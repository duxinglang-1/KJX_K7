/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   image_sensor_BF3703.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Image sensor driver function
 *
 * Author:
 * -------
 * -------
 *
 *=============================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *=============================================================
 ****************************************************************************/

#include "drv_comm.h"
#include "isp_comm_if.h"
#include "camera_sccb.h"
#include "image_sensor.h"
#include "cal_comm_def.h"
#include "isp_if.h"

/* Vedio and night mode */
static kal_bool BF3703_Vedio_mode=KAL_FALSE;
static kal_bool  BF3703_s_bNight_mode =KAL_FALSE; // to distinguish night mode or auto mode, default: auto mode setting

// Pclk, dummy, exposue related variables.
static kal_uint16 BF3703_dummy_pixels=0, BF3703_dummy_lines=0;

/* Image Sensor ID */
static kal_uint16 BF3703_sensor_id=0;

//HAL
IMAGE_SENSOR_INDEX_ENUM SensorIdxBF3703;

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

void BF3703_set_banding_for_50Hz(void);
void BF3703_set_banding_for_60Hz(void);

void BF3703_set_dummy(kal_uint16 pixels, kal_uint16 lines)
{
	CamWriteCmosSensor(0x2A,((pixels&0xF00)>>4));
	CamWriteCmosSensor(0x2B,(pixels&0xFF));
	CamWriteCmosSensor(0x92,(lines&0xFF));
	CamWriteCmosSensor(0x93,((lines&0xFF00)>>8));
}	/* set_BF3703_dummy */

