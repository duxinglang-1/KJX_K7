#ifndef _MMA_STRUCT_H
#define _MMA_STRUCT_H 

#include "mmi_features.h"
#include "MMIDataType.h"
#include "app_ltlcom.h"
#include "kal_general_types.h"
#include "app_mine.h"
#include "drm_def.h"
#include "FileMgrSrvGProt.h"
/*Max length of homepage url of profile MMS adaptor supports*/
#define MMA_MAX_PROF_HOMEPAGE_URL_LENGTH 255
/*Max length of username of profileMMS adaptor supports*/
#define MMA_MAX_PROF_USERNAME_LENGTH 128
/*Max length of password of profile MMS adaptor supports*/
#define MMA_MAX_PROF_PASSWORD_LENGTH 128
/*Max length of response text MMS adaptor supports*/
#define MMA_MAX_RESPONSE_TEXT_LENGTH 256
/*Max length of application data MMS adaptor supports*/
#define MMA_MAX_APP_DATA_LENGTH 32
/*Max length of address MMS adaptor supports*/
#define MMA_MAX_ADDR_LEN 128
/*Max length of subbject MMS adaptor supports*/
#define MMA_MAX_SUBJECT_LEN 41
/*Max length of file name MMS adaptor supports*/
#define MMA_MAX_INTERNAL_FILENAME_LENGTH  100
/*Max length of message array MMS adaptor supports*/
#define MMA_MAX_MSG_ARRAY_NUM   100
/*Max size of checksum file MMS adaptor supports*/
#define MMA_MAX_CHECKSUM_FILE_SIZE 1024
/*Max size of preserve checksum file MMS adaptor supports*/
#define MMA_MAX_CHECKSUM_FILE_RESERVE_LENGTH 120 /* (MMA_MAX_CHECKSUM_FILE_SIZE - 8 - sizeof(mma_basic_msg_info_large_data_strcut) - sizeof(mma_basic_msg_info_property_strcut) - 2) */
/*Max length of external file path MMS adaptor supports*/
#define MMA_MAX_EXTERNAL_FILE_PATH_LEN 261
/*Max number of unread message MMS adaptor supports in unread message list query operation.*/
#define MMA_MAX_UNREAD_MSG_NUM 5
/*Max number of message events MMS adaptor supports.*/
#define MMA_MAX_EVT_NUM 20
/*Max number of message MMS adaptor supports in general message query operation.*/
#define MMA_MAX_MSG_NUM_QUERY_NUM 12
/* ASM Pool Size used by MMA Parsing*/
#define MMA_ASM_MEM_POOL_SIZE  (80 * 1024)
/*Max number of supported TO/CC/BCC addresses.*/
#define MMA_MAX_SUPPORT_ADDR_COUNT 20
/* MAX detail for the MMS Body objects */
#define MMA_MAX_MMS_BODY_FILE_NAME_LEN 21         /* 20 plus 1 for NULL check */

/*chetan*/
typedef unsigned long mma_mms_time_sec;      /*!< Time in sec from 1970-01-01 */ 
typedef unsigned long mma_mms_rply_chrg_size; /*!< Size allowed for a reply charging*/
/*chetan*/

/*chetan*/


/**********************************************************************
 * Structure definition
 **********************************************************************/

typedef struct
{
    unsigned char *name;     /*!< Well-known-field-name or a char.*/
    unsigned char *value;   /*!< Null terminated text string.*/
} mma_mms_entry_header_data_struct;




typedef struct mma_mms_all_param_struct_t
{
    kal_uint8        param;  /*!< mma_mms_param_enum enum */
    
    /*! Param value type. MMS_PARAM_STRING = String, MMS_PARAM_INTEGER = int */
    kal_uint8    type;  /*mma_mms_param_type_enum*/
    
    unsigned char   *key;   /*!< Parameter text key, Token-text See WAP-203-WSP 8.4.2.1 */
    
    union
    {
        unsigned char   *string;    /*! The value is a RFC2616 encoded string or NULL */
        unsigned long      integer;    /*! The value is a number */
    } value;
    /*! Pointer to next param. NULL if no more params  */
    struct mma_mms_all_param_struct_t *next;    
} mma_mms_all_param_struct;


typedef struct
{
    /*! The media type is a known value */
    kal_uint16   known_value; /*mma_mms_known_mediatype_enum*/
    /*! The media type is a us-ascii string */
    unsigned char   *str_value;      
    /*! Pointer to the content type params, NULL if there is no parameters */
    mma_mms_all_param_struct    *params;    
} mma_mms_content_type_struct;

typedef struct mma_mms_all_entry_header_struct_t
{
    /*! Info about which union type to use.*/
    kal_uint8 header_type; /*mma_mms_entry_header_value_type_enum*/

    union
    {
        /*! Value of a shift delimiter.*/
        unsigned char shift_delimiter;   
        
        /*! Type of short cut shift delimiter.*/
        unsigned char short_cut_shift_delimiter; 
        
        /*! Value of a well known field name.*/
        unsigned char *well_known_field_name; 
        
        /*! Type and value of an application header.*/
        mma_mms_entry_header_data_struct application_header;
    } value;

    /*! Next entry header for a body part, NULL if there is no more headers. */
    struct mma_mms_all_entry_header_struct_t *next;
} mma_mms_all_entry_header_struct;



typedef struct mma_mms_body_info_list_struct_t
{
    mma_mms_content_type_struct  *content_type;   /*!< The content type information. */
    mma_mms_all_entry_header_struct  *entry_header;   /*!< The entry header information. */
    unsigned long      number;         /*!< Which part in the body. */
    unsigned long      startPos;       /*!< Start position for the body part (data). */
    unsigned long      size;           /*!< Total size of the body part (data). */
    
    /*! Number of sub parts for the current multipart. 0 if not a multipart */
    unsigned long      num_of_entries;   
     
    /*! Pointer to the next body info element in the list, NULL if last */
    struct mma_mms_body_info_list_struct_t *next;    
} mma_mms_body_info_list_struct;


typedef struct
{
    kal_uint8  class_identifier;    /*!< Enum mma_mms_class_indentifier_enum */
    char                *text_string;        /*!< Textual representation of a message class */
} mma_mms_msg_class_struct;



typedef struct
{
    kal_uint8  charset;    /*!< mma_mms_charset_enum */
    char        *text;      /*!< Text buffer, must be NULL terminated */
} mma_mms_encoded_text_struct;






typedef struct
{
    mma_mms_encoded_text_struct name;       
    char *address;             
    kal_uint8 addr_type;  /*mma_mms_address_type_enum*/  
	kal_uint8 group;      /*mma_address_group_type_enum*/
} mma_mms_address_struct;



typedef struct mma_mms_addr_list_struct_t 
{
	 kal_char *address; 
     kal_uint8 addr_type;  /*mma_mms_address_type_enum*/  
     kal_uint8 group;      /*mma_address_group_type_enum*/

    /*! Address for current element */
   // mma_mms_address_struct current;                 
    struct mma_mms_addr_list_struct_t *prev;
    /*! Next address list element or NULL if last element */
    struct mma_mms_addr_list_struct_t *next;  
	
} mma_mms_addr_list_struct;


typedef struct mma_mms_prev_sent_by_struct_t
{
    unsigned long  forwarded_count_value;
    mma_mms_address_struct  sent_by;
    struct mma_mms_prev_sent_by_struct_t *next;
} mma_mms_prev_sent_by_struct;



typedef struct mma_mms_prev_sent_date_struct_t
{
    unsigned long  forwarded_count_value;
    mma_mms_time_sec  date;
    struct mma_mms_prev_sent_date_struct_t *next;
} mma_mms_prev_sent_date_struct;


