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
 *   image_sensor_OV2655.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   CMOS sensor header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _IMAGE_SENSOR_OV2655_H
#define _IMAGE_SENSOR_OV2655_H

#include "drv_features.h"
#include "sensor_comm_def.h"
#include "isp_if.h"

/**************************Engineer mode***************************************/
  #define OV2655_FACTORY_START_ADDR (0)
  #define OV2655_ENGINEER_START_ADDR (39)

  typedef enum OV2655_group_enum {
     OV2655_PRE_GAIN=0,
     OV2655_CMMCLK_CURRENT,
     OV2655_FRAME_RATE_LIMITATION,
     OV2655_REGISTER_EDITOR,
     OV2655_GROUP_TOTAL_NUMS
  } OV2655_FACTORY_GROUP_ENUM;

  typedef enum OV2655_register_index {
     OV2655_SENSOR_BASEGAIN=OV2655_FACTORY_START_ADDR,
     OV2655_PRE_GAIN_R_INDEX,
     OV2655_PRE_GAIN_Gr_INDEX,
     OV2655_PRE_GAIN_Gb_INDEX,
     OV2655_PRE_GAIN_B_INDEX,     
     OV2655_FACTORY_END_ADDR
  } OV2655_FACTORY_REGISTER_INDEX;
    
  typedef enum OV2655_engineer_index {
     OV2655_CMMCLK_CURRENT_INDEX=OV2655_ENGINEER_START_ADDR,
     OV2655_ENGINEER_END
  } OV2655_FACTORY_ENGINEER_INDEX;


#if (!(defined(DRV_ISP_6238_SERIES) || defined(DRV_ISP_6235_SERIES)))
  typedef struct {
     sensor_reg_struct  reg[ENGINEER_END];
     sensor_reg_struct  cct[FACTORY_END_ADDR];
  } sensor_data_struct;
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
#endif

  /* For OV2655 CCT Function */
  #define OV2655_CCT_MainSensor      OV2655_OMNIVISION
#if defined(SENSOR_ROTATE_0)
  #define OV2655_CCT_FirstGrabColor    BAYER_Gr  // normal 
#elif defined(SENSOR_ROTATE_180)
  #define OV2655_CCT_FirstGrabColor    BAYER_Gb  // rotate 180 
#else
  #define OV2655_CCT_FirstGrabColor    BAYER_Gr  // rotate 90, 270 not used yet 
