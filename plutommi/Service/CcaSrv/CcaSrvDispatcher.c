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
 *  CentralConfigAgentDispatcher.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  CCA Dispatcher Code
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
 * removed!
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

/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
//#ifdef __CCA_SUPPORT__

#include "MMI_features.h"
#include "MMI_include.h"

#include "kal_general_types.h"
#include "kal_trace.h"
#include "kal_public_api.h"

#include "MMIDataType.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"

#ifdef __SPA_SUPPORT__
#include "SIMProvAgentGProt.h"
#endif 

#include "CcaSrvGProt.h"
#include "CcaSrvConfig.h"
#include "CcaSrvProt.h"

#ifdef __MMI_CCA_SUPPORT__


/*----------------------------------------------------------------------------*/
/* Macro define                                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* DECLARATIONS                                                   */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static API declaration                                                     */
/*----------------------------------------------------------------------------*/

/*----------Data Account------------------------------------------*/

extern void srv_dtcnt_prov_proc_cca_doc(srv_cca_app_configure_ind_struct *newConfigDoc);
extern void srv_dtcnt_prov_dm_retrieve_ind(U16 appid, S32 profid);
extern void srv_dtcnt_prov_dm_update_ind(U16 appid, S32 profid, S32 hconfig);


/*----------WAP/MMS-----------------------------------------------*/

#ifdef WAP_SUPPORT     /* Q05A Browser/MMS */
extern void srv_wap_prof_prov_app_configure_ind_hdlr(srv_cca_app_configure_ind_struct *newConfigDoc);
extern void srv_wap_prof_prov_cca_app_sim_status_ind_hdlr(
                srv_cca_app_sim_profile_status_ind_struct *sim_profile_status);

#ifdef SYNCML_DM_SUPPORT
extern void srv_wap_prov_dm_app_recv_prof_ind_hdlr(void *msg);
extern void srv_wap_prov_dm_app_update_prof_ind_hdlr(void *msg);
#endif /* SYNCML_DM_SUPPORT */ 

#else /* WAP_SUPPORT */ 

#ifdef __MMI_BROWSER_2__    /* Q05A Browser/MMS */
extern void srv_prov_browser_cca_new_doc(srv_cca_app_configure_ind_struct *newConfigDoc);
extern void srv_prov_mms_cca_new_doc(srv_cca_app_configure_ind_struct *newConfigDoc);

#ifdef SYNCML_DM_SUPPORT
extern void srv_prov_dm_app_recv_prof_ind(void *msg);
extern void srv_prov_dm_app_update_prof_ind(void *msg);
#endif /* SYNCML_DM_SUPPORT */ 
#endif /* __MMI_BROWSER_2__ */ 
#endif /* WAP_SUPPORT */ 


/*----------WLAN--------------------------------------------------*/

#if defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__)  /* WLAN - DMP */
extern void srv_dtcnt_prov_wlan_proc_cca_doc(U16 conf_id, S32 doc_hdl);
#endif /* defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__) */ 


/*----------VoIP--------------------------------------------------*/

#ifdef __MMI_VOIP_OTAP_DMP__    /* SIP - DMP */
/* under construction !*/
#endif /* __MMI_VOIP_OTAP_DMP__ */ 


/*----------SyncML-DS---------------------------------------------*/

#ifdef __MMI_SYNCML_CCA_SUPPORT__
extern void mmi_syncml_proc_cca_doc(void *param);
extern void mmi_syncml_construct_cca_document_for_dm(void *param);
extern void mmi_syncml_install_cca_document_from_dm(void *param);
#endif /* __MMI_SYNCML_CCA_SUPPORT__ */ 


/*----------Email-------------------------------------------------*/

#ifdef __MMI_EMAIL_OTAP__
extern void srv_email_otap_proc_cca_doc(srv_cca_app_configure_ind_struct *newConfigDoc);
#endif /* __MMI_EMAIL_OTAP__ */ 


/*----------IMPS--------------------------------------------------*/

