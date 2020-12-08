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
 * AGPSSUPLOTAP.c
 *
 * Project:
 * --------
 *
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "stack_common.h"
#include "stack_msgs.h"
#include "MMI_include.h"
#ifdef __MMI_AGPS_OTAP__
#if defined(__AGPS_SUPPORT__) && defined(__SUPL_SUPPORT__)
extern "C"
{
#include "GlobalConstants.h"
#include "custom_events_notify.h"
#include "CommonScreens.h"
#include "Conversions.h"
//#include "DataAccountGProt.h"
#include "UcmSrvGprot.h"
#include "CcaSrvGProt.h"
#include "Cbm_api.h"

#include "supl2mmi_enums.h"
#include "supl2mmi_struct.h"
#endif
#include "App_url.h"

#include "stack_common.h"
#include "mdi_datatype.h"
#include "Mdi_gps.h"

#include "GPSGProt.h"
#include "mmi_rp_srv_gps_def.h"
#include "mmi_frm_queue_gprot.h"

#include "gpssetting.h"
}

#include "vcp_include.h"
#include "vfx_mc_include.h"
#include "vfx_app_scr.h"
#include "Vapp_cca_gprot.h"

#include "vapp_gps_agpssuplotap.h"
#include "mmi_rp_vapp_cca_def.h"
#include "vapp_gpssetting.h"

static const U16 cca_mapping_supl[] =
{
    CCA_NS_TRIGNODE, CCA_NS_OMA_BOOTSTRAP, MMI_SUPL_NS_OMA_BOOTSTRAP, 0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, MMI_SUPL_NS_OMA_PROXY, 0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, MMI_SUPL_NS_OMA_APP, 0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, CCA_NS_OMA_APPADDR, MMI_SUPL_NS_OMA_APPADDR, 0xFFFF,
};


static vapp_gps_suplota_context_struct *g_vapp_gps_suplota_context_p = NULL;
U16 g_profile_name[NVRAM_EF_AGPS_PROFILE_TOTAL][AGPS_MAX_PROFILE_NAME_LEN];

extern "C" kal_bool applib_is_valid_url_wchar(kal_wchar ch);

static MMI_BOOL vcui_gps_suplota_check_valid_addr(char *string);
static S16 vapp_gps_suplota_get_proxy_index(const CHAR *px_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_rtsp_handle_app_configure
 * DESCRIPTION
 *
 * PARAMETERS
 *  newconfigdoc   [IN]
 * RETURNS
 *  void.
 *****************************************************************************/
extern "C" void mmi_supl_handle_app_configure(mmi_cca_app_configure_ind_struct *newconfigdoc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT (g_vapp_gps_suplota_context_p == NULL);
    vapp_gps_suplota_init(newconfigdoc);
    g_vapp_gps_suplota_context_p->cur_gid = GRP_ID_ROOT;
    vapp_gps_suplota_handle_ota(newconfigdoc);
}


/*****************************************************************************
 * FUNCTION
 *  vapp_gps_suplota_init
 * DESCRIPTION
 *  Initialize OTA structure
 * PARAMETERS
 *  ind         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_gps_suplota_init(mmi_cca_app_configure_ind_struct *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT (g_vapp_gps_suplota_context_p == NULL);
    g_vapp_gps_suplota_context_p = (vapp_gps_suplota_context_struct*) OslMalloc(sizeof(vapp_gps_suplota_context_struct));
    kal_mem_set(g_vapp_gps_suplota_context_p, 0, sizeof(vapp_gps_suplota_context_struct));
    g_vapp_gps_suplota_context_p->config_id = ind->config_id;
    g_vapp_gps_suplota_context_p->config_handle = ind->hConfig;
    g_vapp_gps_suplota_context_p->sim_id = ind->sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_gps_suplota_handle_ota
 * DESCRIPTION
 *  handle CCA document
 * PARAMETERS
 *  ind         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_gps_suplota_handle_ota(mmi_cca_app_configure_ind_struct *ind)
{
#if(MMI_SIM_TOTAL > 1)
    MMI_BOOL is_sim_card_valid = MMI_FALSE;
#endif

    if (ind == NULL)
    {
        return;
    }

    if (ind->prov_type != MMI_CCA_PROV_TYPE_OTA_PROV)
    {
        vcui_gps_suplota_send_cca_conf_rsp(CCA_STATUS_INVALID_SETTING);
        return;
    }

	/*
#if(MMI_SIM_TOTAL > 3)
    if (g_vapp_gps_suplota_context_p->sim_id == MMI_SIM4)
    {
       is_sim_card_valid = MMI_TRUE;
    }
#endif

#if(MMI_SIM_TOTAL > 2)
    if (g_vapp_gps_suplota_context_p->sim_id == MMI_SIM3)
    {
       is_sim_card_valid = MMI_TRUE;
    }
#endif
*/
#if(MMI_SIM_TOTAL > 1)
    if (g_vapp_gps_suplota_context_p->sim_id == MMI_SIM2 || g_vapp_gps_suplota_context_p->sim_id == MMI_SIM1)
    {
       is_sim_card_valid = MMI_TRUE;
    }

    if (is_sim_card_valid == MMI_FALSE)
    {
        vcui_gps_suplota_send_cca_conf_rsp(CCA_STATUS_INVALID_SETTING);
		return;
    }
#endif

    mmi_cca_doc_process(
        ind->hConfig,
        cca_mapping_supl,
        sizeof(cca_mapping_supl) / sizeof(U16),
        NULL,
        vapp_gps_suplota_process_callback_nodes,
        NULL);

    vapp_gps_suplota_is_valid_info();
}


/*****************************************************************************
 * FUNCTION
 *  vapp_gps_suplota_process_callback_nodes
 * DESCRIPTION
 *  The node callback function used when processing a CCA document.
 * PARAMETERS
 *  hConfig             [IN]        Configuration document handle
 *  hNode               [IN]        The node handle
 *  node_symbol         [IN]        The converted node symbol
 *  iter_datalist       [IN]        List of parameters in the node
 *  user_data           [IN]        User data
 * RETURNS
 *  result of processing CCA nodes.
 *  On success, return CCA_STATUS_OK;
 *  If there is no empty ota profile return CCA_STATUS_FAIL;
 *  Otherwise, return CCA_STATUS_FAIL.
 *****************************************************************************/
