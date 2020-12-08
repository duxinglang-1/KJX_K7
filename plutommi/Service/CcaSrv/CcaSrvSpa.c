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
*  CentralConfigAgentSpa.c
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
*
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/


//#ifdef __CCA_SUPPORT__
/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_features.h"
#include "MMI_include.h"

#include "kal_general_types.h"
#include "kal_trace.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "kal_public_api.h"

#include "MMIDataType.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"

#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_events_gprot.h"

#include "CcaSrvGprot.h"
#include "CcaSrvConfig.h"
#include "CcaSrvProt.h"


#ifdef __SRV_CCA_SPA__


#ifdef __MMI_CCA_SUPPORT__



/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
#ifdef __SRV_CCA_SLIM__
static void srv_cca_send_sim_status_to_all_apps(srv_cca_src_new_doc_ind_struct* data);
#endif

static U8 srv_cca_source_sim_profile_status_ind_hdlr(void *msg, int mod_id, void *ilm);
static U8 srv_cca_app_sim_profile_status_ind_hdlr(void *msg, int mod_id, void *ilm);
static void srv_cca_send_app_sim_profile_status_ind(
                module_type mod_id,
                srv_cca_prov_type_enum prov_type,
                U16 sim_id,
                U16 config_id,
                U16 spec_id,
                U32 prov_flag);


/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/

/*****************************************************************************
 * FUNCTION
 *  srv_cca_pevt_spa_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_spa_init(void)
{
    mmi_frm_set_protocol_event_handler(
        MSG_ID_SRV_CCA_SRC_SIM_PROFILE_STATUS_IND,
        (PsIntFuncPtr) srv_cca_source_sim_profile_status_ind_hdlr,
        MMI_FALSE);

    mmi_frm_set_protocol_event_handler(
        MSG_ID_SRV_CCA_APP_SIM_PROFILE_STATUS_IND,
        (PsIntFuncPtr) srv_cca_app_sim_profile_status_ind_hdlr,
        MMI_FALSE);
}


#ifdef __SRV_CCA_SLIM__

static void srv_cca_send_sim_status_to_all_apps(srv_cca_src_new_doc_ind_struct* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int index = 0;
    const srv_cca_app_config_struct *crtConfig;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (1)
    {
        crtConfig = srv_cca_get_app_config(index);
        if (crtConfig->config_id == 0xFFFF)
            break;
        if (crtConfig->support_sim_prov == MMI_FALSE)
        {
            index++;
            continue;
        }
        srv_cca_send_app_sim_profile_status_ind(
            srv_cca_get_module_id_by_config(crtConfig->config_id),
            data->prov_type,
            data->sim_id,
            crtConfig->config_id,
            data->spec_id,
            data->prov_flag);
        index++;
    }
}
#endif /* __SRV_CCA_SLIM__ */


/*****************************************************************************
 * FUNCTION
 *  srv_cca_handle_src_sim_profile_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 *  mod_id          [IN]        
 *  ilm             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_cca_status_enum srv_cca_handle_src_sim_profile_status(srv_cca_cntx_struct *cntx, void *msg, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int index = 0;
    const srv_cca_app_config_struct *crtConfig;
    srv_cca_src_new_doc_ind_struct *data;
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (srv_cca_src_new_doc_ind_struct*) msg;
    if (data->prov_type != SRV_CCA_PROV_TYPE_SIM_PROV || data->hConfig != 0)
        return SRV_CCA_STATUS_FAIL;

#ifdef __SRV_CCA_SLIM__

    srv_cca_send_sim_status_to_all_apps(data);

#else /* __SRV_CCA_SLIM__ */


    while (1)
    {
        crtConfig = srv_cca_get_app_config(index);
        if (crtConfig->config_id == 0xFFFF)
            break;
        if (crtConfig->support_sim_prov == MMI_FALSE)
        {
            index++;
            continue;
        }
        srv_cca_send_app_sim_profile_status_ind(
            srv_cca_get_module_id_by_config(crtConfig->config_id),
            data->prov_type,
            data->sim_id,
            crtConfig->config_id,
            data->spec_id,
            data->prov_flag);
        index++;
    }

#endif /* __SRV_CCA_SLIM__ */

    
    srv_cca_send_src_new_doc_rsp(
        (module_type)mod_id,
        data->source_id,
        data->prov_type,
        data->sim_id,
        data->spec_id,
        inst->configResult,
        inst->numApp,
        inst->msg_config_result,
        SRV_CCA_STATUS_OK);

    srv_cca_job_center_scheduler(cntx, SRV_CCA_JOB_SIM_PROFILE_STATUS_FEEDBACK, NULL);
    return SRV_CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_source_sim_profile_status_ind_hdlr
 * DESCRIPTION
 *  MSG_ID_SRV_CCA_APP_UPDATE_PROF_RSP handler
 * PARAMETERS
 *  msg     [IN]        
 *  mod_id          [IN]        
 *  ilm             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_cca_source_sim_profile_status_ind_hdlr(void *msg, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int index = 0;
    const srv_cca_app_config_struct *crtConfig;
    srv_cca_src_sim_profile_status_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (srv_cca_src_sim_profile_status_ind_struct*) msg;

    MMI_TRACE(
        SRV_CCA_TRC_INFO,
        TRC_SRV_CCA_SOURCE_SIM_PROFILE_STATUS_IND_HDLR,
        data->source_id,
        data->prov_type,
        data->prov_flag,
        data->spec_id);

    if (data->prov_type != SRV_CCA_PROV_TYPE_SIM_PROV)
        return MMI_RET_OK;

#ifdef __SRV_CCA_SLIM__
    
        srv_cca_send_sim_status_to_all_apps(data);
    
#else /* __SRV_CCA_SLIM__ */
    

    while (1)
    {
        crtConfig = srv_cca_get_app_config(index);
        if (crtConfig->config_id == 0xFFFF)
            break;
        if (crtConfig->support_sim_prov == MMI_FALSE)
        {
            index++;
            continue;
        }
        srv_cca_send_app_sim_profile_status_ind(
            srv_cca_get_module_id_by_config(crtConfig->config_id),
            data->prov_type,
            data->sim_id,
            crtConfig->config_id,
            data->spec_id,
            data->prov_flag);
        index++;
    }

#endif /* __SRV_CCA_SLIM__ */

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_app_sim_profile_status_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 *  mod_id          [IN]        
 *  ilm             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_cca_app_sim_profile_status_ind_hdlr(void *msg, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cca_dispatch_app_sim_profile_status_ind((srv_cca_app_sim_profile_status_ind_struct*) msg);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_send_app_sim_profile_status_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mod_id          [IN]        
 *  prov_type       [IN]        
 *  sim_id          [IN]        
 *  config_id       [IN]        
 *  spec_id         [IN]        
 *  prov_flag       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_send_app_sim_profile_status_ind(
                module_type mod_id,
                srv_cca_prov_type_enum prov_type,
                U16 sim_id,
                U16 config_id,
                U16 spec_id,
                U32 prov_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_app_sim_profile_status_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = SRV_CCA_NEW_ILM_DATA(srv_cca_app_sim_profile_status_ind_struct);
    
    data->prov_type = prov_type;
    data->sim_id = sim_id;
    data->config_id = config_id;
    data->spec_id = spec_id;
    data->prov_flag = prov_flag;

    mmi_frm_send_ilm(mod_id, MSG_ID_SRV_CCA_APP_SIM_PROFILE_STATUS_IND, (oslParaType*) data, NULL);
}



#endif /* __SRV_CCA_SPA__ */

#endif /* __CCA_SUPPORT__ */




