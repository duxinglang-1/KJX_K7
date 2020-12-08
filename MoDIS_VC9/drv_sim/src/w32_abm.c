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
 * w32_abm.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Socket APIs on WIN32 environment.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
     /* KAL - RTOS Abstraction Layer */
     /* KAL - RTOS Abstraction Layer */
#include "kal_release.h"
     
     /* Task Message Communication */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"         /* local/peer struct */
#include "stack_ltlcom.h"
     
     /* Timer Management  */
#include "stacklib.h"
#include "event_shed.h"         /* event schedulet */
#include "stack_timer.h"
     
     /* Task Management */
#include "syscomp_config.h"
#include "task_config.h"
#include "custom_config.h"
     
#include "app_buff_alloc.h"     /* buffer management API */
#include "lcd_cqueue.h"
#include "bitop_funcs.h"
//#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */  
     
#include "nvram_editor_data_item.h"
#include "custom_nvram_editor_data_item.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_enums.h"
#include "nvram_interface.h"    /* for nvram_get_info() */
     
#include "l3_inc_enums.h"
     
#include "mmi_l3_enums.h"
#include "abm2soc_struct.h"
#include "soc2abm_struct.h"
#include "l4c2abm_struct.h"
#include "mmi_sm_enums.h"
#include "abm2l4c_struct.h"
     
#ifdef __WIFI_SUPPORT__
#include "wndrv_cnst.h"
#include "wndrv_supc_types.h"
#include "wndrv_api.h"
#include "supc_abm_msgs.h"
#include "soc_api.h"
#include "dhcp_abm_enums.h"
#include "dhcp2abm_struct.h"
#endif /* __WIFI_SUPPORT__ */ 
#include "abm2soc_struct.h"   /* interface with Applications */
#include "abm_soc_enums.h"
#include "app2cbm_struct.h"
#include "mmi2abm_struct.h"

#include "soc_api.h"
#include "cbm_api.h"
#include "abm_api.h"
#include "abm_soc_enums.h"
#include "abm_main.h"
#include "abm_util.h"
#include "abm_def.h"

#include <ctype.h>
#include <stdio.h>

#define _W32_ABM_C_

#define ABM_MAX_APP_NWK_NUM  50

typedef enum
{
    W32_ABM_NON_AUTO_DEACT = 0x01,
    W32_ABM_ASK_NEED_NOTIFY = 0x02,
    W32_ABM_ASK_NEED_RESULT = 0x04
} bearer_option_enum;

typedef enum
{
    W32_BEARER_CLOSED         = 0,
    W32_BEARER_OPENING        = 1,
    W32_BEARER_OPENED         = 2
} bearer_state_enum;

typedef struct
{
    int mod_id;
    int app_id;
    int account_id;
    bearer_option_enum option;
    bearer_state_enum  state;
} abm_app_nwk_state_struct;

static abm_app_nwk_state_struct abm_app_nwk[ABM_MAX_APP_NWK_NUM];
static kal_semid w32_abm_lock;
#define ABM_LOCK          kal_take_sem(w32_abm_lock, KAL_INFINITE_WAIT)
#define ABM_UNLOCK        kal_give_sem(w32_abm_lock)

void abm_init_win32(void)
{
    int i;

    for (i = 0 ; i < ABM_MAX_APP_NWK_NUM ; i++)
    {
        abm_app_nwk[i].mod_id         = -1;
        abm_app_nwk[i].app_id         = -1;
    
        abm_app_nwk[i].account_id     = -1;
        abm_app_nwk[i].option         = 0;
        abm_app_nwk[i].state          = W32_BEARER_CLOSED;
    }
    
     w32_abm_lock = kal_create_sem("abm lock", 1);
    return;
}

static
int abm_find_app_slot(int mod_id, 
                      int app_id,
                      int nwk_account_id, 
                      int *idx)
{
    int i;
    ASSERT(idx);
    
    for (i = 0 ; i < ABM_MAX_APP_NWK_NUM ; i++)
    {
        if (((app_id != 0 && abm_app_nwk[i].app_id == app_id) ||
             (app_id == 0 && abm_app_nwk[i].mod_id == mod_id &&
              abm_app_nwk[i].app_id == app_id)) &&
             (nwk_account_id == -1 ||
              abm_app_nwk[i].account_id == nwk_account_id))
        {
            *idx = i;
            return 1;
        }
    }
    return 0;
}

