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
 * ProvBoxAppIProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Provisioning Inbox UI main procedure.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef SRV_PROVBOX_SRV_IPROT_H
#define SRV_PROVBOX_SRV_IPROT_H

#include "MMI_features.h"

#ifdef __MMI_PROV_MESSAGE_SUPPORT__

/*----------------------------------------------------------------------------*/
/* include                                                                    */
/*----------------------------------------------------------------------------*/
#include "UMSrvDefs.h"
#include "MMIDataType.h"

#include "ProvBoxSrvGprot.h"

/*----------------------------------------------------------------------------*/
/* Macro configuration                                                     */
/*----------------------------------------------------------------------------*/
/* support List index data feature. */
#if defined (__MMI_PROV_IN_UM__) && defined(__UNIFIED_MESSAGE_LIST_INDEX_DATA__)
#define __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__
#endif

/* Sim id maybe is multi-sim_id, so the program should tranlate the multi-sim_id to vailable sim id
 * For example, _sim_ids = 0011, if _bit_idx = 1, 
 * so this marco is (0011) & (0010) ==> 0010. And please remember that 0001 ==> index = 0, 0010 =>
 * index = 1, 0100 => index = 2, 1000 => index = 3
 */
#define SRV_PROVBOX_GET_VAILD_SIM_ID(_sim_ids, _bit_idx)  ((_sim_ids) & (1 << (_bit_idx)))

#define SRV_PROVBOX_RESET_BIT_VALUE(_value, _bit_idx)   (_value) = (_value) & (~(1 << (_bit_idx)))

/*----------------------------------------------------------------------------*/
/* Constant configuration                                                     */
/*----------------------------------------------------------------------------*/
 /* Dependency: No change */
#define SRV_PROVBOX_PATH_MAX_BUFF_SIZE          ((SRV_PROVBOX_PATH_MAX_CHAR_LEN + 1) * ENCODING_LENGTH)

/* Dependency : No change */
#define SRV_PROVBOX_ADDR_MAX_BUFF_SIZE          ((SRV_PROVBOX_ADDR_MAX_CHAR_LEN + 1) * ENCODING_LENGTH)


#ifdef __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__
#define SRV_PROVBOX_SORT_ADDR_MAX_CHAR_LEN      SRV_UM_MAX_LIST_INDEX_LEN 
#endif

/*----------------------Max message number------------------------------------*/
/* Max message number in inbox, SRV_PROVBOX_UNLIMITED_NUM means unlimited */
#define SRV_PROVBOX_MAX_INBOX_MSG_NUM           CUSTOM_PROVBOX_MAX_INBOX_MSG_NUM    

/*----------------------Message operation number------------------------------*/

#if (CUSTOM_PROVBOX_MAX_MSG_NUM >= 100)

#define SRV_PROVBOX_MSG_LIST_INIT_SIZE          (100)   /* sizeof(void*) */
#define SRV_PROVBOX_MSG_LIST_INC_SIZE           (100)
#define SRV_PROVBOX_MSG_LIST_DEC_SIZE           (150)

#ifdef __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__
#define SRV_PROVBOX_MAX_GET_SORT_INFO_NUM       (40)    /* Limited by control buffer size */
#else
#define SRV_PROVBOX_MAX_GET_SORT_INFO_NUM       (50)    /* Limited by control buffer size */
#endif
#define SRV_PROVBOX_MAX_MULTI_OP_MSG_NUM        (50)    /* Limited by control buffer size */
#define SRV_PROVBOX_MAX_GET_LIST_INFO_NUM       (5)     /* Limited by control buffer size */

#else /* (CUSTOM_PROVBOX_MAX_MSG_NUM >= 100) */ 

#define SRV_PROVBOX_MSG_LIST_INIT_SIZE          (15)
#define SRV_PROVBOX_MSG_LIST_INC_SIZE           (20)
#define SRV_PROVBOX_MSG_LIST_DEC_SIZE           (30)

