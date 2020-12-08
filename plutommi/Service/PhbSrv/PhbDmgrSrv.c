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
 *  PhbDmgrSrv.c
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_include.h"
#include "PhbSrvGprot.h"
#include "PhbSrv.h"
#include "DataMgr.h"
#include "mmi_rp_srv_phb_def.h"
#include "FileMgrSrvGProt.h"
#include "SimCtrlSrvGprot.h"

#include "MMIDataType.h"
#include "MMI_features.h"
#include "kal_general_types.h"
#include "custom_phb_config.h"
#include "ps_public_enum.h"
#include "Unicodexdcl.h"
#include "nvram_common_defs.h"
#include "string.h"
#include "mmi_frm_nvram_gprot.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "customer_email_num.h"
#include "app_datetime.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "mcd_l4_common.h"
#include "ps_public_struct.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "mmi_msg_struct.h"
#include "sim_common_enums.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "PhbSrvIprot.h"
#include "fs_func.h"
#include "fs_type.h"


#define SRV_PHB_MAX_PATH_LENGTH      64
#define SRV_PHB_DRV                  SRV_FMGR_PUBLIC_DRV
#define SRV_PHB_RES_DATA_FILE        L"phb_video.dat"

#define SRV_PHB_DMGR_SIM1_READY        0x01
#define SRV_PHB_DMGR_SIM2_READY        0x02
#define SRV_PHB_DMGR_PHONE_READY       0x04
#define SRV_PHB_DMGR_PHONE_INIT        0x08
#define SRV_PHB_DMGR_SIM3_READY        0x10
#define SRV_PHB_DMGR_SIM4_READY        0x20

#if (MMI_MAX_SIM_NUM == 2)
#define SRV_PHB_DMGR_READY (SRV_PHB_DMGR_PHONE_READY | SRV_PHB_DMGR_SIM1_READY | SRV_PHB_DMGR_SIM2_READY)
#elif (MMI_MAX_SIM_NUM == 3)
#define SRV_PHB_DMGR_READY (SRV_PHB_DMGR_PHONE_READY | SRV_PHB_DMGR_SIM1_READY | SRV_PHB_DMGR_SIM2_READY | SRV_PHB_DMGR_SIM3_READY)
#elif (MMI_MAX_SIM_NUM == 4)
#define SRV_PHB_DMGR_READY (SRV_PHB_DMGR_PHONE_READY | SRV_PHB_DMGR_SIM1_READY | SRV_PHB_DMGR_SIM2_READY | SRV_PHB_DMGR_SIM3_READY | SRV_PHB_DMGR_SIM4_READY)
#else
#define SRV_PHB_DMGR_READY (SRV_PHB_DMGR_PHONE_READY | SRV_PHB_DMGR_SIM1_READY)
#endif

typedef struct
{
    U8 status;
#ifdef __SRV_PHB_CALLER_RES_DATA_STORE__
    mmi_data_record_store_type record_store;
#if defined(__MMI_PHB_CALLER_VIDEO__)
    mmi_data_record_store_type record_store_2;
#endif /* defined(__MMI_PHB_CALLER_VIDEO__) */
#endif /* __SRV_PHB_CALLER_RES_DATA_STORE__ */
} srv_phb_datamgr_cntx_struct;


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
/* Define your local variable here */




/* Declare your local function here */


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
 
srv_phb_datamgr_cntx_struct g_srv_phb_datamgr_cntx;
srv_phb_datamgr_op_cntx_struct g_srv_phb_datamgr_op_cntx;


