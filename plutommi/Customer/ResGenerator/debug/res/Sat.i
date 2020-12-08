# 1 "temp/res/Sat.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/Sat.c"
# 93 "temp/res/Sat.c"
# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 94 "temp/res/Sat.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 95 "temp/res/Sat.c" 2


<?xml version="1.0" encoding="UTF-8"?>


<APP id="SRV_SAT">



    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------Event Resource Area----------------------------------------------------->


    <!-----------------------------------------------------String Resource Area----------------------------------------------------->

    <STRING id="STR_ID_SAT_MENU_TITLE"/>

    <STRING id="STR_ID_SAT_PLAY_TONE"/>
    <STRING id="STR_ID_SAT_SEND_SMS"/>
    <STRING id="STR_ID_SAT_SEND_SS"/>
    <STRING id="STR_ID_SAT_SEND_USSD"/>
    <STRING id="STR_ID_SAT_SETUP_CALL_CONFIRM"/>



    <STRING id="STR_ID_SAT_SEND_DTMF"/>
# 133 "temp/res/Sat.c"
    <STRING id="STR_ID_SAT_NEXT_ACTION_SEND_SMS"/>
    <STRING id="STR_ID_SAT_NEXT_ACTION_SETUP_CALL"/>
    <STRING id="STR_ID_SAT_NEXT_ACTION_LAUNCH_BROWSER"/>
    <STRING id="STR_ID_SAT_NEXT_ACTION_PROVIDE_LOCAL_INFORMATION"/>
    <STRING id="STR_ID_SAT_NEXT_ACTION_PROVIDE_LOCAL_INFO"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>





    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>


    <!--Menu Tree Area-->






    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SENDER id="EVT_ID_SRV_SAT_PROACTIVE_SIM" hfile="SatSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_SAT_SETUP_MENU" hfile="SatSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_SAT_SETUP_IDLE_DISPLAY" hfile="SatSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_SAT_SIM_REFRESH" hfile="SatSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_SAT_SESSION_END" hfile="SatSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_SAT_SIM_CTRL_INFO" hfile="SatSrvGprot.h"/>

    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_UNAVAILABLE" proc="srv_sat_sim_unavailable_hdlr"/>

    <TIMER id="SAT_MESSAGE_WAIT_TIMER"/>
    <TIMER id="SAT_PLAY_TONE_TIMER"/>

</APP>
