#include "mmi_features.h"
#include "CustResDef.h"         /* for image/audio path */
<?xml version="1.0" encoding="UTF-8"?>

/* Needed header files of the compile option in XML files, if you need others need to add here */
#ifdef __MMI_MMS_2__


/* APP tag, include your app name defined in MMIDataType.h */

<APP id="SRV_MMS">

    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,GlobalMenuItems.h" />


	
 
           <!------------------------------------------------------callback manager  sender part---------------------------------------------------------->
           
       <EVENT id="EVT_ID_SRV_MMS_UPDATE_STATUS" type="SENDER"/>
       <EVENT id="EVT_ID_SHOW_HIDE_ICON" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_MMS_READY" type="SENDER"/>
       <EVENT id="EVT_ID_MMA_INSUF_MEM" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_MMS_DEINIT" type="SENDER"/>
       <EVENT id="EVT_ID_JSR_DELETE_MMS" type="SENDER"/>
       #if defined(__MMI_MMS_USE_ASM__) && defined(__MMI_MMS_2__)
       <EVENT id="EVT_ID_SRV_ASM_SUCCESS" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_ASM_STOP" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_ASM_CANCEL" type="SENDER"/>
       #endif
       #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
       <EVENT id="EVT_ID_SRV_CHK_CARD_PLUG_OUT" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_CHANGE_STORAGE" type="SENDER"/>
       #endif
       
       <EVENT id="EVT_ID_SRV_SET_SETTING" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_APP_ERROR" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_SAVE_OBJECTS_ERROR" type="SENDER"/>
       
        
       <EVENT id="EVT_ID_SRV_TEMPLATE_ERROR" type="SENDER"/>
	   #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
       <EVENT id="EVT_ID_SRV_UPDATE_TEMPLTAE_DEL_FRM_PSUIT" type="SENDER"/>
           
       <EVENT id="EVT_ID_SRV_UPDATE_TEMPLTAE_DEL_FRM_PSUIT_SET_FLAG" type="SENDER"/>
       #endif
       <EVENT id="EVT_ID_SRV_SHOW_STATUS" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_SAVE_RSP_FROM_UC" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_BOOTUP_INIT" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_INVALID_POPUP" type="SENDER"/>
       #ifdef __MMI_MMS_URI_AGENT__
       <EVENT id="EVT_ID_SRV_URI_CONFIRM_POPUP" type="SENDER"/>
       #endif
       #ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
       <EVENT id="EVT_ID_SRV_UPDATE_USE_DETAILS_LIST" type="SENDER"/>   
       #endif
       <EVENT id="EVT_ID_SRV_EXIT_VIEWER_APP" type="SENDER"/>   
       <EVENT id="EVT_ID_SRV_CURR_MSG_UPDATE" type="SENDER"/>   
       <EVENT id="EVT_ID_SRV_SHOW_BGSR_POPUP" type="SENDER"/> 
       #if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)  
       <EVENT id="EVT_ID_SRV_NEW_MMS" type="SENDER"/>   
       #endif
       
       <EVENT id="EVT_ID_SRV_CURR_MSG_SELECT" type="SENDER"/>   
       <EVENT id="EVT_ID_SRV_WAP_READY" type="SENDER"/>   
       <EVENT id="EVT_ID_SRV_STORAGE_FULL_IND" type="SENDER"/>   
       
       <EVENT id="EVT_ID_SRV_UPDATE_MEM_STATUS" type="SENDER"/>   
       
       <EVENT id="EVT_ID_SRV_HDL_CARD_PLUG_OUT" type="SENDER"/> 
         
       <EVENT id="EVT_ID_SRV_BGSR_RESULT" type="SENDER"/>   
       <EVENT id="EVT_ID_SRV_SAVE_OBJECT_COPY_RESULT_HDL" type="SENDER"/>   
       <EVENT id="EVT_ID_SRV_CHECK_AND_DELETE_PROGRESS" type="SENDER"/>
       
       <EVENT id="EVT_ID_SRV_NEW_MMS_MSG" type="SENDER"/>
       <EVENT id="EVT_ID_UMMS_DEINIT_FROM_HISTORY" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_PROCESSING_TEMPLATE" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_MMS_MMA_TERMINATE" type="SENDER"/>
       
#ifdef __MMI_MMS_BGSR_SUPPORT__
#ifdef __MMI_MMS_FALLBACK__
       <EVENT id="EVT_ID_SRV_BGSR_FALLBACK_CUI_CREATE" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_BGSR_FALLBACK_CUI_CLOSE" type="SENDER"/>
#endif /*__MMI_MMS_FALLBACK__*/    
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
       
#ifndef __COSMOS_MMI_PACKAGE__
#ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
       <EVENT id="EVT_ID_SRV_JSR_JAVA_MMS_SEND_ERROR" type="SENDER"/>
