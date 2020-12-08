#include "MMI_features.h"
#include "CustResDef.h"

#ifdef __COSMOS_MMI_PACKAGE__

<?xml version="1.0" encoding="UTF-8"?>

/* Needed header files of the compile option in XML files, if you need others need to add here */
#ifdef __MMI_BROWSER_2__


/* APP tag, include your app name defined in MMIDataType.h */


<APP id="VAPP_BROWSER_LOW_MEM" name ="STR_ID_VAPP_BRW_LOW_MEM" type="venus">

#ifdef __LOW_COST_SUPPORT_COMMON__                     
<MEMORY heap="250 * 1024" cui="max(APP_MMI_WAP_PROF, max(VCUI_FMGR, max(VCUI_BT_SEND_PREPARE)))" //no unificomposer
                     extra_base = "$(BROWSER_POOL_SIZE)" inc="BrowserSrvConfig.h" />                     
#else
<MEMORY heap="275 * 1024" cui="max(APP_MMI_WAP_PROF, max(VCUI_FMGR, max(VCUI_BT_SEND_PREPARE)))"
                     extra_base = "$(BROWSER_POOL_SIZE)" inc="BrowserSrvConfig.h" />
#endif

<APPCONCURRENT concurrent_w_order ="VAPP_BROWSER_LOW_MEM, VAPP_DLAGENT"/>
</APP>


<APP id="VAPP_BROWSER" package_name = "native.mtk.vapp_browser" name ="STR_ID_VAPP_BRW" 
	img ="IMG_ID_VAPP_BRW_BROWSER_ICON" launch ="vapp_brw_app_launch_ext" package_proc ="vapp_brw_app_launch_proc" type="venus">
#ifdef __LOW_COST_SUPPORT_COMMON__                     
<MEMORY heap="250 * 1024" 
#ifdef __MMI_BRW_SLIM__
cui="max(APP_MMI_WAP_PROF,VCUI_FMGR)" //VCUI_SMSONLYCOMPOSER
#else
#ifdef __MMI_UNIFIED_COMPOSER__
cui="max(APP_MMI_WAP_PROF, max(VCUI_FMGR, max(VCUI_BT_SEND_PREPARE, VCUI_SMSONLYCOMPOSER)))" //VCUI_SMSONLYCOMPOSER
#else
	#ifdef __MMI_SMS_COMPOSER__
	cui="max(APP_MMI_WAP_PROF, max(VCUI_FMGR, max(VCUI_BT_SEND_PREPARE, VCUI_SMS_COMPOSER)))" //VCUI_SMS_COMPOSER
	#else
	cui="max(APP_MMI_WAP_PROF, max(VCUI_FMGR, VCUI_BT_SEND_PREPARE)" //no VCUI_SMS_COMPOSER
	#endif
#endif
#endif                     
                     extra_base = "$(BROWSER_POOL_SIZE)" inc="BrowserSrvConfig.h" />                     
#else
<MEMORY heap="275 * 1024" cui="max(APP_MMI_WAP_PROF, max(VCUI_FMGR, max(VCUI_BT_SEND_PREPARE, VCUI_MSGCOMPOSER)))"
                     extra_base = "$(BROWSER_POOL_SIZE)" inc="BrowserSrvConfig.h" />
#endif

<APPCONCURRENT concurrent_w_order ="VAPP_BROWSER, VAPP_DLAGENT"/>

