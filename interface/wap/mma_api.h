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
 *   mma_api.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMA_API_H
#define _MMA_API_H

#include "MMI_features.h"

#include "kal_general_types.h"

/**********************************************************************
 * ENUM definition
 **********************************************************************/

/*Application start mode which would affect MMS content request.
Please refer to XML description file section for detail information.
*/
typedef enum
{
    MMA_MODE_EDIT,        /* XML[O]: Header+body (already adjusted for UC), Application use this mode to create MMS */
    MMA_MODE_SEND,        /* XML[O]: Header+body; XML[I]: Header (already adjusted for UC) */
    MMA_MODE_REPLY,       /* XML[I/O]: Header (already adjusted for UC) */
    MMA_MODE_REPLY_ALL,   /* XML[I/O]: Header (already adjusted for UC) */
    MMA_MODE_FORWARD,     /* XML[O]: Header+body; XML[I]: Header (already adjusted for UC) */
    MMA_MODE_UPLOAD,      /* Used in MMC uploading MMS file */
    MMA_MODE_HEADER,      /* XML[O]: Header, Use in get content to get complete MMS header information */
    MMA_MODE_VIEW,        /* XML[O]: Header+body, Use in get content to get complete MMS header+body information. */
    MMA_MODE_RAW,         /* XML[I/O]: Header+body (RAW), Used in MMC parse/create JSR MMS file */
    MMA_MODE_INT_PARSE,   /* MMA internal use for info extract */
    MMA_MODE_ABORT,       /* To abort an operation (only get content request support this mode) */
    MMA_MODE_POSTCARD,    /* To create a postcard MMS */    
	MMA_MODE_MIXED,       /* To create a Mixed MMS */
#if (defined(__MMI_MMS_VENDOR_APP_SUPPORT__) || defined(__MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__))
	MMA_MODE_VENDOR_XML,		/*to create message for XML file arriving from vendor*/
#endif	/* __MMI_MMS_VENDOR_APP_SUPPORT__ , __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__*/

    MMA_MODE_TEMPLATE     /* To create a Template*/
}mma_app_mode_enum;

/* This enum is used to specify operation results. */
typedef enum
{
    MMA_RESULT_OK,                              /* 0 */
    MMA_RESULT_DELAYED,                         /* 1 */
    MMA_RESULT_CONTINUE,                        /* 2 */
    MMA_RESULT_FAIL,                            /* 3 */
    MMA_RESULT_FAIL_IN_CALL,                    /* 4 */
    MMA_RESULT_FAIL_NOT_READY,                  /* 5 */
    MMA_RESULT_FAIL_BUSY,                       /* 6 */
    MMA_RESULT_FAIL_INSUFFICIENT_MEMORY,        /* 7 */
    MMA_RESULT_FAIL_INSUFFICIENT_STORAGE,       /* 8 */
    MMA_RESULT_FAIL_MAX_MSG_NUM_REACHED,        /* 9 */
    MMA_RESULT_FAIL_MAX_MSG_SIZE_REACHED,       /* 10 */
    MMA_RESULT_FAIL_MAX_SLIDE_NUM_REACHED,      /* 11 */
    MMA_RESULT_FAIL_MAX_ATTACHMENT_NUM_REACHED, /* 12 */
    MMA_RESULT_FAIL_FILE_EMPTY,                 /* 13 */
    MMA_RESULT_FAIL_FILE_NOT_FOUND,             /* 14 */
    MMA_RESULT_FAIL_FILE_CORRUPTED,             /* 15 */
    MMA_RESULT_FAIL_FILE_IN_USE,                /* 16 */
    MMA_RESULT_FAIL_FILE_IO,                    /* 17 */
    MMA_RESULT_FAIL_FOLDER_NOT_FOUND,           /* 18 */
    MMA_RESULT_FAIL_UNSUPPORT_CONTENT,          /* 19 */
    MMA_RESULT_FAIL_COMM_UNSUPPORT_CONTENT,     /* 20 */
    MMA_RESULT_FAIL_COMM_CONFIG_ERROR,          /* 21 */
    MMA_RESULT_FAIL_COMM_CONNECT_ERROR,         /* 22 */
    MMA_RESULT_FAIL_COMM_SERVER_ERROR,          /* 23 */
    MMA_RESULT_FAIL_COMM_SERVER_TIMEOUT,        /* 24 */
    MMA_RESULT_FAIL_COMM_SERVICE_DENIED,        /* 25 */
    MMA_RESULT_FAIL_COMM_UNKNOWN_APN,           /* 26 */
    MMA_RESULT_FAIL_COMM_UNAUTHORIZED,          /* 27 */
    MMA_RESULT_FAIL_USER_CANCEL,                /* 28 */
    MMA_RESULT_FAIL_INVALID_PARAMETER,          /* 29 */
    MMA_RESULT_FAIL_INVALID_MSGID,              /* 30 */
    MMA_RESULT_FAIL_INVALID_FOLDER,             /* 31 */
    MMA_RESULT_FAIL_QUEUE_FULL,                 /* 32 */
    MMA_RESULT_FAIL_PARSE,                      /* 33 */
    MMA_RESULT_FAIL_MSGID_IS_USING,             /* 34 */
    MMA_RESULT_FAIL_CREATION_MODE_MAX_MSG_SIZE_REACHED,    /* 35 */
    MMA_RESULT_FAIL_UPDATE_CHECKSUM_INVALID_PARAM,         /* 36 */
    MMA_RESULT_FAIL_IN_USB_MODE,                /* 37 */
    MMA_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE,    /* 38 */
    MMA_RESULT_FAIL_TERMINATING,                /* 39 */
    MMA_RESULT_FAIL_USERDEF_TEMPLATE_FULL,      /* 40 */
    MMA_RESULT_FAIL_WAP_CONN_MAX_MSG_SIZE_REACHED,         /* 41 */
    MMA_RESULT_OK_WITH_WARNING_CONTENT,         /* 42 */
    MMA_RESULT_ABORTED,                         /* 43 */
    MMA_RESULT_FAIL_SUSPENDED_MODE,             /* 44 */
    MMA_RESULT_FAIL_MSG_EXPIRED,                /* 45 */
    MMA_RESULT_FAIL_IN_VIDEO_CALL,              /* 46 */ 
    MMA_RESULT_FAIL_IMAGE_TOO_LARGE,            /* 47 */ 
    MMA_RESULT_FAIL_MEM_CARD_NOT_PRESENT,       /* 48 */
    MMA_RESULT_FAIL_MEM_CARD_NOT_PRESENT_USE_PHONE,       /* 49 */ 
    MMA_RESULT_FAIL_MEM_CARD_NOT_PRESENT_INSERT_CARD,      /* 50 */  
    MMA_RESULT_FAIL_MAX_MSG_REACHED_ON_PHONE_MEMORY,      /* 51 */
    MMA_RESULT_FAIL_MAX_MSG_REACHED_ON_MEM_CARD,           /* 52 */
    MMA_RESULT_FAIL_MEM_CARD_PLUG_OUT,          /* 53 */
    MMA_RESULT_FAIL_UNSUPPORT_MMS_TYPE,
    MMA_RESULT_FAIL_ROOT_DIR_FULL,
                /*NEW ADDED AS REMOVAL OF SLS*/
    MMA_SMIL_RESULT_SMIL_NOT_CREATED,
    MMA_SMIL_RESULT_MISSING_MEDIA_OBJECTS,
    MMA_SMIL_RESULT_MISSING_MEDIA_OBJECT_SRC,
    MMA_RESULT_END
}mma_result_enum;