void BF3703_init_setting(void)
{
	CamWriteCmosSensor(0x11, 0x80);
	CamWriteCmosSensor(0x09, 0x03);//0X03
	CamWriteCmosSensor(0x13, 0x00);
	CamWriteCmosSensor(0x01, 0x13);
	CamWriteCmosSensor(0x02, 0x25);
	CamWriteCmosSensor(0x8c, 0x02);//01 :devided by 2  02 :devided by 1
	CamWriteCmosSensor(0x8d, 0xfd);//cb: devided by 2  fd :devided by 1
	CamWriteCmosSensor(0x87, 0x1a);
	CamWriteCmosSensor(0x13, 0x07);
	
	//POLARITY of Signal
	CamWriteCmosSensor(0x15, 0x00);
	CamWriteCmosSensor(0x3a, 0x00);   
	
	//black level ,对上电偏绿有改善,如果需要请选择使用
	/*
	CamWriteCmosSensor(0x05, 0x1f);
	CamWriteCmosSensor(0x06, 0x60);
	CamWriteCmosSensor(0x14, 0x1f);
	CamWriteCmosSensor(0x27, 0x03);
	CamWriteCmosSensor(0x06, 0xe0);
	*/
	
	//lens shading
	CamWriteCmosSensor(0x35, 0x78);//68//70
	CamWriteCmosSensor(0x65, 0x68);
	CamWriteCmosSensor(0x66, 0x5f);//62
	CamWriteCmosSensor(0x36, 0x05);
	CamWriteCmosSensor(0x37, 0xe6);//f6
	CamWriteCmosSensor(0x38, 0x46);
	CamWriteCmosSensor(0x9b, 0xf6);
	CamWriteCmosSensor(0x9c, 0x46);
	CamWriteCmosSensor(0xbc, 0x01);
	CamWriteCmosSensor(0xbd, 0xf6);
	CamWriteCmosSensor(0xbe, 0x46);
	
	//AE
	CamWriteCmosSensor(0x82, 0x13);
	CamWriteCmosSensor(0x83, 0x23);
	CamWriteCmosSensor(0x9a, 0x23);//the same as 0x83
	CamWriteCmosSensor(0x84, 0x1a);
	CamWriteCmosSensor(0x85, 0x20);
	CamWriteCmosSensor(0x89, 0x02);//02 :devided by 2  04 :devided by 1
	CamWriteCmosSensor(0x8a, 0x64);//04: devided by 2  05 :devided by 1
	CamWriteCmosSensor(0x8b, 0x02);
	CamWriteCmosSensor(0x86, 0x25);//the same as 0x7b
	CamWriteCmosSensor(0x96, 0xa6);//AE speed
	CamWriteCmosSensor(0x97, 0x0c);//AE speed
	CamWriteCmosSensor(0x98, 0x18);//AE speed
	//AE target
	CamWriteCmosSensor(0x24, 0x7a);//灯箱测试  0x6a
	CamWriteCmosSensor(0x25, 0x70);//灯箱测试  0x7a
	CamWriteCmosSensor(0x94, 0x0a);//INT_OPEN  
	CamWriteCmosSensor(0x80, 0x55);
	
	//denoise 
	CamWriteCmosSensor(0x70, 0x6f);//denoise
	CamWriteCmosSensor(0x72, 0x4f);//denoise
	CamWriteCmosSensor(0x73, 0x2f);//denoise
	CamWriteCmosSensor(0x74, 0x27);//denoise
	CamWriteCmosSensor(0x77, 0x90);//去除格子噪声
	CamWriteCmosSensor(0x7a, 0x4e);//denoise in low light,0x8e\0x4e\0x0e
	CamWriteCmosSensor(0x7b, 0x28);//the same as 0x86
	
	//black level
	CamWriteCmosSensor(0X1F, 0x20);//G target
	CamWriteCmosSensor(0X22, 0x20);//R target
	CamWriteCmosSensor(0X26, 0x20);//B target
	//模拟部分参数
	CamWriteCmosSensor(0X16, 0x01);//如果觉得黑色物体不够黑，有点偏红，将0x16写为0x03会有点改善   
	CamWriteCmosSensor(0xbb, 0x20);  // deglitch  对xclk整形
	CamWriteCmosSensor(0xeb, 0x30);
	CamWriteCmosSensor(0xf5, 0x21);
	CamWriteCmosSensor(0xe1, 0x3c);
	CamWriteCmosSensor(0xbb, 0x20);
	CamWriteCmosSensor(0X2f, 0Xf6);
	CamWriteCmosSensor(0x06, 0xe0);
		
	//anti black sun spot
	CamWriteCmosSensor(0x61, 0xb3);//0x61[3]=0 black sun disable
	CamWriteCmosSensor(0x79, 0xe5);//0x79[7]=0 black sun disable
	CamWriteCmosSensor(0x76, 0x04);
	CamWriteCmosSensor(0xe0, 0x0b);
	CamWriteCmosSensor(0x76, 0x04);
	CamWriteCmosSensor(0x16, 0x01);
	//contrast
	CamWriteCmosSensor(0x56, 0x40);
	
	//Gamma
	CamWriteCmosSensor(0x3b, 0x60);//auto gamma offset adjust in  low light 
	CamWriteCmosSensor(0x3c, 0x20);//auto gamma offset adjust in  low light 
	
	CamWriteCmosSensor(0x39, 0x80); 
	/*//gamma1
	CamWriteCmosSensor(0x3f, 0xb0);
	CamWriteCmosSensor(0X40, 0X88);
	CamWriteCmosSensor(0X41, 0X74);
	CamWriteCmosSensor(0X42, 0X5E);
	CamWriteCmosSensor(0X43, 0X4c);
	CamWriteCmosSensor(0X44, 0X44);
	CamWriteCmosSensor(0X45, 0X3E);
	CamWriteCmosSensor(0X46, 0X39);
	CamWriteCmosSensor(0X47, 0X35);
	CamWriteCmosSensor(0X48, 0X31);
	CamWriteCmosSensor(0X49, 0X2E);
	CamWriteCmosSensor(0X4b, 0X2B);
	CamWriteCmosSensor(0X4c, 0X29);
	CamWriteCmosSensor(0X4e, 0X25);
	CamWriteCmosSensor(0X4f, 0X22);
	CamWriteCmosSensor(0X50, 0X1F);*/
	
	//gamma2  过曝过度好，高亮度
	CamWriteCmosSensor(0x3f, 0xb6);//a8
	CamWriteCmosSensor(0X40, 0X9b);
	CamWriteCmosSensor(0X41, 0X88);
	CamWriteCmosSensor(0X42, 0X6e);
	CamWriteCmosSensor(0X43, 0X59);
	CamWriteCmosSensor(0X44, 0X4d);
	CamWriteCmosSensor(0X45, 0X45);
	CamWriteCmosSensor(0X46, 0X3e);
	CamWriteCmosSensor(0X47, 0X39);
	CamWriteCmosSensor(0X48, 0X35);
	CamWriteCmosSensor(0X49, 0X31);
	CamWriteCmosSensor(0X4b, 0X2e);
	CamWriteCmosSensor(0X4c, 0X2b);
	CamWriteCmosSensor(0X4e, 0X26);
	CamWriteCmosSensor(0X4f, 0X23);
	CamWriteCmosSensor(0X50, 0X21);
		
	/*//gamma3 清晰亮丽 灰阶分布好
	CamWriteCmosSensor(0X3f, 0Xb0);
	CamWriteCmosSensor(0X40, 0X60);
	CamWriteCmosSensor(0X41, 0X60);
	CamWriteCmosSensor(0X42, 0X66);
	CamWriteCmosSensor(0X43, 0X57);
	CamWriteCmosSensor(0X44, 0X4c);
	CamWriteCmosSensor(0X45, 0X43);
	CamWriteCmosSensor(0X46, 0X3c);
	CamWriteCmosSensor(0X47, 0X37);
	CamWriteCmosSensor(0X48, 0X33);
	CamWriteCmosSensor(0X49, 0X2f);
	CamWriteCmosSensor(0X4b, 0X2c);
	CamWriteCmosSensor(0X4c, 0X29);
	CamWriteCmosSensor(0X4e, 0X25);
	CamWriteCmosSensor(0X4f, 0X22);
	CamWriteCmosSensor(0X50, 0X20);
	
	//gamma 4	low noise	
	CamWriteCmosSensor(0X3f, 0Xa8);
	CamWriteCmosSensor(0X40, 0X48);
	CamWriteCmosSensor(0X41, 0X54);
	CamWriteCmosSensor(0X42, 0X4E);
	CamWriteCmosSensor(0X43, 0X44);
	CamWriteCmosSensor(0X44, 0X3E);
	CamWriteCmosSensor(0X45, 0X39);
	CamWriteCmosSensor(0X46, 0X35);
	CamWriteCmosSensor(0X47, 0X31);
	CamWriteCmosSensor(0X48, 0X2E);
	CamWriteCmosSensor(0X49, 0X2B);
	CamWriteCmosSensor(0X4b, 0X29);
	CamWriteCmosSensor(0X4c, 0X27);
	CamWriteCmosSensor(0X4e, 0X23);
	CamWriteCmosSensor(0X4f, 0X20);
	CamWriteCmosSensor(0X50, 0X20);
	*/
	
	/*//color matrix
	CamWriteCmosSensor(0x51, 0x0d);
	CamWriteCmosSensor(0x52, 0x21);
	CamWriteCmosSensor(0x53, 0x14);
	CamWriteCmosSensor(0x54, 0x15);
	CamWriteCmosSensor(0x57, 0x8d);
	CamWriteCmosSensor(0x58, 0x78);
	CamWriteCmosSensor(0x59, 0x5f);
	CamWriteCmosSensor(0x5a, 0x84);
	CamWriteCmosSensor(0x5b, 0x25);
	CamWriteCmosSensor(0x5D, 0x95);
	CamWriteCmosSensor(0x5C, 0x0e);
	*/
	
	
	// color  艳丽
	CamWriteCmosSensor(0x51, 0x0e);
	CamWriteCmosSensor(0x52, 0x16);
	CamWriteCmosSensor(0x53, 0x07);
	CamWriteCmosSensor(0x54, 0x1a);
	CamWriteCmosSensor(0x57, 0x9d);
	CamWriteCmosSensor(0x58, 0x82);
	CamWriteCmosSensor(0x59, 0x71);
	CamWriteCmosSensor(0x5a, 0x8d);
	CamWriteCmosSensor(0x5b, 0x1c);
	CamWriteCmosSensor(0x5D, 0x95);
	CamWriteCmosSensor(0x5C, 0x0e);
	
	
	
	/*
	//适中
	CamWriteCmosSensor(0x51, 0x08);
	CamWriteCmosSensor(0x52, 0x0E);
	CamWriteCmosSensor(0x53, 0x06);
	CamWriteCmosSensor(0x54, 0x12);
	CamWriteCmosSensor(0x57, 0x82);
	CamWriteCmosSensor(0x58, 0x70);
	CamWriteCmosSensor(0x59, 0x5C);
	CamWriteCmosSensor(0x5a, 0x77);
	CamWriteCmosSensor(0x5b, 0x1B);
	CamWriteCmosSensor(0x5c, 0x0e);//0x5c[3:0] low light color coefficient，smaller ,lower noise
	CamWriteCmosSensor(0x5d, 0x95);
	
	
	//color 淡
	CamWriteCmosSensor(0x51, 0x03);
	CamWriteCmosSensor(0x52, 0x0d);
	CamWriteCmosSensor(0x53, 0x0b);
	CamWriteCmosSensor(0x54, 0x14);
	CamWriteCmosSensor(0x57, 0x59);
	CamWriteCmosSensor(0x58, 0x45);
	CamWriteCmosSensor(0x59, 0x41);
	CamWriteCmosSensor(0x5a, 0x5f);
	CamWriteCmosSensor(0x5b, 0x1e);
	CamWriteCmosSensor(0x5c, 0x0e);//0x5c[3:0] low light color coefficient，smaller ,lower noise
	CamWriteCmosSensor(0x5d, 0x95);
	*/
	
	CamWriteCmosSensor(0x60, 0x20);//color open in low light 
	//AWB
	CamWriteCmosSensor(0x6a, 0x01);//如果肤色偏色，将0x6a写为0x81.
	CamWriteCmosSensor(0x23, 0x66);//Green gain
	CamWriteCmosSensor(0xa0, 0x03);//0xa0写0x03，黑色物体更红；0xa0写0x07，黑色物体更黑；
	
	CamWriteCmosSensor(0xa1, 0X41);//
	CamWriteCmosSensor(0xa2, 0X0e);
	CamWriteCmosSensor(0xa3, 0X26);
	CamWriteCmosSensor(0xa4, 0X0d);
	//冷色调
	CamWriteCmosSensor(0xa5, 0x2a);//The upper limit of red gain 
	
	
	/*暖色调
	CamWriteCmosSensor(0xa5, 0x2d);
	*/
	CamWriteCmosSensor(0xa6, 0x04);
	CamWriteCmosSensor(0xa7, 0x80);//BLUE Target
	CamWriteCmosSensor(0xa8, 0x80);//RED Target
	CamWriteCmosSensor(0xa9, 0x28);
	CamWriteCmosSensor(0xaa, 0x28);
	CamWriteCmosSensor(0xab, 0x28);
	CamWriteCmosSensor(0xac, 0x3c);
	CamWriteCmosSensor(0xad, 0xf0);
	CamWriteCmosSensor(0xc8, 0x18);
	CamWriteCmosSensor(0xc9, 0x20);
	CamWriteCmosSensor(0xca, 0x17);
	CamWriteCmosSensor(0xcb, 0x1f);
	CamWriteCmosSensor(0xaf, 0x00); 	  
	CamWriteCmosSensor(0xc5, 0x18);   
	CamWriteCmosSensor(0xc6, 0x00);
	CamWriteCmosSensor(0xc7, 0x20);   
	CamWriteCmosSensor(0xae, 0x83);//如果照户外偏蓝，将此寄存器0xae写为0x81。
	CamWriteCmosSensor(0xcc, 0x30);
	CamWriteCmosSensor(0xcd, 0x70);
	CamWriteCmosSensor(0xee, 0x4c);// P_TH
	
	// color saturation
	CamWriteCmosSensor(0xb0, 0x00);//d0
	/* 
	CamWriteCmosSensor(0xb1, 0xc0);
	CamWriteCmosSensor(0xb2, 0xb0);*/
	
	// 饱和度艳丽
	CamWriteCmosSensor(0xb1, 0xd0);
	CamWriteCmosSensor(0xb2, 0xc0);   
		
	CamWriteCmosSensor(0xb3, 0x88);
	
	//anti webcamera banding
	CamWriteCmosSensor(0x9d, 0x9f);
	
	//switch direction
	CamWriteCmosSensor(0x1e, 0x00);//00:normal	10:IMAGE_V_MIRROR	20:IMAGE_H_MIRROR  30:IMAGE_HV_MIRROR
}


