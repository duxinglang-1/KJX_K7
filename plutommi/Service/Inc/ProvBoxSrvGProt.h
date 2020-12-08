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
 *  ProvBoxSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 * This file implements the external interface used by other application.
 * Any applications who use service provided by ProvBox can only include ProvBoxSrvGprot.h.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef SRV_PROVBOX_SRV_GPROT_H
#define SRV_PROVBOX_SRV_GPROT_H

#include "MMI_include.h"
#include "MMI_features.h"

#ifdef __MMI_PROV_MESSAGE_SUPPORT__

/*----------------------------------------------------------------------------*/
/* include                                                                       */
/*----------------------------------------------------------------------------*/

#include "kal_general_types.h"
#include "app_ltlcom.h"

#include "Custom_ProvBox.h"

#ifdef __MMI_PROV_IN_UM__
#include "UmSrvDefs.h"
#include "UmSrvStruct.h"
#endif

/*----------------------------------------------------------------------------*/
/* Constant configuration                                                     */
/*----------------------------------------------------------------------------*/
/* Only Phone number and IPv4 supported, prefer to use the max phone number define */
#define SRV_PROVBOX_ADDR_MAX_CHAR_LEN           (40)
/* Max application can be configured in one provisioning messages, a little larger than
   the applications number supported by CCA is preferred, just to not to change the file
   format frequently  */
#define SRV_PROVBOX_MAX_APP_INFO_NUM            (20)

#define SRV_PROVBOX_PATH_MAX_CHAR_LEN           (50)

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/
/* Invalid message id, the message id is begin from 1 */
#define SRV_PROVBOX_INVALID_MSG_ID                      (0)
/* Invalid next index, the first index is 0, so next index can not be 0 */
#define SRV_PROVBOX_INVALID_NEXT_INDEX                  (0)
/* Invalid time, it instal_time is 0, it means not installed yet. */
#define SRV_PROVBOX_INVALID_TIME                        (0)

/* Message info bit mask flag, to indicate the install time */
#define SRV_PROVBOX_MSG_INFO_MASK_INSTALL_TIME          (0x0001)
/* Message info bit mask flag, to indicate the read status */
#define SRV_PROVBOX_MSG_INFO_MASK_READ_STATUS           (0x0002)
/* Message info bit mask flag, to indicate the PIN status */
#define SRV_PROVBOX_MSG_INFO_MASK_PIN_STATUS            (0x0004)
/* Message info bit mask flag, to indicate the install status */
#define SRV_PROVBOX_MSG_INFO_MASK_INSTALL_STATUS        (0x0008)
/* Message info bit mask flag, to indicate the application's install time */
#define SRV_PROVBOX_MSG_INFO_MASK_APP_INSTALL_STATUS    (0x0010)

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/
#define SRV_PROVBOX_EVT_HEADER                      \
            MMI_EVT_PARAM_HEADER                    \
            srv_provbox_event_type_enum evt_type;

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/
/* SIM id */
typedef enum
{
    SRV_PROVBOX_SIM_ID_SIM1,                    /* SIM1 */
    SRV_PROVBOX_SIM_ID_SIM2,                    /* SIM2 */
    SRV_PROVBOX_SIM_ID_SIM3,                    /* SIM3 */
    SRV_PROVBOX_SIM_ID_SIM4,                    /* SIM4 */
    SRV_PROVBOX_SIM_ID_DUAL_SIM,                /* DUAL SIM */
    SRV_PROVBOX_SIM_ID_MAX_ITEM                 /* Max item */
} srv_provbox_sim_id_enum;

/* Provisioning box type */
typedef enum
{
    SRV_PROVBOX_BOX_TYPE_UNKNOWN  = 0x00,        /* Unknown */
    SRV_PROVBOX_BOX_TYPE_INBOX    = 0x01,        /* Inbox */
    SRV_PROVBOX_BOX_TYPE_ARCHIVE  = 0x02,        /* Archive box */
    SRV_PROVBOX_BOX_TYPE_EXTRA    = 0x04,        /* Extra box, only used internally */

    SRV_PROVBOX_BOX_TYPE_ALL      = SRV_PROVBOX_BOX_TYPE_INBOX | SRV_PROVBOX_BOX_TYPE_ARCHIVE,                               /* All box types */
    SRV_PROVBOX_BOX_TYPE_WHOLE_ALL= SRV_PROVBOX_BOX_TYPE_INBOX | SRV_PROVBOX_BOX_TYPE_ARCHIVE | SRV_PROVBOX_BOX_TYPE_EXTRA,  /* All box types */

    SRV_PROVBOX_BOX_TYPE_MAX_ITEM                /* Max item */
} srv_provbox_box_type_enum;

typedef enum
{
    SRV_PROVBOX_EVT_TYPE_BOX_FULL_IND,                 /* Provisioning box full event type */
    SRV_PROVBOX_EVT_TYPE_NEW_MSG_IND,                  /* Receive new message event type */
    SRV_PROVBOX_EVT_TYPE_SET_MSG_INFO_IND,             /* Set message information event type */
    SRV_PROVBOX_EVT_TYPE_SET_SORT_INFO_IND,            /* Set sort information of message event type */
    SRV_PROVBOX_EVT_TYPE_SET_MSG_DETAIL_IND,           /* Set the properties of message event type */
    SRV_PROVBOX_EVT_TYPE_SET_MSG_STATE_READY_IND,      /* Set the ready of provbox service event type */
    SRV_PROVBOX_EVT_TYPE_END_OF_ITEM
} srv_provbox_event_type_enum;

/* Box Full ind, include the follow notify type */
typedef enum
{
    SRV_PROVBOX_NOTIFY_TYPE_NO_FULL,           /* ProvBoxSrv is not full */
    SRV_PROVBOX_NOTIFY_TYPE_INBOX_FULL,        /* The inbox of provisioning message is full */
    SRV_PROVBOX_NOTIFY_TYPE_MEM_FULL,          /* The memory of target is full */
    SRV_PROVBOX_NOTIFY_TYPE_DISK_FULL,         /* The disk space of target is full */
    SRV_PROVBOX_NOTIFY_TYPE_UPDATE_MSG_STATE,  /* Notify type is update message state */
    SRV_PROVBOX_NOTIFY_TYPE_MAX_ITEM
} srv_provbox_notify_type_enum;

/* MEssage read status */
typedef enum
{
    SRV_PROVBOX_MSG_READ_STATUS_UNREAD,         /* Unread */
    SRV_PROVBOX_MSG_READ_STATUS_READ,           /* Read */
    SRV_PROVBOX_MSG_READ_STATUS_NONE,           /* None, for error handling only */
    SRV_PROVBOX_MSG_READ_STATUS_MAX_ITEM        /* Max item */
} srv_provbox_msg_read_status_enum;

