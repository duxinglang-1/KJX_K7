#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_SMS_CLASS0" name="STR_ID_VAPP_SMS_CLASS0" type="venus">
    <MEMORY heap="1024 * 50"/>
    <APPCONCURRENT concurrent_w_order ="VAPP_SMS_CLASS0, VAPP_MSG"/>
    	<STRING id="STR_ID_VAPP_SMS_CLASS0"/>
</APP>


<APP id="VAPP_SMS_SEND_URI" name="STR_ID_VAPP_SMS_SEND_URI" type="venus">
    <MEMORY cui="VCUI_MSGCOMPOSER"/>
    <STRING id="STR_ID_VAPP_SMS_SEND_URI"/>
</APP>

<APP id="VAPP_SMS_HEAP" name="STR_ID_VAPP_SMS_HEAP" type="venus">

    <MEMORY heap= "0" vrt_mem_factor= "0"/>
    <STRING id="STR_ID_VAPP_SMS_HEAP"/>
    
</APP>

<APP id="VAPP_SMS_EXTRA_BASE" name="STR_ID_VAPP_SMS_EXTRA_BASE" type="venus">

    <MEMORY extra_base="0" vrt_mem_factor= "0"/>
    <STRING id="STR_ID_VAPP_SMS_EXTRA_BASE"/>
    
</APP>
<APP id="VAPP_SMS_FG" name="STR_ID_VAPP_SMS_FG" type="venus">

    <MEMORY fg="0" vrt_mem_factor= "0"/>
    <STRING id="STR_ID_VAPP_SMS_FG"/>
    
</APP>

<APP id="APP_VAPP_SMS" name="STR_ID_VAPP_SMS" type="venus">
    <LAYOUT file="vapp_sms.xml" />


    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_VAPP_SMS" />

    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id = "SCR_ID_VAPP_SMS_CLASS0_VIEWER"/>

    <!-------------Resource for SMS template begin---------------------------------------------->
#ifdef __MMI_MESSAGES_TEMPLATE__
    <STRING id="STR_ID_VAPP_SMS_TEMPLATE_FULL"/>
    <STRING id="STR_ID_VAPP_SMS_TEMPLATE_SELECT"/>
    <STRING id="STR_ID_VAPP_SMS_DEL_SELECT_TEMPLATES"/>
    <STRING id="STR_ID_VAPP_SMS_DELETE_TEMPLATE_QUERY"/>
    <STRING id="STR_ID_VAPP_SMS_MESSAGE_OPTION"/>
#endif
    <!-------------Resource for SMS template end---------------------------------------------->

    <!-------------Resource for Voicemail server begin---------------------------------------------->
    <STRING id="STR_ID_VAPP_SMS_VM_SERVER"/>
    <STRING id="STR_ID_VAPP_SMS_VM_EDIT"/>
    <STRING id="STR_ID_VAPP_SMS_VM_NAME"/>
    <STRING id="STR_ID_VAPP_SMS_VM_NUMBER"/>

    <!-------------Resource for Voicemail server end---------------------------------------------->

    <!-------------Resource for SMS setting begin---------------------------------------------->
    #if 0
    <STRING id="STR_VAPP_SMS_POPUP_VIEW"/>
    <STRING id="STR_VAPP_SMS_POPUP_CANCEL"/>
    #endif /*slim for 6260, this string never be used*/
#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
	<STRING id="STR_ID_SMS_DEFAULT_STORAGE"/>
    <STRING id="STR_ID_SMS_MSG_FILTER"/>
