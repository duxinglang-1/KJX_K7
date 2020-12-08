# Define source file lists to SRC_LIST
SRC_LIST = j2me\jal\jam\jam_create.c \
           j2me\jal\jam\jam_custom.c \
           j2me\jal\jam\jam_java_native_msg_handler.c \
           j2me\jal\jam\jam_list.c \
           j2me\jal\jam\jam_msg_handler.c \
           j2me\jal\jam\jam_msg_util.c \
           j2me\jal\jam\jam_platform_request.c \
           j2me\jal\jam\jam_drm.c \
           j2me\jal\jam\jam_ca.c \
           j2me\jal\jam\jam_msg_process.c \
           j2me\jal\jam\jam_screen_switch.c \
           j2me\jal\jam\jam_mvm_manager.c \
           j2me\jal\jma\jma_audio_player.c \
           j2me\jal\jma\jma_audio_recorder.c \
           j2me\jal\jma\jma_video_player.c \
           j2me\jal\jma\jma_media_resource.c \
           j2me\jal\jam\jam_performance.c \
           j2me\jal\jvm\jvm_cache.c \
           j2me\jal\jvm\jvm_runtime.c \
           j2me\jal\jvm\jvm_file.c \
           j2me\jal\jvm\jvm_mem.c \
           j2me\jal\jvm\jvm_error.c \
           j2me\jal\jvm\jvm_event_adaptor.c \
           j2me\jal\jvm\jvm_device.c \
           j2me\jal\jvm\jvm_global_setting_util.c \
           j2me\jal\jvm\jvm_vcomm.c \
           j2me\jal\jvm\jvm_io.c \
           j2me\jal\jvm\jvm_resource.c \
           j2me\jal\jvm\jvm_util.c \
           j2me\jal\jvm\jvm_debug.c \
           j2me\jal\jui\jui_widget.c \
           j2me\jal\jui\jui_editor.c \
           j2me\jal\jui\jui_util.c \
           j2me\jal\jpim\jpim_phonebook.c \
           j2me\jal\jpim\jpim_eventDB.c \
           j2me\jal\jnw\jnw_socket.c \
           j2me\jal\jnw\jnw_datagram.c \
           j2me\jal\jnw\jnw_http.c \
           j2me\jal\jnw\jnw_stream.c \
           j2me\jal\jnw\jnw_ssl.c \
           j2me\jal\jwa\jwa_sms.c \
           j2me\jal\jwa\jwa_mms.c \
           j2me\jal\jpush\jpush_general.c \
           j2me\jal\jpush\jpush_timealarm.c \
           j2me\jal\jlbs\jlbs_gps.c \
           j2me\jal\jbt\jbt_main.c \
           j2me\jal\jbt\jbt_gap.c \
           j2me\jal\jbt\jbt_bcc.c \
           j2me\jal\jbt\jbt_ut.c \
           j2me\jal\jbt\jbt_sdpdb.c \
           j2me\jal\jbt\jbt_sdap.c \
           j2me\jal\jbt\jbt_cmdhdl.c \
           j2me\jal\jbt\jbt_spp.c \
           j2me\jal\jbt\jbt_l2cap.c \
           j2me\jal\jbt\jbt_session.c \
           j2me\jal\jbt\jbt_ringbuf.c \
           j2me\jal\jsec\jsec_pki.c
           
SRC_LIST += j2me\jal\jma\jma_animation_player.c \
            j2me\jal\jma\jma_cam_player.c \
            j2me\jal\jma\jma_video_recorder.c 
           
ifneq ($(filter __NEMO_VM__,$(strip $(MODULE_DEFS))),)
SRC_LIST += j2me\jal\jcc\jcc_nfc.c \
            j2me\jal\jsatsa\jsatsa_apdu.c
endif

ifneq ($(filter __MVM__,$(strip $(MODULE_DEFS))),)
SRC_LIST += j2me\jal\jvm\jvm_event.c \
           j2me\jal\jvm\jvm_trace.c \
           j2me\jal\jvm\jvm_base64.c \
           j2me\jal\jvm\jvm_date_time.c \
           j2me\jal\jvm\jvm_resource_manager.c \
           j2me\jal\jui\jui_virtual_keypad.c 