/* This enum is used to specify MMS folder. */
typedef enum
{
    MMA_FOLDER_NONE = 0x0,
    MMA_FOLDER_INBOX = 0x1,
    MMA_FOLDER_OUTBOX = 0x2,
    MMA_FOLDER_SENT = 0x4,
    MMA_FOLDER_DRAFT = 0x8,
    MMA_FOLDER_TEMPLATE = 0x10,        /* This folder is for predefined MMS template */
    MMA_FOLDER_USRDEF_TEMPLATE = 0x20, /* This folder is for user to save MMS as template */
    MMA_FOLDER_ARCHIVE = 0x40,
    MMA_FOLDER_HIDDEN = 0x80,
    MMA_FOLDER_REPORT_BOX = 0x100,
    MMA_FOLDER_ALL = 0xFFFF
}mma_folder_enum;

/* This enum is used to specify MMS creation mode. */
typedef enum
{
    MMA_CREATION_MODE_FREE,        /* Creation mode: Free*/
    MMA_CREATION_MODE_RESTRICTED,  /* Creation mode: Restricted */
    MMA_CREATION_MODE_WARNING      /* Creation mode: Warning*/
}mma_creation_mode_enum;

/* This enum is used to specify the MMS priority. */
typedef enum
{
    MMA_PRIORITY_NOT_SET,  /*Prority is not defined */
    MMA_PRIORITY_LOW,      /*Prority is low */
    MMA_PRIORITY_MEDIUM,   /*Prority is medium */
    MMA_PRIORITY_HIGH      /*Prority is high */
}mma_priority_enum;

/* This enum is used to specify MMS expiry time. Count by seconds*/
typedef enum
{
    MMA_EXPIRY_NOT_SET = 0,           /* epxiry time is not defined */
    MMA_EXPIRY_1_HOUR = 3600,         /* epxiry time is 1 hour */
    MMA_EXPIRY_6_HOURS = 21600,       /* epxiry time is 6 hours */ 
    MMA_EXPIRY_12_HOURS = 43200,      /* epxiry time is 12 hours */ 
    MMA_EXPIRY_1_DAY = 86400,         /* epxiry time is 1 day */
    MMA_EXPIRY_1_WEEK = 604800,       /* epxiry time is 1 week */
    MMA_EXPIRY_MAX = 0                /* epxiry time is not defined */
}mma_expiry_time_enum;

/* This enum is used to specify MMS delivery time. */
typedef enum
{
    MMA_DELIVERY_NOT_SET = 0,        /* delivery time is not defined */
    MMA_DELIVERY_IMMEDIATE = 0,      /* delivery time is 0 hour */     
    MMA_DELIVERY_1_HOUR = 3600,      /* delivery time is 1 hours */
    MMA_DELIVERY_2_HOUR = 7200,      /* delivery time is 2 hours */
    MMA_DELIVERY_12_HOURS = 43200,   /* delivery time is 12 hours */   
    MMA_DELIVERY_24_HOURS = 86400    /* delivery time is 1 day */      
}mma_delivery_time_enum;             

/* This enum is used to specify the MMS header field type. */                                     
typedef enum
{
    MMA_HEADER_UNKNOWN,  /* Unknowm */
    MMA_HEADER_ADDRESS,  /* Address */
    MMA_HEADER_SUBJECT   /* Subject */
}mma_header_attr_enum;

/* This enum is used to specify the media type which the object will be inserted as. */
typedef enum
{
    MMA_INSERT_UNKNOWN,    /* Unknown */
    MMA_INSERT_TEXT,       /* Text */
    MMA_INSERT_IMAGE,      /* image */
    MMA_INSERT_AUDIO,      /* audio */
    MMA_INSERT_VIDEO,      /* video */
    MMA_INSERT_REF,        /* object embeded in <ref> tag */
    MMA_INSERT_ATTACHMENT  /* attachment */
}mma_insert_type_enum;

/*This enum is used to specify the DRM type.*/
typedef enum
{ 
    MMA_DRM_NONE,              /*Not DRM object*/
    MMA_DRM_FL_CD,             /* forward-lock or combined delivery */
    MMA_DRM_SD,                /* seperate-delivery */
    MMA_DRM_SD_NO_RIGHT,       /* Separate-delivery object without right */
    MMA_DRM_PDCF_V2,           /* DRM v2.0 PDCF or V2 object */
    MMA_DRM_PDCF_V2_NO_RIGHT,  /* DRM v2.0 PDCF or V2 object without right */
    MMA_DRM_TYPE_TOTAL
}mma_drm_type_enum;
           
/*This enum is used to specify slide layout.*/
typedef enum
{
    MMA_LAYOUT_NONE,          /* No relative layout specification */
    MMA_LAYOUT_IMAGE_ON_TOP,  /* Image on top; text on bottom */
    MMA_LAYOUT_TEXT_ON_TOP,   /* Text on top; image on bottom */
    MMA_LAYOUT_IMAGE_AT_LEFT, /* Image at left; text at right */
    MMA_LAYOUT_TEXT_AT_LEFT   /* Text at left; image at right */
}mma_slide_layout_enum;