#endif 	/* __MMI_OP12_MMS_MAX_SIZE_SUPPORT__ */
#endif    /* __COSMOS_MMI_PACKAGE__ */
      
       <EVENT id="EVT_ID_SRV_MMS_SEND_REFRESH" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_MMS_SEND_URI_IND" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_MMS_MEM_FULL" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_MMS_GET_CURR_MSG_BOX" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_MMS_NMGR_ALERT" type="SENDER"/>
       
       
       <EVENT id="EVT_ID_SRV_MMS_IN_USE_MSG_ID" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_MMS_READY_FOR_LITE_VIEWER" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_MMS_TEMPLATE_GEN_RESULT" type="SENDER"/>
       
#ifdef __MMI_MMS_USE_ASM__
	   <EVENT id="EVT_ID_SRV_MMS_SERVICE_MEM_FREE_DONE" type="SENDER"/>
#endif
    
<!------------------------------------------------------callback manager reciever part---------------------------------------------------------->


          
        <RECEIVER id="EVT_ID_SRV_MMS_IN_USE_MSG_ID" proc="mmi_umms_app_if_msg_in_view"/>
        <RECEIVER id="EVT_ID_SRV_MMS_IN_USE_MSG_ID" proc="mmi_umms_app_if_is_mms_in_open_state"/>
        
       <RECEIVER id="EVT_ID_MMI_UM_ENTRY_FOLDER" proc="srv_mms_entry_folder_hdlr"/>
       <RECEIVER id="EVT_ID_MMA_INSUF_MEM" proc="mmi_umms_app_core_mma_insuf_mem"/>
       <RECEIVER id="EVT_ID_SRV_MMS_DEINIT" proc="mmi_umms_app_core_mms_deinit"/>
          #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
       <RECEIVER id="EVT_ID_SRV_CHK_CARD_PLUG_OUT" proc="mmi_umms_app_core_handle_sd_card_plug_out"/>
       
       <RECEIVER id="EVT_ID_SRV_CHANGE_STORAGE" proc="mmi_umms_app_core_handle_change_storage_rsp"/>
            #endif
            
       <RECEIVER id="EVT_ID_SRV_SET_SETTING" proc="mmi_umms_app_dtmgr_send_set_settings_to_service"/>
       <RECEIVER id="EVT_ID_SRV_APP_ERROR" proc="mmi_umms_app_core_show_error_popup"/>
       <RECEIVER id="EVT_ID_SRV_SAVE_OBJECTS_ERROR" proc="mmi_umms_app_ui_plug_in_save_object_error_handling"/>

       
       <RECEIVER id="EVT_ID_SRV_TEMPLATE_ERROR" proc="mmi_umms_app_core_handle_template_error_event"/> // defined in mmsappsrvhdlr.h 
	   #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
       <RECEIVER id="EVT_ID_SRV_UPDATE_TEMPLTAE_DEL_FRM_PSUIT" proc="mmi_umms_app_core_update_template_list_after_phone_suite_delete"/> 
       <RECEIVER id="EVT_ID_SRV_UPDATE_TEMPLTAE_DEL_FRM_PSUIT_SET_FLAG" proc="mmi_umms_app_dtmgr_set_userdef_template_del_from_phone_suite_flag"/>
       #endif
      
       
        <RECEIVER id="EVT_ID_SRV_SHOW_STATUS" proc="mmi_umms_app_core_show_mms_status_icon"/>
        <RECEIVER id="EVT_ID_SRV_SAVE_RSP_FROM_UC" proc="mmi_umms_app_core_save_rsp_from_uc"/>
        <RECEIVER id="EVT_ID_SRV_BOOTUP_INIT" proc="mmi_umms_app_core_bootup_init"/>
        <RECEIVER id="EVT_ID_SRV_INVALID_POPUP" proc="mmi_umms_app_core_display_invalid_popup"/>
        #ifdef __MMI_MMS_URI_AGENT__
        <RECEIVER id="EVT_ID_SRV_URI_CONFIRM_POPUP" proc="mmi_umms_app_core_mms_display_uri_confirm_popup"/>
        #endif
        #ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
        <RECEIVER id="EVT_ID_SRV_UPDATE_USE_DETAILS_LIST" proc="mmi_umms_app_core_update_use_details_list"/>
        #endif

        <RECEIVER id="EVT_ID_SRV_EXIT_VIEWER_APP" proc="mmi_umms_app_core_exit_viewer_application"/>
        
         <RECEIVER id="EVT_ID_SRV_CURR_MSG_UPDATE" proc="mmi_umms_app_core_check_crnt_selected_msg_for_update"/>
         <RECEIVER id="EVT_ID_SRV_SHOW_BGSR_POPUP" proc="mmi_umms_app_core_display_bgsr_popup"/>
         #if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
         <RECEIVER id="EVT_ID_SRV_NEW_MMS" proc="mmi_umms_app_core_set_new_mms_arrived"/>
         #endif
         <RECEIVER id="EVT_ID_SRV_CURR_MSG_SELECT" proc="mmi_umms_app_core_check_crnt_selected_msg"/>
         <RECEIVER id="EVT_ID_SRV_WAP_READY" proc="mmi_umms_app_core_wap_ready_hdlr"/>
         <RECEIVER id="EVT_ID_SRV_STORAGE_FULL_IND" proc="mmi_umms_app_core_get_storage_full_ind_data"/>
         <RECEIVER id="EVT_ID_SRV_UPDATE_MEM_STATUS" proc="mmi_umms_app_core_memory_status_screen_update"/>
         
         
         <RECEIVER id="EVT_ID_SRV_HDL_CARD_PLUG_OUT" proc="mmi_umms_app_core_check_card_plug_out_handling"/>
         
         
         <RECEIVER id="EVT_ID_SRV_BGSR_RESULT" proc="mmi_umms_app_core_mms_display_popup_for_bgsr"/>
         <RECEIVER id="EVT_ID_SRV_SAVE_OBJECT_COPY_RESULT_HDL" proc="mmi_umms_app_core_hanlde_save_objects_copy_result"/>
         <RECEIVER id="EVT_ID_SRV_CHECK_AND_DELETE_PROGRESS" proc="mmi_umms_app_ui_plug_in_check_and_delete_progress_screen"/>
        
         #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
         <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="mmi_umms_sd_card_plug_in_hdlr_cb"/>     
           #endif
          #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ 
         <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_umms_sd_card_plug_out_hdlr_cb"/>     
            #endif
           
         <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="mmi_umms_drv_format_hdlr_cb"/>     
            
         <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABLE" proc="srv_mms_sim_available_hdlr"/>    
          
         <RECEIVER id="EVT_ID_SRV_SIM_CTRL_UNAVAILABLE" proc="srv_mms_sim_unavailable_hdlr"/>
         
         	<RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="srv_mms_usb_mode_off"/>
         	<RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="srv_mms_usb_mode_on"/>
          	
            
         <RECEIVER id="EVT_ID_IDLE_GROUP_ENTER" proc="mmi_umms_app_core_idle_hdlr"/>
           
         <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="srv_mms_mode_switch_finish_event_hdlr"/>
		 <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="srv_mms_sim_availability_handler"/>
