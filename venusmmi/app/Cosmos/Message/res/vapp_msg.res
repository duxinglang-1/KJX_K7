#include "mmi_features.h"
#include "custresdef.h"

#define xstr(s) str(s)
#define str(s) #s

#ifdef __MMI_VUI_SAVE_BOOKMARK_SUPPORT__
#define OPTION_VCUI_BKM VCUI_BKM
#else
#define OPTION_VCUI_BKM 0
#endif

#ifdef __MMI_SNS_MESSAGES__
#define OPTION_VCUI_SNS_MSG_COMPOSER VCUI_SNS_MSG_COMPOSER
#else
#define OPTION_VCUI_SNS_MSG_COMPOSER 0
#endif

#ifndef __MMI_MESSAGE_SLIM__
#define OPTION_VCUI_GALLERY_VIDEO_PLAYER VCUI_GALLERY_VIDEO_PLAYER
#else
#define OPTION_VCUI_GALLERY_VIDEO_PLAYER 0
#endif

#ifdef __MMI_UNIFIED_COMPOSER__
	#define OPTION_VCUI_COMPOSER VCUI_MSGCOMPOSER
#else
	#ifdef __MMI_SMS_COMPOSER__ 
		#define OPTION_VCUI_COMPOSER VCUI_SMS_COMPOSER
	#else
		#define OPTION_VCUI_COMPOSER 0
	#endif
#endif

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_MSG_INBOX"
    package_name="native.mtk.msg.inbox"
    name="STR_ID_VAPP_MSG_INBOX"
    img="IMG_ID_VAPP_MSG_MAIN_INBOX"
    launch="vapp_msg_launch_inbox"
    hidden_in_mainmenu = "true"
    type="venus">
    
    <STRING id="STR_ID_VAPP_MSG_INBOX"/>
    <THEME>
        <IMAGE id="IMG_ID_VAPP_MSG_MAIN_INBOX" desc = "Main menu message icon">RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\Message.png"</IMAGE>
    </THEME>
</APP>

<APP id="VAPP_MSG" 
    package_name="native.mtk.msg" 
    name="STR_ID_VAPP_MSG"
    img="IMG_ID_VAPP_MSG_MAIN" 
    launch="vapp_msg_launch" 
    package_proc="vapp_msg_package_proc"
    type="venus">
    <!-- 
    ***************************************************************
    Memory Area
    ***************************************************************
    -->

    <MEMORY heap="MSG_HEAP_SIZE + total(VAPP_MMS_HEAP) + total(VAPP_SMS_HEAP) + total(VAPP_WAP_PUSH_HEAP) + total(VAPP_PROV_HEAP)" extra_base="total(VAPP_MMS_EXTRA_BASE) + total(VAPP_SMS_EXTRA_BASE) + total(VAPP_WAP_PUSH_EXTRA_BASE) + total(VAPP_PROV_EXTRA_BASE)" \
                            fg="total(VAPP_MMS_FG) + total(VAPP_PROV_FG) + total(VAPP_WAP_PUSH_FG) + total(VAPP_SMS_FG)" \
                            cui=xstr(max(VCUI_CONTACT_SAVE \
                                        , OPTION_VCUI_BKM \
                                        , VCUI_DIALER_MAKE_CALL \
                                        , OPTION_VCUI_COMPOSER \
                                        , VCUI_GALLERY_IMAGE_VIEWER \
                                        , OPTION_VCUI_GALLERY_VIDEO_PLAYER \
                                        , VCUI_MUSIC_PLAYER \
                                        , VCUI_DTCNT \
                                        , VCUI_MMS \
                                        , VAPP_CCA \
                                        , OPTION_VCUI_SNS_MSG_COMPOSER \
                                        , VAPP_MMS_CUI_SRV \
                                        ))\  
                            vrt_mem_factor = "1.0"
                            inc="vapp_msg_res_gprot.h"
                               />
    <APPCONCURRENT concurrent_w_order ="VAPP_MSG, VAPP_DLAGENT"/>
#ifdef __MMI_SNS_MESSAGES__
    <APPCONCURRENT concurrent ="VAPP_MSG, VAPP_SNS_PLUGIN"/>
