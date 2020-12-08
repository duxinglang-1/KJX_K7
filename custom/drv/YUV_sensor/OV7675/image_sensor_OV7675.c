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
 *   image_sensor_OV7675.c
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
 *
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


static kal_bool OV7675_VIDEO_MPEG4_QVGA=KAL_FALSE;//Soso Add for QVGA 10fps
static kal_bool OV7675_s_bMPEG4_encode_mode=KAL_FALSE, OV7675_s_bMJPEG_mode = KAL_FALSE; // to distinguish between MPEG4 and MJPEG
static kal_bool  OV7675_s_bNight_mode =KAL_FALSE; // to distinguish night mode or auto mode, default: auto mode setting
static CAL_CAMERA_BANDING_FREQ_ENUM  OV7675_s_bBanding_value = CAM_BANDING_50HZ; // to distinguish between 50HZ and 60HZ.
// Pclk, dummy, exposue related variables.
static kal_uint16 OV7675_dummy_pixels=0, OV7675_dummy_lines=0;
/* Image Sensor ID */
static kal_uint16 OV7675_sensor_id=0;

//HAL
IMAGE_SENSOR_INDEX_ENUM SensorIdxOV7675;

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
static const unsigned char CATSTestPattern[] = { 0 };
#endif

void OV7675_set_banding_for_50Hz(void);
void OV7675_set_banding_for_60Hz(void);

void OV7675_set_dummy(kal_uint16 pixels, kal_uint16 lines)
{
	CamWriteCmosSensor(0x2A,((pixels&0xF00)>>4));
	CamWriteCmosSensor(0x2B,(pixels&0xFF));
	CamWriteCmosSensor(0x92,(lines&0xFF));
	CamWriteCmosSensor(0x93,((lines&0xFF00)>>8));
}	/* set_OV7675_dummy */

