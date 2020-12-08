#include "mmi_features.h"

#include "CustResDef.h"
<?xml version="1.0" encoding="UTF-8"?>
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))

<APP id="VCUI_UC_MMS_SRV" name="STR_ID_VAPP_UC_CUI_SRV" type="venus">
#ifdef __MMI_MMS_USE_ASM__
    <MEMORY extra_base = "SRV_MMS_MMA_ASM_MEM_POOL_SIZE" inc="MmsSrvGprot.h"/>
    <STRING id="STR_ID_VAPP_UC_CUI_SRV"/>
#endif    
</APP>


#ifdef __MMI_VCARD__
   #define VAPP_UC_SERIALIZE_ASM_CUI1_MEM_SIZE "max(VCUI_FMGR, VCUI_BKM, VCUI_CAL_LIST, VCUI_GALLERY_IMAGE_VIEWER, \
                                               VCUI_SOUNDREC, VCUI_UC_MMS_SRV, VCUI_CONTACT_LIST, VCUI_CONTACT_VCARD_VIEW)"
   #define VAPP_UC_SERIALIZE_ASM_CUI1_MEM_SIZE_FOR_EMAIL "max(VCUI_FMGR, VCUI_BKM, VCUI_CAL_LIST, VCUI_GALLERY_IMAGE_VIEWER, \
                                               VCUI_SOUNDREC, VCUI_CONTACT_LIST, VCUI_CONTACT_VCARD_VIEW)"                                                                                                       
#else
   #define VAPP_UC_SERIALIZE_ASM_CUI1_MEM_SIZE "max(VCUI_FMGR, VCUI_BKM, VCUI_CAL_LIST, VCUI_GALLERY_IMAGE_VIEWER, \
                                               VCUI_SOUNDREC, VCUI_UC_MMS_SRV, VCUI_CONTACT_LIST)"
   #define VAPP_UC_SERIALIZE_ASM_CUI1_MEM_SIZE_FOR_EMAIL "max(VCUI_FMGR, VCUI_BKM, VCUI_CAL_LIST, VCUI_GALLERY_IMAGE_VIEWER, \
                                               VCUI_SOUNDREC, VCUI_CONTACT_LIST)"
#endif
                                                    
#ifdef __MMI_COSMOS_UC_VIDEO_SLIM_SUPPORT__
    #define VAPP_UC_SERIALIZE_ASM_CUI2_MEM_SIZE "max(VCUI_GALLERY_IMAGE_PICKER, VCUI_MUSIC_PLAYER)"
    #define VAPP_UC_SERIALIZE_ASM_CUI2_MEM_SIZE_FOR_EMAIL "max(VCUI_GALLERY_IMAGE_PICKER, VCUI_MUSIC_PLAYER)"    
#else
    #ifndef __MMI_MESSAGE_SLIM__
        #define VAPP_UC_SERIALIZE_ASM_CUI2_MEM_SIZE "max(VCUI_GALLERY_VIDEO_PLAYER, VCUI_GALLERY_IMAGE_PICKER, \
                                                    VCUI_GALLERY_VIDEO_PICKER, VCUI_MMS, VCUI_MUSIC_PLAYER)"
        #define VAPP_UC_SERIALIZE_ASM_CUI2_MEM_SIZE_FOR_EMAIL "max(VCUI_GALLERY_VIDEO_PLAYER, VCUI_GALLERY_IMAGE_PICKER, \
                                                              VCUI_GALLERY_VIDEO_PICKER, VCUI_MUSIC_PLAYER)"   
    #else
        #define VAPP_UC_SERIALIZE_ASM_CUI2_MEM_SIZE "max( VCUI_GALLERY_IMAGE_PICKER, VCUI_MMS, VCUI_MUSIC_PLAYER)"
        #define VAPP_UC_SERIALIZE_ASM_CUI2_MEM_SIZE_FOR_EMAIL "max( VCUI_GALLERY_IMAGE_PICKER, VCUI_MUSIC_PLAYER)"          
    #endif
#endif

#ifndef __MMI_MESSAGE_SLIM__
    #ifdef __MMI_COSMOS_UC_VIDEO_SLIM_SUPPORT__
        #define VAPP_UC_SERIALIZE_ASM_MEM_SIZE_FOR_LEMEI "max(VCUI_GALLERY_IMAGE_VIEWER, VCUI_BKM, VCUI_CONTACT_LIST)" 
    #else
        #define VAPP_UC_SERIALIZE_ASM_MEM_SIZE_FOR_LEMEI "max(VCUI_GALLERY_IMAGE_VIEWER, VCUI_GALLERY_VIDEO_PLAYER, VCUI_BKM, VCUI_CONTACT_LIST)"     
    #endif
#else
    #define VAPP_UC_SERIALIZE_ASM_MEM_SIZE_FOR_LEMEI "max(VCUI_GALLERY_IMAGE_VIEWER, VCUI_BKM, VCUI_CONTACT_LIST)"     
#endif
                    
#if (defined(__LOW_COST_SUPPORT_COMMON__))
<APP id="VCUI_MSGCOMPOSER" name="STR_ID_VAPP_UC_MESSAGE_CUI" type="venus">
<MEMORY heap="650*1024-VAPP_UC_SERIALIZE_ASM_MEM_SIZE" extra_base="VAPP_UC_SERIALIZE_ASM_MEM_SIZE" \
    cui=VAPP_UC_SERIALIZE_ASM_CUI1_MEM_SIZE inc="vapp_uc_gprot.h"/>                          
<MEMORY extra_base="VAPP_UC_SERIALIZE_ASM_MEM_SIZE" cui=VAPP_UC_SERIALIZE_ASM_CUI2_MEM_SIZE inc="vapp_uc_gprot.h"/>
</APP>

