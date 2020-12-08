/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *   image_sensor_OV2655.c
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
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "cal_comm_def.h"
#include "isp_if.h"
#include "isp_comm_if.h"
#include "isp_flashlight_if.h"
#include "aaa_ae.h"
#include "camera_sccb.h"
#include "image_sensor.h"
#include "image_sensor_OV2655.h"


IMAGE_SENSOR_INDEX_ENUM OV2655SensorIdx;
CAL_CAMERA_SOURCE_ENUM CameraSource;
sensor_data_struct *pNvramSensorData;
extern camcorder_info_struct OV2655_dsc_support_info;


#define OV2655_PURE_RAW
/* Global Valuable For CCT */
SensorInfo OV2655_g_CCT_MainSensor = OV2655_CCT_MainSensor;
kal_uint8 OV2655_g_CCT_FirstGrabColor = OV2655_CCT_FirstGrabColor;

/* MAX/MIN Explosure Lines Used By AE Algorithm */
kal_uint32 OV2655_MAX_EXPOSURE_LINES=1000;
kal_uint8  OV2655_MIN_EXPOSURE_LINES=2;

struct OV2655_sensor_struct OV2655_Sensor_Driver;

//For Debug
#define OUTPUT_DEBUG_INFO
#define  __DEBUG_TRACE__

kal_bool aeIsEnable(void)
{
 return KAL_TRUE;
}

void OV2655_write_shutter(kal_uint16 shutter)
{
    kal_uint16 max_shutter = 0;
#ifdef OUTPUT_DEBUG_INFO
  kal_print_string_trace(MOD_ENG, TRACE_WARNING, "shutter=%x", shutter);
#endif
  if(OV2655_Sensor_Driver.Camco_mode == OV2655_CAM_CAPTURE_UXGA){  
    max_shutter = OV2655_FULL_PERIOD_LINE_NUMS + OV2655_Sensor_Driver.Dummy_Lines;
  }else{
    max_shutter = OV2655_PV_PERIOD_LINE_NUMS + OV2655_Sensor_Driver.Dummy_Lines;
  }
  
    if (shutter > max_shutter){
        OV2655_Sensor_Driver.extra_shutter = shutter - max_shutter;
        shutter = max_shutter;
    }else{
        OV2655_Sensor_Driver.extra_shutter = 0;
    }

    CamWriteCmosSensor(0x3002, (shutter >> 8) & 0xff );
    CamWriteCmosSensor(0x3003, shutter & 0x00ff );

  if ((OV2655_Sensor_Driver.extra_shutter_backup == 0 && OV2655_Sensor_Driver.extra_shutter > 0)||
     (OV2655_Sensor_Driver.Camco_mode == OV2655_WEBCAM_CAPTURE)||
     (OV2655_Sensor_Driver.Camco_mode == OV2655_CAM_CAPTURE_SVGA)||
    (OV2655_Sensor_Driver.Camco_mode == OV2655_CAM_CAPTURE_UXGA)||
       (aeIsEnable() == KAL_FALSE))
  {
        CamWriteCmosSensor(0x302d, (OV2655_Sensor_Driver.extra_shutter >> 8) & 0xff);
        CamWriteCmosSensor(0x302e, OV2655_Sensor_Driver.extra_shutter & 0xff);
  }
  
  OV2655_Sensor_Driver.extra_shutter_backup = OV2655_Sensor_Driver.extra_shutter;
}  /* OV2655_write_shutter */

static kal_uint16 Reg2Gain(const kal_uint8 iReg)
{
    kal_uint8 iI;
    kal_uint16 iGain = BASEGAIN;    // 1x-gain base

    // Range: 1x to 32x
    // Gain = (GAIN[7] + 1) * (GAIN[6] + 1) * (GAIN[5] + 1) * (GAIN[4] + 1) * (1 + GAIN[3:0] / 16)
    for (iI = 7; iI >= 4; iI--) {
        iGain *= (((iReg >> iI) & 0x01) + 1);
    }

    return iGain +  iGain * (iReg & 0x0F) / 16;

}

static kal_uint8 OV2655_Gain2Reg(const kal_uint16 iGain)
{
    kal_uint8 iReg = 0x00;

    //Transfer Gain to Register Value
     if (iGain < 2 * BASEGAIN) {
         // Gain = 1 + GAIN[3:0](0x00) / 16
         iReg = 16 * (iGain - BASEGAIN) / BASEGAIN;
     }else if (iGain < 4 * BASEGAIN) {
         // Gain = 2 * (1 + GAIN[3:0](0x00) / 16)
         iReg |= 0x10;
         iReg |= 8 * (iGain - 2 * BASEGAIN) / BASEGAIN;
     }else if (iGain < 8 * BASEGAIN) {
         // Gain = 4 * (1 + GAIN[3:0](0x00) / 16)
         iReg |= 0x30;
         iReg |= 4 * (iGain - 4 * BASEGAIN) / BASEGAIN;
     }else if (iGain < 16 * BASEGAIN) {
         // Gain = 8 * (1 + GAIN[3:0](0x00) / 16)
         iReg |= 0x70;
         iReg |= 2 * (iGain - 8 * BASEGAIN) / BASEGAIN;
     }else if (iGain < 32 * BASEGAIN) {
         // Gain = 16 * (1 + GAIN[3:0](0x00) / 16)
         iReg |= 0xF0;
         iReg |= (iGain - 16 * BASEGAIN) / BASEGAIN;
     }else {
         ASSERT(0);
     }    
     
     return iReg;

}


void OV2655_set_dummy(kal_uint16 pixels, kal_uint16 lines)
{
    kal_uint16 PixelsOneline, LinesOneFrame;
 
#ifdef OUTPUT_DEBUG_INFO
  kal_print_string_trace(MOD_ENG, TRACE_WARNING, "pixle= %x, line=%x", pixels,lines);
#endif
  if(OV2655_Sensor_Driver.Camco_mode == OV2655_CAM_CAPTURE_UXGA){ 
    PixelsOneline = OV2655_FULL_PERIOD_PIXEL_NUMS + pixels;
    LinesOneFrame = lines + OV2655_FULL_PERIOD_LINE_NUMS;
  }else{
    PixelsOneline = (OV2655_PV_PERIOD_PIXEL_NUMS+pixels) * 2; // time 2 for 800 * 600, not required for UXGA
    LinesOneFrame = lines + OV2655_PV_PERIOD_LINE_NUMS ;  // 620 for svga, 1240 for uxga
  }

     CamWriteCmosSensor(0x3028, (PixelsOneline - 1) >> 8);
     CamWriteCmosSensor(0x3029, (PixelsOneline - 1) & 0x00FF);
     CamWriteCmosSensor(0x302A, LinesOneFrame >> 8);
     CamWriteCmosSensor(0x302B, LinesOneFrame & 0x00FF);
}   /*  OV2655_Set_Dummy    */