#ifdef __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__
#define SRV_PROVBOX_MAX_GET_SORT_INFO_NUM       (25)    /* Limited by control buffer size */
#else
#define SRV_PROVBOX_MAX_GET_SORT_INFO_NUM       (50)    /* Limited by control buffer size */
#endif /* __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__ */

#define SRV_PROVBOX_MAX_MULTI_OP_MSG_NUM        (15)    /* Limited by control buffer size */
#define SRV_PROVBOX_MAX_GET_LIST_INFO_NUM       (5)     /* Limited by control buffer size */

#endif /* (CUSTOM_PROVBOX_MAX_MSG_NUM >= 100) */ 


#ifdef __MMI_PROV_IN_UM__

#if SRV_PROVBOX_MAX_GET_SORT_INFO_NUM > SRV_UM_MAX_GET_MSG_LIST_NUMBER  /* UM may enlarge GET_LIST structure size */
#undef  SRV_PROVBOX_MAX_GET_SORT_INFO_NUM
#define SRV_PROVBOX_MAX_GET_SORT_INFO_NUM       SRV_UM_MAX_GET_MSG_LIST_NUMBER
#endif 

#if SRV_PROVBOX_MAX_GET_LIST_INFO_NUM > SRV_UM_MAX_GET_MSG_INFO_NUMBER /* UM may enlarge GET_MSG_INFO structure size */
#undef SRV_PROVBOX_MAX_GET_LIST_INFO_NUM      
#define SRV_PROVBOX_MAX_GET_LIST_INFO_NUM       SRV_UM_MAX_GET_MSG_INFO_NUMBER
#endif

#endif /* __MMI_PROV_IN_UM__ */

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/
typedef enum
{
    SRV_PROVBOX_DEL_ALL_MSG_MODE_UNDEFINED,
    SRV_PROVBOX_DEL_ALL_MSG_MODE_RESET,
    SRV_PROVBOX_DEL_ALL_MSG_MODE_DELETABLE,
    SRV_PROVBOX_DEL_ALL_MSG_MODE_FOR_EACH,
    SRV_PROVBOX_DEL_ALL_MSG_MODE_MAX_ITEM
} srv_provbox_del_all_msg_mode_enum;

/* Provisionining message sort type */
typedef enum
{
    SRV_PROVBOX_MSG_SORT_TYPE_MSG_ID,           /* Sort message by message id, it's the same order as by receiving order. */
    SRV_PROVBOX_MSG_SORT_TYPE_TIMESTAMP,        /* Sort message by the receive local time, please note that the local time may be change by user. */
    SRV_PROVBOX_MSG_SORT_TYPE_MSG_SIZE,         /* Sort message by message body size */
    SRV_PROVBOX_MSG_SORT_TYPE_MSG_TYPE,         /* Sort message by message type */
    SRV_PROVBOX_MSG_SORT_TYPE_ADDRESS,          /* Sort message by message address string */
    SRV_PROVBOX_MSG_SORT_TYPE_READ_STATUS,      /* Sort message by read status */
    SRV_PROVBOX_MSG_SORT_TYPE_MAX_ITEM          /* Max item */
} srv_provbox_msg_sort_type_enum;

/* Message order type */
typedef enum
{
    SRV_PROVBOX_ORDER_TYPE_SEQUENCE,            /* By sequence */
    SRV_PROVBOX_ORDER_TYPE_RANDOM,              /* By random */
    SRV_PROVBOX_ORDER_TYPE_MAX_ITEM             /* Max item */
}srv_provbox_order_type_enum;

/* Message operation */
typedef enum
{
    SRV_PROVBOX_MSG_OP_NONE,                    /* No any operation */
    SRV_PROVBOX_MSG_OP_DELETE,                  /* Delete operation: to delete one or more messages */
    SRV_PROVBOX_MSG_OP_MOVE_TO_ARCHIVE,         /* Move to archive: to move one or more message to archive */
    SRV_PROVBOX_MSG_OP_READ_PROPERTY,           /* Read property: to read property of one message */
    SRV_PROVBOX_MSG_OP_MAX_ITEM
} srv_provbox_msg_op_enum;

