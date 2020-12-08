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
 *   image_sensor_GC0307.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/ 
#include "drv_comm.h"
#include "isp_comm_if.h"
#include "image_sensor.h"
#include "sensor_comm_def.h"
#include "Cal_comm_def.h"
#include "isp_if.h"
#include "camera_sccb.h"

/* #define GC0307_DEBUG */
static struct 
{
  kal_bool VideoMode;
  kal_bool NightMode;
  kal_uint8 Banding;

  kal_uint16 DummyPixels;
  kal_uint16 ShutterStep;
  kal_uint8 Ev;
  kal_uint8 Wb; 
  kal_uint8 Effect; 

  kal_uint8 RegMode1; //0x47 register backup  
  kal_uint8 RegWB;    //0x41 register backup

  kal_uint16 FrameRate;
  
  IMAGE_SENSOR_INDEX_ENUM SensorIdx;
  sensor_data_struct *NvramData;
}GC0307SensorStatus;

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

/*************************************************************************
* FUNCTION
*    GC0307InitialSetting
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
static void GC0307InitialSetting(void)
{
  // Initail Sequence Write In.
  //======= close output========
  CamWriteCmosSensor(0x43,0x00); 
  CamWriteCmosSensor(0x44,0xa2); 

  //====== close some functions====
  // open them after configure their parmameters
  CamWriteCmosSensor(0x40,0x10); 
  CamWriteCmosSensor(0x41,0x00);
  CamWriteCmosSensor(0x42,0x10);
  CamWriteCmosSensor(0x47,0x00); //mode1, 
  CamWriteCmosSensor(0x48,0xc3); //mode2, 
  CamWriteCmosSensor(0x49,0x00); //dither_mode
  CamWriteCmosSensor(0x4a,0x00); //clock_gating_en
  CamWriteCmosSensor(0x4b,0x00); //mode_reg3
  CamWriteCmosSensor(0x4E,0x23); //sync mode
  CamWriteCmosSensor(0x4F,0x01); //AWB, AEC, every N frame

  //======== frame timing======== 
  CamWriteCmosSensor(0x01,0x6a); //HB
  CamWriteCmosSensor(0x02,0x0c); //VB
  CamWriteCmosSensor(0x1C,0x00); //Vs_st
  CamWriteCmosSensor(0x1D,0x00); //Vs_et
  CamWriteCmosSensor(0x10,0x00); //high 4 bits of VB, HB
  CamWriteCmosSensor(0x11,0x05); //row_tail,AD_pipe_number

  //========= windowing========
  CamWriteCmosSensor(0x05,0x00); //row_start
  CamWriteCmosSensor(0x06,0x00);
  CamWriteCmosSensor(0x07,0x00); //col start
  CamWriteCmosSensor(0x08,0x00); 
  CamWriteCmosSensor(0x09,0x01); //win height 488
  CamWriteCmosSensor(0x0A,0xE8);
  CamWriteCmosSensor(0x0B,0x02); //win width, pixel array only 640
  CamWriteCmosSensor(0x0C,0x80);

  //========= analog========= 
  CamWriteCmosSensor(0x0D,0x22); //rsh_width 
  CamWriteCmosSensor(0x0E,0x02); //CISCTL mode2,
  CamWriteCmosSensor(0x0F,0xb2); //CISCTL mode1
  CamWriteCmosSensor(0x12,0x70); //7 hrst, 6_4 darsg,
  CamWriteCmosSensor(0x13,0x00); //7 CISCTL_restart, 0 apwd
  CamWriteCmosSensor(0x14,0x00); //NA
  CamWriteCmosSensor(0x15,0xba); //7_4 vref
  CamWriteCmosSensor(0x16,0x13); //5to4 _coln_r,__1to0__da18
  CamWriteCmosSensor(0x17,0x52); //opa_r, ref_r, sRef_r
  CamWriteCmosSensor(0x18,0xc0); //analog_mode, best case for left band.
  CamWriteCmosSensor(0x1E,0x0d); //tsp_width   
  CamWriteCmosSensor(0x1F,0x32); //sh_delay

  //========= offset========= 
  CamWriteCmosSensor(0x47,0x00);//7_test_image, 6_fixed_pga, 5_auto_DN, 4_CbCr_fix, 
                                      //3to2_dark_sequence, 1_allow_pclk_vcync, 0_LSC_test_image
  CamWriteCmosSensor(0x19,0x06);//pga_o 
  CamWriteCmosSensor(0x1a,0x06);//pga_e 

  CamWriteCmosSensor(0x31,0x00);///4///pga_oFFset ,  high 8bits of 11bits
  CamWriteCmosSensor(0x3B,0x00);//global_oFFset, low 8bits of 11bits

  CamWriteCmosSensor(0x59,0x0f);//offset_mode
  CamWriteCmosSensor(0x58,0x88);//DARK_VALUE_RATIO_G,  DARK_VALUE_RATIO_RB
  CamWriteCmosSensor(0x57,0x08);//DARK_CURRENT_RATE
  CamWriteCmosSensor(0x56,0x77);//PGA_OFFSET_EVEN_RATIO, PGA_OFFSET_ODD_RATIO

  //========= blk========= 
  CamWriteCmosSensor(0x35,0xd8);//blk_mode

  CamWriteCmosSensor(0x36,0x40);

  CamWriteCmosSensor(0x3C,0x00); 
  CamWriteCmosSensor(0x3D,0x00); 
  CamWriteCmosSensor(0x3E,0x00); 
  CamWriteCmosSensor(0x3F,0x00); 

  CamWriteCmosSensor(0xb5,0x70); 
  CamWriteCmosSensor(0xb6,0x30); 
  CamWriteCmosSensor(0xb7,0x00); 
  CamWriteCmosSensor(0xb8,0x38); 
  CamWriteCmosSensor(0xb9,0xc2);
  CamWriteCmosSensor(0xba,0x0f); 

  CamWriteCmosSensor(0x7e,0x4c); //48
  CamWriteCmosSensor(0x7f,0x6c); //6c

  CamWriteCmosSensor(0x5c,0x48); //78
  CamWriteCmosSensor(0x5d,0x38); //88


  //========= manual_gain ========= 
  CamWriteCmosSensor(0x61,0x80); //manual_gain_g1 
  CamWriteCmosSensor(0x63,0x80); //manual_gain_r
  CamWriteCmosSensor(0x65,0x90); //manual_gai_b, 0xa0=1.25, 0x98=1.1875
  CamWriteCmosSensor(0x67,0x80); //manual_gain_g2
  CamWriteCmosSensor(0x68,0x14); //global_manual_gain  2.4bits

  //=========CC _R
  CamWriteCmosSensor(0x69,0x41);//54
  CamWriteCmosSensor(0x6A,0xf7);//ff
  CamWriteCmosSensor(0x6B,0xf6);//fe
  CamWriteCmosSensor(0x6C,0x00);//ff
  CamWriteCmosSensor(0x6D,0x4d);//5f
  CamWriteCmosSensor(0x6E,0xfd);//e1

  CamWriteCmosSensor(0x6f,0x00); 

  //=========lsc=========  
  CamWriteCmosSensor(0x70,0x14); 
  CamWriteCmosSensor(0x71,0x1c); 
  CamWriteCmosSensor(0x72,0x20); 

  CamWriteCmosSensor(0x73,0x00);
  CamWriteCmosSensor(0x74,0x3C); //39
  CamWriteCmosSensor(0x75,0x53); 

  //=========dn ========= 
  CamWriteCmosSensor(0x7d,0x1f);//dn_mode
  CamWriteCmosSensor(0x80,0x0c); //when auto_dn, check 7e,7f
  CamWriteCmosSensor(0x81,0x0c);
  CamWriteCmosSensor(0x82,0x44);

  CamWriteCmosSensor(0x83,0x18);//DD_TH1
  CamWriteCmosSensor(0x84,0x18);//DD_TH2
  CamWriteCmosSensor(0x85,0x04);//DD_TH3
  CamWriteCmosSensor(0x87,0x32);//32 b DNDD_low_range X16,DNDD_low_range_C_weight_center

     
  //=========intp-ee=========
  CamWriteCmosSensor(0x88,0x04);
  CamWriteCmosSensor(0x89,0x01);
  CamWriteCmosSensor(0x8a,0x41);//60
  CamWriteCmosSensor(0x8b,0x41);//60
  CamWriteCmosSensor(0x8c,0x07); 

  CamWriteCmosSensor(0x50,0x0c);
  CamWriteCmosSensor(0x5f,0x3c); 

  CamWriteCmosSensor(0x8e,0x04);
  CamWriteCmosSensor(0x86,0x04);

  CamWriteCmosSensor(0x51,0x20);
  CamWriteCmosSensor(0x52,0x08);
  CamWriteCmosSensor(0x53,0x00); 


  //========= YCP ========= 
  //contrast_center
  CamWriteCmosSensor(0x77,0x80); //contrast_center
  CamWriteCmosSensor(0x78,0x00); //fixed_Cb
  CamWriteCmosSensor(0x79,0x00); //fixed_Cr
  CamWriteCmosSensor(0x7a,0x00); //luma_offset
  CamWriteCmosSensor(0x7b,0x40); //hue_cos
  CamWriteCmosSensor(0x7c,0x00); //hue_sin  

  CamWriteCmosSensor(0xa0,0x40); //global_saturation
  CamWriteCmosSensor(0xa1,0x40); //luma_contrast  
  CamWriteCmosSensor(0xa2,0x40); //saturation_Cb
  CamWriteCmosSensor(0xa3,0x40); //saturation_Cr

  CamWriteCmosSensor(0xa4,0xc8);
  CamWriteCmosSensor(0xa5,0x02); 
  CamWriteCmosSensor(0xa6,0x28);
  CamWriteCmosSensor(0xa7,0x04); 

  //skin
  CamWriteCmosSensor(0xa8,0xee);  
  CamWriteCmosSensor(0xa9,0x12);  
  CamWriteCmosSensor(0xaa,0x01);
  CamWriteCmosSensor(0xab,0x20);
  CamWriteCmosSensor(0xac,0xf0);  
  CamWriteCmosSensor(0xad,0x10);  

  //========= ABS========= 
  CamWriteCmosSensor(0xae,0x18); 
  CamWriteCmosSensor(0xaf,0x74); 
  CamWriteCmosSensor(0xb0,0xe0);  
  CamWriteCmosSensor(0xb1,0x20); 
  CamWriteCmosSensor(0xb2,0x6c); 
  CamWriteCmosSensor(0xb3,0x20); 
  CamWriteCmosSensor(0xb4,0x01); 

  //========= AWB =========
  CamWriteCmosSensor(0xbb,0x42); 
  CamWriteCmosSensor(0xbc,0x60); 
  CamWriteCmosSensor(0xbd,0x50); 
  CamWriteCmosSensor(0xbe,0x50); 

  CamWriteCmosSensor(0xbf,0x0c); 
  CamWriteCmosSensor(0xc0,0x06); 
  CamWriteCmosSensor(0xc1,0x70); 
  CamWriteCmosSensor(0xc2,0xf2);  //f4
  CamWriteCmosSensor(0xc3,0x30); 
  CamWriteCmosSensor(0xc4,0x18); //18
  CamWriteCmosSensor(0xc5,0x42); 
  CamWriteCmosSensor(0xc6,0x1c);

  CamWriteCmosSensor(0xca,0x55); 
  CamWriteCmosSensor(0xcb,0x55); 
  CamWriteCmosSensor(0xcc,0x78);

  CamWriteCmosSensor(0xcd,0x80); //R_ratio 
  CamWriteCmosSensor(0xce,0x80); //G_ratio  , cold_white white 
  CamWriteCmosSensor(0xcf,0x80); //B_ratio 

  //=========  aecT  ========= 
  CamWriteCmosSensor(0x20,0x07); //06
  CamWriteCmosSensor(0x21,0xf0); 
  CamWriteCmosSensor(0x22,0x60);
  CamWriteCmosSensor(0x23,0x84); //88
  CamWriteCmosSensor(0x24,0x96); 
  CamWriteCmosSensor(0x25,0x30); 
  CamWriteCmosSensor(0x26,0xd0); 
  CamWriteCmosSensor(0x27,0x00); 

  CamWriteCmosSensor(0x28,0x01); //AEC_exp_level_1bit11to8   
  CamWriteCmosSensor(0x29,0xf4); //AEC_exp_level_1bit7to0	20fps  
  CamWriteCmosSensor(0x2a,0x02); //AEC_exp_level_2bit11to8   
  CamWriteCmosSensor(0x2b,0xbc); //AEC_exp_level_2bit7to0		14fps
  CamWriteCmosSensor(0x2c,0x03); //AEC_exp_level_3bit11to8   
  CamWriteCmosSensor(0x2d,0xe8); //AEC_exp_level_3bit7to0 10fps 
  CamWriteCmosSensor(0x2e,0x07); //AEC_exp_level_4bit11to8  
  CamWriteCmosSensor(0x2f,0x6c); //AEC_exp_level_4bit7to0 5fps 

  CamWriteCmosSensor(0x30,0x20);  
  CamWriteCmosSensor(0x31,0x00);   
  CamWriteCmosSensor(0x32,0x1c); 
  CamWriteCmosSensor(0x33,0x90);  
  CamWriteCmosSensor(0x34,0x20); // 10

  CamWriteCmosSensor(0xd0,0x30); 
  CamWriteCmosSensor(0xd1,0x88); //AEC_target_Y
  CamWriteCmosSensor(0xd2,0x62);  
  CamWriteCmosSensor(0xd4,0x96); 
  CamWriteCmosSensor(0xd5,0x01); 
  CamWriteCmosSensor(0xd6,0x96); //antiflicker_step   
  CamWriteCmosSensor(0xd7,0x04); //AEC_exp_time_min   
  CamWriteCmosSensor(0xd8,0x02); 

  //========= measure window========= 
  CamWriteCmosSensor(0xe0,0x03); 
  CamWriteCmosSensor(0xe1,0x02); 
  CamWriteCmosSensor(0xe2,0x27); 
  CamWriteCmosSensor(0xe3,0x1e);
  CamWriteCmosSensor(0xe8,0x3b);
  CamWriteCmosSensor(0xe9,0x6e);
  CamWriteCmosSensor(0xea,0x2c);
  CamWriteCmosSensor(0xeb,0x50);
  CamWriteCmosSensor(0xec,0x73);

  //=====close_frame======
  CamWriteCmosSensor(0xed,0x00); //close_frame_num1 ,can be use to reduce FPS 
  CamWriteCmosSensor(0xee,0x00); //close_frame_num2  
  CamWriteCmosSensor(0xef,0x00); //close_frame_num

  // page1
  CamWriteCmosSensor(0xf0,0x01); //select page1 

  CamWriteCmosSensor(0x00,0x20);
  CamWriteCmosSensor(0x01,0x20);
  CamWriteCmosSensor(0x02,0x20);
  CamWriteCmosSensor(0x03,0x20);
  CamWriteCmosSensor(0x04,0x78); 
  CamWriteCmosSensor(0x05,0x78);
  CamWriteCmosSensor(0x06,0x78);  
  CamWriteCmosSensor(0x07,0x78); 

  CamWriteCmosSensor(0x10,0x04);
  CamWriteCmosSensor(0x11,0x04);
  CamWriteCmosSensor(0x12,0x04);
  CamWriteCmosSensor(0x13,0x04);
  CamWriteCmosSensor(0x14,0x01);
  CamWriteCmosSensor(0x15,0x01);  
  CamWriteCmosSensor(0x16,0x01);
  CamWriteCmosSensor(0x17,0x01);

  CamWriteCmosSensor(0x20,0x00);
  CamWriteCmosSensor(0x21,0x00);
  CamWriteCmosSensor(0x22,0x00);
  CamWriteCmosSensor(0x23,0x00);
  CamWriteCmosSensor(0x24,0x00);
  CamWriteCmosSensor(0x25,0x00); 
  CamWriteCmosSensor(0x26,0x00);
  CamWriteCmosSensor(0x27,0x00);

  CamWriteCmosSensor(0x40,0x11); 

  //============lscP =====
  CamWriteCmosSensor(0x45,0x05);
  CamWriteCmosSensor(0x46,0x04); 
  CamWriteCmosSensor(0x47,0x04); 

  CamWriteCmosSensor(0x48,0x05);
  CamWriteCmosSensor(0x49,0x09);
  CamWriteCmosSensor(0x4a,0x07); 

  CamWriteCmosSensor(0x62,0xd8); 
  CamWriteCmosSensor(0x63,0x24); 
  CamWriteCmosSensor(0x64,0x24); 
  CamWriteCmosSensor(0x65,0x24); 
  CamWriteCmosSensor(0x66,0xd8); 
  CamWriteCmosSensor(0x67,0x24);

  CamWriteCmosSensor(0x5a,0x00); 
  CamWriteCmosSensor(0x5b,0x00); 
  CamWriteCmosSensor(0x5c,0x00); 
  CamWriteCmosSensor(0x5d,0x00); 
  CamWriteCmosSensor(0x5e,0x00); 
  CamWriteCmosSensor(0x5f,0x00);

  //========== ccP =======
  CamWriteCmosSensor(0x69,0x03); //cc_mode
    
  //CC_G
  CamWriteCmosSensor(0x70,0x52); 
  CamWriteCmosSensor(0x71,0xf1); 
  CamWriteCmosSensor(0x72,0xfe); 
  CamWriteCmosSensor(0x73,0xee); 
  CamWriteCmosSensor(0x74,0x53); 
  CamWriteCmosSensor(0x75,0xf1); 

    //CC_B
  CamWriteCmosSensor(0x76,0x43); 
  CamWriteCmosSensor(0x77,0xf3); 
  CamWriteCmosSensor(0x78,0x00); 
  CamWriteCmosSensor(0x79,0xfd); 
  CamWriteCmosSensor(0x7a,0x53); 
  CamWriteCmosSensor(0x7b,0x00);

  //========== AGP======= 
  CamWriteCmosSensor(0x7e,0x00);  
  CamWriteCmosSensor(0x7f,0x35);  
  CamWriteCmosSensor(0x80,0xc8);  
  CamWriteCmosSensor(0x81,0x06);  //6
  CamWriteCmosSensor(0x82,0x08);  //8

  CamWriteCmosSensor(0x83,0x23);  
  CamWriteCmosSensor(0x84,0x38);  
  CamWriteCmosSensor(0x85,0x4F);  
  CamWriteCmosSensor(0x86,0x61);  
  CamWriteCmosSensor(0x87,0x72);  
  CamWriteCmosSensor(0x88,0x80);  
  CamWriteCmosSensor(0x89,0x8D);  
  CamWriteCmosSensor(0x8a,0xA2);  
  CamWriteCmosSensor(0x8b,0xB2);  
  CamWriteCmosSensor(0x8c,0xC0);  
  CamWriteCmosSensor(0x8d,0xCA);  
  CamWriteCmosSensor(0x8e,0xD3);  
  CamWriteCmosSensor(0x8f,0xDB);  
  CamWriteCmosSensor(0x90,0xE2);  
  CamWriteCmosSensor(0x91,0xED);  
  CamWriteCmosSensor(0x92,0xF6);  
  CamWriteCmosSensor(0x93,0xFD);  

  //about gamma1 is hex r oct
  CamWriteCmosSensor(0x94,0x04);  
  CamWriteCmosSensor(0x95,0x0E);  
  CamWriteCmosSensor(0x96,0x1B);  
  CamWriteCmosSensor(0x97,0x28);  
  CamWriteCmosSensor(0x98,0x35);  
  CamWriteCmosSensor(0x99,0x41);  
  CamWriteCmosSensor(0x9a,0x4E);  
  CamWriteCmosSensor(0x9b,0x67);  
  CamWriteCmosSensor(0x9c,0x7E);  
  CamWriteCmosSensor(0x9d,0x94);  
  CamWriteCmosSensor(0x9e,0xA7);  
  CamWriteCmosSensor(0x9f,0xBA);  
  CamWriteCmosSensor(0xa0,0xC8);  
  CamWriteCmosSensor(0xa1,0xD4);  
  CamWriteCmosSensor(0xa2,0xE7);  
  CamWriteCmosSensor(0xa3,0xF4);  
  CamWriteCmosSensor(0xa4,0xFA); 

  //==== open functions====	
  CamWriteCmosSensor(0xf0,0x00); //set back to page0
  CamWriteCmosSensor(0x45,0x27);
  CamWriteCmosSensor(0x40,0x7e); 
  CamWriteCmosSensor(0x41,0x3f);
  CamWriteCmosSensor(0x47,0x0c);

  //========delay 200ms======== 
  kal_sleep_task(50);
  //=========open output
  CamWriteCmosSensor(0x43,0x40);
  CamWriteCmosSensor(0x44,0xE2);
}

/*************************************************************************
* FUNCTION
*    GC0307SetExpLevel
*
* DESCRIPTION
*    This function maping the level and frame rate.
*
* PARAMETERS
*    Level : level index
*    FrameRate: the frame rete of the level
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC0307SetExpLevel(kal_uint8 Level, kal_uint16 FrameRate)
{
  // Level 1    --max   frame rate 0x28[0:3] 0x29
  // Level 2    --med1 frame rate 0x2a[0:3] 0x2b 
  // Level 3    --med2 frame rate 0x2c[0:3] 0x2d 
  // Level 4    --min    frame rate 0x2e[0:3] 0x2f
  kal_uint16 Exposure;
  kal_uint8 Banding = GC0307SensorStatus.Banding == CAM_BANDING_60HZ ? GC0307_NUM_60HZ : GC0307_NUM_50HZ;

  Exposure = (Banding * GC0307_FRAME_RATE_UNIT / FrameRate)* GC0307SensorStatus.ShutterStep;
  ASSERT(Exposure <= 0xfff);
  ASSERT(Level <= 4 && Level >= 1);

  CamWriteCmosSensor(0x29 + 2 * (Level -1) ,Exposure & 0xff);
  CamWriteCmosSensor(0x28 + 2 * (Level -1),(Exposure >> 8) & 0x0f);
#ifdef GC0307_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "Level:%d,exporsure:%x",Level,Exposure);
#endif
}/* GC0307SetExpLevel */

