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
 *  CallLogSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file exports all the interfaces provided by Call Log Service.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef SRV_CALL_LOG_GPROT_H
#define SRV_CALL_LOG_GPROT_H

/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Abbreviation                                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
/* KAL Layer */
#include "kal_general_types.h"

#include "custom_voip_config.h"
#include "custom_calllog.h"
#include "custom_phb_config.h"  
#include "nvram_common_defs.h"


/* MMI Layer */
#include "MMIDataType.h"
#include "mmi_res_range_def.h"
#include "ProcedureGprot.h"     
#include "mmi_frm_utility_gprot.h"

#include "mmi_rp_srv_calllog_def.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

/*----------------------------------------------------------------------------*/
/* DOC EMPTY                                                                  */
/*----------------------------------------------------------------------------*/

/*
 * An issue is found when to generate the SAP document automatically using the 3rd tool, The follow
 * C coding style with #define grammar can not be distinguished which leads to all structures which
 * has this #defines can not be discerned properly : <p /><p />
 * 
 * 
 * #define SRV_CLOG_LOG_IDENTITY  \ <p />
 *     U8 cate;        \ <p />
 *     U8 sim_id;      \ <p />
 *     U8 log_type;    \ <p />
 *     U8 sub_type
 * 
 * typedef struct <p />
 * {   <p />
 *     SRV_CLOG_LOG_IDENTITY;  <p />
 * }srv_clog_log_identity_struct; <p /><p />
 * 
 * In this case, srv_clog_log_identity_struct can not be seen rightly in the SAP document,due to SRV_CLOG_LOG_IDENTITY 
 * can not seen by this 3rd tool, so the SAP document generated by this tool can not present this structure properly.
 * The reason is that this 3rd tool can not know the grammar of "type field_name;" in a structure, while the grammar of
 * #define doesn't follow the grammar of "type field_name;" as it doesn't has the "field_name" and only be treated as the
 * grammar of "type;", so this 3rd tool can not parse it properly. <p />
 *
 * To solve this issue, there are two methods. <p />
 * 1. To parse this #define and add the full structure in a comment segment, for example:
 *
 * typedef struct                   <p />
 * {                                <p />
 * #ifdef __BUILD_DOM__             <p />
 *     U8 cate;                     <p />
 *     U8 sim_id;                   <p />
 *     U8 log_type;                 <p />
 *     U8 sub_type                  <p />
 * #else 
 *     SRV_CLOG_LOG_IDENTITY;       <p />
 * #endif                           <p />
 * }srv_clog_log_identity_struct;   <p /><p />
 * 
 * You can see this style in some other SAP documents, but as you can see, it cause the structure is not easy to understand in Gprot.h,
 * expecially in the Gprot.h which has many structures with this #define styles, such as this CallLogSrvGprot.h  <p />
 *
 * 2. As this 3rd tool can only understand the standand grammar of "type field_name;", it's easy to give a "filed_name"
 * and make the structure follow this "type filed_name" grammar and not affect the semantics by define an empty macro.
 * such as just define an empty macro element as below:
 * #define SRV_CLOG_EMPTY                   <p />     
 * then, use this macro in those structures with this #define style, such as:
 * typedef struct <p />
 * {                   <p />
 *    SRV_CLOG_LOG_IDENTITY SRV_CLOG_EMPTY; <p />
 * }srv_clog_log_identity_struct;  <p />
 *
 * So, srv_clog_log_identity_struct can be identified by this 3rd tool properly now. this method is easy to understand and
 * also make the code in Gprot.h clearly.  so, The 2nd mothed is preferred and used in this SAP document.     
 */
#define SRV_CLOG_EMPTY


/*----------------------------------------------------------------------------*/
/* Basic type define                                                           */
/*----------------------------------------------------------------------------*/

/* Instance handle, used to indicate an instance of Call Log Service */
typedef U32 SRV_CLOG_HANDLE;

/* CallLog identifier(ID), used to indicate a log id, each log has a log id and it's unique in the whole life of this phone,
   To save code size, it can be changed to U16 but need to check if the range is ok enougth and do some limitation handling 
   to keep the unique characteristics */
typedef U32 SRV_CLOG_ID;

#ifdef __BUILD_DOM__

/* The event parameter header <p /> 
 *
 * evt_id:       event id  <p /> 
 * size:         event struct size  <p /> 
 * user_data:    user data <p /> 
 */
#define MMI_EVT_PARAM_HEADER                \
     U16 evt_id;                            \
     U16 size;                              \
     void *user_data

#endif /* __BUILD_DOM__ */ 

/*
 * Identity of a log type, it's used to work as a unique identifier of a log type, 
 * it's the basic attributes of one log data when work as the part of one log data,
 * and it's a filter when to operate more than one log data, such as to get the logs with special type requirement,
 * in this scenario, all these parameters can be bit mask group, if some of them is zero, 
 * it will be discard when to filter the log data. <p />
 * 
 * cate    :    Log category, please refer to srv_clog_cate_enum <p />
 * sim_id  :    SIM id, please refer to mmi_sim_enum <p />  
 * log_type:    Log type, it depends on category parameter, for call log, it's srv_clog_clt_enum <p />
 * sub_type:    Sub type, it depends on category and log_type parameter, for call log, it's srv_clog_call_type_enum <p /> 
 */
#define SRV_CLOG_LOG_IDENTITY               \
    U8 cate;                                \
    U8 sim_id;                              \
    U8 log_type;                            \
    U8 sub_type

/*
 * Identifier of a log, it's used to work as a unique identifier of a log,
 * since a type of a log is unambiguous, all parameters of the SRV_CLOG_LOG_IDENTITY
 * can not be bit mask group but be a clearly bit value. <p />
 * 
 * SRV_CLOG_LOG_IDENTITY:    Identity of a log type <p />
 * log_id  :    Log id <p />  
 */
#define SRV_CLOG_LOG_IDENTIFIER             \
    SRV_CLOG_LOG_IDENTITY;                  \
    SRV_CLOG_ID  log_id

/*
 * The parameter header of getting list operation, to simple sync different getting list structure. <p />
 * 
 * start_by: To specify the type of start_elm field, please refer to srv_clog_by_enum, 
 * if it's SRV_CLOG_BY_ID, start_elm should be log_id <p />
 * if it's SRV_CLOG_BY_IDX, start_elm should be log list index <p />
 * start_elm: From which element to get log data according to start_elm field <p />
 * log_num:  To specify how many log data to get <p />
 */
#define SRV_CLOG_LIST_LOG_IDS_PARAM         \
    srv_clog_by_enum start_by;              \
    U32  start_elm;                         \
    U32  log_num


/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/* To check if an element is invalid, the element can only be handle(SRV_CLOG_HANDLE), log_id(SRV_CLOG_ID), next_index or next_log_id(SRV_CLOG_ID) */
#define SRV_CLOG_IS_ELM_INVALID(elm)                ((elm) == SRV_CLOG_INVALID_ELM)

/* To set an identity, please refer to srv_clog_log_identity_struct
* elm: Any structure point which can be typecasted to srv_clog_log_identity_struct*
* ct:  Log category, please refer to srv_clog_cate_enum         <p />
* sim: SIM id, please refer to mmi_sim_enum                     <p />
* lt:  Log type, please refer to srv_clog_clt_enum, srv_clog_slt_enum or srv_clog_nwpdlt_enum   <p />
* st:  Sub type, please refer to srv_clog_call_type_enum        <p />   
*/
#define SRV_CLOG_INIT_IDT(elm, ct, sim, lt, st)         \
    do{                                                 \
        (elm)->cate = (ct);                             \
        (elm)->sim_id = (sim);                          \
        (elm)->log_type = (lt);                         \
        (elm)->sub_type = (st);                         \
    }while(0)

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

/* Invalid element,  it can be instance handle(SRV_CLOG_HANDLE) , process id,
   log id(SRV_CLOG_ID), next log id(SRV_CLOG_ID), next list index, but can not be invalid PHB ID(SRV_PHB_ID) which is defined in PhbSrv */
#define SRV_CLOG_INVALID_ELM                    (0)

/* Max number of log id in a list to operate on, such as get or delete and so on */
#define SRV_CLOG_LOG_ID_LIST_MAX_NUM            (20)

/* Max number of log id in req to delete mutil, no more than max ctrl buff size */
#define SRV_CLOG_DEL_MULTI_LOG_MAX_NUM            (120)

/* Max char length of a caller id (CID) which can be URI address for VoIP call or phone number for others, use the same size as PhbSrv commonly */
#define SRV_CLOG_CID_MAX_LEN                    (NVRAM_CLOG_CID_MAX_LEN)

/* Max char length of a phone book name, use the same size as PhbSrv commonly */
#define SRV_CLOG_NAME_MAX_LEN                   (NVRAM_CLOG_NAME_MAX_LEN)