#endif
    <STRING id="STR_ID_VAPP_SMS_PREFER_STORAGE"/>
    <STRING id="STR_ID_VAPP_SMS_PREFER_STORAGE_SUB"/>
    <STRING id="STR_ID_VAPP_SMS_PREFER_STORAGE_ME"/>
    <STRING id="STR_ID_VAPP_SMS_PREFER_STORAGE_SIM"/>
    <STRING id="STR_ID_VAPP_SMS_SET0"/>
    <STRING id="STR_ID_VAPP_SMS_SET1"/>
    <STRING id="STR_ID_VAPP_SMS_SET2"/>
    <STRING id="STR_ID_VAPP_SMS_SET3"/>
    <STRING id="STR_ID_VAPP_SMS_SETTING"/>
    <STRING id="STR_ID_VAPP_SMS_PREFERED_BEARER"/>
    <STRING id="STR_ID_VAPP_SMS_PREFER_GSM_BEARER"/>
    <STRING id="STR_ID_VAPP_SMS_PREFER_GPRS_BEARER"/>
    <STRING id="STR_ID_VAPP_SMS_GSM_BEARER"/>
    <STRING id="STR_ID_VAPP_SMS_PROFILE_SETTING"/>
    <STRING id="STR_ID_VAPP_SMS_EDIT_PROFILE"/>
    <STRING id="STR_ID_VAPP_SMS_PROFILE_NAME"/>
    <STRING id="STR_ID_VAPP_SMS_PROFILE_SC"/>
    <STRING id="STR_ID_VAPP_SMS_PROFILE_VP"/>
    <STRING id="STR_ID_VAPP_SMS_PROFILE_MSG_TYPE"/>
    <STRING id="STR_ID_VAPP_SMS_VP_1HOUR"/>
    <STRING id="STR_ID_VAPP_SMS_VP_6HOUR"/>
    <STRING id="STR_ID_VAPP_SMS_VP_12HOUR"/>
    <STRING id="STR_ID_VAPP_SMS_VP_1DAY"/>
    <STRING id="STR_ID_VAPP_SMS_VP_3DAY"/>
    <STRING id="STR_ID_VAPP_SMS_VP_1WEEK"/>
    <STRING id="STR_ID_VAPP_SMS_TYPE_PAGE"/>
    <STRING id="STR_ID_VAPP_SMS_TYPE_FAX"/>
    <STRING id="STR_ID_VAPP_SMS_TYPE_GROUP4_FAX"/>
    <STRING id="STR_ID_VAPP_SMS_REPLY_PATH"/>
    <STRING id="STR_ID_VAPP_SMS_DELIVERY_REPORT"/>
    <STRING id="STR_ID_VAPP_SMS_POPUP_FROM"/>
    <STRING id="STR_ID_VAPP_SMS_VK_PREV"/>
    <STRING id="STR_ID_VAPP_SMS_VK_NEXT"/>

    <!-------------Resource for Text template end---------------------------------------------->

    <!-------------Resource for Message waiting etc begin---------------------------------------------->
    <STRING id="STR_ID_VAPP_SMS_LINE2_NEW_VOCIEMAIL_WAITING"/>
    <STRING id="STR_ID_VAPP_SMS_NEW_VOCIEMAIL_WAITING"/>
    <STRING id="STR_ID_VAPP_SMS_NEW_FAX_WAITING"/>
    <STRING id="STR_ID_VAPP_SMS_NEW_EMAIL_WAITING"/>
    <STRING id="STR_ID_VAPP_SMS_NEW_NET_MSG_WAITING"/>
    <STRING id="STR_ID_VAPP_SMS_NEW_VEDIO_WAITING"/>
    <STRING id="STR_ID_VAPP_SMS_NEW_VOCIEMAIL_WAITING_FROM"/>
    <STRING id="STR_ID_VAPP_SMS_DELIVERED_TO"/>
    <STRING id="STR_ID_VAPP_SMS_FAILED_TO_SEND_TO"/>
    <STRING id="STR_ID_VAPP_SMS_SEND_SMS_QUERY"/>
    <STRING id="STR_ID_VAPP_SMS_DATA_EXCEED"/>
    <STRING id="STR_ID_VAPP_SMS_VM_CALL_VOICE"/>
    <STRING id="STR_ID_VAPP_SMS_SIM1_VOICEMAIL_NUM_IND"/>
    <STRING id="STR_ID_VAPP_SMS_SIM2_VOICEMAIL_NUM_IND"/>
    <STRING id="STR_ID_VAPP_SMS_SIM3_VOICEMAIL_NUM_IND"/>
    <STRING id="STR_ID_VAPP_SMS_SIM4_VOICEMAIL_NUM_IND"/>
    <STRING id="STR_ID_VAPP_SMS_SIM1_VOICEMAIL_NUM_IND_PLURAL"/>
    <STRING id="STR_ID_VAPP_SMS_SIM2_VOICEMAIL_NUM_IND_PLURAL"/>
    <STRING id="STR_ID_VAPP_SMS_SIM3_VOICEMAIL_NUM_IND_PLURAL"/>
    <STRING id="STR_ID_VAPP_SMS_SIM4_VOICEMAIL_NUM_IND_PLURAL"/>
    <STRING id="STR_ID_VAPP_SMS_SIM1_VOICEMAIL_IND"/>
    <STRING id="STR_ID_VAPP_SMS_SIM2_VOICEMAIL_IND"/>
    <STRING id="STR_ID_VAPP_SMS_SIM3_VOICEMAIL_IND"/>
    <STRING id="STR_ID_VAPP_SMS_SIM4_VOICEMAIL_IND"/>
    <STRING id="STR_ID_VAPP_SMS_NEW_VOICEMAIL_NUM_IND"/>
    <STRING id="STR_ID_VAPP_SMS_NEW_VOICEMAIL_NUM_IND_PLURAL"/>
    <STRING id="STR_ID_VAPP_SMS_NEW_VOICEMAIL_FROM"/>
    <STRING id="STR_ID_VAPP_SMS_LINE2_VOICEMAIL_NUM_IND"/>
    <STRING id="STR_ID_VAPP_SMS_LINE2_VOICEMAIL_NUM_IND_PLURAL"/>
    <STRING id="STR_ID_VAPP_SMS_NEW_FAX_NUM_IND"/>
    <STRING id="STR_ID_VAPP_SMS_NEW_FAX_NUM_IND_PLURAL"/>
    <STRING id="STR_ID_VAPP_SMS_NEW_EMAIL_NUM_IND"/>
    <STRING id="STR_ID_VAPP_SMS_NEW_EMAIL_NUM_IND_PLURAL"/>
    <STRING id="STR_ID_VAPP_SMS_NEW_NET_MSG_NUM_IND"/>
    <STRING id="STR_ID_VAPP_SMS_NEW_NET_MSG_NUM_IND_PLURAL"/>
    <STRING id="STR_ID_VAPP_SMS_NEW_VEDIO_NUM_IND"/>
    <STRING id="STR_ID_VAPP_SMS_NEW_VEDIO_NUM_IND_PLURAL"/>
    <STRING id="STR_ID_VAPP_SMS_PHONE_STORAGE_EXCEEDED"/>
