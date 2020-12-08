# 1 "temp/res/callback_mgr.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/callback_mgr.c"
# 412 "temp/res/callback_mgr.c"
# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 413 "temp/res/callback_mgr.c" 2

<?xml version="1.0" encoding="UTF-8"?>


<APP id="APP_CB_MGR">



    <!--Include Area-->

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>


    <!------------------------------------------------------Other Resource---------------------------------------------------------->
        <SENDER id="EVT_ID_PRE_PROTOCOL" hfile="GlobalResDef.h"/>
        <SENDER id="EVT_ID_PRE_KEY_EVT_ROUTING" hfile="GlobalResDef.h"/>
        <SENDER id="EVT_ID_POST_KEY_EVT_ROUTING" hfile="GlobalResDef.h"/>
        <SENDER id="EVT_ID_KEY_DEFAULT_HANDLER" hfile="GlobalResDef.h"/>
        <SENDER id="EVT_ID_PRE_TOUCH_EVT_ROUTING" hfile="GlobalResDef.h"/>
        <SENDER id="EVT_ID_POST_TOUCH_EVT_ROUTING" hfile="GlobalResDef.h"/>
        <SENDER id="EVT_ID_WGUI_LSK_CLICK" hfile="GlobalResDef.h"/>
        <SENDER id="EVT_ID_WGUI_RSK_CLICK" hfile="GlobalResDef.h"/>
        <SENDER id="EVT_ID_WGUI_CSK_CLICK" hfile="GlobalResDef.h"/>

        <SENDER id="EVT_ID_APP_TERMINATED" hfile="GlobalResDef.h"/>
        <SENDER id="EVT_ID_PRE_ACTIVE_IDLE_APP_IN_END_KEY" hfile="GlobalResDef.h"/>
        <SENDER id="EVT_ID_POST_ACTIVE_IDLE_APP_IN_END_KEY" hfile="GlobalResDef.h"/>
# 466 "temp/res/callback_mgr.c"
        <RECEIVER id="EVT_ID_PRE_KEY_EVT_ROUTING" proc="mmi_frm_nmgr_control_end_callback"/>




        <RECEIVER id="EVT_ID_PRE_KEY_EVT_ROUTING" proc="mmi_key_tone_pre_key_routing_cb"/>







        <RECEIVER id="EVT_ID_PRE_KEY_EVT_ROUTING" proc="mmi_slk_main_evt_hdlr"/>

        <RECEIVER id="EVT_ID_PRE_KEY_EVT_ROUTING" proc="mmi_frm_profiling_pre_key_routing_cb"/>




        <RECEIVER id="EVT_ID_PRE_KEY_EVT_ROUTING" proc="mmi_ucm_bk_call_key_proc"/>
# 498 "temp/res/callback_mgr.c"
        <RECEIVER id="EVT_ID_WGUI_LSK_CLICK" proc="wgui_softkey_default_proc"/>
        <RECEIVER id="EVT_ID_WGUI_RSK_CLICK" proc="wgui_softkey_default_proc"/>
        <RECEIVER id="EVT_ID_WGUI_CSK_CLICK" proc="wgui_softkey_default_proc"/>


        <RECEIVER id="EVT_ID_POST_KEY_EVT_ROUTING" proc="mmi_frm_profiling_post_key_routing_cb"/>
# 533 "temp/res/callback_mgr.c"
        <SENDER id="EVT_ID_SRV_UCM_ACTION_NOTIFY" hfile="UcmSrvGprot.h"/>
        <SENDER id="EVT_ID_SRV_UCM_INDICATION" hfile="UcmSrvGprot.h"/>
        <SENDER id="EVT_ID_SRV_UCM_CNF_INDICATION" hfile="UcmSrvGprot.h"/>
        <SENDER id="EVT_ID_SRV_UCM_STATUS_CHANGE" hfile="UcmSrvGprot.h"/>
        <SENDER id="EVT_ID_SRV_UCM_APP_EXIT_QUERY" hfile="UcmSrvGprot.h"/>
        <SENDER id="EVT_ID_SRV_UCM_INTERCEPT_QUERY" hfile="UcmSrvGprot.h"/>




        <RECEIVER id="EVT_ID_SRV_UCM_INTERCEPT_QUERY" proc="srv_ucm_short_string_crss"/>

        <RECEIVER id="EVT_ID_SRV_UCM_INTERCEPT_QUERY" proc="mmi_ss_intercept"/>
