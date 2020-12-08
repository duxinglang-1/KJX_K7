#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

#ifndef __MMI_EMAIL__

<APP id="VAPP_EMAIL"></APP>

#else

<APP id="VAPP_EMAIL" 
    package_name="native.mtk.vapp_email"
    name="STR_EMAIL_FTO_EMAIL"
    img="IMG_EMAIL_FTO_MAINMENU"
    launch="vapp_email_package_launch"
    package_proc = "vapp_email_package_proc" 
    type="venus">

    <INCLUDE file="customer_email_num.h"/>

    <MEMORY 
    #ifdef __MMI_EMAIL_SUPPORT_1000_MAILS__
        heap="920*1024 + MMI_EMAIL_MAX_CONT_MEM_SIZE" 
    #else
        heap="440*1024 + MMI_EMAIL_MAX_CONT_MEM_SIZE" 
    #endif

    #if defined(__VENUS_3D_UI_ENGINE__)
        vrt_mem_factor="4.0"
    #endif
    
    #if (defined(__LOW_COST_SUPPORT_COMMON__))
        #ifdef __MMI_VUI_SAVE_BOOKMARK_SUPPORT__
            cui="max(max(max(max(max(max(max(max(max(max(VCUI_CONTACT_SAVE, VCUI_DIALER_MAKE_CALL), VAPP_BOOKMARK_CUI), 0), VCUI_FMGR), VCUI_DTCNT), VCUI_CBM), VCUI_MUSIC_PLAYER), VCUI_GALLERY_IMAGE_VIEWER), 0), VCUI_EMAILCOMPOSER)"/>
        #else
            cui="max(max(max(max(max(max(max(max(max(max(VCUI_CONTACT_SAVE, VCUI_DIALER_MAKE_CALL), 0), 0), VCUI_FMGR), VCUI_DTCNT), VCUI_CBM), VCUI_MUSIC_PLAYER), VCUI_GALLERY_IMAGE_VIEWER), 0), VCUI_EMAILCOMPOSER)"/>
        #endif
    #else
        #ifdef __MMI_VUI_SAVE_BOOKMARK_SUPPORT__
            cui="max(max(max(max(max(max(max(max(max(max(VCUI_CONTACT_SAVE, VCUI_DIALER_MAKE_CALL), VAPP_BOOKMARK_CUI), 0), VCUI_FMGR), VCUI_DTCNT), VCUI_CBM), VCUI_MUSIC_PLAYER), VCUI_GALLERY_IMAGE_VIEWER), VCUI_GALLERY_VIDEO_PLAYER), VCUI_EMAILCOMPOSER)"/>
        #else
            cui="max(max(max(max(max(max(max(max(max(max(VCUI_CONTACT_SAVE, VCUI_DIALER_MAKE_CALL), 0), 0), VCUI_FMGR), VCUI_DTCNT), VCUI_CBM), VCUI_MUSIC_PLAYER), VCUI_GALLERY_IMAGE_VIEWER), VCUI_GALLERY_VIDEO_PLAYER), VCUI_EMAILCOMPOSER)"/>
        #endif
    #endif

    <LAYOUT file="vapp_email.xml"/>

    <INCLUDE file="GlobalResDef.h"/>

    <STRING id="STR_EMAIL_FTO_EMAIL"/>
    <STRING id="STR_EMAIL_FTO_MARK_UNREAD_ID"/>
    <STRING id="STR_EMAIL_FTO_SENT_ID"/>
    <STRING id="STR_EMAIL_FTO_RETRIEVING_ID"/>
    <STRING id="STR_EMAIL_FTO_MORE_FOLDER_ID"/>
    <STRING id="STR_EMAIL_FTO_MAILS_ID"/>
    <STRING id="STR_EMAIL_FTO_COMMON_SAVE_TO_DRAFT_ID"/>
    <STRING id="STR_EMAIL_FTO_COMMON_MOVE_TO_DRAFT_ID"/>
    <STRING id="STR_EMAIL_FTO_COMMON_NO_SUBJECT_ID"/>
    <STRING id="STR_EMAIL_FTO_COMMON_MOVED_ID"/>
    <STRING id="STR_EMAIL_FTO_ERROR_CODE_CONN_FAIL_ID"/>
    <STRING id="STR_EMAIL_FTO_ERROR_CODE_AUTH_FAIL_ID"/>
    <STRING id="STR_EMAIL_FTO_ERROR_CODE_NETWORK_ID"/>
    <STRING id="STR_EMAIL_FTO_ERROR_CODE_NOT_SUPPORT_APOP_ID"/>
    <STRING id="STR_EMAIL_FTO_MSG_SSL_ERROR"/>
    <STRING id="STR_EMAIL_FTO_MSG_SERVER_TLS_FAIL"/>
    <STRING id="STR_EMAIL_FTO_DNS_ERR"/>
    <STRING id="STR_EMAIL_FTO_SMTP_RCPT_TO_FAIL"/>
    <STRING id="STR_EMAIL_FTO_RECIPIENT_TOO_MANY_ID"/>
    <STRING id="STR_EMAIL_FTO_DEL_SEL_MAIL_ID"/>
    <STRING id="STR_EMAIL_FTO_DEL_DESTROY_ID"/>
    <STRING id="STR_EMAIL_FTO_FOLDER_SORT_SUBJECT_ID"/>
    <STRING id="STR_EMAIL_FTO_FOLDER_SORT_SIZE_ID"/>
    <STRING id="STR_EMAIL_FTO_TO_ID"/>
    <STRING id="STR_EMAIL_FTO_CC_ID"/>
    <STRING id="STR_EMAIL_FTO_BCC_ID"/>
    <STRING id="STR_EMAIL_FTO_ATTACHMENTS_ID"/>
    <STRING id="STR_EMAIL_FTO_REPLY_ALL_ID"/>
    <STRING id="STR_EMAIL_FTO_STOP_REFRESH_ID"/>
    <STRING id="STR_EMAIL_FTO_STOP_SEND_ID"/>
    <STRING id="STR_EMAIL_FTO_EMAIL_SETTING_ID"/>
    <STRING id="STR_EMAIL_FTO_FROM_ID"/>
    <STRING id="STR_EMAIL_FTO_FROM"/>
    <STRING id="STR_EMAIL_FTO_URL_SAVE_FTO_BOOKMARK_ID"/>
    <STRING id="STR_EMAIL_FTO_ATTACHMENT_ID"/>
    <STRING id="STR_EMAIL_FTO_ACCOUNTS_ID"/>
    <STRING id="STR_EMAIL_FTO_DEL_SELECTED_MAIL_ID"/>
    <STRING id="STR_EMAIL_FTO_DEL_SELECTED_MAILS_ID"/>
    <STRING id="STR_EMAIL_FTO_QUESTION_MARK_ID"/>
    <STRING id="STR_EMAIL_FTO_LINK_HTML"/>
    
    <STRING id="STR_EMAIL_FTO_NEW_ACCOUNT"/>
    <STRING id="STR_EMAIL_FTO_ADVANCED_SETTINGS"/>
    <STRING id="STR_EMAIL_FTO_ACCOUNTS"/>
    <STRING id="STR_EMAIL_FTO_DOWNLOAD_SIZE"/>
    <STRING id="STR_EMAIL_FTO_REPLY_TO_ADDRESS"/>
    <STRING id="STR_EMAIL_FTO_APOP_SECURE_LOGIN"/>
    <STRING id="STR_EMAIL_FTO_INCOMING_PORT"/>
    <STRING id="STR_EMAIL_FTO_OUTGOING_PORT"/>
    <STRING id="STR_EMAIL_FTO_RETRIEVE_AMOUNT"/>
    <STRING id="STR_EMAIL_FTO_ACCOUNT_INFO"/>

    <STRING id="STR_EMAIL_1_HOUR_ID"/>
    <STRING id="STR_EMAIL_2_HOURS_ID"/> 
    <STRING id="STR_EMAIL_FTO_30_MINS"/>
    <STRING id="STR_EMAIL_FTO_5_MINS"/> 
    <STRING id="STR_EMAIL_ACCT_NAME_ID"/> 
    <STRING id="STR_EMAIL_ACCT_SETTING_ID"/>
    <STRING id="STR_EMAIL_AUTHORIZING_ID"/> 
    <STRING id="STR_EMAIL_CHECK_INTERVAL_ID"/> 
    <STRING id="STR_EMAIL_DISPLAY_NAME_ID"/> 
    <STRING id="STR_EMAIL_DOWNLOAD_ALL"/>
    <STRING id="STR_EMAIL_FTO_DOWNLOAD_OPTION"/> 
    <STRING id="STR_EMAIL_ERROR_CODE_AUTH_FAIL_ID"/> 
    <STRING id="STR_EMAIL_ERROR_CODE_BEARER_FAIL"/> 
    <STRING id="STR_EMAIL_ERROR_CODE_CONN_FAIL_ID"/> 
    <STRING id="STR_EMAIL_ERROR_CODE_IMAP_CMD"/> 
    <STRING id="STR_EMAIL_ERROR_CODE_MSG_NOT_EXISTING_ID"/> 
    <STRING id="STR_EMAIL_ERROR_CODE_NETWORK_ID"/> 
    <STRING id="STR_EMAIL_ERROR_CODE_NOT_SUPPORT_APOP_ID"/> 
    <STRING id="STR_EMAIL_ERROR_CODE_OPT_FAIL_ID"/>
    <STRING id="STR_EMAIL_ERROR_CODE_POP_CMD"/> 
    <STRING id="STR_EMAIL_ERROR_CODE_SELECT_FOLDER"/> 
    <STRING id="STR_EMAIL_ERROR_CODE_SMTP_CMD"/> 
    <STRING id="STR_EMAIL_ERROR_CODE_REACH_MAX_NUM"/>    
    <STRING id="STR_EMAIL_HEADER_ONLY"/>
    <STRING id="STR_EMAIL_HEADER_TEXT"/>
    <STRING id="STR_EMAIL_IMAP4_ID"/> 
    <STRING id="STR_EMAIL_INVALID_MAIL_MESSAGE"/> 
    <STRING id="STR_EMAIL_MSG_SERVER_TLS_FAIL"/> 
    <STRING id="STR_EMAIL_OUTGOING_SERVER_ID"/> 
    <STRING id="STR_EMAIL_POP3_ID"/>
    <STRING id="STR_EMAIL_PROTOCOL_ID"/>
    <STRING id="STR_EMAIL_REMOTE_FOLDER_ID"/> 
    <STRING id="STR_EMAIL_SAVE_SENT_EMAILS_ID"/> 
    <STRING id="STR_EMAIL_SECURITY_ID"/> 
    <STRING id="STR_EMAIL_SENT_ID"/>
    <STRING id="STR_EMAIL_SIGNATURE_ID"/> 
    <STRING id="STR_EMAIL_SIGNATURE_ON_OFF_ID"/>
    <STRING id="STR_EMAIL_SMTP_RCPT_TO_FAIL"/> 
    <STRING id="STR_EMAIL_UPDATING_INFO_ID"/> 
    <STRING id="STR_EMAIL_USING_SSL_ID"/> 
    <STRING id="STR_EMAIL_USING_TLS_ID"/> 
    <STRING id="STR_EMAIL_TEMPLATE_1"/>
    <STRING id="STR_EMAIL_TEMPLATE_2"/>
    <STRING id="STR_EMAIL_TEMPLATE_3"/>
    <STRING id="STR_EMAIL_TEMPLATE_4"/>
    <STRING id="STR_EMAIL_TEMPLATE_5"/>
    <STRING id="STR_EMAIL_TEMPLATE_6"/>
    <STRING id="STR_EMAIL_TEMPLATE_7"/>
    <STRING id="STR_EMAIL_TEMPLATE_8"/>
    <STRING id="STR_EMAIL_TEMPLATE_9"/>
    <STRING id="STR_EMAIL_TEMPLATE_10"/>
    <STRING id="STR_EMAIL_COLON_ID"/>

    <STRING id="STR_EMAIL_FTO_OUTGOING_SERVER"/>
    <STRING id="STR_EMAIL_FTO_INCOMING_SERVER"/>
    <STRING id="STR_EMAIL_FTO_ADVANCED"/>
    <STRING id="STR_EMAIL_FTO_EMAIL_ADDR"/>
    <STRING id="STR_EMAIL_FTO_DOWNLOAD_SIZE_KB"/>
    <STRING id="STR_EMAIL_FTO_USER_INFO"/>
    <STRING id="STR_EMAIL_FTO_LOG_IN_INFO"/>
    <STRING id="STR_EMAIL_FTO_ACCT_INFO"/>
    <STRING id="STR_EMAIL_FTO_PLEASE_INPUT_EMAIL_ADDR"/>
    <STRING id="STR_EMAIL_FTO_INVALID_EMAIL_ADDR"/>
    <STRING id="STR_EMAIL_FTO_PLEASE_INPUT_PSWD"/>
    <STRING id="STR_EMAIL_FTO_PLEASE_INPUT_ACCT_NAME"/>
    <STRING id="STR_EMAIL_FTO_PLEASE_INPUT_USER_NAME"/>
    <STRING id="STR_EMAIL_FTO_INVALID_DOWNLOAD_SIZE"/>
    <STRING id="STR_EMAIL_FTO_EMAIL_SETTING"/>
    <STRING id="STR_EMAIL_FTO_WIFI_ONLY"/>
    <STRING id="STR_EMAIL_FTO_ALWAYS_USE_WIFI"/>
    <STRING id="STR_EMAIL_FTO_DEFAULT_DATA_ACCT"/>
    <STRING id="STR_EMAIL_FTO_NOTIFI_AUTO_UPDATE"/>
    <STRING id="STR_EMAIL_FTO_RETRIEVE_AMOUNT_MAILS"/>
    <STRING id="STR_EMAIL_FTO_REPLY_TO_ADDR"/>
    <STRING id="STR_EMAIL_FTO_AT_DOT_COM"/>
    <STRING id="STR_EMAIL_FTO_INVALID_RETRIEVE_AMOUNT"/>
    <STRING id="STR_EMAIL_FTO_DEFAULT_ACCT"/>
    <STRING id="STR_EMAIL_FTO_INVLAID_SERVER_ADDR"/>
    <STRING id="STR_EMAIL_FTO_VALID_PORT_RANGE"/>
    <STRING id="STR_EMAIL_FTO_INSERT"/>
    <STRING id="STR_EMAIL_FTO_REMOTE_FOLDER"/>
    <STRING id="STR_EMAIL_FTO_WRITE_SIG_TEXT_HERE"/>
    <STRING id="STR_EMAIL_FTO_EDIT_SIG"/>
    <STRING id="STR_EMAIL_FTO_ACCT_WIZARD"/>
    <STRING id="STR_EMAIL_FTO_FINISH"/>
    <STRING id="STR_EMAIL_FTO_OTHERS"/>
    <STRING id="STR_EMAIL_FTO_PREV"/>
    <STRING id="STR_EMAIL_FTO_NEXT"/>
    <STRING id="STR_EMAIL_FTO_BASIC_INFO"/>
    <STRING id="STR_EMAIL_FTO_TEXT_NETWORK"/>
    <STRING id="STR_EMAIL_FTO_CONNECTING_NETWORK"/>
    <STRING id="STR_EMAIL_FTO_TRY_AGAIN"/>
    <STRING id="STR_EMAIL_FTO_TEST_FAILED"/>
    <STRING id="STR_EMAIL_FTO_BASIC_INFO_1_3"/>
    <STRING id="STR_EMAIL_FTO_PROTOCOL_2_3"/>
    <STRING id="STR_EMAIL_FTO_SERVER_INFO_3_3"/>
    <STRING id="STR_EMAIL_FTO_GLOBAL_SETTING"/>
    <STRING id="STR_EMAIL_FTO_ALWAYS_SHOW_CC"/>
    <STRING id="STR_EMAIL_FTO_PUSH_ACCT"/>    
    <STRING id="STR_EMAIL_FTO_NEW_EMAIL"/>
    <STRING id="STR_EMAIL_FTO_EDIT_EMAIL"/>
    <STRING id="STR_EMAIL_FTO_SELECT_ACCT"/>
    <STRING id="STR_EMAIL_FTO_SAVED_TO_DRAFT"/>
    <STRING id="STR_EMAIL_FTO_ADDR_EXIST"/>
    <STRING id="STR_EMAIL_FTO_NEW_EMAIL_ID"/>
    <STRING id="STR_EMAIL_FTO_MAIL_BOXES_ID"/>
    <STRING id="STR_EMAIL_FTO_RESEND_MAIL_ID"/>
    <STRING id="STR_EMAIL_FTO_STOP_SENDING"/>
    <STRING id="STR_EMAIL_FTO_SEND_MAIL_ID"/>
    <STRING id="STR_EMAIL_FTO_LINK_MORE"/>
    <STRING id="STR_EMAIL_FTO_USE_DETAILS_ID"/>
    <STRING id="STR_EMAIL_FTO_DEL_MSG_CONFIRM_ID"/>
    <STRING id="STR_EMAIL_FTO_FOLDER_SORT_TIME_ID"/>
    <STRING id="STR_EMAIL_FTO_FOLDER_SORT_SENDER_ID"/>
    <STRING id="STR_EMAIL_FTO_FOLDER_SORT_RECIPIENT_ID"/>
    <STRING id="STR_EMAIL_FTO_FOLDER_SORT_READ_STAUTS_ID"/>
    <STRING id="STR_EMAIL_FTO_REMOTE_FOLDER_ID"/>
    <STRING id="STR_EMAIL_FTO_SENDING_CANNOT_REFRESH"/>
    <STRING id="STR_EMAIL_PLEASE_DOWNLOAD"/>
    <STRING id="STR_EMAIL_REFRESHING_CANNOT_SEND"/>
    <STRING id="STR_EMAIL_REFRESHING_CANNOT_SORT"/>
    <STRING id="STR_EMAIL_SENDING_CANNOT_SORT"/>
    <STRING id="STR_EMAIL_SENDING_CANNOT_DELETE"/>
    <STRING id="STR_EMAIL_FTO_STOP_SENDING"/>
    <STRING id="STR_EMAIL_REFRESHING_CANNOT_DELETE"/>
    <STRING id="STR_EMAIL_STOP_NETWORK_CONFIRM"/>
    <STRING id="STR_EMAIL_UPDATED_AT"/>
    <STRING id="STR_EMAIL_FTO_NEVER_UPDATE"/>
    <STRING id="STR_EMAIL_FTO_NO_RECIPIENT"/>
    <STRING id="STR_EMAIL_FTO_TOO_LARGE_TO_DOWN_ID"/>
    <STRING id="STR_EMAIL_FTO_SWITCH_STORAGE_ID"/>
    <STRING id="STR_EMAIL_FTO_CONTENT_TOO_LARGE_ID"/>
    <STRING id="STR_EMAIL_FTO_ATTACH_NOT_COMPLETE_ID"/>
    <STRING id="STR_EMAIL_FTO_BROKEN_EMAIL_DELETE_ID"/>
    <STRING id="STR_EMAIL_FTO_SIZE_TOO_LARGE"/>
    <STRING id="STR_EMAIL_FTO_START_CREATE_ACCT_ID"/>
    <STRING id="STR_EMAIL_FTO_CREATE_ID"/>

    <STRING id="STR_EMAIL_FTO_NC_UNREAD_ID"/>
    <STRING id="STR_EMAIL_FTO_NC_UNREAD_MAIL_ID"/>
    <STRING id="STR_EMAIL_FTO_NC_UNREAD_MAILS_ID"/>
    <STRING id="STR_EMAIL_FTO_NC_SEND_FAIL_ID"/>
    <STRING id="STR_EMAIL_FTO_NC_REFRESH_FAIL_ID"/>
    <STRING id="STR_EMAIL_FTO_NC_PUSH_REFRESH_FAIL_ID"/>    
    <STRING id="STR_EMAIL_FTO_NC_ACCOUNTS_ID"/>
    <STRING id="STR_EMAIL_FTO_NC_SENDING_ID"/>
    <STRING id="STR_EMAIL_FTO_NC_REFRESHING_ID"/>
    <STRING id="STR_EMAIL_FTO_NC_STOP_1_SEND_ID"/>
    <STRING id="STR_EMAIL_FTO_NC_STOP_N_SEND_PRE_ID"/>
    <STRING id="STR_EMAIL_FTO_NC_STOP_N_SEND_POST_ID"/>
    <STRING id="STR_EMAIL_FTO_NC_STOP_1_REFRESH_ID"/>
    <STRING id="STR_EMAIL_FTO_NC_STOP_N_REFRESH_PRE_ID"/>
    <STRING id="STR_EMAIL_FTO_NC_STOP_N_REFRESH_POST_ID"/>
    <STRING id="STR_EMAIL_FTO_EMPTY_FILE"/>
    <STRING id="STR_EMAIL_FTO_ATTCH_TOO_LARGE"/>
    <STRING id="STR_EMAIL_FTO_PREPARE_TO_SEND"/>
    <STRING id="STR_EMAIL_FTO_EMOTION"/>
    <STRING id="STR_EMAIL_FTO_REPLY_IND"/>
    <STRING id="STR_EMAIL_FTO_FWD_IND"/>
    <STRING id="STR_EMAIL_FTO_EDIT_ACCT_USING"/>
    <STRING id="STR_EMAIL_FTO_NO_EMAIL_ACCT"/>
    <STRING id="STR_EMAIL_FTO_SENDING_CANNOT_OPEN_ID"/>
    <STRING id="STR_EMAIL_FTO_MSG_DELETE_ON_SERVER_ID"/>
    <STRING id="STR_EMAIL_FTO_MSG_SENT_INFO_ID"/>
    <STRING id="STR_EMAIL_FTO_DEL_THE_ACCT"/>
    <STRING id="STR_EMAIL_FTO_EMAIL_OPTIONS_ID"/>
    <STRING id="STR_EMAIL_FTO_TESTING"/>
    <STRING id="STR_EMAIL_FTO_FAILED_TO_DELETE_ID"/>
    <STRING id="STR_EMAIL_FTO_NO_ACCOUNTS_ID"/>
    <STRING id="STR_EMAIL_FTO_NO_EMAILS_ID"/>
    <STRING id="STR_EMAIL_FTO_FILE_TYEP_NOT_SUPPORTED_ID"/>

    <STRING id="STR_EMAIL_FTO_TOOLBAR_NEXT"/>
    <STRING id="STR_EMAIL_EMAIL_FUNCBAR_OK"/>
    <STRING id="STR_EMAIL_FTO_WIZARD_WRONG_DOMAIN"/>
    <STRING id="STR_EMAIL_FTO_MAX_NUM_REACHED"/>
    <STRING id="STR_EMAIL_FTO_SWITCHING"/>
    <STRING id="STR_EMAIL_FTO_VERIFYING"/>
    <STRING id="STR_EMAIL_FTO_STILL_SAVE"/>
    <STRING id="STR_EMAIL_FTO_CANNOT_MATCH_TMPL"/>
    <STRING id="STR_EMAIL_FTO_CONTINUE"/>
    <STRING id="STR_EMAIL_FTO_DRM_FILE_DELETED"/>
    <STRING id="STR_EMAIL_FTO_URI_SEND_NOW"/>
    <STRING id="STR_EMAIL_FTO_SIG_PART_DISCARDED"/>     
    <STRING id="STR_EMAIL_FTO_SIG_DISCARDED"/>
    <STRING id="STR_EMAIL_FTO_REFESHING_CANNOT_OPEN"/>
    <STRING id="STR_EMAIL_FTO_OTAP_FAIL_MASS_STORAGE"/>
    <STRING id="STR_EMAIL_FTO_LEFT_PARENTHESES"/>
    <STRING id="STR_EMAIL_FTO_RIGHT_PARENTHESES"/>
    <STRING id="STR_EMAIL_FTO_PUSH_EMAIL_ACCT"/>
    <STRING id="STR_EMAIL_FTO_CANNOT_REPLACE"/>    
    <STRING id="STR_EMAIL_FTO_MEMORY_FULL"/>
    <STRING id="STR_EMAIL_FTO_PHONE_FULL"/>
    <STRING id="STR_EMAIL_FTO_VIEW_IN_FMGR"/>
    <STRING id="STR_EMAIL_FTO_REMOVE_PHONE_FILE"/>
    <STRING id="STR_EMAIL_FTO_REMOVE_MEMORY_FILE"/>
    <STRING id="STR_EMAIL_FTO_SSO_IMPORT_ID"/>
    <STRING id="STR_EMAIL_FTO_SSO_REPLACE_ID"/>

    #define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\Mainmenu_Icon\\\\"

    <THEME>
        <IMAGE id="IMG_EMAIL_FTO_MAINMENU" desc="Main menu email icon">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\Email.png"</IMAGE>
    </THEME>
    
