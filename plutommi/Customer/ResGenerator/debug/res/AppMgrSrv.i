# 1 "temp/res/AppMgrSrv.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/AppMgrSrv.c"

# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 3 "temp/res/AppMgrSrv.c" 2


<?xml version="1.0" encoding="UTF-8"?>


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
