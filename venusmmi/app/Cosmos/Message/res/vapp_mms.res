#include "mmi_features.h"
#include "CustResDef.h"         /* for image/audio path */
#include "vfx_sys_config.h"
<?xml version="1.0" encoding="UTF-8"?>

/* Needed header files of the compile option in XML files, if you need others need to add here */
#ifdef __MMI_MMS_2__


<APP id="VAPP_MMS_SEND_URI" name="STR_ID_VAPP_MMS_SEND_MMS" type="venus">

    <MEMORY cui="VCUI_MSGCOMPOSER"/>
    <STRING id="STR_ID_VAPP_MMS_SEND_MMS"/>
    
</APP>

<APP id="VAPP_MMS_HEAP" name="STR_ID_VAPP_MMS_HEAP" type="venus">

    <MEMORY heap= "0"  vrt_mem_factor = "0"/>
    <STRING id="STR_ID_VAPP_MMS_HEAP"/>
    
</APP>

<APP id="VAPP_MMS_EXTRA_BASE" name="STR_ID_VAPP_MMS_EXTRA_BASE" type="venus">
#ifndef __MMI_MESSAGE_SLIM__
    <MEMORY extra_base="base(SRV_MDI_VDOPLY_CIF)" vrt_mem_factor = "0" />
#else
    <MEMORY extra_base="0" vrt_mem_factor = "0" />

#endif
    
 
    <STRING id="STR_ID_VAPP_MMS_EXTRA_BASE"/>
    
</APP>
<APP id="VAPP_MMS_FG" name="STR_ID_VAPP_MMS_FG" type="venus">
#ifndef __MMI_MESSAGE_SLIM__
    <MEMORY fg="fg(SRV_MDI_VDOPLY_CIF) + GDI_LCD_WIDTH*GDI_LCD_HEIGHT*2" vrt_mem_factor = "0" />
#else
    <MEMORY fg="0" vrt_mem_factor = "0" />

#endif
    <STRING id="STR_ID_VAPP_MMS_FG"/>
    
</APP>

<APP id="VAPP_MMS_CUI_SRV" name="STR_ID_VAPP_MMS_CUI_SRV" type="venus">

#ifdef __MMI_MMS_USE_ASM__
    <MEMORY extra_base = "SRV_MMS_MMA_ASM_MEM_POOL_SIZE" vrt_mem_factor = "0" inc="MmsSrvGprot.h"/>
    <STRING id="STR_ID_VAPP_MMS_CUI_SRV"/>
#endif    
    