/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_set_startup_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_phb_datamgr_get_status_by_storage(phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (storage)
    {
        case PHB_STORAGE_NVRAM:
            return SRV_PHB_DMGR_PHONE_READY;
            
        case PHB_STORAGE_SIM:
            return SRV_PHB_DMGR_SIM1_READY;
            
    #if (MMI_MAX_SIM_NUM >= 2)
        case PHB_STORAGE_SIM2:
            return SRV_PHB_DMGR_SIM2_READY;
    #endif
    
    #if (MMI_MAX_SIM_NUM >= 3)
        case PHB_STORAGE_SIM3:
            return SRV_PHB_DMGR_SIM3_READY;
    #endif
                
    #if (MMI_MAX_SIM_NUM >= 4)
        case PHB_STORAGE_SIM4:
            return SRV_PHB_DMGR_SIM4_READY;
    #endif

        default:
            ASSERT (0);
    }
    return 0;
}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ind_startup_read
 * DESCRIPTION
 *  This function receives the read indication from L4 Phb at bootup time.
 *  Stores each indication to the global phonebook list.
 * PARAMETERS
 *  info        [IN]        Indication from L4 PHB
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_phb_datamgr_check_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_srv_phb_datamgr_cntx.status & SRV_PHB_DMGR_READY) == SRV_PHB_DMGR_READY)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_send_set_contact_rsp
 * DESCRIPTION
 *  request message to L4 for delete one entry
 * PARAMETERS
 *  storage      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_datamgr_op_fail(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_fail_struct* status = (srv_phb_op_fail_struct*)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_DMGR_OP_RESULT, 
        status->id, status->result, g_srv_phb_datamgr_op_cntx.op_type);

    status->cb(status->result, status->id, status->user_data);
    srv_phb_mem_free(status);
}


#define EXTERNAL_FUNCTION
/***************************************************************************** 
 * Global Function 
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_clear_res_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *          
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_datamgr_clear_res_path(U32 field_mask, U16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SRV_PHB_CALLER_RES_DATA_STORE__
    mmi_data_record_store_type* record_store;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_PHB_CALLER_VIDEO__)
    if (field_mask == MMI_PHB_CONTACT_FIELD_VIDEO)
    {
        record_store = &g_srv_phb_datamgr_cntx.record_store_2;
    }
    else
#endif /* defined(__MMI_PHB_CALLER_VIDEO__) */
    {
        record_store = &g_srv_phb_datamgr_cntx.record_store;
    }
    mmi_data_delete_record(record_store, (U16)(id & 0x3FFF));
#endif /* __SRV_PHB_CALLER_RES_DATA_STORE__ */
} 


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_update_res_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *          
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_phb_datamgr_update_res_path(U32 field_mask, U16 original_id, MMI_BOOL original_type, U16* new_id, MMI_BOOL new_type, U16* res_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SRV_PHB_CALLER_RES_DATA_STORE__
    mmi_data_record_store_type* record_store;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_PHB_CALLER_RES_DATA_STORE__
#if defined(__MMI_PHB_CALLER_VIDEO__)
    if (field_mask == MMI_PHB_CONTACT_FIELD_VIDEO)
    {
        record_store = &g_srv_phb_datamgr_cntx.record_store_2;
    }
    else
#endif /* defined(__MMI_PHB_CALLER_VIDEO__) */
    {
        record_store = &g_srv_phb_datamgr_cntx.record_store;
    }

    if (original_type)
    {
        mmi_data_delete_record(record_store, (U16)(original_id & 0x3FFF));
    }
#endif /* __SRV_PHB_CALLER_RES_DATA_STORE__ */

    if (new_type)
    {
#ifdef __SRV_PHB_CALLER_RES_DATA_STORE__
        if (!res_path || mmi_data_add_record(record_store, new_id, res_path) != 0)
#endif /* __SRV_PHB_CALLER_RES_DATA_STORE__ */
        {
            *new_id = 0;
            return MMI_FALSE;
        }
    }
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_DMGR_UPD_RES, field_mask, original_id, original_type, *new_id, new_type);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_get_res_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *       
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_phb_datamgr_get_res_path(U32 field_mask, U16 index, U16 from_file, U16* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SRV_PHB_CALLER_RES_DATA_STORE__
    mmi_data_record_store_type* record_store;
    S32 result = 1;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *path = 0;
    if (from_file)
    {
#ifdef __SRV_PHB_CALLER_RES_DATA_STORE__
    #if defined(__MMI_PHB_CALLER_VIDEO__)
        if (field_mask == MMI_PHB_CONTACT_FIELD_VIDEO)
        {
            record_store = &g_srv_phb_datamgr_cntx.record_store_2;
        }
        else
    #endif /* defined(__MMI_PHB_CALLER_VIDEO__) */
        {
            record_store = &g_srv_phb_datamgr_cntx.record_store;
        }
        if ((result = mmi_data_get_record(record_store, index, path)) == 0)
        {
            MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_DMGR_UPD_RES, field_mask, index, from_file);
            return 1;
        }
        else
        {
            return result;
        }
#else
    return 0;
#endif /* __SRV_PHB_CALLER_RES_DATA_STORE__ */
    }
    return 1;
}



