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
 *  PhbStartupSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements service functions for phb startup procedure.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#include "ProtocolEvents.h"
#include "PhbSrvGprot.h"
#include "PhbSrv.h"

#ifndef __COSMOS_MMI_PACKAGE__
#include "PhoneBookCore.h"
#endif

#include "MMIDataType.h"
#include "MMI_features.h"
#include "kal_general_types.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "mmi_cb_mgr_gprot.h"
#include "stack_config.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "sim_common_enums.h"
#include "mmi_msg_struct.h"
#include "ps_public_enum.h"
#include "ps_public_struct.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "custom_phb_config.h"
#include "PhbSrvIprot.h"
#include "SatSrvGprot.h"
#include "mmi_frm_utility_gprot.h"
#include "MMI_common_app_trc.h"

#define SRV_PHB_STARTUP_PROCEDURE

/* 
 * Typedef
 */
typedef struct
{
    phb_type_enum entry_type[MMI_SIM_TOTAL]; //used for get entry_by_index, PHB_ANR & PHB_FDN
    MMI_BOOL phb_ready;
} srv_phb_startup_cntx_struct;

typedef struct
{
    U16 sim_total;
    U8 sim_id;
    U8 unused;
}srv_phb_startup_finish_cntx_struct;
typedef struct
{
    U8 adn_len;
    U8 fdn_len;
    U8 bdn_len;
    U8 msisdn_len;
#ifdef __MMI_PHB_USIM_SUPPORT__
    U8 email_len;
    U8 aas_len;
    U8 sne_len;
    U8 gas_len;
#endif
    U16 fdn_total;
    U16 bdn_total;
    U16 msisdn_total;
    U8 adn_support;
    U8 fdn_support;
    U8 bdn_support;
    U8 msisdn_support;
    U8 sdn_support;
    U8 ecc_support;
#ifdef __MMI_PHB_STARTUP_COPY_SIM__
    U16 adn_used;
#endif
}srv_phb_startup_sim_cntx_struct;

/* 
 * Local Variable
 */
static srv_phb_startup_cntx_struct g_srv_phb_startup_cntx;
static srv_phb_startup_sim_cntx_struct g_srv_phb_sim_startup_cntx[MMI_SIM_TOTAL];

/* 
 * Local Function
 */
static void srv_phb_startup_begin_ind(void *info, U16 mod_src);
static void srv_phb_startup_finish_ind(void *info, U16 mod_src);

static void srv_phb_startup_read_dial_mode_hdlr(void *user_data);
static void srv_phb_startup_read_fdn_hdlr(void *user_data);
static void srv_phb_startup_sort_name_index_hdlr(void* user_data);
static void srv_phb_startup_build_lookup_table_hdlr(void);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_startup_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(PRT_PHB_STARTUP_BEGIN_IND, (PsIntFuncPtr)srv_phb_startup_begin_ind, MMI_FALSE);
    mmi_frm_set_protocol_event_handler(PRT_PHB_STARTUP_FINISH_IND, (PsIntFuncPtr)srv_phb_startup_finish_ind, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_clear_ready_flag
 * DESCRIPTION
 *  set ready status as false
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_startup_clear_ready_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_srv_phb_startup_cntx.phb_ready = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_send_ready_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  phb_ready       [IN]        
 *  sim_refresh     [IN]        
 *  storage         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_startup_send_ready_event(MMI_BOOL phb_ready, MMI_BOOL sim_refresh, U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_startup_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_STARTUP_SEND_READY_EVENT, phb_ready, sim_refresh, storage);
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_PHB_READY);
    evt.phb_ready = phb_ready;
    evt.sim_refresh = sim_refresh;
    evt.storage = storage;
    MMI_FRM_CB_EMIT_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_begin_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_startup_begin_ind(void *info, U16 mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_startup_begin_ind_struct *local_ptr= (mmi_phb_startup_begin_ind_struct*) info;
    srv_phb_startup_sim_init_cntx cntx;
    sim_interface_enum sim_id = SIM1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&cntx, 0x00, sizeof(srv_phb_startup_sim_init_cntx));
    srv_phb_startup_clear_ready_flag();
    srv_phb_startup_send_ready_event(MMI_FALSE, MMI_FALSE, PHB_STORAGE_NONE);
    sim_id = (sim_interface_enum)(mmi_frm_sim_to_index(mmi_frm_l4c_mod_to_sim((module_type)mod_src)));
    cntx.sim_interface = sim_id;
    g_srv_phb_sim_startup_cntx[sim_id].fdn_total = local_ptr->desc[PHB_FDN - 1].record_num;
    g_srv_phb_sim_startup_cntx[sim_id].fdn_len = local_ptr->desc[PHB_FDN - 1].alpha_length;

