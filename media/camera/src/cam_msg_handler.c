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

/*******************************************************************************
 * Filename:
 * ---------
 *   cam_msg_handler.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes message handle functions of image module.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by P4 VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 02 27 2013 peter.wang
 * removed!
 * .
 *
 * 02 01 2013 peter.wang
 * removed!
 * .
 *
 * 01 17 2013 peter.wang
 * removed!
 * .
 *
 * 01 11 2013 peter.wang
 * removed!
 * .
 *
 * 01 11 2013 peter.wang
 * removed!
 * removed!
 * .
 *
 * 12 28 2012 peter.wang
 * removed!
 * .
 *
 * 12 04 2012 peter.wang
 * removed!
 * .
 *
 * 12 03 2012 peter.wang
 * removed!
 * .
 *
 * 11 26 2012 peter.wang
 * removed!
 * .
 *
 * 11 21 2012 peter.wang
 * removed!
 * .
 *
 * 11 19 2012 peter.wang
 * removed!
 * .
 *
 * 11 13 2012 peter.wang
 * removed!
 * .
 * 
 * 10 22 2012 peter.wang
 * removed!
 * .
 * 
 * 08 07 2012 peter.wang
 * removed!
 * .
 * 
 * 07 30 2012 shouchun.liao
 * removed!
 * Add sequence number for mav/3d capture.
 *
 * 07 06 2012 jason.chang
 * removed!
 * Fix memory free control for HDR process.
 *
 * 07 02 2012 jason.chang
 * removed!
 * .
 *
 * 06 27 2012 chrono.wu
 * removed!
 * .
 *
 * 06 21 2012 gellmann.chang
 * removed!
 * .
 *
 * 06 21 2012 gellmann.chang
 * removed!
 * .
 *
 * 06 20 2012 shouchun.liao
 * removed!
 * FIx coding defect of 3D image capture mode check.
 *
 * 06 14 2012 peter.wang
 * removed!
 * .
 *
 * 06 11 2012 peter.wang
 * removed!
 * .
 *
 * 06 08 2012 gellmann.chang
 * removed!
 * .
 *
 * 06 01 2012 shouchun.liao
 * removed!
 * Check-in 3D Image/MAV/AutoRama/FSD for MT6250.
 *
 * 05 15 2012 peter.wang
 * removed!
 * .
 *
 * 05 04 2012 peter.wang
 * removed!
 * .
 *
 * 04 19 2012 shouchun.liao
 * removed!
 * fix mav capture abort problem.
 *
 * 03 22 2012 shouchun.liao
 * removed!
 * Check-in RAW Capture for QR code.
 *
 * 03 19 2012 shouchun.liao
 * removed!
 * Check-in start mav stitch by MDI.
 *
 * 03 15 2012 gellmann.chang
 * removed!
 * .
 *
 * 03 13 2012 shouchun.liao
 * removed!
 * free working memory when mav stitch ready.
 *
 * 03 12 2012 ricky.lin
 * removed!
 * .
 *
 * 03 09 2012 shouchun.liao
 * removed!
 * Set mav preview to video mode.
 *
 * 03 06 2012 gellmann.chang
 * removed!
 * .
 *
 * 03 02 2012 shouchun.liao
 * removed!
 * AutoRama slim.
 *
 * 02 27 2012 ricky.lin
 * removed!
 * .
 *
 * 02 27 2012 ricky.lin
 * removed!
 * .
 *
 * 02 23 2012 ricky.lin
 * removed!
 * .
 *
 * 02 15 2012 ricky.lin
 * removed!
 * .
 *
 * 02 13 2012 ricky.lin
 * removed!
 * .
 *
 * 12 20 2011 pochun.huang
 * removed!
 * .
 *
 * 12 16 2011 pochun.huang
 * removed!
 * .
 *
 * 12 13 2011 pochun.huang
 * removed!
 * .
 *
 * 12 12 2011 pochun.huang
 * removed!
 * .
 *
 * 11 22 2011 pochun.huang
 * removed!
 * .
 *
 * 11 15 2011 shouchun.liao
 * removed!
 * Fix hdr working memory allocation fail problem due to memory fragmentation.
 *
 * 11 14 2011 shouchun.liao
 * removed!
 * Allocate capture buffer & extmem memory the same size as hdr work buf size to avoid memory fragment.
 *
 * 10 18 2011 shouchun.liao
 * removed!
 * Postpone burst shot stop handling to current capture complete.
 *
 * 10 03 2011 shouchun.liao
 * removed!
 * check-in qvi with uyvy422 color format support.
 *
 * 09 29 2011 shouchun.liao
 * removed!
 * check-in qvi refine for autorama.
 *
 * 09 27 2011 pochun.huang
 * removed!
 * .
 *
 * 09 22 2011 pochun.huang
 * removed!
 * .
 *
 * 09 21 2011 pochun.huang
 * removed!
 * .
 *
 * 09 21 2011 shouchun.liao
 * removed!
 * Fix cam state checking in cam_set_param_req_hdlr().
 *
 * 09 19 2011 pochun.huang
 * removed!
 * .
 *
 * 09 15 2011 shouchun.liao
 * removed!
 * reset autocap direction only when current_shot_number = 0.
 *
 * 08 25 2011 pochun.huang
 * removed!
 * .
 *
 * 08 24 2011 shouchun.liao
 * removed!
 * Check-in AutoRama/ASD.
 *
 * 08 24 2011 pochun.huang
 * removed!
 * .
 *
 * 08 05 2011 pochun.huang
 * removed!
 * .
 *
 * 07 27 2011 pochun.huang
 * removed!
 * .
 *
 * 06 27 2011 cathytr.huang
 * removed!
 * .
 *
 * 06 24 2011 cathytr.huang
 * removed!
 * .
 *
 * 06 24 2011 cathytr.huang
 * removed!
 * .
 *
 * 06 20 2011 cathytr.huang
 * removed!
 * .
 *
 * 06 15 2011 cathytr.huang
 * removed!
 * .
 *
 * 06 13 2011 cathytr.huang
 * removed!
 * .
 *
 * 06 07 2011 cathytr.huang
 * removed!
 * .
 *
 * 06 07 2011 cathytr.huang
 * removed!
 * .
 *
 * 05 31 2011 tokiya.chang
 * removed!
 * .
 *
 * 05 18 2011 cathytr.huang
 * removed!
 * .
 *
 * 05 17 2011 cathytr.huang
 * removed!
 * .
 *
 * 05 16 2011 cathytr.huang
 * removed!
 * .
 *
 * 05 16 2011 cathytr.huang
 * removed!
 * .
 *
 * 05 11 2011 cathytr.huang
 * removed!
 * .
 *
 * 05 10 2011 cathytr.huang
 * removed!
 * .
 *
 * 04 29 2011 cathytr.huang
 * removed!
 * .
 *
 * 04 19 2011 cathytr.huang
 * removed!
 * .
 *
 * 03 31 2011 cathytr.huang
 * removed!
 * .
 *
 * 03 25 2011 cathytr.huang
 * removed!
 * .
 *
 * 03 25 2011 cathytr.huang
 * removed!
 * .
 *
 * 03 18 2011 vincent.cho
 * removed!
 * .
 *
 * 03 18 2011 vincent.cho
 * removed!
 * .
 *
 * 03 16 2011 cathytr.huang
 * removed!
 * .
 *
 * 03 11 2011 cathytr.huang
 * removed!
 * .
 *
 * 03 08 2011 cathytr.huang
 * removed!
 * .
 *
 * 03 04 2011 cathytr.huang
 * removed!
 * Make power off be a blocking function.
 *
 * 03 03 2011 cathytr.huang
 * removed!
 * .
 *
 * 03 03 2011 cathytr.huang
 * removed!
 * .
 *
 * 03 03 2011 cathytr.huang
 * removed!
 * .
 *
 * 03 02 2011 cathytr.huang
 * removed!
 * .
 *
 * 03 02 2011 cathytr.huang
 * removed!
 * 
 * .
 *
 * 03 02 2011 cathytr.huang
 * removed!
 * .
 *
 * 03 02 2011 cathytr.huang
 * removed!
 * .
 *
 * 03 02 2011 cathytr.huang
 * removed!
 * .
 *
 * 02 24 2011 cathytr.huang
 * removed!
 * .
 *
 * 02 24 2011 cathytr.huang
 * removed!
 * .
 *
 * 02 23 2011 cathytr.huang
 * removed!
 * .
 *
 * 02 23 2011 cathytr.huang
 * removed!
 * .
 *
 * 02 23 2011 cathytr.huang
 * removed!
 * .
 *
 * 02 23 2011 cathytr.huang
 * removed!
 * .
 *
 * 02 22 2011 cathytr.huang
 * removed!
 * .
 *
 * 02 18 2011 cathytr.huang
 * removed!
 * Remove chip compile option.
 *
 * 02 09 2011 cathytr.huang
 * removed!
 * Panorama revises pause/resume.
 *
 * 02 09 2011 cathytr.huang
 * removed!
 * Change structure naming.
 *
 * 02 09 2011 cathytr.huang
 * removed!
 * .
 *
 * 02 08 2011 cathytr.huang
 * removed!
 * Add cam get buffer content operation.
 *
 * 02 08 2011 cathytr.huang
 * removed!
 * Change thumbnail color format.
 *
 * 01 28 2011 cathytr.huang
 * removed!
 * .
 *
 * 01 27 2011 cathytr.huang
 * removed!
 * .
 *
 * 01 26 2011 cathytr.huang
 * removed!
 * Revise memory check handling.
 *
 * 01 24 2011 cathytr.huang
 * removed!
 * .
 *
 * 01 24 2011 cathytr.huang
 * removed!
 * .
 *
 * 01 21 2011 cathytr.huang
 * removed!
 * .
 *
 * 01 20 2011 cathytr.huang
 * removed!
 * .
 *
 * 01 19 2011 cathytr.huang
 * removed!
 * Add error handling.
 *
 * 01 14 2011 cathytr.huang
 * removed!
 * 
 * .
 *
 * 01 12 2011 cathytr.huang
 * removed!
 * .
 *
 * 01 12 2011 cathytr.huang
 * removed!
 * .
 *
 * 01 11 2011 cathytr.huang
 * removed!
 * .
 *
 * 01 10 2011 cathytr.huang
 * removed!
 * .
 *
 * 01 03 2011 cathytr.huang
 * removed!
 * .
 *
 * 12 29 2010 cathytr.huang
 * removed!
 * 
 * Panorama revise..
 *
 * 12 28 2010 cathytr.huang
 * removed!
 * .
 *
 * 12 27 2010 cathytr.huang
 * removed!
 * .
 *
 * 12 23 2010 cathytr.huang
 * removed!
 * .
 *
 * 12 22 2010 cathytr.huang
 * removed!
 * .
 *
 * 12 21 2010 cathytr.huang
 * removed!
 * Add LCM scan line code.
 *
 * 12 16 2010 cathytr.huang
 * removed!
 * Add feature compile option.
 *
 * 12 15 2010 cathytr.huang
 * removed!
 * .
 *
 * 12 15 2010 cathytr.huang
 * removed!
 * Add UI rotate handling.
 *
 * 12 15 2010 cathytr.huang
 * removed!
 * Fix panorama IT issue.
 *
 * 12 14 2010 cathytr.huang
 * removed!
 * Revise code.
 *
 * 12 14 2010 cathytr.huang
 * removed!
 * Add panorama new API and revise profiling.
 *
 * 12 12 2010 cathytr.huang
 * removed!
 * Buffer overlay.
 *
 * 12 08 2010 cathytr.huang
 * removed!
 * Revise panorama.
 *
 * 12 02 2010 cathytr.huang
 * removed!
 * Fix build error.
 *
 * 12 01 2010 cathytr.huang
 * removed!
 * Panorama revise.
 *
 * 12 01 2010 cathytr.huang
 * removed!
 * DDV2 element check in.
 *
 * 11 30 2010 cathytr.huang
 * removed!
 * .
 *
 * 11 30 2010 cathytr.huang
 * removed!
 * Panorama and HW layer revision.
 *
 * 11 30 2010 cathytr.huang
 * NULL
 * Panorama check in & HW layer revise.
 *
 * 11 23 2010 cathytr.huang
 * NULL
 * Revise MEM CAM memory.
 *
 * 11 22 2010 cathytr.huang
 * NULL
 * Fix build error.
 *
 * 11 21 2010 cathytr.huang
 * NULL
 * New memory macro check in.
 *
 * 11 18 2010 cathytr.huang
 * NULL
 * Fix MT6276 capture issue.
 *
 * 11 17 2010 cathytr.huang
 * NULL
 * Remove jpeg header.
 *
 * 11 17 2010 cathytr.huang
 * NULL
 * MED CAM FD revise code.
 *
 * 11 11 2010 bin.han
 * NULL
 * .Check in capture profiling
 *
 * 11 11 2010 cathytr.huang
 * NULL
 * Remove the old ISP API from MED CAM.
 *
 * 11 10 2010 cathytr.huang
 * NULL
 * Fix continue shot issue .
 *
 * 11 10 2010 cathytr.huang
 * NULL
 * Revise code.
 *
 * 11 10 2010 cathytr.huang
 * NULL
 * Revise FD external memory.
 *
 * 11 08 2010 cathytr.huang
 * NULL
 * Add MT6276/6255 raw capture buffer.
 *
 * 11 08 2010 cathytr.huang
 * NULL
 * Revise sensor query function.
 *
 * 11 05 2010 cathytr.huang
 * NULL
 * Add capture with thumbnail and get AF zone.
 *
 * 11 04 2010 cathytr.huang
 * NULL
 * Revise code.
 *
 * 11 04 2010 cathytr.huang
 * NULL
 * Revise code.
 *
 * 11 03 2010 cathytr.huang
 * NULL
 * Fix MED CAM BSS and continue shot.
 *
 * 11 02 2010 cathytr.huang
 * NULL
 * Camcorder adds HW layer usage for making tearing free.
 *
 * 11 02 2010 cathytr.huang
 * NULL
 * HW layer revise and enlarge memory size for concurrency.
 *
 * 11 01 2010 cathytr.huang
 * NULL
 * Remove some redundant codes .
 *
 * 11 01 2010 cathytr.huang
 * NULL
 * Fix BSS buffer issue.
 *
 * 10 31 2010 cathytr.huang
 * NULL
 * Fix Burstshot capture.
 *
 * 10 29 2010 cathytr.huang
 * NULL
 * Modify MED CAM BSS code.
 *
 * 10 29 2010 cathytr.huang
 * NULL
 * .
 *
 * 10 28 2010 cathytr.huang
 * NULL
 * Fix zoom issue and FSAL handle.
 *
 * 10 27 2010 cathytr.huang
 * NULL
 * Fix MED camera capture timeout error.
 *
 * 10 26 2010 cathytr.huang
 * NULL
 * Fix "fail to capture" issue.
 *
 * 10 26 2010 cathytr.huang
 * NULL
 * .
 *
 * 10 25 2010 cathytr.huang
 * NULL
 * According to sensor rotate value, to decide CAL preview rotate value.
 *
 * 10 25 2010 cathytr.huang
 * NULL
 * Fix preview issue
 *
 * 10 23 2010 cathytr.huang
 * NULL
 * MED CAM check in
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by P4 VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef MED_NOT_PRESENT

/*==== INCLUDES =========*/
/* system includes */
#include "kal_release.h"
#include "kal_trace.h"

#include "app_ltlcom.h" /* Task message communiction */

#ifdef __YUVCAM_ENCODE_DIRECT_WRITE_FILE__
#include "FSAL.h"
#endif
#include "cache_sw.h"
#include "mmu.h"

/* local includes */
#include "med_global.h"
#include "med_main.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_smalloc.h"
#include "med_utility.h"
#include "cam_main.h"
#include "cam_v_main.h"
#include "cal_comm_def.h"
#include "fd_comm_def.h"        // face detection common define header file
#include "sd_comm_def.h"        // smile detection common define header file

#ifdef __MED_TVO_MOD__
#include "tv_out.h"
#include "tvo_main.h"
#endif /* __MED_TVO_MOD__ */

#ifdef __CAM_TRACE_ON__
#include "med_trc.h"
#endif

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "cal_api.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "kal_public_defs.h"
#include "mm_comm_def.h"
#include "string.h"
#include "pp_comm_def.h"
#include "cal_mem_def.h"
#include "pp_mem_def.h"
#include "drv_sw_features_mdp.h"
#ifdef __MED_CAM_MOD__

/**************************************************************************************************
 * External Functions Declaration
 **************************************************************************************************/
#if defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* defined(__MM_DEBUG_MEASURE__) */
#define MED_CAM_START_LOGGING(_symbol_)
#define MED_CAM_STOP_LOGGING(_symbol_)
#endif /* defined(__MM_DEBUG_MEASURE__) */

#if defined(__MED_MEM_DEBUG_ON__) && defined(__MTK_TARGET__) && !defined(WIN32)
kal_uint32 g_u32_cam_start_time;
kal_uint32 g_u32_cam_end_time;
kal_uint32 g_u32_cam_duration;
#define MED_CAM_GET_START_TIME(_trace_) \
        do{\
            kal_get_time(&g_u32_cam_start_time);\
        }while(0)
#define MED_CAM_GET_STOP_TIME_AND_PRINT_TRACE(_trace_)\
        do{\
            kal_get_time(&g_u32_cam_end_time);\
            g_u32_cam_duration = kal_ticks_to_milli_secs(g_u32_cam_end_time - g_u32_cam_start_time);\
            kal_trace(TRACE_GROUP_2,_trace_, g_u32_cam_duration,__LINE__);\
        }while(0)
#else /* defined(__MED_MEM_DEBUG_ON__) && defined(__MTK_TARGET__) && !defined(WIN32) */
#define MED_CAM_GET_START_TIME(_trace_)
#define MED_CAM_GET_STOP_TIME_AND_PRINT_TRACE(_trace_) 
#endif /* defined(__MED_MEM_DEBUG_ON__) && defined(__MTK_TARGET__) && !defined(WIN32) */

#if defined(SENSOR_ON_BODY)
#define CAM_MAIN_SENSOR_MIRROR  (0) // 1 : need to mirror
#elif defined(SENSOR_ON_COVER)
#define CAM_MAIN_SENSOR_MIRROR  (1) // 1 : need to mirror
#else
#define CAM_MAIN_SENSOR_MIRROR  (0)
#endif

#define CAM_SUB_SENSOR_MIRROR   (1)

#if defined(__MAIN_LCM_SCANLINE_ROTATION_0__)
#define MAIN_LCM_CROSS_SENSOR_ANGLE  (MM_IMAGE_ROTATE_0)
#elif defined(__MAIN_LCM_SCANLINE_ROTATION_90__)
#define MAIN_LCM_CROSS_SENSOR_ANGLE  (MM_IMAGE_ROTATE_270)
#elif defined(__MAIN_LCM_SCANLINE_ROTATION_180__)
#define MAIN_LCM_CROSS_SENSOR_ANGLE  (MM_IMAGE_ROTATE_180)
#elif defined(__MAIN_LCM_SCANLINE_ROTATION_270__)
#define MAIN_LCM_CROSS_SENSOR_ANGLE  (MM_IMAGE_ROTATE_90)
#else
#define MAIN_LCM_CROSS_SENSOR_ANGLE  (0)
#endif

#if defined(__SUB_LCM_SCANLINE_ROTATION_0__)
#define SUB_LCM_CROSS_SENSOR_ANGLE  (MM_IMAGE_ROTATE_0)
#elif defined(__SUB_LCM_SCANLINE_ROTATION_90__)
#define SUB_LCM_CROSS_SENSOR_ANGLE  (MM_IMAGE_ROTATE_270)
#elif defined(__SUB_LCM_SCANLINE_ROTATION_180__)
#define SUB_LCM_CROSS_SENSOR_ANGLE  (MM_IMAGE_ROTATE_180)
#elif defined(__SUB_LCM_SCANLINE_ROTATION_270__)
#define SUB_LCM_CROSS_SENSOR_ANGLE  (MM_IMAGE_ROTATE_90)
#else
#define SUB_LCM_CROSS_SENSOR_ANGLE  (0)
#endif

#if defined(SENSOR_ROTATE_0)
#define CAM_MAIN_SENSOR_ROTATE  (MM_IMAGE_ROTATE_0)
#elif defined(SENSOR_ROTATE_90)
#define CAM_MAIN_SENSOR_ROTATE  (MM_IMAGE_ROTATE_90)
#elif defined(SENSOR_ROTATE_180)
#define CAM_MAIN_SENSOR_ROTATE  (MM_IMAGE_ROTATE_180)
#elif defined(SENSOR_ROTATE_270)
#define CAM_MAIN_SENSOR_ROTATE  (MM_IMAGE_ROTATE_270)
#else
#define CAM_MAIN_SENSOR_ROTATE  (0)
#endif

#if defined(SUB_SENSOR_ROTATE_0)
#define CAM_SUB_SENSOR_ROTATE  (MM_IMAGE_ROTATE_0)
#elif defined(SUB_SENSOR_ROTATE_90)
#define CAM_SUB_SENSOR_ROTATE  (MM_IMAGE_ROTATE_90)
#elif defined(SUB_SENSOR_ROTATE_180)
#define CAM_SUB_SENSOR_ROTATE  (MM_IMAGE_ROTATE_180)
#elif defined(SUB_SENSOR_ROTATE_270)
#define CAM_SUB_SENSOR_ROTATE  (MM_IMAGE_ROTATE_270)
#else
#define CAM_SUB_SENSOR_ROTATE  (0)
#endif

#define CAM_ABS(val) (((val) < 0) ? -(val) : (val))

static void cam_free_capture_buffer(void);
void cam_free_working_buffer(void);
#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
static void cam_free_stitch_buffer(void);
#endif
static void cam_free_hdr_buffer(void);
void cam_capture_still_image_stop(void);
#if defined(__MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__MED_CAM_3D_IMAGE_SUPPORT__)
static void cam_mav_capture_image_stop(void);
static void cam_mav_stop_stitch(void);
static void cam_mav_start_stitch(void);
#endif
#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
static void cam_panorama_start_stitch(kal_uint32 working_buffer_address, kal_uint32 working_buffer_size);
static void cam_panorama_stop_stitch(void);
static void cam_panorama_stop_bg_stitch(void);
#endif
#if defined(__MED_CAM_HDR_SUPPORT__)
static void cam_hdr_start_process(void);
static void cam_hdr_stop_process(void);
#endif
/**************************************************************************************************
 * MACRO Definition
 **************************************************************************************************/
#define CAM_FREE_CAPTURE_BUFFER() cam_free_capture_buffer();

#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
#define CAM_FREE_STITCH_BUFFER() cam_free_stitch_buffer()
#else
#define CAM_FREE_STITCH_BUFFER()
#endif

#define CAM_FREE_HDR_BUFFER() cam_free_hdr_buffer()

#define CAM_PREVIEW_CHECK_IS_BUFFER_AVAILABLE(pointer)   do{\
                                    if (pointer == NULL)\
                                    {\
                                        CAM_FREE_CAPTURE_BUFFER();\
                                        cam_free_working_buffer();\
                                        cam_set_result(MED_RES_MEM_INSUFFICIENT);\
                                        CAM_SET_EVENT(CAM_EVT_PREVIEW);\
                                        return;\
                                    }\
                                }while(0)

#define CAM_CAPTURE_CHECK_IS_BUFFER_AVAILABLE(pointer)   do{\
                                    if (pointer == NULL)\
                                    {\
                                        CAM_FREE_HDR_BUFFER();\
                                        CAM_FREE_CAPTURE_BUFFER();\
                                        cam_free_working_buffer();\
                                        cam_set_result(MED_RES_MEM_INSUFFICIENT);\
                                        CAM_SET_EVENT(CAM_EVT_CAPTURE);\
                                        return;\
                                    }\
                                }while(0)
                                
#define CAM_CAPTURE_TIMEOUT_DURATION (5000)
#define CAM_FD_PROCESS_TIMEOUT_DURATION (20)
/**************************************************************************************************
 * Static Variables
 **************************************************************************************************/


/**************************************************************************************************
 * Static Functions Declaration
 **************************************************************************************************/
#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_CAMMED_ROCODE", rodata = "DYNAMIC_CODE_CAMMED_ROCODE"
#include "dcmgr.h" 
#endif


void cam_enter_state(kal_uint8 state)
{
    CAM_STATE_TRACE(state);
    cam_context_p->state = state;
}

void cam_wait_event(cam_wait_event_enum evt)
{
     kal_uint32 retrieved_events;
     CAM_WAIT_EVT(evt, __LINE__);
     kal_retrieve_eg_events(cam_context_p->cam_event, (evt), KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND);     
}


void cam_set_event(cam_wait_event_enum evt)
{
      kal_set_eg_events(cam_context_p->cam_event, (evt),KAL_OR);\
      CAM_SET_EVT(evt,__LINE__);                                \
}