void set_OV2655_SVGA()
{
    //CamWriteCmosSensor(0x3012,0x80);
    CamWriteCmosSensor(0x308c,0x80);
    CamWriteCmosSensor(0x308d,0x0e);
    CamWriteCmosSensor(0x360b,0x00);
    CamWriteCmosSensor(0x30b0,0xff);
    CamWriteCmosSensor(0x30b1,0xff);
  #if defined(DRV_ISP_MT6236_HW_SUPPORT)
  CamWriteCmosSensor(0x30b2,0x2d);//2c
  #else
  CamWriteCmosSensor(0x30b2,0x2c);//2c
  #endif
    //CamWriteCmosSensor(0x300e,0x34);
    //0x30---20fps, 0x34---15fps
//    CamWriteCmosSensor(0x300e,0x30); 
#if (defined(DRV_ISP_6238_SERIES))
    CamWriteCmosSensor(0x300e,0x28); 
#else
    CamWriteCmosSensor(0x300e,0x30);
#endif  

    CamWriteCmosSensor(0x300f,0xa6);
    CamWriteCmosSensor(0x3010,0x81);
    CamWriteCmosSensor(0x3082,0x01);
    CamWriteCmosSensor(0x30f4,0x01);
    CamWriteCmosSensor(0x3090,0x33);
    CamWriteCmosSensor(0x3091,0xc0);
    CamWriteCmosSensor(0x30ac,0x42);
    CamWriteCmosSensor(0x30d1,0x08);
    CamWriteCmosSensor(0x30a8,0x56);
    CamWriteCmosSensor(0x3015,0x04);
    CamWriteCmosSensor(0x3093,0x00);
    CamWriteCmosSensor(0x307e,0xe5);
    CamWriteCmosSensor(0x3079,0x00);
    CamWriteCmosSensor(0x30aa,0x42);
    CamWriteCmosSensor(0x3017,0x40);
    CamWriteCmosSensor(0x30f3,0x82);
    CamWriteCmosSensor(0x306a,0x0c);
    CamWriteCmosSensor(0x306d,0x00);
    CamWriteCmosSensor(0x336a,0x3c);
    CamWriteCmosSensor(0x3076,0x6a);
    CamWriteCmosSensor(0x30d9,0x8c);
    CamWriteCmosSensor(0x3016,0x82);
    CamWriteCmosSensor(0x3601,0x30);
    CamWriteCmosSensor(0x304e,0x88);
    CamWriteCmosSensor(0x30f1,0x82);
    CamWriteCmosSensor(0x3350,0x28);
    CamWriteCmosSensor(0x3351,0x21);
    CamWriteCmosSensor(0x3352,0x80);
    CamWriteCmosSensor(0x3353,0x18);
    CamWriteCmosSensor(0x3354,0x00);
    CamWriteCmosSensor(0x3355,0x84);
    CamWriteCmosSensor(0x3356,0x28);
    CamWriteCmosSensor(0x3357,0x21);
    CamWriteCmosSensor(0x3358,0x80);
    CamWriteCmosSensor(0x3359,0x18);
    CamWriteCmosSensor(0x335a,0x00);
    CamWriteCmosSensor(0x335b,0x84);
    CamWriteCmosSensor(0x335c,0x28);
    CamWriteCmosSensor(0x335d,0x21);
    CamWriteCmosSensor(0x335e,0x80);
    CamWriteCmosSensor(0x335f,0x18);
    CamWriteCmosSensor(0x3360,0x00);
    CamWriteCmosSensor(0x3361,0x84);
    CamWriteCmosSensor(0x3363,0x01);
    CamWriteCmosSensor(0x3364,0x03);
    CamWriteCmosSensor(0x3365,0x02);
    CamWriteCmosSensor(0x3366,0x00);
    CamWriteCmosSensor(0x3380,0x20);
    CamWriteCmosSensor(0x3381,0x64);
    CamWriteCmosSensor(0x3382,0x08);
    CamWriteCmosSensor(0x3383,0x30);
    CamWriteCmosSensor(0x3384,0x90);
    CamWriteCmosSensor(0x3385,0xc0);
    CamWriteCmosSensor(0x3386,0xa0);
    CamWriteCmosSensor(0x3387,0x98);
    CamWriteCmosSensor(0x3388,0x08);
    CamWriteCmosSensor(0x3389,0x98);
    CamWriteCmosSensor(0x338a,0x01);
    CamWriteCmosSensor(0x3340,0x0e);
    CamWriteCmosSensor(0x3341,0x1a);
    CamWriteCmosSensor(0x3342,0x31);
    CamWriteCmosSensor(0x3343,0x46);
    CamWriteCmosSensor(0x3344,0x5a);
    CamWriteCmosSensor(0x3345,0x69);
    CamWriteCmosSensor(0x3346,0x75);
    CamWriteCmosSensor(0x3347,0x7e);
    CamWriteCmosSensor(0x3348,0x88);
    CamWriteCmosSensor(0x3349,0x96);
    CamWriteCmosSensor(0x334a,0xa3);
    CamWriteCmosSensor(0x334b,0xaf);
    CamWriteCmosSensor(0x334c,0xc4);
    CamWriteCmosSensor(0x334d,0xd7);
    CamWriteCmosSensor(0x334e,0xe8);
    CamWriteCmosSensor(0x334f,0x20);
    CamWriteCmosSensor(0x3301,0xbf);
    
//BLC isuue    
#if (defined(DRV_ISP_6238_SERIES))
    CamWriteCmosSensor(0x3069,0x84);//04->84
    CamWriteCmosSensor(0x306c,0x10);//00->10 soso modify 2009-2-25
    CamWriteCmosSensor(0x309c,0x00);//02->00
    CamWriteCmosSensor(0x30a2,0x41);//43->41
    CamWriteCmosSensor(0x307c,0x10);//00->10
#else
    CamWriteCmosSensor(0x3069,0x04);
    CamWriteCmosSensor(0x306c,0x00);
    CamWriteCmosSensor(0x309c,0x02);
    CamWriteCmosSensor(0x30a2,0x43);
    CamWriteCmosSensor(0x307c,0x00);
#endif  

    CamWriteCmosSensor(0x30af,0x10);
    CamWriteCmosSensor(0x30af,0x10);
    CamWriteCmosSensor(0x304a,0x00);
    CamWriteCmosSensor(0x304f,0x00);
    CamWriteCmosSensor(0x304d,0x22);
    CamWriteCmosSensor(0x304f,0xa0);
    CamWriteCmosSensor(0x3095,0x00);
    CamWriteCmosSensor(0x3096,0xff);
    CamWriteCmosSensor(0x3097,0x00);
    CamWriteCmosSensor(0x3012,0x10);
    CamWriteCmosSensor(0x306f,0x14);
    CamWriteCmosSensor(0x3319,0x28);
    CamWriteCmosSensor(0x331d,0x48);
    CamWriteCmosSensor(0x3303,0x04);
    CamWriteCmosSensor(0x3023,0x04);
    CamWriteCmosSensor(0x3024,0x06); // Array Horizantal 
    CamWriteCmosSensor(0x3025,0x58);
    CamWriteCmosSensor(0x3026,0x02); // Aarry Vertical 
    CamWriteCmosSensor(0x3027,0x5e);
    CamWriteCmosSensor(0x302a,OV2655_PV_PERIOD_LINE_NUMS >> 8); // Vertical total 768
    CamWriteCmosSensor(0x302b,OV2655_PV_PERIOD_LINE_NUMS & 0x00ff);
  
    CamWriteCmosSensor(0x3088,0x03); // Output 808 pixels, 
    CamWriteCmosSensor(0x3089,0x28);
    CamWriteCmosSensor(0x308a,0x02); // Output 608 lines
    CamWriteCmosSensor(0x308b,0x60);


//Noise Issue
#ifdef OV2655_PURE_RAW
  CamWriteCmosSensor(0x3300,0x82);   //8bits pure raw. 2009-04-10
#else
  CamWriteCmosSensor(0x3300,0x83);   //8bits. 2008-08-26

  //Denoise function, only aviable in 8bits. 2008-08-26
/*
//Auto Denoise & Sharpness 
    CamWriteCmosSensor(0x3306,0x00); 
    CamWriteCmosSensor(0x3370,0xd0);//a0->d0 
    CamWriteCmosSensor(0x3373,0x40);//00->10
    CamWriteCmosSensor(0x3374,0x10); 
    CamWriteCmosSensor(0x3375,0x10); 

    //Sharpness function
    CamWriteCmosSensor(0x3376,0x04); 
    CamWriteCmosSensor(0x3377,0x00);
    CamWriteCmosSensor(0x3378,0x04);
    CamWriteCmosSensor(0x3379,0x80); 
*/  
//Manual Denoise & Sharpness 
    CamWriteCmosSensor(0x3306,0x0c); 
    CamWriteCmosSensor(0x3370,0xff);//a0->d0 
    CamWriteCmosSensor(0x3373,0x40);//00->10
    CamWriteCmosSensor(0x3374,0x10); 
    CamWriteCmosSensor(0x3375,0x10); 

    //Sharpness function
    CamWriteCmosSensor(0x3371,0x00);
    CamWriteCmosSensor(0x3376,0x04); 
    CamWriteCmosSensor(0x3377,0x00);
    CamWriteCmosSensor(0x3378,0x04);
    CamWriteCmosSensor(0x3379,0x80);     
#endif

  
    CamWriteCmosSensor(0x3100,0x04);
    CamWriteCmosSensor(0x3400,0x90);
    CamWriteCmosSensor(0x3606,0x20); // Hsync Mode 0x30
    CamWriteCmosSensor(0x3380,0x80);
    CamWriteCmosSensor(0x3381,0x00);
    CamWriteCmosSensor(0x3382,0x00);
    CamWriteCmosSensor(0x3383,0x00);
    CamWriteCmosSensor(0x3384,0x80);
    CamWriteCmosSensor(0x3385,0x00);
    CamWriteCmosSensor(0x3386,0x00);
    CamWriteCmosSensor(0x3387,0x00);
    CamWriteCmosSensor(0x3388,0x80);
    CamWriteCmosSensor(0x3389,0x00);
    CamWriteCmosSensor(0x338a,0x04);
    CamWriteCmosSensor(0x3301,0xbf);
    CamWriteCmosSensor(0x30f3,0x83);
    CamWriteCmosSensor(0x304e,0x4b);

    CamWriteCmosSensor(0x3011,0x01);//01 -15fps, 00-30fps
    
    CamWriteCmosSensor(0x3086,0x0f);
    CamWriteCmosSensor(0x3086,0x00);
    CamWriteCmosSensor(0x3601,0x30);
    CamWriteCmosSensor(0x3013,0xE0);//Disable Sensor AEC/AGC  Reg0x3013 bit[0],bit[2]
    CamWriteCmosSensor(0x3000,0x1B);
    CamWriteCmosSensor(0x3001,0x0B);
    CamWriteCmosSensor(0x3002,0x02);
    CamWriteCmosSensor(0x3003,0x65);
    CamWriteCmosSensor(0x30a3,0x80);

#if defined(DRV_ISP_MT6236_HW_SUPPORT)
      CamWriteCmosSensor(0x30aa,0x82);// xiaohui modified fo red pixel in the sun
      CamWriteCmosSensor(0x30a3,0x91);
      CamWriteCmosSensor(0x30a1,0x41);
      
  #endif
}