/*************************************************************************
* FUNCTION
*  BF3703SetMirrorFlip
*
* DESCRIPTION
*   This function config the HVmirror of image sensor.
*
*************************************************************************/
 static void BF3703SetMirrorFlip(IMAGE_SENSOR_MIRROR_ENUM ImageMirrorFlip)
 {
	 switch (ImageMirrorFlip)
	 {
	 case IMAGE_SENSOR_MIRROR_NORMAL:
	        CamWriteCmosSensor(0x1e, 0x00);   
		 break;
	 case IMAGE_SENSOR_MIRROR_H:
		CamWriteCmosSensor(0x1e, 0x20);   
		 break;
	 case IMAGE_SENSOR_MIRROR_V:
		CamWriteCmosSensor(0x1e, 0x10);   
		 break;
	 case IMAGE_SENSOR_MIRROR_HV:
		 CamWriteCmosSensor(0x1e, 0x30);   
		 break;
	 default:
		 ASSERT(0);
	 }
 }   /* BF3703SetMirrorFlip */


/*************************************************************************
* FUNCTION
*    GC0308SetVideoFps
*
* DESCRIPTION
*    This function calculate & fix frame rate in video mode
*
* PARAMETERS
*    Fps: video frame rate, base on BF3703_FPS(x)
*
* RETURNS
*    Fps: real frame rate set by sensor
*
* LOCAL AFFECTED
*
*FOR EXAMPLE:
*	We wan't setting 7.5fps, frame_rate=75
*
*************************************************************************/
void BF3703SetVideoFps(kal_uint32 frame_rate)
{
		/*The real frame rate need /10*/
	kal_uint32 exposure_lines = BF3703_PV_PERIOD_LINE_NUMS;
	
	exposure_lines =VEDIO_MCLK*10/2/frame_rate/(BF3703_PV_PERIOD_PIXEL_NUMS + BF3703_dummy_pixels);
	
	BF3703_dummy_lines = exposure_lines - BF3703_PV_PERIOD_LINE_NUMS;
	
	BF3703_set_dummy(BF3703_dummy_pixels, BF3703_dummy_lines);//config max frame rate

	CamWriteCmosSensor(0x8E, (exposure_lines&0xFF00)>>8);
	CamWriteCmosSensor(0x8F, exposure_lines&0xFF);	//config min frame rate;
}


