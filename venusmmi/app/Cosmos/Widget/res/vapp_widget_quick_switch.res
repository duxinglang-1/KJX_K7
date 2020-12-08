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
 *  vapp_widget_quick_switch.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the quick switch widget's resources.
 *
 * Author:
 * -------
 *  Andy Kauo (mtk03823)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 05 02 2012 andy.kauo
 * [MAUI_03177361] [Victor 56V10][Cosmos]Message] Fatal Error (0x4, 0x301733) - MMI File: venusmmi/framework/interface/..\ui_core\mvc\vfx_primitive_frame.h, Function: VappWidgetQuickSwitch::onProc()
 * 1.Do not update widget status while it has been serialized.
 * 2.Change wrap compile option as MMI_VUI_WIDGET_QUICK_SWITCH and code revision.
 * 
 *
 * 02 03 2012 andy.kauo
 * [MAUI_03121898] [WLAN]Can't turn on WLAN when flight mode on at quickly widget
 * . The change of WLAN can be turned on in flight mode (execpt CMCC project).
 *
 * 01 18 2012 ch.ko
 * [MAUI_03118855] Check-in Cosmos 2.0 launcher and screen lock
 * Check-in patch.
 *
 * 09 28 2011 andy.kauo
 * [MAUI_03034417] [5931]WLAN status doesn't sync in this case
 * . Change event ID for querying wlan status.
 *
 * 07 20 2011 andy.kauo
 * [MAUI_02979583] [WiFi] It does not ask user confirmation to OFF WLAN tethering in Quick switch widget
 * Fix build error for resID.
 *
 * 06 23 2011 andy.kauo
 * [MAUI_02966107] [LuffyV22][Cosmos][Home Native widget] Backlight brightness increasing logic wrong
 * Fix backlight increasing level while restore the widget view.
 *
 * 06 10 2011 andy.kauo
 * [MAUI_02959577] [Home] QuickSwitch Widget Check In
 * New Feature Check In.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_QUICK_SWITCH__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "CustResDef.h"


/*****************************************************************************
 * XML
 *****************************************************************************/

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_WIDGET_QUICK_SWITCH" type="venus">

    <!-- String Resource Area-------------------------------------------------->
    <STRING id="STR_ID_VAPP_WIDGET_QUICK_SWITCH"/>
    <STRING id="STR_ID_VAPP_WIDGET_QUICK_SWITCH_WIFI_NOTIFY"/>
    <STRING id="STR_ID_VAPP_WIDGET_QUICK_SWITCH_BT_IN_FLIGHT_MODE_ASK"/>
    <STRING id="STR_ID_VAPP_WIDGET_QUICK_SWITCH_BT_TURN_ON"/>
    <STRING id="STR_ID_VAPP_WIDGET_QUICK_SWITCH_BT_OFF_WITH_CONNECTION"/>
    <STRING id="STR_ID_VAPP_WIDGET_QUICK_SWITCH_BT_TURN_OFF"/>
    <STRING id="STR_ID_VAPP_WIDGET_QUICK_SWITCH_WLAN_OFF_HOT_SPOT"/>
    <STRING id="STR_ID_VAPP_WIDGET_QUICK_SWITCH_WLAN_ON_FAILED"/>
    <STRING id="STR_ID_VAPP_WIDGET_QUICK_SWITCH_WLAN_OFF_FAILED"/>
    <STRING id="STR_ID_VAPP_WIDGET_QUICK_SWITCH_WLAN_ON_CONFIRM"/>
    <STRING id="STR_ID_VAPP_WIDGET_QUICK_SWITCH_WLAN"/>    

    <!-- Image Resource Area--------------------------------------------------->
    #define IMG_ROOT_PATH RES_IMG_ROOT"\\\\Widget\\\\QuickSwitch\\\\"

    <IMAGE id="IMG_ID_VAPP_WIDGET_QUICK_SWITCH_ICON">IMG_ROOT_PATH"QuickSwitch.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_QUICK_SWITCH_BG_N">IMG_ROOT_PATH"BG_N.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_QUICK_SWITCH_BG_P_LEFT">IMG_ROOT_PATH"BG_P_Left.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_QUICK_SWITCH_BG_P_RIGHT">IMG_ROOT_PATH"BG_P_Right.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_QUICK_SWITCH_BG_P_MIDDLE">IMG_ROOT_PATH"BG_P_Middle.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_QUICK_SWITCH_LINE">IMG_ROOT_PATH"SeperatorLine.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_QUICK_SWITCH_WIFI_H">IMG_ROOT_PATH"WIFI_H.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_QUICK_SWITCH_WIFI_N">IMG_ROOT_PATH"WIFI_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_QUICK_SWITCH_BT_H">IMG_ROOT_PATH"BT_H.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_QUICK_SWITCH_BT_N">IMG_ROOT_PATH"BT_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_QUICK_SWITCH_SILENT_H">IMG_ROOT_PATH"Silent_H.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_QUICK_SWITCH_SILENT_N">IMG_ROOT_PATH"Silent_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_QUICK_SWITCH_FLIGHT_H">IMG_ROOT_PATH"Flight_H.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_QUICK_SWITCH_FLIGHT_N">IMG_ROOT_PATH"Flight_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_QUICK_SWITCH_BRIGHTNESS_H">IMG_ROOT_PATH"Brightness_H.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_QUICK_SWITCH_BRIGHTNESS_N">IMG_ROOT_PATH"Brightness_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_H">IMG_ROOT_PATH"Indicator_H.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N">IMG_ROOT_PATH"Indicator_N.png"</IMAGE>

    <!-- Event Area--------------------------------------------------->
    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidgetQuickSwitchPublisher"/>

</APP>

#endif /* defined(__MMI_VUI_WIDGET_QUICK_SWITCH__) */
