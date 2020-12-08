/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_WGTMGR">

#ifdef __MMI_GADGET_SUPPORT__
    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>


    <!------------------------------------------------------Callback Manager---------------------------------------------------------->    
    <SENDER id="EVT_ID_SRV_WGTMGR_FILE_NOT_EXISTS_IND" hfile="WgtMgrSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_WGTMGR_DELETE_WIDGET_IND" hfile="WgtMgrSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_WGTMGR_FINISH_PRE_INSATLL_WIDGET_IND" hfile="WgtMgrSrvGprot.h"/>

    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="srv_wgtmgr_fmgr_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="srv_wgtmgr_fmgr_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="srv_wgtmgr_fmgr_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SHUTDOWN_DEINIT" proc="srv_wgtmgr_shutdown_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_ACCT_DELETE_IND" proc="srv_wgtmgr_dtcnt_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND" proc="srv_wgtmgr_dtcnt_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_SIM_PREFERENCE_UPDATE_IND" proc="srv_wgtmgr_dtcnt_notify_hdlr"/>
#ifdef __MMI_USB_SUPPORT__
    <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="srv_wgtmgr_usb_notify_hdlr"/>
#endif

    <!------------------------------------------------------MMI Cache---------------------------------------------------------->    

    <CACHEDATA type="byte" id="NVRAM_WGTMGR_WGT_SORT_ORDER" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_WGTMGR_WGT_NETWORK_ACCESS" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="byte" id="NVRAM_WGTMGR_WGT_NEED_UPDATE_NAME">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>    

    <CACHEDATA type="byte" id="NVRAM_WGTMGR_PRE_INSTALL_DONE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_WGTMGR_WIFI_ONLY" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_WGTMGR_WGT_DATA_ACCOUNT_FIRST" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> WGTMGR data account </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_WGTMGR_WGT_DATA_ACCOUNT_LAST" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> WGTMGR data account </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_WGTMGR_WGT_DATA_ACCOUNT_2_FIRST" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> WGTMGR data account </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_WGTMGR_WGT_DATA_ACCOUNT_2_LAST" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> WGTMGR data account </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_WGTMGR_WGT_DATA_ACCOUNT_3_FIRST" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> WGTMGR data account </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_WGTMGR_WGT_DATA_ACCOUNT_3_LAST" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> WGTMGR data account </DESCRIPTION>
    </CACHEDATA>
    
    
    <CACHEDATA type="short" id="NVRAM_WGTMGR_WGT_DATA_ACCOUNT_4_FIRST" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> WGTMGR data account </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_WGTMGR_WGT_DATA_ACCOUNT_4_LAST" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> WGTMGR data account </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="double" id="NVRAM_WGTMGR_WGT_PHONE_LANG">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> WGTMGR lang </DESCRIPTION>
    </CACHEDATA>

#endif /* __MMI_GADGET_SUPPORT__ */
</APP>

