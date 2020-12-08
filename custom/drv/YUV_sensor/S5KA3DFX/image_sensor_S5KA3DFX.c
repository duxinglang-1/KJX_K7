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
#include "image_sensor_S5KA3DFX.h"

#include "Cal_comm_def.h"
#include "isp_if.h"

struct S5KA3DFX_SENSOR_STRUCT
{
	kal_bool night_mode;
	kal_bool video_mode;
	kal_uint16 video_current_frame_rate;
	kal_uint16 video_frame_rate;
	kal_uint16 S5KA3DFX_curr_banding;
	kal_uint16 S5KA3DFX_PV_dummy_pixels;
	kal_uint16 S5KA3DFX_PV_dummy_lines;
	kal_uint16 S5KA3DFX_CAP_dummy_pixels;
	kal_uint16 S5KA3DFX_CAP_dummy_lines;
	IMAGE_SENSOR_INDEX_ENUM SensorIdx;
	sensor_data_struct *nvram_data;
};

// Better mask it when release.
//#define S5KA3DFX_OUTPUT_DEBUG_INFO

#define S5KA3DFX_CAP_GAIN_2_ShUTTER

static struct S5KA3DFX_SENSOR_STRUCT S5KA3DFX_Sensor_Status;

extern void CamWriteCmosSensor(kal_uint16 addr, kal_uint16 para);
extern kal_uint16 CamReadCmosSensor(kal_uint16 addr);

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif


/*****************************************************************************
 * FUNCTION
 *  S5KA3DFX_Select_Page
 * DESCRIPTION
 *
 * PARAMETERS
 *  shutter     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void S5KA3DFX_Select_Page(kal_uint16 page)
{
	//Page address
	// 0x00h, ISP Control Register 1
	// 0x01h, ISP Control Register 2
	// 0x02h, Sensor and TG Control Registers
	// 0x03h, Tuning Parameters.
	ASSERT((page == 0x00) || (page == 0x01) || (page == 0x02) || (page == 0x03));
	
	CamWriteCmosSensor(0xef, page);
}   /* S5Ka3dFX_Select_Page */


/*****************************************************************************
 * FUNCTION
 *  S5KA3DFX_write_shutter
 * DESCRIPTION
 *
 * PARAMETERS
 *  shutter     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
//void S5KA3DFX_write_shutter(kal_uint16 cintr,kal_uint16 cintc)
void S5KA3DFX_write_shutter(kal_uint16 shutter)

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

}   /* S5KA3DFX_write_shutter */

void S5KA3DFX_write_cintc(kal_uint16 cintc)

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

}   /* S5KA3DFX_write_shutter */



/*****************************************************************************
 * FUNCTION
 *  S5KA3DFX_read_shutter
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_uint16 S5KA3DFX_read_shutter(void)
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
}   /* S5KA3DFX_read_shutter */

kal_uint16 S5KA3DFX_read_cintc(void)
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
}   /* S5KA3DFX_read_shutter */


/*****************************************************************************
 * FUNCTION
 *  S5KA3DFX_set_dummy
 * DESCRIPTION
 *
 * PARAMETERS
 *  pixels      [IN]
 *  lines       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void S5KA3DFX_set_dummy(kal_uint16 dummy_pixels, kal_uint16 dummy_lines)
{
	dummy_pixels += S5KA3DFX_VGA_DEFAULT_H_BLANK;
	dummy_lines += S5KA3DFX_VGA_DEFAULT_V_BLANK;

	ASSERT(dummy_pixels <= S5KA3DFX_MAX_H_BLANK);
	ASSERT(dummy_lines <= S5KA3DFX_MAX_V_BLANK);

	//Set V Blanking
	S5KA3DFX_Select_Page(S5KA3DFX_PAGE_3);
	CamWriteCmosSensor(0x63, (dummy_lines >> 8) & 0xff);	//NTSC
	CamWriteCmosSensor(0x64, dummy_lines & 0xff);
	CamWriteCmosSensor(0x65, (dummy_lines >> 8) & 0xff);	//PAL
	CamWriteCmosSensor(0x66, dummy_lines & 0xff);

	//Set H Blanking
	S5KA3DFX_Select_Page(S5KA3DFX_PAGE_3);
	CamWriteCmosSensor(0x48, (dummy_pixels >> 8) & 0xff);
	CamWriteCmosSensor(0x49, dummy_pixels & 0xff);
	CamWriteCmosSensor(0x4c, (dummy_pixels >> 8) & 0xff);
	CamWriteCmosSensor(0x4d, dummy_pixels & 0xff);
	S5KA3DFX_Select_Page(S5KA3DFX_PAGE_2);
	CamWriteCmosSensor(0x1a,(dummy_pixels >> 8) & 0xff);	//Must set the same value with HBLANK.
	CamWriteCmosSensor(0x1b,dummy_pixels & 0xff);
}   /* S5KA3DFX_set_dummy */

void S5KA3DFX_SetHVMirror(kal_uint8 Mirror)
{
	switch (Mirror)
	{
		case IMAGE_SENSOR_MIRROR_NORMAL:
			CamWriteCmosSensor(0xEF, 0x03);
			CamWriteCmosSensor(0x70, 0x00);//evt1
		break;
		case IMAGE_SENSOR_MIRROR_H:
			CamWriteCmosSensor(0xEF, 0x03);
			CamWriteCmosSensor(0x70, 0x01);
		break;
		case IMAGE_SENSOR_MIRROR_V:
			CamWriteCmosSensor(0xEF, 0x03);
			CamWriteCmosSensor(0x70, 0x02);
		break;
		case IMAGE_SENSOR_MIRROR_HV:
			CamWriteCmosSensor(0xEF, 0x03);
			CamWriteCmosSensor(0x70, 0x03);//evt1
		break;
	}
}

