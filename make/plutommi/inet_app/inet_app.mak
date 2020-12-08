# Define source file lists to SRC_LIST
SRC_LIST = plutommi\MMI\EmailApp\EmailAppSrc\EmailAppAPI.c

ifneq ($(filter __MMI_EMAIL__ , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\MMI\EmailApp\EmailAppSrc\EmailAppMain.c \
            plutommi\MMI\EmailApp\EmailAppSrc\EmailAppUtil.c \
            plutommi\mmi\emailapp\emailappsrc\EmailAppCore.c \
            plutommi\mmi\emailapp\emailappsrc\EmailAppEmn.c \
            plutommi\mmi\emailapp\emailappsrc\EmailAppOtap.c \
            plutommi\mmi\emailapp\emailappsrc\EmailAppAccount.c \
            plutommi\mmi\emailapp\emailappsrc\EmailAppCompose.c \
            plutommi\mmi\emailapp\emailappsrc\EmailAppRead.c \
            plutommi\mmi\emailapp\emailappsrc\EmailAppoperators.c \
            plutommi\mmi\emailapp\emailappsrc\EmailAppFolder.c \
            plutommi\mmi\emailapp\emailappsrc\EmailAppBPP.c \
            plutommi\mmi\emailapp\emailappsrc\EmailAppMem.c \
            plutommi\mmi\emailapp\emailappsrc\EmailAppMRE.c \
            plutommi\mmi\emailapp\emailappsrc\EmailAppAccountData.c \
            plutommi\mmi\emailapp\emailappsrc\EmailAppAccset.c \
            plutommi\mmi\emailapp\emailappsrc\EmailAppDtcnt.c \
            plutommi\mmi\emailapp\emailappsrc\EmailAppLib.c \
            plutommi\mmi\emailapp\emailappsrc\EmailAppNetwork.c \
            plutommi\mmi\emailapp\emailappsrc\EmailAppStateMgr.c \
            plutommi\mmi\emailapp\emailappsrc\EmailAppSwitchStorage.c \
            plutommi\mmi\emailapp\emailappsrc\EmailAppURI.c \
            plutommi\mmi\emailapp\emailappsrc\EmailAppNCenter.c \
            plutommi\mmi\emailapp\emailappsrc\EmailAppSSO.c
endif

ifneq ($(filter __MMI_IMPS__ , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mmi\IMPS\ImpsSrc\ImpsAppChat.c \
            plutommi\mmi\IMPS\ImpsSrc\ImpsAppChatHistory.c \
            plutommi\mmi\IMPS\ImpsSrc\ImpsAppCommon.c \
            plutommi\mmi\IMPS\ImpsSrc\ImpsAppContact.c \
            plutommi\mmi\IMPS\ImpsSrc\ImpsAppEvent.c \
            plutommi\mmi\IMPS\ImpsSrc\ImpsAppGroup.c \
            plutommi\mmi\IMPS\ImpsSrc\ImpsAppInvite.c \
            plutommi\mmi\IMPS\ImpsSrc\ImpsAppMain.c \
            plutommi\mmi\IMPS\ImpsSrc\ImpsAppOTA.c \
            plutommi\mmi\IMPS\ImpsSrc\ImpsAppPresence.c \
            plutommi\mmi\IMPS\ImpsSrc\ImpsAppProf.c \
            plutommi\mmi\IMPS\ImpsSrc\ImpsAppSearch.c \
            plutommi\mmi\IMPS\ImpsSrc\ImpsAppUICore.c \
            plutommi\mmi\IMPS\ImpsSrc\ImpsAppUtil.c \
            plutommi\mmi\IMPS\ImpsSrc\ImpsCui.c
endif

ifneq ($(filter __CERTMAN_SUPPORT__ , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mmi\CertificateManager\CertificateManagerMMISrc\CertManMMI.c \
            plutommi\mmi\CertificateManager\CertificateManagerMMISrc\CertManMMIInterfaces.c \
            plutommi\mmi\CertificateManager\CertificateManagerMMISrc\CertManMMIUI.c
endif


ifneq ($(filter __MMI_PROV_MESSAGE_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mmi\ProvisioningInbox\ProvBoxApp\ProvBoxAppSrc\ProvBoxAppMain.c \
           plutommi\mmi\ProvisioningInbox\ProvBoxApp\ProvBoxAppSrc\ProvBoxAppUtil.c \
           plutommi\mmi\ProvisioningInbox\ProvBoxApp\ProvBoxAppSrc\ProvBoxAppMsg.c \
           plutommi\mmi\ProvisioningInbox\ProvBoxApp\ProvBoxAppSrc\ProvBoxAppUI.c \
           plutommi\mmi\ProvisioningInbox\ProvBoxApp\ProvBoxAppSrc\ProvBoxAppNUM.c \
           plutommi\mmi\ProvisioningInbox\ProvBoxApp\ProvBoxAppSrc\ProvBoxAppUM.c
endif

ifneq ($(filter __CCA_SUPPORT__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\mtkapp\centralconfigagent\centralconfigagentsrc\centralconfigagentmain.c \
           plutommi\mtkapp\centralconfigagent\centralconfigagentsrc\centralconfigagentui.c
endif

ifneq ($(filter __SPA_SUPPORT__ , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mmi\SIMProvAgent\SIMProvAgentSrc\SIMProvAgentEFHdlr.c \
           plutommi\mmi\SIMProvAgent\SIMProvAgentSrc\SIMProvAgentMain.c \
           plutommi\mmi\SIMProvAgent\SIMProvAgentSrc\SIMProvAgentMsg.c \
           plutommi\mmi\SIMProvAgent\SIMProvAgentSrc\SIMProvAgentParser.c
endif

ifneq ($(filter OBIGO_Q03C_MMS_V01 , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mmi\q03c_mms_V01_agent\q03c_mms_V01_agentsrc\q03c_mms_V01_agentMsg.c \
           plutommi\mmi\q03c_mms_V01_agent\q03c_mms_V01_agentsrc\q03c_mms_V01_agentApp.c \
           plutommi\mmi\q03c_mms_V01_agent\q03c_mms_V01_agentsrc\q03c_mms_V01_agentMain.c \
           plutommi\mmi\q03c_mms_V01_agent\q03c_mms_V01_agentsrc\q03c_mms_V01_agentUtils.c \
           plutommi\mmi\q03c_mms_V01_agent\q03c_mms_V01_agentsrc\q03c_mms_V01_agentobjind.c \
           plutommi\mmi\q03c_mms_V01_agent\q03c_mms_V01_agentsrc\q03c_mms_V01_agentSettings.c
endif
ifneq ($(filter OBIGO_Q03C_MMS_V02 , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mmi\UnifiedMMS\MMSApp\MMSAppSrc\MMSAppDataManager.c \
           plutommi\mmi\UnifiedMMS\MMSApp\MMSAppSrc\MMSAppInterface.c \
           plutommi\mmi\UnifiedMMS\MMSApp\MMSAppSrc\MMSAppResourceDB.c \
           plutommi\mmi\UnifiedMMS\MMSApp\MMSAppSrc\MMSAppScrHdlr.c \
           plutommi\mmi\UnifiedMMS\MMSApp\MMSAppSrc\MMSAppUICallback.c \
           plutommi\mmi\UnifiedMMS\MMSApp\MMSAppSrc\MMSAppUIController.c \
           plutommi\mmi\UnifiedMMS\MMSApp\MMSAppSrc\MMSAppUIdraw.c \
           plutommi\mmi\UnifiedMMS\MMSApp\MMSAppSrc\MMSAppUIPlugin.c \
           plutommi\mmi\UnifiedMMS\MMSApp\MMSAppSrc\MMSAppResourceCntrlDB.c \
           plutommi\mmi\UnifiedMMS\MMSApp\MMSAppSrc\MMSAppSrvHdlr.c \
           plutommi\mmi\UnifiedMMS\MMSApp\MMSAppSrc\MMSAppUtil.c \
           plutommi\mmi\UnifiedMMS\MMSApp\MMSAppSrc\MMSAppOp.c \
           plutommi\mmi\UnifiedMMS\MMSApp\MMSAppSrc\MMSAppSettings.c \
	     plutommi\mmi\UnifiedMMS\MMSApp\MMSAppSrc\MMSAppComposerUILE.c
endif
ifneq ($(filter __MMI_BROWSER_2__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\MMI\BrowserApp\Browser\BrowserSrc\BrowserAppCntrlDB.c
SRC_LIST += plutommi\MMI\BrowserApp\Browser\BrowserSrc\BrowserAppDmgr.c
SRC_LIST += plutommi\MMI\BrowserApp\Browser\BrowserSrc\BrowserAppInterface.c
SRC_LIST += plutommi\MMI\BrowserApp\Browser\BrowserSrc\BrowserAppMain.c
SRC_LIST += plutommi\MMI\BrowserApp\Browser\BrowserSrc\BrowserAppScrDB.c
SRC_LIST += plutommi\MMI\BrowserApp\Browser\BrowserSrc\BrowserAppScrHdlr.c
SRC_LIST += plutommi\MMI\BrowserApp\Browser\BrowserSrc\BrowserAppSrvHdlr.c
SRC_LIST += plutommi\MMI\BrowserApp\Browser\BrowserSrc\BrowserAppUICallback.c
SRC_LIST += plutommi\MMI\BrowserApp\Browser\BrowserSrc\BrowserAppUIDraw.c
SRC_LIST += plutommi\MMI\BrowserApp\Browser\BrowserSrc\BrowserAppUIPlugIn.c
SRC_LIST += plutommi\Cui\BookmarkCui\BookmarkCuiObigo.c
endif

ifeq ($(strip $(BROWSER_SUPPORT)),NONE)
  SRC_LIST += plutommi\CUI\BookmarkCui\BookmarkCui.c
endif
ifneq ($(filter OPERA_BROWSER, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\CUI\BookmarkCui\BookmarkCuiOpera.c
endif

ifneq ($(filter __GADGET_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\MtkApp\WidgetDelegator\WidgetDelegatorSrc\widget_api.cpp \
            plutommi\MtkApp\WidgetDelegator\WidgetDelegatorSrc\widget_editor_ui.c \
            plutommi\MtkApp\WidgetDelegator\WidgetDelegatorSrc\widget_view_ui.c \
            plutommi\MtkApp\WidgetDelegator\WidgetDelegatorSrc\widget_camera_ui.c \
            plutommi\MtkApp\WidgetDelegator\WidgetDelegatorSrc\widget_filebrowser_ui.c \
            plutommi\MtkApp\WidgetDelegator\WidgetDelegatorSrc\widget_devapp.c
endif

ifneq ($(filter __WAP_PUSH_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mmi\BrowserApp\PushInbox\PushInboxSrc\WAPPushCntrlr.c
SRC_LIST += plutommi\mmi\BrowserApp\PushInbox\PushInboxSrc\WAPPushDMgr.c
SRC_LIST += plutommi\mmi\BrowserApp\PushInbox\PushInboxSrc\WAPPushScreenHdlr.c
SRC_LIST += plutommi\mmi\BrowserApp\PushInbox\PushInboxSrc\WAPPushUIPlugIn.c
SRC_LIST += plutommi\Cui\ServiceMessageCui\ServiceMsgCuiMain.c
    ifneq ($(filter __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__,$(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\mmi\BrowserApp\PushInbox\PushInboxSrc\WAPPushProv.c
    endif
    ifneq ($(filter __MMI_PUSH_IN_UM__,$(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\mmi\BrowserApp\PushInbox\PushInboxSrc\WAPPushUM.c
    endif
endif

ifneq ($(filter WAP_SUPPORT, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\MMI\BrowserApp\UPPApp\UPPAppSrc\WAPprofilemain.c
SRC_LIST += plutommi\MMI\BrowserApp\UPPApp\UPPAppSrc\WAPprofileuihandler.c
SRC_LIST += plutommi\MMI\BrowserApp\UPPApp\UPPAppSrc\WAPprovisioningmain.c
endif


# Define include path lists to INC_DIR
INC_DIR = applib\inet\engine\include \
          applib\mem\include \
          applib\misc\include \
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
          plutommi\Framework\Interface \
          plutommi\mmi\inc\menuid \
          plutommi\Framework\CommonFiles\commoninc \
          plutommi\Framework\EventHandling\eventsinc \
          plutommi\Framework\History\historyinc \
          plutommi\Framework\MemManager\memmanagerinc \
          plutommi\Framework\NVRAMManager\nvrammanagerinc \
          plutommi\Framework\Tasks\tasksinc \
          plutommi\Framework\ThemeManager\thememanagerinc \
          plutommi\Framework\GUI\gui_inc \
          plutommi\Framework\GUI\oem_inc \
          plutommi\Framework\InputMethod\Inc \
          plutommi\Framework\LangModule\LangModuleInc \
          plutommi\mmi\miscframework\miscframeworkinc \
          plutommi\Framework\GDI\gdiinc \
          plutommi\service\mdi\mdiinc \
          plutommi\Service\ImgEdtSrv \
          plutommi\mtkapp\mtkappinc \
          vendor\inputmethod\cstar\adaptation\include \
          vendor\inputmethod\t9\adaptation\include \
          btstacka\inc \
          drm\include \
          irda\inc \
          j2me\interface \
          j2me\jal\include \
          j2me\jal\include \
          media\image\include \
          media\rtp\inc \
          media\stream\include \
          usb\include \
          verno \
          wapadp\include \
          xmlp\include \
          plutommi\CUI\Inc \
          plutommi\mmi\athandler\athandlerinc \
          plutommi\mmi\audio\audioinc \
          plutommi\Framework\BIDI\bidiinc \
          plutommi\mmi\browserapp\browser\browserinc \
          plutommi\mmi\browserapp\UPPApp\UPPAppinc \
          plutommi\mmi\browserapp\pushinbox\pushinboxinc \
          plutommi\mmi\CertificateManager\CertificateManagerMMIInc \
	  security\certman\include \
          plutommi\Framework\CommonScreens\commonscreensinc \
          plutommi\mmi\ConnectManagement\ConnectManagementInc \
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
          plutommi\Framework\Languages\thai\thaiinc \
          plutommi\mmi\mainmenu\mainmenuinc \
          plutommi\mmi\messages \
          plutommi\mmi\messages\messagesinc \
          plutommi\mmi\mobileservice\mobileserviceinc \
          plutommi\mmi\nitzhandler\nitzinc \
          plutommi\mmi\organizer\organizerinc \
          plutommi\mmi\phonebook\phonebookinc \
          plutommi\mmi\profiles\profilesinc \
          plutommi\mmi\resource\inc \
          plutommi\mmi\sat\satinc \
          plutommi\mmi\setting\settinginc \
          plutommi\mmi\smartmessage\smartmessageinc \
          plutommi\AppCore\ssc \
          plutommi\mmi\unifiedmessage\unifiedmessageinc \
          plutommi\Service\Inc \
          plutommi\mmi\unifiedcomposer\unifiedcomposerinc \
          plutommi\Service\UcSrv \
          plutommi\mmi\unifiedmms\mmsapp\mmsappinc \
          plutommi\Service\UmmsSrv \
          plutommi\Service\UPPSrv \
          plutommi\mmi\voip\voipinc \
          plutommi\mmi\SIMProvAgent\SIMProvAgentInc \
          plutommi\mtkapp\abrepeater\abrepeaterinc \
          plutommi\mtkapp\audioplayer\audioplayerinc \
          plutommi\mtkapp\MediaPlayer\MediaPlayerInc \
          plutommi\mtkapp\avatar\avatarinc \
          plutommi\mtkapp\barcodereader\barcodereaderinc \
          plutommi\mtkapp\bgsound\bgsoundinc \
          plutommi\mtkapp\camera\camerainc \
          plutommi\mtkapp\camcorder\camcorderinc \
          plutommi\mtkapp\centralconfigagent\centralconfigagentinc \
          plutommi\mtkapp\connectivity\connectivityinc \
          plutommi\mtkapp\connectivity\connectivityinc\btcommon \
          plutommi\mtkapp\connectivity\connectivityinc\btmtk \
          plutommi\Framework\CSBrowser\csbrowserinc \
          plutommi\mtkapp\dlagent\dlagentinc \
          plutommi\mtkapp\dmuiapp\dmuiappinc \
          plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppInc \
          plutommi\mtkapp\EngineerMode\EngineerModeEngine\EngineerModeEngineInc \
          plutommi\mtkapp\filemgr\filemgrinc \
          plutommi\mtkapp\fmradio\fmradioinc \
          plutommi\mtkapp\fmschedulerec\fmschedulerecinc \
          plutommi\mtkapp\javaagency\javaagencyinc \
          plutommi\mtkapp\mmiapi\include \
          plutommi\mtkapp\mobiletvplayer\mobiletvplayerinc \
          plutommi\mtkapp\myfavorite\myfavoriteinc \
          plutommi\mtkapp\photoeditor\photoeditorinc \
          plutommi\mtkapp\pictbridge\pictbridgeinc \
          plutommi\mtkapp\rightsmgr\rightsmgrinc \
          plutommi\mtkapp\soundrecorder\soundrecorderinc \
          plutommi\mtkapp\swflash\swflashinc \
          plutommi\mtkapp\syncml\syncmlinc \
          plutommi\mtkapp\video\videoinc \
          plutommi\mtkapp\vobjects\vobjectinc \
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
          vendor\wap\obigo_Q03C\adaptation\modules\mma\include \
          vendor\wap\obigo_Q03C\adaptation\msf_ui\include \
          plutommi\mmi\UDX\UDXInc \
          plutommi\mmi\ProvisioningInbox\ProvBoxApp\ProvBoxAppInc \
          plutommi\Service\ProvBoxSrv \
          plutommi\mmi\q03c_mms_V01_agent\q03c_mms_V01_agentinc \
          plutommi\service\WapPushSrv \
          vendor\framework\obigo_Q03C\adaptation\integration\include \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\config \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\intgr \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\export \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\refsrc \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_mgr\intgr \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_mgr\refsrc \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_mgr\source \
          vendor\wap\obigo_Q03C\adaptation\integration\include \
          vendor\framework\obigo_Q03C\adaptation\integration\include\trc \
          plutommi\MtkApp\WidgetDelegator\WidgetDelegatorInc \
          plutommi\MtkApp\WidgetDelegator\WidgetDelegatorRes \
          plutommi\VendorApp\APPSDK\APPSDKInc \
          plutommi\cui\Inc \
          vendor\widget\google\adaptation \
          vendor\widget\google\adaptation\extensions\maui_audio_framework \
          venusmmi\app \
          venusmmi\app\common\wallpaper \
          venusmmi\app\common\ncenter \
          venusmmi\app\common\interface\app \
          venusmmi\app\pluto_variation \
          venusmmi\vrt\interface \
          venusmmi\framework \
          venusmmi\framework\interface \
          venusmmi\framework\mmi_core \
          venusmmi\framework\ui_core\base \
          venusmmi\framework\ui_core\mvc \
          venusmmi\framework\ui_core\pme \
          venusmmi\framework\xml \
          venusmmi\visual \
          venusmmi\visual\cp \
          venusmmi\visual\cp\common \
          venusmmi\visual\cp\cosmos \
          venusmmi\visual\cp\fte \
          venusmmi\visual\interface \
          venusmmi\app\common \
          venusmmi\app\common\ime \
          venusmmi\app\common\clipboard \
          venusmmi\app\common\interface\service \
          venusmmi\app\pluto_variation\adapter \
          venusmmi\app\pluto_variation\adapter\interface \
          venusmmi\app\pluto_variation\adapter\interface\res \
          venusmmi\test \
          plutommi\service\BrowserSrv \
          plutommi\CUI\BookmarkCui \
          vendor\opera\browser\adaptation\inc \
          venusmmi\app\pluto_variation\ShellApp\panel \
          venusmmi\app\pluto_variation\ShellApp\panel\HomeScreen \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel\HomeScreen \
          plutommi\Service\ProvisioningSrv \
          custom\common\hal_public \
          plutommi\CUI\SsoCui\SsoCuiInc

ifneq ($(filter OPERA_V10_BROWSER , $(strip $(MODULE_DEFS))),)
INC_DIR += vendor\opera\browser\v1_official\opdev\include
endif
ifneq ($(filter OPERA_V11_BROWSER , $(strip $(MODULE_DEFS))),)
INC_DIR += vendor\opera\browser\v11_official\opdev\include
endif

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


