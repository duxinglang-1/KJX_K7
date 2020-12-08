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
 *   image_sensor_PAS6327.c
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


/* #define PAS6327_DEBUG */
static struct 
{
      kal_bool      PvMode;                 //True: Preview Mode; False: Capture Mode
      kal_bool      NightMode;              //True: Night Mode; False: Auto Mode
      kal_bool      VideoMode;  
      kal_bool      WebcamMode;
      kal_uint8     mirror;
      kal_bool      BypassAe;
      kal_bool      BypassAwb;
      kal_uint32    PvPclk;               //Preview Pclk
      kal_uint32    CpPclk;               //Capture Pclk
      kal_uint16    DummyPixels;          //Dummy Pixels
      kal_uint16    DummyLines;           //Dummy Lines
      kal_uint16     Fps;         
      kal_uint8     Banding;
      kal_uint16    ActiveHsize;
      kal_uint16    ActiveVsize;
      kal_uint16    LineLength;
      kal_uint16    FrameHeight;
      kal_uint8	    BrightnessValueLL;
      kal_uint8	    BrightnessValueNL;
      IMAGE_SENSOR_INDEX_ENUM SensorIdx;
      sensor_data_struct *NvramData; //Need to check if need this item
}PAS6327Sensor;

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

const kal_uint8 PAS6327InitSetting[][2]={
        //PAS6327_YUV_MTK_Normal_20100517.asc
  //bank 0
	{0xEF,0x00},
	{0x04,0x0B},
	{0x06,0x00},
	{0x07,0xAA},
	{0x08,0x61},
	{0x09,0x00},
	{0x0A,0xFF},
	{0x0B,0x30},
	{0x0C,0x00},
	{0x0F,0x96},
	{0x11,0x73},
	{0x13,0xF8},
	{0x14,0x21},
	{0x15,0x96},
	{0x17,0x73},
	{0x19,0x3F},
	{0x1A,0x80},
	{0x1B,0x3F},
	{0x1C,0x80},
	
	{0x39,0x01},
	{0x45,0x02},
	{0x46,0x00},
	{0x47,0x34},
	{0x48,0x16},
	{0x49,0x10},
	{0x4A,0x16},
	{0x4B,0x80},
	{0x4C,0x80},
	{0x4D,0xE6},
	{0x4E,0xF0},
	{0x4F,0xF5},
	{0x50,0x16},
	{0x51,0x1C},
	{0x52,0x0B},
	{0x53,0x46},
	{0x54,0xFF},
	{0x55,0x1E},
	{0x56,0x19},
	{0x57,0x01},
	{0x58,0x03},
	{0x59,0x02},
	{0x5A,0x04},
	{0x5B,0x03},
	{0x63,0x30},
	{0x64,0x05},
	{0x65,0x31},
	{0x66,0x33},
	//jun modify for debug
//	{0x67,0xc6},//For MT6225 platform only, don't modify. Angelo 2010/01/12
//	{0x68,0x2d},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0x69,0x04},
	{0x6A,0x00},
	{0x6B,0x07},  // from 04 to 07
	{0x6C,0x18},  // 0x12 to 0x1C webcam chris 0902
	{0x6D,0x24},
	{0x6E,0x12},
	{0x6F,0x91},
	{0x70,0x00},
	{0x71,0x00},
	{0x72,0x01},
	{0x73,0x02},
	{0x74,0x40},
	{0x75,0x02},
	{0x76,0x07},
	{0x77,0x08},
	{0x78,0x01},
	{0x79,0x16},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0x7b,0x09},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0x7D,0x00},
	{0x7E,0x00},
	{0x7F,0xFF},
	{0x80,0xFE},
	{0x81,0x00},
	{0x82,0x5F},
	{0x83,0xF8},
	{0x84,0x16},
	{0x86,0x12},
	{0x87,0xEA},
	{0x88,0x01},
	{0x89,0x00},
	{0x8A,0x02},
	{0x8B,0x00},
	{0x8C,0xDE},
	{0x8E,0x00},
	{0x8F,0x00},
	{0x90,0x00},
	{0x91,0x00},
	{0x92,0x00},
	{0x93,0x00},
	{0x94,0x00},
	{0x95,0x07},
	{0x96,0x00},
	
	{0xBD,0x0D},//MTKSOP 0902
	{0xE0,0x80},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0xE1,0x02},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0xE2,0xE6},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0xE3,0x01},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0xE4,0xFF},
	{0xE5,0x00},
	{0xE6,0x00},
	{0xE9,0x87},
	{0xEA,0x00},
	{0xEB,0x00},
	{0xED,0x00},
	{0xEE,0x3F},
	{0xED,0x01},
	//bank 1	
	{0xEF,0x01},
	{0x02,0x01},//NP
	{0x03,0x83},
	{0x04,0xFD},
	{0x05,0x01},
	{0x06,0x0F},//Color Gain
	{0x07,0x13},
	{0x08,0x0F},
	{0x09,0x16},//Color Gain End
	{0x0C,0x23},
	{0x0D,0xC6},
	{0x0E,0x02},
	{0x0F,0x00},
	{0x10,0x11},
	{0x11,0x00},
	{0x12,0x20},
	{0x17,0x00},
	{0x18,0x00},
	{0x19,0x00},
	{0x1A,0x00},
	{0x1B,0x8F},
	{0x1C,0x02},
	{0x1D,0xF1}, 
	{0x1E,0x01},
	{0x20,0x16},
	{0x21,0x00},
	{0x22,0x08},
	{0x23,0x00},
	{0x24,0x05},
	{0x27,0x23},
	{0x28,0x00},
	{0x2A,0x00},
	{0x2B,0x4A},
	{0x2C,0x64},
	{0x2D,0x13},
	{0x2E,0x49},
	{0x2F,0x4A},
	{0x30,0x54},
	{0x31,0x86},
	{0x32,0x21},
	{0x33,0x31},
	{0x34,0x81},
	{0x35,0x00},
	{0x36,0x00},
	{0x37,0x00},
	{0x38,0x00},
	{0x39,0x20},
	{0x3B,0x03},
	{0x3C,0x03},
	{0x3D,0x03},
	{0x3E,0x03},
	{0x40,0x00},
	{0x41,0x06},
	{0x42,0x00},
	{0x43,0x82},
	{0x44,0x0E},
	{0x45,0x43},
	{0x48,0x32},
	{0x49,0x22},
	{0x4A,0x00},
	{0x4B,0x18},//[3] : cg_offset_EnL Sync With Cmd_Dac1_even/odd_Sign
	{0x50,0x03},
	{0x51,0x44},
	{0x52,0x61},//0x61=4,0x69=5,0x71=6,0x79=7 [5:3] pixel bias
	{0x53,0x20},
	{0x54,0x08},
	{0x56,0x00},
	{0x57,0x00},
	{0x58,0x00},
	{0x5D,0x00},
	{0x5E,0x03},
	{0x60,0x00},
	{0x62,0x35},
	{0x63,0x7F},
	{0x64,0x34},
	{0x66,0x06},
	{0x67,0x08},
	{0x68,0x07},// LDO enable
	{0x6F,0x00},
	{0x70,0x00},
	{0x71,0x00},
	{0x72,0x00},
	{0x73,0x00},
	{0x74,0x00},
	{0x75,0x00},
	{0x76,0x00},
	{0x77,0x20},
	{0x78,0x07},//0x03// IO driving  from 0x00 to 0x07 [2:0]=>0,1,3,7  [3] slew rate enable
	{0x79,0x0F},
	{0x7A,0x0F},
	{0x7B,0x8A},
	{0x7C,0x00},
	{0x7E,0xAA},
	{0x7F,0xAA},
	{0x80,0x00},
	{0x82,0x00},
	{0x87,0x00},
	{0x88,0x00},
	{0x89,0x00},
	{0x8A,0x00},
	{0x8B,0x00},
	{0x8C,0x00},
	{0x8D,0x02},
	{0x8E,0x00},
	{0x8F,0x00},
	{0x90,0x00},
	{0x91,0x00},
	{0x9E,0x02},
	{0x9F,0x00},
	{0xA1,0x04},
	{0xA2,0xC0}, // Analog setting 0903 from 0x00 to 0xC0
	{0xA4,0x00},
	{0xA5,0x00},
	{0xA6,0x00},
	{0xA7,0x08},
	{0xA8,0x00},
	{0xA9,0x00},
	{0xAA,0x00},
	{0xAB,0x00},
	{0xAC,0x00},
	{0xB0,0x00},
	{0xB1,0x00},
	{0xB2,0x00},
	{0xB4,0x02},
	{0xB6,0x0C},
	{0x11,0x01},
    // Bank 2
	{0xEF,0x02},//////// Bank 2
	{0x07,0x00},
	{0x08,0x00},
	{0x09,0x00},
	{0x0A,0x00},
	{0x0E,0x00},
	{0x0F,0x00},
	{0x10,0x00},
	{0x13,0x00},
	
	{0x1A,0x19},
	{0x1B,0x0F},
	{0x1C,0x20},
	{0x1D,0x82},
	{0x1E,0x08},
	{0x1F,0x1A},
	{0x20,0x02},
	{0x21,0x03},
	{0x22,0x3F},
	{0x23,0xA3},
	{0x24,0xF0},
	{0x25,0x1E},
	{0x26,0x19},
	{0x2A,0x90},
	{0x2B,0x30},
	{0x2C,0x50},
	{0x2D,0x3C},
	{0x2F,0x1A},
	{0x30,0x12},
	{0x32,0x7F},
	{0x36,0x04},
	{0x37,0x88},
	{0x38,0x8F},
	{0x39,0x18},
	{0x3A,0x8E},
	{0x3B,0x20},
	{0x3C,0x03},
	
	{0x55,0x00},
	{0x56,0x05},
	{0x57,0x02},
	{0x58,0x0A},
	{0x59,0x00},
	{0x5A,0x08},
	{0x5B,0x08},
	{0x5C,0x1E}, // 0x07 to 0x1E chris 0831
	{0x5D,0x02},
	{0x5E,0x01},
	{0x5F,0x08},
	{0x60,0x11},
	{0x61,0x00},
	{0x62,0x01},
	{0x63,0x0F},
	{0x64,0x11},
	{0x65,0x40},
	{0x66,0x96},
	{0x67,0x00},
	{0x68,0x00},
	{0x69,0x0F},
	{0x6A,0x00},
	{0x9b,0x02},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0x9c,0x80},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0x9d,0x01},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0x9e,0xe4},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0x9f,0x00},//For MT6225 platform only, don't modify. Angelo 2010/01/12 
	{0xa0,0x00},//For MT6225 platform only, don't modify. Angelo 2010/01/12 
	{0xa1,0x00},//For MT6225 platform only, don't modify. Angelo 2010/01/12/
	{0xa2,0x00},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0xa3,0x01},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0xa4,0x02},//For MT6225 platform only, don't modify. Angelo 2010/01/12 
	{0xa5,0x00},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0xa6,0x02},// Chris 0902
	{0xa8,0x00},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0xa9,0x20},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0xaa,0x02},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0xab,0x80},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0xAC,0x00},
	{0xAD,0x00},
	{0xAE,0x00},
	{0xb0,0x00},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0xb1,0x00},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0xb2,0x00},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0xb3,0x00},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0xb4,0x02},//or MT6225 platform only, don't modify. Angelo 2010/01/12
	{0xb5,0x80},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0xb6,0x01},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0xb7,0xE4},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0xB8,0x00},
	{0xB9,0x00},
	{0xBA,0x00},
	{0xBB,0x00},
	{0xBC,0x03},
	{0xBE,0x00},
	{0xBF,0x04},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0xC0,0x00},//For MT6225 platform only, don't modify. Angelo 2010/01/12
	{0xC1,0x13},// Chris 0902 
	{0xC2,0x00},
	{0xE0,0x04},
	{0xE3,0x00},
	{0xE4,0x00},
	{0xE5,0x00},
	{0xE6,0x00},
	{0xEB,0x00},
	{0x00,0x01},
};
const kal_uint8 PAS6327DeNoise[][2]={ 
	{0xef,0x00},
	{0x1F,0x10},//DeNoise
	{0x20,0x0C},
	{0x21,0x06},
	{0x22,0x14},
	{0x23,0x0D},
	{0x24,0x07},
	{0x25,0x16},
	{0x26,0x00},
	{0x27,0x00},//DeNoise End
	{0xed,0x01},												
};
const kal_uint8 PAS6327ISPGamma[][2]={
	{0xef,0x00},
	{0x29,0x01},//ISP Gamma
	{0x2A,0x0D},
	{0x2B,0x1A},
	{0x2C,0x30},
	{0x2D,0x54},
	{0x2E,0x63},
	{0x2F,0x71},
	{0x30,0x7D},
	{0x31,0x88},
	{0x32,0x9C},
	{0x33,0xAC},
	{0x34,0xBA},
	{0x35,0xC6},
	{0x36,0xD9},
	{0x37,0xE9},
	{0x38,0xF2},//ISP Gamma End
	{0xed,0x01},											
};
const kal_uint8 PAS6327LensShading[][2]={
	{0xef,0x00},
	{0x97,0x10},//Lens shading enable
	{0x99,0x33},
	{0x9A,0x33},
	{0x9B,0x33},
	{0x9C,0x33},
	{0x9D,0x39},
	{0x9E,0x39},
	{0x9F,0x39},
	{0xA0,0x39},
	{0xA1,0x4A},
	{0xA2,0x4A},
	{0xA3,0x4A},
	{0xA4,0x4A},
	{0xA5,0xA0},
	{0xA6,0x7C},
	{0xA7,0x00},
	{0xA8,0xB0},
	{0xA9,0x00},
	{0xAA,0x11},//Lens shading enable End
	{0xed,0x01},
};
const kal_uint8 PAS6327ISPTone[][2]={
	{0xef,0x02},
	{0x17,0x01},//ISP tone curve
	{0x18,0x88},
	{0x19,0xC6},//ISP tone curve end
	{0x00,0x01},
};
const kal_uint8 PAS6327CCMb[][2]={
	{0xef,0x02},
	{0x3E,0x33},//CCM matrix coefficient
	{0x3F,0x25},
	{0x40,0x4B},
	{0x41,0x10},
	{0x42,0x0C},
	{0x43,0x40},
	{0x44,0x4C},
	{0x45,0x48},
	{0x46,0x48},
	{0x47,0x00},
	{0x4F,0x01},
	{0x50,0x3C},
	{0x51,0x04},
	{0x52,0x0F},
	{0x53,0x08},
	{0x54,0x01},//CCM matrix coefficient end
	{0x00,0x01},
};
const kal_uint8 PAS6327Ytag[][2]={ 
	//Ytag, Offset
	{ 45, 0},//EV-4
	{ 70, 0},//EV-3
	{ 95, 0},//EV-2 
	{120, 0},//EV-1
	{145, 0},//EV 0
	{145,16},//EV+1
	{145,32},//EV+2
	{145,48},//EV+3
	{145,64},//EV+4
};