#ifdef __MMI_MMS_BGSR_SUPPORT__
         <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="srv_mms_bgsr_drive_format_hdlr"/>
         <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="srv_mms_bgsr_usb_start_cb"/>
         <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="srv_mms_bgsr_usb_end_cb"/>
         <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="srv_mms_bgsr_sim_status_info_hdlr"/>
         <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="srv_mms_bgsr_sim_status_info_hdlr"/>
#ifdef __MMI_MMS_FALLBACK__
         <RECEIVER id="EVT_ID_SRV_BGSR_FALLBACK_CUI_CREATE" proc="mmi_umms_app_bearer_fallback_cui_hdlr"/>
         <RECEIVER id="EVT_ID_SRV_BGSR_FALLBACK_CUI_CLOSE" proc="mmi_umms_app_bearer_fallback_cui_hdlr"/>
#endif
#endif        
    
#ifdef MMS_SUPPORT  
         <RECEIVER id="EVT_ID_SRV_NW_INFO_ROAMING_STATUS_CHANGED" proc="mmi_mms_on_roaming_status_changed"/>
#endif
#ifndef __COSMOS_MMI_PACKAGE__      
        <RECEIVER id="EVT_ID_SHOW_HIDE_ICON" proc="mmi_umms_app_core_show_hide_status_icon"/>
#endif

		<RECEIVER id="EVT_ID_SRV_MMS_MMA_TERMINATE" proc="mmi_umms_app_core_dummy_listener"/>
    
#ifndef __COSMOS_MMI_PACKAGE__
#ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
        <RECEIVER id="EVT_ID_SRV_JSR_JAVA_MMS_SEND_ERROR" proc="mmi_umms_app_core_display_jsr_popup"/>
#endif 	/* __MMI_OP12_MMS_MAX_SIZE_SUPPORT__ */
#endif    /* __COSMOS_MMI_PACKAGE__ */
              
   <RECEIVER id="EVT_ID_SRV_MMS_SEND_REFRESH" proc="srv_mms_post_refresh_cb"/>           

#ifdef __COSMOS_MMI_PACKAGE__      
        <RECEIVER id="EVT_ID_SRV_MMS_MEM_FULL" proc="mmi_umms_app_core_show_popup"/>
        
#endif
#ifndef __COSMOS_MMI_PACKAGE__
<RECEIVER id="EVT_ID_SRV_MMS_GET_CURR_MSG_BOX" proc="mmi_umms_app_core_get_current_msg_box"/>
#endif
<RECEIVER id="EVT_ID_SRV_MMS_NMGR_ALERT" proc="mmi_umms_app_core_nmgr_alert"/>          
    <RECEIVER id="EVT_ID_JSR_DELETE_MMS" proc="mmi_umms_op_update_recent_event_list_from_phone_suit"/>

