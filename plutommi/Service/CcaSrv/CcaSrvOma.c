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
 *  CentralConfigAgentOma.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  CCA Manipulating OMA Spec Codes
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
 * removed!
 * removed!
 * removed!
 *
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
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_features.h"
#include "MMI_include.h"

#include "stdio.h"
#include "string.h"

#include "kal_general_types.h"
#include "kal_trace.h"
#include "kal_public_api.h"

#include "MMIDataType.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"

#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"


#include "CcaSrvGProt.h"
#include "CcaSrvIProt.h"
#include "CcaSrvConfig.h"
#include "CcaSrvProt.h"

#ifdef __MMI_CCA_SUPPORT__

/*----------------------------------------------------------------------------*/
/* Macro define                                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/
#define CCA_NODE_ID_PREFIX              "@C@"       //"@CCA@"
#define CCA_VIRTUAL_PROXY_ID_PREFIX     "@CP@"      //"@CCA@GEN@"
#define CCA_VIRTUAL_APP_NAME            "Wap profile"
#define CCA_VIRTUAL_PROXY_NAME          "Virtual proxy"
#define CCA_VIRTUAL_PROXY_ADDR          "0.0.0.0"
#define CCA_VIRTUAL_PROXY_PORT          "0"

#define CCA_MAX_REF_BY_ENTRIES          10

/* CCA Node Flag */
#define SRV_CCA_NODE_FLAG_VIRTUAL_PROXY_NODE           0x0001
#define SRV_CCA_NODE_FLAG_VIRTUAL_APPLICATION_NODE     0x0002


/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/


typedef struct cca_oma_deprel_info_struct
{
    struct cca_oma_deprel_info_struct *next;
    S32 hNode;
    CHAR *cca_node_id;
    CHAR *oma_node_id;
    CHAR *oma_ref_id;
} cca_oma_deprel_info_struct;

typedef struct
{
    U16 ref_by_node_symbols[CCA_MAX_REF_BY_ENTRIES];
    S32 ref_by_node_symbols_count;

    S32 ref_by_node_handles[CCA_MAX_REF_BY_ENTRIES];
    S32 ref_by_node_handles_count;

    CHAR *ref_by_appids[CCA_MAX_REF_BY_ENTRIES];
    S32 ref_by_appids_count;
} cca_ref_by_struct;

static U8 cca_oma_memfull_flag = 0;

/*----------------------------------------------------------------------------*/
/* Static API declaration                                                     */
/*----------------------------------------------------------------------------*/
#define SRV_CCA_OMA_API_LIST

/* Utils */
static void srv_cca_oma_handle_memfull(U8 identifier);
static S32 srv_cca_oma_is_node_symbol_exist(U16 symbolToFind, const U16 *l1node_symbols, S32 num_l1node_symbols);
static S32 srv_cca_oma_is_appid_exist(CHAR *appidToFind, const CHAR **appids, S32 numAppIds);

/* Fixed Doc */
static S32 srv_cca_oma_remove_invalid_nodes(S32 hRoot);
static S32 srv_cca_oma_validate_param_values(S32 hNode, U16 param);
static S32 srv_cca_oma_validate_find_id(CHAR **dataarray, S32 count, CHAR *id);
static void srv_cca_oma_validate_add_id(CHAR **dataarray, S32 count, S32 total, CHAR *data);
static void srv_cca_oma_remove_duplicate_port(S32 hParentNode);
static S32 srv_cca_oma_validate_find_node(S32 *dataarray, S32 count, S32 hNode);
static void srv_cca_oma_validate_add_node(S32 *dataarray, S32 count, S32 total, S32 hNode);

#ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__
#ifdef __SRV_CCA_SLIM__
static S32 srv_cca_oma_push_ota_proxy_node_param_check(S32 hRoot, S32 hProxyNode);
#endif
static S32 srv_cca_oma_is_push_ota_private_proxy_node(S32 hRoot, S32 hProxyNode);
static S32 srv_cca_oma_is_push_ota_proxy_node(S32 hRoot, S32 hProxyNode);
#endif /* __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__ */

static S32 srv_cca_oma_adopt_nap_orphan_node(S32 hRoot);
static S32 srv_cca_oma_adopt_proxy_orphan_node(S32 hRoot);

static char *srv_cca_oma_make_virtual_proxy_id(const char *tonapid);
static S32 srv_cca_oma_generate_virtual_application_node(
            const char *app_id,
            const char *to_proxy,
            const char *vrapp_cca_node_id);
#if 0
/* under construction !*/
#endif
static S32 srv_cca_oma_check_node_if_has_node_flag(S32 hNode, S32 node_flag);
static srv_cca_status_enum srv_cca_oma_add_node_flag(S32 hNode, S32 node_flag);

/* Dependency */
static srv_cca_status_enum srv_cca_oma_deprel_populate_ref_ids(
                    cca_oma_deprel_info_struct **listhead,
                    S32 l1node,
                    U16 oma_node_id_symbol,
                    CHAR **oma_ref_ids,
                    S32 size);

static srv_cca_status_enum srv_cca_oma_deprel_populate_lists(
                    S32 deprel,
                    U16 dep_id,
                    cca_oma_deprel_info_struct *list1head,
                    cca_oma_deprel_info_struct *list2head);

static cca_oma_deprel_info_struct *srv_cca_oma_new_deprel_info(void);
static void srv_cca_oma_release_deprel_info(cca_oma_deprel_info_struct *elem);
static void srv_cca_oma_release_deprel_info_list(cca_oma_deprel_info_struct *listhead);
static void srv_cca_oma_attach_deprel_info_to_list(cca_oma_deprel_info_struct **listhead, cca_oma_deprel_info_struct *elem);
static S32 srv_cca_oma_new_deprel_child(U16 dep_id, CHAR *node_id, CHAR *ref_id, S32 hSrcNode);
#if 0
/* under construction !*/
/* under construction !*/
#endif //0

/* Parse Doc */
static S32 srv_cca_oma_check_app_config(srv_cca_cntx_struct *cntx);
static srv_cca_iterator_struct *srv_cca_oma_construct_appcheck_datalist(S32 hConfig);
static srv_cca_status_enum srv_cca_oma_retrieve_all_appids(S32 hConfig, srv_cca_doc_node_datalist_struct *datalist_res);
static srv_cca_status_enum srv_cca_oma_retrieve_nodeids(S32 hConfig, srv_cca_doc_node_datalist_struct *datalist_res);
static srv_cca_status_enum srv_cca_oma_doc_contains_appid(S32 hConfig, const CHAR **appids, S32 numAppIds);

/* Install AP */
static srv_cca_status_enum srv_cca_oma_add_dataacctid_to_ref_nodes(S32 hConfig);
static srv_cca_status_enum srv_cca_oma_mark_application_depset(S32 hConfig, const srv_cca_app_config_struct *crtConfig);
static void srv_cca_oma_mark_referred_depset(srv_cca_doc_node_struct *nodeDepRelBegin, CHAR *nodeIdToMark);
static srv_cca_status_enum srv_cca_oma_mark_in_app_context(srv_cca_inst_struct *inst, S32 hConfig);
static srv_cca_status_enum srv_cca_oma_check_in_app_context(srv_cca_inst_struct *inst, S32 hConfig, srv_cca_doc_node_struct *l1node);
static srv_cca_status_enum srv_cca_oma_is_depset(S32 hConfig, srv_cca_doc_node_struct *l1node);
static srv_cca_status_enum srv_cca_oma_find_proxy_ref_by(
                        S32 hConfig,
                        srv_cca_doc_node_struct *l1node,
                        cca_ref_by_struct *ref_by);
static srv_cca_status_enum srv_cca_oma_get_deprel_childs(S32 hConfig, srv_cca_doc_node_struct **nodeDepRelBegin);
static void srv_cca_oma_mark_reference_depset(srv_cca_doc_node_struct *nodeDepRelBegin, CHAR *refIdToMark);


/*----------------------------------------------------------------------------*/
/* Extern API declaration                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static global variable                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* End                                                                        */
/*----------------------------------------------------------------------------*/
#define SRV_CCA_OMA_UTILS


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_handle_memfull
 * DESCRIPTION
 *  handle memfull scenario
 * PARAMETERS
 *  identifier      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_oma_handle_memfull(U8 identifier)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cca_oma_memfull_flag = 1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_is_memfull_during_app_configure
 * DESCRIPTION
 *  indicate whether memfull occurred during application configuration process
 * PARAMETERS
 *  void
 * RETURNS
 *  0 = false, 1 = memfull
 *****************************************************************************/
S32 srv_cca_oma_is_memfull_during_app_configure(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cca_oma_memfull_flag;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_is_node_symbol_exist
 * DESCRIPTION
 *  check whether the node symbol exists from the app's config setting
 * PARAMETERS
 *  symbolToFind            [IN]        
 *  l1node_symbols          [IN]        
 *  num_l1node_symbols      [IN]        
 * RETURNS
 *  1 if found, 0 otherwise
 *****************************************************************************/
static S32 srv_cca_oma_is_node_symbol_exist(U16 symbolToFind, const U16 *l1node_symbols, S32 num_l1node_symbols)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < num_l1node_symbols; i++)
        if (symbolToFind == l1node_symbols[i])
            return 1;
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_is_appid_exist
 * DESCRIPTION
 *  check whether the app id exists from the app's config setting
 * PARAMETERS
 *  appidToFind     [IN]        
 *  appids          [IN]        
 *  numAppIds       [IN]        
 * RETURNS
 *  1 if found, 0 otherwise
 *****************************************************************************/
static S32 srv_cca_oma_is_appid_exist(CHAR *appidToFind, const CHAR **appids, S32 numAppIds)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < numAppIds; i++)
        if (strcmp(appids[i], appidToFind) == 0)
            return 1;
    return 0;
}






#define SRV_CCA_OMA_FIX_DOC


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_fix_doc
 * DESCRIPTION
 *  API to fix OMA document by
 *  - remove All invalid nodes
 *  - adopt all NAPDEF orphan nodes
 *  - adopt all PROXY orphan nodes
 * PARAMETERS
 *  hRoot       [IN]        
 * RETURNS
 *  0           document unchanged
 *  1           document modified
 *****************************************************************************/
S32 srv_cca_oma_fix_doc(S32 hRoot)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 docChanged = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Firstly to remove all invalid nodes */
    docChanged = srv_cca_oma_remove_invalid_nodes(hRoot);

    /* Secondly, it's time to adopt all orphan node now, 
       How poor children they are, a warm family will be good to them.
       let's adopt the NAPDEF orphan nodes firstly */
    docChanged += srv_cca_oma_adopt_nap_orphan_node(hRoot);

    /* Finally, let's adopt the PROXY orphan nodes */
    docChanged += srv_cca_oma_adopt_proxy_orphan_node(hRoot);

    return docChanged > 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_remove_invalid_nodes
 * DESCRIPTION
 *  API to remove invalid nodes:
 *  - remove NAPDEF with no NAPID or NAPID is empty string("\0")
 *  - remove NAPDEF with duplicated NAPID
 *  - remove PROXY with no PROXY-ID or PROXY-ID is empty string("\0")
 *  - remove PROXY with duplicated PROXY-ID
 *  - remove PROXY with no TO-NAPID or TO-NAPId is empty string("\0")
 *  - remove PROXY with unmatched TO-NAPID
 *  - remove APPLICATION with no APPID or APPId is empty string("\0")
 *  - remove duplicated PORT node in PROXY
 * PARAMETERS
 *  hRoot       [IN]        
 * RETURNS
 *  0           document unchanged
 *  1           document modified
 *****************************************************************************/
static S32 srv_cca_oma_remove_invalid_nodes(S32 hRoot)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *l1node, *next;
    srv_cca_core_data_struct *coredata;
    CHAR *napids[20];
    CHAR *proxyids[20];
    S32 remove;
    S32 docChanged = 0;
    S32 i, napidcount, proxyidcount;
    S32 napdef;
#ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__
    U8 recheck_push_ota;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hRoot || !(((srv_cca_doc_node_struct*) hRoot)->num_child))
        return 0;

    napidcount = 0;
    proxyidcount = 0;
    memset(napids, 0, 20 * sizeof(CHAR*));
    memset(proxyids, 0, 20 * sizeof(CHAR*));
    l1node = ((srv_cca_doc_node_struct*) hRoot)->child;
    while (l1node)
    {
        remove = 0;
        coredata = 0;
    #ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__
        recheck_push_ota = 0;
    #endif
        switch (l1node->node_id)
        {
            case SRV_CCA_NS_OMA_NAPDEF:
                /* remove NAPDEF with no NAPID or empty NAPID */
                if (!srv_cca_oma_validate_param_values((S32) l1node, SRV_CCA_NS_OMA_NAPID))
                {
                    remove = 1;
                    break;
                }

                /* remove NAPDEF with duplicated NAPID */
                srv_cca_doc_nodedata_by_param((S32) l1node, SRV_CCA_NS_OMA_NAPID, &coredata);
                if (!srv_cca_oma_validate_find_id((CHAR **) napids, napidcount, coredata->values.s[0]))
                {
                    srv_cca_oma_validate_add_id((CHAR **) napids, napidcount++, 20, coredata->values.s[0]);
                }
                else
                {
                    remove = 1;
                    break;
                }
                break;

            case SRV_CCA_NS_OMA_PROXY:
            #ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__
                if (srv_cca_oma_is_virtual_proxy((S32) l1node) &&
                    srv_cca_oma_is_push_ota_private_proxy_node(hRoot, (S32) l1node))
                {
                    /* not remove the TO-PROXY in its application node and it's ok */
                    remove = 1;
                    break;
                }

            #endif /* __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__ */
            
                /* remove PROXY with no PROXY-ID or empty PROXY-ID or with no TO-NAPID or empty TO-NAPID */
                if (!srv_cca_oma_validate_param_values((S32) l1node, SRV_CCA_NS_OMA_PROXY_ID) ||
                    !srv_cca_oma_validate_param_values((S32) l1node, SRV_CCA_NS_OMA_TO_NAPID))
                {
                    remove = 1;
                #ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__
                    recheck_push_ota = 1;
                #endif
                    break;
                }

                /* remove PROXY with unmatched TO-NAPID */
                srv_cca_doc_nodedata_by_param((S32) l1node, SRV_CCA_NS_OMA_TO_NAPID, &coredata);
                for (i = 0; i < coredata->size; i++)
                {
                    napdef = srv_cca_doc_find_node_match_param_value(
                                (S32) ((srv_cca_doc_node_struct*) hRoot)->child,
                                SRV_CCA_NS_OMA_NAPDEF,
                                SRV_CCA_NS_OMA_NAPID,
                                SRV_CCA_DATA_TYPE_STR,
                                (void*)coredata->values.s[i]);
                    if (!napdef &&
                        srv_cca_doc_coredata_remove_value(coredata, SRV_CCA_DATA_TYPE_STR, (void*)coredata->values.s[i]))
                    {
                        i--;
                    }
                }
                if (!(coredata->size))
                {
                    remove = 1;
                #ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__
                    recheck_push_ota = 1;
                #endif
                    break;
                }

                /* remove PROXY with duplicated PROXY-ID */
                srv_cca_doc_nodedata_by_param((S32) l1node, SRV_CCA_NS_OMA_PROXY_ID, &coredata);
                if (!srv_cca_oma_validate_find_id((CHAR **) proxyids, proxyidcount, coredata->values.s[0]))
                {
                    srv_cca_oma_validate_add_id((CHAR **) proxyids, proxyidcount++, 20, coredata->values.s[0]);
                }
                else
                {
                    remove = 1;
                    break;
                }

                /* remove duplicated PORT node in PROXY */
                srv_cca_oma_remove_duplicate_port((S32) l1node);
                break;

            case SRV_CCA_NS_OMA_APPLICATION:
                /* remove APPLICATION with no APPID or empty APPID */
                if (!srv_cca_oma_validate_param_values((S32) l1node, SRV_CCA_NS_OMA_APPID))
                {
                    remove = 1;
                    break;
                }
                break;
        }

        next = l1node->next;
        if (remove)
        {
        #ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__
            if (recheck_push_ota)
                remove = !srv_cca_oma_is_push_ota_proxy_node(hRoot, (S32) l1node);
        #endif /* __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__ */ 

            if (remove)
            {
                srv_cca_doc_node_free((S32) l1node);
                docChanged = 1;
            }
        }
        l1node = next;
    }

    return docChanged;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_validate_param_values
 * DESCRIPTION
 *  helper function to check if the values of the specified parameter are valid
 *  if value is NULL or value is "\0", remove it, so do not use this api to remove
 *  those valid param without values, such as STARTPAGE parameter.
 * PARAMETERS
 *  hNode       [IN]        
 *  param       [IN]        
 * RETURNS
 *  0           no valid value
 *  1           all values are valid
 *****************************************************************************/
static S32 srv_cca_oma_validate_param_values(S32 hNode, U16 param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_core_data_struct *coredata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_cca_doc_nodedata_by_param(hNode, param, &coredata) == SRV_CCA_STATUS_NOT_FOUND)
        return 0;
    else if (!coredata || !(coredata->size) || !(coredata->values.s))
        return 0;
    else if (srv_cca_doc_coredata_remove_value(coredata, SRV_CCA_DATA_TYPE_STR, 0) && !(coredata->size))
        return 0;
    else if (srv_cca_doc_coredata_remove_value(coredata, SRV_CCA_DATA_TYPE_STR, "\0") && !(coredata->size))
        return 0;
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_validate_find_id
 * DESCRIPTION
 *  helper function to check whether the value can be found in array
 * PARAMETERS
 *  dataarray       [IN]        
 *  count           [IN]        
 *  id              [IN]        
 * RETURNS
 *  0 if not found
 *  1 if found
 *****************************************************************************/
