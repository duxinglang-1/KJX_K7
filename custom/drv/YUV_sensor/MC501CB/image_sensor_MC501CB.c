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
 *   image_sensor.c
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_comm.h"
#include "isp_comm_if.h"
#include "isp_flashlight_if.h"
#include "camera_sccb.h"
#include "image_sensor.h"
#include "sensor_comm_def.h"
#include "image_sensor_MC501CB.h"

struct MC501CB_SENSOR_STRUCT
{
	kal_bool night_mode;
	kal_bool video_mode;
	kal_uint16 video_current_frame_rate;
	kal_uint16 video_frame_rate;
	kal_uint16 MC501CB_curr_banding;
	kal_uint16 MC501CB_PV_dummy_pixels;
	kal_uint16 MC501CB_PV_dummy_lines;
	kal_uint16 MC501CB_CAP_dummy_pixels;
	kal_uint16 MC501CB_CAP_dummy_lines;
	IMAGE_SENSOR_INDEX_ENUM SensorIdx;
	sensor_data_struct *nvram_data;
};

static struct MC501CB_SENSOR_STRUCT MC501CB_Sensor_Status;

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

/*****************************************************************************
 * FUNCTION
 *  MC501CB_Select_Page
 * DESCRIPTION
 *
 * PARAMETERS
 *  shutter     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void MC501CB_Select_Page(kal_uint16 page)
{
	//Page address
	// 0x00h, ISP Control Register 1
	// 0x01h, ISP Control Register 2
	// 0x02h, Sensor and TG Control Registers
	// 0x03h, Tuning Parameters.
	ASSERT((page == 0x00) || (page == 0x01) || (page == 0x02) || (page == 0x03));
	
	CamWriteCmosSensor(0xef, page);
}   /* MC501CB_Select_Page */


/*****************************************************************************
 * FUNCTION
 *  MC501CB_write_shutter
 * DESCRIPTION
 *
 * PARAMETERS
 *  shutter     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
//void MC501CB_write_shutter(kal_uint16 cintr,kal_uint16 cintc)
void MC501CB_write_shutter(kal_uint16 shutter)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    kal_uint32 temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	CamWriteCmosSensor(0xef, 0x02);

	CamWriteCmosSensor(0x0e,(shutter>>8)&0x1F);
	CamWriteCmosSensor(0x0f,(shutter)&0xFF);

}   /* MC501CB_write_shutter */

void MC501CB_write_cintc(kal_uint16 cintc)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    kal_uint32 temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	CamWriteCmosSensor(0xef, 0x02);

	CamWriteCmosSensor(0x10,(cintc>>8)&0x1F);
	CamWriteCmosSensor(0x11,(cintc)&0xFF);

}   /* MC501CB_write_shutter */



/*****************************************************************************
 * FUNCTION
 *  MC501CB_read_shutter
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_uint16 MC501CB_read_shutter(void)
{
    kal_uint16 shutter;
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    CamWriteCmosSensor(0xef, 0x02);
	shutter = ((CamReadCmosSensor(0x0e)&0x1F) << 8) | CamReadCmosSensor(0x0f);

    return shutter;
}   /* MC501CB_read_shutter */

kal_uint16 MC501CB_read_cintc(void)
{
	kal_uint16 cintc;

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    CamWriteCmosSensor(0xef, 0x02);
	cintc = ((CamReadCmosSensor(0x10)&0xFF) << 8) | CamReadCmosSensor(0x11);
	
    return cintc;
}   /* MC501CB_read_shutter */


/*****************************************************************************
 * FUNCTION
 *  MC501CB_set_dummy
 * DESCRIPTION
 *
 * PARAMETERS
 *  pixels      [IN]
 *  lines       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void MC501CB_set_dummy(kal_uint16 dummy_pixels, kal_uint16 dummy_lines)
{
	dummy_pixels += MC501CB_VGA_DEFAULT_H_BLANK;
	dummy_lines += MC501CB_VGA_DEFAULT_V_BLANK;

	ASSERT(dummy_pixels <= MC501CB_MAX_H_BLANK);
	ASSERT(dummy_lines <= MC501CB_MAX_V_BLANK);

	//Set V Blanking
	MC501CB_Select_Page(MC501CB_PAGE_3);
	CamWriteCmosSensor(0x63, (dummy_lines >> 8) & 0xff);	//NTSC
	CamWriteCmosSensor(0x64, dummy_lines & 0xff);
	CamWriteCmosSensor(0x65, (dummy_lines >> 8) & 0xff);	//PAL
	CamWriteCmosSensor(0x66, dummy_lines & 0xff);

	//Set H Blanking
	MC501CB_Select_Page(MC501CB_PAGE_3);
	CamWriteCmosSensor(0x48, (dummy_pixels >> 8) & 0xff);
	CamWriteCmosSensor(0x49, dummy_pixels & 0xff);
	CamWriteCmosSensor(0x4c, (dummy_pixels >> 8) & 0xff);
	CamWriteCmosSensor(0x4d, dummy_pixels & 0xff);
	MC501CB_Select_Page(MC501CB_PAGE_2);
	CamWriteCmosSensor(0x1a,(dummy_pixels >> 8) & 0xff);	//Must set the same value with HBLANK.
	CamWriteCmosSensor(0x1b,dummy_pixels & 0xff);
}   /* MC501CB_set_dummy */

void MC501CB_SetHVMirror(kal_uint8 Mirror)
{
	switch (Mirror)
	{
		case IMAGE_SENSOR_MIRROR_NORMAL:
//			SET_CAMERA_INPUT_ORDER(INPUT_ORDER_YCbY1Cr);
			CamWriteCmosSensor(0xEF, 0x03);
			CamWriteCmosSensor(0x70, 0x00);//evt1
		break;
		case IMAGE_SENSOR_MIRROR_H:
//			SET_CAMERA_INPUT_ORDER(INPUT_ORDER_YCbY1Cr);
			CamWriteCmosSensor(0xEF, 0x03);
			CamWriteCmosSensor(0x70, 0x01);
		break;
		case IMAGE_SENSOR_MIRROR_V:
//			SET_CAMERA_INPUT_ORDER(INPUT_ORDER_YCbY1Cr);
			CamWriteCmosSensor(0xEF, 0x03);
			CamWriteCmosSensor(0x70, 0x02);
		break;
		case IMAGE_SENSOR_MIRROR_HV:
//			SET_CAMERA_INPUT_ORDER(INPUT_ORDER_YCbY1Cr);
			CamWriteCmosSensor(0xEF, 0x03);
			CamWriteCmosSensor(0x70, 0x03);//evt1
		break;
	}
}