/*-- below IMG for ugly data account --*/
    #define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\Email\\\\ListIcon\\\\"
    <IMAGE id="IMG_EMAIL_FTO_APP1_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP2_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP3_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP4_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP5_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP6_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP7_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP8_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP9_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP10_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP11_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP12_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP13_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP14_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP15_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP16_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP17_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP18_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP19_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP20_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP21_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP22_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP23_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP24_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP25_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP26_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP27_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP28_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP29_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP30_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP31_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP32_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP33_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP34_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP35_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP36_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP37_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP38_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP39_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_APP40_ID">ROOT_PATH"All_Mail.png"</IMAGE>
/*-- above IMG for ugly data account --*/

/*-- to be removed --*/
    <IMAGE id="IMG_EMAIL_MARK_DELETED_BIG_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_UNREAD_LOW_ATT_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_UNREAD_LOW_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_UNREAD_HIGH_ATT_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_UNREAD_HIGH_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_UNREAD_NORMAL_ATT_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_UNREAD_NORMAL_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_READ_LOW_ATT_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_READ_LOW_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_READ_HIGH_ATT_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_READ_HIGH_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_READ_NORMAL_ATT_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_READ_NORMAL_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_MAIN_ID">ROOT_PATH"All_Mail.png"</IMAGE>
    <MENU id = "MENU_ID_EMAIL_MAIN" type = "APP_MAIN" str = "STR_GLOBAL_EMAIL" img = "IMG_EMAIL_MAIN_ID" 
    launch="mmi_email_main_entry_from_shortcut"></MENU>