typedef struct
{                            
//#ifdef MTK_TMP_PATCH 
    kal_uint8 version;/*mma_mms_version_enum*/
//#endif
    /*! [M] The address of the message sender. */ 
    mma_mms_addr_list_struct *from;                    

    /*! [O] The addressee of the message. The address field can contain one or
     *      several addresses. The parameter is a reference to a list 
     *      containing the recipient addresses. One element in the list carries 
     *      the address (PLMN or e-mail) and the text string representing the 
     *      recipient real name (e.g. Joe User) to be used in multimedia 
     *      messages. Please note that PLMN addresses cannot make use of real 
     *      names. A message needs always at least one specified address in one
     *      of the to, cc or bcc field.    
     */ 
	 kal_uint8 from_type; /*mma_mms_from_type_enum*/ 


    mma_mms_addr_list_struct *to;                 

    /*! [O] See To field. */    
    mma_mms_addr_list_struct *cc;                 

    /*! [O] See To field. */ 
    mma_mms_addr_list_struct *bcc;                

    /*! [O] The text string containing the subject of the message. See also 
     *      configuration setting for the maximum length of this field in 
     *      mms_cfg.h.
     */
    mma_mms_encoded_text_struct subject;             

    /*! [O] Arrival time (in seconds since 1970-01-01) of the message at the 
     *      MMS Proxy-Relay. The MMS Proxy-Relay will generate this field if 
     *      not supplied.
     */
    mma_mms_time_sec date;                    

	/*! [M] The Content-Type contains a media type and a number of parameters. 
     *      Examples of media-types are: text/plain, image/jpg, 
     *      multipart/related etc. Examples of parameters are: start, type, 
     *      filename. The MMS Application must always set this field.
     */ 
    //mma_mms_content_type_struct *content_type; 

    /*! [O] The message class field labels the message type as Auto, 
     *      Informational or Advertisement. When the message class is not set 
     *      the class will be interpreted as Personal at the recipient. It is 
     *      recommended not to set this field in normal MMS Applications. 
     */ 
    mma_mms_msg_class_struct msg_class;           

        
    /*! [O] The type of expiry time, absolute or relative. Absolute means that
     *      an absolute time (in seconds since 1970-01-01) is given. Relative
     *      means that the server will add the given number of seconds to
     *      current time.
     */
    kal_uint8 expiry_time_type;/*mma_mms_time_type_enum*/

    /*! [O] Defines the time when the message will be removed from the 
     *      recipient's MMS Proxy-Relay. If not set the maximum time will be 
     *      used. The maximum value is dependent on the MMS Proxy-Relay. 
     */
    mma_mms_time_sec expiry_time;              

//#ifdef MTK_TMP_PATCH  /* TR 29894 */
    /*! [O] The type of delivery time, absolute or relative. Absolute means that
     *      an absolute time (in seconds since 1970-01-01) is given. Relative
     *      means that the server will add the given number of seconds to
     *      current time.
     */
    kal_uint8 delivery_time_type;/*mma_mms_time_type_enum*/
//#endif

    /*! [O] This time value indicates for the MMS Proxy-Relay when the message 
     *      should be delivered to the recipient(s) at a later time. When this 
     *      field is not set the message is delivered immediately.
     */
    mma_mms_time_sec delivery_time;            

    /*! [O] This value defines the message priority. */ 
    kal_uint8 priority;/*mma_mms_priority_enum*/               

    /*! [O] This value is used to control if the "From" address is displayed 
     *      in the message at the recipient's MMS Application.
     */ 
    kal_uint8 visibility; /*mma_mms_sender_visibility_enum*/    

    /*! [O] This field is requesting the retrieving MMS Applications to send a 
     *      read reply message when the message was read. Note; a retrieving 
     *      MMS Application may cancel the request. A read reply message sent
     *      is seen as an ordinary message and the MMS Application controls 
     *      the contents.
     */ 
    kal_uint8 read_reply;             /*mma_mms_read_reply_enum*/

    /*! [O] The setting of this flag will cause the MMS Proxy-Relay to send 
     *      back a notification message when the recipient retrieves the 
     *      message. A retrieving MMS Application may prevent a Delivery 
     *      Report from being sent.
     */ 
    kal_uint8 delivery_report; /*mma_mms_delivery_report_enum*/
    
    /*! [M] Id of the message.
     *      This field is only used when retrieving a message, NOT used when 
     *      sending.
     */
    kal_uint8 to_num;
  
	kal_uint8 cc_num;
      
	kal_uint8 bcc_num;

	kal_uint8 status;

	kal_wchar reported_subject[MMA_MAX_SUBJECT_LEN];
     kal_char *presentation;
     kal_char *app_id;
     kal_char *reply_app_id;
	 /*notif*/
     unsigned long download_size;
     kal_char *content_location;   
	/*report*/
     kal_uint8 dr_status;
     kal_uint8 rr_status;

  
} mma_mms_header_struct;





typedef struct
{
  
        mma_mms_header_struct *header;         /* used when parsing */
      
	#ifdef __MMI_MMS_INSERT_SENDER_ADDR_FROM_SIM__
		kal_uint16 *owner;												/* getting owner number from sim */
    #endif 
		
} mma_mms_description_header_struct;


/*body*/
typedef struct
{
unsigned long value;
kal_uint8 type;/*mma_mms_time_type_enum*/
}mma_mms_type_value_struct;



typedef struct
{
    mma_mms_type_value_struct x;  
    mma_mms_type_value_struct y;  
    mma_mms_type_value_struct w;  
    mma_mms_type_value_struct h;  
} mma_mms_object_area_struct;



typedef struct mma_mms_object_struct_t
{
    kal_uint32 size;
    kal_uint32 offset;
    kal_uint32 id;   
	kal_uint32 encoding;
	kal_uint16 reference_count;
    kal_uint32 charset; /*mma_charset_enum*/
    kal_char *file_path;     
    kal_char *file_name;  
	kal_wchar *file_path_ucs;     
    kal_wchar *file_name_ucs;  
	kal_wchar *mime_type_ext;
	kal_uint8 type;    /*mma_mms_viewer_object_type_enum*/
    kal_bool is_attachment;
    kal_bool is_virtual_file;
    kal_bool rights_expired;
    kal_bool is_restricted;
	kal_bool is_mixed_obj;
    kal_uint8 drm_type; /*mma_drm_type_enum*/
    kal_uint8 drm_process_type;
	kal_char *mime_str;
	 kal_uint32 drm_ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN ];//SRV_FMGR_PATH_MAX_FILE_EXT_LEN defined in filemgrgprot.h
         kal_char *drm_mime_type;
	 kal_uint32 consume_id;
	 kal_uint32 drm_offset;
     kal_uint32 drm_size;
     kal_bool consume_only_timed;
	 kal_bool is_drm_processed;
	 kal_uint8 mime_type;/*applib_mime_type_enum*/
	kal_char *content_id;       // Used By JSR
    kal_char *content_location;  //USED by JSR
	/*requested by ashok to process JSR message */
	kal_char *content_type;       
	kal_uint32 content_type_value;
	kal_uint8 encoding_scheme;
	kal_bool auto_delete_file;
	kal_bool is_invallid;
	struct mma_mms_object_struct_t *next;
      struct mma_mms_object_struct_t *prev;
	#ifdef __DRM_SUPPORT__
	 drm_cid_struct *cid;
	#endif /* __DRM_SUPPORT__ */
} mma_mms_object_struct;




typedef struct mma_mms_slide_text_object_struct_t
{
    mma_mms_object_struct *object;
    unsigned long bg_color;    
    unsigned long fg_color;    
    kal_uint8 text_style;/*mma_text_style_enum*/
    kal_uint16 char_count; 
    kal_uint16 utf8_msg_len;
    kal_uint16 extension_char_count;
    kal_uint16 UCS2_count;
    kal_uint8 text_size;/*mma_text_size_enum*/
    kal_uint32 begin;   
    kal_uint32 end;   
    kal_char *alt;
    kal_uint16 id;  
	kal_uint16 str_id;
	
	mma_mms_object_area_struct *region_area;
	
 
}mma_mms_slide_text_object_struct;



typedef struct mma_mms_slide_ref_object_struct_t
{
    mma_mms_object_struct *object;
    unsigned long bg_color;    
    unsigned long fg_color;   
    kal_uint8 text_style;/*mma_text_style_enum*/
    kal_uint8 text_size;/*mma_text_size_enum*/
    kal_uint32 begin;  
    kal_uint32 end;     
    kal_char *alt;
    kal_uint16 id;  
	mma_mms_object_area_struct *region_area;
    struct mma_mms_slide_ref_object_struct_t *next;
    struct mma_mms_slide_ref_object_struct_t *prev;  
} mma_mms_slide_ref_object_struct;


typedef struct mma_mms_slide_object_struct_t
{
    mma_mms_object_struct *object;
    kal_uint32 begin;   
    kal_uint32 end;    
	mma_mms_object_area_struct *region_area;
    kal_char *alt;
    kal_uint16 id;  
	  struct mma_mms_slide_object_struct_t *next;
} mma_mms_slide_object_struct;


typedef struct mma_mms_slide_struct_t
{	

	struct mma_mms_slide_struct_t *prev;
	mma_mms_slide_object_struct img;
	mma_mms_slide_object_struct vid;
	mma_mms_slide_object_struct aud;
	mma_mms_slide_text_object_struct txt;
	//#ifdef __MMI_MV_SUPPORT_REF_ID__
		mma_mms_slide_ref_object_struct *ref_items;	
	//#endif
    kal_uint32 duration;   
    kal_uint16 slide_num; 
    struct mma_mms_slide_struct_t *next;
} mma_mms_slide_struct;


typedef struct mma_mms_attachment_info_struct_t
{
	mma_mms_object_struct *object;
    struct mma_mms_attachment_info_struct_t *next;
    struct mma_mms_attachment_info_struct_t *prev;
} mma_mms_attachment_info_struct;



typedef struct{
	mma_mms_slide_struct *slides;
	mma_mms_object_struct *objects;
        mma_mms_slide_struct *curr_slide;
        mma_mms_object_struct *curr_object;
	mma_mms_attachment_info_struct *attachment;
	kal_uint32 slide_no;
	unsigned long bgColor; 
	unsigned long fgColor;
	kal_uint32 obj_no;
      kal_uint32 total_attach_no;
      kal_uint32 total_ref_no;
      kal_uint16 total_address;
    kal_uint8 layout;/*mma_slide_layout_enum*/
    kal_uint8 text_fit;        /*mma_region_fit_enum*//* this one also insertion of regions in the main context */
    kal_uint8 image_fit;      /*mma_region_fit_enum*//* this one also insertion of regions in the main context */
   #ifdef __MMI_MMS_POSTCARD__
    srv_postcard_context_struct postcard_recipient_info;    /* Postcard recipient list info */
    BOOL greeting_exist_flag;                               /* if there is greeting, the flag will be T */
   #endif /* __MMI_MMS_POSTCARD__ */
}mma_mms_description_body_struct;