<APP id="VCUI_EMAILCOMPOSER" name="STR_ID_VAPP_UC_MESSAGE_EMAIL_CUI" type="venus">
<MEMORY heap="640*1024-VAPP_UC_SERIALIZE_ASM_MEM_SIZE" extra_base="VAPP_UC_SERIALIZE_ASM_MEM_SIZE" \
    cui=VAPP_UC_SERIALIZE_ASM_CUI1_MEM_SIZE_FOR_EMAIL inc="vapp_uc_gprot.h"/>
<MEMORY extra_base="VAPP_UC_SERIALIZE_ASM_MEM_SIZE" cui=VAPP_UC_SERIALIZE_ASM_CUI2_MEM_SIZE_FOR_EMAIL inc="vapp_uc_gprot.h"/>
</APP>

<APP id="VCUI_SMSONLYCOMPOSER"  name="STR_ID_VAPP_UC_SMS_ONLY_CUI" type="venus">
<MEMORY heap="580*1024-VAPP_UC_SERIALIZE_ASM_MEM_SIZE" extra_base="VAPP_UC_SERIALIZE_ASM_MEM_SIZE" \
    cui="max(VCUI_BKM, VCUI_CONTACT_LIST)" inc="vapp_uc_gprot.h"/>
</APP>

<APP id="VCUI_LEMEICOMPOSER" name="STR_ID_VAPP_UC_LEMEI_COMPOSER_CUI" type="venus">
<MEMORY heap="640*1024" cui=VAPP_UC_SERIALIZE_ASM_MEM_SIZE_FOR_LEMEI />
</APP>

<APP id="VAPP_UNIFIEDCOMPOSER" name="STR_ID_VAPP_UC_MESSAGE" type="venus">

    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

<MEMORY heap="650*1024-VAPP_UC_SERIALIZE_ASM_MEM_SIZE" extra_base="VAPP_UC_SERIALIZE_ASM_MEM_SIZE" \
cui=VAPP_UC_SERIALIZE_ASM_CUI1_MEM_SIZE inc="vapp_uc_gprot.h"/>
<MEMORY extra_base="VAPP_UC_SERIALIZE_ASM_MEM_SIZE" cui=VAPP_UC_SERIALIZE_ASM_CUI2_MEM_SIZE inc="vapp_uc_gprot.h"/>
#else

<APP id="VCUI_MSGCOMPOSER" name="STR_ID_VAPP_UC_MESSAGE_CUI" type="venus">
<MEMORY heap="700*1024" extra_base="100*1024" 	cui="max(VCUI_FMGR, VCUI_STANDARD_CAMERA, VCUI_STANDARD_RECORDER, VCUI_BKM, \
                                                         VCUI_CAL_LIST, VCUI_GALLERY_IMAGE_VIEWER, VCUI_GALLERY_VIDEO_PLAYER, VCUI_GALLERY_IMAGE_PICKER, \
                                                         VCUI_GALLERY_VIDEO_PICKER, VCUI_MMS, VCUI_SOUNDREC, VCUI_MUSIC_PLAYER, \
                                                         VCUI_UC_MMS_SRV, VCUI_CONTACT_LIST, VCUI_CONTACT_VCARD_VIEW)"/>
</APP>

<APP id="VCUI_EMAILCOMPOSER" name="STR_ID_VAPP_UC_MESSAGE_EMAIL_CUI" type="venus">
<MEMORY heap="650*1024" extra_base="100*1024"	cui="max(VCUI_FMGR, VCUI_STANDARD_CAMERA, VCUI_STANDARD_RECORDER, VCUI_BKM, \
                                                         VCUI_CAL_LIST, VCUI_GALLERY_IMAGE_VIEWER, VCUI_GALLERY_VIDEO_PLAYER, VCUI_GALLERY_IMAGE_PICKER, \
                                                         VCUI_GALLERY_VIDEO_PICKER, VCUI_SOUNDREC, VCUI_MUSIC_PLAYER, VCUI_CONTACT_LIST, \
                                                         VCUI_CONTACT_VCARD_VIEW)"/>
</APP>

<APP id="VCUI_SMSONLYCOMPOSER" name="STR_ID_VAPP_UC_SMS_ONLY_CUI" type="venus">
<MEMORY heap="600*1024" extra_base="100*1024" cui="max(VCUI_BKM, VCUI_CONTACT_LIST)"/>
</APP>

<APP id="VCUI_LEMEICOMPOSER" name="STR_ID_VAPP_UC_LEMEI_COMPOSER_CUI" type="venus">
<MEMORY heap="650*1024" cui="max(VCUI_GALLERY_IMAGE_VIEWER, VCUI_GALLERY_VIDEO_PLAYER, VCUI_BKM, VCUI_CONTACT_LIST)"/>
</APP>

<APP id="VAPP_UNIFIEDCOMPOSER" name="STR_ID_VAPP_UC_MESSAGE" type="venus">

    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

<MEMORY heap="700*1024" extra_base="100*1024"	 cui="max(VCUI_FMGR, VCUI_STANDARD_CAMERA, VCUI_STANDARD_RECORDER, VCUI_BKM, \
                                                          VCUI_CAL_LIST, VCUI_GALLERY_IMAGE_VIEWER, VCUI_GALLERY_VIDEO_PLAYER, VCUI_GALLERY_IMAGE_PICKER, \
                                                          VCUI_GALLERY_VIDEO_PICKER, VCUI_MMS, VCUI_SOUNDREC, VCUI_MUSIC_PLAYER, \ 
                                                          VCUI_UC_MMS_SRV, VCUI_CONTACT_LIST, VCUI_CONTACT_VCARD_VIEW)"/>
