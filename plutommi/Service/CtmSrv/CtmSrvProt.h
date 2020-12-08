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
 *  Modification Notice:
 *  --------------------------
 *  This software is modified by MediaTek Inc. and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   CtmSrvProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Cellular Text telephone Modem
 *  Internal prototypes
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __CTM_SUPPORT__

#ifndef SRV_CTM_PROT_H
#define SRV_CTM_PROT_H

#include "CtmSrvGprot.h"

#include "MMIDataType.h"
#include "kal_non_specific_general_types.h"


typedef struct
{
    srv_ctm_state_enum state;
    U8 mode_opening; /* aud_ctm_interface_enum */
    U8 mode_activated; /* aud_ctm_interface_enum */
    MMI_BOOL ctm_call_mode; /* ctm call on when tty_status == on or DIRECT mode is on */
    srv_ctm_act_op_enum curr_act;
    srv_ctm_rsp_cb_func_ptr rsp_cb;
    MMI_BOOL tty_status;
} srv_ctm_cntxt_struct;


extern srv_ctm_cntxt_struct *srv_ctm_p;


extern void srv_ctm_phdlr_close_rsp(void *info);
extern void srv_ctm_send_ind(srv_ctm_ind_enum op, void *ptr);
extern void srv_ctm_act_connect(void);
extern MMI_BOOL srv_ctm_act_send_text(void* info);
extern void srv_ctm_phdlr_connect_rsp(void *info);
extern void srv_ctm_phdlr_send_text_rsp(void *info);
extern void srv_ctm_phdlr_connect_ind(void *info);
extern void srv_ctm_phdlr_open_rsp(void *info);
extern void srv_ctm_speech_on_hdlr(void);
extern void srv_ctm_speech_off_hdlr(void);
extern void srv_ctm_open(MMI_BOOL ctm_open);
extern U8 srv_ctm_derive_mode(void);
extern void srv_ctm_phdlr_receive_text_ind(void *info);
extern U16 srv_ctm_skip_unicode_char(PU16 str, U16 len, U16 ch);
extern void srv_ctm_l4c_set_ctm_status_req(MMI_BOOL is_ctm_on);
extern void srv_ctm_med_close_req(void);
extern void srv_ctm_med_connect_req(void);
extern void srv_ctm_med_open_req(U8 mode);
extern void srv_ctm_med_send_text_req(CHAR* text);
extern void srv_ctm_switch_tty_status(MMI_BOOL switch_on);
extern void srv_ctm_set_tty_status(MMI_BOOL is_present);
extern mmi_ret srv_ctm_hdlr_earphone_plug_in(mmi_event_struct *evt);
extern mmi_ret srv_ctm_hdlr_earphone_plug_out(mmi_event_struct *evt);
extern mmi_ret srv_ctm_hdlr_earphone_query_ctrl(mmi_event_struct *evt);
extern mmi_ret srv_ctm_hdlr_ctm_setting_changed(mmi_event_struct *evt);


     
#endif /* SRV_CTM_PROT_H */ 
#endif /* __CTM_SUPPORT__ */
