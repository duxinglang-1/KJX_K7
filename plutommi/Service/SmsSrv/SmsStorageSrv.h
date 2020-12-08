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
 *  SmsStorageSrv.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service Storage Manager Internal Header File
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
 *****************************************************************************/
#ifndef __SMS_STORAGE_SRV_H__
#define __SMS_STORAGE_SRV_H__
#include "MMI_features.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "custom_mmi_default_value.h"

#include "mmi_msg_context.h"
#include "SmsSrvGProt.h"
#include "SmsProtSrv.h"
#include "Smslib.h"
#include "ps_public_utility.h"

#include "Nvram_common_defs.h"
#include "TcardSrvGprot.h"

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
#define SRV_SMS_MAX_SMS_ENTRY           (CM_SMS_MAX_ENTRY_NUM - CM_SMS_MAX_TCARD_ENTRY_NUM)
#else
#define SRV_SMS_MAX_SMS_ENTRY           CM_SMS_MAX_ENTRY_NUM
#endif


#define SRV_SMS_MAX_ME_SMS_ENTRY        CM_SMS_MAX_ME_ENTRY_NUM
#define SRV_SMS_MAX_SIM_SMS_ENTRY       CM_SMS_MAX_SIM_ENTRY_NUM

#define SRV_SMS_MAX_ADDR_ENTRY          NVRAM_EF_SRV_SMS_ADDR_TOTAL
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
#define SRV_SMS_MAX_TOTAL_SMS_ENTRY           CM_SMS_MAX_ENTRY_NUM
#define SRV_SMS_MAX_TCARD_ADDR_ENTRY          SRV_TCARD_MAX_ADDR_NUM

#endif
//#else
//#define SRV_SMS_MAX_TOTAL_SMS_ENTRY           CM_SMS_MAX_ENTRY_NUM
//#endif
/* PDU Format Message Data Structure */
typedef struct
{
    U8 total_segment;
    srv_sms_status_enum status;
    srv_sms_storage_enum storage_type;
    srv_sms_sim_enum sim_id;
    MYTIME time_stamp;
    U8 **spdu_array;
} srv_sms_msg_data_pdu_struct;

/* Read PDU Callback Data Structure */
typedef struct
{
    srv_sms_spdu_struct *spdu_data;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    srv_sms_tcard_spdu_struct *tcard_spdu_data;
#endif
} srv_sms_read_pdu_cb_struct;

/* Read PDU Format Message Callback Data Structure */
typedef struct
{
    srv_sms_msg_data_pdu_struct *msg_data;
} srv_sms_read_msg_pdu_cb_struct;

/* Add PDU Into Message Callback Data Structure */
typedef struct
{
    U16 msg_id;
    U16 pdu_id;
} srv_sms_msg_add_pdu_cb_struct;

/* Delete PDU Into Message Callback Data Structure */
typedef struct
{
    void *dummy;
} srv_sms_msg_delete_pdu_cb_struct;

/* Update PDU Into Message Callback Data Structure */
typedef struct
{
    void *dummy;
} srv_sms_msg_update_pdu_cb_struct;

typedef struct
{
    srv_sms_status_enum status;
    srv_sms_storage_enum storage_type;
    MMI_BOOL is_hidden;
    MMI_BOOL is_search_concat;
    U8 raw_data_size;
    srv_sms_sim_enum sim_id;
	U16 msg_id;
    U8* pdu_raw_data;
    smslib_general_struct* decode_data;
} srv_sms_msg_add_pdu_struct;


/* Get Msg Reply Path Info Callback Data Structure */
typedef struct
{
    MMI_BOOL reply_path;
    S8 sc_addr[SRV_SMS_MAX_ADDR_LEN + 1];
} srv_sms_get_msg_reply_path_cb_struct;

/* Find Message Data Structure */
typedef struct
{
    S8 address[SRV_SMS_MAX_ADDR_LEN + 1];
    srv_sms_mti_enum mti;
    srv_sms_storage_enum storage_type;
    srv_sms_sim_enum sim_id;
    srv_sms_pid_enum pid;

    MMI_BOOL is_check_concat;
    U8 total_seg;
    U8 not_exist_seg;
    U16 ref_num;
} srv_sms_find_msg_struct;