#endif
	<LAYOUT file = "vapp_UC.xml"/>
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
		<!--String Resource Area-->

	<STRING id="STR_ID_VAPP_UC_MESSAGE"/>
	<STRING id="STR_ID_VAPP_UC_INSERT_ID"/>
	<STRING id="STR_ID_VAPP_UC_NO_IMAGE"/>
	<STRING id="STR_ID_VAPP_UC_AUDIO_ID"/>
	<STRING id="STR_ID_VAPP_UC_TEXT_TEMPLATE_ID"/>
	<STRING id="STR_ID_VAPP_UC_ATTACHMENT_LIST_ID"/>
	<STRING id="STR_ID_VAPP_UC_INSERT_NEW_SLIDE_ID"/>
	<STRING id="STR_ID_VAPP_UC_DELETE_SLIDE_ID"/>
	<STRING id="STR_ID_VAPP_UC_TO_ID"/>
#ifndef __MMI_MESSAGE_SLIM__	
	<STRING id="STR_ID_VAPP_UC_CC_ID"/>
	<STRING id="STR_ID_VAPP_UC_BCC_ID"/>
#endif	
	<STRING id="STR_ID_VAPP_UC_TO_OPTION_ID"/>
	<STRING id="STR_ID_VAPP_UC_MSG_SIZE_EXCEED_ID"/>
	<STRING id="STR_ID_VAPP_UC_RESTRICTED_MODE_MSG_SIZE_EXCEED_ID"/>
	<STRING id="STR_ID_VAPP_UC_SIZE_NOT_ENOUGH_FOR_REC_VIDEO_ID"/>
	<STRING id="STR_ID_VAPP_UC_NUM_CANNOT_BE_EMPTY_ID"/>
	<STRING id="STR_ID_VAPP_UC_ADDR_LENGTH_EXCEED_ID"/>
	<STRING id="STR_ID_VAPP_UC_NUMBER_LENGTH_EXCEED_ID"/>
	<STRING id="STR_ID_VAPP_UC_PROHIBIT_BY_CREATION_MODE_ID"/>
	<STRING id="STR_ID_VAPP_UC_NO_SPACE_ID"/>

	<STRING id="STR_ID_VAPP_UC_INSERTING"/>
	<STRING id="STR_ID_VAPP_UC_SWITCHED_TO"/>

	<STRING id="STR_ID_VAPP_UC_IMAGE"/>
#ifndef __MMI_MESSAGE_SLIM__	
	<STRING id="STR_ID_VAPP_UC_VIDEO"/>	
#endif	
	<STRING id="STR_ID_VAPP_UC_AUDIO"/>	
	<STRING id="STR_ID_VAPP_UC_ATTACHMENT"/>
#ifdef __MMI_VCARD__		
	<STRING id="STR_ID_VAPP_UC_VCARD"/>	
#endif
#ifdef __MMI_VCALENDAR__	
	<STRING id="STR_ID_VAPP_UC_VCALENDAR"/>	
	<STRING id="STR_ID_VAPP_UC_VEVENT"/>	
	<STRING id="STR_ID_VAPP_UC_VTASK"/>	
#endif	
	<STRING id="STR_ID_VAPP_UC_TEXT"/>	
	<STRING id="STR_ID_VAPP_UC_SLIDE"/>
	<STRING id="STR_ID_VAPP_UC_SLIDES_ID"/>

#ifndef __MMI_MESSAGE_SLIM__	
	<STRING id="STR_ID_VAPP_UC_CCBCC"/>	
	<STRING id="STR_ID_VAPP_UC_ADD_CC"/>	
	<STRING id="STR_ID_VAPP_UC_REMOVE_CC"/>											
	<STRING id="STR_ID_VAPP_UC_ADD_BCC"/>	
	<STRING id="STR_ID_VAPP_UC_REMOVE_BCC"/>	
#endif

	<STRING id="STR_ID_VAPP_UC_WRITE_MSG_ID"/>

	<STRING id="STR_ID_VAPP_UC_MAX_TEMPLATE_ALREADY_PRESENT_ID"/>

	<STRING id="STR_ID_VAPP_UC_STORAGE_FILE_IO_ERROR_ID"/>

	<STRING id="STR_ID_VAPP_UC_NO_RECIPIENT_ID"/>
	<STRING id="STR_ID_VAPP_UC_PLS_ADD_RECIPIENT_ID"/>

	<STRING id="STR_ID_VAPP_UC_ABORTED_ID"/>
	<STRING id="STR_ID_VAPP_UC_SEND_SUCCESS_SAVE_SUCCESS"/>
	<STRING id="STR_ID_VAPP_UC_SEND_SUCCESS_SAVE_FAIL"/>
	<STRING id="STR_ID_VAPP_UC_SEND_FAIL_SAVE_SUCCESS"/>
	<STRING id="STR_ID_VAPP_UC_SEND_FAIL_SAVE_FAIL"/>
	<STRING id="STR_ID_VAPP_UC_CONTENT_ERROR_ID"/>
	<STRING id="STR_ID_VAPP_UC_RECIPIENT_NUMBER_EXCEED_ID"/>

	<STRING id="STR_ID_VAPP_UC_UNSUPPORT_CONTENT_ID"/>
	<STRING id="STR_ID_VAPP_UC_NO_ENOUGH_WORKING_SPACE_ID"/>
	<STRING id="STR_ID_VAPP_UC_CREATION_MODE_MAX_MSG_SIZE_REACHED_ID"/>
	<STRING id="STR_ID_VAPP_UC_MAX_SLIDE_NUM_REACHED_ID"/>
	<STRING id="STR_ID_VAPP_UC_TOO_MANY_MSG_ID"/>
	<STRING id="STR_ID_VAPP_UC_SEND_FAIL_ID"/>

	<STRING id="STR_ID_VAPP_UC_SYSTEM_RESOURCES_EXHAUSTED_ID"/>
	<STRING id="STR_ID_VAPP_UC_FILE_CORRUPT_ID"/>
	<STRING id="STR_ID_VAPP_UC_FAILED_TO_ADD_MEDIA_ID"/>
	<STRING id="STR_ID_VAPP_UC_FAILED_TO_ADD_ATTACHMENT_ID"/>
	<STRING id="STR_ID_VAPP_UC_FILE_EMPTY_ID"/>
	<STRING id="STR_ID_VAPP_UC_FILE"/>
	<STRING id="STR_ID_VAPP_UC_RE_ID"/>
	<STRING id="STR_ID_VAPP_UC_FW_ID"/>
	<STRING id="STR_ID_VAPP_UC_FAIL_TO_RESIZE_IMAGE_ID"/>


	<STRING id="STR_ID_VAPP_UC_SERVER_ID"/>
	<STRING id="STR_ID_VAPP_UC_KB_ID"/>
	<STRING id="STR_ID_VAPP_UC_RESIZE_IMAGE_UNCHANGED_ID"/>
	<STRING id="STR_ID_VAPP_UC_WARNING_MODE_CONFIRM"/>
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
	<STRING id="STR_ID_VAPP_UC_INSERT_CARD"/>
	<STRING id="STR_ID_VAPP_UC_CARD_NOT_PRESENT_CONFIRM"/>
	<STRING id="STR_ID_VAPP_UC_MAX_MSG_CARD_CONFIRM"/>
	<STRING id="STR_ID_VAPP_UC_MAX_MSG_PHONE_CONFIRM"/>