void OV7675_init_setting(void)
{
	CamWriteCmosSensor(0x11,0x80);
	CamWriteCmosSensor(0x3a,0x0C);
	CamWriteCmosSensor(0x3D,0xC0);
	CamWriteCmosSensor(0x12,0x00);
	CamWriteCmosSensor(0x15,0x40);
	CamWriteCmosSensor(0xc1,0x7f);

	CamWriteCmosSensor(0x17,0x13);
	CamWriteCmosSensor(0x18,0x01);
	CamWriteCmosSensor(0x32,0xbF);
	CamWriteCmosSensor(0x19,0x03);
	CamWriteCmosSensor(0x1a,0x7b);
	CamWriteCmosSensor(0x03,0x0a);

	CamWriteCmosSensor(0x0c,0x00);
	CamWriteCmosSensor(0x3e,0x00);
	CamWriteCmosSensor(0x70,0x3a);
	CamWriteCmosSensor(0x71,0x35);
	CamWriteCmosSensor(0x72,0x11);
	CamWriteCmosSensor(0x73,0xf0);
	CamWriteCmosSensor(0xa2,0x02);

	CamWriteCmosSensor(0x7a,0x24);
	CamWriteCmosSensor(0x7b,0x04);
	CamWriteCmosSensor(0x7c,0x07);
	CamWriteCmosSensor(0x7d,0x10);
	CamWriteCmosSensor(0x7e,0x28);
	CamWriteCmosSensor(0x7f,0x36);
	CamWriteCmosSensor(0x80,0x44);
	CamWriteCmosSensor(0x81,0x52);
	CamWriteCmosSensor(0x82,0x60);
	CamWriteCmosSensor(0x83,0x6c);
	CamWriteCmosSensor(0x84,0x78);
	CamWriteCmosSensor(0x85,0x8c);
	CamWriteCmosSensor(0x86,0x9e);
	CamWriteCmosSensor(0x87,0xbb);
	CamWriteCmosSensor(0x88,0xd2);
	CamWriteCmosSensor(0x89,0xe5);

	CamWriteCmosSensor(0x13,0xe0);
	CamWriteCmosSensor(0x00,0x00);
	CamWriteCmosSensor(0x10,0x00);
	CamWriteCmosSensor(0x0d,0x40); //
	CamWriteCmosSensor(0x42,0x00);//
	CamWriteCmosSensor(0xb7,0x56); //
	CamWriteCmosSensor(0x14,0x38); // 16x gain will changed in night mode function
	CamWriteCmosSensor(0xa5,0x02);  // 50 banding step will change in banding function
	CamWriteCmosSensor(0xab,0x03);  // 60HZ banding step will change in banding function
	CamWriteCmosSensor(0x24,0x54); 
	CamWriteCmosSensor(0x25,0x4c); 
	CamWriteCmosSensor(0x26,0x82);   
	CamWriteCmosSensor(0x9f,0x78);
	CamWriteCmosSensor(0xa0,0x68);
	CamWriteCmosSensor(0xa1,0x03);
	CamWriteCmosSensor(0xa6,0xD8);
	CamWriteCmosSensor(0xa7,0xD8);
	CamWriteCmosSensor(0xa8,0xf0);
	CamWriteCmosSensor(0xa9,0x90);
	CamWriteCmosSensor(0xaa,0x14);
	CamWriteCmosSensor(0x13,0xe5);

	CamWriteCmosSensor(0x0e,0x61);
	CamWriteCmosSensor(0x0f,0x4b);
	CamWriteCmosSensor(0x16,0x02);
	CamWriteCmosSensor(0x1e,0x07);
	CamWriteCmosSensor(0x21,0x02);
	CamWriteCmosSensor(0x22,0x91);
	CamWriteCmosSensor(0x29,0x07);
	CamWriteCmosSensor(0x33,0x0b);
	CamWriteCmosSensor(0x35,0x0b);
	CamWriteCmosSensor(0x37,0x1d);
	CamWriteCmosSensor(0x38,0x71);
	CamWriteCmosSensor(0x39,0x2a);
	CamWriteCmosSensor(0x3c,0x78);
	CamWriteCmosSensor(0x4d,0x40);
	CamWriteCmosSensor(0x4e,0x20);
	CamWriteCmosSensor(0x69,0x00);

	CamWriteCmosSensor(0x6b,0x0a);
	CamWriteCmosSensor(0x74,0x10);
	CamWriteCmosSensor(0x8d,0x4f);
	CamWriteCmosSensor(0x8e,0x00);
	CamWriteCmosSensor(0x8f,0x00);
	CamWriteCmosSensor(0x90,0x00);
	CamWriteCmosSensor(0x91,0x00);
	CamWriteCmosSensor(0x96,0x00);
	CamWriteCmosSensor(0x9a,0x80);
	CamWriteCmosSensor(0xb0,0x84);
	CamWriteCmosSensor(0xb1,0x0c);
	CamWriteCmosSensor(0xb2,0x0e);
	CamWriteCmosSensor(0xb3,0x82);
	CamWriteCmosSensor(0xb8,0x0a);

	CamWriteCmosSensor(0x43,0x0a);
	CamWriteCmosSensor(0x44,0xf2);
	CamWriteCmosSensor(0x45,0x40);
	CamWriteCmosSensor(0x46,0x5a);
	CamWriteCmosSensor(0x47,0x33);
	CamWriteCmosSensor(0x48,0x42);
	CamWriteCmosSensor(0x59,0xab);
	CamWriteCmosSensor(0x5a,0xad);
	CamWriteCmosSensor(0x5b,0xba);
	CamWriteCmosSensor(0x5c,0x6d);
	CamWriteCmosSensor(0x5d,0x54);
	CamWriteCmosSensor(0x5e,0x0e);
	CamWriteCmosSensor(0x6c,0x0a);
	CamWriteCmosSensor(0x6d,0x65);
	CamWriteCmosSensor(0x6e,0x11);
	CamWriteCmosSensor(0x6f,0x97);

	CamWriteCmosSensor(0x6a,0x40);
	CamWriteCmosSensor(0x01,0x56);
	CamWriteCmosSensor(0x02,0x44);
	CamWriteCmosSensor(0x13,0xe7);	

	CamWriteCmosSensor(0x4f,0x73);
	CamWriteCmosSensor(0x50,0x73);
	CamWriteCmosSensor(0x51,0x00);
	CamWriteCmosSensor(0x52,0x1F);
	CamWriteCmosSensor(0x53,0x55);   
	CamWriteCmosSensor(0x54,0x73);   
	CamWriteCmosSensor(0x55,0x00);
	CamWriteCmosSensor(0x56,0x40);
	CamWriteCmosSensor(0x57,0x80);
	CamWriteCmosSensor(0x58,0x9e);

	CamWriteCmosSensor(0x3f,0x02);
	CamWriteCmosSensor(0x75,0x23);
	CamWriteCmosSensor(0x76,0xe1);
	CamWriteCmosSensor(0x4c,0x00);
	CamWriteCmosSensor(0x77,0x01);
	CamWriteCmosSensor(0x3D,0xC2);
	CamWriteCmosSensor(0x4b,0x09);
	CamWriteCmosSensor(0xc9,0x60);
	CamWriteCmosSensor(0x41,0x38);	
	CamWriteCmosSensor(0x56,0x40);

	CamWriteCmosSensor(0x34,0x11);
	CamWriteCmosSensor(0x3b,0xaa);   
	CamWriteCmosSensor(0xa4,0x89);//insert dummy from 4x
	CamWriteCmosSensor(0x96,0x00);
	CamWriteCmosSensor(0x97,0x30);
	CamWriteCmosSensor(0x98,0x20);
	CamWriteCmosSensor(0x99,0x30);
	CamWriteCmosSensor(0x9a,0x84);
	CamWriteCmosSensor(0x9b,0x29);
	CamWriteCmosSensor(0x9c,0x03);
	CamWriteCmosSensor(0x9d,0x99);
	CamWriteCmosSensor(0x9e,0x7f);
	CamWriteCmosSensor(0x78,0x04);

	CamWriteCmosSensor(0x79,0x01);
	CamWriteCmosSensor(0xc8,0xf0);
	CamWriteCmosSensor(0x79,0x0f);
	CamWriteCmosSensor(0xc8,0x00);
	CamWriteCmosSensor(0x79,0x10);
	CamWriteCmosSensor(0xc8,0x7e);
	CamWriteCmosSensor(0x79,0x0a);
	CamWriteCmosSensor(0xc8,0x80);
	CamWriteCmosSensor(0x79,0x0b);
	CamWriteCmosSensor(0xc8,0x01);
	CamWriteCmosSensor(0x79,0x0c);
	CamWriteCmosSensor(0xc8,0x0f);
	CamWriteCmosSensor(0x79,0x0d);
	CamWriteCmosSensor(0xc8,0x20);
	CamWriteCmosSensor(0x79,0x09);
	CamWriteCmosSensor(0xc8,0x80);
	CamWriteCmosSensor(0x79,0x02);
	CamWriteCmosSensor(0xc8,0xc0);
	CamWriteCmosSensor(0x79,0x03);
	CamWriteCmosSensor(0xc8,0x40);
	CamWriteCmosSensor(0x79,0x05);
	CamWriteCmosSensor(0xc8,0x30);
	CamWriteCmosSensor(0x79,0x26);	

	CamWriteCmosSensor(0x62,0x00);
	CamWriteCmosSensor(0x63,0x00);
	CamWriteCmosSensor(0x64,0x10);
	CamWriteCmosSensor(0x65,0x00);
	CamWriteCmosSensor(0x66,0x05);
	CamWriteCmosSensor(0x94,0x10);   
	CamWriteCmosSensor(0x95,0x13);  
	CamWriteCmosSensor(0xbb, 0xa1); //blc target	
	//gamma
	CamWriteCmosSensor(0x7a, 0x28); 
	CamWriteCmosSensor(0x7b, 0x04); 
	CamWriteCmosSensor(0x7c, 0x09); 
	CamWriteCmosSensor(0x7d, 0x16); 
	CamWriteCmosSensor(0x7e, 0x30); 
	CamWriteCmosSensor(0x7f, 0x3E); 
	CamWriteCmosSensor(0x80, 0x4B); 
	CamWriteCmosSensor(0x81, 0x59); 
	CamWriteCmosSensor(0x82, 0x67); 
	CamWriteCmosSensor(0x83, 0x72); 
	CamWriteCmosSensor(0x84, 0x7c); 
	CamWriteCmosSensor(0x85, 0x8e); 
	CamWriteCmosSensor(0x86, 0x9e); 
	CamWriteCmosSensor(0x87, 0xB6); 
	CamWriteCmosSensor(0x88, 0xcc); 
	CamWriteCmosSensor(0x89, 0xE2); 

	//cmx 115 for mtk
	CamWriteCmosSensor(0x4f, 0x7d);
	CamWriteCmosSensor(0x50, 0x81);
	CamWriteCmosSensor(0x51, 0x04);
	CamWriteCmosSensor(0x52, 0x23);
	CamWriteCmosSensor(0x53, 0x5a);
	CamWriteCmosSensor(0x54, 0x7d);
	CamWriteCmosSensor(0x58, 0x1a);

	//awb from HQ
	CamWriteCmosSensor(0x43, 0x0a);
	CamWriteCmosSensor(0x44, 0xf2);
	CamWriteCmosSensor(0x45, 0x31);
	CamWriteCmosSensor(0x46, 0x57);
	CamWriteCmosSensor(0x47, 0x37);//0x38
	CamWriteCmosSensor(0x48, 0x4c);//0x54
	CamWriteCmosSensor(0x59, 0x80);
	CamWriteCmosSensor(0x5a, 0xbb);
	CamWriteCmosSensor(0x5b, 0xbb);
	CamWriteCmosSensor(0x5c, 0x60);
	CamWriteCmosSensor(0x5d, 0x75);
	CamWriteCmosSensor(0x5e, 0x16);
	CamWriteCmosSensor(0x6a, 0x40);
	CamWriteCmosSensor(0x6c, 0x0a);
	CamWriteCmosSensor(0x6d, 0x65);
	CamWriteCmosSensor(0x6e, 0x11);

	//lenc from HQ
	CamWriteCmosSensor(0x62,0x18);//0x10
	CamWriteCmosSensor(0x63,0x10);//0x0b
	CamWriteCmosSensor(0x64,0x0f);
	CamWriteCmosSensor(0x65,0x00);
	CamWriteCmosSensor(0x66,0x05);
	CamWriteCmosSensor(0x94,0x0d);
	CamWriteCmosSensor(0x95,0x11); //0x10   

	//aec
	CamWriteCmosSensor(0x24, 0x5e);//0x68,0x5e(0x62)
	CamWriteCmosSensor(0x25, 0x54); //0x54(0x58)
	CamWriteCmosSensor(0x26, 0x93); //0x84

	//Edge + Denoise
	CamWriteCmosSensor(0x41, 0x38);

	CamWriteCmosSensor(0x75, 0x63);  //0x64
	CamWriteCmosSensor(0x76, 0xe0); 
	CamWriteCmosSensor(0x77, 0x07); 

	//UVAdjust
	CamWriteCmosSensor(0xc9, 0x30);  // to make more saturation 0x60
	CamWriteCmosSensor(0x61, 0x43);	

	CamWriteCmosSensor(0x4d,0xc0); // this will make add dummy line after active line, it is a little difference with OV7675_AE_LUTs
	CamWriteCmosSensor(0x13, 0xF7); // for mt6268 and mt6253, capture no need to change clock,so preview no need to enable ae
}


