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
 * MmsPcrdSrv.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements .......... Unified Composer.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#ifndef _MMS_POSTCARD_SRV_C
#define _MMS_POSTCARD_SRV_C

#ifdef __MMI_MMS_POSTCARD__
#include "PhoneBookGprot.h"
//#include "Conversions.h"
#include "UcSrvGprot.h"
#include "UcSrvIprot.h"
#include "UcSrv.h"
//suggested add
    #include "MMI_features.h"
    #include "MMIDataType.h"
    #include "Unicodexdcl.h"
    #include "string.h"
   // #include "kal_general_types.h"
    #include "mmi_frm_mem_gprot.h"
   // #include "kal_public_api.h"
    #include "custom_phb_config.h"
    #include "PhbSrvGprot.h"
   // #include "MMI_common_app_trc.h"
    #include "DebugInitDef_Int.h"
    #include "kal_trace.h"
   // #include "mmi_common_app_trc.h"


/*****************************************************************************
 * FUNCTION
 *  srv_postcard_get_recipient_pointer_by_index
 * DESCRIPTION
 *  Get the recipient pointer by index
 * PARAMETERS
 *  instance        [IN]        
 *  index           [IN]        
 *  U8(?)           [IN]        
 * RETURNS
 *  srv_postcard_recipient_struct*
 *****************************************************************************/
srv_postcard_recipient_struct *srv_postcard_get_recipient_pointer_by_index(U32 instance, U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    srv_postcard_recipient_struct *index_recipient = g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_head;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < index; i++)
    {
        index_recipient = index_recipient->next;
    }

    return index_recipient;
}


