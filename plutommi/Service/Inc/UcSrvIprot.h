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
 * UcSrvIprot.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file have all Service interfaces define to the application for Unified Composer.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _UNIFIED_COMPOSER_SRV_IPROT_H
#define _UNIFIED_COMPOSER_SRV_IPROT_H

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))

/*Temp Definition for save msg compile option */
//#define __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
#include "gui_config.h" /* For GUI_INPUT_BOX_MAX_LENGTH */

#include "custom_mmi_default_value.h"   /* For MMI_PHB_NAME_LENGTH */
#include "custom_wap_config.h"
#include "custom_uc_config.h"   /* For MMI_UC_CUSTOM_MAX_ADDR_LEN */

#include "customer_ps_inc.h"
#include "mmsadp.h"
#include "mma_struct.h"
#ifdef __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
#include "xml_def.h"
#endif
//#include "UMGprot.h"
#include "UmSrvDefs.h"
#include "mma_api.h"

/* UC folder name for tem use. */
#define SRV_UC_FOLDER_NAME "@UC"
/* UC text object file name start alphabet. */
#define SRV_UC_TEXT_FILENAME "T"
/* UC text object file name extension. */
#define SRV_UC_TEXT_FILEEXT "txt"
/* UC image object file name start alphabet. */
#define SRV_UC_IMAGE_FILENAME "I"
/* UC image object file name start alphabet. */
#define SRV_UC_VCARD_FILENAME "V"
/* UC signature image object file name start alphabet. */
#define SRV_UC_SIGNATURE_IMAGE_FILENAME "S"
/* UC image object file name extension. Cuurent support only for jpg. */
#define SRV_UC_IMAGE_FILEEXT "jpg"
/* UC image object file name extension. Cuurent support only for jpg. */
#define SRV_UC_VCARD_FILEEXT "vcf"
/* UC xml file name start alphabet. Needed to communicate with MMA module. */
#define SRV_UC_XML_FILENAME "X"
/* UC xml file extension. Needed to communicate with MMA module. */
#define SRV_UC_XML_FILEEXT "xml"
#ifdef __MMI_UC_USE_ASM__
/* UC ASM text file name. */
#define SRV_UC_ASM_TEXT_FILENAME "T_ASM"
#endif /* __MMI_UC_USE_ASM__ */
#define SRV_UC_ASM_TEXT_RE_FILENAME "RE_ASM"

/* Max XMl temp string length UC supports. */
#define SRV_UC_XML_TEMP_STR_LEN (1024)

/* UC temp folder path. */
#define SRV_UC_MAKE_FOLDER_PATH(x, i)           \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\%s%03d", \
      SRV_UC_FOLDER_DRV, SRV_UC_FOLDER_NAME, i);
/* UC generated names for text file with its complete path. */
#define SRV_UC_MAKE_TEXT_FILE_PATH(x, d, i)               \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\%s%03d\\%s%03d.%s",\
      SRV_UC_FOLDER_DRV, SRV_UC_FOLDER_NAME, i, SRV_UC_TEXT_FILENAME, d, SRV_UC_TEXT_FILEEXT );
/* UC generated names for image file with its complete path. */
#define SRV_UC_MAKE_IMAGE_FILE_PATH(x, d, i)              \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\%s%03d\\%s%03d.%s",\
      SRV_UC_FOLDER_DRV, SRV_UC_FOLDER_NAME, i, SRV_UC_IMAGE_FILENAME, d, SRV_UC_IMAGE_FILEEXT );
/* UC generated names for xml file with its complete path. */
#ifdef __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
#define SRV_UC_MAKE_MMS_XML_FILE_PATH(x, d, i)            \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\%s%03d\\%s%03d.%s",\
      SRV_UC_FOLDER_DRV, SRV_UC_FOLDER_NAME, i, SRV_UC_XML_FILENAME, d, SRV_UC_XML_FILEEXT );
#endif     
#define SRV_UC_MAKE_VCARD_FILE_PATH(x, d, i)              \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\%s%03d\\%s%03d.%s",\
      SRV_UC_FOLDER_DRV, SRV_UC_FOLDER_NAME, i, SRV_UC_VCARD_FILENAME, d, SRV_UC_VCARD_FILEEXT );


/* Max filename length for temp files UC supports. */
#define SRV_UC_MAX_TEMP_FILE_LEN ((25 + 1) * ENCODING_LENGTH)

/* MAx length of subject array to use. */
#define SRV_UC_MAX_SUBJECT_ARRAY_LEN 60

/* This structure contains the linked list for objects and other information related to actual location of the object. The structure maintains the linked list of all objects currently added to the MMS, and finally it is used to create the MMS PDU XML */
//typedef struct srv_uc_object_struct_t
//{
  //  struct srv_uc_object_struct_t *next;        /* Next object */
   // struct srv_uc_object_struct_t *previous;    /* Previous object */
   // U32 encoding;                               /* mma_charset_enum */
   // U32 offset;                                 /* Offset in case virtual file */
   // U32 size;                                   /* File size for non-text object. UTF8 size for text object */
	//
  //  U16 *file_path;                             /* NULL terminator is needed. */
  //  U16 *file_name;                             /* File actual name */
   // U32 id;                                     /* object id is a unique number in object list */
    //U16 reference_count;                        /* Refrence count if any */
   // srv_uc_object_type type;                    /* srv_uc_object_type */
    //U8 drm_type;                                /* mma_drm_type_enum */
   // BOOL is_virtual_file;                       /* Virtual file flag */
//} srv_uc_object_struct;

/* This structure contains the linked list for attachment object information. */
//typedef struct srv_uc_attachment_info_struct_t
//{
  //  struct mma_mms_attachment_info_struct_t *next;       /* Next attachment */
    //struct mma_mms_attachment_info_struct_t *previous;   /* Previous attachment */
    //mma_mms_object_struct *object;                       /* srv_uc_object_struct object information *//
//} srv_uc_attachment_info_struct;

/* This structure contains the object attributes information. It contain the object timing proprities. */
//typedef struct
//{
   // mma_mms_object_struct *object;   /* Object info srv_uc_object_struct */
   // U32 id;                         /* Object id */
   // U32 begin;                      /* Object begin time */
  //  U32 end;                        /* Object end time */
//
//} srv_uc_object_info_struct;

