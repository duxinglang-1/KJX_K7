#include "MMI_features.h"
#include "CustResDef.h"


<?xml version="1.0" encoding="UTF-8"?>
#ifdef __BT_MAP_CLIENT__
<APP id="SRV_SMS_BTMAPC">

    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

    <!-- String Resource Area-------------------------------------------------->
    <EVENT id="EVT_ID_SRV_SMS_BTMAPC_READY" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_BTMAPC_NEW_MSG" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_BTMAPC_MEM_EXCEED" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_BTMAPC_MEM_FULL" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_BTMAPC_ADD_MSG" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_BTMAPC_DEL_MSG" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_BTMAPC_UPDATE_MSG" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_BTMAPC_UPDATE_SENDING_ICON" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_BTMAPC_UPDATE_UNSENT_MSG_STATUS" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_BTMAPC_ASYNC_CALLBACK" type="SENDER"/>
</APP>
#endif