void static cam_util_fit_box(
                kal_int32 bbox_width,
                kal_int32 bbox_height,
                kal_int32 src_width,
                kal_int32 src_height,
                kal_int32 *offset_x,
                kal_int32 *offset_y,
                kal_int32 *dest_width,
                kal_int32 *dest_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (src_width == 0 || src_height == 0 || bbox_width == 0 || bbox_height == 0)
    {
        *dest_width = 0;
        *dest_height = 0;
    }
    else if (src_width * bbox_height > src_height * bbox_width)
    {
        *dest_width = bbox_width;
        *dest_height = src_height * bbox_width / src_width;
    }
    else
    {
        *dest_width = src_width * bbox_height / src_height;
        *dest_height = bbox_height;
    }

    /* non-ratio resize if different is small. */
    {
        int diff;

        diff = CAM_ABS(*dest_height - bbox_height);
        if (diff <= 2 && *dest_width == bbox_width)
        {
            *dest_height = bbox_height;
        }

        diff = CAM_ABS(*dest_width - bbox_width);
        if (diff <= 2 && *dest_height == bbox_height)
        {
            *dest_width = bbox_width;
        }
    }

    *offset_x = (bbox_width - *dest_width) / 2;
    *offset_y = (bbox_height - *dest_height) / 2;

    if (*dest_width == 0)
    {
        *dest_width = 1;
    }
    if (*dest_height == 0)
    {
        *dest_height = 1;
    }

    if ((*dest_width & 0x1) == 1)
    {
        (*dest_width)++;
    }
    if ((*dest_height & 0x1) == 1)
    {
        (*dest_height)++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cam_extmem_switch_cachable_region
 * DESCRIPTION
 *  Switch cachable region
 * PARAMETERS
 *  mem_ptr     [OUT]
 *  size        [IN]
 *  b_cachable  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool cam_extmem_switch_cachable_region(kal_uint32* mem_ptr, kal_uint32 size, kal_bool is_cacheable)
{
#if defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (is_cacheable == KAL_FALSE && INT_QueryIsCachedRAM(*mem_ptr, size) == KAL_TRUE)
    {
        dynamic_switch_cacheable_region((void*)mem_ptr, size, PAGE_NO_CACHE);
        ret = KAL_TRUE;
    }
    else
    {
        if (INT_QueryIsNonCachedRAM(*mem_ptr, size) == KAL_TRUE)
        {
            dynamic_switch_cacheable_region((void*)mem_ptr, size, PAGE_CACHEABLE);
            ret = KAL_TRUE;
        }
    }

    return ret;
#else
    return 0;
#endif /* (defined(MT6235) || defined(MT6235B)) && defined(__MTK_TARGET__) && defined(__ARM9_MMU__) */    
}


/*****************************************************************************
 * FUNCTION
 *  cam_alloc_capture_buffer
 * DESCRIPTION
 *  This function is to allocate capture buffer.
 * PARAMETERS
 *  size        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_alloc_capture_buffer(kal_uint16 app_id, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(!cam_context_p->capture_buffer_p); // should free capture buffer before allocating.

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
    size = ((size + 31) >> 5) << 5;
#endif
    cam_context_p->capture_buffer_p = (kal_uint32) med_alloc_asm_mem_cacheable(app_id, size);
    cam_context_p->capture_buffer_size = size;

    cam_extmem_switch_cachable_region(&cam_context_p->capture_buffer_p, cam_context_p->capture_buffer_size, KAL_FALSE);

}


/*****************************************************************************
 * FUNCTION
 *  cam_allocate_memory_for_framebuffer
 * DESCRIPTION
 *  Release internal/external memory used in video module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cam_profiling_log(kal_uint32 stage)
{
#if defined(__MTK_INTERNAL__) && defined(__MED_CAM_PROFILING_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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


/*****************************************************************************
 * FUNCTION
 *  cam_open_image_file
 * DESCRIPTION
 *  This function is to open image file for capture.
 * PARAMETERS
 *  file_name       [IN]
 * RETURNS
 *  open result
 *****************************************************************************/
kal_int32 cam_open_image_file(kal_wchar *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
#ifdef __YUVCAM_ENCODE_DIRECT_WRITE_FILE__
    FSAL_Status fsal_ret;
    kal_int32 fsal_error;
#endif    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if the format valid */
    /* open the file */
    if (cam_context_p->open_file_name_p)
        return MED_RES_OPEN_FILE_FAIL; // one file has opened, please close it firstly.

    cam_context_p->open_file_name_p = file_name;
#ifdef __YUVCAM_ENCODE_DIRECT_WRITE_FILE__    
    fsal_ret = FSAL_Open(&cam_context_p->fsal_file, (void*)file_name, FSAL_WRITE);
    if (fsal_ret != FSAL_OK)
    {
        cam_context_p->open_file_name_p = NULL;
        fsal_error = FSAL_GetLastError(&cam_context_p->fsal_file);
        if (fsal_error == FS_DRIVE_NOT_FOUND)
        {
            return MED_RES_NO_DISC;
        }
        else if (fsal_error == FS_DISK_FULL)
        {
            return MED_RES_DISC_FULL;
        }
        else
        {
            return MED_RES_OPEN_FILE_FAIL;
        }
    }
        
    FSAL_SetBuffer(&cam_context_p->fsal_file, MAX_JPEG_ENCODE_MARGIN_LEN, (kal_uint8 *)cam_context_p->capture_buffer_p);
#else
    cam_context_p->file_handle = FS_Open((kal_wchar*) file_name, FS_CREATE | FS_READ_WRITE);

    if (cam_context_p->file_handle >= 0)
    {
        /* Check free memory space first */
        if ((result = med_check_disc_space(file_name, CAPTURE_MEM_MARGIN)) != MED_RES_OK)
        {
            FS_Close(cam_context_p->file_handle);
            FS_Delete((kal_wchar*) file_name);
            cam_context_p->open_file_name_p = NULL;
            return result;
        }           
    }
    else
    {
        cam_context_p->open_file_name_p = NULL;
        if (cam_context_p->file_handle == FS_WRITE_PROTECTION)
        {
            return MED_RES_WRITE_PROTECTION;
        }
        else if ((cam_context_p->file_handle == FS_ROOT_DIR_FULL) || (cam_context_p->file_handle == FS_DISK_FULL))
        {
            return MED_RES_DISC_FULL;
        }
        else
        {
            return MED_RES_OPEN_FILE_FAIL;
        }
    }
#endif    
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cam_close_image_file
 * DESCRIPTION
 *  This function is to close image file for capture.
 * PARAMETERS
 *  size        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 cam_write_close_image_file(kal_uint32 address, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
#ifdef __YUVCAM_ENCODE_DIRECT_WRITE_FILE__
    kal_int32 fsal_error;
    FSAL_Status fsal_ret;
#endif
    kal_uint32 len;
    kal_int32 res = MED_RES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __YUVCAM_ENCODE_DIRECT_WRITE_FILE__    
    result = (kal_int32)size;
    fsal_error = FSAL_GetLastError(&cam_context_p->fsal_file);       
    fsal_ret = FSAL_Close(&cam_context_p->fsal_file);
    
    if (!(result > 0) || fsal_ret == FSAL_CLOSE_ERROR)
    {
        FS_Delete((kal_wchar*) cam_context_p->open_file_name_p);

        if (fsal_ret == FSAL_CLOSE_ERROR)
        {
            fsal_error = FSAL_GetLastError(&cam_context_p->fsal_file);
            result = JPEG_SW_ENC_WRITE_FILE_FAILED;
        }
        
        if (result == JPEG_SW_ENC_OUT_OF_OUTPUT_BUFFER)
        {
            res = MED_RES_ERROR;
        }
        else if (result == JPEG_SW_ENC_WRITE_FILE_FAILED)
        {
            if (fsal_error == FS_DRIVE_NOT_FOUND)
            {
                res = MED_RES_NO_DISC;
            }
            else if (fsal_error == FS_DISK_FULL)
            {
                res = MED_RES_DISC_FULL;
            }
            else
            {
                res = MED_RES_OPEN_FILE_FAIL;
            }
        }
        else
        {
            res = MED_RES_OPEN_FILE_FAIL;
        }
    }
#else
    if (size > 0)
    {
        MED_CAM_GET_START_TIME(CAM_WRITE_TO_FILE_DURATION);
        MED_CAM_START_LOGGING("CFS");
        result = FS_Write(cam_context_p->file_handle, (void*)address, size, &len);
        MED_CAM_STOP_LOGGING("CFS");

        MED_CAM_START_LOGGING("CFC");
        FS_Close(cam_context_p->file_handle);
        MED_CAM_STOP_LOGGING("CFC");
        MED_CAM_GET_STOP_TIME_AND_PRINT_TRACE(CAM_WRITE_TO_FILE_DURATION);

        if (result != FS_NO_ERROR)
        {
            CAM_CLOSE_IMAGE_RESULT_TRACE(result);
            FS_Delete((kal_wchar*) cam_context_p->open_file_name_p);
            if (result == FS_DRIVE_NOT_FOUND)
            {
                res = MED_RES_NO_DISC;
            }
            else if (result == FS_DISK_FULL)
            {
                res = MED_RES_DISC_FULL;
            }
            else
            {
                res = MED_RES_OPEN_FILE_FAIL;
            }
        }
        else if (size != len)
        {
            FS_Delete((kal_wchar*) cam_context_p->open_file_name_p);
            res = MED_RES_DISC_FULL;
        }
    }
    else
    {
        /* Close and delete the file */
        FS_Close(cam_context_p->file_handle);
        FS_Delete((kal_wchar*) cam_context_p->open_file_name_p);
        res = MED_RES_DISC_FULL;
    }
#endif

    cam_profiling_log(CAL_CAMERA_PROFILING_JPEG_SAVE_FILE_DONE);

    cam_context_p->open_file_name_p = NULL;
    return res;
}


#if defined (ISP_SUPPORT)
/*****************************************************************************
 * FUNCTION
 *  cam_quickview_image_callback
 * DESCRIPTION
 *  This function is to handle camera quick view image ready callback.
 * PARAMETERS
 *  cause       [IN]
 *  ilm_struct *ilm_ptr(?)
 * RETURNS
 *  void
 *****************************************************************************/
void cam_quickview_image_callback(void *pCallbackPara, kal_uint16 CallbackParaLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    P_CAL_BUFFER_CB_STRUCT quickview_ptr;
    kal_uint8 result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    quickview_ptr = (P_CAL_BUFFER_CB_STRUCT)pCallbackPara;
    cam_context_p->is_quickview_ready = KAL_TRUE;

    if (quickview_ptr->ErrorStatus == MM_ERROR_NONE)
        result = MED_RES_OK;
    else
        result = MED_RES_FAIL;

    cam_send_event_ind(CAM_EVT_QUICKVIEW, result);

}


/*****************************************************************************
 * FUNCTION
 *  cam_quickview_image_callback
 * DESCRIPTION
 *  This function is to handle camera thunbnail image ready callback.
 * PARAMETERS
 *  cause       [IN]
 *  ilm_struct *ilm_ptr(?)
 * RETURNS
 *  void
 *****************************************************************************/
void cam_thumbnail_image_callback(void *pCallbackPara, kal_uint16 CallbackParaLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    P_CAL_BUFFER_CB_STRUCT thumbnail_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    thumbnail_ptr = (P_CAL_BUFFER_CB_STRUCT)pCallbackPara;

    cam_context_p->thumbnail_image_address = thumbnail_ptr->ImageBuffAddr;
    cam_context_p->thumbnail_image_size    = thumbnail_ptr->ImageBuffSize;
    cam_context_p->is_thumbnail_ready      = KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  cam_panorama_image_reday_callback
 * DESCRIPTION
 *  This function is to handle camera main jpeg image ready callback.
 * PARAMETERS
 *  cause       [IN]
 *  ilm_struct *ilm_ptr(?)
 * RETURNS
 *  void
 *****************************************************************************/
void cam_panorama_image_reday_callback(void *pCallbackPara, kal_uint16 CallbackParaLen)
{
#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    P_CAL_BUFFER_CB_STRUCT image_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    image_ptr = (P_CAL_BUFFER_CB_STRUCT)pCallbackPara;
    
    if (image_ptr->ErrorStatus == MM_ERROR_NONE)
    {       
        cam_context_p->stitch_image_format = image_ptr->ImageBuffFormat;
        if (image_ptr->ImageBuffFormat == MM_IMAGE_FORMAT_JPEG)
        {
            cam_context_p->stitch_image_address = image_ptr->ImageBuffAddr;
            cam_context_p->stitch_image_size    = image_ptr->ImageBuffSize;
        }
        else
        {
            cam_context_p->stitch_image_address = image_ptr->ImageBuffYAddr;
            cam_context_p->stitch_image_size = 
                                    image_ptr->ImageBuffYSize + 
                                    image_ptr->ImageBuffUSize + 
                                    image_ptr->ImageBuffVSize;
        }
    }
    else
        cam_context_p->stitch_image_address = NULL;
    
    cam_context_p->captured_number++;
    
    cam_send_event_ind(CAM_EVT_PANO_IMG_READY, (kal_uint8)MED_RES_OK);
#endif /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */    
}



/*****************************************************************************
 * FUNCTION
 *  cam_panorama_bg_stitch_ready_callback
 * DESCRIPTION
 *  This function is to handle camera main jpeg image ready callback.
 * PARAMETERS
 *  cause       [IN]
 *  ilm_struct *ilm_ptr(?)
 * RETURNS
 *  void
 *****************************************************************************/
void cam_panorama_bg_stitch_ready_callback(void *pCallbackPara, kal_uint16 CallbackParaLen)
{
#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->bg_stitch_count = (kal_uint32)pCallbackPara;

    cam_send_event_ind(CAM_EVT_PANO_BG_STITCH_READY, (kal_uint8)MED_RES_OK);
#endif /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */    
}


/*****************************************************************************
 * FUNCTION
 *  cam_panorama_stitch_ready_callback
 * DESCRIPTION
 *  This function is to handle camera main jpeg image ready callback.
 * PARAMETERS
 *  cause       [IN]
 *  ilm_struct *ilm_ptr(?)
 * RETURNS
 *  void
 *****************************************************************************/
void cam_panorama_stitch_ready_callback(void *pCallbackPara, kal_uint16 CallbackParaLen)
{
#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    P_CAL_PANO_RESULT_STRUCT jpeg_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jpeg_ptr = (P_CAL_PANO_RESULT_STRUCT)pCallbackPara;
       
    cam_context_p->stitch_jpeg_file_address = jpeg_ptr->ImageBuffAddr;
    cam_context_p->stitch_jpeg_file_size    = jpeg_ptr->ImageBuffSize;
    cam_context_p->stitch_jpeg_file_width   = jpeg_ptr->ImgWidth;
    cam_context_p->stitch_jpeg_file_height  = jpeg_ptr->ImgHeight;

    if (jpeg_ptr->ErrorStatus == MM_ERROR_NONE)
        cam_context_p->stitch_result = MED_RES_OK;
    else
        cam_context_p->stitch_result = MED_RES_FAIL;
    
    cam_send_event_ind(CAM_EVT_PANO_STITCH_READY, (kal_uint8)MED_RES_OK);

#endif /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */    
}

/*****************************************************************************
 * FUNCTION
 *  cam_panorama_stitch_ready_callback
 * DESCRIPTION
 *  This function is to handle camera main jpeg image ready callback.
 * PARAMETERS
 *  cause       [IN]
 *  ilm_struct *ilm_ptr(?)
 * RETURNS
 *  void
 *****************************************************************************/
void cam_panorama_quickview_image_ready_callback(void *pCallbackPara, kal_uint16 CallbackParaLen)
{
#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    P_CAL_BUFFER_CB_STRUCT_AUTORAMA quickview_ptr; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    quickview_ptr = (P_CAL_BUFFER_CB_STRUCT_AUTORAMA)pCallbackPara;
    cam_context_p->stitch_quickview_start_x = quickview_ptr->PanoStartX;
    cam_context_p->stitch_quickview_start_y    = quickview_ptr->PanoStartY;
    cam_context_p->stitch_quickview_width   = quickview_ptr->PanoWidth;
    cam_context_p->stitch_quickview_height  = quickview_ptr->PanoHeight;
    
    cam_send_event_ind(CAM_EVT_PANO_QUICKVIEW_READY, (kal_uint8)MED_RES_OK);
#endif /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */    
}


/*****************************************************************************
 * FUNCTION
 *  cam_autocap_result_callback
 * DESCRIPTION
 *  CAL callback function
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void cam_autocap_result_callback(void *pCallbackPara, kal_uint16 CallbackParaLen)
{
#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    P_AUTOCAP_RESULT_STRUCT pAutoCapRsult;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pAutoCapRsult = (P_AUTOCAP_RESULT_STRUCT)pCallbackPara;

    memset(&cam_context_p->autocap_result, 0, sizeof(AUTOCAP_RESULT_STRUCT));

    cam_context_p->autocap_result.MV_X = pAutoCapRsult->MV_X;
    cam_context_p->autocap_result.MV_Y = pAutoCapRsult->MV_Y;
    cam_context_p->autocap_result.ImageWidth = pAutoCapRsult->ImageWidth;
    cam_context_p->autocap_result.ImageHeight = pAutoCapRsult->ImageHeight;
    cam_context_p->autocap_result.OverlapRatio = pAutoCapRsult->OverlapRatio;
    cam_context_p->autocap_result.ReadyToShot = pAutoCapRsult->ReadyToShot;
    cam_context_p->autocap_result.Direction = pAutoCapRsult->Direction;
    cam_context_p->autocap_result.HintDirection = pAutoCapRsult->HintDirection;
   
#endif /* defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__) */
}

/*****************************************************************************
 * FUNCTION
 *  cam_mav_capture_image_ready_callback
 * DESCRIPTION
 *  This function is to handle mav capture image ready callback.
 * PARAMETERS
 *  cause       [IN]
 *  ilm_struct *ilm_ptr(?)
 * RETURNS
 *  void
 *****************************************************************************/
void cam_mav_capture_image_ready_callback(void *pCallbackPara, kal_uint16 CallbackParaLen)
{
#if defined(__MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined (__MED_CAM_3D_IMAGE_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    P_CAL_MAV_CAP_RESULT_STRUCT pMavCapResult; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pMavCapResult = (P_CAL_MAV_CAP_RESULT_STRUCT)pCallbackPara;
    cam_context_p->mav_cap_result.CurrentImageNumber = pMavCapResult->CurrentImageNumber;
    cam_context_p->mav_cap_result.TotalImageNumber = pMavCapResult->TotalImageNumber;
    
    if(CAM_IN_STATE(CAM_CAPTURE))
    {
        cam_send_event_ind(CAM_EVT_MAV_CAPTURE_IMG_READY, (kal_uint8)MED_RES_OK);
    }
    else
        ASSERT(0);
#endif /* __MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__||__MED_CAM_3D_IMAGE_SUPPORT__*/    
}

/*****************************************************************************
 * FUNCTION
 *  cam_mav_result_callback
 * DESCRIPTION
 *  CAL callback function
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void cam_mav_result_callback(void *pCallbackPara, kal_uint16 CallbackParaLen)
{
#if defined(__MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined (__MED_CAM_3D_IMAGE_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    P_CAL_MAV_RESULT_STRUCT pMavRsult;
    kal_uint8 result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pMavRsult = (P_CAL_MAV_RESULT_STRUCT)pCallbackPara;

    memset(&cam_context_p->mav_result, 0, sizeof(CAL_MAV_RESULT_STRUCT));
    
    if (pMavRsult->ErrorStatus == MM_ERROR_NONE)        
        result = MED_RES_OK;
    else
        result = MED_RES_FAIL;
        
    cam_context_p->mav_result.EncodeDstBufferAddr = pMavRsult->EncodeDstBufferAddr;
    cam_context_p->mav_result.EncodeDstBufferSize = pMavRsult->EncodeDstBufferSize;
    
    cam_send_event_ind(CAM_EVT_MAV_STITCH_IMG_READY, (kal_uint8)result);
   
#endif /* defined(__MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined (__MED_CAM_3D_IMAGE_SUPPORT__) */
}

/*****************************************************************************
 * FUNCTION
 *  cam_main_jpeg_image_callback
 * DESCRIPTION
 *  This function is to handle camera main jpeg image ready callback.
 * PARAMETERS
 *  cause       [IN]
 *  ilm_struct *ilm_ptr(?)
 * RETURNS
 *  void
 *****************************************************************************/
void cam_main_jpeg_image_callback(void *pCallbackPara, kal_uint16 CallbackParaLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    P_CAL_BUFFER_CB_STRUCT jpeg_ptr;
    kal_uint8 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jpeg_ptr = (P_CAL_BUFFER_CB_STRUCT)pCallbackPara;

    cam_context_p->jpeg_image_address = jpeg_ptr->ImageBuffAddr;
    cam_context_p->jpeg_image_size    = jpeg_ptr->ImageBuffSize;

    cam_context_p->captured_number++;

    if (jpeg_ptr->ErrorStatus == MM_ERROR_NONE)
        result = MED_RES_OK;
    else
        result = MED_RES_FAIL;

    cam_send_event_ind(CAM_EVT_CAPTURE, (kal_uint8)result);
}


/*****************************************************************************
 * FUNCTION
 *  cam_focus_callback
 * DESCRIPTION
 *  This function is to handle camera focus callback.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void cam_focus_callback(void *pCallbackPara, kal_uint16 CallbackParaLen)
{
#ifdef AF_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    P_CAL_CAMERA_AF_RESULT_STRUCT pAfResult;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pAfResult = (P_CAL_CAMERA_AF_RESULT_STRUCT)pCallbackPara;

    kal_mem_cpy((void*)&cam_context_p->af_result, (void*)pAfResult, sizeof(CAL_CAMERA_AF_RESULT_STRUCT));
    
    cam_send_event_ind(CAM_EVT_AUTOFOCUS, (kal_uint8)pAfResult->AfSearchResult);
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  cam_fd_result_callback
 * DESCRIPTION
 *  CAL callback function
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void cam_fd_result_callback(void *pCallbackPara, kal_uint16 CallbackParaLen)
{
#if defined(__MED_CAM_FD_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    P_FD_RESULT_STRUCT pFdRsult;
    kal_uint8 i = 0;
    float width_ratio = 0;
    float height_ratio = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pFdRsult = (P_FD_RESULT_STRUCT)pCallbackPara;

    memset(&cam_context_p->fd_result, 0, sizeof(FD_RESULT_STRUCT));

    width_ratio = cam_context_p->preview_width/(float)pFdRsult->image_width;
    height_ratio = cam_context_p->preview_height/(float)pFdRsult->image_height;
    
    cam_context_p->fd_result.face_no = pFdRsult->face_no;
    cam_context_p->fd_result.image_width = pFdRsult->image_width;
    cam_context_p->fd_result.image_height = pFdRsult->image_height;
    
    for (i = 0; i < cam_context_p->fd_result.face_no; i++)
    {
        if (cam_context_p->included_angle == MM_IMAGE_ROTATE_90 || cam_context_p->included_angle == MM_IMAGE_ROTATE_270)
        {
            cam_context_p->fd_result.rect_x0[i] = (pFdRsult->image_height - pFdRsult->rect_y1[i]) * height_ratio;
            cam_context_p->fd_result.rect_x1[i] = (pFdRsult->image_height - pFdRsult->rect_y0[i]) * height_ratio;
            cam_context_p->fd_result.rect_y0[i] = pFdRsult->rect_x0[i] * width_ratio;
            cam_context_p->fd_result.rect_y1[i] = pFdRsult->rect_x1[i] * width_ratio;
        }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif        
        else
        {
            cam_context_p->fd_result.rect_x0[i] = pFdRsult->rect_x0[i] * width_ratio;
            cam_context_p->fd_result.rect_x1[i] = pFdRsult->rect_x1[i] * width_ratio;
            cam_context_p->fd_result.rect_y0[i] = pFdRsult->rect_y0[i] * height_ratio;
            cam_context_p->fd_result.rect_y1[i] = pFdRsult->rect_y1[i] * height_ratio;
        }
    }
    
#endif /* defined(__MED_CAM_FD_SUPPORT__) && (MT6225_SERIES) */
}


/*****************************************************************************
 * FUNCTION
 *  cam_fd_result_callback
 * DESCRIPTION
 *  CAL callback function
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void cam_sd_result_callback(void *pCallbackPara, kal_uint16 CallbackParaLen)
{
#if defined(__MED_CAM_FD_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    P_SD_RESULT_STRUCT pFdRsult;
    kal_uint8 i = 0;
    float width_ratio = 0;
    float height_ratio = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pFdRsult = (P_SD_RESULT_STRUCT)pCallbackPara;

    kal_mem_cpy((void*)&cam_context_p->sd_result, (void*)pFdRsult, sizeof(SD_RESULT_STRUCT));

    width_ratio = cam_context_p->preview_width/(float)pFdRsult->image_width;
    height_ratio = cam_context_p->preview_height/(float)pFdRsult->image_height;

    for (i = 0; i < cam_context_p->sd_result.face_no; i++)
    {
        if (cam_context_p->included_angle == MM_IMAGE_ROTATE_90 || cam_context_p->included_angle == MM_IMAGE_ROTATE_270)
        {
            cam_context_p->sd_result.rect_x0[i] = (pFdRsult->image_height - pFdRsult->rect_y1[i]) * height_ratio;
            cam_context_p->sd_result.rect_x1[i] = (pFdRsult->image_height - pFdRsult->rect_y0[i]) * height_ratio;
            cam_context_p->sd_result.rect_y0[i] = pFdRsult->rect_x0[i] * width_ratio;
            cam_context_p->sd_result.rect_y1[i] = pFdRsult->rect_x1[i] * width_ratio;
        }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        else
        {
            cam_context_p->sd_result.rect_x0[i] *= width_ratio;
            cam_context_p->sd_result.rect_x1[i] *= width_ratio;
            cam_context_p->sd_result.rect_y0[i] *= height_ratio;
            cam_context_p->sd_result.rect_y1[i] *= height_ratio;
        }
    }

    for (i = 0; i < cam_context_p->sd_result.smile_detected_no; i++)
    {
        if (cam_context_p->included_angle == MM_IMAGE_ROTATE_90 || cam_context_p->included_angle == MM_IMAGE_ROTATE_270)
        {
            cam_context_p->sd_result.sd_rect_x0[i] = (pFdRsult->image_height - pFdRsult->sd_rect_y1[i]) * height_ratio;
            cam_context_p->sd_result.sd_rect_x1[i] = (pFdRsult->image_height - pFdRsult->sd_rect_y0[i]) * height_ratio;
            cam_context_p->sd_result.sd_rect_y0[i] = pFdRsult->sd_rect_x0[i] * width_ratio;
            cam_context_p->sd_result.sd_rect_y1[i] = pFdRsult->sd_rect_x1[i] * width_ratio;        
        }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        else
        {
            cam_context_p->sd_result.sd_rect_x0[i] *= width_ratio;
            cam_context_p->sd_result.sd_rect_x1[i] *= width_ratio;
            cam_context_p->sd_result.sd_rect_y0[i] *= height_ratio;
            cam_context_p->sd_result.sd_rect_y1[i] *= height_ratio;        
        }
    }
#endif /* defined(__MED_CAM_FD_SUPPORT__) && (MT6225_SERIES) */
}

/*****************************************************************************
 * FUNCTION
 *  cam_hdr_quickview_image_callback
 * DESCRIPTION
 *  CAL callback function
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void cam_hdr_quickview_image_callback(void *pCallbackPara, kal_uint16 CallbackParaLen)
{
#if defined(__MED_CAM_HDR_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    P_CAL_BUFFER_CB_STRUCT quickview_ptr;
    kal_uint8 result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    quickview_ptr = (P_CAL_BUFFER_CB_STRUCT)pCallbackPara;

    if (quickview_ptr->ErrorStatus == MM_ERROR_NONE)
        result = MED_RES_OK;
    else
        result = MED_RES_FAIL;

    cam_send_event_ind(CAM_EVT_HDR_QUICKVIEW, result);

#endif /* defined(__MED_CAM_HDR_SUPPORT__) */
}


/*****************************************************************************
 * FUNCTION
 *  cam_hdr_main_jpeg_image_callback
 * DESCRIPTION
 *  CAL callback function
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void cam_hdr_main_jpeg_image_callback(void *pCallbackPara, kal_uint16 CallbackParaLen)
{
#if defined(__MED_CAM_HDR_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    P_CAL_HDR_RESULT_STRUCT jpeg_ptr;
    kal_uint8 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jpeg_ptr = (P_CAL_HDR_RESULT_STRUCT)pCallbackPara;

    cam_context_p->hdr_dst_image_p = jpeg_ptr->ImageBuffAddr;
    cam_context_p->hdr_dst_image_size = jpeg_ptr->ImageBuffSize;

    if (jpeg_ptr->ErrorStatus == MM_ERROR_NONE)
        result = MED_RES_OK;
    else
        result = MED_RES_FAIL;

    cam_send_event_ind(CAM_EVT_HDR_MAINIMAGE, (kal_uint8)result);

#endif /* defined(__MED_CAM_HDR_SUPPORT__) */
}

MM_ERROR_CODE_ENUM cam_cal_callback(CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen)
{
#if defined (ISP_SUPPORT)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (CbId == CAL_CBID_QUICK_VIEW_IMAGE_READY)
    {
        cam_quickview_image_callback(pCallbackPara, CallbackParaLen);
    }
    else if (CbId == CAL_CBID_THUMBNAIL_IMAGE_READY)
    {
        cam_thumbnail_image_callback(pCallbackPara, CallbackParaLen);
    }
    else if (CbId == CAL_CBID_STILL_IMAGE_READY)
    {
        cam_main_jpeg_image_callback(pCallbackPara, CallbackParaLen);
    }
    #if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
    else if (CbId == CAL_CBID_PANO_IMAGE_READY)
    {
        cam_panorama_image_reday_callback(pCallbackPara, CallbackParaLen);
    }
    else if (CbId == CAL_CBID_PANO_BG_ADD_IMAGE_READY)
    {
        cam_panorama_bg_stitch_ready_callback(pCallbackPara, CallbackParaLen);
    }
    else if (CbId == CAL_CBID_PANO_RESULT)
    {
        cam_panorama_stitch_ready_callback(pCallbackPara, CallbackParaLen);
    }
    else if (CbId == CAL_CBID_PANO_QUICK_VIEW_IMAGE_READY)
    {
        cam_panorama_quickview_image_ready_callback(pCallbackPara, CallbackParaLen);
    }
    else if (CbId == CAL_CBID_AUTOCAP_RESULT)
    {
        cam_autocap_result_callback(pCallbackPara, CallbackParaLen);
    }
    #endif
    #if defined(__MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined (__MED_CAM_3D_IMAGE_SUPPORT__)
    else if (CbId == CAL_CBID_MAV_CAPTURE_IMAGE_READY)
    {
        cam_mav_capture_image_ready_callback(pCallbackPara, CallbackParaLen);        
    }
    else if (CbId == CAL_CBID_MAV_STITCH_IMAGE_READY)
    {
        cam_mav_result_callback(pCallbackPara, CallbackParaLen);        
    }
    #endif 
    #ifdef AF_SUPPORT
    else if (CbId == CAL_CBID_AF_RESULT)
    {
        cam_focus_callback(pCallbackPara, CallbackParaLen);
    }
    #endif
    #if defined(__MED_CAM_FD_SUPPORT__)
    else if (CbId == CAL_CBID_FD_RESULT)
    {
        cam_fd_result_callback(pCallbackPara, CallbackParaLen);
    }
    else if (CbId == CAL_CBID_SD_RESULT)
    {
        cam_sd_result_callback(pCallbackPara, CallbackParaLen);
    }
#ifdef __CAL_CAPTURE_MODE_ASD_SUPPORT__
    else if (CAL_CBID_ASD_RESULT == CbId)
    {
        cam_context_p->camera_scene_detected_mode=(kal_uint8) *((kal_uint8 *)pCallbackPara);
    }
#endif
    #endif /* __MED_CAM_FD_SUPPORT__ */
    #if defined(__MED_CAM_HDR_SUPPORT__)    
    else if (CbId == CAL_CBID_HDR_QUICK_VIEW_IMAGE_READY)
    {
        cam_hdr_quickview_image_callback(pCallbackPara, CallbackParaLen);
    }
    else if (CbId == CAL_CBID_HDR_RESULT)
    {
        cam_hdr_main_jpeg_image_callback(pCallbackPara, CallbackParaLen);
    }
    #endif /* __MED_CAM_HDR_SUPPORT__ */    
#endif
    return MM_ERROR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  cam_set_camera_id_req_hdlr
 * DESCRIPTION
 *  This function is to select main/sub sensor.
 * PARAMETERS
 *  ilm_ptr     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_set_camera_id_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_set_camera_id_req_struct* req_p;
    CAL_FEATURE_CTRL_STRUCT CalInPara;
    MM_ERROR_CODE_ENUM ret = MM_ERROR_NONE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    ASSERT(CAM_IN_STATE(CAM_IDLE));
        
    req_p = (media_cam_set_camera_id_req_struct*)ilm_ptr->local_para_ptr;
    cam_context_p->cam_id = req_p->cam_id;

    if (CAM_IN_STATE(CAM_IDLE))
    {
        // Select main or sub sensor
        CalInPara.FeatureId = CAL_FEATURE_CAMERA_SOURCE_SELECT;
        CalInPara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
        CalInPara.FeatureSetValue = (kal_uint32)cam_context_p->cam_id;
        ret = CalCtrl(CAL_FEATURE_CTRL, (void*)&CalInPara, NULL, 0, NULL);
    }

    if (MM_ERROR_NONE == ret)
    {
        cam_set_result(MED_RES_OK);
    }
    else
    {
        cam_set_result(MED_RES_FAIL);
    }
    CAM_SET_EVENT(CAM_EVT_BLOCK);    
}


/*****************************************************************************
 * FUNCTION
 *  cam_sensor_query_capability_req_hdlr
 * DESCRIPTION
 *  This function is to query sensor capability information.
 * PARAMETERS
 *  ilm_ptr     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_sensor_query_capability_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_sensor_query_capability_req_struct *req_p = NULL;
    media_cam_qurey_sensor_general_capability_req_struct* info_p = NULL;
    media_cam_qurey_sensor_image_size_req_struct* image_size_p = NULL;
    media_cam_query_iso_binning_capability_req_struct* iso_p = NULL;
    media_cam_query_capture_overlay_req_struct* overlay_p= NULL;
    CAL_FEATURE_CTRL_STRUCT CalFeaturePara;
    CAL_FEATURE_CAMERA_BINNING_INFO_STRUCT BinningInfo;
    CAL_CAMERA_CAPTURE_OVERLAY_CAPABILITY_OUT_STRUCT CameraOverlayOut;
    P_CAL_FEATURE_TYPE_ENUM_STRUCT pCamInfo=(P_CAL_FEATURE_TYPE_ENUM_STRUCT) &(CalFeaturePara.FeatureInfo.FeatureEnum);
    kal_uint32 i = 0;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_cam_sensor_query_capability_req_struct*)ilm_ptr->local_para_ptr;
    
    if (CAM_IN_STATE(CAM_IDLE))
    {
        // Select main or sub sensor
        CalFeaturePara.FeatureId = CAL_FEATURE_CAMERA_SOURCE_SELECT;
        CalFeaturePara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
        CalFeaturePara.FeatureSetValue = (kal_uint32)cam_context_p->cam_id;
        CalFeaturePara.FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
        CalCtrl(CAL_FEATURE_CTRL, (void*)&CalFeaturePara, NULL, 0, NULL);
    }

    CalFeaturePara.FeatureId = req_p->item_id;        
    CalFeaturePara.FeatureCtrlCode = CAL_FEATURE_QUERY_OPERATION;
    CalFeaturePara.FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
    CalFeaturePara.CameraMode = req_p->camera_mode;
        
    if (req_p->item_id == CAL_FEATURE_CAMERA_BINNING_INFO) // CAL_FEATURE_TYPE_STRUCTURED
    {
        iso_p = (media_cam_query_iso_binning_capability_req_struct*)req_p->struct_p;
                
        CalFeaturePara.FeatureId=CAL_FEATURE_CAMERA_BINNING_INFO;
        CalFeaturePara.FeatureCtrlCode=CAL_FEATURE_QUERY_OPERATION;
        CalFeaturePara.FeatureInfo.FeatureStructured.pBinningInfo=&BinningInfo;
        CalCtrl(CAL_FEATURE_CTRL, &CalFeaturePara, &CalFeaturePara, sizeof(CalFeaturePara), NULL);
        
        kal_mem_cpy((void*)&(iso_p->IsoBinningInfo), (void*)&(BinningInfo.IsoBinningInfo), sizeof(BinningInfo));
    }
    else if (req_p->item_id == CAL_FEATUER_CAMERA_CAPTURE_OVERLAY_CAPABILITY) // CAL_FEATURE_TYPE_STRUCTURED
    {                    
        CalFeaturePara.FeatureInfo.FeatureStructured.pCamOverlayCap = &CameraOverlayOut;
        CalCtrl(CAL_FEATURE_CTRL, &CalFeaturePara, &CalFeaturePara, sizeof(CalFeaturePara), NULL);

        overlay_p = (media_cam_query_capture_overlay_req_struct*)req_p->struct_p;
        
        overlay_p->is_support = CameraOverlayOut.CaptureOverlaySupport;
    }
    else if (req_p->item_id == CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE_WITH_DIMENSION) // CAL_FEATURE_TYPE_ENUMERATE
    {                    
        image_size_p = (media_cam_qurey_sensor_image_size_req_struct*)req_p->struct_p;        
        CalFeaturePara.FeatureInfo.FeatureEnum.SupportItemInfo = (void *) image_size_p->image_size;	

        CalCtrl(CAL_FEATURE_CTRL, (void*)&CalFeaturePara, (void*)&CalFeaturePara, sizeof(CalFeaturePara), NULL);

        image_size_p->is_support = pCamInfo->IsSupport;
        image_size_p->item_count = pCamInfo->ItemCount;
        if (image_size_p->is_support)
        {
            ASSERT(MAX_CAMERA_SUPPORT_ITEM_COUNT >= pCamInfo->ItemCount);
            for (i=0;i<pCamInfo->ItemCount;i++)
            {
                   image_size_p->support_item[i] = pCamInfo->SupportItem[i];
            }
        }
        else
        {
            image_size_p->item_count = 0;
        }		
    }	
    else // CAL_FEATURE_TYPE_ENUMERATE
    {
	 CalFeaturePara.FeatureInfo.FeatureEnum.SupportItemInfo = NULL;
        CalCtrl(CAL_FEATURE_CTRL, (void*)&CalFeaturePara, (void*)&CalFeaturePara, sizeof(CalFeaturePara), NULL);
    
        info_p = (media_cam_qurey_sensor_general_capability_req_struct*)req_p->struct_p;

        info_p->is_support = pCamInfo->IsSupport;
        info_p->item_count = pCamInfo->ItemCount;

        if (info_p->is_support)
        {
            ASSERT(MAX_CAMERA_SUPPORT_ITEM_COUNT >= pCamInfo->ItemCount);
            for (i=0;i<pCamInfo->ItemCount;i++)
            {
                info_p->support_item[i] = pCamInfo->SupportItem[i];
            }
        }
        else
        {
            info_p->item_count = 0;
        }
    }
    
    cam_set_result(MED_RES_OK);
    CAM_SET_EVENT(CAM_EVT_BLOCK);     
}


/*****************************************************************************
 * FUNCTION
 *  cam_sensor_query_zoom_info_req_hdlr
 * DESCRIPTION
 *  This function is to query sensor zoom information.
 * PARAMETERS
 *  ilm_ptr     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_sensor_query_zoom_info_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_FEATURE_CTRL_STRUCT CalInPara, CalOutPara;
    CAL_CAMERA_DIGITAL_ZOOM_IN_STRUCT zoomInPara;
    CAL_CAMERA_DIGITAL_ZOOM_OUT_STRUCT zoomOutPara;
    media_cam_zoom_capability_req_struct* req_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CAM_IN_STATE(CAM_IDLE))
    {
        // Select main or sub sensor
        CalInPara.FeatureId = CAL_FEATURE_CAMERA_SOURCE_SELECT;
        CalInPara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
        CalInPara.FeatureSetValue = (kal_uint32)cam_context_p->cam_id;
        CalInPara.FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
        CalCtrl(CAL_FEATURE_CTRL, (void*)&CalInPara, (void*)&CalOutPara, sizeof(CalOutPara), NULL);

    }
    req_p = (media_cam_zoom_capability_req_struct*)ilm_ptr->local_para_ptr;

    CalInPara.FeatureId = CAL_FEATURE_CAMERA_DIGITAL_ZOOM;
    CalInPara.FeatureCtrlCode = CAL_FEATURE_QUERY_OPERATION;
    CalInPara.FeatureInfo.FeatureStructured.pCamDzInPara = &zoomInPara;
    CalInPara.CameraMode = req_p->camera_mode;
    CalOutPara.FeatureInfo.FeatureStructured.pCamDzOutPara = &zoomOutPara;

    zoomInPara.CameraImageSize = (CAM_IMAGE_SIZE_ENUM)req_p->image_size;
    CalCtrl(CAL_FEATURE_CTRL, (void*)&CalInPara, (void*)&CalOutPara, sizeof(CalOutPara), NULL);

    req_p->result_p->DzType = CalOutPara.FeatureInfo.FeatureStructured.pCamDzOutPara->DzType;
    req_p->result_p->MaxZoomFactor = CalOutPara.FeatureInfo.FeatureStructured.pCamDzOutPara->MaxZoomFactor;
    req_p->result_p->TotalZoomSteps = CalOutPara.FeatureInfo.FeatureStructured.pCamDzOutPara->TotalZoomSteps;
    req_p->result_p->pZoomFactorListTable = CalOutPara.FeatureInfo.FeatureStructured.pCamDzOutPara->pZoomFactorListTable;
    
    cam_set_result(MED_RES_OK);
    CAM_SET_EVENT(CAM_EVT_BLOCK);
}


/*****************************************************************************
 * FUNCTION
 *  cam_free_capture_buffer
 * DESCRIPTION
 *  This function is to release cam related memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cam_free_capture_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MED_CAM_HDR_SUPPORT__
    if ((cam_context_p->capture_mode == CAM_STILL_CAPTURE_HDR)&&(0 != cam_context_p->hdr_src_buffer_p))
    {
    // free at cam_free_hdr_buffer
    /*
    if (cam_context_p->capture_buffer_p)
    {
        med_free_asm_mem(cam_context_p->app_id, (void**)&cam_context_p->capture_buffer_p);
        cam_context_p->capture_buffer_size = 0;          
        }
    */
    }
    else
