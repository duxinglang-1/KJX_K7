# 1 "temp/res/MMSSrv.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/MMSSrv.c"
# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 2 "temp/res/MMSSrv.c" 2
# 1 "../customerinc/CustResDef.h" 1
# 191 "../customerinc/CustResDef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/CustResDef.h" 2
# 3 "temp/res/MMSSrv.c" 2
<?xml version="1.0" encoding="UTF-8"?>







<APP id="SRV_MMS">

    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,GlobalMenuItems.h" />




           <!------------------------------------------------------callback manager sender part---------------------------------------------------------->

       <EVENT id="EVT_ID_SRV_MMS_UPDATE_STATUS" type="SENDER"/>
       <EVENT id="EVT_ID_SHOW_HIDE_ICON" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_MMS_READY" type="SENDER"/>
       <EVENT id="EVT_ID_MMA_INSUF_MEM" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_MMS_DEINIT" type="SENDER"/>
       <EVENT id="EVT_ID_JSR_DELETE_MMS" type="SENDER"/>

       <EVENT id="EVT_ID_SRV_ASM_SUCCESS" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_ASM_STOP" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_ASM_CANCEL" type="SENDER"/>


       <EVENT id="EVT_ID_SRV_CHK_CARD_PLUG_OUT" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_CHANGE_STORAGE" type="SENDER"/>


       <EVENT id="EVT_ID_SRV_SET_SETTING" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_APP_ERROR" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_SAVE_OBJECTS_ERROR" type="SENDER"/>


       <EVENT id="EVT_ID_SRV_TEMPLATE_ERROR" type="SENDER"/>





       <EVENT id="EVT_ID_SRV_SHOW_STATUS" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_SAVE_RSP_FROM_UC" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_BOOTUP_INIT" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_INVALID_POPUP" type="SENDER"/>






       <EVENT id="EVT_ID_SRV_EXIT_VIEWER_APP" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_CURR_MSG_UPDATE" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_SHOW_BGSR_POPUP" type="SENDER"/>




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
# 95 "temp/res/MMSSrv.c"
       <EVENT id="EVT_ID_SRV_MMS_SEND_REFRESH" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_MMS_SEND_URI_IND" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_MMS_MEM_FULL" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_MMS_GET_CURR_MSG_BOX" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_MMS_NMGR_ALERT" type="SENDER"/>


       <EVENT id="EVT_ID_SRV_MMS_IN_USE_MSG_ID" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_MMS_READY_FOR_LITE_VIEWER" type="SENDER"/>
       <EVENT id="EVT_ID_SRV_MMS_TEMPLATE_GEN_RESULT" type="SENDER"/>


           <EVENT id="EVT_ID_SRV_MMS_SERVICE_MEM_FREE_DONE" type="SENDER"/>