/* Configuration source id, same value as SRV_CCA_SOURCE_XXX is preferred */
typedef enum
{
    /* For message provider */
    SRV_PROVBOX_SOURCE_ID_TEST,                 /* Test */
    SRV_PROVBOX_SOURCE_ID_WAP,                  /* Wap configuration source, it's PRS indeed now */
    SRV_PROVBOX_SOURCE_ID_DM,                   /* DM configuration source */
    SRV_PROVBOX_SOURCE_ID_SPA,                  /* SPA configuration source */

    /* For message consumer */
    SRV_PROVBOX_SOURCE_ID_PROVBOXUI,            /* ProvBoxUI module */    
    SRV_PROVBOX_SOURCE_ID_CCA,                  /* CCA application */
    SRV_PROVBOX_SOURCE_ID_MAX_ITEM              /* Max item */
} srv_provbox_source_id_enum;

/* Configuration id, same value as CCA_APP_XXX is preferred */
typedef enum
{
    SRV_PROVBOX_CONFIG_ID_INVALID,              /* Invalid */
    SRV_PROVBOX_CONFIG_ID_TEST,                 /* Test */
    SRV_PROVBOX_CONFIG_ID_DATAACCOUNT,          /* Data account */
    SRV_PROVBOX_CONFIG_ID_WLAN,                 /* WLAN */
    SRV_PROVBOX_CONFIG_ID_BROWSER,              /* Browser */
    SRV_PROVBOX_CONFIG_ID_MMS,                  /* MMS */
    SRV_PROVBOX_CONFIG_ID_SIP,                  /* VoIP SIP */
    SRV_PROVBOX_CONFIG_ID_IMPS,                 /* IMPS */
    SRV_PROVBOX_CONFIG_ID_EMAIL,                /* Email */
    SRV_PROVBOX_CONFIG_ID_SYNCMLDS,             /* SyncML-DS */
    SRV_PROVBOX_CONFIG_ID_SYNCMLDM,             /* SyncML-DM */
    SRV_PROVBOX_CONFIG_ID_PUSH,                 /* Push Whitelist*/
    SRV_PROVBOX_CONFIG_ID_WLAN_DMP,             /* WLAN-DMP */
    SRV_PROVBOX_CONFIG_ID_SIP_DMP,              /* VoIP SIP-DMP */
    SRV_PROVBOX_CONFIG_ID_RTSP,                 /* RTSP */
    SRV_PROVBOX_CONFIG_ID_SUPL,                 /* AGPS */    
    SRV_PROVBOX_CONFIG_ID_MAX_ITEM              /* Max item */
} srv_provbox_config_id_enum;

/*  Provisioning message type */
typedef enum
{
    SRV_PROVBOX_MSG_TYPE_OTA,                   /* OTA Provisioning */
    SRV_PROVBOX_MSG_TYPE_DM,                    /* DM Bootstrap */
    SRV_PROVBOX_MSG_TYPE_SIM_MMSICP,            /* SIM MMSICP */
    SRV_PROVBOX_MSG_TYPE_MAX_ITEM               /* Max item */
} srv_provbox_msg_type_enum;

/* Message flags, only support eight flags at most to save memory, it has two types, internal flags and extern flags,
   internal flags have four bits, they are defined and used internally, not exported,
   external flags are defined here and also only have four bit slot available */
typedef enum
{
    SRV_PROVBOX_MSG_FLAG_READING = 0x01,        /* Message in reading */
    SRV_PROVBOX_MSG_FLAG_MAX_ITEM               /*Max item */
} srv_provbox_msg_flag_enum;

/* Message flag operation type */
typedef enum
{
    SRV_PROVBOX_MSG_FLAG_OP_SET,                /* Set operation: set one or more bits */
    SRV_PROVBOX_MSG_FLAG_OP_CLEAR,              /* Clear operation, clear one or more bits */    
    SRV_PROVBOX_MSG_FLAG_OP_MAX_ITEM            /* Max item */
} srv_provbox_msg_flag_op_enum;

/* PIN verification status */
typedef enum
{
    SRV_PROVBOX_MSG_PIN_STATUS_NOT_VERIFIED,    /* PIN code is not verified */
    SRV_PROVBOX_MSG_PIN_STATUS_VERIFIED,        /* PIN code is verified */
    SRV_PROVBOX_MSG_PIN_STATUS_MAX_ITEM         /* Max item */
} srv_provbox_msg_pin_status_enum;

#ifdef __BUILD_DOM__
/* Primitives provided by ProvBox */
typedef enum
{
    MSG_ID_SRV_PROVBOX_SAVE_MSG_AVAILABLE_IND,          /* To indicate if can can save new message to Provisionining inbox or not */
    MSG_ID_SRV_PROVBOX_SAVE_MSG_REQ,                    /* To save a new message to Provisioning Inbox */
    MSG_ID_SRV_PROVBOX_SAVE_MSG_CNF,                    /* To feedback the result of saving new message */
    MSG_ID_SRV_PROVBOX_GET_MSG_DATA_REQ,                /* To get the message data */
    MSG_ID_SRV_PROVBOX_GET_MSG_DATA_CNF,                /* To feedback the message data */

    MSG_ID_SRV_PROVBOX_NEW_MSG_IND,                     /* To indicate a new message is received */
    MSG_ID_SRV_PROVBOX_LIST_INFO_CHANGED_IND,           /* To indicate the list info is changed */
    MSG_ID_SRV_PROVBOX_UPDATE_MSG_NUM_IND,              /* To indicate the message number information is changed */

    //MSG_ID_SRV_PROVBOX_GET_MSG_NUM_REQ,                 /* To get the mesage numuber info */
    MSG_ID_SRV_PROVBOX_GET_MSG_NUM_CNF,                 /* To feedback the mesage number info */
    //MSG_ID_SRV_PROVBOX_GET_SORT_INFO_REQ,               /* To get the sort info */
    MSG_ID_SRV_PROVBOX_GET_SORT_INFO_CNF,               /* To feedback the sort info */
    MSG_ID_SRV_PROVBOX_GET_LIST_INFO_BY_ID_REQ,         /* To get this list info by message id */
    MSG_ID_SRV_PROVBOX_GET_LIST_INFO_BY_ID_CNF,         /* To feedback the list info */
    MSG_ID_SRV_PROVBOX_GET_LIST_INFO_BY_INDEX_REQ,      /* To get the list info by index */
    MSG_ID_SRV_PROVBOX_GET_LIST_INFO_BY_INDEX_CNF,      /* To feedback the list info */

    MSG_ID_SRV_PROVBOX_MULTI_OP_REQ,                    /* To indicate a multipe operation is started, move to archive or delete selected */
    MSG_ID_SRV_PROVBOX_MULTI_OP_CNF,                    /* To feedback the operation result */

    MSG_ID_SRV_PROVBOX_DELETE_MSG_REQ,                  /* To delete one message */
    MSG_ID_SRV_PROVBOX_DELETE_MSG_CNF,                  /* To feedback the delete result */
    MSG_ID_SRV_PROVBOX_DELETE_ALL_MSG_REQ,              /* To delete all messages */
    MSG_ID_SRV_PROVBOX_DELETE_ALL_MSG_CNF,              /* To feedback the delete all result */

    MSG_ID_SRV_PROVBOX_SET_MSG_FLAG_REQ,                /* To set the message flags */    
    MSG_ID_SRV_PROVBOX_SET_MSG_FLAG_CNF,                /* To feedback the message flags */
    MSG_ID_SRV_PROVBOX_GET_MSG_INFO_REQ,                /* To get message detail info */
    MSG_ID_SRV_PROVBOX_GET_MSG_INFO_CNF,                /* To feedback the mesage info */
    MSG_ID_SRV_PROVBOX_UPDATE_MSG_INFO_REQ,             /* To update the message info */
    MSG_ID_SRV_PROVBOX_UPDATE_MSG_INFO_CNF,             /* To feedback the update result */

}msg_id_srv_provbox_enum;
#endif /* __BUILD_DOM__ */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* Message or application configuration status */
typedef enum
{
    SRV_PROVBOX_CONFIG_STATUS_NOT_INSTALLED,    /* Not installed */
    SRV_PROVBOX_CONFIG_STATUS_NOAPP,            /* No application is found in this message */
    SRV_PROVBOX_CONFIG_STATUS_CONFIGED,         /* Configured */    
    SRV_PROVBOX_CONFIG_STATUS_FAILED,           /* Configuration is failed */
    SRV_PROVBOX_CONFIG_STATUS_SKIPPED,          /* Skipped */
    SRV_PROVBOX_CONFIG_STATUS_UPDATED,          /* Updated */
    SRV_PROVBOX_CONFIG_STATUS_INVALID,          /* Invalid setting */
    SRV_PROVBOX_CONFIG_STATUS_UNSUPPORTED,      /* Unsupported setting */
    SRV_PROVBOX_CONFIG_STATUS_CORRUPTED,        /* Corrupted */
    SRV_PROVBOX_CONFIG_STATUS_MISSING_DATA,     /* Missing data */
    SRV_PROVBOX_CONFIG_STATUS_MAX_ITEM          /* Max item */
} srv_provbox_config_status_enum;