/*****************************************************************************
 * FUNCTION
 *  MC501CB_init_cmos_sensor
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MC501CB_init_cmos_sensor()
{
	//==================================================
	//	Command setting
	//==================================================
	CamWriteCmosSensor(0xef, 0x03);
	if (MC501CB_Sensor_Status.MC501CB_curr_banding == CAM_BANDING_50HZ)
	{
		CamWriteCmosSensor(0x00,0x83);	 //enable AE & AWB	
	}
	else
	{
		CamWriteCmosSensor(0x00,0x43);	 //enable AE & AWB	
	}
	CamWriteCmosSensor(0x2b, 0x41);
	//BT(Brightness) Offset
	CamWriteCmosSensor(0x31,0x00);	//Normal light
	CamWriteCmosSensor(0x32,0x06); 	//Low light brightness offset. #24 - 27
	//CT(Contrast)
	CamWriteCmosSensor(0x33, 0x80);		 //NL
	CamWriteCmosSensor(0x34, 0x79); //80  //LL
	//ST(Saturation)	   
	CamWriteCmosSensor(0x36, 0x32); //NL  Saturation, 115%
	CamWriteCmosSensor(0x37, 0x14); //LL  Saturation 25.8%
	//BPR : Should keep the bellows 		
	CamWriteCmosSensor(0x6a, 0x00); 
	CamWriteCmosSensor(0x7b, 0x05); 
	CamWriteCmosSensor(0x38, 0x05); 
	CamWriteCmosSensor(0x39, 0x03); 
	CamWriteCmosSensor(0x2d, 0x08); 
	CamWriteCmosSensor(0x2e, 0x2c); 
	CamWriteCmosSensor(0x2f, 0x3e); 
	CamWriteCmosSensor(0x30, 0xff); 
	CamWriteCmosSensor(0x7c, 0x04); 
	CamWriteCmosSensor(0x7d, 0x2a); 
	CamWriteCmosSensor(0x7e, 0x0c); 
	CamWriteCmosSensor(0x7f, 0x2a);		   
	
	CamWriteCmosSensor(0x28, 0x02);	  //Sharpness 
	CamWriteCmosSensor(0x29, 0x6f); 
	CamWriteCmosSensor(0x2a, 0x00); 
	CamWriteCmosSensor(0x13, 0x00); 
	CamWriteCmosSensor(0x14, 0xa0); 
	CamWriteCmosSensor(0x19, 0x43); 
	CamWriteCmosSensor(0x1a, 0x68);	 // 68	//Outdoor Rgain Max
	CamWriteCmosSensor(0x1b, 0x42);	 //5b ////Outdoor Rgain Min
	CamWriteCmosSensor(0x1c, 0x63);	  //63 //60  ////Outdoor Bgain Max
	
	CamWriteCmosSensor(0x1d, 0x4c);	  // 52//4e  ////Outdoor Bgain Min	
	
	CamWriteCmosSensor(0x1e, 0x68);	//68  //Indoor Rgain Max
	CamWriteCmosSensor(0x1f, 0x42);	//3b  //Indoor Rgain Min
	CamWriteCmosSensor(0x20, 0x7e);	//80  //Indoor Bgain Max
	CamWriteCmosSensor(0x21, 0x4b);	//4e  //Indoor Bgain Min
	
	CamWriteCmosSensor(0x3a, 0x13);		 //14 //[7:4]AWB speed, [3:0] AWB threshold 																														 
	CamWriteCmosSensor(0x3b, 0x3e);		 //AWB skip BRT <= same value with AE target<3. 01> 																												 
	CamWriteCmosSensor(0x3c, 0x00);		 //AWB skip Gain																																					 
	CamWriteCmosSensor(0x3d, 0x18);		 //AWB skip AVG 																																					 
	CamWriteCmosSensor(0x23, 0x80); 
	CamWriteCmosSensor(0x15, 0x0b); 
	CamWriteCmosSensor(0x16, 0xd2); 
	CamWriteCmosSensor(0x17, 0x64); 
	CamWriteCmosSensor(0x18, 0x78); 

	//==================================================
	//	X-shading for Truly GT-E2100 module 
	//==================================================
	CamWriteCmosSensor(0xef, 0x00); 
	CamWriteCmosSensor(0xde, 0x00); 
	CamWriteCmosSensor(0xdf, 0x1F); 
	CamWriteCmosSensor(0xe0, 0x00); 
	CamWriteCmosSensor(0xe1, 0x37); 
	CamWriteCmosSensor(0xe2, 0x08); 
	CamWriteCmosSensor(0xe3, 0x42); 
	CamWriteCmosSensor(0xe4, 0x00); 
	CamWriteCmosSensor(0xe5, 0x12); 
	CamWriteCmosSensor(0xe6, 0x9E); 
	CamWriteCmosSensor(0xe9, 0x00); 
	CamWriteCmosSensor(0xe7, 0x00); 
	CamWriteCmosSensor(0xe8, 0xC8); 
	CamWriteCmosSensor(0xe9, 0x01); 
	CamWriteCmosSensor(0xe7, 0x00); 
	CamWriteCmosSensor(0xe8, 0xC6); 
	CamWriteCmosSensor(0xe9, 0x02); 
	CamWriteCmosSensor(0xe7, 0x00); 
	CamWriteCmosSensor(0xe8, 0xC3); 
	CamWriteCmosSensor(0xe9, 0x03); 
	CamWriteCmosSensor(0xe7, 0x00); 
	CamWriteCmosSensor(0xe8, 0xC0); 
	CamWriteCmosSensor(0xe9, 0x04); 
	CamWriteCmosSensor(0xe7, 0x00); 
	CamWriteCmosSensor(0xe8, 0xC7); 
	CamWriteCmosSensor(0xe9, 0x05); 
	CamWriteCmosSensor(0xe7, 0x00); 
	CamWriteCmosSensor(0xe8, 0xC7); 
	CamWriteCmosSensor(0xe9, 0x06); 
	CamWriteCmosSensor(0xe7, 0x00); 
	CamWriteCmosSensor(0xe8, 0xD0); 
	CamWriteCmosSensor(0xe9, 0x07); 
	CamWriteCmosSensor(0xe7, 0x00); 
	CamWriteCmosSensor(0xe8, 0x6D); 
	CamWriteCmosSensor(0xe9, 0x08); 
	CamWriteCmosSensor(0xe7, 0x00); 
	CamWriteCmosSensor(0xe8, 0x5C); 
	CamWriteCmosSensor(0xe9, 0x09); 
	CamWriteCmosSensor(0xe7, 0x00); 
	CamWriteCmosSensor(0xe8, 0x61); 
	CamWriteCmosSensor(0xe9, 0x0A); 
	CamWriteCmosSensor(0xe7, 0x00); 
	CamWriteCmosSensor(0xe8, 0x51); 
	CamWriteCmosSensor(0xe9, 0x0B); 
	CamWriteCmosSensor(0xe7, 0x00); 
	CamWriteCmosSensor(0xe8, 0x55); 
	CamWriteCmosSensor(0xe9, 0x0C); 
	CamWriteCmosSensor(0xe7, 0x00); 
	CamWriteCmosSensor(0xe8, 0x5A); 
	CamWriteCmosSensor(0xe9, 0x0D); 
	CamWriteCmosSensor(0xe7, 0x00); 
	CamWriteCmosSensor(0xe8, 0x53); 
	CamWriteCmosSensor(0xe9, 0x0E); 
	CamWriteCmosSensor(0xe7, 0x00); 
	CamWriteCmosSensor(0xe8, 0x0C); 
	CamWriteCmosSensor(0xe9, 0x0F); 
	CamWriteCmosSensor(0xe7, 0x07); 
	CamWriteCmosSensor(0xe8, 0xFC); 
	CamWriteCmosSensor(0xe9, 0x10); 
	CamWriteCmosSensor(0xe7, 0x07); 
	CamWriteCmosSensor(0xe8, 0xF6); 
	CamWriteCmosSensor(0xe9, 0x11); 
	CamWriteCmosSensor(0xe7, 0x07); 
	CamWriteCmosSensor(0xe8, 0xE0); 
	CamWriteCmosSensor(0xe9, 0x12); 
	CamWriteCmosSensor(0xe7, 0x07); 
	CamWriteCmosSensor(0xe8, 0xE9); 
	CamWriteCmosSensor(0xe9, 0x13); 
	CamWriteCmosSensor(0xe7, 0x07); 
	CamWriteCmosSensor(0xe8, 0xED); 
	CamWriteCmosSensor(0xe9, 0x14); 
	CamWriteCmosSensor(0xe7, 0x07); 
	CamWriteCmosSensor(0xe8, 0xEC); 
	CamWriteCmosSensor(0xe9, 0x15); 
	CamWriteCmosSensor(0xe7, 0x07); 
	CamWriteCmosSensor(0xe8, 0xBB); 
	CamWriteCmosSensor(0xe9, 0x16); 
	CamWriteCmosSensor(0xe7, 0x07); 
	CamWriteCmosSensor(0xe8, 0xA1); 
	CamWriteCmosSensor(0xe9, 0x17); 
	CamWriteCmosSensor(0xe7, 0x07); 
	CamWriteCmosSensor(0xe8, 0x8B); 
	CamWriteCmosSensor(0xe9, 0x18); 
	CamWriteCmosSensor(0xe7, 0x07); 
	CamWriteCmosSensor(0xe8, 0x80); 
	CamWriteCmosSensor(0xe9, 0x19); 
	CamWriteCmosSensor(0xe7, 0x07); 
	CamWriteCmosSensor(0xe8, 0x7E); 
	CamWriteCmosSensor(0xe9, 0x1A); 
	CamWriteCmosSensor(0xe7, 0x07); 
	CamWriteCmosSensor(0xe8, 0x80); 
	CamWriteCmosSensor(0xe9, 0x1B); 
	CamWriteCmosSensor(0xe7, 0x07); 
	CamWriteCmosSensor(0xe8, 0x87); 
	CamWriteCmosSensor(0xe9, 0x1C); 
	CamWriteCmosSensor(0xe7, 0x07); 
	CamWriteCmosSensor(0xe8, 0x69); 
	CamWriteCmosSensor(0xe9, 0x1D); 
	CamWriteCmosSensor(0xe7, 0x07); 
	CamWriteCmosSensor(0xe8, 0x4B); 
	CamWriteCmosSensor(0xe9, 0x1E); 
	CamWriteCmosSensor(0xe7, 0x07); 
	CamWriteCmosSensor(0xe8, 0x3B); 
	CamWriteCmosSensor(0xe9, 0x1F); 
	CamWriteCmosSensor(0xe7, 0x07); 
	CamWriteCmosSensor(0xe8, 0x28); 
	CamWriteCmosSensor(0xe9, 0x20); 
	CamWriteCmosSensor(0xe7, 0x07); 
	CamWriteCmosSensor(0xe8, 0x21); 
	CamWriteCmosSensor(0xe9, 0x21); 
	CamWriteCmosSensor(0xe7, 0x07); 
	CamWriteCmosSensor(0xe8, 0x13); 
	CamWriteCmosSensor(0xe9, 0x22); 
	CamWriteCmosSensor(0xe7, 0x07); 
	CamWriteCmosSensor(0xe8, 0x20); 
	CamWriteCmosSensor(0xe9, 0x40); 
	
	CamWriteCmosSensor(0x37, 0x9a);	//R Channel
	CamWriteCmosSensor(0x38, 0x89);	//G Channel
	CamWriteCmosSensor(0x39, 0x76);	//B channel //	87.64	-1.43	3.72		3.72
	CamWriteCmosSensor(0x3a, 0x00);
	CamWriteCmosSensor(0x3b, 0xed);	//Lens correction circle center Y axis
	CamWriteCmosSensor(0x3c, 0x01);
	CamWriteCmosSensor(0x3d, 0x2a);	// Lens correction circle center X axis
	//==================================================
	//	Sharpness Configure
	//==================================================
	CamWriteCmosSensor(0xb9, 0x02);	 //Sharpness ON
	CamWriteCmosSensor(0xbb, 0xa8);	 //HPF 
	CamWriteCmosSensor(0xbc, 0x10);
	CamWriteCmosSensor(0xbd, 0x30);
	CamWriteCmosSensor(0xbf, 0x18);
	CamWriteCmosSensor(0xc1, 0x38);
	CamWriteCmosSensor(0xc8, 0x11);	 //YC delay 
	CamWriteCmosSensor(0xeb, 0x81);	 //Edge Color Suppress
	CamWriteCmosSensor(0xed, 0x05);
	//==================================================
	//	AWB Window
	//==================================================
	CamWriteCmosSensor(0xb1, 0x00);	 
	CamWriteCmosSensor(0xb2, 0x62);
	CamWriteCmosSensor(0xb3, 0x00);
	CamWriteCmosSensor(0xb4, 0x00);
	CamWriteCmosSensor(0xb5, 0x01);
	CamWriteCmosSensor(0xb6, 0xa3);
	CamWriteCmosSensor(0xb7, 0x02);
	CamWriteCmosSensor(0xb8, 0x80);		
	CamWriteCmosSensor(0x77, 0x00);	// Sine value [9:8]
	CamWriteCmosSensor(0x78, 0x00);	// Sine value [7:0]

	//==================================================
	//	AWB Setting, AWB_MAP
	//==================================================
	CamWriteCmosSensor(0xef, 0x00);
	CamWriteCmosSensor(0x93, 0x40);
	CamWriteCmosSensor(0x94, 0x80);
	CamWriteCmosSensor(0x95, 0xc0);
	CamWriteCmosSensor(0x96, 0xc0);
	CamWriteCmosSensor(0x97, 0x20);
	CamWriteCmosSensor(0x98, 0x20);
	CamWriteCmosSensor(0x99, 0x30);
	CamWriteCmosSensor(0xA0, 0x00);
	CamWriteCmosSensor(0xA1, 0x00);
	CamWriteCmosSensor(0xA2, 0x1c);
	CamWriteCmosSensor(0xA3, 0x16);
	CamWriteCmosSensor(0xA4, 0x03);
	CamWriteCmosSensor(0xA5, 0x07);
	CamWriteCmosSensor(0xA6, 0x00);
	CamWriteCmosSensor(0xef, 0x00);
	CamWriteCmosSensor(0xad, 0xd0);
	CamWriteCmosSensor(0xaf, 0x10); //26

	//==================================================
	//	RGB Gain (1st)
	//==================================================
	CamWriteCmosSensor(0xef, 0x00);
	CamWriteCmosSensor(0x42, 0x5d); //65
	CamWriteCmosSensor(0x44, 0x60); //62
	CamWriteCmosSensor(0x57, 0x00);	 //AE Min skip, Luminance min level cut-line threshold

	//==================================================
	//	AE Control Setting, Threshold, AE Step...
	//==================================================
	CamWriteCmosSensor(0xef, 0x03);
	CamWriteCmosSensor(0x01, 0x3e); //3c
	//CamWriteCmosSensor(0x02, 0x05);
	CamWriteCmosSensor(0x02, 0x0a);

	CamWriteCmosSensor(0x03, 0x11); //20	AE speed.
	
	CamWriteCmosSensor(0x04, 0x58); // AE Low-light gain max, Default 0x70
	CamWriteCmosSensor(0x06, 0x1c);	// AE High-light gain max, Default 0x1c
	CamWriteCmosSensor(0x07, 0x01);	// AE WindowA Weight
	CamWriteCmosSensor(0x08, 0x01);
	CamWriteCmosSensor(0x0b, 0x01);

	//==================================================
	//	AE Window Setting
	//==================================================
	CamWriteCmosSensor(0xef,0x00);
	CamWriteCmosSensor(0x58,0x00);
	CamWriteCmosSensor(0x59,0x00);
	CamWriteCmosSensor(0x5a,0x02);
	CamWriteCmosSensor(0x5b,0x73);
	CamWriteCmosSensor(0x5c,0x00);
	CamWriteCmosSensor(0x5d,0x00);
	CamWriteCmosSensor(0x5e,0x01);
	CamWriteCmosSensor(0x5f,0xe0);
	CamWriteCmosSensor(0x60,0x00);
	CamWriteCmosSensor(0x61,0x5a);
	CamWriteCmosSensor(0x62,0x02);
	CamWriteCmosSensor(0x63,0x0f);
	CamWriteCmosSensor(0x64,0x00);
	CamWriteCmosSensor(0x65,0x6e);
	CamWriteCmosSensor(0x66,0x01);
	CamWriteCmosSensor(0x67,0x7b);
#ifdef MC501CB_AE_WINDOW_OSD_DISPLAY
	CamWriteCmosSensor(0xef,0x00);
	CamWriteCmosSensor(0x55,0x01);

#endif

	//==================================================
	//	Flicker Detection Setting1, H/V Size Set
	//==================================================
	CamWriteCmosSensor(0xef, 0x00);	 //Flicker setting				   
	CamWriteCmosSensor(0x6a, 0x01);	 //080331 Flicker H SIZE High	   
	CamWriteCmosSensor(0x6b, 0xe0);	 //080331 Flicker H SIZE low	   
	CamWriteCmosSensor(0x6c, 0x05);	 //04 //080331 Flicker WINDOW VSIZE
	CamWriteCmosSensor(0x6d, 0x00);	 //080331 Flicker V SIZE START H   
	CamWriteCmosSensor(0x6e, 0x0e);	 //080331 Flicker V SIZE START L   
	CamWriteCmosSensor(0x6f, 0x00);	 //080331 Flicker H SIZE START H   
	CamWriteCmosSensor(0x70, 0x10);	 //080331 Flicker H SIZE START L   

	//==================================================
	//	Flicker Detection Setting2
	//==================================================
	CamWriteCmosSensor(0xef, 0x03);
	CamWriteCmosSensor(0x22, 0x24);	//23 //flicker sensitivity H/L		
	// B/R Average Min/Max Value for AWB Horizon Temperature Detection
	CamWriteCmosSensor(0x3e, 0x23);
	CamWriteCmosSensor(0x3f, 0x23);
	CamWriteCmosSensor(0x40, 0x00);
	CamWriteCmosSensor(0x41, 0x09);	 //60hz light - 50hz setting threshold 
	CamWriteCmosSensor(0x4a, 0x09);	 //50hz light - 60hz setting threshold 
	CamWriteCmosSensor(0x4b, 0x04);
	CamWriteCmosSensor(0x5b, 0x20);	 //10 //detection haunting protection count 
	CamWriteCmosSensor(0x5d, 0x35);
	CamWriteCmosSensor(0x5e, 0x13);
	CamWriteCmosSensor(0x78, 0x0f);

	//==================================================
	//	Color Martrix Setting
	//==================================================
	CamWriteCmosSensor(0xef, 0x00);
	CamWriteCmosSensor(0x4c, 0x79);	 //CCM
	CamWriteCmosSensor(0x4d, 0xbe);
	CamWriteCmosSensor(0x4e, 0x08);
	CamWriteCmosSensor(0x4f, 0x9c);
	CamWriteCmosSensor(0x50, 0x7a);
	CamWriteCmosSensor(0x51, 0x9e);
	CamWriteCmosSensor(0x52, 0x8f);
	CamWriteCmosSensor(0x53, 0xbb);
	CamWriteCmosSensor(0x54, 0x8a);

	//==================================================
	//	RGB Gamma Setting
	//==================================================
	CamWriteCmosSensor(0xef,0x00);
	CamWriteCmosSensor(0x48,0x00);	// RGB component selection & Indirect address for gamma Y-axis index
	CamWriteCmosSensor(0x49,0x00);
	CamWriteCmosSensor(0x4A,0x03);	// Gamma Y-axis coordinate
	CamWriteCmosSensor(0x48,0x01);
	CamWriteCmosSensor(0x49,0x00);
	CamWriteCmosSensor(0x4A,0x16);
	CamWriteCmosSensor(0x48,0x02);
	CamWriteCmosSensor(0x49,0x00);
	CamWriteCmosSensor(0x4A,0x44);
	CamWriteCmosSensor(0x48,0x03);
	CamWriteCmosSensor(0x49,0x00);
	CamWriteCmosSensor(0x4A,0x9D);
	CamWriteCmosSensor(0x48,0x04);
	CamWriteCmosSensor(0x49,0x01);
	CamWriteCmosSensor(0x4A,0x37);
	CamWriteCmosSensor(0x48,0x05);
	CamWriteCmosSensor(0x49,0x01);
	CamWriteCmosSensor(0x4A,0xB4);
	CamWriteCmosSensor(0x48,0x06);
	CamWriteCmosSensor(0x49,0x02);
	CamWriteCmosSensor(0x4A,0x23);
	CamWriteCmosSensor(0x48,0x07);
	CamWriteCmosSensor(0x49,0x02);
	CamWriteCmosSensor(0x4A,0x72);
	CamWriteCmosSensor(0x48,0x08);
	CamWriteCmosSensor(0x49,0x02);
	CamWriteCmosSensor(0x4A,0xBE);
	CamWriteCmosSensor(0x48,0x09);
	CamWriteCmosSensor(0x49,0x02);
	CamWriteCmosSensor(0x4A,0xFA);
	CamWriteCmosSensor(0x48,0x0A);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0x27);
	CamWriteCmosSensor(0x48,0x0B);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0x55);
	CamWriteCmosSensor(0x48,0x0C);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0x81);
	CamWriteCmosSensor(0x48,0x0D);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0x9B);
	CamWriteCmosSensor(0x48,0x0E);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0xB3);
	CamWriteCmosSensor(0x48,0x0F);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0xC9);
	CamWriteCmosSensor(0x48,0x10);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0xD9);
	CamWriteCmosSensor(0x48,0x11);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0xE9);
	CamWriteCmosSensor(0x48,0x12);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0xFF);
	CamWriteCmosSensor(0x48,0x20);
	CamWriteCmosSensor(0x49,0x00);
	CamWriteCmosSensor(0x4A,0x03);
	CamWriteCmosSensor(0x48,0x21);
	CamWriteCmosSensor(0x49,0x00);
	CamWriteCmosSensor(0x4A,0x16);
	CamWriteCmosSensor(0x48,0x22);
	CamWriteCmosSensor(0x49,0x00);
	CamWriteCmosSensor(0x4A,0x44);
	CamWriteCmosSensor(0x48,0x23);
	CamWriteCmosSensor(0x49,0x00);
	CamWriteCmosSensor(0x4A,0x9D);
	CamWriteCmosSensor(0x48,0x24);
	CamWriteCmosSensor(0x49,0x01);
	CamWriteCmosSensor(0x4A,0x37);
	CamWriteCmosSensor(0x48,0x25);
	CamWriteCmosSensor(0x49,0x01);
	CamWriteCmosSensor(0x4A,0xB4);
	CamWriteCmosSensor(0x48,0x26);
	CamWriteCmosSensor(0x49,0x02);
	CamWriteCmosSensor(0x4A,0x23);
	CamWriteCmosSensor(0x48,0x27);
	CamWriteCmosSensor(0x49,0x02);
	CamWriteCmosSensor(0x4A,0x72);
	CamWriteCmosSensor(0x48,0x28);
	CamWriteCmosSensor(0x49,0x02);
	CamWriteCmosSensor(0x4A,0xBE);
	CamWriteCmosSensor(0x48,0x29);
	CamWriteCmosSensor(0x49,0x02);
	CamWriteCmosSensor(0x4A,0xFA);
	CamWriteCmosSensor(0x48,0x2A);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0x27);
	CamWriteCmosSensor(0x48,0x2B);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0x55);
	CamWriteCmosSensor(0x48,0x2C);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0x81);
	CamWriteCmosSensor(0x48,0x2D);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0x9B);
	CamWriteCmosSensor(0x48,0x2E);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0xB3);
	CamWriteCmosSensor(0x48,0x2F);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0xC9);
	CamWriteCmosSensor(0x48,0x30);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0xD9);
	CamWriteCmosSensor(0x48,0x31);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0xE9);
	CamWriteCmosSensor(0x48,0x32);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0xFF);
	CamWriteCmosSensor(0x48,0x40);
	CamWriteCmosSensor(0x49,0x00);
	CamWriteCmosSensor(0x4A,0x03);
	CamWriteCmosSensor(0x48,0x41);
	CamWriteCmosSensor(0x49,0x00);
	CamWriteCmosSensor(0x4A,0x16);
	CamWriteCmosSensor(0x48,0x42);
	CamWriteCmosSensor(0x49,0x00);
	CamWriteCmosSensor(0x4A,0x44);
	CamWriteCmosSensor(0x48,0x43);
	CamWriteCmosSensor(0x49,0x00);
	CamWriteCmosSensor(0x4A,0x9D);
	CamWriteCmosSensor(0x48,0x44);
	CamWriteCmosSensor(0x49,0x01);
	CamWriteCmosSensor(0x4A,0x37);
	CamWriteCmosSensor(0x48,0x45);
	CamWriteCmosSensor(0x49,0x01);
	CamWriteCmosSensor(0x4A,0xB4);
	CamWriteCmosSensor(0x48,0x46);
	CamWriteCmosSensor(0x49,0x02);
	CamWriteCmosSensor(0x4A,0x23);
	CamWriteCmosSensor(0x48,0x47);
	CamWriteCmosSensor(0x49,0x02);
	CamWriteCmosSensor(0x4A,0x72);
	CamWriteCmosSensor(0x48,0x48);
	CamWriteCmosSensor(0x49,0x02);
	CamWriteCmosSensor(0x4A,0xBE);
	CamWriteCmosSensor(0x48,0x49);
	CamWriteCmosSensor(0x49,0x02);
	CamWriteCmosSensor(0x4A,0xFA);
	CamWriteCmosSensor(0x48,0x4A);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0x27);
	CamWriteCmosSensor(0x48,0x4B);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0x55);
	CamWriteCmosSensor(0x48,0x4C);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0x81);
	CamWriteCmosSensor(0x48,0x4D);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0x9B);
	CamWriteCmosSensor(0x48,0x4E);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0xB3);
	CamWriteCmosSensor(0x48,0x4F);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0xC9);
	CamWriteCmosSensor(0x48,0x50);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0xD9);
	CamWriteCmosSensor(0x48,0x51);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0xE9);
	CamWriteCmosSensor(0x48,0x52);
	CamWriteCmosSensor(0x49,0x03);
	CamWriteCmosSensor(0x4A,0xFF);

}







//zhijie

/*************************************************************************
* FUNCTION
*    MC501CB_NightMode
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
static void MC501CB_NightMode(kal_bool bEnable)
{    
	#ifdef MC501CB_OUTPUT_DEBUG_INFO
		kal_wap_trace(MOD_ENG,TRACE_INFO, "MC501CB NightMode %d",bEnable);
	#endif
	if (MC501CB_Sensor_Status.video_mode == KAL_FALSE)// camera mode
	{
		if (KAL_TRUE == bEnable)
		{ /* camera night mode */
			#ifdef MC501CB_OUTPUT_DEBUG_INFO
				kal_wap_trace(MOD_ENG,TRACE_INFO, "camera night mode");
			#endif
			CamWriteCmosSensor(0xD7, 0x11);
			CamWriteCmosSensor(0x44, 0x50);
		}
		else
		{   /* camera normal mode */
			#ifdef MC501CB_OUTPUT_DEBUG_INFO
				kal_wap_trace(MOD_ENG,TRACE_INFO, "camera normal mode");
			#endif
			CamWriteCmosSensor(0xD7, 0x02);
			CamWriteCmosSensor(0x44, 0x50);
		}
	}
  else //video mode
  {
    if (KAL_TRUE == bEnable)
    {   /* video night mode */
#ifdef MC501CB_OUTPUT_DEBUG_INFO
      kal_wap_trace(MOD_ENG,TRACE_INFO, "video night mode");
#endif
      CamWriteCmosSensor(0xD7, 0x12);
      CamWriteCmosSensor(0x44, 0x50);
    }
    else
    {   /* video normal mode */
#ifdef MC501CB_OUTPUT_DEBUG_INFO
      kal_wap_trace(MOD_ENG,TRACE_INFO, "video normal mode");
#endif
      CamWriteCmosSensor(0xD7, 0x02);
      CamWriteCmosSensor(0x44, 0x50);
    }
  }
}