#if (MMI_MAX_SIM_NUM >= 4)
    <STRING id="STR_ID_VAPP_SMS_SIM4_STORAGE_EXCEEDED"/>
    <STRING id="STR_ID_VAPP_SMS_SIM4_PHONE_STORAGE_EXCEEDED"/>
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    <STRING id="STR_ID_VAPP_SMS_SIM3_STORAGE_EXCEEDED"/>
    <STRING id="STR_ID_VAPP_SMS_SIM3_PHONE_STORAGE_EXCEEDED"/>
#endif
#if (MMI_MAX_SIM_NUM >= 2)
    <STRING id="STR_ID_VAPP_SMS_SIM1_STORAGE_EXCEEDED"/>
    <STRING id="STR_ID_VAPP_SMS_SIM2_STORAGE_EXCEEDED"/>
    <STRING id="STR_ID_VAPP_SMS_SIM1_PHONE_STORAGE_EXCEEDED"/>
    <STRING id="STR_ID_VAPP_SMS_SIM2_PHONE_STORAGE_EXCEEDED"/>
    #if 0
    <STRING id="STR_ID_VAPP_SMS_CHANGE_TO_SIM1_QUERY"/>
    <STRING id="STR_ID_VAPP_SMS_CHANGE_TO_SIM2_QUERY"/>
    #endif /*slim for 6260, this string never be used*/
#else
    <STRING id="STR_ID_VAPP_SMS_SIM_STORAGE_EXCEEDED"/>
    <STRING id="STR_ID_VAPP_SMS_SIM_PHONE_STORAGE_EXCEEDED"/>