typedef struct
{
  mma_mms_description_header_struct *header;  /*new one to be used*/
  mma_mms_description_body_struct  *body;
}mma_mms_description_struct;




/*body*/

/*chetan*/

/*This enum is used to query some information from MMS adaptor.*/
typedef enum
{
  MMA_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM1 = 1,   /* Number of unread Msg in Inbox for SIM1 */
  MMA_QUERY_OPTION_NUM_TOTAL_INBOX_SIM1,            /* total Number of Msg in  Inbox for SIM1*/
  MMA_QUERY_OPTION_NUM_TOTAL_OUTBOX_SIM1,           /* total Number of Msg in Outbox SIM1 */  
  MMA_QUERY_OPTION_NUM_TOTAL_SENT_SIM1,             /* total Number of Msg in Sent SIM1 */  
  MMA_QUERY_OPTION_NUM_UNREAD_ARCHIVE_MSG_SIM1,     /* Number of unread Msg in Archive for SIM1 */  
  MMA_QUERY_OPTION_NUM_TOTAL_ARCHIVE_SIM1,          /* Number of Msg in Archive for SIM1 */
  MMA_QUERY_OPTION_NUM_UNREAD_TOTAL_MSG_SIM1,       /*Number of SIM1 Unread Msg in All folders*/
#if (MMI_MAX_SIM_NUM >= 2)
  MMA_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM2,       /* Number of unread Msg in Inbox for SIM2 */
  MMA_QUERY_OPTION_NUM_TOTAL_INBOX_SIM2,            /* total Number of Msg in  Inbox for SIM2*/
  MMA_QUERY_OPTION_NUM_TOTAL_OUTBOX_SIM2,           /* total Number of Msg in Outbox SIM2 */
  MMA_QUERY_OPTION_NUM_TOTAL_SENT_SIM2,             /* total Number of Msg in Sent SIM2 */
  MMA_QUERY_OPTION_NUM_UNREAD_ARCHIVE_MSG_SIM2,     /* Number of unread Msg in Archive for SIM2 */
  MMA_QUERY_OPTION_NUM_TOTAL_ARCHIVE_SIM2,          /* Number of Msg in Archive for SIM2 */
  MMA_QUERY_OPTION_NUM_UNREAD_TOTAL_MSG_SIM2,        /*Number of SIM2 Unread Msg in All folders*/
#endif
#if (MMI_MAX_SIM_NUM >= 3)
  MMA_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM3,   /* Number of unread Msg in Inbox for SIM3 */
  MMA_QUERY_OPTION_NUM_TOTAL_INBOX_SIM3,            /* total Number of Msg in  Inbox for SIM3*/
  MMA_QUERY_OPTION_NUM_TOTAL_OUTBOX_SIM3,           /* total Number of Msg in Outbox SIM3 */
  MMA_QUERY_OPTION_NUM_TOTAL_SENT_SIM3,             /* total Number of Msg in Sent SIM3 */  
  MMA_QUERY_OPTION_NUM_UNREAD_ARCHIVE_MSG_SIM3,     /* Number of unread Msg in Archive for SIM3 */
  MMA_QUERY_OPTION_NUM_TOTAL_ARCHIVE_SIM3,          /* Number of Msg in Archive for SIM3 */
  MMA_QUERY_OPTION_NUM_UNREAD_TOTAL_MSG_SIM3,       /*Number of SIM3 Unread Msg in All folders*/
#endif
#if (MMI_MAX_SIM_NUM >= 4)
  MMA_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM4,   /* Number of unread Msg in Inbox for SIM4 */
  MMA_QUERY_OPTION_NUM_TOTAL_INBOX_SIM4,            /* total Number of Msg in  Inbox for SIM4*/
  MMA_QUERY_OPTION_NUM_TOTAL_OUTBOX_SIM4,           /* total Number of Msg in Outbox SIM4 */
  MMA_QUERY_OPTION_NUM_TOTAL_SENT_SIM4,             /* total Number of Msg in Sent SIM4 */
  MMA_QUERY_OPTION_NUM_UNREAD_ARCHIVE_MSG_SIM4,     /* Number of unread Msg in Archive for SIM4 */
  MMA_QUERY_OPTION_NUM_TOTAL_ARCHIVE_SIM4,          /* Number of Msg in Archive for SIM4 */
  MMA_QUERY_OPTION_NUM_UNREAD_TOTAL_MSG_SIM4,        /*Number of SIM4 Unread Msg in All folders*/
#endif
  MMA_QUERY_OPTION_NUM_TOTAL_UNREAD_INBOX_MSG,      /* Number of unread Msg in  Inbox*/
  MMA_QUERY_OPTION_NUM_TOTAL_INBOX_MSG,             /* total Number of Msg in  Inbox */
  MMA_QUERY_OPTION_NUM_TOTAL_OUTBOX_MSG,            /* total Number of Msg in Outbox*/
  MMA_QUERY_OPTION_NUM_TOTAL_SENT_MSG,              /* total Number of Msg in Sent  */
  MMA_QUERY_OPTION_NUM_TOTAL_DRAFT_MSG,             /* total Number of Msg in Drafts */
  MMA_QUERY_OPTION_NUM_TOTAL_UNREAD_ARCHIVE_MSG,    /* Number of unread Msg in Archive */
  MMA_QUERY_OPTION_NUM_TOTAL_ARCHIVE_UNCLASSIFIED,  /* Number of Uncalssified Msg in Archive */
  MMA_QUERY_OPTION_NUM_TOTAL_ARCHIVE_MSG,           /* Number of Msg in Archive  */
  MMA_QUERY_OPTION_NUM_TOTAL_USER_DEF_TEMPLATE_MSG, /* Number of Msg in user defined template  */
  MMA_QUERY_OPTION_NUM_TOTAL_PRE_DEF_TEMPLATE_MSG,  /* Number of Msg in Pr defined template  */
  MMA_QUERY_OPTION_NUM_TOTAL_UNREAD_MSG,             /* Number of Unread Msg in All folders*/
  MMA_QUERY_OPTION_NUM_TOTAL_PHONE_MSG,
  MMA_QUERY_OPTION_NUM_TOTAL_CARD_MSG
}mma_query_option_enum;

/*This enum is used to specify SIM id.*/
typedef enum
{
    MMA_SIM_ID_SIM1 = 0x01, /*The first SIM*/
    MMA_SIM_ID_SIM2 = 0x02, /*The second SIM*/
    MMA_SIM_ID_SIM3 = 0x04, /*The third SIM*/
    MMA_SIM_ID_SIM4 = 0x08, /*The fourth SIM*/
    MMA_SIM_ID_SIM_UNCLASSIFIED = 0x10, /* SIM ID not supported */
    MMA_SIM_ID_TOTAL = 0xFF
}mma_sim_id_enum;

/*The structure is used by UM to ask MEA of OBIGO_Q03C_MMS_VO1 to open one MMS message*/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32 msg_box;
    kal_uint32 msg_index;
    kal_uint8  mode;
}wap_mma_um_entry_req_struct;

/*The strcuture is general and used by MMS adaptor to carry result information.*/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32 req_id;
    kal_uint32 msg_id; /* Message id */
    kal_uint8 app_id;  /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8 result;  /* mma_result_enum */
}wap_mma_rsp_struct;

/*This structure is used to describe the image resizing setting.*/
typedef struct
{
    kal_uint32 width;   /* The width which image will be resized to */
    kal_uint32 height;  /* The height which image will be resized to */
    kal_bool   enable;  /* KAL_FALSE: DISABLE, KAL_TRUE: ENABLE */
}mma_image_resizing_struct;

/*This structure is used to describe MMS signature*/
typedef struct
{
    kal_wchar text_file[MMA_MAX_INTERNAL_FILENAME_LENGTH];  /* MMA_MAX_INTERNAL_FILENAME_LENGTH, Filepath of signature text. Encoded by UCS2 */
    kal_wchar img_file[MMA_MAX_EXTERNAL_FILE_PATH_LEN];   /* MMA_MAX_EXTERNAL_FILE_PATH_LEN, Filepath of signature image. Encoded by UCS2 */
    kal_wchar audio_file[MMA_MAX_EXTERNAL_FILE_PATH_LEN]; /* MMA_MAX_EXTERNAL_FILE_PATH_LEN, Filepath of signature audio. Encoded by UCS2 */
    kal_wchar video_file[MMA_MAX_EXTERNAL_FILE_PATH_LEN]; /* MMA_MAX_EXTERNAL_FILE_PATH_LEN, Filepath of signature video. Encoded by UCS2 */
    kal_bool  enable; /* KAL_FALSE: DISABLE, KAL_TRUE: ENABLE */
}mma_signature_struct;

/*This structure is used to describe a setting value and its setting range.*/
typedef struct
{
    kal_uint32 value; /* The setting value */
    kal_uint32 min;   /* The possible minimum */
    kal_uint32 max;   /* The possible maximum */
}mma_setting_struct;

