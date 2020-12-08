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
 *   image_sensor_HI253.c
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

/* #define __HI253_DEBUG_TRACE__ */
#define ISP_DIGITAL_ZOOM_INTERVAL 10

typedef struct
{
	kal_uint16	video_target_width;
	kal_uint16	video_target_height;

	kal_bool	MJPEG_encode_mode;			/* Motion JPEG */
	kal_bool	MPEG4_encode_mode;			/* MJPEG4 JPEG */
	kal_bool	FULLVIDEO_encode_mode;		/* 3G Video Call */

	kal_bool	sensor_cap_state;			/* Preview or Capture mode */
	kal_bool	is_PV_mode; 				/* PV size or Full size */
	kal_bool	is_panorama_capturing;		/* 3G Video Call */

	kal_uint32	curr_banding;				/* 50Hz/60Hz */
	kal_bool	night_mode;
} HI253_OPERATION_STATE_ST;

typedef struct
{
	kal_uint8	sccb_write_id;
	kal_uint8	sccb_read_id;

	kal_uint32	pv_shutter;
	kal_uint32	pv_extra_shutter;
	kal_uint32	pv_sensor_gain;

	kal_uint32	pv_dummy_pixels;
	kal_uint32	pv_dummy_lines;
	kal_uint32	cap_dummy_pixels;
	kal_uint32	cap_dummy_lines;

	/* Preview & Capture Pixel Clock, 360 means 36.0MHz. Unit Multiple 10. */
	kal_uint32	preview_pclk;
	kal_uint32	capture_pclk;

	/* Video frame rate 300 means 30.0fps. Unit Multiple 10. */
	kal_uint32	video_frame_rate;	
	////
	kal_uint8 Wb;
	kal_uint8 Ev;
	kal_uint8 Effect;
	kal_uint8 Mirror;
	kal_uint8 Banding;
	kal_bool NightMode;
	kal_bool VideoMode;
	kal_uint16 Fps;
	kal_uint32 Pclk;
	kal_uint16 DummyPixel; /* for user customization */
	kal_uint16 Hblank; /* for calculating shutter step */
	//kal_uint16 ShutterStep;
	IMAGE_SENSOR_INDEX_ENUM SensorIdx;
	sensor_data_struct *NvramData;

	////
	kal_uint32 mclk;
    kal_bool BypassAe;
    kal_bool BypassAwb;
}HI253Sensor_INFO_ST;
typedef struct _SENSOR_INIT_INFO
{
	kal_uint8 address;
	kal_uint8 data;
}HI253Sensor_INIT_INFO;

static HI253Sensor_INFO_ST HI253Sensor;
static HI253_OPERATION_STATE_ST HI253_op_state;

kal_uint8 gBrightnessValue = 0x0;
static IMAGE_SENSOR_MIRROR_ENUM ImageMirror;

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

/*************************************************************************
* FUNCTION
*	HI253WriteShutter
*
* DESCRIPTION
*	This function used to write the shutter.
*
* PARAMETERS
*	1. kal_uint32 : The shutter want to apply to sensor.
*
* RETURNS
*	None
*
*************************************************************************/
static void HI253WriteShutter(kal_uint32 shutter)
{
	CamWriteCmosSensor(0x03, 0x20); // Page 20
	
	CamWriteCmosSensor(0x83, (shutter>>16)&(0xff)); // EXPTIMEH max fps
	CamWriteCmosSensor(0x84, (shutter>>8)&(0xff)); // EXPTIMEM
	CamWriteCmosSensor(0x85, (shutter>>0)&(0xff)); // EXPTIMEL
}    /* HI253WriteShutter */

/*************************************************************************
* FUNCTION
*	HI253ReadShutter
*
* DESCRIPTION
*	This function read current shutter for calculate the exposure.
*
* PARAMETERS
*	None
*
* RETURNS
*	kal_uint16 : The current shutter value.
*
*************************************************************************/
static kal_uint32 HI253ReadShutter(void)
{
	kal_uint16 temp_reg1, temp_reg2;
	
	/* Backup the preview mode last shutter & sensor gain. */
	CamWriteCmosSensor(0x03, 0x20);
	HI253Sensor.pv_shutter = (CamReadCmosSensor(0x80) << 16)|(CamReadCmosSensor(0x81) << 8)|CamReadCmosSensor(0x82);
	HI253Sensor.pv_extra_shutter = 0;
	
	return HI253Sensor.pv_shutter + HI253Sensor.pv_extra_shutter;
}    /* HI253ReadShutter */

/*************************************************************************
* FUNCTION
*   HI253WriteGain
*
* DESCRIPTION
*   This function apply global gain to sensor
*
* PARAMETERS
*   Gain: base on 0x40
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void HI253WriteGain(kal_uint32 Gain)
{
    // TODO: set global gain here
    kal_uint32 Reg;

    Reg = (Gain - 32) >> 1;
    CamWriteCmosSensor(0x03, 0x20);
    CamWriteCmosSensor(0xB0, Reg);
}

/*************************************************************************
* FUNCTION
*   HI253ReadGain
*
* DESCRIPTION
*   This function get global gain from sensor
*
* PARAMETERS
*   None
*
* RETURNS
*   Gain: base on 0x40
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint32 HI253ReadGain(void)
{
    // TODO: read global gain here
    kal_uint8 Reg;

    CamWriteCmosSensor(0x03, 0x20);
    Reg = CamReadCmosSensor(0xB0);
    
    return 32 + (Reg << 1);
}

/*************************************************************************
* FUNCTION
*	SIV120BSetDummy
*
* DESCRIPTION
*	This function set the dummy pixels(Horizontal Blanking) & dummy lines(Vertical Blanking), it can be
*	used to adjust the frame rate or gain more time for back-end process.
*	
*	IMPORTANT NOTICE: the base shutter need re-calculate for some sensor, or else flicker may occur.
*
* PARAMETERS
*	1. kal_uint32 : Dummy Pixels (Horizontal Blanking)
*	2. kal_uint32 : Dummy Lines (Vertical Blanking)
*
* RETURNS
*	None
*
*************************************************************************/
static void HI253SetDummy(kal_uint32 dummy_pixels, kal_uint32 dummy_lines)
{
	
	CamWriteCmosSensor(0x03, 0x00); 
	CamWriteCmosSensor(0x40, (dummy_pixels>>8)&0xff); // HBLANK=424
	CamWriteCmosSensor(0x41, (dummy_pixels>>0)&0xff);
	CamWriteCmosSensor(0x42, (dummy_lines>>8)&0xff); // VSYNC=62
	CamWriteCmosSensor(0x43, (dummy_lines>>0)&0xff);
	//NULL
	return;

}    /* SIV120BSetDummy */