/*************************************************************************
* FUNCTION
*	BF3703_night_mode
*
* DESCRIPTION
*	This function night mode of BF3703.
*
* PARAMETERS
*	none
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void BF3703_night_mode(kal_bool enable,kal_uint32 vedio_framerate)
{
    if (enable == KAL_TRUE) 
		{	
		   BF3703_s_bNight_mode = KAL_TRUE;
		   if(BF3703_Vedio_mode == KAL_TRUE)
		  {
		  	CamWriteCmosSensor(0X85, 0X2a);
			CamWriteCmosSensor(0X86, 0X30);
			CamWriteCmosSensor(0x7b, 0x30);
			BF3703SetVideoFps(vedio_framerate);		   
		  }	
		 else 
		 {
		BF3703_dummy_pixels=32;
		BF3703_dummy_lines=64;
		BF3703_set_dummy(BF3703_dummy_pixels,BF3703_dummy_lines);//Max fps =30
	
		CamWriteCmosSensor(0X85, 0X2a);
		CamWriteCmosSensor(0X86, 0X3b);
		CamWriteCmosSensor(0x7b, 0x30);		
		CamWriteCmosSensor(0x8e, 0x0c);//0c
		CamWriteCmosSensor(0x8f, 0x75);// Min fps =5
		}
    	}
		else 
		{
		    #ifdef __DBG_SENSOR_TRACE__
				kal_print_string_trace(MOD_ENG, TRACE_INFO, "[IN] BF3703_night_mode is false");
         	   #endif
			BF3703_s_bNight_mode = KAL_FALSE;
			if(BF3703_Vedio_mode == KAL_TRUE)
			{
			CamWriteCmosSensor(0X86, 0X36);
			CamWriteCmosSensor(0x7b, 0x36);
			BF3703SetVideoFps(vedio_framerate);
			}
			else 
			{
				BF3703_dummy_pixels=32;
				BF3703_dummy_lines=64;
	  			BF3703_set_dummy(BF3703_dummy_pixels,BF3703_dummy_lines);//Max fps =30
				CamWriteCmosSensor(0X8e, 0X06);
				CamWriteCmosSensor(0x8f, 0x39);//Min fps =10
            }
	   }
}	/* BF3703_night_mode */

