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
 *  PhbJavaHandlerSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for providing phonebook interface for java package
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)

#include "PhbSrvGprot.h"
#ifdef __J2ME__
#include "Jpim_interface.h"
#include "j2me_custom_option.h"
#endif

#ifdef __MMI_PHB_BIRTHDAY_FIELD__
#include "app_datetime.h"
#endif

#if defined(JSR_75_PIM_EXTRA_IMAGE) && defined(__MMI_FILE_MANAGER__)
#include "Drm_gprot.h"
#include "App_mine.h"
#endif /* defined(JSR_75_PIM_EXTRA_IMAGE) && defined(__MMI_FILE_MANAGER__) */

#include "simctrlsrvgprot.h"
#include "FileMgrType.h"

static void srv_phb_java_write_rsp(U8 result, U16 store_index);
static MMI_BOOL srv_phb_java_check_name_number_data(mmi_phb_handler_entry_struct* entry);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_java_check_entry_data
 * DESCRIPTION
 *  This function return write result to JAVA
 * PARAMETERS
 *  result          [IN]        
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_phb_java_check_entry_data(mmi_phb_handler_entry_struct* entry, U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_remove_invalid_name(entry->name);
    srv_phb_truncate_name(entry->name, storage);
    if (!srv_phb_java_check_name_number_data(entry))
    {
        return MMI_FALSE;
    }

    if (storage != PHB_STORAGE_NVRAM)
    {
        return MMI_TRUE;
    }

#ifdef JSR_75_PIM_EXTRA_BIRTHDAY
#ifdef __MMI_PHB_BIRTHDAY_FIELD__
    if (entry->bDay.nYear || entry->bDay.nMonth || entry->bDay.nDay|| entry->bDay.nHour ||
        entry->bDay.nMin || entry->bDay.nSec || entry->bDay.DayIndex)
    {
        if (!applib_dt_check_valid_by_app(MMI_PHB_BDAY_MIN_YEAR_INT, MMI_PHB_BDAY_MAX_YEAR_INT, &(entry->bDay)))
        {
            srv_phb_java_write_rsp(MMI_PHB_JAVA_BIRTHDAY_ERROR, 0xffff);
            return MMI_FALSE;
        }
    }

#endif /* def __MMI_PHB_BIRTHDAY_FIELD__ */
#endif /* def JSR_75_PIM_EXTRA_BIRTHDAY */

#if defined(JSR_75_PIM_EXTRA_IMAGE)
#if defined(__MMI_FILE_MANAGER__)
    if (entry->phb_image_path[0])
    {
        do
        {
            FS_HANDLE fh;
            MMI_BOOL drm_ret = MMI_TRUE;
            fh = DRM_open_file((kal_wchar*)entry->phb_image_path, FS_READ_ONLY, DRM_PERMISSION_DISPLAY);
            
            if (fh >= FS_NO_ERROR)
            {
            #ifdef __DRM_SUPPORT__
                drm_ret = (MMI_BOOL)DRM_validate_forward_rule(fh, DRM_PERMISSION_DISPLAY);
            #endif
                DRM_close_file(fh);
                if (drm_ret == MMI_TRUE)
                {
                    break;
                }
            }

            srv_phb_java_write_rsp(MMI_PHB_JAVA_IMAGE_ERROR, 0xffff);
            return MMI_FALSE;
        } while (0);
    }
#endif /* __MMI_FILE_MANAGER__ */
#endif /* defined(JSR_75_PIM_EXTRA_IMAGE) */
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_java_write_rsp
 * DESCRIPTION
 *  This function return write result to JAVA
 * PARAMETERS
 *  result          [IN]        
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_java_write_cb(S32 result, U16 store_index, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 java_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result >= 0)
    {
        java_result = MMI_PHB_JAVA_SUCCESS;
    }
    else if (result == SRV_PHB_NUMBER_TOO_LONG)
    {
        java_result = MMI_PHB_JAVA_NUMBER_TOO_LONG;
    }
    else if (result == SRV_PHB_ADN_FORBID)
    {
        java_result = MMI_PHB_JAVA_ADN_FORBID;
    }
    else
    {
        java_result = MMI_PHB_JAVA_ERROR;
    }
    srv_phb_java_write_rsp(java_result, store_index);
}


#ifdef __COSMOS_MMI_PACKAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_search_rsp
 * DESCRIPTION
 *  This function initializes phonebook handler app.
 * PARAMETERS
 *  result          [IN]        
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_java_to_contact(srv_phb_contact *contact, mmi_phb_handler_entry_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_bday_struct birthday;
    S32 i;
    mmi_phb_address_struct* adr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*contact)
    {
        srv_phb_reset_contact(*contact, MMI_PHB_CONTACT_FIELD_ALL);
    }
    else
    {
        *contact = srv_phb_create_contact(NULL);
    }

    srv_phb_contact_set_fname(*contact, entry->name);

    for (i = 0; i < MMI_PHB_NUMBER_FIELD_COUNT; i++)
    {
        if (entry->opt_num[i].number[0])
        {
            srv_phb_contact_add_number_ex(
                    *contact,
                    MMI_PHB_SUB_ID_NEW,
                    0,
                    entry->opt_num[i].type,
                    entry->opt_num[i].number,
                    NULL,
                    MMI_FALSE);
        }
    }

    for (i = 0; i < MMI_PHB_EMAIL_FIELD_COUNT; i++)
    {
        if (entry->emailAddresses[i].email[0])
        {
            srv_phb_contact_add_email_ex(
                *contact,
                MMI_PHB_SUB_ID_NEW,
                0,
                entry->emailAddresses[i].type,
                entry->emailAddresses[i].email,
                NULL);
        }
    }

    if (entry->companyName[0])
    {
        srv_phb_contact_set_company(*contact, entry->companyName);
    }

