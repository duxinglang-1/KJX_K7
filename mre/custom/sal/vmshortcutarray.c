#include "MREAppMgrSrvGprot.h"
#include "mmi_rp_app_am_def.h"
#define MRE_DEFAULT_UPDATE_URL "http://appupgrade.services-mtk.com/gmas/AppsUpdate"
/*
srv_mre_appmgr_shortcut_vsm_info_struct g_app1_vsm = 
{
    0x0100a5,
    "app1.vsm",
    0
};
*/
/* Shortcut app list */
srv_mre_appmgr_shortcut_info_struct g_shortcut_info_list[] = 
{
    {0,
     0,
     0,
     0,
     0
     },
/*     
     {0x0100a4,
     IMG_GLOBAL_OK,
     STR_GLOBAL_0,
     MRE_DEFAULT_UPDATE_URL,
     &g_app1_vsm
     },
     {0x0100a5,
     IMG_GLOBAL_OK,
     STR_GLOBAL_1,
     MRE_DEFAULT_UPDATE_URL,
     0
     },
     */
#if 0
#ifdef __MMI_MRE_SHORTCUT_QQ__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#ifdef __MMI_MRE_SHORTCUT_OPERA__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
#ifdef __MMI_MRE_APP_CALCULATOR_SHORTCUT__
    {
    #if defined(__MMI_MAINLCD_176X220__)
        67140,
    #elif defined(__MMI_MAINLCD_320X240__)
        67141,
    #elif defined(__MMI_MAINLCD_240X320__)
        67142,
    #elif defined(__MMI_MAINLCD_240X400__)
        67143,
    #elif defined(__MMI_MAINLCD_320X480__)
        67144,
    #elif defined(__MMI_MAINLCD_480X800__)
        67145,
    #else
        0,
    #endif
        IMG_ID_AM_APP_CALCULATOR_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_CALCULATOR,   /* name resource id */
        MRE_DEFAULT_UPDATE_URL,
        0
     },
#endif
#ifdef __MMI_MRE_APP_HEALTH_SHORTCUT__
    {
    #if defined(__MMI_MAINLCD_176X220__)
        67150,
    #elif defined(__MMI_MAINLCD_320X240__)
        67151,
    #elif defined(__MMI_MAINLCD_240X320__)
        67152,
    #elif defined(__MMI_MAINLCD_240X400__)
        67153,
    #elif defined(__MMI_MAINLCD_320X480__)
        67154,
    #elif defined(__MMI_MAINLCD_480X800__)
        67155,
    #else
        0,
    #endif
        IMG_ID_AM_APP_HEALTH_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_HEALTH,   /* name resource id */
        MRE_DEFAULT_UPDATE_URL,
        0
     },
#endif
#ifdef __MMI_MRE_APP_STOPWATCH_SHORTCUT__
    {
    #if defined(__MMI_MAINLCD_176X220__)
        67160,
    #elif defined(__MMI_MAINLCD_320X240__)
        67161,
    #elif defined(__MMI_MAINLCD_240X320__)
        67162,
    #elif defined(__MMI_MAINLCD_240X400__)
        67163,
    #elif defined(__MMI_MAINLCD_320X480__)
        67164,
    #elif defined(__MMI_MAINLCD_480X800__)
        67165,
    #else
        0,
    #endif
        IMG_ID_AM_APP_STOPWATCH_SHORTCUT,          /* icon resource id */
        STR_ID_AM_APP_NAME_STOPWATCH,      /* name resource id */
        MRE_DEFAULT_UPDATE_URL,
        0
     },
#endif
#ifdef __MMI_MRE_APP_CONVERTER_SHORTCUT__
    {
    #if defined(__MMI_MAINLCD_176X220__)
        67170,
    #elif defined(__MMI_MAINLCD_320X240__)
        67171,
    #elif defined(__MMI_MAINLCD_240X320__)
        67172,
    #elif defined(__MMI_MAINLCD_240X400__)
        67173,
    #elif defined(__MMI_MAINLCD_320X480__)
        67174,
    #elif defined(__MMI_MAINLCD_480X800__)
        67175,
    #else
        0,
    #endif
        IMG_ID_AM_APP_CONVERTER_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_CONVERTER,   /* name resource id */
        MRE_DEFAULT_UPDATE_URL,
        0
     },
#endif
#ifdef __MMI_MRE_APP_ZAKAT_SHORTCUT__
    {
    #if defined(__MMI_MAINLCD_176X220__)
        67180,
    #elif defined(__MMI_MAINLCD_320X240__)
        67181,
    #elif defined(__MMI_MAINLCD_240X320__)
        67182,
    #elif defined(__MMI_MAINLCD_240X400__)
        67183,
    #elif defined(__MMI_MAINLCD_320X480__)
        67184,
    #elif defined(__MMI_MAINLCD_480X800__)
        67185,
    #else
        0,
    #endif
        IMG_ID_AM_APP_ZAKAT_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_ZAKAT,   /* name resource id */
        MRE_DEFAULT_UPDATE_URL,
        0
     },
#endif
#ifdef __MMI_MRE_GAME_EGYPTCODE_EN_SHORTCUT__
    {
    #if defined(__MMI_MAINLCD_176X220__)
        67000,
    #elif defined(__MMI_MAINLCD_240X320__)
        67001,
    #elif defined(__MMI_MAINLCD_240X400__)
        67002,
    #elif defined(__MMI_MAINLCD_320X480__)
        67003,
    #elif defined(__MMI_MAINLCD_480X800__)
        67004,
    #else
        0,
    #endif
        IMG_ID_AM_APP_EGYPTCODE_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_EGYPTCODE,   /* name resource id */
        MRE_DEFAULT_UPDATE_URL,
        0
     },
#endif
#ifdef __MMI_MRE_GAME_GIRLSLOT_EN_SHORTCUT__
    {
    #if defined(__MMI_MAINLCD_176X220__)
        67010,
    #elif defined(__MMI_MAINLCD_240X320__)
        67011,
    #elif defined(__MMI_MAINLCD_240X400__)
        67012,
    #elif defined(__MMI_MAINLCD_320X480__)
        67013,
    #elif defined(__MMI_MAINLCD_480X800__)
        67014,
    #else
        0,
    #endif
        IMG_ID_AM_APP_GIRLSLOT_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_GIRLSLOT,   /* name resource id */
        MRE_DEFAULT_UPDATE_URL,
        0
     },
#endif
#ifdef __MMI_MRE_GAME_GOLDMINER_EN_SHORTCUT__
    {
    #if defined(__MMI_MAINLCD_176X220__)
        67040,
    #elif defined(__MMI_MAINLCD_320X240__)
        67041,
    #elif defined(__MMI_MAINLCD_240X320__)
        67042,
    #elif defined(__MMI_MAINLCD_240X400__)
        67043,
    #elif defined(__MMI_MAINLCD_320X480__)
        67044,
    #elif defined(__MMI_MAINLCD_480X800__)
        67045,
    #else
        0,
    #endif
        IMG_ID_AM_APP_GOLDMINER_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_GOLDMINER,   /* name resource id */
        MRE_DEFAULT_UPDATE_URL,
        0
     },
#endif
#ifdef __MMI_MRE_GAME_HAPPYEGG_EN_SHORTCUT__
    {
    #if defined(__MMI_MAINLCD_128X160__)
        67080,
    #elif defined(__MMI_MAINLCD_176X220__)
        67081,
    #elif defined(__MMI_MAINLCD_320X240__)
        67082,
    #elif defined(__MMI_MAINLCD_240X320__)
        67083,
    #elif defined(__MMI_MAINLCD_240X400__)
        67084,
    #elif defined(__MMI_MAINLCD_320X480__)
        67085,
    #elif defined(__MMI_MAINLCD_480X800__)
        67086,
    #else
        0,
    #endif
        IMG_ID_AM_APP_HAPPYEGG_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_HAPPYEGG,   /* name resource id */
        MRE_DEFAULT_UPDATE_URL,
        0
     },
#endif
#ifdef __MMI_MRE_GAME_HAPPYWAR_EN_SHORTCUT__
    {
    #if defined(__MMI_MAINLCD_240X320__)
        67070,
    #elif defined(__MMI_MAINLCD_240X400__)
        67071,
    #elif defined(__MMI_MAINLCD_320X480__)
        67072,
    #elif defined(__MMI_MAINLCD_480X800__)
        67073,
    #else
        0,
    #endif
        IMG_ID_AM_APP_HAPPYWAR_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_HAPPYWAR,   /* name resource id */
        MRE_DEFAULT_UPDATE_URL,
        0
     },
#endif
#ifdef __MMI_MRE_GAME_KINGCOMBAT_EN_SHORTCUT__
    {
    #if defined(__MMI_MAINLCD_176X220__)
        67050,
    #elif defined(__MMI_MAINLCD_240X320__)
        67051,
    #elif defined(__MMI_MAINLCD_240X400__)
        67052,
    #elif defined(__MMI_MAINLCD_320X480__)
        67053,
    #elif defined(__MMI_MAINLCD_480X800__)
        67054,
    #else
        0,
    #endif
        IMG_ID_AM_APP_KINGCOMBAT_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_KINGCOMBAT,   /* name resource id */
        MRE_DEFAULT_UPDATE_URL,
        0
     },
#endif
#ifdef __MMI_MRE_GAME_MOTO_EN_SHORTCUT__
    {
    #if defined(__MMI_MAINLCD_240X320__)
        67020,
    #elif defined(__MMI_MAINLCD_320X480__)
        67021,
    #elif defined(__MMI_MAINLCD_480X800__)
        67022,
    #else
        0,
    #endif
        IMG_ID_AM_APP_MOTO_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_MOTO,   /* name resource id */
        MRE_DEFAULT_UPDATE_URL,
        0
     },
#endif
#ifdef __MMI_MRE_GAME_PARKOUR_EN_SHORTCUT__
    {
    #if defined(__MMI_MAINLCD_176X220__)
        67030,
    #elif defined(__MMI_MAINLCD_240X320__)
        67031,
    #elif defined(__MMI_MAINLCD_240X400__)
        67032,
    #elif defined(__MMI_MAINLCD_320X480__)
        67033,
    #elif defined(__MMI_MAINLCD_480X800__)
        67034,
    #else
        0,
    #endif
        IMG_ID_AM_APP_PARKOUR_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_PARKOUR,   /* name resource id */
        MRE_DEFAULT_UPDATE_URL,
        0
     },
#endif
#ifdef __MMI_MRE_GAME_TEARDRESS_EN_SHORTCUT__
    {
    #if defined(__MMI_MAINLCD_240X320__)
        67060,
    #elif defined(__MMI_MAINLCD_240X400__)
        67061,
    #elif defined(__MMI_MAINLCD_320X480__)
        67062,
    #elif defined(__MMI_MAINLCD_480X800__)
        67063,
    #else
        0,
    #endif
        IMG_ID_AM_APP_TEARDRESS_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_TEARDRESS,   /* name resource id */
        MRE_DEFAULT_UPDATE_URL,
        0
     },
#endif
#ifdef __MMI_MRE_APP_FACEBOOK_V2_SHORTCUT__
    {
    #if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_220X176__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
        1664362580,
    #elif defined(__MMI_MAINLCD_320X480__)
        1664362581,
    #elif defined(__MMI_MAINLCD_480X800__)
        1664362582,
    #else
        0,
    #endif
        IMG_ID_AM_APP_FBLITE_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_FBLITE,   /* name resource id */
        MRE_DEFAULT_UPDATE_URL,
        0
     },
#endif
#ifdef __MMI_MRE_APP_FACEBOOK_V2_STANDARD_SHORTCUT__
    {
    #if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_220X176__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
        1664362583,
    #elif defined(__MMI_MAINLCD_320X480__)
        1664362585,
    #elif defined(__MMI_MAINLCD_480X800__)
        1664362587,
    #else
        0,
    #endif
        IMG_ID_AM_APP_FBLITE_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_FBLITE,   /* name resource id */
        MRE_DEFAULT_UPDATE_URL,
        0
     },
#endif
#ifdef __MMI_MRE_APP_YAHOOMV2_SHORTCUT__
    {
    #if defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
        1664362566,
    #elif defined(__MMI_MAINLCD_480X800__)
        1664362568,
    #else
        0,
    #endif
        IMG_ID_AM_APP_YAHOO_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_YAHOO,   /* name resource id */
        MRE_DEFAULT_UPDATE_URL,
        0
     },
#endif
#ifdef __MMI_MRE_APP_YAHOOFINANCE_SHORTCUT__
    {
    #if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_220X176__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
        1664362554,
    #elif defined(__MMI_MAINLCD_480X800__)
        1664362555,
    #else
        0,
    #endif
        IMG_ID_AM_APP_YAHOOFINANCE_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_YAHOOFINANCE,   /* name resource id */
        MRE_DEFAULT_UPDATE_URL,
        0
     },
#endif
#ifdef __MMI_MRE_APP_YAHOONEWS_SHORTCUT__
    {
    #if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_220X176__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
        1664362556,
    #elif defined(__MMI_MAINLCD_480X800__)
        1664362557,
    #else
        0,
    #endif
        IMG_ID_AM_APP_YAHOONEWS_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_YAHOONEWS,   /* name resource id */
        MRE_DEFAULT_UPDATE_URL,
        0
     },
#endif
#ifdef __MMI_MRE_APP_YAHOOWEATHER_SHORTCUT__
    {
    #if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_220X176__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
        1664362558,
    #elif defined(__MMI_MAINLCD_480X800__)
        1664362559,
    #else
        0,
    #endif
        IMG_ID_AM_APP_YAHOOWEATHER_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_YAHOOWEATHER,   /* name resource id */
        MRE_DEFAULT_UPDATE_URL,
        0
     },
#endif
#ifdef __MMI_MRE_APP_YAHOOCRICKET_SHORTCUT__
    {
    #if defined(__MMI_MAINLCD_128X160__)
        65705,
    #elif defined(__MMI_MAINLCD_176X220__)
        65701,
    #elif defined(__MMI_MAINLCD_320X240__)
        65704,
    #elif defined(__MMI_MAINLCD_240X320__)
        65702,
    #elif defined(__MMI_MAINLCD_240X400__)
        65703,
    #elif defined(__MMI_MAINLCD_320X480__)
        65700,
    #else
        0,
    #endif
        IMG_ID_AM_APP_YAHOOCRICKET_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_YAHOOCRICKET,   /* name resource id */
        MRE_DEFAULT_UPDATE_URL,
        0
     },
#endif
#ifdef __MMI_MRE_APP_TWITTER_SHORTCUT__
    {
    #if defined(__MMI_MAINLCD_128X160__)
        65850,
    #elif defined(__MMI_MAINLCD_176X220__)
        65851,
    #elif defined(__MMI_MAINLCD_220X176__)
        65852,
    #elif defined(__MMI_MAINLCD_320X240__)
        #if defined (__MMI_MRE_APP_TWITTER_KEY_SUPPORT__) && !defined (__MMI_MRE_APP_TWITTER_CAMERA_SUPPORT__)
        65855,
	#endif
        #if defined (__MMI_MRE_APP_TWITTER_KEY_SUPPORT__) && defined (__MMI_MRE_APP_TWITTER_CAMERA_SUPPORT__)
        65856,
        #endif
    #elif defined(__MMI_MAINLCD_240X320__)
        #if defined (__MMI_MRE_APP_TWITTER_KEY_SUPPORT__) && !defined (__MMI_MRE_APP_TWITTER_CAMERA_SUPPORT__)
        65853,
	#endif
        #if defined (__MMI_MRE_APP_TWITTER_KEY_SUPPORT__) && defined (__MMI_MRE_APP_TWITTER_CAMERA_SUPPORT__)
        65854,
        #endif
    #elif defined(__MMI_MAINLCD_240X400__)
        #if defined (__MMI_MRE_APP_TWITTER_KEY_SUPPORT__) && defined (__MMI_MRE_APP_TWITTER_CAMERA_SUPPORT__)
        65857,
	#endif
        #if !defined (__MMI_MRE_APP_TWITTER_KEY_SUPPORT__) && defined (__MMI_MRE_APP_TWITTER_CAMERA_SUPPORT__)
        65858,
        #endif
    #elif defined(__MMI_MAINLCD_320X480__)
        #if defined (__MMI_MRE_APP_TWITTER_KEY_SUPPORT__) && !defined (__MMI_MRE_APP_TWITTER_CAMERA_SUPPORT__)
        65862,
	#endif
        #if defined (__MMI_MRE_APP_TWITTER_KEY_SUPPORT__) && defined (__MMI_MRE_APP_TWITTER_CAMERA_SUPPORT__)
        65859,
	#endif
	#if !defined (__MMI_MRE_APP_TWITTER_KEY_SUPPORT__) && !defined (__MMI_MRE_APP_TWITTER_CAMERA_SUPPORT__)
	65863,
        #endif
	#if !defined (__MMI_MRE_APP_TWITTER_KEY_SUPPORT__) && defined (__MMI_MRE_APP_TWITTER_CAMERA_SUPPORT__)
	65860,
	#endif
    #elif defined(__MMI_MAINLCD_480X800__)
	#if defined (__MMI_MRE_APP_TWITTER_CAMERA_SUPPORT__)
        65861,
	#endif
    #else
        0,
    #endif
        IMG_ID_AM_APP_TWITTER_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_TWITTER,   /* name resource id */
        MRE_DEFAULT_UPDATE_URL,
        0
     },
#endif
#ifdef __MMI_MRE_APP_GAMELOFT_LIVE_SHORTCUT__
    {
    #if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
        67190,
    #elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)
        67191,
    #else 
		0,
    #endif
        IMG_ID_AM_APP_GAMELOFT_GLIVE_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_GAMELOFT_GLIVE,   /* name resource id */
        "http://wapshop.gameloft.com/misc/mtk/directdl.php",
        0
     },
#endif
#ifdef __MMI_MRE_APP_GAMELOFT_BC_SHORTCUT__
    {
    #if defined (__MMI_MAINLCD_240X320__)
        67300,
    #elif defined (__MMI_MAINLCD_240X400__)
        67301,
	#elif defined (__MMI_MAINLCD_320X480__)
		67302,
	#elif defined (__MMI_MAINLCD_480X800__)
		67303,
	#elif defined (__MMI_MAINLCD_176X220__)
		67304,
	#elif defined (__MMI_MAINLCD_320X240__)
		67305,
    #else
		0,
    #endif
        IMG_ID_AM_APP_GAMELOFT_BC_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_GAMELOFT_BRAINCHALLENGE,   /* name resource id */
        "http://wapshop.gameloft.com/misc/mtk/directdl.php",
        0
     },
#endif
#ifdef __MMI_MRE_APP_GAMELOFT_BB_SHORTCUT__
    {
   #if defined (__MMI_MAINLCD_240X320__)
        67260,
    #elif defined (__MMI_MAINLCD_240X400__)
        67261,
	#elif defined (__MMI_MAINLCD_320X480__)
		67262,
	#elif defined (__MMI_MAINLCD_480X800__)
		67263,
	#elif defined (__MMI_MAINLCD_176X220__)
		67264,
	#elif defined (__MMI_MAINLCD_320X240__)
		67265,
    #else
		0,
    #endif
        IMG_ID_AM_APP_GAMELOFT_BB_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_GAMELOFT_BLOCKBREAKER,   /* name resource id */
        "http://wapshop.gameloft.com/misc/mtk/directdl.php",
        0
     },
#endif
#ifdef __MMI_MRE_APP_GAMELOFT_AC_SHORTCUT__
    {
   #if defined (__MMI_MAINLCD_240X320__)
        67280,
    #elif defined (__MMI_MAINLCD_240X400__)
        67281,
	#elif defined (__MMI_MAINLCD_320X480__)
		67282,
	#elif defined (__MMI_MAINLCD_480X800__)
		67283,
	#elif defined (__MMI_MAINLCD_176X220__)
		67284,
	#elif defined (__MMI_MAINLCD_320X240__)
		67285,
    #else
		0,
    #endif
        IMG_ID_AM_APP_GAMELOFT_AC_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_GAMELOFT_ASSASSINCREED,   /* name resource id */
        "http://wapshop.gameloft.com/misc/mtk/directdl.php",
        0
     },
#endif
#ifdef __MMI_MRE_APP_GAMELOFT_MC2_SHORTCUT__
    {
   #if defined (__MMI_MAINLCD_240X320__)
        67320,
    #elif defined (__MMI_MAINLCD_240X400__)
        67321,
	#elif defined (__MMI_MAINLCD_320X480__)
		67322,
	#elif defined (__MMI_MAINLCD_480X800__)
		67323,
	#elif defined (__MMI_MAINLCD_176X220__)
		67324,
	#elif defined (__MMI_MAINLCD_320X240__)
		67325,
    #else
		0,
    #endif
        IMG_ID_AM_APP_GAMELOFT_MC2_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_GAMELOFT_MC2,   /* name resource id */
        "http://wapshop.gameloft.com/misc/mtk/directdl.php",
        0
     },
#endif
#ifdef __MMI_MRE_APP_GAMELOFT_AS6_SHORTCUT__
    {
   #if defined (__MMI_MAINLCD_240X320__)
        67250,
    #elif defined (__MMI_MAINLCD_240X400__)
        67251,
	#elif defined (__MMI_MAINLCD_320X480__)
		67252,
	#elif defined (__MMI_MAINLCD_480X800__)
		67253,
	#elif defined (__MMI_MAINLCD_176X220__)
		67254,
	#elif defined (__MMI_MAINLCD_320X240__)
		67255,
    #else
		0,
    #endif
        IMG_ID_AM_APP_GAMELOFT_AS6_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_GAMELOFT_ASPHALT6,   /* name resource id */
        "http://wapshop.gameloft.com/misc/mtk/directdl.php",
        0
     },
#endif
#ifdef __MMI_MRE_APP_GMOBI_APPSTORE_SHORTCUT__
    {
    //#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
        67090,
    //#endif
        IMG_ID_AM_APP_GMOBI_APPSTORE_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_GMOBI_APPSTORE,   /* name resource id */
        "http://appupgrade.services-mtk.com/gmas/AppsUpdate",
        0
     },
#endif
#ifdef __MMI_MRE_APP_MBOUNCE_APPSTORE_SHORTCUT__
    {
    #ifdef __COSMOS_MMI_PACKAGE__
    #if defined(__MMI_MAINLCD_240X400__)
        67101,
    #else
        67100,
    #endif
    #elif defined(__PLUTO_MMI_PACKAGE__)
    #if defined(__MMI_MAINLCD_240X400__)
        67103,
    #else
        67102,
    #endif
    #else
        0,
    #endif
        IMG_ID_AM_APP_MBOUNCE_APPSTORE_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_MBOUNCE_APPSTORE,   /* name resource id */
        "http://mre.mbounce.com/dlstore.php",
        0
     },
#endif
#ifdef __MMI_MRE_APP_KKFUN_APPSTORE_SHORTCUT__
    {
    #if defined(__MMI_MAINLCD_320X240__)
        67110,
    #elif defined(__MMI_MAINLCD_240X320__)
        67111,
    #elif defined(__MMI_MAINLCD_240X400__)
        67112,
    #elif defined(__MMI_MAINLCD_320X480__)
        67113,
    #elif defined(__MMI_MAINLCD_480X800__)
        67114,
    #else
        0,
    #endif
        IMG_ID_AM_APP_KKFUN_APPSTORE_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_KKFUN_APPSTORE,   /* name resource id */
        "http://x.kkfun.com.cn/funbox40/AppsUpdate",
        0
     },
#endif
#ifdef __MMI_MRE_APP_MOBIM_APPSTORE_SHORTCUT__
    {
    #if defined(__MMI_MAINLCD_240X320__)
        67130,
    #elif defined(__MMI_MAINLCD_240X400__)
        67131,
    #elif defined(__MMI_MAINLCD_320X480__)
        67132,
    #elif defined(__MMI_MAINLCD_480X800__)
        67133,
    #else
        0,
    #endif
        IMG_ID_AM_APP_MOBIM_APPSTORE_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_MOBIM_APPSTORE,   /* name resource id */
        "http://ld.huashangtech.com/mtk/imiworld",
        0
     },
#endif
#ifdef __MMI_MRE_APP_MTONE_APPSTORE_SHORTCUT__
    {
    #if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
        67120,
    #else
        0,
    #endif
        IMG_ID_AM_APP_MTONE_APPSTORE_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_MTONE_APPSTORE,   /* name resource id */
        "http://mservice.m-tunes.com.cn/mStore/mtkappupdate.ashx",
        0
     },
#endif
#ifdef __MMI_MRE_APP_MODING_APPSTORE_SHORTCUT__
    {
        67230,
        IMG_ID_AM_APP_MODING_APPSTORE_SHORTCUT,       /* icon resource id */
        STR_ID_AM_APP_NAME_MODING_APPSTORE,   /* name resource id */
        "http://mre.rymoding.com:9090/mrebuildin/update",
        0
     },
#endif
#if defined(__MMI_MRE_APP_VOGINS_MOBILE_MARKET__) && (__MMI_MRE_APP_VOGINS_MOBILE_MARKET__&__MRE_APP_SHORTCUT__)
    {
    #if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__)
        67340,
    #else
        0,
    #endif
        IMG_ID_AM_APP_VOGINS_MOBILE_MARKET,
        STR_ID_AM_APP_VOGINS_MOBILE_MARKET,
        "http://appupdate.vspace.net.cn:8888/index.php",
        0
     },
#endif
#if defined(__MMI_MRE_APP_IBINGO_UISTORE__) && (__MMI_MRE_APP_IBINGO_UISTORE__&__MRE_APP_SHORTCUT__)
    {
    #if defined(__MMI_MAINLCD_240X320__)
        67350,
    #elif defined(__MMI_MAINLCD_240X400__)
        67351,
    #elif defined(__MMI_MAINLCD_320X480__)
        67352,
    #elif defined(__MMI_MAINLCD_480X800__)
        67353,
    #else
        0,
    #endif
        IMG_ID_AM_APP_IBINGO_UISTORE,
        STR_ID_AM_APP_IBINGO_UISTORE,
        "http://ibingo.net.cn/fee/mtkqy",
        0
     },
#endif

#if defined(__MMI_MRE_APP_MOBIM_FCWR__) && (__MMI_MRE_APP_MOBIM_FCWR__&__MRE_APP_SHORTCUT__)
    {
    #if defined(__MMI_MAINLCD_240X320__)
        67360,
    #elif defined(__MMI_MAINLCD_240X400__)
        67361,
    #elif defined(__MMI_MAINLCD_320X480__)
        67362,
    #elif defined(__MMI_MAINLCD_480X800__)
        67363,
    #else
        0,
    #endif
        IMG_ID_AM_APP_MOBIM_FCWR,
        STR_ID_AM_APP_MOBIM_FCWR,
        "http://ld.huashangtech.com/mtk/imiworld",
        0
     },
#endif

#if defined(__MMI_MRE_APP_MITAKE_MSTOCK__) && (__MMI_MRE_APP_MITAKE_MSTOCK__ == __MRE_APP_SHORTCUT__)
    {
    #if defined(__MMI_MAINLCD_240X320__)
        67370,
    #elif defined(__MMI_MAINLCD_240X400__)
        67371,
    #elif defined(__MMI_MAINLCD_320X480__)
        67372,
    #elif defined(__MMI_MAINLCD_480X800__)
        67373,
    #else
        0,
    #endif
        IMG_ID_AM_APP_MITAKE_MSTOCK,
        STR_ID_AM_APP_MITAKE_MSTOCK,
        "http://mre.mitake.com.tw/mre/update.asp?channel=pl",
        0
     },
#endif
    {-1,
     -1,
     -1,
     0,
     0
     }

};