/* To specify how many PHB store index can be searched together in one search request, PHB store index is a conception of PhbSrv, it's the index
* of the storage slot in PhbSrv, it's not the index of PHB UI List, each storage slot can only save one phonebook entry which can has only one name
* but several numbers, each phonebook number also has a id named SRV_PHB_ID which is unique in storage slot level, 
* so, one phb store index may mappting to several PHB id also named phb_number_id in PhbSrv, this macro is used to
* to define how many phonebook name can be searched at the same time when to search all of logs from one phonebook name/entry,
* so may be the phone number is not same as one name can has several number.
*/
#define SRV_CLOG_PHB_IDX_MAX_SEARCH_NUM         (1)

/* Max number of total logs of all log types, it's the max slot limitation in Call Log Service,
 customer can only to change PHB_LN_ENTRY in project.mak file */
#define SRV_CLOG_LOG_MAX_NUM                    (CUSTOM_CLOG_MAX_LOG_NUM)

/* Max number of dialed call logs */
#define SRV_CLOG_MAX_DIALED_CLT_NUM             (CUSTOM_CLOG_MAX_DIALED_CLT_NUM)

/* Max number of missed call logs */
#define SRV_CLOG_MAX_MISSED_CLT_NUM             (CUSTOM_CLOG_MAX_MISSED_CLT_NUM)

/* Max number of received call logs */
#define SRV_CLOG_MAX_RECVED_CLT_NUM             (CUSTOM_CLOG_MAX_RECVED_CLT_NUM)

/* Max number of rejectd call logs, reserved for customization */
#define SRV_CLOG_MAX_REJED_CLT_NUM              (CUSTOM_CLOG_MAX_REJED_CLT_NUM)

/* The max count of timestamp and duration for one same log number, after meger; we name it as log group */
#define SRV_CLOG_TIME_DETAIL_MAX_NUM          (CUSTOM_CLOG_TIME_DETAIL_MAX_NUM)

/* The index of lastest log timestamp or lastest log duration */
#define SRV_CLOG_LASTEST_TIME_IDX                  (0)

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/* Log category, to classfy the log data, please refer to srv_clog_cate_idx_enum for bit-index mapping vice-versa,
only Call Log category is supported now, others are reserved for customization */
typedef enum
{
    SRV_CLOG_CATE_DEFAULT = 0x00,               /* Default value, please discard it if act as a filter  */
    SRV_CLOG_CATE_CALL = 0x01,                  /* Call log category */
    SRV_CLOG_CATE_SMS = 0x02,                   /* SMS log category, reserved for customization  */
    SRV_CLOG_CATE_NWPD = 0x04,                  /* Network packet data log category, reserved for customization  */
    SRV_CLOG_CATE_ALL = 0x07,                   /* All category, can act as bit mask group */
    SRV_CLOG_CATE_MAX_ITEM                      /* Max item */
} srv_clog_cate_enum;

/* Index of log category, used to work as the index of an array commonly, please refer to srv_clog_cate_enum for bit-index mapping vice-versa. */
typedef enum
{
    SRV_CLOG_CATE_IDX_CALL,                     /* Index of call log category */
    SRV_CLOG_CATE_IDX_SMS,                      /* Index of SMS log category, reserved for customization */
    SRV_CLOG_CATE_IDX_NWPD,                     /* Index of network packet data (NWPD) log category, reserved for customization*/
    SRV_CLOG_CATE_IDX_MAX_ITEM                  /* Max item */
} srv_clog_cate_idx_enum;

/* Index of SIM card, used as bit mask index or array index commonly, please refer to mmi_sim_enum for bit-index mapping vice-versa.
 only use SRV_CLOG_SIM_IDX_SIM1 on single SIM project specially */
typedef enum
{
    SRV_CLOG_SIM_IDX_SIM1,                      /* Index of the first SIM card */
    SRV_CLOG_SIM_IDX_SIM2,                      /* Index of the second SIM card */
    SRV_CLOG_SIM_IDX_SIM3,                      /* Index of the third SIM card */
    SRV_CLOG_SIM_IDX_SIM4,                      /* Index of the fourth SIM card */
    SRV_CLOG_SIM_IDX_MAX_ITEM = MMI_SIM_TOTAL   /* Max item, it's the read number of the SIM cards slot support physicaly on a target */
} srv_clog_sim_idx_enum;

/* Call log type (CLT), please refer to srv_clog_clt_idx_enum for bit-index mapping vice-versa,
* please remember to upgrade the NVRAM verno if change the dialed/received value as it's saved in call time data */
typedef enum
{
    SRV_CLOG_CLT_DEFAULT = 0x00,                /* Default value, just discard it if act as a filter */
    SRV_CLOG_CLT_DIALED = 0x01,                 /* Dialed call log type */
    SRV_CLOG_CLT_MISSED = 0x02,                 /* Missed call log type */
    SRV_CLOG_CLT_RECVED = 0x04,                 /* Received call log type */
    SRV_CLOG_CLT_REJED = 0x08,                  /* Rejected call log type, reserved for customization, the log type is decided by UcmSrv if a rejected call is treated as missed call or received call */
    SRV_CLOG_CLT_ALL = 0x0F,                    /* All call log type */
    SRV_CLOG_CLT_MAX_ITEM                       /* Max item */
} srv_clog_clt_enum;

/* Index of call log type, used as bit mask index or array index commonly, please refer to srv_clog_clt_enum for bit-index mapping vice-versa */
typedef enum
{
    SRV_CLOG_CLT_IDX_DIALED,                    /* Index of dialed call log type */
    SRV_CLOG_CLT_IDX_MISSED,                    /* Index of missed call log type */
    SRV_CLOG_CLT_IDX_RECVED,                    /* Index of received call log type */
    SRV_CLOG_CLT_IDX_REJED,                     /* Index of rejected call log, reserved for customization */
    SRV_CLOG_CLT_IDX_ALL,                       /* Index of all call log */
    SRV_CLOG_CLT_IDX_MAX_ITEM                   /* Max item */
} srv_clog_clt_idx_enum;

/* SMS log type (SLT), reserved for customization */
typedef enum
{
    SRV_CLOG_SLT_DEFAFULT = 0x00,               /* Default value, discard it if act as a filter */
    SRV_CLOG_SLT_SENT = 0x01,                   /* Sent SMS log type */
    SRV_CLOG_SLT_RECV = 0x02,                   /* Received SMS log type */
    SRV_CLOG_SLT_ALL = 0x03,                    /* All SMS log type */
    SRV_CLOG_SLT_MAX_ITEM                       /* Max item */    
} srv_clog_slt_enum;

/* Network packet data log type (NWPDLT), reserved for customization */
typedef enum
{
    SRV_CLOG_NWPDLT_DEFAFULT = 0x00,            /* Default value, discard it if act as a filter */
    SRV_CLOG_NWPDLT_SENT = 0x01,                /* Sent network packet data log type */
    SRV_CLOG_NWPDLT_RECV = 0x02,                /* Received network packet data log type */
    SRV_CLOG_NWPDLT_ALL = 0x03,                 /* All packet data type */
    SRV_CLOG_NWPDLT_MAX_ITEM                    /* max item */
} srv_clog_nwpdlt_enum;

/* Call type, please refer to srv_clog_call_type_idx_enum for bit-index mapping vice-versa */
typedef enum
{
    SRV_CLOG_CALL_TYPE_DEFAULT = 0x00,          /* Default value, discard it if act as a filter */
    SRV_CLOG_CALL_TYPE_VOICE = 0x01,            /* Voice call type */
    SRV_CLOG_CALL_TYPE_VIDEO = 0x02,            /* Video call type */
    SRV_CLOG_CALL_TYPE_NON_VOIP = 0x03,         /* Non-VoIP call type */
    SRV_CLOG_CALL_TYPE_VOIP = 0x04,             /* VoIP call type */
    SRV_CLOG_CALL_TYPE_ALL = 0x07,              /* All call type */
    SRV_CLOG_CALL_TYPE_MAX_ITEM                 /* Max item */
} srv_clog_call_type_enum;

/* Index of Call type, used as bit mask index or array index commonly, please refer to srv_clog_call_type_enum for bit-index mapping vice-versa */
typedef enum
{
    SRV_CLOG_CALL_TYPE_IDX_VOICE,               /* Index of voice call type */       
    SRV_CLOG_CALL_TYPE_IDX_VIDEO,               /* Index of video call type */
    SRV_CLOG_CALL_TYPE_IDX_VOIP,                /* Index of VoIP call type */
    SRV_CLOG_CALL_TYPE_IDX_MAX_ITEM             /* Max item */
} srv_clog_call_type_idx_enum;