/*************************************************************************
* FUNCTION
*    BF3703SceneMode
*
* DESCRIPTION
*    This function get/set scene mode of sensor.
*
* PARAMETERS
*    IsCam: camera scene mode or not
*    In, Out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM BF3703SceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT SceneMode = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
    SceneMode->IsSupport = KAL_TRUE;
    SceneMode->ItemCount = 2;
    if (IsCam)
    {
      SceneMode->SupportItem[0] = CAM_AUTO_DSC;
      SceneMode->SupportItem[1] = CAM_NIGHTSCENE;
    }
    else
    {
      SceneMode->SupportItem[0] = CAM_VIDEO_AUTO;
      SceneMode->SupportItem[1] = CAM_VIDEO_NIGHT;
    }
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    kal_bool Enable;
    
    if (CAM_NIGHTSCENE == In->FeatureSetValue || CAM_VIDEO_NIGHT == In->FeatureSetValue)
    {
      Enable = KAL_TRUE;
    }
    else
    {
      Enable = KAL_FALSE;
    }
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    BF3703EV
*
* DESCRIPTION
*    BF3703 EV setting.
*
* PARAMETERS
*    Para
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM BF3703EV(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    P_CAL_FEATURE_TYPE_ENUM_STRUCT EvPara = &Out->FeatureInfo.FeatureEnum;
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION | CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    EvPara->IsSupport = KAL_TRUE;
    EvPara->ItemCount = 9;
    EvPara->SupportItem[0] = CAM_EV_NEG_4_3;
    EvPara->SupportItem[1] = CAM_EV_NEG_3_3;
    EvPara->SupportItem[2] = CAM_EV_NEG_2_3;
    EvPara->SupportItem[3] = CAM_EV_NEG_1_3;
    EvPara->SupportItem[4] = CAM_EV_ZERO;
    EvPara->SupportItem[5] = CAM_EV_POS_1_3;
    EvPara->SupportItem[6] = CAM_EV_POS_2_3;
    EvPara->SupportItem[7] = CAM_EV_POS_3_3;
    EvPara->SupportItem[8] = CAM_EV_POS_4_3;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
#ifdef BF3703_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"EV:%d",iEvTemp);
#endif

    switch (In->FeatureSetValue)
	{
		case CAM_EV_NEG_4_3:    
            CamWriteCmosSensor(0x55, 0xF8);		
			break;		
		case CAM_EV_NEG_3_3:
            CamWriteCmosSensor(0x55, 0xD8);
			break;		
		case CAM_EV_NEG_2_3:
            CamWriteCmosSensor(0x55, 0xB8);
			break;				
		case CAM_EV_NEG_1_3:
            CamWriteCmosSensor(0x55, 0x98);
			break;				
		case CAM_EV_ZERO:
            CamWriteCmosSensor(0x55, 0x00);
			break;				
		case CAM_EV_POS_1_3:
            CamWriteCmosSensor(0x55, 0x18);
			break;				
		case CAM_EV_POS_2_3:
            CamWriteCmosSensor(0x55, 0x30);
			break;				
		case CAM_EV_POS_3_3:
            CamWriteCmosSensor(0x55, 0x50);
			break;				
		case CAM_EV_POS_4_3:	
            CamWriteCmosSensor(0x55, 0x7c);
			break;
		default:
			break;    
	}
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    BF3703WB
*
* DESCRIPTION
*    BF3703 WB setting.
*
* PARAMETERS
*    Para
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM BF3703WB(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    P_CAL_FEATURE_TYPE_ENUM_STRUCT WBPara = &Out->FeatureInfo.FeatureEnum;
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION | CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    WBPara->IsSupport = KAL_TRUE;
    WBPara->ItemCount = 6;
    WBPara->SupportItem[0] = CAM_WB_AUTO;
    WBPara->SupportItem[1] = CAM_WB_CLOUD;
    WBPara->SupportItem[2] = CAM_WB_DAYLIGHT;
    WBPara->SupportItem[3] = CAM_WB_INCANDESCENCE;
    WBPara->SupportItem[4] = CAM_WB_FLUORESCENT;
    WBPara->SupportItem[5] = CAM_WB_TUNGSTEN;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    kal_uint8  temp_reg;
	#ifdef BF3703_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"WB:%d",WBTemp);
#endif
	
	temp_reg=CamReadCmosSensor(0x13);
	
	switch (In->FeatureSetValue)
	{
		case CAM_WB_AUTO:
			CamWriteCmosSensor(0x13,temp_reg|0x2);   // Enable AWB		
			break;

		case CAM_WB_CLOUD:
			CamWriteCmosSensor(0x13,temp_reg&~0x2);  // Disable AWB				
			CamWriteCmosSensor(0x01, 0x0e);
			CamWriteCmosSensor(0x02, 0x23);
			break;		

		case CAM_WB_DAYLIGHT:
			CamWriteCmosSensor(0x13,temp_reg&~0x2);  // Disable AWB				
			CamWriteCmosSensor(0x01, 0x0f);
			CamWriteCmosSensor(0x02, 0x21);
			break;		

		case CAM_WB_INCANDESCENCE:
			CamWriteCmosSensor(0x13,temp_reg&~0x2);  // Disable AWB				
			CamWriteCmosSensor(0x01, 0x1d);
			CamWriteCmosSensor(0x02, 0x14);
			break;		

		case CAM_WB_FLUORESCENT:
			CamWriteCmosSensor(0x13,temp_reg&~0x2);  // Disable AWB				
			CamWriteCmosSensor(0x01, 0x1d);
			CamWriteCmosSensor(0x02, 0x1a);
			break;		

		case CAM_WB_TUNGSTEN:
			CamWriteCmosSensor(0x13,temp_reg&~0x2);  // Disable AWB				
			CamWriteCmosSensor(0x01, 0x1f);
			CamWriteCmosSensor(0x02, 0x0f);
			break;

		case CAM_WB_MANUAL:		
		    // TODO
			break;		

		default:
			break;	;			
	}
  }
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    BF3703Effect
*
* DESCRIPTION
*    BF3703 Effect setting.
*
* PARAMETERS
*    Para
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM BF3703Effect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    P_CAL_FEATURE_TYPE_ENUM_STRUCT EffectPara = &Out->FeatureInfo.FeatureEnum;
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION | CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    EffectPara->IsSupport = KAL_TRUE;
    EffectPara->ItemCount = 14;
    EffectPara->SupportItem[0] = CAM_EFFECT_ENC_NORMAL;
    EffectPara->SupportItem[1] = CAM_EFFECT_ENC_GRAYSCALE;
    EffectPara->SupportItem[2] = CAM_EFFECT_ENC_SEPIA;
    EffectPara->SupportItem[3] = CAM_EFFECT_ENC_SEPIAGREEN;
    EffectPara->SupportItem[4] = CAM_EFFECT_ENC_SEPIABLUE;
    EffectPara->SupportItem[5] = CAM_EFFECT_ENC_COLORINV;
	EffectPara->SupportItem[6] = CAM_EFFECT_ENC_GRAYINV;
	EffectPara->SupportItem[7] = CAM_EFFECT_ENC_BLACKBOARD;
	EffectPara->SupportItem[8] = CAM_EFFECT_ENC_WHITEBOARD;
	EffectPara->SupportItem[9] = CAM_EFFECT_ENC_COPPERCARVING;
	EffectPara->SupportItem[10] = CAM_EFFECT_ENC_BLUECARVING;
	EffectPara->SupportItem[11] = CAM_EFFECT_ENC_EMBOSSMENT;
	EffectPara->SupportItem[12] = CAM_EFFECT_ENC_SKETCH;
	EffectPara->SupportItem[13] = CAM_EFFECT_ENC_CONTRAST;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
#ifdef BF3703_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO,"Effect:%d",In->FeatureSetValue);
#endif
  switch (In->FeatureSetValue)
	{	
		case CAM_EFFECT_ENC_NORMAL:
			CamWriteCmosSensor(0x80,0x45);		
			CamWriteCmosSensor(0x76,0x00);		
			CamWriteCmosSensor(0x69,0x00);
			CamWriteCmosSensor(0x67,0x80);		
			CamWriteCmosSensor(0x68,0x80);
			CamWriteCmosSensor(0x56,0x40);	
			break;		
		case CAM_EFFECT_ENC_GRAYSCALE:
			CamWriteCmosSensor(0x80,0x45);		
			CamWriteCmosSensor(0x76,0x00);		
			CamWriteCmosSensor(0x69,0x20);
			CamWriteCmosSensor(0x67,0x80);		
			CamWriteCmosSensor(0x68,0x80);
			CamWriteCmosSensor(0x56,0x40);		
			break;		
		case CAM_EFFECT_ENC_SEPIA:
			CamWriteCmosSensor(0x80,0x45);		
			CamWriteCmosSensor(0x76,0x00);		
			CamWriteCmosSensor(0x69,0x20);
			CamWriteCmosSensor(0x67,0x60);		
			CamWriteCmosSensor(0x68,0x98);
			CamWriteCmosSensor(0x56,0x40);	
			break;		
		case CAM_EFFECT_ENC_SEPIAGREEN:
			CamWriteCmosSensor(0x80,0x45);		
			CamWriteCmosSensor(0x76,0x00);		
			CamWriteCmosSensor(0x69,0x20);
			CamWriteCmosSensor(0x67,0x70);		
			CamWriteCmosSensor(0x68,0x60);
			CamWriteCmosSensor(0x56,0x40);		
			break;					
		case CAM_EFFECT_ENC_SEPIABLUE:
			CamWriteCmosSensor(0x80,0x45);		
			CamWriteCmosSensor(0x76,0x00);		
			CamWriteCmosSensor(0x69,0x20);
			CamWriteCmosSensor(0x67,0xB0);		
			CamWriteCmosSensor(0x68,0x70);
			CamWriteCmosSensor(0x56,0x40);		
			break;								
		case CAM_EFFECT_ENC_COLORINV:
			CamWriteCmosSensor(0x80,0x45);		
			CamWriteCmosSensor(0x76,0x00);		
			CamWriteCmosSensor(0x69,0x40);
			CamWriteCmosSensor(0x67,0x80);		
			CamWriteCmosSensor(0x68,0x80);
			CamWriteCmosSensor(0x56,0x40);	
			break;	
		case CAM_EFFECT_ENC_GRAYINV:
			CamWriteCmosSensor(0x80,0x45);		
			CamWriteCmosSensor(0x76,0x00);		
			CamWriteCmosSensor(0x69,0x60);
			CamWriteCmosSensor(0x67,0x80);		
			CamWriteCmosSensor(0x68,0x80);
			CamWriteCmosSensor(0x56,0x40);	
			break;
		case CAM_EFFECT_ENC_BLACKBOARD:
			CamWriteCmosSensor(0x69,0x00);
			CamWriteCmosSensor(0x80,0xC5);		
			CamWriteCmosSensor(0x76,0xE0);	
			CamWriteCmosSensor(0x67,0x80);		
			CamWriteCmosSensor(0x68,0x80);
			CamWriteCmosSensor(0x56,0x40);	
			break;
		case CAM_EFFECT_ENC_WHITEBOARD:
			CamWriteCmosSensor(0x69,0x00);
			CamWriteCmosSensor(0x80,0xC5);		
			CamWriteCmosSensor(0x76,0xF0);	
			CamWriteCmosSensor(0x67,0x80);		
			CamWriteCmosSensor(0x68,0x80);
			CamWriteCmosSensor(0x56,0x40);	
			break;
		case CAM_EFFECT_ENC_COPPERCARVING:
			CamWriteCmosSensor(0x69,0x00);
			CamWriteCmosSensor(0x80,0xC5);		
			CamWriteCmosSensor(0x76,0xC0);	
			CamWriteCmosSensor(0x67,0x80);		
			CamWriteCmosSensor(0x68,0x80);
			CamWriteCmosSensor(0x56,0x40);	
			break;
		case CAM_EFFECT_ENC_BLUECARVING:
			CamWriteCmosSensor(0x69,0x00);
			CamWriteCmosSensor(0x80,0xC5);		
			CamWriteCmosSensor(0x76,0xD0);	
			CamWriteCmosSensor(0x67,0x80);		
			CamWriteCmosSensor(0x68,0x80);
			CamWriteCmosSensor(0x56,0x40);	
			break;
		case CAM_EFFECT_ENC_EMBOSSMENT:
			CamWriteCmosSensor(0x69,0x00);
			CamWriteCmosSensor(0x80,0xC5);		
			CamWriteCmosSensor(0x76,0x80);	
			CamWriteCmosSensor(0x67,0x80);		
			CamWriteCmosSensor(0x68,0x80);
			CamWriteCmosSensor(0x56,0x40);	
			break;
		case CAM_EFFECT_ENC_SKETCH:
			CamWriteCmosSensor(0x69,0x00);
			CamWriteCmosSensor(0x80,0xC5);		
			CamWriteCmosSensor(0x76,0xB0);
			CamWriteCmosSensor(0x67,0x80);		
			CamWriteCmosSensor(0x68,0x80);
			CamWriteCmosSensor(0x56,0x40);	
			break;
		case CAM_EFFECT_ENC_CONTRAST:
			CamWriteCmosSensor(0x80,0x45);		
			CamWriteCmosSensor(0x76,0x00);		
			CamWriteCmosSensor(0x69,0x20);
			CamWriteCmosSensor(0x67,0x80);		
			CamWriteCmosSensor(0x68,0x80);
			CamWriteCmosSensor(0x56,0xA8);	
			break;
		default:
			break;
	}
  }   
  return MM_ERROR_NONE;
}


void BF3703_set_banding_for_50Hz(void)
{
	kal_uint16 temp_reg = 0;
	/* Some sensor call base shutter as banding filter. */
	kal_uint32 line_length = 0, sensor_pixel_clock = 0;
	line_length = BF3703_PV_PERIOD_PIXEL_NUMS + DUMMY_PIXELS;
	sensor_pixel_clock = BF3703_PREVIEW_PCLK * 100 * 1000;

	temp_reg = CamReadCmosSensor(0x80);
		
	CamWriteCmosSensor(0x80, temp_reg); 
	CamWriteCmosSensor(0x9d, sensor_pixel_clock/200/line_length);
}