/*************************************************************************
* FUNCTION
*  OV7675SetMirrorFlip
*
* DESCRIPTION
*   This function config the HVmirror of image sensor.
*
*************************************************************************/
 static void OV7675SetMirrorFlip(IMAGE_SENSOR_MIRROR_ENUM ImageMirrorFlip)
 {
	 kal_uint32 HVMirror = 0;
	 HVMirror = CamReadCmosSensor(0x1e);
	 HVMirror &= (0xCF);
	 switch (ImageMirrorFlip)
	 {
	 case IMAGE_SENSOR_MIRROR_NORMAL:
		 HVMirror |= 0x00;
		 break;
	 case IMAGE_SENSOR_MIRROR_H:
		 HVMirror |= 0x20;
		 break;
	 case IMAGE_SENSOR_MIRROR_V:
		 HVMirror |= 0x10;
		 break;
	 case IMAGE_SENSOR_MIRROR_HV:
		 HVMirror |= 0x30;
		 break;
	 default:
		 ASSERT(0);
	 }

	 CamWriteCmosSensor(0x1e,HVMirror);
 }   /* OV7675SetMirrorFlip */

/*************************************************************************
* FUNCTION
*	OV7675_night_mode
*
* DESCRIPTION
*	This function night mode of OV7675.
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
void OV7675_night_mode(kal_bool enable)
{
    kal_uint8 night = CamReadCmosSensor(0x3B);
    if (enable == KAL_TRUE) 
		{	
		   OV7675_s_bNight_mode = KAL_TRUE;
		   if(OV7675_s_bMPEG4_encode_mode == KAL_TRUE)
		  {
		  #if ((defined(MT6235)||defined(MT6235B))&& (!defined( __SW_VIDEO_ADV_RESIZER_SUPPORT__ )))
                OV7675_dummy_pixels = 0;
			   OV7675_dummy_lines = 1530; //  7.5 fps, 6235 with no VIDEO_ADV_RESIZER
			   OV7675_set_dummy(OV7675_dummy_pixels,OV7675_dummy_lines);
		  
		  #else // 6253, 6268, 623_SW_ADV_Resizer 
			  if(OV7675_VIDEO_MPEG4_QVGA == KAL_TRUE){
				 OV7675_dummy_lines = 1020; //10fps, but only shows 5 fps in mt6253
			  }else{
				 OV7675_dummy_lines = 510; //15 fps, but only shows 7.5 fps in mt6253
			  }
		       OV7675_dummy_pixels = 0;
			   OV7675_set_dummy(OV7675_dummy_pixels,OV7675_dummy_lines);
		  #endif
			   CamWriteCmosSensor(0x3B,(night&0x1F)); // fixed frame rate
			   CamWriteCmosSensor(0x2d, 0); // if not set to zero, maybe AE osillation
			   CamWriteCmosSensor(0x2e, 0);
			   CamWriteCmosSensor(0xc9, 0x30);  
			   if(CAM_BANDING_50HZ == OV7675_s_bBanding_value)
			   	        OV7675_set_banding_for_50Hz();
			   else
			   	        OV7675_set_banding_for_60Hz();
			   
		   }
		   else if(OV7675_s_bMJPEG_mode == KAL_TRUE)
		    {
		     #if (defined(MT6235)||defined(MT6235B))
                OV7675_dummy_pixels = 0;
			    OV7675_dummy_lines = 2550; //  5 fps , 6235 with no VIDEO_ADV_RESIZER
			    OV7675_set_dummy(OV7675_dummy_pixels,OV7675_dummy_lines);
              
			 #else
		       OV7675_dummy_pixels = 0;
			   OV7675_dummy_lines = 1020; //10fps, but only shows 5 fps in mt6253, 15 fps in mt6268
			   OV7675_set_dummy(OV7675_dummy_pixels,OV7675_dummy_lines);
			 #endif
			   CamWriteCmosSensor(0x3B,(night&0x1F)); // fixed frame rate
			   CamWriteCmosSensor(0x2d, 0); // if not set to zero, maybe AE osillation
			   CamWriteCmosSensor(0x2e, 0);
			   CamWriteCmosSensor(0xc9, 0x30);  // to set to be 0x30 for low light noise
			   if(CAM_BANDING_50HZ == OV7675_s_bBanding_value)
			   	        OV7675_set_banding_for_50Hz();
			   else
			   	        OV7675_set_banding_for_60Hz();
		   }	
		 else 
		 {
#if (defined(MT6225))
                OV7675_dummy_pixels = 1568;
                          OV7675_dummy_lines = 0; // 10 fps, low light luminux
                          OV7675_set_dummy(OV7675_dummy_pixels,OV7675_dummy_lines);
#else
		       OV7675_dummy_pixels = 0;
			   OV7675_dummy_lines = 255; //20 fps, low light luminux
			   OV7675_set_dummy(OV7675_dummy_pixels,OV7675_dummy_lines);
#endif
			   CamWriteCmosSensor(0x3B,(night&0x1F)|0xE0);    
               CamWriteCmosSensor(0x14, 0x38);
			   CamWriteCmosSensor(0xc9, 0x10);	
          }
		}
		else 
		{
		    #ifdef __DBG_SENSOR_TRACE__
				kal_print_string_trace(MOD_ENG, TRACE_INFO, "[IN] OV7675_night_mode is false");
            #endif
			OV7675_s_bNight_mode = KAL_FALSE;
			if(OV7675_s_bMJPEG_mode == KAL_TRUE)
			{
			 #if (defined(MT6235)||defined(MT6235B))
               OV7675_dummy_pixels = 0;
			   OV7675_dummy_lines = 1020; //  10fps, 6235 with_no_sw_video_ADV_resizer
			   OV7675_set_dummy(OV7675_dummy_pixels,OV7675_dummy_lines);

			 #else
               OV7675_dummy_pixels = 0;
			   OV7675_dummy_lines = 255; //20  fps, but only shows 10 fps in 6253
			   OV7675_set_dummy(OV7675_dummy_pixels,OV7675_dummy_lines);
			 #endif
			   CamWriteCmosSensor(0x3B,(night&0x1F)); // fixed frame rate
			   CamWriteCmosSensor(0x2d, 0); // if not set to zero, maybe AE osillation
			   CamWriteCmosSensor(0x2e, 0);
			   CamWriteCmosSensor(0xc9, 0x30);  
			   if(CAM_BANDING_50HZ == OV7675_s_bBanding_value)
			   	        OV7675_set_banding_for_50Hz();
			   else
			   	        OV7675_set_banding_for_60Hz();
			}
			else if(OV7675_s_bMPEG4_encode_mode == KAL_TRUE)
		    {                
		    #if ((defined(MT6235)||defined(MT6235B))&& (!defined( __SW_VIDEO_ADV_RESIZER_SUPPORT__ )))
                 OV7675_dummy_pixels = 0;
			     OV7675_dummy_lines = 510; //  15 fps for 6235_no_video_ADV_Resizer
			    OV7675_set_dummy(OV7675_dummy_pixels,OV7675_dummy_lines);

			 #else
				if(OV7675_VIDEO_MPEG4_QVGA == KAL_TRUE){
					OV7675_dummy_lines = 255; //20fps, but only shows 10 fps in 6253
				}else{
				 	OV7675_dummy_lines = 0; //30 fps for mt6268, but only shows 15 fps in 6253
				}
			   OV7675_dummy_pixels = 0;
			   OV7675_set_dummy(OV7675_dummy_pixels,OV7675_dummy_lines);
			 #endif
			   CamWriteCmosSensor(0x3B,(night&0x1F)); // fixed frame rate
			   CamWriteCmosSensor(0x2d, 0); // if not set to zero, maybe AE osillation
			   CamWriteCmosSensor(0x2e, 0);
			   CamWriteCmosSensor(0xc9, 0x30); 
			   if(CAM_BANDING_50HZ == OV7675_s_bBanding_value)
			   	        OV7675_set_banding_for_50Hz();
			   else
			   	        OV7675_set_banding_for_60Hz();
		    }
			else 
			{
			#if (defined(MT6225))
                               OV7675_dummy_pixels = 392;
                               OV7675_dummy_lines = 0; //20 fps
                               OV7675_set_dummy(OV7675_dummy_pixels,OV7675_dummy_lines);
			#else
			   OV7675_dummy_pixels = 0;
			   OV7675_dummy_lines = 0; //30 fps
			   OV7675_set_dummy(OV7675_dummy_pixels,OV7675_dummy_lines);
			#endif
			   CamWriteCmosSensor(0x3B,(night&0x1F)|0xA0);     
               CamWriteCmosSensor(0x14,0x28);
			   CamWriteCmosSensor(0xc9, 0x60);  //this will make more saturation in D65 but will decrease saturation in lowlight so need change again in night mode
            }
	   }
}	/* OV7675_night_mode */

