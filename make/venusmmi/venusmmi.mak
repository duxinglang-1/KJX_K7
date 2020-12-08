# Define the specified compile options to COMP_DEFS
COMP_DEFS = APCS_INTWORK
ifneq ($(filter __MMI_VENUS_RT__, $(strip $(MODULE_DEFS))),)
COMP_DEFS += VFX_RT_TEST
endif

ifneq ($(filter __ARM9_MMU__ __ARM11_MMU__, $(strip $(MODULE_DEFS))),)
CFLAGS += --forceinline
CPLUSFLAGS += --forceinline
endif

# Define source file lists to SRC_LIST
SRC_LIST = venusmmi\framework\ui_core\base\vfx_datatype.c \
           venusmmi\framework\ui_core\base\vfx_sys_memory.c \
           venusmmi\framework\ui_core\base\vfx_sys_mem_config.c \
           venusmmi\framework\ui_core\base\vfx_system.c \
           venusmmi\framework\ui_core\base\vfx_cpp_base.cpp \
           venusmmi\framework\ui_core\base\vfx_transform.cpp \
           venusmmi\framework\ui_core\base\vfx_string.cpp \
           venusmmi\framework\ui_core\base\vfx_image_src.cpp \
           venusmmi\framework\ui_core\base\vfx_font_desc.cpp \
           venusmmi\framework\ui_core\base\vfx_stream.cpp \
           venusmmi\framework\ui_core\base\vfx_logger.cpp \
           venusmmi\framework\ui_core\base\vfx_adp_clib.c \
           venusmmi\framework\ui_core\base\vfx_adp_device.c \
           venusmmi\framework\ui_core\base\vfx_adp_os.c \
           venusmmi\framework\ui_core\base\vfx_adp_sse.cpp \
           venusmmi\framework\ui_core\pme\vfx_variant.cpp \
           venusmmi\framework\ui_core\pme\vfx_class_info.cpp \
           venusmmi\framework\ui_core\pme\vfx_object.cpp \
           venusmmi\framework\ui_core\pme\vfx_object_list.cpp \
           venusmmi\framework\ui_core\pme\vfx_signal.cpp \
           venusmmi\framework\ui_core\pme\vfx_async_signal.cpp \
           venusmmi\framework\ui_core\pme\vfx_context.cpp \
           venusmmi\framework\ui_core\pme\vfx_archive.cpp \
           venusmmi\framework\ui_core\mvc\vfx_input_event.cpp \
           venusmmi\framework\ui_core\mvc\vfx_timer.cpp \
           venusmmi\framework\ui_core\mvc\vfx_draw_context.cpp \
           venusmmi\framework\ui_core\mvc\vfx_auto_animate.cpp \
           venusmmi\framework\ui_core\mvc\vfx_frame_filter.cpp \
           venusmmi\framework\ui_core\mvc\vfx_owner_draw.cpp \
           venusmmi\framework\ui_core\mvc\vfx_frame_aligner.cpp \
           venusmmi\framework\ui_core\mvc\vfx_frame.cpp \
           venusmmi\framework\ui_core\mvc\vfx_animatable.cpp \
           venusmmi\framework\ui_core\mvc\vfx_animation.cpp \
           venusmmi\framework\ui_core\mvc\vfx_renderer.cpp \
           venusmmi\framework\ui_core\mvc\vfx_renderer_dump.cpp \
           venusmmi\framework\ui_core\mvc\vfx_primitive_frame.cpp \
           venusmmi\framework\ui_core\mvc\vfx_rect_frame.cpp \
           venusmmi\framework\ui_core\mvc\vfx_text_frame.cpp \
           venusmmi\framework\ui_core\mvc\vfx_control.cpp \
           venusmmi\framework\ui_core\mvc\vfx_screen.cpp \
           venusmmi\framework\ui_core\mvc\vfx_top_level.cpp \
           venusmmi\framework\ui_core\mvc\vfx_shelter.cpp \
           venusmmi\framework\ui_core\mvc\vfx_debug_panel.cpp \
           venusmmi\framework\ui_core\mvc\vfx_profiling_panel.cpp \
           venusmmi\framework\ui_core\mvc\vfx_pen.cpp \
           venusmmi\framework\ui_core\mvc\vfx_keypad.cpp \
           venusmmi\framework\ui_core\mvc\vfx_date_time.cpp \
           venusmmi\framework\ui_core\mvc\vfx_mmi.cpp \
           venusmmi\framework\ui_core\mvc\vfx_base_popup.cpp \
           venusmmi\framework\ui_core\mvc\vfx_primitive_filter.cpp \
           venusmmi\framework\ui_core\mvc\vfx_video_frame.cpp \
           venusmmi\framework\ui_core\mvc\vfx_layer_control.cpp \
           venusmmi\framework\ui_core\mvc\vfx_owner_draw_control.cpp \
           venusmmi\framework\mmi_core\vfx_app.cpp \
           venusmmi\framework\mmi_core\vfx_app_scr.cpp \
           venusmmi\framework\mmi_core\vfx_app_launcher.cpp \
           venusmmi\framework\mmi_core\vfx_cui.cpp \
           venusmmi\framework\mmi_core\vfx_app_cat_scr.cpp \
           venusmmi\framework\mmi_core\vfx_main_scr.cpp \
           venusmmi\framework\mmi_core\vfx_page.cpp \
           venusmmi\framework\mmi_core\vfx_page_bar.cpp \
           venusmmi\framework\mmi_core\vfx_page_transition.cpp \
           venusmmi\framework\mmi_core\vfx_mc_trace.cpp \
           venusmmi\framework\xml\vfx_xml_prop_handler.cpp \
           venusmmi\framework\xml\vfx_xml_table.cpp \
           venusmmi\framework\xml\vfx_xml_loader.cpp \
           venusmmi\plugin\framework\ui_core\base\vpi_system.cpp \
           venusmmi\app\common\ime\vsrv_input_method_popup.cpp

ifneq ($(filter __MMI_VENUS_PLUG_IN_ENGINE__, $(strip $(MODULE_DEFS))),)
SRC_LIST += venusmmi\plugin\framework\mmi_core\vpi_app_launcher.cpp \
           venusmmi\plugin\framework\mmi_core\vpi_app_scr.cpp \
           venusmmi\plugin\framework\mmi_core\vpi_main_scr.cpp \
           venusmmi\plugin\framework\mmi_core\vpi_page.cpp \
           venusmmi\plugin\framework\mmi_core\vpi_page_bar.cpp \
           venusmmi\plugin\framework\mmi_core\vpi_page_transition.cpp \
           venusmmi\plugin\framework\ui_core\base\vpi_font_desc.cpp \
           venusmmi\plugin\framework\ui_core\base\vpi_data_type_convertion.cpp \
           venusmmi\plugin\framework\ui_core\mvc\vpi_animation.cpp \
           venusmmi\plugin\framework\ui_core\mvc\vpi_archive.cpp \
           venusmmi\plugin\framework\ui_core\mvc\vpi_auto_animate.cpp \
           venusmmi\plugin\framework\ui_core\mvc\vpi_base_popup.cpp \
           venusmmi\plugin\framework\ui_core\mvc\vpi_image_frame.cpp \
           venusmmi\plugin\framework\ui_core\mvc\vpi_anim_image_frame.cpp \
           venusmmi\plugin\framework\ui_core\mvc\vpi_renderer.cpp \
           venusmmi\plugin\framework\ui_core\mvc\vpi_text_frame.cpp \
           venusmmi\plugin\framework\ui_core\mvc\vpi_timer.cpp \
           venusmmi\plugin\framework\ui_core\mvc\vpi_top_level.cpp \
           venusmmi\plugin\framework\ui_core\mvc\vpi_control.cpp \
           venusmmi\plugin\framework\ui_core\mvc\vpi_frame.cpp \
           venusmmi\plugin\framework\ui_core\mvc\vpi_frame_filter.cpp \
           venusmmi\plugin\framework\ui_core\mvc\vpi_owner_draw.cpp \
           venusmmi\plugin\framework\ui_core\mvc\vpi_screen.cpp \
           venusmmi\plugin\framework\ui_core\mvc\vpi_owner_draw_control.cpp \
           venusmmi\plugin\framework\ui_core\pme\vpi_async_signal.cpp \
           venusmmi\plugin\framework\ui_core\pme\vpi_object.cpp \
           venusmmi\plugin\framework\ui_core\pme\vpi_object_factory.cpp \
           venusmmi\plugin\visual\cp\vpi_confirm_popup.cpp \
           venusmmi\plugin\visual\cp\vpi_indicator_popup.cpp \
           venusmmi\plugin\visual\cp\vpi_base_menu.cpp \
           venusmmi\plugin\visual\cp\vpi_scrollable.cpp \
           venusmmi\plugin\visual\cp\vpi_text_view.cpp \
           venusmmi\plugin\visual\cp\vpi_text_editor.cpp \
           venusmmi\plugin\visual\cp\vcp_settings_menu_pages.cpp \
           venusmmi\plugin\visual\cp\vpi_settings_menu_pages.cpp \
           venusmmi\plugin\visual\cp\vpi_notifications.cpp
