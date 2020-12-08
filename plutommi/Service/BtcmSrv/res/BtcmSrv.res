<?xml version="1.0" encoding="UTF-8"?>

#include "MMI_features.h" 

<APP id="SRV_BTCM">
#ifdef __MMI_BT_SUPPORT__
    <TIMER id="BT_CMD_GUARD_TIMER"/>
    <TIMER id="BT_POWER_OFF_GUARD_TIMER"/>
    <TIMER id="BT_RELEASE_ALL_CON_GUARD_TIMER"/>
    <TIMER id="BT_TEMP_VISIBLE_TIMER"/>
    <TIMER id="BT_FTPC_BROWSE_FILES_FAILED_TIMER"/>

    <!-- Event registration -->
    <RECEIVER id="EVT_ID_SRV_SETTING_UART_SETTING_CHANGED" proc="srv_bt_cm_uart_hdlr" />
#ifdef __DM_LAWMO_SUPPORT__
    <RECEIVER id="EVT_ID_SRV_DM_LAWMO_LOCK_IND" proc="srv_bt_cm_lawmo_lock_ind_hdlr" />
#endif
#ifdef __MMI_HFP_SUPPORT__
    <RECEIVER id="EVT_ID_SRV_UCM_INDICATION" proc="btaud_ucm_notify_hdlr" />
    <RECEIVER id="EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND" proc="btaud_speech_notify_hdlr" />
#endif
#endif
</APP>

