#include "MMI_features.h"
#include "CustResDef.h"

<?xml version="1.0" encoding="UTF-8"?>

/* Needed header files of the compile option in XML files, if you need others need to add here */


#ifdef WAP_SUPPORT

<APP id="VAPP_WAP_PUSH_LAUNCH_VIEWER" name="STR_ID_VAPP_PUSH_LAUNCH_VIEWER" type="venus">
	#ifdef __MMI_PUSH_IN_UM__
    <MEMORY heap="300*1024" cui="VCUI_BKM"/>
    #else 
    <MEMORY heap="0*1024" cui="VCUI_BKM"/>
    #endif
    <STRING id="STR_ID_VAPP_PUSH_LAUNCH_VIEWER"/>
</APP>

<APP id="VAPP_WAP_PUSH_HEAP" name="STR_ID_VAPP_PUSH_HEAP" type="venus">

    <MEMORY heap = "0" vrt_mem_factor = "0" />
    <STRING id="STR_ID_VAPP_PUSH_HEAP"/>
    
</APP>

<APP id="VAPP_WAP_PUSH_EXTRA_BASE" name="STR_ID_VAPP_PUSH_EXTRA_BASE" type="venus">

    <MEMORY extra_base = "0" vrt_mem_factor = "0" />
    <STRING id="STR_ID_VAPP_PUSH_EXTRA_BASE"/>
    
</APP>
<APP id="VAPP_WAP_PUSH_FG" name="STR_ID_VAPP_PUSH_FG" type="venus">

    <MEMORY fg="0" vrt_mem_factor = "0" />
    <STRING id="STR_ID_VAPP_PUSH_FG"/>
    
</APP>
/* APP tag, include your app name defined in MMIDataType.h */
<APP id="VAPP_WAP_PUSH" type="venus" name="STR_ID_VAPP_PUSH_SERVICE_MESSAGE">


    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can file the ID */
    <!--Include Area--> 
    <INCLUDE file = "GlobalResDef.h"/>
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */

<STRING id="STR_ID_VAPP_PUSH_EDIT_WHITE_LIST"/>
<STRING id="STR_ID_VAPP_PUSH_ADD_WHITE_LIST"/>
<STRING id="STR_ID_VAPP_PUSH_RECEIVE_FROM_ADDRESS"/>
<STRING id="STR_ID_VAPP_PUSH_QUESTION_MARK"/>
<STRING id="STR_ID_VAPP_PUSH_SETUP_CONNECTION"/>
<STRING id="STR_ID_VAPP_PUSH_VIEW_IT"/>
<STRING id="STR_ID_VAPP_PUSH_NEW_SERVICE_MESSAGE_FROM"/>
<STRING id="STR_ID_VAPP_PUSH_LAUNCH_IT_BY_BROWSER"/>
<STRING id="STR_ID_VAPP_PUSH_IGNORE"/>
<STRING id="STR_ID_VAPP_PUSH_EDIT_BLACK_LIST"/>
<STRING id="STR_ID_VAPP_PUSH_ADD_BLACK_LIST"/>
<STRING id="STR_ID_VAPP_PUSH_NO_WHITE_LISTS"/>
<STRING id="STR_ID_VAPP_PUSH_NO_BLACK_LISTS"/>
<STRING id="STR_ID_VAPP_PUSH_CHOOSE_THE_MODE"/>
<STRING id="STR_ID_VAPP_PUSH_VIEW_WEBSITE"/>
<STRING id="STR_ID_VAPP_PUSH_LAUNCH_SL_BY_BROWSER"/>
<STRING id="STR_ID_VAPP_PUSH_SIA_NOTIFICATION"/>
<STRING id="STR_ID_VAPP_PUSH_UNMATCHED_ADDR_NOTIFICATION"/>
<STRING id="STR_ID_VAPP_PUSH_GO_TO_URL"/>
<STRING id="STR_ID_VAPP_PUSH_SAVE_TO_BK"/>

    /* String ID's Start */
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
<STRING id="STR_ID_VAPP_PUSH_ENABLE_WHITE_LIST"/>
<STRING id="STR_ID_VAPP_PUSH_WHITE_LIST"/>
<STRING id="STR_ID_VAPP_PUSH_WL_SETTING_DISCARD"/>
<STRING id="STR_ID_VAPP_PUSH_WL_SETTING_NOTIFY"/>
<STRING id="STR_ID_VAPP_PUSH_UNMATCHED_ADDRESS"/>
<STRING id="STR_ID_VAPP_PUSH_ACCEPT_AND_ADD_WL"/>
<STRING id="STR_ID_VAPP_PUSH_REJECT_AND_ADD_BL"/>
<STRING id="STR_ID_VAPP_PUSH_INBOX_TRUST_LIST_PHONE_NUMBER"/>
<STRING id="STR_ID_VAPP_PUSH_INBOX_TRUST_LIST_IP_ADDRESS"/>
<STRING id="STR_ID_VAPP_PUSH_SENDER_ADDRESS"/>
<STRING id="STR_ID_VAPP_PUSH_SMSC_ADDR"/>
<STRING id="STR_ID_VAPP_PUSH_ATLEAST_ONE_FIELD_REQUIRED"/>
<STRING id="STR_ID_VAPP_PUSH_SETTING_INVALID_SENDER"/>
<STRING id="STR_ID_VAPP_PUSH_SETTING_INVALID_SMSC"/>
<STRING id="STR_ID_VAPP_PUSH_INVALID_IP"/>
<STRING id="STR_ID_VAPP_PUSH_SAME_ITEM_EXIST"/>
<STRING id="STR_ID_VAPP_PUSH_ENABLE_SETTING_ACCEPT_AUTHENTICATED"/>
<STRING id="STR_ID_VAPP_PUSH_DELETE_WHITE_LIST"/>
<STRING id="STR_ID_VAPP_PUSH_TRUST_LIST_FULL"/>
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */

#ifdef __MMI_WAP_PUSH_BLACK_LIST__
<STRING id="STR_ID_VAPP_PUSH_ENABLE_BLACK_LIST"/>
<STRING id="STR_ID_VAPP_PUSH_BLACK_LIST"/>
<STRING id="STR_ID_VAPP_PUSH_REJECT_AND_ADD_BL"/>
<STRING id="STR_ID_VAPP_PUSH_DELETE_BLACK_LIST"/>
<STRING id="STR_ID_VAPP_PUSH_BLACK_LIST_FULL"/>
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */

<STRING id="STR_ID_VAPP_PUSH_ENABLE_SERVICE_LOADING"/>
<STRING id="STR_ID_VAPP_PUSH_ENABLE_SETTING_ACCEPT_ALL"/>
<STRING id="STR_ID_VAPP_PUSH_DISABLE"/>
<STRING id="STR_ID_VAPP_PUSH_SL_SETTING_PROMPT"/>
<STRING id="STR_ID_VAPP_PUSH_SL_SETTING_AUTO_LAUNCH"/>
<STRING id="STR_ID_VAPP_PUSH_SIA_REQ_TITLE"/>
<STRING id="STR_ID_VAPP_PUSH_REJECT"/>
<STRING id="STR_ID_VAPP_PUSH_INBOX_SETTING "/>
<STRING id="STR_ID_VAPP_PUSH_INBOX_ENABLE_PUSH "/>
<STRING id="STR_ID_VAPP_PUSH_NO_SUBJECT"/>
<STRING id="STR_ID_VAPP_PUSH_STORAGE_FULL"/>
<STRING id="STR_ID_VAPP_PUSH_COLON_CHAR"/>

<STRING id="STR_ID_VAPP_PUSH_LEFT_BRACE_CHAR"/>
<STRING id="STR_ID_VAPP_PUSH_RIGHT_BRACE_CHAR"/>
<STRING id="STR_ID_VAPP_PUSH_DELETE_SELECTED_ITEMS"/>
<STRING id="STR_ID_VAPP_PUSH_DELETE_CONRM"/>
<STRING id="STR_ID_VAPP_PUSH_PREV"/>
<STRING id="STR_ID_VAPP_PUSH_NEXT"/>
    /* Unified push new string ID */

	/* For PMG display error */
<STRING id="STR_ID_VAPP_PUSH_SERVICE_MESSAGE"/>

    /* String ID's End */





    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of CUST_IMG_PATH"" */