/* This enum is used to specify connection type. */
typedef enum
{
    MMA_CONN_TYPE_HTTP_PROXY,   /* HTTP connection with proxy */
    MMA_CONN_TYPE_HTTP_DIRECT,  /* HTTP connection without proxy */
    MMA_CONN_TYPE_WSP_CL,       /* WSP connectionless */
    MMA_CONN_TYPE_WSP_CO,       /* WSP connection oriented */
    MMA_CONN_TYPE_WSP_SEC_CL,   /* WSP connectionless with security */
    MMA_CONN_TYPE_WSP_SEC_CO    /* WSP connection oriented with security */
}mma_connection_type_enum;

/* This enum is used to specify 'text style' like bold and italic. Also, these two are mutually exclusive. */
typedef enum
{
	MMA_TEXT_STYLE_NONE = 0x00,		/* None */
    MMA_TEXT_STYLE_BOLD = 0x01,   /* Bold text */
    MMA_TEXT_STYLE_ITALIC = 0x02  /* Italic text */
}mma_text_style_enum;

/* This enum is used to specify 'text size */
typedef enum
{
    MMA_TEXT_SIZE_SMALL = 1,  /* Small text */
    MMA_TEXT_SIZE_MEDIUM,     /* Medium text */
    MMA_TEXT_SIZE_LARGE       /* Large text */
}mma_text_size_enum;

/* This enum is used to specify address group type. */
typedef enum
{
    MMA_ADDRESS_GROUP_TYPE_TO,
    MMA_ADDRESS_GROUP_TYPE_CC,
    MMA_ADDRESS_GROUP_TYPE_BCC,
    MMA_ADDRESS_GROUP_TYPE_FROM,
    MMA_ADDRESS_GROUP_TYPE_TOTAL_NUM
} mma_address_group_type_enum;

/* This enum is used to specify address type. */
typedef enum
{
    MMA_ADDR_TYPE_NONE,          /* Unknown */
    MMA_ADDR_TYPE_PHONE_NUMBER,  /* Phone number */
    MMA_ADDR_TYPE_EMAIL,          /* Email */
    MMA_ADDR_TYPE_IPV4           /* IPv4 */
}mma_addr_type_enum;

/* This enum is used to specify message class. */
typedef enum
{
	MMA_MSG_CLASS_NOT_SET,
    MMA_MSG_CLASS_PERSONAL,         /* MMS message is created by person */
    MMA_MSG_CLASS_ADVERTISEMENT,    /* MMS message is for advertisement */
    MMA_MSG_CLASS_INFORMATIONAL,    /* MMS message is for informational */
    MMA_MSG_CLASS_AUTO              /* MMS message is created automatically */
}mma_msg_class_enum;

/* This enum is used to specify message type. */
typedef enum
{
    MMA_MSG_TYPE_NOTIFICATION,     /* MMS notification */
    MMA_MSG_TYPE_DELIVERY_REPORT,  /* MMS delivery report */
    MMA_MSG_TYPE_READ_REPORT,      /* MMS read report v1.1 */
    MMA_MSG_TYPE_MMS,              /* normal MMS message */
    MMA_MSG_TYPE_JAVA,             /* Java MMS */   
    MMA_MSG_TYPE_TEMPLATE,         /* MMS template */
    MMA_MSG_TYPE_POSTCARD,          /* MMS postcard */
    MMA_MSG_TYPE_UNSUPPORTED
}mma_msg_type_enum;

/* This enum is used to specify message status.*/
typedef enum
{
    MMA_MSG_STATUS_WAITING_SENDING,      /* The status is for msg in outbox */
    MMA_MSG_STATUS_SENDING,              /* The status is for msg in outbox */
    MMA_MSG_STATUS_WAITING_DOWNLOADING,  /* The status is for msg in inbox folder */
    MMA_MSG_STATUS_DOWNLOADING,          /* The status is for msg in inbox folder */
    MMA_MSG_STATUS_NORMAL,               /* It is for template, draft, received MMS, delivery report and read report. */
    MMA_MSG_STATUS_FAILED                /* The status is for msg in sent or inbox folder. In case of inbox folder, the msg shall be mms notification. */
}mma_msg_status_enum;

/* This enum is used to specify retrieval mode. */
typedef enum
{
    MMA_RETRIEVAL_MODE_IMMED,    /* Immediate retrieval */
    MMA_RETRIEVAL_MODE_DEFERRED, /* delayed retrieval */
    MMA_RETRIEVAL_MODE_REJECT,   /* Reject to retrieve MMS message */
    MMA_RETRIEVAL_MODE_AS_HOME   /* Same as setting in home network */
}mma_retrieval_mode_enum;

/* This enum is used to specify delivery report status (value refer to X-Mms-Status header field). */
typedef enum
{
    MMA_DR_STATUS_PENDING = 0,
    MMA_DR_STATUS_EXPIRED = 0x80,       /* MMS is expired */
    MMA_DR_STATUS_RETRIEVED = 0x81,     /* MMS is retrieved */
    MMA_DR_STATUS_REJECTED = 0x82,      /* MMS is rejected */
    MMA_DR_STATUS_DEFERRED = 0x83,      /* MMS is defered */
    MMA_DR_STATUS_UNRECOGNISED = 0x84,  /* MMS is unrecognized */
    MMA_DR_STATUS_INDETERMINATE = 0x85, /* MMS is indeterminate */
    MMA_DR_STATUS_FORWARDED = 0x86,     /* MMS is forwarded */
    MMA_DR_STATUS_UNREACHABLE = 0x87    /* MMS is unreachable */
}mma_dr_status_enum;

/*This enum is used to specify read report status (value refer to X-Mms-Read-Status header field).*/
typedef enum
{
    MMA_RR_STATUS_PENDING = 0,
    MMA_RR_STATUS_READ = 0x80,              /* MMS is read */
    MMA_RR_STATUS_DELETED_NO_READ = 0x81    /* MMS is deleted without reading */
}mma_rr_status_enum;

/* This enum is used to specify MMS version (value refer to X-Mms-MMS-Version). */
typedef enum
{
    MMA_VERSION_10 = 0x10,  /* MMS V1.0 */
    MMA_VERSION_11 = 0x11,  /* MMS V1.1 */
    MMA_VERSION_12 = 0x12   /* MMS V1.2 */
}mma_version_enum;