/*<APP id="VAPP_BROWSER" name ="STR_ID_VAPP_BRW_WEB_BROWSER">*/

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can file the ID */
    <!--Include Area--> 
    <INCLUDE file = "GlobalResDef.h"/>
    <INCLUDE file = "mmi_rp_srv_editor_def.h"/>
    <INCLUDE file = "ServiceDefs.h"/>
    <INCLUDE file = "FileMgrResDef.h"/>
    <INCLUDE file = "mmi_rp_all_defs.h"/>
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */


    /* String ID's Start */
    #ifdef __MMI_VBOOKMARK__
    <STRING id="STR_ID_VAPP_BRW_BOOKMARKS"/>
    #endif
    <STRING id="STR_ID_VAPP_BRW_RECENT_PAGES"/>
    #ifdef __MMI_WAP_OFFLINE_PAGES_SUPPORT__
    <STRING id="STR_ID_VAPP_BRW_STORED_PAGES"/>
    #endif /* __MMI_WAP_OFFLINE_PAGES_SUPPORT__ */
    #ifdef __MMI_VBOOKMARK__
    <STRING id="STR_ID_VAPP_BRW_ADD_TO_BOOKMARK"/>
    #endif
    #ifdef WAP_SEC_SUPPORT
    <STRING id="STR_ID_VAPP_BRW_TRUSTED_CERTIFICATES"/>
    #endif
    <STRING id="STR_ID_VAPP_BRW_PREFERENCES"/>
    <STRING id="STR_ID_VAPP_BRW_TIMEOUT"/>
    <STRING id="STR_ID_VAPP_BRW_NAME"/>
    <STRING id="STR_ID_VAPP_BRW_FORWARD"/>
    <STRING id="STR_ID_VAPP_BRW_CLEAR_AUTH_INFO"/>
    <STRING id="STR_ID_VAPP_BRW_CREATE_FOLDER"/>
    <STRING id="STR_ID_VAPP_BRW_INVALID_PARAM"/>
    <STRING id="STR_ID_VAPP_BRW_ERROR_COMMUNICATION"/>
    <STRING id="STR_ID_VAPP_BRW_HOST_NOT_FOUND"/>
    <STRING id="STR_ID_VAPP_BRW_REQUEST_TIMEOUT"/>
    <STRING id="STR_ID_VAPP_BRW_CONNECTION_FAILED"/>
    <STRING id="STR_ID_VAPP_BRW_SECURE_CONNECTION_FAILED"/>
    #ifdef OBIGO_Q05A
    <STRING id="STR_ID_VAPP_BRW_ERROR_AUTHENTICATION"/>
    <STRING id="STR_ID_VAPP_BRW_SECURE_CONNECTION_CANCELLED"/>
    #endif /* OBIGO_Q05A */
    <STRING id="STR_ID_VAPP_BRW_ERROR_GPRS_UNKNOWN_APN"/>
    <STRING id="STR_ID_VAPP_BRW_ERROR_GPRS_AUTHENTICATION_FAILURE"/>
    <STRING id="STR_ID_VAPP_BRW_ERROR_GPRS_UNSUPPORTED"/>
    <STRING id="STR_ID_VAPP_BRW_ERROR_GPRS_NOT_SUBSCRIBED"/>
    <STRING id="STR_ID_VAPP_BRW_ERROR_CSD_AUTHENTICATION_FAILURE"/>
    <STRING id="STR_ID_VAPP_BRW_PAGE_NOT_FOUND"/>
    <STRING id="STR_ID_VAPP_BRW_PAGE_ALREADY_EXISTS"/>
    <STRING id="STR_ID_VAPP_BRW_REQUEST_FAILED"/>
    <STRING id="STR_ID_VAPP_BRW_PAGE_SAVED_PARTIALLY"/>
    <STRING id="STR_ID_VAPP_BRW_PAGE_LIMIT_EXCEEDED"/>
    <STRING id="STR_ID_VAPP_BRW_UNSUPPORTED_SCHEME"/>
    <STRING id="STR_ID_VAPP_BRW_UNSUPPORTED_ENCODING"/>
    <STRING id="STR_ID_VAPP_BRW_SYNTAX_ERROR"/>
    <STRING id="STR_ID_VAPP_BRW_UNKNOWN_DOC_TYPE"/>
    <STRING id="STR_ID_VAPP_BRW_UNSUPPORTED_WBXML"/>
    <STRING id="STR_ID_VAPP_BRW_DOC_VALIDATION_ERROR"/>
    <STRING id="STR_ID_VAPP_BRW_PARSER_NOT_INITIALIZED"/>
    <STRING id="STR_ID_VAPP_BRW_INTERNAL_ERROR"/>
    <STRING id="STR_ID_VAPP_BRW_RESEND_POST_WARNING"/>
    <STRING id="STR_ID_VAPP_BRW_CONTENT_TOO_LARGE"/>
    <STRING id="STR_ID_VAPP_BRW_INVAL_CHANNEL_ID"/>
    <STRING id="STR_ID_VAPP_BRW_INVAL_REQUEST_ID"/>
    <STRING id="STR_ID_VAPP_BRW_INVAL_SEQUENCE_NUM"/>
    #ifdef __MMI_VBOOKMARK__
    <STRING id="STR_ID_VAPP_BRW_INVALID_TITLE"/>
    <STRING id="STR_ID_VAPP_BRW_INVALID_BOOKMARK_FILE"/>
    #endif
    <STRING id="STR_ID_VAPP_BRW_UNSUPPORTED_ACTION"/>
    <STRING id="STR_ID_VAPP_BRW_ERR_WML_ACCESS_VIOLATION"/>
    <STRING id="STR_ID_VAPP_BRW_ERR_WML_SCRIPT_ACCESS_VIOLATION"/>
    #ifdef OBIGO_Q05A
    <STRING id="STR_ID_VAPP_BRW_ERROR_LOW_MEMORY"/>
    #endif /* OBIGO_Q05A */
    <STRING id="STR_ID_VAPP_BRW_ACCESS_DENIED"/>
    <STRING id="STR_ID_VAPP_BRW_NOT_FOUND"/>
    <STRING id="STR_ID_VAPP_BRW_REQUEST_ABORTED"/>
    <STRING id="STR_ID_VAPP_BRW_WAP_NOT_READY"/>

    #ifdef __MMI_VBOOKMARK__
    <STRING id="STR_ID_VAPP_BRW_EDIT_BOOKMARK"/>
    <STRING id="STR_ID_VAPP_BRW_ADD_BOOKMARK"/>
    #endif
    <STRING id="STR_ID_VAPP_BRW_CLEAR_CACHE"/>
    <STRING id="STR_ID_VAPP_BRW_CLEAR_COOKIE"/>
    <STRING id="STR_ID_VAPP_BRW_LONG_IDLE_TIMEOUT"/>
    #ifdef OBIGO_Q05A
    <STRING id="STR_ID_VAPP_BRW_VIDEO_OBJS_EXCEED_MAX_LIMIT"/>
    #endif /* OBIGO_Q05A */
    #ifdef WAP_SEC_SUPPORT
    <STRING id="STR_ID_VAPP_BRW_TYPE"/>
    <STRING id="STR_ID_VAPP_BRW_VERSION"/>
    <STRING id="STR_ID_VAPP_BRW_SERIAL_NUM"/>
    #endif
    <STRING id="STR_ID_VAPP_BRW_QUESTION_MARK"/>
    #ifdef __MMI_URI_AGENT__
    <STRING id="STR_ID_VAPP_BRW_UHA_CONNECT_TO_BROWSER"/>
    #endif
    #ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
        /* File Upload Feature */
    <STRING id="STR_ID_VAPP_BRW_UPLOADING"/>
    <STRING id="STR_ID_VAPP_BRW_UPLOAD_COMPLETED"/>
    <STRING id="STR_ID_VAPP_BRW_FILE_SIZE_TOO_LARGE"/>
        /* File Upload Feature END */
    #endif /* __MMI_BRW_FILE_UPLOAD_SUPPORT__ */
    #ifdef OBIGO_Q03C_BROWSER
    <STRING id="STR_ID_VAPP_BRW_UNSUPPORTED_SCRIPTS"/>
    <STRING id="STR_ID_VAPP_BRW_REQUIRES_FRAME_SUPPORT"/>
    #endif /* OBIGO_Q03C_BROWSER */
