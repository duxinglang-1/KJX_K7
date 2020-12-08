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
 *  vcui_phb_gprot.h
 *
 * Project:
 * --------
 *  Venus
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifndef __PB_CUI_GPROT_H__
#define __PB_CUI_GPROT_H__

#include "MMIDataType.h"
#include "vapp_phb_gprot.h "

#ifdef __cplusplus
extern "C"
{
#endif

#include "PhbSrvGprot.h"

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C"
{
#endif

/* cui event id */
typedef enum
{
    EVT_ID_CUI_PHB_LIST_RESULT = VCUI_CONTACT_LIST + 1,  /* cui list event */
    
    EVT_ID_CUI_PHB_SAVE_RESULT = VCUI_CONTACT_SAVE + 1,  /* cui saver event */

    EVT_ID_CUI_PHB_SAVE_ENTERED = VCUI_CONTACT_SAVE + 2, /* cui saver entered, may send many time */

    EVT_ID_CUI_PHB_VIEW_RESULT = VCUI_CONTACT_VIEW + 1,  /* cui viewer event */

    EVT_ID_CUI_PHB_VIEW_ENTERED = VCUI_CONTACT_VIEW + 2, /* cui viewer entered, may send many time */

    EVT_ID_CUI_SIM_LOCATE_RESULT = VCUI_SIM_LOCATE + 1,  /* cui locator event */

	EVT_ID_CUI_PHB_SETTING_RESULT = VCUI_CONTACT_SETTING + 1,
    
    EVT_ID_CUI_PHB_TOTAL                                 /* enum tail */
} cui_phb_event_enum;


/* cui list style */
typedef enum
{
    VAPP_PHB_LIST_SINGLE_SELECTOR,                      /* select one contact */

    VAPP_PHB_LIST_GROUP_SINGLE_SELECTOR,                /* select one contact, support group list */

    VAPP_PHB_LIST_MULTI_SELECTOR,                       /* select some contacts */

    VAPP_PHB_LIST_GROUP_MULTI_SELECTOR,                 /* select some contacts, support group list */

    VAPP_PHB_LIST_SELECTOR_TYPE_TOTAL                   /* enum tail */
} vcui_phb_list_type_enum;


/* cui saver style */
typedef enum
{
    VAPP_PHB_SAVE_CONTACT_DEFAULT,                      /* = new + replace */

    VAPP_PHB_SAVE_CONTACT_NEW,                          /* new a contact */

    VAPP_PHB_SAVE_CONTACT_EDIT,                         /* edit a exist contact */

    VAPP_PHB_SAVE_CONTACT_REPLACE,                      /* use the data replace a exist contact */

    VAPP_PHB_SAVE_CONTACT_TOTAL                         /* enum tail */
} vcui_phb_save_contact_type_enum;


/* cui viewer sub-app type */
typedef enum
{
    VAPP_PHB_VIEWER_PROFILE = 1,                        /* contact */

    VAPP_PHB_VIEWER_CLOG,                               /* call log */

    VAPP_PHB_VIEWER_MSG,                                /* message */

    VAPP_PHB_VIEWER_SNS,                                /* sns */

    VAPP_PHB_VIEWER_TYPE_TOTAL                          /* enum tail */
} vcui_phb_viewer_type_enum;


/* cui list event struct */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER

    S32 result;                                         /* success or not */

    U32 select_count;                                   /* selected count */
} vcui_phb_list_result_event_struct;


/* cui saver event struct */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER

    S32 result;                                         /* success or not */

    mmi_phb_contact_id id;                              /* contact id */
} vcui_phb_contact_save_result_event_struct;


/* cui viewer event struct */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER

    S32 result;                                         /* success or not */
} vcui_phb_contact_viewer_result_event_struct;


/* cui locator event struct */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER

    S32 result;                                         /* success or not */
} vcui_phb_sim_locator_result_event_struct;


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_list_create
 * DESCRIPTION
 *  contact list cui: create
 * PARAMETERS
 *  parent_id           :           [IN]        caller id/parent id
 * RETURNS
 *  void
 *****************************************************************************/
mmi_id vcui_phb_list_create(mmi_id parent_id);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_list_set_user_data
 * DESCRIPTION
 *  contact list cui: set user data
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 *  user_data           :           [IN]        user data
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_list_set_user_data(mmi_id cui_id, U32 user_data);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_list_get_user_data
 * DESCRIPTION
 *  contact list cui: get user data
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 * RETURNS
 *  U32                 :           [OUT]       user data
 *****************************************************************************/
