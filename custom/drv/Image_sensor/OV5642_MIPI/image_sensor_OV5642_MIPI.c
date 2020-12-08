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
 *   image_sensor_OV5642_MIPI.c
 *
 * Project:
 * --------
 *   MT6236
 *
 * Description:
 * ------------
 *   OV5642 MIPI sensor driver
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

#define __OV5642_MIPI_DBG__

IMAGE_SENSOR_INDEX_ENUM OV5642MipiSensorIdx;
sensor_data_struct *pOV5642MipiNvramSensorData;
SensorInfo OV5642_MIPI_g_CCT_MainSensor = OV5642_MIPI_CURRENT_MAIN_SENSOR;
static struct OV5642_MIPI_SENSOR_STRUCT OV5642MipiSensorStatus;
extern camcorder_info_struct	OV5642_MIPI_dsc_support_info;
extern void SetIspDrivingCurrent(kal_uint8 Current);
extern void CamRstPinCtrl(IMAGE_SENSOR_INDEX_ENUM Idx, kal_int8 Data);
extern void CamPdnPinCtrl(IMAGE_SENSOR_INDEX_ENUM Idx, kal_int8 Data);


void OV5642MipiWriteShutter(const kal_uint16 iShutter)
{
  kal_uint16 ShutterLimit = iShutter + OV5642_MIPI_SHUTTER_MAX_MARGIN; 
  kal_uint16 FrameHeight;

    if (OV5642MipiSensorStatus.PvMode==KAL_TRUE)
        FrameHeight=OV5642MipiSensorStatus.PvFrameLength;
    else
        FrameHeight=OV5642MipiSensorStatus.CapFrameLength;
  
    if (ShutterLimit < FrameHeight)
        {
        ShutterLimit = FrameHeight;
        }
	
    CamWriteCmosSensor(0x350C, ShutterLimit >> 8); /* AEC VTS output */
    CamWriteCmosSensor(0x350D, ShutterLimit);
		
    CamWriteCmosSensor(0x3500, (iShutter>> 12) & 0xFF);/* shutter */
    CamWriteCmosSensor(0x3501, (iShutter >> 4 ) & 0xFF); 
    CamWriteCmosSensor(0x3502, (iShutter<<4 ) & 0xFF);
}
/*************************************************************************
* FUNCTION
*	OV5642_MIPI_SetShutter
*
* DESCRIPTION
*	This function set e-shutter of OV5642_MIPI to change exposure time.
*
* PARAMETERS
*   iShutter : exposured lines
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/

void OV5642MipiSetShutter(const kal_uint16 iShutter)
{
#ifdef __OV5642_MIPI_DBG__
	kal_print_string_trace(MOD_ENG, TRACE_INFO, "** iShutter:%d",iShutter);

#endif

    OV5642MipiSensorStatus.ExposureLines=iShutter;

    OV5642MipiWriteShutter(iShutter);

 }  /*  OV5642_MIPI_Write_Shutter    */

static void OV5642MipiSetDummy(const kal_uint16 iPixels, const kal_uint16 iLines)
{
    ASSERT(iPixels<0x0fff);
    ASSERT(iLines<0x0fff);	

	CamWriteCmosSensor(0x380c, (iPixels >> 8) & 0xFF);
	CamWriteCmosSensor(0x380d, iPixels & 0xFF);
    CamWriteCmosSensor(0x380e, (iLines >> 8) & 0xFF);
	CamWriteCmosSensor(0x380f, iLines & 0xFF);

}   /*  OV5642_MIPI_Set_Dummy    */