/*****************************************************************************
 * FUNCTION
 *  S5KA3DFX_init_cmos_sensor
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void S5KA3DFX_init_cmos_sensor()
{
	//==================================================
	//	Command setting
	//==================================================
	CamWriteCmosSensor(0xef, 0x03);
	if (S5KA3DFX_Sensor_Status.S5KA3DFX_curr_banding == CAM_BANDING_50HZ)
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
#ifdef S5KA3DFX_AE_WINDOW_OSD_DISPLAY
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




void S5KA3DFX_camera_dynamic_framerate_normalmode()
{

	//Please attach the following setting values 	 29~10 fps
	//at the top of a SET file.------------------------
	//<Rising Edge of Vsync>
	CamWriteCmosSensor(0xEF, 0x00);
	CamWriteCmosSensor(0x07, 0x03);
	CamWriteCmosSensor(0x07, 0x10);
	CamWriteCmosSensor(0x08, 0x03);
	CamWriteCmosSensor(0x06, 0x03);
	CamWriteCmosSensor(0xEF, 0x03);
	CamWriteCmosSensor(0x05, 0x02);
	//---------------------------------------------

	CamWriteCmosSensor(0xEF, 0x03); 
	CamWriteCmosSensor(0x50, 0xE6); 	//Mclk
	CamWriteCmosSensor(0x5F, 0x03); 	//NT Cintr Max
	CamWriteCmosSensor(0x60, 0x02); 	//PAL Cintr Max
	CamWriteCmosSensor(0x61, 0x0C); 	//NT shutter Max (FrameAE mode)
	CamWriteCmosSensor(0x62, 0x0A); 	//PAL shutter Max (FrameAE mode)
	
	CamWriteCmosSensor(0x6E, 0x40); 	//Dgain Min
	CamWriteCmosSensor(0x6F, 0x5A); 	//Dgain Max
	
	CamWriteCmosSensor(0x63, 0x00); 	//NT Vblank
	CamWriteCmosSensor(0x64, 0x37); 
	CamWriteCmosSensor(0x65, 0x00); 	//PAL Vblank
	CamWriteCmosSensor(0x66, 0x37); 
	
	CamWriteCmosSensor(0x48, 0x00); 	//NT Hblank
	CamWriteCmosSensor(0x49, 0x9E); 
	CamWriteCmosSensor(0x4C, 0x00); 	//PAL Hblank
	CamWriteCmosSensor(0x4D, 0x9E); 

	//AE Speed Setting ----------------------------
	CamWriteCmosSensor(0xEF, 0x03);
	CamWriteCmosSensor(0x51, 0x11);
	CamWriteCmosSensor(0x52, 0x10);
	CamWriteCmosSensor(0x53, 0x00);
	CamWriteCmosSensor(0x54, 0x01);
	CamWriteCmosSensor(0x56, 0x22);
	CamWriteCmosSensor(0x57, 0x41);
	CamWriteCmosSensor(0x58, 0x27);
	CamWriteCmosSensor(0x67, 0xAA);
}

void S5KA3DFX_camera_dynamic_framerate_nightmode()
{

	//Please attach the following setting values 	29~6fps
	//at the top of a SET file.------------------------
	//<Rising Edge of Vsync>
	CamWriteCmosSensor(0xEF, 0x00);
	CamWriteCmosSensor(0x07, 0x03);
	CamWriteCmosSensor(0x07, 0x10);
	CamWriteCmosSensor(0x08, 0x03);
	CamWriteCmosSensor(0x06, 0x03);
	CamWriteCmosSensor(0xEF, 0x03);
	CamWriteCmosSensor(0x05, 0x02);
	//---------------------------------------------

	CamWriteCmosSensor(0xEF, 0x03); 
	CamWriteCmosSensor(0x50, 0xE6); 	//Mclk
	CamWriteCmosSensor(0x5F, 0x03); 	//NT Cintr Max
	CamWriteCmosSensor(0x60, 0x02); 	//PAL Cintr Max
	CamWriteCmosSensor(0x61, 0x14); 	//NT shutter Max (FrameAE mode)
	CamWriteCmosSensor(0x62, 0x10); 	//PAL shutter Max (FrameAE mode)
	
	CamWriteCmosSensor(0x6E, 0x40); 	//Dgain Min
	CamWriteCmosSensor(0x6F, 0x5A); 	//Dgain Max
	
	CamWriteCmosSensor(0x63, 0x00); 	//NT Vblank
	CamWriteCmosSensor(0x64, 0x37); 
	CamWriteCmosSensor(0x65, 0x00); 	//PAL Vblank
	CamWriteCmosSensor(0x66, 0x37); 
	
	CamWriteCmosSensor(0x48, 0x00); 	//NT Hblank
	CamWriteCmosSensor(0x49, 0x9E); 
	CamWriteCmosSensor(0x4C, 0x00); 	//PAL Hblank
	CamWriteCmosSensor(0x4D, 0x9E); 

	//AE Speed Setting ----------------------------
	CamWriteCmosSensor(0xEF, 0x03);
	CamWriteCmosSensor(0x51, 0x11);
	CamWriteCmosSensor(0x52, 0x10);
	CamWriteCmosSensor(0x53, 0x00);
	CamWriteCmosSensor(0x54, 0x01);
	CamWriteCmosSensor(0x56, 0x22);
	CamWriteCmosSensor(0x57, 0x41);
	CamWriteCmosSensor(0x58, 0x27);
	CamWriteCmosSensor(0x67, 0xAA);
}
void S5KA3DFX_video_fix_framerate()
{

    if(S5KA3DFX_Sensor_Status.video_frame_rate >250)
	{
	
		//Please attach the following setting values 	29 fps
		//at the top of a SET file.------------------------
		//<Rising Edge of Vsync>
		CamWriteCmosSensor(0xEF, 0x00);
		CamWriteCmosSensor(0x07, 0x03);
		CamWriteCmosSensor(0x07, 0x10);
		CamWriteCmosSensor(0x08, 0x03);
		CamWriteCmosSensor(0x06, 0x03);
		CamWriteCmosSensor(0xEF, 0x03);
		CamWriteCmosSensor(0x05, 0x02);
		//---------------------------------------------

		CamWriteCmosSensor(0xEF, 0x03);
		CamWriteCmosSensor(0x50, 0xE6);	//Mclk
		CamWriteCmosSensor(0x5F, 0x04);	//NT Cintr Max
		CamWriteCmosSensor(0x60, 0x03);	//PAL Cintr Max
		CamWriteCmosSensor(0x61, 0x04);	//NT shutter Max (Fixed mode)
		CamWriteCmosSensor(0x62, 0x03);	//PAL shutter Max (Fixed mode)
		CamWriteCmosSensor(0x6E, 0x40);	//Dgain Min
		CamWriteCmosSensor(0x6F, 0x40);	//Dgain Max
		CamWriteCmosSensor(0x63, 0x00);	//NT Vblank
		CamWriteCmosSensor(0x64, 0x37);
		CamWriteCmosSensor(0x65, 0x00);	//PAL Vblank
		CamWriteCmosSensor(0x66, 0x37);
		CamWriteCmosSensor(0x48, 0x00);	//NT Hblank
		CamWriteCmosSensor(0x49, 0x9E);
		CamWriteCmosSensor(0x4C, 0x00);	//PAL Hblank
		CamWriteCmosSensor(0x4D, 0x9E);

		//AE Speed Setting ----------------------------
		CamWriteCmosSensor(0xEF, 0x03);
		CamWriteCmosSensor(0x51, 0x11);
		CamWriteCmosSensor(0x52, 0x10);
		CamWriteCmosSensor(0x53, 0x00);
		CamWriteCmosSensor(0x54, 0x01);
		CamWriteCmosSensor(0x56, 0x22);
		CamWriteCmosSensor(0x57, 0x41);
		CamWriteCmosSensor(0x58, 0x27);
		CamWriteCmosSensor(0x67, 0xAA);
		
	}
	else if(S5KA3DFX_Sensor_Status.video_frame_rate < 250  && S5KA3DFX_Sensor_Status.video_frame_rate >190)
	{   
	
		//20fps
		CamWriteCmosSensor(0xEF, 0x03);
		CamWriteCmosSensor(0x05, 0x01);
		//---------------------------------------------

		CamWriteCmosSensor(0xEF, 0x03); 
		CamWriteCmosSensor(0x50, 0xE6); 	//Mclk
			CamWriteCmosSensor(0x5F, 0x06); //NT Cintr Max
			CamWriteCmosSensor(0x60, 0x05); //PAL Cintr Max
			CamWriteCmosSensor(0x61, 0x06); //NT shutter Max (Fixed mode)
			CamWriteCmosSensor(0x62, 0x05); //PAL shutter Max (Fixed mode)
			CamWriteCmosSensor(0x6E, 0x40); //Dgain Min
			CamWriteCmosSensor(0x6F, 0x40); //Dgain Max
			CamWriteCmosSensor(0x63, 0x01); //NT Vblank
			CamWriteCmosSensor(0x64, 0x2F);
			CamWriteCmosSensor(0x65, 0x01); //PAL Vblank
			CamWriteCmosSensor(0x66, 0x2F);
		CamWriteCmosSensor(0x48, 0x00); 	//NT Hblank
		CamWriteCmosSensor(0x49, 0x9E); 
		CamWriteCmosSensor(0x4C, 0x00); 	//PAL Hblank
		CamWriteCmosSensor(0x4D, 0x9E); 

		//AE Speed Setting ----------------------------
		CamWriteCmosSensor(0xEF, 0x03);
		CamWriteCmosSensor(0x51, 0x10);
		CamWriteCmosSensor(0x52, 0x00);
		CamWriteCmosSensor(0x53, 0x00);
		CamWriteCmosSensor(0x54, 0x00);
		CamWriteCmosSensor(0x56, 0x01);
		CamWriteCmosSensor(0x57, 0x61);
		CamWriteCmosSensor(0x58, 0x25);
		CamWriteCmosSensor(0x67, 0xCF);	
	}
	else if(S5KA3DFX_Sensor_Status.video_frame_rate <= 190 && S5KA3DFX_Sensor_Status.video_frame_rate >140)
	{
	
		// Non use the advance resizer, then sensor output 15fps.
		//Please attach the following setting values  15fps
		//at the top of a SET file.------------------------
		//<Falling Edge of Vsync>
		CamWriteCmosSensor(0xEF, 0x03);
		CamWriteCmosSensor(0x05, 0x01);
		//---------------------------------------------
		
		CamWriteCmosSensor(0xEF, 0x03); 
		CamWriteCmosSensor(0x50, 0xE6); 	//Mclk
		CamWriteCmosSensor(0x5F, 0x08); 	//NT Cintr Max
		CamWriteCmosSensor(0x60, 0x06); 	//PAL Cintr Max
		CamWriteCmosSensor(0x61, 0x08); 	//NT shutter Max (Fixed mode)
		CamWriteCmosSensor(0x62, 0x06); 	//PAL shutter Max (Fixed mode)
		CamWriteCmosSensor(0x6E, 0x40); 	//Dgain Min
		CamWriteCmosSensor(0x6F, 0x40); 	//Dgain Max
		CamWriteCmosSensor(0x63, 0x02); 	//NT Vblank
		CamWriteCmosSensor(0x64, 0x39); 
		CamWriteCmosSensor(0x65, 0x02); 	//PAL Vblank
		CamWriteCmosSensor(0x66, 0x39); 
		CamWriteCmosSensor(0x48, 0x00); 	//NT Hblank
		CamWriteCmosSensor(0x49, 0x9E); 
		CamWriteCmosSensor(0x4C, 0x00); 	//PAL Hblank
		CamWriteCmosSensor(0x4D, 0x9E); 
		
		//AE Speed Setting ----------------------------
		CamWriteCmosSensor(0xEF, 0x03);
		CamWriteCmosSensor(0x51, 0x10);
		CamWriteCmosSensor(0x52, 0x00);
		CamWriteCmosSensor(0x53, 0x00);
		CamWriteCmosSensor(0x54, 0x00);
		CamWriteCmosSensor(0x56, 0x01);
		CamWriteCmosSensor(0x57, 0x61);
		CamWriteCmosSensor(0x58, 0x25);
		CamWriteCmosSensor(0x67, 0xCF);	
	}
	else if(S5KA3DFX_Sensor_Status.video_frame_rate <= 140 && S5KA3DFX_Sensor_Status.video_frame_rate >110)
	{
	
		 //12fps
		 CamWriteCmosSensor(0xEF, 0x03);
		CamWriteCmosSensor(0x05, 0x01);
		//---------------------------------------------
		
		CamWriteCmosSensor(0xEF, 0x03);
		CamWriteCmosSensor(0x50, 0xE6); //Mclk
		CamWriteCmosSensor(0x5F, 0x0A); //NT Cintr Max
		CamWriteCmosSensor(0x60, 0x08); //PAL Cintr Max
		CamWriteCmosSensor(0x61, 0x0A); //NT shutter Max (Fixed mode)
		CamWriteCmosSensor(0x62, 0x08); //PAL shutter Max (Fixed mode)
		CamWriteCmosSensor(0x6E, 0x40); //Dgain Min
		CamWriteCmosSensor(0x6F, 0x40); //Dgain Max
		CamWriteCmosSensor(0x63, 0x03); //NT Vblank
		CamWriteCmosSensor(0x64, 0x43);
		CamWriteCmosSensor(0x65, 0x03); //PAL Vblank
		CamWriteCmosSensor(0x66, 0x43);
		CamWriteCmosSensor(0x48, 0x00); //NT Hblank
		CamWriteCmosSensor(0x49, 0x9E);
		CamWriteCmosSensor(0x4C, 0x00); //PAL Hblank
		CamWriteCmosSensor(0x4D, 0x9E);
		
		//AE Speed Setting ----------------------------
		CamWriteCmosSensor(0xEF, 0x03);
		CamWriteCmosSensor(0x51, 0x10);
		CamWriteCmosSensor(0x52, 0x00);
		CamWriteCmosSensor(0x53, 0x00);
		CamWriteCmosSensor(0x54, 0x00);
		CamWriteCmosSensor(0x56, 0x01);
		CamWriteCmosSensor(0x57, 0x61);
		CamWriteCmosSensor(0x58, 0x25);
		CamWriteCmosSensor(0x67, 0xCF);
	}
	else if(S5KA3DFX_Sensor_Status.video_frame_rate <= 110 && S5KA3DFX_Sensor_Status.video_frame_rate >90)
	{
	
		 //10fps
		 CamWriteCmosSensor(0xEF, 0x03);
		CamWriteCmosSensor(0x05, 0x01);
		//---------------------------------------------
		
		CamWriteCmosSensor(0xEF, 0x03);
		CamWriteCmosSensor(0x50, 0xE6); //Mclk
		CamWriteCmosSensor(0x5F, 0x0C); //NT Cintr Max
		CamWriteCmosSensor(0x60, 0x0A); //PAL Cintr Max
		CamWriteCmosSensor(0x61, 0x0C); //NT shutter Max (Fixed mode)
		CamWriteCmosSensor(0x62, 0x0A); //PAL shutter Max (Fixed mode)
		CamWriteCmosSensor(0x6E, 0x40); //Dgain Min
		CamWriteCmosSensor(0x6F, 0x40); //Dgain Max
		CamWriteCmosSensor(0x63, 0x04); //NT Vblank
		CamWriteCmosSensor(0x64, 0x4E);
		CamWriteCmosSensor(0x65, 0x04); //PAL Vblank
		CamWriteCmosSensor(0x66, 0x4E);
		CamWriteCmosSensor(0x48, 0x00); //NT Hblank
		CamWriteCmosSensor(0x49, 0x9E);
		CamWriteCmosSensor(0x4C, 0x00); //PAL Hblank
		CamWriteCmosSensor(0x4D, 0x9E);
		
		//AE Speed Setting ----------------------------
		CamWriteCmosSensor(0xEF, 0x03);
		CamWriteCmosSensor(0x51, 0x10);
		CamWriteCmosSensor(0x52, 0x00);
		CamWriteCmosSensor(0x53, 0x00);
		CamWriteCmosSensor(0x54, 0x00);
		CamWriteCmosSensor(0x56, 0x01);
		CamWriteCmosSensor(0x57, 0x61);
		CamWriteCmosSensor(0x58, 0x25);
		CamWriteCmosSensor(0x67, 0xCF);
	}
	else if(S5KA3DFX_Sensor_Status.video_frame_rate <= 90 && S5KA3DFX_Sensor_Status.video_frame_rate >60)
	{
	
		//Please attach the following setting values  7.5fps for video call night mode.
		//at the top of a SET file.------------------------
		//<Falling Edge of Vsync>
		CamWriteCmosSensor(0xEF, 0x03);
		CamWriteCmosSensor(0x05, 0x01);
		//---------------------------------------------
		
		CamWriteCmosSensor(0xEF, 0x03);
		CamWriteCmosSensor(0x50, 0xE6); //Mclk
		CamWriteCmosSensor(0x5F, 0x0F); //NT Cintr Max
		CamWriteCmosSensor(0x60, 0x0C); //PAL Cintr Max
		CamWriteCmosSensor(0x61, 0x0F); //NT shutter Max (Fixed mode)
		CamWriteCmosSensor(0x62, 0x0C); //PAL shutter Max (Fixed mode)
		CamWriteCmosSensor(0x6E, 0x40); //Dgain Min
		CamWriteCmosSensor(0x6F, 0x40); //Dgain Max
		CamWriteCmosSensor(0x63, 0x06); //NT Vblank
		CamWriteCmosSensor(0x64, 0x62);
		CamWriteCmosSensor(0x65, 0x06); //PAL Vblank
		CamWriteCmosSensor(0x66, 0x62);
		CamWriteCmosSensor(0x48, 0x00); //NT Hblank
		CamWriteCmosSensor(0x49, 0x9E);
		CamWriteCmosSensor(0x4C, 0x00); //PAL Hblank
		CamWriteCmosSensor(0x4D, 0x9E);
		
		//AE Speed Setting ----------------------------
		CamWriteCmosSensor(0xEF, 0x03);
		CamWriteCmosSensor(0x51, 0x10);
		CamWriteCmosSensor(0x52, 0x00);
		CamWriteCmosSensor(0x53, 0x00);
		CamWriteCmosSensor(0x54, 0x00);
		CamWriteCmosSensor(0x56, 0x01);
		CamWriteCmosSensor(0x57, 0x61);
		CamWriteCmosSensor(0x58, 0x25);
		CamWriteCmosSensor(0x67, 0xCF);
	}
	else if(S5KA3DFX_Sensor_Status.video_frame_rate <= 60 )
	{ 
	
	    //5fps
		CamWriteCmosSensor(0xEF, 0x03);
		CamWriteCmosSensor(0x05, 0x01);
		//---------------------------------------------
		
		CamWriteCmosSensor(0xEF, 0x03);
		CamWriteCmosSensor(0x50, 0xE6); //Mclk
		CamWriteCmosSensor(0x5F, 0x18); //NT Cintr Max
		CamWriteCmosSensor(0x60, 0x14); //PAL Cintr Max
		CamWriteCmosSensor(0x61, 0x18); //NT shutter Max (Fixed mode)
		CamWriteCmosSensor(0x62, 0x14); //PAL shutter Max (Fixed mode)
		CamWriteCmosSensor(0x6E, 0x40); //Dgain Min
		CamWriteCmosSensor(0x6F, 0x40); //Dgain Max
		CamWriteCmosSensor(0x63, 0x0A); //NT Vblank
		CamWriteCmosSensor(0x64, 0x8B);
		CamWriteCmosSensor(0x65, 0x0A); //PAL Vblank
		CamWriteCmosSensor(0x66, 0x8B);
		CamWriteCmosSensor(0x48, 0x00); //NT Hblank
		CamWriteCmosSensor(0x49, 0x9E);
		CamWriteCmosSensor(0x4C, 0x00); //PAL Hblank
		CamWriteCmosSensor(0x4D, 0x9E);
		
		//AE Speed Setting ----------------------------
		CamWriteCmosSensor(0xEF, 0x03);
		CamWriteCmosSensor(0x51, 0x10);
		CamWriteCmosSensor(0x52, 0x00);
		CamWriteCmosSensor(0x53, 0x00);
		CamWriteCmosSensor(0x54, 0x00);
		CamWriteCmosSensor(0x56, 0x01);
		CamWriteCmosSensor(0x57, 0x61);
		CamWriteCmosSensor(0x58, 0x25);
		CamWriteCmosSensor(0x67, 0xCF);
	}
	else
	    ASSERT(0);
}

//zhijie

/*************************************************************************
* FUNCTION
*    S5KA3DFX_NightMode
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
static void S5KA3DFX_NightMode(kal_bool bEnable)
{    
	#ifdef S5KA3DFX_OUTPUT_DEBUG_INFO
		kal_wap_trace(MOD_ENG,TRACE_INFO, "S5KA3DFX NightMode %d",bEnable);
	#endif
	if (S5KA3DFX_Sensor_Status.video_mode == KAL_FALSE)// camera mode
	{
		if (KAL_TRUE == bEnable)
		{ /* camera night mode */
			#ifdef S5KA3DFX_OUTPUT_DEBUG_INFO
				kal_wap_trace(MOD_ENG,TRACE_INFO, "camera night mode");
			#endif
			CamWriteCmosSensor(0xEF,0x03);

			CamWriteCmosSensor(0x6d,0x50);
			CamWriteCmosSensor(0x6e,0x40);

			CamWriteCmosSensor(0x6f,0x5a);	//Low light digital gain max
			
			CamWriteCmosSensor(0xef,0x00);
			CamWriteCmosSensor(0xed,0x30);
			
			S5KA3DFX_camera_dynamic_framerate_nightmode();
		}
		else
		{   /* camera normal mode */
			#ifdef S5KA3DFX_OUTPUT_DEBUG_INFO
				kal_wap_trace(MOD_ENG,TRACE_INFO, "camera normal mode");
			#endif
			CamWriteCmosSensor(0xEF,0x03);

			CamWriteCmosSensor(0x6d,0x50);
			CamWriteCmosSensor(0x6e,0x40);
			
			CamWriteCmosSensor(0x6f,0x5a);
			
			CamWriteCmosSensor(0xef,0x00);
			CamWriteCmosSensor(0xed,0x05);
			S5KA3DFX_camera_dynamic_framerate_normalmode();
		}
	}
  else //video mode
  {
    if (KAL_TRUE == bEnable)
    {   /* video night mode */
#ifdef S5KA3DFX_OUTPUT_DEBUG_INFO
      kal_wap_trace(MOD_ENG,TRACE_INFO, "video night mode");
#endif
			CamWriteCmosSensor(0xEF,0x03);

			CamWriteCmosSensor(0x6d,0x50);
			CamWriteCmosSensor(0x6e,0x40);

			CamWriteCmosSensor(0x6f,0x5a);	//Low light digital gain max
			
			CamWriteCmosSensor(0xef,0x00);
			CamWriteCmosSensor(0xed,0x30);
    }
    else
    {   /* video normal mode */
#ifdef S5KA3DFX_OUTPUT_DEBUG_INFO
      kal_wap_trace(MOD_ENG,TRACE_INFO, "video normal mode");
#endif
			CamWriteCmosSensor(0xEF,0x03);

			CamWriteCmosSensor(0x6d,0x50);
			CamWriteCmosSensor(0x6e,0x40);
			
			CamWriteCmosSensor(0x6f,0x5a);
			
			CamWriteCmosSensor(0xef,0x00);
			CamWriteCmosSensor(0xed,0x05);
		}
		
		S5KA3DFX_video_fix_framerate();
	
		CamWriteCmosSensor(0xEF, 0x03);
		CamWriteCmosSensor(0x37, 0x2A); 	//Increase low light saturaton
  }
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
#endif
	}
}