<IMAGE id="IMG_ID_WAP_PUSH_VENUS_MESSAGE_LOW_ICON">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\WAP_Push_L.png"</IMAGE>
<IMAGE id="IMG_ID_WAP_PUSH_VENUS_MESSAGE_ICON">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\WAP_Push.png"</IMAGE>
<IMAGE id="IMG_ID_WAP_PUSH_VENUS_MESSAGE_HIGH_ICON">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\WAP_Push_H.png"</IMAGE>

    /* Image ID's End */


     /*********************************************Push Srv events begin*****************************************************************/
	<SENDER id="EVT_ID_SRV_PUSH_SHOW_PROGRESS" hfile="WAPPushSrvGprots.h"/>
	<SENDER id="EVT_ID_SRV_PUSH_SHOW_POPUP" hfile="WAPPushSrvGprots.h"/>
	<SENDER id="EVT_ID_SRV_PUSH_HANDLE_NEW_SERVICE_MSG" hfile="WAPPushSrvGprots.h"/>
	<SENDER id="EVT_ID_SRV_PUSH_MSG_DELETED_BY_SERVER_IND" hfile="WAPPushSrvGprots.h"/>
	<SENDER id="EVT_ID_SRV_PUSH_DELETE_PUSH_SETTING" hfile="WAPPushSrvGprots.h"/>
	<SENDER id="EVT_ID_SRV_PUSH_HANDLE_FULL_MSG" hfile="WAPPushSrvGprots.h"/>
	<SENDER id="EVT_ID_SRV_PUSH_LAUNCH_SL" hfile="WAPPushSrvGprots.h"/>
	<SENDER id="EVT_ID_SRV_PUSH_HANDLE_SL_NON_IDLE" hfile="WAPPushSrvGprots.h"/>
	<SENDER id="EVT_ID_SRV_PUSH_HANDLE_SL_IDLE" hfile="WAPPushSrvGprots.h"/>
	<SENDER id="EVT_ID_SRV_PUSH_MSG_LIST_REPLY" hfile="WAPPushSrvGprots.h"/>
	<SENDER id="EVT_ID_SRV_PUSH_MSG_COUNT_RSP" hfile="WAPPushSrvGprots.h"/>
	<SENDER id="EVT_ID_SRV_PUSH_DRAW_UNKNOWN" hfile="WAPPushSrvGprots.h"/>
	<SENDER id="EVT_ID_SRV_PUSH_SERVICE_INIT" hfile="WAPPushSrvGprots.h"/>
	<SENDER id="EVT_ID_SRV_PUSH_HANDLE_DLG_DATA_RSP" hfile="WAPPushSrvGprots.h"/>
	<SENDER id="EVT_ID_SRV_PUSH_HANDLE_STORAGE_FULL_IND" hfile="WAPPushSrvGprots.h"/>
	<SENDER id="EVT_ID_SRV_PUSH_HANDLE_DELETE_FOLDER_IND" hfile="WAPPushSrvGprots.h"/>
	<SENDER id="EVT_ID_SRV_PUSH_HANDLE_PENDIG_EVENT_ON_IDLE" hfile="WAPPushSrvGprots.h"/>
	<SENDER id="EVT_ID_SRV_PUSH_FETCH_DLG_QUEUE" hfile="WAPPushSrvGprots.h"/>
	<SENDER id="EVT_ID_SRV_PUSH_DISPLAY_MSG" hfile="WAPPushSrvGprots.h"/>
        <SENDER id="EVT_ID_SRV_PUSH_DISPLAY_ERROR_DLG" hfile="WAPPushSrvGprots.h"/>
	<SENDER id="EVT_ID_SRV_PUSH_PROCESS_DELETE_MSG_RSP" hfile="WAPPushSrvGprots.h"/>
	<SENDER id="EVT_ID_SRV_PUSH_PROCESS_DELETE_ALL_MSG_RSP" hfile="WAPPushSrvGprots.h"/>
#ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__
	<SENDER id="EVT_ID_SRV_PUSH_PROV_CUI_CREATE" hfile="WAPPushSrvGprots.h"/>
	<SENDER id="EVT_ID_SRV_PUSH_PROV_CUI_REDISPLAY" hfile="WAPPushSrvGprots.h"/>
#endif
 #ifdef __MMI_PUSH_IN_UM__	
	<SENDER id="EVT_ID_MMI_UM_DELETE_ALL_RES" hfile="WAPPushSrvGprots.h"/>
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__   
	<SENDER id="EVT_ID_MMI_UM_ENTRY_MARK_SEVERAL_RSP" hfile="WAPPushSrvGprots.h"/>
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
#endif /* __MMI_PUSH_IN_UM__ */ 
	
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
	<SENDER id="EVT_ID_SRV_PUSH_UNKNOWN_ADDR_REQ" hfile="WAPPushSrvGprots.h"/>
	//<RECEIVER id="EVT_ID_SRV_PUSH_UNKNOWN_ADDR_REQ" proc="onServiceUnknownAddrReq"/>
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
	<SENDER id="EVT_ID_SRV_PUSH_INBOX_INIT" hfile="WAPPushSrvGprots.h"/>
	
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
	<SENDER id="EVT_ID_SRV_PUSH_OTA_LIST_ENTRY" hfile="WAPPushSrvGprots.h"/>
	<RECEIVER id="EVT_ID_SRV_PUSH_OTA_LIST_ENTRY" proc="onOTAlistEntryEvt"/>