void OV5642MiPiInitialSetting()
{
    CamWriteCmosSensor(0x3103,0x93);
	CamWriteCmosSensor(0x3008,0x82);
	CamWriteCmosSensor(0x3017,0x7f);
	CamWriteCmosSensor(0x3018,0xfc);
	CamWriteCmosSensor(0x3615,0xf0);
	CamWriteCmosSensor(0x3000,0x00);
	CamWriteCmosSensor(0x3001,0x00);
	CamWriteCmosSensor(0x3002,0x5c);
	CamWriteCmosSensor(0x3003,0x00);
	CamWriteCmosSensor(0x3004,0xff);
	CamWriteCmosSensor(0x3005,0xff);
	CamWriteCmosSensor(0x3006,0x43);
	CamWriteCmosSensor(0x3007,0x37);
	CamWriteCmosSensor(0x3011,0x0a);//09
	CamWriteCmosSensor(0x3012,0x02);
	CamWriteCmosSensor(0x3010,0x00);
	CamWriteCmosSensor(0x460c,0x20);
	CamWriteCmosSensor(0x3815,0x04);
	CamWriteCmosSensor(0x370c,0xa0);
	CamWriteCmosSensor(0x3602,0xfc);
	CamWriteCmosSensor(0x3612,0xff);
	CamWriteCmosSensor(0x3634,0xc0);
	CamWriteCmosSensor(0x3613,0x00);
	CamWriteCmosSensor(0x3605,0x7c);
	CamWriteCmosSensor(0x3621,0x09);
	CamWriteCmosSensor(0x3622,0x60);
	CamWriteCmosSensor(0x3604,0x40);
	CamWriteCmosSensor(0x3603,0xa7);
	CamWriteCmosSensor(0x3603,0x27);
	CamWriteCmosSensor(0x4000,0x21);
	CamWriteCmosSensor(0x401d,0x22);
	CamWriteCmosSensor(0x3600,0x54);
	CamWriteCmosSensor(0x3605,0x04);
	CamWriteCmosSensor(0x3606,0x3f);
	CamWriteCmosSensor(0x3c01,0x80);
	CamWriteCmosSensor(0x5000,0x4f);
	CamWriteCmosSensor(0x5020,0x04);
	CamWriteCmosSensor(0x5181,0x79);
	CamWriteCmosSensor(0x5182,0x00);
	CamWriteCmosSensor(0x5185,0x22);
	CamWriteCmosSensor(0x5197,0x01);
	CamWriteCmosSensor(0x5001,0xff);
	CamWriteCmosSensor(0x5500,0x0a);
	CamWriteCmosSensor(0x5504,0x00);
	CamWriteCmosSensor(0x5505,0x7f);
	CamWriteCmosSensor(0x5080,0x08);
	CamWriteCmosSensor(0x300e,0x18);
	CamWriteCmosSensor(0x4610,0x00);
	CamWriteCmosSensor(0x471d,0x05);
	CamWriteCmosSensor(0x4708,0x06);
	CamWriteCmosSensor(0x3808,0x05);//02
	CamWriteCmosSensor(0x3809,0x10);//80
	CamWriteCmosSensor(0x380a,0x03);//01
	CamWriteCmosSensor(0x380b,0xcc);//e0
	CamWriteCmosSensor(0x380e,0x07);
	CamWriteCmosSensor(0x380f,0xd0);
	CamWriteCmosSensor(0x501f,0x00);
	CamWriteCmosSensor(0x5000,0x4f);
	CamWriteCmosSensor(0x4300,0x30);
	CamWriteCmosSensor(0x3503,0x07);
	CamWriteCmosSensor(0x3501,0x73);
	CamWriteCmosSensor(0x3502,0x80);
	CamWriteCmosSensor(0x350b,0x00);
	CamWriteCmosSensor(0x3503,0x07);
	CamWriteCmosSensor(0x3824,0x11);
	CamWriteCmosSensor(0x3825,0xb0);
	CamWriteCmosSensor(0x3501,0x1e);
	CamWriteCmosSensor(0x3502,0x80);
	CamWriteCmosSensor(0x350b,0x7f);
	CamWriteCmosSensor(0x380c,0x07);
	CamWriteCmosSensor(0x380d,0xc0);//2a
	CamWriteCmosSensor(0x380e,0x03);
	CamWriteCmosSensor(0x380f,0xf0);//e8
	CamWriteCmosSensor(0x3a0d,0x04);
	CamWriteCmosSensor(0x3a0e,0x03);
	CamWriteCmosSensor(0x3818,0xc1);
	CamWriteCmosSensor(0x3705,0xdb);
	CamWriteCmosSensor(0x370a,0x81);
	CamWriteCmosSensor(0x3801,0x80);
	CamWriteCmosSensor(0x3621,0xc7);
	CamWriteCmosSensor(0x3801,0x50);
	CamWriteCmosSensor(0x3803,0x08);
	CamWriteCmosSensor(0x3827,0x08);
	CamWriteCmosSensor(0x3810,0x42);//80
	CamWriteCmosSensor(0x3804,0x05);
	CamWriteCmosSensor(0x3805,0x10);//;00
	CamWriteCmosSensor(0x5682,0x05);
	CamWriteCmosSensor(0x5683,0x10);//00
	CamWriteCmosSensor(0x3806,0x03);
	CamWriteCmosSensor(0x3807,0xcc);//;c0
	CamWriteCmosSensor(0x5686,0x03);
	CamWriteCmosSensor(0x5687,0xc4);//;bc
	CamWriteCmosSensor(0x3a00,0x78);
	CamWriteCmosSensor(0x3a1a,0x05);
	CamWriteCmosSensor(0x3a13,0x30);
	CamWriteCmosSensor(0x3a18,0x00);
	CamWriteCmosSensor(0x3a19,0x7c);
	CamWriteCmosSensor(0x3a08,0x12);
	CamWriteCmosSensor(0x3a09,0xc0);
	CamWriteCmosSensor(0x3a0a,0x0f);
	CamWriteCmosSensor(0x3a0b,0xa0);
	CamWriteCmosSensor(0x350c,0x07);
	CamWriteCmosSensor(0x350d,0xd0);
	CamWriteCmosSensor(0x3500,0x00);
	CamWriteCmosSensor(0x3501,0x00);
	CamWriteCmosSensor(0x3502,0x00);
	CamWriteCmosSensor(0x350a,0x00);
	CamWriteCmosSensor(0x350b,0x00);
	CamWriteCmosSensor(0x3503,0x07);//disable 3A  0x00);
	CamWriteCmosSensor(0x528a,0x02);
	CamWriteCmosSensor(0x528b,0x04);
	CamWriteCmosSensor(0x528c,0x08);
	CamWriteCmosSensor(0x528d,0x08);
	CamWriteCmosSensor(0x528e,0x08);
	CamWriteCmosSensor(0x528f,0x10);
	CamWriteCmosSensor(0x5290,0x10);
	CamWriteCmosSensor(0x5292,0x00);
	CamWriteCmosSensor(0x5293,0x02);
	CamWriteCmosSensor(0x5294,0x00);
	CamWriteCmosSensor(0x5295,0x02);
	CamWriteCmosSensor(0x5296,0x00);
	CamWriteCmosSensor(0x5297,0x02);
	CamWriteCmosSensor(0x5298,0x00);
	CamWriteCmosSensor(0x5299,0x02);
	CamWriteCmosSensor(0x529a,0x00);
	CamWriteCmosSensor(0x529b,0x02);
	CamWriteCmosSensor(0x529c,0x00);
	CamWriteCmosSensor(0x529d,0x02);
	CamWriteCmosSensor(0x529e,0x00);
	CamWriteCmosSensor(0x529f,0x02);
	CamWriteCmosSensor(0x3a0f,0x3c);
	CamWriteCmosSensor(0x3a10,0x30);
	CamWriteCmosSensor(0x3a1b,0x3c);
	CamWriteCmosSensor(0x3a1e,0x30);
	CamWriteCmosSensor(0x3a11,0x70);
	CamWriteCmosSensor(0x3a1f,0x10);
	CamWriteCmosSensor(0x3030,0x2b);
	CamWriteCmosSensor(0x3a02,0x00);
	CamWriteCmosSensor(0x3a03,0x7d);
	CamWriteCmosSensor(0x3a04,0x00);
	CamWriteCmosSensor(0x3a14,0x00);
	CamWriteCmosSensor(0x3a15,0x7d);
	CamWriteCmosSensor(0x3a16,0x00);
	CamWriteCmosSensor(0x3a00,0x78);
	CamWriteCmosSensor(0x3a08,0x12);
	CamWriteCmosSensor(0x3a09,0xc0);
	CamWriteCmosSensor(0x3a0a,0x0f);
	CamWriteCmosSensor(0x3a0b,0xa0);
	CamWriteCmosSensor(0x3a0d,0x04);
	CamWriteCmosSensor(0x3a0e,0x03);
	CamWriteCmosSensor(0x5193,0x70);
	CamWriteCmosSensor(0x589b,0x04);
	CamWriteCmosSensor(0x589a,0xc5);
	CamWriteCmosSensor(0x4001,0x42);
	CamWriteCmosSensor(0x401c,0x04);
	CamWriteCmosSensor(0x528a,0x01);
	CamWriteCmosSensor(0x528b,0x04);
	CamWriteCmosSensor(0x528c,0x08);
	CamWriteCmosSensor(0x528d,0x10);
	CamWriteCmosSensor(0x528e,0x20);
	CamWriteCmosSensor(0x528f,0x28);
	CamWriteCmosSensor(0x5290,0x30);
	CamWriteCmosSensor(0x5292,0x00);
	CamWriteCmosSensor(0x5293,0x01);
	CamWriteCmosSensor(0x5294,0x00);
	CamWriteCmosSensor(0x5295,0x04);
	CamWriteCmosSensor(0x5296,0x00);
	CamWriteCmosSensor(0x5297,0x08);
	CamWriteCmosSensor(0x5298,0x00);
	CamWriteCmosSensor(0x5299,0x10);
	CamWriteCmosSensor(0x529a,0x00);
	CamWriteCmosSensor(0x529b,0x20);
	CamWriteCmosSensor(0x529c,0x00);
	CamWriteCmosSensor(0x529d,0x28);
	CamWriteCmosSensor(0x529e,0x00);
	CamWriteCmosSensor(0x529f,0x30);
	CamWriteCmosSensor(0x5282,0x00);
	CamWriteCmosSensor(0x5300,0x00);
	CamWriteCmosSensor(0x5301,0x20);
	CamWriteCmosSensor(0x5302,0x00);
	CamWriteCmosSensor(0x5303,0x7c);
	CamWriteCmosSensor(0x530c,0x00);
	CamWriteCmosSensor(0x530d,0x0c);
	CamWriteCmosSensor(0x530e,0x20);
	CamWriteCmosSensor(0x530f,0x80);
	CamWriteCmosSensor(0x5310,0x20);
	CamWriteCmosSensor(0x5311,0x80);
	CamWriteCmosSensor(0x5308,0x20);
	CamWriteCmosSensor(0x5309,0x40);
	CamWriteCmosSensor(0x5304,0x00);
	CamWriteCmosSensor(0x5305,0x30);
	CamWriteCmosSensor(0x5306,0x00);
	CamWriteCmosSensor(0x5307,0x80);
	CamWriteCmosSensor(0x5314,0x08);
	CamWriteCmosSensor(0x5315,0x20);
	CamWriteCmosSensor(0x5319,0x30);
	CamWriteCmosSensor(0x5316,0x10);
	CamWriteCmosSensor(0x5317,0x08);
	CamWriteCmosSensor(0x5318,0x02);
	CamWriteCmosSensor(0x5380,0x01);
	CamWriteCmosSensor(0x5381,0x00);
	CamWriteCmosSensor(0x5382,0x00);
	CamWriteCmosSensor(0x5383,0x4e);
	CamWriteCmosSensor(0x5384,0x00);
	CamWriteCmosSensor(0x5385,0x0f);
	CamWriteCmosSensor(0x5386,0x00);
	CamWriteCmosSensor(0x5387,0x00);
	CamWriteCmosSensor(0x5388,0x01);
	CamWriteCmosSensor(0x5389,0x15);
	CamWriteCmosSensor(0x538a,0x00);
	CamWriteCmosSensor(0x538b,0x31);
	CamWriteCmosSensor(0x538c,0x00);
	CamWriteCmosSensor(0x538d,0x00);
	CamWriteCmosSensor(0x538e,0x00);
	CamWriteCmosSensor(0x538f,0x0f);
	CamWriteCmosSensor(0x5390,0x00);
	CamWriteCmosSensor(0x5391,0xab);
	CamWriteCmosSensor(0x5392,0x00);
	CamWriteCmosSensor(0x5393,0xa2);
	CamWriteCmosSensor(0x5394,0x08);
	CamWriteCmosSensor(0x5480,0x14);
	CamWriteCmosSensor(0x5481,0x21);
	CamWriteCmosSensor(0x5482,0x36);
	CamWriteCmosSensor(0x5483,0x57);
	CamWriteCmosSensor(0x5484,0x65);
	CamWriteCmosSensor(0x5485,0x71);
	CamWriteCmosSensor(0x5486,0x7d);
	CamWriteCmosSensor(0x5487,0x87);
	CamWriteCmosSensor(0x5488,0x91);
	CamWriteCmosSensor(0x5489,0x9a);
	CamWriteCmosSensor(0x548a,0xaa);
	CamWriteCmosSensor(0x548b,0xb8);
	CamWriteCmosSensor(0x548c,0xcd);
	CamWriteCmosSensor(0x548d,0xdd);
	CamWriteCmosSensor(0x548e,0xea);
	CamWriteCmosSensor(0x548f,0x10);
	CamWriteCmosSensor(0x5490,0x05);
	CamWriteCmosSensor(0x5491,0x00);
	CamWriteCmosSensor(0x5492,0x04);
	CamWriteCmosSensor(0x5493,0x20);
	CamWriteCmosSensor(0x5494,0x03);
	CamWriteCmosSensor(0x5495,0x60);
	CamWriteCmosSensor(0x5496,0x02);
	CamWriteCmosSensor(0x5497,0xb8);
	CamWriteCmosSensor(0x5498,0x02);
	CamWriteCmosSensor(0x5499,0x86);
	CamWriteCmosSensor(0x549a,0x02);
	CamWriteCmosSensor(0x549b,0x5b);
	CamWriteCmosSensor(0x549c,0x02);
	CamWriteCmosSensor(0x549d,0x3b);
	CamWriteCmosSensor(0x549e,0x02);
	CamWriteCmosSensor(0x549f,0x1c);
	CamWriteCmosSensor(0x54a0,0x02);
	CamWriteCmosSensor(0x54a1,0x04);
	CamWriteCmosSensor(0x54a2,0x01);
	CamWriteCmosSensor(0x54a3,0xed);
	CamWriteCmosSensor(0x54a4,0x01);
	CamWriteCmosSensor(0x54a5,0xc5);
	CamWriteCmosSensor(0x54a6,0x01);
	CamWriteCmosSensor(0x54a7,0xa5);
	CamWriteCmosSensor(0x54a8,0x01);
	CamWriteCmosSensor(0x54a9,0x6c);
	CamWriteCmosSensor(0x54aa,0x01);
	CamWriteCmosSensor(0x54ab,0x41);
	CamWriteCmosSensor(0x54ac,0x01);
	CamWriteCmosSensor(0x54ad,0x20);
	CamWriteCmosSensor(0x54ae,0x00);
	CamWriteCmosSensor(0x54af,0x16);
	CamWriteCmosSensor(0x3406,0x00);
	CamWriteCmosSensor(0x5192,0x04);
	CamWriteCmosSensor(0x5191,0xf8);
	CamWriteCmosSensor(0x5193,0x70);
	CamWriteCmosSensor(0x5194,0xf0);
	CamWriteCmosSensor(0x5195,0xf0);
	CamWriteCmosSensor(0x518d,0x3d);
	CamWriteCmosSensor(0x518f,0x54);
	CamWriteCmosSensor(0x518e,0x3d);
	CamWriteCmosSensor(0x5190,0x54);
	CamWriteCmosSensor(0x518b,0xa8);
	CamWriteCmosSensor(0x518c,0xa8);
	CamWriteCmosSensor(0x5187,0x18);
	CamWriteCmosSensor(0x5188,0x18);
	CamWriteCmosSensor(0x5189,0x6e);
	CamWriteCmosSensor(0x518a,0x68);
	CamWriteCmosSensor(0x5186,0x1c);
	CamWriteCmosSensor(0x5181,0x50);
	CamWriteCmosSensor(0x5184,0x25);
	CamWriteCmosSensor(0x5182,0x11);
	CamWriteCmosSensor(0x5183,0x14);
	CamWriteCmosSensor(0x5184,0x25);
	CamWriteCmosSensor(0x5185,0x24);
	CamWriteCmosSensor(0x5025,0x82);
	CamWriteCmosSensor(0x3a0f,0x7e);
	CamWriteCmosSensor(0x3a10,0x72);
	CamWriteCmosSensor(0x3a1b,0x80);
	CamWriteCmosSensor(0x3a1e,0x70);
	CamWriteCmosSensor(0x3a11,0xd0);
	CamWriteCmosSensor(0x3a1f,0x40);
	CamWriteCmosSensor(0x5583,0x40);
	CamWriteCmosSensor(0x5584,0x40);
	CamWriteCmosSensor(0x5580,0x02);
	CamWriteCmosSensor(0x5000,0xcf);
	CamWriteCmosSensor(0x5800,0x27);
	CamWriteCmosSensor(0x5801,0x19);
	CamWriteCmosSensor(0x5802,0x12);
	CamWriteCmosSensor(0x5803,0x0f);
	CamWriteCmosSensor(0x5804,0x10);
	CamWriteCmosSensor(0x5805,0x15);
	CamWriteCmosSensor(0x5806,0x1e);
	CamWriteCmosSensor(0x5807,0x2f);
	CamWriteCmosSensor(0x5808,0x15);
	CamWriteCmosSensor(0x5809,0x0d);
	CamWriteCmosSensor(0x580a,0x0a);
	CamWriteCmosSensor(0x580b,0x09);
	CamWriteCmosSensor(0x580c,0x0a);
	CamWriteCmosSensor(0x580d,0x0c);
	CamWriteCmosSensor(0x580e,0x12);
	CamWriteCmosSensor(0x580f,0x19);
	CamWriteCmosSensor(0x5810,0x0b);
	CamWriteCmosSensor(0x5811,0x07);
	CamWriteCmosSensor(0x5812,0x04);
	CamWriteCmosSensor(0x5813,0x03);
	CamWriteCmosSensor(0x5814,0x03);
	CamWriteCmosSensor(0x5815,0x06);
	CamWriteCmosSensor(0x5816,0x0a);
	CamWriteCmosSensor(0x5817,0x0f);
	CamWriteCmosSensor(0x5818,0x0a);
	CamWriteCmosSensor(0x5819,0x05);
	CamWriteCmosSensor(0x581a,0x01);
	CamWriteCmosSensor(0x581b,0x00);
	CamWriteCmosSensor(0x581c,0x00);
	CamWriteCmosSensor(0x581d,0x03);
	CamWriteCmosSensor(0x581e,0x08);
	CamWriteCmosSensor(0x581f,0x0c);
	CamWriteCmosSensor(0x5820,0x0a);
	CamWriteCmosSensor(0x5821,0x05);
	CamWriteCmosSensor(0x5822,0x01);
	CamWriteCmosSensor(0x5823,0x00);
	CamWriteCmosSensor(0x5824,0x00);
	CamWriteCmosSensor(0x5825,0x03);
	CamWriteCmosSensor(0x5826,0x08);
	CamWriteCmosSensor(0x5827,0x0c);
	CamWriteCmosSensor(0x5828,0x0e);
	CamWriteCmosSensor(0x5829,0x08);
	CamWriteCmosSensor(0x582a,0x06);
	CamWriteCmosSensor(0x582b,0x04);
	CamWriteCmosSensor(0x582c,0x05);
	CamWriteCmosSensor(0x582d,0x07);
	CamWriteCmosSensor(0x582e,0x0b);
	CamWriteCmosSensor(0x582f,0x12);
	CamWriteCmosSensor(0x5830,0x18);
	CamWriteCmosSensor(0x5831,0x10);
	CamWriteCmosSensor(0x5832,0x0c);
	CamWriteCmosSensor(0x5833,0x0a);
	CamWriteCmosSensor(0x5834,0x0b);
	CamWriteCmosSensor(0x5835,0x0e);
	CamWriteCmosSensor(0x5836,0x15);
	CamWriteCmosSensor(0x5837,0x19);
	CamWriteCmosSensor(0x5838,0x32);
	CamWriteCmosSensor(0x5839,0x1f);
	CamWriteCmosSensor(0x583a,0x18);
	CamWriteCmosSensor(0x583b,0x16);
	CamWriteCmosSensor(0x583c,0x17);
	CamWriteCmosSensor(0x583d,0x1e);
	CamWriteCmosSensor(0x583e,0x26);
	CamWriteCmosSensor(0x583f,0x53);
	CamWriteCmosSensor(0x5840,0x10);
	CamWriteCmosSensor(0x5841,0x0f);
	CamWriteCmosSensor(0x5842,0x0d);
	CamWriteCmosSensor(0x5843,0x0c);
	CamWriteCmosSensor(0x5844,0x0e);
	CamWriteCmosSensor(0x5845,0x09);
	CamWriteCmosSensor(0x5846,0x11);
	CamWriteCmosSensor(0x5847,0x10);
	CamWriteCmosSensor(0x5848,0x10);
	CamWriteCmosSensor(0x5849,0x10);
	CamWriteCmosSensor(0x584a,0x10);
	CamWriteCmosSensor(0x584b,0x0e);
	CamWriteCmosSensor(0x584c,0x10);
	CamWriteCmosSensor(0x584d,0x10);
	CamWriteCmosSensor(0x584e,0x11);
	CamWriteCmosSensor(0x584f,0x10);
	CamWriteCmosSensor(0x5850,0x0f);
	CamWriteCmosSensor(0x5851,0x0c);
	CamWriteCmosSensor(0x5852,0x0f);
	CamWriteCmosSensor(0x5853,0x10);
	CamWriteCmosSensor(0x5854,0x10);
	CamWriteCmosSensor(0x5855,0x0f);
	CamWriteCmosSensor(0x5856,0x0e);
	CamWriteCmosSensor(0x5857,0x0b);
	CamWriteCmosSensor(0x5858,0x10);
	CamWriteCmosSensor(0x5859,0x0d);
	CamWriteCmosSensor(0x585a,0x0d);
	CamWriteCmosSensor(0x585b,0x0c);
	CamWriteCmosSensor(0x585c,0x0c);
	CamWriteCmosSensor(0x585d,0x0c);
	CamWriteCmosSensor(0x585e,0x0b);
	CamWriteCmosSensor(0x585f,0x0c);
	CamWriteCmosSensor(0x5860,0x0c);
	CamWriteCmosSensor(0x5861,0x0c);
	CamWriteCmosSensor(0x5862,0x0d);
	CamWriteCmosSensor(0x5863,0x08);
	CamWriteCmosSensor(0x5864,0x11);
	CamWriteCmosSensor(0x5865,0x18);
	CamWriteCmosSensor(0x5866,0x18);
	CamWriteCmosSensor(0x5867,0x19);
	CamWriteCmosSensor(0x5868,0x17);
	CamWriteCmosSensor(0x5869,0x19);
	CamWriteCmosSensor(0x586a,0x16);
	CamWriteCmosSensor(0x586b,0x13);
	CamWriteCmosSensor(0x586c,0x13);
	CamWriteCmosSensor(0x586d,0x12);
	CamWriteCmosSensor(0x586e,0x13);
	CamWriteCmosSensor(0x586f,0x16);
	CamWriteCmosSensor(0x5870,0x14);
	CamWriteCmosSensor(0x5871,0x12);
	CamWriteCmosSensor(0x5872,0x10);
	CamWriteCmosSensor(0x5873,0x11);
	CamWriteCmosSensor(0x5874,0x11);
	CamWriteCmosSensor(0x5875,0x16);
	CamWriteCmosSensor(0x5876,0x14);
	CamWriteCmosSensor(0x5877,0x11);
	CamWriteCmosSensor(0x5878,0x10);
	CamWriteCmosSensor(0x5879,0x0f);
	CamWriteCmosSensor(0x587a,0x10);
	CamWriteCmosSensor(0x587b,0x14);
	CamWriteCmosSensor(0x587c,0x13);
	CamWriteCmosSensor(0x587d,0x12);
	CamWriteCmosSensor(0x587e,0x11);
	CamWriteCmosSensor(0x587f,0x11);
	CamWriteCmosSensor(0x5880,0x12);
	CamWriteCmosSensor(0x5881,0x15);
	CamWriteCmosSensor(0x5882,0x14);
	CamWriteCmosSensor(0x5883,0x15);
	CamWriteCmosSensor(0x5884,0x15);
	CamWriteCmosSensor(0x5885,0x15);
	CamWriteCmosSensor(0x5886,0x13);
	CamWriteCmosSensor(0x5887,0x17);
	CamWriteCmosSensor(0x3710,0x10);
	CamWriteCmosSensor(0x3632,0x51);
	CamWriteCmosSensor(0x3702,0x10);
	CamWriteCmosSensor(0x3703,0xb2);
	CamWriteCmosSensor(0x3704,0x18);
	CamWriteCmosSensor(0x370b,0x40);
	CamWriteCmosSensor(0x370d,0x03);
	CamWriteCmosSensor(0x3631,0x01);
	CamWriteCmosSensor(0x3632,0x52);
	CamWriteCmosSensor(0x3606,0x24);
	CamWriteCmosSensor(0x3620,0x96);
	CamWriteCmosSensor(0x5785,0x07);
	CamWriteCmosSensor(0x3a13,0x30);
	CamWriteCmosSensor(0x3600,0x52);
	CamWriteCmosSensor(0x3604,0x48);
	CamWriteCmosSensor(0x3606,0x1b);
	CamWriteCmosSensor(0x370d,0x0b);
	CamWriteCmosSensor(0x370f,0xc0);
	CamWriteCmosSensor(0x3709,0x01);

	/* test*/
		CamWriteCmosSensor(0x3600, 0x52);
		CamWriteCmosSensor(0x3603, 0x27);
		CamWriteCmosSensor(0x3604, 0x48); /* effect brightness */
		CamWriteCmosSensor(0x3605, 0x04);
		CamWriteCmosSensor(0x3606, 0x1B);
		CamWriteCmosSensor(0x3615, 0xF0);
		CamWriteCmosSensor(0x3620, 0x96);
		CamWriteCmosSensor(0x3622, 0x60); /* effect brightness */
		CamWriteCmosSensor(0x3631, 0x01);
		CamWriteCmosSensor(0x3632, 0x52);
		CamWriteCmosSensor(0x3634, 0xC0);
		CamWriteCmosSensor(0x3702, 0x10);
		CamWriteCmosSensor(0x3703, 0xB2);
		CamWriteCmosSensor(0x3704, 0x18);
		CamWriteCmosSensor(0x3709, 0x01);
		CamWriteCmosSensor(0x370B, 0x40);
		CamWriteCmosSensor(0x370C, 0xA0);
		CamWriteCmosSensor(0x370D, 0x0B); /* [6]: vertical binning. 0: disable, 1: enable */
		CamWriteCmosSensor(0x370F, 0xC0);
		CamWriteCmosSensor(0x3710, 0x10);
	//end
	
	CamWriteCmosSensor(0x3823,0x00);
	CamWriteCmosSensor(0x5007,0x00);
	CamWriteCmosSensor(0x5009,0x00);
	CamWriteCmosSensor(0x5011,0x00);
	CamWriteCmosSensor(0x5013,0x00);
	CamWriteCmosSensor(0x519e,0x00);
	CamWriteCmosSensor(0x5086,0x00);
	CamWriteCmosSensor(0x5087,0x00);
	CamWriteCmosSensor(0x5088,0x00);
	CamWriteCmosSensor(0x5089,0x00);
	CamWriteCmosSensor(0x302b,0x00);
	CamWriteCmosSensor(0x3621,0x87);

    kal_sleep_task(16);

	CamWriteCmosSensor(0x3010,0x00);//0x10);
	CamWriteCmosSensor(0x501f,0x03);
	CamWriteCmosSensor(0x4300,0xf8);
	
	CamWriteCmosSensor(0x5000,0x06);
	CamWriteCmosSensor(0x5001,0x00);
	CamWriteCmosSensor(0x3c01,0x80);
	CamWriteCmosSensor(0x3c00,0x4 );

	CamWriteCmosSensor(0x4801,0x0f);
	CamWriteCmosSensor(0x3007,0x3b);
	CamWriteCmosSensor(0x300e,0x04); //clk output
	CamWriteCmosSensor(0x4803,0x50); //data output
	CamWriteCmosSensor(0x3815,0x01);
	CamWriteCmosSensor(0x4713,0x02);
	CamWriteCmosSensor(0x4842,0x01);
	CamWriteCmosSensor(0x3033,0x43);
	CamWriteCmosSensor(0x3815,0x02);
    CamWriteCmosSensor(0x300f,0x0a);//8bit raw
	CamWriteCmosSensor(0x3003,0x03);
	CamWriteCmosSensor(0x3003,0x01);
    /*BLC*/ 
	CamWriteCmosSensor(0x401d, 0x32);
	CamWriteCmosSensor(0x401e, 0x02);

}	


