#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

#ifdef __SYNCML_SUPPORT__

<APP id="VAPP_SYNC" package_name="native.mtk.sync" name="STR_ID_VAPP_SYNC" img="IMG_ID_VAPP_SYNC" launch="vapp_sync_launch" type="venus">
    <MEMORY base="500*1024 + base(VCUI_DTCNT) + base(VCUI_BT_SELDEV)" heap="500*1024" fg="fg(VCUI_DTCNT)"/>
    <LAYOUT file="vapp_sync.xml" />
    
    #define SYNC_PATH 			 RES_IMG_ROOT"\\\\Sync\\\\"
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
        <STRING id="STR_ID_VAPP_SYNC">"Sync"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_COMMA">","</STRING>
		<STRING id="STR_ID_VAPP_SYNC_COLON">":"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_QUESTION">"?"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_SPACE">" "</STRING>
		<STRING id="STR_ID_VAPP_SYNC_QUOTES_LEFT">"'"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_QUOTES_RIGHT">"'"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_PLEASE_WAIT">"please wait"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_NOW">"Sync now"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_LOG">"Sync log"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_LOG_DB_FINISH">"finish"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_LOG_DB_UNFINISH">"unfinish"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_NO_LOG">"No logs"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_REPORT">"Sync report"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_ACCNT_NAME">"Account name"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_APP_TO_SYNC">"Applications to sync"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_DB_ADDR">"Database address"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_PLS_SEL_APP">"Please select application"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_ACCNTS">"accounts"</STRING>
		
		<STRING id="STR_ID_VAPP_SYNC_CON">"Contacts"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_CAL">"Calendar"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_TASK">"Tasks"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_NOTE">"Notes"</STRING>
		
		<STRING id="STR_ID_VAPP_SYNC_DB_INVALID_SRV_ADDR">"Please input server address"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_DB_INVALID_ACCNT_NAME">"Please input account name"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_DB_INVALID_ADDR_CON">"Please input contacts database address"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_DB_INVALID_ADDR_CAL">"Please input calendar database address"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_DB_INVALID_ADDR_TASK">"Please input tasks database address"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_DB_INVALID_ADDR_NOTE">"Please input notes database address"</STRING>
		
		<STRING id="STR_ID_VAPP_SYNC_REGULAR_NEVER">"Never"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_REGULAR_PWRON">"When handset is on"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_REGULAR_DATA_CHANGE">"When data is changed"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_REGULAR_EVERY_DAY">"Every day"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_REGULAR_EVERY_WEEK">"Every week"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_REGULAR_EVERY_MONTH">"Every month"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_HIDE">"Hide"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_IS_SYNCING">" syncing"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_SYNCHRONIZING">"Synchronizing"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_SENDING">"Sending "</STRING>
		<STRING id="STR_ID_VAPP_SYNC_SENDING_RIGHT"></STRING>		
		<STRING id="STR_ID_VAPP_SYNC_RECEIVING">"Receiving "</STRING>
		<STRING id="STR_ID_VAPP_SYNC_RECEIVING_RIGHT"></STRING>
		<STRING id="STR_ID_VAPP_SYNC_UNFINISH">"Sync unfinished"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_DISCONN">"Disconnected"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_LOCAL_INFO">"Local sync information"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_SERVER_INFO">"Server sync information"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_FINISHED">" finished"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_UNFINISHED">"unfinished"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_DEL_ASK">"Delete"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_REACH_MAXIMUM">"Maximum number reached"</STRING>
		
		/* Remote sync*/
		<STRING id="STR_ID_VAPP_SYNC_REMOTE">"Remote sync"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_REMOTE_ACCNTS">"Remote sync accounts"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_ADD_RMT_ACCNT">"Add server account"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_ACCNT_INFO">"Account infomation"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_NO_ACCNT">"No account"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_SERVER_CONN">"Server connection"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_DATA_ACCNT">"Default data account"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_REGULAR_SYNC">"Regular sync"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_SERVER_ADDR">"Server address"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_BASIC_INFO">"Basic information"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_NEXT">"Next"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_FUNC_PREV">"Prev"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_FUNC_NEXT">"Next"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_FUNC_OK">"OK"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_ACCNT_NAME_EXIST">"Account name already exists"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_PLS_SERVER_ADDR">"Please input server address"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_INVALID_SERVER_ADDR">"Invalid server address"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_CANT_FIND_SERVER">"Can't find server"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_REGULAR_ASK">"Start regular sync with "</STRING>
		<STRING id="STR_ID_VAPP_SYNC_REGULAR_ASK_RIGHT"></STRING>
		<STRING id="STR_ID_VAPP_SYNC_STEP_13">"(1/3)"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_STEP_23">"(2/3)"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_STEP_33">"(3/3)"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_FINISH">"Finish"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_CANCELLING">"Cancelling"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_ABORT_ASK">"Abort current sync?"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_WIFI_ALWAYS">"Always use Wifi"</STRING>
	  <STRING id="STR_ID_VAPP_SYNC_REGULAR_WARNING_LEFT">"This can be only set for one account, '"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_REGULAR_WARNING_RIGHT">"' has selected it"</STRING>
		
		<STRING id="STR_ID_VAPP_SYNC_REGULAR_ONLY_ALLOC">"This can be only set for one account"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_REGULAR_HAS_SELECT">"has selected it"</STRING>
		/* PC Sync*/
		<STRING id="STR_ID_VAPP_SYNC_PC">"PC sync"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_INIT_PC_SYNC">"Initiate new PC sync"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_SYNCED_PCs">"Synced PC"</STRING>
		
		/* Phone Sync*/
		<STRING id="STR_ID_VAPP_SYNC_PHONE">"Phone sync"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_PHONE_NAME">"Phone name"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_INIT_PHONE_SYNC">"Initiate new phone sync"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_SYNCED_PHONES">"Synced phones"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_SYNC_ASK">"Accept sync request from "</STRING>
		<STRING id="STR_ID_VAPP_SYNC_CONN_ASK">"Accept connect request from "</STRING>
		<STRING id="STR_ID_VAPP_SYNC_CONN_ASK_RIGHT">"?"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_NO_PHONE">"No phone"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_PHONE_SETTINGS">"Sync settings"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_ACCEPT_ASK">"Sync settings"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_ACCEPT_ASK_RIGHT">"?"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_REMOTE_PHONE">"Remote phone"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_LOCAL_PHONE">"Local phone"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_PHONE_NAME_EXIST">"Phone name already exists"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_INVALID_PHONE_NAME">"Please input phone name"</STRING>
		
		/* Sync Error Code */
		<STRING id="STR_ID_VAPP_SYNC_ERROR_INVALID_SYNC">"Invalid sync"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_ERROR_INVALID_ACCNT">"Invalid accnt"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_ERROR_INVALID_DB">"Invalid database"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_ERROR_BUSY">"Busy"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_ERROR_NO_DB">"No database"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_PHB_BUSY">"Contacts is not ready"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_WAP_NOT_READY">"wap not ready"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_ERROR_INVALID_DATA_ACCOUNT">"Invalid data account"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_INVALID_CREDENTIAL">"Invalid credential"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_MISSING_CREDENTIAL">"Missing credential"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_LOCALDB_FULL">"Local db full"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_CANCELLED">"Cancelled"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_PAYMENT_REQUIRED">"Payment required"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_CODE_FORBIDDEN">"Code forbidden"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_INCOMPLETE_CMD">"Implete command"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_SVR_DEVICE_FULL">"Device full"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_SERVICE_UNAVAILABLE">"Server not available"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_DATASTORE_FAIL">"Datastore fail"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_SVR_FAIL">"Server fail"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_ERR_OCCUR">"Error Occur"</STRING>
		<STRING id="STR_ID_VAPP_SYNC_PROTOCOL_UNSUPPORT">"Protocal unsupport"</STRING>
		
        <THEME>
            <IMAGE id="IMG_ID_VAPP_SYNC" desc="Main menu sync icon">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\Sync.png"</IMAGE> 
        </THEME>
        
		<IMAGE id="IMG_ID_VAPP_STATUS_SYNC_ONGOING">RES_IMG_ROOT"\\\\StatusIcon\\\\sync.png"</IMAGE> 
		<IMAGE id="IMG_ID_VAPP_STATUS_SYNC_ERROR">RES_IMG_ROOT"\\\\NMGR_Icon\\\\icon_alert.png"</IMAGE> 
		/*<IMAGE id="IMG_ID_VAPP_STATUS_SYNC_ERROR">RES_IMG_ROOT"\\\\StatusIcon\\\\sync_error.png"</IMAGE> */
		<IMAGE id="IMG_ID_VAPP_SYNC_REMOTE">SYNC_PATH"\\\\TabIcon\\\\RemoteSync.png"</IMAGE> 
		<IMAGE id="IMG_ID_VAPP_SYNC_PHONE">SYNC_PATH"\\\\TabIcon\\\\PhoneSync.png"</IMAGE> 
		<IMAGE id="IMG_ID_VAPP_SYNC_NOW">SYNC_PATH"\\\\ToolbarIcon\\\\SyncNow.png"</IMAGE> 
		<IMAGE id="IMG_ID_VAPP_SYNC_VLOG">SYNC_PATH"\\\\ToolbarIcon\\\\SyncLlog.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_SYNC_NEXT">SYNC_PATH"\\\\ToolbarIcon\\\\Next.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_SYNC_INIT_PHONE">SYNC_PATH"\\\\ToolbarIcon\\\\SyncBT.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_SYNC_NMGR">RES_IMG_ROOT"\\\\NMGR_Icon\\\\icon_sync.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_SYNC_NMGR_REGULAR">RES_IMG_ROOT"\\\\NMGR_Icon\\\\icon_sync_regular.png"</IMAGE>
		
		<MENU id = "MENU_ID_SYNCML_MAIN"> </MENU>
    <MENU id = "MENU_ID_SYNCML_DEV_MAIN"> </MENU>