#endif

	<RECEIVER id="EVT_ID_SRV_PUSH_SHOW_PROGRESS" proc="onProgressEvt"/>
	<RECEIVER id="EVT_ID_SRV_PUSH_SHOW_POPUP" proc="onPopupEvt"/>
	<RECEIVER id="EVT_ID_SRV_PUSH_HANDLE_NEW_SERVICE_MSG" proc="onNewServiceMsg"/>
	<RECEIVER id="EVT_ID_SRV_PUSH_MSG_DELETED_BY_SERVER_IND" proc="onMsgDeletedByServerIndEvt"/>
	<RECEIVER id="EVT_ID_SRV_PUSH_HANDLE_FULL_MSG" proc="onFullMsgEvt"/>
	<RECEIVER id="EVT_ID_SRV_PUSH_DELETE_PUSH_SETTING" proc="onDelPushSettingEvt"/>
	//<RECEIVER id="EVT_ID_SRV_PUSH_LAUNCH_SL" proc="onLaunchSL"/>
	//<RECEIVER id="EVT_ID_SRV_PUSH_HANDLE_SL_NON_IDLE" proc="onSLOnNonIdle"/>
	//<RECEIVER id="EVT_ID_SRV_PUSH_HANDLE_SL_IDLE" proc="onSLOnIdle"/>
	<RECEIVER id="EVT_ID_SRV_PUSH_MSG_LIST_REPLY" proc="onMsgListReply"/>
	<RECEIVER id="EVT_ID_SRV_PUSH_MSG_COUNT_RSP" proc="onMsgCntRsp"/>
	<RECEIVER id="EVT_ID_SRV_PUSH_DRAW_UNKNOWN" proc="onDrawUnknownScren"/>
	//<RECEIVER id="EVT_ID_SRV_PUSH_SERVICE_INIT" proc="onServiceInitiationReq"/>
	//<RECEIVER id="EVT_ID_SRV_PUSH_HANDLE_DLG_DATA_RSP" proc="onDlgDataRsp"/>
	<RECEIVER id="EVT_ID_SRV_PUSH_HANDLE_STORAGE_FULL_IND" proc="onStorageFullInd"/>
	<RECEIVER id="EVT_ID_SRV_PUSH_HANDLE_DELETE_FOLDER_IND" proc="onDeleteFolderInd"/>
	<RECEIVER id="EVT_ID_SRV_PUSH_HANDLE_PENDIG_EVENT_ON_IDLE" proc="onPendigEventOnIdle"/>
	<RECEIVER id="EVT_ID_SRV_PUSH_FETCH_DLG_QUEUE" proc="onFetchDlgFromQueue"/>
	//<RECEIVER id="EVT_ID_SRV_PUSH_DISPLAY_MSG" proc="onDisplayMsg"/>
	<RECEIVER id="EVT_ID_SRV_PUSH_INBOX_INIT" proc="onPushAppInit"/>
        <RECEIVER id="EVT_ID_SRV_PUSH_DISPLAY_ERROR_DLG" proc="onDisplayErrorDlg"/>
	<RECEIVER id="EVT_ID_SRV_PUSH_PROCESS_DELETE_MSG_RSP" proc="onProcessDeleteMsgRsp"/>
	<RECEIVER id="EVT_ID_SRV_PUSH_PROCESS_DELETE_ALL_MSG_RSP" proc="onProcessDeleteAllMsgRsp"/>
#ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__
	<RECEIVER id="EVT_ID_SRV_PUSH_PROV_CUI_CREATE" proc="onPushProvSettingCreate"/>
	<RECEIVER id="EVT_ID_SRV_PUSH_PROV_CUI_REDISPLAY" proc="onPushProvSettingRedisplay"/>
#endif
#ifdef __MMI_PUSH_IN_UM__
    <RECEIVER id="EVT_ID_MMI_UM_DELETE_ALL_RES" proc="onDeleteAllRsp"/>
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__   
     <RECEIVER id="EVT_ID_MMI_UM_ENTRY_MARK_SEVERAL_RSP" proc="onUMMarkSeveralRsp"/>
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
#endif /* __MMI_PUSH_IN_UM__ */ 

#ifdef __MMI_FLIGHT_MODE_NOTIFICATION_NEW__
	<RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="onModeFinishSwitchEventHdlr"/>
#endif

#ifdef __MMI_UM_ITERATOR_VIEWER__
#ifdef __MMI_PUSH_IN_UM__
	<RECEIVER id="EVT_ID_MMI_UM_REFRESH" proc="onUpdateIndexingDataFromUM"/>
#endif
#endif
#ifdef __MMI_PUSH_IN_UM__
	<RECEIVER id="EVT_ID_MMI_UM_ENTRY_FOLDER" proc="onUMEnterFolder"/>
#endif /* __MMI_PUSH_IN_UM__ */

    
		 <THEME>
         <COLOR id = "CLR_ID_PUSH_MSG_TEXT_FONT_COLOR" desc = "the text of push message font color"/>
         <COLOR id = "CLR_ID_PUSH_MSG_TEXT_BG_COLOR" desc = "the text of back ground color"/>
         <COLOR id = "CLR_ID_PUSH_MSG_TEXT_VIEW_COLOR" desc = "the text of back ground color"/>
     </THEME>



</APP>
#endif /* WAP_SUPPORT */