/* This enum is used to specify region fit parameter. */
typedef enum
{
    MMA_REGION_FIT_NONE,    /* Not specified */
    MMA_REGION_FIT_MEET,    /* Scale the object so that its aspect ratio is kept, and it is stays fully visible  */
    MMA_REGION_FIT_SCROLL,  /* Scale the object so that its aspect ratio is kept, and some parts are cropped */
    MMA_REGION_FIT_HIDDEN,  /* Do not resize the media object, but fill the box with the background color, or crop the object  */
    MMA_REGION_FIT_FILL,    /* Resize the media object so that it fills the width and height defined in the SMIL document  */
    MMA_REGION_FIT_SLICE    /* Add a scrolling mechanism if the object exceeds the box */
}mma_region_fit_enum;

/* This enum is used to specify text encoding charset (value refer to IANA MIBEnum).*/
typedef enum
{
    MMA_CHARSET_UNKNOWN = 0,        /* Not specified */
    MMA_CHARSET_ASCII = 3,          /* ASCII */
    MMA_CHARSET_ISO_8859_1 = 4,     /* ISO 8859-1 */
    MMA_CHARSET_UTF8 = 106,         /* UFT8 */
    MMA_CHARSET_UCS2 = 1000,        /* UCS2 */
    MMA_CHARSET_UTF16BE = 1013,     /* UTF16BE */
    MMA_CHARSET_UTF16LE = 1014,     /* UTF16LE */
    MMA_CHARSET_UTF16 = 1015,       /* UTF16 */
    MMA_CHARSET_GB2312 = 2025,      /* GB2312 */
    MMA_CHARSET_BIG5 = 2026         /* BIG5 */
}mma_charset_enum;

/* This enum is used to specify UC filter mode. */
typedef enum
{
    MMA_UC_FILTER_MODE_AUDIO_OPEN_MODE, /*audio type when creation mode is free*/
    MMA_UC_FILTER_MODE_IMAGE_OPEN_MODE, /*image type when creation mode is free*/
    MMA_UC_FILTER_MODE_TEXT_OPEN_MODE, /*text type when creation mode is free*/
    MMA_UC_FILTER_MODE_VIDEO_OPEN_MODE, /*video type when creation mode is free*/    
    MMA_UC_FILTER_MODE_ATTACHMENT_OPEN_MODE, /*image type when creation mode is free*/
    MMA_UC_FILTER_MODE_AUDIO_RESTRICTED_MODE, /*audio type when creation mode is restricted*/
    MMA_UC_FILTER_MODE_IMAGE_RESTRICTED_MODE, /*image type when creation mode is restricted*/
    MMA_UC_FILTER_MODE_TEXT_RESTRICTED_MODE, /*text type when creation mode is restricted*/
    MMA_UC_FILTER_MODE_VIDEO_RESTRICTED_MODE, /*video type when creation mode is restricted*/
    MMA_UC_FILTER_MODE_ATTACHMENT_RESTRICTED_MODE /*image type when creation mode is restricted*/
}mma_uc_filter_mode_enum;

/* This enum is used to specify UC filter mode. */
typedef enum
{
    MMA_EVENT_NEW_MSG,                  /* For new message */
    MMA_EVENT_DELETE_MSG,               /* When one message is deleted. Send after delete. */
    MMA_EVENT_SAVE_MSG,                 /* When one message is saved to another folder. Send after saved. */
    MMA_EVENT_DELETE_FOLDER,            /* Send before delete a folder */
    MMA_EVENT_UM_DELETE_FOLDER_DONE,    /* Send after MMA finish deleting folder */
    MMA_EVENT_TOTAL
}mma_event_enum;

/* This enum is used to specify MMS contains only one media type objects. */
typedef enum
{
    MMA_MEDIA_MSG_NONE = 0, /* Not specified */
    MMA_MEDIA_MSG_TEXT,     /* Text MMS: One MMS only contains text object */
    MMA_MEDIA_MSG_AUDIO,    /* Audio MMS: One MMS only contains audio object */
    MMA_MEDIA_MSG_PHOTO,    /* Photo MMS: One MMS only contains image object */
    MMA_MEDIA_MSG_VIDEO     /* Video MMS: One MMS only contains video object */
} mma_media_msg_enum;

/* This enum is used to specify MMS is a Mixed MMS or SMIL MMS */
typedef enum
{
    MMA_MMS_TYPE_SMIL_MMS = 0,  /* MMS has SMIL part */
    MMA_MMS_TYPE_MIXED_MMS,     /* MMS is a Mixed MMS */
    MMA_MMS_TYPE_TOTAL
}mma_mms_type_enum;

/* This enum is used to specify MMS sending size limit */
typedef enum
{
    MMA_SETTING_SIZE_LIMIT_100 = 102400,    /* 100KB */
    MMA_SETTING_SIZE_LIMIT_300 = 307200,    /* 300KB */
    MMA_SETTING_SIZE_LIMIT_600 = 614400,    /* 600KB */
    MMA_SETTING_SIZE_LIMIT_MAX 	
}mma_setting_size_limit_enum;

typedef enum
{
    MMA_TRUNCATED_ATTACHMENT = 0X01,
    MMA_TRUNCATED_SLIDE = 0X02,
    MMA_TRUNCATE_TEXT = 0X04,
    MMA_TRUNCATED_TOTAL = 0XFF	
}mma_content_truncated_enum;


typedef enum
{
    MMA_MSG_STORAGE_NONE = 0X00,
    MMA_MSG_STORAGE_PHONE = 0X01,
    MMA_MSG_STORAGE_CARD1 = 0X02,
    MMA_MSG_STORAGE_TOTAL = 0X03 
} mma_msg_storage_type_enum;

typedef enum
{
    MMA_MMS_STORAGE_ACTION_COPY_MMS, 
    MMA_MMS_STORAGE_ACTION_MOVE_MMS, 
    MMA_MMS_STORAGE_ACTION_TOTAL
}mma_mms_storage_action_type_enum;

