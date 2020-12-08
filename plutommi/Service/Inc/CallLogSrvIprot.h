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
 *  CallLogSrvIprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef SRV_CALL_LOG_IPROT_H
#define SRV_CALL_LOG_IPROT_H

/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_features.h"

#include "kal_general_types.h"

#include "MMIDataType.h"

#include "CallLogSrvGprot.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/

/*-------------- Style (Max 10 bits for 1 style )-----------------------------*/

/* Bit mask position for merge style */
#define SRV_CLOG_STYLE_MERGE_POS                    (0)
/* Bit mask group of merge style, this group is used to indicate the merge style supported */
#define SRV_CLOG_STYLE_MERGE_GRP                    (0x03FF << SRV_CLOG_STYLE_MERGE_POS)
/* Free or consecutive, decide how to stop */
#define SRV_CLOG_STYLE_MERGE_CONSECUTIVE            (0x0001 << SRV_CLOG_STYLE_MERGE_POS)
/* If merge in same category or not, if not, can merge SMS call together */
#define SRV_CLOG_STYLE_MERGE_IN_CATE                (0x0002 << SRV_CLOG_STYLE_MERGE_POS)
/* if merge in same SIM id or not */
#define SRV_CLOG_STYLE_MERGE_IN_SIM_ID              (0x0004 << SRV_CLOG_STYLE_MERGE_POS)
/* If merge in same log type or not */
#define SRV_CLOG_STYLE_MERGE_IN_LOG_TYPE            (0x0008 << SRV_CLOG_STYLE_MERGE_POS)
/* If merge in same sub type or not */
#define SRV_CLOG_STYLE_MERGE_IN_SUB_TYPE            (0x0010 << SRV_CLOG_STYLE_MERGE_POS)
/* decide how to filter */
#define SRV_CLOG_STYLE_MERGE_IN_TYPE                                                 \
                    (SRV_CLOG_STYLE_MERGE_IN_CATE | SRV_CLOG_STYLE_MERGE_IN_SIM_ID | \
                     SRV_CLOG_STYLE_MERGE_IN_LOG_TYPE | SRV_CLOG_STYLE_MERGE_IN_SUB_TYPE)

/* If keep detail or not, decide how many levels */
#define SRV_CLOG_STYLE_MERGE_THREAD                 (0x0020 << SRV_CLOG_STYLE_MERGE_POS)
/* If check PHB or not, if same number, check PHB id, decide how to merge */
#define SRV_CLOG_STYLE_MERGE_BY_PHB_ID              (0x0040 << SRV_CLOG_STYLE_MERGE_POS) 
/* If merge style by number */
#define SRV_CLOG_STYLE_MERGE_BY_NUM                 (0x0080 << SRV_CLOG_STYLE_MERGE_POS)
/* if merge by name or not */
#define SRV_CLOG_STYLE_MERGE_BY_NAME                (0x0100 << SRV_CLOG_STYLE_MERGE_POS)
/* Bit number of merge style */
#define SRV_CLOG_STYLE_MERGE_BIT_NUM                (10)

/* Bit mask position of number style */
#define SRV_CLOG_STYLE_NUM_POS                      (10)
/* Bit mask group of Log number, this group is used to indicate how to handle number limitations */
#define SRV_CLOG_STYLE_NUM_GRP                      (0x0007 << SRV_CLOG_STYLE_NUM_POS)
/* The number of all call logs has special limitation, if not, it's the count of others */
#define SRV_CLOG_STYLE_NUM_TOTAL_LIMITED            (0x0001 << SRV_CLOG_STYLE_NUM_POS)
/* The number of call log from each SIM has special limitations, if not, it's the count of others */
#define SRV_CLOG_STYLE_NUM_SIM_LIMITED              (0x0002 << SRV_CLOG_STYLE_NUM_POS)
/* The number of each call type has special limitations, if not,  */
#define SRV_CLOG_STYLE_NUM_TYPE_LIMITED             (0x0004 << SRV_CLOG_STYLE_NUM_POS)
/* Bit number of log number style */
#define SRV_CLOG_STYLE_NUM_BIT_NUM                  (3)


