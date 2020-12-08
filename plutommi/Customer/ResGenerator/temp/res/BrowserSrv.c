#include "MMI_features.h"
#include "CustResDef.h"
#include "custom_wap_config.h"

<?xml version="1.0" encoding="UTF-8"?>

/* Needed header files of the compile option in XML files, if you need others need to add here */
#ifdef __MMI_BROWSER_2__


/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_BROWSER">

    <INCLUDE file = "mmi_rp_all_defs.h"/>

/* cache settings begin */
    <CACHEDATA type="byte" id="NVRAM_BRW_SETTINGS_HOMEPAGE" restore_flag="TRUE">
        <DEFAULT_VALUE> [WAP_CUSTOM_CFG_DEFAULT_HOMEPAGE] </DEFAULT_VALUE>
        <DESCRIPTION> Homepage Setting </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BRW_SETTINGS_RENDER_MODE" restore_flag="TRUE">
    #ifdef OBIGO_Q05A
        <DEFAULT_VALUE> [WAP_CUSTOM_CFG_DEFAULT_RENDER_MODE] </DEFAULT_VALUE>
    #else
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
    #endif
        <DESCRIPTION> Rendering Mode </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BRW_SETTINGS_NAVIGATE_MODE" restore_flag="TRUE">
    #ifdef OBIGO_Q05A
        <DEFAULT_VALUE> [WAP_CUSTOM_CFG_DEFAULT_NAVIGATE_MODE] </DEFAULT_VALUE>
    #else
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
    #endif
        <DESCRIPTION> Navigation Mode </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BRW_SETTINGS_FONT_SIZE" restore_flag="TRUE">
    #ifdef OBIGO_Q05A
        <DEFAULT_VALUE> [WAP_CUSTOM_CFG_DEFAULT_FONT_SIZE] </DEFAULT_VALUE>
    #else
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
    #endif
        <DESCRIPTION> Font Size </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BRW_SETTINGS_THUMBNAIL" restore_flag="TRUE">
    #ifdef OBIGO_Q05A
        <DEFAULT_VALUE> [WAP_CUSTOM_CFG_DEFAULT_THUMBNAIL] </DEFAULT_VALUE>
    #else
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
    #endif
        <DESCRIPTION> Thumbnail status </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BRW_SETTINGS_SCREEN_SIZE" restore_flag="TRUE">
    #ifdef OBIGO_Q05A
        <DEFAULT_VALUE> [WAP_CUSTOM_CFG_DEFAULT_SCREEN_SIZE] </DEFAULT_VALUE>
    #else
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
    #endif
        <DESCRIPTION> Screen size status </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BRW_SETTINGS_ENCODE_METHOD_INDEX" restore_flag="TRUE">
    #ifdef OBIGO_Q05A
        <DEFAULT_VALUE> [WAP_CUSTOM_CFG_DEFAULT_ENCODE_METHOD_INDEX] </DEFAULT_VALUE>
    #else
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
    #endif
        <DESCRIPTION> Encoding Method </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BRW_SETTINGS_SHOW_VIDEO" restore_flag="TRUE">
    #ifdef OBIGO_Q05A
        <DEFAULT_VALUE> [WAP_CUSTOM_CFG_DEFAULT_SHOW_VIDEO] </DEFAULT_VALUE>
    #else
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
    #endif
        <DESCRIPTION> Video Mode status </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BRW_SETTINGS_PLAY_SOUND" restore_flag="TRUE">
    #ifdef OBIGO_Q05A
        <DEFAULT_VALUE> [WAP_CUSTOM_CFG_DEFAULT_PLAY_SOUND] </DEFAULT_VALUE>
    #else
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
    #endif
        <DESCRIPTION> Play Sound status </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BRW_SETTINGS_LOAD_UNKOWN_MEDIA" restore_flag="TRUE">
    #ifdef OBIGO_Q05A
        <DEFAULT_VALUE> [WAP_CUSTOM_CFG_DEFAULT_LOAD_UNKOWN_MEDIA] </DEFAULT_VALUE>
    #else
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
    #endif
        <DESCRIPTION> Unknown media status </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BRW_SETTINGS_CSS" restore_flag="TRUE">
    #ifdef OBIGO_Q05A
        <DEFAULT_VALUE> [WAP_CUSTOM_CFG_DEFAULT_CSS] </DEFAULT_VALUE>
    #else
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
    #endif
        <DESCRIPTION> CSS status </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BRW_SETTINGS_SCRIPTS" restore_flag="TRUE">
    #ifdef OBIGO_Q05A
        <DEFAULT_VALUE> [WAP_CUSTOM_CFG_DEFAULT_SCRIPTS] </DEFAULT_VALUE>
    #else
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
    #endif
        <DESCRIPTION> Scripts status </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BRW_SETTINGS_CACHE" restore_flag="TRUE">
        <DEFAULT_VALUE> [WAP_CUSTOM_CFG_DEFAULT_CACHE] </DEFAULT_VALUE>
        <DESCRIPTION> Cache status </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BRW_SETTINGS_COOKIE" restore_flag="TRUE">
        <DEFAULT_VALUE> [WAP_CUSTOM_CFG_DEFAULT_COOKIE] </DEFAULT_VALUE>
        <DESCRIPTION> Cookie status </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BRW_SETTINGS_SHORTCUTS" restore_flag="TRUE">
    #ifdef OBIGO_Q05A
        <DEFAULT_VALUE> [WAP_CUSTOM_CFG_DEFAULT_SHORTCUTS] </DEFAULT_VALUE>
    #else
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
    #endif
        <DESCRIPTION> Shortcuts status </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BRW_SETTINGS_SECURITY_WARNINGS" restore_flag="TRUE">
    #ifdef OBIGO_Q05A
        <DEFAULT_VALUE> [WAP_CUSTOM_CFG_DEFAULT_SECURITY_WARNINGS] </DEFAULT_VALUE>
    #else
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
    #endif
        <DESCRIPTION> Security warnings status </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BRW_SETTINGS_SEND_DEVICE_ID" restore_flag="TRUE">
    #ifdef OBIGO_Q05A
        <DEFAULT_VALUE> [WAP_CUSTOM_CFG_DEFAULT_SEND_DEVICE_ID] </DEFAULT_VALUE>
    #else
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
    #endif
        <DESCRIPTION> Send Device ID status </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BRW_SETTINGS_POST_SESSION_INFO" restore_flag="TRUE">
    #ifdef OBIGO_Q05A
        <DEFAULT_VALUE> [WAP_CUSTOM_CFG_DEFAULT_POST_SESSION_INFO] </DEFAULT_VALUE>
    #else
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
    #endif
        <DESCRIPTION> Post Session Info Status </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BRW_RECENT_PAGES_SORTING_METHOD" restore_flag="TRUE">
    #ifdef OBIGO_Q05A
        <DEFAULT_VALUE> [WAP_CUSTOM_CFG_DEFAULT_SORTING_METHOD] </DEFAULT_VALUE>
    #else
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
    #endif
        <DESCRIPTION> Recent page sorting method </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BRW_SHOW_IMAGE_MODE" restore_flag="TRUE">
        <DEFAULT_VALUE> [WAP_CUSTOM_CFG_DEFAULT_SHOW_IMAGE] </DEFAULT_VALUE>
        <DESCRIPTION> Image Mode status </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BRW_SETTINGS_SEARCH_ENGINE" restore_flag="TRUE">
        <DEFAULT_VALUE> [WAP_CUSTOM_CFG_DEFAULT_SEARCH_ENGINE] </DEFAULT_VALUE>
        <DESCRIPTION> Browser History Setting </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BRW_SETTINGS_PRIVATE_MODE" restore_flag="TRUE">
        <DEFAULT_VALUE> [WAP_CUSTOM_CFG_DEFAULT_PRIVATE_MODE] </DEFAULT_VALUE>
        <DESCRIPTION> Private Mode Setting </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BRW_SETTINGS_HISTORY" restore_flag="TRUE">
        <DEFAULT_VALUE> [WAP_CUSTOM_CFG_DEFAULT_HISTORY] </DEFAULT_VALUE>
        <DESCRIPTION> Browser History Setting </DESCRIPTION>
    </CACHEDATA>
