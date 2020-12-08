/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="SRV_CALLSET">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->

    <!-----------------------------------------------------Event Resource Area----------------------------------------------------->
    <EVENT id="EVT_ID_SRV_CALLSET_ACT_RESPONSE"/>
    <EVENT id="EVT_ID_SRV_CALLSET_LINE_SWITCHED" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_CALLSET_CFU_STATUS_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_CALLSET_CTM_SETTING_CHANGED" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_CALLSET_INT_ACT"/>
    
    #ifdef MOTION_SENSOR_SUPPORT
    <EVENT id="EVT_ID_SRV_FLIP_TO_MUTE_CALL" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_TAP_TAP_TO_RECORD_IN_CALL" type="SENDER"/>
    #endif
    
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="srv_callset_hdlr_sim_availability_changed"/>
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="srv_callset_hdlr_mode_switched"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */

    <STRING id="STR_ID_SRV_CALLSET_RESULT_FULL"/>
    <STRING id="STR_ID_SRV_CALLSET_RESULT_TOO_LONG"/>
    <STRING id="STR_ID_SRV_CALLSET_RESULT_DUPLICATED"/>
    <STRING id="STR_ID_SRV_CALLSET_RESULT_EMPTY"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    /* For the detail of scope="XML" please check user manual */



    <!-----------------------------------------------------MMI cache Resource Area------------------------------------------------------>
#ifdef __MMI_CALLSET_CALLER_ID__
    <CACHEDATA type="byte" id="NVRAM_CALLSET_CALLERID" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X02] </DEFAULT_VALUE>
        <DESCRIPTION> Caller ID value </DESCRIPTION>
    </CACHEDATA>
#if (MMI_MAX_SIM_NUM >= 2)
    <CACHEDATA type="byte" id="NVRAM_CALLSET_SIM2_CALLERID" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X02] </DEFAULT_VALUE>
        <DESCRIPTION> SIM2 caller ID value </DESCRIPTION>
    </CACHEDATA>
#if (MMI_MAX_SIM_NUM >= 3)
	<CACHEDATA type="byte" id="NVRAM_CALLSET_SIM3_CALLERID" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X02] </DEFAULT_VALUE>
        <DESCRIPTION> SIM3 caller ID value </DESCRIPTION>
    </CACHEDATA>
	#if (MMI_MAX_SIM_NUM >= 4)
	<CACHEDATA type="byte" id="NVRAM_CALLSET_SIM4_CALLERID" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X02] </DEFAULT_VALUE>
        <DESCRIPTION> SIM4 caller ID value </DESCRIPTION>
    </CACHEDATA>
#endif /*MMI_MAX_SIM_NUM>=4*/
#endif /*MMI_MAX_SIM_NUM>=3*/
#endif /* (MMI_MAX_SIM_NUM >= 2) */
#endif /* __MMI_CALLSET_CALLER_ID__ */

#ifdef __MMI_CALLSET_CUG__
    <CACHEDATA type="byte" id="NVRAM_CALLSET_CUG_ACTIVATED_ID" restore_flag="TRUE">
        <DEFAULT_VALUE> [0Xff] </DEFAULT_VALUE>
        <DESCRIPTION> CUG activated ID </DESCRIPTION>
    </CACHEDATA>
#if (MMI_MAX_SIM_NUM >= 2)
    <CACHEDATA type="byte" id="NVRAM_CALLSET_CUG_SIM2_ACTIVATED_ID" restore_flag="TRUE">
        <DEFAULT_VALUE> [0Xff] </DEFAULT_VALUE>
        <DESCRIPTION> CUG SIM2 activated ID </DESCRIPTION>
    </CACHEDATA>
#if (MMI_MAX_SIM_NUM >= 3)
	<CACHEDATA type="byte" id="NVRAM_CALLSET_CUG_SIM3_ACTIVATED_ID" restore_flag="TRUE">
        <DEFAULT_VALUE> [0Xff] </DEFAULT_VALUE>
        <DESCRIPTION> CUG SIM3 activated ID </DESCRIPTION>
    </CACHEDATA>
