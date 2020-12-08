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
 *  CentralConfigAgentConfig.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Target Application Configuration File
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
#include "stack_config.h"
#include "kal_public_api.h"

#include "MMIDataType.h"
#include "DebugInitDef_Int.h"

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

/* 
 * make sure 0x0000 never bring any effect, such as not L1Symbols, 
 * not affect the usage of cca_app_config_g->num_l1node_smbols, and so on...  
 */

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
#define SRV_CCA_NS_OMA_BOOTSTRAP_L1SYMBOL   SRV_CCA_NS_OMA_BOOTSTRAP
#else
#define SRV_CCA_NS_OMA_BOOTSTRAP_L1SYMBOL   0x0000     
#endif

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

/*----------------------------------------------------------------------------*/
/* Static global variable                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* DECLARATIONS: DATA ACCOUNT                                     */
/*----------------------------------------------------------------*/
static const U16 dtacct_l1symbols[] = {SRV_CCA_NS_OMA_BOOTSTRAP_L1SYMBOL, SRV_CCA_NS_OMA_NAPDEF, SRV_CCA_NS_OMA_PROXY};
extern srv_cca_status_enum srv_dtcnt_prov_is_cca_target(U16 conf_id, S32 doc_hdl, srv_cca_iterator_struct *data_list);

/*----------------------------------------------------------------*/
/* DECLARATIONS: WLAN                                             */
/*----------------------------------------------------------------*/
#if defined(__MMI_WLAN_OTAP_OMAEXT__)
static const U16 wlan_l1symbols[] = {SRV_CCA_NS_OMA_NAPDEF};
#elif defined(__MMI_WLAN_OTAP_DMP__)
static const U16 wlan_dmp_l1symbols[] = {SRV_CCA_NS_OMADMP_WIFI};
#endif 
#if defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__)
extern srv_cca_status_enum srv_dtcnt_prov_wlan_is_cca_target(U16 conf_id, S32 doc_hdl, srv_cca_iterator_struct *data_list);
#endif 

/*----------------------------------------------------------------*/
/* DECLARATIONS: BROWSER                                          */
/*----------------------------------------------------------------*/
#ifdef BROWSER_SUPPORT
static const CHAR *browser_appids[] = { "w2" };
static const U16 browser_l1symbols[] = {SRV_CCA_NS_OMA_BOOTSTRAP_L1SYMBOL, SRV_CCA_NS_OMA_PROXY, SRV_CCA_NS_OMA_APPLICATION};
#endif /* BROWSER_SUPPORT */ 
/*----------------------------------------------------------------*/
/* DECLARATIONS: MMS                                              */
/*----------------------------------------------------------------*/
#ifdef MMS_SUPPORT
static const CHAR *mms_appids[] = { "w4", "ap0005" };
static const U16 mms_l1symbols[] = {SRV_CCA_NS_OMA_BOOTSTRAP_L1SYMBOL, SRV_CCA_NS_OMA_PROXY, SRV_CCA_NS_OMA_APPLICATION};
#endif /* MMS_SUPPORT */ 
/*----------------------------------------------------------------*/
/* DECLARATIONS: SIP                                              */
/*----------------------------------------------------------------*/
//static const CHAR *sip_appids[]           =   {"ap0002"};
//static const U16 sip_l1symbols[]        =   {SRV_CCA_NS_OMA_PROXY, SRV_CCA_NS_OMA_APPLICATION};
#ifdef __MMI_VOIP_OTAP_DMP__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_VOIP_OTAP_DMP__ */ 

/*----------------------------------------------------------------*/
/* DECLARATIONS: EMAIL                                            */
/*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
static const CHAR *email_appids[] = { "25", "110", "143" };
static const U16 email_l1symbols[] = {SRV_CCA_NS_OMA_BOOTSTRAP_L1SYMBOL, SRV_CCA_NS_OMA_PROXY, SRV_CCA_NS_OMA_APPLICATION};
#endif /* __MMI_EMAIL_OTAP__ */ 

