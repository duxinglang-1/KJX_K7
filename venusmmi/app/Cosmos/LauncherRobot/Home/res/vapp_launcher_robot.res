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
 *  vapp_launcher_robot.res
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
 *  Weilun Liu (mtk02772)
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
 * 07 04 2012 weilun.liu
 * [MAUI_03211096] WinguoNet App check in
 * check in winguo app
 *
 * 06 11 2012 weilun.liu
 * [MAUI_03188145] [Cosmos 2.0 enhancement]
 * limt number of shortcut widget
 *
 * 05 18 2012 weilun.liu
 * [MAUI_03188145] [Cosmos 2.0 enhancement]
 * check in new page transition effect and HS FX setting app
 *
 * 04 13 2012 ch.ko
 * [MAUI_03165607] [Cosmos Slim] Check-in patch
 * Reduce system drive usage.
 *
 * 02 21 2012 weilun.liu
 * [MAUI_03131165] [UE]the page indicator is cutted in the bottom and top.
 * change cosmos launcher indicator and customize status bar bg for each launcher
 *
 * 02 07 2012 weilun.liu
 * [MAUI_03119748] [Cosmos2.0] check in
 * robot launcher support delete widget by trash can
 *
 * 01 19 2012 weilun.liu
 * [MAUI_03119748] [Cosmos2.0] check in
 * check in cosmos2.0
 *
 * 01 17 2012 weilun.liu
 * [MAUI_03115275] [Cosmos2.0] check in Cosmos HS and Android HS
 * check in
 *
 * 01 16 2012 weilun.liu
 * [MAUI_03115275] [Cosmos2.0] check in Cosmos HS and Android HS
 * Implement virtual function for meta information
 *
 * 01 11 2012 weilun.liu
 * [MAUI_03115275] [Cosmos2.0] check in Cosmos HS and Android HS
 * check in cosmos and android launcher
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

<APP id="VAPP_LAUNCHER_ROBOT">

    <!-- System Resource Area -------------------------------------------------->

    <CACHEDATA type="byte" id="NVRAM_VAPP_LAUNCHER_ROBOT_NEW_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE>[0x01]</DEFAULT_VALUE>
        <DESCRIPTION>Robot launcher new setting flag</DESCRIPTION>
    </CACHEDATA>


    <!-- String Resource Area-------------------------------------------------->

    <STRING id="STR_ID_VAPP_LAUNCHER_ROBOT_SETTING_NAME"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_ROBOT"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_ROBOT_ADD_WIDGET"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_ROBOT_ADD_SHORTCUT"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_ROBOT_SET_WALLPAPER"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_ROBOT_ALL_PAGE_FULL"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_ROBOT_SHORTCUT_ALREADY_EXIT"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_ROBOT_PAGE_UNAVAILABLE"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_ROBOT_SELECT_SHORTCUT"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_ROBOT_NO_SHORTCUT"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_ROBOT_SELECT_WIDGET"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_ROBOT_NOT_AVAILABLE_IN_USB_MODE"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_ROBOT_FILE_NOT_EXISTS"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_ROBOT_FILE_NOT_EXISTS_AND_WILL_BE_REMOVED"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_ROBOT_KEEP_IT"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_ROBOT_CANNOT_ADD_MORE_SHORTCUT"/>

    <!-- Image Resource Area--------------------------------------------------->

    <!-- Theme Images -->
    <THEME>
        <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_PAGE_INDICATOR_NORMAL" desc="Color of the page indicator at normal status"/>
        <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_PAGE_INDICATOR_HIGHLIGHTED" desc="Color of the page indicator at highlighted status"/>
    </THEME>

    <!-- APP Images -->

    #define LAUNCHER_IMG_ROOT       RES_IMG_ROOT"\\\\Launcher\\\\LauncherRobot\\\\"
    #define HOME_IMG_ROOT           RES_IMG_ROOT"\\\\Home\\\\"
    #define ROBOT_IMG_ROOT          RES_IMG_ROOT"\\\\Launcher\\\\LauncherRobot\\\\Home\\\\"

    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_SETTING_SNAPSHOT">LAUNCHER_IMG_ROOT"screenshot.png"</IMAGE>

    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_TOOBAR_BG_NORMAL">ROBOT_IMG_ROOT"bg_addwidget_n.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_TOOBAR_BG_PRESSED">ROBOT_IMG_ROOT"bg_addwidget_p.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_TOOBAR_SEPARATOR">ROBOT_IMG_ROOT"bg_line.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_TOOBAR_ADD_WIDGET">ROBOT_IMG_ROOT"icon_add_widget.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_TOOBAR_ADD_APP">ROBOT_IMG_ROOT"icon_add_app.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_TOOBAR_WALLPAPER">ROBOT_IMG_ROOT"icon_wallpaper.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_SNAPSHOT_BG">ROBOT_IMG_ROOT"bg_widget_page.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_SHORTCUT_BG">ROBOT_IMG_ROOT"BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_BROWSER_H">ROBOT_IMG_ROOT"Browser_H.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_BROWSER_N">ROBOT_IMG_ROOT"Browser_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_CALL_H">ROBOT_IMG_ROOT"Call_H.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_CALL_N">ROBOT_IMG_ROOT"Call_N.png"</IMAGE>
#ifdef __MMI_GB_WINGUO__
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_WINGUO_N">ROBOT_IMG_ROOT"Winguo_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_WINGUO_H">ROBOT_IMG_ROOT"Winguo_H.png"</IMAGE>
#endif
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_MAINMENU_H">ROBOT_IMG_ROOT"Mianmenu_H.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_MAINMENU_N">ROBOT_IMG_ROOT"Mianmenu_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_INDICATOR_H">ROBOT_IMG_ROOT"Indicador_H.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_INDICATOR_P">ROBOT_IMG_ROOT"Indicador_P.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_TRASH_CAN_BAR_BG_H">ROBOT_IMG_ROOT"Delete_BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_TRASH_CAN_ICON_N">ROBOT_IMG_ROOT"Delete01.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_TRASH_CAN_ICON_H">ROBOT_IMG_ROOT"Delete02.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_STATUS_BAR_BG">LAUNCHER_IMG_ROOT"StatusBar_BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_PAGE_BG">ROBOT_IMG_ROOT"page.9slice.png"</IMAGE>


    <!-- Shader Resource Area ------------------------------------------------->
#if defined(__COSMOS_3D_V10__)
    <BINARY3D id="VAPP_LAUNCHER_ROBOT_COLOR_FILTER_FS" base_path="current">"vapp_launcher_robot_color_filter.fs"</BINARY3D>
#endif /* defined(__COSMOS_3D_V10__) */


    <!-- Event Area (Sender) -------------------------------------------------->


    <!-- Event Area (Receiver) ------------------------------------------------>
    <RECEIVER id="EVT_ID_VAPP_LAUNCHER_SYS_INIT" proc="VappLauncherRobotDirectorPublisher"/>


</APP>

