# Define source file lists to SRC_LIST
SRC_LIST = plutommi\mmi\dataaccount\dataaccountsrc\DataAccountApp.c \
           plutommi\mmi\dataaccount\dataaccountsrc\dataaccountxml.c \
           plutommi\mmi\dataaccount\dataaccountsrc\DataAccountApi.c \
           plutommi\mmi\dataaccount\dataaccountsrc\DataConnectionSIM.c \
           plutommi\mmi\ConnectManagement\ConnectManagementSrc\ConnectManageMain.c \
           plutommi\mtkapp\connectivity\connectivitysrc\btcommon\BtMmiScr.c \
           plutommi\CUI\CbmCui\CbmCui.c \
           plutommi\MMI\Cbm\CbmSrc\CbmAppMain.c \
           plutommi\mtkapp\connectivity\connectivitysrc\connectivity.c \
           plutommi\mtkapp\dlagent\dlagentsrc\DLAgentAppEvtHdlr.c \
           plutommi\mtkapp\dlagent\dlagentsrc\DLAgentAppMain.c \
           plutommi\mtkapp\dlagent\dlagentsrc\DLAgentAppNCenter.c \
           plutommi\mtkapp\dlagent\dlagentsrc\DLAgentAppScrDraw.c \
           plutommi\mtkapp\dlagent\dlagentsrc\DLAgentAppScrHdlr.c \
           plutommi\mtkapp\dlagent\dlagentsrc\DLAgentAppCore.c \
           plutommi\MtkApp\SyncML\SyncMLSrc\syncmlfolder.c \
           plutommi\MtkApp\SyncML\SyncMLSrc\syncmlemail.c \
           plutommi\mtkapp\syncml\syncmlsrc\syncmlpcsync.c \
           plutommi\mtkapp\syncml\syncmlsrc\syncmlaccount.c \
           plutommi\mtkapp\syncml\syncmlsrc\syncmlcommon.c \
           plutommi\mtkapp\syncml\syncmlsrc\syncmlchangelog.c \
           plutommi\mtkapp\syncml\syncmlsrc\syncmlhandler.c \
           plutommi\mtkapp\syncml\syncmlsrc\syncmlmain.c \
           plutommi\mtkapp\syncml\syncmlsrc\syncmlotap.c \
           plutommi\mtkapp\syncml\syncmlsrc\syncmlregularity.c \
           plutommi\mtkapp\syncml\syncmlsrc\syncmlreport.c \
           plutommi\mtkapp\syncml\syncmlsrc\syncmlsas.c \
           plutommi\mtkapp\syncml\syncmlsrc\syncmlviewlog.c \
           plutommi\mtkapp\syncml\syncmlsrc\syncmldevice.c \
           plutommi\CUI\DataAccountCui\DataAccountCui.c \
		   plutommi\mtkapp\connectivity\connectivitysrc\NfcSetting.c \
		   plutommi\mtkapp\connectivity\connectivitysrc\DataRoaming.c

