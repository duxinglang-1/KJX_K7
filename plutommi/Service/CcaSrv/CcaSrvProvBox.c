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
*  CentralConfigAgentProvBox.c
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
*
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#include "MMI_features.h"

//#ifdef __CCA_SUPPORT__

#ifdef __MMI_CCA_SUPPORT__

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_include.h"


#include "string.h"

#include "kal_general_types.h"
#include "kal_trace.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "kal_public_api.h"

#include "MMIDataType.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "GlobalResDef.h"

#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_events_gprot.h"

 
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
#include "ProvBoxSrvGprot.h"
#endif


#include "CcaSrvGprot.h"
#include "CcaSrvIProt.h"
#include "CcaSrvConfig.h"
#include "CcaSrvProt.h"


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
#define SRV_CCA_PROVBOX_API_LIST

static U8 srv_cca_process_prov_msg_req_hdlr(void *msg, int mod_id, void *ilm);

static U8 srv_cca_src_install_prov_msg_cnf_hdlr(void *msg, int mod_id, void *ilm);

static U8 srv_cca_provbox_set_msg_flag_cnf_hdlr(void *msg, int mod_id, void *ilm);

#ifdef __SRV_CCA_SLIM__
static void srv_cca_proxbox_begin_install(srv_provbox_get_msg_info_cnf_struct* info_data);
#endif

static U8 srv_cca_provbox_get_msg_info_cnf_hdlr(void *msg, int mod_id, void *ilm);

static U8 srv_cca_provbox_update_msg_info_cnf_hdlr(void *msg, int mod_id, void *ilm);

static MMI_BOOL srv_cca_job_is_cmn_prov_msg_job(void *src, void *dst);

static srv_cca_cmp_result_enum srv_cca_job_check_cmn_prov_msg_job(void *src, void *dst);

static srv_cca_status_enum srv_cca_accept_process_prov_msg_req(srv_cca_cntx_struct *cntx);

static void srv_cca_send_process_prov_msg_cnf(
                module_type dest_mod_id,
                U32 msg_id,
                S32 trans_id,
                srv_cca_status_enum status);

static void srv_cca_send_install_prov_msg_req(
                srv_cca_inst_struct *inst,
                module_type dest_mod_id,
                U32 msg_id,
                S32 trans_id,
                U16 source_id,
                U16 sim_id,
                srv_cca_prov_type_enum prov_type,
                U32 prov_flag);

static void srv_cca_send_provbox_set_msg_flag_req(
                module_type dest_mod_id,
                U32 trans_id,
                U32 msg_id,
                srv_provbox_msg_flag_op_enum op,
                U32 msg_flag);

static void srv_cca_send_provbox_get_msg_info_req(module_type dest_mod_id, U32 trans_id, U32 msg_id);

static void srv_cca_send_provbox_update_msg_info_req(
                module_type dest_mod_id,
                U32 trans_id,
                U32 msg_id,
                U32 info_mask,
                U32 install_time,
                srv_provbox_msg_read_status_enum read_status,
                srv_provbox_msg_pin_status_enum pin_status,
                srv_provbox_msg_config_status_struct *msg_config_status);

static void srv_cca_copy_msg_config_status(
                srv_provbox_msg_config_status_struct *src_msg_config_status,
                srv_provbox_msg_config_status_struct *dst_msg_config_status);



static int srv_cca_init_config_result(srv_cca_inst_struct *inst, srv_provbox_msg_config_status_struct *msg_config_status);

static void srv_cca_job_current_process_msg_job_finished(srv_cca_cntx_struct *cntx);

static MMI_BOOL srv_cca_update_provbox_config_result(
                    srv_provbox_msg_config_status_struct *msg_config_status,
                    U16 cca_config_id,
                    srv_cca_status_enum cca_app_config_result,
                    srv_cca_status_enum cca_msg_config_result);

static void srv_cca_update_provbox_msg_info(srv_cca_inst_struct *inst, U32 info_mask);
static void srv_cca_update_msg_config_status(srv_cca_inst_struct *inst, U32 msg_id, U16 config_id, srv_cca_status_enum app_config_status, MMI_BOOL update_time);




/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/

#define SRV_CCA_PROVBOX_INIT
/*****************************************************************************
 * FUNCTION
 *  srv_cca_provbox_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_provbox_init(void)
{
    mmi_frm_set_protocol_event_handler(
            MSG_ID_SRV_CCA_PROCESS_PROV_MSG_REQ,
            (PsIntFuncPtr) srv_cca_process_prov_msg_req_hdlr,
            MMI_FALSE);

    mmi_frm_set_protocol_event_handler(
            MSG_ID_SRV_CCA_SRC_INSTALL_PROV_MSG_CNF,
            (PsIntFuncPtr) srv_cca_src_install_prov_msg_cnf_hdlr,
            MMI_FALSE);

    mmi_frm_set_protocol_event_handler(
            MSG_ID_SRV_PROVBOX_SET_MSG_FLAG_CNF,
            (PsIntFuncPtr) srv_cca_provbox_set_msg_flag_cnf_hdlr,
            MMI_FALSE);

    mmi_frm_set_protocol_event_handler(
            MSG_ID_SRV_PROVBOX_GET_MSG_INFO_CNF,
            (PsIntFuncPtr) srv_cca_provbox_get_msg_info_cnf_hdlr,
            MMI_FALSE);

    mmi_frm_set_protocol_event_handler(
            MSG_ID_SRV_PROVBOX_UPDATE_MSG_INFO_CNF,
            (PsIntFuncPtr) srv_cca_provbox_update_msg_info_cnf_hdlr,
            MMI_TRUE);

}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_source_id_provbox_to_cca
 * DESCRIPTION
 *  
 * PARAMETERS
 *  provbox_src_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U16 srv_cca_source_id_provbox_to_cca(srv_provbox_source_id_enum provbox_src_id)
{
#ifdef __SRV_CCA_SLIM__

    /* Potential rule: ProvBox should notify CCA once modify it */

    return provbox_src_id + 1;

#else /* __SRV_CCA_SLIM__ */


    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cca_src_id = SRV_CCA_SOURCE_TEST;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (provbox_src_id)
    {
        case SRV_PROVBOX_SOURCE_ID_TEST:
            cca_src_id = SRV_CCA_SOURCE_TEST;
            break;

        case SRV_PROVBOX_SOURCE_ID_WAP:
            cca_src_id = SRV_CCA_SOURCE_WAP;
            break;

        case SRV_PROVBOX_SOURCE_ID_DM:
            cca_src_id = SRV_CCA_SOURCE_DM;
            break;

        case SRV_PROVBOX_SOURCE_ID_SPA:
            cca_src_id = SRV_CCA_SOURCE_SPA;
            break;

        default:
            SRV_CCA_ASSERT(0);
            break;
    }
    return cca_src_id;

    
#endif /* __SRV_CCA_SLIM__ */
}


#ifdef __SRV_CCA_SLIM__

/* Use for ProvBox<-->CCA config id mapping */
static const U16 g_srv_cca_self_config_id_map_tbl[] =
{
    /* SRV_PROVBOX_CONFIG_ID_INVALID,    */      SRV_CCA_CONFIG_INVALID,
    /* SRV_PROVBOX_CONFIG_ID_TEST,       */      SRV_CCA_CONFIG_TEST, 
    /* SRV_PROVBOX_CONFIG_ID_DATAACCOUNT,*/      SRV_CCA_CONFIG_DTACCT,      
    /* SRV_PROVBOX_CONFIG_ID_WLAN,       */      SRV_CCA_CONFIG_WLAN,         
    /* SRV_PROVBOX_CONFIG_ID_BROWSER,    */      SRV_CCA_CONFIG_BROWSER,        
    /* SRV_PROVBOX_CONFIG_ID_MMS,        */      SRV_CCA_CONFIG_MMS,           
    /* SRV_PROVBOX_CONFIG_ID_SIP,        */      SRV_CCA_CONFIG_SIP,           
    /* SRV_PROVBOX_CONFIG_ID_IMPS,       */      SRV_CCA_CONFIG_IMPS,          
    /* SRV_PROVBOX_CONFIG_ID_EMAIL,      */      SRV_CCA_CONFIG_EMAIL,          
    /* SRV_PROVBOX_CONFIG_ID_SYNCMLDS,   */      SRV_CCA_CONFIG_SYNCMLDS,        
    /* SRV_PROVBOX_CONFIG_ID_SYNCMLDM,   */      SRV_CCA_CONFIG_SYNCMLDM,          
    /* SRV_PROVBOX_CONFIG_ID_PUSH,       */      SRV_CCA_CONFIG_PUSH,         
    /* SRV_PROVBOX_CONFIG_ID_WLAN_DMP,   */      SRV_CCA_CONFIG_WLAN_DMP,         
    /* SRV_PROVBOX_CONFIG_ID_SIP_DMP,    */      SRV_CCA_CONFIG_SIP_DMP,        
    /* SRV_PROVBOX_CONFIG_ID_RTSP,       */      SRV_CCA_CONFIG_RTSP,        
    /* SRV_PROVBOX_CONFIG_ID_SUPL        */      SRV_CCA_CONFIG_SUPL             
};