</APP>
/* APP tag, include your app name defined in MMIDataType.h */
<APP id="VAPP_MMS" name="STR_ID_VAPP_MMS_MMS_SETTINGS" type="venus">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can file the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,GlobalMenuItems.h,MessagesResDef.h" />
   
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
 #ifdef __MMI_MMS_USE_ASM__  
    <MEMORY extra_base="base(SRV_MDI_VDOPLY_CIF) + SRV_MMS_MMA_ASM_MEM_POOL_SIZE" fg="fg(SRV_MDI_VDOPLY_CIF) + GDI_LCD_WIDTH*GDI_LCD_HEIGHT*2" inc="MmsSrvGprot.h"/>
 #else
    <MEMORY extra_base="base(SRV_MDI_VDOPLY_CIF)" fg="fg(SRV_MDI_VDOPLY_CIF) + GDI_LCD_WIDTH*GDI_LCD_HEIGHT*2"/>
 #endif
	<LAYOUT file = "vapp_mms.xml"/>
	
	
    <STRING id="STR_ID_VAPP_MMS_MMS_SETTINGS"/>
    <STRING id="STR_ID_VAPP_MMS_MESSAGE_SETTINGS_COMPOSE"/>
    <STRING id="STR_ID_VAPP_MMS_MESSAGE_SETTINGS_RETRIEVAL"/>	
    <STRING id="STR_ID_VAPP_MMS_MMS_PREFER_STORAGE"/>
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_ANNONYMOUS"/>
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_ADVERTISMENT"/>
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_ROAMING"/>
    <STRING id="STR_ID_VAPP_MMS_SECONDS"/>
    <STRING id="STR_ID_VAPP_MMS_USER_DEFINED" />
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_DEFAULT_SLIDE_TIMING"/>
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_CREATION_MODES"/>
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_IMAGE_RESIZE"/>
    <STRING id="STR_ID_VAPP_MMS_DELIVERY_REPORT"/>
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_READ_REPORT"/>
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_VALIDITY_PERIOD"/>
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_DELIVERY_TIME"/>
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_HOME_NETWORK"/>
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_RET_DEILIVERY_REPORT"/>
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_RET_READ_REPORT"/>
    <STRING id="STR_ID_VAPP_MMS_MMS_PREFER_STORAGE_PHONE"/>
    <STRING id="STR_ID_VAPP_MMS_MMS_PREFER_STORAGE_CARD"/>
    <STRING id="STR_ID_VAPP_MMS_MMS_NO_MEM_CARD"/>
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_RESTRICTED"/>
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_WARNING"/>
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_FREE"/>
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_1_HR"/>
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_6_HRS"/>
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_12_HRS"/>
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_1_DAY"/>
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_1_WEEK"/>
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_IMMEDIATE"/>
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_DELV_1_HR"/>
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_DELV_2_HR"/>
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_DELV_12_HRS"/>
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_DELV_24_HRS"/>
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_AS_HOME"/>
    <STRING id="STR_ID_VAPP_MMS_DEFFERED" />
    <STRING id="STR_ID_VAPP_MMS_SETTINGS_REJECTIVE"/> 
    <STRING id="STR_ID_VAPP_MMS_DATA_ACCOUNT"/> 
    <STRING id="STR_ID_VAPP_MMS_MESSAGE_FILTER"/> 
    <STRING id="STR_ID_VAPP_MMS_PRIORITY"/> 
    <STRING id="STR_ID_VAPP_MMS_SIM1" />
    <STRING id="STR_ID_VAPP_MMS_SIM2" />
    <STRING id="STR_ID_VAPP_MMS_REQUEST_REPORT_FOR_SENT" />
    <STRING id="STR_ID_VAPP_MMS_SECOND" />
    
    
    <STRING id="STR_ID_VAPP_MMS_SIZE" />
    <STRING id="STR_ID_VAPP_MMS_KB" />
    <STRING id="STR_ID_VAPP_MMS_READ_ONLY_BY_JAVA" />
    <STRING id="STR_ID_VAPP_MMS_NO_SUBJECT" />
    <STRING id="STR_ID_VAPP_MMS_BYTES" />
    <STRING id="STR_ID_VAPP_MMS_COPY_MESSAGES" />
    #ifdef __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__
    <STRING id="STR_ID_VAPP_MMS_ARCHIVE" />
    #endif
    <STRING id="STR_ID_VAPP_MMS_COPY_TO_CARD" />
    <STRING id="STR_ID_VAPP_MMS_COPY_TO_PHONE" />
    <STRING id="STR_ID_VAPP_MMS_COPIED_TO_PHONE" />
    <STRING id="STR_ID_VAPP_MMS_COPIED_TO_ARCHIVE" />
    <STRING id="STR_ID_VAPP_MMS_COPIED_TO_CARD" />
#ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__
    <STRING id="STR_ID_VAPP_MMS_REPORTS" />
    <STRING id="STR_ID_VAPP_MMS_NO_REPORTS" />

#endif
    <STRING id="STR_ID_VAPP_MMS_CORRUPTED_MESSAGE" />
    <STRING id="STR_ID_VAPP_MMS_CONTINUE" />

    <STRING id="STR_ID_VAPP_MMS_SLIDE_TIME_ZERO_ERROR"/>
    	