#endif
    {
        if (cam_context_p->capture_buffer_p)
        {
            med_free_asm_mem(cam_context_p->app_id, (void**)&cam_context_p->capture_buffer_p);
            cam_context_p->capture_buffer_size = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cam_free_working_buffer
 * DESCRIPTION
 *  This function is to release cam related memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cam_free_working_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DRV_MDP_LIMIT_CACHE_LINE_32BYTE_ALIGNMENT  // for 53/35 only
    if (cam_context_p->app_frame_buffer_p && /* MED allocate frame buffer1 memory for previewing */
        cam_context_p->frame_buffer1_p)
    {
        med_free_asm_mem(cam_context_p->app_id, (void **)&cam_context_p->frame_buffer1_p);
    }
#endif
#ifdef __CAL_CAPTURE_MODE_ZSD_SUPPORT__    // for 76/56 only
    if (CAM_STILL_CAPTURE_ZSD==cam_context_p->capture_mode)
    {
        if (!CAM_IN_STATE(CAM_PREVIEW))
        {
            if (cam_context_p->frame_buffer1_p)
            {
                med_free_asm_mem(cam_context_p->app_id, (void **)&cam_context_p->frame_buffer1_p);
            }

            if (cam_context_p->frame_buffer2_p)
            {
                med_free_asm_mem(cam_context_p->app_id, (void **)&cam_context_p->frame_buffer2_p);
            }

            if (cam_context_p->frame_buffer3_p)
            {
                med_free_asm_mem(cam_context_p->app_id, (void **)&cam_context_p->frame_buffer3_p);
            }
            cam_context_p->frame_buffer_size = 0;
        }
    }
    else
    {
        if (cam_context_p->frame_buffer2_p)
        {
            med_free_asm_mem(cam_context_p->app_id, (void **)&cam_context_p->frame_buffer2_p);
            cam_context_p->frame_buffer_size = 0;
        }

        if (cam_context_p->frame_buffer3_p)
        {
            med_free_asm_mem(cam_context_p->app_id, (void **)&cam_context_p->frame_buffer3_p);
            cam_context_p->frame_buffer_size = 0;
        }
    }
#else
    if (cam_context_p->frame_buffer2_p)
    {
        med_free_asm_mem(cam_context_p->app_id, (void **)&cam_context_p->frame_buffer2_p);
        cam_context_p->frame_buffer_size = 0;
    }

    if (cam_context_p->frame_buffer3_p)
    {
        med_free_asm_mem(cam_context_p->app_id, (void **)&cam_context_p->frame_buffer3_p);
        cam_context_p->frame_buffer_size = 0;
    }
#endif
    
#ifdef __MED_CAM_HDR_SUPPORT__
    if ((cam_context_p->capture_mode == CAM_STILL_CAPTURE_HDR)&&(0 != cam_context_p->hdr_src_buffer_p))
    {	 
    	// free at cam_free_hdr_buffer        
        /*
        if (cam_context_p->extmem_start_address)
        {            
                med_free_asm_mem(cam_context_p->app_id, (void **)&cam_context_p->extmem_start_address);
                cam_context_p->extmem_size = 0;        
        }
        */
    }
    else
#endif
    {
    if (cam_context_p->extmem_start_address)
    {
        med_free_asm_mem(cam_context_p->app_id, (void **)&cam_context_p->extmem_start_address);
        cam_context_p->extmem_size = 0;
    }
    }

// PC Huang,  Remove
#if 0
#if defined(__MED_CAM_FD_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
// PC Huang, Remove
    

    if (cam_context_p->thumbnail_buffer_address)
    {
        med_free_asm_mem(cam_context_p->app_id,(void **)&cam_context_p->thumbnail_buffer_address);
        cam_context_p->thumbnail_buffer_size = 0;
    }
      
}


#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  cam_free_stitch_buffer
 * DESCRIPTION
 *  This function is to release cam related memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cam_free_stitch_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cam_context_p->stitch_buffer_address)
    {
        med_free_asm_mem(cam_context_p->app_id, (void**)&cam_context_p->stitch_buffer_address);
        cam_context_p->stitch_buffer_size = 0;
    }
}
#endif /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  cam_free_hdr_buffer
 * DESCRIPTION
 *  This function is to release cam related memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cam_free_hdr_buffer(void)
{
#ifdef __MED_CAM_HDR_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cam_context_p->hdr_src_buffer_p)
    {
        med_free_asm_mem(cam_context_p->app_id, (void**)&cam_context_p->hdr_src_buffer_p);
        cam_context_p->hdr_src_buffer_size = 0;    
 
        cam_context_p->hdr_working_buffer_p = 0;		
        cam_context_p->hdr_working_buffer_size = 0;

        cam_context_p->capture_buffer_p= 0;
        cam_context_p->capture_buffer_size = 0;

        cam_context_p->extmem_start_address= 0;
        cam_context_p->extmem_size = 0;
    }

    if (cam_context_p->hdr_quickview_buffer_p)
    {
        med_free_asm_mem(cam_context_p->app_id,(void **)&cam_context_p->hdr_quickview_buffer_p);
        cam_context_p->hdr_quickview_buffer_size = 0;
    }    
#endif
}


/*****************************************************************************
 * FUNCTION
 *  cam_power_up_req_hdlr
 * DESCRIPTION
 *  This function is to handle power up request.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_power_up_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_power_up_req_struct *req_p;
    CAL_FEATURE_CTRL_STRUCT CalInPara;
    MM_ERROR_CODE_ENUM ret = MM_ERROR_NONE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_cam_power_up_req_struct*) ilm_ptr->local_para_ptr;

    cam_context_p->seq_num = req_p->seq_num;
    cam_context_p->app_id = req_p->app_id;

    if (CAM_IN_STATE(CAM_IDLE))
    {
        // Select main or sub sensor
        CalInPara.FeatureId = CAL_FEATURE_CAMERA_SOURCE_SELECT;
        CalInPara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
        CalInPara.FeatureSetValue = (kal_uint32)cam_context_p->cam_id;
        CalCtrl(CAL_FEATURE_CTRL, (void*)&CalInPara, NULL, 0, NULL);
        
        ret = CalOpen(cam_cal_callback);

        if (ret == MM_ERROR_NONE)
        {
            CAM_ENTER_STATE(CAM_READY);
            cam_set_result(MED_RES_OK);
        }
        else
        {
            cam_set_result(MED_RES_FAIL);
        }
    }
    else if (CAM_IN_STATE(CAM_READY))
    {
        cam_send_ready_ind(MED_RES_OK);
    }
    CAM_SET_EVENT(CAM_EVT_POWER_UP);
}


/*****************************************************************************
 * FUNCTION
 *  cam_power_down_req_hdlr
 * DESCRIPTION
 *  This function is to handle power down request.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_power_down_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_SCENARIO_CTRL_STRUCT CalScenarioPara;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;
    CAM_STATE_TRACE(cam_context_p->state);

    if (!CAM_IN_STATE(CAM_IDLE))
    {
        if (CAM_IN_STATE(CAM_PREVIEW))
        {
            // Stop preview
        #ifdef __CAL_CAPTURE_MODE_ZSD_SUPPORT__
            if (CAM_STILL_CAPTURE_ZSD==cam_context_p->capture_mode)
                CalScenarioPara.ScenarioId=CAL_SCENARIO_CAMERA_ZSD_PREVIEW;
            else
        #endif
            CalScenarioPara.ScenarioId=CAL_SCENARIO_CAMERA_PREVIEW;
            CalScenarioPara.ScenarioCtrlCode=CAL_CTRL_CODE_STOP;
            CalScenarioPara.ScenarioCtrlParaLen=0;
            CalScenarioPara.pScenarioCtrlPara=NULL;
            CalCtrl(CAL_SCENARIO_CTRL, (void *) &CalScenarioPara, NULL, 0, NULL);
        }
        else if (CAM_IN_STATE(CAM_CAPTURE))
        {
            // Stop capture
            cam_capture_still_image_stop();
        }
    
        CalClose();
    
        /* to release the memory allocated in MED_MODE_BUFFER mode */
        CAM_FREE_CAPTURE_BUFFER();
        CAM_FREE_HDR_BUFFER();
        cam_free_working_buffer();
        CAM_ENTER_STATE(CAM_IDLE);
    }
    CAM_SET_EVENT(CAM_EVT_POWER_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  cam_preview_req_hdlr
 * DESCRIPTION
 *  This function is to handle camera preview request.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_preview_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_preview_req_struct *req_p;
    CAL_SCENARIO_CTRL_STRUCT CalPreviewScenarioPara;
    CAL_CAMERA_PREVIEW_STRUCT CalPreviewPara;
    CAL_LCD_STRUCT CalLcdPara;
    CAL_ISP_PREVIEW_STRUCT CalIspPreviewPara;
    CAL_POSTPROC_STRUCT CalPostProcPara;
    CAL_MDP_PREVIEW_STRUCT CalMdpPreviewPara;
    MM_ERROR_CODE_ENUM ret;
    MM_IMAGE_ROTATE_ENUM PreviewRotate = MM_IMAGE_ROTATE_0;
    MM_IMAGE_ROTATE_ENUM IncludedAngle = MM_IMAGE_ROTATE_0; 
    kal_uint32 frame_buffer_size;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;
    cam_context_p->jaia_disable = KAL_FALSE;

    if (CAM_IN_STATE(CAM_READY))
    {
        CAM_FREE_CAPTURE_BUFFER();
        CAM_FREE_HDR_BUFFER();
        
        req_p = (media_cam_preview_req_struct*) ilm_ptr->local_para_ptr;

        cam_context_p->capture_mode = req_p->capture_mode;

        cam_context_p->extmem_start_address = 0;
        cam_context_p->extmem_size = 0;
        cam_context_p->ui_rotate = req_p->ui_rotate;
        cam_context_p->binning_mode = req_p->binning_mode;
    #ifdef __MED_CAM_HDR_SUPPORT__        
        cam_context_p->is_hdr_done = KAL_FALSE;
    #endif

        frame_buffer_size = req_p->frame_buffer_size;
    #ifdef DRV_MDP_LIMIT_CACHE_LINE_32BYTE_ALIGNMENT // for 35/53 only
        if (frame_buffer_size % 32 != 0 || ((req_p->frame_buffer1_address & 0x0000001f)!=0))
        {
            cam_context_p->app_frame_buffer_p = req_p->frame_buffer1_address;
            cam_context_p->app_frame_buffer_size = req_p->frame_buffer_size;
            frame_buffer_size = ((req_p->frame_buffer_size + 31) >> 5) << 5;
            cam_context_p->frame_buffer1_p = (kal_uint32) med_alloc_asm_mem_framebuffer(cam_context_p->app_id, frame_buffer_size);
            CAM_PREVIEW_CHECK_IS_BUFFER_AVAILABLE(cam_context_p->frame_buffer1_p);
        }
        else
        {
            cam_context_p->app_frame_buffer_p = NULL;
            cam_context_p->app_frame_buffer_size = 0;
            cam_context_p->frame_buffer1_p = req_p->frame_buffer1_address;
        }

        cam_context_p->frame_buffer2_p = (kal_uint32) med_alloc_asm_mem_framebuffer(cam_context_p->app_id, frame_buffer_size);
        CAM_PREVIEW_CHECK_IS_BUFFER_AVAILABLE(cam_context_p->frame_buffer2_p);
        cam_context_p->frame_buffer3_p = (kal_uint32) med_alloc_asm_mem_framebuffer(cam_context_p->app_id, frame_buffer_size);
        CAM_PREVIEW_CHECK_IS_BUFFER_AVAILABLE(cam_context_p->frame_buffer3_p);
    #else
        cam_context_p->app_frame_buffer_p = req_p->frame_buffer1_address;
    #ifdef __CAL_CAPTURE_MODE_ZSD_SUPPORT__  // for 76/56/55
        if (CAM_STILL_CAPTURE_ZSD==cam_context_p->capture_mode)
        {
            if (0==cam_context_p->frame_buffer2_p)
            {   // to prevent duplicate allocate memory if preview stop but without power down
                cam_context_p->frame_buffer1_p = (kal_uint32) med_alloc_asm_mem_framebuffer(cam_context_p->app_id, req_p->frame_buffer_size);
                cam_context_p->frame_buffer2_p = (kal_uint32) med_alloc_asm_mem_framebuffer(cam_context_p->app_id, req_p->frame_buffer_size);
                cam_context_p->frame_buffer3_p = (kal_uint32) med_alloc_asm_mem_framebuffer(cam_context_p->app_id, req_p->frame_buffer_size); 
            }
        }
        else
    #endif
        {
            cam_context_p->frame_buffer1_p = req_p->frame_buffer1_address;
            cam_context_p->frame_buffer2_p = (kal_uint32) med_alloc_asm_mem_framebuffer(cam_context_p->app_id, frame_buffer_size);
            CAM_PREVIEW_CHECK_IS_BUFFER_AVAILABLE(cam_context_p->frame_buffer2_p);
          #if defined(__LOW_COST_SUPPORT_COMMON__) // Low cost dosen't need tripple buffer.
            cam_context_p->frame_buffer3_p = NULL;
          #else
            cam_context_p->frame_buffer3_p = (kal_uint32) med_alloc_asm_mem_framebuffer(cam_context_p->app_id, frame_buffer_size);
            CAM_PREVIEW_CHECK_IS_BUFFER_AVAILABLE(cam_context_p->frame_buffer3_p);
          #endif
        }        
    #endif /* DRV_MDP_LIMIT_CACHE_LINE_32BYTE_ALIGNMENT */

        if (cam_context_p->lcd_id == 0) // MainLCD
        {           
            if (cam_context_p->cam_id == CAL_CAMERA_SOURCE_MAIN)
            {
                cam_context_p->sensor_rotate = CAM_MAIN_SENSOR_ROTATE;
            #if defined(SENSOR_INSIDE_CLAM)
                cam_context_p->sensor_rotate += MM_IMAGE_ROTATE_180;
            #endif

                PreviewRotate = (MM_IMAGE_ROTATE_ENUM)((cam_context_p->sensor_rotate + MAIN_LCM_CROSS_SENSOR_ANGLE) % 4);            
                if (CAM_MAIN_SENSOR_MIRROR)
                {
                    if ((MM_IMAGE_ROTATE_90==PreviewRotate)||(MM_IMAGE_ROTATE_270==PreviewRotate))
                        PreviewRotate = (MM_IMAGE_ROTATE_ENUM) ((PreviewRotate+MM_IMAGE_ROTATE_180)%4);
                    PreviewRotate += MM_IMAGE_H_MIRROR;
                }
            }
        #ifdef DUAL_CAMERA_SUPPORT
            else
            {
                cam_context_p->sensor_rotate = CAM_SUB_SENSOR_ROTATE;
                
                PreviewRotate = (MM_IMAGE_ROTATE_ENUM)((cam_context_p->sensor_rotate + MAIN_LCM_CROSS_SENSOR_ANGLE) % 4);
                if (CAM_SUB_SENSOR_MIRROR)
                {
                    if ((MM_IMAGE_ROTATE_90==PreviewRotate)||(MM_IMAGE_ROTATE_270==PreviewRotate))
                        PreviewRotate = (PreviewRotate+MM_IMAGE_ROTATE_180)%4;
                    PreviewRotate += MM_IMAGE_H_MIRROR;
                }
            }
        #endif /* DUAL_CAMERA_SUPPORT */     
        }
    #ifdef DUAL_LCD
        else // SubLCD
        {
            if (cam_context_p->cam_id == CAL_CAMERA_SOURCE_MAIN)
            {
                cam_context_p->sensor_rotate = CAM_MAIN_SENSOR_ROTATE;
                
                PreviewRotate = (MM_IMAGE_ROTATE_ENUM)((cam_context_p->sensor_rotate + SUB_LCM_CROSS_SENSOR_ANGLE) % 4);
                if (CAM_MAIN_SENSOR_MIRROR)
                {
                    if ((MM_IMAGE_ROTATE_90==PreviewRotate)||(MM_IMAGE_ROTATE_270==PreviewRotate))
                        PreviewRotate = (PreviewRotate+MM_IMAGE_ROTATE_180)%4;
                    PreviewRotate += MM_IMAGE_H_MIRROR;
                }
            }
            #ifdef DUAL_CAMERA_SUPPORT
            else
            {
                cam_context_p->sensor_rotate = CAM_SUB_SENSOR_ROTATE;

                PreviewRotate = (MM_IMAGE_ROTATE_ENUM)((cam_context_p->sensor_rotate + SUB_LCM_CROSS_SENSOR_ANGLE) % 4);
                if (CAM_SUB_SENSOR_MIRROR)
                {
                    if ((MM_IMAGE_ROTATE_90==PreviewRotate)||(MM_IMAGE_ROTATE_270==PreviewRotate))
                        PreviewRotate = (PreviewRotate+MM_IMAGE_ROTATE_180)%4;
                    PreviewRotate += MM_IMAGE_H_MIRROR;
                }
            }
            #endif /* DUAL_CAMERA_SUPPORT */
        }
    #endif /* DUAL_LCD */
        IncludedAngle = (MM_IMAGE_ROTATE_ENUM)CAM_ABS(cam_context_p->ui_rotate - cam_context_p->sensor_rotate);
        if (IncludedAngle == MM_IMAGE_ROTATE_90 || IncludedAngle == MM_IMAGE_ROTATE_270)
        {
            cam_context_p->preview_width = req_p->preview_height;
            cam_context_p->preview_height = req_p->preview_width;            
        }
        else
        {
            cam_context_p->preview_width = req_p->preview_width;
            cam_context_p->preview_height = req_p->preview_height;
        }

        cam_context_p->included_angle = IncludedAngle;
        cam_context_p->preview_rotate = PreviewRotate;
        
        CalMdpPreviewPara.LcdUpdateEnable = cam_context_p->lcd_update = req_p->lcd_update;        
        CalMdpPreviewPara.DisplayImageWidth = cam_context_p->preview_width;
        CalMdpPreviewPara.DisplayImageHeight = cam_context_p->preview_height;
        CalMdpPreviewPara.FrameBuffAddr1 = cam_context_p->frame_buffer1_p;
        CalMdpPreviewPara.FrameBuffAddr2 = cam_context_p->frame_buffer2_p;
        CalMdpPreviewPara.FrameBuffAddr3 = cam_context_p->frame_buffer3_p;
        if (NULL == cam_context_p->app_frame_buffer_p)
            CalMdpPreviewPara.CameraAppFrameBuffAddr = cam_context_p->frame_buffer1_p;
        else
            CalMdpPreviewPara.CameraAppFrameBuffAddr = cam_context_p->app_frame_buffer_p;
        CalMdpPreviewPara.FrameBuffSize = cam_context_p->frame_buffer_size = frame_buffer_size;
    #ifdef MDP_SUPPORT_HW_OVERLAP
        /* calcaulate still image rotate angle here to pass it to CAL for Overlay frame buffer rotation */
        cam_context_p->capture_rotate = (MM_IMAGE_ROTATE_180*2 + cam_context_p->sensor_rotate - cam_context_p->ui_rotate) % 4;
                                        /* 360 degree + sensor rotate - ui rotate */
        if (cam_context_p->cam_id == CAL_CAMERA_SOURCE_MAIN)
        {
            if (CAM_MAIN_SENSOR_MIRROR)
            {
                if (cam_context_p->included_angle == MM_IMAGE_ROTATE_90 || cam_context_p->included_angle == MM_IMAGE_ROTATE_270)
                {
                    cam_context_p->capture_rotate = (MM_IMAGE_ROTATE_180*3 + cam_context_p->sensor_rotate - cam_context_p->ui_rotate) % 4;
                }
                cam_context_p->capture_rotate += MM_IMAGE_H_MIRROR;
            }
        }
    #ifdef DUAL_CAMERA_SUPPORT
        else
        {
            if (CAM_SUB_SENSOR_MIRROR)
            {
                if (cam_context_p->included_angle == MM_IMAGE_ROTATE_90 || cam_context_p->included_angle == MM_IMAGE_ROTATE_270)
                {
                    cam_context_p->capture_rotate = (MM_IMAGE_ROTATE_180*3 + cam_context_p->sensor_rotate - cam_context_p->ui_rotate) % 4;
                }

                cam_context_p->capture_rotate += MM_IMAGE_H_MIRROR;
            }
        }
    #endif /* DUAL_CAMERA_SUPPORT */

        CalMdpPreviewPara.OverlayEnable = cam_context_p->overlay_frame_mode = req_p->overlay_frame_mode;
        CalMdpPreviewPara.OverlayPaletteAddr = cam_context_p->overlay_palette_addr = (kal_uint32)req_p->overlay_palette_addr;
        CalMdpPreviewPara.OverlayPaletteSize = cam_context_p->overlay_palette_size = req_p->overlay_palette_size;
        CalMdpPreviewPara.OverlayColorDepth = cam_context_p->overlay_color_depth = req_p->overlay_color_depth;
        CalMdpPreviewPara.OverlayFrameSourceKey = cam_context_p->overlay_frame_source_key = req_p->overlay_frame_source_key;
        CalMdpPreviewPara.OverlayFrameWidth = cam_context_p->overlay_frame_width = req_p->overlay_frame_width;
        CalMdpPreviewPara.OverlayFrameHeight = cam_context_p->overlay_frame_height = req_p->overlay_frame_height;
        CalMdpPreviewPara.OverlayFrameBuffAddr = cam_context_p->overlay_frame_buffer_address = req_p->overlay_frame_buffer_address;
    #endif

        CalMdpPreviewPara.ImageRotAngle = PreviewRotate;
        CalMdpPreviewPara.StillImageRotAngle = (MM_IMAGE_ROTATE_ENUM) cam_context_p->capture_rotate;
        CalMdpPreviewPara.ImageDataFormat = cam_context_p->image_data_format = (MM_IMAGE_FORMAT_ENUM)req_p->image_data_format;

        CalIspPreviewPara.ZoomStep = cam_context_p->zoom_step = req_p->zoom_step;
        CalIspPreviewPara.ContrastLevel = cam_context_p->contrast_level = (CAL_CAMERA_CONTRAST_ENUM)req_p->contrast;
        CalIspPreviewPara.SaturationLevel = cam_context_p->saturation_level = (CAL_CAMERA_SATURATION_ENUM)req_p->saturation;
        CalIspPreviewPara.SharpnessLevel = cam_context_p->sharpness_level = (CAL_CAMERA_SHARPNESS_ENUM)req_p->sharpness_level;
        CalIspPreviewPara.WbMode = cam_context_p->wb_mode = (CAL_CAMERA_WB_ENUM)req_p->WB;
        CalIspPreviewPara.EvValue = cam_context_p->ev_value = (CAL_CAMERA_EV_ENUM)req_p->exposure;
        CalIspPreviewPara.BandingFreq = cam_context_p->banding_freq = (CAL_CAMERA_BANDING_FREQ_ENUM)req_p->banding_freq;
        CalIspPreviewPara.ImageEffect = cam_context_p->image_effect = (CAL_CAMERA_IMAGE_EFFECT_ENUM)req_p->effect;
        CalIspPreviewPara.SceneMode = cam_context_p->scene_mode = (CAL_CAMERA_SCENE_MODE_ENUM)req_p->scene_mode;
        CalIspPreviewPara.AeMeteringMode = cam_context_p->ae_metering_mode = (CAL_CAMERA_AE_METERING_MODE_ENUM)req_p->ae_metering_mode;
        CalIspPreviewPara.FlashMode = cam_context_p->flash_mode = (CAL_CAMERA_FLASH_ENUM)req_p->flash_mode;
        CalIspPreviewPara.AfOperationMode = cam_context_p->af_operation_mode = (CAL_CAMERA_AF_OPERATION_MODE_ENUM)req_p->af_operation_mode;
        CalIspPreviewPara.AfRange = cam_context_p->af_range = (CAL_CAMERA_AF_RANGE_ENUM)req_p->af_range;

        CalLcdPara.WfcElementHandle = req_p->layer_element;
        CalLcdPara.WfcContextHandle = req_p->blt_ctx;
        CalLcdPara.WfcDeviceHandle = req_p->blt_dev;

        cam_context_p->extmem_size += CAL_PREVIEW_EXT_MEMORY_SIZE;

        CalPostProcPara.PostProcMode = 0;

    #if defined(__MED_CAM_FD_SUPPORT__)
        cam_context_p->fd_enable = req_p->fd_enable;

    #ifdef __CAL_CAPTURE_MODE_ASD_SUPPORT__
        if (CAM_STILL_CAPTURE_ASD==cam_context_p->capture_mode)
        {
            cam_context_p->camera_scene_detected_mode = CAM_AUTO_DSC; // set default result
            CalPostProcPara.PostProcMode = PP_MODE_ASD;
        }
        else
    #endif
        {
            if (cam_context_p->fd_enable == KAL_TRUE)
            {
                CalPostProcPara.PostProcMode = PP_MODE_FACE_DETECT;
            }
        }
    #endif /* __MED_CAM_FD_SUPPORT__ */

        if (cam_context_p->current_shot_number && 
            cam_context_p->capture_mode == CAM_STILL_CAPTURE_PANO_VIEW)
        {
            CalPostProcPara.PostProcMode = PP_MODE_PANORAMA;
        }

        if (CalPostProcPara.PostProcMode)
            cam_context_p->extmem_size += CAL_PP_PREVIEW_EXT_MEMORY_SIZE;
            
    #ifdef __MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__            
        if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_MAV)
        {
            CalPostProcPara.PostProcMode = PP_MODE_MAV;
        }
    #endif

    #ifdef __MED_CAM_3D_IMAGE_SUPPORT__
        if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_3D_IMAGE)
        {
            CalPostProcPara.PostProcMode = PP_MODE_MAV;
        }
    #endif
        
        if (cam_context_p->extmem_size)
        {
            cam_context_p->extmem_start_address = (kal_uint32) med_alloc_asm_mem_framebuffer(cam_context_p->app_id, cam_context_p->extmem_size);
            CAM_PREVIEW_CHECK_IS_BUFFER_AVAILABLE(cam_context_p->extmem_start_address);
        }

        CalPreviewPara.ExtmemStartAddress = cam_context_p->extmem_start_address;
        CalPreviewPara.ExtmemSize = cam_context_p->extmem_size;

        CalPreviewPara.pLcdPara = &CalLcdPara;
        CalPreviewPara.pMdpPara = &CalMdpPreviewPara;
        CalPreviewPara.pIspPara = &CalIspPreviewPara;
        CalPreviewPara.pPostProcPara = &CalPostProcPara;

    #ifdef __CAL_CAPTURE_MODE_ZSD_SUPPORT__
        if (CAM_STILL_CAPTURE_ZSD==cam_context_p->capture_mode)
            CalPreviewScenarioPara.ScenarioId = CAL_SCENARIO_CAMERA_ZSD_PREVIEW;
        else
    #endif
        CalPreviewScenarioPara.ScenarioId = CAL_SCENARIO_CAMERA_PREVIEW;
        CalPreviewScenarioPara.ScenarioCtrlCode = CAL_CTRL_CODE_START;
        CalPreviewScenarioPara.ScenarioCtrlParaLen = sizeof(CAL_CAMERA_PREVIEW_STRUCT);
        CalPreviewScenarioPara.pScenarioCtrlPara = &CalPreviewPara;
        
    #if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
        cam_context_p->autocap_result.MV_X = 0;
        cam_context_p->autocap_result.MV_Y = 0;
        cam_context_p->autocap_result.ImageWidth = 160;
        cam_context_p->autocap_result.ImageHeight = 120;
        cam_context_p->autocap_result.OverlapRatio = 32;
        cam_context_p->autocap_result.ReadyToShot = KAL_FALSE;
        if (cam_context_p->current_shot_number == 0)
        {
        cam_context_p->autocap_result.Direction = AUTOCAP_DIR_NO;
        }
        cam_context_p->autocap_result.HintDirection = AUTOCAP_HINT_DIR_NO;
    #endif

        ret = CalCtrl(CAL_SCENARIO_CTRL, (void *) &CalPreviewScenarioPara, NULL, 0, NULL);

    #if defined(__MED_CAM_FD_SUPPORT__)
        memset(&cam_context_p->fd_result, 0, sizeof(FD_RESULT_STRUCT));
        memset(&cam_context_p->sd_result, 0, sizeof(SD_RESULT_STRUCT));
    #endif

        if (ret == MM_ERROR_NONE)
        {
            CAM_ENTER_STATE(CAM_PREVIEW);
        }
        else
        {
            cam_free_working_buffer();
            cam_set_result(MED_RES_FAIL);
        }
    }
    else
    {
        cam_set_result(MED_RES_BUSY);
    }

    CAM_SET_EVENT(CAM_EVT_PREVIEW);
}


/*****************************************************************************
 * FUNCTION
 *  cam_stop_req_hdlr
 * DESCRIPTION
 *  This function is to handle camera stop request.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_SCENARIO_CTRL_STRUCT CalScenarioPara;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;

    if (CAM_IN_STATE(CAM_PREVIEW))
    {
        // Stop preview
    #ifdef __CAL_CAPTURE_MODE_ZSD_SUPPORT__
        if (CAM_STILL_CAPTURE_ZSD==cam_context_p->capture_mode)
            CalScenarioPara.ScenarioId=CAL_SCENARIO_CAMERA_ZSD_PREVIEW;
        else
    #endif
        CalScenarioPara.ScenarioId=CAL_SCENARIO_CAMERA_PREVIEW;
        CalScenarioPara.ScenarioCtrlCode=CAL_CTRL_CODE_STOP;
        CalScenarioPara.ScenarioCtrlParaLen=0;
        CalScenarioPara.pScenarioCtrlPara=NULL;
        CalCtrl(CAL_SCENARIO_CTRL, (void *) &CalScenarioPara, NULL, 0, NULL);

        CAM_ENTER_STATE(CAM_READY);
        cam_free_working_buffer();       
    }
    else if (CAM_IN_STATE(CAM_CAPTURE))
    {
        #if defined(__MED_CAM_MUTILSHOT_SUPPORT__)
        // burst shot is non-blocking shot
        if (CAM_STILL_CAPTURE_BURST_SHOT==cam_context_p->capture_mode)
        {
            if (cam_context_p->captured_number < cam_context_p->snapshot_number)
            {
                cam_context_p->is_waiting_burst_capture_stop = KAL_TRUE;
                return; // wait capture complete
            }
        }
        #endif
        // Stop capture
        cam_capture_still_image_stop();
        
        CAM_FREE_CAPTURE_BUFFER();
        CAM_FREE_HDR_BUFFER();
        cam_free_working_buffer();
        CAM_ENTER_STATE(CAM_READY);
    }
    #if defined(__MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined (__MED_CAM_3D_IMAGE_SUPPORT__)
    else if (CAM_IN_STATE(CAM_MAV))
    {
        cam_mav_stop_stitch();
        
        CAM_FREE_CAPTURE_BUFFER();
        cam_free_working_buffer();
        CAM_ENTER_STATE(CAM_READY);
    }
    else if (CAM_IN_STATE(CAM_READY))
    {
        if (CAM_STILL_CAPTURE_MAV==cam_context_p->capture_mode
            ||CAM_STILL_CAPTURE_3D_IMAGE==cam_context_p->capture_mode)
        {
            cam_free_working_buffer();
        }
    }
    #endif /*__MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__||__MED_CAM_3D_IMAGE_SUPPORT__*/
    
    CAM_SET_EVENT(CAM_EVT_STOP);

}

/*****************************************************************************
 * FUNCTION
 *  cam_stop_preview_req_hdlr
 * DESCRIPTION
 *  This function is to handle camera stop request.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_stop_preview_req_hdlr(ilm_struct *ilm_ptr)
{
    CAL_SCENARIO_CTRL_STRUCT CalScenarioPara;

    if (CAM_IN_STATE(CAM_PREVIEW))
    {
        // Stop preview
        /* stop prevew before capture */
        if (CAM_STILL_CAPTURE_ZSD!=cam_context_p->capture_mode)
        {
            CalScenarioPara.ScenarioId=CAL_SCENARIO_CAMERA_PREVIEW;
            CalScenarioPara.ScenarioCtrlCode=CAL_CTRL_CODE_STOP;
            CalScenarioPara.ScenarioCtrlParaLen=0;
            CalScenarioPara.pScenarioCtrlPara=NULL;
            CalCtrl(CAL_SCENARIO_CTRL, (void *) &CalScenarioPara, NULL, 0, NULL);
        }
        //is_first_capture = KAL_TRUE;
    }
    CAM_SET_EVENT(CAM_EVT_STOP);
}


/*****************************************************************************
 * FUNCTION
 *  cam_stop_fast_zoom
 * DESCRIPTION
 *  This function is to stop zoom operation if camera is zooming.
 * PARAMETERS
 *  cause       [IN]
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cam_stop_fast_zoom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_FEATURE_CTRL_STRUCT CalInPara;
    CAL_CAMERA_FAST_ZOOM_STRUCT ZoomPara;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(cam_context_p->is_fast_zoom == KAL_TRUE)
    {
        ZoomPara.ZoomStart = KAL_FALSE;
       
        CalInPara.FeatureId = CAL_FEATURE_CAMERA_FAST_ZOOM;
        CalInPara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;       
        CalInPara.FeatureInfo.FeatureStructured.pCamFastZoom = &ZoomPara;
        CalInPara.FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
        CalCtrl(CAL_FEATURE_CTRL, (void*)&CalInPara, NULL, 0, NULL);
        
        cam_context_p->is_fast_zoom = KAL_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  cam_start_fast_zoom_req_hdlr
 * DESCRIPTION
 *  This function is to handle the request of starting the camera fast zoom.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_start_fast_zoom_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_start_fast_zoom_req_struct *req_p;
    CAL_FEATURE_CTRL_STRUCT CalInPara;
    CAL_CAMERA_FAST_ZOOM_STRUCT ZoomPara;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;

    if (CAM_IN_STATE(CAM_PREVIEW))
    {
        req_p = (media_cam_start_fast_zoom_req_struct*) ilm_ptr->local_para_ptr;

        ZoomPara.ZoomStart = KAL_TRUE;
        ZoomPara.ZoomIn = req_p->zoom_in;
        ZoomPara.ZoomLimit = req_p->zoom_limit;
        ZoomPara.ZoomStep = req_p->zoom_step;
        ZoomPara.ZoomSpeed = req_p->zoom_speed;

        CalInPara.FeatureId = CAL_FEATURE_CAMERA_FAST_ZOOM;
        CalInPara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
        CalInPara.FeatureInfo.FeatureStructured.pCamFastZoom = &ZoomPara;
        CalCtrl(CAL_FEATURE_CTRL, (void*)&CalInPara, NULL, 0, NULL);
        
        cam_context_p->is_fast_zoom = KAL_TRUE;
    }
    
    CAM_SET_EVENT(CAM_EVT_FAST_ZOOM);
}


/*****************************************************************************
 * FUNCTION
 *  cam_stop_fast_zoom_req_hdlr
 * DESCRIPTION
 *  This function is to handle the request of stopping the camera fast zoom.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_stop_fast_zoom_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_FEATURE_CTRL_STRUCT CalInPara;
    CAL_CAMERA_FAST_ZOOM_STRUCT ZoomPara;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;

    if (CAM_IN_STATE(CAM_PREVIEW))
    {
        ZoomPara.ZoomStart = KAL_FALSE;
        
        CalInPara.FeatureId = CAL_FEATURE_CAMERA_FAST_ZOOM;
        CalInPara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
        CalInPara.FeatureInfo.FeatureStructured.pCamFastZoom = &ZoomPara;
        CalCtrl(CAL_FEATURE_CTRL, (void*)&CalInPara, NULL, 0, NULL);
        
        cam_context_p->is_fast_zoom = KAL_FALSE;
    }
    CAM_SET_EVENT(CAM_EVT_FAST_ZOOM);
}


/*****************************************************************************
 * FUNCTION
 *  cam_get_zoom_step_factor_req_hdlr
 * DESCRIPTION
 *  This function is to handle the request of getting the camera fast zoom factor.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_get_zoom_step_factor_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_get_fast_zoom_factor_req_struct *req_p;
    CAL_FEATURE_CTRL_STRUCT CalInPara, CalOutPara;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* isp_fast_zoom_struct zoom_data; */

    cam_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_cam_get_fast_zoom_factor_req_struct*) ilm_ptr->local_para_ptr;

    if (req_p->factor)
    {
        CalInPara.FeatureId = CAL_FEATURE_CAMERA_CURRENT_ZOOM_FACTOR;
        CalInPara.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
        CalCtrl(CAL_FEATURE_CTRL, (void*)&CalInPara, (void*)&CalOutPara, sizeof(CalOutPara), NULL);
        *req_p->factor = CalOutPara.FeatureCurrentValue;
    }
    if (req_p->step)
    {
        CalInPara.FeatureId = CAL_FEATURE_CAMERA_CURRENT_ZOOM_STEP;
        CalInPara.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
        CalCtrl(CAL_FEATURE_CTRL, (void*)&CalInPara, (void*)&CalOutPara, sizeof(CalOutPara), NULL);        
        *req_p->step = CalOutPara.FeatureCurrentValue;
    }
    CAM_SET_EVENT(CAM_EVT_GET_FAST_ZOOM_FACTOR);
}