endif

            
ifeq ($(strip $(VENUS_MMI)),VENUS_3D)
    SRC_LIST += venusmmi\framework\ui_core\base\vfx_asset_src.cpp \
           venusmmi\framework\ui_core\base\vfx_asset_loader.cpp \
           venusmmi\framework\ui_core\mvc\vfx_camera.cpp \
           venusmmi\framework\ui_core\mvc\vfx_group.cpp \
           venusmmi\framework\ui_core\mvc\vfx_light.cpp \
           venusmmi\framework\ui_core\mvc\vfx_material.cpp \
           venusmmi\framework\ui_core\mvc\vfx_pass.cpp \
           venusmmi\framework\ui_core\mvc\vfx_shader.cpp \
           venusmmi\framework\ui_core\mvc\vfx_shader_uniforms.cpp \
           venusmmi\framework\ui_core\mvc\vfx_render_mode.cpp \
           venusmmi\framework\ui_core\mvc\vfx_polygon_mode.cpp \
           venusmmi\framework\ui_core\mvc\vfx_compositing_mode.cpp \
           venusmmi\framework\ui_core\mvc\vfx_blender.cpp \
           venusmmi\framework\ui_core\mvc\vfx_stencil.cpp \
           venusmmi\framework\ui_core\mvc\vfx_mesh.cpp \
           venusmmi\framework\ui_core\mvc\vfx_skinned_mesh.cpp \
           venusmmi\framework\ui_core\mvc\vfx_node.cpp \
           venusmmi\framework\ui_core\mvc\vfx_bounding_volume.cpp \
           venusmmi\framework\ui_core\mvc\vfx_object_3d.cpp \
           venusmmi\framework\ui_core\mvc\vfx_texture.cpp \
           venusmmi\framework\ui_core\mvc\vfx_render_buffer.cpp \
           venusmmi\framework\ui_core\mvc\vfx_render_target.cpp \
           venusmmi\framework\ui_core\mvc\vfx_transformable.cpp \
           venusmmi\framework\ui_core\mvc\vfx_world.cpp
endif

# Venus CP
# Common CP
SRC_LIST += venusmmi\visual\cp\common\vcp_async_image_frame.cpp \
           venusmmi\visual\cp\common\vcp_base_menu.cpp \
           venusmmi\visual\cp\common\vcp_button.cpp \
           venusmmi\visual\cp\common\vcp_clock.cpp \
           venusmmi\visual\cp\common\vcp_command_popup.cpp \
           venusmmi\visual\cp\common\vcp_confirm_popup.cpp \
           venusmmi\visual\cp\common\vcp_content_clone.cpp \
           venusmmi\visual\cp\common\vcp_frame_effect.cpp \
           venusmmi\visual\cp\common\vcp_frame_effect_3d.cpp \
           venusmmi\visual\cp\common\vcp_image_button.cpp \
           venusmmi\visual\cp\common\vcp_input_popup.cpp \
           venusmmi\visual\cp\common\vcp_list_menu.cpp \
           venusmmi\visual\cp\common\vcp_marquee.cpp \
           venusmmi\visual\cp\common\vcp_page_panel.cpp \
           venusmmi\visual\cp\common\vcp_page_panel_3d.cpp \
           venusmmi\visual\cp\common\vcp_pluto_control.cpp \
           venusmmi\visual\cp\common\vcp_scrollable.cpp \
           venusmmi\visual\cp\common\vcp_segment_button.cpp \
           venusmmi\visual\cp\common\vcp_sel_box.cpp \
           venusmmi\visual\cp\common\vcp_sse.cpp \
           venusmmi\visual\cp\common\vcp_state_image.cpp \
           venusmmi\visual\cp\common\vcp_status_icon_bar.cpp \
           venusmmi\visual\cp\common\vcp_switch.cpp \
           venusmmi\visual\cp\common\vcp_symbol_picker.cpp \
           venusmmi\visual\cp\common\vcp_tab_bar.cpp \
           venusmmi\visual\cp\common\vcp_text_editor.cpp \
           venusmmi\visual\cp\common\vcp_text_layout.cpp \
           venusmmi\visual\cp\common\vcp_text_storage.cpp \
           venusmmi\visual\cp\common\vcp_text_utils.cpp \
           venusmmi\visual\cp\common\vcp_text_view.cpp \
           venusmmi\visual\cp\common\vcp_var_height_menu.cpp \
           venusmmi\visual\cp\common\vcp_wheel_menu.cpp \
           venusmmi\visual\cp\common\vcp_vk.cpp 

# Cosmos CP
ifneq ($(filter __MMI_VUI_COSMOS_CP__, $(strip $(MODULE_DEFS))),)
SRC_LIST += venusmmi\visual\cp\cosmos\vcp_activity_indicator.cpp \
           venusmmi\visual\cp\cosmos\vcp_base_picker.cpp \
           venusmmi\visual\cp\cosmos\vcp_bubble_effect.cpp \
           venusmmi\visual\cp\cosmos\vcp_button_util.cpp \
           venusmmi\visual\cp\cosmos\vcp_contact_selector.cpp \
           venusmmi\visual\cp\cosmos\vcp_date_picker.cpp \
           venusmmi\visual\cp\cosmos\vcp_form.cpp \
           venusmmi\visual\cp\cosmos\vcp_function_bar.cpp \
           venusmmi\visual\cp\cosmos\vcp_global_popup.cpp \
           venusmmi\visual\cp\cosmos\vcp_indicator_popup.cpp \
           venusmmi\visual\cp\cosmos\vcp_info_balloon.cpp \
           venusmmi\visual\cp\cosmos\vcp_loading_popup.cpp \
           venusmmi\visual\cp\cosmos\vcp_menu_popup.cpp \
           venusmmi\visual\cp\cosmos\vcp_menu_seek_bar.cpp \
           venusmmi\visual\cp\cosmos\vcp_more_command_popup.cpp \
           venusmmi\visual\cp\cosmos\vcp_navi_title_bar.cpp \
           venusmmi\visual\cp\cosmos\vcp_page_grid.cpp \
           venusmmi\visual\cp\cosmos\vcp_panel_bar.cpp \
           venusmmi\visual\cp\cosmos\vcp_photo_border_frame.cpp \
           venusmmi\visual\cp\cosmos\vcp_progress_indicator.cpp \
           venusmmi\visual\cp\cosmos\vcp_question_popup.cpp \
           venusmmi\visual\cp\cosmos\vcp_select_popup.cpp \
           venusmmi\visual\cp\cosmos\vcp_slider.cpp \
           venusmmi\visual\cp\cosmos\vcp_tab_title_bar.cpp \
           venusmmi\visual\cp\cosmos\vcp_tabctrl_page.cpp \
           venusmmi\visual\cp\cosmos\vcp_time_picker.cpp \
           venusmmi\visual\cp\cosmos\vcp_tool_bar.cpp
endif

# FTE CP
ifeq ($(filter __MMI_VUI_COSMOS_CP__, $(strip $(MODULE_DEFS))),)
SRC_LIST += venusmmi\visual\cp\fte\vcp_alert_popup.cpp \
           venusmmi\visual\cp\fte\vcp_button_internal.cpp \
           venusmmi\visual\cp\fte\vcp_command_title.cpp \
           venusmmi\visual\cp\fte\vcp_inline_menu.cpp \
           venusmmi\visual\cp\fte\vcp_jelly_filter.cpp \
           venusmmi\visual\cp\fte\vcp_option_menu.cpp \
           venusmmi\visual\cp\fte\vcp_shortcut.cpp \
           venusmmi\visual\cp\fte\vcp_softkey.cpp \
           venusmmi\visual\cp\fte\vcp_squeeze_filter.cpp \
           venusmmi\visual\cp\fte\vcp_title_bar.cpp \
           venusmmi\visual\cp\fte\vcp_waiting_icon.cpp \
           venusmmi\visual\cp\fte\vcp_waiting_popup.cpp