const HI253Sensor_INIT_INFO HI253_yuv_sensor_initial_setting_26M_MCLK_info[]=
{

	/*[SENSOR_INITIALIZATION]
	DISP_DATE = "2010-11-24 "
	DISP_WIDTH = 800
	DISP_HEIGHT = 600
	DISP_FORMAT = YUV422
	DISP_DATAORDER = YUYV
	MCLK = 26.00
	PLL = 2.00

	BEGIN*/
	{0x01, 0xf9}, // Sleep ON
	{0x08, 0x0f}, // Hi-Z ON
	{0x01, 0xf8}, // Sleep OFF

	{0x03, 0x00}, // Dummy 750us START
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00}, // Dummy 750us END

	{0x0e, 0x00}, // PLL 

	{0x03, 0x00}, // Dummy 750us START
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00}, // Dummy 750us END

	{0x0e, 0x00}, // PLL OFF
	{0x01, 0xf1}, // Sleep ON
	{0x08, 0x00}, // Hi-Z OFF
	{0x01, 0xf3},
	{0x01, 0xf1},

	{0x03, 0x20}, // Page 20
	{0x10, 0x0c}, // AE OFF
	{0x03, 0x22}, // Page 22
	{0x10, 0x69}, // AWB OFF

	{0x03, 0x00}, // Page 0
	{0x10, 0x13}, // Sub1/2_Preview2
	{0x11, 0x90}, // Windowing ON, 1Frame Skip
	{0x12, 0x04}, // 00:Rinsing edge 04:fall edge
	{0x0b, 0xaa}, // ESD Check Register
	{0x0c, 0xaa}, // ESD Check Register
	{0x0d, 0xaa}, // ESD Check Register
	{0x20, 0x00}, // WINROWH
	{0x21, 0x04}, // WINROWL
	{0x22, 0x00}, // WINCOLH
	{0x23, 0x07}, // WINCOLL
	{0x24, 0x04}, // WINHGTH
	{0x25, 0xb0}, // WINHGTL
	{0x26, 0x06}, // WINWIDH
	{0x27, 0x40}, // WINWIDL

	{0x40, 0x01}, // HBLANKH 424
	{0x41, 0xa8}, // HBLANKL
	{0x42, 0x00}, // VSYNCH 62
	{0x43, 0x3e}, // VSYNCL

	{0x45, 0x04}, // VSCTL1
	{0x46, 0x18}, // VSCTL2
	{0x47, 0xd8}, // VSCTL3

	{0xe1, 0x0f},

	//BLC
	{0x80, 0x2e}, // BLCCTL
	{0x81, 0x7e},
	{0x82, 0x90},
	{0x83, 0x00},
	{0x84, 0x0c},
	{0x85, 0x00},
	{0x90, 0x0a}, // BLCTIMETH ON
	{0x91, 0x0a}, // BLCTIMETH OFF
	{0x92, 0x78}, // BLCAGTH ON
	{0x93, 0x70}, // BLCAGTH OFF
	{0x94, 0x75}, // BLCDGTH ON
	{0x95, 0x70}, // BLCDGTH OFF
	{0x96, 0xdc},
	{0x97, 0xfe},
	{0x98, 0x20},

	//OutDoor BLC
	{0x99,0x42}, // B
	{0x9a,0x42}, // Gb
	{0x9b,0x42}, // R
	{0x9c,0x42}, // Gr

	//Dark BLC
	{0xa0, 0x00}, // BLCOFS DB
	{0xa2, 0x00}, // BLCOFS DGb
	{0xa4, 0x00}, // BLCOFS DR
	{0xa6, 0x00}, // BLCOFS DGr

	//Normal BLC
	{0xa8, 0x43},
	{0xaa, 0x43},
	{0xac, 0x43},
	{0xae, 0x43},

	{0x03, 0x02}, // Page 2
	{0x12, 0x03},
	{0x13, 0x03},
	{0x16, 0x00},
	{0x17, 0x8C},
	{0x18, 0x4c}, // 0x28->0x2c->4c [20100919 update]
	{0x19, 0x00}, // 0x40->0x00 [20100912 update]
	{0x1a, 0x39},
	{0x1c, 0x09},
	{0x1d, 0x40},
	{0x1e, 0x30},
	{0x1f, 0x10},
	{0x20, 0x77},
	{0x21, 0xde}, // 0xdd->0xde [20100919 update]
	{0x22, 0xa7},
	{0x23, 0x30}, // 0xb0->0x30 [20100912 update]
	{0x27, 0x3c},
	{0x2b, 0x80},
	{0x2e, 0x00}, // 100913 power saving Hy gou 11},
	{0x2f, 0x00}, // 100913 power saving Hy gou a1},
	{0x30, 0x05},
	{0x50, 0x20},
	{0x52, 0x01},
	{0x53, 0xc1},
	{0x55, 0x1c},
	{0x56, 0x11}, // 0x00->0x11 [20100912 update]
	{0x5d, 0xA2},
	{0x5e, 0x5a},					   
	{0x60, 0x87},
	{0x61, 0x99},
	{0x62, 0x88},
	{0x63, 0x97},
	{0x64, 0x88},
	{0x65, 0x97},
	{0x67, 0x0c},
	{0x68, 0x0c},
	{0x69, 0x0c},
	{0x72, 0x89},
	{0x73, 0x96}, // 0x97->0x96 [20100919 update]
	{0x74, 0x89},
	{0x75, 0x96}, // 0x97->0x96 [20100919 update]
	{0x76, 0x89},
	{0x77, 0x96}, // 0x97->0x96 [20100912 update]
	{0x7C, 0x85},
	{0x7d, 0xaf},
	{0x80, 0x01},
	{0x81, 0x7f}, // 0x81->0x7f [20100919 update]
	{0x82, 0x13}, // 0x23->0x13 [20100912 update]
	{0x83, 0x24}, // 0x2b->0x24 [20100912 update]
	{0x84, 0x7d},
	{0x85, 0x81},
	{0x86, 0x7d},
	{0x87, 0x81},
	{0x92, 0x48}, // 0x53->0x48 [20100912 update]
	{0x93, 0x54}, // 0x5e->0x54 [20100912 update]
	{0x94, 0x7d},
	{0x95, 0x81},
	{0x96, 0x7d},
	{0x97, 0x81},
	{0xa0, 0x02},
	{0xa1, 0x7b},
	{0xa2, 0x02},
	{0xa3, 0x7b},
	{0xa4, 0x7b},
	{0xa5, 0x02},
	{0xa6, 0x7b},
	{0xa7, 0x02},
	{0xa8, 0x85},
	{0xa9, 0x8c},
	{0xaa, 0x85},
	{0xab, 0x8c},
	{0xac, 0x10}, // 0x20->0x10 [20100912 update]
	{0xad, 0x16}, // 0x26->0x16 [20100912 update]
	{0xae, 0x10}, // 0x20->0x10 [20100912 update]
	{0xaf, 0x16}, // 0x26->0x16 [20100912 update]
	{0xb0, 0x99},
	{0xb1, 0xa3},
	{0xb2, 0xa4},
	{0xb3, 0xae},
	{0xb4, 0x9b},
	{0xb5, 0xa2},
	{0xb6, 0xa6},
	{0xb7, 0xac},
	{0xb8, 0x9b},
	{0xb9, 0x9f},
	{0xba, 0xa6},
	{0xbb, 0xaa},
	{0xbc, 0x9b},
	{0xbd, 0x9f},
	{0xbe, 0xa6},
	{0xbf, 0xaa},
	{0xc4, 0x2c}, // 0x36->0x2c [20100912 update]
	{0xc5, 0x43}, // 0x4e->0x43 [20100912 update]
	{0xc6, 0x63}, // 0x61->0x63 [20100912 update]
	{0xc7, 0x79}, // 0x78->0x79 [20100919 update]
	{0xc8, 0x2d}, // 0x36->0x2d [20100912 update]
	{0xc9, 0x42}, // 0x4d->0x42 [20100912 update]
	{0xca, 0x2d}, // 0x36->0x2d [20100912 update]
	{0xcb, 0x42}, // 0x4d->0x42 [20100912 update]
	{0xcc, 0x64}, // 0x62->0x64 [20100912 update]
	{0xcd, 0x78},
	{0xce, 0x64}, // 0x62->0x64 [20100912 update]
	{0xcf, 0x78},
	{0xd0, 0x0a},
	{0xd1, 0x09},
	{0xd4, 0x0a}, // DCDCTIMETHON
	{0xd5, 0x0a}, // DCDCTIMETHOFF
	{0xd6, 0x78}, // DCDCAGTHON
	{0xd7, 0x70}, // DCDCAGTHOFF
	{0xe0, 0xc4},
	{0xe1, 0xc4},
	{0xe2, 0xc4},
	{0xe3, 0xc4},
	{0xe4, 0x00},
	{0xe8, 0x80}, // 0x00->0x80 [20100919 update]
	{0xe9, 0x40},
	{0xea, 0x7f}, // 0x82->0x7f [20100919 update]
	{0xf0, 0x01}, // 100810 memory delay
	{0xf1, 0x01}, // 100810 memory delay
	{0xf2, 0x01}, // 100810 memory delay
	{0xf3, 0x01}, // 100810 memory delay
	{0xf4, 0x01}, // 100810 memory delay

	{0x03, 0x03},
	{0x10, 0x10},

	{0x03, 0x10}, // Page 10
	{0x10, 0x03}, // YUYV
	{0x12, 0x30}, // ISPCTL3
	{0x13, 0x02}, // ISPCTL4 enable contrast
	{0x20, 0x00}, // ITUCTL
	{0x30, 0x00},
	{0x31, 0x00},
	{0x32, 0x00},
	{0x33, 0x00},
	{0x34, 0x30},
	{0x35, 0x00},
	{0x36, 0x00},
	{0x38, 0x00},
	{0x3e, 0x58},
	{0x3f, 0x02}, // 0x02 for preview and 0x00 for capture
	//{0x40, 0x80}, // YOFS
	{0x40, 0x85}, // YOFS modify brightness
	{0x41, 0x00}, // DYOFS

	//Saturation
	{0x60, 0x6f}, // SATCTL
	{0x61, 0x76}, // SATB
	{0x62, 0x76}, // SATR
	{0x63, 0x30}, // AGSAT
	{0x64, 0x41},
	{0x66, 0x33}, // SATTIMETH
	{0x67, 0x00}, // SATOUTDEL
	{0x6a, 0x90}, // UPOSSAT
	{0x6b, 0x80}, // UNEGSAT
	{0x6c, 0x80}, // VPOSSAT
	{0x6d, 0xa0}, // VNEGSAT
	{0x76, 0x01}, // white protection ON
	{0x74, 0x66},
	{0x79, 0x06},

	{0x03, 0x11}, // Page 11
	{0x10, 0x3f}, // DLPFCTL1
	{0x11, 0x40},
	{0x12, 0xba},
	{0x13, 0xcb},
	{0x26, 0x20}, // LPFAGTHL
	{0x27, 0x22}, // LPFAGTHH
	{0x28, 0x0f}, // LPFOUTTHL
	{0x29, 0x10}, // LPFOUTTHH
	{0x2b, 0x30}, // LPFYMEANTHL
	{0x2c, 0x32}, // LPFYMEANTHH

	//Out2 D-LPF th
	{0x30, 0x70}, // OUT2YBOUNDH
	{0x31, 0x10}, // OUT2YBOUNDL
	{0x32, 0x65}, // OUT2RATIO
	{0x33, 0x09}, // OUT2THH
	{0x34, 0x06}, // OUT2THM
	{0x35, 0x04}, // OUT2THL

	//Out1 D-LPF th
	{0x36, 0x70}, // OUT1YBOUNDH
	{0x37, 0x18}, // OUT1YBOUNDL
	{0x38, 0x65}, // OUT1RATIO
	{0x39, 0x09}, // OUT1THH
	{0x3a, 0x06}, // OUT1THM
	{0x3b, 0x04}, // OUT1THL

	//Indoor D-LPF th
	{0x3c, 0x80}, // INYBOUNDH
	{0x3d, 0x18}, // INYBOUNDL
	{0x3e, 0x80}, // INRATIO
	{0x3f, 0x0c}, // INTHH
	{0x40, 0x09}, // INTHM
	{0x41, 0x06}, // INTHL

	{0x42, 0x80}, // DARK1YBOUNDH
	{0x43, 0x18}, // DARK1YBOUNDL
	{0x44, 0x80}, // DARK1RATIO
	{0x45, 0x12}, // DARK1THH
	{0x46, 0x10}, // DARK1THM
	{0x47, 0x10}, // DARK1THL
	{0x48, 0x90}, // DARK2YBOUNDH
	{0x49, 0x40}, // DARK2YBOUNDL
	{0x4a, 0x80}, // DARK2RATIO
	{0x4b, 0x13}, // DARK2THH
	{0x4c, 0x10}, // DARK2THM
	{0x4d, 0x11}, // DARK2THL
	{0x4e, 0x80}, // DARK3YBOUNDH
	{0x4f, 0x30}, // DARK3YBOUNDL
	{0x50, 0x80}, // DARK3RATIO
	{0x51, 0x13}, // DARK3THH
	{0x52, 0x10}, // DARK3THM
	{0x53, 0x13}, // DARK3THL
	{0x54, 0x11},
	{0x55, 0x17},
	{0x56, 0x20},
	{0x57, 0x20},
	{0x58, 0x20},
	{0x59, 0x30},
	{0x5a, 0x18},
	{0x5b, 0x00},
	{0x5c, 0x00},
	{0x60, 0x3f},
	{0x62, 0x50},
	{0x70, 0x06},

	{0x03, 0x12}, // Page 12
	{0x20, 0x00}, // YCLPFCTL1 0x00 for preview and 0x0f for capture
	{0x21, 0x00}, // YCLPFCTL2 0x00 for preview and 0x0f for capture
	{0x25, 0x30},
	{0x28, 0x00}, // Out1 BP t
	{0x29, 0x00}, // Out2 BP t
	{0x2a, 0x00},
	{0x30, 0x50},
	{0x31, 0x18}, // YCUNI1TH
	{0x32, 0x32}, // YCUNI2TH
	{0x33, 0x40}, // YCUNI3TH
	{0x34, 0x50}, // YCNOR1TH
	{0x35, 0x70}, // YCNOR2TH
	{0x36, 0xa0}, // YCNOR3TH
	{0x3b, 0x06},
	{0x3c, 0x06},

	//Out2 th
	{0x40, 0xa0}, // YCOUT2THH
	{0x41, 0x40}, // YCOUT2THL
	{0x42, 0xa0}, // YCOUT2STDH
	{0x43, 0x90}, // YCOUT2STDM
	{0x44, 0x90}, // YCOUT2STDL
	{0x45, 0x80}, // YCOUT2RAT

	//Out1 th
	{0x46, 0xb0}, // YCOUT1THH
	{0x47, 0x55}, // YCOUT1THL
	{0x48, 0xa0}, // YCOUT1STDH
	{0x49, 0x90}, // YCOUT1STDM
	{0x4a, 0x90}, // YCOUT1STDL
	{0x4b, 0x80}, // YCOUT1RAT

	//In door th
	{0x4c, 0xb0}, // YCINTHH
	{0x4d, 0x40}, // YCINTHL
	{0x4e, 0x90}, // YCINSTDH
	{0x4f, 0x90}, // YCINSTDM
	{0x50, 0xe6}, // YCINSTDL
	{0x51, 0x80}, // YCINRAT

	//Dark1 th
	{0x52, 0xb0}, // YCDARK1THH
	{0x53, 0x60}, // YCDARK1THL
	{0x54, 0xc0}, // YCDARK1STDH
	{0x55, 0xc0}, // YCDARK1STDM
	{0x56, 0xc0}, // YCDARK1STDL
	{0x57, 0x80}, // YCDARK1RAT

	//Dark2 th
	{0x58, 0x90}, // YCDARK2THH
	{0x59, 0x40}, // YCDARK2THL
	{0x5a, 0xd0}, // YCDARK2STDH
	{0x5b, 0xd0}, // YCDARK2STDM
	{0x5c, 0xe0}, // YCDARK2STDL
	{0x5d, 0x80}, // YCDARK2RAT

	//Dark3 th
	{0x5e, 0x88}, // YCDARK3THH
	{0x5f, 0x40}, // YCDARK3THL
	{0x60, 0xe0}, // YCDARK3STDH
	{0x61, 0xe6}, // YCDARK3STDM
	{0x62, 0xe6}, // YCDARK3STDL
	{0x63, 0x80}, // YCDARK3RAT

	{0x70, 0x15},
	{0x71, 0x01}, //Don't Touch register

	{0x72, 0x18},
	{0x73, 0x01}, //Don't Touch register

	{0x74, 0x25},
	{0x75, 0x15},
	{0x80, 0x30},
	{0x81, 0x50},
	{0x82, 0x80},
	{0x85, 0x1a},
	{0x88, 0x00},
	{0x89, 0x00},
	{0x90, 0x00}, // DPCCTL 0x00 For Preview and 0x5d for capture

	{0xc5, 0x30},
	{0xc6, 0x2a},

	//Dont Touch register
	{0xD0, 0x0c},
	{0xD1, 0x80},
	{0xD2, 0x67},
	{0xD3, 0x00},
	{0xD4, 0x00},
	{0xD5, 0x02},
	{0xD6, 0xff},
	{0xD7, 0x18},

	{0x03, 0x13}, // Page 13
	{0x10, 0xcb}, // EDGECTL1
	{0x11, 0x7b}, // EDGECTL2
	{0x12, 0x07}, // EDGECTL3
	{0x14, 0x00}, // EDGECTL5

	{0x20, 0x15}, // EDGENGAIN
	{0x21, 0x13}, // EDGEPGAIN
	{0x22, 0x33},
	{0x23, 0x04}, // EDGEHCLIP1TH
	{0x24, 0x09}, // EDGEHCLIP2TH
	{0x25, 0x08}, // EDGELCLIPTH
	{0x26, 0x18}, // EDGELCLIPLMT
	{0x27, 0x30},
	{0x29, 0x12}, // EDGETIMETH
	{0x2a, 0x50}, // EDGEAGTH

	//Low clip th
	{0x2b, 0x06},
	{0x2c, 0x06},
	{0x25, 0x08},
	{0x2d, 0x0c},
	{0x2e, 0x12},
	{0x2f, 0x12},

	//Out2 Edge
	{0x50, 0x10},
	{0x51, 0x14},
	{0x52, 0x10},
	{0x53, 0x0c},
	{0x54, 0x0f},
	{0x55, 0x0c},

	//Out1 Edge
	{0x56, 0x10},
	{0x57, 0x13},
	{0x58, 0x10},
	{0x59, 0x0c},
	{0x5a, 0x0f},
	{0x5b, 0x0c},

	//Indoor Edge
	{0x5c, 0x0a},
	{0x5d, 0x0b},
	{0x5e, 0x0a},
	{0x5f, 0x08},
	{0x60, 0x09},
	{0x61, 0x08},

	//Dark1 Edge
	{0x62, 0x08},
	{0x63, 0x08},
	{0x64, 0x08},
	{0x65, 0x06},
	{0x66, 0x06},
	{0x67, 0x06},

	//Dark2 Edge
	{0x68, 0x07},
	{0x69, 0x07},
	{0x6a, 0x07},
	{0x6b, 0x05},
	{0x6c, 0x05},
	{0x6d, 0x05},

	//Dark3 Edge
	{0x6e, 0x07},
	{0x6f, 0x07},
	{0x70, 0x07},
	{0x71, 0x05},
	{0x72, 0x05},
	{0x73, 0x05},

	//2DY
	{0x80, 0x00}, // EDGE2DCTL1 00 for preview, must turn on 2DY 0xfd when capture
	{0x81, 0x1f}, // EDGE2DCTL2
	{0x82, 0x05}, // EDGE2DCTL3
	{0x83, 0x01}, // EDGE2DCTL4

	{0x90, 0x05}, // EDGE2DNGAIN
	{0x91, 0x05}, // EDGE2DPGAIN
	{0x92, 0x33}, // EDGE2DLCLIPLMT
	{0x93, 0x30},
	{0x94, 0x03}, // EDGE2DHCLIP1TH
	{0x95, 0x14}, // EDGE2DHCLIP2TH
	{0x97, 0x30},
	{0x99, 0x30},

	{0xa0, 0x04}, // EDGE2DLCOUT2N
	{0xa1, 0x05}, // EDGE2DLCOUT2P
	{0xa2, 0x04}, // EDGE2DLCOUT1N
	{0xa3, 0x05}, // EDGE2DLCOUT1P
	{0xa4, 0x07}, // EDGE2DLCINN
	{0xa5, 0x08}, // EDGE2DLCINP
	{0xa6, 0x07}, // EDGE2DLCD1N
	{0xa7, 0x08}, // EDGE2DLCD1P
	{0xa8, 0x07}, // EDGE2DLCD2N
	{0xa9, 0x08}, // EDGE2DLCD2P
	{0xaa, 0x07}, // EDGE2DLCD3N
	{0xab, 0x08}, // EDGE2DLCD3P

	//Out2 
	{0xb0, 0x22},
	{0xb1, 0x2a},
	{0xb2, 0x28},
	{0xb3, 0x22},
	{0xb4, 0x2a},
	{0xb5, 0x28},

	//Out1 
	{0xb6, 0x22},
	{0xb7, 0x2a},
	{0xb8, 0x28},
	{0xb9, 0x22},
	{0xba, 0x2a},
	{0xbb, 0x28},

	{0xbc, 0x17},
	{0xbd, 0x17},
	{0xbe, 0x17},
	{0xbf, 0x17},
	{0xc0, 0x17},
	{0xc1, 0x17},

	//Dark1
	{0xc2, 0x1e},
	{0xc3, 0x12},
	{0xc4, 0x10},
	{0xc5, 0x1e},
	{0xc6, 0x12},
	{0xc7, 0x10},

	//Dark2
	{0xc8, 0x18},
	{0xc9, 0x05},
	{0xca, 0x05},
	{0xcb, 0x18},
	{0xcc, 0x05},
	{0xcd, 0x05},

	//Dark3 
	{0xce, 0x18},
	{0xcf, 0x05},
	{0xd0, 0x05},
	{0xd1, 0x18},
	{0xd2, 0x05},
	{0xd3, 0x05},

	{0x03, 0x14}, // Page 14
	{0x10, 0x11}, // LENSCTL1
	{0x20, 0x40}, // XCEN
	{0x21, 0x80}, // YCEN
	{0x22, 0x80}, // LENSRGAIN
	{0x23, 0x80}, // LENSGGAIN
	{0x24, 0x80}, // LENSBGAIN

	{0x30, 0xc8},
	{0x31, 0x2b},
	{0x32, 0x00},
	{0x33, 0x00},
	{0x34, 0x90},

	{0x40, 0x65}, // LENSRP0
	{0x50, 0x42}, // LENSGrP0
	{0x60, 0x3a}, // LENSBP0
	{0x70, 0x42}, // LENSGbP0

	{0x03, 0x15}, // Page 15 
	{0x10, 0x0f}, // CMCCTL
	{0x14, 0x52}, // CMCOFSGH
	{0x15, 0x42}, // CMCOFSGM
	{0x16, 0x32}, // CMCOFSGL
	{0x17, 0x2f}, // CMCSIGN

	//CMC
	{0x30, 0x8f}, // CMC11
	{0x31, 0x59}, // CMC12
	{0x32, 0x0a}, // CMC13
	{0x33, 0x15}, // CMC21
	{0x34, 0x5b}, // CMC22
	{0x35, 0x06}, // CMC23
	{0x36, 0x07}, // CMC31
	{0x37, 0x40}, // CMC32
	{0x38, 0x86}, // CMC33

	//CMC OFS
	{0x40, 0x95}, // CMCOFSL11
	{0x41, 0x1f}, // CMCOFSL12
	{0x42, 0x8a}, // CMCOFSL13
	{0x43, 0x86}, // CMCOFSL21
	{0x44, 0x0a}, // CMCOFSL22
	{0x45, 0x84}, // CMCOFSL23
	{0x46, 0x87}, // CMCOFSL31
	{0x47, 0x9b}, // CMCOFSL32
	{0x48, 0x23}, // CMCOFSL33

	//CMC POFS
	{0x50, 0x8c}, // CMCOFSH11
	{0x51, 0x0c}, // CMCOFSH12
	{0x52, 0x00}, // CMCOFSH13
	{0x53, 0x07}, // CMCOFSH21
	{0x54, 0x17}, // CMCOFSH22
	{0x55, 0x9d}, // CMCOFSH23
	{0x56, 0x00}, // CMCOFSH31
	{0x57, 0x0b}, // CMCOFSH32
	{0x58, 0x89}, // CMCOFSH33

	{0x80, 0x03},
	{0x85, 0x40},
	{0x87, 0x02},
	{0x88, 0x00},
	{0x89, 0x00},
	{0x8a, 0x00},

	{0x03, 0x16}, // Page 16
	{0x10, 0x31}, // GMACTL
	{0x18, 0x37},
	{0x19, 0x36},
	{0x1a, 0x0e},
	{0x1b, 0x01},
	{0x1c, 0xdc},
	{0x1d, 0xfe},

	{0x30, 0x00}, // GGMA0
	{0x31, 0x06}, // GGMA1
	{0x32, 0x1d}, // GGMA2
	{0x33, 0x33}, // GGMA3
	{0x34, 0x53}, // GGMA4
	{0x35, 0x6c}, // GGMA5
	{0x36, 0x81}, // GGMA6
	{0x37, 0x94}, // GGMA7
	{0x38, 0xa4}, // GGMA8
	{0x39, 0xb3}, // GGMA9
	{0x3a, 0xc0}, // GGMA10
	{0x3b, 0xcb}, // GGMA11
	{0x3c, 0xd5}, // GGMA12
	{0x3d, 0xde}, // GGMA13
	{0x3e, 0xe6}, // GGMA14
	{0x3f, 0xee}, // GGMA15
	{0x40, 0xf5}, // GGMA16
	{0x41, 0xfc}, // GGMA17
	{0x42, 0xff}, // GGMA18

	{0x50, 0x00}, // RGMA0
	{0x51, 0x03}, // RGMA1
	{0x52, 0x19}, // RGMA2
	{0x53, 0x34}, // RGMA3
	{0x54, 0x58}, // RGMA4
	{0x55, 0x75}, // RGMA5
	{0x56, 0x8d}, // RGMA6
	{0x57, 0xa1}, // RGMA7
	{0x58, 0xb2}, // RGMA8
	{0x59, 0xbe}, // RGMA9
	{0x5a, 0xc9}, // RGMA10
	{0x5b, 0xd2}, // RGMA11
	{0x5c, 0xdb}, // RGMA12
	{0x5d, 0xe3}, // RGMA13
	{0x5e, 0xeb}, // RGMA14
	{0x5f, 0xf0}, // RGMA15
	{0x60, 0xf5}, // RGMA16
	{0x61, 0xf7}, // RGMA17
	{0x62, 0xf8}, // RGMA18

	{0x70, 0x00}, // BGMA0
	{0x71, 0x08}, // BGMA1
	{0x72, 0x17}, // BGMA2
	{0x73, 0x2f}, // BGMA3
	{0x74, 0x53}, // BGMA4
	{0x75, 0x6c}, // BGMA5
	{0x76, 0x81}, // BGMA6
	{0x77, 0x94}, // BGMA7
	{0x78, 0xa4}, // BGMA8
	{0x79, 0xb3}, // BGMA9
	{0x7a, 0xc0}, // BGMA10
	{0x7b, 0xcb}, // BGMA11
	{0x7c, 0xd5}, // BGMA12
	{0x7d, 0xde}, // BGMA13
	{0x7e, 0xe6}, // BGMA14
	{0x7f, 0xee}, // BGMA15
	{0x80, 0xf4}, // BGMA16
	{0x81, 0xfa}, // BGMA17
	{0x82, 0xff}, // BGMA18

	{0x03, 0x17}, // Page 17
	{0xc4, 0x68}, // FLK200
	{0xc5, 0x56}, // FLK240




	{0x03, 0x20}, // Page 20
	{0x11, 0x1c},
	{0x20, 0x01}, // AEFRAMECTL lowtemp off
	{0x21, 0x30},
	{0x22, 0x10},
	{0x23, 0x00},
	{0x24, 0x04},

	{0x28, 0xff},
	{0x29, 0xad},

	// MTK set up					  anti banding --> 1/100 s
	{0x2a, 0xf0},
	{0x2b, 0x34},
	{0x2c, 0xc3},
	{0x2d, 0x5f},
	{0x2e, 0x33},
	{0x30, 0x78},
	{0x32, 0x03},
	{0x33, 0x2e},
	{0x34, 0x30},
	{0x35, 0xd4},
	{0x36, 0xfe},
	{0x37, 0x32},
	{0x38, 0x04},
	{0x3b, 0x22},
	{0x3c, 0xef},
	{0x47, 0xf0},

	//Y_Frame TH
	{0x50, 0x45},
	{0x51, 0x88},

	{0x56, 0x10},
	{0x57, 0xb7},
	{0x58, 0x14},
	{0x59, 0x88},
	{0x5a, 0x04},

	{0x60, 0x55}, // AEWGT1
	{0x61, 0x55}, // AEWGT2
	{0x62, 0x6a}, // AEWGT3
	{0x63, 0xa9}, // AEWGT4
	{0x64, 0x6a}, // AEWGT5
	{0x65, 0xa9}, // AEWGT6
	{0x66, 0x6a}, // AEWGT7
	{0x67, 0xa9}, // AEWGT8
	{0x68, 0x6b}, // AEWGT9
	{0x69, 0xe9}, // AEWGT10
	{0x6a, 0x6a}, // AEWGT11
	{0x6b, 0xa9}, // AEWGT12
	{0x6c, 0x6a}, // AEWGT13
	{0x6d, 0xa9}, // AEWGT14
	{0x6e, 0x55}, // AEWGT15
	{0x6f, 0x55}, // AEWGT16
	{0x70, 0x46}, // YLVL
	{0x71, 0xBb},

	// haunting control
	{0x76, 0x21},
	{0x77, 0xBC}, //02},
	{0x78, 0x34}, //22}, // YTH1
	{0x79, 0x3a}, //2a}, // YTH2HI


	{0x7a, 0x23},
	{0x7b, 0x22},
	{0x7d, 0x23},
	{0x83, 0x01}, //EXP Normal 33.33 fps 
	{0x84, 0x7c}, 
	{0x85, 0x40}, 
	{0x86, 0x01}, //EXPMin 10416.67 fps
	{0x87, 0x38}, 
	{0x88, 0x04}, //EXP Max 10.00 fps 
	{0x89, 0xf3}, 
	{0x8a, 0x80}, 
	{0x8B, 0x7e}, //EXP100 
	{0x8C, 0xc0}, 
	{0x8D, 0x69}, //EXP120 
	{0x8E, 0x6c}, 
	{0x91, 0x05}, 
	{0x92, 0xe9}, 
	{0x93, 0xac}, 
	{0x94, 0x04}, 
	{0x95, 0x32}, 
	{0x96, 0x38},			
	{0x98, 0xdc}, // EXPOUT1 DC 9d out target th
	{0x99, 0x45}, // EXPOUT2
	{0x9a, 0x0d},
	{0x9b, 0xde},

	{0x9c, 0x07}, //EXP Limit 1736.11 fps 
	{0x9d, 0x50}, 
	{0x9e, 0x01}, //EXP Unit 
	{0x9f, 0x38}, 
	{0xa0, 0x03},
	{0xa1, 0xa9},
	{0xa2, 0x80},
	{0xb0, 0x1d}, // AG
	{0xb1, 0x1a}, // AGMIN
	{0xb2, 0x80}, // AGMAX
	{0xb3, 0x20}, // AGLVLH //1a
	{0xb4, 0x1a}, // AGTH1
	{0xb5, 0x44}, // AGTH2
	{0xb6, 0x2f}, // AGBTH1
	{0xb7, 0x28}, // AGBTH2
	{0xb8, 0x25}, // AGBTH3
	{0xb9, 0x22}, // AGBTH4
	{0xba, 0x21}, // AGBTH5
	{0xbb, 0x20}, // AGBTH6
	{0xbc, 0x1f}, // AGBTH7
	{0xbd, 0x1f}, // AGBTH8
	{0xc0, 0x30}, // AGSKY
	{0xc1, 0x20},
	{0xc2, 0x20},
	{0xc3, 0x20},
	{0xc4, 0x08}, // AGTIMETH
	{0xc8, 0x80}, // DGMAX
	{0xc9, 0x60}, // DGMIN			

	{0x03, 0x22}, // Page 22
	{0x10, 0xfd}, // AWBCTL1
	{0x11, 0x2e}, // AWBCTL2
	{0x19, 0x01}, 
	{0x20, 0x30},
	{0x21, 0x80},
	{0x23, 0x08},
	{0x24, 0x01},

	{0x30, 0x80}, // ULVL
	{0x31, 0x80}, // VLVL
	{0x38, 0x11}, // UVTH1
	{0x39, 0x34}, // UVTH2
	{0x40, 0xf7}, // YRANGE

	{0x41, 0x77}, // CDIFF
	{0x42, 0x55}, // CSUM2
	{0x43, 0xf0},
	{0x44, 0x66},
	{0x45, 0x33},
	{0x46, 0x01}, // WHTPXLTH1		   
	{0x47, 0x94},

	{0x50, 0xb2},
	{0x51, 0x81},
	{0x52, 0x98},

	{0x80, 0x38}, // RGAIN
	{0x81, 0x20}, // GGAIN
	{0x82, 0x38}, // BGAIN

	{0x83, 0x5e}, // RMAX
	{0x84, 0x20}, // RMIN
	{0x85, 0x53}, // BMAX
	{0x86, 0x15}, // BMIN

	{0x87, 0x54}, // RMAXM
	{0x88, 0x20}, // RMINM
	{0x89, 0x3f}, // BMAXM 
	{0x8a, 0x1c}, // BMINM

	{0x8b, 0x54}, // RMAXB 
	{0x8c, 0x3f}, // RMINB
	{0x8d, 0x24}, // BMAXB
	{0x8e, 0x1c}, // BMINB

	{0x8f, 0x60}, // BGAINPARA1
	{0x90, 0x5f}, // BGAINPARA2
	{0x91, 0x5c}, // BGAINPARA3
	{0x92, 0x4C}, // BGAINPARA4
	{0x93, 0x41}, // BGAINPARA5
	{0x94, 0x3b}, // BGAINPARA6
	{0x95, 0x36}, // BGAINPARA7
	{0x96, 0x30}, // BGAINPARA8
	{0x97, 0x27}, // BGAINPARA9
	{0x98, 0x20}, // BGAINPARA10
	{0x99, 0x1C}, // BGAINPARA11
	{0x9a, 0x19}, // BGAINPARA12

	{0x9b, 0x88}, // BGAINBND1
	{0x9c, 0x88}, // BGAINBND2
	{0x9d, 0x48}, // RGAINTH1
	{0x9e, 0x38}, // RGAINTH2
	{0x9f, 0x30}, // RGAINTH3

	{0xa0, 0x74}, // RDELTA1
	{0xa1, 0x35}, // BDELTA1
	{0xa2, 0xaf}, // RDELTA2
	{0xa3, 0xf7}, // BDELTA2

	{0xa4, 0x10}, // AWBEXPLMT1
	{0xa5, 0x50}, // AWBEXPLMT2
	{0xa6, 0xc4}, // AWBEXPLMT3

	{0xad, 0x40},
	{0xae, 0x4a},

	{0xaf, 0x2a},
	{0xb0, 0x29},

	{0xb1, 0x20},
	{0xb4, 0xff},
	{0xb8, 0x6b},
	{0xb9, 0x00},

	{0x03, 0x24}, // Page 24
	{0x10, 0x01}, // AFCTL1
	{0x18, 0x06},
	{0x30, 0x06},
	{0x31, 0x90},
	{0x32, 0x25},
	{0x33, 0xa2},
	{0x34, 0x26},
	{0x35, 0x58},
	{0x36, 0x60},
	{0x37, 0x00},
	{0x38, 0x50},
	{0x39, 0x00},

	{0x03, 0x20}, // Page 20
	{0x10, 0x9c}, // AE ON 50Hz
	{0x03, 0x22}, // Page 22
	{0x10, 0xe9}, // AWB ON

	{0x03, 0x00}, // Page 0
	{0x0e, 0x03}, // PLL
	{0x0e, 0x73}, // PLL ON x2

	{0x03, 0x00}, // Dummy 750us START
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00}, // Dummy 750us END

	{0x03, 0x00}, // Page 0
	{0x01, 0xf8}, // Sleep OFF

	/*END
	[END]*/

	{0xff, 0xff}

};
const HI253Sensor_INIT_INFO HI253_yuv_sensor_initial_setting_24M_MCLK_info[]=
{
	/*[SENSOR_INITIALIZATION]
	DISP_DATE = "2009-09-25 21:14:45"
	DISP_WIDTH = 800
	DISP_HEIGHT = 600
	DISP_FORMAT = YUV422
	DISP_DATAORDER = YUYV
	MCLK = 24.00
	PLL = 2.00

	BEGIN*/
	{0x01, 0xf9}, // Sleep ON
	{0x08, 0x0f}, // Hi-Z ON
	{0x01, 0xf8}, // Sleep OFF

	{0x03, 0x00}, // Dummy 750us START
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00}, // Dummy 750us END

	{0x0e, 0x00}, // PLL 

	{0x03, 0x00}, // Dummy 750us START
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00}, // Dummy 750us END

	{0x0e, 0x00}, // PLL OFF
	{0x01, 0xf1}, // Sleep ON
	{0x08, 0x00}, // Hi-Z OFF
	{0x01, 0xf3},
	{0x01, 0xf1},

	{0x03, 0x20}, // Page 20
	{0x10, 0x0c}, // AE OFF
	{0x03, 0x22}, // Page 22
	{0x10, 0x69}, // AWB OFF

	{0x03, 0x00}, // Page 0
	{0x10, 0x13}, // Sub1/2_Preview2
	{0x11, 0x90}, // Windowing ON, 1Frame Skip
	{0x12, 0x04}, // 00:Rinsing edge 04:fall edge
	{0x0b, 0xaa}, // ESD Check Register
	{0x0c, 0xaa}, // ESD Check Register
	{0x0d, 0xaa}, // ESD Check Register
	{0x20, 0x00}, // WINROWH
	{0x21, 0x04}, // WINROWL
	{0x22, 0x00}, // WINCOLH
	{0x23, 0x07}, // WINCOLL
	{0x24, 0x04}, // WINHGTH
	{0x25, 0xb0}, // WINHGTL
	{0x26, 0x06}, // WINWIDH
	{0x27, 0x40}, // WINWIDL

	{0x40, 0x01}, // HBLANKH 424
	{0x41, 0xa8}, // HBLANKL
	{0x42, 0x00}, // VSYNCH 8
	{0x43, 0x08}, // VSYNCL

	{0x45, 0x04}, // VSCTL1
	{0x46, 0x18}, // VSCTL2
	{0x47, 0xd8}, // VSCTL3

	{0xe1, 0x0f},

	//BLC
	{0x80, 0x2e}, // BLCCTL
	{0x81, 0x7e},
	{0x82, 0x90},
	{0x83, 0x00},
	{0x84, 0x0c},
	{0x85, 0x00},
	{0x90, 0x0a}, // BLCTIMETH ON
	{0x91, 0x0a}, // BLCTIMETH OFF
	{0x92, 0x78}, // BLCAGTH ON
	{0x93, 0x70}, // BLCAGTH OFF
	{0x94, 0x75}, // BLCDGTH ON
	{0x95, 0x70}, // BLCDGTH OFF
	{0x96, 0xdc},
	{0x97, 0xfe},
	{0x98, 0x20},

	//OutDoor BLC
	{0x99,0x42}, // B
	{0x9a,0x42}, // Gb
	{0x9b,0x42}, // R
	{0x9c,0x42}, // Gr

	//Dark BLC
	{0xa0, 0x00}, // BLCOFS DB
	{0xa2, 0x00}, // BLCOFS DGb
	{0xa4, 0x00}, // BLCOFS DR
	{0xa6, 0x00}, // BLCOFS DGr

	//Normal BLC
	{0xa8, 0x43},
	{0xaa, 0x43},
	{0xac, 0x43},
	{0xae, 0x43},

	{0x03, 0x02}, // Page 2
	{0x12, 0x03},
	{0x13, 0x03},
	{0x16, 0x00},
	{0x17, 0x8C},
	{0x18, 0x4c}, // 0x28->0x2c->4c [20100919 update]
	{0x19, 0x00}, // 0x40->0x00 [20100912 update]
	{0x1a, 0x39},
	{0x1c, 0x09},
	{0x1d, 0x40},
	{0x1e, 0x30},
	{0x1f, 0x10},
	{0x20, 0x77},
	{0x21, 0xde}, // 0xdd->0xde [20100919 update]
	{0x22, 0xa7},
	{0x23, 0x30}, // 0xb0->0x30 [20100912 update]
	{0x27, 0x3c},
	{0x2b, 0x80},
	{0x2e, 0x00}, // 100913 power saving Hy gou 11},
	{0x2f, 0x00}, // 100913 power saving Hy gou a1},
	{0x30, 0x05},
	{0x50, 0x20},
	{0x52, 0x01},
	{0x53, 0xc1},
	{0x55, 0x1c},
	{0x56, 0x11}, // 0x00->0x11 [20100912 update]
	{0x5d, 0xA2},
	{0x5e, 0x5a},					   
	{0x60, 0x87},
	{0x61, 0x99},
	{0x62, 0x88},
	{0x63, 0x97},
	{0x64, 0x88},
	{0x65, 0x97},
	{0x67, 0x0c},
	{0x68, 0x0c},
	{0x69, 0x0c},
	{0x72, 0x89},
	{0x73, 0x96}, // 0x97->0x96 [20100919 update]
	{0x74, 0x89},
	{0x75, 0x96}, // 0x97->0x96 [20100919 update]
	{0x76, 0x89},
	{0x77, 0x96}, // 0x97->0x96 [20100912 update]
	{0x7C, 0x85},
	{0x7d, 0xaf},
	{0x80, 0x01},
	{0x81, 0x7f}, // 0x81->0x7f [20100919 update]
	{0x82, 0x13}, // 0x23->0x13 [20100912 update]
	{0x83, 0x24}, // 0x2b->0x24 [20100912 update]
	{0x84, 0x7d},
	{0x85, 0x81},
	{0x86, 0x7d},
	{0x87, 0x81},
	{0x92, 0x48}, // 0x53->0x48 [20100912 update]
	{0x93, 0x54}, // 0x5e->0x54 [20100912 update]
	{0x94, 0x7d},
	{0x95, 0x81},
	{0x96, 0x7d},
	{0x97, 0x81},
	{0xa0, 0x02},
	{0xa1, 0x7b},
	{0xa2, 0x02},
	{0xa3, 0x7b},
	{0xa4, 0x7b},
	{0xa5, 0x02},
	{0xa6, 0x7b},
	{0xa7, 0x02},
	{0xa8, 0x85},
	{0xa9, 0x8c},
	{0xaa, 0x85},
	{0xab, 0x8c},
	{0xac, 0x10}, // 0x20->0x10 [20100912 update]
	{0xad, 0x16}, // 0x26->0x16 [20100912 update]
	{0xae, 0x10}, // 0x20->0x10 [20100912 update]
	{0xaf, 0x16}, // 0x26->0x16 [20100912 update]
	{0xb0, 0x99},
	{0xb1, 0xa3},
	{0xb2, 0xa4},
	{0xb3, 0xae},
	{0xb4, 0x9b},
	{0xb5, 0xa2},
	{0xb6, 0xa6},
	{0xb7, 0xac},
	{0xb8, 0x9b},
	{0xb9, 0x9f},
	{0xba, 0xa6},
	{0xbb, 0xaa},
	{0xbc, 0x9b},
	{0xbd, 0x9f},
	{0xbe, 0xa6},
	{0xbf, 0xaa},
	{0xc4, 0x2c}, // 0x36->0x2c [20100912 update]
	{0xc5, 0x43}, // 0x4e->0x43 [20100912 update]
	{0xc6, 0x63}, // 0x61->0x63 [20100912 update]
	{0xc7, 0x79}, // 0x78->0x79 [20100919 update]
	{0xc8, 0x2d}, // 0x36->0x2d [20100912 update]
	{0xc9, 0x42}, // 0x4d->0x42 [20100912 update]
	{0xca, 0x2d}, // 0x36->0x2d [20100912 update]
	{0xcb, 0x42}, // 0x4d->0x42 [20100912 update]
	{0xcc, 0x64}, // 0x62->0x64 [20100912 update]
	{0xcd, 0x78},
	{0xce, 0x64}, // 0x62->0x64 [20100912 update]
	{0xcf, 0x78},
	{0xd0, 0x0a},
	{0xd1, 0x09},
	{0xd4, 0x0a}, // DCDCTIMETHON
	{0xd5, 0x0a}, // DCDCTIMETHOFF
	{0xd6, 0x78}, // DCDCAGTHON
	{0xd7, 0x70}, // DCDCAGTHOFF
	{0xe0, 0xc4},
	{0xe1, 0xc4},
	{0xe2, 0xc4},
	{0xe3, 0xc4},
	{0xe4, 0x00},
	{0xe8, 0x80}, // 0x00->0x80 [20100919 update]
	{0xe9, 0x40},
	{0xea, 0x7f}, // 0x82->0x7f [20100919 update]
	{0xf0, 0x01}, // 100810 memory delay
	{0xf1, 0x01}, // 100810 memory delay
	{0xf2, 0x01}, // 100810 memory delay
	{0xf3, 0x01}, // 100810 memory delay
	{0xf4, 0x01}, // 100810 memory delay

	{0x03, 0x03},
	{0x10, 0x10},

	{0x03, 0x10}, // Page 10
	{0x10, 0x03}, // YUYV
	{0x12, 0x30}, // ISPCTL3
	{0x13, 0x02}, // ISPCTL4 enable contrast
	{0x20, 0x00}, // ITUCTL
	{0x30, 0x00},
	{0x31, 0x00},
	{0x32, 0x00},
	{0x33, 0x00},
	{0x34, 0x30},
	{0x35, 0x00},
	{0x36, 0x00},
	{0x38, 0x00},
	{0x3e, 0x58},
	{0x3f, 0x02}, // 0x02 for preview and 0x00 for capture
	//{0x40, 0x80}, // YOFS
	{0x40, 0x85}, // YOFS modify brightness
	{0x41, 0x00}, // DYOFS

	//Saturation
	{0x60, 0x6f}, // SATCTL
	{0x61, 0x76}, // SATB
	{0x62, 0x76}, // SATR
	{0x63, 0x30}, // AGSAT
	{0x64, 0x41},
	{0x66, 0x33}, // SATTIMETH
	{0x67, 0x00}, // SATOUTDEL
	{0x6a, 0x90}, // UPOSSAT
	{0x6b, 0x80}, // UNEGSAT
	{0x6c, 0x80}, // VPOSSAT
	{0x6d, 0xa0}, // VNEGSAT
	{0x76, 0x01}, // white protection ON
	{0x74, 0x66},
	{0x79, 0x06},

	{0x03, 0x11}, // Page 11
	{0x10, 0x3f}, // DLPFCTL1
	{0x11, 0x40},
	{0x12, 0xba},
	{0x13, 0xcb},
	{0x26, 0x20}, // LPFAGTHL
	{0x27, 0x22}, // LPFAGTHH
	{0x28, 0x0f}, // LPFOUTTHL
	{0x29, 0x10}, // LPFOUTTHH
	{0x2b, 0x30}, // LPFYMEANTHL
	{0x2c, 0x32}, // LPFYMEANTHH

	//Out2 D-LPF th
	{0x30, 0x70}, // OUT2YBOUNDH
	{0x31, 0x10}, // OUT2YBOUNDL
	{0x32, 0x65}, // OUT2RATIO
	{0x33, 0x09}, // OUT2THH
	{0x34, 0x06}, // OUT2THM
	{0x35, 0x04}, // OUT2THL

	//Out1 D-LPF th
	{0x36, 0x70}, // OUT1YBOUNDH
	{0x37, 0x18}, // OUT1YBOUNDL
	{0x38, 0x65}, // OUT1RATIO
	{0x39, 0x09}, // OUT1THH
	{0x3a, 0x06}, // OUT1THM
	{0x3b, 0x04}, // OUT1THL

	//Indoor D-LPF th
	{0x3c, 0x80}, // INYBOUNDH
	{0x3d, 0x18}, // INYBOUNDL
	{0x3e, 0x80}, // INRATIO
	{0x3f, 0x0c}, // INTHH
	{0x40, 0x09}, // INTHM
	{0x41, 0x06}, // INTHL

	{0x42, 0x80}, // DARK1YBOUNDH
	{0x43, 0x18}, // DARK1YBOUNDL
	{0x44, 0x80}, // DARK1RATIO
	{0x45, 0x12}, // DARK1THH
	{0x46, 0x10}, // DARK1THM
	{0x47, 0x10}, // DARK1THL
	{0x48, 0x90}, // DARK2YBOUNDH
	{0x49, 0x40}, // DARK2YBOUNDL
	{0x4a, 0x80}, // DARK2RATIO
	{0x4b, 0x13}, // DARK2THH
	{0x4c, 0x10}, // DARK2THM
	{0x4d, 0x11}, // DARK2THL
	{0x4e, 0x80}, // DARK3YBOUNDH
	{0x4f, 0x30}, // DARK3YBOUNDL
	{0x50, 0x80}, // DARK3RATIO
	{0x51, 0x13}, // DARK3THH
	{0x52, 0x10}, // DARK3THM
	{0x53, 0x13}, // DARK3THL
	{0x54, 0x11},
	{0x55, 0x17},
	{0x56, 0x20},
	{0x57, 0x20},
	{0x58, 0x20},
	{0x59, 0x30},
	{0x5a, 0x18},
	{0x5b, 0x00},
	{0x5c, 0x00},
	{0x60, 0x3f},
	{0x62, 0x50},
	{0x70, 0x06},

	{0x03, 0x12}, // Page 12
	{0x20, 0x00}, // YCLPFCTL1 0x00 for preview and 0x0f for capture
	{0x21, 0x00}, // YCLPFCTL2 0x00 for preview and 0x0f for capture
	{0x25, 0x30},
	{0x28, 0x00}, // Out1 BP t
	{0x29, 0x00}, // Out2 BP t
	{0x2a, 0x00},
	{0x30, 0x50},
	{0x31, 0x18}, // YCUNI1TH
	{0x32, 0x32}, // YCUNI2TH
	{0x33, 0x40}, // YCUNI3TH
	{0x34, 0x50}, // YCNOR1TH
	{0x35, 0x70}, // YCNOR2TH
	{0x36, 0xa0}, // YCNOR3TH
	{0x3b, 0x06},
	{0x3c, 0x06},

	//Out2 th
	{0x40, 0xa0}, // YCOUT2THH
	{0x41, 0x40}, // YCOUT2THL
	{0x42, 0xa0}, // YCOUT2STDH
	{0x43, 0x90}, // YCOUT2STDM
	{0x44, 0x90}, // YCOUT2STDL
	{0x45, 0x80}, // YCOUT2RAT

	//Out1 th
	{0x46, 0xb0}, // YCOUT1THH
	{0x47, 0x55}, // YCOUT1THL
	{0x48, 0xa0}, // YCOUT1STDH
	{0x49, 0x90}, // YCOUT1STDM
	{0x4a, 0x90}, // YCOUT1STDL
	{0x4b, 0x80}, // YCOUT1RAT

	//In door th
	{0x4c, 0xb0}, // YCINTHH
	{0x4d, 0x40}, // YCINTHL
	{0x4e, 0x90}, // YCINSTDH
	{0x4f, 0x90}, // YCINSTDM
	{0x50, 0xe6}, // YCINSTDL
	{0x51, 0x80}, // YCINRAT

	//Dark1 th
	{0x52, 0xb0}, // YCDARK1THH
	{0x53, 0x60}, // YCDARK1THL
	{0x54, 0xc0}, // YCDARK1STDH
	{0x55, 0xc0}, // YCDARK1STDM
	{0x56, 0xc0}, // YCDARK1STDL
	{0x57, 0x80}, // YCDARK1RAT

	//Dark2 th
	{0x58, 0x90}, // YCDARK2THH
	{0x59, 0x40}, // YCDARK2THL
	{0x5a, 0xd0}, // YCDARK2STDH
	{0x5b, 0xd0}, // YCDARK2STDM
	{0x5c, 0xe0}, // YCDARK2STDL
	{0x5d, 0x80}, // YCDARK2RAT

	//Dark3 th
	{0x5e, 0x88}, // YCDARK3THH
	{0x5f, 0x40}, // YCDARK3THL
	{0x60, 0xe0}, // YCDARK3STDH
	{0x61, 0xe6}, // YCDARK3STDM
	{0x62, 0xe6}, // YCDARK3STDL
	{0x63, 0x80}, // YCDARK3RAT

	{0x70, 0x15},
	{0x71, 0x01}, //Don't Touch register

	{0x72, 0x18},
	{0x73, 0x01}, //Don't Touch register

	{0x74, 0x25},
	{0x75, 0x15},
	{0x80, 0x30},
	{0x81, 0x50},
	{0x82, 0x80},
	{0x85, 0x1a},
	{0x88, 0x00},
	{0x89, 0x00},
	{0x90, 0x00}, // DPCCTL 0x00 For Preview and 0x5d for capture

	{0xc5, 0x30},
	{0xc6, 0x2a},

	//Dont Touch register
	{0xD0, 0x0c},
	{0xD1, 0x80},
	{0xD2, 0x67},
	{0xD3, 0x00},
	{0xD4, 0x00},
	{0xD5, 0x02},
	{0xD6, 0xff},
	{0xD7, 0x18},

	{0x03, 0x13}, // Page 13
	{0x10, 0xcb}, // EDGECTL1
	{0x11, 0x7b}, // EDGECTL2
	{0x12, 0x07}, // EDGECTL3
	{0x14, 0x00}, // EDGECTL5

	{0x20, 0x15}, // EDGENGAIN
	{0x21, 0x13}, // EDGEPGAIN
	{0x22, 0x33},
	{0x23, 0x04}, // EDGEHCLIP1TH
	{0x24, 0x09}, // EDGEHCLIP2TH
	{0x25, 0x08}, // EDGELCLIPTH
	{0x26, 0x18}, // EDGELCLIPLMT
	{0x27, 0x30},
	{0x29, 0x12}, // EDGETIMETH
	{0x2a, 0x50}, // EDGEAGTH

	//Low clip th
	{0x2b, 0x06},
	{0x2c, 0x06},
	{0x25, 0x08},
	{0x2d, 0x0c},
	{0x2e, 0x12},
	{0x2f, 0x12},

	//Out2 Edge
	{0x50, 0x10},
	{0x51, 0x14},
	{0x52, 0x10},
	{0x53, 0x0c},
	{0x54, 0x0f},
	{0x55, 0x0c},

	//Out1 Edge
	{0x56, 0x10},
	{0x57, 0x13},
	{0x58, 0x10},
	{0x59, 0x0c},
	{0x5a, 0x0f},
	{0x5b, 0x0c},

	//Indoor Edge
	{0x5c, 0x0a},
	{0x5d, 0x0b},
	{0x5e, 0x0a},
	{0x5f, 0x08},
	{0x60, 0x09},
	{0x61, 0x08},

	//Dark1 Edge
	{0x62, 0x08},
	{0x63, 0x08},
	{0x64, 0x08},
	{0x65, 0x06},
	{0x66, 0x06},
	{0x67, 0x06},

	//Dark2 Edge
	{0x68, 0x07},
	{0x69, 0x07},
	{0x6a, 0x07},
	{0x6b, 0x05},
	{0x6c, 0x05},
	{0x6d, 0x05},

	//Dark3 Edge
	{0x6e, 0x07},
	{0x6f, 0x07},
	{0x70, 0x07},
	{0x71, 0x05},
	{0x72, 0x05},
	{0x73, 0x05},

	//2DY
	{0x80, 0x00}, // EDGE2DCTL1 00 for preview, must turn on 2DY 0xfd when capture
	{0x81, 0x1f}, // EDGE2DCTL2
	{0x82, 0x05}, // EDGE2DCTL3
	{0x83, 0x01}, // EDGE2DCTL4

	{0x90, 0x05}, // EDGE2DNGAIN
	{0x91, 0x05}, // EDGE2DPGAIN
	{0x92, 0x33}, // EDGE2DLCLIPLMT
	{0x93, 0x30},
	{0x94, 0x03}, // EDGE2DHCLIP1TH
	{0x95, 0x14}, // EDGE2DHCLIP2TH
	{0x97, 0x30},
	{0x99, 0x30},

	{0xa0, 0x04}, // EDGE2DLCOUT2N
	{0xa1, 0x05}, // EDGE2DLCOUT2P
	{0xa2, 0x04}, // EDGE2DLCOUT1N
	{0xa3, 0x05}, // EDGE2DLCOUT1P
	{0xa4, 0x07}, // EDGE2DLCINN
	{0xa5, 0x08}, // EDGE2DLCINP
	{0xa6, 0x07}, // EDGE2DLCD1N
	{0xa7, 0x08}, // EDGE2DLCD1P
	{0xa8, 0x07}, // EDGE2DLCD2N
	{0xa9, 0x08}, // EDGE2DLCD2P
	{0xaa, 0x07}, // EDGE2DLCD3N
	{0xab, 0x08}, // EDGE2DLCD3P

	//Out2 
	{0xb0, 0x22},
	{0xb1, 0x2a},
	{0xb2, 0x28},
	{0xb3, 0x22},
	{0xb4, 0x2a},
	{0xb5, 0x28},

	//Out1 
	{0xb6, 0x22},
	{0xb7, 0x2a},
	{0xb8, 0x28},
	{0xb9, 0x22},
	{0xba, 0x2a},
	{0xbb, 0x28},

	{0xbc, 0x17},
	{0xbd, 0x17},
	{0xbe, 0x17},
	{0xbf, 0x17},
	{0xc0, 0x17},
	{0xc1, 0x17},

	//Dark1
	{0xc2, 0x1e},
	{0xc3, 0x12},
	{0xc4, 0x10},
	{0xc5, 0x1e},
	{0xc6, 0x12},
	{0xc7, 0x10},

	//Dark2
	{0xc8, 0x18},
	{0xc9, 0x05},
	{0xca, 0x05},
	{0xcb, 0x18},
	{0xcc, 0x05},
	{0xcd, 0x05},

	//Dark3 
	{0xce, 0x18},
	{0xcf, 0x05},
	{0xd0, 0x05},
	{0xd1, 0x18},
	{0xd2, 0x05},
	{0xd3, 0x05},

	{0x03, 0x14}, // Page 14
	{0x10, 0x11}, // LENSCTL1
	{0x20, 0x40}, // XCEN
	{0x21, 0x80}, // YCEN
	{0x22, 0x80}, // LENSRGAIN
	{0x23, 0x80}, // LENSGGAIN
	{0x24, 0x80}, // LENSBGAIN

	{0x30, 0xc8},
	{0x31, 0x2b},
	{0x32, 0x00},
	{0x33, 0x00},
	{0x34, 0x90},

	{0x40, 0x65}, // LENSRP0
	{0x50, 0x42}, // LENSGrP0
	{0x60, 0x3a}, // LENSBP0
	{0x70, 0x42}, // LENSGbP0

	{0x03, 0x15}, // Page 15 
	{0x10, 0x0f}, // CMCCTL
	{0x14, 0x52}, // CMCOFSGH
	{0x15, 0x42}, // CMCOFSGM
	{0x16, 0x32}, // CMCOFSGL
	{0x17, 0x2f}, // CMCSIGN

	//CMC
	{0x30, 0x8f}, // CMC11
	{0x31, 0x59}, // CMC12
	{0x32, 0x0a}, // CMC13
	{0x33, 0x15}, // CMC21
	{0x34, 0x5b}, // CMC22
	{0x35, 0x06}, // CMC23
	{0x36, 0x07}, // CMC31
	{0x37, 0x40}, // CMC32
	{0x38, 0x86}, // CMC33

	//CMC OFS
	{0x40, 0x95}, // CMCOFSL11
	{0x41, 0x1f}, // CMCOFSL12
	{0x42, 0x8a}, // CMCOFSL13
	{0x43, 0x86}, // CMCOFSL21
	{0x44, 0x0a}, // CMCOFSL22
	{0x45, 0x84}, // CMCOFSL23
	{0x46, 0x87}, // CMCOFSL31
	{0x47, 0x9b}, // CMCOFSL32
	{0x48, 0x23}, // CMCOFSL33

	//CMC POFS
	{0x50, 0x8c}, // CMCOFSH11
	{0x51, 0x0c}, // CMCOFSH12
	{0x52, 0x00}, // CMCOFSH13
	{0x53, 0x07}, // CMCOFSH21
	{0x54, 0x17}, // CMCOFSH22
	{0x55, 0x9d}, // CMCOFSH23
	{0x56, 0x00}, // CMCOFSH31
	{0x57, 0x0b}, // CMCOFSH32
	{0x58, 0x89}, // CMCOFSH33

	{0x80, 0x03},
	{0x85, 0x40},
	{0x87, 0x02},
	{0x88, 0x00},
	{0x89, 0x00},
	{0x8a, 0x00},

	{0x03, 0x16}, // Page 16
	{0x10, 0x31}, // GMACTL
	{0x18, 0x37},
	{0x19, 0x36},
	{0x1a, 0x0e},
	{0x1b, 0x01},
	{0x1c, 0xdc},
	{0x1d, 0xfe},

	{0x30, 0x00}, // GGMA0
	{0x31, 0x06}, // GGMA1
	{0x32, 0x1d}, // GGMA2
	{0x33, 0x33}, // GGMA3
	{0x34, 0x53}, // GGMA4
	{0x35, 0x6c}, // GGMA5
	{0x36, 0x81}, // GGMA6
	{0x37, 0x94}, // GGMA7
	{0x38, 0xa4}, // GGMA8
	{0x39, 0xb3}, // GGMA9
	{0x3a, 0xc0}, // GGMA10
	{0x3b, 0xcb}, // GGMA11
	{0x3c, 0xd5}, // GGMA12
	{0x3d, 0xde}, // GGMA13
	{0x3e, 0xe6}, // GGMA14
	{0x3f, 0xee}, // GGMA15
	{0x40, 0xf5}, // GGMA16
	{0x41, 0xfc}, // GGMA17
	{0x42, 0xff}, // GGMA18

	{0x50, 0x00}, // RGMA0
	{0x51, 0x03}, // RGMA1
	{0x52, 0x19}, // RGMA2
	{0x53, 0x34}, // RGMA3
	{0x54, 0x58}, // RGMA4
	{0x55, 0x75}, // RGMA5
	{0x56, 0x8d}, // RGMA6
	{0x57, 0xa1}, // RGMA7
	{0x58, 0xb2}, // RGMA8
	{0x59, 0xbe}, // RGMA9
	{0x5a, 0xc9}, // RGMA10
	{0x5b, 0xd2}, // RGMA11
	{0x5c, 0xdb}, // RGMA12
	{0x5d, 0xe3}, // RGMA13
	{0x5e, 0xeb}, // RGMA14
	{0x5f, 0xf0}, // RGMA15
	{0x60, 0xf5}, // RGMA16
	{0x61, 0xf7}, // RGMA17
	{0x62, 0xf8}, // RGMA18

	{0x70, 0x00}, // BGMA0
	{0x71, 0x08}, // BGMA1
	{0x72, 0x17}, // BGMA2
	{0x73, 0x2f}, // BGMA3
	{0x74, 0x53}, // BGMA4
	{0x75, 0x6c}, // BGMA5
	{0x76, 0x81}, // BGMA6
	{0x77, 0x94}, // BGMA7
	{0x78, 0xa4}, // BGMA8
	{0x79, 0xb3}, // BGMA9
	{0x7a, 0xc0}, // BGMA10
	{0x7b, 0xcb}, // BGMA11
	{0x7c, 0xd5}, // BGMA12
	{0x7d, 0xde}, // BGMA13
	{0x7e, 0xe6}, // BGMA14
	{0x7f, 0xee}, // BGMA15
	{0x80, 0xf4}, // BGMA16
	{0x81, 0xfa}, // BGMA17
	{0x82, 0xff}, // BGMA18

	{0x03, 0x17}, // Page 17
	{0x10, 0xf7},
	{0xc4, 0x60}, // FLK200
	{0xc5, 0x50}, // FLK240

	{0x03, 0x20}, // Page 20
	{0x11, 0x1c},
	{0x18, 0x30},
	{0x1a, 0x08},
	{0x20, 0x01}, //05_lowtemp Y Mean off
	{0x21, 0x30},
	{0x22, 0x10},
	{0x23, 0x00},
	{0x24, 0x00}, //Uniform Scene Off

	{0x28, 0xe7},
	{0x29, 0x0d}, //20100305 ad->0d
	{0x2a, 0xff},
	{0x2b, 0x04}, //f4->Adaptive off

	{0x2c, 0xc2},
	{0x2d, 0xcf},  //fe->AE Speed option
	{0x2e, 0x33},
	{0x30, 0x78}, //f8
	{0x32, 0x03},
	{0x33, 0x2e},
	{0x34, 0x30},
	{0x35, 0xd4},
	{0x36, 0xfe},
	{0x37, 0x32},
	{0x38, 0x04},
	{0x39, 0x22}, //AE_escapeC10
	{0x3a, 0xde}, //AE_escapeC11
	{0x3b, 0x22}, //AE_escapeC1
	{0x3c, 0xde}, //AE_escapeC2

	//Y_Frame TH
	{0x50, 0x45},
	{0x51, 0x88},

	{0x56, 0x03},
	{0x57, 0xf7},
	{0x58, 0x14},
	{0x59, 0x88},
	{0x5a, 0x04},

	{0x60, 0x55}, // AEWGT1
	{0x61, 0x55}, // AEWGT2
	{0x62, 0x6a}, // AEWGT3
	{0x63, 0xa9}, // AEWGT4
	{0x64, 0x6a}, // AEWGT5
	{0x65, 0xa9}, // AEWGT6
	{0x66, 0x6a}, // AEWGT7
	{0x67, 0xa9}, // AEWGT8
	{0x68, 0x6b}, // AEWGT9
	{0x69, 0xe9}, // AEWGT10
	{0x6a, 0x6a}, // AEWGT11
	{0x6b, 0xa9}, // AEWGT12
	{0x6c, 0x6a}, // AEWGT13
	{0x6d, 0xa9}, // AEWGT14
	{0x6e, 0x55}, // AEWGT15
	{0x6f, 0x55}, // AEWGT16
	{0x70, 0x76}, // YLVL
	{0x71, 0x00}, //82(+8)->+0

	// haunting control
	{0x76, 0x43},
	{0x77, 0xe2}, //04 //f2
	{0x78, 0x23}, // YTH1
	{0x79, 0x42}, // YTH2HI //46
	{0x7a, 0x23},
	{0x7b, 0x22},
	{0x7d, 0x23},
	{0x83, 0x01}, // EXPTIMEH 30fps 
	{0x84, 0x5f}, // EXPTIMEM 
	{0x85, 0x00}, // EXPTIMEL 
	{0x86, 0x01}, // EXPMINH
	{0x87, 0x38}, // EXPMINL
	{0x88, 0x04}, // EXPMAXH 10fps
	{0x89, 0x92}, // EXPMAXM 
	{0x8a, 0x00}, // EXPMAXL 
	{0x8b, 0x75}, // EXP100H
	{0x8c, 0x00}, // EXP100L 
	{0x8d, 0x61}, // EXP120H
	{0x8e, 0x80}, // EXP120L 
	{0x9c, 0x0e}, // EXPLMTH
	{0x9d, 0xa0}, // EXPLMTL 
	{0x9e, 0x01}, // EXPUNITH
	{0x9f, 0x38}, // EXPUNITL 
	{0xb0, 0x18}, // AG
	{0xb1, 0x14}, // AGMIN
	{0xb2, 0xe0}, // AGMAX
	{0xb3, 0x18}, // AGLVLH
	{0xb4, 0x1a}, // AGTH1
	{0xb5, 0x44}, // AGTH2
	{0xb6, 0x2f}, // AGBTH1
	{0xb7, 0x28}, // AGBTH2
	{0xb8, 0x25}, // AGBTH3
	{0xb9, 0x22}, // AGBTH4
	{0xba, 0x21}, // AGBTH5
	{0xbb, 0x20}, // AGBTH6
	{0xbc, 0x1f}, // AGBTH7
	{0xbd, 0x1f}, // AGBTH8
	{0xc8, 0x80}, // DGMAX
	{0xc9, 0x60}, // DGMIN


	{0x03, 0x24}, // Page 24
	{0x10, 0x01}, // AFCTL1
	{0x18, 0x06},
	{0x30, 0x06},
	{0x31, 0x90},
	{0x32, 0x25},
	{0x33, 0xa2},
	{0x34, 0x26},
	{0x35, 0x58},
	{0x36, 0x60},
	{0x37, 0x00},
	{0x38, 0x50},
	{0x39, 0x00},

	{0x03, 0x20}, // Page 20
	{0x10, 0x9c}, // AE ON 50Hz
	{0x03, 0x22}, // Page 22
	{0x10, 0xe9}, // AWB ON

	{0x03, 0x00}, // Page 0
	{0x0e, 0x03}, // PLL
	{0x0e, 0x73}, // PLL ON x2

	{0x03, 0x00}, // Dummy 750us START
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00},
	{0x03, 0x00}, // Dummy 750us END

	{0x03, 0x00}, // Page 0
	{0x01, 0xf8}, // Sleep OFF

	/*END
	[END]*/

	{0xff, 0xff}
};