void OV5642MipiSetXGA(kal_uint8 RAW_Data_bits)
{	
	CamWriteCmosSensor(0x3503,0x07);
	CamWriteCmosSensor(0x3001,0x00);
	CamWriteCmosSensor(0x3002,0x5c);
	CamWriteCmosSensor(0x300d,0x22);

	if(RAW_Data_bits==OV5642_MIPI_8BIT_RAW)
	    CamWriteCmosSensor(0x300f,0x0a);
    else
    	{
    	if (RAW_Data_bits==OV5642_MIPI_10BIT_RAW)
    		CamWriteCmosSensor(0x300f,0x0b);
    	}
	
	CamWriteCmosSensor(0x3011,0x0b);
	CamWriteCmosSensor(0x3010,0x10);//0x10->48Mhz, 0x30->24Mhz
	CamWriteCmosSensor(0x3012,0x01);// 
	CamWriteCmosSensor(0x350c,0x03);//shutter limite 1008
	CamWriteCmosSensor(0x350d,0xf0);
	CamWriteCmosSensor(0x3622,0x60);
	CamWriteCmosSensor(0x3621,0x87);
	CamWriteCmosSensor(0x3709,0x01);
	CamWriteCmosSensor(0x3600,0x52);
	CamWriteCmosSensor(0x3602,0xfc);
	CamWriteCmosSensor(0x3606,0x1b);
	CamWriteCmosSensor(0x3612,0xff);
	CamWriteCmosSensor(0x3613,0x00);
	CamWriteCmosSensor(0x3623,0x01);
	CamWriteCmosSensor(0x3705,0xdb);
	CamWriteCmosSensor(0x370a,0x81);
	CamWriteCmosSensor(0x3801,0x50);
	CamWriteCmosSensor(0x3804,0x05);
	CamWriteCmosSensor(0x3805,0x10);
	CamWriteCmosSensor(0x3806,0x03);
	CamWriteCmosSensor(0x3807,0xcc);
	CamWriteCmosSensor(0x3808,0x05);//1296
	CamWriteCmosSensor(0x3809,0x10);
	CamWriteCmosSensor(0x380a,0x03);//972
	CamWriteCmosSensor(0x380b,0xcc);
	CamWriteCmosSensor(0x380c,0x06);//0x07); 1746
	CamWriteCmosSensor(0x380d,0xd2);//0xc0);
	CamWriteCmosSensor(0x380e,0x03);//0x03); 1000
	CamWriteCmosSensor(0x380f,0xe8);//0xf0);
	CamWriteCmosSensor(0x3810,0x42);
	CamWriteCmosSensor(0x3818,0xc1);
	CamWriteCmosSensor(0x3824,0x11);
	CamWriteCmosSensor(0x3825,0xb0);
	CamWriteCmosSensor(0x3827,0x08);
	CamWriteCmosSensor(0x3a1a,0x05);
	CamWriteCmosSensor(0x3a08,0x12);
	CamWriteCmosSensor(0x3a09,0xc0);
	CamWriteCmosSensor(0x3a0a,0x0f);
	CamWriteCmosSensor(0x3a0b,0xa0);
	CamWriteCmosSensor(0x3a0d,0x04);
	CamWriteCmosSensor(0x3a0e,0x03);
	CamWriteCmosSensor(0x401c,0x04);
	CamWriteCmosSensor(0x5000,0x06);
	CamWriteCmosSensor(0x5001,0x00);
	CamWriteCmosSensor(0x5005,0xdc);


}

