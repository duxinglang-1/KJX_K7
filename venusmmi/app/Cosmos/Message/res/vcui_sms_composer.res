#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

#define SMS_COMPOSER_HEAP_MEM_CONFIG         "200*1024"
#define SMS_COMPOSER_EXTRA_BASE_MEM_CONFIG   "50*1024"
#define SMS_COMPOSER_CUI_MEM_CONFIG          "max(VCUI_CONTACT_LIST)"

#ifndef __MMI_SMS_COMPOSER__

<APP id="VAPP_SMS_COMPOSER"></APP>
<APP id="VCUI_SMS_COMPOSER"></APP>

#else

<APP id="VAPP_SMS_COMPOSER" name="STR_ID_VAPP_SMS_COMPOSER" type="venus">
	<MEMORY heap=SMS_COMPOSER_HEAP_MEM_CONFIG extra_base=SMS_COMPOSER_EXTRA_BASE_MEM_CONFIG cui=SMS_COMPOSER_CUI_MEM_CONFIG/> 
	<STRING id="STR_ID_VAPP_SMS_COMPOSER"/>
</APP>

<APP id="VCUI_SMS_COMPOSER" name="STR_ID_VCUI_SMS_COMPOSER" type="venus">
	<MEMORY heap=SMS_COMPOSER_HEAP_MEM_CONFIG extra_base=SMS_COMPOSER_EXTRA_BASE_MEM_CONFIG cui=SMS_COMPOSER_CUI_MEM_CONFIG/> 

<!-- 
**************************************** String Id ****************************************
-->
	<STRING id="STR_ID_VCUI_SMS_COMPOSER"/>
		
	<STRING id="STR_ID_VCUI_SMSC_INSERT_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_NUMBER_LENGTH_EXCEED_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_RECIPIENT_NUMBER_EXCEED_ID"/>
  <STRING id="STR_ID_VCUI_SMSC_FLIGHT_MODE"/>
	<STRING id="STR_ID_VCUI_SMSC_ADD_RECIPIENT"/>
	<STRING id="STR_ID_VCUI_SMSC_INSERT_PHB_NUMBER_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_INSERT_PHB_NAME_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_TXT_EDITOR_HINT_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_SWITCH_SIM_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_SAVE_AS_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_TO_AS_HINT"/>
	<STRING id="STR_ID_VCUI_SMSC_UNNAMED"/>	
	<STRING id="STR_ID_VCUI_SMSC_INVALID_RECIPIENTS_REMOVED"/>
	<STRING id="STR_ID_VCUI_SMSC_INVALID_RECIPIENT"/>
	<STRING id="STR_ID_VCUI_SMSC_SWITCHED_TO"/>
	<STRING id="STR_ID_VCUI_SMSC_WRITE_MSG_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_CONTINUE"/>	
	<STRING id="STR_ID_VCUI_SMSC_BLOCKED_SIM1_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_BLOCKED_SIM2_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_BLOCKED_SIM3_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_BLOCKED_SIM4_ID"/>	
	<STRING id="STR_ID_VCUI_SMSC_UNAVAILABLE_TRFR_TO_ID"/>	
	<STRING id="STR_ID_VCUI_SMSC_NUM_CANNOT_BE_EMPTY_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_PLS_ADD_RECIPIENT_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_MSG_SIZE_EXCEED_ID"/>	