/*************************************************************************
* FUNCTION
*    GC0307SetMaxExpLevel
*
* DESCRIPTION
*    This function set the max Exposure level (min frame rate).
*
* PARAMETERS
*    Level
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC0307SetMaxExpLevel(kal_uint8 Level)
{
  // 0xdd [4:5]  
  ASSERT(Level <= 4 && Level >= 1);
#ifdef GC0307_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "Max Level:%d",Level);
#endif
  Level = ((Level - 1) << 4) | 0x02;
  CamWriteCmosSensor(0xdd,Level);
}/* GC0307SetMaxExpLevel */

/*************************************************************************
* FUNCTION
*    GC0307SetDummy
*
* DESCRIPTION
*    This function set  dummy pixel and line.
*
* PARAMETERS
*    Pixels
*    Lines
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC0307SetDummy(kal_uint16 Pixels, kal_uint16 Lines)
{
  /*************************************    
   *   Register :0x01 - 0x02 - 0x10   
   *  0x10  [5:4]:VBANK[9:8]; [1:0]:HBANK[9:8]
   *  0x01 HBANK[7:0]
   *  0x02 VBANK[7:0] 
   *  0xd6 anti_flicker_step
   ***************************************/
  ASSERT(Pixels <= GC0307_BLANK_REGISTER_LIMITATION && Lines <= GC0307_BLANK_REGISTER_LIMITATION);
  CamWriteCmosSensor(0x01,Pixels & 0xff); 
  CamWriteCmosSensor(0x02,Lines& 0xff);
  CamWriteCmosSensor(0x10,((Lines & 0x300) >> 4) + ((Pixels & 0xf) >> 8));
  ASSERT(GC0307SensorStatus.ShutterStep <= 0xff);
  CamWriteCmosSensor(0xd6,GC0307SensorStatus.ShutterStep & 0xff); 
