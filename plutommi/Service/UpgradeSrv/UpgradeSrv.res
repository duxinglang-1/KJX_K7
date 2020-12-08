/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "MMI_features.h"
#include "CustResDef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>
#if defined __MMI_VPP_UPGRADE__
/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_UPGRADE">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

    <!-- String Resource Area-------------------------------------------------->
    
    <!------------------------------------------------------Callback Manager---------------------------------------------------------->    

    <EVENT id="EVT_ID_SRV_UPGRADE_DOWNLOAD_REQ" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_UPGRADE_CHECK_VERSION_DONE_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_UPGRADE_DOWNLOAD_APP_DONE_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_UPGRADE_NOTIFY_RESULT_IND" type="SENDER"/>
    
    <RECEIVER id="EVT_ID_SRV_UPGRADE_CHECK_VERSION_DONE_IND" proc="srv_upgrade_event_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_UPGRADE_DOWNLOAD_APP_DONE_IND" proc="srv_upgrade_event_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_UPGRADE_NOTIFY_RESULT_IND" proc="srv_upgrade_event_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN"  proc="srv_upgrade_event_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="srv_upgrade_event_hdlr"/>
#ifdef __MMI_USB_SUPPORT__    
    <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE"                  proc="srv_upgrade_event_hdlr"/>
    <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE"                   proc="srv_upgrade_event_hdlr"/>
#endif    
</APP>
#endif