#endif

    <!-- 
 
    ***************************************************************
    Layout Area
    ***************************************************************
    -->
    <LAYOUT file="vapp_msg.xml" />

    <!-- 
    ***************************************************************
    STRING Area
    ***************************************************************
    -->
    <STRING id="STR_ID_VAPP_MSG"/>
    <STRING id="STR_ID_VAPP_MSG_NEW_MSG"/>
    <STRING id="STR_ID_VAPP_MSG_SENTBOX"/>
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ 
    <STRING id="STR_ID_VAPP_MSG_ARCHIVE"/>
#endif
    <STRING id="STR_ID_VAPP_MSG_SIM_MSG"/>
    <STRING id="STR_ID_VAPP_MSG_SETTING"/>
    <STRING id="STR_ID_VAPP_MSG_VIEW_MSG_IN"/>
    <STRING id="STR_ID_VAPP_MSG_SIM1_MSG"/>
#if (MMI_MAX_SIM_NUM >= 2)
    <STRING id="STR_ID_VAPP_MSG_SIM2_MSG"/>
#endif /* MMI_MAX_SIM_NUM >= 2 */
#if (MMI_MAX_SIM_NUM >= 3)
    <STRING id="STR_ID_VAPP_MSG_SIM3_MSG"/>
#endif /* MMI_MAX_SIM_NUM >= 3 */
#if (MMI_MAX_SIM_NUM >= 4)
    <STRING id="STR_ID_VAPP_MSG_SIM4_MSG"/>
#endif /* MMI_MAX_SIM_NUM >= 4 */
    <STRING id="STR_ID_VAPP_MSG_DELETE_MSG"/>
    <STRING id="STR_ID_VAPP_MSG_DELETE_CS_MSG"/>
    <STRING id="STR_ID_VAPP_MSG_COPY_TO"/>
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ 
    <STRING id="STR_ID_VAPP_MSG_COPY_TO_ARCHIVE"/>
#endif
    <STRING id="STR_ID_VAPP_MSG_COPY_SMS_TO_SIM"/>
    <STRING id="STR_ID_VAPP_MSG_COPY_SMS_TO_SIM1"/>
#if (MMI_MAX_SIM_NUM >= 2)
    <STRING id="STR_ID_VAPP_MSG_COPY_SMS_TO_SIM2"/>
#endif /* MMI_MAX_SIM_NUM >= 2  */
#if (MMI_MAX_SIM_NUM >= 3)
    <STRING id="STR_ID_VAPP_MSG_COPY_SMS_TO_SIM3"/>
#endif /* MMI_MAX_SIM_NUM >= 3  */
#if (MMI_MAX_SIM_NUM >= 4)
    <STRING id="STR_ID_VAPP_MSG_COPY_SMS_TO_SIM4"/>
#endif /* MMI_MAX_SIM_NUM >= 4  */
#ifdef __MMI_MMS_IN_UM__
    <STRING id="STR_ID_VAPP_MSG_COPY_MMS_TO_PHONE"/>
    <STRING id="STR_ID_VAPP_MSG_COPY_MMS_TO_MEMORY_CARD"/>
#endif
    <STRING id="STR_ID_VAPP_MSG_MSG_OPTION"/>
#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
    <STRING id="STR_ID_VAPP_MSG_SORT_MSG_BY"/>
    <STRING id="STR_ID_VAPP_MSG_SORT_MSG_BY_TYPE"/>
    <STRING id="STR_ID_VAPP_MSG_SORT_MSG_BY_READ_STATUS"/>
    <STRING id="STR_ID_VAPP_MSG_SORT_MSG_BY_RECIPIENT"/>
    <STRING id="STR_ID_VAPP_MSG_SORT_MSG_BY_SENDER"/>
    <STRING id="STR_ID_VAPP_MSG_SORT_MSG_BY_TIME"/>
#endif
    <STRING id="STR_ID_VAPP_MSG_ASK_DELETE_COFIRM"/>
    <STRING id="STR_ID_VAPP_MSG_ASK_DELETE_CS_COFIRM"/>
    <STRING id="STR_ID_VAPP_MSG_PUSH_MSG"/>
    <STRING id="STR_ID_VAPP_MSG_CB_MSG"/> 