/* This structure contains the text object attributes information. Like timings and color. */
//typedef struct
//{
  //  mma_mms_object_struct *object;   /* Object info srv_uc_object_struct */
  //  U32 id;                         /* Object id */
   // U32 background_color;           /* Bg color */
  //  U32 foreground_color;           /* Text color */
  //  U16 char_count;                 /* Total Character Count */
  //  U16 utf8_msg_len;               /* Msg Len in UTF8 */
  //  U16 extension_char_count;       /* EXT CHAR Count */
  //  U16 UCS2_count;                 /* UCS2 Count except any extension char */
  //  U32 begin;                      /* Object begin time */
   // U32 end;                        /* Object end time */
//} srv_uc_text_object_info_struct;

/* This structure contains the linked list of ref tag object with there attributes information. On same slide UC support other similar media type as ref tag. */
//typedef struct srv_uc_ref_obj_info_struct_t
//{
  //  struct srv_uc_ref_obj_info_struct_t *next;      /* Next object */
  //  struct srv_uc_ref_obj_info_struct_t *previous;  /* Previous object */
  //  mma_mms_object_struct *object;                   /* Point to assiciated object */
  //  U32 id;                                         /* Object id */
  //  U32 begin;                                      /* Object begin time */
  //  U32 end;                                        /* Object end time */
//} srv_uc_ref_obj_info_struct;

/* This structure contains the linked list of slide data and the object information of taht slide. */
//typedef struct srv_uc_slide_struct_t
//{
   // struct srv_uc_slide_struct_t *next;     /* Next slide */
   // struct srv_uc_slide_struct_t *previous; /* Previous object */
   // mma_mms_slide_text_object_struct text;    /* Text object info on slide */
	//
  //  mma_mms_slide_object_struct image;        /* Image object info on slide */
  //  mma_mms_slide_object_struct audio;        /* Audio object info on slide */
   // mma_mms_slide_object_struct video;        /* Video object info on slide */
    //mma_mms_slide_ref_object_struct *ref_head;   /* Ref tag object link list info on slide */
  //  U32 duration;                           /* Duration of slide */
   // U8 slide_num;                           /* Slide number */
//} srv_uc_slide_struct;

typedef kal_int8 *(*uc_func_ptr_general_insert_get_img_fn) (kal_uint16 index, WCHAR*, MMI_BOOL);

/* This structure contains complete composer msg data. This contains complete information of a message during its composition phase. */
typedef struct
{
    U32 msg_size;                                           /* total = header + body */
    U32 msg_size_without_text_buffer;                       /* total - text */
    U32 msg_body_size;                                      /* total = header + body */
    //U32 background_color;                                   /* Bg color */
    //U32 foreground_color;                                   /* Fg color */
    srv_uc_addr_struct *to_head;                            /* To address list */
   //srv_uc_addr_struct *cc_head;                            /* Cc address list */
   // srv_uc_addr_struct *bcc_head;                           /* Bcc address list */
    srv_uc_addr_struct *from;                               /* From address list */
    U16 *temp_subject;                                      /* Temp subject string use internally */
#ifdef __MMI_MMS_INSERT_SENDER_ADDR_FROM_SIM__
	U16 *owner;												/* getting owner number from sim */
#endif
	U8 to_num;                                              /* Total addresses */
    BOOL read_report;                                       /* Read report flag */
    BOOL delivery_report;                                   /* Delivery report flag */
    U8 priority;                                            /* mma_priority_enum */
    U8 expiry_time;                                         /* srv_uc_expiry_time_enum */
    BOOL hide_sender;                                       /* Hide sender flag */
    U8 delivery_time;                                       /* srv_uc_delivery_time_enum */
    U8 msg_class;                                           /* Msg class for test code */
    U8 best_page_duration;                                  /* Best page duration flag */
   // mma_mms_slide_struct *slide_head;                        /* Slide list head */
   // mma_mms_slide_struct *current_slide;                     /* Current slide pointer */
   //mma_mms_object_struct *object_head;                      /* Object list head */
   // mma_mms_attachment_info_struct *attachment_head;         /* Attachment list head */
    U32 slide_timing;                                       /* Slide time */
    BOOL signature_inserted;                                /* Signature state flag */
    srv_uc_insert_signature_result_enum fail_to_insert_signature;       /* srv_uc_insert_signature_result_enum */
    BOOL signature_in_last_slide;                           /* For user can not add slide after signature */
    BOOL display_no_resize;
   // U8 total_slide_num;                                     /* Total slides */
    U8 current_slide_num;                                   /* Current slide number */
  //  U8 total_object_num;                                    /* Total objects */
   // U8 total_attachment_num;                                /* Total attachments */
  //  U16 total_ref_num_in_list;                              /* Total ref tag objects */
    //srv_uc_layout_enum layout;                              /* srv_uc_layout_enum */
   // U8 txtfit;                                              /* Text fit flag */
 //   U8 imgfit;                                              /* Image fit flag */
//#ifdef __MMI_MMS_POSTCARD__
    //srv_postcard_context_struct postcard_recipient_info;    /* Postcard recipient list info */
	//
   // BOOL greeting_exist_flag;                               /* if there is greeting, the flag will be T */
//#endif /* __MMI_MMS_POSTCARD__ */
    BOOL auto_signature_inserted;                           /* Auto signature status */
    U16 subject[SRV_UC_MAX_SUBJECT_ARRAY_LEN + 1];                /* Subject */
	uc_func_ptr_general_insert_get_img_fn get_media_callback ;  /*Getting the media on DCD mms*/
	U8 media_count ;											/*total media forwarded from DCD App*/
	MMI_BOOL is_abort ;
    mma_mms_header_struct msg_header ;
	mma_mms_description_body_struct msg_body;
	mma_mms_description_header_struct g_msg_header;
	mma_mms_description_struct g_uc_content_info;
} srv_uc_msg_struct;

/* This structure contains some information need to keep during complete process. Like state, mode and text buffer. */
typedef struct
{
    S32 file_handle;                                  /* file handler to user */
    U8 *file_path;                                    /* file path in use */
    BOOL auto_delete_file;
    S32 current_text_file_save_result;                /* result to create text file from text buffer */
	U8 text_buffer[SRV_UC_TEXT_BUFFER_SIZE];		  /* slide text buffer */
    srv_uc_state_enum state;                          /* current state of msg */
    srv_uc_mode_change_status_enum mode;              /* fw/edit swapping mode status of the msg */
    mmi_id app_id;
} srv_uc_main_struct;