void set_OV2655_UXGA()
{
#if (defined(DRV_ISP_6238_SERIES))
//    CamWriteCmosSensor(0x300e,0x34);
#else
    CamWriteCmosSensor(0x300e,0x38); 
#endif
      CamWriteCmosSensor(0x3010,0x82);  
      CamWriteCmosSensor(0x3011,0x01);  // under 1600x1200,decrease the pclk

      CamWriteCmosSensor(0x3012,0x00);
      CamWriteCmosSensor(0x3013,0xf0);
      CamWriteCmosSensor(0x3014,0x44);
      CamWriteCmosSensor(0x301b,0x73);

      CamWriteCmosSensor(0x3023,0x0a);
      CamWriteCmosSensor(0x3026,0x04);
      CamWriteCmosSensor(0x3027,0xbc);
      CamWriteCmosSensor(0x302a,OV2655_FULL_PERIOD_LINE_NUMS >> 8);    // Vertical 
      CamWriteCmosSensor(0x302b,OV2655_FULL_PERIOD_LINE_NUMS & 0x00ff);
        
      CamWriteCmosSensor(0x3069,0x84);
      CamWriteCmosSensor(0x306c,0x10);
      CamWriteCmosSensor(0x306f,0x54);

      CamWriteCmosSensor(0x3070,0xba);
      CamWriteCmosSensor(0x3072,0x9a);
        
      CamWriteCmosSensor(0x3088,0x06);   //Output 1600 pixels
      CamWriteCmosSensor(0x3089,0x40);
      CamWriteCmosSensor(0x308a,0x04);  //Output 1200 lines
      CamWriteCmosSensor(0x308b,0xb0);
      CamWriteCmosSensor(0x308e,0x4c);
        
      CamWriteCmosSensor(0x3095,0x07);
      CamWriteCmosSensor(0x3096,0x16);
      CamWriteCmosSensor(0x3097,0x1a);
      CamWriteCmosSensor(0x309c,0x00 );
        
      CamWriteCmosSensor(0x30a2,0x41);//45->41
      CamWriteCmosSensor(0x30a3,0x11);
      CamWriteCmosSensor(0x30af,0x00);
      CamWriteCmosSensor(0x30c1,0xb9);
           CamWriteCmosSensor(0x30dc,0x00);
      CamWriteCmosSensor(0x30de,0x81);
      CamWriteCmosSensor(0x30df,0x50);
      CamWriteCmosSensor(0x30f3,0x82);
    
      CamWriteCmosSensor(0x3303,0x00);
      CamWriteCmosSensor(0x3319,0x6c);
      CamWriteCmosSensor(0x331d,0x6c);
  #if defined(DRV_ISP_MT6236_HW_SUPPORT)
  CamWriteCmosSensor(0x30aa,0x82);// xiaohui modified fo red pixel in the sun
  CamWriteCmosSensor(0x30a3,0x91);
  CamWriteCmosSensor(0x30a1,0x41);
  
  #endif
}


/*************************************************************************
* FUNCTION
*   OV2655_HVMirror
*
* DESCRIPTION
*   This function config the mirror and flip of the image sensor.
*
* PARAMETERS  
*    image_mirror :  mirror parameter   
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void OV2655_HVMirror(kal_uint8 image_mirror)
{
/********************************************************
Mirror: Reg0x307c bit[1] & Reg0x3090 bit[3]
Flip :    Reg0x307c bit[0]
*********************************************************/
  switch (image_mirror) {
    case IMAGE_SENSOR_MIRROR_NORMAL:
      CamWriteCmosSensor(0x3090,0x33);     
      CamWriteCmosSensor(0x307c, 0x10);
      OV2655_Sensor_Driver.StartX = 1;
      OV2655_Sensor_Driver.StartY = 2;
          break;
    case IMAGE_SENSOR_MIRROR_H:
      CamWriteCmosSensor(0x3090,0x33);     
      CamWriteCmosSensor(0x307c, 0x11);
      OV2655_Sensor_Driver.StartX = 1;
      OV2655_Sensor_Driver.StartY = 3;
    break;
    case IMAGE_SENSOR_MIRROR_V:
      CamWriteCmosSensor(0x3090,0x3b);     
      CamWriteCmosSensor(0x307c, 0x12);  
      OV2655_Sensor_Driver.StartX = 1;
      OV2655_Sensor_Driver.StartY = 2;
    break;
    case IMAGE_SENSOR_MIRROR_HV:
      CamWriteCmosSensor(0x3090,0x3b);        
      CamWriteCmosSensor(0x307c, 0x13);
      OV2655_Sensor_Driver.StartX = 1;
      OV2655_Sensor_Driver.StartY = 3;
    break;
    }
}
void OV2655_night_mode(kal_bool enable)
{
/*********************************************
	Fix Video Function By Fix frame height				
			Auto Mode : 30fps				
			Night Mode: 15fps				
*********************************************/
#if (defined(DRV_ISP_6238_SERIES))
	if(OV2655_Sensor_Driver.Camco_mode == OV2655_VIDEO_MPEG4){
		OV2655_Sensor_Driver.FrameRate_Fix_enable = KAL_TRUE;

		if(enable){
			OV2655_Sensor_Driver.Night_Mode = KAL_TRUE;
#if defined(DRV_ISP_MT6236_HW_SUPPORT)
			if(OV2655_Sensor_Driver.Video_size==OV2655_VIDEO_SIZE_D1){
				OV2655_Sensor_Driver.fixed_frame_rate=50;
			}else if(OV2655_Sensor_Driver.Video_size==OV2655_VIDEO_SIZE_HVGA){
				OV2655_Sensor_Driver.fixed_frame_rate=75;
			}else{
				OV2655_Sensor_Driver.fixed_frame_rate=75;
			}					
#else /*6239/6268*/
			
			OV2655_Sensor_Driver.fixed_frame_rate = 150;		
#endif
	}
		else{
			OV2655_Sensor_Driver.Night_Mode = KAL_FALSE;
#if defined(DRV_ISP_MT6236_HW_SUPPORT)
			if(OV2655_Sensor_Driver.Video_size==OV2655_VIDEO_SIZE_D1){
				OV2655_Sensor_Driver.fixed_frame_rate=75;
			}else if(OV2655_Sensor_Driver.Video_size==OV2655_VIDEO_SIZE_HVGA){
				OV2655_Sensor_Driver.fixed_frame_rate=120;
			}else{
				OV2655_Sensor_Driver.fixed_frame_rate=150;
			}	

#else /*6239/6268*/
			
			OV2655_Sensor_Driver.fixed_frame_rate = 300;	
#endif
		}
	}
#ifdef __MEDIA_VT__
/* under construction !*/
/* under construction !*/
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
	else{
		OV2655_Sensor_Driver.FrameRate_Fix_enable = KAL_FALSE;
	}

	//Fix frame rate
	if(OV2655_Sensor_Driver.FrameRate_Fix_enable == KAL_TRUE)
	{
		OV2655_MAX_EXPOSURE_LINES = (kal_uint16)((((OV2655_Sensor_Driver.Preview_PClk* 1000 )/OV2655_Sensor_Driver.fixed_frame_rate)*10)/(OV2655_PV_PERIOD_PIXEL_NUMS + OV2655_Sensor_Driver.Dummy_Pixels)); 			
		if((OV2655_MAX_EXPOSURE_LINES>OV2655_PV_PERIOD_LINE_NUMS)&&(OV2655_Sensor_Driver.Dummy_Lines<(OV2655_MAX_EXPOSURE_LINES - OV2655_PV_PERIOD_LINE_NUMS))) 	
		  OV2655_Sensor_Driver.Dummy_Lines = OV2655_MAX_EXPOSURE_LINES - OV2655_PV_PERIOD_LINE_NUMS;
		
		OV2655_set_dummy(OV2655_Sensor_Driver.Dummy_Pixels,OV2655_Sensor_Driver.Dummy_Lines);	
	}
#endif
}	/* OV2655_night_mode */
/*************************************************************************
* FUNCTION
*    OV2655Preview
*
* DESCRIPTION
*    This function set to preview mode
*
* PARAMETERS
*    id, in, out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV2655Preview(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{  
  if(OV2655_Sensor_Driver.Camco_mode == OV2655_CAM_CAPTURE_UXGA)
  {
        set_OV2655_SVGA();
  }


	switch (ScenarioId)
	{
		case CAL_SCENARIO_CAMERA_PREVIEW:
		case CAL_SCENARIO_WEBCAM_PREVIEW:
		case CAL_SCENARIO_WEBCAM_CAPTURE:
			OV2655_Sensor_Driver.Camco_mode = OV2655_CAM_PREVIEW;
			OV2655_Sensor_Driver.Preview_PClk = 19500;
			OV2655_Sensor_Driver.Dummy_Pixels = 0;
			OV2655_Sensor_Driver.Dummy_Lines= 50;
			
			OV2655_Sensor_Driver.FrameRate_Fix_enable = KAL_FALSE;
			break;
		case CAL_SCENARIO_VIDEO:
			OV2655_Sensor_Driver.Camco_mode = OV2655_VIDEO_MPEG4;
			OV2655_Sensor_Driver.Preview_PClk = 19500;
			OV2655_Sensor_Driver.Dummy_Pixels = 0;
			OV2655_Sensor_Driver.Dummy_Lines= 50;

			OV2655_Sensor_Driver.FrameRate_Fix_enable = KAL_TRUE;
			OV2655_Sensor_Driver.fixed_frame_rate = pParaIn->MaxVideoFrameRate;

			
			break;
#ifdef __MEDIA_VT__
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
		default:
			OV2655_Sensor_Driver.Camco_mode = OV2655_CAM_PREVIEW;
			OV2655_Sensor_Driver.Preview_PClk = 19500;
			OV2655_Sensor_Driver.Dummy_Pixels = 0;
			OV2655_Sensor_Driver.Dummy_Lines= 50;
			
			OV2655_Sensor_Driver.FrameRate_Fix_enable = KAL_FALSE;
			break;
	}

	
	OV2655_Sensor_Driver.Preview_Pixels_In_Lines = OV2655_PV_PERIOD_PIXEL_NUMS + OV2655_Sensor_Driver.Dummy_Pixels;
	//OV2655_Sensor_Driver.Banding = In->BandingFreq;
	//OV2655_Sensor_Driver.NightMode = In->NightMode;
 
	OV2655_HVMirror(pParaIn->ImageMirror);
	OV2655_set_dummy(OV2655_Sensor_Driver.Dummy_Pixels,OV2655_Sensor_Driver.Dummy_Lines);
	OV2655_write_shutter(OV2655_Sensor_Driver.Preview_Shutter);

	//OV2655_night_mode(pParaIn->NightMode);
	if(OV2655_Sensor_Driver.FrameRate_Fix_enable == KAL_TRUE)
	{
		OV2655_MAX_EXPOSURE_LINES = (kal_uint16)((((OV2655_Sensor_Driver.Preview_PClk* 1000 )/OV2655_Sensor_Driver.fixed_frame_rate)*10)/(OV2655_PV_PERIOD_PIXEL_NUMS + OV2655_Sensor_Driver.Dummy_Pixels)); 			
		if((OV2655_MAX_EXPOSURE_LINES>OV2655_PV_PERIOD_LINE_NUMS)&&(OV2655_Sensor_Driver.Dummy_Lines<(OV2655_MAX_EXPOSURE_LINES - OV2655_PV_PERIOD_LINE_NUMS))) 	
		  OV2655_Sensor_Driver.Dummy_Lines = OV2655_MAX_EXPOSURE_LINES - OV2655_PV_PERIOD_LINE_NUMS;
		
		OV2655_set_dummy(OV2655_Sensor_Driver.Dummy_Pixels,OV2655_Sensor_Driver.Dummy_Lines);	
	}
	OV2655_Sensor_Driver.Band_Mode=pParaIn->BandingFreq;


  OV2655_Sensor_Driver.iGrabWidth = OV2655_IMAGE_SENSOR_PV_WIDTH;
  OV2655_Sensor_Driver.iGrabheight = OV2655_IMAGE_SENSOR_PV_HEIGHT;


	pParaOut->GrabStartX = OV2655_Sensor_Driver.StartX;
	pParaOut->GrabStartY = OV2655_Sensor_Driver.StartY;
	pParaOut->ExposureWindowWidth = OV2655_Sensor_Driver.iGrabWidth;
	pParaOut->ExposureWindowHeight = OV2655_Sensor_Driver.iGrabheight;
}  /* OV2655_preview */