/*************************************************************************
* FUNCTION
*    OV7675SceneMode
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
static MM_ERROR_CODE_ENUM OV7675SceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
  	OV7675_night_mode(Enable);
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV7675EV
*
* DESCRIPTION
*    OV7675 EV setting.
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
static MM_ERROR_CODE_ENUM OV7675EV(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
#ifdef OV7675_DEBUG
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
            CamWriteCmosSensor(0x55, 0x38);
			break;				
		case CAM_EV_POS_3_3:
            CamWriteCmosSensor(0x55, 0x58);
			break;				
		case CAM_EV_POS_4_3:	
            CamWriteCmosSensor(0x55, 0x78);
			break;
		default:
			break;    
	}
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV7675WB
*
* DESCRIPTION
*    OV7675 WB setting.
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
static MM_ERROR_CODE_ENUM OV7675WB(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
	#ifdef OV7675_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"WB:%d",WBTemp);
#endif
	
	temp_reg=CamReadCmosSensor(0x13);
	
	switch (In->FeatureSetValue)
	{
		case CAM_WB_AUTO:

			{
			CamWriteCmosSensor(0x01,0x56);
			CamWriteCmosSensor(0x02,0x44);
			CamWriteCmosSensor(0x13,temp_reg|0x2);   // Enable AWB		
			}
			break;

		case CAM_WB_CLOUD:
			CamWriteCmosSensor(0x13,temp_reg&~0x2);  // Disable AWB				
			CamWriteCmosSensor(0x01, 0x58);
			CamWriteCmosSensor(0x02, 0x60);
            CamWriteCmosSensor(0x6A, 0x40);
			break;		

		case CAM_WB_DAYLIGHT:
			CamWriteCmosSensor(0x13,temp_reg&~0x2);  // Disable AWB				
			CamWriteCmosSensor(0x01, 0x56);
			CamWriteCmosSensor(0x02, 0x5C);
            CamWriteCmosSensor(0x6A, 0x42);
			break;		

		case CAM_WB_INCANDESCENCE:
			CamWriteCmosSensor(0x13,temp_reg&~0x2);  // Disable AWB				
			CamWriteCmosSensor(0x01, 0x9A);
			CamWriteCmosSensor(0x02, 0x40);
			CamWriteCmosSensor(0x6A, 0x48);
			break;		

		case CAM_WB_FLUORESCENT:
			CamWriteCmosSensor(0x13,temp_reg&~0x2);  // Disable AWB				
			CamWriteCmosSensor(0x01, 0x8B);
			CamWriteCmosSensor(0x02, 0x42);
			CamWriteCmosSensor(0x6A, 0x40);
			break;		

		case CAM_WB_TUNGSTEN:
			CamWriteCmosSensor(0x13,temp_reg&~0x2);  // Disable AWB				
			CamWriteCmosSensor(0x01, 0xB8);
			CamWriteCmosSensor(0x02, 0x40);
			CamWriteCmosSensor(0x6A, 0x4F);
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
*    OV7675Effect
*
* DESCRIPTION
*    OV7675 Effect setting.
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
static MM_ERROR_CODE_ENUM OV7675Effect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
#ifdef OV7675_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO,"Effect:%d",In->FeatureSetValue);
#endif
  switch (In->FeatureSetValue)
	{	
		case CAM_EFFECT_ENC_NORMAL:
			CamWriteCmosSensor(0x3A,0x0C);		
			CamWriteCmosSensor(0x67,0x80);		
			CamWriteCmosSensor(0x68,0x80);
			CamWriteCmosSensor(0x56,0x40);		
			break;		
		case CAM_EFFECT_ENC_GRAYSCALE:
			CamWriteCmosSensor(0x3A,0x1C);		
			CamWriteCmosSensor(0x67,0x80);		
			CamWriteCmosSensor(0x68,0x80);
			CamWriteCmosSensor(0x56,0x40);		
			break;		
		case CAM_EFFECT_ENC_SEPIA:
			CamWriteCmosSensor(0x3A,0x1C);		
			CamWriteCmosSensor(0x67,0x40);		
			CamWriteCmosSensor(0x68,0xA0);
			CamWriteCmosSensor(0x56,0x40);		
			break;		
			case CAM_EFFECT_ENC_SEPIAGREEN:
			CamWriteCmosSensor(0x3A,0x1C);		
			CamWriteCmosSensor(0x67,0x40);		
			CamWriteCmosSensor(0x68,0x40);
			CamWriteCmosSensor(0x56,0x40);		
			break;					
		case CAM_EFFECT_ENC_SEPIABLUE:
			CamWriteCmosSensor(0x3A,0x1C);		
			CamWriteCmosSensor(0x67,0xA0);		
			CamWriteCmosSensor(0x68,0x40);
			CamWriteCmosSensor(0x56,0x40);		
			break;								
		case CAM_EFFECT_ENC_COLORINV:
			CamWriteCmosSensor(0x3A,0x2C);		
			CamWriteCmosSensor(0x67,0x80);		
			CamWriteCmosSensor(0x68,0x80);
			CamWriteCmosSensor(0x56,0x40);		
			break;		
		default:
			break;
	}
  }   
  return MM_ERROR_NONE;
}


void OV7675_set_banding_for_50Hz(void)
{
    kal_uint8 banding;
	banding=CamReadCmosSensor(0x3b);
	CamWriteCmosSensor(0x3b,banding|0x08);		/* 50 Hz */ 	
	if(OV7675_s_bMJPEG_mode == KAL_TRUE) 
	{

	  CamWriteCmosSensor(0x9D,0x99); //PCLK:24M, Line_lenght:784
	  if(KAL_TRUE == OV7675_s_bNight_mode)
	   {
	    #if (defined(MT6235)||defined(MT6235B))
        CamWriteCmosSensor(0xA5, 0x13); //banding step, frame lenth: 3060
		#else
		 CamWriteCmosSensor(0xA5, 0x09); //banding step, frame lenth: 1530
		 #endif
		}
	   else
	   {
	   #if (defined(MT6235)||defined(MT6235B))
          CamWriteCmosSensor(0xA5, 0x09); //banding step, frame lengh:1530
	   #else
		 CamWriteCmosSensor(0xA5, 0x04); //banding step, frame lengh:765
		 #endif
	   }
	}
	else if (OV7675_s_bMPEG4_encode_mode == KAL_TRUE)
   {

	  CamWriteCmosSensor(0x9D,0x99); //PCLK:24M, Line_lenght:784
	  if(KAL_TRUE == OV7675_s_bNight_mode)
	   {
	   	   #if ((defined(MT6235)||defined(MT6235B))&& (!defined( __SW_VIDEO_ADV_RESIZER_SUPPORT__ )))
              CamWriteCmosSensor(0xA5, 0x0c); //banding step, frame lenth: 2040
	   #else
	   if(OV7675_VIDEO_MPEG4_QVGA == KAL_TRUE)
	   	{
            CamWriteCmosSensor(0xA5, 0x09); //banding step, frame lenth: 1530
	    }
	    else
		{
		     CamWriteCmosSensor(0xA5, 0x05); //banding step, frame lenth: 1020
		}
		 #endif
		}
	   else
	   {
	     #if ((defined(MT6235)||defined(MT6235B))&& (!defined( __SW_VIDEO_ADV_RESIZER_SUPPORT__ )))
              CamWriteCmosSensor(0xA5, 0x05); //banding step, frame lengh:1020
	   #else
	    if(OV7675_VIDEO_MPEG4_QVGA == KAL_TRUE)
	   	{
	   	  CamWriteCmosSensor(0xA5, 0x04);//banding step, frame lengh:765
	    }
		else
		{
		   CamWriteCmosSensor(0xA5, 0x02); //banding step, frame lengh:510
		}
		 #endif
	   }
	}
   else 
	{
          
		if(KAL_TRUE == OV7675_s_bNight_mode)
		{

                   CamWriteCmosSensor(0x9D,0x99); //PCLK:24M, Line_lenght:784
                       CamWriteCmosSensor(0xA5, 0x04); //banding step, frame lengh:765
		}
		else
		{
                   CamWriteCmosSensor(0x9D,0x99); //PCLK:24M, Line_lenght:784
			CamWriteCmosSensor(0xA5, 0x02); //banding step, frame lengh:510
		}
	}		
}