/* This structure contains some msg type informations must to check to decide its a MMS or SMS message. And what validation need to apply. */
typedef struct
{
    srv_uc_msg_type_enum curr_msg_type;         /* only SMS_PREFER and MMS_PREFER */
    srv_uc_msg_type_enum setting_msg_type;      /* only SMS_PREFER and MMS_PREFER */
    srv_uc_msg_type_enum caller_specific_msg_type;  /* Caller specific msg type if caller need to give preference */
    srv_uc_msg_type_enum backup_msg_type;   /* Backup msg type to keep history */
    srv_uc_MMS_edit_mode_enum MMS_edit_mode;    /* only for caller_specific_msg_type = MMI_UC_MSG_TYPE_MMS_ONLY */
} srv_uc_msg_type_struct;

/* This structure contains signature content list and setting. */
typedef struct
{
    U16 *text_file; /* text media */
    U16 *img_file;  /* image media */
    U16 *audio_file;    /* audio media*/
    U16 *video_file;    /* video media */
    BOOL enable;    /* signature enable or disable setting */
} srv_uc_mms_signature_struct;

/* This structure contains mms specific settings and information. */
typedef struct
{
    srv_uc_mms_signature_struct signature;  /* signature setting */
    mma_image_resizing_struct image_resize; /* image resizing enable or disable setting */
    mma_setting_struct sliding_time;    /* default min max time values */
    U32 max_mms_size;   /* max size of mms selected in compose setting to compose */
    mma_creation_mode_enum creation_mode;   /* user selected creation mode setting */
    mma_priority_enum priority;     /* default priority to set to msg */
    mma_expiry_time_enum validity_period;   /* validity period set to msg from setting */
    mma_delivery_time_enum delivery_time;   /* delivery time set to msg from setting */
    BOOL delivery_report;   /* delivery report enable or disable setting */
    BOOL read_report;   /* read report enable or disable setting */
    BOOL hide_sender;   /* hide sender enable or disable setting */
    U8 best_page_duration;  /* best page duration enable or disable setting */
    U32 duration;   /* default slide time */
} srv_uc_mms_info_struct;

/* This structure contains sms specific settings and information. */
typedef struct
{
    U16 max_gsm7bit_char_num;   /* sms default DCS max usable text length */
    U16 max_ucs2_char_num;  /* sms UCS2 DCS max usable text length */
} srv_uc_sms_info_struct;

/* This structure contains information required in interal operation while sending a msg. */
typedef struct
{
    U32 buffer_index;   /* buffer index value to read the next buffer chunk */
#ifdef __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__  
    U32 xml_file_size;  /* xml file size */
#endif
    FS_HANDLE fs;  /* xml file creation file handle */   
    U32 new_msg_id; /* newly generated the msg id of the msg in composition */
    U32 existed_msg_id; /* existing msg id of the msg already exist and operated in composer */
    srv_uc_msg_type_enum existed_msg_type;  /* msg type of the existing msg operated in composer */
    srv_uc_action_type_enum action; /* action selected on the msg */
    srv_uc_sim_id send_sim_id;  /* sim selection to send the msg */
    srv_uc_msg_truncation_type_enum content_truncated_type; /* truncation type of existing msg if existing content exceeds the limit */
    U16 curr_send_number;   /* current number to send the SMS */
} srv_uc_send_info_struct;

/* This structure contains information required in xml parsing and generation. */
#ifdef __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
typedef struct
{
    XML_PARSER_STRUCT *xml_parser;  /* xml parser structure */
    mma_mms_slide_struct *slide; /* slide link list for xml */
    mma_mms_object_struct *object;   /* object link list for xml */
    srv_uc_address_type_enum addr_type; /* address type. ex. email, phomenumber or IP */
} srv_uc_xml_struct;
#endif

//#if (MMI_MAX_SIM_NUM >= 2)kuldeep_nosim
typedef struct
{
    U32 valid_sim_id_info;
    srv_uc_action_type_enum action;
} srv_uc_dual_sim_info;
//#endif /* MMI_MAX_SIM_NUM */ 

/* This structure contains information register by composer application. */
typedef struct
{
    void *user_data;
    srv_uc_app_mem_alloc_fn app_mem_alloc_fun;  /* application memory allocation method */
    srv_uc_app_mem_free_fn app_mem_free_fun;    /* application memory deallocation method */
    srv_uc_app_mem_alloc_fn app_text_buffer_mem_alloc_fun;  /* application memory deallocation method for text buffer */
    srv_uc_app_mem_free_fn app_text_buffer_mem_free_fun;    /* application memory deallocation method for text buffer */
} srv_uc_app_registered_data_struct;

/* This structure contains information of service requests link list, from composer applications. */
typedef struct srv_uc_service_req_struct_t
{
    U32 req_id; /* application req id */
    srv_uc_app_callback_fn cb_func_p;   /* callback api to call after completing request*/
    struct srv_uc_service_req_struct_t *next;   /* service request structure link linst next pointer */
} srv_uc_service_req_struct;

/* This structure contains information of service requests link list, from composer applications. */
typedef struct
{
    void *user_data;
	srv_uc_msg_struct msg;              /* contains complete composer msg data */
    srv_uc_app_mem_free_fn free;    /* application registered deallocation function */
	srv_uc_main_struct main;    /* information need to keep during complete composition process */
	srv_uc_msg_type_struct msg_type;    /* informations must to check to decide its a MMS or SMS message */
	srv_uc_app_mem_alloc_fn alloc;  /* application registered allocation function */
	srv_uc_send_info_struct send_info;  /* contains information required in interal operation while sending a msg */
#ifdef __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
	srv_uc_xml_struct xml;  /* contains information required in xml parsing and generation */
#endif
	srv_uc_mms_info_struct mms_info;    /* contains mms specific settings and information */
	srv_uc_app_mem_alloc_fn text_buffer_alloc;  /* application registered allocation function for text buffer */
	srv_uc_app_mem_free_fn text_buffer_free;    /* application registered deallocation function for text buffer */
 //#if (MMI_MAX_SIM_NUM >= 2)kuldeep_nosim
    srv_uc_dual_sim_info sim_info;  /* dual sim information*/
 //#endif
	srv_uc_sms_info_struct sms_info;    /* contains sms specific settings and information */
	srv_uc_service_req_struct *srv_req; /* service request structure */
} srv_uc_context_struct;