const kal_uint8 PAS6327EffectPara[10][6]={
	//R_ImgEffectMode, R_ISP_ImgEffect_En, R_ImgEffect_c0, R_ImgEffect_c1, R_ImgEffect_c2, R_ImgEffect_c3
	//0x8f,   0x90,   0x91,   0x92, 0x93,  0x94,
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00,}, //CAM_EFFECT_ENC_NORMAL
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x01,}, //CAM_EFFECT_ENC_GRAYSCALE
	{0x64, 0x8d, 0x00, 0x00, 0x03, 0x01,}, //CAM_EFFECT_ENC_SEPIA
	{0x00, 0x00, 0x00, 0x00, 0x01, 0x01,}, //CAM_EFFECT_ENC_COLORINV
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00,}, //CAM_EFFECT_ENC_EMBOSSMENT
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00,}, //CAM_EFFECT_ENC_SKETCH
	{0x69, 0x71, 0x00, 0x00, 0x03, 0x01,}, //CAM_EFFECT_ENC_SEPIAGREEN
	{0x97, 0x84, 0x00, 0x00, 0x03, 0x01,}, //CAM_EFFECT_ENC_SEPIABLUE
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00,}, //CAM_EFFECT_ENC_BLACKBOARD
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00,}, //CAM_EFFECT_ENC_CONTRAST
};
const kal_uint8 PAS6327WbMode[6][4]={
	//Cmd_Cgn_Gb,	Cmd_Cgn_B, Cmd_Cgn_Gr, Cmd_Cgn_R
	//0x06, 0x07, 0x08,0x09
	{0x0F,0x13,0x0F,0x16},//Auto					
	{0x0c,0x0e,0x0c,0x14},//Cloud
	{0x0a,0x10,0x0a,0x17},//DAYLIGHT
	{0x0c,0x1c,0x0c,0x09},//INCANDESCENCE
	{0x10,0x15,0x10,0x19},//FLUORESCENT
	{0x10,0x11,0x10,0x0d},//TUNGSTEN
};
const kal_uint8 PAS6327AEMode[4][4]={ 
	/* R_AE_maxStage[4:0], R_AG_stage_UB, R_Saturation_LL[4:0], R_Brightness_LL[7:0]*/ 	
	// 0x26 Gain = 16.5X,0x30 Gain = 24X,0x40 Gain=48X
	{0x14,0x24,0x08,0x05},//Camera Normal, 10 fps, chris0831
	{0x1B,0x24,0x0B,0x00},//Camera Night,  5 fps,    chris0831
	{0x0D,0x24,0x08,0x0f},//Video Normal min 30fps
	{0x10,0x1D,0x09,0x00},//Video Night  min 15fps
};