#ifdef JSR_75_PIM_EXTRA_BIRTHDAY
    birthday.b_year = entry->bDay.nYear;
    birthday.b_month = entry->bDay.nMonth;
    birthday.b_day = entry->bDay.nDay;
    srv_phb_contact_set_bday(*contact, &birthday);
#endif

#ifdef JSR_75_PIM_EXTRA_INFO
    if (entry->title[0])
    {
        srv_phb_contact_set_title(*contact, entry->title);
    }
    if (entry->url[0])
    {
        srv_phb_contact_add_url_ex(
                *contact,
                MMI_PHB_SUB_ID_NEW,
                0,
                entry->url);
    }
    if (!adr)
    {
        adr = srv_phb_mem_malloc(sizeof(mmi_phb_address_struct), SRV_PHB_MEMORY_TYPE_ADM);
        memset(adr, 0x00, sizeof(mmi_phb_address_struct));
    }
    if (entry->adrPOBox[0])
    {
        mmi_wcsncpy(adr->pobox, entry->adrPOBox, MMI_PHB_ADDRESS_LENGTH);
    }
    if (entry->adrExtension[0])
    {
        mmi_wcsncpy(adr->extension, entry->adrExtension, MMI_PHB_ADDRESS_LENGTH);
    }
    if (entry->adrStreet[0])
    {
        mmi_wcsncpy(adr->street, entry->adrStreet, MMI_PHB_ADDRESS_LENGTH);
    }
    if (entry->adrCity[0])
    {
        mmi_wcsncpy(adr->city, entry->adrCity, MMI_PHB_ADDRESS_LENGTH);
    }
    if (entry->adrState[0])
    {
        mmi_wcsncpy(adr->state, entry->adrState, MMI_PHB_ADDRESS_LENGTH);
    }
    if (entry->adrPostalCode[0])
    {
        mmi_wcsncpy(adr->postalcode, entry->adrPostalCode, MMI_PHB_ADDRESS_LENGTH);
    }
    if (entry->adrCountry[0])
    {
        mmi_wcsncpy(adr->country, entry->adrCountry, MMI_PHB_ADDRESS_LENGTH);
    }    
    srv_phb_contact_add_address_ex(
        *contact,
        MMI_PHB_SUB_ID_NEW,
        0,
        adr);
    if (adr)
    {
        srv_phb_mem_free(adr);
    }
    if (entry->note[0])
    {
        srv_phb_contact_add_note_ex(
                *contact,
                MMI_PHB_SUB_ID_NEW,
                0,
                entry->note);
    }
#endif
#ifdef JSR_75_PIM_EXTRA_IMAGE
    if (entry->phb_image_path[0])
    {
        srv_phb_contact_set_image_ex(
                *contact,
                0,
                entry->phb_image_path);
    }
#endif

#ifdef __MMI_PHB_CALLER_GROUP__
    for (i = 0; i < MMI_PHB_GROUP_COUNT; i++)
    {
        if (1 & (entry->group_id >> i))
        {
            srv_phb_contact_set_group_ex(*contact, i);
            break;
        }
    }
#endif /* __MMI_PHB_CALLER_GROUP__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_search_rsp
 * DESCRIPTION
 *  This function initializes phonebook handler app.
 * PARAMETERS
 *  result          [IN]        
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_reset_java_not_support_field(srv_phb_contact *contact, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact_dup = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*contact == NULL)
    {
        return;
    }

    contact_dup = srv_phb_create_contact(NULL);
    srv_phb_read_contact((mmi_phb_contact_id)index, NULL, contact_dup);
    srv_phb_contact_set_ringtone(*contact, srv_phb_contact_get_ringtone(contact_dup));
    srv_phb_free_contact(contact_dup);

    return;
}


static void srv_phb_java_write_cb_handler(srv_phb_async_op_cb_struct *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result->type)
    {
        case SRV_PHB_OP_CB_TYPE_ADD:
        {
            srv_phb_add_cb_struct *obj = (srv_phb_add_cb_struct *)result;
            srv_phb_java_write_cb(obj->result, obj->id, NULL);
            srv_phb_free_handle(result->handle);
            break;
        }
        case SRV_PHB_OP_CB_TYPE_UPD:
        {
            srv_phb_update_cb_struct *obj = (srv_phb_update_cb_struct *)result;
            srv_phb_java_write_cb(obj->result, obj->id, NULL);
            srv_phb_free_handle(result->handle);
            break;
        }
        case SRV_PHB_OP_CB_TYPE_DEL:
        {
            srv_phb_delete_cb_struct *obj = (srv_phb_delete_cb_struct *)result;
            srv_phb_java_write_cb(obj->result, obj->id, NULL);
            srv_phb_free_handle(result->handle);
            break;
        }
        default:
            ASSERT(0);
            break;
    }
}