# 589 "temp/res/callback_mgr.c"
        <RECEIVER id="EVT_ID_GUI_INPUTS_CURSOR_CHANGED" proc="mmi_imc_editor_cursor_movement_handler"/>
        <RECEIVER id="EVT_ID_IME_CURSOR_UPDATED" proc="mmi_imc_editor_cursor_movement_handler"/>
        <RECEIVER id="EVT_ID_IME_INVOKE_SPELL_WORD_SCREEN" proc="mmi_imc_enter_spell_word_screen_handler"/>
        <RECEIVER id="EVT_ID_IME_ENTRY_INPUT_METHOD_SCREEN" proc="mmi_imc_input_method_screen_handler"/>






        <RECEIVER id="EVT_ID_INLINE_IMAGETEXT_PEN_UP" proc="wgui_inline_proc_post_event"/>
# 622 "temp/res/callback_mgr.c"
  <SENDER id="EVT_ID_NMGR_SUBLCD_NOTIFY" hfile="GlobalResDef.h"/>
        <SENDER id="EVT_ID_SCENARIO_END" hfile="GlobalResDef.h"/>
        <SENDER id="EVT_ID_NMGR_PLAY_TONE" hfile="GlobalResDef.h"/>
        <SENDER id="EVT_ID_NMGR_PLAY_VIB" hfile="GlobalResDef.h"/>
        <SENDER id="EVT_ID_NMGR_IDLE_CANCEL" hfile="GlobalResDef.h"/>
        <RECEIVER id="EVT_ID_SCENARIO_END" proc="mmi_frm_nmgr_invoke_defer_event_callback"/>
# 697 "temp/res/callback_mgr.c"
        <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="mmi_rmgr_format_notify_hdlr"/>
# 753 "temp/res/callback_mgr.c"
        <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION" proc="srv_prof_notify_hdlr"/>





        <SENDER id="EVT_ID_GPIO_EXT_DEV_KEY_1" hfile="GpioSrvGprot.h"/>
        <SENDER id="EVT_ID_GPIO_EARPHONE_PLUG_IN" hfile="GpioSrvGprot.h"/>
        <SENDER id="EVT_ID_GPIO_EARPHONE_PLUG_OUT" hfile="GpioSrvGprot.h"/>
        <SENDER id="EVT_ID_GPIO_EARPHONE_QUERY_CTRL" hfile="GpioSrvGprot.h"/>
        <SENDER id="EVT_ID_GPIO_BACKLIGHT_DIMMING" hfile="GpioSrvGprot.h"/>
        <SENDER id="EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN" hfile="GpioSrvGprot.h"/>
        <SENDER id="EVT_ID_GPIO_BACKLIGHT_OFF" hfile="GpioSrvGprot.h"/>
        <SENDER id="EVT_ID_GPIO_BACKLIGHT_ON" hfile="GpioSrvGprot.h"/>
        <SENDER id="EVT_ID_GPIO_LCD_SLEEP_IN" hfile="GpioSrvGprot.h"/>
        <SENDER id="EVT_ID_GPIO_LCD_SLEEP_OUT" hfile="GpioSrvGprot.h"/>
        <SENDER id="EVT_ID_GPIO_AFTER_LCD_SLEEP_IN" hfile="GpioSrvGprot.h"/>
        <SENDER id="EVT_ID_GPIO_BACKLIGHT_LEVEL_UPDATE" hfile="GpioSrvGprot.h"/>
        <SENDER id="EVT_ID_GPIO_ENABLE_HAND_FREE" hfile="GpioSrvGprot.h"/>
        <SENDER id="EVT_ID_GPIO_DISABLE_HAND_FREE" hfile="GpioSrvGprot.h"/>
        <SENDER id="EVT_ID_GPIO_MUTE_PHONE" hfile="GpioSrvGprot.h"/>
        <SENDER id="EVT_ID_GPIO_UNMUTE_PHONE" hfile="GpioSrvGprot.h"/>

        <SENDER id="EVT_ID_GPIO_RFID_OPEN" hfile="GpioSrvGprot.h"/>
        <SENDER id="EVT_ID_GPIO_RFID_CLOSE" hfile="GpioSrvGprot.h"/>