/*This structure is used to describe current settings for compse and sending.*/
typedef struct
{
    kal_uint32  validity_period;    /* mma_expiry_time_enum */
    kal_uint32  delivery_time;      /* mma_delivery_time_enum */
    kal_uint32  max_mms_size;       /* Maximum MMS size can be composed*/
    kal_uint32  deadline_for_reply; /* Reply charge deadline time */
    kal_uint32  size;               /* Maximum MMS size can be downloaded*/
    mma_image_resizing_struct   image_resize; /*mma_image_resizing_struct*/
    mma_signature_struct        signature; /* mma_signature_struct */
    mma_setting_struct          sliding_time; /* mma_setting_struct */
    kal_bool    delivery_report;    /* Delivery report requested */
    kal_bool    read_report;        /* Read report requested */
    kal_uint8   creation_mode;      /* mma_creation_mode_enum */
    kal_uint8   priority;           /* mma_priority_enum */
    kal_uint8   layout;             /* 0: Potrait, 1: Landscape*/
    kal_uint8   add_as_drm;         /* 0:FASLE, 1: TRUE */
    kal_uint8   max_no_pages;       /* Max number of slides can be insrted*/
    kal_uint8   best_page_duration; /* 0:DISABLE, 1: ENABLE */
    kal_uint8   reply_charging;     /* 0:DISABLE, 1: ENABLE */
    kal_uint8   request_type;       /* mma_reply_charging_type_enum */
    kal_uint8   hide_sender;        /* Sender visible or not to reciever */
}mma_compose_sending_setting_struct;

/*This structure is used to describe current settings of retrieval.*/
typedef struct
{
    kal_uint8 home_network;           /* mma_retrieval_mode_enum */
    kal_uint8 roaming;                /* mma_retrieval_mode_enum */
    kal_uint8 anonymous_filter;       /* 1: TRUE, 0:FASLE */
    kal_uint8 advertisement_filter;   /* 1: TRUE, 0:FASLE */
    kal_uint8 delivery_report;        /* 1: Allowed: 0, Not Allowed */
}mma_retrieval_setting_struct;

#if defined (__MMI_OP11_HOMESCREEN__) || defined (__MMI_OP12_TOOLBAR__) || defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/*This structure is used to describe unread message information.*/
typedef struct
{
    kal_uint32 msg_id;                          /* Message id */
    kal_uint32 received_date;                   /* Received date of the message. Format of value is GMT time since 1. Jan. 1970, counted by second, no daylight saving*/
    kal_wchar  subject[MMA_MAX_SUBJECT_LEN];    /* MMA_MAX_SUBJECT_LEN, Subject of the message. Encoded by UCS2 */
    kal_wchar  from_address[MMA_MAX_ADDR_LEN];  /* MMA_MAX_ADDR_LEN, From address of the message. Encoded by USC2 */
    kal_uint16 icon_id;                         /* Message image icon id */
    kal_uint8  msg_type;						/* mma_msg_type_enum */
    kal_uint8  num_attach;
    kal_bool   is_subject;
    kal_bool   is_text;
}mma_unread_msg_list_struct;
#endif

/*This structure is used to describe recent event information.*/
typedef struct
{
    kal_uint32 msg_id;                          /* Message id*/
    kal_uint32 received_date;                   /* Received date of the message. Format of value is GMT time since 1. Jan. 1970, counted by second, no daylight saving*/
    kal_wchar  subject[MMA_MAX_SUBJECT_LEN];    /* MMA_MAX_SUBJECT_LEN, Subject of the message. Encoded by UCS2*/
    kal_uint16 icon_id;                         /* Message image icon id */
    kal_uint8  msg_type;						/* mma_msg_type_enum */
    kal_uint8  num_attach;
	kal_uint8   is_read;                         /* Indicate that message is read or unread. TRUE: message has been read, FALSE: message is unread */
    kal_uint8   is_subject;
    kal_uint8   is_text;
}mma_recent_evt_list_struct;

/*This structure is used to describe message property.*/
typedef struct
{
    kal_uint32 msg_id;      /* Message id */
    kal_uint8  msg_type;    /* mma_msg_type_enum */
    kal_bool   is_read;     /* TRUE: read, FALSE: unread */
    kal_bool   is_valid;    /* TRUE: msg is is valid, FALSE: msg id is invalid */
}mma_msg_property_struct;

/* This structure is used by bt local parameter of MSG_ID_WAP_MMA_GET_SETTING_REQ.*/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32 req_id;  /* Request id */
    kal_uint8  app_id;  /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
}wap_mma_get_setting_req_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_GET_SETTING_RSP. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;                             /* Request id */
    kal_uint32  validity_period;                    /* mma_expiry_time_enum */
    kal_uint32  delivery_time;                      /* mma_delivery_time_enum */
    kal_uint32  max_mms_size;                       /* Maximum MMS size can be composed*/
    kal_uint32  deadline_for_reply;                 /* Reply charge deadline time */
    kal_uint32  size;                               /* Maximum MMS size can be downloaded*/
    kal_uint8   app_id;                             /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   result;                             /* mma_result_enum */
    kal_uint8   mms_version;                        /* MMS version, 0x10 is 1.0, 0x11 is 1.1, 0x12 is 1.2 */
    kal_uint8   creation_mode;                      /* mma_creation_mode_enum */
    kal_uint8   priority;                           /* mma_priority_enum */
    kal_uint8   layout;                             /* 0: Potrait, 1: Landscape*/
    kal_uint8   add_as_drm;                         /* 0:FASLE, 1: TRUE */
    kal_uint8   max_no_pages;                       /* Max number of slides can be insrted*/
    kal_uint8   best_page_duration;                 /* 0:DISABLE, 1: ENABLE */
    kal_uint8   reply_charging;                     /* 0:DISABLE, 1: ENABLE */
    kal_uint8   request_type;                       /* mma_reply_charging_type_enum */
    kal_uint8   hide_sender;                        /* Sender visible or not to reciever */
    kal_bool    delivery_report;                    /* Delivery report requested */
    kal_bool    read_report;                        /* Read report requested */
    mma_image_resizing_struct   image_resize;       /*mma_image_resizing_struct*/
    mma_signature_struct        signature;          /* mma_signature_struct */
    mma_setting_struct          sliding_time;       /* mma_setting_struct */    
    mma_retrieval_setting_struct retrieval_setting; /* mma_retrieval_setting */
}wap_mma_get_setting_rsp_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_GET_MEM_STATUS_REQ. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32 req_id;    /* Request id */
    kal_uint8  app_id;    /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8  storage;
}wap_mma_get_mem_status_req_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_GET_MEM_STATUS_RSP. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;     /* Request id */
    kal_uint32  used_size;  /* Specify how many bytes are used by MMS messages. Counted by bytes.*/
    kal_uint64  free_size;  /* Specify how many bytes are free for MMS messages. Counted by bytes.*/
    kal_uint8   app_id;     /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   result;     /* mma_result_enum */
}wap_mma_get_mem_status_rsp_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_SET_SETTING_REQ. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;                                         /* Request id */
    mma_compose_sending_setting_struct  compose_sending_setting;/* mma_compose_sending_setting_struct */
    mma_retrieval_setting_struct        retrieval_setting;      /* mma_retrieval_setting_struct*/
    kal_uint8   app_id;                                         /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   mms_version;                                    /* MMS version, 0x10 is 1.0, 0x11 is 1.1, 0x12 is 1.2 */    
    kal_uint8   preffered_storage;
	kal_uint8   storage_filter;
}wap_mma_set_setting_req_struct;
                               
/* This structure is used by local parameter of MSG_ID_WAP_MMA_SET_SETTING_RSP. */
typedef struct                  
{                               
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */           
    kal_uint32  req_id;     /* Request id */
    kal_uint8   app_id;     /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   result;     /* mma_result_enum */
}wap_mma_set_setting_rsp_struct;   
                                   
/* This structure is used by local parameter of MSG_ID_WAP_MMA_SET_PROFILE_REQ. */
typedef struct                      
{                                    
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */              
    kal_uint32  req_id;                                         /* Request id */
    kal_uint32  data_account;                                   /* Data account used by this profile */
    kal_uint16  proxy_port;                                     /* Port number of proxy */
    kal_wchar homepage_url[MMA_MAX_PROF_HOMEPAGE_URL_LENGTH];   /* MMA_MAX_PROF_HOMEPAGE_URL_LENGTHE, Specify the URL of homepage and encoded by UCS2*/
    kal_wchar username[MMA_MAX_PROF_USERNAME_LENGTH];           /* MMA_MAX_PROF_USERNAME_LENGTH, Specify the username and encoded by UCS2*/
    kal_wchar password[MMA_MAX_PROF_PASSWORD_LENGTH];           /* MMA_MAX_PROF_PASSWORD_LENGTH, Specify the password and encoded by UCS2*/
    kal_uint8 proxy_addr[MMA_MAX_PROF_HOMEPAGE_URL_LENGTH];                                    /* IP address of proxy*/
    kal_uint8   app_id;                                         /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8 connection_type;                                  /* mma_connection_type_enum */
    kal_uint8   sim_id;                                         /* mma_sim_id_enum */
}wap_mma_set_profile_req_struct;           
                                           