/*************************************************************************
* FUNCTION
*    MC501CBEV
*
* DESCRIPTION
*    MC501CB EV setting.
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
static MM_ERROR_CODE_ENUM MC501CBEV(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    kal_uint8 iEvTemp = In->FeatureSetValue;
#ifdef MC501CB_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"EV:%d",iEvTemp);
#endif
   switch (In->FeatureSetValue)
  {
      case CAM_EV_NEG_4_3: 
		CamWriteCmosSensor(0xef,0x03); 
		CamWriteCmosSensor(0x31,0xa0); 
		CamWriteCmosSensor(0x32,0x98); 
		break;
  	  case CAM_EV_NEG_3_3:
		CamWriteCmosSensor(0xef,0x03);
		CamWriteCmosSensor(0x31,0x98);
		CamWriteCmosSensor(0x32,0x90);
		break;
  	  case CAM_EV_NEG_2_3: 
		CamWriteCmosSensor(0xef,0x03);
		CamWriteCmosSensor(0x31,0x90);
		CamWriteCmosSensor(0x32,0x88);
		break;
  	  case CAM_EV_NEG_1_3: 
		CamWriteCmosSensor(0xef,0x03);
		CamWriteCmosSensor(0x31,0x88);
		CamWriteCmosSensor(0x32,0x80);
		break;
  case CAM_EV_ZERO:    
		CamWriteCmosSensor(0xef,0x03);
		CamWriteCmosSensor(0x31,0x00);
		CamWriteCmosSensor(0x32,0x05); 
		break;
  case CAM_EV_POS_1_3:
		CamWriteCmosSensor(0xef,0x03); 
		CamWriteCmosSensor(0x31,0x08); 
		CamWriteCmosSensor(0x32,0x10);
		break;
  case CAM_EV_POS_2_3:
		CamWriteCmosSensor(0xef,0x03);
		CamWriteCmosSensor(0x31,0x10);
		CamWriteCmosSensor(0x32,0x18); 
		break;
  case CAM_EV_POS_3_3: 
		CamWriteCmosSensor(0xef,0x03); 
		CamWriteCmosSensor(0x31,0x18); 
		CamWriteCmosSensor(0x32,0x20);
		break;
  case CAM_EV_POS_4_3: 
		CamWriteCmosSensor(0xef,0x03);
		CamWriteCmosSensor(0x31,0x20);
		CamWriteCmosSensor(0x32,0x28);
		break;
  default: 
  	break;
  }
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    MC501CBWB
*
* DESCRIPTION
*    MC501CB WB setting.
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
static MM_ERROR_CODE_ENUM MC501CBWB(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
#ifdef MC501CB_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"WB:%d",WBTemp);
#endif
    switch (In->FeatureSetValue)
	{
		case CAM_WB_AUTO:
			CamWriteCmosSensor(0xef,0x03);
			
			if (MC501CB_Sensor_Status.MC501CB_curr_banding == CAM_BANDING_50HZ)
			{
				CamWriteCmosSensor(0x00,0x83);
			}
			else
			{
				CamWriteCmosSensor(0x00,0x43);
			}
			
			break;

		case CAM_WB_CLOUD:	
			CamWriteCmosSensor(0xef,0x03);
			
			if (MC501CB_Sensor_Status.MC501CB_curr_banding == CAM_BANDING_50HZ)
			{
				CamWriteCmosSensor(0x00,0x81);
			}
			else
			{
				CamWriteCmosSensor(0x00,0x41);
			}
			
			CamWriteCmosSensor(0xef,0x00);
			CamWriteCmosSensor(0x42,0x77);
			CamWriteCmosSensor(0x43,0x3d);
			CamWriteCmosSensor(0x44,0x47);
			break;

		case CAM_WB_DAYLIGHT:
			CamWriteCmosSensor(0xef,0x03);

			if (MC501CB_Sensor_Status.MC501CB_curr_banding == CAM_BANDING_50HZ)
			{
				CamWriteCmosSensor(0x00,0x81);
			}
			else
			{
				CamWriteCmosSensor(0x00,0x41);
			}
			
			CamWriteCmosSensor(0xef,0x00);
			CamWriteCmosSensor(0x42,0x60);	//0x67);
			CamWriteCmosSensor(0x43,0x40);
			CamWriteCmosSensor(0x44,0x50); //0x4c);
			break;

		case CAM_WB_INCANDESCENCE:
			CamWriteCmosSensor(0xef,0x03);

			if (MC501CB_Sensor_Status.MC501CB_curr_banding == CAM_BANDING_50HZ)
			{
				CamWriteCmosSensor(0x00,0x81);
			}
			else
			{
				CamWriteCmosSensor(0x00,0x41);
			}
			
			CamWriteCmosSensor(0xef,0x00);
			CamWriteCmosSensor(0x42,0x54); //0x44);
			CamWriteCmosSensor(0x43,0x40); //0x43);
			CamWriteCmosSensor(0x44,0x66); //0x7e);
			break;

		case CAM_WB_FLUORESCENT:
			CamWriteCmosSensor(0xef,0x03);

			if (MC501CB_Sensor_Status.MC501CB_curr_banding == CAM_BANDING_50HZ)
			{
				CamWriteCmosSensor(0x00,0x81);
			}
			else
			{
				CamWriteCmosSensor(0x00,0x41);
			}
			
			CamWriteCmosSensor(0xef,0x00);
			CamWriteCmosSensor(0x42,0x59); //0x5c);
			CamWriteCmosSensor(0x43,0x40);
			CamWriteCmosSensor(0x44,0x72); //0x6f);
			break;

		case CAM_WB_TUNGSTEN: // after calculate
			CamWriteCmosSensor(0xef,0x03);

			if (MC501CB_Sensor_Status.MC501CB_curr_banding == CAM_BANDING_50HZ)
			{
				CamWriteCmosSensor(0x00,0x81);
			}
			else
			{
				CamWriteCmosSensor(0x00,0x41);
			}
			
			CamWriteCmosSensor(0xef,0x00);
			CamWriteCmosSensor(0x42,0x3E); // 0x44);
			CamWriteCmosSensor(0x43,0x40); //0x3f);
			CamWriteCmosSensor(0x44,0x7D);//0x81);
			break;

		case CAM_WB_MANUAL:
			// TODO
			break;

		default:
			break;
		
	}
  }
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    MC501CBEffect
*
* DESCRIPTION
*    MC501CB Effect setting.
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
static MM_ERROR_CODE_ENUM MC501CBEffect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
  kal_uint8 EffectTemp = In->FeatureSetValue;
#ifdef MC501CB_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO,"Effect:%d",EffectTemp);
#endif
  switch (In->FeatureSetValue)
	{
		case CAM_EFFECT_ENC_NORMAL:
			CamWriteCmosSensor(0xef, 0x00); //Normal_Effect_table_start:
			CamWriteCmosSensor(0xd3, 0x00); 
			CamWriteCmosSensor(0xd4, 0x00); 
			CamWriteCmosSensor(0xd5, 0x01); 
			CamWriteCmosSensor(0xd6, 0xa3); 
			break;
		case CAM_EFFECT_ENC_GRAYSCALE:
			CamWriteCmosSensor(0xef, 0x00); //Gray_Effect_table_start:
			CamWriteCmosSensor(0xd3, 0x00);
			CamWriteCmosSensor(0xd4, 0x03);
			CamWriteCmosSensor(0xd5, 0x80);
			CamWriteCmosSensor(0xd6, 0x80);
			break;
		case CAM_EFFECT_ENC_SEPIA:
			CamWriteCmosSensor(0xef, 0x00); //Sepia_Effect_table_start:
			CamWriteCmosSensor(0xd3, 0x00);
			CamWriteCmosSensor(0xd4, 0x03);
			CamWriteCmosSensor(0xd5, 0x60);
			CamWriteCmosSensor(0xd6, 0x8c);
			break;
		case CAM_EFFECT_ENC_SEPIAGREEN:
			CamWriteCmosSensor(0xef, 0x00); //Green_Effect_table_start: 
			CamWriteCmosSensor(0xd3, 0x00);
			CamWriteCmosSensor(0xd4, 0x03);
			CamWriteCmosSensor(0xd5, 0x70);
			CamWriteCmosSensor(0xd6, 0x41);
			break;
		case CAM_EFFECT_ENC_SEPIABLUE:
			CamWriteCmosSensor(0xef, 0x00); //Blue_Effect_table_start:		
			CamWriteCmosSensor(0xd3, 0x00);
			CamWriteCmosSensor(0xd4, 0x03);
			CamWriteCmosSensor(0xd5, 0xac);
			CamWriteCmosSensor(0xd6, 0x80);
			break;
			case CAM_EFFECT_ENC_COLORINV:
			CamWriteCmosSensor(0xef, 0x00); //ColorInv_Effect_table_start:
			CamWriteCmosSensor(0xd3, 0x01);
			CamWriteCmosSensor(0xd4, 0x00);
			CamWriteCmosSensor(0xd5, 0x2c);
			CamWriteCmosSensor(0xd6, 0x81);
			break;

		default:
			break;
	}
  }   
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    MC501CBBanding
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
MM_ERROR_CODE_ENUM MC501CBBanding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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

	  // TODO: Set Banding need set again.
  }
  return MM_ERROR_NONE;
}



/*************************************************************************
* FUNCTION
*    MC501CBAeEnable
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
static MM_ERROR_CODE_ENUM MC501CBAeEnable(kal_bool Enable)
{
	MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
	
  kal_uint16 seq_preview_ae = 0;

	MC501CB_Select_Page(0x03);

	seq_preview_ae = CamReadCmosSensor(0x10);
  if (Enable)
  {
	  seq_preview_ae |= 0x80;
  }
  else
  {
	  seq_preview_ae &= 0x7F;
  }
  CamWriteCmosSensor(0x10, seq_preview_ae);

  return ErrCode;
}


/*************************************************************************
* FUNCTION
*    MC501CBAwbEnable
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
static MM_ERROR_CODE_ENUM MC501CBAwbEnable(kal_bool Enable)
{
	MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
	
  kal_uint16 seq_preview_awb = 0;

  MC501CB_Select_Page(0x04);
  seq_preview_awb = CamReadCmosSensor(0x10);

  if (Enable)
  {
	  seq_preview_awb |= 0x80;
  }
  else
  {
	  seq_preview_awb &= 0x7F;
  }
  CamWriteCmosSensor(0x10, seq_preview_awb);

  return ErrCode;
}


/*****************************************************************************
 * FUNCTION
 *  MC501CB_setflashlight
 * DESCRIPTION
 *  This function switch on/off flashligh of MC501CB.
 * PARAMETERS
 *  bEnable     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void MC501CB_setflashlight(kal_bool enable)
{
    /*MC501CB can not support the function*/
}



