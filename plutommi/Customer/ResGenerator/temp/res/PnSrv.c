<?xml version="1.0" encoding="UTF-8"?>

#include "MMI_features.h" 

#ifdef __MMI_PNS__
<APP id="SRV_PNS">
    <INCLUDE file="GlobalResDef.h"/>

<!-- 
**************************************** String section ***************************************
-->
    <STRING id="STR_ID_PNS_BACKGROUND_DATA_ON"/>
    <STRING id="STR_ID_PNS_SEND_DEVICE_INFO_QUERY"/>
    <STRING id="STR_ID_PNS_OPEN_NS"/>

    <!-- Event registration -->
	<SENDER id="EVT_ID_SRV_PNS_START_REGISTER"       hfile="PnSrvGProt.h" />
	<SENDER id="EVT_ID_SRV_PNS_ENTER_NS"             hfile="PnSrvGProt.h" />
	
    <RECEIVER id="EVT_ID_SRV_PNS_START_REGISTER"     proc="srv_pns_broadcast_receiver" />
    <RECEIVER id="EVT_ID_SRV_PNS_ENTER_NS"     proc="srv_pns_broadcast_receiver" />
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY"     proc="srv_pns_broadcast_receiver" />
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED" proc="srv_pns_broadcast_receiver"/>
    <RECEIVER id="EVT_ID_SRV_CBM_BEARER_INFO" proc="srv_pns_broadcast_receiver"/>

    <!-- NVRAM related -->
    <CACHEDATA type="byte" id="NVRAM_PNS_INTERVAL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION>Push notification interval</DESCRIPTION>
    </CACHEDATA>
    <CACHEDATA type="byte" id="NVRAM_PNS_SWITCH" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION>Switch push notification</DESCRIPTION>
    </CACHEDATA>
    <CACHEDATA type="byte" id="NVRAM_PNS_CHANGE_SIM" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION>Flag of SIM changed</DESCRIPTION>
    </CACHEDATA>
</APP>
#endif