# 793 "temp/res/callback_mgr.c"
        <RECEIVER id="EVT_ID_GPIO_BACKLIGHT_LEVEL_UPDATE" proc="mmi_phnset_gpio_set_bl_level_ncenter"/>




        <RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_IN" proc="srv_prof_notify_hdlr"/>

        <RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_IN" proc="mmi_gpio_handle_earphone_plug_in"/>
# 813 "temp/res/callback_mgr.c"
        <RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_OUT" proc="mmi_gpio_handle_earphone_plug_out"/>



        <RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_OUT" proc="srv_prof_notify_hdlr"/>
# 880 "temp/res/callback_mgr.c"
        <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_IN" proc="wndrv_hdl_lcd_sleep_in"/>



        <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_OUT" proc="mmi_gpio_lcd_sleep_out_update_dt"/>
    <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_OUT" proc="mmi_gpio_lcd_sleep_out_repaint_screen"/>







    <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_OUT" proc="wgui_status_icon_bar_sleepout_callback_handler"/>
# 906 "temp/res/callback_mgr.c"
        <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_OUT" proc="wndrv_hdl_lcd_sleep_out"/>







        <RECEIVER id="EVT_ID_GPIO_MUTE_PHONE" proc="mmi_gpio_handle_mute_phone"/>
        <RECEIVER id="EVT_ID_GPIO_UNMUTE_PHONE" proc="mmi_gpio_handle_unmute_phone"/>







        <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="srv_nw_usab_on_sim_availability_changed"/>
# 940 "temp/res/callback_mgr.c"
        <RECEIVER id="EVT_ID_SRV_NW_INFO_ROAMING_STATUS_CHANGED" proc="mmi_mms_on_roaming_status_changed"/>
# 957 "temp/res/callback_mgr.c"
        <RECEIVER id="EVT_ID_SRV_SHUTDOWN_DEINIT" proc="srv_usb_shutdown_handler"/>

        <RECEIVER id="EVT_ID_SRV_SHUTDOWN_DEINIT" proc="srv_ucm_shutdown_proc"/>





        <RECEIVER id="EVT_ID_SRV_SHUTDOWN_HANDLER_RESET" proc="srv_gpio_shutdown_hdlr"/>
# 980 "temp/res/callback_mgr.c"
        <SENDER id="EVT_ID_SCRN_ENTER_SUCCESS_NOFITY" hfile="GlobalResDef.h"/>
        <SENDER id="EVT_ID_SRV_NW_USAB_CHANGED" hfile="NwUsabSrvGprot.h"/>
# 1002 "temp/res/callback_mgr.c"
        <RECEIVER id="EVT_ID_GPIO_RFID_OPEN" proc="mmi_rfid_eint_notify_hdlr"/>
        <RECEIVER id="EVT_ID_GPIO_RFID_CLOSE" proc="mmi_rfid_eint_notify_hdlr"/>
# 1014 "temp/res/callback_mgr.c"
        <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="srv_fmgr_ms_handler"/>
# 1031 "temp/res/callback_mgr.c"
        <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="srv_fmgr_ms_handler"/>
# 1043 "temp/res/callback_mgr.c"
    <SENDER id="EVT_ID_MMI_TIMER_EXPIRY_PROC_EXT" hfile="GlobalResDef.h"/>
    <SENDER id="EVT_ID_MMI_TIMER_INIT_EXT" hfile="GlobalResDef.h"/>


        <SENDER id="EVT_ID_OOM_HANDLE_FAIL" hfile="GlobalResDef.h"/>
# 1059 "temp/res/callback_mgr.c"
</APP>
