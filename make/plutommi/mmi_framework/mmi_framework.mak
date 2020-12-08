# Define source file lists to SRC_LIST
SRC_LIST = plutommi\Framework\CommonScreens\CommonScreensSrc\AlertScreen.c \
           plutommi\customer\custresource\custnfbprogressimg.c \
           plutommi\Framework\CommonScreens\commonscreenssrc\appmem.c \
           plutommi\Framework\CommonScreens\commonscreenssrc\commonscreens.c \
	     plutommi\mmi\setting\settingsrc\preferedinputmethodsetting.c \
           plutommi\Framework\DebugLevels\debuglevelsrc\debuginit.c \
           plutommi\Framework\CallbackManager\mmi_cb_mgr.c \
           plutommi\Framework\CommonFiles\commonsrc\mmi_frm_utility.c \
           plutommi\Framework\Scenario\Scenario.c \
           plutommi\Framework\Scenario\mmi_frm_scenario_llist.c \
           plutommi\Framework\EventHandling\eventssrc\event_handler.c \
           plutommi\Framework\EventHandling\eventssrc\events.c \
           plutommi\Framework\EventHandling\eventssrc\keybrd.c \
           plutommi\Framework\EventHandling\eventssrc\key_tone.c \
           plutommi\Framework\EventHandling\eventssrc\mmitimer.c \
           plutommi\Framework\EventHandling\EventsSrc\mmi_frm_key_routing.c \
           plutommi\Framework\EventHandling\EventsSrc\inputs.c \
           plutommi\Framework\EventHandling\EventsSrc\AT_utility.c \
           plutommi\Framework\History\historysrc\history.c \
           plutommi\Framework\History\historysrc\sublcdhistory.c \
           plutommi\Framework\MemManager\memmanagersrc\AppMemMgrUT.c \
           plutommi\Framework\MemManager\memmanagersrc\AppMemMgrCore.c \
           plutommi\Framework\MemManager\memmanagersrc\appmemmgr.c \
           plutommi\Framework\MemManager\memmanagersrc\scrmemmgr.c \
           plutommi\Framework\MemManager\memmanagersrc\fix_size_mem.c \
           plutommi\Framework\MemManager\memmanagersrc\mmimemmonitor.c \
           plutommi\Framework\MemManager\memmanagersrc\mmi_clipboard.c \
           plutommi\Framework\MemManager\memmanagersrc\mmi_frm_cache.c \
           plutommi\Framework\NVRAMManager\nvrammanagersrc\nvraminterface.c \
           plutommi\Framework\Tasks\taskssrc\mmitask.c \
           plutommi\Framework\Tasks\TasksSrc\mmi_frm_remutex.c \
           plutommi\Framework\Tasks\taskssrc\event_flag.c \
           plutommi\Framework\Tasks\taskssrc\queue.c \
           plutommi\Framework\Tasks\taskssrc\taskinit.c \
           plutommi\Framework\ThemeManager\thememanagersrc\themeconverterui.c \
           plutommi\Framework\ThemeManager\thememanagersrc\themeconverterxml.c \
           plutommi\Framework\ThemeManager\thememanagersrc\thememanager.c \
           plutommi\Framework\Notification\NotificationSrc\Notification.c \
           plutommi\Framework\GUI\gui_src\gui.c \
           plutommi\Framework\GUI\gui_src\gui_asyncdynamic_menus.c \
           plutommi\Framework\GUI\gui_src\gui_buttons.c \
           plutommi\Framework\GUI\gui_src\gui_bytestream.c \
           plutommi\Framework\GUI\gui_src\gui_calendar.c \
           plutommi\Framework\GUI\gui_src\gui_clock.c \
           plutommi\Framework\GUI\gui_src\gui_color_slider.c \
           plutommi\Framework\GUI\gui_src\gui_custom_menus.c \
           plutommi\Framework\GUI\gui_src\gui_dynamic_menus.c \
           plutommi\Framework\GUI\gui_src\gui_ems.c \
           plutommi\Framework\GUI\gui_src\gui_fixed_menuitems.c \
           plutommi\Framework\GUI\gui_src\gui_fixed_menus.c \
           plutommi\Framework\GUI\gui_src\gui_font_size.c \
           plutommi\Framework\GUI\OEM_SRC\gui_font_oem.c \
           plutommi\Framework\GUI\gui_src\gui_hardware_dependent.c \
           plutommi\Framework\GUI\gui_src\gui_inputs.c \
           plutommi\Framework\GUI\gui_src\gui_text_frame.c\
           plutommi\Framework\GUI\gui_src\gui_inputs_cache.c \
           plutommi\Framework\GUI\gui_src\gui_wcss_inputs.c \
           plutommi\Framework\GUI\gui_src\gui_multi_line_inputs.c \
           plutommi\Framework\GUI\gui_src\gui_single_line_inputs.c \
           plutommi\Framework\GUI\gui_src\gui_ems_inputs.c \
           plutommi\Framework\GUI\gui_src\gui_menu_shortcut.c \
           plutommi\Framework\GUI\gui_src\gui_panel.c \
           plutommi\Framework\GUI\gui_src\gui_scrollbars.c \
           plutommi\Framework\GUI\OEM_SRC\gui_scrollbars_oem.c \
           plutommi\Framework\GUI\gui_src\gui_spectrum.c \
           plutommi\Framework\GUI\gui_src\gui_tab_bars.c \
           plutommi\Framework\GUI\oem_src\gui_tab_bars_oem.c \
           plutommi\Framework\GUI\gui_src\gui_text_label.c \
           plutommi\Framework\GUI\gui_src\gui_themes.c \
           plutommi\Framework\GUI\gui_src\gui_title.c \
           plutommi\Framework\GUI\OEM_SRC\gui_title_oem.c \
           plutommi\Framework\GUI\gui_src\gui_virtual_keyboard.c \
           plutommi\Framework\GUI\gui_src\gui_icon_bar.c \
           plutommi\Framework\GUI\gui_src\gui_windows.c \
           plutommi\Framework\GUI\gui_src\gui_video.c \
           plutommi\Framework\GUI\oem_src\gui_menu_oem.c \
           plutommi\Framework\GUI\oem_src\gui_effect_oem.c \
           plutommi\Framework\GUI\oem_src\gui_sse_oem.c \
           plutommi\Framework\GUI\oem_src\gui_main_menu_oem.c \
           plutommi\Framework\GUI\gui_src\wgui.c \
           plutommi\Framework\GUI\gui_src\wgui_tree.c \
           plutommi\Framework\GUI\gui_src\wgui_asyncdynamic_menuitems.c \
           plutommi\Framework\GUI\gui_src\wgui_asyncdynamic_menus.c \
           plutommi\Framework\GUI\gui_src\wgui_calendar.c \
           plutommi\Framework\GUI\gui_src\wgui_categories.c \
           plutommi\Framework\GUI\gui_src\wgui_categories_cm.c \
           plutommi\Framework\GUI\gui_src\wgui_categories_fmgr.c \
           plutommi\Framework\GUI\gui_src\wgui_categories_idlescreen.c \
           plutommi\Framework\GUI\gui_src\wgui_categories_inputs.c \
           plutommi\Framework\GUI\gui_src\wgui_categories_list.c \
           plutommi\Framework\Fontengine\SubtitleFont.c \
           plutommi\Framework\Launcher\mmi_frm_app_launcher.c \
           plutommi\Framework\DCM\mmi_ap_dcm.c