endif
         

SRC_LIST += venusmmi\app\pluto_variation\ShellApp\panel\HomeScreen\vcp_idle_calendar.cpp \
           venusmmi\app\common\data\vdat_network_info.cpp \
           venusmmi\app\common\data\vdat_recent_event.cpp \
           venusmmi\app\common\data\vdat_systime.cpp \
           venusmmi\app\common\ime\vsrv_input_manager.cpp \
           venusmmi\app\common\clipboard\vsrv_clipboard.cpp \
           venusmmi\app\common\wallpaper\vapp_wallpaper.cpp \
           venusmmi\app\common\wallpaper\vapp_wallpaper_cfg.cpp \
           venusmmi\app\common\wallpaper\vapp_wallpaper_content_provider.cpp \
           venusmmi\app\common\wallpaper\vapp_wallpaper_factory.cpp \
           venusmmi\app\common\wallpaper\vapp_wallpaper_file_factory.cpp \
           venusmmi\app\common\wallpaper\vapp_wallpaper_user_factory.cpp \
           venusmmi\app\common\wallpaper\vapp_wallpaper_image_factory.cpp \
           venusmmi\app\common\wallpaper\vapp_wallpaper_video_factory.cpp \
           venusmmi\app\common\wallpaper\vapp_wallpaper_id.cpp \
           venusmmi\app\common\wallpaper\vapp_wallpaper_kit.cpp \
           venusmmi\app\common\wallpaper\vapp_wallpaper_native_factory.cpp \
           venusmmi\app\common\wallpaper\vapp_wallpaper_setting_provider.cpp \
           venusmmi\app\common\wallpaper\vapp_wallpaper_wide.cpp \
           venusmmi\app\common\platform\vapp_platform_context.cpp \
           venusmmi\app\common\message\vapp_msg_data_provider.cpp \
           venusmmi\app\common\cp\vcp_page_menu_util.cpp \
           venusmmi\app\common\cp\vcp_page_menu_transition.cpp \
           venusmmi\app\common\cp\vapp_mav_motion_translator.cpp \
           venusmmi\app\common\cp\vapp_video_player_cp.cpp \
           venusmmi\app\pluto_variation\adapter\Framework\vadp_p2v_uc.cpp \
           venusmmi\app\pluto_variation\adapter\Framework\vadp_p2v_mem_info.cpp \
           venusmmi\app\pluto_variation\adapter\Mainmenu\vadp_v2p_mm.c \
           venusmmi\app\pluto_variation\adapter\GUI\vadp_v2p_inputbox.c \
           venusmmi\app\pluto_variation\adapter\GUI\vadp_v2p_status_icon_bar.c \
           venusmmi\app\pluto_variation\adapter\GUI\vadp_v2p_title_bar.c \
           venusmmi\app\pluto_variation\adapter\GUI\vadp_v2p_idle_calendar.c \
           venusmmi\app\pluto_variation\adapter\GUI\vadp_p2v_theme_info.cpp \
           venusmmi\app\pluto_variation\adapter\GUI\vadp_p2v_inputbox.cpp \
           venusmmi\app\pluto_variation\adapter\ime\vadp_p2v_input_server_interface.cpp \
           venusmmi\app\pluto_variation\adapter\ime\vadp_v2p_input_server.cpp \
           venusmmi\app\pluto_variation\adapter\MultiTouchTest\vadp_p2v_multi_touch_test.cpp \
           venusmmi\app\pluto_variation\MultiTouchTest\vapp_multi_touch_test.cpp \
           venusmmi\app\pluto_variation\adapter\Framework\vadp_v2p_nmgr.cpp \
           venusmmi\app\pluto_variation\adapter\Framework\vadp_v2p_autotest.cpp \
           venusmmi\app\pluto\Vapp_sat.cpp


SRC_LIST += venusmmi\app\common\ncenter\vsrv_notification.cpp \
            venusmmi\app\common\ncenter\vsrv_ncenter.cpp
           
ifneq ($(filter __MMI_NCENTER_SUPPORT__, $(strip $(MODULE_DEFS))),)

        ifeq ($(filter __MMI_KEY_ONLY_NCENTER__, $(strip $(MODULE_DEFS))),)
		 SRC_LIST += venusmmi\app\common\ncenter\vapp_ncenter.cpp \
                     venusmmi\app\common\ncenter\vapp_ncenter_test_cell.cpp \
                     venusmmi\app\common\ncenter\vapp_ncenter_quick_setting_cell.cpp \
                     venusmmi\app\common\ncenter\vapp_ncenter_base_cell.cpp \
                     venusmmi\app\common\ncenter\vapp_ncenter_entry.cpp \
                     venusmmi\app\common\ncenter\vapp_ncenter_system_cell.cpp
                 ifneq ($(filter __MMI_SAFE_MODE__, $(strip $(MODULE_DEFS))),)
                     SRC_LIST += venusmmi\app\common\ncenter\vapp_ncenter_safe_mode_cell.cpp
                 endif
        else
		 SRC_LIST += venusmmi\app\pluto_variation\ncenter\vapp_ncenter_pure_key.cpp \
		     venusmmi\app\pluto_variation\ncenter\vapp_ncenter_pure_key_test_cell.cpp \
		     venusmmi\app\pluto_variation\ncenter\vapp_ncenter_pure_key_quick_setting_cell.cpp \
		     venusmmi\app\pluto_variation\ncenter\vapp_ncenter_pure_key_base_cell.cpp \
		     venusmmi\app\pluto_variation\ncenter\vapp_ncenter_pure_key_entry.cpp \
		     venusmmi\app\pluto_variation\ncenter\vapp_ncenter_pure_key_system_cell.cpp
        endif
endif


ifneq ($(filter __PLUTO_MMI_PACKAGE__, $(strip $(MODULE_DEFS))),)
SRC_LIST += venusmmi\APP\pluto_variation\Mainmenu\vapp_mm_scr.cpp \
            venusmmi\APP\pluto_variation\Mainmenu\vcp_fancy_mode_menu.cpp \
            venusmmi\app\pluto_variation\Mainmenu\vcp_normal_mode_menu.cpp \
            venusmmi\app\pluto_variation\adapter\Mainmenu\vadp_p2v_mm.cpp \
            venusmmi\APP\pluto_variation\Mainmenu\vcp_matrix.cpp \
            venusmmi\APP\pluto_variation\Mainmenu\vcp_matrix_item.cpp \
            venusmmi\app\pluto_variation\ImageFlow\vapp_image_flow.cpp \
            venusmmi\app\pluto_variation\ImageFlow\vcp_image_flow.cpp \
            venusmmi\app\pluto_variation\adapter\ImageFlow\vadp_v2p_image_flow.c 
endif