/*************************************************************************
* FUNCTION
*    HI253InitialSetting
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
/*HAL_modify_working*/static void HI253InitialSetting(void)
{
	kal_uint32 iEcount;
	if(HI253Sensor.mclk==260)
	{
		for(iEcount=0;(!((0xff==(HI253_yuv_sensor_initial_setting_26M_MCLK_info[iEcount].address))&&(0xff==(HI253_yuv_sensor_initial_setting_26M_MCLK_info[iEcount].data))));iEcount++)
		{
			CamWriteCmosSensor(HI253_yuv_sensor_initial_setting_26M_MCLK_info[iEcount].address, HI253_yuv_sensor_initial_setting_26M_MCLK_info[iEcount].data);
		}
		HI253Sensor.preview_pclk = 520;
	}
	else if(HI253Sensor.mclk==240)
	{
		for(iEcount=0;(!((0xff==(HI253_yuv_sensor_initial_setting_24M_MCLK_info[iEcount].address))&&(0xff==(HI253_yuv_sensor_initial_setting_24M_MCLK_info[iEcount].data))));iEcount++)
		{
			CamWriteCmosSensor(HI253_yuv_sensor_initial_setting_24M_MCLK_info[iEcount].address, HI253_yuv_sensor_initial_setting_24M_MCLK_info[iEcount].data);
		}
		HI253Sensor.preview_pclk = 480;
	}
	else
	{
#ifdef __HI253_DEBUG_TRACE__
		kal_wap_trace(MOD_ENG, TRACE_INFO, "NOT SUPPOT THE MCLK");
#endif
		ASSERT(0);
	}
}                                  

