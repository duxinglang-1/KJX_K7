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
 *  SmsEmsSrv.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service EMS Utility API Internal Header File
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#ifndef __SRV_SMS_EMS_SRV_H__
#define __SRV_SMS_EMS_SRV_H__

#include "kal_general_types.h"
#include "MMIDataType.h"
#include "SmsSrvGProt.h"
#include "SmsBtMapCSrvProt.h"
#include "Ems.h"


/* Pack EMSData to TP-UD Structure */
typedef struct
{
    U8 udhi;
    U8 ori_dcs;
    U8 total_seg;
    U8 *tpud[SRV_SMS_MAX_SEG];
    U8 tpud_len[SRV_SMS_MAX_SEG];
}srv_sms_btmapc_pack_struct;


/* Pack TP-UD to EMSData Structure */
typedef struct
{
    U8 fo;
    U8 total_seg;
    U8 *tpud[SRV_SMS_MAX_SEG];
    U8 tpud_len[SRV_SMS_MAX_SEG];
    U8 dcs[SRV_SMS_MAX_SEG];
    U8 ori_dcs[SRV_SMS_MAX_SEG];
}srv_sms_btmapc_unpack_struct;

extern void srv_sms_btmapc_init_ems(void);
extern U16 srv_sms_btmapc_get_curr_concat_ref_num(void);
extern U16 srv_sms_btmapc_get_and_inc_concat_ref_num(void);

extern srv_sms_cause_enum srv_sms_btmapc_convert_msg_data_to_ems(
                            EMSData* ems_data,
                            srv_sms_btmapc_int_msg_data_struct* msg_data);

extern EMSTATUS srv_sms_btmapc_pack_ems(
                    srv_sms_btmapc_pack_struct* pack_data,
                    EMSData* ems_data,
                    srv_sms_btmapc_pack_enum pack_flag);

extern void srv_sms_btmapc_unpack_ems(
                EMSData* ems_data,
                srv_sms_btmapc_unpack_struct* unpack_data,
                srv_sms_unpack_enum unpack_flag);

extern void srv_sms_btmapc_get_pack_data(srv_sms_btmapc_pack_struct* pack_data);
extern void srv_sms_btmapc_get_unpack_data(srv_sms_btmapc_unpack_struct* unpack_data);

extern U32 srv_sms_btmapc_char_to_wchar(char* out_wchar_buff, char* in_char_buff, U32 len);
extern U32 srv_sms_btmapc_wchar_to_char(char* out_char_buff, S16 *in_wchar_buff, U32 len);

extern MMI_BOOL srv_sms_btmapc_is_no_standard_string(U8* ucs2_text_buff, U16 text_len);

extern void srv_sms_btmapc_get_content_from_tpud(
                U8 *content,
                U16 content_size,
                U8 fo,
                U8 dcs,
                U8 *tpdu,
                U8 tpdu_len);
#ifndef __ULC_SLIM_EMS__
extern MMI_BOOL srv_sms_btmapc_check_ucs2_with_asc_content(char* asc_text_buff, U16 char_num);
#endif

extern srv_sms_cause_enum srv_sms_btmapc_read_content_into_ems(
                            EMSData* ems_data,
                            char* file_path,
                            srv_sms_dcs_enum dcs);


extern srv_sms_cause_enum srv_sms_btmapc_add_content_into_ems(
                            EMSData* ems_data,
                            char* content_buff,
                            U16 content_buff_size,
                            srv_sms_dcs_enum dcs,
                            MMI_BOOL is_asc_content);

extern U16 srv_sms_btmapc_remove_escape_char_ext(
            char* dest_buff,
            char* src_buff,
            U16 dest_char_num,
            U16 src_char_num);
MMI_BOOL srv_sms_btmapc_check_ucs2(char* ucs2_text_buff, U16 char_num);
U16 srv_sms_btmapc_add_escape_char(char* dest_buff, char* src_buff, U16 char_num);


#endif /* __SRV_SMS_EMS_SRV_H__ */

