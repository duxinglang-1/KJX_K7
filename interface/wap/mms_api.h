/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   mms_api.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMS_API_H
#define _MMS_API_H

#include "kal_general_types.h"
#include "MMI_features.h"

/*Max length of address MMS solution supports*/
#define MMS_MAX_ENCODE_ADDRESS_LENGTH   122
/*Max length of subject MMS solution supports*/
#define MMS_MAX_ENCODE_SUBJECT_LENGTH   82
/*Max length of text object MMS editor supports*/
#define MMS_MAX_ENCODE_TEXT_LENGTH      1226

/* This enum is used to define MMS content class. The definition of each item can be found in MMS speicifications. */
typedef enum
{
    MMS_CONTENT_CLASS_TEXT = 0,    /* Text class */
    MMS_CONTENT_CLASS_IMAGE_BASIC, /* Image Basic class */
    MMS_CONTENT_CLASS_IMAGE_RICH,  /* Image Rich class */
    MMS_CONTENT_CLASS_VIDEO_BASIC, /* Video Basic class */ 
    MMS_CONTENT_CLASS_VIDEO_RICH,  /* Video Rich class */ 
    MMS_CONTENT_CLASS_UNKNOWN      /* Unknown class */ 
} mms_content_class_enum;

/* This enum is used to specify the type of new MMS message. It is used by mms_general_insert_hdlr(mms_content_entry_struct *). */
typedef enum
{
    MMS_NEW_ADDRESS, /* Create one MMS message with specific address. */
    MMS_NEW_FILE,	 /* Create one MMS message with specific file including image, audio, video and attachment. */
    MMS_NEW_BUFFER,  /* Create one MMS message with specific text content. */
    MMS_NEW_GENERAL, /* Create one MMS message in general manner. Please refer to the usage of mms_content_entry_struct. */
    MMS_NEW_URI      /* Create one MMS message with specific URL. */
} mms_new_type_enum;

/* This enum is used to specify the type of MMS message. */
typedef enum
{
    MMS_MSG_TYPE_MMS = 0, /* Normal MMS */
    MMS_MSG_TYPE_POSTCARD /* Postcard MMS */    
    /* Examples, we may implment them soon
    MMS_MSG_TYPE_PHOTO
    MMS_MSG_TYPE_VIDEO
    MMS_MSG_TYPE_AUDIO
    MMS_MSG_TYPE_GROUP
    */
} mms_msg_type_enum;

typedef void (*func_ptr) (void *);

/* This structure is used to specify content forward to MMS editor. */
typedef struct
{
    mms_new_type_enum mode;     /* mms_msg_type_enum */
    mms_msg_type_enum msg_type; /* mms_msg_type_enum */
    char *addr;                 /* Address encoded by UCS2 */
    char *subject;              /* Subject encoded by UCS2 */
    char *file_path;            /* File path encoded by UCS2 */
    char *text_buffer;          /* Text object encoded by UCS2 */
    func_ptr callback;          /* Callback function specified by caller of mms_content_insert_hdlr_with_callback(..) */
    void *callback_param;       /* Input paramter to callback function above. */
} mms_content_entry_struct;


/* This structure is used to contain MMS address. */
typedef struct mms_addr_struct
{    
    struct mms_addr_struct* next;       /* Previous address*/
    struct mms_addr_struct* previous;   /* Next address*/    
    kal_uint8* addr;                    /* ascii for phone number while ucs2 for email address. NULL terminator is needed */
    kal_uint8 type;                     /* mms_address_type_enum */
    kal_uint8 group;                    /* mms_address_group_type_enum */
} mms_addr_struct;

/* DOM-NOT_FOR_SDK-BEGIN */
/* Q03C MMS V01 only */
typedef struct
{
    kal_uint8 addr_num;
    mms_addr_struct* addr;
    kal_uint8* text_buffer;
    kal_uint16 text_num;
    kal_uint8* subject;
} mms_entry_write_struct;
/* DOM-NOT_FOR_SDK-END */