/*****************************************************************************
 * FUNCTION
 *  cam_get_focus_zone_req_hdlr
 * DESCRIPTION
 *  This function is to get af zone from drv and return the values to MMI
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_get_focus_zone_req_hdlr(ilm_struct* ilm_ptr)
{
#ifdef __CAM_AUTO_FOCUS__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_af_get_zone_struct *req_p;
    media_cam_af_zone_para_struct *zone_para_p;
    CAL_FEATURE_CTRL_STRUCT CalInPara, CalOutPara;
    P_CAL_CAMERA_GET_AF_ZONE_STRUCT pAFInfo;
    kal_uint8 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_cam_af_get_zone_struct*) ilm_ptr->local_para_ptr;
    zone_para_p = req_p->zone_para_p;

    if (CAM_IN_STATE(CAM_PREVIEW))
    {
        CalInPara.FeatureId = CAL_FEATURE_CAMERA_GET_AF_ZONE;
        CalInPara.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;

        CalCtrl(CAL_FEATURE_CTRL, &CalInPara, &CalOutPara, sizeof(CalOutPara), NULL);
        
        pAFInfo = CalOutPara.FeatureInfo.FeatureStructured.pCamGetAfZoneOutPara;
        zone_para_p->af_active_zone = pAFInfo->AfActiveZone;
        kal_mem_cpy((void*)&(zone_para_p->af_zone), (void*)&(pAFInfo->AfZoneLcd), sizeof(pAFInfo->AfZoneLcd));

        if (cam_context_p->included_angle == MM_IMAGE_ROTATE_90 || cam_context_p->included_angle == MM_IMAGE_ROTATE_270)
        {
            for (i = 0; i < MEDIA_CAM_AF_ZONE_MAX_NO; i++)
            {
                zone_para_p->af_zone[i].af_zone_w = pAFInfo->AfZoneLcd[i].H;
                zone_para_p->af_zone[i].af_zone_h = pAFInfo->AfZoneLcd[i].W;

                zone_para_p->af_zone[i].af_zone_x = pAFInfo->AfZoneLcd[i].Y;
                zone_para_p->af_zone[i].af_zone_y = pAFInfo->AfZoneLcd[i].X;
            }
        }        
        
    }
    else
    {
        ASSERT(0);
    }   
    CAM_SET_EVENT(CAM_EVT_GET_FOCUS_ZONE);
#else
    ASSERT(0);
#endif

}


void cam_save_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined(__MED_CAM_HDR_SUPPORT__)
    if (ilm_ptr != NULL) // app request, error handling
    {
        if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_HDR)
        {
            cam_set_result(MED_RES_ERROR);
            CAM_SET_EVENT(CAM_EVT_SAVE);
            return;
        }
    }
    #endif /* __MED_CAM_HDR_SUPPORT__ */

    #if defined(__MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__MED_CAM_3D_IMAGE_SUPPORT__)
    if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_MAV
        ||cam_context_p->capture_mode == CAM_STILL_CAPTURE_3D_IMAGE)
    {
        result = cam_open_image_file((kal_wchar*)cam_context_p->file_name_p);
        if (result == MED_RES_OK)
        {
            result = cam_write_close_image_file(cam_context_p->mav_result.EncodeDstBufferAddr, cam_context_p->mav_result.EncodeDstBufferSize);
        }
            
        cam_set_result(result);
        CAM_SET_EVENT(CAM_EVT_SAVE);
        return;
    }    
    #endif /* __MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__ ||__MED_CAM_3D_IMAGE_SUPPORT__ */


    CAM_FUNC_ENTRY(CAM_SAVE_REQ_HDLR);
    
    /* state must be in CAM_CAPTURE */
    cam_context_p->is_waiting_save = KAL_FALSE;
    
    if (cam_context_p->media_mode == MED_MODE_BUFFER)
    {
        if (cam_context_p->is_main_jpeg_ready)
        {
        #ifndef __YUVCAM_ENCODE_DIRECT_WRITE_FILE__
            result = cam_open_image_file((kal_wchar*)cam_context_p->file_name_p);
            if (result == MED_RES_OK)
        #endif
            {
                result = cam_write_close_image_file(cam_context_p->jpeg_image_address, cam_context_p->jpeg_image_size);
            }
        
            cam_set_result(result);
        }
        else
        {
            cam_context_p->is_waiting_save = KAL_TRUE;
            CAM_FUNC_ENTRY(CAM_WAITING_SAVE);
        }
    }
    else
    {
        cam_set_result(MED_RES_ERROR);      
    }

    if (!cam_context_p->is_waiting_save)
    {
        CAM_SET_EVENT(CAM_EVT_SAVE);
    }
}

MM_IMAGE_ROTATE_ENUM cam_get_middle_rotate_angle(MM_IMAGE_ROTATE_ENUM target_rot_angle, MM_IMAGE_ROTATE_ENUM final_step_rot_angle)
{
    MM_IMAGE_ROTATE_ENUM middle_rot_angle;

    if (target_rot_angle < MM_IMAGE_H_MIRROR)
    {
        middle_rot_angle = (MM_IMAGE_ROTATE_ENUM) (((target_rot_angle + 4) - final_step_rot_angle)%4);
    }
    else
    {
        middle_rot_angle = (MM_IMAGE_ROTATE_ENUM) (target_rot_angle - MM_IMAGE_H_MIRROR);
        middle_rot_angle += final_step_rot_angle;
        middle_rot_angle %= 4;
        middle_rot_angle += MM_IMAGE_H_MIRROR;
    }
    return middle_rot_angle;
}   /* cam_get_middle_rotate_angle() */

/*****************************************************************************
 * FUNCTION
 *  cam_capture_req_hdlr
 * DESCRIPTION
 *  This function is to handle camera capture request.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 cam_capture_still_image_start(
    kal_uint32 buffer_address, 
    kal_uint32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_POSTPROC_STRUCT CalPostCapturePara;
    CAL_SCENARIO_CTRL_STRUCT CalCaptureScenarioPara;
    CAL_ISP_STILL_CAPTURE_STRUCT CalIspCapturePara;
    CAL_MDP_STILL_CAPTURE_STRUCT CalMdpCapturePara;
    CAL_CAMERA_STILL_CAPTURE_STRUCT CalCapturePara;
    CAL_JPEG_ENC_STRUCT CalJpegEncPara;
#if defined(CAM_STANDARD_CAPTURE)    
    CAL_FEATURE_CTRL_STRUCT CalInPara, CalOutPara;
#endif
    MM_ERROR_CODE_ENUM ret;

    kal_int32 resized_offset_x = 0;
    kal_int32 resized_offset_y = 0;
    kal_int32 resized_width = 0;
    kal_int32 resized_height = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_util_fit_box(
            160,
            120,
            cam_context_p->image_width,
            cam_context_p->image_height,
            &resized_offset_x,
            &resized_offset_y,
            &resized_width,
            &resized_height);

    cam_context_p->raw_capture_enable = KAL_FALSE;
#if defined(CAM_OFFLINE_CAPTURE)      
    cam_context_p->raw_capture_enable = KAL_TRUE;
#elif defined(CAM_STANDARD_CAPTURE)
    CalInPara.FeatureId = CAL_FEATURE_CAMERA_CURRENT_ZOOM_STEP;
    CalInPara.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
    CalCtrl(CAL_FEATURE_CTRL, (void*)&CalInPara, (void*)&CalOutPara, sizeof(CalOutPara), NULL);        
    if (CalOutPara.FeatureCurrentValue !=0)
    {
        cam_context_p->raw_capture_enable = KAL_TRUE;
    }
#endif

    CalPostCapturePara.PostProcMode = 0;
    if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_PANO_VIEW)
    {
        CalPostCapturePara.PostProcMode = PP_MODE_PANORAMA;
    }
    else if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_HDR)
    {
        CalPostCapturePara.PostProcMode = PP_MODE_HDR;
    }
    else if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_MAV)
    {
        CalPostCapturePara.PostProcMode = PP_MODE_MAVCAP;
    }
    else if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_3D_IMAGE)
    {
        CalPostCapturePara.PostProcMode = PP_MODE_MAVCAP_3D;
    }
    
    if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_RAW_DATA)
        CalMdpCapturePara.MainImageDataFormat = cam_context_p->image_data_format;
    else
        CalMdpCapturePara.MainImageDataFormat = MM_IMAGE_FORMAT_JPEG;

    CalMdpCapturePara.MainImageJpegYuvSampleFormat = MM_IMAGE_FORMAT_YUV422;
    CalMdpCapturePara.MainImageWidth = cam_context_p->image_width;
    CalMdpCapturePara.MainImageHeight = cam_context_p->image_height;
    CalMdpCapturePara.MainImageBuffAddr = buffer_address;
    CalMdpCapturePara.MainImageBuffSize = buffer_size;

#if defined(__CAMERA_CAPTURE_USING_APP_MEMORY__)
    CalMdpCapturePara.MainImageYBuffAddr = cam_context_p->capture_y_buffer_address;
    CalMdpCapturePara.MainImageYBuffSize = cam_context_p->capture_y_buffer_size;
    CalMdpCapturePara.MainImageUBuffAddr = cam_context_p->capture_u_buffer_address;
    CalMdpCapturePara.MainImageUBuffSize = cam_context_p->capture_u_buffer_size;
    CalMdpCapturePara.MainImageVBuffAddr = cam_context_p->capture_v_buffer_address;
    CalMdpCapturePara.MainImageVBuffSize = cam_context_p->capture_v_buffer_size;

    // If null, MED will self allocate memory for capture, else only allocate memory for qvi rotate 
    if ((cam_context_p->capture_y_buffer_address == NULL) || 
        (cam_context_p->capture_u_buffer_address == NULL) || 
        (cam_context_p->capture_v_buffer_address == NULL))
    {
        CalMdpCapturePara.MainImageYUVEnagle = KAL_FALSE;
    }
    else
    {
        CalMdpCapturePara.MainImageYUVEnagle = KAL_TRUE;
    }
#endif

    CalMdpCapturePara.MainImageWorkingBuffAddr = cam_context_p->capture_buffer_p;
    CalMdpCapturePara.MainImageWorkingBuffSize = cam_context_p->capture_buffer_size;
    CalMdpCapturePara.MainImageRotAngle = (MM_IMAGE_ROTATE_ENUM)cam_context_p->capture_rotate;
#ifdef MDP_SUPPORT_HW_OVERLAP
    CalMdpCapturePara.OverlayEnable = cam_context_p->overlay_frame_mode;
    CalMdpCapturePara.OverlayPaletteAddr = cam_context_p->overlay_palette_addr;
    CalMdpCapturePara.OverlayPaletteSize = cam_context_p->overlay_palette_size;
    CalMdpCapturePara.OverlayColorDepth = cam_context_p->overlay_color_depth;
    CalMdpCapturePara.OverlayFrameSourceKey = cam_context_p->overlay_frame_source_key;
    CalMdpCapturePara.OverlayFrameWidth = cam_context_p->overlay_frame_width;
    CalMdpCapturePara.OverlayFrameHeight = cam_context_p->overlay_frame_height;
    CalMdpCapturePara.OverlayFrameBuffAddr = cam_context_p->overlay_frame_buffer_address;
#endif

    CalMdpCapturePara.QuickViewImageEnable = cam_context_p->quickview_output;
    if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_PANO_VIEW) // current autorama support RGB565 only
    CalMdpCapturePara.QuickViewImageFormat = MM_IMAGE_FORMAT_RGB565;
    else
        CalMdpCapturePara.QuickViewImageFormat = cam_context_p->image_data_format;
    CalMdpCapturePara.QuickViewImageWidth = cam_context_p->quickview_output_width ;
    CalMdpCapturePara.QuickViewImageHeight = cam_context_p->quickview_output_height;
    CalMdpCapturePara.QuickViewImageBuffAddr = cam_context_p->quickview_output_buffer_address;
    CalMdpCapturePara.QuickViewImageBuffSize = cam_context_p->quickview_output_buffer_size;

    CalMdpCapturePara.QuickViewImageLCDRotAngle = (MM_IMAGE_ROTATE_ENUM) cam_context_p->quickview_lcd_rotate;    
    if (MM_IMAGE_ROTATE_0_WITH_LCD_CONFIG == cam_context_p->quickview_lcd_rotate) cam_context_p->quickview_lcd_rotate = MM_IMAGE_ROTATE_0;
    CalMdpCapturePara.QuickViewImageRotAngle = cam_get_middle_rotate_angle((MM_IMAGE_ROTATE_ENUM) cam_context_p->preview_rotate, 
                                                                           (MM_IMAGE_ROTATE_ENUM) cam_context_p->quickview_lcd_rotate);
    
#if defined(EXIF_SUPPORT)
    if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_PANO_VIEW)
        CalMdpCapturePara.ThumbnailImageEnable = KAL_FALSE;
    else if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_RAW_DATA)
        CalMdpCapturePara.ThumbnailImageEnable = KAL_FALSE;
    else
        CalMdpCapturePara.ThumbnailImageEnable = KAL_TRUE;
#else
    CalMdpCapturePara.ThumbnailImageEnable = KAL_FALSE;
#endif
    if (cam_context_p->jaia_disable == KAL_TRUE)
    {
        CalMdpCapturePara.ThumbnailImageEnable = KAL_FALSE;
    }

    CalMdpCapturePara.ThumbnailImageFormat = MM_IMAGE_FORMAT_RGB565;
    CalMdpCapturePara.ThumbnailImageWidth = resized_width;
    CalMdpCapturePara.ThumbnailImageHeight = resized_height;
    CalMdpCapturePara.ThumbnailImageRotAngle = (MM_IMAGE_ROTATE_ENUM)cam_context_p->capture_rotate;
    CalMdpCapturePara.ThumbnailImageBuffAddr = cam_context_p->thumbnail_buffer_address;
    CalMdpCapturePara.ThumbnailImageBuffSize = cam_context_p->thumbnail_buffer_size;
    CalMdpCapturePara.LcdUpdateEnable = KAL_FALSE;
    CalMdpCapturePara.ImageJaiaDisable = cam_context_p->jaia_disable;

    CalIspCapturePara.BinningMode = cam_context_p->binning_mode;
    CalIspCapturePara.MultishotInfo = (MULTISHOT_INFO_ENUM)cam_context_p->multishot_info;
    CalIspCapturePara.ExpoBracketLevel = cam_context_p->expo_bracket_level;
    CalIspCapturePara.RawCaptureEnable = cam_context_p->raw_capture_enable;
    CalIspCapturePara.StillCaptureMode = (CAL_CAMERA_STILL_CAPTURE_ENUM)cam_context_p->capture_mode;    

    CalJpegEncPara.JpegEncQuality = (JPEG_ENCODE_QUALITTY_ENUM)cam_context_p->image_quality;
    //CalJpegEncPara.JpegSamplingFormat = JPEG_YUV_FORMAT_YUV420;
    CalJpegEncPara.JpegSamplingFormat = MM_IMAGE_FORMAT_YUV422;
#ifdef __YUVCAM_ENCODE_DIRECT_WRITE_FILE__
    CalJpegEncPara.pDstFileHandle = &cam_context_p->fsal_file;
#else
    CalJpegEncPara.pDstFileHandle = NULL;
#endif

    CalCapturePara.ExtmemStartAddress = cam_context_p->extmem_start_address;
    CalCapturePara.ExtmemSize = cam_context_p->extmem_size;

    CalCapturePara.pMdpPara = &CalMdpCapturePara;
    CalCapturePara.pIspPara = &CalIspCapturePara;
    CalCapturePara.pJpegEncPara = &CalJpegEncPara;
    CalCapturePara.pPostProcPara = &CalPostCapturePara;

    CalCaptureScenarioPara.ScenarioId = CAL_SCENARIO_CAMERA_STILL_CAPTURE;
#ifdef __CAL_CAPTURE_MODE_ZSD_SUPPORT__
    if (CAM_STILL_CAPTURE_ZSD==cam_context_p->capture_mode)
        CalCaptureScenarioPara.ScenarioId = CAL_SCENARIO_CAMERA_ZSD_CAPTURE;    
#endif
#ifdef __MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__
    if (CAM_STILL_CAPTURE_MAV==cam_context_p->capture_mode)
        CalCaptureScenarioPara.ScenarioId = CAL_SCENARIO_CAMERA_MAV_CAPTURE;    
#endif
#ifdef __MED_CAM_3D_IMAGE_SUPPORT__
    if (CAM_STILL_CAPTURE_3D_IMAGE==cam_context_p->capture_mode)
        CalCaptureScenarioPara.ScenarioId = CAL_SCENARIO_CAMERA_MAV_CAPTURE;    
#endif
    CalCaptureScenarioPara.ScenarioCtrlCode = CAL_CTRL_CODE_START;
    CalCaptureScenarioPara.ScenarioCtrlParaLen = sizeof(CAL_CAMERA_STILL_CAPTURE_STRUCT);
    CalCaptureScenarioPara.pScenarioCtrlPara = &CalCapturePara;

    cam_context_p->is_quickview_ready = KAL_FALSE;
    cam_context_p->is_thumbnail_ready = KAL_FALSE;
    cam_context_p->is_main_jpeg_ready = KAL_FALSE;

    MED_CAM_START_LOGGING("CPJ");
    MED_CAM_GET_START_TIME(CAM_CAPTURE_JPEG_DURATION);

    CAM_ENTER_STATE(CAM_CAPTURE);        
    ret = CalCtrl(CAL_SCENARIO_CTRL, (void *) &CalCaptureScenarioPara, NULL, 0, 0);

    return (kal_int32)ret;
}


/*****************************************************************************
 * FUNCTION
 *  cam_capture_still_image_stop
 * DESCRIPTION
 *  This function is to stop camera capture.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_capture_still_image_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_SCENARIO_CTRL_STRUCT CalCaptureScenarioPara;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CAL_CAPTURE_MODE_ZSD_SUPPORT__
    if (CAM_STILL_CAPTURE_ZSD==cam_context_p->capture_mode)
        CalCaptureScenarioPara.ScenarioId = CAL_SCENARIO_CAMERA_ZSD_CAPTURE;
    else
#endif
#ifdef __MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__
	if (CAM_STILL_CAPTURE_MAV==cam_context_p->capture_mode)
		CalCaptureScenarioPara.ScenarioId = CAL_SCENARIO_CAMERA_MAV_CAPTURE;
	else
#endif
#ifdef __MED_CAM_3D_IMAGE_SUPPORT__
	if (CAM_STILL_CAPTURE_3D_IMAGE==cam_context_p->capture_mode)
		CalCaptureScenarioPara.ScenarioId = CAL_SCENARIO_CAMERA_MAV_CAPTURE;
	else
#endif

    CalCaptureScenarioPara.ScenarioId=CAL_SCENARIO_CAMERA_STILL_CAPTURE;
    CalCaptureScenarioPara.ScenarioCtrlCode=CAL_CTRL_CODE_STOP;
    CalCaptureScenarioPara.ScenarioCtrlParaLen=0;
    CalCaptureScenarioPara.pScenarioCtrlPara=NULL;
    CalCtrl(CAL_SCENARIO_CTRL, (void *) &CalCaptureScenarioPara, NULL, 0, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  cam_capture_req_hdlr
 * DESCRIPTION
 *  This function is to handle camera capture request.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_capture_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_capture_req_struct *req_p;

#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
    CAL_FEATURE_CTRL_STRUCT CalFeaturePara;
#endif
    kal_uint32 buffer_address = 0;
    kal_uint32 buffer_size = 0;
    kal_int32 ret;
    kal_bool  is_first_capture = KAL_FALSE;

    // temp solution for JAVA capture rotation before full still capture rotaiton is support
    CAL_FEATURE_CTRL_STRUCT CalInPara;
    MM_IMAGE_ROTATE_ENUM IncludedAngle = MM_IMAGE_ROTATE_0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_cam_capture_req_struct*) ilm_ptr->local_para_ptr;

    #if defined(__MED_CAM_XENON_FLASH_SUPPORT__)
    if (cam_context_p->xenon_flash_status != CAM_XENON_FLASH_OFF)
        med_stop_timer(CAM_XENON_FLASH_CHECK_TIMER);
    #endif /* defined(__MED_CAM_XENON_FLASH_SUPPORT__) */

    /* it is for MoDis, we return from here */
    #if !defined(__MTK_TARGET__)
    {
        cam_set_result(MED_RES_BUSY);
        CAM_SET_EVENT(CAM_EVT_CAPTURE);
        return;
    }
    #endif

    if (CAM_IN_STATE(CAM_READY) || CAM_IN_STATE(CAM_PREVIEW))
    {
        CAM_FREE_CAPTURE_BUFFER();
        CAM_FREE_HDR_BUFFER();

        /* stop prevew before capture */ 
        if(CAM_IN_STATE(CAM_PREVIEW))
        {
            if (CAM_STILL_CAPTURE_ZSD!=cam_context_p->capture_mode)
            {
                CAM_ENTER_STATE(CAM_READY);
            }
            is_first_capture = KAL_TRUE;
        }
    #if defined(DRV_MDP_LIMIT_CACHE_LINE_32BYTE_ALIGNMENT) && defined(__MTK_TARGET__)  // for 35/53 only
        if (cam_context_p->app_frame_buffer_p)
        {
            memcpy(
                (kal_uint8*) cam_context_p->app_frame_buffer_p,
                (kal_uint8*) cam_context_p->frame_buffer2_p,
                cam_context_p->app_frame_buffer_size);
        }
    #endif /* defined(DRV_MDP_LIMIT_CACHE_LINE_32BYTE_ALIGNMENT) && defined(__MTK_TARGET__) */
    
        /* release preview related memory */
        cam_free_working_buffer();

        ASSERT(req_p->source_device == CAM_SRC_ISP || req_p->source_device == CAM_SRC_MEM);
        if ((req_p->source_device != CAM_SRC_ISP && req_p->source_device != CAM_SRC_MEM))
        {
            cam_set_result(MED_RES_ERROR);
            CAM_ENTER_STATE(CAM_READY);
            CAM_SET_EVENT(CAM_EVT_CAPTURE);
            return;
        }

        cam_context_p->ui_rotate = req_p->ui_rotate;
        cam_context_p->quickview_lcd_rotate = req_p->quickview_lcd_rotate;
        cam_context_p->media_mode = req_p->media_mode;
        cam_context_p->source_device = req_p->source_device;
        cam_context_p->snapshot_number = req_p->snapshot_number;
        cam_context_p->capture_mode = req_p->capture_mode;    

        cam_context_p->continue_capture = req_p->continue_capture;
        cam_context_p->captured_number = 0;
        cam_context_p->expo_bracket_level = 0;

        if (cam_context_p->lcd_id == 0) // MainLCD
        {
            if (cam_context_p->cam_id == CAL_CAMERA_SOURCE_MAIN)
            {
                IncludedAngle = (MM_IMAGE_ROTATE_ENUM)CAM_ABS(cam_context_p->ui_rotate - CAM_MAIN_SENSOR_ROTATE);
            }
            else
            {
                IncludedAngle = (MM_IMAGE_ROTATE_ENUM)CAM_ABS(cam_context_p->ui_rotate - CAM_SUB_SENSOR_ROTATE);
            }
        }
        else // SubLCD
        {
            if (cam_context_p->cam_id == CAL_CAMERA_SOURCE_MAIN)
            {
                IncludedAngle = (MM_IMAGE_ROTATE_ENUM)CAM_ABS(cam_context_p->ui_rotate - CAM_MAIN_SENSOR_ROTATE);
            }
            else
            {
                IncludedAngle = (MM_IMAGE_ROTATE_ENUM)CAM_ABS(cam_context_p->ui_rotate - CAM_SUB_SENSOR_ROTATE);
            }
        }

        cam_context_p->capture_rotate = (MM_IMAGE_ROTATE_180*2 + cam_context_p->sensor_rotate - cam_context_p->ui_rotate) % 4;
                                        /* 360 degree + sensor rotate - ui rotate */
        if (cam_context_p->cam_id == CAL_CAMERA_SOURCE_MAIN)
        {
            if (CAM_MAIN_SENSOR_MIRROR)
            {
                if (IncludedAngle == MM_IMAGE_ROTATE_90 || IncludedAngle == MM_IMAGE_ROTATE_270)
                {
                    cam_context_p->capture_rotate = (MM_IMAGE_ROTATE_180*3 + cam_context_p->sensor_rotate - cam_context_p->ui_rotate) % 4;
                }
                cam_context_p->capture_rotate += MM_IMAGE_H_MIRROR;
            }
        }
    #ifdef DUAL_CAMERA_SUPPORT
        else
        {
            if (CAM_SUB_SENSOR_MIRROR)
            {
                if (IncludedAngle == MM_IMAGE_ROTATE_90 || IncludedAngle == MM_IMAGE_ROTATE_270)
                {
                    cam_context_p->capture_rotate = (MM_IMAGE_ROTATE_180*3 + cam_context_p->sensor_rotate - cam_context_p->ui_rotate) % 4;
                }

                cam_context_p->capture_rotate += MM_IMAGE_H_MIRROR;
            }
        }
    #endif /* DUAL_CAMERA_SUPPORT */
        cam_context_p->image_data_format = (MM_IMAGE_FORMAT_ENUM) req_p->image_data_format;
        cam_context_p->image_width = req_p->image_width;
        cam_context_p->image_height = req_p->image_height;
    #ifdef MDP_SUPPORT_HW_OVERLAP        
        cam_context_p->overlay_frame_mode = req_p->overlay_frame_mode;
        cam_context_p->overlay_palette_addr = (kal_uint32)req_p->overlay_palette_addr;
        cam_context_p->overlay_palette_size = req_p->overlay_palette_size;
        cam_context_p->overlay_color_depth = req_p->overlay_color_depth;
        cam_context_p->overlay_frame_source_key = req_p->overlay_frame_source_key;
        cam_context_p->overlay_frame_width = req_p->overlay_frame_width;
        cam_context_p->overlay_frame_height = req_p->overlay_frame_height;
        cam_context_p->overlay_frame_buffer_address = req_p->overlay_frame_buffer_address;
    #endif     

        cam_context_p->quickview_output = req_p->quickview_output;
        cam_context_p->quickview_output_width = req_p->quickview_output_width;
        cam_context_p->quickview_output_height = req_p->quickview_output_height;
        cam_context_p->quickview_output_buffer_address = req_p->quickview_output_buffer_address;
        cam_context_p->quickview_output_buffer_size = req_p->quickview_output_buffer_size;

        cam_context_p->snapshot_number = req_p->snapshot_number;
        cam_context_p->expo_bracket_level = 0;
        cam_context_p->capture_mode = req_p->capture_mode;    
        cam_context_p->image_quality = req_p->image_quality;
        cam_context_p->jpeg_file_info_p = (jpegs_struct *)req_p->jpegs_p;
        cam_context_p->capture_buffer_pp = req_p->capture_buffer_p;
        cam_context_p->capture_buffer_size_p = req_p->file_size_p;
        cam_context_p->is_waiting_save = KAL_FALSE;
    #if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)        
        cam_context_p->stitch_direction = req_p->direction;
    #endif
        cam_context_p->file_name_p = req_p->filename_p;

        // temp solution for JAVA capture rotation before full still capture rotaiton is support
        // Since the still image resolution in JAVA would be CAM_IMAGE_SIZE_OTHER that result in
        // the still image will not be rotate, we need to force the still image size as CAM_IMAGE_SIZE_WALLPAPER
        // to make sure the still image will be rotate if necessary.
        if (cam_context_p->capture_rotate & 0x01)
        {
            if (cam_context_p->image_resolution == CAM_IMAGE_SIZE_OTHER)
            {
                if (((cam_context_p->image_width<=LCD_WIDTH) && (cam_context_p->image_height<=LCD_HEIGHT)) ||
                    ((cam_context_p->image_width<=LCD_HEIGHT) && (cam_context_p->image_height<=LCD_WIDTH)))
                {
                    cam_context_p->image_resolution = CAM_IMAGE_SIZE_WALLPAPER;

                    CalInPara.FeatureId = CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE;
                    CalInPara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
                    CalInPara.FeatureSetValue = cam_context_p->image_resolution;
                    ret = CalCtrl(CAL_FEATURE_CTRL, (void*)&CalInPara, NULL, 0, NULL);

                }
            }
        }

    // For voiding memory fragmentation, allocate HDR source image buffer firstly.
    #ifdef __MED_CAM_HDR_SUPPORT__
        if (req_p->capture_mode == CAM_STILL_CAPTURE_HDR)
        {
			// allocate CAM_HDR_TOTAL_BUF_SIZE total memory, for both normal image & hdr image
			cam_context_p->hdr_src_buffer_p = (kal_uint32) med_alloc_asm_mem_framebuffer(
														cam_context_p->app_id ,
														CAM_HDR_TOTAL_BUF_SIZE);
			cam_context_p->hdr_src_buffer_size = CAM_HDR_SRC_EXT_MEM_SIZE;
            
            CAM_CAPTURE_CHECK_IS_BUFFER_AVAILABLE(cam_context_p->hdr_src_buffer_p);
        }
    #endif

        if (cam_context_p->image_resolution == CAM_IMAGE_SIZE_WALLPAPER)
        {
            cam_context_p->capture_buffer_size = MAX_CAM_CAPTURE_LCD_ISP_BUF_SIZE;
        }
        else if (cam_context_p->image_resolution <= CAM_IMAGE_SIZE_VGA)
        {
            cam_context_p->capture_buffer_size = MAX_CAM_CAPTURE_VGA_ISP_BUF_SIZE;
        }
        else if (cam_context_p->image_resolution == CAM_IMAGE_SIZE_OTHER)
        {
            if (((cam_context_p->image_width<=LCD_WIDTH) && (cam_context_p->image_height<=LCD_HEIGHT)) ||
                ((cam_context_p->image_width<=LCD_HEIGHT) && (cam_context_p->image_height<=LCD_WIDTH)))
                cam_context_p->capture_buffer_size = MAX_CAM_CAPTURE_LCD_ISP_BUF_SIZE;
            else if (((cam_context_p->image_width<=640) && (cam_context_p->image_height<=480)) ||
                     ((cam_context_p->image_width<=480) && (cam_context_p->image_height<=640)))
                cam_context_p->capture_buffer_size = MAX_CAM_CAPTURE_VGA_ISP_BUF_SIZE;
            else
                cam_context_p->capture_buffer_size = MAX_CAM_CAPTURE_ISP_BUF_SIZE;
        }
        else
        {
            cam_context_p->capture_buffer_size = MAX_CAM_CAPTURE_ISP_BUF_SIZE;
        }

        if (cam_context_p->jaia_disable == KAL_TRUE)
        {
            cam_context_p->capture_buffer_size = (cam_context_p->image_width*cam_context_p->image_height*3);

            if (cam_context_p->capture_buffer_size > CAL_STILL_CAPTURE_LCD_IMAGE_BUFF_MIN_SIZE)
            {
                ASSERT(0);
            }
        }

    #ifdef __MED_CAM_HDR_SUPPORT__
        if (req_p->capture_mode == CAM_STILL_CAPTURE_HDR)
        {
            //cam_context_p->capture_buffer_p = (kal_uint32) med_alloc_asm_mem_framebuffer(cam_context_p->app_id ,MAX_CAM_HDR_WORKING_EXT_MEM_SIZE);
            //CAM_CAPTURE_CHECK_IS_BUFFER_AVAILABLE(cam_context_p->capture_buffer_p);
            /*
	            cam_context_p->capture_buffer_size = CAM_HDR_DST_BUF_SIZE;
			cam_context_p->capture_buffer_p = (kal_uint32) med_alloc_asm_mem_framebuffer(
																			cam_context_p->app_id ,
																			cam_context_p->capture_buffer_size);
			CAM_CAPTURE_CHECK_IS_BUFFER_AVAILABLE(cam_context_p->capture_buffer_size);
			*/
			cam_context_p->capture_buffer_size = MAX_CAM_CAPTURE_ISP_BUF_SIZE;
			cam_context_p->capture_buffer_p = cam_context_p->hdr_src_buffer_p;
        }
        else
    #endif
    #ifdef __MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__
        if (req_p->capture_mode == CAM_STILL_CAPTURE_MAV)
        {
            //don't allocate capture_buffer
        }
        else
    #endif
    #ifdef __MED_CAM_3D_IMAGE_SUPPORT__
        if (req_p->capture_mode == CAM_STILL_CAPTURE_3D_IMAGE)
        {
            //don't allocate capture_buffer
        }
        else
    #endif
    #ifdef __MED_CAM_PANORAMA_VIEW_SUPPORT__
        if (req_p->capture_mode == CAM_STILL_CAPTURE_PANO_VIEW)
        {
            // no need to allocate capture buffer
        }
        else
    #endif
        if (req_p->capture_mode == CAM_STILL_CAPTURE_RAW_DATA)
        {
            // no need to allocate capture buffer because capture buffer from app
        }
        else
        {
          #if defined(__CAMERA_CAPTURE_USING_APP_MEMORY__)


            cam_context_p->capture_y_buffer_address = req_p->capture_y_buffer_address;
            cam_context_p->capture_y_buffer_size = req_p->capture_y_buffer_size;
            cam_context_p->capture_u_buffer_address = req_p->capture_u_buffer_address;
            cam_context_p->capture_u_buffer_size = req_p->capture_u_buffer_size;
            cam_context_p->capture_v_buffer_address = req_p->capture_v_buffer_address;
            cam_context_p->capture_v_buffer_size = req_p->capture_v_buffer_size;
            cam_context_p->capture_buffer_p = NULL;

            // If null, MED will self allocate memory for capture, else only allocate memory for qvi rotate 
            if ((cam_context_p->capture_y_buffer_address != NULL) &&
                (cam_context_p->capture_u_buffer_address != NULL) && 
                (cam_context_p->capture_v_buffer_address != NULL))
            {
                cam_context_p->capture_buffer_size = CAL_QVI_ROT_WORKING_BUFF_SIZE;
            }
          #endif

            cam_context_p->capture_buffer_p = (kal_uint32) med_alloc_asm_mem_framebuffer(cam_context_p->app_id ,cam_context_p->capture_buffer_size);
            CAM_CAPTURE_CHECK_IS_BUFFER_AVAILABLE(cam_context_p->capture_buffer_p);
        }

        if (req_p->media_mode == MED_MODE_BUFFER)
        {
            if (req_p->capture_mode != CAM_STILL_CAPTURE_NORMAL && 
                req_p->capture_mode != CAM_STILL_CAPTURE_CONT_SHOT &&
                req_p->capture_mode != CAM_STILL_CAPTURE_ADD_FRAME &&
                req_p->capture_mode != CAM_STILL_CAPTURE_SMILE_SHOT &&
                req_p->capture_mode != CAM_STILL_CAPTURE_HDR &&
                req_p->capture_mode != CAM_STILL_CAPTURE_ASD &&
                req_p->capture_mode != CAM_STILL_CAPTURE_ZSD &&
                req_p->capture_mode != CAM_STILL_CAPTURE_MAV &&
                req_p->capture_mode != CAM_STILL_CAPTURE_3D_IMAGE)
            {
                ASSERT(0);
            }

        #ifdef __YUVCAM_ENCODE_DIRECT_WRITE_FILE__
            ret = cam_open_image_file(cam_context_p->file_name_p);
            if (ret != MED_RES_OK)
            {
                cam_free_working_buffer();
                cam_set_result(ret);
                CAM_SET_EVENT(CAM_EVT_CAPTURE);
                return;
            }
        #endif

            if (cam_context_p->continue_capture == KAL_FALSE)
                cam_context_p->multishot_info = MULTISHOT_FALSE;
            else if (cam_context_p->continue_capture == KAL_TRUE && is_first_capture)
                cam_context_p->multishot_info = MULTISHOT_FIRST;
            else if (cam_context_p->continue_capture == KAL_TRUE)
                cam_context_p->multishot_info = MULTISHOT_NOT_FIRST;

        #ifdef __MED_CAM_HDR_SUPPORT__
            if (req_p->capture_mode == CAM_STILL_CAPTURE_HDR)
            {
                cam_context_p->is_hdr_done = KAL_FALSE;

                buffer_address = cam_context_p->capture_buffer_p;
                buffer_size = cam_context_p->capture_buffer_size;
            }
            else
        #endif /* __MED_CAM_HDR_SUPPORT__ */
            {
                buffer_address = cam_context_p->capture_buffer_p;
                buffer_size = cam_context_p->capture_buffer_size;
            }
        }
    #ifdef __MED_CAM_MUTILSHOT_SUPPORT__
        else if (req_p->media_mode == MED_MODE_ARRAY)
        {
            cam_context_p->app_capture_buffer_p = (kal_uint32)req_p->app_capture_buffer_p;
            cam_context_p->app_capture_buffer_size = req_p->app_capture_buffer_size;

            if (req_p->capture_mode != CAM_STILL_CAPTURE_RAW_DATA)
            {
                cam_context_p->multishot_info = MULTISHOT_FIRST;
            }
            
            #ifdef __MED_CAM_BESTSHOT_SUPPORT__
            if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_BEST_SHOT)
            {
                cam_context_p->bss_buffer1_p = cam_context_p->app_capture_buffer_p;
                cam_context_p->bss_buffer1_size = cam_context_p->app_capture_buffer_size >> 1;

                cam_context_p->bss_buffer2_p = cam_context_p->bss_buffer1_p + cam_context_p->bss_buffer1_size;
                cam_context_p->bss_buffer2_size = cam_context_p->bss_buffer1_size;

                buffer_address = cam_context_p->bss_buffer1_p;
                buffer_size = cam_context_p->bss_buffer1_size;
            }
            else
            #endif /* __MED_CAM_BESTSHOT_SUPPORT__ */   
            {
                buffer_address = cam_context_p->app_capture_buffer_p;
                buffer_size =  cam_context_p->app_capture_buffer_size;
            }
            if (req_p->capture_mode != CAM_STILL_CAPTURE_RAW_DATA)
            {
                cam_context_p->is_waiting_burst_capture_stop = KAL_FALSE;
            }
        }
    #else
        else if (req_p->media_mode == MED_MODE_ARRAY)
        {
            if (req_p->capture_mode == CAM_STILL_CAPTURE_RAW_DATA)
            {
                buffer_address = cam_context_p->app_capture_buffer_p = (kal_uint32)req_p->app_capture_buffer_p;
                buffer_size = cam_context_p->app_capture_buffer_size = req_p->app_capture_buffer_size;
            }
        }
    #endif /* __MED_CAM_MUTILSHOT_SUPPORT__ */
        cam_context_p->jpeg_buffer_address = buffer_address;
        cam_context_p->jpeg_buffer_size = buffer_size;
            
        if (cam_context_p->image_resolution == CAM_IMAGE_SIZE_WALLPAPER)
            cam_context_p->extmem_size = MAX_CAM_CAPTURE_LCD_ISP_WORK_BUF_SIZE;
        else if (cam_context_p->image_resolution <= CAM_IMAGE_SIZE_VGA)
            cam_context_p->extmem_size = MAX_CAM_CAPTURE_VGA_ISP_WORK_BUF_SIZE;
        else if (cam_context_p->image_resolution == CAM_IMAGE_SIZE_OTHER)
        {
            if (((cam_context_p->image_width<=LCD_WIDTH) && (cam_context_p->image_height<=LCD_HEIGHT)) ||
                ((cam_context_p->image_width<=LCD_HEIGHT) && (cam_context_p->image_height<=LCD_WIDTH)))
                cam_context_p->extmem_size = MAX_CAM_CAPTURE_LCD_ISP_WORK_BUF_SIZE;
            else if (((cam_context_p->image_width<=640) && (cam_context_p->image_height<=480)) ||
                     ((cam_context_p->image_width<=480) && (cam_context_p->image_height<=640)))
                cam_context_p->extmem_size = MAX_CAM_CAPTURE_VGA_ISP_WORK_BUF_SIZE;
            else
                cam_context_p->extmem_size = MAX_CAM_CAPTURE_ISP_WORK_BUF_SIZE;
        }
        else    
            cam_context_p->extmem_size = MAX_CAM_CAPTURE_ISP_WORK_BUF_SIZE;
            
        if (req_p->capture_mode == CAM_STILL_CAPTURE_RAW_DATA)
        {
            cam_context_p->extmem_size = 0;
        }   
    #ifdef __MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__
        if (req_p->capture_mode == CAM_STILL_CAPTURE_MAV)
            cam_context_p->extmem_size = MAX_CAM_MAV_WORKING_EXT_MEM_SIZE;
    #endif
    #ifdef __MED_CAM_3D_IMAGE_SUPPORT__
        if (req_p->capture_mode == CAM_STILL_CAPTURE_3D_IMAGE)
            cam_context_p->extmem_size = MAX_CAM_MAV_WORKING_EXT_MEM_SIZE;
    #endif
    #ifdef __MED_CAM_PANORAMA_VIEW_SUPPORT__
        if (req_p->capture_mode == CAM_STILL_CAPTURE_PANO_VIEW)
        {
            cam_context_p->extmem_size = 0;
        }
    #endif
    #ifdef __MED_CAM_HDR_SUPPORT__
        if (req_p->capture_mode == CAM_STILL_CAPTURE_HDR)
        { 
    	    ASSERT(CAM_HDR_TOTAL_BUF_SIZE >= MAX_CAM_CAPTURE_ISP_BUF_SIZE+cam_context_p->extmem_size);
			if (cam_context_p->extmem_size)
			{
				cam_context_p->extmem_start_address = cam_context_p->hdr_src_buffer_p + MAX_CAM_CAPTURE_ISP_BUF_SIZE;
    	    }            
        }
        else
    #endif
        {
            if (cam_context_p->extmem_size)
            {
                cam_context_p->extmem_start_address = (kal_uint32) med_alloc_asm_mem_framebuffer(cam_context_p->app_id, cam_context_p->extmem_size);
                CAM_CAPTURE_CHECK_IS_BUFFER_AVAILABLE(cam_context_p->extmem_start_address);
            }
        }

    #if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
        if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_PANO_VIEW)
        {
            // set direction of panorama
            ASSERT(cam_context_p->stitch_direction < CAM_NO_OF_PANO_DIR);
            
            CalFeaturePara.FeatureId = CAL_FEATURE_CAMERA_PANO_DIRECTION;
            CalFeaturePara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
            CalFeaturePara.FeatureSetValue = (kal_uint32)cam_context_p->stitch_direction;
            CalCtrl(CAL_FEATURE_CTRL, (void*)&CalFeaturePara, NULL, 0, NULL);

            cam_context_p->multishot_info = MULTISHOT_FALSE;
        }
        else
    #endif /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */              
    #if defined(__MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__)
        if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_MAV)
        {
            //don't allocate thumbnail buffer
        }
        else
    #endif /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */
    #if defined(__MED_CAM_3D_IMAGE_SUPPORT__)
        if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_3D_IMAGE)
        {
            //don't allocate thumbnail buffer
        }
        else
    #endif /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */
        if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_RAW_DATA)
        {
            //don't allocate thumbnail buffer
        }
        else             
        {
            cam_context_p->thumbnail_buffer_size = MAX_CAM_CAPTURE_THUMBNAIL_BUF_SIZE;
            cam_context_p->thumbnail_buffer_address = (kal_uint32) med_alloc_asm_mem_framebuffer(cam_context_p->app_id, cam_context_p->thumbnail_buffer_size);
            CAM_CAPTURE_CHECK_IS_BUFFER_AVAILABLE(cam_context_p->thumbnail_buffer_address);            
        }
        
        #if defined(__MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__)
        if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_MAV)
        {
            cam_context_p->mav_seq_num = req_p->mav_seq_num;
        }
        #endif /* __MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__ */
        #if defined(__MED_CAM_3D_IMAGE_SUPPORT__)
        if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_3D_IMAGE)
        {
            cam_context_p->mav_seq_num = req_p->mav_seq_num;
        }
        #endif /* __MED_CAM_3D_IMAGE_SUPPORT__ */
        
        ret = cam_capture_still_image_start(buffer_address, buffer_size);

        if (ret != MM_ERROR_NONE)
        {
            CAM_ENTER_STATE(CAM_READY);
            cam_free_working_buffer();
            cam_set_result(MED_RES_ERROR);
            CAM_SET_EVENT(CAM_EVT_CAPTURE);
        }
    #if defined(__MED_CAM_BUSTSHOT_SUPPORT__) || defined(__MED_CAM_HDR_SUPPORT__) || defined(__MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__) || defined(__MED_CAM_3D_IMAGE_SUPPORT__)
        else if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_BURST_SHOT ||
                 cam_context_p->capture_mode == CAM_STILL_CAPTURE_HDR ||
                 cam_context_p->capture_mode == CAM_STILL_CAPTURE_MAV ||
                 cam_context_p->capture_mode == CAM_STILL_CAPTURE_3D_IMAGE)
        {
            // non-blocking capture mode
            cam_set_result(MED_RES_OK);
            CAM_SET_EVENT(CAM_EVT_CAPTURE);
        }
    #endif /* __MED_CAM_BUSTSHOT_SUPPORT__*/        
    }
}


