# Define source file lists to SRC_LIST
SRC_LIST = vendor\push\obigo_Q03C\adaptation\modules\pmg\src\pmg_env.c \
           vendor\push\obigo_Q03C\adaptation\modules\pmg\src\pmg_if.c \
           vendor\push\obigo_Q03C\adaptation\modules\pmg\src\pmg_main.c \
           vendor\push\obigo_Q03C\adaptation\modules\pmg\src\pmg_inbox.c \
           vendor\push\obigo_Q03C\adaptation\modules\pmg\src\pmg_phs.c \
           vendor\push\obigo_Q03C\adaptation\modules\pmg\src\pmg_fs.c \
           vendor\push\obigo_Q03C\adaptation\modules\pmg\src\pmg_um.c \
           vendor\push\obigo_Q03C\adaptation\modules\pmg\src\pmg_msg.c \
           vendor\push\obigo_Q03C\adaptation\modules\pmg\src\pmg_dl.c \
           vendor\push\obigo_Q03C\v1_official\modules\PHS\refsrc\phs_dlg.c \
           vendor\push\obigo_Q03C\v1_official\modules\PHS\refsrc\phs_umdb.c
 
# Define include path lists to INC_DIR
ifeq ($(strip $(BROWSER_SUPPORT)),OBIGO_Q05A)
INC_DIR = applib\mem\include \
          wapadp\include \
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
          plutommi\Framework\InputMethod\Inc \
          plutommi\MMI\ConnectManagement\ConnectManagementInc \
          plutommi\mmi\BrowserApp\Browser\BrowserInc \
          plutommi\mmi\BrowserApp\PushInbox\PushInboxInc \
          vendor\framework\obigo_Q03C\adaptation\integration\include\trc \
          vendor\push\obigo_Q03C\v1_official\modules\PHS\config \
          vendor\push\obigo_Q03C\v1_official\modules\PHS\export \
          vendor\push\obigo_Q03C\v1_official\modules\PHS\intgr \
          vendor\push\obigo_Q03C\v1_official\modules\PHS\refsrc \
          vendor\push\obigo_Q03C\v1_official\modules\PHS\source \
          interface\ps \
          interface\wap \
          plutommi\mtkapp\DLAgent\DLAgentInc \
          vendor\push\obigo_Q03C\adaptation\modules\pmg\include \
          kal\include \
          vendor\push\obigo_Q03C\adaptation\integration\include \
          vendor\wap\obigo_Q05A\v1_official\modules\core\stack\stk\export \
          vendor\wap\obigo_Q05A\v1_official\msf\msf_lib\intgr \
          vendor\wap\obigo_Q05A\adaptation\integration\include \
          vendor\wap\obigo_Q05A\v1_official\msf\msf_lib\export\parser \
          vendor\wap\obigo_Q05A\v1_official\msf\msf_lib\config \
          vendor\wap\obigo_Q05A\v1_official\msf\msf_lib\export \
          vendor\wap\obigo_Q05A\v1_official\msf\msf_lib\export\ui_comp \
          vendor\wap\obigo_Q05A\v1_official\msf\msf_lib\refsrc \
          vendor\wap\obigo_Q05A\v1_official\msf\msf_lib\refsrc\ui_comp \
          vendor\wap\obigo_Q05A\v1_official\msf\msf_lib\refsrc\ui_comp\internal \
          vendor\wap\obigo_Q05A\v1_official\msf\msf_mgr\refsrc \
          vendor\wap\obigo_Q05A\v1_official\msf\msf_mgr\source \
          vendor\wap\obigo_Q05A\v1_official\msf\msf_mgr\intgr \
          custom\common custom\common\hal custom\common\ps \
          plutommi\CUI\inc \
          plutommi\Service\Inc \
          plutommi\Service\UPPSrv

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
    INC_DIR += venusmmi\app\Cosmos\Ucm
else
    INC_DIR += plutommi\mmi\Ucm\UcmInc
endif
endif

