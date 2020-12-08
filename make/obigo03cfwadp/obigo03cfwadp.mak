# Define source file lists to SRC_LIST
SRC_LIST = vendor\framework\obigo_Q03C\adaptation\integration\source\hdi_file.c \
           vendor\framework\obigo_Q03C\adaptation\integration\source\hdi_mem.c \
           vendor\framework\obigo_Q03C\adaptation\integration\source\hdi_networkaccount.c \
           vendor\framework\obigo_Q03C\adaptation\integration\source\hdi_pipe.c \
           vendor\framework\obigo_Q03C\adaptation\integration\source\hdi_signal.c \
           vendor\framework\obigo_Q03C\adaptation\integration\source\msf_int.c \
           vendor\framework\obigo_Q03C\adaptation\integration\source\int_exec.c \
           vendor\framework\obigo_Q03C\adaptation\integration\source\int_timer.c \
           vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\refsrc\msf_xchr.c
 
ifneq ($(filter Q03C_IND_MOD_ARCH_SUPPORT, $(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\framework\obigo_Q03C\adaptation\integration\source\msf_misc.c \
            vendor\framework\obigo_Q03C\adaptation\integration\source\msm_int.c \
            vendor\framework\obigo_Q03C\adaptation\integration\source\msf_socket.c 
endif           
 
# Define include path lists to INC_DIR
INC_DIR = kal\include \
          applib\mem\include \
          vendor\mms\obigo_Q03C\adaptation\integration\include \
          vendor\mms\obigo_Q03C\adaptation\modules\mma\include \
          vendor\push\obigo_Q03C\adaptation\integration\include \
          vendor\push\obigo_Q03C\adaptation\modules\pmg\include \
          vendor\wap\obigo_Q03C\adaptation\integration\include \
          vendor\wap\obigo_Q03C\adaptation\modules\bam\include \
          vendor\wap\obigo_Q03C\adaptation\msf_ui\include \
          vendor\wap\obigo_Q03C\adaptation\msf_ui\src \
          vendor\wap\obigo_Q03C\v1_official\modules\BRS\config \
          vendor\framework\obigo_Q03C\adaptation\integration\include\trc \
          vendor\framework\obigo_Q03C\adaptation\integration\include \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\config \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\export \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\intgr \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\refsrc \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_mgr\intgr \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_mgr\refsrc \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_mgr\source \
          vendor\mms\obigo_Q03C\adaptation\modules\nts\export \
          vendor\mms\obigo_Q03C\adaptation\modules\nts\intgr \
          vendor\mms\obigo_Q03C\adaptation\modules\nts\source \
          vendor\mms\obigo_Q03C\adaptation\modules\nts\config \
          vendor\mms\obigo_Q03C\v1_official\modules\MMS\config \
          vendor\mms\obigo_Q03C\v1_official\modules\MMS\export \
          vendor\mms\obigo_Q03C\v1_official\modules\MMS\intgr \
          vendor\mms\obigo_Q03C\v1_official\modules\MMS\refsrc \
          vendor\mms\obigo_Q03C\v1_official\modules\MMS\source \
          vendor\mms\obigo_Q03C\v1_official\modules\SLS\config \
          vendor\mms\obigo_Q03C\v1_official\modules\SLS\export \
          vendor\mms\obigo_Q03C\v1_official\modules\SLS\intgr \
          vendor\mms\obigo_Q03C\v1_official\modules\SLS\source \
          vendor\wap\obigo_Q03C\v1_official\modules\BRS\config \
          vendor\wap\obigo_Q03C\v1_official\modules\BRS\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\BRS\export \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\config \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\intgr \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\export \
          vendor\stk\obigo_Q03C\v1_official\modules\SEC\config \
          vendor\stk\obigo_Q03C\v1_official\modules\SEC\intgr \
          vendor\stk\obigo_Q03C\v1_official\modules\SEC\export \
          vendor\stk\obigo_Q03C\adaptation\modules\wps\include \
          vendor\push\obigo_Q03C\v1_official\modules\PHS\config \
          vendor\push\obigo_Q03C\v1_official\modules\PHS\intgr \
          vendor\push\obigo_Q03C\v1_official\modules\PHS\export \
          vendor\push\obigo_Q03C\adaptation\modules\pmg\include \
          vendor\wap\obigo_Q03C\adaptation\modules\das\include \
          vendor\wap\obigo_Q03C\adaptation\modules\bam\include \
          Plutommi\mmi\Inc \
	    plutommi\CUI\inc \
          plutommi\Framework\Interface \
          plutommi\mmi\inc\MenuID \
          plutommi\Framework\CommonScreens\commonscreensinc \
          plutommi\Framework\CommonFiles\commoninc \
          plutommi\Framework\MemManager\MemManagerInc \
          plutommi\Framework\DebugLevels\DebugLevelInc \
          plutommi\Framework\EventHandling\EventsInc \
          plutommi\Framework\Tasks\TasksInc \
          plutommi\Framework\History\historyinc \
          plutommi\Framework\GUI\gui_Inc \
          plutommi\Framework\GUI\oem_inc \
          Plutommi\mmi\DateTime\DateTimeInc \
          Plutommi\mmi\MiscFramework\MiscFrameworkInc \
          plutommi\MMI\PROFILES\ProfilesInc \
          Plutommi\mmi \
          plutommi\mmi\Setting\SettingInc \
          plutommi\MMI\IdleScreen\IdleScreenInc \
          plutommi\MMI\ConnectManagement\ConnectManagementInc \
          plutommi\MtkApp\MtkAppInc \
          plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppInc \
          plutommi\mtkapp\EngineerMode\EngineerModeEngine\EngineerModeEngineInc \
          plutommi\MtkApp\SoundRecorder\SoundRecorderInc \
          plutommi \
          plutommi\Framework\InputMethod\inc \
          fs\fat\include \
          plutommi\mmi\FunAndGames\FunAndGamesInc \
          plutommi\customer\customerInc \
          plutommi\mmi\Profiles\ProfilesInc \
          plutommi\mmi\Audio\AudioInc \
          plutommi\Framework\GDI\GDIInc \
          plutommi\service\mdi\mdiinc \
          plutommi\MtkApp\Camera\CameraInc \
          plutommi\MtkApp\AudioPlayer\AudioPlayerInc \
          plutommi\MtkApp\FileMgr\FileMgrInc \
          plutommi\MtkApp\mmiapi\include \
          plutommi\MtkApp\CentralConfigAgent\CentralConfigAgentInc \
          plutommi\mmi\phonebook\phonebookinc \
          applib\misc\include \
          interface\hal
 
# Define the specified compile options to COMP_DEFS
COMP_DEFS = SMG_REL_97 \
            __WAP__ \
            MMI_ON_HARDWARE_P \
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
 