#endif

    <!-------------Resource for Message waiting etc end---------------------------------------------->

    <!---------------------- Sms Viewer String Resource Begin --------------------------------->
    <STRING id="STR_ID_VAPP_SMS_REPORTS"/>
    #if 0
    <STRING id="STR_ID_VAPP_SMS_NOT_SUPPORTED"/>
    <STRING id="STR_ID_VAPP_SMS_READ_DETAIL_FAIL"/>
    #endif /*slim for 6260, this string never be used*/
	<STRING id="STR_ID_VAPP_SMS_COPY"/>
	<STRING id="STR_ID_VAPP_SMS_SIM"/>
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    <STRING id="STR_ID_VAPP_SMS_TO_ARCHIVE"/>
    <STRING id="STR_ID_VAPP_SMS_COPY_TO_INBOX"/>
    <STRING id="STR_ID_VAPP_SMS_COPY_TO_SENTBOX"/>
    <STRING id="STR_ID_VAPP_SMS_COPY_TO_OUTBOX"/>
    <STRING id="STR_ID_VAPP_SMS_COPIED_TO_ARCHIVE"/>
    <STRING id="STR_ID_VAPP_SMS_COPIED_TO_INBOX"/>
    <STRING id="STR_ID_VAPP_SMS_COPIED_TO_SENTBOX"/>
    <STRING id="STR_ID_VAPP_SMS_COPIED_TO_OUTBOX"/>
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#if (MMI_MAX_SIM_NUM >= 4)
	<STRING id="STR_ID_VAPP_SMS_TO_SIM4"/>
	<STRING id="STR_ID_VAPP_SMS_COPIED_TO_SIM4"/>
#endif
#if (MMI_MAX_SIM_NUM >= 3)
	<STRING id="STR_ID_VAPP_SMS_TO_SIM3"/>
	<STRING id="STR_ID_VAPP_SMS_COPIED_TO_SIM3"/>
#endif
#if (MMI_MAX_SIM_NUM >= 2)
    <STRING id="STR_ID_VAPP_SMS_TO_SIM2"/>
    <STRING id="STR_ID_VAPP_SMS_COPIED_TO_SIM2"/>
    <STRING id="STR_ID_VAPP_SMS_TO_SIM1"/>
    <STRING id="STR_ID_VAPP_SMS_COPIED_TO_SIM1"/>
#endif /* (MMI_MAX_SIM_NUM >= 2) */
    <STRING id="STR_ID_VAPP_SMS_TO_SIM"/>
    <STRING id="STR_ID_VAPP_SMS_COPIED_TO_SIM"/>

	<STRING id="STR_ID_VAPP_SMS_COPY_TO_SIM"/>
#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
	<STRING id="STR_ID_VAPP_SMS_TO_TCARD"/>
	<STRING id="STR_ID_VAPP_SMS_TCARD_EXCEEDED"/>
	<STRING id="STR_ID_VAPP_SMS_COPIED_TO_TCARD"/>
#endif


    <STRING id="STR_ID_VAPP_SMS_COPY_TO_PHONE"/>
    <STRING id="STR_ID_VAPP_SMS_TO_PHONE"/>
    <STRING id="STR_ID_VAPP_SMS_COPIED_TO_PHONE"/>

    <STRING id="STR_ID_VAPP_SMS_FAIL_TO_DELETE"/>
    <STRING id="STR_ID_VAPP_SMS_FAIL_TO_COPY"/>

    <STRING id="STR_ID_VAPP_SMS_DEL_MSG_QUERY"/>
    #if 0
    <STRING id="STR_ID_VAPP_SMS_VCARD"/>
    <STRING id="STR_ID_VAPP_SMS_VCALENDAR"/>
    #endif /*slim for 6260, this string never be used*/

    <STRING id="STR_ID_VAPP_SMS_EDIT_BEFORE_CALL"/>
    <STRING id="STR_ID_VAPP_SMS_SEND_EMAIL"/>
#if defined(__MMI_VUI_SAVE_BOOKMARK_SUPPORT__) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
    <STRING id="STR_ID_VAPP_SMS_SAVE_TO_BOOKMARKS"/>
