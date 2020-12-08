/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="SRV_TCARD">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
     <!----------------- Timer Id ------------------------------------------> 
    <TIMER id="SRV_TCARD_START_INIT_FOR_USB_IN_TIMER_ID"/> 
    <TIMER id="SRV_TCARD_ASYNC_TIMER_ID"/>
    <!-----------------Tcard Service Events begin--------------------------------------------------->
    <EVENT id="EVT_ID_SRV_TCARD_READY" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_TCARD_ASYNC_CALLBACK" type="SENDER"/>
    
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="srv_tcard_event_proc"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="srv_tcard_event_proc"/>
    
    
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="srv_tcard_format_evt_proc"/>
    #if (defined(__SRV_TCARD_DATA_STORE__)&& defined(__MMI_USB_SUPPORT__))
    <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="srv_tcard_usb_evt_proc"/>
    <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="srv_tcard_usb_evt_proc"/>
    #endif
    <!-----------------Tcard Service Events end--------------------------------------------------->

</APP>