/*****************************************************************************
 * FUNCTION
 *  cam_get_encoded_image_req_hdlr
 * DESCRIPTION
 *  This function is to handle camera capture request.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_encode_capture_image_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_encode_image_req_struct *req_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_cam_encode_image_req_struct*)ilm_ptr->local_para_ptr;

    if (cam_context_p->media_mode != MED_MODE_BUFFER)
    {
        cam_set_result(MED_RES_ERROR);
        CAM_SET_EVENT(CAM_EVT_ENCODE_JPEG);
        return;
    }
    
    if (CAM_IN_STATE(CAM_READY) && cam_context_p->is_main_jpeg_ready)
    {
        if (cam_context_p->is_main_jpeg_ready)
        {
            *req_p->buf_pp = (kal_uint8*)cam_context_p->jpeg_image_address;
            *req_p->buf_size_p = cam_context_p->jpeg_image_size;
            cam_set_result(MED_RES_OK);
        }
        else
        {
            *req_p->buf_pp = NULL;
            *req_p->buf_size_p = 0;
            cam_set_result(MED_RES_ERROR);
        }
        
        CAM_SET_EVENT(CAM_EVT_ENCODE_JPEG);
    }
    else if (CAM_IN_STATE(CAM_CAPTURE))
    {
        //Wait the main image callback
        cam_context_p->capture_buffer_pp = (void**)req_p->buf_pp;
        cam_context_p->capture_buffer_size_p = req_p->buf_size_p;
    }
    else
    {
        ASSERT(0);
    }
}


kal_uint8 cam_bestshot_compare_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    CAL_FEATURE_CTRL_STRUCT CalInPara, CalOutPara;
    CAL_CAMERA_GET_BSS_RESULT_IN_STRUCT BestShotIn;
    CAL_CAMERA_GET_BSS_RESULT_OUT_STRUCT BestShotOut;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CalInPara.FeatureId = CAL_FEATURE_CAMERA_GET_BSS_RESULT;
    CalInPara.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
    CalInPara.FeatureType = CAL_FEATURE_TYPE_STRUCTURED;
    CalInPara.FeatureInfo.FeatureStructured.pCamGetBssInPara = &BestShotIn;

    BestShotIn.SnapShotIndex = cam_context_p->captured_number - 1;
    BestShotIn.JpegSize = cam_context_p->jpeg_image_size;

    CalOutPara.FeatureInfo.FeatureStructured.pCamGetBssOutPara = &BestShotOut;
    CalCtrl(CAL_FEATURE_CTRL, &CalInPara, &CalOutPara, sizeof(CalOutPara), NULL);

    return CalOutPara.FeatureInfo.FeatureStructured.pCamGetBssOutPara->BestShotIndex;
}


void cam_get_fd_result_req_hdlr(ilm_struct* ilm_ptr)
{
#if defined(__MED_CAM_FD_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_get_fd_result_struct *req_p;
    media_cam_fd_result_struct *fd_result_p;
    kal_int8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;
    if (CAM_IN_STATE(CAM_PREVIEW) && cam_context_p->fd_enable == KAL_TRUE)
    {
        req_p = (media_cam_get_fd_result_struct*) ilm_ptr->local_para_ptr;
        fd_result_p = req_p->fd_result_p;
        
        if (cam_context_p->sd_enable)
        {
        #if defined(__SMILE_SHUTTER_SUPPORT__)
            fd_result_p->face_no = cam_context_p->sd_result.face_no;
            fd_result_p->smile_detected_no = cam_context_p->sd_result.smile_detected_no;
            fd_result_p->sd_end_flag = cam_context_p->sd_result.sd_end_flag;
            if (fd_result_p->smile_detected_no >0 || (fd_result_p->sd_end_flag == KAL_TRUE))
            {
                kal_trace(TRACE_GROUP_1,CAM_FD_GET_RESULT_1,fd_result_p->smile_detected_no ,fd_result_p->sd_end_flag);
            }

            for (i=0; i<fd_result_p->face_no; i++)
            {
                ASSERT (i<MAX_CAM_FD_NO);

                fd_result_p->rect_x0[i]  = cam_context_p->sd_result.rect_x0[i];
                fd_result_p->rect_x1[i]  = cam_context_p->sd_result.rect_x1[i];
                fd_result_p->rect_y0[i]  = cam_context_p->sd_result.rect_y0[i];
                fd_result_p->rect_y1[i]  = cam_context_p->sd_result.rect_y1[i];
            }

            for (i=0; i<fd_result_p->smile_detected_no; i++)
            {
                fd_result_p->sd_rect_x0[i] = cam_context_p->sd_result.sd_rect_x0[i];
                fd_result_p->sd_rect_y0[i] = cam_context_p->sd_result.sd_rect_y0[i];
                fd_result_p->sd_rect_x1[i] = cam_context_p->sd_result.sd_rect_x1[i];
                fd_result_p->sd_rect_y1[i] = cam_context_p->sd_result.sd_rect_y1[i];
            }    
        #endif /* defined(__SMILE_SHUTTER_SUPPORT__) */   
        }
        else
        {
            fd_result_p->face_no = cam_context_p->fd_result.face_no;

            for (i=0; i<fd_result_p->face_no; i++)
            {
                ASSERT (i<MAX_CAM_FD_NO);

                fd_result_p->rect_x0[i]  = cam_context_p->fd_result.rect_x0[i];
                fd_result_p->rect_x1[i]  = cam_context_p->fd_result.rect_x1[i];
                fd_result_p->rect_y0[i]  = cam_context_p->fd_result.rect_y0[i];
                fd_result_p->rect_y1[i]  = cam_context_p->fd_result.rect_y1[i];
            }

        #ifdef __CAL_CAPTURE_MODE_ASD_SUPPORT__
            if (CAM_STILL_CAPTURE_ASD==cam_context_p->capture_mode)
            {
                fd_result_p->camera_scene_detected_mode=cam_context_p->camera_scene_detected_mode;
            }
        #endif
        }
    }
    else
    {
        ASSERT(0);
    }
#endif /* __MED_CAM_FD_SUPPORT__ */

    CAM_SET_EVENT(CAM_EVT_BLOCK);
}


void cam_set_fd_id_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


void cam_unset_fd_id_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
 * FUNCTION
 *  cam_pause_preview_postproc_req_hdlr
 * DESCRIPTION
 *  This function is to pause post process
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_pause_preview_postproc_req_hdlr(ilm_struct *ilm_ptr)
{
#if defined(__MED_CAM_FD_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_FEATURE_CTRL_STRUCT CalInPara;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CalInPara.FeatureId = CAL_FEATURE_CAMERA_PREVIEW_POSTPROC_PAUSE;
    CalInPara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
    CalCtrl(CAL_FEATURE_CTRL, &CalInPara, NULL, 0, NULL);

    cam_set_result(MED_RES_OK);
#endif
    CAM_SET_EVENT(CAM_EVT_SET_PARAM);
}


/*****************************************************************************
 * FUNCTION
 *  cam_resume_preview_postproc_req_hdlr
 * DESCRIPTION
 *  This function is to resume post process
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_resume_preview_postproc_req_hdlr(ilm_struct *ilm_ptr)
{
#if defined(__MED_CAM_FD_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_FEATURE_CTRL_STRUCT CalInPara;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CalInPara.FeatureId = CAL_FEATURE_CAMERA_PREVIEW_POSTPROC_RESUME;
    CalInPara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
    CalCtrl(CAL_FEATURE_CTRL, &CalInPara, NULL, 0, NULL);

    cam_set_result(MED_RES_OK);
#endif
    CAM_SET_EVENT(CAM_EVT_SET_PARAM);
}


/*****************************************************************************
 * FUNCTION
 *  cam_set_cap_resolution_req_hdlr
 * DESCRIPTION
 *  This function is to handle camera set cap resolution request.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_set_cap_resolution_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_cap_resolution_struct *req_p;
    CAL_FEATURE_CTRL_STRUCT CalInPara;
    MM_ERROR_CODE_ENUM ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_cam_cap_resolution_struct*) ilm_ptr->local_para_ptr;

    cam_context_p->image_resolution = req_p->image_resolution;
    cam_context_p->image_width  = req_p->image_width;
    cam_context_p->image_height = req_p->image_height;

    CalInPara.FeatureId = CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE;
    CalInPara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
    CalInPara.FeatureSetValue = cam_context_p->image_resolution;
    ret = CalCtrl(CAL_FEATURE_CTRL, (void*)&CalInPara, NULL, 0, NULL); 

    cam_set_result((kal_int32)ret);      

    CAM_SET_EVENT(CAM_EVT_SET_PARAM);
}


/*****************************************************************************
 * FUNCTION
 *  cam_set_param_req_hdlr
 * DESCRIPTION
 *  This function is to handle camera set parameter request.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_set_param_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_set_param_req_struct *req_p;
    CAL_FEATURE_CTRL_STRUCT CalInPara;
    MM_ERROR_CODE_ENUM ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_cam_set_param_req_struct*) ilm_ptr->local_para_ptr;

    if (CAM_IN_STATE(CAM_PREVIEW) || CAM_IN_STATE(CAM_CAPTURE) || CAM_IN_STATE(CAM_READY))
    {
        CalInPara.FeatureId = req_p->param_id;
        CalInPara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
        CalInPara.FeatureSetValue = req_p->value;
        ret = CalCtrl(CAL_FEATURE_CTRL, (void*)&CalInPara, NULL, 0, NULL); 

        #if defined(__MED_CAM_FD_SUPPORT__)    
        if (req_p->param_id == CAL_FEATURE_CAMERA_SMILE_DETECT_START)
        {
            cam_context_p->sd_enable = (kal_bool)req_p->value;
        }
        #endif /* __MED_CAM_FD_SUPPORT__ */

        #if defined(__CAL_DISABLE_JAIA_SUPPORT__)
        if (req_p->param_id == CAL_FEATURE_CAMERA_JAIA_DISABLE)
        {
            cam_context_p->jaia_disable = (kal_bool) req_p->value;
        }
        #endif

        cam_set_result((kal_int32)ret);      
    }
    else
    {
        cam_set_result(MED_RES_FAIL);
    }

    CAM_SET_EVENT(CAM_EVT_SET_PARAM);

}


/*****************************************************************************
 * FUNCTION
 *  cam_set_flash_req_hdlr
 * DESCRIPTION
 *  This function is to handle camera set flash request.
 * PARAMETERS
 *  ilm_ptr     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_set_flash_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    media_cam_set_flash_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;

//    req_p = (media_cam_set_flash_req_struct*) ilm_ptr->local_para_ptr;

}


/*****************************************************************************
 * FUNCTION
 *  cam_stitch_result_ind_hdlr
 * DESCRIPTION
 *  This function is to handle finish stitch panorama process indication from media-v
 * PARAMETERS
 *  ilm_ptr     [in]  ilm struct
 * RETURNS
 *  void
 *****************************************************************************/