/* Save data type */
typedef enum
{
    SRV_PROVBOX_SAVE_DATA_TYPE_NONE,            /* None */
    SRV_PROVBOX_SAVE_DATA_TYPE_FILE,            /* Data is saved in file */
    SRV_PROVBOX_SAVE_DATA_TYPE_RAW_DATA,        /* Data is saved in memory */
    SRV_PROVBOX_SAVE_DATA_TYPE_MAX_ITEM         /* Max item */
} srv_provbox_save_data_type_enum;

/* Result code */
typedef enum
{
    SRV_PROVBOX_RESULT_OK,                      /* Ok */
    SRV_PROVBOX_RESULT_FAIL,                    /* Fail */
    SRV_PROVBOX_RESULT_INVALID_PARAM,           /* Invalid Param */
    SRV_PROVBOX_RESULT_SMALL_BUF,               /* Buffer is too small */

    SRV_PROVBOX_RESULT_MEM_FULL,                /* Memory is full */
    SRV_PROVBOX_RESULT_BOX_FULL,                /* Box is full */    
    SRV_PROVBOX_RESULT_DISK_FULL,               /* Disk is full */
    SRV_PROVBOX_RESULT_READING,                 /* Message is in reading */

    SRV_PROVBOX_RESULT_PARSE_ERR,               /* Parse error */

    SRV_PROVBOX_RESULT_EMPTY,                   /* Empty */
    SRV_PROVBOX_RESULT_NOT_FOUND,               /* Not found */
    SRV_PROVBOX_RESULT_NOT_SAVED,               /* Not saved */
    SRV_PROVBOX_RESULT_CONTINUE,                /* Continue */
    SRV_PROVBOX_RESULT_ERR_VERSION,             /* Error version */

    SRV_PROVBOX_RESULT_FILE_EXIST,              /* File already exists */
    SRV_PROVBOX_RESULT_FILE_NOT_FOUND,          /* File not found */ 
    SRV_PROVBOX_RESULT_FILE_OP_FAIL,            /* File operation fail such as delete, read or write fail */
    SRV_PROVBOX_RESULT_FILE_ERR_SIZE,           /* File size is error */
    SRV_PROVBOX_RESULT_PARTIAL_DELETED,         /* Partial deleted */

    SRV_PROVBOX_RESULT_MAX_ITEM                 /* Max item */
} srv_provbox_result_enum;

/* Address type */
typedef enum
{
    SRV_PROVBOX_ADDR_TYPE_NONE,                 /* No address */
    SRV_PROVBOX_ADDR_TYPE_PHONENUM,             /* Phone number */
    SRV_PROVBOX_ADDR_TYPE_IPV4,                 /* IPv4 address */    
    SRV_PROVBOX_ADDR_TYPE_TEXT,                 /* Test address, not support, for error handling only */
    SRV_PROVBOX_ADDR_TYPE_MAX_ITEM              /* Max item */
} srv_provbox_addr_type_enum;

/*----------------------------------------------------------------------------*/
/* Base structure                                                             */
/*----------------------------------------------------------------------------*/
/* event function:  app use this function to handle the event from service */
typedef void(*srv_provbox_callback_func)(srv_provbox_result_enum, void*);

/* To store the messag address information */
typedef struct
{
    srv_provbox_addr_type_enum addr_type;       /* Address type */
    U16 addr_len;                               /* Address length in char */    
    U16 addr[SRV_PROVBOX_ADDR_MAX_CHAR_LEN + 1];/* Address details in UCS2 encode */
} srv_provbox_addr_struct;

/* Mesasge common information */
typedef struct
{
    U32 msg_id;                                     /* Message id, if not installed, set it to MMI_PROVBOX_INVALID_MSG_ID */
    U32 timestamp;                                  /* Timestamp, if uninstalled, set it to zero */
    U32 install_time;                               /* Install time, if uninstalled, set it to zero */
    srv_provbox_source_id_enum src_id;              /* Configuration source id */
    U8 sim_id;                                      /* SIM id */
    srv_provbox_box_type_enum box_type;             /* Box type, if not installed, set it to MMI_PROVBOX_BOX_TYPE_UNKNOWN */
    srv_provbox_msg_type_enum msg_type;             /* Message type */
    srv_provbox_msg_read_status_enum read_status;   /* if not installed, set it to MMI_PROVBOX_MSG_READ_STATUS_READ */
    srv_provbox_addr_struct sender_addr;            /* if SIM message, set type to MMI_PROVBOX_ADDR_TYPE_NONE */
} srv_provbox_msg_cmn_info_struct;

