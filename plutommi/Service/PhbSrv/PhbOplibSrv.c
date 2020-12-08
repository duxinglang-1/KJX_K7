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
 *  PhbOplibSrv.c
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef PHBOPLIBSRV_C
#define PHBOPLIBSRV_C


/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_include.h"
#include "FileMgrSrvGProt.h"
#include "PhbSrvGprot.h"
#include "PhbSrv.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "ps_public_enum.h"
#include "sim_common_enums.h"
#include "MMI_features.h"
#include "string.h"
#include "custom_phb_config.h"
#include "Unicodexdcl.h"
#include "mmi_msg_struct.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "PhbSrvIprot.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "mmi_rp_srv_phb_def.h"

typedef struct
{
    void* cb;
    void* user_data;
} srv_phb_op_cntx_struct;

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
 *  srv_phb_oplib_copy_contact_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  SQLITE error code
 *****************************************************************************/
static void srv_phb_oplib_copy_contact_data(U32 field_mask, srv_phb_contact_data_struct* dest_field_data, srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined (__MMI_PHB_OPTIONAL_FIELD__) || defined (__MMI_PHB_CALLER_GROUP__)
    S32 i = 0;
#endif
    void* data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_DEFAULT_NUMBER__
    if (field_mask & SRV_PHB_ENTRY_FIELD_DEF)
    {
        dest_field_data->default_number = 0xfe;
    }
#endif /* __MMI_PHB_DEFAULT_NUMBER__ */

    if (field_mask & SRV_PHB_ENTRY_FIELD_NAME)
    {
        if (dest_field_data->name)
        {
            if (dest_field_data->l_name)
            {
                data = (void*)srv_phb_contact_get_fname(contact);
            }
            else
            {
                data = (void*)srv_phb_contact_get_name(contact);
            }
            if (data)
            {
                mmi_wcsncpy(dest_field_data->name, (WCHAR*)data, MMI_PHB_NAME_LENGTH);
            }
            else
            {
                dest_field_data->name[0] = 0;
            }
        }
    #ifdef __MMI_PHB_LAST_NAME_FIELD__
        if (dest_field_data->l_name)
        {
            data = (void*)srv_phb_contact_get_lname(contact);
            if (data)
            {
                mmi_wcsncpy(dest_field_data->l_name, (WCHAR*)data, MMI_PHB_NAME_FIELD_LENGTH);
            }
            else
            {
                dest_field_data->l_name[0] = 0;
            }
        }
    #endif /* __MMI_PHB_LAST_NAME_FIELD__ */    
    }
#ifdef __MMI_PHB_USIM_SUPPORT__
    if (field_mask & SRV_PHB_ENTRY_FIELD_NICK)
    {
        if (dest_field_data->n_name)
        {
            data = (void*)srv_phb_contact_get_nick(contact);
            if (data)
            {
                mmi_wcsncpy(dest_field_data->n_name, (WCHAR*)data, MMI_PHB_NAME_FIELD_LENGTH);
            }
            else
            {
                dest_field_data->n_name[0] = 0;
            }
        }
    }
#endif /* __MMI_PHB_USIM_SUPPORT__ */
    data = (void*)srv_phb_contact_get_number_by_save_index(contact, 0);
    if (data)
    {
    #ifdef __MMI_PHB_DEFAULT_NUMBER__
        if (field_mask & SRV_PHB_ENTRY_FIELD_DEF && ((srv_phb_number_struct*)data)->is_default)
        {
            dest_field_data->default_number = SRV_PHB_ENTRY_FIELD_NUMBER;
        }
    #endif /* __MMI_PHB_DEFAULT_NUMBER__ */
        if (field_mask & SRV_PHB_ENTRY_FIELD_NUMBER && dest_field_data->number)
        {
            mmi_wcsncpy(dest_field_data->number, ((srv_phb_number_struct*)data)->number, MMI_PHB_NUMBER_PLUS_LENGTH);
        }
    }
    else if (field_mask & SRV_PHB_ENTRY_FIELD_NUMBER && dest_field_data->number)
    {
        dest_field_data->number[0] = 0;
    }

#ifdef __MMI_PHB_OPTIONAL_FIELD__
    {
        U8 opt_order[MMI_PHB_OPT_NUM_COUNT * 2];
        if (dest_field_data->opt_order)
        {
            memset(opt_order, 0, sizeof(opt_order));
        }

        for (i = 0; i < MMI_PHB_OPT_NUM_COUNT; i++)
        {
            data = srv_phb_contact_get_number_by_save_index(contact, i + 1);
            if (data)
            {
            #ifdef __MMI_PHB_DEFAULT_NUMBER__
                if (field_mask & SRV_PHB_ENTRY_FIELD_DEF && ((srv_phb_number_struct*)data)->is_default)
                {
                    dest_field_data->default_number = SRV_PHB_ENTRY_FIELD_OPT_NUM_1 << i;
                }
            #endif /* __MMI_PHB_DEFAULT_NUMBER__ */
                if ((field_mask & (SRV_PHB_ENTRY_FIELD_OPT_NUM_1 << i)) && dest_field_data->opt_num[i])
                {
                    mmi_wcsncpy(
                        dest_field_data->opt_num[i]->number,
                        ((srv_phb_number_struct*)data)->number,
                        MMI_PHB_NUMBER_PLUS_LENGTH);
                    
                    dest_field_data->opt_num[i]->type = (mmi_phb_num_type_enum)(((srv_phb_number_struct*)data)->type);
                    if (dest_field_data->opt_order)
                    {
                        opt_order[((srv_phb_number_struct*)data)->index - 1] = (SRV_PHB_ENTRY_FIELD_OPT_NUM_1 << i);
                    }
                }
                continue;
            }
            else if ((field_mask & (SRV_PHB_ENTRY_FIELD_OPT_NUM_1 << i)) && dest_field_data->opt_num[i])
            {
                dest_field_data->opt_num[i]->number[0] = 0;
                if (dest_field_data->opt_order)
                {
                    opt_order[MMI_PHB_OPT_NUM_COUNT + i] = (SRV_PHB_ENTRY_FIELD_OPT_NUM_1 << i);
                }
            }
        }
        if (field_mask & SRV_PHB_ENTRY_FIELD_OPTIONAL_NUM && dest_field_data->opt_order)
        {
            U8 j = 0;
            for (i = 0; j < MMI_PHB_OPT_NUM_COUNT && (i < (MMI_PHB_OPT_NUM_COUNT * 2)); i++)
            {
                if (opt_order[i])
                {
                    dest_field_data->opt_order[j++] = opt_order[i];
                }
            }
        }
    }
    if (field_mask & SRV_PHB_ENTRY_FIELD_COMPANY && dest_field_data->company_name)
    {
        data = srv_phb_contact_get_company(contact);
        if (data)
        {
            mmi_wcsncpy(
                dest_field_data->company_name,
                (WCHAR*)data,
                MMI_PHB_COMPANY_LENGTH);
        }
        else
        {
            dest_field_data->company_name[0] = 0;
        }
    }

    if (field_mask & SRV_PHB_ENTRY_FIELD_EMAIL1 && dest_field_data->email_address)
    {
        data = srv_phb_contact_get_email_by_save_index(contact, 0);
        if (data)
        {
            mmi_wcsncpy(
                dest_field_data->email_address,
                ((srv_phb_email_struct*)data)->email,
                MMI_PHB_EMAIL_LENGTH);
        }
        else
        {
            dest_field_data->email_address[0] = 0;
        }
    }

#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
    if (field_mask & SRV_PHB_ENTRY_FIELD_EMAIL2 && dest_field_data->email_address2)
    {
        data = srv_phb_contact_get_email_by_save_index(contact, 1);
        if (data)
        {
            mmi_wcsncpy(
                dest_field_data->email_address2,
                ((srv_phb_email_struct*)data)->email,
                MMI_PHB_EMAIL_LENGTH);
        }
        else
        {
            dest_field_data->email_address2[0] = 0;
        }
    }
#endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */
#endif /* __MMI_PHB_OPTIONAL_FIELD__ */

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    if (field_mask & SRV_PHB_ENTRY_FIELD_BDAY)
    {
        srv_phb_bday_struct* bday = srv_phb_contact_get_bday(contact);
        if (bday)
        {
            dest_field_data->b_year = bday->b_year;
            dest_field_data->b_month = bday->b_month;
            dest_field_data->b_day = bday->b_day;
        }
    }
#endif /* __MMI_PHB_BIRTHDAY_FIELD__ */

#if defined(__MMI_PHB_INFO_FIELD__)
    if (field_mask & SRV_PHB_ENTRY_FIELD_TITLE && dest_field_data->title)
    {
        data = srv_phb_contact_get_title(contact);
        if (data)
        {
            mmi_wcsncpy(
                dest_field_data->title,
                (WCHAR*)data,
                MMI_PHB_TITLE_LENGTH);
        }
        else
        {
            dest_field_data->title[0] = 0;
        }
    }
    if (field_mask & SRV_PHB_ENTRY_FIELD_URL && dest_field_data->url)
    {
        srv_phb_url_struct* url = srv_phb_contact_get_url_by_sub_id(contact, 0);
        if (url)
        {
            mmi_wcsncpy(
                dest_field_data->url,
                url->url,
                MMI_PHB_URL_LENGTH);
        }
        else
        {
            dest_field_data->url[0] = 0;
        }
    }

    if (field_mask & SRV_PHB_ENTRY_FIELD_NOTE && dest_field_data->note)
    {
        srv_phb_note_struct* note = srv_phb_contact_get_note_by_sub_id(contact, 0);
        if (note)
        {
            mmi_wcsncpy(
                dest_field_data->note,
                note->note,
                MMI_PHB_NOTE_LENGTH);
        }
        else
        {
            dest_field_data->note[0] = 0;
        }
    }

    if (field_mask & SRV_PHB_ENTRY_FIELD_ADDRESS)
    {
        srv_phb_address_struct* address = srv_phb_contact_get_address_by_sub_id(contact, 0);
        if (address)
        {
            if (dest_field_data->pobox)
            {
                mmi_wcsncpy(dest_field_data->pobox, address->address.pobox, MMI_PHB_ADDRESS_LENGTH);
            }
            if (dest_field_data->extension)
            {
                mmi_wcsncpy(dest_field_data->extension, address->address.extension, MMI_PHB_ADDRESS_LENGTH);
            }
            if (dest_field_data->street)
            {
                mmi_wcsncpy(dest_field_data->street, address->address.street, MMI_PHB_ADDRESS_LENGTH);
            }
            if (dest_field_data->city)
            {
                mmi_wcsncpy(dest_field_data->city, address->address.city, MMI_PHB_ADDRESS_LENGTH);
            }
            if (dest_field_data->state)
            {
                mmi_wcsncpy(dest_field_data->state, address->address.state, MMI_PHB_ADDRESS_LENGTH);
            }
            if (dest_field_data->postalcode)
            {
                mmi_wcsncpy(dest_field_data->postalcode, address->address.postalcode, MMI_PHB_ADDRESS_LENGTH);
            }
            if (dest_field_data->country)
            {
                mmi_wcsncpy(dest_field_data->country, address->address.country, MMI_PHB_ADDRESS_LENGTH);
            }
        }
        else
        {
            if (dest_field_data->pobox)
            {
                dest_field_data->pobox[0] = 0;
            }
            if (dest_field_data->extension)
            {
                dest_field_data->extension[0] = 0;
            }
            if (dest_field_data->street)
            {
                dest_field_data->street[0] = 0;
            }
            if (dest_field_data->city)
            {
                dest_field_data->city[0] = 0;
            }
            if (dest_field_data->state)
            {
                dest_field_data->state[0] = 0;
            }
            if (dest_field_data->postalcode)
            {
                dest_field_data->postalcode[0] = 0;
            }
            if (dest_field_data->country)
            {
                dest_field_data->country[0] = 0;
            }

        }
    }
#endif /* defined(__MMI_PHB_INFO_FIELD__) */
#ifdef __MMI_PHB_CALLER_GROUP__
    if (field_mask & SRV_PHB_ENTRY_FIELD_GROUP)
    {
        srv_phb_group_struct* group = srv_phb_contact_get_group(contact);
        dest_field_data->group_mask = 0;
        if (group)
        {
            for (i = 0; i < group->group_count; i++)
            {
                U8 group_id = group->group_id[i];
                #ifdef __MMI_PHB_USIM_SUPPORT__
                if (srv_phb_get_storage_by_group_id(group_id) > PHB_STORAGE_NVRAM)
                {
                    group_id -= MMI_PHB_GROUP_COUNT;
                    group_id = group_id % MMI_PHB_MAX_GAS_COUNT;
                }
                #endif
                dest_field_data->group_mask |= (1 << group_id);
            }
        }
    }
#endif /* __MMI_PHB_CALLER_GROUP__ */
    dest_field_data->res_type = 0;
    if (field_mask & SRV_PHB_ENTRY_FIELD_RING)
    {
        srv_phb_res_struct* ring = srv_phb_contact_get_ringtone(contact);
        if (ring)
        {
            dest_field_data->ringtone_id = ring->res_id;
            if (dest_field_data->ringtone_path)
            {
                mmi_wcsncpy(dest_field_data->ringtone_path, ring->res_path, SRV_FMGR_PATH_MAX_LEN);
            }
            if (ring->res_path[0])
            {
                dest_field_data->res_type |= SRV_PHB_RES_TYPE_RING_FILE;
            }
            else
            {
                dest_field_data->res_type |= SRV_PHB_RES_TYPE_RING_ID;
            }
        }
        else
        {
            dest_field_data->ringtone_id = 0;
            if (dest_field_data->ringtone_path)
            {
                dest_field_data->ringtone_path[0] = 0;
            }
        }
    }

    if (field_mask & SRV_PHB_ENTRY_FIELD_PIC)
    {
        srv_phb_res_struct* image = srv_phb_contact_get_image(contact);
        if (image)
        {
            dest_field_data->image_id = image->res_id;
            if (dest_field_data->image_path)
            {
                mmi_wcsncpy(dest_field_data->image_path, image->res_path, SRV_FMGR_PATH_MAX_LEN);
            }
            if (image->res_path[0])
            {
                dest_field_data->res_type |= SRV_PHB_RES_TYPE_IMAGE_FILE;
            }
            else
            {
                dest_field_data->res_type |= SRV_PHB_RES_TYPE_IMAGE_ID;
            }
        }
        else
        {
            dest_field_data->image_id = IMG_PHB_DEFAULT;
            dest_field_data->res_type |= SRV_PHB_RES_TYPE_IMAGE_ID;
            if (dest_field_data->image_path)
            {
                dest_field_data->image_path[0] = 0;
            }
        }
    }

#if defined(__MMI_PHB_CALLER_VIDEO__)
    if (field_mask & SRV_PHB_ENTRY_FIELD_VIDEO)
    {
        srv_phb_res_struct* video = srv_phb_contact_get_video(contact);
        if (video)
        {
            dest_field_data->video_id = video->res_id;
            if (dest_field_data->video_path)
            {
                mmi_wcsncpy(dest_field_data->video_path, video->res_path, SRV_FMGR_PATH_MAX_LEN);
            }
            if (video->res_path[0])
            {
                dest_field_data->res_type |= SRV_PHB_RES_TYPE_VIDEO_FILE;
            }
            else
            {
                dest_field_data->res_type |= SRV_PHB_RES_TYPE_VIDEO_ID;
            }
            if (video->flag)
            {
                dest_field_data->res_type |= SRV_PHB_RES_TYPE_VIDEO_SOUND_ON;
            }
        }
        else
        {
            dest_field_data->video_id = 0;
            if (dest_field_data->video_path)
            {
                dest_field_data->video_path[0] = 0;
            }
        }
    }
#endif /* __MMI_PHB_CALLER_VIDEO__ */

#if defined(__MMI_IMPS__)
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
#endif /* __MMI_IMPS__ */

#if defined(__MMI_VOIP__)
    if (field_mask & SRV_PHB_ENTRY_FIELD_VOIP && dest_field_data->voip)
    {
        data = srv_phb_contact_get_voip(contact);
        if (data)
        {
            mmi_wcsncpy(
                dest_field_data->voip,
                (WCHAR*)data,
                VOIP_URI_LEN - 1);
        }
        else
        {
            dest_field_data->voip[0] = 0;
        }
    }
#endif /* __MMI_VOIP__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_oplib_dup_contact_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  SQLITE error code
 *****************************************************************************/
static srv_phb_contact srv_phb_oplib_dup_contact_data(phb_storage_enum storage, U32 field_mask, srv_phb_contact_data_struct* src_field_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_default = MMI_FALSE;
#if defined (__MMI_PHB_OPTIONAL_FIELD__) || defined (__MMI_PHB_CALLER_GROUP__)
    S32 i = 0;
#endif
    srv_phb_contact contact = srv_phb_create_contact(NULL);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (field_mask & SRV_PHB_ENTRY_FIELD_NAME)
    {
        if (src_field_data->name && src_field_data->name[0])
        {
            srv_phb_contact_set_fname(contact, src_field_data->name);
        }
    #ifdef __MMI_PHB_LAST_NAME_FIELD__
        if (src_field_data->l_name && src_field_data->l_name[0])
        {
            srv_phb_contact_set_lname(contact, src_field_data->l_name);
        }
    #endif /* __MMI_PHB_LAST_NAME_FIELD__ */
    }
#ifdef __MMI_PHB_USIM_SUPPORT__
    if (field_mask & SRV_PHB_ENTRY_FIELD_NICK)
    {
        if (src_field_data->n_name && src_field_data->n_name[0])
        {
            srv_phb_contact_set_nick(contact, src_field_data->n_name);
        }
    }
#endif /* __MMI_PHB_USIM_SUPPORT__ */
    if (field_mask & SRV_PHB_ENTRY_FIELD_NUMBER)
    {
    #ifdef __MMI_PHB_DEFAULT_NUMBER__
        if (field_mask & SRV_PHB_ENTRY_FIELD_DEF &&
           ((src_field_data->default_number == SRV_PHB_ENTRY_FIELD_NUMBER) || (src_field_data->default_number == 0xFF)))
        {
            is_default = MMI_TRUE;
        }
        else
        {
            is_default = MMI_FALSE;
        }
    #endif /* __MMI_PHB_DEFAULT_NUMBER__ */
        srv_phb_contact_add_number_ex(contact, 0, 0, MMI_PHB_NUM_TYPE_MOBILE, src_field_data->number, NULL, is_default);
    }

#ifdef __MMI_PHB_OPTIONAL_FIELD__
    if (field_mask & SRV_PHB_ENTRY_FIELD_OPTIONAL_NUM)
    {
        U32 field;
        S32 index;
        for (i = 0; i < MMI_PHB_OPT_NUM_COUNT; i++)
        {
            if (src_field_data->opt_order)
            {
                field = src_field_data->opt_order[i];
                switch (field)
                    {
                        case SRV_PHB_ENTRY_FIELD_OPT_NUM_1:
                             index = 0;
                             break;
                        
                        case SRV_PHB_ENTRY_FIELD_OPT_NUM_2:
                             index = 1;
                             break;
                    
                        case SRV_PHB_ENTRY_FIELD_OPT_NUM_3:
                        default:
                             index = 2;
                        break;
                    }
            }
            else
            {
                index = i;
                field = (SRV_PHB_ENTRY_FIELD_OPT_NUM_1 << i);
            }
            if (field_mask & field)
            {
            #ifdef __MMI_PHB_DEFAULT_NUMBER__
                if (field_mask & SRV_PHB_ENTRY_FIELD_DEF &&
                    (src_field_data->default_number == field))
                {
                    is_default = MMI_TRUE;
                }
                else
                {
                    is_default = MMI_FALSE;
                }
            #endif /* __MMI_PHB_DEFAULT_NUMBER__ */
                srv_phb_contact_add_number_ex(
                                contact,
                                index + 1,
                                index + 1,
                                src_field_data->opt_num[index]->type,
                                src_field_data->opt_num[index]->number,
                                NULL,
                                is_default);
            }
        }
    }
    
    if (field_mask & SRV_PHB_ENTRY_FIELD_COMPANY && src_field_data->company_name && src_field_data->company_name[0])
    {
        srv_phb_contact_set_company(contact, src_field_data->company_name);
    }

    if (field_mask & SRV_PHB_ENTRY_FIELD_EMAIL1)
    {
        srv_phb_contact_add_email_ex(contact, 0, 0, 0, src_field_data->email_address, NULL);
    }

#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
    if (field_mask & SRV_PHB_ENTRY_FIELD_EMAIL2)
    {
        srv_phb_contact_add_email_ex(contact, 1, 1, 0, src_field_data->email_address2, NULL);
    }

#endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */
#endif /* __MMI_PHB_OPTIONAL_FIELD__ */
#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    if (field_mask & SRV_PHB_ENTRY_FIELD_BDAY && src_field_data->b_year)
    {
        srv_phb_bday_struct bday;
        bday.b_year = src_field_data->b_year;
        bday.b_month = src_field_data->b_month;
        bday.b_day = src_field_data->b_day;
        srv_phb_contact_set_bday(contact, &bday);
    }
#endif /* __MMI_PHB_BIRTHDAY_FIELD__ */
#if defined(__MMI_PHB_INFO_FIELD__)
    if (field_mask & SRV_PHB_ENTRY_FIELD_TITLE && src_field_data->title && src_field_data->title[0])
    {
        srv_phb_contact_set_title(contact, src_field_data->title);
    }
    if (field_mask & SRV_PHB_ENTRY_FIELD_URL && src_field_data->url && src_field_data->url[0])
    {
        srv_phb_contact_add_url_ex(contact, 0, 0, src_field_data->url);
    }

    if (field_mask & SRV_PHB_ENTRY_FIELD_NOTE && src_field_data->note && src_field_data->note[0])
    {
        srv_phb_contact_add_note_ex(contact, 0, 0, src_field_data->note);
    }

    if (field_mask & SRV_PHB_ENTRY_FIELD_ADDRESS)
    {
        mmi_phb_address_struct address;
        mmi_wcsncpy(address.pobox, src_field_data->pobox, MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy(address.extension, src_field_data->extension, MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy(address.street, src_field_data->street, MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy(address.city, src_field_data->city, MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy(address.state, src_field_data->state, MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy(address.postalcode, src_field_data->postalcode, MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy(address.country, src_field_data->country, MMI_PHB_ADDRESS_LENGTH);
        
        srv_phb_contact_add_address_ex(contact, 0, 0, &address);
    }
#endif /* defined(__MMI_PHB_INFO_FIELD__) */
#ifdef __MMI_PHB_CALLER_GROUP__
    if (field_mask & SRV_PHB_ENTRY_FIELD_GROUP && src_field_data->group_mask)
    {
        srv_phb_group_struct group;
        group.group_count = 0;
        #ifdef __MMI_PHB_USIM_SUPPORT__
        if (storage > PHB_STORAGE_NVRAM)
        {
            for (i = 0; i < MMI_PHB_MAX_GAS_COUNT; i ++)
            {
                if (src_field_data->group_mask & (1 << i))
                {
                    group.group_id[group.group_count++] = (i + MMI_PHB_GROUP_COUNT + MMI_PHB_MAX_GAS_COUNT * srv_phb_get_sim_id(storage));
                }
            }
        }
        else
        #endif
        {
            for (i = 0; i < MMI_PHB_GROUP_COUNT; i++)
            {
                if (src_field_data->group_mask & (1 << i))
                {
                    group.group_id[group.group_count++] = i;
                }
            }
        }
        srv_phb_contact_set_group(contact, &group);
    }
#endif /* __MMI_PHB_CALLER_GROUP__ */
    if (field_mask & SRV_PHB_ENTRY_FIELD_RING)
    {
        srv_phb_contact_set_ringtone_ex(contact, src_field_data->ringtone_id, src_field_data->ringtone_path);
    }

    if (field_mask & SRV_PHB_ENTRY_FIELD_PIC)
    {
        srv_phb_contact_set_image_ex(contact, src_field_data->image_id, src_field_data->image_path);
    }

#if defined(__MMI_PHB_CALLER_VIDEO__)
    if (field_mask & SRV_PHB_ENTRY_FIELD_VIDEO)
    {
        srv_phb_contact_set_video_ex(
            contact,
            src_field_data->video_id,
            src_field_data->video_path,
            (src_field_data->res_type & SRV_PHB_RES_TYPE_VIDEO_SOUND_ON) ? MMI_TRUE: MMI_FALSE);
    }
#endif /* __MMI_PHB_CALLER_VIDEO__ */

#if defined(__MMI_IMPS__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_IMPS__ */

#if defined(__MMI_VOIP__)
    if (field_mask & SRV_PHB_ENTRY_FIELD_VOIP && src_field_data->voip && src_field_data->voip[0])
    {
        srv_phb_contact_set_voip(contact, src_field_data->voip);
    }
#endif /* __MMI_VOIP__ */
    return contact;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_oplib_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_oplib_cb(srv_phb_async_op_cb_struct* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_cntx_struct* cntx = info->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->cb)
    {
        switch (info->type)
        {
            case SRV_PHB_OP_CB_TYPE_ADD:
            case SRV_PHB_OP_CB_TYPE_UPD:
            case SRV_PHB_OP_CB_TYPE_DEL:
            case SRV_PHB_OP_CB_TYPE_COPY:
            case SRV_PHB_OP_CB_TYPE_MOVE:
                ((srv_phb_op_callback_type)(cntx->cb))(
                        ((srv_phb_add_cb_struct*)info)->result,
                        ((srv_phb_add_cb_struct*)info)->id,
                        cntx->user_data);
                break;

            case SRV_PHB_OP_CB_TYPE_COPY_ALL:
            case SRV_PHB_OP_CB_TYPE_MOVE_ALL:
            case SRV_PHB_OP_CB_TYPE_DELETE_ALL:
                ((srv_phb_op_all_callback_type)(cntx->cb))(
                        ((srv_phb_copy_all_cb_struct*)info)->finish_count,
                        ((srv_phb_copy_all_cb_struct*)info)->total_count,
                        cntx->user_data);
                break;
                
            case SRV_PHB_OP_CB_TYPE_MULTI_COPY:
            case SRV_PHB_OP_CB_TYPE_MULTI_MOVE:
            case SRV_PHB_OP_CB_TYPE_MULTI_DELETE:
                ((srv_phb_op_several_callback_type)(cntx->cb))(
                        ((srv_phb_multi_copy_cb_struct*)info)->id_array,
                        ((srv_phb_multi_copy_cb_struct*)info)->finish_count,
                        ((srv_phb_multi_copy_cb_struct*)info)->total_count,
                        cntx->user_data);
                break;

            default:
                return;
        }
    }
    srv_phb_mem_free(cntx);
    srv_phb_free_handle(info->handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_oplib_check_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_phb_oplib_check_valid(srv_phb_contact_data_struct* field_data, U32 field_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (field_mask & SRV_PHB_ENTRY_FIELD_NAME)
    {
        if (field_data->name && (field_data->name[0] != 0))
        {
            return MMI_TRUE;
        }

#if defined(__MMI_PHB_LAST_NAME_FIELD__)
        if (field_data->l_name && (field_data->l_name[0] != 0))
        {
            return MMI_TRUE;
        }
#endif /* defined(__MMI_PHB_LAST_NAME_FIELD__) */
    }

    if (field_mask & SRV_PHB_ENTRY_FIELD_NUMBER)
    {
        if (field_data->number && (field_data->number[0] != 0))
        {
            return MMI_TRUE;
        }
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
static void srv_phb_oplib_op_fail(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_fail_struct* status = (srv_phb_op_fail_struct*)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status->cb(status->result, status->id, status->user_data);
    srv_phb_mem_free(status);
}


#define EXTERNAL_FUNCTION
/***************************************************************************** 
 * Global Function 
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  srv_phb_oplib_get_contact_info
 * DESCRIPTION
 *  get contact's info by store_index
 * PARAMETERS
 *  store_index        :   [IN]      contact's store_index
 *  contact_info       :   [OUT]     contact's info
 * RETURNS
 *  S32
 * RETURN VALUES
 *  SRV_PHB_NO_ERROR          :                    get contact info success
 *  Others                    :                    refer phb error result
 *****************************************************************************/
S32 srv_phb_oplib_get_contact_info(U16 store_index, srv_phb_contact_info_struct* contact_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_startup_is_phb_ready())
    {
        if (!srv_phb_datamgr_check_store_index(store_index, MMI_PHB_CONTACT_FIELD_ALL))
        {
            return SRV_PHB_NOT_FOUND;
        }
        else
        {
            srv_phb_field_filter filter = srv_phb_create_field_filter_ext(srv_phb_convert_field_filter(contact_info->field_mask));
            srv_phb_contact contact = srv_phb_read_contact(store_index, filter, NULL);
            srv_phb_oplib_copy_contact_data(contact_info->field_mask, &(contact_info->field_data), contact);
            srv_phb_free_field_filter(filter);
            srv_phb_free_contact(contact);
            return SRV_PHB_NO_ERROR;
        }
    }
    return SRV_PHB_NOT_READY;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_oplib_add_contact
 * DESCRIPTION
 *  add a phonebook contact
 * PARAMETERS
 *  storage            :   [IN]      storage to add, refer phb_storage_enum
 *  contact_info       :   [IN]      contact's info
 *  cb                 :   [IN]      call back function
 *  user_data          :   [IN]      user data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_oplib_add_contact(U8 storage, U16 record_index, srv_phb_contact_info_struct* info, srv_phb_op_callback_type cb, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_oplib_check_valid(&(info->field_data), info->field_mask))
    {
        srv_phb_op_cntx_struct* cntx = srv_phb_mem_malloc(sizeof(srv_phb_op_cntx_struct), SRV_PHB_MEMORY_TYPE_CTR);
        srv_phb_add_req_struct req;

        cntx->cb = (void*)cb;
        cntx->user_data = user_data;
        req.contact = srv_phb_oplib_dup_contact_data((phb_storage_enum)storage, info->field_mask, &(info->field_data));
        req.storage = (phb_storage_enum)storage;
        req.mode = SRV_PHB_UPDATE_MODE_IMPORT;
        req.record_index = record_index;
        req.cb = srv_phb_oplib_cb;
        req.user_data = cntx;
        srv_phb_add_contact(&req);
        srv_phb_free_contact(req.contact);
        return;
    }
    else
    {
        srv_phb_op_fail_struct* status;
        status = srv_phb_mem_malloc(sizeof(srv_phb_op_fail_struct), SRV_PHB_MEMORY_TYPE_CTR);
        status->result = SRV_PHB_NAME_NUM_EMPTY;
        status->id = SRV_PHB_INVALID_INDEX;
        status->cb = cb;
        status->user_data = user_data;
        srv_phb_async_event_interface(srv_phb_oplib_op_fail, status);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_oplib_update_contact
 * DESCRIPTION
 *  edit a phonebook contact
 * PARAMETERS
 *  store_index        :   [IN]      contact's store_index
 *  contact_info       :   [IN]      contact's info
 *  cb                 :   [IN]      call back function
 *  user_data          :   [IN]      user data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_oplib_update_contact(U16 index, srv_phb_contact_info_struct* info, srv_phb_op_callback_type cb, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_cntx_struct* cntx = srv_phb_mem_malloc(sizeof(srv_phb_op_cntx_struct), SRV_PHB_MEMORY_TYPE_CTR);
    srv_phb_update_req_struct req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->cb = (void*)cb;
    cntx->user_data = user_data;
    req.contact = srv_phb_oplib_dup_contact_data((phb_storage_enum)srv_phb_get_storage(index), info->field_mask, &(info->field_data));
    req.id = index;
    req.mode = SRV_PHB_UPDATE_MODE_IMPORT;
    req.update_field = srv_phb_convert_field_filter(info->field_mask);
    req.cb = srv_phb_oplib_cb;
    req.user_data = cntx;
    srv_phb_update_contact(&req);
    srv_phb_free_contact(req.contact);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_oplib_delete_contact
 * DESCRIPTION
 *  delete a phonebook contact
 * PARAMETERS
 *  store_index        :   [IN]      contact's store_index
 *  cb                 :   [IN]      call back function
 *  user_data          :   [IN]      user data
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_oplib_delete_contact(U16 index, srv_phb_op_callback_type cb, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_cntx_struct* cntx = srv_phb_mem_malloc(sizeof(srv_phb_op_cntx_struct), SRV_PHB_MEMORY_TYPE_CTR);
    srv_phb_delete_req_struct req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->cb = (void*)cb;
    cntx->user_data = user_data;
    req.id = index;
    req.cb = srv_phb_oplib_cb;
    req.user_data = cntx;
    srv_phb_delete_contact(&req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_oplib_copy_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_oplib_copy_contact(U8 dst_storage, U16 src_store_index, srv_phb_op_callback_type cb, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_cntx_struct* cntx = srv_phb_mem_malloc(sizeof(srv_phb_op_cntx_struct), SRV_PHB_MEMORY_TYPE_CTR);
    srv_phb_copy_req_struct req;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->cb = (void*)cb;
    cntx->user_data = user_data;
    req.id = src_store_index;
    req.dest_storage = (phb_storage_enum)dst_storage;
    req.cb = srv_phb_oplib_cb;
    req.user_data = cntx;
    srv_phb_copy_contact(&req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_oplib_build_contact_list
 * DESCRIPTION
 *  build contact store_index array by filter
 * PARAMETERS
 *  filter                   : [IN]        build list filter
 *  entry_array              : [OUT]       output store_index array
 * RETURNS
 *  S32
 * RETURN VALUES
 *  >=0             :          matched contact's count
 *  <0              :          refer phb error result
 *****************************************************************************/
void srv_phb_oplib_move_contact(U8 dst_storage, U16 store_index, srv_phb_op_callback_type cb, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_cntx_struct* cntx = srv_phb_mem_malloc(sizeof(srv_phb_op_cntx_struct), SRV_PHB_MEMORY_TYPE_CTR);
    srv_phb_move_req_struct req;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->cb = (void*)cb;
    cntx->user_data = user_data;
    req.id = store_index;
    req.dest_storage = (phb_storage_enum)dst_storage;
    req.cb = srv_phb_oplib_cb;
    req.user_data = cntx;
    srv_phb_move_contact(&req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_oplib_cancel_multi_op
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_oplib_cancel_multi_op(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_stop_op();
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_oplib_copy_all_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_oplib_copy_all_contact(U8 src_storage, U8 dst_storage, srv_phb_op_all_callback_type cb, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_cntx_struct* cntx = srv_phb_mem_malloc(sizeof(srv_phb_op_cntx_struct), SRV_PHB_MEMORY_TYPE_CTR);
    srv_phb_copy_all_req_struct req;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->cb = (void*)cb;
    cntx->user_data = user_data;
    req.src_storage = (phb_storage_enum)src_storage;
    req.dest_storage = (phb_storage_enum)dst_storage;
    req.cb = srv_phb_oplib_cb;
    req.user_data = cntx;
    srv_phb_copy_all_contact(&req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_oplib_delete_all_contact
 * DESCRIPTION
 *  delete all contacst of a storage
 * PARAMETERS
 *  storage             :   [IN]    storage
 *  cb                  :   [IN]    call back function
 *  user_data           :   [IN]    user data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_oplib_delete_all_contact(U8 storage, srv_phb_op_all_callback_type cb, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_cntx_struct* cntx = srv_phb_mem_malloc(sizeof(srv_phb_op_cntx_struct), SRV_PHB_MEMORY_TYPE_CTR);
    srv_phb_delete_all_req_struct req;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->cb = (void*)cb;
    cntx->user_data = user_data;
    req.storage = (phb_storage_enum)storage;
    req.cb = srv_phb_oplib_cb;
    req.user_data = cntx;
    srv_phb_delete_all_contact(&req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_oplib_move_all_contact
 * DESCRIPTION
 *  move all contacst of a storage
 * PARAMETERS
 *  src_storage         :   [IN]    source storage
 *  dst_storage         :   [IN]    dest storage
 *  cb                  :   [IN]    call back function
 *  user_data           :   [IN]    user data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_oplib_move_all_contact(U8 src_storage, U8 dst_storage, srv_phb_op_all_callback_type cb, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_cntx_struct* cntx = srv_phb_mem_malloc(sizeof(srv_phb_op_cntx_struct), SRV_PHB_MEMORY_TYPE_CTR);
    srv_phb_move_all_req_struct req;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->cb = (void*)cb;
    cntx->user_data = user_data;
    req.src_storage = (phb_storage_enum)src_storage;
    req.dest_storage = (phb_storage_enum)dst_storage;
    req.cb = srv_phb_oplib_cb;
    req.user_data = cntx;
    srv_phb_move_all_contact(&req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_oplib_copy_several_contact
 * DESCRIPTION
 *  copy several contacts to a storage
 * PARAMETERS
 *  entry_array         :   [IN]    source store_index array
 *  entry_count         :   [IN]    source store_index count
 *  dst_storage         :   [IN]    dest storage
 *  cb                  :   [IN]    call back function
 *  user_data           :   [IN]    user data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_oplib_copy_several_contact(U16* entry_array, U16 entry_count, U8 dst_storage, srv_phb_op_several_callback_type cb, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_cntx_struct* cntx = srv_phb_mem_malloc(sizeof(srv_phb_op_cntx_struct), SRV_PHB_MEMORY_TYPE_CTR);
    srv_phb_multi_copy_req_struct req;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->cb = (void*)cb;
    cntx->user_data = user_data;
    req.id_array = entry_array;
    req.contact_count = entry_count;
    req.dest_storage = (phb_storage_enum)dst_storage;
    req.cb = srv_phb_oplib_cb;
    req.user_data = cntx;
    srv_phb_multi_copy_contact(&req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_oplib_delete_several_contact
 * DESCRIPTION
 *  delete several contacts to a storage
 * PARAMETERS
 *  entry_array         :   [IN]    source store_index array
 *  entry_count         :   [IN]    source store_index count
 *  cb                  :   [IN]    call back function
 *  user_data           :   [IN]    user data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_oplib_delete_several_contact(U16* entry_array, U16 entry_count, srv_phb_op_several_callback_type cb, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_cntx_struct* cntx = srv_phb_mem_malloc(sizeof(srv_phb_op_cntx_struct), SRV_PHB_MEMORY_TYPE_CTR);
    srv_phb_multi_delete_req_struct req;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->cb = (void*)cb;
    cntx->user_data = user_data;
    req.id_array = entry_array;
    req.contact_count = entry_count;
    req.cb = srv_phb_oplib_cb;
    req.user_data = cntx;
    srv_phb_multi_delete_contact(&req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_oplib_move_several_contact
 * DESCRIPTION
 *  move several contacts to a storage
 * PARAMETERS
 *  entry_array         :   [IN]    source store_index array
 *  entry_count         :   [IN]    source store_index count
 *  dst_storage         :   [IN]    dest storage
 *  cb                  :   [IN]    call back function
 *  user_data           :   [IN]    user data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_oplib_move_several_contact(U16* entry_array, U16 entry_count, U8 dst_storage, srv_phb_op_several_callback_type cb,  void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_cntx_struct* cntx = srv_phb_mem_malloc(sizeof(srv_phb_op_cntx_struct), SRV_PHB_MEMORY_TYPE_CTR);
    srv_phb_multi_move_req_struct req;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->cb = (void*)cb;
    cntx->user_data = user_data;
    req.id_array = entry_array;
    req.contact_count = entry_count;
    req.dest_storage = (phb_storage_enum)dst_storage;
    req.cb = srv_phb_oplib_cb;
    req.user_data = cntx;
    srv_phb_multi_move_contact(&req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_oplib_build_contact_list
 * DESCRIPTION
 *  build contact store_index array by filter
 * PARAMETERS
 *  filter                   : [IN]        build list filter
 *  entry_array              : [OUT]       output store_index array
 * RETURNS
 *  S32
 * RETURN VALUES
 *  >=0             :          matched contact's count
 *  <0              :          refer phb error result
 *****************************************************************************/
S32 srv_phb_oplib_build_contact_list(srv_phb_filter_struct* filter, U16* entry_array, U32 max_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_startup_is_phb_ready())
    {
        if (filter)
        {
            filter->field_filter = srv_phb_convert_field_filter(filter->field_filter);
        }
        return srv_phb_sse_build_contact_list(filter, entry_array, max_count);
    }
    return SRV_PHB_NOT_READY;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_oplib_build_contact_list
 * DESCRIPTION
 *  build contact store_index array by filter
 * PARAMETERS
 *  filter                   : [IN]        build list filter
 *  entry_array              : [OUT]       output store_index array
 * RETURNS
 *  S32
 * RETURN VALUES
 *  >=0             :          matched contact's count
 *  <0              :          refer phb error result
 *****************************************************************************/
S32 srv_phb_oplib_build_alpha_jump_table(U16* entry_array, U16 entry_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_startup_is_phb_ready())
    {
        if (entry_count > 0)
        {
            srv_phb_sse_build_alpha_jump_table(entry_array, entry_count);
        }
        return SRV_PHB_NO_ERROR;
    }
    return SRV_PHB_NOT_READY;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_oplib_build_contact_list
 * DESCRIPTION
 *  build contact store_index array by filter
 * PARAMETERS
 *  filter                   : [IN]        build list filter
 *  entry_array              : [OUT]       output store_index array
 * RETURNS
 *  S32
 * RETURN VALUES
 *  >=0             :          matched contact's count
 *  <0              :          refer phb error result
 *****************************************************************************/
U16 srv_phb_oplib_get_alpha_index(U16 input_char)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_phb_sse_get_alpha_index(input_char);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_oplib_search
 * DESCRIPTION
 *  search a contact by name or number
 * PARAMETERS
 *  pattern_ucs2        : [IN]     search patern
 *  search_type         : [IN]     search type, refer srv_phb_search_type_enum
 * RETURNS
 *  S32
 * RETURN VALUES
 *  >=0             :          matched contact's store_index
 *  <0              :          refer phb error result
 *****************************************************************************/
S32 srv_phb_oplib_search(U16* pattern_ucs2, srv_phb_search_type_enum search_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_startup_is_phb_ready())
    {
        if (search_type == SRV_PHB_SEARCH_TYPE_NAME)
        {
            return srv_phb_sse_search_name(pattern_ucs2);
        }
        else
        {
            return srv_phb_sse_search_num(pattern_ucs2, NULL);
        }
    }
    return SRV_PHB_NOT_READY;
}


#endif /* PHBOPLIBSRV_C */ 