endif
#  Define include path lists to INC_DIR
INC_DIR = applib\misc\include \
          plutommi\mmi\Organizer\OrganizerInc \
          plutommi\customer\customerinc \
          Plutommi\mmi\Inc \
          plutommi\Framework\Interface \
          plutommi\mmi\inc\MenuID \
          plutommi\Framework\CommonScreens\commonscreensinc \
          plutommi\Framework\DebugLevels\DebugLevelInc \
          plutommi\Framework\CommonFiles\commoninc \
          plutommi\Framework\EventHandling\EventsInc \
          plutommi\Framework\Tasks\TasksInc \
          plutommi\Framework\History\historyinc \
          plutommi\Framework\MemManager\MemManagerInc \
          plutommi\Framework\GUI\gui_Inc \
          plutommi\Framework\GUI\oem_inc \
          plutommi\mmi\FunAndGames\FunAndGamesInc \
          Plutommi\mmi\Audio\AudioInc \
          Plutommi\mmi\Profiles\ProfilesInc \
          Plutommi\mmi\gpio\gpioInc \
          Plutommi\mmi\DateTime\DateTimeInc \
          Plutommi\mmi\MiscFramework\MiscFrameworkInc \
          Plutommi\mmi\phonebook\phonebookinc \
          Plutommi\mmi \
          plutommi\MMI\IdleScreen\IdleScreenInc \
          plutommi\mmi\idle\idleinc \
          plutommi\mmi\GSMCallApplication\CommonFiles\CommonInc \
          plutommi\mmi\GSMCallApplication\incomingcallmanagement\incominginc \
          plutommi\MtkApp\MtkAppInc \
          inet_ps\tcpip\include \
          plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppInc \
          plutommi\mtkapp\EngineerMode\EngineerModeEngine\EngineerModeEngineInc \
          plutommi\MtkApp\SoundRecorder\SoundRecorderInc \
          plutommi\MtkApp\Camera\CameraInc \
          plutommi\MtkApp\AudioPlayer\AudioPlayerInc \
          plutommi\mtkapp\MediaPlayer\MediaPlayerInc \
          plutommi\Framework\GDI\gdiinc \
          plutommi\MtkApp\FileMgr\FileMgrInc \
          $(strip $(PS_FOLDER))\interfaces\local_inc \
          plutommi\MtkApp\mmiapi\include \
          interface\ps \
          $(strip $(PS_FOLDER))\interfaces\local_inc \
          wapadp\include \
          vendor\wap\obigo_Q03C\v1_official\modules\bra\source \
          vendor\wap\obigo_Q03C\v1_official\modules\mms\config \
          vendor\wap\obigo_Q03C\v1_official\msf\msf_lib\intgr \
          vendor\wap\obigo_Q03C\adaptation\modules\mmc\intgr \
          plutommi\service\MDI\MDIInc \
          plutommi\MtkApp\Video\VideoInc \
          plutommi\MMI\Setting\SettingInc \
          plutommi\MtkApp\JavaAgency\JavaAgencyInc \
          plutommi\mmi\ConnectManagement\ConnectManagementInc \
          j2me\jal\include \
          j2me\interface \
          applib\mem\include \
          plutommi\MtkApp\Connectivity\ConnectivityInc\BtCommon \
          plutommi\MtkApp\Connectivity\ConnectivityInc\BtMtk \
          vendor\wap\obigo_Q05A\v1_official\msf\msf_lib\intgr \
          vendor\wap\obigo_Q05A\v1_official\modules\mms\config \
          plutommi\MtkApp\Connectivity\ConnectivityInc \
          plutommi\Framework\InputMethod\Inc \
          btstacka\inc \
          btadp\include \
          interface\mmi \
          interface\wap \
          plutommi\Service\Inc \
          interface\security \
          plutommi\MtkApp\MobileTVPlayer\MobileTVPlayerInc \
          plutommi\MMI\DataAccount\DataAccountInc \
          plutommi\mmi\BrowserApp\Browser\BrowserInc \
          vendor\wap\obigo_q03c\adaptation\integration\include \
          plutommi\CUI\Inc \
          j2me\vm\NEMO\adaptation\include \
          plutommi\mtkapp\dmuiapp\dmuiappinc \
          plutommi\service\appmgrsrv \
          hal\peripheral\inc \
          venusmmi\app\Cosmos\JavaApp \
          venusmmi\app\Cosmos\interface\app \
          venusmmi\app\common\interface\app \
          venusmmi\vrt\interface \
          vcard\include \
          ps\l4\csm\cc\include \
          venusmmi\app\Cosmos\Calendar \
          plutommi\MtkApp\GPS\GPSInc\
          plutommi\Service\JavaAppFactorySrv
          
ifneq ($(filter SUPPORT_JSR_257,$(strip $(MODULE_DEFS))),)
INC_DIR += interface\nfc \
           nfc\inc \
           nfc\nxp\fri\inc \
           nfc\nxp\osal\inc \
           nfc\nxp\dal\inc
endif
ifneq ($(filter __IJET_VM__,$(strip $(MODULE_DEFS))),)
INC_DIR += j2me\vm\IJET\adaptation\include 
endif
ifneq ($(filter __NEMO_VM__,$(strip $(MODULE_DEFS))),)
INC_DIR += j2me\vm\NEMO\adaptation\include 
endif

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
INC_DIR += venusmmi\app\Cosmos\Ucm
else
INC_DIR += plutommi\mmi\Ucm\UcmInc
endif
 
# Define the specified compile options to COMP_DEFS
COMP_DEFS = MMI_ON_HARDWARE_P \
            MTK_SIMU=0 \
            USE_JAM=0 \
            __UCS2_ENCODING \
            SOFTBUTTON_INVERSE \
            USING_SIMPLEFILESYSTEM=0 \
            STACKOVERDUMMYSIZE=18 \
            INCLUDEDEBUG=0 \
            PADTABLE=1 \
            GENERIC_IO_WAIT_TIME=100 \
            MMI_KEYEVENT=1 \
            HITRATETEST=0 \
            COMPILER_SUPPORTS_DIR=0 \
            ONLY_FOR_TESTING_THE_ABOVE_CODE=0 \
            NO_SIGNAL_HANDLER=1 \
            CACHE_VERIFICATION_RESULT=0 \
            UNSUPPORTED_SYSTEM_PNG_FILES=1 \
            COMPILER_SUPPORTS_HANDLE_FILES=1 \
            UNSUPPORTED_SYSTEM_CONF_FILES=1 \
            COMPILER_SUPPORTS_LONG=1

ifeq ($(filter __MTK_TARGET__,$(strip $(MODULE_DEFS))),)
  COMP_DEFS += AJ_PLATFORM_WIN32
  MODIS_DIS_OPTION += AJ_PLATFORM_ARM
endif

          
ifneq ($(filter __NEMO_VM__,$(strip $(MODULE_DEFS))),)
endif