/*************************************************************************
* FUNCTION
*    S5KA3DFXEV
*
* DESCRIPTION
*    S5KA3DFX EV setting.
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
static MM_ERROR_CODE_ENUM S5KA3DFXSceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    S5KA3DFX_NightMode(Enable);
  }
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM S5KA3DFXEV(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
	MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;
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
  	switch (In->FeatureSetValue)
	{
      case CAM_EV_NEG_4_3: 
		CamWriteCmosSensor(0xef,0x03); 
		CamWriteCmosSensor(0x31,0x98);   //a0
		CamWriteCmosSensor(0x32,0x90);   //98
		break;
  	  case CAM_EV_NEG_3_3:
		CamWriteCmosSensor(0xef,0x03);
		CamWriteCmosSensor(0x31,0x90);   //98
		CamWriteCmosSensor(0x32,0x88);   //90
		break;
  	  case CAM_EV_NEG_2_3: 
		CamWriteCmosSensor(0xef,0x03);
		CamWriteCmosSensor(0x31,0x88);   //90
		CamWriteCmosSensor(0x32,0x84);   //88
		break;
  	  case CAM_EV_NEG_1_3: 
		CamWriteCmosSensor(0xef,0x03);
		CamWriteCmosSensor(0x31,0x84);   //88
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
  		ErrorCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		break;
	}	 
  }
  return ErrorCode;
}


/*************************************************************************
* FUNCTION
*    S5KA3DFXContrast
*
* DESCRIPTION
*    Contrast setting.
*
* PARAMETERS
*    In, Out
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM S5KA3DFXContrast(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    //kal_uint8 Data;;
    
    switch (In->FeatureSetValue)
    {
    case CAM_CONTRAST_HIGH:   
		CamWriteCmosSensor(0xEF,0x03);
		CamWriteCmosSensor(0x33, 0xa0);	// Contrast High
		break;
    case CAM_CONTRAST_MEDIUM: 
		CamWriteCmosSensor(0xEF, 0x03);
		CamWriteCmosSensor(0x33, 0x80);	// Contrast Medium
		break;
    case CAM_CONTRAST_LOW:    
		CamWriteCmosSensor(0xEF, 0x03);
		CamWriteCmosSensor(0x33, 0x50);	// Contrast Low
		break;
    default:
      return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    S5KA3DFXWB
*
* DESCRIPTION
*    S5KA3DFX WB setting.
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
static MM_ERROR_CODE_ENUM S5KA3DFXWB(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
	MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;

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
	  
	  switch (In->FeatureSetValue)
	  {
		case CAM_WB_AUTO:
			CamWriteCmosSensor(0xef,0x03);
			
			if (S5KA3DFX_Sensor_Status.S5KA3DFX_curr_banding == CAM_BANDING_50HZ)
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
			
			if (S5KA3DFX_Sensor_Status.S5KA3DFX_curr_banding == CAM_BANDING_50HZ)
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

			if (S5KA3DFX_Sensor_Status.S5KA3DFX_curr_banding == CAM_BANDING_50HZ)
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

			if (S5KA3DFX_Sensor_Status.S5KA3DFX_curr_banding == CAM_BANDING_50HZ)
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

			if (S5KA3DFX_Sensor_Status.S5KA3DFX_curr_banding == CAM_BANDING_50HZ)
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

			if (S5KA3DFX_Sensor_Status.S5KA3DFX_curr_banding == CAM_BANDING_50HZ)
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
		default:
			ErrorCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
			break;
	}
		   	
					  

  }
  return ErrorCode;
}


/*************************************************************************
* FUNCTION
*    S5KA3DFXEffect
*
* DESCRIPTION
*    S5KA3DFX Effect setting.
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
static MM_ERROR_CODE_ENUM S5KA3DFXEffect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
	MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;

  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    P_CAL_FEATURE_TYPE_ENUM_STRUCT EffectPara = &Out->FeatureInfo.FeatureEnum;
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION | CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    EffectPara->IsSupport = KAL_TRUE;
	EffectPara->ItemCount = 7;
    EffectPara->SupportItem[0] = CAM_EFFECT_ENC_NORMAL;
    EffectPara->SupportItem[1] = CAM_EFFECT_ENC_GRAYSCALE;
    EffectPara->SupportItem[2] = CAM_EFFECT_ENC_SEPIA;
    EffectPara->SupportItem[3] = CAM_EFFECT_ENC_SEPIAGREEN;
    EffectPara->SupportItem[4] = CAM_EFFECT_ENC_SEPIABLUE;
    EffectPara->SupportItem[5] = CAM_EFFECT_ENC_COLORINV;
    EffectPara->SupportItem[6] = CAM_EFFECT_ENC_COLORINV;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
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
			//CamWriteCmosSensor(0xd5, 0x2c);
			CamWriteCmosSensor(0xd5, 0x70);
			CamWriteCmosSensor(0xd6, 0x41);
			
			break;
		case CAM_EFFECT_ENC_SEPIABLUE:
			CamWriteCmosSensor(0xef, 0x00); //Blue_Effect_table_start:		
			CamWriteCmosSensor(0xd3, 0x00);
			CamWriteCmosSensor(0xd4, 0x03);
			//CamWriteCmosSensor(0xd5, 0xdc);
			//CamWriteCmosSensor(0xd6, 0x00);
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

		

		case CAM_EFFECT_ENC_GRAYINV:
		case CAM_EFFECT_ENC_COPPERCARVING:
		case CAM_EFFECT_ENC_BLUECARVING:
		case CAM_EFFECT_ENC_CONTRAST:
		case CAM_EFFECT_ENC_EMBOSSMENT:
		case CAM_EFFECT_ENC_SKETCH:
		case CAM_EFFECT_ENC_BLACKBOARD: 			
		case CAM_EFFECT_ENC_WHITEBOARD:
		case CAM_EFFECT_ENC_JEAN:
		case CAM_EFFECT_ENC_OIL:	
		default:
			ErrorCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
			break;
	}
  }   
  return ErrorCode;
}

MM_ERROR_CODE_ENUM S5KA3DFXStillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
	MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;
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
			break;
		default:
			ErrorCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
			break;
	}

	return MM_ERROR_NONE;
}   /* S5KA3DFXStillCaptureSize() */