/* Bit mask position of sync style */
#define SRV_CLOG_STYLE_SIM_SYNC_POS                 (10 + 3)
/* Bit mask group of SIM sync style , this group is used to indicate the SIM sync style */
#define SRV_CLOG_STYLE_SIM_SYNC_GRP                 (0x007F << SRV_CLOG_STYLE_SIM_SYNC_POS)
/* If read LND from SIM card to phone storage when power one */
#define SRV_CLOG_STYLE_SIM_SYNC_READ                (0x0001 << SRV_CLOG_STYLE_SIM_SYNC_POS )
/* If write LND from phone storage to SIM card when power off */
#define SRV_CLOG_STYLE_SIM_SYNC_WRITE               (0x0002 << SRV_CLOG_STYLE_SIM_SYNC_POS)
/* If force to sync LND between SIM card and phone storage on every power on/off time */
#define SRV_CLOG_STYLE_SIM_SYNC_FORCE_SYNC          (0x0004 << SRV_CLOG_STYLE_SIM_SYNC_POS)
/* If handle SIM refresh event, should reload sim log and delete all NVRAM data */
#define SRV_CLOG_STYLE_SIM_SYNC_CMN_REFRESH         (0x0008 << SRV_CLOG_STYLE_SIM_SYNC_POS)
/* If handle SIM changed event, if sync sim when SAT refresh  */
#define SRV_CLOG_STYLE_SIM_SYNC_SAT_REFRESH         (0x0010 << SRV_CLOG_STYLE_SIM_SYNC_POS)
/* If still keep those call log on phone  */
#define SRV_CLOG_STYLE_SIM_SYNC_CLEAR_OLD           (0x0020 << SRV_CLOG_STYLE_SIM_SYNC_POS)
/* If sync by type or by SIM, if by type, the old call log of same type will be deleted,
   this flag can only work with SRV_CLOG_STYLE_SIM_SYNC_DROP_OLD together */
#define SRV_CLOG_STYLE_SIM_SYNC_CLEAR_OLD_BY_TYPE   (0x0040 << SRV_CLOG_STYLE_SIM_SYNC_POS)
/* Bit number of SIM sync style */
#define SRV_CLOG_STYLE_SIM_BIT_NUM                  (7)

/* Bit mask position of PHB sync style */
#define SRV_CLOG_STYLE_PHB_SYNC_POS                 (10 + 3 + 7)
/* Bit mask group of PHB sync style */
#define SRV_CLOG_STYLE_PHB_SYNC_GRP                 (0x07 << SRV_CLOG_STYLE_PHB_SYNC_POS)
/* If sync call log when add a phb entry */
#define SRV_CLOG_STYLE_PHB_SYNC_ADD                 (0x01 << SRV_CLOG_STYLE_PHB_SYNC_POS)
/* If sync call log when delete a phb entry */
#define SRV_CLOG_STYLE_PHB_SYNC_DELETE              (0x02 << SRV_CLOG_STYLE_PHB_SYNC_POS)
/* If sync call log when update a phb entry */
#define SRV_CLOG_STYLE_PHB_SYNC_UPDATE              (0x04 << SRV_CLOG_STYLE_PHB_SYNC_POS)
/* Bit number of PHB sync style */
#define SRV_CLOG_STYLE_PHB_SYNC_NUM                 (3)

