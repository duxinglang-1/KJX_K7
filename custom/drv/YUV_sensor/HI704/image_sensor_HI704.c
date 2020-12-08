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
 *   image_sensor_HI704.c
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
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/ 
#include "drv_comm.h"
#include "isp_comm_if.h"
#include "camera_sccb.h"
#include "image_sensor.h"
#include "cal_comm_def.h"
#include "isp_if.h"

//#define HI704_DEBUG 
static struct 
{
      kal_bool      PvMode;                 //True: Preview Mode; False: Capture Mode
      kal_bool      NightMode;              //True: Night Mode; False: Auto Mode
      kal_bool      VideoMode;     
      kal_uint8     mirror;
      kal_uint32    PvPclk;               //Preview Pclk
      kal_uint32    CpPclk;               //Capture Pclk
      kal_uint16    DummyPixels;          //Dummy Pixels
      kal_uint16    DummyLines;           //Dummy Lines
      kal_uint16     Fps;         
      kal_bool      BypassAe;
      kal_bool      BypassAwb;
      kal_uint8     Wb;
   //   kal_uint32    Exposure;
   //   kal_uint8     Effect;
      kal_uint8     Banding;
      kal_uint16    PvLineLength;
      kal_uint16    PvFrameHeight;
      kal_uint16    CpLineLength;
      kal_uint16    CpFrameHeight;
      IMAGE_SENSOR_INDEX_ENUM SensorIdx;
      sensor_data_struct *NvramData; //Need to check if need this item
}HI704Sensor;

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

const HI704InitInfo HI704InitialSettingInfo[] =
{
    //PAGE 0
    //Image Size/Windowing/HSYNC/VSYNC[Type1]
    {0x03, 0x00},   //PAGEMODE(0x03)
    
    #if 0   //jun debug for init sequency
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
   
    {0x11, 0x90},   //For No Fixed Framerate Bit[2]
    {0x12, 0x00},
        
    {0x20, 0x00},
    {0x21, 0x04},
    {0x22, 0x00},
    {0x23, 0x04},

	{0x24, 0x01},
    {0x25, 0xe0},
    {0x26, 0x02},
    {0x27, 0x80},

	{0x40, 0x00},   //HBLANK: 0x70 = 112
    {0x41, 0x70},
    {0x42, 0x00},   //VBLANK: 0x40 = 64
    {0x43, 0x40},   //0x04 -> 0x40: For Max Framerate = 30fps
            
    //BLC
    {0x80, 0x2e},
    {0x81, 0x7e},
    {0x82, 0x90},
    {0x83, 0x30},
    {0x84, 0x2c},
    {0x85, 0x4b},
    {0x89, 0x48},
        
    {0x90, 0x0b},
    {0x91, 0x0b},    
    {0x92, 0x48},
    {0x93, 0x48},
    {0x98, 0x38},
    {0x99, 0x40},
    {0xa0, 0x00},
    {0xa8, 0x40},
    
    //PAGE 2
    //Analog Circuit
    {0x03, 0x02},      
    {0x13, 0x40},
    {0x14, 0x04},
    {0x1a, 0x00},
    {0x1b, 0x08},
        
    {0x20, 0x33},
    {0x21, 0xaa},
    {0x22, 0xa7},
    {0x23, 0xb1},       //For Sun Pot
        
    {0x3b, 0x48},
        
    {0x50, 0x21},
    {0x52, 0xa2},
    {0x53, 0x0a},
    {0x54, 0x30},
    {0x55, 0x10},
    {0x56, 0x0c},
    {0x59, 0x0F},
        
    {0x60, 0x54},
    {0x61, 0x5d},
    {0x62, 0x56},
    {0x63, 0x5c},
    {0x64, 0x56},
    {0x65, 0x5c},
    {0x72, 0x57},
    {0x73, 0x5b},
    {0x74, 0x57},
    {0x75, 0x5b},
    {0x80, 0x02},
    {0x81, 0x46},
    {0x82, 0x07},
    {0x83, 0x10},
    {0x84, 0x07},
    {0x85, 0x10},
    {0x92, 0x24},
    {0x93, 0x30},
    {0x94, 0x24},
    {0x95, 0x30},
    {0xa0, 0x03},
    {0xa1, 0x45},
    {0xa4, 0x45},
    {0xa5, 0x03},
    {0xa8, 0x12},
    {0xa9, 0x20},
    {0xaa, 0x34},
    {0xab, 0x40},
    {0xb8, 0x55},
    {0xb9, 0x59},
    {0xbc, 0x05},
    {0xbd, 0x09},
    {0xc0, 0x5f},
    {0xc1, 0x67},
    {0xc2, 0x5f},
    {0xc3, 0x67},
    {0xc4, 0x60},
    {0xc5, 0x66},
    {0xc6, 0x60},
    {0xc7, 0x66},
    {0xc8, 0x61},
    {0xc9, 0x65},
    {0xca, 0x61},
    {0xcb, 0x65},
    {0xcc, 0x62},
    {0xcd, 0x64},
    {0xce, 0x62},
    {0xcf, 0x64},
    {0xd0, 0x53},
    {0xd1, 0x68},
     
    //PAGE 10
    //Image Format, Image Effect
    {0x03, 0x10},
    {0x10, 0x03},
    {0x11, 0x43},
    {0x12, 0x30},
        
    {0x40, 0x80},
    {0x41, 0x02},
    {0x48, 0x98},
        
    {0x50, 0x48},
           
    {0x60, 0x7f},
    {0x61, 0x00},
    {0x62, 0xb0},
    {0x63, 0xa8},
    {0x64, 0x48},
    {0x66, 0x90},
    {0x67, 0x42},
    
    //PAGE 11
    //Z-LPF
    {0x03, 0x11},
    {0x10, 0x25},   
    {0x11, 0x1f},   
        
    {0x20, 0x00},   
    {0x21, 0x38},   
    {0x23, 0x0a},
        
    {0x60, 0x10},   
    {0x61, 0x82},
    {0x62, 0x00},   
    {0x63, 0x83},   
    {0x64, 0x83},      
    {0x67, 0xF0},   
    {0x68, 0x30},   
    {0x69, 0x10},   
    
    //PAGE 12
    //2D
    {0x03, 0x12},
        
    {0x40, 0xe9},
    {0x41, 0x09},
        
    {0x50, 0x18},
    {0x51, 0x24},
        
    {0x70, 0x1f},
    {0x71, 0x00},
    {0x72, 0x00},
    {0x73, 0x00},
    {0x74, 0x10},
    {0x75, 0x10},
    {0x76, 0x20},
    {0x77, 0x80},
    {0x78, 0x88},
    {0x79, 0x18},
        
    {0xb0, 0x7d},

    //PAGE 13
    //Edge Enhancement
    {0x03, 0x13},
    {0x10, 0x01},   
    {0x11, 0x89},   
    {0x12, 0x14},   
    {0x13, 0x19},   
    {0x14, 0x08},
        
    {0x20, 0x06},
    {0x21, 0x03},
    {0x23, 0x30},
    {0x24, 0x33},
    {0x25, 0x08},
    {0x26, 0x18},
    {0x27, 0x00},
    {0x28, 0x08},
    {0x29, 0x50},
    {0x2a, 0xe0},
    {0x2b, 0x10},
    {0x2c, 0x28},
    {0x2d, 0x40},
    {0x2e, 0x00},
    {0x2f, 0x00},

    //PAGE 11
    {0x30, 0x11},
        
    {0x80, 0x03},
    {0x81, 0x07},
        
    {0x90, 0x04},
    {0x91, 0x02},
    {0x92, 0x00},
    {0x93, 0x20},
    {0x94, 0x42},
    {0x95, 0x60},
    
    //PAGE 14
    //Lens Shading Correction
    {0x03, 0x14},
    {0x10, 0x01},
        
    {0x20, 0x80},   //For Y decay
    {0x21, 0x80},   //For Y decay
    {0x22, 0x78},
    {0x23, 0x4d},
    {0x24, 0x46},
    
    //PAGE 15 
    //Color Correction
    {0x03, 0x15}, 
    {0x10, 0x03},         
    {0x14, 0x3c},
    {0x16, 0x2c},
    {0x17, 0x2f},
          
    {0x30, 0xc4},
    {0x31, 0x5b},
    {0x32, 0x1f},
    {0x33, 0x2a},
    {0x34, 0xce},
    {0x35, 0x24},
    {0x36, 0x0b},
    {0x37, 0x3f},
    {0x38, 0x8a},
           
    {0x40, 0x87},
    {0x41, 0x18},
    {0x42, 0x91},
    {0x43, 0x94},
    {0x44, 0x9f},
    {0x45, 0x33},
    {0x46, 0x00},
    {0x47, 0x94},
    {0x48, 0x14},
    
    //PAGE 16
    //Gamma Correction
    {0x03,  0x16},
        
    {0x30,  0x00},
    {0x31,  0x1c},
    {0x32,  0x2d},
    {0x33,  0x4e},
    {0x34,  0x6d},
    {0x35,  0x8b},
    {0x36,  0xa2},
    {0x37,  0xb5},
    {0x38,  0xc4},
    {0x39,  0xd0},
    {0x3a,  0xda},
    {0x3b,  0xea},
    {0x3c,  0xf4},
    {0x3d,  0xfb},
    {0x3e,  0xff},
    
    //PAGE 17 
    //Auto Flicker Cancellation 
    {0x03, 0x17},
        
    {0xc4, 0x3c},
    {0xc5, 0x32},
    
    //PAGE 20 
    //AE 
    {0x03, 0x20},
        
    {0x10, 0x0c},
    {0x11, 0x04},
           
    {0x20, 0x01},
    {0x28, 0x27},
    {0x29, 0xa1},   
    {0x2a, 0xf0},
    {0x2b, 0x34},
    {0x2c, 0x2b},
           
    {0x30, 0xf8},
    {0x39, 0x22},
    {0x3a, 0xde},
    {0x3b, 0x22},
    {0x3c, 0xde},
    
    {0x60, 0x95},
    {0x68, 0x3c},
    {0x69, 0x64},
    {0x6A, 0x28},
    {0x6B, 0xc8},
    
    {0x70, 0x42},   //For Y decay   
    {0x76, 0x22},
    {0x77, 0x02},   
    {0x78, 0x12},
    {0x79, 0x27},
    {0x7a, 0x23},  
    {0x7c, 0x1d},
    {0x7d, 0x22},
    
    {0x83, 0x00},
    {0x84, 0xaf},
    {0x85, 0x80}, 
        
    {0x86, 0x00},
    {0x87, 0xc0},
        
    {0x88, 0x02},
    {0x89, 0x49},
    {0x8a, 0x00},    
        
    {0x8b, 0x3a},
    {0x8c, 0x80},  
        
    {0x8d, 0x30},
    {0x8e, 0xc0},
    
    {0x91, 0x02},
    {0x92, 0xdc},
    {0x93, 0x6c},   
    {0x94, 0x01},
    {0x95, 0xb7},
    {0x96, 0x74},   
    {0x98, 0x8C},
    {0x99, 0x23},  
        
    {0x9c, 0x08},   //For Y decay: Exposure Time
    {0x9d, 0xa0},   //For Y decay: Exposure Time
    {0x9e, 0x00},
    {0x9f, 0xc0},
    
    {0xb1, 0x14},
    {0xb2, 0x50},
    {0xb4, 0x14},
    {0xb5, 0x38},
    {0xb6, 0x26},
    {0xb7, 0x20},
    {0xb8, 0x1d},
    {0xb9, 0x1b},
    {0xba, 0x1a},
    {0xbb, 0x19},
    {0xbc, 0x19},
    {0xbd, 0x18},
    
    {0xc0, 0x16},   //0x1a->0x16
    {0xc3, 0x48},
    {0xc4, 0x48}, 
    
    //PAGE 22 
    //AWB
    {0x03, 0x22},
    {0x10, 0xe2},
    {0x11, 0x26},
        
    {0x21, 0x40},
           
    {0x30, 0x80},
    {0x31, 0x80},
    {0x38, 0x12},
    {0x39, 0x33},
        
    {0x40, 0xf0},
    {0x41, 0x33},
    {0x42, 0x33},
    {0x43, 0xf3},
    {0x44, 0x55},
    {0x45, 0x44},
    {0x46, 0x02},
           
    {0x80, 0x45},
    {0x81, 0x20},
    {0x82, 0x48},
    {0x83, 0x52},
    {0x84, 0x1b},
    {0x85, 0x50},
    {0x86, 0x25},
    {0x87, 0x4d},
    {0x88, 0x38},
    {0x89, 0x3e},
    {0x8a, 0x29},
    {0x8b, 0x02},
    {0x8d, 0x22},
    {0x8e, 0x71},  
    {0x8f, 0x63},
        
    {0x90, 0x60},
    {0x91, 0x5c},
    {0x92, 0x50},//{0x92, 0x56},
    {0x93, 0x48},//{0x93, 0x52},
    {0x94, 0x42},//{0x94, 0x4c},
    {0x95, 0x36},
    {0x96, 0x31},
    {0x97, 0x2e},
    {0x98, 0x2a},
    {0x99, 0x29},
    {0x9a, 0x26},
    {0x9b, 0x0b},//{0x9b, 0x09},

    //PAGE 22
    {0x03, 0x22},
    {0x10, 0xfb},

    //PAGE 20
    {0x03, 0x20},
    {0x10, 0x9c},
    
    {0x01, 0xf0},

    //PAGE 0
    {0x03, 0x00},
   // {0x01, 0x90},   //0xf1 ->0x41 : For Preview Green/Red Line.
	{0x01, 0xf0},  //jun debug for driver ability

	{0xff, 0xff}    //End of Initial Setting

};