#ifdef GC0307_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "HB:%x,VB:%x,STEP:%x",Pixels,Lines,GC0307SensorStatus.ShutterStep);
#endif
}/* GC0307SetDummy */

/*************************************************************************
* FUNCTION
*    GC0307CalFps
*
* DESCRIPTION
*    This function calculate & set frame rate and fix frame rate when video mode
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
static void GC0307CalFps(void)
{
  kal_int16 LineLength,DummyLines;
  kal_uint16 MaxFps;
  kal_uint8 Banding = GC0307SensorStatus.Banding == CAM_BANDING_50HZ ? GC0307_NUM_50HZ : GC0307_NUM_60HZ;

  ASSERT(GC0307SensorStatus.DummyPixels >= 0x50 && GC0307SensorStatus.DummyPixels <= GC0307_BLANK_REGISTER_LIMITATION);

  LineLength = GC0307SensorStatus.DummyPixels + GC0307_PERIOD_PIXEL_NUMS;

  GC0307SensorStatus.ShutterStep = GC0307_SYSCLK / Banding / LineLength;

  if (GC0307SensorStatus.VideoMode == KAL_TRUE)
    MaxFps = GC0307SensorStatus.NightMode == KAL_TRUE ? (GC0307_MAX_CAMERA_FPS/2) : GC0307_MAX_CAMERA_FPS;
    else
  MaxFps = GC0307_MAX_CAMERA_FPS;

  if(GC0307SensorStatus.FrameRate > MaxFps) 
    GC0307SensorStatus.FrameRate = MaxFps;

  DummyLines = GC0307_SYSCLK * GC0307_FRAME_RATE_UNIT / LineLength / GC0307SensorStatus.FrameRate - GC0307_PERIOD_LINE_NUMS;

#ifdef GC0307_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "GC0307 cal fps MaxFps %x",GC0307SensorStatus.FrameRate/GC0307_FRAME_RATE_UNIT);
#endif

  if (DummyLines < 3) 
    DummyLines = 3;

  GC0307SetDummy(GC0307SensorStatus.DummyPixels,DummyLines);

  GC0307SetExpLevel(1,GC0307SensorStatus.FrameRate);
  if(GC0307SensorStatus.VideoMode == KAL_FALSE)    
  {
    GC0307SetExpLevel(2,GC0307SensorStatus.FrameRate > GC0307_MED_CAMERA_FPS ? GC0307_MED_CAMERA_FPS : GC0307SensorStatus.FrameRate);
    GC0307SetExpLevel(3,GC0307SensorStatus.FrameRate > GC0307_MIN_CAMERA_NORMAL_FPS ? GC0307_MIN_CAMERA_NORMAL_FPS : GC0307SensorStatus.FrameRate);
    GC0307SetExpLevel(4,GC0307SensorStatus.FrameRate > GC0307_MIN_CAMERA_NIGHT_FPS ? GC0307_MIN_CAMERA_NIGHT_FPS : GC0307SensorStatus.FrameRate);
    if(GC0307SensorStatus.NightMode == KAL_TRUE)
    {
      GC0307SetMaxExpLevel(4);
    }
    else
    {
      GC0307SetMaxExpLevel(3);
    }
  }
  else
  {
    GC0307SetMaxExpLevel(1);
  }
}/* GC0307CalFps */

