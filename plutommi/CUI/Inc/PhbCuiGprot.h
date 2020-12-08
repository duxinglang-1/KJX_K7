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
 * PhbCuiGprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is to provide CUI 
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef _PHB_CUI_GPROT_H
#define _PHB_CUI_GPROT_H

#if !defined(__COSMOS_MMI_PACKAGE__)

#include "MMIDataType.h"
#include "PhoneBookGprot.h"
#include "PhbSrvGprot.h"

/* auto add by kw_check begin */
#include "mmi_res_range_def.h"
#include "kal_general_types.h"
/* auto add by kw_check end */

/**
 * CUI group event
 */
typedef enum
{
    /* SG event ID */
    EVT_ID_PHB_SAVE_CONTACT = PHONE_BOOK_BASE + 100,            /* save contact done: detail info in evt data */
    EVT_ID_PHB_SAVE_CONTACT_CANCEL,                             /* save contact cancel: user press back */
    
    EVT_ID_PHB_SELECT_CONTACT,                                  /* select contact done */
    EVT_ID_PHB_SELECT_CONTACT_CANCEL,                           /* select contact cancel */
    
    EVT_ID_PHB_SELECT_MULTI_CONTACT,                            /* select contacts done */
    EVT_ID_PHB_SELECT_MULTI_CONTACT_CANCEL,                     /* select contacts cancel */

    EVT_ID_PHB_LIST_CONTACT_HIGHLIGHT,                          /* contact list: highlight event */
    EVT_ID_PHB_SELECT_IMAGE,                                    /* select a image from filemgr */

    EVT_ID_PHB_SEARCH_CONTACT_PRE_RUN,
    EVT_ID_PHB_SEARCH_CONTACT,
    EVT_ID_PHB_SEARCH_CONTACT_CANCEL,
    EVT_ID_PHB_SEARCH_CONTACT_QUIT_BY_END_KEY,
    
    EVT_ID_PHB_CONTACT_NOT_READY,
    
    EVT_ID_PHB_TOTAL                                            /* evt end enum */
    /* SG event ID */
} evt_id_phb_enum;

/**
 * CUI list type
 */
typedef enum
{
    MMI_PHB_LIST_TYPE_ALPHA = 0x01,                              /* alpha jump list */
    MMI_PHB_LIST_TYPE_SEARCH = 0x02,                             /* quick search list */
    MMI_PHB_LIST_TYPE_TWO_LINE = 0x04,                           /* two line style list */
    
    MMI_PHB_LIST_TYPE_SINGLE_SELECT = 0x08,                      /* single select list */
    MMI_PHB_LIST_TYPE_SINGLE_SELECT_AND_GROUP = 0x10,            /* singel select list with group */
    MMI_PHB_LIST_TYPE_MULTI_SELECT = 0x20,                       /* multi select list */
    MMI_PHB_LIST_TYPE_MULTI_SELECT_AND_GROUP = 0x40,             /* multi select list with group */
    MMI_PHB_LIST_TYPE_TOTAL                                      /* list type end enum */
} mmi_phb_list_type_enum;

/* phonebook number type enum */
typedef enum
{
    MMI_PHB_NUMBER_TYPE_INVALID,                                 /* invalid number */
    MMI_PHB_NUMBER_TYPE_NUMBER,                                  /* mobile number */
    MMI_PHB_NUMBER_TYPE_HOME_NUMBER,                             /* home number */
    MMI_PHB_NUMBER_TYPE_OFFICE_NUMBER,                           /* office number */
    MMI_PHB_NUMBER_TYPE_FAX_NUMBER,                              /* fax number */
    MMI_PHB_NUMBER_TYPE_EMAIL_ADDRESS,                           /* email address */
    MMI_PHB_NUMBER_TYPE_EMAIL_ADDRESS_2,                         /* email address 2 */
    MMI_PHB_NUMBER_TYPE_ENUM_TOTAL                               /* enum total */
} mmi_phb_number_type_enum;