/*************************************************************************
* FUNCTION
*    HI253HalfAdjust
*
* DESCRIPTION
*    This function Dividend / Divisor and use round-up.
*
* PARAMETERS
*    Dividend
*    Divisor
*
* RETURNS
*    [Dividend / Divisor]
*
* LOCAL AFFECTED
*
*************************************************************************/
__inline static kal_uint32 HI253HalfAdjust(kal_uint32 Dividend, kal_uint32 Divisor)
{
  return (Dividend * 2 + Divisor) / (Divisor * 2); /* that is [Dividend / Divisor + 0.5]*/
}

/*************************************************************************
* FUNCTION
*    HI253SetShutterStep
*
* DESCRIPTION
*    This function is to calculate & set shutter step register .
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
static void HI253SetShutterStep(void)
{
}

/*************************************************************************
* FUNCTION
*    HI253SetFrameCount
*
* DESCRIPTION
*    This function is to set frame count register .
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
/*HAL_modify_working*/static void HI253SetFrameCount(void)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __HI253_DEBUG_TRACE__
/* under construction !*/
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
  #endif
}

/*************************************************************************
* FUNCTION
*	HI253_PV_setting
*
* DESCRIPTION
*	This function apply the preview mode setting, normal the preview size is 1/4 of full size.
*	Ex. 2M (1600 x 1200)
*	Preview: 800 x 600 (Use sub-sample or binning to acheive it)
*	Full Size: 1600 x 1200 (Output every effective pixels.)
*
* PARAMETERS
*	1. image_sensor_exposure_window_struct : Set the grab start x,y and width,height.
*	2. image_sensor_config_struct : Current operation mode.
*
* RETURNS
*	None
*
*************************************************************************/
static void HI253_PV_setting(void)
{
	#if 1
	kal_uint32 HI253_Max_FrameRate, Clock_Divider, HI253_PLL;
	//kal_uint32 HI253_HWidth, HI253_HBLANK, HI253_VLine, HI253_VSYNC;//the same to init reg
	kal_uint32 HI253_OPCLK;
	kal_uint32 HI253_EXP_FREQUENCY, HI253_EXP120, HI253_EXP100;
	kal_uint32 HI253_EXPMAX, HI253_EXPFIX, HI253_EXPTIME;/*, HI253_EXPFIX2, HI253_EXPFIX3;*/
	kal_uint32 temp_INT_cal;//for get INT value
	kal_uint32 HI253_line_length;
	kal_uint32 HI253_BLC_TIME_TH_ONOFF;
	kal_uint32 HI253_EXPMIN, HI253_EXP_LIMIT, HI253_EXP_UNIT;
	
	CamWriteCmosSensor(0x03, 0x00);
	CamWriteCmosSensor(0x10, 0x13); 
	CamWriteCmosSensor(0x12,CamReadCmosSensor(0x12)&0xFC);

	//modify preview start x, y
//	CamWriteCmosSensor(0x03, 0x00);
	CamWriteCmosSensor(0x20, 0x00); // WINROWH
	CamWriteCmosSensor(0x21, 0x04); // WINROWL
	CamWriteCmosSensor(0x22, 0x00); // WINCOLH
	CamWriteCmosSensor(0x23, 0x07); // WINCOLL

	HI253Sensor.pv_dummy_pixels = 424;
	if(HI253Sensor.mclk == 240)
		HI253Sensor.pv_dummy_lines = 8;
	else
		HI253Sensor.pv_dummy_lines = 62;
	Clock_Divider = 1, HI253_PLL = 2;

	CamWriteCmosSensor(0x3f, 0x00);
	CamWriteCmosSensor(0x40, (HI253Sensor.pv_dummy_pixels>>8)&0xff); // HBLANK=424
	CamWriteCmosSensor(0x41, (HI253Sensor.pv_dummy_pixels>>0)&0xff);
	CamWriteCmosSensor(0x42, (HI253Sensor.pv_dummy_lines>>8)&0xff); // VSYNC=62
	CamWriteCmosSensor(0x43, (HI253Sensor.pv_dummy_lines>>0)&0xff);
	
	CamWriteCmosSensor(0x3f, 0x02);

	//Page12
	CamWriteCmosSensor(0x03, 0x12); //Function
	CamWriteCmosSensor(0x20, 0x00);
	CamWriteCmosSensor(0x21, 0x00);
	CamWriteCmosSensor(0x90, 0x00);  
	//Page13
	CamWriteCmosSensor(0x03, 0x13); //Function
	CamWriteCmosSensor(0x80, 0x00); //Function
	
	/*
	EXPMIN=(H-width+HBLANK)/4
	EXP100=(H-width+HBLANK)*INT[OPCLK/(H-width+HBLANK)/100Hz]/8
	EXP120=(H-width+HBLANK)*INT[OPCLK/(H-width+HBLANK)/120Hz]/8
	EXPUNIT=(H-width+HBLANK)/4*/
	
	HI253_line_length = HI253_PV_PERIOD_PIXEL_NUMS + HI253Sensor.pv_dummy_pixels;
	HI253_OPCLK = HI253Sensor.mclk*100000*HI253_PLL*1/Clock_Divider*1/2;//here, it is 26000000

	temp_INT_cal = HI253_OPCLK/HI253_line_length/100;
	HI253_EXP100 = HI253_line_length*temp_INT_cal/8;
	temp_INT_cal = HI253_OPCLK/HI253_line_length/120;
	HI253_EXP120 = HI253_line_length*temp_INT_cal/8;
	HI253_EXP_UNIT = HI253_EXPMIN = HI253_line_length/4;

#ifdef __HI253_DEBUG_TRACE__
	kal_wap_trace(MOD_ENG, TRACE_INFO, "HI253_EXP100=%x", HI253_EXP100);
	kal_wap_trace(MOD_ENG, TRACE_INFO, "HI253_EXP120=%x", HI253_EXP120);
	kal_wap_trace(MOD_ENG, TRACE_INFO, "HI253_EXP_UNIT=%x", HI253_EXP_UNIT);
	kal_wap_trace(MOD_ENG, TRACE_INFO, "HI253_EXPMIN=%x", HI253_EXPMIN);
	kal_wap_trace(MOD_ENG, TRACE_INFO, "HI253Sensor.pv_shutter=%x", HI253Sensor.pv_shutter);
	kal_wap_trace(MOD_ENG, TRACE_INFO, "HI253Sensor.pv_sensor_gain=%x", HI253Sensor.pv_sensor_gain);
#endif
	
	CamWriteCmosSensor(0x03, 0x20);

	CamWriteCmosSensor(0x83, HI253Sensor.pv_shutter >> 16);
	CamWriteCmosSensor(0x84, (HI253Sensor.pv_shutter >> 8) & 0x000000FF);
	CamWriteCmosSensor(0x85, HI253Sensor.pv_shutter & 0x000000FF);
	
	CamWriteCmosSensor(0x86, (HI253_EXPMIN>>8)&0xff);//EXPMIN
	CamWriteCmosSensor(0x87, (HI253_EXPMIN>>0)&0xff);
	CamWriteCmosSensor(0x8b, (HI253_EXP100>>8)&0xff);//EXP100
	CamWriteCmosSensor(0x8c, (HI253_EXP100>>0)&0xff);
	CamWriteCmosSensor(0x8d, (HI253_EXP120>>8)&0xff);//EXP120
	CamWriteCmosSensor(0x8e, (HI253_EXP120>>0)&0xff);

	//not difference 24M and 26M
	CamWriteCmosSensor(0x9c, (HI253_PV_EXPOSURE_LIMITATION>>8)&0xff);//EXP Limit
	CamWriteCmosSensor(0x9d, (HI253_PV_EXPOSURE_LIMITATION>>0)&0xff);
	
	CamWriteCmosSensor(0x9e, (HI253_EXP_UNIT>>8)&0xff);//EXP Unit
	CamWriteCmosSensor(0x9f, (HI253_EXP_UNIT>>0)&0xff);

	if(HI253Sensor.mclk == 260)
		HI253Sensor.preview_pclk = 520;
	else
		HI253Sensor.preview_pclk = 480;
		
	HI253_op_state.is_PV_mode = KAL_TRUE;
	#endif
} /* HI253_PV_setting */