static void OV5642MipiSetQSXGA(kal_uint8 RAW_Data_bits)
{	
	CamWriteCmosSensor(0x3503,0x07);
	
	CamWriteCmosSensor(0x3001,0x40);
	CamWriteCmosSensor(0x3002,0x1c);
	CamWriteCmosSensor(0x300d,0x21);

	if(RAW_Data_bits==OV5642_MIPI_8BIT_RAW)
	    CamWriteCmosSensor(0x300f,0x0a);
    else
    	{
    	if (RAW_Data_bits==OV5642_MIPI_10BIT_RAW)
    		CamWriteCmosSensor(0x300f,0x0b);
    	}
	
	CamWriteCmosSensor(0x3011,0x0b);//96MHz
	CamWriteCmosSensor(0x3010,0x00);//0x30);
	CamWriteCmosSensor(0x3012,0x01);
	
	CamWriteCmosSensor(0x350c,0x07);
	CamWriteCmosSensor(0x350d,0xd0);
	
	CamWriteCmosSensor(0x3622,0x60);
	CamWriteCmosSensor(0x3621,0x29);
	CamWriteCmosSensor(0x3709,0x00);
	CamWriteCmosSensor(0x3600,0x54);
	CamWriteCmosSensor(0x3602,0xe4);
	CamWriteCmosSensor(0x3606,0x1b);
	CamWriteCmosSensor(0x3612,0xac);
	CamWriteCmosSensor(0x3613,0x44);
	CamWriteCmosSensor(0x3623,0x22);
	CamWriteCmosSensor(0x3705,0xda);
	CamWriteCmosSensor(0x370a,0x80);
	
	CamWriteCmosSensor(0x3801,0xb4);
	CamWriteCmosSensor(0x3804,0x0a);
	CamWriteCmosSensor(0x3805,0x20);
	CamWriteCmosSensor(0x3806,0x07);
	CamWriteCmosSensor(0x3807,0x98);
	CamWriteCmosSensor(0x3808,0x0a);
	CamWriteCmosSensor(0x3809,0x20);
	CamWriteCmosSensor(0x380a,0x07);
	CamWriteCmosSensor(0x380b,0x98);
	CamWriteCmosSensor(0x380c,0x0c);
	CamWriteCmosSensor(0x380d,0x80);
	CamWriteCmosSensor(0x380e,0x07);
	CamWriteCmosSensor(0x380f,0xd0);
	CamWriteCmosSensor(0x3810,0xc2);
	CamWriteCmosSensor(0x3818,0x80);
	CamWriteCmosSensor(0x3824,0x11);
	CamWriteCmosSensor(0x3825,0xac);
	CamWriteCmosSensor(0x3827,0x0c);
	
	CamWriteCmosSensor(0x3a1a,0x04);
	CamWriteCmosSensor(0x3a08,0x09);
	CamWriteCmosSensor(0x3a09,0x60);
	CamWriteCmosSensor(0x3a0a,0x07);
	CamWriteCmosSensor(0x3a0b,0xd0);
	CamWriteCmosSensor(0x3a0d,0x10);
	CamWriteCmosSensor(0x3a0e,0x0d);
	
	CamWriteCmosSensor(0x401c,0x06);
	CamWriteCmosSensor(0x5000,0x06);
	CamWriteCmosSensor(0x5001,0x00);
	CamWriteCmosSensor(0x5005,0x00);
	

}

void OV5642MipiSetDenoise()
{

CamWriteCmosSensor(0x5000,0x0e);
CamWriteCmosSensor(0x5282,(CamReadCmosSensor(0x5282) | 0x01));
CamWriteCmosSensor(0x5283,0x10);
CamWriteCmosSensor(0x5285,0x10);
CamWriteCmosSensor(0x5287,0x10);
}

void OV5642MipiSetMirrorFlip(kal_uint8 image_mirror)
{
    kal_uint8 iTemp1 = 0, iTemp2 = 0;

    iTemp1 = CamReadCmosSensor(0x3818) & 0x9f;	//Clear the mirror and flip bits.

    iTemp2 = CamReadCmosSensor(0x3621);

    switch (image_mirror)
        {
        case IMAGE_SENSOR_MIRROR_NORMAL:
            CamWriteCmosSensor(0x3818, iTemp1|0x40);	//Set normal

            if(OV5642MipiSensorStatus.PvMode==1)
                CamWriteCmosSensor(0x3621, 0x47|OV5642_MIPI_HORIZONTAL_BINNING);
            else
                CamWriteCmosSensor(0x3621, iTemp2 & 0xdf);
	    break;

        case IMAGE_SENSOR_MIRROR_H:

            CamWriteCmosSensor(0x3818, iTemp1|0x00);	//Set mirror   

            if(OV5642MipiSensorStatus.PvMode==1)
                CamWriteCmosSensor(0x3621, 0x67|OV5642_MIPI_HORIZONTAL_BINNING);
            else
                CamWriteCmosSensor(0x3621, iTemp2|0x20);				
            break;

        case IMAGE_SENSOR_MIRROR_V:
            CamWriteCmosSensor(0x3818, iTemp1 | 0x60);	//Set lip

            if(OV5642MipiSensorStatus.PvMode==1)
                CamWriteCmosSensor(0x3621, 0x47|OV5642_MIPI_HORIZONTAL_BINNING);
            else
                CamWriteCmosSensor(0x3621, iTemp2 & 0xdf);				
            break;
				
	case IMAGE_SENSOR_MIRROR_HV:

            CamWriteCmosSensor(0x3818, iTemp1|0x20);	//Set  mirror and fflip

            if(OV5642MipiSensorStatus.PvMode==1)
                CamWriteCmosSensor(0x3621, 0x67|OV5642_MIPI_HORIZONTAL_BINNING);
            else
                CamWriteCmosSensor(0x3621, iTemp2|0x20);			
            break;			
    }
}





static kal_uint16 OV5642MipiReg2Gain(const kal_uint8 iReg)
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