#if (MMI_MAX_SIM_NUM >= 4)
	<CACHEDATA type="byte" id="NVRAM_CALLSET_CUG_SIM4_ACTIVATED_ID" restore_flag="TRUE">
        <DEFAULT_VALUE> [0Xff] </DEFAULT_VALUE>
        <DESCRIPTION> CUG SIM4 activated ID </DESCRIPTION>
    </CACHEDATA>
#endif /*MMI_MAX_SIM_NUM>=4*/
#endif /*MMI_MAX_SIM_NUM>=3*/
#endif /* (MMI_MAX_SIM_NUM >= 2) */
#endif /* __MMI_CALLSET_CUG__ */

    <CACHEDATA type="byte" id="NVRAM_CALLSET_CTR_MODE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
        <DESCRIPTION> Call time reminder mode </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_CALLSET_ANSWER_MODE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
        <DESCRIPTION> Answer mode </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_CALLSET_CALL_TIME_DISPLAY" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X01] </DEFAULT_VALUE>
        <DESCRIPTION> Call time display </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_CALLSET_REDIAL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
        <DESCRIPTION> Auto redial mode </DESCRIPTION>
    </CACHEDATA>

#ifdef __MMI_UCM_REJECT_BY_SMS__
    <CACHEDATA type="byte" id="NVRAM_CALLSET_REJ_BY_SMS" restore_flag="TRUE">
    #ifdef __OP01__ /* reject by sms default on for operator requirement */
        <DEFAULT_VALUE> [0X01] </DEFAULT_VALUE>
    #else
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
    #endif
        <DESCRIPTION> Reject by SMS </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_CALLSET_REJ_BY_SMS_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
        <DESCRIPTION> Reject by SMS setting </DESCRIPTION>
    </CACHEDATA>
#endif /* __MMI_UCM_REJECT_BY_SMS__ */

#ifdef __MMI_CONNECT_NOTICE__
    <CACHEDATA type="byte" id="NVRAM_CALLSET_CONNECT_NOTICE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X01] </DEFAULT_VALUE>
        <DESCRIPTION> Connect notice </DESCRIPTION>
    </CACHEDATA>
#endif /* __MMI_CONNECT_NOTICE__ */

#ifdef __IP_NUMBER__
    <CACHEDATA type="byte" id="NVRAM_CALLSET_IP_NUMBER_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> IP number setting </DESCRIPTION>
    </CACHEDATA>
#if (MMI_MAX_SIM_NUM >= 2)
    <CACHEDATA type="byte" id="NVRAM_CALLSET_IP_NUMBER_SETTING_SIM2" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> IP number setting - sim2 </DESCRIPTION>
    </CACHEDATA>
#if (MMI_MAX_SIM_NUM >= 3)
	<CACHEDATA type="byte" id="NVRAM_CALLSET_IP_NUMBER_SETTING_SIM3" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> IP number setting - sim3 </DESCRIPTION>
    </CACHEDATA>
#if (MMI_MAX_SIM_NUM >= 4)
	<CACHEDATA type="byte" id="NVRAM_CALLSET_IP_NUMBER_SETTING_SIM4" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> IP number setting - sim4 </DESCRIPTION>
    </CACHEDATA>
#endif /*MMI_MAX_SIM_NUM>=4*/
#endif /*MMI_MAX_SIM_NUM>=3*/
#endif /* (MMI_MAX_SIM_NUM >= 2) */
#endif /* __IP_NUMBER__ */

#ifdef __MMI_CM_BLACK_LIST__
    <CACHEDATA type="byte" id="NVRAM_CALLSET_BLACKLIST_MODE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Black list setting </DESCRIPTION>
    </CACHEDATA>

#ifdef __MMI_CM_BLACK_LIST_EXT__
#ifdef __MMI_VIDEO_TELEPHONY__
    <CACHEDATA type="byte" id="NVRAM_CALLSET_BLACKLIST_MODE_VIDEO" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Black list setting for video call </DESCRIPTION>
    </CACHEDATA>