/*************************************************************************
* FUNCTION
*    HI704InitialSetting
*
* DESCRIPTION
*    This function initialize the registers of CMOS sensor.
*
* PARAMETERS
*    None
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/

static void HI704InitialSetting(void)
{
	kal_uint32 iEcount;
	for(iEcount=0;(!((0xff==(HI704InitialSettingInfo[iEcount].address))&&(0xff==(HI704InitialSettingInfo[iEcount].data))));iEcount++)
	{	
		CamWriteCmosSensor(HI704InitialSettingInfo[iEcount].address, HI704InitialSettingInfo[iEcount].data);
	}
}

static void HI704InitParameter(void)
{
    HI704Sensor.PvMode = KAL_TRUE;
    HI704Sensor.NightMode = KAL_FALSE;
    HI704Sensor.VideoMode = KAL_FALSE;
    HI704Sensor.Banding = CAM_BANDING_50HZ;
    HI704Sensor.BypassAe = KAL_FALSE;
    HI704Sensor.BypassAwb = KAL_FALSE;
	HI704Sensor.Wb = CAM_NO_OF_WB;
    
    HI704Sensor.CpPclk = HI704Sensor.PvPclk = 13000000;
    HI704Sensor.DummyPixels = 0;
    HI704Sensor.DummyLines = 0;

    HI704Sensor.PvLineLength = 640;
    HI704Sensor.PvFrameHeight = 480;
    HI704Sensor.CpLineLength = 640;
    HI704Sensor.CpFrameHeight = 480;
    
}
                          
/*************************************************************************
* FUNCTION
*    HI704SetMirrorFlip
*
* DESCRIPTION
*    This function set sensor Mirror
*
* PARAMETERS
*    Mirror
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
void HI704SetMirrorFlip(kal_uint8 image_mirror)
{
	  /********************************************************
		* Page Mode 0: Reg 0x0011 bit[1:0] = [Y Flip : X Flip]
		* 0: Off; 1: On.
		*********************************************************/	
    kal_uint8 temp_reg = 0;
		
   #ifdef HI704_DEBUG
		kal_wap_trace(MOD_ENG,TRACE_INFO,"image_mirror:%d",image_mirror);
   #endif
		CamWriteCmosSensor(0x03,0x00);	   //Page 0 
		temp_reg = (CamReadCmosSensor(0x11) & 0xfc); 
	
		switch (image_mirror) 
		{
			case IMAGE_SENSOR_MIRROR_NORMAL:
				temp_reg |= 0x00;
				break;
			case IMAGE_SENSOR_MIRROR_H:
				temp_reg |= 0x01;
				break;
			case IMAGE_SENSOR_MIRROR_V:
				temp_reg |= 0x02;
				break;
			case IMAGE_SENSOR_MIRROR_HV:
				temp_reg |= 0x03;
				break;
			default:
				temp_reg |= 0x00;
		}
	
		CamWriteCmosSensor(0x11, temp_reg);
	
}	/* HI704_Set_Mirror_Flip */