static
int abm_find_free_app_slot(int *idx)
{
    int found;

    ASSERT(idx);
    found = abm_find_app_slot(-1,
                              -1,
                              -1, 
                              idx);
    ASSERT(found == 1);

    return found;
}

static
void abm_free_soc_app_slot(int idx)
{
    ASSERT(idx >= 0 && idx < ABM_MAX_APP_NWK_NUM);

    abm_app_nwk[idx].mod_id = -1;
    abm_app_nwk[idx].app_id = -1;
    abm_app_nwk[idx].account_id = -1;
    abm_app_nwk[idx].option &= ~W32_ABM_NON_AUTO_DEACT;
    abm_app_nwk[idx].state = W32_BEARER_CLOSED;
    
    return;
}

kal_int32 abm_get_bearer_app_result(kal_uint32 type, kal_uint32 state)
{
    return CBM_OK;
}

kal_int32 abm_get_bearer_app_value(kal_uint32 type, kal_uint32 state)
{
    return CBM_OK;
}


void mmi_abm_bearer_connect_req_hdlr(mmi_abm_bearer_event_connect_req_struct *info)
{
    kal_uint8 ap_id;
    int id, i;
    kal_uint8 profile_id;
    int ori_account_id;
    abm_app_id_struct app;
     kal_uint8 ip_addr[4];
    abm_app_proc_struct *app_proc;
    cbm_account_info_struct acct_info;
    mmi_abm_bearer_event_connect_cnf_struct *cnf = NULL;

    /* send back response */
    cnf = construct_local_para(sizeof(mmi_abm_bearer_event_connect_cnf_struct), TD_RESET);
    cnf->event = info->event;
    cnf->ori_acct_id = info->ori_acct_id;
    cnf->result = KAL_TRUE;
    abm_send_msg2extmod(MSG_ID_MMI_ABM_BEARER_EVENT_CONNECT_CNF, MOD_MMI, 
                                           ABM_MMI_SAP, (local_para_struct*)cnf);
                    
    ap_id = cbm_get_app_id(info->ori_acct_id);
    cbm_decode_data_account_id_ext(info->ori_acct_id, &acct_info);
    if (acct_info.acct_num > 1)
        ori_account_id = acct_info.account[1].account_id;
    else
        ori_account_id = acct_info.account[0].account_id;
    
    if (abm_find_app_slot(MOD_NIL, 
                          ap_id,
                          info->ori_acct_id, 
                          &id) )
    {
        app_proc = abm_find_app_proc(CBM_INVALID_MOD_ID, ap_id);
        if (app_proc)
        {
            memcpy(app.report_mod_id, app_proc->app.report_mod_id, sizeof(app.report_mod_id));
        }
        app.ap_id = ap_id;
        app.activate_mod_id = abm_app_nwk[id].mod_id;
        
        if (info->user_result == MMI_ABM_BEARER_EVENT_ACCEPT_THIS_TIME)
        {
            if (abm_app_nwk[id].state == W32_BEARER_OPENING)
            {
                ip_addr[0] = 192;
                ip_addr[1] =168;
                ip_addr[2] = 1;
                ip_addr[3] = 1;
                abm_send_bearer_info_ind2app(&app, abm_app_nwk[id].account_id, 
                                            ori_account_id, 0, 
                                            CBM_ACTIVATING, 
                                            CBM_PS, 
                                            ip_addr, 0, 0, NULL);
                abm_send_bearer_info_ind2mmi(0, CBM_PS, ori_account_id, CBM_ACTIVATED);
                abm_send_bearer_info_ind2app(&app, abm_app_nwk[id].account_id, 
                                            ori_account_id, 0, 
                                            CBM_ACTIVATED, 
                                            CBM_PS, 
                                            ip_addr, 0, 0, NULL);
                abm_app_nwk[id].state = W32_BEARER_OPENED;
            }

            abm_send_act_cnf2soc(abm_app_nwk[id].mod_id,
                                 CBM_PS,
                                 (kal_uint32)abm_app_nwk[id].account_id, /* nw_acc_id */
                                 (kal_uint8)ori_account_id,
                                 0,               /* qos_profile_id */
                                 0,           /* bearer_ctx_id */
                                 0,     /* qos_fulfilled */
                                 ip_addr,
                                 NULL,
                                 NULL,
                                 NULL,
                                 NULL,
                                 NULL,
                                 0,
                                 1500);      /* beaer MTU=0 */
        }
        else
        {
            if (abm_app_nwk[id].state != W32_BEARER_CLOSED)
            {
                abm_send_bearer_info_ind2app(&app, (kal_uint32)abm_app_nwk[id].account_id, 
                                            ori_account_id, 0, 
                                            CBM_DEACTIVATING, 
                                            CBM_PS, NULL, 0, 0, NULL);
                abm_send_bearer_info_ind2mmi(0, CBM_PS, ori_account_id, CBM_DEACTIVATED);
                abm_send_bearer_info_ind2app(&app, (kal_uint32)abm_app_nwk[id].account_id, 
                                            ori_account_id, 0, 
                                            CBM_DEACTIVATED, 
                                            CBM_PS, NULL, 0, 0, NULL);
                    
            }
            abm_send_rej2soc(MSG_ID_SOC_ABM_ACTIVATE_CNF, 
                             abm_app_nwk[id].mod_id, 
                             CBM_PS, 0, 0, abm_app_nwk[id].account_id, 
                             0, 0, KAL_FALSE);
            abm_free_soc_app_slot(id);
        }
    }
        
}