/*************************************************************************
* FUNCTION
*    S5KA3DFXBanding
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
MM_ERROR_CODE_ENUM S5KA3DFXBanding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
	MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;
	if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
	{
		P_CAL_FEATURE_TYPE_ENUM_STRUCT Banding = (P_CAL_FEATURE_TYPE_ENUM_STRUCT)&(Out->FeatureInfo.FeatureEnum);
		Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
		Out->FeatureOperationSupport =  CAL_FEATURE_SET_OPERATION|
		                       CAL_FEATURE_GET_OPERATION|
		                       CAL_FEATURE_QUERY_OPERATION;
		Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
		Banding->IsSupport = KAL_TRUE;
		Banding->ItemCount = 2;
		Banding->SupportItem[0] = CAM_BANDING_50HZ;
		Banding->SupportItem[1] = CAM_BANDING_60HZ;
	}
	else if(CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
	{
		switch (In->FeatureSetValue)
		{
			case CAM_BANDING_50HZ:
				
	            break;
			case CAM_BANDING_60HZ:
				
	            break;
			default:
				ErrorCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
	            break;
				//return KAL_FALSE;		
		}	
	}
  return ErrorCode;
}

/*************************************************************************
* FUNCTION
*    S5KA3DFXGetSensorInfo
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
static void S5KA3DFXGetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT info)
{
	info->SensorId = S5KA3DFX_SENSOR_ID;
	info->SensorIf = IMAGE_SENSOR_IF_PARALLEL;
	info->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
	info->PreviewHMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
	info->PreviewVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
	info->PreviewHVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;  
	info->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
	info->PixelClkInv = KAL_FALSE;
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
	
	info->PreviewWidth = S5KA3DFX_IMAGE_SENSOR_VGA_WIDTH;
	info->PreviewHeight = S5KA3DFX_IMAGE_SENSOR_VGA_HEIGHT;
	info->FullWidth = S5KA3DFX_IMAGE_SENSOR_VGA_WIDTH;
	info->FullHeight = S5KA3DFX_IMAGE_SENSOR_VGA_HEIGHT;
	info->SensorAfSupport = KAL_FALSE;
	info->SensorFlashSupport = KAL_FALSE;
}

static MM_ERROR_CODE_ENUM S5KA3DFXSensorClose(void);


/*************************************************************************
* FUNCTION
*	S5KA3DFX_ae_awb_enable
*
* DESCRIPTION
*	Used to enable/disable the ae/awb, should move all of the enable/disable ae/awb operation 
*	into this function.
*
* PARAMETERS
*	enalbe : 0-disable ae/awb, 1-enable ae/awb
*
* RETURNS
*	kal_uint32
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 S5KA3DFXSetParaPano3aCtrl(kal_bool enable)
{	
	/* If it is controled by the media cal, then sensor driver shouldn't modify it.*/