/*****************************************************************************
 * FUNCTION
 *  srv_postcard_delete_address_editor_handler
 * DESCRIPTION
 *  Callback function if address editor screen is deleted
 * PARAMETERS
 *  instance        [IN]        
 *  p               [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_postcard_delete_address_editor_handler(U32 instance, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_postcard_recipient_struct *new_recipient;
    srv_postcard_recipient_struct *index_recipient;
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_editor != NULL)
    {
        if (mmi_ucs2strlen((S8*) g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_editor->postcard_name) !=
            0 &&
            mmi_ucs2strlen((S8*) g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_editor->
                           postcard_street) != 0 &&
            mmi_ucs2strlen((S8*) g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_editor->postcard_city) !=
            0)
        {
            /* save it */
            new_recipient =
                (srv_postcard_recipient_struct*) g_srv_uc_p[instance]->alloc(sizeof(srv_postcard_recipient_struct), g_srv_uc_p[instance]->user_data);
            memset(new_recipient, 0, sizeof(srv_postcard_recipient_struct));

            mmi_ucs2cpy(
                (S8*) new_recipient->address.postcard_name,
                (S8*) g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_editor->postcard_name);
            mmi_ucs2cpy(
                (S8*) new_recipient->address.postcard_additional,
                (S8*) g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_editor->postcard_additional);
            mmi_ucs2cpy(
                (S8*) new_recipient->address.postcard_street,
                (S8*) g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_editor->postcard_street);
            mmi_ucs2cpy(
                (S8*) new_recipient->address.postcard_city,
                (S8*) g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_editor->postcard_city);
            mmi_ucs2cpy(
                (S8*) new_recipient->address.postcard_postalcode,
                (S8*) g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_editor->postcard_postalcode);
            mmi_ucs2cpy(
                (S8*) new_recipient->address.postcard_state,
                (S8*) g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_editor->postcard_state);
            mmi_ucs2cpy(
                (S8*) new_recipient->address.postcard_country,
                (S8*) g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_editor->postcard_country);

            new_recipient->address.phonebook_index =
                g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_editor->phonebook_index;

        #ifdef __MMI_PHB_INFO_FIELD__
            if (new_recipient->address.phonebook_index != 0xFF)
            {
                /* compare with the original phonebook data if this entry is modified */
                new_recipient->update = srv_postcard_check_if_import_data_changed(new_recipient->address);
            }
            else
        #endif /* __MMI_PHB_INFO_FIELD__ */ 
            {
                new_recipient->update = MMI_TRUE;
            }

            /* operations: init, add, or edit */
            switch (g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_operation)
            {
                case SRV_POSTCARD_ADDRESS_INIT:
                    g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_head = new_recipient;
                    g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_total++;
                    break;

                case SRV_POSTCARD_ADDRESS_ADD:
                    index = g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_index - 1;
                    index_recipient = srv_postcard_get_recipient_pointer_by_index(instance, index);
                    index_recipient->next = new_recipient;
                    new_recipient->previous = index_recipient;
                    g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_total++;
                    break;

                case SRV_POSTCARD_ADDRESS_EDIT:
                    index = g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_index;
                    index_recipient = srv_postcard_get_recipient_pointer_by_index(instance, index);
                    memcpy(&index_recipient->address, &new_recipient->address, sizeof(srv_postcard_address_struct));
                    g_srv_uc_p[instance]->free(new_recipient, g_srv_uc_p[instance]->user_data);
                    break;
            }
        }

        OslMfree(g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_editor);
        g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_editor = NULL;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_postcard_set_recipient_index
 * DESCRIPTION
 *  Highlight handler to keep the selected index of recipient
 * PARAMETERS
 *  instance        [IN]        
 *  index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_postcard_set_recipient_index(U32 instance, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_index = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  srv_postcard_is_recipient_forward
 * DESCRIPTION
 *  Check whether the recipient has been forward from phonebook
 * PARAMETERS
 *  instance        [IN]        
 *  index(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_postcard_is_recipient_forward(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_total
        && g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.phonebook_forward)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

#ifdef __MMI_PHB_INFO_FIELD__


/*****************************************************************************
 * FUNCTION
 *  srv_postcard_check_if_phonebook_data_with_star
 * DESCRIPTION
 *  Check function of import address from phonebook
 * PARAMETERS
 *  store_index     [IN]        
 *  phb_data        [?]         
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_postcard_check_if_phonebook_data_with_star(U16 store_index, mmi_phb_address_struct *phb_data_address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 name[MMI_PHB_NAME_LENGTH + 1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_get_name(store_index, name, MMI_PHB_NAME_LENGTH);
    
    if (mmi_ucs2str((S8*) name, (S8*) SRV_POSTCARD_FORBIDDEN_CHAR) != NULL ||
        mmi_ucs2str((S8*) phb_data_address->extension, (S8*) SRV_POSTCARD_FORBIDDEN_CHAR) != NULL ||
        mmi_ucs2str((S8*) phb_data_address->street, (S8*) SRV_POSTCARD_FORBIDDEN_CHAR) != NULL ||
        mmi_ucs2str((S8*) phb_data_address->city, (S8*) SRV_POSTCARD_FORBIDDEN_CHAR) != NULL ||
        mmi_ucs2str((S8*) phb_data_address->postalcode, (S8*) SRV_POSTCARD_FORBIDDEN_CHAR) != NULL ||
        mmi_ucs2str((S8*) phb_data_address->state, (S8*) SRV_POSTCARD_FORBIDDEN_CHAR) != NULL ||
        mmi_ucs2str((S8*) phb_data_address->country, (S8*) SRV_POSTCARD_FORBIDDEN_CHAR) != NULL)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_postcard_check_if_import_data_changed
 * DESCRIPTION
 *  Check function of import address from phonebook
 * PARAMETERS
 *  address     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_postcard_check_if_import_data_changed(srv_postcard_address_struct address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_address_struct phb_info_field_address;
    U16 name[MMI_PHB_NAME_LENGTH + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_check_entry_exist(address.phonebook_index))
    {
        srv_phb_get_address(address.phonebook_index, 
                            NULL,
                            phb_info_field_address.extension,
                            phb_info_field_address.street,
                            phb_info_field_address.city,
                            phb_info_field_address.state,
                            phb_info_field_address.postalcode,
                            phb_info_field_address.country);
    }        
    else
    {
        memset(&phb_info_field_address, 0, sizeof(mmi_phb_address_struct));
    }
    srv_phb_get_name(address.phonebook_index, name, MMI_PHB_NAME_LENGTH);

    if (mmi_ucs2cmp((S8*) address.postcard_name, (S8*)name) == 0 &&
        mmi_ucs2cmp((S8*) address.postcard_additional, (S8*) phb_info_field_address.extension) == 0 &&
        mmi_ucs2cmp((S8*) address.postcard_street, (S8*) phb_info_field_address.street) == 0 &&
        mmi_ucs2cmp((S8*) address.postcard_city, (S8*) phb_info_field_address.city) == 0 &&
        mmi_ucs2cmp((S8*) address.postcard_postalcode, (S8*) phb_info_field_address.postalcode) == 0 &&
        mmi_ucs2cmp((S8*) address.postcard_state, (S8*) phb_info_field_address.state) == 0 &&
        mmi_ucs2cmp((S8*) address.postcard_country, (S8*) phb_info_field_address.country) == 0)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}
#endif /* __MMI_PHB_INFO_FIELD__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_postcard_clear_all_context
 * DESCRIPTION
 *  Reset function of postcard context
 *  1. delete all
 *  2. send postcard into outbox and finish the export process
 *  3. save postcard to draft
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_postcard_clear_all_context(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_postcard_recipient_struct *last_recipient;
    srv_postcard_recipient_struct *temp_recipient;
    U8 index = g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_total - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_total == 0)
    {
        return;
    }

    last_recipient = srv_postcard_get_recipient_pointer_by_index(instance, index);

    /* delete one by one from the last recipient */
    while (last_recipient != NULL)
    {
        temp_recipient = last_recipient->previous;
        g_srv_uc_p[instance]->free(last_recipient, g_srv_uc_p[instance]->user_data);
        last_recipient = temp_recipient;
    }

    memset(&g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info, 0, sizeof(srv_postcard_context_struct));
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_postcard_get_recipient_name_by_index
 * DESCRIPTION
 *  Get the recipient name by index
 * PARAMETERS
 *  instance        [IN]        
 *  index           [IN]        
 * RETURNS
 *  U8*
 *****************************************************************************/
U8 *srv_postcard_get_recipient_name_by_index(U32 instance, U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_postcard_recipient_struct *index_recipient;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index_recipient = srv_postcard_get_recipient_pointer_by_index(instance, index);
    return index_recipient->address.postcard_name;
}


/*****************************************************************************
 * FUNCTION
 *  srv_postcard_get_recipient_additional_by_index
 * DESCRIPTION
 *  Get the recipient additional information by index
 * PARAMETERS
 *  instance        [IN]        
 *  index           [IN]        
 * RETURNS
 *  U8*
 *****************************************************************************/
U8 *srv_postcard_get_recipient_additional_by_index(U32 instance, U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_postcard_recipient_struct *index_recipient;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index_recipient = srv_postcard_get_recipient_pointer_by_index(instance, index);
    return index_recipient->address.postcard_additional;
}


/*****************************************************************************
 * FUNCTION
 *  srv_postcard_get_recipient_street_by_index
 * DESCRIPTION
 *  Get the recipient street by index
 * PARAMETERS
 *  instance        [IN]        
 *  index           [IN]        
 * RETURNS
 *  U8*
 *****************************************************************************/
U8 *srv_postcard_get_recipient_street_by_index(U32 instance, U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_postcard_recipient_struct *index_recipient;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index_recipient = srv_postcard_get_recipient_pointer_by_index(instance, index);
    return index_recipient->address.postcard_street;
}


/*****************************************************************************
 * FUNCTION
 *  srv_postcard_get_recipient_city_by_index
 * DESCRIPTION
 *  Get the recipient city by index
 * PARAMETERS
 *  instance        [IN]        
 *  index           [IN]        
 * RETURNS
 *  U8*
 *****************************************************************************/
U8 *srv_postcard_get_recipient_city_by_index(U32 instance, U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_postcard_recipient_struct *index_recipient;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index_recipient = srv_postcard_get_recipient_pointer_by_index(instance, index);
    return index_recipient->address.postcard_city;
}


/*****************************************************************************
 * FUNCTION
 *  srv_postcard_get_recipient_postalcode_by_index
 * DESCRIPTION
 *  Get the recipient postalcode by index
 * PARAMETERS
 *  instance        [IN]        
 *  index           [IN]        
 * RETURNS
 *  U8*
 *****************************************************************************/
U8 *srv_postcard_get_recipient_postalcode_by_index(U32 instance, U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_postcard_recipient_struct *index_recipient;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index_recipient = srv_postcard_get_recipient_pointer_by_index(instance, index);
    return index_recipient->address.postcard_postalcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_postcard_get_recipient_state_by_index
 * DESCRIPTION
 *  Get the recipient state by index
 * PARAMETERS
 *  instance        [IN]        
 *  index           [IN]        
 * RETURNS
 *  U8*
 *****************************************************************************/
U8 *srv_postcard_get_recipient_state_by_index(U32 instance, U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_postcard_recipient_struct *index_recipient;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index_recipient = srv_postcard_get_recipient_pointer_by_index(instance, index);
    return index_recipient->address.postcard_state;
}


/*****************************************************************************
 * FUNCTION
 *  srv_postcard_get_recipient_country_by_index
 * DESCRIPTION
 *  Get the recipient country by index
 * PARAMETERS
 *  instance        [IN]        
 *  index           [IN]        
 * RETURNS
 *  U8*
 *****************************************************************************/
U8 *srv_postcard_get_recipient_country_by_index(U32 instance, U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_postcard_recipient_struct *index_recipient;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index_recipient = srv_postcard_get_recipient_pointer_by_index(instance, index);
    return index_recipient->address.postcard_country;
}


/*****************************************************************************
 * FUNCTION
 *  srv_postcard_get_total_recipient_count
 * DESCRIPTION
 *  Get the count of total recipients
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_postcard_get_total_recipient_count(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_total;
}


/*****************************************************************************
 * FUNCTION
 *  srv_postcard_count_recipients
 * DESCRIPTION
 *  Set the count of total recipients
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_postcard_count_recipients(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_postcard_recipient_struct *index_recipient;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index_recipient = g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_head;
    g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_total = 0;

    while (index_recipient != NULL)
    {
        g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_total++;
        index_recipient = index_recipient->next;
    }
    return MMI_TRUE;
}

#ifdef __MMI_PHB_INFO_FIELD__


/*****************************************************************************
 * FUNCTION
 *  srv_postcard_copy_phb_forward_data_to_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_postcard_copy_phb_forward_data_to_editor(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_POSTCARD_COPY_PHB_FORWARD_DATA_TO_EDITOR);
    srv_phb_remove_invalid_name((U16*) g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.phonebook_forward->postcard_name);
    mmi_ucs2cpy(
        (S8*) g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_editor->postcard_name,
        (S8*) g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.phonebook_forward->postcard_name);
    mmi_ucs2cpy(
        (S8*) g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_editor->postcard_additional,
        (S8*) g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.phonebook_forward->postcard_additional);
    mmi_ucs2cpy(
        (S8*) g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_editor->postcard_street,
        (S8*) g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.phonebook_forward->postcard_street);
    mmi_ucs2cpy(
        (S8*) g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_editor->postcard_city,
        (S8*) g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.phonebook_forward->postcard_city);
    mmi_ucs2cpy(
        (S8*) g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_editor->postcard_postalcode,
        (S8*) g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.phonebook_forward->postcard_postalcode);
    mmi_ucs2cpy(
        (S8*) g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_editor->postcard_state,
        (S8*) g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.phonebook_forward->postcard_state);
    mmi_ucs2cpy(
        (S8*) g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_editor->postcard_country,
        (S8*) g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.phonebook_forward->postcard_country);
    return MMI_TRUE;
}
#endif /* __MMI_PHB_INFO_FIELD__ */ 

#endif /* __MMI_MMS_POSTCARD__ */ 
#endif /* _MMS_POSTCARD_SRV_C */ 