/*-- to be removed --*/

    #define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\\Components\\\\\Toolbar\\\\\CommonIcon\\\\"
    <IMAGE id="IMG_EMAIL_FTO_ADD">ROOT_PATH"Add.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_CANCEL">ROOT_PATH"Cancel.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_DELETE">ROOT_PATH"Delete.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_EDIT">ROOT_PATH"Edit.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_SAVE">ROOT_PATH"Save.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_SETTING">ROOT_PATH"Settings.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_INSERT">ROOT_PATH"Insert.png"</IMAGE>

    #define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\Email\\\\ListIcon\\\\"
    <IMAGE id="IMG_EMAIL_FTO_LIST_ACCT">ROOT_PATH"Account.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_ALL_MAIL">ROOT_PATH"All_Mail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_ATTCH">ROOT_PATH"Attchment.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_BROKEN">ROOT_PATH"Broken.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_CALL_ENABLE">ROOT_PATH"Call_Card.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_CALL_DISABLE">ROOT_PATH"Call_Card_dis.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_GET_URL">ROOT_PATH"Get_URL.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_HEADER_CONT">ROOT_PATH"Header_Content.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_HEADER_ONLY">ROOT_PATH"Header_Only.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_PRIO_HIGH">ROOT_PATH"Priority_High.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_PRIO_HIGH_ATT">ROOT_PATH"Priority_High_Att.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_PRIO_LOW">ROOT_PATH"Priority_Low.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_PRIO_LOW_ATT">ROOT_PATH"Priority_Low_Att.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_PRIO_MED">ROOT_PATH"Priority_Medium.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_SEND_MAIL">ROOT_PATH"SendEmail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_UNFINISH">ROOT_PATH"Unfinished.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_REMOTE_SUB_ID">ROOT_PATH"Subscribe.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_REMOTE_UNSUB_ID">ROOT_PATH"Unsubscribe.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_ACCT_REFRESH_ERROR_DEFAULT">ROOT_PATH"Refresh_Error_Default.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_ACCT_REFRESH_ERROR_OTHERS">ROOT_PATH"Refresh_Error_Others.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_ACCT_REFRESHING">ROOT_PATH"Refreshing.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_ACCT_SEND_ERROR_DEFAULT">ROOT_PATH"Send_Error_Default.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_ACCT_SEND_ERROR_OHTERS">ROOT_PATH"Send_Error_Others.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_ACCT_NORMAIL_DEFAULT">ROOT_PATH"Email_Default.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_ACCT_NORMAIL_OHTERS">ROOT_PATH"Email_Others.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_PUSH_ACCT_REFRESH_ERROR_DEFAULT">ROOT_PATH"Refresh_Error_Default_Push.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_PUSH_ACCT_REFRESH_ERROR_OTHERS">ROOT_PATH"Refresh_Error_Others_Push.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_PUSH_ACCT_REFRESHING">ROOT_PATH"Refreshing_Push.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_PUSH_ACCT_SEND_ERROR_DEFAULT">ROOT_PATH"Send_Error_Default_Push.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_PUSH_ACCT_SEND_ERROR_OHTERS">ROOT_PATH"Send_Error_Others_Push.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_PUSH_ACCT_NORMAIL_DEFAULT">ROOT_PATH"Email_Default_Push.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_PUSH_ACCT_NORMAIL_OHTERS">ROOT_PATH"Email_Others_Push.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_PUSH_ACCT_SENDING">ROOT_PATH"Sending_Push.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_PUSH_ACCT_WAITING">ROOT_PATH"Waiting_Push.png"</IMAGE>       

    #define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\Common\\\\Button\\\\"
    <IMAGE id="IMG_EMAIL_FTO_LIST_ADD">ROOT_PATH"Add.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_DEL">ROOT_PATH"Delete.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_DOWNLOAD">ROOT_PATH"Download.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_SAVE">ROOT_PATH"Save.png"</IMAGE>
    
    #define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\Common\\\\ListIcon\\\\"
    <IMAGE id="IMG_EMAIL_FTO_LIST_ACCT_WAITING">ROOT_PATH"Waiting.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_MSG_SEND_FAIL">ROOT_PATH"Fail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_MSG_SENDING">ROOT_PATH"Sending.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LIST_MSG_WAITING">ROOT_PATH"Waiting.png"</IMAGE>

    #define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\Email\\\\ToolbarIcon\\\\"
    <IMAGE id="IMG_EMAIL_FTO_TB_ACCT_SET">ROOT_PATH"Account_Setting.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_TB_CC">ROOT_PATH"CC.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_TB_EMAIL_SET">ROOT_PATH"Emai_Setting.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_TB_MAKE_UNREAD">ROOT_PATH"Make_Unread.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_TB_MOVE_DRAFT">ROOT_PATH"Move_Draft.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_TB_NEW_MAIL">ROOT_PATH"New_Email.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_TB_NEW_TEMPLATE">ROOT_PATH"New_Template.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_TB_NEXT">ROOT_PATH"Next.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_TB_SET_DEFAULT">ROOT_PATH"Set_Default.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_TB_SORT">ROOT_PATH"Sort.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_TB_TEST">ROOT_PATH"Test.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_TB_USE_DETAIL">ROOT_PATH"Use_Detail.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_TB_DOWNLOAD">ROOT_PATH"Download.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_TB_MAILBOXES">ROOT_PATH"MailBoxes.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_TB_REPLY_ALL">ROOT_PATH"Replay_All.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_TB_STOP">ROOT_PATH"Stop.png"</IMAGE>

    #define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\NMGR_Icon\\\\"
    <IMAGE id="IMG_EMAIL_FTO_NC_UNREAD">ROOT_PATH"icon_email_unread.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_NC_SEND_FAIL">ROOT_PATH"icon_alert.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_NC_REFRESH_FAIL">ROOT_PATH"icon_alert.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_NC_SENDING">ROOT_PATH"icon_email_send.png"</IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_NC_REFRESHING">ROOT_PATH"icon_email_refresh.png"</IMAGE>

    #define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\Message\\\\ContactSelector\\\\"
    <IMAGE id="IMG_EMAIL_FTO_ADDRESS_BG_ID">ROOT_PATH"BTN_N.9slice.png"</IMAGE>