#ifdef __MMI_IMPS_OTA__
extern void mmi_imps_proc_cca_doc(srv_cca_app_configure_ind_struct *msg);
#endif /* __MMI_IMPS_OTA__ */ 


/*----------SYNCML-DM---------------------------------------------*/

#ifdef SYNCML_DM_SUPPORT
extern void srv_dm_otap_cca_app_configure_hdlr(srv_cca_app_configure_ind_struct *newConfigDoc);
extern void srv_dm_otap_cca_app_get_prof_hdlr(srv_cca_app_get_prof_ind_struct *newConfigDoc);
extern void srv_dm_otap_cca_app_update_prof_hdlr(srv_cca_app_update_prof_ind_struct *newConfigDoc);
#endif /* SYNCML_DM_SUPPORT */ 


/*----------PRS---------------------------------------------------*/

#ifdef __MMI_PROVISIONING_SERVICE_SUPPORT__
#ifndef __MMI_PROV_MESSAGE_SUPPORT__
extern void srv_prov_cca_new_setting_rsp_hdlr(srv_cca_src_new_setting_rsp_struct *data);
#endif 
#ifdef __SRV_CCA_SUPPORT_AUTH__
extern void srv_prov_cca_ui_auth_rsp_hdlr(srv_cca_src_auth_rsp_struct *l_data);
#endif
extern void srv_prov_cca_new_doc_rsp_hdlr(srv_cca_src_new_doc_rsp_struct *data);
#endif /* __MMI_PROVISIONING_SERVICE_SUPPORT__ */ 


/*----------PUSH--------------------------------------------------*/

#ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__
extern void srv_brw_push_ota_app_configure(srv_cca_app_configure_ind_struct *newconfigdoc);
#endif 


/*----------RTSP--------------------------------------------------*/

#ifdef __MMI_STREAMING_OTAP__
extern void mmi_streaming_proc_cca_doc(srv_cca_app_configure_ind_struct *newconfigdoc);
extern void mmi_streaming_dm_get_profile(srv_cca_app_get_prof_ind_struct * msg);
extern void mmi_streaming_dm_update_profile(srv_cca_app_update_prof_ind_struct * msg);
#endif


/*----------SUPL--------------------------------------------------*/

#ifdef __MMI_AGPS_OTAP__
extern void mmi_supl_handle_app_configure(srv_cca_app_configure_ind_struct *newconfigdoc);
#endif

/*----------------------------------------------------------------*/
/* DECLARATIONS END                                               */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static global variable                                                     */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Extern API declaration                                                     */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* End                                                                        */
/*----------------------------------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  srv_cca_dispatch_src_new_setting_rsp
 * DESCRIPTION
 *  Dispatch MSG_ID_SRV_CCA_SRC_NEW_SETTING_RSP data to Configuration Sources in MMI task
 * PARAMETERS
 *  new_setting_rsp     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_dispatch_src_new_setting_rsp(srv_cca_src_new_setting_rsp_struct *new_setting_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (new_setting_rsp->source_id)
    {
        case SRV_CCA_SOURCE_WAP:
    #ifdef __MMI_PROVISIONING_SERVICE_SUPPORT__
            /* MTK Provisioning Service API for OTA. */
    #ifndef __MMI_PROV_MESSAGE_SUPPORT__
            srv_prov_cca_new_setting_rsp_hdlr(new_setting_rsp);
    #endif 
    #endif /* __MMI_PROVISIONING_SERVICE_SUPPORT__ */ 
            break;

#ifndef __SRV_CCA_SLIM__

        case SRV_CCA_SOURCE_DM:
            SRV_CCA_ASSERT(0);
            break;

#endif /* __SRV_CCA_SLIM__ */

    #ifdef __SPA_SUPPORT__
        case SRV_CCA_SOURCE_SPA:
            mmi_spa_cca_new_setting_rsp_hdlr((void*)new_setting_rsp);
            break;
    #endif /* __SPA_SUPPORT__ */ 

        default:
            SRV_CCA_ASSERT(0);
            break;
    }
}