#ifdef __COSMOS_MMI_PACKAGE__
	<RECEIVER id="EVT_ID_VAPP_LANGUAGE_CHANGED" proc="mmi_umms_app_lang_changed_hdlr"/>
#endif 

/*DM LAWMO REVISE*/
#ifdef __DM_LAWMO_SUPPORT__
   
   /*LAWMO LOCK CALLBACK*/
   <RECIEVER id="EVT_ID_SRV_DM_LAWMO_LOCK_IND" proc="mmi_umms_app_core_mo_type_lawmo_lock_callback_hdlr"/>
   
   /*LAWMO WIPE CALLBACK*/
   <RECIEVER id="EVT_ID_SRV_DM_LAWMO_WIPE_IND" proc="mmi_umms_app_core_mo_type_lawmo_wipe_callback_hdlr"/>
   
    
#endif /*__DM_LAWMO_SUPPORT__*/   

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
#ifndef __COSMOS_MMI_PACKAGE__
<RECIEVER id="EVT_ID_SRV_MMS_TEMPLATE_GEN_RESULT" proc="mmi_umms_app_dtmgr_tmplt_gen_hdlr"/>
#endif
<RECIEVER id="EVT_ID_SETTING_LANGUAGE_CHANGED" proc="srv_mms_default_template_lang_changed_hdlr"/>
#endif
<!------------------------------------------------------ MMI CACHE ------------------------------------------------------------->
     
     <!------------------------------------------------------ DOUBLE CACHE ------------------------------------------------------------->
     
     <CACHEDATA type="double" id="NVRAM_UMMS_RETRIEVAL_SETTINGS" restore_flag="TRUE" restore_id="@NVRAM_UMMS_RESTORE_RETRIEVAL_SETTINGS">
     
     #if (defined(__OP11__))
		<DEFAULT_VALUE> [0x01, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00] </DEFAULT_VALUE>
	 #elif (defined(__OP12__))
		<DEFAULT_VALUE> [0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00] </DEFAULT_VALUE>
	 #elif (defined(__OP01__))
		<DEFAULT_VALUE> [0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00] </DEFAULT_VALUE>
	 #elif (defined(__COSMOS_MMI_PACKAGE__))
		 <DEFAULT_VALUE> [0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00] </DEFAULT_VALUE>
	 #else	
        <DEFAULT_VALUE> [0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00] </DEFAULT_VALUE>
     #endif 
        <DESCRIPTION> MMS V02 MMS Retrieval Settings </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NVRAM_UMMS_RESTORE_RETRIEVAL_SETTINGS">
    
    #if (defined(__OP11__))
		<DEFAULT_VALUE> [0x01, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00] </DEFAULT_VALUE>
	 #elif (defined(__OP12__))
		<DEFAULT_VALUE> [0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00] </DEFAULT_VALUE>
	 #elif (defined(__OP02__))
		<DEFAULT_VALUE> [0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00] </DEFAULT_VALUE>		
	 #elif (defined(__COSMOS_MMI_PACKAGE__))
		 <DEFAULT_VALUE> [0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00] </DEFAULT_VALUE>	 
	 #else	
        <DEFAULT_VALUE> [0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00] </DEFAULT_VALUE>
     #endif  
        <DESCRIPTION> Double cache </DESCRIPTION>
    </CACHEDATA>
    
    
    <!------------------------------------------------------ SHORT CACHE ------------------------------------------------------------->
    
     <CACHEDATA type="short" id="NVRAM_UMMS_LANGUAGE_CHANGE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
    
    
    <!------------------------------------------------------ BYTE CACHE ------------------------------------------------------------->

    <CACHEDATA type="byte" id="NVRAM_SETTING_PREFER_MMS_STORAGE_MODE" restore_flag="TRUE">
    #ifdef  __COSMOS_NO_USER_DRIVE__
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
    #else
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
    #endif
        <DESCRIPTION> MMS Storage </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_SETTING_MMS_MSG_FILTER" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> MMS Storage Filter</DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="byte" id="NVRAM_UMMS_DEF_TMPLT_GEN_STATE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> MMS Templates Gen state </DESCRIPTION>
    </CACHEDATA>


   <!------------------------------------------------------ TIMERS ------------------------------------------------------------->
    <TIMER id="UMMS_SEND_TIMER"/>
    #ifdef __MMI_MMS_ROAMING_NO_ACCEPT_SUPPORT__
    <TIMER id="UMMS_NOTIFY_TIMER"/>
    #endif
    <TIMER id="UMMS_DOWNLOAD_TIMER"/>
    <TIMER id="MMS_VIEWER_TIMER"/>
    <TIMER id="SRV_MMS_BGSR_TIMER"/>
    <TIMER id="UMMS_SETTINGS_TIMER"/>