#if 0
/* under construction !*/
/* under construction !*/
#endif
	if (enable)	
	{
		// Enable the AE/AWB.
	}
	else
	{
		// Disable the AE/AWB
	}

	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*    S5KA3DFXPowerOn
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
static kal_uint16 S5KA3DFXPowerOn(void)
{
	kal_uint16 S5KA3DFX_sensor_id = 0;

	/* PowerOn the sensor */
	CisModulePowerOn(S5KA3DFX_Sensor_Status.SensorIdx, KAL_TRUE);
	
    CameraSccbOpen(CAMERA_SCCB_SENSOR,S5KA3DFX_WRITE_ID, CAMERA_SCCB_8BIT, CAMERA_SCCB_8BIT, 300);

	/* set sensors chip enable pin to low to activate SIV100B */
	CamPdnPinCtrl(S5KA3DFX_Sensor_Status.SensorIdx, 1);

	/* Reset the sensor */
	CamRstPinCtrl(S5KA3DFX_Sensor_Status.SensorIdx, 1);
	kal_sleep_task(2);  /* delay for power stable */


	CamWriteCmosSensor(0xEf,0x01);
	S5KA3DFX_sensor_id = CamReadCmosSensor(0xc5);

	#ifdef S5KA3DFX_OUTPUT_DEBUG_INFO
		kal_wap_trace(MOD_ENG,TRACE_INFO, "S5KA3DFX Sensor ID=%x", S5KA3DFX_sensor_id);
	#endif
	/* Read Sensor ID  */
	return S5KA3DFX_sensor_id;
}