void BF3703_set_banding_for_60Hz(void)
{   
	kal_uint16 temp_reg = 0;
	/* Some sensor call base shutter as banding filter. */
	kal_uint32 line_length = 0, sensor_pixel_clock = 0;
	line_length = BF3703_PV_PERIOD_PIXEL_NUMS + DUMMY_PIXELS;
	sensor_pixel_clock = BF3703_PREVIEW_PCLK * 100 * 1000;

	temp_reg = CamReadCmosSensor(0x80);
	
	CamWriteCmosSensor(0x80, temp_reg&0xFE);	
	CamWriteCmosSensor(0x9E, sensor_pixel_clock/240/line_length);
}

/*************************************************************************
* FUNCTION
*    BF3703Banding
*
* DESCRIPTION
*    This function get capture size
*
* PARAMETERS
*    In, Out, out_len, r_out_len
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM BF3703Banding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  P_CAL_FEATURE_TYPE_ENUM_STRUCT Banding = (P_CAL_FEATURE_TYPE_ENUM_STRUCT)&(Out->FeatureInfo.FeatureEnum);
  switch (In->FeatureCtrlCode)
  {
    case CAL_FEATURE_QUERY_OPERATION:
      Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
      Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|
                               CAL_FEATURE_GET_OPERATION|
                               CAL_FEATURE_QUERY_OPERATION;
      Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
      Banding->IsSupport = KAL_TRUE;
      Banding->ItemCount = 2;
      Banding->SupportItem[0] = CAM_BANDING_50HZ;
      Banding->SupportItem[1] = CAM_BANDING_60HZ;
      break;
	 case CAL_FEATURE_SET_OPERATION:	
		switch (In->FeatureSetValue)
		{
			case CAM_BANDING_50HZ:
				 BF3703_set_banding_for_50Hz();
				 break;
			case CAM_BANDING_60HZ:
				 BF3703_set_banding_for_60Hz();
				 break;
			default:
				break;		
		}	
		break;
  }
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    BF3703AeEnable
*
* DESCRIPTION
*    disable/enable AE
*
* PARAMETERS
*    Enable
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM BF3703AeEnable(kal_bool Enable)
{
	kal_uint16 TempAe = 0;
	TempAe = CamReadCmosSensor(0x13);
  	if (Enable)	
	{
		TempAe =TempAe | 0x01; 
	}
	else
	{
		TempAe = TempAe&(~0x01); 
	}
	CamWriteCmosSensor(0x13, TempAe); 
#ifdef BF3703_DEBUG
  kal_prompt_trace(MOD_ENG,"AEenable:%d",Enable);
#endif

  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    BF3703AwbEnable
*
* DESCRIPTION
*    disable/enable awb
*
* PARAMETERS
*    Enable
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM BF3703AwbEnable(kal_bool Enable)
{
	kal_uint16 TempAwb = 0;
	TempAwb = CamReadCmosSensor(0x13);
  	if (Enable)	
	{
		TempAwb |= 0x02;
	}
	else
	{
		TempAwb &= (0xfd);
	}
	CamWriteCmosSensor(0x13, TempAwb); 
#ifdef BF3703_DEBUG
  kal_prompt_trace(MOD_ENG,"AWBenable:%d",Enable);
#endif

  return MM_ERROR_NONE;
}

void BF3703GetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT SensorInfo) 
{
	SensorInfo->SensorId			=	BF3703_SENSOR_ID;

	SensorInfo->SensorIf			=	IMAGE_SENSOR_IF_PARALLEL;
	SensorInfo->PreviewNormalDataFormat	=	IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
	SensorInfo->PreviewHMirrorDataFormat 	= 	IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
	SensorInfo->PreviewVMirrorDataFormat 	= 	IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
	SensorInfo->PreviewHVMirrorDataFormat 	= 	IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY; 
	SensorInfo->CaptureDataFormat	=	IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;

	SensorInfo->PixelClkInv			=	KAL_FALSE;
	SensorInfo->PixelClkPolarity	=	POLARITY_LOW;
	SensorInfo->HsyncPolarity		=	POLARITY_LOW;	/* Active High, it's inversed. */
	SensorInfo->VsyncPolarity		=	POLARITY_LOW;

	SensorInfo->PreviewMclkFreq 	= 	PREVIEW_MCLK;
	SensorInfo->CaptureMclkFreq 	= 	CAPTURE_MCLK;
	SensorInfo->VideoMclkFreq 		= 	VEDIO_MCLK;

	SensorInfo->PreviewWidth		=	BF3703_IMAGE_SENSOR_VGA_WIDTH;
	SensorInfo->PreviewHeight		=	BF3703_IMAGE_SENSOR_VGA_HEIGHT;
	SensorInfo->FullWidth			=	BF3703_IMAGE_SENSOR_VGA_WIDTH;
	SensorInfo->FullHeight			=	BF3703_IMAGE_SENSOR_VGA_HEIGHT;

	SensorInfo->SensorAfSupport	=	KAL_FALSE;
	SensorInfo->SensorFlashSupport	=	KAL_FALSE;
}	/* BF3703GetSensorInfo() */