#ifdef OBIGO_Q03C_BROWSER
	<STRING id="STR_ID_VAPP_BRW_NO_DISPLAY_CONTENT"/>
#endif

	<STRING id="STR_ID_VAPP_BRW_EMPTY_TRUSTED_CERT_LIST"/>
	
 /** For Cosmos MMI **/
	<STRING id="STR_ID_VAPP_BRW"/>
	<STRING id="STR_ID_VAPP_BRW_INPUT_ADDRESS_OR_KEYWORDS"/>
	<STRING id="STR_ID_VAPP_BRW_FAVORITES"/>
	<STRING id="STR_ID_VAPP_BRW_WEB_BROWSER"/>
	<STRING id="STR_ID_VAPP_BRW_LOCK_SHORTCUT"/>
	<STRING id="STR_ID_VAPP_BRW_EDIT_ADDRESS"/>
	<STRING id="STR_ID_VAPP_BRW_DELETE_SHORTCUT"/>
	<STRING id="STR_ID_VAPP_BRW_PICTURE_OPTION"/>
	<STRING id="STR_ID_VAPP_BRW_OPEN_IN_NEW_PAGE"/>
	<STRING id="STR_ID_VAPP_BRW_SHARE_LINK_VIA_BLUETOOTH"/>
	<STRING id="STR_ID_VAPP_BRW_SHARE_LINK_VIA_EMAIL"/>
	<STRING id="STR_ID_VAPP_BRW_BROWSING_HISTORY"/>
	<STRING id="STR_ID_VAPP_BRW_BOOKMARK_DELETE_CONFIRM"/>
	<STRING id="STR_ID_VAPP_BRW_BOOKMARK_DETAILS"/>
	<STRING id="STR_ID_VAPP_BRW_ALL"/>
	<STRING id="STR_ID_VAPP_BRW_SELECTED"/>
	<STRING id="STR_ID_VAPP_BRW_DETAILS"/>
	<STRING id="STR_ID_VAPP_BRW_YESTERDAY"/>
	<STRING id="STR_ID_VAPP_BRW_DAY_BEFORE_YESTERDAY"/>
	<STRING id="STR_ID_VAPP_BRW_TODAY"/>
	<STRING id="STR_ID_VAPP_BRW_LAST_TWO_DAYS"/>
	<STRING id="STR_ID_VAPP_BRW_SEARCH_ENGINE"/>
	<STRING id="STR_ID_VAPP_BRW_PRIVATE_MODE"/>
	<STRING id="STR_ID_VAPP_BRW_VALIDITY"/>
	<STRING id="STR_ID_VAPP_BRW_SAVE_PICTURE"/>
	<STRING id="STR_ID_VAPP_BRW_SAVE_PAGE"/>
	<STRING id="STR_ID_VAPP_BRW_GO"/>
	<STRING id="STR_ID_VAPP_BRW_SELECT_FOLDER"/>
	<STRING id="STR_ID_VAPP_BRW_LOAD_IMAGES"/>
	<STRING id="STR_ID_VAPP_BRW_PICTURE_SELECT_MODE"/>
	<STRING id="STR_ID_VAPP_BRW_BAIDU"/>
	<STRING id="STR_ID_VAPP_BRW_GOOGLE"/>
	<STRING id="STR_ID_VAPP_BRW_YAHOO"/>
	<STRING id="STR_ID_VAPP_BRW_BING"/>
	<STRING id="STR_ID_VAPP_BRW_30_SEC"/>
	<STRING id="STR_ID_VAPP_BRW_60_SEC"/>
	<STRING id="STR_ID_VAPP_BRW_2_MINS"/>
	<STRING id="STR_ID_VAPP_BRW_3_MINS"/>
	<STRING id="STR_ID_VAPP_BRW_4_MINS"/>
	<STRING id="STR_ID_VAPP_BRW_5_MINS"/>
	<STRING id="STR_ID_VAPP_BRW_ENABLE_HISTORY"/>
	<STRING id="STR_ID_VAPP_BRW_ENABLE_CACHE"/>
	<STRING id="STR_ID_VAPP_BRW_ENABLE_COOKIES"/>
	<STRING id="STR_ID_VAPP_BRW_VIEW_TRUSTED_CERTIFICATES"/>
	<STRING id="STR_ID_VAPP_BRW_SETTINGS"/>
	<STRING id="STR_ID_VAPP_BRW_PRIVACY_OPTIONS"/>
	<STRING id="STR_ID_VAPP_BRW_CLEAR_HISTORY"/>
	<STRING id="STR_ID_VAPP_BRW_ACCOUNT_OPTIONS"/>
	<STRING id="STR_ID_VAPP_BRW_DATA_ACCOUNT"/>
	<STRING id="STR_ID_VAPP_BRW_SECURITY"/>
	<STRING id="STR_ID_VAPP_BRW_RESTORE_DEFAULT_SETTINGS"/>
	<STRING id="STR_ID_VAPP_BRW_RESTORE_SETTINGS"/>
	<STRING id="STR_ID_VAPP_BRW_15_SEC"/>
	<STRING id="STR_ID_VAPP_BRW_WIFI_ONLY"/>
	<STRING id="STR_ID_VAPP_BRW_ALWAYS_USE_WIFI"/>
	<STRING id="STR_ID_VAPP_BRW_CLEAR_COMPLETE_HISTORY_CONFIRM"/>
	<STRING id="STR_ID_VAPP_BRW_CLEAR_COMPLETE_CACHE_CONFIRM"/>
	<STRING id="STR_ID_VAPP_BRW_CLEAR_ALL_COOKIES_CONFIRM"/>
	<STRING id="STR_ID_VAPP_BRW_LOCATION"/>
	<STRING id="STR_ID_VAPP_BRW_ACTIVATED"/>
	<STRING id="STR_ID_VAPP_BRW_EXPIRES"/>
	<STRING id="STR_ID_VAPP_BRW_SIGNATURE"/>
	<STRING id="STR_ID_VAPP_BRW_NAME_HEADING"/>
	<STRING id="STR_ID_VAPP_BRW_CONFIRM_RESTORE_SETTINGS"/>
	<STRING id="STR_ID_VAPP_BRW_SUBJECT"/>
	<STRING id="STR_ID_VAPP_BRW_INVALID_INPUT"/>	
