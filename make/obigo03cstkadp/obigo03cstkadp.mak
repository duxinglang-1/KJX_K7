# Define source file lists to SRC_LIST
SRC_LIST = vendor\stk\obigo_Q03C\adaptation\modules\wps\src\wps_if.c \
           vendor\stk\obigo_Q03C\adaptation\modules\wps\src\wps_msg.c \
           vendor\stk\obigo_Q03C\adaptation\integration\source\wps_exec.c \
           vendor\stk\obigo_Q03C\adaptation\integration\source\sec_int.c

ifneq ($(filter WAP_SEC_SUPPORT, $(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\stk\obigo_Q03C\adaptation\modules\wps\src\wps_env.c \
            vendor\stk\obigo_Q03C\adaptation\modules\wps\src\wps_main.c
else
  ifneq ($(filter __HTTP_INTERFACE__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += vendor\stk\obigo_Q03C\adaptation\modules\wps\src\wps_env.c \
                vendor\stk\obigo_Q03C\adaptation\modules\wps\src\wps_main.c
  endif
endif

# Define include path lists to INC_DIR
INC_DIR = applib\mem\include \
          wapadp\include \
          interface\hal\graphics \
          vendor\mms\obigo_Q03C\adaptation\integration\include \
          vendor\wap\obigo_Q03C\adaptation\integration\include \
          vendor\wap\obigo_Q03C\adaptation\modules\das\include \
          vendor\stk\obigo_Q03C\adaptation\modules\wps\include \
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
          vendor\wap\obigo_Q03C\v1_official\modules\BRS\config \
          vendor\wap\obigo_Q03C\v1_official\modules\BRS\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\BRS\export \
          vendor\stk\obigo_Q03C\v1_official\modules\SEC\config \
          vendor\stk\obigo_Q03C\v1_official\modules\SEC\export \
          vendor\stk\obigo_Q03C\v1_official\modules\SEC\intgr \
          vendor\stk\obigo_Q03C\v1_official\modules\SEC\source \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\config \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\intgr \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\export \
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
          plutommi\service\mdi\mdiinc \
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
          plutommi\Cui\Inc \
          plutommi\Framework\InputMethod\Inc \
          plutommi\MMI\ConnectManagement\ConnectManagementInc \
          plutommi\Service\UPPSrv \
          plutommi\Service\Inc \
          plutommi\mmi\BrowserApp\Browser\BrowserInc \
          vendor\wap\obigo_Q03C\adaptation\modules\bam\include \
          vendor\push\obigo_Q03C\v1_official\modules\PHS\intgr \
          vendor\push\obigo_Q03C\adaptation\modules\pmg\include \
          vendor\push\obigo_Q03C\adaptation\integration\include \
          drm\include \
          vendor\opera\browser\adaptation\inc

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
INC_DIR += venusmmi\app\Cosmos\Ucm
else
INC_DIR += plutommi\mmi\Ucm\UcmInc
endif

ifneq ($(strip $(OBIGO_FEATURE)), NONE)
  ifneq ($(strip $(BROWSER_SUPPORT)), OBIGO_Q05A)
    ifeq ($(strip $(OBIGO_FEATURE)), WAP)
      INC_DIR = applib\mem\include \
          wapadp\include \
          interface\hal\graphics \
          vendor\mms\obigo_Q03C\adaptation\integration\include \
          vendor\wap\obigo_Q03C\adaptation\integration\include \
          vendor\wap\obigo_Q03C\adaptation\modules\das\include \
          vendor\stk\obigo_Q03C\adaptation\modules\wps\include \
          vendor\wap\obigo_Q03C\adaptation\msf_ui\include \
          vendor\framework\obigo_Q03C\adaptation\integration\include \
          vendor\framework\obigo_Q03C\adaptation\integration\include\trc \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\config \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\intgr \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\export \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\refsrc \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_mgr\intgr \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_mgr\refsrc \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_mgr\source \
          vendor\wap\obigo_Q03C\v1_official\modules\BRS\config \
          vendor\wap\obigo_Q03C\v1_official\modules\BRS\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\BRS\export \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\config \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\intgr \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\export \
          vendor\stk\obigo_Q03C\v1_official\modules\SEC\config \
          vendor\stk\obigo_Q03C\v1_official\modules\SEC\export \
          vendor\stk\obigo_Q03C\v1_official\modules\SEC\intgr \
          vendor\stk\obigo_Q03C\v1_official\modules\SEC\source \
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
          plutommi\service\mdi\mdiinc \
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
          plutommi\Cui\Inc \
          plutommi\Framework\InputMethod\Inc \
          plutommi\MMI\ConnectManagement\ConnectManagementInc \
          plutommi\Service\UPPSrv \
          plutommi\Service\Inc \
          plutommi\mmi\BrowserApp\Browser\BrowserInc \
          vendor\wap\obigo_Q03C\adaptation\modules\bam\include \
          vendor\push\obigo_Q03C\v1_official\modules\PHS\intgr \
          vendor\push\obigo_Q03C\adaptation\modules\pmg\include \
          vendor\push\obigo_Q03C\adaptation\integration\include \
          drm\include \
          vendor\opera\browser\adaptation\inc

	ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
		INC_DIR += venusmmi\app\Cosmos\Ucm
	else
		INC_DIR += plutommi\mmi\Ucm\UcmInc
	endif

    endif
    ifeq ($(strip $(OBIGO_FEATURE)), WAP2)
      INC_DIR = applib\mem\include \
          wapadp\include \
          interface\hal\graphics \
          vendor\mms\obigo_Q03C\adaptation\integration\include \
          vendor\wap\obigo_Q03C\adaptation\integration\include \
          vendor\wap\obigo_Q03C\adaptation\modules\das\include \
          vendor\stk\obigo_Q03C\adaptation\modules\wps\include \
          vendor\wap\obigo_Q03C\adaptation\msf_ui\include \
          vendor\framework\obigo_Q03C\adaptation\integration\include \
          vendor\framework\obigo_Q03C\adaptation\integration\include\trc \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\config \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\intgr \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\export \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\refsrc \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_mgr\intgr \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_mgr\refsrc \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_mgr\source \
          vendor\wap\obigo_Q03C\v1_official\modules\BRS\config \
          vendor\wap\obigo_Q03C\v1_official\modules\BRS\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\BRS\export \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\config \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\intgr \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\export \
          vendor\stk\obigo_Q03C\v1_official\modules\SEC\config \
          vendor\stk\obigo_Q03C\v1_official\modules\SEC\export \
          vendor\stk\obigo_Q03C\v1_official\modules\SEC\intgr \
          vendor\stk\obigo_Q03C\v1_official\modules\SEC\source \
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
          plutommi\service\mdi\mdiinc \
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
          plutommi\Cui\Inc \
          plutommi\Framework\InputMethod\Inc \
          plutommi\MMI\ConnectManagement\ConnectManagementInc \
          plutommi\mmi\BrowserApp\Browser\BrowserInc \
          vendor\wap\obigo_Q03C\adaptation\modules\bam\include \
          vendor\push\obigo_Q03C\v1_official\modules\PHS\intgr \
          vendor\push\obigo_Q03C\adaptation\modules\pmg\include \
          vendor\push\obigo_Q03C\adaptation\integration\include \
          drm\include \
          vendor\opera\browser\adaptation\inc \
          plutommi\service\inc \
          plutommi\service\UPPSrv

	ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
		INC_DIR += venusmmi\app\Cosmos\Ucm
	else
		INC_DIR += plutommi\mmi\Ucm\UcmInc
	endif

    endif
  endif
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
 
