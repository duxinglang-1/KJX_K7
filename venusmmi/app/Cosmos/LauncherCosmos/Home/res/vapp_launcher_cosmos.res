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
 *  vapp_home.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the home screen resources.
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
 * 10 15 2012 weilun.liu
 * [MAUI_03162182] [Cosmos Slim]
 * remove unused image resource
 *
 * 06 11 2012 weilun.liu
 * [MAUI_03188145] [Cosmos 2.0 enhancement]
 * limt number of shortcut widget
 *
 * 04 13 2012 ch.ko
 * [MAUI_03165607] [Cosmos Slim] Check-in patch
 * Reduce system drive usage.
 *
 * 02 21 2012 weilun.liu
 * [MAUI_03131165] [UE]the page indicator is cutted in the bottom and top.
 * change cosmos launcher indicator and customize status bar bg for each launcher
 *
 * 01 19 2012 weilun.liu
 * [MAUI_03119748] [Cosmos2.0] check in
 * check in cosmos2.0
 *
 * 12 22 2011 fred.shen
 * [MAUI_02868261] [Cosmos] Cosmos check-in
 * .
 *
 * 11 30 2011 weilun.liu
 * [MAUI_03089241] [Home] add platform memory description on res file
 * add platform memory description on res file
 *
 * 10 30 2011 weilun.liu
 * [MAUI_03065696] [Cosmos3D] use 3d material instead of frame filter
 * support framefilter effect with material on 3d project
 *
 * 07 26 2011 ch.ko
 * [MAUI_02991692] [Home] Support 2nd theme feature
 * Check-in 2nd theme feature.
 *
 * 06 15 2011 ch.ko
 * [MAUI_02959307] [Home] Check-in Cosmos v1.1
 * Check-in patch.
 *
 * 06 15 2011 ch.ko
 * [MAUI_02962442] [Need Path][Sanity Fail] [Homescreen, Native Widget]_Cosmos_HS_Widget_002_017  Assert fail: vfx_sys_memory.c 1411 - MMI
 * Rollback the patch that associated with the wrong CR.
 *
 * 06 10 2011 ch.ko
 * [MAUI_02959307] [Home] Check-in Cosmos v1.1
 * Check-in new features.
 *
 * 06 09 2011 ch.ko
 * [MAUI_02959307] [Home] Check-in Cosmos v1.1
 * Check-in new features.
 *
 * 04 11 2011 ch.ko
 * [MAUI_02886884] [Performance] HS performance fail
 * Enhance performance.
 *
 * 03 31 2011 ch.ko
 * [MAUI_02886884] [Performance] HS performance fail
 * Enhance performance and revise codes.
 *
 * 03 07 2011 ch.ko
 * [MAUI_02891680] [Idle] Change the delete button image path
 * Change the file path of the delete icon.
 *
 * 03 02 2011 ch.ko
 * [MAUI_02654328] [UE]picture cover on chars
 * Remove the text on the page selector.
 *
 * 02 25 2011 ch.ko
 * [MAUI_02652996] [UE]before change screen to set home city,Gallery widget should not disappear
 * Check-in bug fixes and revise codes.
 *
 * 01 13 2011 ch.ko
 * [MAUI_02861217] [Home] Check-in bug fixes and new API
 * Check-in patch.
 *
 * 01 12 2011 ch.ko
 * [MAUI_02854445] [Home] Fix bugs
 * Check-in patch.
 *
 * 01 07 2011 ch.ko
 * [MAUI_02854445] [Home] Fix bugs
 * Check-in bug fixes.
 *
 * 01 04 2011 ch.ko
 * [MAUI_02854445] [Home] Fix bugs
 * Check-in bug fixes.
 *
 * 01 04 2011 tim.chang
 * [MAUI_02849376] [Widget] fix widget bugs
 * revise string id to follow COSMOS naming rule
 *
 * 12 24 2010 ch.ko
 * [MAUI_02849852] [Home] Check-in patch and bug fixes
 * Check-in bug fixes.
 *
 * 12 23 2010 shinn.lin
 * [MAUI_02852469] add type attribute for venus app in <APP> tag
 * .
 *
 * 12 21 2010 ch.ko
 * [MAUI_02849852] [Home] Check-in patch and bug fixes
 * Check-in patch.
 *
 * 12 06 2010 ch.ko
 * [MAUI_02845808] [Home] Check-in bug fixes
 * Check-in bug fixes.
 *
 * 11 29 2010 ch.ko
 * [MAUI_02841587] [RFR] Check-in patch to MAUI
 * Check-in new features.
 *
 * 11 24 2010 ch.ko
 * [MAUI_02841427] [Cosmos][Home] Check-in new feature
 * Check-in new feature.
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