/*************************************************************************
* FUNCTION
*    HI704Ev
*
* DESCRIPTION
*    HI704 EV setting.
*
* PARAMETERS
*    In, Out
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM HI704Ev(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT EvPara = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
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
    kal_uint8 EvTemp = 0x00;
#ifdef HI704_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "EV:%d", In->FeatureSetValue);
#endif
    switch (In->FeatureSetValue)
    {
    case CAM_EV_NEG_4_3: EvTemp = 0xe0; break;
    case CAM_EV_NEG_3_3: EvTemp = 0xc8; break;
    case CAM_EV_NEG_2_3: EvTemp = 0xb0; break;
    case CAM_EV_NEG_1_3: EvTemp = 0x98; break;
    case CAM_EV_ZERO:    EvTemp = 0x88; break;
    case CAM_EV_POS_1_3: EvTemp = 0x18; break;
    case CAM_EV_POS_2_3: EvTemp = 0x30; break;
    case CAM_EV_POS_3_3: EvTemp = 0x48; break;
    case CAM_EV_POS_4_3: EvTemp = 0x60; break;
    default: break;
    }       
    CamWriteCmosSensor(0x03,0x10);
	CamWriteCmosSensor(0x12,(CamReadCmosSensor(0x12)|0x10));//make sure the Yoffset control is opened.
    CamWriteCmosSensor(0x40, EvTemp);	  	 
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HI704Contrast
*
* DESCRIPTION
*    HI704 Contrast setting.
*
* PARAMETERS
*    In, Out
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM HI704Contrast(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT EvPara = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    EvPara->IsSupport = KAL_TRUE;
    EvPara->ItemCount = 3;
    EvPara->SupportItem[0] = CAM_CONTRAST_HIGH;
    EvPara->SupportItem[1] = CAM_CONTRAST_MEDIUM;
    EvPara->SupportItem[2] = CAM_CONTRAST_LOW;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {

    kal_uint8 Contrast = 0x80;
#ifdef HI704_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "EV:%d", In->FeatureSetValue);
#endif
    switch (In->FeatureSetValue)
    {
    case CAM_CONTRAST_HIGH:   Contrast = 0xE0; break;
    case CAM_CONTRAST_MEDIUM: Contrast = 0x98; break;
    case CAM_CONTRAST_LOW:    Contrast = 0x80; break;
    default: break;
    }

    CamWriteCmosSensor(0x03,0x10);
	CamWriteCmosSensor(0x11,(CamReadCmosSensor(0x11)|0x40));//bit[6] (contrast) enable
    CamWriteCmosSensor(0x48, Contrast);
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HI704Wb
*
* DESCRIPTION
*    HI704 WB setting.
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
static MM_ERROR_CODE_ENUM HI704Wb(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
#ifdef HI704_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"WB:%d",In->FeatureSetValue);
#endif
	//This sensor need more time to balance AWB, 
		//we suggest higher fps or drop some frame to avoid garbage color when preview initial
		
	// Add this adjudge for 5 shot capture 
	if (HI704Sensor.Wb == In->FeatureSetValue)		
		return MM_ERROR_NONE;
	else 
		HI704Sensor.Wb = In->FeatureSetValue;
	
    switch (In->FeatureSetValue)
    {
    case CAM_WB_AUTO: /* enable AWB */
      /* CAM_WB_AUTO mode should not update R/G/B gains */
      {
		CamWriteCmosSensor(0x03, 0x22);			
		CamWriteCmosSensor(0x11, 0x2e);				
		CamWriteCmosSensor(0x80, 0x40);//CamWriteCmosSensor(0x80, 0x38);
		CamWriteCmosSensor(0x82, 0x48);//CamWriteCmosSensor(0x82, 0x38);				
		CamWriteCmosSensor(0x83, 0x5e);
		CamWriteCmosSensor(0x84, 0x1b);//CamWriteCmosSensor(0x84, 0x24);
		CamWriteCmosSensor(0x85, 0x50);//CamWriteCmosSensor(0x85, 0x59);
		CamWriteCmosSensor(0x86, 0x24);				
	  }
      break;
    case CAM_WB_CLOUD: /* disable AWB */
	  {
		CamWriteCmosSensor(0x03, 0x22);
		CamWriteCmosSensor(0x11, 0x28);
		CamWriteCmosSensor(0x80, 0x71);
		CamWriteCmosSensor(0x82, 0x2b);
		CamWriteCmosSensor(0x83, 0x72);
		CamWriteCmosSensor(0x84, 0x70);
		CamWriteCmosSensor(0x85, 0x2b);
		CamWriteCmosSensor(0x86, 0x28);
	  }	
      break;
    case CAM_WB_DAYLIGHT:/* disable AWB */
	  {
		CamWriteCmosSensor(0x03, 0x22);
		CamWriteCmosSensor(0x11, 0x28); 	  
		CamWriteCmosSensor(0x80, 0x59);
		CamWriteCmosSensor(0x82, 0x29);
		CamWriteCmosSensor(0x83, 0x60);
		CamWriteCmosSensor(0x84, 0x50);
		CamWriteCmosSensor(0x85, 0x2f);
		CamWriteCmosSensor(0x86, 0x23);
	  }	   
      break;
    case CAM_WB_INCANDESCENCE:/* disable AWB */
      {
		CamWriteCmosSensor(0x03, 0x22);
		CamWriteCmosSensor(0x11, 0x28);		  
		CamWriteCmosSensor(0x80, 0x29);
		CamWriteCmosSensor(0x82, 0x54);
		CamWriteCmosSensor(0x83, 0x2e);
		CamWriteCmosSensor(0x84, 0x23);
		CamWriteCmosSensor(0x85, 0x58);
		CamWriteCmosSensor(0x86, 0x4f);
	 }
      break;
    case CAM_WB_FLUORESCENT:/* disable AWB */
	 {
		CamWriteCmosSensor(0x03, 0x22);
		CamWriteCmosSensor(0x11, 0x28);
		CamWriteCmosSensor(0x80, 0x41);
		CamWriteCmosSensor(0x82, 0x42);
		CamWriteCmosSensor(0x83, 0x44);
		CamWriteCmosSensor(0x84, 0x34);
		CamWriteCmosSensor(0x85, 0x46);
		CamWriteCmosSensor(0x86, 0x3a);
	 }
      break;
    case CAM_WB_TUNGSTEN:/* disable AWB */
     {
		CamWriteCmosSensor(0x03, 0x22);
		CamWriteCmosSensor(0x80, 0x24);
		CamWriteCmosSensor(0x81, 0x20);
		CamWriteCmosSensor(0x82, 0x58);
		CamWriteCmosSensor(0x83, 0x27);
		CamWriteCmosSensor(0x84, 0x22);
		CamWriteCmosSensor(0x85, 0x58);
		CamWriteCmosSensor(0x86, 0x52);
	 }
      break;
    default:
      break;    
    }
  }
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    HI704Effect
*
* DESCRIPTION
*    HI704 Effect setting.
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
static MM_ERROR_CODE_ENUM HI704Effect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    P_CAL_FEATURE_TYPE_ENUM_STRUCT EffectPara = &Out->FeatureInfo.FeatureEnum;
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION | CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    EffectPara->IsSupport = KAL_TRUE;
    EffectPara->ItemCount = 8;
    EffectPara->SupportItem[0] = CAM_EFFECT_ENC_NORMAL;
    EffectPara->SupportItem[1] = CAM_EFFECT_ENC_GRAYSCALE;
    EffectPara->SupportItem[2] = CAM_EFFECT_ENC_SEPIA;
    EffectPara->SupportItem[3] = CAM_EFFECT_ENC_SEPIAGREEN;
    EffectPara->SupportItem[4] = CAM_EFFECT_ENC_SEPIABLUE;
    EffectPara->SupportItem[5] = CAM_EFFECT_ENC_COLORINV;
    EffectPara->SupportItem[6] = CAM_EFFECT_ENC_EMBOSSMENT;
    EffectPara->SupportItem[7] = CAM_EFFECT_ENC_SKETCH;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
   kal_uint16 temp_reg = 0;
   kal_uint16 temp_reg2 = 0;