/*************************************************************************
* FUNCTION
*    MC501CBGetSensorInfo
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
static void MC501CBGetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT info)
{
	info->SensorId = MC501CB_SENSOR_ID;
	info->SensorIf = IMAGE_SENSOR_IF_PARALLEL;

	info->PixelClkInv			=	KAL_FALSE;
	info->PixelClkPolarity = POLARITY_LOW;
	info->HsyncPolarity = POLARITY_LOW;//POLARITY_HIGH;
	info->VsyncPolarity = POLARITY_HIGH;
	
	#if  (defined(DRV_ISP_6238_SERIES)|| defined(DRV_ISP_6276_SERIES))
		info->PreviewMclkFreq = 26000000;
		info->CaptureMclkFreq = 26000000;
		info->VideoMclkFreq = 26000000;
	#elif defined(DRV_ISP_6235_SERIES)
		info->PreviewMclkFreq = 26000000;
		info->CaptureMclkFreq = 26000000;
		info->VideoMclkFreq = 24000000;
	#endif
	
	info->PreviewWidth = MC501CB_IMAGE_SENSOR_VGA_WIDTH;
	info->PreviewHeight = MC501CB_IMAGE_SENSOR_VGA_HEIGHT;
	info->FullWidth = MC501CB_IMAGE_SENSOR_VGA_WIDTH;
	info->FullHeight = MC501CB_IMAGE_SENSOR_VGA_HEIGHT;
	info->SensorAfSupport = KAL_FALSE;
	info->SensorFlashSupport = KAL_FALSE;
}


/*************************************************************************
* FUNCTION
*    MC501CBPowerOn
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
static kal_uint16 MC501CBPowerOn(void)
{
	kal_uint16 MC501CB_sensor_id = 0;

	/* PowerOn the sensor */
	CisModulePowerOn(MC501CB_Sensor_Status.SensorIdx, KAL_TRUE);
	kal_sleep_task(2);  /* delay for power stable */

	CameraSccbOpen(CAMERA_SCCB_SENSOR, MC501CB_WRITE_ID, CAMERA_SCCB_8BIT, CAMERA_SCCB_8BIT, 300);

	CamPdnPinCtrl(MC501CB_Sensor_Status.SensorIdx, 1);	/* Set Power Down High */
	kal_sleep_task(1);

    /* Reset the sensor */
	CamRstPinCtrl(MC501CB_Sensor_Status.SensorIdx, 1);	/* Set Reset Pin High */
	kal_sleep_task(1);
	CamRstPinCtrl(MC501CB_Sensor_Status.SensorIdx, 0);	/* Set Reset Pin Low */
    kal_sleep_task(1);
	CamRstPinCtrl(MC501CB_Sensor_Status.SensorIdx, 1);	/* Set Reset Pin High */
    kal_sleep_task(1);  /* delay for stable sensor */

	// Above correct.

	// TODO: Need re-write it.
	
	CamWriteCmosSensor(0xEf,0x01);
	MC501CB_sensor_id = CamReadCmosSensor(0xc5);

	#ifdef MC501CB_OUTPUT_DEBUG_INFO
		kal_prompt_trace(MOD_ENG, "MC501CB Sensor ID=%x", MC501CB_sensor_id);
	#endif
	/* Read Sensor ID  */
	return MC501CB_sensor_id;
}

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
kal_uint32 MC501CBDetectSensorId(void)
{
	kal_uint32 SensorId=0;
	kal_uint16 ToPdnIdx = (IMAGE_SENSOR_MAIN == MC501CB_Sensor_Status.SensorIdx ? IMAGE_SENSOR_SUB : IMAGE_SENSOR_MAIN);
	kal_int8 i = 0, j = 0;

	for (i = 1; i >= 0; i--)
	{
		for (j = 1; j >= 0; j--)
		{
			/* Make the other camera into power down state. */
			CamRstPinCtrl(ToPdnIdx, i);
			CamRstPinCtrl(ToPdnIdx, j);
			
			SensorId = MC501CBPowerOn();
			
			MC501CBSensorClose();
			
			if (MC501CB_SENSOR_ID == SensorId)
			{
				return MC501CB_SENSOR_ID;
			}
		}
	}

	return 0xFFFFFFFF;
}	/* MC501CBDetectSensorId() */


