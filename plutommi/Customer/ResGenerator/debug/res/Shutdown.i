# 1 "temp/res/Shutdown.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/Shutdown.c"

# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 3 "temp/res/Shutdown.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 4 "temp/res/Shutdown.c" 2


<?xml version="1.0" encoding="UTF-8"?>


<APP id="APP_SHUTDOWN">



    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->



    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>






    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>



    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_SHUTDOWN"/>
    <SCREEN id="SCR_ID_SHUTDOWN_BASE"/>
    <SCREEN id="SCR_ID_SHUTDOWN_ANIMATION"/>

    <RECEIVER id="EVT_ID_SRV_SHUTDOWN_NORMAL_START" proc="mmi_shutdown_normal_start"/>

    <TIMER id="SHUTDOWN_PROCESS_TIMER"/>

</APP>