//kamal
	<STRING id="STR_ID_VAPP_BRW_PLEASE_WAIT"/>
	<STRING id="STR_ID_VAPP_BRW_CLEAR_ALL"/>
	<STRING id="STR_ID_VAPP_BRW_CLEAR_TODAYS_CONFIRMATION"/>
	<STRING id="STR_ID_VAPP_BRW_CLEAR_TWO_DAYS_CONFIRMATION"/>
	<STRING id="STR_ID_VAPP_BRW_CLEAR_ALL_CONFIRMATION"/>
	<STRING id="STR_ID_VAPP_BRW_URL"/>
	<STRING id="STR_ID_VAPP_BRW_ADD"/>
	<STRING id="STR_ID_VAPP_BRW_EXIT_BROWSER"/>
	<STRING id="STR_ID_VAPP_BRW_SHARE_VIA_SMS"/>
	<STRING id="STR_ID_VAPP_BRW_SHARE_VIA_MMS"/>
	<STRING id="STR_ID_VAPP_BRW_NO_SAVED_PAGES"/>
	<STRING id="STR_ID_VAPP_BRW_NO_BROWSING_HISTORY"/>
	<STRING id="STR_ID_VAPP_BRW_NO_BOOKMARKS"/>
	<STRING id="STR_ID_VAPP_BRW_RENAME"/>
	<STRING id="STR_ID_VAPP_BRW_FOLDER_NAME"/>
	<STRING id="STR_ID_VAPP_BRW_UNLOCK_SHORTCUT"/>
	<STRING id="STR_ID_VAPP_BRW_TAP_TO_INPUT"/>
	<STRING id="STR_ID_VAPP_BRW_BOOKMARK"/>
	<STRING id="STR_ID_VAPP_BRW_FOLDER"/>
	<STRING id="STR_ID_VAPP_BRW_SHARE_LINK"/>
   	<STRING id="STR_ID_VAPP_BRW_EDIT_SHORTCUT"/>
   	<STRING id="STR_ID_VAPP_BRW_DELETE_SELECTED_BOOKMARK"/>
   	<STRING id="STR_ID_VAPP_BRW_DELETE_SELECTED_BOOKMARKS"/>
   	<STRING id="STR_ID_VAPP_BRW_DELETE_SELECTED_STORED_PAGE"/>
   	<STRING id="STR_ID_VAPP_BRW_DELETE_SELECTED_STORED_PAGES"/>
   	<STRING id="STR_ID_VAPP_BRW_CLEAR_AUTH_INFO_CONFIRM"/>
   	<STRING id="STR_ID_VAPP_BRW_DELETE_HISTORY_CONFIRM"/>
   	<STRING id="STR_ID_VAPP_BRW_PREV"/>
   	<STRING id="STR_ID_VAPP_BRW_NEXT"/>
   	<STRING id="STR_ID_VAPP_BRW_DELETE_SHORTCUT_CONFIRM"/>
   	<STRING id="STR_ID_VAPP_BRW_INSUFFICIENT_MEMORY_CONFIRM"/>
   	<STRING id="STR_ID_VAPP_BRW_CERTIFICATE_DETAILS"/>
   	<STRING id="STR_ID_VAPP_BRW_DELETE_CERTIFICATE_CONFIRM"/>
   	<STRING id="STR_ID_VAPP_BRW_PAGE_SAVED"/>
   	<STRING id="STR_ID_VAPP_BRW_BOOKMARK_SAVED"/>
   	<STRING id="STR_ID_VAPP_BRW_NO_MATCHED_ITEM"/>
   	<STRING id="STR_ID_VAPP_BRW_PLEASE_INPUT_BOOKMARK_NAME"/>
   	<STRING id="STR_ID_VAPP_BRW_PLEASE_INPUT_FOLDER_NAME"/>
   	<STRING id="STR_ID_VAPP_BRW_FLIGHT_MODE_ACTIVE"/>
   	<STRING id="STR_ID_VAPP_BRW_DELETE_BOOKMARKS"/>
   	<STRING id="STR_ID_VAPP_BRW_LEFT_BRACKET"/>
   	<STRING id="STR_ID_VAPP_BRW_RIGHT_BRACKET"/>
   	<STRING id="STR_ID_VAPP_BRW_EXPORT_SUCCESS"/>
   	<STRING id="STR_ID_VAPP_BRW_EXPORT_FAILED"/>
   	<STRING id="STR_ID_VAPP_BRW_DOT"/>
   	<STRING id="STR_ID_VAPP_BRW_RESTORE"/>
