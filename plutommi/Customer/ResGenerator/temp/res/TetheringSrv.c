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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * TetheringSrv.res
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Tethering service resource.
 *
 * Author:
 * -------
 * Yixiong Zhao(mtk80274)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 04 16 2012 yixiong.zhao
 * [MAUI_03168679] [Proxy Address Support Domain Name Input] check in to 11B
 * Check in proxy url for tethering.
 *
 * 04 11 2012 yixiong.zhao
 * [MAUI_03163544] [WLAN]It use the wrong data connection SIM when turn on WLAN hotspot
 * .
 *
 * 02 16 2012 yixiong.zhao
 * [MAUI_03131496] Move timer id to app res files
 * .
 *
 * 02 15 2012 yixiong.zhao
 * [MAUI_03127267] [Performance][UI_COSMOS][USB_UI_16]select USB tehtering until popup sub-menu
 * .
 *
 * 02 14 2012 yixiong.zhao
 * [MAUI_03129893] [Wi-Fi tethering] Wi-Fi tethering MMI switch depend on __CUSTOM_WIFI_FEATURES_SWITCH__
 * .
 *
 * 02 14 2012 yixiong.zhao
 * [MAUI_03086992] [SIM Recovery]The USB tethering can not camp on network again
 * .
 *
 * 01 14 2012 yixiong.zhao
 * [MAUI_03116474] [MT5931][Must Resolve][11BW1144SP_Only] Show incomplete string on popup in Wifi Tethering
 * .
 *
 * 01 13 2012 yixiong.zhao
 * [MAUI_03116474] [MT5931][Must Resolve][11BW1144SP_Only] Show incomplete string on popup in Wifi Tethering
 * .
 *
 * 10 27 2011 yixiong.zhao
 * [MAUI_03062905] [sap]SAP connect, the da in wifi tethering show empty name
 * .
 *
 * 09 21 2011 yixiong.zhao
 * [MAUI_03033499] [Tethering] Wi-Fi power change by charging
 * .
 *
 * 08 12 2011 yixiong.zhao
 * [MAUI_03004187] [LUFFY76V22][COSMOS][USB Tethering]  USB Tethering should be connected automatically but not
 * .
 *
 * 08 10 2011 yixiong.zhao
 * [MAUI_03002975] [USB tethering] Remove opera conflict code
 * .
 *
 * 06 04 2011 yixiong.zhao
 * [MAUI_02952833] [USB Tethering][1] Assert fail usbacm_drv.c 3486 - DRVHISR
 * .
 *
 * 04 18 2011 yixiong.zhao
 * [MAUI_02660705] [Tethering] Auto turn off
 * .
 *
 * 04 13 2011 yixiong.zhao
 * [MAUI_02743457] should not show CSD account in Wlan Hotspot
 * .
 *
 * 04 11 2011 yixiong.zhao
 * [MAUI_02656054] [Tethering] do some enhancement
 * .
 *
 * 04 06 2011 yixiong.zhao
 * [MAUI_02906018] [USB Tehtering] The Tethering confirm message won't disappear
 * .
 *
 * 03 12 2011 yixiong.zhao
 * [MAUI_02656054] [Tethering] do some enhancement
 * .
 *
 * 03 11 2011 yixiong.zhao
 * [MAUI_02451894] [Hotspot] Hotspot should not disconnect when Phone automatically switch from 3G to 2G network
 * .
 *
 * 02 20 2011 yixiong.zhao
 * [MAUI_02652460] [USB Tethering] Check-in
 * .
 *
 * 02 12 2011 yixiong.zhao
 * [MAUI_02645462] [Hotspot] Check in code (TCPIP, DHCPD, MMI)
 * .
 *
 * 02 10 2011 yixiong.zhao
 * [MAUI_02734848] [Hotspot][wifi][1]assert fail:gl_kal.c 1202 0xd2 0x0 0x0-WNDRV
 * .
 *
 * 01 25 2011 yixiong.zhao
 * [MAUI_02649952] [Hotspot] MMI It should  change to SC.
 * .
 *
 * 01 20 2011 yixiong.zhao
 * [MAUI_02448746] [Hotspot][Int] It remains on 'Please Wait' screen always
 * .
 *
 * 01 17 2011 yixiong.zhao
 * [MAUI_02645462] [Hotspot] Check in code (TCPIP, DHCPD, MMI)
 * Adjust WPA2 string.
 *
 * 01 15 2011 yixiong.zhao
 * [MAUI_02645462] [Hotspot] Check in code (TCPIP, DHCPD, MMI)
 * Do some update
 *
 * 12 31 2010 yixiong.zhao
 * [MAUI_02645462] [Hotspot] Check in code (TCPIP, DHCPD, MMI)
 * solve resgen error.
 *
 * 12 25 2010 yixiong.zhao
 * [MAUI_02645462] [Hotspot] Check in code (TCPIP, DHCPD, MMI)
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>
#ifdef __MMI_TETHERING__
<APP id="SRV_TETHERING" name="STR_SRV_TETHERING_TEMP">
    //<MEMORY base="204800" />
    //<LAYOUT file="vapp_wifihs.xml" />
    <STRING id="STR_ID_SRV_TETHERING"/>
    <STRING id="STR_ID_SRV_TETHERING_WIFI_HS"/>
    <STRING id="STR_ID_SRV_TETHERING_WIFI_HS_SETTINGS"/>
    <STRING id="STR_ID_SRV_TETHERING_WIFI_HS_SSID"> "SSID" </STRING>
    <STRING id="STR_ID_SRV_TETHERING_WIFI_HS_AUTH_MODE"/>
    <STRING id="STR_ID_SRV_TETHERING_WIFI_HS_AUTH_MODE_OPEN"/>
    <STRING id="STR_ID_SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK"> "WPA2 PSK" </STRING>
    <STRING id="STR_ID_SRV_TETHERING_WIFI_SSID_EMPTY_WARNING"/>
    <STRING id="STR_ID_SRV_TETHERING_WIFI_PW_CAPTION"/>
    <STRING id="STR_ID_SRV_TETHERING_WIFI_PW_LENGTH_WARNING"/>
    <STRING id="STR_ID_SRV_TETHERING_WIFI_PW_LENGTH_WARNING_SHORT"/>
    <STRING id="STR_ID_SRV_TETHERING_WIFI_DISCONNECT"/>
    <STRING id="STR_ID_SRV_TETHERING_WIFI_TURN_OFF_WLAN_CNF"/>
    <STRING id="STR_ID_SRV_TETHERING_WIFI_RECONNECT"/>

    <STRING id="STR_ID_SRV_TETHERING_SAVE_ACTIVATE_ASK"/>
    <STRING id="STR_ID_SRV_TETHERING_PROXY_PROMPT"/>
    <STRING id="STR_ID_SRV_TETHERING_PROXY_GUIDE"/>
    <STRING id="STR_ID_SRV_TETHERING_PROXY_PORT"/>

    <STRING id="STR_ID_SRV_TETHERING_OTHER_SETTINGS_AND_INFORMATION"/>

    <STRING id="STR_ID_SRV_TETHERING_CONN_INFO"/>
    <STRING id="STR_ID_SRV_TETHERING_CONN_INFO_CURR_USED_SIM"/>
    <STRING id="STR_ID_SRV_TETHERING_CONN_INFO_APN"/>
    <STRING id="STR_ID_SRV_TETHERING_CONN_INFO_STA_NUM"/>

    <STRING id="STR_ID_SRV_TETHERING_USB"/>
    <STRING id="STR_ID_SRV_TETHERING_USB_DISCONNECT"/>
    <STRING id="STR_ID_SRV_TETHERING_USB_RECONNECT"/>

    <STRING id="STR_ID_SRV_TETHERING_HELP_CONTENT"/>
    <STRING id="STR_ID_SRV_TETHERING_HELP_WIFI_CONTENT"/>
    <STRING id="STR_ID_SRV_TETHERING_HELP_USB_CONTENT"/>
    <STRING id="STR_ID_SRV_TETHERING_USB_REMIND_SHORT"/>

    <STRING id="STR_ID_SRV_TETHERING_INVALID_DATA_ACCOUNT"/>
    <STRING id="STR_ID_SRV_TETHERING_WIFI_TETHERING_ACTIVATED_WARNNING"/>
    <STRING id="STR_ID_SRV_TETHERING_USB_TETHERING_ACTIVATED_WARNNING"/>
    <STRING id="STR_ID_SRV_TETHERING_DIALUP_ACTIVATED_WARNNING"/>
    <STRING id="STR_ID_SRV_TETHERING_AUTO_TURN_OFF"/>

    <RECEIVER id="EVT_ID_SRV_DTCNT_ACCT_DELETE_IND" proc="srv_tethering_dtcnt_changed_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND" proc="srv_tethering_dtcnt_changed_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY" proc="srv_tethering_mode_switch_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="srv_tethering_mode_switch_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED" proc="srv_tethering_nw_availability_changed_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_SIM_PREFERENCE_UPDATE_IND" proc="srv_tethering_dtcnt_sim_prefer_update_hdlr"/>
#ifdef __MMI_TETHERING_WIFI__
    <RECEIVER id="EVT_ID_SRV_CHARBAT_NOTIFY" proc="srv_tethering_charbat_notify_hdlr"/>
#endif /* __MMI_TETHERING_WIFI__ */
#ifdef __USB_TETHERING__
    <RECEIVER id="EVT_ID_USB_MMI_NOTIFY" proc="srv_tethering_usb_cable_status_changed_hdlr"/>
#endif /* __USB_TETHERING__ */
    //<SENDER id="EVT_ID_SRV_TETHERING_STATUS_CHANGED" hfile="GlobalResDef.h"/>
    <CACHEDATA type="byte" id="NVRAM_TETHERING_AUTO_TURN_OFF_FLAG">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Tethering auto turn off flag </DESCRIPTION>
    </CACHEDATA>

    <TIMER id="TETHERING_REACTIVATE_TIMER_ID"/>
    <TIMER id="TETHERING_REACTIVATE_RETRY_TIMER_ID"/>
    <TIMER id="TETHERING_AUTO_TURN_OFF_TIMER_ID"/>
</APP>
#endif /* __MMI_TETHERING__ */