/*************************************************************************
* FUNCTION
*    PAS6327InitialSetting
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

static void PAS6327InitialSetting(void)
{
  #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
  #else
	kal_uint32 i =0;
	
	for(i=0; i<(sizeof(PAS6327InitSetting)/2); i++)
			CamWriteCmosSensor((kal_uint8)PAS6327InitSetting[i][0],(kal_uint8)PAS6327InitSetting[i][1]);
		
		for(i=0; i<(sizeof(PAS6327DeNoise)/2); i++)
			CamWriteCmosSensor((kal_uint8)PAS6327DeNoise[i][0],(kal_uint8)PAS6327DeNoise[i][1]);
	
		for(i=0; i<(sizeof(PAS6327ISPGamma)/2); i++)
			CamWriteCmosSensor((kal_uint8)PAS6327ISPGamma[i][0],(kal_uint8)PAS6327ISPGamma[i][1]);
	
		for(i=0; i<(sizeof(PAS6327LensShading)/2); i++)
			CamWriteCmosSensor((kal_uint8)PAS6327LensShading[i][0],(kal_uint8)PAS6327LensShading[i][1]);
	
		for(i=0; i<(sizeof(PAS6327ISPTone)/2); i++)
			CamWriteCmosSensor((kal_uint8)PAS6327ISPTone[i][0],(kal_uint8)PAS6327ISPTone[i][1]);
	
		for(i=0; i<(sizeof(PAS6327CCMb)/2); i++)
			CamWriteCmosSensor((kal_uint8)PAS6327CCMb[i][0],(kal_uint8)PAS6327CCMb[i][1]);
  #endif

}


/*************************************************************************
* FUNCTION
*    PAS6327SetMirrorFlip
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
void PAS6327SetMirrorFlip(kal_uint8 mirror)
{
	  /********************************************************
		* Page Mode 0: Reg 0x0011 bit[1:0] = [Y Flip : X Flip]
		* 0: Off; 1: On.
		*********************************************************/	
    kal_uint8 iTemp = 0;
		
   #ifdef PAS6327_DEBUG
		kal_wap_trace(MOD_ENG,TRACE_INFO,"image_mirror:%d",mirror);
   #endif

 #if 1
    //Get Image Filp setting
	CamWriteCmosSensor(0xef,0x01);
	iTemp = CamReadCmosSensor(0x21) & ~0x0c;
	
		switch (mirror) 
		{
			case IMAGE_SENSOR_MIRROR_NORMAL://VFlip = 0 , HFlip = 0;
				iTemp = iTemp | 0x00;
				break;
			case IMAGE_SENSOR_MIRROR_H://VFlip = 0 , HFlip = 1;
				iTemp = iTemp | 0x04;
				break;
			case IMAGE_SENSOR_MIRROR_V://VFlip = 1 , HFlip = 0;
				iTemp = iTemp | 0x08;
				break;
			case IMAGE_SENSOR_MIRROR_HV://VFlip = 1 , HFlip = 1;
				iTemp = iTemp | 0x0c;
				break;			
		}
	
	CamWriteCmosSensor(0x21,iTemp);
	CamWriteCmosSensor(0x11,0x01);
 #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	
}	/* PAS6327_Set_Mirror_Flip */