/* This structure is used to specify the type of MMS address. */
typedef enum
{
    MMS_ADDRESS_TYPE_PHONE_NUMBER, /* Phone number */
    MMS_ADDRESS_TYPE_EMAIL,        /* Email address */
    MMS_ADDRESS_TYPE_TOTAL_NUM     /* Max number of address type */
} mms_address_type_enum;

/* This structure is used to specify the group of MMS address. */
typedef enum
{
    MMS_ADDRESS_GROUP_TYPE_TO,         /* To group*/
    MMS_ADDRESS_GROUP_TYPE_CC,         /* Cc group*/
    MMS_ADDRESS_GROUP_TYPE_BCC,        /* Bcc group*/
    MMS_ADDRESS_GROUP_TYPE_FROM,       /* From group*/
    MMS_ADDRESS_GROUP_TYPE_TOTAL_NUM   /* Max number of address group*/
} mms_address_group_type_enum;



/* MMS Entry Function */

/*****************************************************************************
 * FUNCTION
 *  mms_is_ready 
 * DESCRIPTION
 *  This function is usedb by MMI applications, ex: filemanager, camer, USB, phonebook, ToDoList and Calendar, to check if MMS solution is ready to process requests or handle primitves. 
 * PARAMETERS
 *	void
 * PARAMETERS
 *  void
 * RETURN VALUES
 *   0  : mms solution is not ready.
 *   1  : mms solution is ready.
*****************************************************************************/
extern int mms_is_ready(void);

/*****************************************************************************
 * FUNCTION
 *  goto_mms_screen 
 * DESCRIPTION
 *  This function is used by MMI application to start MMS message menu fomr matrix menu (Message => MMS). This function is only valid in Teleca Q03C MMSV01 solution.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
extern void goto_mms_screen(void);

/*****************************************************************************
 * FUNCTION
 *  mms_content_insert_hdlr 
 * DESCRIPTION
 *  This function is used by MMI applciaction to forward one media to MMS composer. MMS solution must show error dialog if MMS solution is not able to process the media forwarded.
 * PARAMETERS
 *  content_source : [IN]  Object filepath encoded by UCS2.
 * RETURNS
 *  void
*****************************************************************************/
extern void mms_content_insert_hdlr(char *content_source);

/*****************************************************************************
 * FUNCTION
 *  mms_content_insert_hdlr_with_callback 
 * DESCRIPTION
 *  This function is used by MMI applciaction to start MMS composer by specific content, ex:address, subject, text  and content file. MMI application is able to specify callback function. MMS solution must show error dialog if MMS solution is not able to process the media forwarded. 
 * PARAMETERS
 *  data : [IN]  information of object inserted to MMS editor.
 * RETURNS
 *  void
*****************************************************************************/
extern void mms_content_insert_hdlr_with_callback(mms_content_entry_struct *data);

/*****************************************************************************
 * FUNCTION
 *  mms_address_insert_hdlr 
 * DESCRIPTION
 *  This function is used by MMI application, ex: Phonebook, to start MMS composer by one To address specified.  MMS solution must show error dialog if MMS solution is not able to process the address forwarded. 
 * PARAMETERS
 *  address : [IN]  address encoded by UCS2.
 * RETURNS
 *  void
*****************************************************************************/
extern void mms_address_insert_hdlr(char *address);

/*****************************************************************************
 * FUNCTION
 *  mms_address_insert_hdlr_with_callback
 * DESCRIPTION
 *  This function is used by MMI application, ex: Phonebook, to start MMS composer for more than one To address .  Caller should provide the callback functon to get the address one by one. 
 * PARAMETERS
 *  address : [IN]  address encoded by UCS2.
 * RETURNS
 *  void
*****************************************************************************/
extern void mms_address_insert_hdlr_with_callback(kal_uint8 addr_count, void *get_address_callback);

/*****************************************************************************
 * FUNCTION
 *  mms_text_insert_hdlr 
 * DESCRIPTION
 *  This function is used by MMI application, ex: Browser Bookmark, to start MMS composer by subject and content of text object specified. MMS solution must show error dialog if MMS solution is not able to process the sibject and text forwarded. 
 * PARAMETERS
 *  subject 		: [IN] Subject encoded by UCS2.
 *  subject_len : [IN] Number of UCS2 character of subject.
 *  text 				: [IN] Text encoded by UCS2.
 *  text_len 		: [IN] Number of UCS2 character of text.
 * RETURNS
 *  void
*****************************************************************************/
extern void mms_text_insert_hdlr(char * subject, unsigned int subject_len, char * text, unsigned int text_len);