<THEME>
    <IMAGE id="IMG_EMAIL_FTO_UNFOLD_ID" desc="unfolde mail receivers"></IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_FOLD_ID" desc="fold mail receivers"></IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_UNREAD_ID" desc="unread mail icon"></IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_TITLEBAR_BG_ID" desc="title bar backgroud image of message list page"></IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_LEFT_ID" desc="left icon of title bar"></IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_RIGHT_ID" desc="right icon of title bar"></IMAGE>
    <IMAGE id="IMG_EMAIL_FTO_CONTENT_BG_ID" desc="backgroud image of mail content"></IMAGE>
    
    <COLOR id = "CLR_EMAIL_FTO_MAIL_CONTENT_TEXT" desc = "Mail content text color"/>
    <COLOR id = "CLR_EMAIL_FTO_MAIL_CONTENT_UNDERLINE" desc = "Mail content underline color"/>
</THEME>    

    <!----- Event Handler Registe------>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="vapp_email_mgr_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="vapp_email_mgr_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="vapp_email_mgr_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION" proc = "vapp_email_mgr_notify_hdlr"/>

    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="vapp_email_mgr_notify_hdlr"/>

#ifdef __MMI_USB_SUPPORT__
    <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="vapp_email_mgr_notify_hdlr"/>
    <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="vapp_email_mgr_notify_hdlr"/>