#ifdef __SMS_CLOUD_SUPPORT__
    <STRING id="STR_ID_VAPP_MSG_BACKUP_CLOUD"/>
    <STRING id="STR_ID_VAPP_MSG_RESTORE_CLOUD"/> 
    <STRING id="STR_ID_VAPP_MSG_BACKUP_FAIL"/>
    <STRING id="STR_ID_VAPP_MSG_RESTORE_FAIL"/> 
    <STRING id="STR_ID_VAPP_MSG_NO_MESSAGE_TO_BACKUP"/>   
    <STRING id="STR_ID_VAPP_MSG_NO_MESSAGE_TO_RESTORE"/>  
    <STRING id="STR_ID_VAPP_MSG_NO_NETWORK"/>  
    <STRING id="STR_ID_VAPP_MSG_LOGIN_FAIL"/> 
#endif /* __SMS_CLOUD_SUPPORT__ */
    <STRING id="STR_ID_VAPP_MSG_CONVERSATION_MODE"/>
    <STRING id="STR_ID_VAPP_MSG_VIEW_WEBSITE"/>
    <STRING id="STR_ID_VAPP_MSG_FAIL_TO_DELETE"/>
    <STRING id="STR_ID_VAPP_MSG_FAIL_TO_COPY"/>
    <STRING id="STR_ID_VAPP_MSG_NCENTER_UNREAD_MSG"/>
    <STRING id="STR_ID_VAPP_MSG_NCENTER_UNSENT_MSG"/>
    <STRING id="STR_ID_VAPP_MSG_UNREAD_MSG"/>
    <STRING id="STR_ID_VAPP_MSG_UNREAD_MSGS"/>
    <STRING id="STR_ID_VAPP_MSG_MSG"/>
    <STRING id="STR_ID_VAPP_MSG_MSGS"/>
    <STRING id="STR_ID_VAPP_MSG_NMGR_NEW_MESSAGE_PREFIX"/>
    <STRING id="STR_ID_VAPP_MSG_NMGR_SEND_FAIL_PREFIX"/>
    <STRING id="STR_ID_VAPP_MSG_NO_SUBJECT"/>
    <STRING id="STR_ID_VAPP_MSG_NO_CONTENT"/>
    <STRING id="STR_ID_VAPP_MSG_NOT_READY"/>
    <STRING id="STR_ID_VAPP_MSG_NOT_READY_AND_CLOSE_APP"/>
    <STRING id="STR_ID_VAPP_MSG_NO_MESSAGES"/>
    <STRING id="STR_ID_VAPP_MSG_RESEND_FAIL"/>
    <STRING id="STR_ID_VAPP_MSG_SWITCH_NUMBER"/>
#if (MMI_MAX_SIM_NUM >= 2)
    <STRING id="STR_ID_VAPP_MSG_SWITCH_SIM"/>
#endif /* MMI_MAX_SIM_NUM >= 2 */
    <STRING id="STR_ID_VAPP_MSG_SWITCH_TO"/>
    <STRING id="STR_ID_VAPP_MSG_CLEAR_ALL_MSGS"/>
    <STRING id="STR_ID_VAPP_MSG_CLEARING"/>
    <STRING id="STR_ID_VAPP_MSG_FAIL_TO_CLEAR"/>
    <STRING id="STR_ID_VAPP_MSG_SELECT_NUMBER"/>
#if (MMI_MAX_SIM_NUM >= 2)
    <STRING id="STR_ID_VAPP_MSG_SELECT_SIM"/>
#endif /* MMI_MAX_SIM_NUM >= 2 */
    <STRING id="STR_ID_VAPP_MSG_MS_DELETE_SELECT_PREFIX"/>
    <STRING id="STR_ID_VAPP_MSG_MS_DELETE_SELECT_POSTFIX"/>
    <STRING id="STR_ID_VAPP_MSG_MS_DELETE_CS_SELECT_PREFIX"/>
    <STRING id="STR_ID_VAPP_MSG_MS_DELETE_CS_SELECT_POSTFIX"/>
    <STRING id="STR_ID_VAPP_MSG_INSUFFICIENT_MEMORY"/>
    <STRING id="STR_ID_VAPP_MSG_INVALID_RECIPIENT"/>
    <STRING id="STR_ID_VAPP_MSG_MAX_MMS_NUM_REACH"/>
    <STRING id="STR_ID_VAPP_MSG_INSERT"/>
    <STRING id="STR_ID_VAPP_MSG_DRM_MMS_CANNOT_EDIT"/>
    <STRING id="STR_ID_VAPP_MSG_ASK_DELETE_TEMPLATE_CONFIRM"/>
    <STRING id="STR_ID_VAPP_MSG_MS_DELETE_TEMPLATE_PREFIX"/>
    <STRING id="STR_ID_VAPP_MSG_MS_DELETE_TEMPLATE_POSTFIX"/>