ifneq ($(filter __PLUTO_MMI_PACKAGE__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_calendar.c \
            plutommi\Framework\GUI\gui_src\wgui_categories_clock.c \
            plutommi\Framework\GUI\gui_src\wgui_categories_common.c \
            plutommi\Framework\GUI\gui_src\wgui_categories_email.c \
            plutommi\Framework\GUI\gui_src\wgui_categories_ems.c \
            plutommi\Framework\GUI\gui_src\wgui_categories_memory.c \
            plutommi\Framework\GUI\gui_src\wgui_categories_mm.c \
            plutommi\Framework\GUI\gui_src\wgui_categories_panel.c \
            plutommi\Framework\GUI\gui_src\wgui_categories_pe.c \
            plutommi\Framework\GUI\gui_src\wgui_categories_tab.c \
            plutommi\Framework\GUI\gui_src\wgui_categories_compatible.c
endif

ifneq ($(filter __UI_MMS_VIEWER_CATEGORY__, $(strip $(MODULE_DEFS))),) 
SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_mms_viewer.c
endif


ifneq ($(filter __COSMOS_MMI_PACKAGE__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\Framework\MemManager\memmanagersrc\mmi_frm_temp_mem.c
endif

SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_multimedia.c \
           plutommi\Framework\GUI\gui_src\wgui_categories_notification.c \
           plutommi\Framework\GUI\gui_src\wgui_categories_popup.c \
           plutommi\Framework\GUI\gui_src\wgui_categories_search.c \
           plutommi\Framework\GUI\gui_src\wgui_categories_sublcd.c \
           plutommi\Framework\GUI\gui_src\wgui_categories_text_viewer.c \
           plutommi\Framework\GUI\gui_src\wgui_categories_util.c \
           plutommi\Framework\GUI\OEM_SRC\wgui_hint_oem.c \
           plutommi\Framework\GUI\gui_src\wgui_clock.c \
           plutommi\Framework\GUI\gui_src\wgui_datetime.c \
           plutommi\Framework\GUI\gui_src\wgui_draw_manager.c \
           plutommi\Framework\GUI\gui_src\wgui_dynamic_menuitems.c \
           plutommi\Framework\GUI\gui_src\wgui_dynamic_menus.c \
           plutommi\Framework\GUI\gui_src\wgui_ems.c \
           plutommi\Framework\GUI\gui_src\wgui_fixed_menuitems.c \
           plutommi\Framework\GUI\gui_src\wgui_fixed_menus.c 
           
ifneq  ($(filter __MMI_INLINE_SLIM__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_inline_edit_Slim.c
else          
	SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_inline_edit.c
endif
                       
SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_progress_bar.c \
           plutommi\Framework\GUI\gui_src\gui_progress_bar.c \
           plutommi\Framework\GUI\gui_src\wgui_inputs.c \
           plutommi\Framework\GUI\gui_src\wgui_inputs_multiline.c \
           plutommi\Framework\GUI\gui_src\wgui_inputs_singleline.c \
           plutommi\Framework\GUI\gui_src\wgui_inputs_dialer.c \
           plutommi\Framework\GUI\gui_src\wgui_editor.c \
           plutommi\Framework\GUI\gui_src\wgui_panel.c \
           plutommi\Framework\GUI\gui_src\wgui_softkeys.c \
           plutommi\Framework\GUI\OEM_SRC\wgui_softkey_oem.c \
           plutommi\Framework\GUI\oem_src\gui_status_icon_bar_oem.c \
           plutommi\Framework\GUI\gui_src\gui_status_icon.c \
           plutommi\Framework\GUI\gui_src\gui_status_icon_bar.c \
           plutommi\Framework\GUI\gui_src\wgui_status_icon_bar.c \
           plutommi\Framework\GUI\gui_src\gui_slide_bar.c \
           plutommi\Framework\GUI\gui_src\wgui_slide_bar.c \
           plutommi\Framework\GUI\gui_src\wgui_tab_bars.c \
           plutommi\Framework\GUI\gui_src\wgui_text_label.c \
           plutommi\Framework\GUI\gui_src\wgui_title.c \
           plutommi\Framework\GUI\gui_src\wgui_touch_screen.c \
           plutommi\Framework\GUI\gui_src\wgui_virtual_keyboard.c \
           plutommi\Framework\GUI\gui_src\wgui_icon_bar.c \
           plutommi\Framework\GUI\gui_src\wingui.c \
           plutommi\Framework\GUI\gui_src\wgui_video.c \
           plutommi\Framework\GUI\gui_src\gui_image.c \
           plutommi\Framework\GUI\gui_src\wgui_image.c \
           plutommi\Framework\GUI\gui_src\gui_horizontal_selector.c \
           plutommi\Framework\GUI\gui_src\gui_touch_feedback.c \
           plutommi\Framework\GUI\oem_src\gui_touch_feedback_oem.c \
           plutommi\Framework\InputMethod\Engine\Engine_Src\Imc.c \
           plutommi\Framework\InputMethod\Engine\Engine_Src\Imc_key.c \
           plutommi\Framework\InputMethod\Engine\Engine_Src\Imc_pen.c \
           plutommi\Framework\InputMethod\Engine\Engine_Src\Imm.c \
           plutommi\Framework\InputMethod\Engine\Engine_Src\Imm_qwerty.c \
           plutommi\Framework\InputMethod\UI\UI_Src\Imui.c \
           plutommi\Framework\LangModule\LangModuleSrc\CommonLang.c \
           plutommi\Framework\LangModule\LangModuleSrc\LangModule.c \
           plutommi\Framework\Charset\ascii.c \
           plutommi\mmi\miscframework\miscframeworksrc\bootupapp.c \
           plutommi\Framework\Charset\gsm7bitdefaultalphabet.c \
           plutommi\mmi\miscframework\miscframeworksrc\mempoolcontainer.c \
           plutommi\Framework\Fontengine\pixcomfontengine.c \
           plutommi\Framework\Fontengine\lang_interface.c \
           plutommi\Framework\Profiling\profilingengine.c \
           plutommi\Framework\Screenrotation\screenrotation.c \
           plutommi\Framework\Screenrotation\SensorRotation.c \
           plutommi\mmi\miscframework\miscframeworksrc\simdetection.c \
           plutommi\mmi\miscframework\miscframeworksrc\smlmenu.c \
           plutommi\mmi\miscframework\miscframeworksrc\LangErrorHandle.c \
           plutommi\Framework\Charset\ucs2.c \
           plutommi\Framework\Charset\Gsm7BitNationalLang.c \
           plutommi\Framework\Procedure\Procedure.c \
           plutommi\Framework\MTE\mtesrc\mte.c \
           plutommi\Framework\MSLT\msltsrc\mslt.c \
           plutommi\mtkapp\mmiapi\src\mmiapi_main.c \
           plutommi\mtkapp\mmiapi\src\mmiapi_sms.c \
           plutommi\mtkapp\mmiapi\src\mmiapi_sms_msg.c \
           plutommi\mtkapp\mmiapi\src\mmiapi_wap.c \
           plutommi\mtkapp\mtkappsrc\ctk.c

ifneq  ($(filter __J2ME__, $(strip $(MODULE_DEFS))),)
  ifeq  ($(filter __MVM__, $(strip $(MODULE_DEFS))),)
	  SRC_LIST += plutommi\mtkapp\mmiapi\src\mmiapi_ui.c
  endif
endif

ifneq ($(strip $(MMI_VERSION)),COSMOS_MMI)
SRC_LIST += plutommi\mmi\miscframework\miscframeworksrc\pwroncharger.c \
           plutommi\Framework\CSBrowser\csbrowsersrc\catscreenbrowser.c \
           plutommi\Framework\CSBrowser\csbrowsersrc\csbentryhandlers.c \
           plutommi\Framework\CSBrowser\csbrowsersrc\csbframework.c \
           plutommi\Framework\GUI\gui_src\wgui_categories_sim.c
endif

SRC_LIST += vendor\inputmethod\mtk\mtkmultitap.c \
           plutommi\CUI\FSEditorCui\FSEditorCui.c \
           plutommi\CUI\MenuCui\MenuCui.c 
           
ifneq  ($(filter __MMI_INLINE_SLIM__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += plutommi\CUI\InlineCui\InlineCui_Slim.c
else          
	SRC_LIST += plutommi\CUI\InlineCui\InlineCui.c
endif
           
ifneq ($(filter __MMI_IME_PLUG_IN__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\Framework\InputMethod\SDK_Layer\SDK_Src\ImeSDK.c
endif

ifneq ($(filter __MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__ __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\mmi\miscframework\miscframeworksrc\FontManager.c
endif

ifneq ($(filter __MMI_BIDI_ALG__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\Framework\BIDI\bidisrc\bidi.c \
           plutommi\Framework\BIDI\bidisrc\bidi_l_rules.c \
           plutommi\Framework\BIDI\bidisrc\bidicharmap.c \
           plutommi\Framework\BIDI\bidisrc\bidipararules.c \
           plutommi\Framework\BIDI\bidisrc\bidiprocessdatatypes.c
endif

ifneq ($(filter __PLUTO_MMI_PACKAGE__, $(strip $(MODULE_DEFS))),)
    ifneq ($(filter __MMI_CSB_BROWSER__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_mms.c
    else
            ifneq ($(filter __MMI_SMART_MESSAGE_MO__, $(strip $(MODULE_DEFS))),)
                SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_mms.c
            else
                ifneq ($(filter __MMI_CAT203_SUPPORT__, $(strip $(MODULE_DEFS))),)
                    SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_mms.c
                endif
            endif
    endif
endif

ifneq ($(filter __MMI_STOPWATCH__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_stopwatch.c
endif

ifneq ($(filter __PLUTO_MMI_PACKAGE__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_uce.c
endif

ifneq ($(filter __PLUTO_MMI_PACKAGE__, $(strip $(MODULE_DEFS))),)
    ifneq ($(filter __MMI_ANIMATED_DIAL__, $(strip $(MODULE_DEFS))),)
               SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_dialer.c
    else
      ifneq ($(filter __MMI_MOTION_DIAL__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_dialer.c
      endif
    endif
endif

ifneq ($(filter __PLUTO_MMI_PACKAGE__, $(strip $(MODULE_DEFS))),)
    ifneq ($(filter __CTM_SUPPORT__, $(strip $(MODULE_DEFS))),)
       SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_imps.c
    else
      ifneq ($(filter __MMI_IMPS__, $(strip $(MODULE_DEFS))),)
          SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_imps.c
      else
          ifneq ($(filter __MMI_CSB_BROWSER__, $(strip $(MODULE_DEFS))),)
                SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_imps.c
          endif
      endif
    endif
endif

ifneq ($(filter __MMI_GESTURES_FRAMEWORK__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\Framework\EventHandling\eventssrc\mmi_frm_gestures.c \
              plutommi\Framework\EventHandling\eventssrc\mmi_frm_gestures_cfg.c
endif

ifneq ($(filter __MMI_TOUCH_SCREEN__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\Framework\EventHandling\eventssrc\touchscreen.c
endif

ifneq ($(filter __MMI_OP11_SIDEBAR__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\Framework\GUI\gui_src\gui_side_bar.c \
                plutommi\Framework\GUI\gui_src\wgui_side_bar.c
endif

ifneq ($(filter __MMI_OP12_TOOLBAR__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\Framework\GUI\gui_src\gui_toolbar.c \
                plutommi\Framework\GUI\gui_src\wgui_toolbar.c
endif

ifneq ($(filter __MMI_OP01_DCD__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_list_op.c
else
    ifneq ($(filter __MMI_OP11_HOMESCREEN__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_list_op.c
    else
        ifneq ($(filter __MMI_CAT1X_0P11_SUPPORT__, $(strip $(MODULE_DEFS))),)
            SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_list_op.c
        else
            ifneq ($(filter __MMI_OP01_DCD_V30__, $(strip $(MODULE_DEFS))),)
                SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_list_op.c
            endif
        endif
    endif
endif

ifneq ($(filter __MMI_OP11_CAT433_SUPPORT__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_idlescreen_op.c
else
    ifneq ($(filter __MMI_OP12_CAT533_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_idlescreen_op.c
    else
        ifneq ($(filter __MMI_CAT203_SUPPORT__, $(strip $(MODULE_DEFS))),)
            SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_idlescreen_op.c
        endif
    endif
endif

ifneq ($(filter __MMI_OP01_DCD__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_op.c
else
    ifneq ($(filter __MMI_OP11_HOMESCREEN__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_op.c
    else
        ifneq ($(filter __MMI_OP02_LEMEI__, $(strip $(MODULE_DEFS))),)
            SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_op.c
        else
            ifneq ($(filter __MMI_OP01_DCD_V30__, $(strip $(MODULE_DEFS))),)
                SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_op.c
            endif
        endif
    endif
endif

ifneq ($(filter __MMI_OP11_HOMESCREEN__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_popup_op.c
else
    ifneq ($(filter __MMI_OP01_DCD_V30__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\Framework\GUI\gui_src\wgui_categories_popup_op.c
    endif
endif


ifneq ($(filter __MMI_QWERTY_KEYPAD_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\Framework\EventHandling\eventssrc\mmi_frm_qwerty.c
endif

ifneq ($(filter __MMI_SUBLCD_MASTER_MODE__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\Framework\EventHandling\eventssrc\sublcd_master.c
endif


ifneq ($(filter __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\Framework\CommonFiles\commonsrc\FrameworkBackwardCompatible.c
else
  ifneq ($(filter __MMI_FRAMEWORK_BACKWARD_COMPATIBLE_SPEC__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\Framework\CommonFiles\commonsrc\FrameworkBackwardCompatible.c
  endif
endif


ifneq ($(filter __MMI_TOUCH_SCREEN__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\Framework\InputMethod\engine\engine_src\imc_pen.c
endif

ifneq ($(filter WAP_SUPPORT, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mtkapp\mtkappsrc\wap_stub.c
endif

ifneq ($(filter __MMI_LANG_BENGALI__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += plutommi\Framework\IndicLanguages\indiclanguagessrc\bengali.c
else
ifneq ($(filter __MMI_LANG_ASSAMESE__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += plutommi\Framework\IndicLanguages\indiclanguagessrc\bengali.c
endif
endif
ifneq ($(filter __MMI_LANG_ASSAMESE__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += plutommi\Framework\IndicLanguages\indiclanguagessrc\assamese.c
endif
ifneq ($(filter __MMI_LANG_HINDI__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += plutommi\Framework\IndicLanguages\indiclanguagessrc\hindi.c
else
ifneq ($(filter __MMI_LANG_MARATHI__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += plutommi\Framework\IndicLanguages\indiclanguagessrc\hindi.c
endif
endif
ifneq ($(filter __MMI_LANG_MALAYALAM__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += plutommi\Framework\IndicLanguages\indiclanguagessrc\malayalam.c
endif
ifneq ($(filter __MMI_LANG_ORIYA__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += plutommi\Framework\IndicLanguages\indiclanguagessrc\oriya.c
endif
ifneq ($(filter __MMI_LANG_KANNADA__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += plutommi\Framework\IndicLanguages\indiclanguagessrc\kannada.c
endif
ifneq ($(filter __MMI_LANG_GUJARATI__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += plutommi\Framework\IndicLanguages\indiclanguagessrc\gujarati.c
endif
ifneq ($(filter __MMI_INDIC_ALG__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += plutommi\Framework\IndicLanguages\indiclanguagessrc\indicruleengine.c \
           plutommi\Framework\IndicLanguages\indiclanguagessrc\indicruleenginecommon.c
endif
ifneq ($(filter __MMI_LANG_MARATHI__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += plutommi\Framework\IndicLanguages\indiclanguagessrc\marathi.c
endif
ifneq ($(filter __MMI_LANG_PUNJABI__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += plutommi\Framework\IndicLanguages\indiclanguagessrc\punjabi.c
endif
ifneq ($(filter __MMI_LANG_TAMIL__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += plutommi\Framework\IndicLanguages\indiclanguagessrc\tamil.c
endif
ifneq ($(filter __MMI_LANG_TELUGU__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += plutommi\Framework\IndicLanguages\indiclanguagessrc\telugu.c
endif

ifneq ($(filter __MMI_LANG_KHMER__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += plutommi\Framework\Languages\Khmer\KhmerSrc\Khmer.c
endif
ifneq ($(filter __MMI_LANG_LAO__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += plutommi\Framework\Languages\Lao\LaoSrc\Lao.c
endif
ifneq ($(filter __MMI_LANG_MYANMAR__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += plutommi\Framework\Languages\Mynammar\MynammarSrc\Mynammar.c
endif

           SRC_LIST += plutommi\Framework\LangModule\LangModuleSrc\thai.c

ifneq ($(filter __MMI_ARSHAPING_ENGINE__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += plutommi\Framework\LangModule\LangModuleSrc\arabicshapingengine.c
endif
ifneq ($(filter __MMI_LANG_VIETNAMESE__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += plutommi\Framework\LangModule\LangModuleSrc\Viet.c
endif
ifneq ($(filter __MMI_LANG_ARMENIAN__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += plutommi\Framework\LangModule\LangModuleSrc\Armenian.c
endif
ifneq ($(filter __MMI_INDIC_ALG__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += plutommi\Framework\LangModule\LangModuleSrc\Indic.c
endif
ifneq ($(filter __MMI_ARSHAPING_ENGINE__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += plutommi\Framework\LangModule\LangModuleSrc\ArabicLang.c
endif

ifeq ($(filter __MTK_TARGET__ , $(strip $(MODULE_DEFS))),)
					 SRC_LIST+= plutommi\Framework\Plugin\mmi_plugin.c  # for MoDIS plugin 
endif

# Define include path lists to INC_DIR
INC_DIR = applib\inet\engine\include \
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
          plutommi\Framework\Scenario \
          plutommi\Framework\Notification\NotificationInc \
          plutommi\Framework\GUI\gui_inc \
          plutommi\Framework\GUI\oem_inc \
          plutommi\mmi\miscframework\miscframeworkinc \
          plutommi\Framework\GDI\gdiinc \
          plutommi\service\mdi\mdiinc \
          plutommi\Service\ImgEdtSrv \
          plutommi\mtkapp\mtkappinc \
          plutommi\Framework\InputMethod\Engine\Engine_Inc \
          plutommi\Framework\InputMethod\Inc \
          plutommi\Framework\InputMethod\UI\UI_Inc \
          vendor\inputmethod\cstar\adaptation\include \
          vendor\inputmethod\t9\adaptation\include \
          btstacka\inc \
          custom\atci\include \
          custom\common \
          drm\include \
          irda\inc \
          j2me\interface \
          j2me\jal\include \
          j2me\jal\include \
          media\common\include \
          media\image\include \
          media\rtp\inc \
          media\stream\include \
          media\mtv\include \
          media\mtv\src \
          usb\include \
          verno \
          wapadp\include \
          xmlp\include \
          plutommi\CUI\Inc \
          plutommi\CUI\MenuCui \
          plutommi\CUI\InlineCui \
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
          plutommi\mmi\imps\impsinc \
          plutommi\Framework\IndicLanguages\indiclanguagesinc \
          plutommi\Framework\LangModule\LangModuleInc \
          plutommi\Framework\Languages\Khmer\KhmerInc \
          plutommi\Framework\Languages\Lao\LaoInc \
          plutommi\Framework\Languages\Mynammar\MynammarInc \
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
          plutommi\mmi\ctm\ctminc \
          plutommi\mmi\ShellApp\ShellAppInc \
          plutommi\Service\Inc \
          plutommi\Service\AppMgrSrv \
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
          plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppInc \
          plutommi\mtkapp\EngineerMode\EngineerModeEngine\EngineerModeEngineInc \
          plutommi\mtkapp\filemgr\filemgrinc \
          plutommi\mtkapp\fmradio\fmradioinc \
          plutommi\mtkapp\fmschedulerec\fmschedulerecinc \
          plutommi\mtkapp\GPS\GPSInc \
          plutommi\mtkapp\javaagency\javaagencyinc \
          plutommi\mtkapp\mmiapi\include \
          plutommi\mtkapp\mobiletvplayer\mobiletvplayerinc \
          plutommi\MtkApp\DTVPlayer\DTVPlayerInc \
          plutommi\MtkApp\MobileTVPlayer\MtvSMSInc \
          plutommi\mtkapp\myfavorite\myfavoriteinc \
          plutommi\mtkapp\photoeditor\photoeditorinc \
          plutommi\mtkapp\pictbridge\pictbridgeinc \
          plutommi\mtkapp\rightsmgr\rightsmgrinc \
          plutommi\mtkapp\soundrecorder\soundrecorderinc \
          plutommi\mtkapp\sndrec\sndrecinc \
          plutommi\mtkapp\answermachine\answermachineinc \
          plutommi\mtkapp\swflash\swflashinc \
          plutommi\mtkapp\syncml\syncmlinc \
          plutommi\mtkapp\video\videoinc \
          plutommi\mtkapp\vobjects\vobjectinc \
          plutommi\mtkapp\mreapp\mreappinc \
          plutommi\mtkapp\vrsd\vrsdinc \
          plutommi\mtkapp\vrsi\vrsiinc \
          plutommi\vendorapp\devapp\devappinc \
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
          plutommi\mmi\ipsecapp\ipsecappinc \
          plutommi\mmi\UDX\UDXInc \
          plutommi\mmi\SIMProvAgent\SIMProvAgentInc \
          venusmmi\vrt\interface \
          venusmmi\framework \
          venusmmi\framework\interface \
          venusmmi\visual \
          venusmmi\visual\interface \
          venusmmi\app\pluto_variation\adapter \
          venusmmi\app\pluto_variation\adapter\interface \
          venusmmi\app\pluto_variation\adapter\interface\res \
          venusmmi\app\pluto_variation\adapter\gui \
          venusmmi\app\pluto_variation\adapter\framework \
          venusmmi\app\pluto_variation\adapter\ime \
          venusmmi\test \
          venusmmi\app \
          venusmmi\app\pluto_variation \
          venusmmi\app\pluto_variation\LauncherKey\Home \
          plutommi\service\Inc \
          plutommi\mmi\Bootup\BootupInc \
          custom\atci\include \
          vendor\opera\browser\adaptation\inc \
          vendor\opera\browser\v1_official\opdev\include \
          plutommi\CUI\BookmarkCui \
          plutommi\MMI\CallSetting\CallSettingInc \
          plutommi\MMI\SupplementaryService\SsInc \
          venusmmi\app\pluto_variation\ShellApp\panel \
          venusmmi\app\pluto_variation\ShellApp\panel\HomeScreen \
          plutommi\Service\CharBatSrv \
          interface\hal\graphics \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel\HomeScreen \
          hal\peripheral\inc \
          ps\l4\csm\cc\include \
          plutommi\Framework\InputMethod\SDK_Layer\SDK_Inc \
          venusmmi\app\Cosmos\interface\app \
          venusmmi\app\Cosmos\interface\cui \
          venusmmi\app\common\interface\app \
          hal\peripheral\inc \
          plutommi\Service\AppMgrSrv \
          venusmmi\app\Cosmos\interface\app \
          interface\media \
          custom\common\hal_public \
          plutommi\Framework\Fontengine \
          plutommi\MMI\MiscFramework\MiscFrameworkInc \
          interface\hal\video \
          plutommi\Service\vk3Srv\inc \
          vendor\vectorfont\komoxo \
          plutommi\cui\ImageClipCui\ImageClipCuiInc \
          plutommi\mmi\npr\npr_tts\inc \
          hal\system\dcmgr\inc

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
INC_DIR += venusmmi\app\pluto_variation\adapter \
          venusmmi\app\pluto_variation\adapter\gui \
          venusmmi\app\pluto_variation\adapter\framework \
          venusmmi\app\pluto_variation\adapter\ime \
          venusmmi\app\pluto_variation\adapter\interface \
          venusmmi\app\pluto_variation\adapter\interface\res \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel\HomeScreen \
          plutommi\Service\CharBatSrv \
          venusmmi\app\Cosmos\interface\app \
          venusmmi\app\Cosmos\interface\cui \
          hal\peripheral\inc
endif

ifeq ($(strip $(CITY_EASY_OBD)),TRUE)
INC_DIR += obd\inc
endif
ifeq ($(strip $(GGT_TRACKER)),TRUE)
INC_DIR += ggt\inc
endif

ifeq ($(filter __MTK_TARGET__ , $(strip $(MODULE_DEFS))),)
INC_DIR += MoDIS_VC9\plugin\inc  # for MoDIS plugin
endif 

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
INC_DIR += venusmmi\app\Cosmos\Ucm
else
INC_DIR += plutommi\mmi\Ucm\UcmInc
endif
		
# Define the specified compile options to COMP_DEFS
COMP_DEFS = MMI_ON_HARDWARE_P  \
            __EMS__ \
            SIM_APP_TOOLKIT \
            TETRIS_GAME_APP \
            CM_APPLICATION_ENABLE \
            MESSAGES_APPLICATION \
            __UCS2_ENCODING \
            CELLBROADCAST_APP \
            __CB__ \
            VM_SUPPORT \
            SHORTCUTS_APP \
            T9LANG_English \
            T9LANG_Chinese \
            T9LANG_Spanish \
            T9LANG_French \
            T9LANG_German \
            T9LANG_Italian \
            EMS_LITTLE_ENDIAN \
            EMS_MEM_MANAGEMENT \
            T9ALPHABETIC \
            T9CHINESE \
            MMS_VIRTUAL_FILE_SUPPORT \
            COMPILER_SUPPORTS_LONG=1
 
ifeq ($(strip $(NPR_TTS_SUPPORT)),TRUE)
SRC_LIST +=   plutommi\mmi\npr\npr_tts\Src\NPR_PUB_interface.c\
		 plutommi\mmi\npr\npr_tts\Src\NPR_TTSPlayer.c\
		 plutommi\mmi\npr\npr_tts\Src\Npr_Ttsu_mainscreen.c\
		 plutommi\mmi\npr\npr_tts\Src\Npr_Tts_core_net.c\
		 plutommi\mmi\npr\npr_tts\Src\NPR_TTSPlayer_Create.c\
		 plutommi\mmi\npr\npr_tts\Src\Npr_Tts_api.c
INC_DIR += plutommi\mmi\npr\npr_tts\inc

SRC_PATH += plutommi\mmi\npr\npr_tts\Src
endif

