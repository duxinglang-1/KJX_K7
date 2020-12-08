#include "MMI_features.h"
#if defined(__MMI_VUI_SHELL_OP01_HOMESCREEN__)
#include "CustResDef.h"

<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_SHELL_OP01_HS">

    <!----------------------------------------Image Resource Area----------------------------------------->
    #define ROOT_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Shell\\\\OP01HomeScreen\\\\"

#ifdef __MMI_OP01_DCD_V30__
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_DCD_BG">ROOT_PATH"DCD_BG.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_DCD_DEFAULT_ICON">ROOT_PATH"Idle_DCD_default.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_DCD_WEATHER_ICON">ROOT_PATH"Idle_Weather_default.png"</IMAGE>
#endif
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_LEFT_ARROW_NORMAL">ROOT_PATH"Idle_ArrowLeft.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_LEFT_ARROW_PRESSED">ROOT_PATH"Idle_ArrowLeft_Active.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_RIGHT_ARROW_NORMAL">ROOT_PATH"Idle_ArrowRight.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_RIGHT_ARROW_PRESSED">ROOT_PATH"Idle_ArrowRight_Active.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_MISSED_CALL_NORMAL">ROOT_PATH"MissCall.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_MISSED_CALL_PRESSED">ROOT_PATH"MissCall_Active.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_SMS_NORMAL">ROOT_PATH"SMS.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_SMS_PRESSED">ROOT_PATH"SMS_Active.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_MMS_NORMAL">ROOT_PATH"MMS.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_MMS_PRESSED">ROOT_PATH"MMS_Active.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_SC_BG">ROOT_PATH"SC_BG.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_SC_HIGHLIGHT">ROOT_PATH"SC_Highlight.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_SC_MAIL">ROOT_PATH"SC_139Mail.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_SC_FETION">ROOT_PATH"SC_FETION.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_SC_MAP">ROOT_PATH"SC_Map.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_SC_MO">ROOT_PATH"SC_MO.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_SC_STOCK">ROOT_PATH"SC_mStock.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_SC_MUSIC">ROOT_PATH"SC_Music.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_SC_MOBILE_VIDEO">ROOT_PATH"SC_MVedio.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_SC_MARKET">ROOT_PATH"SC_STORE.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_SC_READER">ROOT_PATH"SC_READ.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_SC_10086">ROOT_PATH"SC_10086.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_SC_TV">ROOT_PATH"SC_TV.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_STATUS_BAR">ROOT_PATH"Statusbar_BG.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_BUTTON_NORMAL_BG">ROOT_PATH"Button_BG.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_BUTTON_PRESSED_BG">ROOT_PATH"Button_BG_Active.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_SEARCH_ICON_NORMAL">ROOT_PATH"Icon_Search.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_SEARCH_ICON_PRESSED">ROOT_PATH"Icon_Search_Active.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_WLAN_ENABLE_ICON_NORMAL">ROOT_PATH"Icon_WiFi.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_WLAN_ENABLE_ICON_PRESSED">ROOT_PATH"Icon_WiFi_Active.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_WLAN_PROGRESS_DOT">ROOT_PATH"WiFi_dot.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_WLAN_DISABLE_ICON_NORMAL">ROOT_PATH"Icon_WiFi_Disable.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_WLAN_DISABLE_ICON_PRESSED">ROOT_PATH"Icon_WiFi_Disable_Active.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_HINT_BOX_NORMAL">ROOT_PATH"Info_BG.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_OP01HS_HINT_BOX_PRESSED">ROOT_PATH"Info_BG_Active.png"</IMAGE>


    <!------------------------------------------------------Callback Manager Register---------------------------------------------------------->

	<RECEIVER id="EVT_ID_SRV_SMS_READY" proc="mmi_shell_op01_hs_evt_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_SMS_ADD_MSG" proc="mmi_shell_op01_hs_evt_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_SMS_DEL_MSG" proc="mmi_shell_op01_hs_evt_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_SMS_UPDATE_MSG" proc="mmi_shell_op01_hs_evt_hdlr"/>

	<RECEIVER id="EVT_ID_SRV_MMS_READY" proc="mmi_shell_op01_hs_evt_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_UM_NOTIFY_REFRESH" proc="mmi_shell_op01_hs_evt_hdlr"/>
	<RECEIVER id="EVT_ID_JSR_DELETE_MMS" proc="mmi_shell_op01_hs_evt_hdlr"/>

	<RECEIVER id="EVT_ID_SRV_CLOG_READY" proc="mmi_shell_op01_hs_evt_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_CLOG_ADD_LOG" proc="mmi_shell_op01_hs_evt_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_CLOG_UPDATE_LOG" proc="mmi_shell_op01_hs_evt_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_CLOG_UPDATE_ALL" proc="mmi_shell_op01_hs_evt_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_CLOG_DEL_LOG" proc="mmi_shell_op01_hs_evt_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_CLOG_DEL_ALL" proc="mmi_shell_op01_hs_evt_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_CLOG_REFRESH" proc="mmi_shell_op01_hs_evt_hdlr"/>

	<RECEIVER id="EVT_ID_SRV_DTCNT_WLAN_ACTIVE" proc="mmi_shell_op01_hs_evt_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_DTCNT_WLAN_CONNECTED" proc="mmi_shell_op01_hs_evt_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_DTCNT_WLAN_INACTIVE" proc="mmi_shell_op01_hs_evt_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_DTCNT_WLAN_SCAN" proc="mmi_shell_op01_hs_evt_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_DTCNT_WLAN_CONNECT" proc="mmi_shell_op01_hs_evt_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND" proc="mmi_shell_op01_hs_evt_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND" proc="mmi_shell_op01_hs_evt_hdlr"/>

</APP>

#endif /* defined(__MMI_VUI_SHELL_OP01_HOMESCREEN__) */