ifneq ($(strip $(OBIGO_FEATURE)), NONE)
  ifneq ($(strip $(BROWSER_SUPPORT)), OBIGO_Q05A)
  INC_DIR = applib\mem\include \
          wapadp\include \
          vendor\wap\obigo_Q03C\adaptation\integration\include \
          vendor\wap\obigo_Q03C\adaptation\modules\das\include \
          vendor\wap\obigo_Q03C\adaptation\modules\mmc\intgr \
          vendor\wap\obigo_Q03C\adaptation\modules\mmc\source \
          vendor\wap\obigo_Q03C\adaptation\modules\mma\include \
          vendor\wap\obigo_Q03C\adaptation\modules\mma\intgr \
          vendor\wap\obigo_Q03C\adaptation\modules\mma\source \
          vendor\wap\obigo_Q03C\adaptation\modules\mma\export \
          vendor\wap\obigo_Q03C\adaptation\msf_ui\include \
          vendor\framework\obigo_Q03C\adaptation\integration\include\trc \
          vendor\framework\obigo_Q03C\adaptation\integration\include \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\config \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\intgr \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\export \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\refsrc \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_mgr\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\BRA\config \
          vendor\wap\obigo_Q03C\v1_official\modules\BRA\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\BRA\source \
          vendor\wap\obigo_Q03C\v1_official\modules\BRA\refsrc \
          vendor\wap\obigo_Q03C\v1_official\modules\BRA\export \
          vendor\wap\obigo_Q03C\v1_official\modules\BRS\config \
          vendor\wap\obigo_Q03C\v1_official\modules\BRS\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\BRS\export \
          vendor\wap\obigo_Q03C\v1_official\modules\IBS\config \
          vendor\wap\obigo_Q03C\v1_official\modules\IBS\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\JAS\config \
          vendor\wap\obigo_Q03C\v1_official\modules\JAS\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\MEA\config \
          vendor\wap\obigo_Q03C\v1_official\modules\MEA\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\MEA\source \
          vendor\wap\obigo_Q03C\v1_official\modules\MEA\export \
          vendor\wap\obigo_Q03C\v1_official\modules\MMS\config \
          vendor\wap\obigo_Q03C\v1_official\modules\MMS\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\MMS\export \
          vendor\wap\obigo_Q03C\v1_official\modules\MMS\source \
          vendor\wap\obigo_Q03C\v1_official\modules\MMS\refsrc \
          vendor\stk\obigo_Q03C\v1_official\modules\SEC\config \
          vendor\stk\obigo_Q03C\v1_official\modules\SEC\export \
          vendor\stk\obigo_Q03C\v1_official\modules\SEC\intgr \
          vendor\stk\obigo_Q03C\v1_official\modules\SEC\source \
          vendor\wap\obigo_Q03C\v1_official\modules\SLS\config \
          vendor\wap\obigo_Q03C\v1_official\modules\SLS\export \
          vendor\wap\obigo_Q03C\v1_official\modules\SLS\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\SLS\source \
          vendor\wap\obigo_Q03C\v1_official\modules\SMA\config \
          vendor\wap\obigo_Q03C\v1_official\modules\SMA\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\SMA\export \
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
          plutommi\MtkApp\MtkAppInc \
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
          plutommi\Framework\InputMethod\Inc \
          plutommi\MMI\ConnectManagement\ConnectManagementInc \
          plutommi\mmi\BrowserApp\Browser\BrowserInc \
          plutommi\mmi\BrowserApp\PushInbox\PushInboxInc \
          vendor\push\obigo_Q03C\v1_official\modules\PHS\config \
          vendor\push\obigo_Q03C\v1_official\modules\PHS\export \
          vendor\push\obigo_Q03C\v1_official\modules\PHS\intgr \
          vendor\push\obigo_Q03C\v1_official\modules\PHS\refsrc \
          vendor\push\obigo_Q03C\v1_official\modules\PHS\source \
          interface\ps \
          interface\wap \
          plutommi\mtkapp\DLAgent\DLAgentInc \
          vendor\push\obigo_Q03C\adaptation\modules\pmg\include \
          kal\include \
          vendor\push\obigo_Q03C\adaptation\integration\include \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\export \
          vendor\mms\obigo_Q03C\adaptation\integration\include \
          plutommi\CUI\inc \
          plutommi\service\inc \
          plutommi\service\UPPSrv

    ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
    	INC_DIR += venusmmi\app\Cosmos\Ucm
	else
		INC_DIR += plutommi\mmi\Ucm\UcmInc
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
 
 