<!-- 
**************************************** Image section ****************************************
-->

	/* For Sms composer UI */
	<IMAGE id="IMG_ID_VCUI_SMSC_INSERT_ID" >RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Insert.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_SEND_ID">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Send.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_SAVE_AS_ID">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Save.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_SWITCH_SIM_ID">RES_IMG_ROOT"\\\\Message\\\\ToolBarIcon\\\\Switch_SIM.png"</IMAGE>

	/* For vcp_contact_select.cpp*/
	<IMAGE id="IMG_ID_VCUI_SMSC_CONTACT_BTN_BG_HLT">CUST_IMG_PATH_ROOT"\\\\\MainLCD\\\\Default\\\\Message\\\\ContactSelector\\\\BTN_H.9slice.png"</IMAGE>
  <IMAGE id="IMG_ID_VCUI_SMSC_CONTACT_BTN_BG_NRL">CUST_IMG_PATH_ROOT"\\\\\MainLCD\\\\Default\\\\Message\\\\ContactSelector\\\\BTN_N.9slice.png"</IMAGE>
  <IMAGE id="IMG_ID_VCUI_SMSC_CONTACT_BTN_DELETE">CUST_IMG_PATH_ROOT"\\\\\MainLCD\\\\Default\\\\Message\\\\ContactSelector\\\\Delete.png"</IMAGE>
  <IMAGE id="IMG_ID_VCUI_SMSC_BTN_DELETE">CUST_IMG_PATH_ROOT"\\\\\MainLCD\\\\Default\\\\Common\\\\Button\\\\Delete.png"</IMAGE>
  
  <THEME>			
  <IMAGE id="IMG_ID_VCUI_SMSC_CONTACT_ICON" desc="Botton contact shortcut"/>
  <COLOR id="CLR_ID_VCUI_SMSC_CONTACT_TEXT_FRAME" desc = "The contact text frame color"/>
  </THEME>	 
  
<!-- 
**************************************** Callback Manager Receiver ****************************************
-->

  <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="vcuiSmsComposerSimStatusInfoHdlr"/>
  <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="vcuiSmsComposerSimStatusInfoHdlr"/>

<!-- 
**************************************** Cache resource ****************************************
-->	

	<CACHEDATA type="byte" id="NVRAM_VCUI_SMS_COMPOSER_PREFER_SIM" restore_flag="TRUE">
	<DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
	<DESCRIPTION> Byte Cache </DESCRIPTION>
	</CACHEDATA>
								
</APP>

#endif /* __MMI_SMS_COMPOSER__ */

