/*************************************************************************
* FUNCTION
*    MC501CBStillCaptureSize
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
MM_ERROR_CODE_ENUM MC501CBStillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  P_CAL_FEATURE_TYPE_ENUM_STRUCT capsize = (P_CAL_FEATURE_TYPE_ENUM_STRUCT)&(Out->FeatureInfo.FeatureEnum);
  
  switch (In->FeatureCtrlCode)
  {
  case CAL_FEATURE_QUERY_OPERATION:
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|
                                   CAL_FEATURE_GET_OPERATION|
                                   CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
    capsize->IsSupport = KAL_TRUE;
    capsize->ItemCount = 2;
    capsize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
    capsize->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
    break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    MC501CBInitOperationPara
*
* DESCRIPTION
*    This function set sensor operation para
*
* PARAMETERS
*    para
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MC501CBInitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT para)
{
  para->CaptureDelayFrame = 2; /* wait stable frame when sensor change mode (pre to cap) */
  para->PreviewDelayFrame = 5; /* wait stable frame when sensor change mode (cap to pre) */
  para->PreviewDisplayWaitFrame = 2; /* wait stable frame when sensor change mode (cap to pre) */
}

MM_ERROR_CODE_ENUM MC501CBPreview(CAL_SCENARIO_ENUM ScenarioId,
								  P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In,
								  P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
	MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;

	kal_uint8 banding;

	#ifdef MC501CB_OUTPUT_DEBUG_INFO
		kal_wap_trace(MOD_ENG,TRACE_INFO, "MC501CB Preview");
	#endif

	MC501CB_Sensor_Status.MC501CB_curr_banding = In->BandingFreq;
	MC501CB_Sensor_Status.night_mode            = In->NightMode;
	
	CamWriteCmosSensor(0xef,0x03);

	if (MC501CB_Sensor_Status.MC501CB_curr_banding == CAM_BANDING_50HZ)
	{
		CamWriteCmosSensor(0x00,0x83);	 //enable AE & AWB	
	}
	else
	{
		CamWriteCmosSensor(0x00,0x43);	 //enable AE & AWB	
	}
	switch (ScenarioId)
	{
		case CAL_SCENARIO_VIDEO:
			MC501CB_Sensor_Status.video_mode = KAL_TRUE;
			MC501CB_Sensor_Status.video_frame_rate = In->MaxVideoFrameRate;
			break;
			
		case CAL_SCENARIO_CAMERA_PREVIEW:
		case CAL_SCENARIO_WEBCAM_PREVIEW:
		case CAL_SCENARIO_WEBCAM_CAPTURE:
			MC501CB_Sensor_Status.video_mode = KAL_FALSE;
			break;
			
		default:
			ASSERT(0);
			break;
	}
  
	MC501CB_SetHVMirror(In->ImageMirror);
	MC501CB_NightMode(MC501CB_Sensor_Status.night_mode);

	MC501CB_Sensor_Status.MC501CB_PV_dummy_pixels = 0;
	MC501CB_Sensor_Status.MC501CB_PV_dummy_lines = 0;		//For max preview frame rate 30fps.
	
	MC501CB_set_dummy(MC501CB_Sensor_Status.MC501CB_PV_dummy_pixels, MC501CB_Sensor_Status.MC501CB_PV_dummy_lines);

	Out->GrabStartX = 1;
	Out->GrabStartY = 2;
	Out->ExposureWindowWidth  = MC501CB_IMAGE_SENSOR_PV_WIDTH ; 
	Out->ExposureWindowHeight = MC501CB_IMAGE_SENSOR_PV_HEIGHT;

	return ErrCode;
} /* MC501CBPreview */