#ifdef HI704_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"Effect:%d",In->FeatureSetValue);
#endif

    CamWriteCmosSensor(0x03, 0x10);
    temp_reg = CamReadCmosSensor(0x11)& 0x40;
    switch (In->FeatureSetValue)
    {
    case CAM_EFFECT_ENC_NORMAL:
      {
	     //   CamWriteCmosSensor(0x03, 0x10);
	        CamWriteCmosSensor(0x11, temp_reg|0x03);
	        CamWriteCmosSensor(0x12, temp_reg2|0x30);
	        CamWriteCmosSensor(0x13, 0x00);
	        CamWriteCmosSensor(0x44, 0x80);
	        CamWriteCmosSensor(0x45, 0x80);

	        CamWriteCmosSensor(0x47, 0x7f);
	        CamWriteCmosSensor(0x03, 0x13);
	        CamWriteCmosSensor(0x20, 0x07);
	        CamWriteCmosSensor(0x21, 0x07);
        }
      break;
    case CAM_EFFECT_ENC_GRAYSCALE:
        {
		//	CamWriteCmosSensor(0x03, 0x10);
			CamWriteCmosSensor(0x11, temp_reg|0x03);
			CamWriteCmosSensor(0x12, temp_reg2|0x03);
			//CamWriteCmosSensor(0x40, 0x00);
			CamWriteCmosSensor(0x44, 0x80);
			CamWriteCmosSensor(0x45, 0x80);
        }
      break;
    case CAM_EFFECT_ENC_SEPIA:
		{
         //   CamWriteCmosSensor(0x03, 0x10);
            CamWriteCmosSensor(0x11, temp_reg|0x03);
            CamWriteCmosSensor(0x12, temp_reg2|0x23);
            CamWriteCmosSensor(0x13, 0x00);
            CamWriteCmosSensor(0x44, 0x70);
            CamWriteCmosSensor(0x45, 0x98);

            CamWriteCmosSensor(0x47, 0x7f);
            CamWriteCmosSensor(0x03, 0x13);
            CamWriteCmosSensor(0x20, 0x07);
            CamWriteCmosSensor(0x21, 0x07);
        }
      break;
    case CAM_EFFECT_ENC_SEPIAGREEN:
        {
         //   CamWriteCmosSensor(0x03, 0x10);
            CamWriteCmosSensor(0x11, temp_reg|0x03);
            CamWriteCmosSensor(0x12, temp_reg2|0x03);
            //CamWriteCmosSensor(0x40, 0x00);
            CamWriteCmosSensor(0x13, 0x00);
            CamWriteCmosSensor(0x44, 0x30);
            CamWriteCmosSensor(0x45, 0x50);
        }
      break;
    case CAM_EFFECT_ENC_SEPIABLUE:
		{
		//  	CamWriteCmosSensor(0x03, 0x10);
			CamWriteCmosSensor(0x11, temp_reg|0x03);
			CamWriteCmosSensor(0x12, temp_reg2|0x03);
			//CamWriteCmosSensor(0x40, 0x00);
			CamWriteCmosSensor(0x13, 0x00);
			CamWriteCmosSensor(0x44, 0xb0);
			CamWriteCmosSensor(0x45, 0x40);
		}
      break;
    case CAM_EFFECT_ENC_COLORINV:
        {
          //  CamWriteCmosSensor(0x03, 0x10);
            CamWriteCmosSensor(0x11, temp_reg|0x03);
            CamWriteCmosSensor(0x12, temp_reg2|0x08);
            CamWriteCmosSensor(0x13, 0x00);
            CamWriteCmosSensor(0x14, 0x00);
        }
      break;
    case CAM_EFFECT_ENC_EMBOSSMENT:
        {
          //  CamWriteCmosSensor(0x03, 0x10);
            CamWriteCmosSensor(0x11, temp_reg|0x23);
            CamWriteCmosSensor(0x12, temp_reg2|0x30);
            CamWriteCmosSensor(0x13, 0x02);
            //CamWriteCmosSensor(0x40, 0x20);
            CamWriteCmosSensor(0x44, 0x80);
            CamWriteCmosSensor(0x45, 0x80);

            CamWriteCmosSensor(0x47, 0x7f);
            CamWriteCmosSensor(0x03, 0x13);
            CamWriteCmosSensor(0x20, 0x07);
            CamWriteCmosSensor(0x21, 0x07);
        }
      break;
    case CAM_EFFECT_ENC_SKETCH:
        {
        //    CamWriteCmosSensor(0x03, 0x10);
            CamWriteCmosSensor(0x11, temp_reg|0x13);
            CamWriteCmosSensor(0x12, temp_reg2|0x38);
            CamWriteCmosSensor(0x13, 0x02);
            //CamWriteCmosSensor(0x40, 0x20);
            CamWriteCmosSensor(0x44, 0x80);
            CamWriteCmosSensor(0x45, 0x80);

            CamWriteCmosSensor(0x47, 0x7f);
            CamWriteCmosSensor(0x03, 0x13);
            CamWriteCmosSensor(0x20, 0x07);
            CamWriteCmosSensor(0x21, 0x07);
        }
      break;
    default:
      break;
    }
  }   
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HI704StillCaptureSize
*
* DESCRIPTION
*    This function get capture size
*
* PARAMETERS
*    In, Out, OutLen, RealOutLen
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM HI704StillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  const P_CAL_FEATURE_TYPE_ENUM_STRUCT CapSize = &Out->FeatureInfo.FeatureEnum;
  
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_GET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
    CapSize->IsSupport = KAL_TRUE;
    CapSize->ItemCount = 2;
    CapSize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
    CapSize->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
  }
  return MM_ERROR_NONE;
}