/*************************************************************************
* FUNCTION
*    GC0307SetMirror
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
static void GC0307SetMirror(kal_uint8 Mirror)
{
  GC0307SensorStatus.RegMode1 &= 0xF3; 
  switch (Mirror)
  {
    case IMAGE_SENSOR_MIRROR_NORMAL:
      CamWriteCmosSensor(0x0f,0x82); // b0
      CamWriteCmosSensor(0x45,0x24); //Gr first
      GC0307SensorStatus.RegMode1 |= 0x20; 
      break;
    case IMAGE_SENSOR_MIRROR_H:
      CamWriteCmosSensor(0x0f,0x92); 
      CamWriteCmosSensor(0x45,0x25); //R first
      GC0307SensorStatus.RegMode1 |= 0x24; 
      break;
    case IMAGE_SENSOR_MIRROR_V:
      CamWriteCmosSensor(0x0f,0xa2); 
      CamWriteCmosSensor(0x45,0x26); //B first
      GC0307SensorStatus.RegMode1 |= 0x28; 
      break;
    case IMAGE_SENSOR_MIRROR_HV:
      CamWriteCmosSensor(0x0f,0xb2); 
      CamWriteCmosSensor(0x45,0x27); //Gb first
      GC0307SensorStatus.RegMode1 |= 0x2c; 
      break;
    default:
      break;
  }
  CamWriteCmosSensor(0x47,GC0307SensorStatus.RegMode1); //[3:2]dark_seqence    
}/* GC0307SetMirror */