/* Number type, use to get the number info of different log type combination */
typedef enum
{
    SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS,           /* Total logs in a list, one log has one item */
    SRV_CLOG_LOG_NUM_TYPE_UNREAD_NUM,           /* Unread number of all logs */
    SRV_CLOG_LOG_NUM_TYPE_MAX_ITEM              /* Max item */
} srv_clog_log_num_type_enum;

/* By type, use to specify how to get log data, please refer to SRV_CLOG_LIST_LOG_IDS_PARAM */
typedef enum
{
    SRV_CLOG_BY_ID,                             /* By id, e.g. to get logs by log_id */
    SRV_CLOG_BY_IDX,                            /* By index,  e.g. to get logs by list index */
    SRV_CLOG_BY_MAX_ITEM                        /* Max item */
} srv_clog_by_enum;

/* Call log field, it can be bit mask group */
typedef enum
{
    SRV_CLOG_LOG_FIELD_DEFAULT = 0x0000,        /* Default value, just discard it if act as a filter */
    SRV_CLOG_LOG_FIELD_IDENTITY = 0x0001,       /* Identity field */
    SRV_CLOG_LOG_FIELD_LOG_ID = 0x0002,         /* log id */
    SRV_CLOG_LOG_FIELD_PHB_ID = 0x0004,         /* PHB id field, also named phonebook number id, please refer to SAP document of PhbSrv or PhbSrvGprot.h */
    SRV_CLOG_LOG_FIELD_TIMESTAMP = 0x0008,      /* Timestamp field */
    SRV_CLOG_LOG_FIELD_DURATION = 0x0010,       /* Duration filed */
    SRV_CLOG_LOG_FIELD_TOTAL_NUM = 0x0020,      /* Total number field */
    SRV_CLOG_LOG_FIELD_UNREAD_NUM = 0x0040,     /* Unread number field */
    SRV_CLOG_LOG_FIELD_IS_PRIVATE_CID = 0x0080, /* Is private CID field */
    SRV_CLOG_LOG_FIELD_IS_NEW_EVENT = 0x0100,   /* Is new event field */
    SRV_CLOG_LOG_FIELD_LIGHT_VALUES = 0x01FF,   /* Non-string fields */
    SRV_CLOG_LOG_FIELD_NAME = 0x0200,           /* Name field */
    SRV_CLOG_LOG_FIELD_CID = 0x0400,            /* Caller id field */
    SRV_CLOG_LOG_FIELD_ALL = 0x0FFF,            /* All fields */

    SRV_CLOG_LOG_FIELD_PHB_IDXS = 0x1000,       /* PHB store index array fields, only used in srv_clog_search_list_log_ids */

    SRV_CLOG_LOG_FIED_MAX_ITEM                  /* Max item */
} srv_clog_log_field_enum;

/* Result code used in most APIs, should be zero or negative number */
typedef enum
{
    SRV_CLOG_RET_OK = 0,                        /* Success */
    SRV_CLOG_RET_FAIL = -1,                     /* Failed */
    SRV_CLOG_RET_UNKNOWN = -2,                  /* Unknown error */
    SRV_CLOG_RET_NOT_READY = -3,                /* Not ready */
    SRV_CLOG_RET_BUSY = -4,                     /* Busy */
    SRV_CLOG_RET_INVALID = -5,                  /* Invalid */
    SRV_CLOG_RET_INVALID_PARAM = -6,            /* Invalid parameter */
    SRV_CLOG_RET_NOT_FOUND = -10,               /* Not found */
    SRV_CLOG_RET_NOT_SUPPORT = -12,             /* Not support */
    SRV_CLOG_RET_MEM_FULL = -13,                /* Memory full */
    SRV_CLOG_RET_EMPTY = -14,                   /* Empty */
    SRV_CLOG_RET_NEED_RESTART = -15,            /* Need restart */
    SRV_CLOG_RET_NOT_INIT = -16,                /* No initilized */
    SRV_CLOG_RET_PARTIAL_DELETED = -17,         /* Partial deleted */
    SRV_CLOG_RET_SIM_REFERSHED = -18,           /* SIM EF file is refreshed */
    SRV_CLOG_RET_SIM_SYNC = -19,                /* The data between phone storage and SIM card is just sync now, applicaion need to reload the log list */
    SRV_CLOG_RET_CONTINUE = -20,                /* Continue to process current job */
    SRV_CLOG_RET_STOP = -21,                    /* Stop current operation */
    SRV_CLOG_RET_CANCELLED = -22,               /* canceled */
    SRV_CLOG_RET_WAITING = -23,                 /* Waiting */
    SRV_CLOG_RET_NOT_AVAILABLE = -30,           /* Not available */
    SRV_CLOG_RET_QUEUE_FULL = -100,             /* Queue if full */
    SRV_CLOG_RET_MAX_ITEM                       /* Max item */
} srv_clog_ret_enum;

/* Parameter type, used in srv_clog_init_para */
typedef enum
{
    SRV_CLOG_PARA_CREATE,                       /* Parameter type of srv_clog_create_struct */
    SRV_CLOG_PARA_IDENTITY,                     /* Parameter type of srv_clog_log_identity_struct */
    SRV_CLOG_PARA_IDENTIFIER,                   /* Parameter type of srv_clog_log_identifier_struct */
    SRV_CLOG_PARA_NUM_INFO,                     /* Parameter type of srv_clog_num_info_struct */
    SRV_CLOG_PARA_GET_LIST_LOG_IDS_REQ,         /* Parameter type of srv_clog_get_list_log_ids_req_struct */
    SRV_CLOG_PARA_GET_LIST_LOG_IDS_CNF,         /* Parameter type of srv_clog_get_list_log_ids_cnf_struct */
    SRV_CLOG_PARA_GET_LIST_LOG_REQ,             /* Parameter type of srv_clog_get_list_log_req_struct */
    SRV_CLOG_PARA_GET_LIST_LOG_CNF,             /* Parameter type of srv_clog_get_list_log_cnf_struct */
    SRV_CLOG_PARA_GET_LAST_LOG_REQ,             /* Parameter type of srv_clog_get_last_log_req_struct */
    SRV_CLOG_PARA_GET_LAST_LOG_CNF,             /* Parameter type of srv_clog_get_last_log_cnf_struct */
    SRV_CLOG_PARA_LOG,                          /* Parameter type of srv_clog_log_struct */
    SRV_CLOG_PARA_ADD_LOG_REQ,                  /* Parameter type of srv_clog_add_log_req_struct */
    SRV_CLOG_PARA_ADD_LOG_CNF,                  /* Parameter type of srv_clog_add_log_cnf_struct */
    SRV_CLOG_PARA_LOG_CALL_REQ,                 /* Parameter type of srv_clog_log_call_req_struct */
    SRV_CLOG_PARA_LOG_CALL_CNF,                 /* Parameter type of srv_clog_log_call_cnf_struct */
    SRV_CLOG_PARA_LOG_DURATION_REQ,             /* Parameter type of srv_clog_log_duration_req_struct */
    SRV_CLOG_PARA_LOG_DURATION_CNF,             /* Parameter type of srv_clog_log_duration_cnf_struct */
    SRV_CLOG_PARA_UPDATE_LOG_REQ,               /* Parameter type of srv_clog_update_log_req_struct */    
    SRV_CLOG_PARA_UPDATE_LOG_CNF,               /* Parameter type of srv_clog_update_log_cnf_struct */
    SRV_CLOG_PARA_UPDATE_ALL_LOGS_REQ,          /* Parameter type of srv_clog_update_all_logs_req_struct */
    SRV_CLOG_PARA_UPDATE_ALL_LOGS_CNF,          /* Parameter type of srv_clog_update_all_logs_cnf_struct */
    SRV_CLOG_PARA_DEL_LOG_REQ,                  /* Parameter type of srv_clog_del_log_req_struct */
    SRV_CLOG_PARA_DEL_LOG_CNF,                  /* Parameter type of srv_clog_del_log_cnf_struct */
    SRV_CLOG_PARA_DEL_ALL_LOGS_REQ,             /* Parameter type of srv_clog_del_all_logs_req_struct */
    SRV_CLOG_PARA_DEL_ALL_LOGS_CNF,             /* Parameter type of srv_clog_del_all_logs_cnf_struct */
    SRV_CLOG_PARA_DEL_MULTI_LOGS_REQ,           /* Parameter type of srv_clog_del_multi_logs_req_struct */
    SRV_CLOG_PARA_DEL_MULTI_LOGS_CNF,           /* Parameter type of srv_clog_del_multi_logs_cnf_struct */
    SRV_CLOG_PARA_SEARCH_LIST_LOG_IDS_REQ,      /* Parameter type of srv_clog_search_list_log_ids_req_struct */
    SRV_CLOG_PARA_SEARCH_LIST_LOG_IDS_CNF,      /* Parameter type of srv_clog_search_list_log_ids_cnf_struct */

    SRV_CLOG_PARA_MAX_ITEM                  /* Max item */
} srv_clog_para_enum;