/* This enum is used to specify delivery report status (value refer to X-Mms-Status header field). */
typedef enum
{
    MMA_MSG_ICON_STATUS_NONE = 0,
    MMA_MSG_ICON_STATUS_WAITING_FOR_SEND,       /* MMS status is waiting sending */
    MMA_MSG_ICON_STATUS_SENDING,     /* MMS status is sending */
    MMA_MSG_ICON_STATUS_SEND_FAIL,      /* MMS status is send failed */
    MMA_MSG_ICON_STATUS_POSTPONE_FOR_SEND,      /* MMS status is defered to send*/
    MMA_MSG_ICON_STATUS_CORRUPTED_MMS,      /* MMS status is corrupted mms*/
    MMA_MSG_ICON_STATUS_JAVA_MMS,  /* MMS status is JAVA mms */
    MMA_MSG_ICON_STATUS_PRIO_HIGH_MMS, /* MMS status is high priority MMS */
    MMA_MSG_ICON_STATUS_PRIO_LOW_MMS,     /* MMS status is low priority MMS */
    MMA_MSG_ICON_STATUS_PRIO_MED_MMS,   /* MMS status is Medium/default priority MMS */
    MMA_MSG_ICON_STATUS_DR_MMS,   /* MMS status is Delivery Report */
    MMA_MSG_ICON_STATUS_RR_MMS,   /* MMS status is Read Report */
    MMA_MSG_ICON_STATUS_DRAFT_MMS,   /* MMS status is draft/Normal MMS */
    MMA_MSG_ICON_STATUS_NOTIFICATION_MMS,  /* MMS status is Notification */
    MMA_MSG_ICON_TOTAL_MAX_STATUS   /* Total MAX MMS status */
}mma_msg_icon_status_enum;




typedef enum
{
    MMA_MMS_FROM_ADDRESS_PRESENT = 128, /*!< The address is added by the client */
    MMA_MMS_FROM_INSERT_ADDRESS  = 129  /*!< The address is added by the server */
} mma_mms_from_type_enum;






typedef enum
{
    MMA_MMS_TIME_ABSOLUTE           = 128,
    MMA_MMS_TIME_RELATIVE           = 129
} mma_mms_time_type_enum;




typedef enum 
{
    MMA_MMS_MSG_TYPE_SEND_REQ = 128,      /*!< Send request message */
    MMA_MMS_MSG_TYPE_RETRIEVE_CONF = 132  /*!< Retrieve confirm */
}mma_mms_msg_type_enum;


typedef enum
{
    MMA_MMS_READ_REPLY_NOT_SET  =   0,
    MMA_MMS_READ_REPLY_YES      = 128,      /*!< Read reply is requested. */
    MMA_MMS_READ_REPLY_NO       = 129       /*!< Read reply is not requested. */
} mma_mms_read_reply_enum;




typedef enum
{
    MMA_MMS_DELIVERY_REPORT_NOT_SET =   0,
    MMA_MMS_DELIVERY_REPORT_YES     = 128,  /*!< Delivery report is requested. */
    MMA_MMS_DELIVERY_REPORT_NO      = 129   /*!< Delivery report is not requested. */
} mma_mms_delivery_report_enum;





typedef enum
{
    MMA_MMS_SENDER_VISIBILITY_NOT_SET   =   0,  /*!< Show unless sender has secret address*/
    MMA_MMS_SENDER_HIDE                 = 128,  /*!< Don't show the address. */
    MMA_MMS_SENDER_SHOW                 = 129   /*!< Show even secret address. */
} mma_mms_sender_visibility_enum;















        

    






typedef enum
{
    MMA_MMS_OBJECT_TYPE_IMAGE,
    MMA_MMS_OBJECT_TYPE_AUDIO,
    MMA_MMS_OBJECT_TYPE_VIDEO,
    MMA_MMS_OBJECT_TYPE_TEXT,
    MMA_MMS_OBJECT_TYPE_ATTACHMENT,
	MMA_MMS_OBJECT_TYPE_REF,	/*needed by UC*/
    MMA_MMS_OBJECT_TYPE_UNKNOWN,
    MMA_MMS_OBJECT_TYPE_MAX
} mma_mms_viewer_object_type_enum;

/* This enum is used to define UC current state of operation. It will be need to set when launch UC. As each state have different type of flow. */
typedef enum
{
    MMA_MMS_STATE_WRITE_NEW_MSG,     /* Writing new msg state. */
    MMA_MMS_STATE_EDIT_EXISTED_MSG,  /* Edit existing msg state. */
    MMA_MMS_STATE_FORWARD,           /* Forward existing msg state. Only for inbox and sent box msgs. */
    MMA_MMS_STATE_SEND,              /* Send existing msg state. Only for outbox and draft box msgs. */
    MMA_MMS_STATE_REPLY,             /* Reply existing msg state. */
    MMA_MMS_STATE_REPLY_ALL,         /* Reply all existing msg state. */
    MMA_MMS_STATE_TOTAL_NUM          /* Max number of msg states in UC. */
} mma_mms_state_enum;

/* This enum is used to specify the group types of addresses. */
typedef enum
{
    MMA_MMS_ADDRESS_GROUP_TYPE_TO,       /* To group. */
    MMA_MMS_ADDRESS_GROUP_TYPE_CC,       /* Cc group. */
    MMA_MMS_ADDRESS_GROUP_TYPE_BCC,      /* Bcc group. */
    MMA_MMS_ADDRESS_GROUP_TYPE_FROM,     /* From group. */
    MMA_MMS_ADDRESS_GROUP_TYPE_TOTAL_NUM /* Max number of address group. */
} mma_mms_address_group_type_enum;
/*Above Enums are added for XML Removal Activity Amitesh*/


/**********************************************************************
 * Structure definition
 **********************************************************************/

/* This structure is used to describe the information returned by insertion check. */
typedef struct
{
    kal_bool result;                    /* Insertion is allowed */
    kal_bool oversize;                  /* Too large to be inserted */
    kal_bool creation_mode_violate;     /* Violate current creation mode so that cannot be inserted */
    mma_result_enum detail_result;      /* to replace result and oversize */
    mma_insert_type_enum insert_type;   /* The object format should be inserted as */
    mma_drm_type_enum drm_type;         /* DRM information */
}mma_insert_check_struct;

/* This structure is used to describe uc start result. */
typedef struct
{
    mma_result_enum result; /* mma_result_enum */
    mma_app_mode_enum mode; /* mma_app_mode_enum */
}mma_uc_start_rsp_struct;