/*************************************************************************
* FUNCTION
*    S5KA3DFXDetectSensorId
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
static kal_uint32 S5KA3DFXDetectSensorId(void)
{
  MM_ERROR_CODE_ENUM S5KA3DFXSensorClose(void);
  kal_uint16 sensorId; //, AnotherSensorIdx;
  //kal_int8 i, j;
  
  if (IMAGE_SENSOR_MAIN == S5KA3DFX_Sensor_Status.SensorIdx)
  {
    //AnotherSensorIdx = IMAGE_SENSOR_SUB;
  }
  else
  {
    //AnotherSensorIdx = IMAGE_SENSOR_MAIN;
  }
  //for (i = 1; i >= 0; i--)
  {
    //CamRstPinCtrl(AnotherSensorIdx, i);
    //for (j = 1; j >= 0; j--)
    {
      //CamPdnPinCtrl(AnotherSensorIdx, j);
      sensorId = S5KA3DFXPowerOn();
      S5KA3DFXSensorClose();
#ifdef S5KA3DFX_DEBUG
      kal_wap_trace(MOD_ENG,TRACE_INFO,"S5KA3DFXDetectSensorId:%x",sensorId);
#endif
      if (S5KA3DFX_SENSOR_ID == sensorId)
      {
        return S5KA3DFX_SENSOR_ID;
      }
    }
  }
  return MM_ERROR_SENSOR_READ_ID_FAIL;
}

/*************************************************************************
* FUNCTION
*    S5KA3DFXDscSupportInfo
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
/*static void S5KA3DFXDscSupportInfo(P_IMAGE_SENSOR_GET_DSC_SUPPORT_INFO_STRUCT info)
{
#if defined(DRV_ISP_6238_SERIES)
  //kal_mem_cpy(info, &S5KA3DFX_dsc_support_info, sizeof(camcorder_info_struct));
#endif
}
*/
/*************************************************************************
* FUNCTION
*    S5KA3DFXInitOperationPara
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
static void S5KA3DFXInitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT para)
{
  para->CaptureDelayFrame = 2; /* wait stable frame when sensor change mode (pre to cap) */
  para->PreviewDelayFrame = 8; /* wait stable frame when sensor change mode (cap to pre) */
  para->PreviewDisplayWaitFrame = 6; /* wait stable frame when sensor change mode (cap to pre) */
}