/* Use for ProvBox<-->CCA config id mapping */
static const srv_provbox_config_id_enum g_srv_cca_provbox_config_id_map_tbl[] = 
{
    SRV_PROVBOX_CONFIG_ID_INVALID,          /* SRV_CCA_CONFIG_INVALID,      */
    SRV_PROVBOX_CONFIG_ID_TEST,             /* SRV_CCA_CONFIG_TEST,         */
    SRV_PROVBOX_CONFIG_ID_DATAACCOUNT,      /* SRV_CCA_CONFIG_DTACCT,       */
    SRV_PROVBOX_CONFIG_ID_WLAN,             /* SRV_CCA_CONFIG_WLAN,         */
    SRV_PROVBOX_CONFIG_ID_BROWSER,          /* SRV_CCA_CONFIG_BROWSER,      */  
    SRV_PROVBOX_CONFIG_ID_MMS,              /* SRV_CCA_CONFIG_MMS,          */ 
    SRV_PROVBOX_CONFIG_ID_SIP,              /* SRV_CCA_CONFIG_SIP,          */ 
    SRV_PROVBOX_CONFIG_ID_IMPS,             /* SRV_CCA_CONFIG_IMPS,         */ 
    SRV_PROVBOX_CONFIG_ID_EMAIL,            /* SRV_CCA_CONFIG_EMAIL,        */  
    SRV_PROVBOX_CONFIG_ID_SYNCMLDS,         /* SRV_CCA_CONFIG_SYNCMLDS,     */   
    SRV_PROVBOX_CONFIG_ID_SYNCMLDM,         /* SRV_CCA_CONFIG_SYNCMLDM,     */     
    SRV_PROVBOX_CONFIG_ID_PUSH,             /* SRV_CCA_CONFIG_PUSH,         */
    SRV_PROVBOX_CONFIG_ID_WLAN_DMP,         /* SRV_CCA_CONFIG_WLAN_DMP,     */    
    SRV_PROVBOX_CONFIG_ID_SIP_DMP,          /* SRV_CCA_CONFIG_SIP_DMP,      */  
    SRV_PROVBOX_CONFIG_ID_RTSP,             /* SRV_CCA_CONFIG_RTSP,         */ 
    SRV_PROVBOX_CONFIG_ID_SUPL              /* SRV_CCA_CONFIG_SUPL          */   
};

#endif /* __SRV_CCA_SLIM__ */

/*****************************************************************************
 * FUNCTION
 *  srv_cca_config_id_provbox_to_cca
 * DESCRIPTION
 *  
 * PARAMETERS
 *  provbox_config_id       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U16 srv_cca_config_id_provbox_to_cca(srv_provbox_config_id_enum provbox_config_id)
{
#ifdef __SRV_CCA_SLIM__

    U32 i;

    for (i = 0; i < sizeof(g_srv_cca_provbox_config_id_map_tbl)/sizeof(srv_provbox_config_id_enum); i++)
    {
        if (g_srv_cca_provbox_config_id_map_tbl [i] == provbox_config_id)
            return g_srv_cca_self_config_id_map_tbl[i];
    }
    return SRV_CCA_CONFIG_INVALID;
    
#else /* __SRV_CCA_SLIM__ */

    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cca_config_id = SRV_CCA_CONFIG_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (provbox_config_id)
    {
        case SRV_PROVBOX_CONFIG_ID_INVALID:
            cca_config_id = SRV_CCA_CONFIG_INVALID;
            break;

        case SRV_PROVBOX_CONFIG_ID_TEST:
            cca_config_id = SRV_CCA_CONFIG_TEST;
            break;

        case SRV_PROVBOX_CONFIG_ID_DATAACCOUNT:
            cca_config_id = SRV_CCA_CONFIG_DTACCT;
            break;

        case SRV_PROVBOX_CONFIG_ID_WLAN:
            cca_config_id = SRV_CCA_CONFIG_WLAN;
            break;

        case SRV_PROVBOX_CONFIG_ID_BROWSER:
            cca_config_id = SRV_CCA_CONFIG_BROWSER;
            break;

        case SRV_PROVBOX_CONFIG_ID_MMS:
            cca_config_id = SRV_CCA_CONFIG_MMS;
            break;

        case SRV_PROVBOX_CONFIG_ID_SIP:
            cca_config_id = SRV_CCA_CONFIG_SIP;
            break;

        case SRV_PROVBOX_CONFIG_ID_IMPS:
            cca_config_id = SRV_CCA_CONFIG_IMPS;
            break;

        case SRV_PROVBOX_CONFIG_ID_EMAIL:
            cca_config_id = SRV_CCA_CONFIG_EMAIL;
            break;

        case SRV_PROVBOX_CONFIG_ID_SYNCMLDS:
            cca_config_id = SRV_CCA_CONFIG_SYNCMLDS;
            break;

        case SRV_PROVBOX_CONFIG_ID_SYNCMLDM:
            cca_config_id = SRV_CCA_CONFIG_SYNCMLDM;
            break;

        case SRV_PROVBOX_CONFIG_ID_PUSH:
            cca_config_id = SRV_CCA_CONFIG_PUSH;
            break;

    #ifdef __MMI_WLAN_OTAP_DMP__    /* DMP Spec -- WLAN */
        case SRV_PROVBOX_CONFIG_ID_WLAN_DMP:
            cca_config_id = SRV_CCA_CONFIG_WLAN_DMP;
            break;
    #endif /* __MMI_WLAN_OTAP_DMP__ */ 

    #ifdef __MMI_VOIP_OTAP_DMP__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_VOIP_OTAP_DMP__ */ 

        case SRV_PROVBOX_CONFIG_ID_RTSP:
            cca_config_id = SRV_CCA_CONFIG_RTSP;
            break;

        case SRV_PROVBOX_CONFIG_ID_SUPL:
            cca_config_id = SRV_CCA_CONFIG_SUPL;
            break;

        default:
            SRV_CCA_ASSERT(0);
            break;
    }
    return cca_config_id;

#endif /* __SRV_CCA_SLIM__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_config_id_cca_to_provbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cca_config_id       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_config_id_enum srv_cca_config_id_cca_to_provbox(U16 cca_config_id)
{
#ifdef __SRV_CCA_SLIM__
    
        U32 i;
    
        for (i = 0; i < sizeof(g_srv_cca_self_config_id_map_tbl)/sizeof(U16); i++)
        {
            if (g_srv_cca_self_config_id_map_tbl [i] == cca_config_id)
                return g_srv_cca_provbox_config_id_map_tbl[i];
        }
        return SRV_PROVBOX_CONFIG_ID_INVALID;
        
#else /* __SRV_CCA_SLIM__ */

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_config_id_enum provbox_config_id = SRV_PROVBOX_CONFIG_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cca_config_id)
    {
        case SRV_CCA_CONFIG_INVALID:
            provbox_config_id = SRV_PROVBOX_CONFIG_ID_INVALID;
            break;

        case SRV_CCA_CONFIG_TEST:
            provbox_config_id = SRV_PROVBOX_CONFIG_ID_TEST;
            break;
        case SRV_CCA_CONFIG_DTACCT:
            provbox_config_id = SRV_PROVBOX_CONFIG_ID_DATAACCOUNT;
            break;

        case SRV_CCA_CONFIG_WLAN:
            provbox_config_id = SRV_PROVBOX_CONFIG_ID_WLAN;
            break;

        case SRV_CCA_CONFIG_BROWSER:
            provbox_config_id = SRV_PROVBOX_CONFIG_ID_BROWSER;
            break;

        case SRV_CCA_CONFIG_MMS:
            provbox_config_id = SRV_PROVBOX_CONFIG_ID_MMS;
            break;

        case SRV_CCA_CONFIG_SIP:
            provbox_config_id = SRV_PROVBOX_CONFIG_ID_SIP;
            break;

        case SRV_CCA_CONFIG_IMPS:
            provbox_config_id = SRV_PROVBOX_CONFIG_ID_IMPS;
            break;

        case SRV_CCA_CONFIG_EMAIL:
            provbox_config_id = SRV_PROVBOX_CONFIG_ID_EMAIL;
            break;

        case SRV_CCA_CONFIG_SYNCMLDS:
            provbox_config_id = SRV_PROVBOX_CONFIG_ID_SYNCMLDS;
            break;

        case SRV_CCA_CONFIG_SYNCMLDM:
            provbox_config_id = SRV_PROVBOX_CONFIG_ID_SYNCMLDM;
            break;

        case SRV_CCA_CONFIG_PUSH:
            provbox_config_id = SRV_PROVBOX_CONFIG_ID_PUSH;
            break;

    #ifdef __MMI_WLAN_OTAP_DMP__    /* DMP Spec -- WLAN */
        case SRV_CCA_CONFIG_WLAN_DMP:
            provbox_config_id = SRV_PROVBOX_CONFIG_ID_WLAN_DMP;
            break;
    #endif /* __MMI_WLAN_OTAP_DMP__ */ 

    #ifdef __MMI_VOIP_OTAP_DMP__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_VOIP_OTAP_DMP__ */ 

       case SRV_CCA_CONFIG_RTSP:
           provbox_config_id = SRV_PROVBOX_CONFIG_ID_RTSP;
           break;
        
        case SRV_CCA_CONFIG_SUPL:
            provbox_config_id = SRV_PROVBOX_CONFIG_ID_SUPL;
            break;

        default:
            SRV_CCA_ASSERT(0);
            break;
    }
    return provbox_config_id;
    