#endif /* __MMI_VUI_SAVE_BOOKMARK_SUPPORT__ */

    <STRING id="STR_ID_VAPP_SMS_NO_EMAIL"/>
    <STRING id="STR_ID_VAPP_SMS_NO_NICKNAME"/>

	<STRING id="STR_ID_VAPP_SMS_REPORTS_RECIPIENT"/>
	<STRING id="STR_ID_VAPP_SMS_REPORTS_STATUS"/>
	<STRING id="STR_ID_VAPP_SMS_PENDING"/>
	<STRING id="STR_ID_VAPP_SMS_DELIVERED"/>
	<STRING id="STR_ID_VAPP_SMS_FAILED"/>

	<STRING id="STR_ID_VAPP_SMS_RESEND_FAILED_MSG"/>
	<STRING id="STR_ID_VAPP_SMS_RECIPIENTS"/>
	<STRING id="STR_ID_VAPP_SMS_SENDING_CANNOT_OPEN"/>

    <!---------------------- SMS UM String Resource End --------------------------------->
	<STRING id="STR_ID_VAPP_SMS_NOT_SUPPORT"/>
	<STRING id="STR_ID_VAPP_SMS_IMCOMPLETE"/>
	<STRING id="STR_ID_VAPP_SMS_DELIVERY_REPORT"/>
	<STRING id="STR_ID_VAPP_SMS_REPORT"/>
	<STRING id="STR_ID_VAPP_SMS_UNAVAILABLE_SIM"/>
	<STRING id="STR_ID_VAPP_SMS_VOICEMAIL_NOT_AVAILABLE"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\Message\\\\ToolbarIcon\\\\"
    <IMAGE id="IMG_ID_VAPP_SMS_TOOLBAR_USE">ROOT_PATH"Use.png"</IMAGE>

    #define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\Message\\\\StatusIcon\\\\"
    <IMAGE id="IMG_ID_VAPP_SMS_PREVIEW_REPORT">ROOT_PATH"Message_Report.png"</IMAGE>

    #define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\Common\\\\Button\\\\"
    <IMAGE id="IMG_ID_VAPP_SMS_BUTTON_EDIT">ROOT_PATH"Edit.png"</IMAGE>

    #define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\Message\\\\ListIcon\\\\"
    <IMAGE id="IMG_ID_VAPP_SMS_RECEIVED">ROOT_PATH"Receive.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SMS_SENT">ROOT_PATH"Send.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SMS_DRAFT">ROOT_PATH"Drafts.png"</IMAGE>

    #define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\Common\\\\ListIcon\\\\"    
    <IMAGE id="IMG_ID_VAPP_SMS_SEND_FAIL">ROOT_PATH"Fail.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SMS_SEND_WAITING">ROOT_PATH"Waiting.png"</IMAGE>

    #define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\Message\\\\ToolbarIcon\\\\"
    <IMAGE id="IMG_ID_VAPP_SMS_RESEND">ROOT_PATH"Resend_MSG.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SMS_USE_DETAIL">ROOT_PATH"Use_Detail.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SMS_COPY_TO_PHONE">ROOT_PATH"Copy_To_Phone.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SMS_CALL">ROOT_PATH"Call.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SMS_TB_REPORTS">ROOT_PATH"Report.png"</IMAGE>

#ifdef __MMI_UM_REPORT_BOX__
#if (MMI_MAX_SIM_NUM >= 2)
    <IMAGE id="IMG_ID_VAPP_SMS_STATUS_REPORT_SIM1">CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD1\\\\DeliveryReport\\\\delivery_report_sim1.pbm"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SMS_STATUS_REPORT_SIM2">CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD2\\\\DeliveryReport\\\\delivery_report_sim2.pbm"</IMAGE>
#else /* (MMI_MAX_SIM_NUM >= 2) */
    <IMAGE id="IMG_ID_VAPP_SMS_STATUS_REPORT">CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\DeliveryReport\\\\delivery_report.pbm"</IMAGE>
