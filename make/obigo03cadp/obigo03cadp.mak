# Define source file lists to SRC_LIST
SRC_LIST = vendor\wap\obigo_Q03C\adaptation\modules\das\src\das_env.c \
           vendor\wap\obigo_Q03C\adaptation\modules\das\src\das_main.c \
           vendor\wap\obigo_Q03C\adaptation\modules\das\src\das_msg.c \
           vendor\wap\obigo_Q03C\adaptation\modules\das\src\das_view.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\mobile_suite_app.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_action.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_dialog.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_drawing.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_editor.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_encoding.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_font.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_form.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_gadget.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_general.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_icon.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_image.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_key_handler.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_layout.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_menu.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_msg_hdr.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_paint.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_paintbox.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_paint_action.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_paint_dialog.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_paint_gadget_bar.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_paint_gadget_input.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_paint_gadget_string.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_paint_gadget_image.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_paint_menu.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_paint_editor.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_screen.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_sound.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_string.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_style.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_text.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_window.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_winsocket.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_ctk.c \
           vendor\wap\obigo_Q03C\adaptation\msf_ui\src\widget_test.c \
           vendor\wap\obigo_Q03C\adaptation\integration\source\wap_create.c \
           vendor\wap\obigo_Q03C\adaptation\integration\source\wap_mem.c \
           vendor\wap\obigo_Q03C\adaptation\integration\source\wapadp.c \
           vendor\wap\obigo_Q03C\adaptation\integration\source\wap_um.c \
           vendor\wap\obigo_Q03C\adaptation\integration\source\wap_cmn.c \
           wapadp\src\wap_cmmn_utils.c \
           vendor\wap\obigo_Q03C\adaptation\modules\bam\src\bam_cmn.c \
           vendor\wap\obigo_Q03C\adaptation\modules\bam\src\bam_do_elem.c \
           vendor\wap\obigo_Q03C\adaptation\modules\bam\src\bam_env.c \
           vendor\wap\obigo_Q03C\adaptation\modules\bam\src\bam_file.c \
           vendor\wap\obigo_Q03C\adaptation\modules\bam\src\bam_hist.c \
           vendor\wap\obigo_Q03C\adaptation\modules\bam\src\bam_if.c \
           vendor\wap\obigo_Q03C\adaptation\modules\bam\src\bam_main.c \
           vendor\wap\obigo_Q03C\adaptation\modules\bam\src\bam_msg.c \
           vendor\wap\obigo_Q03C\adaptation\modules\bam\src\bam_offline.c \
           vendor\wap\obigo_Q03C\adaptation\modules\bam\src\bam_pipe.c \
           vendor\wap\obigo_Q03C\adaptation\modules\bam\src\bam_registry.c \
           vendor\wap\obigo_Q03C\adaptation\modules\bam\src\bam_req.c \
           vendor\wap\obigo_Q03C\adaptation\modules\bam\src\bam_resource.c \
           vendor\wap\obigo_Q03C\adaptation\modules\bam\src\bam_shortcuts.c \
           vendor\wap\obigo_Q03C\adaptation\modules\bam\src\bam_sif.c \
           vendor\wap\obigo_Q03C\adaptation\modules\bam\src\bam_sig.c \
           vendor\wap\obigo_Q03C\adaptation\modules\bam\src\bam_win.c
ifneq ($(filter OBIGO_Q03C_MMS_V01 , $(strip $(MODULE_DEFS))),)            
SRC_LIST += vendor\wap\obigo_Q03C\adaptation\modules\mmc\intgr\mmc_env.c \
           vendor\wap\obigo_Q03C\adaptation\modules\mmc\source\mmc_jsr.c \
           vendor\wap\obigo_Q03C\adaptation\modules\mma\intgr\mma_env.c \
           vendor\wap\obigo_Q03C\adaptation\modules\mma\source\mma_conf.c \
           vendor\wap\obigo_Q03C\adaptation\modules\mma\source\mma_if_wrapper.c \
           vendor\wap\obigo_Q03C\adaptation\modules\mma\source\mma_intsig.c \
           vendor\wap\obigo_Q03C\adaptation\modules\mma\source\mma_main.c \
           vendor\wap\obigo_Q03C\adaptation\modules\mma\source\mma_rpl.c \
           vendor\wap\obigo_Q03C\adaptation\modules\mma\source\mma_send.c \
           vendor\wap\obigo_Q03C\adaptation\modules\mma\source\mma_utils.c \
           vendor\wap\obigo_Q03C\adaptation\modules\mma\source\mma_utils_xml.c \
           vendor\wap\obigo_Q03C\adaptation\modules\mma\source\mma_um.c \
           vendor\wap\obigo_Q03C\adaptation\modules\slim_mma\intgr\slim_mma_env.c \
           vendor\wap\obigo_Q03C\adaptation\modules\slim_mma\source\slim_mma_intsig.c \
           vendor\wap\obigo_Q03C\adaptation\modules\slim_mma\source\slim_mma_main.c \
           vendor\wap\obigo_Q03C\adaptation\modules\slim_mma\source\slim_mma_rpl.c \
           vendor\wap\obigo_Q03C\adaptation\modules\slim_mma\source\slim_mma_send.c \
           vendor\wap\obigo_Q03C\adaptation\modules\slim_mma\source\slim_mma_utils.c \
           vendor\wap\obigo_Q03C\adaptation\modules\slim_mma\source\slim_mma_utils_xml.c 
