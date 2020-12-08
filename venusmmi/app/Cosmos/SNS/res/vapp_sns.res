/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

#if defined(__SOCIAL_NETWORK_SUPPORT__) && defined (__COSMOS_MMI_PACKAGE__)
/* APP tag, include your app name defined in MMIDataType.h */
<APP id="VAPP_SNS_PLUGIN"
    package_name="native.mtk.sns.bg" 
    name="STR_ID_VAPP_SNS_PLUGIN"
    hidden_in_mainmenu="true"
    type="venus">

    <MEMORY heap="VAPP_SNS_PLUGIN_MIN_MEMORY" inc="vapp_sns_mem_def.h"/>

</APP>

<APP id="VAPP_SNS_BG"
    package_name="native.mtk.sns.bg" 
    name="STR_ID_VAPP_SNS_BG"
    hidden_in_mainmenu="true"
    type="venus">
    
    <MEMORY heap="5"/>

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>
    
    <!-- String Resource Area-------------------------------------------------->

    <STRING id="STR_ID_VAPP_SNS_BG"/>
    
    <!------------------------------------------------------CallBack Manager---------------------------------------------------------->    
    <RECEIVER id="EVT_ID_SRV_SNS_PROCESS_START"        proc="vapp_sns_bg_process_handler"/>    
    <RECEIVER id="EVT_ID_SRV_SNS_PROCESS_COMPLETE"     proc="vapp_sns_bg_process_handler"/>
    <RECEIVER id="EVT_ID_SRV_SNS_ACCOUNT_LOGGED_OUT"   proc="vapp_sns_account_logout_handler"/>    
    <RECEIVER id="EVT_ID_SRV_SNS_PLUGINS_UPGRADED"     proc="vapp_sns_upgrade_result_handler"/>
		
</APP>

#ifdef __MMI_SNS_CENTER__
<APP id="VAPP_SNS" 
    package_name="native.mtk.sns" 
    name="STR_ID_VAPP_SNS"
    img="IMG_ID_VAPP_SNS_MAINMENU_ICN" 
    launch="vapp_sns_app_launch" 
    package_proc="vapp_sns_app_proc"
    type="venus">
#else
<APP id="VAPP_SNS" 
    package_name="native.mtk.sns" 
    name="STR_ID_VAPP_SNS"
    hidden_in_mainmenu="true"
    type="venus">
#endif /*__MMI_SNS_CENTER__*/

#ifdef __MMI_SNS_SLIM__
    <MEMORY cui="max(VCUI_SNS_UPLOAD_PIC, VCUI_SNS_CONTACTS_PICKER)" 
            fg="max(max(VAPP_GALLERY_ASYNC_MEDIALIST_L1_PREVIEW_FG_SIZE, VAPP_GALLERY_ASYNC_MEDIALIST_THUMB_FG_SIZE), 768*1024)" 
            heap="900*1024" 
            inc="vapp_gallery_gprot.h"/>
#else
    <MEMORY cui="max(VCUI_SNS_UPLOAD_PIC, VCUI_SNS_CONTACTS_PICKER)" 
            fg="max(max(VAPP_GALLERY_ASYNC_MEDIALIST_L1_PREVIEW_FG_SIZE, VAPP_GALLERY_ASYNC_MEDIALIST_THUMB_FG_SIZE), 1536*1024)" 
            heap="900*1024" 
            inc="vapp_gallery_gprot.h"/>