#endif /* (MMI_MAX_SIM_NUM >= 2) */
#endif /* __MMI_UM_REPORT_BOX__ */

	<THEME>
	    <IMAGE id="IMG_ID_VAPP_MSG_CONTACT_BAR_BG" desc = "Message contact bar background image"/>
	    <IMAGE id="IMG_ID_VAPP_MSG_CONTACT_PORTRAIT_BG" desc = "Message contact portrait default background image"/>  
	    <IMAGE id="IMG_ID_VAPP_MSG_CONTACT_PORTRAIT_FG" desc = "Message contact portrait default foreground image"/>
	    <INTEGER id="VAPP_MSG_CONTACTBAR_SHADOW_HEIGHT" desc = "Message contact bar shadow height"/>
      #ifdef __MMI_SMS_PORT_MSG__
	    <IMAGE id="IMG_ID_VAPP_SMS_VOBJECT_BUTTON_N" desc = "Vcard or Vcalendar button normal state image in SMS viewer "/>
	    <IMAGE id="IMG_ID_VAPP_SMS_VOBJECT_BUTTON_P" desc = "Vcard or Vcalendar button pressed or highlighted state image in SMS viewer"/>
	    <IMAGE id="IMG_ID_VAPP_SMS_VOBJECT_BUTTON_D" desc = "Vcard or Vcalendar button disabled state image in SMS viewer"/>
      #endif /* __MMI_SMS_PORT_MSG__*/
	#ifdef __MMI_SMS_DETAILS_INFO__	
	    <IMAGE id="IMG_ID_VAPP_MSG_SEND_EMAIL_N" desc = "send email command button normal state image"/>
	    <IMAGE id="IMG_ID_VAPP_MSG_SEND_EMAIL_P" desc = "send email command button pressed or highlighted state image"/>
	    <IMAGE id="IMG_ID_VAPP_MSG_SEND_EMAIL_D" desc = "send email command button disabled state image"/>
	    <IMAGE id="IMG_ID_VAPP_MSG_GO_TO_URL_N" desc = "Go to url command button normal state image"/>
	    <IMAGE id="IMG_ID_VAPP_MSG_GO_TO_URL_P" desc = "Go to url command button pressed or highlighted state image"/>
	    <IMAGE id="IMG_ID_VAPP_MSG_GO_TO_URL_D" desc = "Go to url command button disabled state image"/>

		<IMAGE id="IMG_ID_VAPP_DETAIL_CALL_N" desc = "call command button normal state image"/>
		#if 0
	    <IMAGE id="IMG_ID_VAPP_DETAIL_CALL_P" desc = "call command button pressed or highlighted state image"/>
	    <IMAGE id="IMG_ID_VAPP_DETAIL_CALL_D" desc = "call command button disabled state image"/>
	    #endif /*slim for 6260, these images never be used*/
    #endif

	    <IMAGE id="IMG_ID_VAPP_SMS_RESEND_BUTTON" desc = "unsent sms resend image"/>

	    <COLOR id = "VAPP_SMS_CLASS0_CONTACT_TEXT_COLOR" desc = "Class0 SMS contact text color"/>
	    <COLOR id = "VAPP_SMS_CLASS0_CONTENT_TEXT_COLOR" desc = "Class0 SMS content text color"/>
	    <COLOR id = "VAPP_SMS_CLASS0_CONTENT_TIME_COLOR" desc = "Class0 SMS time text color"/>
	    <COLOR id = "VAPP_SMS_CLASS0_BUTTON1_COLOR" desc = "Class0 SMS save button color"/>
	    <COLOR id = "VAPP_SMS_CLASS0_BUTTON2_COLOR" desc = "Class0 SMS discard color"/>
	    <COLOR id = "VAPP_SMS_VIEWER_TEXT_COLOR" desc = "SMS viewer text color"/>


	    <COLOR id = "VAPP_SMS_TEXT_COLOR" desc = "SMS  text color"/>
	    <COLOR id = "VAPP_SMS_VIEWER_TEXT_BACKGROUND_COLOR" desc = "SMS viewer background color"/>
	</THEME>

    <!-----------------Events begin--------------------------------------------------->
#ifdef __MMI_URI_AGENT__
    <EVENT id="EVT_ID_VAPP_SMS_SEND_URI_IND" type="SENDER"/>
#endif
    <RECEIVER id="EVT_ID_SRV_SMS_READY" proc="VappSmsHandleSmsReadyInd"/>
    <RECEIVER id="EVT_ID_SRV_SMS_NEW_MSG" proc="VappSmsHandleNewSmsInd"/>
    <RECEIVER id="EVT_ID_SRV_SMS_NEW_MSG_WAITING" proc="VappSmsHandleNewMsgWaitingInd"/>
    <RECEIVER id="EVT_ID_SRV_SMS_STATUS_REPORT" proc="VappSmsHandleNewDeliveryReportInd"/>
    <RECEIVER id="EVT_ID_SRV_SMS_MEM_EXCEED" proc="VappSmsHandleMemExceedInd"/>