/*----------------------------------------------------------------------------*/
/* Base structure                                                             */
/*----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/
/*------------------Struct: provide message information: ProvBoxApp API--------------------*/
typedef struct
{
    U8 sim_id;                                                                   /* SIM id, please refer to mmi_sim_enum */
    srv_provbox_box_type_enum box_type;                                          /* Box type */
    U16 req_msg_num;                                                             /* Message number */
    U32 msg_id[SRV_PROVBOX_MAX_GET_LIST_INFO_NUM];                               /* Message number */
    srv_provbox_msg_cmn_info_struct cmn_info[SRV_PROVBOX_MAX_GET_LIST_INFO_NUM]; /* Common information */ 
    S16 msg_size_list[SRV_PROVBOX_MAX_GET_LIST_INFO_NUM];                        /* Message size list */
    U16 rsp_msg_num;
    srv_provbox_result_enum op_result[SRV_PROVBOX_MAX_GET_LIST_INFO_NUM];                       /* KAL_TRUE means OK; KAL_FALSE means failed */
} srv_provbox_msg_info_struct;

typedef struct
{
    U8 sim_id;                                  /* SIM id, please refer to mmi_sim_enum */
    srv_provbox_box_type_enum box_type;         /* Box type */
    U32 start_idx;                              /* Start message index */
    U16 msg_num;                                /* Message number */
    srv_provbox_msg_cmn_info_struct cmn_info[SRV_PROVBOX_MAX_GET_LIST_INFO_NUM];    /* Common information */ 
    S16 msg_size_list[SRV_PROVBOX_MAX_GET_LIST_INFO_NUM];       /* Message size list */
    U32 next_start_idx;                         /* Next start index */
    U32 hdlr_msg_num;
    srv_provbox_result_enum result;             /* Result code */
} srv_provbox_list_info_struct;

typedef struct
{
    U32 more;                               /* Left number of messages not deleted */
    srv_provbox_box_type_enum box_type;         /* Box type */
    srv_provbox_del_all_msg_mode_enum del_all_type;
	mmi_sim_enum sim_id;
    srv_provbox_result_enum result;             /* Result code */
} srv_provbox_msg_delete_all_struct;

typedef struct
{
    srv_provbox_box_type_enum box_type;         /* Box type Input */
    srv_provbox_msg_op_enum op;                 /* Message operation Input */    
    U16 msg_num;                                /* Message number Input */
    U32 msg_id[SRV_PROVBOX_MAX_MULTI_OP_MSG_NUM];       /* Message id list input */
    U16 op_result[SRV_PROVBOX_MAX_MULTI_OP_MSG_NUM];    /* Result code list output */
} srv_provbox_msg_multi_op_struct;

/*------------------- Event: provide message information: ProvBoxApp--------------------*/
typedef struct
{
    SRV_PROVBOX_EVT_HEADER                      /* Event parameter head */
    srv_provbox_msg_cmn_info_struct cmn_info;   /* Common information */
} srv_provbox_evt_new_msg_ind_struct;

#ifdef __MMI_PROV_IN_UM__

typedef struct
{
    SRV_PROVBOX_EVT_HEADER                      /* Event parameter head */
    srv_provbox_msg_cmn_info_struct * msg_info; /* Common information */
    srv_um_msg_info_struct *um_msg_info;
} srv_provbox_evt_msg_info_struct;


typedef struct
{
    SRV_PROVBOX_EVT_HEADER                      /* Event parameter head */
    U8 list_idx_type;                           /* const; sort type */
    S16 msg_size;                               /* const; msg size */
    srv_um_list_idx_data_union *list_data;      /* input value */
    srv_provbox_msg_cmn_info_struct* msg_info;  /* const; msg common information */                             
} srv_provbox_evt_sort_info_struct;