#ifdef __BAIDU_TRANSCODING_SUPPORT__	
	<CACHEDATA type="byte" id="NVRAM_BRW_SETTINGS_BAIDU_PROXY" restore_flag="TRUE">
        <DEFAULT_VALUE> [WAP_CUSTOM_CFG_DEFAULT_USE_BAIDU_PROXY] </DEFAULT_VALUE>
        <DESCRIPTION> Baidu Proxy usage setting </DESCRIPTION>
    </CACHEDATA>
#endif // #ifdef __BAIDU_TRANSCODING_SUPPORT__

    <CACHEDATA type="short" id="NVRAM_BRW_PAGE_TIME_OUT_VALUE" restore_flag="TRUE">
        <DEFAULT_VALUE> [WAP_CUSTOM_CFG_DEFAULT_BROWSE_TIMEOUT] </DEFAULT_VALUE>
        <DESCRIPTION> User Preference </DESCRIPTION>
    </CACHEDATA>

#ifdef __COSMOS_MMI_PACKAGE__

    <CACHEDATA type="byte" id="NVRAM_BRW_SETTINGS_WIFI_ONLY" restore_flag="TRUE">
        <DEFAULT_VALUE> [WAP_CUSTOM_CFG_DEFAULT_WIFI_ONLY] </DEFAULT_VALUE>
        <DESCRIPTION> Wifi Only </DESCRIPTION>
    </CACHEDATA>

#endif
    <RECEIVER id="EVT_ID_SRV_DTCNT_SIM_PREFERENCE_UPDATE_IND" proc="srv_brw_sim_preference_update_handler"/>

    <TIMER id= "BRW_SPLASH_SCREEN_TIMER"/>
    <TIMER id= "BRW_SERVER_CONNECTION_TIMER"/>
#ifdef OBIGO_Q05A
    <TIMER id= "BRW_LOADING_TIME_CHECK_TIMER"/>
#endif
#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
    <TIMER id= "BRW_UPLOAD_COMPLETED_TIMER"/>
#endif
</APP>

#endif  /*  __MMI_BROWSER_2__  */