static kal_uint16 BF3703PowerOn(void)
{
  	CisModulePowerOn(SensorIdxBF3703, KAL_TRUE);
	kal_sleep_task(1);				    // To wait for Stable Power, at least 5ms

	CamPdnPinCtrl(SensorIdxBF3703, 0);	/* Set Power Down Pin Low */
	kal_sleep_task(1);

	CamRstPinCtrl(SensorIdxBF3703, 1);	/* Set Reset Pin High */
	kal_sleep_task(1);
	CamRstPinCtrl(SensorIdxBF3703, 0);	/* Set Reset Pin Low */
 	kal_sleep_task(4);
  	CamRstPinCtrl(SensorIdxBF3703, 1);	/* Set Reset Pin Low */
 	 kal_sleep_task(2); 
  
  
	CameraSccbOpen(CAMERA_SCCB_SENSOR, BF3703_WRITE_ID, CAMERA_SCCB_8BIT, CAMERA_SCCB_8BIT, 400);
    
	// SW Reset Sensor
	CamWriteCmosSensor(0x12,0x80);
	kal_sleep_task(1); 
	
	BF3703_sensor_id = (CamReadCmosSensor(0xFC)<<8)|CamReadCmosSensor(0xFD);	

	return BF3703_sensor_id;
} /* BF3703PowerOn() */

/*************************************************************************
* FUNCTION
*    MC501CBDetectSensorId
*
* DESCRIPTION
*    This function detect sensor id
*
* PARAMETERS
*    None
*
* RETURNS
*    sensor id
*
* LOCAL AFFECTED
*
*************************************************************************/
kal_uint32 BF3703DetectSensorId(void)
{	
    kal_uint32 SensorId=0;
	IMAGE_SENSOR_INDEX_ENUM ToPdnIdx = (IMAGE_SENSOR_MAIN == SensorIdxBF3703 ? IMAGE_SENSOR_SUB : IMAGE_SENSOR_MAIN);
	kal_int8 i = 0, j = 0;
	for (i = 1; i >= 0; i--)
	{
		for (j = 1; j >= 0; j--)
		{
			/* Make the other camera into power down state. */
			CamRstPinCtrl(ToPdnIdx, i);
			CamRstPinCtrl(ToPdnIdx, j);
			
			SensorId = BF3703PowerOn();
			
			BF3703SensorClose();
			
			if (BF3703_SENSOR_ID == SensorId)
			{
				return BF3703_SENSOR_ID;
			}
		}
	}

    return MM_ERROR_SENSOR_READ_ID_FAIL;
}   /* BF3703DetectSensorId() */


MM_ERROR_CODE_ENUM BF3703StillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In,
										   P_CAL_FEATURE_CTRL_STRUCT Out)
{
	MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
	P_CAL_FEATURE_TYPE_ENUM_STRUCT pStillCaptureSize = NULL;

	pStillCaptureSize = (P_CAL_FEATURE_TYPE_ENUM_STRUCT) &(Out->FeatureInfo.FeatureEnum);
	switch (In->FeatureCtrlCode)
	{
	case CAL_FEATURE_QUERY_OPERATION:
		Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
		Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION 
									| CAL_FEATURE_GET_OPERATION 
									| CAL_FEATURE_QUERY_OPERATION;
		
		Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
		
		pStillCaptureSize->IsSupport = KAL_TRUE;
		pStillCaptureSize->ItemCount = 2;
		pStillCaptureSize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
		pStillCaptureSize->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
		ErrCode = MM_ERROR_NONE;
		break;
	default:
		ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		break;
	}

	return ErrCode;
}   /* BF3703StillCaptureSize() */

void BF3703InitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT Para)
{
	Para->CaptureDelayFrame = 2; 		/* wait stable frame when sensor change mode (pre to cap) */
	Para->PreviewDelayFrame = 5; 		/* wait stable frame when sensor change mode (cap to pre) */
	Para->PreviewDisplayWaitFrame = 2; 	/* wait stable frame when sensor change mode (cap to pre) */
} /* BF3703InitOperationPara() */

static kal_uint8 BandingFlag = 0;
MM_ERROR_CODE_ENUM BF3703Preview(CAL_SCENARIO_ENUM ScenarioId,
								  P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT in,
								  P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT out)
{
	MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;
	switch (ScenarioId)
	{
	case CAL_SCENARIO_VIDEO:
		BF3703_Vedio_mode=KAL_TRUE;
		out->WaitStableFrameNum = 3;
		break;
	case CAL_SCENARIO_CAMERA_PREVIEW:
	case CAL_SCENARIO_WEBCAM_PREVIEW:
	case CAL_SCENARIO_WEBCAM_CAPTURE:
		BF3703_Vedio_mode=KAL_FALSE;
		out->WaitStableFrameNum = 5;
		break;
	default:
		ErrorCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		break;
	}

	BF3703SetMirrorFlip(in->ImageMirror);
		
	if (BandingFlag != in->BandingFreq)
		{
		BandingFlag = in->BandingFreq;
		BF3703AeEnable(KAL_FALSE);
		kal_sleep_task(10);
		BF3703AeEnable(KAL_TRUE);
		}
	
	BF3703AwbEnable(KAL_TRUE);
	BF3703_night_mode(in->NightMode,in->MaxVideoFrameRate);

	if (CAM_BANDING_50HZ == in->BandingFreq)
		BF3703_set_banding_for_50Hz();
	else
		BF3703_set_banding_for_60Hz();
	
	out->GrabStartX = BF3703_IMAGE_SENSOR_VGA_INSERTED_PIXELS;
	out->GrabStartY = BF3703_IMAGE_SENSOR_VGA_INSERTED_LINES;
	out->ExposureWindowWidth = BF3703_IMAGE_SENSOR_VGA_WIDTH-16;
	out->ExposureWindowHeight = BF3703_IMAGE_SENSOR_VGA_HEIGHT - 6;
	
	kal_sleep_task(100);
	
	return ErrorCode;
} /* BF3703Preview */