void mmi_abm_bearer_event_notify_rsp_hdlr(app_cbm_bearer_event_notify_rsp_struct * info)
{
    kal_uint8 ap_id;
    int id, i;
    kal_uint8 profile_id;
    int ori_account_id;
    abm_app_id_struct app;
     kal_uint8 ip_addr[4];
    abm_app_proc_struct *app_proc;
    
    ap_id = cbm_get_app_id(info->account_id);
    ori_account_id = cbm_get_original_account(info->account_id);
       
    app.activate_mod_id = MOD_NIL;
    app.ap_id = ap_id;    
    
    if (abm_find_app_slot(MOD_NIL, 
                          ap_id,
                          info->account_id, 
                          &id) == 0)
    {
        app_proc = abm_find_app_proc(CBM_INVALID_MOD_ID, ap_id);
        if (app_proc)
        {
            memcpy(app.report_mod_id, app_proc->app.report_mod_id, sizeof(app.report_mod_id));
        }
        /* wait for connect request */       
    }
}

void abm_soc_activate_req_hdlr(soc_abm_activate_req_struct* info)
{
    kal_uint8 ap_id;
    kal_uint32 id, i;
    kal_uint32 ori_account_id;
    abm_app_id_struct app;
    abm_app_proc_struct *app_proc;
    kal_uint8 ip_addr[4];
    cbm_sim_id_enum sim_id;
    cbm_account_info_struct acct_info;

    ABM_LOCK;
    cbm_decode_data_account_id_ext(info->nw_acc_id, &acct_info);
    ap_id = acct_info.app_id;
    ori_account_id = acct_info.account[0].account_id;
    sim_id = acct_info.account[0].sim_id;
    app.activate_mod_id = info->mod_id;
    app.ap_id = ap_id;    
    
    if (abm_find_app_slot(info->mod_id, 
                          ap_id,
                          info->nw_acc_id, 
                          &id) == 0)
    {
        if (abm_find_app_slot(info->mod_id, 
                          ap_id,
                          -1, 
                          &id))
        {
            abm_app_nwk[id].mod_id = info->mod_id;
            
            if (abm_app_nwk[id].account_id == -1)
                abm_app_nwk[id].account_id = info->nw_acc_id;
            
            abm_app_nwk[id].state = W32_BEARER_CLOSED;
        }
        else
        {
            if (abm_find_free_app_slot(&id))
            {
                abm_app_nwk[id].mod_id = info->mod_id;
                abm_app_nwk[id].app_id = ap_id;
                
                if (abm_app_nwk[id].account_id == -1)
                    abm_app_nwk[id].account_id = info->nw_acc_id;
                
                abm_app_nwk[id].state = W32_BEARER_CLOSED;
            }
        }
    }

    app_proc = abm_find_app_proc(CBM_INVALID_MOD_ID, ap_id);
    if (app_proc)
    {
        memcpy(app.report_mod_id, app_proc->app.report_mod_id, sizeof(app.report_mod_id));
    }

    if (abm_app_nwk[id].state == W32_BEARER_CLOSED)
    {
        ip_addr[0] = 192;
        ip_addr[1] =168;
        ip_addr[2] = 1;
        ip_addr[3] = 1;
        ori_account_id = cbm_encode_data_account_id(ori_account_id, sim_id, 
        0, KAL_FALSE);
        abm_send_bearer_info_ind2app(&app, abm_app_nwk[id].account_id, 
                                    ori_account_id, info->qos_profile_id, 
                                    CBM_ACTIVATING, 
                                    CBM_PS, 
                                    ip_addr, 0, 0, NULL);
        abm_send_bearer_info_ind2mmi(0, CBM_PS, ori_account_id, CBM_ACTIVATED);
        abm_send_bearer_info_ind2app(&app, abm_app_nwk[id].account_id, 
                                    ori_account_id, info->qos_profile_id, 
                                    CBM_ACTIVATED, 
                                    CBM_PS, 
                                    ip_addr, 0, 0, NULL);
        abm_app_nwk[id].state = W32_BEARER_OPENED;
    }

    abm_send_act_cnf2soc(info->mod_id,
                         CBM_PS,
                         (kal_uint32)abm_app_nwk[id].account_id, /* nw_acc_id */
                         (kal_uint8)ori_account_id,
                         info->qos_profile_id,               /* qos_profile_id */
                         0,           /* bearer_ctx_id */
                         0,     /* qos_fulfilled */
                         ip_addr,
                         NULL,
                         NULL,
                         NULL,
                         NULL,
                         NULL,
                         0,
                         1500);      /* beaer MTU=0 */

    ABM_UNLOCK;
    return;
}