/* Result type of an add log action */
typedef enum
{
    SRV_CLOG_ADD_LOG_RET_PURE_ADD,              /* Add new log and not affect other logs */
    SRV_CLOG_ADD_LOG_RET_PURE_MERGE,            /* merge with existing log with same call info, the log_id, total_num are changed, name, number and unread_num may be changed */
    SRV_CLOG_ADD_LOG_RET_REPLACE_OLDEST,        /* replace existing log which is the oldest and independent with this new log */
    SRV_CLOG_ADD_LOG_RET_MAX_ITEM               /* Max item */
} srv_clog_add_log_ret_enum;


/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/
/* Structure for identity, it can work as a base type for identity structures */
typedef struct
{
    SRV_CLOG_LOG_IDENTITY SRV_CLOG_EMPTY;       /* LOg identity */
} srv_clog_log_identity_struct;

/* Structure for identifier, it can work as a base type for identifier structures */
typedef struct
{
    SRV_CLOG_LOG_IDENTIFIER SRV_CLOG_EMPTY;     /* Log identifier */
} srv_clog_log_identifier_struct;

/* Structure for create a new instance. Application can set the base filter by identity for this instance,
   then application does not set its filter again if it always use the same filter,
   CallLog service can check this when to handle a request, and every API can also give a special filter for this special request,
   CallLog Service can merge them and only give the data which can fit both these two filters.
   please refer to srv_clog_create. */
typedef struct
{
    srv_clog_log_identity_struct identity;      /* Log identity, work as the base filter for this instance, this instance can only operate those log data fit this basic filter in its whle life cycle */
    void *user_data;                            /* The caller's user data, caller can pass its user data to CallLogSrv to support multiple instance */
} srv_clog_create_struct;

/* Structure for number statistics, please refer to srv_clog_get_list_num_info */
typedef struct
{
    U16 num[SRV_CLOG_LOG_NUM_TYPE_MAX_ITEM];    /* Number statistics array */
} srv_clog_num_info_struct;

/* Structure for call log */
typedef struct
{
    SRV_CLOG_LOG_IDENTIFIER SRV_CLOG_EMPTY;     /* Log identifier */
    SRV_PHB_ID phb_id;                          /* PHB id, also named phonebook number id, please refer to SAP document of PhbSrv or PhbSrvGprot.h */
    WCHAR name[SRV_CLOG_NAME_MAX_LEN + 1];      /* Name */
    WCHAR cid[SRV_CLOG_CID_MAX_LEN + 1];        /* Caller id (CID), phone number or voip address, in ASCII encode  */
    U32 timestamp[SRV_CLOG_TIME_DETAIL_MAX_NUM];      /* Timestamp, it is order sequence, and timestamp[0] is the lastest */
    U32 duration[SRV_CLOG_TIME_DETAIL_MAX_NUM];       /* Call duration, it is order sequence, and duration[0] is the lastest  */
    U16 total_num;                              /* Total merged number, it's valid only if a log in a sort list, only support 255 now, if more, discard it */
    U16 unread_num;                             /* Unread number */
    U8 is_private_cid;                          /* Private cid or not */
    U8 is_new_event;                            /* New event or not */
} srv_clog_call_log_struct;

/* Structure for SMS log, reserved for customization */
typedef struct
{
    SRV_CLOG_LOG_IDENTIFIER SRV_CLOG_EMPTY;     /* Log identifier */
    SRV_PHB_ID phb_id;                          /* PHB id, also named phonebook number id, please refer to SAP document of PhbSrv or PhbSrvGprot.h */
    WCHAR name[SRV_CLOG_NAME_MAX_LEN + 1];      /* Name */
    WCHAR cid[SRV_CLOG_CID_MAX_LEN + 1];        /* Caller id (CID), phone number, ASCII encode */
    U32 timestamp;                              /* Timestamp */
    U16 total_num;                              /* Total sms number of a log SMS */
} srv_clog_sms_log_struct;

/* Structure for network packet data log, reserved for customization */
typedef struct
{
    SRV_CLOG_LOG_IDENTIFIER SRV_CLOG_EMPTY;     /* Log identifier */
    SRV_PHB_ID phb_id;                          /* PHB id, also named phonebook number id, please refer to SAP document of PhbSrv or PhbSrvGprot.h */
    WCHAR name[SRV_CLOG_NAME_MAX_LEN + 1];      /* Name */
    WCHAR cid[SRV_CLOG_CID_MAX_LEN + 1];        /* Caller id (CID), ASCII encode */
    U32 timestamp;                              /* Timestamp */
    U32 size;                                   /* Data size in byte */
} srv_clog_nwpd_log_struct;

/* Union for all logs */
typedef union
{
    srv_clog_call_log_struct call_log;          /* Call log */
    srv_clog_sms_log_struct sms_log;            /* SMS log, reserved for customization */
    srv_clog_nwpd_log_struct nwpd_log;          /* Network packet data log, reserved for customization */
} srv_clog_log_union;

/* Structure for log data, please refer to srv_clog_get_xxx APIs */
typedef struct
{
    U8 cate;                                    /* Log category, only call log category is supported now, others are reserved for customization */
    srv_clog_log_union data;                    /* Log data */
} srv_clog_log_struct;

/* Structure for the request of getting list log ids, please refer to srv_clog_get_list_log_ids. */
typedef struct
{
    SRV_CLOG_LOG_IDENTITY SRV_CLOG_EMPTY;       /* Log identity */
#ifndef __BUILD_DOM__
    SRV_CLOG_LIST_LOG_IDS_PARAM SRV_CLOG_EMPTY; /* Get list ids parameter */
#else /* __BUILD_DOM__ */
    srv_clog_by_enum start_by;                  /* Start By type */
    U32  start_elm;                             /* Start element, log id or log index, decided by start_by field  */
    U32  log_num;                               /* Log number */
#endif /* __BUILD_DOM__ */
} srv_clog_get_list_log_ids_req_struct;

/* Structure for the conform of getting list log ids, please refer to srv_clog_get_list_log_ids. */
typedef struct
{
    SRV_CLOG_LOG_IDENTITY SRV_CLOG_EMPTY;       /* Log identity */
#ifndef __BUILD_DOM__
    SRV_CLOG_LIST_LOG_IDS_PARAM SRV_CLOG_EMPTY; /* Get list ids parameter */
#else /* __BUILD_DOM__ */
    srv_clog_by_enum start_by;                  /* Start By type */
    U32  start_elm;                             /* Start element, log id or log index, decided by start_by field */
    U32  log_num;                               /* Log number */
#endif /* __BUILD_DOM__ */
    U32 next_start_elm;                         /* Next start element, its type is decided by start_by field */
    SRV_CLOG_ID log_ids[SRV_CLOG_LOG_ID_LIST_MAX_NUM];  /* Log id list */
    srv_clog_ret_enum ret;                      /* Result code */
} srv_clog_get_list_log_ids_cnf_struct;

/* Structure for the request of getting log data, please refer to srv_clog_get_list_log. */
typedef struct
{
    SRV_CLOG_LOG_IDENTITY SRV_CLOG_EMPTY;       /* Log identity */
    srv_clog_by_enum get_by;                    /* By type for element to get */
    U32 get_elm;                                /* Get element, log id or log index, decided by get_by field */
    U32 fields;                                 /* Field bit mask group to get, if zero, return all fields, please refer to srv_clog_log_field_enum  */
} srv_clog_get_list_log_req_struct;

/* Structure for the confirmation of getting log data, please refer to srv_clog_get_list_log. */
typedef struct
{
    SRV_CLOG_LOG_IDENTITY SRV_CLOG_EMPTY;       /* Log identity */
    srv_clog_by_enum get_by;                    /* By type for element to get, log id or array index, decided by get_by */
    U32 get_elm;                                /* Log id or log index */
    U32 fields;                                 /* Field bit mask group to get, if zero, return all fields, please refer to srv_clog_log_field_enum */
    srv_clog_log_struct log;                    /* Log data */
    srv_clog_ret_enum ret;                      /* Result code */
} srv_clog_get_list_log_cnf_struct;

/* Structure for the request of getting the last log, please refer to srv_clog_get_last_log. */
typedef struct
{
    SRV_CLOG_LOG_IDENTITY SRV_CLOG_EMPTY;       /* Log identity */
    U32 fields;                                 /* Field bit mask group to get, if zero, return all fields, please refer to srv_clog_log_field_enum */
} srv_clog_get_last_log_req_struct;

