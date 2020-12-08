# Define source file lists to SRC_LIST
SRC_LIST =  mre\engine\framework\elfldr.c \
            mre\engine\framework\vmloader.c \
			mre\engine\framework\httputil.c \
			mre\engine\framework\vmappcomm.c \
			mre\engine\framework\vmbitstream.c \
			mre\engine\framework\vmcell.c \
			mre\engine\framework\vmcerenv.c \
			mre\engine\framework\vmcermng.c \
			mre\engine\framework\vmcervar.c \
			mre\engine\framework\vmddraw.c \
			mre\engine\framework\vmgettag.c \
			mre\engine\framework\vmgfxold.c \
			mre\engine\framework\vmhttp.c \
			mre\engine\framework\vminifile.c \
			mre\engine\framework\vmmms.c \
			mre\engine\framework\vmmod.c \
			mre\engine\framework\vmmullang.c \
			mre\engine\framework\vmnvramadapter.c \
			mre\engine\framework\vmpermng.c \
			mre\engine\framework\vmpervar.c \
			mre\engine\framework\vmpromng.c \
			mre\engine\framework\vmres.c \
			mre\engine\framework\vmresmng.c \
			mre\engine\framework\vmsensor.c \
			mre\engine\framework\vmshortcut.c \
			mre\engine\framework\vmstack.c \
			mre\engine\framework\vmstdlib.c \
			mre\engine\framework\vmtlv.c \
			mre\engine\framework\vmvideo.c \
			mre\engine\framework\vmvip.c \
			mre\engine\framework\vmso.c \
			mre\engine\framework\vmsm.c \
			mre\engine\framework\vmwin32.c \
                     mre\engine\framework\vmjava.c \
			mre\engine\framework\vmpreload.c \
			mre\engine\sal\vmfrm.c \
			mre\engine\sal\vmcontact.c \
			mre\engine\sal\vmdes.c \
			mre\engine\sal\vmenv.c \
			mre\engine\sal\vmgps.c \
			mre\engine\sal\vmgraph.c \
			mre\engine\sal\vmio.c \
			mre\engine\sal\vmkuro.c \
			mre\engine\sal\vmlog.c \
			mre\engine\sal\vmmd5.c \
			mre\engine\sal\vmmm.c \
			mre\engine\sal\vmnvram.c \
			mre\engine\sal\vmnvramval.c \
			mre\engine\sal\vmoptions.c \
			mre\engine\sal\vmrsa.c \
			mre\engine\sal\vmsalbitstream.c \
			mre\engine\sal\vmsalcell.c \
			mre\engine\sal\vmsalcontact.c \
			mre\engine\sal\vmsalgps.c \
			mre\engine\sal\vmsalmm.c \
			mre\engine\sal\vmsalmms.c \
			mre\engine\sal\vmsalsms.c \
			mre\engine\sal\vmsha1.c \
			mre\engine\sal\vmsms.c \
			mre\engine\sal\vmsock.c \
			mre\engine\sal\vmstatusbar.c \
			mre\engine\sal\vmsys.c \
			mre\engine\sal\vmtel.c \
			mre\engine\sal\vmtheme.c \
			mre\engine\sal\vmtimer.c \
			mre\engine\sal\vmxml.c \
			mre\engine\sal\vmhttps.c \
			mre\engine\sal\vmwps.c \
			mre\engine\sal\vmche.c \
			mre\engine\sal\vmbtcm.c \
			mre\engine\sal\vmbtspp.c \
			mre\engine\sal\vmpayment.c \
			mre\engine\sal\vmpn.c \
			mre\engine\sal\vmda.c \
			mre\engine\sal\vmcppadp.cpp \
			mre\engine\sal\vmcmd.c\
			mre\engine\sal\vmncenter.c \
			mre\engine\sal\vmsso.c \
			mre\engine\sal\vmautostart.c \
			mre\engine\sal\vmalarm.c \
			mre\engine\sal\vmtls.c \
			mre\engine\sal\vmcuifdb.cpp \
			mre\engine\sal\vmsalui.c \
			mre\engine\sal\vmadpui.cpp \
			mre\engine\sal\vmcuifdst.cpp \
			mre\engine\sal\vmuart.c
			