<!------------------------------------------------------callback manager reciever part---------------------------------------------------------->



        <RECEIVER id="EVT_ID_SRV_MMS_IN_USE_MSG_ID" proc="mmi_umms_app_if_msg_in_view"/>
        <RECEIVER id="EVT_ID_SRV_MMS_IN_USE_MSG_ID" proc="mmi_umms_app_if_is_mms_in_open_state"/>

       <RECEIVER id="EVT_ID_MMI_UM_ENTRY_FOLDER" proc="srv_mms_entry_folder_hdlr"/>
       <RECEIVER id="EVT_ID_MMA_INSUF_MEM" proc="mmi_umms_app_core_mma_insuf_mem"/>
       <RECEIVER id="EVT_ID_SRV_MMS_DEINIT" proc="mmi_umms_app_core_mms_deinit"/>

       <RECEIVER id="EVT_ID_SRV_CHK_CARD_PLUG_OUT" proc="mmi_umms_app_core_handle_sd_card_plug_out"/>

       <RECEIVER id="EVT_ID_SRV_CHANGE_STORAGE" proc="mmi_umms_app_core_handle_change_storage_rsp"/>


       <RECEIVER id="EVT_ID_SRV_SET_SETTING" proc="mmi_umms_app_dtmgr_send_set_settings_to_service"/>
       <RECEIVER id="EVT_ID_SRV_APP_ERROR" proc="mmi_umms_app_core_show_error_popup"/>
       <RECEIVER id="EVT_ID_SRV_SAVE_OBJECTS_ERROR" proc="mmi_umms_app_ui_plug_in_save_object_error_handling"/>


       <RECEIVER id="EVT_ID_SRV_TEMPLATE_ERROR" proc="mmi_umms_app_core_handle_template_error_event"/>






        <RECEIVER id="EVT_ID_SRV_SHOW_STATUS" proc="mmi_umms_app_core_show_mms_status_icon"/>
        <RECEIVER id="EVT_ID_SRV_SAVE_RSP_FROM_UC" proc="mmi_umms_app_core_save_rsp_from_uc"/>
        <RECEIVER id="EVT_ID_SRV_BOOTUP_INIT" proc="mmi_umms_app_core_bootup_init"/>
        <RECEIVER id="EVT_ID_SRV_INVALID_POPUP" proc="mmi_umms_app_core_display_invalid_popup"/>







        <RECEIVER id="EVT_ID_SRV_EXIT_VIEWER_APP" proc="mmi_umms_app_core_exit_viewer_application"/>

         <RECEIVER id="EVT_ID_SRV_CURR_MSG_UPDATE" proc="mmi_umms_app_core_check_crnt_selected_msg_for_update"/>
         <RECEIVER id="EVT_ID_SRV_SHOW_BGSR_POPUP" proc="mmi_umms_app_core_display_bgsr_popup"/>



         <RECEIVER id="EVT_ID_SRV_CURR_MSG_SELECT" proc="mmi_umms_app_core_check_crnt_selected_msg"/>
         <RECEIVER id="EVT_ID_SRV_WAP_READY" proc="mmi_umms_app_core_wap_ready_hdlr"/>
         <RECEIVER id="EVT_ID_SRV_STORAGE_FULL_IND" proc="mmi_umms_app_core_get_storage_full_ind_data"/>
         <RECEIVER id="EVT_ID_SRV_UPDATE_MEM_STATUS" proc="mmi_umms_app_core_memory_status_screen_update"/>


         <RECEIVER id="EVT_ID_SRV_HDL_CARD_PLUG_OUT" proc="mmi_umms_app_core_check_card_plug_out_handling"/>


         <RECEIVER id="EVT_ID_SRV_BGSR_RESULT" proc="mmi_umms_app_core_mms_display_popup_for_bgsr"/>
         <RECEIVER id="EVT_ID_SRV_SAVE_OBJECT_COPY_RESULT_HDL" proc="mmi_umms_app_core_hanlde_save_objects_copy_result"/>
         <RECEIVER id="EVT_ID_SRV_CHECK_AND_DELETE_PROGRESS" proc="mmi_umms_app_ui_plug_in_check_and_delete_progress_screen"/>


         <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="mmi_umms_sd_card_plug_in_hdlr_cb"/>


         <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_umms_sd_card_plug_out_hdlr_cb"/>


         <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="mmi_umms_drv_format_hdlr_cb"/>

         <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABLE" proc="srv_mms_sim_available_hdlr"/>

         <RECEIVER id="EVT_ID_SRV_SIM_CTRL_UNAVAILABLE" proc="srv_mms_sim_unavailable_hdlr"/>

                <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="srv_mms_usb_mode_off"/>
                <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="srv_mms_usb_mode_on"/>


         <RECEIVER id="EVT_ID_IDLE_GROUP_ENTER" proc="mmi_umms_app_core_idle_hdlr"/>

         <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="srv_mms_mode_switch_finish_event_hdlr"/>
                 <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="srv_mms_sim_availability_handler"/>

         <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="srv_mms_bgsr_drive_format_hdlr"/>
         <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="srv_mms_bgsr_usb_start_cb"/>
         <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="srv_mms_bgsr_usb_end_cb"/>
         <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="srv_mms_bgsr_sim_status_info_hdlr"/>
         <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="srv_mms_bgsr_sim_status_info_hdlr"/>







         <RECEIVER id="EVT_ID_SRV_NW_INFO_ROAMING_STATUS_CHANGED" proc="mmi_mms_on_roaming_status_changed"/>


        <RECEIVER id="EVT_ID_SHOW_HIDE_ICON" proc="mmi_umms_app_core_show_hide_status_icon"/>


                <RECEIVER id="EVT_ID_SRV_MMS_MMA_TERMINATE" proc="mmi_umms_app_core_dummy_listener"/>







   <RECEIVER id="EVT_ID_SRV_MMS_SEND_REFRESH" proc="srv_mms_post_refresh_cb"/>






<RECEIVER id="EVT_ID_SRV_MMS_GET_CURR_MSG_BOX" proc="mmi_umms_app_core_get_current_msg_box"/>

<RECEIVER id="EVT_ID_SRV_MMS_NMGR_ALERT" proc="mmi_umms_app_core_nmgr_alert"/>
    <RECEIVER id="EVT_ID_JSR_DELETE_MMS" proc="mmi_umms_op_update_recent_event_list_from_phone_suit"/>
# 251 "temp/res/MMSSrv.c"
<!------------------------------------------------------ MMI CACHE ------------------------------------------------------------->

     <!------------------------------------------------------ DOUBLE CACHE ------------------------------------------------------------->

     <CACHEDATA type="double" id="NVRAM_UMMS_RETRIEVAL_SETTINGS" restore_flag="TRUE" restore_id="@NVRAM_UMMS_RESTORE_RETRIEVAL_SETTINGS">