void OV7675_set_banding_for_60Hz(void)
{   
    kal_uint8 banding;
	banding=CamReadCmosSensor(0x3b);
	CamWriteCmosSensor(0x3b,banding&0xF7);	    /* 60 Hz */				
	if (OV7675_s_bMJPEG_mode == KAL_TRUE) 
	{

         CamWriteCmosSensor(0x9E,0x7f); //PCLK:24M, Line_lenght:784
		if(KAL_TRUE == OV7675_s_bNight_mode)
		{
		 #if (defined(MT6235)||defined(MT6235B))
          CamWriteCmosSensor(0xAb, 0x17); //banding step, frame lenth: 3060
		 #else
		  CamWriteCmosSensor(0xAb, 0x0b); //banding step, frame lenth: 1530
		  #endif
		}
		else
		{
				 #if (defined(MT6235)||defined(MT6235B))
            CamWriteCmosSensor(0xAb, 0x0b); //banding step, frame lengh:1530
		 #else
		  CamWriteCmosSensor(0xAb, 0x05); //banding step, frame lengh:765
		  #endif
		}
	}
	else if ((OV7675_s_bMPEG4_encode_mode == KAL_TRUE))
	{
         CamWriteCmosSensor(0x9E,0x7f); //PCLK:24M, Line_lenght:784
	  if(KAL_TRUE == OV7675_s_bNight_mode)
	   {
	   		 #if ((defined(MT6235)||defined(MT6235B))&& (!defined( __SW_VIDEO_ADV_RESIZER_SUPPORT__ )))
			 CamWriteCmosSensor(0xAb, 0x0f); //banding step, frame lenth: 2040
		 #else
		  if(OV7675_VIDEO_MPEG4_QVGA == KAL_TRUE)
	   	{
            CamWriteCmosSensor(0xAb, 0x0b); //banding step, frame lenth: 1530
		 }
		 else
		 {
	        CamWriteCmosSensor(0xAb, 0x07); //banding step, frame lenth: 1020
		 }
	     #endif
	  	}
	   else
	   {
	   		 #if ((defined(MT6235)||defined(MT6235B))&& (!defined( __SW_VIDEO_ADV_RESIZER_SUPPORT__ )))
			 CamWriteCmosSensor(0xAb, 0x07); //banding step, frame lengh:510
		 #else
		  if(OV7675_VIDEO_MPEG4_QVGA == KAL_TRUE)
	   	{
            CamWriteCmosSensor(0xAb, 0x05); //banding step, frame lenth: 765
		 }
		 else
		 {
		 CamWriteCmosSensor(0xAb, 0x03); //banding step, frame lengh:510
		 	}
		 #endif
	   }
	}
	else 
	{
            
		if(KAL_TRUE == OV7675_s_bNight_mode)
		{
               CamWriteCmosSensor(0x9E, 0x7f); //PCLK:24M, Line_lenght:784
		  CamWriteCmosSensor(0xAb, 0x05); //banding step, frame lengh:765
		}
		else
		{
                  CamWriteCmosSensor(0x9E, 0x7f); //PCLK:24M, Line_lenght:784
                  CamWriteCmosSensor(0xab, 0x03); //banding step, frame length: 510
		}
	}
}