ifneq ($(filter __MMI_QUERY_SRV__ , $(strip $(MODULE_DEFS))),)
     SRC_LIST += mre\engine\framework\vmsrvmng.cpp
endif

ifneq ($(filter __COSMOS_MMI_PACKAGE__ , $(strip $(MODULE_DEFS))),)
     SRC_LIST += mre\engine\sal\vmcuifst.cpp
endif

# Define include path lists to INC_DIR
INC_DIR = plutommi\mtkapp\Camcorder\CamcorderInc \
          plutommi\MtkApp\MtkAppInc \
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
          plutommi\AppCore\ssc \
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
          plutommi\Service\DLAgentSrv \
          plutommi\Service\profilessrv \
          plutommi\Service\ImgEdtSrv \
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
          plutommi\VendorApp\DevConfig\DevConfigInc \
          applib\mem\include \
          plutommi\Service\Inc \
          custom\j2me\NEMO\_DEFAULT_BB \
          j2me\jal\include \
          $(strip $(PS_FOLDER))\interfaces\local_inc \
          plutommi\VendorApp\appsdk\appsdkinc \
          plutommi\mtkapp\MREAPP\MREAPPInc \
          plutommi\CUI\Inc \
          plutommi\Service\Inc\Gsinc \
          plutommi\Service\GetSrvSrv \
          plutommi\Service\GetSrvSrv\gs_srv_ebook \
          plutommi\Service\GetSrvSrv\gs_srv_ucm \
          plutommi\Service\GetSrvSrv\gs_srv_um \
          plutommi\Service\GetSrvSrv\gs_srv_mms \
          plutommi\Service\GetSrvSrv\gs_srv_bitstreamaudio \
          plutommi\Service\GetSrvSrv\gs_srv_bitstreamrecord \
          plutommi\Service\GetSrvSrv\gs_srv_idlescreen \
          plutommi\Service\GetSrvSrv\gs_srv_imageviewer \
          plutommi\Service\GetSrvSrv\gs_srv_mmvideo \
          plutommi\Service\GetSrvSrv\gs_srv_profile \
          plutommi\Service\GetSrvSrv\gs_srv_videopdl \
          plutommi\Service\GetSrvSrv\gs_srv_videorecord \
          plutommi\Service\GetSrvSrv\gs_srv_videostream \
          plutommi\Service\Inc \
          venusmmi\app\Cosmos\interface\app \
          venusmmi\app\Cosmos\interface\cui \
          venusmmi\app\common\ime \
          venusmmi\framework\ui_core\mvc \
          venusmmi\framework\ui_core\pme \
          venusmmi\framework\ui_core\base \
          venusmmi\vrt\interface \
          venusmmi\framework\mmi_core \
          vendor\alipay\inc \
          plutommi\mmi\unifiedcomposer\unifiedcomposerinc\
          venusmmi\app\common\ncenter \
          venusmmi\framework\interface \
          plutommi\service\ummssrv \
          venusmmi\app\common\launcher \
          venusmmi\app\common\screen_lock \
          venusmmi\app\common\wallpaper \
          venusmmi\visual\cp\cosmos \
          venusmmi\framework \
          venusmmi\visual\cp\common \
          venusmmi\visual\cp\fte \
          venusmmi\app\common \
          plutommi\Framework\BIDI\BIDIInc \
          venusmmi\app\pluto_variation\adapter \
          verno 

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
INC_DIR += venusmmi\app\Cosmos\Ucm
else
INC_DIR += plutommi\mmi\Ucm\UcmInc
endif

# Define the specified compile options to COMP_DEFS
COMP_DEFS = MMI_ON_HARDWARE_P  \
            __UCS2_ENCODING
 
 
