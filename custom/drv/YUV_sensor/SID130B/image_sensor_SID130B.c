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
 *   image_sensor_SID130B.c
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
#include "cal_api.h"
/* Global Valuable */

#define DRV_ISP_YUV_BURST_MODE_SUPPORT


/* Global Valuable */
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
#define SID130B_SOURCE_CLK_Pre      52000000
#define SID130B_SOURCE_CLK_Cap      52000000
#else
#define SID130B_SOURCE_CLK_Pre      48000000//48000000
#define SID130B_SOURCE_CLK_Cap      69333333//69333333
#endif
#ifdef SID130B_MT6253_EVB
#define SID130B_PCLK_Pre        (41600000)
#define SID130B_PCLK_Cap        (41600000)
#else						
#define SID130B_PCLK_Pre        (SID130B_SOURCE_CLK_Pre/ SID130B_mclk_div_Pre)
#define SID130B_PCLK_Cap        (SID130B_SOURCE_CLK_Cap/ SID130B_mclk_div_Cap)
#endif
#define SID130B_DEBUG

static kal_uint32 SID130B_zoom_factor = 0; 
static kal_bool SID130B_g_bNightMode = KAL_FALSE;
static kal_uint8 SID130B_g_iBanding = CAM_BANDING_50HZ;
static kal_uint8 SID130B_HVMirror = IMAGE_SENSOR_MIRROR_NORMAL;
static kal_uint16 SID130B_PV_Dummy_Pixel = 0x1c; // for user customization//0x1c
static kal_uint16 SID130B_PV_Hblank = 0x1c;       //for calculating shutter step
static kal_uint16 SID130B_PV_Sutter_Step = 0x96;       //Back up for mode change switch factor
static kal_uint16 SID130B_outdoor_condition = 0x63;       //Back up for outdoor condition
static kal_bool SID130B_Video_Mode = KAL_FALSE;
static kal_uint8 SID130B_mclk_div_Pre = 1;//11
static kal_uint8 SID130B_mclk_div_Cap = 1;//11
//static kal_bool SID130B_Mode_change = KAL_FALSE;
static kal_uint16 SID130B_Min_Fps_Normal; 
static kal_uint16 SID130B_Min_Fps_Night; 
static kal_uint16 SID130B_Min_Fps_Video = 30 * SID130B_FRAME_RATE_UNIT;
static kal_uint8 SID130B_Control = 0x00;

/* MAX/MIN Explosure Lines Used By AE Algorithm */
// must be defined but not referenced by YUV driver
kal_uint16 SID130B_MAX_EXPOSURE_LINES = 1000;  
kal_uint8  SID130B_MIN_EXPOSURE_LINES = 1; 



#ifdef SID130B_DEBUG
// for driver current
kal_uint8 pll=0xa2;
kal_uint8 pllset=0x03;//0x30//03//10
kal_uint8 bb_driver_current=1;//33
kal_uint8 sensor_current = 0x0f;//8//0c
#endif


static struct
{
  IMAGE_SENSOR_INDEX_ENUM SensorIdx;
  sensor_data_struct *NvramData;
  kal_uint16 Fps;
  kal_bool BypassAe;
  kal_bool BypassAwb;
  
} SID130BSensor;

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

static void SID130B_set_page(kal_uint8 iPage)
{    
    CamWriteCmosSensor(0x00,iPage);
}

static void SID130B_set_outdoor_fix_gain_conditon(kal_uint8 para)
{    
	SID130B_set_page(0x02); 
	CamWriteCmosSensor(0x27,para);
	CamWriteCmosSensor(0x28,para);
}
/*************************************************************************
* FUNCTION
*    SID130B_half_adjust
*
* DESCRIPTION
*    This function dividend / divisor and use round-up.
*
* PARAMETERS
*    dividend
*    divisor
*
* RETURNS
*    [dividend / divisor]
*
* LOCAL AFFECTED
*
*************************************************************************/
__inline static kal_uint32 SID130B_half_adjust(kal_uint32 dividend, kal_uint32 divisor)
{
  return (dividend * 2 + divisor) / (divisor * 2); /* that is [dividend / divisor + 0.5]*/
}
   
   
   /*************************************************************************
   * FUNCTION
   *   SID130B_PV_Set_Shutter_Step
   *
   * DESCRIPTION
   *   This function is to calculate & set shutter step register .
   *
   *************************************************************************/
   static void SID130B_PV_Set_Shutter_Step(void)
   {	   
	   const kal_uint8 banding = SID130B_g_iBanding == CAM_BANDING_50HZ ? SID130B_NUM_50HZ : SID130B_NUM_60HZ;
	   //const kal_uint16 shutter_step = SID130B_half_adjust(SID130B_PCLK / 2, (SID130B_PV_Hblank + SID130B_PV_PERIOD_PIXEL_NUMS) * banding);
	   const kal_uint16 shutter_step = SID130B_PCLK_Pre/ 2 / (SID130B_PV_Hblank + SID130B_PV_PERIOD_PIXEL_NUMS) / banding;
	   //kal_uint16 shutter_step = SID130B_PCLK_Pre/ 2 / (SID130B_PV_Hblank + SID130B_PV_PERIOD_PIXEL_NUMS) / banding;
   
	   ASSERT(shutter_step <= 0xFF);  //haiyong modify
	   //if(shutter_step > 0xff)
		   //shutter_step=0xfe;
	   /* Block 1:0x34	shutter step*/
	   SID130B_set_page(1);
	   CamWriteCmosSensor(0x34,shutter_step);
	   
	   //ASSERT(shutter_step>2);
	   //SID130B_set_page(2);
	   
	   //CamWriteCmosSensor(0x27,shutter_step-2);   
	   //CamWriteCmosSensor(0x28,shutter_step+2);
	   
	   SID130B_PV_Sutter_Step = shutter_step;
   }/* SID130B_PV_Set_Shutter_Step */
   
   
   /*************************************************************************
   * FUNCTION
   *   SID130B_Set_Frame_Count
   *
   * DESCRIPTION
   *   This function is to set frame count register .
   *
   *************************************************************************/
   static void SID130B_Set_Frame_Count(void)
   {	
	   kal_uint16 Frame_Count,min_fps = 100;
	   kal_uint8 banding = SID130B_g_iBanding == CAM_BANDING_50HZ ? SID130B_NUM_50HZ : SID130B_NUM_60HZ;
   
	   if(SID130B_Min_Fps_Night > SID130B_MAX_CAMERA_FPS)
		   SID130B_Min_Fps_Night = SID130B_MAX_CAMERA_FPS;
   
	   if(SID130B_Min_Fps_Normal > SID130B_MAX_CAMERA_FPS)
		   SID130B_Min_Fps_Normal = SID130B_MAX_CAMERA_FPS;
	   if(  SID130B_Video_Mode == KAL_TRUE)
	       min_fps = SID130B_Min_Fps_Video;
	   else
	       min_fps = SID130B_g_bNightMode ? SID130B_Min_Fps_Night : SID130B_Min_Fps_Normal;
	   Frame_Count = banding * SID130B_FRAME_RATE_UNIT / min_fps;
	   /*Block 01: 0x11  Max shutter step,for Min frame rate */
	   SID130B_set_page(1);
	   CamWriteCmosSensor(0x11,Frame_Count&0xFF);	
   }/* SID130B_Set_Frame_Count */



/*************************************************************************
* FUNCTION
*   SID130B_Config_PV_Blank
*
* DESCRIPTION
*   This function is to set Blank size for Preview mode .
*
* PARAMETERS
*   iBlank: target HBlank size
*      iHz: banding frequency
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void SID130B_Config_PV_Blank(kal_uint16 hblank,kal_uint16 vblank)
{    
	/********************************************	
	*   preview mode 0x24 - 0x27 
	*   page 0
	*	 0x24  [7:4]:HBANK[11:8]; 0x20	[3:0]:VBANK[11:8]
	*  0x25 HBANK[7:0]
	*  0x27 VBANK[7:0]
	*  page 1
	*  0x34	shutter step
	********************************************/
    ASSERT(hblank <= SID130B_BLANK_REGISTER_LIMITATION && vblank <= SID130B_BLANK_REGISTER_LIMITATION);
    SID130B_set_page(0);
    CamWriteCmosSensor(0x24,((hblank>>4)&0xF0)|((vblank>>8)&0x0F));
    CamWriteCmosSensor(0x25,hblank & 0xFF);
    CamWriteCmosSensor(0x27,vblank & 0xFF);
    SID130B_PV_Set_Shutter_Step();
}   /* SID130B_Config_PV_Blank */



/*************************************************************************
* FUNCTION
*   SID130B_Config_Cap_Blank
*
* DESCRIPTION
*   This function is to set Blank size for Preview mode .
*
* PARAMETERS
*   iBlank: target HBlank size
*      iHz: banding frequency
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void SID130B_Config_Cap_Blank(kal_uint16 hblank,kal_uint16 vblank)
{    
	kal_uint16 P2CFactor;
	kal_uint32 CapOutdoor;
	const kal_uint8 banding = SID130B_g_iBanding == CAM_BANDING_50HZ ? SID130B_NUM_50HZ : SID130B_NUM_60HZ;
	const kal_uint16 cap_shutter_step = SID130B_half_adjust(SID130B_PCLK_Cap/ 2, (hblank + SID130B_CAP_PERIOD_PIXEL_NUMS) * banding);
	
	/********************************************
	  *   still mode 0x20 - 0x23 *
	  * 	page 0
	  * 	0x20  [7:4]:HBANK[11:8]; 0x20  [3:0]:VBANK[11:8]
	  *  0x21 HBANK[7:0]
	  *  0x23 VBANK[7:0]
	  *  page 1
	  *  0x35  shutter step
	  *  0x36  preview to still adjust factor
	  ********************************************/
    ASSERT(hblank <= SID130B_BLANK_REGISTER_LIMITATION && vblank <= SID130B_BLANK_REGISTER_LIMITATION);
    SID130B_set_page(0);
    CamWriteCmosSensor(0x20,((hblank>>4)&0xF0)|((vblank>>8)&0x0F));
    CamWriteCmosSensor(0x21,hblank & 0xFF);
    CamWriteCmosSensor(0x23,vblank & 0xFF);

	ASSERT(cap_shutter_step <= 0xFF);    
	/* Block 1:0x35  shutter step*/
	SID130B_set_page(1);
	CamWriteCmosSensor(0x35,cap_shutter_step);
	
	P2CFactor  = cap_shutter_step * 64 / SID130B_PV_Sutter_Step;
	CamWriteCmosSensor(0x36,P2CFactor & 0xFF);  
	CapOutdoor = SID130B_outdoor_condition * cap_shutter_step / SID130B_PV_Sutter_Step;
	SID130B_set_outdoor_fix_gain_conditon(CapOutdoor);
}   /* SID130B_Config_Cap_Blank */




