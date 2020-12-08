# Define source file lists to SRC_LIST
SRC_LIST = plutommi\Framework\GDI\gdisrc\gd_2d_engine.c \
           plutommi\Framework\GDI\gdisrc\gd_primitive.c \
           plutommi\Framework\GDI\gdisrc\gd_primitive16.c \
           plutommi\Framework\GDI\gdisrc\gd_primitive24.c \
           plutommi\Framework\GDI\gdisrc\gd_primitive32.c \
           plutommi\Framework\GDI\gdisrc\gd_primitive32pargb.c \
           plutommi\Framework\GDI\gdisrc\gd_primitive8.c \
           plutommi\Framework\GDI\gdisrc\gdc_main.c \
           plutommi\Framework\GDI\gdisrc\gdd_main.c \
           plutommi\Framework\GDI\gdisrc\gdi.c \
           plutommi\Framework\GDI\gdisrc\gdi_task.c \
           plutommi\Framework\GDI\gdisrc\gdi_animate.c \
           plutommi\Framework\GDI\gdisrc\gdi_bytestream.c \
           plutommi\Framework\GDI\gdisrc\gdi_font.c \
           plutommi\Framework\GDI\gdisrc\gdi_image.c \
           plutommi\Framework\GDI\gdisrc\gdi_image_alpha_bmp.c \
           plutommi\Framework\GDI\gdisrc\gdi_image_alpha_bmp_v2.c \
           plutommi\Framework\GDI\gdisrc\gdi_image_alpha_bmp_v2_internal.c \
           plutommi\Framework\GDI\gdisrc\gdi_image_bmp.c \
           plutommi\Framework\GDI\gdisrc\gdi_image_decoder.c \
           plutommi\Framework\GDI\gdisrc\gdi_image_dev_bmp.c \
           plutommi\Framework\GDI\gdisrc\gdi_image_gif.c \
           plutommi\Framework\GDI\gdisrc\gdi_image_jpeg.c \
           plutommi\Framework\GDI\gdisrc\gdi_image_ktx.c \
           plutommi\Framework\GDI\gdisrc\gdi_image_png.c \
           plutommi\Framework\GDI\gdisrc\gdi_image_sequence.c \
           plutommi\Framework\GDI\gdisrc\gdi_image_virtualfile.c \
           plutommi\Framework\GDI\gdisrc\gdi_image_wbmp.c \
           plutommi\Framework\GDI\gdisrc\gdi_layer.c \
           plutommi\Framework\GDI\gdisrc\gdi_lcd.c \
           plutommi\Framework\GDI\gdisrc\gdi_lfs.c \
           plutommi\Framework\GDI\gdisrc\gdi_mutex.c \
           plutommi\Framework\GDI\gdisrc\gdi_primitive.c \
           plutommi\Framework\GDI\gdisrc\gdi_util.c \
           plutommi\Framework\GDI\gdisrc\gdi_ipp.c \
           plutommi\Framework\GDI\gdisrc\gdi_imgdec_bytestream.c \
           plutommi\Framework\GDI\gdisrc\gdi_imgdec_resizer.c \
           plutommi\Framework\GDI\gdisrc\gdi_imgdec_bmp.c \
           plutommi\Framework\GDI\gdisrc\gdi_imgdec_wbmp.c \
           plutommi\Framework\GDI\gdisrc\gdi_imgdec_gif.c \
           plutommi\Framework\GDI\gdisrc\gdi_imgdec.c \
           plutommi\Framework\GDI\gdisrc\ui_buffer.c

ifneq ($(strip $(MMI_VERSION)),COSMOS_MMI)
SRC_LIST += plutommi\Framework\GDI\gdisrc\gdi_image_9slice.c
endif


ifneq ($(filter JPG_DECODE, $(strip $(MODULE_DEFS))),)
       SRC_LIST += plutommi\Framework\GDI\gdisrc\gdi_image_hwjpg_v2.c
endif

ifneq ($(filter USE_SW_PNG_DECODER USE_HW_PNG_DECODER USE_HW_PNG_DECODER_V1, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\Framework\GDI\gdisrc\gdi_image_png.c
endif

ifneq ($(filter __MULTIPLE_ANGLE_VIEW_SUPPORT__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\Framework\GDI\gdisrc\gdi_image_mav.c
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
          plutommi\mtkapp\mtkappinc \
          plutommi\Framework\InputMethod\Engine\Engine_Inc \
          plutommi\Framework\InputMethod\Inc \
          plutommi\Framework\InputMethod\UI\UI_Inc \
          vendor\inputmethod\cstar\adaptation\include \
          vendor\inputmethod\t9\adaptation\include \
          btstacka\inc \
          custom\atci\include \
          drm\include \
          irda\inc \
          j2me\interface \
          j2me\jal\include \
          j2me\jal\include \
          media\common\include \
          media\image\include \
          media\rtp\inc \
          media\stream\include \
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
          plutommi\Service\UmmsSrv \
          plutommi\mmi\unifiedcomposer\unifiedcomposerinc \
          plutommi\mmi\unifiedmessage\unifiedmessageinc \
          plutommi\mmi\unifiedmms\mmsapp\mmsappinc \
          plutommi\mmi\voip\voipinc \
          plutommi\mtkapp\abrepeater\abrepeaterinc \
          plutommi\mtkapp\audioplayer\audioplayerinc \
          plutommi\mtkapp\MediaPlayer\MediaPlayerInc \
          plutommi\mtkapp\barcodereader\barcodereaderinc \
          plutommi\mtkapp\bgsound\bgsoundinc \
          plutommi\mtkapp\camera\camerainc \
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
          venusmmi\test \
          venusmmi\app \
          plutommi\service\Inc \
          plutommi\mmi\Bootup\BootupInc \
          custom\atci\include \
          custom\atci\include \
          plutommi\mtkapp\NPPlg\NPPlgInc \
          vendor\opera\browser\adaptation\inc \
          vendor\opera\browser\v1_official\opdev\include \
          plutommi\CUI\BookmarkCui \
          plutommi\MMI\CallSetting\CallSettingInc \
          plutommi\MMI\SupplementaryService\SsInc \
          hal\drv_def \
          interface\hal\graphics \
          interface\hal\drv_sw_def \
          interface\hal\display\ddv1 \
          interface\hal\mdp \
          interface\hal\display \
          interface\hal\display\wfc \
          interface\hal\display\common \
          hal\graphics\gif\hw\inc \
          hal\graphics\gif\sw\inc \
          interface\hal\display\exception \
          custom\common\hal_public

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