static kal_uint8 HI704SetParamBanding(kal_uint8 para)
{
    #ifdef HI704_DEBUG
        kal_wap_trace(MOD_ENG, TRACE_INFO,"HI704_Set_Param_Banding = %d",para);
    #endif

	switch (para)
	{
		case CAM_BANDING_50HZ:
        {
			CamWriteCmosSensor(0x03,0x20);
			CamWriteCmosSensor(0x10,0x9c);
		}
			break;

		case CAM_BANDING_60HZ:
		{
			CamWriteCmosSensor(0x03,0x20);
			CamWriteCmosSensor(0x10,0x8c);
		}
			break;

	      default:
	          return KAL_FALSE;
	}
	return KAL_TRUE;
} /* HI704_Set_Param_Banding *


/*************************************************************************
* FUNCTION
*    HI704Banding
*
* DESCRIPTION
*    This function get banding setting
*
* PARAMETERS
*    In, Out, OutLen, RealOutLen
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM HI704Banding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  const P_CAL_FEATURE_TYPE_ENUM_STRUCT Banding = &Out->FeatureInfo.FeatureEnum;
  
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    Banding->IsSupport = KAL_TRUE;
    Banding->ItemCount = 2;
    Banding->SupportItem[0] = CAM_BANDING_50HZ;
    Banding->SupportItem[1] = CAM_BANDING_60HZ;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
#ifdef HI704_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"Banding:%d",In->FeatureSetValue);
#endif
    HI704Sensor.Banding = In->FeatureSetValue;
    HI704SetParamBanding(HI704Sensor.Banding);  
  }  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HI704GetSensorInfo
*
* DESCRIPTION
*    This function get sensor infomation
*
* PARAMETERS
*    None
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static void HI704GetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT Info)
{
  Info->SensorId = HI704_SENSOR_ID;
  Info->SensorIf = IMAGE_SENSOR_IF_PARALLEL;
  Info->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;  
  Info->PreviewHMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY; 
  Info->PreviewVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PreviewHVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY; 
  Info->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PixelClkInv = KAL_TRUE;
  Info->PixelClkPolarity = POLARITY_LOW;
  Info->HsyncPolarity = POLARITY_LOW;
  Info->VsyncPolarity = POLARITY_LOW;
  
  Info->PreviewMclkFreq = 26000000;
  Info->CaptureMclkFreq = 26000000;
  Info->VideoMclkFreq = 26000000;

  Info->PreviewWidth = HI704_IMAGE_SENSOR_VGA_WIDTH;
  Info->PreviewHeight = HI704_IMAGE_SENSOR_VGA_HEIGHT;
  Info->FullWidth = HI704_IMAGE_SENSOR_VGA_WIDTH;
  Info->FullHeight = HI704_IMAGE_SENSOR_VGA_HEIGHT;
  Info->SensorAfSupport = KAL_FALSE;
  Info->SensorFlashSupport = KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*    HI704DetectSensorId
*
* DESCRIPTION
*    This function detect sensor Id
*
* PARAMETERS
*    None
*
* RETURNS
*    sensor Id
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint32 HI704DetectSensorId(void)
{
  MM_ERROR_CODE_ENUM HI704SensorClose(void);
  kal_uint16 HI704PowerOn();
  kal_uint16 SensorId;
  IMAGE_SENSOR_INDEX_ENUM AnotherSensorIdx;
  kal_int8 i, j;
  
  if (IMAGE_SENSOR_MAIN == HI704Sensor.SensorIdx)
  {
    AnotherSensorIdx = IMAGE_SENSOR_SUB;
  }
  else
  {
    AnotherSensorIdx = IMAGE_SENSOR_MAIN;
  }
  for (i = 1; i >= 0; i--)
  {
    for (j = 1; j >= 0; j--)
    {
      CamRstPinCtrl(AnotherSensorIdx, i);
      CamPdnPinCtrl(AnotherSensorIdx, j);
      SensorId = HI704PowerOn();
      HI704SensorClose();
#ifdef HI704_DEBUG
      kal_wap_trace(MOD_ENG,TRACE_INFO,"HI704DetectSensorId:%x",SensorId);
#endif
      if (HI704_SENSOR_ID == SensorId)
      {
        return HI704_SENSOR_ID;
      }
    }
  }
  return 0xFFFFFFFF;
}

/*************************************************************************
* FUNCTION
*    HI704InitOperationPara
*
* DESCRIPTION
*    This function set sensor operation Para
*
* PARAMETERS
*    Para
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void HI704InitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT Para)
{
  Para->CaptureDelayFrame = 2; /* wait stable frame when sensor change mode (pre to cap) */
  Para->PreviewDelayFrame = 5; /* wait stable frame when sensor change mode (cap to pre) */
  Para->PreviewDisplayWaitFrame = 5; /* wait stable frame when sensor change mode (cap to pre) */
}

