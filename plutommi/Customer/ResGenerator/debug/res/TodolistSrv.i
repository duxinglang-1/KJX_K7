# 1 "temp/res/TodolistSrv.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/TodolistSrv.c"


<?xml version="1.0" encoding="UTF-8"?>

# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 6 "temp/res/TodolistSrv.c" 2




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


        <RECEIVER id="EVT_ID_SRV_TDL_LOCAL_EVENT_SEARCH" proc="srv_tdl_local_event_async_search_proc"/>





        <CACHEDATA type="byte" id="NVRAM_TODO_SRV_SNS_REMINDER_SOURCE">
            <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
            <DESCRIPTION> sns_source_id; </DESCRIPTION>
        </CACHEDATA>
        <CACHEDATA type="short" id="NVRAM_TODO_SRV_SNS_REMINDER_ID_H">
            <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
            <DESCRIPTION> reminder id high 2 bytes; </DESCRIPTION>
        </CACHEDATA>
        <CACHEDATA type="short" id="NVRAM_TODO_SRV_SNS_REMINDER_ID_L">
            <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
            <DESCRIPTION> reminder id low 2 bytes; </DESCRIPTION>
        </CACHEDATA>

</APP>