#endif    
    
    <APPCONCURRENT concurrent ="VAPP_SNS, VAPP_SNS_PLUGIN"/>
    
    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>
    <INCLUDE file="Mmi_rp_srv_venus_component_tool_bar_def.h"/>
    
    <!-- String Resource Area-------------------------------------------------->

    <STRING id="STR_ID_VAPP_SNS"/>
    <STRING id="STR_ID_VAPP_SNS_HAPPENINGS"/>
    <STRING id="STR_ID_VAPP_SNS_TIDINGS"/>
    <STRING id="STR_ID_VAPP_SNS_PROFILE"/>
    <STRING id="STR_ID_VAPP_SNS_ALBUMS"/>
    <STRING id="STR_ID_VAPP_SNS_MESSAGES"/>
    <STRING id="STR_ID_VAPP_SNS_POST"/>
    <STRING id="STR_ID_VAPP_SNS_POST_STATUS"/>
    <STRING id="STR_ID_VAPP_SNS_UPLOAD"/>
    <STRING id="STR_ID_VAPP_SNS_UPLOAD_PICTURE"/>
    <STRING id="STR_ID_VAPP_SNS_TAP_TO_REFRESH"/>
    <STRING id="STR_ID_VAPP_SNS_REFRESHING"/>    
    <STRING id="STR_ID_VAPP_SNS_FILTER"/>
    <STRING id="STR_ID_VAPP_SNS_ALL_OF_ACCOUNTS"/> 
    <STRING id="STR_ID_VAPP_SNS_ADD"/>   
    <STRING id="STR_ID_VAPP_SNS_CREATE_GROUP"/>   
    <STRING id="STR_ID_VAPP_SNS_CREATE_NEW_GROUP"/>   
    <STRING id="STR_ID_VAPP_SNS_COMMENT"/>		
    <STRING id="STR_ID_VAPP_SNS_COMMENTS"/>
    <STRING id="STR_ID_VAPP_SNS_CHOOSE_ACCOUNTS"/>	
    <STRING id="STR_ID_VAPP_SNS_NOTIFICATIONS"/>	
    <STRING id="STR_ID_VAPP_SNS_REQUESTS"/>	
    <STRING id="STR_ID_VAPP_SNS_ACCEPT"/>	
    <STRING id="STR_ID_VAPP_SNS_ACCEPTED"/>	
    <STRING id="STR_ID_VAPP_SNS_REJECT"/>	
    <STRING id="STR_ID_VAPP_SNS_REJECTED"/>	
    <STRING id="STR_ID_VAPP_SNS_FAILED"/>	
    <STRING id="STR_ID_VAPP_SNS_PROCESSING"/>
    <STRING id="STR_ID_VAPP_SNS_GROUPS"/>	
    <STRING id="STR_ID_VAPP_SNS_REFRESH"/>
    <STRING id="STR_ID_VAPP_SNS_MY_CONTACTS"/>   
    <STRING id="STR_ID_VAPP_SNS_ME"/>
    <STRING id="STR_ID_VAPP_SNS_BROWSE"/>
    <STRING id="STR_ID_VAPP_SNS_MESSAGE"/>
    <STRING id="STR_ID_VAPP_SNS_BIRTHDAY"/>
    <STRING id="STR_ID_VAPP_SNS_PHONE"/>
    <STRING id="STR_ID_VAPP_SNS_EMAIL"/>
    <STRING id="STR_ID_VAPP_SNS_ADDRESS"/>
    <STRING id="STR_ID_VAPP_SNS_NO_GROUPS"/>
    <STRING id="STR_ID_VAPP_SNS_NO_MEMBERS"/>
    <STRING id="STR_ID_VAPP_SNS_LEFT_PARENTHESIS"/>
    <STRING id="STR_ID_VAPP_SNS_RIGHT_PARENTHESIS"/>
    <STRING id="STR_ID_VAPP_SNS_DELETE_SELECTED_GROUP"/>
    <STRING id="STR_ID_VAPP_SNS_DELETE_SELECTED_GROUPS"/>
    <STRING id="STR_ID_VAPP_SNS_EDIT_GROUP_MEMBER"/>
    <STRING id="STR_ID_VAPP_SNS_ADD_GROUP_MEMBER"/>
    <STRING id="STR_ID_VAPP_SNS_REMOVE_GROUP_MEMBER"/>
    <STRING id="STR_ID_VAPP_SNS_EDIT_MEMBER"/>
    <STRING id="STR_ID_VAPP_SNS_GROUP_NAME_DUPLICATED"/>    
    <STRING id="STR_ID_VAPP_SNS_FAIL_TO_EDIT_GROUP"/>
    <STRING id="STR_ID_VAPP_SNS_RENAME"/>
    <STRING id="STR_ID_VAPP_SNS_NO_ACTIVITIES"/>
    <STRING id="STR_ID_VAPP_SNS_NO_COMMENTS"/>
    <STRING id="STR_ID_VAPP_SNS_NO_NOTIFICATIONS"/>    
    <STRING id="STR_ID_VAPP_SNS_NO_REQUESTS"/>
    <STRING id="STR_ID_VAPP_SNS_NO_ACCOUNTS"/>    
    <STRING id="STR_ID_VAPP_SNS_NO_CONTACTS"/>
    <STRING id="STR_ID_VAPP_SNS_SELECT_SNS_CONTACT"/>
    <STRING id="STR_ID_VAPP_SNS_FAIL_TO_UPDATE_STATUS"/>
    <STRING id="STR_ID_VAPP_SNS_FAIL_TO_ADD_COMMENT"/>
    <STRING id="STR_ID_VAPP_SNS_POSTED"/>
    <STRING id="STR_ID_VAPP_SNS_UPDATE_PLEASE_WAIT"/>
    <STRING id="STR_ID_VAPP_SNS_ADD_PLEASE_WAIT"/>
    <STRING id="STR_ID_VAPP_SNS_NEW_REQUEST"/>
    <STRING id="STR_ID_VAPP_SNS_NEW_REQUESTS"/>
    <STRING id="STR_ID_VAPP_SNS_NEW_NOTIFICATION"/>
    <STRING id="STR_ID_VAPP_SNS_NEW_NOTIFICATIONS"/>
    <STRING id="STR_ID_VAPP_SNS_SEARCH"/>
    <STRING id="STR_ID_VAPP_SNS_REACH_MAX_GROUP_NUM"/>
    <STRING id="STR_ID_VAPP_SNS_REACH_MAX_SELECTED_NUM"/>
    <STRING id="STR_ID_VAPP_SNS_OPEN_BROWSER_TO_SEE_DETAILS"/>
    <STRING id="STR_ID_VAPP_SNS_BUSY_NOW_PLEASE_TRY_LATER"/>
    <STRING id="STR_ID_VAPP_SNS_PLEASE_SET_SNS_ACCOUNTS_FIRST"/>
    <STRING id="STR_ID_VAPP_SNS_ACCOUNT_HAS_BEEN_LOGOUT"/>
    <STRING id="STR_ID_VAPP_SNS_YOUR"/>
    <STRING id="STR_ID_VAPP_SNS_UPDATED"/>
    <STRING id="STR_ID_VAPP_SNS_FAILED_TO_UPDATED"/>
    <STRING id="STR_ID_VAPP_SNS_SYNC_TO_GET_SNS_CONTACTS"/>
    <STRING id="STR_ID_VAPP_SNS_SYNCING_CONTACTS"/>
    <STRING id="STR_ID_VAPP_SNS_SYNC"/>
    
    <STRING id="STR_ID_VAPP_SNS_SETTINGS_TITLE"/>
    <STRING id="STR_ID_VAPP_SNS_ACCOUNTS_SETTINGS"/>
    <STRING id="STR_ID_VAPP_SNS_NEWS_REMINDER"/>
    <STRING id="STR_ID_VAPP_SNS_FACEBOOK_ACCOUNT"/>
    <STRING id="STR_ID_VAPP_SNS_ACCOUNT"/>
    <STRING id="STR_ID_VAPP_SNS_SYNCINTERVAL"/>
    <STRING id="STR_ID_VAPP_SNS_SYNCCONTACTS"/>
    <STRING id="STR_ID_VAPP_SNS_SYNCCALENDAR"/>
    <STRING id="STR_ID_VAPP_SNS_SYNCSETTING"/>
    <STRING id="STR_ID_VAPP_SNS_NO_ALBUMS"/>
    <STRING id="STR_ID_VAPP_SNS_NO_MORE_ALBUMS"/>
    <STRING id="STR_ID_VAPP_SNS_ALBUM_ME"/>
    <STRING id="STR_ID_VAPP_SNS_VIEW_MORE"/>
    <STRING id="STR_ID_VAPP_SNS_VIEW_EARLIER"/>
    <STRING id="STR_ID_VAPP_SNS_LAST_UPDATE"/>
    <STRING id="STR_ID_VAPP_SNS_SEE_ALL"/>
    <STRING id="STR_ID_VAPP_SNS_TAP_TO_RETRY"/>
    <STRING id="STR_ID_VAPP_SNS_NO_PICTURES"/>
    