/* This structure is used by bt local parameter of MSG_ID_WAP_MMA_SET_PROFILE_RSP. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id; /* Request id */
    kal_uint8   app_id; /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   result; /* mma_result_enum */
}wap_mma_set_profile_rsp_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_GET_CONTENT_REQ. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;         /* Request id */
    kal_uint32  msg_id;         /* Message id */
    kal_uint8   app_id;         /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   mode;           /* mma_app_mode_enum, Content request mode*/
    kal_uint8   creation_mode;  /* mma_creation_mode_enum, Creation mode to filter content.*/
}wap_mma_get_content_req_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_GET_CONTENT_RSP. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    mma_mms_description_struct *content_info;
    kal_uint32  req_id;                                         /* Request id */
    kal_uint32  msg_id;                                         /* Message id */
    kal_uint32  mms_header_size;                                /* Size of MMS headers */
    kal_uint32  mms_body_size;                                  /* Size of MMS bodies */
    kal_bool    isFollowPhoneMMSContentClass;                   /* Specify if the MMS follow handset content class */
    kal_uint8   app_id;                                         /* MMA_APP, application id in requst message, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   result;                                         /* mma_result_enum */
    kal_uint8   content_truncate_info;
}wap_mma_get_content_rsp_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_CREATE_REQ. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    mma_mms_description_struct *content_info;
    kal_uint32  req_id;                                          /* Request id */
    kal_uint32  msg_id;                                          /* Message id */
    kal_uint32  xml_size;                                        /* Size of the XML file */
    kal_uint32  buffer_index;                                    /* XML content segment (carried in peer buffer of MSG_ID_WAP_MMA_CREATE_REQ) returned. Start form 0.*/
    kal_uint32  buffer_size;                                     /* The content size in peer buffer of MSG_ID_WAP_MMA_CREATE_REQ */
    kal_wchar   msg_file_path[MMA_MAX_INTERNAL_FILENAME_LENGTH]; /* MMA_MAX_INTERNAL_FILENAME_LENGTH, File path of MMS message. f the MMS message is stored in file, application can insert the MMS to MMA system. If msg_file_path is not NULL, MMA will directly insert this MMS file to MMA system. The message will be inserted to DRAFT folder first. Application can change the folder by SAVE_REQ primitive*/
    kal_wchar   xml_filepath[MMA_MAX_INTERNAL_FILENAME_LENGTH];  /* MMA_MAX_INTERNAL_FILENAME_LENGTH, Specify file path of XML file */
    kal_bool    more;                                            /* Spcify if more XML text to be sent*/
    kal_uint8   app_id;                                          /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   mode;                                            /* mma_app_mode_enum */
    kal_uint8   sim_id;                                          /* mma_sim_id_enum */
}wap_mma_create_req_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_CREATE_RSP. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;                  /* Request id */
    kal_uint32  msg_id;                  /* Message id */
    kal_uint32  buffer_index;            /* XML content segment request. Start form 0.*/
    kal_uint32  min_fs_space_required;   /* When the value is more than 0, it means we don't have enoguh working file space to create the MMS */
    kal_uint8   app_id;                  /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   storage;
    kal_uint8   result;                  /* mma_result_enum */
}wap_mma_create_rsp_struct;
/* This structure is used by local parameter of MSG_ID_WAP_MMA_FREE_MMS_CONTENT. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;         /* Request id */
    kal_uint32  msg_id;         /* Message id */
    kal_uint8   app_id;         /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
}wap_mma_free_content_info_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_DELETE_REQ. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;                        /* Request id */
    kal_uint32  no_of_msg;                     /* Num of messages in msg_id array */
    kal_uint32  msg_id[MMA_MAX_MSG_ARRAY_NUM]; /* MMA_MAX_MSG_ARRAY_NUM, The to-be-deleted msg id list */
    kal_uint16  box;                           /* mma_folder_enum, Message box the message was saved in*/
    kal_uint8   app_id;                        /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
}wap_mma_delete_req_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_DELETE_RSP. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;                         /* Request id */
    kal_uint32  no_of_msg;                      /* Num of messages in msg_id array */
    kal_uint32  msg_id[MMA_MAX_MSG_ARRAY_NUM];  /* MMA_MAX_MSG_ARRAY_NUM, The to-be-deleted msg id list request*/
    kal_uint32  result[MMA_MAX_MSG_ARRAY_NUM];  /* MMA_MAX_MSG_ARRAY_NUM, The result of deletion of the to-be-deleted msg id list request*/
    kal_uint8   app_id;                         /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
}wap_mma_delete_rsp_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_SAVE_REQ. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;                         /* Request id */
    kal_uint32  no_of_msg;                      /* Num of messages in msg_id array */
    kal_uint32  msg_id[MMA_MAX_MSG_ARRAY_NUM];  /* The to-be-moved msg id list request */
    kal_uint16  box;                            /* mma_folder_enum */
    kal_uint8   app_id;                         /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
}wap_mma_save_req_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_SAVE_RSP. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;                         /* Request id */
    kal_uint32  no_of_msg;                      /* Num of messages in msg_id array */
    kal_uint32  msg_id[MMA_MAX_MSG_ARRAY_NUM];  /* MMA_MAX_MSG_ARRAY_NUM, The to-be-moved msg id list request*/
    kal_uint32  result[MMA_MAX_MSG_ARRAY_NUM];  /* MMA_MAX_MSG_ARRAY_NUM, The result of deletion of the to-be-moved msg id list request*/
    kal_uint8   app_id;                         /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
}wap_mma_save_rsp_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_PERVIEW_REQ. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id; /* Request id */
    kal_uint32  msg_id; /* Message id */
    kal_uint8   app_id; /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
}wap_mma_preview_req_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_PERVIEW_RSP. */
typedef wap_mma_rsp_struct wap_mma_preview_rsp_struct;


