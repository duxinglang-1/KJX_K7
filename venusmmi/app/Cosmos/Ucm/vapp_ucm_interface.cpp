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
 *  vapp_ucm_interface.cpp
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  UCM exported APIs source file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "MMI_features.h"

#ifdef __MMI_UCM__
#include "mmi_rp_core_ucm_def.h"
#include "mmi_rp_vapp_ucm_def.h"

#ifdef __MMI_URI_AGENT__
#include "vapp_ucm_uha_prot.h"
#endif /* __MMI_URI_AGENT__ */  

extern "C"
{
    #include "UCMProt.h"
    #include "UCMGProt.h"    
    #include "UcmCoreProt.h"
    #include "UcmSrvGProt.h"
    #include "NwInfoSrvGprot.h" /* srv_nw_info_get_protocol */  
#ifdef __MMI_VIDEO_TELEPHONY__
    #include "ModeSwitchSrvGprot.h" /* srv_mode_switch_is_network_service_available , srv_mode_switch_get_current_mode */
#endif /* __MMI_VIDEO_TELEPHONY__ */

#ifdef __MMI_VIDEO_TELEPHONY__
    #include "SimCtrlSrvGprot.h" /* srv_sim_ctrl_get_unavailable_cause */
#endif /* __MMI_VIDEO_TELEPHONY__ */
    #include "MMIDataType.h"
    #include "kal_general_types.h"
    #include "DebugInitDef_Int.h"
    #include "kal_trace.h"
    #include "mmi_common_app_trc.h"
    #include "string.h"
    #include "kal_public_api.h"
    #include "CustDataRes.h"
    #include "mmi_frm_events_gprot.h"
    #include "GlobalResDef.h"
    #include "gui_data_types.h"
    #include "AlertScreen.h"
    #include "Unicodexdcl.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "CustMenuRes.h"
    #include "wgui_categories_list.h"
    #include "GlobalConstants.h"
    #include "mmi_frm_input_gprot.h"
    #include "NetSetSrvGprot.h"
    #include "NetSetAppGprot.h"
    #include "SimCtrlSrvGprot.h" /* srv_sim_ctrl_get_unavailable_cause */
    #include "Phbsrvgprot.h" /* srv_phb_set_preferred_sim */
    #include "Custom_ecc.h" /* ecc_call_type_enum */
}

mmi_ucm_cntx_struct g_mmi_ucm_cntx;
mmi_ucm_cntx_struct *g_ucm_p = &g_mmi_ucm_cntx;
extern void vapp_ucm_display_popup(srv_ucm_result_enum result);

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_init_context
 * DESCRIPTION
 *  Initialize UCM app context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_init_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // Special init context for venusmmi
    memset(&g_ucm_p->call_misc.index_list, -1, (SRV_UCM_MAX_CALL * sizeof(srv_ucm_index_info_struct)));
    g_ucm_p->call_misc.is_dtmf = MMI_TRUE;
    g_ucm_p->call_misc.hilite_tab = -1;
    mmi_ucm_set_act_request_callback(mmi_ucm_act_callback);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_init
 * DESCRIPTION
 *  Initialize UCM application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_init_context();
    mmi_core_ucm_init_context();
#ifdef __MMI_URI_AGENT__
    mmi_ucm_uha_init();
#endif /* __MMI_URI_AGENT__ */

#ifdef __MMI_VIDEO_TELEPHONY__
    mmi_ucm_vt_init();
#endif /* __MMI_VIDEO_TELEPHONY__ */
}