/* Bit mask position of base sort style */
#define SRV_CLOG_STYLE_BASE_SORT_POS                (10 + 3 + 7 + 3)
/* Bit mask group of base sort style*/
#define SRV_CLOG_STYLE_BASE_SORT_GRP                (0x03 << SRV_CLOG_STYLE_BASE_SORT_POS)
/* If sort call log by timestamp, if not, sort call log by the adding order, Reserved for extention  */
#define SRV_CLOG_STYLE_BASE_SORT_BY_TIMESTAMP       (0x01 << SRV_CLOG_STYLE_BASE_SORT_POS)
/* If sort callog in ascending order, if not, in descending order, Reserved for extention */
#define SRV_CLOG_STYLE_BASE_SORT_ASCENDING          (0x02 << SRV_CLOG_STYLE_BASE_SORT_POS)
/* Bit number of base sort style*/
#define SRV_CLOG_STYLE_BASE_SORT_NUM                (2)

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/* Styles supported */
typedef enum
{
    SRV_CLOG_STYLE_TYPE_DEF_BASE = 0,       /* Style base */
    SRV_CLOG_STYLE_TYPE_MERGE = 0,          /* Style type for merging, styles less than 100 is reserved for internal used */
    SRV_CLOG_STYLE_TYPE_NUM,                /* Style for log number */
    SRV_CLOG_STYLE_TYPE_SIM_SYNC,           /* SIM sync operation */
    SRV_CLOG_STYLE_TYPE_PHB_SYNC,           /* PHB sync operation */
    SRV_CLOG_STYLE_TYPE_BASE_SORT,          /* Common sort style */

    // SRV_CLOG_STYLE_TYPE_NAME,            /* Name style 2 name or 1 name */
    SRV_CLOG_STYLE_TYPE_FILTER,             /* Filter style, reserved for extention */
    SRV_CLOG_STYLE_TYPE_FILTER_ADV,         /* Advance filter style, reserved for extention  */
    SRV_CLOG_STYLE_TYPE_SORT_ADV,           /* Advance sort style, reserved for extention  */
    SRV_CLOG_STYLE_TYPE_DEF_MAX_ITEM        /* Max item */
} srv_clog_def_style_type_enum;

/* Service base styles range */
typedef enum
{
    SRV_CLOG_STYLE_TYPE_BASE = 100,         /* Base value */
    SRV_CLOG_STYLE_TYPE_MAX_ITEM            /* Max item */
} srv_clog_style_type_enum;

/*Common sort methods, Reserved for extention */
typedef enum
{
    SRV_CLOG_SORT_BY_LOG_ID /*= 0x01 */,         /* Sort logs by log_id in absolute time */
    SRV_CLOG_SORT_BY_TIMESTAMP /* = 0x02 */,      /* Sort logs by timestamp in local time */
    SRV_CLOG_SORT_MAX_ITEM                  /* Max item */
} srv_clog_sort_enum;

/* Field of indexing sorting, Reserved for extention */
typedef enum
{
    SRV_CLOG_IDX_FIELD_LOG_ID,              /* Log id field */
    SRV_CLOG_IDX_FIELD_TIMSTAMP,            /* Timestamp field */
    SRV_CLOG_IDX_FIELD_MAX_ITEM             /* Max item */
} srv_clog_idx_field_enum;

/* Indexing direction, Reserved for extention */
typedef enum
{
    SRV_CLOG_DIRECTOIN_UNCLASSIFIED,        /* Unclassified direction */
    SRV_CLOG_DIRECTION_DESCENDING,          /* Descending direction */
    SRV_CLOG_DIRECTION_ASCENDING,           /* Ascending direction */
    SRV_CLOG_DIRECTION_MAX_ITEM             /* Max item */
} srv_clog_direction_enum;

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*****************************************************************************
 * FUNCTION
 *  srv_clog_init
 * DESCRIPTION
 *  To initialize the call log service, it initializes the service context and 
 *  related components. Service is still not ready now yet.
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 * HLD
 * init context; init related components; set state = INIT;
 *****************************************************************************/
extern MMI_RET srv_clog_init(mmi_event_struct *evt);