/*************************************************************************
* FUNCTION
*	HI253_CAP_setting
*
* DESCRIPTION
*	This function apply the full size mode setting.
*	Ex. 2M (1600 x 1200)
*	Preview: 800 x 600 (Use sub-sample or binning to acheive it)
*	Full Size: 1600 x 1200 (Output every effective pixels.)
*
* PARAMETERS
*	1. image_sensor_exposure_window_struct : Set the grab start x,y and width,height.
*	2. image_sensor_config_struct : Current operation mode.
*
* RETURNS
*	None
*
*************************************************************************/
static void HI253_CAP_setting(void)
{
	#if 1
	kal_uint16 temp = 0;

	// 1600*1200   
	CamWriteCmosSensor(0x03,0x00);
	
	CamWriteCmosSensor(0x10,0x00);//change size to 1600*1200
	// CLK_DIV_REG=(CamReadCmosSensor(0x12)&0xFC);    // don't divide,PCLK=48M 采取插dummy的方式，不使用分频
	
	CamWriteCmosSensor(0x3f,0x00);
	
	//Page12
	CamWriteCmosSensor(0x03, 0x12); //Function
	CamWriteCmosSensor(0x20, 0x0f);
	CamWriteCmosSensor(0x21, 0x0f);
	CamWriteCmosSensor(0x90, 0x5d);  
	
	//Page13
	CamWriteCmosSensor(0x03, 0x13); //Function
	CamWriteCmosSensor(0x80, 0xfd); //Function
	
	/*capture 1600*1200 start x, y*/
	CamWriteCmosSensor(0x03, 0x00);
	CamWriteCmosSensor(0x20, 0x00); // WINROWH
	CamWriteCmosSensor(0x21, 0x0f); // WINROWL
	CamWriteCmosSensor(0x22, 0x00); // WINCOLH
	CamWriteCmosSensor(0x23, 0x19); // WINCOLL
	
	HI253Sensor.capture_pclk = 480;
	HI253_op_state.is_PV_mode = KAL_FALSE;
	#endif
} /* HI253_CAP_setting */



#ifdef __ZERO_SHUTTER_DELAY_SUPPORT__
static void HI253_FullPV_setting(P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In)
{
	#if 1
		////
		kal_uint8 StartX = 0, StartY = 1;

		volatile kal_uint32 shutter = 0, temp_reg = 0;
		kal_uint32 prev_line_len = 0;
		kal_uint32 cap_line_len = 0;
		kal_uint8 imask=0,CLK_DIV_REG=0;

		kal_uint32 HI253_Max_FrameRate, Clock_Divider, HI253_PLL;
		kal_uint32 HI253_HWidth, HI253_HBLANK, HI253_VLine, HI253_VSYNC;//the same to init reg
		kal_uint32 HI253_OPCLK;
		kal_uint32 HI253_EXP_FREQUENCY, HI253_EXP120, HI253_EXP100;
		kal_uint32 temp_INT_cal;//for get INT value
		kal_uint32 HI253_line_length;
		kal_uint32 HI253_EXPMIN, HI253_EXP_LIMIT, HI253_EXP_UNIT;


//
	  {    /* FULL Size Capture Mode */

		  CamWriteCmosSensor(0x01,(CamReadCmosSensor(0x01)|0x01));//sensor sleep in for fast capture
		  HI253_CAP_setting();
		  CLK_DIV_REG=(CamReadCmosSensor(0x12)&0xFC);	  // don't divide,PCLK=48M
  
		  {
		#if ((defined(DRV_ISP_6238_SERIES) || defined(DRV_ISP_6276_SERIES)))
			  if (In->ZoomFactor >= 400)
			  {
				  imask = 1;
				  Clock_Divider = 2, HI253_PLL = 2;
				  HI253Sensor.capture_pclk = HI253Sensor.mclk*HI253_PLL*1/Clock_Divider;
				  
				  HI253Sensor.cap_dummy_pixels = 360;
				  HI253Sensor.cap_dummy_lines = 20;
			  }
			  else if (In->ZoomFactor >= 200)
			  {
				  imask = 1;
				  Clock_Divider = 2, HI253_PLL = 2;
				  HI253Sensor.capture_pclk = HI253Sensor.mclk*HI253_PLL*1/Clock_Divider;
				  
				  HI253Sensor.cap_dummy_pixels = 360;	/*If Capture fail, you can add this dummy*/
				  HI253Sensor.cap_dummy_lines = 20;
			  }
			  else
			  {
				  imask = 0;
				  Clock_Divider = 1, HI253_PLL = 2;
				  HI253Sensor.capture_pclk = HI253Sensor.mclk*HI253_PLL*1/Clock_Divider;
				  
				  HI253Sensor.cap_dummy_pixels =360;  /*If Capture fail, you can add this dummy*/
				  HI253Sensor.cap_dummy_lines = 104;
			  }
		#elif (defined(DRV_ISP_6235_SERIES))
			  /* If Capture fail or system hang when capture, you can add dummy pixels for each step.  */
			  if (In->ZoomFactor >= (ISP_DIGITAL_ZOOM_INTERVAL * 3)) // DZ >= 3X
			  {
				  imask = 1;
				  Clock_Divider = 2, HI253_PLL = 2;
				  HI253Sensor.capture_pclk = HI253Sensor.mclk*HI253_PLL*1/Clock_Divider;
				  
				  HI253Sensor.cap_dummy_pixels = 360;
				  HI253Sensor.cap_dummy_lines = 20;
			  }
			  else if (In->ZoomFactor >= (ISP_DIGITAL_ZOOM_INTERVAL * 2)) // DZ >= 2x
			  {
				  imask = 1;
				  Clock_Divider = 2, HI253_PLL = 2;
				  HI253Sensor.capture_pclk = HI253Sensor.mclk*HI253_PLL*1/Clock_Divider;
				  
				  HI253Sensor.cap_dummy_pixels = 360;
				  HI253Sensor.cap_dummy_lines = 20;
			  }
			  else if (In->ZoomFactor > (ISP_DIGITAL_ZOOM_INTERVAL * 1)) // DZ > 1x
			  {
				  imask = 1;Clock_Divider = 2, HI253_PLL = 2;
				  HI253Sensor.capture_pclk = HI253Sensor.mclk*HI253_PLL*1/Clock_Divider; 
				  
				  HI253Sensor.cap_dummy_pixels = 360;
				  HI253Sensor.cap_dummy_lines = 20;
			  }
			  else 
			  {
				  imask = 0;
				  Clock_Divider = 1, HI253_PLL = 2;
				  HI253Sensor.capture_pclk = HI253Sensor.mclk*HI253_PLL*1/Clock_Divider;
				  
				  HI253Sensor.cap_dummy_pixels = 360;
				  HI253Sensor.cap_dummy_lines = 104;
			  }
		#endif
		  }
		  {
			  CLK_DIV_REG = CLK_DIV_REG|imask;
			  CamWriteCmosSensor(0x03, 0x00); 
			  CamWriteCmosSensor(0x12,CLK_DIV_REG);
			  
			  /*
			  EXPMIN=(H-width+HBLANK)/4
			  EXP100=(H-width+HBLANK)*INT[OPCLK/(H-width+HBLANK)/100Hz]/8
			  EXP120=(H-width+HBLANK)*INT[OPCLK/(H-width+HBLANK)/120Hz]/8
			  EXPUNIT=(H-width+HBLANK)/4*/
			  
			  cap_line_len = HI253_FULL_PERIOD_PIXEL_NUMS + HI253Sensor.cap_dummy_pixels;
			  HI253_OPCLK = HI253Sensor.mclk*100000*HI253_PLL*1/Clock_Divider*1/2;//here, it is 26000000
		  
			  temp_INT_cal = HI253_OPCLK/cap_line_len/100;
			  HI253_EXP100 = cap_line_len*temp_INT_cal/8;
			  temp_INT_cal = HI253_OPCLK/cap_line_len/120;
			  HI253_EXP120 = cap_line_len*temp_INT_cal/8;
			  HI253_EXP_UNIT = HI253_EXPMIN = cap_line_len/4;
			  
			  CamWriteCmosSensor(0x03, 0x20);
			  CamWriteCmosSensor(0x86, (HI253_EXPMIN>>8)&0xff);//EXPMIN
			  CamWriteCmosSensor(0x87, (HI253_EXPMIN>>0)&0xff);
			  CamWriteCmosSensor(0x8b, (HI253_EXP100>>8)&0xff);//EXP100
			  CamWriteCmosSensor(0x8c, (HI253_EXP100>>0)&0xff);
			  CamWriteCmosSensor(0x8d, (HI253_EXP120>>8)&0xff);//EXP120
			  CamWriteCmosSensor(0x8e, (HI253_EXP120>>0)&0xff);
		  
			  //not difference 24M and 26M
			  CamWriteCmosSensor(0x9c, (HI253_FULL_EXPOSURE_LIMITATION>>8)&0xff);//EXP Limit
			  CamWriteCmosSensor(0x9d, (HI253_FULL_EXPOSURE_LIMITATION>>0)&0xff);
			  
			  CamWriteCmosSensor(0x9e, (HI253_EXP_UNIT>>8)&0xff);//EXP Unit
			  CamWriteCmosSensor(0x9f, (HI253_EXP_UNIT>>0)&0xff);
		  }
		  
		  HI253SetDummy(HI253Sensor.cap_dummy_pixels, HI253Sensor.cap_dummy_lines);
		  
	/*	  prev_line_len = HI253_PV_PERIOD_PIXEL_NUMS + HI253Sensor.pv_dummy_pixels;
		  cap_line_len = HI253_FULL_PERIOD_PIXEL_NUMS + HI253Sensor.cap_dummy_pixels;
		  shutter = shutter>>imask;
		  if(shutter<1)
			  shutter = 1;
  
		  HI253WriteShutter(shutter);*/
	  }
  
	  //sensor sleep out
	  CamWriteCmosSensor(0x01,(CamReadCmosSensor(0x01)&0xfe));//sensor sleep out

	if(HI253Sensor.mclk == 260)
		HI253Sensor.preview_pclk = 520/Clock_Divider;
	else
		HI253Sensor.preview_pclk = 480/Clock_Divider;
		
	HI253_op_state.is_PV_mode = KAL_TRUE;
	#endif
} /* HI253_PV_setting */
#endif



/*************************************************************************
* FUNCTION
*	HI253_Set_Video_Frame_Rate
*
* DESCRIPTION
*	This function set the sensor output frmae to target frame and fix the frame rate for 
*	video encode.
*
* PARAMETERS
*	1. kal_uint32 : Target frame rate to fixed.
*
* RETURNS
*	None
*
*************************************************************************/
static void HI253_Set_Video_Frame_Rate(kal_uint32 min_frame_rate, kal_uint32 max_frame_rate)
{
	#if 1
	/*The real frame rate need /10*/
	kal_uint32 HI253_Max_FrameRate, Clock_Divider=1, HI253_PLL=2;
	kal_uint32 HI253_HWidth, HI253_HBLANK, HI253_VLine, HI253_VSYNC;//the same to init reg
	kal_uint32 HI253_OPCLK;
	kal_uint32 HI253_EXP_FREQUENCY, HI253_EXP120, HI253_EXP100;
	kal_uint32 HI253_EXPMAX, HI253_EXPFIX, HI253_EXPTIME;/*, HI253_EXPFIX2, HI253_EXPFIX3;*/
	kal_uint32 temp_INT_cal;//for get INT value
	kal_uint32 HI253_line_length;
	kal_uint32 HI253_BLC_TIME_TH_ONOFF; 
	kal_uint32 HI253_FIX_FRAMERATE_FLAG = 0;
	/*
	OPCLK=(PLL*Clock Divider*1/2)*MCLK
	PCLK=(PLL*Clock Divider*Sub-Sample*(preview mode2))*MCLK//preview1=1, preview2=2
	To=1/OPCLK

	H-width=1640 for full size and preview1, 824 for preview2
	V-line=1248 for full size, 632 for preview1 and preview2
	Frame Length=(H-width+HBLANK)*(V-line+VSYNC)*To

	So, maximum frame rate=1s/Frame Length

	EXP100=(H-width+HBLANK)*INT[OPCLK/(H-width+HBLANK)/100Hz]/8 //(1/100s)10 ms 包含有多少个 8倍的pixel（一个pixel需要两个pclk）（pixel的总个数必须能够被line length 整除）（曝光单位是8个pixel为单位的）
	EXP120=(H-width+HBLANK)*INT[OPCLK/(H-width+HBLANK)/120Hz]/8 
	EXPUNIT=(H-width+HBLANK)/4

	EXPMAX = EXP100*INT(100/min_frame_rate), minimum frame rate should be defined by user //min fps为5或10
	EXPTIME = EXP100*INT(100/init_frame_rate）//这里init frame rate 是30，在一帧含有base shutter，能够有的最大曝光为多少个 8倍的pixel
	EXPMIN=(H-width+HBLANK)/4

	EXPFIX = INT( ((1/framerate)*OPCLK )  / line_length )  *line_length/8
	//fixed frame rate should be defined by user and not above maximum frame rate 
	//按指定的fix fps 来计算时，一帧所含的 8倍pixel的个数
	
	BLC_TIME_TH_ON&OFF = DEC 2 HEX	[100(120)Hz/MIN_FRAMERATE]
	*/
	if(min_frame_rate==max_frame_rate)
		HI253_FIX_FRAMERATE_FLAG = 1;

	//please note: current max frame rate is 30.02
	CamWriteCmosSensor(0x03, 0x00); // Page 0
	HI253_HBLANK = (CamReadCmosSensor(0x40)<<8) | (CamReadCmosSensor(0x41));//0x01a8
	HI253_VSYNC = (CamReadCmosSensor(0x42)<<8) | (CamReadCmosSensor(0x43));//0x003e

	HI253_line_length = HI253_PV_PERIOD_PIXEL_NUMS + HI253_HBLANK;
	HI253_OPCLK = HI253Sensor.mclk*100000*HI253_PLL*1/Clock_Divider*1/2;//here, it is 26000000
	HI253_Max_FrameRate = (HI253Sensor.mclk*100000*1*HI253_PLL*1/Clock_Divider*1/2)/(HI253_line_length*(HI253_PV_PERIOD_LINE_NUMS+HI253_VSYNC));

#ifdef __HI253_DEBUG_TRACE__
	kal_wap_trace(MOD_ENG, TRACE_INFO, "HI253_Set_Video_Frame_Rate max=%d", max_frame_rate);
	kal_wap_trace(MOD_ENG, TRACE_INFO, "HI253_Set_Video_Frame_Rate min=%d", min_frame_rate);
	kal_wap_trace(MOD_ENG, TRACE_INFO, "HI253_Max_FrameRate=%d", HI253_Max_FrameRate);
#endif
	if(max_frame_rate>(HI253_Max_FrameRate*10))
		ASSERT(0);
	
	/*EXPTIME = EXP100*INT(100/frame_rate) */
	CamWriteCmosSensor(0x03, 0x20);
	HI253_EXP_FREQUENCY = (CamReadCmosSensor(0x10)&0x10);//get frequency
	if(HI253_EXP_FREQUENCY)//100Hz
	{
		HI253_EXP100 = (CamReadCmosSensor(0x8b)<<8) | (CamReadCmosSensor(0x8c));//0x7ec0
		temp_INT_cal = 100*10/max_frame_rate;//note: INT(100Hz/frameRate)
		HI253_EXPTIME = HI253_EXP100*temp_INT_cal;

		temp_INT_cal = 100*10/min_frame_rate;//note: INT(100Hz/frameRate)
		HI253_EXPMAX = HI253_EXP100*temp_INT_cal;
	}
	else//120Hz
	{
		HI253_EXP120 = (CamReadCmosSensor(0x8d)<<8) | (CamReadCmosSensor(0x8e));//0x696c
		temp_INT_cal = 120*10/max_frame_rate;//note: INT(120Hz/frameRate)
		HI253_EXPTIME = HI253_EXP120*temp_INT_cal;

		temp_INT_cal = 120*10/min_frame_rate;//note: INT(120Hz/frameRate)
		HI253_EXPMAX = HI253_EXP120*temp_INT_cal;
	}

//	/*EXPMAX = EXPTIME = EXP100*INT(100/frame_rate) */
//	HI253_EXPMAX = HI253_EXPTIME;

	if(HI253_FIX_FRAMERATE_FLAG)
	{
		/* EXPFIX = INT( ((1/framerate)*OPCLK )  / line_length )  *line_length/8 */
		temp_INT_cal = (HI253_OPCLK *1*10/max_frame_rate)/ HI253_line_length;
		HI253_EXPFIX = temp_INT_cal*HI253_line_length/8;
	}
	/*BLC and DC DC is same value
	BLC_TIME_TH_ON&OFF = DEC 2 HEX	[100(120)Hz/MIN_FRAMERATE]*/
	if(HI253_EXP_FREQUENCY)//100 Hz
	{
		HI253_BLC_TIME_TH_ONOFF = 100*10/min_frame_rate;
	}
	else//120Hz
	{
		HI253_BLC_TIME_TH_ONOFF = 120*10/min_frame_rate;
	}

#ifdef __HI253_DEBUG_TRACE__
	kal_wap_trace(MOD_ENG, TRACE_INFO, "HHI253_EXPTIME=%x", HI253_EXPTIME);
	kal_wap_trace(MOD_ENG, TRACE_INFO, "HHI253_EXPMAX=%x", HI253_EXPMAX);
	kal_wap_trace(MOD_ENG, TRACE_INFO, "HI253_EXPFIX=%x", HI253_EXPFIX);
	kal_wap_trace(MOD_ENG, TRACE_INFO, "HI253_BLC_TIME_TH_ONOFF=%x", HI253_BLC_TIME_TH_ONOFF);
#endif	
	/*DISP_NAME = "Video NormalMode fixed 20fps"
	DISP_WIDTH = 800
	DISP_HEIGHT = 600
	DISP_FORMAT = YUV422
	DISP_DATAORDER = YUYV
	MCLK = 26.00
	PLL = 2.00
	BEGIN*/
	CamWriteCmosSensor(0x01, 0xf9); // Sleep ON
	CamWriteCmosSensor(0x03, 0x00); // Page 0
//	CamWriteCmosSensor(0x11, 0x94); // Fixed frame rate ON
	if(HI253_FIX_FRAMERATE_FLAG)
	{
		CamWriteCmosSensor(0x11,(CamReadCmosSensor(0x11)|0x04));// Fixed frame rate ON, not modify mirror para
	}
	else
	{
		CamWriteCmosSensor(0x11,(CamReadCmosSensor(0x11)&0xfb));// Fixed frame rate OFF, not modify mirror para
	}	
	CamWriteCmosSensor(0x90, HI253_BLC_TIME_TH_ONOFF); // BLC_TIME_TH_ON
	CamWriteCmosSensor(0x91, HI253_BLC_TIME_TH_ONOFF); // BLC_TIME_TH_OFF
	CamWriteCmosSensor(0x92, 0x78); // BLC_AG_TH_ON
	CamWriteCmosSensor(0x93, 0x70); // BLC_AG_TH_OFF
	CamWriteCmosSensor(0x03, 0x02); // Page 2
	CamWriteCmosSensor(0xd4, HI253_BLC_TIME_TH_ONOFF); // DCDC_TIME_TH_ON
	CamWriteCmosSensor(0xd5, HI253_BLC_TIME_TH_ONOFF); // DCDC_TIME_TH_OFF
	CamWriteCmosSensor(0xd6, 0x78); // DCDC_AG_TH_ON
	CamWriteCmosSensor(0xd7, 0x70); // DCDC_AG_TH_OFF
	
	CamWriteCmosSensor(0x03, 0x20); // Page 20
	//CamWriteCmosSensor(0x10, 0x1c); // AE OFF
	CamWriteCmosSensor(0x10,(CamReadCmosSensor(0x10)&0x7f));// AE ON BIT 7
	CamWriteCmosSensor(0x18, 0x38); // AE Reset ON
	if(HI253_FIX_FRAMERATE_FLAG)
	{
		CamWriteCmosSensor(0x11, 0x00); // 0x35 for fixed frame rate
		CamWriteCmosSensor(0x2a, 0x03); // 0x35 for fixed frame rate
		CamWriteCmosSensor(0x2b, 0x35); // 0x35 for fixed frame rate, 0x34 for dynamic frame rate
	}
	else
	{
		CamWriteCmosSensor(0x11, 0x1c); // 0x35 for fixed frame rate
		CamWriteCmosSensor(0x2a, 0xf0); // 0x35 for fixed frame rate
		CamWriteCmosSensor(0x2b, 0x34); // 0x35 for fixed frame rate, 0x34 for dynamic frame rate
	}
	
	CamWriteCmosSensor(0x83, (HI253_EXPTIME>>16)&(0xff)); // EXPTIMEH max fps
	CamWriteCmosSensor(0x84, (HI253_EXPTIME>>8)&(0xff)); // EXPTIMEM
	CamWriteCmosSensor(0x85, (HI253_EXPTIME>>0)&(0xff)); // EXPTIMEL

	CamWriteCmosSensor(0x88, (HI253_EXPMAX>>16)&(0xff)); // EXPMAXH min fps
	CamWriteCmosSensor(0x89, (HI253_EXPMAX>>8)&(0xff)); // EXPMAXM
	CamWriteCmosSensor(0x8a, (HI253_EXPMAX>>0)&(0xff)); // EXPMAXL

	if(HI253_FIX_FRAMERATE_FLAG)
	{
		CamWriteCmosSensor(0x91, (HI253_EXPFIX>>16)&(0xff)); //EXP Fix30 fps
		CamWriteCmosSensor(0x92, (HI253_EXPFIX>>8)&(0xff));
		CamWriteCmosSensor(0x93, (HI253_EXPFIX>>0)&(0xff));
	}
	
	CamWriteCmosSensor(0x01, 0xf8); // Sleep OFF
	//CamWriteCmosSensor(0x10, 0x9c); // AE ON 50Hz
	CamWriteCmosSensor(0x10,(CamReadCmosSensor(0x10)|0x80));// AE ON BIT 7
	CamWriteCmosSensor(0x18, 0x30); // AE Reset OFF
	
	HI253Sensor.video_frame_rate = min_frame_rate;
	#endif
}

