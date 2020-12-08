<?xml version="1.0" encoding="UTF-8"?>

#include "MMI_features.h" 

<APP id="SRV_REMINDER">
	<EVENT id="EVT_ID_SRV_REMINDER_BOOTUP_START" type="SENDER"/>
	<EVENT id="EVT_ID_SRV_REMINDER_BOOTUP_INIT"	type="SENDER"/>
	<EVENT id="EVT_ID_SRV_REMINDER_BOOTUP_COMPLETE" type="SENDER"/>
	<EVENT id="EVT_ID_SRV_REMINDER_NOTIFY" type="SENDER"/>
	<EVENT id="EVT_ID_SRV_REMINDER_PWRRESET_REQ" type="SENDER"/>
	
	<RECEIVER id="EVT_ID_SRV_DATETIME_CHANGE" proc="srv_reminder_on_time_change_notify"/>
	<RECEIVER id="EVT_ID_SRV_REMINDER_BOOTUP_COMPLETE" proc="srv_reminder_on_bootup_notify"/>
	<RECEIVER id="EVT_ID_SRV_SHUTDOWN_NORMAL_START" proc="srv_reminder_on_shutdown_notify"/>
	
#ifdef  MOTION_SENSOR_SUPPORT
	<CACHEDATA type="byte" id="NVRAM_REMINDER_TURNOVER_SENSOR_STATE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X01] </DEFAULT_VALUE>
        <DESCRIPTION> current value 0,1 </DESCRIPTION>
    </CACHEDATA>
#endif
    
</APP>
