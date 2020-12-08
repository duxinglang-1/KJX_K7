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
 *  SsSrvStructMgmt.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SS service structure management
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
 
/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "SsSrvGprot.h"
#include "SsSrvProt.h"

#include "MMI_features.h"
#include "MMIDataType.h"
#include "string.h"
#include "stack_msgs.h"
#include "kal_non_specific_general_types.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "kal_release.h"
#include "wgui_categories_list.h"



/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable 
 *****************************************************************************/
static srv_ss_cntx_struct g_srv_ss_cntx[MMI_SIM_TOTAL];

srv_ss_cntx_struct *srv_ss_p;

/***************************************************************************** 
 * Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_ss_init
 * DESCRIPTION
 *  ss initialization
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if it is busy
 *****************************************************************************/
void srv_ss_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {
        srv_ss_cntx_set_ptr(sim_id);
        memset(srv_ss_p, 0, sizeof(srv_ss_cntx_struct));
        srv_ss_p->sim = sim_id;
        srv_ss_cntx_reset_ptr();
    }
	srv_ss_init_phdlr();
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_init_phdlr
 * DESCRIPTION
 *  ss protocol event handler initialization
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if it is busy
 *****************************************************************************/
void srv_ss_init_phdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ss_set_ps_event_handler(srv_ss_phdlr_call_forward_rsp, MSG_ID_MMI_SS_CALL_FORWARD_RSP);
    srv_ss_set_ps_event_handler(srv_ss_phdlr_call_bar_rsp, MSG_ID_MMI_SS_CALL_BARRING_RSP);
    srv_ss_set_ps_event_handler(srv_ss_phdlr_change_password_rsp, MSG_ID_MMI_SS_CHANGE_PASSWORD_RSP);
    srv_ss_set_ps_event_handler(srv_ss_phdlr_call_wait_rsp, MSG_ID_MMI_SS_CALL_WAIT_RSP);
    srv_ss_set_ps_event_handler(srv_ss_phdlr_ussd_rsp, MSG_ID_MMI_SS_USSD_RSP);
    srv_ss_set_ps_event_handler(srv_ss_phdlr_clip_interrogate_ind, MSG_ID_MMI_SS_CLIP_INTERROGATE_IND);
    srv_ss_set_ps_event_handler(srv_ss_phdlr_clir_interrogate_ind, MSG_ID_MMI_SS_CLIR_INTERROGATE_IND);
    srv_ss_set_ps_event_handler(srv_ss_phdlr_colp_interrogate_ind, MSG_ID_MMI_SS_COLP_INTERROGATE_IND);
    srv_ss_set_ps_event_handler(srv_ss_phdlr_colr_interrogate_ind, MSG_ID_MMI_SS_COLR_INTERROGATE_IND);

#ifdef __CNAP_SUPPORT__
    srv_ss_set_ps_event_handler(srv_ss_phdlr_cnap_interrogate_ind, MSG_ID_MMI_SS_CNAP_INTERROGATE_IND);
#endif
#ifdef __CCBS_SUPPORT__
    srv_ss_set_ps_event_handler(srv_ss_phdlr_ccbs_rsp, MSG_ID_MMI_SS_CCBS_RSP);
#endif

#ifdef __EMLPP_SUPPORT__
    srv_ss_set_ps_event_handler(srv_ss_phdlr_emlpp_rsp, MSG_ID_MMI_SS_EMLPP_RSP);
#endif

    srv_ss_set_ps_event_handler(srv_ss_phdlr_ussr_ind, MSG_ID_MMI_SS_USSR_IND);
    srv_ss_set_ps_event_handler(srv_ss_phdlr_ussn_ind, MSG_ID_MMI_SS_USSN_IND);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_is_busy
 * DESCRIPTION
 *  check if ss service is busy
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_TRUE if it is busy
 *****************************************************************************/
MMI_BOOL srv_ss_is_busy(srv_ss_act_enum op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_ss_p->act_info.op != SRV_SS_ACT_IDLE)
    {
        /* ss service is waiting for response */
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_SS_IS_BUSY, op, 1);
        return MMI_TRUE;
    }
    else if (srv_ss_p->in_ss_session &&
             (op != SRV_SS_ACT_SS_OPERATION) &&
             (op != SRV_SS_ACT_ABORT))
    {
        /* only allow to reply ussr or abort ss when there is ss session */
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_SS_IS_BUSY, op, 2);
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_cntx_set_ptr
 * DESCRIPTION
 *  set context pointer (lock sim context) 
 * PARAMETERS
 *  sim     [IN]    target sim
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_cntx_set_ptr(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ss_p)
    {
        MMI_ASSERT(0);
    }

    /* lock srv_ss_p */
	srv_ss_p = &g_srv_ss_cntx[mmi_frm_sim_to_index(sim)];  

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_SS_CNTX_SET_PTR, sim);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_cntx_reset_ptr
 * DESCRIPTION
 *  reset context pointer (unlock context)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_cntx_reset_ptr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* unlock */
    /* Shall reset cntxt ptr after all cntxt related operation is done */

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_SS_CNTX_RESET_PTR);

    srv_ss_p = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_cntx_is_locked
 * DESCRIPTION
 *  check if context is locked
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if it is locked
 *****************************************************************************/
MMI_BOOL srv_ss_cntx_is_locked(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return srv_ss_p ? MMI_TRUE : MMI_FALSE;
}