MM_ERROR_CODE_ENUM MC501CBCapture(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
	Out->GrabStartX = 1;
	Out->GrabStartY = 2;
	Out->ExposureWindowWidth = MC501CB_IMAGE_SENSOR_FULL_WIDTH; 
	Out->ExposureWindowHeight = MC501CB_IMAGE_SENSOR_FULL_HEIGHT;
	
	return MM_ERROR_NONE;
} /* MC501CBCapture() */


/*************************************************************************
* FUNCTION
*    MC501CBSensorOpen
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
static MM_ERROR_CODE_ENUM MC501CBSensorOpen(void)
{
	if (MC501CB_SENSOR_ID != MC501CBPowerOn())
		return MM_ERROR_SENSOR_READ_ID_FAIL;

    MC501CB_init_cmos_sensor();
	MC501CB_Sensor_Status.MC501CB_curr_banding = CAM_BANDING_50HZ;
	MC501CB_Sensor_Status.video_mode = KAL_FALSE;
	MC501CB_Sensor_Status.night_mode = KAL_FALSE;
	
	return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    MC501CBSensorFeatureCtrl
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
static MM_ERROR_CODE_ENUM MC501CBSensorFeatureCtrl(kal_uint32 id, void *In, void *Out, kal_uint32 out_len, kal_uint32 *r_out_len)
{
  MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
  kal_uint32 TmpFrameRate;

    P_CAL_FEATURE_CTRL_STRUCT pCameraFeatureIn=(P_CAL_FEATURE_CTRL_STRUCT) In;
    P_CAL_FEATURE_CTRL_STRUCT pCameraFeatureOut=(P_CAL_FEATURE_CTRL_STRUCT) Out;
    // for camera HAL UT only
    P_CAL_FEATURE_TYPE_ENUM_STRUCT pCamFeatureEnum=(P_CAL_FEATURE_TYPE_ENUM_STRUCT) &(pCameraFeatureOut->FeatureInfo.FeatureEnum);
    P_CAL_CAMERA_DIGITAL_ZOOM_OUT_STRUCT pCameraDzOut=pCameraFeatureOut->FeatureInfo.FeatureStructured.pCamDzOutPara;


  if (id >= CAL_FEATURE_WEBCAM_BEGIN && id <= CAL_FEATURE_WEBCAM_END)
  {
    return MC501CBWebcamFeatureCtrl(id, In, Out, out_len, r_out_len);
  }

  if(Out!=NULL && CAL_FEATURE_QUERY_OPERATION==pCameraFeatureIn->FeatureCtrlCode){
        pCamFeatureEnum->IsSupport = KAL_FALSE;
  }

  switch (id)
  {
     /* CAL Query and set series */
    case CAL_FEATURE_CAMERA_BRIGHTNESS:
    case CAL_FEATURE_CAMERA_EV_VALUE:
      ErrCode = MC501CBEV(In, Out);
      break;
    case CAL_FEATURE_CAMERA_CONTRAST:
    case CAL_FEATURE_CAMERA_HUE:
    case CAL_FEATURE_CAMERA_SATURATION:
    case CAL_FEATURE_CAMERA_SHARPNESS:
    case CAL_FEATURE_CAMERA_GAMMA:
      ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
      break;
    case CAL_FEATURE_CAMERA_WB:
      ErrCode = MC501CBWB(In, Out);
      break;
    case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
      ErrCode = MC501CBEffect(In, Out);
      break;
    case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
      ErrCode = MC501CBStillCaptureSize(In, Out);
      break;
    case CAL_FEATURE_CAMERA_BANDING_FREQ: /* move to preview */
      ErrCode = MC501CBBanding(In, Out);
      break;
    case CAL_FEATURE_CAMERA_FLASH_MODE:
      ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
      break;

    /* Get Info series */
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
      MC501CBGetSensorInfo((P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT)Out);
      break;
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
      ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = MC501CBDetectSensorId();
      break;
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
      ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = MC501CB_Sensor_Status.video_frame_rate;
      break;
    case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
      MC501CBInitOperationPara((P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT)Out);
      break;

	case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
		CamPdnPinCtrl(MC501CB_Sensor_Status.SensorIdx, 0);
		CamRstPinCtrl(MC501CB_Sensor_Status.SensorIdx, 0);		// OV7675 don't have the reset pin.
		break;
    /* Set Para series */
    case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
      ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
      break;      
    case IMAGE_SENSOR_FEATURE_VSYNC_HISR_INFORM_FRAME_TIME:
      TmpFrameRate = ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
    break;      
    case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
      MC501CB_Sensor_Status.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
      break;
    case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
      break;     
	case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
		ErrCode = MC501CBAeEnable((kal_bool)(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue));
		break;
	case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
		ErrCode = MC501CBAwbEnable((kal_bool)(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue));
		break;
	case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
	    CamGetHWInfo(MC501CB_Sensor_Status.SensorIdx, Out);
	    break;
    default:
      ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
      break;
  }
  return ErrCode;
}

