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
 *  SmsConvertSrv.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service Converter API Internal Header File
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
#ifndef __SRV_SMS_CONVERTER_SRV_H__
#define __SRV_SMS_CONVERTER_SRV_H__

#include "kal_general_types.h"
#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
#include "ps_public_struct.h"

#include "SmsSrvGProt.h"
#include "SmsBtMapCSrvProt.h"
#include "Smslib.h"
#include "ps_public_utility.h"
#include "ems.h"


/* Reference TS 11.11 Clause 10.5.3 */
typedef enum
{
    SPDU_STATUS_FREE_SPACE  = 0x00,
    SPDU_STATUS_USED_SPACE  = 0x01,
    SPDU_STATUS_UNREAD      = 0x03,
    SPDU_STATUS_READ        = 0x01,
    SPDU_STATUS_SENT        = 0x05,
    SPDU_STATUS_UNSENT      = 0x07,
    /* Internal Defination, just for ME Storage */
    SPDU_STATUS_DRAFT       = 0x27
}srv_sms_btmapc_spdu_status_enum;

typedef void(*GetPduListFunc)(U8** pdu_list, U8 pdu_total, void* user_data);

extern U32 srv_sms_btmapc_scts_to_utc_sec(U8 scts[]);
extern void srv_sms_btmapc_utc_sec_to_scts(U8 scts[], U32 utc_sec);
extern void srv_sms_btmapc_scts_to_mytime(MYTIME* mytime, U8 scts[]);
extern void srv_sms_btmapc_mytime_to_scts(U8 scts[], MYTIME* mytime);

extern U8 srv_sms_btmapc_msg_status_to_spdu_status(srv_sms_status_enum msg_status);
extern srv_sms_status_enum srv_sms_btmapc_spdu_status_to_msg_status(U8 pdu_status, srv_sms_storage_enum storage_type);

extern srv_sms_cause_enum srv_sms_btmapc_convert_msg_data_to_pdu(
                            U8** pdu_list,
                            U8* pdu_len_list,
                            U8* total_num,
                            srv_sms_btmapc_msg_node_struct *msg_node,
                            srv_sms_btmapc_int_msg_data_struct* msg_data,
                            srv_sms_btmapc_pack_enum pack_flag,
                            srv_sms_sim_enum sim_id);

extern srv_sms_cause_enum srv_sms_btmapc_convert_msg_data_to_pdu_ext(
                            U8** pdu_list,
                            U8* pdu_len_list,
                            U8* total_num,
                            srv_sms_btmapc_msg_node_struct *msg_node,
                            srv_sms_btmapc_int_msg_data_struct* msg_data,
                            srv_sms_btmapc_pack_enum pack_flag,
                            srv_sms_sim_enum sim_id,
                            GetPduListFunc get_pdu_list_func,
                            void* user_data);

extern MMI_BOOL srv_sms_btmapc_convert_spdu_to_msg_data(
                    srv_sms_msg_data_struct* msg_data,
                    srv_sms_btmapc_spdu_struct** spdu_list,
                    U8 total_num);

extern void srv_sms_btmapc_msg_info_to_msg_data(
                srv_sms_msg_data_struct* msg_data,
                srv_sms_msg_info_struct* msg_info,
                EMSData* ems_data);

extern void srv_sms_btmapc_msg_node_to_msg_data(
                srv_sms_msg_data_struct* msg_data,
                srv_sms_btmapc_msg_node_struct* msg_node);

extern MMI_BOOL srv_sms_btmapc_get_msg_info_from_pdu(
                    srv_sms_btmapc_msg_node_struct* msg_node,
                    U8* curr_seg,
                    U8* msg_ref,
                    U8* out_pdu_len,
                    U8* pdu_raw_data);

extern MMI_BOOL srv_sms_btmapc_get_reply_path_from_pdu(
                    MMI_BOOL* reply_path,
                    char* sc_addr,
                    U8* pdu_raw_data);

extern void srv_sms_btmapc_msg_node_to_msg_info(
                srv_sms_msg_info_struct* msg_info,
                srv_sms_btmapc_msg_node_struct* msg_node);


extern MMI_BOOL srv_sms_btmapc_get_content_from_pdu(
                    char* content_buff,
                    U32 content_buff_size,
                    U8* pdu_raw_data);

extern void srv_sms_btmapc_decode_data_to_msg_node(
                srv_sms_btmapc_msg_node_struct* msg_node,
                U8* curr_seg,
                U8* msg_ref,
                smslib_general_struct* decode_data);

extern void srv_sms_btmapc_encode_spdu(
                srv_sms_btmapc_spdu_struct* spdu_data,
                srv_sms_status_enum status,
                U8* pdu_raw_data,
                U8 raw_data_size,
                srv_sms_sim_enum sim_id);
extern void srv_sms_btmapc_reset_spdu(srv_sms_btmapc_spdu_struct* spdu_data);

extern void srv_sms_btmapc_asc_addr_to_l4_number(l4c_number_struct *l4c_number, U8* asc_addr);
extern void srv_sms_btmapc_l4_number_to_asc_addr(char* asc_addr, U8 max_addr_len, l4c_number_struct *l4c_number);

extern srv_sms_mti_enum srv_sms_btmapc_status_to_mti(srv_sms_status_enum status);
extern srv_sms_dcs_enum srv_sms_btmapc_smslib_alphabet_to_dcs(smslib_alphabet_enum alphabet_type);

extern void srv_sms_btmapc_set_pdu_msg_ref(U8* pdu_data, U8 msg_ref);

extern void srv_sms_btmapc_convert_segment(
                U8 *dest_total_seg,
                U8 *dest_start_seg,
                U8 *dest_curr_seg,
                U8 src_total_seg,
                U8 src_curr_seg);
#endif /* __SRV_SMS_CONVERTER_SRV_H__ */