/*************************************************************************
* FUNCTION
*    OV2655Capture
*
* DESCRIPTION
*    This function set to capture mode
*
* PARAMETERS
*    id, in, out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV2655Capture(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)

{
//  const kal_bool bMetaMode = sensor_config_data->meta_mode != CAPTURE_MODE_NORMAL;

  
  if(KAL_TRUE==pParaIn->EnableShutterTransfer)
  {
	  OV2655_Sensor_Driver.Preview_Shutter=pParaIn->CaptureShutter;
  }


  if ((pParaIn->ImageTargetWidth<=OV2655_IMAGE_SENSOR_PV_WIDTH)&&
     (pParaIn->ImageTargetHeight<=OV2655_IMAGE_SENSOR_PV_HEIGHT))     
  {  /* Less than SVGA 800x600 Mode */    

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
  #endif
  	{   
      OV2655_Sensor_Driver.Camco_mode = OV2655_CAM_CAPTURE_SVGA;

      OV2655_Sensor_Driver.Capture_PClk = 19500;

      OV2655_Sensor_Driver.Dummy_Pixels = 0;
      OV2655_Sensor_Driver.Dummy_Lines= 0;

      OV2655_Sensor_Driver.iGrabWidth = OV2655_IMAGE_SENSOR_PV_WIDTH;
      OV2655_Sensor_Driver.iGrabheight = OV2655_IMAGE_SENSOR_PV_HEIGHT;
      }
    
    OV2655_Sensor_Driver.Capture_Pixels_In_Lines = OV2655_PV_PERIOD_PIXEL_NUMS + OV2655_Sensor_Driver.Dummy_Pixels;

    //Update the new shutter
    OV2655_Sensor_Driver.Capture_Shutter = OV2655_Sensor_Driver.Preview_Shutter * (OV2655_Sensor_Driver.Capture_PClk/OV2655_Sensor_Driver.Preview_PClk);
    OV2655_Sensor_Driver.Capture_Shutter = OV2655_Sensor_Driver.Capture_Shutter * (OV2655_Sensor_Driver.Preview_Pixels_In_Lines/OV2655_Sensor_Driver.Capture_Pixels_In_Lines);
  }else{ /*UXGA*/
    //Config UXGA capture Digtal Window 1620 *1220
        set_OV2655_UXGA();
    OV2655_Sensor_Driver.Camco_mode = OV2655_CAM_CAPTURE_UXGA;
    
#ifdef CAM_OTF_CAPTURE//Capture on the fly Mode
#if defined(DRV_ISP_MT6236_HW_SUPPORT)

    if ((pParaIn->ImageTargetWidth <= 1600)&& 
      (pParaIn->ImageTargetHeight <= 1200)){//For 2M Capture
      
      OV2655_Sensor_Driver.Capture_PClk = 39000;

      if(pParaIn->ZoomFactor == 100){//Not Zoom
        OV2655_Sensor_Driver.Dummy_Pixels = 0;
        OV2655_Sensor_Driver.Dummy_Lines= 0;//1940*1240
      }else if(pParaIn->ZoomFactor <= 200){//Zoom 1x ~ 2x
        OV2655_Sensor_Driver.Dummy_Pixels = 0;
        OV2655_Sensor_Driver.Dummy_Lines= 0;//1940*1240
      }else if(pParaIn->ZoomFactor <= 300){//Zoom 2x ~ 3x
        OV2655_Sensor_Driver.Dummy_Pixels = 1000;
        OV2655_Sensor_Driver.Dummy_Lines= 0;//2600*1240
      }else if(pParaIn->ZoomFactor <= 400){//Zoom 3x ~ 4x
        OV2655_Sensor_Driver.Dummy_Pixels = 1800;
        OV2655_Sensor_Driver.Dummy_Lines= 0;//2600*1240
      }else{ //Zoom 4x ~ 8x
      CamWriteCmosSensor(0x3011,0x02);//(39000/3)*2
        OV2655_Sensor_Driver.Capture_PClk = 26000;
        OV2655_Sensor_Driver.Dummy_Pixels = 1800;
        OV2655_Sensor_Driver.Dummy_Lines= 0;//3500*1240
      }
    }else{
      if(pParaIn->ZoomFactor == 100){//Not Zoom
      
        OV2655_Sensor_Driver.Capture_PClk = 39000;
        OV2655_Sensor_Driver.Dummy_Pixels = 0;
        OV2655_Sensor_Driver.Dummy_Lines= 0;//1940*1240
      }else if(pParaIn->ZoomFactor <= 200){//Zoom 1x ~ 2x
      
        OV2655_Sensor_Driver.Capture_PClk = 39000;
        OV2655_Sensor_Driver.Dummy_Pixels = 1400;
        OV2655_Sensor_Driver.Dummy_Lines= 0;//1940*1240
      }else if(pParaIn->ZoomFactor <= 400){//Zoom 2x ~ 4x
      
        CamWriteCmosSensor(0x3011,0x03);//(39000/3)*2
        OV2655_Sensor_Driver.Capture_PClk = 19500;
        OV2655_Sensor_Driver.Dummy_Pixels = 1600;
        OV2655_Sensor_Driver.Dummy_Lines= 0;//2600*1240
      }else{ //Zoom 4x ~ 8x
        CamWriteCmosSensor(0x3011,0x03);//(39000/4)*2
        OV2655_Sensor_Driver.Capture_PClk = 19500;
        OV2655_Sensor_Driver.Dummy_Pixels = 2000;
        OV2655_Sensor_Driver.Dummy_Lines= 0;//3500*1240
      }

    }
  #else
    if ((pParaIn->ImageTargetWidth <= 1600)&& 
      (pParaIn->ImageTargetHeight <= 1200)){//For 2M Capture
      
      OV2655_Sensor_Driver.Capture_PClk = 39000;

      if(pParaIn->ZoomFactor == 100){//Not Zoom
        OV2655_Sensor_Driver.Dummy_Pixels = 0;
        OV2655_Sensor_Driver.Dummy_Lines= 0;//1940*1240
      }else if(pParaIn->ZoomFactor <= 200){//Zoom 1x ~ 2x
        OV2655_Sensor_Driver.Dummy_Pixels = 0;
        OV2655_Sensor_Driver.Dummy_Lines= 0;//1940*1240
      }else if(pParaIn->ZoomFactor <= 400){//Zoom 2x ~ 4x
        OV2655_Sensor_Driver.Dummy_Pixels = 660;
        OV2655_Sensor_Driver.Dummy_Lines= 0;//2600*1240
      }else{ //Zoom 4x ~ 8x
        OV2655_Sensor_Driver.Dummy_Pixels = 1560;
        OV2655_Sensor_Driver.Dummy_Lines= 0;//3500*1240
      }
    }else{
      if(pParaIn->ZoomFactor == 100){//Not Zoom
      
        OV2655_Sensor_Driver.Capture_PClk = 39000;
        OV2655_Sensor_Driver.Dummy_Pixels = 0;
        OV2655_Sensor_Driver.Dummy_Lines= 0;//1940*1240
      }else if(pParaIn->ZoomFactor <= 200){//Zoom 1x ~ 2x
      
        OV2655_Sensor_Driver.Capture_PClk = 39000;
        OV2655_Sensor_Driver.Dummy_Pixels = 1400;
        OV2655_Sensor_Driver.Dummy_Lines= 0;//1940*1240
      }else if(pParaIn->ZoomFactor <= 400){//Zoom 2x ~ 4x
      
        CamWriteCmosSensor(0x3011,0x02);//(39000/3)*2
        OV2655_Sensor_Driver.Capture_PClk = 26000;
        OV2655_Sensor_Driver.Dummy_Pixels = 900;
        OV2655_Sensor_Driver.Dummy_Lines= 0;//2600*1240
      }else{ //Zoom 4x ~ 8x
        CamWriteCmosSensor(0x3011,0x03);//(39000/4)*2
        OV2655_Sensor_Driver.Capture_PClk = 19500;
        OV2655_Sensor_Driver.Dummy_Pixels = 900;
        OV2655_Sensor_Driver.Dummy_Lines= 0;//3500*1240
      }

    }
  #endif
#elif CAM_OFFLINE_CAPTURE //Capture Offline Mode
    OV2655_Sensor_Driver.Capture_PClk = 39000;
    OV2655_Sensor_Driver.Dummy_Pixels = 0;
    OV2655_Sensor_Driver.Dummy_Lines= 0;
#else//Before W1005 for not the new capture mode:OTF&OFFLINE
    OV2655_Sensor_Driver.Capture_PClk = 39000;
    OV2655_Sensor_Driver.Dummy_Pixels = 0;
    OV2655_Sensor_Driver.Dummy_Lines= 0;
#endif

    OV2655_Sensor_Driver.iGrabWidth = OV2655_IMAGE_SENSOR_FULL_WIDTH;
    OV2655_Sensor_Driver.iGrabheight = OV2655_IMAGE_SENSOR_FULL_HEIGHT;

    OV2655_Sensor_Driver.Capture_Pixels_In_Lines = OV2655_FULL_PERIOD_PIXEL_NUMS + OV2655_Sensor_Driver.Dummy_Pixels;

    //Update the new shutter
    OV2655_Sensor_Driver.Capture_Shutter = OV2655_Sensor_Driver.Preview_Shutter * (OV2655_Sensor_Driver.Capture_PClk/OV2655_Sensor_Driver.Preview_PClk);
    OV2655_Sensor_Driver.Capture_Shutter = (OV2655_Sensor_Driver.Capture_Shutter * OV2655_Sensor_Driver.Preview_Pixels_In_Lines)/OV2655_Sensor_Driver.Capture_Pixels_In_Lines;

    if((OV2655_Sensor_Driver.sensor_id == OV2650_SENSOR_ID_1) || (OV2655_Sensor_Driver.sensor_id == OV2650_SENSOR_ID_2))
      OV2655_Sensor_Driver.Capture_Shutter = 2* OV2655_Sensor_Driver.Capture_Shutter;//For OV2650
  } /*UXGA*/

  OV2655_set_dummy(OV2655_Sensor_Driver.Dummy_Pixels,OV2655_Sensor_Driver.Dummy_Lines);
  OV2655_write_shutter(OV2655_Sensor_Driver.Capture_Shutter);

  pParaOut->GrabStartX = OV2655_Sensor_Driver.StartX;
  pParaOut->GrabStartY = OV2655_Sensor_Driver.StartY;
  pParaOut->ExposureWindowWidth = OV2655_Sensor_Driver.iGrabWidth;
  pParaOut->ExposureWindowHeight = OV2655_Sensor_Driver.iGrabheight;


  /* For CCT Capture 
  When capture raw data format, the first bar is dark then following, 
  so delay several frame to make sure the shutter take effect before TG start grab data. */