#if 0
    <RECEIVER id="EVT_ID_SRV_SMS_SIM_REFRESH" proc="VappSmsHandleSimRefreshInd"/>
    <RECEIVER id="EVT_ID_SRV_SMS_AT_CMD_IND" proc="VappSmsHandleAtCmdInd"/>
    <RECEIVER id="EVT_ID_SRV_SMS_MEM_FULL" proc="VappSmsHandleMemFullInd"/>
    <RECEIVER id="EVT_ID_SRV_SMS_MEM_AVAILABLE" proc="VappSmsHandleMemAvailableInd"/>
    <RECEIVER id="EVT_ID_SRV_SMS_API_SEND_MSG" proc="VappSmsHandleApiSendSmsInd"/>
#endif

#if (defined(__DM_LAWMO_SUPPORT__) || defined(__DM_MO_SUPPORT__))
    <RECEIVER id="EVT_ID_SRV_DM_LAWMO_WIPE_IND" proc="VappSmsClass0CancelInd"/>
#endif

#if 0
#ifdef __SRV_SMS_BACKGROUND_SEND_SUPPORT__
    <RECEIVER id="EVT_ID_SRV_SMS_UPDATE_UNSENT_MSG_STATUS" proc="VappSmsHandleUpdateUnsentSmsStatus"/>
#endif
    <RECEIVER id="EVT_ID_SRV_SMS_UPDATE_SENDING_ICON" proc="VappSmsHandleSendIconInd"/>
    <RECEIVER id="EVT_ID_SRV_SMS_ADD_REPORT" proc="VappSmsHandleReportChangeInd"/>
    <RECEIVER id="EVT_ID_SRV_SMS_DEL_REPORT" proc="VappSmsHandleReportChangeInd"/>
    <RECEIVER id="EVT_ID_SRV_SMS_UPDATE_REPORT" proc="VappSmsHandleReportChangeInd"/>
#endif
#ifdef __MMI_MESSAGES_TEMPLATE__
    <RECEIVER id="EVT_ID_SRV_SMS_ADD_TEMPLATE" proc="VappSmsHandleTemplateAddInd"/>
    <RECEIVER id="EVT_ID_SRV_SMS_DEL_TEMPLATE" proc="VappSmsHandleTemplateDelInd"/>
#endif

    <!---------------------------SMS UM SAP EVENT-------------------------------------->
	<RECEIVER id="EVT_ID_SRV_SMS_READY" proc="vapp_sms_um_ready_event_proc"/>
	<RECEIVER id="EVT_ID_SRV_SMS_NEW_MSG" proc="vapp_sms_um_new_msg_event_proc"/>
	<RECEIVER id="EVT_ID_SRV_SMS_ADD_MSG" proc="vapp_sms_um_msg_add_event_proc"/>
	<RECEIVER id="EVT_ID_SRV_SMS_DEL_MSG" proc="vapp_sms_um_msg_del_event_proc"/>
	<RECEIVER id="EVT_ID_SRV_SMS_UPDATE_MSG" proc="vapp_sms_um_msg_update_event_proc"/>
	<RECEIVER id="EVT_ID_SRV_SMS_REFRESH_MSG" proc="vapp_sms_um_msg_refresh_event_proc"/>
	<RECEIVER id="EVT_ID_SRV_SMS_UPDATE_UNSENT_MSG_STATUS" proc="vapp_sms_um_unsent_msg_update_event_proc"/>
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
	<RECEIVER id="EVT_ID_SRV_SMS_CLEAR_FOLDER" proc="vapp_sms_um_folder_changed_proc"/>
	<RECEIVER id="EVT_ID_SRV_SMS_HIDE_LIST" proc="vapp_sms_um_folder_changed_proc"/>
#endif

    <!-----------------Events end--------------------------------------------------->

    <!-----------------SMS app mmi cache begin--------------------------------------------------->
    <CACHEDATA type="double" id="VAPP_SMS_MSG_WAITING_HIDE_FLAG">
        <DEFAULT_VALUE> [0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> message waiting check if need hide info </DESCRIPTION>
    </CACHEDATA>
    <!-----------------SMS app mmi cache end--------------------------------------------------->


</APP>