#ifdef __MMI_UM_TEMPLATE_SUPPORT__
    <STRING id="STR_ID_VAPP_MSG_TEMPLATE"/>
#endif
    <STRING id="STR_ID_VAPP_MSG_SIM_CARD_UNAVAILABLE_TRANSFER_TO"/>
    <STRING id="STR_ID_VAPP_MSG_SIM_SMS_FULL"/>
#if (MMI_MAX_SIM_NUM >= 2)
    <STRING id="STR_ID_VAPP_MSG_SIM1_SMS_FULL"/>
    <STRING id="STR_ID_VAPP_MSG_SIM2_SMS_FULL"/>
#endif /* MMI_MAX_SIM_NUM >= 2 */
#if (MMI_MAX_SIM_NUM >= 3)
    <STRING id="STR_ID_VAPP_MSG_SIM3_SMS_FULL"/>
#endif /* MMI_MAX_SIM_NUM >= 3 */
#if (MMI_MAX_SIM_NUM >= 4)
    <STRING id="STR_ID_VAPP_MSG_SIM4_SMS_FULL"/>
#endif /* MMI_MAX_SIM_NUM >= 4 */
    <STRING id="STR_ID_VAPP_MSG_PHONE_SMS_FULL"/>
    <STRING id="STR_ID_VAPP_MSG_SMS_REACH"/>
    <STRING id="STR_ID_VAPP_MSG_PHONE_MMS_FULL"/>
    <STRING id="STR_ID_VAPP_MSG_CARD_MMS_FULL"/>
    <STRING id="STR_ID_VAPP_MSG_MMS_REACH"/>
    <STRING id="STR_ID_VAPP_MSG_PROV_FULL"/>
    <STRING id="STR_ID_VAPP_MSG_PROV_REACH"/>
    <STRING id="STR_ID_VAPP_MSG_NSS_VIEW"/>
#ifdef __MMI_SNS_MESSAGES__
    <STRING id="STR_ID_VAPP_MSG_LOCAL"/>
    <STRING id="STR_ID_VAPP_MSG_SNS"/>
#endif /* __MMI_SNS_MESSAGES__ */

    <STRING id ="STR_ID_VAPP_MSG_COPY_TO_INBOX"/>
    <STRING id ="STR_ID_VAPP_MSG_COPY_SMS_TO_PHONE"/>
    <STRING id ="STR_ID_VAPP_MSG_COPY_SMS_TO_MEMORY_CARD"/>
    <STRING id ="STR_ID_VAPP_MSG_COPY_TO_MEMORY_CARD"/>
#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
    <STRING id ="STR_ID_VAPP_MSG_SMS_MEMORY_CARD_FULL"/>