void cam_stitch_result_ind_hdlr(ilm_struct *ilm_ptr)
{
#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#else /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */
    /* not reach here */
    ASSERT(0);
#endif /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  cam_start_stitch_req_hdlr
 * DESCRIPTION
 *  This function is to handle Start stitch Panorama Process request from MMI,
 *  it will send mesg to MED_V and wait indication from MED_V, then set event.
 * PARAMETERS
 *  ilm_ptr     [in]  ilm struct
 * RETURNS
 *  void
 *****************************************************************************/
void cam_start_stitch_req_hdlr(ilm_struct *ilm_ptr)
{
#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_start_stitch_req_struct *req_p;
    kal_uint32 buffer_address = NULL;
    kal_uint32 buffer_size = 0;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_cam_start_stitch_req_struct*)ilm_ptr->local_para_ptr;
    
    cam_context_p->stitch_seq_no = req_p->seq_no;

    cam_context_p->jpeg_buffer_address = req_p->target_buffer_address;
    cam_context_p->jpeg_buffer_size = req_p->target_buffer_size;
    cam_context_p->quickview_output = req_p->quickview_output;
    cam_context_p->quickview_output_buffer_address = req_p->quickview_output_buffer_address;
    cam_context_p->quickview_output_buffer_size = req_p->quickview_output_buffer_size;
    cam_context_p->quickview_output_width = req_p->quickview_output_width;
    cam_context_p->quickview_output_height = req_p->quickview_output_height;
    cam_context_p->quickview_output_resize_by_buffer_size_enable = req_p->quickview_output_resize_by_buffer_size_enable;
    
    if (CAM_IN_STATE(CAM_READY) && !cam_context_p->is_bg_stitching)
    {
        req_p = (media_cam_start_stitch_req_struct*) ilm_ptr->local_para_ptr;

        CAM_FREE_STITCH_BUFFER();
        CAM_FREE_CAPTURE_BUFFER();

        if (cam_context_p->stitch_app_buffer_address)
        {
            buffer_address = cam_context_p->stitch_app_buffer_address;
            buffer_size = cam_context_p->stitch_app_buffer_size;            
        }
        else
        {
            cam_context_p->stitch_buffer_size = (CAL_PP_PANO_SCENARIO_EXT_MEMORY_SIZE+31)&0xFFFFFFE0;
            cam_context_p->stitch_buffer_address = (kal_uint32)med_alloc_asm_mem_framebuffer(
                                                                    cam_context_p->app_id, 
                                                                    cam_context_p->stitch_buffer_size);

            buffer_address = cam_context_p->stitch_buffer_address;
            buffer_size = cam_context_p->stitch_buffer_size;          
        }
        cam_context_p->is_stitch_done = KAL_FALSE;
        cam_panorama_start_stitch(buffer_address, buffer_size);

        cam_context_p->current_shot_number = 0;
        /* enter STITCH state */
        CAM_PANO_ENTER_STATE(CAM_PANO_STITCH_FINAL);
    }
    else
    {
        cam_context_p->is_waiting_stitch = KAL_TRUE;
    }
    /* set event */
    CAM_SET_EVENT(CAM_EVT_BLOCK);

#else /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */
    /* not reach here */
    ASSERT(0);
#endif /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  cam_stop_stitch_req_hdlr
 * DESCRIPTION
 *  This function is to handle Stop stitch Panorama Process request from MMI,
 *  it will send mesg to MED_V and wait indication from MED_V, then set event.
 * PARAMETERS
 *  ilm_ptr     [in]  ilm struct
 * RETURNS
 *  void
 *****************************************************************************/
void cam_stop_stitch_req_hdlr(ilm_struct *ilm_ptr)
{
#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CAM_PANO_IN_STATE(CAM_PANO_STITCH_BG) || CAM_PANO_IN_STATE(CAM_PANO_STITCH_BG_PAUSE))
    {
        cam_panorama_stop_bg_stitch();
        CAM_PANO_ENTER_STATE(CAM_PANO_IDLE);
    }
    else if(CAM_PANO_IN_STATE(CAM_PANO_STITCH_FINAL) || CAM_IN_STATE(CAM_PANO_STITCH_PAUSE))
    {
        cam_panorama_stop_stitch();
        cam_context_p->stitch_seq_no++;
        
        CAM_PANO_ENTER_STATE(CAM_PANO_IDLE);
    }

    cam_context_p->is_waiting_stitch = KAL_FALSE;
    cam_context_p->is_stitch_done = KAL_FALSE;
    cam_context_p->current_shot_number = 0;
    cam_context_p->stitch_app_buffer_address = NULL;
    cam_context_p->stitch_app_buffer_size = 0;
    CAM_FREE_STITCH_BUFFER();
    
    CAM_SET_EVENT(CAM_EVT_BLOCK);

#else /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */
    /* not reach here */
    ASSERT(0);
#endif /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */
}



/*****************************************************************************
 * FUNCTION
 *  cam_reset_panorama_3a_req_hdlr
 * DESCRIPTION
 *  This function is to handle Stop stitch Panorama Process request from MMI,
 * PARAMETERS
 *  ilm_ptr     [in]  ilm struct
 * RETURNS
 *  void
 *****************************************************************************/
void cam_reset_panorama_3a_req_hdlr(ilm_struct *ilm_ptr)
{
#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (CAM_PANO_IN_STATE(CAM_PANO_STITCH_BG) || CAM_PANO_IN_STATE(CAM_PANO_STITCH_BG_PAUSE))
    {
        cam_panorama_stop_bg_stitch();
        CAM_PANO_ENTER_STATE(CAM_PANO_IDLE);
    }
    else if (CAM_PANO_IN_STATE(CAM_PANO_STITCH_FINAL) || CAM_PANO_IN_STATE(CAM_PANO_STITCH_PAUSE))
    {
        cam_panorama_stop_stitch();
        cam_context_p->stitch_seq_no++;

        CAM_PANO_ENTER_STATE(CAM_PANO_IDLE);
    }
    
    cam_context_p->is_waiting_stitch = KAL_FALSE;
    cam_context_p->is_stitch_done = KAL_FALSE;
    cam_context_p->current_shot_number = 0;
    cam_context_p->stitch_app_buffer_address = NULL;
    cam_context_p->stitch_app_buffer_size = 0;

    CAM_FREE_STITCH_BUFFER();
    
    CAM_SET_EVENT(CAM_EVT_BLOCK);

#else /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */
    /* not reach here */
    ASSERT(0);
#endif /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  cam_pause_stitch_req_hdlr
 * DESCRIPTION
 *  This function is to pause stitch process.
 * PARAMETERS
 *  ilm_ptr     [in]  ilm struct
 * RETURNS
 *  void
 *****************************************************************************/
void cam_pause_stitch_req_hdlr(ilm_struct *ilm_ptr)
{
#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_SCENARIO_CTRL_STRUCT CalStitchScenarioPara;
    CAL_CAMERA_POSTPROC_STRUCT CalPostProcPara;
    CAL_POSTPROC_STRUCT PostProcPara;
    CAL_FEATURE_CTRL_STRUCT CalInPara;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __CAM_TRACE_ON__
    kal_trace(TRACE_GROUP_2, CAM_STITCH_PAUSE, cam_context_p->state);
    #endif
    
    if (CAM_PANO_IN_STATE(CAM_PANO_STITCH_FINAL))
    {
        PostProcPara.PostProcMode = PP_MODE_PANORAMA;
        CalPostProcPara.pPostProcPara = &PostProcPara;
        
        CalStitchScenarioPara.ScenarioId = CAL_SCENARIO_POST_PROCESSING;
        CalStitchScenarioPara.ScenarioCtrlCode = CAL_CTRL_CODE_PAUSE;
        CalStitchScenarioPara.ScenarioCtrlParaLen = sizeof(CAL_CAMERA_POSTPROC_STRUCT);
        CalStitchScenarioPara.pScenarioCtrlPara = &CalPostProcPara;
            
        CalCtrl(CAL_SCENARIO_CTRL, (void *)&CalStitchScenarioPara, NULL, 0, NULL);
        
        CAM_PANO_ENTER_STATE(CAM_PANO_STITCH_PAUSE);
        cam_set_result(MED_RES_OK);
    }
    else if (CAM_PANO_IN_STATE(CAM_PANO_STITCH_BG))
    {
        CalInPara.FeatureId = CAL_FEATURE_CAMERA_BG_PANO_ADD_IMAGE_PAUSE;
        CalInPara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
        CalCtrl(CAL_FEATURE_CTRL, &CalInPara, NULL, 0, NULL);
        CAM_PANO_ENTER_STATE(CAM_PANO_STITCH_BG_PAUSE);
        cam_set_result(MED_RES_OK);
    }
    else
    {
        cam_set_result(MED_RES_FAIL);
    }
    
    CAM_FREE_STITCH_BUFFER();
    CAM_SET_EVENT(CAM_EVT_BLOCK);
#else /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */
    /* should not reach here! */
    ASSERT(0);
#endif /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  cam_resume_stitch_req_hdlr
 * DESCRIPTION
 *  This function is to pause stitch process.
 * PARAMETERS
 *  ilm_ptr     [in]  ilm struct
 * RETURNS
 *  void
 *****************************************************************************/
void cam_resume_stitch_req_hdlr(ilm_struct *ilm_ptr)
{
#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_SCENARIO_CTRL_STRUCT CalStitchScenarioPara;
    CAL_CAMERA_POSTPROC_STRUCT CalPostProcPara;
    CAL_POSTPROC_STRUCT PostProcPara;
    kal_uint32 buffer_address = NULL;
    kal_uint32 buffer_size = 0;
    CAL_FEATURE_CTRL_STRUCT CalInPara;
    CAL_FEATURE_CAMERA_PANO_ADD_IMAGE_STRUCT PanoAddImg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __CAM_TRACE_ON__
    kal_trace(TRACE_GROUP_2, CAM_STITCH_RESUME, cam_context_p->state);
    #endif

    if (CAM_PANO_IN_STATE(CAM_PANO_STITCH_PAUSE) && !cam_context_p->is_bg_stitching)
    {
        if (cam_context_p->is_stitch_done == KAL_TRUE)
        {
            cam_send_stitch_result_ind(cam_context_p->stitch_seq_no, 
                                       cam_context_p->stitch_result,
                                       cam_context_p->stitch_jpeg_file_address, 
                                       cam_context_p->stitch_jpeg_file_size,
                                       cam_context_p->stitch_jpeg_file_width,
                                       cam_context_p->stitch_jpeg_file_height);
            cam_context_p->is_stitch_done = KAL_FALSE;
            CAM_PANO_ENTER_STATE(CAM_PANO_IDLE);
        }
        else
        {
            if (cam_context_p->stitch_app_buffer_address)
            {
                buffer_address = cam_context_p->stitch_app_buffer_address;
                buffer_size = cam_context_p->stitch_app_buffer_size;            
            }
            else
            {
                cam_context_p->stitch_buffer_size = (CAL_PP_PANO_SCENARIO_EXT_MEMORY_SIZE+31)&0xFFFFFFE0;
                cam_context_p->stitch_buffer_address = (kal_uint32)med_alloc_asm_mem_framebuffer(
                                                                        cam_context_p->app_id, 
                                                                        cam_context_p->stitch_buffer_size);
                buffer_address = cam_context_p->stitch_buffer_address;
                buffer_size = cam_context_p->stitch_buffer_size;          
            }
        
            PostProcPara.PostProcMode = PP_MODE_PANORAMA;
            CalPostProcPara.pPostProcPara = &PostProcPara;
            CalPostProcPara.ExtmemStartAddress = buffer_address;
            CalPostProcPara.ExtmemSize  = buffer_size;
    
            CalStitchScenarioPara.ScenarioId = CAL_SCENARIO_POST_PROCESSING;
            CalStitchScenarioPara.ScenarioCtrlCode = CAL_CTRL_CODE_RESUME;
            CalStitchScenarioPara.ScenarioCtrlParaLen = sizeof(CAL_CAMERA_POSTPROC_STRUCT);
            CalStitchScenarioPara.pScenarioCtrlPara = &CalPostProcPara;
                
            CalCtrl(CAL_SCENARIO_CTRL, (void *)&CalStitchScenarioPara, NULL, 0, NULL);
            CAM_PANO_ENTER_STATE(CAM_PANO_STITCH_FINAL);
        }
        cam_set_result(MED_RES_OK);
    }
    else if (CAM_PANO_IN_STATE(CAM_PANO_STITCH_BG_PAUSE))
    {
        // Add image for bg stitch
        if (cam_context_p->stitch_app_buffer_address)
        {
            PanoAddImg.ExtmemStartAddr = cam_context_p->stitch_app_buffer_address;
            PanoAddImg.ExtmemSize = cam_context_p->stitch_app_buffer_size;            
        }
        else
        {
            if (cam_context_p->stitch_buffer_address == NULL)
            {
                cam_context_p->stitch_buffer_size = MED_CAM_BG_STITCH_EXT_MEM_SIZE;
                cam_context_p->stitch_buffer_address = (kal_uint32)med_alloc_asm_mem_framebuffer(
                                                                        cam_context_p->app_id, 
                                                                        cam_context_p->stitch_buffer_size);
            }

            PanoAddImg.ExtmemStartAddr = cam_context_p->stitch_buffer_address;
            PanoAddImg.ExtmemSize = cam_context_p->stitch_buffer_size;
        }

        PanoAddImg.CurrentShotNumber = cam_context_p->current_shot_number;
        PanoAddImg.SrcImgFormat = cam_context_p->stitch_image_format;
        PanoAddImg.StitchDirection = cam_context_p->stitch_direction;
        PanoAddImg.ImageWidth = cam_context_p->image_width;
        PanoAddImg.ImageHeight = cam_context_p->image_height;
        PanoAddImg.ImageBufferAddr = cam_context_p->stitch_image_address;
        PanoAddImg.ImageBufferSize = cam_context_p->stitch_image_size;
        
        CalInPara.FeatureId = CAL_FEATURE_CAMERA_BG_PANO_ADD_IMAGE_RESUME;
        CalInPara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
        CalInPara.FeatureType = CAL_FEATURE_TYPE_STRUCTURED;
        CalInPara.FeatureInfo.FeatureStructured.pPanoAddImgPara = &PanoAddImg;

        CalCtrl(CAL_FEATURE_CTRL, &CalInPara, NULL, 0, NULL);
        CAM_PANO_ENTER_STATE(CAM_PANO_STITCH_BG);
        cam_set_result(MED_RES_OK);
    }
    else
    {
        cam_set_result(MED_RES_FAIL);
    }

    CAM_SET_EVENT(CAM_EVT_BLOCK);
#else /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */
    /* should not reach here! */
    ASSERT(0);
#endif /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */
    
}


/*****************************************************************************
 * FUNCTION
 *  cam_set_stitch_mem_hdlr
 * DESCRIPTION
 *  This function is to handle set stitch memory.
 * PARAMETERS
 *  ilm_ptr     [in]  ilm struct
 * RETURNS
 *  void
 *****************************************************************************/
void cam_set_stitch_mem_hdlr(ilm_struct *ilm_ptr)
{
#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_set_stitch_mem_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CAM_IN_STATE(CAM_READY) || CAM_IN_STATE(CAM_PREVIEW))
    {
        req_p = (media_cam_set_stitch_mem_req_struct*) ilm_ptr->local_para_ptr;

        if (req_p->buffer_size >= ((CAL_PP_PANO_SCENARIO_EXT_MEMORY_SIZE+31)&0xFFFFFFE0))
        {
            cam_context_p->stitch_app_buffer_address = req_p->buffer_address;
            cam_context_p->stitch_app_buffer_size = req_p->buffer_size;
        }
        else
        {
            ASSERT(0);
        }
    }
    else
    {
        ASSERT(0);
    }
    CAM_SET_EVENT(CAM_EVT_BLOCK);
#else /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */
    /* should not reach here! */
    ASSERT(0);
#endif /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  cam_encode_panorama_hdlr
 * DESCRIPTION
 *  This function is to encode panorama.
 * PARAMETERS
 *  ilm_ptr     [in]  ilm struct
 * RETURNS
 *  void
 *****************************************************************************/
void cam_encode_panorama_hdlr(ilm_struct *ilm_ptr)
{
#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_panorama_encode_req_struct *req_p;
    CAL_FEATURE_CTRL_STRUCT CalInPara;
    CAL_FEATURE_CAMERA_PANO_ENCODE_STRUCT PanoEncodePara;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(CAM_PANO_IN_STATE(CAM_PANO_STITCH_FINAL))
    {
        req_p = (media_cam_panorama_encode_req_struct*) ilm_ptr->local_para_ptr;
        
        PanoEncodePara.QuickviewRoiX = req_p->quickview_roi_x;
        PanoEncodePara.QuickviewRoiY = req_p->quickview_roi_y;
        PanoEncodePara.QuickviewRoiWidth = req_p->quickview_roi_width;
        PanoEncodePara.QuickviewRoiHeight = req_p->quickview_roi_height;
        PanoEncodePara.IsJaiaQviBufAligned = req_p->is_jaia_qvi_buf_aligned;
        
        CalInPara.FeatureId = CAL_FEATURE_CAMERA_ENCODE_PANORAMA;
        CalInPara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
        CalInPara.FeatureType = CAL_FEATURE_TYPE_STRUCTURED;
        CalInPara.FeatureInfo.FeatureStructured.pPanoEncodePara = &PanoEncodePara;
        
        CalCtrl(CAL_FEATURE_CTRL, &CalInPara, NULL, 0, NULL);

    }
    else
    {
        ASSERT(0);
    }

    CAM_SET_EVENT(CAM_EVT_BLOCK); 
#else /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */
    /* should not reach here! */
    ASSERT(0);
#endif /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  cam_encode_panorama_hdlr
 * DESCRIPTION
 *  This function is to encode panorama.
 * PARAMETERS
 *  ilm_ptr     [in]  ilm struct
 * RETURNS
 *  void
 *****************************************************************************/
void cam_get_autocap_result_req_hdlr(ilm_struct* ilm_ptr)
{
#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_get_autocap_result_struct *req_p;
    media_cam_autocap_result_struct *autocap_result_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;
    if (CAM_IN_STATE(CAM_PREVIEW) && CAM_PANO_IN_STATE(CAM_PANO_STITCH_BG))
    {
        req_p = (media_cam_get_autocap_result_struct*) ilm_ptr->local_para_ptr;
        autocap_result_p = req_p->autocap_result_p; 
        
        autocap_result_p->ready_to_shot = cam_context_p->autocap_result.ReadyToShot;
        autocap_result_p->overlap_ratio = cam_context_p->autocap_result.OverlapRatio;
        autocap_result_p->stitch_dir = cam_context_p->autocap_result.Direction;
        autocap_result_p->move_hint_dir = cam_context_p->autocap_result.HintDirection;
        if (cam_context_p->included_angle == MM_IMAGE_ROTATE_90 || cam_context_p->included_angle == MM_IMAGE_ROTATE_270)
        {
            autocap_result_p->mv_x = cam_context_p->autocap_result.MV_Y*cam_context_p->preview_height/cam_context_p->autocap_result.ImageHeight;
            autocap_result_p->mv_y = cam_context_p->autocap_result.MV_X*cam_context_p->preview_width/cam_context_p->autocap_result.ImageWidth;
        }
        else
        {
            autocap_result_p->mv_x = cam_context_p->autocap_result.MV_X*cam_context_p->preview_width/cam_context_p->autocap_result.ImageWidth;
            autocap_result_p->mv_y = cam_context_p->autocap_result.MV_Y*cam_context_p->preview_height/cam_context_p->autocap_result.ImageHeight;
        }
    }
    else
    {
        ASSERT(0);
    }
#endif /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */

    CAM_SET_EVENT(CAM_EVT_BLOCK);
}


/*****************************************************************************
 * FUNCTION
 *  cam_hdr_stop_req_hdlr
 * DESCRIPTION
 *  This function is to handle stop hdr request.
 * PARAMETERS
 *  ilm_ptr     [in]  ilm struct
 * RETURNS
 *  void
 *****************************************************************************/
void cam_hdr_stop_req_hdlr(ilm_struct *ilm_ptr)
{
#if defined(__MED_CAM_HDR_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_FEATURE_CTRL_STRUCT CalInPara;
    CAL_SCENARIO_CTRL_STRUCT CalHdrPara;
    CAL_CAMERA_POSTPROC_STRUCT CalHdrPostProcPara;
    CAL_POSTPROC_STRUCT CalPostProcPara;
    media_cam_stop_hdr_req_struct *req_p;
    kal_int32 result = MED_RES_OK;
    kal_bool is_src_image_ready = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CAM_FUNC_ENTRY(CAM_HDR_STOP_REQ_HDLR);
    
    req_p = (media_cam_stop_hdr_req_struct *)ilm_ptr->local_para_ptr;
    cam_context_p->file_name_p = req_p->filename_p;
    
    if (CAM_IN_STATE(CAM_CAPTURE) || CAM_IN_STATE(CAM_HDR))
    {
        if (CAM_IN_STATE(CAM_CAPTURE))
        {
            if (!cam_context_p->file_name_p)
            {
                cam_capture_still_image_stop();
                CAM_FREE_CAPTURE_BUFFER();
            }
            else
            {         
                cam_context_p->is_waiting_save = KAL_TRUE;
                CAM_FUNC_ENTRY(CAM_WAITING_SAVE);
                return;
            }
        }
        else if (CAM_IN_STATE(CAM_HDR))
        {
            CAM_FUNC_ENTRY(CAM_HDR_ABORT);
            CalInPara.FeatureId = CAL_FEATURE_CAMERA_HDR_CAPTURE_ABORT;
            CalInPara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
            CalCtrl(CAL_FEATURE_CTRL, &CalInPara, NULL, 0, NULL);

            CalPostProcPara.PostProcMode = PP_MODE_HDR;
            CalHdrPostProcPara.pPostProcPara = &CalPostProcPara;
            CalHdrPara.ScenarioId = CAL_SCENARIO_POST_PROCESSING;
            CalHdrPara.ScenarioCtrlCode = CAL_CTRL_CODE_STOP;
            CalHdrPara.ScenarioCtrlParaLen = sizeof(CAL_CAMERA_POSTPROC_STRUCT);
            CalHdrPara.pScenarioCtrlPara = & CalHdrPostProcPara;
            CalCtrl(CAL_SCENARIO_CTRL, (void *) &CalHdrPara, NULL, 0, NULL);

            is_src_image_ready = KAL_TRUE;          
        }
        cam_free_working_buffer();
        CAM_ENTER_STATE(CAM_READY);        
    }
    else if (CAM_IN_STATE(CAM_READY) && cam_context_p->is_hdr_done)
    {
        is_src_image_ready = KAL_TRUE;      
    }
    else
        cam_set_result(MED_RES_FAIL);

    if (is_src_image_ready && 
        cam_context_p->file_name_p && 
        cam_context_p->hdr_src_buffer_p)
    {
        if ((result = cam_open_image_file(cam_context_p->file_name_p)) == MED_RES_OK)
        {
            result = cam_write_close_image_file(
                        cam_context_p->jpeg_image_address, 
                        cam_context_p->jpeg_image_size);
        }       
        cam_set_result(result);
        CAM_FREE_HDR_BUFFER();
    }
    
    CAM_SET_EVENT(CAM_EVT_SAVE);

#else /* __MED_CAM_HDR_SUPPORT__ */
    cam_set_result(MED_RES_FAIL);
    CAM_SET_EVENT(CAM_EVT_SAVE);
#endif /* __MED_CAM_HDR_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  cam_hdr_save_images_req_hdlr
 * DESCRIPTION
 *  This function is to handle save hdr images request.
 * PARAMETERS
 *  ilm_ptr     [in]  ilm struct
 * RETURNS
 *  void
 *****************************************************************************/
void cam_hdr_save_images_req_hdlr(ilm_struct *ilm_ptr)
{
#if defined(__MED_CAM_HDR_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_save_hdr_images_req_struct *req_p = NULL;
    kal_int32 result = MED_RES_FAIL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CAM_FUNC_ENTRY(CAM_HDR_SAVE_IMAGES_REQ_HDLR);
    CAM_STATE_TRACE(cam_context_p->state);
    
    if (ilm_ptr)
        req_p = (media_cam_save_hdr_images_req_struct *)ilm_ptr->local_para_ptr;

    cam_context_p->is_hdr_waiting_save = KAL_FALSE;
    
    if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_HDR && 
        cam_context_p->hdr_src_buffer_p &&
        cam_context_p->hdr_working_buffer_p)
    {
        if (req_p)
        {
            cam_context_p->file_name_p = req_p->captured_filename_p;
            cam_context_p->hdr_file_name_p = req_p->hdr_filename_p;
        }
        
        if (cam_context_p->is_hdr_done)
        {
            do{
                if (cam_context_p->file_name_p)
                {
                    if ((result = cam_open_image_file(cam_context_p->file_name_p)) == MED_RES_OK)
                    {
                        result = cam_write_close_image_file(
                                    cam_context_p->jpeg_image_address, 
                                    cam_context_p->jpeg_image_size);
                        if (result != MED_RES_OK)
                            break;
                    }
                    else 
                        break;
                }

                if (cam_context_p->hdr_file_name_p)
                {
                    if ((result = cam_open_image_file(cam_context_p->hdr_file_name_p)) == MED_RES_OK)
                    {
                        result = cam_write_close_image_file(
                                    cam_context_p->hdr_dst_image_p, 
                                    cam_context_p->hdr_dst_image_size);
                        if (result != MED_RES_OK)
                            break;
                    }
                    else 
                        break;
                }
                
            }while(0);
            
            cam_set_result(result);
        }
        else
        {
            cam_context_p->is_hdr_waiting_save = KAL_TRUE;
            CAM_FUNC_ENTRY(CAM_HDR_WAITING_SAVE);
            return;
        }
    }
    else
    {
        cam_set_result(MED_RES_FAIL);
    }
    
    CAM_SET_EVENT(CAM_EVT_HDR_SAVE);

#else /* __MED_CAM_HDR_SUPPORT__ */
    cam_set_result(MED_RES_FAIL);
    CAM_SET_EVENT(CAM_EVT_HDR_SAVE);
#endif /* __MED_CAM_HDR_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  cam_quickview_event_ind_hdlr
 * DESCRIPTION
 *  This function is to handle camera quickview event indication.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_quickview_event_ind_hdlr(media_cam_event_ind_struct* ind_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cam_context_p->media_mode == MED_MODE_BUFFER &&
        cam_context_p->quickview_output)
    {
        cam_set_result(ind_p->cause);

    #if defined(__MED_CAM_HDR_SUPPORT__)
        if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_HDR)
        {
            // Event has set in previous
            cam_send_hdr_result_ind(
                (kal_int16)ind_p->cause, 
                CAM_HDR_CAPTURE_QUICKVIEW_RAWDATA,
                cam_context_p->quickview_output_buffer_address,
                cam_context_p->quickview_output_buffer_size);
        }
        else
    #endif /* __MED_CAM_HDR_SUPPORT__ */       
    #if defined(__ZERO_SHUTTER_DELAY_SUPPORT__)
        if (cam_context_p->capture_mode != CAM_STILL_CAPTURE_ZSD)
    #endif
        {
            CAM_SET_EVENT(CAM_EVT_CAPTURE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cam_panorama_image_ready_ind_hdlr
 * DESCRIPTION
 *  This function is to handle camera panorama event indication.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_panorama_image_ready_ind_hdlr(media_cam_event_ind_struct* ind_p)
{
#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_FEATURE_CTRL_STRUCT CalInPara;
    CAL_FEATURE_CAMERA_PANO_ADD_IMAGE_STRUCT PanoAddImg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_capture_still_image_stop();
    
    if (cam_context_p->stitch_image_address)
    {
        cam_context_p->current_shot_number++;
        
        if (cam_context_p->capture_buffer_pp && cam_context_p->capture_buffer_size_p)
        {
            *cam_context_p->capture_buffer_pp = (void*)cam_context_p->stitch_image_address;
            *cam_context_p->capture_buffer_size_p = cam_context_p->stitch_image_size;
        }
        cam_set_result(MED_RES_OK);
        
        // Add image for bg stitch
        if (cam_context_p->stitch_app_buffer_address)
        {
            PanoAddImg.ExtmemStartAddr = cam_context_p->stitch_app_buffer_address;
            PanoAddImg.ExtmemSize = cam_context_p->stitch_app_buffer_size;            
        }
        else
        {
            if (cam_context_p->stitch_buffer_address == NULL)
            {
                cam_context_p->stitch_buffer_size = MED_CAM_BG_STITCH_EXT_MEM_SIZE;
                cam_context_p->stitch_buffer_address = (kal_uint32)med_alloc_asm_mem_framebuffer(
                                                                        cam_context_p->app_id, 
                                                                        cam_context_p->stitch_buffer_size);
            }

            PanoAddImg.ExtmemStartAddr = cam_context_p->stitch_buffer_address;
            PanoAddImg.ExtmemSize = cam_context_p->stitch_buffer_size;
        }

        PanoAddImg.CurrentShotNumber = cam_context_p->current_shot_number;
        PanoAddImg.SrcImgFormat = cam_context_p->stitch_image_format;
        PanoAddImg.StitchDirection = cam_context_p->stitch_direction;
        PanoAddImg.ImageWidth = cam_context_p->image_width;
        PanoAddImg.ImageHeight = cam_context_p->image_height;
        PanoAddImg.ImageBufferAddr = cam_context_p->stitch_image_address;
        PanoAddImg.ImageBufferSize = cam_context_p->stitch_image_size;
        
        CalInPara.FeatureId = CAL_FEATURE_CAMERA_BG_PANO_ADD_IMAGE_START;
        CalInPara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
        CalInPara.FeatureType = CAL_FEATURE_TYPE_STRUCTURED;
        CalInPara.FeatureInfo.FeatureStructured.pPanoAddImgPara = &PanoAddImg;

        CalCtrl(CAL_FEATURE_CTRL, &CalInPara, NULL, 0, NULL);
        cam_context_p->is_bg_stitching = KAL_TRUE;
        CAM_PANO_ENTER_STATE(CAM_PANO_STITCH_BG);
    }
    else
    {
        if (cam_context_p->capture_buffer_pp && cam_context_p->capture_buffer_size_p)
        {
            *cam_context_p->capture_buffer_pp = (void*)NULL;
            *cam_context_p->capture_buffer_size_p = 0;
        }        
        cam_set_result(MED_RES_FAIL);
    }
    cam_free_working_buffer();
    CAM_ENTER_STATE(CAM_READY);
    CAM_SET_EVENT(CAM_EVT_CAPTURE);

#endif /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */   
}


/*****************************************************************************
 * FUNCTION
 *  cam_panorama_bg_stitch_ready_ind_hdlr
 * DESCRIPTION
 *  This function is to handle camera panorama event indication.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_panorama_bg_stitch_ready_ind_hdlr(media_cam_event_ind_struct* ind_p)
{
#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 buffer_address = NULL;
    kal_uint32 buffer_size = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cam_context_p->bg_stitch_count == cam_context_p->current_shot_number)
        cam_context_p->is_bg_stitching = KAL_FALSE;
    
    if (cam_context_p->is_waiting_stitch && !cam_context_p->is_bg_stitching)
    {
        CAM_FREE_STITCH_BUFFER();
        CAM_FREE_CAPTURE_BUFFER();

        if (cam_context_p->stitch_app_buffer_address)
        {
            buffer_address = cam_context_p->stitch_app_buffer_address;
            buffer_size = cam_context_p->stitch_app_buffer_size;            
        }
        else
        {
            cam_context_p->stitch_buffer_size = (CAL_PP_PANO_SCENARIO_EXT_MEMORY_SIZE+31)&0xFFFFFFE0;
            cam_context_p->stitch_buffer_address = (kal_uint32)med_alloc_asm_mem_framebuffer(
                                                                    cam_context_p->app_id, 
                                                                    cam_context_p->stitch_buffer_size);

            buffer_address = cam_context_p->stitch_buffer_address;
            buffer_size = cam_context_p->stitch_buffer_size;            
        }
        cam_context_p->is_stitch_done = KAL_FALSE;
        cam_panorama_start_stitch(buffer_address, buffer_size);

        cam_context_p->current_shot_number = 0;
        cam_context_p->is_waiting_stitch = KAL_FALSE;
        /* enter STITCH state */
        CAM_PANO_ENTER_STATE(CAM_PANO_STITCH_FINAL);   
    }

#endif /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */   
}


/*****************************************************************************
 * FUNCTION
 *  cam_panorama_stitch_ready_ind_hdlr
 * DESCRIPTION
 *  This function is to handle camera panorama event indication.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_panorama_stitch_ready_ind_hdlr(media_cam_event_ind_struct* ind_p)
{
#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
            
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->is_stitch_done = KAL_TRUE;
    CAM_FREE_STITCH_BUFFER();

    cam_context_p->stitch_app_buffer_address = NULL;
    cam_context_p->stitch_app_buffer_size = 0;

    if(CAM_PANO_IN_STATE(CAM_PANO_STITCH_FINAL) || CAM_IN_STATE(CAM_PANO_STITCH_PAUSE))
        cam_panorama_stop_stitch();

    #ifdef __CAM_TRACE_ON__
    kal_trace(TRACE_GROUP_2, CAM_STITCH_DONE, cam_context_p->state);
    #endif
    
    if (CAM_PANO_IN_STATE(CAM_PANO_STITCH_FINAL))
    {
        cam_send_stitch_result_ind(
            cam_context_p->stitch_seq_no, 
            cam_context_p->stitch_result,
            cam_context_p->stitch_jpeg_file_address, 
            cam_context_p->stitch_jpeg_file_size,
            cam_context_p->stitch_jpeg_file_width,
            cam_context_p->stitch_jpeg_file_height);
        
        CAM_PANO_ENTER_STATE(CAM_PANO_IDLE);
    }


#endif /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */   
}


/*****************************************************************************
 * FUNCTION
 *  cam_panorama_quickview_ready_ind_hdlr
 * DESCRIPTION
 *  This function is to handle camera panorama quick view ready event indication.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
cam_panorama_quickview_ready_ind_hdlr(media_cam_event_ind_struct* ind_p)
{
#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
            
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_panorama_quickview_image_ind(
            (kal_int16)ind_p->cause,
            cam_context_p->stitch_quickview_start_x,
            cam_context_p->stitch_quickview_start_y,
            cam_context_p->stitch_quickview_width,
            cam_context_p->stitch_quickview_height);
#endif /* __MED_CAM_HDR_SUPPORT__ */   
}


/*****************************************************************************
 * FUNCTION
 *  cam_hdr_quickview_event_ind_hdlr
 * DESCRIPTION
 *  This function is to handle camera hdr quickview event indication.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_hdr_quickview_event_ind_hdlr(media_cam_event_ind_struct* ind_p)
{
#if defined(__MED_CAM_HDR_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
            
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CAM_IN_STATE(CAM_HDR))
    {
        cam_send_hdr_result_ind(
            (kal_int16)ind_p->cause, 
            CAM_HDR_PROCESSED_QUICKVIEW_RAWDATA,
            cam_context_p->hdr_quickview_buffer_p,
            cam_context_p->hdr_quickview_buffer_size);        
    }
#endif /* __MED_CAM_HDR_SUPPORT__ */   
}


/*****************************************************************************
 * FUNCTION
 *  cam_hdr_quickview_event_ind_hdlr
 * DESCRIPTION
 *  This function is to handle camera hdr quickview event indication.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_hdr_main_jpeg_event_ind_hdlr(media_cam_event_ind_struct* ind_p)
{
#if defined(__MED_CAM_HDR_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
            
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CAM_IN_STATE(CAM_HDR))
    {
        cam_hdr_stop_process();
        
        cam_send_hdr_result_ind(
            (kal_int16)ind_p->cause, 
            CAM_HDR_PROCESSED_MAINIMAGE_JPEG,
            cam_context_p->hdr_dst_image_p,
            cam_context_p->hdr_dst_image_size);

        cam_context_p->is_hdr_done = KAL_TRUE;
        CAM_ENTER_STATE(CAM_READY);

        if (cam_context_p->is_hdr_waiting_save)
            cam_hdr_save_images_req_hdlr(NULL);
    }
#endif /* __MED_CAM_HDR_SUPPORT__ */   
}

/*****************************************************************************
 * FUNCTION
 *  cam_mav_image_ready_event_ind_hdlr
 * DESCRIPTION
 *  This function is to handle camera mav capture ready event indication.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_mav_image_ready_event_ind_hdlr(media_cam_event_ind_struct* ind_p)
{
#if defined(__MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__MED_CAM_3D_IMAGE_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
            
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    //#ifdef __CAM_TRACE_ON__
    kal_trace(TRACE_GROUP_2, CAM_MAV_CAPTURE_1IMAGE, cam_context_p->state);
    //#endif
    
    if (CAM_IN_STATE(CAM_CAPTURE))
    {
        if(cam_context_p->mav_cap_result.CurrentImageNumber==cam_context_p->mav_cap_result.TotalImageNumber)
        {
            //#ifdef __CAM_TRACE_ON__
            kal_trace(TRACE_GROUP_2, CAM_MAV_CAPTURE_DONE, cam_context_p->state);
            //#endif
            
            cam_mav_capture_image_stop();
            CAM_ENTER_STATE(CAM_READY);
        }
        
        cam_send_mav_capture_image_ready_ind(
            (kal_int16)ind_p->cause,
            cam_context_p->mav_cap_result.CurrentImageNumber,
            cam_context_p->mav_cap_result.TotalImageNumber,
            cam_context_p->mav_seq_num);        
/*  // called by MMI
        if(cam_context_p->mav_cap_result.CurrentImageNumber==cam_context_p->mav_cap_result.TotalImageNumber)
        {
			cam_mav_start_stitch();
			CAM_ENTER_STATE(CAM_MAV);
		}
*/
    }
#endif /* __MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__ || __MED_CAM_3D_IMAGE_SUPPORT__ */   
}

/*****************************************************************************
 * FUNCTION
 *  cam_mav_stitch_ready_event_ind_hdlr
 * DESCRIPTION
 *  This function is to handle camera mav capture ready event indication.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_mav_stitch_ready_event_ind_hdlr(media_cam_event_ind_struct* ind_p)
{
#if defined(__MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__MED_CAM_3D_IMAGE_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
            
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //#ifdef __CAM_TRACE_ON__
    kal_trace(TRACE_GROUP_2, CAM_MAV_STITCH_DONE, cam_context_p->state);
    //#endif
    
    if (CAM_IN_STATE(CAM_MAV))
    {
        cam_mav_stop_stitch();
        cam_free_working_buffer();
    
        cam_send_mav_stitch_result_ind(
            (kal_int16)ind_p->cause,
            cam_context_p->mav_result.EncodeDstBufferAddr,
            cam_context_p->mav_result.EncodeDstBufferSize,
            cam_context_p->mav_seq_num);        
            
        CAM_ENTER_STATE(CAM_READY);
    }
    /*  remove to avoid interrupt case
    else
        ASSERT(0);
    */
#endif /* __MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__||__MED_CAM_3D_IMAGE_SUPPORT__ */   
}

/*****************************************************************************
 * FUNCTION
 *  cam_mav_capture_image_stop
 * DESCRIPTION
 *  This function is to stop mav capture.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__MED_CAM_3D_IMAGE_SUPPORT__)
static void cam_mav_capture_image_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_SCENARIO_CTRL_STRUCT CalCaptureScenarioPara;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CalCaptureScenarioPara.ScenarioId=CAL_SCENARIO_CAMERA_MAV_CAPTURE;
    CalCaptureScenarioPara.ScenarioCtrlCode=CAL_CTRL_CODE_STOP;
    CalCaptureScenarioPara.ScenarioCtrlParaLen=0;
    CalCaptureScenarioPara.pScenarioCtrlPara=NULL;
    CalCtrl(CAL_SCENARIO_CTRL, (void *) &CalCaptureScenarioPara, NULL, 0, NULL);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  cam_start_mav_stitch_req_hdlr
 * DESCRIPTION
 *  This function is to handle Start stitch MAV Process request from MMI,
 *  it will send mesg to MED_V and wait indication from MED_V, then set event.
 * PARAMETERS
 *  ilm_ptr     [in]  ilm struct
 * RETURNS
 *  void
 *****************************************************************************/
void cam_start_mav_stitch_req_hdlr(ilm_struct *ilm_ptr)
{
#if defined(__MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__MED_CAM_3D_IMAGE_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //media_cam_start_mav_stitch_req_struct *req_p;
    //kal_uint32 buffer_address = NULL;
    //kal_uint32 buffer_size = 0;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        
    if (CAM_IN_STATE(CAM_READY))
    {
        //req_p = (media_cam_start_mav_stitch_req_struct*) ilm_ptr->local_para_ptr;

        //Ricky free memory only in the final stage
        //CAM_FREE_STITCH_BUFFER();
        //CAM_FREE_CAPTURE_BUFFER();
        
        //Ricky TBD
        //cam_context_p->is_stitch_done = KAL_FALSE;
        if(cam_context_p->mav_cap_result.CurrentImageNumber==cam_context_p->mav_cap_result.TotalImageNumber)
        {
			cam_mav_start_stitch();
			CAM_ENTER_STATE(CAM_MAV);
		}
        
        /* enter STITCH state */
        //CAM_PANO_ENTER_STATE(CAM_PANO_STITCH_FINAL);
    }
    else
    {
        //cam_context_p->is_waiting_stitch = KAL_TRUE;
    }
    /* set event */
    CAM_SET_EVENT(CAM_EVT_BLOCK);

#else /* __MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__ || __MED_CAM_3D_IMAGE_SUPPORT__*/
    /* not reach here */
    ASSERT(0);
#endif /* __MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__ || __MED_CAM_3D_IMAGE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  cam_stop_mav_stitch_req_hdlr
 * DESCRIPTION
 *  This function is to handle Stop stitch Panorama Process request from MMI,
 *  it will send mesg to MED_V and wait indication from MED_V, then set event.
 * PARAMETERS
 *  ilm_ptr     [in]  ilm struct
 * RETURNS
 *  void
 *****************************************************************************/
void cam_stop_mav_stitch_req_hdlr(ilm_struct *ilm_ptr)
{
#if defined(__MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__MED_CAM_3D_IMAGE_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CAM_IN_STATE(CAM_MAV))
    {
        cam_mav_stop_stitch();        
        
        CAM_ENTER_STATE(CAM_READY);
    }

    CAM_FREE_STITCH_BUFFER();
    
    CAM_SET_EVENT(CAM_EVT_BLOCK);

#else /* __MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__ || __MED_CAM_3D_IMAGE_SUPPORT__ */
    /* not reach here */
    ASSERT(0);
#endif /* __MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__ || __MED_CAM_3D_IMAGE_SUPPORT__ */
}

#if defined(__MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__MED_CAM_3D_IMAGE_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  cam_mav_start_stitch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cam_mav_start_stitch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_SCENARIO_CTRL_STRUCT CalStitchScenarioPara;
    CAL_CAMERA_POSTPROC_STRUCT CalPostProcPara;
    CAL_POSTPROC_STRUCT PostProcPara;
    CAL_MDP_POSTPROC_STRUCT MdpPostProcPara;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    //call CAL to do stitch
    PostProcPara.PostProcMode = PP_MODE_MAV;
    //Ricky TBD
    CalPostProcPara.ExtmemStartAddress = cam_context_p->extmem_start_address;
    CalPostProcPara.ExtmemSize  = cam_context_p->extmem_size;
//    CalPostProcPara.JpegBuffAddr = cam_context_p->jpeg_buffer_address;
//    CalPostProcPara.JpegBuffSize = cam_context_p->jpeg_buffer_size;
    CalPostProcPara.pPostProcPara = &PostProcPara;
    CalPostProcPara.pMdpPara = &MdpPostProcPara;

    CalStitchScenarioPara.ScenarioId = CAL_SCENARIO_POST_PROCESSING;
    CalStitchScenarioPara.ScenarioCtrlCode = CAL_CTRL_CODE_START;
    CalStitchScenarioPara.ScenarioCtrlParaLen = sizeof(CAL_CAMERA_POSTPROC_STRUCT );
    CalStitchScenarioPara.pScenarioCtrlPara = & CalPostProcPara;
    CalCtrl(CAL_SCENARIO_CTRL, (void *) &CalStitchScenarioPara, NULL, 0, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  cam_mav_stop_stitch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cam_mav_stop_stitch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_SCENARIO_CTRL_STRUCT CalStitchScenarioPara;
    CAL_CAMERA_POSTPROC_STRUCT CalPostProcPara;
    CAL_POSTPROC_STRUCT PostProcPara;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PostProcPara.PostProcMode = PP_MODE_MAV;
    CalPostProcPara.pPostProcPara = &PostProcPara;
    
    CalStitchScenarioPara.ScenarioId = CAL_SCENARIO_POST_PROCESSING;
    CalStitchScenarioPara.ScenarioCtrlCode = CAL_CTRL_CODE_STOP;
    CalStitchScenarioPara.ScenarioCtrlParaLen = sizeof(CAL_CAMERA_POSTPROC_STRUCT);
    CalStitchScenarioPara.pScenarioCtrlPara = &CalPostProcPara;
        
    CalCtrl(CAL_SCENARIO_CTRL, (void *)&CalStitchScenarioPara, NULL, 0, NULL);
}
#endif /* __MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__ || __MED_CAM_3D_IMAGE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  cam_capture_event_ind_hdlr
 * DESCRIPTION
 *  This function is to handle camera capture event indication.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_capture_event_ind_hdlr(media_cam_event_ind_struct* ind_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MED_CAM_MUTILSHOT_SUPPORT__
    kal_uint32 buffer_address = 0, buffer_size = 0;
    kal_int32 average_size = 0;
#endif
#ifdef __MED_CAM_BESTSHOT_SUPPORT__
    kal_uint8 bestshot_index;
#endif
#if defined(__CAM_BSS_DEBUG_MODE__)
    FS_HANDLE file_handle;
    kal_uint32 len;
    kal_wchar file_name[512], idx[20];   
#endif 
    kal_int32 result = MED_RES_OK; 
#ifdef __MED_CAM_HDR_SUPPORT__
    kal_int32 prev_state = cam_context_p->state;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CAM_FUNC_ENTRY(CAM_CAPTURE_EVENT_HDLR);
    CAM_STATE_TRACE(cam_context_p->state);
    
    MED_CAM_STOP_LOGGING("CPJ");
    MED_CAM_GET_STOP_TIME_AND_PRINT_TRACE(CAM_CAPTURE_JPEG_DURATION);

    #if defined(__MED_CAM_MUTILSHOT_SUPPORT__)
    if (cam_context_p->is_waiting_burst_capture_stop)
    {
        cam_capture_still_image_stop();
        
        CAM_FREE_CAPTURE_BUFFER();
        CAM_FREE_HDR_BUFFER();
        cam_free_working_buffer();
        CAM_ENTER_STATE(CAM_READY);
        CAM_SET_EVENT(CAM_EVT_STOP);
        cam_context_p->is_waiting_burst_capture_stop = KAL_FALSE;
        return;
    }
    #endif
    
    cam_capture_still_image_stop();
    cam_context_p->is_main_jpeg_ready = KAL_TRUE;

    CAM_ENTER_STATE(CAM_READY);
    if (cam_context_p->jpeg_image_size <= 0 || ind_p->cause != MED_RES_OK)
    {
        cam_context_p->jpeg_image_size = 0;
        result = MED_RES_FAIL;
    }

    if (result == MED_RES_FAIL)
    {
        // error handling
    #if defined(__MED_CAM_MUTILSHOT_SUPPORT__)
        if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_BURST_SHOT)
        {
            cam_send_capture_event_ind(result, (kal_uint16) cam_context_p->captured_number);
        }
        #if defined(__MED_CAM_BESTSHOT_SUPPORT__) || defined(__MED_CAM_EV_BRACKET_SUPPORT__) || defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
        else if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_EV_BRACKETING ||
                 cam_context_p->capture_mode == CAM_STILL_CAPTURE_PANO_VIEW ||
                 cam_context_p->capture_mode == CAM_STILL_CAPTURE_AUTO_RAMA ||
                 cam_context_p->capture_mode == CAM_STILL_CAPTURE_BEST_SHOT)
        {
            cam_set_result(result);
            CAM_SET_EVENT(CAM_EVT_CAPTURE);
        }
        #endif
        else
    #endif /* __MED_CAM_MUTILSHOT_SUPPORT__ */            
        {
        #ifdef __MED_CAM_HDR_SUPPORT__
            if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_HDR)
            {
                cam_send_hdr_result_ind(
                    (kal_int16)result, 
                    CAM_HDR_CAPTURE_MAINIMAGE_JPEG,
                    NULL,
                    NULL);
            }
        #endif
            if (cam_context_p->capture_buffer_pp != NULL)
            {
                cam_set_result(result);
                CAM_SET_EVENT(CAM_EVT_ENCODE_JPEG);
            }
            else if (cam_context_p->is_waiting_save)
            {
                cam_save_req_hdlr(NULL);
                cam_set_result(result);
            }
            else if (!cam_context_p->quickview_output)
            {
                cam_set_result(result);
                CAM_SET_EVENT(CAM_EVT_CAPTURE);
            }
        }
        
        cam_free_working_buffer();
        return;
    }

    if (cam_context_p->jpeg_file_info_p)
    {
        cam_context_p->jpeg_file_info_p->file_address[cam_context_p->captured_number - 1] = cam_context_p->jpeg_image_address;
        cam_context_p->jpeg_file_info_p->file_size[cam_context_p->captured_number - 1] = cam_context_p->jpeg_image_size;
    }