/*************************************************************************
* FUNCTION
*	HI253_night_mode
*
* DESCRIPTION
*	This function enable sensor night mode or normal mode. In low light condition, to preview
*	it need more sensor gain to make the image more brightness, and lower frame rate to get
*	more exposure value and get better image quality.
*
* PARAMETERS
*	1. kal_bool : KAL_TRUE - night mode, KAL_FALSE - normal mode.
*
* RETURNS
*	None
*
*************************************************************************/
static void HI253NightMode(kal_bool enable)
{
	#if 1
	kal_uint32 video_frame_rate = 0;

	/* Get the video frame rate from frame rate lut table. */
	//video_frame_rate = HI253_Get_Video_Frame_Rate( \
	//			enable, HI253_op_state.video_target_width, HI253_op_state.video_target_height);

#ifdef __HI253_DEBUG_TRACE__
	kal_wap_trace(MOD_ENG, TRACE_INFO, "HI253_night, enable=%d, video_frame_rate=%d, Size %d x %d", \
		enable, video_frame_rate, HI253_op_state.video_target_width, HI253_op_state.video_target_height);
#endif
	//return;
	if (enable) 		/* Night Mode */
	{
		if (HI253Sensor.VideoMode == KAL_TRUE)	/* Video */
		{
			HI253_Set_Video_Frame_Rate(HI253Sensor.Fps, HI253Sensor.Fps);
		}
		else 										/* Camera */
		{
			/*DISP_NAME = "Capture NightMode Dynamic 5~30fps"*/
			HI253_Set_Video_Frame_Rate(HI253Sensor.Fps, 300);
		}      
	}
	else  				/* Normal Mode */
	{
		if (HI253Sensor.VideoMode == KAL_TRUE)	/* Video */
		{
			HI253_Set_Video_Frame_Rate(HI253Sensor.Fps, HI253Sensor.Fps);
		}
		else										/* Camera */
		{
			/*DISP_NAME = "Capture NormalMode Dynamic 10~30fps"*/
			HI253_Set_Video_Frame_Rate(HI253Sensor.Fps, 300);
		}
	}

	HI253_op_state.night_mode = enable;
	#endif
}    /* HI253_night_mode */

/*************************************************************************
* FUNCTION
*    HI253SceneMode
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
static MM_ERROR_CODE_ENUM HI253SceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    HI253NightMode(Enable);
  }
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    HI253WriteBlank
*
* DESCRIPTION
*    This function write Hblank and Vblank.
*
* PARAMETERS
*    Hblank
*    Vblank
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
/*HAL_modify_working*/static void HI253WriteBlank(kal_uint16 Hblank,kal_uint16 Vblank)
{
 /*************************************    
  *   Register :0x20 - 0x22    
  *  0x20  [5:4]:HBANK[9:8]; 0x20  [1:0]:VBANK[9:8]
  *  0x21 HBANK[7:0]
  *  0x22 VBANK[7:0]   
  ***************************************/
#if 0
#ifdef __HI253_DEBUG_TRACE__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

/*************************************************************************
* FUNCTION
*    HI253CalFps
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
/*HAL_modify_working*/static void HI253CalFps(void)
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
#ifdef __HI253_DEBUG_TRACE__
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif
}

/*************************************************************************
* FUNCTION
*    HI253SetHVMirror
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
static void HI253SetHVMirror(kal_uint8 Mirror)
{
  kal_uint8 Ctrl = 0;
#ifdef __HI253_DEBUG_TRACE__
  kal_wap_trace(MOD_ENG,TRACE_INFO,"Mirror:%d",Mirror);
#endif 
  CamWriteCmosSensor(0x03,0x00); //bank 0	  
  Ctrl = (CamReadCmosSensor(0x11) & 0xfc);	  
  switch (Mirror)
  {
	  case IMAGE_SENSOR_MIRROR_NORMAL:
		  Ctrl |= 0x00;
		  break;
	  case IMAGE_SENSOR_MIRROR_H:
		  Ctrl |= 0x01;
		  break;
	  case IMAGE_SENSOR_MIRROR_V:
		  Ctrl |= 0x02;
		  break;
	  case IMAGE_SENSOR_MIRROR_HV:
		  Ctrl |= 0x03;
		  break;
	  default:
		  ASSERT(0);
  }
  CamWriteCmosSensor(0x11, Ctrl); 
}

/*************************************************************************
* FUNCTION
*    HI253Ev
*
* DESCRIPTION
*    HI253 EV setting.
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
static MM_ERROR_CODE_ENUM HI253Ev(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    //kal_uint8 EvTemp = 0x00;
#ifdef __HI253_DEBUG_TRACE__
    kal_wap_trace(MOD_ENG,TRACE_INFO, "EV:%d", In->FeatureSetValue);
#endif
	
	CamWriteCmosSensor(0x03,0x10);
	CamWriteCmosSensor(0x12,(CamReadCmosSensor(0x12)|0x10));//make sure the Yoffset control is opened.

    switch (In->FeatureSetValue)
	{
		case CAM_EV_NEG_4_3:							/* EV -2 */
			CamWriteCmosSensor(0x40,0xe0);
			gBrightnessValue = 0xe0;
			break;
		case CAM_EV_NEG_3_3:							/* EV -1.5 */
			CamWriteCmosSensor(0x40,0xc8);
			gBrightnessValue = 0xc8;
			break;
		case CAM_EV_NEG_2_3:							/* EV -1 */
			CamWriteCmosSensor(0x40,0xb0);
			gBrightnessValue = 0xb0;
			break;
		case CAM_EV_NEG_1_3:							/* EV -0.5 */
			CamWriteCmosSensor(0x40,0x98);
			gBrightnessValue = 0x98;
			break;
		case CAM_EV_ZERO:								/* EV 0 */
			CamWriteCmosSensor(0x40,0x85);
			gBrightnessValue = 0x85;
			break;
		case CAM_EV_POS_1_3:							/* EV +0.5 */
			CamWriteCmosSensor(0x40,0x18);
			gBrightnessValue = 0x18;
			break;
		case CAM_EV_POS_2_3:							/* EV +1 */
			CamWriteCmosSensor(0x40,0x30);
			gBrightnessValue = 0x30;
			break;
		case CAM_EV_POS_3_3:							/* EV +1.5 */
			CamWriteCmosSensor(0x40,0x48);
			gBrightnessValue = 0x48;
			break;
		case CAM_EV_POS_4_3:							/* EV +2 */
			CamWriteCmosSensor(0x40,0x60);
			gBrightnessValue = 0x60;
			break;
		default:
			break;
	}
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HI253Contrast
*
* DESCRIPTION
*    HI253 Contrast setting.
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
static MM_ERROR_CODE_ENUM HI253Contrast(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        const P_CAL_FEATURE_TYPE_ENUM_STRUCT Contrast = &Out->FeatureInfo.FeatureEnum;

        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
        // TODO: add supported contrast enum here
        Contrast->IsSupport = KAL_TRUE;
        Contrast->ItemCount = 3;
        Contrast->SupportItem[0] = CAM_CONTRAST_HIGH;
        Contrast->SupportItem[1] = CAM_CONTRAST_MEDIUM;
        Contrast->SupportItem[2] = CAM_CONTRAST_LOW;
    }
    else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
    {
        // TODO: adjust contrast here
        switch (In->FeatureSetValue)
        {
        case CAM_CONTRAST_HIGH:
            CamWriteCmosSensor(0x03, 0x10);
            CamWriteCmosSensor(0x48, 0x8A);
            break;
        case CAM_CONTRAST_MEDIUM:
            CamWriteCmosSensor(0x03, 0x10);
            CamWriteCmosSensor(0x48, 0x80);
            break;
        case CAM_CONTRAST_LOW:
            CamWriteCmosSensor(0x03, 0x10);
            CamWriteCmosSensor(0x48, 0x76);
            break;
        default:
            return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        }
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   HI253Saturation
*
* DESCRIPTION
*   Saturation setting.
*
* PARAMETERS
*   In, Out
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM HI253Saturation(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        const P_CAL_FEATURE_TYPE_ENUM_STRUCT Saturation = &Out->FeatureInfo.FeatureEnum;

        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
        // TODO: add supported saturation enum here
        Saturation->IsSupport = KAL_TRUE;
        Saturation->ItemCount = 3;
        Saturation->SupportItem[0] = CAM_SATURATION_HIGH;
        Saturation->SupportItem[1] = CAM_SATURATION_MEDIUM;
        Saturation->SupportItem[2] = CAM_SATURATION_LOW;
    }
    else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
    {
        // TODO: adjust saturation here
        switch (In->FeatureSetValue)
        {
        case CAM_SATURATION_HIGH:
            CamWriteCmosSensor(0x03, 0x10);
            CamWriteCmosSensor(0x61, 0x86);
	        CamWriteCmosSensor(0x62, 0x86);
            break;
        case CAM_SATURATION_MEDIUM:
            CamWriteCmosSensor(0x03, 0x10);
            CamWriteCmosSensor(0x61, 0x76);
	        CamWriteCmosSensor(0x62, 0x76);
            break;
        case CAM_SATURATION_LOW:
            CamWriteCmosSensor(0x03, 0x10);
            CamWriteCmosSensor(0x61, 0x66);
	        CamWriteCmosSensor(0x62, 0x66);
            break;
        default:
            return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        }
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   HI253Sharpness
*
* DESCRIPTION
*   Sharpness setting.
*
* PARAMETERS
*   In, Out
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM HI253Sharpness(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        const P_CAL_FEATURE_TYPE_ENUM_STRUCT Sharpness = &Out->FeatureInfo.FeatureEnum;

        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
        // TODO: add supported sharpness enum here
        Sharpness->IsSupport = KAL_TRUE;
        Sharpness->ItemCount = 3;
        Sharpness->SupportItem[0] = CAM_SHARPNESS_HIGH;
        Sharpness->SupportItem[1] = CAM_SHARPNESS_MEDIUM;
        Sharpness->SupportItem[2] = CAM_SHARPNESS_LOW;
    }
    else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
    {
        // TODO: adjust sharpness here
        switch (In->FeatureSetValue)
        {
        case CAM_SHARPNESS_HIGH:
            CamWriteCmosSensor(0x03, 0x13);
            CamWriteCmosSensor(0x20, 0x0E);
            CamWriteCmosSensor(0x21, 0x0E);
            break;
        case CAM_SHARPNESS_MEDIUM:
            CamWriteCmosSensor(0x03, 0x13);
            CamWriteCmosSensor(0x20, 0x07);
            CamWriteCmosSensor(0x21, 0x07);
            break;
        case CAM_SHARPNESS_LOW:
            CamWriteCmosSensor(0x03, 0x13);
            CamWriteCmosSensor(0x20, 0x02);
            CamWriteCmosSensor(0x21, 0x02);
            break;
        default:
            return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        }
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HI253Wb
*
* DESCRIPTION
*    HI253 WB setting.
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
static MM_ERROR_CODE_ENUM HI253Wb(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
#ifdef __HI253_DEBUG_TRACE__
		kal_wap_trace(MOD_ENG,TRACE_INFO,"WB:%d",In->FeatureSetValue);
#endif
		switch (In->FeatureSetValue)
		{
			case CAM_WB_AUTO: /* enable AWB */
				//HI253_awb_enable(KAL_TRUE);
				CamWriteCmosSensor(0x03, 0x22);
				CamWriteCmosSensor(0x10, 0x69);
				//CamWriteCmosSensor(0x80, 0x38);
				//CamWriteCmosSensor(0x81, 0x20);
				//CamWriteCmosSensor(0x82, 0x3a);
				CamWriteCmosSensor(0x83, 0x5e);
				CamWriteCmosSensor(0x84, 0x20);
				CamWriteCmosSensor(0x85, 0x53);
				CamWriteCmosSensor(0x86, 0x15);
				CamWriteCmosSensor(0x10, 0xe9);
				break;
			case CAM_WB_CLOUD: //cloudy
				//HI253_awb_enable(KAL_FALSE);
				CamWriteCmosSensor(0x03, 0x22);
				CamWriteCmosSensor(0x10, 0x69);
				CamWriteCmosSensor(0x80, 0x49);
				CamWriteCmosSensor(0x81, 0x20);
				CamWriteCmosSensor(0x82, 0x24);
				CamWriteCmosSensor(0x83, 0x50);
				CamWriteCmosSensor(0x84, 0x45);
				CamWriteCmosSensor(0x85, 0x24);
				CamWriteCmosSensor(0x86, 0x1e);
				break;
			case CAM_WB_DAYLIGHT: //sunny
				//HI253_awb_enable(KAL_FALSE);
				CamWriteCmosSensor(0x03, 0x22);
				CamWriteCmosSensor(0x10, 0x69);
				CamWriteCmosSensor(0x80, 0x45);
				CamWriteCmosSensor(0x81, 0x20);
				CamWriteCmosSensor(0x82, 0x27);
				CamWriteCmosSensor(0x83, 0x44);
				CamWriteCmosSensor(0x84, 0x3f);
				CamWriteCmosSensor(0x85, 0x29);
				CamWriteCmosSensor(0x86, 0x23);
				break;
			case CAM_WB_INCANDESCENCE: //office 白炽灯---datasheet fluorescent2
				//HI253_awb_enable(KAL_FALSE);
				CamWriteCmosSensor(0x03, 0x22);
				CamWriteCmosSensor(0x10, 0x69);
				CamWriteCmosSensor(0x80, 0x33);
				CamWriteCmosSensor(0x81, 0x20);
				CamWriteCmosSensor(0x82, 0x3d);
				CamWriteCmosSensor(0x83, 0x2e);
				CamWriteCmosSensor(0x84, 0x24);
				CamWriteCmosSensor(0x85, 0x43);
				CamWriteCmosSensor(0x86, 0x3d);
				break;
			case CAM_WB_FLUORESCENT://荧光灯----datasheet fluorescent1
				//HI253_awb_enable(KAL_FALSE);
				CamWriteCmosSensor(0x03, 0x22);
				CamWriteCmosSensor(0x10, 0x69);
				CamWriteCmosSensor(0x80, 0x45);
				CamWriteCmosSensor(0x81, 0x20);
				CamWriteCmosSensor(0x82, 0x2f);
				CamWriteCmosSensor(0x83, 0x38);
				CamWriteCmosSensor(0x84, 0x32);
				CamWriteCmosSensor(0x85, 0x39);
				CamWriteCmosSensor(0x86, 0x33);
				break;
			case CAM_WB_TUNGSTEN: //home 钨光灯----datasheet:light bulb
				//HI253_awb_enable(KAL_FALSE);
				CamWriteCmosSensor(0x03, 0x22);
				CamWriteCmosSensor(0x10, 0x69);
				CamWriteCmosSensor(0x80, 0x25);
				CamWriteCmosSensor(0x81, 0x20);
				CamWriteCmosSensor(0x82, 0x44);
				CamWriteCmosSensor(0x83, 0x22);
				CamWriteCmosSensor(0x84, 0x1e);
				CamWriteCmosSensor(0x85, 0x50);
				CamWriteCmosSensor(0x86, 0x45);
				break;
			default:
				break;
		}
	}
	return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    HI253Effect
*
* DESCRIPTION
*    HI253 Effect setting.
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
static MM_ERROR_CODE_ENUM HI253Effect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    //EffectPara->SupportItem[6] = CAM_EFFECT_ENC_GRAYINV;
    //EffectPara->SupportItem[7] = CAM_EFFECT_ENC_EMBOSSMENT;
    //EffectPara->SupportItem[8] = CAM_EFFECT_ENC_SKETCH;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
#ifdef __HI253_DEBUG_TRACE__
		kal_wap_trace(MOD_ENG,TRACE_INFO,"Effect:%d",In->FeatureSetValue);
#endif
		
		//if (HI253Sensor.Effect == In->FeatureSetValue)
		//{
		//  return MM_ERROR_NONE;
		//}
		HI253Sensor.Effect = In->FeatureSetValue;
		switch (HI253Sensor.Effect)
		{
			case CAM_EFFECT_ENC_NORMAL:
				CamWriteCmosSensor(0x03, 0x10);
				CamWriteCmosSensor(0x11, 0x03);
				CamWriteCmosSensor(0x12, 0x30);
				CamWriteCmosSensor(0x40, gBrightnessValue);
				break;
			case CAM_EFFECT_ENC_SEPIA:
				CamWriteCmosSensor(0x03, 0x10);
				CamWriteCmosSensor(0x11, 0x03);
				CamWriteCmosSensor(0x12, 0x23);
				//CamWriteCmosSensor(0x40, 0x00);
				CamWriteCmosSensor(0x44, 0x70);
				CamWriteCmosSensor(0x45, 0x98);
				CamWriteCmosSensor(0x47, 0x7f);
				break;
			case CAM_EFFECT_ENC_COLORINV://----datasheet
				CamWriteCmosSensor(0x03, 0x10);
				CamWriteCmosSensor(0x11, 0x03);
				CamWriteCmosSensor(0x12, 0x28);
				//CamWriteCmosSensor(0x40, 0x00);
				CamWriteCmosSensor(0x44, 0x80);
				CamWriteCmosSensor(0x45, 0x80);
				CamWriteCmosSensor(0x47, 0x7f);
				break;
			case CAM_EFFECT_ENC_SEPIAGREEN://----datasheet aqua
				CamWriteCmosSensor(0x03, 0x10);
				CamWriteCmosSensor(0x11, 0x03);
				CamWriteCmosSensor(0x12, 0x23);
				//CamWriteCmosSensor(0x40, 0x00);
				CamWriteCmosSensor(0x44, 0x80);
				CamWriteCmosSensor(0x45, 0x04);
				CamWriteCmosSensor(0x47, 0x7f);
				break;
			case CAM_EFFECT_ENC_SEPIABLUE:
				CamWriteCmosSensor(0x03, 0x10);
				CamWriteCmosSensor(0x11, 0x03);
				CamWriteCmosSensor(0x12, 0x23);
				//CamWriteCmosSensor(0x40, 0x00);
				CamWriteCmosSensor(0x44, 0xb0);
				CamWriteCmosSensor(0x45, 0x40);
				CamWriteCmosSensor(0x47, 0x7f);
				break;
			case CAM_EFFECT_ENC_GRAYSCALE: //----datasheet black & white
				CamWriteCmosSensor(0x03, 0x10);
				CamWriteCmosSensor(0x11, 0x03);
				CamWriteCmosSensor(0x12, 0x23);
				//CamWriteCmosSensor(0x40, 0x00);
				CamWriteCmosSensor(0x44, 0x80);
				CamWriteCmosSensor(0x45, 0x80);
				CamWriteCmosSensor(0x47, 0x7f);
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
				break;
		}

	  	if(HI253Sensor.Effect != CAM_EFFECT_ENC_NORMAL)
	    {
			CamWriteCmosSensor(0x03,0x10);
			CamWriteCmosSensor(0x12,(CamReadCmosSensor(0x12)|0x10));//make sure the Yoffset control is opened.
			CamWriteCmosSensor(0x40, gBrightnessValue);
	    }	
  	}
	return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HI253StillCaptureSize
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
static MM_ERROR_CODE_ENUM HI253StillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  const P_CAL_FEATURE_TYPE_ENUM_STRUCT CapSize = &Out->FeatureInfo.FeatureEnum;
  
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_GET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
    CapSize->IsSupport = KAL_TRUE;
	CapSize->ItemCount = 4;
	CapSize->SupportItem[0] = CAM_SIZE_WALLPAPER;
	CapSize->SupportItem[1] = CAM_SIZE_VGA;
	CapSize->SupportItem[2] = CAM_SIZE_1M;
	CapSize->SupportItem[3] = CAM_SIZE_2M;//?interplation
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HI253Banding
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
static MM_ERROR_CODE_ENUM HI253Banding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  const P_CAL_FEATURE_TYPE_ENUM_STRUCT Banding = &Out->FeatureInfo.FeatureEnum;
  kal_uint16 TempReg;
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
#ifdef __HI253_DEBUG_TRACE__
    kal_wap_trace(MOD_ENG,TRACE_INFO,"Banding:%d",In->FeatureSetValue);
#endif
    HI253Sensor.Banding = In->FeatureSetValue;
	
		CamWriteCmosSensor(0x03,0x20);
		TempReg = CamReadCmosSensor(0x10);
	
		switch (HI253Sensor.Banding)
		{
			case CAM_BANDING_50HZ:
				CamWriteCmosSensor(0x03,0x20);
				CamWriteCmosSensor(0x10,(TempReg | 0x10));
				break;
				
			case CAM_BANDING_60HZ:
				CamWriteCmosSensor(0x03,0x20);
				CamWriteCmosSensor(0x10,(TempReg & (~0x10)));
				break;
				
			default:
				/* Enable Auto Anti-Flicker if the sensor support it. */
				break;
		}

  }  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HI253GetSensorInfo
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
static void HI253GetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT Info)
{
  Info->SensorId = HI253_SENSOR_ID;
  Info->SensorIf = IMAGE_SENSOR_IF_PARALLEL;
  Info->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PreviewHMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PreviewVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PreviewHVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;  
  Info->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PixelClkInv = KAL_FALSE;
  Info->PixelClkPolarity = POLARITY_LOW;
  Info->HsyncPolarity = POLARITY_LOW;
  Info->VsyncPolarity = POLARITY_LOW;
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
  Info->PreviewMclkFreq = 26000000;
  Info->CaptureMclkFreq = 26000000;
  Info->VideoMclkFreq = 26000000;
#else
  Info->PreviewMclkFreq = 24000000;
  Info->CaptureMclkFreq = 24000000;
  Info->VideoMclkFreq = 24000000;
#endif
  HI253Sensor.mclk = Info->PreviewMclkFreq/100000;
  Info->PreviewWidth = HI253_IMAGE_SENSOR_PV_WIDTH;
  Info->PreviewHeight = HI253_IMAGE_SENSOR_PV_HEIGHT;
  Info->FullWidth = HI253_IMAGE_SENSOR_FULL_WIDTH;
  Info->FullHeight = HI253_IMAGE_SENSOR_FULL_HEIGHT;
  Info->SensorAfSupport = KAL_FALSE;
  Info->SensorFlashSupport = KAL_FALSE;
}