#ifdef __SRV_SMS_MULTI_ADDR__
typedef struct
{
    U8 status;
#ifdef __SRV_SMS_MULTI_ADDR_REPORT__
    U8 total_seg;
    U8 msg_ref[SRV_SMS_MAX_SEG];
    U16 report_id;
#endif /* __SRV_SMS_MULTI_ADDR_REPORT__ */
} srv_sms_update_addr_struct;
#endif /* __SRV_SMS_MULTI_ADDR__ */

extern MMI_BOOL srv_sms_set_msg_ext_status(U16 msg_id, U8 ext_status);
extern U8 srv_sms_get_msg_ext_status(U16 msg_id);

extern SMS_HANDLE srv_sms_get_update_handle(void);

extern void srv_sms_update_msg(
                U16 msg_id,
                SMS_HANDLE update_handle,
                SrvSmsCallbackFunc callback_func,
                void* user_data);

extern void srv_sms_read_pdu(  
                U16 pdu_id,
                SrvSmsCallbackFunc callback_func,
                void* user_data);

extern void srv_sms_msg_change_pdu_status(  
                U16 pdu_id,
                srv_sms_status_enum status,
                SrvSmsCallbackFunc callback_func,
                void* user_data);

extern void srv_sms_msg_add_pdu(
                srv_sms_msg_add_pdu_struct* add_pdu_data,
                SrvSmsCallbackFunc callback_func,
                void* user_data);

extern void srv_sms_msg_delete_pdu(
                U16 pdu_id,
                SrvSmsCallbackFunc callback_func,
                void* user_data);

extern  void srv_sms_msg_update_pdu(
                U16 pdu_id,
                srv_sms_spdu_struct *spdu_data,
                SrvSmsCallbackFunc callback_func,
                void* user_data);

extern SMS_HANDLE srv_sms_delete_msg_bg(
                    U16 msg_id,
                    SrvSmsCallbackFunc callback_func,
                    void *user_data);

extern void srv_sms_unhide_msg(U16 msg_id);

extern void srv_sms_read_msg_pdu(
                    U16 msg_id,
                    srv_sms_msg_data_pdu_struct* msg_data,
                    SrvSmsCallbackFunc callback_func,
                    void* user_data);

extern void srv_sms_get_msg_reply_path(
                U16 msg_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);

extern U16 srv_sms_find_msg(srv_sms_find_msg_struct* find_data);
extern MMI_BOOL srv_sms_is_memory_full(srv_sms_storage_enum storage_type, srv_sms_sim_enum sim_id);

extern MMI_BOOL srv_sms_add_msg_into_list(
                    U16 *msg_id_list,
                    U16 curr_num,
                    U16 max_num,
                    U16 add_msg_id,
                    srv_sms_sort_enum sort_flag,
                    srv_sms_order_enum order_flag);
extern MMI_BOOL srv_sms_delete_msg_from_list(
                    U16 *msg_id_list,
                    U16 msg_num,
                    U16 del_msg_id);

extern void srv_sms_storage_init(void);
extern void srv_sms_init_ems(void);
extern void srv_sms_list_init(void);

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
extern void srv_sms_tcard_list_init(void);
#endif

#ifdef __SRV_SMS_DELIVERY_STATUS__
extern void srv_sms_update_sr_status(
                char* number,
                U8 msg_ref,
                srv_sms_sim_enum sim_id,
                srv_sms_sr_status_enum tp_st,
                SrvSmsCallbackFunc callback_func,
                void* user_data);
#endif /* __SRV_SMS_DELIVERY_STATUS__ */

#ifdef __SRV_SMS_MULTI_ADDR__
extern void srv_sms_update_msg_ext_addr(
                U16 msg_id,
                U16 ext_addr_index,
                srv_sms_update_addr_struct* update_info);
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
extern void srv_sms_update_tcard_msg_ext_addr(
                U16 msg_id,
                U16 ext_addr_index,
                srv_sms_update_addr_struct* update_info);

#endif
#endif /* __SRV_SMS_MULTI_ADDR__ */

#ifdef __SRV_SMS_RESEND_COUNT__
extern U8 srv_sms_get_msg_resend_count(U16 msg_id);
#endif /* __SRV_SMS_RESEND_COUNT__ */

extern U16 srv_sms_query_msg_int(
                srv_sms_query_struct *query_data,
                U16* msg_list,
                U16 list_size);

#endif /* __SMS_STORAGE_SRV_H__ */
