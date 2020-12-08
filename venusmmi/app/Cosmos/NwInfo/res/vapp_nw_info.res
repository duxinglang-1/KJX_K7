#include "mmi_features.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_NW_INFO" name="STR_ID_VAPP_NW_INFO_APP_NAME" type="venus">

    <STRING id="STR_ID_VAPP_NW_INFO_APP_NAME"/>
    <STRING id="STR_ID_VAPP_NW_INFO_INVALID_SIM_MSG"/>
#if (MMI_MAX_SIM_NUM >= 2)
    <STRING id="STR_ID_VAPP_NW_INFO_INVALID_SIMX_MSG"/>
#endif
    
    <MEMORY base="80000"/>
    
    <RECEIVER id="EVT_ID_SRV_NW_INFO_REGISTER_FAILED" proc="vapp_nw_info_on_register_failed"/>
    
    <RECEIVER id="EVT_ID_SRV_NW_INFO_STATUS_CHANGED" proc="mmi_nw_info_on_status_changed"/> // In NwInfoIcon.c
#ifdef __HOMEZONE_SUPPORT__
    // Cosmos does not support homezone icon yet
#endif

    <RECEIVER id="EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED" proc="vapp_nw_info_signal_on_service_avai_changed"/>
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="vapp_nw_info_signal_on_mode_switched"/>
    <RECEIVER id="EVT_ID_SRV_NW_INFO_SIGNAL_STRENGTH_CHANGED" proc="vapp_nw_info_signal_on_strength_changed"/>
    <RECEIVER id="EVT_ID_SRV_BOOTUP_SIM_SLOT_READY" proc="vapp_nw_info_icon_on_sim_slot_ready"/>

#if defined(__SIM_HOT_SWAP_SUPPORT__)
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED" proc="mmi_nw_info_icon_on_sim_event"/>
#endif
    
</APP>