/*************************************************************************
* FUNCTION
*    S5KA3DFXPreview
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
static void S5KA3DFXPreview(CAL_SCENARIO_ENUM id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT in, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT out)
{
//    kal_uint8 banding;

	#ifdef S5KA3DFX_OUTPUT_DEBUG_INFO
		kal_wap_trace(MOD_ENG,TRACE_INFO, "S5KA3DFX Preview");
	#endif

	S5KA3DFX_Sensor_Status.S5KA3DFX_curr_banding = in->BandingFreq;
	S5KA3DFX_Sensor_Status.night_mode            = in->NightMode;
	
	CamWriteCmosSensor(0xef,0x03);

	if (S5KA3DFX_Sensor_Status.S5KA3DFX_curr_banding == CAM_BANDING_50HZ)
	{
		CamWriteCmosSensor(0x00,0x83);	 //enable AE & AWB	
	}
	else
	{
		CamWriteCmosSensor(0x00,0x43);	 //enable AE & AWB	
	}
	switch (id)
	{
		case CAL_SCENARIO_VIDEO:
			S5KA3DFX_Sensor_Status.video_mode = KAL_TRUE;
			S5KA3DFX_Sensor_Status.video_frame_rate = in->MaxVideoFrameRate;
			break;
			
		case CAL_SCENARIO_CAMERA_PREVIEW:
		case CAL_SCENARIO_WEBCAM_PREVIEW:
		case CAL_SCENARIO_WEBCAM_CAPTURE:
			S5KA3DFX_Sensor_Status.video_mode = KAL_FALSE;
			break;
			
		default:
			ASSERT(0);
			break;
	}
  
	S5KA3DFX_SetHVMirror(in->ImageMirror);

	S5KA3DFX_Sensor_Status.S5KA3DFX_PV_dummy_pixels = 0;
	S5KA3DFX_Sensor_Status.S5KA3DFX_PV_dummy_lines = 0;		//For max preview frame rate 30fps.
	
	S5KA3DFX_set_dummy(S5KA3DFX_Sensor_Status.S5KA3DFX_PV_dummy_pixels, S5KA3DFX_Sensor_Status.S5KA3DFX_PV_dummy_lines);
	S5KA3DFX_NightMode(S5KA3DFX_Sensor_Status.night_mode);
	out->GrabStartX = 1;
	out->GrabStartY = 2;
	out->ExposureWindowWidth  = S5KA3DFX_IMAGE_SENSOR_PV_WIDTH ; 
	out->ExposureWindowHeight = S5KA3DFX_IMAGE_SENSOR_PV_HEIGHT;
}

/*************************************************************************
* FUNCTION
*    S5KA3DFXCapture
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
static void S5KA3DFXCapture(CAL_SCENARIO_ENUM id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT in, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT out)
{
/*	kal_uint32 S5KA3DFX_cintr1 = 254;
	kal_uint32 S5KA3DFX_cintr2 = 254;
	kal_uint32 S5KA3DFX_cintc1 = 0;
	kal_uint32 S5KA3DFX_cintc2 = 0;
	kal_uint16 PV_line_len = 0;
	kal_uint16 CAP_line_len = 0;
	kal_uint8 i = 0;
	#ifdef S5KA3DFX_CAP_GAIN_2_ShUTTER
		kal_uint16 D_Gain_R = 0, D_Gain_G = 0, D_Gain_B = 0;
		//float sensor_gain = 0;
		//kal_uint16 gain_reg = 0;
		//kal_uint16 gain_idx = 0;
	#endif

	#ifdef S5KA3DFX_OUTPUT_DEBUG_INFO
		kal_wap_trace(MOD_ENG,TRACE_INFO, "S5KA3DFX Capture");
	#endif
	//If not web camera mode, it should disable AE & AWB.
	CamWriteCmosSensor(0xef,0x03);

	if (S5KA3DFX_Sensor_Status.S5KA3DFX_curr_banding == CAM_BANDING_50HZ)
	{
		CamWriteCmosSensor(0x00,0x80);	 //disable AE & AWB 
	}
	else
	{
		CamWriteCmosSensor(0x00,0x40);	 //disable AE & AWB 
	}
		
	kal_sleep_task(3);				//Wait for disable AE & AWB take effect.
	S5KA3DFX_cintr1 = S5KA3DFX_read_shutter();	 //read preview shutter
	S5KA3DFX_cintc1 = S5KA3DFX_read_cintc();
	#ifdef S5KA3DFX_CAP_GAIN_2_ShUTTER
		CamWriteCmosSensor(0xef, 0x00);
		D_Gain_R = CamReadCmosSensor(0x45);	
		D_Gain_G = D_Gain_B = D_Gain_R;	//The digital red, green and blue gain is same.

	#ifdef S5KA3DFX_OUTPUT_DEBUG_INFO
		kal_wap_trace(MOD_ENG,TRACE_INFO, "CAP_Cal: D_Gain_R=%x, D_Gain_G=%x, D_Gain_B=%x", D_Gain_R, D_Gain_G, D_Gain_B);
	#endif
	#endif

	S5KA3DFX_Sensor_Status.S5KA3DFX_CAP_dummy_pixels = 0;
	S5KA3DFX_Sensor_Status.S5KA3DFX_CAP_dummy_lines = 0;
	PV_line_len = S5KA3DFX_PV_PERIOD_PIXEL_NUMS+ S5KA3DFX_Sensor_Status.S5KA3DFX_PV_dummy_pixels;
	CAP_line_len = S5KA3DFX_CAP_PERIOD_PIXEL_NUMS+ S5KA3DFX_Sensor_Status.S5KA3DFX_CAP_dummy_pixels;

	S5KA3DFX_cintr2=(S5KA3DFX_cintr1 * PV_line_len + S5KA3DFX_cintc1) / CAP_line_len;
	S5KA3DFX_cintc2=(S5KA3DFX_cintr1 * PV_line_len + S5KA3DFX_cintc1 - S5KA3DFX_cintr2 * CAP_line_len);

	S5KA3DFX_set_dummy(S5KA3DFX_Sensor_Status.S5KA3DFX_CAP_dummy_pixels, S5KA3DFX_Sensor_Status.S5KA3DFX_CAP_dummy_lines);

#ifdef S5KA3DFX_CAP_GAIN_2_ShUTTER
	//Gain = 128/(128 -gain_reg[6:0])

	CamWriteCmosSensor(0xef, 0x03);
	//gain_idx = CamReadCmosSensor(0x7A);	//Current shutter index, use this index as digital gain table index.

	if (D_Gain_R >= 0x5a)
	{
		D_Gain_R = 0x40;  //D_Gain_R == 0x40;
		D_Gain_G = D_Gain_B = D_Gain_R;
		S5KA3DFX_cintr2 = (kal_uint32)((float)S5KA3DFX_cintr2 * (float)1.4);
		S5KA3DFX_cintc2 = (kal_uint32)((float)S5KA3DFX_cintc2 * (float)1.4);
	}

	CamWriteCmosSensor(0xef, 0x00);
	CamWriteCmosSensor(0x45, D_Gain_R);
	CamWriteCmosSensor(0x46, D_Gain_G);
	CamWriteCmosSensor(0x47, D_Gain_B);
#endif

	for(i=0;i<100;i++)
	{
		S5KA3DFX_write_shutter(S5KA3DFX_cintr2);  //setting capture shutter  
		S5KA3DFX_write_cintc(S5KA3DFX_cintc2);
		if(S5KA3DFX_cintr2 == S5KA3DFX_read_shutter()
			&& S5KA3DFX_cintc2 == S5KA3DFX_read_cintc())
		 {
			break;
		 }
		kal_sleep_task(1);
	}  
*/
	out->GrabStartX = 1;
	out->GrabStartY = 2;
	out->ExposureWindowWidth = S5KA3DFX_IMAGE_SENSOR_FULL_WIDTH; 
	out->ExposureWindowHeight = S5KA3DFX_IMAGE_SENSOR_FULL_HEIGHT;
}

