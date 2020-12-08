# 1 "temp/res/CallSetSrv.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/CallSetSrv.c"

# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 3 "temp/res/CallSetSrv.c" 2

<?xml version="1.0" encoding="UTF-8"?>

<APP id="SRV_CALLSET">



    <!--Include Area-->

    <!-----------------------------------------------------Event Resource Area----------------------------------------------------->
    <EVENT id="EVT_ID_SRV_CALLSET_ACT_RESPONSE"/>
    <EVENT id="EVT_ID_SRV_CALLSET_LINE_SWITCHED" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_CALLSET_CFU_STATUS_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_CALLSET_CTM_SETTING_CHANGED" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_CALLSET_INT_ACT"/>






    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="srv_callset_hdlr_sim_availability_changed"/>
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="srv_callset_hdlr_mode_switched"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->


    <STRING id="STR_ID_SRV_CALLSET_RESULT_FULL"/>
    <STRING id="STR_ID_SRV_CALLSET_RESULT_TOO_LONG"/>
    <STRING id="STR_ID_SRV_CALLSET_RESULT_DUPLICATED"/>
    <STRING id="STR_ID_SRV_CALLSET_RESULT_EMPTY"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>





    <!-----------------------------------------------------MMI cache Resource Area------------------------------------------------------>

    <CACHEDATA type="byte" id="NVRAM_CALLSET_CALLERID" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X02] </DEFAULT_VALUE>
        <DESCRIPTION> Caller ID value </DESCRIPTION>
    </CACHEDATA>
# 68 "temp/res/CallSetSrv.c"
    <CACHEDATA type="byte" id="NVRAM_CALLSET_CUG_ACTIVATED_ID" restore_flag="TRUE">
        <DEFAULT_VALUE> [0Xff] </DEFAULT_VALUE>
        <DESCRIPTION> CUG activated ID </DESCRIPTION>
    </CACHEDATA>
# 92 "temp/res/CallSetSrv.c"
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


    <CACHEDATA type="byte" id="NVRAM_CALLSET_REJ_BY_SMS" restore_flag="TRUE">



        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>

        <DESCRIPTION> Reject by SMS </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_CALLSET_REJ_BY_SMS_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
        <DESCRIPTION> Reject by SMS setting </DESCRIPTION>
    </CACHEDATA>



    <CACHEDATA type="byte" id="NVRAM_CALLSET_CONNECT_NOTICE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X01] </DEFAULT_VALUE>
        <DESCRIPTION> Connect notice </DESCRIPTION>
    </CACHEDATA>



    <CACHEDATA type="byte" id="NVRAM_CALLSET_IP_NUMBER_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> IP number setting </DESCRIPTION>
    </CACHEDATA>
# 161 "temp/res/CallSetSrv.c"
    <CACHEDATA type="byte" id="NVRAM_CALLSET_BLACKLIST_MODE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Black list setting </DESCRIPTION>
    </CACHEDATA>
# 192 "temp/res/CallSetSrv.c"
    <CACHEDATA type="byte" id="NVRAM_CALLSET_QUICK_END_FLAG" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
        <DESCRIPTION> Auto quick end </DESCRIPTION>
    </CACHEDATA>
# 283 "temp/res/CallSetSrv.c"
    <CACHEDATA type="short" id="NVRAM_CALLSET_CTR_TIME">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Call time reminder time </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_CALLSET_QUICK_END_TIME" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Auto quick end duration </DESCRIPTION>
    </CACHEDATA>
# 306 "temp/res/CallSetSrv.c"
</APP>
