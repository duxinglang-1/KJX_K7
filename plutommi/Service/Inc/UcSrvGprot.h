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
 * UcSrvGprot.h
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

#ifndef _UNIFIED_COMPOSER_SRV_GPROT_H
#define _UNIFIED_COMPOSER_SRV_GPROT_H

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))

#include "gui_config.h" /* For GUI_INPUT_BOX_MAX_LENGTH */

#include "custom_mmi_default_value.h"   /* For MMI_PHB_NAME_LENGTH */
#include "custom_wap_config.h"
#include "custom_uc_config.h"   /* For MMI_UC_CUSTOM_MAX_ADDR_LEN */
#ifdef __MMI_EMAIL__
#include "customer_email_num.h"
#endif
#include "customer_ps_inc.h"
#include "mmsadp.h"
#include "mma_struct.h"
//#include "xml_def.h"
//#include "UMGprot.h"
//suggested add
    #include "MMI_features.h"
    #include "UmSrvDefs.h"
    #include "customer_email_num.h"
    #include "custom_phb_config.h"
    #include "FileMgrSrvGProt.h"
    //#include "kal_general_types.h"
    #include "MMIDataType.h"
    #include "mma_api.h"
    #include "fs_type.h"
#define __XML_REMOVAL__
/* Max length of subject UC supports, to compatable with UM subject. */
#define SRV_UC_MAX_SUBJECT_LEN SRV_UM_MAX_SUBJECT_LEN

/* Max Email length UC supports. */
#define SRV_UC_MAX_EMAIL_LEN (MMI_EMAIL_MAX_ADDR_LEN)
/*Trace for Slim project while Assert is disable*/ 
#define TRC_SRV_UC_ASSERT "[UC]Assert happens at line = %d in the file = %s"
/* Max Phone number length UC supports. */
#define SRV_UC_MAX_PHONE_NUMBER_LEN MMI_PHB_NUMBER_LENGTH
#if SRV_UC_MAX_EMAIL_LEN < SRV_UC_MAX_PHONE_NUMBER_LEN
#error email len shall not smaller than phone number
#endif 
/* Minium address field length UC supports. */
#define SRV_UC_MIN_ADDR_LEN (3)
/* Invalid value indicator UC supports. */
#define SRV_UC_INVALID_VALUE (0xFFFFFFFF)
/* Max char/text UC supports on single slide. */
#if defined (__COSMOS_MMI_PACKAGE__) && defined (__MMI_EMAIL__)
#if GUI_INPUT_BOX_MAX_LENGTH < (MMI_EMAIL_MAX_CONT_LEN_BY_K * 1024)
#define SRV_UC_MAX_CHAR_NUM_IN_ONE_SLIDE (MMI_EMAIL_MAX_CONT_LEN_BY_K * 1024)
#else
#define SRV_UC_MAX_CHAR_NUM_IN_ONE_SLIDE (GUI_INPUT_BOX_MAX_LENGTH)
#endif
#else
#ifdef __MMI_UC_ENCODING_BASED_SLIDE_TEXT_LENGTH_SUPPORT__
#define SRV_UC_MAX_CHAR_NUM_IN_ONE_SLIDE 3072
#else
#define SRV_UC_MAX_CHAR_NUM_IN_ONE_SLIDE (GUI_INPUT_BOX_MAX_LENGTH)
#endif
#endif
/* Max char/text buffer size UC supports on single slide. */
#define SRV_UC_TEXT_BUFFER_SIZE (SRV_UC_MAX_CHAR_NUM_IN_ONE_SLIDE * ENCODING_LENGTH + ENCODING_LENGTH)
/* Max UTF8 char/text buffer size UC supports on single slide. */
#define SRV_UC_UTF8_TEXT_BUFFER_SIZE (SRV_UC_TEXT_BUFFER_SIZE * ENCODING_LENGTH + ENCODING_LENGTH)

