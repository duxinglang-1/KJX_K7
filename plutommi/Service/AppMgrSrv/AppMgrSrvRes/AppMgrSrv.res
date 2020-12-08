/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_APPMGR">

    <SENDER id="EVT_ID_SRV_APPMGR_INSTALL_PACKAGE" hfile="AppMgrSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE" hfile="AppMgrSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE" hfile="AppMgrSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_APPMGR_UPDATE_BADGE" hfile="AppMgrSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_APPMGR_UPDATE_ALL_INSTALLED_PACKAGE" hfile="AppMgrSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_APPMGR_INSTALL_START" hfile="AppMgrSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_APPMGR_INSTALL_PROGRESS" hfile="AppMgrSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_APPMGR_INSTALL_FINISH" hfile="AppMgrSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_APPMGR_INSTALL_ERROR" hfile="AppMgrSrvGprot.h"/>

    <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="srv_appmgr_cb_evt_hdlr"/>
    <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="srv_appmgr_cb_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="srv_appmgr_cb_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="srv_appmgr_cb_evt_hdlr"/>

</APP>