#ifdef __MED_CAM_MUTILSHOT_SUPPORT__    
    if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_BURST_SHOT)
    {   
        cam_send_capture_event_ind(MED_RES_OK, (kal_uint16) cam_context_p->captured_number);
    }
    #ifdef __MED_CAM_EV_BRACKET_SUPPORT__
    else if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_EV_BRACKETING)
    {
        cam_context_p->expo_bracket_level++;
    }
    #endif /* __MED_CAM_EV_BRACKET_SUPPORT__ */
    #ifdef __MED_CAM_BESTSHOT_SUPPORT__
    else if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_BEST_SHOT)
    {
    #if defined(__CAM_BSS_DEBUG_MODE__)
        kal_wsprintf(idx, ".%d.jpg", cam_context_p->captured_number - 1);
        kal_wstrcpy(file_name, cam_context_p->file_name_p);
        kal_wstrcat(file_name,idx);

        file_handle = FS_Open((kal_wchar*) file_name, FS_CREATE | FS_READ_WRITE);

        if (file_handle >= FS_NO_ERROR)
        {
            result = FS_Write(file_handle, (void*)cam_context_p->jpeg_image_address, cam_context_p->jpeg_image_size, &len);
            FS_Close(file_handle);
            if ((result < FS_NO_ERROR)||(cam_context_p->jpeg_image_size != len))
            {
                FS_Delete((kal_wchar*) file_name);
            }
        }
    #endif /* __CAM_BSS_DEBUG_MODE__ */
    }
    #endif /* __MED_CAM_BESTSHOT_SUPPORT__ */
#endif /* __MED_CAM_MUTILSHOT_SUPPORT__ */
    
    if (cam_context_p->captured_number == cam_context_p->snapshot_number)
    {
        cam_free_working_buffer();
        if (cam_context_p->media_mode == MED_MODE_BUFFER)
        {
            #if defined(__ZERO_SHUTTER_DELAY_SUPPORT__)
            if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_ZSD)
            {
                CAM_SET_EVENT(CAM_EVT_CAPTURE);
            }
            #endif
            if (cam_context_p->capture_buffer_pp != NULL)
            {
                *cam_context_p->capture_buffer_pp = (void*)cam_context_p->jpeg_image_address;
                *cam_context_p->capture_buffer_size_p = cam_context_p->jpeg_image_size;
                cam_set_result(result);
                CAM_SET_EVENT(CAM_EVT_ENCODE_JPEG);

                cam_context_p->capture_buffer_pp = NULL;
                cam_context_p->capture_buffer_size_p = NULL;
            }
            else if (cam_context_p->is_waiting_save)
            {
                cam_save_req_hdlr(NULL);
                return;
            }
            else if (!cam_context_p->quickview_output && 
                      cam_context_p->capture_mode != CAM_STILL_CAPTURE_HDR)
            {
                cam_set_result(result);
                CAM_SET_EVENT(CAM_EVT_CAPTURE);
            }
            #ifdef __MED_CAM_HDR_SUPPORT__
            if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_HDR)
            {
                CAM_FREE_CAPTURE_BUFFER();

                if (prev_state == CAM_CAPTURE && !cam_context_p->is_waiting_save)
                {
                    cam_send_hdr_result_ind(
                        (kal_int16)result, 
                        CAM_HDR_CAPTURE_MAINIMAGE_JPEG,
                        cam_context_p->jpeg_image_address,
                        cam_context_p->jpeg_image_size); 
                
                    CAM_ENTER_STATE(CAM_HDR);
								
//                    cam_context_p->hdr_working_buffer_size = MAX_CAM_HDR_WORKING_EXT_MEM_SIZE;
//                    cam_context_p->hdr_working_buffer_p = (kal_uint32) med_alloc_asm_mem_framebuffer(
//                                                                            cam_context_p->app_id ,
//                                                                            cam_context_p->hdr_working_buffer_size);					
/*
					ASSERT(MAX_CAM_HDR_WORKING_EXT_MEM_SIZE <= CAM_HDR_DST_BUF_SIZE);
                    cam_context_p->hdr_working_buffer_size = MAX_CAM_HDR_WORKING_EXT_MEM_SIZE;
					cam_context_p->hdr_working_buffer_p = cam_context_p->capture_buffer_p;
*/
					ASSERT(CAM_HDR_TOTAL_BUF_SIZE >= CAM_HDR_SRC_EXT_MEM_SIZE+MAX_CAM_HDR_WORKING_EXT_MEM_SIZE);
					cam_context_p->hdr_working_buffer_size = MAX_CAM_HDR_WORKING_EXT_MEM_SIZE;
					cam_context_p->hdr_working_buffer_p = cam_context_p->hdr_src_buffer_p + CAM_HDR_SRC_EXT_MEM_SIZE;
                    if (cam_context_p->quickview_output)
                    {
                        cam_context_p->hdr_quickview_buffer_size = cam_context_p->quickview_output_buffer_size;
                        cam_context_p->hdr_quickview_buffer_p = (kal_uint32) med_alloc_asm_mem_framebuffer(
                                                                                cam_context_p->app_id, 
                                                                                cam_context_p->hdr_quickview_buffer_size);
                    }
                    cam_hdr_start_process();
                }
            }
            #endif /* __MED_CAM_HDR_SUPPORT__ */
        }
    #ifdef __MED_CAM_MUTILSHOT_SUPPORT__
        else if (cam_context_p->media_mode == MED_MODE_ARRAY)
        {
            if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_EV_BRACKETING ||
                cam_context_p->capture_mode == CAM_STILL_CAPTURE_PANO_VIEW ||
                cam_context_p->capture_mode == CAM_STILL_CAPTURE_AUTO_RAMA ||
                cam_context_p->capture_mode == CAM_STILL_CAPTURE_RAW_DATA)
            {
                cam_set_result(result);
                CAM_SET_EVENT(CAM_EVT_CAPTURE);
            }
            #ifdef __MED_CAM_BESTSHOT_SUPPORT__
            else if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_BEST_SHOT)
            {
                MED_CAM_GET_START_TIME(CAM_BSS_DURATION);
                bestshot_index = cam_bestshot_compare_result();
                MED_CAM_GET_STOP_TIME_AND_PRINT_TRACE(CAM_BSS_DURATION);

                if (bestshot_index == cam_context_p->captured_number - 1)
                {
                    cam_context_p->best_image_p = cam_context_p->jpeg_image_address;
                    cam_context_p->best_image_size = cam_context_p->jpeg_image_size;                    
                }

                if (cam_context_p->capture_buffer_pp && cam_context_p->capture_buffer_size_p)
                {
                    *cam_context_p->capture_buffer_pp = (void*)cam_context_p->best_image_p;
                    *cam_context_p->capture_buffer_size_p = cam_context_p->best_image_size;
                }
    
                cam_set_result(result);
                CAM_SET_EVENT(CAM_EVT_CAPTURE);
            }            
            #endif /* __MED_CAM_BESTSHOT_SUPPORT__ */
        }
    #endif /* __MED_CAM_MUTILSHOT_SUPPORT__ */        
    }
#ifdef __MED_CAM_MUTILSHOT_SUPPORT__
    else if (cam_context_p->captured_number < cam_context_p->snapshot_number)
    {
        if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_BURST_SHOT || 
            cam_context_p->capture_mode == CAM_STILL_CAPTURE_EV_BRACKETING)
        {
            ASSERT(cam_context_p->jpeg_image_address >= cam_context_p->jpeg_buffer_address);
            cam_context_p->jpeg_buffer_size -= (cam_context_p->jpeg_image_address - cam_context_p->jpeg_buffer_address) + cam_context_p->jpeg_image_size;
            cam_context_p->jpeg_buffer_address = cam_context_p->jpeg_image_address + cam_context_p->jpeg_image_size;

            buffer_address = cam_context_p->jpeg_buffer_address;
            buffer_size = cam_context_p->jpeg_buffer_size;

            if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_BURST_SHOT)
            {
                average_size = buffer_size/(cam_context_p->snapshot_number - (cam_context_p->captured_number-1));
                if (cam_context_p->jpeg_file_info_p->file_size[cam_context_p->captured_number-1] > average_size)
                {
                    if (cam_context_p->image_quality > JPEG_ENCODE_QUALITY_LOW)
                    {
                        cam_context_p->image_quality--;
                    }
                }                
            }
        }
        #ifdef __MED_CAM_BESTSHOT_SUPPORT__
        else if (cam_context_p->capture_mode == CAM_STILL_CAPTURE_BEST_SHOT)
        {
            MED_CAM_GET_START_TIME(CAM_BSS_DURATION);
            bestshot_index = cam_bestshot_compare_result();
            MED_CAM_GET_STOP_TIME_AND_PRINT_TRACE(CAM_BSS_DURATION);

            if (bestshot_index == cam_context_p->captured_number - 1)
            {
                cam_context_p->best_image_buffer_p = cam_context_p->jpeg_buffer_address;
                cam_context_p->best_image_p = cam_context_p->jpeg_image_address;
                cam_context_p->best_image_size = cam_context_p->jpeg_image_size;             
            }

            if (cam_context_p->best_image_buffer_p == cam_context_p->bss_buffer2_p)
            {
                cam_context_p->jpeg_buffer_address = cam_context_p->bss_buffer1_p;
                cam_context_p->jpeg_buffer_size = cam_context_p->bss_buffer1_size;                
            }
            else
            {
                cam_context_p->jpeg_buffer_address = cam_context_p->bss_buffer2_p;
                cam_context_p->jpeg_buffer_size = cam_context_p->bss_buffer2_size;
            }
            buffer_address = cam_context_p->jpeg_buffer_address;
            buffer_size = cam_context_p->jpeg_buffer_size;
        }
        #endif /* __MED_CAM_BESTSHOT_SUPPORT__ */

        if (cam_context_p->captured_number == cam_context_p->snapshot_number - 1)
            cam_context_p->multishot_info = MULTISHOT_END;
        else
            cam_context_p->multishot_info = MULTISHOT_NOT_FIRST;
        
        cam_capture_still_image_start(buffer_address, buffer_size);
    }
#endif /* __MED_CAM_MUTILSHOT_SUPPORT__ */    
}


/*****************************************************************************
 * FUNCTION
 *  cam_event_ind_hdlr
 * DESCRIPTION
 *  This function is to handle camera event indication.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_event_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_event_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_cam_event_ind_struct*) ilm_ptr->local_para_ptr;

    if ((ind_p->event == CAM_EVT_CAPTURE) && CAM_IN_STATE(CAM_CAPTURE))
    {
        cam_capture_event_ind_hdlr(ind_p);
    }
    #ifdef AF_SUPPORT    
    else if ((ind_p->event == CAM_EVT_AUTOFOCUS))
    {
        cam_send_autofocus_process_done_ind(ind_p->cause, cam_context_p->af_result.AfSuccessZone);
    }
    #endif
    else if ((ind_p->event == CAM_EVT_QUICKVIEW) && CAM_IN_STATE(CAM_CAPTURE))
    {
        cam_quickview_event_ind_hdlr(ind_p);
    }
    #if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
    else if (ind_p->event == CAM_EVT_PANO_IMG_READY && CAM_IN_STATE(CAM_CAPTURE))
    {
        cam_panorama_image_ready_ind_hdlr(ind_p);
    }
    else if (ind_p->event == CAM_EVT_PANO_BG_STITCH_READY)
    {
        cam_panorama_bg_stitch_ready_ind_hdlr(ind_p);
    }
    else if (ind_p->event == CAM_EVT_PANO_STITCH_READY)
    {
        cam_panorama_stitch_ready_ind_hdlr(ind_p);
    }
    else if (ind_p->event == CAM_EVT_PANO_QUICKVIEW_READY)
    {
        cam_panorama_quickview_ready_ind_hdlr(ind_p);
    }
    #endif /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */
    #if defined(__MED_CAM_HDR_SUPPORT__)        
    else if (ind_p->event == CAM_EVT_HDR_QUICKVIEW)
    {
        cam_hdr_quickview_event_ind_hdlr(ind_p);
    }
    else if (ind_p->event == CAM_EVT_HDR_MAINIMAGE)
    {
        cam_hdr_main_jpeg_event_ind_hdlr(ind_p);
    }
    #endif /* __MED_CAM_HDR_SUPPORT__ */    
    #if defined(__MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__MED_CAM_3D_IMAGE_SUPPORT__)        
    else if (ind_p->event == CAM_EVT_MAV_CAPTURE_IMG_READY)
    {
        cam_mav_image_ready_event_ind_hdlr(ind_p);
    }
    else if (ind_p->event == CAM_EVT_MAV_STITCH_IMG_READY)
    {
        cam_mav_stitch_ready_event_ind_hdlr(ind_p);
    }
    #endif /* __MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__ || __MED_CAM_3D_IMAGE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  cam_get_buffer_content_req_hdlr
 * DESCRIPTION
 *  This function is to get frame buffer content.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_get_buffer_content_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_get_buff_content_req_struct *req_p;
    CAL_CAMERA_GET_PREVIEW_IMAGE_STRUCT GetBuffPara;
    CAL_FEATURE_CTRL_STRUCT CalInPara;
    MM_IMAGE_ROTATE_ENUM IncludedAngle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CAM_IN_STATE(CAM_PREVIEW))
    {
        if (cam_context_p->lcd_id == 0) // MainLCD
        {           
            if (cam_context_p->cam_id == CAL_CAMERA_SOURCE_MAIN)
            {
                IncludedAngle = (MM_IMAGE_ROTATE_ENUM)CAM_ABS(cam_context_p->ui_rotate - CAM_MAIN_SENSOR_ROTATE);
            }
            else
            {
                IncludedAngle = (MM_IMAGE_ROTATE_ENUM)CAM_ABS(cam_context_p->ui_rotate - CAM_SUB_SENSOR_ROTATE);
            }
        }
        else // SubLCD
        {
            if (cam_context_p->cam_id == CAL_CAMERA_SOURCE_MAIN)
            {
                IncludedAngle = (MM_IMAGE_ROTATE_ENUM)CAM_ABS(cam_context_p->ui_rotate - CAM_MAIN_SENSOR_ROTATE);
            }
            else
            {
                IncludedAngle = (MM_IMAGE_ROTATE_ENUM)CAM_ABS(cam_context_p->ui_rotate - CAM_SUB_SENSOR_ROTATE);
            }            
        }

        req_p = (media_cam_get_buff_content_req_struct*)ilm_ptr->local_para_ptr;

        CalInPara.FeatureId = CAL_FEATURE_CAMERA_GET_PREVIEW_IMAGE;
        CalInPara.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
        CalInPara.FeatureInfo.FeatureStructured.pCamGetPreviewImageInPara = &GetBuffPara;

        GetBuffPara.ImageRotAngle = (MM_IMAGE_ROTATE_ENUM)cam_context_p->preview_rotate;
        GetBuffPara.ImageBuffAddr = req_p->buffer_address;
        GetBuffPara.ImageBuffSize = req_p->buffer_size;
        GetBuffPara.ImageDataFormat = (MM_IMAGE_FORMAT_ENUM)cam_context_p->image_data_format;
        if (IncludedAngle == MM_IMAGE_ROTATE_90 || IncludedAngle == MM_IMAGE_ROTATE_270)
        {  
            GetBuffPara.ImageWidth = req_p->buffer_height;
            GetBuffPara.ImageHeight = req_p->buffer_width;
        }
        else
        {
            GetBuffPara.ImageWidth = req_p->buffer_width;
            GetBuffPara.ImageHeight = req_p->buffer_height;
        }
        
        CalCtrl(CAL_FEATURE_CTRL, &CalInPara, NULL, 0, NULL);
        cam_set_result(MED_RES_OK);
    }
    else
    {
        cam_set_result(MED_RES_FAIL);
    }
    CAM_SET_EVENT(CAM_EVT_GET_BUFF_CONTENT);
}


/*****************************************************************************
 * FUNCTION
 *  cam_get_predicted_image_size_req_hdlr
 * DESCRIPTION
 *  This function is to get predicted capture image size.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_get_predicted_image_size_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_get_predicted_image_size_req_struct *req_p;
    MM_ERROR_CODE_ENUM ret = MM_ERROR_NONE;
    CAL_FEATURE_CTRL_STRUCT CalInPara;
    CAL_CAMERA_GET_JPEG_SIZE_ESTIMATION_STRUCT JpegSizeEstimation;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_cam_get_predicted_image_size_req_struct*)ilm_ptr->local_para_ptr;

    JpegSizeEstimation.ImageWidth=req_p->image_width;
    JpegSizeEstimation.ImageHeight=req_p->image_height;
    JpegSizeEstimation.JpegEncQuality=(JPEG_ENCODE_QUALITTY_ENUM)req_p->image_qty;
    JpegSizeEstimation.JpegSamplingFormat=MM_IMAGE_FORMAT_YUV422;
    CalInPara.FeatureId = CAL_FEATURE_CAMERA_GET_JPEG_SIZE_ESTIMATION;
    CalInPara.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
    CalInPara.FeatureInfo.FeatureStructured.pGetJpegSizeEstimationPara = &JpegSizeEstimation;
    ret = CalCtrl(CAL_FEATURE_CTRL, &CalInPara, &CalInPara, sizeof(CalInPara), NULL);
    *(req_p->image_size_p)=CalInPara.FeatureCurrentValue;

    cam_set_result(ret);
    CAM_SET_EVENT(CAM_EVT_BLOCK);
}


#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  cam_panorama_start_stitch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cam_panorama_start_stitch(kal_uint32 working_buffer_address, kal_uint32 working_buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_SCENARIO_CTRL_STRUCT CalStitchScenarioPara;
    CAL_CAMERA_POSTPROC_STRUCT CalPostProcPara;
    CAL_POSTPROC_STRUCT PostProcPara;
    CAL_MDP_POSTPROC_STRUCT MdpPostProcPara;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MdpPostProcPara.QuickViewImageEnable = cam_context_p->quickview_output;
    MdpPostProcPara.QuickViewImageFormat = MM_IMAGE_FORMAT_RGB565;
    MdpPostProcPara.QuickViewImageRotAngle = MM_IMAGE_ROTATE_0;
    MdpPostProcPara.QuickViewImageWidth = cam_context_p->quickview_output_width;
    MdpPostProcPara.QuickViewImageHeight = cam_context_p->quickview_output_height;
    MdpPostProcPara.QuickViewImageBuffAddr = cam_context_p->quickview_output_buffer_address;
    MdpPostProcPara.QuickViewImageBuffSize = cam_context_p->quickview_output_buffer_size;
    MdpPostProcPara.QuickViewImageResizeByBuffSizeEnable = cam_context_p->quickview_output_resize_by_buffer_size_enable;
    
    //call CAL to do stitch
    PostProcPara.PostProcMode = PP_MODE_PANORAMA;
    CalPostProcPara.ExtmemStartAddress = working_buffer_address;
    CalPostProcPara.ExtmemSize  = working_buffer_size;
    CalPostProcPara.JpegBuffAddr = cam_context_p->jpeg_buffer_address;
    CalPostProcPara.JpegBuffSize = cam_context_p->jpeg_buffer_size;
    CalPostProcPara.pPostProcPara = &PostProcPara;
    CalPostProcPara.pMdpPara = &MdpPostProcPara;

    CalStitchScenarioPara.ScenarioId = CAL_SCENARIO_POST_PROCESSING;
    CalStitchScenarioPara.ScenarioCtrlCode = CAL_CTRL_CODE_START;
    CalStitchScenarioPara.ScenarioCtrlParaLen = sizeof(CAL_CAMERA_POSTPROC_STRUCT );
    CalStitchScenarioPara.pScenarioCtrlPara = & CalPostProcPara;
    CalCtrl(CAL_SCENARIO_CTRL, (void *) &CalStitchScenarioPara, NULL, 0, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  cam_panorama_stop_stitch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cam_panorama_stop_stitch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_SCENARIO_CTRL_STRUCT CalStitchScenarioPara;
    CAL_CAMERA_POSTPROC_STRUCT CalPostProcPara;
    CAL_POSTPROC_STRUCT PostProcPara;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PostProcPara.PostProcMode = PP_MODE_PANORAMA;
    CalPostProcPara.pPostProcPara = &PostProcPara;
    
    CalStitchScenarioPara.ScenarioId = CAL_SCENARIO_POST_PROCESSING;
    CalStitchScenarioPara.ScenarioCtrlCode = CAL_CTRL_CODE_STOP;
    CalStitchScenarioPara.ScenarioCtrlParaLen = sizeof(CAL_CAMERA_POSTPROC_STRUCT);
    CalStitchScenarioPara.pScenarioCtrlPara = &CalPostProcPara;
        
    CalCtrl(CAL_SCENARIO_CTRL, (void *)&CalStitchScenarioPara, NULL, 0, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  cam_panorama_stop_bg_stitch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cam_panorama_stop_bg_stitch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_FEATURE_CTRL_STRUCT CalInPara;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CalInPara.FeatureId = CAL_FEATURE_CAMERA_BG_PANO_ADD_IMAGE_STOP;
    CalInPara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
    CalCtrl(CAL_FEATURE_CTRL, &CalInPara, NULL, 0, NULL);
}
#endif /* __MED_CAM_PANORAMA_VIEW_SUPPORT__ */


#if defined(__MED_CAM_HDR_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  cam_hdr_start_process
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cam_hdr_start_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_SCENARIO_CTRL_STRUCT CalHdrPara;
    CAL_CAMERA_POSTPROC_STRUCT CalPostProcPara;
    CAL_POSTPROC_STRUCT PostProcPara;
    CAL_MDP_POSTPROC_STRUCT MdpPostProcPara;
    kal_int32 resized_offset_x = 0;
    kal_int32 resized_offset_y = 0;
    kal_int32 resized_width = 0;
    kal_int32 resized_height = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CAM_FUNC_ENTRY(CAM_HDR_START);
    
    ASSERT(cam_context_p->hdr_working_buffer_p);
    if (cam_context_p->quickview_output)
        ASSERT(cam_context_p->hdr_quickview_buffer_p);
    
    cam_context_p->thumbnail_buffer_size = MAX_CAM_CAPTURE_THUMBNAIL_BUF_SIZE;
    cam_context_p->thumbnail_buffer_address = (kal_uint32) med_alloc_asm_mem_framebuffer(
                                                                cam_context_p->app_id, 
                                                                cam_context_p->thumbnail_buffer_size);
    ASSERT(cam_context_p->thumbnail_buffer_address);
    
    cam_util_fit_box(
            160,
            120,
            cam_context_p->image_width,
            cam_context_p->image_height,
            &resized_offset_x,
            &resized_offset_y,
            &resized_width,
            &resized_height);
    
    MdpPostProcPara.MainImageWidth = cam_context_p->image_width;
    MdpPostProcPara.MainImageHeight = cam_context_p->image_height;
    MdpPostProcPara.QuickViewImageEnable = cam_context_p->quickview_output;
    MdpPostProcPara.QuickViewImageFormat = cam_context_p->image_data_format;
    MdpPostProcPara.QuickViewImageRotAngle = MM_IMAGE_ROTATE_0;
    MdpPostProcPara.QuickViewImageWidth = cam_context_p->quickview_output_width;
    MdpPostProcPara.QuickViewImageHeight = cam_context_p->quickview_output_height;
    MdpPostProcPara.QuickViewImageBuffAddr = cam_context_p->hdr_quickview_buffer_p;
    MdpPostProcPara.ThumbnailImageEnable = KAL_TRUE;
    MdpPostProcPara.ThumbnailImageFormat = MM_IMAGE_FORMAT_RGB565;
    MdpPostProcPara.ThumbnailImageRotAngle = MM_IMAGE_ROTATE_0;
    MdpPostProcPara.ThumbnailImageWidth = resized_width;
    MdpPostProcPara.ThumbnailImageHeight = resized_height;
    MdpPostProcPara.ThumbnailImageBuffAddr = cam_context_p->thumbnail_buffer_address;
        
    //call CAL to do hdr
    PostProcPara.PostProcMode = PP_MODE_HDR;
    CalPostProcPara.SrcImageFormat = MM_IMAGE_FORMAT_JPEG;
    CalPostProcPara.SrcImageAddr= cam_context_p->jpeg_image_address;
    CalPostProcPara.SrcImageSize = cam_context_p->jpeg_image_size;
        
    CalPostProcPara.ExtmemStartAddress = cam_context_p->hdr_working_buffer_p;
    CalPostProcPara.ExtmemSize  = cam_context_p->hdr_working_buffer_size;
    CalPostProcPara.pPostProcPara = &PostProcPara;
    CalPostProcPara.pMdpPara = &MdpPostProcPara;

    CalHdrPara.ScenarioId = CAL_SCENARIO_POST_PROCESSING;
    CalHdrPara.ScenarioCtrlCode = CAL_CTRL_CODE_START;
    CalHdrPara.ScenarioCtrlParaLen = sizeof(CAL_CAMERA_POSTPROC_STRUCT);
    CalHdrPara.pScenarioCtrlPara = & CalPostProcPara;
    CalCtrl(CAL_SCENARIO_CTRL, (void *) &CalHdrPara, NULL, 0, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  cam_hdr_stop_process
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cam_hdr_stop_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_SCENARIO_CTRL_STRUCT CalHdrUtPara;
    CAL_CAMERA_POSTPROC_STRUCT CalPostProcPara;
    CAL_POSTPROC_STRUCT PostProcPara;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CAM_FUNC_ENTRY(CAM_HDR_STOP);
    
    PostProcPara.PostProcMode = PP_MODE_HDR;
    CalPostProcPara.pPostProcPara = &PostProcPara;

    CalHdrUtPara.ScenarioId = CAL_SCENARIO_POST_PROCESSING;
    CalHdrUtPara.ScenarioCtrlCode = CAL_CTRL_CODE_STOP;
    CalHdrUtPara.ScenarioCtrlParaLen = sizeof(CAL_CAMERA_POSTPROC_STRUCT);
    CalHdrUtPara.pScenarioCtrlPara = & CalPostProcPara;
    CalCtrl(CAL_SCENARIO_CTRL, (void *) &CalHdrUtPara, NULL, 0, NULL);    

    cam_free_working_buffer();
}
#endif /* __MED_CAM_HDR_SUPPORT__ */