void abm_soc_deactivate_req_hdlr(soc_abm_deactivate_req_struct* info)
{
    kal_uint8 ap_id;
    int id;
    cbm_sim_id_enum sim_id;
    kal_uint32 ori_account_id;
    abm_app_id_struct app;
    abm_app_proc_struct *app_proc;
    
    ap_id = cbm_get_app_id(info->nw_acc_id);
    ori_account_id = cbm_get_original_account(info->nw_acc_id);
    sim_id = cbm_get_sim_id(info->nw_acc_id);
    app.activate_mod_id = info->mod_id;
    app.ap_id = ap_id;  
    
    ABM_LOCK;
    if (abm_find_app_slot(info->mod_id, 
                          ap_id,
                          info->nw_acc_id, 
                          &id))
    {
        app_proc = abm_find_app_proc(CBM_INVALID_MOD_ID, ap_id);
        if (app_proc)
        {
            memcpy(app.report_mod_id, app_proc->app.report_mod_id, sizeof(app.report_mod_id));
        }
    
        if ((info->cause & ABM_APP_NON_AUTO_DEACT) != ABM_APP_NON_AUTO_DEACT)
        {
            if (abm_app_nwk[id].option & W32_ABM_NON_AUTO_DEACT)
            {
                abm_send_rej2soc(
                        MSG_ID_SOC_ABM_DEACTIVATE_CNF,
                        info->mod_id,
                        ABM_E_SOCKET_BEARER_IP_ANY,
                        ABM_E_NON_AUTO_DEACT,
                        0,
                        info->nw_acc_id,
                        ABM_DEFAULT_QOS,
                        ABM_NULL_BEARER,
                        KAL_FALSE);
                ABM_UNLOCK;
                return;
            }
        }
        if (abm_app_nwk[id].state != W32_BEARER_CLOSED)
        {
            ori_account_id = cbm_encode_data_account_id(ori_account_id, sim_id, 
            0, 0);
            abm_send_bearer_info_ind2app(&app, info->nw_acc_id, 
                                        ori_account_id, info->qos_profile_id, 
                                        CBM_DEACTIVATING, 
                                        CBM_PS, NULL, 0, 0, NULL);
            abm_send_bearer_info_ind2mmi(0, CBM_PS, ori_account_id, CBM_DEACTIVATED);
            abm_send_bearer_info_ind2app(&app, info->nw_acc_id, 
                                        ori_account_id, info->qos_profile_id, 
                                        CBM_DEACTIVATED, 
                                        CBM_PS, NULL, 0, 0, NULL);
                
        }
        abm_free_soc_app_slot(id);
    }
       
    abm_send_deact_cnf2soc(info->mod_id,
                           info->nw_acc_id, 
                           info->qos_profile_id, 0);
    ABM_UNLOCK;
    return;
}