/* Structure for the confirmation of getting the last log, please refer to srv_clog_get_last_log. */
typedef struct
{
    SRV_CLOG_LOG_IDENTITY SRV_CLOG_EMPTY;       /* Log identity */
    U32 fields;                                 /* Field bit mask group to get, if zero, return all fields, please refer to srv_clog_log_field_enum  */
    srv_clog_log_struct log;                    /* Log data */
    srv_clog_ret_enum ret;                      /* Result code */
} srv_clog_get_last_log_cnf_struct;

/* Structure for the request of logging a new call log, please refer to srv_clog_log_call. */
typedef struct
{
    SRV_CLOG_LOG_IDENTITY SRV_CLOG_EMPTY;       /* Log identity */
    SRV_PHB_ID phb_id;                          /* PH id encoded with store index and phone number type */
    WCHAR *name;                                /* some name may come from network, such voice email, voip, ip dial. */
    WCHAR *cid;                                 /* Caller id, phone number or VoIP address */
    U32 timestamp;                              /* Timestamp to add this new log, it's the number of second. */
    MMI_BOOL is_private_cid;                    /* Private caller id or not */
} srv_clog_log_call_req_struct;

/* Structure for the confirmation of logging a new call log, please refer to srv_clog_log_call. */
typedef struct
{
    SRV_CLOG_ID log_id;                         /* Log id */
    srv_clog_ret_enum ret;                      /* Result code */
} srv_clog_log_call_cnf_struct;

/* Structure for the request of adding a new log, please refer to srv_clog_add_log. */
typedef srv_clog_log_struct srv_clog_add_log_req_struct;

/* Structure for the confirmation of adding a new log, please refer to srv_clog_add_log. */
typedef struct
{
    SRV_CLOG_ID log_id;                         /* Log id */
    srv_clog_ret_enum ret;                      /* Result code */
} srv_clog_add_log_cnf_struct;

/* Structure for the request of logging the duration periodically for a new call log, please refer to srv_clog_log_duration */
typedef struct
{
    SRV_CLOG_LOG_IDENTIFIER SRV_CLOG_EMPTY;     /* Log identifier */
    U32 duration;                               /* Duration, specially for missed call, it's the duration from the call is receved to the call is hung up */
} srv_clog_log_duration_req_struct;

/* Structure for confirmation of logging the duration periodically for a  new call log, please refer to srv_clog_log_duration  */
typedef struct
{
    SRV_CLOG_ID log_id;                         /* Log id */
    srv_clog_ret_enum ret;                      /* Result code */
} srv_clog_log_duration_cnf_struct;

/* Structure for the request of updating a log, please refer to srv_clog_update_log */
typedef struct
{
    U32 req_fields;                             /* Fields bit mask group, to specify which fields to be updated */
    srv_clog_log_struct log_data;               /* Log data, can only set the update field */
} srv_clog_update_log_req_struct;

/* Structure for the confirmation of updating a log, please refer to srv_clog_update_log  */
typedef struct
{
    SRV_CLOG_ID log_id;                         /* Log id */
    U32 req_fields;                             /* Fields bit mask group, to specify which fields to be updated, please refer to srv_clog_log_field_enum  */
    U32 updated_fields;                         /* Fields bit mask group, to specify which fields are updated finally, please refer to srv_clog_log_field_enum  */
    srv_clog_ret_enum ret;                      /* Result code */
} srv_clog_update_log_cnf_struct;

/* Structure for the request of updating all logs, please refer to srv_clog_update_all_logs */
typedef struct
{
    SRV_CLOG_LOG_IDENTITY SRV_CLOG_EMPTY;       /* Log identity */
    U32 req_fields;                             /* Fields to update, only support read state now, please refer to srv_clog_log_field_enum  */
    MMI_BOOL read;                              /* Read or not, can only be MMI_TURE now, change unread state to read for all logs */
} srv_clog_update_all_logs_req_struct;

/* Structure for the confirmation of updating all logs, please refer to srv_clog_update_all_logs */
typedef struct
{
    U32 req_fields;                             /* Fields to update, only support read state now, please refer to srv_clog_log_field_enum  */
    U32 updated_fields;                         /* Fields updated, only support read state now, please refer to srv_clog_log_field_enum  */
    U32 total_num;                              /* Total number to be updated */
    U32 num_updated;                            /* How many logs are updated */
    srv_clog_ret_enum ret;                      /* Result code */
} srv_clog_update_all_logs_cnf_struct;

/* Structure for the request of deleting a log, please refer to srv_clog_delete_log_by_id. */
typedef struct
{
    SRV_CLOG_ID log_id;                         /* Log id */
} srv_clog_del_log_req_struct;

/* Structure for the confirmation of deleting a log, please refer to srv_clog_delete_log_by_id. */
typedef struct
{
    SRV_CLOG_ID log_id;                         /* Log id */
    srv_clog_ret_enum ret;                      /* Result code */
} srv_clog_del_log_cnf_struct;

/* Structure for the request of deleting all logs, please refer to srv_clog_delete_all_logs */
typedef struct
{
    SRV_CLOG_LOG_IDENTITY SRV_CLOG_EMPTY;       /* Log identity */
} srv_clog_del_all_logs_req_struct;

/* Structure for the confirmation of deleting all logs, please refer to srv_clog_delete_all_logs   */
typedef struct
{
    U32 total_num;                              /* Total number */
    U32 deleted_num;                            /* The number of deleted log */
    srv_clog_ret_enum ret;                      /* result code */
} srv_clog_del_all_logs_cnf_struct;

/* DOM-NOT_FOR_SDK-BEGIN */

/* Structure for the request of deleting multi logs, please refer to srv_clog_delete_multi_logs */
typedef struct
{
    SRV_CLOG_LOG_IDENTITY SRV_CLOG_EMPTY;       /* Log identity */
    SRV_CLOG_ID log_ids[SRV_CLOG_DEL_MULTI_LOG_MAX_NUM];        /* set valid id in first array, set other as SRV_CLOG_INVALID_ELM */
} srv_clog_del_multi_logs_req_struct;

/* Structure for the confirmation of deleting multi logs, please refer to srv_clog_delete_multi_logs   */
typedef struct
{
    U32 total_num;                              /* Total number */
    U32 deleted_num;                            /* The number of deleted log */
    srv_clog_ret_enum ret;                      /* result code */
} srv_clog_del_multi_logs_cnf_struct;

/* DOM-NOT_FOR_SDK-END */

/* Structure for the request of searching list log ids, please refer to srv_clog_search_list_log_ids */
typedef struct
{
    SRV_CLOG_LOG_IDENTITY SRV_CLOG_EMPTY;       /* Log identity */
    srv_clog_by_enum start_by;                  /* To specify the type of start_elm field */
    U32 start_elm;                              /* Start element, log id or list index, decided by start_by field  */
    U32 search_fields;                          /* Fields to match, if zero, skip it and search all fields, please refer to srv_clog_log_field_enum  */
    U16 phb_idx_num;                            /* The number of PHB store index stored in phb_idx array */
    U16 phb_idx[SRV_CLOG_PHB_IDX_MAX_SEARCH_NUM];	/* Array to store the PHB store index for searching */
} srv_clog_search_list_log_ids_req_struct;

/* Structure for the confirmation of searching list log ids, please refer to srv_clog_search_list_log_ids */
typedef struct
{
    SRV_CLOG_LOG_IDENTITY SRV_CLOG_EMPTY;       /* Log identity */
    srv_clog_by_enum start_by;                  /* Start element, log id or list index */
    SRV_CLOG_ID start_elm;                      /* Start element, log id or list index, decided by start_by field */
    U32 search_fields;                          /* Fields to match, if zero, skip it and search all fields, please refer to srv_clog_log_field_enum  */
    U16 id_num;                                 /* Id number stored in log_ids array */
    SRV_CLOG_ID log_ids[SRV_CLOG_LOG_ID_LIST_MAX_NUM];  /* Log ids */
    SRV_CLOG_ID next_elm;                       /* Next element to search, its type is decided by start_by field */
    srv_clog_ret_enum ret;                      /* result code */
} srv_clog_search_list_log_ids_cnf_struct;

/*----------------------------------------------------------------------------*/
/* Event                                                                      */
/*----------------------------------------------------------------------------*/

/* The base head of event structure */
typedef struct
{
    MMI_EVT_PARAM_HEADER                        /* Event parameter header */
    SRV_CLOG_HANDLE handle;                     /* Handle who leads this change */
} srv_clog_evt_log_op_struct;

/*
 * Structure for event of notifying service is ready.
 * Application can show waiting screen before receive this event, the total number is dependent with the merge style,
 * if application has different style against the default one, application should create an instance and call
 * srv_clog_get_num_stat to get it 
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER                        /* Event parameter header */
    U8 sup_merge;                               /* Support merge or not, it's MMI_TRUE or MMI_FALSE now */
    U8 sup_thread;                              /* Support thread or not, t's MMI_TRUE or MMI_FALSE now, reserved for customization */
    U32 ur_mclt_num[SRV_CLOG_SIM_IDX_MAX_ITEM]; /* Unread missed call log type number per SIM card */
} srv_clog_evt_srv_ready_struct;