/*****************************************************************************
 * FUNCTION
 *  GC0307WriteReg
 * DESCRIPTION
 *  This function set the register of GC0307.
 * PARAMETERS
 *  Addr       [IN]        the register index of GC0307
 *  Para       [IN]        setting parameter of the specified register of GC0307
 * RETURNS
 *  void
 *****************************************************************************/
static void GC0307WriteReg(kal_uint32 Addr, kal_uint32 Para)
{
  CamWriteCmosSensor(Addr,Para);
}

/*****************************************************************************
 * FUNCTION
 *  GC0307ReadReg
 * DESCRIPTION
 *  This function read parameter of specified register from GC0307.
 * PARAMETERS
 *  Addr       [IN]        the register index of GC0307
 * RETURNS
 *  the data that read from GC0307
 *****************************************************************************/
static kal_uint32 GC0307ReadReg(kal_uint32 Addr)
{
  return CamReadCmosSensor(Addr);
}

/*************************************************************************
* FUNCTION
*    GC0307EV
*
* DESCRIPTION
*    GC0307 EV setting.
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
static MM_ERROR_CODE_ENUM GC0307EV(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
#ifdef GC0307_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "EV:%d", In->FeatureSetValue);
#endif
    if (GC0307SensorStatus.Ev == In->FeatureSetValue)
    {
      return MM_ERROR_NONE;
    }
    GC0307SensorStatus.Ev = In->FeatureSetValue;
    switch (In->FeatureSetValue)
    {
      case CAM_EV_NEG_4_3:    
        CamWriteCmosSensor(0x7a, 0xc0);
        CamWriteCmosSensor(0xd1, 0x68);
        break;
      case CAM_EV_NEG_3_3:
        CamWriteCmosSensor(0x7a, 0xd0);
        CamWriteCmosSensor(0xd1, 0x70);
        break;
      case CAM_EV_NEG_2_3:
        CamWriteCmosSensor(0x7a, 0xe0);
        CamWriteCmosSensor(0xd1, 0x78);
        break;
      case CAM_EV_NEG_1_3:
        CamWriteCmosSensor(0x7a, 0xf0);
        CamWriteCmosSensor(0xd1, 0x80);
        break;
      case CAM_EV_ZERO:
        CamWriteCmosSensor(0x7a, 0x00);
        CamWriteCmosSensor(0xd1, 0x88); //80
        break;
      case CAM_EV_POS_1_3:
        CamWriteCmosSensor(0x7a, 0x20);
        CamWriteCmosSensor(0xd1, 0x98);
        break;
      case CAM_EV_POS_2_3:
        CamWriteCmosSensor(0x7a, 0x30);
        CamWriteCmosSensor(0xd1, 0xa8);
        break;
      case CAM_EV_POS_3_3:
        CamWriteCmosSensor(0x7a, 0x40);
        CamWriteCmosSensor(0xd1, 0xb8);
        break;
      case CAM_EV_POS_4_3:
        CamWriteCmosSensor(0x7a, 0x50);
        CamWriteCmosSensor(0xd1, 0xc8);
        break;
      default:
        break;
    }
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    GC0307WB
*
* DESCRIPTION
*    GC0307 Wb setting.
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
static MM_ERROR_CODE_ENUM GC0307WB(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
#ifdef GC0307_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"Wb:%d",In->FeatureSetValue);
#endif
    if (GC0307SensorStatus.Wb == In->FeatureSetValue)
      return MM_ERROR_NONE;

    GC0307SensorStatus.Wb = In->FeatureSetValue;
    switch (In->FeatureSetValue)
    {
      case CAM_WB_AUTO:
        CamWriteCmosSensor(0xc7,0x4c); //for AWB can adjust back
        CamWriteCmosSensor(0xc8,0x40);
        CamWriteCmosSensor(0xc9,0x4a);
        GC0307SensorStatus.RegWB = GC0307SensorStatus.RegWB|0x04;
        CamWriteCmosSensor(0x41,GC0307SensorStatus.RegWB);// Enable AWB
        break;
      case CAM_WB_CLOUD:
        GC0307SensorStatus.RegWB = GC0307SensorStatus.RegWB&~0x04;
        CamWriteCmosSensor(0x41,GC0307SensorStatus.RegWB);   // Disable AWB 
        CamWriteCmosSensor(0xc7,0x5a); //WB_manual_gain
        CamWriteCmosSensor(0xc8,0x42);
        CamWriteCmosSensor(0xc9,0x40);
        break;
      case CAM_WB_DAYLIGHT:   // tai yang guang
        GC0307SensorStatus.RegWB = GC0307SensorStatus.RegWB&~0x04;
        CamWriteCmosSensor(0x41,GC0307SensorStatus.RegWB);   // Disable AWB 
        CamWriteCmosSensor(0xc7,0x50);
        CamWriteCmosSensor(0xc8,0x45);
        CamWriteCmosSensor(0xc9,0x40);
        break;
      case CAM_WB_INCANDESCENCE:   // bai re guang
        GC0307SensorStatus.RegWB = GC0307SensorStatus.RegWB&~0x04;
        CamWriteCmosSensor(0x41,GC0307SensorStatus.RegWB);   // Disable AWB 
        CamWriteCmosSensor(0xc7,0x48);
        CamWriteCmosSensor(0xc8,0x40);
        CamWriteCmosSensor(0xc9,0x5c);
        break;
      case CAM_WB_FLUORESCENT:   //ri guang deng
        GC0307SensorStatus.RegWB = GC0307SensorStatus.RegWB&~0x04;
        CamWriteCmosSensor(0x41,GC0307SensorStatus.RegWB);   // Disable AWB 
        CamWriteCmosSensor(0xc7,0x40);
        CamWriteCmosSensor(0xc8,0x42);
        CamWriteCmosSensor(0xc9,0x50);
        break;
      case CAM_WB_TUNGSTEN:   // wu si deng
        GC0307SensorStatus.RegWB = GC0307SensorStatus.RegWB&~0x04;
        CamWriteCmosSensor(0x41,GC0307SensorStatus.RegWB);   // Disable AWB 
        CamWriteCmosSensor(0xc7,0x40);
        CamWriteCmosSensor(0xc8,0x54);
        CamWriteCmosSensor(0xc9,0x70);
        break;
      default:
        break;
    }
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    GC0307Effect
*
* DESCRIPTION
*    GC0307 Effect setting.
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
static MM_ERROR_CODE_ENUM GC0307Effect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    P_CAL_FEATURE_TYPE_ENUM_STRUCT EffectPara = &Out->FeatureInfo.FeatureEnum;
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION | CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    EffectPara->IsSupport = KAL_TRUE;
    EffectPara->ItemCount = 6;
    EffectPara->SupportItem[0] = CAM_EFFECT_ENC_NORMAL;
    EffectPara->SupportItem[1] = CAM_EFFECT_ENC_GRAYSCALE;
    EffectPara->SupportItem[2] = CAM_EFFECT_ENC_SEPIA;
    EffectPara->SupportItem[3] = CAM_EFFECT_ENC_SEPIAGREEN;
    EffectPara->SupportItem[4] = CAM_EFFECT_ENC_SEPIABLUE;
    EffectPara->SupportItem[5] = CAM_EFFECT_ENC_COLORINV;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
#ifdef GC0307_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"Effect:%d",In->FeatureSetValue);
#endif
    if (GC0307SensorStatus.Effect == In->FeatureSetValue)
      return MM_ERROR_NONE;

    GC0307SensorStatus.Effect = In->FeatureSetValue;

    if((In->FeatureSetValue == CAM_EFFECT_ENC_NORMAL) || (In->FeatureSetValue == CAM_EFFECT_ENC_COLORINV))        
      GC0307SensorStatus.RegMode1 = GC0307SensorStatus.RegMode1 & 0xef;
    else
      GC0307SensorStatus.RegMode1 = GC0307SensorStatus.RegMode1 | 0x10;
    switch (In->FeatureSetValue)
    {
      case CAM_EFFECT_ENC_NORMAL:
        GC0307SensorStatus.RegWB = GC0307SensorStatus.RegWB|0x39;
        CamWriteCmosSensor(0x41,GC0307SensorStatus.RegWB);
        CamWriteCmosSensor(0x40,0x7e);
        CamWriteCmosSensor(0x42,0x10);
        CamWriteCmosSensor(0x47,GC0307SensorStatus.RegMode1);
        CamWriteCmosSensor(0x48,0xc3);
        CamWriteCmosSensor(0x8a,0x50);//60
        CamWriteCmosSensor(0x8b,0x50);
        CamWriteCmosSensor(0x8c,0x07);
        CamWriteCmosSensor(0x50,0x0c);
        CamWriteCmosSensor(0x77,0x80);
        CamWriteCmosSensor(0xa1,0x40);
        CamWriteCmosSensor(0x7a,0x00);
        CamWriteCmosSensor(0x78,0x00);
        CamWriteCmosSensor(0x79,0x00);
        CamWriteCmosSensor(0x7b,0x40);
        CamWriteCmosSensor(0x7c,0x00);        
        CamWriteCmosSensor(0x40,0x7e); 
        CamWriteCmosSensor(0x41,GC0307SensorStatus.RegWB);            
        CamWriteCmosSensor(0xf0,0x01); //go to page 1
        CamWriteCmosSensor(0x80,0x48);
        CamWriteCmosSensor(0x7f,0x40);
        CamWriteCmosSensor(0xf0,0x00); //back to page 0
        break;                        
      case CAM_EFFECT_ENC_GRAYSCALE:
        GC0307SensorStatus.RegWB = GC0307SensorStatus.RegWB|0x39;
        CamWriteCmosSensor(0x41,GC0307SensorStatus.RegWB);
        CamWriteCmosSensor(0x40,0x7e);
        CamWriteCmosSensor(0x42,0x10);
        CamWriteCmosSensor(0x47,GC0307SensorStatus.RegMode1);
        CamWriteCmosSensor(0x48,0xc3);
        CamWriteCmosSensor(0x8a,0x60);
        CamWriteCmosSensor(0x8b,0x60);
        CamWriteCmosSensor(0x8c,0x07);
        CamWriteCmosSensor(0x50,0x0c);
        CamWriteCmosSensor(0x77,0x80);
        CamWriteCmosSensor(0xa1,0x40);
        CamWriteCmosSensor(0x7a,0x00);
        CamWriteCmosSensor(0x78,0x00);
        CamWriteCmosSensor(0x79,0x00);
        CamWriteCmosSensor(0x7b,0x40);
        CamWriteCmosSensor(0x7c,0x00);
        break;            
      case CAM_EFFECT_ENC_SEPIA:
        GC0307SensorStatus.RegWB = GC0307SensorStatus.RegWB|0x39;
        CamWriteCmosSensor(0x41,GC0307SensorStatus.RegWB);
        CamWriteCmosSensor(0x40,0x7e);
        CamWriteCmosSensor(0x42,0x10);
        CamWriteCmosSensor(0x47,GC0307SensorStatus.RegMode1);
        CamWriteCmosSensor(0x48,0xc3);
        CamWriteCmosSensor(0x8a,0x60);
        CamWriteCmosSensor(0x8b,0x60);
        CamWriteCmosSensor(0x8c,0x07);
        CamWriteCmosSensor(0x50,0x0c);
        CamWriteCmosSensor(0x77,0x80);
        CamWriteCmosSensor(0xa1,0x40);
        CamWriteCmosSensor(0x7a,0x00);
        CamWriteCmosSensor(0x78,0xc0);
        CamWriteCmosSensor(0x79,0x20);
        CamWriteCmosSensor(0x7b,0x40);
        CamWriteCmosSensor(0x7c,0x00);
        break;            
      case CAM_EFFECT_ENC_COLORINV:
        GC0307SensorStatus.RegWB = GC0307SensorStatus.RegWB|0x69;
        CamWriteCmosSensor(0x41,GC0307SensorStatus.RegWB);
        CamWriteCmosSensor(0x40,0x7e);
        CamWriteCmosSensor(0x42,0x10);
        CamWriteCmosSensor(0x47,GC0307SensorStatus.RegMode1);
        CamWriteCmosSensor(0x48,0xc3);
        CamWriteCmosSensor(0x8a,0x60);
        CamWriteCmosSensor(0x8b,0x60);
        CamWriteCmosSensor(0x8c,0x07);
        CamWriteCmosSensor(0x50,0x0c);
        CamWriteCmosSensor(0x77,0x80);
        CamWriteCmosSensor(0xa1,0x40);
        CamWriteCmosSensor(0x7a,0x00);
        CamWriteCmosSensor(0x78,0x00);
        CamWriteCmosSensor(0x79,0x00);
        CamWriteCmosSensor(0x7b,0x40);
        CamWriteCmosSensor(0x7c,0x00);
        break;            
      case CAM_EFFECT_ENC_SEPIAGREEN:
        GC0307SensorStatus.RegWB = GC0307SensorStatus.RegWB|0x39;
        CamWriteCmosSensor(0x41,GC0307SensorStatus.RegWB);
        CamWriteCmosSensor(0x40,0x7e);
        CamWriteCmosSensor(0x42,0x10);
        CamWriteCmosSensor(0x47,GC0307SensorStatus.RegMode1);
        CamWriteCmosSensor(0x48,0xc3);
        CamWriteCmosSensor(0x8a,0x60);
        CamWriteCmosSensor(0x8b,0x60);
        CamWriteCmosSensor(0x8c,0x07);
        CamWriteCmosSensor(0x50,0x0c);
        CamWriteCmosSensor(0x77,0x80);
        CamWriteCmosSensor(0xa1,0x40);
        CamWriteCmosSensor(0x7a,0x00);
        CamWriteCmosSensor(0x78,0xc0);
        CamWriteCmosSensor(0x79,0xc0);
        CamWriteCmosSensor(0x7b,0x40);
        CamWriteCmosSensor(0x7c,0x00);
        break;            
      case CAM_EFFECT_ENC_SEPIABLUE:
        GC0307SensorStatus.RegWB = GC0307SensorStatus.RegWB|0x39;
        CamWriteCmosSensor(0x41,GC0307SensorStatus.RegWB);
        CamWriteCmosSensor(0x40,0x7e);
        CamWriteCmosSensor(0x42,0x10);
        CamWriteCmosSensor(0x47,GC0307SensorStatus.RegMode1);
        CamWriteCmosSensor(0x48,0xc3);
        CamWriteCmosSensor(0x8a,0x60);
        CamWriteCmosSensor(0x8b,0x60);
        CamWriteCmosSensor(0x8c,0x07);
        CamWriteCmosSensor(0x50,0x0c);
        CamWriteCmosSensor(0x77,0x80);
        CamWriteCmosSensor(0xa1,0x40);
        CamWriteCmosSensor(0x7a,0x00);
        CamWriteCmosSensor(0x78,0x70);
        CamWriteCmosSensor(0x79,0x00);
        CamWriteCmosSensor(0x7b,0x3f);
        CamWriteCmosSensor(0x7c,0xf5);
        break;       
      default:
        break;
    }
  }   
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    GC0307StillCaptureSize
*
* DESCRIPTION
*    This function get capture size
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
static MM_ERROR_CODE_ENUM GC0307StillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  const P_CAL_FEATURE_TYPE_ENUM_STRUCT CapSize = &Out->FeatureInfo.FeatureEnum;
  
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_GET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
    CapSize->IsSupport = KAL_TRUE;
    CapSize->ItemCount = 2;
    CapSize->SupportItem[0] = CAM_SIZE_WALLPAPER;
    CapSize->SupportItem[1] = CAM_SIZE_VGA;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    GC0307Banding
*
* DESCRIPTION
*    This function get Banding setting
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
static MM_ERROR_CODE_ENUM GC0307Banding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    GC0307SceneMode
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
static MM_ERROR_CODE_ENUM GC0307SceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
 
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    GC0307GetSensorInfo
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
void GC0307GetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT SensorInfo)
{
  SensorInfo->SensorId=GC0307_SENSOR_ID;
  SensorInfo->SensorIf=IMAGE_SENSOR_IF_PARALLEL;
  SensorInfo->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
  SensorInfo->PreviewHMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
  SensorInfo->PreviewVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
  SensorInfo->PreviewHVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;  
  SensorInfo->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
  SensorInfo->PixelClkInv=POLARITY_LOW;
  SensorInfo->HsyncPolarity=POLARITY_LOW;
  SensorInfo->VsyncPolarity=POLARITY_HIGH;
  SensorInfo->PreviewMclkFreq = GC0307_SYSCLK;
  SensorInfo->CaptureMclkFreq = GC0307_SYSCLK;
  SensorInfo->VideoMclkFreq = GC0307_SYSCLK;
  SensorInfo->PreviewWidth=GC0307_IMAGE_SENSOR_VGA_WIDTH;
  SensorInfo->PreviewHeight=GC0307_IMAGE_SENSOR_VGA_HEIGHT;
  SensorInfo->FullWidth=GC0307_IMAGE_SENSOR_VGA_WIDTH;
  SensorInfo->FullHeight=GC0307_IMAGE_SENSOR_VGA_HEIGHT;
  SensorInfo->SensorAfSupport=KAL_FALSE;
  SensorInfo->SensorFlashSupport=KAL_FALSE;
} /* GC0307GetSensorInfo() */