kal_int32 abm_get_bearer_mmi_value(kal_uint32 type, kal_uint32 state)
{
    return CBM_OK;
}

#ifndef __NWK_APP_UT__

kal_int8 cbm_hold_bearer(kal_uint8 app_id)
{
    int i;
    int free_slot = -1;

    ABM_LOCK;
    
    for (i = 0; i < ABM_MAX_APP_NWK_NUM; i++)
    {
        if ((app_id != 0 && abm_app_nwk[i].app_id == app_id))
        {
            abm_app_nwk[i].option = W32_ABM_NON_AUTO_DEACT;
            break;
        }
        if (free_slot == -1)
        {
            if (abm_app_nwk[i].app_id == -1 && abm_app_nwk[i].mod_id == -1)
                free_slot = i;
        }
    }
    if (i >= ABM_MAX_APP_NWK_NUM && free_slot != -1)
    {
        abm_app_nwk[free_slot].app_id = app_id;
        abm_app_nwk[free_slot].option = W32_ABM_NON_AUTO_DEACT;
    }

    ABM_UNLOCK;
    return CBM_OK;
}

kal_int8 cbm_release_bearer(kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_soc_deactivate_req_struct *ind_ptr;
    ilm_struct *ilm_ptr;
    abm_app_id_struct app;
    kal_uint8 i;
    abm_app_proc_struct *app_proc = NULL;
    kal_uint32 nwk_acct_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ABM_LOCK;
    for (i = 0 ; i < ABM_MAX_APP_NWK_NUM ; i++)
    {
        if ((app_id != 0 && abm_app_nwk[i].app_id == app_id))
        {
            if (abm_app_nwk[i].state != W32_BEARER_CLOSED)
                break;
        }
    }
    if (i >= ABM_MAX_APP_NWK_NUM)
    {
        ABM_UNLOCK;
        return CBM_ERROR;
    }
    
    nwk_acct_id = cbm_encode_data_account_id(CBM_ALL_NWK_ACCT_ID, CBM_SIM_ID_SIM1, app_id, KAL_FALSE);

    ind_ptr = (app_soc_deactivate_req_struct *) 
              construct_local_para(sizeof(app_soc_deactivate_req_struct), TD_CTRL | TD_RESET);
    ind_ptr->account_id = nwk_acct_id;
    ind_ptr->qos_profile_id = CBM_ALL_QOS_ID;
   
    ilm_ptr = allocate_ilm(stack_get_active_module_id());
    ilm_ptr->msg_id = (msg_type) MSG_ID_APP_SOC_DEACTIVATE_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*)ind_ptr;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(stack_get_active_module_id(), MOD_SOC, SOC_APP_SAP, ilm_ptr);

    ABM_UNLOCK;
    return CBM_WOULDBLOCK; 
}

kal_int8 cbm_get_bearer_type(kal_uint32 account_id,
                             cbm_bearer_enum *bearer_type)
{
    kal_uint32 ori_account_id;
    kal_uint8 bearer_id;

    ori_account_id = cbm_get_original_account(account_id);
   
    if (abm_get_bearer_type(ori_account_id, 
        (cbm_bearer_enum *)bearer_type) != CBM_OK)
    {
        *bearer_type = CBM_BEARER_NONE;
    }
    
    return CBM_OK;
}

kal_int32 cbm_get_bearer_status(kal_uint32 account_id)
{

    kal_int32 id = 0;
    kal_int32 ret = 0;
    
    ABM_LOCK;
    
    
    if (abm_find_app_slot(MOD_NIL, 
                          cbm_get_app_id(account_id),
                          account_id, 
                          &id))
    {
        if (abm_app_nwk[id].state == W32_BEARER_OPENED)
        {
            ret = CBM_ACTIVATED;
        }
        else
        {
            ret = CBM_DEACTIVATED;
        }
    }
    else
    {
        ret = CBM_DEACTIVATED;
    }
    
    ABM_UNLOCK;
    return ret;
}

#endif /* __NWK_APP_UT__ */

kal_int32 abm_get_bearer_message_result(kal_uint32 type, kal_uint32 state)
{
    return CBM_OK;
}

kal_int32 abm_get_bearer_message_value(kal_uint32 type, kal_uint32 state)
{
    return CBM_OK;
}

