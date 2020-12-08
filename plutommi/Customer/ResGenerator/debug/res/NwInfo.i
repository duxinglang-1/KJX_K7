# 1 "temp/res/NwInfo.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/NwInfo.c"

# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 3 "temp/res/NwInfo.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 4 "temp/res/NwInfo.c" 2


<?xml version="1.0" encoding="UTF-8"?>


<APP id="APP_NW_INFO">



    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>
# 55 "temp/res/NwInfo.c"
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="mmi_nw_info_on_sim_availablity_changed"/>
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="mmi_nw_info_signal_on_mode_switched"/>
    <RECEIVER id="EVT_ID_SRV_NW_INFO_STATUS_CHANGED" proc="mmi_nw_info_on_status_changed"/>
    <RECEIVER id="EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED" proc="mmi_nw_info_signal_on_service_avai_changed"/>



    <RECEIVER id="EVT_ID_SRV_NW_INFO_SIGNAL_STRENGTH_CHANGED" proc="mmi_nw_info_signal_on_strength_changed"/>
# 81 "temp/res/NwInfo.c"
</APP>