/*************************************************************************
* FUNCTION
*    OV7675Banding
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
MM_ERROR_CODE_ENUM OV7675Banding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
				 OV7675_set_banding_for_50Hz();
				 break;
			case CAM_BANDING_60HZ:
				 OV7675_set_banding_for_60Hz();
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
*    OV7675AeEnable
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
static MM_ERROR_CODE_ENUM OV7675AeEnable(kal_bool Enable)
{
	kal_uint16 TempAe = 0;
	TempAe = CamReadCmosSensor(0x13);
  	if (Enable)	
	{
		// Enable the AE/AWB.
		TempAe |= 0x05; 
	}
	else
	{
		// Disable the AE/AWB
		TempAe &= (0xfa); 
	}
	CamWriteCmosSensor(0x13, TempAe); 
#ifdef OV7675_DEBUG
  kal_prompt_trace(MOD_ENG,"AEenable:%d",Enable);
#endif

  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV7675AwbEnable
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
static MM_ERROR_CODE_ENUM OV7675AwbEnable(kal_bool Enable)
{
	kal_uint16 TempAwb = 0;
	TempAwb = CamReadCmosSensor(0x13);
  	if (Enable)	
	{
		// Enable the AE/AWB.
		TempAwb |= 0x02;
	}
	else
	{
		// Disable the AE/AWB
		TempAwb &= (0xfd);
	}
	CamWriteCmosSensor(0x13, TempAwb); 
#ifdef OV7675_DEBUG
  kal_prompt_trace(MOD_ENG,"AWBenable:%d",Enable);
#endif

  return MM_ERROR_NONE;
}

void OV7675GetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT SensorInfo) 
{
	SensorInfo->SensorId			=	OV7675_SENSOR_ID;

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

	SensorInfo->PreviewMclkFreq 	= 	26000000;
	SensorInfo->CaptureMclkFreq 	= 	26000000;
	SensorInfo->VideoMclkFreq 		= 	26000000;

	SensorInfo->PreviewWidth		=	OV7675_IMAGE_SENSOR_VGA_WIDTH;
	SensorInfo->PreviewHeight		=	OV7675_IMAGE_SENSOR_VGA_HEIGHT;
	SensorInfo->FullWidth			=	OV7675_IMAGE_SENSOR_VGA_WIDTH;
	SensorInfo->FullHeight			=	OV7675_IMAGE_SENSOR_VGA_HEIGHT;

	SensorInfo->SensorAfSupport	=	KAL_FALSE;
	SensorInfo->SensorFlashSupport	=	KAL_FALSE;
}	/* OV7675GetSensorInfo() */