/* This structure is used by local parameter of MSG_ID_WAP_MMA_SEND_REQ. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;         /* Request id */
    kal_uint32  msg_id;         /* Message id */
    kal_uint16  box;            /* mma_folder_enum */
    kal_bool    is_read_report; /* Specify if this MMS is a read report corresponding to msg_id above */
    kal_bool    send_and_save;  /* Obsolete */
    kal_uint8   app_id;         /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   sim_id;         /* mma_sim_id_enum */
}wap_mma_send_req_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_SEND_IND. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;     /* Request id */
    kal_uint32  msg_id;     /* Message id */
    kal_uint8   app_id;     /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   retry;      /* Obsolete. It is always 0. */
    kal_uint8   percent;    /* Percentage of completion. From 0 to 100. */
    kal_uint8   sim_id;     /* mma_sim_id_enum, Specify the SIM card user choose to send the MMS. */
}wap_mma_send_ind_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_SEND_RES. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;     /* Request id */
    kal_uint8   app_id;     /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   result;     /* mma_result_enum */
}wap_mma_send_res_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_SEND_RSP. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;                                         /* Request id */
    kal_uint32  msg_id;                                         /* Message id */
    kal_wchar   response_text[MMA_MAX_RESPONSE_TEXT_LENGTH];    /* MMA_MAX_RESPONSE_TEXT_LENGTH, Response text in send confirmation (MSend.conf PDU) from MMS server. */
    kal_uint16  box;                                            /* mma_folder_enum */
    kal_bool    send_and_save;                                  /* Oboslete */
    kal_uint8   app_id;                                         /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   result;                                         /* mma_result_enum */
}wap_mma_send_rsp_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_CANCEL_SEND_REQ. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id; /* Request id */
    kal_uint32  msg_id; /* Message id */
    kal_uint8   app_id; /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
}wap_mma_cancel_send_req_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_CANCEL_SEND_RSP. */
typedef wap_mma_rsp_struct wap_mma_cancel_send_rsp_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_DOWNLOAD_REQ. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;     /* Request id */
    kal_uint32  msg_id;     /* Message id of MMS notification*/
    kal_uint8   app_id;     /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   sim_id;     /* mma_sim_id_enum */
}wap_mma_download_req_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_DOWNLOAD_RSP. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;                                         /* Request id */
    kal_uint32  msg_id;                                         /* Message id of notification */
	kal_uint32  new_msg_id;                                     /* Message id of new MMS being downloaded successfully */
    kal_wchar   response_text[MMA_MAX_RESPONSE_TEXT_LENGTH];    /* MMA_MAX_RESPONSE_TEXT_LENGTH, Response text from server. */
    kal_uint8   app_id;                                         /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   result;                                         /* mma_result_enum */
}wap_mma_download_rsp_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_DOWNLOAD_IND. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;         /* Request id */
    kal_uint32  msg_id;         /* Message id */
    kal_uint32  bytes_received; /* Total number of bytes received. */   
    kal_uint8   app_id;         /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   retry;          /* Retry time*/
    kal_uint8   percent;        /* Percentage of completion. From 0 to 100.*/
    kal_uint8   sim_id;         /* mma_sim_id_enum, Specify the SIM card MMA use to download the MMS. */
}wap_mma_download_ind_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_DOWNLOAD_RES. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id; /* Request id */
    kal_uint8   app_id; /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   result; /* mma_result_enum */
}wap_mma_download_res_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_CANCEL_DOWNLOAD_REQ. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id; /* Request id */
    kal_uint32  msg_id; /* Message id */
    kal_uint8   app_id; /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
}wap_mma_cancel_download_req_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_CANCEL_DOWNLOAD_RSP. */
typedef wap_mma_rsp_struct wap_mma_cancel_download_rsp_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_GET_MSG_INFO_REQ. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id; /* Request id */
    kal_uint32  msg_id; /* Message id */
    kal_uint8   app_id; /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
}wap_mma_get_msg_info_req_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_GET_MSG_INFO_RSP. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;                             /* Request id */
    kal_uint32  msg_id;                             /* Message id */
    kal_uint32  msg_size;                           /* The size of message. Counted by byte */
    kal_uint32  user_elements_size;                 /* The size of MMS bodies */
    kal_uint32  date;                               /* The date field is in mms header of mms message. It should be given in seconds since 1.Jan. 1970 GMT. */
    kal_uint32  expiry_date;                        /* Expiration date. The format is relative second value. */
    kal_uint32  received_date;                      /* Received date. This value is only valied for these received MMS message. */
    kal_wchar   from_address[MMA_MAX_ADDR_LEN];     /* MMA_MAX_ADDR_LEN, From address of the MMS. Encoded by USC2 */
    kal_wchar subject[MMA_MAX_SUBJECT_LEN];         /* MMA_MAX_SUBJECT_LEN, Subject of the MMS. Encoded by USC2 */
    kal_uint8   app_data[MMA_MAX_APP_DATA_LENGTH];  /* Application data keep in MMS adaptor*/
    kal_uint8   java_app_id[100];                   /* Java application id. It is for JSR205 (Java MMS). Encoded by ASCII */
    kal_uint8   java_reply_app_id[100];             /* Java reply-application id. It is for JSR205 (Java MMS). Encoded by ASCII */
    kal_bool  need_read_report;                     /* Specify if the MMS message require to send read report to sender. */
    kal_bool  isRead;                               /* Specify if the MMS message is alraedy read. */
    kal_bool  isForwardlock;                        /* When MMS contain any DRM forward-lock or combine-delivery object, the value is KAL_TRUE. Because sepertae-delivery DRM object can be forwarded. */
    kal_bool  isDRM;                                /* When MMS contain any DRM object, the value is KAL_TRUE */
    kal_bool  isFollowPhoneMMSContentClass;         /* Specify if the MMS follow handset content class */   
    kal_bool    hasAttachment;                      /* Specify if the MMS message contain any attachment. */
    kal_uint8   app_id;                             /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   result;                             /* mma_result_enum */
	kal_uint8   storage_type;                       /* mma_msg_storage_type_enum*/
    kal_uint8   msg_media_type;                     /* mma_media_msg_enum */
    kal_uint8   from_address_type;                  /* mma_addr_type_enum */
    kal_uint8 msg_type;                             /* mma_msg_type_enum */
    kal_uint8 msg_class;                            /* mma_msg_class_enum */
    kal_uint8 priority;                             /* mma_priority_enum */
    kal_uint8   sim_id;                             /* mma_sim_id_enum */
}wap_mma_get_msg_info_rsp_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_SET_READMARK_REQ. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;   /* Request id */
    kal_uint32  msg_id;   /* Message id */
    kal_bool    readmark; /* Specify read status of the MMS */
    kal_uint8   app_id;   /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
}wap_mma_set_readmark_req_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_SET_READMARK_RSP. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id; /* Request id */
    kal_uint8   app_id; /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   result; /* mma_result_enum */    
}wap_mma_set_readmark_rsp_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_START_IMMED_RETRIEVAL_IND */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  msg_id; /* Message id */
    kal_uint8   sim_id; /* mma_sim_id_enum, specify which sim card is used to download the MMS */
}wap_mma_start_immed_retrieval_ind_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_STOP_IMMED_RETRIEVAL_IND */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  msg_id;      /* Message id */
    kal_uint32  error_cause; /* mma_result_enum */
    kal_uint8   result;      /* mma_result_enum */    
    kal_uint8   sim_id;      /* mma_sim_id_enum */
    kal_wchar response_text[MMA_MAX_RESPONSE_TEXT_LENGTH];    /* Encoded by UCS2 */
}wap_mma_stop_immed_retrieval_ind_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_SET_APP_DATA_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id; /* Request id */
    kal_uint32  msg_id; /* Message id */
    kal_uint8   app_id; /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   app_data[MMA_MAX_APP_DATA_LENGTH]; /* Data specified by MMS application */
}wap_mma_set_app_data_req_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_SET_APP_DATA_RSP */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id; /* Request id */
    kal_uint32  msg_id; /* Message id */
    kal_uint8   app_id; /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   result; /* mma_result_enum */    
}wap_mma_set_app_data_rsp_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_GET_MSG_LIST_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id; /* Request id */
    kal_uint32  folder; /* mma_folder_enum */
    kal_uint8   app_id; /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   storage; /* phone or memory card mma_msg_storage_type_enum */
}wap_mma_get_msg_list_req_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_GET_MSG_LIST_RSP */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;                         /* Request id */
    kal_uint32  no_of_msg;                      /*Total number of MMS messages in folder.*/
    kal_uint32  msg_id[MMA_MAX_MSG_ARRAY_NUM];  /* The array can store 399 msg_ids. The value of last item is 0. For emaple, if msg_id[10] is 0, it means there are 9 valid msg_ids from msg_id[0] ~ msg_id[9] */
    kal_bool    more;                           /* If no_of_msg is more than 399, the more flag will be KAL_TRUE. */
    kal_uint8   app_id;                         /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   result;                         /* mma_result_enum */  
}wap_mma_get_msg_list_rsp_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_STORAGE_FULL_IND */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  min_fs_space_required; /* When the value is more than 0, it means we don't have enoguh working file space to receive MMS */
    kal_uint8   result;     /* mma_result_enum */
}wap_mma_storage_full_ind_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_VIEW_MSG_IND */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  msg_id; /* Specify the message id of MMS will be played */
}wap_mma_view_msg_ind_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_MSG_IS_VALID_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;     /* Request id */
    kal_uint32  msg_id_list[MMA_MAX_MSG_ARRAY_NUM]; /* Array of message ids will be checked */
    kal_uint8   app_id;     /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
}wap_mma_msg_is_valid_req_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_MSG_IS_VALID_RSP */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;     /* Request id */
    kal_uint16  box[MMA_MAX_MSG_ARRAY_NUM]; /* mma_folder_enum */
    kal_uint8   app_id;     /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   result;     /* mma_result_enum */
    kal_uint8   msg_validity_list[MMA_MAX_MSG_ARRAY_NUM]; /* Array of validation result of message ids application requests to check */
}wap_mma_msg_is_valid_rsp_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_NOTIFY_EVENT_IND */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint16  event_id;   /* mma_event_enum */
    kal_uint8   app_id;     /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
}wap_mma_notify_event_ind_struct;

/* This structure is for MMA_EVENT_NEW_MSG defined in mma_event_enum */
typedef struct
{
    kal_uint32  msg_id; /* Message id */
    kal_uint32  date;   /* The date of receiving the MMS. Format of value is GMT time since 1. Jan. 1970, counted by second, no daylight saving. */
    kal_uint16  folder; /* mma_folder_enum */
    kal_uint16  report_status; /* if msg_type is RR, then it is mma_rr_status_enum. If msg_type is DR, it is mma_dr_status_enum */
    kal_uint8   msg_media_type; /* mma_media_msg_enum */
    kal_uint8   sim_id; /* mma_sim_id_enum */
    kal_uint8   msg_type; /* mma_msg_type_enum */
    kal_uint8   from_address_type;
    kal_wchar   from_address[MMA_MAX_ADDR_LEN];
}wap_mma_event_new_msg_struct;

/* This structure is for MMA_EVENT_DELETE_MSG defined in mma_event_enum */
typedef struct
{
    kal_uint32  msg_id; /* Message id */
    kal_uint16  folder; /* mma_folder_enum */
}wap_mma_event_delete_msg_struct;

/* This structure is for MMA_EVENT_SAVE_MSG defined in mma_event_enum */
typedef struct
{
    kal_uint32  msg_id; /* Message id */
    kal_uint16  folder; /* mma_folder_enum */
}wap_mma_event_save_msg_struct;

/* This structure is for MMA_EVENT_DELETE_FOLDER defined in mma_event_enum */
typedef struct
{
    kal_uint16  folder; /* mma_folder_enum */
}wap_mma_event_delete_folder_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_MMS_OBJ_IND */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;                                         /* Request id */
    kal_wchar   mms_filepath[MMA_MAX_EXTERNAL_FILE_PATH_LEN];   /* MMA_MAX_EXTERNAL_FILE_PATH_LEN, Encoded by USC2 */
    kal_uint8   app_id;                                         /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   msg_type;                                       /* mma_msg_type_enum */
    kal_uint8   sim_id;                                         /* mma_sim_id_enum, specify which sim card this MMS comes from */
}wap_mma_mms_obj_ind_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_MMS_OBJ_RES */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id; /* Request id */
    kal_uint8   app_id; /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   result; /* mma_result_enum */
}wap_mma_mms_obj_res_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_GET_UNREAD_MSG_LIST_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;               /* Request id */
    kal_uint32  start_index;          /* Start index of this request. 0 means the latest unread mms message. */
    kal_uint32  num_of_msg_requested; /* Number of messages this request needs */
    kal_uint8   app_id;               /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
}wap_mma_get_unread_msg_list_req_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_GET_UNREAD_MSG_LIST_RSP */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;                                                 /* Request id */
    kal_uint32  total_num_of_unread_msg;                                /* More unread message to be sent */
    kal_uint32  num_of_unread_msg;                                      /* specify how many items are in unread_msg_list[] */