#endif
	<STRING id="STR_ID_VAPP_UC_DELETE_ASK_ID"/>
	<STRING id="STR_ID_VAPP_UC_DELETE_ALL_ASK_ID"/>
	<STRING id="STR_ID_VAPP_UC_CONN_TYPE_MAX_SIZE_REACHED_ID"/>

	<STRING id="STR_ID_VAPP_UC_CONTINUE"/>

    <STRING id="STR_ID_VAPP_UC_FLIGHT_MODE"/>

	<STRING id="STR_ID_VAPP_UC_ADD_RECIPIENT"/>
#ifdef __MMI_VCARD__	
	<STRING id="STR_ID_VAPP_UC_INSERT_VCARD"/>
#endif	
	<STRING id="STR_ID_VAPP_UC_ADD_SUBJECT_ID"/>
	<STRING id="STR_ID_VAPP_UC_REMOVE_SUBJECT_ID"/>
	<STRING id="STR_ID_VAPP_UC_ENTER_RECIPIENT_ID"/>
	<STRING id="STR_ID_VAPP_UC_ADD_FROM_CONTACTS_ID"/>
	<STRING id="STR_ID_VAPP_UC_EDIT_RECIPIENT_ID"/>
	<STRING id="STR_ID_VAPP_UC_REMOVE_RECIPIENT_ID"/>
	<STRING id="STR_ID_VAPP_UC_REMOVE_ALL_RECIPIENTS_ID"/>
	<STRING id="STR_ID_VAPP_UC_SAVE_TO_DRAFT_ID"/>
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
	<STRING id="STR_ID_VAPP_UC_REMOVE_EMS_OBJECT_CONFIRM"/>
	<STRING id="STR_ID_VAPP_UC_CORRUPT_MSG_DELETE_CONFIRM"/>
#endif
	<STRING id="STR_ID_VAPP_UC_WRITE_MSG_SUBJECT_ID"/>
	<STRING id="STR_ID_VAPP_UC_REMOVE_PICTURE_ID"/>
	<STRING id="STR_ID_VAPP_UC_REMOVE_AUDIO_ID"/>
#ifndef __MMI_MESSAGE_SLIM__	
	<STRING id="STR_ID_VAPP_UC_VIDEO_OPTIONS_ID"/>
#endif	
	<STRING id="STR_ID_VAPP_UC_REMOVE_VIDEO_ID"/>
	<STRING id="STR_ID_VAPP_UC_ATTACHMENT_OPTIONS_ID"/>
	<STRING id="STR_ID_VAPP_UC_REMOVE_ATTACHMENT_ID"/>
	<STRING id="STR_ID_VAPP_UC_ADD_MY_PICTURES_ID"/>
	<STRING id="STR_ID_VAPP_UC_ADD_MY_SOUNDS_ID"/>
#ifndef __MMI_COSMOS_UC_VIDEO_SLIM_SUPPORT__	
	<STRING id="STR_ID_VAPP_UC_ADD_MY_VIDEOS_ID"/>
#else	
	<STRING id="STR_ID_VAPP_UC_ADD_VIDEOS_FROM_FMGR_ID"/>
#endif
	<STRING id="STR_ID_VAPP_UC_TAKE_PICTURE_ID"/>
	<STRING id="STR_ID_VAPP_UC_RECORD_SOUND_ID"/>
	<STRING id="STR_ID_VAPP_UC_RECORD_VIDEO_ID"/>
	<STRING id="STR_ID_VAPP_UC_ADD_PICTURE_ID"/>
	<STRING id="STR_ID_VAPP_UC_ADD_SOUND_ID"/>
	<STRING id="STR_ID_VAPP_UC_ADD_VIDEO_ID"/>
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
	<STRING id="STR_ID_VAPP_UC_SWITCHED_TO_SMS_ID"/>
	<STRING id="STR_ID_VAPP_UC_SWITCHED_TO_MMS_ID"/>
#endif
	<STRING id="STR_ID_VAPP_UC_PREVIEW_MMS_ID"/>
	<STRING id="STR_ID_VAPP_UC_ADD_NEW_SLIDE_AFTER_ID"/>
	<STRING id="STR_ID_VAPP_UC_ADD_NEW_SLIDE_BEFORE_ID"/>