/*************************************************************************
* FUNCTION
*    HI704AeEnable
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
static MM_ERROR_CODE_ENUM HI704AeEnable(kal_bool Enable)  //need to do AE func
{
#ifdef HI704_DEBUG
	kal_prompt_trace(MOD_ENG,"AEenable:%d",Enable);
#endif

  if (HI704Sensor.BypassAe && HI704Sensor.PvMode)
	{
		Enable = KAL_FALSE;
	}


  if (Enable)
  {
     CamWriteCmosSensor(0x03, 0x20);
     CamWriteCmosSensor(0x10, CamReadCmosSensor(0x10)|0x80);	//Open AE
     CamWriteCmosSensor(0x18, CamReadCmosSensor(0x18)&0xf7);	//Reset AE
  }
  else
  {
     CamWriteCmosSensor(0x03, 0x20);
     CamWriteCmosSensor(0x10, CamReadCmosSensor(0x10)&0x7f);   //Close AE
     CamWriteCmosSensor(0x18, CamReadCmosSensor(0x18)|0x08);   //Reset AE
  }

  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HI704AwbEnable
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
static MM_ERROR_CODE_ENUM HI704AwbEnable(kal_bool Enable)   //need to do AE func
{
   #ifdef HI704_DEBUG
	  kal_prompt_trace(MOD_ENG,"AWBenable:%d",Enable);
   #endif
 
   if (HI704Sensor.BypassAwb && HI704Sensor.PvMode)
	  {
		  Enable = KAL_FALSE;
	  }
 

  if (Enable)
  {
	 CamWriteCmosSensor(0x03, 0x22);
	 CamWriteCmosSensor(0x10, CamReadCmosSensor(0x10)|0x80);	 //Open AWB
  }
  else
  {
	 CamWriteCmosSensor(0x03, 0x22);
     CamWriteCmosSensor(0x10, CamReadCmosSensor(0x10)&0x7f);	 //Close AWB
  }

 

  return MM_ERROR_NONE;
}

static void HI704CalMinFrameRate(kal_uint16 MinFps)
{
    kal_uint32 HI704Expmax;
    kal_uint32 HI704Expbanding;

#ifdef HI704_DEBUG
  kal_wap_trace(MOD_ENG, TRACE_INFO,"Cal_Frame_Rate:%d",MinFps);
#endif

    //No Fixed Framerate
    CamWriteCmosSensor(0x01, CamReadCmosSensor(0x01)|0x01);   //Sleep: For Write Reg

    CamWriteCmosSensor(0x03, 0x00);
    CamWriteCmosSensor(0x11, CamReadCmosSensor(0x11)&0xfb);
    
    CamWriteCmosSensor(0x03, 0x20);
    CamWriteCmosSensor(0x10, CamReadCmosSensor(0x10)&0x7f);   //Close AE
    
    CamWriteCmosSensor(0x11, 0x04);
    CamWriteCmosSensor(0x18, CamReadCmosSensor(0x18)|0x08);   //Reset AE
    CamWriteCmosSensor(0x2a, 0xf0);
    CamWriteCmosSensor(0x2b, 0x34);

    CamWriteCmosSensor(0x03, 0x00);
    HI704Sensor.DummyPixels = ((CamReadCmosSensor(0x40)<<8)|CamReadCmosSensor(0x41));
    HI704Sensor.PvLineLength = HI704_VGA_DEFAULT_PIXEL_NUMS+ HI704Sensor.DummyPixels;

    if(HI704Sensor.Banding == CAM_BANDING_50HZ)
    {
        HI704Expbanding = (HI704Sensor.PvPclk/HI704Sensor.PvLineLength/100)*HI704Sensor.PvLineLength/8;
        HI704Expmax = HI704Expbanding*100*10/MinFps ;
    }
    else if(HI704Sensor.Banding == CAM_BANDING_60HZ)
    {
        HI704Expbanding = (HI704Sensor.PvPclk/HI704Sensor.PvLineLength/120)*HI704Sensor.PvLineLength/8;
        HI704Expmax = HI704Expbanding*120*10/MinFps ;
    }
    else
    {
        kal_wap_trace(MOD_ENG, TRACE_INFO,"[HI704][Error] Wrong Banding Setting!!!...");
    }
    
    CamWriteCmosSensor(0x03, 0x20);
    CamWriteCmosSensor(0x88, (HI704Expmax>>16)&0xff);
    CamWriteCmosSensor(0x89, (HI704Expmax>>8)&0xff);
    CamWriteCmosSensor(0x8a, (HI704Expmax>>0)&0xff);

    CamWriteCmosSensor(0x01, CamReadCmosSensor(0x01)&0xfe);   //Exit Sleep: For Write Reg

    CamWriteCmosSensor(0x03, 0x20);
    CamWriteCmosSensor(0x10, CamReadCmosSensor(0x10)|0x80);   //Open AE
    CamWriteCmosSensor(0x18, CamReadCmosSensor(0x18)&0xf7);   //Reset AE
}


static void HI704FixVideoFrameRate(kal_uint16 FixFps)
{
    kal_uint32 HI704Expfix;
    kal_uint32 HI704ExpfixTemp;
    kal_uint32 HI704Expmax;
    kal_uint32 HI704Expbanding;
    
    #ifdef HI704_DEBUG
        kal_wap_trace(MOD_ENG, TRACE_INFO,"[HI704] HI704_NightMode...");
        kal_wap_trace(MOD_ENG, TRACE_INFO,"[HI704] HI704_fix_framerate = %d...",FixFps);
    #endif
    
    // Fixed Framerate
    CamWriteCmosSensor(0x01, CamReadCmosSensor(0x01)|0x01);   //Sleep: For Write Reg

    CamWriteCmosSensor(0x03, 0x00);
    CamWriteCmosSensor(0x11, CamReadCmosSensor(0x11)|0x04);

    CamWriteCmosSensor(0x03, 0x20);
    CamWriteCmosSensor(0x10, CamReadCmosSensor(0x10)&0x7f);   //Close AE
    
    CamWriteCmosSensor(0x11, 0x00);
    CamWriteCmosSensor(0x18, CamReadCmosSensor(0x18)|0x08);   //Reset AE
    CamWriteCmosSensor(0x2a, 0x00);
    CamWriteCmosSensor(0x2b, 0x35);

    CamWriteCmosSensor(0x03, 0x00);
    HI704Sensor.DummyPixels = ((CamReadCmosSensor(0x40)<<8)|CamReadCmosSensor(0x41));
  //  kal_wap_trace(MOD_ENG, TRACE_INFO,"[HI704] HI704_sensor.dummy_pixels = %d...",HI704Sensor.DummyPixels);

    HI704Sensor.PvLineLength = HI704_VGA_DEFAULT_PIXEL_NUMS + HI704Sensor.DummyPixels;
  //  kal_wap_trace(MOD_ENG, TRACE_INFO,"[HI704] HI704_sensor.pv_line_length = %d...",HI704Sensor.PvLineLength);
    
    HI704Sensor.DummyLines = ((CamReadCmosSensor(0x42)<<8)|CamReadCmosSensor(0x43));
   // kal_wap_trace(MOD_ENG, TRACE_INFO,"[HI704] HI704_sensor.dummy_lines = %d...",HI704Sensor.DummyLines);
    
    HI704ExpfixTemp = ((HI704Sensor.PvPclk*10/FixFps)-(HI704Sensor.PvLineLength*HI704Sensor.DummyLines))/8;
 //   kal_wap_trace(MOD_ENG, TRACE_INFO,"[HI704] HI704_expfix_temp = %x ...",HI704ExpfixTemp);
    HI704Expfix = ((HI704ExpfixTemp*8/HI704Sensor.PvLineLength)*HI704Sensor.PvLineLength)/8;
 //   kal_wap_trace(MOD_ENG, TRACE_INFO,"[HI704] HI704_expfix = %x ...",HI704Expfix);

    CamWriteCmosSensor(0x03, 0x20);
    CamWriteCmosSensor(0x91, (HI704Expfix>>16)&0xff);
    CamWriteCmosSensor(0x92, (HI704Expfix>>8)&0xff);
    CamWriteCmosSensor(0x93, (HI704Expfix>>0)&0xff);

    if(HI704Sensor.Banding == CAM_BANDING_50HZ)
    {
        HI704Expbanding = ((CamReadCmosSensor(0x8b)<<8)|CamReadCmosSensor(0x8c));
    }
    else if(HI704Sensor.Banding == CAM_BANDING_60HZ)
    {
        HI704Expbanding = ((CamReadCmosSensor(0x8d)<<8)|CamReadCmosSensor(0x8e));
    }
    else
    {
   //     kal_wap_trace(MOD_ENG, TRACE_INFO,"[HI704][Error] Wrong Banding Setting!!!...");
    }
    HI704Expmax = ((HI704ExpfixTemp-HI704Expbanding)/HI704Expbanding)*HI704Expbanding;

    #ifdef HI704_DEBUG
        kal_wap_trace(MOD_ENG, TRACE_INFO,"[HI704] HI704_expbanding = %x...",HI704Expbanding);
        kal_wap_trace(MOD_ENG, TRACE_INFO,"[HI704] HI704_expmax = %x...",HI704Expmax);
    #endif
    
    CamWriteCmosSensor(0x03, 0x20);
    CamWriteCmosSensor(0x88, (HI704Expmax>>16)&0xff);
    CamWriteCmosSensor(0x89, (HI704Expmax>>8)&0xff);
    CamWriteCmosSensor(0x8a, (HI704Expmax>>0)&0xff);

    CamWriteCmosSensor(0x01, CamReadCmosSensor(0x01)&0xfe);   //Exit Sleep: For Write Reg

    CamWriteCmosSensor(0x03, 0x20);
    CamWriteCmosSensor(0x10, CamReadCmosSensor(0x10)|0x80);   //Open AE
    CamWriteCmosSensor(0x18, CamReadCmosSensor(0x18)&0xf7);   //Reset AE

}



/*************************************************************************
* FUNCTION
*    HI704NightMode
*
* DESCRIPTION
*    This function switch on/off night mode
*
* PARAMETERS
*    enable
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void HI704NightMode(kal_bool Enable)
{    
  #ifdef HI704_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "HI704 NightMode %d",Enable);
  #endif
  if (HI704Sensor.VideoMode == KAL_FALSE)// camera mode
  {
      #ifdef HI704_DEBUG
      kal_wap_trace(MOD_ENG,TRACE_INFO, "camera mode");
      #endif
      HI704CalMinFrameRate(HI704Sensor.Fps);       
  }
  else //video mode
  {
      #ifdef HI704_DEBUG
      kal_wap_trace(MOD_ENG,TRACE_INFO, "video mode");
      #endif
	  HI704FixVideoFrameRate(HI704Sensor.Fps);
  }
}
/*************************************************************************
* FUNCTION
*    PAS6327SceneMode
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
static MM_ERROR_CODE_ENUM HI704SceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    HI704NightMode(Enable);
  }
  return MM_ERROR_NONE;
}


// 640 * 480
void HI704SetVGAMode(void)
{
    CamWriteCmosSensor(0x03, 0x00); //jun debug, page 0
    CamWriteCmosSensor(0x01, CamReadCmosSensor(0x01)|0x01);   //Sleep: For Write Reg

  //  CamWriteCmosSensor(0x03, 0x00);
    CamWriteCmosSensor(0x10, 0x00);        //VGA Size

    CamWriteCmosSensor(0x20, 0x00);
    CamWriteCmosSensor(0x21, 0x04);

    CamWriteCmosSensor(0x40, 0x00);        //HBLANK: 0x70 = 112
    CamWriteCmosSensor(0x41, 0x70);
    CamWriteCmosSensor(0x42, 0x00);        //VBLANK: 0x04 = 4
    CamWriteCmosSensor(0x43, 0x40);

    CamWriteCmosSensor(0x03, 0x11);
    CamWriteCmosSensor(0x10, 0x25);  

    CamWriteCmosSensor(0x03, 0x20);
    CamWriteCmosSensor(0x10, CamReadCmosSensor(0x10)&0x7f);   //Close AE
    CamWriteCmosSensor(0x18, CamReadCmosSensor(0x18)|0x08);   //Reset AE

    CamWriteCmosSensor(0x83, 0x00);
    CamWriteCmosSensor(0x84, 0xaf);
    CamWriteCmosSensor(0x85, 0x80);
    CamWriteCmosSensor(0x86, 0x00);
    CamWriteCmosSensor(0x87, 0xc0);

    CamWriteCmosSensor(0x8b, 0x3a);
    CamWriteCmosSensor(0x8c, 0x80);
    CamWriteCmosSensor(0x8d, 0x30);
    CamWriteCmosSensor(0x8e, 0xc0);

    CamWriteCmosSensor(0x9c, 0x08);
    CamWriteCmosSensor(0x9d, 0xa0);
    CamWriteCmosSensor(0x9e, 0x00);
    CamWriteCmosSensor(0x9f, 0xc0);

    CamWriteCmosSensor(0x03, 0x00); //jun debug,page 0
    CamWriteCmosSensor(0x01, CamReadCmosSensor(0x01)&0xfe);   //Exit Sleep: For Write Reg

    CamWriteCmosSensor(0x03, 0x20);
    CamWriteCmosSensor(0x10, CamReadCmosSensor(0x10)|0x80);   //Open AE
    CamWriteCmosSensor(0x18, CamReadCmosSensor(0x18)&0xf7);   //Reset AE

}

// 320 * 240
void HI704SetQVGAMode(void)
{  
    CamWriteCmosSensor(0x03, 0x00); //jun debug,page 0
    CamWriteCmosSensor(0x01, CamReadCmosSensor(0x01)|0x01);   //Sleep: For Write Reg
    
   // CamWriteCmosSensor(0x03, 0x00);
    CamWriteCmosSensor(0x10, 0x01);        //QVGA Size: 0x10 -> 0x01

    CamWriteCmosSensor(0x20, 0x00);
    CamWriteCmosSensor(0x21, 0x02);

    CamWriteCmosSensor(0x40, 0x01);        //HBLANK:  0x0158 = 344
    CamWriteCmosSensor(0x41, 0x58);
    CamWriteCmosSensor(0x42, 0x00);        //VBLANK:  0x14 = 20
    CamWriteCmosSensor(0x43, 0x14);

    CamWriteCmosSensor(0x03, 0x11);        //QVGA Fixframerate
    CamWriteCmosSensor(0x10, 0x21);  

    CamWriteCmosSensor(0x03, 0x20);
    CamWriteCmosSensor(0x10, CamReadCmosSensor(0x10)&0x7f);   //Close AE
    CamWriteCmosSensor(0x18, CamReadCmosSensor(0x18)|0x08);   //Reset AE

    CamWriteCmosSensor(0x83, 0x00);
    CamWriteCmosSensor(0x84, 0xaf);
    CamWriteCmosSensor(0x85, 0xc8);
    CamWriteCmosSensor(0x86, 0x00);
    CamWriteCmosSensor(0x87, 0xfa);

    CamWriteCmosSensor(0x8b, 0x3a);
    CamWriteCmosSensor(0x8c, 0x98);
    CamWriteCmosSensor(0x8d, 0x30);
    CamWriteCmosSensor(0x8e, 0xd4);

    CamWriteCmosSensor(0x9c, 0x0b);
    CamWriteCmosSensor(0x9d, 0x3b);
    CamWriteCmosSensor(0x9e, 0x00);
    CamWriteCmosSensor(0x9f, 0xfa);

    CamWriteCmosSensor(0x03, 0x00); //jun debug,page 0
    CamWriteCmosSensor(0x01, CamReadCmosSensor(0x01)&0xfe);   //Exit Sleep: For Write Reg

    CamWriteCmosSensor(0x03, 0x20);
    CamWriteCmosSensor(0x10, CamReadCmosSensor(0x10)|0x80);   //Open AE
    CamWriteCmosSensor(0x18, CamReadCmosSensor(0x18)&0xf7);   //Reset AE

}


/*************************************************************************
* FUNCTION
*    HI704PowerOn
*
* DESCRIPTION
*    This function reset sensor and read Id
*
* PARAMETERS
*    None
*
* RETURNS
*    sensor Id
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint16 HI704PowerOn(void)
{
  kal_uint16 SensorId;
  /* PowerOn the sensor */
  CisModulePowerOn(HI704Sensor.SensorIdx, KAL_TRUE);
  CameraSccbOpen(CAMERA_SCCB_SENSOR, HI704_SLAVE_ADDR, CAMERA_SCCB_8BIT, CAMERA_SCCB_8BIT, 300); //jun debug
  kal_sleep_task(2);  /* delay for power stable */
  
  /* set sensors chip enable pin to low to activate HI704 */
  CamPdnPinCtrl(HI704Sensor.SensorIdx, 0);
  
  /* Reset the sensor */
  CamRstPinCtrl(HI704Sensor.SensorIdx, 1);
  kal_sleep_task(1);
  CamRstPinCtrl(HI704Sensor.SensorIdx, 0);
  kal_sleep_task(1);
  CamRstPinCtrl(HI704Sensor.SensorIdx, 1);
  /* delay for stable sensor */  
  kal_sleep_task(2); //need wait 10ms, jun debug


  //Software Reset
  CamWriteCmosSensor(0x03,0x00); //jun debug,page 0
  CamWriteCmosSensor(0x01,0xf1);
  CamWriteCmosSensor(0x01,0xf3);
  CamWriteCmosSensor(0x01,0xf1);
  
  /* Read Sensor ID  */
  SensorId = CamReadCmosSensor(0x04);