#if 0
<!-- 
**************************************** Backup ****************************************
-->	 
       
  /* APP id */
	<APP id="VCUI_MMS_SRV"></APP>
	<APP id="VCUI_EMAILCOMPOSER"></APP>
	<APP id="VCUI_SMSONLYCOMPOSER"></APP>
	<APP id="VCUI_LEMEICOMPOSER"></APP>

	/* string */
	<STRING id="STR_ID_VCUI_SMSC_NO_IMAGE"/>
	<STRING id="STR_ID_VCUI_SMSC_AUDIO_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_TEXT_TEMPLATE_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_ATTACHMENT_LIST_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_INSERT_NEW_SLIDE_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_DELETE_SLIDE_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_TO_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_CC_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_BCC_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_TO_OPTION_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_RESTRICTED_MODE_MSG_SIZE_EXCEED_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_SIZE_NOT_ENOUGH_FOR_REC_VIDEO_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_ADDR_LENGTH_EXCEED_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_PROHIBIT_BY_CREATION_MODE_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_NO_SPACE_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_DISCARD_EDITED_MSG_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_INSERTING"/>
	<STRING id="STR_ID_VCUI_SMSC_IMAGE"/>
	<STRING id="STR_ID_VCUI_SMSC_VIDEO"/>	
	<STRING id="STR_ID_VCUI_SMSC_AUDIO"/>	
	<STRING id="STR_ID_VCUI_SMSC_ATTACHMENT"/>	
	<STRING id="STR_ID_VCUI_SMSC_VCARD"/>	
	<STRING id="STR_ID_VCUI_SMSC_VCALENDAR"/>	
	<STRING id="STR_ID_VCUI_SMSC_VEVENT"/>	
	<STRING id="STR_ID_VCUI_SMSC_VTASK"/>	
	<STRING id="STR_ID_VCUI_SMSC_TEXT"/>	
	<STRING id="STR_ID_VCUI_SMSC_SLIDE"/>
	<STRING id="STR_ID_VCUI_SMSC_SLIDES_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_CCBCC"/>	
	<STRING id="STR_ID_VCUI_SMSC_ADD_CC"/>	
	<STRING id="STR_ID_VCUI_SMSC_REMOVE_CC"/>											
	<STRING id="STR_ID_VCUI_SMSC_ADD_BCC"/>	
	<STRING id="STR_ID_VCUI_SMSC_REMOVE_BCC"/>	
	<STRING id="STR_ID_VCUI_SMSC_STORAGE_FULL_DELETE_FILE_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_MAX_TEMPLATE_ALREADY_PRESENT_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_STORAGE_FILE_IO_ERROR_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_STORAGE_FULL_MSG_CONTENT_LOSS_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_NO_RECIPIENT_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_ABORT_FAIL_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_ABORTED_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_SEND_SUCCESS_SAVE_SUCCESS"/>
	<STRING id="STR_ID_VCUI_SMSC_SEND_SUCCESS_SAVE_FAIL"/>
	<STRING id="STR_ID_VCUI_SMSC_SEND_FAIL_SAVE_SUCCESS"/>
	<STRING id="STR_ID_VCUI_SMSC_SEND_FAIL_SAVE_FAIL"/>
	<STRING id="STR_ID_VCUI_SMSC_CONTENT_ERROR_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_CAN_NOT_PLAY_COMPLETE"/>
	<STRING id="STR_ID_VCUI_SMSC_UNSUPPORT_CONTENT_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_NO_ENOUGH_WORKING_SPACE_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_CREATION_MODE_MAX_MSG_SIZE_REACHED_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_MAX_SLIDE_NUM_REACHED_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_TOO_MANY_MSG_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_SEND_FAIL_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_SEND_FAIL_NO_BOX_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_SYSTEM_RESOURCES_EXHAUSTED_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_FILE_CORRUPT_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_FAILED_TO_ADD_MEDIA_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_FAILED_TO_ADD_ATTACHMENT_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_FILE_EMPTY_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_FILE"/>
	<STRING id="STR_ID_VCUI_SMSC_RE_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_FW_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_FAIL_TO_RESIZE_IMAGE_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_EXCEED_SLIDE_TIME_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_SAVE_AS_TEMPLATE_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_NUMBER_LENGTH_TOO_SHORT_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_LESS_THAN_MEDIA_TIME_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_INTERVAL_PREFIX_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_INTERVAL_INFIX_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_SERVER_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_KB_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_RESIZE_IMAGE_UNCHANGED_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_WARNING_MODE_CONFIRM"/>
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
	<STRING id="STR_ID_VCUI_SMSC_INSERT_CARD"/>
	<STRING id="STR_ID_VCUI_SMSC_CARD_NOT_PRESENT_CONFIRM"/>
	<STRING id="STR_ID_VCUI_SMSC_MAX_MSG_CARD_CONFIRM"/>
	<STRING id="STR_ID_VCUI_SMSC_MAX_MSG_PHONE_CONFIRM"/>
#endif
	<STRING id="STR_ID_VCUI_SMSC_DELETE_ASK_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_DELETE_ALL_ASK_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_CONN_TYPE_MAX_SIZE_REACHED_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_SEND_FRM_SIM1"/>
	<STRING id="STR_ID_VCUI_SMSC_SEND_FRM_SIM2"/>

	<STRING id="STR_ID_VCUI_SMSC_SIM1_TO_SIM2"/>
	<STRING id="STR_ID_VCUI_SMSC_SIM2_TO_SIM1"/>
	<STRING id="STR_ID_VCUI_SMSC_SEND_TO_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_INSERT_VCARD"/>
	<STRING id="STR_ID_VCUI_SMSC_ADD_SUBJECT_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_REMOVE_SUBJECT_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_ENTER_RECIPIENT_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_ADD_FROM_CONTACTS_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_EDIT_RECIPIENT_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_REMOVE_RECIPIENT_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_REMOVE_ALL_RECIPIENTS_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_SAVE_TO_DRAFT_ID"/>
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
	<STRING id="STR_ID_VCUI_SMSC_REMOVE_EMS_OBJECT_CONFIRM"/>
	<STRING id="STR_ID_VCUI_SMSC_CORRUPT_MSG_DELETE_CONFIRM"/>
