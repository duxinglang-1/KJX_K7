# Define source file lists to SRC_LIST
SRC_LIST = plutommi\mmi\funandgames\funandgamessrc\funandgamessrc.c \
           plutommi\mmi\funandgames\funandgamessrc\javagame.c \
           plutommi\mmi\funandgames\funandgamessrc\pictureeditor.c \
           plutommi\mmi\funandgames\funandgamessrc\pictureeditorengine.c \
           plutommi\mmi\funandgames\funandgamessrc\pictureeditorhandler.c \
           plutommi\mtkapp\avatar\avatarsrc\avatar.c \
           plutommi\mtkapp\MediaPlayer\MediaPlayerSrc\MediaPlayerMain.c \
           plutommi\mtkapp\MediaPlayer\MediaPlayerSrc\MediaPlayerMsgHandler.c \
           plutommi\mtkapp\MediaPlayer\MediaPlayerSrc\MediaPlayerSingleApp.c \
           plutommi\mtkapp\fmschedulerec\fmschedulerecsrc\fmschedulerec.c \
           plutommi\mtkapp\fmschedulerec\fmschedulerecsrc\fmschedulerecmsghdlr.c \
           plutommi\mtkapp\fmschedulerec\fmschedulerecsrc\fmschedulerecscreen.c \
           plutommi\mtkapp\fmschedulerec\fmschedulerecsrc\fmschedulerecsetting.c \
           plutommi\mtkapp\javaagency\javaagencysrc\javaagencyem.c \
           plutommi\mtkapp\javaagency\javaagencysrc\javaagencymidsinstall.c \
           plutommi\mtkapp\javaagency\javaagencysrc\javaagencysrc.c \
           plutommi\mtkapp\javaagency\javaagencysrc\javaagencytaskswitch.c \
           plutommi\mtkapp\javaagency\javaagencysrc\javaagencytimealarm.c \
           plutommi\mtkapp\javaagency\javaagencysrc\javaagencyutil.c \
           plutommi\mtkapp\javaagency\javaagencysrc\JavaAgencyManager.c \
           plutommi\mtkapp\javaagency\javaagencysrc\JavaAgencyNetworkProfile.c \
           plutommi\mtkapp\javaagency\javaagencysrc\JavaAgencyEMPerformance.c \
           plutommi\mtkapp\javaagency\javaagencysrc\JavaAgencySettings.c \
           plutommi\mtkapp\javaagency\javaagencysrc\JavaAgencyNCenter.cpp \
           plutommi\mtkapp\swflash\swflashsrc\swflashdlsrc.c \
           plutommi\mtkapp\swflash\swflashsrc\swflashplayer.c \
           plutommi\CUI\CameraCui\CameraCui.c \
           plutommi\CUI\CamcorderCui\CamcorderCui.c \
           plutommi\mtkapp\audioplayer\audioplayersrc\audioplayersingleplayer.c \
           plutommi\mtkapp\audioplayer\audioplayersrc\audioplayerutil.c \
           plutommi\cui\ImageClipCui\ImageClipCuiSrc\ImageClipCui.c \
           plutommi\cui\ImageClipCui\ImageClipCuiSrc\ImageClipCuiOSD.c
           
ifneq ($(filter __J2ME__, $(strip $(MODULE_DEFS))),)
	ifneq ($(filter __MVM__, $(strip $(MODULE_DEFS))),)
		SRC_LIST +=plutommi\mtkapp\javaagency\javaagencysrc\JavaAgencyUITextBox.c \
		           plutommi\mtkapp\javaagency\javaagencysrc\JavaAgencyUITextField.c \
		           plutommi\mtkapp\javaagency\javaagencysrc\JavaAgencyUIDateField.c \
		           plutommi\mtkapp\javaagency\javaagencysrc\JavaAgencyUIOptionMenu.c \
		           plutommi\mtkapp\javaagency\javaagencysrc\JavaAgencyUICommon.c
	endif
