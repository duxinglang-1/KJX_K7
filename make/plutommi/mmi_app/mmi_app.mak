# Define source file lists to SRC_LIST
SRC_LIST = plutommi\mmi\athandler\athandlersrc\athandler.c \
           plutommi\mmi\cphs\cphssrc\cphsprotocolhandlers.c \
           plutommi\mmi\cphs\cphssrc\csp.c \
           plutommi\mmi\cphs\cphssrc\infonum.c \
           plutommi\mmi\datetime\datetimesrc\datetime.c \
           plutommi\mmi\dictionary\dictsrc\dictionarymain.c \
           plutommi\mmi\extra\extrasrc\extra.c \
           plutommi\mmi\extra\extrasrc\ecompass.c \
           plutommi\mmi\gpio\gpiosrc\generaldeviceinterface.c \
           plutommi\mmi\gpio\gpiosrc\gpioapp.c \
           plutommi\mmi\gpio\gpiosrc\volumehandler.c

ifneq ($(filter __MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__ , $(strip $(MODULE_DEFS))),)
     SRC_LIST += plutommi\MMI\AppList\AppListSrc\AppList_video_decorder.c
endif
ifneq ($(filter __MMI_LAUNCHER_APP_LIST__ , $(strip $(MODULE_DEFS))),)
     SRC_LIST += plutommi\MMI\Idle\IdleSrc\IdleAppList.c \
                plutommi\MMI\AppList\AppListSrc\AppList.c \
                plutommi\MMI\AppList\AppListSrc\AppListData.c \
                plutommi\MMI\AppList\AppListSrc\AppListDraw.c \
                plutommi\MMI\AppList\AppListSrc\AppListVLW.c