#if defined (__MMI_OP11_HOMESCREEN__) || defined (__MMI_OP12_TOOLBAR__) || defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    mma_unread_msg_list_struct unread_msg_list[MMA_MAX_UNREAD_MSG_NUM]; /* MMA_MAX_UNREAD_MSG_NUM, Unread message list. */
#endif
    kal_uint8   app_id;                                                 /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   result;                                                 /* mma_result_enum */
    kal_uint8   more;                                                   /* 1: have more unread messages to be sent, 0: no more unread message */
}wap_mma_get_unread_msg_list_rsp_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_GET_RECENT_EVT_LIST_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;               /* Request id */
    kal_uint32  start_index;          /* Start index of this request. 0 means the latest recent event */
    kal_uint32  num_of_evt_requested; /* Number of events this request needs */
    kal_uint8   app_id;               /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
}wap_mma_get_recent_evt_list_req_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_GET_RECENT_EVT_LIST_RSP */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;             /* Request id */
    kal_uint32  total_num_of_evt;   /* Number of total events */
    kal_uint32  num_of_evt;         /* specify how many items are in event_list[] */
    mma_recent_evt_list_struct event_list[MMA_MAX_EVT_NUM]; /*MMA_MAX_EVT_NUM, Event list */
    kal_uint8   app_id;             /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   result;             /* mma_result_enum */
    kal_uint8   more;               /* 1: have more event to be sent, 0: no more event */
}wap_mma_get_recent_evt_list_rsp_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_DELETE_RECENT_EVT_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id; /* Request id */
    kal_uint32  msg_id; /* Message id, 0xFFFFFFFF means that MMA should remove all recent event list. */
    kal_uint8   app_id; /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
}wap_mma_delete_recent_evt_req_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_DELETE_RECENT_EVT_RSP */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id; /* Request id */
    kal_uint32  msg_id; /* Message id */
    kal_uint8   app_id; /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   result; /* mma_result_enum */
}wap_mma_delete_recent_evt_rsp_struct;

/* This structure is used by local parameter ofMSG_ID_WAP_MMA_SUSPEND_MMS_SERVICE_REQ  */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id; /* Request id */
    kal_uint8   app_id; /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
}wap_mma_suspend_mms_service_req_struct;

/* This structure is used by local parameter of ofMSG_ID_WAP_MMA_SUSPEND_MMS_SERVICE_RSP */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id; /* Request id */
    kal_uint8   app_id; /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   result; /* mma_result_enum */
}wap_mma_suspend_mms_service_rsp_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_RESUME_MMS_SERVICE_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id; /* Request id */
    kal_uint8   app_id; /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
}wap_mma_resume_mms_service_req_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_RESUME_MMS_SERVICE_RSP */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id; /* Request id */
    kal_uint8   app_id; /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   result; /* mma_result_enum */
}wap_mma_resume_mms_service_rsp_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_DRM_ENCODE_DONE_IND */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  result; /* mma_result_enum */
    kal_uint8   serial;
}wap_mma_drm_encode_done_ind_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_GET_MSG_PROPERTY_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;                        /* Request id */
    kal_uint32  no_of_msg;                     /* Num of messages in msg_id arrary */
    kal_uint32  msg_id[MMA_MAX_MSG_ARRAY_NUM]; /* MMA_MAX_MSG_ARRAY_NUM, Message id that application want to get property */
    kal_uint8   app_id;                        /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
}wap_mma_get_msg_property_req_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_GET_MSG_PROPERTY_RSP */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;                                          /* Request id */
    kal_uint32  result;                                          /* mma_result_enum */
    kal_uint32  num_of_msg;                                      /* Num of messages in msg_property arrary */
    mma_msg_property_struct msg_property[MMA_MAX_MSG_ARRAY_NUM]; /* MMA_MAX_MSG_ARRAY_NUM, Message property list */
    kal_uint8   app_id;                                          /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
}wap_mma_get_msg_property_rsp_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_GET_MSG_NUM_REQ. Application can fill any number of enums in request structure to get response.
Like
req_tb[0] = MMA_QUERY_OPTION_NUM_TOTAL_INBOX_SIM1;
req_tb[1] = MMA_QUERY_OPTION_NUM_TOTAL_DRAFT_MSG,
req_tb[2] = MMA_QUERY_OPTION_NUM_TOTAL_SENT_SIM1,
req_tb[3] = 0 => END of table
- - - - - - - - 
Rsp for above request will be.
rsp_tb[0] = 12
rsp_tb[1] = 10
rsp_tb[2] = 13
req_tb[3] = 0 =>END of table
*/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id; /* Request id */
    kal_uint32  req_tb[MMA_MAX_MSG_NUM_QUERY_NUM];/* MMA_MAX_MSG_NUM_QUERY_NUM, The request option array. Applicatio can put several query options in this array. MMA module will put result in another array and respond it to application. Final item of the arry MUST be 0. */
    kal_uint8   app_id; /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
}wap_mma_get_msg_num_req_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_GET_MSG_NUM_RSP */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;                           /* Request id */
    kal_uint32 rsp_tb[MMA_MAX_MSG_NUM_QUERY_NUM]; /* MMA_MAX_MSG_NUM_QUERY_NUM], Anwser to req_tb[] carried in wap_mma_get_msg_num_req_struct.*/
    kal_uint8   app_id;                           /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   result;                           /* mma_result_enum */    
}wap_mma_get_msg_num_rsp_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_SET_SIM_ID_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id; /* Request id */
    kal_uint32  msg_id; /* Message id */
    kal_uint8   app_id; /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8 sim_id;   /*mma_sim_id_enum*/
}wap_mma_set_sim_id_req_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_SET_SIM_ID_RSP */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id; /* Request id */
    kal_uint8   app_id; /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   result; /* mma_result_enum */    
}wap_mma_set_sim_id_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32  req_id; /* Request id */
    kal_uint32  msg_id; /* Message id */
    kal_uint8   app_id; /* application id */
    kal_uint8   dest_storage; /* phone or memory card mma_msg_storage_type_enum */
    kal_uint8   action_type;              /* mma_mms_storage_action_type_enum */
}wap_mma_change_msg_storage_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32  req_id; /* Request id */
    kal_uint32  msg_id; /* Message id */
    kal_uint8   app_id; /* application id */
    kal_uint8  result; /* mma_result_enum */
    kal_uint8 action_type;              /* mma_mms_storage_action_type_enum */
}wap_mma_change_msg_storage_rsp_struct;

/* To make another copy of mms in Archive folder */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32  req_id; /* Request id */
    kal_uint32  msg_id; /* Message id */
    kal_uint8   app_id; /* application id */
}wap_mma_cpy_msg_to_archive_folder_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32  req_id; /* Request id */
    kal_uint32  msg_id; /* Message id */
    kal_uint8   app_id; /* application id */
    kal_uint8  result; /* mma_result_enum */
}wap_mma_cpy_msg_to_archive_folder_rsp_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_RR_MARK_REQ. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;   /* Request id */
    kal_uint32  msg_id;   /* Message id */
    kal_uint8   rr_mark;  /* Specify read report send status of the MMS. 1 means RR in sending state; 0 means sent */
    kal_uint8   app_id;   /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_bool    rr_reset_all; /* for __DM_LAWMO_SUPPORT__ CMCC support */
}wap_mma_rr_mark_req_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_CHECK_TEMPLATE_RSP. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
     kal_uint8   app_id; /* application id */
     kal_uint8  result; /* mma_result_enum */
}wap_mma_check_template_rsp_struct;

/* This structure is used by local parameter of MSG_ID_WAP_MMA_RR_MARK_RSP. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id; /* Request id */
    kal_uint8   app_id; /* MMA_APP, application id, Ex: MMA_APP_ID_UC, MMA_APP_ID_UM, MMA_APP_ID_TEMPLATE,.. */
    kal_uint8   result; /* mma_result_enum */    
}wap_mma_rr_mark_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 msg_id;
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */    
    kal_uint8 mode;  /* mma_app_mode_enum */
    kal_uint8 edit_mode; /*mmi_uc_MMS_edit_mode_enum*/
    kal_uint8 sim_id; /*mmi_uc_sim_id*/
}wap_mma_uc_start_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 msg_id;
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */    
    kal_uint8 result;  /* mma_result_enum */
    kal_uint8 mode;  /* mma_app_mode_enum */
}wap_mma_uc_start_rsp_struct;