/*************************************************************************
* FUNCTION
*    GC0307DetectSensorId
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
static kal_uint32 GC0307DetectSensorId(void)
{
  MM_ERROR_CODE_ENUM GC0307SensorClose(void);
  kal_int8 GC0307PowerOn();
  kal_uint16 SensorId, AnotherSensorIdx;
  kal_int8 i, j;
  
  if (IMAGE_SENSOR_MAIN == GC0307SensorStatus.SensorIdx)
  {
    AnotherSensorIdx = IMAGE_SENSOR_SUB;
  }
  else
  {
    AnotherSensorIdx = IMAGE_SENSOR_MAIN;
  }
  for (i = 1; i >= 0; i--)
  {
    CamRstPinCtrl(AnotherSensorIdx, i);
    for (j = 1; j >= 0; j--)
    {
      CamPdnPinCtrl(AnotherSensorIdx, j);
      SensorId = GC0307PowerOn();
      GC0307SensorClose();
#ifdef GC0307_DEBUG
      kal_wap_trace(MOD_ENG,TRACE_INFO,"GC0307DetectSensorId:%x",SensorId);
#endif
      if (GC0307_SENSOR_ID == SensorId)
      {
        return GC0307_SENSOR_ID;
      }
    }
  }
  return MM_ERROR_SENSOR_READ_ID_FAIL;
}

/*************************************************************************
* FUNCTION
*    GC0307InitOperationPara
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
static void GC0307InitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT Para)
{
  Para->CaptureDelayFrame = 2; /* wait stable frame when sensor change mode (pre to cap) */
  Para->PreviewDelayFrame = 3; /* wait stable frame when sensor change mode (cap to pre) */
  Para->PreviewDisplayWaitFrame = 2; /* wait stable frame when sensor change mode (cap to pre) */
}