#endif /* __MMI_VIDEO_TELEPHONY__ */
#endif/* __MMI_CM_BLACK_LIST_EXT__ */
#endif /* __MMI_CM_BLACK_LIST__ */

#ifdef __MMI_CM_WHITE_LIST__
    <CACHEDATA type="byte" id="NVRAM_CALLSET_WHITELIST_MODE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> White list setting </DESCRIPTION>
    </CACHEDATA>

#ifdef __MMI_CM_WHITE_LIST_EXT__
#ifdef __MMI_VIDEO_TELEPHONY__
    <CACHEDATA type="byte" id="NVRAM_CALLSET_WHITELIST_MODE_VIDEO" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> White list setting for video call </DESCRIPTION>
    </CACHEDATA>
#endif /* __MMI_VIDEO_TELEPHONY__ */
#endif/* __MMI_CM_WHITE_LIST_EXT__ */
#endif /* __MMI_CM_WHITE_LIST__ */

    <CACHEDATA type="byte" id="NVRAM_CALLSET_QUICK_END_FLAG" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
        <DESCRIPTION> Auto quick end </DESCRIPTION>
    </CACHEDATA>

#ifdef __CTM_SUPPORT__
    <CACHEDATA type="byte" id="NVRAM_CALLSET_CTM_MODE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> CTM mode </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_CALLSET_CTM_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> CTM setting </DESCRIPTION>
    </CACHEDATA>
#endif /* __CTM_SUPPORT__ */

#ifdef __MMI_VIDEO_TELEPHONY__
    <CACHEDATA type="byte" id="NVRAM_CALLSET_VT_ANSWER_MODE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> VT answer mode </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_CALLSET_VT_DIAL_MODE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> VT dial mode </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_CALLSET_VT_MIC" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> VT microphone </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_CALLSET_VT_SPEAKER" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> VT speaker </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_CALLSET_VT_CAMERA" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> VT camera mode </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_CALLSET_VT_NIGHT_FRONT" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> VT night mode for front camera </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_CALLSET_VT_EV_FRONT" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> VT EV value for front camera </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_CALLSET_VT_ZOOM_FRONT" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> VT zoom setting for front camera </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_CALLSET_VT_NIGHT_BACK" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> VT night mode for back camera </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_CALLSET_VT_EV_BACK" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> VT EV value for back camera </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_CALLSET_VT_ZOOM_BACK" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> VT zoom setting for back camera </DESCRIPTION>
    </CACHEDATA>
#endif /* __MMI_VIDEO_TELEPHONY__ */

#ifdef __OP01_FWPBW__
    <CACHEDATA type="byte" id="NVRAM_CALLSET_DELAY_DIAL_TIME" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x04] </DEFAULT_VALUE>
        <DESCRIPTION> delay dial time, dial after 1~255 seconds, 0 means OFF </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_CALLSET_OFFHOOK_REMINDER_TIMEOUT" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x1E] </DEFAULT_VALUE>
        <DESCRIPTION> off-hook timeout in seconds to start the reminder, default is 30s </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_CALLSET_OFFHOOK_REMINDER_DURATION" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x05] </DEFAULT_VALUE>
        <DESCRIPTION> off-hook reminder duration in seconds, default is 5s </DESCRIPTION>
    </CACHEDATA>
#endif /* __OP01_FWPBW__ */

    <CACHEDATA type="short" id="NVRAM_CALLSET_CTR_TIME">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Call time reminder time </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_CALLSET_QUICK_END_TIME" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Auto quick end duration </DESCRIPTION>
    </CACHEDATA>

	#ifdef MOTION_SENSOR_SUPPORT
    <CACHEDATA type="byte" id="NVRAM_CALLSET_FLIP_TO_MUTE_CALL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X01] </DEFAULT_VALUE>
        <DESCRIPTION> Flip to mute call </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_CALLSET_TAP_TAP_TO_RECORD_IN_CALL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X01] </DEFAULT_VALUE>
        <DESCRIPTION> Tap Tap to record in call </DESCRIPTION>
    </CACHEDATA>
    #endif


</APP>