/*
 * Structure for event of notifying a new log is added.
 * Application should refresh its list to show this new logs, application should
 * first to check if this new log is the one it cares, if not, do nothing.
 * CallLogApp will answer for the refresh of IVOVN modules, so, IVOVN no need to care this event.
 * 
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER                        /* Event parameter header */
    SRV_CLOG_HANDLE handle;                     /* Handle who leads this change */
    srv_clog_add_log_ret_enum add_ret;          /* Add result type */
    srv_clog_log_identifier_struct new_idf;     /* Identity of new log added */
    srv_clog_log_identifier_struct old_idf;     /* Identity of old log deleted, it's invalid if add_ret is SRV_CLOG_ADD_LOG_RET_PURE_ADD */
} srv_clog_evt_add_log_struct;

/*
 * Structure for event of notifying a new log is updated.
 * Application need to refresh its screen to show the new updated data.
 * Application should first to check if the log id is some one it cares, if not, just do nothing.
 * 
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER                        /* Event parameter header */
    SRV_CLOG_HANDLE handle;                     /* Handle who leads this change */
    U32 fields;                                 /* Fields which are updated, please refer to srv_clog_log_field_enum  */
    srv_clog_log_struct log;                    /* Log data */
} srv_clog_evt_update_log_struct;

/* Structure for event of notifying all logs of specified type are updated */
typedef struct
{
    MMI_EVT_PARAM_HEADER                        /* Event parameter header */
    SRV_CLOG_HANDLE handle;                     /* Handle who leads this change */
    U32 fields;                                 /* Fields to update, please refer to srv_clog_log_field_enum  */
    srv_clog_log_identity_struct idt;           /* Identity */
} srv_clog_evt_update_all_struct;

/*
 * Structure for event of notifying a log is deleted.
 * Application needs to refresh its screen if it is using this log.
 * 
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER                        /* Event parameter header */
    SRV_CLOG_HANDLE handle;                     /* Handle who leads this change */
    srv_clog_log_identifier_struct idf;         /* Identifier */
} srv_clog_evt_del_log_struct;

/*
 * Structure for event of notifying all logs of specifically information are deleted.
 * Application needs to reload all log data.
 * 
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER                        /* Event parameter header */
    SRV_CLOG_HANDLE handle;                     /* Handle who leads this change */
    srv_clog_log_identity_struct idt;		    /* Identity of logs deleted */
} srv_clog_evt_del_all_struct;


/*----------------------------------------------------------------------------*/
/* Callback                                                                   */
/*----------------------------------------------------------------------------*/

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * 
 * FUNCTION
 *  SRV_CLOG_BASE_CB
 *
 * DESCRIPTION
 *  Base callback function type for call log service operation, can be used in blocking mode
 *
 *  or non-blocking mode. 
 * PARAMETERS
 *  handle :        [IN]     Instance handle, created by srv_clog_create.
 *  pid :           [IN]     Process id, must be unique, to identify this process, service will general an unique one and return it to caller if it's SRV_CLOG_INVALID_ELM.
 *  req_data :      [IN]     Request data, it's NULL commonly, it's the structure with the same name as the API, such as it's srv_clog_xxx_req_struct in srv_clog_xxx() API.
 *  cnf_data :      [IN]     Confirmation data, it's the structure with the same name as the API used, such as it's srv_clog_xxx_cnf_struct in srv_clog_xxx() mapping to srv_clog_xxx_req_struct.
 *  more :          [IN]     it's MMI_FALSE it can return all data in cnf_data field, or MMI_TRUE if can only return partial data in cnf_data and return next partial data in a async way.
 *  ret :           [IN]     Result code of this action
 *
 * RETURNS
 * srv_clog_ret_enum
 *
 * RETURN VALUES
 *  SRV_CLOG_RET_OK :        Indicate caller to call this callback function continually until finished in blocking or non-blocking mode
 *  SRV_CLOG_RET_STOP :      Indicate caller to stop next calling
 *  Others :                 Return error code and stop.
 *
 *****************************************************************************/
typedef S32(*SRV_CLOG_BASE_CB) (SRV_CLOG_HANDLE handle, S32 pid,
                                void *req_data, void *cnf_data, MMI_BOOL more, srv_clog_ret_enum ret);


/*----------------------------------------------------------------------------*/
/* Extern Function                                                            */
/*----------------------------------------------------------------------------*/

/*****************************************************************************
 * FUNCTION
 *  srv_clog_init_para
 *
 * DESCRIPTION
 *  To init the structure, it's strongly recommended to use this API to init 
 *  the structures used in one API instead of memset it simply, as it may set
 *  invalid PHB id with special non-zero value.
 * 
 * PARAMETERS
 *  para_type :        [IN] parameter type    
 *  para_data :        [IN] parameter data    
 *
 * RETURNS
 *  srv_clog_ret_enum
 *
 * RETURN VALUES
 *  < 0 :       error code, it's SRV_CLOG_RET_INVALID_PARAM
 *  0 :         Success
 *
 *****************************************************************************/
extern S32 srv_clog_init_para(srv_clog_para_enum para_type, void *para_data);


/*****************************************************************************
 * FUNCTION
 *  srv_clog_is_ready
 *
 * DESCRIPTION
 *  To check if service is ready, caller can not access service until service is ready.
 *  Please call this API before to access service forwardly in case thatcan not recieve
 *  CallLogSrv ready event.
 *
 * PARAMETERS
 *  void    
 *
 * RETURNS
 *  Return MMI_TRUE or MMI_FALSE, keep S32 return type for easy upgrade.
 *
 * RETURN VALUES
 *  MMI_TRUE :      ready 
 *  MMI_FALSE:      not ready
 *
 *****************************************************************************/
extern S32 srv_clog_is_ready(void);


/*****************************************************************************
 * FUNCTION
 *  srv_clog_create
 *
 * DESCRIPTION
 *  To create a service instance, it's strongly recommended to create an instance
 *  before access CallLogService, and it's also strongly recommended to create the
 *  instance in the time just want to use it and destroy it once not use it as only
 *  several instances supported at the same time and may be decreased in the future
 *  to save memory.
 *
 * PARAMETERS
 *  create :       [IN] Create data    
 *
 * RETURNS
 *  Return the error code
 *
 * RETURN VALUES
 *  > 0 :    Valid handler 
 *  0 :      Invalid handle, please check if it equal to SRV_CLOG_INVALID_ELM instead of comparing it with zero.
 *  < 0 :    Impossiable code
 *
 *****************************************************************************/
extern SRV_CLOG_HANDLE srv_clog_create(const srv_clog_create_struct *create);


/*****************************************************************************
 * FUNCTION
 *  srv_clog_destroy
 *
 * DESCRIPTION
 *  To destroy a service instance, it's strongly recommended to destroy the instance once not use it
 *  and can create it later if want to use it again as only several instances supported at the same time
 *  and may be decreased in the future to save memory. 
 *
 * PARAMETERS
 *  handle :        [IN] Instance handle to be destroyed    
 *
 * RETURNS
 *  Return the error code
 *
 * RETURN VALUES
 *  > 0 :       Impossible value 
 *  0 :         destroy success
 *  < 0 :       Error code
 *
 *****************************************************************************/
extern S32 srv_clog_destroy(SRV_CLOG_HANDLE handle);


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_user_data
 *
 * DESCRIPTION
 *  To get the user data of one instance, the caller can pass it's user data to 
 *  CallLogSrv to support multiple instance of itself easily. it's strongly 
 *  recommended to support multiple instance of one application from 10A.
 *
 * PARAMETERS
 *  handle :        [IN] Instance handle    
 *
 * RETURNS
 *  The user data of this instance 
 * RETURN VALUES
 *  NULL :      Return NULL if not set user data 
 *  !NULL :     Valid user data
 *
 *****************************************************************************/
extern void *srv_clog_get_user_data(SRV_CLOG_HANDLE handle);


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_unread_missed_call_num
 *
 * DESCRIPTION
 *  To get the number of the unread logs in blocking mode no matter merged or not. 
 *  It will return the total count of the unread logs from every SIM cards if 
 *  support multiple SIM cards, please refer to srv_clog_get_list_num_info if
 *  want to get the detail number information of different log type combination.
 *
 * PARAMETERS
 *  void    
 *
 * RETURNS
 *  Return unread number of missed call.
 *
 * RETURN VALUES
 *  >= 0 :      unread number 
 *  < 0 :       Impossible value
 *
 *****************************************************************************/