/* This structure is used to describe the inserted object information. */
typedef struct
{
    kal_uint32 current_msg_size;            /* Current message size */
    kal_uint32 max_msg_size;                /* Max. message size */
    mma_creation_mode_enum creation_mode;   /* Current creation mode setting value */
    mma_insert_type_enum insert_type;       /* The media type the object will be inserted as, ex. Image, audio, text or attachment. <b>When forwarding, use  MMA_INSERT_UNKNOWN </b>*/
    mma_mms_type_enum mms_type;             /* MMS type, mms_type is used to indicate the editing MMS is a SMIL MMS or Mixed MMS */
    kal_wchar *filepath;                    /* Filepath of the to-be-inserted object, encoded by UCS2 */
}mma_insert_info_struct;


/**********************************************************************
 * Function declarations
 **********************************************************************/
 
/*****************************************************************************
 * FUNCTION
 *  mma_check_drm_type name 
 * DESCRIPTION
 *  Check object for DRM type 
 * PARAMETERS
 *  filepath : [IN]  Path of file will be checked.
 * RETURNS
 *  DRM type (mma_drm_type_enum)
*****************************************************************************/ 
extern mma_drm_type_enum mma_check_drm_type(const kal_wchar *filepath);

/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_text_uintvar_overhead_size 
 * DESCRIPTION
 *  When UC calculate text size internally, it misses DataLen uintvar overhead added for multipart. The overhead value is the value incremented on mma_get_uintvar_length_bytes(0)
 * PARAMETERS
 *  utf8_byte_size : [IN]  UTF8 text object size.
 * RETURNS
 *  overhead size in bytes
*****************************************************************************/
extern kal_uint32 mma_uc_calc_text_uintvar_overhead_size(kal_uint32 utf8_byte_size);

/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_header_attribute_size
 * DESCRIPTION
 *  This function is for Unified Composer to get the payload size of an MMS header field. The header field can only be address or subject. The data parameter should be a UCS2 string.
 * PARAMETERS
 *  attr : [IN]  The header field type to be calculated.
  * data : [IN]  Field content encoded by UCS2. 
 * RETURNS
 *  Payload size in bytes.
*****************************************************************************/
extern kal_uint32 mma_uc_calc_header_attribute_size(mma_header_attr_enum attr, const kal_wchar *data);

/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_object_multipart_size 
 * DESCRIPTION
 *  This function is for Unified Composer to get the multipart payload size of a specified object in file system. The multipart payload size includes object size and multipart header. 
 * PARAMETERS
 *  filepath : [IN]  Object filepath encoded by UCS2.
 * RETURNS
 *  Payload size in bytes.
*****************************************************************************/
extern kal_uint32 mma_uc_calc_object_multipart_size(const kal_wchar *filepath);

/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_slide_smil_size 
 * DESCRIPTION
 *  This function is to calculate SMIL description size for slide (<par dur=1000ms></par>) 
 * PARAMETERS
 *  sec : [IN] second
 * RETURNS
 *  smil description size.
*****************************************************************************/
extern kal_uint32 mma_uc_calc_slide_smil_size(kal_uint32 sec);

/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_object_smil_size 
 * DESCRIPTION
 *  This function is for Unified Composer to get the SMIL description payload size of an inserted object. If the object is inserted as an image, an audio or a video, the filepath parameter should be specified.
 *  Ex. <text src="??.??" region="Text" /> or <audio src="??.??" /> or <img src="??.??" region="Image" /> or <video src="??.??" region="Image" /> or <ref src="??.??" /> 
 * PARAMETERS
 *  type     : [IN] The media type the object is inserted as, ex. Image, audio, text.
 *  filepath : [OUT] Object filepath encoded by UCS2. 
 * RETURNS
 *  Payload size in bytes..
*****************************************************************************/
extern kal_uint32 mma_uc_calc_object_smil_size(mma_insert_type_enum type, const kal_wchar *filepath);


//#ifdef __MMI_UC_AUTO_RESIZE_IMG_BASED_ON_LEFT_MMS_SIZE__

/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_object_overhead_size 
 * DESCRIPTION
 *  Calculate object overhead size including
 *  - multipart header:
 *  + HeadersLen, Headers: mma_uc_calc_object_multipart_header_size()
 *  + DataLen
 *  - smil description size:
 * PARAMETERS
 *  type : [IN]  insert type.
 *  filename : [IN]  file name will be inserted.
 *  filesize : [IN]  size of file will be inserted.
 *  mms_type : [IN]  MMS message type.
 * RETURNS
 *  overhead size in bytes
*****************************************************************************/
extern kal_uint32 mma_uc_calc_object_overhead_size(mma_insert_type_enum type, const kal_wchar *filename, kal_uint32 filesize, mma_mms_type_enum mms_type);
//#endif

/*****************************************************************************
 * FUNCTION
 *  mma_uc_set_file_mgr_filter 
 * DESCRIPTION
 *  This function is to set the filter for uc. 
 * PARAMETERS
 *  filter               : [OUT]  file filter used by unified composer
 *  media_type_to_insert : [IN] UC filter mode. 
 * RETURNS
 *  void
*****************************************************************************/
extern void mma_uc_set_file_mgr_filter(void* filter, mma_uc_filter_mode_enum media_type_to_insert);

/*****************************************************************************
 * FUNCTION
 *  mma_uc_get_file_mgr_filtere 
 * DESCRIPTION
 *  This function is obslete. 
 * PARAMETERS
 *  filter : [OUT]  filte description.
 *  option : [OUT] param2 description. 
 * RETURNS
 *  void
*****************************************************************************/
extern void mma_uc_get_file_mgr_filter(void *filter /*fmgr_filter_mask_struct defined in fmt_def.h*/, mma_uc_filter_mode_enum option);

/*****************************************************************************
 * FUNCTION
 *  mma_uc_insert_object_check 
 * DESCRIPTION
 *  This function is for Unified Composer to check if the to-be-inserted object is eligible for insertion. 
 *  If insert_info->insert_type is MMA_INSERT_UNKNOWN, this API should fill the right insert_type. For 3gp and mp4 files, MMA should check the file is audio or video. If file is audio, insert_info->insert_type is MMA_INSERT_AUDIO. If file is video, insert_info->insert_type is MMA_INSERT_VIDEO.
 *  MMA should check if object violate creation mode.
 *  If connection type is WAP, MMA should check if message size is larger than MMA_MAX_WAP_CONN_MSG_SIZE, not insert_info->max_msg_size given by application. If yes, MMA should return MMA_RESULT_FAIL_WAP_CONN_MAX_MSG_SIZE_REACHED as the detail_result.
 * PARAMETERS
 *  insert_info : [IN]  Information of the inserting object.
 *  info        : [OUT] Insertion eligibility info. Output parameter. Detail_result field can replace result+oversize+creation_mode_violate fields.
 * RETURNS
 *  void
*****************************************************************************/
extern void mma_uc_insert_object_check(mma_insert_info_struct *insert_info, mma_insert_check_struct *info);

