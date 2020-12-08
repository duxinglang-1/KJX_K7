/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>
<APP id="SRV_UNIFIEDMESSAGE">

    <!------------------------------------------------------Other Resource---------------------------------------------------------->

	<SENDER id="EVT_ID_SRV_UM_NOTIFY_READY" hfile="UmSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_UM_NOTIFY_HIGHLIGHT_MSG" hfile="UmSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_UM_NOTIFY_REFRESH" hfile="UmSrvGprot.h"/>

#if defined(__MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && defined(__MMI_MMS_IN_UM__)
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="mmi_um_sd_card_plug_in_out_hdlr"/>     
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_um_sd_card_plug_in_out_hdlr"/>     
#endif

	<RECEIVER id="EVT_ID_SETTING_LANGUAGE_CHANGED" proc="srv_um_receive_event"/>
#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
	<RECEIVER id="EVT_ID_SRV_DATETIME_CHANGE" proc="srv_um_on_time_change_event"/>
#endif

    <TIMER id="SRV_UM_SEND_MSG_TIMER_ID"/>

#if (defined(__OP01__) && (MMI_MAX_SIM_NUM >= 2))
    <CACHEDATA type="byte" id="NVRAM_UM_PREFER_SIM" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> UM prefer SIM</DESCRIPTION>
    </CACHEDATA>
#endif /* __MMI_UM_CONVERSATION_BOX__ */

</APP>

