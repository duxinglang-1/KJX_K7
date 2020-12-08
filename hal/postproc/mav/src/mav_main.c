#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"

#include "mav_if.h"
#include "mm_comm_def.h"
#include "pp_comm_def.h"

#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__)||defined(__CAMERA_GYRO_SUPPORT__)
#include "mav_comm_def.h"
#include "utility_comm_def.h"
#include "pp_if.h"
#include "mav_core.h"

// 3D image
#include "iul_x_math.h"

//=================== Global Define =====================//
static MAV_STATE_ENUM				gMavState;
static MAV_CORE_PROCESS_STATE_ENUM	gMavCoreProcessState;
static kal_uint16					gMavTotalImageNum;
static kal_int32					gWorkingBufferSize;
static MAV_SET_ENV_INFO_STRUCT      gMavSetEnvInfo;
static MAV_SET_PROC_INFO_STRUCT     gMavSetProcInfo;
static MAV_RESULT_STRUCT			gMavResult;
static mav_image_info				gMavImageInfo[MAV_IMAGE_NUM];
static MavCoreResultInfo	        g_mav_process_result;
static MavTuningInfo				g_mav_tuning_para;
static DrvMavObject_e				gDrvObjEnum;

//=============== Callback Function =====================//
MM_ERROR_CODE_ENUM (* pfPpMavCb) (PP_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen);


//==================== Debug Info =======================//
//#define MAV_DEBUG
#ifdef MAV_DEBUG
#include "fsal.h"

static kal_wchar    img_filename[128];
static kal_wchar    log_filename[128];
static STFSAL       rWriteFile;
static FSAL_Status  rWriteStatus;

static char         mav_log_buffer[1000];
static char         temp_str[200];

static int          log_file_count;
#endif


MM_ERROR_CODE_ENUM MavOpen(void)
{
	gMavState = MAV_STATE_STANDBY;
	gMavCoreProcessState = MAV_CORE_PROCESS_STATE_STANDBY;
    return MM_ERROR_NONE;
}	/* MavOpen() */

MM_ERROR_CODE_ENUM MavClose(void)
{
	gMavState = MAV_STATE_READY;
	gMavCoreProcessState = MAV_CORE_PROCESS_STATE_READY;
    return MM_ERROR_NONE;
}	/* MavClose() */