static void srv_phb_java_updata_add_delete_contact(mmi_phb_handler_set_entry_req_struct *local_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!local_ptr->entry_ptr)
    {
        srv_phb_delete_req_struct req;
        req.id = local_ptr->index;
        req.cb = srv_phb_java_write_cb_handler;
        req.user_data = NULL;
        srv_phb_delete_contact(&req);
        return;
    }
    
    if (local_ptr->index != 0xffff)
    {
        if (srv_phb_check_entry_exist(local_ptr->index))
        {
            local_ptr->storage = srv_phb_get_storage(local_ptr->index);
        }
        else
        {
            srv_phb_java_write_rsp(MMI_PHB_JAVA_OUT_OF_INDEX, 0xffff);
            return;
        }
    }
    if (!srv_phb_java_check_entry_data(local_ptr->entry_ptr, local_ptr->storage))
    {
        return;
    }
    srv_phb_java_to_contact(&contact, local_ptr->entry_ptr);
    
    /* [Add] operation. */
    if (local_ptr->index == 0xffff)
    {
        srv_phb_add_req_struct req;
        req.record_index = MMI_PHB_INVALID_CONTACT_ID;
        req.storage = (phb_storage_enum)local_ptr->storage;
        req.cb = srv_phb_java_write_cb_handler;
        req.contact = contact;
        req.mode = SRV_PHB_UPDATE_MODE_REPLACE;
        req.user_data = NULL;
        srv_phb_add_contact(&req);
    }
    
    /* [Update] operation. */
    else
    {
        srv_phb_update_req_struct req;
        srv_phb_reset_java_not_support_field(&contact, local_ptr->index);
        req.id = local_ptr->index;
        req.cb = srv_phb_java_write_cb_handler;
        req.mode = SRV_PHB_UPDATE_MODE_REPLACE;
        req.contact = contact;
        req.update_field = MMI_PHB_CONTACT_FIELD_ALL;
        req.user_data = NULL;
        srv_phb_update_contact(&req);
    }
        srv_phb_free_contact(contact);
    }


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_search_rsp
 * DESCRIPTION
 *  This function initializes phonebook handler app.
 * PARAMETERS
 *  result          [IN]        
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_java_buffer_init(mmi_phb_handler_entry_struct* entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(entry, 0x00, sizeof(mmi_phb_handler_entry_struct));
    entry->store_index = 0xffff;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_search_rsp
 * DESCRIPTION
 *  This function initializes phonebook handler app.
 * PARAMETERS
 *  result          [IN]        
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_contact_to_java(srv_phb_contact *contact, mmi_phb_handler_entry_struct* entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_iterator iter;
    srv_phb_number_struct* number;
    srv_phb_email_struct* email;
    srv_phb_bday_struct* birthday;
    srv_phb_address_struct* address;
    srv_phb_url_struct* url;
    srv_phb_note_struct* note;
    S32 index = 0;
    WCHAR *temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_java_buffer_init(entry);
    temp = srv_phb_contact_get_name(*contact);
    if (temp)
    {
        mmi_wcscpy(entry->name, srv_phb_contact_get_name(*contact));
    }
    
    iter = srv_phb_contact_get_number_iterator(*contact);
    while (iter && index < MMI_PHB_NUMBER_FIELD_COUNT)
    {
        number = srv_phb_contact_get_number_next(&iter);
        if (number)
        {
            mmi_wcscpy(entry->opt_num[index].number, number->number);
            entry->opt_num[index].type = (mmi_phb_num_type_enum)number->type;
        }
        index++;
    }

    index = 0;
    iter = srv_phb_contact_get_email_iterator(*contact);
    while (iter && index < MMI_PHB_EMAIL_FIELD_COUNT)
    {
        email = srv_phb_contact_get_email_next(&iter);
        if (email)
        {
            mmi_wcscpy(entry->emailAddresses[index].email, email->email);
            entry->emailAddresses[index].type = (mmi_phb_email_type_enum)email->type;
        }
        index++;
    }

    temp = srv_phb_contact_get_company(*contact);
    if (temp)
    {
        mmi_wcscpy(entry->companyName, srv_phb_contact_get_company(*contact));
    }    

#ifdef JSR_75_PIM_EXTRA_BIRTHDAY
    birthday = srv_phb_contact_get_bday(*contact);
    if (birthday)
    {
        entry->bDay.nYear = birthday->b_year;
        entry->bDay.nMonth = birthday->b_month;
        entry->bDay.nDay = birthday->b_day;
    }
#endif

#ifdef JSR_75_PIM_EXTRA_INFO
    temp = srv_phb_contact_get_title(*contact);
    if (temp)
    {
        mmi_wcscpy(entry->title, srv_phb_contact_get_title(*contact));
    } 
    iter = srv_phb_contact_get_url_iterator(*contact);
    url = srv_phb_contact_get_url_next(&iter);
    if (url)
    {
        mmi_wcscpy(entry->url, url->url);
    }
    iter = srv_phb_contact_get_address_iterator(*contact);
    address = srv_phb_contact_get_address_next(&iter);
    if (address)
    {
        mmi_wcscpy(entry->adrPOBox, address->address.pobox);
        mmi_wcscpy(entry->adrExtension, address->address.extension);
        mmi_wcscpy(entry->adrStreet, address->address.street);
        mmi_wcscpy(entry->adrCity, address->address.city);
        mmi_wcscpy(entry->adrState, address->address.state);
        mmi_wcscpy(entry->adrPostalCode, address->address.postalcode);
        mmi_wcscpy(entry->adrCountry, address->address.country);
    }
    iter = srv_phb_contact_get_note_iterator(*contact);
    note = srv_phb_contact_get_note_next(&iter);
    if (note)
    {
        mmi_wcscpy(entry->note, note->note);
    }
#endif

#ifdef JSR_75_PIM_EXTRA_IMAGE
    if (srv_phb_contact_get_image(*contact) && srv_phb_contact_get_image(*contact)->res_path[0])
    {
        mmi_wcscpy(entry->phb_image_path, srv_phb_contact_get_image(*contact)->res_path);
    }
#endif

#ifdef __MMI_PHB_CALLER_GROUP__
    if (srv_phb_contact_get_group(*contact))
    {
        srv_phb_group_struct *group_info = srv_phb_contact_get_group(*contact);
        entry->group_id = (U32)(1 << group_info->group_id[0]);
    }
#endif

#ifdef JSR_75_PIM_EXTRA_PREFERRED_NUMBER
    entry->preferred_no = 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_search_rsp
 * DESCRIPTION
 *  This function initializes phonebook handler app.
 * PARAMETERS
 *  result          [IN]        
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_java_get_contact_info(U16 store_index, mmi_phb_handler_entry_struct* entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    srv_phb_field_filter filter;
    U16 index = entry->sort_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filter = srv_phb_create_field_filter_ext(MMI_PHB_CONTACT_FIELD_ALL);
    contact = srv_phb_read_contact(store_index, filter, NULL);
    srv_phb_contact_to_java(&contact, entry);
    srv_phb_free_field_filter(filter);
    srv_phb_free_contact(contact);
    entry->store_index = store_index;
    entry->sort_index = index;
}


static MMI_BOOL srv_phb_java_check_name_number_data(mmi_phb_handler_entry_struct* entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_PHB_NUMBER_FIELD_COUNT; i++)
    {
        srv_phb_remove_invalid_number(entry->opt_num[i].number);
        srv_phb_truncate_number(entry->opt_num[i].number);
        if (!srv_phb_check_valid_number(entry->opt_num[i].number))
        {
            srv_phb_java_write_rsp(MMI_PHB_JAVA_ERROR, 0xffff);
            return MMI_FALSE;
        }
    }

    if ((!entry->name[0] && !entry->opt_num[0].number[0]))
    {
        srv_phb_java_write_rsp(MMI_PHB_JAVA_ERROR, 0xffff);
        return MMI_FALSE;
    }

    return MMI_TRUE;
}
#else
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_search_rsp
 * DESCRIPTION
 *  This function initializes phonebook handler app.
 * PARAMETERS
 *  result          [IN]        
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_java_build_contact_info(srv_phb_contact_info_struct* contact_info, mmi_phb_handler_entry_struct* entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(contact_info, 0, sizeof(srv_phb_contact_info_struct));
    contact_info->field_mask = (SRV_PHB_ENTRY_FIELD_SIM | SRV_PHB_ENTRY_FIELD_GROUP | SRV_PHB_ENTRY_FIELD_DEF);

    contact_info->field_data.name = entry->name;
    contact_info->field_data.number = entry->number;

#ifdef __MMI_PHB_OPTIONAL_FIELD__
    contact_info->field_mask |= (SRV_PHB_ENTRY_FIELD_OPTIONAL_NUM | SRV_PHB_ENTRY_FIELD_COMPANY | SRV_PHB_ENTRY_FIELD_EMAIL1);
    contact_info->field_data.opt_num[0] = &(entry->opt_num[0]);
    contact_info->field_data.opt_num[1] = &(entry->opt_num[1]);
    contact_info->field_data.opt_num[2] = &(entry->opt_num[2]);
    contact_info->field_data.company_name = entry->companyName;
    contact_info->field_data.email_address = entry->emailAddress;
#if defined(JSR_75_PIM_EXTRA_EMAIL2) && defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
    contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_EMAIL2;
    contact_info->field_data.email_address2 = entry->emailAddress2;
#endif /* defined(JSR_75_PIM_EXTRA_EMAIL2) && defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__) */
#else /* clear buffer */
    entry->homeNumber[0] = 0;
    entry->companyName[0] = 0;
    entry->emailAddress[0] = 0;
#if defined(JSR_75_PIM_EXTRA_EMAIL2) && defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
    entry->emailAddress2[0] = 0;
#endif /* defined(JSR_75_PIM_EXTRA_EMAIL2) && defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__) */
    entry->officeNumber[0] = 0;
    entry->faxNumber[0] = 0;
#endif /* __MMI_PHB_OPTIONAL_FIELD__ */
#if defined(__MMI_PHB_DEFAULT_NUMBER__) && defined(JSR_75_PIM_EXTRA_PREFERRED_NUMBER)
    contact_info->field_data.default_number = entry->preferred_no;
#else
    contact_info->field_data.default_number = 0xff;
#endif

#ifdef JSR_75_PIM_EXTRA_BIRTHDAY
#ifdef __MMI_PHB_BIRTHDAY_FIELD__
    contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_BDAY;
    contact_info->field_data.b_year = entry->bDay.nYear;
    contact_info->field_data.b_month = entry->bDay.nMonth;
    contact_info->field_data.b_day = entry->bDay.nDay;
#endif /* __MMI_PHB_BIRTHDAY_FIELD__ */
#endif /* JSR_75_PIM_EXTRA_BIRTHDAY */

#if defined(JSR_75_PIM_EXTRA_INFO)
#if defined(__MMI_PHB_INFO_FIELD__)
    contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_INFO;
    contact_info->field_data.title = entry->title;
    contact_info->field_data.url = entry->url;
    contact_info->field_data.pobox = entry->adrPOBox;
    contact_info->field_data.extension = entry->adrExtension;
    contact_info->field_data.street = entry->adrStreet;
    contact_info->field_data.city = entry->adrCity;
    contact_info->field_data.state = entry->adrState;
    contact_info->field_data.postalcode = entry->adrPostalCode;
    contact_info->field_data.country = entry->adrCountry;
    contact_info->field_data.note = entry->note;
#endif /* __MMI_PHB_INFO_FIELD__ */
#endif /* defined(JSR_75_PIM_EXTRA_INFO) */

#ifdef JSR_75_PIM_EXTRA_IMAGE
    contact_info->field_mask |= SRV_PHB_ENTRY_FIELD_PIC;
    contact_info->field_data.image_path = entry->phb_image_path;
    if (entry->phb_image_path[0])
    {
        contact_info->field_data.res_type = SRV_PHB_RES_TYPE_IMAGE_FILE;
    }
#endif

#ifdef __MMI_PHB_CALLER_GROUP__
    contact_info->field_data.group_mask = entry->group_id;
#endif
}


static void srv_phb_java_updata_add_delete_contact(mmi_phb_handler_set_entry_req_struct *local_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_info_struct contact_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (local_ptr->entry_ptr == NULL)
    {
        srv_phb_oplib_delete_contact(local_ptr->index, srv_phb_java_write_cb, NULL);
        return;
    }
    
    if (local_ptr->index != 0xffff)
    {
        if (srv_phb_check_entry_exist(local_ptr->index))
        {
            local_ptr->storage = srv_phb_get_storage(local_ptr->index);
        }
        else
        {
            srv_phb_java_write_rsp(MMI_PHB_JAVA_OUT_OF_INDEX, 0xffff);
            return;
        }
    }
    if (!srv_phb_java_check_entry_data(local_ptr->entry_ptr, local_ptr->storage))
    {
        return;
    }
    srv_phb_java_build_contact_info(&contact_info, local_ptr->entry_ptr);
    /* [Add] operation. */
    if (local_ptr->index == 0xffff)
    {
        srv_phb_oplib_add_contact(local_ptr->storage, SRV_PHB_INVALID_INDEX, &contact_info, srv_phb_java_write_cb, NULL);
    }
    /* [Update] operation. */
    else
    {
        srv_phb_oplib_update_contact(local_ptr->index, &contact_info, srv_phb_java_write_cb, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_search_rsp
 * DESCRIPTION
 *  This function initializes phonebook handler app.
 * PARAMETERS
 *  result          [IN]        
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_java_get_contact_info(U16 store_index, mmi_phb_handler_entry_struct* entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_info_struct contact_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry->store_index = store_index;
    srv_phb_java_build_contact_info(&contact_info, entry);
    srv_phb_oplib_get_contact_info((U16)store_index, &contact_info);
#if defined(__MMI_PHB_DEFAULT_NUMBER__) && defined(JSR_75_PIM_EXTRA_PREFERRED_NUMBER)
    entry->preferred_no = contact_info.field_data.default_number;
#endif

#ifdef __MMI_PHB_CALLER_GROUP__
    entry->group_id = contact_info.field_data.group_mask;
#endif

#ifdef JSR_75_PIM_EXTRA_BIRTHDAY
#ifdef __MMI_PHB_BIRTHDAY_FIELD__
    entry->bDay.nYear = contact_info.field_data.b_year;
    entry->bDay.nMonth = contact_info.field_data.b_month;
    entry->bDay.nDay = contact_info.field_data.b_day;
#endif /* __MMI_PHB_BIRTHDAY_FIELD__ */
#endif /* JSR_75_PIM_EXTRA_BIRTHDAY */
}


static MMI_BOOL srv_phb_java_check_name_number_data(mmi_phb_handler_entry_struct* entry)
{
    srv_phb_remove_invalid_number(entry->number);
    srv_phb_truncate_number(entry->number);
    if ((!entry->name[0] && !entry->number[0]) ||
        (!srv_phb_check_valid_number(entry->number)))
    {
        srv_phb_java_write_rsp(MMI_PHB_JAVA_ERROR, 0xffff);
        return MMI_FALSE;
    }

#ifdef __MMI_PHB_OPTIONAL_FIELD__
    srv_phb_remove_invalid_number(entry->homeNumber);
    srv_phb_remove_invalid_number(entry->officeNumber);
    srv_phb_remove_invalid_number(entry->faxNumber);

    srv_phb_truncate_number(entry->homeNumber);
    srv_phb_truncate_number(entry->officeNumber);
    srv_phb_truncate_number(entry->faxNumber);
#endif /* __MMI_PHB_OPTIONAL_FIELD__ */
    if ((!srv_phb_check_valid_number(entry->homeNumber)) ||
        (!srv_phb_check_valid_number(entry->officeNumber)) ||
        (!srv_phb_check_valid_number(entry->officeNumber)))
    {
        srv_phb_java_write_rsp(MMI_PHB_JAVA_ERROR, 0xffff);
        return MMI_FALSE;
    }

    return MMI_TRUE;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_phb_java_write_rsp
 * DESCRIPTION
 *  This function return write result to JAVA
 * PARAMETERS
 *  result          [IN]        
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_java_write_rsp(U8 result, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_handler_set_entry_rsp_struct *msg_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_ptr = (mmi_phb_handler_set_entry_rsp_struct*) OslConstructDataPtr(sizeof(mmi_phb_handler_set_entry_rsp_struct));

    msg_ptr->result = result;
    msg_ptr->store_index = store_index;
    mmi_frm_send_ilm(MOD_JASYN, MSG_ID_MMI_PHB_JAVA_SET_ENTRY_RSP, (oslParaType*)msg_ptr, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_java_write_req
 * DESCRIPTION
 *  This function write a phonebook entry from JAVA request
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_java_write_req(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_handler_set_entry_req_struct *local_ptr = (mmi_phb_handler_set_entry_req_struct*) info;
    U8 storage = local_ptr->storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_phb_startup_is_phb_ready())
    {
        srv_phb_java_write_rsp(MMI_PHB_JAVA_NOT_READY, 0xffff);
        return;
    }
    if (local_ptr->index == 0xffff)
    {
        if ((storage >= PHB_STORAGE_SIM) &&
            (storage <= PHB_STORAGE_SIM4) &&
            !srv_sim_ctrl_is_available(mmi_frm_index_to_sim(srv_phb_get_sim_id(storage))))
        {
            srv_phb_java_write_rsp(MMI_PHB_JAVA_NO_SIM_CARD, 0xffff);
            return;
        }
        if (srv_phb_get_used_contact(storage) == srv_phb_get_total_contact(storage))
        {
            srv_phb_java_write_rsp(MMI_PHB_JAVA_STORAGE_FULL, 0xffff);
            return;
        }
        /* Check free space and assign storage location */
        if (storage == PHB_STORAGE_MAX)
        {
            for (storage = PHB_STORAGE_NVRAM; storage < PHB_STORAGE_MAX; storage ++)
            {
                if (srv_phb_get_used_contact(storage) != srv_phb_get_total_contact(storage))
            {
                    local_ptr->storage = storage;
                    break;
            }
            }
        }
    }
    srv_phb_java_updata_add_delete_contact(local_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_java_read_rsp
 * DESCRIPTION
 *  This function initializes phonebook handler app.
 * PARAMETERS
 *  result      [IN]        
 *  count       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_java_read_rsp(U8 result, U16 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_handler_get_entry_rsp_struct *msg_ptr;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_ptr = (mmi_phb_handler_get_entry_rsp_struct*) OslConstructDataPtr(sizeof(mmi_phb_handler_get_entry_rsp_struct));

    msg_ptr->result = result;
    msg_ptr->count = count;
    mmi_frm_send_ilm(MOD_JASYN, MSG_ID_MMI_PHB_JAVA_GET_ENTRY_RSP, (oslParaType*) msg_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_read_req
 * DESCRIPTION
 *  This function initializes phonebook handler app.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_java_read_req(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    mmi_phb_handler_get_entry_req_struct *local_ptr = (mmi_phb_handler_get_entry_req_struct*) info;
    U8 storage = local_ptr->storage;
    U16 index;
    U16 count = 0;
    U16 store_index = 0;
    U16 req_count = local_ptr->count;
    U16 used_count = srv_phb_get_used_contact(storage);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_phb_startup_is_phb_ready())
    {
        srv_phb_java_read_rsp(MMI_PHB_JAVA_NOT_READY, 0);
        return;
    }
    if ((req_count > 0) && (local_ptr->entry_ptr != NULL))
    {
         index = local_ptr->index;
        if (index > used_count)
        {
            srv_phb_java_read_rsp(MMI_PHB_JAVA_OUT_OF_INDEX, 0);
            return;
        }
        if (local_ptr->sort_type == MMI_PHB_BY_NAME)
        {
            while ((index <= used_count) && (count < req_count))
            {
                store_index = srv_phb_sort_index_to_store_index(storage, index);
                local_ptr->entry_ptr[count].sort_index = index;
                srv_phb_java_get_contact_info(store_index, &local_ptr->entry_ptr[count++]);
            }

            srv_phb_java_read_rsp(MMI_PHB_JAVA_SUCCESS, count);
            return;
        }
    }
    else if (local_ptr->count == 0)
    {
        srv_phb_java_read_rsp(MMI_PHB_JAVA_SUCCESS, used_count);
        return;   
    }
    srv_phb_java_read_rsp(MMI_PHB_JAVA_NOT_SUPPORT, 0);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_java_search_rsp
 * DESCRIPTION
 *  This function initializes phonebook handler app.
 * PARAMETERS
 *  result          [IN]        
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_java_search_rsp(U8 result, U16 sort_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_handler_search_entry_rsp_struct *msg_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_ptr =
        (mmi_phb_handler_search_entry_rsp_struct*)
        OslConstructDataPtr(sizeof(mmi_phb_handler_search_entry_rsp_struct));

    /* Decide error cause */
    msg_ptr->result = result;
    msg_ptr->index = sort_index;
    mmi_frm_send_ilm(MOD_JASYN, MSG_ID_MMI_PHB_JAVA_SEARCH_ENTRY_RSP, (oslParaType*) msg_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_search_req
 * DESCRIPTION
 *  This function initializes phonebook handler app.
 * PARAMETERS
 *  info        [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_java_search_req(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    srv_phb_search_type_enum search_type;
    mmi_phb_handler_search_entry_req_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_phb_handler_search_entry_req_struct*) info;

    if (!srv_phb_startup_is_phb_ready())
    {
        srv_phb_java_search_rsp(MMI_PHB_JAVA_NOT_READY, 0xffff);
        return;
    }
    if (!local_ptr->pattern[0] && !local_ptr->pattern[1])
    {
        srv_phb_java_search_rsp(MMI_PHB_JAVA_NOT_FOUND, 0xffff);
        return;
    }
    if (local_ptr->sort_type != MMI_PHB_BY_NAME)
    {
        srv_phb_java_search_rsp(MMI_PHB_JAVA_NOT_SUPPORT, 0xffff);
        return;
    }

    /* Search by name */
    if (local_ptr->search_type == MMI_PHB_BY_NAME)
    {
        search_type = SRV_PHB_SEARCH_TYPE_NAME;
    }
    /* Search by number */
    else if (local_ptr->search_type == MMI_PHB_BY_NUMBER)
    {
        search_type = SRV_PHB_SEARCH_TYPE_NUM;
    }
    else
    {
        srv_phb_java_search_rsp(MMI_PHB_JAVA_NOT_SUPPORT, 0xffff);
        return;
    }
    result = srv_phb_oplib_search((U16*)local_ptr->pattern, search_type);
    if (result >= 0)
    {
        srv_phb_java_get_contact_info((U16)result, local_ptr->entry_ptr);
        srv_phb_java_search_rsp(
            MMI_PHB_JAVA_SUCCESS, 
            srv_phb_store_index_to_sort_index(local_ptr->storage, (U16)result));
    }
    else
    {
        srv_phb_java_search_rsp(MMI_PHB_JAVA_NOT_FOUND, 0xffff);
    }
}


/*****************************************************************************
* FUNCTION
 *  mmi_phb_java_get_group_info_rsp
* DESCRIPTION
*   This function initializes phonebook handler app.
* PARAMETERS
 *  result      [IN]        
 *  count       [IN]        
 * RETURNS
*  void
 *****************************************************************************/
static void srv_phb_java_get_group_info_rsp(U8 result, U8 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_handler_get_group_info_rsp_struct *msg_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_ptr = (mmi_phb_handler_get_group_info_rsp_struct*) OslConstructDataPtr(sizeof(mmi_phb_handler_get_group_info_rsp_struct));

    msg_ptr->result = result;
    msg_ptr->count = count;
    mmi_frm_send_ilm(MOD_JASYN, MSG_ID_MMI_PHB_JAVA_GET_GROUP_INFO_RSP, (oslParaType*) msg_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_java_get_group_info_req
 * DESCRIPTION
 *  This function gets group information.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_java_get_group_info_req(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    mmi_phb_handler_get_group_info_req_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_phb_handler_get_group_info_req_struct*) info;

    if (!srv_phb_startup_is_phb_ready())
    {
        srv_phb_java_get_group_info_rsp(MMI_PHB_JAVA_NOT_READY, 0);
        return;
    }

#ifdef __MMI_PHB_CALLER_GROUP__
        if (local_ptr->group_ptr == NULL)
        {
            U8 group_array[MMI_PHB_GROUP_COUNT];
            count = srv_phb_get_group_list(group_array, NULL, PHB_STORAGE_NVRAM);
            srv_phb_java_get_group_info_rsp(MMI_PHB_JAVA_SUCCESS, count);
            return;
        }
    if ((local_ptr->storage == PHB_STORAGE_MAX) || (local_ptr->storage == PHB_STORAGE_NVRAM))
    {
        if (local_ptr->max_group > 0)
        {
            /* Copy group information by assigned count number */
            S32 i;
            U8 group_array[MMI_PHB_GROUP_COUNT];
            U16 *group_name = OslMalloc((MMI_PHB_GROUP_NAME_LENGTH + 1) * MMI_PHB_GROUP_COUNT * sizeof(U16));
            count = srv_phb_get_group_list(group_array, group_name, PHB_STORAGE_NVRAM);
            count = count > local_ptr->max_group ? local_ptr->max_group : count;
            for (i = 0; i < count; i++)
            {
                local_ptr->group_ptr[i].group_id = group_array[i];
                mmi_wcscpy(
                    local_ptr->group_ptr[i].group_name,
                    group_name + i * (MMI_PHB_GROUP_NAME_LENGTH + 1));
            }
            OslMfree(group_name);
            srv_phb_java_get_group_info_rsp(MMI_PHB_JAVA_SUCCESS, count);
            return;
        }

    }
#endif /* __MMI_PHB_CALLER_GROUP__ */
    srv_phb_java_get_group_info_rsp(MMI_PHB_JAVA_ERROR, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_set_group_info_rsp
 * DESCRIPTION
 *  This function return set group info result to JAVA
 * PARAMETERS
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_java_set_group_info_rsp(U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_handler_set_group_info_rsp_struct *msg_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_ptr = (mmi_phb_handler_set_group_info_rsp_struct*) OslConstructDataPtr(sizeof(mmi_phb_handler_set_group_info_rsp_struct));

    msg_ptr->result = result;
    mmi_frm_send_ilm(MOD_JASYN, MSG_ID_MMI_PHB_JAVA_SET_GROUP_INFO_RSP, (oslParaType*) msg_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_java_set_group_info_cb
 * DESCRIPTION
 *  call back function of set group information
 * PARAMETERS
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_java_set_group_info_cb(S32 result, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result >= 0)
    {
        srv_phb_java_set_group_info_rsp(MMI_PHB_JAVA_SUCCESS);
    }
    else
    {
        srv_phb_java_set_group_info_rsp(MMI_PHB_JAVA_ERROR);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_java_set_group_info_req
 * DESCRIPTION
 *  This function write a group name from JAVA request
 * PARAMETERS
 *  info        [IN]     
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_java_set_group_info_req(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_handler_set_group_info_req_struct *local_ptr;
    S32 result = SRV_PHB_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_phb_handler_set_group_info_req_struct*) info;
    if (!srv_phb_startup_is_phb_ready())
    {
       srv_phb_java_set_group_info_rsp(MMI_PHB_JAVA_NOT_READY);
       return;
    }

#ifdef __MMI_PHB_CALLER_GROUP__
    if (local_ptr->group_ptr != NULL)
    {
        srv_phb_group_info_struct group_info;
        if (local_ptr->group_id < MMI_PHB_GROUP_COUNT)
        {
            /* Update group name operation. */
            srv_phb_get_group_info(local_ptr->group_id, &group_info);
            mmi_wcsncpy(group_info.group_name, (U16*)local_ptr->group_ptr->group_name, MMI_PHB_GROUP_NAME_LENGTH);
            group_info.cb = srv_phb_java_set_group_info_cb;
            group_info.user_data = NULL;
            srv_phb_update_group_info(local_ptr->group_id, &group_info);
        }
        else
        {
            /* add group */
            memset(&group_info, 0, sizeof(srv_phb_group_info_struct));
            mmi_wcsncpy(group_info.group_name, (U16*)local_ptr->group_ptr->group_name, MMI_PHB_GROUP_NAME_LENGTH);
            group_info.cb = srv_phb_java_set_group_info_cb;
            srv_phb_add_group(&group_info);
        }
    }
    else
    {
        srv_phb_delete_group(local_ptr->group_id, srv_phb_java_set_group_info_cb, NULL);
        if (local_ptr->delete_list_ptr)
        {
            srv_phb_filter_struct filter;
            srv_phb_group_filter_struct group_filter;
            filter.storage = PHB_STORAGE_NVRAM;
            filter.field_filter = SRV_PHB_ENTRY_FIELD_ALL;
            filter.name_filter = NULL;
            filter.qsearch_filter = NULL;
            filter.group_filter = &group_filter;
            group_filter.group_mask = 0xFFFF;
            group_filter.is_equal = MMI_FALSE;
            result = srv_phb_oplib_build_contact_list(&filter, local_ptr->delete_list_ptr->list, MMI_PHB_PHONE_ENTRIES);
            local_ptr->delete_list_ptr->count = result;
        }
    }
#else /* __MMI_PHB_CALLER_GROUP__ */
    srv_phb_java_set_group_info_rsp(MMI_PHB_JAVA_ERROR);
#endif /* __MMI_PHB_CALLER_GROUP__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_java_handler_init
 * DESCRIPTION
 *  This function initializes phonebook handler app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_java_handler_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(srv_phb_java_write_req, MSG_ID_MMI_PHB_JAVA_SET_ENTRY_REQ);
    SetProtocolEventHandler(srv_phb_java_read_req, MSG_ID_MMI_PHB_JAVA_GET_ENTRY_REQ);
    SetProtocolEventHandler(srv_phb_java_search_req, MSG_ID_MMI_PHB_JAVA_SEARCH_ENTRY_REQ);
    SetProtocolEventHandler(srv_phb_java_get_group_info_req, MSG_ID_MMI_PHB_JAVA_GET_GROUP_INFO_REQ);
    SetProtocolEventHandler(srv_phb_java_set_group_info_req, MSG_ID_MMI_PHB_JAVA_SET_GROUP_INFO_REQ);
}
#endif /* defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC) */ 
