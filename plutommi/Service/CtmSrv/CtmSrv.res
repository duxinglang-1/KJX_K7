#ifdef __CTM_SUPPORT__
#include "MMI_features.h"
#ifdef DEVELOPER_BUILD_FIRST_PASS

<?xml version="1.0" encoding="UTF-8"?>

<APP id="SRV_CTM">

<!-----------------------------------------------------Event Resource Area----------------------------------------------------->
    <EVENT id="EVT_ID_SRV_CTM_INDICATION" type="SENDER"/>
    <RECEIVER id="EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND" proc="srv_ctm_speech_status_ind_hdlr"/>

<!-- 
**************************************** String section ***************************************
-->


<!-- 
**************************************** Screen section ***************************************
-->

<!-----------------------------------------------------MMI timer------------------------------------------------------>
	  <TIMER id="CM_AUTOANSWER_NOTIFYDURATION_TIMER"/>
	  <TIMER id="CM_GET_TIME_CALLBACK"/>
	  <TIMER id="CM_NOTIFYDURATION_TIMER"/>
	  <TIMER id="CM_CTM_ALERT_NOTIFYDURATION_TIMER"/> 
</APP>

#endif
#endif