/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_res_check_data_space
 * DESCRIPTION
 *  Check free space in data record before save to phonebook.
 * PARAMETERS
 *  field_mask        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_phb_datamgr_res_check_data_space(U32 field_mask)
{
#ifdef __SRV_PHB_CALLER_RES_DATA_STORE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 attr = 0;
    S32 result;
    mmi_data_record_store_type* record_store;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PHB_CALLER_VIDEO__)
    if (field_mask == MMI_PHB_CONTACT_FIELD_VIDEO)
    {
        record_store = &g_srv_phb_datamgr_cntx.record_store_2;
    }
    else
#endif /* defined(__MMI_PHB_CALLER_VIDEO__) */
    {
        record_store = &g_srv_phb_datamgr_cntx.record_store;
    }
    attr = FS_GetAttributes((const WCHAR*)record_store->db_file);
    if (attr & FS_ATTR_READ_ONLY)
    {
        FS_SetAttributes((const WCHAR*)record_store->db_file, (U8) (attr & ~(FS_ATTR_READ_ONLY)));
    }
    result = mmi_data_check_space_for_add_record(record_store);
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_DMGR_CHECK_SPACE, field_mask, result);
    return result;
#else
    return -1;
#endif /* __SRV_PHB_CALLER_RES_DATA_STORE__ */
}



