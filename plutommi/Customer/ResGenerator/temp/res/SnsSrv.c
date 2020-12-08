/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "MMI_features.h"
#include "CustResDef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

#ifdef __SOCIAL_NETWORK_SUPPORT__
/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_SNS">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

    <!-- String Resource Area-------------------------------------------------->

    <STRING id="STR_ID_SRV_SNS_NOT_READY"/>
    <STRING id="STR_ID_SRV_SNS_INVALID_ACCOUNT"/>
    <STRING id="STR_ID_SRV_SNS_INVALID_TOKEN"/>
    <STRING id="STR_ID_SRV_SNS_NETWORK_ERROR"/>
    <STRING id="STR_ID_SRV_SNS_CANCELLED"/>
    <STRING id="STR_ID_SRV_SNS_INCORRECT_TIME"/>
    <STRING id="STR_ID_SRV_SNS_UPGRADING"/>
    
    <!------------------------------------------------------Callback Manager---------------------------------------------------------->    

    <EVENT id="EVT_ID_SRV_SNS_READY" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SNS_LIST_UPDATED" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SNS_LIST_INVALIDATED" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SNS_ITEM_UPDATED" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SNS_ITEM_EXT_UPDATED" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SNS_COUNTS_UPDATED" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SNS_RESULT" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SNS_PROCESS_START" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SNS_PROCESS_COMPLETE" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SNS_NET_FETCH_LIST_START" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SNS_NET_FETCH_LIST_END" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SNS_ACCOUNT_LOGGED_OUT" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SNS_PLUGIN_TO_LOAD" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SNS_PLUGINS_UNLOADED" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SNS_PLUGINS_UPGRADED" type="SENDER"/>
    
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION"    proc="srv_sns_mmi_event_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN"   proc="srv_sns_mmi_event_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT"  proc="srv_sns_mmi_event_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_READY"     proc="srv_sns_mmi_event_hdlr"/>    
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT"        proc="srv_sns_mmi_event_hdlr"/>    
    <RECEIVER id="EVT_ID_SRV_DTCNT_SIM_PREFERENCE_UPDATE_IND" proc="srv_sns_mmi_event_hdlr"/>    
#ifdef __MMI_USB_SUPPORT__
    <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE"                   proc="srv_sns_mmi_event_hdlr"/>
    <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE"                    proc="srv_sns_mmi_event_hdlr"/>
#endif
    
    <!------------------------------------------------------MMI Cache---------------------------------------------------------->    

    <CACHEDATA type="byte" id="NVRAM_SNS_NEWS_REMINDER" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> News reminder </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_SNS_SYNC_INTERVAL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Sync interval </DESCRIPTION>
    </CACHEDATA>
    
    <TIMER id="SRV_SNS_NOTIF_TIMER"/>
    <TIMER id="SRV_SNS_SYNC_TIMER"/>
    <TIMER id="SRV_SNS_INIT_TIMER"/>
    <TIMER id="SRV_SNS_UPGRADE_TIMER"/>

</APP>

#endif /* __SOCIAL_NETWORK_SUPPORT__ */