#ifdef __BAIDU_TRANSCODING_SUPPORT__
   	<STRING id="STR_ID_VAPP_BRW_USE_BAIDU_PROXY"/>
   	<STRING id="STR_ID_VAPP_BRW_USE_BAIDU_PROXY_CONFIRM"/>
   	<STRING id="STR_ID_VAPP_BRW_SWITCH_OFF_BAIDU_PROXY_CONFIRM"/>
#endif /* #ifdef __BAIDU_TRANSCODING_SUPPORT__ */
   	<STRING id="STR_ID_VAPP_BRW_BEARER_SWITCH_RETRY"/>

#ifdef __MMI_URI_AGENT__
   	<STRING id="STR_ID_VAPP_BRW_URI_BUSY"/>
#endif
   	<STRING id="STR_ID_VAPP_BRW_NETWORK_NOT_AVAILABLE"/>
   	<STRING id="STR_ID_VAPP_BRW_SIM_IN_USE"/>
   	<STRING id="STR_ID_VAPP_BRW_NETWORK_NOT_AVAILABLE_NO_WIFI"/>
    /* String ID's End */




    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of CUST_IMG_PATH" */


#if defined(OBIGO_Q05A)
    <IMAGE id="IMG_ID_VAPP_BRW_FMGR_FILE_TYPE_HTM"> CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIWEB.PBM"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_BRW_FMGR_HTM_LARGE_TYPE"> CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_HTM.gif"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_BRW_FMGR_HTML_LARGE_TYPE"> CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_HTML.gif"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_BRW_FMGR_WML_LARGE_TYPE"> CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_WML.gif"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_BRW_FMGR_XHTML_LARGE_TYPE"> CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_XHTML.gif"</IMAGE>
#endif


#if defined (__MMI_VBOOKMARK__ )
    <IMAGE id="IMG_ID_VAPP_BRW_FMGR_ICON_FILE_TYPE_VBOOKMARK"> CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_USER.pbm"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_BRW_FMGR_FILE_TYPE_URL"> CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_URL.pbm"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_BRW_FMGR_FILE_TYPE_VBM"> CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_URL.pbm"</IMAGE>
#endif /* #if defined (__MMI_VBOOKMARK__ )  */