/*****************************************************************************
 * FUNCTION
 *  srv_clog_set_def_style
 * DESCRIPTION
 *  To set the selected styles, for example, if want to merge the same type 
 *  consecutive call logs, this function needs to be called to set this specific
 *  style, service shall merges and sorts the logs according to the required style.
 *  this function may be wrapped with different compile options to cater different
 *  requirements.
 * PARAMETERS
 *  type :           [IN] The style type
 *  style :          [IN] The style to set, a value or a bit mask group which depends on the type field, if style = 0, just to clear this style type
 *  data :           [IN] data to set, if used depends on the type field.                     
 *   
 * RETURNS
 *  srv_clog_ret_enum
 * RETURN VALUES
 *  Pos. value:     Process identifier
 *  0:              Impossible value
 *  Neg. value:     Error code
 *  void
 * EXAMPLE
 * <code>
 * srv_clog_sort_tbl_struct sort_tbl = { 0 };
 *
 * srv_clog_set_def_style(SRV_CLOG_STYLE_MERGE, 
 *                         SRV_CLOG_STYLE_MERGE_BY_TYPE | SRV_CLOG_STYPE_MERGE_CONSECUTIVE, NULL);
 * srv_clog_set_def_style(SRV_CLOG_STYPE_SORT, 0, (void*)&sort_tbl);
 * </code>
 * HLD
 *  use a flag to indicate if new flag is set and not apply, then apply the style in
 *  srv_clog_start;
 *****************************************************************************/
extern S32 srv_clog_set_def_style(U32 type, U32 style, void *data);

/*****************************************************************************
 * FUNCTION
 *  srv_clog_set_def_style
 * DESCRIPTION
 *  To get default style
 *  requirements.
 * PARAMETERS
 *  type :           [IN] The style type
 *  style :          [IN] The style to set, a value or a bit mask group which depends on the type field, if style = 0, just to clear this style type
 *  data :           [IN] data to set, if used depends on the type field.                     
 *   
 * RETURNS
 *  srv_clog_ret_enum
 * RETURN VALUES
 *  Pos. value:     Process identifier
 *  0:              Impossible value
 *  Neg. value:     Error code
 *  void
 *****************************************************************************/
extern S32 srv_clog_get_def_style(U32 type, U32 *style, void **data);

/*****************************************************************************
 * FUNCTION
 *  srv_clog_start
 * DESCRIPTION
 *  To start the service. It loads log data from SIM and NVRAM, fill internal
 *  data pool, prepare log list for application to get, after all is done, service
 *  enter ready state and emits EVT_ID_SRV_CLOG_STATE_NOTIFY to application,
 *  application can not get log data from service only recieve this event with 
 *  READY state. <p />
 *  It only check if the styles are changed and apply new styles if already started.<p />
 *  Since it's a non-blocking process, application need to receive EVT_ID_SRV_CLOG_STATE_NOTIFY
 *  to see if it's done.
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern S32 srv_clog_start(void);


/*----------------------------------------------------------------------------*/
/* GPRS count                                                                 */
/*----------------------------------------------------------------------------*/
#ifdef __MMI_CLOG_GPRS_COUNT__

/* Bit mask of the fields in srv_clog_gprs_data_struct */
typedef enum
{
    SRV_CLOG_GPRS_FIELD_LAST_SENT = 0x01,   /* Last sent */
    SRV_CLOG_GPRS_FIELD_LAST_RECVED = 0x02, /* Last received */
    SRV_CLOG_GPRS_FIELD_LAST_TIME = 0x04,   /* Last time */
    SRV_CLOG_GPRS_FIELD_LAST_ALL = 0x07,    /* last all bit mask group */

    SRV_CLOG_GPRS_FIELD_TOTAL_SENT = 0x10,  /* Total sent */
    SRV_CLOG_GPRS_FIELD_TOTAL_RECVED = 0x20,/* Total recieved */
    SRV_CLOG_GPRS_FIELD_TOTAL_TIME = 0x40,  /* Total time */
    SRV_CLOG_GPRS_FIELD_TOTAL_ALL = 0x70,   /* Total all field bit mask group */
    SRV_CLOG_GPRS_FIELD_ALL = 0xFF,         /* All fields bit mask group */
    SRV_CLOG_GPRS_FIELD_MAX_ITEM            /* Max item */
} srv_clog_gprs_field_enum;

/* Structure for GPRS counter */
typedef struct
{
    U64 last_sent;                          /* Last sent */
    U64 last_recved;                        /* Last received */
    U64 last_time;                          /* Last time */

    U64 total_sent;                         /* Total sent */
    U64 total_recved;                       /* Total received */
    U64 total_time;                         /* Total time */
} srv_clog_gprs_data_struct;