/*****************************************************************************
 * FUNCTION
 *  mms_general_insert_hdlr 
 * DESCRIPTION
 *  This function is same as mms_content_insert_hdlr_with_callback(). New MMI applications use this function instead of mms_content_insert_hdlr_with_callback(). We keep mms_content_insert_hdlr_with_callback() for backward compatibile purpose. 
 * PARAMETERS
 *  data : [IN]  information of object inserted to MMS editor.
 * RETURNS
 *  void
*****************************************************************************/
extern void mms_general_insert_hdlr(mms_content_entry_struct *data);

/*****************************************************************************
 * FUNCTION
 *  mms_is_content_forward 
 * DESCRIPTION
 *  This function is used by MMI application to query if the file is able to forward to MMS composer. 
 * PARAMETERS
 *  filename : [IN]  Filepath of the to-be-forwarded object (encoded by UCS2).
 * PARAMETERS
 *  void
 * RETURN VALUES
 *   0  : The file can not be forewarded to MMS editor.
 *   1  : The file can be forewarded to MMS editor.
*****************************************************************************/
extern int mms_is_content_forward(const char *filename);

/*****************************************************************************
 * FUNCTION
 *  mms_hide_send_mms_menu 
 * DESCRIPTION
 *  This function is check if "send MMS" menu shall be hidden. Applications shall invoke this API before invoking mms_xxx_insert() "APIs to forward sutff to MMS composer".
 * PARAMETERS
 *  void
 * RETURN VALUES
 *   KAL_TRUE  : The "send menu" shall be hidden.
 *   KAL_FALSE : The "send menu" can be displayed.
*****************************************************************************/
extern kal_bool mms_hide_send_mms_menu(void);

/*****************************************************************************
 * FUNCTION
 *  mms_get_content_class 
 * DESCRIPTION
 *  This function is used by MMI application to get content class of MMS solution. 
 * PARAMETERS
 *  filter : [OUT]  filte description.
 *  option : [OUT] param2 description. 
 * RETURNS
 *  void
*****************************************************************************/
extern mms_content_class_enum mms_get_content_class(void);

/*****************************************************************************
 * FUNCTION
 *  mms_get_max_msg_size_in_restricted_mode 
 * DESCRIPTION
 *  The function is used by Unified Composer to get max message size when creation mode is restricted. 
 * PARAMETERS
 *  void
 * RETURNS
 *  The max size of mms message when creation mode is restricted.
*****************************************************************************/
extern kal_uint32 mms_get_max_msg_size_in_restricted_mode(void);

/*****************************************************************************
 * FUNCTION
 *  mms_get_max_image_resolution_in_restricted_mode 
 * DESCRIPTION
 *  This function is used by MMI application to get the max image resolution when creation mode is restricted mode. 
 * PARAMETERS
 *  width : [OUT]  max width of image resoultion when creation mode is restricted.
 *  height : [OUT] max height of image resoultion when creation mode is restricted.
 * RETURNS
 *  void
*****************************************************************************/
extern void mms_get_max_image_resolution_in_restricted_mode(kal_int32 *width, kal_int32 *height);

/*****************************************************************************
 * FUNCTION
 *  mms_send_msg 
 * DESCRIPTION
 *  This function is used by Unified Message Composer application to inform MMs solution that it wants to send one MMS message. If MMS solution is not able to hande this MMS message, it has to show error popup to user. 
 * PARAMETERS
 *  simid		: [IN] Use SIM1 or SIM2 to send the MMS message.
 *  msg_id	: [IN] Identifier of MMS message to be sent. 
 * RETURNS
 *  void
*****************************************************************************/
extern kal_uint8 mms_send_msg(kal_int32 simid/* 0: SIM1, 1:SIM2 */,kal_uint32 msg_id, kal_uint8 storage_type, kal_uint16 app_id);

