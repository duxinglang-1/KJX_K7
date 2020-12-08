# Define source file lists to SRC_LIST

SRC_LIST = vendor\mms\obigo_Q03C\adaptation\integration\source\mms_exec.c \
           vendor\mms\obigo_Q03C\v1_official\modules\MMS\refsrc\mms_a.c \
           vendor\mms\obigo_Q03C\v1_official\modules\MMS\refsrc\mms_aApp.c \
           vendor\mms\obigo_Q03C\adaptation\modules\mma\src\mma_create.c \
           vendor\mms\obigo_Q03C\adaptation\modules\mma\src\mma_env.c \
           vendor\mms\obigo_Q03C\adaptation\modules\mma\src\mma_event.c \
           vendor\mms\obigo_Q03C\adaptation\modules\mma\src\mma_interface.c \
           vendor\mms\obigo_Q03C\adaptation\modules\mma\src\mma_main.c \
           vendor\mms\obigo_Q03C\adaptation\modules\mma\src\mma_mime.c \
           vendor\mms\obigo_Q03C\adaptation\modules\mma\src\mma_msgmgr.c \
           vendor\mms\obigo_Q03C\adaptation\modules\mma\src\mma_msg_struct.c \
           vendor\mms\obigo_Q03C\adaptation\modules\mma\src\mma_parse.c \
            vendor\mms\obigo_Q03C\adaptation\modules\mma\src\mma_smil.c \
           vendor\mms\obigo_Q03C\adaptation\modules\mma\src\mma_sendrecv.c \
           vendor\mms\obigo_Q03C\adaptation\modules\mma\src\mma_setting.c \
           vendor\mms\obigo_Q03C\adaptation\modules\mma\src\mma_um.c \
           vendor\mms\obigo_Q03C\adaptation\modules\mma\src\mma_utilities.c \
           vendor\mms\obigo_Q03C\adaptation\modules\mma\src\mma_xml.c \
	   vendor\mms\obigo_Q03C\adaptation\modules\mma\src\mma_drmsrv.c 
           

ifeq ($(filter Q03C_IND_MOD_ARCH_SUPPORT, $(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\mms\obigo_Q03C\adaptation\modules\nts\export\nts_if.c \
           vendor\mms\obigo_Q03C\adaptation\modules\nts\intgr\nts_env.c \
           vendor\mms\obigo_Q03C\adaptation\modules\nts\source\nts_main.c \
           vendor\mms\obigo_Q03C\adaptation\modules\nts\source\nts_channel.c \
           vendor\mms\obigo_Q03C\adaptation\modules\nts\source\nts_transaction.c \
           vendor\mms\obigo_Q03C\adaptation\modules\nts\source\nts_stack.c \
           vendor\mms\obigo_Q03C\adaptation\modules\nts\source\nts_util.c \
           vendor\mms\obigo_Q03C\adaptation\modules\nts\source\nts_sig.c
endif

# Define include path lists to INC_DIR

INC_DIR = vendor\mms\obigo_Q03C\adaptation\integration\include \
          vendor\mms\obigo_Q03C\adaptation\modules\mma\include \
          vendor\framework\obigo_Q03C\adaptation\integration\include\trc \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\config \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\intgr \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\export \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\refsrc \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_mgr\intgr \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_mgr\source \
          vendor\framework\obigo_Q03C\adaptation\integration\include \
          vendor\mms\obigo_Q03C\v1_official\modules\MMS\config \
          vendor\mms\obigo_Q03C\v1_official\modules\MMS\intgr \
          vendor\mms\obigo_Q03C\v1_official\modules\MMS\export \
          vendor\mms\obigo_Q03C\v1_official\modules\MMS\source \
          vendor\mms\obigo_Q03C\v1_official\modules\MMS\refsrc \
          vendor\push\obigo_Q03C\adaptation\integration\include \
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
          plutommi\Framework\InputMethod\Inc \
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
          plutommi\Service\UcSrv \
          plutommi\Service\UmSrv \
          plutommi\MMI\UnifiedComposer\UnifiedComposerInc \
          xmlp\include \
          interface\fs \
          kal\include \
          plutommi\MtkApp\CentralConfigAgent\CentralConfigAgentInc \
          plutommi\mmi\DataAccount\DataAccountInc \
          plutommi\Service\Inc \
          plutommi\MMI\ConnectManagement\ConnectManagementInc \
          custom\common custom\common\hal custom\common\ps \
          plutommi\mmi\UnifiedMMS\MMSApp\MMSAppInc \
          plutommi\Service\UmmsSrv \
          plutommi\mtkapp\vObjects\vObjectInc \
          plutommi\CUI\inc \
          vcard\include \
          vendor\wap\obigo_Q03C\adaptation\integration\include \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\config \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\export \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\intgr \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\refsrc \
          vendor\mms\obigo_Q03C\adaptation\modules\nts\export \
          vendor\mms\obigo_Q03C\adaptation\modules\nts\intgr \
          vendor\mms\obigo_Q03C\adaptation\modules\nts\source \
          vendor\mms\obigo_Q03C\adaptation\modules\nts\config

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



ifeq ($(filter Q03C_IND_MOD_ARCH_SUPPORT, $(strip $(MODULE_DEFS))),)
endif