#endif
    <STRING id ="STR_ID_VAPP_MSG_MEMORY_CARD_FULL_SAVE_TO_PHONE"/>
    <STRING id ="STR_ID_VAPP_MSG_PHONE_FULL_SAVE_TO_MEMORY_CARD"/>
    <!-- 
    ***************************************************************
    IMAGE Area
    ***************************************************************
    -->
    <THEME>
        <IMAGE id="IMG_ID_VAPP_MSG_DIALOG_BUBBLE_LEFT"              desc = "The left bubble normal mode in the dialog list"/>
        <IMAGE id="IMG_ID_VAPP_MSG_DIALOG_BUBBLE_LEFT_DISABLED"     desc = "The left bubble disable mode in the dialog list"/>
        <IMAGE id="IMG_ID_VAPP_MSG_DIALOG_BUBBLE_RIGHT"             desc = "The right bubble normal mode in the dialog list"/>
        <IMAGE id="IMG_ID_VAPP_MSG_DIALOG_BUBBLE_RIGHT_DISABLED"    desc = "The right bubble disable mode in the dialog list"/>
        <IMAGE id="IMG_ID_VAPP_MSG_DIALOG_BUBBLE_HIGHLIGHT"         desc = "The bubble highlight effect image in the dialog list"/>
        <IMAGE id="IMG_ID_VAPP_MSG_DIALOG_ARROW_LEFT"               desc = "The left bubble arrow normal mode in the dialog list"/>
        <IMAGE id="IMG_ID_VAPP_MSG_DIALOG_ARROW_LEFT_HIGHLIGHT"     desc = "The left bubble arrow highlight mode in the dialog list"/>
        <IMAGE id="IMG_ID_VAPP_MSG_DIALOG_ARROW_LEFT_DISABLED"      desc = "The left bubble arrow disable mode in the dialog list"/>
        <IMAGE id="IMG_ID_VAPP_MSG_DIALOG_ARROW_RIGHT"              desc = "The right bubble arrow normal mode in the dialog list"/>
        <IMAGE id="IMG_ID_VAPP_MSG_DIALOG_ARROW_RIGHT_HIGHLIGHT"    desc = "The right bubble arrow highlight mode in the dialog list"/>
        <IMAGE id="IMG_ID_VAPP_MSG_DIALOG_ARROW_RIGHT_DISABLED"     desc = "The right bubble arrow diable mode in the dialog list"/>
        <IMAGE id="IMG_ID_VAPP_MSG_DIALOG_EDITOR_BG"                desc = "The editor background in the dialog list"/>
        <IMAGE id="IMG_ID_VAPP_MSG_DIALOG_LIST_BG"                  desc = "The dialog list background"/>
        <COLOR id="CLR_ID_VAPP_MSG_DIALOG_CELL_TIME_LEFT"           desc = "The left bubble time color of dialog list"/>
        <COLOR id="CLR_ID_VAPP_MSG_DIALOG_CELL_TIME_RIGHT"          desc = "The right bubble time color of dialog list"/>

        <COLOR id="CLR_ID_VAPP_MSG_DIALOG_CELL_TIME_SHADOW"         desc = "The bubble time shadow color of dialog list"/>
        <COLOR id="CLR_ID_VAPP_MSG_PHB_DIALOG_CB_NAME"              desc = "The name color of dialog list contact bar in the contact app"/>
        <COLOR id="CLR_ID_VAPP_MSG_PHB_DIALOG_CB_NUMBER"            desc = "The number color of dialog list contact bar in the contact app"/>
        <IMAGE id="IMG_ID_VAPP_MSG_CONTACT_DIALOG_BAR_BG"           desc = "The contact bar background of dialog list contact bar in the contact app"/>
        <IMAGE id="IMG_ID_VAPP_MSG_PHB_DIALOG_LIST_BG"              desc = "The background of dialog list in the contact app"/>
        <COLOR id="CLR_ID_VAPP_MSG_UNREAD_MSG"                      desc = "The unread message color and shows on folder list"/>
        <IMAGE id="IMG_ID_VAPP_MSG_MAIN" desc = "Main menu message icon">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\Message.png"</IMAGE>
    </THEME>

#ifdef __MMI_UM_BOX_LIST_SUPPORT__
    <IMAGE id="IMG_ID_VAPP_MSG_INBOX">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Inbox.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MSG_DRAFTS">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Drafts.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MSG_SENTBOX">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Sendbox.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MSG_OUTBOX">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Outbox.png"</IMAGE>
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    <IMAGE id="IMG_ID_VAPP_MSG_ARCHIVE">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Archive.png"</IMAGE>
#endif 
#endif 
    <IMAGE id="IMG_ID_VAPP_MSG_TB_NEW_MSG">RES_IMG_ROOT"\\\\Message\\\\ToolBarIcon\\\\NEW_MSG.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MSG_TB_SIM_MSG">RES_IMG_ROOT"\\\\Message\\\\ToolBarIcon\\\\SIM_MSG.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MSG_TB_CALL">RES_IMG_ROOT"\\\\Message\\\\ToolBarIcon\\\\Call.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MSG_TB_COPY_TO_PHONE">RES_IMG_ROOT"\\\\Message\\\\ToolBarIcon\\\\Copy_To_Phone.png"</IMAGE>