/*************************************************************************
* FUNCTION
*    SID130B_cal_fps
*
* DESCRIPTION
*    This function calculate & set frame rate and fix frame rate when video mode
*    MUST BE INVOKED AFTER SIM120C_preview() !!!
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
static void SID130B_cal_fps(void)
{
    kal_int16 Line_length,Dummy_Line;
    kal_uint16 max_fps = 300;

    Line_length = SID130B_PV_Dummy_Pixel + SID130B_PV_PERIOD_PIXEL_NUMS; 

	{
		kal_uint32 clk = SID130B_PCLK_Pre;
	//	kal_wap_trace(MOD_ENG,TRACE_INFO, "SID130B_PCLK_Pre:%d",clk);
	}
	if (SID130B_Video_Mode == KAL_TRUE)
	{		
		max_fps =  SID130B_Min_Fps_Video;
	}
	else
	{		
		max_fps = SID130B_MAX_CAMERA_FPS;
	}
	
    Dummy_Line = SID130B_PCLK_Pre * SID130B_FRAME_RATE_UNIT / (2 * Line_length * max_fps) - SID130B_PV_PERIOD_LINE_NUMS; 
    if(Dummy_Line > SID130B_BLANK_REGISTER_LIMITATION)
    {
        Dummy_Line = SID130B_BLANK_REGISTER_LIMITATION;
        Line_length = SID130B_PCLK_Pre * SID130B_FRAME_RATE_UNIT / (2 * (Dummy_Line + SID130B_PV_PERIOD_LINE_NUMS) * max_fps);
    }	
	else if(Dummy_Line < 0)
	{
		max_fps = SID130B_PCLK_Pre * SID130B_FRAME_RATE_UNIT / (2 * Line_length * SID130B_PV_PERIOD_LINE_NUMS);
	}
    SID130B_PV_Hblank = Line_length -  SID130B_PV_PERIOD_PIXEL_NUMS;
    SID130B_Config_PV_Blank((SID130B_PV_Hblank > 0) ? SID130B_PV_Hblank : 0, (Dummy_Line > 0) ? Dummy_Line : 0);
    
}




/*************************************************************************
* FUNCTION
*   SID130B_SID130B_HVMirror
*
*  DESCRIPTION
*    This function config the mirror and flip of the image sensor.
* 
*  PARAMETERS	
*     image_mirror :  mirror parameter   
* 
*  RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void SID130B_SID130B_HVMirror(kal_uint8 image_mirror)
{
    kal_uint8 iHV_Mirror;
    
    if(SID130B_HVMirror == image_mirror)
        return;
    
    SID130B_HVMirror = image_mirror;
	//SID130B_set_page(0x00);
    iHV_Mirror = (SID130B_Control & 0xFC);  
    switch (image_mirror) 
    {
        case IMAGE_SENSOR_MIRROR_NORMAL:
            iHV_Mirror |= 0x00;
            break;
        case IMAGE_SENSOR_MIRROR_H:
            iHV_Mirror |= 0x01;
            break;
        case IMAGE_SENSOR_MIRROR_V:
            iHV_Mirror |= 0x02;
            break;
        case IMAGE_SENSOR_MIRROR_HV:
            iHV_Mirror |= 0x03;
            break;
        default:
            iHV_Mirror |= 0x00;
    }
    //CamWriteCmosSensor(0x04, iHV_Mirror);
    SID130B_Control = iHV_Mirror;
}   /* SID130B_SID130B_HVMirror */



/*************************************************************************
* FUNCTION
*   SID130B_FixFrameRate
*
* DESCRIPTION
*   This function fix the frame rate of image sensor.
*
*************************************************************************/
static void SID130B_FixFrameRate(kal_bool bEnable)
{
    if(bEnable == KAL_TRUE)
    {   //fix frame rate
        SID130B_Control |= 0xC0;
        //SID130B_set_page(0);
        //CamWriteCmosSensor(0x04,SID130B_Control);
    }
    else
    {        
        SID130B_Control &= 0x3F;
        //SID130B_set_page(0);
        //CamWriteCmosSensor(0x04,SID130B_Control);

    }
}   /* SID130B_FixFrameRate */

void SID130B_set_dummy(kal_uint16 pixels, kal_uint16 lines)
{
    kal_uint8 temp_reg1, temp_reg2;
    kal_uint16 temp_reg;

    /*Very Important: The line_length must < 0x1000, it is to say 0x3028 must < 0x10, or else the sensor will crash*/
    /*The dummy_pixel must < 2156*/
    if (pixels >= 2156) 
        pixels = 2155;
    if (pixels < 0x100)
    {
        CamWriteCmosSensor(0x302c,(pixels&0xFF)); //EXHTS[7:0]
        temp_reg = SID130B_FULL_PERIOD_PIXEL_NUMS;
        CamWriteCmosSensor(0x3029,(temp_reg&0xFF));         //H_length[7:0]
        CamWriteCmosSensor(0x3028,((temp_reg&0xFF00)>>8));  //H_length[15:8]
    }
    else
    {
        CamWriteCmosSensor(0x302c,0);
        temp_reg = pixels + SID130B_FULL_PERIOD_PIXEL_NUMS;
        CamWriteCmosSensor(0x3029,(temp_reg&0xFF));         //H_length[7:0]
        CamWriteCmosSensor(0x3028,((temp_reg&0xFF00)>>8));  //H_length[15:8]
    }

    // read out and + line
    temp_reg1 = CamReadCmosSensor(0x302B);    // VTS[b7~b0]
    temp_reg2 = CamReadCmosSensor(0x302A);    // VTS[b15~b8]
    temp_reg = (temp_reg1 & 0xFF) | (temp_reg2 << 8);

    temp_reg += lines;

    CamWriteCmosSensor(0x302B,(temp_reg&0xFF));         //VTS[7:0]
    CamWriteCmosSensor(0x302A,((temp_reg&0xFF00)>>8));  //VTS[15:8]
}    /* SID130B_set_dummy */



static void SID130B_YUV_sensor_initial_setting(void)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef SID130B_MT6253_EVB
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#ifdef SID130B_DEBUG
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
#endif	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef SID130B_MT6253_EVB
/* under construction !*/
#else
#ifdef SID130B_DEBUG
/* under construction !*/
#else
/* under construction !*/
#endif	
#endif	
/* under construction !*/
/* under construction !*/
#else
SID130B_set_page(0x00); 
CamWriteCmosSensor(0x04, 0x00); //Select Group B
CamWriteCmosSensor(0x05, 0x0F); //Select Group A :UXGA Output
CamWriteCmosSensor(0x06, 0x8E); //Select Group B :SVGA Output                
// Vendor recommended value ### Don't change ###

CamWriteCmosSensor(0x09, 0x11); 
CamWriteCmosSensor(0x0A, 0x03); 
CamWriteCmosSensor(0x08, 0xa2); //PLL on
 
CamWriteCmosSensor(0x10, 0x27);//17
CamWriteCmosSensor(0x11, 0x03);//02
CamWriteCmosSensor(0x12, 0x89); //0x8a 2010.02.08//86
//CamWriteCmosSensor(0x13, 0x1a);
CamWriteCmosSensor(0x14, 0x07);//27
CamWriteCmosSensor(0x15, 0x22);//22
CamWriteCmosSensor(0x16, 0x40);//40
CamWriteCmosSensor(0x17, 0xCF); //cb
CamWriteCmosSensor(0x18, 0x38); 
CamWriteCmosSensor(0x40, 0x0F);
CamWriteCmosSensor(0x41, 0x17);
CamWriteCmosSensor(0x42, 0x52);   
             
//Flicker - 50Hz  - Still mode       48MHz MCLK    
CamWriteCmosSensor(0x20, 0x00);
CamWriteCmosSensor(0x21, 0x02);
CamWriteCmosSensor(0x23, 0x51);               

//Flicker - 50Hz - Preview mode 48MHz MCLK
CamWriteCmosSensor(0x24, 0x00);
CamWriteCmosSensor(0x25, 0x10);
CamWriteCmosSensor(0x27, 0x2A); 

SID130B_set_page(0x01); 
CamWriteCmosSensor(0x34, 0xC8); 
CamWriteCmosSensor(0x35, 0x78);
CamWriteCmosSensor(0x36, 0x26);
               
//AE Block 
CamWriteCmosSensor(0x10, 0x00);
CamWriteCmosSensor(0x11, 0x0C);//0A 100423
CamWriteCmosSensor(0x12, 0x78);
CamWriteCmosSensor(0x13, 0x78);
CamWriteCmosSensor(0x14, 0x78);
CamWriteCmosSensor(0x17, 0xC4);                
CamWriteCmosSensor(0x19, 0x00);//0x8E
CamWriteCmosSensor(0x1A, 0x00);//0x0A
CamWriteCmosSensor(0x1C, 0x03);                   
CamWriteCmosSensor(0x40, 0x73); //Max Again //anyuan 0x73
CamWriteCmosSensor(0x41, 0x20);
CamWriteCmosSensor(0x42, 0x20);
CamWriteCmosSensor(0x43, 0x00);
CamWriteCmosSensor(0x44, 0x00);
CamWriteCmosSensor(0x45, 0x01);
CamWriteCmosSensor(0x46, 0x0C);
CamWriteCmosSensor(0x47, 0x11);
CamWriteCmosSensor(0x48, 0x15);
CamWriteCmosSensor(0x49, 0x17);
CamWriteCmosSensor(0x4A, 0x1A);
CamWriteCmosSensor(0x4B, 0x1C);
CamWriteCmosSensor(0x4C, 0x1E);
CamWriteCmosSensor(0x4D, 0x1E);
CamWriteCmosSensor(0x4E, 0x0F);
CamWriteCmosSensor(0x4F, 0x09);
CamWriteCmosSensor(0x50, 0x07);
CamWriteCmosSensor(0x51, 0x05);
CamWriteCmosSensor(0x52, 0x04);
CamWriteCmosSensor(0x53, 0x03);
CamWriteCmosSensor(0x54, 0x02);
CamWriteCmosSensor(0x55, 0x01); 

