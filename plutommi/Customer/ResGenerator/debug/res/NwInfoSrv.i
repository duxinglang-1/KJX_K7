# 1 "temp/res/NwInfoSrv.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/NwInfoSrv.c"

# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 3 "temp/res/NwInfoSrv.c" 2


<?xml version="1.0" encoding="UTF-8"?>


<APP id="SRV_NW_INFO">

    <SENDER id="EVT_ID_SRV_NW_INFO_STATUS_CHANGED" hfile="NwInfoSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED" hfile="NwInfoSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_NW_INFO_SIGNAL_STRENGTH_CHANGED" hfile="NwInfoSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_NW_INFO_LOCATION_CHANGED" hfile="NwInfoSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_NW_INFO_ROAMING_STATUS_CHANGED" hfile="NwInfoSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_NW_INFO_PROTOCOL_CAPABILITY_CHANGED" hfile="NwInfoSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_NW_INFO_SIM_DN_STATUS_CHANGED" hfile="NwInfoSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_NW_INFO_REGISTER_FAILED" hfile="NwInfoSrvGprot.h"/>







    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="srv_nw_info_on_sim_availability_changed"/>
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="srv_nw_info_notify_mode_changed"/>



    <TIMER id="TIMER_ID_SRV_NW_INFO_SIGNAL_ANIMATION"/>

</APP>
