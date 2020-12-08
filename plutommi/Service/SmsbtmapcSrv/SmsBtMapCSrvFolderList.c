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
 *  SmsFolderListSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service Folder List Hanlder
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MOD_SMSAL__
/**************************************************************
* Header Files Include
**************************************************************/
#include "SmsSrvGprot.h"
#include "SmsBtmapcSrvGprot.h"
#include "SmsBtmapCSrvStorage.h"
#include "SmsBtmapCSrvUtil.h"
#include "MMI_trc_Int.h"
#include "MMI_common_app_trc.h"
#include "mmi_rp_srv_sms_btmapc_def.h"
#ifdef __SRV_SMS_BTMAPC__

/**************************************************************
* MARCO
**************************************************************/
#define SRV_SMS_BTMAPC_FISRT_BOX_TYPE          SRV_SMS_BTMAPC_BOX_INBOX
#define SRV_SMS_BTMAPC_MAX_MSG_BITMAP_SIZE     ((SRV_SMS_BTMAPC_MAX_SMS_ENTRY + 7) / 8)



/**************************************************************
* Global Variables Declaration
**************************************************************/ 
typedef struct
{
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_del_list_cntx_struct;

typedef struct
{
    srv_sms_storage_enum dest_storage;
    MMI_BOOL flag;
    U16 curr_msg_id;
    U16 msg_num;
    U8 *msg_bitmap;
    U16 *msg_id_list;
    U16 *msg_list_size;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_move_copy_list_cntx_struct;


/**************************************************************
* Extern Function Declaration
**************************************************************/


/**************************************************************
* Static Variables Defination
**************************************************************/
static U16 srv_sms_btmapc_inbox_size;
static U16 srv_sms_btmapc_outbox_size;
static U16 srv_sms_btmapc_drafts_size;
static U16 srv_sms_btmapc_deleted_size;
static U16 srv_sms_btmapc_unsent_size;

static U16 srv_sms_btmapc_inbox_list[SRV_SMS_BTMAPC_MAX_SMS_ENTRY];
static U16 srv_sms_btmapc_outbox_list[SRV_SMS_BTMAPC_MAX_SMS_ENTRY];
static U16 srv_sms_btmapc_drafts_list[SRV_SMS_BTMAPC_MAX_SMS_ENTRY];
static U16 srv_sms_btmapc_deleted_list[SRV_SMS_BTMAPC_MAX_SMS_ENTRY];
static U16 srv_sms_btmapc_unsent_list[SRV_SMS_BTMAPC_MAX_SMS_ENTRY];

/**************************************************************
* Static Function Declaration
**************************************************************/
static MMI_BOOL srv_sms_btmapc_list_sms_event_handler(srv_sms_event_struct *event_data);
static void srv_sms_btmapc_list_create_folder(void);
static MMI_BOOL srv_sms_btmapc_is_folder_list_support(srv_sms_btmapc_box_enum msg_box_type);
static void srv_sms_btmapc_list_reset_folder(void);
static void srv_sms_btmapc_list_set_msg_change_event(void);
static void srv_sms_btmapc_list_clear_msg_change_event(void);
static void srv_sms_btmapc_list_add_event_handler(srv_sms_event_add_struct *event_info);
static void srv_sms_btmapc_list_del_event_handler(srv_sms_event_delete_struct *event_info);
static void srv_sms_btmapc_list_update_event_handler(srv_sms_event_update_struct *event_info);
static MMI_BOOL srv_sms_btmapc_get_list_and_size(
                    U16 **msg_id_list,
                    U16 *msg_list_size,
                    srv_sms_btmapc_box_enum msg_box_type);

static U16 srv_sms_btmapc_get_list_and_size_pointer(
                U16 **msg_id_list,
                U16 **msg_list_size,
                srv_sms_btmapc_box_enum msg_box_type);

static void srv_sms_btmapc_delete_msg_list_callback(srv_sms_callback_struct *callback_data);
static void srv_sms_btmapc_create_list(srv_sms_btmapc_box_enum msg_box_type);
static void srv_sms_btmapc_get_list_query_data(
                srv_sms_query_struct *query_data,
                srv_sms_btmapc_box_enum msg_box_type);


/**************************************************************
* Function Defination
**************************************************************/
void srv_sms_btmapc_list_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LIST_INIT);

    srv_sms_btmapc_list_reset_folder();
    
    srv_sms_btmapc_list_create_folder();
    srv_sms_btmapc_list_set_msg_change_event();
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_unread_sms_num
 * DESCRIPTION
 *  Get Unread Message's number
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 srv_sms_btmapc_get_unread_sms_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < srv_sms_btmapc_inbox_size; i++)
    {
        U16 msg_id = srv_sms_btmapc_inbox_list[i];
        srv_sms_status_enum status;

        status = srv_sms_btmapc_get_msg_status(msg_id);
    
        if (status & SRV_SMS_STATUS_UNREAD)
        {
            count++;
        }
    }

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_unread_sim_sms_num
 * DESCRIPTION
 *  Get Unread SIM Box Message's number
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_id
 * DESCRIPTION
 *  Get message ID of the message in the box list
 * PARAMETERS
 *  msg_box_type    [IN]        Message Box List Type
 *  list_index      [IN]        The position of message in the Box List
 * RETURNS
 *  U16
 *****************************************************************************/