#ifdef __MMI_SYNCML_DEVICE_SYNC__
	<RECEIVER id="EVT_ID_SRV_SYNC_CM" proc="vapp_sync_phone_evt_handlr"/>
	<RECEIVER id="EVT_ID_SRV_SYNC_ASK_CONN" proc="vapp_sync_phone_evt_handlr"/>
	<RECEIVER id="EVT_ID_SRV_SYNC_ASK_SYNC" proc="vapp_sync_phone_evt_handlr"/>
#endif

	<RECEIVER id="EVT_ID_SRV_SYNC_OTA_IND" proc="vapp_sync_remote_evt_handlr"/>
	  <RECEIVER id="EVT_ID_SRV_SYNC_FINISH" proc="vapp_sync_on_notification"/>
	<RECEIVER id="EVT_ID_SRV_SYNC_ACCNT_OP" proc="vapp_sync_on_notification"/>	
	<RECEIVER id="EVT_ID_SRV_SYNC_ASK_SYNC" proc="vapp_sync_on_notification"/>

    <CACHEDATA type="byte" id="NVRAM_EF_VAPP_SYNC_LAST_TAB">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION>nvram last focus tab item</DESCRIPTION>
    </CACHEDATA>

</APP>

<APP id="VCUI_SYNC" name="VAPP_STR_SYNC_CUI" type="venus">
    <MEMORY base="250*1024"/>
</APP>

<APP id="VCUI_SYNC_PROV" name="VAPP_STR_SYNC_PROV_CUI" type="venus">
    <MEMORY base="250*1024"/>
</APP>

#endif /* SYNCML_SUPPORT */
