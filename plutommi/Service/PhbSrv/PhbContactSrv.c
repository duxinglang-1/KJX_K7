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
 *  PhbContactSrv.c
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef PHBCONTACTSRV_C
#define PHBCONTACTSRV_C


/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_include.h"
#include "PhbContactSrv.h"
#include "PhbSrvGprot.h"
#include "mmi_rp_srv_phb_def.h"
#include "MMI_common_app_trc.h"
/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
/* Define your local variable here */


/* Declare your local function here */




/***************************************************************************** 
 * Local Function
 *****************************************************************************/


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_reset_link_field
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_contact_reset_link_field(srv_phb_link_struct* link)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (link->alloc_head)
    {
        link->alloc_tail->next = link->head;
    }
    else
    {
        link->alloc_head = link->head;
    }
    if (link->tail)
    {
        link->alloc_tail = link->tail;
    }
    link->count = 0;
    link->head = NULL;
    link->tail = NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_init_name
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_contact_init_name(srv_phb_contact_name_struct* name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    name->fname[0] = 0;
    name->lname[0] = 0;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_init_res
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_contact_init_res(srv_phb_res_struct* res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res->flag = MMI_FALSE;
    res->res_id = 0;
    res->res_path[0] = 0;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_init_group
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_contact_init_group(srv_phb_group_struct* group)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group->group_count = 0;
    /* memset(group->group_id, MMI_PHB_INVALID_GROUP_ID, MMI_PHB_GROUP_COUNT); */
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_init_number
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_contact_init_number(srv_phb_number_struct* number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    number->sub_id = MMI_PHB_SUB_ID_NEW;
    number->type = MMI_PHB_NUM_TYPE_MOBILE;
    number->number[0] = 0;
    number->label[0] = 0;
    number->is_default = MMI_FALSE;
    number->last_used_sim = 0;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_init_number
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_contact_set_number(
                                srv_phb_number_struct* dest_number,
                                mmi_phb_sub_id id,
                                U8 save_index,
                                U8 type,
                                const WCHAR* number,
                                const WCHAR* label,
                                MMI_BOOL is_default)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_number->sub_id = id;
    dest_number->index = save_index;
    dest_number->type = type;
    dest_number->last_used_sim = 0;
    if (number)
    {
        mmi_wcsncpy((WCHAR*)(dest_number->number), number, MMI_PHB_NUMBER_PLUS_LENGTH);
    }
    else
    {
        dest_number->number[0] = 0;
    }
    if (label)
    {
        mmi_wcsncpy((WCHAR*)(dest_number->label), label, MMI_PHB_FIELD_LABEL_LENGTH);
    }
    else
    {
        dest_number->label[0] = 0;
    }
    dest_number->is_default = is_default;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_init_number
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_contact_set_asc_number(
                                srv_phb_number_struct* dest_number,
                                mmi_phb_sub_id id,
                                U8 save_index,
                                U8 type,
                                const CHAR* number,
                                const WCHAR* label,
                                MMI_BOOL is_default)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_number->sub_id = id;
    dest_number->index = save_index;
    dest_number->type = type;
    dest_number->last_used_sim = 0;
    if (number)
    {
        mmi_asc_n_to_wcs((WCHAR*)(dest_number->number), (CHAR*)number, MMI_PHB_NUMBER_PLUS_LENGTH);
    }
    else
    {
        dest_number->number[0] = 0;
    }
    if (label)
    {
        mmi_wcsncpy((WCHAR*)(dest_number->label), label, MMI_PHB_FIELD_LABEL_LENGTH);
    }
    else
    {
        dest_number->label[0] = 0;
    }
    dest_number->is_default = is_default;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_asc_number_ex
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_contact_set_asc_number_ex(
                                srv_phb_number_struct* dest_number,
                                mmi_phb_sub_id id,
                                U8 save_index,
                                U8 type,
                                U8 last_used_sim,
                                const CHAR* number,
                                const WCHAR* label,
                                MMI_BOOL is_default)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_number->sub_id = id;
    dest_number->index = save_index;
    dest_number->type = type;
    dest_number->last_used_sim = last_used_sim;
    if (number)
    {
        mmi_asc_n_to_wcs((WCHAR*)(dest_number->number), (CHAR*)number, MMI_PHB_NUMBER_PLUS_LENGTH);
    }
    else
    {
        dest_number->number[0] = 0;
    }
    if (label)
    {
        mmi_wcsncpy((WCHAR*)(dest_number->label), label, MMI_PHB_FIELD_LABEL_LENGTH);
    }
    else
    {
        dest_number->label[0] = 0;
    }
    dest_number->is_default = is_default;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_init_number
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_contact_copy_number(srv_phb_number_struct* dest_number, const srv_phb_number_struct* src_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_number->sub_id = src_number->sub_id;
    dest_number->type = src_number->type;
    dest_number->index = src_number->index;
    dest_number->last_used_sim = src_number->last_used_sim;
    mmi_wcsncpy((WCHAR*)(dest_number->number), (WCHAR*)(src_number->number), MMI_PHB_NUMBER_PLUS_LENGTH);
    mmi_wcsncpy((WCHAR*)(dest_number->label), (WCHAR*)(src_number->label), MMI_PHB_FIELD_LABEL_LENGTH);
    dest_number->is_default = src_number->is_default;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_init_email
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_contact_init_email(srv_phb_email_struct* email)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email->sub_id = MMI_PHB_SUB_ID_NEW;
    email->type = MMI_PHB_EMAIL_TYPE_HOME;
    email->email[0] = 0;
    email->label[0] = 0;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_email
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_contact_set_email(srv_phb_email_struct* dest_email, mmi_phb_sub_id id, U8 save_index, U8 type, const WCHAR* email, const WCHAR* label)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_email->sub_id = id;
    dest_email->index = save_index;
    dest_email->type = type;
    if (email)
    {
        mmi_wcsncpy((WCHAR*)(dest_email->email), email, MMI_PHB_EMAIL_LENGTH);
    }
    else
    {
        dest_email->email[0] = 0;
    }
    if (label)
    {
        mmi_wcsncpy((WCHAR*)(dest_email->label), label, MMI_PHB_FIELD_LABEL_LENGTH);
    }
    else
    {
        dest_email->label[0] = 0;
    }
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_asc_email
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_contact_set_asc_email(srv_phb_email_struct* dest_email, mmi_phb_sub_id id, U8 save_index, U8 type, const CHAR* email, const WCHAR* label)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_email->sub_id = id;
    dest_email->index = save_index;
    dest_email->type = type;
    if (email)
    {
        mmi_asc_n_to_wcs((WCHAR*)(dest_email->email), (CHAR*)email, MMI_PHB_EMAIL_LENGTH);
    }
    else
    {
        dest_email->email[0] = 0;
    }
    if (label)
    {
        mmi_wcsncpy((WCHAR*)(dest_email->label), label, MMI_PHB_FIELD_LABEL_LENGTH);
    }
    else
    {
        dest_email->label[0] = 0;
    }
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_copy_email
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_contact_copy_email(srv_phb_email_struct* dest_email, const srv_phb_email_struct* src_email)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_email->sub_id = src_email->sub_id;
    dest_email->index = src_email->index;
    dest_email->type = src_email->type;
    mmi_wcsncpy((WCHAR*)(dest_email->label), (WCHAR*)(dest_email->label), MMI_PHB_FIELD_LABEL_LENGTH);
    mmi_wcsncpy((WCHAR*)(dest_email->email), (WCHAR*)(src_email->email), MMI_PHB_EMAIL_LENGTH);
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_init_address
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_contact_init_address(srv_phb_address_struct* address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    address->sub_id = MMI_PHB_SUB_ID_NEW;
    address->type = 0;
    address->address.pobox[0] = 0;
    address->address.extension[0] = 0;
    address->address.street[0] = 0;
    address->address.city[0] = 0;
    address->address.state[0] = 0;
    address->address.postalcode[0] = 0;
    address->address.country[0] = 0;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_address
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_contact_set_address(srv_phb_address_struct* dest_address, mmi_phb_sub_id id, U8 type, const mmi_phb_address_struct* address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_address->sub_id = id;
    dest_address->type = type;
    if (address)
    {
        mmi_wcsncpy((WCHAR*)(dest_address->address.pobox), (WCHAR*)(address->pobox), MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((WCHAR*)(dest_address->address.extension), (WCHAR*)(address->extension), MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((WCHAR*)(dest_address->address.street), (WCHAR*)(address->street), MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((WCHAR*)(dest_address->address.city), (WCHAR*)(address->city), MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((WCHAR*)(dest_address->address.state), (WCHAR*)(address->state), MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((WCHAR*)(dest_address->address.postalcode), (WCHAR*)(address->postalcode), MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((WCHAR*)(dest_address->address.country), (WCHAR*)(address->country), MMI_PHB_ADDRESS_LENGTH);
    }
    else
    {
        dest_address->address.pobox[0] = 0;
        dest_address->address.extension[0] = 0;
        dest_address->address.street[0] = 0;
        dest_address->address.city[0] = 0;
        dest_address->address.state[0] = 0;
        dest_address->address.postalcode[0] = 0;
        dest_address->address.country[0] = 0;
    }
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_init_address
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_contact_copy_address(srv_phb_address_struct* dest_address, const srv_phb_address_struct* src_address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_address->sub_id = src_address->sub_id;
    dest_address->index = src_address->index;
    dest_address->type = src_address->type;
    mmi_wcsncpy((WCHAR*)(dest_address->address.pobox), (WCHAR*)(src_address->address.pobox), MMI_PHB_ADDRESS_LENGTH);
    mmi_wcsncpy((WCHAR*)(dest_address->address.extension), (WCHAR*)(src_address->address.extension), MMI_PHB_ADDRESS_LENGTH);
    mmi_wcsncpy((WCHAR*)(dest_address->address.street), (WCHAR*)(src_address->address.street), MMI_PHB_ADDRESS_LENGTH);
    mmi_wcsncpy((WCHAR*)(dest_address->address.city), (WCHAR*)(src_address->address.city), MMI_PHB_ADDRESS_LENGTH);
    mmi_wcsncpy((WCHAR*)(dest_address->address.state), (WCHAR*)(src_address->address.state), MMI_PHB_ADDRESS_LENGTH);
    mmi_wcsncpy((WCHAR*)(dest_address->address.postalcode), (WCHAR*)(src_address->address.postalcode), MMI_PHB_ADDRESS_LENGTH);
    mmi_wcsncpy((WCHAR*)(dest_address->address.country), (WCHAR*)(src_address->address.country), MMI_PHB_ADDRESS_LENGTH);
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_init_url
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_contact_init_url(srv_phb_url_struct* url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    url->sub_id = MMI_PHB_SUB_ID_NEW;
    url->type = 0;
    url->url[0] = 0;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_url
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_contact_set_url(srv_phb_url_struct* dest_url, mmi_phb_sub_id id, U8 type, const WCHAR* url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_url->sub_id = id;
    dest_url->type = type;
    if (url)
    {
        mmi_wcsncpy((WCHAR*)(dest_url->url), url, MMI_PHB_URL_LENGTH);
    }
    else
    {
        dest_url->url[0] = 0;
    }
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_asc_url
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_contact_set_asc_url(srv_phb_url_struct* dest_url, mmi_phb_sub_id id, U8 type, const CHAR* url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_url->sub_id = id;
    dest_url->type = type;
    if (url)
    {
        mmi_asc_n_to_wcs((WCHAR*)(dest_url->url), (CHAR*)url, MMI_PHB_URL_LENGTH);
    }
    else
    {
        dest_url->url[0] = 0;
    }
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_copy_url
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_contact_copy_url(srv_phb_url_struct* dest_url, const srv_phb_url_struct* src_url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_url->sub_id = src_url->sub_id;
    dest_url->index = src_url->index;
    dest_url->type = src_url->type;
    mmi_wcsncpy((WCHAR*)(dest_url->url), (WCHAR*)(src_url->url), MMI_PHB_URL_LENGTH);
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_init_note
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_contact_init_note(srv_phb_note_struct* note)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    note->sub_id = MMI_PHB_SUB_ID_NEW;
    note->type = 0;
    note->note[0] = 0;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_note
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_contact_set_note(srv_phb_note_struct* dest_note, mmi_phb_sub_id id, U8 type, const WCHAR* note)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_note->sub_id = id;
    dest_note->type = type;
    if (note)
    {
        mmi_wcsncpy((WCHAR*)(dest_note->note), note, MMI_PHB_NOTE_LENGTH);
    }
    else
    {
        dest_note->note[0] = 0;
    }
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_copy_note
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_contact_copy_note(srv_phb_note_struct* dest_note, const srv_phb_note_struct* src_note)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_note->sub_id = src_note->sub_id;
    dest_note->index = src_note->index;
    dest_note->type = src_note->type;
    mmi_wcsncpy((WCHAR*)(dest_note->note), (WCHAR*)(src_note->note), MMI_PHB_NOTE_LENGTH);
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_filed_node
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_contact_set_filed(srv_phb_contact_field_struct* filed_point, MMI_BOOL is_dynamic, void* field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filed_point->is_reset = MMI_FALSE;
    filed_point->dynamic_field = is_dynamic;
    filed_point->field = field;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_fname
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL srv_phb_contact_add_node_tail(srv_phb_link_struct* link, srv_phb_node_struct* new_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!link)
    {
        return MMI_FALSE;
    }
    if (link->head)
    {
        link->tail->next = new_node;
        link->tail = new_node;
    }
    else /* empty link */
    {
        link->head = new_node;
        link->tail = new_node;
    }
    new_node->next = NULL;
    link->count++;
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_node_realloc
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static srv_phb_node_struct* srv_phb_contact_node_realloc(srv_phb_link_struct* link)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_node_struct* node;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!link)
    {
        return NULL;
    }
    if (link->alloc_head)
    {
        node = link->alloc_head;
        link->alloc_head = link->alloc_head->next;
        return node;
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_node_remove
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static srv_phb_node_struct* srv_phb_contact_node_remove(srv_phb_link_struct* link, srv_phb_node_struct* prev, srv_phb_node_struct* node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!link)
    {
        return NULL;
    }
    if (prev)
    {
        prev->next = node->next;
    }
    else
    {
        link->head = link->head->next;
    }
    if (node == link->tail)
    {
        link->tail = prev;
    }
    link->count--;
    if (link->alloc_head)
    {
        link->alloc_tail->next = node;
        link->alloc_tail = node;
    }
    else
    {
        link->alloc_head = node;
        link->alloc_tail = node;
    }
    node->next = NULL;
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_name_field
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static srv_phb_contact_name_struct* srv_phb_contact_get_name_field(srv_phb_contact_struct* contact, MMI_BOOL alloc_new)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_field_struct* name_field;
    srv_phb_contact_name_struct* name = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!contact)
    {
        return NULL;
    }
    name_field = &(contact->fileds_point[MMI_PHB_CONTACT_FIELD_ID_NAME]);
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_CONTACT_GET_NAME_FIELD, name_field->field, alloc_new);
    if (name_field->field)
    {
        name = (srv_phb_contact_name_struct*)(name_field->field);
        if (name_field->is_reset)
        {
            name_field->is_reset = MMI_FALSE;
            srv_phb_contact_init_name((srv_phb_contact_name_struct*)(name_field->field));
        }
    }
    else if (alloc_new)
    {
        name = srv_phb_mem_malloc(sizeof(srv_phb_contact_name_struct), SRV_PHB_MEMORY_TYPE_ADM);

        srv_phb_contact_init_name(name);
        srv_phb_contact_set_filed(name_field, MMI_FALSE, name);
    }
    return name;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_bday_field
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static srv_phb_bday_struct* srv_phb_contact_get_bday_field(srv_phb_contact_struct* contact, MMI_BOOL alloc_new)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_field_struct* bday_field;
    srv_phb_bday_struct* bday = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!contact)
    {
        return NULL;
    }
    bday_field = &(contact->fileds_point[MMI_PHB_CONTACT_FIELD_ID_BDAY]);
    
    if (bday_field->field)
    {
        bday = (srv_phb_bday_struct*)(bday_field->field);
        if (bday_field->is_reset)
        {
            bday_field->is_reset = MMI_FALSE;
            memset(bday, 0, sizeof(srv_phb_bday_struct));
        }
    }
    else if (alloc_new)
    {
        bday = srv_phb_mem_malloc(sizeof(srv_phb_bday_struct), SRV_PHB_MEMORY_TYPE_ADM);
        
        memset(bday, 0, sizeof(srv_phb_bday_struct));
        srv_phb_contact_set_filed(bday_field, MMI_FALSE, bday);
    }
    return bday;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_group_field
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static srv_phb_group_struct* srv_phb_contact_get_group_field(srv_phb_contact_struct* contact, MMI_BOOL alloc_new)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_field_struct* group_field;
    srv_phb_group_struct* group = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!contact)
    {
        return NULL;
    }
    group_field = &(contact->fileds_point[MMI_PHB_CONTACT_FIELD_ID_GROUP]);
    
    if (group_field->field)
    {
        group = (srv_phb_group_struct*)(group_field->field);
        if (group_field->is_reset)
        {
            group_field->is_reset = MMI_FALSE;
            srv_phb_contact_init_group(group);
        }
    }
    else if (alloc_new)
    {
        group = srv_phb_mem_malloc(sizeof(srv_phb_group_struct), SRV_PHB_MEMORY_TYPE_ADM);
        
        srv_phb_contact_init_group(group);
        srv_phb_contact_set_filed(group_field, MMI_FALSE, group);
    }
    return group;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_res_field
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static srv_phb_res_struct* srv_phb_contact_get_res_field(srv_phb_contact_struct* contact, mmi_phb_contact_field_id_enum field_id, MMI_BOOL alloc_new)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_field_struct* res_field;
    srv_phb_res_struct* res = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!contact)
    {
        return NULL;
    }
    res_field = &(contact->fileds_point[field_id]);
    
    if (res_field->field)
    {
        res = (srv_phb_res_struct*)(res_field->field);
        if (res_field->is_reset)
        {
            res_field->is_reset = MMI_FALSE;
            srv_phb_contact_init_res(res);
        }
    }
    else if (alloc_new)
    {
        res = srv_phb_mem_malloc(sizeof(srv_phb_res_struct), SRV_PHB_MEMORY_TYPE_ADM);
        
        srv_phb_contact_init_res(res);
        srv_phb_contact_set_filed(res_field, MMI_FALSE, res);
    }
    return res;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_string_field_data
* DESCRIPTION
*  get a pure string field's data, if data not malloc yet, maalloc it first
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static WCHAR* srv_phb_contact_get_string_field_data(srv_phb_contact_struct* contact, mmi_phb_contact_field_id_enum field_id, S32 data_length, MMI_BOOL alloc_new)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_field_struct* field;
    WCHAR* data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!contact)
    {
        return NULL;
    }
    field = &(contact->fileds_point[field_id]);
    
    if (field->field)
    {
        data = (WCHAR*)(field->field);
        if (field->is_reset) /* name field need reset */
        {
            field->is_reset = MMI_FALSE;
            data[0] = 0;
        }
    }
    else if (alloc_new)
    {
        data = srv_phb_mem_malloc(sizeof(WCHAR) * (data_length + 1), SRV_PHB_MEMORY_TYPE_ADM);
        
        data[0] = 0;
        srv_phb_contact_set_filed(field, MMI_FALSE, data);
    }
    return data;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_link_field
* DESCRIPTION
*  get a pure string field's data, if data not malloc yet, maalloc it first
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static srv_phb_link_struct* srv_phb_contact_get_link_field(srv_phb_contact_struct* contact, mmi_phb_contact_field_id_enum field_id, MMI_BOOL alloc_new)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_field_struct* link_field;
    srv_phb_link_struct* link = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!contact)
    {
        return NULL;
    }
    link_field = &(contact->fileds_point[field_id]);
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_CONTACT_GET_LINK_FIELD, link_field->field, alloc_new);
    if (link_field->field)
    {
        link = (srv_phb_link_struct*)(link_field->field);
        if (link_field->is_reset)
        {
            link_field->is_reset = MMI_FALSE;
            srv_phb_contact_reset_link_field(link);
        }
    }
    else if (alloc_new)
    {
        link = srv_phb_mem_malloc(sizeof(srv_phb_link_struct), SRV_PHB_MEMORY_TYPE_ADM);
        
        memset(link, 0, sizeof(srv_phb_link_struct));
        srv_phb_contact_set_filed(link_field, MMI_TRUE, link);
    }
    return link;
}


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

#define CONTACT_VALUES
/*****************************************************************************
* FUNCTION
*  srv_phb_create_contact
* DESCRIPTION
*  create a contact handle
* PARAMETERS
*  contact            : [IN]   src contact, if it's NULL return a empry contact, otherwise copy the src contact
* RETURNS
*  void
*****************************************************************************/
srv_phb_contact srv_phb_create_contact(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* dest_contact = srv_phb_mem_malloc(sizeof(srv_phb_contact_struct), SRV_PHB_MEMORY_TYPE_ADM);
    srv_phb_contact_struct* src_contact = contact;
    void* src;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_CONTACT_CREATE_CONTACT, src_contact, dest_contact);

    memset(dest_contact, 0, sizeof(srv_phb_contact_struct));
    if (src_contact)
    {
        mmi_phb_contact_field_id_enum i = MMI_PHB_CONTACT_FIELD_ID_NAME;
        for (; i < MMI_PHB_CONTACT_FIELD_DATA_TOTAL; i++)
        {
            switch (i)
            {
                case MMI_PHB_CONTACT_FIELD_ID_NAME:
                    src = (void*)srv_phb_contact_get_name_field(src_contact, MMI_FALSE);
                    if (src)
                    {
                        memcpy(
                            srv_phb_contact_get_name_field(dest_contact, MMI_TRUE),
                            src,
                            sizeof(srv_phb_contact_name_struct));
                    }
                    break;

            #ifdef __MMI_PHB_USIM_SUPPORT__
                case MMI_PHB_CONTACT_FIELD_ID_NICK:
                    src = (void*)srv_phb_contact_get_string_field_data(src_contact, i, MMI_PHB_NAME_FIELD_LENGTH, MMI_FALSE);
                    if (src)
                    {
                        mmi_wcsncpy(
                            srv_phb_contact_get_string_field_data(dest_contact, i, MMI_PHB_NAME_FIELD_LENGTH, MMI_TRUE),
                            src,
                            MMI_PHB_NAME_FIELD_LENGTH);
                    }
                    break;
            #endif /*   __MMI_PHB_USIM_SUPPORT__ */

                case MMI_PHB_CONTACT_FIELD_ID_NUMBER:
                {
                    src = (void*)srv_phb_contact_get_number_iterator(src_contact);
                    while (src)
                    {
                        srv_phb_contact_add_number(dest_contact, srv_phb_contact_get_number_next((srv_phb_iterator*)(&src)));
                    }
                }
                    break;

            #ifdef __MMI_PHB_OPTIONAL_FIELD__
                case MMI_PHB_CONTACT_FIELD_ID_EMAIL:
                {
                    src = (void*)srv_phb_contact_get_email_iterator(src_contact);
                    while (src)
                    {
                        srv_phb_contact_add_email(dest_contact, srv_phb_contact_get_email_next((srv_phb_iterator*)(&src)));
                    }
                }
                    break;
            #ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
                case MMI_PHB_CONTACT_FIELD_ID_COMPANY:
                    src = (void*)srv_phb_contact_get_string_field_data(src_contact, i, MMI_PHB_COMPANY_LENGTH, MMI_FALSE);
                    if (src)
                    {
                        mmi_wcsncpy(
                            srv_phb_contact_get_string_field_data(dest_contact, i, MMI_PHB_COMPANY_LENGTH, MMI_TRUE),
                            src,
                            MMI_PHB_COMPANY_LENGTH);
                    }
                    break;
            #endif /* __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__ */        
            #endif /* __MMI_PHB_OPTIONAL_FIELD__ */

            #if defined(__MMI_PHB_INFO_FIELD__)
                case MMI_PHB_CONTACT_FIELD_ID_ADDRESS:
                {
                    src = (void*)srv_phb_contact_get_address_iterator(src_contact);
                    while (src)
                    {
                        srv_phb_contact_add_address(dest_contact, srv_phb_contact_get_address_next((srv_phb_iterator*)(&src)));
                    }
                }
                    break;

                case MMI_PHB_CONTACT_FIELD_ID_TITLE:
                    src = (void*)srv_phb_contact_get_string_field_data(src_contact, i, MMI_PHB_TITLE_LENGTH, MMI_FALSE);
                    if (src)
                    {
                        mmi_wcsncpy(
                            srv_phb_contact_get_string_field_data(dest_contact, i, MMI_PHB_TITLE_LENGTH, MMI_TRUE),
                            src,
                            MMI_PHB_TITLE_LENGTH);
                    }
                    break;

                case MMI_PHB_CONTACT_FIELD_ID_URL:
                {
                    src = (void*)srv_phb_contact_get_url_iterator(src_contact);
                    while (src)
                    {
                        srv_phb_contact_add_url(dest_contact, srv_phb_contact_get_url_next((srv_phb_iterator*)(&src)));
                    }
                }
                    break;
                    
                case MMI_PHB_CONTACT_FIELD_ID_NOTE:
                {
                    src = (void*)srv_phb_contact_get_note_iterator(src_contact);
                    while (src)
                    {
                        srv_phb_contact_add_note(dest_contact, srv_phb_contact_get_note_next((srv_phb_iterator*)(&src)));
                    }
                }
                    break;
            #endif /* defined(__MMI_PHB_INFO_FIELD__) */

            #ifdef __MMI_PHB_CALLER_GROUP__
                case MMI_PHB_CONTACT_FIELD_ID_GROUP:
                    src = (void*)srv_phb_contact_get_group_field(src_contact, MMI_FALSE);
                    if (src)
                    {
                        memcpy(
                            srv_phb_contact_get_group_field(dest_contact, MMI_TRUE),
                            src,
                            sizeof(srv_phb_group_struct));
                    }
                    break;
            #endif /* __MMI_PHB_CALLER_GROUP__ */

            #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
                case MMI_PHB_CONTACT_FIELD_ID_BDAY:
                    src = (void*)srv_phb_contact_get_bday_field(src_contact, MMI_FALSE);
                    if (src)
                    {
                        memcpy(
                            srv_phb_contact_get_bday_field(dest_contact, MMI_TRUE),
                            src,
                            sizeof(srv_phb_bday_struct));
                    }
                    break;
            #endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */

                case MMI_PHB_CONTACT_FIELD_ID_RING:
                case MMI_PHB_CONTACT_FIELD_ID_IMAGE:
                case MMI_PHB_CONTACT_FIELD_ID_VIDEO:
                    src = (void*)srv_phb_contact_get_res_field(src_contact, i, MMI_FALSE);
                    if (src)
                    {
                        memcpy(
                            srv_phb_contact_get_res_field(dest_contact, i, MMI_TRUE),
                            src,
                            sizeof(srv_phb_res_struct));
                    }
                    break;

            #if defined(__MMI_VOIP__)
                case MMI_PHB_CONTACT_FIELD_ID_VOIP:
                    src = (void*)srv_phb_contact_get_string_field_data(src_contact, i, VOIP_URI_LEN - 1, MMI_FALSE);
                    if (src)
                    {
                        mmi_wcsncpy(
                            srv_phb_contact_get_string_field_data(dest_contact, i, VOIP_URI_LEN - 1, MMI_TRUE),
                            src,
                            VOIP_URI_LEN - 1);
                    }
                    break;
            #endif /* defined(__MMI_VOIP__) */

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
            #endif /* defined(__MMI_IMPS__) */

            #if defined(__MMI_PHB_MSN_FIELD__)
                case MMI_PHB_CONTACT_FIELD_ID_MSN:
                    src = (void*)srv_phb_contact_get_string_field_data(src_contact, i, MMI_PHB_EMAIL_LENGTH, MMI_FALSE);
                    if (src)
                    {
                        mmi_wcsncpy(
                            srv_phb_contact_get_string_field_data(dest_contact, i, MMI_PHB_EMAIL_LENGTH, MMI_TRUE),
                            src,
                            MMI_PHB_EMAIL_LENGTH);
                    }
                    break;
            #endif /* defined(__MMI_PHB_MSN_FIELD__) */
            }
        }
    }
    return dest_contact;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_free_contact
* DESCRIPTION
*  free a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void srv_phb_free_contact(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = (srv_phb_contact_struct*)contact;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_CONTACT_FREE_CONTACT, contact);
    if (info)
    {
        srv_phb_contact_field_struct* field_point;
        S32 i = 0;
        for (; i < MMI_PHB_CONTACT_FIELD_DATA_TOTAL; i++)
        {
            field_point = &(info->fileds_point[i]);
            if (field_point->field)
            {
                if (field_point->dynamic_field)
                {
                    srv_phb_free_link(
                        ((srv_phb_link_struct*)(field_point->field))->head,
                        ((srv_phb_link_struct*)(field_point->field))->tail);
                    srv_phb_free_link(
                        ((srv_phb_link_struct*)(field_point->field))->alloc_head,
                        ((srv_phb_link_struct*)(field_point->field))->alloc_tail);
                }
                srv_phb_mem_free(field_point->field);
            }
        }
        srv_phb_mem_free(info);
    }
}


/*****************************************************************************
* FUNCTION
*  srv_phb_reset_contact
* DESCRIPTION
*  reset all contact values
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void srv_phb_reset_contact(srv_phb_contact contact, U32 field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = (srv_phb_contact_struct*)contact;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (info)
    {
        S32 i;
        for (i = 0; i < MMI_PHB_CONTACT_FIELD_DATA_TOTAL; i++)
        {
            if ((1 << (i + 1)) & field)
            {
                info->fileds_point[i].is_reset = MMI_TRUE;
            }
        }
    }
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_fname
* DESCRIPTION
*  get first name from a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
WCHAR* srv_phb_contact_get_fname(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_name_struct* name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    name = srv_phb_contact_get_name_field(info, MMI_FALSE);
    if (name)
    {
        return name->fname;
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_fname
* DESCRIPTION
*  set first name to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
WCHAR* srv_phb_contact_set_fname(srv_phb_contact contact, const WCHAR* fname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_name_struct* name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    name = srv_phb_contact_get_name_field(info, MMI_TRUE);
    if (name)
    {
        if (fname)
        {
            mmi_wcsncpy((WCHAR*)name->fname, fname, MMI_PHB_NAME_FIELD_LENGTH);
        }
        else
        {
            name->fname[0] = 0;
        }
        return name->fname;
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_lname
* DESCRIPTION
*  get last name from a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
WCHAR* srv_phb_contact_get_lname(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_name_struct* name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    name = srv_phb_contact_get_name_field(info, MMI_FALSE);
    if (name)
    {
        return name->lname;
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_lname
* DESCRIPTION
*  set last name to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
WCHAR* srv_phb_contact_set_lname(srv_phb_contact contact, const WCHAR* lname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_name_struct* name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    name = srv_phb_contact_get_name_field(info, MMI_TRUE);
    if (name)
    {
        if (lname)
        {
            mmi_wcsncpy((WCHAR*)name->lname, lname, MMI_PHB_NAME_FIELD_LENGTH);
        }
        else
        {
            name->lname[0] = 0;
        }
        return name->lname;
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_name
* DESCRIPTION
*  set name to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
WCHAR* srv_phb_contact_set_name(srv_phb_contact contact, const WCHAR* name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_name_struct* contact_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    contact_name = srv_phb_contact_get_name_field(info, MMI_TRUE);
    if (contact_name)
    {
        if (name)
        {
            mmi_wcsncpy((WCHAR*)contact_name->name, name, MMI_PHB_NAME_LENGTH);
        }
        else
        {
            contact_name->name[0] = 0;
        }
        return contact_name->name;
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_lname
* DESCRIPTION
*  get full name from a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
WCHAR* srv_phb_contact_get_name(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_name_struct* name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    name = srv_phb_contact_get_name_field(info, MMI_FALSE);
    if (name)
    {
        srv_phb_convert_to_name((U16*)(name->name), (U16*)(name->fname), (U16*)(name->lname), MMI_PHB_NAME_LENGTH);
        return name->name;
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_nick
* DESCRIPTION
*  get nick name from a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
WCHAR* srv_phb_contact_get_nick(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    return srv_phb_contact_get_string_field_data(info, MMI_PHB_CONTACT_FIELD_ID_NICK, MMI_PHB_NAME_FIELD_LENGTH, MMI_FALSE);
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_nick
* DESCRIPTION
*  set nick name to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
WCHAR* srv_phb_contact_set_nick(srv_phb_contact contact, const WCHAR* nick)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    WCHAR* dest_nick = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    dest_nick = srv_phb_contact_get_string_field_data(info, MMI_PHB_CONTACT_FIELD_ID_NICK, MMI_PHB_NAME_FIELD_LENGTH, MMI_TRUE);
    if (dest_nick)
    {
        if (nick)
        {
            mmi_wcsncpy(dest_nick, nick, MMI_PHB_NAME_FIELD_LENGTH);
        }
        else
        {
            dest_nick[0] = 0;
        }
    }
    return dest_nick;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_company
* DESCRIPTION
*  get company filed from contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
WCHAR* srv_phb_contact_get_company(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    return srv_phb_contact_get_string_field_data(info, MMI_PHB_CONTACT_FIELD_ID_COMPANY, MMI_PHB_COMPANY_LENGTH, MMI_FALSE);
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_company
* DESCRIPTION
*  set company field to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
WCHAR* srv_phb_contact_set_company(srv_phb_contact contact, const WCHAR* company)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    WCHAR* dest_company = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    dest_company = srv_phb_contact_get_string_field_data(info, MMI_PHB_CONTACT_FIELD_ID_COMPANY, MMI_PHB_COMPANY_LENGTH, MMI_TRUE);
    if (dest_company)
    {
        if (company)
        {
            mmi_wcsncpy(dest_company, company, MMI_PHB_COMPANY_LENGTH);
        }
        else
        {
            dest_company[0] = 0;
        }
    }
    return dest_company;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_title
* DESCRIPTION
*  get title field to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
WCHAR* srv_phb_contact_get_title(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    return srv_phb_contact_get_string_field_data(info, MMI_PHB_CONTACT_FIELD_ID_TITLE, MMI_PHB_TITLE_LENGTH, MMI_FALSE);
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_title
* DESCRIPTION
*  set title field to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
WCHAR* srv_phb_contact_set_title(srv_phb_contact contact, const WCHAR* title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    WCHAR* dest_title = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    dest_title = srv_phb_contact_get_string_field_data(info, MMI_PHB_CONTACT_FIELD_ID_TITLE, MMI_PHB_TITLE_LENGTH, MMI_TRUE);
    if (dest_title)
    {
        if (title)
        {
            mmi_wcsncpy(dest_title, title, MMI_PHB_TITLE_LENGTH);
        }
        else
        {
            dest_title[0] = 0;
        }
    }
    return dest_title;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_bday
* DESCRIPTION
*  get bday field to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_bday_struct* srv_phb_contact_get_bday(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    return srv_phb_contact_get_bday_field(info, MMI_FALSE);
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_bday
* DESCRIPTION
*  set bday field to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_bday_struct* srv_phb_contact_set_bday(srv_phb_contact contact, const srv_phb_bday_struct* bday)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_bday_struct* dest_bday = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    dest_bday = srv_phb_contact_get_bday_field(info, MMI_TRUE);
    if (dest_bday)
    {
        if (bday)
        {
            memcpy(dest_bday, bday, sizeof(srv_phb_bday_struct));
        }
        else
        {
            memset(dest_bday, 0, sizeof(srv_phb_bday_struct));
        }
    }
    return dest_bday;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_group
* DESCRIPTION
*  get group field to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_group_struct* srv_phb_contact_get_group(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    return srv_phb_contact_get_group_field(info, MMI_FALSE);
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_group
* DESCRIPTION
*  set group field to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_group_struct* srv_phb_contact_set_group(srv_phb_contact contact, const srv_phb_group_struct* group)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_group_struct* dest_group = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    dest_group = srv_phb_contact_get_group_field(info, MMI_TRUE);
    if (dest_group)
    {
        if (group)
        {
            memcpy(dest_group, group, sizeof(srv_phb_group_struct));
        }
        else
        {
            srv_phb_contact_init_group(dest_group);
        }
    }
    return dest_group;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_group_ex
* DESCRIPTION
*  set group field to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_group_struct* srv_phb_contact_set_group_ex(srv_phb_contact contact, U8 group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_group_struct* dest_group = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    dest_group = srv_phb_contact_get_group_field(info, MMI_TRUE);
    if (dest_group && group_id != MMI_PHB_INVALID_GROUP_ID)
    {
        dest_group->group_count = 1;
        dest_group->group_id[0] = group_id;
    }
    return dest_group;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_ringtone
* DESCRIPTION
*  get ringtone field to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_res_struct* srv_phb_contact_get_ringtone(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    return srv_phb_contact_get_res_field(info, MMI_PHB_CONTACT_FIELD_ID_RING, MMI_FALSE);
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_ringtone
* DESCRIPTION
*  set ringtone field to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_res_struct* srv_phb_contact_set_ringtone(srv_phb_contact contact, const srv_phb_res_struct* ringtone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_res_struct* dest_ring = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    dest_ring = srv_phb_contact_get_res_field(info, MMI_PHB_CONTACT_FIELD_ID_RING, MMI_TRUE);
    if (dest_ring)
    {
        if (ringtone)
        {
            memcpy(dest_ring, ringtone, sizeof(srv_phb_res_struct));
        }
        else
        {
            srv_phb_contact_init_res(dest_ring);
        }
    }
    return dest_ring;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_ringtone_ex
* DESCRIPTION
*  set ringtone field to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_res_struct* srv_phb_contact_set_ringtone_ex(srv_phb_contact contact, U16 id, const WCHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_res_struct* dest_ring = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    dest_ring = srv_phb_contact_get_res_field(info, MMI_PHB_CONTACT_FIELD_ID_RING, MMI_TRUE);
    if (dest_ring)
    {
        dest_ring->res_id = id;
        if (path)
        {
            mmi_wcsncpy(dest_ring->res_path, path, SRV_FMGR_PATH_MAX_LEN);
        }
        else
        {
            dest_ring->res_path[0] = 0;
        }
    }
    return dest_ring;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_image
* DESCRIPTION
*  get image field to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_res_struct* srv_phb_contact_get_image(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_res_struct* image;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    image = srv_phb_contact_get_res_field(info, MMI_PHB_CONTACT_FIELD_ID_IMAGE, MMI_FALSE);
    if (image && !(image->res_path[0]) && !(image->res_id))
    {
        image->res_id = IMG_PHB_DEFAULT;
    }
    return image;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_image
* DESCRIPTION
*  set image field to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_res_struct* srv_phb_contact_set_image(srv_phb_contact contact, const srv_phb_res_struct* image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_res_struct* dest_image = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    dest_image = srv_phb_contact_get_res_field(info, MMI_PHB_CONTACT_FIELD_ID_IMAGE, MMI_TRUE);
    if (dest_image)
    {
        if (image)
        {
            memcpy(dest_image, image, sizeof(srv_phb_res_struct));
        }
        else
        {
            srv_phb_contact_init_res(dest_image);
        }
    }
    return dest_image;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_image_ex
* DESCRIPTION
*  set image field to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_res_struct* srv_phb_contact_set_image_ex(srv_phb_contact contact, U16 id, const WCHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_res_struct* dest_image = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    dest_image = srv_phb_contact_get_res_field(info, MMI_PHB_CONTACT_FIELD_ID_IMAGE, MMI_TRUE);
    if (dest_image)
    {
        dest_image->res_id = id;
        if (path)
        {
            mmi_wcsncpy(dest_image->res_path, path, SRV_FMGR_PATH_MAX_LEN);
        }
        else
        {
            dest_image->res_path[0] = 0;
        }
    }
    return dest_image;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_video
* DESCRIPTION
*  get video field to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_res_struct* srv_phb_contact_get_video(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    return srv_phb_contact_get_res_field(info, MMI_PHB_CONTACT_FIELD_ID_VIDEO, MMI_FALSE);
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_video
* DESCRIPTION
*  set video field to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_res_struct* srv_phb_contact_set_video(srv_phb_contact contact, const srv_phb_res_struct* video)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_res_struct* dest_video = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    dest_video = srv_phb_contact_get_res_field(info, MMI_PHB_CONTACT_FIELD_ID_VIDEO, MMI_TRUE);
    if (dest_video)
    {
        if (video)
        {
            memcpy(dest_video, video, sizeof(srv_phb_res_struct));
        }
        else
        {
            srv_phb_contact_init_res(dest_video);
        }
    }
    return dest_video;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_video_ex
* DESCRIPTION
*  set video field to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_res_struct* srv_phb_contact_set_video_ex(srv_phb_contact contact, U16 id, const WCHAR* path, MMI_BOOL video_sound)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_res_struct* dest_video = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    dest_video = srv_phb_contact_get_res_field(info, MMI_PHB_CONTACT_FIELD_ID_VIDEO, MMI_TRUE);
    if (dest_video)
    {
        dest_video->res_id = id;
        dest_video->flag = video_sound;
        if (path)
        {
            mmi_wcsncpy(dest_video->res_path, path, SRV_FMGR_PATH_MAX_LEN);
        }
        else
        {
            dest_video->res_path[0] = 0;
        }
    }
    return dest_video;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_imps
* DESCRIPTION
*  get imps field to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
WCHAR* srv_phb_contact_get_imps(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    return srv_phb_contact_get_string_field_data(info, MMI_PHB_CONTACT_FIELD_ID_IMPS, MMI_PHB_IMPS_LENGTH, MMI_FALSE);
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_imps
* DESCRIPTION
*  set imps field to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
WCHAR* srv_phb_contact_set_imps(srv_phb_contact contact, const WCHAR* imps)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    WCHAR* dest_imps = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    dest_imps = srv_phb_contact_get_string_field_data(info, MMI_PHB_CONTACT_FIELD_ID_IMPS, MMI_PHB_IMPS_LENGTH, MMI_TRUE);
    if (dest_imps)
    {
        if (imps)
        {
            mmi_wcsncpy(dest_imps, imps, MMI_PHB_IMPS_LENGTH);
        }
        else
        {
            dest_imps[0] = 0;
        }
    }
    return dest_imps;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_imps
* DESCRIPTION
*  set imps field to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
WCHAR* srv_phb_contact_set_asc_imps(srv_phb_contact contact, const CHAR* imps)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    WCHAR* dest_imps = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    dest_imps = srv_phb_contact_get_string_field_data(info, MMI_PHB_CONTACT_FIELD_ID_IMPS, MMI_PHB_IMPS_LENGTH, MMI_TRUE);
    if (dest_imps)
    {
        if (imps)
        {
            mmi_asc_n_to_wcs(dest_imps, (CHAR*)imps, MMI_PHB_IMPS_LENGTH);
        }
        else
        {
            dest_imps[0] = 0;
        }
    }
    return dest_imps;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_voip
* DESCRIPTION
*  get voip field to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
WCHAR* srv_phb_contact_get_voip(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    return srv_phb_contact_get_string_field_data(info, MMI_PHB_CONTACT_FIELD_ID_VOIP, VOIP_URI_LEN - 1, MMI_FALSE);
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_voip
* DESCRIPTION
*  set voip field to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
WCHAR* srv_phb_contact_set_voip(srv_phb_contact contact, const WCHAR* voip)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    WCHAR* dest_voip = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    dest_voip = srv_phb_contact_get_string_field_data(info, MMI_PHB_CONTACT_FIELD_ID_VOIP, VOIP_URI_LEN - 1, MMI_TRUE);
    if (dest_voip)
    {
        if (voip)
        {
            mmi_wcsncpy(dest_voip, voip, VOIP_URI_LEN - 1);
        }
        else
        {
            dest_voip[0] = 0;
        }
    }
    return dest_voip;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_asc_voip
* DESCRIPTION
*  set voip field to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
WCHAR* srv_phb_contact_set_asc_voip(srv_phb_contact contact, const CHAR* voip)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    WCHAR* dest_voip = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    dest_voip = srv_phb_contact_get_string_field_data(info, MMI_PHB_CONTACT_FIELD_ID_VOIP, VOIP_URI_LEN - 1, MMI_TRUE);
    if (dest_voip)
    {
        if (voip)
        {
            mmi_asc_n_to_wcs(dest_voip, (CHAR*)voip, VOIP_URI_LEN - 1);
        }
        else
        {
            dest_voip[0] = 0;
        }
    }
    return dest_voip;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_msn
* DESCRIPTION
*  get msn field to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
WCHAR* srv_phb_contact_get_msn(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    return srv_phb_contact_get_string_field_data(info, MMI_PHB_CONTACT_FIELD_ID_MSN, MMI_PHB_EMAIL_LENGTH, MMI_FALSE);
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_msn
* DESCRIPTION
*  set msn field to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
WCHAR* srv_phb_contact_set_msn(srv_phb_contact contact, const WCHAR* msn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    WCHAR* dest_msn = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    dest_msn = srv_phb_contact_get_string_field_data(info, MMI_PHB_CONTACT_FIELD_ID_MSN, MMI_PHB_EMAIL_LENGTH, MMI_TRUE);
    if (dest_msn)
    {
        if (msn)
        {
            mmi_wcsncpy(dest_msn, msn, MMI_PHB_EMAIL_LENGTH);
        }
        else
        {
            dest_msn[0] = 0;
        }
    }
    return dest_msn;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_set_asc_msn
* DESCRIPTION
*  set msn field to a contact handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
WCHAR* srv_phb_contact_set_asc_msn(srv_phb_contact contact, const CHAR* msn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    WCHAR* dest_msn = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    dest_msn = srv_phb_contact_get_string_field_data(info, MMI_PHB_CONTACT_FIELD_ID_MSN, MMI_PHB_EMAIL_LENGTH, MMI_TRUE);
    if (dest_msn)
    {
        if (msn)
        {
            mmi_asc_n_to_wcs(dest_msn, (CHAR*)msn, MMI_PHB_EMAIL_LENGTH);
        }
        else
        {
            dest_msn[0] = 0;
        }
    }
    return dest_msn;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_add_number
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_number_struct* srv_phb_contact_add_number(srv_phb_contact contact, const srv_phb_number_struct* number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_number_struct* number_field = NULL;
    srv_phb_number_node_struct* number_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    number_field = (srv_phb_contact_number_struct*)srv_phb_contact_get_link_field(
                                                        info,
                                                        MMI_PHB_CONTACT_FIELD_ID_NUMBER,
                                                        MMI_TRUE);
    if (number_field)
    {
        number_node = (srv_phb_number_node_struct*)srv_phb_contact_node_realloc((srv_phb_link_struct*)number_field);
        if (!number_node)
        {
            number_node = srv_phb_mem_malloc(sizeof(srv_phb_number_node_struct), SRV_PHB_MEMORY_TYPE_ADM);
        }
        srv_phb_contact_add_node_tail((srv_phb_link_struct*)number_field, (srv_phb_node_struct*)number_node);
        if (number)
        {
            srv_phb_contact_copy_number(&(number_node->data), number);
        }
        else
        {
            srv_phb_contact_init_number(&(number_node->data));
        }
        return &(number_node->data);
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_add_number
* DESCRIPTION
*  add a number to contact container
* PARAMETERS
*  contact                    : [IN]  contact container
*  id                         : [IN]  number sub id, new number set as MMI_PHB_SUB_ID_NEW
*  save_index                 : [IN]  number save index, only for AT begin as 0, otherwise set as 0
*  type                       : [IN]  number type, refer mmi_phb_num_type_enum
*  number                     : [IN]  asc number data
*  label                      : [IN]  number field label
*  is_default                 : [IN]  is default number flag
* RETURNS
*  srv_phb_number_struct
*****************************************************************************/
srv_phb_number_struct* srv_phb_contact_add_asc_number(
                                srv_phb_contact contact,
                                mmi_phb_sub_id id,
                                U8 save_index,
                                U8 type,
                                const CHAR* number,
                                const WCHAR* label,
                                MMI_BOOL is_default)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_number_struct* number_field = NULL;
    srv_phb_number_node_struct* number_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    number_field = (srv_phb_contact_number_struct*)srv_phb_contact_get_link_field(
                                                        info,
                                                        MMI_PHB_CONTACT_FIELD_ID_NUMBER,
                                                        MMI_TRUE);
    if (number_field)
    {
        number_node = (srv_phb_number_node_struct*)srv_phb_contact_node_realloc((srv_phb_link_struct*)number_field);
        if (!number_node)
        {
            number_node = srv_phb_mem_malloc(sizeof(srv_phb_number_node_struct), SRV_PHB_MEMORY_TYPE_ADM);
        }
        srv_phb_contact_add_node_tail((srv_phb_link_struct*)number_field, (srv_phb_node_struct*)number_node);
        srv_phb_contact_set_asc_number(&(number_node->data), id, save_index, type, number, label, is_default);
        return &(number_node->data);
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_add_number
* DESCRIPTION
*  add a number to contact container
* PARAMETERS
*  contact                    : [IN]  contact container
*  id                         : [IN]  number sub id, new number set as MMI_PHB_SUB_ID_NEW
*  save_index                 : [IN]  number save index, only for AT begin as 0, otherwise set as 0
*  type                       : [IN]  number type, refer mmi_phb_num_type_enum
*  number                     : [IN]  asc number data
*  label                      : [IN]  number field label
*  is_default                 : [IN]  is default number flag
* RETURNS
*  srv_phb_number_struct
*****************************************************************************/
srv_phb_number_struct* srv_phb_contact_add_asc_number_ex(
                                srv_phb_contact contact,
                                mmi_phb_sub_id id,
                                U8 save_index,
                                U8 type,
                                U8 last_used_sim,
                                const CHAR* number,
                                const WCHAR* label,
                                MMI_BOOL is_default)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_number_struct* number_field = NULL;
    srv_phb_number_node_struct* number_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    number_field = (srv_phb_contact_number_struct*)srv_phb_contact_get_link_field(
                                                        info,
                                                        MMI_PHB_CONTACT_FIELD_ID_NUMBER,
                                                        MMI_TRUE);
    if (number_field)
    {
        number_node = (srv_phb_number_node_struct*)srv_phb_contact_node_realloc((srv_phb_link_struct*)number_field);
        if (!number_node)
        {
            number_node = srv_phb_mem_malloc(sizeof(srv_phb_number_node_struct), SRV_PHB_MEMORY_TYPE_ADM);
        }
        srv_phb_contact_add_node_tail((srv_phb_link_struct*)number_field, (srv_phb_node_struct*)number_node);
        srv_phb_contact_set_asc_number_ex(&(number_node->data), id, save_index, type, last_used_sim, number, label, is_default);
        return &(number_node->data);
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_add_number_ex
* DESCRIPTION
*  add a number to contact container
* PARAMETERS
*  contact                    : [IN]  contact container
*  id                         : [IN]  number sub id, new number set as MMI_PHB_SUB_ID_NEW
*  save_index                 : [IN]  number save index, only for AT, otherwise set as 0
*  type                       : [IN]  number type, refer mmi_phb_num_type_enum
*  number                     : [IN]  wcs number data
*  label                      : [IN]  number field label
*  is_default                 : [IN]  is default number flag
* RETURNS
*  srv_phb_number_struct
*****************************************************************************/
srv_phb_number_struct* srv_phb_contact_add_number_ex(
                                srv_phb_contact contact,
                                mmi_phb_sub_id id,
                                U8 save_index,
                                U8 type,
                                const WCHAR* number,
                                const WCHAR* label,
                                MMI_BOOL is_default)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_number_struct* number_field = NULL;
    srv_phb_number_node_struct* number_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    number_field = (srv_phb_contact_number_struct*)srv_phb_contact_get_link_field(
                                                        info,
                                                        MMI_PHB_CONTACT_FIELD_ID_NUMBER,
                                                        MMI_TRUE);
    if (number_field)
    {
        number_node = (srv_phb_number_node_struct*)srv_phb_contact_node_realloc((srv_phb_link_struct*)number_field);
        if (!number_node)
        {
            number_node = srv_phb_mem_malloc(sizeof(srv_phb_number_node_struct), SRV_PHB_MEMORY_TYPE_ADM);
        }
        srv_phb_contact_add_node_tail((srv_phb_link_struct*)number_field, (srv_phb_node_struct*)number_node);
        srv_phb_contact_set_number(&(number_node->data), id, save_index, type, number, label, is_default);
        return &(number_node->data);
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_find_number
* DESCRIPTION
* 
* PARAMETERS
*  contact    : [IN]  contact infor
*  number    : [IN]  number
*  index       : [OUT] number index in contact
* RETURNS
*  MMI_TRUE  : number exist
*  MMI_FALSE : not found
*****************************************************************************/
MMI_BOOL srv_phb_contact_find_number(srv_phb_contact contact, U16 *number, U32 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 sub_id = 0;
    MMI_BOOL result = MMI_FALSE;
    srv_phb_iterator iter;
    srv_phb_number_struct *query_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    iter = srv_phb_contact_get_number_iterator(contact);
    while (iter && sub_id < MMI_PHB_NUMBER_FIELD_COUNT)
    {
        query_number = srv_phb_contact_get_number_next(&iter);
        if (query_number)
        {
            result = srv_phb_compare_number(query_number->number, number);
            if (result == MMI_TRUE)
            {
                break;
            }
        }
        sub_id++;
    }
    if (index)
    {
        *index = sub_id;  
    }
    return result;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_number_count
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
U16 srv_phb_contact_get_number_count(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_number_struct* number_field = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return 0;
    }
    number_field = (srv_phb_contact_number_struct*)srv_phb_contact_get_link_field(
                                                        info,
                                                        MMI_PHB_CONTACT_FIELD_ID_NUMBER,
                                                        MMI_FALSE);
    if (number_field)
    {
        return number_field->count;
    }
    return 0;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_number_iterator
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_iterator srv_phb_contact_get_number_iterator(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_number_struct* number_field = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return 0;
    }
    number_field = (srv_phb_contact_number_struct*)srv_phb_contact_get_link_field(
                                                        info,
                                                        MMI_PHB_CONTACT_FIELD_ID_NUMBER,
                                                        MMI_FALSE);
    if (number_field && number_field->head)
    {
        return (srv_phb_iterator)(number_field->head);
    }
    return 0;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_number_next
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_number_struct* srv_phb_contact_get_number_next(srv_phb_iterator* iterator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_number_node_struct* node = (srv_phb_number_node_struct*)(*iterator);
    srv_phb_number_struct* number = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (node)
    {
        number = &(node->data);
        *iterator = (srv_phb_iterator)(node->next);
    }
    return number;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_number_by_sub_id
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_number_struct* srv_phb_contact_get_number_by_sub_id(srv_phb_contact contact, mmi_phb_sub_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_number_struct* number_field = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    number_field = (srv_phb_contact_number_struct*)srv_phb_contact_get_link_field(
                                                        info,
                                                        MMI_PHB_CONTACT_FIELD_ID_NUMBER,
                                                        MMI_FALSE);
    if (number_field && number_field->head)
    {
        srv_phb_number_node_struct* node = number_field->head;
        while (node)
        {
            if (node->data.sub_id == id)
            {
                return &(node->data);
            }
            node = node->next;
        }
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_number_by_save_index
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_number_struct* srv_phb_contact_get_number_by_save_index(srv_phb_contact contact, U8 save_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_number_struct* number_field = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    number_field = (srv_phb_contact_number_struct*)srv_phb_contact_get_link_field(
                                                        info,
                                                        MMI_PHB_CONTACT_FIELD_ID_NUMBER,
                                                        MMI_FALSE);
    if (number_field && number_field->head)
    {
        srv_phb_number_node_struct* node = number_field->head;
        while (node)
        {
            if (node->data.index == save_index)
            {
                return &(node->data);
            }
            node = node->next;
        }
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_first_number
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_number_struct* srv_phb_contact_get_first_number(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_number_struct* number_field = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    number_field = (srv_phb_contact_number_struct*)srv_phb_contact_get_link_field(
                                                        info,
                                                        MMI_PHB_CONTACT_FIELD_ID_NUMBER,
                                                        MMI_FALSE);
    if (number_field && number_field->head)
    {
        return &(number_field->head->data);
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_remove_number
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
MMI_BOOL srv_phb_contact_remove_number(srv_phb_contact contact, srv_phb_number_struct* number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_number_struct* number_field = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return MMI_FALSE;
    }
    number_field = (srv_phb_contact_number_struct*)srv_phb_contact_get_link_field(
                                                        info,
                                                        MMI_PHB_CONTACT_FIELD_ID_NUMBER,
                                                        MMI_FALSE);
    if (number_field && number_field->head)
    {
        srv_phb_number_node_struct* prev = NULL;
        srv_phb_number_node_struct* node = number_field->head;
        while (node)
        {
            if (&(node->data) == number)
            {
                srv_phb_contact_node_remove(
                        (srv_phb_link_struct*)number_field,
                        (srv_phb_node_struct*)prev,
                        (srv_phb_node_struct*)node);
                return MMI_TRUE;
            }
            prev = node;
            node = node->next;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_add_email
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_email_struct* srv_phb_contact_add_email(srv_phb_contact contact, const srv_phb_email_struct* email)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_email_struct* email_field = NULL;
    srv_phb_email_node_struct* email_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    email_field = (srv_phb_contact_email_struct*)srv_phb_contact_get_link_field(info, MMI_PHB_CONTACT_FIELD_ID_EMAIL, MMI_TRUE);
    if (email_field)
    {
        email_node = (srv_phb_email_node_struct*)srv_phb_contact_node_realloc((srv_phb_link_struct*)email_field);
        if (!email_node)
        {
            email_node = srv_phb_mem_malloc(sizeof(srv_phb_email_node_struct), SRV_PHB_MEMORY_TYPE_ADM);
        }
        srv_phb_contact_add_node_tail((srv_phb_link_struct*)email_field, (srv_phb_node_struct*)email_node);
        if (email)
        {
            srv_phb_contact_copy_email(&(email_node->data), email);
        }
        else
        {
            srv_phb_contact_init_email(&(email_node->data));
        }
        return &(email_node->data);
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_add_asc_email
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_email_struct* srv_phb_contact_add_asc_email(srv_phb_contact contact, mmi_phb_sub_id id, U8 save_index, U8 type, const CHAR* email, const WCHAR* label)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_email_struct* email_field = NULL;
    srv_phb_email_node_struct* email_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    email_field = (srv_phb_contact_email_struct*)srv_phb_contact_get_link_field(info, MMI_PHB_CONTACT_FIELD_ID_EMAIL, MMI_TRUE);
    if (email_field)
    {
        email_node = (srv_phb_email_node_struct*)srv_phb_contact_node_realloc((srv_phb_link_struct*)email_field);
        if (!email_node)
        {
            email_node = srv_phb_mem_malloc(sizeof(srv_phb_email_node_struct), SRV_PHB_MEMORY_TYPE_ADM);
        }
        srv_phb_contact_add_node_tail((srv_phb_link_struct*)email_field, (srv_phb_node_struct*)email_node);
        srv_phb_contact_set_asc_email(&(email_node->data), id, save_index, type, email, label);
        return &(email_node->data);
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_add_email_ex
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_email_struct* srv_phb_contact_add_email_ex(srv_phb_contact contact, mmi_phb_sub_id id, U8 save_index, U8 type, const WCHAR* email, const WCHAR* label)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_email_struct* email_field = NULL;
    srv_phb_email_node_struct* email_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    email_field = (srv_phb_contact_email_struct*)srv_phb_contact_get_link_field(info, MMI_PHB_CONTACT_FIELD_ID_EMAIL, MMI_TRUE);
    if (email_field)
    {
        email_node = (srv_phb_email_node_struct*)srv_phb_contact_node_realloc((srv_phb_link_struct*)email_field);
        if (!email_node)
        {
            email_node = srv_phb_mem_malloc(sizeof(srv_phb_email_node_struct), SRV_PHB_MEMORY_TYPE_ADM);
        }
        srv_phb_contact_add_node_tail((srv_phb_link_struct*)email_field, (srv_phb_node_struct*)email_node);
        srv_phb_contact_set_email(&(email_node->data), id, save_index, type, email, label);
        return &(email_node->data);
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_email_count
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
U16 srv_phb_contact_get_email_count(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_email_struct* email_field = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return 0;
    }
    email_field = (srv_phb_contact_email_struct*)srv_phb_contact_get_link_field(info, MMI_PHB_CONTACT_FIELD_ID_EMAIL, MMI_FALSE);
    if (email_field)
    {
        return email_field->count;
    }
    return 0;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_email_iterator
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_iterator srv_phb_contact_get_email_iterator(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_email_struct* email_field = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return 0;
    }
    email_field = (srv_phb_contact_email_struct*)srv_phb_contact_get_link_field(info, MMI_PHB_CONTACT_FIELD_ID_EMAIL, MMI_FALSE);
    if (email_field && email_field->head)
    {
        return (srv_phb_iterator)(email_field->head);
    }
    return 0;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_email_next
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_email_struct* srv_phb_contact_get_email_next(srv_phb_iterator* iterator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_email_node_struct* node = (srv_phb_email_node_struct*)(*iterator);
    srv_phb_email_struct* email = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (node)
    {
        email = &(node->data);
        *iterator = (srv_phb_iterator)(node->next);
    }
    return email;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_email_by_sub_id
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_email_struct* srv_phb_contact_get_email_by_sub_id(srv_phb_contact contact, mmi_phb_sub_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_email_struct* email_field = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    email_field = (srv_phb_contact_email_struct*)srv_phb_contact_get_link_field(info, MMI_PHB_CONTACT_FIELD_ID_EMAIL, MMI_FALSE);
    if (email_field && email_field->head)
    {
        srv_phb_email_node_struct* node = email_field->head;
        while (node)
        {
            if (node->data.sub_id == id)
            {
                return &(node->data);
            }
            node = node->next;
        }
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_email_by_save_index
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_email_struct* srv_phb_contact_get_email_by_save_index(srv_phb_contact contact, U8 save_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_email_struct* email_field = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    email_field = (srv_phb_contact_email_struct*)srv_phb_contact_get_link_field(info, MMI_PHB_CONTACT_FIELD_ID_EMAIL, MMI_FALSE);
    if (email_field && email_field->head)
    {
        srv_phb_email_node_struct* node = email_field->head;
        while (node)
        {
            if (node->data.index == save_index)
            {
                return &(node->data);
            }
            node = node->next;
        }
    }
    return NULL;
}

/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_first_email
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_email_struct* srv_phb_contact_get_first_email(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_email_struct* email_field = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    email_field = (srv_phb_contact_email_struct*)srv_phb_contact_get_link_field(info, MMI_PHB_CONTACT_FIELD_ID_EMAIL, MMI_FALSE);
    if (email_field && email_field->head)
    {
        return &(email_field->head->data);
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_remove_email
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
MMI_BOOL srv_phb_contact_remove_email(srv_phb_contact contact, srv_phb_email_struct* email)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_email_struct* email_field = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return MMI_FALSE;
    }
    email_field = (srv_phb_contact_email_struct*)srv_phb_contact_get_link_field(
                                                        info,
                                                        MMI_PHB_CONTACT_FIELD_ID_EMAIL,
                                                        MMI_FALSE);
    if (email_field && email_field->head)
    {
        srv_phb_email_node_struct* prev = NULL;
        srv_phb_email_node_struct* node = email_field->head;
        while (node)
        {
            if (&(node->data) == email)
            {
                srv_phb_contact_node_remove(
                        (srv_phb_link_struct*)email_field,
                        (srv_phb_node_struct*)prev,
                        (srv_phb_node_struct*)node);
                return MMI_TRUE;
            }
            prev = node;
            node = node->next;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_add_address
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_address_struct* srv_phb_contact_add_address(srv_phb_contact contact, const srv_phb_address_struct* address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_address_struct* address_field = NULL;
    srv_phb_address_node_struct* address_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    address_field =
        (srv_phb_contact_address_struct*)srv_phb_contact_get_link_field(info, MMI_PHB_CONTACT_FIELD_ID_ADDRESS, MMI_TRUE);
    if (address_field)
    {
        address_node = (srv_phb_address_node_struct*)srv_phb_contact_node_realloc((srv_phb_link_struct*)address_field);
        if (!address_node)
        {
            address_node = srv_phb_mem_malloc(sizeof(srv_phb_address_node_struct), SRV_PHB_MEMORY_TYPE_ADM);
        }
        srv_phb_contact_add_node_tail((srv_phb_link_struct*)address_field, (srv_phb_node_struct*)address_node);
        if (address)
        {
            srv_phb_contact_copy_address(&(address_node->data), address);
        }
        else
        {
            srv_phb_contact_init_address(&(address_node->data));
        }
        return &(address_node->data);
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_add_address_ex
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_address_struct* srv_phb_contact_add_address_ex(srv_phb_contact contact, mmi_phb_sub_id id, U8 type, const mmi_phb_address_struct* address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_address_struct* address_field = NULL;
    srv_phb_address_node_struct* address_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    address_field =
        (srv_phb_contact_address_struct*)srv_phb_contact_get_link_field(info, MMI_PHB_CONTACT_FIELD_ID_ADDRESS, MMI_TRUE);
    if (address_field)
    {
        address_node = (srv_phb_address_node_struct*)srv_phb_contact_node_realloc((srv_phb_link_struct*)address_field);
        if (!address_node)
        {
            address_node = srv_phb_mem_malloc(sizeof(srv_phb_address_node_struct), SRV_PHB_MEMORY_TYPE_ADM);
        }
        srv_phb_contact_add_node_tail((srv_phb_link_struct*)address_field, (srv_phb_node_struct*)address_node);
        srv_phb_contact_set_address(&(address_node->data), id, type, address);
        return &(address_node->data);
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_address_count
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
U16 srv_phb_contact_get_address_count(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_address_struct* address_field = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return 0;
    }
    address_field =
        (srv_phb_contact_address_struct*)srv_phb_contact_get_link_field(info, MMI_PHB_CONTACT_FIELD_ID_ADDRESS, MMI_FALSE);
    if (address_field)
    {
        return address_field->count;
    }
    return 0;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_address_iterator
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_iterator srv_phb_contact_get_address_iterator(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_address_struct* address_field = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return 0;
    }
    address_field =
        (srv_phb_contact_address_struct*)srv_phb_contact_get_link_field(info, MMI_PHB_CONTACT_FIELD_ID_ADDRESS, MMI_FALSE);
    if (address_field && address_field->head)
    {
        return (srv_phb_iterator)(address_field->head);
    }
    return 0;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_address_next
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_address_struct* srv_phb_contact_get_address_next(srv_phb_iterator* iterator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_address_node_struct* node = (srv_phb_address_node_struct*)(*iterator);
    srv_phb_address_struct* address = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (node)
    {
        address = &(node->data);
        *iterator = (srv_phb_iterator)(node->next);
    }
    return address;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_address_by_sub_id
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_address_struct* srv_phb_contact_get_address_by_sub_id(srv_phb_contact contact, mmi_phb_sub_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_address_struct* address_field = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    address_field =
        (srv_phb_contact_address_struct*)srv_phb_contact_get_link_field(info, MMI_PHB_CONTACT_FIELD_ID_ADDRESS, MMI_FALSE);
    if (address_field && address_field->head)
    {
        srv_phb_address_node_struct* node = address_field->head;
        while (node)
        {
            if (node->data.sub_id == id)
            {
                return &(node->data);
            }
            node = node->next;
        }
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_add_url
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_url_struct* srv_phb_contact_add_url(srv_phb_contact contact, const srv_phb_url_struct* url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_url_struct* url_field = NULL;
    srv_phb_url_node_struct* url_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    url_field = (srv_phb_contact_url_struct*)srv_phb_contact_get_link_field(info, MMI_PHB_CONTACT_FIELD_ID_URL, MMI_TRUE);
    if (url_field)
    {
        url_node = (srv_phb_url_node_struct*)srv_phb_contact_node_realloc((srv_phb_link_struct*)url_field);
        if (!url_node)
        {
            url_node = srv_phb_mem_malloc(sizeof(srv_phb_url_node_struct), SRV_PHB_MEMORY_TYPE_ADM);
        }
        srv_phb_contact_add_node_tail((srv_phb_link_struct*)url_field, (srv_phb_node_struct*)url_node);
        if (url)
        {
            srv_phb_contact_copy_url(&(url_node->data), url);
        }
        else
        {
            srv_phb_contact_init_url(&(url_node->data));
        }
        return &(url_node->data);
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_add_url_ex
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_url_struct* srv_phb_contact_add_url_ex(srv_phb_contact contact, mmi_phb_sub_id id, U8 type, const WCHAR* url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_url_struct* url_field = NULL;
    srv_phb_url_node_struct* url_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    url_field = (srv_phb_contact_url_struct*)srv_phb_contact_get_link_field(info, MMI_PHB_CONTACT_FIELD_ID_URL, MMI_TRUE);
    if (url_field)
    {
        url_node = (srv_phb_url_node_struct*)srv_phb_contact_node_realloc((srv_phb_link_struct*)url_field);
        if (!url_node)
        {
            url_node = srv_phb_mem_malloc(sizeof(srv_phb_url_node_struct), SRV_PHB_MEMORY_TYPE_ADM);
        }
        srv_phb_contact_add_node_tail((srv_phb_link_struct*)url_field, (srv_phb_node_struct*)url_node);
        srv_phb_contact_set_url(&(url_node->data), id, type, url);
        return &(url_node->data);
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_add_url_ex
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_url_struct* srv_phb_contact_add_asc_url(srv_phb_contact contact, mmi_phb_sub_id id, U8 type, const CHAR* url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_url_struct* url_field = NULL;
    srv_phb_url_node_struct* url_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    url_field = (srv_phb_contact_url_struct*)srv_phb_contact_get_link_field(info, MMI_PHB_CONTACT_FIELD_ID_URL, MMI_TRUE);
    if (url_field)
    {
        url_node = (srv_phb_url_node_struct*)srv_phb_contact_node_realloc((srv_phb_link_struct*)url_field);
        if (!url_node)
        {
            url_node = srv_phb_mem_malloc(sizeof(srv_phb_url_node_struct), SRV_PHB_MEMORY_TYPE_ADM);
        }
        srv_phb_contact_add_node_tail((srv_phb_link_struct*)url_field, (srv_phb_node_struct*)url_node);
        srv_phb_contact_set_asc_url(&(url_node->data), id, type, url);
        return &(url_node->data);
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_url_count
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
U16 srv_phb_contact_get_url_count(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_url_struct* url_field = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return 0;
    }
    url_field = (srv_phb_contact_url_struct*)srv_phb_contact_get_link_field(info, MMI_PHB_CONTACT_FIELD_ID_URL, MMI_FALSE);
    if (url_field)
    {
        return url_field->count;
    }
    return 0;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_url_iterator
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_iterator srv_phb_contact_get_url_iterator(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_url_struct* url_field = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return 0;
    }
    url_field = (srv_phb_contact_url_struct*)srv_phb_contact_get_link_field(info, MMI_PHB_CONTACT_FIELD_ID_URL, MMI_FALSE);
    if (url_field && url_field->head)
    {
        return (srv_phb_iterator)(url_field->head);
    }
    return 0;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_url_next
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_url_struct* srv_phb_contact_get_url_next(srv_phb_iterator* iterator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_url_node_struct* node = (srv_phb_url_node_struct*)(*iterator);
    srv_phb_url_struct* url = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (node)
    {
        url = &(node->data);
        *iterator = (srv_phb_iterator)(node->next);
    }
    return url;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_url_by_sub_id
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_url_struct* srv_phb_contact_get_url_by_sub_id(srv_phb_contact contact, mmi_phb_sub_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_url_struct* url_field = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    url_field = (srv_phb_contact_url_struct*)srv_phb_contact_get_link_field(info, MMI_PHB_CONTACT_FIELD_ID_URL, MMI_FALSE);
    if (url_field && url_field->head)
    {
        srv_phb_url_node_struct* node = url_field->head;
        while (node)
        {
            if (node->data.sub_id == id)
            {
                return &(node->data);
            }
            node = node->next;
        }
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_add_note
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_note_struct* srv_phb_contact_add_note(srv_phb_contact contact, const srv_phb_note_struct* note)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_note_struct* note_field = NULL;
    srv_phb_note_node_struct* note_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    note_field = (srv_phb_contact_note_struct*)srv_phb_contact_get_link_field(info, MMI_PHB_CONTACT_FIELD_ID_NOTE, MMI_TRUE);
    if (note_field)
    {
        note_node = (srv_phb_note_node_struct*)srv_phb_contact_node_realloc((srv_phb_link_struct*)note_field);
        if (!note_node)
        {
            note_node = srv_phb_mem_malloc(sizeof(srv_phb_note_node_struct), SRV_PHB_MEMORY_TYPE_ADM);
        }
        srv_phb_contact_add_node_tail((srv_phb_link_struct*)note_field, (srv_phb_node_struct*)note_node);
        if (note)
        {
            srv_phb_contact_copy_note(&(note_node->data), note);
        }
        else
        {
            srv_phb_contact_init_note(&(note_node->data));
        }
        return &(note_node->data);
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_add_note_ex
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_note_struct* srv_phb_contact_add_note_ex(srv_phb_contact contact, mmi_phb_sub_id id, U8 type, const WCHAR* note)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_note_struct* note_field = NULL;
    srv_phb_note_node_struct* note_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    note_field = (srv_phb_contact_note_struct*)srv_phb_contact_get_link_field(info, MMI_PHB_CONTACT_FIELD_ID_NOTE, MMI_TRUE);
    if (note_field)
    {
        note_node = (srv_phb_note_node_struct*)srv_phb_contact_node_realloc((srv_phb_link_struct*)note_field);
        if (!note_node)
        {
            note_node = srv_phb_mem_malloc(sizeof(srv_phb_note_node_struct), SRV_PHB_MEMORY_TYPE_ADM);
        }
        srv_phb_contact_add_node_tail((srv_phb_link_struct*)note_field, (srv_phb_node_struct*)note_node);
        srv_phb_contact_set_note(&(note_node->data), id, type, note);
        return &(note_node->data);
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_note_count
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
U16 srv_phb_contact_get_note_count(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_note_struct* note_field = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return 0;
    }
    note_field = (srv_phb_contact_note_struct*)srv_phb_contact_get_link_field(info, MMI_PHB_CONTACT_FIELD_ID_NOTE, MMI_FALSE);
    if (note_field)
    {
        return note_field->count;
    }
    return 0;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_note_iterator
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_iterator srv_phb_contact_get_note_iterator(srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_note_struct* note_field = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return 0;
    }
    note_field = (srv_phb_contact_note_struct*)srv_phb_contact_get_link_field(info, MMI_PHB_CONTACT_FIELD_ID_NOTE, MMI_FALSE);
    if (note_field && note_field->head)
    {
        return (srv_phb_iterator)(note_field->head);
    }
    return 0;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_note_next
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_note_struct* srv_phb_contact_get_note_next(srv_phb_iterator* iterator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_note_node_struct* node = (srv_phb_note_node_struct*)(*iterator);
    srv_phb_note_struct* note = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (node)
    {
        note = &(node->data);
        *iterator = (srv_phb_iterator)(node->next);
    }
    return note;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_contact_get_note_by_sub_id
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
srv_phb_note_struct* srv_phb_contact_get_note_by_sub_id(srv_phb_contact contact, mmi_phb_sub_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_struct* info = contact;
    srv_phb_contact_note_struct* note_field = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return NULL;
    }
    note_field = (srv_phb_contact_note_struct*)srv_phb_contact_get_link_field(info, MMI_PHB_CONTACT_FIELD_ID_NOTE, MMI_FALSE);
    if (note_field && note_field->head)
    {
        srv_phb_note_node_struct* node = note_field->head;
        while (node)
        {
            if (node->data.sub_id == id)
            {
                return &(node->data);
            }
            node = node->next;
        }
    }
    return NULL;
}

#endif /* PHBCONTACTSRV_C */