U32 vcui_phb_list_get_user_data(mmi_id cui_id);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_list_set_req_type
 * DESCRIPTION
 *  contact list cui: set request list type
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 *  list_type           :           [IN]        request list type
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_list_set_req_type(mmi_id cui_id, vcui_phb_list_type_enum list_type);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_list_set_req_field
 * DESCRIPTION
 *  contact list cui: set request field
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 *  field_mask          :           [IN]        contact field mask, please check phb service for detail
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_list_set_req_field(mmi_id cui_id, U32 field_mask);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_list_set_req_count
 * DESCRIPTION
 *  contact list cui: set request count
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 *  req_count           :           [IN]        request contact count
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_list_set_req_count(mmi_id cui_id, U32 req_count);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_list_set_drag_ncenter_flag
 * DESCRIPTION
 *  contact list cui: set drag ncenter flag
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 *  is_drag           :           [IN]        is ncenter drag
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_list_set_drag_ncenter_flag(mmi_id cui_id, MMI_BOOL is_drag);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_list_set_group
 * DESCRIPTION
 *  contact list cui: set list source group
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 *  groupId             :           [IN]        group id
 *  thisGroup           :           [IN]        VFX_TRUE: contacts from this group, VFX_FALSE: all other contacts
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_list_set_group(mmi_id cui_id, U32 groupId, MMI_BOOL thisGroup);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_list_set_storage
 * DESCRIPTION
 *  contact list cui: set list source storage mask
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 *  storageMask         :           [IN]        storage mask
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_list_set_storage(mmi_id cui_id, U32 storageMask);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_list_set_title_str
 * DESCRIPTION
 *  contact list cui: set list title string
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 *  str_id              :           [IN]        title string
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_list_set_title_str(mmi_id cui_id, U32 str_id);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_list_get_selected_count
 * DESCRIPTION
 *  contact list cui: get selected count
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 * RETURNS
 *  U32                 :           [OUT]       selected contact count
 *****************************************************************************/
U32 vcui_phb_list_get_selected_count(mmi_id cui_id);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_list_get_contact_id
 * DESCRIPTION
 *  contact list cui: get selected contact id
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 * RETURNS
 *  mmi_phb_contact_id  :           [OUT]       contact id
 *****************************************************************************/
mmi_phb_contact_id vcui_phb_list_get_contact_id(mmi_id cui_id);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_list_get_contact_id_by_index
 * DESCRIPTION
 *  contact list cui: get selected contact id by index
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 *  index               :           [IN]        selected contact index
 * RETURNS
 *  mmi_phb_contact_id  :           [OUT]       contact id
 *****************************************************************************/
mmi_phb_contact_id vcui_phb_list_get_contact_id_by_index(mmi_id cui_id, U16 index);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_list_get_selected_contact_name
 * DESCRIPTION
 *  contact list cui: get selected contact's name
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 *  buf                 :           [IN]        data buf
 *  length              :           [IN]        buf length(WCHAR)
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_list_get_selected_contact_name(mmi_id cui_id, WCHAR* buf, U16 length);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_list_get_selected_contact_name_by_index
 * DESCRIPTION
 *  contact list cui: get selected contact's name by index
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 *  buf                 :           [IN]        data buf
 *  length              :           [IN]        buf length(WCHAR)
 *  index               :           [IN]        selected contact index
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_list_get_selected_contact_name_by_index(mmi_id cui_id, WCHAR* buf, U16 length, U16 index);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_list_get_selected_contact_data
 * DESCRIPTION
 *  contact list cui: get selected contact data
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 *  buf                 :           [IN]        data buf
 *  length              :           [IN]        buf length(WCHAR)
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_list_get_selected_contact_data(mmi_id cui_id, WCHAR* buf, U16 length);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_list_get_selected_contact_data_by_index
 * DESCRIPTION
 *  contact list cui: get selected contact data by index
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 *  buf                 :           [IN]        data buf
 *  length              :           [IN]        buf length(WCHAR)
 *  index               :           [IN]        selected contact index
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_list_get_selected_contact_data_by_index(mmi_id cui_id, WCHAR* buf, U16 length, U16 index);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_list_get_selected_contact_data_type
 * DESCRIPTION
 *  contact list cui: get selected contact data type
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 *  type                :           [OUT]       data type
 *  sub_type            :           [OUT]       data sub_type
 *  sub_id              :           [OUT]       data sub_id        
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_list_get_selected_contact_data_type(mmi_id cui_id, U32 *type, U32 *sub_type, U32 *sub_id);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_list_get_selected_contact_data_type_by_index
 * DESCRIPTION
 *  contact list cui: get selected contact data type by index
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 *  type                :           [OUT]       data type
 *  sub_type            :           [OUT]       data sub_type
 *  sub_id              :           [OUT]       data sub_id        
 *  index               :           [IN]        selected contact index
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_list_get_selected_contact_data_type_by_index(mmi_id cui_id, U32 *type, U32 *sub_type, U32 *sub_id, U16 index);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_list_run
 * DESCRIPTION
 *  contact list cui: run
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_list_run(mmi_id cui_id);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_list_close
 * DESCRIPTION
 *  contact list cui: close
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_list_close(mmi_id cui_id);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_contact_saver_create
 * DESCRIPTION
 *  contact saver cui: create
 * PARAMETERS
 *  parent_id           :           [IN]        caller id/parent id
 * RETURNS
 *  mmi_id              :           [OUT]       cui_id
 *****************************************************************************/
