<?xml version="1.0" encoding="UTF-8"?>

#include "MMI_features.h" 

<APP id="SRV_ALARM">
	
	<EVENT id="EVT_ID_SRV_ALM_OP" type="SENDER"/>
	
	<RECEIVER id="EVT_ID_SRV_REMINDER_NOTIFY" proc="srv_alm_notify_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_SHUTDOWN_FINAL_DEINIT" proc="srv_alm_notify_hdlr"/>
	
</APP>