#ifdef HI704_DEBUG
  kal_wap_trace(MOD_ENG, TRACE_INFO, "HI704 Sensor ID: %x ",SensorId);
#endif
  return SensorId;
}

/*************************************************************************
* FUNCTION
*    HI704Preview
*
* DESCRIPTION
*    This function set to preview mode
*
* PARAMETERS
*    Id, In, Out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void HI704Preview(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint16 StartX = 1, StartY = 1,GrabWidth = 0, GrabHeight = 0;
  
#ifdef HI704_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "HI704 Preview");
#endif


  if(HI704Sensor.PvMode == KAL_TRUE)
  {
    HI704Sensor.Banding = In->BandingFreq;
    HI704Sensor.NightMode = In->NightMode;
    HI704Sensor.mirror = In->ImageMirror;
    
    switch (Id)
    {
    case CAL_SCENARIO_VIDEO:
      HI704SetQVGAMode();
      HI704Sensor.VideoMode = KAL_TRUE;
      HI704Sensor.Fps = In->MaxVideoFrameRate * HI704_FRAME_RATE_UNIT / 10;
      GrabWidth = HI704_IMAGE_SENSOR_QVGA_WIDTH - 10;
      GrabHeight = HI704_IMAGE_SENSOR_QVGA_HEIGHT - 10;
      break;
    case CAL_SCENARIO_CAMERA_PREVIEW:
    case CAL_SCENARIO_WEBCAM_PREVIEW:
    case CAL_SCENARIO_WEBCAM_CAPTURE:
      HI704SetVGAMode();
      HI704Sensor.VideoMode = KAL_FALSE;
      HI704Sensor.Fps = HI704_FRAME_RATE_UNIT * (HI704Sensor.NightMode ? 5 : 10);
      GrabWidth = HI704_IMAGE_SENSOR_VGA_WIDTH - 10;
      GrabHeight = HI704_IMAGE_SENSOR_VGA_HEIGHT - 10;
      break;
    default:
      break;
    }
	  HI704SetMirrorFlip(HI704Sensor.mirror);
	  HI704NightMode(HI704Sensor.NightMode);
	  HI704SetParamBanding(HI704Sensor.Banding);
	  Out->WaitStableFrameNum = 5;
	  
  }  
  else	/* add this case for Cap-to-Prv, 5-shot issue */
  {
    Out->WaitStableFrameNum = 1;
  	HI704Sensor.PvMode = KAL_TRUE;  
	GrabWidth = HI704_IMAGE_SENSOR_VGA_WIDTH - 10;
	GrabHeight = HI704_IMAGE_SENSOR_VGA_HEIGHT - 10;
  }
  
  Out->GrabStartX = StartX;
  Out->GrabStartY = StartY;
  Out->ExposureWindowWidth = GrabWidth; 
  Out->ExposureWindowHeight = GrabHeight;
}

