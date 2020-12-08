#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

#ifdef __MMI_BT_SUPPORT__
<APP id="VAPP_BT_MAIN" name="STR_ID_VAPP_BT_MAIN" type="venus">
    <MEMORY heap="500*1024"/>

    <CACHEDATA type="byte" id="NVRAM_BT_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Bluetooth Setting </DESCRIPTION>
    </CACHEDATA>
    <CACHEDATA type="byte" id="NVRAM_BT_STORAGE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Bluetooth Storage </DESCRIPTION>
    </CACHEDATA>

    <STRING id="STR_ID_VAPP_BLUETOOTH" />
    <STRING id="STR_ID_VAPP_BT_MAIN" />
    <STRING id="STR_ID_VAPP_BT_PAIRED_DEVICE" />
    <STRING id="STR_ID_VAPP_BT_VISIBILITY" />
    <STRING id="STR_ID_VAPP_BT_MY_DEVICE_NAME" />
    <STRING id="STR_ID_VAPP_BT_SETTING_HINT" />
    <STRING id="STR_ID_VAPP_BT_IN_FLIGHT_MODE_ASK" />
    <STRING id="STR_ID_VAPP_BT_REMOTE_SIM_MODE" />
    <STRING id="STR_ID_VAPP_BT_RECENT_DEVICE" />
    <STRING id="STR_ID_VAPP_BT_SEARCH" />
    <STRING id="STR_ID_VAPP_BT_SEARCHING" />    
    <STRING id="STR_ID_VAPP_BT_STOP_SEARCH" />    
    <STRING id="STR_ID_VAPP_BT_DEVICE_FOUND" />
    <STRING id="STR_ID_VAPP_BT_RESEARCH" />
    <STRING id="STR_ID_VAPP_BT_SEARCH_RESULT" />
    <STRING id="STR_ID_VAPP_BT_POWER_ON_BLUETOOTH_FIRST" />
    <STRING id="STR_ID_VAPP_BT_AUTHORIZE" />
    <STRING id="STR_ID_VAPP_BT_STORAGE" />
    <STRING id="STR_ID_VAPP_BT_ALWAYS_CONNECT" />
    <STRING id="STR_ID_VAPP_BT_ALWAYS_ASK" />
    <STRING id="STR_ID_VAPP_BT_ACCEPT" />
    <STRING id="STR_ID_VAPP_BT_REJECT" />
    <STRING id="STR_ID_VAPP_BT_ACCEPT_ASK" />
    <STRING id="STR_ID_VAPP_BT_ACCEPT_EXCHANGE" />
    <STRING id="STR_ID_VAPP_BT_DELETE_ASK" />
    <STRING id="STR_ID_VAPP_BT_AUTHORIZE_ASK" />
    <STRING id="STR_ID_VAPP_BT_PAIR_SUCESS" />
    <STRING id="STR_ID_VAPP_BT_PAIR_FAILED" />
    <STRING id="STR_ID_VAPP_BT_INPUT_PASSCODE" />
    <STRING id="STR_ID_VAPP_BT_NUMERIC_COMPARISON" />
    <STRING id="STR_ID_VAPP_BT_ACCEPT_PAIRING" />
    <STRING id="STR_ID_VAPP_BT_SAVE_TO_PHONE" />
    <STRING id="STR_ID_VAPP_BT_SAVE_TO_CARD" />
    <STRING id="STR_ID_VAPP_BT_RECV_START" />
    <STRING id="STR_ID_VAPP_BT_RECV_COMPLETE" />
    <STRING id="STR_ID_VAPP_BT_RECV_FAIL" />
    <STRING id="STR_ID_VAPP_BT_FILE" />
    <STRING id="STR_ID_VAPP_BT_FILES" />
    <STRING id="STR_ID_VAPP_BT_PAIR_LIST_FULL" />
    <STRING id="STR_ID_VAPP_BT_HEADSET_DISCONNECT"/>
    <STRING id="STR_ID_VAPP_BT_FAIL_CONNECT" />
    <STRING id="STR_ID_VAPP_BT_NOT_AVAILABLE" />
    <STRING id="STR_ID_VAPP_BT_TURN_ON" />
    <STRING id="STR_ID_VAPP_BT_TURN_OFF" />
    <STRING id="STR_ID_VAPP_BT_PLEASE_WAIT" />
    <STRING id="STR_ID_VAPP_BT_TURN_OFF_WITH_CONNECTION_CONFIRM" />
    <STRING id="STR_ID_VAPP_BT_PAIRED_DEV_FULL" />
    <STRING id="STR_BT_VAPP_BT_DISCONN_DEV_CONN" />
    <STRING id="STR_ID_VAPP_BT_PAIRED_DEV_EMPTY" />
    <STRING id="STR_ID_VAPP_BT_MY_ADDR" />
    <STRING id="STR_ID_VAPP_BT_PREFER_SIM" />
    <STRING id="STR_ID_VAPP_BT_PREFER_SIM_NOT_AVAILIABLE" />
    <STRING id="STR_ID_VAPP_BT_NO_DEV_FOUND" />

    <IMAGE id="IMG_ID_VAPP_BT_TAB_MAIN">RES_IMG_ROOT"\\\\Bluetooth\\\\TabIcon\\\\Buletooth.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_BT_TAB_DEVICE">RES_IMG_ROOT"\\\\Bluetooth\\\\TabIcon\\\\Paired.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_BT_DEV_LAP">RES_IMG_ROOT"\\\\Bluetooth\\\\ListIcon\\\\Computer.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_BT_DEV_MOB">RES_IMG_ROOT"\\\\Bluetooth\\\\ListIcon\\\\Phone.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_BT_DEV_AUDIO">RES_IMG_ROOT"\\\\Bluetooth\\\\ListIcon\\\\Audio.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_BT_DEV_OTHER">RES_IMG_ROOT"\\\\Bluetooth\\\\ListIcon\\\\Common.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_BT_DEV_PRINTER">RES_IMG_ROOT"\\\\Bluetooth\\\\ListIcon\\\\Printer.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_BT_DEV_CONNECTED">RES_IMG_ROOT"\\\\Bluetooth\\\\ListIcon\\\\Connected.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_BT_NC_SEND">RES_IMG_ROOT"\\\\NMGR_Icon\\\\icon_BT_out.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_BT_NC_RECEIVE">RES_IMG_ROOT"\\\\NMGR_Icon\\\\icon_BT_in.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_BT_DEV_SEARCH_STOP">RES_IMG_ROOT"\\\\Email\\\\ToolbarIcon\\\\Stop.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_BT_DEV_SEARCHING">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Search.png"</IMAGE>
    
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="vapp_bt_storage_change_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="vapp_bt_storage_change_hdlr"/>
#ifdef __MMI_USB_SUPPORT__
#ifdef __MMI_OPP_SUPPORT__
    <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="vapp_opps_usb_plugin_hdlr"/>