/* Max number of attachment UC supports. */
#define SRV_UC_MAX_ATTACHMENT_NUM (mma_get_max_attachment_no())
/* Max number of recipient UC supports. */
#define SRV_UC_MAX_ADDRESS_NUM (mma_get_max_recipient_no())
/* Max number of slides UC supports. */
#define SRV_UC_MAX_MMS_SLIDE_NUM (mma_get_max_slide_no())
/* Max string length for the XML data strings */
#define SRV_UC_XML_STR_LEN                  (12)

#ifndef SRV_UC_MAX_IMAGE_WIDTH
/* Max image width UC supports. */
#define SRV_UC_MAX_IMAGE_WIDTH (1600)
#endif /* SRV_UC_MAX_IMAGE_WIDTH */ 

#ifndef SRV_UC_MAX_IMAGE_HEIGHT
/* Max image hight UC supports. */
#define SRV_UC_MAX_IMAGE_HEIGHT (1600)
#endif /* SRV_UC_MAX_IMAGE_HEIGHT */ 
/* Default Bg color (0x00FFFFFF). */
#define SRV_UC_DEFAULT_BG_COLOR (mma_get_default_smil_bg_color())
/* Default Fg color (0x00000000). */
#define SRV_UC_DEFAULT_FG_COLOR (mma_get_default_smil_fg_color())

#ifdef APP_STORAGE_IN_SYS_DRV
/* UC folder drive to use. To sync with mms and all app as they need to use system drive space. */
#define SRV_UC_FOLDER_DRV SRV_FMGR_SYSTEM_DRV
#else /* APP_STORAGE_IN_SYS_DRV */ 
/* UC folder drive to use. */
#define SRV_UC_FOLDER_DRV SRV_FMGR_PUBLIC_DRV
#endif /* APP_STORAGE_IN_SYS_DRV */ 

/* Max peer buffer size UC supports. */
#define SRV_UC_MAX_XML_SIZE_IN_PEER_BUFFER (2000)

/* Invalid index in UC (0xFFFF). */
#define SRV_UC_INVALID_INDEX (0xFFFF)

/* Image Resizing results */
/* Success */
#define SRV_UC_RESIZING_SUCCEED                                         (1)
/* Success no need resize */
#define SRV_UC_RESIZING_SUCCEED_WITH_UNCHANGED                          (0)
/* GDI resize fail */
#define SRV_UC_RESIZING_FAILED_IN_GDI_FAILED                            (-1)
/* GDI disk full error */
#define SRV_UC_RESIZING_FAILED_IN_GDI_ENCODER_ERR_DISK_FULL             (-5)
/* GDI write protection error */
#define SRV_UC_RESIZING_FAILED_IN_GDI_ENCODER_ERR_WRITE_PROTECTION      (-6)
/* GDI no disk error */
#define SRV_UC_RESIZING_FAILED_IN_GDI_ENCODER_ERR_NO_DISK               (-7)
/* GDI no quota error */
#define SRV_UC_RESIZING_FAILED_IN_NO_QUOTA                              (-10)
/* GDI unknown dimention error */
#define SRV_UC_RESIZING_FAILED_IN_UNKNOWN_DIMENSION                     (-11)
/* GDI insufficient drawing buffer error */
#define SRV_UC_RESIZING_FAILED_IN_INSUFFICIENT_DRAWING_BUF              (-12)
/* GDI final size after resize greater then expected error */
#define SRV_UC_RESIZING_ERR_SIZE_LARGER_THAN_EXPECTATION                (-13)


