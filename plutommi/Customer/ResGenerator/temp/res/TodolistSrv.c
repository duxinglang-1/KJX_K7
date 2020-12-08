

<?xml version="1.0" encoding="UTF-8"?>

#include "MMI_features.h" 

//#ifdef __MMI_SRV_TODOLIST__
#if ((defined(__MMI_CALENDAR_EVENT__) || defined(__MMI_TODOLIST__)) && !defined(__COSMOS_MMI_PACKAGE__)) || defined(__COSMOS_MMI_PACKAGE__)

<APP id="SRV_TODOLIST">
    <TIMER id="TIMER_ID_SRV_TDL_SEARCH_1"/>
    <TIMER id="TIMER_ID_SRV_TDL_SEARCH_2"/>
    <TIMER id="TIMER_ID_SRV_TDL_SEARCH_3"/>
    <TIMER id="TIMER_ID_SRV_TDL_SEARCH_4"/>
    <TIMER id="TIMER_ID_SRV_TDL_SEARCH_5"/>
    <TIMER id="TIMER_ID_SRV_TDL_SEARCH_6"/>
    <TIMER id="TIMER_ID_SRV_TDL_SEARCH_7"/>
    
	<SENDER id="EVT_ID_SRV_TDL_OP" hfile="TodolistSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_TDL_EVENT_SEARCH" hfile="TodolistSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_TDL_EVENT_OP" hfile="TodolistSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_TDL_LOCAL_EVENT_SEARCH" hfile="TodolistSrvGprot.h"/>

#if (defined(__MMI_CALENDAR_EVENT__) && !defined(__COSMOS_MMI_PACKAGE__)) || defined(__COSMOS_MMI_PACKAGE__)
	<RECEIVER id="EVT_ID_SRV_TDL_LOCAL_EVENT_SEARCH" proc="srv_tdl_local_event_async_search_proc"/>	
#ifdef __MMI_SNS_CALENDAR__	
	<RECEIVER id="EVT_ID_SRV_REMINDER_NOTIFY" proc="srv_tdl_sns_reminder_notify_hdlr"/>
#endif	
#endif

	<CACHEDATA type="byte" id="NVRAM_TODO_SRV_SNS_REMINDER_SOURCE">
	    <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
	    <DESCRIPTION> sns_source_id;  </DESCRIPTION>
	</CACHEDATA>
	<CACHEDATA type="short" id="NVRAM_TODO_SRV_SNS_REMINDER_ID_H">
	    <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
	    <DESCRIPTION> reminder id high 2 bytes;  </DESCRIPTION>
	</CACHEDATA>
	<CACHEDATA type="short" id="NVRAM_TODO_SRV_SNS_REMINDER_ID_L">
	    <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
	    <DESCRIPTION> reminder id low 2 bytes;  </DESCRIPTION>
	</CACHEDATA>

</APP>

#endif