/*************************************************************************
* FUNCTION
*    PAS6327Ev
*
* DESCRIPTION
*    PAS6327 EV setting.
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
static MM_ERROR_CODE_ENUM PAS6327Ev(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    kal_uint8 EvTemp = 0;
#ifdef PAS6327_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "EV:%d", In->FeatureSetValue);
#endif
    switch (In->FeatureSetValue)
    {
    case CAM_EV_NEG_4_3: EvTemp = 0; break;
    case CAM_EV_NEG_3_3: EvTemp = 1; break;
    case CAM_EV_NEG_2_3: EvTemp = 2; break;
    case CAM_EV_NEG_1_3: EvTemp = 3; break;
    case CAM_EV_ZERO:    EvTemp = 4; break;
    case CAM_EV_POS_1_3: EvTemp = 5; break;
    case CAM_EV_POS_2_3: EvTemp = 6; break;
    case CAM_EV_POS_3_3: EvTemp = 7; break;
    case CAM_EV_POS_4_3: EvTemp = 8; break;
    default: break;
    }       

    CamWriteCmosSensor(0xef,0x00);
	CamWriteCmosSensor(0x6f,PAS6327Ytag[EvTemp][0]);		
	CamWriteCmosSensor(0xed,0x01);

	CamWriteCmosSensor(0xef,0x02);
	CamWriteCmosSensor(0x69,PAS6327Sensor.BrightnessValueLL+PAS6327Ytag[EvTemp][1]);
	CamWriteCmosSensor(0x6A,PAS6327Sensor.BrightnessValueNL+PAS6327Ytag[EvTemp][1]);
	CamWriteCmosSensor(0x00,0x01);
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    PAS6327Contrast
*
* DESCRIPTION
*    PAS6327 Contrast setting.
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
static MM_ERROR_CODE_ENUM PAS6327Contrast(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    
#ifdef PAS6327_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "EV:%d", In->FeatureSetValue);
#endif
    switch (In->FeatureSetValue)
    {
    case CAM_CONTRAST_HIGH:   //G 10 
	    CamWriteCmosSensor(0xef,0x00);
		CamWriteCmosSensor(0x29,0x01);  
		CamWriteCmosSensor(0x2A,0x3b);				
		CamWriteCmosSensor(0x2B,0x61);				
		CamWriteCmosSensor(0x2C,0x8f);				
		CamWriteCmosSensor(0x2D,0xba);				
		CamWriteCmosSensor(0x2E,0xc7);				
		CamWriteCmosSensor(0x2F,0xd0);				
		CamWriteCmosSensor(0x30,0xd7);				
		CamWriteCmosSensor(0x31,0xdc);				
		CamWriteCmosSensor(0x32,0xe5);				
		CamWriteCmosSensor(0x33,0xea);				
		CamWriteCmosSensor(0x34,0xef);				
		CamWriteCmosSensor(0x35,0xf2);				
		CamWriteCmosSensor(0x36,0xf7);				
		CamWriteCmosSensor(0x37,0xfb);				
		CamWriteCmosSensor(0x38,0xfd);
		CamWriteCmosSensor(0xed,0x01);
       break;
    case CAM_CONTRAST_MEDIUM: //Normal
        CamWriteCmosSensor(0xef,0x00);
		CamWriteCmosSensor(0x29,0x01);
		CamWriteCmosSensor(0x2A,0x0D);
		CamWriteCmosSensor(0x2B,0x1A);
		CamWriteCmosSensor(0x2C,0x30);
		CamWriteCmosSensor(0x2D,0x54);
		CamWriteCmosSensor(0x2E,0x63);
		CamWriteCmosSensor(0x2F,0x71);
		CamWriteCmosSensor(0x30,0x7D);
		CamWriteCmosSensor(0x31,0x88);
		CamWriteCmosSensor(0x32,0x9C);
		CamWriteCmosSensor(0x33,0xAC);
		CamWriteCmosSensor(0x34,0xBA);
		CamWriteCmosSensor(0x35,0xC6);
		CamWriteCmosSensor(0x36,0xD9);
		CamWriteCmosSensor(0x37,0xE9);
		CamWriteCmosSensor(0x38,0xF2);
		CamWriteCmosSensor(0xed,0x01);
       break;
    case CAM_CONTRAST_LOW: //G Disable
        CamWriteCmosSensor(0xef,0x00);
		CamWriteCmosSensor(0x29,0x00);//ISP Gamma
		CamWriteCmosSensor(0xed,0x01);
       break;
    default: break;
    }
  
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    PAS6327Wb
*
* DESCRIPTION
*    PAS6327 WB setting.
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
static MM_ERROR_CODE_ENUM PAS6327Wb(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
     kal_uint8 Index = 0;
#ifdef PAS6327_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"WB:%d",In->FeatureSetValue);
#endif
	if(In->FeatureSetValue == CAM_WB_AUTO)
	{
			CamWriteCmosSensor(0xef,0x00);
			CamWriteCmosSensor(0x72,0x01);		
			CamWriteCmosSensor(0xed,0x01);
			CamWriteCmosSensor(0x80, CamReadCmosSensor(0x80)|0x78);  // set[11~14] to 1
			CamWriteCmosSensor(0xed,0x01);					 
			return MM_ERROR_NONE;
	}		
    else
    {

	        CamWriteCmosSensor(0xef,0x00);
			CamWriteCmosSensor(0x72,0x10);
			CamWriteCmosSensor(0xed,0x01);
			CamWriteCmosSensor(0x80, CamReadCmosSensor(0x80)&0x87);  // set[11~14] to 0
			CamWriteCmosSensor(0xed,0x01);

		    switch (In->FeatureSetValue)
		    {
		    case CAM_WB_AUTO: /* enable AWB */
		      /* CAM_WB_AUTO mode should not update R/G/B gains */
		         Index = 0;
		      break;
		    case CAM_WB_CLOUD: /* disable AWB */
				 Index = 1;	
		      break;
		    case CAM_WB_DAYLIGHT:/* disable AWB */
		         Index = 2;	   
		      break;
		    case CAM_WB_INCANDESCENCE:/* disable AWB */
		         Index = 3;
		      break;
		    case CAM_WB_FLUORESCENT:/* disable AWB */
				Index = 4;
		      break;
		    case CAM_WB_TUNGSTEN:/* disable AWB */
		        Index = 5;
		      break;
		    default:
		      return MM_ERROR_NONE;    
		    }
		    CamWriteCmosSensor(0xef,0x01);
			CamWriteCmosSensor(0x06,PAS6327WbMode[Index][0]);//Cmd_Cgn_Gb
			CamWriteCmosSensor(0x07,PAS6327WbMode[Index][1]);//Cmd_Cgn_B
			CamWriteCmosSensor(0x08,PAS6327WbMode[Index][2]);//Cmd_Cgn_Gr
			CamWriteCmosSensor(0x09,PAS6327WbMode[Index][3]);//Cmd_Cgn_R
			CamWriteCmosSensor(0x11,0x01);
   }
  }
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    PAS6327Effect
*
* DESCRIPTION
*    PAS6327 Effect setting.
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
static MM_ERROR_CODE_ENUM PAS6327Effect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    P_CAL_FEATURE_TYPE_ENUM_STRUCT EffectPara = &Out->FeatureInfo.FeatureEnum;
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION | CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    EffectPara->IsSupport = KAL_TRUE;
    EffectPara->ItemCount = 10;
    EffectPara->SupportItem[0] = CAM_EFFECT_ENC_NORMAL;
    EffectPara->SupportItem[1] = CAM_EFFECT_ENC_GRAYSCALE;
    EffectPara->SupportItem[2] = CAM_EFFECT_ENC_SEPIA;
    EffectPara->SupportItem[3] = CAM_EFFECT_ENC_SEPIAGREEN;
    EffectPara->SupportItem[4] = CAM_EFFECT_ENC_SEPIABLUE;
    EffectPara->SupportItem[5] = CAM_EFFECT_ENC_COLORINV;
    EffectPara->SupportItem[6] = CAM_EFFECT_ENC_EMBOSSMENT;
    EffectPara->SupportItem[7] = CAM_EFFECT_ENC_SKETCH;
    EffectPara->SupportItem[8] = CAM_EFFECT_ENC_BLACKBOARD;
    EffectPara->SupportItem[9] = CAM_EFFECT_ENC_CONTRAST;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    kal_int8 index = 0;
  