<APP id="VAPP_LAUNCHER_COSMOS">

    <!-- System Resource Area -------------------------------------------------->

    <CACHEDATA type="byte" id="NVRAM_VAPP_LAUNCHER_COSMOS_NEW_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE>[0x01]</DEFAULT_VALUE>
        <DESCRIPTION>Cosmos launcher new setting flag</DESCRIPTION>
    </CACHEDATA>


    <!-- String Resource Area-------------------------------------------------->

    <STRING id="STR_ID_VAPP_LAUNCHER_COSMOS_SETTING_NAME"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_COSMOS"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_COSMOS_ADD_WIDGET"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_COSMOS_ADD_SHORTCUT"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_COSMOS_SET_WALLPAPER"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_COSMOS_ALL_PAGE_FULL"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_COSMOS_PAGE_UNAVAILABLE"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_COSMOS_SELECT_SHORTCUT"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_COSMOS_NO_SHORTCUT"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_COSMOS_SELECT_WIDGET"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_COSMOS_NOT_AVAILABLE_IN_USB_MODE"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_COSMOS_FILE_NOT_EXISTS"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_COSMOS_FILE_NOT_EXISTS_AND_WILL_BE_REMOVED"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_COSMOS_KEEP_IT"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_COSMOS_CANNOT_ADD_MORE_SHORTCUT"/>

    <!-- Image Resource Area--------------------------------------------------->

    <!-- APP Images -->
    #define LAUNCHER_IMG_ROOT   RES_IMG_ROOT"\\\\Launcher\\\\LauncherCosmos\\\\"
    #define HOME_IMG_ROOT       RES_IMG_ROOT"\\\\Launcher\\\\LauncherCosmos\\\\Home\\\\"
    #define INDICATOR_IMG_ROOT  RES_IMG_ROOT"\\\\Launcher\\\\LauncherCosmos\\\\Indicator\\\\"

    <IMAGE id="IMG_ID_VAPP_LAUNCHER_COSMOS_SETTING_SNAPSHOT">LAUNCHER_IMG_ROOT"screenshot.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_COSMOS_PAGE_INDICATOR_NORMAL">INDICATOR_IMG_ROOT"Indicator_w.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_COSMOS_PAGE_INDICATOR_HIGHLIGHTED_1">INDICATOR_IMG_ROOT"Indicator_1.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_COSMOS_PAGE_INDICATOR_HIGHLIGHTED_2">INDICATOR_IMG_ROOT"Indicator_2.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_COSMOS_PAGE_INDICATOR_HIGHLIGHTED_3">INDICATOR_IMG_ROOT"Indicator_3.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_COSMOS_PAGE_INDICATOR_HIGHLIGHTED_4">INDICATOR_IMG_ROOT"Indicator_4.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_COSMOS_PAGE_INDICATOR_HIGHLIGHTED_5">INDICATOR_IMG_ROOT"Indicator_5.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_COSMOS_PAGE_INDICATOR_HALO">HOME_IMG_ROOT"indi_halo.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_COSMOS_SHORTCUT_BG">HOME_IMG_ROOT"icon_bg.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_COSMOS_SHORTCUT_SEPARATOR">HOME_IMG_ROOT"splitter.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_COSMOS_TOOBAR_BG_NORMAL">HOME_IMG_ROOT"bg_addwidget_n.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_COSMOS_TOOBAR_BG_PRESSED">HOME_IMG_ROOT"bg_addwidget_p.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_COSMOS_TOOBAR_SEPARATOR">HOME_IMG_ROOT"bg_line.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_COSMOS_TOOBAR_ADD_WIDGET">HOME_IMG_ROOT"icon_add_widget.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_COSMOS_TOOBAR_ADD_APP">HOME_IMG_ROOT"icon_add_app.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_COSMOS_TOOBAR_WALLPAPER">HOME_IMG_ROOT"icon_wallpaper.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_COSMOS_SNAPSHOT_BG">HOME_IMG_ROOT"bg_widget_page.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_COSMOS_STATUS_BAR_BG">LAUNCHER_IMG_ROOT"StatusBar_BG.9slice.png"</IMAGE>

    <!-- Shader Resource Area ------------------------------------------------->
#if defined(__COSMOS_3D_V10__)
    <BINARY3D id="VAPP_LAUNCHER_COSMOS_COLOR_FILTER_FS" base_path="current">"vapp_launcher_cosmos_color_filter.fs"</BINARY3D>
#endif /* defined(__COSMOS_3D_V10__) */


    <!-- Event Area (Sender) -------------------------------------------------->


    <!-- Event Area (Receiver) ------------------------------------------------>
    <RECEIVER id="EVT_ID_VAPP_LAUNCHER_SYS_INIT" proc="VappLauncherCosmosDirectorPublisher"/>


</APP>

