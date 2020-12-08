# 1 "temp/res/SmsSrv.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/SmsSrv.c"

# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 3 "temp/res/SmsSrv.c" 2

<?xml version="1.0" encoding="UTF-8"?>

<APP id="SRV_SMS">



    <!--Include Area-->

    <!-------------Resource for SMS template begin---------------------------------------------->
# 25 "temp/res/SmsSrv.c"
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
# 75 "temp/res/SmsSrv.c"
    <RECEIVER id="EVT_ID_SRV_SMS_PS_NORMAL_IND" proc="srv_sms_storage_event_proc"/>
    <RECEIVER id="EVT_ID_SRV_SMS_PS_NORMAL_IND" proc="srv_sms_setting_event_proc"/>

    <RECEIVER id="EVT_ID_SRV_SMS_PS_AT_IND" proc="srv_sms_at_event_proc"/>





    <RECEIVER id="EVT_ID_SRV_SMS_PS_RECEIVER_IND" proc="srv_sms_handle_normal_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="srv_sms_sim_status_changed_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SAT_SIM_REFRESH" proc="srv_sms_sim_refresh_event_hdlr"/>







    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="srv_sms_send_mode_switch_finish_event_hdlr"/>
# 125 "temp/res/SmsSrv.c"
    <!-----------------SMS Service Events end--------------------------------------------------->
    <!-------------timer id res---------------------------------------------->
    <TIMER id="MESSAGES_SMS_BOOTUP_TIMER_ID"/>
    <TIMER id="MESSAGES_CONTINUE_SEND_SMS_PROCESS_TIMER_ID"/>


    <!-----------------SMS Service id_timer begin--------------------------------------------------->
    <TIMER id="SRV_SMS_LMS_RECV_TIMER_ID"/>



    <!-----------------SMS Service id_timer end--------------------------------------------------->


    <!-----------------SMS Service mmi cache begin--------------------------------------------------->
    <CACHEDATA type="byte" id="NVRAM_SMS_ACTIVE_PROFILE_INDEX">
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
# 166 "temp/res/SmsSrv.c"
    <CACHEDATA type="byte" id="NVRAM_SMS_MISCELL_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X1B] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>


    <CACHEDATA type="byte" id="NVRAM_SMS_PREFER_STORAGE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> NVRAM_SMS_PREFER_STORAGE </DESCRIPTION>
    </CACHEDATA>


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
# 236 "temp/res/SmsSrv.c"
    <!-----------------SMS Service mmi cache begin--------------------------------------------------->

</APP>