#ifdef PAS6327_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"Effect:%d",In->FeatureSetValue);
#endif
    switch (In->FeatureSetValue)
    {
    case CAM_EFFECT_ENC_NORMAL:
		index = 0;
      break;
    case CAM_EFFECT_ENC_GRAYSCALE:
		index = 1;
      break;
    case CAM_EFFECT_ENC_SEPIA:
		index = 2;
      break;
    case CAM_EFFECT_ENC_SEPIAGREEN:
        index = 6;
      break;
    case CAM_EFFECT_ENC_SEPIABLUE:
		index = 7;
      break;
    case CAM_EFFECT_ENC_COLORINV:
        index = 3;
      break;
    case CAM_EFFECT_ENC_EMBOSSMENT:
        index = 4;
      break;
    case CAM_EFFECT_ENC_SKETCH:
        index = 5;
      break;
    case CAM_EFFECT_ENC_BLACKBOARD:
		index = 8;
	  break;				
	case CAM_EFFECT_ENC_CONTRAST:
		index = 9;
	  break;	
    default:
      return MM_ERROR_NONE;
    }
	CamWriteCmosSensor(0xef,0x00);
	CamWriteCmosSensor(0x8f,PAS6327EffectPara[index][0]);//R_ImgEffect_c0
	CamWriteCmosSensor(0x90,PAS6327EffectPara[index][1]);//R_ImgEffect_c1
	CamWriteCmosSensor(0x91,PAS6327EffectPara[index][2]);//R_ImgEffect_c2
	CamWriteCmosSensor(0x92,PAS6327EffectPara[index][3]);//R_ImgEffect_c3
	CamWriteCmosSensor(0x93,PAS6327EffectPara[index][4]);//R_ImgEffectMode
	CamWriteCmosSensor(0x94,PAS6327EffectPara[index][5]);//R_ISP_ImgEffect_En
	CamWriteCmosSensor(0xed,0x01);   
  }   
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    PAS6327StillCaptureSize
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
static MM_ERROR_CODE_ENUM PAS6327StillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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

static kal_uint8 PAS6327SetParamBanding(kal_uint8 para)
{
   kal_bool Banding60HZ = 0;
    #ifdef PAS6327_DEBUG
        kal_wap_trace(MOD_ENG, TRACE_INFO,"PAS6327_Set_Param_Banding = %d",para);
    #endif

	switch (para)
	{
		case CAM_BANDING_50HZ:
			Banding60HZ = 0;
			break;

		case CAM_BANDING_60HZ:
	        Banding60HZ = 1;
			break;
			
	    default:
	        return KAL_FALSE;
	}

	CamWriteCmosSensor(0xef,0x00);
	CamWriteCmosSensor(0x66,((CamReadCmosSensor(0x66)&0xFE)| Banding60HZ));
	CamWriteCmosSensor(0xed,0x01);
	
	return KAL_TRUE;
} /* PAS6327_Set_Param_Banding *


/*************************************************************************
* FUNCTION
*    PAS6327Banding
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
static MM_ERROR_CODE_ENUM PAS6327Banding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
#ifdef PAS6327_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"Banding:%d",In->FeatureSetValue);
#endif
    PAS6327Sensor.Banding = In->FeatureSetValue;
    PAS6327SetParamBanding(PAS6327Sensor.Banding);  
  }  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    PAS6327GetSensorInfo
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
static void PAS6327GetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT Info)
{
  Info->SensorId = PAS6327_SENSOR_ID;
  Info->SensorIf = IMAGE_SENSOR_IF_PARALLEL;
  Info->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;  //need to check
  Info->PreviewHMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY; //need to check
  Info->PreviewVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;//need to check
  Info->PreviewHVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;  //need to check
  Info->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PixelClkInv = KAL_FALSE;
  Info->PixelClkPolarity = POLARITY_LOW;
  Info->HsyncPolarity = POLARITY_LOW;
  Info->VsyncPolarity = POLARITY_HIGH;
  
  Info->PreviewMclkFreq = 26000000;
  Info->CaptureMclkFreq = 26000000;
  Info->VideoMclkFreq = 26000000;

  Info->PreviewWidth = PAS6327_IMAGE_SENSOR_VGA_WIDTH;//PAS6327_IMAGE_SENSOR_PV_WIDTH
  Info->PreviewHeight = PAS6327_IMAGE_SENSOR_VGA_HEIGHT;//PAS6327_IMAGE_SENSOR_PV_HEIGHT
  Info->FullWidth = PAS6327_IMAGE_SENSOR_VGA_WIDTH;//PAS6327_IMAGE_SENSOR_FULL_WIDTH
  Info->FullHeight = PAS6327_IMAGE_SENSOR_VGA_HEIGHT;//PAS6327_IMAGE_SENSOR_FULL_HEIGHT
  Info->SensorAfSupport = KAL_FALSE;
  Info->SensorFlashSupport = KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*    PAS6327DetectSensorId
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
static kal_uint32 PAS6327DetectSensorId(void)
{
  MM_ERROR_CODE_ENUM PAS6327SensorClose(void);
  kal_uint16 PAS6327PowerOn();
  kal_uint16 SensorId;
  IMAGE_SENSOR_INDEX_ENUM AnotherSensorIdx;
  kal_int8 i, j;
  
  if (IMAGE_SENSOR_MAIN == PAS6327Sensor.SensorIdx)
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
      SensorId = PAS6327PowerOn();
      PAS6327SensorClose();
#ifdef PAS6327_DEBUG
      kal_wap_trace(MOD_ENG,TRACE_INFO,"PAS6327DetectSensorId:%x",SensorId);
#endif
      if (PAS6327_SENSOR_ID == SensorId)
      {
        return PAS6327_SENSOR_ID;
      }
    }
  }
  return 0xFFFFFFFF;
}

/*************************************************************************
* FUNCTION
*    PAS6327InitOperationPara
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
static void PAS6327InitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT Para)
{
  Para->CaptureDelayFrame = 2; /* wait stable frame when sensor change mode (pre to cap) */
  Para->PreviewDelayFrame = 2; /* wait stable frame when sensor change mode (cap to pre) */
  Para->PreviewDisplayWaitFrame = 2; /* wait stable frame when sensor change mode (cap to pre) */
}