#endif
	<STRING id="STR_ID_VCUI_SMSC_WRITE_MSG_SUBJECT_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_REMOVE_PICTURE_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_REMOVE_AUDIO_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_VIDEO_OPTIONS_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_REMOVE_VIDEO_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_ATTACHMENT_OPTIONS_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_REMOVE_ATTACHMENT_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_ADD_MY_PICTURES_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_ADD_MY_SOUNDS_ID"/>
#ifndef __MMI_COSMOS_UC_VIDEO_SLIM_SUPPORT__	
	<STRING id="STR_ID_VCUI_SMSC_ADD_MY_VIDEOS_ID"/>
#else	
	<STRING id="STR_ID_VCUI_SMSC_ADD_VIDEOS_FROM_FMGR_ID"/>
#endif
	<STRING id="STR_ID_VCUI_SMSC_TAKE_PICTURE_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_RECORD_SOUND_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_RECORD_VIDEO_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_ADD_PICTURE_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_ADD_SOUND_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_ADD_VIDEO_ID"/>
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
	<STRING id="STR_ID_VCUI_SMSC_SWITCHED_TO_SMS_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_SWITCHED_TO_MMS_ID"/>
#endif
	<STRING id="STR_ID_VCUI_SMSC_PREVIEW_MMS_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_ADD_NEW_SLIDE_AFTER_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_ADD_NEW_SLIDE_BEFORE_ID"/>
#if defined(__MMI_MESSAGES_TEMPLATE__)
	<STRING id="STR_ID_VCUI_SMSC_INSERT_TEXT_TEMPLATE_ID"/>
#endif
	<STRING id="STR_ID_VCUI_SMSC_INSERT_ATTACHMENT_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_INSERT_BOOKMARK_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_TRUNCATE_NUMBER_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_MSG_CLASS_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_IMAGE_TOO_LARGE"/>
	<STRING id="STR_ID_VCUI_SMSC_SOME_OBJECT_WITHDREW"/>
	<STRING id="STR_ID_VCUI_SMSC_REMOVED_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_ADD_OBJECT_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_ADD_CONTACT_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_MULTIMEDIA"/>
#ifdef OMA13_CON_739_SUPPORT_TEMP_TEST_CODE
	<STRING id="STR_ID_VCUI_SMSC_PERSONAL"/>
	<STRING id="STR_ID_VCUI_SMSC_ADVERTISEMENT"/>
	<STRING id="STR_ID_VCUI_SMSC_INFORMATIONAL"/>
	<STRING id="STR_ID_VCUI_SMSC_AUTO"/>