/* String Ids of MMA */
    <STRING id="MMA_STR_ID_MESSAGE_CORRUPT" />
    <STRING id="MMA_STR_ID_MESSAGE_UNSUPPORTED"/>
	<STRING id="MMA_STR_ID_MMS_DELIVERY_REPORT"/>
	<STRING id="MMA_STR_ID_MMS_READ_REPORT"/>
#ifdef __MMI_MMS_GROUP_MSG__    
    <STRING id="MMA_STR_ID_MMS_GROUP_MESSAGE"/>
#endif
#if defined ( __MMI_MMS_GROUP_MSG__) || defined ( __MMI_OP12_MMS_GROUP_MSG_SUPPORT__)    
    <STRING id="MMA_STR_ID_GROUP_MSG_RECIPIENT"/>
#endif
    <STRING id="MMS_STR_ID_EMPTY_STRING" />
    <STRING id="MMS_STR_ID_RR_TEXT_FROM" />
    <STRING id="MMS_STR_ID_RR_TEXT_MSGID" />
	<STRING id="MMS_STR_ID_RR_TEXT_READ"/>
	<STRING id="MMS_STR_ID_RR_TEXT_SENT"/>
	<STRING id="MMS_STR_ID_RR_TEXT_SUBJECT"/>
	<STRING id="MMS_STR_ID_RR_TEXT_TO"/>
	<STRING id="MMS_STR_ID_RR_TEXT_WAS_READ"/>
	<STRING id="MMS_STR_ID_RR_TEXT_YOUR_MSG"/>	
/* String Ids of MMA end */


/* Applications  */

<STRING id="STR_ID_UMMS_NEW_MMS" />
<STRING id="STR_ID_UMMS_NEW_MMS_FROM_SIM1" />
<STRING id="STR_ID_UMMS_NEW_MMS_FROM_SIM2" />
<STRING id="STR_ID_UMMS_NEW_MMS_FROM_SIM3" />
<STRING id="STR_ID_UMMS_NEW_MMS_FROM_SIM4" />
<STRING id="STR_ID_MMS_VIEWER_TEXT_STRIPPED" />

#ifdef __MMI_MMS_REPORT_BOX_SUPPORT__	
	<STRING id="STR_ID_UMMS_NEW_DR"/>
	<STRING id="STR_ID_UMMS_NEW_RR"/>
#endif

#ifdef __MMI_OP11_MMS_SEND_TO_PHOTO_BLOG__
     <STRING id="STR_FMGR_UMMS_TO_BLOG"/>
#endif

#ifdef __MMI_MMS_POSTCARD__
    <STRING id="STR_FMGR_UMMS_TO_POSTCARD"/>
#endif

#if defined (__MMI_MMS_REPORT_STATUS_MENU_SUPPORT__) || defined (__MMI_MMS_REPORT_BOX_SUPPORT__)
	<STRING id="STR_ID_UMMS_STATUS_PENDING" />
	<STRING id="STR_ID_UMMS_STATUS_DELIVERED" />
	<STRING id="STR_ID_UMMS_STATUS_EXPIRED" />
	<STRING id="STR_ID_UMMS_STATUS_REJECTED" />
	<STRING id="STR_ID_UMMS_STATUS_DEFERRED" />
	<STRING id="STR_ID_UMMS_STATUS_UNRECOGNIZED" />
    <STRING id="STR_ID_UMMS_STATUS_INTERMEDIATE" />
    <STRING id="STR_ID_UMMS_STATUS_FORWARDED" />
    <STRING id="STR_ID_UMMS_STATUS_UNREACHABLE" />
    <STRING id="STR_ID_UMMS_STATUS_READ" />
	<STRING id="STR_ID_UMMS_STATUS_DELETED_WITHOUT_READ"/>
	<STRING id="STR_ID_UMMS_STATUS_FAILED_TO_DELIVER_TO"/>
	<STRING id="STR_ID_UMMS_STATUS_DELIVERED_TO" />
	<STRING id="STR_ID_UMMS_STATUS_READ_BY" />
#endif
#ifdef __MMI_MMS_USE_ASM__
    <STRING id="STR_ID_UMMS_MMS_SERVICE"/>	
#endif