/*************************************************************************
* FUNCTION
*    GC0307AEEnable
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
static MM_ERROR_CODE_ENUM GC0307AEEnable(kal_bool Enable)
{
  if (Enable)
  {
    GC0307SensorStatus.RegWB = GC0307SensorStatus.RegWB | 0x08;
  }
  else
  {
    GC0307SensorStatus.RegWB = GC0307SensorStatus.RegWB & 0xF7;
  }
#ifdef GC0307_DEBUG
  kal_prompt_trace(MOD_ENG,"AEenable:%d",Enable);
#endif
  CamWriteCmosSensor(0x41,GC0307SensorStatus.RegWB);

  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    GC0307AWBEnable
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
static MM_ERROR_CODE_ENUM GC0307AWBEnable(kal_bool Enable)
{
  if (Enable)
  {
    GC0307SensorStatus.RegWB = GC0307SensorStatus.RegWB | 0x04;
  }
  else
  {
    GC0307SensorStatus.RegWB = GC0307SensorStatus.RegWB & 0xFB;
  }
#ifdef GC0307_DEBUG
  kal_prompt_trace(MOD_ENG,"AWBenable:%d",Enable);
#endif
  CamWriteCmosSensor(0x41,GC0307SensorStatus.RegWB);

  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    GC0307PowerOn
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
static kal_int8 GC0307PowerOn(void)
{
  kal_uint8 SensorId=0;
  
  /* PowerOn the sensor */
  CisModulePowerOn(GC0307SensorStatus.SensorIdx, KAL_TRUE); // Power On CIS Power 
  CameraSccbOpen(CAMERA_SCCB_SENSOR, GC0307_SLAVE_ADDR, CAMERA_SCCB_8BIT, CAMERA_SCCB_8BIT, 320);
  kal_sleep_task(2); // To wait for Stable Power

  /* set sensors chip enable pin to low to activate GC0307 */
  CamPdnPinCtrl(GC0307SensorStatus.SensorIdx, 0);
  
  SensorId=CamReadCmosSensor(0x00);
#ifdef GC0307_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "GC0307 Sensor ID %x",SensorId);
#endif
  return SensorId;
}