/* phonebook save contact cui style */
typedef enum
{
    CUI_PHB_SAVE_CONTACT_NEW = 0x01,                             /* save a contact to a new contact */
    CUI_PHB_SAVE_CONTACT_REPLACE = 0x02,                         /* save a contact to a exist contact */
    CUI_PHB_SAVE_CONTACT_TOTAL,
} cui_phb_save_contact_style_enum;

/* phonebook select image cui style */
typedef enum
{
    CUI_PHB_SELECT_IMG_FROM_FILE = 0x01,                         /* select image from file */
    CUI_PHB_SELECT_IMG_CAMERA = 0x02,                            /* select image from camera */
    CUI_PHB_SELECT_IMG_TOTAL,
} cui_phb_select_image_style_enum;


/** 
  * CUI: save a contact to phonebook
  */

/* result struct sent to caller app by frm SG */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER

    S32 result;                                                 /* save contact result: pls check PhbSrvGprot.h for error detail */
    U16 store_index;                                            /* saved contact's store index */

    U8 field_type;                                              /* last highlight field type */
} cui_phb_save_contact_result_struct;

/** 
  * CUI: entry phonebook list to select a contact
  */

/* result struct sent to caller app by frm SG */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER

    U16 store_index;                                            /* select contact's store index */
    U16 *name;                                                  /* select contact's name */
    U16 *select_data;                                           /* select data, if possible 
                                                                   eg: only select one number or email, if select more then one field, 
                                                                   then the caller should call phb service api to get by store index */
    U32 data_type;                                              /* select data's data type, if only select one field */
} cui_phb_select_contact_result_struct;


/**
 * list CUI, highlight event
 */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER

    U16 highlight_store_index;                                  /* highlight store index */
} cui_phb_list_contact_highlight_struct;

/** 
  * CUI: entry phonebook list to select contacts
  */

#if defined(__MMI_PHB_GENERIC_MULTI_SELECT__)
/**
  * Cui multi select result event structure
  */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER

    U16 count;                                                  /* select contact's count */
    U16 *store_index;                                           /* select contact's store index array */
    U8 *field;                                                  /* select contact's field type array */
    MMI_BOOL is_group;                                          /* MMI_TRUE: select contact come from caller group */
} cui_phb_multi_select_contact_result_struct;
#endif

#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER

    U16 *path;
    MMI_BOOL result;
} cui_phb_select_image_struct;
#endif

extern void cui_phb_save_contact_set_type(MMI_ID phb_save_sg_id, U32 type);
extern U32 cui_phb_save_contact_get_support_type(void);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_user_data
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook: this api is to set caller's user data
 * PARAMETERS
 *  phb_save_sg_id          :         [IN]       screen group id
 *  user_data               :         [IN]       parent group's user data
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_save_contact_set_user_data(mmi_id phb_save_sg_id, U32 user_data);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_get_user_data
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook: this api is to get caller's user data
 * PARAMETERS
 *  phb_save_sg_id          :         [IN]       screen group id
 * RETURNS
 *  U32
 *****************************************************************************/
extern U32 cui_phb_save_contact_get_user_data(mmi_id phb_save_sg_id);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_store_index
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook: this api is for call phonebook editor CUI
 * PARAMETERS
 *  phb_save_sg_id          :         [IN]       screen group id
 *  store_index             :         [IN]       edit contact's store index
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_save_contact_set_store_index(mmi_id phb_save_sg_id, U16 store_index);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_action
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook: this api is only for phonebook to use
 * PARAMETERS
 *  phb_save_sg_id          :         [IN]           phonebook save sg id
 *  action                  :         [IN]           operation: add/edit
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_save_contact_set_action(mmi_id phb_save_sg_id, U8 action);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_storage
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook: this api is to set storage
 * PARAMETERS
 *  phb_save_sg_id          :         [IN]           phonebook save sg id
 *  storage                 :         [IN]           phonebook storage
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_save_contact_set_storage(mmi_id phb_save_sg_id, U8 storage);


/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_create
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook
 * PARAMETERS
 *  parent_id          :         [IN]       Caller screen group id
 * RETURNS
 *  mmi_id             :                    GRP_ID_INVALID: Can not use CUI
 *****************************************************************************/
