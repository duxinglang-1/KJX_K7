# Define source file lists to SRC_LIST
SRC_LIST =  mre\custom\sal\vmapparray.c \
			mre\custom\sal\vmcamera.c \
			mre\custom\sal\vmchset.c \
			mre\custom\sal\vmime.c \
			mre\custom\sal\vmeditor.c \
			mre\custom\sal\vmmacrostub.c \
			mre\custom\sal\vmsalsensor.c \
			mre\custom\sal\vmsim.c \
			mre\custom\sal\vmua.c \
			mre\custom\sal\vmsettings.cpp \
			mre\custom\sal\vmshortcutarray.c \
			mre\custom\sal\vmsparray.c
			
SRC_LIST +=  mre\custom\romapp\mre_app_qq2010_vxp.c
SRC_LIST +=  mre\custom\romapp\mre_app_qqbrowser_vxp.c
SRC_LIST +=  mre\custom\romapp\mre_app_opera_vxp.c
SRC_LIST += mre\custom\romapp\mre_qq_vsm.c
SRC_LIST += mre\custom\romapp\mre_helloworld_vso.c

ifneq ($(filter __MMI_MRE_APP_CALCULATOR__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=  mre\custom\romapp\mre_app_calculator_vxp.c
endif

ifneq ($(filter __MMI_MRE_APP_OPERA_MINI_V6__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=  mre\custom\romapp\mre_app_opera_V6_1_RC2_vxp.c
endif

ifneq ($(filter __MMI_MRE_APP_CONVERTER__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=  mre\custom\romapp\mre_app_converter_vxp.c
endif

ifneq ($(filter __MMI_MRE_APP_HEALTH__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=  mre\custom\romapp\mre_app_health_vxp.c
endif

ifneq ($(filter __MMI_MRE_APP_ZY_EBOOK__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=  mre\custom\romapp\mre_app_ebook_vxp.c
endif

ifneq ($(filter __MMI_MRE_APP_YOUTUBE__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=  mre\custom\romapp\mre_app_YouTube.c
endif


ifneq ($(filter __MMI_MRE_GAME_EGYPTCODE_EN__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=  mre\custom\romapp\mtone_games\mre_app_egypt_code_en_vxp.c
endif

ifneq ($(filter __MMI_MRE_GAME_EGYPTCODE_CHS__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=  mre\custom\romapp\mtone_games\mre_app_egypt_code_chs_vxp.c
endif

ifneq ($(filter __MMI_MRE_GAME_GIRLSLOT_EN__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=  mre\custom\romapp\mtone_games\mre_app_girl_slot_en_vxp.c
endif

ifneq ($(filter __MMI_MRE_GAME_GIRLSLOT_CHS__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=  mre\custom\romapp\mtone_games\mre_app_girl_slot_chs_vxp.c
endif

ifneq ($(filter __MMI_MRE_GAME_GOLDMINER_EN__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=  mre\custom\romapp\mtone_games\mre_app_gold_miner_en_vxp.c
endif

ifneq ($(filter __MMI_MRE_GAME_GOLDMINER_CHS__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=  mre\custom\romapp\mtone_games\mre_app_gold_miner_chs_vxp.c
endif

ifneq ($(filter __MMI_MRE_GAME_HAPPYEGG_EN__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=  mre\custom\romapp\mtone_games\mre_app_happy_egg_en_vxp.c
endif

ifneq ($(filter __MMI_MRE_GAME_HAPPYEGG_CHS__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=  mre\custom\romapp\mtone_games\mre_app_happy_egg_chs_vxp.c
endif

ifneq ($(filter __MMI_MRE_GAME_HAPPYWAR_EN__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=  mre\custom\romapp\mtone_games\mre_app_happy_war_en_vxp.c
endif

ifneq ($(filter __MMI_MRE_GAME_HAPPYWAR_CHS__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=  mre\custom\romapp\mtone_games\mre_app_happy_war_chs_vxp.c
endif

ifneq ($(filter __MMI_MRE_GAME_KINGCOMBAT_EN__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=  mre\custom\romapp\mtone_games\mre_app_king_combat_en_vxp.c
endif

ifneq ($(filter __MMI_MRE_GAME_KINGCOMBAT_CHS__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=  mre\custom\romapp\mtone_games\mre_app_king_combat_chs_vxp.c
endif

ifneq ($(filter __MMI_MRE_GAME_MOTO_EN__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=  mre\custom\romapp\mtone_games\mre_app_moto_en_vxp.c
endif

ifneq ($(filter __MMI_MRE_GAME_MOTO_CHS__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=  mre\custom\romapp\mtone_games\mre_app_moto_chs_vxp.c
endif

ifneq ($(filter __MMI_MRE_GAME_PARKOUR_EN__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=  mre\custom\romapp\mtone_games\mre_app_parkour_en_vxp.c
endif

ifneq ($(filter __MMI_MRE_GAME_PARKOUR_CHS__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=  mre\custom\romapp\mtone_games\mre_app_parkour_chs_vxp.c
endif

ifneq ($(filter __MMI_MRE_GAME_TEARDRESS_EN__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=  mre\custom\romapp\mtone_games\mre_app_tear_dress_en_vxp.c
endif

ifneq ($(filter __MMI_MRE_GAME_TEARDRESS_CHS__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=  mre\custom\romapp\mtone_games\mre_app_tear_dress_chs_vxp.c
endif

ifneq ($(filter __MMI_MRE_APP_STOPWATCH__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=  mre\custom\romapp\mre_app_stopwatch_vxp.c
endif

ifneq ($(filter __MMI_MRE_APP_ZAKAT__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=  mre\custom\romapp\mre_app_zakat_vxp.c
endif

ifneq ($(filter __MMI_MRE_APP_3GT_GAME_BOWLING_ENG__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += mre\custom\romapp\mre_app_3GT_Game_Bowling_ENG_vxp.c
endif

ifneq ($(filter __MMI_MRE_APP_3GT_GAME_BOWLING_CHS__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += mre\custom\romapp\mre_app_3GT_Game_Bowling_CHS_vxp.c
endif

ifneq ($(filter __MMI_MRE_APP_3GT_GAME_BOWLING_CHT__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += mre\custom\romapp\mre_app_3GT_Game_Bowling_CHT_vxp.c
endif

ifneq ($(filter __MMI_MRE_APP_3GT_GAME_DANDELION__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += mre\custom\romapp\mre_app_3GT_Game_DanDelion_vxp.c
endif

ifneq ($(filter __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHS__ __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHT__ __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_ENG__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += mre\custom\romapp\3gt\rash_motor\mre_app_3GT_Rash_Motor_vxp.c
endif

ifneq ($(filter __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHS__ __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHT__ __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_ENG__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += mre\custom\romapp\3gt\balance_ball\mre_app_3GT_Balance_Ball_vxp.c
endif

ifneq ($(filter __MMI_MRE_APP_FBLITE__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += mre\custom\romapp\facebook\facebooklite\mre_app_facebook_lite.c
endif

ifneq ($(filter __MMI_MRE_APP_FBLITEV11__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += mre\custom\romapp\facebook\facebooklite\mre_app_facebook_lite_v11.c
endif

ifneq ($(filter __MMI_MRE_APP_YAHOOMV1__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += mre\custom\romapp\yahoo\mre_app_yahoo_messengerv1.c
endif

ifneq ($(filter __MMI_MRE_APP_YAHOOMV2__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += mre\custom\romapp\yahoo\mre_app_yahoo_messengerv2.c
	SRC_LIST += mre\custom\romapp\yahoo\mre_app_yahoo_messengerv2_SSL_vsm.c
	SRC_LIST += mre\custom\romapp\yahoo\mre_app_yahoo_messengerv2_UI_vsm.c
endif

ifneq ($(filter __MMI_MRE_APP_YAHOOFINANCE__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += mre\custom\romapp\yahoo\mre_app_yahoo_finance.c
endif
ifneq ($(filter __MMI_MRE_APP_YAHOONEWS__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += mre\custom\romapp\yahoo\mre_app_yahoo_news.c
endif
ifneq ($(filter __MMI_MRE_APP_YAHOOWEATHER__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += mre\custom\romapp\yahoo\mre_app_yahoo_weather.c
endif
ifneq ($(filter __MMI_MRE_APP_YAHOOCRICKET__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += mre\custom\romapp\yahoo\mre_app_yahoo_cricket.c
endif
    
ifneq ($(filter __MMI_MRE_APP_RENREN__, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=  mre\custom\romapp\renren\mre_app_renren_vxp.c
endif

ifneq ($(filter __MMI_MRE_APP_KAIXIN__, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=  mre\custom\romapp\kaixin\mre_app_kaixin_vxp.c
endif

ifneq ($(filter __MMI_MRE_APP_GAMELOFT_CN_PACKAGE1__, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=  mre\custom\romapp\gameloft\mre_gameloft_games_cn_package1.c
endif

ifneq ($(filter __MMI_MRE_APP_GAMELOFT_CN_PACKAGE2__, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=  mre\custom\romapp\gameloft\mre_gameloft_games_cn_package2.c
endif

ifneq ($(filter __MMI_MRE_APP_GAMELOFT_CN_PACKAGE3__, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=  mre\custom\romapp\gameloft\mre_gameloft_games_cn_package3.c
endif

ifneq ($(filter __MMI_MRE_APP_GAMELOFT_CN_PACKAGE4__, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=  mre\custom\romapp\gameloft\mre_gameloft_games_cn_package4.c
endif

ifneq ($(filter __MMI_MRE_APP_GAMELOFT_GB_PACKAGE1__, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=  mre\custom\romapp\gameloft\mre_gameloft_games_gb_package1.c
endif

ifneq ($(filter __MMI_MRE_APP_GAMELOFT_GB_PACKAGE2__, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=  mre\custom\romapp\gameloft\mre_gameloft_games_gb_package2.c
endif

ifneq ($(filter __MMI_MRE_APP_GAMELOFT_GB_PACKAGE3__, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=  mre\custom\romapp\gameloft\mre_gameloft_games_gb_package3.c
endif

ifneq ($(filter __MMI_MRE_APP_GAMELOFT_GB_PACKAGE4__, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=  mre\custom\romapp\gameloft\mre_gameloft_games_gb_package4.c
endif

ifneq ($(filter __MMI_MRE_APP_GAMELOFT_AS6_CN_MT6250__ __MMI_MRE_APP_GAMELOFT_AS6_GB_MT6250__, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=  mre\custom\romapp\gameloft\mre_gameloft_games.c
endif

ifneq ($(filter __MMI_MRE_APP_FACEBOOK_V2__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += mre\custom\romapp\facebook\facebooklite\mre_app_facebook_v2.c
endif

ifneq ($(filter __MMI_MRE_APP_YOUKU__, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=  mre\custom\romapp\youku\mre_app_youku_vxp.c
endif

ifneq ($(filter __MMI_MRE_APP_TWITTER__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += mre\custom\romapp\twitter\mre_app_twitter.c
endif

ifneq ($(filter __MMI_MRE_APP_ANGRYBIRDS_EN__, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=  mre\custom\romapp\kkfun\mre_app_AngryBird_EN.c
endif

ifneq ($(filter __MMI_MRE_APP_ANGRYBIRDS_SC__, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=  mre\custom\romapp\kkfun\mre_app_AngryBird_SC.c
endif

ifneq ($(filter __MMI_MRE_APP_FRUITNINJA_EN__, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=  mre\custom\romapp\kkfun\mre_app_FruitNinja_EN.c
endif

ifneq ($(filter __MMI_MRE_APP_FRUITNINJA_SC__, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=  mre\custom\romapp\kkfun\mre_app_FruitNinja_SC.c
endif

ifneq ($(filter __MMI_MRE_APP_FISHINGFUN_EN__, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=  mre\custom\romapp\kkfun\mre_app_FishingFun_EN.c
endif

ifneq ($(filter __MMI_MRE_APP_FISHINGFUN_SC__, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=  mre\custom\romapp\kkfun\mre_app_FishingFun_SC.c
endif

ifneq ($(filter __MMI_MRE_APP_FACEBOOK_V2_STANDARD__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += mre\custom\romapp\facebook\facebooklite\mre_app_facebook_v2_standard.c
	SRC_LIST += mre\custom\romapp\facebook\facebooklite\mre_app_facebook_v2_vsm.c
endif

ifneq ($(filter __MMI_MRE_APP_GAMELOFT_2ND_PACKAGE__, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=  mre\custom\romapp\gameloft\mre_gameloft_2nd_wave_package.c
endif

ifneq ($(filter __MMI_MRE_APP_WOCHACHA__, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=  mre\custom\romapp\wochacha\mre_app_wochacha_vxp.c
endif

ifneq ($(filter __MMI_MRE_APP_MITAKE_MSTOCK__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += mre\custom\romapp\mitake\mre_app_mitake_mstock_vxp.c
endif

ifneq ($(filter __MMI_MRE_APP_SINA_WEIBO__, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=  mre\custom\romapp\sina\mre_app_sina_weibo_vxp.c
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
          $(strip $(PS_FOLDER))\interfaces\local_inc \
          plutommi\VendorApp\appsdk\appsdkinc \
          plutommi\mtkapp\MREAPP\MREAPPInc \
          plutommi\CUI\Inc \
          venusmmi\app\common\
          venusmmi\app\common\ime\
          venusmmi\app\Cosmos\interface\app \
          venusmmi\app\pluto_variation\adapter\
          venusmmi\app\pluto_variation\adapter\interface\
          venusmmi\app\pluto_variation\adapter\interface\res\
          venusmmi\app\pluto_variation\adapter\ime\
          venusmmi\framework\
          venusmmi\framework\interface\
          venusmmi\framework\mmi_core\
          venusmmi\framework\ui_core\base \
          venusmmi\framework\ui_core\mvc \
          venusmmi\framework\ui_core\pme \
          venusmmi\visual\
          venusmmi\visual\cp\
          venusmmi\visual\cp\common \
          venusmmi\visual\cp\cosmos \
          venusmmi\visual\cp\fte \
          venusmmi\visual\interface\
          venusmmi\vrt\
          venusmmi\vrt\interface\
          plutommi\Service\Inc \
          plutommi\Service\ummssrv\
          plutommi\framework\bidi\bidiinc\
          plutommi\Framework\InputMethod\Engine\Engine_Inc \
          plutommi\Framework\InputMethod\UI\UI_Inc \
          verno

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
INC_DIR += venusmmi\app\Cosmos\Ucm
else
INC_DIR += plutommi\mmi\Ucm\UcmInc
endif

# Define the specified compile options to COMP_DEFS
COMP_DEFS = MMI_ON_HARDWARE_P  \
            __UCS2_ENCODING
 
 
