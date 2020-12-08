/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="SRV_SMS">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->

    <!-------------Resource for SMS template begin---------------------------------------------->
#ifdef __SRV_SMS_PREDEFINED_TEMPLATE__
    <STRING id="STR_ID_SRV_SMS_TEMPLATE_1"/>
    <STRING id="STR_ID_SRV_SMS_TEMPLATE_2"/>
    <STRING id="STR_ID_SRV_SMS_TEMPLATE_3"/>
    <STRING id="STR_ID_SRV_SMS_TEMPLATE_4"/>
    <STRING id="STR_ID_SRV_SMS_TEMPLATE_5"/>
    <STRING id="STR_ID_SRV_SMS_TEMPLATE_6"/>
    <STRING id="STR_ID_SRV_SMS_TEMPLATE_7"/>
    <STRING id="STR_ID_SRV_SMS_TEMPLATE_8"/>
    <STRING id="STR_ID_SRV_SMS_TEMPLATE_9"/>
    <STRING id="STR_ID_SRV_SMS_TEMPLATE_10"/>
#endif
    <!-------------Resource for SMS template end---------------------------------------------->

    <!-----------------SMS Service Events begin--------------------------------------------------->
    <EVENT id="EVT_ID_SRV_SMS_BEGIN"/>
    <EVENT id="EVT_ID_SRV_SMS_READY" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_NEW_MSG" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_NEW_MSG_WAITING" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_STATUS_REPORT" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_SIM_REFRESH" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_AT_CMD_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_MEM_EXCEED" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_MEM_FULL" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_MEM_AVAILABLE" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_ADD_MSG" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_DEL_MSG" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_UPDATE_MSG" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_UPDATE_SENDING_ICON" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_UPDATE_UNSENT_MSG_STATUS" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_API_SEND_MSG" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_UPDATE_COUNTER" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_REFRESH_MSG" type="SENDER"/>

    <EVENT id="EVT_ID_SRV_SMS_CLEAR_FOLDER" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_HIDE_LIST" type="SENDER"/>

    <EVENT id="EVT_ID_SRV_SMS_ADD_REPORT" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_DEL_REPORT" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_UPDATE_REPORT" type="SENDER"/>

    <EVENT id="EVT_ID_SRV_SMS_PS_NORMAL_IND" type="SENDER"/>
    
    <EVENT id="EVT_ID_SRV_SMS_PS_STORAGE_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_PS_RECEIVER_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_PS_AT_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_PS_CB_MSG_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_PS_CB_GS_CHANGE_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_ASYNC_CALLBACK" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_STARTUP_READ_ME_SMS" type="SENDER"/>
#ifdef __SMS_CLOUD_SUPPORT__
    <EVENT id="EVT_ID_SRV_SMS_BACKUP_RESTORE" type="SENDER"/>
#endif

#ifdef __SRV_SMS_TEMPLATE__
    <EVENT id="EVT_ID_SRV_SMS_ADD_TEMPLATE" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_DEL_TEMPLATE" type="SENDER"/>
#endif
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    <EVENT id="EVT_ID_SRV_TCARD_SMS_READY" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SMS_SAVE_STORAGE_STATUS" type="SENDER"/>
#endif
    <RECEIVER id="EVT_ID_SRV_SMS_PS_NORMAL_IND" proc="srv_sms_storage_event_proc"/>
    <RECEIVER id="EVT_ID_SRV_SMS_PS_NORMAL_IND" proc="srv_sms_setting_event_proc"/>
#ifdef __SRV_SMS_AT_SUPPORT__
    <RECEIVER id="EVT_ID_SRV_SMS_PS_AT_IND" proc="srv_sms_at_event_proc"/>
#endif

#ifdef __SRV_SMS_ARCHIVE__
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="srv_sms_fmgr_format_hdlr"/>
#endif /*__SRV_SMS_ARCHIVE__*/
    <RECEIVER id="EVT_ID_SRV_SMS_PS_RECEIVER_IND" proc="srv_sms_handle_normal_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="srv_sms_sim_status_changed_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SAT_SIM_REFRESH" proc="srv_sms_sim_refresh_event_hdlr"/>

#if ((defined(__SRV_SMS_ARCHIVE__) || defined(__SRV_SMS_TCARD_STORAGE_SUPPORT__))&& defined(__MMI_USB_SUPPORT__))
    <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="srv_sms_list_usb_evt_proc"/>
    <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="srv_sms_list_usb_evt_proc"/>
#endif

#ifdef __SRV_SMS_BACKGROUND_SEND_SUPPORT__
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="srv_sms_send_mode_switch_finish_event_hdlr"/>
#if defined(__SRV_SMS_BACKGROUND_AUTO_RESEND_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
    <RECEIVER id="EVT_ID_SRV_SMS_DEL_MSG" proc="srv_sms_send_from_storage_del_msg_proc"/>