<!-----------------------------------------------------FTO MMS STRINGS--------------------------------------------------------------->
	<STRING id="STR_ID_VAPP_MMS_SUBJECT" />
	<STRING id="STR_ID_VAPP_MMS_VIEW_OBJECT"  />
	<STRING id="STR_ID_VAPP_MMS_OBJECT_TBAR"  />
	<STRING id="STR_ID_VAPP_MMS_USE_DETAIL"  />
	#ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
	<STRING id="STR_ID_VAPP_MMS_DETAIL_TBAR"  />
	#endif
	<STRING id="STR_ID_VAPP_MMS_SLIDE"  />
	<STRING id="STR_ID_VAPP_MMS_SEND_EMAIL" />
	<STRING id="STR_ID_VAPP_MMS_SAVE_TO_BOOKMARK" />
	<STRING id="STR_ID_VAPP_MMS_ADD_AS_NEW_CONTACT" />
	<STRING id="STR_ID_VAPP_MMS_ADD_AS_EXISTING_CONTACT" />
	<STRING id="STR_ID_VAPP_MMS_GO_TO_URL" />
	<STRING id="STR_ID_VAPP_MMS_EDIT_BEFORE_CALL" />
	<STRING id="STR_ID_VAPP_MMS_SEND_MESSAGE" />
	<STRING id="STR_ID_VAPP_MMS_VIEWER_SEND_RR_CONFIRM" />
	<STRING id="STR_ID_VAPP_MMS_VIEWER_SEND_RR_CONFIRM_DONT_SEND" />
	<STRING id="STR_ID_VAPP_MMS_SIM_INVALID" />
	<STRING id="STR_ID_VAPP_MMS_VIEWER_TEXT_STRIPPED" />
	<STRING id="STR_ID_VAPP_MMS_TRUNCATE_NUMBER" />
	<STRING id="STR_ID_VAPP_MMS_URL_TOO_LONG" />
	<STRING id="STR_ID_VAPP_MMS_VIEWER_APP" />
	<STRING id="STR_ID_VAPP_MMS_VIEWER_FILE_ERROR" />
	<STRING id="STR_ID_VAPP_MMS_VIEWER_OUT_OF_MEMORY" />
    <STRING id="STR_ID_VAPP_MMS_WRITE_MESSAGE" />
	<STRING id="STR_ID_VAPP_MMS_DEFAULT_DATA_ACCOUNT" />
  	<STRING id="STR_ID_VAPP_MMS_RESULT_FAIL_MAX_MSG_NUM_REACHED" />
        <STRING id="STR_ID_VAPP_MMS_RESULT_FAIL_MAX_MSG_SIZE_REACHED" />
        <STRING id="STR_ID_VAPP_MMS_RESULT_FAIL_FILE_IN_USE" />
        <STRING id="STR_ID_VAPP_MMS_RESULT_FAIL_FILE_IO" />
        <STRING id="STR_ID_VAPP_MMS_RESULT_FAIL_UNSUPPORT_CONTENT" />
	<STRING id="STR_ID_VAPP_MMS_RESULT_FAIL_FILE_CORRUPTED" />
  	<STRING id="STR_ID_VAPP_MMS_RESULT_FAIL_INVALID_PARAMETER" />
  	<STRING id="STR_ID_VAPP_MMS_RESULT_FAIL_MAX_SLIDE_NUM_REACHED" />
  	<STRING id="STR_ID_VAPP_MMS_RESULT_FAIL_MAX_ATTACHMENT_NUM_REACHED" />
 	<STRING id="STR_ID_VAPP_MMS_RESULT_FAIL_INVALID_MSGID" />
  	<STRING id="STR_ID_VAPP_MMS_RESULT_FAIL_INVALID_FOLDER" />
 	<STRING id="STR_ID_VAPP_MMS_RESULT_FAIL_PARSE" />
  	<STRING id="STR_ID_VAPP_MMS_RESULT_FAIL_MSGID_IS_USING" />
  	<STRING id="STR_ID_VAPP_MMS_RESULT_FAIL_CREATION_MODE_MAX_MSG_SIZE_REACHED" />
   	<STRING id="STR_ID_VAPP_MMS_RESULT_FAIL_FILE_LARGE" />
  	<STRING id="STR_ID_VAPP_MMS_ROOT_DIR_FULL" />
  	<STRING id="STR_ID_VAPP_MMS_MMA_RESULT_FAIL" />
	<STRING id="STR_ID_VAPP_MMS_CONTACT_TO" />
	<STRING id="STR_ID_VAPP_MMS_CONTACT_CC" />
	<STRING id="STR_ID_VAPP_MMS_CONTACT_BCC" />
	<STRING id="STR_ID_VAPP_MMS_CONTACT_CC_RECIPIENTS" />
	<STRING id="STR_ID_VAPP_MMS_CONTACT_BCC_RECIPIENTS" />	
#ifdef __MMI_URI_AGENT__
        <STRING id="STR_ID_VAPP_MMS_SEND_MMS_CONFIRM"/>
