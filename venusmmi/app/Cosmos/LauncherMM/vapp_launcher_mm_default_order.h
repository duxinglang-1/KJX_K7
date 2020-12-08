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
 *  vapp_launcher_mm_default_order.h
 *
 * Project:
 * --------
 *  Cosmos Launcher 2.0 - Launcher MM
 *
 * Description:
 * ------------
 *  Launcher MM Default Order
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


#ifndef __VAPP_LAUNCHER_MM_DEFAULT_ORDER_H__
#define __VAPP_LAUNCHER_MM_DEFAULT_ORDER_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_LAUNCHER_MM__


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

#if defined(__MMI_MAINLCD_480X800__)
static const VfxS32 VAPP_LAUNCHER_MM_BAR_CELL_COUNT = 4;
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
static const VfxS32 VAPP_LAUNCHER_MM_BAR_CELL_COUNT = 4;
#else // default HVGA 320X480
static const VfxS32 VAPP_LAUNCHER_MM_BAR_CELL_COUNT = 4;
#endif

#ifdef __OP02_0200__
static const VfxS32 VAPP_LAUNCHER_MM_ORGANIZE_UNCHANGABLE_PAGE_ITEM_COUNT = 4;
#else
static const VfxS32 VAPP_LAUNCHER_MM_ORGANIZE_UNCHANGABLE_PAGE_ITEM_COUNT = 0;
#endif

const mmi_app_package_name_struct vappLauncherMmDefaultOrder[] = 
{
    // the shortcut bar
    "native.mtk.dialer",
    "native.mtk.msg",
#ifdef __MMI_MUSIC_PLAYER_SLIM__
	"native.mtk.musicplayerslim",
#else
    "native.mtk.musicplayer",
#endif
    "native.mtk.contact",
    
    // the page content
#ifdef __OP02_0200__
    "native.mtk.mobile_internet",
    "native.mtk.wo_store",
    "native.mtk.lemei",
    "native.mtk.online_sales",
#endif
    "native.mtk.calllog",
    "native.mtk.calendar",
    "native.mtk.camcorder",
    "native.mtk.setting",
    "native.mtk.clock",
    "native.mtk.alarm",
    "native.mtk.opera",
    "native.mtk.vapp_browser",
    "native.mtk.vapp_dlagent",
    "native.mtk.gallery",
#if defined(__MMI_MAINLCD_240X320__)
    "native.mtk.launcher_shuttle",
    "native.mtk.screen_lock_shuttle",
    "native.mtk.app_icon",
    "native.mtk.launcher_mm_barrel_setting",
#endif
    "native.mtk.calculator",
    "native.mtk.fmgr",
    "native.mtk.appmanager",
    "native.mtk.soundrec",
#if defined(__MMI_MAINLCD_480X800__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__)
    "native.mtk.launcher_shuttle",
    "native.mtk.screen_lock_shuttle",
    "native.mtk.app_icon",
    "native.mtk.launcher_mm_barrel_setting",
#endif
    "native.mtk.wifi",
    "native.mtk.cnmgr",
    "native.mtk.vapp_notes",
    "native.mtk.task",
    "native.mtk.fmradio",
    "native.mtk.sync",
    "native.mtk.vapp_email",
    "native.mtk.worldclock",
    "native.mtk.app_converter",
 #ifdef __MMI_BAIDU_SEARCH_COSMOS__
    "native.mtk.baidu",
 #endif
 #if (defined(__MMI_BAIDU_SEARCH_COSMOS__) || defined(__MMI_GOOGLE_SEARCH_COSMOS__)) && (defined(__MMI_GB_WINGUO__) || defined(__MMI_GB_WINGUO_V2__))
    "native.guobi.winguo",
    "native.guobi.winguo_net",
 #endif
    "native.mtk.sat"
};

const VfxS32 vappLauncherMmDefaultOrderCount = sizeof(vappLauncherMmDefaultOrder) / sizeof(mmi_app_package_name_struct);


#endif // __MMI_VUI_LAUNCHER_MM__


#endif // __VAPP_LAUNCHER_MM_DEFAULT_ORDER_H__

