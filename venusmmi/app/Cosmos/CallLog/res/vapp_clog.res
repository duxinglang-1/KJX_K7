#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_CALLLOG"
    package_name="native.mtk.calllog"
    name="STR_ID_VAPP_CLOG"
    img="IMG_ID_VAPP_CLOG_MAIN_MENU"
    launch="vapp_clog_launch" type="venus"
    package_proc="vapp_clog_package_proc">

    <LAYOUT file="vapp_clog.xml" />

    <CACHEDATA type="byte" id="NVRAM_VAPP_CLOG_NCENTER_HAVE_NOTI" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Whether have notification after reboot </DESCRIPTION>
    </CACHEDATA>
    
<!------------------------------String Resource Area-------------------------------------->
    <STRING id="STR_ID_VAPP_CLOG"/>
    <STRING id="STR_ID_VAPP_CLOG_NCENTER_GROUP_TITLE"/>
    //<STRING id="STR_ID_VAPP_CLOG_CALL_BY_SIM1"/>
	//<STRING id="STR_ID_VAPP_CLOG_CALL_BY_SIM2"/>
	//<STRING id="STR_ID_VAPP_CLOG_CALL_VIDEO"/>
	<STRING id="STR_ID_VAPP_CLOG_VIEW_CONTACT"/>
	<STRING id="STR_ID_VAPP_CLOG_ALL"/>
	<STRING id="STR_ID_VAPP_CLOG_MISSED"/>
	<STRING id="STR_ID_VAPP_CLOG_UNKONWN_NUMBER"/>
	<STRING id="STR_ID_VAPP_CLOG_UNSAVED"/>
	<STRING id="STR_ID_VAPP_CLOG_UNNAMED"/>
	<STRING id="STR_ID_VAPP_CLOG_CLEAR_THE_CALL_LOG_QUERY"/>
	//<STRING id="STR_ID_VAPP_CLOG_CLEARING"/>
	//<STRING id="STR_ID_VAPP_CLOG_CLEAR_ALL"/>
	<STRING id="STR_ID_VAPP_CLOG_NO_CALL_LOG"/>
	<STRING id="STR_ID_VAPP_CLOG_CLEAR_THE_MISSED_CALL_QUERY"/>
	<STRING id="STR_ID_VAPP_CLOG_NO_MISSED_CALL"/>
	<STRING id="STR_ID_VAPP_CLOG_DETAILS"/>
	<STRING id="STR_ID_VAPP_CLOG_RING_ONCE"/>
	<STRING id="STR_ID_VAPP_CLOG_MISSED_CALL"/>
	<STRING id="STR_ID_VAPP_CLOG_RECEIVED_CALL"/>
	<STRING id="STR_ID_VAPP_CLOG_DIALLED_CALL"/>
	<STRING id="STR_ID_VAPP_CLOG_DELETE_THE_CALL_LOG_QUERY"/>
#if defined(__MMI_CM_BLACK_LIST__) && defined(__OP01__)
    <STRING id="STR_ID_VAPP_CLOG_VIEW_BLACK_LIST"/>
#endif /* __MMI_CM_BLACK_LIST__ && __OP01__ */

   // <STRING id="STR_ID_VAPP_CLOG_CALL_TYPE"/>
    //<STRING id="STR_ID_VAPP_CLOG_CALL_TIME"/>
    //<STRING id="STR_ID_VAPP_CLOG_DURATION"/>
    <STRING id="STR_ID_VAPP_CLOG_MULTI_MISSED_CALLS"/>
    //<STRING id="STR_ID_VAPP_CLOG_SIM_USED"/>
    <STRING id="STR_ID_VAPP_CLOG_UNKNOWN"/>
    <STRING id="STR_ID_VAPP_CLOG_LEFT_BRACKET"/>
    <STRING id="STR_ID_VAPP_CLOG_RIGHT_BRACKET"/>
    <STRING id="STR_ID_VAPP_CLOG_SELECT_SIM"/>
    <STRING id="STR_ID_VAPP_CLOG_SEC"/>
    <STRING id="STR_ID_VAPP_CLOG_SECS"/>
    <STRING id="STR_ID_VAPP_CLOG_MIN"/>
    <STRING id="STR_ID_VAPP_CLOG_MINS"/>
    <STRING id="STR_ID_VAPP_CLOG_HOUR"/>
    <STRING id="STR_ID_VAPP_CLOG_HOURS"/>