MM_ERROR_CODE_ENUM BF3703Capture(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT in,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT out)
{
	MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;
	out->GrabStartX = BF3703_IMAGE_SENSOR_VGA_INSERTED_PIXELS;
	out->GrabStartY = BF3703_IMAGE_SENSOR_VGA_INSERTED_LINES;
	out->ExposureWindowWidth = BF3703_IMAGE_SENSOR_VGA_WIDTH - 16;
	out->ExposureWindowHeight = BF3703_IMAGE_SENSOR_VGA_HEIGHT - 6;
	
	return ErrorCode;
} 	/* BF3703Capture() */

MM_ERROR_CODE_ENUM BF3703SensorOpen(void)
{
	kal_uint16 SensorId;
	SensorId = BF3703PowerOn();
	if (BF3703_SENSOR_ID != SensorId)
		return MM_ERROR_SENSOR_READ_ID_FAIL;

	BF3703_init_setting();
  
	return MM_ERROR_NONE;
} /* BF3703SensorOpen() */

/*************************************************************************
* FUNCTION
*    BF3703SensorFeatureCtrl
*
* DESCRIPTION
*    This function set sensor feature mode
*
* PARAMETERS
*    id: scenario id
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM BF3703SensorFeatureCtrl(kal_uint32 id, void *In, void *Out, kal_uint32 out_len, kal_uint32 *r_out_len)
{
	MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
	P_CAL_FEATURE_CTRL_STRUCT pCameraFeatureIn=(P_CAL_FEATURE_CTRL_STRUCT) In;
	P_CAL_FEATURE_CTRL_STRUCT pCameraFeatureOut=(P_CAL_FEATURE_CTRL_STRUCT) Out;
	P_CAL_FEATURE_TYPE_ENUM_STRUCT pCamFeatureEnum=(P_CAL_FEATURE_TYPE_ENUM_STRUCT) &(pCameraFeatureOut->FeatureInfo.FeatureEnum);

  if (id >= CAL_FEATURE_WEBCAM_BEGIN && id <= CAL_FEATURE_WEBCAM_END)
  {
    return BF3703WebcamFeatureCtrl(id, In, Out, out_len, r_out_len);
  }

  if(Out!=NULL && CAL_FEATURE_QUERY_OPERATION==pCameraFeatureIn->FeatureCtrlCode){
        pCamFeatureEnum->IsSupport = KAL_FALSE;
  }

  switch (id)
  {
     /* CAL Query and set series */
    case CAL_FEATURE_CAMERA_BRIGHTNESS:
    case CAL_FEATURE_CAMERA_EV_VALUE:
      ErrCode = BF3703EV(In, Out);
      break;
    case CAL_FEATURE_CAMERA_CONTRAST:
    case CAL_FEATURE_CAMERA_HUE:
    case CAL_FEATURE_CAMERA_SATURATION:
    case CAL_FEATURE_CAMERA_SHARPNESS:
    case CAL_FEATURE_CAMERA_GAMMA:
      ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
      break;
    case CAL_FEATURE_CAMERA_WB:
      ErrCode = BF3703WB(In, Out);
      break;
    case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
      ErrCode = BF3703Effect(In, Out);
      break;
    case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
      ErrCode = BF3703StillCaptureSize(In, Out);
      break;
    case CAL_FEATURE_CAMERA_BANDING_FREQ:
      ErrCode = BF3703Banding(In, Out);
      break;
	case CAL_FEATURE_CAMERA_SCENE_MODE:
      ErrCode = BF3703SceneMode(KAL_TRUE, In, Out);
      break;
    case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
      ErrCode = BF3703SceneMode(KAL_FALSE, In, Out);
      break;
    case CAL_FEATURE_CAMERA_FLASH_MODE:
      ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
      break;

    /* Get Info series */
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
      BF3703GetSensorInfo((P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT)Out);
      break;
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
      ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = BF3703DetectSensorId();
      break;
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
		// TODO: Need implement the video night function and then update it.
      ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = 150;
      break;
    case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
      BF3703InitOperationPara((P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT)Out);
      break;

	case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
		CamPdnPinCtrl(SensorIdxBF3703, 1);
		break;
    /* Set Para series */
    case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
      ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
      break;      
    case IMAGE_SENSOR_FEATURE_VSYNC_HISR_INFORM_FRAME_TIME:
    break;      
    case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
      SensorIdxBF3703 = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
      break;
    case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
      break;     
	case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
		ErrCode = BF3703AeEnable((kal_bool)(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue));
		break;
	case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
		ErrCode = BF3703AwbEnable((kal_bool)(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue));
		break;
	case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
	    CamGetHWInfo(SensorIdxBF3703, Out);
	    break;
    default:
      ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
      break;
  }
  return ErrCode;
}



/*************************************************************************
* FUNCTION
*    BF3703SensorFeatureCtrl
*
* DESCRIPTION
*    This function set sensor run preview or capture mode
*
* PARAMETERS
*    id: scenario id
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM BF3703SensorCtrl(CAL_SCENARIO_ENUM ScenarioId, void *pParaIn,
                                         void *pParaOut, kal_uint32 ParaOutLen, kal_uint32 *RealOutLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
    switch (ScenarioId)
    {
        case CAL_SCENARIO_CAMERA_PREVIEW:
        case CAL_SCENARIO_VIDEO:
        case CAL_SCENARIO_WEBCAM_PREVIEW:
        case CAL_SCENARIO_WEBCAM_CAPTURE:
            BF3703Preview(ScenarioId, pParaIn, pParaOut);
        break;
        case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
            BF3703Capture(ScenarioId, pParaIn, pParaOut);
        break;
        default:
        break;
    }
    return ErrorCode;
}



/*************************************************************************
* FUNCTION
*    BF3703SensorClose
*
* RETURNS
*    error code
*
*************************************************************************/

MM_ERROR_CODE_ENUM BF3703SensorClose(void)
{
	CameraSccbClose(CAMERA_SCCB_SENSOR);
	
  	CisModulePowerOn(SensorIdxBF3703, KAL_FALSE);

	CamPdnPinCtrl(SensorIdxBF3703, 1);	/* Set Power Down Pin High */

    return MM_ERROR_NONE;
}



/*************************************************************************
* FUNCTION
*    BF3703SensorFunc
*
* DESCRIPTION
*    This function get sensor function pointer
*
* PARAMETERS
*    sensor function pointer
*
* RETURNS
*    error code
*
* GLOBALS AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM BF3703SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
	static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncBF3703=
	{
		BF3703SensorOpen,
		BF3703SensorFeatureCtrl,
		BF3703SensorCtrl,
		BF3703SensorClose,
	};

	*pfSensorFunc = &ImageSensorFuncBF3703;

	return MM_ERROR_NONE;
}