extern mmi_id cui_phb_save_contact_create(mmi_id parent_id);


/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_data
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook
 * PARAMETERS
 *  phb_save_sg_id         :          [IN]          phonebook save sg id
 *  contact                :          [IN]          contact info to be saved
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_save_contact_set_data(mmi_id phb_save_sg_id, srv_phb_contact_data_struct* contact);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_name
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook, save name info
 * PARAMETERS
 *  phb_save_sg_id          :         [IN]           phonebook save sg id
 *  first_name              :         [IN]           first name
 *  last_name               :         [IN]           last name if support
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_save_contact_set_name(mmi_id phb_save_sg_id, U16* first_name, U16* last_name);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_number
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook, save number info
 * PARAMETERS
 *  phb_save_sg_id              :     [IN]          phonebook save sg id
 *  number                      :     [IN]          mobile number
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_save_contact_set_number(mmi_id phb_save_sg_id, U16* number);

#ifdef __MMI_PHB_OPTIONAL_FIELD__
/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_email
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook, save email info
 * PARAMETERS
 *  phb_save_sg_id              :     [IN]            phonebook save sg id
 *  email                       :     [IN]            email address
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_save_contact_set_email(mmi_id phb_save_sg_id, U16* email);
#endif

#if defined(__MMI_VOIP__)
/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_voip
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook, save voip info
 * PARAMETERS
 *  phb_save_sg_id              :     [IN]           phonebook save sg id
 *  voip                               :     [IN]           voip number
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_save_contact_set_voip(mmi_id phb_save_sg_id, U16* voip);
#endif

#if defined(__MMI_VOIP__)
/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_url
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook, save url info
 * PARAMETERS
 *  phb_save_sg_id             :      [IN]              phonebook save sg  id
 *  url                        :      [IN]              url address
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_save_contact_set_url(mmi_id phb_save_sg_id, U16* url);
#endif


/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_need_popup
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook, popup
 * PARAMETERS
 *  phb_save_sg_id             :      [IN]              phonebook save sg  id
 *  is_popup                   :      [IN]              MMI_TRUE: need popup by phonebook
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_save_contact_set_need_popup(mmi_id phb_save_sg_id, MMI_BOOL is_popup);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_highlight_type
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook, set first highlight item
 * PARAMETERS
 *  phb_save_sg_id             :      [IN]              phonebook save sg  id
 *  highlight_type             :      [IN]              item type
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_save_contact_set_highlight_type(mmi_id phb_save_sg_id, U8 highlight_type);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_res
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook, popup
 * PARAMETERS
 *  phb_save_sg_id             :      [IN]              phonebook save sg  id
 *  path                       :      [IN]              res path
 *  res_id                     :      [IN]              res id
 *  res_from                   :      [IN]              res from
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_save_contact_set_res(mmi_id phb_save_sg_id, U16 *path, U16 res_id, U8 res_from);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_run
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook, run function
 * PARAMETERS
 *  phb_save_sg_id             :      [IN]              save contact cui sg id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_save_contact_run(mmi_id phb_save_sg_id);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_close
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook, close function
 * PARAMETERS
 *  phb_save_sg_id                :      [IN]           save contact sg id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_save_contact_close(mmi_id phb_save_sg_id);


/** 
  * CUI: entry phonebook list to select a contact
  */

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_create
 * DESCRIPTION
 *  Phonebook Cui - select list contact, creat function
 * PARAMETERS
 *  parent_id          :         [IN]       Caller screen group id
 * RETURNS
 *  mmi_id             :                    GRP_ID_INVALID: Can not use CUI
 *****************************************************************************/
extern mmi_id cui_phb_list_select_contact_create(mmi_id parent_id);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_set_user_data
 * DESCRIPTION
 *  Phonebook Cui - select list contact: this api is to set caller's user data
 * PARAMETERS
 *  phb_select_sg_id        :         [IN]       screen group id
 *  user_data               :         [IN]       parent group's user data
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_list_select_contact_set_user_data(mmi_id phb_select_sg_id, U32 user_data);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_get_user_data
 * DESCRIPTION
 *  Phonebook Cui - select list contact: this api is to get caller's user data
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       screen group id
 * RETURNS
 *  U32
 *****************************************************************************/