#if defined(__MMI_MESSAGES_TEMPLATE__)
	<STRING id="STR_ID_VAPP_UC_INSERT_TEXT_TEMPLATE_ID"/>
#endif
	<STRING id="STR_ID_VAPP_UC_INSERT_ATTACHMENT_ID"/>

#if 0	
	<STRING id="STR_ID_VAPP_UC_INSERT_PHB_NUMBER_ID"/>
	<STRING id="STR_ID_VAPP_UC_INSERT_PHB_NAME_ID"/>
#endif	
	<STRING id="STR_ID_VAPP_UC_INSERT_PHB_NAME_AND_NUM_ID"/>
	<STRING id="STR_ID_VAPP_UC_INSERT_BOOKMARK_ID"/>
	<STRING id="STR_ID_VAPP_UC_TRUNCATE_NUMBER_ID"/>
	<STRING id="STR_ID_VAPP_UC_MSG_CLASS_ID"/>
	<STRING id="STR_ID_VAPP_UC_IMAGE_TOO_LARGE"/>
	<STRING id="STR_ID_VAPP_UC_SOME_OBJECT_WITHDREW"/>
	<STRING id="STR_ID_VAPP_UC_REMOVED_ID"/>
	<STRING id="STR_ID_VAPP_UC_ADD_OBJECT_ID"/>
	<STRING id="STR_ID_VAPP_UC_ADD_CONTACT_ID"/>
	<STRING id="STR_ID_VAPP_UC_MULTIMEDIA"/>
#ifdef OMA13_CON_739_SUPPORT_TEMP_TEST_CODE
	<STRING id="STR_ID_VAPP_UC_PERSONAL"/>
	<STRING id="STR_ID_VAPP_UC_ADVERTISEMENT"/>
	<STRING id="STR_ID_VAPP_UC_INFORMATIONAL"/>
	<STRING id="STR_ID_VAPP_UC_AUTO"/>
#endif /* OMA13_CON_739_SUPPORT_TEMP_TEST_CODE */
	<STRING id="STR_ID_VAPP_UC_FAILURE_TEXT_CONTENT_EMPTY"/>
	<STRING id="STR_ID_VAPP_UC_FAILURE_TEXT_CONTENT_EXCEED"/>
	<STRING id="STR_ID_VAPP_UC_TXT_EDITOR_HINT_ID"/>
	<STRING id="STR_ID_VAPP_UC_TXT_EDITOR_SUBJECT_HINT_ID"/> 
	<STRING id="STR_ID_VAPP_UC_ADD_SLIDE_ID"/>
	<STRING id="STR_ID_VAPP_UC_REMOVE_SLIDE_ID"/>
	<STRING id="STR_ID_VAPP_UC_SWITCH_SIM_ID"/>

	<STRING id="STR_ID_VAPP_UC_NEW_TEMPLATE_ID"/>
	<STRING id="STR_ID_VAPP_UC_USING_SIM1_ID"/>
	<STRING id="STR_ID_VAPP_UC_USING_SIM2_ID"/>

#if (defined(__MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__) || defined(__MMI_MESSAGES_TEMPLATE__))		
	<STRING id="STR_ID_VAPP_UC_TEMPLATE_ID"/>
#endif	
	<STRING id="STR_ID_VAPP_UC_ADD_ATTACHMENTS_ID"/>
	<STRING id="STR_ID_VAPP_UC_ATTACHMENTS"/>
	<STRING id="STR_ID_VAPP_UC_TOTAL"/>
#ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__	
	<STRING id="STR_ID_VAPP_UC_EMOTICON"/>
#endif	
	<STRING id="STR_ID_VAPP_UC_UNSUPPORTED_MEDIA"/>
	<STRING id="STR_ID_VAPP_UC_RECIPIENTS_ID"/>
	<STRING id="STR_ID_VAPP_UC_SEND_CONT_ID"/>
	<STRING id="STR_ID_VAPP_UC_TO_AS_HINT"/>
#ifndef __MMI_MESSAGE_SLIM__	
	<STRING id="STR_ID_VAPP_UC_CC_AS_HINT"/>
	<STRING id="STR_ID_VAPP_UC_BCC_AS_HINT"/>
#endif	
	<STRING id="STR_ID_VAPP_UC_UNNAMED"/>	
	<STRING id="STR_ID_VAPP_UC_INVALID_RECIPIENTS_REMOVED"/>
	<STRING id="STR_ID_VAPP_UC_INVALID_ADDRESSES_REMOVED"/>
	<STRING id="STR_ID_VAPP_UC_INVALID_RECIPIENT"/>
	<STRING id="STR_ID_VAPP_UC_USING_SIM3_ID"/>
	<STRING id="STR_ID_VAPP_UC_USING_SIM4_ID"/>

	<STRING id="STR_ID_VAPP_UC_BLOCKED_SIM1_ID"/>
	<STRING id="STR_ID_VAPP_UC_BLOCKED_SIM2_ID"/>
	<STRING id="STR_ID_VAPP_UC_BLOCKED_SIM3_ID"/>
	<STRING id="STR_ID_VAPP_UC_BLOCKED_SIM4_ID"/>
	<STRING id="STR_ID_VAPP_UC_UNAVAILABLE_TRFR_TO_ID"/>
	
	<STRING id="STR_ID_VAPP_UC_TCARD_NOT_PRESENT_USE_PHONE"/>
	<STRING id="STR_ID_VAPP_UC_TCARD_FULL_SAVE_TO_PHONE"/>
	<STRING id="STR_ID_VAPP_UC_PHONE_FULL_SAVE_TO_TCARD"/>
		
		<!--End String Resource Area-->


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>

	<!--Image Resource Area-->

		/* FTO start adding resource */
		<IMAGE id="IMG_ID_VAPP_UC_INSERT_ID" >RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Insert.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_PREVIEW_ID">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Preview.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_MORE_ID">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\More.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_FOLD_ID">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Fold.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_SEND_ID">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Send.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_ADD_FILE_ID">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Add_File.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_SAVE_AS_ID">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Save.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_CLEAR_ALL_ID">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Clear.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_ATTACHMENT_FILE_ID">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Attachment.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_IMAGE_FILE_ID">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Image_Files.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_AUDIO_FILE_ID">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Audio_Files.png"</IMAGE>