#if (defined(DRV_ISP_6238_SERIES))
//  if( bMetaMode == CAPTURE_MODE_META ) 
 //   kal_sleep_task(100);
#endif
}  /* OV2655_capture() */

/*************************************************************************
* FUNCTION
*  OV2655_write_reg
*
* DESCRIPTION
*  This function set the register of OV2655.
*
* PARAMETERS
*  addr : the register index of OV2655
*  para : setting parameter of the specified register of OV2655
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void OV2655_write_reg(kal_uint32 addr, kal_uint32 para)
{
  CamWriteCmosSensor(addr,para);
}  /* OV2655_write_reg() */

/*************************************************************************
* FUNCTION
*  CamReadCmosSensor
*
* DESCRIPTION
*  This function read parameter of specified register from OV2655.
*
* PARAMETERS
*  addr : the register index of OV2655
*
* RETURNS
*  the data that read from OV2655
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 OV2655_read_reg(kal_uint32 addr)
{
  return CamReadCmosSensor(addr);
}  /* OV2655_read_reg() */

/*************************************************************************
* FUNCTION
*  OV2655_set_shutter
*
* DESCRIPTION
*  This function set e-shutter of OV2655 to change exposure time.
*
* PARAMETERS
*  shutter : exposured lines
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void OV2655SetShutter(kal_uint16 shutter)
{
  if (shutter <1 )
    shutter =1;

  OV2655_Sensor_Driver.Preview_Shutter = shutter;

  OV2655_write_shutter(shutter);

}  /* OV2655_set_shutter */

/*************************************************************************
* FUNCTION
*  OV2655SetGain
*
* DESCRIPTION
*  This function is to set global gain to sensor.
*
* PARAMETERS
*  gain : sensor global gain(base: 0x40)
*
* RETURNS
*  the actually gain set to sensor.
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint16 OV2655SetGain(kal_uint16 iGain)
{
  /**************************************************************
    Gain Timming:
      ____  ____  ____  ____  ____  ____
      |  |  |  |  |  |  |  |  |  |  |  |  |  
    ____|  |___|  |___|  |___|  |___|  |___|  |___|
       {0}       {1}    {2}    {3}     {0}     {1}
  shutter/sensor Gain    ISP Gain
  **************************************************************/
    const kal_uint16 iBaseGain = Reg2Gain(pNvramSensorData->cct[SENSOR_BASEGAIN].para);
    const kal_uint16 iGain2Set = iGain * iBaseGain / BASEGAIN;
    kal_uint8 iReg = OV2655_Gain2Reg(iGain2Set);

/////////////////////////////////////////////////////////////////////////
//For Gain register value need correction from Gain test 
    //Step(1)Gain 0x10 need sift 1 point For point 0x10 change dark than Point 0x0F
    if((iReg >=0x10)&&(iReg <0x30))
        iReg +=1;

   //Step(2)
    if((iReg > 0x1f)&&(iReg <0x30))// For step 1), Gain shift to (0x1f,0x30).but Point 0x20 same as Point 0x10, need change to Point 0x30 
    {
        iReg |= 0x30;
        iReg += 0x2;//Need shifte 0x2 + 0x01(step 1)
    }else if((iReg >=0x30)&&(iReg <0x70))
        iReg +=3;

 
 //Step(3) For OV2655,Max Gain value 0x3f and Max Gain shift 0x4 , So Gain table 0x3b
    if(OV2655_Sensor_Driver.sensor_id ==OV2655_SENSOR_ID_3) //  max gain is 8* Gain on OV2655
    {
        if((iReg > 0x3f)||(iReg >=0x70))
            iReg = 0x3f;
    }
   else//For OV2650 sensor Gain 16x
    {
        if((iReg > 0x3f)&&(iReg <0x70))// above 8*Gain after shift   1* Gain, Set 8*Gain register value,Then shift  again
        {
            iReg |= 0x70;
            iReg += 1;
        }
        else if((iReg >=0x70)&&(iReg <0xf0))//  8*Gain - 16*Gain, Shift  2* Gain
            iReg +=4;

        if(iReg >0x7f)// above 16*Gain, Set  as 16*Gain
            iReg =0xf0;    
    }
/////////////////////////////////////////////////////////////////////////

    //Apply the Gain value
    CamWriteCmosSensor(0x3000, iReg);

    //  extra shutter
    CamWriteCmosSensor(0x302d, (OV2655_Sensor_Driver.extra_shutter>> 8) & 0xff);
    CamWriteCmosSensor(0x302e, OV2655_Sensor_Driver.extra_shutter & 0xff);
  
    return Reg2Gain(iReg) * BASEGAIN / iBaseGain;
}


#if (!defined(DRV_ISP_6219_SERIES))
//extern void flashlight_power_on(kal_bool on);
void OV2655_Set_Flashlight(kal_bool bEnable)
{
 //   flashlight_power_on(bEnable);
}   /*  OV2640_Set_Flashlight   */
#endif


//------------------------Engineer mode---------------------------------
extern int sprintf (char*, const char*, ...);


void  OV2655GetSensorGroupCount(kal_int32* sensor_count_ptr)
{
  *sensor_count_ptr = GROUP_TOTAL_NUMS;
  return;
}