/* Cosmos images start */
<IMAGE id="IMG_ID_VAPP_BRW_TITLEBAR_BOOKMARKS">RES_IMG_ROOT"\\\\Browser\\\\TabIcon\\\\Bookmark.png"</IMAGE>
<IMAGE id="IMG_ID_VAPP_BRW_TITLEBAR_HISTORY">RES_IMG_ROOT"\\\\Browser\\\\TabIcon\\\\History.png"</IMAGE>
<IMAGE id="IMG_ID_VAPP_BRW_TITLEBAR_SAVED_PAGES">RES_IMG_ROOT"\\\\Browser\\\\TabIcon\\\\Savepage.png"</IMAGE>
<IMAGE id="IMG_ID_VAPP_BRW_LOCK">RES_IMG_ROOT"\\\\Browser\\\\Lock.png"</IMAGE>
<IMAGE id="IMG_ID_VAPP_BRW_MINIMIZE">RES_IMG_ROOT"\\\\Browser\\\\Minimize.png"</IMAGE>
<IMAGE id="IMG_ID_VAPP_BRW_REFRESH">RES_IMG_ROOT"\\\\Browser\\\\Refresh.png"</IMAGE>
<THEME>
<IMAGE id="IMG_ID_VAPP_BRW_FULLSCREEN" desc="full screen browser icon" />
</THEME>
//<IMAGE id="IMG_ID_VAPP_BRW_FULLSCREEN">RES_IMG_ROOT"\\\\Browser\\\\FullScreen.png"</IMAGE>
#ifndef __MMI_BRW_SLIM__
<IMAGE id="IMG_ID_VAPP_BRW_ADD_LINK">RES_IMG_ROOT"\\\\Browser\\\\Add.png"</IMAGE>
#else
<IMAGE id="IMG_ID_VAPP_BRW_ADD_LINK">RES_IMG_ROOT"\\\\Redesign\\\\Browser\\\\Add.png"</IMAGE>
#endif
<IMAGE id="IMG_ID_VAPP_BRW_FOLDER_NEXT_LEVEL">RES_IMG_ROOT"\\\\Browser\\\\Nextlevel.png"</IMAGE>
<THEME>
<IMAGE id="IMG_ID_VAPP_BRW_HOMEPAGE_ICON" desc="home page icon"/>
</THEME>
//<IMAGE id="IMG_ID_VAPP_BRW_HOMEPAGE_ICON">RES_IMG_ROOT"\\\\Browser\\\\Home.png"</IMAGE>
#ifndef __MMI_BRW_SLIM__
<IMAGE id="IMG_ID_VAPP_BRW_SHORTCUTS_ICON">RES_IMG_ROOT"\\\\Browser\\\\Default_Shortcut.png"</IMAGE>
#else
<IMAGE id="IMG_ID_VAPP_BRW_SHORTCUTS_ICON">RES_IMG_ROOT"\\\\Redesign\\\\Browser\\\\Default_Shortcut.png"</IMAGE>
#endif
<IMAGE id="IMG_ID_VAPP_BRW_TOOLBAR_FAVORITES">RES_IMG_ROOT"\\\\Browser\\\\ToolbarIcon\\\\Favorite.png"</IMAGE>
<IMAGE id="IMG_ID_VAPP_BRW_TOOLBAR_BACK">RES_IMG_ROOT"\\\\Browser\\\\ToolbarIcon\\\\Back.png"</IMAGE>
<IMAGE id="IMG_ID_VAPP_BRW_TOOLBAR_ADD_BOOKMARK">RES_IMG_ROOT"\\\\Browser\\\\ToolbarIcon\\\\Add_Bookmark.png"</IMAGE>
<IMAGE id="IMG_ID_VAPP_BRW_LIST_ICON_ADD_BKM">RES_IMG_ROOT"\\\\Browser\\\\ListIcon\\\\Add_BM.png"</IMAGE>
<IMAGE id="IMG_ID_VAPP_BRW_LIST_ICON_USER_BKM_FILE">RES_IMG_ROOT"\\\\Browser\\\\ListIcon\\\\Bookmark.png"</IMAGE>
<IMAGE id="IMG_ID_VAPP_BRW_LIST_ICON_DEFAULT_BKM_FILE">RES_IMG_ROOT"\\\\Browser\\\\ListIcon\\\\Factory_BM.png"</IMAGE>
<IMAGE id="IMG_ID_VAPP_BRW_LIST_ICON_BKM_FOLDER">RES_IMG_ROOT"\\\\Browser\\\\ListIcon\\\\Folder.png"</IMAGE>
<IMAGE id="IMG_ID_VAPP_BRW_LIST_ICON_SEARCH_RESULT">RES_IMG_ROOT"\\\\Browser\\\\ListIcon\\\\Search.png"</IMAGE>
<IMAGE id="IMG_ID_VAPP_BRW_LIST_ICON_URL_RESULT">RES_IMG_ROOT"\\\\Browser\\\\ListIcon\\\\URL.png"</IMAGE>
<IMAGE id="IMG_ID_VAPP_BRW_EXPORT_BKM">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Export.png"</IMAGE>
<IMAGE id="IMG_ID_VAPP_BRW_GO">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Send.png"</IMAGE>
<THEME>
<IMAGE id="IMG_ID_VAPP_BRW_BUTTON_BG" desc="browser button bg icon" />
<IMAGE id="IMG_ID_VAPP_BRW_WEBSITE_BG" desc="browser website bg icon" />
</THEME>
//<IMAGE id="IMG_ID_VAPP_BRW_BUTTON_BG">RES_THEME_ROOT"\\\\Theme1\\\\Components\\\\Button\\\\Default01_N.9slice.png"</IMAGE>
//<IMAGE id="IMG_ID_VAPP_BRW_WEBSITE_BG">RES_THEME_ROOT"\\\\Theme1\\\\Browser\\\\Website_BG.9slice.png"</IMAGE>
<THEME>
//<IMAGE id="IMG_ID_VAPP_BRW_BROWSER_ICON" desc="Main menu browser icon">RES_THEME_ROOT"\\\\Default\\\\Mainmenu_Icon\\\\Browser.png"</IMAGE>
<IMAGE id="IMG_ID_VAPP_BRW_BROWSER_ICON" desc="Main menu browser icon">RES_THEME_ROOT"\\\\Default\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\Browser.png"</IMAGE>
<IMAGE id="IMG_ID_VAPP_BRW_MINIMIZE_FULL_SCREEN" desc="minimize full screen browser icon" />
</THEME>
//<IMAGE id="IMG_ID_VAPP_BRW_MINIMIZE_FULL_SCREEN">RES_IMG_ROOT"\\\\Browser\\\\Minimize_N.png"</IMAGE>
<IMAGE id="IMG_ID_VAPP_BRW_STOP">RES_IMG_ROOT"\\\\Browser\\\\Stop.png"</IMAGE>

/* Do not remove this dummy image as it marks the beginning of the snapshot images */
<IMAGE id="IMG_ID_VAPP_BRW_SNAPSHOT_BEGIN" />
/* Begin the snapshot image population below this line in the same order as they are stored in the default 
global shortcut data in COMMON_NVRAM_EF_WAP_GLOBAL_SHORTCUT_LIST_DEFAULT in file nvram_common_config.c */
#ifndef __MMI_BRW_SLIM__
<IMAGE id="IMG_ID_VAPP_BRW_SNAPSHOT_GOOGLE_SEARCH">RES_IMG_ROOT"\\\\Browser\\\\Google.png"</IMAGE>
#ifdef WAP_SEC_SUPPORT
<IMAGE id="IMG_ID_VAPP_BRW_SNAPSHOT_GOOGLEPLUS">RES_IMG_ROOT"\\\\Browser\\\\GooglePlus.png"</IMAGE>
#else
  #if (defined(GOOGLE_SEARCH_SUPPORT) && defined(PGDL_SUPPORT_YOUTUBE))
    <IMAGE id="IMG_ID_VAPP_BRW_SNAPSHOT_YOUTUBE">RES_IMG_ROOT"\\\\Browser\\\\Youtube.png"</IMAGE>
  #else