/*************************************************************************
* FUNCTION
*    GC0307Preview
*
* DESCRIPTION
*    This function set to preview mode
*
* PARAMETERS
*    id, In, Out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC0307Preview(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint8 XOffset = 4;
  kal_uint8 YOffset = 4; 

  GC0307SensorStatus.VideoMode = (Id == CAL_SCENARIO_VIDEO) ? KAL_TRUE : KAL_FALSE;   
  GC0307SensorStatus.NightMode = In->NightMode;
  GC0307SensorStatus.Banding = In->BandingFreq;
  GC0307SensorStatus.FrameRate = GC0307SensorStatus.VideoMode ? In->MaxVideoFrameRate : GC0307_MAX_CAMERA_FPS;

  GC0307SetMirror(In->ImageMirror);
  GC0307CalFps();

  Out->GrabStartX = XOffset;
  Out->GrabStartY = YOffset;
  Out->ExposureWindowWidth = GC0307_IMAGE_SENSOR_VGA_WIDTH - XOffset;
  Out->ExposureWindowHeight = GC0307_IMAGE_SENSOR_VGA_HEIGHT - YOffset;
}/* GC0307Preview */

/*************************************************************************
* FUNCTION
*    GC0307Capture
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
static void GC0307Capture(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint8 XOffset = 4;
  kal_uint8 YOffset = 4; 

  Out->GrabStartX = XOffset;
  Out->GrabStartY = YOffset;
  Out->ExposureWindowWidth = GC0307_IMAGE_SENSOR_VGA_WIDTH - XOffset;
  Out->ExposureWindowHeight = GC0307_IMAGE_SENSOR_VGA_HEIGHT - YOffset;
} /* GC0307Capture() */

/*************************************************************************
* FUNCTION
*    GC0307SensorOpen
*
* DESCRIPTION
*    This function read sensor id and init sensor
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
MM_ERROR_CODE_ENUM GC0307SensorOpen(void)
{
  kal_uint8 SensorId=0;

  SensorId = GC0307PowerOn();
  if(SensorId != GC0307_SENSOR_ID)
  return MM_ERROR_SENSOR_READ_ID_FAIL;

  GC0307InitialSetting();
  GC0307SensorStatus.VideoMode = KAL_FALSE;
  GC0307SensorStatus.NightMode = KAL_FALSE;
  GC0307SensorStatus.Banding = CAM_BANDING_50HZ;

  // Don't need to config dummy lines,please to change frame rate directly
#ifndef GC0307_USE_13M_MCLK
  GC0307SensorStatus.DummyPixels = 0x65; 
#else
  GC0307SensorStatus.DummyPixels = 0x6A; 
#endif
  GC0307SensorStatus.RegMode1 = 0x20;   //0x47 register backup
  GC0307SensorStatus.RegWB = 0x3f;      //0x41 register backup
  
  GC0307SensorStatus.Ev = CAM_EV_ZERO; 
  GC0307SensorStatus.Wb = CAM_WB_AUTO; 
  GC0307SensorStatus.Effect = CAM_EV_ZERO;
  return MM_ERROR_NONE;
} /* GC0307SensorOpen() */

/*************************************************************************
* FUNCTION
*    GC0307SensorFeatureCtrl
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
static MM_ERROR_CODE_ENUM GC0307SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_ENUM Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
  kal_uint32 TmpFrameRate;
  kal_bool FeatureValueTemp = KAL_FALSE;
#ifdef GC0307_DEBUG
  kal_wap_trace(MOD_ENG, TRACE_INFO, "GC0307 FeatureCtrl Id:%x",Id);
#endif
  if (Id >= CAL_FEATURE_WEBCAM_BEGIN && Id <= CAL_FEATURE_WEBCAM_END)
  {
    return GC0307WebcamFeatureCtrl(Id, In, Out, OutLen, RealOutLen);
  }
  switch (Id)
  {
   /* CAL Query and set series */
  case CAL_FEATURE_CAMERA_BRIGHTNESS:
  case CAL_FEATURE_CAMERA_EV_VALUE:
    ErrCode = GC0307EV(In, Out);
    break;
  case CAL_FEATURE_CAMERA_CONTRAST:
  case CAL_FEATURE_CAMERA_HUE:
  case CAL_FEATURE_CAMERA_SATURATION:
  case CAL_FEATURE_CAMERA_SHARPNESS:
  case CAL_FEATURE_CAMERA_GAMMA:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  case CAL_FEATURE_CAMERA_WB:
    ErrCode = GC0307WB(In, Out);
    break;
  case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
    ErrCode = GC0307Effect(In, Out);
    break;
  case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
    ErrCode = GC0307StillCaptureSize(In, Out);
    break;
  case CAL_FEATURE_CAMERA_BANDING_FREQ: /* move to preview */
    ErrCode = GC0307Banding(In, Out);
    break;
  case CAL_FEATURE_CAMERA_SCENE_MODE:
    ErrCode = GC0307SceneMode(KAL_TRUE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
    ErrCode = GC0307SceneMode(KAL_FALSE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_FLASH_MODE:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;

  /* Get Info series */
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
    GC0307GetSensorInfo(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = GC0307DetectSensorId();
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = GC0307SensorStatus.FrameRate * 10 / GC0307_FRAME_RATE_UNIT;
    break;
  case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
    GC0307InitOperationPara(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_DSC_SUPPORT_INFO:
    break;
  case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
    CamGetHWInfo(GC0307SensorStatus.SensorIdx, Out);
    break;
    
  /* Set Para series */
  case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
    CamPdnPinCtrl(GC0307SensorStatus.SensorIdx, 1);   
    break;
  case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
    GC0307SensorStatus.NvramData = &(((nvram_camera_para_struct *)In)->SENSOR);
    break;
  case IMAGE_SENSOR_FEATURE_VSYNC_HISR_INFORM_FRAME_TIME:
    TmpFrameRate = ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
    break;
  case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
    GC0307SensorStatus.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
    break;
  case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
    break;
  case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
    FeatureValueTemp = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue ? KAL_FALSE : KAL_TRUE;
    ErrCode = GC0307AEEnable(FeatureValueTemp);
    break;
  case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
    FeatureValueTemp = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue ? KAL_FALSE : KAL_TRUE;
    ErrCode = GC0307AWBEnable(FeatureValueTemp);
    break;
  default:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  }
  return ErrCode;
}

/*************************************************************************
* FUNCTION
*    GC0307SensorCtrl
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
static MM_ERROR_CODE_ENUM GC0307SensorCtrl(CAL_SCENARIO_ENUM Id, void *In, void *Out, kal_uint16 OutLen)
{
  switch (Id)
  {
    case CAL_SCENARIO_CAMERA_PREVIEW:
    case CAL_SCENARIO_VIDEO:
    case CAL_SCENARIO_WEBCAM_PREVIEW:
    case CAL_SCENARIO_WEBCAM_CAPTURE:
      GC0307Preview(Id, In, Out);
      break;
    case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
      GC0307Capture(Id, In, Out);
      break;
    default:
      break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    GC0307SensorClose
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
MM_ERROR_CODE_ENUM GC0307SensorClose(void)
{
  /* power down sensor */
  CamPdnPinCtrl(GC0307SensorStatus.SensorIdx, 1);
  CisModulePowerOn(GC0307SensorStatus.SensorIdx, KAL_FALSE);
  CameraSccbClose(CAMERA_SCCB_SENSOR);
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    GC0307SensorFunc
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
MM_ERROR_CODE_ENUM GC0307SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncGC0307=
  {
    GC0307SensorOpen,
    GC0307SensorFeatureCtrl,
    GC0307SensorCtrl,
    GC0307SensorClose,
  };
  
  *pfSensorFunc=&ImageSensorFuncGC0307;
  
  return MM_ERROR_NONE;
}/* GC0307SensorFunc() */