/* This enum is used to specify operation results. */
typedef enum
{
    SRV_UC_OK,                                  /* 0 */ 
    SRV_UC_SIZE_EXCEEDS,                        /* 1 */
    SRV_UC_CREATION_MODE_SIZE_EXCEEDS,          /* 2 */
    SRV_UC_SIZE_NOT_ENOUGH_FOR_REC_VIDEO,       /* 3 */
    SRV_UC_PROHIBIT_BY_CREATION_MODE,           /* 4 */
    SRV_UC_PROHIBIT_BY_DRM,                     /* 5 */
    SRV_UC_NO_SPACE,                            /* 6 */
    SRV_UC_NO_SPACE_TONE,                       /* 7 */
    SRV_UC_INSUFFICIENT_MEMORY,                 /* 8 */
    SRV_UC_STORAGE_FULL,                        /* 9 */
    SRV_UC_ERROR,                               /* 10 */
    SRV_UC_XML_ERROR,                           /* 11 */
    SRV_UC_NOT_SUPPORT,                         /* 12 */

    SRV_UC_FILE_CORRUPT,                        /* 13 */
    SRV_UC_FILE_EMPTY,                          /* 14 */
    SRV_UC_FILE_NOT_FOUND,                      /* 15 */
    SRV_UC_FOLDER_NOT_FOUND,                    /* 16 */
    SRV_UC_WAP_CONN_MAX_MSG_SIZE_REACHED,       /* 17 */
    SRV_UC_FAIL_IN_VIDEO_CALL,                  /* 18 */
    SRV_UC_FAIL_IMAGE_TOO_LARGE,                /* 19 */
    SRV_UC_RESULT_TOTAL_NUM                     /* 20 */
} srv_uc_result;

/* This enum is used to define message type modes supported in UC. This is decided before start composer and will inform UC that it can be switchable inside composer operation or its fixed to one type. */
typedef enum
{
    SRV_UC_MSG_TYPE_DEFAULT,    /* Default type. */
    SRV_UC_MSG_TYPE_SMS_PREFER, /* Default mode SMS. Try to change to SMS if content say can be SMS. */
    SRV_UC_MSG_TYPE_MMS_PREFER, /* Default mode MMS. */
    SRV_UC_MSG_TYPE_SMS_ONLY,   /* Only SMS mode support. Msg will not change to MMS. */
    SRV_UC_MSG_TYPE_MMS_ONLY,   /* Only MMS mode support. Can not be changed to SMS. */
    SRV_UC_MSG_TYPE_TOTAL_NUM   /* Max number of type modes UC supports. */
} srv_uc_msg_type_enum;

/* This enum is used to define composer internal actions supported in UC. */
typedef enum
{
    SRV_UC_ACTION_IDLE,                     /* Uc action idle. No action. Default type. value 0 */
    SRV_UC_ACTION_SEND,                     /* Uc action send. value 1 */
    SRV_UC_ACTION_SEND_AND_SAVE,            /* Uc action send and save. value 2 */
    SRV_UC_ACTION_SAVE,                     /* Uc action save. value 3 */
    SRV_UC_ACTION_DELETE,                   /* Uc action delete. value 4 */
    SRV_UC_ACTION_PREVIEW,                  /* Uc action preview. value 5 */
    SRV_UC_ACTION_SAVE_IN_BACKGROUND,       /* Uc action save in background. value 6 */
    SRV_UC_ACTION_SAVE_AS_TEMPLATE,         /* Uc action save as template. value 7 */
    SRV_UC_ACTION_SEND_IN_BACKGROUND,       /* Uc action send in background. value 8 */
    SRV_UC_ACTION_DELETE_IN_BACKGROUND,     /* Uc action delete in background. value 9 */

    SRV_UC_ACTION_SAVE_IN_BACKGROUND_WHEN_BATTERY_LOW,  /* Uc action save in background when battery low. value 10 */
    SRV_UC_ACTION_TOTAL_NUM                 /* Max action. value 11 */
} srv_uc_action_type_enum;

/* This enum is used to define edit mode types supported in UC. This is decided when launch editor for edit a MMS/SMS/Postcard/Email. Values currently used to tell composer difference between normal and postcard MMS. */
typedef enum
{
    SRV_UC_MMS_EDIT_MODE_NORMAL_MMS,    /* Normal MMS mode. */
    SRV_UC_MMS_EDIT_MODE_POSTCARD_MMS,  /* Postcard MMS mode. */
    SRV_UC_MMS_EDIT_MODE_EMAIL,                     /* Email mode. */
    SRV_UC_MMS_EDIT_SMS_TEMPLATE,                     /* Need to check if sms support this */
    SRV_UC_MMS_EDIT_MODE_LEMEI_MMS,
    SRV_UC_MMS_EDIT_MODE_TOTAL_NUM      /* Max number of MMS modes UC supports. */
} srv_uc_MMS_edit_mode_enum;