#endif 
 	<STRING id="STR_ID_VAPP_MMS_NOTIFICATION_CORRUPT" />
  	<STRING id="STR_ID_VAPP_MMS_NOTIFICATION_UNRECOGNIZED" />
        <STRING id="STR_ID_VAPP_MMS_NOTIFICATION_EXPIRED" />
        <STRING id="STR_ID_VAPP_MMS_RESEND" />
        <STRING id="STR_ID_VAPP_MMS_RESTRICTED_MODE" />
        <STRING id="STR_ID_VAPP_MMS_MODE_WARNING_CONFIRM" />
       <STRING id="STR_ID_VAPP_MMS_CONFM_DELETE_READ_REPORT_MMS" />
        <STRING id="STR_ID_VAPP_MMS_DELETE_CONRM" />
	    <STRING id="STR_ID_VAPP_MMS_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE" />
        <STRING id="STR_ID_VAPP_MMS_NOT_OPEN_RECIPIENT_LIST" />
         <STRING id="STR_ID_VAPP_MMS_DELETE_TEMPLATE" />
         <STRING id="STR_ID_VAPP_MMS_PHONE_FULL" />
         <STRING id="STR_ID_VAPP_MMS_MEMORY_CARD_FULL" />
         <STRING id="STR_ID_VAPP_MMS_MEMORY_CARD_PHONE_BOTH_FULL" />  
          <STRING id="STR_ID_VAPP_MMS_SAVE_TO_MEMORY_CARD" />     
          <STRING id="STR_ID_VAPP_MMS_SAVE_TO_PHONE" />    


#ifndef __MMI_MMS_TEMPLATES_NUM__
#define __MMI_MMS_TEMPLATES_NUM__ 5
#endif
	#if (__MMI_MMS_TEMPLATES_NUM__>0)
    	<STRING id="STR_ID_VAPP_MMS_TEMPLATES_TITLE_01" />
	#endif
	#if (__MMI_MMS_TEMPLATES_NUM__>1)
		<STRING id="STR_ID_VAPP_MMS_TEMPLATES_TITLE_02" />
	#endif
	#if (__MMI_MMS_TEMPLATES_NUM__>2)
		<STRING id="STR_ID_VAPP_MMS_TEMPLATES_TITLE_03" />
	#endif
	#if (__MMI_MMS_TEMPLATES_NUM__>3)
		<STRING id="STR_ID_VAPP_MMS_TEMPLATES_TITLE_04" />
	#endif
	#if (__MMI_MMS_TEMPLATES_NUM__>4)
		<STRING id="STR_ID_VAPP_MMS_TEMPLATES_TITLE_05" />
	#endif
	#if (__MMI_MMS_TEMPLATES_NUM__>5)
		<STRING id="STR_ID_VAPP_MMS_TEMPLATES_TITLE_06" />
	#endif
	#if (__MMI_MMS_TEMPLATES_NUM__>6)
		<STRING id="STR_ID_VAPP_MMS_TEMPLATES_TITLE_07" />
	#endif
	#if (__MMI_MMS_TEMPLATES_NUM__>7)
		<STRING id="STR_ID_VAPP_MMS_TEMPLATES_TITLE_08" />
	#endif
	#if (__MMI_MMS_TEMPLATES_NUM__>8)
		<STRING id="STR_ID_VAPP_MMS_TEMPLATES_TITLE_09" />
	#endif
	#if (__MMI_MMS_TEMPLATES_NUM__>9)
		<STRING id="STR_ID_VAPP_MMS_TEMPLATES_TITLE_10" />
	#endif

	
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define MMS_ROOT_PATH RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\"
#ifdef __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__
        <IMAGE id="IMG_ID_VENUS_MMS_ARCHIVE">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Archive.png"</IMAGE>
