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
 *  vapp_desktop.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the launcher desktop resources.
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
 * 01 19 2012 weilun.liu
 * [MAUI_03107346] [Rolltech]the midlet icon is still there after delete the midlet
 * In FTE launcher, HS will deinit everything, so widget can not receive app mgr event dynamically.
 * use static function to check the shorcut widget if uninstalled after receive appmgr uninstall event.
 *
 * 09 19 2011 ch.ko
 * [MAUI_03026956] can not power off phone by power key
 * Check-in patch.
 *
 * 09 10 2011 ch.ko
 * [MAUI_03024931] [Launcher] Tune performance
 * Check-in patch.
 *
 * 09 01 2011 ch.ko
 * [MAUI_03018122] [Home] Check-in FTE launcher
 * Check-in new feature.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "CustResDef.h"


/*****************************************************************************
 * XML
 *****************************************************************************/

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_DESKTOP" package_name="native.mtk.desktop"
     name="STR_ID_VAPP_DESKTOP" img="IMG_ID_VAPP_DESKTOP_ICON"
     launch="vapp_desktop_launch">

    <!----- Screen Resource Area ---------------------------------------------->
    <SCREEN id="SCR_ID_VAPP_DESKTOP_WIDGET_SELECTOR"/>
    <SCREEN id="SCR_ID_VAPP_DESKTOP_SHORTCUT_SELECTOR"/>


    <!-- String Resource Area-------------------------------------------------->

    <STRING id="STR_ID_VAPP_DESKTOP"/>
    <STRING id="STR_ID_VAPP_DESKTOP_ADD_WIDGET"/>
    <STRING id="STR_ID_VAPP_DESKTOP_ADD_SHORTCUT"/>
    <STRING id="STR_ID_VAPP_DESKTOP_SET_WALLPAPER"/>
    <STRING id="STR_ID_VAPP_DESKTOP_ALL_PAGE_FULL"/>
    <STRING id="STR_ID_VAPP_DESKTOP_PAGE_UNAVAILABLE"/>
    <STRING id="STR_ID_VAPP_DESKTOP_SELECT_SHORTCUT"/>
    <STRING id="STR_ID_VAPP_DESKTOP_NO_SHORTCUT"/>
    <STRING id="STR_ID_VAPP_DESKTOP_SELECT_WIDGET"/>
    <STRING id="STR_ID_VAPP_DESKTOP_NO_WIDGET"/>


    <!-- Image Resource Area--------------------------------------------------->

    <!-- Main Menu Icon -->
    #define APP_ICON_IMG_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\"
    <IMAGE id="IMG_ID_VAPP_DESKTOP_ICON">APP_ICON_IMG_PATH"Home.png"</IMAGE>

    <!-- APP Images -->
    #define DESKTOP_IMG_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Home\\\\"
    #define INDICATOR_IMG_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Indicator\\\\"

    <IMAGE id="IMG_ID_VAPP_DESKTOP_PAGE_INDICATOR_NORMAL">INDICATOR_IMG_PATH"Indicator_w.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_DESKTOP_PAGE_INDICATOR_HIGHLIGHTED">INDICATOR_IMG_PATH"Indicator_g.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_DESKTOP_SHORTCUT_BG">DESKTOP_IMG_PATH"icon_bg.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_DESKTOP_TOOBAR_BG_NORMAL">DESKTOP_IMG_PATH"bg_addwidget_n.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_DESKTOP_TOOBAR_BG_PRESSED">DESKTOP_IMG_PATH"bg_addwidget_p.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_DESKTOP_TOOBAR_SEPARATOR">DESKTOP_IMG_PATH"bg_line.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_DESKTOP_TOOBAR_ADD_WIDGET">DESKTOP_IMG_PATH"icon_add_widget.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_DESKTOP_TOOBAR_ADD_APP">DESKTOP_IMG_PATH"icon_add_app.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_DESKTOP_SNAPSHOT_BG">DESKTOP_IMG_PATH"bg_widget_page.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_DESKTOP_POPUP_TOP_BG">DESKTOP_IMG_PATH"popup_bg1.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_DESKTOP_POPUP_BOTTOM_BG">DESKTOP_IMG_PATH"popup_bg2.9slice.png"</IMAGE>

    
    <!-----------------------------------------------------Other Resource Area------------------------------------------------------>   
    <RECEIVER id="EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE" proc="vapp_desktop_main_evt_hdlr"/>

</APP>

#endif /* defined(__MMI_VUI_LAUNCHER__) */

