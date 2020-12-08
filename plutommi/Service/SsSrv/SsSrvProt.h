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

/*******************************************************************************
 * Filename:
 * ---------
 *  SsSrvProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SS service internal prototypes
 *
 * Author:
 * -------
 * 
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#ifndef SRV_SS_PROT_H
#define SRV_SS_PROT_H

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "SsSrvGprot.h"
#include "MMIDataType.h"
#include "kal_non_specific_general_types.h"
#include "MMI_features.h"
#include "l4c_common_enum.h"
#include "UcmSrvGprot.h" /* srv_ucm_call_type_enum */

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

#ifdef __BUILD_DOM__
typedef enum
{
    EVT_ID_SRV_SS_INT_ACT = EVT_ID_SRV_SS_TOTAL + 1,
    EVT_ID_SRV_SS_INT_TOTAL
} srv_ss_int_evt_enum;
#endif /* __BUILD_DOM__ */

typedef struct
{
    srv_ss_source_id_enum source;
    srv_ss_act_enum op;
    void *info;
    mmi_proc_func rsp_cb;
    void *rsp_user_data;
} srv_ss_act_info_struct;


typedef struct
{
    mmi_sim_enum sim;
    srv_ss_act_info_struct act_info;
    MMI_BOOL in_ss_session;
} srv_ss_cntx_struct;


typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_ss_act_enum op;
    void *info;
    mmi_proc_func rsp_cb;
    void *rsp_user_data;
} srv_ss_act_evt_struct;


#ifdef __MMI_SS_SHOW_CAUSE__
typedef struct
{
    U16 cause;
    U8 cause_string[SRV_SS_MAX_CAUSE_LENGTH + 1];
} srv_ss_cause_table_struct;
#endif /* __MMI_SS_SHOW_CAUSE__ */

/*
 * ussn / ussr structure
 */
typedef struct
{
    srv_ss_ind_enum ind;
    srv_ss_direction_enum direction;
    U8 dcs; /* smsal_dcs_enum */
    WCHAR ussd_string[SRV_SS_MAX_LENGTH + 1];
} srv_ss_ussn_ussr_struct;


extern srv_ss_cntx_struct *srv_ss_p;

/***************************************************************************** 
 * Internal Function
 *****************************************************************************/

/* SsSrvInterface.c */
extern void srv_ss_post_rsp_evt(srv_ss_rsp_struct *info);
extern void srv_ss_post_act_req_evt(srv_ss_act_enum op, void *info, mmi_proc_func rsp_cb, void *rsp_user_data);
extern void *srv_ss_post_copy_act_req(srv_ss_act_enum op, void *from);
extern void *srv_ss_post_copy_act_rsp(srv_ss_act_enum op, void *from);
extern mmi_ret srv_ss_post_act_req_evt_hdlr(mmi_event_struct* para);
extern void srv_ss_post_ind_evt(srv_ss_ind_enum op, void *info);
extern void srv_ss_post_act_notify_evt(srv_ss_act_notify_enum type, srv_ss_rsp_struct *rsp_info);
extern mmi_ret srv_ss_post_evt_cb(mmi_post_result_event_struct *result_evt);
extern void srv_ss_set_ps_event_handler(PsExtFuncPtr func, U16 event);
extern void srv_ss_reset_ps_event_handler(U16 event);
extern void srv_ss_l4c_ss_operation_req(U8 length, WCHAR *str, U8 cf_num_len);
extern void srv_ss_l4c_ss_abort_req(PsExtFuncPtr cb);
#ifdef __USSD_AUTO_REJECT__
extern void srv_ss_l4c_ack_req(U16 cause);
extern void srv_ss_phdlr_ussd_ack_rsp(void *info);
#endif /* __USSD_AUTO_REJECT__ */
extern void srv_ss_phdlr_ss_operation_rsp(void *info, int mod_src);
extern void srv_ss_phdlr_call_forward_rsp(void *info, int mod_src);
extern void srv_ss_phdlr_call_bar_rsp(void *info, int mod_src);
extern void srv_ss_phdlr_change_password_rsp(void *info, int mod_src);
extern void srv_ss_phdlr_call_wait_rsp(void *info, int mod_src);
extern void srv_ss_phdlr_ussd_rsp(void *info, int mod_src);
extern void srv_ss_phdlr_ussr_ind(void *info, int mod_src);
extern void srv_ss_phdlr_ussn_ind(void *info, int mod_src);
extern void srv_ss_phdlr_clip_interrogate_ind(void *info, int mod_src);
extern void srv_ss_phdlr_clir_interrogate_ind(void *info, int mod_src);
extern void srv_ss_phdlr_colp_interrogate_ind(void *info, int mod_src);
extern void srv_ss_phdlr_colr_interrogate_ind(void *info, int mod_src);
extern void srv_ss_phdlr_cnap_interrogate_ind(void *info, int mod_src);
extern void srv_ss_phdlr_ccbs_rsp(void *info, int mod_src);
extern void srv_ss_phdlr_emlpp_rsp(void *info, int mod_src);