typedef struct
{
    SRV_PROVBOX_EVT_HEADER                       /* Event parameter head */
    srv_um_detail_field_enum um_detail_field;    /* const; um request the field of message detail */
    S16 msg_size;                                /* const; message size */
    U32 um_user_data;                            /* const; um user data from um request privitime message */
    srv_provbox_msg_cmn_info_struct *info;       /* const; to provide message information */
    srv_um_traverse_func um_traverse_callback;   /* const; um traverse callback fucntion to get msg detail */
    S32 traverse_ret;
} srv_provbox_evt_msg_detail_struct;

typedef struct
{
    SRV_PROVBOX_EVT_HEADER                            /* Event parameter head */
    srv_provbox_callback_func um_set_ready_callback;
    srv_provbox_result_enum   set_ready_result;
} srv_provbox_evt_msg_msg_ready_struct;

#endif /* __MMI_PROV_IN_UM__ */


/*----------------------------------------------------------------------------*/
/* API declarations                                                           */
/*----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  srv_provbox_is_ready 
 * DESCRIPTION
 *  Check if provbox service is ready
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL srv_provbox_is_ready(void);

/*****************************************************************************
 * FUNCTION
 *    srv_provbox_send_um_refresh_ind 
 * DESCRIPTION
 *    To send refresh ind event to um.
 * PARAMETERS
 *    srv_um_refresh_enum      [IN]       refresh enum
 *    U32                      [IN]       message id
 *    void*                    [IN]       user data
 * RETURNS
 *    void
 *****************************************************************************/


#ifdef __MMI_PROV_IN_UM__

extern void srv_provbox_send_um_refresh_ind(
                srv_um_refresh_enum type, 
                U32 msg_id, void* user_data);

/*****************************************************************************
 * FUNCTION
 *    srv_provbox_sim_pbox2um 
 * DESCRIPTION
 *    Pbox sim id to UM sim id.
 * PARAMETERS
 *    prov_box_sim             [IN]       PBox sim id
 * RETURNS
 *    UM sim id
 *****************************************************************************/
srv_um_sim_enum srv_provbox_sim_pbox2um(mmi_sim_enum prov_box_sim);

/*****************************************************************************
 * FUNCTION
 *    srv_provbox_addr_type_pbox2um 
 * DESCRIPTION
 *    
 * PARAMETERS
 *    provbox_type             [IN]       PBox address type
 * RETURNS
 *    
 *****************************************************************************/
extern srv_um_addr_enum srv_provbox_addr_type_pbox2um(srv_provbox_addr_type_enum provbox_type);


/*****************************************************************************
 * FUNCTION
 *    srv_provbox_read_status_pbox2um 
 * DESCRIPTION
 *    
 * PARAMETERS
 *    read_status             [IN]       PBox read status
 * RETURNS
 *    
 *****************************************************************************/
extern MMI_BOOL srv_provbox_read_status_pbox2um(srv_provbox_msg_read_status_enum read_status);

#endif /* __MMI_PROV_IN_UM__ */



/*****************************************************************************
 * FUNCTION
 *    srv_provbox_get_msg_num 
 * DESCRIPTION
 *    To provide the number of provisioning message.
 * PARAMETERS
 *    srv_provbox_box_type_enum  [IN]    message type enum
 * RETURNS
 *    U32
 *****************************************************************************/
extern U32 srv_provbox_get_msg_num(srv_provbox_box_type_enum box_type);

/*****************************************************************************
 * FUNCTION
 *    srv_provbox_get_new_msg_id 
 * DESCRIPTION
 *    To provide the new message id.
 * PARAMETERS
 *    void
 * RETURNS
 *    U32
 *****************************************************************************/
extern U32 srv_provbox_get_new_msg_id(void);