#if defined (__AUTO_SCENE_DETECT_SUPPORT__)
/*************************************************************************
* FUNCTION
*    HI253GetEvAwbRef
*
* DESCRIPTION
*    This function get sensor Ev/Awb (EV05/EV13) for auto scene detect
*
* PARAMETERS
*    Ref
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void HI253GetEvAwbRef(P_SENSOR_AE_AWB_REF_STRUCT Ref)
{
    Ref->SensorAERef.AeRefLV05Shutter = 1920;
    Ref->SensorAERef.AeRefLV05Gain = 224 * 2; /* 3.5x, 128 base */
    Ref->SensorAERef.AeRefLV13Shutter = 21;
    Ref->SensorAERef.AeRefLV13Gain = 72 * 2; /* 1.125x, 128 base */
    Ref->SensorAwbGainRef.AwbRefD65Rgain = 212; /* 1.66x, 128 base */
    Ref->SensorAwbGainRef.AwbRefD65Bgain = 138; /* 1.08x, 128 base */
    Ref->SensorAwbGainRef.AwbRefCWFRgain = 176; /* 1.375x, 128 base */
    Ref->SensorAwbGainRef.AwbRefCWFBgain = 196; /* 1.53x, 128 base */
}

/*************************************************************************
* FUNCTION
*    HI253GetCurAeAwbInfo
*
* DESCRIPTION
*    This function get sensor cur Ae/Awb for auto scene detect
*
* PARAMETERS
*    Info
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void HI253GetCurAeAwbInfo(P_SENSOR_AE_AWB_CUR_STRUCT Info)
{
    kal_uint32 Reg, LineLength;
    
    CamWriteCmosSensor(0x03, 0x20);
    Reg = (CamReadCmosSensor(0x80) << 16)|(CamReadCmosSensor(0x81) << 8)|CamReadCmosSensor(0x82);
    CamWriteCmosSensor(0x03, 0x00);
    LineLength = ((CamReadCmosSensor(0x40) << 8)|CamReadCmosSensor(0x41)) + 824;
    Info->SensorAECur.AeCurShutter = Reg * 8 / LineLength;
    Info->SensorAECur.AeCurGain = HI253ReadGain() * 2; /* 128 base */
    CamWriteCmosSensor(0x03, 0x22);
    Info->SensorAwbGainCur.AwbCurRgain = 64 + CamReadCmosSensor(0x80) * 2; /* 128 base */
    Info->SensorAwbGainCur.AwbCurBgain = 64 + CamReadCmosSensor(0x82) * 2; /* 128 base */
}
#endif

/*************************************************************************
* FUNCTION
*    HI253DetectSensorId
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
static kal_uint32 HI253DetectSensorId(void)
{
  MM_ERROR_CODE_ENUM HI253SensorClose(void);
  kal_uint16 HI253PowerOn();
  kal_uint16 SensorId;
  IMAGE_SENSOR_INDEX_ENUM AnotherSensorIdx;
  kal_int8 i, j;
  
  if (IMAGE_SENSOR_MAIN == HI253Sensor.SensorIdx)
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
      SensorId = HI253PowerOn();
      HI253SensorClose();
#ifdef __HI253_DEBUG_TRACE__
      kal_wap_trace(MOD_ENG,TRACE_INFO,"HI253DetectSensorId:%x",SensorId);
#endif
      if (HI253_SENSOR_ID == SensorId)
      {
        return HI253_SENSOR_ID;
      }
    }
  }
  return MM_ERROR_SENSOR_READ_ID_FAIL;
}

/*************************************************************************
* FUNCTION
*    HI253InitOperationPara
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
static void HI253InitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT Para)
{
  Para->CaptureDelayFrame = 3; /* wait stable frame when sensor change mode (pre to cap) */
  Para->PreviewDelayFrame = 3; /* wait stable frame when sensor change mode (cap to pre) */
  Para->PreviewDisplayWaitFrame = 3; /* wait stable frame when sensor change mode (cap to pre) */
}