<!------------------------------------------------------ MMS TEMPLATE RESOURCES ------------------------------------------------------------->
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
#ifndef __MMI_MMS_TEMPLATES_NUM__
#define __MMI_MMS_TEMPLATES_NUM__ 5
#endif
	#if (__MMI_MMS_TEMPLATES_NUM__>0)
    	<STRING id="STR_ID_UMMS_TEMPLATES_TITLE_01" />
	#endif
	#if (__MMI_MMS_TEMPLATES_NUM__>1)
		<STRING id="STR_ID_UMMS_TEMPLATES_TITLE_02" />
	#endif
	#if (__MMI_MMS_TEMPLATES_NUM__>2)
		<STRING id="STR_ID_UMMS_TEMPLATES_TITLE_03" />
	#endif
	#if (__MMI_MMS_TEMPLATES_NUM__>3)
		<STRING id="STR_ID_UMMS_TEMPLATES_TITLE_04" />
	#endif
	#if (__MMI_MMS_TEMPLATES_NUM__>4)
		<STRING id="STR_ID_UMMS_TEMPLATES_TITLE_05" />
	#endif
	#if (__MMI_MMS_TEMPLATES_NUM__>5)
		<STRING id="STR_ID_UMMS_TEMPLATES_TITLE_06" />
	#endif
	#if (__MMI_MMS_TEMPLATES_NUM__>6)
		<STRING id="STR_ID_UMMS_TEMPLATES_TITLE_07" />
	#endif
	#if (__MMI_MMS_TEMPLATES_NUM__>7)
		<STRING id="STR_ID_UMMS_TEMPLATES_TITLE_08" />
	#endif
	#if (__MMI_MMS_TEMPLATES_NUM__>8)
		<STRING id="STR_ID_UMMS_TEMPLATES_TITLE_09" />
	#endif
	#if (__MMI_MMS_TEMPLATES_NUM__>9)
		<STRING id="STR_ID_UMMS_TEMPLATES_TITLE_10" />
	#endif

#if (__MMI_MMS_TEMPLATES_NUM__>0)
    <IMAGE id="IMG_ID_UMMS_TEMPLATES_01" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T01.gif"</IMAGE>
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>1)
    <IMAGE id="IMG_ID_UMMS_TEMPLATES_02" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T02.gif"</IMAGE>
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>2)
    <IMAGE id="IMG_ID_UMMS_TEMPLATES_03" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T03.gif"</IMAGE>
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>3)
    <IMAGE id="IMG_ID_UMMS_TEMPLATES_04" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T04.gif"</IMAGE>
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>4)
    <IMAGE id="IMG_ID_UMMS_TEMPLATES_05" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T05.gif"</IMAGE>
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>5)
    <IMAGE id="IMG_ID_UMMS_TEMPLATES_06" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T06.gif"</IMAGE>
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>6)
    <IMAGE id="IMG_ID_UMMS_TEMPLATES_07" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T07.gif"</IMAGE>
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>7)
    <IMAGE id="IMG_ID_UMMS_TEMPLATES_08" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T08.gif"</IMAGE>
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>8)
    <IMAGE id="IMG_ID_UMMS_TEMPLATES_09" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T09.gif"</IMAGE>
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>9)
    <IMAGE id="IMG_ID_UMMS_TEMPLATES_10" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T10.gif"</IMAGE>
#endif
    
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>

#if (__MMI_MMS_TEMPLATES_NUM__>0)
    <AUDIO id="AUDIO_ID_UMMS_TEMPLATES_01" force_type="FORCE_ADO_MIDI" > CUST_ADO_PATH"\\\\MMS\\\\mms01.mid"</AUDIO>
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>1)
    <AUDIO id="AUDIO_ID_UMMS_TEMPLATES_02" force_type="FORCE_ADO_MIDI" > CUST_ADO_PATH"\\\\MMS\\\\mms02.mid"</AUDIO>
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>2)
    <AUDIO id="AUDIO_ID_UMMS_TEMPLATES_03" force_type="FORCE_ADO_MIDI" > CUST_ADO_PATH"\\\\MMS\\\\mms03.mid"</AUDIO>
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>3)
    <AUDIO id="AUDIO_ID_UMMS_TEMPLATES_04" force_type="FORCE_ADO_MIDI" > CUST_ADO_PATH"\\\\MMS\\\\mms04.mid"</AUDIO>
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>4)
    <AUDIO id="AUDIO_ID_UMMS_TEMPLATES_05" force_type="FORCE_ADO_MIDI" > CUST_ADO_PATH"\\\\MMS\\\\mms05.mid"</AUDIO>
#endif

#endif
<!------------------------------------------------------ MMS TEMPLATE RESOURCES END ------------------------------------------------------------->

	<IMAGE id="IMG_ID_SRV_MMS_VIEWER_APP" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\SB_mms.bmp"</IMAGE>

#ifndef __COSMOS_MMI_PACKAGE__
/* Image Id and path of MMA */
#ifndef __MMI_SMS_BOX_ICON_SLIM__ 
    <IMAGE id="MMA_IMG_LETTER_CREATED" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\draft\\\\mmsdraft.bmp"</IMAGE>
#endif /* __MMI_SMS_BOX_ICON_SLIM__ */    
    <IMAGE id="MMA_IMG_CORRUPT" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\MMS_corrupted.bmp"</IMAGE>
#ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
    <IMAGE id="MMA_IMG_REPORT_BOX_RR" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\reportbox\\\\Read_report.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_REPORT_BOX_DR" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\reportbox\\\\Delivery_report.bmp"</IMAGE>
#endif
#ifdef __MMI_ULTRA_SLIM_MMS_2__
#ifndef __MMI_SMS_BOX_ICON_SLIM__ 
    <IMAGE id="MMA_IMG_LETTER" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_message.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_LETTER_READ" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_messageread.bmp"</IMAGE>