#endif /* OMA13_CON_739_SUPPORT_TEMP_TEST_CODE */
	<STRING id="STR_ID_VCUI_SMSC_FAILURE_TEXT_CONTENT_EMPTY"/>
	<STRING id="STR_ID_VCUI_SMSC_FAILURE_TEXT_CONTENT_EXCEED"/>
	<STRING id="STR_ID_VCUI_SMSC_TXT_EDITOR_SUBJECT_HINT_ID"/> 
	<STRING id="STR_ID_VCUI_SMSC_ADD_SLIDE_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_REMOVE_SLIDE_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_NEW_TEMPLATE_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_USING_SIM1_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_USING_SIM2_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_DRAFT_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_TEMPLATE_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_ADD_ATTACHMENTS_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_ATTACHMENTS"/>
	<STRING id="STR_ID_VCUI_SMSC_TOTAL"/>
	<STRING id="STR_ID_VCUI_SMSC_EMOTICON"/>
	<STRING id="STR_ID_VCUI_SMSC_UNSUPPORTED_MEDIA"/>
	<STRING id="STR_ID_VCUI_SMSC_RECIPIENTS_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_SEND_CONT_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_CC_AS_HINT"/>
	<STRING id="STR_ID_VCUI_SMSC_BCC_AS_HINT"/>
	<STRING id="STR_ID_VCUI_SMSC_INVALID_ADDRESSES_REMOVED"/>
	<STRING id="STR_ID_VCUI_SMSC_USING_SIM3_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_USING_SIM4_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_QUERY_SIM1_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_QUERY_SIM2_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_QUERY_SIM3_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_QUERY_SIM4_ID"/>
	<STRING id="STR_ID_VCUI_SMSC_TCARD_NOT_PRESENT_USE_PHONE"/>
	<STRING id="STR_ID_VCUI_SMSC_TCARD_FULL_SAVE_TO_PHONE"/>
	<STRING id="STR_ID_VCUI_SMSC_PHONE_FULL_SAVE_TO_TCARD"/>  
	
	/* image */	
	/* FTO start adding resource */
	<IMAGE id="IMG_ID_VCUI_SMSC_PREVIEW_ID">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Preview.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_MORE_ID">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\More.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_FOLD_ID">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Fold.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_ADD_FILE_ID">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Add_File.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_CLEAR_ALL_ID">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Clear.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_ATTACHMENT_FILE_ID">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Attachment.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_IMAGE_FILE_ID">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Image_Files.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_AUDIO_FILE_ID">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Audio_Files.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_VIDEOFILE__ID">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Video_File.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_TEXT_FILE_ID">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Text_Files.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_VCARD_FILE_ID">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Vcard_File.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_VCALENDAR_FILE_ID">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Vcalendar_File.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_UNKNOWN_FILE_ID">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Unknow_File.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_JAD_FILE_ID">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\JAD.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_ADD_CCBCC_ID">RES_IMG_ROOT"\\\\Message\\\\ToolBarIcon\\\\Add_CC.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_REPLACE_ID">RES_IMG_ROOT"\\\\Message\\\\ToolBarIcon\\\\Replace.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_ADD_VCARD_ID">RES_IMG_ROOT"\\\\Message\\\\ToolBarIcon\\\\Add_Vcard.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_ADD_VCALENDAR_ID">RES_IMG_ROOT"\\\\Message\\\\ToolBarIcon\\\\Add_Calendar.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_ADD_SUBJECT_ID">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Add.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_REMOVE_SUBJECT_ID">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Remove.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_CANCEL_ID">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Cancel.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_OPTION_ID">RES_IMG_ROOT"\\\\Message\\\\Option.png"</IMAGE>

#if defined(__MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__)	
	<IMAGE id="IMG_ID_VCUI_SMSC_EMOTIC_1_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\1.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_EMOTIC_2_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\2.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_EMOTIC_3_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\3.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_EMOTIC_4_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\4.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_EMOTIC_5_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\5.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_EMOTIC_6_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\6.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_EMOTIC_7_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\7.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_EMOTIC_8_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\8.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_EMOTIC_9_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\9.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_EMOTIC_10_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\10.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_EMOTIC_11_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\11.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_EMOTIC_12_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\12.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_EMOTIC_13_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\13.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_EMOTIC_14_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\14.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_EMOTIC_15_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\15.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_EMOTIC_16_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\16.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_EMOTIC_17_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\17.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_EMOTIC_18_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\18.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_EMOTIC_19_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\19.png"</IMAGE>
	<IMAGE id="IMG_ID_VCUI_SMSC_EMOTIC_20_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\20.png"</IMAGE>
#endif

#ifdef __DRM_SUPPORT__
	<IMAGE id="IMG_ID_VCUI_SMSC_DRM_DEFAULT_ID">RES_IMG_ROOT"\\\\Message\\\\DRM_Default.png"</IMAGE>
#endif
    	
  <THEME>		
  <IMAGE id="IMG_ID_VCUI_SMSC_EMOTIC_BG_BT2" desc="Emoticon background image"/>				
  </THEME>	    	
    	    
#endif /* if 0 */    