/* Application configuration status */
typedef struct
{
    srv_provbox_config_id_enum config_id;       /* Configuration id */
    srv_provbox_config_status_enum status;      /* Configuration status */
} srv_provbox_app_config_status_struct;


/* Provisioning message configuration status */
typedef struct
{
    U16 app_num;                                    /* Application number */
    srv_provbox_config_status_enum config_status;   /* the config status of whole message, if uninstalled, set it to MMI_PROVBOX_CONFIG_STATUS_NOT_INSTALLED */
    srv_provbox_app_config_status_struct app_config_status[SRV_PROVBOX_MAX_APP_INFO_NUM];  /* Applications' configuration status */
} srv_provbox_msg_config_status_struct;

typedef struct
{
    U32 msg_id;                                 /* Message id input */
    srv_provbox_msg_cmn_info_struct cmn_info;   /* Message common infomation output */
    S16 msg_size;                               /* Message size output */
    srv_provbox_result_enum result;
} srv_provbox_msg_properties_struct;

/*----------------------------------------------------------------------------*/
/* Primitive structure                                                        */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/
/******************************************************************************
 * To support split
 *****************************************************************************/
/*----------------------Primitive for message provider: PRS, DM, SPA----------*/
/* Structure for the primitive of MSG_ID_SRV_PROVBOX_SAVE_MSG_AVAILABLE_IND,
 it's used to indicate that configuration source can save new message to Provisioning inbox now,
 it's used by ProvBoxSrv to notify configuration source once it get free after it's full by some reason */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U32 trans_id;                               /* Transaction id */
} srv_provbox_save_msg_available_ind_struct;

/* To store message data information */
typedef struct
{
    S16 app_data_size;                              /* Application private data size in bytes */
    void *app_data;                                 /* Application private data */
    srv_provbox_save_data_type_enum prov_data_type; /* The type to indicate how to save the provisioning message raw data */
    S16 prov_data_size;                             /* The data size of provisioning message */
    void *prov_data;                                /* Provisioning message raw data */
    U16 *prov_file;                                 /* The name of the file in UCS2 encode to store the provisionining raw data if save data to file*/
} srv_provbox_msg_data_struct;

/* Structure for the primitive of MSG_ID_SRV_PROVBOX_SAVE_MSG_REQ, 
it's used by configuration source to save new message in Provisioning Inbox once it receive new message */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U32 trans_id;                               /* Transaction id */
    srv_provbox_msg_cmn_info_struct cmn_info;   /* Common information */
    srv_provbox_msg_config_status_struct msg_config_status;     /* Message configuration status */
    srv_provbox_msg_data_struct msg_data;       /* Message data information */
} srv_provbox_save_msg_req_struct;

/* Structure for the primitive of MSG_ID_SRV_PROVBOX_SAVE_MSG_CNF,
   ProvBoxSrv sends this primitive to configuration source to notify the result of the saving new message request */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U32 trans_id;                               /* Transaction id */
    U32 msg_id;                                 /* Message id */
    srv_provbox_source_id_enum src_id;          /* Configuration source id */ 
    U8 sim_id;                                  /* SIM id */
    srv_provbox_msg_type_enum msg_type;         /* Message type */
    void *app_data;                             /* Application data */
    void *prov_data;                            /* Provisioning raw data */
    WCHAR *prov_file;                           /* Provisioning file name in UCS encode */
    srv_provbox_result_enum result;             /* Result code */
} srv_provbox_save_msg_cnf_struct;

/* Structure for the primitive of MSG_ID_SRV_PROVBOX_GET_MSG_DATA_REQ,
it's used to get message data from Provisioning Inbox by message id */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U32 trans_id;                               /* Transaction id */
    U32 msg_id;                                 /* Message id */
    srv_provbox_source_id_enum src_id;          /* Configuration source id */
} srv_provbox_get_msg_data_req_struct;

/* Structure for the primitive of MSG_ID_SRV_PROVBOX_GET_MSG_DATA_CNF, 
it's used by ProvBoxSrv to send the result of getting message data request */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U32 trans_id;                               /* Transaction id */
    U32 msg_id;                                 /* Message id */
    srv_provbox_source_id_enum src_id;          /* Configuration source id */
    U8 sim_id;                                  /* SIM id */
    S16 app_data_size;                          /* Size of application data */
    void *app_data;                             /* free memory using srv_provbox_free_app_data() */
    WCHAR filename[SRV_PROVBOX_PATH_MAX_CHAR_LEN + 1];    /* File name of the file to store the provisioning data */
    srv_provbox_result_enum result;                     /* Result code */
} srv_provbox_get_msg_data_cnf_struct;

/*----------------------Primitive for Message displayer: ProvBoxUI ------------*/

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* Structure of the primitive of MSG_ID_SRV_PROVBOX_LIST_INFO_CHANGED_IND,
  it's used by ProvBoxSrv to notify ProvBoxUI that the list info of some message is changed */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    srv_provbox_msg_cmn_info_struct cmn_info;   /* Common information */     
} srv_provbox_list_info_changed_ind_struct;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*----------------------Primitive for message reader: CCA---------------------*/

/* Structure for the primitive of MSG_ID_SRV_PROVBOX_SET_MSG_FLAG_REQ, 
  it's use to set message flags */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U32 trans_id;                               /* Transaction id */
    U32 msg_id;                                 /* Message id */
    srv_provbox_msg_flag_op_enum op;            /* Message flag operation */    
    U32 msg_flag;                               /* Messag flags */
} srv_provbox_set_msg_flag_req_struct;

/* Structure for the primitive of MSG_ID_SRV_PROVBOX_SET_MSG_FLAG_CNF,
 it's used to feedback the result of setting message flag request */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U32 trans_id;                               /* Transaction id */
    U32 msg_id;                                 /* Message id */
    srv_provbox_msg_flag_op_enum op;            /* Message flag operation */    
    U32 msg_flag;                               /* Message flag */
    srv_provbox_result_enum result;             /* Result code */
} srv_provbox_set_msg_flag_cnf_struct;

/* Structure for the primitive of MSG_ID_SRV_PROVBOX_GET_MSG_INFO_REQ,
  it's used to get the message detail info */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U32 trans_id;                               /* Transaction id */
    U32 msg_id;                                 /* Message id */
} srv_provbox_get_msg_info_req_struct;

/* Structure for the primitive of MSG_ID_SRV_PROVBOX_GET_MSG_INFO_CNF,
  it's used to feedback the result of getting mesasge info request */
typedef struct
{
    LOCAL_PARA_HDR                               /* Local parameter head */
    U32 trans_id;                                /* Transaction id */
    srv_provbox_msg_cmn_info_struct cmn_info;    /* Common information*/
    srv_provbox_msg_pin_status_enum pin_status;  /* PIN verification status */
    srv_provbox_msg_config_status_struct msg_config_status;     /* Message configuration status */
    srv_provbox_result_enum result;              /* Result code */
} srv_provbox_get_msg_info_cnf_struct;