static kal_uint8 OV5642MipiGain2Reg(const kal_uint16 iGain)
{
    kal_uint8 iReg = 0x00;

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

/*************************************************************************
* FUNCTION
*	OV5642_MIPI_SetGain
*
* DESCRIPTION
*	This function is to set global gain to sensor.
*
* PARAMETERS
*   iGain : sensor global gain(base: 0x40)
*
* RETURNS
*	the actually gain set to sensor.
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint16 OV5642MipiSetGain(kal_uint16 iGain)
{
    const kal_uint16 iBaseGain = OV5642MipiReg2Gain(pOV5642MipiNvramSensorData->cct[OV5642_MIPI_INDEX_BASE_GAIN].para);
    const kal_uint16 iGain2Set = iBaseGain * iGain / BASEGAIN;
    const kal_uint8 iReg = OV5642MipiGain2Reg(iGain2Set);

	CamWriteCmosSensor(0x350B, iReg);	

#ifdef __OV5642_MIPI_DBG__
    kal_print_string_trace (MOD_ENG,TRACE_INFO, "[GAIN]Shut: %d, Gain: %d, YAvg: %x", OV5642MipiSensorStatus.ExposureLines, iGain, iReg);
#endif

    return OV5642MipiReg2Gain(iReg) * BASEGAIN / iBaseGain;
}

static kal_uint16 OV5642MipiReadGain(void)
{
    volatile signed char i;
    kal_uint16 sensor_gain=0,temp_reg_base=0;

    sensor_gain=(temp_reg_base*BASEGAIN)/8;
    return sensor_gain;
}  /* MT9P012MipiReadGain */

static void OV5642MipiFixVideoFrameRate(kal_uint16 framerate)
{

if (framerate>=300)
	OV5642MipiSensorStatus.VideoCurrentFrameRate=270;
else if(framerate>=240)
	OV5642MipiSensorStatus.VideoCurrentFrameRate=240;
else if(framerate>=200)
	OV5642MipiSensorStatus.VideoCurrentFrameRate=200;
else if(framerate>=150)
	OV5642MipiSensorStatus.VideoCurrentFrameRate=150;
else if(framerate>=120)
	OV5642MipiSensorStatus.VideoCurrentFrameRate=120;
else if(framerate>=100)
	OV5642MipiSensorStatus.VideoCurrentFrameRate=100;
else if(framerate>=75)
	OV5642MipiSensorStatus.VideoCurrentFrameRate=75;
else if(framerate>=50)
    OV5642MipiSensorStatus.VideoCurrentFrameRate=50;
else
	ASSERT(0);
	
    OV5642MipiSensorStatus.VideoMaxLineLength = (kal_uint16)((OV5642MipiSensorStatus.PrvPclk*1000000*10/OV5642MipiSensorStatus.VideoCurrentFrameRate)/(OV5642MipiSensorStatus.PvFrameLength));

    if (OV5642MipiSensorStatus.VideoMaxLineLength < OV5642MipiSensorStatus.PvLineLength)			
        OV5642MipiSensorStatus.VideoMaxLineLength = OV5642MipiSensorStatus.PvLineLength;

	if (OV5642MipiSensorStatus.VideoMaxLineLength>0x0fff)
            {
            CamWriteCmosSensor(0x3010,0x30); //20MHz pclk		
            OV5642MipiSensorStatus.PrvPclk=24;//MHz
            OV5642MipiSensorStatus.VideoMaxLineLength = (kal_uint16)((OV5642MipiSensorStatus.PrvPclk*1000000*10/OV5642MipiSensorStatus.VideoCurrentFrameRate)/(OV5642MipiSensorStatus.PvFrameLength));

            if (OV5642MipiSensorStatus.VideoMaxLineLength>0x0fff)
                {	 
                CamWriteCmosSensor(0x3010,0x70);
                OV5642MipiSensorStatus.PrvPclk=12;//MHz
                OV5642MipiSensorStatus.VideoMaxLineLength = (kal_uint16)((OV5642MipiSensorStatus.PrvPclk*1000000*10/OV5642MipiSensorStatus.VideoCurrentFrameRate)/(OV5642MipiSensorStatus.PvFrameLength));		
                }	
            }

    OV5642MipiSetDummy(OV5642MipiSensorStatus.VideoMaxLineLength,OV5642MipiSensorStatus.PvFrameLength);
    OV5642MipiSensorStatus.PvLineLength=OV5642MipiSensorStatus.VideoMaxLineLength;
}

/*************************************************************************
* FUNCTION
*	OV5642_MIPI_night_mode
*
* DESCRIPTION
*	This function night mode of OV5642_MIPI.
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
static void OV5642MipiNightMode(kal_bool enable)
{
}/* OV5642_MIPI_night_mode */

/*************************************************************************
* FUNCTION
*   OV5642_MIPI_SetFlashlight
*
* DESCRIPTION
*   OV5642_MIPI flash control function
*
* PARAMETERS
*   bEnable: KAL_TRUE -> enable flash light, otherwise disable flash light
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void OV5642MipiSetFlashlight(kal_bool bEnable)
{
    FlashlightPowerOn(OV5642MipiSensorIdx, bEnable);
}   /*  OV5642_MIPI_SetFlashlight    */

void OV5642MipiGetSensorAeInfo(IMAGE_SENSOR_AE_INFO_STRUCT *info_ptr) {
	info_ptr->DefaultPrevLinePixels = OV5642_MIPI_PV_PERIOD_PIXEL_NUMS;
    info_ptr->CurrentPrevLinePixels =OV5642_MIPI_PV_PERIOD_PIXEL_NUMS +OV5642MipiSensorStatus.PvDummyPixels;
	info_ptr->CurrentPclk=OV5642MipiSensorStatus.PrvPclk*1000000;
}

// for camera HAL integration
// write camera_para to sensor register
void OV5642MipiCameraParaToSensor(nvram_camera_para_struct *pCameraPara)
{
	kal_uint32	i;
	for(i=0; 0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr; i++)
	{
		CamWriteCmosSensor(pCameraPara->SENSOR.reg[i].addr, pCameraPara->SENSOR.reg[i].para);
    }

	for(i=ENGINEER_START_ADDR; 0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr; i++)
	{
		CamWriteCmosSensor(pCameraPara->SENSOR.reg[i].addr, pCameraPara->SENSOR.reg[i].para);
    }
	for(i=FACTORY_START_ADDR+1; i<5; i++)
	{
		CamWriteCmosSensor(pCameraPara->SENSOR.cct[i].addr, pCameraPara->SENSOR.cct[i].para);
    }

} /* OV5642MipiCameraParaToSensor() */

// update camera_para from sensor register
void OV5642MipiSensorToCameraPara(nvram_camera_para_struct *pCameraPara)
{
	kal_uint32	i;
	for(i=0; 0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr; i++)
	{
		pCameraPara->SENSOR.reg[i].para = CamReadCmosSensor(pCameraPara->SENSOR.reg[i].addr);
    }

	for(i=ENGINEER_START_ADDR; 0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr; i++)
	{
		pCameraPara->SENSOR.reg[i].para = CamReadCmosSensor(pCameraPara->SENSOR.reg[i].addr);
	}

} /* OV5642MipiSensorToCameraPara() */


void  OV5642MipiGetSensorGroupCount(kal_int32* sensor_count_ptr)
{

    *sensor_count_ptr=GROUP_TOTAL_NUMS;

    return;
}


void OV5642MipiGetSensorGrouinfo(kal_uint16 group_idx, kal_int8* group_name_ptr, kal_int32* item_count_ptr)
{
   switch (group_idx)
   {
    case PRE_GAIN:
        kal_sprintf((kal_char *)group_name_ptr, "CCT");
        *item_count_ptr = CCT_END_ADDR;
        break;
    case CMMCLK_CURRENT:
        kal_sprintf((kal_char *)group_name_ptr, "CMMCLK Current");
        *item_count_ptr = 1;
        break;
    case FRAME_RATE_LIMITATION:
        break;
    case REGISTER_EDITOR:
        kal_sprintf((kal_char *)group_name_ptr, "Register Editor");
        *item_count_ptr = 2;
        break;
    default:
        ASSERT(0);
    }
}

void OV5642MipiGetSensorItemInfo(kal_uint16 group_idx,kal_uint16 item_idx, CAL_CCT_SENSOR_ITEM_INFO_STRUCT* info_ptr)
{
	kal_uint16 temp_addr=0;
	
    switch (group_idx) {

	case PRE_GAIN:
		switch (item_idx) {
		case SENSOR_BASEGAIN:
			sprintf((char *) (info_ptr->ItemNamePtr), "SENSOR_BASEGAIN");
			info_ptr->ItemValue = 1000 * OV5642MipiReg2Gain(pOV5642MipiNvramSensorData->cct[SENSOR_BASEGAIN].para) / BASEGAIN;
			info_ptr->IsTrueFalse = KAL_FALSE;
			info_ptr->IsReadOnly = KAL_FALSE;
			info_ptr->IsNeedRestart = KAL_FALSE;
			info_ptr->Min = 1 * 1000;	// MIN. global gain = 1x gain
			info_ptr->Max = 32 * 1000; // MAX. global gain = 32x gain
			break;
	
		case PRE_GAIN_R_INDEX:
		case PRE_GAIN_Gr_INDEX:
		case PRE_GAIN_B_INDEX:
		case PRE_GAIN_Gb_INDEX:
			switch (item_idx)
			{
				case PRE_GAIN_R_INDEX:
				  temp_addr = 1;
				break;
				case PRE_GAIN_Gr_INDEX:
				  temp_addr = 2;
				break;
				case PRE_GAIN_B_INDEX:
				  temp_addr = 3;
				break;
				case PRE_GAIN_Gb_INDEX:
				temp_addr = 4;
				break;
				default:
				   ASSERT(0);		
			}
			
			if (item_idx == PRE_GAIN_R_INDEX) {
				sprintf((char *) (info_ptr->ItemNamePtr), "Pregain-R");
			}else if (item_idx == PRE_GAIN_Gr_INDEX) {
				sprintf((char *) (info_ptr->ItemNamePtr), "Pregain-Gr");
			}else if (item_idx == PRE_GAIN_B_INDEX) {
				sprintf((char *) (info_ptr->ItemNamePtr), "Pregain-B");
			}else if (item_idx == PRE_GAIN_Gb_INDEX) {
				sprintf((char *) (info_ptr->ItemNamePtr), "Pregain-Gr");
			}else {
				ASSERT(0);
			}
	
			// R, G, B gain = reg / 0x400
			info_ptr->ItemValue = pOV5642MipiNvramSensorData->cct[temp_addr].para * 1000 / 0x400;
			info_ptr->IsTrueFalse = KAL_FALSE;
			info_ptr->IsReadOnly = KAL_FALSE;
			info_ptr->IsNeedRestart = KAL_FALSE;
			info_ptr->Min = 1 * 1000;	// MIN. pre-gain
			info_ptr->Max = 0xfff * 1000 / 0x400; // MAX. pre-gain
			break;
		}
		break;
	
	case CMMCLK_CURRENT:
		switch (item_idx) {
		case 0:
			sprintf((char *) info_ptr->ItemNamePtr, "Drv Current[2,4,6,8]mA");
			switch (pOV5642MipiNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para) {
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
			}	// switch (pOV5642MipiNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para)
	
			info_ptr->IsTrueFalse = KAL_FALSE;
			info_ptr->IsReadOnly = KAL_FALSE;
			info_ptr->IsNeedRestart = KAL_TRUE;
			info_ptr->Min = 2;
			info_ptr->Max = 8;
			break;
	
		default:
			ASSERT(0);
		}	// switch (item_idx)
		break;
	
	case REGISTER_EDITOR:
		switch (item_idx) {
		case 0:
			sprintf((char *) info_ptr->ItemNamePtr, "REG Addr.");
			info_ptr->ItemValue = 0;
			info_ptr->IsTrueFalse = KAL_FALSE;
			info_ptr->IsReadOnly = KAL_FALSE;
			info_ptr->IsNeedRestart = KAL_FALSE;
			info_ptr->Min = 0x00;
			info_ptr->Max = 0xFF;
			break;
	
		case 1:
			sprintf((char *) info_ptr->ItemNamePtr, "REG Value");
			info_ptr->ItemValue = 0;
			info_ptr->IsTrueFalse = KAL_FALSE;
			info_ptr->IsReadOnly = KAL_FALSE;
			info_ptr->IsNeedRestart = KAL_FALSE;
			info_ptr->Min = 0x00;
			info_ptr->Max = 0xFF;
			break;
	
		default:
			ASSERT(0);
		}
		break;
	
	default:
		ASSERT(0);
    }
}

kal_bool OV5642MipiSetSensorItemInfo(kal_uint16 group_idx, kal_uint16 item_idx, kal_int32 ItemValue)
{
	kal_uint16 iTemp = 0x00;
	 static kal_uint32 iFAC_SENSOR_REG = 0x00;
	 kal_uint16 temp_addr=0;

    switch (group_idx)
    {
		case PRE_GAIN:
			switch (item_idx) {
			case SENSOR_BASEGAIN:
				if (ItemValue < 1 * 1000 || ItemValue >= 32 * 1000) {
					return KAL_FALSE;
				}
		
				iTemp = OV5642MipiGain2Reg(ItemValue * BASEGAIN / 1000);
				pOV5642MipiNvramSensorData->cct[SENSOR_BASEGAIN].para = iTemp;
				CamWriteCmosSensor(pOV5642MipiNvramSensorData->cct[SENSOR_BASEGAIN].addr, iTemp);
				break;
		
			case PRE_GAIN_R_INDEX:
			case PRE_GAIN_Gr_INDEX:
			case PRE_GAIN_B_INDEX:
			case PRE_GAIN_Gb_INDEX:
				switch (item_idx)
				{
					case PRE_GAIN_R_INDEX:
					  temp_addr = 1;
					break;
					case PRE_GAIN_Gr_INDEX:
					  temp_addr = 2;
					break;
					case PRE_GAIN_B_INDEX:
					  temp_addr = 3;
					  break;
					 case PRE_GAIN_Gb_INDEX:
						temp_addr = 4;
					break;
					default:
					   ASSERT(0);		
				}
				// 0x332B[3] must be 1 to enable manual R/G/B gain control
				if (ItemValue < 1 * 1000 || ItemValue > (kal_uint32) (1000 * 0xfff / 0x400)) {
					return KAL_FALSE;
				}
		
				iTemp = ItemValue * 0x400 / 1000;  // R, G, B gain = reg. / 0x40
				pOV5642MipiNvramSensorData->cct[temp_addr].para = iTemp;
				CamWriteCmosSensor((pOV5642MipiNvramSensorData->cct[item_idx].addr>>16)&0xffff, (iTemp>>8)&0xff);
				CamWriteCmosSensor(pOV5642MipiNvramSensorData->cct[item_idx].addr&0xffff, iTemp&0xff);
				
				break;
		
			default:
				ASSERT(0);	
			}
			break;
		
			case CMMCLK_CURRENT:
				switch (item_idx) {
				case 0:
					if (ItemValue == 2) {
						pOV5642MipiNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_2MA;
						SetIspDrivingCurrent(ISP_DRIVING_2MA);
					}else if (ItemValue == 3 || ItemValue == 4) {
						pOV5642MipiNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_4MA;
						SetIspDrivingCurrent(ISP_DRIVING_4MA);
					}else if (ItemValue == 5 || ItemValue == 6) {
						pOV5642MipiNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_6MA;
						SetIspDrivingCurrent(ISP_DRIVING_6MA);
					}else if (ItemValue == 7 || ItemValue == 8) {
						pOV5642MipiNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_8MA;
						SetIspDrivingCurrent(ISP_DRIVING_8MA);
					}else {
						return KAL_FALSE;
					}
					break;
		
				default:
					ASSERT(0);
				}	// switch (CMMCLK_CURRENT)
			break;
		
		case REGISTER_EDITOR:
			switch (item_idx)	{
			case 0:
				if (ItemValue < 0 || ItemValue > 0xFFFF) {
					return KAL_FALSE;
				}
				iFAC_SENSOR_REG = ItemValue;
				break;
		
			case 1:
				if (ItemValue < 0 || ItemValue > 0xFFFF) {
					return KAL_FALSE;
				}
				CamWriteCmosSensor(iFAC_SENSOR_REG, ItemValue);
				break;
		
			default:
				ASSERT(0);
			}	// switch (iItemIndex)
			break;
		
			default:
			   ASSERT(0);

    }

    return KAL_TRUE;
}


void OV5642MipiGetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT pSensorInfo)
{
    pSensorInfo->SensorId=OV5642_MIPI_SENSOR_ID;
    pSensorInfo->SensorIf=IMAGE_SENSOR_IF_MIPI;
    pSensorInfo->PreviewNormalDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_B_FIRST;
    pSensorInfo->PreviewHMirrorDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_B_FIRST;
    pSensorInfo->PreviewVMirrorDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gr_FIRST;
    pSensorInfo->PreviewHVMirrorDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gr_FIRST;    
    pSensorInfo->CaptureDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_B_FIRST;
    pSensorInfo->PixelClkInv=KAL_FALSE;
    pSensorInfo->PixelClkPolarity=POLARITY_LOW;
    pSensorInfo->HsyncPolarity=POLARITY_LOW;
    pSensorInfo->VsyncPolarity=POLARITY_LOW;
    pSensorInfo->PreviewMclkFreq = 26000000;
    pSensorInfo->CaptureMclkFreq = 26000000;
    pSensorInfo->VideoMclkFreq = 26000000;
    pSensorInfo->PreviewWidth=OV5642_MIPI_IMAGE_SENSOR_PV_WIDTH;
    pSensorInfo->PreviewHeight=OV5642_MIPI_IMAGE_SENSOR_PV_HEIGHT;
    pSensorInfo->FullWidth=OV5642_MIPI_IMAGE_SENSOR_FULL_WIDTH;
    pSensorInfo->FullHeight=OV5642_MIPI_IMAGE_SENSOR_FULL_HEIGHT;
    pSensorInfo->SensorAfSupport=KAL_FALSE;
    pSensorInfo->SensorFlashSupport=KAL_FALSE;
} /* OV5642MipiGetSensorInfo() */