#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
    g_srv_phb_sim_startup_cntx[sim_id].bdn_total = local_ptr->desc[PHB_BDN - 1].record_num;
    g_srv_phb_sim_startup_cntx[sim_id].bdn_len = local_ptr->desc[PHB_BDN - 1].alpha_length;
    
    g_srv_phb_sim_startup_cntx[sim_id].msisdn_total = local_ptr->desc[PHB_MSISDN - 1].record_num;
    g_srv_phb_sim_startup_cntx[sim_id].msisdn_len = local_ptr->desc[PHB_MSISDN - 1].alpha_length;
#endif /*__MMI_PHB_SLIM_EXTRA_DEFEATURE__ */
    g_srv_phb_sim_startup_cntx[sim_id].adn_support = local_ptr->desc[PHB_PHONEBOOK - 1].is_support;
    g_srv_phb_sim_startup_cntx[sim_id].adn_len = local_ptr->desc[PHB_PHONEBOOK - 1].alpha_length;
    cntx.total_count = local_ptr->desc[PHB_PHONEBOOK - 1].record_num;

    if (local_ptr->desc[PHB_PHONEBOOK - 1].record_size == 0 ||
        local_ptr->desc[PHB_PHONEBOOK - 1].record_num == 0)
    {
        g_srv_phb_sim_startup_cntx[sim_id].adn_support = 0;
    }
    g_srv_phb_sim_startup_cntx[sim_id].fdn_support = local_ptr->desc[PHB_FDN - 1].is_support;
    if (local_ptr->desc[PHB_FDN - 1].record_size == 0 ||
        local_ptr->desc[PHB_FDN - 1].record_num == 0)
    {
        g_srv_phb_sim_startup_cntx[sim_id].fdn_support = 0;
    }
    
#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
    g_srv_phb_sim_startup_cntx[sim_id].bdn_support = local_ptr->desc[PHB_BDN - 1].is_support;
    if (local_ptr->desc[PHB_BDN - 1].record_size == 0 ||
        local_ptr->desc[PHB_BDN - 1].record_num == 0)
    {
        g_srv_phb_sim_startup_cntx[sim_id].bdn_support = 0;
    }
    g_srv_phb_sim_startup_cntx[sim_id].msisdn_support = local_ptr->desc[PHB_MSISDN - 1].is_support;
    if (local_ptr->desc[PHB_MSISDN - 1].record_size == 0 ||
        local_ptr->desc[PHB_MSISDN - 1].record_num == 0)
    {
        g_srv_phb_sim_startup_cntx[sim_id].msisdn_support = 0;
    }
    g_srv_phb_sim_startup_cntx[sim_id].sdn_support = local_ptr->desc[PHB_SDN - 1].is_support;
    if (local_ptr->desc[PHB_SDN - 1].record_size == 0 ||
        local_ptr->desc[PHB_SDN - 1].record_num == 0)
    {
        g_srv_phb_sim_startup_cntx[sim_id].sdn_support = 0;
    }
    g_srv_phb_sim_startup_cntx[sim_id].ecc_support = local_ptr->desc[PHB_ECC - 1].is_support;
    if (local_ptr->desc[PHB_ECC - 1].record_size == 0 ||
        local_ptr->desc[PHB_ECC - 1].record_num == 0)
    {
        g_srv_phb_sim_startup_cntx[sim_id].ecc_support = 0;
    }
#endif /* __MMI_PHB_SLIM_EXTRA_DEFEATURE__ */