#endif /* __MMI_SMS_BOX_ICON_SLIM__ */    
    <IMAGE id="MMA_IMG_NOTIF" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\notification\\\\notification.bmp"</IMAGE>
#else
    <IMAGE id="MMA_IMG_LOCK_MODE" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\SB_MMSLOCK.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_LETTER_JAVA" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Jsr\\\\mms_messagejsr.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_FORWARD_LOCK_READ_PRIO_HIGH" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock_read_h.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_FORWARD_LOCK_READ_PRIO_LOW" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock_read_l.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_FORWARD_LOCK_PRIO_HIGH" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock_h.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_FORWARD_LOCK_PRIO_LOW" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock_l.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_FORWARD_LOCK" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_FORWARD_LOCK_READ" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock_read.bmp"</IMAGE>
#ifndef __MMI_SLIM_MMS_2__
    <IMAGE id="MMA_IMG_FORWARD_LOCK_ATTACHMENT_READ_PRIO_HIGH" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_ALmessageread_h.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_FORWARD_LOCK_ATTACHMENT_READ_PRIO_LOW" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_ALmessageread_l.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_FORWARD_LOCK_ATTACHMENT_PRIO_HIGH" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_ALmessage_h.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_FORWARD_LOCK_ATTACHMENT_PRIO_LOW" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_ALmessage_l.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_FORWARD_LOCK_ATTACHMENT" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_ALmessage.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_FORWARD_LOCK_ATTACHMENT_READ" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_ALmessageread.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_ATTACHMENT_READ_PRIO_HIGH" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_Amessageread_h.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_ATTACHMENT_READ_PRIO_LOW" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_Amessageread_l.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_ATTACHMENT_PRIO_HIGH" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_Amessage_h.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_ATTACHMENT_PRIO_LOW" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_Amessage_l.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_ATTACHMENT" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_Amessage.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_ATTACHMENT_READ" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_Amessageread.bmp"</IMAGE>
#endif /* __MMI_SLIM_MMS_2__ */
    <IMAGE id="MMA_IMG_LETTER" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_message.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_LETTER_READ" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_messageread.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_LETTER_READ_PRIO_HIGH" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_messageread_h.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_LETTER_READ_PRIO_LOW" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_messageread_l.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_LETTER_PRIO_HIGH" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_message_h.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_LETTER_PRIO_LOW" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_message_l.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_NOTIF" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\notification\\\\notification.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_NOTIF_PRIO_HIGH" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\notification\\\\notification_h.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_NOTIF_PRIO_LOW" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\notification\\\\notification_l.bmp"</IMAGE>
#ifndef __MMI_MMS_REPORT_BOX_SUPPORT__
    <IMAGE id="MMA_IMG_RR" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\readreport\\\\mms_read.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_RR_READ" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\readreport\\\\mms_read_read.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_DR" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\deliveryreport\\\\mms_delivery.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_DR_READ" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\deliveryreport\\\\mms_delivery_read.bmp"</IMAGE>
#endif
#if defined (__MMI_OP11_MMS_SUPPORT_AUDIO_MSG__) || defined (__MMI_MMS_VOICE_MESSAGE_HANDLING__)
    <IMAGE id="MMA_IMG_AUDIO" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Audiounread.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_AUDIO_PRIO_HIGH" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Audiounread_h.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_AUDIO_PRIO_LOW" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Audiounread_l.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_AUDIO_READ" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Audioread.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_AUDIO_READ_PRIO_HIGH" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Audioread_h.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_AUDIO_READ_PRIO_LOW" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Audioread_l.bmp"</IMAGE>
#endif
#ifdef __MMI_OP11_MMS_SUPPORT_VIDEO_MSG__
    <IMAGE id="MMA_IMG_VIDEO" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Videounread.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_VIDEO_PRIO_HIGH" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Videounread_h.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_VIDEO_PRIO_LOW" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Videounread_l.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_VIDEO_READ" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Videoread.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_VIDEO_READ_PRIO_HIGH" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Videoread_h.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_VIDEO_READ_PRIO_LOW" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Videoread_l.bmp"</IMAGE>
#endif
#ifdef __MMI_OP11_MMS_SUPPORT_PHOTO_MSG__
    <IMAGE id="MMA_IMG_PHOTO" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Picunread.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_PHOTO_PRIO_HIGH" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Picunread_h.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_PHOTO_PRIO_LOW" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Picunread_l.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_PHOTO_READ" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Picread.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_PHOTO_READ_PRIO_HIGH" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Picread_h.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_PHOTO_READ_PRIO_LOW" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Picread_l.bmp"</IMAGE>
#endif
#ifdef __MMI_MMS_POSTCARD__
    <IMAGE id="MMA_IMG_POSTCARD_MMS" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_postcard.bmp"</IMAGE>