/*************************************************************************
* FUNCTION
*    PAS6327AeEnable
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
static MM_ERROR_CODE_ENUM PAS6327AeEnable(kal_bool Enable)  //need to do AE func
{

  kal_uint8 Reg_vlaue = 0;
  
#ifdef PAS6327_DEBUG
	kal_prompt_trace(MOD_ENG,"AEenable:%d",Enable);
#endif

  if (PAS6327Sensor.BypassAe && PAS6327Sensor.PvMode)
  {
	  Enable = KAL_FALSE;
  }

  CamWriteCmosSensor(0xef,0x00);
   Reg_vlaue = CamReadCmosSensor(0x66);

  if (Enable)
	  Reg_vlaue |= 0x10;

  else
      Reg_vlaue &= 0xef;

  
  CamWriteCmosSensor(0x66,Reg_vlaue);  
  //  CamWriteCmosSensor(0xed,0x01);  /* AE的设定不需要update flag */

  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    PAS6327AwbEnable
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
static MM_ERROR_CODE_ENUM PAS6327AwbEnable(kal_bool Enable)   //need to do AE func
{

 	kal_uint8 Reg_vlaue = 0;

   #ifdef PAS6327_DEBUG
	  kal_prompt_trace(MOD_ENG,"AWBenable:%d",Enable);
   #endif

   if (PAS6327Sensor.BypassAwb && PAS6327Sensor.PvMode)
  {
    Enable = KAL_FALSE;
  }

   	CamWriteCmosSensor(0xef,0x00);
	Reg_vlaue = CamReadCmosSensor(0x72);

  if (Enable)
    Reg_vlaue |= 0x01;
  else
    Reg_vlaue &= 0xfe;
	
	CamWriteCmosSensor(0x72,Reg_vlaue);	
//	CamWriteCmosSensor(0xed,0x01);  /* AWB的设定不需要update flag */

  return MM_ERROR_NONE;
}

static void PAS6327SetDummy(kal_uint16 DummyPixel,kal_uint16 DummyLine)
{
  kal_uint16 frameHeight = 0;

   frameHeight = PAS6327Sensor.ActiveVsize + PAS6327Sensor.DummyLines;
   PAS6327Sensor.FrameHeight = frameHeight;
  
    CamWriteCmosSensor(0xef,0x01);
	CamWriteCmosSensor(0x03,(DummyPixel&0x00FF));//Cmd_Nov_Size[7:0]
	CamWriteCmosSensor(0x80,(DummyPixel&0xFF00)>>8);//Cmd_Nov_Size[15:8]
	CamWriteCmosSensor(0x11,0x01);

  	CamWriteCmosSensor(0xef,0x00);
	CamWriteCmosSensor(0x13,frameHeight&0x00FF);				/* R_lpf_min[7:0] */
	CamWriteCmosSensor(0x14,(9<<4)|((frameHeight&0x0700)>>8));	/* R_lpf_min[10:8] */
	CamWriteCmosSensor(0xed,0x01);
}

static void PAS6327CalFrameRate(kal_uint16 Fps)
{
    #ifdef PAS6327_DEBUG
        kal_wap_trace(MOD_ENG, TRACE_INFO,"[PAS6327] PAS6327_NightMode...");
        kal_wap_trace(MOD_ENG, TRACE_INFO,"[PAS6327] PAS6327_fix_framerate = %d...",Fps);
    #endif

    #if 1
    PAS6327Sensor.LineLength = PAS6327Sensor.ActiveHsize + PAS6327Sensor.DummyPixels+2;
	PAS6327Sensor.FrameHeight = ((PAS6327Sensor.PvPclk>>1)*10/(PAS6327Sensor.LineLength * Fps)) - 1;

    if(PAS6327Sensor.FrameHeight >= 0x7FF)      
     {
        PAS6327Sensor.DummyPixels = 400;
		PAS6327Sensor.LineLength = PAS6327Sensor.ActiveHsize + PAS6327Sensor.DummyPixels+2;
	    PAS6327Sensor.FrameHeight = ((PAS6327Sensor.PvPclk>>1)*10/(PAS6327Sensor.LineLength * Fps)) - 1;     
	    if(PAS6327Sensor.FrameHeight >= 0x7FF)      
       {
        PAS6327Sensor.DummyPixels = 1000;
		PAS6327Sensor.LineLength = PAS6327Sensor.ActiveHsize + PAS6327Sensor.DummyPixels+2;
	    PAS6327Sensor.FrameHeight = ((PAS6327Sensor.PvPclk>>1)*10/(PAS6327Sensor.LineLength * Fps)) - 1; 
	   }
     } 

    if(PAS6327Sensor.FrameHeight < PAS6327Sensor.ActiveVsize)      
     {
       PAS6327Sensor.FrameHeight = PAS6327Sensor.ActiveVsize;
     }
     

    PAS6327Sensor.DummyLines = PAS6327Sensor.FrameHeight - PAS6327Sensor.ActiveVsize;

    CamWriteCmosSensor(0xef,0x01);
	CamWriteCmosSensor(0x04,PAS6327Sensor.FrameHeight&0x00FF);//Cmd_Lpf
	CamWriteCmosSensor(0x05,(PAS6327Sensor.FrameHeight&0xFF00)>>8);
	CamWriteCmosSensor(0x11,0x01);
	
    PAS6327SetDummy(PAS6327Sensor.DummyPixels,PAS6327Sensor.DummyLines);
    
    #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
}



/*************************************************************************
* FUNCTION
*    PAS6327NightMode
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
static void PAS6327NightMode(kal_bool Enable)
{    
  kal_uint8 Index = 0;
 
  #ifdef PAS6327_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "PAS6327 NightMode %d",Enable);
  #endif

  if (PAS6327Sensor.VideoMode == KAL_FALSE)// camera mode
  {
      #ifdef PAS6327_DEBUG
      kal_wap_trace(MOD_ENG,TRACE_INFO, "camera mode");
      #endif
      
      if(Enable)  //camera night mode
      {
        Index = 1;
      }
      else  //camera auto mode
      {
		Index = 0;
      }          
  }
  else //video mode
  {
      #ifdef PAS6327_DEBUG
      kal_wap_trace(MOD_ENG,TRACE_INFO, "video mode");
      #endif
      
      if(Enable)  //video night mode
      {
		Index = 3;
      }
      else  //video auto mode
      {
		Index = 2;
      }    
	  
  }

    CamWriteCmosSensor(0xef,0x00);
	CamWriteCmosSensor(0x6C,PAS6327AEMode[Index][0]);//R_AE_maxStage[4:0],  decide min fps, R_lpf_min decide max fps or min fps
	CamWriteCmosSensor(0x6D,PAS6327AEMode[Index][1]);//R_AG_stage_UB
	CamWriteCmosSensor(0xed,0x01);	

	CamWriteCmosSensor(0xef,0x02);
	CamWriteCmosSensor(0x5F,PAS6327AEMode[Index][2]);//R_Saturation_LL[4:0]
	CamWriteCmosSensor(0x69,PAS6327AEMode[Index][3]);//R_Brightness_LL[7:0]
	CamWriteCmosSensor(0x00,0x01);

   // add for trigger AE at first time 2010/06/22
    CamWriteCmosSensor(0xef,0x01);
    CamWriteCmosSensor(0x11,0x01);  
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
static MM_ERROR_CODE_ENUM PAS6327SceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    PAS6327NightMode(Enable);
  }
  return MM_ERROR_NONE;
}

static kal_uint16 PAS6327GetSensorID(void)
{
	CamWriteCmosSensor(0xef,0x00);
	return ((CamReadCmosSensor(0x00) << 8)| CamReadCmosSensor(0x01));
}

static void SetPclockFrequency(kal_uint32 Frequency)
{

	CamWriteCmosSensor(0xef,0x00);
	CamWriteCmosSensor(0x67,(Frequency>>11)&0x00ff);
	CamWriteCmosSensor(0x68,((Frequency>>11)&0xff00)>>8);
	CamWriteCmosSensor(0xed,0x01);
}


/*************************************************************************
* FUNCTION
*    PAS6327PowerOn
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
static kal_uint16 PAS6327PowerOn(void)
{
  kal_uint16 SensorId;
  /* PowerOn the sensor */
  CisModulePowerOn(PAS6327Sensor.SensorIdx, KAL_TRUE);
  CameraSccbOpen(CAMERA_SCCB_SENSOR, PAS6327_SLAVE_ADDR, CAMERA_SCCB_8BIT, CAMERA_SCCB_8BIT, 300);
  CameraSccbDisWR(CAMERA_SCCB_SENSOR);  //must add to disable write_and_read in SCCB read

  kal_sleep_task(1);  /* delay for power stable */

    /* set sensors chip enable pin to low to activate PAS6327 */
  CamPdnPinCtrl(PAS6327Sensor.SensorIdx, 0);   //need to check power on sequency 
   kal_sleep_task(1);
   
  /* Reset the sensor */
  CamRstPinCtrl(PAS6327Sensor.SensorIdx, 1);
  kal_sleep_task(1);
  CamRstPinCtrl(PAS6327Sensor.SensorIdx, 0);
  kal_sleep_task(4);
  CamRstPinCtrl(PAS6327Sensor.SensorIdx, 1);
  kal_sleep_task(2);


  /* Read Sensor ID  */
  SensorId = PAS6327GetSensorID();
  