extern void vapp_ucm_set_preferred_sim()
{
    /* Set preferred sim */
    mmi_sim_enum sim = MMI_SIM_NONE;
    srv_phb_cm_number_struct phb_num;    
    srv_phb_caller_info_struct phb_data;
    S32 res;
    U16 num_uri[SRV_UCM_MAX_NUM_URI_LEN+1];
    memset(num_uri, 0, sizeof(num_uri));
    mmi_asc_n_to_ucs2((CHAR*)num_uri, (CHAR*)g_ucm_p->mo_info.dial_num.num_uri, strlen((char*)g_ucm_p->mo_info.dial_num.num_uri));
    memset(&phb_num, 0, sizeof(srv_phb_cm_number_struct));
    memset(&phb_data, 0, sizeof(srv_phb_caller_info_struct));
    phb_num.number = num_uri;
    phb_num.is_mo_call = MMI_TRUE;
    if (g_ucm_p->mo_info.dial_type & SRV_UCM_SIM1_CALL_TYPE_ALL)
    {
        sim = MMI_SIM1;
        phb_num.sim_interface = SIM1;
        phb_num.call_type = ECC_SIM1_CALL;
    }
#if (MMI_MAX_SIM_NUM >= 2)
    if (g_ucm_p->mo_info.dial_type & SRV_UCM_SIM2_CALL_TYPE_ALL)
    {
        sim = MMI_SIM2;
        phb_num.sim_interface = SIM2;
        phb_num.call_type = ECC_SIM2_CALL;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if (g_ucm_p->mo_info.dial_type & SRV_UCM_SIM3_CALL_TYPE_ALL)
    {
        sim = MMI_SIM3;
        phb_num.sim_interface = SIM3;
        phb_num.call_type = ECC_SIM3_CALL;
    }
#if (MMI_MAX_SIM_NUM == 4)
    else if (g_ucm_p->mo_info.dial_type & SRV_UCM_SIM4_CALL_TYPE_ALL)
    {
        sim = MMI_SIM4;
        phb_num.sim_interface = SIM4;
        phb_num.call_type = ECC_SIM4_CALL;
    }
#endif /* (MMI_MAX_SIM_NUM == 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */
    phb_num.user_data = g_ucm_p->mo_info.phb_data;
    srv_phb_get_caller_info_by_number(&phb_num, &phb_data);
    res = srv_phb_set_preferred_sim(num_uri, MMI_PHB_INVALID_CONTACT_ID, sim, SRV_PHB_NUMBER_OP_TYPE_DIAL);

    MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_SET_PREF_SIM, res, sim);
}

