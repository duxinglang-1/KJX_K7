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
 *  PhbXmgntSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements service functions for phb extra# mamagement.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
#ifndef PHBXMGNTSRV_C
#define PHBXMGNTSRV_C

#include "ProtocolEvents.h"
#include "PhbSrvGprot.h"
#include "PhbSrv.h"
#include "GSM7BitDefaultAlphabet.h"
#include "CallSetSrvGprot.h"
#include "app_usedetails.h"
#include "PhoneBookGprot.h"
#include "SimCtrlSrvGprot.h"

#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
#endif

#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
#include "HomeScreenOp11V32Gprot.h"
#endif

#include "MMI_features.h"
#include "MMIDataType.h"
#include "ps_public_struct.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "mmi_msg_struct.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "ps_public_enum.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "custom_phb_config.h"
#include "mcd_l4_common.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "PhbSrvIprot.h"
#include "DebugInitDef_Int.h"
#include "mmi_cb_mgr_gprot.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "ps_public_enum.h"
#include "mmi_frm_utility_gprot.h"
#include "FileMgrSrvGprot.h"

#define SRV_PHB_EXTRA_MANAGEMENT

/* 
 * Typedef
 */
typedef struct
{
    U16 read_times;
    U16 sim_list_count;
    srv_phb_xmgnt_entry_struct sim_list[SRV_PHB_XMGNT_SIM_ENTRIES];
} srv_phb_sim_list_struct;

typedef struct
{
    MMI_BOOL is_new;
    U8 is_busy;
    U8 is_busy_ex;
    U8 sim_interface;
    U8 phb_type;
    U16 *name;
    U16 *number;
    srv_phb_xmgnt_callback_type result_callback;
    srv_phb_xmgnt_callback_type_ex result_callback_ex;
    srv_phb_sim_list_struct sim_list;
    l4c_phb_entry_struct sim_entry;
} srv_phb_xmgnt_cntx_struct;

/* 
 * Local Variable
 */
static srv_phb_xmgnt_cntx_struct g_srv_phb_xmgnt_cntx;

/* 
 * Local Function
 */
#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
static void srv_phb_xmgnt_get_list_req(U8 sim_interface, U8 phb_type);
static void srv_phb_xmgnt_get_list_rsp(void *info);
#endif
static void srv_phb_xmgnt_delete_fdn(U8 sim_id, U16 index);
static srv_phb_xmgnt_entry_struct srv_phb_xmgnt_get_fdn_by_index(U16 index);
static void srv_phb_xmgnt_set_fdn(l4c_phb_entry_struct *phb_entry);
static void srv_phb_xmgnt_get_entry_req(U8 sim_interface, U8 phb_type, U16 record_index);
static void srv_phb_xmgnt_get_entry_rsp(void *info);
//static U16 srv_phb_xmgnt_get_fdn_count(U8 sim_interface);
static U16 srv_phb_xmgnt_get_fdn_sort_index(U8 sim_interface, U16 store_index);

static void srv_phb_xmgnt_set_entry_req(
                U8 sim_interface,
                U8 phb_type,
                U16 index,
                U16 record_index,
                U16 *name,
                U16 *number);
static void srv_phb_xmgnt_set_entry_rsp(void *info);

static void srv_phb_xmgnt_delete_entry_req(U8 sim_interface, U8 phb_type, U16 index, U16 record_index);
static void srv_phb_xmgnt_delete_entry_rsp(void *info);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_xmgnt_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_get_list_count
 * DESCRIPTION
 *  This function is used to get extra# list count.
 * PARAMETERS
 *  handle:             [IN]        extra# handle
 * RETURNS
 *  extra# list count
 *****************************************************************************/
