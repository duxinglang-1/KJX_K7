# 1 "temp/res/CbsSrv.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/CbsSrv.c"
# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 2 "temp/res/CbsSrv.c" 2

# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 4 "temp/res/CbsSrv.c" 2

<?xml version="1.0" encoding="UTF-8"?>

<APP id="SRV_CBS">
    <!--Include Area-->

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    <!--Menu Item Area-->

    <!--Menu Tree Area-->


    <!------------------------------------------------------Other Resource---------------------------------------------------------->

    <!-----------------------------------------------Callback Manager Register------------------------------------------------------>
        <EVENT id="EVT_ID_SRV_CBS_READY_IND" type="SENDER"/>
        <EVENT id="EVT_ID_SRV_CBS_NEW_MSG_IND" type="SENDER"/>
        <EVENT id="EVT_ID_SRV_CBS_GS_CHANGE_IND" type="SENDER"/>
        <EVENT id="EVT_ID_SRV_CBS_ADD_MSG" type="SENDER"/>
        <EVENT id="EVT_ID_SRV_CBS_DEL_MSG" type="SENDER"/>
        <EVENT id="EVT_ID_SRV_CBS_ADD_CHNL" type="SENDER"/>
        <EVENT id="EVT_ID_SRV_CBS_DEL_CHNL" type="SENDER"/>
        <EVENT id="EVT_ID_SRV_CBS_UPDATE_CHNL" type="SENDER"/>
        <EVENT id="EVT_ID_SRV_CBS_MODE_CHANGE" type="SENDER"/>
        <EVENT id="EVT_ID_SRV_CBS_INIT_OP_IND" type="SENDER"/>

        <RECEIVER id="EVT_ID_SRV_SMS_PS_NORMAL_IND" proc="srv_cbs_event_proc"/>
        <RECEIVER id="EVT_ID_SRV_SMS_PS_CB_MSG_IND" proc="srv_cbs_event_proc"/>
        <RECEIVER id="EVT_ID_SRV_SMS_PS_CB_GS_CHANGE_IND" proc="srv_cbs_event_proc"/>
    <RECEIVER id="EVT_ID_SRV_SAT_SIM_REFRESH" proc="srv_cbs_sim_refresh_event_hdlr"/>



</APP>
