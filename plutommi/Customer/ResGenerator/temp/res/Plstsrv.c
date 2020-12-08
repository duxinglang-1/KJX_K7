/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "MMI_features.h" 
#ifdef __PLST_SERVICE_DB_SUPPORT__

#include "CustResDef.h"         /* for image/audio path */

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_PLST">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file=" MMIDataType.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    /* Populate MediaPlayer String Start */
    <STRING id="STR_ID_SRV_PLST_UNKNOWN_ARTIST"/>
    <STRING id="STR_ID_SRV_PLST_UNKNOWN_ALBUM"/>
    <STRING id="STR_ID_SRV_PLST_UNKNOWN_GENRE"/>
    <STRING id="STR_ID_SRV_PLST_VERSION_WRONG"/>
    <STRING id="STR_ID_SRV_PLST_MAX_SERVICE_SUPPORT"/>
    <STRING id="STR_ID_SRV_PLST_MEMORY_CORRUPT"/>
    <STRING id="STR_ID_SRV_PLST_DB_CONRRPUT"/>
    <STRING id="STR_ID_SRV_PLST_GDI_ERR"/>
    <STRING id="STR_ID_SRV_PLST_META_PARSER_ERR"/>
    <STRING id="STR_ID_SRV_PLST_ITEM_EXIST"/>
    <STRING id="STR_ID_SRV_PLST_FS_ERR"/>
    <STRING id="STR_ID_SRV_PLST_PARAM_ERR"/>
    <STRING id="STR_ID_SRV_PLST_DESTORY_FAIL"/>
    <STRING id="STR_ID_SRV_PLST_SQLITE_ERR"/>
    <STRING id="STR_ID_SRV_PLST_FATAL_ERR"/>
    <STRING id="STR_ID_SRV_PLST_UNKNOWN_ERR"/>
    <STRING id="STR_ID_SRV_PLST_DB_NOMEM"/>
    <STRING id="STR_ID_SRV_PLST_DB_READ_ONLY"/>
    <STRING id="STR_ID_SRV_PLST_DB_CANNOT_OPEN"/>
    <STRING id="STR_ID_SRV_PLST_DB_EMPTY"/>
    <STRING id="STR_ID_SRV_PLST_PLST_ITEM_FULL"/>   
    <STRING id="STR_ID_SRV_PLST_DB_NOT_FOUND"/> 
    <STRING id="STR_ID_SRV_PLST_DB_ITEM_FULL"/> 
    <STRING id="STR_ID_SRV_PLST_DB_AUDIO_FULL"/> 
    <STRING id="STR_ID_SRV_PLST_DB_VIDEO_FULL"/> 



    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="srv_plst_service_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="srv_plst_service_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT" proc="srv_plst_service_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="srv_plst_service_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE" proc="srv_plst_service_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION" proc="srv_plst_service_notify_hdlr"/>
    #ifdef __MMI_USB_SUPPORT__
    <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="srv_plst_usb_plug_in_hdlr"/>
    <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="srv_plst_usb_plug_out_hdlr"/>
    #endif
</APP>
#endif