/* This enum is used to define message info type modes supported in UC. Filled when want to launch UC editor to inform about the requester message application. */
typedef enum
{
    SRV_UC_INFO_TYPE_SMS,                               /* Info type SMS. */
    SRV_UC_INFO_TYPE_MMS,                               /* Info type MMS. */
    SRV_UC_INFO_TYPE_NORMAL_MMS = SRV_UC_INFO_TYPE_MMS, /* Info type MMS. for backward conpatiblity. */
    SRV_UC_INFO_TYPE_POSTCARD_MMS,                      /* Info type Postcard. */
    SRV_UC_INFO_TYPE_EMAIL,                      /* Info type EMAIL. */
    SRV_UC_INFO_TYPE_SMS_TEMPLATE,                               /* Info type SMS Template. */
    SRV_UC_INFO_TYPE_MMS_TEMPLATE,                               /* Info type MMS Template. */
    SRV_UC_INFO_TYPE_VCARD,                      /* Info type VCARD. */
    SRV_UC_INFO_TYPE_VCALENDER,                      /* Info type VCALENDER. */
    SRV_UC_INFO_TYPE_LEMEI_MMS,    
    SRV_UC_INFO_TYPE_TOTAL_NUM                          /* Max number of msg info UC supports. */
} srv_uc_info_type_enum;

/* This enum is used to define insert signature operation results. Use to keep internal status of autosignature. */
typedef enum
{
    SRV_UC_INSERT_RESULT_SUCCESS,           /* Successfully added. */
    SRV_UC_INSERT_RESULT_FAIL,              /* Fail to add. */
    SRV_UC_INSERT_RESULT_FILE_NOT_EXIST,    /* File not exist on path. */
    SRV_UC_INSERT_RESULT_TOTAL_NUM          /* Max number of insert signature results. */
} srv_uc_insert_signature_result_enum;

/* This enum is used to define UC current state of operation. It will be need to set when launch UC. As each state have different type of flow. */
typedef enum
{
    SRV_UC_STATE_WRITE_NEW_MSG,     /* Writing new msg state. */
    SRV_UC_STATE_EDIT_EXISTED_MSG,  /* Edit existing msg state. */
    SRV_UC_STATE_FORWARD,           /* Forward existing msg state. Only for inbox and sent box msgs. */
    SRV_UC_STATE_SEND,              /* Send existing msg state. Only for outbox and draft box msgs. */
    SRV_UC_STATE_REPLY,             /* Reply existing msg state. */
    SRV_UC_STATE_REPLY_ALL,         /* Reply all existing msg state. */
    SRV_UC_STATE_TOTAL_NUM          /* Max number of msg states in UC. */
} srv_uc_state_enum;

/* This enum is used to specify the type of address. Email or number. */
typedef enum
{
    SRV_UC_ADDRESS_TYPE_PHONE_NUMBER,   /* Phone number. */
    SRV_UC_ADDRESS_TYPE_EMAIL,          /* Email address. */
    SRV_UC_ADDRESS_TYPE_IP,             /* IP address. */
    SRV_UC_ADDRESS_TYPE_TOTAL_NUM       /* Max number of address type. */
} srv_uc_address_type_enum;

/* This enum is used to specify the group types of addresses. */
typedef enum
{
    SRV_UC_ADDRESS_GROUP_TYPE_TO,       /* To group. */
    SRV_UC_ADDRESS_GROUP_TYPE_CC,       /* Cc group. */
    SRV_UC_ADDRESS_GROUP_TYPE_BCC,      /* Bcc group. */
    SRV_UC_ADDRESS_GROUP_TYPE_FROM,     /* From group. */
    SRV_UC_ADDRESS_GROUP_TYPE_TOTAL_NUM /* Max number of address group. */
} srv_uc_address_group_type_enum;