void OV5642MipiGetMipiInfo(P_IMAGE_SENSOR_MIPI_PARA_IN_STRUCT pParaIn, P_IMAGE_SENSOR_MIPI_PARA_OUT_STRUCT pParaOut)
{
    if((CAL_SCENARIO_CAMERA_PREVIEW == pParaIn->ScenarioMode)
        ||(CAL_SCENARIO_WEBCAM_PREVIEW == pParaIn->ScenarioMode)
        ||(CAL_SCENARIO_CCT_CAMERA_PREVIEW == pParaIn->ScenarioMode))
    {
        pParaOut->MipiLaneNum = 1;
        pParaOut->LowPwr2HighSpeedDelayCount = 25;
    }
    else if ((CAL_SCENARIO_CAMERA_STILL_CAPTURE ==pParaIn->ScenarioMode) 
        ||(CAL_SCENARIO_CCT_CAMERA_CAPTURE_JPEG ==pParaIn->ScenarioMode) 
        ||(CAL_SCENARIO_CCT_CAMERA_CAPTURE_RAW ==pParaIn->ScenarioMode))
    {

    if ((pParaIn->TargetWidth<=OV5642_MIPI_IMAGE_SENSOR_PV_WIDTH)
        &&(pParaIn->TargetHeight<=OV5642_MIPI_IMAGE_SENSOR_PV_HEIGHT))
        {
        //#ifdef CAM_OFFLINE_CAPTURE
		if(CAL_RAW_CAPTURE_MODE_OFFLINE==pParaIn->CaptureScenario)
			{
            pParaOut->MipiLaneNum = 1;
            pParaOut->LowPwr2HighSpeedDelayCount = 10;
			}
        else
        	{
            pParaOut->MipiLaneNum = 1;
            pParaOut->LowPwr2HighSpeedDelayCount = 25;
        	}	
        }
    else
        {
        //#ifdef CAM_OFFLINE_CAPTURE
		if(CAL_RAW_CAPTURE_MODE_OFFLINE==pParaIn->CaptureScenario)
			{
            pParaOut->MipiLaneNum = 1;
            pParaOut->LowPwr2HighSpeedDelayCount = 10;
			}
        //#elif CAM_OTF_CAPTURE
		else if (CAL_RAW_CAPTURE_MODE_OTF==pParaIn->CaptureScenario)
		    {
            if (100==pParaIn->DigitalZoomFactor) /* 1x capture */
                {
                pParaOut->MipiLaneNum = 1;
                pParaOut->LowPwr2HighSpeedDelayCount = 25;
                }
            else if(pParaIn->DigitalZoomFactor<200)/* 1x~2x capture */
                {
                pParaOut->MipiLaneNum = 1;
                pParaOut->LowPwr2HighSpeedDelayCount = 25;
                }
            else if(pParaIn->DigitalZoomFactor<=400)/* 2x~4x capture */
                {
                pParaOut->MipiLaneNum = 1;
                pParaOut->LowPwr2HighSpeedDelayCount = 40;
                }
            else /* 4x~8x capture */
                {
                pParaOut->MipiLaneNum = 1;
                pParaOut->LowPwr2HighSpeedDelayCount = 70;
                }
			}
        else //CAM_STANDARD_CAPTURE
        	{
                if (pParaIn->DigitalZoomFactor>100)
                    {
                    pParaOut->MipiLaneNum = 1;
                    pParaOut->LowPwr2HighSpeedDelayCount = 10;
                    }
                else
                    {
                    pParaOut->MipiLaneNum = 1;
                    pParaOut->LowPwr2HighSpeedDelayCount = 25;
                    }

        	}
        }
    }
    else if((CAL_SCENARIO_VIDEO ==pParaIn->ScenarioMode))
    {
        switch (OV5642MipiSensorStatus.PrvPclk)
        {
            case 48:
                pParaOut->MipiLaneNum = 1;
                pParaOut->LowPwr2HighSpeedDelayCount = 25;
                break;	
            case 24:	
                pParaOut->MipiLaneNum = 1;
                pParaOut->LowPwr2HighSpeedDelayCount = 40;
                break;
            case 12:
                pParaOut->MipiLaneNum = 1;
                pParaOut->LowPwr2HighSpeedDelayCount = 70;
            break;
            default:
		ASSERT(0);
            break; 
        }
    }
    
}


static kal_uint16 OV5642MipiPowerOn(void)
{
		volatile kal_uint32 iI;
		kal_uint32 sensor_id=0;
		
		CisModulePowerOn(OV5642MipiSensorIdx, KAL_TRUE);
		CameraSccbOpen(CAMERA_SCCB_SENSOR, OV5642_MIPI_WRITE_ID, CAMERA_SCCB_16BIT, CAMERA_SCCB_8BIT, 320);
		kal_sleep_task(2);	/* delay for power stable */

		CamPdnPinCtrl(OV5642MipiSensorIdx, 0);
				
		/* Reset the sensor */
		CamRstPinCtrl(OV5642MipiSensorIdx, 1);
		kal_sleep_task(1);
		CamRstPinCtrl(OV5642MipiSensorIdx, 0);
		kal_sleep_task(1);
		CamRstPinCtrl(OV5642MipiSensorIdx, 1);
		/* delay for stable sensor */  
		kal_sleep_task(8);	// at least one frame delay time needed after HW reset
				
		// check if sensor ID correct
		for (iI=0;iI<10;iI++)
			{
			sensor_id = ((CamReadCmosSensor(0x300A) << 8) | CamReadCmosSensor(0x300B));
	
        #ifdef __OV5642_MIPI_DBG__
				kal_print_string_trace(MOD_ENG,TRACE_INFO,"SENSOR ID = %x",sensor_id);
        #endif
	
			if (sensor_id==OV5642_MIPI_SENSOR_ID)
				break;
			}
	
		return sensor_id;

} /* OV5642MipiPowerOn() */

kal_uint32 OV5642MipiDetectSensorId(void)
{
  MM_ERROR_CODE_ENUM OV5642MipiSensorClose(void);
  kal_uint16 OV5642MipiPowerOn();
  kal_uint16 sensorId, AnotherSensorIdx;
  kal_int8 i, j;

  if (IMAGE_SENSOR_MAIN == OV5642MipiSensorIdx)
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
      sensorId = OV5642MipiPowerOn();
      OV5642MipiSensorClose();
#ifdef __OV5642_MIPI_DBG__
      kal_wap_trace(MOD_ENG,TRACE_INFO,"OV5642Mipi DetectSensorId:%x",sensorId);
#endif
      if (OV5642_MIPI_SENSOR_ID == sensorId)
      {
        return OV5642_MIPI_SENSOR_ID;
      }
    }
  }
  return MM_ERROR_SENSOR_READ_ID_FAIL;
}   /* OV5642MipiDetectSensorId() */

MM_ERROR_CODE_ENUM OV5642MipiSensorOpen(void)
{
    IspSetInterruptTriggerDelayLines(4);	// 0: VD INT, others: TG INT & start line

    if (OV5642MipiPowerOn()!= OV5642_MIPI_SENSOR_ID)
        return MM_ERROR_SENSOR_READ_ID_FAIL;

 	OV5642MipiSensorStatus.BackupExposureLines=400;
	
	OV5642MiPiInitialSetting();
    return MM_ERROR_NONE;
} /* OV5642MipiSensorOpen() */

