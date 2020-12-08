/*******************************************************************************
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *	sensor_common_interface.h
 *
 * Project:
 * --------
 *
 *
 * Description:
 * ------------
 *   This file is intends for ISP SW Interface about raw camera.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _SENSOR_COMMON_INTERFACE_H_
#define _SENSOR_COMMON_INTERFACE_H_

#define SENSOR_COMMON_INTERFACE_SUPPORT
/*Please do not include other header files here */
#include "kal_release.h"
#include "cal_comm_def.h"
#include "sensor_comm_def.h"
/* MT6253EL */
#include "ds_if.h"

/*typedef enum
{
	ERROR_NONE=0,
	ERROR_COMM_BEGIN=1,
	ERROR_INCORRECT_PARAMETER,
	ERROR_OUT_OF_MEMORY,
	ERROR_ISP_BEGIN=1000,
	ERROR_MDP_BEGIN=2000,
	ERROR_LCD_BEGIN=3000,
	ERROR_JPEG_BEGIN=4000,
	ERROR_CAL_BEGIN=5000,
	ERROR_SENSOR_BEGIN=6000,
	ERROR_SENSOR_READ_ID_FAIL,
	ERROR_SENSOR_FEATURE_NOT_SUPPORT,
	ERROR_SENSOR_WAIT_FRAME_READY_FAIL,
	ERROR_LENS_BEGIN=7000,
	ERRROR_FLASHLIGHT_BEGIN=8000,
	ERROR_MAX
}MM_ERROR_CODE_ENUM;*/


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
#endif

/* start data structure for getting sensor frame rate for video */
typedef struct
{
	kal_uint16 current_video_frame_rate;     /* current sensor frame rate for video */

}SENSOR_FLEXIBLE_VIDEO_FRAMERATE_STRUCT, *PSENSOR_FLEXIBLE_VIDEO_FRAMERATE_STRUCT;
/* end of data structure for getting sensor frame rate for video */


/* start data structure for getting the shading table from sensor's EEPROM */
#if 0 // defined in sensor_comm_def.h
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

/* start - data structure for JPEG sensor & new digital zoom interface */
typedef enum{
	ZOOM_NOT_SUPPORT=0,
	ZOOM_SUPPORT_NORMAL,//byt step
	ZOOM_SUPPORT_LOOK_UP_TABLE
}ZOOM_SUPPORT_TYPE_ENUM;

/* MT6253EL */
/* sensor I/F */
typedef enum
{
	SENSOR_IF_PARALLEL,
	SENSOR_IF_MIPI,
	SENSOR_IF_DIRECT,	
	SENSOR_IF_SERIAL,	
	SENSOR_IF_TOTAL_NO	
}SENSOR_IF_ENUM;


typedef enum
{
        SENSOR_DATA_FORMAT_UNKNOWN=0,
        SENSOR_DATA_FORMAT_BAYER_RG,//bayer default
        SENSOR_DATA_FORMAT_BAYER_GR,
        SENSOR_DATA_FORMAT_BAYER_BG,
        SENSOR_DATA_FORMAT_BAYER_GB,
        SENSOR_DATA_FORMAT_YUV422_VYUY,//yuv default
        SENSOR_DATA_FORMAT_YUV422_YUYV,
        SENSOR_DATA_FORMAT_YUV422_UYVY,
        SENSOR_DATA_FORMAT_YUV422_YVYU,
        SENSOR_DATA_FORMAT_RGB565,        
	 SENSOR_DATA_FORMAT_JPEG,
        SENSOR_DATA_FORMAT_TOTAL_NO     
}SENSOR_DATA_FORMAT_ENUM;



typedef enum
{
	SENSOR_MODE_UNKNOWN=0,
	SENSOR_MODE_PAUSE,
	SENSOR_MODE_RESUME,	
	SENSOR_MODE_TOTAL_NO	
}SENSOR_MODE_ENUM;

typedef  void (* SENSOR_HW_IF_FUNC) (void);




/*capture size shoud mapping to CAP_SIZE  in Med_api.h */
typedef enum
{
	CAPTURE_SIZE_WALLPAPER=0,   	//CAM_SIZE_WALLPAPER
       CAPTURE_SIZE_QVGA,			//CAM_SIZE_QVGA
	CAPTURE_SIZE_VGA,				//CAM_SIZE_VGA
	CAPTURE_SIZE_1M,				//CAM_SIZE_1M
	CAPTURE_SIZE_2M,				//CAM_SIZE_2M
	CAPTURE_SIZE_3M,				//CAM_SIZE_3M
	CAPTURE_SIZE_4M,				//CAM_SIZE_4M
	CAPTURE_SIZE_5M,				//CAM_SIZE_5M
	CAPTURE_SIZE_OTHER,			//CAM_SIZE_OTHER
	CAPTURE_SIZE_NOT_SUPPORT	//CAM_SIZE_NOT_SUPPORT
}CAPTURE_SIZE_ENUM;  


typedef struct
{
	CAPTURE_SIZE_ENUM current_capture_size;
}CAPTURE_SIZE_STRUCT, *PCAPTURE_SIZE_STRUCT;

typedef struct
{
	kal_bool video_mode;
	CAPTURE_SIZE_ENUM current_capture_size;
}SENSOR_ZOOM_QUERY_STRUCT, *PSENSOR_ZOOM_QUERY_STRUCT;


typedef struct
{
    CAPTURE_SIZE_ENUM capture_resolution;
    SENSOR_DATA_FORMAT_ENUM capture_sensor_type; // yuv , jpeg
    ZOOM_SUPPORT_TYPE_ENUM zoom_support_type; //0:no supprot , 1: normal type , 2: jpeg sensor type 
    kal_uint16 zoom_steps;
    kal_uint16 max_zoom_factor;
    const kal_uint32 *zoom_table;
}SENSOR_ZOOM_INFO_STRUCT, *PSENSOR_ZOOM_INFO_STRUCT , cam_zoom_basic_t;

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
#endif
/* MT6253EL */
typedef struct
{
	SENSOR_IF_ENUM	sensor_if_type;
	SENSOR_DATA_FORMAT_ENUM	preview_data_format;
	SENSOR_DATA_FORMAT_ENUM	capture_data_format;
	SENSOR_DATA_FORMAT_ENUM	video_data_format;
	kal_uint16 sensor_preview_width;
	kal_uint16 sensor_preview_height;
	kal_uint16 sensor_full_width;
	kal_uint16 sensor_full_height;
	kal_uint16 sensor_video_width;
	kal_uint16 sensor_video_height;
} SENSOR_COMMON_INFO_STRUCT, *PSENSOR_COMMON_INFO_STRUCT;
/* SENSOR_FEATURE_GET_COMMON_INFO, Output */
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
#endif
#endif /* _SENSOR_COMMON_INTERFACE_H_ */