/* Structure for the primitive of MSG_ID_SRV_PROVBOX_UPDATE_MSG_INFO_REQ, 
   it's used to update the message detail information */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U32 trans_id;                               /* Transaction id */
    U32 msg_id;                                 /* Message id */
    U32 info_mask;                              /* Info bit mask group */
    U32 install_time;                           /* Install time */
    srv_provbox_source_id_enum src_id;          /* Configuration source id */ 
    srv_provbox_msg_read_status_enum read_status;   /* Read status */
    srv_provbox_msg_pin_status_enum pin_status; /* PIN verification status */
    srv_provbox_msg_config_status_struct msg_config_status;     /* Message configuration status */
} srv_provbox_update_msg_info_req_struct;

/* Structure of the primitive of MSG_ID_SRV_PROVBOX_UPDATE_MSG_INFO_CNF,
 it's used to feedback the result of updating message info request*/
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U32 trans_id;                               /* Transaction id */
    U32 msg_id;                                 /* Message id */
    srv_provbox_source_id_enum src_id;          /* Configuration source id */    
    srv_provbox_result_enum result;             /* Result code */
} srv_provbox_update_msg_info_cnf_struct;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*------------------- Event: provide message information: ProvBoxApp--------------------*/
typedef struct
{
    SRV_PROVBOX_EVT_HEADER                      /* Event parameter head */
} srv_provbox_event_struct;

typedef struct
{
    SRV_PROVBOX_EVT_HEADER                      /* Event parameter head */
    srv_provbox_notify_type_enum type;          /* Event notify type */
} srv_provbox_evt_notify_struct;


/*----------------------------------------------------------------------------*/
/* End                                                                        */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* API declarations                                                           */
/*----------------------------------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_init 
 * DESCRIPTION
 *  Initialize the ProvBox application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_provbox_init(void);

/*****************************************************************************
 * FUNCTION
 *    srv_provbox_free_app_data 
 * DESCRIPTION
 *    Setting Source(PRS/DM/SPA)use it to free the app_data allocated by ProvBox 
 *    in MSG_ID_MMI_CCA_SOURCE_GET_MSG_DATA_CNF.
 * PARAMETERS
 *    pp_data  [IN]   pointer of application data memory
 * RETURNS
 *    void
 *****************************************************************************/
extern void srv_provbox_free_app_data(void *app_data);

/*****************************************************************************
 * FUNCTION
 *  srv_provbox_get_total_msg_num 
 * DESCRIPTION
 *  Provide the number of provisioning message
 * PARAMETERS
 *  void
 * RETURNS
 *  U32
 *****************************************************************************/
extern U32 srv_provbox_get_total_msg_num(void);


/*****************************************************************************
 * FUNCTION
 *    srv_provbox_get_msg_status 
 * DESCRIPTION
 *    To get message status.
 * PARAMETERS
 *    msg_id      [IN]       message id
 * RETURNS
 *    srv_provbox_msg_read_status_enum
 *****************************************************************************/
extern srv_provbox_msg_read_status_enum srv_provbox_get_msg_status(U32 msg_id);

/*****************************************************************************
 * FUNCTION
 *    srv_provbox_set_msg_status 
 * DESCRIPTION
 *    To set message status
 * PARAMETERS
 *    msg_id      [IN]       message id
 *    status      [IN]       message status
 * RETURNS
 *    srv_provbox_result_enum
 *****************************************************************************/
#ifdef __MMI_PROV_IN_UM__
extern srv_provbox_result_enum srv_provbox_main_um_set_msg_state(
                                   U32 msg_id, 
                                   srv_provbox_msg_read_status_enum status,
                                   srv_provbox_callback_func callback_func,
                                   void *user_data);
#endif

/*****************************************************************************
 * FUNCTION
 *    srv_provbox_get_unread_msg_num 
 * DESCRIPTION
 *    To get the unread number of provisioning message.
 * PARAMETERS
 *    srv_provbox_box_type_enum [IN] the box type of message
 *    U8 [IN] sim id of provisioning message
 * RETURNS
 *    U32
 *****************************************************************************/
extern U32 srv_provbox_get_unread_msg_num(srv_provbox_box_type_enum box_type, U8 sim_id);


/*----------------------------------------------------------------------------*/
/* End                                                                        */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Adaptor code, should be removed after fully split done                                                                        */
/*----------------------------------------------------------------------------*/
#define MMI_PROVBOX_ADDR_MAX_CHAR_LEN                       SRV_PROVBOX_ADDR_MAX_CHAR_LEN
#define MMI_PROVBOX_MAX_APP_INFO_NUM                        SRV_PROVBOX_MAX_APP_INFO_NUM


#define MMI_PROVBOX_MAX_INBOX_MSG_NUM                       SRV_PROVBOX_MAX_INBOX_MSG_NUM

#define MMI_PROVBOX_MAX_GET_LIST_INFO_NUM                   SRV_PROVBOX_MAX_GET_LIST_INFO_NUM
#define MMI_PROVBOX_MAX_MULTI_OP_MSG_NUM                    SRV_PROVBOX_MAX_MULTI_OP_MSG_NUM
#ifdef __MMI_PROV_IN_UM__
#define MMI_PROVBOX_MAX_GET_SORT_INFO_NUM                   SRV_PROVBOX_MAX_GET_SORT_INFO_NUM
#endif /* __MMI_PROV_IN_UM__ */


/* Primitive for internal usage */
#define MSG_ID_SRV_PROVBOX_CONTINUE_PROCESS_JOB_IND         MSG_ID_MMI_PROVBOX_CONTINUE_PROCESS_JOB_IND

/* Primitive for message provider */
#define MSG_ID_SRV_PROVBOX_SAVE_MSG_AVAILABLE_IND           MSG_ID_MMI_PROVBOX_SAVE_MSG_AVAILABLE_IND
#define MSG_ID_SRV_PROVBOX_SAVE_MSG_REQ                     MSG_ID_MMI_PROVBOX_SAVE_MSG_REQ
#define MSG_ID_SRV_PROVBOX_SAVE_MSG_CNF                     MSG_ID_MMI_PROVBOX_SAVE_MSG_CNF
#define MSG_ID_SRV_PROVBOX_GET_MSG_DATA_REQ                 MSG_ID_MMI_PROVBOX_GET_MSG_DATA_REQ
#define MSG_ID_SRV_PROVBOX_GET_MSG_DATA_CNF                 MSG_ID_MMI_PROVBOX_GET_MSG_DATA_CNF

/* Primitive for message shower */
#define MSG_ID_SRV_PROVBOX_NEW_MSG_IND                      MSG_ID_MMI_PROVBOX_NEW_MSG_IND
#define MSG_ID_SRV_PROVBOX_LIST_INFO_CHANGED_IND            MSG_ID_MMI_PROVBOX_LIST_INFO_CHANGED_IND