/* This enum is used to specify the object type of the media. Media will be inserted as these types in msg. */
typedef enum
{
    SRV_UC_OBJECT_TYPE_IMAGE,       /* Image. */
    SRV_UC_OBJECT_TYPE_AUDIO,       /* Audio. */
    SRV_UC_OBJECT_TYPE_VIDEO,       /* Video. */
    SRV_UC_OBJECT_TYPE_TEXT,        /* Text. */
    SRV_UC_OBJECT_TYPE_ATTACHMENT,  /* Attachment. */
    SRV_UC_OBJECT_TYPE_REF,         /* Object embeded in <ref> tag. */
    SRV_UC_OBJECT_TYPE_UNKNOWN,     /* Unknown. */
    SRV_UC_DONE_TYPE_TOTAL_NUM      /* Max number of object types UC supports. */
} srv_uc_object_type;

/* This enum is used to specify slide layout. It will tell that on slide image region will be upper or lower. */
//typedef enum
//{
  //  SRV_UC_LAYOUT_DEFAULT,              /* No relative layout specification. */
   // SRV_UC_LAYOUT_THUMBNAIL_AT_TOP,     /* Image on top; text on bottom. */
    //SRV_UC_LAYOUT_THUMBNAIL_AT_BOTTOM,  /* Image on bottom; text on top. */
    //SRV_UC_LAYOUT_TOTAL_NUM             /* Max number of layouts UC supports. */
//} srv_uc_layout_enum;

/* This enum is used to specify slide region fit types. */
typedef enum
{
    SRV_UC_REGION_FIT_NONE,     /* No relative fit type. */
    SRV_UC_REGION_FIT_MEET,     /* Meet fit type. */
    SRV_UC_REGION_FIT_SCROLL,   /* Scroll fit type. */
    SRV_UC_REGION_FIT_HIDDEN,   /* Hidden fit type. */
    SRV_UC_REGION_FIT_FILL,     /* Fill fit type. */
    SRV_UC_REGION_FIT_SLICE,    /* Slice fit type. */
    SRV_UC_REGION_TOTAL_NUM     /* Max number of region fit types UC supports. */
} srv_uc_region_fit_enum;

/* This enum is used to specify msg expiry time. */
typedef enum
{
    SRV_UC_EXPIRY_NOT_SET,  /* Epxiry time is not defined. */
    SRV_UC_EXPIRY_1_HOUR,   /* Epxiry time is 1 hour. */
    SRV_UC_EXPIRY_6_HOURS,  /* Epxiry time is 6 hours. */
    SRV_UC_EXPIRY_12_HOURS, /* Epxiry time is 12 hours. */
    SRV_UC_EXPIRY_1_DAY,    /* Epxiry time is 1 day. */
    SRV_UC_EXPIRY_1_WEEK,   /* Epxiry time is 1 week. */
    SRV_UC_EXPIRY_MAX       /* Epxiry time is not defined. Should be max. */
} srv_uc_expiry_time_enum;

/* This enum is used to specify msg delivery time. */
typedef enum
{
    SRV_UC_DELIVERY_NOT_SET,    /* Delivery time is not defined. */
    SRV_UC_DELIVERY_IMMEDIATE,  /* Delivery time is immediate. */
    SRV_UC_DELIVERY_1_HOUR,     /* Delivery time is 1 hour. */
    SRV_UC_DELIVERY_12_HOURS,   /* Delivery time is 12 hours. */
    SRV_UC_DELIVERY_24_HOURS    /* Delivery time is 1 day. */
} srv_uc_delivery_time_enum;

/* This enum is used to specify sim in use. Its designed for two sim only. */
typedef enum
{
     /* Unclassified message */
  SRV_UC_SIM_ID_UNCLASSIFIED  = 0x00,
  SRV_UC_SIM_ID_GSM_SIM1 = 0x01,      /* SIM1 card message */
  SRV_UC_SIM_ID_GSM_SIM2 = 0x02,
  SRV_UC_SIM_ID_GSM_SIM3 = 0x04,
  SRV_UC_SIM_ID_GSM_SIM4 = 0x08  /* SIM2 card message */
   
} srv_uc_sim_id;