ifneq ($(filter __PLUTO_MMI_PACKAGE__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\APP\pluto_variation\ShellApp\panel\MediaPlayer\vapp_shell_mediaplayer.cpp \
                venusmmi\app\pluto_variation\ShellApp\panel\MsgViewer\vapp_shell_msg_viewer.cpp \
                venusmmi\app\pluto_variation\ShellApp\panel\MsgViewer\vapp_notepaper.cpp \
                venusmmi\app\pluto_variation\ShellApp\panel\FavoriteContacts\vapp_shell_fc.cpp \
                venusmmi\app\pluto_variation\adapter\ShellApp\panel\MediaPlayer\vadp_shell_mediaplayer.cpp \
                venusmmi\app\pluto_variation\adapter\ShellApp\panel\MsgViewer\vadp_shell_msg_viewer.cpp

    ifneq ($(filter __MMI_VUI_SHELL_APP__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\app\pluto_variation\ShellApp\base\vapp_shell_scr.cpp \
                venusmmi\app\pluto_variation\ShellApp\base\vapp_shell_multi_page_cp.cpp \
                venusmmi\app\pluto_variation\ShellApp\base\vapp_shell_page_order.cpp \
                venusmmi\app\pluto_variation\ShellApp\base\vapp_shell_panel.cpp \
                venusmmi\app\pluto_variation\adapter\ShellApp\base\vadp_p2v_shell.cpp
    endif

    ifneq ($(filter __MMI_VUI_SHELL_SCREEN_LOCK__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\app\pluto_variation\ShellApp\base\vapp_shell_scrlock.cpp \
                venusmmi\app\pluto_variation\adapter\ShellApp\base\vadp_p2v_shell_scrlock.cpp
    endif

    ifneq ($(filter __MMI_VUI_SCREEN_LOCK_KEY__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\app\pluto_variation\ScreenLockKey\vapp_screen_lock_key_unlock.cpp \
                venusmmi\app\pluto_variation\ScreenLockKey\vapp_screen_lock_key_unlockitem.cpp \
                venusmmi\app\pluto_variation\ScreenLockKey\vapp_screen_lock_key_unlock_centry.cpp \
                venusmmi\app\pluto_variation\ScreenLockKey\vapp_screen_lock_key_unlock_default.cpp \
                venusmmi\app\pluto_variation\ScreenLockKey\vapp_screen_lock_key_unlock_calllog.cpp \
                venusmmi\app\pluto_variation\ScreenLockKey\vapp_screen_lock_key_unlock_msg.cpp \
                venusmmi\app\pluto_variation\ScreenLockKey\vapp_screen_lock_key_arrow.cpp \
                venusmmi\app\pluto_variation\ScreenLockKey\vapp_screen_lock_key_factory.cpp \
                venusmmi\app\pluto_variation\ScreenLockKey\vapp_screen_lock_key_main.cpp
    endif
    
    ifneq ($(filter __MMI_VUI_SCREEN_LOCK_KEY__, $(strip $(MODULE_DEFS))),)
        ifneq ($(filter __MMI_NCENTER_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += venusmmi\app\pluto_variation\ScreenLockKey\vapp_screen_lock_key_notification_cell.cpp \
                    venusmmi\app\pluto_variation\ScreenLockKey\vapp_screen_lock_key_notification_list.cpp \
                    venusmmi\app\pluto_variation\ScreenLockKey\vapp_screen_lock_key_notification.cpp
        endif
    endif

    ifneq ($(filter __MMI_VUI_SCREEN_LOCK_KEY__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\app\pluto_variation\ScreenLockKey\vapp_launcher_key_clock.cpp
    else
        ifneq ($(filter __MMI_VUI_LAUNCHER_KEY__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += venusmmi\app\pluto_variation\ScreenLockKey\vapp_launcher_key_clock.cpp
        endif
    endif

    ifneq ($(filter __MMI_VUI_WIDGET_KEY_MUSIC_PLAYER__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\app\pluto_variation\LauncherKey\widget\MusicPlayer\vapp_widget_key_musicplayer.cpp
    endif
    
    ifneq ($(filter __MMI_VUI_WIDGET_KEY_FM_RADIO__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\app\pluto_variation\LauncherKey\widget\fmradio\vapp_widget_key_fmradio.cpp
    endif


    ifneq ($(filter __MMI_VUI_HOMESCREEN__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_cp.cpp \
                venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_scr.cpp \
                venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_shortcut_mgr.cpp \
                venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_shortcut_cfg.cpp \
                venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_shortcut_panel.cpp \
                venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_widget_mgr.cpp \
                venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_widget_cfg.cpp \
                venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_widget_shortcut.cpp \
                venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_widget_operator_name.cpp \
                venusmmi\app\pluto_variation\adapter\ShellApp\panel\HomeScreen\vadp_p2v_hs_widget_recent_event.cpp \
                venusmmi\app\pluto_variation\adapter\ShellApp\panel\HomeScreen\vadp_v2p_hs_widget_recent_event.c \
                venusmmi\app\pluto_variation\adapter\ShellApp\panel\HomeScreen\vadp_p2v_hs.cpp \
                venusmmi\app\pluto_variation\adapter\ShellApp\panel\HomeScreen\vadp_v2p_hs.c
    endif

    ifneq ($(filter __MMI_VUI_HOMESCREEN_CLOCK__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_widget_clock.cpp \
                venusmmi\app\pluto_variation\adapter\ShellApp\panel\HomeScreen\vadp_v2p_hs_widget_dualclock.c
    endif

    ifneq ($(filter __MMI_VUI_HOMESCREEN_BAIDU_SEARCH__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_widget_baidu_search.cpp \
                venusmmi\app\pluto_variation\adapter\ShellApp\panel\HomeScreen\vadp_v2p_hs_widget_baidu_search.c
    endif

    ifneq ($(filter __MMI_VUI_HOMESCREEN_PROFILE__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_widget_profile.cpp \
                venusmmi\app\pluto_variation\adapter\ShellApp\panel\HomeScreen\vadp_v2p_widget_profile.c
    endif

    ifneq ($(filter __MMI_VUI_HOMESCREEN_NEXT_ALARM__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_widget_next_alarm.cpp
    endif

    ifneq ($(filter __MMI_VUI_HOMESCREEN_EVENT_INBOX__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_widget_event_inbox.cpp
    endif

    ifneq ($(filter __MMI_VUI_HOMESCREEN_PHOTO__,$(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_widget_photo.cpp \
                venusmmi\app\pluto_variation\adapter\ShellApp\panel\HomeScreen\vadp_p2v_widget_photo.cpp \
                venusmmi\app\pluto_variation\adapter\ShellApp\panel\HomeScreen\vadp_v2p_widget_photo.c
    endif

    ifneq ($(filter __MMI_VUI_HOMESCREEN_AUDIO_PLAYER__,$(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_widget_audplayer.cpp \
                venusmmi\app\pluto_variation\adapter\ShellApp\panel\HomeScreen\vadp_v2p_widget_audplayer.c
    endif

    ifneq ($(filter __MMI_VUI_HOMESCREEN_FM_RADIO__,$(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_widget_fmradio.cpp \
                venusmmi\app\pluto_variation\adapter\ShellApp\panel\HomeScreen\vadp_v2p_widget_fmradio.c
    endif

    ifneq ($(filter __MMI_VUI_SHELL_IMAGE_VIEWER__,$(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\APP\pluto_variation\ShellApp\panel\ImageViewer\vapp_shell_imageviewer.cpp \
                venusmmi\APP\pluto_variation\adapter\ShellApp\panel\ImageViewer\vadp_shell_imageviewer.cpp
    endif

    ifneq ($(filter __MMI_VUI_SHELL_RECENT_CALLS__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\app\pluto_variation\ShellApp\panel\RecentCalls\vapp_shell_recent_calls.cpp
    endif

    ifneq ($(filter __MMI_VUI_SHELL_SHORTCUTS__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\APP\pluto_variation\ShellApp\panel\Shortcuts\vapp_shell_shortcuts.cpp \
                venusmmi\APP\pluto_variation\adapter\ShellApp\panel\Shortcuts\vadp_shell_shortcuts.cpp
    endif

    ifneq ($(filter __MMI_VUI_SHELL_SETTINGS__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\app\pluto_variation\ShellApp\panel\Settings\vapp_shell_settings.cpp
    endif

    ifneq ($(filter __MMI_VUI_SHELL_OP01_HOMESCREEN__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\app\pluto_variation\ShellApp\panel\OP01HomeScreen\vapp_op01_hs_cp.cpp \
                venusmmi\app\pluto_variation\ShellApp\panel\OP01HomeScreen\vapp_op01_hs_scr.cpp \
                venusmmi\app\pluto_variation\adapter\ShellApp\panel\OP01HomeScreen\vadp_p2v_op01_hs.cpp \
                venusmmi\app\pluto_variation\adapter\ShellApp\panel\OP01HomeScreen\vadp_v2p_op01_hs.c
    endif

    ifneq ($(filter __MMI_VUI_HOMESCREEN_BOOKMARK__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_widget_bookmark.cpp \
                venusmmi\app\pluto_variation\adapter\ShellApp\panel\HomeScreen\vadp_v2p_hs_widget_bookmark.c
    endif

    ifneq ($(filter __MMI_VUI_HOMESCREEN_TODO__,$(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_widget_todo.cpp \
                venusmmi\app\pluto_variation\adapter\ShellApp\panel\HomeScreen\vadp_p2v_widget_todo.cpp
    endif 

    ifneq ($(filter __MMI_VUI_HOMESCREEN_ACLOCK__,$(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_widget_aclock.cpp
    endif

    ifneq ($(filter __MMI_VUI_HOMESCREEN_CALENDAR__,$(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_widget_calendar.cpp
    endif

    ifneq ($(filter __MMI_VUI_HOMESCREEN_DATE__,$(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_widget_date.cpp
    endif

    ifneq ($(filter __MMI_VUI_HOMESCREEN_DCLOCK__,$(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_widget_dclock.cpp
    endif

    ifneq ($(filter __MMI_VUI_HOMESCREEN_DUALCLOCK__,$(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_widget_dualclock.cpp
    endif

    ifneq ($(filter __MMI_VUI_HOMESCREEN_MEMO__,$(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_widget_memo.cpp \
                venusmmi\app\pluto_variation\adapter\ShellApp\panel\HomeScreen\vadp_v2p_hs_widget_memo.c
    endif

    ifneq ($(filter __MMI_VUI_HOMESCREEN_PET__,$(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_widget_pet.cpp
    endif

    ifneq ($(filter __MMI_VUI_HOMESCREEN_SNOW__,$(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\APP\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_widget_snow.cpp
    endif


    ifneq ($(filter __GADGET_SUPPORT__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\app\pluto_variation\ShellApp\panel\HomeScreen\vapp_hs_widget_delegator.cpp
    endif

    ifneq ($(filter __MMI_VUI_LAUNCHER__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\app\pluto_variation\Launcher\Desktop\vapp_desktop.cpp \
                venusmmi\app\pluto_variation\Launcher\Desktop\vapp_desktop_director.cpp \
                venusmmi\app\pluto_variation\Launcher\Desktop\vapp_desktop_primitive.cpp \
                venusmmi\app\pluto_variation\Launcher\Desktop\vapp_desktop_bar.cpp \
                venusmmi\app\pluto_variation\Launcher\Desktop\vapp_desktop_page.cpp \
                venusmmi\app\pluto_variation\Launcher\Desktop\vapp_desktop_page_selector.cpp \
                venusmmi\app\pluto_variation\Launcher\Desktop\vapp_desktop_popup_menu.cpp \
                venusmmi\app\pluto_variation\Launcher\Desktop\vapp_desktop_widget_selector.cpp \
                venusmmi\app\pluto_variation\Launcher\Desktop\vapp_desktop_shortcut_selector.cpp \
                venusmmi\app\pluto_variation\Launcher\AppWidget\vapp_app_widget.cpp \
                venusmmi\app\pluto_variation\Launcher\AppWidget\vapp_app_widget_shortcut.cpp \
                venusmmi\app\pluto_variation\Launcher\AppWidget\vapp_app_widget_primitive.cpp \
                venusmmi\app\pluto_variation\Launcher\AppWidget\vapp_app_widget_archive.cpp \
                venusmmi\app\pluto_variation\Launcher\AppWidget\vapp_app_widget_kit.cpp \
                venusmmi\app\pluto_variation\Launcher\AppWidget\vapp_app_widget_factory.cpp \
                venusmmi\app\pluto_variation\Launcher\AppWidget\vapp_app_widget_native_factory.cpp \
                venusmmi\app\pluto_variation\Launcher\AppWidget\vapp_app_widget_shortcut_factory.cpp \
                venusmmi\app\pluto_variation\Launcher\AppWidget\vapp_app_widget_clock.cpp \
                venusmmi\app\pluto_variation\Launcher\AppWidget\vapp_app_widget_operator_name_cosmos.cpp \
                venusmmi\app\pluto_variation\Launcher\Drawer\vapp_drawer.cpp \
                venusmmi\app\pluto_variation\Launcher\Drawer\vapp_drawer_builder.cpp \
                venusmmi\app\pluto_variation\Launcher\Drawer\vapp_drawer_page_menu.cpp
    endif

    ifneq ($(filter __MMI_VUI_LAUNCHER__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += venusmmi\app\pluto_variation\Launcher\Drawer\vapp_drawer_shortcut_bar.cpp
    else
        ifneq ($(filter __MMI_VUI_LAUNCHER_KEY__, $(strip $(MODULE_DEFS))),)
              SRC_LIST += venusmmi\app\pluto_variation\Launcher\Drawer\vapp_drawer_shortcut_bar.cpp
        endif
    endif

    ifneq ($(filter __MMI_VUI_LAUNCHER_KEY__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\app\pluto_variation\LauncherKey\Home\vapp_launcher_key.cpp \
                venusmmi\app\pluto_variation\LauncherKey\Home\vapp_launcher_key_director.cpp \
                venusmmi\app\pluto_variation\LauncherKey\Home\vapp_launcher_key_primitive.cpp \
                venusmmi\app\pluto_variation\LauncherKey\Home\vapp_launcher_key_widget_menu.cpp \
                venusmmi\app\pluto_variation\LauncherKey\Mainmenu\vapp_launcher_key_mainmenu.cpp \
                venusmmi\app\pluto_variation\LauncherKey\Mainmenu\vapp_launcher_key_mainmenu_builder.cpp \
                venusmmi\app\pluto_variation\LauncherKey\Mainmenu\vapp_launcher_key_mainmenu_page_menu.cpp
        ifneq ($(filter __OP01_3G__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += venusmmi\app\pluto_variation\LauncherKey\OPMainmenu\vapp_op_launcher_key_mainmenu_util.c \
                    venusmmi\app\pluto_variation\LauncherKey\OPMainmenu\OP01Mainmenu\vapp_op01_launcher_key_mainmenu.c \
                    venusmmi\app\pluto_variation\LauncherKey\OPHome\vapp_op_launcher_key_hs.cpp               
        endif
    endif

    ifneq ($(filter __MMI_VUI_WIDGET_KEY_IMAGE_VIEWER__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\app\pluto_variation\LauncherKey\widget\ImageViewer\vapp_widget_key_image_viewer_cache.cpp \
                venusmmi\app\pluto_variation\LauncherKey\widget\ImageViewer\vapp_widget_key_image_viewer_cell.cpp \
                venusmmi\app\pluto_variation\LauncherKey\widget\ImageViewer\vapp_widget_key_image_viewer_panel.cpp \
                venusmmi\app\pluto_variation\LauncherKey\widget\ImageViewer\vapp_widget_key_image_viewer.cpp
    endif

    ifneq ($(filter __MMI_VUI_WIDGET_KEY_VIP_CONTACT__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\app\pluto_variation\LauncherKey\Widget\VipContact\vapp_widget_favorite_contact.cpp
    endif

    ifneq ($(filter __MMI_VUI_WIDGET_KEY_MESSAGE__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\app\pluto_variation\LauncherKey\Widget\Message\vapp_widget_message.cpp
    endif

    ifneq ($(filter __MMI_VUI_WIDGET_KEY_ALARM__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += venusmmi\app\pluto_variation\LauncherKey\widget\Alarm\vapp_widget_key_alarm.cpp
    endif

endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WAVE__,$(strip $(MODULE_DEFS))),)
SRC_LIST += venusmmi\app\common\wallpaper\vapp_wallpaper_wave.cpp
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_CHIPSET__,$(strip $(MODULE_DEFS))),)
SRC_LIST += venusmmi\app\common\wallpaper\vapp_wallpaper_chipset.cpp
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_COMET__,$(strip $(MODULE_DEFS))),)
SRC_LIST += venusmmi\app\common\wallpaper\vapp_wallpaper_comet.cpp
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPACE__,$(strip $(MODULE_DEFS))),)
SRC_LIST += venusmmi\app\common\wallpaper\vapp_wallpaper_space.cpp
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPANGLE__,$(strip $(MODULE_DEFS))),)
SRC_LIST += venusmmi\app\common\wallpaper\vapp_wallpaper_spangle.cpp
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_FIREFLY__,$(strip $(MODULE_DEFS))),)
SRC_LIST += venusmmi\app\common\wallpaper\vapp_wallpaper_firefly.cpp
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MATRIX__,$(strip $(MODULE_DEFS))),)
SRC_LIST += venusmmi\app\common\wallpaper\vapp_wallpaper_matrix.cpp
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WILDWORLD__,$(strip $(MODULE_DEFS))),)
SRC_LIST += venusmmi\app\common\wallpaper\vapp_wallpaper_wildworld.cpp
endif

SRC_LIST += venusmmi\app\common\wallpaper\vapp_wallpaper_sakura.cpp

ifneq ($(filter __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__,$(strip $(MODULE_DEFS))),)
SRC_LIST += venusmmi\app\common\wallpaper\vapp_wallpaper_video.cpp
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_EARTH__,$(strip $(MODULE_DEFS))),)
SRC_LIST += venusmmi\app\common\wallpaper\vapp_wallpaper_3d_earth.cpp
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_WAVE__,$(strip $(MODULE_DEFS))),)
SRC_LIST += venusmmi\app\common\wallpaper\vapp_wallpaper_3d_wave.cpp
endif

ifneq ($(filter __MMI_VUI_MEDIAWALL__,$(strip $(MODULE_DEFS))),)
SRC_LIST += venusmmi\APP\pluto_variation\adapter\MediaWall\vadp_mediawall.cpp \
            venusmmi\APP\pluto_variation\MediaWall\vapp_mediawall.cpp
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_INTERACTIVE_VIDEO__,$(strip $(MODULE_DEFS))),)
    SRC_LIST += venusmmi\app\common\wallpaper\Vapp_wallpaper_frame_video.cpp
    SRC_LIST += venusmmi\app\common\wallpaper\Vapp_wallpaper_interactive_video.cpp
    SRC_LIST += venusmmi\app\common\wallpaper\vapp_wallpaper_video_decoder.c
    SRC_LIST += venusmmi\app\common\wallpaper\vapp_wallpaper_file.cpp
endif

ifneq ($(filter __COSMOS_3D_V10__,$(strip $(MODULE_DEFS))),)
	SRC_LIST += venusmmi\app\common\wallpaper\vapp_wallpaper_3d_sakura.cpp
endif

ifneq ($(filter __COSMOS_3D_V10__,$(strip $(MODULE_DEFS))),)
	SRC_LIST += venusmmi\app\common\wallpaper\vapp_wallpaper_3d_maple.cpp
endif

ifneq ($(filter __COSMOS_3D_V10__,$(strip $(MODULE_DEFS))),)
	SRC_LIST += venusmmi\app\common\wallpaper\vapp_wallpaper_3d_cassia.cpp
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MAV__,$(strip $(MODULE_DEFS))),)
SRC_LIST += venusmmi\app\common\wallpaper\Vapp_wallpaper_mav.cpp
endif

SRC_LIST += venusmmi\app\common\archive\vapp_archive_file.cpp \
            venusmmi\app\common\archive\vapp_archive_nvram.cpp

ifneq ($(filter __MMI_VUI_WIDGET_FACTORY__, $(strip $(MODULE_DEFS))),)
SRC_LIST += venusmmi\app\common\widget\vapp_widget_system.cpp \
            venusmmi\app\common\widget\vapp_widget.cpp \
            venusmmi\app\common\widget\vapp_widget_3d.cpp \
            venusmmi\app\common\widget\vapp_widget_mini_stage.cpp \
            venusmmi\app\common\widget\vapp_widget_shortcut.cpp \
            venusmmi\app\common\widget\vapp_widget_hello_world.cpp \
            venusmmi\app\common\widget\vapp_widget_primitive.cpp \
            venusmmi\app\common\widget\vapp_widget_kit.cpp \
            venusmmi\app\common\widget\vapp_widget_factory.cpp \
            venusmmi\app\common\widget\vapp_widget_native_factory.cpp \
            venusmmi\app\common\widget\vapp_widget_shortcut_factory.cpp
endif

ifneq ($(filter __MMI_VUI_WIDGET_MRE__, $(strip $(MODULE_DEFS))),)
SRC_LIST += venusmmi\app\common\widget\vapp_widget_mre.cpp \
            venusmmi\app\common\widget\vapp_widget_mre_factory.cpp \
            venusmmi\plugin\app\widget\vpi_widget_provider.cpp
endif

ifneq ($(filter __MMI_VUI_LAUNCHER_FACTORY__, $(strip $(MODULE_DEFS))),)
SRC_LIST += venusmmi\app\common\launcher\vapp_launcher_system.cpp \
            venusmmi\app\common\launcher\vapp_launcher_heap.cpp \
            venusmmi\app\common\launcher\vapp_launcher_setting_provider.cpp \
            venusmmi\app\common\launcher\vapp_launcher.cpp \
            venusmmi\app\common\launcher\vapp_launcher_hello_world.cpp \
            venusmmi\app\common\launcher\vapp_launcher_primitive.cpp \
            venusmmi\app\common\launcher\vapp_launcher_kit.cpp \
            venusmmi\app\common\launcher\vapp_launcher_factory.cpp \
            venusmmi\app\common\launcher\vapp_launcher_native_factory.cpp \
            venusmmi\app\common\launcher\vapp_launcher_develop.cpp
endif

ifneq ($(filter __MMI_VUI_LAUNCHER_MRE__, $(strip $(MODULE_DEFS))),)
SRC_LIST += venusmmi\app\common\launcher\vapp_launcher_mre.cpp \
            venusmmi\app\common\launcher\vapp_launcher_mre_factory.cpp \
            venusmmi\plugin\app\launcher\vpi_launcher_provider.cpp \
            venusmmi\plugin\app\widget\vpi_widget_primitive.cpp \
            venusmmi\plugin\app\widget\vpi_widget.cpp \
            venusmmi\plugin\app\widget\vpi_widget_kit.cpp
endif

ifneq ($(filter __MMI_VUI_SCREEN_LOCK_FACTORY__, $(strip $(MODULE_DEFS))),)
SRC_LIST += venusmmi\app\common\screen_lock\vapp_screen_lock_system.cpp \
            venusmmi\app\common\screen_lock\vapp_screen_lock_setting_provider.cpp \
            venusmmi\app\common\screen_lock\vapp_screen_lock_base.cpp \
            venusmmi\app\common\screen_lock\vapp_screen_lock_hello_world.cpp \
            venusmmi\app\common\screen_lock\vapp_screen_lock_primitive.cpp \
            venusmmi\app\common\screen_lock\vapp_screen_lock_kit.cpp \
            venusmmi\app\common\screen_lock\vapp_screen_lock_factory.cpp \
            venusmmi\app\common\screen_lock\vapp_screen_lock_native_factory.cpp
endif

ifneq ($(filter __MMI_VUI_SCREEN_LOCK_MRE__, $(strip $(MODULE_DEFS))),)
SRC_LIST += venusmmi\app\common\screen_lock\vapp_screen_lock_mre.cpp \
            venusmmi\app\common\screen_lock\vapp_screen_lock_mre_factory.cpp \
            venusmmi\plugin\app\screen_lock\vpi_screen_lock_provider.cpp
endif

ifneq ($(filter __MMI_VUI_WALLPAPER_MRE__, $(strip $(MODULE_DEFS))),)
SRC_LIST += venusmmi\app\common\wallpaper\vapp_wallpaper_mre.cpp \
            venusmmi\app\common\wallpaper\vapp_wallpaper_mre_factory.cpp \
            venusmmi\plugin\app\wallpaper\vpi_wallpaper_provider.cpp             
endif

ifneq ($(filter __MMI_VUI_LAUNCHER_MRE__, $(strip $(MODULE_DEFS))),)
SRC_LIST += venusmmi\plugin\app\wallpaper\vpi_wallpaper.cpp \
            venusmmi\plugin\app\wallpaper\vpi_wallpaper_kit.cpp
else
    ifneq ($(filter __MMI_VUI_SCREEN_LOCK_MRE__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += venusmmi\plugin\app\wallpaper\vpi_wallpaper.cpp \
                    venusmmi\plugin\app\wallpaper\vpi_wallpaper_kit.cpp
    endif           
endif

# Define include path lists to INC_DIR
INC_DIR = venusmmi\vrt\interface \
          venusmmi\framework \
          venusmmi\framework\interface \
          venusmmi\visual \
          venusmmi\visual\interface \
          venusmmi\app\common \
          venusmmi\app\pluto \
          venusmmi\app\common\interface \
          venusmmi\app\common\interface\cp \
          venusmmi\app\common\interface\service \
          venusmmi\app\common\interface\app \
          venusmmi\app\common\clipboard \
          venusmmi\app\common\wallpaper \
          venusmmi\app\common\platform \
          venusmmi\app\common\message \
          venusmmi\app\common\archive \
          venusmmi\app\common\widget \
          venusmmi\app\common\launcher \
          venusmmi\app\common\screen_lock \
          venusmmi\app\common\ncenter \
          venusmmi\app\pluto_variation\ncenter \
          venusmmi\app\pluto_variation\adapter \
          venusmmi\app\pluto_variation\adapter\interface \
          venusmmi\app\pluto_variation\adapter\interface\res \
          venusmmi\test\common \
          venusmmi\test\app \
          venusmmi\test\cp \
          venusmmi\test\vrt \
          venusmmi\test\framework\ui_core \
          venusmmi\test\framework\mmi_core \
          venusmmi\test\framework\xml \
          venusmmi\app \
          venusmmi\app\pluto_variation \
          venusmmi\framework\mmi_core \
          venusmmi\framework\ui_core\base \
          venusmmi\framework\ui_core\mvc \
          venusmmi\framework\ui_core\pme \
          venusmmi\framework\xml \
          venusmmi\app\common\data \
          venusmmi\app\common\ime \
          venusmmi\app\pluto_variation\adapter\interface\trc \
          venusmmi\app\pluto_variation\adapter\Framework \
          venusmmi\app\pluto_variation\adapter\GUI \
          venusmmi\visual\cp \
          venusmmi\visual\cp\common \
          venusmmi\visual\cp\fte \
          venusmmi\visual\cp\cosmos \
          applib\inet\engine\include \
          applib\mem\include \
          applib\misc\include \
          applib\kazlib \
          drv\include \
          fmt\include \
          fs\fat\include \
          interface\hwdrv \
          $(strip $(PS_FOLDER))\interfaces\local_inc \
          plutommi\customer\customerinc \
          plutommi\customer\customize \
          plutommi\customer\custresource \
          plutommi\mmi\asyncevents\asynceventsinc \
          plutommi\mmi\inc \
          plutommi\Framework\Interface \
          plutommi\mmi\inc\menuid \
          plutommi\Framework\CommonFiles\commoninc \
          plutommi\Framework\EventHandling\eventsinc \
          plutommi\Framework\History\historyinc \
          plutommi\Framework\MemManager\memmanagerinc \
          plutommi\Framework\NVRAMManager\nvrammanagerinc \
          plutommi\Framework\Tasks\tasksinc \
          plutommi\Framework\ThemeManager\thememanagerinc \
          plutommi\Framework\GUI\gui_inc \
          plutommi\Framework\GUI\oem_inc \
          plutommi\cui\inc \
          plutommi\CUI\MsgViewerCui\
          plutommi\mmi\miscframework\miscframeworkinc \
          plutommi\Framework\GDI\gdiinc \
          plutommi\service\mdi\mdiinc \
          plutommi\Service\ImgEdtSrv \
          plutommi\mtkapp\mtkappinc \
          plutommi\Framework\InputMethod\Engine\Engine_Inc \
          plutommi\Framework\InputMethod\Inc \
          plutommi\Framework\InputMethod\UI\UI_Inc \
          plutommi\mmi\CubeApp\CubeAppInc \
          plutommi\mmi\ShellApp\ShellAppInc \
          vendor\inputmethod\cstar\adaptation\include \
          vendor\inputmethod\t9\adaptation\include \
          btstacka\inc \
          interface\hal\bluetooth \
          drm\include \
          irda\inc \
          j2me\interface \
          j2me\jal\include \
          j2me\jal\include \
          media\image\include \
          media\rtp\inc \
          media\stream\include \
          usb\include \
          verno \
          wapadp\include \
          xmlp\include \
          plutommi\mmi\athandler\athandlerinc \
          plutommi\mmi\audio\audioinc \
          plutommi\Framework\BIDI\bidiinc \
          plutommi\mmi\browserapp\browser\browserinc \
          plutommi\mmi\browserapp\pushinbox\pushinboxinc \
          plutommi\Framework\CommonScreens\commonscreensinc \
          plutommi\mmi\cphs\cphsinc \
          plutommi\mmi\customerservice\customerserviceinc \
          plutommi\mmi\dataaccount\dataaccountinc \
          plutommi\mmi\datetime\datetimeinc \
          plutommi\Framework\DebugLevels\debuglevelinc \
          plutommi\mmi\dictionary\dictinc \
          plutommi\mmi\ebookreader\ebookinc \
          plutommi\mmi\emailapp\emailappinc \
          plutommi\mmi\extra\extrainc \
          plutommi\mmi\funandgames\funandgamesinc \
          plutommi\mmi\gpio\gpioinc \
          plutommi\service\gpiosrv \
          plutommi\mmi\gsmcallapplication\commonfiles\commoninc \
          plutommi\mmi\gsmcallapplication\incomingcallmanagement\incominginc \
          plutommi\mmi\gsmcallapplication\outgoingcallmanagement\outgoinginc \
          plutommi\mmi\help\helpinc \
          plutommi\mmi\idlescreen\idlescreeninc \
          plutommi\mmi\idlescreen\idlescreeninc\demoappinc \
          plutommi\MMI\Idle\IdleInc \
          plutommi\MMI\Dialer\DialerInc \
          plutommi\MMI\ScrLocker\ScrLockerInc \
          plutommi\MMI\ScrSaver\ScrSaverInc \
          plutommi\MMI\Factory\FactoryInc \
          plutommi\mmi\imps\impsinc \
          plutommi\Framework\IndicLanguages\indiclanguagesinc \
          plutommi\Framework\LangModule\LangModuleInc \
          plutommi\mmi\mainmenu\mainmenuinc \
          plutommi\mmi\messages \
          plutommi\mmi\messages\messagesinc \
          plutommi\mmi\mobileservice\mobileserviceinc \
          plutommi\Framework\MTE\mteinc \
          plutommi\Framework\MSLT\msltinc \
          plutommi\mmi\nitzhandler\nitzinc \
          plutommi\mmi\organizer\organizerinc \
          plutommi\mmi\phonebook\phonebookinc \
          plutommi\mmi\profiles\profilesinc \
          plutommi\mmi\resource\inc \
          plutommi\mmi\sat\satinc \
          plutommi\mmi\setting\settinginc \
          plutommi\mmi\smartmessage\smartmessageinc \
          plutommi\AppCore\ssc \
          plutommi\MMI\SimSpace\SimSpaceInc \
          plutommi\Service\AppMgrSrv \
          plutommi\Service\Inc \
          plutommi\Service\UmSrv \
          plutommi\Service\UmmsSrv \
          plutommi\mmi\unifiedcomposer\unifiedcomposerinc \
          plutommi\mmi\unifiedmessage\unifiedmessageinc \
          plutommi\mmi\unifiedmms\mmsapp\mmsappinc \
          plutommi\mmi\voip\voipinc \
          plutommi\mtkapp\abrepeater\abrepeaterinc \
          plutommi\mtkapp\audioplayer\audioplayerinc \
          plutommi\mtkapp\MediaPlayer\MediaPlayerInc \
          plutommi\mtkapp\avatar\avatarinc \
          plutommi\mtkapp\barcodereader\barcodereaderinc \
          plutommi\mtkapp\bgsound\bgsoundinc \
          plutommi\mtkapp\camera\camerainc \
          plutommi\MtkApp\ImageView\ImageViewInc \
          plutommi\mtkapp\camcorder\camcorderinc \
          plutommi\mtkapp\centralconfigagent\centralconfigagentinc \
          plutommi\mtkapp\connectivity\connectivityinc \
          plutommi\mtkapp\connectivity\connectivityinc\btcommon \
          plutommi\mtkapp\connectivity\connectivityinc\btmtk \
          plutommi\Framework\CSBrowser\csbrowserinc \
          plutommi\mtkapp\DCD\DCDInc \
          plutommi\mtkapp\dlagent\dlagentinc \
          plutommi\mtkapp\dmuiapp\dmuiappinc \
          plutommi\mtkapp\filemgr\filemgrinc \
          plutommi\mtkapp\fmradio\fmradioinc \
          plutommi\mtkapp\fmschedulerec\fmschedulerecinc \
          plutommi\mtkapp\GPS\GPSInc \
          plutommi\mtkapp\javaagency\javaagencyinc \
          plutommi\mtkapp\mmiapi\include \
          plutommi\mtkapp\mobiletvplayer\mobiletvplayerinc \
          plutommi\mtkapp\myfavorite\myfavoriteinc \
          plutommi\mtkapp\photoeditor\photoeditorinc \
          plutommi\mtkapp\pictbridge\pictbridgeinc \
          plutommi\mtkapp\rightsmgr\rightsmgrinc \
          plutommi\MtkApp\SoftwareTracer\SoftwareTracerInc \
          plutommi\mtkapp\soundrecorder\soundrecorderinc \
          plutommi\mtkapp\sndrec\sndrecinc \
          plutommi\mtkapp\answermachine\answermachineinc \
          plutommi\mtkapp\swflash\swflashinc \
          plutommi\mtkapp\syncml\syncmlinc \
          plutommi\mtkapp\video\videoinc \
          plutommi\mtkapp\vobjects\vobjectinc \
          plutommi\mtkapp\vrsd\vrsdinc \
          plutommi\mtkapp\vrsi\vrsiinc \
          plutommi\mtkapp\MREAPP\MREAPPInc \
          plutommi\vendorapp\devapp\devappinc \
          plutommi\Service\PlstSrv \
          plutommi\Service\MediaCacheSrv \
          plutommi\MMI\AppList\AppListInc\
          vendor\dict\gv\adaptation\inc \
          vendor\dict\motech\adaptation\inc \
          vendor\dict\trilogy\adaptation\inc \
          vendor\game_engine\brogent\adaptation \
          vendor\game_engine\brogent\game \
          vendor\game_engine\intergrafx\adaptation \
          vendor\game_engine\intergrafx\game \
          vendor\swflash\neomtel\adaptation\inc \
          vendor\wap\obigo_q05a\adaptation\integration\owl\include \
          vendor\wap\obigo_q05a\adaptation\modules\bam\include \
          vendor\wap\obigo_Q03C\v1_official\modules\bra\config \
          vendor\wap\obigo_Q03C\v1_official\modules\bra\refsrc \
          vendor\wap\obigo_Q03C\v1_official\modules\bra\source \
          vendor\wap\obigo_Q03C\v1_official\modules\mea\intgr \
          vendor\wap\obigo_Q03C\v1_official\msf\msf_lib\config \
          vendor\wap\obigo_Q03C\v1_official\msf\msf_lib\export \
          vendor\wap\obigo_Q03C\v1_official\msf\msf_lib\intgr \
          vendor\wap\obigo_Q03C\adaptation\modules\mma\include \
          vendor\wap\obigo_Q03C\adaptation\msf_ui\include \
          vendor\mobilevideo\adaption\MobileVideoInc\include_CM \
          vendor\mobilevideo\adaption\MobileVideoInc\include \
          plutommi\mmi\ipsecapp\ipsecappinc \
          plutommi\mmi\UDX\UDXInc \
          plutommi\mtkapp\SearchWeb\SearchWebInc \
          plutommi\Service\inc \
          applib\sqlite3\inc \
          vendor\player\ipeer\inc \
          plutommi\MtkApp\WgtMgrApp\WgtMgrAppInc \
          plutommi\MtkApp\NPPlg\NPPlgInc \
          vendor\widget\google\adaptation\extensions\maui_audio_framework \
          vendor\widget\google\adaptation \
          plutommi\MtkApp\WidgetDelegator\WidgetDelegatorInc \
          vendor\opera\browser\v1_official\opdev\include \
          vendor\opera\browser\adaptation\inc \
          plutommi\mmi\CallLog\CallLogInc \
          plutommi\Service\ProfilesSrv \
          plutommi\CUI\ImageViewCui \
          plutommi\MMI\PhoneBook\Core \
          plutommi\mmi\sns\snsinc \
          venusmmi\app\pluto_variation\interface \
          venusmmi\app\pluto_variation\ShellApp\base \
          venusmmi\app\pluto_variation\ShellApp\panel \
          venusmmi\app\pluto_variation\ScreenLockKey \
          venusmmi\app\pluto_variation\ShellApp\panel\HomeScreen \
          venusmmi\app\pluto_variation\ShellApp\panel\RecentCalls \
          venusmmi\app\pluto_variation\ShellApp\panel\ImageViewer \
          venusmmi\app\pluto_variation\ShellApp\panel\Shortcuts \
          venusmmi\app\pluto_variation\ShellApp\panel\MsgViewer \
          venusmmi\app\pluto_variation\ShellApp\panel\FavoriteContacts \
          venusmmi\app\pluto_variation\ShellApp\panel\MediaPlayer \
          venusmmi\app\pluto_variation\ShellApp\panel\Settings \
          venusmmi\app\pluto_variation\ShellApp\panel\OP01HomeScreen \
          venusmmi\app\pluto_variation\Launcher\Desktop \
          venusmmi\app\pluto_variation\Launcher\AppWidget \
          venusmmi\app\pluto_variation\Launcher\Drawer \
          venusmmi\app\pluto_variation\LauncherKey\Home \
          venusmmi\app\pluto_variation\LauncherKey\widget\Alarm \
          venusmmi\app\pluto_variation\LauncherKey\widget\ImageViewer \
          venusmmi\app\pluto_variation\LauncherKey\widget\VipContact \
          venusmmi\app\pluto_variation\LauncherKey\widget\Message \
          venusmmi\app\pluto_variation\adapter\ShellApp\base \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel\HomeScreen \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel\MediaPlayer \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel\ImageViewer \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel\Shortcuts \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel\MsgViewer \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel\OP01HomeScreen \
          venusmmi\app\pluto_variation\adapter\MediaWall \
          venusmmi\app\pluto_variation\adapter\MultiTouchTest \
          venusmmi\app\pluto_variation\MultiTouchTest \
          venusmmi\app\Cosmos\interface\cui \
          venusmmi\app\Cosmos\WidgetDelegator \
          venusmmi\app\Cosmos\interface\app \
          venusmmi\app\Cosmos\LauncherCosmos\MM \
          venusmmi\app\Cosmos\Theme \
          venusmmi\app\Cosmos\Setting\launcher_screen_lock \
          venusmmi\app\pluto_variation\adapter\ime \
          plutommi\Framework\InputMethod\inc \
          interface\hal\drv_sw_def \
          venusmmi\app\pluto_variation\ImageFlow \
          plutommi\Service\DtcntSrv \
          interface\hal\video_codec \
          interface\hal\graphics \
          venusmmi\app\pluto_variation\LauncherKey\widget\musicplayer \
          venusmmi\app\pluto_variation\LauncherKey\Mainmenu \
          venusmmi\app\pluto_variation\LauncherKey\OPMainmenu \
          venusmmi\app\pluto_variation\LauncherKey\OPHome

ifneq ($(filter __MMI_VENUS_PLUG_IN_ENGINE__, $(strip $(MODULE_DEFS))),)
INC_DIR +=venusmmi\plugin\framework\interface \
          venusmmi\plugin\framework\mmi_core \
          venusmmi\plugin\framework\ui_core\base \
          venusmmi\plugin\framework\ui_core\mvc \
          venusmmi\plugin\framework\ui_core\pme \
          venusmmi\plugin\visual\cp \
          venusmmi\plugin\app\interface \
          plutommi\Service\GetSrvSrv
endif

INC_DIR += venusmmi\plugin\app\widget

ifneq ($(filter __MMI_VUI_LAUNCHER_MRE__, $(strip $(MODULE_DEFS))),)
INC_DIR += venusmmi\plugin\app\launcher
INC_DIR += venusmmi\plugin\app\wallpaper 
endif

ifneq ($(filter __MMI_VUI_SCREEN_LOCK_MRE__, $(strip $(MODULE_DEFS))),)
INC_DIR += venusmmi\plugin\app\screen_lock
INC_DIR += venusmmi\plugin\app\wallpaper 
endif

ifneq ($(filter __MMI_VUI_WALLPAPER_MRE__, $(strip $(MODULE_DEFS))),)
INC_DIR += venusmmi\plugin\app\wallpaper 
endif

ifeq ($(strip $(VENUS_MMI)),VENUS_3D)
INC_DIR +=vendor\intergrafx_hw\LW\Mimosa \
          vendor\intergrafx_hw\LW\Girl \
          vendor\intergrafx_hw\LW\Clock \
          vendor\intergrafx_hw\LW\Horse \
          vendor\intergrafx_hw\LW\Daydream \
          vendor\intergrafx_hw\LW\Lighthouse \
          vendor\intergrafx_hw\LW\Puppy \
          vendor\intergrafx_hw\LW\Solar \
          vendor\intergrafx_hw\LW\Fish \
          vendor\intergrafx_hw\LW\Transformer \
          venusmmi\app\pluto
else
INC_DIR +=vendor\intergrafx\LW\Mimosa \
          vendor\intergrafx\LW\Girl \
          vendor\intergrafx\LW\Clock \
          vendor\intergrafx\LW\Horse \
          vendor\intergrafx\LW\Daydream \
          vendor\intergrafx\LW\Lighthouse \
          vendor\intergrafx\LW\Puppy \
          vendor\intergrafx\LW\Solar \
          vendor\intergrafx\LW\Fish \
          vendor\intergrafx\LW\Transformer \
          venusmmi\app\pluto
endif

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
INC_DIR += venusmmi\app\Cosmos\Ucm
else
INC_DIR += plutommi\mmi\Ucm\UcmInc
endif