/*----------------------------------------------------------------*/
/* DECLARATIONS: SyncML-DS                                        */
/*----------------------------------------------------------------*/
#ifdef __MMI_SYNCML_CCA_SUPPORT__
static const CHAR *syncmlds_appids[] = { "w5" };
static const U16 syncmlds_l1symbols[] = {SRV_CCA_NS_OMA_BOOTSTRAP_L1SYMBOL, SRV_CCA_NS_OMA_PROXY, SRV_CCA_NS_OMA_APPLICATION};
#endif /* __MMI_SYNCML_CCA_SUPPORT__ */ 

/*----------------------------------------------------------------*/
/* DECLARATIONS: SyncML-DM                                        */
/*----------------------------------------------------------------*/
#ifdef SYNCML_DM_SUPPORT
static const CHAR *syncmldm_appids[] = { "w7" };
static const U16 syncmldm_l1symbols[] = {SRV_CCA_NS_OMA_BOOTSTRAP_L1SYMBOL, SRV_CCA_NS_OMA_PROXY, SRV_CCA_NS_OMA_APPLICATION};
#endif /* SYNCML_DM_SUPPORT */ 

/*----------------------------------------------------------------*/
/* DECLARATIONS: IMPS                                             */
/*----------------------------------------------------------------*/
#ifdef __MMI_IMPS_OTA__
static const CHAR *imps_appids[] = { "wA" };
static const U16 imps_l1symbols[] = {SRV_CCA_NS_OMA_BOOTSTRAP_L1SYMBOL, SRV_CCA_NS_OMA_PROXY, SRV_CCA_NS_OMA_APPLICATION};
#endif /* __MMI_IMPS_OTA__ */ 

/*----------------------------------------------------------------*/
/* DECLARATIONS: PUSH                                             */
/*----------------------------------------------------------------*/

#ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__
static const CHAR *push_appids[] = { "oma:mo:oma-push:1.0" };
static const U16 push_l1symbols[] = {SRV_CCA_NS_OMA_NAPDEF, SRV_CCA_NS_OMA_PROXY, SRV_CCA_NS_OMA_APPLICATION};
#endif /* __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__ */ 

/*----------------------------------------------------------------*/
/* DECLARATIONS: RTSP (streaming)                                 */
/*----------------------------------------------------------------*/

#ifdef __MMI_STREAMING_OTAP__
static const CHAR *rtsp_appids[] = { "554" };
static const U16 rtsp_l1symbols[] = {SRV_CCA_NS_OMA_BOOTSTRAP_L1SYMBOL, SRV_CCA_NS_OMA_PROXY, SRV_CCA_NS_OMA_APPLICATION};
#endif /* __MMI_STREAMING_OTAP__ */ 

/*----------------------------------------------------------------*/
/* DECLARATIONS: SUPL: Secure User Plane Location (AGPS)          */
/*----------------------------------------------------------------*/

#ifdef __MMI_AGPS_OTAP__
static const CHAR *supl_appids[] = { "ULP", "ap0004" };
static const U16 supl_l1symbols[] = {SRV_CCA_NS_OMA_BOOTSTRAP_L1SYMBOL, SRV_CCA_NS_OMA_PROXY, SRV_CCA_NS_OMA_APPLICATION};
#endif /* __MMI_AGPS_OTAP__ */ 

/*----------------------------------------------------------------*/
/* Target Application Configuration                               */
/*----------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Extern API declaration                                                     */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* End                                                                        */
/*----------------------------------------------------------------------------*/