extern U32 srv_clog_get_unread_missed_call_num(void);


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_sim_unread_missed_call_num
 *
 * DESCRIPTION
 *  To get the number of the unread missed call log of each SIM card in blocking mode
 *  no matter the logs is merged or not. please refer to srv_clog_get_list_num_info if
 *  want to get the detail number information of different log type combination.
 *
 * PARAMETERS
 *  num_list :           [OUT]  The array list to store the unread numbers of missed call via each SIM card
 *  sim_num  :           [IN]   The SIM card number to get
 *
 * RETURNS
 *  Return unread number.
 *
 * RETURN VALUES
 *  > 0 :      Unread number of all SIM cards
 *  = 0 :      no any unread logs
 *
 *****************************************************************************/
extern U32 srv_clog_get_sim_unread_missed_call_num(U32 *num_list, U32 sim_num);


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_list_num_info
 *
 * DESCRIPTION
 *  To get the number statistics of all logs in blocking mode.
 *  If any field of identity is 0, it will discard it and return the total number
 *  of this field.
 *
 * PARAMETERS
 *  handle :         [IN]    Instance handle, can be invalid handle(SRV_CLOG_INVALID_ELM)
 *  identity :       [IN]    Identity to filter the data, can be NULL, if any field is 0, just discard it.
 *  num_info :       [OUT]   Number info, can not be NULL
 *
 * RETURNS
 *  srv_clog_ret_enum
 *
 * RETURN VALUES
 *  > 0 :       Impossible value
 *  0 :         Success
 *  < 0 :       Error code
 *
 *****************************************************************************/
extern S32 srv_clog_get_list_num_info(
            SRV_CLOG_HANDLE handle,
            const srv_clog_log_identity_struct *identity,
            srv_clog_num_info_struct *num_info);


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_list_log_ids
 *
 * DESCRIPTION
 *  To get the log id list in blocking mode. Application can first use this 
 *  function to get the log id list needed, then to get the detail info of every
 *  log by log_id field, application can call this function for more than one 
 *  time to get all log id list.
 *  Since it's a blocking process, it only peek log id list in memory in sync mode.
 *  Please note, if any identity field in req_data is 0, just skip it.
 *
 * PARAMETERS
 *  handle :         [IN]   Instance handle
 *  req_data :       [IN]   Request data information
 *  cnf_data :       [OUT]  confirmation data information
 *
 * RETURNS
 *  srv_clog_ret_enum
 *
 * RETURN VALUES
 *  > 0 :       Impossible value
 *  0 :         Success
 *  < 0 :       Error code
 *
 *****************************************************************************/
extern S32 srv_clog_get_list_log_ids(
            SRV_CLOG_HANDLE handle,
            const srv_clog_get_list_log_ids_req_struct *req_data,
            srv_clog_get_list_log_ids_cnf_struct *cnf_data);


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_list_log
 *
 * DESCRIPTION
 *  To get the log information of the specific log id in blocking mode.
 *
 * PARAMETERS
 *  handle :         [IN]   Instance handle
 *  req_data :       [IN]   Request data information
 *  cnf_data :       [OUT]  confirmation data information
 *
 * RETURNS
 *  srv_clog_ret_enum
 *
 * RETURN VALUES
 *  > 0 :       Impossible value
 *  0 :         Success
 *  < 0 :       Error code
 *
 *****************************************************************************/
extern S32 srv_clog_get_list_log(
            SRV_CLOG_HANDLE handle,
            const srv_clog_get_list_log_req_struct *req_data,
            srv_clog_get_list_log_cnf_struct *cnf_data);


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_log_by_id
 *
 * DESCRIPTION
 *  To get the log by log_id.
 *
 * PARAMETERS
 *  handle :       [IN]  handle
 *  log_id :       [IN]  log_id
 *  fields :       [IN]  Which fields to get, please refer to srv_clog_log_field_enum
 *  log    :       [OUT] log data
 *
 * RETURNS
 *  srv_clog_ret_enum
 *
 * RETURN VALUES
 *  > 0 :       Impossible value
 *  0 :         Success
 *  < 0 :       Error code
 *
 *****************************************************************************/
extern S32 srv_clog_get_log_by_id(SRV_CLOG_HANDLE handle, SRV_CLOG_ID log_id, U32 fields, srv_clog_log_struct *log);


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_last_log
 *
 * DESCRIPTION
 *  To get the last log with specific identity information. It's independent with
 *  the merge style and list style.
 *
 *   User: AP who needs to get the last log, Such as UcmSrv or Bluetooth, just to dial the last call again.
 *
 * PARAMETERS
 *  handle :         [IN]   Instance handle
 *  req_data :       [IN]   Request data
 *  cnf_data :       [OUT]  Confirmation data
 *
 * RETURNS
 *  srv_clog_ret_enum
 *
 * RETURN VALUES
 *  > 0 :       Impossible value
 *  0 :         Success
 *  < 0 :       Error code
 *
 *****************************************************************************/
extern S32 srv_clog_get_last_log(
            SRV_CLOG_HANDLE handle,
            const srv_clog_get_last_log_req_struct *req_data,
            srv_clog_get_last_log_cnf_struct *cnf_data);


/*****************************************************************************
 * FUNCTION
 *  srv_clog_add_log
 *
 * DESCRIPTION
 *  To add a new log, it is a non-blocking process.
 *
 *  User: AP who needs to log a new log, Such as UcmSrv.
 *
 * PARAMETERS
 *  handle :         [IN]   The instance handle, it can be NULL now
 *  pid :            [IN]   Process id, must be unique, to identify this process, service will general an unique one and return it to caller if it's SRV_CLOG_INVALID_ELM.
 *  req_data :       [IN]   Request data
 *  log_id :         [OUT]  Log id for quickly reference
 *  func_cb :        [IN]   Callback function to return the confirmation data, it uses srv_clog_add_log_cnf_struct as cnf_data.
 *
 * RETURNS
 *  srv_clog_ret_enum or process id
 *
 * RETURN VALUES
 *  > 0 :       Process id
 *  0 :         Impossible value
 *  < 0 :       Error code
 *
 *****************************************************************************/
extern S32 srv_clog_add_log(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            const srv_clog_add_log_req_struct *req_data,
            SRV_CLOG_ID *log_id,
            SRV_CLOG_BASE_CB func_cb);


/*****************************************************************************
 * FUNCTION
 *  srv_clog_log_call
 *
 * DESCRIPTION
 *  To log a new call, it is a non-blocking process.
 *
 *  User: AP who needs to log a new log, UcmSrv only now.
 *
 * PARAMETERS
 *  handle :         [IN]   The instance handle, it can be NULL now
 *  pid :            [IN]   Process id, must be unique, to identify this process, service will general an unique one and return it to caller if it's SRV_CLOG_INVALID_ELM.
 *  req_data :       [IN]   Request data
 *  log_id :         [OUT]  Log id for quickly reference
 *  func_cb :        [IN]   Callback function to return the confirmation data, it uses srv_clog_log_call_cnf_struct as cnf_data.
 *
 * RETURNS
 *  srv_clog_ret_enum or process id
 *
 * RETURN VALUES
 *  > 0 :       Process id
 *  0 :         Impossible value
 *  < 0 :       Error code
 *
 *****************************************************************************/
extern S32 srv_clog_log_call(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            const srv_clog_log_call_req_struct *req_data,
            SRV_CLOG_ID *log_id,
            SRV_CLOG_BASE_CB func_cb);


/*****************************************************************************
 * FUNCTION
 *  srv_clog_log_duration
 *
 * DESCRIPTION
 * To log the log duration, it is a non-blocking mode.
 * It's only used for UcmSrv, it will send event to CallLogApp to check if current
 * screen is Call Time screen or if is_call_done is TRUE, if so, it will save
 * call duration, or it will just return with ok.
 * 
 * User: AP who needs to change log duration frequently, UcmSrv only now.
 *
 * PARAMETERS
 *  handle :         [IN]   The instance handle, it can be NULL now
 *  pid :            [IN]   Process id, must be unique, to identify this process, service will general an unique one and return it to caller if it's SRV_CLOG_INVALID_ELM.
 *  req_data :       [IN]   Request data
 *  func_cb :        [IN]   Function callback to return the result, can be NULL, it uses srv_clog_log_duration_cnf_struct as cnf_data.
 *
 * RETURNS
 *  srv_clog_ret_enum or process id
 *
 * RETURN VALUES
 *  > 0 :       Process id
 *  0 :         Impossible value
 *  < 0 :       Error code
 *
 *****************************************************************************/
extern S32 srv_clog_log_duration(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            const srv_clog_log_duration_req_struct *req_data,
            SRV_CLOG_BASE_CB func_cb);