static void OV5642MipiPreview(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{
	
    OV5642MipiSensorStatus.PvMode = KAL_TRUE;
	
    OV5642MipiSensorStatus.PvDummyPixels=0;
    OV5642MipiSensorStatus.PvDummyLines=0;
    
    OV5642MipiSetXGA(OV5642_MIPI_8BIT_RAW);
    OV5642MipiSensorStatus.PrvPclk=48;//MHz

    OV5642MipiSetMirrorFlip(pParaIn->ImageMirror);

    OV5642MipiSensorStatus.PvLineLength= OV5642_MIPI_PV_PERIOD_PIXEL_NUMS + OV5642MipiSensorStatus.PvDummyPixels;
    OV5642MipiSensorStatus.PvFrameLength= OV5642_MIPI_PV_PERIOD_LINE_NUMS + OV5642MipiSensorStatus.PvDummyLines;

    OV5642MipiSetDummy(OV5642MipiSensorStatus.PvLineLength, OV5642MipiSensorStatus.PvFrameLength);

    pParaOut->GrabStartX = 0;
    pParaOut->GrabStartY = 21;
    pParaOut->ExposureWindowWidth = OV5642_MIPI_IMAGE_SENSOR_PV_WIDTH;
    pParaOut->ExposureWindowHeight = OV5642_MIPI_IMAGE_SENSOR_PV_HEIGHT;
   
    OV5642MipiWriteShutter(OV5642MipiSensorStatus.BackupExposureLines);

}/* OV5642MipiPreview */

void OV5642MipiGetPreviewFlashlightInfo(P_FLASHLIGHT_PREVIEW_PARA_STURCT pPreviewInfo)
{
    pPreviewInfo->pixels = OV5642_MIPI_PV_PERIOD_PIXEL_NUMS;
    pPreviewInfo->lines = OV5642_MIPI_IMAGE_SENSOR_PV_HEIGHT;
    pPreviewInfo->frame_lines = OV5642_MIPI_PV_PERIOD_LINE_NUMS;
     
}


static void OV5642MipiCapture(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{
    volatile kal_uint16 shutter=OV5642MipiSensorStatus.ExposureLines;
    float ShutterTemp=OV5642MipiSensorStatus.ExposureLines;
    
    OV5642MipiSensorStatus.BackupExposureLines = OV5642MipiSensorStatus.ExposureLines;

    if(KAL_TRUE==pParaIn->EnableShutterTransfer)
    {
        shutter=pParaIn->CaptureShutter;
        ShutterTemp=(float)pParaIn->CaptureShutter;
    }

    if ((pParaIn->ImageTargetWidth<=OV5642_MIPI_IMAGE_SENSOR_PV_WIDTH)&&
        (pParaIn->ImageTargetHeight<=OV5642_MIPI_IMAGE_SENSOR_PV_HEIGHT))
        {
        OV5642MipiSensorStatus.PvMode = KAL_TRUE;

        OV5642MipiSetXGA(OV5642_MIPI_10BIT_RAW);
		
        OV5642MipiSensorStatus.CapPclk=48;//MHz

        //#ifdef CAM_OTF_CAPTURE
        if (CAL_RAW_CAPTURE_MODE_OTF==pParaIn->CaptureScenario)
        	{
            OV5642MipiSensorStatus.CapDummyLines = 0;

            if (100==pParaIn->ZoomFactor) /* 1x capture */
                OV5642MipiSensorStatus.CapDummyPixels = 0;
            else if(pParaIn->ZoomFactor<200)/* 1x~2x capture */
                OV5642MipiSensorStatus.CapDummyPixels = 200;
            else if(pParaIn->ZoomFactor<=400)/* 2x~4x capture */
                OV5642MipiSensorStatus.CapDummyPixels = 1500;
            else /* 4x~8x capture */
                OV5642MipiSensorStatus.CapDummyPixels = 2000;
        	}

        //#elif CAM_OFFLINE_CAPTURE
        else if(CAL_RAW_CAPTURE_MODE_OFFLINE==pParaIn->CaptureScenario)
        	{
            OV5642MipiSensorStatus.CapPclk=96;
            CamWriteCmosSensor(0x3010,0x00);//-> to 96MHz
            OV5642MipiSensorStatus.CapDummyPixels=1400;
            OV5642MipiSensorStatus.CapDummyLines=0;
        	}
        //#else
        else
			{
            OV5642MipiSensorStatus.CapDummyPixels=0;
            OV5642MipiSensorStatus.CapDummyLines=0;
        	}
        //#endif

            OV5642MipiSensorStatus.CapLineLength=OV5642_MIPI_PV_PERIOD_PIXEL_NUMS+OV5642MipiSensorStatus.CapDummyPixels;
            OV5642MipiSensorStatus.CapFrameLength=OV5642_MIPI_PV_PERIOD_LINE_NUMS+OV5642MipiSensorStatus.CapDummyLines;
			
            pParaOut->GrabStartX = 1;
            pParaOut->GrabStartY = 21;
            pParaOut->ExposureWindowWidth = OV5642_MIPI_IMAGE_SENSOR_PV_WIDTH;
            pParaOut->ExposureWindowHeight = OV5642_MIPI_IMAGE_SENSOR_PV_HEIGHT;
        }
    
    else  //>1.3M
        {
        OV5642MipiSensorStatus.PvMode = KAL_FALSE;

        OV5642MipiSetQSXGA(OV5642_MIPI_10BIT_RAW);
        OV5642MipiSetDenoise();

        //#ifdef CAM_OFFLINE_CAPTURE
       	if(CAL_RAW_CAPTURE_MODE_OFFLINE==pParaIn->CaptureScenario)
        	{		
            OV5642MipiSensorStatus.CapPclk=96;//MHz		
				
            OV5642MipiSensorStatus.CapDummyPixels=0;
            OV5642MipiSensorStatus.CapDummyLines=0;
       		}
        //#elif CAM_OTF_CAPTURE
        else if (CAL_RAW_CAPTURE_MODE_OTF==pParaIn->CaptureScenario)
        	{
            OV5642MipiSensorStatus.CapDummyLines=0;

        /* Check Zoom Factor */
            if (100==pParaIn->ZoomFactor)  //1x capture
            	{
                CamWriteCmosSensor(0x3010,0x10);
                OV5642MipiSensorStatus.CapPclk=48;//MHz
				 
                OV5642MipiSensorStatus.CapDummyPixels=0;
            	}
            else if(pParaIn->ZoomFactor<200)//1x~2x capture
            	{
                CamWriteCmosSensor(0x3010,0x10);
                OV5642MipiSensorStatus.CapPclk=48;//MHz	

                OV5642MipiSensorStatus.CapDummyPixels=OV5642MipiSensorStatus.CapPclk*1000000/OV5642_MIPI_FULL_PERIOD_LINE_NUMS
                                                        /OV5642_MIPI_2X_ZOOM_IN_CAPTURE_FRAME-OV5642_MIPI_FULL_PERIOD_PIXEL_NUMS;
            	}
            else if(pParaIn->ZoomFactor<=400)//2x~4x capture
            	{
                CamWriteCmosSensor(0x3010,0x30);
                OV5642MipiSensorStatus.CapPclk=24;//MHz

                OV5642MipiSensorStatus.CapDummyPixels=OV5642MipiSensorStatus.CapPclk*1000000/OV5642_MIPI_FULL_PERIOD_LINE_NUMS
                                                        /OV5642_MIPI_4X_ZOOM_IN_CAPTURE_FRAME-OV5642_MIPI_FULL_PERIOD_PIXEL_NUMS;
                } 
            else //4x~8x capture
            	{
                CamWriteCmosSensor(0x3010,0x70);
                OV5642MipiSensorStatus.CapPclk=12;//MHz
   
                OV5642MipiSensorStatus.CapDummyPixels=(OV5642MipiSensorStatus.CapPclk*1000000/OV5642_MIPI_FULL_PERIOD_LINE_NUMS
                                                        /OV5642_MIPI_4X_ZOOM_IN_CAPTURE_FRAME)*2-OV5642_MIPI_FULL_PERIOD_PIXEL_NUMS;

                }   
        	}
     //#else ////CAM_STANDARD_CAPTURE
     else
        {
		 if (pParaIn->ZoomFactor>100)
             {
             OV5642MipiSensorStatus.CapPclk=96;//MHz
				
             OV5642MipiSensorStatus.CapDummyPixels = 0;
             OV5642MipiSensorStatus.CapDummyLines=0;
             }
         else
             {	
             CamWriteCmosSensor(0x3010,0x10);				
             OV5642MipiSensorStatus.CapPclk=48;//MHz				

             OV5642MipiSensorStatus.CapDummyPixels=0;
             OV5642MipiSensorStatus.CapDummyLines=0;
             }
     	}
     //#endif

	OV5642MipiSensorStatus.CapLineLength=OV5642_MIPI_FULL_PERIOD_PIXEL_NUMS+OV5642MipiSensorStatus.CapDummyPixels;
	OV5642MipiSensorStatus.CapFrameLength=OV5642_MIPI_FULL_PERIOD_LINE_NUMS+OV5642MipiSensorStatus.CapDummyLines;

        pParaOut->GrabStartX = 1;
        pParaOut->GrabStartY = 21;
        pParaOut->ExposureWindowWidth = OV5642_MIPI_IMAGE_SENSOR_FULL_WIDTH;
        pParaOut->ExposureWindowHeight = OV5642_MIPI_IMAGE_SENSOR_FULL_HEIGHT;
    }

    OV5642MipiSetMirrorFlip(pParaIn->ImageMirror);

    OV5642MipiSetDummy(OV5642MipiSensorStatus.CapLineLength,OV5642MipiSensorStatus.CapFrameLength);

    if (OV5642MipiSensorStatus.PvMode==KAL_FALSE)
    	{
        if (ShutterTemp<=10)
            ShutterTemp=ShutterTemp+1;
        else
            ShutterTemp=ShutterTemp*107/100;
		
        ShutterTemp=(ShutterTemp*OV5642MipiSensorStatus.CapPclk/OV5642MipiSensorStatus.PrvPclk)*OV5642MipiSensorStatus.PvLineLength
                     /OV5642MipiSensorStatus.CapLineLength;

        shutter=ShutterTemp +0.5;
    	}
    else //VGA capture
        {
        //#ifdef CAM_OFFLINE_CAPTURE
        if(CAL_RAW_CAPTURE_MODE_OFFLINE==pParaIn->CaptureScenario)
        	{        
            ShutterTemp=(ShutterTemp*OV5642MipiSensorStatus.CapPclk/OV5642MipiSensorStatus.PrvPclk)*OV5642MipiSensorStatus.PvLineLength
                          /OV5642MipiSensorStatus.CapLineLength;

            shutter=ShutterTemp +0.5;
            }
        //#endif
        }

    if(shutter<1)
        shutter=1;

    OV5642MipiWriteShutter(shutter);

} /* OV5642MipiCapture() */

void OV5642MipiGetCaptureFlashlightInfo(P_FLASHLIGHT_CAPTURE_SENSOR_PARA_IN_STRUCT pParaIn, P_FLASHLIGHT_CAPTURE_PARA_STRUCT pCaptureInfo)
{
    if(KAL_TRUE==OV5642MipiSensorStatus.PvMode)
    {
        //#ifdef CAM_OFFLINE_CAPTURE
        if(CAL_RAW_CAPTURE_MODE_OFFLINE==pParaIn->CaptureScenario)
            pCaptureInfo->default_pclk = 96000000;
        else
            pCaptureInfo->default_pclk = 48000000;
    }
    else
    {
        //#ifdef CAM_OFFLINE_CAPTURE
        if(CAL_RAW_CAPTURE_MODE_OFFLINE==pParaIn->CaptureScenario)
            pCaptureInfo->default_pclk = 96000000;
		//#elif CAM_OTF_CAPTURE
		else if (CAL_RAW_CAPTURE_MODE_OTF==pParaIn->CaptureScenario)
			{
            if(pParaIn->DigitalZoomFactor<200)
                pCaptureInfo->default_pclk = 48000000;
            else if(pParaIn->DigitalZoomFactor<=400)
                pCaptureInfo->default_pclk = 24000000;
            else
                pCaptureInfo->default_pclk = 12000000;
			}
       //#else//CAM_STANDARD_CAPTURE
       else
       	    {
            if(pParaIn->DigitalZoomFactor>100)
                pCaptureInfo->default_pclk = 96000000;
            else	
                pCaptureInfo->default_pclk = 48000000;
       	    }
	   //#endif
				
    }
    pCaptureInfo->pixels = OV5642MipiSensorStatus.CapLineLength;
    pCaptureInfo->frame_lines = OV5642MipiSensorStatus.CapFrameLength;
    pCaptureInfo->lines = OV5642_MIPI_IMAGE_SENSOR_FULL_HEIGHT;
    pCaptureInfo->shutter = OV5642MipiSensorStatus.CapShutter;
    //Shutter = flashlight_sensor_capture_config(&flashlight_capture_para, pParaIn);    
    
}

static void OV5642MipiVideo(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{	
    OV5642MipiSensorStatus.PvMode = KAL_TRUE;
	
    OV5642MipiSensorStatus.PvDummyPixels=0;
    OV5642MipiSensorStatus.PvDummyLines=0;
    
    OV5642MipiSetXGA(OV5642_MIPI_8BIT_RAW);
    OV5642MipiSensorStatus.PrvPclk=48;//MHz

    OV5642MipiSensorStatus.PvDummyPixels=0;
	OV5642MipiSensorStatus.PvDummyLines=0;
    OV5642MipiSensorStatus.PvLineLength= OV5642_MIPI_PV_PERIOD_PIXEL_NUMS + OV5642MipiSensorStatus.PvDummyPixels;
    OV5642MipiSensorStatus.PvFrameLength= OV5642_MIPI_PV_PERIOD_LINE_NUMS + OV5642MipiSensorStatus.PvDummyLines;

	OV5642MipiFixVideoFrameRate(pParaIn->MaxVideoFrameRate);

    OV5642MipiSetMirrorFlip(pParaIn->ImageMirror);

    pParaOut->GrabStartX = 0;
    pParaOut->GrabStartY = 9;
    pParaOut->ExposureWindowWidth = OV5642_MIPI_IMAGE_SENSOR_PV_WIDTH;
    pParaOut->ExposureWindowHeight = OV5642_MIPI_IMAGE_SENSOR_PV_HEIGHT;
   
    OV5642MipiWriteShutter(OV5642MipiSensorStatus.BackupExposureLines);

}/* OV5642MipiPreview */

MM_ERROR_CODE_ENUM OV5642MipiBinningInfo(P_CAL_FEATURE_CTRL_STRUCT pFeatureParaIn,
                                        P_CAL_FEATURE_CTRL_STRUCT pFeatureParaOut,
                                        kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{
    P_CAL_FEATURE_CAMERA_BINNING_INFO_STRUCT pBinningInfo=pFeatureParaOut->FeatureInfo.FeatureStructured.pBinningInfo;
    kal_uint8 i;

    switch (pFeatureParaIn->FeatureCtrlCode)
    {
        case CAL_FEATURE_QUERY_OPERATION:
            for (i=CAM_ISO_AUTO;i<=CAM_ISO_400;i++)
            {
                pBinningInfo->IsoBinningInfo[i].MaxResolution=CAM_IMAGE_SIZE_5M;
                pBinningInfo->IsoBinningInfo[i].IsoSupported=KAL_TRUE;
                pBinningInfo->IsoBinningInfo[i].BinningEnable=KAL_FALSE;
            }
            for (;i<=CAM_ISO_1600;i++)
            {
                pBinningInfo->IsoBinningInfo[i].MaxResolution=CAM_IMAGE_SIZE_1M;
                pBinningInfo->IsoBinningInfo[i].IsoSupported=KAL_TRUE;
                pBinningInfo->IsoBinningInfo[i].BinningEnable=KAL_TRUE;
            }
        break;
    }
}   /* OV5642MipiBinningInfo() */

MM_ERROR_CODE_ENUM OV5642MipiStillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT pFeatureParaIn,
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
            pStillCaptureSize->ItemCount = 7;
            pStillCaptureSize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
            pStillCaptureSize->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
            pStillCaptureSize->SupportItem[2] = CAM_IMAGE_SIZE_1M;
            pStillCaptureSize->SupportItem[3] = CAM_IMAGE_SIZE_2M;
            pStillCaptureSize->SupportItem[4] = CAM_IMAGE_SIZE_3M;
            pStillCaptureSize->SupportItem[5] = CAM_IMAGE_SIZE_4M;
            pStillCaptureSize->SupportItem[6] = CAM_IMAGE_SIZE_5M;
        break;
    }

    return MM_ERROR_NONE;
}   /* OV5642MipiStillCaptureSize() */

void OV5642MipiInitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT pInitOperPara)
{
	pInitOperPara->CaptureDelayFrame = 2;			/* wait stable frame when sensor change mode (pre to cap) */
	pInitOperPara->PreviewDelayFrame = 2;			/* wait stable frame when sensor change mode (cap to pre) */
	pInitOperPara->PreviewDisplayWaitFrame = 3;	/* wait stable frame when sensor change mode (cap to pre) */
	pInitOperPara->AeCalDelayFrame = 0;			/* The frame of calculation default 0 */
	pInitOperPara->AeShutDelayFrame = 0;			/* The frame of setting shutter default 0 for TG int */
	pInitOperPara->AeSensorGainDelayFrame = 2;	/* The frame of setting sensor gain */
	pInitOperPara->AeIspGainDelayFrame = 2;		/* The frame of setting gain */
	pInitOperPara->AeCalPeriod = 3;				/* AE AWB calculation period */
	#if(defined(LED_FLASHLIGHT_SUPPORT))
       	pInitOperPara->FlashlightMode = FLASHLIGHT_LED_CONSTANT;
	#elif(defined(LED_ONOFF_SUPPORT))
       	pInitOperPara->FlashlightMode = FLASHLIGHT_LED_ONOFF;
	#else
       	pInitOperPara->FlashlightMode = FLASHLIGHT_NONE;
	#endif
  pInitOperPara->FlashlightDeltaMainLum = 65;    // 1.015*64(1.015X)
} /* OV5642MipiInitOperationPara() */

void OV5642MipiDscSupportInfo(P_IMAGE_SENSOR_GET_DSC_SUPPORT_INFO_STRUCT pDscSupportInfo)
{
    kal_mem_cpy(pDscSupportInfo, &OV5642_MIPI_dsc_support_info, sizeof(camcorder_info_struct));
} /* OV5642MipiDscSupportInfo() */


MM_ERROR_CODE_ENUM OV5642MipiSensorFeatureCtrl(kal_uint32 FeatureId,
                                                void* pFeatureParaIn, void* pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;

    if ((FeatureId>=CAL_FEATURE_WEBCAM_BEGIN)&&
        (FeatureId<=CAL_FEATURE_WEBCAM_END))
    {
        ErrorCode=OV5642MipiWebcamFeatureCtrl(FeatureId, pFeatureParaIn, pFeatureParaOut,
                                               FeatureParaOutLen, pRealFeatureParaOutLen);
        return ErrorCode;
    }
    // for the features that not support in the sensor, then it is not necessary to implement it.
    switch (FeatureId)
    {
        /*get*/
        case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
            OV5642MipiGetSensorInfo((P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT) pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_MIPI_INFO:
            OV5642MipiGetMipiInfo((P_IMAGE_SENSOR_MIPI_PARA_IN_STRUCT)pFeatureParaIn,(P_IMAGE_SENSOR_MIPI_PARA_OUT_STRUCT) pFeatureParaOut);
            FeatureParaOutLen = sizeof(P_IMAGE_SENSOR_MIPI_PARA_OUT_STRUCT);
            *pRealFeatureParaOutLen = sizeof(P_IMAGE_SENSOR_MIPI_PARA_OUT_STRUCT);            
        break;        
        case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
            ((P_IMAGE_SENSOR_COMM_DATA_STRUCT) pFeatureParaOut)->FeatureValue=OV5642MipiDetectSensorId();
        break;
        case IMAGE_SENSOR_FEATURE_GET_PREVIEW_FLASHLIGHT_INFO:
            OV5642MipiGetPreviewFlashlightInfo((P_FLASHLIGHT_PREVIEW_PARA_STURCT)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_CAPTURE_FLASHLIGHT_INFO:
            OV5642MipiGetCaptureFlashlightInfo((P_FLASHLIGHT_CAPTURE_SENSOR_PARA_IN_STRUCT)pFeatureParaIn, (P_FLASHLIGHT_CAPTURE_PARA_STRUCT)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_AE_INFO:
            OV5642MipiGetSensorAeInfo((P_IMAGE_SENSOR_AE_INFO_STRUCT)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_AE_LUT:
            OV5642MipiGetAeLut((P_AE_LUT_INFO_STRUCT) pFeatureParaIn, (P_IMAGE_SENSOR_AE_LUT_STRUCT)pFeatureParaOut,
                                FeatureParaOutLen, pRealFeatureParaOutLen);
        break;
        case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
            ((P_IMAGE_SENSOR_COMM_DATA_STRUCT) pFeatureParaOut)->FeatureValue=OV5642MipiSensorStatus.VideoCurrentFrameRate;
        break;
        case IMAGE_SENSOR_FEATURE_GET_SHADING_TABLE:
            ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        break;
        case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
            OV5642MipiInitOperationPara((P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_DSC_SUPPORT_INFO:
            OV5642MipiDscSupportInfo((P_IMAGE_SENSOR_GET_DSC_SUPPORT_INFO_STRUCT)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
            pOV5642MipiNvramSensorData = &(((nvram_camera_para_struct *) pFeatureParaIn)->SENSOR);
        break;
        case IMAGE_SENSOR_FEATURE_GET_GAIN:
            ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaOut)->FeatureValue=OV5642MipiReadGain();
        break;
        case IMAGE_SENSOR_FEATURE_GET_ENG_INFO:
            ((P_SENSOR_INFO_STRUCT)pFeatureParaOut)->id = 148;
            ((P_SENSOR_INFO_STRUCT)pFeatureParaOut)->type = CMOS_SENSOR;
        break;
        case IMAGE_SENSOR_FEATURE_GET_CCT_GROUP_COUNT:
            OV5642MipiGetSensorGroupCount((kal_int32*)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_CCT_GROUP_INFO:
            OV5642MipiGetSensorGrouinfo(((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaIn)->GroupNamePtr, &((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaOut)->ItemCount);
        break;  
        case IMAGE_SENSOR_FEATURE_GET_CCT_ITEM_INFO:
            OV5642MipiGetSensorItemInfo(((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemIdx, (P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaOut);
        break;
		
		/*set*/
        case IMAGE_SENSOR_FEATURE_SET_ESHUTTER:
            OV5642MipiSetShutter(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
        break;
        case IMAGE_SENSOR_FEATURE_SET_GAIN:
            OV5642MipiSetGain(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
        break;
        case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
            OV5642MipiSensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT) pFeatureParaIn)->ImageSensorIdx;
        break;
	    case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
            CamPdnPinCtrl(OV5642MipiSensorIdx, 1);
	        CamRstPinCtrl(OV5642MipiSensorIdx, 0);
        break;
        case IMAGE_SENSOR_FEATURE_SET_CCT_ITEM_INFO:
            OV5642MipiSetSensorItemInfo(((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemIdx, ((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemValue);
        break;		
		
        case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE:
            OV5642MipiNightMode(((P_IMAGE_SENSOR_COMM_CTRL_STRUCT)pFeatureParaIn)->FeatureEnable);
        break;
        case IMAGE_SENSOR_FEATURE_CTRL_FLASHLIGHT:
            OV5642MipiSetFlashlight(((P_IMAGE_SENSOR_COMM_CTRL_STRUCT)pFeatureParaIn)->FeatureEnable);
        break;

        case CAL_FEATURE_CAMERA_BINNING_INFO:
            ErrorCode=OV5642MipiBinningInfo((P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaIn,
                                             (P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaOut, FeatureParaOutLen, pRealFeatureParaOutLen);
        break;
        // customized by customer
        case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
            ErrorCode=OV5642MipiStillCaptureSize((P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaIn,
                                         (P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaOut, FeatureParaOutLen, pRealFeatureParaOutLen);
        break;
        // for YUV sensor sample code
        // the following are for YUV sensor only
        case CAL_FEATURE_CAMERA_SHARPNESS:
        case CAL_FEATURE_CAMERA_EV_VALUE:
        case CAL_FEATURE_CAMERA_BANDING_FREQ:
        case CAL_FEATURE_CAMERA_WB:
        case CAL_FEATURE_CAMERA_HUE:
        case CAL_FEATURE_CAMERA_BRIGHTNESS:
        case CAL_FEATURE_CAMERA_CONTRAST:
        case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
        case CAL_FEATURE_CAMERA_SATURATION:
        break;
        case IMAGE_SENSOR_FEATURE_YUV_3A_CTRL:
        case CAL_FEATURE_CAMERA_FLASH_MODE:
            // These features are supported in YUV sensor only.
            // Put here just for notifying DD colleagues. Should be removed later for OV5642. PC Huang 20100903
            ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        break;
        // the above are for YUV sensor only
        case CAL_FEATURE_CCT_OP_CAMERA_PARA_TO_SENSOR:
            OV5642MipiCameraParaToSensor(pFeatureParaIn);
        break;
        case CAL_FEATURE_CCT_OP_SENSOR_TO_CAMERA_PARA:
            OV5642MipiSensorToCameraPara(pFeatureParaOut);
        break;
        
        default:
            ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        break;
    }
    return ErrorCode;
} /* OV5642MipiSensorFeatureCtrl() */

MM_ERROR_CODE_ENUM OV5642MipiSensorCtrl(CAL_SCENARIO_ENUM ScenarioId, void *pParaIn,
                                         void *pParaOut, kal_uint16 ParaOutLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;

    switch (ScenarioId)
    {
        case CAL_SCENARIO_CAMERA_PREVIEW:
        case CAL_SCENARIO_WEBCAM_PREVIEW:
        case CAL_SCENARIO_WEBCAM_CAPTURE:
            OV5642MipiPreview(ScenarioId, pParaIn, pParaOut);
        break;
        case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
            OV5642MipiCapture(ScenarioId, pParaIn, pParaOut);
        break;
		case CAL_SCENARIO_VIDEO:
			OV5642MipiVideo(ScenarioId, pParaIn, pParaOut);		
        default:
        break;
    }
    return ErrorCode;
}

MM_ERROR_CODE_ENUM OV5642MipiSensorClose(void)
{
	  /* power down sensor */
	  CamPdnPinCtrl(OV5642MipiSensorIdx, 1);
	  CamRstPinCtrl(OV5642MipiSensorIdx, 0);
      CisModulePowerOn(OV5642MipiSensorIdx, KAL_FALSE);
	  CameraSccbClose(CAMERA_SCCB_SENSOR);

    return MM_ERROR_NONE;
}


IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncOV5642Mipi=
{
    OV5642MipiSensorOpen,
    OV5642MipiSensorFeatureCtrl,
    OV5642MipiSensorCtrl,
    OV5642MipiSensorClose,
};

MM_ERROR_CODE_ENUM OV5642MipiSensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
	*pfSensorFunc=&ImageSensorFuncOV5642Mipi;
}	/* cam_module_func_config() */