// NORMAL mode AE metering : window setting change
CamWriteCmosSensor(0x60, 0xFF);
CamWriteCmosSensor(0x61, 0xFF);                            
CamWriteCmosSensor(0x62, 0xFF);
CamWriteCmosSensor(0x63, 0xFF);
CamWriteCmosSensor(0x64, 0xFF);
CamWriteCmosSensor(0x65, 0xFF);               
CamWriteCmosSensor(0x66, 0x00);
CamWriteCmosSensor(0x67, 0x50);                            
CamWriteCmosSensor(0x68, 0x50);
CamWriteCmosSensor(0x69, 0x50);
CamWriteCmosSensor(0x6A, 0x50);
CamWriteCmosSensor(0x6B, 0x00);
CamWriteCmosSensor(0x6C, 0x06); 
                        
CamWriteCmosSensor(0x70, 0xc4);
CamWriteCmosSensor(0x73, 0x22);
CamWriteCmosSensor(0x74, 0x07);
CamWriteCmosSensor(0x77, 0xd0);
CamWriteCmosSensor(0x78, 0xd8);                                                            

//AWB Block
SID130B_set_page(0x02); 
CamWriteCmosSensor(0x10, 0xD3);
CamWriteCmosSensor(0x11, 0x11);
CamWriteCmosSensor(0x13, 0x7F);            //# AWB taget Cr
CamWriteCmosSensor(0x14, 0x80);  //AWB taget Cb                          
CamWriteCmosSensor(0x15, 0xEE);
CamWriteCmosSensor(0x16, 0x80);
CamWriteCmosSensor(0x17, 0xD0);
CamWriteCmosSensor(0x18, 0x80);
CamWriteCmosSensor(0x19, 0x98);
CamWriteCmosSensor(0x1A, 0x68);
CamWriteCmosSensor(0x1B, 0x98);
CamWriteCmosSensor(0x1C, 0x68);
CamWriteCmosSensor(0x1D, 0x8C);
CamWriteCmosSensor(0x1E, 0x74);
CamWriteCmosSensor(0x20, 0xF0);
CamWriteCmosSensor(0x21, 0x84);
CamWriteCmosSensor(0x22, 0xB4);
CamWriteCmosSensor(0x23, 0x20);
CamWriteCmosSensor(0x25, 0x20);
CamWriteCmosSensor(0x26, 0x05);
CamWriteCmosSensor(0x27, 0x63); // for outdoor fix gain enter
CamWriteCmosSensor(0x28, 0x63); // for outdoor fix gain quit
CamWriteCmosSensor(0x29, 0xAB); 
CamWriteCmosSensor(0x2A, 0x9D);
CamWriteCmosSensor(0x30, 0x00);
CamWriteCmosSensor(0x31, 0x10); 
CamWriteCmosSensor(0x32, 0x00); 
CamWriteCmosSensor(0x33, 0x10); 
CamWriteCmosSensor(0x34, 0x06); 
CamWriteCmosSensor(0x35, 0x30); 
CamWriteCmosSensor(0x36, 0x04); 
CamWriteCmosSensor(0x37, 0xa0); 
CamWriteCmosSensor(0x40, 0x01); 
CamWriteCmosSensor(0x41, 0x04); 
CamWriteCmosSensor(0x42, 0x08); 
CamWriteCmosSensor(0x43, 0x10); 
CamWriteCmosSensor(0x44, 0x13); 
CamWriteCmosSensor(0x45, 0x6b); 
CamWriteCmosSensor(0x46, 0x82); 

//CMA change  -D65~A
CamWriteCmosSensor(0x53, 0x8a); //AWB R Gain for D30 to D20
CamWriteCmosSensor(0x54, 0xb6); //AWB B Gain for D30 to D20
CamWriteCmosSensor(0x55, 0x8d); //AWB R Gain for D20 to D30
CamWriteCmosSensor(0x56, 0xb5); //AWB B Gain for D20 to D30
CamWriteCmosSensor(0x57, 0xa0); //AWB R Gain for D65 to D30
CamWriteCmosSensor(0x58, 0x88); //AWB B Gain for D65 to D30
CamWriteCmosSensor(0x59, 0xa0); //AWB R Gain for D30 to D65
CamWriteCmosSensor(0x5A, 0xa8); //AWB B Gain for D30 to D65
                
CamWriteCmosSensor(0x64, 0x00); //T1~T2 RGAIN
CamWriteCmosSensor(0x65, 0x00); 
CamWriteCmosSensor(0x66, 0x00); //T3~T4 RGAIN
CamWriteCmosSensor(0x67, 0x00); 
CamWriteCmosSensor(0x68, 0xA5); //T5~T6 RGAIN
CamWriteCmosSensor(0x69, 0xB4); 
CamWriteCmosSensor(0x6A, 0xB3); //T7~T8 RGAIN
CamWriteCmosSensor(0x6B, 0xAC); 
CamWriteCmosSensor(0x6C, 0xB7); //T9~T10 RGAIN
CamWriteCmosSensor(0x6D, 0x98); 
CamWriteCmosSensor(0x6E, 0xBA); //T11~T12 RGAIN
CamWriteCmosSensor(0x6F, 0x90); 
CamWriteCmosSensor(0x70, 0xBF); //T13~T14 RGAIN
CamWriteCmosSensor(0x71, 0x9B); 
CamWriteCmosSensor(0x72, 0xCE); //T15~T16 RGAIN
CamWriteCmosSensor(0x73, 0x8C); 
CamWriteCmosSensor(0x74, 0x7F); //T1 White RGAIN BOT
CamWriteCmosSensor(0x75, 0x8C); //T1 White RGAIN TOP
CamWriteCmosSensor(0x76, 0xAD); //T1 White BGAIN BOT
CamWriteCmosSensor(0x77, 0xBA); //T1 White BGAIN TOP
CamWriteCmosSensor(0x78, 0x8F); //T2 White RGAIN BOT
CamWriteCmosSensor(0x79, 0x9A); //T2 White RGAIN TOP
CamWriteCmosSensor(0x7A, 0xA3); //T2 White BGAIN BOT
CamWriteCmosSensor(0x7B, 0xAC); //T2 White BGAIN TOP
CamWriteCmosSensor(0x7C, 0xA0); //T3 White RGAIN BOT
CamWriteCmosSensor(0x7D, 0xA9); //T3 White RGAIN TOP
CamWriteCmosSensor(0x7E, 0x95); //T3 White BGAIN BOT
CamWriteCmosSensor(0x7F, 0xAC); //T3 White BGAIN TOP
CamWriteCmosSensor(0x80, 0xAD); //T4 White RGAIN BOT
CamWriteCmosSensor(0x81, 0xBC); //T4 White RGAIN TOP
CamWriteCmosSensor(0x82, 0x98); //T4 White BGAIN BOT
CamWriteCmosSensor(0x83, 0xA4); //T4 White BGAIN TOP
CamWriteCmosSensor(0x84, 0x00); //T5 White RGAIN BOT
CamWriteCmosSensor(0x85, 0x00); //T5 White RGAIN TOP   

CamWriteCmosSensor(0x86, 0x00); //T5 White BGAIN BOT
CamWriteCmosSensor(0x87, 0x00); //T5 White BGAIN TOP
CamWriteCmosSensor(0x88, 0xC9); //T6 White RGAIN BOT
CamWriteCmosSensor(0x89, 0xD5); //T6 White RGAIN TOP
CamWriteCmosSensor(0x8A, 0x70); //T6 White BGAIN BOT
CamWriteCmosSensor(0x8B, 0x7B); //T6 White BGAIN TOP
CamWriteCmosSensor(0x8C, 0xD0); //T7 White RGAIN BOT
CamWriteCmosSensor(0x8D, 0xE5); //T7 White RGAIN TOP
CamWriteCmosSensor(0x8E, 0x58); //T7 White BGAIN BOT
CamWriteCmosSensor(0x8F, 0x70); //T7 White BGAIN TOP
CamWriteCmosSensor(0xB4, 0x05); 
CamWriteCmosSensor(0xB5, 0x0F); 
CamWriteCmosSensor(0xB6, 0x06); 
CamWriteCmosSensor(0xB7, 0x06); 
CamWriteCmosSensor(0xB8, 0x40); 
CamWriteCmosSensor(0xB9, 0x10); 
CamWriteCmosSensor(0xBA, 0x06); 

//IDP
SID130B_set_page(0x03); 
CamWriteCmosSensor(0x10, 0xFF);
CamWriteCmosSensor(0x11, 0x1D);//1d
CamWriteCmosSensor(0x12, 0x1D);
CamWriteCmosSensor(0x13, 0xFF);
CamWriteCmosSensor(0x14, 0x00);
CamWriteCmosSensor(0x15, 0xc0);