MM_ERROR_CODE_ENUM MavFeatureCtrl(MAV_FEATURE_ENUM FeatureId,
                                      void* pParaIn, void* pParaOut,kal_uint16 ParaOutLen)
{    
    P_MAV_SET_ENV_INFO_STRUCT pMavSetEnvInfo = (P_MAV_SET_ENV_INFO_STRUCT)pParaIn;
    P_MAV_SET_PROC_INFO_STRUCT pMavSetProcInfo = (P_MAV_SET_PROC_INFO_STRUCT)pParaIn; 
    P_MAV_GET_ENV_INFO_STRUCT pMavGetEnvInfo = (P_MAV_GET_ENV_INFO_STRUCT)pParaOut;

    P_MAV_RESULT_STRUCT pMavResult = (P_MAV_RESULT_STRUCT) pParaOut;
    PP_STATE_ENUM* pMavCheckState = (PP_STATE_ENUM*) pParaOut;	

    UTL_SWITCH_CACHE_STRUCT MemSwitch;

    int i;

    switch (FeatureId)
    {
    case MAV_FEATURE_GET_ENV_INFO:	

		// [Janice] 2012/6/4 modify read max image num to common def
		//pMavGetEnvInfo->MaxImageNumber = MAV_MAX_IMAGE_NUM;
		pMavGetEnvInfo->MaxImageNumber = MAV_IMAGE_NUM;
		pMavGetEnvInfo->WorkingBufSize = gWorkingBufferSize;

        break;

    case MAV_FEATURE_SET_ENV_INFO:	
		// tuning param
		if(pMavSetEnvInfo->pTuningInfo==NULL)
		{
            /* settings for MAV */
			gMavSetEnvInfo.pTuningInfo = &g_mav_tuning_para;
            gMavSetEnvInfo.pTuningInfo->RCWinBound = 30;              // default: 30
            gMavSetEnvInfo.pTuningInfo->SearchRange = 15;             // default: 15
            gMavSetEnvInfo.pTuningInfo->MatchRate = 48;               // default: 48            
            gMavSetEnvInfo.pTuningInfo->RectErrThre = 8;              // default: 8
            gMavSetEnvInfo.pTuningInfo->IterNum = 5;                  // default: 5
            gMavSetEnvInfo.pTuningInfo->MaxAngle = 10;                // default: 10
			// [Janice Modified 20120223]:mark the region of check small clip region(doesn't check now)
            gMavSetEnvInfo.pTuningInfo->ClipRatio = 154;              // default: 154 (0.6)
            
			gMavSetEnvInfo.WorkingBuffAddr = pMavSetEnvInfo->WorkingBuffAddr;
			gMavSetEnvInfo.WorkingBufSize = pMavSetEnvInfo->WorkingBufSize;
			gMavSetEnvInfo.ImageHeight = pMavSetEnvInfo->ImageHeight;
			gMavSetEnvInfo.ImageWidth = pMavSetEnvInfo->ImageWidth;

			gDrvObjEnum = DRV_MAV_OBJ_SW;
		}
		else
		{
			memcpy(&gMavSetEnvInfo, pMavSetEnvInfo, sizeof(MAV_SET_ENV_INFO_STRUCT));
                        gMavSetEnvInfo.pTuningInfo = &g_mav_tuning_para;	
                        memcpy(gMavSetEnvInfo.pTuningInfo, pMavSetEnvInfo->pTuningInfo, sizeof(MavTuningInfo));

			//================= The mechinism to differ from MAV and 3D Image ========================//
			if (gMavSetEnvInfo.pTuningInfo->IterNum == 0)
			{
				gDrvObjEnum = DRV_MAV_OBJ_PANO3D;
				gMavSetEnvInfo.pTuningInfo->IterNum = 30; // hard coded
			}
			else
			{
				gDrvObjEnum = DRV_MAV_OBJ_SW;
			}

		}

		gWorkingBufferSize = GetMavWorkingBufferSize(pMavSetEnvInfo->ImageWidth,pMavSetEnvInfo->ImageHeight);

        break;

    case MAV_FEATURE_SET_PROC_INFO:

		gMavTotalImageNum = pMavSetProcInfo->TotalImgNumber;
		memcpy(&gMavSetProcInfo, pMavSetProcInfo, sizeof(MAV_SET_PROC_INFO_STRUCT));

        break;


    case MAV_FEATURE_GET_RESULT:

		memcpy(pMavResult, &gMavResult, sizeof(MAV_RESULT_STRUCT));
		
        break;
        
    case MAV_FEATURE_GET_STATE:
        
        if(MAV_STATE_READY == gMavState)
        {
            *pMavCheckState = PP_STATE_READY;
        }
        else
        {
            *pMavCheckState = PP_STATE_BUSY;
        }
        break;

    case MAV_FEATURE_SET_LOG_INFO:
		
        break;
    default:
        break;
    }
    return MM_ERROR_NONE;
}	/* MavFeatureCtrl() */
	
// 3D image
#ifdef __3D_IMAGE_SUPPORT__
#define TBL_S_0 (512)
#define TBL_S_1 (512)
#define TBL_S_2 (256)
#define TBL_S_3 (256)
#define TBL_S_4 (256)
#define TBL_S_T (TBL_S_0+TBL_S_1+TBL_S_2+TBL_S_3+TBL_S_4)

void MavCreateGammaTable(kal_uint8 *table[])
{
	//const int     tab_num = 5;
	//const int     tab_size[5] = {512,512,256,256,256};
	const double  f1 = 0.45, f2 = 0.25, r = 1.0/1.6, c1 = 191.0/255.0, c2 = 64.0/255.0;
	const int 	R = 40960; 	//(1.0/1.6) << 16
	int           i, itmp;

	// table[0] => f1 * max(0,a-b)
	//memset(table[0], 0, 256);
	for (i=0; i<256; i++)
	{
		table[0][i] = 0;
	}
	for(i=256; i<512; i++)    // table[0][511] is unused
	{
		itmp = i - 255;
		table[0][i] = (kal_uint8)(f1 * itmp + 0.5);
	}

	// table[1] => f2 * max(0,a-b)
	//memset(table[1], 0, 256);
	for (i=0; i<256; i++)
	{
		table[1][i] = 0;
	}
	for(i=256; i<512; i++)    // table[1][511] is unused
	{
		itmp = i - 255;
		table[1][i] = (kal_uint8)(f2 * itmp + 0.5);
	}

	// table[2] => 191/255 * a
	for(i=0; i<256; i++)
	{
		table[2][i] = (kal_uint8)(c1 * i + 0.5);
	}

	// table[3] => 64/255 * a
	for(i=0; i<256; i++)
	{
		table[3][i] = (kal_uint8)(c2 * i + 0.5);
	}

	// table[4] => a ^ 1/r
	//for(i=0; i<256; i++)
	//  table[4][i] = (kal_uint8)(255.0 * pow(i/255.0,r) + 0.5);
	for(i=0; i<256; i++) // shift left 16 bit for fix point power calculation
	{
		table[4][i] = (kal_uint8)(((iul_x_power((i<<16)>>8, R)<<8)+32768)>>16);
	}
}

