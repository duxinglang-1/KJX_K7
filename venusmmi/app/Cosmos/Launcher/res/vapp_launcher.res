/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vapp_launcher.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the launcher resources.
 *
 * Author:
 * -------
 *  Cheng-Hung Ko (mtk01585)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 * 
 * 07 19 2012 weilun.liu
 * [MAUI_03217184] [Cosmos SLIM] add APP_MRE_BG concurrency with VAPP_LAUNCHER
 * add  APP_MRE_BG to concurrency table
 *
 * 07 13 2012 weilun.liu
 * [MAUI_03214876] [Victor 56V10][Cosmos][Java] Java can't be minimize , it always be terminated
 * set concurrency on 3d project
 *
 * 07 12 2012 weilun.liu
 * [MAUI_03213460] [UE] the whole screen show mess after pressing home key
 * enlarge ASM size to let gdi decode successfully
 *
 * 06 22 2012 leo.hu
 * [MAUI_03206565] mCare patch
 * .
 *
 * 06 19 2012 weilun.liu
 * [MAUI_03204333] [Cosmos SLIM] restore launcher history if OOM happens
 * support restore history and handle home key pressed with new evt provided by framework
 *
 * 06 18 2012 ch.ko
 * [MAUI_03165607] [Cosmos Slim] Check-in patch
 * Set dependency for MCare running in the background.
 *
 * 06 01 2012 ch.ko
 * [MAUI_03165607] [Cosmos Slim] Check-in patch
 * Support launcher to use ASM as runtime heap.
 *
 * 06 01 2012 weilun.liu
 * [MAUI_03162182] [Cosmos Slim]
 * remove home icon, launcher should populate it if they need
 *
 * 05 21 2012 ch.ko
 * [MAUI_03163831] [DLUI] Check-in patch
 * Correct the concurrency settings.
 *
 * 05 18 2012 ch.ko
 * [MAUI_03163831] [DLUI] Check-in patch
 * Check-in MRE launcher memory model.
 *
 * 05 17 2012 weilun.liu
 * [MAUI_03162182] [Cosmos Slim]
 * suspend wallpaper if swipe by key and set hidden_in_mainmenu res flag
 *
 * 05 14 2012 ch.ko
 * [MAUI_03165607] [Cosmos Slim] Check-in patch
 * Check-in downloadable APP icon for Cosmos slim project.
 *
 * 05 10 2012 stella.yang
 * [MAUI_03146398] [DLUI] VPI Check in
 * .
 *
 * 05 04 2012 stella.yang
 * [MAUI_03177248] Fatal Error (0x1, 0xf8646191) - MMI
 * .
 *
 * 04 24 2012 ch.ko
 * [MAUI_03163831] [DLUI] Check-in patch
 * Check-in MRE widget memory model patch.
 *
 * 04 10 2012 weilun.liu
 * [MAUI_03162182] [Cosmos Slim]
 * adjust java compile option
 *
 * 04 09 2012 weilun.liu
 * [MAUI_03162182] [Cosmos Slim]
 * reduce vrt factor to 5 in cosmos slim, and add launcher and wallpaper concurrency if not defined java
 *
 * 03 22 2012 weilun.liu
 * [MAUI_03154209] [Launcher] Workaround VRT mem factor and video memory concurrency issue.
 * set vrt factor dynamically for different wallpaper
 *
 * 03 22 2012 ch.ko
 * [MAUI_03147351] Check-in Cosmos slim patch
 * Rollback the modfiication on launcher resource.
 *
 * 03 21 2012 weilun.liu
 * [MAUI_03153741] [ADD CFG] CFG_MMI_VUI_LAUNCHER_JAVA_VIDEO_CONCURRENCY
 * disable java,video, launcher concurrency in the insufficient memory project
 *
 * 03 21 2012 ch.ko
 * [MAUI_03147028] [DLUI] Check-in new features
 * Check-in hello world launcher..
 *
 * 03 20 2012 weilun.liu
 * [MAUI_03152290] [Video]Failed to add facebook widget with VLW and JAVA.
 * set concurrency table
 *
 * 03 09 2012 weilun.liu
 * [MAUI_03146052] [6256 Cosmos3D]reduce VRT memory size from18MB to 12.5MB(WVGA/HVGA)
 * add vrt cache factor config table for launcher
 *
 * 02 15 2012 ch.ko
 * [MAUI_03118855] Check-in Cosmos 2.0 launcher and screen lock
 * Early initialize the launcher and widget system.
 *
 * 01 17 2012 ch.ko
 * [MAUI_03118855] Check-in Cosmos 2.0 launcher and screen lock
 * Check-in launcher framework.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "CustResDef.h"


/*****************************************************************************
 * XML
 *****************************************************************************/

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_LAUNCHER" package_name="native.mtk.launcher" name="STR_ID_VAPP_LAUNCHER"
    launch="vapp_launcher_launch" hidden_in_mainmenu="true" type="venus">

    <!-- System Resource Area -------------------------------------------------->

    /*
     * Launcher will use a global memory as its context such that it will not be
     * deleted when OOM happens. Still need to fill this memory tag and fill
     * 'base' as zero such that the VRT auto. cache mechanism will be turned on.
     */