#endif /* __SRV_CCA_SLIM__ */

}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_prov_type_provbox_to_cca
 * DESCRIPTION
 *  
 * PARAMETERS
 *  provbox_msg_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_cca_prov_type_enum srv_cca_prov_type_provbox_to_cca(srv_provbox_msg_type_enum provbox_msg_type)
{
#ifdef __SRV_CCA_SLIM__
        
     /* Protential rule: the index mapping should not be changed */
     return provbox_msg_type == SRV_PROVBOX_MSG_TYPE_SIM_MMSICP ? SRV_CCA_PROV_TYPE_SIM_PROV : SRV_CCA_PROV_TYPE_OTA_PROV;
            
#else /* __SRV_CCA_SLIM__ */

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_prov_type_enum cca_prov_type = SRV_CCA_PROV_TYPE_OTA_PROV;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    

    switch (provbox_msg_type)
    {
        case SRV_PROVBOX_MSG_TYPE_OTA:
            cca_prov_type = SRV_CCA_PROV_TYPE_OTA_PROV;
            break;

        case SRV_PROVBOX_MSG_TYPE_DM:
            cca_prov_type = SRV_CCA_PROV_TYPE_OTA_PROV;
            break;

        case SRV_PROVBOX_MSG_TYPE_SIM_MMSICP:
            cca_prov_type = SRV_CCA_PROV_TYPE_SIM_PROV;
            break;

        default:
            SRV_CCA_ASSERT(0);
            break;
    }
    return cca_prov_type;

#endif /* __SRV_CCA_SLIM__ */

}


#ifdef __SRV_CCA_SLIM__

/* Use for ProvBox<-->CCA config status mapping
Potential rule: PrvoBox should not change it index without notify CCA */
static const srv_cca_status_enum g_srv_cca_self_config_status_map_tbl[] = 
{
    SRV_CCA_STATUS_SETTING_NOT_INSTALLED,       /* SRV_PROVBOX_CONFIG_STATUS_NOT_INSTALLED */
    SRV_CCA_STATUS_SETTING_NOAPP,               /* SRV_PROVBOX_CONFIG_STATUS_NOAPP */
    SRV_CCA_STATUS_OK,                          /* SRV_PROVBOX_CONFIG_STATUS_CONFIGED*/
    SRV_CCA_STATUS_FAIL,                        /* SRV_PROVBOX_CONFIG_STATUS_FAILED*/    
    SRV_CCA_STATUS_SETTING_SKIPPED,             /* SRV_PROVBOX_CONFIG_STATUS_SKIPPED*/
    SRV_CCA_STATUS_SETTING_UPDATED,             /* SRV_PROVBOX_CONFIG_STATUS_UPDATED*/
    SRV_CCA_STATUS_INVALID_SETTING,             /* SRV_PROVBOX_CONFIG_STATUS_INVALID*/
    SRV_CCA_STATUS_UNSUPPORTED_SETTING,         /* SRV_PROVBOX_CONFIG_STATUS_UNSUPPORTED*/
    SRV_CCA_STATUS_CORRUPTED_SETTING,           /* SRV_PROVBOX_CONFIG_STATUS_CORRUPTED*/
    SRV_CCA_STATUS_MISSING_DATA                 /* SRV_PROVBOX_CONFIG_STATUS_MISSING_DATA*/
};

#endif /* __SRV_CCA_SLIM__ */

/*****************************************************************************
 * FUNCTION
 *  srv_cca_install_status_provbox_to_cca
 * DESCRIPTION
 *  
 * PARAMETERS
 *  provbox_config_status       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_cca_status_enum srv_cca_install_status_provbox_to_cca(srv_provbox_config_status_enum provbox_config_status)
{
#ifdef __SRV_CCA_SLIM__
    
    SRV_CCA_ASSERT(provbox_config_status < sizeof(g_srv_cca_self_config_status_map_tbl)/sizeof(srv_cca_status_enum));
    
    return g_srv_cca_self_config_status_map_tbl[provbox_config_status];
    
#else /* __SRV_CCA_SLIM__ */
        
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_status_enum cca_status = SRV_CCA_STATUS_SETTING_SKIPPED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (provbox_config_status)
    {
        case SRV_PROVBOX_CONFIG_STATUS_NOT_INSTALLED:
            cca_status = SRV_CCA_STATUS_SETTING_NOT_INSTALLED;
            break;

        case SRV_PROVBOX_CONFIG_STATUS_NOAPP:
            cca_status = SRV_CCA_STATUS_SETTING_NOAPP;
            break;

        case SRV_PROVBOX_CONFIG_STATUS_CONFIGED:
            cca_status = SRV_CCA_STATUS_OK;
            break;

        case SRV_PROVBOX_CONFIG_STATUS_FAILED:
            cca_status = SRV_CCA_STATUS_FAIL;
            break;

        case SRV_PROVBOX_CONFIG_STATUS_SKIPPED:
            cca_status = SRV_CCA_STATUS_SETTING_SKIPPED;
            break;

        case SRV_PROVBOX_CONFIG_STATUS_UPDATED:
            cca_status = SRV_CCA_STATUS_SETTING_UPDATED;
            break;

        case SRV_PROVBOX_CONFIG_STATUS_INVALID:
            cca_status = SRV_CCA_STATUS_INVALID_SETTING;
            break;

        case SRV_PROVBOX_CONFIG_STATUS_UNSUPPORTED:
            cca_status = SRV_CCA_STATUS_UNSUPPORTED_SETTING;
            break;

        case SRV_PROVBOX_CONFIG_STATUS_CORRUPTED:
            cca_status = SRV_CCA_STATUS_CORRUPTED_SETTING;
            break;

        case SRV_PROVBOX_CONFIG_STATUS_MISSING_DATA:
            cca_status = SRV_CCA_STATUS_MISSING_DATA;
            break;
        
        default:
            break;

    }
    return cca_status;

#endif /* __SRV_CCA_SLIM__ */
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_install_status_cca_to_provbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cca_config_status       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_config_status_enum srv_cca_install_status_cca_to_provbox(srv_cca_status_enum cca_config_status)
{
#ifdef __SRV_CCA_SLIM__

    U32 i;

    for (i = 0; i < sizeof(g_srv_cca_self_config_status_map_tbl)/sizeof(srv_cca_status_enum); i++)
    {
        if (g_srv_cca_self_config_status_map_tbl[i] == cca_config_status)
            return (srv_provbox_config_status_enum)i;
    }
    return SRV_PROVBOX_CONFIG_STATUS_NOT_INSTALLED;
        
#else /* __SRV_CCA_SLIM__ */

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_config_status_enum provbox_config_status = SRV_PROVBOX_CONFIG_STATUS_NOT_INSTALLED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cca_config_status)
    {
        case SRV_CCA_STATUS_SETTING_NOT_INSTALLED:
            provbox_config_status = SRV_PROVBOX_CONFIG_STATUS_NOT_INSTALLED;
            break;

        case SRV_CCA_STATUS_SETTING_NOAPP:
            provbox_config_status = SRV_PROVBOX_CONFIG_STATUS_NOAPP;
            break;

        case SRV_CCA_STATUS_OK:
            provbox_config_status = SRV_PROVBOX_CONFIG_STATUS_CONFIGED;
            break;

        case SRV_CCA_STATUS_FAIL:
            provbox_config_status = SRV_PROVBOX_CONFIG_STATUS_FAILED;
            break;

        case SRV_CCA_STATUS_SETTING_SKIPPED:
            provbox_config_status = SRV_PROVBOX_CONFIG_STATUS_SKIPPED;
            break;

        case SRV_CCA_STATUS_SETTING_UPDATED:
            provbox_config_status = SRV_PROVBOX_CONFIG_STATUS_UPDATED;
            break;

        case SRV_CCA_STATUS_INVALID_SETTING:
            provbox_config_status = SRV_PROVBOX_CONFIG_STATUS_INVALID;
            break;

        case SRV_CCA_STATUS_UNSUPPORTED_SETTING:
            provbox_config_status = SRV_PROVBOX_CONFIG_STATUS_UNSUPPORTED;
            break;

        case SRV_CCA_STATUS_CORRUPTED_SETTING:
            provbox_config_status = SRV_PROVBOX_CONFIG_STATUS_CORRUPTED;
            break;

        case SRV_CCA_STATUS_MISSING_DATA:
            provbox_config_status = SRV_PROVBOX_CONFIG_STATUS_MISSING_DATA;
            break;

        default:
            SRV_CCA_ASSERT(0);
            break;
    }

    return provbox_config_status;

