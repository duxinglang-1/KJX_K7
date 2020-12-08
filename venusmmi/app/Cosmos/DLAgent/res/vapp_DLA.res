/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "MMI_features.h"
#if defined (__MMI_DOWNLOAD_AGENT__)
#include "CustResDef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */

<APP id="VAPP_DLAGENT" package_name = "native.mtk.vapp_dlagent" name ="VAPP_STR_DLA_DOWNLOAD_AGENT" 
	img ="VAPP_IMG_ID_DLA_MAIN_ICON" launch ="vapp_dla_app_launch_ext" package_proc ="vapp_dla_app_launch_proc">
#ifdef __LOW_COST_SUPPORT_COMMON__                     
<MEMORY heap="200 * 1024"/>                     
#else
<MEMORY heap="512 * 1024"/>
#endif
    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file = "GlobalResDef.h"/>
   
   
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->

	<STRING id="VAPP_STR_DLA_DOWNLOAD_AGENT"/>
    <STRING id="VAPP_STR_DLA_FILES_ARE_DOWNLOADING"/>
    <STRING id="VAPP_STR_DLA_FILES_ARE_FAILED_TO_DOWNLOAD"/>
    <STRING id="VAPP_STR_DLA_FILES_ARE_COMPLETED_DOWNLOAD"/>
    <STRING id="VAPP_STR_DLA_IS_DOWNLOADING"/>
    <STRING id="VAPP_STR_DLA_IS_FAILED_TO_DOWNLOAD"/>
    <STRING id="VAPP_STR_DLA_IS_COMPLETED_DOWNLOAD"/>
    <STRING id="VAPP_STR_DLA_PUSHED_OBJECT"/>
    <STRING id="VAPP_STR_DLA_FAILED_TO_DOWNLOAD"/>
    <STRING id="VAPP_STR_DLA_COMPLETED_DOWNLOAD"/>
    <STRING id="VAPP_STR_DLA_COMPLETED"/>
    <STRING id="VAPP_STR_DLA_DOWNLOADED"/>
    <STRING id="VAPP_STR_DLA_FILE_DOWNLOADING"/>
    <STRING id="VAPP_STR_DLA_SELECT_STORAGE"/>
    <STRING id="VAPP_STR_DLA_DISCARD_DOWNLOADING"/>
    <STRING id="VAPP_STR_DLA_UNKNOWN_TIME_REMAINING"/>
    <STRING id="VAPP_STR_DLA_INITIALIZING"/>
    <STRING id="VAPP_STR_DLA_PAUSED"/>
    <STRING id="VAPP_STR_DLA_RETRY"/>
    <STRING id="VAPP_STR_DLA_WAITING"/>
    <STRING id="VAPP_STR_DLA_NO_DOWNLOADING"/>
    <STRING id="VAPP_STR_DLA_NO_COMPLETED"/>
    <STRING id="VAPP_STR_DLA_PAUSE_ALL"/>
    <STRING id="VAPP_STR_DLA_RESUME_ALL"/>
    <STRING id="VAPP_STR_DLA_REMOVE_ALL"/>
    <STRING id="VAPP_STR_DLA_DISCARD"/>
    <STRING id="VAPP_STR_DLA_DISCARD_DOWNLOADING_CONFIRM"/>
    <STRING id="VAPP_STR_DLA_REMOVE_COMPLETED_CONFIRM"/>
    <STRING id="VAPP_STR_DLA_OVERWRITE"/>
    <STRING id="VAPP_STR_DLA_FILENAME_ALREADY_EXISTS"/>
    <STRING id="VAPP_STR_DLA_MAX_DOWNLOAD_EXCEEDS"/>
    <STRING id="VAPP_STR_DLA_EMPTY_FILENAME"/>
    <STRING id="VAPP_STR_DLA_FILE_SAVE_TO"/>
    <STRING id="VAPP_STR_DA_FILE_NAME"/>
    <STRING id="VAPP_DLA_STR_FILE"/>
    <STRING id="VAPP_DLA_STR_NEW_PUSHED_OBJECT"/>
    <STRING id="VAPP_STR_DLA_EXIST_DOWNLOAD_IN_INIT"/>
    <STRING id="VAPP_STR_DLA_FLIGHT_MODE_ACTIVE"/>
    <STRING id="VAPP_STR_DLA_ACCESS_FAILED"/>
    <STRING id="VAPP_STR_DLA_PROMPT_EXCEED_MAX_DL"/>
    <STRING id="VAPP_STR_DLA_PROMPT_TIME_REMAIN"/>
    <STRING id="VAPP_STR_DLA_PROMPT_SIZE"/>
    <STRING id="VAPP_STR_DLA_PROMPT_TYPE"/>
    <STRING id="VAPP_STR_DLA_PROMPT_NEED_DOWNLOADING_NOTIFY_CHARGE"/>
    <STRING id="VAPP_STR_DLA_PROMPT_ESTIMATED"/>
    <STRING id="VAPP_STR_DLA_PROMPT_UNKNOWN"/>
    <STRING id="VAPP_STR_DLA_PROMPT_NAME"/>
    <STRING id="VAPP_STR_DLA_PROMPT_VENDOR"/>
    <STRING id="VAPP_STR_DLA_PROMPT_DESC"/>
    <STRING id="VAPP_STR_DLA_PROMPT_INFOURL"/>
    <STRING id="VAPP_STR_DLA_JOB_EXIST"/>
    <STRING id="VAPP_STR_DLA_DOWNLOADING_DESCRIPTOR"/>
