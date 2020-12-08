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
 *  SmsBtMapCStorageSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service For BT File
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/

#include "MMI_features.h"
#ifdef __MOD_SMSAL__

#include "SmsBtMapCSrvStorage.h"
#include "Stdlib.h"
#include "SmsSrvGProt.h"
#include "SmsBtMapCSrvProt.h"
#include "app_datetime.h"
#include "fs_errcode.h"
#include "FileMgrSrvGProt.h"
#include "Unicodexdcl.h"
#include "PhbSrvGprot.h"
#include "SmsBtMapCSrvGProt.h"
#include "DateTimeType.h"
#include "mmi_rp_srv_sms_btmapc_def.h"

#ifdef __SRV_SMS_BTMAPC__

#define SRV_SMS_BTMAPC_QUERY_LIST_SIZE     SRV_SMS_BTMAPC_MAX_SMS_ENTRY
#define SRV_SMS_BTMAPC_TPUD_SIZE           140

#define SRV_SMS_BTMAPC_OP_INVALID_HDL 0xFFFFFFFF 
#define SRV_SMS_BTMAPC_OP_INVALID_INDEX 0xFFFFFFFF 

static const unsigned short sms_btmapc_stor_fcstab[256] = 
{
    0x0000, 0x1189, 0x2312, 0x329b, 0x4624, 0x57ad, 0x6536, 0x74bf, 0x8c48, 0x9dc1, 0xaf5a, 0xbed3, 0xca6c, 0xdbe5,
    0xe97e, 0xf8f7, 0x1081, 0x0108, 0x3393, 0x221a, 0x56a5, 0x472c, 0x75b7, 0x643e, 0x9cc9, 0x8d40, 0xbfdb, 0xae52,
    0xdaed, 0xcb64, 0xf9ff, 0xe876, 0x2102, 0x308b, 0x0210, 0x1399, 0x6726, 0x76af, 0x4434, 0x55bd, 0xad4a, 0xbcc3,
    0x8e58, 0x9fd1, 0xeb6e, 0xfae7, 0xc87c, 0xd9f5, 0x3183, 0x200a, 0x1291, 0x0318, 0x77a7, 0x662e, 0x54b5, 0x453c,
    0xbdcb, 0xac42, 0x9ed9, 0x8f50, 0xfbef, 0xea66, 0xd8fd, 0xc974, 0x4204, 0x538d, 0x6116, 0x709f, 0x0420, 0x15a9,
    0x2732, 0x36bb, 0xce4c, 0xdfc5, 0xed5e, 0xfcd7, 0x8868, 0x99e1, 0xab7a, 0xbaf3, 0x5285, 0x430c, 0x7197, 0x601e,
    0x14a1, 0x0528, 0x37b3, 0x263a, 0xdecd, 0xcf44, 0xfddf, 0xec56, 0x98e9, 0x8960, 0xbbfb, 0xaa72, 0x6306, 0x728f,
    0x4014, 0x519d, 0x2522, 0x34ab, 0x0630, 0x17b9, 0xef4e, 0xfec7, 0xcc5c, 0xddd5, 0xa96a, 0xb8e3, 0x8a78, 0x9bf1,
    0x7387, 0x620e, 0x5095, 0x411c, 0x35a3, 0x242a, 0x16b1, 0x0738, 0xffcf, 0xee46, 0xdcdd, 0xcd54, 0xb9eb, 0xa862,
    0x9af9, 0x8b70, 0x8408, 0x9581, 0xa71a, 0xb693, 0xc22c, 0xd3a5, 0xe13e, 0xf0b7, 0x0840, 0x19c9, 0x2b52, 0x3adb,
    0x4e64, 0x5fed, 0x6d76, 0x7cff, 0x9489, 0x8500, 0xb79b, 0xa612, 0xd2ad, 0xc324, 0xf1bf, 0xe036, 0x18c1, 0x0948,
    0x3bd3, 0x2a5a, 0x5ee5, 0x4f6c, 0x7df7, 0x6c7e, 0xa50a, 0xb483, 0x8618, 0x9791, 0xe32e, 0xf2a7, 0xc03c, 0xd1b5,
    0x2942, 0x38cb, 0x0a50, 0x1bd9, 0x6f66, 0x7eef, 0x4c74, 0x5dfd, 0xb58b, 0xa402, 0x9699, 0x8710, 0xf3af, 0xe226,
    0xd0bd, 0xc134, 0x39c3, 0x284a, 0x1ad1, 0x0b58, 0x7fe7, 0x6e6e, 0x5cf5, 0x4d7c, 0xc60c, 0xd785, 0xe51e, 0xf497,
    0x8028, 0x91a1, 0xa33a, 0xb2b3, 0x4a44, 0x5bcd, 0x6956, 0x78df, 0x0c60, 0x1de9, 0x2f72, 0x3efb, 0xd68d, 0xc704,
    0xf59f, 0xe416, 0x90a9, 0x8120, 0xb3bb, 0xa232, 0x5ac5, 0x4b4c, 0x79d7, 0x685e, 0x1ce1, 0x0d68, 0x3ff3, 0x2e7a,
    0xe70e, 0xf687, 0xc41c, 0xd595, 0xa12a, 0xb0a3, 0x8238, 0x93b1, 0x6b46, 0x7acf, 0x4854, 0x59dd, 0x2d62, 0x3ceb,
    0x0e70, 0x1ff9, 0xf78f, 0xe606, 0xd49d, 0xc514, 0xb1ab, 0xa022, 0x92b9, 0x8330, 0x7bc7, 0x6a4e, 0x58d5, 0x495c,
    0x3de3, 0x2c6a, 0x1ef1, 0x0f78
};
#define srv_sms_btmapc_checksum_fcs(fcs, c)  ((fcs >> 8) ^ sms_btmapc_stor_fcstab[(fcs ^ c) & 0x00ff])


static void srv_sms_btmapc_save_msg_callback(srv_sms_callback_struct *callback_data);
static srv_sms_cause_enum srv_sms_btmapc_save_msg_init(srv_sms_btmapc_save_cntx_struct* save_cntx);
static void srv_sms_btmapc_save_msg_deinit(srv_sms_btmapc_save_cntx_struct *save_cntx);
//static void srv_sms_btmapc_update_msg_deinit(srv_sms_btmapc_update_cntx_struct *update_cntx);
static void srv_sms_btmapc_update_msg_next(srv_sms_btmapc_update_cntx_struct* update_cntx);
static MMI_BOOL srv_sms_btmapc_update_msg_check_data(
                    U16 msg_id,
                    srv_sms_btmapc_int_msg_data_struct* msg_data);
static void srv_sms_btmapc_update_msg_init(
                srv_sms_btmapc_update_cntx_struct* update_cntx,
                U16 msg_id);
static void srv_sms_btmapc_delete_msg_ext_callback(srv_sms_callback_struct *callback_data);
static void srv_sms_btmapc_delete_msg_bitmap_callback(srv_sms_callback_struct *callback_data);
static void srv_sms_btmapc_change_status_update_next(srv_sms_btmapc_change_status_cntx_struct* change_cntx);
static void srv_sms_btmapc_query_msg_attribute(
                U16 *msg_id_list,
                U16 *msg_num,
                srv_sms_query_enum query_flag,
                srv_sms_query_struct *query_data);

static MMI_BOOL srv_sms_btmapc_query_is_match(
                    U16 msg_id,
                    srv_sms_query_enum query_flag,
                    srv_sms_query_struct *query_data);

static void srv_sms_btmapc_sort_msg_timestamp(
                    U16 *msg_id_array,
                    U16 msg_num,
                    srv_sms_order_enum order_flag);
static void srv_sms_btmapc_sort_msg_timestamp_asc(U16 *msg_id_array, U16 msg_num);
static void srv_sms_btmapc_sort_msg_timestamp_desc(U16 *msg_id_array, U16 msg_num);

static void srv_sms_btmapc_add_msg_into_list_by_desc_timestap(
                U16 *msg_id_list,
                U16 curr_num,
                U16 max_num,
                U16 add_msg_id);

static U32 srv_sms_btmapc_get_table_index(srv_sms_btmapc_file_index_enum file_index);
static SMS_BTMAPC_CHECKSUM srv_sms_btmapc_checksum_compute_by_hd(FS_HANDLE hd, U32 position);
static void srv_sms_btmapc_free_send_handle(SMS_HANDLE sms_handle);

extern void srv_sms_btmapc_sort_msg(
        U16 *msg_id_array,
        U16 msg_num,
        srv_sms_sort_enum sort_flag,
        srv_sms_order_enum order_flag);



/**************************************************************
* Function Defination
**************************************************************/