/*************************************************************************
* FUNCTION
*    HI704Capture
*
* DESCRIPTION
*    This function set to capture mode
*
* PARAMETERS
*    Id, In, Out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void HI704Capture(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint8 StartX = 1, StartY = 1;

#ifdef HI704_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "HI704 Capture");
#endif

  HI704Sensor.PvMode = KAL_FALSE;
  Out->WaitStableFrameNum = 1;
  Out->GrabStartX = StartX;
  Out->GrabStartY = StartY;
  Out->ExposureWindowWidth = HI704_IMAGE_SENSOR_VGA_WIDTH - 10; 
  Out->ExposureWindowHeight = HI704_IMAGE_SENSOR_VGA_HEIGHT - 10;
}

/*************************************************************************
* FUNCTION
*    HI704SensorOpen
*
* DESCRIPTION
*    This function read sensor Id and init sensor
*
* PARAMETERS
*    None
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM HI704SensorOpen(void)
{
  if (HI704_SENSOR_ID != HI704PowerOn())
  {
    return MM_ERROR_SENSOR_READ_ID_FAIL;
  }
  HI704InitialSetting();
  HI704InitParameter();

  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HI704SensorFeatureCtrl
*
* DESCRIPTION
*    This function set sensor feature mode
*
* PARAMETERS
*    Id: scenario Id
*    In: input parameter
*    Out: output parameter
*    OutLen: output parameter length
*    RealOutLen: real output parameter length
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM HI704SensorFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
  
#ifdef HI704_DEBUG
  kal_wap_trace(MOD_ENG, TRACE_INFO, "HI704 FeatureCtrl Id:%x",Id);
#endif
  if (Id >= CAL_FEATURE_WEBCAM_BEGIN && Id <= CAL_FEATURE_WEBCAM_END)
  {
    return HI704WebcamFeatureCtrl(Id, In, Out, OutLen, RealOutLen);
  }
  switch (Id)
  {
   /* CAL Query and set series */
  case CAL_FEATURE_CAMERA_BRIGHTNESS:
  case CAL_FEATURE_CAMERA_EV_VALUE:
    ErrCode = HI704Ev(In, Out);
    break;
  case CAL_FEATURE_CAMERA_CONTRAST:
   // ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    ErrCode = HI704Contrast(In, Out);
    break;
  case CAL_FEATURE_CAMERA_HUE:
  case CAL_FEATURE_CAMERA_SATURATION:
  case CAL_FEATURE_CAMERA_SHARPNESS:
  case CAL_FEATURE_CAMERA_GAMMA:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  case CAL_FEATURE_CAMERA_WB:
    ErrCode = HI704Wb(In, Out);
    break;
  case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
    ErrCode = HI704Effect(In, Out);
    break;
  case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
    ErrCode = HI704StillCaptureSize(In, Out);
    break;
  case CAL_FEATURE_CAMERA_BANDING_FREQ: /* Only query here, set function move to preview */
    ErrCode = HI704Banding(In, Out);
    break;
  case CAL_FEATURE_CAMERA_SCENE_MODE:
    ErrCode = HI704SceneMode(KAL_TRUE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
    ErrCode = HI704SceneMode(KAL_FALSE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_FLASH_MODE:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;

  /* Get Info series */
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
    HI704GetSensorInfo(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = HI704DetectSensorId();
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = HI704Sensor.Fps * 10 / HI704_FRAME_RATE_UNIT;
    break;
  case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
    HI704InitOperationPara(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
    CamGetHWInfo(HI704Sensor.SensorIdx, Out);
    break;
    
  /* Set Para series */
  case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
    CamPdnPinCtrl(HI704Sensor.SensorIdx, 1);   
    CamRstPinCtrl(HI704Sensor.SensorIdx, 0);
    break;
  case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
    HI704Sensor.NvramData = &(((nvram_camera_para_struct *)In)->SENSOR);
    break;
  case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
    HI704Sensor.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
    break;
  case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
    break;
  case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
	HI704Sensor.BypassAe = *(kal_bool *)In;
	HI704AeEnable(HI704Sensor.BypassAe ? KAL_FALSE : KAL_TRUE);
	break;
  case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
    HI704Sensor.BypassAwb = *(kal_bool *)In;
    HI704AwbEnable(HI704Sensor.BypassAwb ? KAL_FALSE : KAL_TRUE);
    break;   
  default:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  }
  return ErrCode;
}

/*************************************************************************
* FUNCTION
*    HI704SensorCtrl
*
* DESCRIPTION
*    This function set sensor scenario mode
*
* PARAMETERS
*    Id: scenario Id
*    In/Out: parameter
*    OutLen: Out parameter length
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM HI704SensorCtrl(CAL_SCENARIO_ENUM Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  switch (Id)
  {
	  case CAL_SCENARIO_CAMERA_PREVIEW:
	  case CAL_SCENARIO_VIDEO:
	  case CAL_SCENARIO_WEBCAM_PREVIEW:
	  case CAL_SCENARIO_WEBCAM_CAPTURE:
	    HI704Preview(Id, In, Out);
	    break;
	  case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
	    HI704Capture(Id, In, Out);
	    break;
	  default:
	    break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HI704SensorClose
*
* DESCRIPTION
*    This function is to turn off sensor module power.
*
* PARAMETERS
*    None
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM HI704SensorClose(void)
{
  /* power down sensor */
  //enter sensor sleep
  CamWriteCmosSensor(0x03, 0x00); //enter	page 0
  CamWriteCmosSensor(0x01, (CamReadCmosSensor(0x01)|0x01));
  kal_sleep_task(1); // need >= 1ms  jun debug
  
  CamPdnPinCtrl(HI704Sensor.SensorIdx, 1);
  kal_sleep_task(1); // need >= 5ms  jun debug
  CamRstPinCtrl(HI704Sensor.SensorIdx, 0);
  CisModulePowerOn(HI704Sensor.SensorIdx, KAL_FALSE);
  CameraSccbClose(CAMERA_SCCB_SENSOR);
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HI704SensorFunc
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
MM_ERROR_CODE_ENUM HI704SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncHI704 =
  {
    HI704SensorOpen,
    HI704SensorFeatureCtrl,
    HI704SensorCtrl,
    HI704SensorClose,
  };
  
  *pfSensorFunc = &ImageSensorFuncHI704;
  
  return MM_ERROR_NONE;
}