static cca_status_enum vapp_gps_suplota_process_callback_nodes(
                    S32 hConfig,
                    S32 hNode,
                    U16 node_symbol,
                    cca_iterator_struct *iter_datalist,
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_status_enum status = CCA_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (node_symbol)
    {
        case MMI_SUPL_NS_OMA_BOOTSTRAP:
            vapp_gps_suplota_parse_bootstrap(iter_datalist, user_data);
            break;

        case MMI_SUPL_NS_OMA_PROXY:
            vapp_gps_suplota_parse_proxy(iter_datalist, user_data);
            break;

        case MMI_SUPL_NS_OMA_APP:
            vapp_gps_suplota_parse_app(iter_datalist, user_data);
            break;

        case MMI_SUPL_NS_OMA_APPADDR:
            vapp_gps_suplota_parse_appaddr(iter_datalist, user_data);
            break;

        default:
            break;
    }

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_gps_suplota_parse_bootstrap
 * DESCRIPTION
 *  The function used to parse bootstrap node.
 * PARAMETERS
 *  iter_datalist       [IN]        List of parameters in the node
 *  user_data           [IN]        User data
 * RETURNS
 *  result of processing CCA nodes.
 *  On success, return CCA_STATUS_OK;
 *  Otherwise, return CCA_STATUS_FAIL.
 *****************************************************************************/
static cca_status_enum vapp_gps_suplota_parse_bootstrap(
                    cca_iterator_struct *iter_datalist,
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_status_enum status = CCA_STATUS_OK;
    CHAR **provurl;
    S32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = mmi_cca_doc_get_nodedata_strs(iter_datalist, CCA_NS_OMA_PROVURL, &provurl, &size);

    /* one bootstap should only include one provurl or no provurl */
    if (status != CCA_STATUS_OK || size > 1)
    {
        return CCA_STATUS_FAIL;
    }

    mmi_cca_generate_hash_value((CHAR*)provurl[0], g_vapp_gps_suplota_context_p->provurl,
        CCA_HASH_VALUE_MAX_BYTES);

    mmi_cca_iterator_restart(iter_datalist);
    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_gps_suplota_parse_proxy
 * DESCRIPTION
 *  The function used to parse proxy node.
 *  fill proxy_id(hash) or sap_id(hash) or data_account
 * PARAMETERS
 *  iter_datalist       [IN]        List of parameters in the node
 *  user_data           [IN]        User data
 * RETURNS
 *  result of processing CCA nodes.
 *  On success, return CCA_STATUS_OK;
 *  Otherwise, return CCA_STATUS_FAIL.
 *****************************************************************************/
static cca_status_enum vapp_gps_suplota_parse_proxy(
                    cca_iterator_struct *iter_datalist,
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *data;
    cca_status_enum status = CCA_STATUS_OK;
    char **px_id;
    S32 size;
    S16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = vapp_gps_suplota_get_empty_item_index();
    if (index == NVRAM_EF_AGPS_PROFILE_TOTAL * g_vapp_gps_suplota_context_p->sim_id)
    {
        return CCA_STATUS_FAIL;
    }
    g_vapp_gps_suplota_context_p->curr_index = index;

    status = mmi_cca_doc_get_nodedata_strs(iter_datalist, CCA_NS_OMA_PROXY_ID, &px_id, &size);

    /* one proxy should has only one prxoy id */
    if (status != CCA_STATUS_OK || size != 1)
    {
        return CCA_STATUS_FAIL;
    }
    /* judghe whether this proxy has existed for we only support the first valid proxy for same proxy id */
    if (vapp_gps_suplota_get_proxy_index(px_id[0]) != NVRAM_EF_AGPS_PROFILE_TOTAL * g_vapp_gps_suplota_context_p->sim_id)
    {
        return CCA_STATUS_FAIL;
    }

    mmi_cca_iterator_restart(iter_datalist);

    while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
    {/* get proxy_id(hash),nap_id(hash) or data_account */
        status = vapp_gps_suplota_handle_proxy_params(data, user_data);
        if (status != CCA_STATUS_OK)
        {
            break;
        }
    }

    if (status != CCA_STATUS_OK)
    {
        return status;
    }

    g_vapp_gps_suplota_context_p->profile_list[index].is_used = MMI_TRUE;
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_gps_suplota_handle_proxy_params
 * DESCRIPTION
 *  Handle CCA PROXY node parameters
 * PARAMETERS
 *  data            [IN]        CCA proxy data
 *  user_data       [IN]        User data
 * RETURNS
 *  On success, return CCA_STATUS_OK, otherwise return CCA_STATUS_FAIL
 *****************************************************************************/
static cca_status_enum vapp_gps_suplota_handle_proxy_params(cca_core_data_struct *data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 //   U8 dataacct_type;
    U8 cbm_reg_ret;
    U8 cbm_app_id;
    mmi_supl_profile_struct *prof = &g_vapp_gps_suplota_context_p->profile_list[g_vapp_gps_suplota_context_p->curr_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (data->id)
    {
        case CCA_NS_OMA_PROXY_ID:
            /* Whether the value is presented and the type is legal. */
            if (data->size <= 0 || data->type != CCA_DT_STR)
            {
                return CCA_STATUS_FAIL;
            }

            /* Whether this is a ASCII string. */
            if (!vcui_gps_suplota_is_ascii_string((U8*)data->values.s[0]))
            {
                return CCA_STATUS_FAIL;
            }

            /* Check whether the length of the proxy id is legal. */
            mmi_cca_generate_hash_value((CHAR*)data->values.s[0],
                (U8*)prof->proxy_id,
                CCA_HASH_VALUE_MAX_BYTES);
            break;

        case CCA_NS_OMA_TO_NAPID:
            /* Whether the value is presented and the type is legal. */
            if (data->size <= 0 || data->type != CCA_DT_STR)
            {
                return CCA_STATUS_FAIL;
            }

            /* Whether this is a ASCII string. */
            if (!vcui_gps_suplota_is_ascii_string((U8*)data->values.s[0]))
            {
                return CCA_STATUS_FAIL;
            }

            /* Check whether the length of the proxy id is legal. */
            mmi_cca_generate_hash_value((CHAR*)data->values.s[0],
                (U8*)prof->nap_id,
                CCA_HASH_VALUE_MAX_BYTES);
            break;

        case CCA_NS_DATAACCTID:
            if (data->size <= 0 || data->type != CCA_DT_INT)
            {
                return CCA_STATUS_FAIL;
            }

           /* dataacct_type = 0;//mmi_dtcnt_get_bearer_type((U8)data->values.i[0]);
            if (dataacct_type & DATA_ACCOUNT_INVALID_ID)
            {
                return CCA_STATUS_FAIL;
            }*/

            //prof->account_id = data->values.i[0];
            /*prof->account_id= cbm_encode_data_account_id(
                data->values.i[0],
                CBM_SIM_ID_SIM1,
                imps_p->gen_info.cbm_app_id,
                FALSE);*/
			cbm_reg_ret = cbm_register_app_id(&cbm_app_id);
			if(cbm_reg_ret == CBM_OK){
    			switch (g_vapp_gps_suplota_context_p ->sim_id)
    			{
    /*			#if(MMI_SIM_TOTAL > 3)
					case MMI_SIM4:
        				prof->account_id = cbm_encode_data_account_id(
                			(U32)data->values.i[0],
                			CBM_SIM_ID_SIM4,
                			cbm_app_id,
                			MMI_FALSE);
					break;
				#endif
				#if(MMI_SIM_TOTAL > 2)
					case MMI_SIM3:
        				prof->account_id = cbm_encode_data_account_id(
                			(U32)data->values.i[0],
                			CBM_SIM_ID_SIM3,
                			cbm_app_id,
                			MMI_FALSE);
					break;
				#endif */
				#if(MMI_SIM_TOTAL > 1)
					case MMI_SIM2:
        				prof->account_id = cbm_encode_data_account_id(
                			(U32)data->values.i[0],
                			CBM_SIM_ID_SIM2,
                			cbm_app_id,
                			MMI_FALSE);
					break;
				#endif
					default:
        				prof->account_id = cbm_encode_data_account_id(
                			(U32)data->values.i[0],
                			CBM_SIM_ID_SIM1,
                			cbm_app_id,
                			MMI_FALSE);
					break;
    			}
			}
            break;

        default:
            break;
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_gps_suplota_parse_app
 * DESCRIPTION
 *  The function used to parse app node.
 *  search usable proxy_id(both in profile and node) and fill name
 * PARAMETERS
 *  iter_datalist       [IN]        List of parameters in the node
 *  user_data           [IN]        User data
 * RETURNS
 *  result of processing CCA nodes.
 *  On success, return CCA_STATUS_OK;
 *  Otherwise, return CCA_STATUS_FAIL.
 *****************************************************************************/
static cca_status_enum vapp_gps_suplota_parse_app(
                    cca_iterator_struct *iter_datalist,
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *data;
    char **px_id;
    S32 size;
    cca_status_enum status = CCA_STATUS_OK;
    S16 index = -1;
    U8 i;
    U8 j;
    MMI_BOOL same_proxy = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = mmi_cca_doc_get_nodedata_strs(iter_datalist, CCA_NS_OMA_TO_PROXY, &px_id, &size);

    /* exist related proxy */
    if (status != CCA_STATUS_OK)
    {
        return CCA_STATUS_FAIL;
    }

    for (i = 0; i < size; i++)
    {
        /* judge whether this app include same proxy id */
        for (j = 0; j < i; j++)
        {
            if (strcmp(px_id[j], px_id[i]) == 0)
            {
                same_proxy = MMI_TRUE;
                break;
            }
        }
        /* the app node has include this proxy node */
        if (same_proxy)
        {
            continue;
        }

        index = vapp_gps_suplota_get_proxy_index(px_id[i]);
        if (index == NVRAM_EF_AGPS_PROFILE_TOTAL * g_vapp_gps_suplota_context_p->sim_id)
        {
            continue;
        }
        g_vapp_gps_suplota_context_p->curr_index = index;

        mmi_cca_iterator_restart(iter_datalist);

        while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
        {
            status = vapp_gps_suplota_handle_app_params(data, user_data);
            if (status != CCA_STATUS_OK)
            {
                break;
            }
        }

        g_vapp_gps_suplota_context_p->profile_list[index].wait_fill_addr = MMI_TRUE;
    }

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_gps_suplota_handle_app_params
 * DESCRIPTION
 *  Handle CCA application node parameters
 * PARAMETERS
 *  data            [IN]        CCA proxy data
 *  user_data       [IN]        User data
 * RETURNS
 *  On success, return CCA_STATUS_OK, otherwise return CCA_STATUS_FAIL
 *****************************************************************************/
static cca_status_enum vapp_gps_suplota_handle_app_params(cca_core_data_struct *data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (data->id)
    {
        case CCA_NS_OMA_NAME:
            /* Whether the value is presented and the type is legal. If it's
               illegal, default name will be used. Still return OK. */
            if (data->size <= 0 || data->type != CCA_DT_STR)
            {
                return CCA_STATUS_FAIL;   /* Error-tolerant for profile's name */
            }

            /* Extract the profile's name. If the name is too long, it will be
               truncated by the function. */
            mmi_chset_utf8_to_ucs2_string(
                (U8*)g_vapp_gps_suplota_context_p->profile_list[g_vapp_gps_suplota_context_p->curr_index].name,
                AGPS_MAX_PROFILE_NAME_LEN * ENCODING_LENGTH,
                (U8*)data->values.s[0]);
            break;

        default:
            break;
    }
    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_gps_suplota_parse_appaddr
 * DESCRIPTION
 *  The function used to parse app addr node.
 *  fill profile->addr
 * PARAMETERS
 *  iter_datalist       [IN]        List of parameters in the node
 *  user_data           [IN]        User data
 * RETURNS
 *  On success, return CCA_STATUS_OK, otherwise return CCA_STATUS_FAIL
 *****************************************************************************/
static cca_status_enum vapp_gps_suplota_parse_appaddr(
                    cca_iterator_struct *iter_datalist,
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *data;
    cca_status_enum status = CCA_STATUS_OK;
    U8 i;
    U8 pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pos = NVRAM_EF_AGPS_PROFILE_TOTAL * (g_vapp_gps_suplota_context_p->sim_id - 1);
    for (i = pos; i < NVRAM_EF_AGPS_PROFILE_TOTAL + pos; i++)
//    for (i = 0; i < NVRAM_EF_AGPS_PROFILE_TOTAL; i++)
    {
        if (g_vapp_gps_suplota_context_p->profile_list[i].wait_fill_addr)
        {
            g_vapp_gps_suplota_context_p->profile_list[i].addr_type_valid = MMI_FALSE;
        }
    }
    mmi_cca_iterator_restart(iter_datalist);

    while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
    {
        status = vapp_gps_suplota_handle_appaddr_params(data, user_data);
        if (status != CCA_STATUS_OK)
        {
            break;
        }
    }

    pos = NVRAM_EF_AGPS_PROFILE_TOTAL * (g_vapp_gps_suplota_context_p->sim_id - 1);
    for (i = pos; i < NVRAM_EF_AGPS_PROFILE_TOTAL + pos; i++)
   // for (i = 0; i < NVRAM_EF_AGPS_PROFILE_TOTAL; i++)
    {
        if (g_vapp_gps_suplota_context_p->profile_list[i].wait_fill_addr)
        {
            if (!g_vapp_gps_suplota_context_p->profile_list[i].addr_type_valid)
            {
                g_vapp_gps_suplota_context_p->profile_list[i].is_used = MMI_FALSE;
            }
            else
            {
                g_vapp_gps_suplota_context_p->profile_list[i].wait_fill_addr = MMI_FALSE;
            }
        }
    }

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_gps_suplota_handle_appaddr_params
 * DESCRIPTION
 *  Handle CCA application address node parameters
 * PARAMETERS
 *  data            [IN]        CCA proxy data
 *  user_data       [IN]        User data
 * RETURNS
 *  On success, return CCA_STATUS_OK, otherwise return CCA_STATUS_FAIL
 *****************************************************************************/
static cca_status_enum vapp_gps_suplota_handle_appaddr_params(cca_core_data_struct *data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    cca_status_enum result;
//    CHAR *value = NULL;
//    U32 src_end_pos;
    U8 i;
    U8 pos;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (data->id)
    {
        case CCA_NS_OMA_ADDR:
            /* Whether this is a ASCII string. */
            if (!vcui_gps_suplota_is_ascii_string((U8*)data->values.s[0]))
            {
                return CCA_STATUS_FAIL;
            }

            if (/*applib_url_is_valid((const char *)value) != 0 ||*/
               vcui_gps_suplota_check_valid_addr((char*)data->values.s[0]))
            {
                return CCA_STATUS_FAIL;
            }

	     pos = NVRAM_EF_AGPS_PROFILE_TOTAL * (g_vapp_gps_suplota_context_p->sim_id - 1);
	     for (i = pos; i < NVRAM_EF_AGPS_PROFILE_TOTAL + pos; i++)
            //for (i = 0; i < NVRAM_EF_AGPS_PROFILE_TOTAL; i++)
            {
                if (g_vapp_gps_suplota_context_p->profile_list[i].wait_fill_addr)
                {
                    kal_wsprintf((WCHAR*)g_vapp_gps_suplota_context_p->profile_list[i].addr, "%s", data->values.s[0]);
                }
            }
            break;

        case CCA_NS_OMA_ADDRTYPE:
	    pos = NVRAM_EF_AGPS_PROFILE_TOTAL * (g_vapp_gps_suplota_context_p->sim_id - 1);
	    for (i = pos; i < NVRAM_EF_AGPS_PROFILE_TOTAL + pos; i++)
            //for (i = 0; i < NVRAM_EF_AGPS_PROFILE_TOTAL; i++)
            {
                if (g_vapp_gps_suplota_context_p->profile_list[i].wait_fill_addr)
                {
                    g_vapp_gps_suplota_context_p->profile_list[i].addr_type_valid = MMI_TRUE;
                }
            }
            break;

        default:
            break;
    }
    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_gps_suplota_is_valid_info
 * DESCRIPTION
 *  This function used to judge whether profile is valid.
 *  For OTA, prompt user IMPS_PROF_COUNT profile that may be invalid.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_gps_suplota_is_valid_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 pos;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vapp_gps_suplota_context_p->count = 0;

    pos = NVRAM_EF_AGPS_PROFILE_TOTAL * (g_vapp_gps_suplota_context_p->sim_id - 1);
    for (i = pos; i < 1 + pos; i++)
    //for (i = 0; i < NVRAM_EF_AGPS_PROFILE_TOTAL; i++)
    {
        if (vapp_gps_suplota_check_one_profile(i))
        {
            g_vapp_gps_suplota_context_p->count++;
        }
    }

    if (0 == g_vapp_gps_suplota_context_p->count)
    {
        vcui_gps_suplota_send_cca_conf_rsp(CCA_STATUS_INVALID_SETTING);
        if (g_vapp_gps_suplota_context_p == NULL)
        {
            return;
        }

        OslMfree(g_vapp_gps_suplota_context_p);
        g_vapp_gps_suplota_context_p = NULL;
        return;
    }

    for (i = pos; i < NVRAM_EF_AGPS_PROFILE_TOTAL + pos; i++)
    //for (i = 0; i < NVRAM_EF_AGPS_PROFILE_TOTAL; i++)
    {
        if (g_vapp_gps_suplota_context_p->profile_list[i].is_used)
        {
            g_vapp_gps_suplota_context_p->curr_index = i;
            break;
        }
    }

    vapp_gps_suplota_entry_ota_setting();
}


/*****************************************************************************
 * FUNCTION
 *  vapp_gps_suplota_check_one_profile
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL vapp_gps_suplota_check_one_profile(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 pos;
    S32 len;
    U8 is_em_setting_on;
//    S16 error;
    MMI_BOOL is_null;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pos = NVRAM_EF_AGPS_PROFILE_TOTAL * (g_vapp_gps_suplota_context_p->sim_id - 1);
    if (g_vapp_gps_suplota_context_p->profile_list[index].is_used)
    {
        /*if (g_vapp_gps_suplota_context_p->profile_list[index].account_id < 0)
        {
            g_vapp_gps_suplota_context_p->profile_list[index].is_used = MMI_FALSE;
            return MMI_FALSE;
        }*/

        len = mmi_ucs2strlen((CHAR *)g_vapp_gps_suplota_context_p->profile_list[index].addr);
        if (len <= 0)
        {
            g_vapp_gps_suplota_context_p->profile_list[index].is_used = MMI_FALSE;
            return MMI_FALSE;
        }
        for (i = 0; i < len; i++)
        {
            if (!applib_is_valid_url_wchar(g_vapp_gps_suplota_context_p->profile_list[index].addr[i]))
            {
                g_vapp_gps_suplota_context_p->profile_list[index].is_used = MMI_FALSE;
                return MMI_FALSE;
            }
        }

        g_vapp_gps_suplota_context_p->profile_list[index].match_index = 0xff;
        g_vapp_gps_suplota_context_p->curr_index = index;
    #ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
        is_null = MMI_TRUE;
        for (i = 0; i < MMI_SUPL_OTA_HASH_LEN; i++)
        {
            if (g_vapp_gps_suplota_context_p->provurl[i] != 0)
            {
                is_null = MMI_FALSE;
                break;
            }
        }
    #endif

        is_em_setting_on = mmi_gps_setting_get_em_on_off();
/*      if (is_em_setting_on == 0xff)
        {
            is_em_setting_on = 0;
            WriteRecord(NVRAM_EF_AGPS_EM_SETTING_LID, 1, &is_em_setting_on, NVRAM_EF_AGPS_EM_SETTING_SIZE, &error);
        }
*/
        if (is_em_setting_on)
        {
        #ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
            if (!is_null)
            {
		        for (i = pos; i < NVRAM_EF_AGPS_PROFILE_TOTAL + pos; i++)
                //for (i = 0; i < NVRAM_EF_AGPS_PROFILE_TOTAL; i++)
                {
                    if (vapp_gps_suplota_match_profile(i))
                    {
                        break;
                    }
                }

                if (i != NVRAM_EF_AGPS_PROFILE_TOTAL * g_vapp_gps_suplota_context_p->sim_id)
                {
                    g_vapp_gps_suplota_context_p->profile_list[index].match_index = i;
                }
            }
        #endif
            return MMI_TRUE;
        }

    #ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
	if (is_null || !vapp_gps_suplota_match_profile(0 + pos))
        //if (is_null || !vapp_gps_suplota_match_profile(0))
        {
    #endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
            g_vapp_gps_suplota_context_p->profile_list[index].is_used = MMI_FALSE;
            return MMI_FALSE;
    #ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
        }
        else
        {
          //  g_vapp_gps_suplota_context_p->profile_list[index].match_index = 0;
	        g_vapp_gps_suplota_context_p->profile_list[index].match_index = 0 + pos;
            return MMI_TRUE;
        }
    #endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
    }
    else
    {
        return MMI_FALSE;
    }
}


#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  vapp_gps_suplota_match_profile
 * DESCRIPTION
 *  whether provurl or nap_id are the same(if null check the name)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL vapp_gps_suplota_match_profile(U8 index)
{
    nvram_ef_agps_profile_struct nvram_profile;
    U8 i;
    MMI_BOOL is_null;
    MMI_BOOL ret = MMI_FALSE;

    mmi_gps_setting_get_profile(&nvram_profile);

    is_null = MMI_TRUE;
    for (i = 0; i < MMI_SUPL_OTA_HASH_LEN; i++)
    {
        if (nvram_profile.provurl[i] != 0 || nvram_profile.nap_id[i] != 0)
        {
            is_null = MMI_FALSE;
            break;
        }
    }

    if (is_null)
    {
        if (!mmi_ucs2cmp((CHAR*)nvram_profile.name, (CHAR*)g_vapp_gps_suplota_context_p->profile_list[g_vapp_gps_suplota_context_p->curr_index].name))
        {
            ret = MMI_TRUE;
        }
    }
    else
    {
        ret = MMI_TRUE;
        for (i = 0; i < MMI_SUPL_OTA_HASH_LEN; i++)
        {
            if (nvram_profile.provurl[i] != g_vapp_gps_suplota_context_p->provurl[i] ||
                nvram_profile.nap_id[i] != g_vapp_gps_suplota_context_p->profile_list[g_vapp_gps_suplota_context_p->curr_index].nap_id[i])
            {
                ret = MMI_FALSE;
                break;
            }
        }
    }

    return ret;
}
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  vapp_gps_suplota_entry_ota_setting
 * DESCRIPTION
 *  Entry function for screen that display OTA information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_gps_suplota_entry_ota_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_id = vcui_gps_cca_install_create(GRP_ID_ROOT);
    g_vapp_gps_suplota_context_p->cui_id = cui_id;
    vcui_gps_cca_install_set_param(cui_id,NULL,NULL);
    vcui_gps_cca_install_run(cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  vapp_gps_suplota_string
 * DESCRIPTION
 *  Compose OTA information string
 * PARAMETERS
 *  buffer      [IN/OUT]        Store string of OTA information
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_gps_suplota_string(char *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR uc2_temp[200];
    U8 i;
    U8 pos;
    U8 index ;

    mmi_supl_profile_struct *prof = &g_vapp_gps_suplota_context_p->profile_list[g_vapp_gps_suplota_context_p->curr_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* instant message */
    //mmi_ucs2cpy(buffer, GetString(STR_ID_CCA_SUPL));
    mmi_ucs2cpy(buffer, (CHAR*)L"");
    mmi_ucs2cat(buffer, GetString(STR_ID_GPS_SETTING_AGPS));
    mmi_ucs2cat(buffer, (CHAR*)L"\n");

    /* profile index */
    pos = NVRAM_EF_AGPS_PROFILE_TOTAL * (g_vapp_gps_suplota_context_p->sim_id - 1);
    index = g_vapp_gps_suplota_context_p->curr_index - pos;
    for (i = 0 + pos; i < g_vapp_gps_suplota_context_p->curr_index; i++)
    {
        if (g_vapp_gps_suplota_context_p->profile_list[i].is_used)
        {
            continue;
        }

        index--;
    }
    kal_wsprintf((WCHAR *)uc2_temp, "%d/%d", index + 1, g_vapp_gps_suplota_context_p->count);

    mmi_ucs2cat(buffer, GetString(STR_ID_GPS_SETTING_AGPS_PROFILE));
    mmi_ucs2cat(buffer, GetString(STR_ID_GPS_SETTING_COLON));
    mmi_ucs2cat(buffer, (CHAR*) L" ");
    mmi_ucs2cat(buffer, uc2_temp);
    mmi_ucs2cat(buffer, (CHAR*)L"\n");

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    if (g_vapp_gps_suplota_context_p->profile_list[index].match_index != 0xFF)
    {
        mmi_ucs2cat(buffer, GetString(STR_ID_VAPP_CCA_UPDATE_PROFILE));
        mmi_ucs2cat(buffer, (CHAR*)L"\n");
    }
#endif

    mmi_ucs2cat(buffer, (CHAR*)L"\n");

    /* profile name */
    if (prof->name[0])
    {
        mmi_ucs2cat(buffer, GetString(STR_ID_GPS_SETTING_AGPS_PROFILE_NAME));
        mmi_ucs2cat(buffer, GetString(STR_ID_GPS_SETTING_COLON));
        mmi_ucs2cat(buffer, (CHAR*) L" ");
        mmi_ucs2cat(buffer, (CHAR*)(prof->name));
        mmi_ucs2cat(buffer, (CHAR*)L"\n");
    }

    /* profile addr */
    if (prof->addr[0])
    {
        mmi_ucs2cat(buffer, GetString(STR_GLOBAL_ADDRESS));
        mmi_ucs2cat(buffer, GetString(STR_ID_GPS_SETTING_COLON));
        mmi_ucs2cat(buffer, (CHAR*) L" ");
        mmi_ucs2cat(buffer, (CHAR*)(prof->addr));
        mmi_ucs2cat(buffer, (CHAR*)L"\n");
    }
}

/*****************************************************************************
 * FUNCTION
 *  vapp_gps_suplota_save_a_profile
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_gps_suplota_save_a_profile(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_agps_profile_struct temp_profile;
    nvram_ef_gps_mmi_sim_struct  temp_sim_setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_gps_setting_get_profile(&temp_profile);
    mmi_gps_setting_get_sim_setting(g_vapp_gps_suplota_context_p->sim_id, &temp_sim_setting);

    mmi_ucs2cpy((CHAR*)temp_profile.name, (CHAR*)g_vapp_gps_suplota_context_p->profile_list[g_vapp_gps_suplota_context_p->curr_index].name);
    if (mmi_ucs2strlen((CHAR*)temp_profile.name)== 0)
    {
        kal_wsprintf(temp_profile.name, "Profile %d", index + 1);
    }

    mmi_ucs2cpy((CHAR*)temp_profile.addr, (CHAR*)g_vapp_gps_suplota_context_p->profile_list[g_vapp_gps_suplota_context_p->curr_index].addr);
    temp_sim_setting.data_account = g_vapp_gps_suplota_context_p->profile_list[g_vapp_gps_suplota_context_p->curr_index].account_id;
    temp_profile.port = 7275;

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    memcpy(
        temp_profile.provurl,
        g_vapp_gps_suplota_context_p->provurl,
        sizeof(U8) * MMI_SUPL_OTA_HASH_LEN);
    memcpy(
        temp_profile.nap_id,
        g_vapp_gps_suplota_context_p->profile_list[g_vapp_gps_suplota_context_p->curr_index].nap_id,
        sizeof(U8) * MMI_SUPL_OTA_HASH_LEN);
#endif

    mmi_gps_setting_set_profile(&temp_profile);
    mmi_gps_setting_set_sim_setting(g_vapp_gps_suplota_context_p->sim_id, &temp_sim_setting);
}


///*****************************************************************************
// * FUNCTION
// *  mmi_supl_entry_ota_prof_list
// * DESCRIPTION
// *  Entry screen for list profiles
// * PARAMETERS
// *  void
// * RETURNS
// *  void
// *****************************************************************************/
//static void vcui_gps_suplota_entry_ota_prof_list(void)
//{
//    /*----------------------------------------------------------------*/
//    /* Local Variables                                                */
//    /*----------------------------------------------------------------*/
//
//    /*----------------------------------------------------------------*/
//    /* Code Body                                                      */
//    /*----------------------------------------------------------------*/
//}

/*****************************************************************************
 * FUNCTION
 *  vapp_gps_suplota_select
 * DESCRIPTION
 *  Select overwrite one existing profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_gps_suplota_select(void)
{
    vapp_gps_suplota_save_a_profile(0);
    g_vapp_gps_suplota_context_p->is_install= MMI_TRUE;
    vapp_gps_suplota_check_next_profile();
}

/*****************************************************************************
 * FUNCTION
 *  vapp_gps_suplota_get_empty_item_index
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
static S16 vapp_gps_suplota_get_empty_item_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    S16 pos;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pos = NVRAM_EF_AGPS_PROFILE_TOTAL * (g_vapp_gps_suplota_context_p->sim_id - 1);
    for (i = pos; i < NVRAM_EF_AGPS_PROFILE_TOTAL + pos; i++)
    //for (i = 0; i < NVRAM_EF_AGPS_PROFILE_TOTAL; i++)
    {
        if (g_vapp_gps_suplota_context_p->profile_list[i].is_used == MMI_FALSE)
        {
            break;
        }
    }

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_gps_suplota_get_proxy_index
 * DESCRIPTION
 *  Find relevant profile according proxy_id that relate proxy with application.
 * PARAMETERS
 *  px_id       [IN]        ID used to relate proxy with application
 * RETURNS
 *  If find related profile succesfully, return index of profile.
 *  otherwise return 0xFF.
 *****************************************************************************/
static S16 vapp_gps_suplota_get_proxy_index(const CHAR *px_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    U8 temp_id[MMI_SUPL_OTA_HASH_LEN] = {0};
    S16 pos;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_vapp_gps_suplota_context_p != NULL);

    mmi_cca_generate_hash_value(px_id, (U8*)temp_id, CCA_HASH_VALUE_MAX_BYTES);

    pos = NVRAM_EF_AGPS_PROFILE_TOTAL * (g_vapp_gps_suplota_context_p->sim_id - 1);
    for (i = pos; i < NVRAM_EF_AGPS_PROFILE_TOTAL + pos; i++)
    //for (i = 0; i < NVRAM_EF_AGPS_PROFILE_TOTAL; i++)
    {
        if (g_vapp_gps_suplota_context_p->profile_list[i].is_used)
        {
            if (memcmp(g_vapp_gps_suplota_context_p->profile_list[i].proxy_id, temp_id,
                CCA_HASH_VALUE_MAX_BYTES) == 0)
            {
                break;
            }
        }
    }

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  vcui_gps_suplota_send_cca_conf_rsp
 * DESCRIPTION
 *  This function sends the response message back to CCA for the result of
 *  configuration. Once application sends this primitive, no further access
 *  to the configuration document should be made.
 * PARAMETERS
 *  status      [IN]        Configuration result
 * RETURNS
 *  void
 *****************************************************************************/
static void vcui_gps_suplota_send_cca_conf_rsp(cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_cca_app_configure_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (mmi_cca_app_configure_rsp_struct*) OslConstructDataPtr(
                                                sizeof(mmi_cca_app_configure_rsp_struct));

    data->config_id = g_vapp_gps_suplota_context_p->config_id;
    data->hConfig = g_vapp_gps_suplota_context_p->config_handle;
    data->status = status;
    data->sim_id = g_vapp_gps_suplota_context_p->sim_id;

    /* Send the response message. */
    message.oslSrcId = MOD_MMI;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_MMI_CCA_APP_CONFIGURE_RSP;
    message.oslDataPtr = (oslParaType*) data;
    message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  vcui_gps_suplota_is_ascii_string
 * DESCRIPTION
 *  This function checks whether the input UTF-8 encoded string is an ASCII
 *  string.
 * PARAMETERS
 *  utf8_str        [IN]        Input UTF-8 encoded string
 * RETURNS
 *  If input string is ASCII string, return TRUE. Otherwise, return FALSE.
 *****************************************************************************/
static MMI_BOOL vcui_gps_suplota_is_ascii_string(const U8 *utf8_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If this is an ASCII string, each octet should be an ASCII character. */
    for (; *utf8_str != '\0'; ++utf8_str)
    {
        if (*utf8_str > 0x7F)
        {
            return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  vcui_gps_suplota_check_valid_addr
 * DESCRIPTION
 *  This function is used for checking whether the given string contains any
 *  white spaces or not
 * PARAMETERS
 *  string      [OUT]       String in asscii
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL vcui_gps_suplota_check_valid_addr(char *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(string);

    /* string length check */
    if (strlen(string) == 0 || strlen(string) >= AGPS_MAX_PROFILE_ADDR_LEN)
    {
        return MMI_FALSE;
    }

    /* white space / tab / ooxx invalid words check */
    for (index = 0; index < strlen((char*) string); index ++)
    {
        if ((string[index] == 9) ||
            (string[index] == 10) ||
            (string[index] == 13 ) ||
            (string[index] == 32 ))
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_gps_suplota_install_status
 * DESCRIPTION
 *  This function used to judge which status will be send to CCA.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_gps_suplota_install_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 curr_scr = GetActiveScreenId();
    mmi_id cur_gid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_vapp_gps_suplota_context_p)
    {
        return;
    }
    cur_gid = g_vapp_gps_suplota_context_p->cui_id;
    if (g_vapp_gps_suplota_context_p->is_update)
    {
        vcui_gps_suplota_send_cca_conf_rsp(CCA_STATUS_SETTING_UPDATED);
	vapp_gps_setting_profile_set();
    }
    else if (g_vapp_gps_suplota_context_p->is_install)
    {
        vcui_gps_suplota_send_cca_conf_rsp(CCA_STATUS_OK);
	vapp_gps_setting_profile_set();
    }
	 else if (g_vapp_gps_suplota_context_p->is_backkey)
    {
        vcui_gps_suplota_send_cca_conf_rsp(CCA_STATUS_ENDKEY_PRESSED);
    }
    else
    {
        vcui_gps_suplota_send_cca_conf_rsp(CCA_STATUS_SETTING_SKIPPED);
		//vcui_gps_cca_install_skip_popup(cur_gid);
    }

    OslMfree(g_vapp_gps_suplota_context_p);
    g_vapp_gps_suplota_context_p = NULL;
    vcui_gps_cca_install_stop(cur_gid);
}


/*****************************************************************************
 * FUNCTION
 *  vapp_gps_suplota_check_next_profile
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_gps_suplota_check_next_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vapp_gps_suplota_context_p->curr_index >= NVRAM_EF_AGPS_PROFILE_TOTAL - 1)
    {
        vapp_gps_suplota_install_status();
    }
    else
    {
        for (i = g_vapp_gps_suplota_context_p->curr_index + 1; i < NVRAM_EF_AGPS_PROFILE_TOTAL; i++)
        {
            if (g_vapp_gps_suplota_context_p->profile_list[i].is_used)
            {
                break;
            }
        }

        if (i != NVRAM_EF_AGPS_PROFILE_TOTAL* g_vapp_gps_suplota_context_p->sim_id)
        {
            g_vapp_gps_suplota_context_p->curr_index = i;
            vapp_gps_suplota_entry_ota_setting();
        }
        else
        {
            vapp_gps_suplota_install_status();
        }
    }
}

/*******************************************************************************
* Export CUI API
*******************************************************************************/
/* Create GPS CUI*/
extern "C" mmi_id vcui_gps_cca_install_create(mmi_id parent_id)
{
	if (parent_id == GRP_ID_ROOT)
	{
		parent_id = vapp_cca_get_parent_id();
	}
    mmi_id cui_id = VfxAppLauncher::createCui(
                                        VCUI_GPS_SETTING_OTAP,
                                        VFX_OBJ_CLASS_INFO(VappGPSSettingOTAPCui),
                                        parent_id);
    return cui_id;
}
extern "C" void vcui_gps_cca_install_set_param(mmi_id cui_id,void(*install)(void), void(*skip)(void))
{

}
extern "C" void vcui_gps_cca_install_run(mmi_id cui_id)
{
    VfxAppLauncher::runCui(cui_id);
}

extern "C" void vcui_gps_cca_install_stop(mmi_id cui_id)
{
    VfxAppLauncher::terminate(cui_id);
}

VFX_IMPLEMENT_CLASS("VappGPSSettingOTAPCui", VappGPSSettingOTAPCui, VfxCui);
void VappGPSSettingOTAPCui::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // create and display main screen
    VappGPSSettingOTAPCuiScr *scr;
    VFX_OBJ_CREATE(scr, VappGPSSettingOTAPCuiScr, this);
	scr->show();
}

VFX_IMPLEMENT_CLASS("VappGPSSettingOTAPCuiScr", VappGPSSettingOTAPCuiScr, VfxMainScr);

void VappGPSSettingOTAPCuiScr::on1stReady()
{
    VfxMainScr::on1stReady();

    // create and display first page
    VappGPSSettingOTAPCuiPage *page;
    VFX_OBJ_CREATE(page, VappGPSSettingOTAPCuiPage, this);
    pushPage(0, page);
}


VFX_IMPLEMENT_CLASS("VappGPSSettingOTAPCuiPage", VappGPSSettingOTAPCuiPage, VfxPage);
void VappGPSSettingOTAPCuiPage::onInit()
{
//	VfxU32 i;
    VfxPage::onInit(); // call base class
    // title bar
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    VfxWString str;
    str.loadFromRes(STR_ID_VAPP_CCA_INSTALL_SETTING);
    titleBar->setTitle(str);
    setTopBar(titleBar);

    VcpTextView *textView;
    VFX_OBJ_CREATE(textView, VcpTextView, this);

    textView->setRect(LEFT_GAPS, TOP_GAPS,getSize().width - LEFT_GAPS - RIGHT_GAPS,getSize().height - TOP_GAPS - BOTTOM_GAPS);

	textView->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    VfxWChar *text;
    VFX_ALLOC_MEM(text, 512, this);
    memset(text, 0x00, 512);
    vapp_gps_suplota_string((char*)text);
    textView->setText(text);
    textView->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
    VFX_FREE_MEM(text);

    VcpToolBar *toolBar;
    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
    str.loadFromRes(STR_GLOBAL_INSTALL);
    toolBar->addItem(INSTALL_PAGE_ID_TOOLBAR_INSTALL, str, IMG_ID_VAPP_CCA_INSTALL);

    str.loadFromRes(STR_ID_VAPP_CCA_SKIP);
    toolBar->addItem(INSTALL_PAGE_ID_TOOLBAR_SKIP, str, IMG_ID_VAPP_CCA_SKIP);
    toolBar->m_signalButtonTap.connect(this, &VappGPSSettingOTAPCuiPage::onToolbarTapped);
    setBottomBar(toolBar);
}

void VappGPSSettingOTAPCuiPage::onQueryRotateEx(
    VfxScreenRotateParam &param)
{
}

void VappGPSSettingOTAPCuiPage::onToolbarTapped(VfxObject* sender, VfxId id)
{
    switch (id)
    {
        case INSTALL_PAGE_ID_TOOLBAR_INSTALL:
			vapp_gps_suplota_select();
            break;
        case INSTALL_PAGE_ID_TOOLBAR_SKIP:
			vapp_gps_suplota_check_next_profile();
			//popupSkipped();
            break;

        default:
            break;
    }
}

void VappGPSSettingOTAPCuiPage::ConfirmSelected(VfxObject* obj, VfxId id)
{
	switch(id)
	{
		case VCP_CONFIRM_POPUP_BUTTON_YES:
			g_vapp_gps_suplota_context_p->is_backkey = MMI_TRUE;
			vapp_gps_suplota_install_status();
			break;
		case VCP_CONFIRM_POPUP_BUTTON_NO:
			break;
	}
}


void VappGPSSettingOTAPCuiPage::onBack()
{
	VcpConfirmPopup *m_cfmPopup;
	VFX_OBJ_CREATE(m_cfmPopup,VcpConfirmPopup,this);
	m_cfmPopup ->setInfoType(VCP_POPUP_TYPE_QUESTION);
	m_cfmPopup ->setText((VfxResId)STR_ID_VAPP_CCA_EXIT_INSTALL_CONFIRM);
	m_cfmPopup ->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
	m_cfmPopup ->m_signalButtonClicked.connect(this, &VappGPSSettingOTAPCuiPage::ConfirmSelected);
	//m_cfmPopup ->setAutoDestory(VFX_TRUE);
	m_cfmPopup ->show(VFX_TRUE);
}


void VappGPSSettingOTAPCui::onInit()
{
    VfxCui::onInit();
}


void VappGPSSettingOTAPCui::onDeinit()
{
    VfxCui::onDeinit();
	/*when exit tell cca status, else cca will not work then*/
	vapp_gps_suplota_install_status();
}

mmi_ret VappGPSSettingOTAPCui::onProc(mmi_event_struct * evt)
{
    return MMI_RET_OK;
}

#endif /* __vapp_gps_suplota__ */