//DPC
CamWriteCmosSensor(0x30, 0x88); //DPCNRCTRL
CamWriteCmosSensor(0x31, 0x08); //10 100423 DPTHR @ AGAIN = 00 
CamWriteCmosSensor(0x32, 0x08); //0C 100423 DPTHR @ AGAIN = 20
CamWriteCmosSensor(0x33, 0x04); //08 100423 DPTHR @ AGAIN = 40
CamWriteCmosSensor(0x34, 0x00); //04 100423 DPTHR @ AGAIN = 60
CamWriteCmosSensor(0x35, 0x00); //DPTHR @ AGAIN = 80
CamWriteCmosSensor(0x36, 0x44); //DPTHVRNG
CamWriteCmosSensor(0x37, 0x66); //DPNUMBER
CamWriteCmosSensor(0x38, 0x00); //0x00             # NRTHR0 @ AGAIN = 00
CamWriteCmosSensor(0x39, 0x18); //0x0C             # NRTHR1 @ AGAIN = 20
CamWriteCmosSensor(0x3A, 0x40); //0x18             # NRTHR2 @ AGAIN = 40
CamWriteCmosSensor(0x3B, 0x80); //0x30             # NRTHR3 @ AGAIN = 60
CamWriteCmosSensor(0x3C, 0xFF); //80 100423                   NRTHR4 @ AGAIN = 80
CamWriteCmosSensor(0x3D, 0x04); //NRTHVRNG0 @ AGAIN = 00
CamWriteCmosSensor(0x3E, 0x0c); //NRTHVRNG1 @ AGAIN = 20
CamWriteCmosSensor(0x3F, 0x20); //NRTHVRNG2 @ AGAIN = 40
CamWriteCmosSensor(0x40, 0x80); //NRTHVRNG3 @ AGAIN = 60
CamWriteCmosSensor(0x41, 0x80); //NRTHVRNG4 @ AGAIN = 80
CamWriteCmosSensor(0x42, 0x10); //NRTHVRNGMAX
CamWriteCmosSensor(0x43, 0x80); //40 100423 NRTHRWGT
CamWriteCmosSensor(0x44, 0x40); //BASELVL
CamWriteCmosSensor(0x45, 0x05); //06 100423 SHUMAXH
CamWriteCmosSensor(0x46, 0xdc); //40 100423 SHUMAXL
CamWriteCmosSensor(0x47, 0x30); //ILLUMITHDRK

//Shading
CamWriteCmosSensor(0x50, 0x20); //RXSHDL
CamWriteCmosSensor(0x51, 0x32); //RXSHDR
CamWriteCmosSensor(0x52, 0x40); //RXSHDT
CamWriteCmosSensor(0x53, 0x2a); //RXSHDB      
CamWriteCmosSensor(0x54, 0x1b); //GXSHDL
CamWriteCmosSensor(0x55, 0x19); //GXSHDR
CamWriteCmosSensor(0x56, 0x20); //GXSHDT
CamWriteCmosSensor(0x57, 0x15); //GXSHDB      
CamWriteCmosSensor(0x58, 0x1b); //GXSHDL
CamWriteCmosSensor(0x59, 0x19); //GXSHDR
CamWriteCmosSensor(0x5A, 0x20); //GXSHDT
CamWriteCmosSensor(0x5B, 0x15); //GXSHDB      
CamWriteCmosSensor(0x5C, 0x33); //BXSHDL
CamWriteCmosSensor(0x5D, 0x42); //BXSHDR
CamWriteCmosSensor(0x5E, 0x49); //BXSHDT
CamWriteCmosSensor(0x5F, 0x30); //BXSHDB      
CamWriteCmosSensor(0x60, 0x32); //#SHDCNTH(X/Y)
CamWriteCmosSensor(0x61, 0x20); //#SHDCNTX
CamWriteCmosSensor(0x62, 0x67); //#SHDCNTY 
CamWriteCmosSensor(0x63, 0x8A); 
CamWriteCmosSensor(0x66, 0x76);            
CamWriteCmosSensor(0x6B, 0x01);
CamWriteCmosSensor(0x6C, 0x22);
CamWriteCmosSensor(0x6D, 0x23);
CamWriteCmosSensor(0x6E, 0x55);
CamWriteCmosSensor(0x6F, 0x77);
CamWriteCmosSensor(0x70, 0x65);
CamWriteCmosSensor(0x71, 0x01);
CamWriteCmosSensor(0x72, 0x23);
CamWriteCmosSensor(0x73, 0x33);
CamWriteCmosSensor(0x74, 0x45);
CamWriteCmosSensor(0x75, 0x55);
CamWriteCmosSensor(0x76, 0x55);
CamWriteCmosSensor(0x77, 0x01);
CamWriteCmosSensor(0x78, 0x23);
CamWriteCmosSensor(0x79, 0x33);
CamWriteCmosSensor(0x7A, 0x45);
CamWriteCmosSensor(0x7B, 0x55);
CamWriteCmosSensor(0x7C, 0x55);
CamWriteCmosSensor(0x7D, 0x00);
CamWriteCmosSensor(0x7E, 0x01);
CamWriteCmosSensor(0x7F, 0x11);
CamWriteCmosSensor(0x80, 0x33);
CamWriteCmosSensor(0x81, 0x33);
CamWriteCmosSensor(0x82, 0x22);
CamWriteCmosSensor(0x83, 0x18);//14 100423
CamWriteCmosSensor(0x84, 0x0f);

//CamWriteCmosSensor(0x94, 0x06);
//CamWriteCmosSensor(0x95, 0x40);
//CamWriteCmosSensor(0x96, 0x04);
//CamWriteCmosSensor(0x97, 0xb0);

//Interpolation
CamWriteCmosSensor(0xA0, 0x2F);
CamWriteCmosSensor(0xA1, 0x04);
CamWriteCmosSensor(0xA2, 0xB7);
CamWriteCmosSensor(0xA3, 0xB7);
CamWriteCmosSensor(0xA4, 0x08);
CamWriteCmosSensor(0xA5, 0xFF);
CamWriteCmosSensor(0xA6, 0x00);
CamWriteCmosSensor(0xA7, 0xFF);
CamWriteCmosSensor(0xA8, 0x00);
CamWriteCmosSensor(0xA9, 0x00);
CamWriteCmosSensor(0xAA, 0x00);
CamWriteCmosSensor(0xAB, 0x00);
CamWriteCmosSensor(0xAC, 0x60);
CamWriteCmosSensor(0xAD, 0x18);
CamWriteCmosSensor(0xAE, 0x10);
CamWriteCmosSensor(0xAF, 0x20);
CamWriteCmosSensor(0xB0, 0x08);
CamWriteCmosSensor(0xB1, 0x00);

//Color Matrix for D65
CamWriteCmosSensor(0xC0, 0xaF);// CMASB D20 or D30 or Dark Condition Color Matrix Selection
CamWriteCmosSensor(0xC1, 0x66);
CamWriteCmosSensor(0xC2, 0xd4);
CamWriteCmosSensor(0xC3, 0x06);
CamWriteCmosSensor(0xC4, 0xF0);
CamWriteCmosSensor(0xC5, 0x5A);
CamWriteCmosSensor(0xC6, 0xF6);
CamWriteCmosSensor(0xC7, 0xF9);
CamWriteCmosSensor(0xC8, 0xBF);
CamWriteCmosSensor(0xC9, 0x88);
CamWriteCmosSensor(0xCA, 0x00);
CamWriteCmosSensor(0xCB, 0x00);
CamWriteCmosSensor(0xCC, 0x00);
CamWriteCmosSensor(0xCD, 0x00);
CamWriteCmosSensor(0xCE, 0x00);

//Color Matrix for CWF
CamWriteCmosSensor(0xD0, 0x2F);
CamWriteCmosSensor(0xD1, 0x71);
CamWriteCmosSensor(0xD2, 0xb6);
CamWriteCmosSensor(0xD3, 0x19);
CamWriteCmosSensor(0xD4, 0xE8);
CamWriteCmosSensor(0xD5, 0x5a);
CamWriteCmosSensor(0xD6, 0xFe);
CamWriteCmosSensor(0xD7, 0xe8);
CamWriteCmosSensor(0xD8, 0xae);
CamWriteCmosSensor(0xD9, 0xaa);
CamWriteCmosSensor(0xDA, 0x00);
CamWriteCmosSensor(0xDB, 0x00);
CamWriteCmosSensor(0xDC, 0x00);
CamWriteCmosSensor(0xDD, 0x00);
CamWriteCmosSensor(0xDE, 0x00);

//Color Matrix for A
CamWriteCmosSensor(0xE0, 0x2F);
CamWriteCmosSensor(0xE1, 0x5C);
CamWriteCmosSensor(0xE2, 0xDD);
CamWriteCmosSensor(0xE3, 0x06);
CamWriteCmosSensor(0xE4, 0xE0);
CamWriteCmosSensor(0xE5, 0x69);
CamWriteCmosSensor(0xE6, 0xF6);
CamWriteCmosSensor(0xE7, 0xE5);
CamWriteCmosSensor(0xE8, 0xAB);
CamWriteCmosSensor(0xE9, 0xAE);
CamWriteCmosSensor(0xEA, 0x6A);
CamWriteCmosSensor(0xEB, 0x01);
CamWriteCmosSensor(0xEC, 0x2D);
CamWriteCmosSensor(0xED, 0xEE);
CamWriteCmosSensor(0xEE, 0x04);

//IDP 2
SID130B_set_page(0x04);             
//Gamma - R
CamWriteCmosSensor(0x10, 0x00);                
CamWriteCmosSensor(0x11, 0x05);
CamWriteCmosSensor(0x12, 0x0c);
CamWriteCmosSensor(0x13, 0x1d);
CamWriteCmosSensor(0x14, 0x45);
CamWriteCmosSensor(0x15, 0x64);
CamWriteCmosSensor(0x16, 0x7c);
CamWriteCmosSensor(0x17, 0x8e);
CamWriteCmosSensor(0x18, 0xa0);
CamWriteCmosSensor(0x19, 0xae);
CamWriteCmosSensor(0x1A, 0xbb);
CamWriteCmosSensor(0x1B, 0xd0);
CamWriteCmosSensor(0x1C, 0xe2);
CamWriteCmosSensor(0x1D, 0xf2);
CamWriteCmosSensor(0x1E, 0xf9);
CamWriteCmosSensor(0x1F, 0xFF);
                                                                                                                