/* Structure for getting GPRS counter */
typedef struct
{
    mmi_sim_enum sim_id;                    /* SIM id */
} srv_clog_gprs_get_req_struct;

/* Structure for resetting GPRS counter */
typedef struct
{
    mmi_sim_enum sim_id;                    /* SIM id */
    U32 fields;                             /* Fields bit mask group */
} srv_clog_gprs_reset_req_struct;

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  SRV_CLOG_GPRS_GET_DATA_CB
 * DESCRIPTION
 *  To get gprs count data.
 * PARAMETERS
 *  data type :        [IN] Get request dat
 *  gprs_data :       [IN] GPRS data
 *  ret :           [IN] Return code
 * RETURNS
 *  srv_clog_ret_enum
 *****************************************************************************/
typedef S32(*SRV_CLOG_GPRS_GET_DATA_CB) (void *user_data,
                                         srv_clog_gprs_get_req_struct *req_data,
                                         const srv_clog_gprs_data_struct *gprs_data,
                                         MMI_BOOL more, srv_clog_ret_enum ret);

/*****************************************************************************
* <GROUP  CallBackFunctions>
* FUNCTION
 *  SRV_CLOG_GPRS_RESET_DATA_CB
 * DESCRIPTION
 *  To get gprs count data.
 * PARAMETERS
 *  get_data:    [IN] Get data 
 *  ret :        [IN] Return code
 * RETURNS
 *  srv_clog_ret_enum
 *****************************************************************************/
typedef S32(*SRV_CLOG_GPRS_RESET_DATA_CB) (void *user_data,
                                           srv_clog_gprs_reset_req_struct *req_data,
                                           MMI_BOOL more, srv_clog_ret_enum ret);

/*****************************************************************************
 * FUNCTION
 *  srv_clog_gprs_get_data
 * DESCRIPTION
 *  To get gprs count data.
 * PARAMETERS
 *  req_data :       [IN] Get request
 *  user_data :       [IN] User data
 *  func_cb :         [IN] Callback function
 * RETURNS
 *  srv_clog_ret_enum
 *****************************************************************************/
extern S32 srv_clog_gprs_get_data(
            const srv_clog_gprs_get_req_struct *req_data,
            const void *user_data,
            SRV_CLOG_GPRS_GET_DATA_CB func_cb);

/*****************************************************************************
 * FUNCTION
 *  srv_clog_gprs_reset_data
 * DESCRIPTION
 *  To reset gprs count data.
 * PARAMETERS
 *  req_data :        [IN] Reset request
 *  user_data :         [IN] User data
 *  func_cb :           [IN] Callback function
 * RETURNS
 *  srv_clog_ret_enum
 *****************************************************************************/
extern S32 srv_clog_gprs_reset_data(
            const srv_clog_gprs_reset_req_struct *req_data,
            const void *user_data,
            SRV_CLOG_GPRS_RESET_DATA_CB func_cb);

#endif /* __MMI_CLOG_GPRS_COUNT__ */

/*----------------------------------------------------------------------------*/
/* Call time                                                                  */
/*----------------------------------------------------------------------------*/
#ifdef __MMI_CLOG_CALL_TIME__

/* Call time operator type */
typedef enum
{
    SRV_CLOG_CTIME_OP_TYPE_SINGLE,              /* To get a single data accumulated with different types */ 
    SRV_CLOG_CTIME_OP_TYPE_MULTI,               /* To get multiple data for different types */
    SRV_CLOG_CTIME_OP_TYPE_MAX_ITEM
}srv_clog_ctime_op_type_enum;

/* Bit mask of the fields in srv_clog_ctime_data_struct */
typedef enum
{
    SRV_CLOG_CTIME_FIELD_LAST_DIALED = 0x0001,  /* Last sent  */
    SRV_CLOG_CTIME_FIELD_LAST_RECVED = 0x0002,  /* Last received  */
    SRV_CLOG_CTIME_FIELD_LAST_ALL = 0x000F,     /* Last all  */

    SRV_CLOG_CTIME_FIELD_TOTAL_DIALED = 0x0010, /* Total sent */
    SRV_CLOG_CTIME_FIELD_TOTAL_RECVED = 0x0020, /* Total received */
    SRV_CLOG_CTIME_FIELD_TOTAL_ALL = 0x00F0,    /* Total all */
    SRV_CLOG_CTIME_FIELD_LIFE = 0x001F,          /* Life fields */
    SRV_CLOG_CTIME_FIELD_ALL = 0x00FF,          /* All common fields */
    SRV_CLOG_CTIME_FIELD_MAX_ITEM               /* Max item */
} srv_clog_ctime_field_enum;