kal_bool MavGammaByTable(void *srcL, void *srcR, void *dst, kal_uint32 src_width, kal_uint32 src_height, kal_uint8 *table[])
{
	kal_int32 i;
	kal_uint8 *pleft, *pright, *pout;

	kal_int32 rR, rG, rB;
	kal_int32 lR, lG, lB;
	kal_int32 mR, mG, mB;	
	kal_int32 g_left, b_left;

	pleft = srcL;
	pright = srcR;
	pout = dst;

	i = src_height*src_width;
	while (--i >= 0) // column
	{
		lR = (*pleft++);
		lG = (*pleft++);
		lB = (*pleft++);

		rR = (*pright++);
		rG = (*pright++);
		rB = (*pright++);

		// table look-up for each pixel
		//for(i=0; i<width*height; i++)
		//{
		//  g_left = left[G][i] + table[0][left[R][i]- left[G][i] + 255];
		//  b_left = left[B][i] + table[1][left[R][i]- left[B][i] + 255];
		//  output[R][i] = table[4][ table[2][g_left] + table[3][b_left] ];

		//  output[G][i] = right[G][i] + table[0][right[R][i]-right[G][i] + 255];
		//  output[B][i] = right[B][i] + table[1][right[R][i]-right[B][i] + 255];
		//}					
		
		g_left = lG + table[0][lR - lG + 255];		
		b_left = lB + table[1][lR - lB + 255];
		mR = table[4][ table[2][g_left] + table[3][b_left] ];
		mG = rG + table[0][rR - rG + 255];
		mB = rB + table[1][rR - rB + 255];

		*pout++ = mR;
		*pout++ = mG;
		*pout++ = mB;
	}

	return KAL_TRUE;
}

void MavYUV420toRGB888(kal_uint32 ImgY, kal_uint32 ImgU, kal_uint32 ImgV, 
								kal_uint32 ImgRGB, kal_uint32 width, kal_uint32 height)
{
	kal_uint8* pImgY = (kal_uint8 *)ImgY;
	kal_uint8* pImgU = (kal_uint8 *)ImgU;
	kal_uint8* pImgV = (kal_uint8 *)ImgV;	
	kal_uint8* pImgRGB = (kal_uint8 *)ImgRGB;	
	int w,h;

	h = height;
	while (--h >= 0)
	{						
		// even row get UV and write to result
		w = width >> 1;
		if(!(h&1))
		{
			pImgU -= w;
			pImgV -= w;			
		}	
		while(--w >= 0)
		{
			kal_uint8 ly1, ly2, lu, lv;
			kal_int32 lR, lG, lB;

			ly1 = *pImgY++;
			ly2 = *pImgY++;
			lu = *pImgU++;
			lv = *pImgV++;

			lR = ly1 + ((359*(lv-128))>>8);
			if(lR < 0)
				lR = 0;
			else if(lR > 255)
				lR = 255;			
			
			lG = ly1 - ((88*(lu-128)+183*(lv-128))>>8);
			if(lG < 0)
				lG = 0;
			else if(lG > 255)
				lG = 255;
			
			lB = ly1 + ((454*(lu-128))>>8);
			if(lB < 0)
				lB = 0;
			else if(lB > 255)
				lB = 255;
			
			*pImgRGB++ = (kal_uint8)(lR);
			*pImgRGB++ = (kal_uint8)(lG);
			*pImgRGB++ = (kal_uint8)(lB);

			lR = ly2 + ((359*(lv-128))>>8);
			if(lR < 0)
				lR = 0;
			else if(lR > 255)
				lR = 255;			
			
			lG = ly2 - ((88*(lu-128)+183*(lv-128))>>8);
			if(lG < 0)
				lG = 0;
			else if(lG > 255)
				lG = 255;
			
			lB = ly2 + ((454*(lu-128))>>8);
			if(lB < 0)
				lB = 0;
			else if(lB > 255)
				lB = 255;

			*pImgRGB++ = (kal_uint8)(lR);
			*pImgRGB++ = (kal_uint8)(lG);
			*pImgRGB++ = (kal_uint8)(lB);
		}
	}
}

