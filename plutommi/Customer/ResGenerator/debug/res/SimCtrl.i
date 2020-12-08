# 1 "temp/res/SimCtrl.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/SimCtrl.c"

# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 3 "temp/res/SimCtrl.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 4 "temp/res/SimCtrl.c" 2


<?xml version="1.0" encoding="UTF-8"?>


<APP id="APP_SIM_CTRL">





    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->


    <STRING id="STR_ID_SIM_CTRL_SIM_ACCESS_ERROR"/>
# 44 "temp/res/SimCtrl.c"
    <STRING id="STR_ID_SIM_CTRL_SIM_CAME_OFF"/>
# 62 "temp/res/SimCtrl.c"
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>


    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_SIM_CTRL"/>





    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="mmi_sim_ctrl_on_sim_availability_changed"/>





</APP>