/* Structure for call time */
typedef struct
{
    mmi_sim_enum sim_id;                    /* SIM id */
    srv_clog_call_type_enum call_type;      /* Call type */
    srv_clog_clt_enum last_type;            /* Last call time type saved, it's srv_clog_clt_enum */
    U32 last_dialed;                        /* Last sent time */
    U32 last_recved;                        /* Last received time */
    U32 total_dialed;                       /* Total sent time */
    U32 total_recved;                       /* Total received time */
    U32 life;                               /* Life time from ex-factory */
} srv_clog_ctime_data_struct;

/*****************************************************************************
 * FUNCTION
 *  srv_clog_ctime_get_data
 * DESCRIPTION
 *  To get call time data.
 * PARAMETERS
 *  sim_id :          [IN] SIM id
 *  call_type :       [IN] Call type, only VoIP and NON_VoIP supported
 *  data :            [OUT] Data buffer
 *  data_num :        [OUT] The number of data to get, the array size of data parameter
 * RETURNS
 *  srv_clog_ret_enum
 *****************************************************************************/
extern S32 srv_clog_ctime_get_data(
            mmi_sim_enum sim_id,
            srv_clog_call_type_enum call_type,
            srv_clog_ctime_op_type_enum op_type,
            srv_clog_ctime_data_struct *data,
            U32 data_num);

/*****************************************************************************
 * FUNCTION
 *  srv_clog_ctime_reset_data
 * DESCRIPTION
 *  To get call time data.
 * PARAMETERS
 *  sim_id :          [IN] SIM id
 *  call_type :       [IN] Call type, only VoIP and NON_VoIP supported
 *  fields :          [OUT]Bit mask group of fields to reset
 * RETURNS
 *  srv_clog_ret_enum
 *****************************************************************************/
extern S32 srv_clog_ctime_reset_data(mmi_sim_enum sim_id, srv_clog_call_type_enum call_type, U32 fields);

#endif /* __MMI_CLOG_CALL_TIME__ */


/*----------------------------------------------------------------------------*/
/* Call cost                                                                  */
/*----------------------------------------------------------------------------*/
#ifdef __MMI_CLOG_CALL_COST__

/* The max pin code size include zero end char */
#define SRV_CLOG_CCOST_MAX_PIN_SIZE         (MAX_SIM_PASSWD_LEN)

/* The max char length of call cost currency string */
#define SRV_CLOG_CCOST_MAX_CURRENCY_LEN     (4)
/* The max char length of call cost PPU string */
#define SRV_CLOG_CCOST_MAX_PPU_LEN          (20)

/* Bit mask of the fields in srv_clog_ccost_data_struct */
typedef enum
{
    SRV_CLOG_CCOST_FIELD_LAST = 0x01,       /* Last */
    SRV_CLOG_CCOST_FIELD_TOTAL = 0x02,      /* Total */
    SRV_CLOG_CCOST_FIELD_MAX = 0x04,        /* Max */
    SRV_CLOG_CCOST_FIELD_PPU = 0x10,        /* PPU name */
    SRV_CLOG_CCOST_FIELD_CURRENCY = 0x20,   /* Currency name */
    SRV_CLOG_CCOST_FIELD_PUC = SRV_CLOG_CCOST_FIELD_PPU | SRV_CLOG_CCOST_FIELD_CURRENCY,    /* Bit mask group of PPU name and currency name */
    SRV_CLOG_CCOST_FIELD_ALL_RESET = SRV_CLOG_CCOST_FIELD_TOTAL | SRV_CLOG_CCOST_FIELD_MAX | SRV_CLOG_CCOST_FIELD_PUC, /* Bit mask group of all fields can be reset */
    SRV_CLOG_CCOST_FIELD_ALL = SRV_CLOG_CCOST_FIELD_LAST | SRV_CLOG_CCOST_FIELD_ALL_RESET, /* Bit mask group of all fields, reset last is reserved for extention */
    SRV_CLOG_CCOST_FIELD_MAX_ITEM
} srv_clog_ccost_field_enum;