typedef struct
{
    srv_uc_main_struct *main;
    srv_uc_msg_type_struct *msg_type;
    srv_uc_mms_info_struct *mms_info;
    srv_uc_sms_info_struct *sms_info;
    srv_uc_msg_struct *msg;
    srv_uc_send_info_struct *send_info;
	#ifdef __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
    srv_uc_xml_struct *xml;
	#endif
#if (MMI_MAX_SIM_NUM >= 2)
    srv_uc_dual_sim_info *sim_info;
#endif 
}srv_uc_cntxt_reference_struct;

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_uc_select_instance
 * DESCRIPTION
 *  This function initialize one instance of the Unified Composer service. And provide the instance id correcponding to that service instance to application.
 * PARAMETERS
 *  void
 * RETURNS
 *  instance id
 *****************************************************************************/
extern U32 srv_uc_select_instance(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  srv_uc_create
 * DESCRIPTION
 *  This function initialize one instance of the Unified Composer service with registered callbacks from composer application.
 *  And provide the instance id correcponding to that service instance to application.
 * PARAMETERS
 *  data : [IN] application registered callbacks at initialize time.
 * RETURNS
 *  instance id
 *****************************************************************************/
extern U32 srv_uc_create(srv_uc_app_registered_data_struct data);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_delete
 * DESCRIPTION
 *  This function de-initialize one instance of the Unified Composer service.
 * PARAMETERS
 *  instance : [IN] instance id.
 * RETURNS
 *  
 *****************************************************************************/
extern U32 srv_uc_delete(U32 instance);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_srv_main_context
 * DESCRIPTION
 *  This function returns the service main context to the application.
 * PARAMETERS
 *  instance : [IN] instance id.
 * RETURNS
 *  main context of the service
 *****************************************************************************/
extern srv_uc_main_struct *srv_uc_get_srv_main_context(U32 instance);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_srv_msg_type_context
 * DESCRIPTION
 *  This function returns the service msg type context to the application.
 * PARAMETERS
 *  instance : [IN] instance id.
 * RETURNS
 *  msg type context of the service
 *****************************************************************************/
extern srv_uc_msg_type_struct *srv_uc_get_srv_msg_type_context(U32 instance);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_srv_mms_info_context
 * DESCRIPTION
 *  This function returns the service mms info context to the application.
 * PARAMETERS
 *  instance : [IN] instance id.
 * RETURNS
 *  mms info context of the service
 *****************************************************************************/
extern srv_uc_mms_info_struct *srv_uc_get_srv_mms_info_context(U32 instance);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_srv_sms_info_context
 * DESCRIPTION
 *  This function returns the service sms info context to the application.
 * PARAMETERS
 *  instance : [IN] instance id.
 * RETURNS
 *  sms info context of the service
 *****************************************************************************/
extern srv_uc_sms_info_struct *srv_uc_get_srv_sms_info_context(U32 instance);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_srv_msg_info_context
 * DESCRIPTION
 *  This function returns the service composer msg complete info context to the application.
 * PARAMETERS
 *  instance : [IN] instance id.
 * RETURNS
 *  composer msg data info context of the service
 *****************************************************************************/
extern srv_uc_msg_struct *srv_uc_get_srv_msg_info_context(U32 instance);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_srv_send_info_context
 * DESCRIPTION
 *  This function returns the service internal info context containing sending info to the application.
 * PARAMETERS
 *  instance : [IN] instance id.
 * RETURNS
 *  send info context of the service
 *****************************************************************************/
extern srv_uc_send_info_struct *srv_uc_get_srv_send_info_context(U32 instance);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_srv_xml_info_context
 * DESCRIPTION
 *  This function returns the service xml info to the application.
 * PARAMETERS
 *  instance : [IN] instance id.
 * RETURNS
 *  send info context of the service
 *****************************************************************************/
#ifdef __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
extern srv_uc_xml_struct *srv_uc_get_srv_xml_info_context(U32 instance);
#endif

/* DOM-NOT_FOR_SDK-BEGIN */
//#if (MMI_MAX_SIM_NUM >= 2)kuldeep_nosim
extern srv_uc_dual_sim_info *srv_uc_get_srv_sim_info_context(U32 instance);
//#endif 
#ifdef __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
extern void srv_uc_xml_start_element_hdlr(U32 instance, void *data, const char *el, const char **attr, S32 error);
extern void srv_uc_xml_end_element_hdlr(U32 instance, void *data, const char *el, S32 error);
extern void srv_uc_xml_data_hdlr(U32 instance, void *data, const char *el, const char *value, int len, S32 error);
extern S32 srv_uc_create_xml_element_start(FS_HANDLE fh, U8 *element_name, U8 **attr_list);
#endif
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  srv_uc_insert_slide
 * DESCRIPTION
 *  This function to insert one page/slide in the msg context.
 * PARAMETERS
 *  instance : [IN] instance id
 *  cur_slide : [IN] current context of the slide
 * RETURNS
 *  updated slide context
 *****************************************************************************/
extern mma_mms_slide_struct *srv_uc_insert_slide(U32 instance, mma_mms_slide_struct *cur_slide);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_insert_object
 * DESCRIPTION
 *  This function to create the object from one media file.
 * PARAMETERS
 *  instance : [IN] instance id
 *  filePath : [IN] media file path
 *  object_type : [IN] type of media
 * RETURNS
 *  selected recipient entries
 *****************************************************************************/
extern mma_mms_object_struct *srv_uc_insert_object(U32 instance, S8 *filePath, srv_uc_object_type object_type);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_delete_ref_obj_info_from_list
 * DESCRIPTION
 *  This function to get the recipient context for the selected entry by index.
 * PARAMETERS
 *  instance : [IN] instance id
 *  cur_ref : [IN] current ref list pointer to remove
 * RETURNS
 *  MMI_TRUE:   Success
 *  MMI_FALSE:  Failure
 *****************************************************************************/
extern MMI_BOOL srv_uc_delete_ref_obj_info_from_list(U32 instance, mma_mms_slide_ref_object_struct *cur_ref);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_insert_object_to_slide
 * DESCRIPTION
 *  This function to get the recipient context for the selected entry by index.
 * PARAMETERS
 *  instance : [IN] instance id
 *  object : [IN] pointer to link list to objects
 *  slide : [IN/OUT] pointer to link list of slides
 *  object_type : [IN] object type
 * RETURNS
 *  MMI_TRUE:   Success
 *  MMI_FALSE:  Failure
 *****************************************************************************/
extern MMI_BOOL srv_uc_insert_object_to_slide(
                U32 instance,
                mma_mms_object_struct *object,
                mma_mms_slide_struct *slide,
                srv_uc_object_type object_type);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_insert_attachment
 * DESCRIPTION
 *  This function to add the attachment to the attachment list.
 * PARAMETERS
 *  instance : [IN] instance id
 * RETURNS
 *  pointer to link list of attachments
 *****************************************************************************/
extern mma_mms_attachment_info_struct *srv_uc_insert_attachment(U32 instance);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_insert_object_to_slide
 * DESCRIPTION
 *  This function to add the object in the attachment list.
 * PARAMETERS
 *  object : [IN] media object node
 *  attachment : [IN/OUT] pointer to link list of attachments
 * RETURNS
 *  MMI_TRUE:   Success
 *  MMI_FALSE:  Failure
 *****************************************************************************/
extern MMI_BOOL srv_uc_insert_object_to_attachment(
                mma_mms_object_struct *object,
                mma_mms_attachment_info_struct *attachment);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_ref_by_index
 * DESCRIPTION
 *  This function to insert one page/slide in the msg context.
 * PARAMETERS
 *  instance : [IN] instance id
 *  index : [IN] index of ref id
 * RETURNS
 *  updated slide context
 *****************************************************************************/
extern mma_mms_slide_ref_object_struct *srv_uc_get_ref_by_index(U32 instance, U16 index);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_ref_by_index
 * DESCRIPTION
 *  This function to delete ref media by index.
 * PARAMETERS
 *  instance : [IN] instance id
 *  index : [IN] index of ref id
 * RETURNS
 *  MMI_TRUE:   Success
 *  MMI_FALSE:  Failure
 *****************************************************************************/
extern MMI_BOOL srv_uc_delete_ref_by_index(U32 instance, U16 index);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_attachment_by_index
 * DESCRIPTION
 *  This function to get the pointer to the attachment node by index.
 * PARAMETERS
 *  instance : [IN] instance id
 *  index : [IN] index of attachment id
 * RETURNS
 *  pointer to link list of attachments
 *****************************************************************************/
extern mma_mms_attachment_info_struct *srv_uc_get_attachment_by_index(U32 instance, U16 index);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_object_in_slide
 * DESCRIPTION
 *  This function to get the pointer to the attachment node by index.
 * PARAMETERS
 *  slide : [IN] pointer to slide link list
 *  object_type : [IN] object type
 * RETURNS
 *  pointer to link list of attachments
 *****************************************************************************/
extern mma_mms_object_struct *srv_uc_get_object_in_slide(mma_mms_slide_struct *slide, srv_uc_object_type object_type);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_file_extension
 * DESCRIPTION
 *  This function to get the pointer to the start of the ext in the file path
 * PARAMETERS
 *  filePath : [IN] media file path
 * RETURNS
 *  pointer to ext in the file name
 *****************************************************************************/
extern U16 *srv_uc_get_file_extension(U16 *filePath);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_insert_ref_obj_info_to_tail
 * DESCRIPTION
 *  This function to get the recipient context for the selected entry by index.
 * PARAMETERS
 *  instance : [IN] instance id
 *  slide : [IN/OUT] pointer to link list of slides
 *  id : [IN] ref object id
 *  begin : [IN] start time
 *  end : [IN] end time
 * RETURNS
 *  pointer to the ref object link list
 *****************************************************************************/
extern mma_mms_slide_ref_object_struct *srv_uc_insert_ref_obj_info_to_tail(
                                    U32 instance,
                                    mma_mms_slide_struct *slide,
                                    U32 id,
                                    U32 begin,
                                    U32 end);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_object_by_id
 * DESCRIPTION
 *  This function to get the pointer to the attachment node by index.
 * PARAMETERS
 *  instance : [IN] instance id
 *  object_id : [IN] object id to get
 * RETURNS
 *  pointer to the node search by id in the link list of object
 *****************************************************************************/
extern mma_mms_object_struct *srv_uc_get_object_by_id(U32 instance, U32 object_id);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_delete_slide_with_object
 * DESCRIPTION
 *  This function to delete the selected slide among the link list of slides with the object.
 * PARAMETERS
 *  instance : [IN] instance id
 *  slide : [IN/OUT] pointer to perticular slide in the link list of slides
 * RETURNS
 *  MMI_TRUE:   Success
 *  MMI_FALSE:  Failure
 *****************************************************************************/
extern MMI_BOOL srv_uc_delete_slide_with_object(U32 instance, mma_mms_slide_struct *slide);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_delete_object_from_list
 * DESCRIPTION
 *  This function to delete the object from the link list of objects.
 * PARAMETERS
 *  instance : [IN] instance id
 *  object : [IN] pointer to the object need to delete in the link list of objects.
 * RETURNS
 *  MMI_TRUE:   Success
 *  MMI_FALSE:  Failure
 *****************************************************************************/
extern MMI_BOOL srv_uc_delete_object_from_list(U32 instance, mma_mms_object_struct *object);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_delete_attachment_from_list
 * DESCRIPTION
 *  This function to delete the attachment object from the link list of attachments.
 * PARAMETERS
 *  instance : [IN] instance id
 *  att : [IN] pointer to the attachment object need to delete in the link list of attachments.
 * RETURNS
 *  MMI_TRUE:   Success
 *  MMI_FALSE:  Failure
 *****************************************************************************/
extern MMI_BOOL srv_uc_delete_attachment_from_list(U32 instance, mma_mms_attachment_info_struct *att);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_add_address
 * DESCRIPTION
 *  This function to add the recipient in the UC recipient list for passed instance of service.
 * PARAMETERS
 *  instance : [IN] instance id
 *  ucs2_addr : [IN] actual recipient string
 *  type : [IN] type of address
 *  group : [IN] group id of address field
 * RETURNS
 *  MMI_TRUE:   Success
 *  MMI_FALSE:  Failure
 *****************************************************************************/
extern MMI_BOOL srv_uc_add_address(
        U32 instance,
        U8 *ucs2_addr,
        srv_uc_address_type_enum type,
        srv_uc_address_group_type_enum group);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_addr
 * DESCRIPTION
 *  This function to get the recipient context for the selected entry by index.
 * PARAMETERS
 *  instance : [IN] instance id
 *  index : [IN] selected index of the recipient
 * RETURNS
 *  selected recipient entries
 *****************************************************************************/
extern srv_uc_addr_struct *srv_uc_get_addr(U32 instance, U16 index);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_delete_all_addr
 * DESCRIPTION
 *  This function to remove all recipient list.
 * PARAMETERS
 *  instance : [IN] instance id
 * RETURNS
 *  MMI_TRUE:   Success
 *  MMI_FALSE:  Failure
 *****************************************************************************/
extern MMI_BOOL srv_uc_delete_all_addr(U32 instance);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_sms_setting
 * DESCRIPTION
 *  This function to get sms settings.
 * PARAMETERS
 *  instance : [IN] instance id
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_uc_get_sms_setting(U32 instance);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_is_email_addr_valid
 * DESCRIPTION
 *  This function to check the validity of email address.
 * PARAMETERS
 *  addr : [IN] email address string
 * RETURNS
 *  TRUE:   Success
 *  FALSE:  Failure
 *****************************************************************************/
extern BOOL srv_uc_is_email_addr_valid(U8 *addr);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_is_phone_number_valid
 * DESCRIPTION
 *  This function to check the validity of phone number address.
 * PARAMETERS
 *  strNumber : [IN] phone number string
 * RETURNS
 *  TRUE:   Success
 *  FALSE:  Failure
 *****************************************************************************/
extern BOOL srv_uc_is_phone_number_valid(S8 *strNumber);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_init_uc_folder
 * DESCRIPTION
 *  This function to init UC folder.
 * PARAMETERS
 *  instance : [IN] instance id
 * RETURNS
 *  result of the folder init
 *****************************************************************************/
extern S32 srv_uc_init_uc_folder(U32 instance);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_reset_msg
 * DESCRIPTION
 *  This function to reset UC service context for perticular instance.
 * PARAMETERS
 *  instance : [IN] instance id
 * RETURNS
 *  MMI_TRUE:   Success
 *  MMI_FALSE:  Failure
 *****************************************************************************/
extern MMI_BOOL srv_uc_reset_msg(U32 instance);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_is_pending_action
 * DESCRIPTION
 *  This function returns true if UC have pending action. Used by other application to know UC status.
 * PARAMETERS
 *  instance : [IN] instance id
 * RETURNS
 *   KAL_FALSE  : no pending action.
 *   KAL_TRUE  : pending action.
 *****************************************************************************/
extern kal_bool srv_uc_is_pending_action(U32 instance);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_is_sms_in_use
 * DESCRIPTION
 *  This function to check if the msg_id is in used (Other application need to check for this before use a msg.
 *  Because same message can not be used by two applications simultaneously)
 * PARAMETERS
 *  instance : [IN] instance id
 *  msg_id : [IN] Msg id.
 * RETURNS
 *   KAL_FALSE  : Not in use.
 *   KAL_TRUE  : In use.
 *****************************************************************************/
extern kal_bool srv_uc_is_sms_in_use(U32 instance, kal_uint32 msg_id);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_is_no_recepient
 * DESCRIPTION
 *  This function to check if there is any recipient or not in recipient list.
 * PARAMETERS
 *  instance : [IN] instance id
 * RETURNS
 *   MMI_FALSE  : No recipient.
 *   MMI_TRUE  : recipient.
 *****************************************************************************/
extern MMI_BOOL srv_uc_is_no_recepient(U32 instance);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_update_msg_size
 * DESCRIPTION
 *  This function to check, calculate and update the msg size according to changed structure.
 * PARAMETERS
 *  instance : [IN] instance id
 * RETURNS
 *  TRUE:   Success
 *  FALSE:  Failure
 *****************************************************************************/
extern MMI_BOOL srv_uc_update_msg_size(U32 instance);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_reserved_size
 * DESCRIPTION
 *  This function to check, calculate and update the msg size according to changed structure.
 * PARAMETERS
 *  instance : [IN] instance id
 * RETURNS
 *  Reserved size
 *****************************************************************************/
extern U32 srv_uc_reserved_size(U32 instance);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_update_msg_size
 * DESCRIPTION
 *  This function to calculate and check for the msg size for exceed or not. This is for pre addition check for objects.
 * PARAMETERS
 *  instance : [IN] instance id
 *  size : [IN] assumed size of the mms after adding the latest object or header
 *  fail_in_restricted_size_check : [IN] flag to check restricted mode or not for size
 * RETURNS
 *  MMI_TRUE:   Success
 *  MMI_FALSE:  Failure
 *****************************************************************************/
extern MMI_BOOL srv_uc_check_if_exceed_MMS_size_limitation(
                U32 instance,
                U32 size,
                MMI_BOOL *fail_in_restricted_size_check);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_check_uc_folder
 * DESCRIPTION
 *  This function to check and create the UC temp working folder.
 * PARAMETERS
 *  void
 * RETURNS
 *  failure error code or success for UC folder
 *****************************************************************************/
extern S32 srv_uc_check_uc_folder(U32 instance);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_check_virtual_file_object_for_creation_mode
 * DESCRIPTION
 *  This function to check the object validity wether it can be added for selected creation mode or not.
 * PARAMETERS
 *  instance : [IN] instance id
 *  obj : [IN] object data for checking
 *  type : [IN] type of media object
 * RETURNS
 *  MMI_TRUE:   Success
 *  MMI_FALSE:  Failure
 *****************************************************************************/
extern MMI_BOOL srv_uc_check_virtual_file_object_for_creation_mode(
        U32 instance,
        mma_mms_object_struct *obj,
        srv_uc_object_type type);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_is_in_ref_obj_type_range
 * DESCRIPTION
 *  This function check for ref media validation and return the validation result in true /false.
 * PARAMETERS
 *  filepath : [IN] file coplete path
 * RETURNS
 *   MMI_FALSE  : Failure
 *   MMI_TRUE  : Success
 *****************************************************************************/
extern MMI_BOOL srv_uc_is_in_ref_obj_type_range(S8 *filepath);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_set_subject
 * DESCRIPTION
 *  This function is to set the subject of the msg.
 * PARAMETERS
 *  instance : [IN] instance id
 *  subject_str : [IN] updated subject string
 * RETURNS
 *   MMI_FALSE  : Failure
 *   MMI_TRUE  : Success
 *****************************************************************************/
extern MMI_BOOL srv_uc_set_subject(
        U32 instance,
        S8* subject_str);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_subject
 * DESCRIPTION
 *  This function to get teh subject of the mms.
 * PARAMETERS
 *  instance : [IN] instance id
 * RETURNS
 *   U16*  : subject string
 *****************************************************************************/
extern U16* srv_uc_get_subject(
        U32 instance);

#ifdef __MMI_MMS_POSTCARD__
/*****************************************************************************
 * FUNCTION
 *  srv_postcard_get_recipient_pointer_by_index
 * DESCRIPTION
 *  This function to get the pointer to the recipient in recipient context for the selected entry by index for postcard.
 * PARAMETERS
 *  instance : [IN] instance id
 *  index : [IN] selected index of the recipient
 * RETURNS
 *  selected recipient entries for postcard
 *****************************************************************************/
extern srv_postcard_recipient_struct *srv_postcard_get_recipient_pointer_by_index(U32 instance, U8 index);
/*****************************************************************************
 * FUNCTION
 *  srv_postcard_is_recipient_forward
 * DESCRIPTION
 *  This function to check whether the recipient has been forward from phonebook.
 * PARAMETERS
 *  instance : [IN] instance id
 * RETURNS
 *   MMI_TRUE  : Yes
 *   MMI_FALSE  : No
 *****************************************************************************/
extern MMI_BOOL srv_postcard_is_recipient_forward(U32 instance);
/*****************************************************************************
 * FUNCTION
 *  srv_postcard_clear_all_context
 * DESCRIPTION
 *  This function to do the following actions
 *  1. delete all
 *  2. send postcard into outbox and finish the export process
 *  3. save postcard to draft
 * PARAMETERS
 *  instance : [IN] instance id
 * RETURNS
 *   MMI_TRUE  : Success
 *   MMI_FALSE  : Failure
 *****************************************************************************/
extern MMI_BOOL srv_postcard_clear_all_context(U32 instance);
/*****************************************************************************
 * FUNCTION
 *  srv_postcard_get_recipient_name_by_index
 * DESCRIPTION
 *  This function to get the recipient name by index.
 * PARAMETERS
 *  instance : [IN] instance id
 * RETURNS
 *   name string
 *****************************************************************************/
extern U8 *srv_postcard_get_recipient_name_by_index(U32 instance, U8 index);
/*****************************************************************************
 * FUNCTION
 *  srv_postcard_get_total_recipient_count
 * DESCRIPTION
 *  This function to get the total count of postcard recipients.
 * PARAMETERS
 *  instance : [IN] instance id
 * RETURNS
 *   postcard recipient count
 *****************************************************************************/
extern U8 srv_postcard_get_total_recipient_count(U32 instance);
/*****************************************************************************
 * FUNCTION
 *  srv_postcard_get_total_recipient_count
 * DESCRIPTION
 *  This function to count and set the total count of postcard recipients.
 * PARAMETERS
 *  instance : [IN] instance id
 * RETURNS
 *   MMI_TRUE  : Success
 *   MMI_FALSE  : Failure
 *****************************************************************************/
extern MMI_BOOL srv_postcard_count_recipients(U32 instance);

#ifdef __MMI_PHB_INFO_FIELD__
/*****************************************************************************
 * FUNCTION
 *  srv_postcard_get_total_recipient_count
 * DESCRIPTION
 *  This function to check for the intrigity of the imported address from phonebook.
 * PARAMETERS
 *  address : [IN] recipient address
 * RETURNS
 *   MMI_TRUE  : Changed from last values
 *   MMI_FALSE  : No change
 *****************************************************************************/
extern MMI_BOOL srv_postcard_check_if_import_data_changed(srv_postcard_address_struct address);
#endif /* __MMI_PHB_INFO_FIELD__ */
#endif /* __MMI_MMS_POSTCARD__ */ 

/* DOM-NOT_FOR_SDK-BEGIN */
extern srv_uc_msg_type_enum srv_uc_get_setting_msg_type(void);
#ifdef __MMI_MMS_INSERT_SENDER_ADDR_FROM_SIM__
extern void srv_uc_get_owner_num(U32 instance, U16* owner_num);
#endif
extern mmi_sim_enum srv_uc_convert_ucsim_to_mmisim(srv_uc_sim_id sim);

extern mma_mms_read_reply_enum srv_uc_convert_mms_rr_to_mma_rr(BOOL read_report);
extern mma_mms_delivery_report_enum srv_uc_convert_mms_dr_to_mma_dr(BOOL delivery_report);
extern mma_mms_sender_visibility_enum srv_uc_convert_mms_vis_to_mma_vis(BOOL visibility);
//extern mma_mms_priority_enum srv_uc_convert_mms_prio_to_mma_prio(mma_priority_enum prio);
extern mma_mms_addr_list_struct *srv_uc_get_address(U32 instance, mma_mms_address_group_type_enum addr_type);
extern mma_addr_type_enum srv_uc_convert_uc_addrtype_to_mma(srv_uc_address_type_enum type);
extern srv_uc_address_type_enum srv_uc_convert_mma_addr_type_to_uc_addr_type(mma_addr_type_enum type);
extern mma_address_group_type_enum srv_uc_convert_uc_addr_group_to_mma_addr_group(srv_uc_address_group_type_enum uc_grp);
extern mma_mms_addr_list_struct *srv_uc_convert_uc_addr_to_mms_addr(srv_uc_addr_struct *uc_address, U32 instance);
extern void srv_uc_free_mem_alloc_for_mma_addr(mma_mms_addr_list_struct *addr_head, U32 instance);
//extern S32 srv_uc_get_mms_info_from_content_rsp(U32 instance, 
												//mma_mms_description_header_struct *mms_header,
										      //  mma_mms_description_body_struct *mms_body);
//extern void srv_uc_header_data_hdlr(U32 instance, mma_mms_description_header_struct* p_header);
//extern void srv_uc_address_data_hdlr(U32 instance, mma_mms_addr_list_struct *addr, srv_uc_address_group_type_enum addr_group_type);
//extern void srv_uc_body_data_hdlr(U32 instance, mma_mms_description_body_struct *mms_body);
extern void *mmi_uc_srv_alloc_mem_cbk(kal_uint32 len, void* user_data);
extern void mmi_uc_mms_free_mem_cbk(void *ptr);

extern MMI_BOOL srv_uc_reset_layout_if_needed(U32 instance);
extern S32 srv_uc_handle_text_in_current_slide(U32 instance);
extern mma_mms_object_struct *srv_uc_check_duplicate_object(U32 instance, U16 *filePath);

extern mma_mms_type_enum srv_uc_get_mms_type(U32 instance);
extern srv_uc_result srv_uc_convert_mms_check_result(mma_insert_check_struct *check_result);
extern MMI_BOOL srv_uc_post_handler_handle_object_insert_if_file_path_exist(
                U32 instance,
                mma_insert_type_enum mms_type,
                U8 *srv_uc_image_path,
                PU16 filePath);
extern mma_mms_object_struct *srv_uc_insert_object_virtual_file(U32 instance, S8 *file_name, S8 *filePath, srv_uc_object_type object_type);
extern MMI_BOOL srv_uc_is_resized_image(U16 *file_path, U32 instance);
extern MMI_BOOL srv_uc_make_image_file_path(U8 *srv_uc_image_path, U32 instance);
extern MMI_BOOL srv_uc_make_vcard_file_path(U8 *srv_uc_image_path, U32 instance);
extern MMI_BOOL srv_uc_update_filepath_with_string(U32 instance, S8 *srv_uc_new_path);
extern U8 srv_uc_signature_pass_warning_mode_content_check(U32 instance);
extern U32 srv_uc_convert_uc_sim_id_to_mma(srv_uc_sim_id sim_id);
extern srv_uc_sim_id srv_uc_convert_sim_id(srv_uc_sim_id sim_id);
extern U32 srv_uc_convert_uc_sim_id_to_wap_prof(srv_uc_sim_id sim_id);
extern U32 srv_uc_convert_to_mms_insert_type(srv_uc_object_type object_type);

extern MMI_BOOL srv_uc_set_valid_sim(U32 instance);
#ifdef __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
extern S32 srv_uc_create_mms_xml_description_file(U32 instance);
extern MMI_BOOL srv_uc_reset_msg_ext(U32 instance);
extern MMI_BOOL srv_uc_delete_slide_with_object_ext(U32 instance, mma_mms_slide_struct *slide);
#endif
extern MMI_BOOL srv_uc_remove_duplicate_entries(U32 instance);
extern U8 srv_uc_check_number_length_for_sms(U32 instance);
extern U8 srv_uc_check_number_length_for_sms_in_send_case(U32 instance);
extern U16 srv_uc_get_highlighted_index(U32 instance, srv_uc_addr_struct *addr);
extern srv_uc_addr_struct *srv_uc_copy_address(U32 instance, srv_uc_addr_struct *addr);
extern U16 srv_uc_convert_mms_app_mode_to_uc_state(U16 app_mode);
extern MMI_BOOL srv_uc_reset_mms_signature(U32 instance);
extern srv_uc_expiry_time_enum srv_uc_convert_mms_expiry_time_to_uc(U32 mms_expiry_time);
extern srv_uc_delivery_time_enum srv_uc_convert_mms_delivery_time_to_uc(U32 mms_delivery_time);
extern U16 srv_uc_convert_uc_state_to_mms_app_mode(U16 state);
extern MMI_BOOL srv_uc_handle_extra_information_from_mma(U32 instance, S32 flag);
extern srv_um_msg_box_enum srv_uc_convert_mma_folder_to_um_folder(mma_folder_enum folder_id);
extern void srv_uc_send_um_msg_refresh_ind(U32 instance, U8 msg_box, U16 msg_type);
extern MMI_BOOL srv_uc_read_file_to_text_buffer(U32 instance, U8 *file_path, U32 encoding);
extern MMI_BOOL srv_uc_delete_addr(U32 instance, srv_uc_addr_struct *address);
extern void srv_uc_free_addr_memory(U32 instance, srv_uc_addr_struct *addr);
extern S32 srv_uc_save_buffer_to_file(U16 instance, U8 *file_path, U8 *buffer, U16 char_num);
extern void srv_uc_set_media_duration(mma_mms_slide_struct *slide_head);
extern void srv_uc_make_signature_image_file_path(U8 *srv_uc_image_path, U32 instance);

extern void srv_uc_reset_text_buffer(U32 instance);
extern void srv_uc_copy_filename_filepath(U32 instance);
extern mma_mms_address_group_type_enum srv_uc_convert_mma_group_to_mms(U8 mma_grp_type);
extern srv_uc_addr_struct *srv_uc_cpy_address(mma_mms_addr_list_struct *mms_address,U32 instance);
extern srv_uc_address_group_type_enum srv_uc_convert_mma_addr_group_to_uc_addr_group(mma_address_group_type_enum mma_grp);

#ifdef __MMI_MMS_POSTCARD__
extern U8 srv_postcard_delete_addr_editor_handler(U32 instance, void *p);
extern void srv_postcard_set_recipient_index(U32 instance, S32 index);
#endif /* __MMI_MMS_POSTCARD__ */ 

#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
extern U32 srv_uc_check_and_add_addr_to_phb_notify_list(U32 instance, srv_uc_phb_list_type_enum type);
#endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 

#ifdef __MMI_MMS_BGSR_SUPPORT__
extern S32 srv_uc_convert_mma_folder_to_bgsr_folder(S32 folderID);
#endif /* __MMI_MMS_BGSR_SUPPORT__ */ 

#ifdef __MMI_UC_MMS_IMG_RESOLUTION__
MMI_BOOL srv_uc_img_resolution_exceed_limitation(U16 *file_path);
#endif /* __MMI_UC_MMS_IMG_RESOLUTION__ */
extern U32 srv_uc_convert_to_mms_layout_type(mma_slide_layout_enum layout_type);

/* DOM-NOT_FOR_SDK-END */
extern U16 *srv_uc_get_file_name(U16 *filePath);
extern kal_uint8 srv_uc_get_max_mo_sms_segment(void);
extern MMI_BOOL srv_uc_compare_string_ignore_case(U16 *addr_1, U16 *addr_2);
#endif /* (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) */ 
#endif /* _UNIFIED_COMPOSER_SRV_IPROT_H */ 