extern U32 cui_phb_list_select_contact_get_user_data(mmi_id phb_select_sg_id);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_set_field_filter
 * DESCRIPTION
 *  Phonebook Cui - select list contact, set contact's field filter
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 *  filter                    :         [IN]       phonebook field filter
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_list_select_contact_set_field_filter(mmi_id phb_select_sg_id, U32 filter);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_set_storage
 * DESCRIPTION
 *  Phonebook Cui - select list contact, set contact's storage
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 *  storage                   :         [IN]       phonebook storage, default is preffered storage
 *                                                 PHB_STORAGE_MAX/PHB_STORAGE_NVRAM/PHB_STORAGE_SIM
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_list_select_contact_set_storage(mmi_id phb_select_sg_id, U8 storage);

#ifdef __MMI_VUI_WIDGET_KEY_VIP_CONTACT__
/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_set_widget
 * DESCRIPTION
 *  Phonebook Cui - select list contact, set flag if caller is widget
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 *  is_set                   :         [IN]       if wight, show widget contact list
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_list_select_contact_set_widget(mmi_id phb_select_sg_id, MMI_BOOL is_set);
#endif

#ifdef __MMI_NCENTER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_set_ncenter
 * DESCRIPTION
 *  Phonebook Cui - select list contact, set flag if disable ncenter
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 *  is_set                   :         [IN]      if disable ncenter, set true
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_list_select_contact_set_ncenter(mmi_id phb_select_sg_id, MMI_BOOL is_set);
#endif


/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_set_group
 * DESCRIPTION
 *  Phonebook Cui - select list contact, set caller group id
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 *  group_id                  :         [IN]       Caller group id. for show caller group member list
 *  is_equal                  :         [IN]       group id filter
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_list_select_contact_set_group(mmi_id phb_select_sg_id, U8 group_id, MMI_BOOL is_equal);

extern mmi_id cui_phb_list_select_contact_get_parent_group(mmi_id phb_select_sg_id);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_set_lsk_icon
 * DESCRIPTION
 *  Phonebook Cui - select list contact, set lsk icon
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 *  lsk_img                   :         [IN]       set lsk label/image
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_list_select_contact_set_lsk_icon(mmi_id phb_select_sg_id, U16 lsk_img);


/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_contact_set_first_highlight_index
 * DESCRIPTION
 *  Phonebook Cui - select list contact, set first highlight
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 *  index                     :         [IN]       highlight index
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_list_contact_set_first_highlight_index(mmi_id phb_select_sg_id, S32 index);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_run
 * DESCRIPTION
 *  Phonebook Cui - select list contact, run function
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_list_select_contact_run(mmi_id phb_select_sg_id);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_close
 * DESCRIPTION
 *  Phonebook Cui - select list contact, close function
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_list_select_contact_close(mmi_id phb_select_sg_id);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_emit
 * DESCRIPTION
 *  Phonebook Cui - select list contact, emit event
 * PARAMETERS
 *  parent_id          :         [IN]       List sg id
 *  evt_id             :         [IN]       event id
 *  name               :         [IN]       contact name
 *  select_data        :         [IN]       select data
 *  data_type          :         [IN]       data type
 *  store_index        :         [IN]       store index
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_list_select_contact_emit(
                mmi_id parent_id,
                U16 evt_id,
                U16 *name,
                U16 *select_data,
                U32 data_type,
                U16 store_index);


/** 
  * CUI: entry phonebook list to select contacts
  */

/**
  * Cui multi select result event structure
  */
#if defined(__MMI_PHB_GENERIC_MULTI_SELECT__)

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_set_count
 * DESCRIPTION
 *  Phonebook Cui - multi select contact set max select count
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 *  select_count              :         [IN]       max select count
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_list_select_contact_set_count(mmi_id phb_select_sg_id, U16 select_count);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_multi_select_contact_create
 * DESCRIPTION
 *  Phonebook Cui - multi select contact create function
 * PARAMETERS
 *  parent_id          :         [IN]       Caller screen group id
 * RETURNS
 *  mmi_id             :                    GRP_ID_INVALID: Can not use CUI
 *****************************************************************************/