#ifndef __MMI_MESSAGE_SLIM__	
		<IMAGE id="IMG_ID_VAPP_UC_VIDEOFILE__ID">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Video_File.png"</IMAGE>
#endif		
		<IMAGE id="IMG_ID_VAPP_UC_TEXT_FILE_ID">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Text_Files.png"</IMAGE>
#ifdef __MMI_VCARD__		
		<IMAGE id="IMG_ID_VAPP_UC_VCARD_FILE_ID">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Vcard_File.png"</IMAGE>
#endif		
#ifdef __MMI_VCALENDAR__
		<IMAGE id="IMG_ID_VAPP_UC_VCALENDAR_FILE_ID">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Vcalendar_File.png"</IMAGE>
#endif		
		<IMAGE id="IMG_ID_VAPP_UC_UNKNOWN_FILE_ID">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Unknow_File.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_JAD_FILE_ID">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\JAD.png"</IMAGE>
#ifndef __MMI_MESSAGE_SLIM__		
		<IMAGE id="IMG_ID_VAPP_UC_ADD_CCBCC_ID">RES_IMG_ROOT"\\\\Message\\\\ToolBarIcon\\\\Add_CC.png"</IMAGE>
#endif		
		<IMAGE id="IMG_ID_VAPP_UC_SWITCH_SIM_ID">RES_IMG_ROOT"\\\\Message\\\\ToolBarIcon\\\\Switch_SIM.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_REPLACE_ID">RES_IMG_ROOT"\\\\Message\\\\ToolBarIcon\\\\Replace.png"</IMAGE>
#ifdef	__MMI_VCARD__	
		<IMAGE id="IMG_ID_VAPP_UC_ADD_VCARD_ID">RES_IMG_ROOT"\\\\Message\\\\ToolBarIcon\\\\Add_Vcard.png"</IMAGE>
#endif		
#ifdef __MMI_VCALENDAR__
		<IMAGE id="IMG_ID_VAPP_UC_ADD_VCALENDAR_ID">RES_IMG_ROOT"\\\\Message\\\\ToolBarIcon\\\\Add_Calendar.png"</IMAGE>
#endif		
		<IMAGE id="IMG_ID_VAPP_UC_ADD_SUBJECT_ID">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Add.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_REMOVE_SUBJECT_ID">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Remove.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_CANCEL_ID">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Cancel.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_OPTION_ID">RES_IMG_ROOT"\\\\Message\\\\Option.png"</IMAGE>

#if defined(__MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__)	
		<IMAGE id="IMG_ID_VAPP_UC_EMOTIC_1_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\1.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_EMOTIC_2_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\2.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_EMOTIC_3_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\3.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_EMOTIC_4_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\4.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_EMOTIC_5_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\5.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_EMOTIC_6_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\6.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_EMOTIC_7_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\7.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_EMOTIC_8_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\8.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_EMOTIC_9_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\9.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_EMOTIC_10_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\10.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_EMOTIC_11_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\11.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_EMOTIC_12_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\12.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_EMOTIC_13_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\13.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_EMOTIC_14_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\14.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_EMOTIC_15_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\15.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_EMOTIC_16_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\16.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_EMOTIC_17_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\17.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_EMOTIC_18_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\18.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_EMOTIC_19_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\19.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_UC_EMOTIC_20_ID">RES_IMG_ROOT"\\\\Message\\\\Emoticon\\\\20.png"</IMAGE>
#endif

#ifdef __DRM_SUPPORT__
		<IMAGE id="IMG_ID_VAPP_UC_DRM_DEFAULT_ID">RES_IMG_ROOT"\\\\Message\\\\DRM_Default.png"</IMAGE>
