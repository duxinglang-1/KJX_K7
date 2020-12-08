# Define source file lists to SRC_LIST
SRC_LIST = plutommi\Service\AppMgrSrv\AppMgrSrv.c \
           plutommi\Service\NativeAppFactorySrv\NativeAppFactorySrv.c \
           plutommi\Service\UmSrv\UmSrvCacheMgr.c \
           plutommi\Service\UmSrv\UmSrvInterface.c \
           plutommi\Service\UmSrv\UmSrvMain.c \
           plutommi\Service\UmSrv\UmSrvMsgHandler.c \
           plutommi\service\CertmanSrv\certManAgentSrv.c \
           plutommi\Service\InetSrv\InetSrvMain.c \
           plutommi\Service\InetSrv\InetSrvRecv.c \
           plutommi\Service\InetSrv\InetSrvSend.c \
           plutommi\Service\InetSrv\InetSrvUtil.c \
           plutommi\Service\DevProfileSrv\DevProfileSrv.c \
           plutommi\Service\TetheringSrv\TetheringSrvApi.c

ifneq ($(filter __MMI_PNS__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\PnSrv\PnSrvMain.c \
	       plutommi\Service\PnSrv\PnSrvJsonUtil.c \
           vendor\push_notification_engine\HPNSTask\src\hpnsPlatform.c
endif
ifeq ($(strip $(CLOUD_SUPPORT)),SOURCE)
SRC_LIST += plutommi\Service\SsoSrv\SsoSrvMain.c \
            plutommi\Service\SsoSrv\plugin\yahoo\YAHOO_vpp.c
endif
ifneq ($(filter WAP_SUPPORT , $(strip $(MODULE_DEFS))),) 
SRC_LIST += plutommi\Service\UPPSrv\WAPprovisioningSrvmain.c \
	   plutommi\Service\UPPSrv\WAPprovisioningSrvmsghandler.c \
           plutommi\Service\UPPSrv\WAPprofileSrvmsghandler.c \
           plutommi\Service\UPPSrv\WAPprofileSrvstoragehandler.c \
           plutommi\Service\UPPSrv\WAPprofileSrvmain.c \
           plutommi\Service\UPPSrv\WAPprofileSrvconfig.c
endif

ifneq ($(filter __PROVISIONING_SERVICE_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\ProvisioningSrv\ProvisioningSrvCommonUtils.c \
	     plutommi\Service\ProvisioningSrv\ProvisioningSrvConfiguringSrc.c \
	     plutommi\Service\ProvisioningSrv\ProvisioningSrvMsgHandler.c \
	   plutommi\Service\ProvisioningSrv\ProvisioningSrvTagHandler.c
endif

SRC_LIST += plutommi\Service\ProvisioningSrv\ProvisioningSrvMain.c 

ifneq ($(filter OBIGO_Q03C_MMS_V02 , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\UmmsSrv\MmsInterfaceSrv.c \
           plutommi\Service\UmmsSrv\MMSTemplateGenSrv.c \
           plutommi\Service\UmmsSrv\MMSSLIMBGSRSrvLE.c \
           plutommi\Service\UmmsSrv\MmsMainSrv.c \
           plutommi\Service\UmmsSrv\MMSAdpSrv.c \
           plutommi\Service\UmmsSrv\MmsMsgHdlrSrv.c \
           plutommi\Service\UmmsSrv\MmsMsgParseSrv.c \
           plutommi\Service\UmmsSrv\MmsMemoryManagerSrv.c \
           plutommi\Service\UmmsSrv\MmsXMLEncodeSrv.c \
           plutommi\Service\UmmsSrv\MmsSendRcvSrv.c \
           plutommi\Service\UmmsSrv\MmsUseDetailSrv.c \
           plutommi\Service\UmmsSrv\MmsExtSrv.c \
           plutommi\Service\UmmsSrv\MMSBGSRSrvApp.c \
           plutommi\Service\UmmsSrv\MMSBGSRSrvMain.c \
           plutommi\Service\UmmsSrv\MMSBGSRSrvMsg.c \
           plutommi\Service\UmmsSrv\MMSJSRSrvMain.c \
           plutommi\Service\UmmsSrv\MmsContextSrvLE.c
ifneq ($(filter __MMS_JSR_205_SUPPORT__ , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\UmmsSrv\MMSJSRSrvSndRcv.c
endif


endif
ifneq ($(filter __MMS_STANDALONE_COMPOSER_SUPPORT__ , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\UcSrv\UcEgnSrv.c \
           plutommi\Service\UcSrv\UcXmlSrv.c \
           plutommi\Service\UcSrv\UcMiscSrv.c \
           plutommi\Service\UcSrv\UcPcrdSrv.c
endif

ifneq ($(filter __UNIFIED_COMPOSER_SUPPORT__  , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\UcSrv\UcEgnSrv.c \
           plutommi\Service\UcSrv\UcXmlSrv.c \
           plutommi\Service\UcSrv\UcMiscSrv.c \
           plutommi\Service\UcSrv\UcPcrdSrv.c
endif

ifneq ($(filter __MMI_IMPS__ , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\ImpsSrv\ImpsChatSrv.c \
            plutommi\Service\ImpsSrv\ImpsDataSrv.c \
            plutommi\Service\ImpsSrv\ImpsFmSrv.c \
            plutommi\Service\ImpsSrv\ImpsGroupSrv.c \
            plutommi\Service\ImpsSrv\ImpsInviteSrv.c \
            plutommi\Service\ImpsSrv\ImpsMainSrv.c \
            plutommi\Service\ImpsSrv\ImpsPaSrv.c
endif

ifneq ($(filter __MMI_EBOOK_READER__ , $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\Service\EbrSrv\EbrSrv.c \
                plutommi\Service\EbrSrv\ebookframework.c
endif

ifneq ($(filter __MMI_PUSH_TURN_ON_OFF_SWITCH__ , $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\Service\PushSwitchSrv\PushSwitchSrv.c
endif

SRC_LIST += plutommi\Service\TodoSrv\TodolistSrv.c \
           plutommi\Service\CphsSrv\CphsSrv.c

SRC_LIST += plutommi\Service\FileMgrSrv\FileMgrSrvAsyncFS.c \
           plutommi\Service\FileMgrSrv\FileMgrSrvCommon.c \
           plutommi\Service\FileMgrSrv\FileMgrSrvFileInfo.c \
           plutommi\Service\FileMgrSrv\FileMgrSrvFileList.c \
           plutommi\Service\FileMgrSrv\FileMgrSrvFolderFL.c \
           plutommi\Service\FileMgrSrv\FileMgrSrvNotification.c \
           plutommi\Service\FileMgrSrv\FileMgrSrvPath.c \
           plutommi\Service\FileMgrSrv\FileMgrSrvStorage.c \
           plutommi\Service\FileMgrSrv\FileMgrSrvTypes.c \
           plutommi\Service\FileMgrSrv\FileMgrSrvTest.cpp \
           plutommi\Service\FileMgrSrv\FileMgrSrvTestItems.cpp

ifneq ($(filter __MMI_FMGR_CUSTICON_SUPPORT__ , $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\Service\FileMgrSrv\FileMgrSrvCustIcon.c
endif

SRC_LIST += plutommi\Service\PhbSrv\PhbSrv.c \
           plutommi\Service\PhbSrv\PhbStartupSrv.c \
           plutommi\Service\PhbSrv\PhbAtSrv.c \
           plutommi\Service\PhbSrv\PhbOplibSrv.c \
           plutommi\Service\PhbSrv\PhbSseSrv.c \
           plutommi\Service\PhbSrv\PhbDmgrSrv.c \
           plutommi\Service\PhbSrv\PhbXmgntSrv.c \
           plutommi\Service\PhbSrv\PhbMemSrv.c \
           plutommi\Service\PhbSrv\PhbUtilSrv.c \
           plutommi\Service\PhbSrv\PhbSdkSrv.c \
           plutommi\Service\PhbSrv\PhbContactSrv.c \
           plutommi\Service\PhbSrv\PhbPhoneSrv.c \
           plutommi\Service\PhbSrv\PhbSimSrv.c \
           plutommi\Service\PhbSrv\PhbGroupSrv.c \
           plutommi\Service\PhbSrv\PhbOPSrv.c \
           plutommi\Service\PhbSrv\PhbSettingSrv.c \
           plutommi\Service\PhbSrv\PhbJavaHandlerSrv.c \
           plutommi\Service\PhbSrv\PhbPBAPSrv.c \
           plutommi\Service\PhbSrv\PhbCloudSrv.c \
           plutommi\Service\PhbSrv\PhbTcardSrv.c \
           plutommi\Service\PhbSrv\datamgr.c \
           plutommi\Service\UcmSrv\UcmSrvAtHdlr.c \
           plutommi\Service\UcmSrv\UcmSrvMain.c \
           plutommi\Service\UcmSrv\UcmSrvUtil.c \
           plutommi\Service\UcmSrv\UcmSrvPrmt.c \
           plutommi\Service\UcmSrv\UcmSrvInterface.c \
           plutommi\Service\UcmSrv\UcmSrvIntInterface.c

SRC_LIST += plutommi\Service\SmsSrv\SmsInitSrv.c \
           plutommi\Service\SmsSrv\SmsDispatchSrv.c \
           plutommi\Service\SmsSrv\SmsQueueSrv.c \
           plutommi\Service\SmsSrv\SmsReceiverSrv.c \
           plutommi\Service\SmsSrv\SmsSenderSrv.c \
		   plutommi\Service\SmsSrv\SmsStorageCoreSrv.c \
           plutommi\Service\SmsSrv\SmsStorageInterfaceSrv.c \
           plutommi\Service\SmsSrv\SmsStorageMsgSrv.c \
           plutommi\Service\SmsSrv\SmsFolderListSrv.c \
           plutommi\Service\SmsSrv\SmsStatusReportSrv.c \
           plutommi\Service\SmsSrv\SmsAtHandlerSrv.c \
           plutommi\Service\SmsSrv\SmsConverterSrv.c \
           plutommi\Service\SmsSrv\SmsEmsSrv.c \
           plutommi\Service\SmsSrv\SmsUtilSrv.c \
           plutommi\Service\SmsSrv\SmsSettingSrv.c \
           plutommi\Service\SmsSrv\SmsStorageTcardSrv.c \
           plutommi\Service\SmsSrv\SmsBackupRestoreSrv.c \
           plutommi\Service\SmsSrv\CBSMainSrv.c \
           plutommi\Service\SmsSrv\CBSStorageSrv.c \
           plutommi\Service\TcardSrv\Tcard_config.c \
           plutommi\Service\TcardSrv\TcardMainsrv.c \
           plutommi\Service\TcardSrv\TcardUtilSrv.c \
           plutommi\Service\SmsSrv\CBSSettingSrv.c

ifneq ($(filter __SRV_SMS_BACKGROUND_SEND_SUPPORT__  , $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\Service\SmsSrv\SmsSendfromStorageSrv.c
endif

ifneq ($(filter __SRV_SMS_SIM_CUST_DATA__  , $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\Service\SmsSrv\SmsStorageSimCustSrv.c
endif

ifneq ($(filter __SRV_SMS_ARCHIVE__  , $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\Service\SmsSrv\SmsArchiveSrv.c
endif

SRC_LIST += plutommi\service\gsm3gcallsrv\GCallSrvCmEvent.c \
           plutommi\service\gsm3gcallsrv\GCallSrvCmInterface.c \
           plutommi\service\gsm3gcallsrv\GCallSrvPsEvent.c \
           plutommi\service\gsm3gcallsrv\GCallSrvPsInterface.c \
           plutommi\service\gsm3gcallsrv\GCallSrvStructMgmt.c \
           plutommi\service\gsm3gcallsrv\GCallSrvUtil.c \
           plutommi\service\Dtcntsrv\DtcntSrvApi.c \
           plutommi\service\Dtcntsrv\DtcntSrvDb.c \
           plutommi\service\Dtcntsrv\DtcntSrvMain.c \
           plutommi\Service\BootupSrv\BootupSrv.c \
           plutommi\Service\BootupSrv\BootupSrvProtocol.c \
           plutommi\Service\BootupSrv\BootupSrvSecurity.c \
           plutommi\Service\BootupSrv\BootupSrvCancelVeri.c \
           plutommi\Service\SimCtrlSrv\SimCtrlSrv.c \
           plutommi\Service\SimCtrlSrv\SimCtrlSrvAdp.c \
           plutommi\Service\SimCtrlSrv\SimCtrlSrvVeri.c \
           plutommi\Service\NwInfoSrv\NwInfoSrv.c \
           plutommi\Service\NwInfoSrv\NwInfoSrvAttach.c \
           plutommi\Service\NwInfoSrv\NwInfoSrvSignal.c \
           plutommi\Service\ShutdownSrv\ShutdownSrv.c \
           plutommi\Service\gpioSrv\gpioBacklightSrv.c \
           plutommi\Service\gpioSrv\Gpiosrv.c \
           plutommi\Service\gpioSrv\gpiospeechsrv.c \
           plutommi\Service\gpioSrv\gpiosrvsetting.c \
           plutommi\Service\CallSetSrv\CallSetSrvInterface.c \
           plutommi\Service\CallSetSrv\CallSetSrvStructMgmt.c \
           plutommi\Service\CallSetSrv\CallSetSrvUtil.c \
           plutommi\Service\CallSetSrv\BgSoundSrvUtils.c \
           plutommi\Service\SsSrv\SsSrvInterface.c \
           plutommi\Service\SsSrv\SsSrvOperation.c \
           plutommi\Service\SsSrv\SsSrvStructMgmt.c \
           plutommi\Service\SsSrv\SsSrvUtil.c \
           plutommi\Service\CbmSrv\CbmSrvInterface.c \
           plutommi\Service\CbmSrv\CbmSrvMain.c \
           plutommi\Service\CbmSrv\CbmSrvMsgHdlr.c \
           plutommi\Service\CbmSrv\CbmSrvWlanPrefer.c \
           plutommi\Service\SatSrv\SatSrv.c \
           plutommi\Service\SatSrv\SatCommandSrv.c \
           plutommi\Service\SatSrv\SatIconSrv.c \
           plutommi\Service\SimAccessSrv\SimAccessSrv.c \
           plutommi\Service\NetSetSrv\NetSetSrvMsgQueue.c \
           plutommi\Service\NetSetSrv\plmnname.c \
           plutommi\Service\NetSetSrv\NetSetSrv.c \
           plutommi\Service\ModeSwitchSrv\ModeSwitchSrv.c \
           plutommi\Service\NwUsabSrv\NwUsabSrv.c \
           plutommi\Service\SettingSrv\PenCalibrationSrv.c \
           plutommi\Service\SettingSrv\GeneralSettingSrv.c \
           plutommi\Service\SettingSrv\RestoreSrv.c \
           plutommi\Service\EonsSrv\EonsSrvMain.c \
           plutommi\Service\NwNameSrv\NwNameSrvMain.c \
           plutommi\Service\NwNameSrv\NwNameSrvSpdi.c \
           plutommi\Service\NwNameSrv\NwNameSrvCphs.c \
           plutommi\Service\ImeiSrv\ImeiSrv.c \
           plutommi\Service\SafeModeSrv\SafeModeSrv.c \
           plutommi\Service\ProfilesSrv\ProfilesSrvMain.c \
           plutommi\Service\CallLogSrv\CallLogSrvAtCmd.c \
           plutommi\Service\CallLogSrv\CallLogSrvComp.c \
           plutommi\Service\CallLogSrv\CallLogSrvIdxTbl.c \
           plutommi\Service\CallLogSrv\CallLogSrvIf.c \
           plutommi\Service\CallLogSrv\CallLogSrvJobHdlr.c \
           plutommi\Service\CallLogSrv\CallLogSrvMain.c \
           plutommi\Service\CallLogSrv\CallLogSrvPhbSync.c \
           plutommi\Service\CallLogSrv\CallLogSrvPsAdp.c \
           plutommi\Service\CallLogSrv\CallLogSrvSiTbl.c \
           plutommi\Service\CallLogSrv\CallLogSrvStore.c \
           plutommi\Service\CallLogSrv\CallLogSrvUtils.c \
           plutommi\Service\vCalSrv\vCalSrv.c \
           plutommi\Service\SecSetSrv\SecSetSrvPhone.c \
           plutommi\service\MediaCacheSrv\MediaCacheDaemon.c \
           plutommi\Service\CharBatSrv\CharBatSrv.c \
           plutommi\Service\UriAgentSrv\UriAgentSrv.c \
           plutommi\Service\UriAgentSrv\UriAgentSrvUtil.c \
           plutommi\service\mdi\mdisrc\mdi_audio.c \
           plutommi\service\mdi\mdisrc\mdi_common.c \
           plutommi\service\mdi\mdisrc\mdi_mtv.c \
           plutommi\service\mdi\mdisrc\mdi_swflash.c \
           plutommi\service\mdi\mdisrc\mdi_video.c \
           plutommi\service\mdi\mdisrc\mdi_video_rec.c \
           plutommi\service\mdi\mdisrc\mdi_video_clip.c \
           plutommi\service\mdi\mdisrc\mdi_gps.c \
           plutommi\service\mdi\mdisrc\mdi_agps.c \
           plutommi\service\mdi\mdisrc\mdi_bitstream.c \
           plutommi\Service\ReminderSrv\ReminderSrv.c \
           plutommi\Service\ReminderSrv\ReminderSrvUtil.c \
           plutommi\Service\ReminderSrv\ReminderSrvQueue.c \
           plutommi\Service\AppMgrSrv\AppMgrSrv.c \
           plutommi\Service\NativeAppFactorySrv\NativeAppFactorySrv.c \
           plutommi\Service\AlarmSrv\AlarmSrv.c \
           plutommi\Service\SoundRecSrv\SoundRecSrv.c \
           plutommi\Service\SoundEffectSrv\SoundEffectSrv.c \
           plutommi\Service\MRESrv\MRESrv.c \
           plutommi\Service\MRESrv\MRESrvDownload.c \
           plutommi\Service\MREAppMgrSrv\MREAppMgrSrv.c \
           plutommi\Service\MREPushSrv\MREPushSrv.c \
           plutommi\Service\MREPushSrv\MREPushUISrv.c\
           plutommi\Service\CnmgrSrv\CnmgrSrvMain.c \
           plutommi\Service\DmSRsrv\DmSelfRegister.c \
           plutommi\Service\RightsMgr\RightsMgrSrv.c \
           plutommi\Service\MASSrv\MASSrv.c \
           plutommi\Service\DataLockSrv\DataLockSrv.c\
           plutommi\Service\NotificationSettingSrv\NotificationSettingSrvTbl.c \
           plutommi\Service\NotificationSettingSrv\NotificationSettingSrv.c \
           plutommi\Service\UpgradeSrv\UpgradeSrvMain.c \
           plutommi\Service\UpgradeSrv\UpgradeSrvUtil.c

ifneq ($(filter __MMI_NITZ__ ,$(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\service\NITZSrv\NITZSrv.c
endif

# MDI
ifneq ($(filter __MMI_CAMERA__ __MMI_CAMCORDER__,$(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\service\mdi\mdisrc\mdi_camera.c
endif

ifneq ($(filter __MMI_WEBCAM__,$(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\service\mdi\mdisrc\mdi_webcam.c
endif


ifneq ($(filter __WAP_PUSH_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\WapPushSrv\WAPPushSrvMain.c
SRC_LIST += plutommi\Service\WapPushSrv\WAPPushSrvPmgInterface.c
SRC_LIST += plutommi\Service\WapPushSrv\WAPPushSrvSettings.c
ifneq ($(filter __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__,$(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\WapPushSrv\WAPPushSrvProv.c
endif
endif

ifneq ($(filter __MMI_USB_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\UsbSrv\usbsrv.c
endif

SRC_LIST += plutommi\Service\BtAudioSrv\BtAudioSrv.c
ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
    SRC_LIST += plutommi\Service\BtcmSrv\BtcmSrvInterface.c \
                plutommi\Service\BtcmSrv\BtcmSrvMain.c \
                plutommi\Service\BtcmSrv\BtcmSrvPrmt.c
                
    ifneq ($(filter __BT_DIALER_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\Service\DialerSrv\BTDialerSrv.c
    endif  
    
    ifneq ($(filter __BT_MAP_CLIENT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\Service\MapcSrv\MapcSrv.c \
                    plutommi\Service\MapcSrv\MapObjSrv.c         
    endif                
    ifneq ($(filter __MMI_HFP_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\Service\BthfSrv\BthfSrv.c
    endif
    ifneq ($(filter __MMI_BPP_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\Service\BppSrv\BppSrv.c
    endif
    ifneq ($(filter __MMI_SPP_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\Service\SppSrv\SppSrv.c
    endif
    ifneq ($(filter __MMI_OPP_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\service\oppsrv\OppSrv.c
    endif
    ifneq ($(filter __MMI_BIP_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\service\BipSrv\BipSrv.c
    endif
    ifneq ($(filter __MMI_PBAP_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\service\PbapSrv\PbapSrv.c
    endif
    ifneq ($(filter __BT_PBAP_CLIENT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\service\PbapSrv\PbapcSrv.c
    endif    
    ifneq ($(filter __BT_PBAP_CLIENT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\service\PhbSrv\PhbpbapcSrv.c
    endif
    ifneq ($(filter __MMI_FTC_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\Service\FtpSrv\FtpSrv.c
    else
        ifneq ($(filter __MMI_FTS_SUPPORT__, $(strip $(MODULE_DEFS))),)
            SRC_LIST += plutommi\Service\FtpSrv\FtpSrv.c
        endif
    endif
    ifneq ($(filter __MMI_FTC_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\Service\FtpSrv\FtpcSrv.c
    endif
    ifneq ($(filter __MMI_FTS_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\Service\FtpSrv\FtpsSrv.c
    endif
    ifneq ($(filter __MMI_BT_AUDIO_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\Service\BthScoPathSrv\BthScoPathSrv.c
    endif
    ifneq ($(filter __MMI_A2DP_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\Service\A2dpSrv\A2dpSrv.c
    endif
    ifneq ($(filter __MMI_AVRCP_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\Service\AvrcpSrv\AvrcpSrv.c
    endif
endif

ifneq ($(filter __CCA_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\service\Dtcntsrv\DtcntSrvProv.c
endif
ifneq ($(filter __MMI_WLAN_FEATURES__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\service\Dtcntsrv\DtcntSrvWlan.c
endif
ifneq ($(filter __CCA_SUPPORT__, $(strip $(MODULE_DEFS))),)
  ifneq ($(filter __MMI_WLAN_FEATURES__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\service\Dtcntsrv\DtcntSrvWlanOtap.c
  endif
endif

ifneq ($(filter __MMI_SRV_MEDIACACHE__, $(strip $(MODULE_DEFS))),)
       SRC_LIST += plutommi\service\MediaCacheSrv\MediaCacheSrv.c
endif

ifneq ($(filter __GADGET_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\WgtMgrSrv\WgtMgrSrvData.c \
           plutommi\Service\WgtMgrSrv\WgtMgrSrvMain.c \
           plutommi\Service\WgtMgrSrv\WgtMgrSrvMsgHdlr.c \
           plutommi\Service\WgtMgrSrv\WgtMgrSrvAdp.cpp \
           plutommi\Service\WgtMgrSrv\WgtAppFactorySrv.c
endif

ifneq ($(filter __MMI_CLOG_GPRS_COUNT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\Service\CallLogSrv\CallLogSrvGprsCount.c
endif
ifneq ($(filter __MMI_CLOG_CALL_COST__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\Service\CallLogSrv\CallLogSrvCallCost.c
endif
ifneq ($(filter __MMI_CLOG_CALL_TIME__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\Service\CallLogSrv\CallLogSrvCallTime.c
endif
ifneq ($(filter __MMI_CLOG_SIM_SYNC_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\Service\CallLogSrv\CallLogSrvSimSync.c
endif

ifneq ($(filter __CCA_SUPPORT__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\Service\CcaSrv\CcaSrvConfig.c \
             plutommi\Service\CcaSrv\CcaSrvDispatcher.c \
             plutommi\Service\CcaSrv\CcaSrvDoc.c \
             plutommi\Service\CcaSrv\CcaSrvDm.c \
             plutommi\Service\CcaSrv\CcaSrvMain.c \
             plutommi\Service\CcaSrv\CcaSrvOma.c \
             plutommi\Service\CcaSrv\CcaSrvProvBox.c \
             plutommi\Service\CcaSrv\CcaSrvSpa.c \
             plutommi\Service\CcaSrv\CcaSrvUtils.c
endif

ifneq ($(filter __MMI_BROWSER_2__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\BrowserSrv\BrowserSrvMain.c
SRC_LIST += plutommi\Service\BrowserSrv\BrowserSrvSettings.c
SRC_LIST += plutommi\Service\BrowserSrv\BrowserSrvBookmarks.c
SRC_LIST += plutommi\Service\BrowserSrv\BrowserSrvInterface.c
SRC_LIST += plutommi\Service\BrowserSrv\BrowserSrvMain.c
SRC_LIST += plutommi\Service\BrowserSrv\BrowserSrvMsgHdlr.c
SRC_LIST += plutommi\Service\BrowserSrv\BrowserSrvSettings.c
endif

ifneq ($(filter __CTM_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\service\ctmsrv\CtmSrv.c
endif

ifneq ($(filter __PLST_SERVICE_DB_SUPPORT__ __MMI_MOT_SUPPORT__,$(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\PlstSrv\PlstSrvMain.c
endif

ifneq ($(filter __MMI_PLAYLIST_SERVICE_SLIM__,$(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\Service\PlstSlimSrv\MusicPlaylist.c
else
ifneq ($(filter __PLST_SERVICE_DB_SUPPORT__,$(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\PlstSrv\PlstSrvsql.c
SRC_LIST += plutommi\Service\PlstSrv\PlstSrv.c
SRC_LIST += plutommi\Service\PlstSrv\PlstSrvpls.c
endif
endif

ifneq ($(filter __MMI_MOT_SUPPORT__,$(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\MotSrv\MotSrv.c
endif

SRC_LIST += plutommi\Service\SensorSrv\SensorSrv.c

ifeq ($(strip $(CLOUD_SUPPORT)),SOURCE)
SRC_LIST += plutommi\Service\CloudSrv\BackupRestoreSrvApi.c \
            plutommi\Service\CloudSrv\BackupRestoreSrvCard.c \
            plutommi\Service\CloudSrv\BackupRestoreSrvSms.c \
            plutommi\Service\CloudSrv\BackupRestoreSrvScheduler.c
endif

ifneq ($(filter __MMI_EMAIL__ , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\EmailSrv\EmailSrvAccount.c \
            plutommi\Service\EmailSrv\EmailSrvFolder.c \
            plutommi\Service\EmailSrv\EmailSrvMessage.c \
            plutommi\Service\EmailSrv\EmailSrvAsyncFS.c \
            plutommi\Service\EmailSrv\EmailSrvComposer.c \
            plutommi\Service\EmailSrv\EmailSrvStorage.c \
            plutommi\Service\EmailSrv\EmailSrvStorFS.c \
            plutommi\Service\EmailSrv\EmailSrvStorFSAcct.c \
            plutommi\Service\EmailSrv\EmailSrvStorFSFldr.c \
            plutommi\Service\EmailSrv\EmailSrvStorFSMsg.c \
            plutommi\Service\EmailSrv\EmailSrvScheduler.c \
            plutommi\Service\EmailSrv\EmailSrvObject.c \
            plutommi\Service\EmailSrv\EmailSrvUtil.c \
            plutommi\Service\EmailSrv\EmailSrvMain.c \
            plutommi\Service\EmailSrv\EmailSrvNetwork.c \
            plutommi\Service\EmailSrv\EmailSrvNetworkMain.c \
            plutommi\Service\EmailSrv\EmailSrvNetworkFSM.c \
            plutommi\Service\EmailSrv\EmailSrvNetworkPS.c \
            plutommi\Service\EmailSrv\EmailSrvSMTP.c \
            plutommi\Service\EmailSrv\EmailSrvPOP3.c \
            plutommi\Service\EmailSrv\EmailSrvIMAP4.c \
            plutommi\Service\EmailSrv\EmailSrvEMN.c \
            plutommi\Service\EmailSrv\EmailSrvOTAP.c
ifeq ($(strip $(CLOUD_SUPPORT)),SOURCE)
SRC_LIST += plutommi\Service\EmailSrv\EmailSrvSso.c
endif
endif

ifneq ($(filter __MMI_PROV_MESSAGE_SUPPORT__ , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\ProvBoxSrv\ProvBoxSrvFile.c \
            plutommi\Service\ProvBoxSrv\ProvBoxSrvMain.c \
            plutommi\Service\ProvBoxSrv\ProvBoxSrvMisc.c \
            plutommi\Service\ProvBoxSrv\ProvBoxSrvMsgHdlr.c \
            plutommi\Service\ProvBoxSrv\ProvBoxSrvMsgList.c
endif

ifneq ($(filter __SCALADO_SUPPORT__ , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\ImgEdtSrv\ImgEdtSrvApp.c \
            plutommi\Service\ImgEdtSrv\ImgEdtSrvTask.c \
            plutommi\Service\ImgEdtSrv\ImgEdtSrvCore.c \
            plutommi\Service\ImgEdtSrv\ImgEdtSrvEffect.c \
            plutommi\Service\ImgEdtSrv\ImgEdtSrvMeta.c \
            plutommi\Service\ImgEdtSrv\ImgEdtSrvUtil.c \
            plutommi\Service\ImgEdtSrv\ImgEdtSrvTest.cpp \
            plutommi\Service\ImgEdtSrv\ImgEdtSrvTestItems.cpp
endif


ifneq ($(filter __MMI_QUERY_SRV__ , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\GetSrvSrv\gs_memory.c \
            plutommi\Service\GetSrvSrv\gs_cbase.cpp \
            plutommi\Service\GetSrvSrv\gs_core.cpp \
            plutommi\Service\GetSrvSrv\gs_srv_ebook\gs_srv_ebook.cpp \
            plutommi\Service\GetSrvSrv\gs_proxy.cpp \
            plutommi\Service\GetSrvSrv\gs_srv_bitstreamaudio\gs_srv_bitstreamaudio.cpp \
            plutommi\Service\GetSrvSrv\gs_srv_bitstreamrecord\gs_srv_bitstreamrecord.cpp \
            plutommi\Service\GetSrvSrv\gs_srv_idlescreen\gs_srv_idlescreen.cpp \
            plutommi\Service\GetSrvSrv\gs_srv_imageviewer\gs_srv_imageviewer.cpp \
            plutommi\Service\GetSrvSrv\gs_srv_mmvideo\gs_srv_mmvideo.cpp \
            plutommi\Service\GetSrvSrv\gs_srv_profile\gs_srv_profile.cpp \
            plutommi\Service\GetSrvSrv\gs_srv_videopdl\gs_srv_videopdl.cpp \
            plutommi\Service\GetSrvSrv\gs_srv_videorecord\gs_srv_videorecord.cpp \
            plutommi\Service\GetSrvSrv\gs_srv_videostream\gs_srv_videostream.cpp \
            plutommi\Service\GetSrvSrv\gs_srv_ucm\gs_srv_ucm.cpp \
            plutommi\Service\GetSrvSrv\gs_srv_um\gs_srv_um.cpp \
            plutommi\Service\GetSrvSrv\gs_srv_mms\gs_srv_mms.cpp\
            plutommi\Service\GetSrvSrv\gs_srv_email\gs_srv_email.cpp \
	    plutommi\Service\GetSrvSrv\gs_srv_appmgr\gs_srv_appmgr.cpp\
            plutommi\Service\GetSrvSrv\gs_srv_ncenter\gs_srv_ncenter.cpp #need to merge
endif

ifneq ($(filter __COSMOS_MMI__  , $(strip $(MODULE_DEFS))),)
ifneq ($(filter __SYNCML_SUPPORT__  , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\SyncSrv\SyncSrv.c	\
            plutommi\Service\SyncSrv\SyncSrvAccnt.c	\
            plutommi\Service\SyncSrv\SyncSrvChangeLog.c	\
            plutommi\Service\SyncSrv\SyncSrvListener.c	\
            plutommi\Service\SyncSrv\SyncSrvMsg.c	\
            plutommi\Service\SyncSrv\SyncSrvUT.c	\
            plutommi\Service\SyncSrv\SyncSrvCm.c	\
            plutommi\Service\SyncSrv\SyncSrvCmCbm.c	\
            plutommi\Service\SyncSrv\Sync\SyncSrvRemoteAccnt.c	\
            plutommi\Service\SyncSrv\Sync\SyncSrvRemoteSync.c	\
            plutommi\Service\SyncSrv\Sync\SyncSrvRemoteEvtHandlr.c	\
            plutommi\Service\SyncSrv\Sync\SyncSrvRemoteRegularSync.c	\
            plutommi\Service\SyncSrv\Sync\SyncSrvSync.c	\
            plutommi\Service\SyncSrv\DataBase\SyncSrvDataBase.c	\
            plutommi\Service\SyncSrv\DataBase\SyncSrvDataBaseFactory.c	\
            plutommi\Service\SyncSrv\DataBase\SyncSrvDataBaseContact.c	\
            plutommi\Service\SyncSrv\DataBase\SyncSrvDataBaseContactChangeLog.c

ifneq ($(filter __MMI_SYNCML_CCA_SUPPORT__  , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\SyncSrv\Sync\SyncSrvRemoteAccntOta.c	\
            plutommi\Service\SyncSrv\Sync\SyncSrvRemoteAccntOtaParser.c
endif

ifneq ($(filter __SYNCML_DEVICE_SYNC__  , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\SyncSrv\SyncSrvCmBT.c	\
            plutommi\Service\SyncSrv\Sync\SyncSrvPhoneAccnt.c	\
            plutommi\Service\SyncSrv\Sync\SyncSrvPhoneSync.c
endif

ifneq ($(filter __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__  , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\SyncSrv\DataBase\SyncSrvDataBaseEvent.c	\
            plutommi\Service\SyncSrv\DataBase\SyncSrvDataBaseEventChangeLog.c
endif

ifneq ($(filter __MMI_SYNCML_SYNC_TASK_SUPPORT__  , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\SyncSrv\DataBase\SyncSrvDbTask.c	\
            plutommi\Service\SyncSrv\DataBase\SyncSrvDbTaskCLog.c
endif

ifneq ($(filter __MMI_SYNCML_SYNC_NOTE_SUPPORT__  , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\SyncSrv\DataBase\SyncSrvDbNote.c	\
            plutommi\Service\SyncSrv\DataBase\SyncSrvDbNoteCLog.c
endif
endif
endif

ifneq ($(filter __MMI_TETHERING__  , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\TetheringSrv\TetheringSrv.c
endif



ifneq ($(filter __MMI_DOWNLOAD_AGENT__ , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\DLAgentSrv\DLAgentSrvConfig.c \
            plutommi\Service\DLAgentSrv\DLAgentSrvDRM.c \
            plutommi\Service\DLAgentSrv\DLAgentSrvHttp.c \
            plutommi\Service\DLAgentSrv\DLAgentSrvOMA.c \
            plutommi\Service\DLAgentSrv\DLAgentSrvOMAUtil.c \
            plutommi\Service\DLAgentSrv\DLAgentSrvPush.c \
            plutommi\Service\DLAgentSrv\DLAgentSrvUtil.c \
            plutommi\Service\DLAgentSrv\DLAgentSrvWPS.c \
            plutommi\Service\DLAgentSrv\DLAgentSrvInterface.c \
            plutommi\Service\DLAgentSrv\DLAgentSrvMRE.c \
            plutommi\Service\DLAgentSrv\DLAgentSrvMsgHdlr.c \
            plutommi\Service\DLAgentSrv\DLAgentSrvHttpDL.c

endif

ifneq ($(filter __J2ME__ , $(strip $(MODULE_DEFS))),)  
SRC_LIST += plutommi\Service\JavaAppFactorySrv\JavaAppFactorySrv.c
endif

ifneq ($(filter __NTPD_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\NtpSrv\NtpSrvMain.c
endif

ifneq ($(filter SYNCML_DM_SUPPORT, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\service\dmsrv\dmsrvmain.c \
                plutommi\service\dmsrv\dmsrvacc.c \
                plutommi\service\dmsrv\dmsrvsession.c \
                plutommi\service\dmsrv\dmsrvutil.c \
                plutommi\service\dmsrv\dmsrvdl.c \
                plutommi\service\dmsrv\dmsrvappadp.c
    ifneq ($(filter __CCA_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\service\dmsrv\dmsrvotap.c
    endif

    ifneq ($(filter __DM_LAWMO_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\service\dmsrv\dmsrvlawmo.c
    endif

    ifneq ($(filter __DM_SCOMO_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\service\dmsrv\dmsrvscomo.c
    endif

    ifneq ($(filter __DM_FOTA_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\service\dmsrv\dmsrvfota.c
    endif
endif

ifneq ($(filter __SOCIAL_NETWORK_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\SnsSrv\plugin\renren\RR_vpp.c
endif

ifneq ($(filter __FACEBOOK_SNS_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\SnsSrv\plugin\facebook\FB_vpp.c
endif

ifneq ($(filter __TWITTER_SNS_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\SnsSrv\plugin\twitter\TW_vpp.c
endif

ifneq ($(filter __BT_MAP_CLIENT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\Service\SmsBtmapcSrv\SmsBtMapCSrvCore.c \
            plutommi\Service\SmsBtmapcSrv\SmsBtMapCSrvFolderList.c \
            plutommi\Service\SmsBtmapcSrv\SmsBtMapCSrvParser.c \
            plutommi\Service\SmsBtmapcSrv\SmsBtMapCSrvStorage.c \
            plutommi\Service\SmsBtmapcSrv\SmsBtMapCSrvStorageCore.c \
            plutommi\Service\SmsBtmapcSrv\SmsBtMapCSrvConverter.c \
            plutommi\Service\SmsBtmapcSrv\SmsBtMapCSrvUtil.c 
endif            
            
# Define include path lists to INC_DIR
INC_DIR = hal\video\demuxer\provider\inc \
          custom\video \
          drm\include \
          gps\inc \
          irda\inc \
          j2me\interface \
          j2me\jal\include \
          j2me\jal\include \
          media\image\include \
          media\rtp\inc \
          media\stream\include \
          media\mtv\src \
          media\mtv\include \
          usb\include \
          verno \
          wapadp\include \
          xmlp\include \
          applib\inet\engine\include \
          applib\mem\include \
          applib\misc\include \
          nvram\include \
          plutommi\customer\customerinc \
          plutommi\mmi\asyncevents\asynceventsinc \
          plutommi\mmi\inc \
          plutommi\Framework\Interface \
          plutommi\Framework\IndicLanguages\indiclanguagesinc \
          plutommi\Framework\CommonFiles\commoninc \
          plutommi\Framework\EventHandling\eventsinc \
          plutommi\Framework\History\historyinc \
          plutommi\Framework\Scenario \
          plutommi\Framework\MemManager\memmanagerinc \
          plutommi\Framework\NVRAMManager\nvrammanagerinc \
          plutommi\Framework\Tasks\tasksinc \
          plutommi\Framework\ThemeManager\thememanagerinc \
          plutommi\Framework\GUI\gui_inc \
          plutommi\Framework\GUI\oem_inc \
          plutommi\Framework\Fontengine \
          plutommi\mmi\miscframework\miscframeworkinc \
          plutommi\Framework\InputMethod\Inc \
          plutommi\Framework\GDI\gdiinc \
          plutommi\service\mdi\mdiinc \
          plutommi\mmi\Organizer\OrganizerInc \
          plutommi\mmi\datetime\datetimeinc \
          plutommi\Framework\DebugLevels\debuglevelinc \
          plutommi\mmi\setting\settinginc \
          plutommi\service\Inc \
          plutommi\service\UmSrv \
          plutommi\Service\UcSrv \
          plutommi\MMI\UnifiedComposer\UnifiedComposerInc \
          plutommi\Service\DtcntSrv \
          plutommi\mtkapp\filemgr\filemgrinc \
          plutommi\Service\UmmsSrv \
          plutommi\mmi\UnifiedMMS\MMSApp\MMSAppInc \
          plutommi\mtkapp\JavaAgency\JavaAgencyInc \
          plutommi\MtkApp\Connectivity\ConnectivityInc \
          plutommi\MMI\BrowserApp\UPPApp\UPPAppInc \
          plutommi\Service\UriAgentSrv \
          plutommi\mtkapp\DMUIApp\DMUIAppInc \
          btstacka\inc \
          btadp\include \
          plutommi\mtkapp\MREAPP\MREAPPInc \
          venusmmi\app \
          venusmmi\framework \
          venusmmi\vrt\interface \
          vendor\widget\google\adaptation \
          plutommi\Framework\CommonScreens\commonscreensinc \
          plutommi\mmi\gpio\gpioinc \
          plutommi\mtkapp\audioplayer\audioplayerinc \
          plutommi\mtkapp\connectivity\connectivityinc \
          plutommi\mtkapp\connectivity\connectivityinc\btcommon \
          plutommi\mtkapp\connectivity\connectivityinc\btmtk \
          plutommi\mmi\phonebook\phonebookinc \
          plutommi\mmi\phonebook\core \
          plutommi\CUI\Inc \
          plutommi\mtkapp\mtkappinc \
          plutommi\mtkapp\syncml\syncmlinc \
          xmlp\include \
          vcard\include \
          wapadp\include \
          plutommi\MtkApp\vObjects\vObjectInc \
          plutommi\MtkApp\CentralConfigAgent\CentralConfigAgentInc \
          plutommi\mmi\Messages\MessagesInc \
          plutommi\MMI\Messages \
          plutommi\mmi\profiles\ProfilesInc \
          plutommi\MMI\IdleScreen\IdleScreenInc \
          plutommi\MMI\IdleScreen\IdleScreenInc\DemoAppInc \
          plutommi\mmi\Audio\AudioInc \
          plutommi\mmi\ebookreader\ebookinc \
          plutommi\service\UcmSrv \
          plutommi\mmi\gsmcallapplication\commonfiles\commoninc \
          plutommi\mmi\gsmcallapplication\incomingcallmanagement\incominginc \
          plutommi\mmi\gsmcallapplication\outgoingcallmanagement\outgoinginc \
          plutommi\mmi\cphs\cphsinc \
          plutommi\mtkapp\bgsound\bgsoundinc \
          plutommi\AppCore\ssc \
          plutommi\mtkapp\answermachine\answermachineinc \
          plutommi\MMI\VoIP\VoIPInc \
          plutommi\MtkApp\GPS\GPSInc \
          drm\include \
          plutommi\MMI\DataAccount\DataAccountInc \
          plutommi\VendorApp\DevConfig\DevConfigInc \
          $(strip $(PS_FOLDER))\smslib\include \
          $(strip $(PS_FOLDER))\l4\include \
          custom\common\pluto_mmi \
          custom\common\VENUS_MMI \
          custom\common\hal_public \
          interface\media \
          interface\ps\include \
          interface\ps\enum \
          plutommi\mmi\sat\satinc \
          plutommi\service\Gsm3GCallSrv \
          plutommi\service\CtmSrv \
          $(strip $(PS_FOLDER))\l4\csm\cc\include \
          $(strip $(PS_FOLDER))\interfaces\enum \
          plutommi\service\WapPushSrv \
          plutommi\mmi\BrowserApp\PushInbox\PushInboxInc \
          plutommi\mmi\emailapp\emailappinc \
          plutommi\Service\EmailSrv \
          plutommi\Service\CloudSrv \
          applib\sqlite3\inc \
          plutommi\MtkApp\Camera\CameraInc \
          plutommi\mtkapp\mediaplayer\mediaplayerinc \
          plutommi\mtkapp\rightsmgr\rightsmgrinc \
          plutommi\Service\PlstSrv \
          plutommi\Service\PlstSlimSrv \
          plutommi\MtkApp\WidgetDelegator\WidgetDelegatorInc \
          plutommi\MMI\NITZHandler\NITZInc \
          plutommi\Service\AppMgrSrv \
          plutommi\Service\NativeAppFactorySrv \
          plutommi\Service\ProfilesSrv \
          plutommi\Service\SoundEffectSrv \
          plutommi\Service\SoundRecSrv \
          plutommi\Service\BthScoPathSrv \
          plutommi\Service\A2dpSrv \
          plutommi\Service\AvrcpSrv \
          plutommi\mtkapp\fmradio\fmradioinc \
          plutommi\mmi\ATHandler\ATHandlerInc \
          plutommi\MMI\MiscFramework\MiscFrameworkInc \
          plutommi\MMI\Idle\IdleInc \
          plutommi\service\NetSetSrv \
          plutommi\service\ModeSwitchSrv \
          plutommi\service\BrowserSrv \
          plutommi\mmi\BrowserApp\Browser\BrowserInc \
          plutommi\mmi\DataAccount\DataAccountInc \
          vendor\wap\obigo_Q05A\adaptation\modules\bam\include \
          interface\wap \
          plutommi\MtkApp\DLAgent\DLAgentInc \
          plutommi\service\CallLogSrv \
          plutommi\Service\CcaSrv \
          plutommi\mmi\SIMProvAgent\SIMProvAgentInc \
          plutommi\mmi\connectmanagement\connectmanagementinc \
          plutommi\Service\vCalSrv \
          plutommi\Service\CharBatSrv \
          venusmmi\app\Cosmos\Dataaccount \
          plutommi\Service\ProvBoxSrv \
          vendor\player\ipeer\inc \
          vendor\player\ipeer\adaptation\inc \
          vendor\scalado\include \
          vendor\wap\obigo_Q03C\adaptation\integration\include \
          verno \
          interface\hal \
          interface\hal\video \
          interface\inet_ps \
          venusmmi\app\Cosmos\interface\app \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel\HomeScreen \
          venusmmi\app\pluto_variation\ShellApp\panel \
          venusmmi\app\pluto_variation\ShellApp\panel\HomeScreen \
          plutommi\Service\InetSrv \
          plutommi\Service\GetSrvSrv \
          plutommi\Service\Inc\Gsinc \
          interface\ps \
          interface\mmi \
          interface\hal\drv_sw_def \
          plutommi\Service\SyncSrv \
          plutommi\Service\SyncSrv\Database \
          plutommi\Service\SyncSrv\Sync \
          plutommi\Service\TetheringSrv \
          plutommi\Service\ProvisioningSrv \
          plutommi\Service\UPPSrv \
          plutommi\Service\PhbSrv \
          plutommi\Service\CnmgrSrv \
          plutommi\Service\ImgEdtSrv \
          plutommi\Service\UpgradeSrv \
          plutommi\Service\SsSrv \
          venusmmi\app\common\ime \
          venusmmi\framework\ui_core\mvc \
          venusmmi\framework\ui_core\pme \
          venusmmi\framework\ui_core\base \
          venusmmi\framework\mmi_core \
          plutommi\cui\fseditorcui \
          venusmmi\app\Cosmos\Calendar \
          venusmmi\app\Cosmos\JavaApp \
          plutommi\Service\DmSrv \
          plutommi\Service\DmSRsrv \
          interface\fota \
          btmt\rf_desense \
          venusmmi\app\cosmos\OPMmApp\
          venusmmi\app\pluto_variation\LauncherKey\OPMainmenu \
          inet_ps\ntpd\include \
          plutommi\Service\PnSrv \
          vendor\push_notification_engine\HPNSTask\inc \
          vendor\push_notification_engine\PnsLib\JsonParser \
          plutommi\Service\SppSrv \
          interface\hal\bluetooth \
          custom\common\hal_public \
          interface\media\video \
          vendor\sensor\mcube\inc\
          venusmmi\framework\interface \
          venusmmi\visual\cp \
          plutommi\mtkapp\video\videoinc \
          venusmmi\vrt\interface \
          venusmmi\app\common\ncenter \
          venusmmi\app\common\interface\app\
          plutommi\Service\TcardSrv \
          plutommi\Service\NotificationSettingSrv \
          plutommi\Service\SsoSrv\plugin\yahoo \
          hal\system\dcmgr\inc \
          plutommi\Service\MapcSrv \
          plutommi\Service\SmsbtmapcSrv \
          plutommi\Service\PbapSrv

ifeq ($(filter __MTK_TARGET__ , $(strip $(MODULE_DEFS))),)
INC_DIR += MoDIS_VC9\MoDIS  # for w32_utility.h
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