mmi_id vcui_phb_contact_saver_create(mmi_id parent_id);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_contact_saver_create2
 * DESCRIPTION
 *  contact saver cui: create (contact internal use)
 * PARAMETERS
 *  parent_id           :           [IN]        caller id/parent id
 * RETURNS
 *  mmi_id              :           [OUT]       cui_id
 *****************************************************************************/
mmi_id vcui_phb_contact_saver_create2(mmi_id parent_id);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_contact_saver_set_user_data
 * DESCRIPTION
 *  contact saver cui: set user data
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 *  user_data           :           [IN]        user data
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_contact_saver_set_user_data(mmi_id cui_id, U32 user_data);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_contact_saver_get_user_data
 * DESCRIPTION
 *  contact saver cui: get user data
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 * RETURNS
 *  U32                 :           [OUT]       user data
 *****************************************************************************/
U32 vcui_phb_contact_saver_get_user_data(mmi_id cui_id);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_contact_saver_set_type
 * DESCRIPTION
 *  contact saver cui: set saver type
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 *  type                :           [IN]        saver type
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_contact_saver_set_type(mmi_id cui_id, vcui_phb_save_contact_type_enum type);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_contact_saver_set_contact_id
 * DESCRIPTION
 *  contact saver cui: set contact id
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 *  id                  :           [IN]        contact id
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_contact_saver_set_contact_id(mmi_id cui_id, mmi_phb_contact_id id);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_contact_saver_set_name
 * DESCRIPTION
 *  contact saver cui: set name
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 *  name                :           [IN]        input name
 *  length              :           [IN]        input name length
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_contact_saver_set_name(mmi_id cui_id, WCHAR* name, U32 length);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_contact_saver_set_number
 * DESCRIPTION
 *  contact saver cui: set number
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 *  number              :           [IN]        input number
 *  length              :           [IN]        input number length
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_contact_saver_set_number(mmi_id cui_id, WCHAR* number, U32 length);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_contact_saver_set_email
 * DESCRIPTION
 *  contact saver cui: set email
 * PARAMETERS
 *  cui_id          :           [IN]        cui_id
 *  email           :           [IN]        email address
 *  length          :           [IN]        email length
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_contact_saver_set_email(mmi_id cui_id, WCHAR* email, U32 length);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_contact_saver_set_image
 * DESCRIPTION
 *  contact saver cui: set image
 * PARAMETERS
 *  cui_id          :           [IN]        cui_id
 *  path            :           [IN]        image path
 *  length          :           [IN]        path length
 *  id              :           [IN]        image id, if it is global
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_contact_saver_set_image(mmi_id cui_id, WCHAR* path, U32 length, U32 id);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_contact_saver_run
 * DESCRIPTION
 *  contact saver cui: run
 * PARAMETERS
 *  cui_id          :           [IN]        cui_id
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_contact_saver_run(mmi_id cui_id);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_contact_saver_close
 * DESCRIPTION
 *  contact saver cui: close
 * PARAMETERS
 *  cui_id          :           [IN]        cui_id
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_contact_saver_close(mmi_id cui_id);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_contact_viewer_create
 * DESCRIPTION
 *  contact viewer cui: create
 * PARAMETERS
 *  parent_id       :           [IN]        caller id/parent id
 * RETURNS
 *  mmi_id          :           [OUT]       cui_id
 *****************************************************************************/