U16 srv_sms_btmapc_get_msg_id(srv_sms_btmapc_box_enum msg_box_type, U16 list_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_id = SRV_SMS_INVALID_MSG_ID;
    U16 *msg_id_list = NULL;
    U16 msg_list_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_btmapc_get_list_and_size(&msg_id_list, &msg_list_size, msg_box_type))
    {
        if (list_index < msg_list_size)
        {
            msg_id = msg_id_list[list_index];
        }
    }

    return msg_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_list_size
 * DESCRIPTION
 *  Get number of the messages in a box list
 * PARAMETERS
 *  msg_box_type    [IN]        Message Box List Type
 * RETURNS
 *  U16
 *****************************************************************************/
U16 srv_sms_btmapc_get_list_size(srv_sms_btmapc_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_list_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_box_type)
    {
        case SRV_SMS_BTMAPC_BOX_INBOX:
            msg_list_size = srv_sms_btmapc_inbox_size;
            break;

        case SRV_SMS_BTMAPC_BOX_OUTBOX:
            msg_list_size = srv_sms_btmapc_outbox_size;
            break;

        case SRV_SMS_BTMAPC_BOX_DRAFTS:
            msg_list_size = srv_sms_btmapc_drafts_size;
            break;

        case SRV_SMS_BTMAPC_BOX_UNSENT:
            msg_list_size = srv_sms_btmapc_unsent_size;
            break;

        default:
            break;
    }

    return msg_list_size;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_list_type
 * DESCRIPTION
 *  Get a message(with specific status, storage tpye, folder type)'s Box the Box List Type
 * PARAMETERS
 *  status          [IN]        Message Status
 *  storage_type    [IN]        Storage Type
 *  folder_id       [IN]        Folder Type
 * RETURNS
 *  srv_sms_box_enum
 *****************************************************************************/
srv_sms_btmapc_box_enum srv_sms_btmapc_get_list_type(
                    srv_sms_status_enum status,
                    srv_sms_storage_enum storage_type,
                    srv_sms_folder_enum folder_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_box_enum msg_box_type = SRV_SMS_BTMAPC_BOX_RESERVED;
    U32 temp_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_LIST_TYPE, status, storage_type, folder_id);
    /* Remove other Flag (Unsupported Flag) */
    temp_status = status & (~SRV_SMS_STATUS_UNSUPPORTED);

    switch (temp_status)
    {
        case SRV_SMS_STATUS_UNREAD:
        case SRV_SMS_STATUS_READ:
            msg_box_type = SRV_SMS_BTMAPC_BOX_INBOX;
            break;

        case SRV_SMS_STATUS_DRAFT:
            msg_box_type = SRV_SMS_BTMAPC_BOX_DRAFTS;
            break;

        case SRV_SMS_STATUS_SENT:
            msg_box_type = SRV_SMS_BTMAPC_BOX_OUTBOX;
            break;

        case SRV_SMS_STATUS_UNSENT:
            msg_box_type = SRV_SMS_BTMAPC_BOX_UNSENT;
            break;

        default:
            msg_box_type = SRV_SMS_BTMAPC_BOX_NONE;
            break;
    }

    return msg_box_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_list_index
 * DESCRIPTION
 *  Get position (list index) and box list type of the message
 * PARAMETERS
 *  msg_box_type    [OUT]       Message Box List type
 *  msg_id          [IN]        Message ID
 * RETURNS
 *  U16
 *****************************************************************************/