#if defined(__VENUS_3D_UI_ENGINE__)
    <MEMORY base="0" fg="total(VAPP_PLATFORM_CONTEXT)+max(total(APP_VENUS_WALLPAPER_VIDEO),VAPP_LAUNCHER_FG_MEM)+1331200"
            inc="vapp_launcher_mem_cfg.h"/>

#if defined(__MMI_VUI_LAUNCHER_JAVA_VIDEO_CONCURRENCY__)
    <APPCONCURRENT concurrent_w_order="APP_JAVA, APP_TENCENT_MCARE_BG, VAPP_LAUNCHER_MRE, VAPP_WIDGET_MRE, VAPP_LAUNCHER_HEAP, SRV_VENUS_THEME, VAPP_LAUNCHER, VAPP_SCREEN_LOCK_MRE"/>
#else
#if defined(__J2ME__) && defined(J2ME_SUPPORT_BACKGROUND)
    <APPCONCURRENT concurrent_w_order="APP_JAVA, APP_TENCENT_MCARE_BG, VAPP_LAUNCHER_MRE, VAPP_WIDGET_MRE, VAPP_LAUNCHER_HEAP, SRV_VENUS_THEME, VAPP_LAUNCHER, VAPP_SCREEN_LOCK_MRE"/>
#else   // wallpaper needs to concurrent with launcher if java is not defined
    <APPCONCURRENT concurrent_w_order="APP_TENCENT_MCARE_BG, VAPP_LAUNCHER_MRE, VAPP_WIDGET_MRE, VAPP_LAUNCHER_HEAP, SRV_VENUS_THEME, VAPP_LAUNCHER, VAPP_SCREEN_LOCK_MRE"/>
#endif /* defined(__J2ME__) && defined(J2ME_SUPPORT_BACKGROUND) */
#endif /* defined(__MMI_VUI_LAUNCHER_JAVA_VIDEO_CONCURRENCY__) */

#else
    <MEMORY base="0" fg="total(VAPP_PLATFORM_CONTEXT)"
            vrt_mem_factor="VAPP_LAUNCHER_EXTRA_CACHE_MEM_FACTOR"
            inc="vapp_launcher_mem_cfg.h"/>

#if defined(__MMI_VUI_LAUNCHER_JAVA_VIDEO_CONCURRENCY__)
    <APPCONCURRENT concurrent_w_order="APP_JAVA, APP_TENCENT_MCARE_BG, APP_VENUS_WALLPAPER_TOTAL, VAPP_WIDGET_ADP, VAPP_WIDGET_DELEGATOR_IDLE, VAPP_LAUNCHER_MRE, VAPP_WIDGET_MRE, APP_MRE_BG, VAPP_LAUNCHER_HEAP, SRV_VENUS_THEME, VAPP_LAUNCHER, VAPP_SCREEN_LOCK_MRE"/>
#else
#if defined(__J2ME__) && defined(J2ME_SUPPORT_BACKGROUND)
    <APPCONCURRENT concurrent_w_order="APP_JAVA, APP_TENCENT_MCARE_BG, VAPP_WIDGET_ADP, VAPP_WIDGET_DELEGATOR_IDLE, VAPP_LAUNCHER_MRE, VAPP_WIDGET_MRE, APP_MRE_BG, VAPP_LAUNCHER_HEAP, SRV_VENUS_THEME, VAPP_LAUNCHER, VAPP_SCREEN_LOCK_MRE"/>
#else   // wallpaper needs to concurrent with launcher if java is not defined
    <APPCONCURRENT concurrent_w_order="APP_TENCENT_MCARE_BG, APP_VENUS_WALLPAPER_TOTAL, VAPP_WIDGET_ADP, VAPP_WIDGET_DELEGATOR_IDLE, VAPP_LAUNCHER_MRE, VAPP_WIDGET_MRE, APP_MRE_BG, VAPP_LAUNCHER_HEAP, SRV_VENUS_THEME, VAPP_LAUNCHER, VAPP_SCREEN_LOCK_MRE"/>
#endif /* defined(__J2ME__) && defined(J2ME_SUPPORT_BACKGROUND) */
#endif /* defined(__MMI_VUI_LAUNCHER_JAVA_VIDEO_CONCURRENCY__) */
    
#endif /* defined(__VENUS_3D_UI_ENGINE__) */

    <!-- String Resource Area-------------------------------------------------->

    <STRING id="STR_ID_VAPP_LAUNCHER"/>


    <!-- Image Resource Area--------------------------------------------------->


    <!-- Event Area (Sender) -------------------------------------------------->

    /*
     * This event is emitted after the handset enters the launcher App.
     *
     * Structure: vapp_launcher_active_evt_struct
     */
    <EVENT id="EVT_ID_VAPP_LAUNCHER_ACTIVE" type="SENDER"/>

    /*
     * This event is emitted after the handset exits the launcher App.
     *
     * Structure: vapp_launcher_inactive_evt_struct
     */
    <EVENT id="EVT_ID_VAPP_LAUNCHER_INACTIVE" type="SENDER"/>

    <RECEIVER id="EVT_ID_PRE_ACTIVE_IDLE_APP_IN_END_KEY" proc="vapp_launcher_main_evt_hdlr"/>

    <!-- Event Area (Receiver) ------------------------------------------------>


</APP>


