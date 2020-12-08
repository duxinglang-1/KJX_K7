#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"

#include "mavcap_if.h"
#include "mm_comm_def.h"
#include "pp_comm_def.h"

#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__)||defined(__CAMERA_GYRO_SUPPORT__)
#include "autocap_core.h"
#include "MavMotionCore.h"
#include "utility_core.h"
#include "pp_if.h"
/*******************************************************************************
* Global Define
********************************************************************************/
//== AutoCap ==//
static MAVCAP_STATE_ENUM gMavCapState = MAVCAP_IDLE_STATE;
static MAVCAP_SET_MEM_INFO_STRUCT gMavCapSetMemInfo;
static MAVCAP_SET_ENV_INFO_STRUCT gMavCapSetEnvInfo;
static MAVCAP_GET_ENV_INFO_STRUCT gMavCapGetEnvInfo;
static MAVCAP_RESULT_STRUCT gMavCapResult;
static MAVCAP_TUNING_PARA_STRUCT    gMavTuningPara;

static MAVCAP_CORE_MOTION_TUNING_PARA_STRUCT g_mav_core_motion_tuning_para;
static MAVCAP_CORE_SET_MEM_INFO_STRUCT g_mav_core_set_mem_struct;
static MAVCAP_CORE_SET_ENV_INFO_STRUCT g_mav_core_set_info_struct;


//== MavMotion ==//
static MUINT32			    gMavCapCurrProcNum;
static kal_uint32           gMavCapSrcImageWidth;
static kal_uint32           gMavCapSrcImageHeight;
static MTKMotionResultInfo	gMavMotionResultStruct; 
static kal_bool				gMavForceToShotFlag;
static kal_uint8			gMavForceToShotCnt;


MM_ERROR_CODE_ENUM (* pfPpMavCapCb) (PP_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen);

//enter preview called
MM_ERROR_CODE_ENUM MavCapOpen(void)
{
    gMavCapState = MAVCAP_IDLE_STATE;
    gMavForceToShotFlag = KAL_FALSE;
    gMavForceToShotCnt = 0;
    return MM_ERROR_NONE;
}	/* MavCapOpen() */


//leave preview called
MM_ERROR_CODE_ENUM MavCapClose(void)
{
    gMavCapState = MAVCAP_IDLE_STATE;
    gMavForceToShotFlag = KAL_FALSE;
    AutoCapCoreExit();
    return MM_ERROR_NONE;
}	/* MavCapClose() */

camera_autocap_init_struct autocap_init_struct;

#if defined(__CAMERA_GYRO_SUPPORT__)
#define GYRO_RANGE_RATIO 1 // range = min|max dist * this ratio
kal_bool gyroEnable;
kal_int16 gyroMinDist, gyroMaxDist;
kal_int16 gyroDiffX, gyroDiffY;
kal_int16 gyroAccuX, gyroAccuY;

//#define CAMERA_GYRO_DEBUG 
#ifdef CAMERA_GYRO_DEBUG
kal_int16 logDiffX[100];
kal_int16 logDiffY[100];
kal_int16 logAccuX[100];
kal_int16 logAccuY[100];
kal_uint32 logCounter = 0;

#include "fsal.h"

static kal_wchar    gyro_img_filename[128];
static STFSAL       gyro_rWriteFile;
static FSAL_Status  gyro_rWriteStatus;
static int          gyro_log_file_count = 0;
static char         gyro_log_buffer[300];
kal_bool 				gyro_is_fileopen = KAL_FALSE;
#endif