#ifdef __SRV_CCA_SUPPORT_AUTH__
/*****************************************************************************
 * FUNCTION
 *  srv_cca_dispatch_src_auth_rsp
 * DESCRIPTION
 *  Dispatch MSG_ID_SRV_CCA_SRC_AUTH_RSP data to Configuration Sources in MMI task
 * PARAMETERS
 *  auth_rsp        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_dispatch_src_auth_rsp(srv_cca_src_auth_rsp_struct *auth_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (auth_rsp->source_id)
    {
        case SRV_CCA_SOURCE_WAP :
    #ifdef __MMI_PROVISIONING_SERVICE_SUPPORT__
            srv_prov_cca_ui_auth_rsp_hdlr(auth_rsp);
    #endif 
            break;

#ifndef __SRV_CCA_SLIM__
        case SRV_CCA_SOURCE_DM:
            SRV_CCA_ASSERT(0);
            break;

        case SRV_CCA_SOURCE_SPA:
            /* mmi_sim_handle_cca_source_ui_auth_rsp(auth_rsp); */
            SRV_CCA_ASSERT(0);
            break;
#endif /* __SRV_CCA_SLIM__ */

        default:
            SRV_CCA_ASSERT(0);
            break;
    }

}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_cca_dispatch_src_new_doc_rsp
 * DESCRIPTION
 *  Dispatch MSG_ID_SRV_CCA_SRC_NEW_DOC_RSP data to Configuration Sources in MMI task
 * PARAMETERS
 *  new_doc_rsp     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_dispatch_src_new_doc_rsp(srv_cca_src_new_doc_rsp_struct *new_doc_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (new_doc_rsp->source_id)
    {
        case SRV_CCA_SOURCE_WAP:
    #ifdef __MMI_PROVISIONING_SERVICE_SUPPORT__
            srv_prov_cca_new_doc_rsp_hdlr(new_doc_rsp);
    #endif 
            break;

#ifndef __SRV_CCA_SLIM__
        case SRV_CCA_SOURCE_DM:
            SRV_CCA_ASSERT(0);
            break;
#endif /* __SRV_CCA_SLIM__ */

    #ifdef __SPA_SUPPORT__
        case SRV_CCA_SOURCE_SPA:
            mmi_spa_cca_new_doc_rsp_hdlr((void*)new_doc_rsp);
            break;
    #endif /* __SPA_SUPPORT__ */ 

        default:
            SRV_CCA_ASSERT(0);
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_dispatch_app_configure_ind
 * DESCRIPTION
 *  Dispatch MSG_ID_CCA_APP_CONFIGURE_IND data to target applications in MMI task
 * PARAMETERS
 *  newConfigDoc        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_dispatch_app_configure_ind(srv_cca_app_configure_ind_struct *newConfigDoc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        SRV_CCA_TRC_INFO, TRC_SRV_CCA_DISPATCH_APP_CONFIGURE_IND,
        newConfigDoc->prov_type,
        newConfigDoc->prov_flag,
        newConfigDoc->sim_id,
        newConfigDoc->config_id,
        newConfigDoc->hConfig);

    SRV_CCA_LOG_DOC(newConfigDoc->hConfig);

    switch (newConfigDoc->config_id)
    {
            /*----------------------------------------------------------------*/
            /* DISPATCH: DATA ACCOUNT                                         */
            /*----------------------------------------------------------------*/
        case SRV_CCA_CONFIG_DTACCT:
            srv_dtcnt_prov_proc_cca_doc(newConfigDoc);
            break;

            /*----------------------------------------------------------------*/
            /* DISPATCH: WLAN                                                 */
            /*----------------------------------------------------------------*/
    #if defined(__MMI_WLAN_OTAP_OMAEXT__)
        case SRV_CCA_CONFIG_WLAN:
            srv_dtcnt_prov_wlan_proc_cca_doc(newConfigDoc->config_id, newConfigDoc->hConfig);
            break;
    #elif defined(__MMI_WLAN_OTAP_DMP__)
        case SRV_CCA_CONFIG_WLAN_DMP:
            srv_dtcnt_prov_wlan_proc_cca_doc(newConfigDoc->config_id, newConfigDoc->hConfig);
            break;
    #endif 

            /*----------------------------------------------------------------*/
            /* DISPATCH: BROWSER                                              */
            /*----------------------------------------------------------------*/

#ifdef __SRV_CCA_SLIM__

    #ifdef WAP_SUPPORT
        case SRV_CCA_CONFIG_BROWSER:
            srv_wap_prof_prov_app_configure_ind_hdlr(newConfigDoc);
            break;
    #endif /* WAP_SUPPORT */ 
    
#else /* __SRV_CCA_SLIM__ */
    
        case SRV_CCA_CONFIG_BROWSER:
    #ifdef WAP_SUPPORT
            srv_wap_prof_prov_app_configure_ind_hdlr(newConfigDoc);
    #else /* WAP_SUPPORT */ 


            MMI_TRACE(SRV_CCA_TRC_ERROR, SRV_CCA_TRC_DISPATCHER_PROV_APP_NOT_SUPPORT);

            srv_cca_send_cca_app_configure_rsp(
                newConfigDoc->sim_id,
                newConfigDoc->config_id,
                newConfigDoc->hConfig,
                SRV_CCA_STATUS_SETTING_SKIPPED);

    #endif /* WAP_SUPPORT */ 
            break;

#endif /* __SRV_CCA_SLIM__ */

            /*----------------------------------------------------------------*/
            /* DISPATCH: MMS                                                  */
            /*----------------------------------------------------------------*/
#ifdef __SRV_CCA_SLIM__
    
    #ifdef WAP_SUPPORT
        case SRV_CCA_CONFIG_MMS:
            srv_wap_prof_prov_app_configure_ind_hdlr(newConfigDoc);
            break;
    #endif /* __SRV_CCA_SLIM__ */
        
#else /* __SRV_CCA_SLIM__ */
        
        
        case SRV_CCA_CONFIG_MMS:
    #ifdef WAP_SUPPORT
            srv_wap_prof_prov_app_configure_ind_hdlr(newConfigDoc);
    #else 
            MMI_TRACE(SRV_CCA_TRC_ERROR, SRV_CCA_TRC_DISPATCHER_PROV_APP_NOT_SUPPORT);

            srv_cca_send_cca_app_configure_rsp(
                newConfigDoc->sim_id,
                newConfigDoc->config_id,
                newConfigDoc->hConfig,
                SRV_CCA_STATUS_SETTING_SKIPPED);
 
    #endif /* WAP_SUPPORT */ 
            break;

#endif /* __SRV_CCA_SLIM__ */

            /*----------------------------------------------------------------*/
            /* DISPATCH: SIP                                                  */
            /*----------------------------------------------------------------*/
            /* case SRV_CCA_CONFIG_SIP:
               //trigger callback or send ILM
               srv_cca_send_cca_app_configure_rsp(newConfigDoc->sim_id, newConfigDoc->config_id, newConfigDoc->hConfig, CCA_STATUS_SETTING_SKIPPED);
               break; */

    #ifdef __MMI_VOIP_OTAP_DMP__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_VOIP_OTAP_DMP__ */ 

            /*----------------------------------------------------------------*/
            /* DISPATCH: EMAIL                                                */
            /*----------------------------------------------------------------*/
    #ifdef __MMI_EMAIL_OTAP__
        case SRV_CCA_CONFIG_EMAIL:
            srv_email_otap_proc_cca_doc(newConfigDoc);
            break;
    #endif /* __MMI_EMAIL_OTAP__ */ 

            /*----------------------------------------------------------------*/
            /* DISPATCH: SyncML-DS                                            */
            /*----------------------------------------------------------------*/
        #ifdef __MMI_SYNCML_CCA_SUPPORT__
        case SRV_CCA_CONFIG_SYNCMLDS:
            mmi_syncml_proc_cca_doc((void*)newConfigDoc);
            break;
        #endif /* __MMI_SYNCML_CCA_SUPPORT__ */ 

            /*----------------------------------------------------------------*/
            /* DISPATCH: SyncML-DM                                            */
            /*----------------------------------------------------------------*/
        #ifdef SYNCML_DM_SUPPORT
        case SRV_CCA_CONFIG_SYNCMLDM:
            srv_dm_otap_cca_app_configure_hdlr(newConfigDoc);
            break;
        #endif /* SYNCML_DM_SUPPORT */ 

            /*----------------------------------------------------------------*/
            /* DISPATCH: IMPS                                                 */
            /*----------------------------------------------------------------*/
        #ifdef __MMI_IMPS_OTA__
        case SRV_CCA_CONFIG_IMPS:
            mmi_imps_proc_cca_doc(newConfigDoc);
            break;
        #endif /* __MMI_IMPS_OTA__ */ 

            /*----------------------------------------------------------------*/
            /* DISPATCH: Push                                                 */
            /*----------------------------------------------------------------*/
        #ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__
        case SRV_CCA_CONFIG_PUSH:
            srv_brw_push_ota_app_configure(newConfigDoc);
            break;
        #endif /* __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__ */ 


            /*----------------------------------------------------------------*/
            /* DISPATCH: RTSP                                                 */
            /*----------------------------------------------------------------*/
#ifdef __MMI_STREAMING_OTAP__
        case SRV_CCA_CONFIG_RTSP:
            mmi_streaming_proc_cca_doc(newConfigDoc);
            break;
#endif /* __MMI_STREAMING_OTAP__ */ 


            /*----------------------------------------------------------------*/
            /* DISPATCH: SUPL                                                 */
            /*----------------------------------------------------------------*/
#ifdef __MMI_AGPS_OTAP__
        case SRV_CCA_CONFIG_SUPL:
            mmi_supl_handle_app_configure(newConfigDoc);
            break;
#endif /* __MMI_AGPS_OTAP__ */ 


            /*----------------------------------------------------------------*/
            /* Default: Skipped                                            */
            /*----------------------------------------------------------------*/
    
        default:

            MMI_TRACE(SRV_CCA_TRC_ERROR, TRC_SRV_CCA_DISPATCHER_PROV_CONFIG_ID_NOT_FOUND);

            srv_cca_send_cca_app_configure_rsp(
                newConfigDoc->sim_id,
                newConfigDoc->config_id,
                newConfigDoc->hConfig,
                SRV_CCA_STATUS_SETTING_SKIPPED);
            break;
    }
}


#ifdef __SRV_CCA_SPA__
/*****************************************************************************
 * FUNCTION
 *  srv_cca_dispatch_app_sim_profile_status_ind
 * DESCRIPTION
 *  Dispatch MSG_ID_CCA_APP_SIM_PROFIE_STATUS_IND to target application in MMI task
 * PARAMETERS
 *  sim_profile_status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_dispatch_app_sim_profile_status_ind(srv_cca_app_sim_profile_status_ind_struct *sim_profile_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        SRV_CCA_TRC_INFO, TRC_SRV_CCA_DISPATCH_APP_SIM_PROFILE_STATUS_IND,
        sim_profile_status->prov_type,
        sim_profile_status->sim_id,
        sim_profile_status->config_id,
        sim_profile_status->spec_id,
        sim_profile_status->prov_flag);

    switch (sim_profile_status->config_id)
    {

#ifdef __SRV_CCA_SLIM__

    #if defined(WAP_SUPPORT) && defined(__SPA_SUPPORT__)
        case SRV_CCA_CONFIG_MMS:
            srv_wap_prof_prov_cca_app_sim_status_ind_hdlr(sim_profile_status);  /* USIM */
            break;
    #endif /* WAP_SUPPORT && __SPA_SUPPORT__ */ 

        
#else /* __SRV_CCA_SLIM__ */
        
        case SRV_CCA_CONFIG_MMS:
    #ifdef WAP_SUPPORT
    #ifdef __SPA_SUPPORT__
            srv_wap_prof_prov_cca_app_sim_status_ind_hdlr(sim_profile_status);  /* USIM */
    #endif 
    #endif /* WAP_SUPPORT */ 
            break;

#endif /* __SRV_CCA_SLIM__ */

        default:
            SRV_CCA_ASSERT(0);
            break;
    }
}
#endif /* __SRV_CCA_SPA__ */