#ifdef __MMI_SNS_MESSAGES__
    <STRING id="STR_ID_VAPP_SNS_MSG_NO_MSG"/>
    <STRING id="STR_ID_VAPP_SNS_MSG_NEW_SNS_MSG"/>
    <STRING id="STR_ID_VAPP_SNS_MSG_NEW_SNS_MSGS"/>
    <STRING id="STR_ID_VAPP_SNS_MGS_FAIL_TO_SEND"/>
    <STRING id="STR_ID_VAPP_SNS_MSG_ONE_SENDING_PLEASE_WAIT"/>
#endif /* __MMI_SNS_MESSAGES__ */

//#ifdef __FACEBOOK_CONTENT_SUPPORT__
    <STRING id="STR_ID_VAPP_SNS_FB_LIKE"/>
    <STRING id="STR_ID_VAPP_SNS_FB_LIKES"/>
    <STRING id="STR_ID_VAPP_SNS_FB_LIKE_TB"/>
    <STRING id="STR_ID_VAPP_SNS_FB_UNLIKE_TB"/>
    <STRING id="STR_ID_VAPP_SNS_FB_COMMENT"/>
    <STRING id="STR_ID_VAPP_SNS_FB_COMMENTS"/>
//#endif /* __FACEBOOK_CONTENT_SUPPORT__ */