/*************************************************************************
* FUNCTION
*    HI253AeEnable
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
static MM_ERROR_CODE_ENUM HI253AeEnable(kal_bool Enable)
{  
  kal_uint16 AeTemp = 0;
  
  if (HI253Sensor.BypassAe)
  {
    Enable = KAL_FALSE;
  }
#ifdef __HI253_DEBUG_TRACE__
  kal_prompt_trace(MOD_ENG,"AEenable:%d",Enable);
#endif

  CamWriteCmosSensor(0x03,0x20);
  AeTemp = CamReadCmosSensor(0x10);
  
  if (Enable)	
  {
	  CamWriteCmosSensor(0x10, (AeTemp| 0x80)); /* Turn ON AEC/AGC*/
  }
  else
  {
	  CamWriteCmosSensor(0x10, (AeTemp&(~0x80))); /* Turn OFF AEC/AGC*/
  }
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HI253AwbEnable
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
static MM_ERROR_CODE_ENUM HI253AwbEnable(kal_bool Enable)
{
  kal_uint16 AwbTemp = 0;
  
  if (HI253Sensor.BypassAwb)
  {
    Enable = KAL_FALSE;
  }
#ifdef __HI253_DEBUG_TRACE__
  kal_prompt_trace(MOD_ENG,"AWBenable:%d",Enable);
#endif

  CamWriteCmosSensor(0x03,0x22);
  AwbTemp = CamReadCmosSensor(0x10);
  
  if (Enable)
  {
	  CamWriteCmosSensor(0x10, (AwbTemp | 0x80));
  }
  else
  {
	  CamWriteCmosSensor(0x10, (AwbTemp& ~0x80));
  }
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HI253PowerOn
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
static kal_uint16 HI253PowerOn(void)
{
  	kal_uint16 SensorId;
	///*
	//1 <1> PDN and RST default value is low
	CamPdnPinCtrl(HI253Sensor.SensorIdx, 0);
	CamRstPinCtrl(HI253Sensor.SensorIdx, 0);
	//kal_sleep_task(1);		// >=0us

	//2 <2> power on (to sensor), first VDD(2.8), second VDD(1.8) after >=0us
	CisModulePowerOn(HI253Sensor.SensorIdx, KAL_TRUE);
	kal_sleep_task(1);		// To wait for Stable Power
	CameraSccbOpen(CAMERA_SCCB_SENSOR, HI253_SLAVE_ADDR, CAMERA_SCCB_8BIT, CAMERA_SCCB_8BIT, 320);

	//4 <3> disable power down (to BB)
	CamPdnPinCtrl(HI253Sensor.SensorIdx, 1);
	//kal_sleep_task(1);		// >= 0us
	//4 <4> enable MCLK (to BB)
	//HI253_Enable_Output_MCLK(HI253Sensor.mclk);	// Enable the master clock. 240, 260

	//5 <5> enable power down (to BB)
	kal_sleep_task(2);		// >= 5ms
	CamPdnPinCtrl(HI253Sensor.SensorIdx, 0);		// Hynix FAE advise to keep the chip-enable pin to low always.

	//6 <6> hardware reset sensor (to BB)
	CamRstPinCtrl(HI253Sensor.SensorIdx, 0);
	kal_sleep_task(3);		// >= 10ms
	CamRstPinCtrl(HI253Sensor.SensorIdx, 1); //Sensor RESET pin high
	kal_sleep_task(1);		// >= 16 MCLK

	//7 <7>software reset sensor and wait (to sensor)
    CamWriteCmosSensor(0x01,0xf1);
    CamWriteCmosSensor(0x01,0xf3);
    CamWriteCmosSensor(0x01,0xf1);
	kal_sleep_task(1);
	
	/* Read Sensor ID  */
	SensorId = CamReadCmosSensor(0x04);

#ifdef __HI253_DEBUG_TRACE__
	kal_wap_trace(MOD_ENG, TRACE_INFO, "HI253 Sensor ID: %x ",SensorId);
#endif
	return SensorId;
}

/*************************************************************************
* FUNCTION
*    HI253Preview
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
static void HI253Preview(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint8 StartX = 0, StartY = 1;

#ifdef __HI253_DEBUG_TRACE__
  kal_wap_trace(MOD_ENG,TRACE_INFO, "HI253 Preview");
#endif

  HI253Sensor.Banding = In->BandingFreq;
  HI253Sensor.NightMode = In->NightMode;
  switch (Id)
  {
  case CAL_SCENARIO_VIDEO:
    StartX = HI253_PV_GRAB_START_X;
    StartY = HI253_PV_GRAB_START_Y;
    HI253Sensor.VideoMode = KAL_TRUE;
    HI253Sensor.Fps = In->MaxVideoFrameRate * HI253_FRAME_RATE_UNIT / 10;
    break;
  case CAL_SCENARIO_CAMERA_PREVIEW:
    StartX = HI253_PV_GRAB_START_X;
    StartY = HI253_PV_GRAB_START_Y;
    HI253Sensor.VideoMode = KAL_FALSE;
    HI253Sensor.Fps = HI253_FRAME_RATE_UNIT * (HI253Sensor.NightMode ? 5 : 10);
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE:
    StartX = HI253_PV_GRAB_START_X;
    StartY = HI253_PV_GRAB_START_Y;
    HI253Sensor.VideoMode = KAL_FALSE;
    HI253Sensor.Fps = HI253_FRAME_RATE_UNIT * (HI253Sensor.NightMode ? 5 : 10);
    break;
  default:
    break;
  }
  HI253_PV_setting();
  ImageMirror = In->ImageMirror;
  HI253SetHVMirror(In->ImageMirror);
  //HI253Banding(In, Out);
  HI253NightMode(HI253Sensor.NightMode);
  HI253CalFps();
  HI253SetFrameCount();

  Out->GrabStartX = StartX;
  Out->GrabStartY = StartY;
  Out->ExposureWindowWidth = HI253_IMAGE_SENSOR_PV_WIDTH - 2 * StartX; 
  Out->ExposureWindowHeight = HI253_IMAGE_SENSOR_PV_HEIGHT - 2 * StartY;
}

#ifdef __ZERO_SHUTTER_DELAY_SUPPORT__
/*************************************************************************
* FUNCTION
*    HI253Preview
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
static void HI253FullPreview(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint8 StartX = 0, StartY = 1;

#ifdef __HI253_DEBUG_TRACE__
  kal_wap_trace(MOD_ENG,TRACE_INFO, "HI253 FullPreview");
#endif

  HI253Sensor.Banding = In->BandingFreq;
  HI253Sensor.NightMode = In->NightMode;
  switch (Id)
  {
  case CAL_SCENARIO_VIDEO:
    StartX = HI253_PV_GRAB_START_X;
    StartY = HI253_PV_GRAB_START_Y;
    HI253Sensor.VideoMode = KAL_TRUE;
    HI253Sensor.Fps = In->MaxVideoFrameRate * HI253_FRAME_RATE_UNIT / 10;
    break;
  case CAL_SCENARIO_CAMERA_PREVIEW:
    StartX = HI253_PV_GRAB_START_X;
    StartY = HI253_PV_GRAB_START_Y;
    HI253Sensor.VideoMode = KAL_FALSE;
    HI253Sensor.Fps = HI253_FRAME_RATE_UNIT * (HI253Sensor.NightMode ? 5 : 10);
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE:
    StartX = HI253_PV_GRAB_START_X;
    StartY = HI253_PV_GRAB_START_Y;
    HI253Sensor.VideoMode = KAL_FALSE;
    HI253Sensor.Fps = HI253_FRAME_RATE_UNIT * (HI253Sensor.NightMode ? 5 : 10);
    break;
  default:
    break;
  }
  HI253_FullPV_setting( In);
  HI253SetHVMirror(In->ImageMirror);
  //HI253Banding(In, Out);
  HI253NightMode(HI253Sensor.NightMode);
  HI253CalFps();
  HI253SetFrameCount();

	Out->GrabStartX = HI253_FULL_GRAB_START_X;
	Out->GrabStartY = HI253_FULL_GRAB_START_Y;
	Out->ExposureWindowWidth = HI253_FULL_GRAB_WIDTH;
	Out->ExposureWindowHeight = HI253_FULL_GRAB_HEIGHT;

  
}
#endif


/*************************************************************************
* FUNCTION
*    HI253Capture
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
static void HI253Capture(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint8 StartX = 0, StartY = 1;
  
  volatile kal_uint32 shutter = 0, temp_reg = 0;
  kal_uint32 prev_line_len = 0;
  kal_uint32 cap_line_len = 0;
  kal_uint8 imask=0,CLK_DIV_REG=0;
  
  kal_uint32 HI253_Max_FrameRate, Clock_Divider, HI253_PLL;
  kal_uint32 HI253_HWidth, HI253_HBLANK, HI253_VLine, HI253_VSYNC;//the same to init reg
  kal_uint32 HI253_OPCLK;
  kal_uint32 HI253_EXP_FREQUENCY, HI253_EXP120, HI253_EXP100;
  kal_uint32 temp_INT_cal;//for get INT value
  kal_uint32 HI253_line_length;
  kal_uint32 HI253_EXPMIN, HI253_EXP_LIMIT, HI253_EXP_UNIT;

#if 1
#ifdef __HI253_DEBUG_TRACE__
  kal_wap_trace(MOD_ENG,TRACE_INFO, "HI253 Capture");
#endif
#ifdef __HI253_DEBUG_TRACE__
	  kal_wap_trace(MOD_ENG, TRACE_INFO, "HI253_Capture, isp_op_mode=%d, mirror=%d, Size=%d x %d", \
		  Id, In->ImageMirror, \
		  In->ImageTargetWidth, In->ImageTargetHeight);
#endif
	  
	  HI253_op_state.sensor_cap_state = KAL_TRUE;
	  
	  /* If not WEBCAM mode */
	  if ( (Id != CAL_SCENARIO_WEBCAM_PREVIEW) && (Id != CAL_SCENARIO_WEBCAM_CAPTURE ) )
	  {   
		  //sleep in, for read AE AWB RGB
		  CamWriteCmosSensor(0x01,(CamReadCmosSensor(0x01)|0x01));//sensor sleep in
		  // turn off AEC/AGC
		  HI253AeEnable(KAL_FALSE);
		  HI253AwbEnable(KAL_FALSE);
		  CamWriteCmosSensor(0x01,(CamReadCmosSensor(0x01)&0xfe));//sensor sleep out for fast capture
	  }
	  
	  shutter = HI253ReadShutter();
	  HI253Sensor.pv_sensor_gain = HI253ReadGain();
	  
#ifdef __HI253_DEBUG_TRACE__
	  kal_wap_trace(MOD_ENG, TRACE_INFO, "HI253_Capture, HI253Sensor.pv_sensor_gain=%d, shutter=%d", HI253Sensor.pv_sensor_gain, shutter);
#endif
	  
	  if ((In->ImageTargetWidth <= HI253_IMAGE_SENSOR_PV_WIDTH)
		  && (In->ImageTargetHeight <= HI253_IMAGE_SENSOR_PV_HEIGHT))
	  { 	  /* Capture Size Less than PV Size */
		  
		  if ( (Id == CAL_SCENARIO_WEBCAM_PREVIEW) || (Id == CAL_SCENARIO_WEBCAM_CAPTURE ) )	  /* Webcam mode */
		  {
		#if (defined(__DYNAMIC_SENSOR_DELAY__))
		//	  In->wait_stable_frame = 0;	  // For preview size capture, no need wait stable frame.
		#endif
			  
			  Out->GrabStartX = HI253_PV_GRAB_START_X;
			  Out->GrabStartY = HI253_PV_GRAB_START_Y;
			  Out->ExposureWindowWidth = HI253_PV_GRAB_WIDTH;
			  Out->ExposureWindowHeight = HI253_PV_GRAB_HEIGHT;
			  
			  /* For web camera mode, the ae is enalbed always, so after apply the grab window. return it directly. */
			  return ;
		  }
		  else												  /* Preview Size Still mode */
		  {
			  if (In->ZoomFactor >= (ISP_DIGITAL_ZOOM_INTERVAL * 3)) // DZ >= 3x
			  {
				  HI253Sensor.cap_dummy_pixels = 424;
				  if(HI253Sensor.mclk == 240)
					  HI253Sensor.cap_dummy_lines = 8;
				  else
					  HI253Sensor.cap_dummy_lines = 62;
			  }
			  else if (In->ZoomFactor >= (ISP_DIGITAL_ZOOM_INTERVAL * 2)) // DZ >= 2x
			  {
				  HI253Sensor.cap_dummy_pixels = 424;
				  if(HI253Sensor.mclk == 240)
					  HI253Sensor.cap_dummy_lines = 8;
				  else
					  HI253Sensor.cap_dummy_lines = 62;
			  }
			  else
			  {
				  HI253Sensor.cap_dummy_pixels = 424;
				  if(HI253Sensor.mclk == 240)
					  HI253Sensor.cap_dummy_lines = 8;
				  else
					  HI253Sensor.cap_dummy_lines = 62;
			  }
			  
			  HI253Sensor.capture_pclk = HI253Sensor.preview_pclk;   //Don't need change the clk for pv capture
			  HI253SetDummy(HI253Sensor.cap_dummy_pixels, HI253Sensor.cap_dummy_lines);
  
			  prev_line_len = HI253_PV_PERIOD_PIXEL_NUMS + HI253Sensor.pv_dummy_pixels;
			  cap_line_len = HI253_PV_PERIOD_PIXEL_NUMS + HI253Sensor.cap_dummy_pixels;
			  shutter = (shutter * HI253Sensor.capture_pclk) / HI253Sensor.preview_pclk;
			  shutter = (shutter * prev_line_len) / cap_line_len;
			  HI253WriteShutter(shutter);
			  
		#if (defined(__DYNAMIC_SENSOR_DELAY__))
		//	  In->wait_stable_frame = 0;	  // For preview size capture, no need wait stable frame.
		#endif
			  
			  Out->GrabStartX = HI253_PV_GRAB_START_X;
			  Out->GrabStartY = HI253_PV_GRAB_START_Y;
			  Out->ExposureWindowWidth = HI253_PV_GRAB_WIDTH;
			  Out->ExposureWindowHeight = HI253_PV_GRAB_HEIGHT;
		  }
		  
	  }
	  else 
	  {    /* FULL Size Capture Mode */
		#if (defined(__DYNAMIC_SENSOR_DELAY__))
		//	  camera_wait_sensor_vd_done();   // Apply the switch size setting from VD. it's more safe.
		#endif
		  CamWriteCmosSensor(0x01,(CamReadCmosSensor(0x01)|0x01));//sensor sleep in for fast capture
		  HI253_CAP_setting();
		  CLK_DIV_REG=(CamReadCmosSensor(0x12)&0xFC);	  // don't divide,PCLK=48M
  
		  /* Capture Size <= 2M */
		  if ((In->ImageTargetWidth <= HI253_IMAGE_SENSOR_FULL_WIDTH)
			  && (In->ImageTargetHeight <= HI253_IMAGE_SENSOR_FULL_HEIGHT))
		  {
		#if ((defined(DRV_ISP_6238_SERIES) || defined(DRV_ISP_6276_SERIES)))
			  if (In->ZoomFactor >= 400)
			  {
				  imask = 1;
				  Clock_Divider = 2, HI253_PLL = 2;
				  HI253Sensor.capture_pclk = HI253Sensor.mclk*HI253_PLL*1/Clock_Divider;
				  
				  HI253Sensor.cap_dummy_pixels = 360;
				  HI253Sensor.cap_dummy_lines = 20;
			  }
			  else if (In->ZoomFactor >= 200)
			  {
				  imask = 1;
				  Clock_Divider = 2, HI253_PLL = 2;
				  HI253Sensor.capture_pclk = HI253Sensor.mclk*HI253_PLL*1/Clock_Divider;
				  
				  HI253Sensor.cap_dummy_pixels = 360;	/*If Capture fail, you can add this dummy*/
				  HI253Sensor.cap_dummy_lines = 20;
			  }
			  else
			  {
				  imask = 0;
				  Clock_Divider = 1, HI253_PLL = 2;
				  HI253Sensor.capture_pclk = HI253Sensor.mclk*HI253_PLL*1/Clock_Divider;
				  
				  HI253Sensor.cap_dummy_pixels =360;  /*If Capture fail, you can add this dummy*/
				  HI253Sensor.cap_dummy_lines = 104;
			  }
		#elif (defined(DRV_ISP_6235_SERIES))
			  if (In->ZoomFactor >= (ISP_DIGITAL_ZOOM_INTERVAL * 3))  // DZ >= 3X
			  {
				  imask = 1;
				  Clock_Divider = 2, HI253_PLL = 2;
				  HI253Sensor.capture_pclk = HI253Sensor.mclk*HI253_PLL*1/Clock_Divider;
				  
				  HI253Sensor.cap_dummy_pixels = 360;
				  HI253Sensor.cap_dummy_lines = 20;
			  }
			  else if (In->ZoomFactor >= (ISP_DIGITAL_ZOOM_INTERVAL * 2))  // DZ >= 2X
			  {
				  imask = 1;
				  Clock_Divider = 2, HI253_PLL = 2;
				  HI253Sensor.capture_pclk = HI253Sensor.mclk*HI253_PLL*1/Clock_Divider;
				  
				  HI253Sensor.cap_dummy_pixels = 360;	/*If Capture fail, you can add this dummy*/
				  HI253Sensor.cap_dummy_lines = 20;
			  }
			  else 
			  {
				  imask = 0;
				  Clock_Divider = 1, HI253_PLL = 2;
				  HI253Sensor.capture_pclk = HI253Sensor.mclk*HI253_PLL*1/Clock_Divider;
				  
				  HI253Sensor.cap_dummy_pixels = 360;	/*If Capture fail, you can add this dummy*/
			#ifdef DRV_ISP_YUV_BURST_MODE_SUPPORT 
				  /* For MT6253 Series chip, limit the max capture frame rate to 8.5fps*/
				  HI253Sensor.cap_dummy_lines = 104;
			#else
				  HI253Sensor.cap_dummy_lines = 104;
			#endif
			  }
		#endif
		  }
		  else			  /* When Capture Size Interpolate to 3M */
		  {
		#if ((defined(DRV_ISP_6238_SERIES) || defined(DRV_ISP_6276_SERIES)))
			  if (In->ZoomFactor >= 400)
			  {
				  imask = 1;
				  Clock_Divider = 2, HI253_PLL = 2;
				  HI253Sensor.capture_pclk = HI253Sensor.mclk*HI253_PLL*1/Clock_Divider;
				  
				  HI253Sensor.cap_dummy_pixels = 360;
				  HI253Sensor.cap_dummy_lines = 20;
			  }
			  else if (In->ZoomFactor >= 200)
			  {
				  imask = 1;
				  Clock_Divider = 2, HI253_PLL = 2;
				  HI253Sensor.capture_pclk = HI253Sensor.mclk*HI253_PLL*1/Clock_Divider;
				  
				  HI253Sensor.cap_dummy_pixels = 360;	/*If Capture fail, you can add this dummy*/
				  HI253Sensor.cap_dummy_lines = 20;
			  }
			  else
			  {
				  imask = 0;
				  Clock_Divider = 1, HI253_PLL = 2;
				  HI253Sensor.capture_pclk = HI253Sensor.mclk*HI253_PLL*1/Clock_Divider;
				  
				  HI253Sensor.cap_dummy_pixels =360;  /*If Capture fail, you can add this dummy*/
				  HI253Sensor.cap_dummy_lines = 104;
			  }
		#elif (defined(DRV_ISP_6235_SERIES))
			  /* If Capture fail or system hang when capture, you can add dummy pixels for each step.  */
			  if (In->ZoomFactor >= (ISP_DIGITAL_ZOOM_INTERVAL * 3)) // DZ >= 3X
			  {
				  imask = 1;
				  Clock_Divider = 2, HI253_PLL = 2;
				  HI253Sensor.capture_pclk = HI253Sensor.mclk*HI253_PLL*1/Clock_Divider;
				  
				  HI253Sensor.cap_dummy_pixels = 360;
				  HI253Sensor.cap_dummy_lines = 20;
			  }
			  else if (In->ZoomFactor >= (ISP_DIGITAL_ZOOM_INTERVAL * 2)) // DZ >= 2x
			  {
				  imask = 1;
				  Clock_Divider = 2, HI253_PLL = 2;
				  HI253Sensor.capture_pclk = HI253Sensor.mclk*HI253_PLL*1/Clock_Divider;
				  
				  HI253Sensor.cap_dummy_pixels = 360;
				  HI253Sensor.cap_dummy_lines = 20;
			  }
			  else if (In->ZoomFactor > (ISP_DIGITAL_ZOOM_INTERVAL * 1)) // DZ > 1x
			  {
				  imask = 1;Clock_Divider = 2, HI253_PLL = 2;
				  HI253Sensor.capture_pclk = HI253Sensor.mclk*HI253_PLL*1/Clock_Divider; 
				  
				  HI253Sensor.cap_dummy_pixels = 360;
				  HI253Sensor.cap_dummy_lines = 20;
			  }
			  else 
			  {
				  imask = 0;
				  Clock_Divider = 1, HI253_PLL = 2;
				  HI253Sensor.capture_pclk = HI253Sensor.mclk*HI253_PLL*1/Clock_Divider;
				  
				  HI253Sensor.cap_dummy_pixels = 360;
				  HI253Sensor.cap_dummy_lines = 104;
			  }
		#endif
		  }
		  {
			  CLK_DIV_REG = CLK_DIV_REG|imask;
			  CamWriteCmosSensor(0x03, 0x00); 
			  CamWriteCmosSensor(0x12,CLK_DIV_REG);
			  
			  /*
			  EXPMIN=(H-width+HBLANK)/4
			  EXP100=(H-width+HBLANK)*INT[OPCLK/(H-width+HBLANK)/100Hz]/8
			  EXP120=(H-width+HBLANK)*INT[OPCLK/(H-width+HBLANK)/120Hz]/8
			  EXPUNIT=(H-width+HBLANK)/4*/
			  
			  cap_line_len = HI253_FULL_PERIOD_PIXEL_NUMS + HI253Sensor.cap_dummy_pixels;
			  HI253_OPCLK = HI253Sensor.mclk*100000*HI253_PLL*1/Clock_Divider*1/2;//here, it is 26000000
		  
			  temp_INT_cal = HI253_OPCLK/cap_line_len/100;
			  HI253_EXP100 = cap_line_len*temp_INT_cal/8;
			  temp_INT_cal = HI253_OPCLK/cap_line_len/120;
			  HI253_EXP120 = cap_line_len*temp_INT_cal/8;
			  HI253_EXP_UNIT = HI253_EXPMIN = cap_line_len/4;
			  
			  CamWriteCmosSensor(0x03, 0x20);
			  CamWriteCmosSensor(0x86, (HI253_EXPMIN>>8)&0xff);//EXPMIN
			  CamWriteCmosSensor(0x87, (HI253_EXPMIN>>0)&0xff);
			  CamWriteCmosSensor(0x8b, (HI253_EXP100>>8)&0xff);//EXP100
			  CamWriteCmosSensor(0x8c, (HI253_EXP100>>0)&0xff);
			  CamWriteCmosSensor(0x8d, (HI253_EXP120>>8)&0xff);//EXP120
			  CamWriteCmosSensor(0x8e, (HI253_EXP120>>0)&0xff);
		  
			  //not difference 24M and 26M
			  CamWriteCmosSensor(0x9c, (HI253_FULL_EXPOSURE_LIMITATION>>8)&0xff);//EXP Limit
			  CamWriteCmosSensor(0x9d, (HI253_FULL_EXPOSURE_LIMITATION>>0)&0xff);
			  
			  CamWriteCmosSensor(0x9e, (HI253_EXP_UNIT>>8)&0xff);//EXP Unit
			  CamWriteCmosSensor(0x9f, (HI253_EXP_UNIT>>0)&0xff);
		  }
		  
		  HI253SetDummy(HI253Sensor.cap_dummy_pixels, HI253Sensor.cap_dummy_lines);
		  
		  prev_line_len = HI253_PV_PERIOD_PIXEL_NUMS + HI253Sensor.pv_dummy_pixels;
		  cap_line_len = HI253_FULL_PERIOD_PIXEL_NUMS + HI253Sensor.cap_dummy_pixels;
		  shutter = shutter>>imask;
		  if(shutter<1)
			  shutter = 1;
  
		  HI253WriteShutter(shutter);
  
	#if (defined(__DYNAMIC_SENSOR_DELAY__))
	//	  In->wait_stable_frame = 3;
	#endif
  
		  Out->GrabStartX = HI253_FULL_GRAB_START_X;
		  Out->GrabStartY = HI253_FULL_GRAB_START_Y;
		  Out->ExposureWindowWidth = HI253_FULL_GRAB_WIDTH;
		  Out->ExposureWindowHeight = HI253_FULL_GRAB_HEIGHT;
	  }
  
	  //sensor sleep out
	  CamWriteCmosSensor(0x01,(CamReadCmosSensor(0x01)&0xfe));//sensor sleep out
  
#ifdef __HI253_DEBUG_TRACE__
	  kal_wap_trace(MOD_ENG, TRACE_INFO, "HI253_Capture, preview_pclk=%d, capture_pclk=%d", \
		  HI253Sensor.preview_pclk, HI253Sensor.capture_pclk);
	  kal_wap_trace(MOD_ENG, TRACE_INFO, "HI253_Capture, prev_line_len=%d, cap_line_len=%d, shutter=%d", \
		  prev_line_len, cap_line_len, shutter);
#endif
	#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif

  OV2659SetHVMirror(ImageMirror);
}

/*************************************************************************
* FUNCTION
*    HI253SensorOpen
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
static MM_ERROR_CODE_ENUM HI253SensorOpen(void)
{
  if (HI253_SENSOR_ID != HI253PowerOn())
  {
    return MM_ERROR_SENSOR_READ_ID_FAIL;
  }
  HI253Sensor.VideoMode = KAL_FALSE;
  HI253Sensor.NightMode = KAL_FALSE;
  HI253Sensor.Banding = CAM_BANDING_50HZ;
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
  HI253Sensor.Pclk = 26000000;
#else
  HI253Sensor.Pclk = 24000000;
#endif
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
  HI253Sensor.DummyPixel = 0x62;
#else
  HI253Sensor.DummyPixel = 0x08;
#endif
  HI253Sensor.Fps = 10 * HI253_FRAME_RATE_UNIT;
  //HI253Sensor.ShutterStep= 0x96;
  
  HI253InitialSetting();
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HI253SensorFeatureCtrl
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
static MM_ERROR_CODE_ENUM HI253SensorFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
  
#ifdef __HI253_DEBUG_TRACE__
  kal_wap_trace(MOD_ENG, TRACE_INFO, "HI253 FeatureCtrl Id:%x",Id);
#endif
  if (Id >= CAL_FEATURE_WEBCAM_BEGIN && Id <= CAL_FEATURE_WEBCAM_END)
  {
    return HI253WebcamFeatureCtrl(Id, In, Out, OutLen, RealOutLen);
  }
    switch (Id)
    {
    /* CAL Query and set series */
    case CAL_FEATURE_CAMERA_BRIGHTNESS:
    case CAL_FEATURE_CAMERA_EV_VALUE:
        ErrCode = HI253Ev(In, Out);
        break;
    case CAL_FEATURE_CAMERA_CONTRAST:
        ErrCode = HI253Contrast(In, Out);
        break;
    case CAL_FEATURE_CAMERA_SATURATION:
        ErrCode = HI253Saturation(In, Out);
        break;
    case CAL_FEATURE_CAMERA_SHARPNESS:
        ErrCode = HI253Sharpness(In, Out);
        break;
  case CAL_FEATURE_CAMERA_WB:
    ErrCode = HI253Wb(In, Out);
    break;
  case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
    ErrCode = HI253Effect(In, Out);
    break;
  case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
    ErrCode = HI253StillCaptureSize(In, Out);
    break;
  case CAL_FEATURE_CAMERA_BANDING_FREQ: /* Only query here, set function move to preview */
    ErrCode = HI253Banding(In, Out);
    break;
  case CAL_FEATURE_CAMERA_FLASH_MODE:
  case CAL_FEATURE_CAMERA_HUE:
  case CAL_FEATURE_CAMERA_GAMMA:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;

  /* Get Info series */
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
    HI253GetSensorInfo(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = HI253DetectSensorId();
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = HI253Sensor.Fps * 10 / HI253_FRAME_RATE_UNIT;
    break;
  case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
    HI253InitOperationPara(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
    CamGetHWInfo(HI253Sensor.SensorIdx, Out);
    break;
#if defined (__AUTO_SCENE_DETECT_SUPPORT__)
    case IMAGE_SENSOR_FEATURE_GET_EV_AWB_REF:
        HI253GetEvAwbRef(Out);
        break;
    case IMAGE_SENSOR_FEATURE_GET_SHUTTER_GAIN_AWB_GAIN:
        HI253GetCurAeAwbInfo(Out);
        break;
    case IMAGE_SENSOR_FEATURE_SET_SCENE_ENHANCE:
    {
        CAL_FEATURE_CTRL_STRUCT Para;

        Para.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
        Para.FeatureSetValue = ((P_SENSOR_SCENE_ENHANCE_STRUCT)In)->SceneContrast;
        HI253Contrast(&Para, NULL);
        Para.FeatureSetValue = ((P_SENSOR_SCENE_ENHANCE_STRUCT)In)->SceneSaturation;
        HI253Saturation(&Para, NULL);
        Para.FeatureSetValue = ((P_SENSOR_SCENE_ENHANCE_STRUCT)In)->SceneSharpness;
        HI253Sharpness(&Para, NULL);
        break;
    }
#endif

  /* Set Para series */
  case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
    CamPdnPinCtrl(HI253Sensor.SensorIdx, 0);   
    CamRstPinCtrl(HI253Sensor.SensorIdx, 0);
    break;
  case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
    HI253Sensor.NvramData = &(((nvram_camera_para_struct *)In)->SENSOR);
    break;
  case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
    HI253Sensor.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
    break;
  case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
    break;
  case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
	HI253Sensor.BypassAe = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
	HI253AeEnable(HI253Sensor.BypassAe ? KAL_FALSE : KAL_TRUE);
	break;
  case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
	HI253Sensor.BypassAwb = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
	HI253AwbEnable(HI253Sensor.BypassAwb ? KAL_FALSE : KAL_TRUE);
	break;

  default:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  }
  return ErrCode;
}

/*************************************************************************
* FUNCTION
*    HI253SensorCtrl
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
static MM_ERROR_CODE_ENUM HI253SensorCtrl(CAL_SCENARIO_ENUM Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  switch (Id)
  {
  case CAL_SCENARIO_CAMERA_PREVIEW:
  case CAL_SCENARIO_VIDEO:
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE:
    HI253Preview(Id, In, Out);
    break;
#ifdef __ZERO_SHUTTER_DELAY_SUPPORT__
  case CAL_SCENARIO_CAMERA_ZSD_PREVIEW:
    HI253FullPreview(Id, In, Out);
    break;
#endif
  case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
    HI253Capture(Id, In, Out);
    break;
  default:
    break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HI253SensorClose
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
static MM_ERROR_CODE_ENUM HI253SensorClose(void)
{
  /* power down sensor */
  CamPdnPinCtrl(HI253Sensor.SensorIdx, 0);// Hynix FAE advise to keep the chip-enable pin to low always.
  kal_sleep_task(1);		// >= 16 mclk cycles
  CamRstPinCtrl(HI253Sensor.SensorIdx, 0);
  CisModulePowerOn(HI253Sensor.SensorIdx, KAL_FALSE);
  CameraSccbClose(CAMERA_SCCB_SENSOR);
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HI253SensorFunc
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
MM_ERROR_CODE_ENUM HI253SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncHI253 =
  {
    HI253SensorOpen,
    HI253SensorFeatureCtrl,
    HI253SensorCtrl,
    HI253SensorClose,
  };
  
  *pfSensorFunc = &ImageSensorFuncHI253;
  
  return MM_ERROR_NONE;
}