#ifdef __MMI_DA_RESUME__
    <STRING id="VAPP_STR_DLA_PROMPT_RESUME_NOT_SUPPORTED_BY_SERVER"/>
    <STRING id="VAPP_STR_DLA_ERROR_RESUME_FAIL"/>
    <STRING id="VAPP_STR_DLA_JOB_RESUME"/>
#endif

    <STRING id="VAPP_STR_DLA_NO_RIGHTS"/>
    <STRING id="VAPP_STR_DLA_WAITING_FOR_RIGHTS"/>
    <STRING id="VAPP_STR_DLA_RIGHTS_DID_NOT_ARRIVE_ON_TIME"/>
    <STRING id="VAPP_STR_DLA_RIGHTS_DELAYED_SUFFIX"/>

		<STRING id="VAPP_STR_DLA_JAVA_JOB_EXIST"/>
		<STRING id="VAPP_STR_DLA_AHTUENTICATION_FAILED"/>
		<STRING id="VAPP_STR_DLA_OMA_ERROR_SEND_REPORT_FAIL"/>
		<STRING id="VAPP_STR_DLA_SAVED_TO_PHONE"/>
    <STRING id="VAPP_STR_DLA_SAVED_TO_CARD"/>
    <STRING id="VAPP_STR_DLA_UNABLE_TO_SAVE_FILE"/>
    <STRING id="VAPP_STR_DLA_ERROR_CONNECT_CLOSED"/>
    <STRING id="VAPP_STR_DLA_OMA_ERROR_SEND_REPORT_CANCEL"/>
    <STRING id="VAPP_STR_DLA_PROMPT_DL_COMPLETE"/>
    <STRING id="VAPP_STR_DLA_PROCESSING"/>
    <STRING id="VAPP_STR_DLA_NEW_PUSH"/>
	<STRING id="VAPP_STR_DLA_PROMPT_SEC"/>
	<STRING id="VAPP_STR_DLA_PROMPT_MINS"/>
	<STRING id="VAPP_STR_DLA_PROMPT_MIN"/>
	<STRING id="VAPP_STR_DLA_PROMPT_SECS"/>
	<STRING id="VAPP_STR_DLA_OMA_DOWNLOADING_ICON"/>
	<STRING id="VAPP_STR_DLA_OMA_SEND_REPORT"/>
    <STRING id="VAPP_STR_DLA_INSERT_MEMORY_CARD"/>

    

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
 	
 	<IMAGE id="VAPP_IMG_ID_DLA_TB_REMOVE_ALL">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Delete.png"</IMAGE>
 	<IMAGE id="VAPP_IMG_ID_DLA_TB_CANCEL">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Cancel.png"</IMAGE>
 	<IMAGE id="VAPP_IMG_ID_DLA_TB_SUBMIT">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Ok.png"</IMAGE>
 	<IMAGE id="VAPP_IMG_ID_DLA_TB_SAVE">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\save.png"</IMAGE>
 	
 	<IMAGE id="VAPP_IMG_ID_DLA_COMPLETED_TAB_ICON">RES_IMG_ROOT"\\\\DLAgent\\\\tab_completed.png"</IMAGE>
 	<IMAGE id="VAPP_IMG_ID_DLA_TB_PAUSE_ALL">RES_IMG_ROOT"\\\\DLAgent\\\\icon_pause_all.png"</IMAGE>
 	<IMAGE id="VAPP_IMG_ID_DLA_RESUME_ALL">RES_IMG_ROOT"\\\\DLAgent\\\\icon_resume_all.png"</IMAGE>	
 	<IMAGE id="VAPP_IMG_ID_DLA_TAB_DOWNLOADING">RES_IMG_ROOT"\\\\DLAgent\\\\tab_dl.png"</IMAGE>
 	<IMAGE id="VAPP_IMG_ID_DLA_TB_DOWNLOAD">RES_IMG_ROOT"\\\\DLAgent\\\\icon_dl.png"</IMAGE>

 	<IMAGE id="VAPP_IMG_ID_DLA_NCENTER_PAUSE">RES_IMG_ROOT"\\\\DLAgent\\\\pause.png"</IMAGE>
 	<IMAGE id="VAPP_IMG_ID_DLA_NCENTER_RESTART">RES_IMG_ROOT"\\\\DLAgent\\\\restart.png"</IMAGE>
 	<IMAGE id="VAPP_IMG_ID_DLA_NCENTER_RESUME">RES_IMG_ROOT"\\\\DLAgent\\\\resume.png"</IMAGE>
 	<IMAGE id="VAPP_IMG_ID_DLA_NCENTER_COMPLETE">RES_IMG_ROOT"\\\\DLAgent\\\\complete.png"</IMAGE>

    <THEME>
 	    <IMAGE id="VAPP_IMG_ID_DLA_MAIN_ICON" desc="Main menu downloads icon">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\DLAgent.png"</IMAGE>
    </THEME>
 	
 	<IMAGE id="VAPP_IMG_ID_DLA_NC_COMPLETED_ICON">RES_IMG_ROOT"\\\\NMGR_Icon\\\\icon_complete.png"</IMAGE>
 	<IMAGE id="VAPP_IMG_ID_DLA_NC_FAILED_ICON">RES_IMG_ROOT"\\\\NMGR_Icon\\\\icon_alert.png"</IMAGE>
 	<IMAGE id="VAPP_IMG_ID_DLA_NC_DOWNLOADING_ICON">RES_IMG_ROOT"\\\\NMGR_Icon\\\\icon_download.png"</IMAGE>

	
	
	<RECEIVER id="EVT_ID_DLA_SRV_SHOW_PROGRESS" proc="vapp_da_evt_show_progress"/>	
	<RECEIVER id="EVT_ID_DLA_SRV_POPUP_FOR_JOB_MSG" proc="vapp_da_evt_popup_for_job_msg"/>	
	<RECEIVER id="EVT_ID_DLA_SRV_POPUP" proc="vapp_da_evt_popup"/>	
	<RECEIVER id="EVT_ID_DLA_SRV_DISPLAY_JOB_LIST" proc="vapp_da_evt_display_job_list"/>	
	<RECEIVER id="EVT_ID_DLA_SRV_PROGRESSING_CLOSE" proc="vapp_da_evt_close_processing"/>	
	<RECEIVER id="EVT_ID_DLA_SRV_POPUP_ERRORCODE_WITH_CALLBACK" proc="vapp_da_evt_popup_error_code_with_callback"/>	
	<RECEIVER id="EVT_ID_DLA_SRV_SHOW_NEW_DOWNLOAD_CONFIRM_SCREEN" proc="vapp_da_evt_new_download_confirm_screen"/>	
	<RECEIVER id="EVT_ID_DLA_SRV_SET_ACTIVE_DOWNLOAD_CONFIRM_SCREEN" proc="vapp_da_return_mmi_ok"/>	
	<RECEIVER id="EVT_ID_DLA_SRV_WPS_HTTP_RSP_CALLBACK" proc="vapp_da_evt_wps_http_rsp_callback"/>	
	<RECEIVER id="EVT_ID_DLA_SRV_CONFIRM_OMA_DOWNLOAD" proc="vapp_da_return_mmi_ok"/>
	<RECEIVER id="EVT_ID_DLA_SRV_OMA_HANDLE_HTTP_RSP" proc="vapp_da_return_mmi_ok"/>
	<RECEIVER id="EVT_ID_DLA_SRV_SHOW_USER_AUTH_SCREEN" proc="vapp_da_evt_show_user_auth_screen"/>
	<RECEIVER id="EVT_ID_DLA_SRV_PUSH_PROCESS_ITEM" proc="vapp_da_return_mmi_ok"/>
	<RECEIVER id="EVT_ID_DLA_SRV_UPDATE_JOB_STATUS" proc="vapp_da_evt_update_job_status"/>
	<RECEIVER id="EVT_ID_DLA_SRV_CLICK_JOB" proc="vapp_da_return_mmi_ok"/>
	<RECEIVER id="EVT_ID_DLA_SRV_JOB_ABORTED_CALLBACK" proc="vapp_da_evt_job_aborted_callback"/>
	<RECEIVER id="EVT_ID_DLA_SRV_REMOVE_JOB_SCREENS" proc="vapp_da_return_mmi_ok"/>
	<RECEIVER id="EVT_ID_DLA_SRV_UPDATE_NCENTER" proc="vapp_da_evt_update_ncenter"/>
	<RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="vapp_da_evt_enter_usb_mode"/>
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="vapp_da_evt_flight_mode"/>
	<RECEIVER id="EVT_ID_SRV_FMGRI_CARD_PLUG_IN" proc="vapp_da_evt_memory_card_plug"/>
	<RECEIVER id="EVT_ID_SRV_FMGRI_CARD_PLUG_OUT" proc="vapp_da_evt_memory_card_plug"/>
	
	<RECEIVER id="EVT_ID_DLA_SRV_SELECT_STORAGE" proc="NULL"/>
	<RECEIVER id="EVT_ID_DLA_SRV_SET_STORAGE_INSTANCE" proc="NULL"/>	
	<RECEIVER id="EVT_ID_DLA_SRV_DISPLAY_JOB_DETAIL" proc="vapp_da_evt_display_job_detail"/>			
	<RECEIVER id="EVT_ID_DLA_SRV_DRM_SAVE_AS" proc="NULL"/>
	<RECEIVER id="EVT_ID_DLA_SRV_UPDATE_CONTENT_BY_DRM_PROCESSING" proc="NULL"/>
	<RECEIVER id="EVT_ID_DLA_SRV_CLOSE_APP" proc="vapp_da_evt_close_app"/>
	<RECEIVER id="EVT_ID_DLA_SRV_POPUP_ERROR_FOR_JOB" proc="vapp_da_evt_popup_error_for_job"/>
	<RECEIVER id="EVT_ID_DLA_SRV_POPUP_FOR_JOB" proc="vapp_da_evt_popup_for_job"/>

#if defined (__SIM_HOT_SWAP_SUPPORT__)
	<RECEIVER id="EVT_ID_SRV_SIM_CTRL_UNAVAILABLE" proc="vapp_dla_evt_handle_sim_indication"/>
#endif
        <RECEIVER id="EVT_ID_DLA_SRV_IS_USB_AVAILABLE" proc="vapp_da_evt_usb_available"/>
</APP>
#endif //__MMI_DOWNLOAD_AGENT__