/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_header_size 
 * DESCRIPTION
 *  This function is for Unified Composer to calculate MMS header size based on the provided header content. The function is only used for Forward/Send mode. For Forward/Send mode, Unified Composer won't change MMS body content but only header content; therefore, Unifed Composer only use this function to calculate MMS header size and add fixed body size brought in MSG_ID_WAP_GET_MMS_CONTENT_RSP to get total MMS size.
 * PARAMETERS
 *  mms      : [IN]  The structure of mms is mmi_uc_msg_struct. The structure is defined in Unified Composer application and wouldn't be explained in this document.
 *  mms_type : [IN] Indicate the MMS type. 
 * RETURNS
 *  MMS header size in bytes.
*****************************************************************************/
extern kal_uint32 mma_uc_calc_header_size(const void *mms, mma_mms_type_enum mms_type);

/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_msg_size 
 * DESCRIPTION
 *  This function is for Unified Composer to calculate MMS size based on the provided content and MMS type. 
 * PARAMETERS
 *  mms      : [IN]  The structure of mms is mmi_uc_msg_struct. The structure is defined in Unified Composer application and wouldn't be explained in this document.
 *  mms_type : [IN] Indicate the MMS type. 
 * RETURNS
 *  MMS size in bytes.
*****************************************************************************/
extern kal_uint32 mma_uc_calc_msg_size(const void *mms, mma_mms_type_enum mms_type);

/*****************************************************************************
 * FUNCTION
 *  mma_is_storage_exported_to_pc 
 * DESCRIPTION
 *  This function is to check whether mms folder is exported to pc. 
 * PARAMETERS
 *  void
 * RETURN VALUES
 *   TRUE  : mms folder is exported to pc.
 *   FALSE : mms folder is not exported to pc.
*****************************************************************************/
extern kal_bool mma_is_storage_exported_to_pc(void);

/*****************************************************************************
 * FUNCTION
 *  mma_get_request_id 
 * DESCRIPTION
 *  This function is used to get request ID to identify the submitted request. The assigned request ID is  unique and its value would be greater than 0. 
 * PARAMETERS
 *  void
 * RETURNS
 *  Request ID.
*****************************************************************************/
extern kal_uint32 mma_get_request_id(void);

/*****************************************************************************
 * FUNCTION
 *  mma_get_msg_id 
 * DESCRIPTION
 *  This function is to get message id according to message folder and index. 
 * PARAMETERS
 *  msg_box_type : [IN]  mma_folder_enum, Message folder.
 *  msg_index    : [IN] Message index. 
 * RETURNS
 *  Message id.
*****************************************************************************/
extern kal_uint32 mma_get_msg_id(kal_uint16 msg_box_type, kal_uint16 msg_index);

/*****************************************************************************
 * FUNCTION
 *  mma_get_box 
 * DESCRIPTION
 *  This function is for application to look up MMS box ID by message ID. 
 * PARAMETERS
 *  msg_id : [IN]  Message ID.
 * RETURNS
 *  MMS box ID.
*****************************************************************************/
extern mma_folder_enum mma_get_box(kal_uint32 msg_id);

/*****************************************************************************
 * FUNCTION
 *  mma_get_home_directory 
 * DESCRIPTION
 *  This function is to get mms home directory. 
 * PARAMETERS
 *  buffer      : [OUT]  Used to store returned mms directory path. UCS2 encoding.
 *  buffer_size : [IN]   size of byfere. 
 *  storage     : [IN]   Storage enum
 * RETURN VALUES
 *  KAL_TRUE: buffer is not null and buffer size is enough to store the result.
 *  KAL_FALSE: buffer is not enough to save mms home directory.
*****************************************************************************/
extern kal_bool mma_get_home_directory(kal_wchar *buffer, kal_uint32 buffer_size, kal_uint8 storage);

/*****************************************************************************
 * FUNCTION
 *  mma_get_msg_file_name 
 * DESCRIPTION
 *  This function is to get file name of one MMS message.
 *  Q05A: "0300001\ 0010001.dat"
 *  Q03C: "1.m"
 * PARAMETERS
 *  msg_id      : [IN]  Message id.
 *  buffer      : [OUT] Used to store returned file name. UCS2 encoding.
 *  buffer_size : [IN]  size of byfere. 
 * RETURN VALUES
 *  KAL_TRUE: buffer is not null and buffer size is enough to store the result.
 *  KAL_FALSE: buffer is not enough to save file name of mms message.
*****************************************************************************/
extern kal_bool mma_get_msg_file_name(kal_uint32 msg_id, kal_wchar *buffer, kal_uint32 buffer_size);

/*****************************************************************************
 * FUNCTION
 *  mma_is_ready_for_usb 
 * DESCRIPTION
 *  This function is used to check if MMA is ready for USB mode. 
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  0: MMA is not reacy for USB mode.
 *  1: MMA is ready for USB mode.
*****************************************************************************/
extern int mma_is_ready_for_usb(void);

/*****************************************************************************
 * FUNCTION
 *  mma_is_ready_for_format 
 * DESCRIPTION
 *  This function is used to check if MMA is ready for format operation. 
 * PARAMETERS
 *  drive     : [IN]   drive enum
 * RETURNS
 *  return value description.
 * RETURN VALUES
 *  KAL_TRUE  : MMA is reacy for format operation.
 *  KAL_FALSE : MMA is not reacy for format operation.
*****************************************************************************/
extern kal_bool mma_is_ready_for_format(kal_uint8 drive);

/*****************************************************************************
 * FUNCTION
 *  mma_get_max_slide_no 
 * DESCRIPTION
 *  This function is used to get maximum number of mms slides. 
 * PARAMETERS
 *  void
 * RETURNS
 *  maximum number of mms slides.
*****************************************************************************/
extern kal_uint32 mma_get_max_slide_no(void);