//#define MSG_ID_SRV_PROVBOX_GET_MSG_NUM_REQ                  MSG_ID_MMI_PROVBOX_GET_MSG_NUM_REQ
//#define MSG_ID_SRV_PROVBOX_GET_MSG_NUM_CNF                  MSG_ID_MMI_PROVBOX_GET_MSG_NUM_CNF
//#define MSG_ID_SRV_PROVBOX_GET_SORT_INFO_REQ                MSG_ID_MMI_PROVBOX_GET_SORT_INFO_REQ
//#define MSG_ID_SRV_PROVBOX_GET_SORT_INFO_CNF                MSG_ID_MMI_PROVBOX_GET_SORT_INFO_CNF
//#define MSG_ID_SRV_PROVBOX_GET_LIST_INFO_BY_ID_REQ          MSG_ID_MMI_PROVBOX_GET_LIST_INFO_BY_ID_REQ
//#define MSG_ID_SRV_PROVBOX_GET_LIST_INFO_BY_ID_CNF          MSG_ID_MMI_PROVBOX_GET_LIST_INFO_BY_ID_CNF
//#define MSG_ID_SRV_PROVBOX_GET_LIST_INFO_BY_INDEX_REQ       MSG_ID_MMI_PROVBOX_GET_LIST_INFO_BY_INDEX_REQ
//#define MSG_ID_SRV_PROVBOX_GET_LIST_INFO_BY_INDEX_CNF       MSG_ID_MMI_PROVBOX_GET_LIST_INFO_BY_INDEX_CNF

//#define MSG_ID_SRV_PROVBOX_MULTI_OP_REQ                     MSG_ID_MMI_PROVBOX_MULTI_OP_REQ
//#define MSG_ID_SRV_PROVBOX_MULTI_OP_CNF                     MSG_ID_MMI_PROVBOX_MULTI_OP_CNF

//#define MSG_ID_SRV_PROVBOX_DELETE_MSG_REQ                   MSG_ID_MMI_PROVBOX_DELETE_MSG_REQ
//#define MSG_ID_SRV_PROVBOX_DELETE_MSG_CNF                   MSG_ID_MMI_PROVBOX_DELETE_MSG_CNF
//#define MSG_ID_SRV_PROVBOX_DELETE_ALL_MSG_REQ               MSG_ID_MMI_PROVBOX_DELETE_ALL_MSG_REQ
//#define MSG_ID_SRV_PROVBOX_DELETE_ALL_MSG_CNF               MSG_ID_MMI_PROVBOX_DELETE_ALL_MSG_CNF

/* Primitive for message reader */
#define MSG_ID_SRV_PROVBOX_SET_MSG_FLAG_REQ                 MSG_ID_MMI_PROVBOX_SET_MSG_FLAG_REQ
#define MSG_ID_SRV_PROVBOX_SET_MSG_FLAG_CNF                 MSG_ID_MMI_PROVBOX_SET_MSG_FLAG_CNF
#define MSG_ID_SRV_PROVBOX_GET_MSG_INFO_REQ                 MSG_ID_MMI_PROVBOX_GET_MSG_INFO_REQ
#define MSG_ID_SRV_PROVBOX_GET_MSG_INFO_CNF                 MSG_ID_MMI_PROVBOX_GET_MSG_INFO_CNF
#define MSG_ID_SRV_PROVBOX_UPDATE_MSG_INFO_REQ              MSG_ID_MMI_PROVBOX_UPDATE_MSG_INFO_REQ
#define MSG_ID_SRV_PROVBOX_UPDATE_MSG_INFO_CNF              MSG_ID_MMI_PROVBOX_UPDATE_MSG_INFO_CNF



#define MMI_PROVBOX_INVALID_MSG_ID  SRV_PROVBOX_INVALID_MSG_ID
#define MMI_PROVBOX_INVALID_NEXT_INDEX  SRV_PROVBOX_INVALID_NEXT_INDEX
#define MMI_PROVBOX_INVALID_TIME  SRV_PROVBOX_INVALID_TIME

#define MMI_PROVBOX_MSG_INFO_MASK_INSTALL_TIME  SRV_PROVBOX_MSG_INFO_MASK_INSTALL_TIME
#define MMI_PROVBOX_MSG_INFO_MASK_READ_STATUS  SRV_PROVBOX_MSG_INFO_MASK_READ_STATUS
#define MMI_PROVBOX_MSG_INFO_MASK_PIN_STATUS  SRV_PROVBOX_MSG_INFO_MASK_PIN_STATUS
#define MMI_PROVBOX_MSG_INFO_MASK_INSTALL_STATUS  SRV_PROVBOX_MSG_INFO_MASK_INSTALL_STATUS
#define MMI_PROVBOX_MSG_INFO_MASK_APP_INSTALL_STATUS  SRV_PROVBOX_MSG_INFO_MASK_APP_INSTALL_STATUS

/* For message provider */
#define MMI_PROVBOX_SOURCE_ID_TEST SRV_PROVBOX_SOURCE_ID_TEST
#define MMI_PROVBOX_SOURCE_ID_WAP SRV_PROVBOX_SOURCE_ID_WAP
#define MMI_PROVBOX_SOURCE_ID_DM SRV_PROVBOX_SOURCE_ID_DM
#define MMI_PROVBOX_SOURCE_ID_SPA SRV_PROVBOX_SOURCE_ID_SPA
/* For message consumer */
#define MMI_PROVBOX_SOURCE_ID_PROVBOXUI SRV_PROVBOX_SOURCE_ID_PROVBOXUI
#define MMI_PROVBOX_SOURCE_ID_CCA SRV_PROVBOX_SOURCE_ID_CCA

typedef srv_provbox_source_id_enum mmi_provbox_source_id_enum;