//Gamma - G                                      
CamWriteCmosSensor(0x20, 0x00);
CamWriteCmosSensor(0x21, 0x05);
CamWriteCmosSensor(0x22, 0x0c);
CamWriteCmosSensor(0x23, 0x1d);
CamWriteCmosSensor(0x24, 0x45);
CamWriteCmosSensor(0x25, 0x64);
CamWriteCmosSensor(0x26, 0x7c);
CamWriteCmosSensor(0x27, 0x8e);
CamWriteCmosSensor(0x28, 0xa0);
CamWriteCmosSensor(0x29, 0xae);
CamWriteCmosSensor(0x2A, 0xbb);
CamWriteCmosSensor(0x2B, 0xd0);
CamWriteCmosSensor(0x2C, 0xe2);
CamWriteCmosSensor(0x2D, 0xf2);
CamWriteCmosSensor(0x2E, 0xf9);
CamWriteCmosSensor(0x2F, 0xFF);
                                                                                               
//Gamma - B                                      
CamWriteCmosSensor(0x30, 0x00);
CamWriteCmosSensor(0x31, 0x05);
CamWriteCmosSensor(0x32, 0x0c);
CamWriteCmosSensor(0x33, 0x1d);
CamWriteCmosSensor(0x34, 0x45);
CamWriteCmosSensor(0x35, 0x64);
CamWriteCmosSensor(0x36, 0x7c);
CamWriteCmosSensor(0x37, 0x8e);
CamWriteCmosSensor(0x38, 0xa0);
CamWriteCmosSensor(0x39, 0xae);
CamWriteCmosSensor(0x3A, 0xbb);
CamWriteCmosSensor(0x3B, 0xd0);
CamWriteCmosSensor(0x3C, 0xe2);
CamWriteCmosSensor(0x3D, 0xf2);
CamWriteCmosSensor(0x3E, 0xf9);
CamWriteCmosSensor(0x3F, 0xFF);
                                                                                                
//CSC                                                                    
CamWriteCmosSensor(0x60, 0x33);
CamWriteCmosSensor(0x61, 0x20);
CamWriteCmosSensor(0x62, 0xE4);
CamWriteCmosSensor(0x63, 0xFA);
CamWriteCmosSensor(0x64, 0x13);
CamWriteCmosSensor(0x65, 0x25);
CamWriteCmosSensor(0x66, 0x07);
CamWriteCmosSensor(0x67, 0xF5);
CamWriteCmosSensor(0x68, 0xEA);
CamWriteCmosSensor(0x69, 0x20);
CamWriteCmosSensor(0x6A, 0xC8);
CamWriteCmosSensor(0x6B, 0xC4);
CamWriteCmosSensor(0x6C, 0x84);
CamWriteCmosSensor(0x6D, 0x04);
CamWriteCmosSensor(0x6E, 0x0C);
CamWriteCmosSensor(0x6F, 0x00);
                                                                                                
//Edge                                                                  
CamWriteCmosSensor(0x80, 0xA2);
CamWriteCmosSensor(0x81, 0x10);
CamWriteCmosSensor(0x82, 0x14);
CamWriteCmosSensor(0x83, 0x04);
CamWriteCmosSensor(0x84, 0x18);
CamWriteCmosSensor(0x85, 0x06);
CamWriteCmosSensor(0x86, 0x00);
CamWriteCmosSensor(0x87, 0x04);
CamWriteCmosSensor(0x88, 0x18);
CamWriteCmosSensor(0x89, 0x06);
CamWriteCmosSensor(0x8a, 0x00);
CamWriteCmosSensor(0x8b, 0x24);
CamWriteCmosSensor(0x8c, 0x24);
CamWriteCmosSensor(0X90, 0x16);
CamWriteCmosSensor(0x91, 0x03);
CamWriteCmosSensor(0x93, 0xE0);

//Cr/Cb Coring
CamWriteCmosSensor(0x94, 0x1b);//1b
CamWriteCmosSensor(0x95, 0x25);//1b
CamWriteCmosSensor(0x96, 0x4C);
CamWriteCmosSensor(0x97, 0x76); 
CamWriteCmosSensor(0x98, 0x30);//100423
CamWriteCmosSensor(0x9A, 0xF5);
CamWriteCmosSensor(0xA1, 0x08);
CamWriteCmosSensor(0xA2, 0x10);
CamWriteCmosSensor(0xA3, 0x20);//16 100423
CamWriteCmosSensor(0xA4, 0x40);//20 100423
CamWriteCmosSensor(0xA5, 0xff);//30 100423
CamWriteCmosSensor(0xA6, 0xA0);
CamWriteCmosSensor(0xA7, 0x05);//09 100423
CamWriteCmosSensor(0xA8, 0xdc);//60 100423           
CamWriteCmosSensor(0xA9, 0x20);
CamWriteCmosSensor(0xAA, 0x60);          
CamWriteCmosSensor(0xAC, 0xFF);
CamWriteCmosSensor(0xAD, 0x09);
CamWriteCmosSensor(0xAE, 0x96);
CamWriteCmosSensor(0xAF, 0x18);
CamWriteCmosSensor(0xB2, 0x30); //50 100423 color suppression start level            //0x40
CamWriteCmosSensor(0xB3, 0x14); //[7:4]color suppression slope //0x33                                                                                                                                                    //[3:0]color suppression end gain
//CamWriteCmosSensor(0xB6, 0x08); //Brightness Control

//Color Saturation
CamWriteCmosSensor(0xBC, 0x15); //0x14
CamWriteCmosSensor(0xBD, 0x15);
CamWriteCmosSensor(0xBE, 0x16);
CamWriteCmosSensor(0xBF, 0x16); 
CamWriteCmosSensor(0xc0, 0x10);
CamWriteCmosSensor(0xc1, 0x10);
CamWriteCmosSensor(0xc2, 0x14);
CamWriteCmosSensor(0xc3, 0x14);
CamWriteCmosSensor(0xc4, 0x14);
CamWriteCmosSensor(0xc5, 0x14);
CamWriteCmosSensor(0xc6, 0x01);
CamWriteCmosSensor(0xc7, 0x01);
CamWriteCmosSensor(0xc8, 0x01);
CamWriteCmosSensor(0xc9, 0x01);
CamWriteCmosSensor(0xca, 0x01);
CamWriteCmosSensor(0xcb, 0x01);
CamWriteCmosSensor(0xcc, 0x04);
CamWriteCmosSensor(0xcd, 0x3f);
CamWriteCmosSensor(0xce, 0x01);            
                                                                                               
//IDP 3                                                  
SID130B_set_page(0x05); 
                                                                                               
//Memory                                                           
CamWriteCmosSensor(0x40, 0x15);
CamWriteCmosSensor(0x41, 0x28);
CamWriteCmosSensor(0x42, 0x04);
CamWriteCmosSensor(0x43, 0x15);
CamWriteCmosSensor(0x44, 0x28);
CamWriteCmosSensor(0x45, 0x04);
CamWriteCmosSensor(0x46, 0x15);
CamWriteCmosSensor(0x47, 0x28);
CamWriteCmosSensor(0x48, 0x04);
                                                                                               
//Knee                                                                 
CamWriteCmosSensor(0x90, 0xCA); //
CamWriteCmosSensor(0x91, 0x81); //knee function selection/knee point H
CamWriteCmosSensor(0x92, 0x00); //knee point L
CamWriteCmosSensor(0x93, 0x50); //Knee gain
CamWriteCmosSensor(0x94, 0x41); //[6:4]knee start H/[2:0]Knee END H
CamWriteCmosSensor(0x95, 0x7E); //knee start L
CamWriteCmosSensor(0x96, 0x48); //knee END L
                                                                                                
//ADG                                                                   
CamWriteCmosSensor(0x99, 0xC0);
CamWriteCmosSensor(0xA0, 0x10);
CamWriteCmosSensor(0xA1, 0x22);
CamWriteCmosSensor(0xA2, 0x36);
CamWriteCmosSensor(0xA3, 0x49);
CamWriteCmosSensor(0xA4, 0x5D);
CamWriteCmosSensor(0xA5, 0x70);
CamWriteCmosSensor(0xA6, 0x82);
CamWriteCmosSensor(0xA7, 0x94);
CamWriteCmosSensor(0xA8, 0xA5);
CamWriteCmosSensor(0xA9, 0xB5);
CamWriteCmosSensor(0xAA, 0xC3);
CamWriteCmosSensor(0xAB, 0xD1);
CamWriteCmosSensor(0xAC, 0xDE);
CamWriteCmosSensor(0xAD, 0xEA);
CamWriteCmosSensor(0xAE, 0xF5);
CamWriteCmosSensor(0xAF, 0xFF);
                                                                                                
//YXGMA                                                             
CamWriteCmosSensor(0xB0, 0xc0); //YGMACTRL
CamWriteCmosSensor(0xB1, 0x04); //YGMASLOP
CamWriteCmosSensor(0xB8, 0x0f); //DRKTHR1
CamWriteCmosSensor(0xB9, 0x10); //DRKTHR2
//CamWriteCmosSensor(0xBA,    0x38); //DRKTHR3
//CamWriteCmosSensor(0xBB,    0x39); //DRKTHR4
CamWriteCmosSensor(0xC0, 0x03);
CamWriteCmosSensor(0xC1, 0x0E);
CamWriteCmosSensor(0xC2, 0x16);
CamWriteCmosSensor(0xC3, 0x24);
CamWriteCmosSensor(0xC4, 0x3F);
CamWriteCmosSensor(0xC5, 0x56);
CamWriteCmosSensor(0xC6, 0x6A);
CamWriteCmosSensor(0xC7, 0x7C);
CamWriteCmosSensor(0xC8, 0x8C);
CamWriteCmosSensor(0xC9, 0x98);
CamWriteCmosSensor(0xCA, 0xA2);
CamWriteCmosSensor(0xCB, 0xB8);
CamWriteCmosSensor(0xCC, 0xCD);
CamWriteCmosSensor(0xCD, 0xE2);
CamWriteCmosSensor(0xCE, 0xF0);
CamWriteCmosSensor(0xCF, 0xFF);