endif

ifneq ($(filter __MMI_MEDIA_PLAYER__, $(strip $(MODULE_DEFS))),)

    SRC_LIST += plutommi\mtkapp\MediaPlayer\MediaPlayerSrc\MediaPlayerSettingSrc.c

    ifneq ($(filter __MMI_MEDIA_PLAYER_FTE__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\mtkapp\MediaPlayer\MediaPlayerSrc\MediaPlayerFTEMainScreen.c
    endif

    ifneq ($(filter __MMI_MEDIA_PLAYER_PLST_DB_STYLE__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\mtkapp\MediaPlayer\MediaPlayerSrc\MediaPlayerPlaylistUI.c
    endif

    ifneq ($(filter __MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\mtkapp\MediaPlayer\MediaPlayerSrc\MediaPlayerPlayListDB.c
    endif

    ifeq ($(filter __MMI_MEDIA_PLAYER_FTE__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\mtkapp\MediaPlayer\MediaPlayerSrc\MediaPlayerMainScreen.c
    endif

    ifneq ($(filter __MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__, $(strip $(MODULE_DEFS))),)
        ifeq ($(filter __MMI_MEDIA_PLAYER_FTE__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\mtkapp\MediaPlayer\MediaPlayerSrc\MediaPlayerPlayList.c
        endif
    endif

    ifneq ($(filter __MMI_KURO_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\mtkapp\MediaPlayer\MediaPlayerSrc\MediaPlayerPlayListKuro.c
        SRC_LIST += plutommi\mtkapp\MediaPlayer\MediaPlayerSrc\MediaPlayerKuroSkin.c
    endif

endif

ifneq ($(filter __MMI_ATV_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mtkapp\mobiletvplayer\mobiletvplayersrc\mobiletvplayer.c
SRC_LIST += plutommi\mtkapp\mobiletvplayer\mobiletvplayersrc\mobiletvplayerOSD.c
endif

ifneq ($(filter __MMI_MOBILE_TV_CMMB_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mtkapp\dtvplayer\dtvplayersrc\dtvplayer.c
SRC_LIST += plutommi\mtkapp\dtvplayer\dtvplayersrc\dtvplayerOSD.c
SRC_LIST += plutommi\mtkapp\dtvplayer\dtvplayersrc\dtvplayerCMMB.c
SRC_LIST += plutommi\mtkapp\dtvplayer\dtvplayerSrc\dtvplayerMBBMS.c
endif




ifneq ($(filter __MMI_IMAGE_VIEWER__, $(strip $(MODULE_DEFS))),)

ifneq ($(filter __MMI_IMAGE_VIEWER_EX__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\mtkapp\camera\camerasrc\imageviewer.c
    SRC_LIST += plutommi\mtkapp\camera\camerasrc\imageviewerCommon.c
    SRC_LIST += plutommi\CUI\ImageViewCui\ImageViewCui.c
    SRC_LIST += plutommi\mtkapp\camera\camerasrc\imageviewerEXApp.c
    SRC_LIST += plutommi\mtkapp\camera\camerasrc\imageviewerEXSkin.c
    SRC_LIST += plutommi\mtkapp\camera\camerasrc\ImageViewerExSlidingBar.c
else
    SRC_LIST += plutommi\CUI\ImageViewCui\ImgviewCui.c
    SRC_LIST += plutommi\CUI\ImageViewCui\ImgviewCuiScrn.c
    SRC_LIST += plutommi\mtkapp\ImageView\ImageViewSrc\ImgViewer.c
    SRC_LIST += plutommi\mtkapp\ImageView\ImageViewSrc\ImgViewerSkin.c
    SRC_LIST += plutommi\mtkapp\ImageView\ImageViewSrc\MediaAppPanel.c
	SRC_LIST += plutommi\mtkapp\ImageView\ImageViewSrc\MediaAppFrame.c
    SRC_LIST += plutommi\mtkapp\ImageView\ImageViewSrc\ImgViewUtil.c
    SRC_LIST += plutommi\mtkapp\ImageView\ImageViewSrc\ImgViewerCacheInfc.c
    SRC_LIST += plutommi\mtkapp\ImageView\ImageViewSrc\ImgViewerCacheAdp.c
    SRC_LIST += plutommi\mtkapp\ImageView\ImageViewSrc\ImgViewerCacheMgr.c
    SRC_LIST += plutommi\mtkapp\ImageView\ImageViewSrc\ImgViewerCacheDB.c
endif

endif

ifneq ($(filter __MMI_PHOTOEDITOR__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\mtkapp\photoeditor\photoeditorsrc\photoeditor.c
    SRC_LIST += plutommi\CUI\PhotoEditorCui\photoeditorcui.c
endif

ifneq ($(filter __MMI_CAMCORDER__,$(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\CUI\CamcorderCui\CamcorderCui.c \
            plutommi\mtkapp\camcorder\camcordersrc\camcorderapp.c \
            plutommi\mtkapp\camcorder\camcordersrc\camcorderosd.c \
            plutommi\mtkapp\camcorder\camcordersrc\camcorderfteosd.c \
            plutommi\mtkapp\camcorder\camcordersrc\camcordersetting.c \
            plutommi\mtkapp\camcorder\camcordersrc\camcordersettinghdlr.c
endif

ifneq ($(filter __MMI_SLIDESHOW__, $(strip $(MODULE_DEFS))),)
       SRC_LIST += plutommi\mtkapp\photoeditor\photoeditorsrc\slideshow.c
endif

ifneq ($(filter __MMI_CAMERA__, $(strip $(MODULE_DEFS))),)
    ifeq ($(filter __MMI_CAMCORDER__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\mtkapp\camera\camerasrc\cameraapp.c
        SRC_LIST += plutommi\mtkapp\camera\camerasrc\cameramenu.c
    endif
endif

ifneq ($(filter __MMI_VRSI__,$(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mtkapp\vrsi\vrsisrc\vrsicityquery.c
SRC_LIST += plutommi\mtkapp\vrsi\vrsisrc\vrsidigitdial.c
SRC_LIST += plutommi\mtkapp\vrsi\vrsisrc\vrsigrammar.c
SRC_LIST += plutommi\mtkapp\vrsi\vrsisrc\vrsimaincmd.c
SRC_LIST += plutommi\mtkapp\vrsi\vrsisrc\vrsinamedial.c
SRC_LIST += plutommi\mtkapp\vrsi\vrsisrc\vrsinamequery.c
SRC_LIST += plutommi\mtkapp\vrsi\vrsisrc\vrsiredial.c
SRC_LIST += plutommi\mtkapp\vrsi\vrsisrc\vrsisettings.c
SRC_LIST += plutommi\mtkapp\vrsi\vrsisrc\vrsiprofile.c
SRC_LIST += plutommi\mtkapp\vrsi\vrsisrc\vrsishortcut.c
endif


ifneq ($(filter __MMI_STREAMING_OTAP__,$(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mtkapp\video\videosrc\StreamingOTAP.c
endif

ifneq ($(filter __MMI_MOT_SUPPORT__,$(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\MtkApp\MOT\MOTSrc\MOTApp.c
endif

ifneq ($(filter __MMI_VIDEO_PLAYER__, $(strip $(MODULE_DEFS))),)
       SRC_LIST +=  plutommi\mtkapp\video\videosrc\vdoplyapp.c
else
    ifneq ($(filter __MMI_VIDEO_PLAY_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST +=  plutommi\mtkapp\video\videosrc\vdoplyapp.c
    else
        ifneq ($(filter __MMI_VIDEO_RECORDER__, $(strip $(MODULE_DEFS))),)
            ifeq ($(filter __MMI_CAMCORDER__, $(strip $(MODULE_DEFS))),)
                SRC_LIST +=  plutommi\mtkapp\video\videosrc\vdoplyapp.c
            endif
        endif
    endif
endif


ifneq ($(filter __MMI_AB_REPEATER__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += plutommi\mtkapp\abrepeater\abrepeatersrc\abrepeatermainscreen.c \
           plutommi\mtkapp\abrepeater\abrepeatersrc\abrepeatermsghandler.c \
           plutommi\mtkapp\abrepeater\abrepeatersrc\abrepeatersrc.c
endif
ifneq ($(filter __MMI_BG_SOUND_EFFECT__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += plutommi\mtkapp\bgsound\bgsoundsrc\bgsoundincall.c \
           plutommi\mtkapp\bgsound\bgsoundsrc\bgsoundsetting.c
endif

ifneq ($(filter __MMI_AUDIO_PLAYER__, $(strip $(MODULE_DEFS))),)
	ifneq ($(filter __MMI_FTE_SUPPORT__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += plutommi\mtkapp\audioplayer\audioplayersrc\audioPlayerMainScreen_FTE.c
	SRC_LIST += plutommi\mtkapp\audioplayer\audioplayersrc\audioplayermainscreen.c
	else
	SRC_LIST += plutommi\mtkapp\audioplayer\audioplayersrc\audioplayermainscreen.c
	endif
	SRC_LIST +=plutommi\mtkapp\audioplayer\audioplayersrc\audioplayermsghandler.c \
           plutommi\mtkapp\audioplayer\audioplayersrc\audioplayerplaylist.c \
           plutommi\mtkapp\audioplayer\audioplayersrc\audioplayersrc.c \
           plutommi\mtkapp\audioplayer\audioplayersrc\audioplayersettings.c \
           plutommi\mtkapp\audioplayer\audioplayersrc\audioplayerdetails.c
endif

ifneq ($(filter __MMI_SOUND_RECORDER__, $(strip $(MODULE_DEFS))),)
		SRC_LIST +=plutommi\mtkapp\soundrecorder\soundrecordersrc\soundrecordermsghandler.c \
		           plutommi\mtkapp\soundrecorder\soundrecordersrc\soundrecordersrc.c \
		           plutommi\mtkapp\sndrec\sndrecsrc\sndrecui.c \
		           plutommi\mtkapp\sndrec\sndrecsrc\sndrecdraw.c \
		           plutommi\mtkapp\sndrec\sndrecsrc\sndrecutil.c \
		           plutommi\mtkapp\sndrec\sndrecsrc\sndrecmsg.c
endif

ifneq ($(filter __MMI_AUTO_ANSWER_MACHINE__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mtkapp\AnswerMachine\AnswerMachineSrc\AnswerMachineSetting.c \
           plutommi\mtkapp\AnswerMachine\AnswerMachineSrc\AnswerMachineSrc.c
endif

ifneq ($(filter __MMI_FM_RADIO__, $(strip $(MODULE_DEFS))),)
	ifneq ($(filter __MMI_FTE_SUPPORT__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += plutommi\mtkapp\fmradio\fmradiosrc\fmradiomainscreen_FTE.c
	else
		ifneq ($(filter __MMI_MAINLCD_96X64__, $(strip $(MODULE_DEFS))),)
        	SRC_LIST += plutommi\mtkapp\fmradio\fmradiosrc\fmradiomainscreen_BW.c
    	else
	        SRC_LIST += plutommi\mtkapp\fmradio\fmradiosrc\fmradiomainscreen.c
	    endif
	endif
	SRC_LIST += plutommi\mtkapp\fmradio\fmradiosrc\fmradiomsghdlr.c \
	           plutommi\mtkapp\fmradio\fmradiosrc\fmradiosrc.c \
	           plutommi\mtkapp\fmradio\fmradiosrc\FMRadioSchd.c
endif

ifneq ($(filter __MMI_VIDEO_RECORDER__,$(strip $(MODULE_DEFS))),)
    SRC_LIST += plutommi\mtkapp\video\videosrc\vdorecapp.c
    SRC_LIST += plutommi\CUI\VdoRecCui\VdoRecCui.c
else
    ifneq ($(filter __MMI_CAMCORDER__,$(strip $(MODULE_DEFS))),)
        SRC_LIST += plutommi\CUI\VdoRecCui\VdoRecCui.c
    endif
endif

ifneq ($(filter __ATV_SMS_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\mtkapp\mobiletvplayer\MtvSMSSrc\mtvsmsmain.c \
            plutommi\mtkapp\mobiletvplayer\MtvSMSSrc\MtvSmsViewer.c \
            plutommi\mtkapp\mobiletvplayer\MtvSMSSrc\MtvSmsTemplates.c \
            plutommi\mtkapp\mobiletvplayer\MtvSMSSrc\MtvSmsSendMsg.c \
            plutommi\mtkapp\mobiletvplayer\MtvSMSSrc\MtvSmsList.c \
            plutommi\mtkapp\mobiletvplayer\MtvSMSSrc\MtvSmsEditor.c \
            plutommi\mtkapp\mobiletvplayer\MtvSMSSrc\MtvSmsCommon.c \
            plutommi\mtkapp\mobiletvplayer\MtvSMSSrc\mtvsmsphb.c
endif

ifneq ($(filter __MMI_YOUTUBE_SHORTCUT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += plutommi\MMI\YouTuBe\YouTuBeSrc\YouTuBeMain.c
endif


# Define include path lists to INC_DIR
INC_DIR = applib\inet\engine\include \
          applib\mem\include \
          applib\misc\include \
          hal\system\dcmgr\inc \
          drv\include \
          fmt\include \
          fs\fat\include \
          interface\hwdrv \
          interface\hal\drv_sw_def \
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
          plutommi\Framework\InputMethod\Engine\Engine_Inc \
          plutommi\Framework\InputMethod\Inc \
          plutommi\Framework\InputMethod\UI\UI_Inc \
          plutommi\Framework\GDI\gdiinc \
          plutommi\service\mdi\mdiinc \
          plutommi\MMI\YouTuBe\YouTuBeInc \
          plutommi\mtkapp\mtkappinc \
          vendor\inputmethod\cstar\adaptation\include \
          vendor\inputmethod\t9\adaptation\include \
          btstacka\inc \
          custom\common\hal_public \
          drm\include \
          hal\peripheral\inc \
          init\include \
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
          plutommi\CUI\Inc \
          plutommi\mmi\athandler\athandlerinc \
          plutommi\mmi\audio\audioinc \
          plutommi\Framework\BIDI\bidiinc \
          plutommi\mmi\browserapp\browser\browserinc \
          plutommi\mmi\browserapp\pushinbox\pushinboxinc \
          plutommi\Framework\CommonScreens\commonscreensinc \
          plutommi\mmi\connectmanagement\connectmanagementinc \
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
          plutommi\Service\Inc \
          plutommi\mmi\unifiedcomposer\unifiedcomposerinc \
          plutommi\mmi\unifiedmessage\unifiedmessageinc \
          plutommi\mmi\unifiedmms\mmsapp\mmsappinc \
          plutommi\Service\UmmsSrv \
          plutommi\mmi\voip\voipinc \
          plutommi\mtkapp\abrepeater\abrepeaterinc \
          plutommi\mtkapp\audioplayer\audioplayerinc \
          plutommi\mtkapp\avatar\avatarinc \
          plutommi\mtkapp\bgsound\bgsoundinc \
          plutommi\mtkapp\camera\camerainc \
          plutommi\mtkapp\camcorder\camcorderinc \
          plutommi\mtkapp\MediaPlayer\MediaPlayerInc \
          plutommi\MtkApp\MOT\MOTInc  \
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
          plutommi\mtkapp\dtvplayer\dtvplayerinc \
          plutommi\mtkapp\myfavorite\myfavoriteinc \
          plutommi\mtkapp\photoeditor\photoeditorinc \
          plutommi\mtkapp\pictbridge\pictbridgeinc \
          plutommi\mtkapp\rightsmgr\rightsmgrinc \
          plutommi\mtkapp\soundrecorder\soundrecorderinc \
          plutommi\mtkapp\sndrec\sndrecinc \
          plutommi\mtkapp\AnswerMachine\AnswerMachineInc \
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
          vendor\wap\obigo_Q03C\v1_official\msf\msf_lib\config \
          vendor\wap\obigo_Q03C\v1_official\msf\msf_lib\export \
          vendor\wap\obigo_Q03C\v1_official\msf\msf_lib\intgr \
          vendor\wap\obigo_Q03C\adaptation\modules\mma\include \
          vendor\wap\obigo_Q03C\adaptation\msf_ui\include \
          plutommi\mmi\UDX\UDXInc \
          applib\sqlite3\inc \
          media\bitstream\include \
          vendor\player\ipeer\inc \
          vendor\player\ipeer\adaptation\inc \
          plutommi\CUI\VdoRecCui \
          plutommi\CUI\CameraCui \
          plutommi\CUI\CamcorderCui \
          plutommi\CUI\ImageViewCui \
          plutommi\CUI\PhotoEditorCui \
          plutommi\mtkapp\DCD\DCDInc \
          venusmmi\vrt\interface \
          venusmmi\framework \
          venusmmi\framework\interface \
          venusmmi\visual \
          venusmmi\visual\interface \
          venusmmi\test \
          venusmmi\app \
          venusmmi\app\Cosmos\interface\app \
          venusmmi\app\common\wallpaper \
          venusmmi\app\common\ncenter \
          venusmmi\app\common\interface\app \
          venusmmi\framework\ui_core\mvc \
          vendor\widget\google\adaptation \
          vendor\wap\obigo_q03c\adaptation\integration\include \
          venusmmi\app\pluto_variation\adapter \
          venusmmi\app\pluto_variation\adapter\interface \
          venusmmi\app\pluto_variation\adapter\interface\res \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel\HomeScreen \
          plutommi\Service\ProfilesSrv \
          plutommi\MtkApp\GPS\GPSInc \
          plutommi\mtkapp\MREAPP\MREAPPInc \
          plutommi\Service\UMSrv \
          plutommi\service\appmgrsrv \
          plutommi\Service\ImgEdtSrv \
          plutommi\mtkapp\MobileTVPlayer\MtvSMSInc \
          plutommi\mmi\phonebook\core \
          plutommi\Framework\LangModule\langmoduleinc \
          vendor\intergrafx\Game\Adaptation \
          vendor\intergrafx\Engine\IGV3Inc \
          plutommi\Service\JavaAppFactorySrv \
          vendor\intergrafx\Game\Launcher \
		  plutommi\mtkapp\ImageView\ImageViewInc \
		  btmt\rf_desense \
          custom\common\hal_public \
          plutommi\mmi\Sns\SnsInc \
          plutommi\cui\ImageClipCui\ImageClipCuiInc \
          vendor\cmmb\adp\inc \

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
INC_DIR += venusmmi\app\Cosmos\Ucm
else
INC_DIR += plutommi\mmi\Ucm\UcmInc
endif

ifneq ($(filter __MMI_NCENTER_SUPPORT__, $(strip $(MODULE_DEFS))),)
INC_DIR += venusmmi\app\Cosmos\JavaApp \
           venusmmi\framework\ui_core\pme \
           venusmmi\framework\mmi_core \
           venusmmi\app\common \
           venusmmi\app\common\ime \
           venusmmi\visual\cp \
           venusmmi\visual\cp\cosmos \
           venusmmi\visual\cp\common \
           venusmmi\visual\cp\fte
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