#endif
#ifdef __DM_LAWMO_SUPPORT__
    <RECEIVER id="EVT_ID_SRV_DM_LAWMO_LOCK_IND" proc="srv_msg_lawmo_cancel_bg_send"/>
#endif
#endif

#ifdef __DM_LAWMO_SUPPORT__
    <RECEIVER id="EVT_ID_SRV_DM_LAWMO_WIPE_IND" proc="srv_msg_lawmo_delete_sms_data"/>
#endif

#ifdef __SMS_CLOUD_SUPPORT__
    <RECEIVER id="EVT_ID_SRV_CLD_BACKUP_BEGIN_IND" proc="srv_sms_backup_restore_event_hdlr"/><!--begin to put data-->
    <RECEIVER id="EVT_ID_SRV_CLD_GET_DATA_IND" proc="srv_sms_backup_restore_event_hdlr"/><!--begin to get data-->
    <RECEIVER id="EVT_ID_SRV_CLD_CLOSE_DONE_IND" proc="srv_sms_backup_restore_event_hdlr"/><!--close finish-->
    <RECEIVER id="EVT_ID_SRV_CLD_PUT_DATA_RES_IND" proc="srv_sms_backup_restore_event_hdlr"/><!--put data respond-->
    <RECEIVER id="EVT_ID_SRV_CLD_ERROR_IND" proc="srv_sms_backup_restore_event_hdlr"/><!--put data respond-->
    <RECEIVER id="EVT_ID_SRV_CLD_ASYNC_UID_DONE_IND" proc="srv_sms_backup_restore_event_hdlr"/><!--async uid done-->
#endif

#ifdef __SRV_SMS_PREDEFINED_TEMPLATE__
#ifdef _MUTILANG_TEMPLATE_
    <RECEIVER id="EVT_ID_SETTING_LANGUAGE_CHANGED" proc="srv_sms_template_language_changed_proc"/>
#endif
#endif
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    <RECEIVER id="EVT_ID_SRV_TCARD_READY" proc="srv_sms_tcard_event_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SMS_READY" proc="srv_sms_tcard_event_hdlr"/>
#endif   
    <!-----------------SMS Service Events end--------------------------------------------------->
    <!-------------timer id res---------------------------------------------->
    <TIMER id="MESSAGES_SMS_BOOTUP_TIMER_ID"/>
    <TIMER id="MESSAGES_CONTINUE_SEND_SMS_PROCESS_TIMER_ID"/>


    <!-----------------SMS Service id_timer begin--------------------------------------------------->
    <TIMER id="SRV_SMS_LMS_RECV_TIMER_ID"/>
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    <TIMER id="SRV_SMS_TCARD_ASYNC_TIMER_ID"/>    
#endif
    <!-----------------SMS Service id_timer end--------------------------------------------------->


    <!-----------------SMS Service mmi cache begin--------------------------------------------------->
    <CACHEDATA type="byte" id="NVRAM_SMS_ACTIVE_PROFILE_INDEX">
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

#ifdef __SRV_SMS_MULTI_SIM__
    <CACHEDATA type="byte" id="NVRAM_SIM2_ACTIVE_PROFILE_IDX">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
#endif

#if (MMI_MAX_SIM_NUM >= 3)
    <CACHEDATA type="byte" id="NVRAM_SIM3_ACTIVE_PROFILE_IDX">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
#endif

#if (MMI_MAX_SIM_NUM >= 4)
    <CACHEDATA type="byte" id="NVRAM_SIM4_ACTIVE_PROFILE_IDX">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
#endif

    <CACHEDATA type="byte" id="NVRAM_SMS_MISCELL_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X1B] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

#ifdef __SRV_SMS_PREFER_STORAGE_SETTING__
    <CACHEDATA type="byte" id="NVRAM_SMS_PREFER_STORAGE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> NVRAM_SMS_PREFER_STORAGE </DESCRIPTION>
    </CACHEDATA>
#endif

    <CACHEDATA type="short" id="NVRAM_SMS_CONCAT_MSG_REF_VALUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_SMSCOUNTERS_SENT_SHORT">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_SMSCOUNTERS_RECD_SHORT">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

#ifdef __SRV_SMS_MULTI_SIM__
    <CACHEDATA type="short" id="NVRAM_SIM2_SMSCOUNTERS_SENT">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_SIM2_SMSCOUNTERS_RECV">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
    
#if (MMI_MAX_SIM_NUM >= 3)
    <CACHEDATA type="short" id="NVRAM_SIM3_SMSCOUNTERS_SENT">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_SIM3_SMSCOUNTERS_RECV">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif

#if (MMI_MAX_SIM_NUM >= 4)
    <CACHEDATA type="short" id="NVRAM_SIM4_SMSCOUNTERS_SENT">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_SIM4_SMSCOUNTERS_RECV">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif
#endif

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    <CACHEDATA type="byte" id="NVRAM_SMS_STORAGE_FILTER">
        <DEFAULT_VALUE> [0x07] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif

    <!-----------------SMS Service mmi cache begin--------------------------------------------------->

</APP>