#ifdef __MMI_CLOG_MARK_SEVERAL__
    <STRING id="STR_ID_VAPP_CLOG_DELETE_SELECTED_CALL_LOGS_QUERY"/>
    <STRING id="STR_ID_VAPP_CLOG_QUESTION_MARK"/>
#endif

    <STRING id="STR_ID_VAPP_CLOG_USAGE"/>
#if (MMI_MAX_SIM_NUM > 1)    
    //<STRING id="STR_ID_VAPP_CLOG_SIM1_USAGE"/>
    //<STRING id="STR_ID_VAPP_CLOG_SIM2_USAGE"/>
#endif    

#ifdef __MMI_CLOG_GPRS_COUNT__    
	<STRING id="STR_ID_VAPP_CLOG_USAGE_GPRS"/>
	<STRING id="STR_ID_VAPP_CLOG_USAGE_MONTHLY_ALL"/>
	<STRING id="STR_ID_VAPP_CLOG_USAGE_MONTHLY_RECEIVED"/>
	<STRING id="STR_ID_VAPP_CLOG_USAGE_MONTHLY_SENT"/>
	<STRING id="STR_ID_VAPP_CLOG_USAGE_MB"/>
	<STRING id="STR_ID_VAPP_CLOG_USAGE_THRESHOLD"/>
	<STRING id="STR_ID_VAPP_CLOG_USAGE_HELP_TEXT"/>
#endif /* __MMI_CLOG_GPRS_COUNT__ */

#ifdef __MMI_CLOG_SMS_COUNT__
	<STRING id="STR_ID_VAPP_CLOG_USAGE_SMS"/>
	<STRING id="STR_ID_VAPP_CLOG_USAGE_MONTHLY_OUTGOING"/>
	<STRING id="STR_ID_VAPP_CLOG_USAGE_MONTHLY_INCOMING"/>
#endif /* __MMI_CLOG_SMS_COUNT__ */

#ifdef __MMI_CLOG_CALL_TIME__	
	<STRING id="STR_ID_VAPP_CLOG_USAGE_CALL_TIME"/>
	<STRING id="STR_ID_VAPP_CLOG_USAGE_CT_MONTHLY_OUTGOING"/>
	<STRING id="STR_ID_VAPP_CLOG_USAGE_CT_MONTHLY_INCOMING"/>
#endif /* __MMI_CLOG_CALL_TIME__ */

#ifdef __MMI_CLOG_CALL_COST__
	<STRING id="STR_ID_VAPP_CLOG_USAGE_CALL_COST"/>
	<STRING id="STR_ID_VAPP_CLOG_USAGE_LAST_CALL_COST"/>	
	<STRING id="STR_ID_VAPP_CLOG_USAGE_TOTAL_COST"/>
	<STRING id="STR_ID_VAPP_CLOG_USAGE_CLEAR_COST"/>
	<STRING id="STR_ID_VAPP_CLOG_USAGE_MAX_COST"/>	
	<STRING id="STR_ID_VAPP_CLOG_USAGE_PPU"/>
	<STRING id="STR_ID_VAPP_CLOG_USAGE_PRICE"/>
	<STRING id="STR_ID_VAPP_CLOG_USAGE_UNIT"/>
	<STRING id="STR_ID_VAPP_CLOG_USAGE_INVALID_INPUT"/>
#endif /* __MMI_CLOG_CALL_COST__ */	

    <STRING id="STR_ID_VAPP_CLOG_USAGE_PREV"/>
	<STRING id="STR_ID_VAPP_CLOG_USAGE_NEXT"/>
	