static const srv_cca_app_config_struct cca_app_config_g[] = 
{
    /*
     * {config_id, num_appids, num_l1node_symbols, appids, l1node_symbols, app_check_doc_hdlr, support_sim_prov}
     * 
     * config_id:      Application Config ID, eg, SRV_CCA_CONFIG_DTACCT, SRV_CCA_CONFIG_BROWSER (defined in CentralConfigAgentConst.h)
     * num_appids:     Number of APPIDs listed in appids array
     * num_l1node_symbols:  Number of level 1 node symbols listed in l1node_symbols
     * appids:         Array of strings indicating its APPID value(s)
     * l1node_symbols: Array of CCA Symbols indicating the interested level 1 node symbols
     * app_check_doc_hdlr:  Application callback checking whether it has interests in this document
     * 
     */

    /*----------------------------------------------------------------*/
    /* APP CONFIG: DATA ACCOUNT                                       */
    /*----------------------------------------------------------------*/
//    {SRV_CCA_CONFIG_DTACCT, srv_dtcnt_prov_is_cca_target, NULL, 0, dtacct_l1symbols, 
//     sizeof(dtacct_l1symbols) / sizeof(U16), MMI_FALSE},

    {SRV_CCA_CONFIG_DTACCT, 0, sizeof(dtacct_l1symbols) / sizeof(U16), NULL, dtacct_l1symbols, 
     srv_dtcnt_prov_is_cca_target, MMI_FALSE},

    /*----------------------------------------------------------------*/
    /* APP CONFIG: WLAN                                               */
    /*----------------------------------------------------------------*/
#if 0    
 #if defined(__MMI_WLAN_OTAP_OMAEXT__)
/* under construction !*/
/* under construction !*/
 #elif defined(__MMI_WLAN_OTAP_DMP__)
/* under construction !*/
/* under construction !*/
 #endif 
#endif//0

#if defined(__MMI_WLAN_OTAP_OMAEXT__)
       {SRV_CCA_CONFIG_WLAN, 0, sizeof(wlan_l1symbols) / sizeof(U16), NULL, wlan_l1symbols, 
         srv_dtcnt_prov_wlan_is_cca_target, MMI_FALSE},
#elif defined(__MMI_WLAN_OTAP_DMP__)
       {SRV_CCA_CONFIG_WLAN_DMP,  0, sizeof(wlan_dmp_l1symbols) / sizeof(U16), NULL, wlan_dmp_l1symbols, 
        srv_dtcnt_prov_wlan_is_cca_target, MMI_FALSE},
#endif 

    /*----------------------------------------------------------------*/
    /* APP CONFIG: BROWSER                                            */
    /*----------------------------------------------------------------*/
 #ifdef BROWSER_SUPPORT
//    {SRV_CCA_CONFIG_BROWSER, 0, browser_appids, sizeof(browser_appids) / sizeof(CHAR *), browser_l1symbols,
//     sizeof(browser_l1symbols) / sizeof(U16), MMI_FALSE},

     {SRV_CCA_CONFIG_BROWSER, sizeof(browser_appids) / sizeof(CHAR *), sizeof(browser_l1symbols) / sizeof(U16), 
        browser_appids, browser_l1symbols, NULL, MMI_FALSE},
 #endif /* BROWSER_SUPPORT */ 

    /*----------------------------------------------------------------*/
    /* APP CONFIG: MMS                                                */
    /*----------------------------------------------------------------*/
 #ifdef MMS_SUPPORT
//    {SRV_CCA_CONFIG_MMS, NULL, mms_appids, sizeof(mms_appids) / sizeof(CHAR *), mms_l1symbols,
//     sizeof(mms_l1symbols) / sizeof(U16), MMI_TRUE},

     {SRV_CCA_CONFIG_MMS, sizeof(mms_appids) / sizeof(CHAR *), sizeof(mms_l1symbols) / sizeof(U16), 
        mms_appids, mms_l1symbols, NULL, MMI_TRUE},
 #endif /* MMS_SUPPORT */ 

    /*----------------------------------------------------------------*/
    /* APP CONFIG: SIP                                                */
    /*----------------------------------------------------------------*/
 #ifdef __MMI_VOIP_OTAP_DMP__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
 #endif /* __MMI_VOIP_OTAP_DMP__ */ 

    /*----------------------------------------------------------------*/
    /* APP CONFIG: EMAIL                                              */
    /*----------------------------------------------------------------*/
 #ifdef __MMI_EMAIL_OTAP__
 //   {SRV_CCA_CONFIG_EMAIL, NULL, email_appids, sizeof(email_appids) / sizeof(CHAR *), email_l1symbols,
 //    sizeof(email_l1symbols) / sizeof(U16), MMI_FALSE},

    {SRV_CCA_CONFIG_EMAIL, sizeof(email_appids) / sizeof(CHAR *),sizeof(email_l1symbols) / sizeof(U16),  
        email_appids, email_l1symbols, NULL, MMI_FALSE},

 #endif /* __MMI_EMAIL_OTAP__ */ 

    /*----------------------------------------------------------------*/
    /* APP CONFIG: SyncML-DS                                          */
    /*----------------------------------------------------------------*/
 #ifdef __MMI_SYNCML_CCA_SUPPORT__
//    {SRV_CCA_CONFIG_SYNCMLDS, NULL, syncmlds_appids, sizeof(syncmlds_appids) / sizeof(CHAR *), syncmlds_l1symbols,
//     sizeof(syncmlds_l1symbols) / sizeof(U16), MMI_FALSE},

    {SRV_CCA_CONFIG_SYNCMLDS, sizeof(syncmlds_appids) / sizeof(CHAR *), sizeof(syncmlds_l1symbols) / sizeof(U16), 
        syncmlds_appids, syncmlds_l1symbols, NULL, MMI_FALSE},
 #endif /* __MMI_SYNCML_CCA_SUPPORT__ */ 

    /*----------------------------------------------------------------*/
    /* APP CONFIG: SyncML-DM                                          */
    /*----------------------------------------------------------------*/
 #ifdef SYNCML_DM_SUPPORT
//    {SRV_CCA_CONFIG_SYNCMLDM, NULL, syncmldm_appids, sizeof(syncmldm_appids) / sizeof(CHAR *), syncmldm_l1symbols,
//     sizeof(syncmldm_l1symbols) / sizeof(U16), MMI_FALSE},

    {SRV_CCA_CONFIG_SYNCMLDM, sizeof(syncmldm_appids) / sizeof(CHAR *),  sizeof(syncmldm_l1symbols) / sizeof(U16),
        syncmldm_appids, syncmldm_l1symbols, NULL, MMI_FALSE},

 #endif /* SYNCML_DM_SUPPORT */ 

    /*----------------------------------------------------------------*/
    /* APP CONFIG: IMPS                                               */
    /*----------------------------------------------------------------*/
 #ifdef __MMI_IMPS_OTA__
//    {SRV_CCA_CONFIG_IMPS, NULL, imps_appids, sizeof(imps_appids) / sizeof(CHAR *), imps_l1symbols,
//     sizeof(imps_l1symbols) / sizeof(U16), MMI_FALSE},

    {SRV_CCA_CONFIG_IMPS, sizeof(imps_appids) / sizeof(CHAR *), sizeof(imps_l1symbols) / sizeof(U16), 
        imps_appids, imps_l1symbols, NULL, MMI_FALSE},

 #endif /* __MMI_IMPS_OTA__ */ 

    /*----------------------------------------------------------------*/
    /* APP CONFIG: PUSH                                               */
    /*----------------------------------------------------------------*/
 #ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__
 //   {SRV_CCA_CONFIG_PUSH, NULL, push_appids, sizeof(push_appids) /sizeof(CHAR *), push_l1symbols, 
 //    sizeof(push_l1symbols) / sizeof(U16), MMI_FALSE},

     {SRV_CCA_CONFIG_PUSH, sizeof(push_appids) /sizeof(CHAR *), sizeof(push_l1symbols) / sizeof(U16), 
        push_appids, push_l1symbols, NULL, MMI_FALSE},
 #endif /* __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__ */ 

    /*----------------------------------------------------------------*/
    /* APP CONFIG: RTSP                                               */
    /*----------------------------------------------------------------*/
#ifdef __MMI_STREAMING_OTAP__
//    {SRV_CCA_CONFIG_RTSP, NULL, rtsp_appids, sizeof(rtsp_appids) / sizeof(CHAR *), rtsp_l1symbols,
//     sizeof(rtsp_l1symbols) / sizeof(U16), MMI_FALSE},

    {SRV_CCA_CONFIG_RTSP, sizeof(rtsp_appids) / sizeof(CHAR *), sizeof(rtsp_l1symbols) / sizeof(U16), 
        rtsp_appids, rtsp_l1symbols, NULL, MMI_FALSE},

#endif /* __MMI_STREAMING_OTAP__ */ 

       /*----------------------------------------------------------------*/
       /* APP CONFIG: SUPL                                               */
       /*----------------------------------------------------------------*/
#ifdef __MMI_AGPS_OTAP__
//       {SRV_CCA_CONFIG_SUPL, NULL, supl_appids, sizeof(supl_appids) / sizeof(CHAR *), supl_l1symbols,
//        sizeof(supl_l1symbols) / sizeof(U16), MMI_FALSE},

       {SRV_CCA_CONFIG_SUPL,  sizeof(supl_appids) / sizeof(CHAR *), sizeof(supl_l1symbols) / sizeof(U16), 
         supl_appids, supl_l1symbols, NULL, MMI_FALSE},

#endif /* __MMI_AGPS_OTAP__ */ 
    
    /*----------------------------------------------------------------*/
    /* APP CONFIG: Unknown                                            */
    /*----------------------------------------------------------------*/
    /* please insert above this line */
    {0xFFFF, 0, 0, NULL, NULL, NULL, MMI_FALSE}
};