<IMAGE id="IMG_ID_VAPP_BRW_SNAPSHOT_GOOGLEPLUS"></IMAGE>
#endif
#endif
<IMAGE id="IMG_ID_VAPP_BRW_SNAPSHOT_GAMELOFT">RES_IMG_ROOT"\\\\Browser\\\\Gameloft.png"</IMAGE>
<IMAGE id="IMG_ID_VAPP_BRW_SNAPSHOT_YAHOO">RES_IMG_ROOT"\\\\Browser\\\\Yahoo.png"</IMAGE>
<IMAGE id="IMG_ID_VAPP_BRW_SNAPSHOT_YAHOONEWS">RES_IMG_ROOT"\\\\Browser\\\\YahooNews.png"</IMAGE>
<IMAGE id="IMG_ID_VAPP_BRW_SNAPSHOT_YAHOOOMG">RES_IMG_ROOT"\\\\Browser\\\\YahooOMG.png"</IMAGE>
#else
<IMAGE id="IMG_ID_VAPP_BRW_SNAPSHOT_GOOGLE_SEARCH">RES_IMG_ROOT"\\\\Redesign\\\\Browser\\\\Google.png"</IMAGE>
#ifdef WAP_SEC_SUPPORT
<IMAGE id="IMG_ID_VAPP_BRW_SNAPSHOT_GOOGLEPLUS">RES_IMG_ROOT"\\\\Redesign\\\\Browser\\\\GooglePlus.png"</IMAGE>
#else
  #if (defined(GOOGLE_SEARCH_SUPPORT) && defined(PGDL_SUPPORT_YOUTUBE))
    <IMAGE id="IMG_ID_VAPP_BRW_SNAPSHOT_YOUTUBE">RES_IMG_ROOT"\\\\Redesign\\\\Browser\\\\Youtube.png"</IMAGE>
#endif
#endif
<IMAGE id="IMG_ID_VAPP_BRW_SNAPSHOT_GAMELOFT">RES_IMG_ROOT"\\\\Redesign\\\\Browser\\\\Gameloft.png"</IMAGE>
<IMAGE id="IMG_ID_VAPP_BRW_SNAPSHOT_YAHOO">RES_IMG_ROOT"\\\\Redesign\\\\Browser\\\\Yahoo.png"</IMAGE>
<IMAGE id="IMG_ID_VAPP_BRW_SNAPSHOT_YAHOONEWS">RES_IMG_ROOT"\\\\Redesign\\\\Browser\\\\Yahoo.png"</IMAGE>
<IMAGE id="IMG_ID_VAPP_BRW_SNAPSHOT_YAHOOOMG">RES_IMG_ROOT"\\\\Redesign\\\\Browser\\\\Yahoo.png"</IMAGE>
#endif
<IMAGE id="IMG_ID_VAPP_BRW_SNAPSHOT_END" />
/* Snapshot images end */

/* Cosmos images ends */

/*****************************Browser Srv events ***********************************************/
	<SENDER id="EVT_ID_SRV_BRW_ERROR_IND" hfile="BrowserSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_BRW_SHOW_POPUP" hfile="BrowserSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_BRW_UPDATE_TITLE" hfile="BrowserSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_BRW_RENDERING_STATUS_START_IND" hfile="BrowserSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_BRW_RENDERING_STATUS_END_IND" hfile="BrowserSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_BRW_RENDERING_STATUS_CONTINUE_IND" hfile="BrowserSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_BRW_DOC_INFO_IND" hfile="BrowserSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_BRW_SHOW_SEC_CNF_DLG" hfile="BrowserSrvGprot.h"/>
#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
	<SENDER id="EVT_ID_SRV_BRW_SELECT_FILE_IND" hfile="BrowserSrvGprot.h"/>
#endif
	<SENDER id="EVT_ID_SRV_BRW_URI_REQ_IND" hfile="BrowserSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_BRW_SHOW_AUTH_DLG" hfile="BrowserSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_START_BROWSER_ACTION_IND" hfile="BrowserSrvGprot.h"/>
	#ifdef __SAT__
	<SENDER id="EVT_ID_SRV_BRW_SAT_LAUNCH_REQ" hfile="BrowserSrvGprot.h"/>
	#endif
	<SENDER id="EVT_ID_SRV_BRW_ELEMENT_FOCUSSED_IND" hfile="BrowserSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_BRW_WMLS_DLG_IND" hfile="BrowserSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_BRW_BKM_PROVISIONING_IND" hfile="BrowserSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_BRW_OPEN_BEARER_IND" hfile="BrowserSrvGprot.h"/>
	
	
	<RECEIVER id="EVT_ID_SRV_BRW_ERROR_IND" proc="vappBrwServiceErrorIndHandler"/>
	<RECEIVER id="EVT_ID_SRV_BRW_SHOW_POPUP" proc="vappBrwServiceErrorPopupHandler"/>
#ifdef OBIGO_Q05A
	<RECEIVER id="EVT_ID_SRV_BRW_UPDATE_TITLE" proc="mmi_brw_srv_hdlr_notify_app_proc"/>
