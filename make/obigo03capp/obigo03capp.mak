# Define source file lists to SRC_LIST
SRC_LIST = vendor\wap\obigo_Q03C\v1_official\modules\BRS\refsrc\brs_char.c \
           vendor\wap\obigo_Q03C\v1_official\modules\BRS\refsrc\brs_dlg.c \
           vendor\wap\obigo_Q03C\v1_official\modules\BRS\refsrc\brs_plab.c \
           vendor\wap\obigo_Q03C\v1_official\modules\BRS\refsrc\brs_pldata.c \
           vendor\wap\obigo_Q03C\v1_official\modules\BRS\refsrc\brs_plege.c \
           vendor\wap\obigo_Q03C\v1_official\modules\BRS\refsrc\brs_plg.c \
           vendor\wap\obigo_Q03C\v1_official\modules\BRS\refsrc\brs_plrtsp.c \
           vendor\wap\obigo_Q03C\v1_official\modules\BRS\refsrc\brs_plsms.c \
           vendor\wap\obigo_Q03C\v1_official\modules\BRS\refsrc\brs_plmms.c \
           vendor\wap\obigo_Q03C\v1_official\modules\BRS\refsrc\brs_plti.c \
           vendor\wap\obigo_Q03C\v1_official\modules\BRS\refsrc\brs_pltx.c \
           vendor\wap\obigo_Q03C\v1_official\modules\BRS\refsrc\brs_plschmhdlr.c \
           vendor\wap\obigo_Q03C\v1_official\modules\BRS\refsrc\brs_spel.c 
ifneq ($(filter OBIGO_Q03C_MMS_V01 , $(strip $(MODULE_DEFS))),)                       
SRC_LIST += vendor\wap\obigo_Q03C\v1_official\modules\MMS\refsrc\mms_a.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MMS\refsrc\mms_aApp.c \
           vendor\wap\obigo_Q03C\v1_official\modules\SMA\export\sma_if.c \
           vendor\wap\obigo_Q03C\v1_official\modules\SMA\intgr\sma_env.c \
           vendor\wap\obigo_Q03C\v1_official\modules\SMA\source\saasync.c \
           vendor\wap\obigo_Q03C\v1_official\modules\SMA\source\saattach.c \
           vendor\wap\obigo_Q03C\v1_official\modules\SMA\source\saintsig.c \
           vendor\wap\obigo_Q03C\v1_official\modules\SMA\source\salnk.c \
           vendor\wap\obigo_Q03C\v1_official\modules\SMA\source\samain.c \
           vendor\wap\obigo_Q03C\v1_official\modules\SMA\source\samenu.c \
           vendor\wap\obigo_Q03C\v1_official\modules\SMA\source\sapckg.c \
           vendor\wap\obigo_Q03C\v1_official\modules\SMA\source\saph.c \
           vendor\wap\obigo_Q03C\v1_official\modules\SMA\source\sapipe.c \
           vendor\wap\obigo_Q03C\v1_official\modules\SMA\source\sasbp.c \
           vendor\wap\obigo_Q03C\v1_official\modules\SMA\source\sasig.c \
           vendor\wap\obigo_Q03C\v1_official\modules\SMA\source\saslide.c \
           vendor\wap\obigo_Q03C\v1_official\modules\SMA\source\sasls.c \
           vendor\wap\obigo_Q03C\v1_official\modules\SMA\source\saui.c \
           vendor\wap\obigo_Q03C\v1_official\modules\SMA\source\sauidia.c \
           vendor\wap\obigo_Q03C\v1_official\modules\SMA\source\sauilnk.c \
           vendor\wap\obigo_Q03C\v1_official\modules\SMA\source\sauisig.c \
           vendor\wap\obigo_Q03C\v1_official\modules\SMA\source\smtrcmn.c \
           vendor\wap\obigo_Q03C\v1_official\modules\SMA\source\smtrctrl.c \
           vendor\wap\obigo_Q03C\v1_official\modules\SMA\source\smtrpar.c \
           vendor\wap\obigo_Q03C\v1_official\modules\SMA\source\smtrrend.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\intgr\mea_env.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\refsrc\mea_int.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\refsrc\mea_rc.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\maaddr.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\maasync.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\macomm.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\maconf.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\macore.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\macrh.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\macth.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\madel.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\maincn.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\maintsig.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mamcr.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mame.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mamem.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mamh.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mamme.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mammv.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mamob.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mamoh.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mamr.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mamv.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\manotif.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\maopts.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mapbh.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mapckg.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\maph.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\masch.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mase.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\masig.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\maslh.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\masrh.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mauicmn.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mauicols.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mauicomm.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mauiconf.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mauidia.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mauiform.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mauiincn.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mauime.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mauimenu.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mauimh.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mauimme.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mauimmv.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mauimob.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mauimv.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mauipm.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mauise.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mauisemm.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mauisig.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mautils.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mtr_cmn.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mtr_ctrl.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mtr_par.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\source\mtr_rend.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\export\mea_if.c \
           vendor\wap\obigo_Q03C\v1_official\modules\MEA\export\meal_if.c