#endif /* __SRV_CCA_SLIM__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_process_prov_msg_req_hdlr
 * DESCRIPTION
 *  MSG_ID_SRV_CCA_PROCESS_PROV_MSG_REQ handler
 * PARAMETERS
 *  msg         [IN]        
 *  mod_id      [IN]        
 *  ilm         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_cca_process_prov_msg_req_hdlr(void *msg, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_job_struct *job;
    srv_cca_status_enum result;
    srv_cca_process_prov_msg_req_struct *req = (srv_cca_process_prov_msg_req_struct*) msg;
    srv_cca_cntx_struct *cntx = srv_cca_get_cntx();
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        SRV_CCA_TRC_INFO,
        TRC_SRV_CCA_PROCESS_PROV_MSG_REQ_HDLR,
        req->trans_id,
        req->msg_id,
        inst->cca_state,
        inst->process_state);

    result = srv_cca_accept_process_prov_msg_req(cntx);
    if (result != SRV_CCA_STATUS_OK)
    {
        srv_cca_send_process_prov_msg_cnf((module_type) mod_id, req->msg_id, req->trans_id, result);
		srv_cca_emit_notify_event(inst, SRV_CCA_NOTIFY_TYPE_NOT_AVAILABLE);
		return MMI_RET_OK;
    }

    inst->msg_info_cnf = srv_cca_malloc_type(srv_provbox_get_msg_info_cnf_struct);
    job = srv_cca_job_create_new_job(SRV_CCA_JOB_PROCESS_PROV_MSG_REQ, (module_type) mod_id, (void*)msg);
    if (!inst->msg_info_cnf || !job)
    {
        srv_cca_job_free_job(job);
        srv_cca_send_process_prov_msg_cnf((module_type) mod_id, req->msg_id, req->trans_id, SRV_CCA_STATUS_MEMFULL);
        srv_cca_emit_notify_event(inst, SRV_CCA_NOTIFY_TYPE_MEM_FULL);

        return MMI_RET_OK;
    }
    /* show please wait,  may need to handle DM operation or installing SIM provisioning background for some time firstly. 
     *  ProvBoxUI already show "please wait" and not response to END Key.
    */
    srv_cca_job_center_scheduler(cntx, job->type, job);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_src_install_prov_msg_cnf_hdlr
 * DESCRIPTION
 *  MSG_ID_SRV_CCA_SOURCE_INSTALL_MSG_CNF handler
 * PARAMETERS
 *  msg         [IN]        
 *  mod_id      [IN]        
 *  ilm         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_cca_src_install_prov_msg_cnf_hdlr(void *msg, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_src_install_prov_msg_cnf_struct *cnf_data;
    srv_cca_cntx_struct *cntx = srv_cca_get_cntx();
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_data = (srv_cca_src_install_prov_msg_cnf_struct*) msg;
    SRV_CCA_ASSERT(cnf_data->trans_id == SRV_CCA_TRANS_ID_INSTALL_MSG);

    MMI_TRACE(
        SRV_CCA_TRC_INFO,
        TRC_SRV_CCA_SOURCE_INSTALL_PROV_MSG_CNF_HDLR,
        cnf_data->trans_id,
        cnf_data->msg_id,
        cnf_data->source_id,
        cnf_data->sim_id,
        cnf_data->prov_type,
        cnf_data->prov_flag,
        cnf_data->status,
        inst->process_state);

    /* may be reset when update fail, check it here */    
    if  (inst->process_state == SRV_CCA_PROCESS_MSG_STATE_RESET_MSG_FLAG)
        return MMI_RET_OK;

    inst->process_state = SRV_CCA_PROCESS_MSG_STATE_RESET_MSG_FLAG;
    srv_cca_send_provbox_set_msg_flag_req(
        srv_cca_get_module_id_by_source(SRV_CCA_SOURCE_PROVBOX),
        SRV_CCA_TRANS_ID_RESET_MSG_FLAG,
        cnf_data->msg_id,
        SRV_PROVBOX_MSG_FLAG_OP_CLEAR,
        SRV_PROVBOX_MSG_FLAG_READING);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_provbox_set_msg_flag_cnf_hdlr
 * DESCRIPTION
 *  MSG_ID_SRV_PROVBOX_SET_MSG_FLAG_CNF handler
 * PARAMETERS
 *  msg         [IN]        
 *  mod_id      [IN]        
 *  ilm         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_cca_provbox_set_msg_flag_cnf_hdlr(void *msg, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_set_msg_flag_cnf_struct *cnf_data;
    srv_cca_process_prov_msg_req_struct *req_data;
    srv_cca_cntx_struct *cntx = srv_cca_get_cntx();
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_data = (srv_provbox_set_msg_flag_cnf_struct*) msg;

    MMI_TRACE(
        SRV_CCA_TRC_INFO,
        TRC_SRV_CCA_PROVBOX_SET_MSG_FALG_CNF_HDLR,
        cnf_data->trans_id,
        cnf_data->msg_id,
        cnf_data->op,
        cnf_data->msg_flag,
        cnf_data->result,
        inst->process_state,
        inst->end_key_pressed);

    SRV_CCA_ASSERT(inst->cca_state == SRV_CCA_STATE_PROCESS_MSG);

    req_data = (srv_cca_process_prov_msg_req_struct*) cntx->curr_job->data;

    if (inst->end_key_pressed != 0 || cnf_data->result != SRV_PROVBOX_RESULT_OK)
    {
        if (inst->end_key_pressed == 0)
        {
            if (cnf_data->result != SRV_PROVBOX_RESULT_OK && cnf_data->result != SRV_PROVBOX_RESULT_MEM_FULL &&
                cnf_data->result != SRV_PROVBOX_RESULT_DISK_FULL)
            {
                srv_cca_emit_notify_event(inst, SRV_CCA_NOTIFY_TYPE_GET_MSG_FAIL);
            }
        }
        inst->process_state = SRV_CCA_PROCESS_MSG_STATE_END_PROCESS_MSG;
        srv_cca_send_process_prov_msg_cnf(
            cntx->curr_job->src_mod_id,
            req_data->msg_id,
            req_data->trans_id,
            SRV_CCA_STATUS_FAIL);
        srv_cca_job_center_scheduler(cntx, SRV_CCA_JOB_PROCESS_PROV_MSG_CNF, NULL);
        return MMI_RET_OK;
    }

    if (inst->process_state == SRV_CCA_PROCESS_MSG_STATE_SET_MSG_FLAG)
    {

        SRV_CCA_ASSERT(cnf_data->trans_id == SRV_CCA_TRANS_ID_SET_MSG_FLAG);

        if (inst->end_key_pressed != 0)
        {
            inst->end_key_pressed = 0;
            inst->update_info_fail = SRV_PROVBOX_RESULT_OK;
            inst->process_state = SRV_CCA_PROCESS_MSG_STATE_RESET_MSG_FLAG;
            srv_cca_send_provbox_set_msg_flag_req(
                srv_cca_get_module_id_by_source(SRV_CCA_SOURCE_PROVBOX),
                SRV_CCA_TRANS_ID_RESET_MSG_FLAG,
                cnf_data->msg_id,
                SRV_PROVBOX_MSG_FLAG_OP_CLEAR,
                SRV_PROVBOX_MSG_FLAG_READING);
            return MMI_RET_OK;
        }

        inst->process_state = SRV_CCA_PROCESS_MSG_STATE_GET_MSG_INFO;
        srv_cca_send_provbox_get_msg_info_req(
            srv_cca_get_module_id_by_source(SRV_CCA_SOURCE_PROVBOX),
            SRV_CCA_TRANS_ID_GET_MSG_INFO,
            cnf_data->msg_id);
        return MMI_RET_OK;
    }
  
  if (inst->process_state == SRV_CCA_PROCESS_MSG_STATE_RESET_MSG_FLAG)
    {
        SRV_CCA_ASSERT(cnf_data->trans_id == SRV_CCA_TRANS_ID_RESET_MSG_FLAG);

        if (inst->end_key_pressed == 0)
        {
            if (inst->update_info_fail != SRV_PROVBOX_RESULT_OK &&
                inst->update_info_fail != SRV_PROVBOX_RESULT_MEM_FULL &&
                inst->update_info_fail != SRV_PROVBOX_RESULT_DISK_FULL)
            {
                srv_cca_emit_notify_event(inst,SRV_CCA_NOTIFY_TYPE_UPDATE_MSG_FAIL);
            }
        }

        inst->process_state = SRV_CCA_PROCESS_MSG_STATE_END_PROCESS_MSG;
        srv_cca_send_process_prov_msg_cnf(
            cntx->curr_job->src_mod_id,
            req_data->msg_id,
            req_data->trans_id,
            inst->result);

        srv_cca_job_center_scheduler(cntx, SRV_CCA_JOB_PROCESS_PROV_MSG_CNF, NULL);
        return MMI_RET_OK;
    }
    else
    {
        return MMI_RET_OK;
    };
}



#ifdef __SRV_CCA_SLIM__

static void srv_cca_proxbox_begin_install(srv_provbox_get_msg_info_cnf_struct* info_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cca_src_id;
    U32 prov_flag = 0;
    module_type src_mod_id;
    srv_cca_prov_type_enum cca_prov_type;
    srv_cca_cntx_struct *cntx = srv_cca_get_cntx();
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cca_src_id = srv_cca_source_id_provbox_to_cca(info_data->cmn_info.src_id);
    src_mod_id = srv_cca_get_module_id_by_source(cca_src_id);
    cca_prov_type = srv_cca_prov_type_provbox_to_cca(info_data->cmn_info.msg_type);
    if (info_data->pin_status == SRV_PROVBOX_MSG_PIN_STATUS_VERIFIED)
        SRV_CCA_SET_FLAG(prov_flag, (U32) SRV_CCA_PROV_FLAG_PIN_VERIFIED);

    inst->process_state = SRV_CCA_PROCESS_MSG_STATE_BEGIN_INSTALL_MSG;
    srv_cca_send_install_prov_msg_req(
        inst,
        src_mod_id,
        info_data->cmn_info.msg_id,
        SRV_CCA_TRANS_ID_INSTALL_MSG,
        (U16) cca_src_id,
        (U16) info_data->cmn_info.sim_id,
        cca_prov_type,
        prov_flag);
}

#endif /* __SRV_CCA_SLIM__ */


/*****************************************************************************
 * FUNCTION
 *  srv_cca_provbox_get_msg_info_cnf_hdlr
 * DESCRIPTION
 *  MSG_ID_SRV_PROVBOX_GET_MSG_INFO_CNF handler
 * PARAMETERS
 *  msg         [IN]        
 *  mod_id      [IN]        
 *  ilm         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_cca_provbox_get_msg_info_cnf_hdlr(void *msg, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __SRV_CCA_SLIM__
    U16 cca_src_id;
    U32 prov_flag = 0;
    module_type src_mod_id;
    srv_cca_prov_type_enum cca_prov_type;
#endif /* __SRV_CCA_SLIM__ */

    srv_provbox_get_msg_info_cnf_struct *info_data;
    srv_cca_cntx_struct *cntx = srv_cca_get_cntx();
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info_data = (srv_provbox_get_msg_info_cnf_struct*) msg;

    MMI_TRACE(
        SRV_CCA_TRC_INFO,
        TRC_SRV_CCA_PROVBOX_GET_MSG_INFO_CNF_HDLR_INFO,
        info_data->trans_id,
        info_data->pin_status,
        info_data->result,
        inst->process_state,
        inst->end_key_pressed);

    MMI_TRACE(
        SRV_CCA_TRC_INFO,
        TRC_SRV_CCA_PROVBOX_GET_MSG_INFO_CNF_HDLR_OTHER_INFO,
        info_data->cmn_info.msg_id,
        info_data->cmn_info.timestamp,
        info_data->cmn_info.install_time,
        info_data->cmn_info.src_id,
        info_data->cmn_info.sim_id,
        info_data->cmn_info.box_type,
        info_data->cmn_info.msg_type,
        info_data->cmn_info.read_status,
        info_data->cmn_info.sender_addr.addr_len);

    SRV_CCA_ASSERT(inst->msg_info_cnf);
    SRV_CCA_ASSERT(info_data->trans_id == SRV_CCA_TRANS_ID_GET_MSG_INFO);

    if (inst->end_key_pressed != 0 || info_data->result != SRV_PROVBOX_RESULT_OK)
    {
        if (inst->end_key_pressed == 0)
        {
            if (info_data->result != SRV_PROVBOX_RESULT_OK &&
                info_data->result != SRV_PROVBOX_RESULT_MEM_FULL && info_data->result != SRV_PROVBOX_RESULT_DISK_FULL)
            {
                srv_cca_emit_notify_event(inst, SRV_CCA_NOTIFY_TYPE_GET_MSG_FAIL);
            }
        }
        inst->end_key_pressed = 0;
        inst->update_info_fail = SRV_PROVBOX_RESULT_OK;
        inst->process_state = SRV_CCA_PROCESS_MSG_STATE_RESET_MSG_FLAG;
        inst->result = SRV_CCA_STATUS_FAIL;
        srv_cca_send_provbox_set_msg_flag_req(
            srv_cca_get_module_id_by_source(SRV_CCA_SOURCE_PROVBOX),
            SRV_CCA_TRANS_ID_RESET_MSG_FLAG,
            info_data->cmn_info.msg_id,
            SRV_PROVBOX_MSG_FLAG_OP_CLEAR,
            SRV_PROVBOX_MSG_FLAG_READING);
        return MMI_RET_OK;
    }

    memcpy(inst->msg_info_cnf, info_data, sizeof(srv_provbox_get_msg_info_cnf_struct));
    srv_cca_init_config_result(inst, &info_data->msg_config_status);

    if (info_data->cmn_info.read_status == SRV_PROVBOX_MSG_READ_STATUS_UNREAD)
    {
        inst->process_state = SRV_CCA_PROCESS_MSG_STATE_UPDATE_READ_STATUS;
        ((srv_provbox_get_msg_info_cnf_struct*) inst->msg_info_cnf)->cmn_info.read_status =
            SRV_PROVBOX_MSG_READ_STATUS_READ;
        srv_cca_update_provbox_msg_info(inst, SRV_PROVBOX_MSG_INFO_MASK_READ_STATUS);
        return MMI_RET_OK;
    }


#ifdef __SRV_CCA_SLIM__

     srv_cca_proxbox_begin_install(info_data);

#else /* __SRV_CCA_SLIM__ */

    cca_src_id = srv_cca_source_id_provbox_to_cca(info_data->cmn_info.src_id);
    src_mod_id = srv_cca_get_module_id_by_source(cca_src_id);
    cca_prov_type = srv_cca_prov_type_provbox_to_cca(info_data->cmn_info.msg_type);
    if (info_data->pin_status == SRV_PROVBOX_MSG_PIN_STATUS_VERIFIED)
        SRV_CCA_SET_FLAG(prov_flag, (U32) SRV_CCA_PROV_FLAG_PIN_VERIFIED);

    inst->process_state = SRV_CCA_PROCESS_MSG_STATE_BEGIN_INSTALL_MSG;
    srv_cca_send_install_prov_msg_req(
        inst,
        src_mod_id,
        info_data->cmn_info.msg_id,
        SRV_CCA_TRANS_ID_INSTALL_MSG,
        (U16) cca_src_id,
        (U16) info_data->cmn_info.sim_id,
        cca_prov_type,
        prov_flag);

#endif /* __SRV_CCA_SLIM__ */
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_provbox_update_msg_info_cnf_hdlr
 * DESCRIPTION
 *  MSG_ID_SRV_PROVBOX_UPDATE_MSG_INFO_CNF handler
 * PARAMETERS
 *  msg         [IN]        
 *  mod_id      [IN]        
 *  ilm         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_cca_provbox_update_msg_info_cnf_hdlr(void *msg, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __SRV_CCA_SLIM__
    U16 cca_src_id;
    U32 prov_flag = 0;
    module_type src_mod_id;
    srv_cca_prov_type_enum cca_prov_type;
#endif /* __SRV_CCA_SLIM__ */

    srv_provbox_update_msg_info_cnf_struct *cnf_data;
    srv_provbox_get_msg_info_cnf_struct *info_data;
    srv_cca_cntx_struct *cntx = srv_cca_get_cntx();
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_data = (srv_provbox_update_msg_info_cnf_struct*) msg;
    /* check if this message is sent to CCA or any other applications, 
       if not, should let other application to catch this primitive. */
    if (cnf_data->src_id != SRV_PROVBOX_SOURCE_ID_CCA)
        return 0;

    MMI_TRACE(
        SRV_CCA_TRC_INFO,
        TRC_SRV_CCA_PROVBOX_UPDATE_MSG_INFO_CNF_HDLR,
        cnf_data->trans_id,
        cnf_data->msg_id,
        cnf_data->src_id,
        cnf_data->result,
        inst->process_state,
        inst->end_key_pressed);

    if (cnf_data->result != SRV_PROVBOX_RESULT_OK)
    {
        inst->update_info_fail = cnf_data->result;
    }
    if (inst->end_key_pressed != 0)
    {
        inst->end_key_pressed = 0;
        inst->update_info_fail = SRV_PROVBOX_RESULT_OK;

        inst->process_state = SRV_CCA_PROCESS_MSG_STATE_RESET_MSG_FLAG;
        inst->result = SRV_CCA_STATUS_FAIL;
        srv_cca_send_provbox_set_msg_flag_req(
            srv_cca_get_module_id_by_source(SRV_CCA_SOURCE_PROVBOX),
            SRV_CCA_TRANS_ID_RESET_MSG_FLAG,
            cnf_data->msg_id,
            SRV_PROVBOX_MSG_FLAG_OP_CLEAR,
            SRV_PROVBOX_MSG_FLAG_READING);
        return 1;
    }

    info_data = (srv_provbox_get_msg_info_cnf_struct*) inst->msg_info_cnf;

    if (inst->process_state == SRV_CCA_PROCESS_MSG_STATE_UPDATE_READ_STATUS)
    {

#ifdef __SRV_CCA_SLIM__

        srv_cca_proxbox_begin_install(info_data);

#else /* __SRV_CCA_SLIM__ */

        cca_src_id = srv_cca_source_id_provbox_to_cca(info_data->cmn_info.src_id);
        src_mod_id = srv_cca_get_module_id_by_source(cca_src_id);
        cca_prov_type = srv_cca_prov_type_provbox_to_cca(info_data->cmn_info.msg_type);
        if (info_data->pin_status == SRV_PROVBOX_MSG_PIN_STATUS_VERIFIED)
            SRV_CCA_SET_FLAG(prov_flag, (U32) SRV_CCA_PROV_FLAG_PIN_VERIFIED);

        inst->process_state = SRV_CCA_PROCESS_MSG_STATE_BEGIN_INSTALL_MSG;
        srv_cca_send_install_prov_msg_req(
            inst, 
            src_mod_id,
            info_data->cmn_info.msg_id,
            SRV_CCA_TRANS_ID_INSTALL_MSG,
            (U16) cca_src_id,
            (U16) info_data->cmn_info.sim_id,
            cca_prov_type,
            prov_flag);

#endif /* __SRV_CCA_SLIM__ */

        return 1;
    }

#ifndef __SRV_CCA_SLIM__    

    else if (inst->process_state == SRV_CCA_PROCESS_MSG_STATE_UPDATE_PIN_STATUS)
    {
        return 1;
    }
    else if (inst->process_state == SRV_CCA_PROCESS_MSG_STATE_RECEIVE_NEW_DOC)
    {
        return 1;
    }
    else if (inst->process_state == SRV_CCA_PROCESS_MSG_STATE_UPDATE_APP_INSTALL_STATUS)
    {
        return 1;
    }
    else if (inst->process_state == SRV_CCA_PROCESS_MSG_STATE_UPDATE_MSG_INSTALL_STATUS)
    {
        return 1;
    }
    else
    {
        return 1;
    }

#else /* __SRV_CCA_SLIM__ */    

    return 1;

#endif /* __SRV_CCA_SLIM__ */    
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_job_is_cmn_prov_msg_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_cca_job_is_cmn_prov_msg_job(void *src, void *dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_job_struct *job = (srv_cca_job_struct*)src;
    srv_cca_src_new_setting_ind_struct *ind_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CCA_ASSERT(job);

    if (job == NULL)
        return MMI_FALSE;

    if (job->type == SRV_CCA_JOB_NEW_SETTING_IND_REQ)
    {
        ind_data = (srv_cca_src_new_setting_ind_struct*) job->data;
        if (ind_data->prov_type == SRV_CCA_PROV_TYPE_OTA_PROV)
            return MMI_TRUE;
        else
            return MMI_FALSE;
    }
    else if (job->type == SRV_CCA_JOB_PROCESS_PROV_MSG_REQ)
        return MMI_TRUE;
    else
        return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_job_check_cmn_prov_msg_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_cca_cmp_result_enum srv_cca_job_check_cmn_prov_msg_job(void *src, void *dst)
{
    if (srv_cca_job_is_cmn_prov_msg_job(src, dst))
        return SRV_CCA_CMP_RESULT_EQUAL;
    else
        return SRV_CCA_CMP_RESULT_UNEQUAL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_accept_process_prov_msg_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static srv_cca_status_enum srv_cca_accept_process_prov_msg_req(srv_cca_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 msg_num = 0;
    MMI_BOOL cmn_job = MMI_FALSE;
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if any message in processing. */
    if (inst->cca_state == SRV_CCA_STATE_PROCESS_MSG)
    {
        MMI_TRACE(
            SRV_CCA_TRC_INFO,
            TRC_SRV_CCA_ACCEPT_PROCESS_PROV_MSG_REQ_PROCESSING,
            inst->cca_state,
            cmn_job,
            msg_num);
        return SRV_CCA_STATUS_CCA_BUSY;
    }
    /* check if any common provisioning in installing. */
    if (inst->cca_state == SRV_CCA_STATE_PROV &&
        MMI_TRUE == (cmn_job = srv_cca_job_is_cmn_prov_msg_job((void*)cntx->curr_job, NULL)))
    {
        MMI_TRACE(
            SRV_CCA_TRC_INFO,
            TRC_SRV_CCA_ACCEPT_PROCESS_PROV_MSG_REQ_INSTALLING,
            inst->cca_state,
            cmn_job,
            msg_num);
        return SRV_CCA_STATUS_CCA_BUSY;
    }
    /* check if any common message in queue.  */
    msg_num = srv_cca_slist_get_num_by_data((srv_cca_slist_struct *)cntx->job_list, 
                            srv_cca_job_check_cmn_prov_msg_job, NULL);
    if (msg_num > 0)
    {
        MMI_TRACE(
            SRV_CCA_TRC_INFO,
            TRC_SRV_CCA_ACCEPT_PROCESS_PROV_MSG_REQ_IN_QUEUE,
            inst->cca_state,
            cmn_job,
            msg_num);
        return SRV_CCA_STATUS_CCA_BUSY;
    }
    SRV_CCA_ASSERT(!inst->msg_info_cnf);
    return SRV_CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_send_process_prov_msg_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest_mod_id     [IN]        
 *  msg_id          [IN]        
 *  trans_id        [IN]        
 *  status          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_send_process_prov_msg_cnf(module_type dest_mod_id, U32 msg_id, S32 trans_id, srv_cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_process_prov_msg_cnf_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_SEND_PROCESS_PROV_MSG_CNF, msg_id, trans_id, status);

    data = SRV_CCA_NEW_ILM_DATA(srv_cca_process_prov_msg_cnf_struct);

    data->msg_id = msg_id;
    data->trans_id = trans_id;
    data->status = status;

    mmi_frm_send_ilm(dest_mod_id, MSG_ID_SRV_CCA_PROCESS_PROV_MSG_CNF, (oslParaType*) data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_send_install_prov_msg_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest_mod_id     [IN]        
 *  msg_id          [IN]        
 *  trans_id        [IN]        
 *  source_id       [IN]        
 *  sim_id          [IN]        
 *  prov_type       [IN]        
 *  prov_flag       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_send_install_prov_msg_req(
                srv_cca_inst_struct *inst,
                module_type dest_mod_id,
                U32 msg_id,
                S32 trans_id,
                U16 source_id,
                U16 sim_id,
                srv_cca_prov_type_enum prov_type,
                U32 prov_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_src_install_prov_msg_req_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        SRV_CCA_TRC_INFO,
        TRC_SRV_CCA_SEND_INSTALL_PROV_MSG_REQ,
        trans_id,
        msg_id,
        source_id,
        sim_id,
        prov_type,
        prov_flag,
        inst->process_state);

    data = SRV_CCA_NEW_ILM_DATA(srv_cca_src_install_prov_msg_req_struct);

    data->msg_id = msg_id;
    data->trans_id = trans_id;
    data->source_id = source_id;
    data->sim_id = sim_id;
    data->prov_type = prov_type;
    data->prov_flag = prov_flag;

    mmi_frm_send_ilm(dest_mod_id, MSG_ID_SRV_CCA_SRC_INSTALL_PROV_MSG_REQ, (oslParaType*) data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_send_provbox_set_msg_flag_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest_mod_id     [IN]        
 *  trans_id        [IN]        
 *  msg_id          [IN]        
 *  op              [IN]        
 *  msg_flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_send_provbox_set_msg_flag_req(
                module_type dest_mod_id,
                U32 trans_id,
                U32 msg_id,
                srv_provbox_msg_flag_op_enum op,
                U32 msg_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_set_msg_flag_req_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_SEND_PROVBOX_SET_MSG_FLAG_REQ, trans_id, msg_id, op, msg_flag);

    data = SRV_CCA_NEW_ILM_DATA(srv_provbox_set_msg_flag_req_struct);

    data->trans_id = trans_id;
    data->msg_id = msg_id;
    data->op = op;
    data->msg_flag = msg_flag;

    mmi_frm_send_ilm(dest_mod_id, MSG_ID_SRV_PROVBOX_SET_MSG_FLAG_REQ, (oslParaType*) data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_send_provbox_get_msg_info_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest_mod_id     [IN]        
 *  trans_id        [IN]        
 *  msg_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_send_provbox_get_msg_info_req(module_type dest_mod_id, U32 trans_id, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_get_msg_info_req_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_SEND_PROVBOX_GET_MSG_INFO_REQ, trans_id, msg_id);

    data = SRV_CCA_NEW_ILM_DATA(srv_provbox_get_msg_info_req_struct);

    data->trans_id = trans_id;
    data->msg_id = msg_id;

    mmi_frm_send_ilm(dest_mod_id, MSG_ID_SRV_PROVBOX_GET_MSG_INFO_REQ, (oslParaType*) data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_send_provbox_update_msg_info_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest_mod_id             [IN]        
 *  trans_id                [IN]        
 *  msg_id                  [IN]        
 *  info_mask               [IN]        
 *  install_time            [IN]        
 *  read_status             [IN]        
 *  pin_status              [IN]        
 *  msg_config_status       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_send_provbox_update_msg_info_req(
                module_type dest_mod_id,
                U32 trans_id,
                U32 msg_id,
                U32 info_mask,
                U32 install_time,
                srv_provbox_msg_read_status_enum read_status,
                srv_provbox_msg_pin_status_enum pin_status,
                srv_provbox_msg_config_status_struct *msg_config_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_update_msg_info_req_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        SRV_CCA_TRC_INFO,
        TRC_SRV_CCA_SEND_PROVBOX_UPDATE_MSG_INFO_REQ,
        trans_id,
        msg_id,
        info_mask,
        install_time,
        read_status,
        pin_status);

    data = SRV_CCA_NEW_ILM_DATA(srv_provbox_update_msg_info_req_struct);

    data->trans_id = trans_id;
    data->msg_id = msg_id;
    data->src_id = SRV_PROVBOX_SOURCE_ID_CCA;
    data->info_mask = info_mask;
    data->install_time = install_time;
    data->read_status = read_status;
    data->pin_status = pin_status;
    srv_cca_copy_msg_config_status(msg_config_status, &data->msg_config_status);

    mmi_frm_send_ilm(dest_mod_id, MSG_ID_SRV_PROVBOX_UPDATE_MSG_INFO_REQ, (oslParaType*) data, NULL);
}


#ifdef __SRV_CCA_SUPPORT_AUTH__
/*****************************************************************************
 * FUNCTION
 *  srv_cca_provbox_handle_pin_ok
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info_mask       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_cca_provbox_handle_pin_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_get_msg_info_cnf_struct *info_data;
    srv_cca_cntx_struct *cntx = srv_cca_get_cntx();
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (inst->cca_state != SRV_CCA_STATE_PROCESS_MSG)
        return MMI_FALSE;
    
    info_data = (srv_provbox_get_msg_info_cnf_struct*) inst->msg_info_cnf;
    info_data->pin_status = SRV_PROVBOX_MSG_PIN_STATUS_VERIFIED;
    inst->process_state = SRV_CCA_PROCESS_MSG_STATE_UPDATE_PIN_STATUS;
    srv_cca_update_provbox_msg_info(inst, SRV_PROVBOX_MSG_INFO_MASK_PIN_STATUS);
    return MMI_TRUE;
}
#endif /* __SRV_CCA_SUPPORT_AUTH__ */


/*****************************************************************************
 * FUNCTION
 *  srv_cca_provbox_src_new_doc_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info_mask       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_cca_provbox_src_new_doc_ind_hdlr(int mod_id, srv_cca_src_new_doc_ind_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_cntx_struct *cntx = srv_cca_get_cntx(); 
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (inst->cca_state != SRV_CCA_STATE_PROCESS_MSG)
        return MMI_FALSE;
    
    /* the document shall be processed from now. */
    inst->result = SRV_CCA_STATUS_OK;
    if (data->hConfig == 0)
    {
        /* OTA provisioning must provide the CCA document */
        srv_cca_send_src_new_doc_rsp(
                (module_type) mod_id,
                data->source_id,
                data->prov_type,
                data->sim_id,
                data->spec_id,
                inst->configResult,
                inst->numApp,
                inst->msg_config_result,
                SRV_CCA_STATUS_FAIL);

        {
            srv_cca_emit_notify_event(inst, SRV_CCA_NOTIFY_TYPE_INVALID_SETTING);
        }
        srv_cca_job_center_scheduler(cntx, SRV_CCA_JOB_NEW_DOC_RSP_FEEDBACK, NULL);
        return MMI_TRUE;
    }

    /* fill provisioning context */
    inst->process_state = SRV_CCA_PROCESS_MSG_STATE_RECEIVE_NEW_DOC;
    inst->prs_mod_id = (module_type) mod_id;
    inst->source_id = data->source_id;
    inst->prov_type = SRV_CCA_PROV_TYPE_OTA_PROV;
    inst->bak_prov_type = data->prov_type;
    inst->sim_id = data->sim_id;
    inst->specId = data->spec_id;
    inst->hConfig = data->hConfig;
    if (data->sec_type == SRV_CCA_SEC_TYPE_USERNETWIN)
        SRV_CCA_SET_FLAG(inst->prov_flag, SRV_CCA_PROV_FLAG_FACTORY_PROFILE_UPDATABLE);

    inst->crtConfigIndex = 0;
    srv_cca_start_provisioning_job(cntx);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_provbox_app_config_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info_mask       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_cca_provbox_app_config_rsp_hdlr(srv_cca_inst_struct *inst, srv_cca_app_configure_rsp_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (inst->cca_state != SRV_CCA_STATE_PROCESS_MSG)
        return MMI_FALSE;

    /* should update once installed,  so if power off abnormally, can keep the right config status, 
     * the apps still not installed are treated as skipped in this scenario.
     */
    srv_cca_update_msg_config_status(inst,
            ((srv_provbox_get_msg_info_cnf_struct*) inst->msg_info_cnf)->cmn_info.msg_id,
            data->config_id,
            data->status, MMI_TRUE);
    return MMI_TRUE;        
}

/*****************************************************************************
 * FUNCTION
 *  srv_cca_update_provbox_msg_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info_mask       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_update_provbox_msg_info(srv_cca_inst_struct *inst, U32 info_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 trans_id;
    srv_provbox_get_msg_info_cnf_struct *info_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_CCA_CHECK_FLAG(info_mask, SRV_PROVBOX_MSG_INFO_MASK_READ_STATUS))
        trans_id = SRV_CCA_TRANS_ID_UPDATE_READ_STATUS;
    else if (SRV_CCA_CHECK_FLAG(info_mask, SRV_PROVBOX_MSG_INFO_MASK_PIN_STATUS))
        trans_id = SRV_CCA_TRANS_ID_UPDATE_PIN_STATUS;
    else if (SRV_CCA_CHECK_FLAG(info_mask, SRV_PROVBOX_MSG_INFO_MASK_APP_INSTALL_STATUS))
        trans_id = SRV_CCA_TRANS_ID_UPDATE_APP_INSTALL_STATUS;
    else if (SRV_CCA_CHECK_FLAG(info_mask, SRV_PROVBOX_MSG_INFO_MASK_INSTALL_STATUS))
        trans_id = SRV_CCA_TRANS_ID_UPDATE_MSG_INSTALL_STATUS;
    else
    {
        SRV_CCA_ASSERT(0);
        return;
    }

    info_data = (srv_provbox_get_msg_info_cnf_struct*) inst->msg_info_cnf;
    srv_cca_send_provbox_update_msg_info_req(
        srv_cca_get_module_id_by_source(SRV_CCA_SOURCE_PROVBOX),
        trans_id,
        info_data->cmn_info.msg_id,
        info_mask,
        info_data->cmn_info.install_time,
        info_data->cmn_info.read_status,
        info_data->pin_status,
        &info_data->msg_config_status);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_copy_msg_config_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_msg_config_status       [IN]        
 *  dst_msg_config_status       [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_copy_msg_config_status(
                srv_provbox_msg_config_status_struct *src_msg_config_status,
                srv_provbox_msg_config_status_struct *dst_msg_config_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (src_msg_config_status == NULL || dst_msg_config_status == NULL)
        return;

    dst_msg_config_status->app_num = src_msg_config_status->app_num;
    dst_msg_config_status->config_status = src_msg_config_status->config_status;
    for (i = 0; i < SRV_PROVBOX_MAX_APP_INFO_NUM; i++)
    {
        dst_msg_config_status->app_config_status[i].config_id = src_msg_config_status->app_config_status[i].config_id;
        dst_msg_config_status->app_config_status[i].status = src_msg_config_status->app_config_status[i].status;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_provbox_reset_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_provbox_reset_cntx(srv_cca_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_CCA_SLIM__

    memset(inst, 0x0, sizeof(srv_cca_inst_struct));

#else /* __SRV_CCA_SLIM__ */

    inst->process_state = SRV_CCA_PROCESS_MSG_STATE_IDLE;
    inst->msg_info_cnf = NULL;
    inst->end_key_pressed = 0;
    inst->update_info_fail = SRV_PROVBOX_RESULT_OK;
    inst->bak_prov_type = SRV_CCA_PROV_TYPE_OTA_PROV;

#endif /* __SRV_CCA_SLIM__ */

    inst->result = SRV_CCA_STATUS_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_submit_job_to_process_msg_manager
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  job         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_cca_status_enum srv_cca_submit_job_to_process_msg_manager(srv_cca_cntx_struct *cntx, srv_cca_job_type_enum type, srv_cca_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_status_enum result = SRV_CCA_STATUS_OK;
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
#ifndef __SRV_CCA_SLIM__
        
        case SRV_CCA_JOB_NEXT_JOB_REQ:
        {
            SRV_CCA_ASSERT(0);
        }
            break;
#endif /* __SRV_CCA_SLIM__ */

        case SRV_CCA_JOB_INVALID_SETTING_IND_REQ:
        {
            srv_cca_src_invalid_setting_ind_struct *data = (srv_cca_src_invalid_setting_ind_struct*)job->data;
            inst->process_state = SRV_CCA_PROCESS_MSG_STATE_RESET_MSG_FLAG;
            srv_cca_send_provbox_set_msg_flag_req(
                srv_cca_get_module_id_by_source(SRV_CCA_SOURCE_PROVBOX),
                SRV_CCA_TRANS_ID_RESET_MSG_FLAG,
                data->msg_id,
                SRV_PROVBOX_MSG_FLAG_OP_CLEAR,
                SRV_PROVBOX_MSG_FLAG_READING);
		    srv_cca_job_free_job(job);
		}
		break;

#ifndef __SRV_CCA_SLIM__
        case SRV_CCA_JOB_NEW_SETTING_IND_REQ:
            break;
#endif /* __SRV_CCA_SLIM__ */

        case SRV_CCA_JOB_NEW_SETTING_RSP_FEEDBACK:
        {
            inst->process_state = SRV_CCA_PROCESS_MSG_STATE_RESET_MSG_FLAG;
            inst->result = SRV_CCA_STATUS_FAIL;
            srv_cca_send_provbox_set_msg_flag_req(
                srv_cca_get_module_id_by_source(SRV_CCA_SOURCE_PROVBOX),
                SRV_CCA_TRANS_ID_RESET_MSG_FLAG,
                ((srv_provbox_get_msg_info_cnf_struct*) inst->msg_info_cnf)->cmn_info.msg_id,
                SRV_PROVBOX_MSG_FLAG_OP_CLEAR,
                SRV_PROVBOX_MSG_FLAG_READING);
            break;
        }

#ifndef __SRV_CCA_SLIM__
        case SRV_CCA_JOB_NEW_DOC_RSP_FEEDBACK:
            /* do nothing */
            break;
#endif /* __SRV_CCA_SLIM__ */

        case SRV_CCA_JOB_AUTH_ABORT:
        {
            if (inst->process_state == SRV_CCA_PROCESS_MSG_STATE_BEGIN_INSTALL_MSG ||
                inst->process_state == SRV_CCA_PROCESS_MSG_STATE_RECEIVE_NEW_DOC)
            {
                inst->end_key_pressed = 0;
                inst->update_info_fail = SRV_PROVBOX_RESULT_OK;

                inst->process_state = SRV_CCA_PROCESS_MSG_STATE_RESET_MSG_FLAG;
                inst->result = SRV_CCA_STATUS_OK;
                srv_cca_send_provbox_set_msg_flag_req(
                    srv_cca_get_module_id_by_source(SRV_CCA_SOURCE_PROVBOX),
                    SRV_CCA_TRANS_ID_RESET_MSG_FLAG,
                    ((srv_provbox_get_msg_info_cnf_struct*) inst->msg_info_cnf)->cmn_info.msg_id,
                    SRV_PROVBOX_MSG_FLAG_OP_CLEAR,
                    SRV_PROVBOX_MSG_FLAG_READING);
            }
            else if (inst->process_state != SRV_CCA_PROCESS_MSG_STATE_RESET_MSG_FLAG)
            {
                inst->end_key_pressed = 1;
            }
        }
            break;


#ifdef __SRV_CCA_PROF_OPER__
        case SRV_CCA_JOB_GET_PROF_IND_REQ:
        case SRV_CCA_JOB_UPDATE_PROF_IND_REQ:
        case SRV_CCA_JOB_APP_GET_PROF_RSP_FEEDBACK:
        case SRV_CCA_JOB_APP_UPDATE_PROF_RSP_FEEDBACK:
        case SRV_CCA_JOB_SESSION_BEGIN_IND_REQ:
        case SRV_CCA_JOB_SESSION_END_IND_REQ:
            srv_cca_dm_handle_in_process_msg(cntx, type, job);
        break;
#endif /* __SRV_CCA_PROF_OPER__ */

#ifndef __SRV_CCA_SLIM__
        case SRV_CCA_JOB_PROCESS_PROV_MSG_REQ:
            break;
#endif /* __SRV_CCA_SLIM__ */

        case SRV_CCA_JOB_PROCESS_PROV_MSG_CNF:
            srv_cca_job_current_process_msg_job_finished(cntx);
            break;

        default:
        {
#ifndef __SRV_CCA_SLIM__
            SRV_CCA_ASSERT(0);
#endif /* __SRV_CCA_SLIM__ */
        }
            break;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_provbox_handle_in_idle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  job         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_cca_status_enum srv_cca_provbox_handle_in_idle(srv_cca_cntx_struct *cntx, srv_cca_job_type_enum type, srv_cca_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(type)
    {
        case SRV_CCA_JOB_PROCESS_PROV_MSG_REQ:
        {
            srv_cca_process_prov_msg_req_struct *req_data;

            req_data = (srv_cca_process_prov_msg_req_struct*) job->data;

            inst->cca_state = SRV_CCA_STATE_PROCESS_MSG;
            inst->process_state = SRV_CCA_PROCESS_MSG_STATE_SET_MSG_FLAG;
            inst->result = SRV_CCA_STATUS_FAIL;
            cntx->curr_job = job;

            srv_cca_send_provbox_set_msg_flag_req(
                MOD_MMI,
                SRV_CCA_TRANS_ID_SET_MSG_FLAG,
                req_data->msg_id,
                SRV_PROVBOX_MSG_FLAG_OP_SET,
                SRV_PROVBOX_MSG_FLAG_READING);
            break;
        }

#ifndef __SRV_CCA_SLIM__
        case SRV_CCA_JOB_PROCESS_PROV_MSG_CNF:
        {
            SRV_CCA_ASSERT(0);
        }
            break;
#endif /* __SRV_CCA_SLIM__ */

        default:
            SRV_CCA_ASSERT(0);
        break;
    }
    return SRV_CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_init_config_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_config_status       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int srv_cca_init_config_result(srv_cca_inst_struct *inst, srv_provbox_msg_config_status_struct *msg_config_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    U16 cca_config_id;
    srv_cca_status_enum cca_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst->numApp = 0;
    inst->msg_config_result = srv_cca_install_status_provbox_to_cca(msg_config_status->config_status);

    for (i = 0; i < SRV_PROVBOX_MAX_APP_INFO_NUM; i++)
    {
        if (inst->numApp > SRV_CCA_MAX_APPS)
            break;
        cca_config_id = srv_cca_config_id_provbox_to_cca(msg_config_status->app_config_status[i].config_id);
        if (cca_config_id == SRV_CCA_CONFIG_INVALID)
            continue;
        cca_status = srv_cca_install_status_provbox_to_cca(msg_config_status->app_config_status[i].status);

        inst->configResult[inst->numApp].config_id = cca_config_id;
        inst->configResult[inst->numApp].result = cca_status;
        inst->numApp++;
    }
    for (i = inst->numApp; i < SRV_CCA_MAX_APPS; i++)
    {
        inst->configResult[inst->numApp].config_id = SRV_CCA_CONFIG_INVALID;
        inst->configResult[inst->numApp].result = SRV_CCA_STATUS_SETTING_NOT_INSTALLED;
    }

    return inst->numApp;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_job_current_process_msg_job_finished
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_job_current_process_msg_job_finished(srv_cca_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cca_emit_install_finished_event(inst);

    if (inst->msg_info_cnf)
    {
        srv_cca_mfree(inst->msg_info_cnf);
        inst->msg_info_cnf = NULL;
    }

    srv_cca_job_free_job(cntx->curr_job);
    cntx->curr_job = NULL;

    inst->cca_state = SRV_CCA_STATE_IDLE;

    inst->process_state = SRV_CCA_PROCESS_MSG_STATE_IDLE;

    srv_cca_job_center_scheduler(cntx, SRV_CCA_JOB_NEXT_JOB_REQ, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_preprocess_config_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_preprocess_config_result(srv_cca_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    srv_provbox_get_msg_info_cnf_struct *cnf_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_data = (srv_provbox_get_msg_info_cnf_struct*) inst->msg_info_cnf;

    inst->msg_config_result = SRV_CCA_STATUS_SETTING_SKIPPED;
    cnf_data->msg_config_status.config_status = SRV_PROVBOX_CONFIG_STATUS_SKIPPED;

    for (i = 0; i < inst->numApp; i++)
    {
        inst->configResult[i].result = SRV_CCA_STATUS_SETTING_SKIPPED;
        if (i < SRV_PROVBOX_MAX_APP_INFO_NUM)
            cnf_data->msg_config_status.app_config_status[i].status = SRV_PROVBOX_CONFIG_STATUS_SKIPPED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_update_provbox_config_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_config_status           [IN]        
 *  cca_config_id               [IN]        
 *  cca_app_config_result       [IN]        
 *  cca_msg_config_result       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_cca_update_provbox_config_result(
                    srv_provbox_msg_config_status_struct *msg_config_status,
                    U16 cca_config_id,
                    srv_cca_status_enum cca_app_config_result,
                    srv_cca_status_enum cca_msg_config_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    MMI_BOOL changed = MMI_FALSE;
    srv_provbox_config_id_enum provbox_config_id;
    srv_provbox_config_status_enum provbox_config_status;
    srv_provbox_config_status_enum provbox_app_config_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_config_status == NULL)
        return MMI_FALSE;

    provbox_config_status = srv_cca_install_status_cca_to_provbox(cca_msg_config_result);
    if (msg_config_status->config_status != provbox_config_status)
    {
        msg_config_status->config_status = provbox_config_status;
        changed = MMI_TRUE;
    }
    if (cca_config_id == SRV_CCA_CONFIG_INVALID)
        return changed;

    provbox_config_id = srv_cca_config_id_cca_to_provbox(cca_config_id);
    provbox_app_config_status = srv_cca_install_status_cca_to_provbox(cca_app_config_result);
    for (i = 0; i < msg_config_status->app_num; i++)
    {
        if (msg_config_status->app_config_status[i].config_id == provbox_config_id)
        {
            if (msg_config_status->app_config_status[i].status != provbox_app_config_status)
            {
                msg_config_status->app_config_status[i].status = provbox_app_config_status;
                return MMI_TRUE;
            }
            return changed;
        }
    }

    SRV_CCA_ASSERT(i <= SRV_PROVBOX_MAX_APP_INFO_NUM);

    if (i >= SRV_PROVBOX_MAX_APP_INFO_NUM)
        return MMI_FALSE;

    msg_config_status->app_config_status[msg_config_status->app_num].config_id = provbox_config_id;
    msg_config_status->app_config_status[msg_config_status->app_num].status = provbox_app_config_status;
    msg_config_status->app_num++;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_update_msg_config_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id                  [IN]        
 *  config_id               [IN]        
 *  app_config_status       [IN]        
 *  update_time             [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_update_msg_config_status(srv_cca_inst_struct *inst, U32 msg_id, U16 config_id, srv_cca_status_enum app_config_status, MMI_BOOL update_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MMI_BOOL ret;
    U32 info_mask;
    srv_provbox_get_msg_info_cnf_struct *cnf_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (inst->cca_state != SRV_CCA_STATE_PROCESS_MSG)
        return;
    if (msg_id == SRV_CCA_INVALID_MSG_ID)
        return;

    SRV_CCA_ASSERT(inst->msg_info_cnf);

    cnf_data = (srv_provbox_get_msg_info_cnf_struct*) inst->msg_info_cnf;
    if (cnf_data == NULL)
        return;
    ret = srv_cca_update_provbox_config_result(
                &cnf_data->msg_config_status,
                config_id,
                app_config_status,
                inst->msg_config_result);
    if (ret)
    {
        if (update_time == MMI_FALSE)
            info_mask = SRV_PROVBOX_MSG_INFO_MASK_APP_INSTALL_STATUS;
        else
            info_mask = SRV_PROVBOX_MSG_INFO_MASK_APP_INSTALL_STATUS | SRV_PROVBOX_MSG_INFO_MASK_INSTALL_TIME;
        inst->process_state = SRV_CCA_PROCESS_MSG_STATE_UPDATE_APP_INSTALL_STATUS;
        srv_cca_update_provbox_msg_info(inst, info_mask);
    }
}



#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 
#endif /* __CCA_SUPPORT__ */