endif           
ifneq ($(filter Q03C_IND_MOD_ARCH_SUPPORT, $(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\wap\obigo_Q03C\adaptation\integration\source\msf_file.c \
            vendor\wap\obigo_Q03C\adaptation\integration\source\msf_int.c \
            vendor\wap\obigo_Q03C\adaptation\integration\source\msf_nw_acc.c \
            vendor\wap\obigo_Q03C\adaptation\integration\source\msf_pipe.c \
            vendor\wap\obigo_Q03C\adaptation\integration\source\msm_int.c \
            vendor\wap\obigo_Q03C\adaptation\integration\source\msf_misc.c \
            vendor\wap\obigo_Q03C\adaptation\integration\source\msf_socket.c \
            vendor\wap\obigo_Q03C\adaptation\integration\source\msf_signal.c
endif
 
# Define include path lists to INC_DIR
INC_DIR = applib\mem\include \
          wapadp\include \
          vendor\wap\obigo_Q03C\adaptation\integration\include \
          vendor\wap\obigo_Q03C\adaptation\modules\das\include \
          vendor\stk\obigo_Q03C\adaptation\modules\wps\include \
          vendor\wap\obigo_Q03C\adaptation\modules\mmc\intgr \
          vendor\wap\obigo_Q03C\adaptation\modules\mmc\source \
          vendor\wap\obigo_Q03C\adaptation\modules\mma\include \
          vendor\wap\obigo_Q03C\adaptation\modules\mma\intgr \
          vendor\wap\obigo_Q03C\adaptation\modules\mma\source \
          vendor\wap\obigo_Q03C\adaptation\modules\mma\export \
          vendor\wap\obigo_Q03C\adaptation\modules\slim_mma\include \
          vendor\wap\obigo_Q03C\adaptation\modules\slim_mma\intgr \
          vendor\wap\obigo_Q03C\adaptation\modules\slim_mma\source \
          vendor\wap\obigo_Q03C\v1_official\modules\MEA\config \
          vendor\wap\obigo_Q03C\v1_official\modules\MEA\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\MEA\source \
          vendor\wap\obigo_Q03C\v1_official\modules\MEA\export \
          vendor\wap\obigo_Q03C\v1_official\modules\MMS\config \
          vendor\wap\obigo_Q03C\v1_official\modules\MMS\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\MMS\export \
          vendor\wap\obigo_Q03C\v1_official\modules\MMS\source \
          vendor\wap\obigo_Q03C\v1_official\modules\MMS\refsrc \
          vendor\wap\obigo_Q03C\v1_official\modules\SLS\config \
          vendor\wap\obigo_Q03C\v1_official\modules\SLS\export \
          vendor\wap\obigo_Q03C\v1_official\modules\SLS\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\SLS\source \
          vendor\wap\obigo_Q03C\v1_official\modules\SMA\config \
          vendor\wap\obigo_Q03C\v1_official\modules\SMA\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\SMA\export \
          vendor\wap\obigo_Q03C\adaptation\msf_ui\include \
          vendor\framework\obigo_Q03C\adaptation\integration\include\trc \
          vendor\framework\obigo_Q03C\adaptation\integration\include \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\config \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\intgr \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\export \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\refsrc \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_mgr\intgr \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_mgr\refsrc \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_mgr\source \
          vendor\wap\obigo_Q03C\v1_official\modules\BRA\config \
          vendor\wap\obigo_Q03C\v1_official\modules\BRA\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\BRA\source \
          vendor\wap\obigo_Q03C\v1_official\modules\BRA\refsrc \
          vendor\wap\obigo_Q03C\v1_official\modules\BRA\export \
          vendor\wap\obigo_Q03C\v1_official\modules\BRS\config \
          vendor\wap\obigo_Q03C\v1_official\modules\BRS\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\BRS\export \
          vendor\wap\obigo_Q03C\v1_official\modules\BRS\source \
          vendor\wap\obigo_Q03C\v1_official\modules\BRS\refsrc \
          vendor\wap\obigo_Q03C\v1_official\modules\IBS\config \
          vendor\wap\obigo_Q03C\v1_official\modules\IBS\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\JAS\config \
          vendor\wap\obigo_Q03C\v1_official\modules\JAS\intgr \
          vendor\stk\obigo_Q03C\v1_official\modules\SEC\config \
          vendor\stk\obigo_Q03C\v1_official\modules\SEC\export \
          vendor\stk\obigo_Q03C\v1_official\modules\SEC\intgr \
          vendor\stk\obigo_Q03C\v1_official\modules\SEC\source \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\config \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\intgr \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\export \
          vendor\wap\obigo_Q03C\v1_official\modules\UIA\config \
          vendor\wap\obigo_Q03C\v1_official\modules\UIA\intgr \
          applib\misc\include \
          Plutommi\mmi\Inc \
          plutommi\Framework\Interface \
          plutommi\mmi\inc\MenuID \
          plutommi\Framework\CommonScreens\commonscreensinc \
          plutommi\Framework\CommonFiles\CommonInc \
          plutommi\Framework\NVRAMManager\NVRAMManagerInc \
          plutommi\Framework\ThemeManager\ThemeManagerInc \
          plutommi\Framework\DebugLevels\DebugLevelInc \
          plutommi\Framework\EventHandling\EventsInc \
          plutommi\Framework\Tasks\TasksInc \
          plutommi\Framework\History\historyinc \
          plutommi\Framework\MemManager\MemManagerInc \
          plutommi\Framework\GUI\gui_Inc \
          plutommi\Framework\GUI\oem_inc \
          Plutommi\mmi\DateTime\DateTimeInc \
          Plutommi\mmi\MiscFramework\MiscFrameworkInc \
          plutommi\mmi\PROFILES\ProfilesInc \
          plutommi\mmi\phonebook\phonebookinc \
          plutommi\mmi\organizer\organizerInc \
          plutommi\Framework\NVRAMManager\NVRAMManagerInc \
          plutommi\mmi\gpio\gpioInc \
          plutommi\mmi\GSMCallApplication\CommonFiles\CommonInc \
          plutommi\mmi\GSMCallApplication\outgoingcallmanagement\outgoinginc \
          plutommi\mmi\GSMCallApplication\incomingcallmanagement\incominginc \
          plutommi\mmi\messages\messagesInc \
          plutommi\MMI\Setting\SettingInc \
          Plutommi\mmi \
          plutommi\MMI\IdleScreen\IdleScreenInc \
          plutommi\MMI\Idle\IdleInc \
          plutommi\MMI\ScrLocker\ScrLockerInc \
          plutommi\MMI\ScrSaver\ScrSaverInc \
          plutommi\MtkApp\MtkAppInc \
          plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppInc \
          plutommi\mtkapp\EngineerMode\EngineerModeEngine\EngineerModeEngineInc \
          plutommi\MtkApp\SoundRecorder\SoundRecorderInc \
          plutommi\mmi\FunAndGames\FunAndGamesInc \
          plutommi\Framework\ThemeManager\ThemeManagerInc \
          plutommi\mmi\audio\audioinc \
          plutommi\mmi\sat\satInc \
          plutommi\customer\customerInc \
          plutommi\Framework\GDI\GDIInc \
          plutommi\service\MDI\MDIInc \
          plutommi\MtkApp\Camera\CameraInc \
          plutommi\MtkApp\AudioPlayer\AudioPlayerInc \
          plutommi\MtkApp\FileMgr\FileMgrInc \
          plutommi\MtkApp\mmiapi\include \
          fmt\include \
          plutommi\MtkApp\JavaAgency\JavaAgencyInc \
          drm\include \
          j2me\interface \
          j2me\jal\include \
          plutommi\MMI\UnifiedMessage\UnifiedMessageInc \
          applib\misc\include \
          applib\mem\include \
          plutommi\MtkApp\Connectivity\ConnectivityInc \
          plutommi\MMI\UnifiedComposer\UnifiedComposerInc \
          xmlp\include \
          interface\fs \
          plutommi\MtkApp\CentralConfigAgent\CentralConfigAgentInc \
          plutommi\mmi\DataAccount\DataAccountInc \
          plutommi\Service\Inc \
          plutommi\Service\UmSrv \
          plutommi\Service\UPPSrv \
          plutommi\Cui\Inc \
          plutommi\Framework\InputMethod\Inc \
          venusmmi\app\Cosmos\Browser \
          venusmmi\app\Cosmos\interface\app \
          plutommi\MMI\ConnectManagement\ConnectManagementInc \
          plutommi\mmi\BrowserApp\Browser\BrowserInc \
          plutommi\service\UPPSrv \
          plutommi\service\inc \
          vendor\wap\obigo_Q03C\adaptation\modules\bam\include \
          vendor\push\obigo_Q03C\v1_official\modules\PHS\intgr \
          vendor\push\obigo_Q03C\adaptation\modules\pmg\include \
          vendor\push\obigo_Q03C\adaptation\integration\include \
          drm\include \
          vendor\mms\obigo_Q03C\adaptation\integration\include \
          interface\hal

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
INC_DIR += venusmmi\app\Cosmos\Ucm
else
INC_DIR += plutommi\mmi\Ucm\UcmInc
endif
 
# Define the specified compile options to COMP_DEFS
COMP_DEFS = MMI_ON_HARDWARE_P \
            __WAP__ \
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
            MTK_TMP_PATCH
 
ifneq ($(filter OBIGO_Q03C_MMS_V01 , $(strip $(MODULE_DEFS))),)                      
endif 