void OV2655GetSensorGroupInfo(kal_uint16 group_idx, kal_int8* group_name_ptr, kal_int32* item_count_ptr)
{
   switch (group_idx)
   {
        case PRE_GAIN:
    sprintf((char *)group_name_ptr, "CCT");
    *item_count_ptr = FACTORY_END_ADDR;
    break;
  case CMMCLK_CURRENT:
    sprintf((char *) group_name_ptr, "CMMCLK Current");
    *item_count_ptr = 1;
        break;  
  case FRAME_RATE_LIMITATION:
    break;
  case REGISTER_EDITOR:
    break;
  default:
    ASSERT(0);
  }
}
static void OV2655GetSensorItemInfo(kal_uint16 group_idx,kal_uint16 item_idx, CAL_CCT_SENSOR_ITEM_INFO_STRUCT* info_ptr)
{
  kal_uint32 iReg2Gain=0;
  kal_uint8 iReg=0x00;
  kal_uint8 iRegbit = 0x00;

  switch (group_idx)
  {     
    case PRE_GAIN:
      switch (item_idx)
      {
        case SENSOR_BASEGAIN:                
          sprintf((char *) (info_ptr->ItemValue), "SENSOR_BASEGAIN");
          iReg = pNvramSensorData->cct[SENSOR_BASEGAIN].para;        
          break; 
        
        case PRE_GAIN_R_INDEX:          
          sprintf((char *) (info_ptr->ItemValue), "Pregain-R");
          iReg = pNvramSensorData->cct[PRE_GAIN_R_INDEX].para;  
          break;

        case PRE_GAIN_Gr_INDEX:          
          sprintf((char *) (info_ptr->ItemValue), "Pregain-Gr");
          iReg = pNvramSensorData->cct[PRE_GAIN_Gr_INDEX].para;  
          break;
          
        case PRE_GAIN_Gb_INDEX:
          sprintf((char *) info_ptr->ItemValue, "Pregain-Gb");
          iReg = pNvramSensorData->cct[PRE_GAIN_Gb_INDEX].para;  
          break;
          
        case PRE_GAIN_B_INDEX:
          sprintf((char *) info_ptr->ItemValue, "Pregain-B");          
          iReg = pNvramSensorData->cct[PRE_GAIN_B_INDEX].para;  
          break;
          
        default:
           ASSERT(0);    
      }

      //Transfer Reg value to Gain value
      if (item_idx == SENSOR_BASEGAIN){
        iReg2Gain = Reg2Gain(iReg);
        
                           info_ptr->ItemValue = (1000*iReg2Gain)/BASEGAIN;
        info_ptr->Min=1*1000; //Min global gain = 1x base gain
        info_ptr->Max=8*1000; //Max global gain = 16x base gain 
      }else{  
        iRegbit= iReg & 0xC0;
        
        if (iRegbit == 0x00){
          iReg2Gain = 1000;
        }else if (iRegbit == 0x40){
          iReg2Gain = 1250;
        }else if (iRegbit == 0x80){
          iReg2Gain = 1500;
        }else if (iRegbit == 0xC0){
          iReg2Gain = 1750;
        }
        
                             info_ptr->ItemValue = iReg2Gain;
        info_ptr->Min=1000;
        info_ptr->Max=1875; 
      }

      info_ptr->IsTrueFalse=KAL_FALSE;
      info_ptr->IsReadOnly=KAL_FALSE;
      info_ptr->IsNeedRestart=KAL_FALSE;  
      break;

    case CMMCLK_CURRENT:
      switch (item_idx) {
        case 0:
          sprintf((char *) info_ptr->ItemValue, "Drv Current[2,4,6,8]mA");
          switch (pNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para) {
            case ISP_DRIVING_2MA:
              info_ptr->ItemValue = 2;
              break;
            case ISP_DRIVING_4MA:
              info_ptr->ItemValue = 4;
              break;
            case ISP_DRIVING_6MA:
              info_ptr->ItemValue = 6;
              break;
            case ISP_DRIVING_8MA:
              info_ptr->ItemValue = 8;
              break;
            default:
              ASSERT(0);
          }

        info_ptr->IsTrueFalse = KAL_FALSE;
        info_ptr->IsReadOnly = KAL_FALSE;
        info_ptr->IsNeedRestart = KAL_TRUE;
        info_ptr->Min = 2;
        info_ptr->Max = 8;
        break;
      default:
        ASSERT(0);
      }   // switch (iItem_IDX)
      break;
    case FRAME_RATE_LIMITATION:
      break;
    case REGISTER_EDITOR:
      break;
    default:
      ASSERT(0); 
  }
}

kal_bool OV2655SetSensorItemInfo(kal_uint16 group_idx, kal_uint16 item_idx, kal_int32 ItemValue)
{
  kal_uint16 Reg_addr = 0;    
  kal_uint32 gain = 0 ;
  kal_uint8 iOV2655_Gain2Reg=0;

  switch (group_idx)
  {
    case PRE_GAIN:
      switch (item_idx)
      {
        case SENSOR_BASEGAIN:
          if (ItemValue < 1 * 1000 || ItemValue >= 8 * 1000) {
            return KAL_FALSE;
          }

          Reg_addr = SENSOR_BASEGAIN;      
          break;
        
        case PRE_GAIN_R_INDEX:
          if (ItemValue < 1 * 1000 || ItemValue >= 4 * 1000) {
            return KAL_FALSE;
          }

          Reg_addr = PRE_GAIN_R_INDEX;
          break;
          
          case PRE_GAIN_Gr_INDEX:    
          if (ItemValue < 1 * 1000 || ItemValue >= 4 * 1000) {
            return KAL_FALSE;
          }
          
          Reg_addr = PRE_GAIN_Gr_INDEX;
            break;
                
          case PRE_GAIN_Gb_INDEX:  
          if (ItemValue < 1 * 1000 || ItemValue >= 4 * 1000) {
            return KAL_FALSE;
          }

          Reg_addr = PRE_GAIN_Gb_INDEX;
            break;
                
          case PRE_GAIN_B_INDEX:  
          if (ItemValue < 1 * 1000 || ItemValue >= 4 * 1000) {
            return KAL_FALSE;
          }

          Reg_addr = PRE_GAIN_B_INDEX;
            break;

        default:
             ASSERT(0);  
      }


      //Gain value trnsfer to the Register value
      if (Reg_addr == SENSOR_BASEGAIN){
                
                           gain = (ItemValue * BASEGAIN)/1000;
        iOV2655_Gain2Reg = OV2655_Gain2Reg(gain);   

      }else{
                              iOV2655_Gain2Reg = pNvramSensorData->cct[Reg_addr].para;
                              iOV2655_Gain2Reg &= ~0xC0;

                      if(ItemValue>=1000 && ItemValue<=1125)
              iOV2655_Gain2Reg |= 0x00;
          else if(ItemValue>1125 && ItemValue<=1375)
              iOV2655_Gain2Reg |= 0x40;
          else if(ItemValue>1375 && ItemValue<=1625)
              iOV2655_Gain2Reg |= 0x80;
          else if(ItemValue>1625 && ItemValue<=1875)
              iOV2655_Gain2Reg |= 0xC0;
          else
            return KAL_FALSE;
      }

      pNvramSensorData->cct[Reg_addr].para = iOV2655_Gain2Reg;
      OV2655_write_reg(pNvramSensorData->cct[Reg_addr].addr, iOV2655_Gain2Reg);
      break;

    case CMMCLK_CURRENT:
      switch (item_idx) {
        case 0:
            if (ItemValue == 2) {
                pNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_2MA;
      //          set_isp_driving_current(ISP_DRIVING_2MA);
            }else if (ItemValue == 3 || ItemValue == 4) {
                pNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_4MA;
    //            set_isp_driving_current(ISP_DRIVING_4MA);
            }else if (ItemValue == 5 || ItemValue == 6) {
                pNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_6MA;
 //               set_isp_driving_current(ISP_DRIVING_6MA);
            }else if (ItemValue == 7 || ItemValue == 8) {
                pNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_8MA;
 //               set_isp_driving_current(ISP_DRIVING_8MA);
            }else {
                return KAL_FALSE;
            }
            break;

        default:
            ASSERT(0);
      }   // switch (CMMCLK_CURRENT)
      break;

    case FRAME_RATE_LIMITATION:
      break;

    case REGISTER_EDITOR:
      break;
    default:
      ASSERT(0);
  }
  
  return KAL_TRUE;
}




/*************************************************************************
* FUNCTION
*    OV2655PowerOn
*
* DESCRIPTION
*    This function reset sensor and read id
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
static kal_uint16 OV2655PowerOn(void)
{
	kal_uint16 SensorId = NULL_SENSOR_ID;
	kal_uint8 i = 0;

	CisModulePowerOn(OV2655SensorIdx, KAL_TRUE);
	CameraSccbOpen(CAMERA_SCCB_SENSOR, OV2655_WRITE_ID, CAMERA_SCCB_16BIT, CAMERA_SCCB_8BIT, 300);

	kal_sleep_task(2); // To wait for Stable Power

	CamPdnPinCtrl(OV2655SensorIdx, 0);

	/* Reset the sensor */
	CamRstPinCtrl(OV2655SensorIdx, 1); //Sensor RESET pin high
	kal_sleep_task(1);
	CamRstPinCtrl(OV2655SensorIdx, 0); //Sensor RESET pin low
	kal_sleep_task(2);
	CamRstPinCtrl(OV2655SensorIdx, 1);  //Sensor RESET pin high
	kal_sleep_task(1);

	
	//Soft Reset
	CamWriteCmosSensor(0x0038, 0x00);
	kal_sleep_task(1);			  


	OV2655_Sensor_Driver.sensor_id = ((CamReadCmosSensor(0x300A) << 8) | CamReadCmosSensor(0x300B));
#ifdef OUTPUT_DEBUG_INFO
	kal_print_string_trace(MOD_ENG, TRACE_WARNING, "OV2655 SENSOR ID: %x", OV2655_Sensor_Driver.sensor_id);
#endif
	if ((OV2655_Sensor_Driver.sensor_id != OV2655_SENSOR_ID_3) && 
		(OV2655_Sensor_Driver.sensor_id != OV2650_SENSOR_ID_1) && 
		(OV2655_Sensor_Driver.sensor_id != OV2650_SENSOR_ID_2) ){
		return -1;
	}else{
		return OV2655_SENSOR_ID;
	}

} /* OV2655PowerOn() */