#endif /* __MMI_OPP_SUPPORT__ */
#endif /* __MMI_USB_SPLIT_SUPPORT__ */

    #if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
    #ifdef __MMI_USB_SUPPORT__
    <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="vapp_ftp_enter_usb_ms_callback"/>
    #endif /* __MMI_USB_SUPPORT__ */
    #endif

    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_SWITCH_OTHER_NOTIFY" proc="vapp_bt_flight_mode_ind_handle"/>

    #ifdef __MMI_USB_SUPPORT__
    <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="vapp_bt_enter_usb_ms_hdlr"/>
    <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="vapp_bt_exit_usb_ms_hdlr"/>
    #endif /* __MMI_USB_SPLIT_SUPPORT__ */

</APP>

<APP id="VAPP_BT_SEND" name="STR_ID_VAPP_BT_SEND" type="venus">
    <MEMORY heap="200*1024"/>
    <TIMER id="MMI_TIMER_UPDATE_PROGRESS" />
    <TIMER id="MMI_TIMER_CACULATE_FILES_SIZE" />
    <STRING id="STR_ID_VAPP_BT_SENDING" />
    <STRING id="STR_ID_VAPP_BT_SENT" />
    <STRING id="STR_ID_VAPP_BT_CONNECTING" />
    <STRING id="STR_ID_VAPP_BT_FAIL_SEND" />
    <STRING id="STR_ID_VAPP_BT_SEND" />
    <STRING id="STR_ID_VAPP_BT_DISCARD_SENDING" />
    <STRING id="STR_ID_VAPP_BT_DISCARD" />
    <STRING id="STR_ID_VAPP_BT_CANCEL" />
    <STRING id="STR_ID_VAPP_BT_ALL_SENT" />
    <STRING id="STR_ID_VAPP_BT_NOT_ALL_SENT" />
    <STRING id="STR_ID_VAPP_BT_ONE_NOT_SENT" />

#ifdef __MMI_USB_SUPPORT__
#ifdef __MMI_OPP_SUPPORT__
    <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="vapp_oppc_usb_plugin_hdlr"/>
#endif /* __MMI_OPP_SUPPORT__ */
#endif /* __MMI_USB_SPLIT_SUPPORT__ */

#ifdef __MMI_OPP_SUPPORT__
    <RECEIVER id="EVT_ID_VAPP_LANGUAGE_CHANGED" proc="vapp_oppc_language_changed_hdlr"/>
#endif /* __MMI_OPP_SUPPORT__ */

</APP>

<APP id="VAPP_BT_PASSKEY_NOTIFY" name="STR_ID_VAPP_BT_PASSKEY_NOTIFY" type="venus">
    <MEMORY heap="150*1024"/>
    <STRING id="STR_ID_VAPP_BT_PASSKEY_NOTIFY" />
</APP>

<APP id="VAPP_BT_FMGR_LAUNCHER" name="STR_ID_VAPP_BT_FMGR_LAUNCHER" type="venus">
    <MEMORY cui="VCUI_FMGR" heap="10*1024"/>
    <STRING id="STR_ID_VAPP_BT_FMGR_LAUNCHER" />
</APP>

<APP id="VCUI_BT_POWERON" name="STR_ID_VCUI_BT_POWERON" type="venus">
    <MEMORY heap="50*1024"/>
    <STRING id="STR_ID_VCUI_BT_POWERON" />
</APP>

<APP id="VCUI_BT_SELDEV" name="STR_ID_VCUI_BT_SELDEV" type="venus">
    <MEMORY heap="100*1024"/>
    <STRING id="STR_ID_VCUI_BT_SELDEV" />
</APP>

<APP id="VCUI_BT_SEND_PREPARE" name="STR_ID_VCUI_BT_SEND_PREPARE" type="venus">
    <MEMORY cui="VCUI_BT_SELDEV" heap="100*1024"/>
    <STRING id="STR_ID_VCUI_BT_SEND_PREPARE" />
</APP>

#ifdef __MMI_PBAP_SUPPORT__
<APP id="VAPP_BT_OBEX_AUTHTICATION" name="STR_ID_VAPP_BT_OBEX_AUTHTICATION" type="venus">
    <MEMORY heap="100*1024"/>
    <STRING id="STR_ID_VAPP_BT_OBEX_AUTHTICATION" />
</APP>
#endif //__MMI_PBAP_SUPPORT__

#endif//__MMI_BT_SUPPORT__

<APP id="APP_BLUETOOTH" type="venus">
#ifdef __MMI_BPP_SUPPORT__
     <SCREEN id="SCR_BPP_DUMMY"/>
#endif
</APP>