mmi_id vcui_phb_contact_viewer_create(mmi_id parent_id);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_contact_viewer_set_contact_id
 * DESCRIPTION
 *  contact viewer cui: set contact id
 * PARAMETERS
 *  cui_id          :           [IN]        cui_id
 *  id              :           [IN]        contact id
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_contact_viewer_set_contact_id(mmi_id cui_id, mmi_phb_contact_id id);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_contact_viewer_set_sub_app
 * DESCRIPTION
 *  contact viewer cui: set sub-app type
 * PARAMETERS
 *  cui_id          :           [IN]        cui_id
 *  type            :           [IN]        sub-app type
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_contact_viewer_set_sub_app(mmi_id cui_id, vcui_phb_viewer_type_enum type);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_contact_viewer_set_user_data
 * DESCRIPTION
 *  contact viewer cui: set user data
 * PARAMETERS
 *  cui_id          :           [IN]        cui_id
 *  type            :           [IN]        sub-app type
 *  user_data       :           [IN]        user data
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_contact_viewer_set_user_data(mmi_id cui_id, vcui_phb_viewer_type_enum type, void* user_data);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_contact_viewer_get_user_data
 * DESCRIPTION
 *  contact viewer cui: get user data
 * PARAMETERS
 *  cui_id          :           [IN]        cui_id
 *  type            :           [IN]        sub-app type
 * RETURNS
 *  void*           :           [OUT]       user data pointer
 *****************************************************************************/
void* vcui_phb_contact_viewer_get_user_data(mmi_id cui_id, vcui_phb_viewer_type_enum type);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_contact_viewer_run
 * DESCRIPTION
 *  contact viewer cui: run
 * PARAMETERS
 *  cui_id          :           [IN]        cui id
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_contact_viewer_run(mmi_id cui_id);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_contact_viewer_close
 * DESCRIPTION
 *  contact viewer cui: close
 * PARAMETERS
 *  cui_id          :           [IN]        cui id
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_contact_viewer_close(mmi_id cui_id);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_sim_locator_create
 * DESCRIPTION
 *  sim locator cui: create
 * PARAMETERS
 *  parent_id       :           [IN]        caller id/parent id
 *  index           :           [IN]        record index
 * RETURNS
 *  mmi_id          :           [OUT]       cui_id
 *****************************************************************************/
mmi_id vcui_phb_sim_locator_create(mmi_id parent_id, U16 index);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_sim_locator_run
 * DESCRIPTION
 *  sim locator cui: run
 * PARAMETERS
 *  cui_id          :           [IN]        cui id
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_sim_locator_run(mmi_id cui_id);


/*****************************************************************************
 * FUNCTION
 *  vcui_phb_sim_locator_close
 * DESCRIPTION
 *  sim locator cui: close
 * PARAMETERS
 *  cui_id          :           [IN]        cui id
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_phb_sim_locator_close(mmi_id cui_id);


/*****************************************************************************
 * FUNCTION
 *  vcui_vcard_create
 * DESCRIPTION
 *  vcard cui: create
 * PARAMETERS
 *  parent_id       :           [IN]        caller id/parent id
 * RETURNS
 *  mmi_id          :           [OUT]       cui_id
 *****************************************************************************/
mmi_id vcui_vcard_create(mmi_id parent_id);


/*****************************************************************************
 * FUNCTION
 *  vcui_vcard_run
 * DESCRIPTION
 *  vcard cui: run
 * PARAMETERS
 *  cui_id          :           [IN]        cui id
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_vcard_run(mmi_id cui_id);


/*****************************************************************************
 * FUNCTION
 *  vcui_vcard_close
 * DESCRIPTION
 *  vcard cui: close
 * PARAMETERS
 *  cui_id          :           [IN]        cui id
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_vcard_close(mmi_id cui_id);


/*****************************************************************************
 * FUNCTION
 *  vcui_vcard_set_path
 * DESCRIPTION
 *  vcard cui: set path
 * PARAMETERS
 *  cui_id          :           [IN]        cui id
 *  path            :           [IN]        path
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_vcard_set_path(mmi_id cui_id, const WCHAR *path);


/*****************************************************************************
 * FUNCTION
 *  vcui_vcard_set_content
 * DESCRIPTION
 *  vcard cui: set content
 * PARAMETERS
 *  cui_id          :           [IN]        cui id
 *  content         :           [IN]        content
 *  length          :           [IN]        length
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_vcard_set_content(mmi_id cui_id, void *content, U32 length);
#ifdef __MMI_PHB_NEED_SERIALZE__
extern "C" void vapp_phb_open_uc_cui(void *arg, VfxU32 argSize);
extern "C" mmi_ret vapp_phb_proxy_proc(mmi_event_struct *evt);
#endif


typedef enum
{
    PHB_CUI_NONE,
    PHB_CUI_UC_MESSAGE,
    PHB_CUI_TOTAL_NUM
}VappPhbCuiTypeEnum;

#ifdef __cplusplus
}
#endif

#endif /* __PB_CUI_GPROT_H__ */