/*************************************************************************
* FUNCTION
*    S5KA3DFXSensorOpen
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
static MM_ERROR_CODE_ENUM S5KA3DFXSensorOpen(void)
{
	if (S5KA3DFX_SENSOR_ID != S5KA3DFXPowerOn()) return MM_ERROR_SENSOR_READ_ID_FAIL;

    S5KA3DFX_init_cmos_sensor();
	S5KA3DFX_Sensor_Status.S5KA3DFX_curr_banding = CAM_BANDING_50HZ;
	S5KA3DFX_Sensor_Status.video_mode = KAL_FALSE;
	S5KA3DFX_Sensor_Status.night_mode = KAL_FALSE;
	return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    S5KA3DFXSensorFeatureCtrl
*
* DESCRIPTION
*    This function set sensor feature mode
*
* PARAMETERS
*    FeatureId: scenario FeatureId
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM S5KA3DFXSensorFeatureCtrl(kal_uint32 FeatureId, void *In,
													void *Out, kal_uint32 OutLen, 
													kal_uint32 *RealOutLen)
{
  MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
  //kal_uint32 TmpFrameRate;
  P_CAL_FEATURE_CTRL_STRUCT pCameraFeatureIn=(P_CAL_FEATURE_CTRL_STRUCT) In;
	P_CAL_FEATURE_CTRL_STRUCT pCameraFeatureOut=(P_CAL_FEATURE_CTRL_STRUCT) Out;
	// for camera HAL UT only
	P_CAL_FEATURE_TYPE_ENUM_STRUCT pCamFeatureEnum=(P_CAL_FEATURE_TYPE_ENUM_STRUCT) &(pCameraFeatureOut->FeatureInfo.FeatureEnum);
	//P_CAL_CAMERA_DIGITAL_ZOOM_OUT_STRUCT pCameraDzOut=pCameraFeatureOut->FeatureInfo.FeatureStructured.pCamDzOutPara;


	if (FeatureId >= CAL_FEATURE_WEBCAM_BEGIN && FeatureId<= CAL_FEATURE_WEBCAM_END)
	{
	  return S5KA3DFXWebcamFeatureCtrl(FeatureId, In, Out, OutLen, RealOutLen);
	}

	if(Out!=NULL && CAL_FEATURE_QUERY_OPERATION==pCameraFeatureIn->FeatureCtrlCode)
	{
	  pCamFeatureEnum->IsSupport = KAL_FALSE;
	}


	switch (FeatureId)
	{
	 /* CAL Query and set series */
	case CAL_FEATURE_CAMERA_BRIGHTNESS:
	case CAL_FEATURE_CAMERA_EV_VALUE:
		ErrCode = S5KA3DFXEV(In, Out);
		break;
		
	case CAL_FEATURE_CAMERA_CONTRAST:
		ErrCode = S5KA3DFXContrast(In,Out);
		break;
	case CAL_FEATURE_CAMERA_HUE:
	case CAL_FEATURE_CAMERA_SATURATION:
	case CAL_FEATURE_CAMERA_SHARPNESS:
	case CAL_FEATURE_CAMERA_GAMMA:
		ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		break;

	case CAL_FEATURE_CAMERA_WB:
		ErrCode = S5KA3DFXWB(In, Out);
		break;
		
	case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
		ErrCode = S5KA3DFXEffect(In, Out);
		break;

	case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
		ErrCode = S5KA3DFXStillCaptureSize(In, Out);
		break;
		
	case CAL_FEATURE_CAMERA_BANDING_FREQ: /* move to preview */
		ErrCode = S5KA3DFXBanding(In, Out);
		break;
	case CAL_FEATURE_CAMERA_SCENE_MODE:
		ErrCode = S5KA3DFXSceneMode(KAL_TRUE, In, Out);
    break;
	case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
		ErrCode = S5KA3DFXSceneMode(KAL_FALSE, In, Out);
    break;
	case CAL_FEATURE_CAMERA_FLASH_MODE:
		ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		break;

	/* Get Info series */
	case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
		S5KA3DFXGetSensorInfo((P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT)Out);
		break;
	case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
		((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = S5KA3DFXDetectSensorId();
		break;
	case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
		((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = S5KA3DFX_Sensor_Status.video_frame_rate ;
		break;
	case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
		S5KA3DFXInitOperationPara((P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT)Out);
		break;
	case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
    	CamGetHWInfo(S5KA3DFX_Sensor_Status.SensorIdx, Out);
    break;

/* Set Para series */
    case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
		CamPdnPinCtrl(S5KA3DFX_Sensor_Status.SensorIdx,0);
		CamRstPinCtrl(S5KA3DFX_Sensor_Status.SensorIdx,0);
		break;
	case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
		S5KA3DFX_Sensor_Status.nvram_data = &(((nvram_camera_para_struct *)In)->SENSOR);
		break;	   
	case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
		S5KA3DFX_Sensor_Status.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
		break;
	case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
		break; 	
	case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
		ErrCode = S5KA3DFXSetParaPano3aCtrl(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue);
		break;
	case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
		ErrCode = S5KA3DFXSetParaPano3aCtrl(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue);
		break;
	default:
		ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		break;

	}
	
	return ErrCode;
}

/*************************************************************************
* FUNCTION
*    S5KA3DFXSensorCtrl
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
static MM_ERROR_CODE_ENUM S5KA3DFXSensorCtrl(CAL_SCENARIO_ENUM id, void *in, void *out, kal_uint16 out_len)
{
	MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;

	#ifdef S5KA3DFX_OUTPUT_DEBUG_INFO
		kal_wap_trace(MOD_ENG,TRACE_INFO, "S5KA3DFXSensorCtrl id =%d ",id);
	#endif
  switch (id)
  {
  case CAL_SCENARIO_CAMERA_PREVIEW:
  case CAL_SCENARIO_VIDEO:
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE: 
  	S5KA3DFXPreview(id, in, out); 
	break;
  case CAL_SCENARIO_CAMERA_STILL_CAPTURE: 
  	S5KA3DFXCapture(id, in, out);
	break;
  default: 
	  ErrorCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
  	break;
  }
  return ErrorCode;
}

/*************************************************************************
* FUNCTION
*    S5KA3DFXSensorClose
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
static MM_ERROR_CODE_ENUM S5KA3DFXSensorClose(void)
{
#ifdef S5KA3DFX_OUTPUT_DEBUG_INFO
		kal_wap_trace(MOD_ENG,TRACE_INFO, "XXX_Power off");
#endif

  CisModulePowerOn(S5KA3DFX_Sensor_Status.SensorIdx, KAL_FALSE);
  CameraSccbClose(CAMERA_SCCB_SENSOR);
    
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    S5KA3DFXSensorFunc
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
MM_ERROR_CODE_ENUM S5KA3DFXSensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncS5KA3DFX=
  {
    S5KA3DFXSensorOpen,
    S5KA3DFXSensorFeatureCtrl,
    S5KA3DFXSensorCtrl,
    S5KA3DFXSensorClose,
  };
  
  *pfSensorFunc = &ImageSensorFuncS5KA3DFX;
}

