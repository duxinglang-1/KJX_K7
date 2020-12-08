/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "MMI_features.h"
#if defined (__MMI_DOWNLOAD_AGENT__)
#include "CustResDef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_DOWNLOADAGENT">
<INCLUDE file = "mmi_rp_all_defs.h"/>
    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>
	<RECEIVER id="EVT_ID_SRV_SHUTDOWN_DEINIT" proc="srv_da_shutdown_proc"/>	
#ifdef __MMI_USB_SUPPORT__
	#if defined(__USB_IN_NORMAL_MODE__) && defined(__MMI_DOWNLOAD_AGENT__)
		<RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="srv_da_usb_mode_on"/>
	#endif
#endif /* __MMI_USB_SUPPORT__ */

    <STRING id="STR_DA_TEXT_FILE"/>
	<STRING id="STR_DA_IMAGE_FILE"/>
	<STRING id="STR_DA_AUDIO_FILE"/>
	<STRING id="STR_DA_VIDEO_FILE"/>
	<STRING id="STR_DA_APP_FILE"/>
	<STRING id="STR_DA_MSG_FILE"/>
	<STRING id="STR_DA_MULTI_FILE"/>
	<STRING id="STR_DA_UNKNOWN_FILE"/>
	<STRING id="STR_DA_VCARD_FILE"/>
	<STRING id="STR_DA_VCALENDAR_FILE"/>
	<STRING id="STR_ID_DA_CANCELLED"/>
#if defined (__MMI_OMA_DD_DOWNLOAD__)
	<STRING id="STR_ID_DA_OMA_LOSS_OF_SERVICE_MSG"/>
    <STRING id="STR_ID_DA_OMA_ATTRIBUTE_MISMATCH_MSG"/>
    <STRING id="STR_ID_DA_OMA_INVALID_DESCRIPTOR_MSG"/>
    <STRING id="STR_ID_DA_OMA_INVALID_DDVSERSION_MSG"/>
    <STRING id="STR_ID_DA_OMA_DEVICE_ABORTED_MSG"/>
    <STRING id="STR_ID_DA_OMA_NON_ACCEPTABLE_CONTENT_MSG"/>
    <STRING id="STR_ID_DA_OMA_LOADER_ERROR_MSG"/>
    <STRING id="STR_ID_DA_AHTUENTICATION_FAILED"/>
#endif
	<RECEIVER id="EVT_ID_SRV_SHUTDOWN_DEINIT" proc="srv_da_shutdown_proc"/>
#if defined (BROWSER_SUPPORT)
    <RECEIVER id="EVT_ID_IDLE_GROUP_ENTER" proc="mmi_da_enter_idle_screen_notify"/>
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_da_scr_select_storage_on_dev_plug_out"/>
#endif
	
#ifdef __MMI_USB_SUPPORT__
	#if defined(__USB_IN_NORMAL_MODE__) && defined(__MMI_DOWNLOAD_AGENT__)
		<RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="srv_da_usb_mode_on"/>
	#endif
#endif /* __MMI_USB_SUPPORT__ */

	<RECEIVER id="EVT_ID_SRV_CBM_BEARER_AVAILABLE" proc="srv_da_bearer_available"/>
	<RECEIVER id="EVT_ID_SRV_CBM_BEARER_UNAVAILABLE" proc="srv_da_bearer_unavailable"/>
/*****************************DLAgent Srv events ***********************************************/
	<SENDER id="EVT_ID_DLA_SRV_SHOW_PROGRESS" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_POPUP_FOR_JOB_MSG" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_POPUP" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_SELECT_STORAGE" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_SET_STORAGE_INSTANCE" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_DISPLAY_JOB_LIST" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_DISPLAY_JOB_DETAIL" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_PROGRESSING_CLOSE" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_POPUP_ERRORCODE_WITH_CALLBACK" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_SHOW_NEW_DOWNLOAD_CONFIRM_SCREEN" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_SET_ACTIVE_DOWNLOAD_CONFIRM_SCREEN" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_WPS_HTTP_RSP_CALLBACK" hfile="DLAgentSrvGProt.h"/>
	
	<SENDER id="EVT_ID_DLA_SRV_CONFIRM_OMA_DOWNLOAD" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_OMA_HANDLE_HTTP_RSP" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_SHOW_USER_AUTH_SCREEN" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_PUSH_PROCESS_ITEM" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_UPDATE_JOB_STATUS" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_DRM_SAVE_AS" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_UPDATE_CONTENT_BY_DRM_PROCESSING" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_CLICK_JOB" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_JOB_ABORTED_CALLBACK" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_REMOVE_JOB_SCREENS" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_UPDATE_NCENTER" hfile="DLAgentSrvGProt.h"/>
	
	<SENDER id="EVT_ID_DLA_SRV_UPDATE_NCENTER_DOWNLOADING_CELL" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_UPDATE_NCENTER_COMPLETED_CELL" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_UPDATE_NCENTER_FAILED_CELL" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_UPDATE_NCENTER_PUSHED_OBJ_CELL" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_CLOSE_APP" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_POPUP_ERROR_FOR_JOB" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_POPUP_FOR_JOB" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_POPUP_FOR_JOB" hfile="DLAgentSrvGProt.h"/>
        <SENDER id="EVT_ID_DLA_SRV_JAVA_FILE_IND" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_JAVA_SETTING_IND" hfile="DLAgentSrvGProt.h"/>
	<SENDER id="EVT_ID_DLA_SRV_CERTMAN_SETTING_IND" hfile="DLAgentSrvGProt.h"/>	
        <SENDER id="EVT_ID_DLA_SRV_IS_USB_AVAILABLE" hfile="DLAgentSrvGProt.h"/>
     <SENDER id="EVT_ID_DLA_SRV_SHOW_NMGR_POPUP" hfile="DLAgentSrvGProt.h"/>
	<TIMER id="SRV_DA_TIMER_UPDATE_STATUS"/>
	<TIMER id="SRV_DA_WPS_TIMER_0"/>
	<TIMER id="SRV_DA_TIMER_TRIGGERED_PROC_TIMER_BASE"/>
</APP>
#endif //__MMI_DOWNLOAD_AGENT__
