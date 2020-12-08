# 1 "temp/res/NwNameSrv.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/NwNameSrv.c"
# 104 "temp/res/NwNameSrv.c"
# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 105 "temp/res/NwNameSrv.c" 2
# 1 "../customerinc/CustResDef.h" 1
# 191 "../customerinc/CustResDef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/CustResDef.h" 2
# 106 "temp/res/NwNameSrv.c" 2


<?xml version="1.0" encoding="UTF-8"?>
<APP id="SRV_NW_NAME">

    <!----- Include Area ------------------------------------------------------>


    <!----- String Resource Area ---------------------------------------------->
    <STRING id="STR_ID_NWNAME_LIMITED_SERVICE"/>
    <STRING id="STR_ID_NWNAME_INVALID_SIM"/>
    <STRING id="STR_ID_NWNAME_NO_SERVICE"/>
    <STRING id="STR_ID_NWNAME_INSERT_SIM"/>
    <STRING id="STR_ID_NWNAME_SIM_ACCESS_ERROR"/>
    <STRING id="STR_ID_NWNAME_SIM_BLOCKED"/>
    <STRING id="STR_ID_NWNAME_SIM_DISCONNECTED"/>
    <STRING id="STR_ID_NWNAME_SIM_ACCESS_PROFILE"/>
    <STRING id="STR_ID_NWNAME_SELECT_NETWORK"/>
    <STRING id="STR_ID_NWNAME_FLIGHT_MODE"/>
    <STRING id="STR_ID_NWNAME_SIM_CLOSED"/>
    <STRING id="STR_ID_NWNAME_INVALID_IMEI"/>
    <STRING id="STR_ID_NWNAME_SAME_IMEI"/>
    <STRING id="STR_ID_NWNAME_PREPAREING_SIM_CARD"/>

    <!----- Image Resource Area ----------------------------------------------->


    <!----- Screen Resource Area ---------------------------------------------->


    <!----- Menu Resource Area ------------------------------------------------>


    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="srv_nw_name_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED" proc="srv_nw_name_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_NW_INFO_LOCATION_CHANGED" proc="srv_nw_name_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_EONS_UPDATED" proc="srv_nw_name_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SAT_SIM_REFRESH" proc="srv_nw_name_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED" proc="srv_nw_name_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="srv_nw_name_main_evt_hdlr"/>

    <RECEIVER id="EVT_ID_NITZ_NW_NAME_UPDATE_NOTIFY" proc="srv_nw_name_main_evt_hdlr"/>
# 158 "temp/res/NwNameSrv.c"
    <EVENT id="EVT_ID_SRV_NW_NAME_CHANGED" type="SENDER"/>






    <EVENT id="EVT_ID_SRV_NW_NAME_SIM_CHANGED_BY_SAT" type="SENDER"/>
</APP>