#ifdef PAS6327_DEBUG
  kal_wap_trace(MOD_ENG, TRACE_INFO, "PAS6327 Sensor ID: %x ",SensorId);
#endif
  return SensorId;
}

static void PAS6327I2CwriteAEOFF(void)
{
        // turn off I2C write AE parameter
       CamWriteCmosSensor(0xef,0x00);
       CamWriteCmosSensor(0x7f,0x00);
       CamWriteCmosSensor(0x80,0x00);
       CamWriteCmosSensor(0xed,0x01);

}

static void PAS6327I2CwriteAEON(void)
{
         // turn on I2C write AE parameter
       CamWriteCmosSensor(0xef,0x00);
       CamWriteCmosSensor(0x7f,0xff);
       CamWriteCmosSensor(0x80,0xfe);
       CamWriteCmosSensor(0xed,0x01);
}

static void PAS6327SkipFrame(kal_uint8 SkipFrameNumber)
{
	//Skip one frame for image stable 
	kal_uint8 FrameCnt1 = 0;
	kal_uint8 FrameCnt2 = 0;
	kal_uint8 SkipFrameCnt = 0;
	kal_uint32 i = 0;
	kal_uint32 j = 0;
	
#ifdef PAS6327_DEBUG
	kal_prompt_trace(MOD_ENG,"PAS6327SkipFrame");
#endif	

	SkipFrameCnt = SkipFrameNumber;

	CamWriteCmosSensor(0xef,0x00);

	for(j=0;j<(SkipFrameCnt/3);j++)
	{
		FrameCnt1 =  (CamReadCmosSensor(0xb9)&0x70)>>4;

		for(i=0;i<0xffffffff;i++)
		{
			FrameCnt2 = (CamReadCmosSensor(0xb9)&0x70)>>4;

			if((FrameCnt1-FrameCnt2>=3)||(FrameCnt2-FrameCnt1>=3))
				break;
		};
	}

	SkipFrameCnt -= (j*3);

	if(SkipFrameCnt == 0)
		return;

	FrameCnt1 = (CamReadCmosSensor(0xb9)&0x70)>>4;
	
	for(i=0;i<0xffffffff;i++)
	{
		FrameCnt2 = (CamReadCmosSensor(0xb9)&0x70)>>4;
	
		if((FrameCnt1-FrameCnt2>=SkipFrameCnt)||(FrameCnt2-FrameCnt1>=SkipFrameCnt))
			break;
	};	
}


/*************************************************************************
* FUNCTION
*    PAS6327Preview
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
static void PAS6327Preview(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint16 StartX = 0, StartY = 4,GrabWidth = PAS6327_IMAGE_SENSOR_VGA_WIDTH, GrabHeight = PAS6327_IMAGE_SENSOR_VGA_HEIGHT;
  
#ifdef PAS6327_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "PAS6327 Preview");
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
  PAS6327Sensor.PvMode = KAL_TRUE;
  PAS6327Sensor.WebcamMode = KAL_FALSE;
  PAS6327Sensor.VideoMode = KAL_FALSE;
  PAS6327Sensor.Banding = In->BandingFreq;
  PAS6327Sensor.NightMode = In->NightMode;
  PAS6327Sensor.mirror = In->ImageMirror;
  
  	PAS6327AeEnable(KAL_FALSE);
	PAS6327AwbEnable(KAL_TRUE); 
  
  switch (Id)
  {
  case CAL_SCENARIO_VIDEO:    
    PAS6327Sensor.VideoMode = KAL_TRUE;
    PAS6327Sensor.Fps = In->MaxVideoFrameRate * PAS6327_FRAME_RATE_UNIT / 10;
    PAS6327Sensor.DummyPixels = 135;
    break;
  case CAL_SCENARIO_CAMERA_PREVIEW:
    PAS6327Sensor.Fps = PAS6327_FRAME_RATE_UNIT * 30;//PAS6327_FRAME_RATE_UNIT * (PAS6327Sensor.NightMode ? 5 : 10);
    PAS6327Sensor.DummyPixels = 135;
    break;
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE:
    PAS6327Sensor.WebcamMode = KAL_TRUE;
    PAS6327Sensor.Fps = PAS6327_FRAME_RATE_UNIT * 30;//PAS6327_FRAME_RATE_UNIT * (PAS6327Sensor.NightMode ? 5 : 10);
    PAS6327Sensor.DummyPixels = 250;
    break;
  default:
    break;
  }

 
	PAS6327SetMirrorFlip(PAS6327Sensor.mirror);

	PAS6327CalFrameRate(PAS6327Sensor.Fps);

	PAS6327NightMode(PAS6327Sensor.NightMode);

	PAS6327SetParamBanding(PAS6327Sensor.Banding);

	PAS6327AeEnable(KAL_TRUE);
	PAS6327I2CwriteAEON();

	PAS6327SkipFrame(2);

  Out->GrabStartX = StartX;
  Out->GrabStartY = StartY;
  Out->ExposureWindowWidth = PAS6327_IMAGE_SENSOR_VGA_WIDTH; 
  Out->ExposureWindowHeight = PAS6327_IMAGE_SENSOR_VGA_HEIGHT - 4;
  #endif
}

/*************************************************************************
* FUNCTION
*    PAS6327Capture
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
static void PAS6327Capture(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint8 StartX = 0, StartY = 4;

#ifdef PAS6327_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "PAS6327 Capture");
#endif

  PAS6327Sensor.PvMode = KAL_FALSE;

  PAS6327AeEnable(KAL_FALSE); 
  PAS6327AwbEnable(KAL_FALSE);
  PAS6327I2CwriteAEOFF(); 

  Out->GrabStartX = StartX;
  Out->GrabStartY = StartY;
  Out->ExposureWindowWidth = PAS6327_IMAGE_SENSOR_VGA_WIDTH; 
  Out->ExposureWindowHeight = PAS6327_IMAGE_SENSOR_VGA_HEIGHT - 4;
}

/*************************************************************************
* FUNCTION
*    PAS6327SensorOpen
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
static MM_ERROR_CODE_ENUM PAS6327SensorOpen(void)
{
  if (PAS6327_SENSOR_ID != PAS6327PowerOn())
  {
    return MM_ERROR_SENSOR_READ_ID_FAIL;
  }

    /*remove to init setting*/ 
  PAS6327Sensor.PvPclk = 26000000; 
  SetPclockFrequency(PAS6327Sensor.PvPclk); //must be mclk_26M_pclk_26M or mclk_24M_pclk_24M
  kal_sleep_task(20);
  
  PAS6327InitialSetting();
  PAS6327Sensor.PvMode = KAL_FALSE;
  PAS6327Sensor.BypassAe = KAL_FALSE;
  PAS6327Sensor.BypassAwb = KAL_FALSE;
  