#endif

    <IMAGE id="IMG_ID_VAPP_UC_CONTACT_BTN_BG_HLT">CUST_IMG_PATH_ROOT"\\\\\MainLCD\\\\Default\\\\Message\\\\ContactSelector\\\\BTN_H.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_UC_CONTACT_BTN_BG_NRL">CUST_IMG_PATH_ROOT"\\\\\MainLCD\\\\Default\\\\Message\\\\ContactSelector\\\\BTN_N.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_UC_CONTACT_BTN_DELETE">CUST_IMG_PATH_ROOT"\\\\\MainLCD\\\\Default\\\\Message\\\\ContactSelector\\\\Delete.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_UC_BTN_DELETE">CUST_IMG_PATH_ROOT"\\\\\MainLCD\\\\Default\\\\Common\\\\Button\\\\Delete.png"</IMAGE>
   
    <THEME>		
	
    <!--Need to move to theme-->
    <IMAGE id="IMG_ID_VAPP_UC_CONTACT_ICON" desc="Botton contact shortcut"/>
    <COLOR id="CLR_ID_VAPP_UC_CONTACT_TEXT_FRAME" desc = "The contact text frame color"/>
    </THEME>	
    
    <!--End Image Resource Area-->

	<!--------------------------------------------------------------------------------------------------------------------->
        <!--Audio Resource Area-->
        <!--Audio Resource Area-->

        <!--End Audio Resource Area-->
        <!--End Audio Resource Area-->
        <!--------------------------------------------------------------------------------------------------------------------->


        <!--------------------------------------------------------------------------------------------------------------------->
        <!--Media Resource Area-->
        <!--Media Resource Area-->

        <!--End Media Resource Area-->
        <!--End Media Resource Area-->
        <!--------------------------------------------------------------------------------------------------------------------->

		<!--------------------------------------------------------------------------------------------------------------------->
        <!--Screen ID Area-->
        <!--Screen ID Area-->
	
	 <!--End Screen Resource Area-->
        <!--End Screen Resource Area-->
        <!--------------------------------------------------------------------------------------------------------------------->


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */
	 <!--------------------------------------------------------------------------------------------------------------------->
        <!--Menu Item Area-->
        <!--Menu Item Area-->

				<MENU id = "MENU_ID_VUC_OPT_INSERT" type = "OPTION" str = "STR_ID_VAPP_UC_INSERT_ID">

					#if (defined(__MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__) || defined(__MMI_MESSAGES_TEMPLATE__))
					<MENU id = "MENU_ID_VUC_OPT_TEMPLATE" type = "OPTION" str = "STR_ID_VAPP_UC_TEMPLATE_ID">
						#if defined(__MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__)
						<MENUITEM id = "MENU_ID_VUC_OPT_INSERT_EMOTICON" str = "STR_ID_VAPP_UC_EMOTICON"/>
						#endif
						#ifdef __MMI_MESSAGES_TEMPLATE__
						<MENUITEM id = "MENU_ID_VUC_OPT_INSERT_TEMPLATE" str = "STR_ID_VAPP_UC_TEMPLATE_ID"/>
						#endif
					</MENU> <!--menu_item_end(MENU_ID_VUC_OPT_TEMPLATE)-->	
					#endif
					<MENU id = "MENU_ID_VUC_OPT_MULTIMEDIA" type = "OPTION" str = "@OID:STR_GLOBAL_MULTIMEDIA">
						
				#if (!defined(__LOW_COST_SUPPORT_COMMON__))		
						<MENU id = "MENU_ID_VUC_OPT_IMAGE_OPTIONS" type = "OPTION" str = "STR_ID_VAPP_UC_IMAGE">
							<MENUITEM id = "MENU_ID_VUC_OPT_INSERT_IMAGE" str = "STR_ID_VAPP_UC_ADD_MY_PICTURES_ID"/>
						#ifdef __MMI_CAMERA__
							<MENUITEM id = "MENU_ID_VUC_OPT_INSERT_NEW_IMAGE" str = "STR_ID_VAPP_UC_TAKE_PICTURE_ID"/>
						#endif /* __MMI_CAMERA__ */
						</MENU> <!--menu_item_end(MENU_ID_VUC_OPT_IMAGE_OPTIONS)-->									
				#else
						<MENUITEM id = "MENU_ID_VUC_OPT_INSERT_IMAGE" str = "STR_ID_VAPP_UC_IMAGE"/>
				#endif
				
		#ifndef __MMI_MESSAGE_SLIM__		
				#if (!defined(__LOW_COST_SUPPORT_COMMON__))
						<MENU id = "MENU_ID_VUC_OPT_VIDEO_OPTIONS" type = "OPTION" str = "STR_ID_VAPP_UC_VIDEO">
						#ifndef __MMI_COSMOS_UC_VIDEO_SLIM_SUPPORT__
							<MENUITEM id = "MENU_ID_VUC_OPT_INSERT_VIDEO" str = "STR_ID_VAPP_UC_ADD_MY_VIDEOS_ID"/>
						#else
							<MENUITEM id = "MENU_ID_VUC_OPT_INSERT_VIDEO" str = "STR_ID_VAPP_UC_ADD_VIDEOS_FROM_FMGR_ID"/>
						#endif	
					 	#if defined(__MMI_CAMCORDER__)
								<MENUITEM id = "MENU_ID_VUC_OPT_INSERT_NEW_VIDEO" str = "STR_ID_VAPP_UC_RECORD_VIDEO_ID"/>
						#endif /* __MMI_CAMCORDER__*/
						</MENU> <!--menu_item_end(MENU_ID_VUC_OPT_VIDEO_OPTIONS)-->
				#else
						<MENUITEM id = "MENU_ID_VUC_OPT_INSERT_VIDEO" str = "STR_ID_VAPP_UC_VIDEO"/>
				#endif /* __LOW_COST_SUPPORT_COMMON__ */
		#endif /* __MMI_MESSAGE_SLIM__ */
						
				#ifdef __MMI_SOUNDREC_CUI__
						<MENU id = "MENU_ID_VUC_OPT_AUDIO_OPTIONS" type = "OPTION" str = "STR_ID_VAPP_UC_AUDIO">
							<MENUITEM id = "MENU_ID_VUC_OPT_INSERT_AUDIO" str = "STR_ID_VAPP_UC_ADD_MY_SOUNDS_ID"/>
						#ifdef __MMI_SOUND_RECORDER__
							<MENUITEM id = "MENU_ID_VUC_OPT_INSERT_NEW_AUDIO" str = "STR_ID_VAPP_UC_RECORD_SOUND_ID"/>
						#endif /* __MMI_SOUND_RECORDER__ */
						</MENU> <!--menu_item_end(MENU_ID_VUC_OPT_AUDIO_OPTIONS)-->
				#else
						<MENUITEM id = "MENU_ID_VUC_OPT_INSERT_AUDIO" str = "STR_ID_VAPP_UC_AUDIO"/>
				#endif

						
					</MENU> <!--menu_item_end(MENU_ID_VUC_OPT_MULTIMEDIA)-->

					<MENU id = "MENU_ID_VUC_OPT_ATTACHMENT" type = "OPTION" str = "STR_ID_VAPP_UC_ATTACHMENT">
                    #if defined(__MMI_VCARD__)
						<MENUITEM id = "MENU_ID_VUC_INSERT_VCARD" str = "STR_ID_VAPP_UC_VCARD"/>
                    #endif
                    #if defined(__MMI_VCALENDAR__)                    
						<MENUITEM id = "MENU_ID_VUC_INSERT_VEVENT" str = "STR_ID_VAPP_UC_VEVENT"/>
						<MENUITEM id = "MENU_ID_VUC_INSERT_VTASK" str = "STR_ID_VAPP_UC_VTASK"/>
                    #endif						
						<MENUITEM id = "MENU_ID_VUC_INSERT_FILE" str = "STR_ID_VAPP_UC_FILE"/>							
					</MENU> <!--menu_item_end(MENU_ID_VUC_OPT_ATTACHMENT)-->									

					<MENU id = "MENU_ID_VUC_OPT_TEXT" type = "OPTION" str = "STR_ID_VAPP_UC_TEXT">
					#if 0
						<MENUITEM id = "MENU_ID_VUC_OPT_INSERT_PHB_NAME" str = "STR_ID_VAPP_UC_INSERT_PHB_NAME_ID"/>
						<MENUITEM id = "MENU_ID_VUC_OPT_INSERT_PHB_NUMBER" str = "STR_ID_VAPP_UC_INSERT_PHB_NUMBER_ID"/>
					#endif	
						<MENUITEM id = "MENU_ID_VUC_OPT_INSERT_PHB_NAME_AND_NUM" str = "STR_ID_VAPP_UC_INSERT_PHB_NAME_AND_NUM_ID"/>
						<MENUITEM id = "MENU_ID_VUC_OPT_INSERT_BOOKMARK" str = "STR_ID_VAPP_UC_INSERT_BOOKMARK_ID"/>	
					</MENU> <!--menu_item_end(MENU_ID_VUC_OPT_TEXT)-->	
	
					<MENU id = "MENU_ID_VUC_OPT_SLIDE" type = "OPTION" str = "STR_ID_VAPP_UC_SLIDE">
						<MENUITEM id = "MENU_ID_VUC_OPT_SLIDE_INSERT" str = "STR_ID_VAPP_UC_SLIDE"/>
					</MENU> <!--menu_item_end(MENU_ID_VUC_OPT_SLIDE)-->

				</MENU> <!--menu_item_end(MENU_ID_VUC_OPT_INSERT)-->									