static kal_uint16 OV7675PowerOn(void)
{
    CisModulePowerOn(SensorIdxOV7675, KAL_TRUE);
	kal_sleep_task(2);				    // To wait for Stable Power, at least 5ms

	CameraSccbOpen(CAMERA_SCCB_SENSOR, OV7675_WRITE_ID, CAMERA_SCCB_8BIT, CAMERA_SCCB_8BIT, 300);

	CamPdnPinCtrl(SensorIdxOV7675, 1);	/* Set Power Down High */
	kal_sleep_task(1);
	CamPdnPinCtrl(SensorIdxOV7675, 0);	/* Set Power Down Low */
    kal_sleep_task(3); //it should wait at least 10ms before starting I2C

	CamRstPinCtrl(SensorIdxOV7675, 1);	/* Set Power Down High */
	kal_sleep_task(1);
	CamRstPinCtrl(SensorIdxOV7675, 0);	/* Set Power Down Low */
    kal_sleep_task(3); //it should wait at least 10ms before starting I2C
    CamRstPinCtrl(SensorIdxOV7675, 1);	/* Set Power Down Low */
    kal_sleep_task(3); //it should wait at least 10ms before starting I2C
    
	// SW Reset Sensor
	CamWriteCmosSensor(0x12,0x80);
	kal_sleep_task(2); //it should wiate at least 3ms after software reset and start init
	
	OV7675_sensor_id = (CamReadCmosSensor(0x0A)<<8)|CamReadCmosSensor(0x0B);	

	return OV7675_sensor_id;
} /* OV7675PowerOn() */

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
kal_uint32 OV7675DetectSensorId(void)
{
    kal_uint32 SensorId=0;
	IMAGE_SENSOR_INDEX_ENUM ToPdnIdx = (IMAGE_SENSOR_MAIN == SensorIdxOV7675 ? IMAGE_SENSOR_SUB : IMAGE_SENSOR_MAIN);
	kal_int8 i = 0, j = 0;

	for (i = 1; i >= 0; i--)
	{
		for (j = 1; j >= 0; j--)
		{
			/* Make the other camera into power down state. */
			CamRstPinCtrl(ToPdnIdx, i);
			CamRstPinCtrl(ToPdnIdx, j);
			
			SensorId = OV7675PowerOn();
			
			OV7675SensorClose();
			
			if (OV7675_SENSOR_ID == SensorId)
			{
				return OV7675_SENSOR_ID;
			}
		}
	}

    return MM_ERROR_SENSOR_READ_ID_FAIL;
}   /* OV7675DetectSensorId() */


MM_ERROR_CODE_ENUM OV7675StillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In,
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
}   /* OV7675StillCaptureSize() */

void OV7675InitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT Para)
{
	Para->CaptureDelayFrame = 2; /* wait stable frame when sensor change mode (pre to cap) */
	Para->PreviewDelayFrame = 5; /* wait stable frame when sensor change mode (cap to pre) */
	Para->PreviewDisplayWaitFrame = 2; /* wait stable frame when sensor change mode (cap to pre) */
} /* OV7675InitOperationPara() */

static kal_uint8 BandingFlag = 0;
MM_ERROR_CODE_ENUM OV7675Preview(CAL_SCENARIO_ENUM ScenarioId,
								  P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT in,
								  P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT out)
{
	MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;

	switch (ScenarioId)
	{
	case CAL_SCENARIO_VIDEO:
		out->WaitStableFrameNum = 3;
		break;
	case CAL_SCENARIO_CAMERA_PREVIEW:
	case CAL_SCENARIO_WEBCAM_PREVIEW:
	case CAL_SCENARIO_WEBCAM_CAPTURE:
		out->WaitStableFrameNum = 5;
		break;
	default:
		ErrorCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		break;
	}

	OV7675SetMirrorFlip(in->ImageMirror);
	
	if (CAM_BANDING_50HZ == in->BandingFreq)
		OV7675_set_banding_for_50Hz();
	else
		OV7675_set_banding_for_60Hz();
	
	
	if (BandingFlag != in->BandingFreq)
		{
		BandingFlag = in->BandingFreq;
		OV7675AeEnable(KAL_FALSE);
		CamWriteCmosSensor(0x10,0x00);
		kal_sleep_task(10);
		OV7675AeEnable(KAL_TRUE);
		}
	OV7675AwbEnable(KAL_TRUE);
	OV7675_night_mode(in->NightMode);
	out->GrabStartX = OV7675_IMAGE_SENSOR_VGA_INSERTED_PIXELS;
	out->GrabStartY = OV7675_IMAGE_SENSOR_VGA_INSERTED_LINES;
	out->ExposureWindowWidth = OV7675_IMAGE_SENSOR_VGA_WIDTH;
	out->ExposureWindowHeight = OV7675_IMAGE_SENSOR_VGA_HEIGHT - 7;
	/*add For OV7675 preview screen show reddish when point to dark region*/
	kal_sleep_task(100);
	CamWriteCmosSensor(0x6f,0x96);
	kal_sleep_task(10);
	/*add For OV7675 preview screen show reddish when point to dark region*/

	return ErrorCode;
} /* OV7675Preview */