CamWriteCmosSensor(0xe0, 0x04);
CamWriteCmosSensor(0xe1, 0x88);
CamWriteCmosSensor(0xe2, 0x09);
CamWriteCmosSensor(0xe3, 0x0c);
CamWriteCmosSensor(0xe4, 0x11);
CamWriteCmosSensor(0xe5, 0x16);

CamWriteCmosSensor(0xe6, 0x1b);
CamWriteCmosSensor(0xe7, 0x24);
CamWriteCmosSensor(0xe8, 0x30);
CamWriteCmosSensor(0xe9, 0x3e);           

//Sensor on
SID130B_set_page(0x00);
CamWriteCmosSensor(0x03, (sensor_current << 4) | 0x5);

SID130B_set_page(0x01); 
CamWriteCmosSensor(0x10, 0xc4);


#endif
} /* SID130B_YUV_sensor_initial_setting */




/*****************************************************************************
 * FUNCTION
 *  SID130BWriteReg
 * DESCRIPTION
 *  This function set the register of SID130B.
 * PARAMETERS
 *  Addr       [IN]        the register index of SID130B
 *  Para       [IN]        setting parameter of the specified register of SID130B
 * RETURNS
 *  void
 *****************************************************************************/
static void SID130BWriteReg(kal_uint32 Addr, kal_uint32 Para)
{
  CamWriteCmosSensor(Addr,Para);
}

/*****************************************************************************
 * FUNCTION
 *  SID130BReadReg
 * DESCRIPTION
 *  This function read parameter of specified register from SID130B.
 * PARAMETERS
 *  Addr       [IN]        the register index of SID130B
 * RETURNS
 *  the data that read from SID130B
 *****************************************************************************/
static kal_uint32 SID130BReadReg(kal_uint32 Addr)
{
  return CamReadCmosSensor(Addr);
}


/*************************************************************************
* FUNCTION
*    SID130BEV
*
* DESCRIPTION
*    SID130B EV setting.
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
static MM_ERROR_CODE_ENUM SID130BEV(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATRUE_CTRL_STRUCT Out)
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
    kal_uint8 iEvTemp= In->FeatureSetValue;
#ifdef SID130B_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "EV:%d", In->FeatureSetValue);
#endif
	SID130B_set_page(1);
    switch (iEvTemp)
    {
    case CAM_EV_NEG_4_3: 
		CamWriteCmosSensor(0xb6, 0xa0);
	    break;
    case CAM_EV_NEG_3_3: 
		CamWriteCmosSensor(0xb6, 0x98);
        break;
    case CAM_EV_NEG_2_3: 
		CamWriteCmosSensor(0xb6, 0x90);
        break;
    case CAM_EV_NEG_1_3: 
		CamWriteCmosSensor(0xb6, 0x88);
        break;
    case CAM_EV_ZERO:    
		CamWriteCmosSensor(0xb6, 0x00);
        break;
    case CAM_EV_POS_1_3: 
		CamWriteCmosSensor(0xb6, 0x08);
        break;
    case CAM_EV_POS_2_3: 
		CamWriteCmosSensor(0xb6, 0x10);
        break;
    case CAM_EV_POS_3_3: 
		CamWriteCmosSensor(0xb6, 0x18);
        break;
    case CAM_EV_POS_4_3: 
		CamWriteCmosSensor(0xb6, 0x20);
        break;
    default: break;
    }
  }
  return MM_ERROR_NONE;
}
static MM_ERROR_CODE_ENUM SID130BContrast(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT Contrast = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    Contrast->IsSupport = KAL_TRUE;
    Contrast->ItemCount = 3;
    Contrast->SupportItem[0] = CAM_CONTRAST_HIGH;
    Contrast->SupportItem[1] = CAM_CONTRAST_MEDIUM;
    Contrast->SupportItem[2] = CAM_CONTRAST_LOW;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    kal_uint8 Data;
	SID130B_set_page(4);
    switch (In->FeatureSetValue)
    {
    case CAM_CONTRAST_HIGH:   Data = 0x12; break;
    case CAM_CONTRAST_MEDIUM: Data = 0x10; break;
    case CAM_CONTRAST_LOW:    Data = 0x0e; break;
    default:
      return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
    CamWriteCmosSensor(0xba, Data); /* manual Y offset */
    CamWriteCmosSensor(0xbb, Data); /* Y Contrast Gain(0x20 = 1x) */
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SID130BWB
*
* DESCRIPTION
*    SID130B WB setting.
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
static MM_ERROR_CODE_ENUM SID130BWB(P_CAL_FEATRUE_CTRL_STRUCT In, P_CAL_FEATRUE_CTRL_STRUCT Out)
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
    kal_uint8 WBTemp = In->FeatureSetValue;
#ifdef SID130B_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"WB:%d",WBTemp);
#endif
	SID130B_set_page(2);
    switch (WBTemp)
    {
    case CAM_WB_AUTO: /* enable AWB */
		/* CAM_WB_AUTO mode should not update R/G/B gains */
		CamWriteCmosSensor(0x10, 0xD3);
      break;
    case CAM_WB_CLOUD:
		CamWriteCmosSensor(0x10, 0x00);  // disable AWB
		CamWriteCmosSensor(0x50, 0xD0);
		CamWriteCmosSensor(0x51, 0x88);
      break;
    case CAM_WB_DAYLIGHT:
		CamWriteCmosSensor(0x10, 0x00);  // disable AWB
		CamWriteCmosSensor(0x50, 0xC2);
		CamWriteCmosSensor(0x51, 0x9E);
      break;
    case CAM_WB_INCANDESCENCE:
		CamWriteCmosSensor(0x10, 0x00);	// disable AWB
		CamWriteCmosSensor(0x50, 0x98);
		CamWriteCmosSensor(0x51, 0xC8);

      break;
    case CAM_WB_FLUORESCENT:
		CamWriteCmosSensor(0x10, 0x00);  // disable AWB
		CamWriteCmosSensor(0x50, 0xAA);
		CamWriteCmosSensor(0x51, 0xBE);
      break;
    case CAM_WB_TUNGSTEN:
		CamWriteCmosSensor(0x10, 0x00);  // disable AWB
		CamWriteCmosSensor(0x50, 0x90);
		CamWriteCmosSensor(0x51, 0xC0);
      break;
    default:
      break;
    }
  }
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    SID130BEffect
*
* DESCRIPTION
*    SID130B Effect setting.
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
static MM_ERROR_CODE_ENUM SID130BEffect(P_CAL_FEATRUE_CTRL_STRUCT In, P_CAL_FEATRUE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    P_CAL_FEATURE_TYPE_ENUM_STRUCT EffectPara = &Out->FeatureInfo.FeatureEnum;
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION | CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    EffectPara->IsSupport = KAL_TRUE;
    EffectPara->ItemCount = 9;
    EffectPara->SupportItem[0] = CAM_EFFECT_ENC_NORMAL;
    EffectPara->SupportItem[1] = CAM_EFFECT_ENC_GRAYSCALE;
    EffectPara->SupportItem[2] = CAM_EFFECT_ENC_SEPIA;
    EffectPara->SupportItem[3] = CAM_EFFECT_ENC_SEPIAGREEN;
    EffectPara->SupportItem[4] = CAM_EFFECT_ENC_SEPIABLUE;
    EffectPara->SupportItem[5] = CAM_EFFECT_ENC_COLORINV;
    EffectPara->SupportItem[6] = CAM_EFFECT_ENC_GRAYINV;
    EffectPara->SupportItem[7] = CAM_EFFECT_ENC_EMBOSSMENT;
    EffectPara->SupportItem[8] = CAM_EFFECT_ENC_SKETCH;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    kal_uint8 EffectTemp = In->FeatureSetValue;
#ifdef SID130B_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"Effect:%d",EffectTemp);
#endif
	SID130B_set_page(4);
    switch (EffectTemp)
    {
    case CAM_EFFECT_ENC_NORMAL:
		CamWriteCmosSensor(0xD9, 0x00);
      break;
    case CAM_EFFECT_ENC_GRAYSCALE:
		CamWriteCmosSensor(0xD9, 0x40);
      break;
    case CAM_EFFECT_ENC_SEPIA:
		CamWriteCmosSensor(0xD9, 0x80);
		CamWriteCmosSensor(0xDA, 0x60);
		CamWriteCmosSensor(0xDB, 0xA0);
      break;
    case CAM_EFFECT_ENC_SEPIAGREEN:
		CamWriteCmosSensor(0xD9, 0x80);
		CamWriteCmosSensor(0xDA, 0x50);
		CamWriteCmosSensor(0xDB, 0x50);
      break;
    case CAM_EFFECT_ENC_SEPIABLUE:
		CamWriteCmosSensor(0xD9, 0x80);
		CamWriteCmosSensor(0xDA, 0xC0);
		CamWriteCmosSensor(0xDB, 0x60);
      break;
    case CAM_EFFECT_ENC_COLORINV:
        CamWriteCmosSensor(0xD9, 0x10);
      break;
    case CAM_EFFECT_ENC_GRAYINV:
        CamWriteCmosSensor(0xD9, 0x20);
      break;
    case CAM_EFFECT_ENC_EMBOSSMENT:
        CamWriteCmosSensor(0xD9, 0x08);
      break;
    case CAM_EFFECT_ENC_SKETCH:
        CamWriteCmosSensor(0xD9, 0x04);
      break;
    default:
      break;
    }
  }   
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SID130BStillCaptureSize
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
static MM_ERROR_CODE_ENUM SID130BStillCaptureSize(P_CAL_FEATRUE_CTRL_STRUCT In, P_CAL_FEATRUE_CTRL_STRUCT Out)
{
  const P_CAL_FEATURE_TYPE_ENUM_STRUCT CapSize = &Out->FeatureInfo.FeatureEnum;
  
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_GET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
    CapSize->IsSupport = KAL_TRUE;
	CapSize->ItemCount = 5;
	CapSize->SupportItem[0] = CAM_SIZE_WALLPAPER;
	CapSize->SupportItem[1] = CAM_SIZE_VGA;
	CapSize->SupportItem[2] = CAM_SIZE_1M;
	CapSize->SupportItem[3] = CAM_SIZE_2M;//
	CapSize->SupportItem[4] = CAM_SIZE_3M;//

  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SID130BBanding
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
MM_ERROR_CODE_ENUM SID130BBanding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
kal_uint8 BandingTemp = In->FeatureSetValue;
#ifdef SID130B_DEBUG
kal_wap_trace(MOD_ENG,TRACE_INFO,"Banding:%d",In->FeatureSetValue);
#endif
if(SID130B_g_iBanding == BandingTemp)
			return MM_ERROR_NONE;		
SID130B_g_iBanding = BandingTemp;
SID130B_PV_Set_Shutter_Step();
SID130B_Set_Frame_Count();
}
return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    SID130BGetSensorInfo
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
static void SID130BGetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT Info)
{
  Info->SensorId = SID130B_SENSOR_ID;
  //Info->ResetActiveHigh = KAL_FALSE;
  //Info->PowerOnActiveHigh = KAL_TRUE; //High means sensor work
  Info->SensorIf = IMAGE_SENSOR_IF_PARALLEL;
  Info->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PreviewHMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PreviewVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PreviewHVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;  
  Info->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PixelClkPolarity = POLARITY_LOW;
  Info->HsyncPolarity = POLARITY_LOW;//POLARITY_HIGH;
  Info->VsyncPolarity = POLARITY_LOW;
  //Info->DrivingCurrent = ISP_DRIVING_8MA;
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
  Info->PreviewMclkFreq = 26000000;
  Info->CaptureMclkFreq = 26000000;
  Info->VideoMclkFreq = 26000000;
#else
  Info->PreviewMclkFreq = 24000000;
  Info->CaptureMclkFreq = 24000000;
  Info->VideoMclkFreq = 24000000;
#endif
  Info->PreviewWidth = SID130B_IMAGE_SENSOR_PV_WIDTH;
  Info->PreviewHeight = SID130B_IMAGE_SENSOR_PV_HEIGHT;
  Info->FullWidth = SID130B_IMAGE_SENSOR_FULL_WIDTH;
  Info->FullHeight = SID130B_IMAGE_SENSOR_FULL_HEIGHT;
  Info->SensorAfSupport = KAL_FALSE;
  Info->SensorFlashSupport = KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*    SID130BDetectSensorId
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
static kal_uint32 SID130BDetectSensorId(void)
{
  MM_ERROR_CODE_ENUM SID130BSensorClose(void);
  kal_uint16 SID130BPowerOn();
  kal_uint16 sensorId, AnotherSensorIdx;
  kal_int8 i, j;
  
  if (IMAGE_SENSOR_MAIN == SID130BSensor.SensorIdx)
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
      sensorId = SID130BPowerOn();
      SID130BSensorClose();
#ifdef SID130B_DEBUG
      kal_wap_trace(MOD_ENG,TRACE_INFO,"SID130BDetectSensorId:%x",sensorId);
#endif
      if (SID130B_SENSOR_ID == sensorId)
      {
        return SID130B_SENSOR_ID;
      }
    }
  }
  return MM_ERROR_SENSOR_READ_ID_FAIL;
}