//#ifdef __TWITTER_CONTENT_SUPPORT__
    <STRING id="STR_ID_VAPP_SNS_TWT_RETWEET_TB"/>
    <STRING id="STR_ID_VAPP_SNS_TWT_RETWEET"/>
    <STRING id="STR_ID_VAPP_SNS_TWT_RETWEETS"/>
    <STRING id="STR_ID_VAPP_SNS_TWT_FAILED_TO_RETWEET"/>
//#endif /* __TWITTER_CONTENT_SUPPORT__ */

    <STRING id="STR_ID_VAPP_SNS_REMINDER_NEVER"/>
    <STRING id="STR_ID_VAPP_SNS_HOURS"/>
    <STRING id="STR_ID_VAPP_SNS_MINS"/>
    <STRING id="STR_ID_VAPP_SNS_HOUR"/>
    <STRING id="STR_ID_VAPP_SNS_MIN"/>
    <STRING id="STR_ID_VAPP_SNS_DAY"/>
    <STRING id="STR_ID_VAPP_SNS_WEEK"/>
    <STRING id="STR_ID_VAPP_SNS_LOGIN"/>
    <STRING id="STR_ID_VAPP_SNS_LOGGINGIN"/>
    <STRING id="STR_ID_VAPP_SNS_LOGOUT"/>
    <STRING id="STR_ID_VAPP_SNS_LOGGINGOUT"/>

    <!-- Audio Resource Area-------------------------------------------------->
    <AUDIO id="AUD_ID_VAPP_SNS_NEWS" flag="MULTIBIN">CUST_ADO_PATH"\\\\SNS\\\\news_remindar.mp3"</AUDIO>

    <!-- Image Resource Area--------------------------------------------------->
    <!-- Main Menu Icon -->
    
    <IMAGE id="IMG_ID_VAPP_SNS_PIC_VIEWER_TITLE_BG">RES_IMG_ROOT"\\\\SNS\\\\SNS_PicView_BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_REFRESH_CELL_BG">RES_IMG_ROOT"\\\\SNS\\\\SNS_Refresh_BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_REFRESH_CELL_BG_PRESSED">RES_IMG_ROOT"\\\\SNS\\\\SNS_Refresh_BG_Pressed.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_CELL_BG">RES_IMG_ROOT"\\\\SNS\\\\SNS_HV_BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_BTN_DISCARD">RES_IMG_ROOT"\\\\SNS\\\\SNSIcon_Discard.png"</IMAGE>
    
    
    <IMAGE id="IMG_ID_VAPP_SNS_LIST_SYNC_N_ICN">RES_IMG_ROOT"\\\\SNS\\\\ListIcon\\\\Sync_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_LIST_SYNC_P_ICN">RES_IMG_ROOT"\\\\SNS\\\\ListIcon\\\\Sync_P.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_LIST_SYNC_D_ICN">RES_IMG_ROOT"\\\\SNS\\\\ListIcon\\\\Sync_D.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_LIST_REFRESH_N_ICN">RES_IMG_ROOT"\\\\SNS\\\\ListIcon\\\\Sync_N_Big.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_LIST_REFRESH_P_ICN">RES_IMG_ROOT"\\\\SNS\\\\ListIcon\\\\Sync_P_Big.png"</IMAGE>    
    <IMAGE id="IMG_ID_VAPP_SNS_LIST_SYNCING_ICN">RES_IMG_ROOT"\\\\SNS\\\\ListIcon\\\\Syncing.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_LIST_UPLOAD_FAIL_ICN">RES_IMG_ROOT"\\\\SNS\\\\ListIcon\\\\Failed.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_LIST_SNS_ICN">RES_IMG_ROOT"\\\\SNS\\\\ListIcon\\\\SNS.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_LIST_SNS_SMALL_ICN">RES_IMG_ROOT"\\\\SNS\\\\ListIcon\\\\SNS_s.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_LIST_GROUP_ICN">RES_IMG_ROOT"\\\\SNS\\\\ListIcon\\\\Group.png"</IMAGE>
        
    <IMAGE id="IMG_ID_VAPP_SNS_TAB_HAPPENINGS_ICN">RES_IMG_ROOT"\\\\SNS\\\\TabIcon\\\\Happening.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_TAB_TIDINGS_ICN">RES_IMG_ROOT"\\\\SNS\\\\TabIcon\\\\Tidings.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_TAB_PROFILE_ICN">RES_IMG_ROOT"\\\\Contact\\\\TabIcon\\\\Profile.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_TAB_ALBIMS_ICN">RES_IMG_ROOT"\\\\SNS\\\\TabIcon\\\\Albums.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_TAB_SNS_ICN">RES_IMG_ROOT"\\\\SNS\\\\TabIcon\\\\SNS.png"</IMAGE>

    <IMAGE id="IMG_ID_VAPP_SNS_TOOL_BAR_LOGOUT">RES_IMG_ROOT"\\\\SNS\\\\ToolbarIcon\\\\Logout.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_TOOL_BAR_COMMENTS_ICN">RES_IMG_ROOT"\\\\SNS\\\\ToolbarIcon\\\\Comments.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_TOOL_BAR_COMMENTS_FOLD_ICN">RES_IMG_ROOT"\\\\SNS\\\\ToolbarIcon\\\\Comments_Retract.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_TOOL_BAR_COMMENTS_UNFOLD_ICN">RES_IMG_ROOT"\\\\SNS\\\\ToolbarIcon\\\\Comments_Spread.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_TOOL_BAR_FILTER_ICN">RES_IMG_ROOT"\\\\SNS\\\\ToolbarIcon\\\\Filter.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_TOOL_BAR_POST_ICN">RES_IMG_ROOT"\\\\SNS\\\\ToolbarIcon\\\\Post.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_TOOL_BAR_RENAME_ICN">RES_IMG_ROOT"\\\\SNS\\\\ToolbarIcon\\\\Rename.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_TOOL_BAR_UPLOAD_ICN">RES_IMG_ROOT"\\\\SNS\\\\ToolbarIcon\\\\Upload.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_TOOL_BAR_ADD_GROUP_ICN">RES_IMG_ROOT"\\\\Contact\\\\ToolbarIcon\\\\Add_Group.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_TOOL_BAR_DELETE_GROUP_ICN">RES_IMG_ROOT"\\\\Contact\\\\ToolbarIcon\\\\Delete_Group.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_TOOL_BAR_GROUP_ICN">RES_IMG_ROOT"\\\\Contact\\\\ToolbarIcon\\\\Group.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_TOOL_BAR_EDIT_MEMBER_ICN">RES_IMG_ROOT"\\\\Contact\\\\ToolbarIcon\\\\Edit_Member.png"</IMAGE>
 
    <IMAGE id="IMG_ID_VAPP_SNS_TOOL_BAR_LIKE_ICN">RES_IMG_ROOT"\\\\SNS\\\\ToolbarIcon\\\\Like.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_TOOL_BAR_UNLIKE_ICN">RES_IMG_ROOT"\\\\SNS\\\\ToolbarIcon\\\\Unlike.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_TOOL_BAR_RETWEET_ICN">RES_IMG_ROOT"\\\\SNS\\\\ToolbarIcon\\\\Retweet.png"</IMAGE>

    <MENUITEM id="MENU_ID_SNS_ADD" str="STR_GLOBAL_ADD" img="VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD"/>
    <MENUITEM id="MENU_ID_SNS_COMMENTS" str="STR_ID_VAPP_SNS_COMMENTS" img="IMG_GLOBAL_L1"/>
    <MENUITEM id="MENU_ID_SNS_SHARE" str="STR_GLOBAL_SHARE" img="VCP_IMG_TOOL_BAR_COMMON_ITEM_SHARE"/>
    <MENUITEM id="MENU_ID_SNS_SEE_ALL" str="STR_ID_VAPP_SNS_SEE_ALL" img="IMG_GLOBAL_L2"/>
    <MENUITEM id="MENU_ID_SNS_SAVE" str="STR_GLOBAL_SAVE" img="VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE"/>
    
    <MENU id="MENU_ID_SNS_IMG_VIEWER" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SNS_ADD</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_SHARE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SNS_SAVE</MENUITEM_ID>
    </MENU>
    <!-- Theme Images -->
    <THEME>
    <COLOR id="CLR_ID_VAPP_SNS_MAIN_TEXT"               desc = "The color of main text in sns happenings, tidings and messages screen"/>
    <COLOR id="CLR_ID_VAPP_SNS_MAIN_TEXT_DISABLED"      desc = "The disabled color of main text in sns happenings, tidings and messages screen"/>
    <COLOR id="CLR_ID_VAPP_SNS_HINT_TEXT"               desc = "The color of content and hint text in sns happenings, tidings and messages screen"/>
    <COLOR id="CLR_ID_VAPP_SNS_HINT_TEXT_DISABLED"      desc = "The disabled color of content and hint text in sns happenings, tidings and messages screen"/>
    <COLOR id="CLR_ID_VAPP_SNS_MAIN_TEXT_HIGHLIGHT"     desc = "The color when the main text is highlight"/>
    <COLOR id="CLR_ID_VAPP_SNS_IMAGE_BG"                desc = "The background color of when the image is loading or not exists"/>
    <COLOR id="CLR_ID_VAPP_SNS_IMAGE_BORDER"            desc = "The border color of the image"/>
    <COLOR id="CLR_ID_VAPP_SNS_REQUEST_STATUS_BG"       desc = "The background color of the request processing status"/>
    
    <IMAGE id="IMG_ID_VAPP_SNS_MAINMENU_ICN"            desc = "Main menu sns icon">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\SNS.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNS_SEARCH"                  desc = "The sns contact search icon in the list"/>
    <IMAGE id="IMG_ID_VAPP_SNS_BTN_BACK"                desc = "The sns contact back button icon in the search bar"/>