kal_int16 gyro_range(kal_int16 x, kal_int16 min, kal_int16 max)
{
	if(x < min)					
		return min;				
	else if(x > max)			
		return max;				
	else						
		return x;				
}	
kal_uint16 gyro_abs(kal_int16 x)
{
	if(x < 0)
		return (-1)*x;
	else
		return x;
}
#endif
MM_ERROR_CODE_ENUM MavCapFeatureCtrl(MAVCAP_FEATURE_ENUM FeatureId,
                                      void* pParaIn, void* pParaOut,kal_uint16 ParaOutLen)
{    

    P_MAVCAP_SET_ENV_INFO_STRUCT pMavCapSetEnvInfo = (P_MAVCAP_SET_ENV_INFO_STRUCT)pParaIn;
    P_MAVCAP_SET_MEM_INFO_STRUCT pMavCapSetMemInfo = (P_MAVCAP_SET_MEM_INFO_STRUCT)pParaIn; 
    P_MAVCAP_GET_ENV_INFO_STRUCT pMavCapGetEnvInfo = (P_MAVCAP_GET_ENV_INFO_STRUCT)pParaOut;

    P_MAVCAP_RESULT_STRUCT pMavCapResult = (P_MAVCAP_RESULT_STRUCT) pParaOut;
    PP_STATE_ENUM* pMavCapCheckState = (PP_STATE_ENUM*) pParaOut;	
    

    switch (FeatureId)
    {
    case MAVCAP_FEATURE_GET_ENV_INFO:

        pMavCapGetEnvInfo->ImageWidth = MAVCAP_IMAGE_XS;
        pMavCapGetEnvInfo->ImageHeight = MAVCAP_IMAGE_YS;
        // Get working buffer size
        pMavCapGetEnvInfo->WorkingBufSize = (kal_uint32)MAVCAP_WORKING_BUFFER_SIZE;
        pMavCapGetEnvInfo->SrcImgFormat= MM_IMAGE_FORMAT_YUV420;			

        break;

    case MAVCAP_FEATURE_SET_ENV_INFO:	

        //-- AutoCap --//
        kal_mem_cpy(&gMavCapSetEnvInfo, pMavCapSetEnvInfo, sizeof(MAVCAP_SET_ENV_INFO_STRUCT) );

        autocap_init_struct.image_width = MAVCAP_IMAGE_XS;
        autocap_init_struct.image_height = MAVCAP_IMAGE_YS;
        autocap_init_struct.lcd_width = pMavCapSetEnvInfo->target_width;
        autocap_init_struct.lcd_height = pMavCapSetEnvInfo->target_height;
        autocap_init_struct.log_enable = KAL_FALSE;
        autocap_init_struct.tolerance_x = pMavCapSetEnvInfo->p_tuning_data->tolerance_x;
        autocap_init_struct.tolerance_y = pMavCapSetEnvInfo->p_tuning_data->tolerance_y;
        autocap_init_struct.image_format = AUTOCAP_IMAGE_FORMAT_YUV420;
        AutoCapCoreSetInfo(&autocap_init_struct);

        gMavCapSrcImageWidth=pMavCapSetEnvInfo->target_width;
        gMavCapSrcImageHeight=pMavCapSetEnvInfo->target_height;

        //-- MavMotion --//
        gMavCapCurrProcNum = 0;
        gMavCapSetEnvInfo.p_tuning_data = &gMavTuningPara;
        if(pMavCapSetEnvInfo->p_tuning_data==NULL)
        {
            gMavCapSetEnvInfo.p_tuning_data->tolerance_x = 8;
            gMavCapSetEnvInfo.p_tuning_data->tolerance_y = 8;
            gMavCapSetEnvInfo.p_tuning_data->MaxMV = 8;
	    gMavCapSetEnvInfo.p_tuning_data->StepLB = 5;
	    gMavCapSetEnvInfo.p_tuning_data->StepUB = 10;
        }
        else
        {
            memcpy(gMavCapSetEnvInfo.p_tuning_data, pMavCapSetEnvInfo->p_tuning_data, sizeof(MAVCAP_TUNING_PARA_STRUCT));
        }

#if defined(__CAMERA_GYRO_SUPPORT__)
		gyroEnable = KAL_FALSE;
		if( -1 == gMavCapSetEnvInfo.p_tuning_data->MaxMV )
			gyroEnable = KAL_TRUE;
		gyroMinDist = gMavCapSetEnvInfo.p_tuning_data->StepLB;
		gyroMaxDist = gMavCapSetEnvInfo.p_tuning_data->StepUB;		
		gyroDiffX = gyroDiffY = 0;
		gyroAccuX = gyroAccuY = 0;

		#ifdef CAMERA_GYRO_DEBUG
		logCounter = 0;

		if(gyro_is_fileopen)
		{
			FSAL_Close(&gyro_rWriteFile); 
			gyro_is_fileopen = KAL_FALSE;
		}

		kal_wsprintf(gyro_img_filename, "C:\\Gyro_log%02d.txt",gyro_log_file_count);
		gyro_img_filename[0] = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);   
		if ( FSAL_OPEN_ERROR != FSAL_Open(&gyro_rWriteFile, gyro_img_filename, FSAL_WRITE) ) 
		{
			gyro_is_fileopen = KAL_TRUE;
		gyro_log_file_count++;
		}			
		#endif
#endif

        gMavCapState = MAVCAP_CONFIG_STATE;			

        break;

    case MAVCAP_FEATURE_SET_PROC_INFO:	

        gMavCapState = MAVCAP_MEM_PROCESS_STATE;//MAVCAP_READY_STATE;
        kal_mem_cpy(&gMavCapSetMemInfo, pMavCapSetMemInfo, sizeof(MAVCAP_SET_MEM_INFO_STRUCT));
        gMavCapSetMemInfo.PpProcFmt = MM_IMAGE_FORMAT_YUV422;
        break;

    case MAVCAP_FEATURE_GET_STATE:

        if((gMavCapState == MAVCAP_READY_STATE)||(gMavCapState == MAVCAP_CONFIG_STATE))
        {
            *pMavCapCheckState=PP_STATE_READY;
        }
        else
        {
            *pMavCapCheckState=PP_STATE_BUSY;
        }

        break;

    case MAVCAP_FEATURE_GET_RESULT:
       
        kal_mem_cpy(pMavCapResult, &gMavCapResult, sizeof(MAVCAP_RESULT_STRUCT));		    

        break;

    case MAVCAP_FEATURE_SET_LOG_INFO:
		
        break;
    default:
        break;
    }
    return MM_ERROR_NONE;
}	/* MavCapFeatureCtrl() */