void cam_profiling_set_active_req_hdlr(ilm_struct *ilm_ptr)
{
#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
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


void cam_profiling_set_buffer_req_hdlr(ilm_struct *ilm_ptr)
{
#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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


void cam_profiling_log_req_hdlr(ilm_struct *ilm_ptr)
{
#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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


void cam_profiling_get_append_req_hdlr(ilm_struct *ilm_ptr)
{
#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

#if defined(__MTK_TARGET__)
#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))

/* We need this app id, because in Cosmos MMI, all of the frame buffer from MED is allocated
   from ASM, so need to know the current app id. */
kal_uint16 CATS_AppId = 0;

extern kal_uint32 MainSensorId;
extern kal_uint8 IspPreviewFrameCount;

/***********************************************************************
 * FUNCTION
 *  CATSSaveFileDebug
 * DESCRIPTION
 *  Save the test pattern for debug or get the test pattern.
 * PARAMETERS
 *  void
 * RETURNS
 *  MM_ERROR_NONE means init OK, or else init failed.
 ***********************************************************************/
void CATSSaveFileDebug(kal_uint32 image_buff_address, kal_uint32 image_buff_size, WCHAR *file_name, kal_uint32 file_name_size)
{
    FS_HANDLE fp = -1;				/* Default, no file opened. */
    kal_uint32 len = 0;
    kal_uint32 jpeg_result = 0;
    kal_bool is_jpeg_saved = KAL_FALSE;

    WCHAR yuv_file_name[256] = {0};

    memcpy((kal_uint8*) yuv_file_name, (kal_uint8*) file_name, file_name_size);

    yuv_file_name[0] = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);

    fp = FS_Open(yuv_file_name, FS_CREATE | FS_READ_WRITE);

    if (fp < 0)
    {
        kal_prompt_trace(MOD_ENG, "!!!!Open file %s error = %x", yuv_file_name, fp);

        yuv_file_name[0] = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE);
        fp = FS_Open(yuv_file_name, FS_CREATE | FS_READ_WRITE);
    }

    if (fp >= 0)
    {
        jpeg_result = FS_Write(fp, (void *)image_buff_address, image_buff_size, &len);
	
        kal_prompt_trace(MOD_ENG, "Write file = %x, len=%d", jpeg_result, len);

        is_jpeg_saved = KAL_TRUE;
    }
    else
    {
        // Error handle.
        kal_prompt_trace(MOD_ENG, "!!!!Open file %s error = %x", yuv_file_name, fp);
    }

    FS_Close(fp);
}


/***********************************************************************
 * FUNCTION
 *  CATSFeatureCtrl
 * DESCRIPTION
 *  All of the function or variable of CATS(Camera Auto Test System) is start with CATS, and this
 *  function will init the cal, select the main/sub sensor, get the sensor id.
 * PARAMETERS
 *  void
 * RETURNS
 *  MM_ERROR_NONE means init OK, or else init failed.
 ***********************************************************************/
MM_ERROR_CODE_ENUM CATSFeatureGetSensorID(kal_uint32 *sensor_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MM_ERROR_CODE_ENUM ret = MM_ERROR_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(sensor_id != NULL);

    if (MainSensorId != 0xFFFFFFFF)
    {
        /* Because it is already get when open the cal, so return it directly. */
        *sensor_id = MainSensorId;
        return MM_ERROR_NONE;
    }
    else
    {
        return MM_ERROR_SENSOR_READ_ID_FAIL;
    }

    return ret;
}


/***********************************************************************
 * FUNCTION
 *  CATSFeatureCtrl
 * DESCRIPTION
 *  All of the function or variable of CATS(Camera Auto Test System) is start with CATS, and this
 *  function will init the cal, select the main/sub sensor, get the sensor id.
 * PARAMETERS
 *  void
 * RETURNS
 *  MM_ERROR_NONE means init OK, or else init failed.
 ***********************************************************************/
MM_ERROR_CODE_ENUM CATSFeatureGetPatternFormat(MM_IMAGE_FORMAT_ENUM *image_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MM_ERROR_CODE_ENUM ret = MM_ERROR_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(image_format != NULL);
    
#ifdef USE_UYVY422_BETWEEN_MDP_LCD
    *image_format = MM_IMAGE_FORMAT_PACKET_UYVY422;
#else
    *image_format = MM_IMAGE_FORMAT_RGB565;
#endif

    CATS_TRACE("GetPatternFormat: image_format=%d", *image_format);

    return ret;
}


/***********************************************************************
 * FUNCTION
 *  CATSFeatureCtrl
 * DESCRIPTION
 *  All of the function or variable of CATS(Camera Auto Test System) is start with CATS, and this
 *  function will init the cal, select the main/sub sensor, get the sensor id.
 * PARAMETERS
 *  void
 * RETURNS
 *  MM_ERROR_NONE means init OK, or else init failed.
 ***********************************************************************/
MM_ERROR_CODE_ENUM CATSFeatureGetTestPattern(cats_frame_buff_st *pattern_frame)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MM_ERROR_CODE_ENUM ret = MM_ERROR_NONE;
    CAL_SCENARIO_CTRL_STRUCT CalPreviewScenarioPara;
    CAL_FEATURE_CTRL_STRUCT CalInPara;
    
    CAL_CAMERA_PREVIEW_STRUCT CalPreviewPara;
    CAL_LCD_STRUCT CalLcdPara;
    CAL_ISP_PREVIEW_STRUCT CalIspPreviewPara;
    CAL_POSTPROC_STRUCT CalPostProcPara;
    CAL_MDP_PREVIEW_STRUCT CalMdpPreviewPara;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(pattern_frame != NULL);
    ASSERT(pattern_frame->frame_buffer != NULL);

    CATS_TRACE("test pattern window = %dx%d", pattern_frame->frame_width, pattern_frame->frame_height);

    cam_context_p->extmem_start_address = NULL;
    cam_context_p->extmem_size = 0;
    cam_context_p->binning_mode = 0;
    cam_context_p->app_id = CATS_AppId;

    /* It will not use the app frame buffer, so set ut as null directly. */
    cam_context_p->app_frame_buffer_p = NULL;
    cam_context_p->app_frame_buffer_size = 0;
    
    cam_context_p->frame_buffer_size = pattern_frame->frame_buffer_size;

    /* The user must prepare one buffer which with/height is frame_width/frame_height to 
                store the test pattern. */
    cam_context_p->frame_buffer1_p = pattern_frame->frame_buffer;
    CAM_PREVIEW_CHECK_IS_BUFFER_AVAILABLE(cam_context_p->frame_buffer1_p);
    cam_context_p->frame_buffer2_p = (kal_uint32) med_alloc_asm_mem(cam_context_p->app_id, cam_context_p->frame_buffer_size);
    CAM_PREVIEW_CHECK_IS_BUFFER_AVAILABLE(cam_context_p->frame_buffer2_p);
    cam_context_p->frame_buffer3_p = NULL;      /* Don't need use the tripple bubbfer for this hw verify. */

    cam_context_p->preview_offset_x = 0;
    cam_context_p->preview_offset_y = 0;
    cam_context_p->preview_width = pattern_frame->frame_width;
    cam_context_p->preview_height = pattern_frame->frame_height;

    cam_context_p->ui_rotate = 0;
    cam_context_p->included_angle = 0;
    cam_context_p->preview_rotate = 0;
    CATSFeatureGetPatternFormat(&(cam_context_p->image_data_format));

    CalMdpPreviewPara.LcdUpdateEnable = cam_context_p->lcd_update = KAL_FALSE;        
    CalMdpPreviewPara.DisplayImageWidth = cam_context_p->preview_width;
    CalMdpPreviewPara.DisplayImageHeight = cam_context_p->preview_height;
    CalMdpPreviewPara.FrameBuffAddr1 = cam_context_p->frame_buffer1_p;
    CalMdpPreviewPara.FrameBuffAddr2 = cam_context_p->frame_buffer2_p;
    CalMdpPreviewPara.FrameBuffAddr3 = NULL;    /* Don't need use the tripple bubbfer for this hw verify. */
    CalMdpPreviewPara.FrameBuffSize = cam_context_p->frame_buffer_size;

#ifdef MDP_SUPPORT_HW_OVERLAP
    CalMdpPreviewPara.OverlayEnable = cam_context_p->overlay_frame_mode = KAL_FALSE;
    CalMdpPreviewPara.OverlayPaletteAddr = cam_context_p->overlay_palette_addr = 0;
    CalMdpPreviewPara.OverlayPaletteSize = cam_context_p->overlay_palette_size = 0;
    CalMdpPreviewPara.OverlayColorDepth = cam_context_p->overlay_color_depth = 0;
    CalMdpPreviewPara.OverlayFrameSourceKey = cam_context_p->overlay_frame_source_key = 0;
    CalMdpPreviewPara.OverlayFrameWidth = cam_context_p->overlay_frame_width = 0;
    CalMdpPreviewPara.OverlayFrameHeight = cam_context_p->overlay_frame_height = 0;
    CalMdpPreviewPara.OverlayFrameBuffAddr = cam_context_p->overlay_frame_buffer_address = 0;
#else
    CalMdpPreviewPara.OverlayEnable = KAL_FALSE;
#endif

    CalMdpPreviewPara.ImageRotAngle = 0;
    CalMdpPreviewPara.ImageDataFormat = (MM_IMAGE_FORMAT_ENUM)cam_context_p->image_data_format;

    CalIspPreviewPara.ZoomStep = cam_context_p->zoom_step = 0;
    CalIspPreviewPara.ContrastLevel = cam_context_p->contrast_level = 1;
    CalIspPreviewPara.SaturationLevel = cam_context_p->saturation_level = 1;
    CalIspPreviewPara.SharpnessLevel = cam_context_p->sharpness_level = 1;
    CalIspPreviewPara.WbMode = cam_context_p->wb_mode = 0;
    CalIspPreviewPara.EvValue = cam_context_p->ev_value = 4;
    CalIspPreviewPara.BandingFreq = cam_context_p->banding_freq = 0;
    CalIspPreviewPara.ImageEffect = cam_context_p->image_effect = 0;
    CalIspPreviewPara.SceneMode = cam_context_p->scene_mode = 0;
    CalIspPreviewPara.AeMeteringMode = cam_context_p->ae_metering_mode = 0;
    CalIspPreviewPara.FlashMode = cam_context_p->flash_mode = 0;
    CalIspPreviewPara.AfOperationMode = cam_context_p->af_operation_mode = 1;
    CalIspPreviewPara.AfRange = cam_context_p->af_range = 0;

    CalLcdPara.WfcElementHandle = 0x12345678;
    CalLcdPara.WfcContextHandle = 0x12345678;
    CalLcdPara.WfcDeviceHandle = 0x12345678;

#if defined(__MED_CAM_FD_SUPPORT__)
    cam_context_p->fd_enable = KAL_FALSE;
    cam_context_p->sd_enable = KAL_FALSE;
#endif

    cam_context_p->extmem_size += CAL_PREVIEW_EXT_MEMORY_SIZE;
    if (cam_context_p->extmem_size)
    {
        cam_context_p->extmem_start_address = (kal_uint32) med_alloc_asm_mem_framebuffer(cam_context_p->app_id, cam_context_p->extmem_size);
        CAM_PREVIEW_CHECK_IS_BUFFER_AVAILABLE(cam_context_p->extmem_start_address);
    }

    CalPreviewPara.ExtmemStartAddress = cam_context_p->extmem_start_address;
    CalPreviewPara.ExtmemSize = cam_context_p->extmem_size;

    CalPreviewPara.pLcdPara = &CalLcdPara;
    CalPreviewPara.pMdpPara = &CalMdpPreviewPara;
    CalPreviewPara.pIspPara = &CalIspPreviewPara;
    CalPreviewPara.pPostProcPara = NULL;

    /* Make sensor start output the test pattern. */
    CalInPara.FeatureId = CAL_FEATURE_CAMERA_SENOSR_OUTPUT_TEST_PATTERN;
    CalInPara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
    CalInPara.FeatureSetValue = KAL_TRUE;
    ret = CalCtrl(CAL_FEATURE_CTRL, (void *) &CalInPara, NULL, 0, NULL);

    /* Start Camera Preview */
    CalPreviewScenarioPara.ScenarioId = CAL_SCENARIO_CAMERA_PREVIEW;
    CalPreviewScenarioPara.ScenarioCtrlCode = CAL_CTRL_CODE_START;
    CalPreviewScenarioPara.ScenarioCtrlParaLen = sizeof(CAL_CAMERA_PREVIEW_STRUCT);
    CalPreviewScenarioPara.pScenarioCtrlPara = &CalPreviewPara;

    ret = CalCtrl(CAL_SCENARIO_CTRL, (void *) &CalPreviewScenarioPara, NULL, 0, NULL);
    CATS_TRACE("Start Camera Preview ret=%d", ret);

    if (ret == MM_ERROR_NONE)
    {
        CAM_ENTER_STATE(CAM_PREVIEW);

        /* Wait to get stable test pattern frame buffer. */
    #ifdef __MTK_TARGET__
        while (IspPreviewFrameCount <= 10)      // Max wait 10 frames to get stable frame.
        {
            kal_sleep_task(5);
        }
    #else
        kal_sleep_task(200);        /* Modis, delay 200*4.615ms directly.  */
    #endif

        /* Stop Camera Preview */
        CalPreviewScenarioPara.ScenarioId=CAL_SCENARIO_CAMERA_PREVIEW;
        CalPreviewScenarioPara.ScenarioCtrlCode=CAL_CTRL_CODE_STOP;
        CalPreviewScenarioPara.ScenarioCtrlParaLen=0;
        CalPreviewScenarioPara.pScenarioCtrlPara=NULL;
        ret = CalCtrl(CAL_SCENARIO_CTRL, (void *) &CalPreviewScenarioPara, NULL, 0, NULL);
        CATS_TRACE("Stop Camera Preview ret=%d", ret);

        // It can use to debug the test pattern or get the test pattern.
        CATSSaveFileDebug(pattern_frame->frame_buffer, pattern_frame->frame_buffer_size, \
                    L"C:\\Pattern.yuv", sizeof(L"C:\\Pattern.yuv"));

        CAM_ENTER_STATE(CAM_READY);
    }
    else
    {
        CAM_ENTER_STATE(CAM_IDLE);
    }

    /* Make sensor Stop output the test pattern. */
    CalInPara.FeatureId = CAL_FEATURE_CAMERA_SENOSR_OUTPUT_TEST_PATTERN;
    CalInPara.CameraMode = CAL_CAMERA_MODE_CAMERA;
    CalInPara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
    CalInPara.FeatureSetValue = KAL_FALSE;
    ret = CalCtrl(CAL_FEATURE_CTRL, (void *) &CalInPara, NULL, 0, NULL);

    cam_free_working_buffer();
    cam_context_p->frame_buffer1_p = NULL;  /* This buffer will freed in the caller api. */

    return MM_ERROR_NONE;
}

/***********************************************************************
 * FUNCTION
 *  CATSFeatureCompareTestPattern
 * DESCRIPTION
 *  All of the function or variable of CATS(Camera Auto Test System) is start with CATS, and this
 *  function will init the cal, select the main/sub sensor, get the sensor id.
 * PARAMETERS
 *  void
 * RETURNS
 *  MM_ERROR_NONE means init OK, or else init failed.
 ***********************************************************************/
MM_ERROR_CODE_ENUM CATSFeatureCompareTestPattern(cats_frame_buff_st *pattern_frame, cats_compare_result_st *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MM_ERROR_CODE_ENUM ret = MM_ERROR_NONE;
    kal_uint8 *src_pattern = NULL;
    kal_uint8 *cmp_pattern = NULL;
    kal_uint32 cert_err_threshold = 0;
    kal_uint32 idx = 0;
    static kal_uint32 cats_compare_index = 0;
    CAL_FEATURE_CTRL_STRUCT CalInPara;
    CAL_FEATURE_CTRL_STRUCT CalOutPara;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT((pattern_frame != NULL) && (result != NULL));
    ASSERT(pattern_frame->frame_buffer != NULL);

    cert_err_threshold = pattern_frame->err_ratio_threshold;

    /* We just think if the error exceed 50%, it should be un-acceptable. */
    if (cert_err_threshold > 50)
    {
        cert_err_threshold = 50;
    }

    result->pattern_size = 0;
    result->err_pattern_cnt = 0;
    result->err_ratio = 0;

    CATS_TRACE("[Compared Start] size = %dx%d, ratio=%d", pattern_frame->frame_width, \
                pattern_frame->frame_height, pattern_frame->err_ratio_threshold);

    /* Get sensor test pattern. */
    CalInPara.FeatureId = CAL_FEATURE_CAMERA_GET_TEST_PATTERN;
    CalInPara.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
    ret = CalCtrl(CAL_FEATURE_CTRL, (void *) &CalInPara, (void*) &CalOutPara, sizeof(CalOutPara), NULL);
    ASSERT (ret == MM_ERROR_NONE);
    src_pattern = (kal_uint8 *) CalOutPara.FeatureCurrentValue;

    cmp_pattern = (kal_uint8 *)pattern_frame->frame_buffer;
    /* Multiple 2 is because the buffer format is YUV422, one pixels occupy two bytes. */
    result->pattern_size = pattern_frame->frame_width * pattern_frame->frame_height * 2;
    
    while (idx < result->pattern_size)
    {
        if ((*src_pattern) != (*cmp_pattern))
        {
            result->err_pattern_cnt++;
        }

        src_pattern++;
        cmp_pattern++;
        idx++;
    }

    /* Error Ratio is represent with percent, and 10 means 10%, range is 0% to 100% */
    result->err_ratio = 100 * result->err_pattern_cnt / result->pattern_size;

    CATS_TRACE("[Compared Done] err_ratio=%d, error_pattern_cnt=%d, pattern_size=%d", \
                    result->err_ratio, result->err_pattern_cnt, result->pattern_size);

    cats_compare_index++;
    if (result->err_ratio > cert_err_threshold)
    {
        CATSSaveFileDebug(pattern_frame->frame_buffer, pattern_frame->frame_buffer_size, \
                    L"C:\\CATS_Fail.yuv", sizeof(L"C:\\CATS_Fail.yuv"));
        
        ret = MM_ERROR_SENSOR_FAIL;
    }

    return ret;
}


/***********************************************************************
 * FUNCTION
 *  CATSFeatureCtrl
 * DESCRIPTION
 *  All of the function or variable of CATS(Camera Auto Test System) is start with CATS, and this
 *  function will init the cal, select the main/sub sensor, get the sensor id.
 * PARAMETERS
 *  void
 * RETURNS
 *  MM_ERROR_NONE means init OK, or else init failed.
 ***********************************************************************/
MM_ERROR_CODE_ENUM CATSFeatureStressTest()
{
    return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
}

/***********************************************************************
 * FUNCTION
 *  CATSFeatureCtrl
 * DESCRIPTION
 *  All of the function or variable of CATS(Camera Auto Test System) is start with CATS, and this
 *  function will init the cal, select the main/sub sensor, get the sensor id.
 * PARAMETERS
 *  void
 * RETURNS
 *  MM_ERROR_NONE means init OK, or else init failed.
 ***********************************************************************/
MM_ERROR_CODE_ENUM CATSFeatureCameraPreview(cats_frame_buff_st *pattern_frame)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MM_ERROR_CODE_ENUM ret = MM_ERROR_NONE;
    CAL_SCENARIO_CTRL_STRUCT CalPreviewScenarioPara;
    CAL_FEATURE_CTRL_STRUCT CalInPara;
    
    CAL_CAMERA_PREVIEW_STRUCT CalPreviewPara;
    CAL_LCD_STRUCT CalLcdPara;
    CAL_ISP_PREVIEW_STRUCT CalIspPreviewPara;
    CAL_POSTPROC_STRUCT CalPostProcPara;
    CAL_MDP_PREVIEW_STRUCT CalMdpPreviewPara;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(pattern_frame != NULL);
    ASSERT(pattern_frame->frame_buffer != NULL);

    CATS_TRACE("test pattern window = %dx%d", pattern_frame->frame_width, pattern_frame->frame_height);

    if (!((160 == pattern_frame->frame_width) && (120 == pattern_frame->frame_height))
        && !((320 == pattern_frame->frame_width) && (240 == pattern_frame->frame_height))
        && !((640 == pattern_frame->frame_width) && (480 == pattern_frame->frame_height)))
    {
        /* Currently we only can support 160x120, 320x240 & 640x480 test pattern size. */
        return MM_ERROR_INVALID_PARAMETER;
    }

    cam_context_p->extmem_start_address = NULL;
    cam_context_p->extmem_size = 0;
    cam_context_p->binning_mode = 0;
    cam_context_p->app_id = CATS_AppId;

    /* It will not use the app frame buffer, so set ut as null directly. */
    cam_context_p->app_frame_buffer_p = NULL;
    cam_context_p->app_frame_buffer_size = 0;
    
    cam_context_p->frame_buffer_size = pattern_frame->frame_buffer_size;

    /* The user must prepare one buffer which with/height is frame_width/frame_height to 
                store the test pattern. */
    cam_context_p->frame_buffer1_p = pattern_frame->frame_buffer;
    CAM_PREVIEW_CHECK_IS_BUFFER_AVAILABLE(cam_context_p->frame_buffer1_p);
    cam_context_p->frame_buffer2_p = (kal_uint32) med_alloc_asm_mem(cam_context_p->app_id, cam_context_p->frame_buffer_size);
    CAM_PREVIEW_CHECK_IS_BUFFER_AVAILABLE(cam_context_p->frame_buffer2_p);
    cam_context_p->frame_buffer3_p = NULL;      /* Don't need use the tripple bubbfer for this hw verify. */

    cam_context_p->preview_offset_x = 0;
    cam_context_p->preview_offset_y = 0;
    cam_context_p->preview_width = pattern_frame->frame_width;
    cam_context_p->preview_height = pattern_frame->frame_height;

    cam_context_p->ui_rotate = 0;
    cam_context_p->included_angle = 0;
    cam_context_p->preview_rotate = 0;
    CATSFeatureGetPatternFormat(&(cam_context_p->image_data_format));

    CalMdpPreviewPara.LcdUpdateEnable = cam_context_p->lcd_update = KAL_FALSE;        
    CalMdpPreviewPara.DisplayImageWidth = cam_context_p->preview_width;
    CalMdpPreviewPara.DisplayImageHeight = cam_context_p->preview_height;
    CalMdpPreviewPara.FrameBuffAddr1 = cam_context_p->frame_buffer1_p;
    CalMdpPreviewPara.FrameBuffAddr2 = cam_context_p->frame_buffer2_p;
    CalMdpPreviewPara.FrameBuffAddr3 = NULL;    /* Don't need use the tripple bubbfer for this hw verify. */
    CalMdpPreviewPara.FrameBuffSize = cam_context_p->frame_buffer_size;

#ifdef MDP_SUPPORT_HW_OVERLAP
    CalMdpPreviewPara.OverlayEnable = cam_context_p->overlay_frame_mode = KAL_FALSE;
    CalMdpPreviewPara.OverlayPaletteAddr = cam_context_p->overlay_palette_addr = 0;
    CalMdpPreviewPara.OverlayPaletteSize = cam_context_p->overlay_palette_size = 0;
    CalMdpPreviewPara.OverlayColorDepth = cam_context_p->overlay_color_depth = 0;
    CalMdpPreviewPara.OverlayFrameSourceKey = cam_context_p->overlay_frame_source_key = 0;
    CalMdpPreviewPara.OverlayFrameWidth = cam_context_p->overlay_frame_width = 0;
    CalMdpPreviewPara.OverlayFrameHeight = cam_context_p->overlay_frame_height = 0;
    CalMdpPreviewPara.OverlayFrameBuffAddr = cam_context_p->overlay_frame_buffer_address = 0;
#else
    CalMdpPreviewPara.OverlayEnable = KAL_FALSE;
#endif

    CalMdpPreviewPara.ImageRotAngle = 0;
    CalMdpPreviewPara.ImageDataFormat = (MM_IMAGE_FORMAT_ENUM)cam_context_p->image_data_format;

    CalIspPreviewPara.ZoomStep = cam_context_p->zoom_step = 0;
    CalIspPreviewPara.ContrastLevel = cam_context_p->contrast_level = 1;
    CalIspPreviewPara.SaturationLevel = cam_context_p->saturation_level = 1;
    CalIspPreviewPara.SharpnessLevel = cam_context_p->sharpness_level = 1;
    CalIspPreviewPara.WbMode = cam_context_p->wb_mode = 0;
    CalIspPreviewPara.EvValue = cam_context_p->ev_value = 4;
    CalIspPreviewPara.BandingFreq = cam_context_p->banding_freq = 0;
    CalIspPreviewPara.ImageEffect = cam_context_p->image_effect = 0;
    CalIspPreviewPara.SceneMode = cam_context_p->scene_mode = 0;
    CalIspPreviewPara.AeMeteringMode = cam_context_p->ae_metering_mode = 0;
    CalIspPreviewPara.FlashMode = cam_context_p->flash_mode = 0;
    CalIspPreviewPara.AfOperationMode = cam_context_p->af_operation_mode = 1;
    CalIspPreviewPara.AfRange = cam_context_p->af_range = 0;

    CalLcdPara.WfcElementHandle = 0x12345678;
    CalLcdPara.WfcContextHandle = 0x12345678;
    CalLcdPara.WfcDeviceHandle = 0x12345678;

#if defined(__MED_CAM_FD_SUPPORT__)
    cam_context_p->fd_enable = KAL_FALSE;
    cam_context_p->sd_enable = KAL_FALSE;
#endif

    cam_context_p->extmem_size += CAL_PREVIEW_EXT_MEMORY_SIZE;
    if (cam_context_p->extmem_size)
    {
        cam_context_p->extmem_start_address = (kal_uint32) med_alloc_asm_mem_framebuffer(cam_context_p->app_id, cam_context_p->extmem_size);
        CAM_PREVIEW_CHECK_IS_BUFFER_AVAILABLE(cam_context_p->extmem_start_address);
    }

    CalPreviewPara.ExtmemStartAddress = cam_context_p->extmem_start_address;
    CalPreviewPara.ExtmemSize = cam_context_p->extmem_size;

    CalPreviewPara.pLcdPara = &CalLcdPara;
    CalPreviewPara.pMdpPara = &CalMdpPreviewPara;
    CalPreviewPara.pIspPara = &CalIspPreviewPara;
    CalPreviewPara.pPostProcPara = NULL;

    /* Start Camera Preview */
    CalPreviewScenarioPara.ScenarioId = CAL_SCENARIO_CAMERA_PREVIEW;
    CalPreviewScenarioPara.ScenarioCtrlCode = CAL_CTRL_CODE_START;
    CalPreviewScenarioPara.ScenarioCtrlParaLen = sizeof(CAL_CAMERA_PREVIEW_STRUCT);
    CalPreviewScenarioPara.pScenarioCtrlPara = &CalPreviewPara;

    ret = CalCtrl(CAL_SCENARIO_CTRL, (void *) &CalPreviewScenarioPara, NULL, 0, NULL);
    CATS_TRACE("Start Camera Preview ret=%d", ret);

    if (ret == MM_ERROR_NONE)
    {
        CAM_ENTER_STATE(CAM_PREVIEW);

        /* Wait to get stable test pattern frame buffer. */
    #ifdef __MTK_TARGET__
        while (IspPreviewFrameCount <= 10)      // Max wait 10 frames to get stable frame.
        {
            kal_sleep_task(5);
        }
    #else
        kal_sleep_task(200);        /* Modis, delay 200*4.615ms directly.  */
    #endif

        // It can use to debug the test pattern or get the test pattern.
        CATSSaveFileDebug(pattern_frame->frame_buffer, pattern_frame->frame_buffer_size, \
                    L"C:\\Cam_Preview_Buf.yuv", sizeof(L"C:\\Cam_Preview_Buf.yuv"));
    }
    else
    {
        CAM_ENTER_STATE(CAM_IDLE);
    }

    cam_free_working_buffer();
    cam_context_p->frame_buffer1_p = NULL;  /* This buffer will freed in the caller api. */

    return MM_ERROR_NONE;
}


/***********************************************************************
 * FUNCTION
 *  CATSFeatureCameraCapture
 * DESCRIPTION
 *  Used to capture one image for the MTF, image quality test with AT command.
 * PARAMETERS
 *  void
 * RETURNS
 *  MM_ERROR_NONE means init OK, or else init failed.
 ***********************************************************************/
MM_ERROR_CODE_ENUM CATSFeatureCameraCapture(cats_capture_image_st *pParaIn, cats_capture_image_st *pParaOut)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_SCENARIO_CTRL_STRUCT CalScenarioPara;
    kal_uint32 buffer_address = 0;
    kal_uint32 buffer_size = 0;
    kal_int32 ret;
    kal_bool  is_first_capture = KAL_FALSE;
    kal_uint8 before_captured_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->app_id = CATS_AppId;

    if (CAM_IN_STATE(CAM_READY) || CAM_IN_STATE(CAM_PREVIEW))
    {
        CAM_FREE_CAPTURE_BUFFER();
        CAM_FREE_HDR_BUFFER();

        /* stop prevew before capture */ 
        if(CAM_IN_STATE(CAM_PREVIEW))
        {
            CalScenarioPara.ScenarioId=CAL_SCENARIO_CAMERA_PREVIEW;
            CalScenarioPara.ScenarioCtrlCode=CAL_CTRL_CODE_STOP;
            CalScenarioPara.ScenarioCtrlParaLen=0;
            CalScenarioPara.pScenarioCtrlPara=NULL;
            CalCtrl(CAL_SCENARIO_CTRL, (void *) &CalScenarioPara, NULL, 0, NULL);

            CAM_ENTER_STATE(CAM_READY);

            is_first_capture = KAL_TRUE;
        }
#if defined(DRV_MDP_LIMIT_CACHE_LINE_32BYTE_ALIGNMENT) && defined(__MTK_TARGET__)  // for 35/53 only
        if (cam_context_p->app_frame_buffer_p)
        {
            memcpy(
                (kal_uint8*) cam_context_p->app_frame_buffer_p,
                (kal_uint8*) cam_context_p->frame_buffer2_p,
                cam_context_p->app_frame_buffer_size);
        }
#endif /* defined(DRV_MDP_LIMIT_CACHE_LINE_32BYTE_ALIGNMENT) && defined(__MTK_TARGET__) */
    
        /* release preview related memory */
        cam_free_working_buffer();

        cam_context_p->ui_rotate = MM_IMAGE_ROTATE_0;
        cam_context_p->quickview_lcd_rotate = MM_IMAGE_ROTATE_0;
        cam_context_p->media_mode = MED_MODE_BUFFER;
        cam_context_p->source_device = CAM_SRC_ISP;
        cam_context_p->snapshot_number = 0;
        cam_context_p->capture_mode = pParaIn->capture_mode;    

        cam_context_p->continue_capture = KAL_FALSE;
        cam_context_p->captured_number = 0;
        cam_context_p->expo_bracket_level = 0;

        cam_context_p->capture_rotate = MM_IMAGE_ROTATE_0;

        cam_context_p->image_width = pParaIn->image_width;
        cam_context_p->image_height = pParaIn->image_height;
        cam_context_p->image_resolution = pParaIn->image_resolution;

#ifdef MDP_SUPPORT_HW_OVERLAP
        /* Disable the overlay frame mode. */
        cam_context_p->overlay_frame_mode = KAL_FALSE;
        cam_context_p->overlay_palette_addr = NULL;
        cam_context_p->overlay_palette_size = 0;
        cam_context_p->overlay_color_depth = 0;
        cam_context_p->overlay_frame_source_key = 0;
        cam_context_p->overlay_frame_width = 0;
        cam_context_p->overlay_frame_height = 0;
        cam_context_p->overlay_frame_buffer_address = NULL;
#endif

        /* Disable the quick view image, don't support quick view now.. */
        cam_context_p->quickview_output = KAL_FALSE;
        cam_context_p->quickview_output_width = 0;
        cam_context_p->quickview_output_height = 0;
        cam_context_p->quickview_output_buffer_address = NULL;
        cam_context_p->quickview_output_buffer_size = 0;

        cam_context_p->snapshot_number = 1;
        cam_context_p->expo_bracket_level = 0;

        cam_context_p->image_quality = pParaIn->image_quality;
        cam_context_p->jpeg_file_info_p = NULL;
        cam_context_p->capture_buffer_pp = NULL;
        cam_context_p->capture_buffer_size_p = NULL;
        cam_context_p->is_waiting_save = KAL_FALSE;
#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)        
        cam_context_p->stitch_direction = 0;
#endif
        cam_context_p->file_name_p = NULL;

        cam_context_p->capture_buffer_p = pParaIn->capture_buffer_p;
        cam_context_p->capture_buffer_size = pParaIn->capture_buffer_size;
        CAM_CAPTURE_CHECK_IS_BUFFER_AVAILABLE(cam_context_p->capture_buffer_p);
            
        if (cam_context_p->media_mode == MED_MODE_BUFFER)
        {
            if (cam_context_p->continue_capture == KAL_FALSE)
                cam_context_p->multishot_info = MULTISHOT_FALSE;
            else if (cam_context_p->continue_capture == KAL_TRUE && is_first_capture)
                cam_context_p->multishot_info = MULTISHOT_FIRST;
            else if (cam_context_p->continue_capture == KAL_TRUE)
                cam_context_p->multishot_info = MULTISHOT_NOT_FIRST;

            buffer_address = cam_context_p->capture_buffer_p;
            buffer_size = cam_context_p->capture_buffer_size;
        }

        cam_context_p->jpeg_buffer_address = cam_context_p->capture_buffer_p;
        cam_context_p->jpeg_buffer_size = cam_context_p->capture_buffer_size;
            
        cam_context_p->extmem_size = MAX_CAM_CAPTURE_ISP_WORK_BUF_SIZE;
        if (cam_context_p->extmem_size)
        {
            cam_context_p->extmem_start_address = (kal_uint32) med_alloc_asm_mem_framebuffer(cam_context_p->app_id, cam_context_p->extmem_size);
            CAM_CAPTURE_CHECK_IS_BUFFER_AVAILABLE(cam_context_p->extmem_start_address);
        }

        {
            cam_context_p->thumbnail_buffer_size = MAX_CAM_CAPTURE_THUMBNAIL_BUF_SIZE;
            cam_context_p->thumbnail_buffer_address = (kal_uint32) med_alloc_asm_mem_framebuffer(cam_context_p->app_id, cam_context_p->thumbnail_buffer_size);
            CAM_CAPTURE_CHECK_IS_BUFFER_AVAILABLE(cam_context_p->thumbnail_buffer_address);            
        }

        before_captured_num = cam_context_p->captured_number;
        
        ret = cam_capture_still_image_start(buffer_address, buffer_size);

        /* Wait to the capture jpeg function is complement. */
        while (before_captured_num == cam_context_p->captured_number)
        {
            kal_sleep_task(5);
        }

        CATS_TRACE("Capture Done ret=%d, jpeg_image_address=%x, jpeg_image_size=%d", \
                        ret, cam_context_p->jpeg_image_address, cam_context_p->jpeg_image_size);

        // It can use to debug the captured jpeg.
        CATSSaveFileDebug(cam_context_p->jpeg_image_address, cam_context_p->jpeg_image_size, \
                    L"C:\\Captured_JPEG.jpg", sizeof(L"C:\\Captured_JPEG.jpg"));

        /* Provide the final jpeg image buffer address & jpeg file size to caller. */
        pParaOut->jpeg_image_address = cam_context_p->jpeg_image_address;
        pParaOut->jpeg_image_size = cam_context_p->jpeg_image_size;

        cam_context_p->capture_buffer_p = NULL;     /* This memory is freed by caller. */
        cam_context_p->capture_buffer_size = 0;
            
        if (ret != MM_ERROR_NONE)
        {
            CAM_ENTER_STATE(CAM_READY);
            cam_free_working_buffer();  /* Free the external memory & thumbnail memory. */
            
            return MM_ERROR_CAL_INVALID_CTRL_TYPE;
        }
        /* If capture OK, then it will free buffer in function cam_capture_event_ind_hdlr() */

        return MM_ERROR_NONE;
    }
    else
    {
        return MM_ERROR_CAL_INVALID_STATE;
    }
}


/***********************************************************************
 * FUNCTION
 *  CATSInit
 * DESCRIPTION
 *  All of the function or variable of CATS(Camera Auto Test System) is start with CATS, and this
 *  function will init the cal, select the main/sub sensor, get the sensor id.
 * PARAMETERS
 *  void
 * RETURNS
 *  MM_ERROR_NONE means init OK, or else init failed.
 ***********************************************************************/
MM_ERROR_CODE_ENUM CATSInit(kal_uint16 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MM_ERROR_CODE_ENUM ret = MM_ERROR_NONE;
    CAL_FEATURE_CTRL_STRUCT CalInPara;

#if defined(__MM_DCM_SUPPORT__)
    if (KAL_FALSE == DCM_Isloaded(DYNAMIC_CODE_COMPRESS_CAMMED))
        DCM_Load(DYNAMIC_CODE_COMPRESS_CAMMED, NULL, NULL);
    if (KAL_FALSE == DCM_Isloaded(DYNAMIC_CODE_COMPRESS_CAMCAL))
        DCM_Load(DYNAMIC_CODE_COMPRESS_CAMCAL, NULL, NULL);
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CATS_AppId = app_id;
    
    CAM_ENTER_STATE(CAM_IDLE);
    
    CalInit();

    CalInPara.FeatureId = CAL_FEATURE_CAMERA_SOURCE_SELECT;     /* Select main or sub sensor. */
    CalInPara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
    CalInPara.FeatureSetValue = CAL_CAMERA_SOURCE_MAIN;         /* Default set as Main sensor. */
    CalCtrl(CAL_FEATURE_CTRL, (void*)&CalInPara, NULL, 0, NULL);

    MainSensorId = 0xFFFFFFFF;
    ret = CalOpen(cam_cal_callback);
    CATS_TRACE("===================== CalOpened ret=%d, Sensor ID=%x =====================", ret, MainSensorId);

    CAM_ENTER_STATE(CAM_READY);

    return ret;
}

/***********************************************************************
 * FUNCTION
 *  CATSFeatureCtrl
 * DESCRIPTION
 *  All of the function or variable of CATS(Camera Auto Test System) is start with CATS, and this
 *  function will init the cal, select the main/sub sensor, get the sensor id.
 * PARAMETERS
 *  void
 * RETURNS
 *  MM_ERROR_NONE means init OK, or else init failed.
 ***********************************************************************/
MM_ERROR_CODE_ENUM CATSFeatureCtrl(
                        CATS_FEATURE_ENUM Feature,
                        void *pParaIn,
                        void *pParaOut)
{
    MM_ERROR_CODE_ENUM ret = MM_ERROR_NONE;

    CATS_TRACE("FeatureCtrl In: Feature=%d", Feature);
    
    switch (Feature)
    {
        case CATS_FEATURE_GET_SENSOR_ID:                        /* Get Sensor ID */
            ret = CATSFeatureGetSensorID((kal_uint32 *)pParaOut);
            break;
        case CATS_FEATURE_GET_PATTERN_FORMAT:                   /* Get Pattern Format */
            ret = CATSFeatureGetPatternFormat((MM_IMAGE_FORMAT_ENUM *)pParaOut);
            break;
        case CATS_FEATURE_GET_TEST_PATTERN:                     /* Get Pattern Buffer */
            ret = CATSFeatureGetTestPattern((cats_frame_buff_st *)pParaIn);
            break;
        case CATS_FEATURE_COMPARE_TEST_PATTERN:                 /* Compare the test pattern buffer. */
            ret = CATSFeatureCompareTestPattern((cats_frame_buff_st *)pParaIn, (cats_compare_result_st *)pParaOut);
            break;
        case CATS_FEATURE_STESS_TEST:                           /* Do Stress Test */
            //ret = CATSFeatureStressTest();
            ret = MM_ERROR_CAL_INVALID_CTRL_TYPE;
            break;
        case CATS_FEATURE_CAMERA_PREVIEW:
            //ret = CATSFeatureCameraPreview((cats_frame_buff_st *)pParaIn);
            ret = MM_ERROR_CAL_INVALID_CTRL_TYPE;
            break;
        case CATS_FEATURE_CAMERA_CAPTURE:
            //ret = CATSFeatureCameraCapture((cats_capture_image_st *)pParaIn, (cats_capture_image_st *)pParaOut);
            ret = MM_ERROR_CAL_INVALID_CTRL_TYPE;
            break;
        default:
            ret = MM_ERROR_CAL_INVALID_CTRL_TYPE;
            break;
    }

    CATS_TRACE("FeatureCtrl Out: Feature=%d, ret=%d", Feature, ret);
    
    return ret;
}


/***********************************************************************
 * FUNCTION
 *  CATSDeinit
 * DESCRIPTION
 *  Do the opposite operation of init.
 * PARAMETERS
 *  void
 * RETURNS
 *  MM_ERROR_NONE means de-init OK, or else init failed.
 ***********************************************************************/
MM_ERROR_CODE_ENUM CATSDeinit()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MM_ERROR_CODE_ENUM ret = MM_ERROR_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = CalClose();
    CATS_TRACE("===================== CalClosed ret=%d =====================", ret);

    MainSensorId = 0xFFFFFFFF;

    ret = CalDeinit();

    CAM_ENTER_STATE(CAM_IDLE);

#if defined(__MM_DCM_SUPPORT__)
    DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMCAL);
    DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMMED);
#endif

    return ret;
}
#endif  /* #if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__)) */
#endif  /* #if defined(__MTK_TARGET__) */


#else
#error "no such combination"
#endif



#endif /* __MED_CAM_MOD__ */

#endif /* MED_NOT_PRESENT */