extern mmi_id cui_phb_list_multi_select_contact_create(mmi_id parent_id);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_multi_select_contact_run
 * DESCRIPTION
 *  Phonebook Cui - multi select contact, run function
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_list_multi_select_contact_run(mmi_id phb_select_sg_id);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_multi_select_contact_close
 * DESCRIPTION
 *  Phonebook Cui - multi select contact, close funtion
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_list_multi_select_contact_close(mmi_id phb_select_sg_id);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_group_select_contact_create
 * DESCRIPTION
 *  Phonebook Cui - tab multi select contact, create function
 * PARAMETERS
 *  parent_id          :         [IN]       Caller screen group id
 * RETURNS
 *  mmi_id             :                    GRP_ID_INVALID: Can not use CUI
 *****************************************************************************/
extern mmi_id cui_phb_list_group_select_contact_create(mmi_id parent_id);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_group_select_contact_run
 * DESCRIPTION
 *  Phonebook Cui - tab multi select contact, run function
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_list_group_select_contact_run(mmi_id phb_select_sg_id);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_group_select_contact_close
 * DESCRIPTION
 *  Phonebook Cui - tab multi select contact, close function
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_list_group_select_contact_close(mmi_id phb_select_sg_id);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_multi_select_contact_emit
 * DESCRIPTION
 *  Phonebook Cui - tab multi select contact, emit event
 * PARAMETERS
 *  parent_id          :         [IN]       List sg id
 *  evt_id             :         [IN]       event id
 *  count              :         [IN]       contact count
 *  store_index        :         [IN]       contact store index array
 *  field_index        :         [IN]       field type array
 *  is_group           :         [IN]       is selected from group
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_list_multi_select_contact_emit(
                 mmi_id parent_id,
                 U16 evt_id,
                 U16 count,
                 U16 *store_index,
                 U8 *field_index,
                 MMI_BOOL is_group);
#endif /* __MMI_PHB_GENERIC_MULTI_SELECT__ */

/*****************************************************************************
 * FUNCTION
 *  cui_phb_send_data_to_sa
 * DESCRIPTION
 *  Phonebook Cui - send result to Caller group proc function
 * PARAMETERS
 *  parent_id              :         [IN]       Caller group sg id
 *  data                   :         [IN]       CUI result data
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_phb_send_data_to_sa(mmi_id parent_id, void* data);

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_launch
 * DESCRIPTION
 *  Phonebook Cui - launch phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_launch(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_idle_launch
 * DESCRIPTION
 *  Phonebook Cui - launch phonebook from idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_idle_launch(void);

/*****************************************************************************
 * FUNCTION
 *  cui_phb_view_contact
 * DESCRIPTION
 *  Phonebook Cui - view one contact
 * PARAMETERS
 *  parent_id              :        [IN]        parent group id
 *  store_index            :        [IN]        contact store index
 * RETURNS
 *  void
 *****************************************************************************/
extern mmi_id cui_phb_view_contact(mmi_id parent_id, U16 store_index);

#ifdef __MMI_PHB_CALLER_RES__
#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
extern MMI_ID cui_phb_select_image_create(MMI_ID group_id, U32 type);
extern void cui_phb_select_image_run(MMI_ID group_id);
extern void cui_phb_select_image_close(MMI_ID sg_id);
#endif
#endif

typedef enum
{
    /* compare the whole field */
    CUI_PHB_SEARCH_CONTACT_EQUAL,
    
    /* compare the part field */
    /* only support it now */
    CUI_PHB_SEARCH_CONTACT_CONTAIN,
    
    CUI_PHB_SEARCH_CONTACT_STYLE_TOTAL
} cui_phb_search_contact_style_enum;