#ifdef __MMI_PHB_USIM_SUPPORT__
    if (local_ptr->desc[PHB_ANR - 1].is_support &&
        local_ptr->desc[PHB_ANR - 1].record_size &&
        local_ptr->desc[PHB_ANR - 1].record_num)
    {
        cntx.anr_count = local_ptr->desc[PHB_ANR - 1].occurrence;
    }
    if (local_ptr->desc[PHB_EMAIL - 1].is_support &&
        local_ptr->desc[PHB_EMAIL - 1].record_size &&
        local_ptr->desc[PHB_EMAIL - 1].record_num)
    {
        g_srv_phb_sim_startup_cntx[sim_id].email_len = local_ptr->desc[PHB_EMAIL - 1].alpha_length;
        cntx.email_count = local_ptr->desc[PHB_EMAIL - 1].occurrence;
    }
    if (local_ptr->desc[PHB_SNE - 1].is_support &&
        local_ptr->desc[PHB_SNE - 1].record_size &&
        local_ptr->desc[PHB_SNE - 1].record_num)
    {
        g_srv_phb_sim_startup_cntx[sim_id].sne_len = local_ptr->desc[PHB_SNE - 1].alpha_length;
        cntx.sne_count = local_ptr->desc[PHB_SNE - 1].occurrence;
    }
    if (local_ptr->desc[PHB_AAS - 1].is_support &&
        local_ptr->desc[PHB_AAS - 1].record_size &&
        local_ptr->desc[PHB_AAS - 1].record_num)
    {
        g_srv_phb_sim_startup_cntx[sim_id].aas_len = local_ptr->desc[PHB_AAS - 1].alpha_length;
        cntx.aas_count = (U8)(local_ptr->desc[PHB_AAS - 1].record_num);
    }
    if (local_ptr->desc[PHB_GAS - 1].is_support &&
        local_ptr->desc[PHB_GAS - 1].record_size &&
        local_ptr->desc[PHB_GAS - 1].record_num)
    {
        g_srv_phb_sim_startup_cntx[sim_id].gas_len = local_ptr->desc[PHB_GAS - 1].alpha_length;
        cntx.gas_count = (U8)(local_ptr->desc[PHB_GAS - 1].record_num);
    }