<!------------------------------Image Resource Area-------------------------------------->

    <IMAGE id="IMG_ID_VAPP_CLOG_NMGR_MISSED">RES_IMG_ROOT"\\\\NMGR_Icon\\\\icon_call_miss.png"</IMAGE>

    <THEME>
        <IMAGE id="IMG_ID_VAPP_CLOG_MAIN_MENU" desc="Main menu call log icon">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\CallLog.png"</IMAGE>
        
    #if (MMI_MAX_SIM_NUM == 1)
        <IMAGE id="IMG_ID_VAPP_CLOG_CALL_SIM1_N" desc="general call normal icon"/>
        <IMAGE id="IMG_ID_VAPP_CLOG_CALL_SIM1_P" desc="general call pressed icon"/>
        <IMAGE id="IMG_ID_VAPP_CLOG_CALL_SIM1_D" desc="general call disable icon"/>
        <IMAGE id="IMG_ID_VAPP_CLOG_DETAIL_CALL_SIM1" desc="general call button"/>
    #elif (MMI_MAX_SIM_NUM > 1)
        <IMAGE id="IMG_ID_VAPP_CLOG_CALL_SIM1_N" desc="SIM1 call normal icon"/>
        <IMAGE id="IMG_ID_VAPP_CLOG_CALL_SIM1_P" desc="SIM1 call pressed icon"/>
        <IMAGE id="IMG_ID_VAPP_CLOG_CALL_SIM1_D" desc="SIM1 call disable icon"/>
        <IMAGE id="IMG_ID_VAPP_CLOG_DETAIL_CALL_SIM1" desc="SIM1 call button"/>
        
        <IMAGE id="IMG_ID_VAPP_CLOG_CALL_SIM2_N" desc="SIM2 call normal icon"/>
        <IMAGE id="IMG_ID_VAPP_CLOG_CALL_SIM2_P" desc="SIM2 call pressed icon"/>
        <IMAGE id="IMG_ID_VAPP_CLOG_CALL_SIM2_D" desc="SIM2 call disable icon"/>
        <IMAGE id="IMG_ID_VAPP_CLOG_DETAIL_CALL_SIM2" desc="SIM2 call button"/>
    #endif /* MMI_MAX_SIM_NUM */

    #ifdef __MMI_VIDEO_TELEPHONY__
        <IMAGE id="IMG_ID_VAPP_CLOG_CALL_VIDEO_N" desc="video call normal icon"/>
        <IMAGE id="IMG_ID_VAPP_CLOG_CALL_VIDEO_P" desc="video call pressed icon"/>
        <IMAGE id="IMG_ID_VAPP_CLOG_CALL_VIDEO_D" desc="video call disable icon"/>
        <IMAGE id="IMG_ID_VAPP_CLOG_DETAIL_CALL_VIDEO" desc="video call button"/>
        
        <IMAGE id="IMG_ID_VAPP_CLOG_VIDEO_BTN_N" desc="video call normal color"/>
        <IMAGE id="IMG_ID_VAPP_CLOG_VIDEO_BTN_P" desc="video call pressed color"/>
        <IMAGE id="IMG_ID_VAPP_CLOG_VIDEO_BTN_D" desc="video call disable color"/>
    #endif /* __MMI_VIDEO_TELEPHONY__ */

        <IMAGE id="IMG_ID_VAPP_CLOG_SAVE_CONTACT" desc="detail screen save icon"/>
    
    </THEME>
    //temp for mmi_app_2
    <IMAGE id = "IMG_ID_CLOG_MAIN_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\CallCenter\\\\CC_callhistory.pbm"</IMAGE>


<!----------------- NVRAM Cache ------------------------------------------->

    <CACHEDATA type="short" id="NVRAM_VAPP_CLOG_USAGE_MONTH">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NVRAM_VAPP_CLOG_USAGE_GPRS_THRESHOLD">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Double cache </DESCRIPTION>
    </CACHEDATA>

<!----------------- Event Id ------------------------------------------->

    <!----------------- CallLogSrv Event Handler ----------------------->
    <EVENT id="EVT_ID_VAPP_CLOG_APP_ENTER" type="SENDER"/>
    <RECEIVER id="EVT_ID_SRV_CLOG_READY" proc="vapp_clog_srv_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_CLOG_ADD_LOG" proc="vapp_clog_srv_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_CLOG_UPDATE_LOG" proc="vapp_clog_srv_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_CLOG_UPDATE_ALL" proc="vapp_clog_srv_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_CLOG_DEL_LOG" proc="vapp_clog_srv_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_CLOG_DEL_ALL" proc="vapp_clog_srv_evt_hdlr"/>

    <RECEIVER id="EVT_ID_GPIO_EXT_DEV_KEY_1" proc="vapp_clog_gpio_hookkey_hdlr"/>

</APP>