/*************************************************************************
* FUNCTION
*    SID130BInitOperationPara
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
static void SID130BInitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT Para)
{
  Para->CaptureDelayFrame = 2; /* wait stable frame when sensor change mode (pre to cap) */
  Para->PreviewDelayFrame = 2; /* wait stable frame when sensor change mode (cap to pre) */
  Para->PreviewDisplayWaitFrame = 2; /* wait stable frame when sensor change mode (cap to pre) */
}

/*************************************************************************
* FUNCTION
*    SID130BDscSupportInfo
*
* DESCRIPTION
*    This function get dsc support Info
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
static void SID130BDscSupportInfo(P_IMAGE_SENSOR_GET_DSC_SUPPORT_INFO_STRUCT Info)
{
#if defined(DRV_ISP_6238_SERIES)
  //kal_mem_cpy(Info, &SID130B_dsc_support_info, sizeof(camcorder_info_struct));
#endif
}

/*************************************************************************
* FUNCTION
*    SID130BAEEnable
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
static MM_ERROR_CODE_ENUM SID130BAEEnable(kal_bool Enable)
{
  kal_uint8 AETemp;
  if (SID130BSensor.BypassAe )
	  {
		  Enable = KAL_FALSE;
	  }

  if (Enable)
  {
    AETemp = 0x80;
  }
  else
  {
    AETemp = 0x00;
  }
#ifdef SID130B_DEBUG
  kal_prompt_trace(MOD_ENG,"AEenable:%d",Enable);
#endif
  CamWriteCmosSensor(0x40, AETemp);

  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SID130BAWBEnable
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
static MM_ERROR_CODE_ENUM SID130BAWBEnable(kal_bool Enable)
{
  kal_uint8 AWBTemp;
  if (SID130BSensor.BypassAwb )
		{
			Enable = KAL_FALSE;
		}

  if (Enable)
  {
    AWBTemp = 0xC3;
  }
  else
  {
    AWBTemp = 0x00;
  }
#ifdef SID130B_DEBUG
  kal_prompt_trace(MOD_ENG,"AWBenable:%d",Enable);
#endif
  CamWriteCmosSensor(0x60, AWBTemp);

  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SID130BNightMode
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
static void SID130BNightMode(kal_bool Enable)
	{	 
#ifdef    SID130B_DEBUG
		kal_wap_trace(MOD_ENG,TRACE_INFO, "NightMode %d",Enable);
#endif
	
//		if((SID130B_g_bNightMode == Enable) && (SID130B_Mode_change == KAL_FALSE))
//		return;
		
//		SID130B_Mode_change = KAL_FALSE; 
	
		if ( SID130B_Video_Mode == KAL_FALSE)// camera mode
		{
			if (SID130B_g_bNightMode == KAL_TRUE)
			{	/* camera night mode */
#ifdef SID130B_DEBUG
				kal_wap_trace(MOD_ENG,TRACE_INFO, "camera night mode");
#endif
				//SID130B_set_page(1);
				/* Max Analog Gain Value @ Shutter step = Max Shutter step */
				/*0x58 : 7X; 0x60 : 8X; 0x68 : 10X; 0x70 : 12X; 0x80 : 16X; 0xff : 32X;*/
				///CamWriteCmosSensor(0x40,0x70); 
				SID130B_set_page(4);
				CamWriteCmosSensor(0xb6,0x0c); //Brightness Control 0x11
				//CamWriteCmosSensor(0xb2,0x70); //Color Suppression Change Start State	0x17			
				//CamWriteCmosSensor(0xb3,0x10); //Slope
			}
			else
			{	/* camera normal mode */
#ifdef SID130B_DEBUG
				kal_wap_trace(MOD_ENG,TRACE_INFO, "camera normal mode");
#endif
				//SID130B_set_page(1);
				//CamWriteCmosSensor(0x40,0x70); //Max Analog Gain Value @ Shutter step = Max Shutter step  0x7D
				SID130B_set_page(4);
				CamWriteCmosSensor(0xb6,0x04); //Brightness Control 0x11
				//CamWriteCmosSensor(0xb2,0x30); //Color Suppression Change Start State	0x17			
				//CamWriteCmosSensor(0xb3,0x10); //Slope
			}
			SID130B_Set_Frame_Count();
		}	 
		else //video mode
		{
		    SID130B_Video_Mode =KAL_TRUE;
	        SID130B_FixFrameRate(KAL_TRUE);  
			SID130B_set_page(4);
			CamWriteCmosSensor(0xb6,0x08); //Brightness Control 0x11  
			if (SID130B_g_bNightMode== KAL_TRUE)
			{	/* video night mode */
#ifdef SID130B_DEBUG
				kal_wap_trace(MOD_ENG,TRACE_INFO, "video night mode");
#endif						
	            SID130B_Min_Fps_Video = SID130BSensor.Fps;
			}
			else
			{	/* video normal mode */
#ifdef SID130B_DEBUG
				kal_wap_trace(MOD_ENG,TRACE_INFO, "video normal mode");
#endif			
				SID130B_Min_Fps_Video = SID130BSensor.Fps;
			}
		}
		SID130B_cal_fps();	  
        SID130B_Set_Frame_Count();   
	}

static MM_ERROR_CODE_ENUM SID130BSceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    SID130BNightMode(Enable);
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SID130BPowerOn
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
static kal_uint16 SID130BPowerOn(void)
{
  kal_uint16 sensor_id = 0;
  /* PowerOn the sensor */
  CisModulePowerOn(SID130BSensor.SensorIdx, KAL_TRUE);
  CameraSccbOpen(CAMERA_SCCB_SENSOR, SID130B_WRITE_ID, CAMERA_SCCB_8BIT, CAMERA_SCCB_8BIT, 300);
  kal_sleep_task(1);  /* delay for power stable */
  
  /* set sensors chip enable pin to low to activate SID130B */
  CamPdnPinCtrl(SID130BSensor.SensorIdx, 1);
  kal_sleep_task(1);  /* delay for Chip state,10 + 2 mclk*/
  
  /* Reset the sensor */
  
  kal_wap_trace(MOD_ENG,TRACE_INFO,"sid130B sensor id %x",sensor_id);
  CamRstPinCtrl(SID130BSensor.SensorIdx, 1);
  CamRstPinCtrl(SID130BSensor.SensorIdx, 0);
  kal_sleep_task(1);  /* delay for Chip Reset,10 + 2 mclk*/
  CamRstPinCtrl(SID130BSensor.SensorIdx, 1);
  /* delay for stable sensor */  
   kal_sleep_task(10);  /* delay for stable sensor I2C */
  
  /* Read Sensor ID  */
#ifdef SID130B_DEBUG
  kal_wap_trace(MOD_ENG, TRACE_INFO, "SID130B Sensor ID: %x ",CamReadCmosSensor(0x01));
#endif
  /* Read Sensor ID  */
	  SID130B_set_page(0);
	  //sensor_id = CamReadCmosSensor(0x01)<<8 | CamReadCmosSensor(0x02);
	  sensor_id = CamReadCmosSensor(0x01) ;
  return sensor_id;
}