/*****************************************************************************
 * FUNCTION
 *  srv_clog_update_log
 *
 * DESCRIPTION
 *  To update a log, it is a non-blocking process.
 *
 * PARAMETERS
 *  handle :          [IN]   The instance handle
 *  pid :             [IN]   Process id, must be unique, to identify this process, service will general an unique one and return it to caller if it's SRV_CLOG_INVALID_ELM.
 *  req_data :        [IN]   Request data
 *  func_cb :         [IN]   Callback function to return the confirmation data, it uses srv_clog_update_log_cnf_struct as cnf_data.
 *
 * RETURNS
 *  srv_clog_ret_enum or process id
 *
 * RETURN VALUES
 *  > 0 :       Process id
 *  0 :         Impossible value
 *  < 0 :       Error code
 *
 *****************************************************************************/
extern S32 srv_clog_update_log(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            const srv_clog_update_log_req_struct *req_data,
            SRV_CLOG_BASE_CB func_cb);


/*****************************************************************************
 * FUNCTION
 *  srv_clog_update_all_logs
 *
 * DESCRIPTION
 *  To update all logs with specific fields, it is a non-blocking process.
 *  Only update read status for all logs now.
 *
 *  User: APs who show log list to user and need to update the read status for 
 *  all logs before show its list screen, such as CallLogApp, ShellApp-Recent call,
 *  ShellApp-Favorite contact, PHB-DS and so on. AP also needs to update the status icon
 *  in the callback function or in sync calling mode with this function.
 *
 * PARAMETERS
 *  handle :         [IN]   The instance handle
 *  pid :            [IN]   Process id, must be unique, to identify this process, service will general an unique one and return it to caller if it's SRV_CLOG_INVALID_ELM.
 *  req_data :       [IN]   Request data
 *  func_cb :        [IN]   Callback function to return the confirmation data, it uses srv_clog_update_all_logs_cnf_struct as cnf_data.
 *
 * RETURNS
 *  srv_clog_ret_enum or process id
 *
 * RETURN VALUES
 *  > 0 :       Process id
 *  0 :         Impossible value
 *  < 0 :       Error code
 *
 *****************************************************************************/
extern S32 srv_clog_update_all_logs(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            const srv_clog_update_all_logs_req_struct *req_data,
            SRV_CLOG_BASE_CB func_cb);


/*****************************************************************************
 * FUNCTION
 *  srv_clog_delete_log_by_id
 *
 * DESCRIPTION
 *  To delete a log, it is a non-blocking process.
 *
 * PARAMETERS
 *  handle :         [IN]   The instance handle
 *  pid :            [IN]   Process id, must be unique, to identify this process, service will general an unique one and return it to caller if it's SRV_CLOG_INVALID_ELM.
 *  log_id :         [IN]   Log id to delete
 *  func_cb :        [IN]   Callback function to return the confirmation data, it uses srv_clog_del_log_cnf_struct as cnf_data.
 *
 * RETURNS
 *  srv_clog_ret_enum or process id
 *
 * RETURN VALUES
 *  > 0 :       Process id
 *  0 :         Impossible value
 *  < 0 :       Error code
 *
 *****************************************************************************/
extern S32 srv_clog_delete_log_by_id(SRV_CLOG_HANDLE handle, S32 pid, SRV_CLOG_ID log_id, SRV_CLOG_BASE_CB func_cb);


/*****************************************************************************
 * FUNCTION
 *  srv_clog_delete_all_logs
 *
 * DESCRIPTION
 *  To delete all logs with specified type, it is a non-blocking process.
 *
 * PARAMETERS
 *  handle :         [IN]   The instance handle
 *  pid :            [IN]   Process id, must be unique, to identify this process, service will general an unique one and return it to caller if it's SRV_CLOG_INVALID_ELM.
 *  req_data :       [IN]   Request data
 *  func_cb :        [IN]   Callback function to return the confirmation data, it uses srv_clog_del_all_logs_cnf_struct as cnf_data.
 *
 * RETURNS
 *  srv_clog_ret_enum or process id
 *
 * RETURN VALUES
 *  > 0 :       Process id
 *  0 :         Impossible value
 *  < 0 :       Error code
 *
 *****************************************************************************/
extern S32 srv_clog_delete_all_logs(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            const srv_clog_del_all_logs_req_struct *req_data,
            SRV_CLOG_BASE_CB func_cb);


/* DOM-NOT_FOR_SDK-BEGIN */

#ifdef __MMI_CLOG_MARK_SEVERAL__
/*****************************************************************************
 * FUNCTION
 *  srv_clog_delete_multi_logs
 *
 * DESCRIPTION
 *  To delete multi logs with specified type and specified log_id, it is a non-blocking process.
 *  must set right SRV_CLOG_LOG_IDENTITY in req_data, becuase it only search log_id in this SRV_CLOG_LOG_IDENTITY.
 *
 * PARAMETERS
 *  handle :         [IN]   The instance handle
 *  pid :            [IN]   Process id, must be unique, to identify this process, service will general an unique one and return it to caller if it's SRV_CLOG_INVALID_ELM.
 *  req_data :       [IN]   Request data
 *  func_cb :        [IN]   Callback function to return the confirmation data, it uses srv_clog_del_multi_logs_cnf_struct as cnf_data.
 *
 * RETURNS
 *  srv_clog_ret_enum or process id
 *
 * RETURN VALUES
 *  > 0 :       Process id
 *  0 :         Impossible value
 *  < 0 :       Error code
 *
 *****************************************************************************/
extern S32 srv_clog_delete_multi_logs(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            const srv_clog_del_multi_logs_req_struct *req_data,
            SRV_CLOG_BASE_CB func_cb);
#endif /* __MMI_CLOG_MARK_SEVERAL__ */

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  srv_clog_search_list_log_ids
 *
 * DESCRIPTION
 *  To search multiple logs, it is a non-blocking process.
 * 
 *  User: AP who needs to search logs, such as ShellApp-Favorite contact.
 *  PHB-DialingSearch can also use it but better to get the cid BCD code by itself to speed it.
 *
 * PARAMETERS
 *  handle :         [IN]   The instance handle
 *  pid :            [IN]   Process id, must be unique, to identify this process, service will general an unique one and return it to caller if it's SRV_CLOG_INVALID_ELM.
 *  req_data :       [IN]   Request data
 *  func_cb :        [IN]   Callback function to return the confirmation data, it uses srv_clog_search_list_log_ids_cnf_struct as cnf_data.
 *
 * RETURNS
 *  srv_clog_ret_enum or process id
 *
 * RETURN VALUES
 *  > 0 :       Process id
 *  0 :         Impossible value
 *  < 0 :       Error code
 *
 *****************************************************************************/
extern S32 srv_clog_search_list_log_ids(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            const srv_clog_search_list_log_ids_req_struct *req_data,
            SRV_CLOG_BASE_CB func_cb);


/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  srv_clog_sat_refresh_hdlr
 *
 * DESCRIPTION
 *  To handle SAT refresh event in non-blocking mode.
 * 
 *  User: SatSrv.
 *
 * PARAMETERS
 *  sim_id :         [IN]   SIM id
 *  ef_file_idx :    [IN]   EF file index, only support FILE_LND_IDX now
 *
 * RETURNS
 *  srv_clog_ret_enum or process id
 *
 * RETURN VALUES
 *  > 0 :       Process id
 *  0 :         Impossible value
 *  < 0 :       Error code
 *
 *****************************************************************************/
extern S32 srv_clog_sat_refresh_hdlr(mmi_sim_enum sim_id, U16 ef_file_idx);


/*****************************************************************************
 * FUNCTION
 *  srv_clog_shutdown_hdlr
 *
 * DESCRIPTION
 *  Shutdown process, save call log back to SIM card. 
 *  pleaser please refer to ProcedureGprot.h of ShutDownSrv module.
 *  User: Shutdown AP in ShutdownFlow.c.
 *
 * PARAMETERS
 *  arg :           [IN]   Caller arg
 *  id_info :       [IN]   Procedure id info
 *
 * RETURNS
 *  mmi_frm_proc_result_enum 
 *
 * RETURN VALUES
 *  Result code
 *
 *****************************************************************************/
extern mmi_frm_proc_result_enum srv_clog_shutdown_hdlr(void *arg, const mmi_frm_proc_id_info_struct id_info);


#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_clog_phb_evt_hdlr
 *
 * DESCRIPTION
 *  To handle Phonebook event when to support PHB Sync feature.
 *
 * PARAMETERS
 *  evt :           [IN]   Event
 *
 * RETURNS
 *  MMI_RET_OK 
 *
 * RETURN VALUES
 *  MMI_RET_OK
 *
 *****************************************************************************/
extern MMI_RET srv_clog_phb_evt_hdlr(mmi_event_struct *evt);
#endif /* __MMI_CLOG_PHB_SYNC_SUPPORT__ */


/* DOM-NOT_FOR_SDK-END */

#ifdef __cplusplus
}
#endif 


#endif /* SRV_CALL_LOG_GPROT_H */ 