#if 0
				<MENU id = "MENU_ID_VUC_MEDIA_OPTION" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
						<MENUITEM id = "MENU_ID_VUC_MEDIA_PREVIEW" str = "STR_GLOBAL_PREVIEW"/>
						<MENUITEM id = "MENU_ID_VUC_OPT_REMOVE" str = "@OID:STR_GLOBAL_REMOVE"/>
				</MENU> <!--menu_item_end(MENU_ID_VUC_MEDIA_OPTION)-->

				<MENU id = "MENU_ID_VUC_SAVE_AS_OPTION" type = "OPTION" str = "STR_GLOBAL_SAVE">
						<MENUITEM id = "MENU_ID_VUC_OPT_SAVE_TO_DRAFT" str = "STR_ID_VAPP_UC_DRAFT_ID"/>
						<MENUITEM id = "MENU_ID_VUC_OPT_SAVE_AS_TEMPLATE" str = "STR_ID_VAPP_UC_SAVE_AS_TEMPLATE_ID"/>				
				</MENU> <!--menu_item_end(MENU_ID_VUC_SAVE_AS_OPTION)-->

				<MENU id = "MENU_ID_VUC_HEADER_OPTION" type = "OPTION" str = "STR_ID_VAPP_UC_CCBCC">
						<MENUITEM id = "MENU_ID_VUC_ADD_CC" str = "STR_ID_VAPP_UC_ADD_CC"/>
						<MENUITEM id = "MENU_ID_VUC_REMOVE_CC" str = "STR_ID_VAPP_UC_REMOVE_CC"/>						
						<MENUITEM id = "MENU_ID_VUC_ADD_BCC" str = "STR_ID_VAPP_UC_ADD_BCC"/>	
						<MENUITEM id = "MENU_ID_VUC_REMOVE_BCC" str = "STR_ID_VAPP_UC_REMOVE_BCC"/>									
				</MENU> <!--menu_item_end(MENU_ID_VUC_SAVE_AS_OPTION)-->
#endif				
								
    <!------------------------------------------------------Other Resource---------------------------------------------------------->

    <RECEIVER id="EVT_ID_SRV_SMS_DEL_MSG" proc="vappUcHandleSmsMsgDelEvent"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="vappUcSdCardPlugInHdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="vappUcSdCardPlugOutHdlr"/>
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_UNAVAILABLE" proc="vappUcForceClose"/>
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABLE" proc="vappUcForceClose"/>
#ifdef __MMI_USB_SUPPORT__
    <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="vappUcUsbMsPlugInHdlr"/>
#endif
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="vappUcSimStatusInfoHdlr"/>
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="vappUcSimStatusInfoHdlr"/>
    <RECEIVER id="EVT_ID_SRV_MMS_MMA_TERMINATE" proc="vappUcTerminateAllApps"/>
	<EVENT id="EVT_ID_SRV_UC_MESSAGE_DELETED" type="SENDER"/>
	<EVENT id="EVT_ID_UC_DATA_COLLECTION_CB_FINISH_NOTIFY" type="SENDER"/>	
	

	<CACHEDATA type="byte" id="NVRAM_UC_APP_PREFER_SIM" restore_flag="TRUE">
	<DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
	<DESCRIPTION> Byte Cache </DESCRIPTION>
	</CACHEDATA>
</APP>
#endif
