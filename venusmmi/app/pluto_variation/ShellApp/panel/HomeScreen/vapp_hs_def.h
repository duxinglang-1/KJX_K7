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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_hs_def.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the definition of Venus applications
 *  MMI.
 *
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
#ifndef __VAPP_HS_DEF_H__
#define __VAPP_HS_DEF_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "MMI_features.h"


/****************************************************************************
 * Feature Definition
 ****************************************************************************/

/* 
 * If the shell does not use multiple pages, we turn on the home screen multiple
 * desktop feature.
 */
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__)
#define VAPP_HS_CFG_MULTI_DESKTOP
#endif

/*
 * If the shell only has one page, shell will not use its own shortcut panel.
 * In this case, we turn on the home screen shortcut panel.
 */
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__)
#define VAPP_HS_CFG_SHORTCUT_PANEL
#endif


/**********************************************************************
 * Definitions
 **********************************************************************/

#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) || defined(__MMI_MAINLCD_320X240__)
/* Maximum supported image width of photo widget */
#define VAPP_WIDGET_PHOTO_MAX_WIDTH     (100)
/* Maximum supported image height of photo widget */
#define VAPP_WIDGET_PHOTO_MAX_HEIGHT    (100)
#elif defined(__MMI_MAINLCD_320X480__)
/* Maximum supported image width of photo widget */
#define VAPP_WIDGET_PHOTO_MAX_WIDTH     (148)
/* Maximum supported image height of photo widget */
#define VAPP_WIDGET_PHOTO_MAX_HEIGHT    (148)
#else
/* Maximum supported image width of photo widget */
#define VAPP_WIDGET_PHOTO_MAX_WIDTH     (113)
/* Maximum supported image height of photo widget */
#define VAPP_WIDGET_PHOTO_MAX_HEIGHT    (113)
#endif /* defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */

/* Minimum supported image width of photo widget */
#define VAPP_WIDGET_PHOTO_MIN_WIDTH     (40)
/* Minimum supported image height of photo widget */
#define VAPP_WIDGET_PHOTO_MIN_HEIGHT    (40)

/* Audio player widget state - Init */
#define VAPP_WIDGET_AUDPLAYER_STATE_INIT    (0)
/* Audio player widget state - Play */
#define VAPP_WIDGET_AUDPLAYER_STATE_PLAY    (1)
/* Audio player widget state - Process */
#define VAPP_WIDGET_AUDPLAYER_STATE_PROCESS (2)

/* FM radio widget state - Init */
#define VAPP_WIDGET_FMR_STATE_INIT          (0)
/* FM radio widget state - Ready */
#define VAPP_WIDGET_FMR_STATE_READY         (1)
/* FM radio widget state - Play */
#define VAPP_WIDGET_FMR_STATE_PLAY          (2)
/* FM radio widget state - Play without list */
#define VAPP_WIDGET_FMR_STATE_PLAY_NO_LIST  (3)
/* FM radio widget state - Searching */
#define VAPP_WIDGET_FMR_STATE_SEARCHING     (4)

/* Shortcut max number */
#define VAPP_HS_SHORTCUT_MAX_NUM            (32)

/* Widget max number */
#define VAPP_HS_WIDGET_MAX_NUM              (32)

/* Widget pen event enumeration */
typedef enum
{
    VAPP_HS_WIDGET_PEN_EVENT_DOWN,      /* Pen down */
    VAPP_HS_WIDGET_PEN_EVENT_UP,        /* Pen up */
    VAPP_HS_WIDGET_PEN_EVENT_CANCEL     /* Pen cancel */    
} VappHsWidgetPenTypeEnum;

/* Widget button type enumeration */
typedef enum
{
    VAPP_HS_WIDGET_BUTTON_PLAY,         /* Play button */
    VAPP_HS_WIDGET_BUTTON_STOP,         /* Stop button */
    VAPP_HS_WIDGET_BUTTON_PAUSE,        /* Pause button */
    VAPP_HS_WIDGET_BUTTON_PREV,         /* Prev button */
    VAPP_HS_WIDGET_BUTTON_NEXT          /* Next button */
} VappHsWidgetButtonTypeEnum;

/* Audio player info enumeration */
typedef enum
{
    VAPP_HS_WIDGET_AUDPLAYER_INFO_STATE,        /* State */
    VAPP_HS_WIDGET_AUDPLAYER_INFO_TITLE,        /* Title */
    VAPP_HS_WIDGET_AUDPLAYER_INFO_DURATION,     /* Duration */
    VAPP_HS_WIDGET_AUDPLAYER_INFO_CURR_TIME,     /* Current time */
    VAPP_HS_WIDGET_AUDPLAYER_INFO_PAUSE_DISABLE
} VappHsWidgetAudplayerGetInfoEnum;

/* Audio player callback type enumeration */
typedef enum
{
    VAPP_HS_WIDGET_AUDPLAYER_STATUS_CHANGE,     /* Status change */
    VAPP_HS_WIDGET_AUDPLAYER_MEDIA_CHANGE       /* Media change */
} VappHsWidgetAudplayerCallbackTypeEnum;

/* FM radio info enumeration */
typedef enum
{
    VAPP_HS_WIDGET_FMR_INFO_STATE,      /* State */
    VAPP_HS_WIDGET_FMR_INFO_CH_TITLE,   /* Title */
    VAPP_HS_WIDGET_FMR_INFO_CH_NUM      /* Channel number */
} VappHsWidgetFmrGetInfoEnum;

/* Shortcut type enumeration */
typedef enum
{
    // Device shortcut
    VAPP_HS_SHORTCUT_TYPE_DEVICE,
        
#ifdef __MRE_AM__
    // VRE shortcut
    VAPP_HS_SHORTCUT_TYPE_VAM,
#endif

    VAPP_HS_SHORTCUT_TYPE_TOTAL,

    VAPP_HS_SHORTCUT_TYPE_INVALID
} VappHsShortcutTypeEnum;

/* widget type enumeration */
typedef enum
{
    // Device widget
    VAPP_HS_WIDGET_TYPE_DEVICE,

#if defined(__MMI_GADGET_SUPPORT__)
    // Google gadget
    VAPP_HS_WIDGET_TYPE_GADGET,
#endif

    VAPP_HS_WIDGET_TYPE_TOTAL,

    VAPP_HS_WIDGET_TYPE_INVALID
} VappHsWidgetTypeEnum;

#ifdef __cplusplus
}   /* extern "C" */
#endif
#endif /* __VAPP_HS_DEF_H__ */