#if 1
  PAS6327AeEnable(KAL_FALSE);
  PAS6327AwbEnable(KAL_FALSE);

  CamWriteCmosSensor(0xef,0x01);
  PAS6327Sensor.ActiveHsize = ((CamReadCmosSensor(0x1C)&0x03)<<8)|CamReadCmosSensor(0x1B);
  PAS6327Sensor.ActiveVsize = ((CamReadCmosSensor(0x1E)&0x01)<<8)|CamReadCmosSensor(0x1D);

  CamWriteCmosSensor(0xef,0x02);
  PAS6327Sensor.BrightnessValueLL = CamReadCmosSensor(0x69);
  PAS6327Sensor.BrightnessValueNL = CamReadCmosSensor(0x6A);

  
  CamWriteCmosSensor(0xef,0x00);
  CamWriteCmosSensor(0xCE,PAS6327WbMode[0][3]-15);//Cmd_Cgn_R
  CamWriteCmosSensor(0xCF,PAS6327WbMode[0][0]-15);//Cmd_Cgn_G
  CamWriteCmosSensor(0xD0,PAS6327WbMode[0][1]-15);//Cmd_Cgn_B
  CamWriteCmosSensor(0xed,0x01);

  
 #endif
 
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    PAS6327SensorFeatureCtrl
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
static MM_ERROR_CODE_ENUM PAS6327SensorFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
  
#ifdef PAS6327_DEBUG
  kal_wap_trace(MOD_ENG, TRACE_INFO, "PAS6327 FeatureCtrl Id:%x",Id);
#endif
  if (Id >= CAL_FEATURE_WEBCAM_BEGIN && Id <= CAL_FEATURE_WEBCAM_END)
  {
    return PAS6327WebcamFeatureCtrl(Id, In, Out, OutLen, RealOutLen);
  }
  switch (Id)
  {
   /* CAL Query and set series */
  case CAL_FEATURE_CAMERA_BRIGHTNESS:
  case CAL_FEATURE_CAMERA_EV_VALUE:
    ErrCode = PAS6327Ev(In, Out);
    break;
  case CAL_FEATURE_CAMERA_CONTRAST:
   // ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    ErrCode = PAS6327Contrast(In, Out);
    break;
  case CAL_FEATURE_CAMERA_HUE:
  case CAL_FEATURE_CAMERA_SATURATION:
  case CAL_FEATURE_CAMERA_SHARPNESS:
  case CAL_FEATURE_CAMERA_GAMMA:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  case CAL_FEATURE_CAMERA_WB:
    ErrCode = PAS6327Wb(In, Out);
    break;
  case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
    ErrCode = PAS6327Effect(In, Out);
    break;
  case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
    ErrCode = PAS6327StillCaptureSize(In, Out);
    break;
  case CAL_FEATURE_CAMERA_BANDING_FREQ: /* Only query here, set function move to preview */
    ErrCode = PAS6327Banding(In, Out);
    break;
  case CAL_FEATURE_CAMERA_SCENE_MODE:
    ErrCode = PAS6327SceneMode(KAL_TRUE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
    ErrCode = PAS6327SceneMode(KAL_FALSE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_FLASH_MODE:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;

  /* Get Info series */
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
    PAS6327GetSensorInfo(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = PAS6327DetectSensorId();
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = PAS6327Sensor.Fps * 10 / PAS6327_FRAME_RATE_UNIT;
    break;
  case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
    PAS6327InitOperationPara(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
    CamGetHWInfo(PAS6327Sensor.SensorIdx, Out);
    break;
    
  /* Set Para series */
  case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:  //need to check power down flow
    CamPdnPinCtrl(PAS6327Sensor.SensorIdx, 1);   
    CamRstPinCtrl(PAS6327Sensor.SensorIdx, 0);
    break;
  case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
    PAS6327Sensor.NvramData = &(((nvram_camera_para_struct *)In)->SENSOR);
    break;
  case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
    PAS6327Sensor.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
    break;
  case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
    break;
  case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
    PAS6327Sensor.BypassAe = *(kal_bool *)In;
    PAS6327AeEnable(PAS6327Sensor.BypassAe ? KAL_FALSE : KAL_TRUE);
    break;
  case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
	PAS6327Sensor.BypassAwb = *(kal_bool *)In;
	PAS6327AwbEnable(PAS6327Sensor.BypassAwb ? KAL_FALSE : KAL_TRUE);
    break;
  default:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  }
  return ErrCode;
}

/*************************************************************************
* FUNCTION
*    PAS6327SensorCtrl
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
static MM_ERROR_CODE_ENUM PAS6327SensorCtrl(CAL_SCENARIO_ENUM Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  switch (Id)
  {
	  case CAL_SCENARIO_CAMERA_PREVIEW:
	  case CAL_SCENARIO_VIDEO:
	  case CAL_SCENARIO_WEBCAM_PREVIEW:
	  case CAL_SCENARIO_WEBCAM_CAPTURE:
	    PAS6327Preview(Id, In, Out);
	    break;
	  case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
	    PAS6327Capture(Id, In, Out);
	    break;
	  default:
	    break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    PAS6327SensorClose
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
static MM_ERROR_CODE_ENUM PAS6327SensorClose(void)
{  //need to check power down flow

  CamPdnPinCtrl(PAS6327Sensor.SensorIdx, 1);
  CamRstPinCtrl(PAS6327Sensor.SensorIdx, 0);
  CisModulePowerOn(PAS6327Sensor.SensorIdx, KAL_FALSE);
  CameraSccbClose(CAMERA_SCCB_SENSOR);
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    PAS6327SensorFunc
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
MM_ERROR_CODE_ENUM PAS6327SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncPAS6327 =
  {
    PAS6327SensorOpen,
    PAS6327SensorFeatureCtrl,
    PAS6327SensorCtrl,
    PAS6327SensorClose,
  };
  
  *pfSensorFunc = &ImageSensorFuncPAS6327;
  
  return MM_ERROR_NONE;
}