#endif

  /* MAXIMUM EXPLOSURE LINES USED BY AE */
  //extern kal_uint16 OV2655_MAX_EXPOSURE_LINES;
  //extern kal_uint8  OV2655_MIN_EXPOSURE_LINES;


  /* SENSOR EXPOSURE LINE LIMITATION */
  #define OV2655_FULL_EXPOSURE_LIMITATION           1248
  #define OV2655_PV_EXPOSURE_LIMITATION            672

  //IMAGE SIZE
  #define OV2655_IMAGE_SENSOR_PV_WIDTH            (800 - 16)
  #define OV2655_IMAGE_SENSOR_PV_HEIGHT                 (600 - 12)
  #define OV2655_IMAGE_SENSOR_FULL_WIDTH          (1600 - 24)
  #define OV2655_IMAGE_SENSOR_FULL_HEIGHT          (1200 - 18)

  //USED BY AE TABLE
   //#define IMAGE_SENSOR_FULL_WIDTH              OV2655_IMAGE_SENSOR_FULL_WIDTH


  /* SENSOR HORIZONTAL/VERTICAL BLANKING */  
  #define OV2655_IMAGE_SENSOR_PV_DEFAULT_HBLANKING    (170) 
  #define OV2655_IMAGE_SENSOR_PV_DEFAULT_VBLANKING    (18) //17.961
  
  #define OV2655_IMAGE_SENSOR_FULL_DEFAULT_HBLANKING     (340)  //
  #define OV2655_IMAGE_SENSOR_FULL_DEFAULT_VBLANKING   (40) //(2404330-)/1940~=39.52    
  

  /* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */  
  #define OV2655_PV_ACTIVE_PIXEL_NUMS             800
  #define OV2655_PV_ACTIVE_LINE_NUMS            600

  #define OV2655_FULL_ACTIVE_PIXEL_NUMS            1600
  #define OV2655_FULL_ACTIVE_LINE_NUMS            1200

  
  #define OV2655_PV_PERIOD_PIXEL_NUMS             (OV2655_PV_ACTIVE_PIXEL_NUMS+OV2655_IMAGE_SENSOR_PV_DEFAULT_HBLANKING)//970
  #define OV2655_PV_PERIOD_LINE_NUMS            (OV2655_PV_ACTIVE_LINE_NUMS+OV2655_IMAGE_SENSOR_PV_DEFAULT_VBLANKING)//619.673

  #define OV2655_FULL_PERIOD_PIXEL_NUMS            (OV2655_FULL_ACTIVE_PIXEL_NUMS+OV2655_IMAGE_SENSOR_FULL_DEFAULT_HBLANKING) //1940
  #define OV2655_FULL_PERIOD_LINE_NUMS            (OV2655_FULL_ACTIVE_LINE_NUMS+OV2655_IMAGE_SENSOR_FULL_DEFAULT_VBLANKING)//2404332/1940=1239.346 ~=1240


  //Mode state
  typedef enum OV2655_CAMCO_MODE
  {    
    OV2655_CAM_PREVIEW=0,//Camera Preview
    
    OV2655_CAM_CAPTURE_SVGA,//Camera Capture
    OV2655_CAM_CAPTURE_UXGA,
  
    OV2655_VIDEO_MPEG4,//Video Mode
    OV2655_VIDEO_MJPEG,
    
#ifdef __MEDIA_VT__
/* under construction !*/
#endif    
    OV2655_WEBCAM_CAPTURE,//WebCam
    
    OV2655_VIDEO_MAX
  } OV2655_Camco_MODE;

	typedef enum OV2655_VIDEO_SIZE
	{		
	  OV2655_VIDEO_SIZE_QCIF=0,
	  OV2655_VIDEO_SIZE_CIF,
	  OV2655_VIDEO_SIZE_QVGA,
	  OV2655_VIDEO_SIZE_HVGA,
	  OV2655_VIDEO_SIZE_D1,
	  OV2655_VIDEO_SIZE__MAX
	} OV2655_Video_Size;
  struct OV2655_sensor_struct
  {
    kal_uint16 sensor_write_id;
    kal_uint16 sensor_read_id;
    kal_uint16 sensor_id;
  
    OV2655_Camco_MODE Camco_mode;
  
    //kal_uint32 MClk;
    kal_uint32 Preview_PClk;
    kal_uint32 Capture_PClk;
    kal_uint16 Preview_Pixels_In_Lines; 
    kal_uint16 Capture_Pixels_In_Lines;
    kal_uint16 Preview_Shutter;
    kal_uint16 Capture_Shutter;
    kal_uint16 Dummy_Pixels;
    kal_uint16 Dummy_Lines;
    
    kal_uint16 StartX;
    kal_uint16 StartY;
    kal_uint16 iGrabWidth;
    kal_uint16 iGrabheight;
  
      kal_uint16 extra_shutter;
    kal_uint16 extra_shutter_backup;
  
    kal_bool FrameRate_Fix_enable;
    kal_uint32 fixed_frame_rate;
    kal_bool Night_Mode;
 	CAL_CAMERA_BANDING_FREQ_ENUM Band_Mode;
    OV2655_Video_Size Video_size;
  };

  //Config TG $ ISP
  #define OV2655_SET_RESET_CMOS_SENSOR_HIGH    REG_ISP_CMOS_SENSOR_MODE_CONFIG |= REG_CMOS_SENSOR_RESET_BIT;
  #define OV2655_SET_RESET_CMOS_SENSOR_LOW    REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_RESET_BIT;
  #define OV2655_SET_PDN_CMOS_SENSOR_LOW            REG_ISP_CMOS_SENSOR_MODE_CONFIG &= ~REG_CMOS_SENSOR_POWER_ON_BIT;
  #define OV2655_SET_FIRST_GRAB_COLOR(n)           REG_ISP_PREPROCESS_CTRL1 &= ~REG_PREPROCESS1_PID_POLARITY_BIT;\
                        REG_ISP_PREPROCESS_CTRL1 &= ~REG_PREPROCESS1_LID_POLARITY_BIT;\
                         REG_ISP_PREPROCESS_CTRL1 |= (n<<12);

  #define OV2655_WRITE_ID               0x60
  #define OV2655_READ_ID                0x61

  /* SENSOR CHIP VERSION */
  #define OV2650_SENSOR_ID_1              0x2651
  #define OV2650_SENSOR_ID_2              0x2652
  #define OV2655_SENSOR_ID_3              0x2656
MM_ERROR_CODE_ENUM OV2655SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

#endif /* _IMAGE_SENSOR_H */