/*****************************************************************************
 * FUNCTION
 *  mms_is_reentrant 
 * DESCRIPTION
 *  This function is used by MMI application to query if user is able to reenter MMS screen again (Reenterant issue). Currenlty, Unified Message application will invoke this function when user wants to enter Message menu in MT call. 
 * PARAMETERS
 *  filter : [OUT]  filte description.
 *  option : [OUT] param2 description. 
 * RETURN VALUES
 *   0  : User is not able to reenter MMS screen again.
 *   1  : User is able to reenter MMS screen again.
*****************************************************************************/
extern int mms_is_reentrant(void);

#ifdef __MMI_MMS_IN_UM__
/*****************************************************************************
 * FUNCTION
 *  mms_um_entry_msg 
 * DESCRIPTION
 *  This function is used by Unified Message to inform MMs solution that user choose one MMS message. MMS solution could display option menu for this MMS message or directly play this MMS message. If MMS solution is not able to hande this MMS message, it has to show error popup to user. 
 * PARAMETERS
 *  msg_box_type 	: [IN] Specify which folder the MMS user highlights stays in. The format of msg_box_type is UmMsgBoxType defined in UnifiedMessageGprot.h.
 *  msg_id 				: [IN] Specify the identifier of MMS which user highlights. 
 *  key_code			:	[IN] Specify how user access this MMS (from CSK or LSK). The format of key_codes is mmi_keypads_enum defined in GlobalConstants.h.
 * RETURNS
 *  void
*****************************************************************************/
extern  kal_uint16 mms_um_entry_msg(void * );

/*****************************************************************************
 * FUNCTION
 *  mms_um_entry_write_msg 
 * DESCRIPTION
 *  This function is used by Unifed Message application to inform that MMS solution that user wants to start one MMS composer. This function may not valid in all MMS solution (Q03CMMSV01: Support, Q03CMMSV02: Not Support). If MMS solution is not able to hande this request, it has to show error popup to user. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
extern void mms_um_entry_write_msg(void);

/*****************************************************************************
 * FUNCTION
 *  mms_um_entry_template 
 * DESCRIPTION
 *  This function is used by Unified Message application to inform MMS solution that user wants to enter MMS template menu. MMS solution has to show menu of MMS template message. If MMS solution is bot able to process tis request, it has to show error popup to user.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
extern void mms_um_entry_template(void);

/*****************************************************************************
 * FUNCTION
 *  mms_um_entry_setting 
 * DESCRIPTION
 *  This function is used by Unified Message application to inform MMS solution that user wants to enter MMS settings menu. MMS solution has to show menu of MMS settings. If MMS solution is bot able to process tis request, it has to show error popup to user.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
extern void mms_um_entry_setting(void);
#endif /*__MMI_MMS_IN_UM__*/


/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef __MMI_URI_AGENT__
/*This is for Q03CMMSV01 only*/
extern void mms_uri_insert_hdlr(kal_uint32 ura_appid,char * url,char * param,kal_uint32 options,void * cb);
extern void mms_uri_insert_hdlr_ext(void);
#endif /*__MMI_URI_AGENT__*/
/* DOM-NOT_FOR_SDK-END */

#ifdef __MMI_MMS_FALLBACK__
/*****************************************************************************
 * FUNCTION
 *  mms_refresh_profile 
 * DESCRIPTION
 *  This function is refresh MMS profile related to sim card. BGSR (MMS background send & receive application uses this function to perform bearer recovery mechanism)
 * PARAMETERS
 *  simid : [IN]  Specify which profile of sim card shall be refreshed. (0: SIM1, 1: SIM2)
 * RETURNS
 *  void
*****************************************************************************/
extern void mms_refresh_profile(kal_int32 simid/* 0: SIM1, 1:SIM2 */);
#endif /*__MMI_MMS_FALLBACK__*/

#if (defined(MMS_SUPPORT) && defined(OBIGO_Q03C_MMS_V01))
extern kal_bool mmi_mms_is_mms_can_enter(void);
#endif

#endif /*_MMS_API_H*/