#endif
	<RECEIVER id="EVT_ID_SRV_BRW_RENDERING_STATUS_START_IND" proc="vappBrwServiceStartTransactionHandler"/>
	<RECEIVER id="EVT_ID_SRV_BRW_RENDERING_STATUS_END_IND" proc="vappBrwServiceEndTransactionHandler"/>
	<RECEIVER id="EVT_ID_SRV_BRW_RENDERING_STATUS_CONTINUE_IND" proc="vappBrwServiceContinueTransactionHandler"/>
	<RECEIVER id="EVT_ID_SRV_BRW_DOC_INFO_IND" proc="vappBrwServiceDocumentIndHandler"/>
	<RECEIVER id="EVT_ID_SRV_BRW_SHOW_SEC_CNF_DLG" proc="vappBrwServiceSecConfirmHandler"/>
#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
	<RECEIVER id="EVT_ID_SRV_BRW_SELECT_FILE_IND" proc="vappBrwServiceSelectFileIndHandler"/>
#endif
	<RECEIVER id="EVT_ID_SRV_BRW_URI_REQ_IND" proc="vappBrwServiceUriReqHandler"/>
	<RECEIVER id="EVT_ID_SRV_BRW_SHOW_AUTH_DLG" proc="vappBrwServiceAuthenticationIndHandler"/>
	<RECEIVER id="EVT_ID_SRV_START_BROWSER_ACTION_IND" proc="vappBrwServiceStartBrowserHandler"/>s
#ifdef __SAT__
	<RECEIVER id="EVT_ID_SRV_BRW_SAT_LAUNCH_REQ" proc="vappBrwServiceSatLaunchHandler"/>
#endif
	<RECEIVER id="EVT_ID_SRV_BRW_ELEMENT_FOCUSSED_IND" proc="vappBrwServiceElementFocusHandler"/>

	<RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="vappBrwEnterUsbModeHandler"/>
	<RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="vappBrwExitUsbModeHandler"/>
	<RECEIVER id="EVT_ID_SRV_BRW_WMLS_DLG_IND" proc="vappBrwWmlsDlgHandler"/>
	<RECEIVER id="EVT_ID_SRV_BRW_BKM_PROVISIONING_IND" proc="vappBrwBkmProvisioningHandler"/>
	<RECEIVER id="EVT_ID_SRV_BRW_OPEN_BEARER_IND" proc="vappBrwServiceOpenBearerHandler"/>

/***********************************************Event Handling End***************************************/


/***********************************************MENU Ids Begin***************************************/
        <MENU id="MENU_ID_VAPP_BRW_FMGR_BOOKMARK_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS" img="IMG_GLOBAL_OPTIONS">
            <MENUITEM_ID>MENU_ID_VAPP_BRW_FMGR_BOOKMARK_GOTO</MENUITEM_ID>
        </MENU>
        <MENUITEM id="MENU_ID_VAPP_BRW_FMGR_BOOKMARK_GOTO" str="STR_GLOBAL_GO_TO"/>


        <MENU id="MENU_ID_VAPP_BRW_FMGR_BOOKMARK_SEND_OPTIONS" type="OPTION" str="STR_GLOBAL_SEND" />
/***********************************************MENU Ids End***************************************/


 

</APP>
<FILE_TYPES>
    #if 0
    <FILE_GROUP_TYPE type_id="FMGR_GROUP_BOOKMARK" small_icon="IMG_ID_BRW_FMGR_FILE_TYPE_HTM" option="MENU_ID_BRW_WEB_FILE_OPTIONS">
        <FILE_TYPE type_id="FMGR_TYPE_WML" extension="WML" large_icon="IMG_ID_BRW_FMGR_WML_LARGE_TYPE"/>
        <FILE_TYPE type_id="FMGR_TYPE_HTML" extension="HTML" large_icon="IMG_ID_BRW_FMGR_HTML_LARGE_TYPE"/>
        <FILE_TYPE type_id="FMGR_TYPE_HTM" extension="HTM" large_icon="IMG_ID_BRW_FMGR_HTM_LARGE_TYPE"/>
        <FILE_TYPE type_id="FMGR_TYPE_XHTML" extension="XHTML" large_icon="IMG_ID_BRW_FMGR_XHTML_LARGE_TYPE"/>
        <FILE_TYPE type_id="FMGR_TYPE_WMLC" extension="WMLC" large_icon="IMG_ID_BRW_FMGR_WML_LARGE_TYPE"/>
    </FILE_GROUP_TYPE>
    #endif

#if defined (__MMI_VBOOKMARK__ )
    <FILE_TYPE type_id="FMGR_TYPE_URL" extension="URL" small_icon="IMG_ID_VAPP_BRW_FMGR_ICON_FILE_TYPE_VBOOKMARK" large_icon="IMG_ID_VAPP_BRW_FMGR_FILE_TYPE_URL" option="MENU_ID_VAPP_BRW_FMGR_BOOKMARK_OPTIONS" />
    <FILE_TYPE type_id="FMGR_TYPE_VBM" extension="VBM" small_icon="IMG_ID_VAPP_BRW_FMGR_ICON_FILE_TYPE_VBOOKMARK" large_icon="IMG_ID_VAPP_BRW_FMGR_FILE_TYPE_VBM" option="MENU_ID_VAPP_BRW_FMGR_BOOKMARK_OPTIONS" />
#endif

#if defined (__MMI_VBOOKMARK__ )

    <FILE_OPTION_HDLR option="MENU_ID_VAPP_BRW_FMGR_BOOKMARK_GOTO" handler="vappBrwBookmarkOptionsHandler"/>

#endif
</FILE_TYPES>

#endif /* __COSMOS_MMI_PACKAGE__ */

#endif  /*  __MMI_BROWSER_2__  */