ifneq ($(filter __MMI_OP01_DCD__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\mtkapp\DCD\DCDSrc\DCDParseUrl.c \
                plutommi\mtkapp\DCD\DCDSrc\DCDNetEventHandler.c \
                plutommi\mtkapp\DCD\DCDSrc\DCDPush.c \
                plutommi\mtkapp\DCD\DCDSrc\DCDMain.c \
                plutommi\mtkapp\DCD\DCDSrc\DCDIdle.c \
                plutommi\mtkapp\DCD\DCDSrc\DCDStoryList.c \
                plutommi\mtkapp\DCD\DCDSrc\DCDStoryViewer.c \
                plutommi\mtkapp\DCD\DCDSrc\DCDChannelList.c \
                plutommi\mtkapp\DCD\DCDSrc\DCDSetting.c
else
    ifneq ($(filter __MMI_OP01_DCD_V30__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\mtkapp\DCD\DCDSrc\DCDV30App.c \
                    plutommi\mtkapp\DCD\DCDSrc\DCDV30Srv.c
    endif
endif

ifneq ($(filter __MMI_OP01_SYNCML_SETTING__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mtkapp\syncml\syncmlsrc\syncmlcustomizedsettings.c
endif

ifneq ($(filter __MMI_DATA_LOCK__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mtkapp\DataService\DataServiceSrc\DataService.c
endif

ifneq ($(filter __MMI_PUSH_TURN_ON_OFF_SWITCH__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mtkapp\PushSwitch\PushSwitchSrc\PushSwitch.c
endif

ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
    SRC_LIST += plutommi\mtkapp\connectivity\connectivitysrc\btmtk\BtMmiObex.c \
                plutommi\mtkapp\connectivity\connectivitysrc\btcommon\BtMmiObexScr.c \
                plutommi\mtkapp\connectivity\connectivitysrc\btmtk\BtMmiRecv.c \
                plutommi\mtkapp\connectivity\connectivitysrc\btmtk\BtMmiSend.c \
                plutommi\mtkapp\connectivity\connectivitysrc\btmtk\BtMmiSetting.c \
                plutommi\CUI\BTCMCui\BtcmCui.c
                
    ifneq ($(filter __MMI_BT_AUDIO_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\mtkapp\connectivity\connectivitysrc\btmtk\BtMmiHfp.c \
                    plutommi\mtkapp\connectivity\connectivitysrc\btmtk\BtMmiHsp.c
    endif
    ifneq ($(filter __MMI_A2DP_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\mtkapp\connectivity\connectivitysrc\btmtk\BtMmiA2dp.c \
                    plutommi\mtkapp\connectivity\connectivitysrc\btmtk\BTMMIA2DPScr.c \
                    plutommi\mtkapp\connectivity\connectivitysrc\btcommon\av_bt.c
    endif
    ifneq ($(filter __MMI_AVRCP_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\mtkapp\connectivity\connectivitysrc\btmtk\BtMmiAvrcp.c
    else
        ifneq ($(filter __MMI_AVRCP_CT_SUPPORT__, $(strip $(MODULE_DEFS))),)
            SRC_LIST += plutommi\mtkapp\connectivity\connectivitysrc\btmtk\BtMmiAvrcp.c
        endif
    endif
    ifneq ($(filter __MMI_BPP_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\mtkapp\connectivity\connectivitysrc\btmtk\BppMmi.c \
                    plutommi\mtkapp\connectivity\connectivitysrc\btmtk\BppXhtml.c
    endif
    ifneq ($(filter __MMI_DUN_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\mtkapp\connectivity\connectivitysrc\btmtk\BtMmiDun.c
    endif
    ifneq ($(filter __MMI_FAX_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\mtkapp\connectivity\connectivitysrc\btmtk\BtMmiFax.c
    endif
    ifneq ($(filter __MMI_OPP_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\mtkapp\connectivity\connectivitysrc\btmtk\BtMmiOpp.c
    endif
    ifneq ($(filter __MMI_BIP_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\mtkapp\connectivity\connectivitysrc\btmtk\BtMmiBip.c
    endif
    ifneq ($(filter __MMI_PBAP_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\mtkapp\connectivity\connectivitysrc\btmtk\BtMmiPbap.c
    endif
    ifneq ($(filter __MMI_FTC_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\mtkapp\connectivity\connectivitysrc\btmtk\BtMmiFtp.c
    else
        ifneq ($(filter __MMI_FTS_SUPPORT__, $(strip $(MODULE_DEFS))),)
            SRC_LIST += plutommi\mtkapp\connectivity\connectivitysrc\btmtk\BtMmiFtp.c
        endif
    endif
    ifneq ($(filter __MMI_HIDD_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\mtkapp\connectivity\connectivitysrc\btmtk\BtMmiHidd.c \
                    plutommi\mtkapp\connectivity\connectivitysrc\btcommon\BtMmiHidScr.c
    endif
    ifneq ($(filter __MMI_SPP_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\mtkapp\connectivity\connectivitysrc\btmtk\BtMmiSpp.c
    endif
    ifneq ($(filter __MMI_SIMAP_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\mtkapp\connectivity\connectivitysrc\btmtk\BtMmiSimap.c
    endif
    ifneq ($(filter __SUPPORT_JBT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\MtkApp\Connectivity\ConnectivitySrc\btmtk\BtMmiBcc.c
    endif
    ifneq ($(filter __MMI_BT_AUDIO_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\mtkapp\connectivity\connectivitysrc\btcommon\btmmiscopath.c
    endif
endif
 
ifneq ($(filter __MMI_USB_SUPPORT__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\mtkapp\connectivity\connectivitysrc\usbdevice.c
endif

ifneq ($(filter __MMI_WLAN_FEATURES__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mmi\dataaccount\dataaccountsrc\WlanAppCore.c \
           plutommi\mmi\dataaccount\dataaccountsrc\WlanAppEAP.c \
           plutommi\mmi\dataaccount\dataaccountsrc\WlanAppOperators.c \
           plutommi\mmi\dataaccount\dataaccountsrc\DataAccountUtils.c \
           plutommi\mmi\dataaccount\dataaccountsrc\WlanAppUI.c \
           plutommi\mmi\dataaccount\dataaccountsrc\WlanAppWps.c \
           plutommi\CUI\DataAccountCui\WlanCui.c
endif

ifneq ($(filter __MMI_WLAN_FEATURES__, $(strip $(MODULE_DEFS))),)
ifneq ($(filter __MMI_OP01_WIFI__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mmi\dataaccount\dataaccountsrc\cmcc_wlan_auth_ui.c \
           plutommi\mmi\dataaccount\dataaccountsrc\cmcc_wlan_auth_http.c
endif
endif

ifneq ($(filter __MMI_WEBCAM__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mtkapp\connectivity\connectivitysrc\webcam.c
endif

ifneq ($(filter __MMI_USB_SUPPORT__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\mtkapp\connectivity\connectivitysrc\usbdevice.c \
               plutommi\mtkapp\connectivity\connectivitysrc\UsbAdapt.c \
               plutommi\mtkapp\connectivity\connectivitysrc\usbpoweron.c 
endif

ifneq ($(filter SYNCML_DM_SUPPORT, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\mtkapp\dmapp\dmappsrc\dmapp.c \
                plutommi\mtkapp\dmapp\dmappsrc\dmappdl.c \
                plutommi\mtkapp\dmapp\dmappsrc\dmappsession.c
    ifneq ($(filter __CCA_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\mtkapp\dmapp\dmappsrc\dmappotap.c
    endif

    ifneq ($(filter __DM_LAWMO_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\mtkapp\dmapp\dmappsrc\dmapplawmo.c
    endif

    ifneq ($(filter __DM_FOTA_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\mtkapp\dmapp\dmappsrc\dmappfota.c
    endif
endif

ifneq ($(filter __MMI_IPSEC__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\mmi\IPSecApp\IPSecAppSrc\IPSecApp.c
endif

ifneq ($(filter __MMI_TETHERING__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\mmi\Tethering\TetheringSrc\TetheringApp.c
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
          plutommi\mmi\idle\idlesrc \
          plutommi\mmi\factory\factoryinc \
          plutommi\mmi\idle\idleinc \
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
          media\video\include \
          usb\include \
          verno \
          wapadp\include \
          xmlp\include \
          vcard\include \
          plutommi\CUI\Inc \
          plutommi\mmi\athandler\athandlerinc \
          plutommi\mmi\audio\audioinc \
          plutommi\Framework\BIDI\bidiinc \
          plutommi\mmi\browserapp\browser\browserinc \
          plutommi\Service\UPPSrv \
          plutommi\Service\Inc \
          plutommi\mmi\browserapp\pushinbox\pushinboxinc \
          plutommi\Framework\CommonScreens\commonscreensinc \
          plutommi\mmi\ConnectManagement\ConnectManagementInc \
          plutommi\mmi\cphs\cphsinc \
          plutommi\mmi\customerservice\customerserviceinc \
          plutommi\mmi\dataaccount\dataaccountinc \
          plutommi\Service\dtcntsrv \
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
          plutommi\Service\ProvisioningSrv \
          plutommi\mmi\resource\inc \
          plutommi\mmi\sat\satinc \
          plutommi\mmi\setting\settinginc \
          plutommi\mmi\smartmessage\smartmessageinc \
          plutommi\AppCore\ssc \
          plutommi\Service\Inc \
          plutommi\mmi\unifiedcomposer\unifiedcomposerinc \
          plutommi\mmi\unifiedmessage\unifiedmessageinc \
          plutommi\mmi\unifiedmms\mmsapp\mmsappinc \
          plutommi\Service\UmmsSrv \
          plutommi\mmi\voip\voipinc \
          plutommi\mmi\IPSecApp\IPSecAppInc \
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
          plutommi\mtkapp\DCD\DCDInc \
          plutommi\mtkapp\dlagent\dlagentinc \
          plutommi\mtkapp\dmapp\dmappinc \
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
          plutommi\mtkapp\soundrecorder\soundrecorderinc \
          plutommi\mtkapp\swflash\swflashinc \
          plutommi\mtkapp\syncml\syncmlinc \
          plutommi\mtkapp\video\videoinc \
          plutommi\mtkapp\vobjects\vobjectinc \
          plutommi\mtkapp\vrsd\vrsdinc \
          plutommi\mtkapp\vrsi\vrsiinc \
          plutommi\vendorapp\devapp\devappinc \
          venusmmi\vrt\interface \
          venusmmi\app\common\ncenter \
          venusmmi\app\common\interface\app \
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
          plutommi\mmi\SIMProvAgent\SIMProvAgentInc \
          security\ike\include \
          plutommi\mmi\UDX\UDXInc \
          interface\ps \
          btadp\include \
          interface\hal\bluetooth \
          vendor\streaming\a8box\adaptation\Inc \
          plutommi\Service\ProvBoxSrv \
          plutommi\mmi\ProvisioningInbox\ProvBoxApp\ProvBoxAppInc \
          vendor\player\ipeer\inc \
          vendor\player\ipeer\adaptation\inc \
          plutommi\mtkapp\MREAPP\MREAPPInc \
          plutommi\CUI\Inc \
          plutommi\CUI\DataAccountCui \
          plutommi\Service\CbmSrv \
          plutommi\MtkApp\WgtMgrApp\WgtMgrAppInc \
          plutommi\mmi\Tethering\TetheringInc \
          plutommi\Service\UPPSrv \
          plutommi\Service\ProvisioningSrv \
          plutommi\Service\RightsMgr \
          interface\hal\bluetooth \
          custom\common\hal_public \
          hal\system\dcmgr\inc

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
 