MM_ERROR_CODE_ENUM OV7675Capture(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT in,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT out)
{
	MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;

	out->GrabStartX = OV7675_IMAGE_SENSOR_VGA_INSERTED_PIXELS;
	out->GrabStartY = OV7675_IMAGE_SENSOR_VGA_INSERTED_LINES;
	out->ExposureWindowWidth = OV7675_IMAGE_SENSOR_VGA_WIDTH;
	out->ExposureWindowHeight = OV7675_IMAGE_SENSOR_VGA_HEIGHT - 7;
	
	return ErrorCode;
} 	/* OV7675Capture() */

MM_ERROR_CODE_ENUM OV7675SensorOpen(void)
{
	kal_uint16 SensorId;
  
	SensorId = OV7675PowerOn();
	if (OV7675_SENSOR_ID != SensorId)
		return MM_ERROR_SENSOR_READ_ID_FAIL;

	OV7675_init_setting();
  
	return MM_ERROR_NONE;
} /* OV7675SensorOpen() */

/*************************************************************************
* FUNCTION
*    OV7675SensorFeatureCtrl
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
static MM_ERROR_CODE_ENUM OV7675SensorFeatureCtrl(kal_uint32 id, void *In, void *Out, kal_uint32 out_len, kal_uint32 *r_out_len)
{
	MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
	P_CAL_FEATURE_CTRL_STRUCT pCameraFeatureIn=(P_CAL_FEATURE_CTRL_STRUCT) In;
	P_CAL_FEATURE_CTRL_STRUCT pCameraFeatureOut=(P_CAL_FEATURE_CTRL_STRUCT) Out;
	P_CAL_FEATURE_TYPE_ENUM_STRUCT pCamFeatureEnum=(P_CAL_FEATURE_TYPE_ENUM_STRUCT) &(pCameraFeatureOut->FeatureInfo.FeatureEnum);

  if (id >= CAL_FEATURE_WEBCAM_BEGIN && id <= CAL_FEATURE_WEBCAM_END)
  {
    return OV7675WebcamFeatureCtrl(id, In, Out, out_len, r_out_len);
  }

  if(Out!=NULL && CAL_FEATURE_QUERY_OPERATION==pCameraFeatureIn->FeatureCtrlCode){
        pCamFeatureEnum->IsSupport = KAL_FALSE;
  }

  switch (id)
  {
     /* CAL Query and set series */
    case CAL_FEATURE_CAMERA_BRIGHTNESS:
    case CAL_FEATURE_CAMERA_EV_VALUE:
      ErrCode = OV7675EV(In, Out);
      break;
    case CAL_FEATURE_CAMERA_CONTRAST:
    case CAL_FEATURE_CAMERA_HUE:
    case CAL_FEATURE_CAMERA_SATURATION:
    case CAL_FEATURE_CAMERA_SHARPNESS:
    case CAL_FEATURE_CAMERA_GAMMA:
      ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
      break;
    case CAL_FEATURE_CAMERA_WB:
      ErrCode = OV7675WB(In, Out);
      break;
    case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
      ErrCode = OV7675Effect(In, Out);
      break;
    case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
      ErrCode = OV7675StillCaptureSize(In, Out);
      break;
    case CAL_FEATURE_CAMERA_BANDING_FREQ: /* move to preview */
      ErrCode = OV7675Banding(In, Out);
      break;
	case CAL_FEATURE_CAMERA_SCENE_MODE:
      ErrCode = OV7675SceneMode(KAL_TRUE, In, Out);
      break;
    case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
      ErrCode = OV7675SceneMode(KAL_FALSE, In, Out);
      break;
    case CAL_FEATURE_CAMERA_FLASH_MODE:
      ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
      break;

    /* Get Info series */
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
      OV7675GetSensorInfo((P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT)Out);
      break;
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
      ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = OV7675DetectSensorId();
      break;
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
		// TODO: Need implement the video night function and then update it.
      ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = 150;
      break;
    case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
      OV7675InitOperationPara((P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT)Out);
      break;

	case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
		CamPdnPinCtrl(SensorIdxOV7675, 1);
		//CamRstPinCtrl(SensorIdxOV7675, 0);		// OV7675 don't have the reset pin.
		break;
    /* Set Para series */
    case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
      ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
      break;      
    case IMAGE_SENSOR_FEATURE_VSYNC_HISR_INFORM_FRAME_TIME:
    break;      
    case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
      SensorIdxOV7675 = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
      break;
    case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
      break;     
	case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
		ErrCode = OV7675AeEnable((kal_bool)(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue));
		break;
	case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
		ErrCode = OV7675AwbEnable((kal_bool)(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue));
		break;
	case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
	    CamGetHWInfo(SensorIdxOV7675, Out);
	    break;
    default:
      ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
      break;
  }
  return ErrCode;
}

MM_ERROR_CODE_ENUM OV7675SensorCtrl(CAL_SCENARIO_ENUM ScenarioId, void *pParaIn,
                                         void *pParaOut, kal_uint32 ParaOutLen, kal_uint32 *RealOutLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;

    switch (ScenarioId)
    {
        case CAL_SCENARIO_CAMERA_PREVIEW:
        case CAL_SCENARIO_VIDEO:
        case CAL_SCENARIO_WEBCAM_PREVIEW:
        case CAL_SCENARIO_WEBCAM_CAPTURE:
            OV7675Preview(ScenarioId, pParaIn, pParaOut);
        break;
        case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
            OV7675Capture(ScenarioId, pParaIn, pParaOut);
        break;
        default:
        break;
    }
    return ErrorCode;
}

MM_ERROR_CODE_ENUM OV7675SensorClose(void)
{
	CameraSccbClose(CAMERA_SCCB_SENSOR);
	
    CisModulePowerOn(SensorIdxOV7675, KAL_FALSE);

    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV7675SensorFunc
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
MM_ERROR_CODE_ENUM OV7675SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
	static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncOV7675=
	{
		OV7675SensorOpen,
		OV7675SensorFeatureCtrl,
		OV7675SensorCtrl,
		OV7675SensorClose,
	};

	*pfSensorFunc = &ImageSensorFuncOV7675;

	return MM_ERROR_NONE;
}


