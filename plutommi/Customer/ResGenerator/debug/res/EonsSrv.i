# 1 "temp/res/EonsSrv.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/EonsSrv.c"
# 93 "temp/res/EonsSrv.c"
# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 94 "temp/res/EonsSrv.c" 2


# 1 "../customerinc/CustResDef.h" 1
# 191 "../customerinc/CustResDef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/CustResDef.h" 2
# 97 "temp/res/EonsSrv.c" 2

<?xml version="1.0" encoding="UTF-8"?>
<APP id="SRV_EONS">

    <!----- Include Area ------------------------------------------------------>


    <!----- String Resource Area ---------------------------------------------->


    <!----- Image Resource Area ----------------------------------------------->


    <!----- Screen Resource Area ---------------------------------------------->


    <!----- Menu Resource Area ------------------------------------------------>


    <!------------------------------------------------------Other Resource---------------------------------------------------------->






    <EVENT id="EVT_ID_SRV_EONS_UPDATED" type="SENDER"/>

    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="srv_eons_main_evt_hdlr"/>

    <RECEIVER id="EVT_ID_SRV_NW_INFO_LOCATION_CHANGED" proc="srv_eons_main_evt_hdlr"/>

    <RECEIVER id="EVT_ID_SRV_NW_NAME_SIM_CHANGED_BY_SAT" proc="srv_eons_main_evt_hdlr"/>
</APP>