/*************************************************************************
* FUNCTION
*    OV2655DetectSensorId
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
static kal_uint32 OV2655DetectSensorId(void)
{
  kal_uint16 SensorId;
  MM_ERROR_CODE_ENUM OV2655SensorClose(void);

  SensorId = OV2655PowerOn();
  CisModulePowerOn(OV2655SensorIdx, KAL_FALSE);
  OV2655SensorClose();

  return SensorId;
}

extern void OV2655CameraParaToSensor(nvram_camera_para_struct *pCameraPara);

static MM_ERROR_CODE_ENUM OV2655SensorOpen(void)
{
	if (OV2655_SENSOR_ID != OV2655PowerOn()) return MM_ERROR_SENSOR_READ_ID_FAIL;
	set_OV2655_SVGA();
	
	OV2655_Sensor_Driver.Camco_mode = OV2655_CAM_PREVIEW;
	//OV2655CameraParaToSensor();
	//Reg0x30a1 Bit[0] = 0x01 dont kown why
	CamWriteCmosSensor(0x30A1, CamReadCmosSensor(0x30A1)|0x01);
}

/*************************************************************************
* FUNCTION
*    OV2655GetSensorInfo
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
static void OV2655GetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT Info)
{
  Info->SensorId = OV2655_SENSOR_ID;
//  Info->ResetActiveHigh = KAL_FALSE;
//  Info->PowerOnActiveHigh = KAL_FALSE;//KAL_TRUE;
  Info->SensorIf = IMAGE_SENSOR_IF_PARALLEL;

#ifdef OV2655_PURE_RAW
  Info->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_R_FIRST;
  Info->PreviewHMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_R_FIRST;
  Info->PreviewVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_R_FIRST;
  Info->PreviewHVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_R_FIRST;  
  
  Info->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_R_FIRST;
#else
  Info->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gb_FIRST;
  Info->PreviewHMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gb_FIRST;
  Info->PreviewVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gb_FIRST;
  Info->PreviewHVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gb_FIRST;  
  
  Info->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gb_FIRST;
#endif  

  Info->PixelClkPolarity = POLARITY_LOW;
  Info->HsyncPolarity = POLARITY_LOW;//POLARITY_HIGH;
  Info->VsyncPolarity = POLARITY_LOW;  
//  Info->DrivingCurrent = ISP_DRIVING_8MA;
  Info->PreviewMclkFreq = 26000000;
  Info->CaptureMclkFreq = 26000000;
  Info->VideoMclkFreq = 26000000;
  Info->PreviewWidth = OV2655_IMAGE_SENSOR_PV_WIDTH; 
  Info->PreviewHeight = OV2655_IMAGE_SENSOR_PV_HEIGHT;  
  Info->FullWidth = OV2655_IMAGE_SENSOR_FULL_WIDTH;
  Info->FullHeight = OV2655_IMAGE_SENSOR_FULL_HEIGHT;
  Info->SensorAfSupport = KAL_FALSE;
  Info->SensorFlashSupport = KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*    OV2655Banding
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
MM_ERROR_CODE_ENUM OV2655Banding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV2655StillCaptureSize
*
* DESCRIPTION
*    This function get capture size
*
* PARAMETERS
*    in, out, out_len, r_out_len
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV2655StillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT pFeatureParaIn,
                                               P_CAL_FEATURE_CTRL_STRUCT pFeatureParaOut,
                                               kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{
  P_CAL_FEATURE_TYPE_ENUM_STRUCT pStillCaptureSize=(P_CAL_FEATURE_TYPE_ENUM_STRUCT) &(pFeatureParaOut->FeatureInfo.FeatureEnum);

  switch (pFeatureParaIn->FeatureCtrlCode)
  {
  case CAL_FEATURE_QUERY_OPERATION:
    pFeatureParaOut->FeatureType=CAL_FEATURE_TYPE_ENUMERATE;
    pFeatureParaOut->FeatureOperationSupport=CAL_FEATURE_SET_OPERATION|
                                             CAL_FEATURE_GET_OPERATION|
                                             CAL_FEATURE_QUERY_OPERATION;
    pFeatureParaOut->FeatureModeSupport=CAL_FEATURE_CAMERA_SUPPORT;
    pStillCaptureSize->IsSupport=KAL_TRUE;
    pStillCaptureSize->ItemCount = 4;
    pStillCaptureSize->SupportItem[0] = CAM_SIZE_WALLPAPER;
    pStillCaptureSize->SupportItem[1] = CAM_SIZE_VGA;
    pStillCaptureSize->SupportItem[2] = CAM_SIZE_1M;
    pStillCaptureSize->SupportItem[3] = CAM_SIZE_2M;
    break;
  }
  return MM_ERROR_NONE;
}

static MM_ERROR_CODE_ENUM OV2655BinningInfo(P_CAL_FEATURE_CTRL_STRUCT pFeatureParaIn,
                                        P_CAL_FEATURE_CTRL_STRUCT pFeatureParaOut,
                                        kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{
  P_CAL_FEATURE_CAMERA_BINNING_INFO_STRUCT pBinningInfo = pFeatureParaOut->FeatureInfo.FeatureStructured.pBinningInfo;
  kal_uint8 i;
  
  switch (pFeatureParaIn->FeatureCtrlCode)
  {
  case CAL_FEATURE_QUERY_OPERATION:
    for (i = CAM_ISO_AUTO; i <= CAM_ISO_200; i++)
    {
      pBinningInfo->IsoBinningInfo[i].MaxResolution = CAM_IMAGE_SIZE_2M;
      pBinningInfo->IsoBinningInfo[i].IsoSupported = KAL_TRUE;
      pBinningInfo->IsoBinningInfo[i].BinningEnable = KAL_FALSE;
    }
    for (;i <= CAM_ISO_1600; i++)
    {
      pBinningInfo->IsoBinningInfo[i].MaxResolution = CAM_IMAGE_SIZE_1M;
      pBinningInfo->IsoBinningInfo[i].IsoSupported = KAL_FALSE;
      pBinningInfo->IsoBinningInfo[i].BinningEnable = KAL_TRUE;
    }
  break;
  }
}
void OV2655GetSensorAeInfo(IMAGE_SENSOR_AE_INFO_STRUCT *info_ptr) {
	info_ptr->DefaultPrevLinePixels = OV2655_PV_PERIOD_PIXEL_NUMS;
	info_ptr->CurrentPrevLinePixels = OV2655_PV_PERIOD_PIXEL_NUMS + OV2655_Sensor_Driver.Dummy_Pixels;
	info_ptr->CurrentPclk = OV2655_Sensor_Driver.Preview_PClk * 1000;
}
/*************************************************************************
* FUNCTION
*  image_sensor_func_config
*
* DESCRIPTION
*  This function maps the camera module function API structure.
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
// write camera_para to sensor register
static void OV2655CameraParaToSensor(nvram_camera_para_struct *pCameraPara)
{
  kal_uint32  i;

  for(i=0; (0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr); i++)
  {
    CamWriteCmosSensor(pCameraPara->SENSOR.reg[i].addr, pCameraPara->SENSOR.reg[i].para);
  }
  for(i=ENGINEER_START_ADDR; (0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr); i++)
  {
    CamWriteCmosSensor(pCameraPara->SENSOR.reg[i].addr, pCameraPara->SENSOR.reg[i].para);
  }
  for(i=0; i<FACTORY_END_ADDR; i++)
  {
    CamWriteCmosSensor(pCameraPara->SENSOR.reg[i].addr,pCameraPara->SENSOR.reg[i].para);
  }
}

// update camera_para from sensor register
static void OV2655SensorToCameraPara(nvram_camera_para_struct *pCameraPara)
{
  kal_uint32  i;

  for(i=0; (0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr)&&(i<ENGINEER_START_ADDR); i++)
  {
    pCameraPara->SENSOR.reg[i].para = CamReadCmosSensor(pCameraPara->SENSOR.reg[i].addr);
  }
  for(i=ENGINEER_START_ADDR; (0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr); i++)
  {
    pCameraPara->SENSOR.reg[i].para = CamReadCmosSensor(pCameraPara->SENSOR.reg[i].addr);
  }
}

/*************************************************************************
* FUNCTION
*    OV2655InitOperationPara
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
static void OV2655InitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT Para)
{
  Para->CaptureDelayFrame = 1; /* wait stable frame when sensor change mode (pre to cap) */
  Para->PreviewDelayFrame = 2; /* wait stable frame when sensor change mode (cap to pre) */
  Para->PreviewDisplayWaitFrame = 3; /* wait stable frame when sensor change mode (cap to pre) */
	Para->AeCalDelayFrame = 0; /* The frame of calculation default 0 */
	Para->AeShutDelayFrame = 0; /* The frame of setting shutter default 0 for TG int */
	Para->AeSensorGainDelayFrame = 1; /* The frame of setting sensor gain */
	Para->AeIspGainDelayFrame = 2; /* The frame of setting gain */
	Para->AeCalPeriod = 3; /* AE AWB calculation period */
#if(defined(LED_FLASHLIGHT_SUPPORT))
	Para->FlashlightMode = FLASHLIGHT_LED_CONSTANT;
#elif(defined(LED_ONOFF_SUPPORT))
	Para->FlashlightMode = FLASHLIGHT_LED_ONOFF;
#else
	Para->FlashlightMode = FLASHLIGHT_NONE;
#endif
	Para->FlashlightDeltaMainLum = 65; // 1.015*64(1.015X)
}