/* SsSrvOperation.c */
extern srv_ss_result_enum srv_ss_op_call_forward(void *info);
extern srv_ss_result_enum srv_ss_op_call_bar(void *info);
extern srv_ss_result_enum srv_ss_op_call_wait(void *info);
extern srv_ss_result_enum srv_ss_op_ss_operation(void *info, U8 cf_num_len);
extern srv_ss_result_enum srv_ss_op_abort(void);
extern void srv_ss_ps_ss_operation_done(srv_ss_rsp_struct *info, MMI_BOOL end_session);
extern void srv_ss_ps_receive_ussn_ussr(void *info);
extern void srv_ss_ps_derive_ussd(U8 dcs, U8 length, PU8 str, WCHAR *out_str);
extern srv_ss_result_enum srv_ss_ps_derive_result(srv_ss_ps_cause_enum cause);
extern srv_ss_result_enum srv_ss_ps_append_bs_code(mmi_sim_enum sim, CHAR *buf, srv_ss_call_type_enum call_type);


/* SsSrvStructMgmt.c */
extern void srv_ss_init(void);
extern void srv_ss_init_phdlr(void);
extern MMI_BOOL srv_ss_is_busy(srv_ss_act_enum op);
extern void srv_ss_cntx_set_ptr(mmi_sim_enum sim);
extern void srv_ss_cntx_reset_ptr(void);
extern MMI_BOOL srv_ss_cntx_is_locked(void);

/* SsSrvUtil.c */
extern U8 srv_ss_get_sim_interface(mmi_sim_enum sim);
extern srv_ucm_call_type_enum srv_ss_get_call_type(mmi_sim_enum sim);
extern srv_ss_bs_code_enum srv_ss_get_bs_code(U8 ps_bs_code);
extern srv_ss_direction_enum srv_ss_get_direction(U8 ps_dir);
extern srv_ss_call_forward_type_enum srv_ss_get_cf_type(U8 ps_cf_type);
extern srv_ss_call_bar_type_enum srv_ss_get_cb_type(U8 ps_cb_type);
extern MMI_BOOL srv_ss_support_cf(mmi_sim_enum sim, srv_ss_call_forward_type_enum type, srv_ss_call_type_enum call_type);
extern MMI_BOOL srv_ss_support_cb(mmi_sim_enum sim, srv_ss_call_bar_type_enum type, srv_ss_call_type_enum call_type);
extern MMI_BOOL srv_ss_support_cw(mmi_sim_enum sim);
extern MMI_BOOL srv_ss_support_cid(mmi_sim_enum sim);
extern MMI_BOOL srv_ss_is_valid_sim(mmi_sim_enum sim);

#endif /* SRV_SS_PROT_H */