/*************************************************************************
* FUNCTION
*    MC501CBSensorCtrl
*
* DESCRIPTION
*    This function set sensor scenario mode
*
* PARAMETERS
*    id: scenario id
*    In/Out: parameter
*    out_len: Out parameter length
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM MC501CBSensorCtrl(CAL_SCENARIO_ENUM id, void *In, void *Out, kal_uint16 out_len)
{
  switch (id)
  {
  case CAL_SCENARIO_CAMERA_PREVIEW:
  case CAL_SCENARIO_VIDEO:
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE: 
  	MC501CBPreview(id, In, Out); 
	break;
  case CAL_SCENARIO_CAMERA_STILL_CAPTURE: 
  	MC501CBCapture(id, In, Out);
	break;
  default: break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    MC501CBSensorClose
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
MM_ERROR_CODE_ENUM MC501CBSensorClose(void)
{
#ifdef MC501CB_OUTPUT_DEBUG_INFO
		kal_prompt_trace(MOD_ENG, "XXX_Power off");
#endif
	CameraSccbClose(CAMERA_SCCB_SENSOR);

	CisModulePowerOn(MC501CB_Sensor_Status.SensorIdx, KAL_FALSE);
    
	return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    MC501CBSensorFunc
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
MM_ERROR_CODE_ENUM MC501CBSensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncMC501CB=
  {
    MC501CBSensorOpen,
    MC501CBSensorFeatureCtrl,
    MC501CBSensorCtrl,
    MC501CBSensorClose,
  };
  
  *pfSensorFunc = &ImageSensorFuncMC501CB;
}

