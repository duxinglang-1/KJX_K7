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
 *  CbmSrvIntProt.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  MMI CBM internal interface 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef SRV_CBM_INT_PROT_H
#define SRV_CBM_INT_PROT_H

#include "CbmSrvFeature.h"
#include "cbm_consts.h"

#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "mmi2abm_struct.h"

//#define CBM_UT_TEST

/*************************************************************************
* Enums
*************************************************************************/
/* Maximum call number in each call service */
#define SRV_CBM_MAX_APP_NUM (ABM_MAX_APP_NUM)
#define CBM_NWK_DISALLOW_EVENT    0x00000001


/*************************************************************************
* Structures
*************************************************************************/
#ifdef __CBM_DISALLOW_NWK_SRV_SUPPRT__

typedef struct
{
    MMI_BOOL is_valid;
    U8 app_id;
    U32 disallowed_bearer[CBM_SIM_ID_TOTAL];
} srv_cbm_nwk_app_struct;

typedef struct
{
    kal_eventgrpid wait_event;
    kal_bool result;
    U32      disallowed_bearer[CBM_SIM_ID_TOTAL];
    srv_cbm_nwk_app_struct app_list[SRV_CBM_MAX_APP_NUM];
} srv_cbm_nwk_srv_struct;

#endif /* __CBM_DISALLOW_NWK_SRV_SUPPRT__ */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef enum
{
    SRV_CBM_APP_STATE_NONE,
    SRV_CBM_APP_STATE_STARTUP,
    SRV_CBM_APP_STATE_CONNECTING,
    SRV_CBM_APP_STATE_CONNECT_FAIL,
    SRV_CBM_APP_STATE_CONNECTED,
    SRV_CBM_APP_STATE_DISCONNECTED,
    SRV_CBM_APP_STATE_SWITCHING,
    SRV_CBM_APP_STATE_SWITCH_FAIL,
    SRV_CBM_APP_STATE_MMS_STARTUP,
    SRV_CBM_APP_STATE_MMS_PENDING,
    SRV_CBM_APP_STATE_PENDING_STARTUP,
    SRV_CBM_APP_STATE_TOTAL
} srv_cbm_app_state_enum;

typedef struct
{
    U8 evt;
    U8 app_id;
    U32 nw_acct_id;
    U32 rel_acct_id;
    srv_cbm_app_state_enum app_state;
} srv_cbm_app_cntx_struct;

typedef struct
{
#ifdef __CBM_DISALLOW_NWK_SRV_SUPPRT__
    srv_cbm_nwk_srv_struct nwk_srv;
#endif
    //srv_cbm_app_evt_struct  app[ABM_MAX_APP_NUM];
    srv_cbm_app_cntx_struct app[ABM_MAX_APP_NUM];
    S32 wlan_query_type;

#ifdef __PS_PDP_SWITCH_SUPPORT__
    MMI_BOOL notify_bearer_available;
#endif
} srv_cbm_context_struct;

extern srv_cbm_context_struct *const g_cbm_srv_cxt_ptr;


/*************************************************************************
* External APIs
*************************************************************************/
#ifdef __CBM_DISALLOW_NWK_SRV_SUPPRT__
extern void srv_cbm_lock(void);
extern void srv_cbm_unlock(kal_bool result);
extern void srv_cbm_send_nwk_srv_req(
                mmi_abm_nwk_srv_action_enum action,
                mmi_abm_nwk_srv_type_enum type,
                U32 bearer_type[]);
extern void srv_cbm_nwk_srv_cnf_hdlr(void *info);
#endif /* __CBM_DISALLOW_NWK_SRV_SUPPRT__ */

extern void srv_cbm_bearer_event_notify_ind_hdlr(void* info);
extern U8 srv_cbm_bearer_info_ind_hdlr(void *info);
extern void srv_cbm_app_bearer_info_ind_hdlr(void *info);
extern mmi_ret srv_cbm_wifi_connect_ind_hdlr(mmi_event_struct *evt);

#ifdef __CBM_DISALLOW_NWK_SRV_SUPPRT__
extern srv_cbm_nwk_app_struct *srv_cbm_get_app_index(U8 app_id);
extern U32 srv_cbm_merge_bearer(
            mmi_abm_nwk_srv_action_enum action,
            srv_cbm_nwk_app_struct *app_p,
            cbm_sim_id_enum sim_id,
            U32 type);
extern void srv_cbm_disallow_bearer(srv_cbm_nwk_app_struct *app_p, cbm_sim_id_enum sim_id, U32 type, U8 app_id);
extern void srv_cbm_allow_bearer(srv_cbm_nwk_app_struct *app_p, cbm_sim_id_enum sim_id, U32 type);
extern S32 srv_cbm_get_sim_num(void);
extern void srv_cbm_mark_common_bearer(U32 bearer_type[], U32 common_type);
extern void srv_cbm_unmark_common_bearer(U32 bearer_type[], U32 common_type);
#endif /* __CBM_DISALLOW_NWK_SRV_SUPPRT__ */

extern srv_cbm_app_cntx_struct *srv_cbm_get_app_slot(U8 app_id);
extern void srv_cbm_free_app_slot(srv_cbm_app_cntx_struct *app_p);

extern cbm_result_error_enum srv_cbm_get_real_acct_id(U32 nw_acct_id, U32 *rel_acct_id, U32 *bearer_type);

extern void srv_cbm_bearer_init_ind_hdlr(void *info);
extern void srv_cbm_send_bearer_init_rsp(MMI_BOOL result, U32 ori_acct_id, U32 rel_acct_id, U32 bearer_type, S32 cause);
extern void srv_cbm_bearer_deinit_ind_hdlr(void *info);
extern void srv_cbm_send_bearer_deinit_rsp(U32 nw_acct_id);
extern void srv_cbm_bearer_connect_result_ind_hdlr(void *info);
extern void srv_cbm_send_bearer_evt_connect_req(U32 user_result, U32 event, U32 ori_acct_id, U32 sel_acct_id);

#ifdef __PS_PDP_SWITCH_SUPPORT__
extern srv_cbm_app_cntx_struct *srv_cbm_get_mms_app_slot(srv_cbm_app_state_enum app_state);
extern S32 srv_cbm_activate_mms_pre_proc(cbm_sim_id_enum mms_sim_id, cbm_result_error_enum *cause);
extern void srv_cbm_proc_pending_app(srv_cbm_app_state_enum app_state, S32 cause);
extern void srv_cbm_send_bearer_disconnect_req(cbm_sim_id_enum sim_id, U32 bearer);
extern void srv_cbm_bearer_disconnect_cnf_hdlr(void *msg);
extern void srv_cbm_bearer_status_ind_hdlr(void *msg);
#endif /* __PS_PDP_SWITCH_SUPPORT__ */

#endif /* SRV_CBM_INT_PROT_H */