void MavImage3D()
{ 		
	kal_uint32 resWidth, resHeight;
	kal_uint32 lImgY, lImgU, lImgV;
	kal_uint32 rImgY, rImgU, rImgV;
	kal_uint32 lImgRGB, rImgRGB, dstImgRGB;
	kal_uint32 gammaTable;
	kal_uint8 *table[5];
	
	// src image address for 3D process
	resWidth = gMavResult.ClipWidth;
	resHeight = gMavResult.ClipHeight; 
	if ((resWidth & 1) || (resHeight & 1))
	{	/// we do not handle odd width and height
		return;
	}				
	lImgY = gMavResult.PpImgBufAddr;
	lImgU = lImgY + resWidth*resHeight;
	lImgV = lImgU + (resWidth*resHeight>>2);
	rImgY = gMavResult.PpImgBufAddr+(gMavSetEnvInfo.ImageHeight*gMavSetEnvInfo.ImageWidth*3/2);
	rImgU = rImgY + resWidth*resHeight;
	rImgV = rImgU + (resWidth*resHeight>>2);

	// rgb888 tmp buffers & gamma table using working memory
	lImgRGB = gMavSetEnvInfo.WorkingBuffAddr;
	rImgRGB = lImgRGB+gMavSetEnvInfo.ImageHeight*gMavSetEnvInfo.ImageWidth*3;
	dstImgRGB = rImgRGB;//+gMavSetEnvInfo.ImageHeight*gMavSetEnvInfo.ImageWidth*3;
	gammaTable = dstImgRGB+gMavSetEnvInfo.ImageHeight*gMavSetEnvInfo.ImageWidth*3;
	table[0] = (kal_uint8 *)gammaTable;
	table[1] = table[0]+TBL_S_0;
	table[2] = table[1]+TBL_S_1;
	table[3] = table[2]+TBL_S_2;
	table[4] = table[3]+TBL_S_3;
	ASSERT(gMavSetEnvInfo.WorkingBufSize >= gMavSetEnvInfo.ImageHeight*gMavSetEnvInfo.ImageWidth*6 + TBL_S_T);

	#ifdef MAV_DEBUG		
		img_filename[0] = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);   
		kal_wsprintf(img_filename, "C:\\Left_Round%02d_MavResult_%dx%d.yuv",log_file_count,gMavResult.ClipWidth,gMavResult.ClipHeight);
		if ( FSAL_OPEN_ERROR != FSAL_Open(&rWriteFile, img_filename, FSAL_WRITE) ) 
		{
			rWriteStatus = FSAL_Write(&rWriteFile, (unsigned char *)(gMavResult.PpImgBufAddr + 0*(gMavSetEnvInfo.ImageHeight*gMavSetEnvInfo.ImageWidth*3/2)), gMavResult.ClipHeight*gMavResult.ClipWidth*3/2);
			FSAL_Close(&rWriteFile);				
		}
		kal_wsprintf(img_filename, "C:\\Right_Round%02d_MavResult_%dx%d.yuv",log_file_count,gMavResult.ClipWidth,gMavResult.ClipHeight);
		if ( FSAL_OPEN_ERROR != FSAL_Open(&rWriteFile, img_filename, FSAL_WRITE) ) 
		{
			rWriteStatus = FSAL_Write(&rWriteFile, (unsigned char *)(gMavResult.PpImgBufAddr + 1*(gMavSetEnvInfo.ImageHeight*gMavSetEnvInfo.ImageWidth*3/2)), gMavResult.ClipHeight*gMavResult.ClipWidth*3/2);
			FSAL_Close(&rWriteFile);				
		}
	#endif
	
	MavYUV420toRGB888(lImgY, lImgU, lImgV, lImgRGB, resWidth, resHeight);	
	MavYUV420toRGB888(rImgY, rImgU, rImgV, rImgRGB, resWidth, resHeight);
	
	MavCreateGammaTable(table);
	MavGammaByTable((void *)lImgRGB, (void *)rImgRGB, (void *)dstImgRGB, resWidth, resHeight, table);