/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_used_contacts
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_phb_datamgr_used_contacts(U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 used;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(storage)
    {
        case PHB_STORAGE_SIM:
        case PHB_STORAGE_SIM2:
        case PHB_STORAGE_SIM3:
        case PHB_STORAGE_SIM4:
        {
            used = srv_phb_get_sim_used((phb_storage_enum)storage);
            break;
        }
        case PHB_STORAGE_NVRAM:
        {
            used = srv_phb_get_phone_used();
            break;
        }
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        case PHB_STORAGE_TCARD:
        {
            used = srv_phb_get_tcard_used_count();
            break;
        }
        #endif
        case PHB_STORAGE_MAX:
        default:
        {
            used = srv_phb_get_phone_used() + srv_phb_get_sim_used((phb_storage_enum)storage);
            #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
            used += srv_phb_get_tcard_used_count();
            #endif
        }
    }
    return used;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_total_contacts
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_phb_datamgr_total_contacts(U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 total;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (storage == PHB_STORAGE_NVRAM)
    {
        total = srv_phb_get_phone_total();
    }
    else if (storage >= PHB_STORAGE_SIM && storage <= PHB_STORAGE_SIM4)
    {
        total = srv_phb_get_sim_total((phb_storage_enum)storage);
    }
    #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
    else if (storage == PHB_STORAGE_TCARD)
    {
        total = srv_phb_get_tcard_total_count();
    }
    #endif
    else
    {
        total = srv_phb_get_phone_total() + srv_phb_get_sim_total((phb_storage_enum)storage);
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        total += srv_phb_get_tcard_total_count();
        #endif
    }
    return total;    
}




/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_check_store_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_phb_datamgr_check_store_index(mmi_phb_contact_id id, U32 field_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 field_mask = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_srv_phb_datamgr_cntx.status & SRV_PHB_DMGR_READY) == SRV_PHB_DMGR_READY)
    {
        if (id < MMI_PHB_PHONE_ENTRIES)
        {
            field_mask = srv_phb_get_phone_field_mask(id);
        }
        else if (id < MMI_PHB_BASIC_ENTRIES)
        {
            field_mask = srv_phb_get_sim_field_mask(id);
        }
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        else if (id < MMI_PHB_ENTRIES)
        {
            field_mask = srv_phb_get_tcard_field_mask(id);
        }
        #endif
        if (field_mask & field_type)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_get_field_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_datamgr_get_field_mask(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 field_mask = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id < MMI_PHB_PHONE_ENTRIES)
    {
        field_mask = srv_phb_get_phone_field_mask(id);
    }
    else if (id < MMI_PHB_BASIC_ENTRIES)
    {
        field_mask = srv_phb_get_sim_field_mask(id);
    }
    #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
    else if (id < MMI_PHB_ENTRIES)
    {
        field_mask = srv_phb_get_tcard_field_mask(id);
    }
    #endif
    return field_mask;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_get_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_datamgr_get_name(mmi_phb_contact_id id, WCHAR* name, S32 out_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (name)
    {
        if (id >= MMI_PHB_ENTRIES + MMI_PHB_FDN_TOTAL_ENTRIES)
        {
            name[0] = 0;
        }
        else if (id >= MMI_PHB_ENTRIES)
        {
            mmi_wcsncpy(name, srv_phb_xmgnt_get_fdn_name(id), out_len);
        }
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        else if (id >= MMI_PHB_BASIC_ENTRIES)
        {
            srv_phb_convert_to_name(
                name,
                srv_phb_get_tcard_fname(id),
                srv_phb_get_tcard_lname(id),
                out_len);
        }
        #endif
        else if (id >= MMI_PHB_PHONE_ENTRIES)
        {
            mmi_wcsncpy(name, srv_phb_get_sim_name(id), out_len);
        }
        else
        {
            srv_phb_convert_to_name(
                name,
                srv_phb_get_phone_fname(id),
                srv_phb_get_phone_lname(id),
                out_len);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_get_num_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_phb_datamgr_get_num_count(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id >= MMI_PHB_ENTRIES)
    {
        return 0;
    }
    #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
    else if (id >= MMI_PHB_BASIC_ENTRIES)
    {
        return srv_phb_get_tcard_num_count(id);
    }
    #endif
    else if (id >= MMI_PHB_PHONE_ENTRIES && id < MMI_PHB_BASIC_ENTRIES)
    {
        return srv_phb_get_sim_num_count(id);
    }
    else
    {
        return srv_phb_get_phone_num_count(id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_get_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
CHAR* srv_phb_datamgr_get_number(mmi_phb_contact_id id, U8 save_index, U8* type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id < MMI_PHB_PHONE_ENTRIES && save_index < MMI_PHB_NUMBER_FIELD_COUNT)
    {
        mmi_phb_optional_fields_struct* optional_fields_data = srv_phb_get_phone_optional_field(id);
        if (type)
        {
            *type = (U8)(optional_fields_data->num[save_index].type);
        }
        return (CHAR*)(optional_fields_data->num[save_index].number);
    }
    else if (id < MMI_PHB_BASIC_ENTRIES)
    {
        return srv_phb_get_sim_number(id, save_index, type);
    }
    #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
    else if (id < MMI_PHB_ENTRIES && save_index < MMI_PHB_NUMBER_FIELD_COUNT)
    {
        return srv_phb_get_tcard_number(id, save_index, NULL, type, NULL);
    }
    #endif
    return NULL;
}



/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_get_email_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_phb_datamgr_get_email_count(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id >= MMI_PHB_ENTRIES)
    {
        return 0;
    }
    else if (id >= MMI_PHB_PHONE_ENTRIES && id < MMI_PHB_BASIC_ENTRIES)
    {
        return srv_phb_get_sim_email_count(id);
    }
    else
    {
        return srv_phb_get_phone_email_count(id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_get_email
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
CHAR* srv_phb_datamgr_get_email(mmi_phb_contact_id id, U8 save_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id >= MMI_PHB_PHONE_ENTRIES && id < MMI_PHB_BASIC_ENTRIES)
    {
        return srv_phb_get_sim_email(id, save_index);
    }
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
    else if (save_index < MMI_PHB_NUMBER_FIELD_COUNT)
    {
        if (id < MMI_PHB_PHONE_ENTRIES)
        {
            mmi_phb_optional_fields_struct* optional_fields_data = srv_phb_get_phone_optional_field(id);
            return (CHAR*)(optional_fields_data->email_address[save_index].email);
        }
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        else
        {
            return srv_phb_get_tcard_email(id, save_index, NULL, NULL);
        }
        #endif
    }
    #endif
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_datamgr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SRV_PHB_CALLER_RES_DATA_STORE__
    U16 path[SRV_PHB_MAX_PATH_LENGTH];
#ifdef __MMI_PHB_CALLER_VIDEO__
    MMI_BOOL use_tcard = MMI_FALSE;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(path, "%c:\\%w", SRV_PHB_DRV, SRV_PHB_RES_DATA_FILE);
    /* May need to check if init successfully here. */
    if (mmi_data_init_record_store(
                &g_srv_phb_datamgr_cntx.record_store,
                (CHAR*)path,
                (SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH) != 0)
    {
#ifdef __MMI_PHB_CALLER_VIDEO__
        use_tcard = MMI_TRUE;
#endif
        kal_wsprintf(path, "%c:\\%w", SRV_FMGR_CARD_DRV, SRV_PHB_RES_DATA_FILE);
        if (mmi_data_init_record_store(
                &g_srv_phb_datamgr_cntx.record_store,
                (CHAR*)path,
                (SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH) != 0)
        {
            return;
        }
    }
    
#if defined(__MMI_PHB_CALLER_VIDEO__)
    if (use_tcard)
    {
        kal_wsprintf(path, "%c:\\ex_%w", SRV_FMGR_CARD_DRV, SRV_PHB_RES_DATA_FILE);
    }
    else
    {
        kal_wsprintf(path, "%c:\\ex_%w", SRV_PHB_DRV, SRV_PHB_RES_DATA_FILE);
    }
    /* May need to check if init successfully here. */
    mmi_data_init_record_store(
                &g_srv_phb_datamgr_cntx.record_store_2,
                (CHAR*)path,
                (SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH);
#endif /* defined(__MMI_PHB_CALLER_VIDEO__) */
#endif /* __SRV_PHB_CALLER_RES_DATA_STORE__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_set_startup_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_datamgr_set_startup_ready(phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_DMGR_STARTUP_SET_READY, storage, g_srv_phb_datamgr_cntx.status);
    g_srv_phb_datamgr_cntx.status |= srv_phb_datamgr_get_status_by_storage(storage);
    if ((srv_phb_datamgr_check_ready()))
    {
        srv_phb_startup_datamgr_ready_hdlr();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ind_startup_read
 * DESCRIPTION
 *  This function receives the read indication from L4 Phb at bootup time.
 *  Stores each indication to the global phonebook list.
 * PARAMETERS
 *  info        [IN]        Indication from L4 PHB
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_datamgr_startup_read_sim_finish(U8 sim_interface, U16 sim_total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_sim_startup_read_finish(sim_interface, sim_total);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ind_startup_read
 * DESCRIPTION
 *  This function receives the read indication from L4 Phb at bootup time.
 *  Stores each indication to the global phonebook list.
 * PARAMETERS
 *  info        [IN]        Indication from L4 PHB
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_datamgr_startup_read_sim_begin(srv_phb_startup_sim_init_cntx *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_interface = info->sim_interface;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_phb_datamgr_op_cntx.is_busy)
    {
        g_srv_phb_datamgr_op_cntx.is_busy = MMI_FALSE;
        srv_phb_stop_op();
        g_srv_phb_datamgr_op_cntx.cb(SRV_PHB_ERROR, SRV_PHB_INVALID_INDEX, g_srv_phb_datamgr_op_cntx.user_data);
    }
#if (MMI_MAX_SIM_NUM >= 2)
    if (sim_interface == SIM2)
    {
        g_srv_phb_datamgr_cntx.status &= ~SRV_PHB_DMGR_SIM2_READY;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if (sim_interface == SIM3)
    {
        g_srv_phb_datamgr_cntx.status &= ~SRV_PHB_DMGR_SIM3_READY;
    }
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    else if (sim_interface == SIM4)
    {
        g_srv_phb_datamgr_cntx.status &= ~SRV_PHB_DMGR_SIM4_READY;
    }
#endif
    else
#endif /* MMI_MAX_SIM_NUM */
    {
        g_srv_phb_datamgr_cntx.status &= ~SRV_PHB_DMGR_SIM1_READY;
    }
    srv_phb_sim_reset(info);
    /* bootup read phone contact, sim refresh */
    if (!(g_srv_phb_datamgr_cntx.status & SRV_PHB_DMGR_PHONE_INIT))
    {
        g_srv_phb_datamgr_cntx.status |= SRV_PHB_DMGR_PHONE_INIT;
        srv_phb_init_phone_name();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_set_field_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_datamgr_set_field_mask(mmi_phb_contact_id id, U32 filed_flag, MMI_BOOL exist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id > MMI_PHB_PHONE_ENTRIES)
    {
        srv_phb_set_sim_field_mask(id, filed_flag, exist);
    }
    else
    {
        srv_phb_set_phone_field_mask(id, filed_flag, exist);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_commit_all_field_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_datamgr_commit_all_field_mask(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_commit_all_phone_field_mask();
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_read_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_datamgr_read_contact(mmi_phb_contact_id id, srv_phb_contact contact, srv_phb_field_filter filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_DMGR_READ_CONTACT, id, srv_phb_datamgr_get_field_mask(id));
    if (id < MMI_PHB_PHONE_ENTRIES)
    {
        srv_phb_read_phone_contact(id, contact, filter);
    }
    else if (id < MMI_PHB_BASIC_ENTRIES)
    {
        srv_phb_read_sim_contact(id, contact, filter);
    }
    #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
    else
    {
        srv_phb_read_tcard_contact(id, contact, filter);
    }
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_get_op_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_phb_datamgr_op_cntx_struct* srv_phb_datamgr_get_op_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_srv_phb_datamgr_op_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_send_set_contact_rsp
 * DESCRIPTION
 *  request message to L4 for delete one entry
 * PARAMETERS
 *  storage      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_phb_datamgr_op_done(srv_phb_datamgr_op_status_struct* status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_DMGR_OP_RESULT, 
        status->id, status->result, g_srv_phb_datamgr_op_cntx.op_type);
    if (g_srv_phb_datamgr_op_cntx.is_busy)
    {
        if (status->result >= 0)
        {
            srv_phb_op_evt_struct evt;
            U16 evt_id = 0;
            switch (g_srv_phb_datamgr_op_cntx.op_type)
            {
                case SRV_PHB_DATAMGR_OP_TYPE_ADD:
                case SRV_PHB_DATAMGR_OP_TYPE_COPY:
                    evt_id = EVT_ID_PHB_ADD_CONTACT;
                    break;
                    
                case SRV_PHB_DATAMGR_OP_TYPE_UPD:
                    evt_id = EVT_ID_PHB_UPD_CONTACT;
                    break;

                case SRV_PHB_DATAMGR_OP_TYPE_DEL:
                    evt_id = EVT_ID_PHB_DEL_CONTACT;
                    g_srv_phb_datamgr_op_cntx.contact = NULL;
                    break;
                    
                default:
                    break;
            }

            MMI_FRM_INIT_EVENT(&evt, evt_id);
            evt.id = status->id;
            evt.store_index = status->id;
            evt.contact = g_srv_phb_datamgr_op_cntx.contact;
            evt.update_field = g_srv_phb_datamgr_op_cntx.update_field;            
            MMI_FRM_CB_EMIT_EVENT(&evt);
        }
        g_srv_phb_datamgr_op_cntx.is_busy = MMI_FALSE;
        g_srv_phb_datamgr_op_cntx.cb(status->result, status->id, g_srv_phb_datamgr_op_cntx.user_data);
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_add_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_datamgr_add_contact(srv_phb_datamgr_add_req_struct* req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_fail_struct* status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_DMGR_ADD_CONTACT, g_srv_phb_datamgr_op_cntx.is_busy, req->storage, req->record_index, MMI_PHB_CONTACT_FIELD_ALL);

    if (!g_srv_phb_datamgr_op_cntx.is_busy)
    {
        g_srv_phb_datamgr_op_cntx.is_busy = MMI_TRUE;
        g_srv_phb_datamgr_op_cntx.op_type = SRV_PHB_DATAMGR_OP_TYPE_ADD;
        g_srv_phb_datamgr_op_cntx.mode = req->mode;
        g_srv_phb_datamgr_op_cntx.update_field = srv_phb_get_support_field((phb_storage_enum)req->storage);
        g_srv_phb_datamgr_op_cntx.pos.index = req->record_index;
        g_srv_phb_datamgr_op_cntx.pos.storage = req->storage;
        g_srv_phb_datamgr_op_cntx.contact = req->contact;
        g_srv_phb_datamgr_op_cntx.cb = req->cb;
        g_srv_phb_datamgr_op_cntx.user_data = req->user_data;

        if (req->storage == PHB_STORAGE_NVRAM)
        {
            srv_phb_write_phone_contact();
            return;
        }
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        else if (req->storage == PHB_STORAGE_TCARD)
        {
            srv_phb_write_tcard_contact();
            return;
        }
        #endif
        else
        {
            if (srv_phb_write_sim_contact())
            {
                return;
            }
            status = srv_phb_mem_malloc(sizeof(srv_phb_op_fail_struct), SRV_PHB_MEMORY_TYPE_CTR);
            status->result = SRV_PHB_NAME_NUM_EMPTY;
            g_srv_phb_datamgr_op_cntx.is_busy = MMI_FALSE;
        }
    }
    else
    {
        status = srv_phb_mem_malloc(sizeof(srv_phb_op_fail_struct), SRV_PHB_MEMORY_TYPE_CTR);
        status->result = SRV_PHB_DATAMGR_BUSY;
    }
    status->id = (mmi_phb_contact_id)(req->record_index);
    status->cb = req->cb;
    status->user_data = req->user_data;
    srv_phb_async_event_interface(srv_phb_datamgr_op_fail, status);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_update_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_datamgr_update_contact(srv_phb_datamgr_update_req_struct* req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_fail_struct* status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_DMGR_UPD_CONTACT, g_srv_phb_datamgr_op_cntx.is_busy, req->id, req->update_field);

    if (!g_srv_phb_datamgr_op_cntx.is_busy)
    {
        g_srv_phb_datamgr_op_cntx.is_busy = MMI_TRUE;
        g_srv_phb_datamgr_op_cntx.op_type = SRV_PHB_DATAMGR_OP_TYPE_UPD;
        g_srv_phb_datamgr_op_cntx.mode = req->mode;
        srv_phb_store_index_to_record_index(
            req->id, 
            &g_srv_phb_datamgr_op_cntx.pos.storage,
            &g_srv_phb_datamgr_op_cntx.pos.index);
        g_srv_phb_datamgr_op_cntx.update_field = (req->update_field & srv_phb_get_support_field((phb_storage_enum)g_srv_phb_datamgr_op_cntx.pos.storage));
        g_srv_phb_datamgr_op_cntx.contact = req->contact;
        g_srv_phb_datamgr_op_cntx.cb = req->cb;
        g_srv_phb_datamgr_op_cntx.user_data = req->user_data;
        
        if (g_srv_phb_datamgr_op_cntx.pos.storage == PHB_STORAGE_NVRAM)
        {
            srv_phb_write_phone_contact();
            return;
        }
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        else if (g_srv_phb_datamgr_op_cntx.pos.storage == PHB_STORAGE_TCARD)
        {
            srv_phb_write_tcard_contact();
            return;
        }
        #endif
        else
        {
            if (srv_phb_write_sim_contact())
            {
                return;
            }
            status = srv_phb_mem_malloc(sizeof(srv_phb_op_fail_struct), SRV_PHB_MEMORY_TYPE_CTR);
            status->result = SRV_PHB_NAME_NUM_EMPTY;
            g_srv_phb_datamgr_op_cntx.is_busy = MMI_FALSE;
        }
    }
    else
    {
        status = srv_phb_mem_malloc(sizeof(srv_phb_op_fail_struct), SRV_PHB_MEMORY_TYPE_CTR);
        status->result = SRV_PHB_DATAMGR_BUSY;
    }
    status->id = req->id;
    status->cb = req->cb;
    status->user_data = req->user_data;
    srv_phb_async_event_interface(srv_phb_datamgr_op_fail, status);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_delete_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_datamgr_delete_contact(srv_phb_datamgr_delete_req_struct* req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_DMGR_DEL_CONTACT, g_srv_phb_datamgr_op_cntx.is_busy, req->id);

    if (!g_srv_phb_datamgr_op_cntx.is_busy)
    {
        g_srv_phb_datamgr_op_cntx.is_busy = MMI_TRUE;
        g_srv_phb_datamgr_op_cntx.op_type = SRV_PHB_DATAMGR_OP_TYPE_DEL;
        srv_phb_store_index_to_record_index(
            req->id, 
            &g_srv_phb_datamgr_op_cntx.pos.storage,
            &g_srv_phb_datamgr_op_cntx.pos.index);
        g_srv_phb_datamgr_op_cntx.cb = req->cb;
        g_srv_phb_datamgr_op_cntx.user_data = req->user_data;
        
        if (g_srv_phb_datamgr_op_cntx.pos.storage == PHB_STORAGE_NVRAM)
        {
            srv_phb_delete_phone_contact(&g_srv_phb_datamgr_op_cntx.pos);
        }
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        else if (g_srv_phb_datamgr_op_cntx.pos.storage == PHB_STORAGE_TCARD)
        {
            srv_phb_delete_tcard_contact(&g_srv_phb_datamgr_op_cntx.pos);
        }
        #endif
        else
        {
            srv_phb_delete_sim_contact(&g_srv_phb_datamgr_op_cntx.pos);
        }
    }
    else
    {
        srv_phb_op_fail_struct* status = srv_phb_mem_malloc(sizeof(srv_phb_op_fail_struct), SRV_PHB_MEMORY_TYPE_CTR);
        status->result = SRV_PHB_DATAMGR_BUSY;
        status->id = req->id;
        status->cb = req->cb;
        status->user_data = req->user_data;
        srv_phb_async_event_interface(srv_phb_datamgr_op_fail, status);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_copy_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_datamgr_copy_contact(srv_phb_datamgr_copy_req_struct* req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_fail_struct* status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_DMGR_COPY_CONTACT, g_srv_phb_datamgr_op_cntx.is_busy, req->id);

    if (!g_srv_phb_datamgr_op_cntx.is_busy)
    {
        g_srv_phb_datamgr_op_cntx.is_busy = MMI_TRUE;
        g_srv_phb_datamgr_op_cntx.op_type = SRV_PHB_DATAMGR_OP_TYPE_COPY;
        g_srv_phb_datamgr_op_cntx.src_id = req->id;
        g_srv_phb_datamgr_op_cntx.pos.index = SRV_PHB_INVALID_INDEX;
        g_srv_phb_datamgr_op_cntx.pos.storage = req->storage,
        g_srv_phb_datamgr_op_cntx.contact = NULL;
        g_srv_phb_datamgr_op_cntx.cb = req->cb;
        g_srv_phb_datamgr_op_cntx.user_data = req->user_data;
        g_srv_phb_datamgr_op_cntx.update_field = srv_phb_datamgr_get_field_mask(req->id);
        
        if (g_srv_phb_datamgr_op_cntx.pos.storage == PHB_STORAGE_NVRAM)
        {
            srv_phb_copy_phone_contact(g_srv_phb_datamgr_op_cntx.src_id);
            return;
        }
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        else if(g_srv_phb_datamgr_op_cntx.pos.storage == PHB_STORAGE_TCARD)
        {
            srv_phb_copy_tcard_contact();
            return;
        }
        #endif
        else
        {
            if (srv_phb_copy_sim_contact())
            {
                return;
            }
            status = srv_phb_mem_malloc(sizeof(srv_phb_op_fail_struct), SRV_PHB_MEMORY_TYPE_CTR);
            status->result = SRV_PHB_NAME_NUM_EMPTY;
            g_srv_phb_datamgr_op_cntx.is_busy = MMI_FALSE;
        }
    }
    else
    {
        status = srv_phb_mem_malloc(sizeof(srv_phb_op_fail_struct), SRV_PHB_MEMORY_TYPE_CTR);
        status->result = SRV_PHB_DATAMGR_BUSY;
    }
    status->id = req->id;
    status->cb = req->cb;
    status->user_data = req->user_data;
    srv_phb_async_event_interface(srv_phb_datamgr_op_fail, status);
}