#endif        
        <IMAGE id="IMG_ID_VENUS_MMS_ATTACHMENT">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Attachment.png"</IMAGE>
        <IMAGE id="IMG_ID_VENUS_MMS_DRAFT">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Drafts.png"</IMAGE>
        <IMAGE id="IMG_ID_VENUS_MMS_FAIL">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Fail.png"</IMAGE>
        <IMAGE id="IMG_ID_VENUS_MMS_HIGH_PRIORITY"> MMS_ROOT_PATH"High_Priority_MMS.png" </IMAGE>
        <IMAGE id="IMG_ID_VENUS_MMS_LOW_PRIORITY">MMS_ROOT_PATH"Low_Priority_MMS.png"</IMAGE>
        <IMAGE id="IMG_ID_VENUS_MMS_NORMAL_PRIORITY">MMS_ROOT_PATH"Normal_MMS.png"</IMAGE>
        <IMAGE id="IMG_ID_VENUS_MMS_IMAGE_FILES">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Image_Files.png"</IMAGE>
        <IMAGE id="IMG_ID_VENUS_MMS_INBOX">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Inbox.png"</IMAGE>
        <IMAGE id="IMG_ID_VENUS_MMS_JAD">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\JAD.png"</IMAGE>
        <IMAGE id="IMG_ID_VENUS_MMS_JAVA">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Java_MMS.png"</IMAGE>
        <IMAGE id="IMG_ID_VENUS_MMS_OUTBOX">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Outbox.png"</IMAGE>
    #ifdef __COSMOS_MMS_VIEWER_CONTACT_BAR_STATUS_ICON__	
        <IMAGE id="IMG_ID_VENUS_MMS_RECEIVE">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Receive.png"</IMAGE>
        <IMAGE id="IMG_ID_VENUS_MMS_SEND">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Send.png"</IMAGE>
    #endif
        <IMAGE id="IMG_ID_VENUS_MMS_SENDBOX">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Sendbox.png"</IMAGE>
        <IMAGE id="IMG_ID_VENUS_MMS_SENDING">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Sending.png"</IMAGE>
        <IMAGE id="IMG_ID_VENUS_MMS_TEXT_FILES">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Text_Files.png"</IMAGE>
        <IMAGE id="IMG_ID_VENUS_MMS_UNKNOWN_FILE">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Unknow_File.png"</IMAGE>
#ifdef __MMI_VCALENDAR__        
        <IMAGE id="IMG_ID_VENUS_MMS_VCALENDAR_FILE">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Vcalendar_File.png"</IMAGE>
#endif
#ifdef __MMI_VCARD__        
        <IMAGE id="IMG_ID_VENUS_MMS_VCARD_FILE">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Vcard_File.png"</IMAGE>
#endif
#ifndef __MMI_MESSAGE_SLIM__        
        <IMAGE id="IMG_ID_VENUS_MMS_VIDEO_FILE">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Video_File.png"</IMAGE>
#endif
        <IMAGE id="IMG_ID_VENUS_MMS_AUDIO_FILE">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Audio_Files.png"</IMAGE>               
        <IMAGE id="IMG_ID_VENUS_MMS_WAITING">RES_IMG_ROOT"\\\\Common\\\\ListIcon\\\\Waiting.png"</IMAGE>
#ifdef __DRM_SUPPORT__					
        <IMAGE id="IMG_ID_VENUS_MMS_DRM_DEFAULT">RES_IMG_ROOT"\\\\Message\\\\DRM_Default.png"</IMAGE>
#endif        
		<IMAGE id="IMG_ID_VENUS_MMS_SEND_FAIL">RES_IMG_ROOT"\\\\Common\\\\ListIcon\\\\Fail.png"</IMAGE>
        
        <IMAGE id="IMG_ID_VENUS_MMS_COPY_TO_PHONE">RES_IMG_ROOT"\\\\Message\\\\ToolbarIcon\\\\Copy_To_Phone.png"</IMAGE>

        <IMAGE id="IMG_ID_VENUS_MMS_RESEND">RES_IMG_ROOT"\\\\Message\\\\ToolbarIcon\\\\Resend_MSG.png"</IMAGE>
        <IMAGE id="IMG_ID_VENUS_MMS_USE">RES_IMG_ROOT"\\\\Message\\\\ToolbarIcon\\\\Use.png"</IMAGE>
    #ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
        <IMAGE id="IMG_ID_VENUS_MMS_USE_DETAIL">RES_IMG_ROOT"\\\\Message\\\\ToolbarIcon\\\\Use_Detail.png"</IMAGE>
    #endif
        
       #define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\Message\\\\ToolbarIcon\\\\"    
        <IMAGE id="IMG_ID_VAPP_MMS_RESEND">ROOT_PATH"Resend_MSG.png"</IMAGE>    
        <IMAGE id="IMG_ID_VAPP_MMS_CALL">ROOT_PATH"Call.png"</IMAGE>    
  #ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__      
         <IMAGE id="IMG_ID_VAPP_MMS_REPORTS">ROOT_PATH"Report.png"</IMAGE> 
  #endif       
        
        <IMAGE id="IMG_ID_VENUS_MMS_CORRUPT_IMAGE">RES_IMG_ROOT"\\\\Message\\\\Corrupted.png"</IMAGE>
        <IMAGE id="IMG_ID_VAPP_MMS_STATUS_ICON_REPORTS">RES_IMG_ROOT"\\\\Message\\\\StatusIcon\\\\Message_Report.png"</IMAGE>
        