/*****************************************************************************
 * FUNCTION
 *    srv_provbox_is_full 
 * DESCRIPTION
 *    To check if the provisioning box is full.
 * PARAMETERS
 *    void
 * RETURNS
 *    MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_provbox_is_full(void);

/*****************************************************************************
 * FUNCTION
 *    srv_provbox_get_msg_sim_id 
 * DESCRIPTION
 *    To get the sim id of special provisioning message.
 * PARAMETERS
 *    U32       [IN]   message id
 * RETURNS
 *    mmi_sim_enum
 *****************************************************************************/
extern mmi_sim_enum srv_provbox_get_msg_sim_id(U32 msg_id);

/*****************************************************************************
 * FUNCTION
 *    srv_provbox_get_msg_id_by_idx 
 * DESCRIPTION
 *    To get message id by the index of list menu and message box type.
 * PARAMETERS
 *    U32                          [IN]   the index of list menu
 *    srv_provbox_box_type_enum    [IN]   the box type of message
 *    U32*                         [OUT]  message id
 * RETURNS
 *    srv_provbox_result_enum
 *****************************************************************************/
extern srv_provbox_result_enum srv_provbox_get_msg_id_by_idx(
                                   U32 msg_idx, 
                                   srv_provbox_box_type_enum box_type, 
                                   U32 *msg_id);

/*****************************************************************************
 * FUNCTION
 *    srv_provbox_get_list_info 
 * DESCRIPTION
 *    To get list info of provisioning message.
 * PARAMETERS
 *    srv_provbox_list_info_struct*  [IN]
 * RETURNS
 *    void
 *****************************************************************************/
extern void srv_provbox_get_list_info(srv_provbox_list_info_struct *list_info);

/*****************************************************************************
 * FUNCTION
 *    srv_provbox_msg_get_properties 
 * DESCRIPTION
 *    To get properties of provisioning message.
 * PARAMETERS
 *    srv_provbox_msg_properties_struct*  [IN]
 * RETURNS
 *    srv_provbox_result_enum
 *****************************************************************************/
extern srv_provbox_result_enum srv_provbox_msg_get_properties(
                                   srv_provbox_msg_properties_struct *data);


/*****************************************************************************
 * FUNCTION
 *    srv_provbox_set_msg_status 
 * DESCRIPTION
 *    
 * PARAMETERS
 *    
 * RETURNS
 *    srv_provbox_result_enum
 *****************************************************************************/
extern srv_provbox_result_enum srv_provbox_set_msg_status(U32 msg_id, srv_provbox_msg_read_status_enum status);



/*****************************************************************************
 * FUNCTION
 *    srv_provbox_msg_delete 
 * DESCRIPTION
 *    To delete provisioning message.
 * PARAMETERS
 *    U32  [IN]
 * RETURNS
 *    srv_provbox_result_enum
 *****************************************************************************/
extern srv_provbox_result_enum srv_provbox_msg_delete(U32 msg_id);

/*****************************************************************************
 * FUNCTION
 *    srv_provbox_msg_delete_all 
 * DESCRIPTION
 *    To delete all provisioning message.
 * PARAMETERS
 *    srv_provbox_msg_delete_all_struct*  [IN]
 * RETURNS
 *    srv_provbox_result_enum
 *****************************************************************************/
extern srv_provbox_result_enum srv_provbox_msg_delete_all(srv_provbox_msg_delete_all_struct *data);

/*****************************************************************************
 * FUNCTION
 *    srv_provbox_msg_delete_all 
 * DESCRIPTION
 *    To delete all provisioning message.
 * PARAMETERS
 *    srv_provbox_msg_delete_all_struct*  [IN]
 * RETURNS
 *    srv_provbox_result_enum
 *****************************************************************************/
extern srv_provbox_result_enum srv_provbox_msg_multi_op_hdlr(srv_provbox_msg_multi_op_struct *data);

#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */

#endif /* SRV_PROVBOX_SRV_IPROT_H */