iul_csc_rgb888_to_yuv422itlv((kal_uint8 *)dstImgRGB, (kal_uint8 *)lImgY, resWidth, resHeight);
	
	#ifdef MAV_DEBUG		
		img_filename[0] = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);   
		kal_wsprintf(img_filename, "C:\\3D_Round%02d_MavResult_%dx%d.yuv",log_file_count,gMavResult.ClipWidth,gMavResult.ClipHeight);
		if ( FSAL_OPEN_ERROR != FSAL_Open(&rWriteFile, img_filename, FSAL_WRITE) ) 
		{
			rWriteStatus = FSAL_Write(&rWriteFile, (unsigned char *)(gMavResult.PpImgBufAddr + 0*(gMavSetEnvInfo.ImageHeight*gMavSetEnvInfo.ImageWidth*2)), gMavResult.ClipHeight*gMavResult.ClipWidth*2);
	        FSAL_Close(&rWriteFile);                
		}
	#endif	
}			



#endif /* __3D_IMAGE_SUPPORT__ */

MM_ERROR_CODE_ENUM MavCtrl(PP_SCENARIO_ENUM ScenarioId, PP_SCENARIO_CTRL_ENUM CtrlCode,
                               void* pParaIn, void* pParaOut,kal_uint16 ParaOutLen)
{
    kal_uint32	i, j,StartTime, TotalTime=0;
    UTL_SWITCH_CACHE_STRUCT MemSwitch;	

    mav_init_struct     mav_init_info;
    MavCoreTuningInfo	mav_core_tunig_para;

    int YUV_IMAGE_SIZE;

    if(PP_CTRL_CODE_STOP == CtrlCode)
    {          
        gMavState = MAV_STATE_STANDBY;
        gMavCoreProcessState = MAV_CORE_PROCESS_STATE_STANDBY;
        MavCoreReset();
        PP_SET_EVENT(PP_EVENT_MAV_STOP_CNF);   
    }
    else if(PP_CTRL_CODE_START == CtrlCode)
    {
        gMavState = MAV_STATE_PROC;

        if (gMavCoreProcessState == MAV_CORE_PROCESS_STATE_STANDBY)
        {
            MavCoreReset();

            //============= Init working buffer =============//

            // Working buffer to cacheable
            MemSwitch.pMemAddr= (kal_uint32*)&(gMavSetEnvInfo.WorkingBuffAddr);
            MemSwitch.Size = gMavSetEnvInfo.WorkingBufSize;
            MemSwitch.CacheableFlag=KAL_TRUE;
            UtlFeatureCtrl(UTL_FEATURE_EXT_MEM_SWITCH_CACHE,&MemSwitch,NULL,NULL);

            // init working buffer
            memset((void*)gMavSetEnvInfo.WorkingBuffAddr, 0 ,gMavSetEnvInfo.WorkingBufSize);

            mav_init_info.ImgWidth = gMavSetEnvInfo.ImageWidth;
            mav_init_info.ImgHeight = gMavSetEnvInfo.ImageHeight;
            mav_init_info.TotalImgNumber = gMavTotalImageNum;
            mav_init_info.WorkingBuffAddr = gMavSetEnvInfo.WorkingBuffAddr;
            mav_init_info.ObjEnum = gDrvObjEnum;

            mav_init_info.pTuningInfo = &mav_core_tunig_para;

            mav_init_info.pTuningInfo->RCWinBound = gMavSetEnvInfo.pTuningInfo->RCWinBound;
            mav_init_info.pTuningInfo->SearchRange = gMavSetEnvInfo.pTuningInfo->SearchRange;
            mav_init_info.pTuningInfo->MatchRate = gMavSetEnvInfo.pTuningInfo->MatchRate;
            mav_init_info.pTuningInfo->SwEisEnable = KAL_FALSE;
            mav_init_info.pTuningInfo->RectErrThre = gMavSetEnvInfo.pTuningInfo->RectErrThre;
            mav_init_info.pTuningInfo->IterNum = gMavSetEnvInfo.pTuningInfo->IterNum;
            mav_init_info.pTuningInfo->MaxAngle = gMavSetEnvInfo.pTuningInfo->MaxAngle;

            mav_init_info.pTuningInfo->ClipRatio = gMavSetEnvInfo.pTuningInfo->ClipRatio;
            mav_init_info.pTuningInfo->DispBound = 2.5;
            mav_init_info.pTuningInfo->DispRatio = 0.5;

            //mav_init_info.pTuningInfo->ActMatThre = 20; 
            mav_init_info.pTuningInfo->ActMatThre = 0;  // [Janice Modified 20120217: active pair of FP is not enough for Alignment]


            mav_init_info.pTuningInfo->SpecDispMin = -16; 
            mav_init_info.pTuningInfo->SpecDispMax = 8;
            mav_init_info.pTuningInfo->SpecPanelWidth = MAV_MAX_WIDTH;
            mav_init_info.pTuningInfo->SpecPanelHeight = MAV_MAX_HEIGHT;

            // init working buffer to core layer
            MavInitWorkingBuffer(&mav_init_info);


            //============= Init image buffer =============//
            // Image buffer to cacheable
            MemSwitch.pMemAddr= (kal_uint32*)&(gMavSetProcInfo.PpImgBufAddr);
            MemSwitch.Size = gMavSetEnvInfo.ImageHeight * gMavSetEnvInfo.ImageWidth * 3/2 * gMavTotalImageNum;
            MemSwitch.CacheableFlag=KAL_TRUE;
            UtlFeatureCtrl(UTL_FEATURE_EXT_MEM_SWITCH_CACHE,&MemSwitch,NULL,NULL);

            YUV_IMAGE_SIZE = gMavSetEnvInfo.ImageWidth * gMavSetEnvInfo.ImageHeight * 3 / 2;

            for (i=0;i<gMavTotalImageNum;i++)
            {
                gMavImageInfo[i].Height = gMavSetEnvInfo.ImageHeight;
                gMavImageInfo[i].Width = gMavSetEnvInfo.ImageWidth;
                gMavImageInfo[i].ImgAddr = (MUINT32)gMavSetProcInfo.PpImgBufAddr + i*YUV_IMAGE_SIZE;
                gMavImageInfo[i].MotionValue[0] = gMavSetProcInfo.GlobalMotion[i][0];
                gMavImageInfo[i].MotionValue[1] = gMavSetProcInfo.GlobalMotion[i][1];
            }

            #ifdef MAV_DEBUG
            memset(mav_log_buffer,0,sizeof(mav_log_buffer));
            
            strcat(mav_log_buffer, temp_str);  
            for (i=0;i<gMavTotalImageNum;i++)
            {
                sprintf(temp_str, "%d,%d\n",gMavImageInfo[i].MotionValue[0],gMavImageInfo[i].MotionValue[1]);
                strcat(mav_log_buffer, temp_str);            
            }

            kal_wsprintf(log_filename, "C:\\Round%02d_MV.txt",log_file_count);
            log_filename[0] = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);       
            if ( FSAL_OPEN_ERROR != FSAL_Open(&rWriteFile, log_filename, FSAL_WRITE )) 
            {
                rWriteStatus = FSAL_Write(&rWriteFile, (kal_uint8*)mav_log_buffer, sizeof(mav_log_buffer));
                FSAL_Close(&rWriteFile);
            }
                        

            //====================================== MAV source image =================================================//
            for(i=0; i<gMavTotalImageNum; i++)
            {
                kal_wsprintf(img_filename, "C:\\Round%02d_MavSource_%03d_%dx%d.yuv420",log_file_count,i,gMavImageInfo[i].Width,gMavImageInfo[i].Height);
                img_filename[0] = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);   
                if ( FSAL_OPEN_ERROR != FSAL_Open(&rWriteFile, img_filename, FSAL_WRITE) ) 
                {
                    rWriteStatus = FSAL_Write(&rWriteFile, (unsigned char *)(gMavImageInfo[i].ImgAddr), gMavImageInfo[i].Height*gMavImageInfo[i].Width*3/2);
                    FSAL_Close(&rWriteFile);                
                }
            } 
            #endif

        }

        gMavCoreProcessState = MavCoreProcess(&gMavImageInfo[0],&g_mav_process_result,gMavTotalImageNum);

        // If Mav core process finish
        if(MAV_CORE_PROCESS_STATE_READY == gMavCoreProcessState)
        {
            gMavResult.ClipHeight = g_mav_process_result.ClipHeight;
            gMavResult.ClipWidth = g_mav_process_result.ClipWidth;
            gMavResult.PpImgBufAddr = gMavImageInfo[0].ImgAddr;
            for (j = 0; j < gMavTotalImageNum; j++)
            {
                gMavResult.Image[j].ClipX = g_mav_process_result.ImageInfo[j].ClipX;
                gMavResult.Image[j].ClipY = g_mav_process_result.ImageInfo[j].ClipY;
                gMavResult.Image[j].AngleValueX = g_mav_process_result.ImageInfo[j].AngleValueX;
                gMavResult.Image[j].AngleValueY = g_mav_process_result.ImageInfo[j].AngleValueY;
                gMavResult.Image[j].AngleValueZ = g_mav_process_result.ImageInfo[j].AngleValueZ;
            }

			// 3D image
			#ifdef __3D_IMAGE_SUPPORT__		
			if(DRV_MAV_OBJ_PANO3D==gDrvObjEnum)
				MavImage3D();					
			#endif			
			
            gMavState = MAV_STATE_READY;
        }

        if(gMavState == MAV_STATE_READY)
        {
            MemSwitch.pMemAddr= (kal_uint32*)&(gMavImageInfo[0].ImgAddr);
            MemSwitch.Size = gMavImageInfo[0].Height * gMavImageInfo[0].Width * 3/2 * gMavTotalImageNum;
            MemSwitch.CacheableFlag=KAL_FALSE;
            UtlFeatureCtrl(UTL_FEATURE_EXT_MEM_SWITCH_CACHE,&MemSwitch,NULL,NULL);

            MemSwitch.pMemAddr= (kal_uint32*)&(gMavSetEnvInfo.WorkingBuffAddr);
            MemSwitch.Size = gMavSetEnvInfo.WorkingBufSize;
            MemSwitch.CacheableFlag=KAL_FALSE;
            UtlFeatureCtrl(UTL_FEATURE_EXT_MEM_SWITCH_CACHE,&MemSwitch,NULL,NULL);

            #ifdef MAV_DEBUG
            //====================================== MAV result image =================================================//
            for(i=0; i<gMavTotalImageNum; i++)
            {
                kal_wsprintf(img_filename, "C:\\Round%02d_MavResult_%03d_%dx%d.yuv420",log_file_count,i,gMavResult.ClipWidth,gMavResult.ClipHeight);
                img_filename[0] = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);   
                if ( FSAL_OPEN_ERROR != FSAL_Open(&rWriteFile, img_filename, FSAL_WRITE) ) 
                {
                    rWriteStatus = FSAL_Write(&rWriteFile, (unsigned char *)(gMavResult.PpImgBufAddr + i*(gMavSetEnvInfo.ImageHeight*gMavSetEnvInfo.ImageWidth*3/2)), gMavResult.ClipHeight*gMavResult.ClipWidth*3/2);
                    FSAL_Close(&rWriteFile);                
                }
            } 
            log_file_count++;
            #endif

            pfPpMavCb(PP_CBID_MAV_RESULT, &gMavResult, sizeof(MAV_RESULT_STRUCT));
        }
    }

    return MM_ERROR_NONE;
}	/* MavCtrl() */


MAV_FUNCTION_STRUCT MavFuncMap=
{
    MavOpen,
    MavFeatureCtrl,
    MavCtrl,
    MavClose
};



MM_ERROR_CODE_ENUM MavInit(MM_ERROR_CODE_ENUM (* pfMavCallback) (PP_CALLBACK_ID_ENUM CbId,
                               void *pCallbackPara, kal_uint16 CallbackParaLen),
								P_MAV_FUNCTION_STRUCT *pfMavCapFunc)
{
    pfPpMavCb = pfMavCallback;	
    *pfMavCapFunc=&MavFuncMap;
	gMavState = MAV_STATE_INIT;
    return MM_ERROR_NONE;
}	/* MavInit() */

#else   /*#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)*/

MM_ERROR_CODE_ENUM MavInit(MM_ERROR_CODE_ENUM (* pfMavCapCallback) (PP_CALLBACK_ID_ENUM CbId,
                               void *pCallbackPara, kal_uint16 CallbackParaLen),
								P_MAV_FUNCTION_STRUCT *pfMavCapFunc)
{
    return MM_ERROR_NONE;
} /* MavInit() */

#endif
#pragma arm section code, rodata