/*****************************************************************************
 * FUNCTION
 *  srv_cca_get_app_config_info_by_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
const srv_cca_app_config_struct * srv_cca_get_app_config(U32 index)
{
    return &(cca_app_config_g[index]);
}

/*****************************************************************************
 * FUNCTION
 *  srv_cca_get_module_id_by_source
 * DESCRIPTION
 *  get KAL module ID based on CCA's source_id
 * PARAMETERS
 *  source_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
module_type srv_cca_get_module_id_by_source(U16 source_id)
{
#ifdef __SRV_CCA_SLIM__

    return (source_id == SRV_CCA_SOURCE_DM ? MOD_DM : MOD_MMI);

#else /* __SRV_CCA_SLIM__ */
    
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type mod_id = MOD_MMI;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (source_id)
    {
        case SRV_CCA_SOURCE_TEST:
        case SRV_CCA_SOURCE_WAP:
        case SRV_CCA_SOURCE_SPA:
        case SRV_CCA_SOURCE_PROVBOX:
        case SRV_CCA_SOURCE_PROVBOXUI:
            mod_id = MOD_MMI;
            break;

        case SRV_CCA_SOURCE_DM:
            mod_id = MOD_DM;
            break;

        default:
            SRV_CCA_ASSERT(0);
            break;
    }
    return mod_id;

    
#endif /* __SRV_CCA_SLIM__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_get_module_id_by_app
 * DESCRIPTION
 *  get KAL module ID based on CCA's app_id
 * PARAMETERS
 *  app_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
module_type srv_cca_get_module_id_by_app(U16 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MOD_MMI;

#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0

}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_get_module_id_by_config
 * DESCRIPTION
 *  get KAL module ID based on CCA's config_id
 * PARAMETERS
 *  config_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
module_type srv_cca_get_module_id_by_config(U16 config_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_cca_get_module_id_by_app((U16) SRV_CCA_GET_APP(config_id));
}



#endif /* __CCA_SUPPORT__ */ 


