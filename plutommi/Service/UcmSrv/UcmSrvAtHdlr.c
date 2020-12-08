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
 *  UcmSrvIntInterface.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 * 
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
#include "MMIDataType.h"
#include "mmi_msg_struct.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "MMI_features.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "ps_public_enum.h"
#include "string.h"
#include "mmi_frm_mem_gprot.h"
#include "Unicodexdcl.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_msgs.h"
#include "ps_public_struct.h"
#include "rmmi_common_enum.h"
#include "UcmSrvGprot.h"
#include "UcmSrvIntProt.h"
#include "UcmSrvProt.h"
#include "PhbSrvGprot.h"
#include "CallLogSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#ifdef __CTM_SUPPORT__
#include "CtmSrvGprot.h"
#endif /* __CTM_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_at_res_req_success
 * DESCRIPTION
 *  In order to indicate the L4 starting the operation. 
 *  Send a start req to L4 with RMMI_UCM_CAUSE_NONE.
 *
 * PARAMETERS
 *  module_id       [IN]            Module ID. To record which sim card 
 *                                  operation
 *  source_id       [IN]            To record the L4 source id(MOD_L4)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_at_res_req_success(srv_ucm_module_origin_enum module_id, U8 source_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* AT information */
    g_ucm_srv_p->call_misc.curr_module = module_id;
    memset(&g_ucm_srv_p->call_misc.at_info, 0, sizeof(srv_ucm_int_at_info_struct));
    g_ucm_srv_p->call_misc.at_info.l4c_source = source_id;

    /* Notify AT fisrt, that the action is going to perform */
    srv_ucm_at_res_req(module_id, source_id, MMI_TRUE, RMMI_UCM_CAUSE_NONE);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_at_res_req_fail
 * DESCRIPTION
 *  In order to indicate the L4 starting the operation. 
 *  Send a start req to L4 with RMMI_UCM_CAUSE_XXX.
 *
 * PARAMETERS
 *  module_id       [IN]            Module ID. To record which sim card 
 *                                  operation
 *  source_id       [IN]            To record the L4 source id(MOD_L4)
 *  cause           [IN]            Fail cause reason.
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_at_res_req_fail(srv_ucm_module_origin_enum module_id, U8 source_id, U8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_ucm_at_res_req(module_id, source_id, MMI_FALSE, cause);
    g_ucm_srv_p->call_misc.curr_module = SRV_UCM_MODULE_ORIGIN_COMMON;
    memset(&g_ucm_srv_p->call_misc.at_info, 0, sizeof(srv_ucm_int_at_info_struct));
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_at_req_prepare_single_call_data
 * DESCRIPTION
 *  Prepare the single call data.
 *
 * PARAMETERS
 *  single_call_req [OUT]           Pointer to the output data
 *  call_type       [IN]            Call type
 *  group_id        [IN]            Group id
 *  call_id         [IN]            Call id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_at_req_prepare_single_call_data(
                srv_ucm_single_call_act_req_struct *single_call_req, 
                srv_ucm_call_type_enum call_type, 
                S16 group_id, 
                S16 call_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset first */
    memset(single_call_req, 0, sizeof(srv_ucm_single_call_act_req_struct));
    /* assign */
    single_call_req->action_uid.call_type = call_type;
    single_call_req->action_uid.group_id = group_id;
    single_call_req->action_uid.call_id = call_id;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_at_req_prepare_single_group_data
 * DESCRIPTION
 *  Prepare the single call data.
 *
 * PARAMETERS
 *  single_group_req [OUT]           Pointer to the output data
 *  call_type        [IN]            Call type
 *  group_id         [IN]            Group id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_at_req_prepare_single_group_data(
                srv_ucm_single_group_act_req_struct *single_group_req, 
                srv_ucm_call_type_enum call_type, 
                S16 group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset first */
    memset(single_group_req, 0, sizeof(srv_ucm_single_group_act_req_struct));
    /* assign */
    single_group_req->call_type = call_type;
    single_group_req->action_group = group_id;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_at_req_prepare_multiple_group_data
 * DESCRIPTION
 *  Prepare the single call data.
 *
 * PARAMETERS
 *  single_group_req [OUT]           Pointer to the output data
 *  call_type        [IN]            Call type
 *  group_id         [IN]            Group id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_at_req_prepare_multiple_group_data(
                srv_ucm_multiple_group_act_req_struct *multiple_group_req, 
                srv_ucm_call_type_enum active_call_type, 
                S16 active_group_id, 
                srv_ucm_call_type_enum other_call_type, 
                S16 other_group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset first */
    memset(multiple_group_req, 0, sizeof(srv_ucm_multiple_group_act_req_struct));
    /* assign */
    multiple_group_req->active_call_type = active_call_type;
    multiple_group_req->active_group = active_group_id;
    multiple_group_req->other_call_type = other_call_type;
    multiple_group_req->other_group = other_group_id;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_at_req_ind
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_at_req_ind(void *msg, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0, group_index = 0, call_index = 0, len = 0;
    U8 *ucs2_num = NULL;
    U8 cause = 0;
    U16 store_index = 0;
    srv_ucm_call_type_enum call_type = SRV_UCM_VOICE_CALL_TYPE;
    srv_ucm_id_info_struct unique_id;
    srv_ucm_index_info_struct index;
    srv_ucm_dial_act_req_struct dial_req;
    srv_ucm_hold_and_dial_act_req_struct hold_and_dial_req;
    srv_ucm_single_call_act_req_struct single_call_req;
    srv_ucm_single_group_act_req_struct single_group_req;
    srv_ucm_hold_and_accept_act_req_struct hold_and_accept_req;
    srv_ucm_multiple_group_act_req_struct multiple_group_req;
#ifdef __MMI_UCM_ECT__
    srv_ucm_ect_act_req_struct ect_req;
#endif
    mmi_ucm_at_req_ind_struct *at_ind = (mmi_ucm_at_req_ind_struct*)msg;
    srv_ucm_module_origin_enum module_id = SRV_UCM_MODULE_ORIGIN_AT;
    MMI_BOOL data_ata_not_allowed = MMI_FALSE;
    U32 clog_handle;
    srv_clog_get_last_log_req_struct req_data;
    srv_clog_create_struct create;
    srv_clog_get_last_log_cnf_struct cnf_data;
    MMI_BOOL is_bldn_allowed = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* SIM1 AT command or SIM2 AT command */
    module_id = (srv_ucm_module_origin_enum) (SRV_UCM_MODULE_ORIGIN_AT + (mod_src - MOD_L4C));

    /* AT command is not allowed when UCM is busy, CTM is connected or Autoam is started */
    if ((srv_ucm_is_pending_action() == MMI_TRUE) ||
    #ifdef __MMI_AUTO_ANSWER_MACHINE__
        (srv_ucm_autoam_get_state() != SRV_UCM_AUTOAM_STATE_IDLE) ||
    #endif /* __MMI_AUTO_ANSWER_MACHINE__ */
    #ifdef __CTM_SUPPORT__
        (srv_ctm_is_connected() == MMI_TRUE) ||
    #endif /* __CTM_SUPPORT__ */
        MMI_FALSE)
    {
        switch (at_ind->action)
        {
            case RMMI_UCM_ATD:
            case RMMI_UCM_ATD_2:
            case RMMI_UCM_ATD_3:
            case RMMI_UCM_ATD_4:
            case RMMI_UCM_BLDN:
            case RMMI_UCM_MEM_DIAL:
            case RMMI_UCM_MEM_DIAL_2:
            case RMMI_UCM_MEM_DIAL_3:
            case RMMI_UCM_MEM_DIAL_4:
            {
                cause = RMMI_UCM_CAUSE_ATD_NOT_ALLOWED;
            }
            break;

            case RMMI_UCM_ATD_DATA:
            {
                cause = RMMI_UCM_CAUSE_ATD_DATA_NOT_ALLOWED;
            }
            break;

            case RMMI_UCM_ATH:
            case RMMI_UCM_CHUP:
            {
                cause = RMMI_UCM_CAUSE_ATH_NOT_ALLOWED;
            }
            break;

            case RMMI_UCM_ATA:
            {
                cause = RMMI_UCM_CAUSE_ATA_NOT_ALLOWED;
            }
            break;

            case RMMI_UCM_CHLD:
            {
                cause = RMMI_UCM_CAUSE_CHLD_NOT_ALLOWED;
            }
            break;

            default:
            {
                MMI_ASSERT(0);
            }
            break;
        }
        srv_ucm_at_res_req(module_id, at_ind->source_id, MMI_FALSE, cause);
        return;
    }

    switch (at_ind->action)
    {
        case RMMI_UCM_ATD:
        case RMMI_UCM_ATD_2:
        case RMMI_UCM_ATD_3:
        case RMMI_UCM_ATD_4:
        case RMMI_UCM_ATD_DATA:
        case RMMI_UCM_BLDN:
        case RMMI_UCM_MEM_DIAL:
        case RMMI_UCM_MEM_DIAL_2:
        case RMMI_UCM_MEM_DIAL_3:
        case RMMI_UCM_MEM_DIAL_4:

            memset(&dial_req, 0, sizeof(srv_ucm_dial_act_req_struct));
            memset(&hold_and_dial_req, 0, sizeof(srv_ucm_hold_and_dial_act_req_struct));

            ucs2_num = OslMalloc((SRV_UCM_MAX_NUM_URI_LEN + 1) * ENCODING_LENGTH);            
            memset(ucs2_num, 0, ((SRV_UCM_MAX_NUM_URI_LEN + 1) * ENCODING_LENGTH));

            if ((at_ind->action == RMMI_UCM_BLDN) && (at_ind->cmd_from_bt == MMI_TRUE))
            {
                /* BLDN only comes from BT */
                srv_clog_init_para(SRV_CLOG_PARA_CREATE, &create);
                clog_handle =  srv_clog_create((const srv_clog_create_struct *)&create);
                srv_clog_init_para(SRV_CLOG_PARA_GET_LAST_LOG_REQ,  (srv_clog_get_last_log_req_struct*)&req_data);
                srv_clog_init_para(SRV_CLOG_PARA_GET_LAST_LOG_CNF,  (srv_clog_get_last_log_cnf_struct*)&cnf_data);
                req_data.cate = SRV_CLOG_CATE_CALL;
                req_data.log_type =  SRV_CLOG_CLT_DIALED;
                req_data.sub_type = SRV_CLOG_CALL_TYPE_VOICE;
                req_data.fields = 0;

                if (srv_mode_switch_get_current_mode() != SRV_MODE_SWITCH_ALL_OFF)
                {
                    switch (module_id)
                    {
                        case SRV_UCM_MODULE_ORIGIN_AT:
                            req_data.sim_id = MMI_SIM1;
                            break;
                    #if (MMI_MAX_SIM_NUM >= 2)
                        case SRV_UCM_MODULE_ORIGIN_AT_SIM2:
                            req_data.sim_id = MMI_SIM2;
                            break;
                    #if (MMI_MAX_SIM_NUM >= 3)
                        case SRV_UCM_MODULE_ORIGIN_AT_SIM3:
                            req_data.sim_id = MMI_SIM3;
                            break;
                    #if (MMI_MAX_SIM_NUM == 4)
                        case SRV_UCM_MODULE_ORIGIN_AT_SIM4:
                            req_data.sim_id = MMI_SIM4;
                            break;
                    #endif /* (MMI_MAX_SIM_NUM == 4) */
                    #endif /* (MMI_MAX_SIM_NUM >= 3) */
                    #endif /* (MMI_MAX_SIM_NUM >= 2) */
                        default:
                            req_data.sim_id = (mmi_sim_enum)srv_mode_switch_get_current_mode();
                            break;
                    }
                }
                else
                {
                    is_bldn_allowed = MMI_FALSE;
                }

                if ((srv_clog_get_last_log(clog_handle, &req_data, &cnf_data) == SRV_CLOG_RET_OK) && 
                    (is_bldn_allowed == MMI_TRUE))
                {
                    call_type = srv_ucm_query_voice_type_by_sim((mmi_sim_enum)cnf_data.log.data.call_log.sim_id);
                    mmi_ucs2cpy((CHAR *)ucs2_num, (CHAR *)(cnf_data.log.data.call_log.cid));
                    srv_clog_destroy(clog_handle);
                }
                else
                {
                    srv_ucm_at_res_req(module_id, at_ind->source_id, MMI_FALSE, RMMI_UCM_CAUSE_NO_NUM_EXIST);
                    OslMfree(ucs2_num);
                    srv_clog_destroy(clog_handle);
                    break;
                }
            }
            else if ((at_ind->action == RMMI_UCM_MEM_DIAL) ||
                    #if (MMI_MAX_SIM_NUM >= 2)
                        (at_ind->action == RMMI_UCM_MEM_DIAL_2) ||
                    #if (MMI_MAX_SIM_NUM >= 3)
                        (at_ind->action == RMMI_UCM_MEM_DIAL_3) ||
                    #if (MMI_MAX_SIM_NUM == 4)
                        (at_ind->action == RMMI_UCM_MEM_DIAL_4) ||
                    #endif /* (MMI_MAX_SIM_NUM == 4) */
                    #endif /* (MMI_MAX_SIM_NUM >= 3) */
                    #endif /* (MMI_MAX_SIM_NUM >= 2) */
                        MMI_FALSE)
            {
                call_type = srv_ucm_at_query_voice_call_type(module_id);
                switch (at_ind->action)
                {
                #if (MMI_MAX_SIM_NUM >= 2)
                    case RMMI_UCM_MEM_DIAL_2:
                        srv_phb_record_index_to_store_index(PHB_STORAGE_SIM2, at_ind->number[0], &store_index);
                        break;
                #endif /* MMI_MAX_SIM_NUM >= 2 */

                #if (MMI_MAX_SIM_NUM >= 3)
                    case RMMI_UCM_MEM_DIAL_3:
                        srv_phb_record_index_to_store_index(PHB_STORAGE_SIM3, at_ind->number[0], &store_index);
                        break;
                #endif /* MMI_MAX_SIM_NUM >= 3 */

                #if (MMI_MAX_SIM_NUM >= 4)
                    case RMMI_UCM_MEM_DIAL_4:
                        srv_phb_record_index_to_store_index(PHB_STORAGE_SIM4, at_ind->number[0], &store_index);
                        break;
                #endif /* MMI_MAX_SIM_NUM >= 4 */

                    default:
                        srv_phb_record_index_to_store_index(PHB_STORAGE_SIM, at_ind->number[0], &store_index);
                        break;
                }
                if (srv_phb_get_number(store_index, (U16*)ucs2_num, (U16)SRV_UCM_MAX_NUM_URI_LEN) == MMI_FALSE)
                {
                    srv_ucm_at_res_req(module_id, at_ind->source_id, MMI_FALSE, RMMI_UCM_CAUSE_NO_NUM_EXIST);
                    OslMfree(ucs2_num);
                    break;
                }
            }
            else
            {
                /* RMMI_UCM_ATD / RMMI_UCM_ATD_DATA */
                MMI_ASSERT(at_ind->number[at_ind->length] == '\0');

                if (at_ind->cmd_from_bt == MMI_TRUE)
                {
                    /* AT command from BT device */
                    if (at_ind->action == RMMI_UCM_ATD)
                    {
                        call_type = SRV_UCM_VOICE_CALL_TYPE;
                    }
                #if (MMI_MAX_SIM_NUM >= 2)
                    else if (at_ind->action == RMMI_UCM_ATD_2)
                    {
                        call_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
                    }
                #if (MMI_MAX_SIM_NUM >= 3)
                    else if (at_ind->action == RMMI_UCM_ATD_3)
                    {
                        call_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
                    }
                #if (MMI_MAX_SIM_NUM == 4)
                    else if (at_ind->action == RMMI_UCM_ATD_4)
                    {
                        call_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;
                    }
                #endif /* (MMI_MAX_SIM_NUM == 4) */
                #endif /* (MMI_MAX_SIM_NUM >= 3) */
                #endif /* (MMI_MAX_SIM_NUM >= 2) */
                    else/* if (at_ind->action == RMMI_UCM_ATD_DATA) */
                    {
                        call_type = srv_ucm_at_query_data_call_type(module_id);
                    }
                    /* No need to add assert here
                    else
                    {
                        MMI_ASSERT(0);
                    }*/
                }
                else
                {
                    /* AT command not from BT device */
                    if (at_ind->action == RMMI_UCM_ATD)
                    {
                        call_type = srv_ucm_at_query_voice_call_type(module_id);
                    }
                #if (MMI_MAX_SIM_NUM >= 2)
                    else if (at_ind->action == RMMI_UCM_ATD_2)
                    {
                        call_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
                    }
                #if (MMI_MAX_SIM_NUM >= 3)
                    else if (at_ind->action == RMMI_UCM_ATD_3)
                    {
                        call_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
                    }
                #if (MMI_MAX_SIM_NUM == 4)
                    else if (at_ind->action == RMMI_UCM_ATD_4)
                    {
                        call_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;
                    }
                #endif /* (MMI_MAX_SIM_NUM == 4) */
                #endif /* (MMI_MAX_SIM_NUM >= 3) */
                #endif /* (MMI_MAX_SIM_NUM >= 2) */
                    else if (at_ind->action == RMMI_UCM_ATD_DATA)
                    {
                        call_type = srv_ucm_at_query_data_call_type(module_id);
                    }
                    else
                    {
                        MMI_ASSERT(0);
                    }
                }

                len = (at_ind->length > SRV_UCM_MAX_NUM_URI_LEN) ? SRV_UCM_MAX_NUM_URI_LEN : at_ind->length;
                mmi_asc_n_to_ucs2((CHAR *)ucs2_num, (CHAR *)at_ind->number, len);
            }
            /* Notify AT fisrt, that the action is going to perform */
            srv_ucm_at_res_req_success(module_id, at_ind->source_id);

            /* Prepare data for dial action */
            dial_req.call_type = call_type;
            dial_req.is_ip_dial = MMI_FALSE;
            dial_req.module_id = module_id;
            mmi_ucs2ncpy((CHAR *)&dial_req.num_uri, (CHAR *)ucs2_num, SRV_UCM_MAX_NUM_URI_LEN);
            
            /* Prepare data for hold and dial action */
            if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) > 0)
            {
                hold_and_dial_req.dial_call_type = call_type;
                hold_and_dial_req.is_ip_dial = MMI_FALSE;
                hold_and_dial_req.module_id = module_id;
                mmi_ucs2ncpy((CHAR *)&hold_and_dial_req.num_uri, (CHAR *)ucs2_num, SRV_UCM_MAX_NUM_URI_LEN);
                group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
                hold_and_dial_req.active_call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                hold_and_dial_req.active_group = g_ucm_srv_p->call_list.group_info[group_index].group_id;
            }
            
            if (((srv_ucm_is_emergency_number(call_type, (U8*)at_ind->number) == MMI_FALSE) ||
                ((srv_ucm_is_emergency_number(call_type, (U8*)at_ind->number) == MMI_TRUE) &&
                (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0))) &&
                (srv_ucm_query_act_permit(SRV_UCM_DIAL_ACT, &dial_req) == SRV_UCM_RESULT_OK))
            {
                srv_ucm_act_request(SRV_UCM_DIAL_ACT, &dial_req, NULL, NULL);
            }
            else if ((srv_ucm_is_emergency_number(call_type, (U8*)at_ind->number) == MMI_FALSE) &&
                (srv_ucm_query_act_permit(SRV_UCM_HOLD_AND_DIAL_ACT, &hold_and_dial_req) == SRV_UCM_RESULT_OK))
            {
                srv_ucm_act_request(SRV_UCM_HOLD_AND_DIAL_ACT, &hold_and_dial_req, NULL, NULL);
            }
        #ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_AND_DIAL__
            else if ((((srv_ucm_is_emergency_number(call_type, (U8*)at_ind->number) == MMI_TRUE) && 
                (srv_ucm_is_emergency_call() == MMI_FALSE) &&
                !(call_type & SRV_UCM_DATA_CALL_TYPE_ALL)) ||
                ((srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_CALL_TYPE_DATA_CSD_ALL, NULL) > 0) && 
                (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 1) &&
                !(call_type & SRV_UCM_DATA_CALL_TYPE_ALL))) &&
                (srv_ucm_query_act_permit(SRV_UCM_END_ALL_AND_DIAL_ACT, &dial_req) == SRV_UCM_RESULT_OK))
            {
                srv_ucm_act_request(SRV_UCM_END_ALL_AND_DIAL_ACT, &dial_req, NULL, NULL);
            }
        #endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_AND_DIAL__ */
            else
            {
                U8 cause = RMMI_UCM_CAUSE_NONE;
                if (at_ind->action == RMMI_UCM_ATD_DATA)
                {
                    cause = RMMI_UCM_CAUSE_ATD_DATA_NOT_ALLOWED;
                }
                else
                {
                    cause = RMMI_UCM_CAUSE_ATD_NOT_ALLOWED;
                }
                srv_ucm_at_res_req_fail(module_id, at_ind->source_id, cause);
            }
            
            OslMfree(ucs2_num);
            break;

        case RMMI_UCM_ATH:
        case RMMI_UCM_CHUP:
            if ((srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0) ||
            #ifdef __MMI_VIDEO_TELEPHONY__
                ((srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VIDEO_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) > 0) &&
                (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 1)) ||
            #endif /*__MMI_VIDEO_TELEPHONY__*/
                MMI_FALSE)
            {
                group_index = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Active group index */
                call_index = g_ucm_srv_p->call_misc.index_list[0].call_index; /* Active call index */

                if (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0)
                {
                #ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__
                    i = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Held group index */
                    j = g_ucm_srv_p->call_misc.index_list[0].call_index; /* Held call index */
                    /* Notify AT fisrt, that the action is going to perform */
                    srv_ucm_at_res_req_success(module_id, at_ind->source_id);

                    /* Prepare data for end all active and retrieve action */
                    srv_ucm_at_req_prepare_single_call_data(
                                &single_call_req, 
                                g_ucm_srv_p->call_list.group_info[i].call_type, 
                                g_ucm_srv_p->call_list.group_info[i].group_id, 
                                g_ucm_srv_p->call_list.group_info[i].call_info[j].call_id);

                    if (srv_ucm_query_act_permit(SRV_UCM_END_ALL_ACTIVE_AND_RETRIEVE_ACT, &single_call_req) == SRV_UCM_RESULT_OK)
                    {
                        srv_ucm_act_request(SRV_UCM_END_ALL_ACTIVE_AND_RETRIEVE_ACT, &single_call_req, NULL, NULL);
                    }
                    else
                #endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__ */
                    {
                        srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_ATH_NOT_ALLOWED);
                    }
                }
                else if (g_ucm_srv_p->call_list.group_info[group_index].num_call == 1)
                {
                    /* Notify AT fisrt, that the action is going to perform */
                    srv_ucm_at_res_req_success(module_id, at_ind->source_id);

                    /* Prepare data for end single action */
                    srv_ucm_at_req_prepare_single_call_data(
                                &single_call_req, 
                                g_ucm_srv_p->call_list.group_info[group_index].call_type, 
                                g_ucm_srv_p->call_list.group_info[group_index].group_id, 
                                g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id);

                    if (srv_ucm_query_act_permit(SRV_UCM_END_SINGLE_ACT, &single_call_req) == SRV_UCM_RESULT_OK)
                    {
                        srv_ucm_act_request(SRV_UCM_END_SINGLE_ACT, &single_call_req, NULL, NULL);
                    }
                    else
                    {
                        srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_ATH_NOT_ALLOWED);
                    }
                }
                else if (g_ucm_srv_p->call_list.group_info[group_index].num_call > 1)
                {
                    /* Notify AT fisrt, that the action is going to perform */
                    srv_ucm_at_res_req_success(module_id, at_ind->source_id);

                    /* Prepare data for end conference action */
                    srv_ucm_at_req_prepare_single_group_data(
                                &single_group_req, 
                                g_ucm_srv_p->call_list.group_info[group_index].call_type, 
                                g_ucm_srv_p->call_list.group_info[group_index].group_id);

                    if (srv_ucm_query_act_permit(SRV_UCM_END_CONFERENCE_ACT, &single_group_req) == SRV_UCM_RESULT_OK)
                    {
                        srv_ucm_act_request(SRV_UCM_END_CONFERENCE_ACT, &single_group_req, NULL, NULL);
                    }
                    else
                    {
                        srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_ATH_NOT_ALLOWED);
                    }
                }
            }
            else if ((srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0) ||
            #ifdef __MMI_VIDEO_TELEPHONY__
                ((srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_VIDEO_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) > 0) &&
                (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 1)) ||
            #endif /*__MMI_VIDEO_TELEPHONY__*/
                MMI_FALSE)
            {
                group_index = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Outgoing group index */
                call_index = g_ucm_srv_p->call_misc.index_list[0].call_index; /* Outgoing call index */
                /* Notify AT fisrt, that the action is going to perform */
                srv_ucm_at_res_req_success(module_id, at_ind->source_id);

                /* Prepare data for end single action */
                srv_ucm_at_req_prepare_single_call_data(
                            &single_call_req, 
                            g_ucm_srv_p->call_list.group_info[group_index].call_type, 
                            g_ucm_srv_p->call_list.group_info[group_index].group_id, 
                            g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id);

                if (srv_ucm_query_act_permit(SRV_UCM_END_SINGLE_ACT, &single_call_req) == SRV_UCM_RESULT_OK)
                {
                    srv_ucm_act_request(SRV_UCM_END_SINGLE_ACT, &single_call_req, NULL, NULL);
                }
                else
                {
                    srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_ATH_NOT_ALLOWED);
                }
            }
            else if (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0)
            {
                group_index = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Held group index */
                call_index = g_ucm_srv_p->call_misc.index_list[0].call_index; /* Held call index */
                
                if (g_ucm_srv_p->call_list.group_info[group_index].num_call == 1)
                {
                    /* Notify AT fisrt, that the action is going to perform */
                    srv_ucm_at_res_req_success(module_id, at_ind->source_id);

                    /* Prepare data for end single action */
                    srv_ucm_at_req_prepare_single_call_data(
                                &single_call_req, 
                                g_ucm_srv_p->call_list.group_info[group_index].call_type, 
                                g_ucm_srv_p->call_list.group_info[group_index].group_id, 
                                g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id);

                    if (srv_ucm_query_act_permit(SRV_UCM_END_SINGLE_ACT, &single_call_req) == SRV_UCM_RESULT_OK)
                    {
                        srv_ucm_act_request(SRV_UCM_END_SINGLE_ACT, &single_call_req, NULL, NULL);
                    }
                    else
                    {
                        srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_ATH_NOT_ALLOWED);
                    }
                }
                else if (g_ucm_srv_p->call_list.group_info[group_index].num_call > 1)
                {
                    /* Notify AT fisrt, that the action is going to perform */
                    srv_ucm_at_res_req_success(module_id, at_ind->source_id);

                    /* Prepare data for end conference action */
                    srv_ucm_at_req_prepare_single_group_data(
                                &single_group_req, 
                                g_ucm_srv_p->call_list.group_info[group_index].call_type, 
                                g_ucm_srv_p->call_list.group_info[group_index].group_id);

                    if (srv_ucm_query_act_permit(SRV_UCM_END_CONFERENCE_ACT, &single_group_req) == SRV_UCM_RESULT_OK)
                    {
                        srv_ucm_act_request(SRV_UCM_END_CONFERENCE_ACT, &single_group_req, NULL, NULL);
                    }
                    else
                    {
                        srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_ATH_NOT_ALLOWED);
                    }
                }
            }
            else if ((srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0) ||
            #ifdef __MMI_VIDEO_TELEPHONY__
                ((srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_VIDEO_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) > 0) &&
                (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 1)) ||
            #endif /*__MMI_VIDEO_TELEPHONY__*/
                MMI_FALSE)
            {
                group_index = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Incoming group index */
                call_index = g_ucm_srv_p->call_misc.index_list[0].call_index; /* Incoming call index */
                /* Notify AT fisrt, that the action is going to perform */
                srv_ucm_at_res_req_success(module_id, at_ind->source_id);

                /* Prepare data for end single action */
                srv_ucm_at_req_prepare_single_call_data(
                            &single_call_req, 
                            g_ucm_srv_p->call_list.group_info[group_index].call_type, 
                            g_ucm_srv_p->call_list.group_info[group_index].group_id, 
                            g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id);

                if (srv_ucm_query_act_permit(SRV_UCM_END_SINGLE_ACT, &single_call_req) == SRV_UCM_RESULT_OK)
                {
                    srv_ucm_act_request(SRV_UCM_END_SINGLE_ACT, &single_call_req, NULL, NULL);
                }
                else
                {
                    srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_ATH_NOT_ALLOWED);
                }
            }
            else
            {
                srv_ucm_at_res_req(module_id, at_ind->source_id, MMI_FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_HANGUP);
            }
            break;

        case RMMI_UCM_ATA:

            /* SIM1 AT can only answer SIM1 data call, SIM2 AT can only answer SIM2 data call  */
            if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_DATA_CALL_TYPE_ALL, NULL) > 0)
            {
                if (((module_id == SRV_UCM_MODULE_ORIGIN_AT) && (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_DATA_CALL_TYPE, NULL) > 0)) ||
                #if (MMI_MAX_SIM_NUM >= 2)
                    ((module_id == SRV_UCM_MODULE_ORIGIN_AT_SIM2) && (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_DATA_CALL_TYPE_SIM2, NULL) > 0)) ||
                #if (MMI_MAX_SIM_NUM >= 3)
                    ((module_id == SRV_UCM_MODULE_ORIGIN_AT_SIM3) && (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_DATA_CALL_TYPE_SIM3, NULL) > 0)) ||
                #if (MMI_MAX_SIM_NUM == 4)
                    ((module_id == SRV_UCM_MODULE_ORIGIN_AT_SIM4) && (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_DATA_CALL_TYPE_SIM4, NULL) > 0)) ||
                #endif /* (MMI_MAX_SIM_NUM == 4) */
                #endif /* (MMI_MAX_SIM_NUM >= 3) */
                #endif /* (MMI_MAX_SIM_NUM >= 2) */
                    MMI_FALSE)
                {
                    data_ata_not_allowed = MMI_FALSE;
                }
                else
                {
                    data_ata_not_allowed = MMI_TRUE;
                }
            }

            /* RMMI_UCM_ATA cannot answer waiting call */
            if ((srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 1) &&
                (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) > 0) &&
                (data_ata_not_allowed == MMI_FALSE))
            {
                group_index = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Incoming group index */
                call_index = g_ucm_srv_p->call_misc.index_list[0].call_index; /* Incoming call index */
                /* Notify AT fisrt, that the action is going to perform */
                srv_ucm_at_res_req_success(module_id, at_ind->source_id);
                
                /* Prepare data for accept action */
                srv_ucm_at_req_prepare_single_call_data(
                            &single_call_req, 
                            g_ucm_srv_p->call_list.group_info[group_index].call_type, 
                            g_ucm_srv_p->call_list.group_info[group_index].group_id, 
                            g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id);
                
                if (srv_ucm_query_act_permit(SRV_UCM_ACCEPT_ACT, &single_call_req) == SRV_UCM_RESULT_OK)
                {
                    srv_ucm_act_request(SRV_UCM_ACCEPT_ACT, &single_call_req, NULL, NULL);
                }
                else
                {
                    srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_ATA_NOT_ALLOWED);
                }
            }
            else
            {
                srv_ucm_at_res_req(module_id, at_ind->source_id, MMI_FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_ANSWER);
            }
            break;

        case RMMI_UCM_CHLD:

            switch (at_ind->opcode)
            {
                case CSMCC_REL_HELD_OR_UDUB:

                    /* Release waiting call */
                    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), NULL) > 0)
                    {
                        if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0)
                        {
                            group_index = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Waiting group index */
                            call_index = g_ucm_srv_p->call_misc.index_list[0].call_index; /* Waiting call index */
                            /* Notify AT fisrt, that the action is going to perform */
                            srv_ucm_at_res_req_success(module_id, at_ind->source_id);
                            
                            /* Prepare data for accept action */
                            srv_ucm_at_req_prepare_single_call_data(
                                        &single_call_req, 
                                        g_ucm_srv_p->call_list.group_info[group_index].call_type, 
                                        g_ucm_srv_p->call_list.group_info[group_index].group_id, 
                                        g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id);
                            
                            if (srv_ucm_query_act_permit(SRV_UCM_END_SINGLE_ACT, &single_call_req) == SRV_UCM_RESULT_OK)
                            {
                                srv_ucm_act_request(SRV_UCM_END_SINGLE_ACT, &single_call_req, NULL, NULL);
                            }
                            else
                            {
                                srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_NO_CALL_TO_REL);
                            }
                        }
                        else if (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0)
                        {
                            group_index = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Held group index */
                            call_index = g_ucm_srv_p->call_misc.index_list[0].call_index; /* Held call index */

                            if (g_ucm_srv_p->call_list.group_info[group_index].num_call == 1)
                            {
                                /* Notify AT fisrt, that the action is going to perform */
                                srv_ucm_at_res_req_success(module_id, at_ind->source_id);

                                /* Prepare data for end single action */
                                srv_ucm_at_req_prepare_single_call_data(
                                            &single_call_req, 
                                            g_ucm_srv_p->call_list.group_info[group_index].call_type, 
                                            g_ucm_srv_p->call_list.group_info[group_index].group_id, 
                                            g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id);

                                if (srv_ucm_query_act_permit(SRV_UCM_END_SINGLE_ACT, &single_call_req) == SRV_UCM_RESULT_OK)
                                {
                                    srv_ucm_act_request(SRV_UCM_END_SINGLE_ACT, &single_call_req, NULL, NULL);
                                }
                                else
                                {
                                    srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_NO_CALL_TO_REL);
                                }
                            }
                            else if (g_ucm_srv_p->call_list.group_info[group_index].num_call > 1)
                            {
                                /* Notify AT fisrt, that the action is going to perform */
                                srv_ucm_at_res_req_success(module_id, at_ind->source_id);
                        
                                /* Prepare data for end conference action */
                                srv_ucm_at_req_prepare_single_group_data(
                                            &single_group_req, 
                                            g_ucm_srv_p->call_list.group_info[group_index].call_type, 
                                            g_ucm_srv_p->call_list.group_info[group_index].group_id);
                        
                                if (srv_ucm_query_act_permit(SRV_UCM_END_CONFERENCE_ACT, &single_group_req) == SRV_UCM_RESULT_OK)
                                {
                                    srv_ucm_act_request(SRV_UCM_END_CONFERENCE_ACT, &single_group_req, NULL, NULL);
                                }
                                else
                                {
                                    srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_NO_CALL_TO_REL);
                                }
                            }
                            else
                            {
                                srv_ucm_at_res_req(module_id, at_ind->source_id, MMI_FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_REL);
                            }
                        }
                        else
                        {
                            srv_ucm_at_res_req(module_id, at_ind->source_id, MMI_FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_REL);
                        }
                    }
                    else
                    {
                        srv_ucm_at_res_req(module_id, at_ind->source_id, MMI_FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_REL);
                    }
                    break;

                case CSMCC_REL_ACTIVE_AND_ACCEPT:

                #ifdef __MMI_VIDEO_TELEPHONY__
                    if ((srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) > 0) &&
                        (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), NULL) == 0))
                    {
                        /* Active call is not voice/data/csd call type */
                        group_index = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Active group index */

                        if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0)
                        {
                            i = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Incoming group index */
                            j = g_ucm_srv_p->call_misc.index_list[0].call_index; /* Incoming call index */
                            /* Notify AT fisrt, that the action is going to perform */
                            srv_ucm_at_res_req_success(module_id, at_ind->source_id);

                            /* Prepare data for hold and accept action */
                            memset(&hold_and_accept_req, 0, sizeof(srv_ucm_hold_and_accept_act_req_struct));
                            hold_and_accept_req.active_call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                            hold_and_accept_req.active_group = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                            hold_and_accept_req.mt_call_uid.group_id = g_ucm_srv_p->call_list.group_info[i].group_id;
                            hold_and_accept_req.mt_call_uid.call_type = g_ucm_srv_p->call_list.group_info[i].call_type;
                            hold_and_accept_req.mt_call_uid.call_id = g_ucm_srv_p->call_list.group_info[i].call_info[j].call_id;
                            
                            if (srv_ucm_query_act_permit(SRV_UCM_HOLD_AND_ACCEPT_ACT, &hold_and_accept_req) == SRV_UCM_RESULT_OK)
                            {
                                srv_ucm_act_request(SRV_UCM_HOLD_AND_ACCEPT_ACT, &hold_and_accept_req, NULL, NULL);
                            }
                            else
                            {
                                srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_NO_CALL_TO_REL);
                            }
                        }
                        else if (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0)
                        {
                            i = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Held group index */
                            /* Notify AT fisrt, that the action is going to perform */
                            srv_ucm_at_res_req_success(module_id, at_ind->source_id);

                            /* Prepare data for swap action */
                            srv_ucm_at_req_prepare_multiple_group_data(
                                        &multiple_group_req, 
                                        g_ucm_srv_p->call_list.group_info[group_index].call_type, 
                                        g_ucm_srv_p->call_list.group_info[group_index].group_id, 
                                        g_ucm_srv_p->call_list.group_info[i].call_type, 
                                        g_ucm_srv_p->call_list.group_info[i].group_id);

                            if (srv_ucm_query_act_permit(SRV_UCM_SWAP_ACT, &multiple_group_req) == SRV_UCM_RESULT_OK)
                            {
                                srv_ucm_act_request(SRV_UCM_SWAP_ACT, &multiple_group_req, NULL, NULL);
                            }
                            else
                            {
                                srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_NO_CALL_TO_REL);
                            }
                        }
                        else
                        {
                            srv_ucm_at_res_req(module_id, at_ind->source_id, MMI_FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_REL);
                        }
                    }
                    else
                #endif /* __MMI_VIDEO_TELEPHONY__ */
                    if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0)
                    {
                        group_index = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Active group index */
                        call_index = g_ucm_srv_p->call_misc.index_list[0].call_index; /* Active group index */

                        if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0)
                        {
                            i = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Waiting group index */
                            j = g_ucm_srv_p->call_misc.index_list[0].call_index; /* Waiting call index */
                            /* Notify AT fisrt, that the action is going to perform */
                            srv_ucm_at_res_req_success(module_id, at_ind->source_id);
                            
                            /* Prepare data for end single action */
                            srv_ucm_at_req_prepare_single_call_data(
                                        &single_call_req, 
                                        g_ucm_srv_p->call_list.group_info[i].call_type, 
                                        g_ucm_srv_p->call_list.group_info[i].group_id, 
                                        g_ucm_srv_p->call_list.group_info[i].call_info[j].call_id);

                            if (srv_ucm_query_act_permit(SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT, &single_call_req) == SRV_UCM_RESULT_OK)
                            {
                                srv_ucm_act_request(SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT, &single_call_req, NULL, NULL);
                            }
                            else
                            {
                                srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_NO_CALL_TO_REL);
                            }
                        }
                        else if (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0)
                        {
                        #ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__
                            i = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Held group index */
                            /* Notify AT fisrt, that the action is going to perform */
                            srv_ucm_at_res_req_success(module_id, at_ind->source_id);

                            /* Prepare data for end all active and retrieve action */
                            srv_ucm_at_req_prepare_single_group_data(
                                        &single_group_req, 
                                        g_ucm_srv_p->call_list.group_info[i].call_type, 
                                        g_ucm_srv_p->call_list.group_info[i].group_id);
                          
                            if (srv_ucm_query_act_permit(SRV_UCM_END_ALL_ACTIVE_AND_RETRIEVE_ACT, &single_group_req) == SRV_UCM_RESULT_OK)
                            {
                                srv_ucm_act_request(SRV_UCM_END_ALL_ACTIVE_AND_RETRIEVE_ACT, &single_group_req, NULL, NULL);
                            }
                            else
                        #endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__ */
                            {
                                srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_NO_CALL_TO_REL);
                            }
                        }
                        else
                        {
                            if (g_ucm_srv_p->call_list.group_info[group_index].num_call == 1)
                            {
                                /* Notify AT fisrt, that the action is going to perform */
                                srv_ucm_at_res_req_success(module_id, at_ind->source_id);

                                /* Prepare data for end single action */
                                srv_ucm_at_req_prepare_single_call_data(
                                            &single_call_req, 
                                            g_ucm_srv_p->call_list.group_info[group_index].call_type, 
                                            g_ucm_srv_p->call_list.group_info[group_index].group_id, 
                                            g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id);

                                if (srv_ucm_query_act_permit(SRV_UCM_END_SINGLE_ACT, &single_call_req) == SRV_UCM_RESULT_OK)
                                {
                                    srv_ucm_act_request(SRV_UCM_END_SINGLE_ACT, &single_call_req, NULL, NULL);
                                }
                                else
                                {
                                    srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_NO_CALL_TO_REL);
                                }
                            }
                            else if (g_ucm_srv_p->call_list.group_info[group_index].num_call > 1)
                            {
                                /* Notify AT fisrt, that the action is going to perform */
                                srv_ucm_at_res_req_success(module_id, at_ind->source_id);

                                /* Prepare data for end conference action */
                                srv_ucm_at_req_prepare_single_group_data(
                                            &single_group_req, 
                                            g_ucm_srv_p->call_list.group_info[group_index].call_type, 
                                            g_ucm_srv_p->call_list.group_info[group_index].group_id);

                                if (srv_ucm_query_act_permit(SRV_UCM_END_CONFERENCE_ACT, &single_group_req) == SRV_UCM_RESULT_OK)
                                {
                                    srv_ucm_act_request(SRV_UCM_END_CONFERENCE_ACT, &single_group_req, NULL, NULL);
                                }
                                else
                                {
                                    srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_NO_CALL_TO_REL);
                                }
                            }
                        }
                    }
                    else if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), NULL) == 0)
                    {
                        /* RMMI_UCM_CHLD: CSMCC_REL_ACTIVE_AND_ACCEPT can only answer waiting call */

                        if ((srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0) &&
                            (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), NULL) > 0))
                        {
                            group_index = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Waiting group index */
                            call_index = g_ucm_srv_p->call_misc.index_list[0].call_index; /* Waiting call index */
                            /* Notify AT fisrt, that the action is going to perform */
                            srv_ucm_at_res_req_success(module_id, at_ind->source_id);
                            
                            /* Prepare data for accept action */
                            srv_ucm_at_req_prepare_single_call_data(
                                        &single_call_req, 
                                        g_ucm_srv_p->call_list.group_info[group_index].call_type, 
                                        g_ucm_srv_p->call_list.group_info[group_index].group_id, 
                                        g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id);
                            
                            if (srv_ucm_query_act_permit(SRV_UCM_ACCEPT_ACT, &single_call_req) == SRV_UCM_RESULT_OK)
                            {
                                srv_ucm_act_request(SRV_UCM_ACCEPT_ACT, &single_call_req, NULL, NULL);
                            }
                            else
                            {
                                srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_NO_CALL_TO_REL);
                            }
                        }
                        else if (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0)
                        {
                            group_index = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Held group index */

                            /* Notify AT fisrt, that the action is going to perform */
                            srv_ucm_at_res_req_success(module_id, at_ind->source_id);
                            
                            /* Prepare data for end conference action */
                            srv_ucm_at_req_prepare_single_group_data(
                                        &single_group_req, 
                                        g_ucm_srv_p->call_list.group_info[group_index].call_type, 
                                        g_ucm_srv_p->call_list.group_info[group_index].group_id);
                            
                            if (srv_ucm_query_act_permit(SRV_UCM_RETRIEVE_ACT, &single_group_req) == SRV_UCM_RESULT_OK)
                            {
                                srv_ucm_act_request(SRV_UCM_RETRIEVE_ACT, &single_group_req, NULL, NULL);
                            }
                            else
                            {
                                srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_NO_CALL_TO_REL);
                            }
                        }
                        else
                        {
                            srv_ucm_at_res_req(module_id, at_ind->source_id, MMI_FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_REL);
                        }
                    }
                    else
                    {
                        srv_ucm_at_res_req(module_id, at_ind->source_id, MMI_FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_REL);
                    }
                    break;

                case CSMCC_REL_SPECIFIC_CALL:
                {
                    MMI_BOOL hit = MMI_FALSE;

                    for (group_index = 0; group_index < g_ucm_srv_p->call_list.num_group; group_index++)
                    {
                        for (call_index = 0; call_index < g_ucm_srv_p->call_list.group_info[group_index].num_call; call_index++)
                        {
                            if ((g_ucm_srv_p->call_list.group_info[group_index].call_type & SRV_UCM_VOICE_CALL_TYPE_ALL) && 
                                (g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id == at_ind->call_id))
                            {
                                hit = MMI_TRUE;
                                /* Notify AT fisrt, that the action is going to perform */
                                srv_ucm_at_res_req_success(module_id, at_ind->source_id);

                                /* Prepare data for end single action */
                                srv_ucm_at_req_prepare_single_call_data(
                                            &single_call_req, 
                                            g_ucm_srv_p->call_list.group_info[group_index].call_type, 
                                            g_ucm_srv_p->call_list.group_info[group_index].group_id, 
                                            g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id);

                                if (srv_ucm_query_act_permit(SRV_UCM_END_SINGLE_ACT, &single_call_req) == SRV_UCM_RESULT_OK)
                                {
                                    srv_ucm_act_request(SRV_UCM_END_SINGLE_ACT, &single_call_req, NULL, NULL);
                                }
                                else
                                {
                                    srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_INVALID_CALLID);
                                }
                                break;
                            }
                        }
                    }
                    if (MMI_FALSE == hit)
                    {
                        // not find, send back the response
                        srv_ucm_at_res_req(module_id, at_ind->source_id, MMI_FALSE, RMMI_UCM_CAUSE_INVALID_CALLID);
                    }
                }
                break;

                case CSMCC_HOLD_ACTIVE_AND_ACCEPT:

                #ifdef __MMI_VIDEO_TELEPHONY__
                    if ((srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) > 0) &&
                        (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), NULL) == 0))
                    {
                        /* Active call is not voice call type */
                        group_index = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Active group index */

                        if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0)
                        {
                            i = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Incoming group index */
                            j = g_ucm_srv_p->call_misc.index_list[0].call_index; /* Incoming call index */
                            /* Notify AT fisrt, that the action is going to perform */
                            srv_ucm_at_res_req_success(module_id, at_ind->source_id);

                            /* Prepare data for hold and accept action */
                            memset(&hold_and_accept_req, 0, sizeof(srv_ucm_hold_and_accept_act_req_struct));
                            hold_and_accept_req.active_call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                            hold_and_accept_req.active_group = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                            hold_and_accept_req.mt_call_uid.group_id = g_ucm_srv_p->call_list.group_info[i].group_id;
                            hold_and_accept_req.mt_call_uid.call_type = g_ucm_srv_p->call_list.group_info[i].call_type;
                            hold_and_accept_req.mt_call_uid.call_id = g_ucm_srv_p->call_list.group_info[i].call_info[j].call_id;
                            
                            if (srv_ucm_query_act_permit(SRV_UCM_HOLD_AND_ACCEPT_ACT, &hold_and_accept_req) == SRV_UCM_RESULT_OK)
                            {
                                srv_ucm_act_request(SRV_UCM_HOLD_AND_ACCEPT_ACT, &hold_and_accept_req, NULL, NULL);
                            }
                            else
                            {
                                srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_NO_CALL_TO_HOLD);
                            }
                        }
                        else if (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0)
                        {
                            i = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Held group index */
                            /* Notify AT fisrt, that the action is going to perform */
                            srv_ucm_at_res_req_success(module_id, at_ind->source_id);

                            /* Prepare data for swap action */
                            srv_ucm_at_req_prepare_multiple_group_data(
                                        &multiple_group_req, 
                                        g_ucm_srv_p->call_list.group_info[group_index].call_type, 
                                        g_ucm_srv_p->call_list.group_info[group_index].group_id, 
                                        g_ucm_srv_p->call_list.group_info[i].call_type, 
                                        g_ucm_srv_p->call_list.group_info[i].group_id);

                            if (srv_ucm_query_act_permit(SRV_UCM_SWAP_ACT, &multiple_group_req) == SRV_UCM_RESULT_OK)
                            {
                                srv_ucm_act_request(SRV_UCM_SWAP_ACT, &multiple_group_req, NULL, NULL);
                            }
                            else
                            {
                                srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_NO_CALL_TO_HOLD);
                            }
                        }
                        else
                        {
                            srv_ucm_at_res_req(module_id, at_ind->source_id, MMI_FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_HOLD);
                        }
                    }
                    else
                #endif /* __MMI_VIDEO_TELEPHONY__ */
                    if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0)
                    {
                        group_index = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Active group index */
                        call_index = g_ucm_srv_p->call_misc.index_list[0].call_index; /* Active group index */

                        /* 1A1H1W, cannot accept 1W but can swap 1A1H */
                        if (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0)
                        {
                            i = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Held group index */
                            /* Notify AT fisrt, that the action is going to perform */
                            srv_ucm_at_res_req_success(module_id, at_ind->source_id);

                            /* Prepare data for swap action */
                            srv_ucm_at_req_prepare_multiple_group_data(
                                        &multiple_group_req, 
                                        g_ucm_srv_p->call_list.group_info[group_index].call_type, 
                                        g_ucm_srv_p->call_list.group_info[group_index].group_id, 
                                        g_ucm_srv_p->call_list.group_info[i].call_type, 
                                        g_ucm_srv_p->call_list.group_info[i].group_id);

                            if (srv_ucm_query_act_permit(SRV_UCM_SWAP_ACT, &multiple_group_req) == SRV_UCM_RESULT_OK)
                            {
                                srv_ucm_act_request(SRV_UCM_SWAP_ACT, &multiple_group_req, NULL, NULL);
                            }
                            else
                            {
                                srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_NO_CALL_TO_HOLD);
                            }
                        }
                        else if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0)
                        {
                            i = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Incoming group index */
                            j = g_ucm_srv_p->call_misc.index_list[0].call_index; /* Incoming call index */
                            /* Notify AT fisrt, that the action is going to perform */
                            srv_ucm_at_res_req_success(module_id, at_ind->source_id);

                            /* Prepare data for hold and accept action */
                            memset(&hold_and_accept_req, 0, sizeof(srv_ucm_hold_and_accept_act_req_struct));
                            hold_and_accept_req.active_call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                            hold_and_accept_req.active_group = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                            hold_and_accept_req.mt_call_uid.group_id = g_ucm_srv_p->call_list.group_info[i].group_id;
                            hold_and_accept_req.mt_call_uid.call_type = g_ucm_srv_p->call_list.group_info[i].call_type;
                            hold_and_accept_req.mt_call_uid.call_id = g_ucm_srv_p->call_list.group_info[i].call_info[j].call_id;
                            
                            if (srv_ucm_query_act_permit(SRV_UCM_HOLD_AND_ACCEPT_ACT, &hold_and_accept_req) == SRV_UCM_RESULT_OK)
                            {
                                srv_ucm_act_request(SRV_UCM_HOLD_AND_ACCEPT_ACT, &hold_and_accept_req, NULL, NULL);
                            }
                            else
                            {
                                srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_NO_CALL_TO_HOLD);
                            }
                        }
                        else
                        {
                            /* Notify AT fisrt, that the action is going to perform */
                            srv_ucm_at_res_req_success(module_id, at_ind->source_id);

                            /* Prepare data for hold action */
                            srv_ucm_at_req_prepare_single_group_data(
                                        &single_group_req, 
                                        g_ucm_srv_p->call_list.group_info[group_index].call_type, 
                                        g_ucm_srv_p->call_list.group_info[group_index].group_id);
                            
                            if (srv_ucm_query_act_permit(SRV_UCM_HOLD_ACT, &single_group_req) == SRV_UCM_RESULT_OK)
                            {
                                srv_ucm_act_request(SRV_UCM_HOLD_ACT, &single_group_req, NULL, NULL);
                            }
                            else
                            {
                                srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_NO_CALL_TO_HOLD);
                            }
                        }
                    }
                    else if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), NULL) == 0)
                    {
                        /* RMMI_UCM_CHLD: CSMCC_HOLD_ACTIVE_AND_ACCEPT can only answer waiting call */
                        if ((srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0) &&
                            (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 1))
                        {
                            group_index = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Incoming group index */
                            call_index = g_ucm_srv_p->call_misc.index_list[0].call_index; /* Incoming call index */
                            /* Notify AT fisrt, that the action is going to perform */
                            srv_ucm_at_res_req_success(module_id, at_ind->source_id);

                            /* Prepare data for accept action */
                            srv_ucm_at_req_prepare_single_call_data(
                                        &single_call_req, 
                                        g_ucm_srv_p->call_list.group_info[group_index].call_type, 
                                        g_ucm_srv_p->call_list.group_info[group_index].group_id, 
                                        g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id);
                            
                            if (srv_ucm_query_act_permit(SRV_UCM_ACCEPT_ACT, &single_call_req) == SRV_UCM_RESULT_OK)
                            {
                                srv_ucm_act_request(SRV_UCM_ACCEPT_ACT, &single_call_req, NULL, NULL);
                            }
                            else
                            {
                                srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_NO_CALL_TO_HOLD);
                            }
                        }
                        else if (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0)
                        {
                            group_index = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Held group index */
                            call_index = g_ucm_srv_p->call_misc.index_list[0].call_index; /* Held call index */
                            /* Notify AT fisrt, that the action is going to perform */
                            srv_ucm_at_res_req_success(module_id, at_ind->source_id);

                            /* Prepare data for retrieve action */
                            srv_ucm_at_req_prepare_single_group_data(
                                        &single_group_req, 
                                        g_ucm_srv_p->call_list.group_info[group_index].call_type, 
                                        g_ucm_srv_p->call_list.group_info[group_index].group_id);
                            
                            if (srv_ucm_query_act_permit(SRV_UCM_RETRIEVE_ACT, &single_group_req) == SRV_UCM_RESULT_OK)
                            {
                                srv_ucm_act_request(SRV_UCM_RETRIEVE_ACT, &single_group_req, NULL, NULL);
                            }
                            else
                            {
                                srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_NO_CALL_TO_HOLD);
                            }
                        }
                        else
                        {
                            srv_ucm_at_res_req(module_id, at_ind->source_id, MMI_FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_HOLD);
                        }
                    }
                    else
                    {
                        srv_ucm_at_res_req(module_id, at_ind->source_id, MMI_FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_HOLD);
                    }
                    break;

                case CSMCC_HOLD_ACTIVE_EXCEPT_SPECIFIC_CALL:
                    
                    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) > 0)
                    {
                        group_index = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Active group index */

                        unique_id.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                        unique_id.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                        unique_id.call_id = at_ind->call_id;

                        if((at_ind->call_id != SRV_UCM_INVALID_ID) && (srv_ucm_query_index_by_id(&unique_id, &index) == MMI_TRUE))
                        {
                            /* Notify AT fisrt, that the action is going to perform */
                            srv_ucm_at_res_req_success(module_id, at_ind->source_id);

                            /* Prepare data for accept action */
                            srv_ucm_at_req_prepare_single_call_data(
                                        &single_call_req, 
                                        g_ucm_srv_p->call_list.group_info[group_index].call_type, 
                                        g_ucm_srv_p->call_list.group_info[group_index].group_id, 
                                        g_ucm_srv_p->call_list.group_info[group_index].call_info[index.call_index].call_id);
                            
                            if (srv_ucm_query_act_permit(SRV_UCM_SPLIT_ACT, &single_call_req) == SRV_UCM_RESULT_OK)
                            {
                                srv_ucm_act_request(SRV_UCM_SPLIT_ACT, &single_call_req, NULL, NULL);
                            }
                            else
                            {
                                srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_INVALID_CALLID);
                            }
                        }
                        else
                        {
                            srv_ucm_at_res_req(module_id, at_ind->source_id, MMI_FALSE, RMMI_UCM_CAUSE_INVALID_CALLID);
                        }
                    }
                    else
                    {
                        srv_ucm_at_res_req(module_id, at_ind->source_id, MMI_FALSE, RMMI_UCM_CAUSE_INVALID_CALLID);
                    }
                    break;

                case CSMCC_ADD_HELD_CALL:

                    if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0)
                    {
                        group_index = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Active group index */

                        if (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0)
                        {
                            i = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Held group index */
                            /* Notify AT fisrt, that the action is going to perform */
                            srv_ucm_at_res_req_success(module_id, at_ind->source_id);

                            /* Prepare data for swap action */
                            srv_ucm_at_req_prepare_multiple_group_data(
                                        &multiple_group_req, 
                                        g_ucm_srv_p->call_list.group_info[group_index].call_type, 
                                        g_ucm_srv_p->call_list.group_info[group_index].group_id, 
                                        g_ucm_srv_p->call_list.group_info[i].call_type, 
                                        g_ucm_srv_p->call_list.group_info[i].group_id);

                            if (srv_ucm_query_act_permit(SRV_UCM_CONFERENCE_ACT, &multiple_group_req) == SRV_UCM_RESULT_OK)
                            {
                                srv_ucm_act_request(SRV_UCM_CONFERENCE_ACT, &multiple_group_req, NULL, NULL);
                            }
                            else
                            {
                                srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_NO_CALL_TO_CONFERENCE);
                            }
                        }
                        else
                        {
                            srv_ucm_at_res_req(module_id, at_ind->source_id, MMI_FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_CONFERENCE);
                        }
                    }
                    else
                    {
                        srv_ucm_at_res_req(module_id, at_ind->source_id, MMI_FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_CONFERENCE);
                    }
                    break;

                case CSMCC_EXPLICIT_CALL_TRANSFER:
                #ifdef __MMI_UCM_ECT__
                    if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0)
                    {
                        group_index = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Outgoing group index */

                        if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0)
                        {
                            i = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Active group index */
                        }
                        else if (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0)
                        {
                            i = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Held group index */
                        }
                        /* Notify AT fisrt, that the action is going to perform */
                        srv_ucm_at_res_req_success(module_id, at_ind->source_id);
                    
                        /* Prepare data for swap action */
                        memset(&ect_req, 0, sizeof(srv_ucm_ect_act_req_struct));
                        ect_req.first_call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                        ect_req.first_group = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                        ect_req.second_call_type = g_ucm_srv_p->call_list.group_info[i].call_type;
                        ect_req.second_group = g_ucm_srv_p->call_list.group_info[i].group_id;
                    
                        if (srv_ucm_query_act_permit(SRV_UCM_EXPLICIT_CALL_TRANSFER_ACT, &ect_req) == SRV_UCM_RESULT_OK)
                        {
                            srv_ucm_act_request(SRV_UCM_EXPLICIT_CALL_TRANSFER_ACT, &ect_req, NULL, NULL);
                        }
                        else
                        {
                            srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_NO_CALL_TO_ECT);
                        }
                    }
                    else
                    {
                        /* No outgoing call */

                        if (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0)
                        {
                            group_index = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Held group index */
                        
                            if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0)
                            {
                                i = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Active group index */
                                /* Notify AT fisrt, that the action is going to perform */
                                srv_ucm_at_res_req_success(module_id, at_ind->source_id);
                                
                                /* Prepare data for swap action */
                                memset(&ect_req, 0, sizeof(srv_ucm_ect_act_req_struct));
                                ect_req.first_call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                                ect_req.first_group = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                                ect_req.second_call_type = g_ucm_srv_p->call_list.group_info[i].call_type;
                                ect_req.second_group = g_ucm_srv_p->call_list.group_info[i].group_id;
                                
                                if (srv_ucm_query_act_permit(SRV_UCM_EXPLICIT_CALL_TRANSFER_ACT, &ect_req) == SRV_UCM_RESULT_OK)
                                {
                                    srv_ucm_act_request(SRV_UCM_EXPLICIT_CALL_TRANSFER_ACT, &ect_req, NULL, NULL);
                                }
                                else
                                {
                                    srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_NO_CALL_TO_ECT);
                                }
                            }
                            else
                            {
                                /* No call to do ECT with Held call */
                                srv_ucm_at_res_req(module_id, at_ind->source_id, MMI_FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_ECT);
                            }
                        }
                        else
                        {
                            /* No held call */
                            srv_ucm_at_res_req(module_id, at_ind->source_id, MMI_FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_ECT);
                        }
                    }
                #else /* __MMI_UCM_ECT__ */
                    srv_ucm_at_res_req(module_id, at_ind->source_id, MMI_FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_ECT);
                #endif /* __MMI_UCM_ECT__ */
                    break;

                case CSMCC_ACTIVATE_CCBS_CALL:
                    srv_ucm_at_res_req(module_id, at_ind->source_id, MMI_FALSE, RMMI_UCM_CAUSE_CHLD_NOT_ALLOWED);
                    break;

                case CSMCC_REL_SPECIFIC_ACTIVE_CALL:

                    if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0)
                    {
                        group_index = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Active group index */

                        unique_id.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                        unique_id.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                        unique_id.call_id = at_ind->call_id;
                        if ((at_ind->call_id != SRV_UCM_INVALID_ID) && (srv_ucm_query_index_by_id(&unique_id, &index) == MMI_TRUE))
                        {
                            if ((at_ind->cmd_from_bt == MMI_TRUE) &&
                                (g_ucm_srv_p->call_list.group_info[group_index].num_call == 1) && 
                                (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), g_ucm_srv_p->call_misc.index_list) > 0))
                            {
                            #ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__
                                i = g_ucm_srv_p->call_misc.index_list[0].group_index; /* Held group index */
                                /* Notify AT fisrt, that the action is going to perform */
                                srv_ucm_at_res_req_success(module_id, at_ind->source_id);
                                
                                /* Prepare data for end all active and retrieve action */
                                srv_ucm_at_req_prepare_single_group_data(
                                            &single_group_req, 
                                            g_ucm_srv_p->call_list.group_info[i].call_type, 
                                            g_ucm_srv_p->call_list.group_info[i].group_id);
                                
                                if (srv_ucm_query_act_permit(SRV_UCM_END_ALL_ACTIVE_AND_RETRIEVE_ACT, &single_group_req) == SRV_UCM_RESULT_OK)
                                {
                                    srv_ucm_act_request(SRV_UCM_END_ALL_ACTIVE_AND_RETRIEVE_ACT, &single_group_req, NULL, NULL);
                                }
                                else
                            #endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__ */
                                {
                                    srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_INVALID_CALLID);
                                }
                            }
                            else
                            {
                                /* Notify AT fisrt, that the action is going to perform */
                                srv_ucm_at_res_req_success(module_id, at_ind->source_id);
                        
                                /* Prepare data for end single action */
                                srv_ucm_at_req_prepare_single_call_data(
                                            &single_call_req, 
                                            g_ucm_srv_p->call_list.group_info[index.group_index].call_type, 
                                            g_ucm_srv_p->call_list.group_info[index.group_index].group_id, 
                                            g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].call_id);
                        
                                if (srv_ucm_query_act_permit(SRV_UCM_END_SINGLE_ACT, &single_call_req) == SRV_UCM_RESULT_OK)
                                {
                                    srv_ucm_act_request(SRV_UCM_END_SINGLE_ACT, &single_call_req, NULL, NULL);
                                }
                                else
                                {
                                    srv_ucm_at_res_req_fail(module_id, at_ind->source_id, RMMI_UCM_CAUSE_INVALID_CALLID);
                                }
                            }
                        }
                        else
                        {
                            srv_ucm_at_res_req(module_id, at_ind->source_id, MMI_FALSE, RMMI_UCM_CAUSE_INVALID_CALLID);
                        }
                    }
                    else
                    {
                        srv_ucm_at_res_req(module_id, at_ind->source_id, MMI_FALSE, RMMI_UCM_CAUSE_INVALID_CALLID);
                    }
                    break;

                case CSMCC_REL_ALL:

                    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL), NULL) > 0)
                    {
                        /* Notify AT fisrt, that the action is going to perform */
                        srv_ucm_at_res_req_success(module_id, at_ind->source_id);

                        /* Perform the action */
                        g_ucm_srv_p->call_misc.curr_action = SRV_UCM_END_ALL_ACT;
                        srv_ucm_end_all_action_with_call_type((srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_CALL_TYPE_DATA_CSD_ALL));
                    }
                    else
                    {
                        srv_ucm_at_res_req(module_id, at_ind->source_id, MMI_FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_HANGUP);
                    }
                    break;

                default:
                    MMI_ASSERT(0); /* not valid op_code */
                    break;
            }
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_at_res_req
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_at_res_req(srv_ucm_module_origin_enum module_id, U8 source, U8 result, U8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_ucm_at_res_req_struct *msg_req;
    msg_req = (mmi_ucm_at_res_req_struct*)OslConstructDataPtr(sizeof(mmi_ucm_at_res_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_req->source_id = source;
    msg_req->result = result;
    msg_req->cause = cause;

    mmi_frm_send_ilm((oslModuleType) (MOD_L4C + (module_id - SRV_UCM_MODULE_ORIGIN_AT)), MSG_ID_MMI_UCM_AT_RES_REQ, (oslParaType*) msg_req, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_at_general_req
 * DESCRIPTION
 *  General reuest to AT
 * PARAMETERS
 *  module_id:      [IN]            Module id
 *  rcode_type:     [IN]            Retrun code type
 *  at_info:        [IN]            AT info that needs to bypass by UCM
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_at_general_req(srv_ucm_module_origin_enum module_id, U8 rcode_type, U8 call_id, srv_ucm_int_at_info_struct *at_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_general_rcode_req_struct *msg_req;
    msg_req = (mmi_ucm_general_rcode_req_struct*)OslConstructDataPtr(sizeof(mmi_ucm_general_rcode_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_req->source_id = at_info->l4c_source;
    msg_req->type = rcode_type;
    msg_req->call_id = call_id;
    msg_req->call_type = at_info->l4c_type;
    memcpy(&msg_req->number, &at_info->l4c_number, sizeof(l4c_number_struct));

    mmi_frm_send_ilm((oslModuleType) (MOD_L4C + (module_id - SRV_UCM_MODULE_ORIGIN_AT)), MSG_ID_MMI_UCM_GENERAL_RCODE_REQ, (oslParaType*) msg_req, NULL);
}

#ifdef __BT_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_ucm_sync_call_state_to_headset
 * DESCRIPTION
 *  Sync call state to bluetooth handfree profile with the order 
 *  1. call 
 *  2. call setup
 *  3. call held 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_sync_call_state_to_headset()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_call_type_enum sync_call_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_VIDEO_TELEPHONY__
    sync_call_type = SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_VIDEO_CALL_TYPE_ALL;
#else
    sync_call_type = SRV_UCM_VOICE_CALL_TYPE_ALL;
#endif

    if (srv_ucm_query_group_count(SRV_UCM_ACTIVE_STATE, sync_call_type, MMI_FALSE, NULL) > 0)
    {
        srv_ucm_bt_send_multiple_sim_ciev_req(RMMI_CIND_CALL, RMMI_CIND_CC_ACTIVE);

        if (srv_ucm_query_group_count(SRV_UCM_HOLD_STATE, sync_call_type, MMI_FALSE, NULL) > 0)
        {
            /* active call + held call */
            srv_ucm_bt_send_multiple_sim_ciev_req(RMMI_CIND_CALLHELD, RMMI_CIND_HELD_ACTIVE_HOLD);
        }
        else
        {
            /* only active call */
            srv_ucm_bt_send_multiple_sim_ciev_req(RMMI_CIND_CALLHELD, RMMI_CIND_HELD_NONE);
        }
    }
    else if (srv_ucm_query_group_count(SRV_UCM_HOLD_STATE, SRV_UCM_VOICE_CALL_TYPE_ALL, MMI_FALSE, NULL) > 0)
    {
        /* for the sake of supporting BT headset before version 1.5 */
        srv_ucm_bt_send_multiple_sim_ciev_req(RMMI_CIND_CALL, RMMI_CIND_CC_ACTIVE);
        
        srv_ucm_bt_send_multiple_sim_ciev_req(RMMI_CIND_CALLHELD, RMMI_CIND_HELD_HOLD);

    #ifdef __MMI_VIDEO_TELEPHONY__
        sync_call_type = SRV_UCM_VOICE_CALL_TYPE_ALL;
    #endif
    }
    else
    {
        srv_ucm_bt_send_multiple_sim_ciev_req(RMMI_CIND_CALL, RMMI_CIND_CC_NONE);

        if (srv_ucm_query_group_count(SRV_UCM_HOLD_STATE, sync_call_type, MMI_FALSE, NULL) > 0)
        {
            /* only held call */
            srv_ucm_bt_send_multiple_sim_ciev_req(RMMI_CIND_CALLHELD, RMMI_CIND_HELD_HOLD);
        }
        else
        {
            /* no active call + no held call */
            srv_ucm_bt_send_multiple_sim_ciev_req(RMMI_CIND_CALLHELD, RMMI_CIND_HELD_NONE);
        }
    }

    if (srv_ucm_query_group_count(SRV_UCM_OUTGOING_STATE, sync_call_type, MMI_FALSE, NULL) > 0)
    {
        srv_ucm_bt_send_multiple_sim_ciev_req(RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_OUTGOING);
    }
    else if (srv_ucm_query_group_count(SRV_UCM_INCOMING_STATE, sync_call_type, MMI_FALSE, NULL) > 0)
    {
        srv_ucm_bt_send_multiple_sim_ciev_req(RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_INCOMING);
    }
    else
    {
        srv_ucm_bt_send_multiple_sim_ciev_req(RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_NONE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_bt_handfree_ciev_req
 * DESCRIPTION
 *  CIEV request
 * PARAMETERS
 *  module_id       [IN]            Module id
 *  type            [IN]            Indicator type
 *  event           [IN]            Event value
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_bt_handfree_ciev_req(mmi_sim_enum sim_id, U8 type, U8 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_ucm_hf_ciev_rcode_req_struct *msg_req;
    msg_req = (mmi_ucm_hf_ciev_rcode_req_struct*)OslConstructDataPtr(sizeof(mmi_ucm_hf_ciev_rcode_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg_req->ind_type = type;
    msg_req->event= event;

    mmi_frm_send_ilm(mmi_frm_sim_to_l4c_mod(sim_id), MSG_ID_MMI_UCM_HF_CIEV_RCODE_REQ, (oslParaType*) msg_req, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_bt_send_multiple_sim_ciev_req
 * DESCRIPTION
 *  Send the ciev request to BT in order to sync call state.
 *  It will send to all of sim cards.
 * PARAMETERS
 *  type            [IN]            Indicator type
 *  event           [IN]            Call status event
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_bt_send_multiple_sim_ciev_req(U8 type, U8 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_handfree_ciev_req(MMI_SIM1, type, event);
#if (MMI_MAX_SIM_NUM >= 2)
    srv_ucm_bt_handfree_ciev_req(MMI_SIM2, type, event);
#if (MMI_MAX_SIM_NUM >= 3)
    srv_ucm_bt_handfree_ciev_req(MMI_SIM3, type, event);
#if (MMI_MAX_SIM_NUM == 4)
    srv_ucm_bt_handfree_ciev_req(MMI_SIM4, type, event);
#endif /* (MMI_MAX_SIM_NUM == 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */
}
#endif /* __BT_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_ucm_at_query_voice_call_type
 * DESCRIPTION
 *  Get ucm service voice call type by at origin
 * PARAMETERS
 *  at_origin       [IN]        from which at interface
 * RETURNS
 *  voice call type
 *****************************************************************************/
srv_ucm_call_type_enum srv_ucm_at_query_voice_call_type(srv_ucm_module_origin_enum at_origin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_call_type_enum call_type = SRV_UCM_VOICE_CALL_TYPE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (at_origin)
    {
        case SRV_UCM_MODULE_ORIGIN_AT:
            call_type = SRV_UCM_VOICE_CALL_TYPE;
            break;
    #if (MMI_MAX_SIM_NUM >= 2)
        case SRV_UCM_MODULE_ORIGIN_AT_SIM2:
            call_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
            break;
    #if (MMI_MAX_SIM_NUM >= 3)
        case SRV_UCM_MODULE_ORIGIN_AT_SIM3:
            call_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
            break;
    #if (MMI_MAX_SIM_NUM == 4)
        case SRV_UCM_MODULE_ORIGIN_AT_SIM4:
            call_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;
            break;
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        default:
            MMI_ASSERT(0);
            break;
    }
    return call_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ucm_at_query_data_call_type
 * DESCRIPTION
 *  Get ucm service data call type by at origin
 * PARAMETERS
 *  at_origin       [IN]        from which at interface
 * RETURNS
 *  data call type
 *****************************************************************************/
srv_ucm_call_type_enum srv_ucm_at_query_data_call_type(srv_ucm_module_origin_enum at_origin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_call_type_enum call_type = SRV_UCM_DATA_CALL_TYPE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (at_origin)
    {
        case SRV_UCM_MODULE_ORIGIN_AT:
            call_type = SRV_UCM_DATA_CALL_TYPE;
            break;
    #if (MMI_MAX_SIM_NUM >= 2)
        case SRV_UCM_MODULE_ORIGIN_AT_SIM2:
            call_type = SRV_UCM_DATA_CALL_TYPE_SIM2;
            break;
    #if (MMI_MAX_SIM_NUM >= 3)
        case SRV_UCM_MODULE_ORIGIN_AT_SIM3:
            call_type = SRV_UCM_DATA_CALL_TYPE_SIM3;
            break;
    #if (MMI_MAX_SIM_NUM == 4)
        case SRV_UCM_MODULE_ORIGIN_AT_SIM4:
            call_type = SRV_UCM_DATA_CALL_TYPE_SIM4;
            break;
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        default:
            MMI_ASSERT(0);
            break;
    }
    return call_type;
}