endif
ifneq ($(filter __MMI_APPLIST_BARREL_SUPPORT__ , $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\MMI\AppList\AppListSrc\AppListBarrel.c
endif

ifneq ($(filter __MMI_EBOOK_READER__ , $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\mmi\ebookreader\ebooksrc\ebooksrc.c
endif

ifneq ($(filter __MMI_CALCULATOR__ , $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\mmi\extra\extrasrc\calculator.c
endif

ifneq ($(filter __MMI_OP11_HOMESCREEN__ , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mmi\idlescreen\idlescreensrc\idlehomescreen.c \
           plutommi\mmi\idlescreen\idlescreensrc\idlehomescreengprot.c
endif
SRC_LIST += plutommi\mmi\idlescreen\idlescreensrc\idlenotificationmanager.c \
           plutommi\mmi\idlescreen\idlescreensrc\idlenotificationmanagerconfig.c \
           plutommi\mmi\idlescreen\idlescreensrc\idlerecentevent.c
ifneq ($(filter __MMI_OP11_HOMESCREEN_0301__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\mmi\idlescreen\idlescreensrc\HomeScreenOp11V32.c
else
  ifneq ($(filter __MMI_OP11_HOMESCREEN_0302__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\mmi\idlescreen\idlescreensrc\HomeScreenOp11V32.c
  endif
endif
SRC_LIST += plutommi\mmi\Factory\FactorySrc\Factory.c \
           plutommi\mmi\Idle\IdleSrc\IdleAdapter.c \
           plutommi\mmi\Idle\IdleSrc\IdleMain.c \
           plutommi\mmi\Idle\IdleSrc\IdleCommon.c \
           plutommi\mmi\Idle\IdleSrc\IdleEventCfg.c \
           plutommi\mmi\Idle\IdleSrc\IdleSubLcd.c \
           plutommi\mmi\Idle\IdleSrc\IdleFactory.c \
           plutommi\mmi\Idle\IdleSrc\IdleObject.c \
           plutommi\mmi\Idle\IdleSrc\IdleClassic.c
ifneq ($(filter __MMI_VUI_SHELL_APP__ , $(strip $(MODULE_DEFS))),)
	SRC_LIST += plutommi\mmi\Idle\IdleSrc\IdleShell.c
endif
ifneq ($(filter __MMI_OP11_HOMESCREEN__ , $(strip $(MODULE_DEFS))),)
	SRC_LIST += plutommi\mmi\Idle\IdleSrc\IdleOp11v25.c
endif
ifneq ($(filter __MMI_OP11_HOMESCREEN_0301__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\mmi\Idle\IdleSrc\IdleOp11v32.c
else
  ifneq ($(filter __MMI_OP11_HOMESCREEN_0302__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\mmi\Idle\IdleSrc\IdleOp11v32.c
  endif
endif
ifneq ($(filter __MMI_VUI_LAUNCHER__ , $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\MMI\Idle\IdleSrc\IdleLauncher.c
endif
ifneq ($(filter __MMI_VUI_LAUNCHER_KEY__ , $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\MMI\Idle\IdleSrc\IdleLauncherKey.c
endif

SRC_LIST += plutommi\mmi\ScrSaver\ScrSaverSrc\ScrSaverAdapter.c \
           plutommi\mmi\ScrSaver\ScrSaverSrc\ScrSaverMain.c \
           plutommi\mmi\ScrSaver\ScrSaverSrc\ScrSaverFactory.c \
           plutommi\mmi\ScrSaver\ScrSaverSrc\ScrSaverObject.c
ifneq ($(filter __MMI_ANALOG_CLOCK__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\mmi\ScrSaver\ScrSaverSrc\ScrSaverClock.c
else
  ifneq ($(filter __MMI_DIGITAL_CLOCK__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\mmi\ScrSaver\ScrSaverSrc\ScrSaverClock.c
  endif
endif
SRC_LIST += plutommi\mmi\ScrSaver\ScrSaverSrc\ScrSaverMedia.c
ifneq ($(filter __MMI_LCD_PARTIAL_ON__ , $(strip $(MODULE_DEFS))),)
	SRC_LIST += plutommi\mmi\ScrSaver\ScrSaverSrc\ScrSaverTime.c
endif
ifneq ($(filter __MMI_THEMES_V2_SUPPORT__ , $(strip $(MODULE_DEFS))),)
	SRC_LIST += plutommi\mmi\ScrSaver\ScrSaverSrc\ScrSaverTheme.c
endif
SRC_LIST += plutommi\mmi\ScrLocker\ScrLockerSrc\ScrLockerMain.c \
           plutommi\mmi\ScrLocker\ScrLockerSrc\ScrLockerSos.c \
           plutommi\mmi\ScrLocker\ScrLockerSrc\ScrLockerFactory.c \
           plutommi\mmi\ScrLocker\ScrLockerSrc\ScrLockerObject.c \
           plutommi\mmi\ScrLocker\ScrLockerSrc\ScrLockerClassic.c
ifneq ($(filter __MMI_FANCY_SCREEN_LOCK__ , $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\mmi\ScrLocker\ScrLockerSrc\ScrLockerFancy.c
endif
ifneq ($(filter __MMI_VUI_SHELL_SCREEN_LOCK__ , $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\mmi\ScrLocker\ScrLockerSrc\ScrLockerShell.c
endif
ifneq ($(filter __DM_LAWMO_SUPPORT__ , $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\mmi\ScrLocker\ScrLockerSrc\ScrLockerLawmo.c
endif
ifneq ($(filter __MMI_VUI_SCREEN_LOCK_KEY__ , $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\mmi\ScrLocker\ScrLockerSrc\ScrlockerScreenLockKey.c
endif
ifneq ($(filter __MMI_VUI_SCREEN_LOCK_KEY__ , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mmi\setting\settingsrc\ScreenLockKeyImageSetting.c
endif
ifneq ($(filter __MMI_SCREEN_LOCK_CLASSIC_NEPTUNE_LIKE_BWUI__ , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mmi\ScrLocker\ScrLockerSrc\ScrLockerPopup.c
endif

SRC_LIST += plutommi\mmi\ScrLocker\ScrLockerSrc\ScrLockerSetting.c \
           plutommi\mmi\Dialer\DialerSrc\DialerMain.c \
           plutommi\CUI\DialerCui\DialerCuiMain.c \
           plutommi\CUI\DialerCui\DialerCuiCommon.c \
           plutommi\CUI\DialerCui\DialerCuiFactory.c \
           plutommi\CUI\DialerCui\DialerCuiObject.c \
           plutommi\CUI\DialerCui\DialerCuiClassic.c \
           plutommi\CUI\DialerCui\DialerCuiSos.c \
           plutommi\mmi\mainmenu\mainmenusrc\mainmenu.c

SRC_LIST += plutommi\mmi\messages\messagessrc\messagesmiscell.c \
           plutommi\mmi\messages\messagessrc\smsmomtguiinterface.c \
           plutommi\mmi\messages\messagessrc\smspshandler.c \
           plutommi\mmi\messages\messagessrc\SmsAppMainUI.c \
           plutommi\mmi\messages\messagessrc\SmsAppMsg.c \
           plutommi\mmi\messages\messagessrc\SmsAppSendMsg.c \
           plutommi\mmi\messages\messagessrc\SmsAppUM.c \
           plutommi\mmi\messages\messagessrc\SmsAppUmSap.c \
           plutommi\mmi\messages\messagessrc\SmsAppMisc.c \
           plutommi\mmi\messages\messagessrc\SmsAppCommonUI.c \
           plutommi\mmi\messages\messagessrc\SmsAppUtil.c \
           plutommi\mmi\messages\messagessrc\SmsAppSetting.c \
           plutommi\mmi\messages\messagessrc\Voicemail.c \
           plutommi\mmi\messages\messagessrc\CbsAppMain.c \
           plutommi\mmi\messages\messagessrc\CbsAppMsg.c
ifneq ($(filter __MMI_SMS_APP_EMS_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\mmi\messages\messagessrc\emsmiscell.c
else
  ifneq ($(filter __MMI_MESSAGES_EMS__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\mmi\messages\messagessrc\emsmiscell.c
  endif
endif
ifeq ($(filter __UNIFIED_COMPOSER_SUPPORT__ , $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\mmi\messages\messagessrc\SmsAppEditor.c
endif
ifneq ($(filter __MMI_SMS_APP_EMS_SUPPORT__ , $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\mmi\messages\messagessrc\SmsAppEms.c
endif
ifneq ($(filter __MMI_MESSAGES_TEMPLATE__ , $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\mmi\messages\messagessrc\SmsAppTemplates.c
endif

ifneq ($(filter __MMI_SAFE_MODE__ , $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\MtkApp\SafeMode\SafeModeSrc\safemode.c \
  			  plutommi\MtkApp\SafeMode\SafeModeSrc\safemodeAutostart.c
endif

SRC_LIST += plutommi\mmi\nitzhandler\nitzsource\nitz.c \
           plutommi\mmi\organizer\organizersrc\alarm.c \
           plutommi\mmi\organizer\organizersrc\AlarmIndication.c \
           plutommi\mmi\organizer\organizersrc\AlarmInterface.c \
           plutommi\mmi\organizer\organizersrc\alarmframework.c \
           plutommi\mmi\organizer\Reminder\ReminderApp.c \
           plutommi\mmi\organizer\Reminder\FactoryAlarm.c \
           plutommi\mmi\organizer\Reminder\PwrResetAlarm.c \
           plutommi\mmi\organizer\Reminder\ReminderBootupInitApps.c \
           plutommi\mmi\organizer\organizersrc\birthday.c \
           plutommi\mmi\organizer\organizersrc\calendar.c \
           plutommi\mmi\organizer\organizersrc\CalendarEvent.c \
           plutommi\mmi\organizer\organizersrc\organizer.c \
           plutommi\mmi\organizer\organizersrc\lunarquery.c \
           plutommi\mmi\organizer\organizersrc\todolist.c \
           plutommi\mmi\organizer\organizersrc\todolistdb.c \
           plutommi\mmi\organizer\organizersrc\ToDoListApp.c \
           plutommi\mmi\organizer\organizersrc\todolistutil.c \
           plutommi\mmi\Organizer\IndianCalendar\IndianCalendarSrc\IndianCalendar.c \
           plutommi\mmi\Organizer\HijriCalendar\HijriCalendarSrc\HijriCalendar.c \
           plutommi\mmi\Organizer\HijriCalendar\HijriCalendarSrc\AzaanAlarm.c \
           plutommi\mmi\organizer\organizersrc\worldclock.c \
           plutommi\CUI\WorldClockCui\WorldClockCui.c \
           plutommi\mmi\organizer\organizersrc\NoteApp.c \
           plutommi\mmi\phonebook\phonebooksrc\PhoneBookGroup.c \
           plutommi\mmi\phonebook\phonebooksrc\phonebookextranumber.c \
           plutommi\mmi\phonebook\phonebooksrc\phonebookmain.c \
           plutommi\mmi\phonebook\phonebooksrc\phonebooksetting.c \
           plutommi\mmi\phonebook\phonebooksrc\phonebookApp.c \
           plutommi\mmi\phonebook\core\phonebookCore.c \
           plutommi\mmi\phonebook\phonebooksrc\phonebookList.c \
           plutommi\mmi\phonebook\phonebooksrc\phonebookEditor.c \
           plutommi\mmi\phonebook\phonebooksrc\phonebookCallerRes.c \
           plutommi\Cui\PhbCui\PhbCui.c \
           plutommi\mmi\profiles\profilessrc\ProfilesApp.c \
           plutommi\mmi\profiles\profilessrc\Soundset.c \
           plutommi\mmi\sat\satsrc\sat.c \
           plutommi\mmi\sat\satsrc\service.c \
           plutommi\mmi\sat\satsrc\SatApp.c \
           plutommi\mmi\setting\settingsrc\apncontrollist.c \
           plutommi\mmi\setting\settingsrc\dateandtime.c \
           plutommi\mmi\setting\settingsrc\flightmode.c \
           plutommi\mmi\setting\settingsrc\mmi_phnset_dispchar.c \
           plutommi\mmi\setting\settingsrc\phnsetgpio.c \
           plutommi\mmi\setting\settingsrc\PhnsetDisplay.c \
           plutommi\mmi\setting\settingsrc\PhnsetDispMenuService.c \
           plutommi\mmi\setting\settingsrc\PhnsetMenuService.c \
           plutommi\mmi\setting\settingsrc\phonesetup.c \
           plutommi\mmi\setting\settingsrc\restore.c \
           plutommi\mmi\setting\settingsrc\scheduledpoweronoff.c \
           plutommi\mmi\setting\settingsrc\screensaver.c \
           plutommi\mmi\setting\settingsrc\settingsrc.c \
           plutommi\mmi\setting\settingsrc\soundeffect.c \
           plutommi\mmi\setting\settingsrc\wallpaper.c \
           plutommi\mmi\setting\settingsrc\MMIThemes.c \
           plutommi\mmi\setting\settingsrc\NetSetApp.c \
           plutommi\mmi\setting\settingsrc\NetSetAppOthers.c \
           plutommi\mmi\setting\settingsrc\NetSetAppPrefMode.c \
           plutommi\mmi\setting\settingsrc\NetSetAppPrefList.c \
           plutommi\mmi\setting\settingsrc\NetSetAppNWSelect.c \
           plutommi\mmi\setting\settingsrc\RestoreServiceHdlr.c \
           plutommi\mmi\setting\settingsrc\ViewSettingCommon.c \
           plutommi\mmi\setting\settingsrc\TTSSetting.c \
           plutommi\MMI\Setting\SettingSrc\NetSetServiceSelection.c \
           plutommi\CUI\SsoCui\SsoCuiSrc\SsoCui.c \
           plutommi\MMI\SSOAPP\SSOAPPSrc\SSOAPPSrc.c \
           plutommi\MMI\Setting\SettingSrc\MotionSensorSrc.c \
           plutommi\MMI\Setting\SettingSrc\PhnsetWidgetMgr.c \
           plutommi\MMI\Setting\SettingSrc\PhnsetShortcutSetting.c \
           plutommi\MMI\Setting\SettingSrc\PhnsetLauncherSetting.c \
           plutommi\MMI\Setting\SettingSrc\PhnsetMainEffectSetting.c \
           plutommi\MMI\Setting\SettingSrc\NetSetSimName.c \
           plutommi\MMI\Setting\SettingSrc\PhnsetDlCalData.c \
           plutommi\CUI\SecSetCui\SecSetCuiVerify.c \
           plutommi\CUI\PasswordCui\PwdCuiBasic.c \
           plutommi\CUI\PasswordCui\PwdCuiGuardSlim.c \
           plutommi\MMI\SecuritySetting\SecSetSrc\SecSetMenu.c \
           plutommi\MMI\SecuritySetting\SecSetSrc\SecSetSimMenu.c \
           plutommi\MMI\SecuritySetting\SecSetSrc\SecSetSimCommon.c \
           plutommi\MMI\SecuritySetting\SecSetSrc\SecSetPhone.c \
           plutommi\MMI\SecuritySetting\SecSetSrc\SecSetUbchv.c \
           plutommi\MMI\SecuritySetting\SecSetSrc\SecSetUtil.c \
           plutommi\MMI\SecuritySetting\SecSetSrc\SecSetHPVeri.c \
           plutommi\MMI\SecuritySetting\SecSetSrc\SecSetSSC.c \
           plutommi\mmi\ucm\ucmsrc\UcmEventHdlr.c \
           plutommi\mmi\ucm\ucmsrc\UCMUI.c \
           plutommi\mmi\ucm\ucmsrc\UcmUha.c \
           plutommi\mmi\ucm\ucmsrc\UcmVtCore.c \
           plutommi\mmi\ucm\ucmsrc\ucminterface.c \
           plutommi\mmi\setting\settingsrc\Appicon.c
         
ifneq ($(filter __MMI_NSS_SUPPORT__ , $(strip $(MODULE_DEFS))),)                  
SRC_LIST += plutommi\MMI\Setting\SettingSrc\NSSApp.c
endif

ifneq ($(filter __NTPD_SUPPORT__ , $(strip $(MODULE_DEFS))),)                  
SRC_LIST += plutommi\mmi\Setting\SettingSrc\NtpApp.c
endif
  
ifneq ($(filter __UNIFIED_COMPOSER_SUPPORT__ , $(strip $(MODULE_DEFS))),)                  
SRC_LIST += plutommi\mmi\UnifiedComposer\UnifiedComposerSrc\UcPcrdApp.c \
           plutommi\mmi\unifiedcomposer\unifiedcomposersrc\UcAppCore.c \
           plutommi\mmi\unifiedcomposer\unifiedcomposersrc\UcAppInterface.c \
           plutommi\mmi\unifiedcomposer\unifiedcomposersrc\UCMsgHdlrApp.c \
           plutommi\mmi\unifiedcomposer\unifiedcomposersrc\UcScrUIHldr.c \
           plutommi\mmi\unifiedcomposer\unifiedcomposersrc\UcScrUICb.c \
           plutommi\mmi\unifiedcomposer\unifiedcomposersrc\UcScrUICtrl.c \
           plutommi\mmi\unifiedcomposer\unifiedcomposersrc\UcScrUIDraw.c \
           plutommi\mmi\unifiedcomposer\unifiedcomposersrc\UcScrUIPlugin.c \
           plutommi\CUI\UcCui\UcCui.c
endif
ifneq ($(filter __MMS_STANDALONE_COMPOSER_SUPPORT__ , $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mmi\UnifiedComposer\UnifiedComposerSrc\UcPcrdApp.c \
           plutommi\mmi\unifiedcomposer\unifiedcomposersrc\UcAppCore.c \
           plutommi\mmi\unifiedcomposer\unifiedcomposersrc\UcAppInterface.c \
           plutommi\mmi\unifiedcomposer\unifiedcomposersrc\UCMsgHdlrApp.c \
           plutommi\mmi\unifiedcomposer\unifiedcomposersrc\UcScrUIHldr.c \
           plutommi\mmi\unifiedcomposer\unifiedcomposersrc\UcScrUICb.c \
           plutommi\mmi\unifiedcomposer\unifiedcomposersrc\UcScrUICtrl.c \
           plutommi\mmi\unifiedcomposer\unifiedcomposersrc\UcScrUIDraw.c \
           plutommi\mmi\unifiedcomposer\unifiedcomposersrc\UcScrUIPlugin.c \
           plutommi\CUI\UcCui\UcCui.c
endif
SRC_LIST += plutommi\mmi\unifiedmessage\unifiedmessagesrc\UMAdaptor.c \
           plutommi\mmi\unifiedmessage\unifiedmessagesrc\UMApperance.c \
           plutommi\mmi\unifiedmessage\unifiedmessagesrc\UMCentralCtrl.c \
           plutommi\mmi\unifiedmessage\unifiedmessagesrc\UMFsm.c \
           plutommi\mmi\unifiedmessage\unifiedmessagesrc\UMInterface.c \
           plutommi\mmi\unifiedmessage\unifiedmessagesrc\UMMain.c \
           plutommi\mmi\unifiedmessage\unifiedmessagesrc\UMScrHdlr.c \
           plutommi\mmi\unifiedmessage\unifiedmessagesrc\UMUtility.c \
           plutommi\mmi\CubeApp\CubeAppSrc\CubeApp.c \
           plutommi\MtkApp\AGPSLog\AGPSLogSrc\EngineerModeAGPSlogUI.c \
           plutommi\MtkApp\AGPSLog\AGPSLogSrc\EngineerModeAGPSlogCore.c \
           plutommi\MtkApp\AGPSLog\AGPSLogSrc\EngineerModeAGPSlogService.c \
           plutommi\MtkApp\AGPSLog\AGPSLogSrc\EngineerModeAGPSlogStringDef.c \
           plutommi\mtkapp\filemgr\filemgrsrc\filemgrcommon.c \
           plutommi\mtkapp\filemgr\filemgrsrc\filemgrfsdata.c \
           plutommi\mtkapp\filemgr\filemgrsrc\filemgrgui.c \
           plutommi\mtkapp\filemgr\filemgrsrc\filemgrinstance.c \
           plutommi\mtkapp\filemgr\filemgrsrc\filemgrmain.c \
           plutommi\mtkapp\filemgr\filemgrsrc\filemgrservice.c \
           plutommi\mtkapp\filemgr\filemgrsrc\filemgrservicehdlr.c \
           plutommi\mtkapp\filemgr\filemgrsrc\filemgrtable.c \
           plutommi\mtkapp\filemgr\filemgrsrc\filemgrutil.c \
           plutommi\CUI\filemgrcui\filemgrcui.c \
           plutommi\CUI\filemgrcui\filemgrcuiadp.c \
           plutommi\mtkapp\myfavorite\myfavoritesrc\myfavorite.c
ifneq ($(filter __MMI_PICT_BRIDGE_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mtkapp\pictbridge\pictbridgesrc\pictbridgecui.c \
           plutommi\mtkapp\pictbridge\pictbridgesrc\pictbridgefmgr.c \
           plutommi\mtkapp\pictbridge\pictbridgesrc\pictbridgehandler.c \
           plutommi\mtkapp\pictbridge\pictbridgesrc\pictbridgemain.c \
           plutommi\mtkapp\pictbridge\pictbridgesrc\pictbridgesettings.c \
           plutommi\mtkapp\pictbridge\pictbridgesrc\pictbridgexml.c
endif
SRC_LIST += plutommi\mtkapp\rightsmgr\rightsmgrsrc\rightsmgr.c \
           plutommi\mtkapp\rightsmgr\rightsmgrsrc\rightsmgrutil.c \
           plutommi\mtkapp\rightsmgr\rightsmgrsrc\rightsmgrgeninfo.c \
           plutommi\mtkapp\rightsmgr\rightsmgrsrc\rightsmgrlistro.c \
           plutommi\mtkapp\rightsmgr\rightsmgrsrc\rightsmgrsweep.c \
           plutommi\mtkapp\rightsmgr\rightsmgrsrc\rightsmgrui.c \
           plutommi\mtkapp\rightsmgr\rightsmgrsrc\rightsmgrwhitelist.c \
           plutommi\mtkapp\vobjects\vobjectsrc\vbookmark.c \
           plutommi\mtkapp\vobjects\vobjectsrc\vcalendar.c \
           plutommi\mtkapp\vobjects\vobjectsrc\vcard.c \
           plutommi\mtkapp\vobjects\vobjectsrc\vobjects.c \
           plutommi\mmi\UDX\UDXSrc\UDXScr.c \
           plutommi\mmi\UDX\UDXSrc\UDXHdlr.c \
           plutommi\mmi\UDX\UDXSrc\UDXMain.c \
           plutommi\mtkapp\searchweb\searchwebsrc\searchwebcommon.c \
           plutommi\mtkapp\searchweb\searchwebsrc\searchwebbaiduconfig.c \
           plutommi\mtkapp\searchweb\searchwebsrc\searchwebbaidu.c \
           plutommi\mtkapp\searchweb\searchwebsrc\searchwebgoogleconfig.c \
           plutommi\CUI\ToneSelectorCui\ToneSelectorCui.c \
           plutommi\CUI\ToneSelectorCui\ToneSelectorCuiForSLIM.c \
           plutommi\Cui\SmsCui\SmsGenericCui.c \
           plutommi\Cui\SmsCui\SmsSaveCui.c \
           plutommi\Cui\SmsCui\SmsUtilCui.c \
           plutommi\Cui\SmsCui\SmsSenderCui.c \
           plutommi\mmi\Bootup\BootupSrc\BootupFlow.c \
           plutommi\mmi\Bootup\BootupSrc\BootupAdp.c \
           plutommi\mmi\Bootup\BootupSrc\BootupMoDIS.c \
           plutommi\mmi\Bootup\BootupSrc\BootupDiskCheck.c \
           plutommi\mmi\Bootup\BootupSrc\BootupScrUtil.c \
           plutommi\mmi\Bootup\BootupSrc\BootupMode.c \
           plutommi\mmi\Bootup\BootupSrc\BootupInitApps.c \
           plutommi\mmi\Bootup\BootupSrc\BootupAnimation.c \
           plutommi\mmi\Bootup\BootupSrc\BootupSecurity.c \
           plutommi\mmi\Bootup\BootupSrc\BootupSecConfig.c \
           plutommi\mmi\Bootup\BootupSrc\BootupScrAni.c \
           plutommi\mmi\Bootup\BootupSrc\BootupSubLcd.c \
           plutommi\mmi\Shutdown\ShutdownSrc\ShutdownFlow.c \
           plutommi\mmi\Shutdown\ShutdownSrc\ShutdownAni.c \
           plutommi\mmi\Shutdown\ShutdownSrc\ShutdownSubLcd.c \
           plutommi\mmi\SimCtrl\SimCtrlSrc\SimCtrlApp.c \
           plutommi\mmi\NwInfo\NwInfoSrc\NwInfoApp.c \
           plutommi\mmi\NwInfo\NwInfoSrc\NwInfoIcon.c \
           plutommi\mmi\NwInfo\NwInfoSrc\NwInfoSignal.c \
           plutommi\mmi\IdleScreen\IdleScreenSrc\HomeScreenOp11Setting.c \
           plutommi\MMI\CallSetting\CallSettingCore\CallSetCore.c \
           plutommi\MMI\CallSetting\CallSettingSrc\CallSetStructMgmt.c \
           plutommi\MMI\CallSetting\CallSettingSrc\CallSetUi.c \
           plutommi\MMI\SupplementaryService\SsSrc\SsStructMgmt.c \
           plutommi\MMI\SupplementaryService\SsSrc\SsUi.c \
           plutommi\MMI\ShellApp\ShellAppSrc\ShellApp.c \
           plutommi\CUI\MsgViewerCui\MsgViewerCui.c \
           plutommi\CUI\MsgViewerCui\MsgViewerCuiAdp.c \
           plutommi\mmi\CallLog\CallLogSrc\CallLogAction.c \
           plutommi\mmi\CallLog\CallLogSrc\CallLogAdpCmn.c \
           plutommi\mmi\CallLog\CallLogSrc\CallLogAdpOp11.c \
           plutommi\mmi\CallLog\CallLogSrc\CallLogConfig.c \
           plutommi\mmi\CallLog\CallLogSrc\CallLogLayout.c \
           plutommi\mmi\CallLog\CallLogSrc\CallLogMain.c \
           plutommi\mmi\CallLog\CallLogSrc\CallLogMainMenu.c \
           plutommi\mmi\CallLog\CallLogSrc\CallLogMisc.c \
           plutommi\mmi\CallLog\CallLogSrc\CallLogOption.c \
           plutommi\mmi\CallLog\CallLogSrc\CallLogViewer.c \
           plutommi\mmi\CallLog\CallLogSrc\CallLogAdvanced.c

ifneq ($(filter __MMI_ENGINEER_MODE__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeAudio.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeBT.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeMMColor.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeBacklight.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeDebugInfo.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeDevice.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeDM.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeFRMProfiling.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeFSTestCore.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeFSTestUI.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeGPRS.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeGPS.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeInetApp.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeIperf.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeMiniGPS.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeMisc.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeMMIFramework.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeMotion.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeMultimedia.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModePCSNetwork.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModePMIC.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeProfiling.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeRFtest.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeSocketApp.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeSocketDemoApp.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeStorage.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeVOIP.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeBTRFtest.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeLCD.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeNWEvent.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeNWInfo.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeWLAN.c \
           plutommi\mtkapp\EngineerMode\EngineerModeEngine\EngineerModeEngineSrc\EngineerModeMain.c \
           plutommi\mtkapp\EngineerMode\EngineerModeEngine\EngineerModeEngineSrc\EngineerModeUtil.c \
           plutommi\mtkapp\EngineerMode\EngineerModeEngine\EngineerModeEngineSrc\EngineerModeCommUI.c \
           plutommi\mtkapp\EngineerMode\EngineerModeEngine\EngineerModeEngineSrc\EngineerModeCommMem.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeSSPSettings.c  \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerMode3GInfo.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeConfTest.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeTouchPanel.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModePXS.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeGDIProfiling.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeGDIProfBlt.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeGDIProfImage.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeGDIProfPlatform.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeGDIProfFlatten.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeGDIProfLT.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeGDIProfMisc.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeGDIProfDecoder.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeCnmgr.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeNfc.c \
           plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppSrc\EngineerModeRecorderSetting.c
endif

ifneq ($(filter __MMI_FACTORY_MODE__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mtkapp\FactoryMode\FactoryModeSrc\FactoryModeAudio.c\
           plutommi\mtkapp\FactoryMode\FactoryModeSrc\FactoryModeDevice.c\
           plutommi\mtkapp\FactoryMode\FactoryModeSrc\FactoryModeKeypad.c\
           plutommi\mtkapp\FactoryMode\FactoryModeSrc\FactoryModeMain.c\
           plutommi\mtkapp\FactoryMode\FactoryModeSrc\FactoryModeMedia.c\
           plutommi\mtkapp\FactoryMode\FactoryModeSrc\FactoryModeMisc.c\
           plutommi\mtkapp\FactoryMode\FactoryModeSrc\FactoryModeNxMPoint.c\
           plutommi\mtkapp\FactoryMode\FactoryModeSrc\FactoryModeParallelLine.c\
           plutommi\mtkapp\FactoryMode\FactoryModeSrc\FactoryModeQuickTest.c\
           plutommi\mtkapp\FactoryMode\FactoryModeSrc\FactoryModeQuickTstSet.c\
           plutommi\mtkapp\FactoryMode\FactoryModeSrc\FactoryModeTC01.c\
           plutommi\mtkapp\FactoryMode\FactoryModeSrc\FactoryModeTouchPanel.c \
           plutommi\mtkapp\FactoryMode\FactoryModeSrc\FactoryModeDualTouchCalibration.c\
           plutommi\mtkapp\FactoryMode\FactoryModeSrc\FactoryModeUtil.c \
           plutommi\mtkapp\FactoryMode\FactoryModeSrc\FactoryModeNFC.c
endif

ifneq ($(filter __MMI_FM_TC01_CAMERA_TEST__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mtkapp\FactoryMode\FactoryModeSrc\FactoryModeTC01.c
endif

ifneq ($(filter __MMI_MOBILE_SERVICE__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mmi\mobileservice\mobileservicesrc\mobileserviceappmain.c
endif

ifneq ($(filter __MMI_CUSTOMER_SERVICE__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mmi\customerservice\customerservicesrc\custserviceappmain.c
endif
 
ifneq ($(filter __GADGET_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\MtkApp\WgtMgrApp\WgtMgrAppSrc\WgtMgrAppInstall.c \
            plutommi\MtkApp\WgtMgrApp\WgtMgrAppSrc\WgtMgrAppMain.c \
            plutommi\MtkApp\WgtMgrApp\WgtMgrAppSrc\WgtMgrAppSettings.c
endif

ifneq ($(filter __MMI_CLOG_GPRS_COUNT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\mmi\CallLog\CallLogSrc\CalllogGprsCount.c
endif
ifneq ($(filter __MMI_CLOG_CALL_COST__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\mmi\CallLog\CallLogSrc\CallLogCallCost.c
endif
ifneq ($(filter __MMI_CLOG_CALL_TIME__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\mmi\CallLog\CallLogSrc\CallLogCallTime.c
endif
ifneq ($(filter __MMI_CLOG_SMS_COUNT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\mmi\CallLog\CallLogSrc\CallLogSmsCount.c
endif

ifneq ($(filter __MMI_MExE_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\mmi\sat\satsrc\mexe.c
endif

ifneq ($(filter __MMI_VPP_UPGRADE__, $(strip $(MODULE_DEFS))),)
  SRC_LIST +=  plutommi\MMI\Upgrade\UpgradeSrc\Upgrade.c

endif

ifneq ($(filter __CTM_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\MMI\Ctm\CtmSrc\Ctm.c
endif

ifneq ($(filter __MMI_DIALER_SEARCH__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\mmi\phonebook\phonebooksrc\PhoneBookDialerSearch.c
endif

ifneq ($(filter __MMI_VOIP__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\CUI\DialerCui\DialerCuiVoip.c
endif
ifneq ($(filter __MMI_DIALER_SEARCH__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\CUI\DialerCui\DialerCuiSearch.c
endif

ifneq ($(filter __MMI_VIDEO_TELEPHONY__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += plutommi\mmi\ucm\ucmsrc\UcmVtCallScr.c
endif

ifeq ($(strip $(VOIP_SUPPORT)),FALSE)
SRC_LIST += plutommi\mmi\voip\voipsrc\voipcall.c \
           plutommi\mmi\voip\voipsrc\voipinterface.c \
           plutommi\mmi\voip\voipsrc\voipmain.c \
           plutommi\mmi\voip\voipsrc\voipmsghdlr.c \
           plutommi\mmi\voip\voipsrc\voipotapdmp.c \
           plutommi\mmi\voip\voipsrc\voipsetting.c \
           plutommi\mmi\voip\voipsrc\voipsignal.c \
           plutommi\mmi\voip\voipsrc\voiputil.c \
           plutommi\mmi\voip\voipsrc\voipvoice.c
endif

ifneq ($(filter __MRE_AM__, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=  plutommi\mtkapp\MREAPP\MREAPPSrc\MREAPPEntry.c \
           plutommi\mtkapp\MREAPP\MREAPPSrc\AMShortcut.c \
           plutommi\mtkapp\MREAPP\MREAPPSrc\AMApp.c \
           plutommi\mtkapp\MREAPP\MREAPPSrc\AMConfig.c \
           plutommi\mtkapp\MREAPP\MREAPPSrc\AMMainScreen.c \
           plutommi\mtkapp\MREAPP\MREAPPSrc\AMProxy.c \
           plutommi\mtkapp\MREAPP\MREAPPSrc\AMScreens.c \
           plutommi\mtkapp\MREAPP\MREAPPSrc\AMUtil.c \
           plutommi\mtkapp\MREAPP\MREAPPSrc\AMZiMoRes.c \
           plutommi\mtkapp\MREAPP\MREAPPSrc\AMDLAgent.c \
           plutommi\mtkapp\MREAPP\MREAPPSrc\MreDLTaskMgr.c \
           plutommi\mtkapp\MREAPP\MREAPPSrc\liblist.c
 endif

SRC_LIST +=  plutommi\mtkapp\MREAPP\MREAPPSrc\AMLaunchApp.c
SRC_LIST +=  plutommi\mtkapp\MREAPP\MREAPPSrc\AMLaunchApp_int.c
 

ifneq ($(filter __MMI_MRE_MSPACE__, $(strip $(MODULE_DEFS))),)
    SRC_DIR +=  plutommi\mtkapp\MSpace\MSpaceSrc
endif

ifneq ($(filter __MMI_MRE_MSPACE__, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=  plutommi\mtkapp\MSpace\MSpaceSrc\MSpace.c
    SRC_LIST +=  plutommi\mtkapp\MSpace\MSpaceSrc\MSpaceAppScreen.c
    SRC_LIST +=  plutommi\mtkapp\MSpace\MSpaceSrc\MSpaceAs.c
    SRC_LIST +=  plutommi\mtkapp\MSpace\MSpaceSrc\MSpaceMainScreen.c
endif
 

ifneq ($(filter __MMI_BMI__, $(strip $(MODULE_DEFS))),)
	 SRC_LIST += plutommi\mmi\extra\extrasrc\health.c
else
  ifneq ($(filter __MMI_MENSTRUAL__, $(strip $(MODULE_DEFS))),)
	 SRC_LIST += plutommi\mmi\extra\extrasrc\health.c
  endif
endif

ifneq ($(filter __MMI_BMI__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += plutommi\mmi\extra\extrasrc\bmi.c
endif

ifneq ($(filter __MMI_MENSTRUAL__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += plutommi\mmi\extra\extrasrc\healthmenstural.c
endif

ifneq ($(filter __MMI_UNIT_CONVERTER__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += plutommi\mmi\extra\extrasrc\unitconvertor.c
endif

ifneq ($(filter __MMI_CURRENCY_CONVERTER__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += plutommi\mmi\extra\extrasrc\currencyconvertor.c
endif

ifneq ($(filter __MMI_STOPWATCH__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += plutommi\mmi\extra\extrasrc\stopwatchmultipurpose.c \
           plutommi\mmi\extra\extrasrc\stopwatchtypical.c
endif

ifneq ($(filter __MMI_ZAKAT_CALCULATOR__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += plutommi\mmi\extra\extrasrc\zakatcalculator.c
endif

ifeq ($(filter __DISABLE_SHORTCUTS_IMPL__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += plutommi\mmi\extra\extrasrc\shortcuts.c
endif

ifneq ($(filter __MMI_DUAL_SIM_MASTER__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\mmi\setting\settingsrc\ModeSwitchApp.c
endif
ifneq ($(filter __MMI_TOUCH_SCREEN__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\mmi\setting\settingsrc\PhnsetCalibration.c
endif
ifneq ($(filter __MMI_POWER_ON_OFF_DISPLAY__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\mmi\setting\settingsrc\poweronoffdisplay.c
endif
SRC_LIST += plutommi\mmi\SimSpace\SimSpaceSrc\SimSpace.c
SRC_LIST += plutommi\CUI\SimSelCui\SimSelCui.c

ifneq ($(filter __MMI_OP02_LEMEI__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\mtkapp\Lemei\LemeiSrc\Lemei.c
endif

SRC_LIST += plutommi\CUI\UseDetailCui\UseDetailCui.c

ifneq ($(filter __GPS_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mtkapp\GPS\GPSSrc\GPSMgr.c \
           plutommi\mtkapp\GPS\GPSSrc\GPSSetting.c \
           plutommi\mtkapp\GPS\GPSSrc\GPSSettingMainScr.c \
           plutommi\mtkapp\GPS\GPSSrc\AGPSSUPLOTAP.c \
           plutommi\mtkapp\GPS\GPSSrc\GPSMgrAGPSCP.c \
           plutommi\mtkapp\GPS\GPSSrc\GPSMgrAGPSUP.c \
           plutommi\mtkapp\GPS\GPSSrc\gps_ate.c
endif

SRC_LIST += plutommi\AppCore\SSC\SSCOperate.c \
           plutommi\AppCore\SSC\SSCPassEngine.c \
           plutommi\AppCore\SSC\SSCStringHandle.c 

SRC_LIST += plutommi\AppCore\Ucm\UcmKernel.c \
           plutommi\AppCore\Ucm\UcmUhaCore.c


SRC_LIST += plutommi\MtkApp\MREAPP\MREAPPSrc\DLShortcut.c \

# Define include path lists to INC_DIR
INC_DIR = applib\inet\engine\include \
          applib\mem\include \
          applib\misc\include \
          drv\include \
          fmt\include \
          fs\fat\include \
          interface\hwdrv \
          interface\wifi \
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
          plutommi\mmi\miscframework\miscframeworkinc \
          plutommi\Framework\InputMethod\Inc \
          plutommi\Framework\GDI\gdiinc \
          plutommi\service\mdi\mdiinc \
          plutommi\Service\ImgEdtSrv \
          plutommi\mtkapp\mtkappinc \
          vendor\inputmethod\cstar\adaptation\include \
          vendor\inputmethod\t9\adaptation\include \
          venusmmi\app\pluto \
          btstacka\inc \
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
          vcard\include \
          plutommi\CUI\Inc \
          plutommi\CUI\InlineCui \
          plutommi\mmi\athandler\athandlerinc \
          plutommi\mmi\audio\audioinc \
          plutommi\Framework\BIDI\bidiinc \
          plutommi\mmi\browserapp\browser\browserinc \
          plutommi\mmi\browserapp\pushinbox\pushinboxinc \
          plutommi\MMI\CertificateManager\CertificateManagerMMIInc \
          security\certman\include \
          plutommi\Framework\CommonScreens\commonscreensinc \
          plutommi\MMI\ConnectManagement\ConnectManagementInc \
          plutommi\mmi\cphs\cphsinc \
          plutommi\mmi\customerservice\customerserviceinc \
          plutommi\mmi\dataaccount\dataaccountinc \
          plutommi\mmi\datetime\datetimeinc \
          plutommi\Framework\DebugLevels\debuglevelinc \
          plutommi\mmi\dictionary\dictinc \
          plutommi\mmi\ebookreader\ebookinc \
          plutommi\mmi\emailapp\emailappinc \
          plutommi\service\ProvisioningSrv \
          plutommi\mmi\extra\extrainc \
          plutommi\mmi\funandgames\funandgamesinc \
          plutommi\mmi\gpio\gpioinc \
          plutommi\mmi\gsmcallapplication\commonfiles\commoninc \
          plutommi\mmi\gsmcallapplication\incomingcallmanagement\incominginc \
          plutommi\mmi\gsmcallapplication\outgoingcallmanagement\outgoinginc \
          plutommi\mmi\help\helpinc \
          plutommi\mmi\idlescreen\idlescreeninc \
          plutommi\mmi\idlescreen\idlescreeninc\demoappinc \
          plutommi\MMI\Factory\FactoryInc \
          plutommi\MMI\Idle\IdleInc \
          plutommi\MMI\Dialer\DialerInc \
          plutommi\MMI\ScrLocker\ScrLockerInc \
          plutommi\MMI\ScrSaver\ScrSaverInc \
          plutommi\mmi\imps\impsinc \
          plutommi\Framework\IndicLanguages\indiclanguagesinc \
          plutommi\Framework\Languages\thai\thaiinc \
          plutommi\mmi\mainmenu\mainmenuinc \
          plutommi\mmi\messages \
          plutommi\CUI\SsoCui\SsoCuiInc \
          plutommi\MMI\SSOAPP\SSOAPPInc \
          plutommi\mmi\messages\messagesinc \
          plutommi\mmi\mobileservice\mobileserviceinc \
          plutommi\mmi\nitzhandler\nitzinc \
          plutommi\mmi\organizer\Organizerinc \
          plutommi\mmi\Organizer\IndianCalendar\IndianCalendarInc \
          plutommi\mmi\Organizer\Reminder \
          plutommi\mmi\phonebook\phonebookinc \
          plutommi\mmi\phonebook\core \
          plutommi\mmi\profiles\profilesinc \
          plutommi\mmi\resource\inc \
          plutommi\mmi\sat\satinc \
          plutommi\mmi\setting\settinginc \
          plutommi\mmi\SecuritySetting\SecSetInc \
          plutommi\mmi\smartmessage\smartmessageinc \
          plutommi\mmi\ucm\ucminc \
          plutommi\mmi\ctm\ctminc \
          plutommi\service\Inc \
          plutommi\service\UmSrv \
          plutommi\mmi\unifiedmessage\unifiedmessageinc \
          plutommi\Service\UcSrv \
          plutommi\mmi\unifiedcomposer\unifiedcomposerinc \
          venusmmi\app\pluto_variation\CubeApp \
          plutommi\mmi\CubeApp\CubeAppInc \
          plutommi\mmi\unifiedmms\mmsapp\mmsappinc \
          plutommi\Service\UmmsSrv \
          plutommi\mmi\voip\voipinc \
          plutommi\mmi\Organizer\HijriCalendar\HijriCalendarInc \
          plutommi\mtkapp\abrepeater\abrepeaterinc \
          plutommi\MtkApp\AGPSLog\AGPSLogInc \
          plutommi\mtkapp\audioplayer\audioplayerinc \
          plutommi\mtkapp\MediaPlayer\MediaPlayerInc \
          plutommi\mtkapp\avatar\avatarinc \
          plutommi\mtkapp\barcodereader\barcodereaderinc \
          plutommi\mtkapp\bgsound\bgsoundinc \
          plutommi\mtkapp\camera\camerainc \
          plutommi\MtkApp\ImageView\ImageViewInc \
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
          plutommi\mtkapp\FactoryMode\FactoryModeInc \
          custom\common\hal \
          plutommi\mtkapp\filemgr\filemgrinc \
          plutommi\mtkapp\fmradio\fmradioinc \
          plutommi\mtkapp\fmschedulerec\fmschedulerecinc \
          plutommi\mtkapp\GPS\GPSInc \
          plutommi\mtkapp\javaagency\javaagencyinc \
          plutommi\mtkapp\mmiapi\include \
          plutommi\mtkapp\mobiletvplayer\mobiletvplayerinc \
          plutommi\MtkApp\MobileTVPlayer\MtvSMSInc \
          plutommi\mtkapp\dtvplayer\dtvplayerinc \
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
          plutommi\mtkapp\vrsd\vrsdinc \
          plutommi\mtkapp\vrsi\vrsiinc \
          plutommi\mtkapp\searchweb\searchwebinc \
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
          vendor\mobilevideo\adaption\MobileVideoInc\include_CM \
          vendor\mobilevideo\adaption\MobileVideoInc\include \
          plutommi\mmi\SIMProvAgent\SIMProvAgentInc \
          plutommi\mmi\UDX\UDXInc \
          vendor\qqim\adaptation\inc \
          plutommi\Service\ProvBoxSrv \
          plutommi\mmi\ProvisioningInbox\ProvBoxApp\ProvBoxAppInc \
          init\include \
          $(strip $(PS_FOLDER))\l4\include \
          venusmmi\vrt\interface \
          venusmmi\framework \
          venusmmi\framework\interface \
          venusmmi\visual \
          venusmmi\visual\interface \
          venusmmi\app\pluto_variation\interface \
          venusmmi\app\pluto_variation\adapter \
          venusmmi\app\pluto_variation\adapter\interface \
          venusmmi\app\pluto_variation\adapter\interface\res \
          venusmmi\test \
          venusmmi\app \
          venusmmi\app\pluto_variation \
          venusmmi\app\common\wallpaper \
          venusmmi\app\common\ncenter \
          venusmmi\app\common\interface\app \
          venusmmi\framework\ui_core\mvc \
          venusmmi\app\common\data \
          plutommi\mtkapp\MREAPP\MREAPPInc \
          plutommi\mtkapp\MSpace\MSpaceInc \
          plutommi\Service\MRESrv \
          plutommi\CUI\ToneSelectorCui \
          plutommi\Framework\LangModule\LangModuleInc \
          plutommi\MMI\Bootup\BootupInc \
          plutommi\MMI\NwInfo\NwInfoInc \
          plutommi\MMI\SimCtrl\SimCtrlInc \
          plutommi\MMI\Shutdown\ShutdownInc \
          plutommi\mmi\q03c_mms_V01_agent\q03c_mms_V01_agentinc \
          plutommi\Service\MediaCacheSrv \
          plutommi\Service\inc \
          plutommi\MtkApp\WgtMgrApp\WgtMgrAppInc \
          plutommi\MMI\CallSetting\CallSettingInc \
          plutommi\MMI\SupplementaryService\SsInc \
          vendor\opera\browser\adaptation\inc \
          plutommi\Service\NetSetSrv \
          plutommi\Service\ModeSwitchSrv \
          plutommi\Service\ProfilesSrv \
          plutommi\MMI\ShellApp\ShellAppInc \
          venusmmi\app\pluto_variation\ShellApp\base \
          venusmmi\app\pluto_variation\ShellApp\panel \
          venusmmi\app\pluto_variation\adapter\ShellApp\base \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel \
          plutommi\mmi\CallLog\CallLogInc \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel\HomeScreen \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel\MsgViewer\
          venusmmi\app\pluto_variation\ShellApp\panel\HomeScreen \
          venusmmi\app\pluto_variation\adapter\MultiTouchTest \
          vendor\opera\browser\v1_official\opdev\include \
          operator\ORANGE\common\venusmmi\pluto_adapter\interface\res \
          operator\ORANGE\common\venusmmi\pluto_adapter\HomeScreen \
          operator\ORANGE\common\venusmmi\app\HomeScreen \
          operator\ORANGE\common\venusmmi \
          mmi_core\app\SupplementaryService \
          plutommi\mmi\SimSpace\SimSpaceInc \
          plutommi\CUI\SimSelCui \
          plutommi\Framework\InputMethod\Engine\Engine_Inc \
          plutommi\Framework\InputMethod\SDK_Layer\SDK_Inc \
          plutommi\Framework\InputMethod\UI\UI_Inc \
          hal\storage\mc\inc \
          plutommi\mtkapp\Lemei\LemeiInc \
          plutommi\Service\Inc \
          plutommi\Service\UPPSrv \
          hal\video\custom \
          custom\video \
          interface\hal\display\common \
          interface\ps\enum \
          meta\cct \
          plutommi\Service\DmSRsrv \
          vendor\widget\google\adaptation \
          interface\nfc \
          plutommi\CUI\UseDetailCui \
          interface\hal\video_codec \
          custom\drv\measure\Inc \
          custom\common\hal_public \
          custom\codegen\$(strip $(BOARD_VER))\
          interface\hal\graphics \
          interface\hal\fmr \
          plutommi\Service\RightsMgr \
          plutommi\AppCore\SSC \
          venusmmi\app\pluto_variation\LauncherKey\widget\musicplayer \
          plutommi\AppCore\Ucm \
          plutommi\cui\ImageClipCui\ImageClipCuiInc \
          plutommi\Service\TcardSrv \
          plutommi\MtkApp\SafeMode\SafeModeInc \
          hal\system\dcmgr\inc \
          plutommi\Service\SmsSrv

ifneq ($(filter __MMI_LAUNCHER_APP_LIST__ , $(strip $(MODULE_DEFS))),)
INC_DIR += plutommi\MMI\AppList\AppListInc
endif
          
ifeq ($(filter __MTK_TARGET__ , $(strip $(MODULE_DEFS))),)
INC_DIR += MoDIS_VC9\MoDIS  # for w32_utility.h
endif
          
ifneq ($(filter __RF_DESENSE_TEST__, $(strip $(MODULE_DEFS))),)
  INC_DIR += BTMT\rf_desense\$(strip $(PLATFORM))
endif

ifneq ($(filter __SOCIAL_NETWORK_SUPPORT__ , $(strip $(MODULE_DEFS))),)              
   INC_DIR += plutommi\mmi\sns\snsinc
   INC_DIR += plutommi\cui\SnsCui
endif

ifneq ($(filter __MMI_VPP_UPGRADE__, $(strip $(MODULE_DEFS))),)
   INC_DIR += plutommi\MMI\Upgrade\UpgradeInc
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

SRC_PATH += plutommi\AppCore\Ucm