#ifdef __MMI_UM_TEMPLATE_SUPPORT__
    <IMAGE id="IMG_ID_VAPP_MSG_TAB_SMS">RES_IMG_ROOT"\\\\Contact\\\\TabIcon\\\\Message.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MSG_TAB_MMS">RES_IMG_ROOT"\\\\Message\\\\TabIcon\\\\MMS.png"</IMAGE>
#endif
    <IMAGE id="IMG_ID_VAPP_MSG_NCENTER_UNREAD">RES_IMG_ROOT"\\\\NMGR_Icon\\\\icon_msg_unread.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MSG_NCENTER_UNSENT">RES_IMG_ROOT"\\\\NMGR_Icon\\\\icon_msg_unsent_msg.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MSG_NCENTER_MEMORY_FULL">RES_IMG_ROOT"\\\\NMGR_Icon\\\\icon_msg_full.png"</IMAGE>
#ifdef __MMI_SNS_MESSAGES__
    <IMAGE id="IMG_ID_VAPP_MSG_TAB_LOCAL">RES_IMG_ROOT"\\\\SNS\\\\Tabicon\\\\Local.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MSG_TAB_SNS">RES_IMG_ROOT"\\\\SNS\\\\Tabicon\\\\SNS.png"</IMAGE>
#endif /* __MMI_SNS_MESSAGES__ */

    <CACHEDATA type="byte" id="NVRAM_VAPP_MESSAGE_CS_SETTING" restore_flag="TRUE">
    #ifdef __MMI_UM_CONVERSATION_BOX__
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
    #else
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        <DESCRIPTION> FTO message conversation box setting on / off </DESCRIPTION>
    </CACHEDATA>
    <CACHEDATA type="byte" id="NVRAM_VAPP_MSG_NCENTER_UNREAD_MSG" restore_flag="FALSE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> FTO unread message setting. if end user clear the notification, it will not show after re-boot </DESCRIPTION>
    </CACHEDATA>
    <CACHEDATA type="byte" id="NVRAM_VAPP_MSG_NCENTER_OUTBOX_MSG" restore_flag="FALSE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> FTO unsent message setting. if end user clear the notification, it will not show after re-boot </DESCRIPTION>
    </CACHEDATA>
    <CACHEDATA type="byte" id="NVRAM_VAPP_MSG_NCENTER_MEMORY_FULL_PREVIOUS_EVT" restore_flag="FALSE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> FTO message memory full event record. This record will remember the previous event that sent from service. </DESCRIPTION>
    </CACHEDATA>
    <CACHEDATA type="byte" id="NVRAM_VAPP_MSG_NCENTER_MEMORY_FULL" restore_flag="FALSE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> FTO message memory full setting. if end user clear the notification, it will not show after re-boot </DESCRIPTION>
    </CACHEDATA>

    <EVENT id="EVT_ID_VAPP_MSG_ENTRY" type="SENDER"/>
    <RECEIVER id="EVT_ID_SRV_UM_NOTIFY_READY" proc="vapp_msg_event_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_UM_NOTIFY_REFRESH" proc="vapp_msg_event_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_UM_NOTIFY_READY" proc="vapp_msg_event_ncenter_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_UM_NOTIFY_REFRESH" proc="vapp_msg_event_ncenter_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SMS_UPDATE_UNSENT_MSG_STATUS" proc="vapp_msg_event_ncenter_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_MMS_UPDATE_STATUS" proc="vapp_msg_event_ncenter_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SMS_MEM_FULL" proc="vapp_msg_event_ncenter_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SMS_MEM_AVAILABLE" proc="vapp_msg_event_ncenter_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_MMS_MEM_FULL" proc="vapp_msg_event_ncenter_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_PROVBOX_EVT_IND" proc="vapp_msg_event_ncenter_hdlr"/>
    <RECEIVER id="EVT_ID_VAPP_MSG_ENTRY" proc="vapp_msg_enter_hdlr"/>    
</APP>