#define MMI_PROVBOX_CONFIG_ID_INVALID SRV_PROVBOX_CONFIG_ID_INVALID
#define MMI_PROVBOX_CONFIG_ID_TEST SRV_PROVBOX_CONFIG_ID_TEST
#define MMI_PROVBOX_CONFIG_ID_DATAACCOUNT SRV_PROVBOX_CONFIG_ID_DATAACCOUNT
#define MMI_PROVBOX_CONFIG_ID_WLAN SRV_PROVBOX_CONFIG_ID_WLAN
#define MMI_PROVBOX_CONFIG_ID_BROWSER SRV_PROVBOX_CONFIG_ID_BROWSER
#define MMI_PROVBOX_CONFIG_ID_MMS SRV_PROVBOX_CONFIG_ID_MMS
#define MMI_PROVBOX_CONFIG_ID_SIP SRV_PROVBOX_CONFIG_ID_SIP
#define MMI_PROVBOX_CONFIG_ID_IMPS SRV_PROVBOX_CONFIG_ID_IMPS
#define MMI_PROVBOX_CONFIG_ID_EMAIL SRV_PROVBOX_CONFIG_ID_EMAIL
#define MMI_PROVBOX_CONFIG_ID_SYNCMLDS SRV_PROVBOX_CONFIG_ID_SYNCMLDS
#define MMI_PROVBOX_CONFIG_ID_SYNCMLDM SRV_PROVBOX_CONFIG_ID_SYNCMLDM
#define MMI_PROVBOX_CONFIG_ID_PUSH SRV_PROVBOX_CONFIG_ID_PUSH
#define MMI_PROVBOX_CONFIG_ID_WLAN_DMP SRV_PROVBOX_CONFIG_ID_WLAN_DMP
#define MMI_PROVBOX_CONFIG_ID_SIP_DMP SRV_PROVBOX_CONFIG_ID_SIP_DMP
#define MMI_PROVBOX_CONFIG_ID_RTSP SRV_PROVBOX_CONFIG_ID_RTSP
#define MMI_PROVBOX_CONFIG_ID_SUPL SRV_PROVBOX_CONFIG_ID_SUPL

typedef srv_provbox_config_id_enum mmi_provbox_config_id_enum;

#define MMI_PROVBOX_SIM_ID_SIM1 SRV_PROVBOX_SIM_ID_SIM1
#define MMI_PROVBOX_SIM_ID_SIM2 SRV_PROVBOX_SIM_ID_SIM2
#define MMI_PROVBOX_SIM_ID_DUAL_SIM SRV_PROVBOX_SIM_ID_DUAL_SIM

typedef srv_provbox_sim_id_enum mmi_provbox_sim_id_enum;


#define MMI_PROVBOX_BOX_TYPE_UNKNOWN SRV_PROVBOX_BOX_TYPE_UNKNOWN
#define MMI_PROVBOX_BOX_TYPE_INBOX SRV_PROVBOX_BOX_TYPE_INBOX
#define MMI_PROVBOX_BOX_TYPE_ARCHIVE SRV_PROVBOX_BOX_TYPE_ARCHIVE
#define MMI_PROVBOX_BOX_TYPE_EXTRA SRV_PROVBOX_BOX_TYPE_EXTRA  /* only used internally */

typedef srv_provbox_box_type_enum mmi_provbox_box_type_enum;



#define MMI_PROVBOX_MSG_TYPE_OTA SRV_PROVBOX_MSG_TYPE_OTA                /* OTA Provisioning */
#define MMI_PROVBOX_MSG_TYPE_DM SRV_PROVBOX_MSG_TYPE_DM                  /* DM Bootstrap */
#define MMI_PROVBOX_MSG_TYPE_SIM_MMSICP SRV_PROVBOX_MSG_TYPE_SIM_MMSICP  /* SIM MMSICP */

typedef srv_provbox_msg_type_enum mmi_provbox_msg_type_enum;


#define MMI_PROVBOX_MSG_SORT_TYPE_MSG_ID SRV_PROVBOX_MSG_SORT_TYPE_MSG_ID       /* It's the same order as by receiving order. */
#define MMI_PROVBOX_MSG_SORT_TYPE_TIMESTAMP SRV_PROVBOX_MSG_SORT_TYPE_TIMESTAMP    /* The local time, may be change by user. */
#define MMI_PROVBOX_MSG_SORT_TYPE_MSG_SIZE SRV_PROVBOX_MSG_SORT_TYPE_MSG_SIZE
#define MMI_PROVBOX_MSG_SORT_TYPE_MSG_TYPE SRV_PROVBOX_MSG_SORT_TYPE_MSG_TYPE
#define MMI_PROVBOX_MSG_SORT_TYPE_ADDRESS SRV_PROVBOX_MSG_SORT_TYPE_ADDRESS
#define MMI_PROVBOX_MSG_SORT_TYPE_READ_STATUS SRV_PROVBOX_MSG_SORT_TYPE_READ_STATUS

//typedef srv_provbox_msg_sort_type_enum mmi_provbox_msg_sort_type_enum;


#define MMI_PROVBOX_ORDER_TYPE_SEQUENCE SRV_PROVBOX_ORDER_TYPE_SEQUENCE
#define MMI_PROVBOX_ORDER_TYPE_RANDOM SRV_PROVBOX_ORDER_TYPE_RANDOM

//typedef srv_provbox_order_type_enum mmi_provbox_order_type_enum;


#define MMI_PROVBOX_ADDR_TYPE_NONE SRV_PROVBOX_ADDR_TYPE_NONE
#define MMI_PROVBOX_ADDR_TYPE_PHONENUM SRV_PROVBOX_ADDR_TYPE_PHONENUM
#define MMI_PROVBOX_ADDR_TYPE_IPV4 SRV_PROVBOX_ADDR_TYPE_IPV4
#define MMI_PROVBOX_ADDR_TYPE_TEXT SRV_PROVBOX_ADDR_TYPE_TEXT

typedef srv_provbox_addr_type_enum mmi_provbox_addr_type_enum;

#define MMI_PROVBOX_SAVE_DATA_TYPE_NONE SRV_PROVBOX_SAVE_DATA_TYPE_NONE
#define MMI_PROVBOX_SAVE_DATA_TYPE_FILE SRV_PROVBOX_SAVE_DATA_TYPE_FILE
#define MMI_PROVBOX_SAVE_DATA_TYPE_RAW_DATA SRV_PROVBOX_SAVE_DATA_TYPE_RAW_DATA 

typedef srv_provbox_save_data_type_enum mmi_provbox_save_data_type_enum;

#define MMI_PROVBOX_MSG_FLAG_READING SRV_PROVBOX_MSG_FLAG_READING

typedef srv_provbox_msg_flag_enum mmi_provbox_msg_flag_enum;


#define MMI_PROVBOX_MSG_FLAG_OP_SET SRV_PROVBOX_MSG_FLAG_OP_SET
#define MMI_PROVBOX_MSG_FLAG_OP_CLEAR SRV_PROVBOX_MSG_FLAG_OP_CLEAR

typedef srv_provbox_msg_flag_op_enum mmi_provbox_msg_flag_op_enum;

#define MMI_PROVBOX_MSG_OP_DELETE SRV_PROVBOX_MSG_OP_DELETE
#define MMI_PROVBOX_MSG_OP_MOVE_TO_ARCHIVE SRV_PROVBOX_MSG_OP_MOVE_TO_ARCHIVE
#define MMI_PROVBOX_MSG_OP_MAX_ITEM SRV_PROVBOX_MSG_OP_MAX_ITEM

//typedef srv_provbox_msg_op_enum mmi_provbox_msg_op_enum;

#define MMI_PROVBOX_MSG_READ_STATUS_UNREAD SRV_PROVBOX_MSG_READ_STATUS_UNREAD
#define MMI_PROVBOX_MSG_READ_STATUS_READ SRV_PROVBOX_MSG_READ_STATUS_READ

