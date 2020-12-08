# Define source file lists to SRC_LIST
SRC_LIST = plutommi\VendorApp\DevApp\DevAppSrc\DevApp.c \
           plutommi\VendorApp\DevConfig\DevConfigSrc\DevConfig.c \
           plutommi\VendorApp\ResGenerator\DevApp_ReadRes.c \
           plutommi\VendorApp\DevResource\Resources\DevAppAdoMap.c \
           plutommi\VendorApp\DevResource\Resources\DevAppAdoRes.c \
           plutommi\VendorApp\DevResource\Resources\DevAppImgMap.c \
           plutommi\VendorApp\DevResource\Resources\DevAppImgRes.c \
           plutommi\VendorApp\DevResource\Resources\DevAppMenuRes.c \
           plutommi\VendorApp\DevResource\Resources\DevAppStrMap.c \
           plutommi\VendorApp\DevResource\Resources\DevAppStrRes.c 

ifeq ($(strip $(FLAVOR)),VENDOR_SDK)
  SRC_LIST += plutommi\VendorApp\DevSample\DevSampleSrc\Sample_Call.c \
              plutommi\VendorApp\DevSample\DevSampleSrc\Sample_FileSystem.c \
              plutommi\VendorApp\DevSample\DevSampleSrc\Sample_IMEI_IMSI.c \
              plutommi\VendorApp\DevSample\DevSampleSrc\Sample_Interrupt_Handler.c \
              plutommi\VendorApp\DevSample\DevSampleSrc\Sample_Memory.c \
              plutommi\VendorApp\DevSample\DevSampleSrc\Sample_SMS.c \
              plutommi\VendorApp\DevSample\DevSampleSrc\Sample_Wps.c \
              plutommi\VendorApp\DevSample\DevSampleSrc\Sample_XML.c
endif

# Define include path lists to INC_DIR
INC_DIR = plutommi\mtkapp\Camcorder\CamcorderInc \
          plutommi\MtkApp\MtkAppInc \
          plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppInc \
          plutommi\mtkapp\EngineerMode\EngineerModeEngine\EngineerModeEngineInc \
          plutommi\MtkApp\Connectivity\ConnectivityInc \
          plutommi\MtkApp\Connectivity\ConnectivityInc\BtCommon \
          plutommi\MtkApp\SoundRecorder\SoundRecorderInc \
          plutommi\MtkApp\AudioPlayer\AudioPlayerInc \
          plutommi\MtkApp\ABRepeater\ABRepeaterInc \
          plutommi\mmi\asyncevents\AsyncEventsInc \
          plutommi\mmi\Audio\AudioInc \
          plutommi\mmi\GSMCallApplication\CommonFiles\CommonInc \
          plutommi\mmi\GSMCallApplication\outgoingcallmanagement\outgoinginc \
          plutommi\mmi\GSMCallApplication\incomingcallmanagement\incominginc \
          plutommi\Customer\custresource \
          plutommi\mmi\DateTime\DateTimeInc \
          plutommi\Framework\DebugLevels\debuglevelInc \
          plutommi\Framework\CommonFiles\CommonInc \
          plutommi\Framework\Tasks\tasksinc \
          plutommi\Framework\History\historyInc \
          plutommi\Framework\EventHandling\EventsInc \
          plutommi\Framework\MemManager\MemManagerInc \
          plutommi\Framework\NVRAMManager\NVRAMManagerInc \
          plutommi\Framework\ThemeManager\ThemeManagerInc \
          plutommi\mmi\FunAndGames\FunAndGamesInc \
          plutommi\Framework\GUI\gui_inc \
          plutommi\Framework\GUI\oem_inc \
          plutommi\MMI\IdleScreen\IdleScreenInc \
          plutommi\MMI\IdleScreen\IdleScreenInc\DemoAppInc \
          plutommi\mmi\inc \
          plutommi\Framework\Interface \
          plutommi\Framework\InputMethod\inc \
          plutommi\mmi\inc\MenuID \
          plutommi\mmi\MainMenu\MainMenuInc \
          plutommi\mmi\Messages\MessagesInc \
          plutommi\MMI\Messages \
          plutommi\mmi\miscframework\miscframeworkinc \
          plutommi\mmi\phonebook\PhonebookInc \
          plutommi\mmi\profiles\ProfilesInc \
          plutommi\mmi\sat\satInc \
          plutommi\mmi\Setting\SettingInc \
          plutommi\AppCore\SSC \
          plutommi\MMI\gpio\gpioInc \
          plutommi\MMI\DataAccount\DataAccountInc \
          plutommi\MMI\Help\HelpInc \
          plutommi\MMI\Organizer\OrganizerInc \
          plutommi\MMI\Extra\ExtraInc \
          plutommi\mmi\ATHandler\ATHandlerInc \
          plutommi\mmi\NITZHandler\NITZInc \
          fs\fat\include \
          plutommi\Framework\CommonScreens\commonscreensInc \
          plutommi\mmi\CPHS\CPHSInc \
          plutommi\customer\customerinc \
          plutommi\MtkApp\FileMgr\FileMgrInc \
          plutommi\MtkApp\Camera\CameraInc \
          plutommi\MtkApp\Video\VideoInc \
          plutommi\Framework\GDI\GDIInc \
          plutommi\service\MDI\MDIInc \
          plutommi\MtkApp\mmiapi\include \
          interface\hwdrv \
          wapadp\include \
          fmt\include \
          irda\inc \
          plutommi\MtkApp\vObjects\vObjectInc \
          plutommi\MtkApp\FMRadio\FMRadioInc \
          plutommi\MtkApp\FMScheduleRec\FMScheduleRecInc \
          plutommi\MMI\EmailApp\EmailAppInc \
          drm\include \
          plutommi\MtkApp\VRSD\VRSDInc \
          plutommi\MtkApp\VRSI\VRSIInc \
          plutommi\MtkApp\PhotoEditor\PhotoEditorInc \
          applib\misc\include \
          plutommi\MtkApp\BGSound\BGSoundInc \
          xmlp\include \
          plutommi\MtkApp\JavaAgency\JavaAgencyInc \
          plutommi\VendorApp\DevApp\DevAppInc \
          plutommi\VendorApp\APPSDK\APPSDKInc \
          plutommi\VendorApp\DevConfig\DevConfigInc \
          applib\mem\include \
          plutommi\CUI\Inc \
          plutommi\Service\Inc \
          plutommi\mtkapp\MREAPP\MREAPPInc

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
INC_DIR += venusmmi\app\Cosmos\Ucm
else
INC_DIR += plutommi\mmi\Ucm\UcmInc
endif

# Define the specified compile options to COMP_DEFS
COMP_DEFS = MMI_ON_HARDWARE_P \
            __UCS2_ENCODING

ifneq ($(filter PLUTO_MMI COSMOS_MMI,$(strip $(call Upper,$(MMI_VERSION)))),)
ifeq ($(call Upper,$(strip $(LEVEL))),VENDOR)
  COMP_DEFS += __DEVAPP_RESOURCE_OUTPUT__
endif
endif