#ifdef __MMI_SNS_MESSAGES__
    <IMAGE id="IMG_ID_VAPP_SNS_MSG_EDITOR_BG"           desc = "The background of the sender in the sns message screen and viewer screen"/>
    <IMAGE id="IMG_ID_VAPP_SNS_MSG_NEW_MSG"             desc = "The new sns message icon in the conversation list"/>
    <IMAGE id="IMG_ID_VAPP_SNS_NEW_MSG_BTN_BG_N"        desc = "The normal situation of the new sns message button background"/>
    <IMAGE id="IMG_ID_VAPP_SNS_NEW_MSG_BTN_BG_P"        desc = "The Press situation of the new sns message button background"/>
    <IMAGE id="IMG_ID_VAPP_SNS_NEW_MSG_BTN_BG_D"        desc = "The disable situation of the new sns message button background"/>
#endif /* __MMI_SNS_MESSAGES__ */
    </THEME>


    <!-- APP Images -->
    #define SNS_IMG_ROOT       RES_IMG_ROOT"\\\\Home\\\\"


    <!-- Event Area (Sender) -------------------------------------------------->


    <!-- Event Area (Receiver) ------------------------------------------------>
    <RECEIVER id="EVT_ID_SRV_SNS_READY"                proc="vapp_sns_ncenter_send_event_handler"/>
    <RECEIVER id="EVT_ID_SRV_SNS_PROCESS_START"        proc="vapp_sns_ncenter_send_event_handler"/>    
    <RECEIVER id="EVT_ID_SRV_SNS_PROCESS_COMPLETE"     proc="vapp_sns_ncenter_send_event_handler"/>
    <RECEIVER id="EVT_ID_SRV_SNS_ACCOUNT_LOGGED_OUT"   proc="vapp_sns_ncenter_send_event_handler"/>    
    
    <RECEIVER id="EVT_ID_SRV_SNS_READY"                proc="vapp_sns_ncenter_counts_update_event_handler"/>
    <RECEIVER id="EVT_ID_SRV_SNS_COUNTS_UPDATED"       proc="vapp_sns_ncenter_counts_update_event_handler"/>
    <RECEIVER id="EVT_ID_SRV_SNS_NET_FETCH_LIST_START" proc="vapp_sns_ncenter_fetch_event_handler"/>
    <RECEIVER id="EVT_ID_SRV_SNS_NET_FETCH_LIST_END"   proc="vapp_sns_ncenter_fetch_event_handler"/>
    
    <!---MMI Cache------------------------------------------------------------->   
       
</APP>

#endif /* __SOCIAL_NETWORK_SUPPORT__ */