U16 srv_sms_btmapc_get_msg_list_index(srv_sms_btmapc_box_enum* msg_box_type, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *msg_id_list;
    U16 *msg_list_size;
    U16 list_index = SRV_SMS_INVALID_LIST_INDEX;
    srv_sms_btmapc_box_enum curr_box_type = SRV_SMS_BTMAPC_FISRT_BOX_TYPE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_LIST_INDEX, msg_id);
    *msg_box_type = SRV_SMS_BTMAPC_BOX_NONE;
    
    while (curr_box_type < SRV_SMS_BTMAPC_BOX_RESERVED)
    {
        if (srv_sms_btmapc_is_folder_list_support(curr_box_type) == MMI_TRUE)
        {
            U16 i;

            srv_sms_btmapc_get_list_and_size_pointer(&msg_id_list, &msg_list_size, curr_box_type);

            for (i = 0; i < *msg_list_size; i++)
            {
                if (msg_id_list[i] == msg_id)
                {
                    *msg_box_type = curr_box_type;
                    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_LIST_INDEX_1, *msg_box_type, i);
                    return i;
                }
            }
        }
        curr_box_type <<= 1;
    }
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_LIST_INDEX_1, *msg_box_type, list_index);
    return list_index;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_msg_list
 * DESCRIPTION
 *  1. Delete all of the messages in the Message Box List.
 *  2. The Callback Action Data Structure is srv_sms_delete_msg_list_cb_struct.
 * PARAMETERS
 *  msg_box_type    [IN]        Message Box List Type
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_delete_msg_list(
        srv_sms_btmapc_box_enum msg_box_type,
        srv_sms_sim_enum sim_id,
        SrvSmsCallbackFunc callback_func,
        void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_del_list_cntx_struct *del_list_cntx;
    U8 *msg_bitmap;
    U16 *msg_id_list;
    U16 *msg_list_size;
    srv_sms_btmapc_box_enum curr_box_type = SRV_SMS_BTMAPC_FISRT_BOX_TYPE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_MSG_LIST, msg_box_type);

    msg_bitmap = (U8 *)OslMalloc(SRV_SMS_BTMAPC_MAX_MSG_BITMAP_SIZE);

    memset(msg_bitmap, 0, SRV_SMS_BTMAPC_MAX_MSG_BITMAP_SIZE);

    while (curr_box_type < SRV_SMS_BTMAPC_BOX_RESERVED)
    {
        if ((msg_box_type & curr_box_type) && 
            (srv_sms_btmapc_is_folder_list_support(curr_box_type) == MMI_TRUE))
        {
            U16 i;

            srv_sms_btmapc_get_list_and_size_pointer(&msg_id_list, &msg_list_size, curr_box_type);

            for (i = 0; i < *msg_list_size; i++)
            {
                U16 msg_id = msg_id_list[i];
                srv_sms_btmapc_set_bitmap_index(msg_id, msg_bitmap);
            }
        }

        curr_box_type <<= 1;
    }

    del_list_cntx = (srv_sms_del_list_cntx_struct *)OslMalloc(sizeof(srv_sms_del_list_cntx_struct));

    del_list_cntx->callback_func = callback_func;
    del_list_cntx->user_data = user_data;

    srv_sms_btmapc_delete_msg_bitmap(
        msg_bitmap,
        SRV_SMS_BTMAPC_MAX_MSG_BITMAP_SIZE,
        srv_sms_btmapc_delete_msg_list_callback,
        del_list_cntx);

    OslMfree(msg_bitmap);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_msg_list_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_btmapc_delete_msg_list_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_delete_msg_list_cb_struct del_list_cb_data;
    srv_sms_delete_msg_bitmap_cb_struct *del_bitmap_cb_data;
    srv_sms_del_list_cntx_struct *del_list_cntx;
    SrvSmsCallbackFunc callback_func;
    void *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_MSG_LIST_CALLBACK, callback_data->result);

    del_list_cntx = (srv_sms_del_list_cntx_struct*)callback_data->user_data;
    del_bitmap_cb_data = (srv_sms_delete_msg_bitmap_cb_struct*)callback_data->action_data;

    callback_func = del_list_cntx->callback_func;
    user_data = del_list_cntx->user_data;

    del_list_cb_data.deleted_msg_num = del_bitmap_cb_data->deleted_num;

    OslMfree(del_list_cntx);

    srv_sms_btmapc_callback(
        SRV_SMS_ACTION_DELETE,
        callback_data->result,
        callback_data->cause,
        &del_list_cb_data,
        user_data,
        callback_func);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_list_sms_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_sms_btmapc_list_sms_event_handler(srv_sms_event_struct *event_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LIST_SMS_EVENT_HANDLER, event_data->evt_id);

    switch (event_data->evt_id)
    {
        case EVT_ID_SRV_SMS_BTMAPC_READY:
        {
            srv_sms_event_sms_ready_struct *event_info;

            event_info = (srv_sms_event_sms_ready_struct*)event_data->event_info;

            if (event_info->is_sms_ready)
            {
                srv_sms_btmapc_list_create_folder();
                srv_sms_btmapc_list_set_msg_change_event();
            }
            else
            {
                srv_sms_btmapc_list_reset_folder();
                srv_sms_btmapc_list_clear_msg_change_event();
            }
            break;
        }

        case EVT_ID_SRV_SMS_BTMAPC_ADD_MSG:
        {
            srv_sms_event_add_struct *event_info;

            event_info = (srv_sms_event_add_struct *)event_data->event_info;
    
            srv_sms_btmapc_list_add_event_handler(event_info);
            break;
        }

        case EVT_ID_SRV_SMS_BTMAPC_DEL_MSG:
        {
            srv_sms_event_delete_struct *event_info;

            event_info = (srv_sms_event_delete_struct *)event_data->event_info;

            srv_sms_btmapc_list_del_event_handler(event_info);
            break;
        }

        case EVT_ID_SRV_SMS_BTMAPC_UPDATE_MSG:
        {
            srv_sms_event_update_struct *event_info;

            event_info = (srv_sms_event_update_struct *)event_data->event_info;

            srv_sms_btmapc_list_update_event_handler(event_info);
            break;
        }

        default:
            break;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_list_create_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_btmapc_list_create_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_box_type = SRV_SMS_BTMAPC_FISRT_BOX_TYPE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((msg_box_type < SRV_SMS_BTMAPC_BOX_RESERVED) && 
           srv_sms_btmapc_is_folder_list_support((srv_sms_btmapc_box_enum)msg_box_type))
    {
        srv_sms_btmapc_create_list((srv_sms_btmapc_box_enum)msg_box_type);

        msg_box_type = msg_box_type << 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_folder_list_support
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_sms_btmapc_is_folder_list_support(srv_sms_btmapc_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_IS_FOLDER_LIST_SUPPORT, msg_box_type);

    switch (msg_box_type)
    {
        case SRV_SMS_BTMAPC_BOX_INBOX:
        case SRV_SMS_BTMAPC_BOX_OUTBOX:
        case SRV_SMS_BTMAPC_BOX_DRAFTS:
        case SRV_SMS_BTMAPC_BOX_UNSENT:
            result = MMI_TRUE;
            break;

        default:
            result = MMI_FALSE;
            break;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_list_reset_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_btmapc_list_reset_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LIST_RESET_FOLDER);

    srv_sms_btmapc_inbox_size = 0;
    srv_sms_btmapc_outbox_size = 0;
    srv_sms_btmapc_drafts_size = 0;
    srv_sms_btmapc_unsent_size = 0;
    srv_sms_btmapc_deleted_size = 0;
        
    memset(srv_sms_btmapc_inbox_list, 0xFF, sizeof(U16) * SRV_SMS_BTMAPC_MAX_SMS_ENTRY);
    memset(srv_sms_btmapc_outbox_list, 0xFF, sizeof(U16) * SRV_SMS_BTMAPC_MAX_SMS_ENTRY);
    memset(srv_sms_btmapc_drafts_list, 0xFF, sizeof(U16) * SRV_SMS_BTMAPC_MAX_SMS_ENTRY);
    memset(srv_sms_btmapc_unsent_list, 0xFF, sizeof(U16) * SRV_SMS_BTMAPC_MAX_SMS_ENTRY);
    memset(srv_sms_btmapc_deleted_list, 0xFF, sizeof(U16) * SRV_SMS_BTMAPC_MAX_SMS_ENTRY);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_list_set_msg_change_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_btmapc_list_set_msg_change_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LIST_SET_MSG_CHANGE_EVENT);
    srv_sms_btmapc_set_interrupt_event_handler(EVT_ID_SRV_SMS_BTMAPC_READY, srv_sms_btmapc_list_sms_event_handler, NULL);
    srv_sms_btmapc_set_interrupt_event_handler(EVT_ID_SRV_SMS_BTMAPC_ADD_MSG, srv_sms_btmapc_list_sms_event_handler, NULL);
    srv_sms_btmapc_set_interrupt_event_handler(EVT_ID_SRV_SMS_BTMAPC_DEL_MSG, srv_sms_btmapc_list_sms_event_handler, NULL);
    srv_sms_btmapc_set_interrupt_event_handler(EVT_ID_SRV_SMS_BTMAPC_UPDATE_MSG, srv_sms_btmapc_list_sms_event_handler, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_list_clear_msg_change_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_btmapc_list_clear_msg_change_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LIST_CLEAR_MSG_CHANGE_EVENT);
    srv_sms_btmapc_clear_interrupt_event_handler(EVT_ID_SRV_SMS_BTMAPC_READY, srv_sms_btmapc_list_sms_event_handler, NULL);
    srv_sms_btmapc_clear_interrupt_event_handler(EVT_ID_SRV_SMS_BTMAPC_ADD_MSG, srv_sms_btmapc_list_sms_event_handler, NULL);
    srv_sms_btmapc_clear_interrupt_event_handler(EVT_ID_SRV_SMS_BTMAPC_DEL_MSG, srv_sms_btmapc_list_sms_event_handler, NULL);
    srv_sms_btmapc_clear_interrupt_event_handler(EVT_ID_SRV_SMS_BTMAPC_UPDATE_MSG, srv_sms_btmapc_list_sms_event_handler, NULL);
}