/*****************************************************************************
 * FUNCTION
 *  srv_cca_dispatch_ready_ind
 * DESCRIPTION
 *  Dispatch MSG_ID_CCA_SOURCE_CCA_READY_IND to Configuration Source in MMI task
 * PARAMETERS
 *  cca_ready_ind       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_dispatch_ready_ind(srv_cca_ready_ind_struct *cca_ready_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cca_ready_ind->source_id)
    {
        case SRV_CCA_SOURCE_SPA:
    #ifdef __SPA_SUPPORT__
            mmi_spa_cca_ready_ind_hdlr((void*)cca_ready_ind);
    #endif 
            break;

        default:
            SRV_CCA_ASSERT(0);
            break;
    }
}



#ifdef __SRV_CCA_PROF_OPER__

/*****************************************************************************
 * FUNCTION
 *  srv_cca_dispatch_profile_operations
 * DESCRIPTION
 *  Dispatch MSG_ID_CCA_APP_GET_PROF_IND and MSG_ID_CCA_APP_UPDATE_PROF_IND
 *  to target applications in MMI task
 * PARAMETERS
 *  oper            [IN]        {SRV_CCA_OPER_GET, SRV_CCA_OPER_UPDATE}
 *  app_id          [IN]        
 *  local_parm      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_dispatch_profile_operations(srv_cca_oper_enum oper, U16 app_id, void *local_parm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_app_get_prof_ind_struct *get_prof_ind = 0;
    srv_cca_app_update_prof_ind_struct *update_prof_ind = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_DISPATCHER_ASYNC, oper, app_id);

    if (oper == SRV_CCA_OPER_GET)
    {
        get_prof_ind = (srv_cca_app_get_prof_ind_struct*) local_parm;
        MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_DISPATCHER_ASYNC_GET, get_prof_ind->app_id, get_prof_ind->prof_id);
    }
    else if (oper == SRV_CCA_OPER_UPDATE)
    {
        update_prof_ind = (srv_cca_app_update_prof_ind_struct*) local_parm;

        MMI_TRACE(
            SRV_CCA_TRC_INFO,
            TRC_SRV_CCA_DISPATCHER_ASYNC_UPDATE,
            update_prof_ind->app_id,
            update_prof_ind->prof_id,
            update_prof_ind->hConfig);

    }
    else
    {
        SRV_CCA_ASSERT(0);
    }

    switch (app_id)
    {
            /*----------------------------------------------------------------*/
            /* DISPATCH: DATA ACCOUNT                                         */
            /*----------------------------------------------------------------*/
        case SRV_CCA_APP_DTACCT:
            if (oper == SRV_CCA_OPER_GET)
                srv_dtcnt_prov_dm_retrieve_ind(app_id, get_prof_ind->prof_id);
            else if (oper == SRV_CCA_OPER_UPDATE)
                srv_dtcnt_prov_dm_update_ind(app_id, update_prof_ind->prof_id, update_prof_ind->hConfig);
            break;

            /*----------------------------------------------------------------*/
            /* DISPATCH: BROWSER                                              */
            /*----------------------------------------------------------------*/