static S32 srv_cca_oma_validate_find_id(CHAR **dataarray, S32 count, CHAR *id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < count; i++)
    {
        if (strcmp(dataarray[i], id) == 0)
            return 1;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_validate_add_id
 * DESCRIPTION
 *  helper function to add a value to predefined array
 * PARAMETERS
 *  dataarray       [IN]        
 *  count           [IN]        
 *  total           [IN]        
 *  data            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_oma_validate_add_id(CHAR **dataarray, S32 count, S32 total, CHAR *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (count >= total)
    {
        MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_OMA_VALIDATE_ADD_ID, count, total);
        return;
    }

    dataarray[count] = data;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_remove_duplicate_port
 * DESCRIPTION
 *  helper function to check and remove duplicated PORT node within the specified parent node
 * PARAMETERS
 *  hParentNode     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_oma_remove_duplicate_port(S32 hParentNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *child;
    srv_cca_doc_node_struct *next;
    S32 portnodes[20];
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hParentNode)
        return;

    memset(portnodes, 0, 20 * sizeof(S32));
    child = ((srv_cca_doc_node_struct*) hParentNode)->child;
    while (child)
    {
        if (child->node_id == SRV_CCA_NS_OMA_PORT)
        {
            if (srv_cca_oma_validate_find_node((S32*) portnodes, count, (S32) child))
            {
                next = child->next;
                srv_cca_doc_node_free((S32) child);
                child = next;
                continue;
            }
            else
            {
                srv_cca_oma_validate_add_node((S32*) portnodes, count++, 20, (S32) child);
            }
        }
        child = child->next;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_validate_find_node
 * DESCRIPTION
 *  helper function to check whether the given node contains duplicated data to those stored in array
 * PARAMETERS
 *  dataarray       [IN]        
 *  count           [IN]        
 *  hNode           [IN]        
 * RETURNS
 *  0 if not found
 *  1 if found
 *****************************************************************************/
static S32 srv_cca_oma_validate_find_node(S32 *dataarray, S32 count, S32 hNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < count; i++)
    {
        if (srv_cca_doc_node_check_equal_content(dataarray[i], hNode))
            return 1;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_validate_add_node
 * DESCRIPTION
 *  helper function to add a node to predefined array
 * PARAMETERS
 *  dataarray       [IN]        
 *  count           [IN]        
 *  total           [IN]        
 *  hNode           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_oma_validate_add_node(S32 *dataarray, S32 count, S32 total, S32 hNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (count >= total)
    {
        MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_OMA_VALIDATE_ADD_NODE, count, total);
        return;
    }

    dataarray[count] = hNode;
}


#ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__


#ifdef __SRV_CCA_SLIM__
static S32 srv_cca_oma_push_ota_proxy_node_param_check(S32 hRoot, S32 hProxyNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *proxyid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    if (!hRoot || !hProxyNode)
        return 0;
    if (((srv_cca_doc_node_struct*) hProxyNode)->node_id != SRV_CCA_NS_OMA_PROXY)
        return 0;

    /* get PROXY ID */
    if (srv_cca_doc_nodedata_str_first(hProxyNode, SRV_CCA_NS_OMA_PROXY_ID, &proxyid) != SRV_CCA_STATUS_OK)
        return 0;

    if (!proxyid || proxyid[0] == '\0')
        return 0;

    return 1;
}
#endif /* __SRV_CCA_SLIM__ */

/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_is_push_ota_private_proxy_node
 * DESCRIPTION
 *  check if a PROXY node is only referenced by Push OTA App node
 *  hNode=input PROXY node to be checked if associated with push ota app node
 *  return 0=proxy node is NOT associated with push ota,
 *  1= only associated with push ota app node
 * PARAMETERS
 *  hRoot           [IN]        
 *  hProxyNode      [IN]        
 * RETURNS
 *  0           not only be referred by Push application node
 *  1           only be referred by Push application node
 *****************************************************************************/
static S32 srv_cca_oma_is_push_ota_private_proxy_node(S32 hRoot, S32 hProxyNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *l1node = ((srv_cca_doc_node_struct*) hRoot)->child;
    CHAR *proxyid = 0;
    S32 startNode;
    S32 find_app = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_CCA_SLIM__

    if (!srv_cca_oma_push_ota_proxy_node_param_check(hRoot, hProxyNode))
        return 0;
    
#else /* __SRV_CCA_SLIM__ */
    
    if (!hRoot || !hProxyNode)
        return 0;
    
    if (((srv_cca_doc_node_struct*) hProxyNode)->node_id != SRV_CCA_NS_OMA_PROXY)
        return 0;

    /* get PROXY ID */
    if (srv_cca_doc_nodedata_str_first(hProxyNode, SRV_CCA_NS_OMA_PROXY_ID, &proxyid) != SRV_CCA_STATUS_OK)
        return 0;

    if (!proxyid || proxyid[0] == '\0')
        return 0;

#endif /* __SRV_CCA_SLIM__ */

    /* for each push OTA app node */
    startNode = (S32) l1node;
    while (1)
    {
        startNode = srv_cca_doc_find_node_match_param_value(startNode, SRV_CCA_NS_OMA_APPLICATION, SRV_CCA_NS_OMA_TO_PROXY, SRV_CCA_DATA_TYPE_STR, (void*)proxyid);       /* WARNING: only the first PROXYID is checked! */

        if (!startNode)
            break;

        /* check whether PROXY ID could be found in app node's TO-PROXY */
        if (!srv_cca_doc_node_has_param_value
            ((S32) startNode, SRV_CCA_NS_OMA_APPID, SRV_CCA_DATA_TYPE_STR, (void*)"oma:mo:oma-push:1.0"))
            return 0;
        /* find a push application node who use this proxy node particularly */
        find_app++;

        startNode = (S32) (((srv_cca_doc_node_struct*) startNode)->next);
        if (!startNode)
            break;
    }
    if (find_app)
        return 1;
    else
        return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_is_push_ota_proxy_node
 * DESCRIPTION
 *  check if PROXY node is referenced by Push OTA App node
 *  hNode=input PROXY node to be checked if associated with push ota app node
 *  return 0=proxy node is NOT associated with push ota, 1=associated with push ota app node
 * PARAMETERS
 *  hRoot           [IN]        
 *  hProxyNode      [IN]        
 * RETURNS
 *  0           not be referred by Push application node
 *  1           is referred by Push application node
 *****************************************************************************/
static S32 srv_cca_oma_is_push_ota_proxy_node(S32 hRoot, S32 hProxyNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 config_idx = 0;
    CHAR *proxyid = 0;
    S32 startNode;
    srv_cca_doc_node_struct *l1node = ((srv_cca_doc_node_struct*) hRoot)->child;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_CCA_SLIM__
    
        if (!srv_cca_oma_push_ota_proxy_node_param_check(hRoot, hProxyNode))
            return 0;
        
#else /* __SRV_CCA_SLIM__ */

    if (!hRoot || !hProxyNode)
        return 0;

    if (((srv_cca_doc_node_struct*) hProxyNode)->node_id != SRV_CCA_NS_OMA_PROXY)
        return 0;

    /* get PROXY ID */
    if (srv_cca_doc_nodedata_str_first(hProxyNode, SRV_CCA_NS_OMA_PROXY_ID, &proxyid) != SRV_CCA_STATUS_OK)
        return 0;

    if (!proxyid || proxyid[0] == '\0')
        return 0;

#endif /* __SRV_CCA_SLIM__ */


    /* find Push OTA App config */
    while (srv_cca_get_app_config(config_idx)->config_id != 0xFFFF &&
           srv_cca_get_app_config(config_idx)->config_id != SRV_CCA_CONFIG_PUSH)
    {
        config_idx++;
    }
    if (srv_cca_get_app_config(config_idx)->config_id == 0xFFFF)
        return 0;

    /* for each push OTA app node */
    startNode = (S32) l1node;
    while (1)
    {
        startNode = srv_cca_doc_find_node_match_param_value(startNode, 
            SRV_CCA_NS_OMA_APPLICATION, SRV_CCA_NS_OMA_APPID, SRV_CCA_DATA_TYPE_STR, 
            (void*)srv_cca_get_app_config(config_idx)->appids[0]);   /* WARNING: only the first appid is checked! */

        if (!startNode)
            break;

        /* check whether PROXY ID could be found in app node's TO-PROXY */
        if (srv_cca_doc_node_has_param_value((S32) startNode, SRV_CCA_NS_OMA_TO_PROXY, SRV_CCA_DATA_TYPE_STR, (void*)proxyid))
            return 1;
        startNode = (S32) (((srv_cca_doc_node_struct*) startNode)->next);
        if (!startNode)
            break;
    }
    return 0;
}


#endif /* __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_adopt_nap_orphan_node
 * DESCRIPTION
 *  we will treat an isolated NAPDEF node or PROXY node as an browser provisioning setting.
 *  this API is used to handle a NAPDEF node which is not referred in all other nodes,
 *  such as application nodes and proxy nodes, if so, we treat this node as
 *  an orphan node, and we should generate a virtual proxy node to refer to it.
 *  this API should be called before srv_cca_oma_adopt_proxy_orphan_node to adopt all
 *  PROXY node because the proxy nodes generated in this step are orphan nodes too,
 *  and they should be adopted by an application node.
 *  please note, each NAPDEF node should be adopted by an isolated proxy node,
 *  but all PROXY nodes can be adopted by an isolated application node.
 * PARAMETERS
 *  hRoot       [IN]        
 * RETURNS
 *  0           document unchanged
 *  1           document modified
 *****************************************************************************/
static S32 srv_cca_oma_adopt_nap_orphan_node(S32 hRoot)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *next;
    srv_cca_doc_node_struct *l1node;
    srv_cca_core_data_struct *coredata;
    S32 match_node;
    CHAR*new_proxy_id;
    S32 virtual_proxy;
    U8 docChanged = 0;
    CHAR *virtual_node_id;
    S32 value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hRoot || !(((srv_cca_doc_node_struct*) hRoot)->num_child))
        return 0;

    l1node = ((srv_cca_doc_node_struct*) hRoot)->child;
    while (l1node)
    {
        coredata = NULL;
        switch (l1node->node_id)
        {
            case SRV_CCA_NS_OMA_NAPDEF:
                srv_cca_doc_nodedata_by_param((S32) l1node, SRV_CCA_NS_OMA_NAPID, &coredata);

                /* check if there are any proxy nodes which refer to this NAPDEF node */
                match_node = srv_cca_doc_find_node_match_param_value(
                                (S32) ((srv_cca_doc_node_struct*) hRoot)->child,
                                SRV_CCA_NS_OMA_PROXY,
                                SRV_CCA_NS_OMA_TO_NAPID,
                                SRV_CCA_DATA_TYPE_STR,
                                (void*)coredata->values.s[0]);
                if (match_node)
                    break;

                /* check if there are any application node which refers to this NAPDEF node */
                match_node = srv_cca_doc_find_node_match_param_value(
                                (S32) ((srv_cca_doc_node_struct*) hRoot)->child,
                                SRV_CCA_NS_OMA_APPLICATION,
                                SRV_CCA_NS_OMA_TO_NAPID,
                                SRV_CCA_DATA_TYPE_STR,
                                (void*)coredata->values.s[0]);
                if (match_node)
                    break;

                if (SRV_CCA_STATUS_OK == srv_cca_doc_nodedata_int_first((S32) l1node, SRV_CCA_NS_OMA_BEARER, &value))
                {
                    /* Browser only support GPRS/CSD/WLAN bearer, if not, do not treat it as browser profile */
                    if (value != SRV_CCA_NS_VAL_GSM_GPRS && value != SRV_CCA_NS_VAL_GSM_CSD && value != SRV_CCA_NS_VAL_WLAN)
                        break;
                }
                else
                {
                    /* there is no bearer type */
                    break;
                }

                /* Unluckily, it's an orphan and need to be adopted, poor baby it is ! */
                virtual_node_id = srv_cca_oma_make_new_node_id();
                if (!virtual_node_id)
                    break;
                virtual_proxy = srv_cca_oma_generate_virtual_proxy_node(
                                    (const char*)coredata->values.s[0],
                                    (const char*)virtual_node_id,
                                    &new_proxy_id);
                srv_cca_mfree(virtual_node_id);
                if (!virtual_proxy)
                    break;
                srv_cca_doc_node_attach(virtual_proxy, hRoot);
                docChanged = 1;
                break;

            default:
                break;
        }
        next = l1node->next;
        l1node = next;
    }
    return docChanged;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_adopt_proxy_orphan_node
 * DESCRIPTION
 *  we will treat an isolated NAPDEF node or PROXY node as an browser provisioning.
 *  this API is used to handle a PROXY node which is not referred in all other nodes,
 *  such as application nodes, if so, we treat this node as an orphan node,
 *  and we should generate a virtual application node to refer to it.
 *  this API should be called after srv_cca_oma_adopt_nap_orphan_node to adopt all
 *  NAPDEF node because the proxy nodes generated in this API are orphan nodes too,
 *  and they should be adopted by an application node in this step.
 *  please note, every NAPDEF node should be adopted by an isolated proxy node,
 *  but all PROXY nodes can be adopted by an isolated application node.
 * PARAMETERS
 *  hRoot       [IN]        
 * RETURNS
 *  0           document unchanged
 *  1           document modified
 *****************************************************************************/
static S32 srv_cca_oma_adopt_proxy_orphan_node(S32 hRoot)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *next;
    srv_cca_doc_node_struct *l1node;
    srv_cca_core_data_struct *coredata;
    S32 match_app;
    U8 docChanged = 0;
    S32 virtual_app = 0;
    CHAR *virtual_node_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hRoot || !(((srv_cca_doc_node_struct*) hRoot)->num_child))
        return 0;

    l1node = ((srv_cca_doc_node_struct*) hRoot)->child;
    while (l1node)
    {
        coredata = NULL;
        switch (l1node->node_id)
        {
            case SRV_CCA_NS_OMA_PROXY:
                srv_cca_doc_nodedata_by_param((S32) l1node, SRV_CCA_NS_OMA_PROXY_ID, &coredata);

                /* check if there are any application nodes which refer to this proxy node */
                match_app = srv_cca_doc_find_node_match_param_value(
                                (S32) ((srv_cca_doc_node_struct*) hRoot)->child,
                                SRV_CCA_NS_OMA_APPLICATION,
                                SRV_CCA_NS_OMA_TO_PROXY,
                                SRV_CCA_DATA_TYPE_STR,
                                (void*)coredata->values.s[0]);
                if (match_app)
                    break;

                /*
                 * Unluckily, it's an orphan and need to be adopted, poor baby it is ! 
                 * * oh, dear, one application node can adopt all orphans, a big family for them,
                 * * wish a happen childhood!
                 */
                if (!virtual_app)
                {
                    virtual_node_id = srv_cca_oma_make_new_node_id();
                    if (!virtual_node_id)
                        break;
                    virtual_app = srv_cca_oma_generate_virtual_application_node(
                                    "w2",
                                    (const char*)coredata->values.s[0],
                                    (const char*)virtual_node_id);
                    srv_cca_mfree(virtual_node_id);
                    if (!virtual_app)
                        break;
                    srv_cca_doc_node_attach(virtual_app, hRoot);
                }
                else
                {
                    srv_cca_doc_nodedata_add_str(virtual_app, SRV_CCA_NS_OMA_TO_PROXY, (const CHAR*)coredata->values.s[0]);
                }
                docChanged = 1;
                break;

            default:
                break;
        }
        next = l1node->next;
        l1node = next;
    }
    return docChanged;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_make_new_node_id
 * DESCRIPTION
 *  API to generate a new node id for a CCA node
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
char *srv_cca_oma_make_new_node_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR nodeid[20];
    CHAR *new_nodeid;
    CHAR idPrefix[] = CCA_NODE_ID_PREFIX;
    static U16 cca_nodeid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cca_nodeid++;
    sprintf(nodeid, "%d", cca_nodeid);
    new_nodeid = srv_cca_malloc(sizeof(CHAR) * (strlen(idPrefix) + strlen(nodeid) + 1));
    if(!new_nodeid)
        return NULL;
    strcpy(new_nodeid, idPrefix);
    strcat(new_nodeid, nodeid);
    return new_nodeid;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_make_virtual_proxy_id
 * DESCRIPTION
 *  API to generate a PROXY ID for the Virtual Proxy based on the original TO-NAPID
 * PARAMETERS
 *  tonapid     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static char *srv_cca_oma_make_virtual_proxy_id(const char *tonapid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *newProxyID;
    CHAR idPrefix[] = CCA_VIRTUAL_PROXY_ID_PREFIX;
    int prefix_len, tonapid_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prefix_len = strlen(idPrefix);
    tonapid_len = strlen(tonapid);

    newProxyID = (CHAR*) srv_cca_malloc(sizeof(CHAR) * (prefix_len + tonapid_len + 1));
    if (!newProxyID)
        return NULL;
    memset(newProxyID, 0, sizeof(CHAR) * (prefix_len + tonapid_len + 1));
    memcpy(newProxyID, idPrefix, prefix_len);
    memcpy(newProxyID + strlen(idPrefix), tonapid, tonapid_len);

    return newProxyID;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_free_id
 * DESCRIPTION
 *  API to free a new node id or proxy id for a CCA node
 * PARAMETERS
 *  cca_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_oma_free_id(char *cca_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cca_id)
        srv_cca_mfree(cca_id);
}

/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_generate_virtual_proxy_node
 * DESCRIPTION
 *  API to generate a virtual proxy node
 *  caller must NOT release the memory returned in "out_new_pxy_id"
 *  ie, caller must copy the data in "out_new_pxy_id" if it wishes to use it
 * PARAMETERS
 *  tonapid                 [IN]        
 *  vrpxy_cca_node_id       [IN]        
 *  out_new_pxy_id          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_cca_oma_generate_virtual_proxy_node(const char *tonapid, const char *vrpxy_cca_node_id, char **out_new_pxy_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 vrProxy = 0;
    S32 hNodePort = 0;
    CHAR *newProxyID = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (out_new_pxy_id)
        *out_new_pxy_id = 0;

    if ((vrProxy = srv_cca_doc_node_new(SRV_CCA_NS_OMA_PROXY)) == 0)
        return 0;

    /* add CCA NODE_ID */
    if (srv_cca_doc_nodedata_add_str(vrProxy, SRV_CCA_NS_NODEID, vrpxy_cca_node_id) == SRV_CCA_STATUS_MEMFULL)
        return 0;

    /* add PROXY-ID */
    newProxyID = (CHAR*) srv_cca_oma_make_virtual_proxy_id(tonapid);
    if(!newProxyID)
        goto virtual_proxy_error;
    if (srv_cca_doc_nodedata_add_str(vrProxy, SRV_CCA_NS_OMA_PROXY_ID, newProxyID) == SRV_CCA_STATUS_MEMFULL)
        goto virtual_proxy_error;
    srv_cca_mfree(newProxyID);
    newProxyID = 0;

    /* add NAME */
    if (srv_cca_doc_nodedata_add_str(vrProxy, SRV_CCA_NS_OMA_NAME, CCA_VIRTUAL_PROXY_NAME) == SRV_CCA_STATUS_MEMFULL)
        goto virtual_proxy_error;

    /* add PXADDR */
    if (srv_cca_doc_nodedata_add_str(vrProxy, SRV_CCA_NS_OMA_PXADDR, CCA_VIRTUAL_PROXY_ADDR) == SRV_CCA_STATUS_MEMFULL)
        goto virtual_proxy_error;

    /* add PXADDR-TYPE */
    if (srv_cca_doc_nodedata_add_int(vrProxy, SRV_CCA_NS_OMA_PXADDRTYPE, SRV_CCA_NS_VAL_IPV4) == SRV_CCA_STATUS_MEMFULL)
        goto virtual_proxy_error;

    /* add TO-NAPID */
    if (srv_cca_doc_nodedata_add_str(vrProxy, SRV_CCA_NS_OMA_TO_NAPID, (const CHAR*)tonapid) == SRV_CCA_STATUS_MEMFULL)
        goto virtual_proxy_error;

    /* add PORT */
    if ((hNodePort = srv_cca_doc_node_new_and_attach(SRV_CCA_NS_OMA_PORT, vrProxy)) == 0)
        goto virtual_proxy_error;
    if (srv_cca_doc_nodedata_add_str(hNodePort, SRV_CCA_NS_OMA_PORTNBR, CCA_VIRTUAL_PROXY_PORT) == SRV_CCA_STATUS_MEMFULL)
        goto virtual_proxy_error;
    if (srv_cca_doc_nodedata_add_int(hNodePort, SRV_CCA_NS_OMA_SERVICE, SRV_CCA_NS_VAL_OTA_HTTP_TO) == SRV_CCA_STATUS_MEMFULL)
        goto virtual_proxy_error;

    /* add node flag */
    if (SRV_CCA_STATUS_OK != srv_cca_oma_add_node_flag(vrProxy, SRV_CCA_NODE_FLAG_VIRTUAL_PROXY_NODE))
        goto virtual_proxy_error;

    if (out_new_pxy_id)
        srv_cca_doc_nodedata_str_first(vrProxy, SRV_CCA_NS_OMA_PROXY_ID, (CHAR **) out_new_pxy_id);

    return vrProxy;

  virtual_proxy_error:
    if (newProxyID)
        srv_cca_mfree(newProxyID);
    if (vrProxy)
        srv_cca_doc_node_free(vrProxy);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_generate_virtual_application_node
 * DESCRIPTION
 *  API to generate a virtual application node
 * PARAMETERS
 *  app_id                  [IN]        
 *  to_proxy                [IN]        
 *  vrapp_cca_node_id       [IN]        
 * RETURNS
 *  new application node
 *****************************************************************************/
static S32 srv_cca_oma_generate_virtual_application_node(
        const char *app_id,
        const char *to_proxy,
        const char *vrapp_cca_node_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 vrApp = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (app_id == NULL || app_id[0] == 0)
        return 0;
    if (to_proxy == NULL || to_proxy[0] == 0)
        return 0;
    if (vrapp_cca_node_id == NULL || vrapp_cca_node_id[0] == 0)
        return 0;

    if ((vrApp = srv_cca_doc_node_new(SRV_CCA_NS_OMA_APPLICATION)) == 0)
        return 0;

    /* add CCA NODE_ID */
    if (srv_cca_doc_nodedata_add_str(vrApp, SRV_CCA_NS_NODEID, vrapp_cca_node_id) == SRV_CCA_STATUS_MEMFULL)
        goto virtual_app_error;

    /* add APP-ID */
    if (srv_cca_doc_nodedata_add_str(vrApp, SRV_CCA_NS_OMA_APPID, app_id) == SRV_CCA_STATUS_MEMFULL)
        goto virtual_app_error;

    /* add NAME */
    if (srv_cca_doc_nodedata_add_str(vrApp, SRV_CCA_NS_OMA_NAME, CCA_VIRTUAL_APP_NAME) == SRV_CCA_STATUS_MEMFULL)
        goto virtual_app_error;

    /* add TO-PROXY */
    if (srv_cca_doc_nodedata_add_str(vrApp, SRV_CCA_NS_OMA_TO_PROXY, (const CHAR*)to_proxy) == SRV_CCA_STATUS_MEMFULL)
        goto virtual_app_error;

    /* add node flag */
    if (SRV_CCA_STATUS_OK != srv_cca_oma_add_node_flag(vrApp, SRV_CCA_NODE_FLAG_VIRTUAL_APPLICATION_NODE))
        goto virtual_app_error;

    return vrApp;

  virtual_app_error:
    if (vrApp)
        srv_cca_doc_node_free(vrApp);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_is_virtual_proxy
 * DESCRIPTION
 *  to check if a node is a virtual proxy node
 * PARAMETERS
 *  hProxy      [IN]        
 * RETURNS
 *  0: false; 1: true
 *****************************************************************************/
MMI_BOOL srv_cca_oma_is_virtual_proxy(S32 hProxy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_cca_oma_check_node_if_has_node_flag(hProxy, SRV_CCA_NODE_FLAG_VIRTUAL_PROXY_NODE))
        return MMI_TRUE;
    else
        return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_is_virtual_application
 * DESCRIPTION
 *  to check if a node is a virtual application node
 * PARAMETERS
 *  hApp        [IN]        
 * RETURNS
 *  0: false; 1: true
 *****************************************************************************/
MMI_BOOL srv_cca_oma_is_virtual_application(S32 hApp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_cca_oma_check_node_if_has_node_flag(hApp, SRV_CCA_NODE_FLAG_VIRTUAL_APPLICATION_NODE))
        return MMI_TRUE;
    else
        return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_check_node_if_has_node_flag
 * DESCRIPTION
 *  to check if a node has a node flag
 * PARAMETERS
 *  hNode           [IN]        
 *  node_flag       [IN]        
 * RETURNS
 *  0: false; 1: true
 *****************************************************************************/
static S32 srv_cca_oma_check_node_if_has_node_flag(S32 hNode, S32 node_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 value = 0;
    srv_cca_status_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hNode)
        return 0;

    result = srv_cca_doc_nodedata_int_first(hNode, SRV_CCA_NS_NODEFLAG, &value);
    if (result == SRV_CCA_STATUS_OK)
    {
        if (value & node_flag)
            return 1;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_add_node_flag
 * DESCRIPTION
 *  add node flag to a node
 * PARAMETERS
 *  hNode           [IN]        
 *  node_flag       [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_OK: success; other: fail
 *****************************************************************************/
static srv_cca_status_enum srv_cca_oma_add_node_flag(S32 hNode, S32 node_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 *values;
    S32 size;
    srv_cca_status_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hNode)
        return SRV_CCA_STATUS_FAIL;

    result = srv_cca_doc_nodedata_ints(hNode, SRV_CCA_NS_NODEFLAG, &values, &size);
    if (result == SRV_CCA_STATUS_NOT_FOUND)
    {
        return srv_cca_doc_nodedata_add_int(hNode, SRV_CCA_NS_NODEFLAG, node_flag);
    }
    else if (result == SRV_CCA_STATUS_OK)
    {
        values[0] |= node_flag;
        return srv_cca_doc_update_nodedata_ints(hNode, SRV_CCA_NS_NODEFLAG, size, (const S32*)values);
    }
    return result;
}



#define SRV_CCA_OMA_GEN_DEPREF
/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_generate_deprel_node
 * DESCRIPTION
 *  API to generate dependency relationship node given the document ROOT node
 *  this API would only consider the dependency relationship between:
 *  PROXY->NAPDEF
 *  APPLICATION->PROXY
 * PARAMETERS
 *  hRoot       [IN]        
 * RETURNS
 *  0           invalid hRoot / memory full
 *****************************************************************************/
S32 srv_cca_oma_generate_deprel_node(S32 hRoot)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 deprel = 0;
    srv_cca_doc_node_struct *l1node;
    cca_oma_deprel_info_struct *pxylist = 0;
    cca_oma_deprel_info_struct *naplist = 0;
    cca_oma_deprel_info_struct *applist = 0;
    CHAR **values;
    S32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hRoot)
        return 0;

    deprel = srv_cca_doc_node_new(SRV_CCA_NS_DEPREL);
    if (!deprel)
        return 0;

    l1node = ((srv_cca_doc_node_struct*) hRoot)->child;
    if (!l1node)
        return deprel;

    while (l1node)
    {
        if (l1node->node_id == SRV_CCA_NS_OMA_PROXY &&
            srv_cca_doc_nodedata_strs((S32) l1node, SRV_CCA_NS_OMA_TO_NAPID, &values, &size) == SRV_CCA_STATUS_OK)
        {
            if (srv_cca_oma_deprel_populate_ref_ids(&pxylist, (S32) l1node, SRV_CCA_NS_OMA_PROXY_ID, values, size) ==
                SRV_CCA_STATUS_MEMFULL)
                goto srv_cca_oma_new_deprel_child_error;
        }
        else if (l1node->node_id == SRV_CCA_NS_OMA_APPLICATION &&
                 srv_cca_doc_nodedata_strs((S32) l1node, SRV_CCA_NS_OMA_TO_PROXY, &values, &size) == SRV_CCA_STATUS_OK)
        {
            if (srv_cca_oma_deprel_populate_ref_ids(&applist, (S32) l1node, SRV_CCA_NS__NULL, values, size) ==
                SRV_CCA_STATUS_MEMFULL)
                goto srv_cca_oma_new_deprel_child_error;
        }
        else if (l1node->node_id == SRV_CCA_NS_OMA_NAPDEF)
        {
            if (srv_cca_oma_deprel_populate_ref_ids(&naplist, (S32) l1node, SRV_CCA_NS_OMA_NAPID, 0, 0) ==
                SRV_CCA_STATUS_MEMFULL)
                goto srv_cca_oma_new_deprel_child_error;
        }
        l1node = l1node->next;
    }
    if (srv_cca_oma_deprel_populate_lists(deprel, SRV_CCA_NS_DEP_PROXY, pxylist, naplist) == SRV_CCA_STATUS_MEMFULL)
        goto srv_cca_oma_new_deprel_child_error;
    if (srv_cca_oma_deprel_populate_lists(deprel, SRV_CCA_NS_DEP_APPLICATION, applist, pxylist) == SRV_CCA_STATUS_MEMFULL)
        goto srv_cca_oma_new_deprel_child_error;

    srv_cca_oma_release_deprel_info_list(pxylist);
    srv_cca_oma_release_deprel_info_list(naplist);
    srv_cca_oma_release_deprel_info_list(applist);
    return deprel;

  srv_cca_oma_new_deprel_child_error:
    srv_cca_doc_node_free(deprel);
    srv_cca_oma_release_deprel_info_list(pxylist);
    srv_cca_oma_release_deprel_info_list(naplist);
    srv_cca_oma_release_deprel_info_list(applist);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_deprel_populate_ref_ids
 * DESCRIPTION
 *  helper function to add deprel info data to list from multiple ref_ids
 * PARAMETERS
 *  listhead                [IN]        
 *  l1node                  [IN]        
 *  oma_node_id_symbol      [IN]        (SRV_CCA_NS__NULL if no oma_node_id)
 *  oma_ref_ids             [IN]        
 *  size                    [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_OK
 *  SRV_CCA_STATUS_MEMFULL
 *****************************************************************************/
static srv_cca_status_enum srv_cca_oma_deprel_populate_ref_ids(
                    cca_oma_deprel_info_struct **listhead,
                    S32 l1node,
                    U16 oma_node_id_symbol,
                    CHAR **oma_ref_ids,
                    S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    cca_oma_deprel_info_struct *tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!size)
    {
        tmp = srv_cca_oma_new_deprel_info();
        if (!tmp)
            return SRV_CCA_STATUS_MEMFULL;

        tmp->hNode = (S32) l1node;
        if (srv_cca_doc_nodedata_str_first((S32) l1node, SRV_CCA_NS_NODEID, &(tmp->cca_node_id)) != SRV_CCA_STATUS_OK)
        {
            srv_cca_oma_release_deprel_info(tmp);
            return SRV_CCA_STATUS_MEMFULL;
        }
        if (oma_node_id_symbol != SRV_CCA_NS__NULL &&
            (srv_cca_doc_nodedata_str_first((S32) l1node, oma_node_id_symbol, &(tmp->oma_node_id)) != SRV_CCA_STATUS_OK ||
             tmp->oma_node_id == 0))
        {
            srv_cca_oma_release_deprel_info(tmp);
            return SRV_CCA_STATUS_MEMFULL;
        }
        srv_cca_oma_attach_deprel_info_to_list(listhead, tmp);
        return SRV_CCA_STATUS_OK;
    }

    for (i = 0; i < size; i++)
    {
        if (oma_ref_ids[i] == 0)
            continue;

        tmp = srv_cca_oma_new_deprel_info();
        if (!tmp)
            return SRV_CCA_STATUS_MEMFULL;

        tmp->hNode = (S32) l1node;
        tmp->oma_ref_id = oma_ref_ids[i];

        if (srv_cca_doc_nodedata_str_first((S32) l1node, SRV_CCA_NS_NODEID, &(tmp->cca_node_id)) != SRV_CCA_STATUS_OK)
        {
            srv_cca_oma_release_deprel_info(tmp);
            continue;
        }
        if (oma_node_id_symbol != SRV_CCA_NS__NULL &&
            (srv_cca_doc_nodedata_str_first((S32) l1node, oma_node_id_symbol, &(tmp->oma_node_id)) != SRV_CCA_STATUS_OK ||
             tmp->oma_node_id == 0))
        {
            srv_cca_oma_release_deprel_info(tmp);
            continue;
        }

        srv_cca_oma_attach_deprel_info_to_list(listhead, tmp);
    }
    return SRV_CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_deprel_populate_lists
 * DESCRIPTION
 *  helper function to cross reference 2 deprel info lists and create deprel child and insert to deprel node
 * PARAMETERS
 *  deprel          [IN]        
 *  dep_id          [IN]        
 *  list1head       [IN]        
 *  list2head       [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_OK
 *  SRV_CCA_STATUS_MEMFULL
 *****************************************************************************/
static srv_cca_status_enum srv_cca_oma_deprel_populate_lists(
                    S32 deprel,
                    U16 dep_id,
                    cca_oma_deprel_info_struct *list1head,
                    cca_oma_deprel_info_struct *list2head)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_oma_deprel_info_struct *tmp2;
    S32 deprel_child;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (list1head)
    {
        tmp2 = list2head;
        while (tmp2)
        {
            if (list1head->oma_ref_id == NULL)
                break;
            if (tmp2->oma_node_id == NULL)
            {
                tmp2 = tmp2->next;
                continue;
            }
            if (strcmp(list1head->oma_ref_id, tmp2->oma_node_id) == 0)
            {
                deprel_child = srv_cca_oma_new_deprel_child(dep_id, list1head->cca_node_id, tmp2->cca_node_id, list1head->hNode);
                if (!deprel_child)
                    return SRV_CCA_STATUS_MEMFULL;
                srv_cca_doc_node_attach(deprel_child, deprel);
                break;
            }
            tmp2 = tmp2->next;
        }
        list1head = list1head->next;
    }
    return SRV_CCA_STATUS_OK;
}



/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_new_deprel_info
 * DESCRIPTION
 *  Create a new deprel info element
 * PARAMETERS
 *  void
 * RETURNS
 *  0           memory full
 *  otherwise   created info elem
 *****************************************************************************/
static cca_oma_deprel_info_struct *srv_cca_oma_new_deprel_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_oma_deprel_info_struct *elem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    elem = srv_cca_malloc_type(cca_oma_deprel_info_struct);
    if (elem)
        memset(elem, 0, sizeof(cca_oma_deprel_info_struct));
    return elem;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_release_deprel_info
 * DESCRIPTION
 *  Release a new deprel info memory
 * PARAMETERS
 *  elem        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_oma_release_deprel_info(cca_oma_deprel_info_struct *elem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cca_mfree(elem);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_release_deprel_info_list
 * DESCRIPTION
 *  Release a new deprel info list memory
 * PARAMETERS
 *  listhead        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_oma_release_deprel_info_list(cca_oma_deprel_info_struct *listhead)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_oma_deprel_info_struct *next;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (listhead)
    {
        next = listhead->next;
        srv_cca_oma_release_deprel_info(listhead);
        listhead = next;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_attach_deprel_info_to_list
 * DESCRIPTION
 *  Attach a deprel info element to list
 * PARAMETERS
 *  listhead        [IN]        
 *  elem            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_oma_attach_deprel_info_to_list(cca_oma_deprel_info_struct **listhead, cca_oma_deprel_info_struct *elem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cca_doc_link_list_elem_to_last((srv_cca_generic_ptr_struct **) listhead, (srv_cca_generic_ptr_struct*) elem);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_new_deprel_child
 * DESCRIPTION
 *  create a new dependency relationship child node
 * PARAMETERS
 *  dep_id          [IN]        
 *  node_id         [IN]        
 *  ref_id          [IN]        
 *  hSrcNode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 srv_cca_oma_new_deprel_child(U16 dep_id, CHAR *node_id, CHAR *ref_id, S32 hSrcNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_status_enum status;
    srv_cca_doc_node_struct *nodeDepRelChild;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nodeDepRelChild = (srv_cca_doc_node_struct*) srv_cca_doc_node_new(dep_id);
    if (!nodeDepRelChild)
        return 0;

    if (srv_cca_doc_nodedata_add_int((S32) nodeDepRelChild, SRV_CCA_NS_HSRCNODE, hSrcNode) != SRV_CCA_STATUS_OK)
        goto srv_cca_oma_new_deprel_child_error;
    if (srv_cca_doc_nodedata_add_int((S32) nodeDepRelChild, SRV_CCA_NS_ISUSED, 0) != SRV_CCA_STATUS_OK)
        goto srv_cca_oma_new_deprel_child_error;
    if (srv_cca_doc_nodedata_add_str((S32) nodeDepRelChild, SRV_CCA_NS_NODEID, (const CHAR*)node_id) != SRV_CCA_STATUS_OK)
        goto srv_cca_oma_new_deprel_child_error;
    if (dep_id == SRV_CCA_NS_DEP_PROXY)
        status = srv_cca_doc_nodedata_add_str((S32) nodeDepRelChild, SRV_CCA_NS_REFNAPID, (const CHAR*)ref_id);
    else
        status = srv_cca_doc_nodedata_add_str((S32) nodeDepRelChild, SRV_CCA_NS_REFPXID, (const CHAR*)ref_id);
    if (status != SRV_CCA_STATUS_OK)
        goto srv_cca_oma_new_deprel_child_error;

    return (S32) nodeDepRelChild;

  srv_cca_oma_new_deprel_child_error:
    if (nodeDepRelChild)
        srv_cca_doc_node_free((S32) nodeDepRelChild);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_find_deprel_info
 * DESCRIPTION
 *  Release a new deprel info list memory
 * PARAMETERS
 *  listhead        [IN]        
 *  oma_node_id     [IN]        
 * RETURNS
 *  the matched deprel info, or 0 if not found
 *****************************************************************************/
cca_oma_deprel_info_struct *srv_cca_oma_find_deprel_info(cca_oma_deprel_info_struct *listhead, CHAR *oma_node_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (listhead)
    {
        if (listhead->oma_node_id && strcmp(listhead->oma_node_id, oma_node_id) == 0)
            return listhead;
        listhead = listhead->next;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_add_deprel
 * DESCRIPTION
 *  add dependency relation data to dep rel subtree in doc
 * PARAMETERS
 *  hRoot           [IN]        
 *  dep_id          [IN]        
 *  node_id         [IN]        
 *  ref_id          [IN]        
 *  hSrcNode        [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
srv_cca_status_enum srv_cca_oma_add_deprel(S32 hRoot, U16 dep_id, CHAR *node_id, CHAR *ref_id, S32 hSrcNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *nodeDepRel;
    S32 hDepRelChild;
    U16 symbol;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hRoot)
        return SRV_CCA_STATUS_INVALID_HANDLE;

    /* get DEP_REL root node */
    symbol = SRV_CCA_NS_DEPREL;
    nodeDepRel = (srv_cca_doc_node_struct*) srv_cca_doc_list_find(
                                            (srv_cca_generic_ptr_struct *) (((srv_cca_doc_node_struct*) hRoot)->child),
                                            srv_cca_doc_equal_node_id,
                                            (void*)&symbol);
    if (!nodeDepRel)
    {
        nodeDepRel = (srv_cca_doc_node_struct*) srv_cca_doc_node_new_and_attach(SRV_CCA_NS_DEPREL, hRoot);
        if (!nodeDepRel)
            return SRV_CCA_STATUS_MEMFULL;
    }

    /* add dep rel data to DEP_REL node */
    hDepRelChild = srv_cca_oma_new_deprel_child(dep_id, node_id, ref_id, hSrcNode);
    if (!hDepRelChild)
        return SRV_CCA_STATUS_MEMFULL;
    srv_cca_doc_node_attach(hDepRelChild, (S32) nodeDepRel);

    return SRV_CCA_STATUS_OK;
}



#define SRV_CCA_OMA_SORT_DOC

/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_sort_new_doc
 * DESCRIPTION
 *  this function ensures all PROXY nodes are ahead of APPLICATION nodes
 * PARAMETERS
 *  hRoot       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_oma_sort_new_doc(S32 hRoot)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *root;
    srv_cca_doc_node_struct *proxys = NULL;
    srv_cca_doc_node_struct *apps = NULL;
    srv_cca_doc_node_struct *bootstraps = NULL;
    srv_cca_doc_node_struct *napdefs = NULL;
    srv_cca_doc_node_struct *crt;
    srv_cca_doc_node_struct *tmp;
    srv_cca_doc_node_struct *prev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CCA_ASSERT(hRoot);
    root = (srv_cca_doc_node_struct*) hRoot;
    if (root->num_child <= 1)
        return;

    prev = 0;
    crt = root->child;
    while (crt)
    {
        tmp = crt->next;
        if (crt->node_id == SRV_CCA_NS_OMA_PROXY || crt->node_id == SRV_CCA_NS_OMA_NAPDEF ||
            crt->node_id == SRV_CCA_NS_OMA_APPLICATION || crt->node_id == SRV_CCA_NS_OMA_BOOTSTRAP)
        {
            if (prev)
                prev->next = crt->next;
            else
                root->child = crt->next;
            crt->next = 0;

            if (crt->node_id == SRV_CCA_NS_OMA_PROXY)
                srv_cca_doc_link_list_elem_to_last(
                    (srv_cca_generic_ptr_struct **) & proxys,
                    (srv_cca_generic_ptr_struct*) crt);
            else if (crt->node_id == SRV_CCA_NS_OMA_APPLICATION)
                srv_cca_doc_link_list_elem_to_last((srv_cca_generic_ptr_struct **) & apps, (srv_cca_generic_ptr_struct*) crt);
            else if (crt->node_id == SRV_CCA_NS_OMA_BOOTSTRAP)
                srv_cca_doc_link_list_elem_to_last(
                    (srv_cca_generic_ptr_struct **) & bootstraps,
                    (srv_cca_generic_ptr_struct*) crt);
            else if (crt->node_id == SRV_CCA_NS_OMA_NAPDEF)
                srv_cca_doc_link_list_elem_to_last(
                    (srv_cca_generic_ptr_struct **) & napdefs,
                    (srv_cca_generic_ptr_struct*) crt);
        }
        else
            prev = crt;
        crt = tmp;
    }

    srv_cca_doc_link_list_elem_to_last((srv_cca_generic_ptr_struct **) & bootstraps, (srv_cca_generic_ptr_struct*) napdefs);
    srv_cca_doc_link_list_elem_to_last((srv_cca_generic_ptr_struct **) & bootstraps, (srv_cca_generic_ptr_struct*) proxys);
    srv_cca_doc_link_list_elem_to_last((srv_cca_generic_ptr_struct **) & bootstraps, (srv_cca_generic_ptr_struct*) apps);
    srv_cca_doc_link_list_elem_to_last(
        (srv_cca_generic_ptr_struct **) & bootstraps,
        (srv_cca_generic_ptr_struct*) (root->child));
    root->child = bootstraps;
}


#define SRV_CCA_OMA_GEN_L1SYMBOLS
/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_construct_l1symbols
 * DESCRIPTION
 *  pre: valid hConfig
 *  cosntruct level 1 symbols array
 * PARAMETERS
 *  hConfig             [IN]        
 *  max_symbols         [IN]        
 *  num_symbols         [IN]        
 *  l1symbols           [OUT]       
 *  l1symbols_count     [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_oma_construct_l1symbols(
        S32 hConfig,
        S32 max_symbols,
        S32 *num_symbols,
        U16 *l1symbols,
        S32 *l1symbols_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 crtNumSymbols;
    srv_cca_doc_node_struct *l1nodes;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hConfig || !num_symbols || !l1symbols || !l1symbols_count)
        return;
    l1nodes = ((srv_cca_document_struct*) hConfig)->doc_tree->child;
    *num_symbols = 0;
     kal_mem_set(l1symbols, 0, max_symbols * sizeof(U16));
     kal_mem_set(l1symbols_count, 0, max_symbols * sizeof(U16));
    if (max_symbols <= 0)
        return;

    crtNumSymbols = 0;
    while (l1nodes)
    {
        if (srv_cca_oma_is_in_app_context(l1nodes))
        {
            for (i = 0; i < crtNumSymbols; i++)
                if (l1nodes->node_id == l1symbols[i])
                    break;
            if (i < crtNumSymbols)
                l1symbols_count[i]++;
            else if (crtNumSymbols < max_symbols)
            {
                l1symbols[crtNumSymbols] = l1nodes->node_id;
                l1symbols_count[crtNumSymbols] = 1;
                crtNumSymbols++;
            }
        }
        l1nodes = l1nodes->next;
    }
    *num_symbols = crtNumSymbols;
}





#define SRV_CCA_OMA_PARSE_DOC

/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_handle_new_doc
 * DESCRIPTION
 *  handle new OMA doc
 *  func shows MEM FULL / DONE dialog if needed
 * PARAMETERS
 *  hConfig     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_cca_oma_handle_new_doc(srv_cca_cntx_struct *cntx, S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32    anyAppInterests;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cca_oma_sort_new_doc((S32) ((srv_cca_document_struct*) hConfig)->doc_tree);

    /* log the whole cca doc */
    SRV_CCA_LOG_DOC(hConfig);

    anyAppInterests = srv_cca_oma_check_app_config(cntx);
    return anyAppInterests;
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_check_app_config
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 srv_cca_oma_check_app_config(srv_cca_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    const srv_cca_app_config_struct *crtConfig;
    S32 isAppInterests;
    S32 anyAppInterests;
    srv_cca_iterator_struct *iter_datalist;
    srv_cca_status_enum status;
    srv_cca_core_data_struct *dataobj;
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_UI_ENTRY_SETTINGS_INFO);

    iter_datalist = srv_cca_oma_construct_appcheck_datalist(inst->hConfig);
    if (!iter_datalist)
    {
        /* If SIM Provisioning, can not show UI */
        if (inst->prov_type == SRV_CCA_PROV_TYPE_OTA_PROV)
            srv_cca_emit_notify_event(inst, SRV_CCA_NOTIFY_TYPE_MEM_FULL);
        
        srv_cca_configure_complete(cntx);
        return 0;
    }

    anyAppInterests = 0;
    while (1)
    {
        crtConfig = srv_cca_get_app_config(i);

        MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_CHECK_APP_CONFIG_ID, i, crtConfig->config_id);

        if (crtConfig->config_id == 0xFFFF)
            break;

        isAppInterests = 0;

        /* ensure level 1 node symbols are defined in APP's config (skip this app if none are found) */
        status = srv_cca_doc_get_nodedata_by_param(iter_datalist, SRV_CCA_NS_L1NODEID, &dataobj);
        if (status == SRV_CCA_STATUS_OK)
        {
            S32 dtidx = 0;

            for (; dtidx < dataobj->size; dtidx++)
            {
                if (srv_cca_oma_is_node_symbol_exist
                    ((U16) (dataobj->values.i[dtidx]), crtConfig->l1node_symbols, crtConfig->num_l1node_symbols))
                    break;
            }
            if (dtidx >= dataobj->size)
            {
                MMI_TRACE(SRV_CCA_TRC_WARNING, TRC_SRV_CCA_CHECK_APP_L1NODE_NOT_FOUND, i, crtConfig->config_id);
                i++;
                continue;
            }
        }

        /* check if AppCheck callback exists */
        if (crtConfig->app_check_doc_hdlr)
        {
            srv_cca_iterator_restart(iter_datalist);
            if (crtConfig->app_check_doc_hdlr(crtConfig->config_id, inst->hConfig, iter_datalist) == SRV_CCA_STATUS_OK)
                isAppInterests = 1;
            else
            {
                MMI_TRACE(SRV_CCA_TRC_WARNING, TRC_SRV_CCA_CHECK_APP_APPCHECK_FAIL, i, crtConfig->config_id);
                i++;
                continue;
            }
        }

        /* check if AppID is defined */
        if (!isAppInterests && crtConfig->num_appids > 0 && crtConfig->appids)
        {
            status = srv_cca_oma_doc_contains_appid(inst->hConfig, crtConfig->appids, crtConfig->num_appids);
            if (status == SRV_CCA_STATUS_MEMFULL)
            {
                srv_cca_doc_datalist_release((srv_cca_doc_node_datalist_struct*) (iter_datalist->head_node), 1);
                srv_cca_iterator_release(iter_datalist);
                srv_cca_configure_complete(cntx);
                return 0;
            }

            isAppInterests = (status == SRV_CCA_STATUS_OK);

            if (!isAppInterests)
            {
                MMI_TRACE(SRV_CCA_TRC_WARNING, TRC_SRV_CCA_CHECK_APP_APPID_NOT_FOUND, i, crtConfig->config_id);
            }

            MMI_TRACE(
                SRV_CCA_TRC_INFO,
                TRC_SRV_CCA_CHECK_APP_CHECK_STATUS,
                i,
                crtConfig->config_id,
                (status == SRV_CCA_STATUS_OK));
        }
        else
        {
            isAppInterests = 1;

            MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_CHECK_APP_CHECK_STATUS, i, crtConfig->config_id, 2);
            MMI_TRACE(SRV_CCA_TRC_WARNING, TRC_SRV_CCA_CHECK_APP_APPID_NOT_DEFINED);
        }

        /* add APP name to settings info if it interested in this prov doc */
        if (isAppInterests)
        {
            SRV_CCA_ASSERT(inst->numApp < SRV_CCA_MAX_APPS);
            MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_CHECK_APP_INCLUDED_APPNUM, i, crtConfig->config_id, inst->numApp);

            srv_cca_new_config_result(inst, crtConfig->config_id, SRV_CCA_STATUS_SETTING_SKIPPED);
            anyAppInterests = 1;
        }
		else
		{
			//TO DO: need to delete config id if exist to handle version changed issue.
		//	srv_cca_delete_config_result(inst, crtConfig->config_id);
		}
        i++;
    }

    /* release iterator and its data --> can remove the datalist release when iterator deep delete is implemented! */
    srv_cca_doc_datalist_release((srv_cca_doc_node_datalist_struct*) (iter_datalist->head_node), 1);
    srv_cca_iterator_release(iter_datalist);

    return anyAppInterests;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_construct_appcheck_datalist
 * DESCRIPTION
 *  cosntruct data for the APP_CHECK function callback
 * PARAMETERS
 *  hConfig     [IN]        
 * RETURNS
 *  constructed object, 0 if memory full
 *****************************************************************************/
static srv_cca_iterator_struct *srv_cca_oma_construct_appcheck_datalist(S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_iterator_struct *iter_datalist;
    srv_cca_doc_node_datalist_struct *datalist_nodeid;
    srv_cca_doc_node_datalist_struct *datalist_appid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* construct AppIDs list */
    datalist_appid = srv_cca_doc_datalist_new(SRV_CCA_NS_OMA_APPID, SRV_CCA_DATA_TYPE_STR);
    if (!datalist_appid)
        return 0;
    if (srv_cca_oma_retrieve_all_appids(hConfig, datalist_appid) == SRV_CCA_STATUS_MEMFULL)
    {
        srv_cca_doc_datalist_release(datalist_appid, 1);
        return 0;
    }

    /* construct L1 Node IDs list */
    datalist_nodeid = srv_cca_doc_datalist_new(SRV_CCA_NS_L1NODEID, SRV_CCA_DATA_TYPE_INT);
    if (!datalist_nodeid)
    {
        srv_cca_doc_datalist_release(datalist_appid, 1);
        return 0;
    }
    if (srv_cca_oma_retrieve_nodeids(hConfig, datalist_nodeid) == SRV_CCA_STATUS_MEMFULL)
    {
        srv_cca_doc_datalist_release(datalist_appid, 1);
        srv_cca_doc_datalist_release(datalist_nodeid, 1);
        return 0;
    }

    /* link the 2 datalist together */
    datalist_nodeid->next = datalist_appid;

    /* construct iterator */
    iter_datalist = srv_cca_iterator_new(SRV_CCA_TR_LIST, SRV_CCA_IT_DATALIST, (srv_cca_generic_ptr_struct*) datalist_nodeid, 0);

    if (!iter_datalist)
    {
        /* srv_cca_doc_datalist_release(datalist_appid, 1); */
        srv_cca_doc_datalist_release(datalist_nodeid, 1);
    }
    return iter_datalist;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_retrieve_all_appids
 * DESCRIPTION
 *  pre: valid hConfig and datalist pointer
 *  retrieve all AppIDs described by this doc and store them in a datalist
 * PARAMETERS
 *  hConfig             [IN]        
 *  datalist_res        [OUT]       
 * RETURNS
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
static srv_cca_status_enum srv_cca_oma_retrieve_all_appids(S32 hConfig, srv_cca_doc_node_datalist_struct *datalist_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *l1nodes;
    srv_cca_doc_node_datalist_struct *datalist;
    U16 symbol;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    l1nodes = ((srv_cca_document_struct*) hConfig)->doc_tree->child;
    symbol = SRV_CCA_NS_OMA_APPID;
    while (l1nodes)
    {
        if (l1nodes->node_id == SRV_CCA_NS_OMA_APPLICATION)
        {
            datalist = (srv_cca_doc_node_datalist_struct*) srv_cca_doc_list_find(
                                                        (srv_cca_generic_ptr_struct*) (l1nodes->listchain),
                                                        srv_cca_doc_equal_param_id,
                                                        (void*)&symbol);
            if (datalist && datalist->data.size > 0 &&
                !srv_cca_doc_coredata_values_exists_str(
                    datalist_res->data.values.s,
                    datalist_res->data.size,
                    datalist->data.values.s[0]))
            {
                if (srv_cca_doc_coredata_append(&(datalist_res->data), 1, (void*)datalist->data.values.s) ==
                    SRV_CCA_STATUS_MEMFULL)
                {
                    srv_cca_doc_coredata_release_values(&(datalist_res->data));
                    return SRV_CCA_STATUS_MEMFULL;
                }
            }
        }
        l1nodes = l1nodes->next;
    }
    return SRV_CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_retrieve_nodeids
 * DESCRIPTION
 *  pre: valid hConfig and datalist pointer
 *  retrieve all node_id described by this doc and store them in a datalist
 * PARAMETERS
 *  hConfig             [IN]        
 *  datalist_res        [OUT]       
 * RETURNS
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
static srv_cca_status_enum srv_cca_oma_retrieve_nodeids(S32 hConfig, srv_cca_doc_node_datalist_struct *datalist_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *l1nodes;
    S32 val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    l1nodes = ((srv_cca_document_struct*) hConfig)->doc_tree->child;
    while (l1nodes)
    {
        val = (S32) l1nodes->node_id;   /* to avoid typecasting U16 pointer to S32 pointer (higher 2 bytes = corrupted data) */
        if (srv_cca_doc_coredata_append(&(datalist_res->data), 1, (void*)&val) == SRV_CCA_STATUS_MEMFULL)
        {
            srv_cca_doc_coredata_release_values(&(datalist_res->data));
            return SRV_CCA_STATUS_MEMFULL;
        }
        l1nodes = l1nodes->next;
    }
    return SRV_CCA_STATUS_OK;
}



/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_doc_contains_appid
 * DESCRIPTION
 *  check whether doc contains the specified appid
 * PARAMETERS
 *  hConfig         [IN]        
 *  appids          [IN]        
 *  numAppIds       [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_OK=found
 *  SRV_CCA_STATUS_NOT_FOUND=not found
 *****************************************************************************/
static srv_cca_status_enum srv_cca_oma_doc_contains_appid(S32 hConfig, const CHAR **appids, S32 numAppIds)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_iterator_struct *iter_nodelist;
    srv_cca_status_enum status;
    CHAR *value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hConfig || !appids || numAppIds <= 0)
        return SRV_CCA_STATUS_INVALID_HANDLE;

    status = srv_cca_doc_get_nodes(hConfig, SRV_CCA_NS_OMA_APPLICATION, &iter_nodelist, 0);
    if (status == SRV_CCA_STATUS_MEMFULL)
        return SRV_CCA_STATUS_MEMFULL;

    if (status == SRV_CCA_STATUS_NOT_FOUND)
        return SRV_CCA_STATUS_NOT_FOUND;

    while (srv_cca_iterator_next(iter_nodelist))
    {
        status = srv_cca_doc_get_nodedata_str_first(iter_nodelist, SRV_CCA_NS_OMA_APPID, &value);
        if (status == SRV_CCA_STATUS_MEMFULL)
        {
            srv_cca_iterator_release(iter_nodelist);
            return SRV_CCA_STATUS_MEMFULL;
        }
        else if (status != SRV_CCA_STATUS_OK)
            continue;

        if (srv_cca_oma_is_appid_exist(value, appids, numAppIds))
        {
            srv_cca_iterator_release(iter_nodelist);
            return SRV_CCA_STATUS_OK;
        }
    }
    srv_cca_iterator_release(iter_nodelist);
    return SRV_CCA_STATUS_NOT_FOUND;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_revise_doc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_cca_status_enum srv_cca_oma_revise_doc(S32 hRoot)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_CCA_HANDLE hDepNode;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    
    srv_cca_oma_fix_doc(hRoot);
    hDepNode = srv_cca_oma_generate_deprel_node(hRoot);
    if (!hDepNode)
        return SRV_CCA_STATUS_MEMFULL;
    srv_cca_doc_node_attach(hDepNode, hRoot);
    srv_cca_oma_sort_new_doc(hRoot);
    return SRV_CCA_STATUS_OK;
}

#define SRV_CCA_OMA_INSTALL
/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_new_doc_continue
 * DESCRIPTION
 *  continue to process next application
 *  func shows MEM FULL / DONE / PROGRESSING dialog if needed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_oma_new_doc_continue(srv_cca_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    const srv_cca_app_config_struct *crtConfig;
    srv_cca_status_enum status;
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_OMA_NEW_DOC_CONTINUE, inst->crtConfigIndex);

    crtConfig = srv_cca_get_app_config(inst->crtConfigIndex);
    if (srv_cca_get_config_result(inst, crtConfig->config_id) != SRV_CCA_STATUS_NOT_FOUND)
    {
        MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_OMA_NEW_DOC_CONTINUE_FIND_APP, crtConfig->config_id);

        /* add data account IDs to all referenced node if not yet done so */
        status = srv_cca_oma_add_dataacctid_to_ref_nodes(inst->hConfig);

        /*  mark the all the node in use for the push application */
        if (status == SRV_CCA_STATUS_OK && crtConfig->config_id == SRV_CCA_CONFIG_PUSH)
            status = srv_cca_oma_mark_application_depset(inst->hConfig, crtConfig);

        /* go through config doc & mark nodes that are in this app's context */
        if (status == SRV_CCA_STATUS_OK)
            status = srv_cca_oma_mark_in_app_context(inst, inst->hConfig);

        if (status == SRV_CCA_STATUS_MEMFULL)
        {
            srv_cca_oma_handle_memfull(SRV_CCA_MEM_FULL_IN_APP);
        }
        
        /* Check if need to filter it */
        if (inst->has_selected)
        {
            for (i = 0; i < inst->sel_cfg_num; i++)
            {
                if (inst->sel_cfg_ids[i] == crtConfig->config_id)
                break;
            }
            if (i == inst->sel_cfg_num)
                status = SRV_CCA_STATUS_SETTING_SKIPPED;
        }
        
        if (status == SRV_CCA_STATUS_OK)
        {
            /* send configure_ind to app */
            srv_cca_register_memfull_notify(srv_cca_oma_handle_memfull, SRV_CCA_MEM_FULL_IN_APP);
            srv_cca_send_app_configure_ind(
                inst,
                inst->prov_type,
                inst->prov_flag,
                inst->sim_id,
                crtConfig->config_id,
                inst->hConfig);
            return;
        }
    }
    srv_cca_oma_new_doc_process_next_app(cntx);
}


#ifdef __SRV_CCA_SLIM__
static void srv_cca_oma_new_doc_process_end(srv_cca_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to save memory for setting_info */
    if (inst->hConfig)
    {
        srv_cca_doc_destroy(inst->hConfig);
        inst->hConfig = 0;
    }
    
    srv_cca_emit_post_install_event(inst);
    if (srv_cca_oma_is_memfull_during_app_configure())
    {
        cca_oma_memfull_flag = 0;
        srv_cca_emit_notify_event(inst, SRV_CCA_NOTIFY_TYPE_MEM_FULL);
    }
}
#endif /* __SRV_CCA_SLIM__ */

/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_new_doc_process_next_app
 * DESCRIPTION
 *  continue to process next application
 *  func shows DONE dialog if needed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_oma_new_doc_process_next_app(srv_cca_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_OMA_NEW_DOC_PROCESS_NEXT_APP, inst->crtConfigIndex + 1);

    srv_cca_deregister_memfull_notify(SRV_CCA_MEM_FULL_IN_APP);

    /* next app in config list */
    inst->crtConfigIndex++;

    /* if next app found */
    if (srv_cca_get_app_config(inst->crtConfigIndex)->config_id != 0xFFFF && 
        !srv_cca_oma_is_memfull_during_app_configure())
    {
        /* send signal to itself to continue process */
        srv_cca_send_new_doc_continue_ind();
        return;
    }

    /* no more app */
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    if (inst->cca_state == SRV_CCA_STATE_PROCESS_MSG)
    {

#ifdef __SRV_CCA_SLIM__

        srv_cca_oma_new_doc_process_end(cntx);

#else /* __SRV_CCA_SLIM__ */

        /* to save memory for setting_info */
        if (inst->hConfig)
        {
            srv_cca_doc_destroy(inst->hConfig);
            inst->hConfig = 0;
        }

        srv_cca_emit_post_install_event(inst);
        if (srv_cca_oma_is_memfull_during_app_configure())
        {
            cca_oma_memfull_flag = 0;
            srv_cca_emit_notify_event(inst, SRV_CCA_NOTIFY_TYPE_MEM_FULL);
        }

#endif /* __SRV_CCA_SLIM__ */

        return;
    }
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 

    if (inst->prov_type == SRV_CCA_PROV_TYPE_SIM_PROV)
    {
        srv_cca_configure_complete(cntx);
        if (srv_cca_oma_is_memfull_during_app_configure())
            cca_oma_memfull_flag = 0;
        return;
    }

    if (inst->prov_type == SRV_CCA_PROV_TYPE_OTA_PROV)
    {
#ifdef __SRV_CCA_SLIM__
        
                srv_cca_oma_new_doc_process_end(cntx);
        
#else /* __SRV_CCA_SLIM__ */

        /* to save memory for setting_info */
        if (inst->hConfig)
        {
            srv_cca_doc_destroy(inst->hConfig);
            inst->hConfig = 0;
        }

        srv_cca_emit_post_install_event(inst);
        if (srv_cca_oma_is_memfull_during_app_configure())
        {
            cca_oma_memfull_flag = 0;
            srv_cca_emit_notify_event(inst, SRV_CCA_NOTIFY_TYPE_MEM_FULL);
        }
#endif /* __SRV_CCA_SLIM__ */

        return;
    }
    SRV_CCA_ASSERT(0);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_add_dataacctid_to_ref_nodes
 * DESCRIPTION
 *  add data account ID to the associated NAPDEF node
 * PARAMETERS
 *  hConfig     [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_INVALID_HANDLE
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
static srv_cca_status_enum srv_cca_oma_add_dataacctid_to_ref_nodes(S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_document_struct *doc;
    srv_cca_doc_node_struct *nodeDepRel;
    srv_cca_doc_node_struct *l1node;
    S32 dtacctid;
    S32 hSrcNode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    doc = (srv_cca_document_struct*) hConfig;
    if (!doc)
        return SRV_CCA_STATUS_INVALID_HANDLE;

    if (!(doc->dtAcctIDAdded))
        return SRV_CCA_STATUS_OK;

    if (srv_cca_oma_get_deprel_childs(hConfig, &nodeDepRel) == SRV_CCA_STATUS_MEMFULL)
        return SRV_CCA_STATUS_MEMFULL;

    /* remove all data account ID in nodes
       needs to be removed first so the order of IDs can be guarranteed
       (this is to handle cases when multiple data account provisioning apps are in use
       eg, standard data account + WLAN...etc) */
    l1node = doc->doc_tree->child;
    while (l1node)
    {
        srv_cca_doc_remove_nodedata((S32) l1node, SRV_CCA_NS_DATAACCTID);
        l1node = l1node->next;
    }

    /*
     * add data account IDs to nodes
     */
    while (nodeDepRel)
    {
        if (srv_cca_doc_nodedata_int_first((S32) nodeDepRel, SRV_CCA_NS_DATAACCTID, &dtacctid) != SRV_CCA_STATUS_OK ||
            srv_cca_doc_nodedata_int_first((S32) nodeDepRel, SRV_CCA_NS_HSRCNODE, &hSrcNode) != SRV_CCA_STATUS_OK)
        {
            nodeDepRel = nodeDepRel->next;
            continue;
        }

        if (srv_cca_doc_nodedata_add_int(hSrcNode, SRV_CCA_NS_DATAACCTID, dtacctid) != SRV_CCA_STATUS_OK)
            return SRV_CCA_STATUS_MEMFULL;
        nodeDepRel = nodeDepRel->next;
    }
    doc->dtAcctIDAdded = 0;
    return SRV_CCA_STATUS_OK;
}




/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_mark_application_depset
 * DESCRIPTION
 *  mark the dependencies of one application who can determine the usage of all its dependencies
 *  mark the node in use which is referred by current application
 * PARAMETERS
 *  hConfig         [IN]        
 *  crtConfig       [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_INVALID_HANDLE
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
static srv_cca_status_enum srv_cca_oma_mark_application_depset(S32 hConfig, const srv_cca_app_config_struct *crtConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *nodeDepRelBegin;
    srv_cca_iterator_struct *iter_nodelist;
    srv_cca_status_enum status;
    CHAR *value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hConfig || !crtConfig)
        return SRV_CCA_STATUS_INVALID_HANDLE;

    status = srv_cca_doc_get_nodes(hConfig, SRV_CCA_NS_OMA_APPLICATION, &iter_nodelist, 0);
    if (status == SRV_CCA_STATUS_MEMFULL)
        return SRV_CCA_STATUS_MEMFULL;

    if (status == SRV_CCA_STATUS_NOT_FOUND)
        return SRV_CCA_STATUS_OK;

    while (srv_cca_iterator_next(iter_nodelist))
    {
        status = srv_cca_doc_get_nodedata_str_first(iter_nodelist, SRV_CCA_NS_OMA_APPID, &value);
        if (status == SRV_CCA_STATUS_MEMFULL)
        {
            srv_cca_iterator_release(iter_nodelist);
            return SRV_CCA_STATUS_MEMFULL;
        }
        else if (status != SRV_CCA_STATUS_OK)
            continue;

        if (srv_cca_oma_is_appid_exist(value, crtConfig->appids, crtConfig->num_appids))
        {
            status = srv_cca_doc_get_nodedata_str_first(iter_nodelist, SRV_CCA_NS_NODEID, &value);
            if (status == SRV_CCA_STATUS_MEMFULL)
            {
                srv_cca_iterator_release(iter_nodelist);
                return SRV_CCA_STATUS_MEMFULL;
            }
            if (srv_cca_oma_get_deprel_childs(hConfig, &nodeDepRelBegin) == SRV_CCA_STATUS_MEMFULL)
            {
                srv_cca_iterator_release(iter_nodelist);
                return SRV_CCA_STATUS_MEMFULL;
            }

            /* recursively mark in-use flag */
            srv_cca_oma_mark_referred_depset(nodeDepRelBegin, value);
        }
    }
    srv_cca_iterator_release(iter_nodelist);
    return SRV_CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_mark_referred_depset
 * DESCRIPTION
 *  mark dep rel subtree nodes to "set" if data has been filled
 *  recursively mark nodes who is referred by this node from top down to bottom
 * PARAMETERS
 *  nodeDepRelBegin     [IN]        
 *  nodeIdToMark        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_oma_mark_referred_depset(srv_cca_doc_node_struct *nodeDepRelBegin, CHAR *nodeIdToMark)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *crtNode;
    srv_cca_doc_node_datalist_struct *crtdlist;
    CHAR **nodeid;
    S32 *inuse;
 //   CHAR **refnapid;
    CHAR **refpxid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    crtNode = nodeDepRelBegin;
    /* for each dep-rel data nodes */
    while (crtNode)
    {
        /* get its parameters */
        crtdlist = crtNode->listchain;
        nodeid = 0;
        inuse = 0;
      //  refnapid = 0;
        refpxid = 0;
        while (crtdlist)
        {
            switch (crtdlist->data.id)
            {
                case SRV_CCA_NS_NODEID:
                    nodeid = crtdlist->data.values.s;
                    break;
                case SRV_CCA_NS_ISUSED:
                    inuse = crtdlist->data.values.i;
                    break;
               /*     
                case SRV_CCA_NS_REFNAPID:
                    refnapid = crtdlist->data.values.s;
                    break;
               */     
                case SRV_CCA_NS_REFPXID:
                    refpxid = crtdlist->data.values.s;
                    break;
            }
            crtdlist = crtdlist->next;
        }

        /* check if ref id matched */
        if (nodeid && strcmp(nodeid[0], nodeIdToMark) == 0)
        {
            /* mark in-use only if this node hasnt been marked before */
            if (inuse && inuse[0] == 0)
            {
                inuse[0] = 1;
                /* recursively mark nodes that is referred by this node */
                if (refpxid && refpxid[0])
                    srv_cca_oma_mark_referred_depset(nodeDepRelBegin, refpxid[0]);
                /*
                 * else if(refnapid && refnapid[0])
                 * srv_cca_oma_mark_top_depset(nodeDepRelBegin, refnapid[0]);
                 */
            }
        }

        crtNode = crtNode->next;
    }
}



/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_mark_in_app_context
 * DESCRIPTION
 *  check whether each of the level 1 nodes is in app's context (set flag)
 * PARAMETERS
 *  hConfig     [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_OK=one or more nodes are in app's context (and marked),
 *  SRV_CCA_STATUS_FAIL=no nodes are in app's context (and marked),
 *  SRV_CCA_STATUS_MEMFULL
 *****************************************************************************/
static srv_cca_status_enum srv_cca_oma_mark_in_app_context(srv_cca_inst_struct *inst, S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_status_enum status;
    srv_cca_doc_node_struct *l1node;
    srv_cca_doc_node_datalist_struct *datalist;
    U8 hasNodeInContext;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hConfig)
        return SRV_CCA_STATUS_INVALID_HANDLE;

    hasNodeInContext = 0;
    l1node = ((srv_cca_document_struct*) hConfig)->doc_tree->child;
    while (l1node)
    {
        status = srv_cca_oma_check_in_app_context(inst, hConfig, l1node);
        if (status == SRV_CCA_STATUS_MEMFULL)
            return SRV_CCA_STATUS_MEMFULL;

        datalist = srv_cca_doc_datalist_find_ptr(l1node->listchain, SRV_CCA_NS_INAPPCONTEXT);
        hasNodeInContext |= (status == SRV_CCA_STATUS_OK);
        if (!datalist)
            status = srv_cca_doc_nodedata_add_int((S32) l1node, SRV_CCA_NS_INAPPCONTEXT, (status == SRV_CCA_STATUS_OK));
        else
            datalist->data.values.i[0] = (S32) (status == SRV_CCA_STATUS_OK);

        if (status == SRV_CCA_STATUS_MEMFULL)
            return SRV_CCA_STATUS_MEMFULL;

        l1node = l1node->next;
    }
    return (hasNodeInContext ? SRV_CCA_STATUS_OK : SRV_CCA_STATUS_FAIL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_check_in_app_context
 * DESCRIPTION
 *  check whether this level 1 node is in app's context
 * PARAMETERS
 *  hConfig     [IN]        
 *  l1node      [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_OK=node in app context
 *  SRV_CCA_STATUS_FAIL=node not in app context
 *  SRV_CCA_STATUS_MEMFULL
 *****************************************************************************/
static srv_cca_status_enum srv_cca_oma_check_in_app_context(srv_cca_inst_struct *inst, S32 hConfig, srv_cca_doc_node_struct *l1node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_document_struct *doc;
    const srv_cca_app_config_struct *crtConfig;
    U16 l1node_symbol;
    S32 i;
    srv_cca_status_enum status;
    srv_cca_doc_node_datalist_struct *datalist;
    cca_ref_by_struct ref_by;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    doc = (srv_cca_document_struct*) hConfig;
    crtConfig = srv_cca_get_app_config(inst->crtConfigIndex);

    if (!doc || !l1node)
        return SRV_CCA_STATUS_INVALID_HANDLE;

    l1node_symbol = l1node->node_id;

    /* 0. ensure node symbol is not on proprietary symbols list */
    if (l1node_symbol == SRV_CCA_NS_DEPREL)
        return SRV_CCA_STATUS_FAIL;

    /* 1. ensure node symbol is defined in APP's config */
    if (!srv_cca_oma_is_node_symbol_exist(l1node_symbol, crtConfig->l1node_symbols, crtConfig->num_l1node_symbols))
        return SRV_CCA_STATUS_FAIL;

    /* DA 2.0 REVISE: not check dependency for data account */
    if (crtConfig->config_id == SRV_CCA_CONFIG_DTACCT || crtConfig->config_id == SRV_CCA_CONFIG_WLAN)
        return SRV_CCA_STATUS_OK;

    /* 2. ensure node's dependency setting is set (or non exists) */
    if ((status = srv_cca_oma_is_depset(hConfig, l1node)) != SRV_CCA_STATUS_OK)
        return status;

    /* 3. if node = PROXY --> ensure the referenced APP node has same appid as in APP's config
       and referenced node is defined in node_symbol list */
    if (l1node_symbol == SRV_CCA_NS_OMA_PROXY)
    {
        /* get reference information */
        status = srv_cca_oma_find_proxy_ref_by(hConfig, l1node, &ref_by);
        if (status == SRV_CCA_STATUS_MEMFULL)
            return SRV_CCA_STATUS_MEMFULL;
        if (status == SRV_CCA_STATUS_OK)
        {
            /* check if referenced appid is defined by APP's config */
            for (i = 0; i < ref_by.ref_by_appids_count; i++)
                if (srv_cca_oma_is_appid_exist(ref_by.ref_by_appids[i], crtConfig->appids, crtConfig->num_appids))
                    break;

            /* if not defined by APP's config, check if this proxy is referenced by any node symbol defined by APP's config */
            if (i >= ref_by.ref_by_appids_count)
            {
                for (i = 0; i < ref_by.ref_by_node_symbols_count; i++)
                    if (srv_cca_oma_is_node_symbol_exist
                        (ref_by.ref_by_node_symbols[i], crtConfig->l1node_symbols, crtConfig->num_l1node_symbols))
                        break;
                if (i >= ref_by.ref_by_node_symbols_count)
                    return SRV_CCA_STATUS_FAIL;
            }
        }
    }

    /* 4. if node = APP --> ensure node's appid is defined in APP's config */
    if (l1node_symbol == SRV_CCA_NS_OMA_APPLICATION)
    {
        datalist = srv_cca_doc_datalist_find_ptr(l1node->listchain, SRV_CCA_NS_OMA_APPID);
        if (!datalist ||
            !srv_cca_oma_is_appid_exist(datalist->data.values.s[0], crtConfig->appids, crtConfig->num_appids))
            return SRV_CCA_STATUS_FAIL;
    }

    return SRV_CCA_STATUS_OK;
}



/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_is_depset
 * DESCRIPTION
 *  check whether a dep rel node contains data
 * PARAMETERS
 *  hConfig     [IN]        
 *  l1node      [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_FAIL
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
static srv_cca_status_enum srv_cca_oma_is_depset(S32 hConfig, srv_cca_doc_node_struct *l1node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *nodeDepRelBegin;
    CHAR *l1node_id;
    srv_cca_doc_node_datalist_struct *datalist;
    U16 symbol;
    U8 found_but_not_inuse;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    found_but_not_inuse = 0;
    if (srv_cca_oma_get_deprel_childs(hConfig, &nodeDepRelBegin) == SRV_CCA_STATUS_MEMFULL)
        return SRV_CCA_STATUS_MEMFULL;
    if (!nodeDepRelBegin)
        return SRV_CCA_STATUS_OK;

    symbol = SRV_CCA_NS_NODEID;
    datalist = (srv_cca_doc_node_datalist_struct*) srv_cca_doc_list_find(
                                                (srv_cca_generic_ptr_struct*) (l1node->listchain),
                                                srv_cca_doc_equal_param_id,
                                                (void*)&symbol);
    /* no SRV_CCA_NS_NODEID defined */
    if (!datalist)
        return SRV_CCA_STATUS_OK;

    l1node_id = datalist->data.values.s[0];
    /* for each dep-rel data node */
    while (nodeDepRelBegin)
    {
        /* find matching node_id */
        symbol = SRV_CCA_NS_NODEID;
        datalist = (srv_cca_doc_node_datalist_struct*) srv_cca_doc_list_find(
                                                    (srv_cca_generic_ptr_struct*) (nodeDepRelBegin->listchain),
                                                    srv_cca_doc_equal_param_id,
                                                    (void*)&symbol);
        if (datalist && strcmp(datalist->data.values.s[0], l1node_id) == 0)
        {
            /* check if in-use */
            symbol = SRV_CCA_NS_ISUSED;
            datalist = (srv_cca_doc_node_datalist_struct*) srv_cca_doc_list_find(
                                                        (srv_cca_generic_ptr_struct *) (nodeDepRelBegin->listchain),
                                                        srv_cca_doc_equal_param_id,
                                                        (void*)&symbol);
            if (datalist && datalist->data.values.i[0] == 1)
                return SRV_CCA_STATUS_OK;
            found_but_not_inuse = 1;
        }
        nodeDepRelBegin = nodeDepRelBegin->next;
    }
    if (found_but_not_inuse)
        return SRV_CCA_STATUS_FAIL;
    return SRV_CCA_STATUS_OK;
}



/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_is_in_app_context
 * DESCRIPTION
 *  check whether this level 1 nodes is in app's context
 * PARAMETERS
 *  l1node      [IN]        
 * RETURNS
 *****************************************************************************/
S32 srv_cca_oma_is_in_app_context(srv_cca_doc_node_struct *l1node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_datalist_struct *datalist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!l1node)
        return 0;

    datalist = srv_cca_doc_datalist_find_ptr(l1node->listchain, SRV_CCA_NS_INAPPCONTEXT);
    return (!datalist || datalist->data.values.i[0]);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_find_proxy_ref_by
 * DESCRIPTION
 *  pre: valid ref_by object struct for storing output
 * PARAMETERS
 *  hConfig     [IN]        
 *  l1node      [IN]        
 *  ref_by      [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_MEMFULL if mem full
 *  SRV_CCA_STATUS_FAIL if no other nodes has ref to this node
 *  SRV_CCA_STATUS_OK if one or more nodes has ref to this node (with reference info stored in ref_by obj)
 *****************************************************************************/
static srv_cca_status_enum srv_cca_oma_find_proxy_ref_by(S32 hConfig, srv_cca_doc_node_struct *l1node, cca_ref_by_struct *ref_by)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_datalist_struct *datalist;
    srv_cca_doc_node_struct *nodeDepRelBegin;
    srv_cca_doc_node_struct *srcNode;
    S32 isused;
    CHAR *ref_pxid;
    CHAR *l1node_id;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(ref_by, 0, sizeof(cca_ref_by_struct));

    if (srv_cca_oma_get_deprel_childs(hConfig, &nodeDepRelBegin) == SRV_CCA_STATUS_MEMFULL)
        return SRV_CCA_STATUS_MEMFULL;

    /* retrieve NODE_ID parameter of this level 1 node */
    datalist = srv_cca_doc_datalist_find_ptr(l1node->listchain, SRV_CCA_NS_NODEID);
    l1node_id = 0;
    if (datalist)
        l1node_id = datalist->data.values.s[0];

    if (!l1node_id)
        return SRV_CCA_STATUS_FAIL;

    /* for each of dependency relationship nodes */
    while (nodeDepRelBegin)
    {
        srcNode = 0;
        isused = 0;
        ref_pxid = 0;

        /* extract data */
        datalist = nodeDepRelBegin->listchain;
        while (datalist)
        {
            switch (datalist->data.id)
            {
                case SRV_CCA_NS_HSRCNODE:
                    srcNode = (srv_cca_doc_node_struct*) (datalist->data.values.i[0]);
                    break;
                case SRV_CCA_NS_ISUSED:
                    isused = datalist->data.values.i[0];
                    break;
                case SRV_CCA_NS_REFPXID:
                    ref_pxid = datalist->data.values.s[0];
                    break;
                case SRV_CCA_NS_NODEID:
                case SRV_CCA_NS_REFNAPID:
                    break;
            }
            datalist = datalist->next;
        }

        /* if found a node with ref to this proxy node */
        if (srcNode && ref_pxid && isused && strcmp(l1node_id, ref_pxid) == 0)
        {
            /* add referenced node symbols */
            if (ref_by->ref_by_node_symbols_count < CCA_MAX_REF_BY_ENTRIES)
            {
                for (i = 0; i < ref_by->ref_by_node_symbols_count; i++)
                    if (ref_by->ref_by_node_symbols[i] == srcNode->node_id)
                        break;
                /* do not add APPLICATION symbol to list because APPLICATION nodes are differentiated by appids
                   --> will cause ambigious if APPLICATION is added as a proxy may be referenced by 1 app and not the another */
                if (i >= ref_by->ref_by_node_symbols_count && srcNode->node_id != SRV_CCA_NS_OMA_APPLICATION)
                {
                    ref_by->ref_by_node_symbols[ref_by->ref_by_node_symbols_count] = srcNode->node_id;
                    ref_by->ref_by_node_symbols_count++;
                }
            }
            /* add referenced node handles */
            if (ref_by->ref_by_node_handles_count < CCA_MAX_REF_BY_ENTRIES)
            {
                for (i = 0; i < ref_by->ref_by_node_handles_count; i++)
                    if (ref_by->ref_by_node_handles[i] == (S32) srcNode)
                        break;
                if (i >= ref_by->ref_by_node_handles_count)
                {
                    ref_by->ref_by_node_handles[ref_by->ref_by_node_handles_count] = (S32) srcNode;
                    ref_by->ref_by_node_handles_count++;
                }
            }
            /* add referenced appids */
            if (srcNode->node_id == SRV_CCA_NS_OMA_APPLICATION && ref_by->ref_by_appids_count < CCA_MAX_REF_BY_ENTRIES)
            {
                datalist = srv_cca_doc_datalist_find_ptr(srcNode->listchain, SRV_CCA_NS_OMA_APPID);
                if (datalist)
                {
                    for (i = 0; i < ref_by->ref_by_appids_count; i++)
                        if (strcmp(ref_by->ref_by_appids[i], datalist->data.values.s[0]) == 0)
                            break;
                    if (i >= ref_by->ref_by_appids_count)
                    {
                        ref_by->ref_by_appids[ref_by->ref_by_appids_count] = datalist->data.values.s[0];
                        ref_by->ref_by_appids_count++;
                    }
                }
            }
        }
        nodeDepRelBegin = nodeDepRelBegin->next;
    }

    return (ref_by->ref_by_node_symbols_count || ref_by->ref_by_node_handles_count ||
            ref_by->ref_by_appids_count) ? SRV_CCA_STATUS_OK : SRV_CCA_STATUS_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_add_dataacctid
 * DESCRIPTION
 *  add data account ID to the associated NAPDEF node
 * PARAMETERS
 *  hConfig         [IN]        
 *  nap_node_id     [IN]        
 *  dataacctid      [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_INVALID_HANDLE
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
srv_cca_status_enum srv_cca_oma_add_dataacctid(S32 hConfig, CHAR *nap_node_id, S32 dataacctid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_document_struct *doc;
    CHAR *refnapid = NULL;
    srv_cca_status_enum status;
    srv_cca_doc_node_struct *nodeDepRelBegin;
    srv_cca_doc_node_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    doc = (srv_cca_document_struct*) hConfig;
    if (!doc || !nap_node_id)
        return SRV_CCA_STATUS_INVALID_HANDLE;

    if (srv_cca_oma_get_deprel_childs(hConfig, &nodeDepRelBegin) == SRV_CCA_STATUS_MEMFULL)
        return SRV_CCA_STATUS_MEMFULL;

    /* add data account ID to deprel node */
    node = nodeDepRelBegin;
    while (node)
    {
        status = srv_cca_doc_nodedata_str_first((S32) node, SRV_CCA_NS_REFNAPID, &refnapid);
        if (status != SRV_CCA_STATUS_OK && refnapid || (refnapid && strcmp(nap_node_id, refnapid) != 0))
        {
            node = node->next;
            continue;
        }

        if (srv_cca_doc_nodedata_add_int((S32) node, SRV_CCA_NS_DATAACCTID, dataacctid) != SRV_CCA_STATUS_OK)
            return SRV_CCA_STATUS_MEMFULL;

        doc->dtAcctIDAdded = 1;
        node = node->next;
    }

    /* recursively mark in-use flag for those node who has reference to this node */
    srv_cca_oma_mark_reference_depset(nodeDepRelBegin, nap_node_id);

    return SRV_CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_add_dtcnt_id
 * DESCRIPTION
 *      
 * RETURNS
 *  
 *****************************************************************************/
extern srv_cca_status_enum srv_cca_add_dtcnt_id(srv_cca_dtcnt_id_para_struct *dtcnt_id_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!dtcnt_id_para)
        return SRV_CCA_STATUS_INVALID_PARAM;

    return srv_cca_oma_add_dataacctid(dtcnt_id_para->h_config, dtcnt_id_para->nap_node_id, dtcnt_id_para->dtcnt_id);
}

/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_get_deprel_childs
 * DESCRIPTION
 *  mark dep rel subtree nodes to "set" if data has been filled
 * PARAMETERS
 *  hConfig             [IN]        
 *  nodeDepRelBegin     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static srv_cca_status_enum srv_cca_oma_get_deprel_childs(S32 hConfig, srv_cca_doc_node_struct **nodeDepRelBegin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_iterator_struct *iter_nodelist;
    srv_cca_status_enum status;
    srv_cca_doc_nodelist_struct *nodelist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (nodeDepRelBegin)
        *nodeDepRelBegin = 0;

    /* get dep-rel data nodes iterator */
    status = srv_cca_doc_get_nodes(hConfig, SRV_CCA_NS_DEPREL, &iter_nodelist, 0);
    if (status == SRV_CCA_STATUS_MEMFULL)
        return SRV_CCA_STATUS_MEMFULL;
    else if (status == SRV_CCA_STATUS_OK)
    {
        if (nodeDepRelBegin)
        {
            nodelist = (srv_cca_doc_nodelist_struct*) (srv_cca_iterator_next(iter_nodelist));
            if (nodelist && nodelist->node)
                *nodeDepRelBegin = nodelist->node->child;
        }
        srv_cca_iterator_release(iter_nodelist);
    }
    return SRV_CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_mark_reference_depset
 * DESCRIPTION
 *  mark dep rel subtree nodes to "set" if data has been filled
 *  recursively mark nodes that has reference to this node from bottom up to top
 * PARAMETERS
 *  nodeDepRelBegin     [IN]        
 *  refIdToMark         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_oma_mark_reference_depset(srv_cca_doc_node_struct *nodeDepRelBegin, CHAR *refIdToMark)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *crtNode;
    srv_cca_doc_node_datalist_struct *crtdlist;
    CHAR **nodeid;
    S32 *inuse;
    CHAR **refnapid;
    CHAR **refpxid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    crtNode = nodeDepRelBegin;
    /* for each dep-rel data nodes */
    while (crtNode)
    {
        /* get its parameters */
        crtdlist = crtNode->listchain;
        nodeid = 0;
        inuse = 0;
        refnapid = 0;
        refpxid = 0;
        while (crtdlist)
        {
            switch (crtdlist->data.id)
            {
                case SRV_CCA_NS_NODEID:
                    nodeid = crtdlist->data.values.s;
                    break;
                case SRV_CCA_NS_ISUSED:
                    inuse = crtdlist->data.values.i;
                    break;
                case SRV_CCA_NS_REFNAPID:
                    refnapid = crtdlist->data.values.s;
                    break;
                case SRV_CCA_NS_REFPXID:
                    refpxid = crtdlist->data.values.s;
                    break;
            }
            crtdlist = crtdlist->next;
        }

        /* check if ref id matched */
        if ((refnapid && strcmp(refnapid[0], refIdToMark) == 0) || (refpxid && strcmp(refpxid[0], refIdToMark) == 0))
        {
            /* mark in-use only if this node hasn't been marked before */
            if (inuse && inuse[0] == 0)
            {
                inuse[0] = 1;
                /* recursively mark nodes that has ref to this node */
                if (nodeid && nodeid[0])
                    srv_cca_oma_mark_reference_depset(nodeDepRelBegin, nodeid[0]);
            }
        }

        crtNode = crtNode->next;
    }
}





#endif /* __CCA_SUPPORT__ */ 