<!-----------------------------------------------------FTO MMS ICONS----------------------------------------------------------------->
	<IMAGE id="IMG_ID_VENUS_MMS_TEXT_FILES">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Text_Files.png"</IMAGE>
        <IMAGE id="IMG_ID_VENUS_MMS_UNKNOWN_FILE">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Unknow_File.png"</IMAGE>
    #ifdef __MMI_VCALENDAR__    
        <IMAGE id="IMG_ID_VENUS_MMS_VCALENDAR_FILE">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Vcalendar_File.png"</IMAGE>
    #endif
    #ifdef __MMI_VCARD__     
        <IMAGE id="IMG_ID_VENUS_MMS_VCARD_FILE">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Vcard_File.png"</IMAGE>
    #endif
    #ifndef __MMI_MESSAGE_SLIM__    
        <IMAGE id="IMG_ID_VENUS_MMS_VIDEO_FILE">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Video_File.png"</IMAGE>
    #endif    
        <IMAGE id="IMG_ID_VENUS_MMS_AUDIO_FILE">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Audio_Files.png"</IMAGE> 
	<IMAGE id="IMG_ID_VENUS_MMS_ATTACHMENT">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Attachment.png"</IMAGE>
	#ifdef __DRM_SUPPORT__
	<IMAGE id="IMG_ID_VENUS_MMS_DRM_DEFAULT">RES_IMG_ROOT"\\\\Message\\\\DRM_Default.png"</IMAGE>
	#endif
	<IMAGE id="IMG_ID_VENUS_MMS_USE">RES_IMG_ROOT"\\\\Message\\\\ToolbarIcon\\\\Use.png"</IMAGE>
        <IMAGE id="IMG_ID_VENUS_MMS_USE_DETAIL">RES_IMG_ROOT"\\\\Message\\\\ToolbarIcon\\\\Use_Detail.png"</IMAGE>
	<IMAGE id="IMG_ID_VENUS_MMS_VIEW_OBJECT">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Preview.png"</IMAGE>  
	
<!------------------------------------------THEME IMAGE BELOW---------------------------------------------------->
	<THEME>
		<IMAGE id="IMG_ID_VENUS_MMS_NEXT_SLIDE" desc="mms go to next slide" />         
		<IMAGE id="IMG_ID_VENUS_MMS_PREVIOUS_SLIDE" desc="mms go to previus slide" />    
		<IMAGE id="IMG_ID_VENUS_MMS_PLAY_SLIDE" desc="mms to play slide" /> 
#ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
		<IMAGE id="IMG_ID_VENUS_MMS_LAUNCH_EMAIL_D" desc="mms launch email client disable" />        
		<IMAGE id="IMG_ID_VENUS_MMS_LAUNCH_EMAIL_N" desc="mms launch email client normal" />      
		<IMAGE id="IMG_ID_VENUS_MMS_LAUNCH_EMAIL_P" desc="mms launch email client pressed" />      
		<IMAGE id="IMG_ID_VENUS_MMS_GO_TO_URL_P" desc="mms launch url pressed" />    
		<IMAGE id="IMG_ID_VENUS_MMS_GO_TO_URL_D" desc="mms launch url disable" />        
		<IMAGE id="IMG_ID_VENUS_MMS_GO_TO_URL_N" desc="mms launch url normal" />  
		<IMAGE id="IMG_ID_VENUS_MMS_SIM_CALL_D" desc="mms sim call disable" />        
		<IMAGE id="IMG_ID_VENUS_MMS_SIM_CALL_N" desc="mms sim call normal" />        
		<IMAGE id="IMG_ID_VENUS_MMS_SIM_CALL_P" desc="mms sim call pressed" />  