endif

ifneq ($(filter Q03C_IND_MOD_ARCH_SUPPORT, $(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\wap\obigo_Q03C\v1_official\msf\msf_lib\refsrc\msf_dlg.c \
            vendor\wap\obigo_Q03C\v1_official\msf\msf_lib\refsrc\msf_drc.c \
            vendor\wap\obigo_Q03C\v1_official\msf\msf_lib\refsrc\msf_sas.c \
            vendor\wap\obigo_Q03C\v1_official\msf\msf_lib\refsrc\msf_xmim.c \
            vendor\wap\obigo_Q03C\v1_official\msf\msf_lib\refsrc\msf_xchr.c \
            vendor\wap\obigo_Q03C\v1_official\msf\msf_lib\refsrc\wml_inpf.c \
            vendor\wap\obigo_Q03C\v1_official\msf\msf_mgr\refsrc\msm_dlg.c
endif
 
# Define include path lists to INC_DIR
INC_DIR = wapadp\include \
          vendor\wap\obigo_Q03C\adaptation\integration\include \
          vendor\wap\obigo_Q03C\adaptation\modules\mma\include \
          vendor\wap\obigo_Q03C\adaptation\modules\mma\export \
          vendor\wap\obigo_Q03C\adaptation\modules\mma\source \
          vendor\wap\obigo_Q03C\adaptation\modules\mma\intgr \
          vendor\wap\obigo_Q03C\adaptation\modules\mmc\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\MEA\config \
          vendor\wap\obigo_Q03C\v1_official\modules\MEA\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\MEA\refsrc \
          vendor\wap\obigo_Q03C\v1_official\modules\MEA\source \
          vendor\wap\obigo_Q03C\v1_official\modules\MEA\export \
          vendor\wap\obigo_Q03C\v1_official\modules\MMS\config \
          vendor\wap\obigo_Q03C\v1_official\modules\MMS\refsrc \
          vendor\wap\obigo_Q03C\v1_official\modules\MMS\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\MMS\source \
          vendor\wap\obigo_Q03C\v1_official\modules\MMS\export \
          vendor\wap\obigo_Q03C\v1_official\modules\SLS\config \
          vendor\wap\obigo_Q03C\v1_official\modules\SLS\export \
          vendor\wap\obigo_Q03C\v1_official\modules\SLS\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\SMA\config \
          vendor\wap\obigo_Q03C\v1_official\modules\SMA\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\SMA\refsrc \
          vendor\wap\obigo_Q03C\v1_official\modules\SMA\export \
          vendor\wap\obigo_Q03C\v1_official\modules\SMA\source \
          vendor\stk\obigo_Q03C\adaptation\modules\wps\include \
          vendor\wap\obigo_Q03C\adaptation\msf_ui\include \
          vendor\framework\obigo_Q03C\adaptation\integration\include\trc \
          vendor\framework\obigo_Q03C\adaptation\integration\include \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\config \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\refsrc \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\export \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\intgr \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_mgr\refsrc \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_mgr\intgr \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_mgr\source \
          vendor\wap\obigo_Q03C\v1_official\modules\BRA\config \
          vendor\wap\obigo_Q03C\v1_official\modules\BRA\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\BRA\source \
          vendor\wap\obigo_Q03C\v1_official\modules\BRA\refsrc \
          vendor\wap\obigo_Q03C\v1_official\modules\BRA\export \
          vendor\wap\obigo_Q03C\v1_official\modules\BRS\config \
          vendor\wap\obigo_Q03C\v1_official\modules\BRS\refsrc \
          vendor\wap\obigo_Q03C\v1_official\modules\BRS\export \
          vendor\wap\obigo_Q03C\v1_official\modules\BRS\intgr \
          vendor\wap\obigo_Q03C\v1_official\modules\BRS\source \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\config \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\refsrc \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\export \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\intgr \
          Plutommi\mmi\Inc \
          plutommi\Framework\Interface \
          plutommi\mmi\inc\MenuID \
          plutommi\Framework\CommonScreens\commonscreensinc \
          plutommi\Framework\CommonFiles\CommonInc \
          plutommi\Framework\MemManager\MemManagerInc \
          plutommi\Framework\DebugLevels\DebugLevelInc \
          plutommi\Framework\EventHandling\EventsInc \
          plutommi\Framework\Tasks\TasksInc \
          plutommi\Framework\History\historyinc \
          plutommi\Framework\NVRAMManager\nvrammanagerinc \
          plutommi\Framework\ThemeManager\thememanagerinc \
          applib\mem\include \
          plutommi\Framework\InputMethod\Inc \
          plutommi\mmi\setting\settinginc \
          plutommi\Framework\GUI\gui_Inc \
          plutommi\Framework\GUI\oem_inc \
          Plutommi\mmi\DateTime\DateTimeInc \
          Plutommi\mmi\MiscFramework\MiscFrameworkInc \
          plutommi\mmi\PROFILES\ProfilesInc \
          plutommi\mmi\phonebook\phonebookinc \
          plutommi\mmi\Organizer\OrganizerInc \
          plutommi\mmi\gpio\gpioInc \
          plutommi\mmi\messages\messagesInc \
          Plutommi\mmi \
          plutommi\MMI\IdleScreen\IdleScreenInc \
          plutommi\MtkApp\MtkAppInc \
          plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppInc \
          plutommi\mtkapp\EngineerMode\EngineerModeEngine\EngineerModeEngineInc \
          plutommi\MtkApp\SoundRecorder\SoundRecorderInc \
          plutommi\mmi\FunAndGames\FunAndGamesInc \
          plutommi\mmi\audio\audioinc \
          plutommi\mmi\sat\satInc \
          plutommi\customer\customerInc \
          plutommi\Framework\GDI\GDIInc \
          plutommi\service\MDI\MDIInc \
          plutommi\MtkApp\Camera\CameraInc \
          plutommi\MtkApp\AudioPlayer\AudioPlayerInc \
          plutommi\mtkapp\MediaPlayer\MediaPlayerInc \
          plutommi\MtkApp\FileMgr\FileMgrInc \
          plutommi\MtkApp\mmiapi\include \
          fmt\include \
          applib\misc\include \
          plutommi\MtkApp\dlagent\dlagentInc \
          plutommi\MtkApp\CentralConfigAgent\CentralConfigAgentInc \
          plutommi\mmi\DataAccount\DataAccountInc \
          plutommi\mmi\ConnectManagement\ConnectManagementInc \
          plutommi\mmi\EmailApp\EmailAppInc \
          plutommi\service\inc \
          plutommi\service\UPPSrv \
          plutommi\Service\Inc \
          vendor\push\obigo_Q03C\adaptation\integration\include \
          vendor\mms\obigo_Q03C\adaptation\integration\include

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
 
