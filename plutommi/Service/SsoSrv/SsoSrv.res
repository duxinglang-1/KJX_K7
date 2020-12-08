/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "MMI_features.h"
#include "CustResDef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

#ifdef __MMI_SSO__
/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_SSO">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>
    
    <!-- String Resource Area-------------------------------------------------->

    <STRING id="STR_ID_SRV_SSO_BUSY"/>
    <STRING id="STR_ID_SRV_SSO_CONNECTION_FAIL"/>
    <STRING id="STR_ID_SRV_SSO_INCORRECT_ID_PW"/>
    <STRING id="STR_ID_SRV_SSO_NOT_FULL_EMAIL"/>
    <STRING id="STR_ID_SRV_SSO_CANCELLED"/>

    <!------------------------------------------------------Callback Manager---------------------------------------------------------->    

    <EVENT id="EVT_ID_SRV_SSO_READY"            type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SSO_LOGIN"            type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SSO_LOGOUT"           type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SSO_REFRESH"          type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SSO_PLUGINS_UPGRADED" type="SENDER"/>
        
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION"   proc="srv_sso_mmi_event_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN"  proc="srv_sso_mmi_event_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="srv_sso_mmi_event_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_READY"    proc="srv_sso_mmi_event_hdlr"/>    
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT"       proc="srv_sso_mmi_event_hdlr"/>    
#ifdef __MMI_USB_SUPPORT__
    <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE"                  proc="srv_sso_mmi_event_hdlr"/>
    <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE"                   proc="srv_sso_mmi_event_hdlr"/>
#endif

    <TIMER id="SRV_SSO_UPGRADE_TIMER"/>
    <TIMER id="SRV_SSO_CALLBACK_TIMER"/>

</APP>

#endif /* __MMI_SSO__ */