#endif		     
 
		<IMAGE id="IMG_ID_VENUS_MMS_SIM1_ICON" desc="mms sim1 icon" />        
		<IMAGE id="IMG_ID_VENUS_MMS_SIM2_ICON" desc="mms sim2 icon" />        
		<IMAGE id="IMG_ID_VENUS_MMS_BG_N" desc="mms button bg normal" />   
		<IMAGE id="IMG_ID_VENUS_MMS_BG_P" desc="mms button bg pressed" />    
		<IMAGE id="IMG_ID_VENUS_MMS_BG_D" desc="mms go to next disable" />     
    #ifndef __MMI_MESSAGE_SLIM__
		<IMAGE id="IMG_ID_VENUS_MMS_VIDEO_OVERLAY" desc="mms Video on first slide" />     
    #endif
    		
		<IMAGE id="IMG_ID_VENUS_MMS_DOWNLOAD" desc="mms download" />     
	    <IMAGE id="IMG_ID_VENUS_MMS_DIALOG_RESEND" desc="mms resend" />  
	    <COLOR id = "VAPP_MMS_LITEVIEW_TEXT_COLOR" desc = "MMS viewer text color"/>
	    <COLOR id = "VAPP_MMS_LITEVIEW_SUB_TEXT_COLOR" desc = "MMS viewer sub text color"/>
	    <COLOR id = "VAPP_MMS_VIEWER_TEXT_COLOR" desc = "MMS viewer text color"/>
	    <COLOR id = "VAPP_MMS_VIEWER_TEXT_BACKGROUND_COLOR" desc = "MMS viewer sub text color"/>
	</THEME>
<!------------------------------------------THEME IMAGE ABOVE---------------------------------------------------->
	

#if (__MMI_MMS_TEMPLATES_NUM__>0)
    <IMAGE id="IMG_ID_UMMS_TEMPLATES_01" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T01.gif"</IMAGE>
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>1)
    <IMAGE id="IMG_ID_UMMS_TEMPLATES_02" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T02.gif"</IMAGE>
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>2)
    <IMAGE id="IMG_ID_UMMS_TEMPLATES_03" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T03.gif"</IMAGE>
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>3)
    <IMAGE id="IMG_ID_UMMS_TEMPLATES_04" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T04.gif"</IMAGE>
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>4)
    <IMAGE id="IMG_ID_UMMS_TEMPLATES_05" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T05.gif"</IMAGE>
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>5)
    <IMAGE id="IMG_ID_UMMS_TEMPLATES_06" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T06.gif"</IMAGE>
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>6)
    <IMAGE id="IMG_ID_UMMS_TEMPLATES_07" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T07.gif"</IMAGE>
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>7)
    <IMAGE id="IMG_ID_UMMS_TEMPLATES_08" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T08.gif"</IMAGE>
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>8)
    <IMAGE id="IMG_ID_UMMS_TEMPLATES_09" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T09.gif"</IMAGE>
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>9)
    <IMAGE id="IMG_ID_UMMS_TEMPLATES_10" > CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T10.gif"</IMAGE>
#endif
   
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
#if (__MMI_MMS_TEMPLATES_NUM__>0)
    <AUDIO id="AUDIO_ID_UMMS_TEMPLATES_01" > CUST_ADO_PATH"\\\\MMS\\\\mms01.mid"</AUDIO>
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>1)
    <AUDIO id="AUDIO_ID_UMMS_TEMPLATES_02" > CUST_ADO_PATH"\\\\MMS\\\\mms02.mid"</AUDIO>
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>2)
    <AUDIO id="AUDIO_ID_UMMS_TEMPLATES_03" > CUST_ADO_PATH"\\\\MMS\\\\mms03.mid"</AUDIO>
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>3)
    <AUDIO id="AUDIO_ID_UMMS_TEMPLATES_04" > CUST_ADO_PATH"\\\\MMS\\\\mms04.mid"</AUDIO>
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>4)
    <AUDIO id="AUDIO_ID_UMMS_TEMPLATES_05" > CUST_ADO_PATH"\\\\MMS\\\\mms05.mid"</AUDIO>
#endif
#endif
		

	
	
	
	<IMAGE id="IMG_ID_VENUS_MMS_NOTIFICATION_ICON">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Notification_MMS.png"</IMAGE>   
    /* Drafts folder options end */
     <!------------------------------------------------------Other Resource---------------------------------------------------------->

</APP>



#endif