/* This enum is used to specify forward status of message. Its designed to track forward and edit inter change of states. */
typedef enum
{
    SRV_UC_NORMAL_EDIT_MODE,  /* Edit Mode */
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    SRV_UC_SEND_WITHOUT_EDIT_MODE,  /* Send mode having no edit. Need to keep original content. */
    SRV_UC_SEND_WITH_EDIT_MODE,   /* Send mode having edit. Can change content according to edit mode. */
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
    SRV_UC_FORWARD_WITHOUT_EDIT_MODE,   /* Forward mode having no edit. Need to keep original content. */
    SRV_UC_FORWARD_WITH_EDIT_MODE   /* Forward mode having edit. Can change content according to edit mode. */
} srv_uc_mode_change_status_enum;

/* This enum is used to specify differnt type of media truncation when exceeding from the limit. */
typedef enum
{
    SRV_UC_TRUNCATED_TYPE_NONE = 0x00,    
    SRV_UC_TRUNCATED_TYPE_ATTACHMENT = 0X01,  /* Removal of additional attachment media from the msg. */
    SRV_UC_TRUNCATED_TYPE_SLIDE = 0X02,  /* Truncation of slides, if exceed from max limit. */
    SRV_UC_TRUNCATED_TYPE_TEXT = 0X04,  /* Truncation of extra text from the slide, if exceed per slide text limit. */
    SRV_UC_TRUNCATED_TYPE_TOTAL_NUM = 0XFF  /* Max limit */
} srv_uc_msg_truncation_type_enum;

/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
typedef enum
{
    SRV_UC_PHB_LIST_TYPE_SMS,
    SRV_UC_PHB_LIST_TYPE_NORMAL_MMS,
    SRV_UC_PHB_LIST_TYPE_POSTCARD_MMS,
    SRV_UC_PHB_LIST_TYPE_TOTAL_NUM
} srv_uc_phb_list_type_enum;
#endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 
/* DOM-NOT_FOR_SDK-END */

/* This structure contains the linked list for address information. */
typedef struct srv_uc_addr_struct_t
{
    struct srv_uc_addr_struct_t *next;      /* Next address */
    struct srv_uc_addr_struct_t *previous;  /* Previous address */
    kal_uint8 *addr;                        /* ascii for phone number while ucs2 for email address. NULL terminator is needed. */
    srv_uc_address_type_enum type;          /* srv_uc_address_type_enum */
    srv_uc_address_group_type_enum group;   /* srv_uc_address_group_type_enum */
} srv_uc_addr_struct;

#ifdef __MMI_MMS_POSTCARD__

#define SRV_POSTCARD_MAX_RECIPIENTS 5   /* 5 recipients. At max 5 recipient can be set with one postcard. */
#define SRV_POSTCARD_MAX_GREETING 200   /* 200 characters. Limit to greeting text set to 200 char. */

/*
 * *GlobalPostcard*(GreetingText)*(Name)*(AddtionalInformation)*(Street)*(PostalCode) (City)*(State)*(Country)
 */
#define SRV_POSTCARD_SENT_MAX_CONTENT (8 /* star */ + 1 /* space */ + 14 /* prefix */ + MMI_PHB_NAME_LENGTH + (MMI_PHB_ADDRESS_LENGTH * 6) + SRV_POSTCARD_MAX_GREETING)
#define SRV_POSTCARD_SAVE_MAX_CONTENT ((8 /* star */ + 1 /* space */ + 14 /* prefix */ + MMI_PHB_NAME_LENGTH + (MMI_PHB_ADDRESS_LENGTH * 6)) * SRV_POSTCARD_MAX_RECIPIENTS + SRV_POSTCARD_MAX_GREETING)

#define SRV_POSTCARD_FORBIDDEN_CHAR L"*"

/* DOM-NOT_FOR_SDK-BEGIN */
typedef enum
{
    SRV_POSTCARD_ADDRESS_INIT,
    SRV_POSTCARD_ADDRESS_ADD,
    SRV_POSTCARD_ADDRESS_EDIT
} srv_postcard_address_operation_enum;
/* DOM-NOT_FOR_SDK-END */

