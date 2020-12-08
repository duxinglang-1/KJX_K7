# Define source file lists to SRC_LIST
SRC_LIST = plutommi\Framework\GDI\GDISrc\gd_primitive_arm.c \
           gdi_arm\src\gui_effect_arm_oem.c \
           plutommi\Framework\GDI\gdisrc\gdi_image_alpha_bmp_v2_core.c  \
           plutommi\Framework\GDI\gdisrc\gdi_image_alpha_bmp_v2_speed.cpp  \
           plutommi\Framework\GDI\gdisrc\gd_primitive_pargb6666.c \
           plutommi\Framework\GDI\gdisrc\gdi_blending.c

ifneq ($(filter __COSMOS_MMI__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\Framework\GDI\GDISrc\gdi_image_9slice.c
endif
		   

#  Define include path lists to INC_DIR
INC_DIR = applib\mem\include          \
          plutommi\MtkApp\MtkAppInc          \
          plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppInc         \
          plutommi\mtkapp\EngineerMode\EngineerModeEngine\EngineerModeEngineInc          \
          plutommi\MtkApp\Connectivity\ConnectivityInc          \
          plutommi\MtkApp\Connectivity\ConnectivityInc\BtCommon          \
          plutommi\MtkApp\Connectivity\ConnectivityInc\BtMtk          \
          plutommi\MtkApp\SoundRecorder\SoundRecorderInc          \
          plutommi\MtkApp\AudioPlayer\AudioPlayerInc          \
          plutommi\MtkApp\ABRepeater\ABRepeaterInc          \
          plutommi\mmi\asyncevents\AsyncEventsInc          \
          plutommi\mmi\Audio\AudioInc          \
          plutommi\mmi\GSMCallApplication\CommonFiles\CommonInc          \
          plutommi\mmi\GSMCallApplication\outgoingcallmanagement\outgoinginc          \
          plutommi\mmi\GSMCallApplication\incomingcallmanagement\incominginc          \
          plutommi\Customer\custresource          \
          plutommi\mmi\DateTime\DateTimeInc          \
          plutommi\Framework\DebugLevels\debuglevelInc          \
          plutommi\Framework\CommonFiles\commoninc          \
          plutommi\Framework\Tasks\tasksinc          \
          plutommi\Framework\History\historyInc          \
          plutommi\Framework\EventHandling\EventsInc          \
          plutommi\Framework\MemManager\MemManagerInc          \
          plutommi\Framework\NVRAMManager\NVRAMManagerInc          \
          plutommi\Framework\ThemeManager\ThemeManagerInc          \
          plutommi\mmi\FunAndGames\FunAndGamesInc          \
          plutommi\Framework\GUI\gui_inc          \
          plutommi\Framework\GUI\oem_inc          \
          plutommi\MMI\IdleScreen\IdleScreenInc          \
          plutommi\MMI\IdleScreen\IdleScreenInc\DemoAppInc          \
          plutommi\mmi\inc \
          plutommi\Framework\Interface          \
          plutommi\mmi\inc\MenuID          \
          plutommi\mmi\MainMenu\MainMenuInc          \
          plutommi\mmi\Messages\MessagesInc          \
          plutommi\MMI\Messages          \
          plutommi\mmi\miscframework\miscframeworkinc          \
          plutommi\mmi\phonebook\PhonebookInc          \
          plutommi\mmi\profiles\ProfilesInc          \
          plutommi\mmi\sat\satInc          \
          plutommi\mmi\Setting\SettingInc          \
          plutommi\MMI\gpio\gpioInc          \
          plutommi\MMI\DataAccount\DataAccountInc          \
          plutommi\MMI\Help\HelpInc          \
          plutommi\MMI\Organizer\OrganizerInc          \
          plutommi\MMI\Extra\ExtraInc          \
          plutommi\mmi\ATHandler\ATHandlerInc          \
          plutommi\mmi\NITZHandler\NITZInc          \
          fs\fat\include          \
          plutommi\Framework\CommonScreens\commonscreensInc          \
          plutommi\mmi\CPHS\CPHSInc          \
          plutommi\customer\customerinc          \
          plutommi\MtkApp\FileMgr\FileMgrInc          \
          plutommi\MtkApp\Camera\CameraInc          \
          plutommi\MtkApp\Video\VideoInc          \
          plutommi\Framework\GDI\GDIInc          \
          xmlp\include          \
          plutommi\service\MDI\MDIInc          \
          plutommi\MtkApp\mmiapi\include          \
          interface\hwdrv          \
          wapadp\include          \
          fmt\include          \
          irda\inc          \
          plutommi\MtkApp\vObjects\vObjectInc          \
          plutommi\MtkApp\FMRadio\FMRadioInc          \
          plutommi\MtkApp\FMScheduleRec\FMScheduleRecInc          \
          plutommi\MMI\EmailApp\EmailAppInc          \
          drm\include          \
          plutommi\MtkApp\VRSD\VRSDInc          \
          plutommi\MtkApp\VRSI\VRSIInc          \
          plutommi\MtkApp\PhotoEditor\PhotoEditorInc          \
          applib\misc\include          \
          plutommi\MtkApp\BGSound\BGSoundInc          \
          xmlp\include          \
          plutommi\MtkApp\JavaAgency\JavaAgencyInc          \
          plutommi\MMI\Dictionary\DictInc          \
          j2me\interface          \
          j2me\jal\include          \
          plutommi\VendorApp\DevApp\DevAppInc          \
          j2me\jal\include          \
          plutommi\MtkApp\DLAgent\DLAgentInc          \
          plutommi\MMI\UnifiedMessage\UnifiedMessageInc          \
          plutommi\mmi\EbookReader\EbookInc          \
          interface\hal\display\ddv1          \
          interface\hal\display          \
          interface\hal\display\wfc          \
          interface\hal\display\common          \
          interface\hal\display\ddv1

# Define the specified compile options to COMP_DEFS
COMP_DEFS = MMI_ON_HARDWARE_P