/*This structure is used to describe message attributes for the MMS. */
typedef struct
{
    kal_uint32 user_elements_size;
    kal_uint32 msg_size;
    kal_uint32 timestamp;
    kal_uint32 date;                               /* The date field is in mms header of mms message. It should be given in seconds since 1.Jan. 1970 GMT. */
    kal_uint32 expiry_date;                        /* Expiration date. The format is relative second value. */
    kal_bool is_follow_phone_mms_content_class;
    kal_bool is_forward_lock;
    kal_bool is_lock_mode;
    kal_bool is_msg_corrupt;
	kal_bool is_read;
	kal_bool need_read_report;
    kal_uint8 msg_type;
	kal_uint8 media_type;
    kal_uint8 folder;
    kal_uint8 msg_sim_id;
    kal_uint8 from_address_type;
    kal_uint8 msg_storage;
    kal_uint8 prev_folder;
    kal_uint8 msg_report_status;                    /* RR, DR report status */
    kal_wchar from_address[MMA_MAX_ADDR_LEN];
    kal_wchar subject[MMA_MAX_SUBJECT_LEN];         /* Subject of the MMS. Encoded by USC2 */
    kal_wchar reported_subject[MMA_MAX_SUBJECT_LEN];
}mma_sync_msg_attribute_struct;

typedef struct
{
	kal_uint16 addr_len;
    kal_uint8 addr_group; 	/* mma_address_group_type_enum */	
	kal_uint8 addr_type;    /* mma_addr_type_enum */
	kal_wchar address[MMA_MAX_ADDR_LEN];   /* Encoded by USC2 */
}mma_msg_addr_info_struct;

/*This structure is used to provide mms information in sync behavior. */
typedef struct
{
    kal_uint32 user_elements_size;
    kal_uint32 msg_size;
    kal_uint32 msg_download_size;   /* For notification */
    kal_uint32 date;                               /* The date field is in mms header of mms message. It should be given in seconds since 1.Jan. 1970 GMT. */
    kal_uint32 expiry_date;                        /* Expiration date. The format is relative second value. */
    kal_uint32 received_date;                      /* Received date. This value is only valid for these received MMS message. */
    kal_uint8 app_data[MMA_MAX_APP_DATA_LENGTH];  /* Application data keep in MMS adaptor*/
    kal_uint8 java_app_id[100];                   /* Java application id. It is for JSR205 (Java MMS). Encoded by ASCII */
    kal_wchar from_address[MMA_MAX_ADDR_LEN];
    kal_wchar subject[MMA_MAX_SUBJECT_LEN];         /* Subject of the MMS. Encoded by USC2 */
    kal_wchar reported_subject[MMA_MAX_SUBJECT_LEN];
    mma_msg_addr_info_struct address[MMA_MAX_SUPPORT_ADDR_COUNT];
    kal_bool  need_read_report;                     /* Specify if the MMS message require to send read report to sender. */
	kal_bool  need_delivery_report;                /* Specify if the MMS message require to send delivery report to sender. */
    kal_bool  isRead;                               /* Specify if the MMS message is already read. */
    kal_bool  isForwardlock;
    kal_bool  is_follow_phone_mms_content_class;
    kal_uint8 result;
    kal_uint8 storage_type;                       /* mma_msg_storage_type_enum*/
    kal_uint8 msg_media_type;                     /* mma_media_msg_enum */
    kal_uint8 from_address_type;
    kal_uint8 msg_type;
    kal_uint8 msg_class;                            /* mma_msg_class_enum */
    kal_uint8 priority;                             /* mma_priority_enum */
    kal_uint8 sim_id;                               /* mma_sim_id_enum */	
    kal_uint8 msg_report_status;                    /* RR, DR report status */
    kal_uint8 to_addr_count;
    kal_uint8 cc_addr_count;
    kal_uint8 bcc_addr_count;
}wap_mma_get_mms_msg_info_struct;

#define MMA_MAX_SIM_COUNT MMI_MAX_SIM_NUM

typedef enum
{
    MMA_INDEX_FOR_SIM_UNCLASSIFIED = 0,
    MMA_INDEX_FOR_SIM1,
    MMA_INDEX_FOR_SIM2,
    MMA_INDEX_FOR_SIM3,
    MMA_INDEX_FOR_SIM4,
    MMA_MAX_INDEX_FOR_SIM
}mma_index_for_id;

/* MMS count for the folders based on SIM ID */
typedef struct mms_mma_folder_mms_count_for_sim_id
{
    kal_uint16 inbox_unread_msg_num;
    kal_uint16 inbox_read_msg_num;
    kal_uint16 unsent_msg_num;
    kal_uint16 sent_msg_num;
    kal_uint16 archive_unread_inbox_msg_num;
    kal_uint16 archive_read_inbox_msg_num;
    kal_uint16 archive_sent_msg_num;
}mms_mma_folder_mms_count_for_sim_id;

typedef struct mma_mms_folder_mms_count_status_struct
{
    kal_uint16 draft_msg_num;
    kal_uint16 predefined_template_msg_num;
    kal_uint16 userdefined_template_msg_num;
    kal_uint16 archive_msg_num;
    kal_uint16 recent_event_number;
    kal_uint16 unread_report_msg_num;
    kal_uint16 total_phone_mms;
    kal_uint16 total_mcard_mms;
    struct mms_mma_folder_mms_count_for_sim_id folder[MMA_MAX_INDEX_FOR_SIM];     
} mma_mms_folder_mms_count_status_struct;

/* Global context to provide the report status for the SENT folder mms */
typedef struct wap_mma_mms_msg_report_status_st
{
	kal_uint16 addr_len;
    kal_uint8 addr_group; 	/* mma_address_group_type_enum */	
	kal_uint8 addr_type;    /* mma_addr_type_enum */
    kal_uint8 rr_status;    /* Read report status for this address */ 		
	kal_uint8 dr_status;    /* Delivery report status for this address */
	kal_wchar address[MMA_MAX_ADDR_LEN];   /* Encoded by USC2 */
	struct wap_mma_mms_msg_report_status_st *next;	/* To create the address list */
}wap_mma_mms_msg_report_status_struct;

/* Global context to provide the report status for the Report ID */
typedef struct
{
    kal_uint32 orig_msgId;  /* Original msg_id for which this report come */
    kal_uint32 date;
    kal_uint16 addr_len;
    kal_uint8 storage_type;    /* Storage of the MMS */
    kal_uint8 report_type;    /* Read/Delivery report. 0 means DR, 1 means RR */
    kal_uint8 status;    /* Read/Delivery report status for this address */
    kal_uint8 sim_id;    /* sim ID status. For Dual SIM */
    kal_uint8 addr_type;    /* Phone/Email */    
    kal_wchar address[MMA_MAX_ADDR_LEN];   /* Encoded by UCS2 */
}mma_mms_msg_report_info_struct;

/*This structure is used to provide mms information for the Icon in sync behavior. */
typedef struct
{
    kal_uint8 msg_type;
    kal_uint8 priority;                             /* mma_priority_enum */
    kal_uint8 sim_id;                               /* mma_sim_id_enum */
}wap_mma_get_mms_msg_icon_info_struct;

/*This structure is used to provide mms Objects information in sync behavior. */
typedef struct
{
    kal_uint32 body_size;
    kal_uint32 body_offset;
	kal_uint16 body_name_len;	/* not for text file of the MMS*/
	kal_uint16 txt_encoding_scheme;
    kal_uint8 body_type;         /* Text, Image, Audio, Video */
    kal_uint8 is_drm;         /* DRM or not */
	kal_wchar body_name[MMA_MAX_MMS_BODY_FILE_NAME_LEN];	/* not for text file of MMS*/
}wap_mma_get_mms_body_objects_info_struct;

/*This structure is used to provide mms thumbnail infomration in sync behavior. */
typedef struct
{
    kal_uint32 msg_download_size;  /* Downloaded mms size for the Notification */
    wap_mma_get_mms_body_objects_info_struct thumbnail_info;   /* mma_media_msg_enum */
    wap_mma_get_mms_body_objects_info_struct thumbnail_info_txt;   /* mma_media_msg_enum */
    kal_wchar subject[MMA_MAX_SUBJECT_LEN];         /* Subject of the MMS. Encoded by USC2 */
}wap_mma_get_mms_thumbnail_info_struct;

typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;   /* Request id */
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */    
    kal_uint32  msg_id;   /* Message id */
  
}wap_mma_get_mms_thumbnail_and_attr_info_req_struct;


typedef struct
{
    kal_uint32 timestamp; 
	kal_uint8 msg_type;	/*Msg type mma_msg_type_enum*/
	kal_uint8 storage_type;
    kal_uint32 msg_size;
    kal_uint8 msg_sim_id;
    wap_mma_get_mms_thumbnail_info_struct body_header_data;   /* mma_media_msg_enum */
}wap_mma_get_mms_thumbnail_and_attr_info_struct;

typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32 result;  /* result returned by MMA */
    kal_uint32 req_id;
    kal_uint8 app_id;
    kal_uint32  msg_id;   /* Message id */
    wap_mma_get_mms_thumbnail_and_attr_info_struct attr_tbm_info;   /* mma_media_msg_enum */
}wap_mma_get_mms_thumbnail_and_attr_info_rsp_struct;

#endif  /* End of _MMA_STRUCT_H */