/* This structure contains the personal physical address information of the recipient. As the postacrd need to send on physical address. sync with the definition in PhoneBookTypes.h. */
typedef struct
{
    /* sync with the definition in PhoneBookTypes.h */
    U8 postcard_name[(MMI_PHB_NAME_LENGTH + 1) *ENCODING_LENGTH];   /* Name of recipient. */
    U8 postcard_additional[(MMI_PHB_ADDRESS_LENGTH + 1) *ENCODING_LENGTH];  /* additional information of recipient. */
    U8 postcard_street[(MMI_PHB_ADDRESS_LENGTH + 1) *ENCODING_LENGTH];  /* Street name of recipient. */
    U8 postcard_city[(MMI_PHB_ADDRESS_LENGTH + 1) *ENCODING_LENGTH];    /* City name of recipient. */
    U8 postcard_postalcode[(MMI_PHB_ADDRESS_LENGTH + 1) *ENCODING_LENGTH];  /* Zipcode of recipient. */
    U8 postcard_state[(MMI_PHB_ADDRESS_LENGTH + 1) *ENCODING_LENGTH];   /* Name of state of recipient. */
    U8 postcard_country[(MMI_PHB_ADDRESS_LENGTH + 1) *ENCODING_LENGTH]; /* Country name of recipient. */
    U16 phonebook_index;    /* Index of recipient in the phone's phonebook. If alraedy present. */
} srv_postcard_address_struct;

/* This structure contains the linked list of recipients of postcard. */
typedef struct postcard_recipient_struct_t
{
    struct postcard_recipient_struct_t *previous;   /* Next object */
    struct postcard_recipient_struct_t *next;       /* Previous object */
    srv_postcard_address_struct address;            /* Postcard recipient complete infomation set */
    MMI_BOOL update;                                /* Update status in phonebook. */
} srv_postcard_recipient_struct;

/* This structure contains the main and complete information must to keep for postacrd msg only. */
typedef struct
{
    U8 recipient_index;                             /* Current counter. */
    U8 recipient_total;                             /* Total recipient count. */
    U8 recipient_operation;                         /* operation types in address editor are 0: init, 1: add, 2: edit */

    mmi_id select_contact_cui_gid;                  /* group id for selection cui of PHB. */
    mmi_id save_contact_cui_gid;                    /* group id for save cui of PHB. */

    srv_postcard_recipient_struct *recipient_head;  /* linked-list recipients */
    srv_postcard_address_struct *recipient_editor;  /* address inline editor buffer */
    srv_postcard_address_struct *phonebook_forward; /* address forwarded from phonebook */
} srv_postcard_context_struct;
#endif /* __MMI_MMS_POSTCARD__ */ 

/* This structure contains the data to be passed to UC when other (MMS) application want to launch the UC composer. */
typedef struct
{
    U32 msg_id;          /* msg id */
    U8 app_id;          /* Application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    U8 mode;            /* mma_app_mode_enum */       
    U8 edit_mode;       /* srv_uc_MMS_edit_mode_enum */
    U8 sim_id;          /* srv_uc_sim_id */
    U8 curr_storage;    /* message stored on? */
} srv_uc_start_struct;

typedef void *(*srv_uc_app_mem_alloc_fn) (kal_uint32, void *);
typedef void (*srv_uc_app_mem_free_fn) (void *, void *);
typedef void (*srv_uc_app_callback_fn) (void *);
typedef void (*srv_void_fun_ptr) (void);

/*****************************************************************************
 * FUNCTION
 *  srv_uc_is_mms_in_use
 * DESCRIPTION
 *  This function to check if the msg_id is in used (Other application need to check for this before use a msg.
 *  Because same message can not be used by two applications simultaneously).
 * PARAMETERS
 *  msg_id : [IN] Msg id.
 * RETURNS
 *   KAL_FALSE  : Not in use.
 *   KAL_TRUE  : In use.
 *****************************************************************************/
extern kal_bool srv_uc_is_mms_in_use(kal_uint32 msg_id);

#endif /* (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) */ 
#endif /* _UNIFIED_COMPOSER_SRV_GPROT_H */ 
