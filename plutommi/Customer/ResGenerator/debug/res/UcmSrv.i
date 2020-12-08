# 1 "temp/res/UcmSrv.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/UcmSrv.c"
<?xml version="1.0" encoding="UTF-8"?>

# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 4 "temp/res/UcmSrv.c" 2

<APP id="SRV_UCM">
    <INCLUDE file="GlobalResDef.h"/>

<!--
**************************************** String section ***************************************
-->

    <STRING id="STR_ID_SRV_UCM_RESULT_USER_ABORT"/>
    <STRING id="STR_ID_SRV_UCM_RESULT_EMPTY_NUMBER"/>
    <STRING id="STR_ID_SRV_UCM_RESULT_CALLED_PARTY_BUSY"/>
    <STRING id="STR_ID_SRV_UCM_RESULT_NETWORK_NOT_AVAILABLE"/>
    <STRING id="STR_ID_SRV_UCM_RESULT_CALLED_PARTY_NOT_ANSWERED"/>
    <STRING id="STR_ID_SRV_UCM_RESULT_UCM_BUSY"/>
    <STRING id="STR_ID_SRV_UCM_RESULT_CANCEL"/>
    <STRING id="STR_ID_SRV_UCM_RESULT_FLIGHT_MODE_PROHIBIT"/>
    <STRING id="STR_ID_SRV_UCM_RESULT_PREFERRED_MODE_PROHIBIT"/>
    <STRING id="STR_ID_SRV_UCM_RESULT_SOS_CALL_EXISTS"/>
    <STRING id="STR_ID_SRV_UCM_RESULT_SOS_NUMBER_ONLY"/>
    <STRING id="STR_ID_SRV_UCM_RESULT_LOW_BATTERY"/>
    <STRING id="STR_ID_SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL"/>
    <STRING id="STR_ID_SRV_UCM_RESULT_NOT_ALLOWED_TO_ACCEPT"/>
    <STRING id="STR_ID_SRV_UCM_RESULT_ACTION_NOT_ALLOWED"/>
    <STRING id="STR_ID_SRV_UCM_RESULT_NO_ACTIVE_CALL"/>


<!--
**************************************** Other Resource ***************************************
-->
    <TIMER id="UCM_CONFIRM_TIMER_ID"/>
    <TIMER id="UCM_AUTO_REDIAL_TIMER"/>
    <TIMER id="UCM_SEND_DTMF_TIMER"/>
    <TIMER id="UCM_AUTO_ANSWER_MACHINE_TIMER"/>
    <TIMER id="UCM_AUTO_ANSWER_MACHINE_END_TIMER"/>

</APP>
