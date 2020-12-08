/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "MMI_features.h" 
#ifdef __MMI_PLAYLIST_SERVICE_SLIM__

#include "CustResDef.h"         /* for image/audio path */

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_PLST_SLIM">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file=" MMIDataType.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->


    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="srv_playlist_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="srv_playlist_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT" proc="srv_playlist_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="srv_playlist_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE" proc="srv_playlist_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION" proc="srv_playlist_notify_hdlr"/>
    #ifdef __MMI_USB_SUPPORT__
    <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="srv_playlist_usb_plug_out_hdlr"/>
    <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="srv_playlist_usb_plug_in_hdlr"/>
    #endif
</APP>
#endif