#endif /* __MMI_USB_SUPPORT__ */

    <RECEIVER id="EVT_ID_SRV_SHUTDOWN_FINAL_DEINIT" proc="vapp_email_mgr_notify_hdlr"/>

    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc= "vapp_email_mgr_notify_hdlr "/>

    <TIMER id="EMAIL_MMI_EMN_NOTIFY_TIMER"/>
    <TIMER id="EMAIL_MMI_CONT_PARSER_TIMER"/>    
    <TIMER id="VAPP_EMAIL_MGR_JOB_SCHEDULER"/>    
    <TIMER id="EMAIL_MMI_AUTO_CHECK_TIMER_0"/>
    <TIMER id="EMAIL_MMI_AUTO_CHECK_TIMER_1"/>
    <TIMER id="EMAIL_MMI_AUTO_CHECK_TIMER_2"/> 
    <TIMER id="EMAIL_MMI_AUTO_CHECK_TIMER_3"/>
    <TIMER id="EMAIL_MMI_AUTO_CHECK_TIMER_4"/>
    <TIMER id="EMAIL_MMI_AUTO_CHECK_TIMER_5"/>
    <TIMER id="EMAIL_MMI_AUTO_CHECK_TIMER_6"/> 
    <TIMER id="EMAIL_MMI_AUTO_CHECK_TIMER_7"/>
    <TIMER id="EMAIL_MMI_AUTO_CHECK_TIMER_8"/>
    <TIMER id="EMAIL_MMI_AUTO_CHECK_TIMER_9"/>
 
#ifdef __MMI_SSO__
    <RECEIVER id="EVT_ID_SRV_EMAIL_CLOUD_IND" proc="vapp_email_sso_ind_hdlr"/>
    <RECEIVER id="EVT_ID_CUI_SSO_LOGIN_DONE" proc="vapp_email_sso_login_done_hdlr"/>
#endif /* __MMI_SSO__ */

</APP>

#endif /* __MMI_EMAIL__ */