#include "mmi_features.h"
#ifdef __SRV_CBS_SUPPORT__
#include "custresdef.h"

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
#if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
 	<RECEIVER id="EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED" proc="srv_cbs_event_proc"/>
#endif /* (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)) */
</APP>
#endif