#ifdef WAP_SUPPORT
#ifdef SYNCML_DM_SUPPORT
        case SRV_CCA_APP_BROWSER:
            if (oper == SRV_CCA_OPER_GET)
                srv_wap_prov_dm_app_recv_prof_ind_hdlr(local_parm);
            else if (oper == SRV_CCA_OPER_UPDATE)
                srv_wap_prov_dm_app_update_prof_ind_hdlr(local_parm);
            break;
#endif /* SYNCML_DM_SUPPORT */ 
#endif /* WAP_SUPPORT */ 

            /*----------------------------------------------------------------*/
            /* DISPATCH: MMS                                                  */
            /*----------------------------------------------------------------*/
#ifdef WAP_SUPPORT
#ifdef SYNCML_DM_SUPPORT
        case SRV_CCA_APP_MMS:
            if (oper == SRV_CCA_OPER_GET)
                srv_wap_prov_dm_app_recv_prof_ind_hdlr(local_parm);
            else if (oper == SRV_CCA_OPER_UPDATE)
                srv_wap_prov_dm_app_update_prof_ind_hdlr(local_parm);
            break;
#endif /* SYNCML_DM_SUPPORT */ 
#endif /* WAP_SUPPORT */ 

            /*----------------------------------------------------------------*/
            /* DISPATCH: SyncML-DS                                            */
            /*----------------------------------------------------------------*/
    #ifdef __MMI_SYNCML_CCA_SUPPORT__
        case SRV_CCA_APP_SYNCMLDS:
            if (oper == SRV_CCA_OPER_GET)
                mmi_syncml_construct_cca_document_for_dm(local_parm);
            else if (oper == SRV_CCA_OPER_UPDATE)
                mmi_syncml_install_cca_document_from_dm(local_parm);
            break;
    #endif /* __MMI_SYNCML_CCA_SUPPORT__ */ 

	    /******************************************************************/
            /*DISPATCH: Streaming-DM                                                                                              */
	    /******************************************************************/
	#ifdef __MMI_STREAMING_OTAP__
	#ifdef SYNCML_DM_SUPPORT
	    case SRV_CCA_APP_RTSP:
			if(oper == SRV_CCA_OPER_GET)
			{
			    mmi_streaming_dm_get_profile(local_parm);
			}
			else if(oper == SRV_CCA_OPER_UPDATE)
			{
			    mmi_streaming_dm_update_profile(local_parm);
			}
			break;
	#endif
	#endif
	
            /*----------------------------------------------------------------*/
            /* DISPATCH: SyncML-DM                                            */
            /*----------------------------------------------------------------*/
    #ifdef SYNCML_DM_SUPPORT
        case SRV_CCA_APP_SYNCMLDM:
            if (oper == SRV_CCA_OPER_GET)
                srv_dm_otap_cca_app_get_prof_hdlr(local_parm);
            else if (oper == SRV_CCA_OPER_UPDATE)
                srv_dm_otap_cca_app_update_prof_hdlr(local_parm);
            break;
    #endif /* SYNCML_DM_SUPPORT */ 


            /*----------------------------------------------------------------*/
            /* Default                                                        */
            /*----------------------------------------------------------------*/
        default:
            MMI_TRACE(SRV_CCA_TRC_WARNING, TRC_SRV_CCA_DISPATCHER_ASYNC_APP_NOT_FOUND);

            if (oper == SRV_CCA_OPER_GET)
                srv_cca_send_cca_app_get_prof_rsp(
                    get_prof_ind->sim_id,
                    app_id,
                    get_prof_ind->prof_id,
                    0,
                    SRV_CCA_STATUS_FAIL);
            else if (oper == SRV_CCA_OPER_UPDATE)
                srv_cca_send_cca_app_update_prof_rsp(
                    update_prof_ind->sim_id,
                    app_id,
                    update_prof_ind->prof_id,
                    update_prof_ind->hConfig,
                    SRV_CCA_STATUS_FAIL);
            break;
    }
}


#endif /* __SRV_CCA_PROF_OPER__ */


#endif /* __CCA_SUPPORT__ */ 