extern void vapp_ucm_end_key_handler(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_key
 * DESCRIPTION
 *  end key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ucm_end_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vapp_ucm_end_key_handler();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_marker_scrn_id
 * DESCRIPTION
 *  get marker screen id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern U16 mmi_ucm_get_marker_scrn_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_init_call_para
 * DESCRIPTION
 * initialize make call parameter. The default value is for common use 
 * PARAMETERS
 *  make_call_para:            [IN]      Make call parameter.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ucm_init_call_para(mmi_ucm_make_call_para_struct *make_call_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(make_call_para, 0, sizeof(mmi_ucm_make_call_para_struct));   
    make_call_para->dial_type = SRV_UCM_CALL_TYPE_NO_DATA_CSD;
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_init_call_para_for_sendkey
 * DESCRIPTION
 * initialize make call parameter for sendkey triggered behaviors. 
 * The default value of dial type will be the type which is decided when pressing send key 
 * PARAMETERS
 *  make_call_para:            [IN]      Make call parameter.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_init_call_para_for_sendkey(mmi_ucm_make_call_para_struct *make_call_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(make_call_para, 0, sizeof(mmi_ucm_make_call_para_struct));
    make_call_para->dial_type = g_ucm_p->call_misc.sendkeys_makecall_dial_type;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_call_launch
 * DESCRIPTION
 *  Dial call api
 *  Dial_type is not allowed to be bitwised,
 *  If disallow to make call, will popup error message
 *  Before filling in make_call_para structure, caller can use mmi_ucm_init_call_para or mmi_ucm_init_call_para_for_sendkey
 *  to init structure first, and then fill in specific parameters as required.
 * PARAMETERS
 *  caller_gid:                [IN]      caller screen group id. before group screen mechanism is ready, fill 0 always
 *  make_call_para:            [IN]      Make call parameter.
 * RETURNS
 *  Return ucm app group screen id, before group screen mechanism is ready, return 0 always
 *****************************************************************************/
extern U16 mmi_ucm_call_launch(U16 caller_gid, mmi_ucm_make_call_para_struct *make_call_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 unicodeLen = 0;
    srv_ucm_dial_act_req_struct check_act_req;
    srv_ucm_act_opcode_enum first_permit_act_op = SRV_UCM_NO_ACT;
    srv_ucm_result_enum tmp_permit_result = SRV_UCM_RESULT_UNSPECIFIED_ERROR;
    srv_ucm_result_enum first_permit_result = SRV_UCM_RESULT_UNSPECIFIED_ERROR;
    srv_ucm_hold_and_dial_act_req_struct hold_and_dial_req;
    S32 group_index_array[SRV_UCM_MAX_GROUP];
    srv_ucm_group_info_struct group_info;
    mmi_ucm_ecc_hdlr_enum ECC_result;
    srv_ucm_call_type_enum  available_call_type = (srv_ucm_call_type_enum)0;
            
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_CALL_LAUNCH_P2, make_call_para->dial_type, mmi_ucs2strlen((CHAR*)make_call_para->ucs2_num_uri));
    /*These parameter should set here for mmi_ucm_exec_dial_cb_by_result*/
    g_ucm_p->mo_info.callback = make_call_para->adv_para.after_make_call_callback;
    g_ucm_p->mo_info.callback_para = make_call_para->adv_para.after_callback_user_data;
    mmi_ucm_set_act_request_dial_user_data(g_ucm_p->mo_info.callback_para);

    /* 2. if the input number is a SS, mCare, CRSS,  launch corresponding application*/
    if (srv_ucm_intercept(make_call_para->dial_type, make_call_para->ucs2_num_uri, make_call_para->adv_para.module_id) == MMI_TRUE)
    {
        mmi_ucm_exec_dial_cb_by_result(SRV_UCM_RESULT_OK);
        return GRP_ID_INVALID; 
    }

    /* 3. Check if ECC already exists */   
    if (srv_ucm_is_emergency_call())
    {
        //TBD: mmi_popup_display((WCHAR*)((UI_string_type) GetString(srv_ucm_query_error_message(SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL))), MMI_EVENT_FAILURE, NULL);
        vapp_ucm_display_popup(SRV_UCM_RESULT_SOS_CALL_EXISTS);
        mmi_ucm_exec_dial_cb_by_result(SRV_UCM_RESULT_SOS_CALL_EXISTS);
        return GRP_ID_INVALID; /*should return ucm app's group id */
    }

    /* 4. unhide menu based on input dialtype*/
    /* Not necessary in FTO */
	
    /* 5. use global para to keep some info */
    /* for mmi_ucm_outgoing_call_sendkey, mmi_ucm_dial_option_make_call, mmi_ucm_is_sos_wait_dial. because this api can not give input parameter */

    /* 5-1. translate input URI to ascii and copy to g_ucm_p->mo_info.dial_num.num_uri */        
    unicodeLen = (SRV_UCM_MAX_NUM_URI_LEN > mmi_ucs2strlen((CHAR*)make_call_para->ucs2_num_uri)) ? (mmi_ucs2strlen((CHAR*)make_call_para->ucs2_num_uri)) : (SRV_UCM_MAX_NUM_URI_LEN);
    memset(g_ucm_p->mo_info.dial_num.num_uri, 0, SRV_UCM_MAX_NUM_URI_LEN + 1);
    
    mmi_ucs2_n_to_asc((CHAR*)g_ucm_p->mo_info.dial_num.num_uri, (CHAR*)make_call_para->ucs2_num_uri, unicodeLen * ENCODING_LENGTH);
    /* Special handle for single vidoe call type + ECC number case */
    if (SRV_UCM_VIDEO_CALL_TYPE == make_call_para->dial_type)
    {
        if (MMI_TRUE == srv_ucm_is_emergency_number(SRV_UCM_VOICE_CALL_TYPE , (U8 *)g_ucm_p->mo_info.dial_num.num_uri))
        {
            /* if user dial ECC number with VT type, (and it a SIM1 ECC number) the type will change to sim1|sim2 automatically */
            make_call_para->dial_type = SRV_UCM_VOICE_CALL_TYPE;
        }
    }

    /* 5-2. keep rest info */
    
    g_ucm_p->mo_info.dial_type = make_call_para->dial_type;
    g_ucm_p->mo_info.module_id = make_call_para->adv_para.module_id;
    g_ucm_p->mo_info.is_ip_dial = make_call_para->adv_para.is_ip_dial;
    g_ucm_p->mo_info.phb_data = make_call_para->adv_para.phb_data;


    //MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_CALL_LAUNCH_P4, g_ucm_p->mo_info.dial_type, g_ucm_p->mo_info.module_id, g_ucm_p->mo_info.is_ip_dial, make_call_para->ucs2_num_uri);
        
    /* 6. ECC related handler */
    /* 6-1. Fill check_act_req */
    memset(&check_act_req, 0, sizeof(srv_ucm_dial_act_req_struct));
    unicodeLen = (SRV_UCM_MAX_NUM_URI_LEN > mmi_ucs2strlen((CHAR*)make_call_para->ucs2_num_uri)) ? (mmi_ucs2strlen((CHAR*)make_call_para->ucs2_num_uri)) : (SRV_UCM_MAX_NUM_URI_LEN);    
    if (unicodeLen > 0)
    {
        mmi_ucs2ncpy((CHAR*)check_act_req.num_uri, (CHAR*) make_call_para->ucs2_num_uri, unicodeLen);
    }
    check_act_req.is_ip_dial = make_call_para->adv_para.is_ip_dial;
    check_act_req.module_id = make_call_para->adv_para.module_id;

    check_act_req.phb_data = make_call_para->adv_para.phb_data;

    /* 6-2. Handle ECC with given input call type */
    
    ECC_result = mmi_ucm_ecc_check_handler(make_call_para->dial_type, &check_act_req, MMI_TRUE);
    
    if(MMI_UCM_ECC_HDLR_PASS_AND_DIALED == ECC_result)
    {  
        return 0;//return GRP_ID_UCM_MO; /* GRP_ID_UCM_MO group will be created in dial start notify */ 
    }

    if (MMI_UCM_ECC_HDLR_ALL_PASS == ECC_result)
    {
        ECC_result = mmi_ucm_ecc_check_handler(make_call_para->dial_type, &check_act_req, MMI_FALSE);
        if (MMI_UCM_ECC_HDLR_PASS_AND_DIALED == ECC_result)
        {
            return 0; /* GRP_ID_UCM_MO group will be created in dial start notify */ 
        }
    }

    /* Best effort for ECC */   
    /* 6-3. Handle ECC in best-effort way if the number is ECC for all given types but can not permit to dial in previous step */

    if (MMI_UCM_ECC_HDLR_ALL_PASS == ECC_result)
    {
        ECC_result = mmi_ucm_ecc_check_handler(SRV_UCM_CALL_TYPE_ALL, &check_act_req, MMI_TRUE);
        if (MMI_UCM_ECC_HDLR_PASS_AND_DIALED == ECC_result)
        {
            return 0;//return GRP_ID_UCM_MO; /* GRP_ID_UCM_MO group will be created in dial start notify */ 
        }
    }

    if (MMI_UCM_ECC_HDLR_ALL_PASS == ECC_result)
    {
        if (MMI_UCM_ECC_HDLR_PASS_AND_DIALED == mmi_ucm_ecc_check_handler(SRV_UCM_CALL_TYPE_ALL, &check_act_req, MMI_FALSE))
        {
            return 0;//return GRP_ID_UCM_MO; /* GRP_ID_UCM_MO group will be created in dial start notify */
        }
    }

    /* 7. decide the available call type based on permit with input dial type */
    /* 7-1. check each type's dial related permit. the priority will be dial, hold&dial, endall&dial */    
    if (available_call_type == 0 && (make_call_para->dial_type & SRV_UCM_VOICE_CALL_TYPE))
    {
        check_act_req.call_type = SRV_UCM_VOICE_CALL_TYPE;
        /* invalid number check will be in srv permit (only for dial related actions) */
        if (MMI_TRUE == mmi_ucm_pass_dial_permit(&check_act_req, &first_permit_act_op, &tmp_permit_result))
        {
             available_call_type = (srv_ucm_call_type_enum)(available_call_type | SRV_UCM_VOICE_CALL_TYPE);
        }
        if (tmp_permit_result > first_permit_result)
        {
            first_permit_result = tmp_permit_result;
        }
    }

#if (MMI_MAX_SIM_NUM >= 2)
    if (available_call_type == 0 && (make_call_para->dial_type & SRV_UCM_VOICE_CALL_TYPE_SIM2))
    {
        check_act_req.call_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
        if (MMI_TRUE == mmi_ucm_pass_dial_permit(&check_act_req, &first_permit_act_op, &tmp_permit_result))
        {
            available_call_type = (srv_ucm_call_type_enum)(available_call_type | SRV_UCM_VOICE_CALL_TYPE_SIM2);
        }
        if (tmp_permit_result > first_permit_result)
        {
            first_permit_result = tmp_permit_result;
        }
    }

#if (MMI_MAX_SIM_NUM >= 3)
    if (available_call_type == 0 && (make_call_para->dial_type & SRV_UCM_VOICE_CALL_TYPE_SIM3))
    {
        check_act_req.call_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
        if (MMI_TRUE == mmi_ucm_pass_dial_permit(&check_act_req, &first_permit_act_op, &tmp_permit_result))
        {
            available_call_type = (srv_ucm_call_type_enum)(available_call_type | SRV_UCM_VOICE_CALL_TYPE_SIM3);
        }
        if (tmp_permit_result > first_permit_result)
        {
            first_permit_result = tmp_permit_result;
        }
    }
#if (MMI_MAX_SIM_NUM >= 4)
        if (available_call_type == 0 && (make_call_para->dial_type & SRV_UCM_VOICE_CALL_TYPE_SIM4))
        {
            check_act_req.call_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;
            if (MMI_TRUE == mmi_ucm_pass_dial_permit(&check_act_req, &first_permit_act_op, &tmp_permit_result))
            {
                available_call_type = (srv_ucm_call_type_enum)(available_call_type | SRV_UCM_VOICE_CALL_TYPE_SIM4);
            }
            if (tmp_permit_result > first_permit_result)
            {
                first_permit_result = tmp_permit_result;
            }
        }
#endif /* (MMI_MAX_SIM_NUM >= 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */

#ifdef __MMI_VOIP__
    if (available_call_type == 0 && (make_call_para->dial_type & SRV_UCM_VOIP_CALL_TYPE))
    {
        check_act_req.call_type = SRV_UCM_VOIP_CALL_TYPE;
        if (MMI_TRUE == mmi_ucm_pass_dial_permit(&check_act_req, &first_permit_act_op, &tmp_permit_result))
        {
             available_call_type = (srv_ucm_call_type_enum)(available_call_type | SRV_UCM_VOIP_CALL_TYPE);
        }

        if (tmp_permit_result > first_permit_result)
        {
            first_permit_result = tmp_permit_result;
        }
    }
#endif /* __MMI_VOIP__ */  

#ifdef __MMI_VIDEO_TELEPHONY__
    if (available_call_type == 0 && (make_call_para->dial_type & SRV_UCM_VIDEO_CALL_TYPE))
    {
        check_act_req.call_type = SRV_UCM_VIDEO_CALL_TYPE;
        if (MMI_TRUE == mmi_ucm_pass_dial_permit(&check_act_req, &first_permit_act_op, &tmp_permit_result))
        {
             available_call_type = (srv_ucm_call_type_enum)(available_call_type | SRV_UCM_VIDEO_CALL_TYPE);
        }
        if (tmp_permit_result > first_permit_result)
        {
            first_permit_result = tmp_permit_result;
        }        
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

    /* 8. decide the available dial types, if ==0, pop err msg */
    if (available_call_type == 0)
    {
        if (SRV_UCM_RESULT_UNSPECIFIED_ERROR == first_permit_result)
        {
            first_permit_result = SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL;
        }
        vapp_ucm_display_popup(first_permit_result);
        mmi_ucm_exec_dial_cb_by_result(first_permit_result);
        //mmi_frm_group_close(GRP_ID_UCM_PRE_MO);
        return GRP_ID_INVALID; /*should return ucm app's group id */
    }    
    /* 9. Dial call directly if only one call type */

    /* Not dial VT call if out of 3G coverage */
    if (SRV_UCM_VIDEO_CALL_TYPE == make_call_para->dial_type &&  
        (srv_nw_info_get_protocol(MMI_SIM1) != MMI_WCDMA))
    {
        vapp_ucm_display_popup(SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL);
        mmi_ucm_exec_dial_cb_by_result(SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL);
        return GRP_ID_INVALID; /*should return ucm app's group id */          
    }

    /* 9.2 background sound */

    /* 9.3 dial out */
    /* if SRV_UCM_HOLD_AND_DIAL_ACT, need more information */
    if (SRV_UCM_HOLD_AND_DIAL_ACT == first_permit_act_op)
    {
        if (srv_ucm_query_group_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, group_index_array) != 1) 
        {
            MMI_ASSERT(0);
        }

        if( srv_ucm_query_group_data(group_index_array[0], &group_info) <= 0)
        {
            MMI_ASSERT(0);
        }
        
        memset(&hold_and_dial_req, 0, sizeof(srv_ucm_hold_and_dial_act_req_struct));
        hold_and_dial_req.active_call_type = group_info.call_type;
        hold_and_dial_req.active_group = group_info.group_id;
        hold_and_dial_req.dial_call_type = check_act_req.call_type;
        hold_and_dial_req.is_ip_dial = check_act_req.is_ip_dial;
        hold_and_dial_req.module_id = check_act_req.module_id;
        hold_and_dial_req.phb_data = check_act_req.phb_data;
        mmi_ucs2cpy((CHAR*)hold_and_dial_req.num_uri, (CHAR*)check_act_req.num_uri);
        
        srv_ucm_act_request(first_permit_act_op, &hold_and_dial_req, g_ucm_p->mo_info.callback_para, mmi_ucm_act_callback);
    }
    else
    {
        check_act_req.call_type = available_call_type;
        srv_ucm_act_request(first_permit_act_op, &check_act_req, g_ucm_p->mo_info.callback_para, mmi_ucm_act_callback);
    }
    
    return 0; /* GRP_ID_UCM_MO group will be created in dial start notify */ 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_showAOC
 * DESCRIPTION
 *  Get AOC display status
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: should display AOC info
 *****************************************************************************/
extern MMI_BOOL mmi_ucm_get_show_aoc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->call_cost.uid_info.call_id != SRV_UCM_INVALID_INDEX) 
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_error_message
 * DESCRIPTION
 *  Error message API for applications which operations are not allowed during in-call.
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
void mmi_ucm_entry_error_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_ext(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL, MMI_EVENT_FAILURE, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_app_entry_error_message
 * DESCRIPTION
 *  a wrapper API for displaying error message API for applications which operations are not 
 *  allowed during in-call (mmi_ucm_entry_error_message)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_app_entry_error_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_entry_error_message();
}

#endif /* __MMI_UCM__ */

