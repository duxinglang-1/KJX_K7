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
 *  SmsBtMapCSrvGProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service Global prototype declaration
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
 *
 * removed!
 * removed!
 *
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#ifndef __SRV_SMS_BTMAPC_GPROT_H__
#define __SRV_SMS_BTMAPC_GPROT_H__

#ifndef __SRV_SMS_BTMAPC_TEST__
#define __SRV_SMS_BTMAPC_TEST__
#endif

#ifdef __BT_MAP_CLIENT__
#define __SRV_SMS_BTMAPC__
#endif

#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "custom_mmi_default_value.h"
#include "ps_public_enum.h"
#include "stack_config.h"
#include "customer_ps_inc.h"
#include "nvram_common_defs.h"
#include "mmi_rp_srv_sms_def.h"
#include "SmsSrvGprot.h"

typedef enum
{
    SRV_SMS_BTMAPC_BOX_NONE         = 0x00,    /* None */
    SRV_SMS_BTMAPC_BOX_INBOX        = 0x01,    /* Inbox, listed all SMS received from network */
    SRV_SMS_BTMAPC_BOX_OUTBOX       = 0x02,    /* Outbox, listed all SMS sent to network, (or to be sent to network if don't support Unsent list) */
    SRV_SMS_BTMAPC_BOX_DRAFTS       = 0x04,    /* Drafts, listed all draft SMS */
    SRV_SMS_BTMAPC_BOX_UNSENT       = 0x08,    /* Unsent, listed all SMS to be sent to network, and they have been sent failed once */
    SRV_SMS_BTMAPC_BOX_DELETED      = 0x10,
    SRV_SMS_BTMAPC_BOX_RESERVED     = 0x20
} srv_sms_btmapc_box_enum;


/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_init
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  SMS_HANDLE
 *****************************************************************************/
void srv_sms_btmapc_init(void);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_connect
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  SMS_HANDLE
 *****************************************************************************/