MM_ERROR_CODE_ENUM MavCapCtrl(PP_SCENARIO_ENUM ScenarioId, PP_SCENARIO_CTRL_ENUM CtrlCode,
                               void* pParaIn, void* pParaOut,kal_uint16 ParaOutLen)
{
    int i;

    P_MAVCAP_RESULT_STRUCT pMavCapResult = &gMavCapResult;
    P_MAVCAP_SET_MEM_INFO_STRUCT pMavCapSetMemInfo = &gMavCapSetMemInfo;

    UTL_SWITCH_CACHE_STRUCT MemSwitch;

    UTL_BILINEAR_RESIZER_STRUCT UtlRisizerInfo;

    camera_autocap_set_mem_struct autocap_set_mem_struct;
    camera_autocap_init_struct		autocap_reset_struct;
    camera_autocap_result_struct    AutoCapResultStruct;

    
    ASSERT(gMavCapState!=MAVCAP_IDLE_STATE);


    if(PP_CTRL_CODE_START == CtrlCode)
    {		
        /*-------------- MEM--------------*/

        gMavCapState = MAVCAP_MEM_PROCESS_STATE;

        //=================== To Cacheable ===================//
        MemSwitch.pMemAddr=&(gMavCapSetMemInfo.PpProcBufAddr); 
        MemSwitch.Size=(kal_uint32)gMavCapSetMemInfo.PpProcBufSize;
        MemSwitch.CacheableFlag=KAL_TRUE;
        UtlFeatureCtrl(UTL_FEATURE_EXT_MEM_SWITCH_CACHE,&MemSwitch,NULL,NULL);

        MemSwitch.pMemAddr=&(gMavCapSetMemInfo.PpSrcBufAddr); 
        MemSwitch.Size=(kal_uint32)gMavCapSetMemInfo.PpSrcBufSize;
        MemSwitch.CacheableFlag=KAL_TRUE;
        UtlFeatureCtrl(UTL_FEATURE_EXT_MEM_SWITCH_CACHE,&MemSwitch,NULL,NULL);


        //================= AutoCap Set Working Buffer ===================//
        autocap_set_mem_struct.ext_mem_start_addr = (kal_uint32)pMavCapSetMemInfo->PpProcBufAddr;
        autocap_set_mem_struct.ext_mem_size = (kal_uint32)pMavCapSetMemInfo->PpProcBufSize;
        AutoCapCoreSetProcInfo(&autocap_set_mem_struct);

        // copy source image form MDP to MavCap working memory
        if(PP_MEM_OP_COPY_TO_PROC_BUF == gMavCapSetMemInfo.PpMemOpType)
        {
            //kal_mem_cpy((kal_uint8*)(gMavCapSetMemInfo.PpProcBufAddr), (kal_uint8*)gMavCapSetMemInfo.PpSrcBufAddr, gMavCapSetMemInfo.PpSrcBufSize); 
        }
        else if(PP_MEM_OP_RESIZE_TO_PROC_BUF== gMavCapSetMemInfo.PpMemOpType)
        {
            UtlRisizerInfo.srcAddr = (kal_uint16*) gMavCapSetMemInfo.PpSrcBufAddr;
            UtlRisizerInfo.srcWidth= gMavCapSrcImageWidth;
            UtlRisizerInfo.srcHeight= gMavCapSrcImageHeight;
            UtlRisizerInfo.dstAddr = (kal_uint16*) gMavCapSetMemInfo.PpSrcBufAddr;
            UtlRisizerInfo.dstWidth = MAVCAP_IMAGE_XS;
            UtlRisizerInfo.dstHeight = MAVCAP_IMAGE_YS;
            UtlBilinearResizer(&UtlRisizerInfo);
        }
        else
        {
            return MM_ERROR_INVALID_PARAMETER;
        }

        gMavCapState = MAVCAP_PROCESS_STATE;

        //===================== AutoCap Process ===================//
        AutoCapCoreProcess(gMavCapSetMemInfo.PpSrcBufAddr, &AutoCapResultStruct);	

#if defined(__CAMERA_GYRO_SUPPORT__)
if(gyroEnable) // camera gyro mode
{		
	gyroDiffX = AutoCapResultStruct.mv_x;
	gyroDiffY = AutoCapResultStruct.mv_y;
	

	//pMavCapResult->MV_X = gyro_range(gyroAccuX+gyroDiffX, gyroMinDist, gyroMaxDist);
	//gyroAccuX = gyro_range(gyroAccuX+gyroDiffX, gyroMinDist*GYRO_RANGE_RATIO, gyroMaxDist*GYRO_RANGE_RATIO);

	//pMavCapResult->MV_Y = gyro_range(gyroAccuY+gyroDiffY, gyroMinDist, gyroMaxDist);
	//gyroAccuY = gyro_range(gyroAccuY+gyroDiffY, gyroMinDist*GYRO_RANGE_RATIO, gyroMaxDist*GYRO_RANGE_RATIO);

        pMavCapResult->MV_X = gyro_range(AutoCapResultStruct.mv_x, gyroMinDist, gyroMaxDist);
        pMavCapResult->MV_Y = gyro_range(AutoCapResultStruct.mv_y, gyroMinDist, gyroMaxDist);

	pMavCapResult->ReadyToShot = KAL_FALSE;			
	pMavCapResult->OverlapRatio = gyroMaxDist;

	// log
	#ifdef CAMERA_GYRO_DEBUG
	logDiffX[logCounter]=gyroDiffX;
	logDiffY[logCounter]=gyroDiffY;
	logAccuX[logCounter]=gyroAccuX;
	logAccuY[logCounter]=gyroAccuY;		
	logCounter++;
	if(logCounter >= 100)		
		logCounter = 0;

if(gyro_is_fileopen)
{
	memset(gyro_log_buffer,0,sizeof(gyro_log_buffer));
	sprintf(gyro_log_buffer, "Cb:(%d,%d), Diff:(%d,%d), Accu:(%d, %d)", 
										pMavCapResult->MV_X, pMavCapResult->MV_Y,
										gyroDiffX, gyroDiffY,
										gyroAccuX, gyroAccuY);
	gyro_log_buffer[299] = '\n';
	gyro_rWriteStatus = FSAL_Write(&gyro_rWriteFile, (kal_uint8*)gyro_log_buffer, sizeof(gyro_log_buffer));	
}	
	#endif

	// callback
	gMavCapState = MAVCAP_READY_STATE;
	
	//AutoCapCoreResetAllMV();

	pfPpMavCapCb(PP_CBID_MAVCAP_RESULT, pMavCapResult, sizeof(MAVCAP_RESULT_STRUCT));
	
	return MM_ERROR_NONE;
}
#endif

        // [Note]: Mav mv = - AutoCap mv
        pMavCapResult->MV_X = -AutoCapResultStruct.mv_x;
        pMavCapResult->MV_Y = -AutoCapResultStruct.mv_y;
        pMavCapResult->ImageWidth = MAVCAP_IMAGE_XS;
        pMavCapResult->ImageHeight = MAVCAP_IMAGE_YS;
        pMavCapResult->OverlapRatio = OVERLAP_RATIO;
        pMavCapResult->Direction = AutoCapResultStruct.direction;
        pMavCapResult->HintDirection = AutoCapResultStruct.hint_direction;
        pMavCapResult->ReadyToShot = AutoCapResultStruct.ready_to_shot;

        if(!gMavForceToShotFlag && gMavCapSetMemInfo.PpForceToShot)
        {
        	gMavForceToShotFlag = gMavCapSetMemInfo.PpForceToShot;
        	pMavCapResult->ReadyToShot = KAL_TRUE;
        	printf("Force To Shot!!\n");
        }

        if(gMavForceToShotFlag)	// force to capture and fix the framecount to minmum
        {
        	if (gMavForceToShotCnt % gMavCapSetEnvInfo.p_tuning_data->StepLB == 0)
        	{
        		pMavCapResult->ReadyToShot = KAL_TRUE;
        		gMavForceToShotCnt = 0;
        	}
        	else
        	{
        		pMavCapResult->ReadyToShot = KAL_FALSE;
        	}
        	
        	pMavCapResult->ErrPattern = 0;
        	pMavCapResult->FrameCount = gMavCapSetEnvInfo.p_tuning_data->StepLB;
        	gMavForceToShotCnt++;
        }
        else	// Normal flow
        {

        //=================== Mav Motion input ====================//
        // Duplicate the autocap result to mv/tv result
        for (i = 0; i < MOTION_TOTAL_BN; i++)
        {
            pMavCapSetMemInfo->MotionValueXY[i*2] = pMavCapResult->MV_X;
            pMavCapSetMemInfo->MotionValueXY[i*2+1] = pMavCapResult->MV_Y;
            pMavCapSetMemInfo->TrustValueXY[i*2] = 50;
            pMavCapSetMemInfo->TrustValueXY[i*2+1] = 50;
        }

        //================= MAV Motion Process ===================//
        g_mav_core_set_info_struct.dir_decided = gMavCapSetEnvInfo.dir_decided;
        g_mav_core_set_info_struct.target_height = gMavCapSetEnvInfo.target_height;
        g_mav_core_set_info_struct.target_width = gMavCapSetEnvInfo.target_width;

        g_mav_core_set_info_struct.p_mavmotion_tuning_data = &g_mav_core_motion_tuning_para;
        g_mav_core_set_info_struct.p_mavmotion_tuning_data->MaxMV = gMavCapSetEnvInfo.p_tuning_data->MaxMV;
        g_mav_core_set_info_struct.p_mavmotion_tuning_data->StepLB = gMavCapSetEnvInfo.p_tuning_data->StepLB;
        g_mav_core_set_info_struct.p_mavmotion_tuning_data->StepUB = gMavCapSetEnvInfo.p_tuning_data->StepUB;
        g_mav_core_set_info_struct.p_mavmotion_tuning_data->ToleranceX = 0;
        g_mav_core_set_info_struct.p_mavmotion_tuning_data->ToleranceY = 0;
        g_mav_core_set_info_struct.p_mavmotion_tuning_data->OverlapRatio = 0;

        memcpy(g_mav_core_set_mem_struct.MotionValueXY, pMavCapSetMemInfo->MotionValueXY,sizeof(g_mav_core_set_mem_struct.MotionValueXY));
        memcpy(g_mav_core_set_mem_struct.TrustValueXY, pMavCapSetMemInfo->TrustValueXY,sizeof(g_mav_core_set_mem_struct.TrustValueXY));

        g_mav_core_set_mem_struct.PpProcBufAddr =  pMavCapSetMemInfo->PpProcBufAddr;
        g_mav_core_set_mem_struct.PpProcBufSize = pMavCapSetMemInfo->PpProcBufSize;
        g_mav_core_set_mem_struct.PpProcFmt = pMavCapSetMemInfo->PpProcFmt;

	if(gMavCapCurrProcNum==0)
	{
		MotionDetectInit(&g_mav_core_set_info_struct);
			    MotionDetect(&g_mav_core_set_mem_struct, &gMavMotionResultStruct);
	}
	else
	{
			    MotionDetect(&g_mav_core_set_mem_struct, &gMavMotionResultStruct);
	}
	gMavCapCurrProcNum++;

		pMavCapResult->ReadyToShot = gMavMotionResultStruct.ReadyToShot;
		pMavCapResult->ErrPattern = gMavMotionResultStruct.ErrPattern;
		pMavCapResult->FrameCount = gMavMotionResultStruct.FrameCount;
	// MV value should follow AutoCap result, not MavMotion result
        }	

	//============ Reset the mv when ReadyToShot is true =============//
	if (pMavCapResult->ReadyToShot == KAL_TRUE)
	{
		// Use AutoCapCoreSetInfo to reset mv_x and mv_y			
		autocap_reset_struct.image_width = MAVCAP_IMAGE_XS;
		autocap_reset_struct.image_height = MAVCAP_IMAGE_YS;
		autocap_reset_struct.lcd_width = gMavCapSetEnvInfo.target_width;
		autocap_reset_struct.lcd_height = gMavCapSetEnvInfo.target_height;
		autocap_reset_struct.log_enable = KAL_FALSE;
		autocap_reset_struct.tolerance_x = gMavCapSetEnvInfo.p_tuning_data->tolerance_x;
		autocap_reset_struct.tolerance_y = gMavCapSetEnvInfo.p_tuning_data->tolerance_y;
		autocap_reset_struct.image_format = AUTOCAP_IMAGE_FORMAT_YUV420;
		// For MavMotion, if ReadyToShot flag is true, reset both mv_x and mv_y
		AutoCapCoreSetInfo(&autocap_reset_struct);
	}


        //=================== To Non Cacheable ===================//
        MemSwitch.pMemAddr=&(gMavCapSetMemInfo.PpProcBufAddr); 
        MemSwitch.Size=(kal_uint32)gMavCapSetMemInfo.PpProcBufSize;
        MemSwitch.CacheableFlag=KAL_FALSE;
        UtlFeatureCtrl(UTL_FEATURE_EXT_MEM_SWITCH_CACHE,&MemSwitch,NULL,NULL);

        MemSwitch.pMemAddr=&(gMavCapSetMemInfo.PpSrcBufAddr); 
        MemSwitch.Size=(kal_uint32)gMavCapSetMemInfo.PpSrcBufSize;
        MemSwitch.CacheableFlag=KAL_FALSE;
        UtlFeatureCtrl(UTL_FEATURE_EXT_MEM_SWITCH_CACHE,&MemSwitch,NULL,NULL);

        gMavCapState = MAVCAP_READY_STATE;

        //=================== cb to CAL ===================//
        pfPpMavCapCb(PP_CBID_MAVCAP_RESULT, pMavCapResult, sizeof(MAVCAP_RESULT_STRUCT));
    }
    else if (PP_CTRL_CODE_RESET == CtrlCode)
    {
        AutoCapCoreExit();
		gMavForceToShotFlag = KAL_FALSE;
    }

    return MM_ERROR_NONE;
}	/* MavCapCtrl() */



MAVCAP_FUNCTION_STRUCT MavCapFuncMap=
{
    MavCapOpen,
    MavCapFeatureCtrl,
    MavCapCtrl,
    MavCapClose
};



MM_ERROR_CODE_ENUM MavCapInit(MM_ERROR_CODE_ENUM (* pfMavCapCallback) (PP_CALLBACK_ID_ENUM CbId,
                               void *pCallbackPara, kal_uint16 CallbackParaLen),
                               P_MAVCAP_FUNCTION_STRUCT *pfMavCapFunc)
{
    pfPpMavCapCb = pfMavCapCallback;	
    *pfMavCapFunc=&MavCapFuncMap;
    return MM_ERROR_NONE;
}	/* MavCapInit() */

#else   /*#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)*/

MM_ERROR_CODE_ENUM MavCapInit(MM_ERROR_CODE_ENUM (* pfMavCapCallback) (PP_CALLBACK_ID_ENUM CbId,
                               void *pCallbackPara, kal_uint16 CallbackParaLen),
                               P_MAVCAP_FUNCTION_STRUCT *pfMavCapFunc)
{
    return MM_ERROR_NONE;
} /* MavCapInit() */




#endif
#pragma arm section code, rodata