/*****************************************************************************
 * FUNCTION
 *  srv_sms_exec_interrupt_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_btmapc_list_add_event_handler(srv_sms_event_add_struct *event_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 add_msg_id = event_info->msg_id;
    srv_sms_msg_info_struct *msg_info = &event_info->msg_info;
    srv_sms_btmapc_box_enum msg_box_type;
    U16 *msg_id_list = NULL;
    U16 *msg_list_size = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LIST_ADD_EVENT_HANDLER, event_info);

    msg_box_type = srv_sms_btmapc_get_list_type(
                    msg_info->status,
                    msg_info->storage_type,
                    msg_info->folder_id);

    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LIST_ADD_EVENT_HANDLER_1, msg_box_type);

    srv_sms_btmapc_get_list_and_size_pointer(
        &msg_id_list,
        &msg_list_size,
        msg_box_type);

    if (msg_id_list != NULL)
    {
        U16 curr_msg_num;
        U16 max_msg_num = SRV_SMS_BTMAPC_MAX_SMS_ENTRY;
        MMI_BOOL result;

        curr_msg_num = *msg_list_size;

        result = srv_sms_btmapc_add_msg_into_list(
                    msg_id_list,
                    curr_msg_num,
                    max_msg_num,
                    add_msg_id,
                    SRV_SMS_SORT_TIMESTAMP,
                    SRV_SMS_ORDER_DEFAULT);

        if (result == MMI_TRUE)
        {
            (*msg_list_size)++;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_exec_interrupt_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_btmapc_list_del_event_handler(srv_sms_event_delete_struct *event_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 del_msg_id = event_info->msg_id;
    srv_sms_msg_info_struct *msg_info = &event_info->msg_info;
    srv_sms_btmapc_box_enum msg_box_type;
    U16 *msg_id_list = NULL;
    U16 *msg_list_size = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LIST_DEL_EVENT_HANDLER, event_info);

    msg_box_type = srv_sms_btmapc_get_list_type(
                    msg_info->status,
                    msg_info->storage_type,
                    msg_info->folder_id);

    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LIST_DEL_EVENT_HANDLER_1, msg_box_type);

    srv_sms_btmapc_get_list_and_size_pointer(
        &msg_id_list,
        &msg_list_size,
        msg_box_type);

    if (msg_id_list != NULL)
    {
        U16 curr_msg_num;
        MMI_BOOL result;

        curr_msg_num = *msg_list_size;

        result = srv_sms_btmapc_delete_msg_from_list(msg_id_list, curr_msg_num, del_msg_id);

        if (result == MMI_TRUE)
        {
            (*msg_list_size)--;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_list_update_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_btmapc_list_update_event_handler(srv_sms_event_update_struct *event_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 update_msg_id = event_info->msg_id;
    srv_sms_msg_info_struct *old_msg_info = &event_info->old_msg_info;
    srv_sms_msg_info_struct *new_msg_info = &event_info->new_msg_info;
    srv_sms_btmapc_box_enum src_box_type;
    srv_sms_btmapc_box_enum dest_box_type;
    U16 *src_msg_id_list = NULL;
    U16 *src_msg_list_size;
    U16 *dest_msg_id_list = NULL;
    U16 *dest_msg_list_size;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LIST_UPDATE_EVENT_HANDLER, event_info);

    src_box_type = srv_sms_btmapc_get_list_type(
                        old_msg_info->status,
                        old_msg_info->storage_type,
                        old_msg_info->folder_id);

    dest_box_type = srv_sms_btmapc_get_list_type(
                        new_msg_info->status,
                        new_msg_info->storage_type,
                        new_msg_info->folder_id);

    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LIST_UPDATE_EVENT_HANDLER_1, src_box_type, dest_box_type);

    if (src_box_type != dest_box_type)
    {
        srv_sms_btmapc_get_list_and_size_pointer(
            &src_msg_id_list,
            &src_msg_list_size,
            src_box_type);

        srv_sms_btmapc_get_list_and_size_pointer(
            &dest_msg_id_list,
            &dest_msg_list_size,
            dest_box_type);

            
        if (src_msg_id_list != NULL)
        {
            result = srv_sms_btmapc_delete_msg_from_list(src_msg_id_list, *src_msg_list_size, update_msg_id);
            if (result == MMI_TRUE)
            {
                (*src_msg_list_size)--;
            }
        }
        if (dest_msg_id_list != NULL)
        {   
            result = srv_sms_btmapc_add_msg_into_list(
                        dest_msg_id_list,
                        *dest_msg_list_size,
                        SRV_SMS_BTMAPC_MAX_SMS_ENTRY,
                        update_msg_id,
                        SRV_SMS_SORT_TIMESTAMP,
                        SRV_SMS_ORDER_DEFAULT);
            if (result == MMI_TRUE)
            {
                (*dest_msg_list_size)++;
            }
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_list_and_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_sms_btmapc_get_list_and_size(U16 **msg_id_list, U16 *msg_list_size, srv_sms_btmapc_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_box_type)
    {
        case SRV_SMS_BTMAPC_BOX_INBOX:
            *msg_id_list = srv_sms_btmapc_inbox_list;
            *msg_list_size = srv_sms_btmapc_inbox_size;
            break;

        case SRV_SMS_BTMAPC_BOX_OUTBOX:
            *msg_id_list = srv_sms_btmapc_outbox_list;
            *msg_list_size = srv_sms_btmapc_outbox_size;
            break;

        case SRV_SMS_BTMAPC_BOX_DRAFTS:
            *msg_id_list = srv_sms_btmapc_drafts_list;
            *msg_list_size = srv_sms_btmapc_drafts_size;
            break;
        
        case SRV_SMS_BTMAPC_BOX_DELETED:
            *msg_id_list = srv_sms_btmapc_deleted_list;
            *msg_list_size = srv_sms_btmapc_deleted_size;
            break;
            
#ifdef __SRV_SMS_UNSENT_LIST__
        case SRV_SMS_BTMAPC_BOX_UNSENT:
            *msg_id_list = srv_sms_btmapc_unsent_list;
            *msg_list_size = srv_sms_btmapc_unsent_size;
            break;
#endif /* __SRV_SMS_UNSENT_LIST__ */

        default:
            result = MMI_FALSE;
            break;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_list_and_size_pointer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static U16 srv_sms_btmapc_get_list_and_size_pointer(
                U16 **msg_id_list,
                U16 **msg_list_size,
                srv_sms_btmapc_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 max_list_size = SRV_SMS_BTMAPC_MAX_SMS_ENTRY;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_LIST_AND_SIZE_POINTER, msg_box_type);

    switch (msg_box_type)
    {
        case SRV_SMS_BTMAPC_BOX_INBOX:
            *msg_id_list = srv_sms_btmapc_inbox_list;
            *msg_list_size = &srv_sms_btmapc_inbox_size;
            break;

        case SRV_SMS_BTMAPC_BOX_OUTBOX:
            *msg_id_list = srv_sms_btmapc_outbox_list;
            *msg_list_size = &srv_sms_btmapc_outbox_size;
            break;

        case SRV_SMS_BTMAPC_BOX_DRAFTS:
            *msg_id_list = srv_sms_btmapc_drafts_list;
            *msg_list_size = &srv_sms_btmapc_drafts_size;
            break;
            
        case SRV_SMS_BTMAPC_BOX_DELETED:
            *msg_id_list = srv_sms_btmapc_deleted_list;
            *msg_list_size = &srv_sms_btmapc_deleted_size;
            break;

        case SRV_SMS_BTMAPC_BOX_UNSENT:
            *msg_id_list = srv_sms_btmapc_unsent_list;
            *msg_list_size = &srv_sms_btmapc_unsent_size;
            break;

        default:
            *msg_id_list = NULL;
            *msg_list_size = NULL;
            max_list_size = 0;
            break;
    }

    return max_list_size;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_create_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_btmapc_create_list(srv_sms_btmapc_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *msg_id_list;
    U16 *list_size;
    U16 max_list_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CREATE_LIST, msg_box_type);

    max_list_size = srv_sms_btmapc_get_list_and_size_pointer(
                        &msg_id_list,
                        &list_size,
                        msg_box_type);

    if (max_list_size > 0)
    {
        srv_sms_query_struct *query_data;
        U16 msg_num;

        query_data = (srv_sms_query_struct *)OslMalloc(sizeof(srv_sms_query_struct));

        srv_sms_btmapc_get_list_query_data(query_data, msg_box_type);

        msg_num = srv_sms_btmapc_query_msg_int(query_data, msg_id_list, max_list_size);

        *list_size = msg_num;
        OslMfree(query_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_list_query_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_btmapc_get_list_query_data(
                srv_sms_query_struct *query_data,
                srv_sms_btmapc_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_box_type)
    {
        case SRV_SMS_BTMAPC_BOX_INBOX:
        {
            query_data->folder_id = SRV_SMS_FOLDER_DEFAULT;
            query_data->query_flag = SRV_SMS_QUERY_STATUS;
            query_data->status = (srv_sms_status_enum)(SRV_SMS_STATUS_UNREAD | SRV_SMS_STATUS_READ);
            query_data->sort_flag = SRV_SMS_SORT_TIMESTAMP;
            query_data->order_flag = SRV_SMS_ORDER_DEFAULT;
            break;
        }

        case SRV_SMS_BTMAPC_BOX_OUTBOX:
        {
            query_data->folder_id = SRV_SMS_FOLDER_DEFAULT;
            query_data->query_flag = SRV_SMS_QUERY_STATUS;
            query_data->status = SRV_SMS_STATUS_SENT;
            break;
        }
        
        case SRV_SMS_BTMAPC_BOX_DRAFTS:
        {
            query_data->folder_id = SRV_SMS_FOLDER_DEFAULT;
            query_data->query_flag = SRV_SMS_QUERY_STATUS;
            query_data->status = SRV_SMS_STATUS_DRAFT;
            break;
        }
        case SRV_SMS_BTMAPC_BOX_UNSENT:
        {
            query_data->folder_id = SRV_SMS_FOLDER_DEFAULT;
            query_data->query_flag = SRV_SMS_QUERY_STATUS;
            query_data->status = SRV_SMS_STATUS_UNSENT;
            break;
        }

        default:
            MMI_ASSERT(0);
            break;
    }

    query_data->sort_flag = SRV_SMS_SORT_TIMESTAMP;
    query_data->order_flag = SRV_SMS_ORDER_DEFAULT;
}


#endif /* __SRV_SMS_BTMAPC__*/
#endif /* __MOD_SMSAL__ */