/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_msg
 * DESCRIPTION
 *  1. Read Message's Data, included message status, number, content and other attributes
 *     (Storage Type, SIM Card, Profile element, etc.) indicated by the flag;
 *  2. The buffer to save the content should be provided by caller.
 *  3. The Callback Action Data Structure is srv_sms_read_msg_cb_struct;
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 *  change_status   [IN]        Whether change the UNREAD Msg to READ
 *  msg_data        [IN/OUT]    Message Data For Filling back read data
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_msg
 * DESCRIPTION
 *  1. Read Message's Data, included message status, number, content and other attributes
 *     (Storage Type, SIM Card, Profile element, etc.) indicated by the flag;
 *  2. The buffer to save the content should be provided by caller.
 *  3. The Callback Action Data Structure is srv_sms_read_msg_cb_struct;
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 *  change_status   [IN]        Whether change the UNREAD Msg to READ
 *  msg_data        [IN/OUT]    Message Data For Filling back read data
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
SMS_HANDLE srv_sms_btmapc_read_msg_detail(
                U16 msg_id,
                MMI_BOOL change_status,
                void* msg_data, 
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause;
    srv_sms_btmapc_read_cntx_struct *read_cntx = (srv_sms_btmapc_read_cntx_struct *)user_data;
    srv_sms_msg_data_struct *msgData = (srv_sms_msg_data_struct *)msg_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    error_cause = srv_sms_btmapc_check_common_msg_error(msg_id, SRV_SMS_ACTION_READ);
    srv_sms_btmapc_get_msg_address(msg_id, msgData->number);
    msgData->tp_st = msg_id;
    if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
    {
        if (read_cntx)
        {
            srv_sms_btmapc_read_me_sms(
                msg_id,
                srv_sms_btmapc_read_msg_callback,
                user_data);
        }
    }
    return (SMS_HANDLE)read_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_save_handle
 * DESCRIPTION
 *  Get a SMS_HANDLE For Saving or Updating Message
 * PARAMETERS
 *  void
 * RETURNS
 *  SMS_HANDLE
 *****************************************************************************/
SMS_HANDLE srv_sms_btmapc_get_save_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_save_cntx_struct *save_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    save_cntx = srv_sms_btmapc_alloc_cntx(
                    sizeof(srv_sms_btmapc_save_cntx_struct),
                    SRV_SMS_ACTION_SAVE,
                    NULL,
                    NULL);

    if (save_cntx)
    {
        srv_sms_btmapc_int_msg_data_struct *msg_data;

        msg_data = srv_sms_btmapc_alloc_int_msg_data();

        CNTX_SET_HD_DATA(save_cntx, msg_data);
    }

    return (SMS_HANDLE)save_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_save_msg
 * DESCRIPTION
 *  1. Save a new message to SMS Storage.
 *  2. The Callers need to get a SMS save handle by API srv_sms_get_save_handle() first,
 *     then they can call the seting API (srv_sms_set_content() etc.) to set the parameters
 *     they concerned.
 *  3. If Caller specify those parameters (Status, Address, Content, SIM Card, Storage Type,
 *     Profile element, we will use them, otherwise, it will user the defaut value (If the 
 *     parameters is in the SMS setting, it will use the setting's value as defaut).
 *  4. The Callback Action Data Struct is srv_sms_save_msg_cb_struct.
 * PARAMETERS
 *  save_handle     [IN]        Save Handle
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_save_msg(
        SMS_HANDLE save_handle,
        SrvSmsCallbackFunc callback_func,
        void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
    srv_sms_btmapc_save_cntx_struct *save_cntx = (srv_sms_btmapc_save_cntx_struct*)save_handle;
    srv_sms_btmapc_int_msg_data_struct *msg_data = (srv_sms_btmapc_int_msg_data_struct*)CNTX_GET_HD_DATA(save_cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* This API may change to
     *      SMS_HANDLE srv_sms_save_msg(SMS_DATA sms_data, ...);
     * And need to provide a sets of SET SMS_DATA API to replace SET SMS_HANDLE API
     * ex. srv_sms_set_address(SMS_HANDLE handle, ...) need to change to 
     *     srv_sms_set_address(SMS_DATA data, ...) 
     */

    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SAVE_MSG, save_handle);

    do
    {
        U16 msg_id;
        srv_sms_btmapc_msg_node_struct *msg_node = &save_cntx->msg_node;
        
        if (sms_btmapc_storage_cntx.is_ready == MMI_FALSE)
        {
            error_cause = SRV_SMS_CAUSE_NOT_READY;
            break;
        }
        if (CNTX_GET_ACTION(save_cntx) != SRV_SMS_ACTION_SAVE)
        {
            error_cause = SRV_SMS_CAUSE_DATA_INVALID;
            break;
        }

        CNTX_SET_CALLBACK(save_cntx, callback_func, user_data);
        error_cause = srv_sms_btmapc_save_msg_init(save_cntx);
        if (error_cause != SRV_SMS_CAUSE_NO_ERROR)
        {
            break;
        }
        msg_id = srv_sms_btmapc_add_msg_node(msg_node);
        if(msg_id == SRV_SMS_INVALID_MSG_ID)
        {
            error_cause = SRV_SMS_CAUSE_MEM_FULL;
        }
        else
        {
            srv_sms_btmapc_write_me_sms(
                msg_id, 
                msg_data->content_buff, 
                srv_sms_btmapc_save_msg_callback,
                save_cntx);
        }
    } while (0);

    if (error_cause != SRV_SMS_CAUSE_NO_ERROR)
    {
        srv_sms_btmapc_save_msg_deinit(save_cntx);
        srv_sms_btmapc_free_cntx(save_cntx);
        srv_sms_btmapc_async_callback(             
                SRV_SMS_ACTION_SAVE,                         
                MMI_FALSE,                      
                error_cause,                          
                NULL,                           
                0,                              
                user_data,                       
                callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_update_handle
 * DESCRIPTION
 *  Get a SMS_HANDLE For Updating Message
 * PARAMETERS
 *  void
 * RETURNS
 *  SMS_HANDLE
 *****************************************************************************/
SMS_HANDLE srv_sms_btmapc_get_update_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_update_cntx_struct *update_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    update_cntx = srv_sms_btmapc_alloc_cntx(
                    sizeof(srv_sms_btmapc_update_cntx_struct),
                    SRV_SMS_ACTION_UPDATE,
                    NULL,
                    NULL);

    if (update_cntx)
    {
        srv_sms_btmapc_int_msg_data_struct *msg_data;

        msg_data = srv_sms_btmapc_alloc_int_msg_data();

        CNTX_SET_HD_DATA(update_cntx, msg_data);
    }

    return (SMS_HANDLE)update_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_msg
 * DESCRIPTION
 *  1. Update a existed message to the new message
 *  2. The usage of this API is similiar with srv_sms_save_msg();
 *  3. This API is not supported in this stage.
 *  4. The Callback Action Data Structure is srv_sms_update_msg_cb_struct;
 *  5. This API is not implemented in the current version.
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 *  save_handle     [IN]        Save Handle
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_update_msg(
        U16 msg_id,
        SMS_HANDLE update_handle,
        SrvSmsCallbackFunc callback_func,
        void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_update_cntx_struct *update_cntx = (srv_sms_btmapc_update_cntx_struct*)update_handle;
    srv_sms_btmapc_int_msg_data_struct *msg_data;
    srv_sms_cause_enum error_cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_data = (srv_sms_btmapc_int_msg_data_struct*)CNTX_GET_HD_DATA(update_cntx);

    error_cause = srv_sms_btmapc_check_common_msg_error(msg_id, SRV_SMS_ACTION_UPDATE);

    if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
    {
        if (srv_sms_btmapc_update_msg_check_data(msg_id, msg_data))
        {
            CNTX_SET_CALLBACK(update_cntx, callback_func, user_data);

            srv_sms_btmapc_update_msg_init(
                update_cntx,
                msg_id);

            srv_sms_btmapc_update_msg_next(update_cntx);
        }
        else
        {
            error_cause = SRV_SMS_CAUSE_DATA_INVALID;
        }
    }
    
    if (error_cause != SRV_SMS_CAUSE_NO_ERROR)
    {
        srv_sms_btmapc_free_int_msg_data(msg_data);
        srv_sms_btmapc_free_cntx(update_cntx);
        srv_sms_btmapc_async_callback(             
                SRV_SMS_ACTION_UPDATE,                         
                MMI_FALSE,                      
                error_cause,                          
                NULL,                           
                0,                              
                user_data,                       
                callback_func);
    }
}



/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_msg_bitmap
 * DESCRIPTION
 *  1. Delete the messages indicated by the msg_bitmap;
 *  2. The Callback Action Data Structure is srv_sms_delete_msg_bitmap_cb_struct;
 * PARAMETERS
 *  msg_bitmap      [IN]        The bitmap of the Message IDs
 *  byte_size       [IN]        The byte number of the msg_bitmap
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
SMS_HANDLE srv_sms_btmapc_delete_msg_bitmap(
                U8 msg_bitmap[],
                U16 bitmap_size,
                SrvSmsCallbackFunc callback_func,
                void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_delete_bitmap_cntx_struct *del_bitmap_cntx = NULL;
    U16 curr_msg_id = SRV_SMS_INVALID_BITMAP_INDEX;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((msg_bitmap != NULL) && (bitmap_size > 0))
    {
        curr_msg_id = srv_sms_btmapc_get_bitmap_index(0, msg_bitmap, bitmap_size);
    }

    if (curr_msg_id != SRV_SMS_INVALID_BITMAP_INDEX)
    {
        del_bitmap_cntx = srv_sms_btmapc_alloc_cntx(
                            (sizeof(srv_sms_btmapc_delete_bitmap_cntx_struct) + bitmap_size),
                            SRV_SMS_ACTION_DELETE,
                            callback_func,
                            user_data);

        if (del_bitmap_cntx)
        {
            del_bitmap_cntx->msg_bitmap = (U8*)del_bitmap_cntx + sizeof(srv_sms_btmapc_delete_bitmap_cntx_struct);

            memcpy(del_bitmap_cntx->msg_bitmap, msg_bitmap, bitmap_size);

            del_bitmap_cntx->bitmap_size = bitmap_size;
            del_bitmap_cntx->curr_msg_id = curr_msg_id;
            del_bitmap_cntx->deleted_num = 0;
            del_bitmap_cntx->callback_func = callback_func;
            del_bitmap_cntx->user_data = user_data;

            del_bitmap_cntx->deleted_msg_bitmap = (U8 *)OslMalloc(bitmap_size);
            memset(del_bitmap_cntx->deleted_msg_bitmap, 0, bitmap_size);

            srv_sms_btmapc_delete_msg(
                curr_msg_id,
                srv_sms_btmapc_delete_msg_bitmap_callback,
                del_bitmap_cntx);
        }
        else
        {
            SMS_BTMAPC_ASYNC_ERR_CALLBACK(
                SRV_SMS_ACTION_DELETE,
                SRV_SMS_CAUSE_MEM_INSUFFICIENT,
                user_data,
                callback_func);
        }
    }
    else
    {
        srv_sms_delete_msg_bitmap_cb_struct del_bitmap_cb_data;

        del_bitmap_cb_data.deleted_num = 0;
        del_bitmap_cb_data.bitmap_size = 0;
        del_bitmap_cb_data.deleted_msg_bitmap = NULL;

        SMS_BTMAPC_ASYNC_SUCC_CALLBACK(
            SRV_SMS_ACTION_DELETE,
            &del_bitmap_cb_data,
            user_data,
            callback_func);
    }

    return del_bitmap_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_change_msg_status
 * DESCRIPTION
 *  1. Change message's status;
 *  2. The Callback Action Data Structure is srv_sms_change_msg_status_cb_struct;
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 *  status          [IN]        Destination Status
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
SMS_HANDLE srv_sms_btmapc_change_msg_status_detail(
                U16 msg_id,
                srv_sms_status_enum status,
                srv_sms_btmapc_change_status_cntx_struct *change_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause;
    srv_sms_btmapc_msg_node_struct *msg_node;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error_cause = srv_sms_btmapc_check_common_msg_error(msg_id, SRV_SMS_ACTION_CHANGE_STATUS);
    if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
    {
        msg_node = srv_sms_btmapc_get_msg_node(msg_id);
        msg_node->status = change_cntx->status;
        srv_sms_btmapc_change_status_update_next(change_cntx);
    }
    else
    {         
         srv_sms_btmapc_cntx_callback(
             change_cntx,
             MMI_FALSE,
             error_cause,
             NULL);
    }

    return (SMS_HANDLE)change_cntx;
}



/*****************************************************************************
 * FUNCTION
 *  srv_sms_query_msg_int
 * DESCRIPTION
 *  
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_sms_btmapc_query_msg_int(
        srv_sms_query_struct *query_data,
        U16* msg_list,
        U16 list_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0;
    U16 i;
    U32 query_flag = 0x01;
    U16 *query_msg_list = msg_list;
    U16 max_msg_num = list_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_btmapc_storage_cntx.total_msg_num > 0)
    {
        if (max_msg_num > SRV_SMS_BTMAPC_MAX_SMS_ENTRY)
        {
            max_msg_num = SRV_SMS_BTMAPC_MAX_SMS_ENTRY;
        }

        /* Get Valid Message */
        for (i = 0; i < (sms_btmapc_storage_cntx.used_msg_tail_id + 1); i++)
        {
            if (srv_sms_btmapc_is_msg_exist(i) && (count < max_msg_num))
            {
                query_msg_list[count++] = i;
            }
        }

        while ((count > 0) && (query_flag < SRV_SMS_QUERY_RESERVED))
        {
            //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_QUERY_MSG_2, count, query_flag);

            if (query_data->query_flag & query_flag)
            {
                srv_sms_btmapc_query_msg_attribute(
                    query_msg_list,
                    &count,
                    (srv_sms_query_enum)query_flag,
                    query_data);
            }

            query_flag <<= 1;
        }
    }

    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_QUERY_MSG_2, count);

    if (count > 0)
    {
        srv_sms_btmapc_sort_msg(
            query_msg_list,
            count,
            query_data->sort_flag,
            query_data->order_flag);
    }

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_query_msg
 * DESCRIPTION
 *  1. Query the messages with some properties.
 *  2. The caller can set the query_flag, and the corresponding paramenters of
 *     the propertied they wanted. The folder ID is mandatory in the current version;
 *  3. The caller also can specify the sort flag, in the current version, we only 
 *     support sorting by timestamp.
 *  4. The Callback Action Data Structure is srv_sms_query_msg_cb_struct;
 * PARAMETERS
 *  query_data      [IN]        Query Data
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_query_msg(
        srv_sms_query_struct *query_data,
        SrvSmsCallbackFunc callback_func,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_query_msg_cb_struct query_cb_data;
    U16 *query_msg_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    query_msg_list = (U16*)OslMalloc(sizeof(U16) * SRV_SMS_BTMAPC_QUERY_LIST_SIZE);

    query_cb_data.msg_num = srv_sms_btmapc_query_msg_int(
                                query_data,
                                query_msg_list,
                                SRV_SMS_BTMAPC_QUERY_LIST_SIZE);

    query_cb_data.msg_id_list = query_msg_list;

    /* Must use sync callback, because the queried list is released after callback */
    srv_sms_btmapc_succ_callback(
        SRV_SMS_ACTION_QUERY,
        &query_cb_data,
        user_data,
        callback_func);

    OslMfree(query_msg_list);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sort_msg
 * DESCRIPTION
 *  1. Sort the messages list.
 *  2. In the current version, we only support sorting by timestamp.
 * PARAMETERS
 *  msg_id_array    :   [IN]        Message ID Array
 *  msg_num         :   [IN]        Message Number
 *  sort_flag       :   [IN]        Sorting Type Flag
 *  order_flag      :   [IN]        Ordering Flag
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_sort_msg(
        U16 *msg_id_array,
        U16 msg_num,
        srv_sms_sort_enum sort_flag,
        srv_sms_order_enum order_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SORT_MSG, msg_num, sort_flag, order_flag);

    switch (sort_flag)
    {
        case SRV_SMS_SORT_TIMESTAMP:
            srv_sms_btmapc_sort_msg_timestamp(msg_id_array, msg_num, order_flag);
            break;

        case SRV_SMS_SORT_NONE:
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_asc_address
 * DESCRIPTION
 *  Get Message's Address (ASCII Format)
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 * RETURNS
 *  S8*
 *****************************************************************************/
const S8* srv_sms_btmapc_get_msg_asc_address(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const S8 *address;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_btmapc_is_msg_exist(msg_id) == MMI_TRUE)
    {
        address = srv_sms_btmapc_msg_list[msg_id].number;
    }
    else
    {
        address = NULL;
    }

    return address;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_address
 * DESCRIPTION
 *  Get Message's Address (ASCII Format)
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 * RETURNS
 *  S8*
 *****************************************************************************/
void srv_sms_btmapc_get_msg_address(U16 msg_id, S8* ucs2_addr_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const S8 *asc_address;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    asc_address = srv_sms_btmapc_get_msg_asc_address(msg_id);

    if (asc_address != NULL)
    {    
        mmi_asc_to_ucs2(ucs2_addr_buff, (S8*)asc_address);
    }
    else
    {
        ucs2_addr_buff[0] = '\0';
        ucs2_addr_buff[1] = '\0';
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_multi_addr_num
 * DESCRIPTION
 *  Get Message's mutli Address's number
 * PARAMETERS
 *  msg_id          :   [IN]        Message ID
 * RETURNS
 *  U16
 *****************************************************************************/
U16 srv_sms_btmapc_get_msg_addr_num(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_btmapc_is_msg_exist(msg_id))
    {
    #ifdef __SRV_SMS_MULTI_ADDR__
        count = srv_sms_btmapc_msg_list[msg_id].ext_addr_num + 1;
    #else /* __SRV_SMS_MSG_INFO_CONTENT__ */
        count = 1;
    #endif /* __SRV_SMS_MSG_INFO_CONTENT__ */
    }
    
    return count;
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_multi_addr
 * DESCRIPTION
 *  Get Message's Address
 * PARAMETERS
 *  addr_buff       :   [IN]        ucs2 address buffer
 *  msg_id          :   [IN]        Message ID
 * RETURNS
 *  S8*
 *****************************************************************************/
void srv_sms_btmapc_get_msg_multi_addr(
                WCHAR* addr_buff,
                srv_sms_status_enum* status,
                U16 msg_id,
                U16 addr_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_MULTI_ADDR__
    count = srv_sms_btmapc_get_msg_addr_num(msg_id);
#else /* __SRV_SMS_MULTI_ADDR__ */
    count = 1;
#endif /* __SRV_SMS_MULTI_ADDR__ */

    if (addr_index < count)
    {
        {
            srv_sms_btmapc_get_msg_address(msg_id, (S8*)addr_buff);        
            MMI_ASSERT(msg_id < SRV_SMS_BTMAPC_MAX_SMS_ENTRY);
            *status = (srv_sms_status_enum)srv_sms_btmapc_msg_list[msg_id].status;
        }
    }
    else
    {
        addr_buff[0] = '\0';
        *status = SRV_SMS_STATUS_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_content
 * DESCRIPTION
 *  Get Message's Content For List Display.
 *  This API only for SMS application Internal Using
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 * RETURNS
 *  S8*
 *****************************************************************************/
const S8* srv_sms_btmapc_get_msg_content(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const S8 *content;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_btmapc_is_msg_exist(msg_id) == MMI_TRUE)
    {
        content = (S8*)srv_sms_btmapc_msg_list[msg_id].content;
    }
    else
    {
        content = NULL;
    }
    return content;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_timestamp
 * DESCRIPTION
 *  Get Message's Timestamp (MTTIME Format)
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 *  timestamp       [OUT]       Timestamp
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_get_msg_timestamp(U16 msg_id, MYTIME *time_stamp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 timestamp_int;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    timestamp_int = srv_sms_btmapc_get_msg_timestamp_utc_sec(msg_id);

    applib_dt_utc_sec_2_mytime(timestamp_int, (applib_time_struct *)time_stamp, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_timestamp_utc_sec
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_sms_btmapc_get_msg_timestamp_utc_sec(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 timestamp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_btmapc_is_msg_exist(msg_id) == MMI_TRUE)
    {
        timestamp = srv_sms_btmapc_msg_list[msg_id].timestamp;
    }
    else
    {
        timestamp = 0;
    }
    return timestamp;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_pid
 * DESCRIPTION
 *  Get Message's PID (Protocol Identifier)
 * PARAMETERS
 *  msg_id      [IN]    Message ID
 * RETURNS
 *  srv_sms_pid_enum
 *****************************************************************************/
srv_sms_pid_enum srv_sms_btmapc_get_msg_pid(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_pid_enum pid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_btmapc_is_msg_exist(msg_id) == MMI_TRUE)
    {
        pid = (srv_sms_pid_enum)srv_sms_btmapc_msg_list[msg_id].pid;
    }
    else
    {
        pid = SRV_SMS_PID_RESERVED;
    }

    return pid;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_status
 * DESCRIPTION
 *  Get Message's Status
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 * RETURNS
 *  srv_sms_status_enum
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_mti
 * DESCRIPTION
 *  Get Message's MTI (Message Type Indication)
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 * RETURNS
 *  srv_sms_mti_enum
 *****************************************************************************/
srv_sms_mti_enum srv_sms_btmapc_get_msg_mti(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_mti_enum mti;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_btmapc_is_msg_exist(msg_id) == MMI_TRUE)
    {
        mti = (srv_sms_mti_enum)srv_sms_btmapc_msg_list[msg_id].mti;
    }
    else
    {
        mti = SRV_SMS_MTI_RESERVED;
    }

    return mti;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_port
 * DESCRIPTION
 *  Get Message's Destination Port Number
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 * RETURNS
 *  U16
 *****************************************************************************/
U16 srv_sms_btmapc_get_msg_port(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 port_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_MSG_INFO_PORT__
    if (srv_sms_btmapc_is_msg_exist(msg_id))
    {
        port_num = srv_sms_btmapc_msg_list[msg_id].port_num;
    }
#endif /* __SRV_SMS_MSG_INFO_PORT__ */

    return port_num;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_size
 * DESCRIPTION
 *  Get Message's size, only for SMS application internal using
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 * RETURNS
 *  U8
 *****************************************************************************/
U16 srv_sms_btmapc_get_msg_size(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_sms_btmapc_is_msg_exist(msg_id) == MMI_TRUE)
    {
        msg_size = srv_sms_btmapc_msg_list[msg_id].size;
    }
    else
    {
        msg_size = 0;
    }
    

    return msg_size;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_msg_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_sms_cause_enum srv_sms_btmapc_read_msg_init(
                            srv_sms_btmapc_read_cntx_struct* read_cntx,
                            U16 msg_id,
                            MMI_BOOL change_status,
                            srv_sms_msg_data_struct* msg_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum msg_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    read_cntx->msg_id = msg_id;
    msg_status = srv_sms_btmapc_get_msg_status(msg_id);

    if ((msg_status & SRV_SMS_STATUS_UNREAD) && (change_status == MMI_TRUE))
    {
        read_cntx->change_status = MMI_TRUE;
    }
    else
    {
        read_cntx->change_status = MMI_FALSE;
    }
    read_cntx->msg_data = msg_data;

    return SRV_SMS_CAUSE_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_save_msg_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_btmapc_save_msg_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_save_cntx_struct *save_cntx;
    MMI_BOOL result = callback_data->result;
    srv_sms_cause_enum error_cause = callback_data->cause;
    U16 msg_id;
    WCHAR file_name[SRV_SMS_BTMAPC_MAX_PATH_LEN];
	srv_sms_btmapc_msg_node_struct *msg_node = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    save_cntx = (srv_sms_btmapc_save_cntx_struct*)callback_data->user_data;    
    msg_node = &(save_cntx->msg_node);
    msg_id = msg_node->msg_id;
    
    if (CNTX_IS_ABORT(save_cntx))
    {
        result = MMI_FALSE;
        error_cause = SRV_SMS_CAUSE_ABORT;
    }

    if (result)
    {
        srv_sms_save_msg_cb_struct save_msg_cb_data;
        if (msg_id != SRV_SMS_INVALID_MSG_ID)
        {
            srv_sms_event_add_struct *event_data;
            MMI_BOOL int_result;

            /* Set Event data For Add Event */
            event_data = (srv_sms_event_add_struct *)OslMalloc(sizeof(srv_sms_event_add_struct));

            event_data->msg_id = msg_id;
            srv_sms_btmapc_msg_node_to_msg_info(&event_data->msg_info, msg_node);
            /* Free Save Content Buffer Before Execute Any Callback Function */
            srv_sms_btmapc_save_msg_deinit(save_cntx);
            /* Execute Message Add Interrupt Event */
            int_result = srv_sms_btmapc_exec_interrupt_event(EVT_ID_SRV_SMS_BTMAPC_ADD_MSG, event_data);

            /* Execute Callback Function */
            save_msg_cb_data.msg_id = msg_id;

            srv_sms_btmapc_cntx_callback(
                save_cntx,
                MMI_TRUE,
                SRV_SMS_CAUSE_NO_ERROR,
                &save_msg_cb_data);

            if (int_result == MMI_FALSE)
            {
                /* Emit Message Add Event */
                srv_sms_btmapc_emit_event(EVT_ID_SRV_SMS_BTMAPC_ADD_MSG, event_data);
            }

            OslMfree(event_data);
        }
        else
        {
            srv_sms_btmapc_save_msg_deinit(save_cntx);
            srv_sms_btmapc_cntx_callback(
                save_cntx,
                result,
                SRV_SMS_CAUSE_MEM_FULL,
                NULL);
         }
    }
    else
    {
        if(msg_id != SRV_SMS_INVALID_MSG_ID)
        {
            srv_sms_btmapc_get_msg_name(msg_id, MMI_FALSE, file_name);
            if(FS_Delete(file_name) >= 0)
            {
                srv_sms_btmapc_delete_msg_node(msg_id);
            }
        }
        if (CNTX_IS_ABORT(save_cntx))
        {
            result = MMI_TRUE;
        }
        srv_sms_btmapc_save_msg_deinit(save_cntx);
        srv_sms_btmapc_cntx_callback(
            save_cntx,
            result,
            error_cause,
            NULL);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_save_msg_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static srv_sms_cause_enum srv_sms_btmapc_save_msg_init(srv_sms_btmapc_save_cntx_struct* save_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
    MYTIME local_time;
    MYTIME *timestamp;
    U32 temp_timestamp;
    U8 sms_mti;    
    srv_sms_btmapc_int_msg_data_struct *msg_data = (srv_sms_btmapc_int_msg_data_struct*)CNTX_GET_HD_DATA(save_cntx);
    srv_sms_btmapc_msg_node_struct *msg_node = &save_cntx->msg_node;
    srv_sms_para_enum para_flag = msg_data->para_flag;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_node->status = msg_data->status;
    if((msg_data->number[0] != '\0') || (msg_data->number[1] != '\0'))
    {
        if (srv_sms_btmapc_check_ucs2_number(msg_data->number) == MMI_FALSE)
        {
            error_cause = SRV_SMS_CAUSE_NUMBER_INVALID;
        }
        else
        {
            mmi_ucs2_to_asc(msg_node->number, msg_data->number);
        }
    }
    else
    {
        if (msg_node != NULL)
        {
            msg_node->number[0] = '\0';
        }

        if (msg_data->is_allow_num_emtpy == MMI_FALSE)
        {
            error_cause = SRV_SMS_CAUSE_NUMBER_EMPTY;
        }
    }

    switch (msg_data->status)
    {
        case SRV_SMS_STATUS_UNREAD:
        case SRV_SMS_STATUS_READ:
            sms_mti = SMSLIB_MTI_DELIVER;
            break;

        case SRV_SMS_STATUS_SENT:
        case SRV_SMS_STATUS_UNSENT:
        case SRV_SMS_STATUS_DRAFT:
        default:
            sms_mti = SMSLIB_MTI_SUBMIT;
            break;
    }
    msg_node->mti = (U8)sms_mti;

    /* Set SCTS (SMS Center Timestamp) */
    if (para_flag & SRV_SMS_PARA_TIMESTAMP)
    {
        timestamp = &msg_data->timestamp;
    }
    else
    {
        DTGetRTCTime(&local_time);

        timestamp = &local_time;
    }
    temp_timestamp = mmi_dt_mytime_2_utc_sec(timestamp, MMI_FALSE);
    msg_node->timestamp = applib_dt_sec_local_to_utc(temp_timestamp);

    if (para_flag & SRV_SMS_PARA_PID)
    {
        msg_node->pid = (U8)msg_data->pid;
    }
    else
    {
        msg_node->pid = SRV_SMS_PID_DEFAULT;
    }
    if (para_flag & SRV_SMS_PARA_CONTENT_BUFF)
    {
        if(msg_data->content_buff_size < SRV_SMS_MSG_INFO_CONTENT_LEN * 2)
        {
            memcpy(msg_node->content, msg_data->content_buff, msg_data->content_buff_size);
        }
        else
        {
            memcpy(msg_node->content, msg_data->content_buff, SRV_SMS_MSG_INFO_CONTENT_LEN * 2);
        }
    }
    
    if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
    {
        if (msg_data->para_flag & SRV_SMS_PARA_MSG_REF)
        {
            memcpy(save_cntx->msg_ref, msg_data->msg_ref, sizeof(save_cntx->msg_ref));
        }
        else
        {
            memset(save_cntx->msg_ref, 0, sizeof(save_cntx->msg_ref));
        }

        if (msg_data->para_flag & SRV_SMS_PARA_STATUS_REPORT)
        {
            save_cntx->report_id = msg_data->report_id;
        }
        else
        {
            save_cntx->report_id = SRV_SMS_INVALID_MSG_ID;
        }

        msg_node->storage_type = msg_data->storage_type;
        msg_node->start_pdu_id = SRV_SMS_BTMAPC_INVALID_PDU_ID;

        /* Init Save Msg Context */
        save_cntx->curr_index = 0;
        save_cntx->error_cause = SRV_SMS_CAUSE_NO_ERROR;
        save_cntx->storage_type = msg_data->storage_type;
        save_cntx->sim_id = msg_data->sim_id;
    }
    return error_cause;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_save_msg_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_btmapc_save_msg_deinit(srv_sms_btmapc_save_cntx_struct *save_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_int_msg_data_struct *msg_data = (srv_sms_btmapc_int_msg_data_struct*)CNTX_GET_HD_DATA(save_cntx);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SAVE_MSG_DEINIT);
    OslMfree(msg_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_msg_next
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_btmapc_update_msg_next(srv_sms_btmapc_update_cntx_struct* update_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_msg_node_struct *msg_node;
    srv_sms_event_update_struct *event_data;
    srv_sms_change_msg_status_cb_struct change_status_cb_data;
    U16 msg_id = update_cntx->msg_id;
    MMI_BOOL int_result;

    event_data = (srv_sms_event_update_struct *)OslMalloc(sizeof(srv_sms_event_update_struct));

    /* Get Old Msg Info */
    srv_sms_btmapc_get_msg_info(&event_data->old_msg_info, msg_id);

    msg_node = srv_sms_btmapc_get_msg_node(msg_id);
    
    if (update_cntx->update_flag & SRV_SMS_PARA_STATUS)
    {
        srv_sms_btmapc_int_msg_data_struct *msg_data;
        msg_data = CNTX_GET_HD_DATA(update_cntx);
        msg_node->status = (msg_node->status & SRV_SMS_STATUS_UNSUPPORTED) | msg_data->status;
    }
    /* Set Event Data For Message Change */
    event_data->msg_id = msg_id;
    event_data->change_para_flag = update_cntx->update_flag;
    srv_sms_btmapc_get_msg_info(&event_data->new_msg_info, msg_id);
    /* Exec Message Update Interrupt Event */
    int_result = srv_sms_btmapc_exec_interrupt_event(EVT_ID_SRV_SMS_BTMAPC_UPDATE_MSG, event_data);

    srv_sms_btmapc_cntx_callback(
        update_cntx,
        MMI_TRUE,
        SRV_SMS_CAUSE_NO_ERROR,
        &change_status_cb_data);

    if (!int_result)
    {
        /* Emit Update Event */
        srv_sms_btmapc_emit_event(EVT_ID_SRV_SMS_BTMAPC_UPDATE_MSG, event_data);
    }

    OslMfree(event_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_update_msg_check_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_btmapc_update_msg_check_data(
                    U16 msg_id,
                    srv_sms_btmapc_int_msg_data_struct* msg_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        srv_sms_status_enum msg_status;
        srv_sms_mti_enum msg_mti;

        msg_status = srv_sms_btmapc_get_msg_status(msg_id);
        msg_mti = srv_sms_btmapc_status_to_mti(msg_status);

        if (msg_data->para_flag & SRV_SMS_PARA_STATUS)
        {
            srv_sms_mti_enum mti;

            mti = srv_sms_btmapc_status_to_mti(msg_data->status);

            if (mti != msg_mti)
            {
                result = MMI_FALSE;
                break;
            }
        }

        if ((msg_data->para_flag & SRV_SMS_PARA_MSG_REF) &&
            (msg_mti != SRV_SMS_MTI_SUBMIT))
        {
            result = MMI_FALSE;
            break;
        }
    } while (0);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_msg_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_btmapc_update_msg_init(
                srv_sms_btmapc_update_cntx_struct* update_cntx,
                U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_int_msg_data_struct *msg_data = (srv_sms_btmapc_int_msg_data_struct*)CNTX_GET_HD_DATA(update_cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    update_cntx->curr_index = 0;
    update_cntx->msg_id = msg_id;
    update_cntx->update_flag = msg_data->para_flag;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_msg_deinit
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
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
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_msg_ext
 * DESCRIPTION
 *  1. Delete an existed message;
 *  2. If the message is not existed, the result is FALSE;
 *  3. The Callback Action Data Structure is srv_sms_delete_msg_cb_struct;
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
SMS_HANDLE srv_sms_btmapc_delete_msg_detail(
                        U16 msg_id,
                        MMI_BOOL is_backgroud,
                        srv_sms_btmapc_delete_cntx_struct *delete_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
    WCHAR file_name[SRV_SMS_BTMAPC_MAX_PATH_LEN];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
    error_cause = srv_sms_btmapc_check_common_msg_error(msg_id, SRV_SMS_ACTION_DELETE);
    if (error_cause == SRV_SMS_CAUSE_NO_ERROR && delete_cntx)
    {
        srv_sms_btmapc_get_msg_name(msg_id, MMI_FALSE, file_name);
        if(FS_Delete(file_name) < 0)
        {
            error_cause = SRV_SMS_CAUSE_FS_ERROR;
        }
        srv_sms_btmapc_callback(
            SRV_SMS_ACTION_DELETE,
            MMI_TRUE,
            error_cause,
            NULL,
            delete_cntx,
            srv_sms_btmapc_delete_msg_ext_callback);
    }

    if (error_cause != SRV_SMS_CAUSE_NO_ERROR)
    {
        srv_sms_btmapc_cntx_callback(
            delete_cntx,
            MMI_FALSE,
            error_cause,
            NULL);
    }
    return (SMS_HANDLE)delete_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_msg_ext_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_btmapc_delete_msg_ext_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_delete_cntx_struct *delete_cntx;
    MMI_BOOL result = callback_data->result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    delete_cntx = (srv_sms_btmapc_delete_cntx_struct*)callback_data->user_data;

    if (result)
    {
        srv_sms_delete_msg_cb_struct del_msg_cb_data;
        srv_sms_event_delete_struct *event_data = NULL;
        U16 deleted_msg_id = delete_cntx->msg_id;
        MMI_BOOL int_result = MMI_FALSE;

        /* Delete Message Node */
        srv_sms_btmapc_delete_msg_node(deleted_msg_id);
        if (CNTX_IS_ABORT(delete_cntx))
        {
            result = MMI_FALSE;
        }

        srv_sms_btmapc_cntx_callback(
            delete_cntx,
            result,
            callback_data->cause,
            &del_msg_cb_data);

        if (int_result == MMI_FALSE)
        {
            /* Emit Message Delete Event */
            srv_sms_btmapc_emit_event(EVT_ID_SRV_SMS_BTMAPC_DEL_MSG, event_data);
        }

        if (event_data != NULL)
        {
            OslMfree(event_data);
        }
    }
    else
    {
        if (CNTX_IS_ABORT(delete_cntx))
        {
            result = MMI_TRUE;
        }

        srv_sms_btmapc_cntx_callback(
            delete_cntx,
            result,
            callback_data->cause,
            NULL);
    }
}




/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_msg_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_sms_cause_enum srv_sms_btmapc_delete_msg_init(
                            srv_sms_btmapc_delete_cntx_struct* delete_cntx,
                            U16 msg_id,
                            MMI_BOOL is_background)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_MSG_INIT);

    delete_cntx->curr_index = 0;
    delete_cntx->msg_id = msg_id;
    delete_cntx->is_background = is_background;

    return SRV_SMS_CAUSE_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_msg_bitmap_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_btmapc_delete_msg_bitmap_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_delete_bitmap_cntx_struct *del_bitmap_cntx;
    srv_sms_delete_msg_bitmap_cb_struct del_bitmap_cb_data;
    MMI_BOOL result = callback_data->result;
    MMI_BOOL is_finished = MMI_TRUE;
    U16 curr_msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    del_bitmap_cntx = (srv_sms_btmapc_delete_bitmap_cntx_struct*)callback_data->user_data;
    curr_msg_id = del_bitmap_cntx->curr_msg_id;

    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_MSG_BITMAP_CALLBACK, callback_data->result);

    if (CNTX_IS_ABORT(del_bitmap_cntx))
    {
        curr_msg_id = srv_sms_btmapc_get_bitmap_index(
                        (U16)(curr_msg_id + 1),
                        del_bitmap_cntx->msg_bitmap,
                        del_bitmap_cntx->bitmap_size);

        /* If all SMSs are deleted, the abort result is false */
        if (curr_msg_id == SRV_SMS_INVALID_BITMAP_INDEX)
        {
            result = MMI_FALSE;
        }
        else
        {
            result = MMI_TRUE;
        }
    }
    else
    {
        if (result)
        {
            /* Set Deleted Bitmap For Callback */
            srv_sms_btmapc_set_bitmap_index(curr_msg_id, del_bitmap_cntx->deleted_msg_bitmap);
            del_bitmap_cntx->deleted_num++;

            /* Get Next Msg ID */
            curr_msg_id = srv_sms_btmapc_get_bitmap_index(
                            (U16)(curr_msg_id + 1),
                            del_bitmap_cntx->msg_bitmap,
                            del_bitmap_cntx->bitmap_size);

            if (curr_msg_id != SRV_SMS_INVALID_BITMAP_INDEX)
            {
                is_finished = MMI_FALSE;

                del_bitmap_cntx->curr_msg_id = curr_msg_id;

                srv_sms_btmapc_delete_msg(
                    curr_msg_id,
                    srv_sms_btmapc_delete_msg_bitmap_callback,
                    del_bitmap_cntx);
            }
        }
    }

    if (is_finished)
    {
        U8 *deleted_msg_bitmap;

        deleted_msg_bitmap = del_bitmap_cntx->deleted_msg_bitmap;

        del_bitmap_cb_data.deleted_num = del_bitmap_cntx->deleted_num;
        del_bitmap_cb_data.bitmap_size = del_bitmap_cntx->bitmap_size;
        del_bitmap_cb_data.deleted_msg_bitmap = deleted_msg_bitmap;

        srv_sms_btmapc_cntx_callback(
            del_bitmap_cntx,
            result,
            callback_data->cause,
            &del_bitmap_cb_data);

        OslMfree(deleted_msg_bitmap);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_change_status_update_next
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_btmapc_change_status_update_next(srv_sms_btmapc_change_status_cntx_struct* change_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_msg_node_struct *msg_node;
    srv_sms_event_update_struct *event_data;
    srv_sms_change_msg_status_cb_struct change_status_cb_data;
    U16 msg_id = change_cntx->msg_id;
    MMI_BOOL int_result;

    event_data = (srv_sms_event_update_struct *)OslMalloc(sizeof(srv_sms_event_update_struct));

    /* Get Old Msg Info */
    srv_sms_btmapc_get_msg_info(&event_data->old_msg_info, msg_id);

    msg_node = srv_sms_btmapc_get_msg_node(msg_id);
    /* Update the status in the msg list */
    msg_node->status = (msg_node->status & SRV_SMS_STATUS_UNSUPPORTED) | change_cntx->status;

    /* Set Event Data For Message Change */
    event_data->msg_id = msg_id;
    event_data->change_para_flag = SRV_SMS_PARA_STATUS;;
    srv_sms_btmapc_get_msg_info(&event_data->new_msg_info, msg_id);
    /* Exec Message Update Interrupt Event */
    int_result = srv_sms_btmapc_exec_interrupt_event(EVT_ID_SRV_SMS_BTMAPC_UPDATE_MSG, event_data);

    srv_sms_btmapc_cntx_callback(
        change_cntx,
        MMI_TRUE,
        SRV_SMS_CAUSE_NO_ERROR,
        &change_status_cb_data);

    if (int_result == MMI_FALSE)
    {
        /* Emit Update Event */
        srv_sms_btmapc_emit_event(EVT_ID_SRV_SMS_BTMAPC_UPDATE_MSG, event_data);
    }
    OslMfree(event_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_change_msg_status_init
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
srv_sms_cause_enum srv_sms_btmapc_change_msg_status_init(
                            srv_sms_btmapc_change_status_cntx_struct* change_cntx,
                            U16 msg_id,
                            srv_sms_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    change_cntx->curr_index = 0;
    change_cntx->msg_id = msg_id;
    change_cntx->status = status;

    return SRV_SMS_CAUSE_NO_ERROR;
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_query_msg_attribute
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_btmapc_query_msg_attribute(
                U16 *msg_id_list,
                U16 *msg_num,
                srv_sms_query_enum query_flag,
                srv_sms_query_struct *query_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 total_num = *msg_num;
    U16 num_count = 0;
    U16 msg_id;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_QUERY_MSG_ATTRIBUTE, query_flag);

    for (i = 0; i < total_num; i++)
    {
        msg_id = msg_id_list[i];
    
        if (srv_sms_btmapc_query_is_match(msg_id, query_flag, query_data) == MMI_TRUE)
        {
            msg_id_list[num_count++] = msg_id;
        }
    }

    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_QUERY_MSG_ATTRIBUTE_1, num_count);

    *msg_num = num_count;
}



/*****************************************************************************
 * FUNCTION
 *  srv_sms_query_is_match
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_btmapc_query_is_match(
                    U16 msg_id,
                    srv_sms_query_enum query_flag,
                    srv_sms_query_struct *query_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_msg_node_struct *curr_node = &srv_sms_btmapc_msg_list[msg_id];
    MMI_BOOL result = MMI_FALSE;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (query_flag)
    {
        case SRV_SMS_QUERY_STATUS:
        {
            srv_sms_status_enum status = (srv_sms_status_enum)curr_node->status;
            if (status & query_data->status)
            {
                result = MMI_TRUE;
            }
            break;
        }

        case SRV_SMS_QUERY_MTI:
            if (curr_node->mti == query_data->mti)
            {
                result = MMI_TRUE;
            }
            break;

        case SRV_SMS_QUERY_STORAGE_TYPE:
            if (curr_node->storage_type == query_data->storage_type)
            {
                result = MMI_TRUE;
            }
            break;

        case SRV_SMS_QUERY_PID:
            if (curr_node->pid == query_data->pid)
            {
                result = MMI_TRUE;
            }
            break;

        case SRV_SMS_QUERY_TIMESTAMP:
        {
            U16 upper_time_int;
            U16 lower_time_int;

            upper_time_int = applib_dt_mytime_2_utc_sec((applib_time_struct *)&query_data->upper_time, MMI_FALSE);
            lower_time_int = applib_dt_mytime_2_utc_sec((applib_time_struct *)&query_data->lower_time, MMI_FALSE);
        
            if ((upper_time_int >= curr_node->timestamp) && (lower_time_int <= curr_node->timestamp))
            {
                result = MMI_TRUE;
            }
            break;
        }

        case SRV_SMS_QUERY_NUMBER:
        {
            U16 ucs2_num[SRV_SMS_MAX_ADDR_LEN + 1];

            mmi_asc_to_ucs2((S8*)ucs2_num, curr_node->number);

            if (srv_phb_compare_number(ucs2_num, (U16*)query_data->number) == MMI_TRUE)
            {
                result = MMI_TRUE;
            }
            break;
        }
        default:
            result = MMI_TRUE;
            break;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sort_msg_timestamp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_btmapc_sort_msg_timestamp(
                U16 *msg_id_array,
                U16 msg_num,
                srv_sms_order_enum order_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SORT_MSG_TIMESTAMP, msg_num, order_flag);

    switch (order_flag)
    {
        case SRV_SMS_ORDER_ASC:
            srv_sms_btmapc_sort_msg_timestamp_asc(msg_id_array, msg_num);
            break;

        case SRV_SMS_ORDER_DESC:
        case SRV_SMS_ORDER_DEFAULT:
        default:
            srv_sms_btmapc_sort_msg_timestamp_desc(msg_id_array, msg_num);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sort_msg_timestamp_asc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_btmapc_sort_msg_timestamp_asc(U16 *msg_id_array, U16 msg_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((msg_id_array != NULL) && (msg_num > 1))
    {
        for (i = 0; i < (msg_num - 1); i++)
        {
            U16 temp_msg_id = msg_id_array[i];
            U16 min_index = i;
            U32 min_time;

            min_time = srv_sms_btmapc_get_msg_timestamp_utc_sec(temp_msg_id);
        
            for (j = i + 1; j < msg_num; j++)
            {
                U32 curr_time;

                curr_time = srv_sms_btmapc_get_msg_timestamp_utc_sec(msg_id_array[j]);

                if (curr_time < min_time)
                {
                    min_time = curr_time;
                    min_index = j;
                }   
            }

            if (min_index != i)
            {
                msg_id_array[i] = msg_id_array[min_index];
                msg_id_array[min_index] = temp_msg_id;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sort_msg_timestamp_desc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_btmapc_sort_msg_timestamp_desc(U16 *msg_id_array, U16 msg_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((msg_id_array != NULL) && (msg_num > 1))
    {
        for (i = 0; i < (msg_num - 1); i++)
        {
            U16 temp_msg_id = msg_id_array[i];
            U16 max_index = i;
            U32 max_time;

            max_time = srv_sms_btmapc_get_msg_timestamp_utc_sec(temp_msg_id);
        
            for (j = i + 1; j < msg_num; j++)
            {
                U32 curr_time;

                curr_time = srv_sms_btmapc_get_msg_timestamp_utc_sec(msg_id_array[j]);

                if (curr_time > max_time)
                {
                    max_time = curr_time;
                    max_index = j;
                }   
            }

            if (max_index != i)
            {
                msg_id_array[i] = msg_id_array[max_index];
                msg_id_array[max_index] = temp_msg_id;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_msg_into_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_btmapc_add_msg_into_list(
            U16 *msg_id_list,
            U16 curr_num,
            U16 max_num,
            U16 add_msg_id,
            srv_sms_sort_enum sort_flag,
            srv_sms_order_enum order_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_MSG_INTO_LIST, curr_num, max_num, add_msg_id, sort_flag, order_flag);

    switch (sort_flag)
    {
        case SRV_SMS_SORT_TIMESTAMP:
        {
            switch (order_flag)
            {
                case SRV_SMS_ORDER_ASC:
                    break;

                case SRV_SMS_ORDER_DEFAULT:
                case SRV_SMS_ORDER_DESC:
                default:
                    srv_sms_btmapc_add_msg_into_list_by_desc_timestap(
                        msg_id_list,
                        curr_num,
                        max_num,
                        add_msg_id);
                    break;
            }    
            break;
        }

        default:
            break;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_msg_into_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_btmapc_delete_msg_from_list(
            U16 *msg_id_list,
            U16 msg_num,
            U16 del_msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_MSG_FROM_LIST, msg_num, del_msg_id);

    if (msg_num > 0)
    {
        for (i = 0; i < msg_num; i++)
        {
            if (msg_id_list[i] == del_msg_id)
            {
                result = MMI_TRUE;
                break;
            }
        }

        if (result == MMI_TRUE)
        {
            for (; i < (msg_num - 1); i++)
            {
                msg_id_list[i] = msg_id_list[i + 1];
            }

            msg_id_list[msg_num - 1] = SRV_SMS_INVALID_MSG_ID;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_msg_into_list_by_desc_timestap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_btmapc_add_msg_into_list_by_desc_timestap(
                U16 *msg_id_list,
                U16 curr_num,
                U16 max_num,
                U16 add_msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_MSG_INTO_LIST_BY_DESC_TIMESTAP);

    if (curr_num < max_num)
    {
        S32 i;
        S32 j;
        U32 new_timestamp = srv_sms_btmapc_get_msg_timestamp_utc_sec(add_msg_id);

        for (i = 0; i < (S32)curr_num; i++)
        {
            U32 comp_timestamp;

            comp_timestamp = srv_sms_btmapc_get_msg_timestamp_utc_sec(msg_id_list[i]);

            if (new_timestamp > comp_timestamp)
            {
                break;
            }
        }

        for (j = (curr_num - 1); j >= (S32)i; j--)
        {
            msg_id_list[j + 1] = msg_id_list[j];
        }

        msg_id_list[i] = add_msg_id;
    }
}

S32 srv_sms_btmapc_sync_read_record(srv_sms_btmapc_op_struct *read_cntx, CHAR *buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 size;
    U32 Offset;
    srv_sms_btmapc_file_index_enum file_index;        
    U32 table_index;
    srv_sms_btmapc_file_entry_struct *record;
    WCHAR ucs2_buff[SRV_SMS_BTMAPC_MAX_PATH_LEN];
    FS_HANDLE hd = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/
    if(buff != NULL )
    {
        file_index = read_cntx->file_index;
        table_index = srv_sms_btmapc_get_table_index(file_index);
        if(table_index != SRV_SMS_BTMAPC_OP_INVALID_INDEX)
        {
            record = &sms_btmapc_file_mgr_common_table[table_index];
            if(read_cntx->start_record_id < record->record_number)
            {
                srv_sms_btmapc_get_file_name(read_cntx->file_index, MMI_FALSE, ucs2_buff);
                hd = FS_Open((U16*)ucs2_buff, FS_READ_ONLY);
                Offset = read_cntx->start_record_id * record->record_size + sizeof(SMS_BTMAPC_CHECKSUM);
                if( hd >= 0)
                {
                    FS_Seek(hd, Offset, FS_FILE_BEGIN);
                    FS_Read(hd, buff, record->record_size, &size);
                    if(record->record_size == size)
                    {
                        return SRV_SMS_BTMAPC_OP_FS_SUCC;
                    }
                    else
                    {
                        FS_Close(hd);
                        return SRV_SMS_BTMAPC_OP_FS_ERROR;
                    }
                }
                else
                {
                    return SRV_SMS_BTMAPC_OP_FS_ERROR;
                }
            }
            else
            {
                return SRV_SMS_BTMAPC_OP_INVALID_PARA;
            }
        }
        else
        {
            return SRV_SMS_BTMAPC_OP_INVALID_PARA;
        }
    }
    else
    {
        return SRV_SMS_BTMAPC_OP_INVALID_PARA;
    }
}


S32 srv_sms_btmapc_sync_write_record(srv_sms_btmapc_op_struct *read_cntx, CHAR *buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 size;
    U32 Offset;
    S32 result;
    srv_sms_btmapc_file_index_enum file_index;
    U32 table_index;
    SMS_BTMAPC_CHECKSUM checksum;
    srv_sms_btmapc_file_entry_struct *record;
    WCHAR ucs2_buff[SRV_SMS_BTMAPC_MAX_PATH_LEN];
    FS_HANDLE hd = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/
    if(buff != NULL )
    {
        file_index = read_cntx->file_index;
        table_index = srv_sms_btmapc_get_table_index(file_index);
        if(table_index != SRV_SMS_BTMAPC_OP_INVALID_INDEX)
        {
            record = &sms_btmapc_file_mgr_common_table[table_index];
            if(read_cntx->start_record_id < record->record_number)
            {
                srv_sms_btmapc_get_file_name(file_index, MMI_FALSE, ucs2_buff);
                hd = FS_Open((U16*)ucs2_buff, FS_READ_WRITE);
                Offset = read_cntx->start_record_id * record->record_size + sizeof(SMS_BTMAPC_CHECKSUM);
                if( hd >= 0)
                {
                    FS_Seek(hd, Offset, FS_FILE_BEGIN);
                    result = FS_Write(hd, buff, record->record_size, &size);
                    if (result >= 0 )
                    {
                        checksum = srv_sms_btmapc_checksum_compute_by_hd(hd, sizeof(SMS_BTMAPC_CHECKSUM));
                        FS_Seek(hd, 0, FS_FILE_BEGIN);
                        result = FS_Write(hd, &checksum, sizeof(SMS_BTMAPC_CHECKSUM), &size);
                    }
                    else
                    {
                        FS_Close(hd);
                        return SRV_SMS_BTMAPC_OP_FS_ERROR;
                    }
                }
                else
                {
                    return SRV_SMS_BTMAPC_OP_FS_ERROR;
                }
            }
        }
        else
        {
            return SRV_SMS_BTMAPC_OP_INVALID_PARA;
        }
    }
    return SRV_SMS_BTMAPC_OP_INVALID_PARA;
}


U32 srv_sms_btmapc_get_table_index(srv_sms_btmapc_file_index_enum file_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_file_entry_struct *record;
    U32 i;
    U32 total;
    U32 index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total = sizeof(sms_btmapc_file_mgr_common_table)/sizeof(srv_sms_btmapc_file_entry_struct);
    for(i = 0; i < total; i++)
    {
        record = &sms_btmapc_file_mgr_common_table[i];
        if(record->file_index == file_index)
        {
            index = i;
            break;
        }
    }

    if(i == total)
    {
        index = SRV_SMS_BTMAPC_OP_INVALID_INDEX;
    }

    return index;   
}

static SMS_BTMAPC_CHECKSUM srv_sms_btmapc_checksum_compute_by_hd(FS_HANDLE hd, U32 position)
{
       /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SMS_BTMAPC_CHECKSUM checksum = 0xffff;
    U8 *buf;
    U32 i, read;
    S32 retval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    buf = (U8*) get_ctrl_buffer(2048);
    FS_Seek(hd, position, FS_FILE_BEGIN);

    while (MMI_TRUE)
    {
        retval = FS_Read(hd, buf, 2048, &read);
        if (retval < FS_NO_ERROR || read == 0)
        {
            break;
        }

        for (i = 0; i < read; i++)
        {
            checksum = (SMS_BTMAPC_CHECKSUM)srv_sms_btmapc_checksum_fcs(checksum, buf[i]);
        }
    }

    free_ctrl_buffer((void*)buf);
    return checksum;
}


srv_sms_status_enum srv_sms_btmapc_get_msg_status(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_btmapc_is_msg_exist(msg_id) == MMI_TRUE)
    {
        srv_sms_btmapc_msg_node_struct *msg_node = &srv_sms_btmapc_msg_list[msg_id];
        status = (srv_sms_status_enum)msg_node->status;
    }
    else
    {
        status = SRV_SMS_STATUS_NONE;
    }

    return status;
}



srv_sms_cause_enum srv_sms_btmapc_check_common_msg_error(U16 msg_id, srv_sms_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_btmapc_is_msg_exist(msg_id) == MMI_FALSE)
    {
        error_cause = SRV_SMS_CAUSE_INVALID_MEM_INDEX;
    }
    else if (srv_sms_btmapc_check_msg_op_conflict(msg_id, action) == MMI_TRUE)
    {
        error_cause = SRV_SMS_CAUSE_OP_CONFLICT;
    }
    else
    {
        error_cause = SRV_SMS_CAUSE_NO_ERROR;
    }

    return error_cause;
}


MMI_BOOL srv_sms_btmapc_is_msg_exist(U16 msg_id)
{
    if((msg_id < SRV_SMS_BTMAPC_MAX_SMS_ENTRY) &&
       (srv_sms_btmapc_msg_list[msg_id].status != SRV_SMS_STATUS_NONE))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


void srv_sms_btmapc_str_to_utctime(applib_time_struct * utc_time, const char * str)
{
    char year[5];
    char month[3];
    char day[3];
    char hour[3];
    char min[3];
    char sec[3];

    memcpy(year, &str[0], 4);
    year[4] = 0;
    memcpy(month, &str[4], 2);
    month[2] = 0;
    memcpy(day, &str[6], 2);
    day[2] = 0;
    memcpy(hour, &str[9], 2);
    hour[2] = 0;
    memcpy(min, &str[11], 2);
    min[2] = 0;
    memcpy(sec, &str[13], 2);
    sec[2] = 0;

    utc_time->nYear = atoi(year);
    utc_time->nMonth = atoi(month);
    utc_time->nDay = atoi(day);
    utc_time->nHour = atoi(hour);
    utc_time->nMin = atoi(min);
    utc_time->nSec = atoi(sec);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_msg_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sms_btmapc_send_msg_callback(SMS_HANDLE sms_handle, MMI_BOOL result, srv_sms_cause_enum cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_handle_struct *sms_hd = (srv_sms_btmapc_handle_struct*) sms_handle;
    srv_sms_btmapc_send_handle_struct *hd_data = (srv_sms_btmapc_send_handle_struct*) sms_hd->hd_data;
    SrvSmsCallbackFunc callback_func = hd_data->callback_func;
    srv_sms_callback_struct callback_data;
    srv_sms_send_msg_cb_struct send_cb_data;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    send_cb_data.report_id = hd_data->report_id;
    send_cb_data.total_seg = hd_data->total_segment;

    for (i = 0; i < hd_data->total_segment; i++)
    {
        send_cb_data.msg_ref[i] = hd_data->msg_ref[i];
    }

    callback_data.result = result;
    callback_data.cause = cause;
    callback_data.action = SRV_SMS_ACTION_SEND;
    callback_data.user_data = hd_data->user_data;
    callback_data.action_data = &send_cb_data;

    if (hd_data->send_type != SRV_SMS_BG_SAVE_SEND)
    {
        srv_sms_btmapc_free_send_handle(sms_handle);
    }

    if (callback_func != NULL)
    {
        callback_func(&callback_data);
    }
}


void srv_sms_btmapc_free_send_handle(SMS_HANDLE sms_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    srv_sms_btmapc_handle_struct *send_hd;
    srv_sms_btmapc_send_handle_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(sms_handle != NULL);

    send_hd = (srv_sms_btmapc_handle_struct*) sms_handle;
    hd_data = (srv_sms_btmapc_send_handle_struct*)send_hd->hd_data;

    MMI_ASSERT(hd_data != NULL);
    
    hd_data->pdu_list[0] = NULL;

    OslMfree(hd_data);
    hd_data = NULL;

    OslMfree(send_hd);
    send_hd = NULL;
}


SMS_HANDLE srv_sms_btmapc_get_send_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_handle_struct *sms_handle;
    srv_sms_btmapc_send_handle_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hd_data = OslMalloc(sizeof(srv_sms_btmapc_send_handle_struct));

    memset((S8*) hd_data, 0, sizeof(srv_sms_btmapc_send_handle_struct));

    memset((S8*) &(hd_data->msg_data), 0, sizeof(srv_sms_btmapc_int_msg_data_struct));

    hd_data->reply_msg_id = SRV_SMS_INVALID_MSG_ID;
    hd_data->msg_id = SRV_SMS_INVALID_MSG_ID;
    hd_data->action_id = SRV_SMS_BTMAPC_ACTION_INVALID_ID;
    hd_data->sim_id = SRV_SMS_SIM_1;
    hd_data->send_type = SRV_SMS_BG_SEND;

    hd_data->msg_data.sim_id = SRV_SMS_SIM_1;
    hd_data->msg_data.is_allow_num_emtpy = MMI_FALSE;
    hd_data->msg_data.is_allow_sc_emtpy = MMI_FALSE;
    hd_data->msg_data.is_asc_content = MMI_FALSE;
    hd_data->msg_data.status = SRV_SMS_STATUS_UNSENT;
#ifdef __SRV_SMS_MULTI_ADDR__
    hd_data->msg_data.addr_num = 0;
#endif

    hd_data->is_abort = MMI_FALSE;
    hd_data->is_use_action = MMI_FALSE;

#ifdef __SRV_SMS_DELIVERY_STATUS__
    hd_data->report_id = SRV_SMS_INVALID_MSG_ID;
#endif /* __SRV_SMS_DELIVERY_STATUS__ */

    sms_handle = OslMalloc(sizeof(srv_sms_btmapc_handle_struct));
    sms_handle->action = SRV_SMS_ACTION_SEND;
    sms_handle->hd_data = (void*) hd_data;

    return (SMS_HANDLE)sms_handle;
}
#endif /* __SRV_SMS_BTMAPC__ */
#endif /* __MOD_SMSAL__ */

