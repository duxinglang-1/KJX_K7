/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vfx_config.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Venus UI Config Settings
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
 
#ifndef __VFX_CONFIG_H__
#define __VFX_CONFIG_H__

#ifdef __cplusplus
extern "C"
{
#endif

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For DPI
#include "lcd_sw_inc.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/* 
 * VfxWString::format() can output the max number of wide-characters.
 * (include terminal character) 
 */
#define VFX_WSTRING_FORMAT_MAX_LEN      128

/* To enable debug trace output */
#define VFX_TRACE_ENABLE

/* To enable memory debugging log output. */
//#define VFX_MEM_LOG_ENABLE

/* To enable vfx heap profiling  */
//#define __VFX_HEAP_PROFILE__

/* The memory debugging log output full path file name. */
#define VFX_MEM_LOG_FILE_NAME           "T:\\venus.log"

/* Enable testbed for developping Venus UI Engine. */
#if defined(VFX_RT_TEST)
#define __AFX_RT_TEST__
#endif


#ifdef __MTK_TARGET__
    /* Force disable memory log (not supported on target) */
    #undef VFX_TRACE_ENABLE
    #undef VFX_MEM_LOG_ENABLE
#endif


/*
 * SWLA Switch
 */
#if defined(__MTK_TARGET__) && !defined(VFX_CFG_SOFTWARE_LA)
//#define VFX_CFG_SOFTWARE_LA
#endif

#if defined(__MTK_TARGET__) && defined(__VENUS_SWLA_DBG_ON__)
#undef VFX_CFG_SOFTWARE_LA
#define VFX_CFG_SOFTWARE_LA
#endif


/* 
 * Pen settings
 */

/* Sampling period(millisecond) config for Event-based pen */
#define VFX_SYS_PEN_SAMPLE_MSEC         30


/*
 * Pen move config for both Event-based and Stroke-Based.
 *
 * NOTE: Long tap offset are doubled.
 */
#define VFX_SYS_PEN_SKIP_MOVE_OFFSET    2

/* Fuzzy touch switch */
#if (defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_FTE_SUPPORT__)) && defined(__MTK_TARGET__)
#define VFX_CFG_PEN_FUZZY_TOUCH
#endif

#if defined(VFX_CFG_PEN_FUZZY_TOUCH) && !defined(__TOUCH_PANEL_CAPACITY__)
/* Common finger touch range for RTP (0.137 inch) */
#define VFX_TOUCH_FINGER_MAX_WIDTH      (UI_DEVICE_WIDTH / 16)
#define VFX_TOUCH_FINGER_WIDTH          ((137 * LCM_DPI / 1000) > VFX_TOUCH_FINGER_MAX_WIDTH ? VFX_TOUCH_FINGER_MAX_WIDTH : (137 * LCM_DPI / 1000))
#elif defined(VFX_CFG_PEN_FUZZY_TOUCH)
/* Common finger touch range for CTP (0.137 inch) */
#define VFX_TOUCH_FINGER_MAX_WIDTH      (UI_DEVICE_WIDTH / 16)
#define VFX_TOUCH_FINGER_WIDTH          ((137 * LCM_DPI / 1000) > VFX_TOUCH_FINGER_MAX_WIDTH ? VFX_TOUCH_FINGER_MAX_WIDTH : (137 * LCM_DPI / 1000))
#else
#define VFX_TOUCH_FINGER_WIDTH          0
#endif

#if defined(LIBRA35_DEMO_BB)
/* Need a larger number if the touch panel has larger noise */
#define VFX_SYS_PEN_SKIP_LONGTAP_OFFSET 14
#elif defined(VFX_CFG_PEN_FUZZY_TOUCH)
#define VFX_SYS_PEN_SKIP_LONGTAP_OFFSET (VFX_TOUCH_FINGER_WIDTH / 2)
#else
/* Default value 0 means use VFX_SYS_PEN_SKIP_MOVE_OFFSET */
#define VFX_SYS_PEN_SKIP_LONGTAP_OFFSET 0
#endif

/* Screen rotate effect setting */
#if defined(__LOW_COST_SUPPORT_COMMON__)
#define VFX_CFG_SCREEN_ROTATE_DEFAULT_EFFECT vfxScreenRotateRotateOnly
#else
#define VFX_CFG_SCREEN_ROTATE_DEFAULT_EFFECT vfxScreenRotateMorph
#endif

#ifdef __cplusplus
} /* extern "C"*/
#endif 

#endif /* __VFX_DATATYPE_H__ */