typedef srv_provbox_msg_read_status_enum mmi_provbox_msg_read_status_enum;

#define MMI_PROVBOX_MSG_PIN_STATUS_NOT_VERIFIED SRV_PROVBOX_MSG_PIN_STATUS_NOT_VERIFIED
#define MMI_PROVBOX_MSG_PIN_STATUS_VERIFIED SRV_PROVBOX_MSG_PIN_STATUS_VERIFIED

typedef srv_provbox_msg_pin_status_enum mmi_provbox_msg_pin_status_enum;

#define  MMI_PROVBOX_CONFIG_STATUS_NOT_INSTALLED  SRV_PROVBOX_CONFIG_STATUS_NOT_INSTALLED
#define  MMI_PROVBOX_CONFIG_STATUS_NOAPP SRV_PROVBOX_CONFIG_STATUS_NOAPP
#define  MMI_PROVBOX_CONFIG_STATUS_CONFIGED SRV_PROVBOX_CONFIG_STATUS_CONFIGED
#define  MMI_PROVBOX_CONFIG_STATUS_FAILED SRV_PROVBOX_CONFIG_STATUS_FAILED
#define  MMI_PROVBOX_CONFIG_STATUS_SKIPPED SRV_PROVBOX_CONFIG_STATUS_SKIPPED
#define  MMI_PROVBOX_CONFIG_STATUS_UPDATED SRV_PROVBOX_CONFIG_STATUS_UPDATED
#define  MMI_PROVBOX_CONFIG_STATUS_INVALID SRV_PROVBOX_CONFIG_STATUS_INVALID
#define  MMI_PROVBOX_CONFIG_STATUS_UNSUPPORTED SRV_PROVBOX_CONFIG_STATUS_UNSUPPORTED
#define  MMI_PROVBOX_CONFIG_STATUS_CORRUPTED SRV_PROVBOX_CONFIG_STATUS_CORRUPTED
#define  MMI_PROVBOX_CONFIG_STATUS_MISSING_DATA SRV_PROVBOX_CONFIG_STATUS_MISSING_DATA
#define  MMI_PROVBOX_CONFIG_STATUS_MAX_ITEM SRV_PROVBOX_CONFIG_STATUS_MAX_ITEM

typedef srv_provbox_config_status_enum mmi_provbox_config_status_enum;



/*----------------------------------------------------------------------------*/
/* Typedef function pointer                                                   */
/*----------------------------------------------------------------------------*/


typedef srv_provbox_addr_struct                         mmi_provbox_addr_struct;
typedef srv_provbox_msg_data_struct                     mmi_provbox_msg_data_struct;
//typedef srv_provbox_sim_msg_stat_struct                 mmi_provbox_sim_msg_stat_struct;
//typedef srv_provbox_box_msg_stat_struct                 mmi_provbox_box_msg_stat_struct;


#ifdef __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__
typedef srv_provbox_sort_data_union                     mmi_provbox_sort_data_union;
#endif /* __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__ */

//typedef srv_provbox_msg_sort_info_struct                mmi_provbox_msg_sort_info_struct;

typedef srv_provbox_msg_cmn_info_struct                 mmi_provbox_msg_cmn_info_struct;
//typedef srv_provbox_app_config_status_struct            mmi_provbox_app_config_status_struct;
typedef srv_provbox_msg_config_status_struct            mmi_provbox_msg_config_status_struct;
//typedef srv_provbox_continue_process_job_ind_struct     mmi_provbox_continue_process_job_ind_struct;
typedef srv_provbox_save_msg_available_ind_struct       mmi_provbox_save_msg_available_ind_struct;
typedef srv_provbox_save_msg_req_struct                 mmi_provbox_save_msg_req_struct;
typedef srv_provbox_save_msg_cnf_struct                 mmi_provbox_save_msg_cnf_struct;
typedef srv_provbox_get_msg_data_req_struct             mmi_provbox_get_msg_data_req_struct;
typedef srv_provbox_get_msg_data_cnf_struct             mmi_provbox_get_msg_data_cnf_struct;

//typedef srv_provbox_new_msg_ind_struct                  mmi_provbox_new_msg_ind_struct;
typedef srv_provbox_list_info_changed_ind_struct        mmi_provbox_list_info_changed_ind_struct;

//typedef srv_provbox_get_msg_num_req_struct              mmi_provbox_get_msg_num_req_struct;
//typedef srv_provbox_get_msg_num_cnf_struct              mmi_provbox_get_msg_num_cnf_struct;
//typedef srv_provbox_get_sort_info_req_struct            mmi_provbox_get_sort_info_req_struct;
//typedef srv_provbox_get_sort_info_cnf_struct            mmi_provbox_get_sort_info_cnf_struct;
//typedef srv_provbox_get_list_info_by_index_req_struct   mmi_provbox_get_list_info_by_index_req_struct;
//typedef srv_provbox_get_list_info_by_index_cnf_struct   mmi_provbox_get_list_info_by_index_cnf_struct;
//typedef srv_provbox_get_list_info_by_id_req_struct      mmi_provbox_get_list_info_by_id_req_struct;

//typedef srv_provbox_get_list_info_by_id_cnf_struct      mmi_provbox_get_list_info_by_id_cnf_struct;
//typedef srv_provbox_delete_msg_req_struct               mmi_provbox_delete_msg_req_struct;
//typedef srv_provbox_delete_msg_cnf_struct               mmi_provbox_delete_msg_cnf_struct;

//typedef srv_provbox_delete_all_msg_req_struct           mmi_provbox_delete_all_msg_req_struct;
//typedef srv_provbox_delete_all_msg_cnf_struct           mmi_provbox_delete_all_msg_cnf_struct;
//typedef srv_provbox_multi_op_req_struct                 mmi_provbox_multi_op_req_struct;

//typedef srv_provbox_multi_op_cnf_struct                 mmi_provbox_multi_op_cnf_struct;
typedef srv_provbox_set_msg_flag_req_struct             mmi_provbox_set_msg_flag_req_struct;
typedef srv_provbox_set_msg_flag_cnf_struct             mmi_provbox_set_msg_flag_cnf_struct;
//typedef srv_provbox_get_msg_info_req_struct             mmi_provbox_get_msg_info_req_struct;
typedef srv_provbox_get_msg_info_cnf_struct             mmi_provbox_get_msg_info_cnf_struct;
typedef srv_provbox_update_msg_info_req_struct          mmi_provbox_update_msg_info_req_struct;
typedef srv_provbox_update_msg_info_cnf_struct          mmi_provbox_update_msg_info_cnf_struct;

#define mmi_provbox_init srv_provbox_init
#define mmi_provbox_free_app_data srv_provbox_free_app_data

#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 

#endif /* MMI_PROVBOX_SRV_GPROT_H */ 