/*************************************************************************
* FUNCTION
*    SID130BPreview
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
static void SID130BPreview(CAL_SCENARIO_ENUM id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint8 StartX = 0, StartY = 2;
  //kal_bool	SID130B_Mode_temp = KAL_FALSE;

#ifdef SID130B_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "SID130B Preview");
#endif

  SID130B_g_iBanding = In->BandingFreq;
  SID130B_g_bNightMode = In->NightMode;
  //SID130B_Mode_temp = KAL_FALSE;
  SID130B_Min_Fps_Normal = 10 * SID130B_FRAME_RATE_UNIT;//normal 10fps night 5 fps 
  SID130B_Min_Fps_Night = SID130B_Min_Fps_Normal >> 1; 
  SID130B_Control = SID130B_Control & 0xEF | 0x00;  
  SID130B_FixFrameRate(KAL_FALSE);
	switch (id)
  {
    case CAL_SCENARIO_VIDEO:
      SID130B_Video_Mode = KAL_TRUE;
      SID130BSensor.Fps = In->MaxVideoFrameRate;
      break;
    default:
	  SID130B_Video_Mode = KAL_FALSE;
		//SID130B_Mode_temp = KAL_FALSE;
  }
	//if ( SID130B_Mode_temp !=  SID130B_Video_Mode)
	  //{
		   //SID130B_Video_Mode =  SID130B_Mode_temp;
		   //SID130B_Mode_change = KAL_TRUE;		 
	  //}
	
	SID130B_SID130B_HVMirror(In->ImageMirror);
	SID130B_set_outdoor_fix_gain_conditon(SID130B_outdoor_condition);
	//use group_B register
	SID130B_set_page(0);
	CamWriteCmosSensor(0x04,SID130B_Control);
    SID130BNightMode(SID130B_g_bNightMode);	
	Out->WaitStableFrameNum = 3 ;
	Out->GrabStartX = StartX;
	Out->GrabStartY = StartY;
	Out->ExposureWindowWidth = SID130B_IMAGE_SENSOR_PV_WIDTH-8; 
	Out->ExposureWindowHeight = SID130B_IMAGE_SENSOR_PV_HEIGHT-6;
}

/*************************************************************************
* FUNCTION
*    SID130BCapture
*
* DESCRIPTION
*    This function set to capture mode
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
static void SID130BCapture(CAL_SCENARIO_ENUM id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint8 StartX = 0, StartY = 2;
  kal_uint16 iDummy_pixel = 0;

#ifdef SID130B_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "SID130B Capture");
#endif
  if (In->ImageTargetWidth <= SID130B_IMAGE_SENSOR_PV_WIDTH &&
				In->ImageTargetHeight<= SID130B_IMAGE_SENSOR_PV_HEIGHT)
  	{
  Out->GrabStartX = StartX+8;
  Out->GrabStartY = StartY+7;
  Out->ExposureWindowWidth = SID130B_IMAGE_SENSOR_PV_WIDTH - 8; 
  Out->ExposureWindowHeight = SID130B_IMAGE_SENSOR_PV_HEIGHT - 6;
  	}
  else
	{
		// Capture frame rate 9.23 fps
		
		//iDummy_pixel = 0x158;
		
		iDummy_pixel = 0x02;
		if(In->ZoomFactor >= 200 && In->ZoomFactor <= 300)
			iDummy_pixel = 0x4E4;
		else if (In->ZoomFactor  > 300)
			iDummy_pixel = 0x7D2;
		
		SID130B_Config_Cap_Blank(iDummy_pixel,0x00);//SID130B_Config_Cap_Blank(iDummy_pixel,0x3D);
		//use group_A register
		SID130B_set_page(0);
		SID130B_Control = SID130B_Control |0x10; 
		CamWriteCmosSensor(0x04,SID130B_Control);
		kal_sleep_task(8);
		Out->GrabStartX = StartX + 8;
		Out->GrabStartY = StartY + 7;
		Out->ExposureWindowWidth = SID130B_IMAGE_SENSOR_FULL_WIDTH - 8;
		Out->ExposureWindowHeight = SID130B_IMAGE_SENSOR_FULL_HEIGHT - 6;
	}
}

/*************************************************************************
* FUNCTION
*    SID130BSensorOpen
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
static MM_ERROR_CODE_ENUM SID130BSensorOpen(void)
{
  if (SID130B_SENSOR_ID != SID130BPowerOn())
  {
    return MM_ERROR_SENSOR_READ_ID_FAIL;
  }
  SID130B_mclk_div_Pre = 1; 
	SID130B_mclk_div_Cap = 1;
    SID130B_Video_Mode = KAL_FALSE;
    //SID130B_Mode_change = KAL_FALSE;        
    SID130B_g_bNightMode = KAL_FALSE;
    SID130B_g_iBanding = CAM_BANDING_50HZ;
    SID130B_Control = 0x00;
	SID130B_HVMirror = IMAGE_SENSOR_MIRROR_NORMAL;
	SID130B_PV_Dummy_Pixel = 0x42;
	SID130B_Min_Fps_Normal = 10 * SID130B_FRAME_RATE_UNIT;
	SID130B_Min_Fps_Night = SID130B_Min_Fps_Normal >> 1;

  SID130B_cal_fps();
  SID130B_YUV_sensor_initial_setting();
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SID130BSensorFeatureCtrl
*
* DESCRIPTION
*    This function set sensor feature mode
*
* PARAMETERS
*    id: scenario id
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
static MM_ERROR_CODE_ENUM SID130BSensorFeatureCtrl(IMAGE_SENSOR_FEATURE_ENUM id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
  kal_uint32 TmpFrameRate;
  
#ifdef SID130B_DEBUG
  kal_wap_trace(MOD_ENG, TRACE_INFO, "SID130B FeatureCtrl Id:%x",id);
#endif
  if (id >= CAL_FEATURE_WEBCAM_BEGIN && id <= CAL_FEATURE_WEBCAM_END)
  {
    return SID130BWebcamFeatureCtrl(id, In, Out, OutLen, RealOutLen);
  }
  switch (id)
  {
   /* CAL Query and set series */
  case CAL_FEATURE_CAMERA_BRIGHTNESS:
  case CAL_FEATURE_CAMERA_EV_VALUE:
    ErrCode = SID130BEV(In, Out);
    break;
  case CAL_FEATURE_CAMERA_CONTRAST:
  	ErrCode = SID130BContrast(In, Out);
    break;
  case CAL_FEATURE_CAMERA_HUE:
  case CAL_FEATURE_CAMERA_SATURATION:
  case CAL_FEATURE_CAMERA_SHARPNESS:
  case CAL_FEATURE_CAMERA_GAMMA:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  case CAL_FEATURE_CAMERA_WB:
    ErrCode = SID130BWB(In, Out);
    break;
  case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
    ErrCode = SID130BEffect(In, Out);
    break;
  case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
    ErrCode = SID130BStillCaptureSize(In, Out);
    break;
  case CAL_FEATURE_CAMERA_SCENE_MODE:
	ErrCode = SID130BSceneMode(KAL_TRUE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
	ErrCode = SID130BSceneMode(KAL_FALSE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_BANDING_FREQ: /* move to preview */
    ErrCode = SID130BBanding(In, Out);
    break;
  case CAL_FEATURE_CAMERA_FLASH_MODE:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;

  /* Get Info series */
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
    SID130BGetSensorInfo(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = SID130BDetectSensorId();
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = SID130BSensor.Fps * 10 / SID130B_FRAME_RATE_UNIT;
    break;
  case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
    SID130BInitOperationPara(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_DSC_SUPPORT_INFO:
    SID130BDscSupportInfo(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
    CamGetHWInfo(SID130BSensor.SensorIdx, Out);
    break;
    
  /* Set Para series */
  case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
    SID130BSensor.NvramData = &(((nvram_camera_para_struct *)In)->SENSOR);
    break;
  case IMAGE_SENSOR_FEATURE_VSYNC_HISR_INFORM_FRAME_TIME:
    TmpFrameRate = ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
    break;
  case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
    SID130BSensor.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
    break;
  case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
    break;
  case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
      SID130BSensor.BypassAe = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
      SID130BAEEnable(SID130BSensor.BypassAe ? KAL_FALSE : KAL_TRUE);
    break;
    case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
      SID130BSensor.BypassAwb = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
      SID130BAWBEnable(SID130BSensor.BypassAwb ? KAL_FALSE : KAL_TRUE);
      break;
  default:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  }
  return ErrCode;
}

/*************************************************************************
* FUNCTION
*    SID130BSensorCtrl
*
* DESCRIPTION
*    This function set sensor scenario mode
*
* PARAMETERS
*    id: scenario id
*    In/Out: parameter
*    OutLen: Out parameter length
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM SID130BSensorCtrl(CAL_SCENARIO_ENUM id, void *In, void *Out, kal_uint16 OutLen)
{
  switch (id)
  {
  case CAL_SCENARIO_CAMERA_PREVIEW:
  case CAL_SCENARIO_VIDEO:
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE:
    SID130BPreview(id, In, Out);
    break;
  case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
    SID130BCapture(id, In, Out);
    break;
  default:
    break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SID130BSensorClose
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
static MM_ERROR_CODE_ENUM SID130BSensorClose(void)
{
  /* power down sensor */
  SID130B_set_page(0);
  CamWriteCmosSensor(0x03, 0x02);  //sensor sleep mode
  CamPdnPinCtrl(SID130BSensor.SensorIdx, 0);
  CamRstPinCtrl(SID130BSensor.SensorIdx, 0);
  CisModulePowerOn(SID130BSensor.SensorIdx, KAL_FALSE);
  CameraSccbClose(CAMERA_SCCB_SENSOR);
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SID130BSensorFunc
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
MM_ERROR_CODE_ENUM SID130BSensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncSID130B =
  {
    SID130BSensorOpen,
    SID130BSensorFeatureCtrl,
    SID130BSensorCtrl,
    SID130BSensorClose,
  };
  
  *pfSensorFunc = &ImageSensorFuncSID130B;
  
  return MM_ERROR_NONE;
}