#endif /* __MMI_PHB_USIM_SUPPORT__ */

    /* Notify SIM1 begin to DataMgr, then DataMgr will begin to read SIM/Phone entries at the same time. */
    srv_phb_datamgr_startup_read_sim_begin(&cntx);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_finish_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_startup_finish_ind(void *info, U16 mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_startup_finish_ind_struct *local_ptr;
    U8 sim_id = 0;
#ifdef __MMI_PHB_STARTUP_COPY_SIM__
    U8 phb_storage;
#endif
    srv_phb_startup_finish_cntx_struct *finish_cntx = srv_phb_mem_malloc(sizeof(srv_phb_startup_finish_cntx_struct), SRV_PHB_MEMORY_TYPE_CTR);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_id = (U8)(mmi_frm_sim_to_index(mmi_frm_l4c_mod_to_sim((module_type)mod_src)));
    local_ptr = (mmi_phb_startup_finish_ind_struct*) info;

    if (g_srv_phb_sim_startup_cntx[sim_id].adn_len > MMI_PHB_NAME_FIELD_LENGTH)
    {
        g_srv_phb_sim_startup_cntx[sim_id].adn_len = MMI_PHB_NAME_FIELD_LENGTH;
    }

#ifdef __MMI_PHB_STARTUP_COPY_SIM__
    phb_storage = srv_phb_get_storage_by_sim_id(sim_id);
    g_srv_phb_sim_startup_cntx[sim_id].adn_used = srv_phb_get_used_contact(phb_storage);
#endif

    finish_cntx->sim_id = sim_id;
    finish_cntx->sim_total = local_ptr->sim_max_num;
    srv_phb_xmgnt_read_dial_mode((sim_interface_enum)sim_id, srv_phb_startup_read_dial_mode_hdlr, finish_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_send_init_res_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_startup_send_init_res_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4c_phb_init_res_req_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr =
        (mmi_l4c_phb_init_res_req_struct*) OslConstructDataPtr(sizeof(mmi_l4c_phb_init_res_req_struct));
    local_ptr->type = PHB_PHONEBOOK;
    local_ptr->storage = PHB_STORAGE_NVRAM;
    local_ptr->total = srv_phb_get_total_contact(PHB_STORAGE_NVRAM);
    local_ptr->used = srv_phb_get_used_contact(PHB_STORAGE_NVRAM);
    local_ptr->free = local_ptr->total - local_ptr->used;
    local_ptr->max_name_len = MMI_PHB_NAME_LENGTH * sizeof(U16);
    local_ptr->max_num_len = MMI_PHB_NUMBER_LENGTH;
    local_ptr->max_mail_len = MMI_PHB_EMAIL_LENGTH;

    mmi_frm_send_ilm(MOD_L4C, PRT_PHB_INIT_RES_REQ, (oslParaType*) local_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_datamgr_ready_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_startup_datamgr_ready_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Notify L4C to get phonebook total/used/free count */
    srv_phb_startup_send_init_res_req();

    
    /* Notify SSE to sort name index */
    if (srv_phb_sse_build_name_index(srv_phb_startup_sort_name_index_hdlr, NULL))
    {
        srv_phb_startup_sort_name_index_hdlr(NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_read_dial_mode_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_startup_read_dial_mode_hdlr(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_startup_finish_cntx_struct *finish_cntx = (srv_phb_startup_finish_cntx_struct *)user_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //srv_phb_xmgnt_set_read_false();
    //srv_phb_sse_clear_fdn_name_index();
    srv_phb_xmgnt_read_fdn_to_ram((sim_interface_enum)(finish_cntx->sim_id), srv_phb_startup_read_fdn_hdlr, user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_read_fdn_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_startup_read_fdn_hdlr(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_startup_finish_cntx_struct* finish_cntx = (srv_phb_startup_finish_cntx_struct*)user_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_phb_datamgr_startup_read_sim_finish(finish_cntx->sim_id, finish_cntx->sim_total);
    srv_phb_mem_free(finish_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_sort_name_index_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_startup_sort_name_index_hdlr(void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_startup_cntx.phb_ready = MMI_TRUE;

    /* Read speed dial info */
#if defined(__MMI_PHB_SPEED_DIAL__)
    srv_phb_speed_dial_init();
#endif

    /* Read VIP contact info */
    #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_WIDGET_KEY_VIP_CONTACT__)
    srv_phb_vip_contact_init();
    #endif
    srv_phb_startup_send_ready_event(MMI_TRUE, MMI_FALSE, PHB_STORAGE_NONE);
    /* Notify SSE to build lookup table */
    #ifdef __VCARD_CLOUD_SUPPORT__
    srv_phb_cloud_init();
    #endif
    srv_phb_sse_build_lookup_table(srv_phb_startup_build_lookup_table_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_build_lookup_table_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_startup_build_lookup_table_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
    srv_phb_tcard_init();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_set_phb_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_startup_set_phb_status(MMI_BOOL status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_startup_cntx.phb_ready = status;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_is_phb_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_phb_startup_is_phb_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_STARTUP_IS_PHB_READY, g_srv_phb_startup_cntx.phb_ready);
    return (MMI_BOOL) g_srv_phb_startup_cntx.phb_ready;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_is_phb_support
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 *  phb_type            [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_phb_startup_is_phb_support(U8 sim_interface, U8 phb_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        switch (phb_type)
        {
        #ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
            case PHB_ECC:
            return (MMI_BOOL) g_srv_phb_sim_startup_cntx[sim_interface].ecc_support;
        #endif /* __MMI_PHB_SLIM_EXTRA_DEFEATURE__ */
            case PHB_FDN:
            return (MMI_BOOL) g_srv_phb_sim_startup_cntx[sim_interface].fdn_support;
        #ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
            case PHB_BDN:
            return (MMI_BOOL) g_srv_phb_sim_startup_cntx[sim_interface].bdn_support;
            case PHB_MSISDN:
            return (MMI_BOOL) g_srv_phb_sim_startup_cntx[sim_interface].msisdn_support;
            case PHB_SDN:
            return (MMI_BOOL) g_srv_phb_sim_startup_cntx[sim_interface].sdn_support;
        #endif /* __MMI_PHB_SLIM_EXTRA_DEFEATURE__ */
            case PHB_PHONEBOOK:
            return (MMI_BOOL) g_srv_phb_sim_startup_cntx[sim_interface].adn_support;
            default:
                break;
        }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_get_alpha_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 *  phb_type            [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_phb_startup_get_alpha_length(U8 sim_interface, U8 phb_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        switch (phb_type)
        {
            case PHB_FDN:
            return g_srv_phb_sim_startup_cntx[sim_interface].fdn_len;
        #ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
            case PHB_BDN:
            return g_srv_phb_sim_startup_cntx[sim_interface].bdn_len;
            case PHB_MSISDN:
            return g_srv_phb_sim_startup_cntx[sim_interface].msisdn_len;
        #endif /* __MMI_PHB_SLIM_EXTRA_DEFEATURE__ */
            case PHB_PHONEBOOK:
                if (g_srv_phb_sim_startup_cntx[sim_interface].adn_len > MMI_PHB_NAME_FIELD_LENGTH)
                {
                    return MMI_PHB_NAME_FIELD_LENGTH;
                }
                else
                {
                    return g_srv_phb_sim_startup_cntx[sim_interface].adn_len;
                }
        #ifdef __MMI_PHB_USIM_SUPPORT__
            case PHB_EMAIL:
                if (g_srv_phb_sim_startup_cntx[sim_interface].email_len > MMI_PHB_EMAIL_LENGTH)
                {
                    return MMI_PHB_EMAIL_LENGTH;
                }
                else
                {
                    return g_srv_phb_sim_startup_cntx[sim_interface].email_len;
                }
                
            case PHB_SNE:
                if (g_srv_phb_sim_startup_cntx[sim_interface].sne_len > MMI_PHB_NAME_FIELD_LENGTH)
                {
                    return MMI_PHB_NAME_FIELD_LENGTH;
                }
                else
                {
                    return g_srv_phb_sim_startup_cntx[sim_interface].sne_len;
                }

                
            case PHB_AAS:
                if (g_srv_phb_sim_startup_cntx[sim_interface].aas_len > MMI_PHB_FIELD_LABEL_LENGTH)
                {
                    return MMI_PHB_FIELD_LABEL_LENGTH;
                }
                else
                {
                    return g_srv_phb_sim_startup_cntx[sim_interface].aas_len;
                }
               case PHB_GAS:
                if (g_srv_phb_sim_startup_cntx[sim_interface].gas_len > MMI_PHB_FIELD_LABEL_LENGTH)
                {
                    return MMI_PHB_FIELD_LABEL_LENGTH;
                }
                else
                {
                    return g_srv_phb_sim_startup_cntx[sim_interface].gas_len;
                }
        #endif
            default:
                break;
        }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_get_fdn_total
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 srv_phb_startup_get_fdn_total(U8 sim_interface)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_phb_sim_startup_cntx[sim_interface].fdn_total;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_get_bdn_total
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 srv_phb_startup_get_bdn_total(U8 sim_interface)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
    return g_srv_phb_sim_startup_cntx[sim_interface].bdn_total;
#else
    return 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_get_msisdn_total
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 srv_phb_startup_get_msisdn_total(U8 sim_interface)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
    return g_srv_phb_sim_startup_cntx[sim_interface].msisdn_total;
#else
    return 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_get_initing_entry_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 * RETURNS
 *  phb_type_enum
 *****************************************************************************/
phb_type_enum srv_phb_startup_get_initing_entry_type(U8 sim_interface)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_phb_startup_cntx.entry_type[sim_interface];
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_get_msisdn_total
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
void srv_phb_startup_set_initing_entry_type(U8 sim_interface, phb_type_enum entry_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_startup_cntx.entry_type[sim_interface] = entry_type;
}


void srv_phb_startup_read_entry_by_index_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_id = srv_phb_get_sim_id_by_mod_id(mod_src);
    phb_type_enum entry_type = srv_phb_startup_get_initing_entry_type(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_PHB_USIM_SUPPORT__
    if (entry_type == PHB_ANR)
    {
        srv_phb_read_anr_rsp(info, mod_src);
    }
    else
    #endif
    if (entry_type == PHB_FDN)
    {
        srv_phb_xmgnt_read_fdn_to_ram_rsp(info, mod_src);
    }
}

#ifdef __MMI_PHB_STARTUP_COPY_SIM__


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_get_adn_used_first
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 srv_phb_startup_get_adn_used_first(U8 sim_interface)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U16 is_first = 0xFFFF;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_interface != SIM1 && sim_interface != SIM2 && sim_interface != SIM3 && sim_interface != SIM4)
    {
        return 0;
    }
    else
    {
        if (is_first == 0xFFFF)
        {
            is_first = g_srv_phb_sim_startup_cntx[sim_interface].adn_used;
        }

        return is_first;
    }
}

#endif /* __MMI_PHB_STARTUP_COPY_SIM__ */

#define SRV_PHB_SAT_HANDLER


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_sat_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_startup_sat_hdlr(U8 sim_interface)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_startup_clear_ready_flag();
    srv_phb_startup_send_ready_event(MMI_FALSE, MMI_TRUE, srv_phb_get_storage_by_sim_id(sim_interface));
}