typedef enum
{
    /* search field: name */
    /* only support it now */    
    CUI_PHB_SEARCH_CONTACT_NAME,
    
    /* search field number */
    CUI_PHB_SEARCH_CONTACT_NUMBER,
    
    /* search field email */
    CUI_PHB_SEARCH_CONTACT_EMAIL,
    
    CUI_PHB_SEARCH_CONTACT_FIELD_TOTAL
} cui_phb_search_contact_field_enum;

typedef struct
{
    /* compare style: default is CUI_PHB_SEARCH_CONTACT_CONTAIN */
    cui_phb_search_contact_style_enum search_style;
    
    /* compare field: default is CUI_PHB_SEARCH_CONTACT_NAME */
    cui_phb_search_contact_field_enum search_field;

    /* search field content */
    U16 *search_data;

    /* search field data length */
    U16 length;
    
    /* to get contact's content field mask, ex: SRV_PHB_ENTRY_FIELD_GSM_NUM */
    U32 get_field;
} cui_phb_search_contact_struct;


typedef struct
{
    /*
     * EVT_ID_PHB_SEARCH_CONTACT_PRE_RUN:
     *  it will be sent out after pre-run cui with contact count, if count = 1, 
     *  num_count = 1, it means only one contact match, application maybe no need
     *  call cui run, and close the cui directly.
     * EVT_ID_PHB_SEARCH_CONTACT: 
     *  select a contact with id, field type information, and application use cui
     *  get data function to get the selected data. when the count = 0, it means no
     *  more contact to select, application should call cui close api.
     */
    MMI_EVT_GROUP_PARAM_HEADER

    U16 count;              /* contact count */
    
    U16 id;                 /* selected contact id */
    U32 field_type;         /* selected field mask */
    U8 num_count;           /* contact's number count */
} cui_phb_search_contact_result_struct;


/*****************************************************************************
 * FUNCTION
 *  cui_phb_search_contact_init
 * DESCRIPTION
 *  Phonebook Cui - init structure
 * PARAMETERS
 *  cui_phb_search_contact_struct   [IN]    search filter, see struct: cui_phb_search_contact_struct
 * RETURNS
 *  MMI_ID
 *****************************************************************************/
void cui_phb_search_contact_init(cui_phb_search_contact_struct *search);


/*****************************************************************************
 * FUNCTION
 *  cui_phb_search_contact_create
 * DESCRIPTION
 *  Phonebook Cui - create function
 * PARAMETERS
 *  parent_id                       [IN]    parent group id
 *  cui_phb_search_contact_struct   [IN]    search filter, see struct: cui_phb_search_contact_struct
 * RETURNS
 *  MMI_ID
 *****************************************************************************/
MMI_ID cui_phb_search_contact_create(MMI_ID parent_id, cui_phb_search_contact_struct *search);


/*****************************************************************************
 * FUNCTION
 *  cui_phb_search_contact_get_data
 * DESCRIPTION
 *  Phonebook Cui - get selected data
 * PARAMETERS
 *  group_id                        [IN]    cui group id
 *  id                              [IN]    selected contact id
 *  field_mask                      [IN]    selected field mask
 *  buf                             [OUT]   selected data
 *  buf_length                      [OUT]   buf length
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_search_contact_get_data(MMI_ID group_id, U16 id, U32 field_mask, U16 *buf, U16 buf_length, MMI_BOOL more);


/*****************************************************************************
 * FUNCTION
 *  cui_phb_search_contact_pre_run
 * DESCRIPTION
 *  Phonebook Cui - pre run function, maybe no screen to show
 * PARAMETERS
 *  group_id                        [IN]    cui group id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_search_contact_pre_run(MMI_ID group_id);


/*****************************************************************************
 * FUNCTION
 *  cui_phb_search_contact_run
 * DESCRIPTION
 *  Phonebook Cui - run the cui
 * PARAMETERS
 *  group_id                        [IN]    cui group id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_search_contact_run(MMI_ID group_id);


/*****************************************************************************
 * FUNCTION
 *  cui_pbh_search_contact_close
 * DESCRIPTION
 *  Phonebook Cui - close the cui
 * PARAMETERS
 *  group_id                        [IN]    cui group id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_pbh_search_contact_close(MMI_ID group_id);

#endif

#endif /* _PHB_CUI_GPROT_H  */