/*************************************************************************
* FUNCTION
*    OV2655DscSupportInfo
*
* DESCRIPTION
*    This function get dsc support info
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
static void OV2655DscSupportInfo(P_IMAGE_SENSOR_GET_DSC_SUPPORT_INFO_STRUCT pDscSupportInfo)
{
  kal_mem_cpy(pDscSupportInfo, &OV2655_dsc_support_info, sizeof(camcorder_info_struct));
}


/*************************************************************************
* FUNCTION
*    OV2655SensorFeatureCtrl
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
static MM_ERROR_CODE_ENUM OV2655SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_ENUM FeatureId,
                                                void *pFeatureParaIn, void *pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{
  MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;

  if (FeatureId >= CAL_FEATURE_WEBCAM_BEGIN && FeatureId <= CAL_FEATURE_WEBCAM_END)
  {
	return OV2655WebcamFeatureCtrl(FeatureId, pFeatureParaIn, pFeatureParaOut,
								   FeatureParaOutLen, pRealFeatureParaOutLen);
  }
  // for the features that not support in the sensor, then it is not necessary to implement it.
  switch (FeatureId)
  {
  case IMAGE_SENSOR_FEATURE_SET_ESHUTTER:
	OV2655SetShutter(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
	break;
  case IMAGE_SENSOR_FEATURE_SET_GAIN:
	OV2655SetGain(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
	break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
	OV2655GetSensorInfo((P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT) pFeatureParaOut);
	break;
  case IMAGE_SENSOR_FEATURE_GET_MIPI_INFO:
	FeatureParaOutLen = sizeof(P_IMAGE_SENSOR_MIPI_PARA_OUT_STRUCT);
	*pRealFeatureParaOutLen = sizeof(P_IMAGE_SENSOR_MIPI_PARA_OUT_STRUCT);			  
	break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
	((P_IMAGE_SENSOR_COMM_DATA_STRUCT) pFeatureParaOut)->FeatureValue=OV2655DetectSensorId();
	break;
  case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
	OV2655SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT) pFeatureParaIn)->ImageSensorIdx;
	break;
  case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE:
	break;
  case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
	CamPdnPinCtrl(OV2655SensorIdx,1);
	CamRstPinCtrl(OV2655SensorIdx,0);
	break;
  case IMAGE_SENSOR_FEATURE_GET_PREVIEW_FLASHLIGHT_INFO:
	//OV2655GetPreviewFlashlightInfo((P_FLASHLIGHT_PREVIEW_PARA_STURCT)pFeatureParaOut);
	break;
  case IMAGE_SENSOR_FEATURE_GET_CAPTURE_FLASHLIGHT_INFO:
	//OV2655GetCaptureFlashlightInfo((P_FLASHLIGHT_CAPTURE_SENSOR_PARA_IN_STRUCT)pFeatureParaIn, (P_FLASHLIGHT_CAPTURE_PARA_STRUCT)pFeatureParaOut);
	break;
  case IMAGE_SENSOR_FEATURE_CTRL_FLASHLIGHT:
	//OV2655SetFlashlight(((P_IMAGE_SENSOR_COMM_CTRL_STRUCT)pFeatureParaIn)->FeatureEnable);
	break;
  case IMAGE_SENSOR_FEATURE_GET_AE_INFO:
	OV2655GetSensorAeInfo((P_IMAGE_SENSOR_AE_INFO_STRUCT)pFeatureParaOut);
	break;
  case IMAGE_SENSOR_FEATURE_GET_AE_LUT:
	OV2655GetAeLut((P_AE_LUT_INFO_STRUCT) pFeatureParaIn, (P_IMAGE_SENSOR_AE_LUT_STRUCT)pFeatureParaOut,
						FeatureParaOutLen, pRealFeatureParaOutLen);
	break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
  	 ((P_IMAGE_SENSOR_COMM_DATA_STRUCT) pFeatureParaOut)->FeatureValue=OV2655_Sensor_Driver.fixed_frame_rate;
	break;
  case IMAGE_SENSOR_FEATURE_GET_SHADING_TABLE:
	ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
	break;
  case CAL_FEATURE_CAMERA_BINNING_INFO:
	ErrorCode=OV2655BinningInfo((P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaIn,
									 (P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaOut, FeatureParaOutLen, pRealFeatureParaOutLen);
	break;
  // customized by customer
  case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
	ErrorCode=OV2655StillCaptureSize((P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaIn,
								 (P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaOut, FeatureParaOutLen, pRealFeatureParaOutLen);
	break;
  // for YUV sensor sample code
  // the following are for YUV sensor only
  case CAL_FEATURE_CAMERA_SHARPNESS:
  // please refer the sample code of OV2655Sharpness();
	//ErrorCode=OV2655Sharpness((P_CAL_FEATRUE_CTRL_STRUCT)pFeatureParaIn,
	//							   (P_CAL_FEATRUE_CTRL_STRUCT)pFeatureParaOut, FeatureParaOutLen, pRealFeatureParaOutLen);
	break;
  case CAL_FEATURE_CAMERA_EV_VALUE:
  case CAL_FEATURE_CAMERA_BANDING_FREQ:
  case CAL_FEATURE_CAMERA_WB:
  case CAL_FEATURE_CAMERA_HUE:
  case CAL_FEATURE_CAMERA_BRIGHTNESS:
  case CAL_FEATURE_CAMERA_CONTRAST:
  case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
  case CAL_FEATURE_CAMERA_SATURATION:
  case IMAGE_SENSOR_FEATURE_YUV_3A_CTRL:
  case CAL_FEATURE_CAMERA_FLASH_MODE:
	// These features are supported in YUV sensor only.
	// Put here just for notifying DD colleagues. Should be removed later for MT9P012. PC Huang 20100903
	ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
	break;
  // the above are for YUV sensor only
  case CAL_FEATURE_CCT_OP_CAMERA_PARA_TO_SENSOR:
	OV2655CameraParaToSensor(pFeatureParaIn);
	break;
  case CAL_FEATURE_CCT_OP_SENSOR_TO_CAMERA_PARA:
	OV2655SensorToCameraPara(pFeatureParaOut);
	break;
  case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
	OV2655InitOperationPara((P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT)pFeatureParaOut);
	break;
  case IMAGE_SENSOR_FEATURE_GET_DSC_SUPPORT_INFO:
	OV2655DscSupportInfo((P_IMAGE_SENSOR_GET_DSC_SUPPORT_INFO_STRUCT)pFeatureParaOut);
	break;
  case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
	pNvramSensorData = &(((nvram_camera_para_struct *) pFeatureParaIn)->SENSOR);
	break;
  case IMAGE_SENSOR_FEATURE_GET_GAIN:
//	((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaOut)->FeatureValue=OV2655ReadGain();
	break;
  case IMAGE_SENSOR_FEATURE_GET_ENG_INFO:
	((P_SENSOR_INFO_STRUCT)pFeatureParaOut)->id = 145;
	((P_SENSOR_INFO_STRUCT)pFeatureParaOut)->type = CMOS_SENSOR;
	break;
  case IMAGE_SENSOR_FEATURE_GET_CCT_GROUP_COUNT:
	OV2655GetSensorGroupCount((kal_int32 *)pFeatureParaOut);
	break;
  case IMAGE_SENSOR_FEATURE_GET_CCT_GROUP_INFO:
	OV2655GetSensorGroupInfo(((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaIn)->GroupNamePtr, &((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaOut)->ItemCount);
	break;	
  case IMAGE_SENSOR_FEATURE_GET_CCT_ITEM_INFO:
	OV2655GetSensorItemInfo(((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemIdx, (P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaOut);
	break;
  case IMAGE_SENSOR_FEATURE_SET_CCT_ITEM_INFO:
	OV2655SetSensorItemInfo(((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemIdx, ((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemValue);
	break;
  default:
	ErrorCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
	break;
  }
  return ErrorCode;
}


/*************************************************************************
* FUNCTION
*    OV2655SensorCtrl
*
* DESCRIPTION
*    This function set sensor scenario mode
*
* PARAMETERS
*    id: scenario id
*    in/out: parameter
*    out_len: out parameter length
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV2655SensorCtrl(CAL_SCENARIO_ENUM ScenarioId, void *pParaIn,
                                         void *pParaOut, kal_uint16 ParaOutLen)
{
	switch (ScenarioId)
	{
		case CAL_SCENARIO_CAMERA_PREVIEW:
		case CAL_SCENARIO_WEBCAM_PREVIEW:
		case CAL_SCENARIO_WEBCAM_CAPTURE:
		case CAL_SCENARIO_VIDEO:
		case CAL_SCENARIO_VIDEO_TELEPHONY:
		OV2655Preview(ScenarioId, pParaIn, pParaOut);
		break;
		case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
		OV2655Capture(ScenarioId, pParaIn, pParaOut);
		break;
		default:
		break;
	}
	return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    OV2655SensorClose
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
static MM_ERROR_CODE_ENUM OV2655SensorClose(void)
{
	CamPdnPinCtrl(OV2655SensorIdx, 1);
  	CameraSccbClose(CAMERA_SCCB_SENSOR);

	CisModulePowerOn(OV2655SensorIdx, KAL_FALSE);

	return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV2655SensorFunc
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
MM_ERROR_CODE_ENUM OV2655SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncOV2655 =
  {
    OV2655SensorOpen,
    OV2655SensorFeatureCtrl,
    OV2655SensorCtrl,
    OV2655SensorClose,
  };
  
  *pfSensorFunc = &ImageSensorFuncOV2655;
}
