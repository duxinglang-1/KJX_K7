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
 *  PhbSdkSrv.c
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef PHBSDKSRV_C
#define PHBSDKSRV_C


/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_include.h"
#include "PhbSrvGprot.h"
#include "PhoneBookGprot.h"
#include "PhbSrv.h"


#include "MMIDataType.h"
#include "kal_general_types.h"
#include "custom_phb_config.h"
#include "MMI_features.h"
#include "Unicodexdcl.h"
#include "ps_public_enum.h"
#include "string.h"

typedef struct
{
    srv_phb_sdk_contact_struct* contact_ptr;
    srv_phb_contact_info_struct contact_info;
    srv_phb_sdk_callback_type cb;
} srv_phb_sdk_cntx_struct;


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
/* Define your local variable here */


/* Declare your local function here */


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/


/***************************************************************************** 
 * Local Function
 *****************************************************************************/
    
    
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sdk_add_contact
 * DESCRIPTION
 *  store data to phonebook
 * PARAMETERS
 *  vcard_data              [IN]        data struct
 *  store_complete_func     [IN]        after store data, call complete cb
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_sdk_op_cb(S32 result, U16 index, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_sdk_cntx_struct* srv_phb_sdk_cntx = (srv_phb_sdk_cntx_struct*)user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((srv_phb_sdk_cntx->contact_ptr) && (result == SRV_PHB_NO_ERROR))
    {
        srv_phb_store_index_to_record_index(
            index, 
            &srv_phb_sdk_cntx->contact_ptr->pos.storage,
            &srv_phb_sdk_cntx->contact_ptr->pos.index);
    }
    srv_phb_sdk_cntx->cb(result, srv_phb_sdk_cntx->contact_ptr);
    srv_phb_mem_free(srv_phb_sdk_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sdk_get_used_contacts   
 * DESCRIPTION
 *  store data to phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_phb_sdk_is_phb_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifndef __COSMOS_MMI_PACKAGE__
    return mmi_phb_check_ready(MMI_FALSE);
    #else
    return srv_phb_startup_is_phb_ready();
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sdk_get_contact 
 * DESCRIPTION
 *  store data to phonebook
 * PARAMETERS
 *  vcard_data              [IN]        data struct
 *  store_complete_func     [IN]        after store data, call complete cb
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_sdk_build_contact_info(srv_phb_contact_info_struct* contact_info, srv_phb_sdk_contact_struct* sdk_contact_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
    S32 i;
    #endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    contact_info->field_mask = SRV_PHB_ENTRY_FIELD_VENDOR;
    contact_info->field_data.name = sdk_contact_ptr->name;
    contact_info->field_data.l_name = NULL;
    contact_info->field_data.number = sdk_contact_ptr->number;

#ifdef __MMI_PHB_OPTIONAL_FIELD__
    for (i = 0; i < MMI_PHB_OPT_NUM_COUNT; i++)
    {
        contact_info->field_data.opt_num[i] = &(sdk_contact_ptr->opt_num[i]);
    }
    contact_info->field_data.opt_order = NULL;
    contact_info->field_data.email_address = sdk_contact_ptr->email_address;
#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
    contact_info->field_data.email_address2 = sdk_contact_ptr->email_address2;
#endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */
    contact_info->field_data.company_name = sdk_contact_ptr->company_name;
#endif /* __MMI_PHB_OPTIONAL_FIELD__ */
#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    contact_info->field_data.b_day = sdk_contact_ptr->birth_day; 
    contact_info->field_data.b_month = sdk_contact_ptr->birth_mon; 
    contact_info->field_data.b_year = sdk_contact_ptr->birth_year;
#endif /* __MMI_PHB_BIRTHDAY_FIELD__ */
#if defined(__MMI_PHB_INFO_FIELD__)
    contact_info->field_data.title = sdk_contact_ptr->title;
    contact_info->field_data.url = sdk_contact_ptr->url;
    contact_info->field_data.pobox = sdk_contact_ptr->adr_pobox;
    contact_info->field_data.extension = sdk_contact_ptr->adr_extension;
    contact_info->field_data.street = sdk_contact_ptr->adr_street;
    contact_info->field_data.city = sdk_contact_ptr->adr_city;
    contact_info->field_data.state = sdk_contact_ptr->adr_state;
    contact_info->field_data.postalcode = sdk_contact_ptr->adr_postal_code;
    contact_info->field_data.country = sdk_contact_ptr->adr_country;
    contact_info->field_data.note = sdk_contact_ptr->note;
#endif /* __MMI_PHB_INFO_FIELD__ */
    contact_info->field_data.group_mask = sdk_contact_ptr->group_mask;
    contact_info->field_data.ringtone_id = 0;
    contact_info->field_data.image_id = 0;
#if defined(__MMI_PHB_CALLER_VIDEO__)
    contact_info->field_data.video_id = 0;
#endif
#if defined(__MMI_IMPS__)
/* under construction !*/
#endif
#if defined(__MMI_VOIP__)
    contact_info->field_data.voip = NULL;
#endif
#ifdef __MMI_PHB_DEFAULT_NUMBER__
    contact_info->field_data.default_number = 0xff;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sdk_add_contact
 * DESCRIPTION
 *  store data to phonebook
 * PARAMETERS
 *  vcard_data              [IN]        data struct
 *  store_complete_func     [IN]        after store data, call complete cb
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_sdk_add_contact(srv_phb_sdk_add_req_struct* req_info, srv_phb_sdk_callback_type cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_sdk_cntx_struct* srv_phb_sdk_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_sdk_cntx = 
        (srv_phb_sdk_cntx_struct*)srv_phb_mem_malloc(sizeof(srv_phb_sdk_cntx_struct), SRV_PHB_MEMORY_TYPE_CTR);

    srv_phb_sdk_cntx->contact_ptr = req_info->contact_ptr;
    
    /* to be remove begin */
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    if (req_info->contact_ptr->home_number[0]
        || req_info->contact_ptr->office_number[0]
        || req_info->contact_ptr->fax_number[0])
    {
        mmi_wcscpy(req_info->contact_ptr->opt_num[0].number, req_info->contact_ptr->home_number);
        req_info->contact_ptr->opt_num[0].type = MMI_PHB_NUM_TYPE_HOME;
        
        mmi_wcscpy(req_info->contact_ptr->opt_num[1].number, req_info->contact_ptr->office_number);
        req_info->contact_ptr->opt_num[1].type = MMI_PHB_NUM_TYPE_OFFICE;
        
        mmi_wcscpy(req_info->contact_ptr->opt_num[2].number, req_info->contact_ptr->fax_number);
        req_info->contact_ptr->opt_num[2].type = MMI_PHB_NUM_TYPE_FAX;
    }
#endif
    /* to be remove end */
    
    srv_phb_sdk_build_contact_info(&(srv_phb_sdk_cntx->contact_info), req_info->contact_ptr);
    srv_phb_sdk_cntx->cb = cb;
    srv_phb_oplib_add_contact((U8)req_info->storage, SRV_PHB_INVALID_INDEX, &(srv_phb_sdk_cntx->contact_info), srv_phb_sdk_op_cb, srv_phb_sdk_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sdk_update_contact
 * DESCRIPTION
 *  store data to phonebook
 * PARAMETERS
 *  vcard_data              [IN]        data struct
 *  store_complete_func     [IN]        after store data, call complete cb
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_sdk_update_contact(srv_phb_sdk_update_req_struct* req_info, srv_phb_sdk_callback_type cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    srv_phb_sdk_cntx_struct* srv_phb_sdk_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_sdk_cntx = 
        (srv_phb_sdk_cntx_struct*)srv_phb_mem_malloc(sizeof(srv_phb_sdk_cntx_struct), SRV_PHB_MEMORY_TYPE_CTR);

    srv_phb_sdk_cntx->contact_ptr = req_info->contact_ptr;
    /* to be remove begin */
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    if (req_info->contact_ptr->home_number[0]
        || req_info->contact_ptr->office_number[0]
        || req_info->contact_ptr->fax_number[0])
    {
        mmi_wcscpy(req_info->contact_ptr->opt_num[0].number, req_info->contact_ptr->home_number);
        req_info->contact_ptr->opt_num[0].type = MMI_PHB_NUM_TYPE_HOME;
        
        mmi_wcscpy(req_info->contact_ptr->opt_num[1].number, req_info->contact_ptr->office_number);
        req_info->contact_ptr->opt_num[1].type = MMI_PHB_NUM_TYPE_OFFICE;
        
        mmi_wcscpy(req_info->contact_ptr->opt_num[2].number, req_info->contact_ptr->fax_number);
        req_info->contact_ptr->opt_num[2].type = MMI_PHB_NUM_TYPE_FAX;
    }
#endif
    /* to be remove end */

    srv_phb_sdk_build_contact_info(&(srv_phb_sdk_cntx->contact_info), req_info->contact_ptr);
    srv_phb_sdk_cntx->cb = cb;
    srv_phb_record_index_to_store_index(req_info->pos.storage, req_info->pos.index, &store_index);
    srv_phb_oplib_update_contact(store_index, &(srv_phb_sdk_cntx->contact_info), srv_phb_sdk_op_cb, srv_phb_sdk_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sdk_delete_contact
 * DESCRIPTION
 *  store data to phonebook
 * PARAMETERS
 *  vcard_data              [IN]        data struct
 *  store_complete_func     [IN]        after store data, call complete cb
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_sdk_delete_contact(srv_phb_sdk_delete_req_struct* req_info, srv_phb_sdk_callback_type cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    srv_phb_sdk_cntx_struct* srv_phb_sdk_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_sdk_cntx = 
        (srv_phb_sdk_cntx_struct*)srv_phb_mem_malloc(sizeof(srv_phb_sdk_cntx_struct), SRV_PHB_MEMORY_TYPE_CTR);
    
    srv_phb_record_index_to_store_index(req_info->pos.storage, req_info->pos.index, &store_index);
    srv_phb_sdk_cntx->contact_ptr = NULL;
    srv_phb_sdk_cntx->cb = cb;
    srv_phb_oplib_delete_contact(store_index, srv_phb_sdk_op_cb, srv_phb_sdk_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sdk_get_contact 
 * DESCRIPTION
 *  store data to phonebook
 * PARAMETERS
 *  vcard_data              [IN]        data struct
 * RETURNS
 *  result
 *****************************************************************************/
S32 srv_phb_sdk_get_contact(srv_phb_sdk_get_req_struct* req_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    S32 result;
    srv_phb_sdk_cntx_struct* srv_phb_sdk_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SDK_GET_CONTACT, req_info->pos.storage, req_info->pos.index);
    srv_phb_sdk_cntx = 
        (srv_phb_sdk_cntx_struct*)srv_phb_mem_malloc(sizeof(srv_phb_sdk_cntx_struct), SRV_PHB_MEMORY_TYPE_CTR);
    
    srv_phb_sdk_cntx->contact_ptr = req_info->contact_ptr;
    srv_phb_sdk_build_contact_info(&(srv_phb_sdk_cntx->contact_info), req_info->contact_ptr);
    srv_phb_record_index_to_store_index(req_info->pos.storage, req_info->pos.index, &store_index);
    result = srv_phb_oplib_get_contact_info(store_index, &(srv_phb_sdk_cntx->contact_info));
    
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SDK_GET_CONTACT_2, store_index, result, req_info->contact_ptr->name);
    if (result == SRV_PHB_NO_ERROR)
    {
    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        req_info->contact_ptr->birth_day = srv_phb_sdk_cntx->contact_info.field_data.b_day;
        req_info->contact_ptr->birth_mon = srv_phb_sdk_cntx->contact_info.field_data.b_month;
        req_info->contact_ptr->birth_year = srv_phb_sdk_cntx->contact_info.field_data.b_year;
    #endif /* __MMI_PHB_BIRTHDAY_FIELD__ */
    
    /* to be remove begin */
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        mmi_wcscpy(req_info->contact_ptr->home_number, req_info->contact_ptr->opt_num[0].number);
        mmi_wcscpy(req_info->contact_ptr->office_number, req_info->contact_ptr->opt_num[1].number);
        mmi_wcscpy(req_info->contact_ptr->fax_number, req_info->contact_ptr->opt_num[2].number);
    #endif
    /* to be remove end */
        req_info->contact_ptr->group_mask = srv_phb_sdk_cntx->contact_info.field_data.group_mask;
    }
    srv_phb_mem_free(srv_phb_sdk_cntx);
    return result;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sdk_search_contact  
 * DESCRIPTION
 *  store data to phonebook
 * PARAMETERS
 *  vcard_data              [IN]        data struct
 * RETURNS
 *  result
 *****************************************************************************/
S32 srv_phb_sdk_search_contact(srv_phb_sdk_search_req_struct* req_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    srv_phb_sdk_cntx_struct* srv_phb_sdk_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_oplib_search(req_info->pattern_ucs2, req_info->search_type);
    if (result >= 0)
    {
        srv_phb_sdk_cntx = 
            (srv_phb_sdk_cntx_struct*)srv_phb_mem_malloc(sizeof(srv_phb_sdk_cntx_struct), SRV_PHB_MEMORY_TYPE_CTR);

        srv_phb_sdk_cntx->contact_ptr = req_info->contact_ptr;
        srv_phb_sdk_build_contact_info(&(srv_phb_sdk_cntx->contact_info), req_info->contact_ptr);
        srv_phb_store_index_to_record_index(
            (U16)result, 
            &req_info->contact_ptr->pos.storage,
            &req_info->contact_ptr->pos.index);
        result = srv_phb_oplib_get_contact_info((U16)result, &(srv_phb_sdk_cntx->contact_info));
        if (result == SRV_PHB_NO_ERROR)
        {
        #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
            req_info->contact_ptr->birth_day = srv_phb_sdk_cntx->contact_info.field_data.b_day;
            req_info->contact_ptr->birth_mon = srv_phb_sdk_cntx->contact_info.field_data.b_month;
            req_info->contact_ptr->birth_year = srv_phb_sdk_cntx->contact_info.field_data.b_year;
        #endif /* __MMI_PHB_BIRTHDAY_FIELD__ */
        
        /* to be remove begin */
        #ifdef __MMI_PHB_OPTIONAL_FIELD__
            mmi_wcscpy(req_info->contact_ptr->home_number, req_info->contact_ptr->opt_num[0].number);
            mmi_wcscpy(req_info->contact_ptr->office_number, req_info->contact_ptr->opt_num[1].number);
            mmi_wcscpy(req_info->contact_ptr->fax_number, req_info->contact_ptr->opt_num[2].number);
        #endif
        /* to be remove end */
            req_info->contact_ptr->group_mask = srv_phb_sdk_cntx->contact_info.field_data.group_mask;
        }
        srv_phb_mem_free(srv_phb_sdk_cntx);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sdk_get_total_contacts   
 * DESCRIPTION
 *  store data to phonebook
 * PARAMETERS
 *  mmi_phb_storage_loc_enum     [IN]        after store data, call complete cb
 * RETURNS
 *  U16
 *****************************************************************************/
S32 srv_phb_sdk_get_total_contacts(phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_phb_sdk_is_phb_ready())
    {
        return SRV_PHB_NOT_READY;
    }
    return srv_phb_datamgr_total_contacts((U8)storage);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sdk_get_used_contacts   
 * DESCRIPTION
 *  store data to phonebook
 * PARAMETERS
 *  mmi_phb_sdk_pos_struct*      [OUT]        data struct
 *  mmi_phb_storage_loc_enum     [IN]        after store data, call complete cb
 * RETURNS
 *  U16
 *****************************************************************************/
S32 srv_phb_sdk_get_used_contacts(srv_phb_contact_pos_struct* pos_array, phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 entry_count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SDK_GET_USED_CONTACT_1, storage, pos_array);
    if (!srv_phb_sdk_is_phb_ready())
    {
        return SRV_PHB_NOT_READY;
    }

    if (pos_array)
    {
        srv_phb_filter_struct filter;
        U16* temp_array;
        S32 i;
        memset(&filter, 0, sizeof(srv_phb_filter_struct));
        filter.field_filter = 0xffff;
        filter.storage = storage;

        temp_array = (U16*)srv_phb_mem_malloc(sizeof(U16) * MMI_PHB_ENTRIES, SRV_PHB_MEMORY_TYPE_ADM);
        entry_count = srv_phb_oplib_build_contact_list(&filter, temp_array, MMI_PHB_ENTRIES);
        for (i = 0; i < entry_count; i++)
        {
            srv_phb_store_index_to_record_index(
                temp_array[i], 
                &pos_array[i].storage,
                &pos_array[i].index);
            MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SDK_GET_USED_CONTACT_2, pos_array[i].storage, pos_array[i].index);
        }
        srv_phb_mem_free(temp_array);
    }
    else
    {
        entry_count = srv_phb_get_used_contact((U8)storage);
    }
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SDK_GET_USED_CONTACT_3, entry_count);
    return entry_count;
}

#endif /* PHBSDKSRV_C */ 