S32 srv_sms_btmapc_connect(
          int app_id,
          SrvSmsCallbackFunc callback_func,
          void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_disconnect
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  SMS_HANDLE
 *****************************************************************************/

void srv_sms_btmapc_disconnect(
          S32 hd,
          SrvSmsCallbackFunc callback_func,
          void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_get_msg_list
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  SMS_HANDLE
 *****************************************************************************/

void srv_sms_btmapc_get_msg_list(
                MMI_BOOL is_refresh,
                srv_sms_btmapc_box_enum box_type,
                SrvSmsCallbackFunc callback_func,
                void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_read_msg
 * DESCRIPTION
 *  1. Read Message's Data, included message status, number, content and other attributes
 *     (Storage Type, SIM Card, Profile element, etc.) indicated by the flag;
 *  2. The buffer to save the content should be provided by caller.
 *  3. The Callback Action Data Structure is srv_sms_btmapc_read_msg_cb_struct;
 * PARAMETERS
 *  msg_id          :   [IN]        Message ID
 *  change_status   :   [IN]        Whether change the UNREAD Msg to READ
 *  msg_data        :   [IN/OUT]    Message Data For Filling back read data
 *  callback_func   :   [IN]        Callback Function
 *  user_data       :   [IN]        User Data
 * RETURNS
 *  SMS_HANDLE
 *****************************************************************************/
extern SMS_HANDLE srv_sms_btmapc_read_msg(
                    U16 msg_id,
                    MMI_BOOL change_status,
                    srv_sms_msg_data_struct* msg_data,
                    SrvSmsCallbackFunc callback_func,
                    void* user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_get_save_handle
 * DESCRIPTION
 *  Get a SMS_HANDLE For Saving or Updating Message
 * PARAMETERS
 *  void
 * RETURNS
 *  SMS_HANDLE
 *****************************************************************************/
extern SMS_HANDLE srv_sms_btmapc_get_save_handle(void);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_save_msg
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
 *  save_handle     :   [IN]        Save Handle
 *  callback_func   :   [IN]        Callback Function
 *  user_data       :   [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sms_btmapc_save_msg(
                SMS_HANDLE save_handle,
                SrvSmsCallbackFunc callback_func,
                void* user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_delete_msg
 * DESCRIPTION
 *  1. Delete an existed message;
 *  2. If the message is not existed, the result is FALSE;
 *  3. The Callback Action Data Structure is srv_sms_delete_msg_cb_struct;
 * PARAMETERS
 *  msg_id          :   [IN]        Message ID
 *  callback_func   :   [IN]        Callback Function
 *  user_data       :   [IN]        User Data
 * RETURNS
 *  SMS_HANDLE
 *****************************************************************************/
extern SMS_HANDLE srv_sms_btmapc_delete_msg(
                    U16 msg_id,
                    SrvSmsCallbackFunc callback_func,
                    void* user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_get_msg
 * DESCRIPTION
 *  1. get message;
 * PARAMETERS
 *  msg_id          :   [IN]        Message ID
 *  callback_func   :   [IN]        Callback Function
 *  user_data       :   [IN]        User Data
 * RETURNS
 *  SMS_HANDLE
 *****************************************************************************/

extern SMS_HANDLE srv_sms_btmapc_get_msg(
                U16 msg_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_change_msg_status
 * DESCRIPTION
 *  1. Change message's status;
 *  2. The Callback Action Data Structure is srv_sms_change_msg_status_cb_struct;
 * PARAMETERS
 *  msg_id          :   [IN]        Message ID
 *  status          :   [IN]        Destination Status
 *  callback_func   :   [IN]        Callback Function
 *  user_data       :   [IN]        User Data
 * RETURNS
 *  SMS_HANDLE
 *****************************************************************************/
extern SMS_HANDLE srv_sms_btmapc_change_msg_status(
                    U16 msg_id,
                    srv_sms_status_enum status,
                    SrvSmsCallbackFunc callback_func,
                    void* user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_query_msg
 * DESCRIPTION
 *  1. Query the messages with some properties.
 *  2. The caller can set the query_flag, and the corresponding paramenters of
 *     the propertied they wanted. The folder ID is mandatory in the current version;
 *  3. The caller also can specify the sort flag, in the current version, we only 
 *     support sorting by timestamp.
 *  4. The Callback Action Data Structure is srv_sms_query_msg_cb_struct;
 * PARAMETERS
 *  query_data      :   [IN]        Query Data
 *  callback_func   :   [IN]        Callback Function
 *  user_data       :   [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sms_btmapc_query_msg(
                srv_sms_query_struct* query_data,
                SrvSmsCallbackFunc callback_func,
                void* user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_sort_msg
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
extern void srv_sms_btmapc_sort_msg(
                U16* msg_id_array,
                U16 msg_num,
                srv_sms_sort_enum sort_flag,
                srv_sms_order_enum order_flag);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_get_msg_asc_address
 * DESCRIPTION
 *  Get Message's Address (ASCII Format)
 * PARAMETERS
 *  msg_id          :   [IN]        Message ID
 * RETURNS
 *  S8*
 *****************************************************************************/
extern const S8* srv_sms_btmapc_get_msg_asc_address(U16 msg_id);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_get_msg_address
 * DESCRIPTION
 *  Get Message's Address (ASCII Format)
 * PARAMETERS
 *  msg_id          :   [IN]        Message ID
 *  ucs2_addr_buff  :   [IN]        ucs2 address
 * RETURNS
 *  S8*
 *****************************************************************************/
extern void srv_sms_btmapc_get_msg_address(U16 msg_id, S8* ucs2_addr_buff);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_get_msg_addr_num
 * DESCRIPTION
 *  Get Message's mutli Address's number
 * PARAMETERS
 *  msg_id          :   [IN]        Message ID
 * RETURNS
 *  U16
 *****************************************************************************/
extern U16 srv_sms_btmapc_get_msg_addr_num(U16 msg_id);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_get_multi_addr
 * DESCRIPTION
 *  Get Message's Address
 * PARAMETERS
 *  addr_buff       :   [IN]        ucs2 address buffer
 *  msg_id          :   [IN]        Message ID
 * RETURNS
 *  S8*
 *****************************************************************************/
extern void srv_sms_btmapc_get_msg_multi_addr(
                WCHAR* addr_buff,
                srv_sms_status_enum* send_status,
                U16 msg_id,
                U16 addr_index);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_get_msg_content
 * DESCRIPTION
 *  Get Message's Content For List Display.
 *  This API only for SMS application Internal Using
 * PARAMETERS
 *  msg_id          :   [IN]        Message ID
 * RETURNS
 *  S8*
 *****************************************************************************/
extern const S8* srv_sms_btmapc_get_msg_content(U16 msg_id);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_get_msg_content_async
 * DESCRIPTION
 *  1. Get Message's Content (For List display) async(The Content is returned in
 *     the callback function).
 *  2. This API is only for This API only for SMS application Internal Using.
 *  3. The Callback Action Data Structure is srv_sms_get_msg_content_async_cb_struct.
 * PARAMETERS
 *  msg_id          :   [IN]        Message ID
 *  callback_func   :   [IN]        Callback Function
 *  user_data       :   [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
extern SMS_HANDLE srv_sms_btmapc_get_msg_content_async(
                    U16 msg_id,
                    SrvSmsCallbackFunc callback_func,
                    void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_get_msg_timestamp
 * DESCRIPTION
 *  Get Message's Timestamp (MTTIME Format)
 * PARAMETERS
 *  msg_id          :   [IN]        Message ID
 *  timestamp       :   [OUT]       Timestamp
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sms_btmapc_get_msg_timestamp(U16 msg_id, MYTIME* timestamp);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_get_msg_timestamp_utc_sec
 * DESCRIPTION
 *  Get Message's timestamp (UTC Second format)
 * PARAMETERS
 *  msg_id          :   [IN]        Message ID
 * RETURNS
 *  U32
 *****************************************************************************/
extern U32 srv_sms_btmapc_get_msg_timestamp_utc_sec(U16 msg_id);


/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_get_msg_pid
 * DESCRIPTION
 *  Get Message's PID (Protocol Identifier)
 * PARAMETERS
 *  msg_id      :   [IN]    Message ID
 * RETURNS
 *  srv_sms_pid_enum
 *****************************************************************************/
extern srv_sms_pid_enum srv_sms_btmapc_get_msg_pid(U16 msg_id);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_get_msg_status
 * DESCRIPTION
 *  Get Message's Status
 * PARAMETERS
 *  msg_id      :   [IN]        Message ID
 * RETURNS
 *  srv_sms_status_enum
 *****************************************************************************/
extern srv_sms_status_enum srv_sms_btmapc_get_msg_status(U16 msg_id);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_get_msg_mti
 * DESCRIPTION
 *  Get Message's MTI (Message Type Indication)
 * PARAMETERS
 *  msg_id       :   [IN]        Message ID
 * RETURNS
 *  srv_sms_mti_enum
 *****************************************************************************/
extern srv_sms_mti_enum srv_sms_btmapc_get_msg_mti(U16 msg_id);


/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_get_msg_port
 * DESCRIPTION
 *  Get Message's Destination Port Number
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 * RETURNS
 *  U16
 *****************************************************************************/
extern U16 srv_sms_btmapc_get_msg_port(U16 msg_id);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_get_msg_size
 * DESCRIPTION
 *  Get Message's size, only for SMS application internal using
 * PARAMETERS
 *  msg_id      :    [IN]        Message ID
 * RETURNS
 *  U16
 *****************************************************************************/
extern U16 srv_sms_btmapc_get_msg_size(U16 msg_id);


/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_is_msg_exist
 * DESCRIPTION
 *  Check Wether the message is existed
 * PARAMETERS
 *  msg_id      :    [IN]        Message ID
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sms_btmapc_is_msg_exist(U16 msg_id);


/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_get_unread_sms_num
 * DESCRIPTION
 *  Get Unread Message's number
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
extern U16 srv_sms_btmapc_get_unread_sms_num(void);


/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_get_msg_id
 * DESCRIPTION
 *  Get message ID of the message in the box list
 * PARAMETERS
 *  msg_box_type   : [IN]        Message Box List Type
 *  list_index     : [IN]        The position of message in the Box List
 * RETURNS
 *  U16
 *****************************************************************************/
extern U16 srv_sms_btmapc_get_msg_id(srv_sms_btmapc_box_enum msg_box_type, U16 list_index);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_get_list_size
 * DESCRIPTION
 *  Get number of the messages in a box list
 * PARAMETERS
 *  msg_box_type   : [IN]        Message Box List Type
 * RETURNS
 *  U16
 *****************************************************************************/
extern U16 srv_sms_btmapc_get_list_size(srv_sms_btmapc_box_enum msg_box_type);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_get_list_type
 * DESCRIPTION
 *  Get a message(with specific status, storage tpye, folder type)'s Box the Box List Type
 * PARAMETERS
 *  status         : [IN]        Message Status
 *  storage_type   : [IN]        Storage Type
 *  folder_id      : [IN]        Folder Type
 * RETURNS
 *  srv_sms_box_enum
 *****************************************************************************/
extern srv_sms_btmapc_box_enum srv_sms_btmapc_get_list_type(
                            srv_sms_status_enum status,
                            srv_sms_storage_enum storage_type,
                            srv_sms_folder_enum folder_id);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_get_msg_list_index
 * DESCRIPTION
 *  Get position (list index) and box list type of the message
 * PARAMETERS
 *  msg_box_type  :  [OUT]       Message Box List type
 *  msg_id        :  [IN]        Message ID
 * RETURNS
 *  U16
 *****************************************************************************/
extern U16 srv_sms_btmapc_get_msg_list_index(srv_sms_btmapc_box_enum* msg_box_type, U16 msg_id);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_delete_msg_list
 * DESCRIPTION
 *  1. Delete all of the messages in the Message Box List.
 *  2. The Callback Action Data Structure is srv_sms_delete_msg_list_cb_struct.
 * PARAMETERS
 *  msg_box_type    :   [IN]        Message Box List Type
 *  sim_id          :   [IN]        SIM card id
 *  callback_func   :   [IN]        Callback Function
 *  user_data       :   [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sms_btmapc_delete_msg_list(
                srv_sms_btmapc_box_enum msg_box_type,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void* user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_get_send_handle
 * DESCRIPTION
 *  1. send a new message by SMS HANDLE
 *  2. The Callers need to get a SMS send handle by API srv_sms_get_send_handle() first,
 *     then they can call the seting API (srv_sms_set_content() etc.) to set the parameters
 *     they concerned. Then Call srv_sms_send_msg()to start to send SMS.
 *  3. If Caller specify those parameters (Status, Address, Content, SIM Card, Storage Type,
 *     Profile element, we will use them, otherwise, it will use the defaut value (If the 
 *     parameters is in the SMS setting, it will use the setting's value as defaut).
 *  4. The Callback Action Data is: S8 number[SRV_SMS_MAX_ADDR_LEN + 1].
 * PARAMETERS
 *  Void
 * RETURNS
 *  SMS_HANDLE
 *****************************************************************************/
extern SMS_HANDLE srv_sms_btmapc_get_send_handle(void);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_send_msg
 * DESCRIPTION
 *  Send SMS using SMS_HANDLE
 *  This sms handle is initialized after srv_sms_get_send_handle(),
 *  Send informations are set by calling srv_sms_set_xxx().
 * PARAMETERS
 *  send_handle     :   [IN]    SMS send hanlde
 *  callback_func   :   [IN]    Callback function        
 *  user_data       :   [IN]    User data 
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sms_btmapc_send_msg(SMS_HANDLE send_handle, SrvSmsCallbackFunc callback_func, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_abort
 * DESCRIPTION
 *  1. Abort an action (Read/Send/Save, etc); 
 *     In current version, it is only can abort a read action.
 *  2. The abort is a async operation, and it may be failed. The result is returned
 *     in the callback function of the aborted action(ex. Read).
 *     If the result is FALSE, and the cause is SRV_SMS_CAUSE_ABORT. it means the
 *     abort is success. Otherwise, the abort is failed.
 *  3. The callback function of the aborted action (Read/Send/Save, etc) will be called even if abort it.
 * PARAMETERS
 *  handle  :   [IN]    Handle of an action
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sms_btmapc_abort(
                SMS_HANDLE handle,
                SrvSmsCallbackFunc callback_func,
                void* user_data);

extern MMI_BOOL srv_sms_btmapc_check_ucs2_number(char* ucs2_num);
extern U16 srv_sms_btmapc_get_sms_counter(srv_sms_sim_enum sim_id, srv_sms_count_type_enum sms_count_type);
extern MMI_BOOL srv_sms_btmapc_check_dst_number(U8 *num, U8 numLen);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_set_content
 * DESCRIPTION
 *  set content.
 *  1>  The default content will consider as UCS2 text; And its default 
 *      DCS is UCS2;
 *  2>  If set the DCS as GSM Default 7Bit, we will change the DCS to UCS2 when 
 *      the content contains UCS2 characters. But if caller specify the DCS 
 *      to UCS2, we willn't change DCS even if the content don't contain UCS2
 *      characters.
 *  3>  If you want the specify the DCS, you need to call API srv_sms_set_content_dcs()
 *      to set the DCS. 
 *  4>  For the 8Bit DCS (SRV_SMS_DCS_8BIT), must set 8bit content, the content will be considered 
 *      as binary Data.
 *  5>  For the 7Bit DCS (SRV_SMS_DCS_7BIT), must set 7Bit content buffer.
 *  6>  Content size is buffer size, size of Bytes.
 * PARAMETERS
 *  sms_handle     :   [IN]    SMS hanlde
 *  content_buff   :   [IN]    S8 content_buff[content_size + ENCODING_LENGTH], content dcs is ucs2
 *  content_size   :   [IN]    size of Bytes  
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sms_btmapc_set_content(SMS_HANDLE sms_handle, char *content_buff, U16 content_size);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_set_address
 * DESCRIPTION
 *  Set SMS send or save handle's recipient address
 * PARAMETERS
 *  sms_handle  :   [IN]    SMS hanlde
 *  ucs2_addr   :   [IN]    UCS2 Address  
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL srv_sms_btmapc_set_address(SMS_HANDLE sms_handle, char *ucs2_addr);

/*****************************************************************************
 * FUNCTION
 * srv_sms_btmapc_set_send_type
 * DESCRIPTION
 * Specify send message way. 
 * PARAMETERS
 *  sms_handle     :   [IN]    SMS hanlde
 *  type           :   [IN]    send message way      
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sms_btmapc_set_send_type(SMS_HANDLE sms_handle, srv_sms_send_type_enum type);

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_delete_msg_bitmap
 * DESCRIPTION
 *  1. Delete the messages indicated by the msg_bitmap;
 *  2. The Callback Action Data Structure is srv_sms_delete_msg_bitmap_cb_struct;
 * PARAMETERS
 *  msg_bitmap      :   [IN]        The bitmap of the Message IDs
 *  byte_size       :   [IN]        The byte number of the msg_bitmap
 *  callback_func   :   [IN]        Callback Function
 *  user_data       :   [IN]        User Data
 * RETURNS
 *  SMS_HANDLE
 *****************************************************************************/
extern SMS_HANDLE srv_sms_btmapc_delete_msg_bitmap(
                    U8 msg_bitmap[],
                    U16 byte_size,
                    SrvSmsCallbackFunc callback_func,
                    void* user_data);

#endif /* __SRV_SMS_BTMAPC_GPROT_H__ */