/*****************************************************************************
 * FUNCTION
 *  mma_get_max_recipient_no 
 * DESCRIPTION
 *  This function is used to get maximum number of mms address. 
 * PARAMETERS
 *  void
 * RETURNS
 *  maximum number of mms address.
*****************************************************************************/
extern kal_uint32 mma_get_max_recipient_no(void);

/*****************************************************************************
 * FUNCTION
 *  mma_get_max_attachment_no 
 * DESCRIPTION
 *  This function is used to get maximum number of mms attachment. 
 * PARAMETERS
 *  void 
 * RETURNS
 *  rmaximum number of mms attachment.
*****************************************************************************/
extern kal_uint32 mma_get_max_attachment_no(void);

/*****************************************************************************
 * FUNCTION
 *  mma_get_max_process_time 
 * DESCRIPTION
 *  This function is used to get maximum time of processing one mms. Unified Composer use this value to start the timer for progressing screen. Recommanded value: 30 seconds per 100KB. 
 * PARAMETERS
 *  void 
 * RETURNS
 *  maximum time of processing one mms (30 seconds per 100KB).
*****************************************************************************/
extern kal_uint32 mma_get_max_process_time(void); /* 30 seconds per 100KB */

/*****************************************************************************
 * FUNCTION
 *  mma_get_restricted_image_type 
 * DESCRIPTION
 *  This function is used to get MMS image mime type list in restricted mode. 
 * PARAMETERS
 *  void
 * RETURNS
 *  mime type string.
*****************************************************************************/
extern const char *mma_get_restricted_image_type(void);

/*****************************************************************************
 * FUNCTION
 *  mma_get_restricted_text_type 
 * DESCRIPTION
 *  This function is used to get MMS text mime type list in restricted mode. 
 * PARAMETERS
 *  void
 * RETURNS
 *  mime type string.
*****************************************************************************/
extern const char *mma_get_restricted_text_type(void);

/*****************************************************************************
 * FUNCTION
 *  mma_get_restricted_audio_type 
 * DESCRIPTION
 *  This function is used to get MMS audio mime type list in restricted mode. 
 * PARAMETERS
 *  void
 * RETURNS
 *  mime type string.
*****************************************************************************/
extern const char *mma_get_restricted_audio_type(void);

/*****************************************************************************
 * FUNCTION
 *  mma_get_restricted_video_type 
 * DESCRIPTION
*  This function is used to get MMS video mime type list in restricted mode. 
 * PARAMETERS
 *  void
 * RETURNS
 *  mime type string.
*****************************************************************************/
extern const char *mma_get_restricted_video_type(void);

/*****************************************************************************
 * FUNCTION
 *  mma_get_restricted_attachment_type 
 * DESCRIPTION
*  This function is used to get MMS attachment mime type list in restricted mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  mime type string.
*****************************************************************************/
extern const char *mma_get_restricted_attachment_type(void);

/*****************************************************************************
 * FUNCTION
 *  mma_get_restricted_image_type 
 * DESCRIPTION
 *  This function is used to get MMS image mime type list. 
 * PARAMETERS
 *  void
 * RETURNS
 *  mime type string.
*****************************************************************************/
extern const char *mma_get_image_type(void);

/*****************************************************************************
 * FUNCTION
 *  mma_get_restricted_text_type 
 * DESCRIPTION
 *  This function is used to get MMS text mime type list. 
 * PARAMETERS
 *  void
 * RETURNS
 *  mime type string.
*****************************************************************************/
extern const char *mma_get_text_type(void);

/*****************************************************************************
 * FUNCTION
 *  mma_get_restricted_audio_type 
 * DESCRIPTION
 *  This function is used to get MMS audio mime type list. 
 * PARAMETERS
 *  void
 * RETURNS
 *  mime type string.
*****************************************************************************/
extern const char *mma_get_audio_type(void);

/*****************************************************************************
 * FUNCTION
 *  mma_get_restricted_video_type 
 * DESCRIPTION
*  This function is used to get MMS video mime type list. 
 * PARAMETERS
 *  void
 * RETURNS
 *  mime type string.
*****************************************************************************/
extern const char *mma_get_video_type(void);

/*****************************************************************************
 * FUNCTION
 *  mma_get_restricted_video_type 
 * DESCRIPTION
*  This function is used to get MMS attachement mime type list. 
 * PARAMETERS
 *  void
 * RETURNS
 *  mime type string.
*****************************************************************************/
extern const char *mma_get_attachment_type(void);

/*****************************************************************************
 * FUNCTION
 *  mma_get_default_smil_bg_color 
 * DESCRIPTION
 *  function description 
 * PARAMETERS
 *  void
 * RETURNS
 *  return value description.
 * RETURN VALUES                     [this TAG is an alternative of RETURNS]
 *  ReturnValue1 : description of return value 1.
 *  ReturnValue2 : description of return value 2.
 *
* EXAMPLE				    [this TAG is optional]
 * <code>
 * if a=b then a=a+1;
 * </code>
*****************************************************************************/
extern kal_uint32 mma_get_default_smil_bg_color(void);

/*****************************************************************************
 * FUNCTION
 *  mma_get_default_smil_fg_color 
 * DESCRIPTION
 *  This function is used to get default smil background color. 
 * PARAMETERS
 *  void
 * RETURNS
 *  default smil background color.
*****************************************************************************/
extern kal_uint32 mma_get_default_smil_fg_color(void);

extern kal_bool mmi_uc_is_uc_screen_in_history(void);

#define MMA_IS_UNIFIED_COMPOSER_ACTIVE mmi_uc_is_uc_screen_in_history

#if defined(__MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__)
    #define MMA_MAX_WAP_CONN_MSG_SIZE (100 * 1024)  /* Max MMS size can be downloaded in WSP connection. The value should not exceed 300K (based on STK_CFG_WTP_SAR_MAX_PDU_SIZE */
#elif defined(__MMI_MMS_WAP_CONNECTION_MAX_SIZE_SUPPORT__)
    #define MMA_MAX_WAP_CONN_MSG_SIZE (300 * 1024) /* Max MMS size can be downloaded in WSP connection. The value should not exceed 300K (based on STK_CFG_WTP_SAR_MAX_PDU_SIZE */
#else 
	#define MMA_MAX_WAP_CONN_MSG_SIZE (100 * 1024)
#endif

#endif /*_MMA_API_H*/