# 266 "temp/res/MMSSrv.c"
        <DEFAULT_VALUE> [0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00] </DEFAULT_VALUE>

        <DESCRIPTION> MMS V02 MMS Retrieval Settings </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NVRAM_UMMS_RESTORE_RETRIEVAL_SETTINGS">
# 282 "temp/res/MMSSrv.c"
        <DEFAULT_VALUE> [0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00] </DEFAULT_VALUE>

        <DESCRIPTION> Double cache </DESCRIPTION>
    </CACHEDATA>


    <!------------------------------------------------------ SHORT CACHE ------------------------------------------------------------->

     <CACHEDATA type="short" id="NVRAM_UMMS_LANGUAGE_CHANGE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>


    <!------------------------------------------------------ BYTE CACHE ------------------------------------------------------------->

    <CACHEDATA type="byte" id="NVRAM_SETTING_PREFER_MMS_STORAGE_MODE" restore_flag="TRUE">



        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>

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



    <TIMER id="UMMS_DOWNLOAD_TIMER"/>
    <TIMER id="MMS_VIEWER_TIMER"/>
    <TIMER id="SRV_MMS_BGSR_TIMER"/>
    <TIMER id="UMMS_SETTINGS_TIMER"/>



    <STRING id="MMA_STR_ID_MESSAGE_CORRUPT" />
    <STRING id="MMA_STR_ID_MESSAGE_UNSUPPORTED"/>
        <STRING id="MMA_STR_ID_MMS_DELIVERY_REPORT"/>
        <STRING id="MMA_STR_ID_MMS_READ_REPORT"/>






    <STRING id="MMS_STR_ID_EMPTY_STRING" />
    <STRING id="MMS_STR_ID_RR_TEXT_FROM" />
    <STRING id="MMS_STR_ID_RR_TEXT_MSGID" />
        <STRING id="MMS_STR_ID_RR_TEXT_READ"/>
        <STRING id="MMS_STR_ID_RR_TEXT_SENT"/>
        <STRING id="MMS_STR_ID_RR_TEXT_SUBJECT"/>
        <STRING id="MMS_STR_ID_RR_TEXT_TO"/>
        <STRING id="MMS_STR_ID_RR_TEXT_WAS_READ"/>
        <STRING id="MMS_STR_ID_RR_TEXT_YOUR_MSG"/>





<STRING id="STR_ID_UMMS_NEW_MMS" />
<STRING id="STR_ID_UMMS_NEW_MMS_FROM_SIM1" />
<STRING id="STR_ID_UMMS_NEW_MMS_FROM_SIM2" />
<STRING id="STR_ID_UMMS_NEW_MMS_FROM_SIM3" />
<STRING id="STR_ID_UMMS_NEW_MMS_FROM_SIM4" />
<STRING id="STR_ID_MMS_VIEWER_TEXT_STRIPPED" />
# 391 "temp/res/MMSSrv.c"
    <STRING id="STR_ID_UMMS_MMS_SERVICE"/>


<!------------------------------------------------------ MMS TEMPLATE RESOURCES ------------------------------------------------------------->
# 480 "temp/res/MMSSrv.c"
<!------------------------------------------------------ MMS TEMPLATE RESOURCES END ------------------------------------------------------------->

        <IMAGE id="IMG_ID_SRV_MMS_VIEWER_APP" > "..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\MMS\\\\SB_mms.bmp"</IMAGE>




    <IMAGE id="MMA_IMG_LETTER_CREATED" > "..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\MMS\\\\draft\\\\mmsdraft.bmp"</IMAGE>

    <IMAGE id="MMA_IMG_CORRUPT" > "..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\MMS\\\\message\\\\MMS_corrupted.bmp"</IMAGE>






    <IMAGE id="MMA_IMG_LETTER" > "..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\MMS\\\\message\\\\mms_message.bmp"</IMAGE>
    <IMAGE id="MMA_IMG_LETTER_READ" > "..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\MMS\\\\message\\\\mms_messageread.bmp"</IMAGE>

    <IMAGE id="MMA_IMG_NOTIF" > "..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\MMS\\\\notification\\\\notification.bmp"</IMAGE>
# 601 "temp/res/MMSSrv.c"
    <MENUITEM id="MENU_ID_FMGR_FWD_MMS" str="STR_GLOBAL_AS_MULTIMEDIA_MSG"/>
# 610 "temp/res/MMSSrv.c"
</APP>

<FILE_TYPES>

    <FILE_OPTION_HDLR option="MENU_ID_FMGR_FWD_MMS" enabler="mmi_umms_fmgr_forward_mms_enabler" handler="mmi_umms_fmgr_to_mms_hdlr"/>
# 623 "temp/res/MMSSrv.c"
</FILE_TYPES>