U16 srv_phb_xmgnt_get_list_count(SRV_PHB_XMGNT_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_sim_list_struct *sim_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(handle != NULL);
    sim_list = (srv_phb_sim_list_struct*) handle;
    return sim_list->sim_list_count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_get_entry_index
 * DESCRIPTION
 *  This function is used to get entry index by hilight index.
 * PARAMETERS
 *  handle:             [IN]        extra# handle
 *  index:              [IN]        hilight index
 * RETURNS
 *  entry index
 *****************************************************************************/
U16 srv_phb_xmgnt_get_entry_index(SRV_PHB_XMGNT_HANDLE handle, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_sim_list_struct *sim_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(handle != NULL);
    sim_list = (srv_phb_sim_list_struct*) handle;
    return sim_list->sim_list[index].index;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_get_entry_name
 * DESCRIPTION
 *  This function is used to get extra# name by hilight index.
 * PARAMETERS
 *  handle:             [IN]        extra# handle
 *  index:              [IN]        hilight index
 * RETURNS
 *  extra# name
 *****************************************************************************/
U16 *srv_phb_xmgnt_get_entry_name(SRV_PHB_XMGNT_HANDLE handle, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_sim_list_struct *sim_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(handle != NULL);
    sim_list = (srv_phb_sim_list_struct*) handle;
    return sim_list->sim_list[index].alpha_id.name;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_get_entry_number
 * DESCRIPTION
 *  This function is used to get extra# number by hilight index.
 * PARAMETERS
 *  handle:             [IN]        extra# handle
 *  index:              [IN]        hilight index
 * RETURNS
 *  extra# number
 *****************************************************************************/
U16 *srv_phb_xmgnt_get_entry_number(SRV_PHB_XMGNT_HANDLE handle, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_sim_list_struct *sim_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(handle != NULL);
    sim_list = (srv_phb_sim_list_struct*) handle;
    return sim_list->sim_list[index].tel.number;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_get_entry_number_length
 * DESCRIPTION
 *  This function is used to get extra# number length by hilight index.
 * PARAMETERS
 *  handle:             [IN]        extra# handle
 *  index:              [IN]        hilight index
 * RETURNS
 *  extra# number length
 *****************************************************************************/
U8 srv_phb_xmgnt_get_entry_number_length(SRV_PHB_XMGNT_HANDLE handle, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_sim_list_struct *sim_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(handle != NULL);
    sim_list = (srv_phb_sim_list_struct*) handle;
    return sim_list->sim_list[index].tel.length;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_get_list
 * DESCRIPTION
 *  This function is used to get extra# list.
 * PARAMETERS
 *  sim_interface:      [IN]        SIM1/SIM2
 *  phb_type:           [IN]        PHB_ECC/PHB_FDN/PHB_BDN/PHB_MSISDN/PHB_SDN
 *  list_cb:            [IN]        Get extra# list callback
 * RETURNS
 *  extra# handle
 *****************************************************************************/
SRV_PHB_XMGNT_HANDLE srv_phb_xmgnt_get_list(
                        U8 sim_interface,
                        U8 phb_type,
                        srv_phb_xmgnt_callback_type list_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index[MMI_PHB_FDN_ENTRIES];
    U32 i;
    srv_phb_xmgnt_entry_struct fdn;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_xmgnt_cntx.sim_list.sim_list_count = 0;
    memset(index, 0x00, MMI_PHB_FDN_ENTRIES*sizeof (U16));
    switch (phb_type)
    {
        case PHB_FDN:
            srv_phb_sse_get_fdn_by_sim_id(sim_interface, index);
            for (i = 0; i < SRV_PHB_XMGNT_SIM_ENTRIES; i++)
            {
                if (index[i] >= MMI_PHB_ENTRIES && index[i] < MMI_PHB_ENTRIES + MMI_PHB_FDN_TOTAL_ENTRIES)
                {
                    fdn = srv_phb_xmgnt_get_fdn_by_index(index[i]);
                    g_srv_phb_xmgnt_cntx.sim_list.sim_list[i].alpha_id.name_length = fdn.alpha_id.name_length;
                    g_srv_phb_xmgnt_cntx.sim_list.sim_list[i].alpha_id.name_dcs = fdn.alpha_id.name_dcs;
                    mmi_wcsncpy(
                        g_srv_phb_xmgnt_cntx.sim_list.sim_list[i].alpha_id.name,
                        fdn.alpha_id.name,
                        MMI_PHB_NAME_LENGTH
                        );
                    g_srv_phb_xmgnt_cntx.sim_list.sim_list[i].index = fdn.record_index;
                    g_srv_phb_xmgnt_cntx.sim_list.sim_list[i].tel.length = fdn.tel.length;
                    g_srv_phb_xmgnt_cntx.sim_list.sim_list[i].tel.type = fdn.tel.type;
                    mmi_wcsncpy(
                        g_srv_phb_xmgnt_cntx.sim_list.sim_list[i].tel.number,
                        fdn.tel.number,
                        MMI_PHB_NUMBER_PLUS_LENGTH
                        );
                    g_srv_phb_xmgnt_cntx.sim_list.sim_list_count ++;
                }
            }
            break;
#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
    case PHB_ECC:
    case PHB_BDN:
    case PHB_MSISDN:
    case PHB_SDN:
        if (g_srv_phb_xmgnt_cntx.is_busy)
        {
            return NULL;
        }
        g_srv_phb_xmgnt_cntx.is_busy = 1;
        g_srv_phb_xmgnt_cntx.sim_interface = sim_interface;
        g_srv_phb_xmgnt_cntx.phb_type = phb_type;
        g_srv_phb_xmgnt_cntx.result_callback = list_cb;
        g_srv_phb_xmgnt_cntx.sim_list.read_times = 0;
        g_srv_phb_xmgnt_cntx.sim_list.sim_list_count = 0;
        srv_phb_xmgnt_get_list_req(sim_interface, phb_type);
        break;
#endif /* __MMI_PHB_SLIM_EXTRA_DEFEATURE__ */           
    }
    return &g_srv_phb_xmgnt_cntx.sim_list;
}

#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__

/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_get_list_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 *  phb_type            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_xmgnt_get_list_req(U8 sim_interface, U8 phb_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_get_entry_by_index_req_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr =
        (mmi_phb_get_entry_by_index_req_struct*) OslConstructDataPtr(sizeof(mmi_phb_get_entry_by_index_req_struct));
    local_ptr->type = phb_type;
    local_ptr->index =
        (g_srv_phb_xmgnt_cntx.sim_list.read_times++) * PHB_MAX_PHB_ENTRIES + 1;    /* l4phb entry index starts from 1 */
    local_ptr->record_index = 0xFFFF;
    local_ptr->no_data = PHB_MAX_PHB_ENTRIES;
    SetProtocolEventHandler(srv_phb_xmgnt_get_list_rsp, PRT_PHB_GET_ENTRY_BY_INDEX_RSP);
    mmi_frm_send_ilm(mmi_frm_sim_to_l4c_mod(mmi_frm_index_to_sim(sim_interface)), PRT_PHB_GET_ENTRY_BY_INDEX_REQ, (oslParaType*) local_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_get_list_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_xmgnt_get_list_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_get_entry_by_index_rsp_struct *local_ptr;
    U16 i, index;
    U8 number[MMI_PHB_NUMBER_PLUS_LENGTH + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_phb_get_entry_by_index_rsp_struct*) info;

    if (local_ptr->result.flag == L4C_OK)
    {
        for (i = 0; i < local_ptr->no_list; i++)
        {
            if (g_srv_phb_xmgnt_cntx.sim_list.sim_list_count >= SRV_PHB_XMGNT_SIM_ENTRIES)
            {
                break;
            }

            if ((g_srv_phb_xmgnt_cntx.phb_type == PHB_MSISDN) &&
                (g_srv_phb_xmgnt_cntx.sim_list.sim_list_count >= SRV_PHB_XMGNT_OWNER_NUMBERS))
            {
                break;
            }

            if ((g_srv_phb_xmgnt_cntx.phb_type == PHB_ECC) &&
                (g_srv_phb_xmgnt_cntx.sim_list.sim_list_count >= SRV_PHB_XMGNT_SOS_ENTRIES))
            {
                break;
            }

        #ifndef __TC01_LTUI__
            if ((g_srv_phb_xmgnt_cntx.phb_type == PHB_SDN) &&
                (local_ptr->list[i].alpha_id.name_length == 0) && (local_ptr->list[i].tel.length == 0))
        #else
            if ((local_ptr->list[i].alpha_id.name_length == 0) && (local_ptr->list[i].tel.length == 0))
        #endif
            {
                continue;
            }

            index = g_srv_phb_xmgnt_cntx.sim_list.sim_list_count;
            g_srv_phb_xmgnt_cntx.sim_list.sim_list_count++;

            g_srv_phb_xmgnt_cntx.sim_list.sim_list[index].storage = local_ptr->list[i].storage;
            g_srv_phb_xmgnt_cntx.sim_list.sim_list[index].type = local_ptr->list[i].type;
            g_srv_phb_xmgnt_cntx.sim_list.sim_list[index].index = local_ptr->list[i].index;
            g_srv_phb_xmgnt_cntx.sim_list.sim_list[index].record_index = local_ptr->list[i].record_index;
            g_srv_phb_xmgnt_cntx.sim_list.sim_list[index].tel.type = local_ptr->list[i].tel.type;
            g_srv_phb_xmgnt_cntx.sim_list.sim_list[index].tel.length = local_ptr->list[i].tel.length;

            if (g_srv_phb_xmgnt_cntx.phb_type != PHB_ECC)
            {
                g_srv_phb_xmgnt_cntx.sim_list.sim_list[index].alpha_id.name_length =
                    local_ptr->list[i].alpha_id.name_length;
                g_srv_phb_xmgnt_cntx.sim_list.sim_list[index].alpha_id.name_dcs =
                    local_ptr->list[i].alpha_id.name_dcs;

                InputboxConvertGSMToDeviceEncoding(
                    local_ptr->list[i].alpha_id.name,
                    (U8*) g_srv_phb_xmgnt_cntx.sim_list.sim_list[index].alpha_id.name,
                    local_ptr->list[i].alpha_id.name_length,
                    (MMI_PHB_NAME_LENGTH + 1) * ENCODING_LENGTH,
                    local_ptr->list[i].alpha_id.name_dcs,
                    0,
                    1);

                if (local_ptr->list[i].alpha_id.name_length > MMI_PHB_NAME_LENGTH)
                {
                    g_srv_phb_xmgnt_cntx.sim_list.sim_list[index].alpha_id.name_length = MMI_PHB_NAME_LENGTH;
                    if (local_ptr->list[i].alpha_id.name_dcs == MMI_UCS2_DCS)
                    {
                        g_srv_phb_xmgnt_cntx.sim_list.sim_list[index].alpha_id.name_length =
                            (U8) (MMI_PHB_NAME_LENGTH / 2 * 2);
                    }
                    else if (local_ptr->list[i].alpha_id.name_dcs == MMI_UCS2_81)
                    {
                        g_srv_phb_xmgnt_cntx.sim_list.sim_list[index].alpha_id.name_length =
                            (U8) ((MMI_PHB_NAME_LENGTH - 3) * 2);
                    }
                    g_srv_phb_xmgnt_cntx.sim_list.sim_list[index].alpha_id.name[
                        g_srv_phb_xmgnt_cntx.sim_list.sim_list[index].alpha_id.name_length] = 0;
                    g_srv_phb_xmgnt_cntx.sim_list.sim_list[index].alpha_id.name[
                        g_srv_phb_xmgnt_cntx.sim_list.sim_list[index].alpha_id.name_length + 1] = 0;
                }
            }

            if (srv_phb_check_international_number(local_ptr->list[i].tel.type))
            {
                /* now number is +**21*8123456# */
                applib_decode_number(local_ptr->list[i].tel.number, number, 0x91);
                /* now number is **21*+8123456# */
                mmi_asc_to_ucs2(
                    (CHAR*) g_srv_phb_xmgnt_cntx.sim_list.sim_list[index].tel.number,
                    (CHAR*) number);
            }
            else
            {
                mmi_asc_to_ucs2(
                    (CHAR*) g_srv_phb_xmgnt_cntx.sim_list.sim_list[index].tel.number,
                    (CHAR*) local_ptr->list[i].tel.number);
            }
        }

        if (local_ptr->no_list == PHB_MAX_PHB_ENTRIES)
        {
            srv_phb_xmgnt_get_list_req(g_srv_phb_xmgnt_cntx.sim_interface, g_srv_phb_xmgnt_cntx.phb_type);
            return;
        }
        else
        {
            g_srv_phb_xmgnt_cntx.is_busy = 0;
            g_srv_phb_xmgnt_cntx.result_callback(SRV_PHB_XMGNT_RESULT_OK);
        }
    }
    else if (local_ptr->result.flag == L4C_ERROR && local_ptr->result.cause == PHB_ERRNO_READ_EMPTY)
    {
        /* L4PHB handle is not correct, should transform to L4C_OK */
        g_srv_phb_xmgnt_cntx.is_busy = 0;
        g_srv_phb_xmgnt_cntx.result_callback(SRV_PHB_XMGNT_RESULT_OK);
    }
    else
    {
        g_srv_phb_xmgnt_cntx.is_busy = 0;
        g_srv_phb_xmgnt_cntx.result_callback(SRV_PHB_XMGNT_RESULT_FAIL);
    }
}

#endif /* __MMI_PHB_SLIM_EXTRA_DEFEATURE__ */


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_get_entry
 * DESCRIPTION
 *  This function is used to get extra# entry by record index.
 * PARAMETERS
 *  sim_interface:      [IN]        SIM1/SIM2
 *  phb_type:           [IN]        PHB_ECC/PHB_FDN/PHB_BDN/PHB_MSISDN/PHB_SDN
 *  record_index:       [IN]        PHB record index
 *  entry_cb:           [IN]        Get extra# entry callback
 * RETURN VALUES
 *  MMI_TRUE:           This request is accepted.
 *  MMI_FALSE:          This request is rejected.
 *****************************************************************************/
MMI_BOOL srv_phb_xmgnt_get_entry(
            U8 sim_interface,
            U8 phb_type,
            U16 record_index,
            srv_phb_xmgnt_callback_type_ex entry_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_phb_xmgnt_cntx.is_busy_ex)
    {
        return MMI_FALSE;
    }

    g_srv_phb_xmgnt_cntx.is_busy_ex = 1;
    g_srv_phb_xmgnt_cntx.result_callback_ex = entry_cb;

    srv_phb_xmgnt_get_entry_req(sim_interface, phb_type, record_index);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_get_entry_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 *  phb_type            [IN]        
 *  record_index        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_xmgnt_get_entry_req(U8 sim_interface, U8 phb_type, U16 record_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_get_entry_by_index_req_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr =
        (mmi_phb_get_entry_by_index_req_struct*) OslConstructDataPtr(sizeof(mmi_phb_get_entry_by_index_req_struct));
    local_ptr->type = phb_type;
    local_ptr->index = 0xFFFF;
    local_ptr->record_index = record_index;
    local_ptr->no_data = 1;
    SetProtocolEventHandler(srv_phb_xmgnt_get_entry_rsp, PRT_PHB_GET_ENTRY_BY_INDEX_RSP);
    mmi_frm_send_ilm(mmi_frm_sim_to_l4c_mod(mmi_frm_index_to_sim(sim_interface)), PRT_PHB_GET_ENTRY_BY_INDEX_REQ, (oslParaType*) local_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_get_entry_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_xmgnt_get_entry_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_get_entry_by_index_rsp_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_phb_get_entry_by_index_rsp_struct*) info;

    memcpy(&g_srv_phb_xmgnt_cntx.sim_entry, &local_ptr->list[0], sizeof(l4c_phb_entry_struct));

    if (local_ptr->result.flag == L4C_OK)
    {
        g_srv_phb_xmgnt_cntx.is_busy_ex = 0;
        g_srv_phb_xmgnt_cntx.result_callback_ex(SRV_PHB_XMGNT_RESULT_OK, &g_srv_phb_xmgnt_cntx.sim_entry);
    }
    else if (local_ptr->result.flag == L4C_ERROR && local_ptr->result.cause == PHB_ERRNO_READ_EMPTY)
    {
        /* L4PHB handle is not correct, should transform to L4C_OK */
        g_srv_phb_xmgnt_cntx.is_busy_ex = 0;
        g_srv_phb_xmgnt_cntx.result_callback_ex(SRV_PHB_XMGNT_RESULT_OK, &g_srv_phb_xmgnt_cntx.sim_entry);
    }
    else
    {
        g_srv_phb_xmgnt_cntx.is_busy_ex = 0;
        g_srv_phb_xmgnt_cntx.result_callback_ex(SRV_PHB_XMGNT_RESULT_FAIL, &g_srv_phb_xmgnt_cntx.sim_entry);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_set_entry
 * DESCRIPTION
 *  This function is used to add/edit extra# entry.
 * PARAMETERS
 *  sim_interface:      [IN]        SIM1/SIM2
 *  phb_type:           [IN]        PHB_ECC/PHB_FDN/PHB_BDN/PHB_MSISDN/PHB_SDN
 *  index:              [IN]        PHB entry index
 *  record_index:       [IN]        PHB record index
 *  name:               [IN]        extra# name
 *  number:             [IN]        extra# number
 *  set_cb:             [IN]        Add/Edit extra# entry callback
 * RETURN VALUES
 *  MMI_TRUE:           This request is accepted.
 *  MMI_FALSE:          This request is rejected.
 *****************************************************************************/
MMI_BOOL srv_phb_xmgnt_set_entry(
            U8 sim_interface,
            U8 phb_type,
            U16 index,
            U16 record_index,
            U16 *name,
            U16 *number,
            srv_phb_xmgnt_callback_type set_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_phb_xmgnt_cntx.is_busy)
    {
        return MMI_FALSE;
    }
#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
    if (phb_type == PHB_BDN)
    {
        index = record_index;
        record_index = 0XFFFF;
    }
#endif /* __MMI_PHB_SLIM_EXTRA_DEFEATURE__ */
    g_srv_phb_xmgnt_cntx.is_busy = 1;
    g_srv_phb_xmgnt_cntx.sim_interface = sim_interface;
    g_srv_phb_xmgnt_cntx.phb_type = phb_type;
    g_srv_phb_xmgnt_cntx.name = name;
    g_srv_phb_xmgnt_cntx.number = number;
    g_srv_phb_xmgnt_cntx.result_callback = set_cb;

    srv_phb_xmgnt_set_entry_req(sim_interface, phb_type, index, record_index, name, number);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_set_entry_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 *  phb_type            [IN]        
 *  index               [IN]        
 *  record_index        [IN]        
 *  name                [IN]        
 *  number              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_xmgnt_set_entry_req(
                U8 sim_interface,
                U8 phb_type,
                U16 index,
                U16 record_index,
                U16 *name,
                U16 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_set_entry_req_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (record_index == 0xFFFF)
    {
        g_srv_phb_xmgnt_cntx.is_new = MMI_TRUE;
    }
    else
    {
        g_srv_phb_xmgnt_cntx.is_new = MMI_FALSE;
    }
    local_ptr = (mmi_phb_set_entry_req_struct*) OslConstructDataPtr(sizeof(mmi_phb_set_entry_req_struct));
    local_ptr->type = phb_type;
    local_ptr->no_data = 1;
    local_ptr->list.index = index;
    local_ptr->list.record_index = record_index;
    local_ptr->list.storage = srv_phb_get_storage_by_sim_id(sim_interface);
    g_srv_phb_xmgnt_cntx.phb_type = phb_type;
    srv_phb_build_l4phb_entry(&local_ptr->list, name, NULL, number);
    SetProtocolEventHandler(srv_phb_xmgnt_set_entry_rsp, PRT_PHB_SET_ENTRY_RSP);
    mmi_frm_send_ilm(mmi_frm_sim_to_l4c_mod(mmi_frm_index_to_sim(sim_interface)), PRT_PHB_SET_ENTRY_REQ, (oslParaType*) local_ptr, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_set_entry_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_xmgnt_set_entry_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_set_entry_rsp_struct *local_ptr;
    U16 index;
    U8 sim_id; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_phb_set_entry_rsp_struct*) info;
    index = local_ptr->list[0].record_index;
    if (local_ptr->result.flag == L4C_OK)
    {
        g_srv_phb_xmgnt_cntx.is_busy = 0;
        if (g_srv_phb_xmgnt_cntx.phb_type == PHB_FDN)
        {
            srv_phb_xmgnt_set_fdn(&(local_ptr->list[0]));        
            sim_id = srv_phb_get_sim_id((phb_storage_enum)(local_ptr->list[0].storage));
            index = srv_phb_xmgnt_get_fdn_sort_index(sim_id, index);
            if (g_srv_phb_xmgnt_cntx.is_new != MMI_TRUE)
            {
                srv_phb_sse_delete_name_index(index);
            }
            srv_phb_sse_insert_name_index(index, g_srv_phb_xmgnt_cntx.name);
        }
        g_srv_phb_xmgnt_cntx.result_callback(SRV_PHB_XMGNT_RESULT_OK);
        if (g_srv_phb_xmgnt_cntx.phb_type == PHB_MSISDN)
        {
            if (local_ptr->list[0].index <= SRV_CALLSET_MAX_LINE)
            {
                srv_phb_owner_number_set_name_number(
                    g_srv_phb_xmgnt_cntx.sim_interface,
                    (U16) (local_ptr->list[0].record_index - 1),
                    g_srv_phb_xmgnt_cntx.name,
                    g_srv_phb_xmgnt_cntx.number);
            }
        }
    }
    else if (local_ptr->result.cause == SIM_EF_RECORD_FULL)
    {
        g_srv_phb_xmgnt_cntx.is_busy = 0;
        g_srv_phb_xmgnt_cntx.result_callback(SRV_PHB_XMGNT_RESULT_EF_FULL);
    }
    else if (local_ptr->result.cause == SIM_CHV_RETRY_ALLOW)
    {
        g_srv_phb_xmgnt_cntx.is_busy = 0;
        g_srv_phb_xmgnt_cntx.result_callback(SIM_CHV_RETRY_ALLOW);
    }
    else
    {
        g_srv_phb_xmgnt_cntx.is_busy = 0;
        g_srv_phb_xmgnt_cntx.result_callback(SRV_PHB_XMGNT_RESULT_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_delete_entry
 * DESCRIPTION
 *  This function is used to delete extra# entry.
 * PARAMETERS
 *  sim_interface:      [IN]        SIM1/SIM2
 *  phb_type:           [IN]        PHB_ECC/PHB_FDN/PHB_BDN/PHB_MSISDN/PHB_SDN
 *  index:              [IN]        PHB entry index
 *  record_index:       [IN]        PHB entry index
 *  del_cb:             [IN]        Delete extra# entry callback
 * RETURN VALUES
 *  MMI_TRUE:           This request is accepted.
 *  MMI_FALSE:          This request is rejected.
 *****************************************************************************/
MMI_BOOL srv_phb_xmgnt_delete_entry(
            U8 sim_interface,
            U8 phb_type,
            U16 index,
            U16 record_index,
            srv_phb_xmgnt_callback_type del_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_phb_xmgnt_cntx.is_busy)
    {
        return MMI_FALSE;
    }
#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
    if (phb_type == PHB_BDN)
    {
        index = record_index;
        record_index = 0XFFFF;
    }
#endif /* __MMI_PHB_SLIM_EXTRA_DEFEATURE__ */
    g_srv_phb_xmgnt_cntx.is_busy = 1;
    g_srv_phb_xmgnt_cntx.sim_interface = sim_interface;
    g_srv_phb_xmgnt_cntx.result_callback = del_cb;

    srv_phb_xmgnt_delete_entry_req(sim_interface, phb_type, index, record_index);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_delete_entry_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 *  phb_type            [IN]        
 *  index               [IN]        
 *  record_index        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_xmgnt_delete_entry_req(U8 sim_interface, U8 phb_type, U16 index, U16 record_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_del_entry_req_struct *local_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_phb_del_entry_req_struct*) OslConstructDataPtr(sizeof(mmi_phb_del_entry_req_struct));
    local_ptr->type = phb_type;
    local_ptr->index = index;
    local_ptr->no_data = 1;
    local_ptr->del_all = MMI_FALSE;
    local_ptr->record_index = record_index;
    local_ptr->storage = srv_phb_get_storage_by_sim_id(sim_interface);
    g_srv_phb_xmgnt_cntx.phb_type = phb_type;
    SetProtocolEventHandler(srv_phb_xmgnt_delete_entry_rsp, PRT_PHB_DEL_ENTRY_RSP);
    mmi_frm_send_ilm(mmi_frm_sim_to_l4c_mod(mmi_frm_index_to_sim(sim_interface)), PRT_PHB_DEL_ENTRY_REQ, (oslParaType*) local_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_delete_entry_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_xmgnt_delete_entry_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_del_entry_rsp_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_phb_del_entry_rsp_struct*) info;

    if (local_ptr->result.flag == L4C_OK)
    {
        g_srv_phb_xmgnt_cntx.is_busy = 0;
        if (g_srv_phb_xmgnt_cntx.phb_type == PHB_FDN)
        {
            srv_phb_xmgnt_delete_fdn(g_srv_phb_xmgnt_cntx.sim_interface, local_ptr->old_index);
        }
        g_srv_phb_xmgnt_cntx.result_callback(SRV_PHB_XMGNT_RESULT_OK);
        if (g_srv_phb_xmgnt_cntx.phb_type == PHB_MSISDN)
        {
            if (local_ptr->old_index <= SRV_CALLSET_MAX_LINE)
            {
                srv_phb_owner_number_set_name_number(
                    g_srv_phb_xmgnt_cntx.sim_interface,
                    (U16) (local_ptr->old_index - 1),
                    L"",
                    L"");
            }
        }
    }
    else if (local_ptr->result.cause == SIM_CHV_RETRY_ALLOW)
    {
        g_srv_phb_xmgnt_cntx.is_busy = 0;
        g_srv_phb_xmgnt_cntx.result_callback(SIM_CHV_RETRY_ALLOW);
    }
    else
    {
        g_srv_phb_xmgnt_cntx.is_busy = 0;
        g_srv_phb_xmgnt_cntx.result_callback(SRV_PHB_XMGNT_RESULT_FAIL);
    }
}

#define SRV_PHB_DIAL_MODE

/* 
 * Typedef
 */
typedef struct
{
    U8 fdn_mode;
    U8 bdn_mode;
    MMI_BOOL is_ready;
} srv_phb_sim_dial_mode_struct;

typedef struct
{
    srv_phb_sim_dial_mode_struct sim_dial_mode[MMI_SIM_TOTAL];
    void * user_data[MMI_SIM_TOTAL];
    srv_phb_startup_callback_type startup_callback;
} srv_phb_dial_mode_struct;

/* 
 * Local Variable
 */
static srv_phb_dial_mode_struct g_srv_phb_dial_mode;

/* 
 * Local Function
 */
static void srv_phb_xmgnt_toggle_dial_mode_req(U8 sim_interface, U8 phb_type);
static void srv_phb_xmgnt_toggle_dial_mode_rsp(void *info);

static void srv_phb_xmgnt_read_dial_mode_req(sim_interface_enum sim_id);
static void srv_phb_xmgnt_read_dial_mode_rsp(void *info, int mod_id);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_query_dial_mode
 * DESCRIPTION
 *  This function is used to query FDN/BDN dial mode.
 * PARAMETERS
 *  sim_interface:      [IN]        SIM1/SIM2
 *  phb_type:           [IN]        PHB_FDN/PHB_BDN
 * RETURNS
 *  FDN/BDN dial mode (0: off, 1: on, 0xFF: query failed)
 *****************************************************************************/
U8 srv_phb_xmgnt_query_dial_mode(U8 sim_interface, U8 phb_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (phb_type == PHB_FDN)
    {
        return g_srv_phb_dial_mode.sim_dial_mode[sim_interface].fdn_mode;
    }
#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
    else if (phb_type == PHB_BDN)
    {
        return g_srv_phb_dial_mode.sim_dial_mode[sim_interface].bdn_mode;
    }
#endif /* __MMI_PHB_SLIM_EXTRA_DEFEATURE__ */

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_toggle_dial_mode
 * DESCRIPTION
 *  This function is used to toggle FDN/BDN dial mode.
 * PARAMETERS
 *  sim_interface:      [IN]        SIM1/SIM2
 *  phb_type:           [IN]        PHB_FDN/PHB_BDN
 *  toggle_cb:          [IN]        Toggle FDN/BDN dial mode callback
 * RETURN VALUES
 *  MMI_TRUE:           This request is accepted.
 *  MMI_FALSE:          This request is rejected.
 *****************************************************************************/
MMI_BOOL srv_phb_xmgnt_toggle_dial_mode(
            U8 sim_interface,
            U8 phb_type,
            srv_phb_xmgnt_callback_type toggle_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_phb_xmgnt_cntx.is_busy)
    {
        return MMI_FALSE;
    }

    g_srv_phb_xmgnt_cntx.is_busy = 1;
    g_srv_phb_xmgnt_cntx.sim_interface = sim_interface;
    g_srv_phb_xmgnt_cntx.phb_type = phb_type;
    g_srv_phb_xmgnt_cntx.result_callback = toggle_cb;

    srv_phb_xmgnt_toggle_dial_mode_req(sim_interface, phb_type);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_toggle_dial_mode_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 *  phb_type            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_xmgnt_toggle_dial_mode_req(U8 sim_interface, U8 phb_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_set_dial_mode_req_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr =
        (mmi_smu_set_dial_mode_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_set_dial_mode_req_struct));
    if (phb_type == PHB_FDN)
    {
        local_ptr->type = SRV_PHB_DN_TYPE_FDN;
        local_ptr->on_off = !g_srv_phb_dial_mode.sim_dial_mode[sim_interface].fdn_mode;
    }
#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
    else if (phb_type == PHB_BDN)
    {
        local_ptr->type = SRV_PHB_DN_TYPE_BDN;
        local_ptr->on_off = !g_srv_phb_dial_mode.sim_dial_mode[sim_interface].bdn_mode;
    }
#endif /* __MMI_PHB_SLIM_EXTRA_DEFEATURE__ */
    else
    {
        MMI_ASSERT(0);
    }
    SetProtocolEventHandler(srv_phb_xmgnt_toggle_dial_mode_rsp, PRT_MMI_SMU_SET_DIAL_MODE_RSP);
    mmi_frm_send_ilm(mmi_frm_sim_to_l4c_mod(mmi_frm_index_to_sim(sim_interface)), PRT_MMI_SMU_SET_DIAL_MODE_REQ, (oslParaType*) local_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_toggle_dial_mode_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_xmgnt_toggle_dial_mode_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_set_dial_mode_rsp_struct *local_ptr;
    sim_interface_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_smu_set_dial_mode_rsp_struct*) info;

    if (local_ptr->result)
    {
        for (sim_id = SIM1; sim_id < MMI_SIM_TOTAL; sim_id++)
        {
            if (g_srv_phb_xmgnt_cntx.sim_interface == sim_id)
            {
                if (g_srv_phb_xmgnt_cntx.phb_type == PHB_FDN)
                {
                    g_srv_phb_dial_mode.sim_dial_mode[sim_id].fdn_mode = !g_srv_phb_dial_mode.sim_dial_mode[sim_id].fdn_mode;
                    break;
                }
            #ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
                else if (g_srv_phb_xmgnt_cntx.phb_type == PHB_BDN)
                {
                    g_srv_phb_dial_mode.sim_dial_mode[sim_id].bdn_mode = !g_srv_phb_dial_mode.sim_dial_mode[sim_id].bdn_mode;
                    break;
                }
            #endif /* __MMI_PHB_SLIM_EXTRA_DEFEATURE__ */
            }
        }
        srv_phb_startup_clear_ready_flag();
        g_srv_phb_xmgnt_cntx.is_busy = 0;
        g_srv_phb_xmgnt_cntx.result_callback(SRV_PHB_XMGNT_RESULT_OK);
    }
    else
    {
        g_srv_phb_xmgnt_cntx.is_busy = 0;
        g_srv_phb_xmgnt_cntx.result_callback(SRV_PHB_XMGNT_RESULT_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_get_dial_mode
 * DESCRIPTION
 *  This function is used to read dial mode during phonebook startup.
 * PARAMETERS
 *  init_cb:            [IN]        startup callback
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_xmgnt_read_dial_mode(sim_interface_enum sim_id, srv_phb_startup_callback_type init_cb, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_dial_mode.sim_dial_mode[sim_id].is_ready = MMI_FALSE;
    g_srv_phb_dial_mode.startup_callback = init_cb;
    g_srv_phb_dial_mode.user_data[sim_id] = user_data;
    srv_phb_xmgnt_read_dial_mode_req(sim_id);
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_read_dial_mode_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_xmgnt_read_dial_mode_req(sim_interface_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(PRT_MMI_SMU_GET_DIAL_MODE_RSP, (PsIntFuncPtr)srv_phb_xmgnt_read_dial_mode_rsp, MMI_FALSE);
    mmi_frm_send_ilm(mmi_frm_sim_to_l4c_mod(mmi_frm_index_to_sim(sim_id)), PRT_MMI_SMU_GET_DIAL_MODE_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_read_dial_mode_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_xmgnt_read_dial_mode_rsp(void *info, int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_get_dial_mode_rsp_struct *local_ptr = (mmi_smu_get_dial_mode_rsp_struct*) info;
    sim_interface_enum sim_id = (sim_interface_enum)(mmi_frm_sim_to_index(mmi_frm_l4c_mod_to_sim((module_type)mod_id)));
    U8 *fdn_mode = &g_srv_phb_dial_mode.sim_dial_mode[sim_id].fdn_mode;
    U8 *bdn_mode = &g_srv_phb_dial_mode.sim_dial_mode[sim_id].bdn_mode;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    *fdn_mode = 0;
    *bdn_mode = 0;
    if (local_ptr->result)
    {
        switch (local_ptr->dial_mode)
        {         
            case SRV_PHB_DN_TYPE_FDN:
                *fdn_mode = 1;
                break;
            case SRV_PHB_DN_TYPE_BDN:
            case SRV_PHB_DN_TYPE_ADN_BDN:
                *bdn_mode = 1;
                break;
            case SRV_PHB_DN_TYPE_FDN_BDN:
                *fdn_mode = 1;
                *bdn_mode = 1;
                break;
            case SRV_PHB_DN_TYPE_ADN:
            default:
                break;
        }
    }
    g_srv_phb_dial_mode.sim_dial_mode[sim_id].is_ready = MMI_TRUE;
    g_srv_phb_dial_mode.startup_callback(g_srv_phb_dial_mode.user_data[sim_id]);
}


#define SRV_PHB_FDN_SEARCH

/* 
 * Typedef
 */
typedef struct
{
    srv_phb_xmgnt_entry_struct fdn_entry[MMI_PHB_FDN_ENTRIES];
    U16 entry_count;
    MMI_BOOL is_ready;
} srv_phb_fdn_list_struct;

typedef struct
{
    srv_phb_fdn_list_struct fdn_list[MMI_SIM_TOTAL];
    void *user_data[MMI_SIM_TOTAL];
    srv_phb_startup_callback_type startup_callback;
} srv_phb_fdn_cntx_struct;

/* 
 * Local Variable
 */
static srv_phb_fdn_cntx_struct g_srv_phb_fdn_cntx;

/* 
 * Local Function
 */
static void srv_phb_xmgnt_read_fdn_to_ram_hdlr(sim_interface_enum sim_id);
static void srv_phb_xmgnt_read_fdn_to_ram_req(sim_interface_enum sim_id);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_get_fdn_by_index
 * DESCRIPTION
 *  get fdn list by index
 * PARAMETERS
 *  index            [IN]  fdn sort index
 * RETURNS
 *  extra# handle
 *****************************************************************************/
srv_phb_xmgnt_entry_struct srv_phb_xmgnt_get_fdn_by_index(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index -= MMI_PHB_ENTRIES;
    return g_srv_phb_fdn_cntx.fdn_list[index / MMI_PHB_FDN_ENTRIES].fdn_entry[index % MMI_PHB_FDN_ENTRIES];
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_set_fdn
 * DESCRIPTION
 *  This function is used to get extra# list.
 * PARAMETERS
 *  sim_interface:      [IN]        SIM1/SIM2
 *  phb_type:           [IN]        PHB_ECC/PHB_FDN/PHB_BDN/PHB_MSISDN/PHB_SDN
 *  list_cb:            [IN]        Get extra# list callback
 * RETURNS
 *  extra# handle
 *****************************************************************************/
void srv_phb_xmgnt_set_fdn(l4c_phb_entry_struct *phb_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_id = srv_phb_get_sim_id((phb_storage_enum)(phb_entry->storage));
    U16 index;
    U16 record_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_phb_xmgnt_cntx.is_new == MMI_TRUE)
    {
        record_index = 0;
        g_srv_phb_fdn_cntx.fdn_list[sim_id].entry_count ++;
    }
    else
    {
        record_index = phb_entry->record_index;
    }
    for (index = 0; index < MMI_PHB_FDN_ENTRIES; index++)
        {
        if (g_srv_phb_fdn_cntx.fdn_list[sim_id].fdn_entry[index].record_index == record_index)
            {
                break;
            }
        }
    srv_phb_parse_l4phb_entry(
        phb_entry,
        g_srv_phb_fdn_cntx.fdn_list[sim_id].fdn_entry[index].alpha_id.name,
        NULL,
        g_srv_phb_fdn_cntx.fdn_list[sim_id].fdn_entry[index].tel.number
        );
    g_srv_phb_fdn_cntx.fdn_list[sim_id].fdn_entry[index].record_index = phb_entry->record_index;
    g_srv_phb_fdn_cntx.fdn_list[sim_id].fdn_entry[index].tel.length = phb_entry->tel.length;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_delete_fdn
 * DESCRIPTION
 *  This function is used to delete a fdn entry.
 * PARAMETERS
 *  sim_id       :      [IN]        sim interface
 *  index         :      [IN]        fdn index
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_xmgnt_delete_fdn(sim_interface_enum sim_id, U16 index)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 sort_index = srv_phb_xmgnt_get_fdn_sort_index(sim_id, index);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_phb_sse_delete_name_index(sort_index);
    g_srv_phb_fdn_cntx.fdn_list[sim_id].entry_count --;
    g_srv_phb_fdn_cntx.fdn_list[sim_id].fdn_entry[sort_index - sim_id * MMI_PHB_FDN_ENTRIES - MMI_PHB_ENTRIES].record_index = 0;;
}


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
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_get_fdn_sort_index
 * DESCRIPTION
 *  get sort index by store inde.
 * PARAMETERS
 *  sim_id       :      [IN]        sim interface
 *  index         :      [IN]        fdn index
 * RETURNS
 *  void
 *****************************************************************************/
static U16 srv_phb_xmgnt_get_fdn_sort_index(sim_interface_enum sim_id, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (index = 0; index < MMI_PHB_FDN_ENTRIES; index ++)
    {
        if (g_srv_phb_fdn_cntx.fdn_list[sim_id].fdn_entry[index].record_index == store_index)
        {
            return index + sim_id * MMI_PHB_FDN_ENTRIES + MMI_PHB_ENTRIES;
        }
    }

    return 0xFFFF;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_get_fdn_name
 * DESCRIPTION
 *  This function is used to get fdn name by contact id.
 * PARAMETERS
 *  id:             [IN]        contact id
 * RETURNS
 *  extra# list count
 *****************************************************************************/

WCHAR* srv_phb_xmgnt_get_fdn_name(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_interface_enum sim_id;
    U16 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    sim_id = (sim_interface_enum)((id - MMI_PHB_ENTRIES) / MMI_PHB_FDN_ENTRIES);
    index = (id - MMI_PHB_ENTRIES) % MMI_PHB_FDN_ENTRIES;
    return g_srv_phb_fdn_cntx.fdn_list[sim_id].fdn_entry[index].alpha_id.name;    
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_read_fdn_to_ram
 * DESCRIPTION
 *  This function is used to read FDN list (both SIM1 and SIM2) to ram for call querying name.
 *  This permanent list will be different from Phonebook settings->Extra#->FDN list after adding/editing/deleting some FDN entry.
 *  But when FDN entry changed, it will automatically read all FDN list again.
 *  So just copy it to keep them synchronized.
 * PARAMETERS
 *  init_cb:            [IN]        startup callback
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_xmgnt_read_fdn_to_ram(sim_interface_enum sim_id, srv_phb_startup_callback_type init_cb, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_fdn_cntx.startup_callback = init_cb;
    g_srv_phb_fdn_cntx.user_data[sim_id] = user_data;
    g_srv_phb_fdn_cntx.fdn_list[sim_id].is_ready = MMI_FALSE;
    g_srv_phb_fdn_cntx.fdn_list[sim_id].entry_count = 0;
    srv_phb_sse_clear_fdn_name_index(sim_id);
    srv_phb_xmgnt_read_fdn_to_ram_req(sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_read_fdn_to_ram_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_xmgnt_read_fdn_to_ram_hdlr(sim_interface_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_phb_fdn_cntx.startup_callback != NULL)
    {
        g_srv_phb_fdn_cntx.startup_callback(g_srv_phb_fdn_cntx.user_data[sim_id]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_set_read_false
 * DESCRIPTION
 *  This function will set the read value of the FDN for each sim to MMI_FALSE.
 * PARAMETERS
 *  init_cb:            [IN]        startup callback
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_phb_xmgnt_set_read_false(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_interface_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (sim_id = SIM1; sim_id < MMI_SIM_TOTAL; sim_id++)
    {
        g_srv_phb_fdn_cntx.fdn_list[sim_id].is_ready = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_read_fdn_to_ram_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_xmgnt_read_fdn_to_ram_req(sim_interface_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_get_entry_by_index_req_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_phb_get_entry_by_index_req_struct*) OslConstructDataPtr(sizeof(mmi_phb_get_entry_by_index_req_struct));
    local_ptr->type = PHB_FDN;
    local_ptr->index = g_srv_phb_fdn_cntx.fdn_list[sim_id].entry_count + 1;    /* l4phb entry index starts from 1 */
    local_ptr->record_index = 0xFFFF;
    local_ptr->no_data = PHB_MAX_PHB_ENTRIES;
    local_ptr->storage = srv_phb_get_storage_by_sim_id(sim_id);
    srv_phb_startup_set_initing_entry_type(sim_id, PHB_FDN);
    mmi_frm_set_protocol_event_handler(PRT_PHB_GET_ENTRY_BY_INDEX_RSP, (PsIntFuncPtr)srv_phb_startup_read_entry_by_index_rsp, MMI_FALSE);
    mmi_frm_send_ilm(mmi_frm_sim_to_l4c_mod(mmi_frm_index_to_sim(sim_id)), PRT_PHB_GET_ENTRY_BY_INDEX_REQ, (oslParaType*) local_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_read_fdn_to_ram_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_xmgnt_read_fdn_to_ram_rsp(void *info, int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_get_entry_by_index_rsp_struct *local_ptr;
    U16 i, index;
    sim_interface_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_phb_get_entry_by_index_rsp_struct*) info;
    sim_id = (sim_interface_enum)(mmi_frm_sim_to_index(mmi_frm_l4c_mod_to_sim((module_type)mod_id)));
    if (local_ptr->result.flag == L4C_OK)
    {
        for (i = 0; i < local_ptr->no_list; i++)
        {
            if (g_srv_phb_fdn_cntx.fdn_list[sim_id].entry_count >= MMI_PHB_FDN_ENTRIES)
            {
                break;
            }

            index = g_srv_phb_fdn_cntx.fdn_list[sim_id].entry_count;
            g_srv_phb_fdn_cntx.fdn_list[sim_id].entry_count++;
            g_srv_phb_fdn_cntx.fdn_list[sim_id].fdn_entry[index].alpha_id.name_length = local_ptr->list[i].alpha_id.name_length;
            g_srv_phb_fdn_cntx.fdn_list[sim_id].fdn_entry[index].alpha_id.name_dcs = local_ptr->list[i].alpha_id.name_dcs;
            g_srv_phb_fdn_cntx.fdn_list[sim_id].fdn_entry[index].record_index = local_ptr->list[i].record_index;
            srv_phb_parse_l4phb_entry(
                &(local_ptr->list[i]),
                g_srv_phb_fdn_cntx.fdn_list[sim_id].fdn_entry[index].alpha_id.name,
                NULL,
                g_srv_phb_fdn_cntx.fdn_list[sim_id].fdn_entry[index].tel.number);
            g_srv_phb_fdn_cntx.fdn_list[sim_id].fdn_entry[index].tel.type = local_ptr->list[i].tel.type;
            g_srv_phb_fdn_cntx.fdn_list[sim_id].fdn_entry[index].tel.length = local_ptr->list[i].tel.length;
            srv_phb_sse_delete_name_index(MMI_PHB_ENTRIES + sim_id * MMI_PHB_FDN_ENTRIES + index);
            srv_phb_sse_insert_name_index(MMI_PHB_ENTRIES + sim_id * MMI_PHB_FDN_ENTRIES + index, g_srv_phb_fdn_cntx.fdn_list[sim_id].fdn_entry[index].alpha_id.name);
        }

        if (local_ptr->no_list == PHB_MAX_PHB_ENTRIES)
        {
            srv_phb_xmgnt_read_fdn_to_ram_req(sim_id);
            return;
        }
    }

    g_srv_phb_fdn_cntx.fdn_list[sim_id].is_ready = MMI_TRUE;
    srv_phb_xmgnt_read_fdn_to_ram_hdlr(sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_update_fdn_to_ram
 * DESCRIPTION
 *  This function is used to update current FDN list (SIM1 or SIM2) to ram.
 *  This permanent list will be different from Phonebook settings->Extra#->FDN list after adding/editing/deleting some FDN entry.
 *  But when FDN entry changed, it will automatically read all FDN list again.
 *  So just copy it to keep them synchronized.
 * PARAMETERS
 *  sim_interface:      [IN]        SIM1/SIM2
 *  count:              [IN]        SIM list count
 *  sim_list:           [IN]        SIM list
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_xmgnt_update_fdn_to_ram(U8 sim_interface, U16 count, srv_phb_xmgnt_entry_struct *sim_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_xmgnt_query_dial_mode(sim_interface, PHB_FDN))
    {
        g_srv_phb_fdn_cntx.fdn_list[sim_interface].entry_count = count;
        memcpy(
            g_srv_phb_fdn_cntx.fdn_list[sim_interface].fdn_entry,
            sim_list,
            count * sizeof(srv_phb_xmgnt_entry_struct));
    }
    else
    {
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_search_fdn_by_number
 * DESCRIPTION
 *  This function is used to search FDN name (SIM1 or SIM2) by number.
 * PARAMETERS
 *  sim_interface:      [IN]        SIM1/SIM2
 *  number:             [IN]        Number to dial
 *  name:               [OUT]       Name to match the number
 * RETURNS
 *  PHB entry index
 *****************************************************************************/
U16 srv_phb_xmgnt_search_fdn_by_number(U8 sim_interface, U16 *number, U16 *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, count = 0;
    U16 fdn_list_count;
    srv_phb_xmgnt_entry_struct *fdn_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_xmgnt_query_dial_mode(sim_interface, PHB_FDN))
    {
        fdn_list_count = g_srv_phb_fdn_cntx.fdn_list[sim_interface].entry_count;
        fdn_list = g_srv_phb_fdn_cntx.fdn_list[sim_interface].fdn_entry;
    }
    else
    {
        return 0xFFFF;
    }

    for (i = 0; i < MMI_PHB_FDN_ENTRIES && count < fdn_list_count; i ++)
    {
        if (fdn_list[i].record_index > 0)
        {
            if (srv_phb_compare_number(fdn_list[i].tel.number, number))
            {
                mmi_wcscpy(name, (U16*) fdn_list[i].alpha_id.name);
                return i;
            }
            count ++;
        }
    }
    return 0xFFFF;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_approve_fdn
 * DESCRIPTION
 *  This is phb_approve function of PHB module.
 * PARAMETERS
 *  number                [IN]     BCD number to approve
 *  num_length            [IN]     number length
 *  sim_id                [IN]     sim interface enum
 *  l4c_op                [IN]     l4c_operation_type
 *  cause                 [OUT]    fail cause
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_phb_xmgnt_approve_fdn(
            kal_uint8 *number,
            kal_uint8 num_length,
            kal_uint8 sim_id,
            l4c_operation_type_enum l4c_op,
            kal_uint16 *cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U8 asc_number[MMI_PHB_NUMBER_LENGTH + 1];
    U32 src_number_len;
    U16 *src_number;
    U8 dest_number[MMI_PHB_NUMBER_LENGTH + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (number == NULL || num_length == 0)
    {
        *cause = PHB_APPROVE_FORMAT_FAIL;
        return MMI_FALSE;
    }
    #ifdef __OP01__
    if ((g_srv_phb_dial_mode.sim_dial_mode[sim_id].fdn_mode ||
         g_srv_phb_dial_mode.sim_dial_mode[sim_id].bdn_mode))
    {
        if ((num_length == 3 && number[1] == 0x00 && number[2] == 0xF0) ||
            (num_length == 2 && number[1] == 0x80) ||
            (num_length == 3 && number[1] == 0x11 && number[2] == 0xF0) ||
            (num_length == 3 && number[1] == 0x11 && number[2] == 0xF8) ||
            (num_length == 3 && number[1] == 0x11 && number[2] == 0xF9) ||
            (num_length == 3 && number[1] == 0x99 && number[2] == 0xF9))
        {
            return MMI_TRUE;
        }
    }
    #endif
    
    if (SRV_PHB_DN_TYPE_FDN&l4csmu_get_dial_mode())
    {
        g_srv_phb_dial_mode.sim_dial_mode[sim_id].fdn_mode = 1;
    }
    else
    {
        g_srv_phb_dial_mode.sim_dial_mode[sim_id].fdn_mode = 0;
    }

    if (g_srv_phb_dial_mode.sim_dial_mode[sim_id].fdn_mode)
    {
        if (g_srv_phb_dial_mode.sim_dial_mode[sim_id].is_ready == MMI_TRUE && g_srv_phb_fdn_cntx.fdn_list[sim_id].is_ready == MMI_TRUE)
        {
            srv_phb_convert_to_digit(asc_number, number+1, (num_length-1)*2);
            for (i = 0; i < MMI_PHB_FDN_ENTRIES; i++)
            {
                if (g_srv_phb_fdn_cntx.fdn_list[sim_id].fdn_entry[i].record_index == 0)
                {
                    continue;
                }
                src_number = g_srv_phb_fdn_cntx.fdn_list[sim_id].fdn_entry[i].tel.number;
                src_number_len = (U32)g_srv_phb_fdn_cntx.fdn_list[sim_id].fdn_entry[i].tel.length;
                if (src_number_len == 0)
                {
                    continue;
                }
                if (*src_number == '+' && *number == 0x91)
                {
                    src_number ++;
                }
                num_length = (U8)mmi_ucs2_n_to_asc((CHAR *)dest_number, (CHAR *)src_number, src_number_len * 2);
                dest_number[num_length] = '\0';
                if (srv_phb_compare_fdn_number((CHAR *)asc_number, (CHAR *)dest_number) == MMI_TRUE)
                {
                    return MMI_TRUE;
                }
            }
            *cause = PHB_APPROVE_FDN_BLOCKED;
            return MMI_FALSE;
            
        }
        else
        {
            *cause = PHB_APPROVE_PHB_NOT_READY;
            return MMI_FALSE;
        }
    }
    else
    {
        return MMI_TRUE;
    }    
}

#define SRV_PHB_MSISDN_INFO

/* 
 * Local Variable
 */
static mmi_phb_owner_number_struct g_srv_phb_msisdn_info[MMI_MAX_SIM_NUM][SRV_CALLSET_MAX_LINE];

/*****************************************************************************
 * FUNCTION
 *  srv_phb_send_owner_number_changed_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface   [IN]        
 *  index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_send_owner_number_changed_event(U8 sim_interface, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_owner_number_changed_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_PHB_OWNER_NUMBER_CHANGED);
    evt.sim_interface = sim_interface;
    evt.index = index;
    MMI_FRM_CB_EMIT_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_owner_number_parse_msisdn_info
 * DESCRIPTION
 *  This function is used to parse MSISDN information.
 * PARAMETERS
 *  sim_interface:      [IN]        SIM1/SIM2
 *  no_msisdn:          [IN]        No. of MSISDN
 *  msisdn:             [IN]        MSISDN data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_owner_number_parse_msisdn_info(U8 sim_interface, U8 no_msisdn, l4csmu_addr_struct *msisdn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_owner_number_struct *msisdn_info;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_interface < MMI_MAX_SIM_NUM)
    {
        msisdn_info = g_srv_phb_msisdn_info[sim_interface];
    }
    else
    {
        return;
    }

    if (no_msisdn > 0)
    {
        U8 number[MMI_PHB_NUMBER_PLUS_LENGTH + 1];

        for (i = 0; ((i < SRV_CALLSET_MAX_LINE) && (i < no_msisdn)); i++)
        {
            InputboxConvertGSMToDeviceEncoding(
                msisdn[i].alpha_id,
                (U8*) msisdn_info[i].name,
                msisdn[i].alpha_id_size,
                (MMI_PHB_NAME_LENGTH + 1) * ENCODING_LENGTH,
                msisdn[i].alpha_id_dcs,
                0,
                1);

            /* now number is +**21*8123456# */
            applib_decode_number(msisdn[i].digit, number, msisdn[i].ton_npi);
            /* now number is **21*+8123456# */
            mmi_asc_to_ucs2((CHAR*) msisdn_info[i].number, (CHAR*) number);

            srv_phb_send_owner_number_changed_event(sim_interface, i);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_owner_number_set_name_number
 * DESCRIPTION
 *  This function is used to set MSISDN name & number by index.
 * PARAMETERS
 *  sim_interface:      [IN]        SIM1/SIM2
 *  index:              [IN]        LINE1(0)/LINE2(1)
 *  name:               [IN]        MSISDN name
 *  number:             [IN]        MSISDN number
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_owner_number_set_name_number(U8 sim_interface, U16 index, U16 *name, U16 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_interface < MMI_MAX_SIM_NUM && index < SRV_CALLSET_MAX_LINE)
    {
        mmi_wcscpy(g_srv_phb_msisdn_info[sim_interface][index].name, name);
        mmi_wcscpy(g_srv_phb_msisdn_info[sim_interface][index].number, number);
    }
    else
    {
        return;
    }

    srv_phb_send_owner_number_changed_event(sim_interface, index);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_owner_number_get_name
 * DESCRIPTION
 *  This function is used to get MSISDN name by index.
 * PARAMETERS
 *  sim_interface:      [IN]        SIM1/SIM2
 *  index:              [IN]        LINE1(0)/LINE2(1)
 * RETURNS
 *  MSISDN name
 *****************************************************************************/
U16 *srv_phb_owner_number_get_name(U8 sim_interface, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_interface < MMI_MAX_SIM_NUM && index < SRV_CALLSET_MAX_LINE)
    {
        return g_srv_phb_msisdn_info[sim_interface][index].name;
    }
    else
    {
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_owner_number_get_number
 * DESCRIPTION
 *  This function is used to get MSISDN number by index.
 * PARAMETERS
 *  sim_interface:      [IN]        SIM1/SIM2
 *  index:              [IN]        LINE1(0)/LINE2(1)
 * RETURNS
 *  MSISDN number
 *****************************************************************************/
U16 *srv_phb_owner_number_get_number(U8 sim_interface, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_interface < MMI_MAX_SIM_NUM && index < SRV_CALLSET_MAX_LINE)
    {
        return g_srv_phb_msisdn_info[sim_interface][index].number;
    }
    else
    {
        return NULL;
    }
}

#if defined(__MMI_PHB_SPEED_DIAL__)

#define SRV_PHB_SPEED_DIAL

/* 
 * Local Variable
 */
static mmi_phb_speed_dial_struct g_srv_phb_speed_list[MMI_PHB_SPEED_DIAL_COUNT];

/* 
 * Local Function
 */
static void srv_phb_read_speed_dial(void);
static mmi_ret srv_phb_speed_dial_update_cb(mmi_event_struct *evt);
static mmi_ret srv_phb_speed_dial_delete_cb(mmi_event_struct *evt);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_speed_dial_reload
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_speed_dial_reload(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 store_index;
    U16 number[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
    mmi_sim_enum sim;
    U8 index;
    pBOOL sim_available = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0, sim = MMI_SIM1; index < MMI_SIM_TOTAL; index++, sim<<=1)
    {
        if (srv_sim_ctrl_is_available(sim))
        {
            sim_available = MMI_TRUE;
            break;
        }
    }
    if (!sim_available)
    {
        return;
    }

    srv_phb_read_speed_dial();

    for (i = 0; i < MMI_PHB_SPEED_DIAL_COUNT; i++)
    {
        store_index = g_srv_phb_speed_list[i].store_index;

        if (store_index == 0xFFFF)
        {
            g_srv_phb_speed_list[i].is_sync = SRV_PHB_SPEED_DIAL_SYNC_STATUS_FAIL;
        }
        else
        {
            if (store_index < MMI_PHB_PHONE_ENTRIES
            #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
            || store_index >= MMI_PHB_BASIC_ENTRIES
            #endif
                )
            {
                /* Use data stored in NVRAM directly */
            }
            else
            {
                if (srv_phb_check_entry_exist(store_index))
                {
                    if (g_srv_phb_speed_list[i].num_type == SRV_PHB_ENTRY_FIELD_NUMBER)
                    {
                        srv_phb_get_number(store_index, number, MMI_PHB_NUMBER_PLUS_LENGTH);
                        if (srv_phb_compare_number(number, g_srv_phb_speed_list[i].number))
                        {
                            g_srv_phb_speed_list[i].is_sync = SRV_PHB_SPEED_DIAL_SYNC_STATUS_OK;
                        }
                        else
                        {
                            g_srv_phb_speed_list[i].is_sync = SRV_PHB_SPEED_DIAL_SYNC_STATUS_FAIL;
                        }
                    }
                }
                else
                {
                    g_srv_phb_speed_list[i].is_sync = SRV_PHB_SPEED_DIAL_SYNC_STATUS_FAIL;
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_speed_dial_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_speed_dial_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_speed_dial_reload();

    mmi_frm_cb_reg_event(EVT_ID_PHB_UPD_CONTACT, srv_phb_speed_dial_update_cb, NULL);
    mmi_frm_cb_reg_event(EVT_ID_PHB_DEL_CONTACT, srv_phb_speed_dial_delete_cb, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_speed_dial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_read_speed_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_PHB_SPEED_DIAL_COUNT; i++)
    {
        ReadRecord(NVRAM_EF_PHB_SPEEDDIAL_LID, (U16) (i + 1), &g_srv_phb_speed_list[i], NVRAM_EF_PHB_SPEEDDIAL_SIZE, &error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pre_set_speed_dial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 *  store_index     [IN]        
 *  num_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_pre_set_speed_dial(U16 index, U16 store_index, U32 num_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_speed_list[index].is_sync = SRV_PHB_SPEED_DIAL_SYNC_STATUS_ADDING;
    g_srv_phb_speed_list[index].num_type = num_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pre_del_speed_dial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_pre_del_speed_dial(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_speed_list[index].is_sync = SRV_PHB_SPEED_DIAL_SYNC_STATUS_DELING;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_revert_syncing_speed_dial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_revert_syncing_speed_dial(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_phb_speed_list[index].is_sync == SRV_PHB_SPEED_DIAL_SYNC_STATUS_DELING)
    {
        g_srv_phb_speed_list[index].is_sync = SRV_PHB_SPEED_DIAL_SYNC_STATUS_OK;
    }
    else if (g_srv_phb_speed_list[index].is_sync == SRV_PHB_SPEED_DIAL_SYNC_STATUS_ADDING)
    {
        g_srv_phb_speed_list[index].is_sync = SRV_PHB_SPEED_DIAL_SYNC_STATUS_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_write_speed_dial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_write_speed_dial(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(NVRAM_EF_PHB_SPEEDDIAL_LID, (U16) (index + 1), &g_srv_phb_speed_list[index], NVRAM_EF_PHB_SPEEDDIAL_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_update_speed_dial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 *  store_index     [IN]        
 *  number          [IN]        
 *  num_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_update_speed_dial(U16 index, U16 store_index, U16 *number, U32 num_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_speed_list[index].is_sync = SRV_PHB_SPEED_DIAL_SYNC_STATUS_OK;
    g_srv_phb_speed_list[index].store_index = store_index;
    g_srv_phb_speed_list[index].num_type = num_type;
    mmi_wcscpy(g_srv_phb_speed_list[index].number, number);
    srv_phb_write_speed_dial(index);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_delete_speed_dial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_delete_speed_dial(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_srv_phb_speed_list[index], 0xFF, sizeof(mmi_phb_speed_dial_struct));
    srv_phb_write_speed_dial(index);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_speed_dial_is_sync
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  MMI_TRUE if set
 *****************************************************************************/
MMI_BOOL srv_phb_speed_dial_is_sync(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
    if (srv_phb_get_storage(g_srv_phb_speed_list[index].store_index) == PHB_STORAGE_TCARD && srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV) == MMI_FALSE)
    {
        return MMI_FALSE;
    }
    #endif
    return (g_srv_phb_speed_list[index].is_sync == (U8)SRV_PHB_SPEED_DIAL_SYNC_STATUS_OK) ? MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_speed_dial_get_sync_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_phb_speed_dial_get_sync_status(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_phb_speed_list[index].is_sync;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_speed_dial_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_index     [IN]        
 *  num_type        [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_phb_query_speed_dial_key(U16 store_index, U32 num_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_PHB_SPEED_DIAL_COUNT; i++)
    {
        switch (g_srv_phb_speed_list[i].is_sync)
        {
            case SRV_PHB_SPEED_DIAL_SYNC_STATUS_OK:
                if (store_index == g_srv_phb_speed_list[i].store_index &&
                    num_type == g_srv_phb_speed_list[i].num_type)
                {
                    return (U8)(i + 2);
                }
                break;
            case SRV_PHB_SPEED_DIAL_SYNC_STATUS_ADDING:
                if (num_type == g_srv_phb_speed_list[i].num_type)
                {
                    return (U8)(i + 2);
                }
                break;
            case SRV_PHB_SPEED_DIAL_SYNC_STATUS_FAIL:
            default :
                break;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_speed_dial_get_store_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  Speed dial store index
 *****************************************************************************/
U16 srv_phb_speed_dial_get_store_index(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_phb_speed_list[index].store_index;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_speed_dial_get_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  Speed dial name
 *****************************************************************************/
U16 *srv_phb_speed_dial_get_name(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_get_name(g_srv_phb_speed_list[index].store_index, g_srv_phb_speed_list[index].name, MMI_PHB_NAME_LENGTH);
    return g_srv_phb_speed_list[index].name;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_speed_dial_get_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  Speed dial number
 *****************************************************************************/
U16 *srv_phb_speed_dial_get_number(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_phb_speed_list[index].number;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_speed_dial_get_number_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  Speed dial number type
 *****************************************************************************/
U32 srv_phb_speed_dial_get_number_type(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_phb_speed_list[index].num_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_speed_dial_get_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  VIP contact entry
 *****************************************************************************/
mmi_phb_speed_dial_struct *srv_phb_speed_dial_get_entry(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_speed_dial_get_name(index);
    return &g_srv_phb_speed_list[index];
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_speed_dial_update_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt             [IN]        
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret srv_phb_speed_dial_update_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_evt_struct *phb_evt;
    U16 i;
    U16 store_index;
    U16 sub_id;
    srv_phb_contact contact;
    srv_phb_number_struct* number;
    U32 num_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_evt = (srv_phb_op_evt_struct*) evt;
    store_index = phb_evt->id;
    contact = phb_evt->contact;

    for (i = 0; i < MMI_PHB_SPEED_DIAL_COUNT; i++)
    {
        if (srv_phb_speed_dial_is_sync(i) &&
            srv_phb_speed_dial_get_store_index(i) == store_index)
        {
            num_type = srv_phb_speed_dial_get_number_type(i);
            #ifdef __COSMOS_MMI_PACKAGE__
            sub_id = num_type;
            #else
            switch (num_type)
            {
                case SRV_PHB_ENTRY_FIELD_NUMBER:
                    sub_id = 0;
                    break;
                #ifdef __MMI_PHB_OPTIONAL_FIELD__
                case SRV_PHB_ENTRY_FIELD_OPT_NUM_1:
                    sub_id = 1;
                    break;
                    
                case SRV_PHB_ENTRY_FIELD_OPT_NUM_2:
                    sub_id = 2;
                    break;
                    
                case SRV_PHB_ENTRY_FIELD_OPT_NUM_3:
                    sub_id = 3;
                    break;
                #endif             
                default:
                    sub_id = MMI_PHB_SUB_ID_NEW;
                    break;
            }
            #endif
            number = srv_phb_contact_get_number_by_sub_id(contact, sub_id);
            if (number && number->number[0])
                {
                    srv_phb_update_speed_dial(
                        i,
                        store_index,
                        number->number,
                    num_type);
                }
                else
                {
                    srv_phb_delete_speed_dial(i);
                }
            }
        }

    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  srv_phb_speed_dial_delete_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt             [IN]        
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret srv_phb_speed_dial_delete_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_evt_struct *phb_evt;
    U16 i, store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_evt = (srv_phb_op_evt_struct*) evt;
    store_index = phb_evt->store_index;

    for (i = 0; i < MMI_PHB_SPEED_DIAL_COUNT; i++)
    {
        if (srv_phb_speed_dial_is_sync(i) &&
            srv_phb_speed_dial_get_store_index(i) == store_index)
        {
                    srv_phb_delete_speed_dial(i);
        }
    }
    return MMI_RET_OK;
}

#endif /* defined(__MMI_PHB_SPEED_DIAL__) */


#define SRV_PHB_DIALER_DIRECT_DIAL
#ifdef __OP01_FWPBW__

void srv_phb_direct_dial_init(mmi_phb_speed_dial_struct *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_DIALER_DIRECT_DIAL_LID, 1, buf, NVRAM_EF_PHB_SPEEDDIAL_SIZE, &error);
}


void srv_phb_direct_dial_save(U16 index, U16 *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    mmi_phb_speed_dial_struct *temp = (mmi_phb_speed_dial_struct *)srv_phb_mem_malloc(
                                      sizeof(mmi_phb_speed_dial_struct) * MMI_PHB_SPEED_DIAL_COUNT,
                                      SRV_PHB_MEMORY_TYPE_ADM);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_DIALER_DIRECT_DIAL_LID, 1, temp, NVRAM_EF_PHB_SPEEDDIAL_SIZE, &error);
    mmi_wcscpy(temp[index].number, buf);
    if (buf[0])
    {
        temp[index].is_sync = 1;
    }
    else
    {
        temp[index].is_sync = 0;
    }
    WriteRecord(NVRAM_EF_DIALER_DIRECT_DIAL_LID, 1, temp, NVRAM_EF_PHB_SPEEDDIAL_SIZE, &error);
    srv_phb_mem_free(temp);
}


MMI_BOOL srv_phb_get_direct_dial(U16 index, U16 *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    mmi_phb_speed_dial_struct *temp = (mmi_phb_speed_dial_struct *)srv_phb_mem_malloc(
                                      sizeof(mmi_phb_speed_dial_struct) * MMI_PHB_SPEED_DIAL_COUNT,
                                      SRV_PHB_MEMORY_TYPE_ADM);
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_DIALER_DIRECT_DIAL_LID, 1, temp, NVRAM_EF_PHB_SPEEDDIAL_SIZE, &error);
    if (temp[index].is_sync)
    {
        mmi_wcscpy(buf, temp[index].number);
        ret = MMI_TRUE;
    }
    return ret;
}
#endif

#define SRV_PHB_VIP_CONTACT

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_WIDGET_KEY_VIP_CONTACT__)

/* 
 * Local Variable
 */
static mmi_phb_vip_contact_struct g_srv_phb_vip_list[MMI_PHB_VIP_CONTACT_COUNT];

/* 
 * Local Function
 */
static void srv_phb_read_vip_contact(void);
static mmi_ret srv_phb_vip_contact_update_cb(mmi_event_struct *evt);
static mmi_ret srv_phb_vip_contact_delete_cb(mmi_event_struct *evt);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_vip_contact_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_vip_contact_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 store_index;
    U16 number[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
    //mmi_sim_enum sim_id;
    //U8 index;
    pBOOL sim_available = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_read_vip_contact();

    for (i = 0; i < MMI_PHB_VIP_CONTACT_COUNT; i++)
    {
        store_index = g_srv_phb_vip_list[i].store_index;

        if (store_index == 0xFFFF)
        {
            if (g_srv_phb_vip_list[i].is_sync == 2 /* for pre-defined VIP contact */)
            {
                g_srv_phb_vip_list[i].is_sync = MMI_TRUE;
            }
            else
            {
                if (g_srv_phb_vip_list[i].is_sync != MMI_TRUE)
                {
                    g_srv_phb_vip_list[i].is_sync = MMI_FALSE;
                }
            }
        }
        else
        {
            if (store_index < MMI_PHB_PHONE_ENTRIES)
            {
                /* Use data stored in NVRAM directly */
            }
            else
            {
                if (srv_phb_check_entry_exist(store_index))
                {
                    if (g_srv_phb_vip_list[i].num_type == SRV_PHB_ENTRY_FIELD_NUMBER)
                    {
                        srv_phb_get_number(store_index, number, MMI_PHB_NUMBER_PLUS_LENGTH);
                        if (srv_phb_compare_number(number, g_srv_phb_vip_list[i].number))
                        {
                            g_srv_phb_vip_list[i].is_sync = MMI_TRUE;
                            srv_phb_get_name(store_index, g_srv_phb_vip_list[i].name, MMI_PHB_NAME_LENGTH);
                        }
                        else
                        {
                            g_srv_phb_vip_list[i].is_sync = MMI_FALSE;
                        }
                    }
                }
                else
                {
                    g_srv_phb_vip_list[i].is_sync = MMI_FALSE;
                }
            }
        }
    }

    mmi_frm_cb_reg_event(EVT_ID_PHB_UPD_CONTACT, srv_phb_vip_contact_update_cb, NULL);
    mmi_frm_cb_reg_event(EVT_ID_PHB_DEL_CONTACT, srv_phb_vip_contact_delete_cb, NULL);
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    mmi_op11_hs32_con_vip_update();
#endif
#if defined(__MMI_OP11_HOMESCREEN__)
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_vip_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_read_vip_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_PHB_VIP_CONTACT_LID, 1, g_srv_phb_vip_list, NVRAM_EF_PHB_VIP_CONTACT_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_update_vip_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 *  store_index     [IN]        
 *  name            [IN]        
 *  number          [IN]        
 *  num_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_update_vip_contact(U16 index, U16 store_index, U16 *name, U16 *number, U32 num_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_vip_list[index].is_sync = MMI_TRUE;
    g_srv_phb_vip_list[index].store_index = store_index;
    g_srv_phb_vip_list[index].num_type = num_type;
    if (name != NULL && name[0])
    {
        mmi_wcsncpy(g_srv_phb_vip_list[index].name, name, MMI_PHB_NAME_LENGTH);
    }
    if (number != NULL && number[0])
    {
        mmi_wcsncpy(g_srv_phb_vip_list[index].number, number, MMI_PHB_NUMBER_LENGTH);
    }
    WriteRecord(NVRAM_EF_PHB_VIP_CONTACT_LID, 1, g_srv_phb_vip_list, NVRAM_EF_PHB_VIP_CONTACT_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_clear_vip_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_clear_vip_contact(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_srv_phb_vip_list[index], 0xFF, sizeof(mmi_phb_vip_contact_struct));
    WriteRecord(NVRAM_EF_PHB_VIP_CONTACT_LID, 1, g_srv_phb_vip_list, NVRAM_EF_PHB_VIP_CONTACT_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_clear_all_vip_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_clear_all_vip_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_srv_phb_vip_list, 0xFF, NVRAM_EF_PHB_VIP_CONTACT_SIZE);
    WriteRecord(NVRAM_EF_PHB_VIP_CONTACT_LID, 1, g_srv_phb_vip_list, NVRAM_EF_PHB_VIP_CONTACT_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_vip_contact_is_sync
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  MMI_TRUE if set
 *****************************************************************************/
MMI_BOOL srv_phb_vip_contact_is_sync(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_srv_phb_vip_list[index].is_sync == MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_vip_contact_get_store_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  VIP contact store index
 *****************************************************************************/
U16 srv_phb_vip_contact_get_store_index(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_phb_vip_list[index].store_index;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_vip_contact_get_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  VIP contact name
 *****************************************************************************/
U16 *srv_phb_vip_contact_get_name(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_phb_vip_list[index].store_index != 0xFFFF)
    {
        srv_phb_get_name(g_srv_phb_vip_list[index].store_index, g_srv_phb_vip_list[index].name, MMI_PHB_NAME_LENGTH);
    }
    return g_srv_phb_vip_list[index].name;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_vip_contact_get_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  VIP contact number
 *****************************************************************************/
U16 *srv_phb_vip_contact_get_number(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_phb_vip_list[index].number;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_vip_contact_get_number_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  VIP contact number type
 *****************************************************************************/
U32 srv_phb_vip_contact_get_number_type(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_phb_vip_list[index].num_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_vip_contact_get_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  VIP contact entry
 *****************************************************************************/
mmi_phb_vip_contact_struct *srv_phb_vip_contact_get_entry(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(!g_srv_phb_vip_list[index].is_sync ||
        (g_srv_phb_vip_list[index].store_index != SRV_PHB_INVALID_INDEX &&
        srv_phb_datamgr_check_store_index(g_srv_phb_vip_list[index].store_index, MMI_PHB_CONTACT_FIELD_ALL) == MMI_FALSE))
    {
        srv_phb_vip_contact_delete_entry(index);
    }
    srv_phb_vip_contact_get_name(index);
    return &g_srv_phb_vip_list[index];
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_vip_contact_get_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_vip_contact_get_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    for(i = 0; i < MMI_PHB_VIP_CONTACT_COUNT; i++)
    {
        if (g_srv_phb_vip_list[i].is_sync &&
            (g_srv_phb_vip_list[i].name[0] != 0xFFFF || g_srv_phb_vip_list[i].number[0] != 0xFFFF))
        {
            count ++;
        }
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_vip_contact_delete_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_vip_contact_delete_entry(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    for(i = index; i < MMI_PHB_VIP_CONTACT_COUNT - 1; i++)
    {
        memcpy(&g_srv_phb_vip_list[i], &g_srv_phb_vip_list[i + 1], sizeof(mmi_phb_vip_contact_struct));
    }
    memset(&g_srv_phb_vip_list[i], 0xFF, sizeof(mmi_phb_vip_contact_struct));
    WriteRecord(NVRAM_EF_PHB_VIP_CONTACT_LID, 1, g_srv_phb_vip_list, NVRAM_EF_PHB_VIP_CONTACT_SIZE, &error);
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_vip_contact_update_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt             [IN]        
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret srv_phb_vip_contact_update_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_evt_struct *phb_evt;
    U16 i, store_index;
    U16 *name;
    srv_phb_contact contact;
    srv_phb_number_struct* number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_evt = (srv_phb_op_evt_struct*) evt;
    store_index = phb_evt->id;
    name = srv_phb_mem_malloc((MMI_PHB_NAME_LENGTH + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_CTR);
    contact = phb_evt->contact;

    srv_phb_get_name(store_index, name, MMI_PHB_NAME_LENGTH);

    for (i = 0; i < MMI_PHB_VIP_CONTACT_COUNT; i++)
    {
        if (srv_phb_vip_contact_is_sync(i) &&
            srv_phb_vip_contact_get_store_index(i) == store_index)
        {
            switch (srv_phb_vip_contact_get_number_type(i))
            {
                case SRV_PHB_ENTRY_FIELD_NUMBER:
                    number = srv_phb_contact_get_number_by_save_index(contact, 0);
                    break;
            #ifdef __MMI_PHB_OPTIONAL_FIELD__
                case SRV_PHB_ENTRY_FIELD_OPT_NUM_1:
                    number = srv_phb_contact_get_number_by_save_index(contact, 1);
                    break;
                    
                case SRV_PHB_ENTRY_FIELD_OPT_NUM_2:
                    number = srv_phb_contact_get_number_by_save_index(contact, 2);
                    break;
                    
                case SRV_PHB_ENTRY_FIELD_OPT_NUM_3:
                    number = srv_phb_contact_get_number_by_save_index(contact, 3);
                    break;
            #endif /* __MMI_PHB_OPTIONAL_FIELD__ */
            
                default:
                    number = NULL;
                    break;
            }
            if (number)
            {
                if (number->number[0])
                {
                    srv_phb_update_vip_contact(
                        i,
                        store_index,
                        name,
                        number->number,
                        SRV_PHB_ENTRY_FIELD_NUMBER);
                }
                else
                {
                    srv_phb_clear_vip_contact(i);
                }
            }
        }
    }

    srv_phb_mem_free(name);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_vip_contact_delete_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt             [IN]        
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret srv_phb_vip_contact_delete_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_evt_struct *phb_evt;
    U16 i = 0, store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_evt = (srv_phb_op_evt_struct*) evt;
    store_index = phb_evt->store_index;

    while (i < MMI_PHB_VIP_CONTACT_COUNT)
    {
        if (srv_phb_vip_contact_is_sync(i) &&
            srv_phb_vip_contact_get_store_index(i) == store_index)
        {
            #ifdef __MMI_VUI_WIDGET_KEY_VIP_CONTACT__
            srv_phb_vip_contact_delete_entry(i);
            continue;
            #else
            srv_phb_clear_vip_contact(i);
            #endif
        }
        i ++;
    }

    return MMI_RET_OK;
}

#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__) */


#define Yue_Zheng_add_part_begin
static void* xdn_data;
static srv_phb_xdnmgr_callback_type xdn_cb;

static void srv_phb_xdnmgr_toggle_dial_mode_cb(U16 result)
{
    xdn_cb(result, xdn_data);
}


MMI_BOOL srv_phb_xdnmgr_toggle_dial_mode(
    U8 sim_type, 
    phb_type_enum phb_type, 
    srv_phb_xdnmgr_callback_type cb,
    void* user_data)
{
    xdn_data = user_data;
    xdn_cb = cb;
    return srv_phb_xmgnt_toggle_dial_mode(sim_type, phb_type, srv_phb_xdnmgr_toggle_dial_mode_cb);
}


static void srv_phb_xdngnt_get_list_cb(U16 result)
{
    xdn_cb(result, xdn_data);
}

static void srv_phb_xdngnt_get_list_cb_ex(void *result)
{
    xdn_cb(SRV_PHB_XMGNT_RESULT_OK, xdn_data);
}

SRV_PHB_XMGNT_HANDLE srv_phb_xdnmgr_get_list(
        U8 sim_type,
        phb_type_enum phb_type,
        srv_phb_xdnmgr_callback_type list_cb,
        void *user_data)
{
    xdn_data = user_data;
    xdn_cb = list_cb;
    if (phb_type == PHB_FDN)
    {
        srv_phb_async_event_interface(srv_phb_xdngnt_get_list_cb_ex, NULL);
    }
    return srv_phb_xmgnt_get_list(sim_type, phb_type, srv_phb_xdngnt_get_list_cb);
}


static void srv_phb_xdnmgr_save_cb(U16 result)
{
    xdn_cb(result, xdn_data);
}



MMI_BOOL srv_phb_fdnmgr_set_entry(
                    U8 sim_type,
                    U8 phb_type,
                    U16 index,
                    U16 record_index,
                    U16 *name,
                    U16 *number,
                    srv_phb_xdnmgr_callback_type save_cb,
                    SRV_PHB_XMGNT_HANDLE handle,
                    MMI_BOOL is_new,
                    void *user_data)
{
    xdn_data = user_data;
    xdn_cb = save_cb;
    return srv_phb_xmgnt_set_entry(
        sim_type,
        phb_type,
        0xFFFF,
        (U16) ((!is_new) ? index : 0xFFFF),
        name,
        number,
        srv_phb_xdnmgr_save_cb);
}


static void srv_phb_xdnmgr_delete_cb(U16 result)
{
    xdn_cb(result, xdn_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xdnmgr_delete_entry
 * DESCRIPTION
 *  This function is used to delete extra# entry.
 * PARAMETERS
 *  sim_interface:      [IN]        SIM1/SIM2
 *  phb_type:           [IN]        PHB_ECC/PHB_FDN/PHB_BDN/PHB_MSISDN/PHB_SDN
 *  index:              [IN]        PHB entry index
 *  record_index:       [IN]        PHB record index
 *  del_cb:             [IN]        Delete extra# entry callback
 *  user_data:           [IN]      user_data
 * RETURN VALUES
 *  MMI_TRUE:           This request is accepted.
 *  MMI_FALSE:          This request is rejected.
 *****************************************************************************/
extern MMI_BOOL srv_phb_xdnmgr_delete_entry(
                    U8 sim_interface,
                    U8 phb_type,
                    U16 index,
                    U16 record_index,
                    srv_phb_xdnmgr_callback_type del_cb,
                    void *user_data)
{
    xdn_data = user_data;
    xdn_cb = del_cb;
    return srv_phb_xmgnt_delete_entry(
        sim_interface,
        phb_type,
        0xFFFF,
        index,
        srv_phb_xdnmgr_delete_cb);
}

#define Yue_Zheng_add_part_end

#endif /* PHBXMGNTSRV_C */