/* Structure for call cost */
typedef struct
{
    U32 last;                               /* Last */
    U32 total;                              /* total cost */
    U32 max;                                /* Max */

    // double ppu_value;                                    /* PPU value */
    WCHAR ppu[SRV_CLOG_CCOST_MAX_PPU_LEN + 1];              /* PPU name */
    WCHAR currency[SRV_CLOG_CCOST_MAX_CURRENCY_LEN + 1];    /* Currency */
} srv_clog_ccost_data_struct;

/*****************************************************************************
* <GROUP  CallBackFunctions>
 * FUNCTION
 *  SRV_CLOG_CCOST_GET_CB
 * DESCRIPTION
 *  To get call cost data.
 * PARAMETERS
 *  sim_id :         [IN] SIM id
 *  fields :         [IN] Bit mask of fields to get
 *  data :           [OUT] Data buffer
 *  more :           [OUT] If more data to get in next callback
 *  ret :            [OUT] Result code
 * RETURNS
 *  srv_clog_ret_enum
 *****************************************************************************/
typedef S32(*SRV_CLOG_CCOST_GET_CB) (void *user_data, mmi_sim_enum sim_id, U32 fields,
                                     const srv_clog_ccost_data_struct *data, MMI_BOOL more, srv_clog_ret_enum ret);

/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_get_data
 * DESCRIPTION
 *  To get call cost data.
 * PARAMETERS
 *  sim_id :          [IN] SIM id
 *  fields :          [OUT]Bit mask group of fields to reset
 *  user_data :       [IN] User data
 *  func_cb :       	[IN] Function callback to return the data
 * RETURNS
 *  srv_clog_ret_enum
 *****************************************************************************/
extern S32 srv_clog_ccost_get_data(
            mmi_sim_enum sim_id,
            U32 fields,
            const void *user_data,
            SRV_CLOG_CCOST_GET_CB func_cb);

/*****************************************************************************
* <GROUP  CallBackFunctions>
 * FUNCTION
 *  SRV_CLOG_CCOST_SET_CB
 * DESCRIPTION
 *  To set call cost data.
 * PARAMETERS
 *  user_data :      [IN] User data
 *  sim_id :         [IN] SIM id
 *  fields :         [IN] Fields bit group to set
 *  ret :            [IN] Result code
 * RETURNS
 *  srv_clog_ret_enum
 *****************************************************************************/
typedef S32(*SRV_CLOG_CCOST_SET_CB) (void *user_data, mmi_sim_enum sim_id, U32 fields, srv_clog_ret_enum ret);

/*****************************************************************************
 * FUNCTION
 *  srv_clog_ccost_set_data
 * DESCRIPTION
 *  To set call cost data.
 * PARAMETERS
 *  sim_id :          [IN] SIM id, can only be mmi_sim_enum, can not be bit group
 *  fields :          [OUT]Bit mask group of fields to reset
 *  data :       	  [IN] User data
 *  pin :       	  [IN] PIN code
 *  user_data :       [IN] User data
 *  func_cb :         [IN] Function callback to return the data
 * RETURNS
 *  srv_clog_ret_enum
 *****************************************************************************/
extern S32 srv_clog_ccost_set_data(
            mmi_sim_enum sim_id,
            U32 fields,
            const srv_clog_ccost_data_struct *data,
            const WCHAR *pin,
            const void *user_data,
            SRV_CLOG_CCOST_SET_CB func_cb);


#endif /* __MMI_CLOG_CALL_COST__ */
/*----------------------------------------------------------------------------*/
/* End                                                                        */
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif 


#endif /* SRV_CALL_LOG_IPROT_H */ 