#endif
#ifdef __MMI_MMS_GROUP_MSG__
    <IMAGE id="MMA_IMG_GROUP" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Gmessageunread.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_GROUP_PRIO_HIGH" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Gmessageunread_h.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_GROUP_PRIO_LOW" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Gmessageunread_l.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_GROUP_READ" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Gmessageread.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_GROUP_READ_PRIO_HIGH" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Gmessageread_h.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_GROUP_READ_PRIO_LOW" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Gmessageread_l.bmp"</IMAGE>
#if defined (__MMI_OP11_MMS_SUPPORT_AUDIO_MSG__) || defined (__MMI_MMS_VOICE_MESSAGE_HANDLING__)
    <IMAGE id="MMA_IMG_GROUP_AUDIO" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GAudiounread.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_GROUP_AUDIO_PRIO_HIGH" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GAudiounread_h.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_GROUP_AUDIO_PRIO_LOW" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GAudiounread_l.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_GROUP_AUDIO_READ" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GAudioread.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_GROUP_AUDIO_READ_PRIO_HIGH" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GAudioread_h.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_GROUP_AUDIO_READ_PRIO_LOW" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GAudioread_l.bmp"</IMAGE>
#endif
#ifdef __MMI_OP11_MMS_SUPPORT_VIDEO_MSG__
    <IMAGE id="MMA_IMG_GROUP_VIDEO" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GVideounread.pbm"</IMAGE>
    <IMAGE id="MMA_IMG_GROUP_VIDEO_PRIO_HIGH" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GVideounread_h.pbm"</IMAGE>
    <IMAGE id="MMA_IMG_GROUP_VIDEO_PRIO_LOW" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GVideounread_l.pbm"</IMAGE>
    <IMAGE id="MMA_IMG_GROUP_VIDEO_READ" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GVideoread.pbm"</IMAGE>
    <IMAGE id="MMA_IMG_GROUP_VIDEO_READ_PRIO_HIGH" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GVideoread_h.pbm"</IMAGE>
    <IMAGE id="MMA_IMG_GROUP_VIDEO_READ_PRIO_LOW" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GVideoread_l.pbm"</IMAGE>
#endif
#ifdef __MMI_OP11_MMS_SUPPORT_PHOTO_MSG__
    <IMAGE id="MMA_IMG_GROUP_PHOTO" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GPicunread.pbm"</IMAGE>
    <IMAGE id="MMA_IMG_GROUP_PHOTO_PRIO_HIGH" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GPicunread_h.pbm"</IMAGE>
    <IMAGE id="MMA_IMG_GROUP_PHOTO_PRIO_LOW" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GPicunread_l.pbm"</IMAGE>
    <IMAGE id="MMA_IMG_GROUP_PHOTO_READ" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GPicread.pbm"</IMAGE>
    <IMAGE id="MMA_IMG_GROUP_PHOTO_READ_PRIO_HIGH" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GPicread_h.pbm"</IMAGE>
    <IMAGE id="MMA_IMG_GROUP_PHOTO_READ_PRIO_LOW" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GPicread_l.pbm"</IMAGE>
#endif
#endif  /* __MMI_MMS_GROUP_MSG__ */ 
#endif  /* __MMI_ULTRA_SLIM_MMS_2__ */
   
#endif /* __COSMOS_MMI_PACKAGE__ */
   
    <MENUITEM id="MENU_ID_FMGR_FWD_MMS" str="STR_GLOBAL_AS_MULTIMEDIA_MSG"/>
#ifdef __MMI_OP11_MMS_SEND_TO_PHOTO_BLOG__
     <MENUITEM id="MENU_ID_UMMS_FMGR_SEND_TO_ORANGE_BLOG" str="STR_FMGR_UMMS_TO_BLOG"/>
#endif

#ifdef __MMI_MMS_POSTCARD__
    <MENUITEM id="MENU_ID_UMMS_FMGR_SEND_TO_POSTCARD" str="STR_FMGR_UMMS_TO_POSTCARD"/>
#endif

</APP>

<FILE_TYPES>
#ifndef __COSMOS_MMI_PACKAGE__
    <FILE_OPTION_HDLR option="MENU_ID_FMGR_FWD_MMS" enabler="mmi_umms_fmgr_forward_mms_enabler" handler="mmi_umms_fmgr_to_mms_hdlr"/>
#endif
#ifdef __MMI_OP11_MMS_SEND_TO_PHOTO_BLOG__
    <FILE_OPTION_HDLR option="MENU_ID_UMMS_FMGR_SEND_TO_ORANGE_BLOG" enabler="mmi_umms_fmgr_forward_mms_enabler" handler="mmi_umms_fmgr_to_mms_blog_hdlr"/>
#endif
#ifdef __MMI_MMS_POSTCARD__
     <FILE_OPTION_HDLR option="MENU_ID_UMMS_FMGR_SEND_TO_POSTCARD" enabler="mmi_umms_fmgr_forward_mms_enabler" handler="mmi_umms_fmgr_to_mms_postcard_hndlr"/>
#endif

</FILE_TYPES>
#endif