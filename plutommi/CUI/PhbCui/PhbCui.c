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
 * PhonebookCUI.c
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMI_include.h"
#include "FileMgrSrvGProt.h"
#include "MMIDataType.h"

#include "PhoneBookGprot.h"
#include "PhoneBookProt.h"
#include "PhoneBookResDef.h"
#include "PhoneBookTypes.h"
#include "PhoneBookCore.h"
#include "PhoneBookExtraNumber.h"
#include "PhbCuiGprot.h"
#include "MenuCuiGprot.h"
#include "FSEditorCuiGprot.h"
#include "InlineCuiGprot.h"
#include "PhbSrvGprot.h"
#include "CommonScreens.h"
#include "mmi_frm_scenario_gprot.h"

#include "IdleAppDef.h"                     /* for g_idle_context */
#include "IdleAppProt.h"

#if defined(__MMI_VCARD__)
#include "vObjects.h"
#include "vcard.h"
#endif /* defined(__MMI_VCARD__) */ 

#include "FileMgrCuiGprot.h"
#if defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__)
#include "CameraCuiGprot.h"
#endif

/* auto add by kw_check begin */
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "string.h"
#include "custom_phb_config.h"
#include "MMI_features.h"
#include "kal_general_types.h"
#include "GlobalResDef.h"
#include "kal_public_api.h"
#include "Unicodexdcl.h"
#include "ps_public_enum.h"
#include "customer_email_num.h"
#include "PhbSrvIprot.h"
#include "CommonScreensResDef.h"
/* auto add by kw_check end */
#ifdef __MMI_SNS_CONTACTS__
#include "SnsCuiGprot.h"
#include "SnsSrvGprot.h"
#include "mmi_rp_srv_sns_def.h"
#endif
#if defined(__MMI_IMAGE_CLIP_CUI__) && defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
#include "ImageClipCuiGprot.h"
#endif
#include "mmi_frm_app_launcher_gprot.h"
#ifdef __MMI_NCENTER_SUPPORT__
#include "vapp_ncenter_gprot.h"
#endif
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
#include "TcardSrvGprot.h"
#endif

/*----------------------------------------------------------------*/
/* extern variable                                                */
/*----------------------------------------------------------------*/
#if defined(__MMI_PHB_CALLER_VIDEO__)
#if defined(__MMI_SWFLASH__)
extern U8 g_phb_swflash_video_minus;
#endif
#endif

#ifdef __MMI_SNS_CONTACTS__
extern mmi_phb_sns_misc_struct g_mmi_phb_sns_misc;
#endif

/*----------------------------------------------------------------*/
/* Local functions                                                */
/*----------------------------------------------------------------*/
static void cui_phb_list_select_contact_release_cntx(mmi_phb_list_cntx_struct *list_cntx);
static mmi_ret cui_phb_save_contact_proc(mmi_event_struct *evt);
static mmi_ret cui_phb_view_contact_proc(mmi_event_struct *evt);


#define CUI_PHB_SAVE_CONTACT
/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_create_cntx
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook, create save contact cntx
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_phb_save_contact_cntx_struct*
 *****************************************************************************/
mmi_phb_save_contact_cntx_struct* cui_phb_save_contact_create_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_save_contact_cntx_struct *save_cntx;
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    S32 i;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_SAVE_CONTACT_CREATE_CNTX);

    save_cntx = (mmi_phb_save_contact_cntx_struct *) srv_phb_mem_malloc(sizeof(mmi_phb_save_contact_cntx_struct), SRV_PHB_MEMORY_TYPE_ADM);
    
    /**
     * init save contact cntx
     */
    memset(save_cntx, 0, sizeof(mmi_phb_save_contact_cntx_struct));

    save_cntx->contact = (mmi_phb_contact_info_struct *) srv_phb_mem_malloc(sizeof(mmi_phb_contact_info_struct), SRV_PHB_MEMORY_TYPE_ADM);
    memset(save_cntx->contact, 0, sizeof(mmi_phb_contact_info_struct));
#ifdef __MMI_PHB_OPTIONAL_FIELD__ 
    for (i = 0; i < MMI_PHB_OPT_NUM_COUNT; i++)
    {
        save_cntx->contact->opt_order[i] = SRV_PHB_ENTRY_FIELD_OPT_NUM_1 << i;
    }
#endif
    save_cntx->res = (mmi_phb_caller_res_struct *) srv_phb_mem_malloc(sizeof(mmi_phb_caller_res_struct), SRV_PHB_MEMORY_TYPE_ADM);

    /**
     * Set default value
     */
    save_cntx->action = MMI_PHB_OP_ADD;
    save_cntx->storage = (U8) mmi_phb_get_preferred_storage();
    save_cntx->store_index = MMI_PHB_INVALID_STORE_INDEX;
#ifdef __MMI_PHB_DEFAULT_NUMBER__
    save_cntx->contact->default_number = 0xff;
#endif
#ifdef __MMI_SAVE_CONTACT_REPLACE__
    save_cntx->style = CUI_PHB_SAVE_CONTACT_NEW | CUI_PHB_SAVE_CONTACT_REPLACE;
#else
    save_cntx->style = CUI_PHB_SAVE_CONTACT_NEW;
#endif
    save_cntx->first_highlight_type = 0xff;

    save_cntx->is_popup = MMI_TRUE;
    
    return save_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_release_cntx
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook, release save contact cntx
 * PARAMETERS
 *  save_cntx                       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_save_contact_release_cntx(mmi_phb_save_contact_cntx_struct *save_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG1(TRC_MMI_PHB_SAVE_CONTACT_RELEASE_CNTX, save_cntx->sg_id);

    if (save_cntx != NULL)
    {
        if (save_cntx->contact != NULL)
        {
            srv_phb_mem_free(save_cntx->contact);
            save_cntx->contact = NULL;
        }
        if (save_cntx->res != NULL)
        {
            srv_phb_mem_free(save_cntx->res);
            save_cntx->res = NULL;
        }
    #ifdef __MMI_SAVE_CONTACT_REPLACE__
        if (save_cntx->update_list != NULL)
        {
            cui_phb_list_select_contact_release_cntx(save_cntx->update_list);
            save_cntx->update_list = NULL;
        }
    #endif
        srv_phb_mem_free(save_cntx);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_create
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook
 * PARAMETERS
 *  parent_id          :         [IN]       Caller screen group id
 * RETURNS
 *  mmi_id
 *****************************************************************************/
mmi_id cui_phb_save_contact_create(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;    
    mmi_phb_save_contact_cntx_struct *save_cntx;
    mmi_id sg_id = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_CUI_PHB_SAVE_CONTACT_CREATE);

    /* Always allow to create success */
    /* if (mmi_phb_check_ready(MMI_TRUE)) */
    {
        handle = mmi_phb_cntx_mgr_create_handle(MMI_PHB_SG_CUI_SAVE);
        sg_id = mmi_phb_cntx_mgr_get_sg_id(handle);
        mmi_phb_cntx_mgr_set_parent_id(handle, parent_id);
        save_cntx = cui_phb_save_contact_create_cntx();

        save_cntx->sg_id = sg_id;
        save_cntx->parent_id = parent_id;

        mmi_phb_cntx_mgr_set_data(handle, save_cntx);

        mmi_frm_group_create(parent_id, sg_id, cui_phb_save_contact_proc, save_cntx);
    }

    return sg_id;
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_cntx
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook: set cntx
 * PARAMETERS
 *  save_cntx               :       [IN]        save contact cntx
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_save_contact_set_cntx(mmi_phb_save_contact_cntx_struct *save_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_CUI_PHB_SAVE_CONTACT_SET_CNTX);

    g_mmi_phb_save_contact_p = save_cntx;
    g_mmi_phb_contact_p = save_cntx->contact;
#ifdef __MMI_PHB_CALLER_RES__
    g_mmi_phb_res_p = save_cntx->res;
#endif
    
#ifdef __MMI_SAVE_CONTACT_REPLACE__
    if (save_cntx->update_list)
    {
        cui_phb_list_select_contact_set_cntx(save_cntx->update_list);
    }
#endif
}


void cui_phb_save_contact_set_type(MMI_ID phb_save_sg_id, U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_save_contact_cntx_struct *save_cntx;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_save_sg_id);
    save_cntx = (mmi_phb_save_contact_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);

    save_cntx->style = 0;

    if (type & CUI_PHB_SAVE_CONTACT_REPLACE)
    {
    #ifdef __MMI_SAVE_CONTACT_REPLACE__
        save_cntx->style = CUI_PHB_SAVE_CONTACT_REPLACE;
    #else
        save_cntx->style = CUI_PHB_SAVE_CONTACT_NEW;
    #endif
    }

    if (type & CUI_PHB_SAVE_CONTACT_NEW)
    {
       save_cntx->style |= CUI_PHB_SAVE_CONTACT_NEW;
    }
}

U32 cui_phb_save_contact_get_support_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SAVE_CONTACT_REPLACE__
    return CUI_PHB_SAVE_CONTACT_NEW | CUI_PHB_SAVE_CONTACT_REPLACE;
#else
    return CUI_PHB_SAVE_CONTACT_NEW;
#endif    
}


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
void cui_phb_save_contact_set_user_data(mmi_id phb_save_sg_id, U32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_save_contact_cntx_struct *save_cntx;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_save_sg_id);
    save_cntx = (mmi_phb_save_contact_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);

    save_cntx->user_data = user_data;
}


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
U32 cui_phb_save_contact_get_user_data(mmi_id phb_save_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_save_contact_cntx_struct *save_cntx;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_save_sg_id);
    save_cntx = (mmi_phb_save_contact_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);

    return save_cntx->user_data;
}


void cui_phb_save_contact_set_store_index(mmi_id phb_save_sg_id, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_save_contact_cntx_struct *save_cntx;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG2(TRC_MMI_PHB_SAVE_CNTACT_SET_STORE_INDEX, phb_save_sg_id, store_index);
    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_save_sg_id);
    save_cntx = (mmi_phb_save_contact_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);
    save_cntx->store_index = store_index;
    save_cntx->action = MMI_PHB_OP_EDIT;
    save_cntx->storage = srv_phb_get_storage(store_index);
}


void cui_phb_save_contact_set_action(mmi_id phb_save_sg_id, U8 action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_save_contact_cntx_struct *save_cntx;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG2(TRC_MMI_PHB_SAVE_CNTACT_SET_ACTION, phb_save_sg_id, action);
    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_save_sg_id);
    save_cntx = (mmi_phb_save_contact_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);
    save_cntx->action = (mmi_phb_op_action_enum)action;
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_data
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook: set storage
 * PARAMETERS
 *  phb_save_sg_id                   [IN]
 *  storage                               [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_save_contact_set_storage(mmi_id phb_save_sg_id, U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_save_contact_cntx_struct *save_cntx;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG2(TRC_MMI_PHB_SAVE_CNTACT_SET_STORAGE, phb_save_sg_id, storage);
    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_save_sg_id);
    save_cntx = (mmi_phb_save_contact_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);
    save_cntx->storage = storage;
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_data
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook
 * PARAMETERS
 *  parent_id         :          [IN]          phonebook save sg id
 *  contact           :          [IN]          contact info to be saved
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_save_contact_set_data(mmi_id phb_save_sg_id, srv_phb_contact_data_struct* contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_save_contact_cntx_struct *save_cntx;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG1(TRC_MMI_PHB_SAVE_CNTACT_SET_DATA, phb_save_sg_id);

    MMI_ASSERT(contact != NULL);
    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_save_sg_id);
    save_cntx = (mmi_phb_save_contact_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);

    /**
     * build contact info
     */
    mmi_phb_contact_srv_to_mmi(contact, save_cntx->contact);
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_name
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook, save name info
 * PARAMETERS
 *  phb_save_sg_id          :         [IN]           phonebook save sg id
 *  first_name                  :         [IN]           first name
 *  last_name                  :         [IN]           last name if support
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_save_contact_set_name(mmi_id phb_save_sg_id, U16* first_name, U16* last_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_save_contact_cntx_struct *save_cntx;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG1(TRC_MMI_PHB_SAVE_CNTACT_SET_NAME, phb_save_sg_id);
    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_save_sg_id);
    save_cntx = (mmi_phb_save_contact_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);

    /**
     * build contact info
     */
    if (first_name != NULL)
    {
        srv_phb_remove_invalid_name(first_name);
        mmi_wcsncpy(save_cntx->contact->name, first_name, MMI_PHB_NAME_FIELD_LENGTH);
    }
    if (last_name != NULL)
    {
        srv_phb_remove_invalid_name(last_name);
        
    #ifdef __MMI_PHB_LAST_NAME_FIELD__    
        mmi_wcsncpy(save_cntx->contact->last_name, last_name, MMI_PHB_NAME_FIELD_LENGTH);
    #else
        srv_phb_convert_to_name(save_cntx->contact->name, first_name, last_name, MMI_PHB_NAME_FIELD_LENGTH);
    #endif
    }
}


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
void cui_phb_save_contact_set_number(mmi_id phb_save_sg_id, U16* number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_save_contact_cntx_struct *save_cntx;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG1(TRC_MMI_PHB_SAVE_CNTACT_SET_NUMBER, phb_save_sg_id);
    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_save_sg_id);
    save_cntx = (mmi_phb_save_contact_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);

    if (number != NULL)
    {
        srv_phb_remove_invalid_number(number);
        mmi_phb_truncate_number_field_to_max_len(save_cntx->contact->number, number, MMI_PHB_NUMBER_LENGTH);
    }
}


#ifdef __MMI_PHB_OPTIONAL_FIELD__
/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_email
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook, save email info
 * PARAMETERS
 *  phb_save_sg_id              :     [IN]            phonebook save sg id
 *  email                             :     [IN]            email address
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_save_contact_set_email(mmi_id phb_save_sg_id, U16* email)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_save_contact_cntx_struct *save_cntx;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG1(TRC_MMI_PHB_SAVE_CNTACT_SET_EMAIL, phb_save_sg_id);
    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_save_sg_id);
    save_cntx = (mmi_phb_save_contact_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);
#ifdef __MMI_PHB_USIM_SUPPORT__    
    if(mmi_phb_check_usim_detail_ex(PHB_STORAGE_SIM,0,PHB_EMAIL) )   //check for USIM1 free email
    {
        save_cntx->storage = PHB_STORAGE_MAX;
    }
    else
    {
        save_cntx->storage = (U8)mmi_phb_get_preferred_storage();
    }
#else
    save_cntx->storage = PHB_STORAGE_NVRAM;
#endif
    save_cntx->is_from_email = MMI_TRUE;
    if (email != NULL)
    {
        mmi_wcsncpy(save_cntx->contact->emailAddress, email, MMI_PHB_EMAIL_LENGTH);
    }
}
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
void cui_phb_save_contact_set_voip(mmi_id phb_save_sg_id, U16* voip)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_save_contact_cntx_struct *save_cntx;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG1(TRC_MMI_PHB_SAVE_CNTACT_SET_VOIP, phb_save_sg_id);
    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_save_sg_id);
    save_cntx = (mmi_phb_save_contact_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);

    save_cntx->storage = PHB_STORAGE_NVRAM;

    if (voip != NULL)
    {
        mmi_wcsncpy(save_cntx->contact->voip, voip, VOIP_URI_LEN - 1);
    }
}
#endif


#ifdef __MMI_PHB_INFO_FIELD__
/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_url
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook, save url info
 * PARAMETERS
 *  phb_save_sg_id             :      [IN]              phonebook save sg  id
 *  url                                :      [IN]              url address
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_save_contact_set_url(mmi_id phb_save_sg_id, U16* url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_save_contact_cntx_struct *save_cntx;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG1(TRC_MMI_PHB_SAVE_CNTACT_SET_URL, phb_save_sg_id);
    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_save_sg_id);
    save_cntx = (mmi_phb_save_contact_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);

    save_cntx->storage = PHB_STORAGE_NVRAM;

    if (url != NULL)
    {
        mmi_wcsncpy(save_cntx->contact->url, url, MMI_PHB_URL_LENGTH);
    }
}
#endif

void cui_phb_save_contact_set_highlight_type(mmi_id phb_save_sg_id, U8 highlight_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_save_contact_cntx_struct *save_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_save_sg_id);
    save_cntx = (mmi_phb_save_contact_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);

    save_cntx->first_highlight_type = highlight_type;
}


void cui_phb_save_contact_set_need_popup(mmi_id phb_save_sg_id, MMI_BOOL is_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_save_contact_cntx_struct *save_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_save_sg_id);
    save_cntx = (mmi_phb_save_contact_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);

    save_cntx->is_popup = is_popup;
}


void cui_phb_save_contact_set_res(mmi_id phb_save_sg_id, U16 *path, U16 res_id, U8 res_from)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_save_contact_cntx_struct *save_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_save_sg_id);
    save_cntx = (mmi_phb_save_contact_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);

    switch (res_from)
    {
        case MMI_PHB_RECV_RES_IMAGE:
        {
            save_cntx->contact->picture_id = res_id;
            mmi_wcscpy(save_cntx->contact->picture, path);
            break;
        }

        case MMI_PHB_RECV_RES_AUDIO:
        {
            save_cntx->contact->ring_tone_id = res_id;
            break;
        }

    #if defined(__MMI_PHB_CALLER_VIDEO__)
        case MMI_PHB_RECV_RES_VIDEO:        
    #ifdef __MMI_SWFLASH__
        case MMI_PHB_RECV_RES_SWFLASH:
    #endif
        {
            save_cntx->contact->video_id = res_id;
            mmi_wcscpy(save_cntx->contact->video, path);
            break;
        }
    #endif
    
        default:
            /* error trace */
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_entry
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook, entry screen
 * PARAMETERS
 *  phb_save_sg_id                   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_save_contact_entry(mmi_id phb_save_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_save_contact_cntx_struct *save_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;    
    }

    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_save_sg_id);
    save_cntx = (mmi_phb_save_contact_cntx_struct *) mmi_phb_cntx_mgr_get_data(handle);

#ifdef __MMI_SAVE_CONTACT_REPLACE__
    if (save_cntx->style == CUI_PHB_SAVE_CONTACT_REPLACE &&
        (save_cntx->action == MMI_PHB_OP_ADD && (save_cntx->field_mask == SRV_PHB_ENTRY_FIELD_NUMBER)))
    {
        mmi_phb_entry_save_contact_opt_update_list();
    }
    else if (save_cntx->style == CUI_PHB_SAVE_CONTACT_NEW)
    {
        mmi_phb_op_add_pre_entry(save_cntx);
    }
    else if (save_cntx->action == MMI_PHB_OP_ADD && 
        (save_cntx->field_mask == SRV_PHB_ENTRY_FIELD_NUMBER))
    {        
        mmi_phb_entry_general_save_contact_option();
    }
    else
    {
        mmi_phb_op_add_pre_entry(save_cntx);
    }
#else
    mmi_phb_op_add_pre_entry(save_cntx);
#endif
}



/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_proc
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook, proc function
 * PARAMETERS
 *  evt                 :     [IN]          event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret cui_phb_save_contact_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;    
    mmi_phb_save_contact_cntx_struct *save_cntx;
    mmi_ret menu_cui_proc;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    save_cntx = (mmi_phb_save_contact_cntx_struct *) evt->user_data;
    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(save_cntx->sg_id);

    menu_cui_proc = mmi_phb_choose_storage_menu_cui_proc(evt);
    if (menu_cui_proc == MMI_RET_OK)
    {
        return MMI_RET_OK;
    }

    menu_cui_proc = mmi_phb_edit_menu_cui_proc(evt);
    if (menu_cui_proc == MMI_RET_OK)
    {
        return MMI_RET_OK;
    }

#ifdef __MMI_PHB_CALLER_RES__
#if !(defined(LOW_COST_SUPPORT) && !(defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)))
    menu_cui_proc = mmi_phb_image_edit_menu_cui_proc(evt);
    if (menu_cui_proc == MMI_RET_OK)
    {
        return MMI_RET_OK;
    }
#endif
#endif /* __MMI_PHB_CALLER_RES__ */

#ifdef __MMI_SAVE_CONTACT_REPLACE__
    menu_cui_proc = mmi_phb_save_choose_menu_cui_proc(evt);
    if (menu_cui_proc == MMI_RET_OK)
    {
        return MMI_RET_OK;
    }
#endif

#ifdef __MMI_PHB_CALLER_RES__
#if defined(__MMI_PHB_CALLER_VIDEO__)
    menu_cui_proc = mmi_phb_video_edit_menu_cui_proc(evt);
    if (menu_cui_proc == MMI_RET_OK)
    {
        return MMI_RET_OK;
    }
    menu_cui_proc = mmi_phb_video_audio_menu_cui_proc(evt);
    if (menu_cui_proc == MMI_RET_OK)
    {
        return MMI_RET_OK;
    }
#endif /* defined(__MMI_PHB_CALLER_VIDEO__) */

#ifdef __MMI_PHB_UI_IN_TABS__
    if (mmi_phb_profiles_contact_proc(evt) == MMI_RET_OK)
    {
        return MMI_RET_OK;
    }
#endif
#endif /* __MMI_PHB_CALLER_RES__ */

    switch (evt->evt_id)
    {
    #ifdef __MMI_PHB_UI_IN_TABS__
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        case EVT_ID_CUI_FSEDITOR_CSK_PRESSED:
        case EVT_ID_CUI_FSEDITOR_ABORT:
        case EVT_ID_CUI_FSEDITOR_CHANGED:
            mmi_phb_number_editor_proc(evt);
            break;
    #else /* __MMI_PHB_UI_IN_TABS__ */
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_ABORT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        case EVT_ID_CUI_INLINE_NOTIFY:
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_INACTIVE:
        case EVT_ID_CUI_INLINE_GROUP_DEINIT:
            if (mmi_phb_check_storage(MMI_TRUE, save_cntx->storage))
            {
                mmi_phb_phone_editor_proc(evt);
            }
            else
            {
                mmi_phb_sim_editor_proc(evt);
            }
            break;
    #endif /* __MMI_PHB_UI_IN_TABS__ */
            
        case EVT_ID_GROUP_INACTIVE:
        {
            if (!save_cntx->evt_out && mmi_frm_scrn_get_count(save_cntx->sg_id) == 0)
            {
                cui_phb_save_contact_result_struct evt;

                evt.evt_id = EVT_ID_PHB_SAVE_CONTACT_CANCEL;
                evt.size = sizeof(cui_phb_save_contact_result_struct);
                evt.user_data = NULL;
                evt.sender_id = save_cntx->sg_id;

                evt.result = SRV_PHB_ERROR;
                evt.field_type = 0xff;

                save_cntx->evt_out = MMI_TRUE;
                
                mmi_phb_cntx_mgr_post_evt(save_cntx->sg_id, MMI_FALSE, (mmi_event_struct*)&evt);
            }
            break;
        }
        
        case EVT_ID_GROUP_ACTIVE:
            cui_phb_save_contact_set_cntx(save_cntx);
            break;
            	
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
            g_mmi_phb_op_cntx.end_key_press = MMI_TRUE;
            break;

        case EVT_ID_GROUP_EXIT:
        {
            //move out the group node from the scenario tree
        #if defined(__MMI_IMPS__)
/* under construction !*/
/* under construction !*/
        #endif
            break;
        }

        case EVT_ID_GROUP_DEINIT:
        {
            if (g_mmi_phb_op_cntx.end_key_press
                && (mmi_phb_op_check_pre_save(save_cntx->contact, save_cntx->storage, MMI_FALSE))
                )
            {
            	cui_phb_save_contact_set_cntx(save_cntx);
        		mmi_phb_end_key_save_contact();
            }
            else
            {
                g_mmi_phb_op_cntx.end_key_press = MMI_FALSE;
                #ifdef __MMI_PHB_SPEED_DIAL__
                srv_phb_speed_dial_reload();
                #endif
            }
            // release group node
            cui_phb_save_contact_release_cntx(save_cntx);
            mmi_phb_cntx_mgr_release_handle(handle);
            break;
        }
        
        case EVT_ID_GROUP_FOCUSED:
        case EVT_ID_GROUP_REDRAW_START:
            cui_phb_save_contact_set_cntx(save_cntx);
            break;
            
        case EVT_ID_POPUP_QUIT:
        {
            mmi_phb_sg_data_struct *instance;
            
            instance = mmi_phb_cntx_mgr_get_instance(save_cntx->sg_id);

            if (instance && instance->delay_event)
            {
                save_cntx->evt_out = MMI_TRUE;
                mmi_phb_cntx_mgr_post_evt(save_cntx->sg_id, MMI_FALSE, instance->delay_event);
            }
            
            break;
        }

    #ifdef __MMI_PHB_CALLER_RES__
    #if defined(__MMI_FILE_MANAGER__)
        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
        {
            mmi_phb_fmgr_cui_res_handle((cui_file_selector_result_event_struct*) evt);
            break;
        }

	#if defined(__MMI_IMAGE_CLIP_CUI__) && defined(__MMI_FILE_USEAS_SUPPORT__)
	#if defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
		case EVT_ID_CUI_IMAGE_CLIP_CLOSE_REQUEST:
		{
			cui_image_clip_close(((cui_image_clip_evt_struct*)evt)->sender_id);
			break;
		}

		case EVT_ID_CUI_IMAGE_CLIP_RESULT_SUCCESS:
		{
			cui_image_clip_evt_struct *clip_result = (cui_image_clip_evt_struct*)evt;
			mmi_phb_clip_image_finish(clip_result->save_file_path);
			break;
		}
	#endif
	#endif
		
    #if defined(__MMI_FILE_USEAS_SUPPORT__)
    #if defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__)
        case CUI_CAMERA_EVENT_RESULT_SUCCESS:
            mmi_phb_camera_cui_res_handle((WCHAR*)(((cui_camera_event_struct*)evt)->file_path));
        case CUI_CAMERA_EVENT_RESULT_FAILED:
        case CUI_CAMERA_EVENT_RESULT_CLOSE_ME:
            cui_camera_close(((cui_camera_event_struct*)evt)->sender_id);
            break;
    #endif /* defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__) */
    #endif /* defined(__MMI_FILE_USEAS_SUPPORT__) */
    #endif /* __MMI_FILE_MANAGER__ */
    #endif /* __MMI_PHB_CALLER_RES__ */
        default:
            break;
    }
 
    return MMI_RET_OK;
}


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
void cui_phb_save_contact_run(mmi_id phb_save_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_save_contact_cntx_struct *save_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG1(TRC_MMI_PHB_SAVE_CONTACT_RUN, phb_save_sg_id);
    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_save_sg_id);
    save_cntx = mmi_phb_cntx_mgr_get_data(handle);

    if (save_cntx->action == MMI_PHB_OP_EDIT)
    {
        MMI_ASSERT(save_cntx->store_index != MMI_PHB_INVALID_STORE_INDEX);
        mmi_phb_contact_get_contact_info(save_cntx->store_index, save_cntx->contact);
    }

#ifdef __MMI_PHB_CALLER_RES__
    mmi_phb_contact_res_value_assign(phb_save_sg_id, save_cntx->res, save_cntx->contact);
#endif

    save_cntx->field_mask = mmi_phb_contact_build_field_mask(save_cntx->contact);
    
    if (save_cntx->field_mask != 0 && save_cntx->action != MMI_PHB_OP_EDIT)
    {
        save_cntx->done_flag = MMI_TRUE;
    }

    cui_phb_save_contact_set_cntx(save_cntx);

#ifdef __MMI_PHB_CALLER_RES__
    mmi_phb_contact_build_res();
#endif

    mmi_frm_group_enter(phb_save_sg_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_phb_save_contact_entry(phb_save_sg_id);
}


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
void cui_phb_save_contact_close(mmi_id phb_save_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG1(TRC_MMI_PHB_SAVE_CONTACT_CLOSE, phb_save_sg_id);
    mmi_frm_group_close(phb_save_sg_id);
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_get_contact
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook
 * PARAMETERS
 *  phb_save_sg_id                  [IN]
 * RETURNS
 *  mmi_phb_contact_info_struct*
 *****************************************************************************/
mmi_phb_contact_info_struct* cui_phb_save_contact_get_contact(mmi_id phb_save_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_save_contact_cntx_struct *save_cntx;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_save_sg_id);
    save_cntx = (mmi_phb_save_contact_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);

    return save_cntx->contact;
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_get_cntx
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook
 * PARAMETERS
 *  phb_save_sg_id                  [IN]
 * RETURNS
 *  mmi_phb_save_contact_cntx_struct*
 *****************************************************************************/
mmi_phb_save_contact_cntx_struct* cui_phb_save_contact_get_cntx(mmi_id phb_save_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_save_sg_id);

    return (mmi_phb_save_contact_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);
}

#define CUI_PHB_IMAGE_SELECT
#ifdef __MMI_PHB_CALLER_RES__
#if !defined(LOW_COST_SUPPORT)
#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)&&defined(__SRV_PHB_CALLER_RES_DATA_STORE__)
static mmi_ret cui_phb_select_image_proc(mmi_event_struct * evt)
{
    mmi_phb_select_image_struct* user_data = (mmi_phb_select_image_struct*) evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
        {
            cui_file_selector_result_event_struct* result = (cui_file_selector_result_event_struct*) evt;

            if (result->result > 0)
            {
                /**
                 * get selected path
                 */
                cui_file_selector_get_selected_filepath(
                    result->sender_id,
                    NULL,
                    (WCHAR *) user_data->path,
                    (SRV_FMGR_PATH_MAX_LEN+1) * ENCODING_LENGTH);
                
                /**
                 * Check image content
                 */
                if (mmi_phb_image_check_valid_image((CHAR*) user_data->path, MMI_FALSE))
                {
                    mmi_frm_scrn_first_enter(
                        user_data->sg_id,
                        SCR_ID_PHB_IMAGE_VIEW_IMAGE,
                        (FunctionPtr) mmi_phb_select_image_preview,
                        user_data);
                }
            }
            else
            {
                cui_phb_select_image_struct evt;

                evt.evt_id = EVT_ID_PHB_SELECT_IMAGE;
                evt.sender_id = user_data->sg_id;
                evt.size = sizeof(cui_phb_select_image_struct);
                evt.result = MMI_FALSE;
                evt.path = NULL;

                mmi_frm_group_post_to_parent(user_data->sg_id, (mmi_group_event_struct*)&evt);
            }
            break;
        }
        
    #if defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__)        
        case CUI_CAMERA_EVENT_RESULT_SUCCESS:
        {
            cui_camera_event_struct *result = (cui_camera_event_struct*)evt;
            mmi_ucs2cpy((CHAR *)user_data->path, (CHAR *) result->file_path);
            
            if (mmi_phb_image_check_valid_image((CHAR*) user_data->path, MMI_TRUE))
            {
                mmi_frm_scrn_first_enter(
                    user_data->sg_id,
                    SCR_ID_PHB_IMAGE_VIEW_IMAGE,
                    (FunctionPtr) mmi_phb_select_image_preview,
                    user_data);
            }
            else
            {
                // error handler
            }
            break;
        }
        case CUI_CAMERA_EVENT_RESULT_FAILED:
        case CUI_CAMERA_EVENT_RESULT_CLOSE_ME:
        {
            cui_phb_select_image_struct evt;

            evt.evt_id = EVT_ID_PHB_SELECT_IMAGE;
            evt.sender_id = user_data->sg_id;
            evt.size = sizeof(cui_phb_select_image_struct);
            evt.result = MMI_FALSE;
            evt.path = NULL;

            mmi_frm_group_post_to_parent(user_data->sg_id, (mmi_group_event_struct*)&evt);

            break;
        }
    #endif
    
        case EVT_ID_GROUP_DEINIT:
        {
            srv_phb_mem_free(user_data);
            break;
        }
        default:
            break;
    }
 
    return MMI_RET_OK;
}

MMI_ID cui_phb_select_image_create(MMI_ID group_id, U32 type)
{
    MMI_ID sg_id;
    mmi_phb_select_image_struct *user_data;

    user_data = srv_phb_mem_malloc(sizeof(mmi_phb_select_image_struct), SRV_PHB_MEMORY_TYPE_ADM);
    memset(user_data, 0, sizeof(mmi_phb_select_image_struct));

    if (type == CUI_PHB_SELECT_IMG_FROM_FILE)
    {
        user_data->type = CUI_PHB_SELECT_IMG_FROM_FILE;
    }
    else if (type == CUI_PHB_SELECT_IMG_CAMERA)
    {
        user_data->type = CUI_PHB_SELECT_IMG_CAMERA;
    }
    else
    {
        MMI_ASSERT(0);
    }
    
    sg_id = mmi_frm_group_create(
                    group_id,
                    GRP_ID_AUTO_GEN,
                    cui_phb_select_image_proc,
                    user_data);

    user_data->sg_id = sg_id;

    return sg_id;
}

void cui_phb_select_image_run(MMI_ID group_id)
{
    mmi_phb_select_image(group_id);
}

void cui_phb_select_image_close(MMI_ID sg_id)
{
    mmi_frm_group_close(sg_id);
}
#endif /* defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__) */
#endif
#endif /* __MMI_PHB_CALLER_RES__ */

#define CUI_PHB_CONTACT_LIST


/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_create_cntx
 * DESCRIPTION
 *  Phonebook Cui - select a contact: create cntx
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_phb_list_cntx_struct*
 *****************************************************************************/
mmi_phb_list_cntx_struct* cui_phb_list_select_contact_create_cntx(U8 list_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_list_cntx_struct *list_cntx;
#ifdef __MMI_SNS_CONTACTS__
    CHAR* sns_favorite;
    U32 i;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_CUI_PHB_LIST_CREATE_CNTX);

    list_cntx = (mmi_phb_list_cntx_struct *) srv_phb_mem_malloc(sizeof(mmi_phb_list_cntx_struct), SRV_PHB_MEMORY_TYPE_ADM);
    
    /**
     * init contact list cntx
     */
    memset(list_cntx, 0, sizeof(mmi_phb_list_cntx_struct));

    list_cntx->contact_array = (U16 *) srv_phb_mem_malloc(sizeof(U16) * MMI_PHB_ENTRIES ,SRV_PHB_MEMORY_TYPE_ADM);

    /**
     * set init value
     */
    list_cntx->storage = (U8) mmi_phb_get_preferred_storage();
    list_cntx->filter = MMI_PHB_LIST_DFAULT_FILTER;
    list_cntx->select_count = 0xffff;
    list_cntx->group_filter.group_mask = 0xffff;

    if (list_type == MMI_PHB_LIST_TYPE_MULTI_SELECT || list_type == MMI_PHB_LIST_TYPE_MULTI_SELECT_AND_GROUP)
    {
        list_cntx->mark_array = (U16 *) srv_phb_mem_malloc(sizeof(U16) * MMI_PHB_ENTRIES ,SRV_PHB_MEMORY_TYPE_ADM);
        list_cntx->mark_field = (U8 *) srv_phb_mem_malloc(sizeof(U8) * MMI_PHB_ENTRIES ,SRV_PHB_MEMORY_TYPE_ADM);

        memset(list_cntx->mark_array, 0, sizeof(U16) * MMI_PHB_ENTRIES);
        memset(list_cntx->mark_field, 0, sizeof(U8) * MMI_PHB_ENTRIES);
    }

    if (list_type == MMI_PHB_LIST_TYPE_MULTI_SELECT_AND_GROUP)
    {
        list_cntx->group_array = (U8*) srv_phb_mem_malloc(sizeof(U8) * MMI_PHB_GROUP_TOTAL_COUNT, SRV_PHB_MEMORY_TYPE_ADM);
    }

#ifdef __MMI_SNS_CONTACTS__
    if (list_type == MMI_PHB_LIST_TYPE_SINGLE_SELECT)
    {
    	list_cntx->sns_friend_list = (mmi_phb_sns_friend_list_struct*)srv_phb_mem_malloc(sizeof(mmi_phb_sns_friend_list_struct), SRV_PHB_MEMORY_TYPE_CTR);
    	memset(list_cntx->sns_friend_list, 0, sizeof(mmi_phb_sns_friend_list_struct));
    	list_cntx->sns_favorite_list = (mmi_phb_sns_favorite_list_struct*)srv_phb_mem_malloc(sizeof(mmi_phb_sns_favorite_list_struct), SRV_PHB_MEMORY_TYPE_CTR);
    	memset(list_cntx->sns_favorite_list, 0, sizeof(mmi_phb_sns_favorite_list_struct));
        sns_favorite = (CHAR*)srv_phb_mem_malloc(sizeof(CHAR) * MMI_PHB_SNS_FAVORITE_MAX_NUM * SRV_SNS_MAX_LEN_ID, SRV_PHB_MEMORY_TYPE_ADM);
        memset(sns_favorite, 0, sizeof(CHAR) * MMI_PHB_SNS_FAVORITE_MAX_NUM * SRV_SNS_MAX_LEN_ID);
        for (i = 0; i < MMI_PHB_SNS_FAVORITE_MAX_NUM; i++)
        {
            list_cntx->sns_favorite[i] = &(sns_favorite[SRV_SNS_MAX_LEN_ID * i]);
        }
    }
#endif
    
    return list_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_release_cntx
 * DESCRIPTION
 *  Phonebook Cui - select contact list, release cntx
 * PARAMETERS
 *  phb_select_sg_id                       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_phb_list_select_contact_release_cntx(mmi_phb_list_cntx_struct *list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SNS_CONTACTS__
    CHAR* sns_favorite;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG1(TRC_CUI_PHB_LIST_RELEASE_CNTX, list_cntx->sg_id);

    if (list_cntx != NULL)
    {
        if (list_cntx->contact_array != NULL)
        {
            srv_phb_mem_free(list_cntx->contact_array);
            list_cntx->contact_array = NULL;
        }
        if (list_cntx->mark_array != NULL)
        {
            srv_phb_mem_free(list_cntx->mark_array);
            list_cntx->mark_array = NULL;
        }
        if (list_cntx->mark_field != NULL)
        {
            srv_phb_mem_free(list_cntx->mark_field);
            list_cntx->mark_field = NULL;
        }
        if (list_cntx->group_array != NULL)
        {
            srv_phb_mem_free(list_cntx->group_array);
            list_cntx->group_array = NULL;
        }
    #ifdef __MMI_SNS_CONTACTS__
    	if (list_cntx->sns_friend_list != NULL)
    	{
            srv_sns_release_list(list_cntx->sns_friend_list->list_id, MMI_TRUE);
    	    srv_phb_mem_free(list_cntx->sns_friend_list);
            list_cntx->sns_friend_list = NULL;
    	}
    	if (list_cntx->sns_favorite_list != NULL)
    	{
            srv_sns_release_list(list_cntx->sns_favorite_list->list_id, MMI_TRUE);
    	    srv_phb_mem_free(list_cntx->sns_favorite_list);
            list_cntx->sns_favorite_list = NULL;
    	}
        sns_favorite = list_cntx->sns_favorite[0];
        if (sns_favorite != NULL)
        {
            srv_phb_mem_free(sns_favorite);
        }
    #endif
        srv_phb_mem_free(list_cntx);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_create
 * DESCRIPTION
 *  Phonebook Cui - select a contact from contact list
 * PARAMETERS
 *  parent_id                 :       [IN]          Caller screen group id
 * RETURNS
 *  mmi_id
 *****************************************************************************/
mmi_id cui_phb_list_select_contact_create(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;    
    mmi_phb_list_cntx_struct *list_cntx;
    mmi_id sg_id = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_CUI_PHB_LIST_SELECT_CONTACT_CREATE);
    
    //if (mmi_phb_check_ready(MMI_TRUE))
    {
        handle = mmi_phb_cntx_mgr_create_handle(MMI_PHB_SG_CUI_LIST);
        sg_id = mmi_phb_cntx_mgr_get_sg_id(handle);
        mmi_phb_cntx_mgr_set_parent_id(handle, parent_id);
        list_cntx = cui_phb_list_select_contact_create_cntx(MMI_PHB_LIST_TYPE_SINGLE_SELECT);

        list_cntx->sg_id = sg_id;
        list_cntx->parent_id = parent_id;
        mmi_phb_cntx_mgr_set_data(handle, list_cntx);

        mmi_frm_group_create(parent_id, sg_id, cui_phb_list_select_contact_proc, list_cntx);
    }

    return sg_id;
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_set_cntx
 * DESCRIPTION
 *  Phonebook Cui - select list contact, set list cntx
 * PARAMETERS
 *  list_cntx          :         [IN]       List cntx
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_list_select_contact_set_cntx(mmi_phb_list_cntx_struct *list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_CUI_PHB_LIST_SELECT_CONTACT_SET_CNTX);

    g_mmi_phb_list_p = list_cntx;
}

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
void cui_phb_list_select_contact_set_user_data(mmi_id phb_select_sg_id, U32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_list_cntx_struct *list_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_select_sg_id);
    list_cntx = (mmi_phb_list_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);

    list_cntx->user_data = user_data;
}

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
U32 cui_phb_list_select_contact_get_user_data(mmi_id phb_select_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_list_cntx_struct *list_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_select_sg_id);
    list_cntx = (mmi_phb_list_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);

    return list_cntx->user_data;
}


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
void cui_phb_list_select_contact_set_field_filter(mmi_id phb_select_sg_id, U32 filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_list_cntx_struct *list_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG2(TRC_CUI_PHB_LIST_SELECT_CONTACT_SET_FILTER, phb_select_sg_id, filter);
    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_select_sg_id);
    list_cntx = (mmi_phb_list_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);

    /**
     * reset email field
     */
    if (filter & SRV_PHB_ENTRY_FIELD_GSM_NUM)
    {
        filter |= SRV_PHB_ENTRY_FIELD_GSM_NUM;
    }
    if (filter & SRV_PHB_ENTRY_FIELD_EMAIL)
    {
        filter |= SRV_PHB_ENTRY_FIELD_EMAIL;
    }
	list_cntx->filter = filter;
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_set_storage
 * DESCRIPTION
 *  Phonebook Cui - select list contact, set contact's storage
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 *  storage                   :         [IN]       phonebook storage, default is preffered storage
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_list_select_contact_set_storage(mmi_id phb_select_sg_id, U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_list_cntx_struct *list_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG2(TRC_CUI_PHB_LIST_SELECT_CONTACT_SET_STORAGE, phb_select_sg_id, storage);
    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_select_sg_id);
    list_cntx = (mmi_phb_list_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);

    list_cntx->storage = storage;
}


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
void cui_phb_list_select_contact_set_widget(mmi_id phb_select_sg_id, MMI_BOOL is_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_list_cntx_struct *list_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_select_sg_id);
    list_cntx = (mmi_phb_list_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);
    list_cntx->is_widget = is_set;
}
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
void cui_phb_list_select_contact_set_ncenter(mmi_id phb_select_sg_id, MMI_BOOL is_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_list_cntx_struct *list_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_select_sg_id);
    list_cntx = (mmi_phb_list_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);
    list_cntx->is_disable_ncenter = is_set;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_set_group
 * DESCRIPTION
 *  Phonebook Cui - select list contact, set caller group id
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 *  group_id                  :         [IN]       Caller group id. for show caller group member list
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_list_select_contact_set_group(mmi_id phb_select_sg_id, U8 group_id, MMI_BOOL is_equal)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_list_cntx_struct *list_cntx;  
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG2(TRC_CUI_PHB_LIST_SELECT_CONTACT_SET_GROUP, phb_select_sg_id, group_id);
    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_select_sg_id);
    list_cntx = (mmi_phb_list_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);
    list_cntx->group_id = group_id;
    
#if defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__) || defined (__MMI_PHB_USIM_GROUP_SUPPORT__)
    if (group_id >= MMI_PHB_GROUP_COUNT + MMI_PHB_GROUP_USIM_COUNT)
    {
        group_id -= MMI_PHB_GROUP_COUNT + MMI_PHB_GROUP_USIM_COUNT;
    }
#ifdef __MMI_PHB_USIM_GROUP_SUPPORT__
    else if (group_id >= MMI_PHB_GROUP_COUNT)
    {
        group_id = (group_id - MMI_PHB_GROUP_COUNT) % MMI_PHB_MAX_GAS_COUNT;
    }
#endif
#endif
    
    list_cntx->group_filter.group_mask = (U32)(1 << group_id);
    list_cntx->group_filter.is_equal = is_equal;
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_get_parent_group
 * DESCRIPTION
 *  Phonebook Cui - select list contact, set caller group id
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 *  group_id                  :         [IN]       Caller group id. for show caller group member list
 * RETURNS
 *  void
 *****************************************************************************/
mmi_id cui_phb_list_select_contact_get_parent_group(mmi_id phb_select_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_list_cntx_struct *list_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_select_sg_id);
    list_cntx = (mmi_phb_list_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);
    
    return list_cntx->parent_id;
}



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
void cui_phb_list_select_contact_set_lsk(mmi_id phb_select_sg_id, U16 icon, U16 label)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_list_cntx_struct *list_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_select_sg_id);
    list_cntx = (mmi_phb_list_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);

    list_cntx->lsk_img = icon;
    list_cntx->lsk_label = label;
}


void cui_phb_list_contact_set_first_highlight_index(mmi_id phb_select_sg_id, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_list_cntx_struct *list_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_select_sg_id);
    list_cntx = (mmi_phb_list_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);

    list_cntx->list_index = index;
}



/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_entry
 * DESCRIPTION
 *  Phonebook Cui - select a contact, entry screen
 * PARAMETERS
 *  phb_select_sg_id                   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_list_select_contact_entry(mmi_id phb_select_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;    
    }
        
    mmi_phb_list_select_entry();
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_proc
 * DESCRIPTION
 *  Phonebook Cui - select contact list: proc function
 * PARAMETERS
 *  evt                   [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret cui_phb_list_select_contact_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_list_cntx_struct *list_cntx;
#if defined(__MMI_PHB_MULTI_OPERATION__)
    mmi_ret menu_cui_proc;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_cntx = (mmi_phb_list_cntx_struct *) evt->user_data;
    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(list_cntx->sg_id);

#if defined(__MMI_PHB_MULTI_OPERATION__)
    menu_cui_proc = mmi_phb_mark_several_menu_cui_proc(evt);
    if (menu_cui_proc == MMI_RET_OK)
    {
        return MMI_RET_OK;
    }
#endif

    switch (evt->evt_id)
    {
        case EVT_ID_SCENAIO_CHANGE:
        case EVT_ID_GROUP_FIRST_ENTRY:
            break;
            
        case EVT_ID_GROUP_INACTIVE:
        {
            if (!list_cntx->evt_out && mmi_frm_scrn_get_count(list_cntx->sg_id) == 0)
            {
                cui_phb_select_contact_result_struct evt;

                evt.evt_id = EVT_ID_PHB_SELECT_CONTACT_CANCEL;
                evt.size = sizeof(cui_phb_select_contact_result_struct);
                evt.user_data = NULL;
                evt.sender_id = list_cntx->sg_id;
                list_cntx->evt_out = MMI_TRUE;
                
                mmi_phb_cntx_mgr_post_evt(list_cntx->sg_id, MMI_FALSE, (mmi_event_struct*)&evt);
            }
            
            break;
        }
        case EVT_ID_GROUP_ACTIVE:
            cui_phb_list_select_contact_set_cntx(list_cntx);
            break;
            
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
            break;
            
        case EVT_ID_GROUP_DEINIT:
            cui_phb_list_select_contact_release_cntx(list_cntx);
            mmi_phb_cntx_mgr_release_handle(handle);
            break;
            
        case EVT_ID_GROUP_FOCUSED:
        case EVT_ID_GROUP_REDRAW_START:
            cui_phb_list_select_contact_set_cntx(list_cntx);
            break;
            
        case EVT_ID_POPUP_QUIT:
        {
            mmi_phb_sg_data_struct *instance;
            
            instance = mmi_phb_cntx_mgr_get_instance(list_cntx->sg_id);

            if (instance && instance->delay_event)
            {
                list_cntx->evt_out = MMI_TRUE;
                mmi_phb_cntx_mgr_post_evt(list_cntx->sg_id, MMI_FALSE, instance->delay_event);
            }
            
            break;
        }
    #if defined(__MMI_VCARD__) && defined(__MMI_OPP_SUPPORT__)
        case EVT_ID_VCARD_CANCEL:
        case EVT_ID_VCARD_DONE:
            cui_vcard_multi_send_close(((cui_vcard_result_struct*)evt)->sender_id);
            mmi_frm_group_close(list_cntx->sg_id);
            break;
    #endif /* defined(__MMI_VCARD__) && defined(__MMI_OPP_SUPPORT__) */

    #if defined(__MMI_MULTI_VCARD__)
        case EVT_ID_VCARD_EXPORT_CANCEL:
        case EVT_ID_VCARD_EXPORT_DONE:
            cui_vcard_export_vcard_close(((cui_vcard_result_struct*)evt)->sender_id);
            mmi_frm_group_close(list_cntx->sg_id);
            break;
    #endif /* defined(__MMI_MULTI_VCARD__) */

    #ifdef __MMI_NCENTER_SUPPORT__
        case EVT_ID_VAPP_NCENTER_DRAG:
            if (list_cntx->is_disable_ncenter)
    	    {
    	        return MMI_RET_ERR;
    	    }
            break;
    #endif
    
        default:
            break;
    }
 
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_select_contact_proc
 * DESCRIPTION
 *  Phonebook group - select contact list: proc function
 * PARAMETERS
 *  evt                   [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret cui_phb_list_select_group_member_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_list_cntx_struct *list_cntx;
#if defined(__MMI_PHB_GENERIC_MULTI_SELECT__)
    mmi_ret menu_cui_proc;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_cntx = (mmi_phb_list_cntx_struct *) evt->user_data;
    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(list_cntx->sg_id);

#if defined(__MMI_PHB_GENERIC_MULTI_SELECT__) && defined(__MMI_PHB_CALLER_GROUP__)
    menu_cui_proc = mmi_phb_group_member_ms_menu_cui_proc(evt);
    if (menu_cui_proc == MMI_RET_OK)
    {
        return MMI_RET_OK;
    }
#endif   

    switch (evt->evt_id)
    {   
        case EVT_ID_GROUP_INACTIVE:
        {
            if (!list_cntx->evt_out && mmi_frm_scrn_get_count(list_cntx->sg_id) == 0)
            {
                cui_phb_select_contact_result_struct evt;

                evt.evt_id = EVT_ID_PHB_SELECT_CONTACT_CANCEL;
                evt.size = sizeof(cui_phb_select_contact_result_struct);
                evt.user_data = NULL;
                evt.sender_id = list_cntx->sg_id;
                list_cntx->evt_out = MMI_TRUE;
                
                mmi_phb_cntx_mgr_post_evt(list_cntx->sg_id, MMI_FALSE, (mmi_event_struct*)&evt);
            }
            
            break;
        }
        
        case EVT_ID_GROUP_ACTIVE:
        case EVT_ID_GROUP_FOCUSED:
        case EVT_ID_GROUP_REDRAW_START:
            cui_phb_list_select_contact_set_cntx(list_cntx);
            break;           
            
        case EVT_ID_GROUP_DEINIT:
            cui_phb_list_select_contact_release_cntx(list_cntx);
            mmi_phb_cntx_mgr_release_handle(handle);
            break;
                       
        default:
            break;
    }
 
    return MMI_RET_OK;
}


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
void cui_phb_list_select_contact_run(mmi_id phb_select_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_list_cntx_struct *list_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG1(TRC_CUI_PHB_LIST_SELECT_CONTACT_RUN, phb_select_sg_id);

    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_select_sg_id);
    list_cntx = mmi_phb_cntx_mgr_get_data(handle);

    cui_phb_list_select_contact_set_cntx(list_cntx);

    mmi_frm_group_enter(phb_select_sg_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_phb_list_select_contact_entry(phb_select_sg_id);
}


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
void cui_phb_list_select_contact_close(mmi_id phb_select_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(phb_select_sg_id);
}


#define CUI_PHB_SEARCH_CONTACT
#if defined(__MMI_PHB_GENERIC_MULTI_SELECT__)
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
void cui_phb_search_contact_init(cui_phb_search_contact_struct *search)
{
    search->search_style = CUI_PHB_SEARCH_CONTACT_CONTAIN;
    search->search_field = CUI_PHB_SEARCH_CONTACT_NAME;
    search->search_data = NULL;
    search->length = 0;
    search->get_field = SRV_PHB_ENTRY_FIELD_GSM_NUM;
}


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
void cui_phb_search_contact_get_data(MMI_ID group_id, U16 id, U32 field_mask, U16 *buf, U16 buf_length, MMI_BOOL more)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (field_mask == SRV_PHB_ENTRY_FIELD_NUMBER)
    {
        srv_phb_get_number(id, buf, buf_length);
    }
#ifdef __MMI_PHB_OPTIONAL_FIELD__    
    else if (field_mask == SRV_PHB_ENTRY_FIELD_OPT_NUM_1
        || field_mask == SRV_PHB_ENTRY_FIELD_OPT_NUM_2
        || field_mask == SRV_PHB_ENTRY_FIELD_OPT_NUM_3)
    {
        srv_phb_get_optional_number(id, field_mask, buf, NULL, buf_length);
    }
    else if (field_mask == SRV_PHB_ENTRY_FIELD_EMAIL1)
    {
        srv_phb_get_email_address(id, buf, buf_length);
    }
#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__    
    else if (field_mask == SRV_PHB_ENTRY_FIELD_EMAIL2)
    {
        srv_phb_get_email_address2(id, buf, buf_length);
    }
#endif    
#endif
    else
    {
        *buf = 0;
    }

    if (more)
    {
        mmi_phb_search_contact_continue(group_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_multi_select_contact_proc
 * DESCRIPTION
 *  Phonebook Cui - select contacts list: proc function
 * PARAMETERS
 *  evt                   [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret cui_phb_search_contact_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_list_cntx_struct *list_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_cntx = (mmi_phb_list_cntx_struct *) evt->user_data;
    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(list_cntx->sg_id);

    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_FIRST_ENTRY:
            break;
            
        case EVT_ID_GROUP_INACTIVE:
            break;
            
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
        {
            cui_phb_search_contact_result_struct evt;

            evt.evt_id = EVT_ID_PHB_SEARCH_CONTACT_QUIT_BY_END_KEY;
            evt.size = sizeof(cui_phb_search_contact_result_struct);
            evt.user_data = NULL;
            evt.sender_id = list_cntx->sg_id;
            list_cntx->evt_out = MMI_TRUE;
            
            mmi_phb_cntx_mgr_post_evt(list_cntx->sg_id, MMI_FALSE, (mmi_event_struct*)&evt);
            break;
        }
        
        case EVT_ID_GROUP_ACTIVE:            
            cui_phb_list_select_contact_set_cntx(list_cntx);
            break;
        
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
            break;
            
        case EVT_ID_GROUP_DEINIT:
            cui_phb_list_select_contact_release_cntx(list_cntx);
            mmi_phb_cntx_mgr_release_handle(handle);
            break;
            
        case EVT_ID_GROUP_FOCUSED:
        case EVT_ID_GROUP_REDRAW_START:
            cui_phb_list_select_contact_set_cntx(list_cntx);
            break;
            
        case EVT_ID_POPUP_QUIT:
        {
            mmi_phb_sg_data_struct *instance;
            
            instance = mmi_phb_cntx_mgr_get_instance(list_cntx->sg_id);

            if (instance && instance->delay_event)
            {
                list_cntx->evt_out = MMI_TRUE;
                mmi_phb_cntx_mgr_post_evt(list_cntx->sg_id, MMI_FALSE, instance->delay_event);
            }
            
            break;
        }

        default:
            break;
    }
 
    return MMI_RET_OK;
}


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
MMI_ID cui_phb_search_contact_create(MMI_ID parent_id, cui_phb_search_contact_struct *search)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;    
    mmi_phb_list_cntx_struct *list_cntx;
    mmi_id sg_id = GRP_ID_INVALID;
    U16 length = MMI_PHB_NAME_LENGTH;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if (mmi_phb_check_ready(TRUE))
    {
        MMI_ASSERT(search->search_style == CUI_PHB_SEARCH_CONTACT_CONTAIN && search->search_field == CUI_PHB_SEARCH_CONTACT_NAME);
    
        handle = mmi_phb_cntx_mgr_create_handle(MMI_PHB_SG_CUI_LIST_MULTI);
        sg_id = mmi_phb_cntx_mgr_get_sg_id(handle);
        mmi_phb_cntx_mgr_set_parent_id(handle, parent_id);
        list_cntx = cui_phb_list_select_contact_create_cntx(MMI_PHB_LIST_TYPE_MULTI_SELECT);

        list_cntx->sg_id = sg_id;
        list_cntx->parent_id = parent_id;
        list_cntx->filter = search->get_field;
        if (search->length < length)
        {
            length = search->length;
        }

        mmi_wcsncpy(list_cntx->qsearch_input_buffer, search->search_data, length);
        
        mmi_phb_cntx_mgr_set_data(handle, list_cntx);

        mmi_frm_group_create(parent_id, sg_id, cui_phb_search_contact_proc, list_cntx);
    }

    return sg_id;
}



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
void cui_phb_search_contact_pre_run(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_list_cntx_struct *list_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG1(TRC_CUI_PHB_LIST_SELECT_CONTACT_RUN, group_id);

    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(group_id);
    list_cntx = mmi_phb_cntx_mgr_get_data(handle);

    cui_phb_list_select_contact_set_cntx(list_cntx);
    
    mmi_frm_group_enter(group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_phb_search_contact_pre_run();
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_search_contact_run
 * DESCRIPTION
 *  Phonebook Cui - run the cui
 * PARAMETERS
 *  phb_select_sg_id                        [IN]    cui group id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_search_contact_run(MMI_ID phb_select_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_list_cntx_struct *list_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_select_sg_id);
    list_cntx = mmi_phb_cntx_mgr_get_data(handle);

    cui_phb_list_select_contact_set_cntx(list_cntx);
        
    mmi_phb_search_contact_run();
}



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
void cui_pbh_search_contact_close(MMI_ID group_id)
{
    mmi_frm_group_close(group_id);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_emit
 * DESCRIPTION
 *  Phonebook Cui - select list contact, done function, send result out
 * PARAMETERS
 *  parent_id          :      [IN]           Caller group id
 *  evt_id             :      [IN]           evt id
 *  result             :      [IN]           operation result
 *  store_index        :      [IN]           contact store index
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_list_select_contact_emit(
         mmi_id parent_id,
         U16 evt_id,
         U16 *name,
         U16 *select_data,
         U32 data_type,
         U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_phb_select_contact_result_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt.evt_id = evt_id;
    evt.size = sizeof(cui_phb_select_contact_result_struct);
    evt.sender_id = parent_id;
    evt.user_data = NULL;
    
    evt.name = name;
    evt.select_data = select_data;
    evt.store_index = store_index;
    evt.data_type = data_type;
    
    cui_phb_send_data_to_sa(parent_id, &evt);
}


void cui_phb_list_highlight_contact_emit(
        mmi_id parent_id,
        U16 evt_id,
        U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_phb_list_contact_highlight_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parent_id == GRP_ID_INVALID || parent_id == 0)
    {
        return;
    }
    
    evt.evt_id = evt_id;
    evt.size = sizeof(cui_phb_list_contact_highlight_struct);
    evt.sender_id = parent_id;
    
    evt.highlight_store_index = store_index;

    cui_phb_send_data_to_sa(parent_id, &evt);
}

#define CUI_PHB_CONTACT_LIST_MULTI

#ifdef __MMI_PHB_GENERIC_MULTI_SELECT__


/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_multi_select_contact_proc
 * DESCRIPTION
 *  Phonebook Cui - select contacts list: proc function
 * PARAMETERS
 *  evt                   [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret cui_phb_list_multi_select_contact_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_list_cntx_struct *list_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_cntx = (mmi_phb_list_cntx_struct *) evt->user_data;
    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(list_cntx->sg_id);

    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_FIRST_ENTRY:
            break;
            
        case EVT_ID_GROUP_INACTIVE:
        {
            if (!list_cntx->evt_out && mmi_frm_scrn_get_count(list_cntx->sg_id) == 0)
            {
                cui_phb_multi_select_contact_result_struct evt;

                evt.evt_id = EVT_ID_PHB_SELECT_MULTI_CONTACT_CANCEL;
                evt.size = sizeof(cui_phb_multi_select_contact_result_struct);
                evt.user_data = NULL;
                evt.sender_id = list_cntx->sg_id;
                list_cntx->evt_out = MMI_TRUE;
                
                mmi_phb_cntx_mgr_post_evt(list_cntx->sg_id, MMI_FALSE, (mmi_event_struct*)&evt);
            }
            break;
        }
        
        case EVT_ID_GROUP_ACTIVE:            
            cui_phb_list_select_contact_set_cntx(list_cntx);
            break;
        
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
            break;
            
        case EVT_ID_GROUP_DEINIT:
            cui_phb_list_select_contact_release_cntx(list_cntx);
            mmi_phb_cntx_mgr_release_handle(handle);
            break;
            
        case EVT_ID_GROUP_FOCUSED:
        case EVT_ID_GROUP_REDRAW_START:
            cui_phb_list_select_contact_set_cntx(list_cntx);
            break;
            
        case EVT_ID_POPUP_QUIT:
        {
            mmi_phb_sg_data_struct *instance;
            
            instance = mmi_phb_cntx_mgr_get_instance(list_cntx->sg_id);

            if (instance && instance->delay_event)
            {
                list_cntx->evt_out = MMI_TRUE;
                mmi_phb_cntx_mgr_post_evt(list_cntx->sg_id, MMI_FALSE, instance->delay_event);
            }
            
            break;
        }

        default:
            break;
    }
 
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_multi_select_contact_create
 * DESCRIPTION
 *  Phonebook Cui - multi select contact create function
 * PARAMETERS
 *  parent_id          :         [IN]       Caller screen group id
 * RETURNS
 *  mmi_id
 *****************************************************************************/
mmi_id cui_phb_list_multi_select_contact_create(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;    
    mmi_phb_list_cntx_struct *list_cntx;
    mmi_id sg_id = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if (mmi_phb_check_ready(TRUE))
    {
        handle = mmi_phb_cntx_mgr_create_handle(MMI_PHB_SG_CUI_LIST_MULTI);
        sg_id = mmi_phb_cntx_mgr_get_sg_id(handle);
        mmi_phb_cntx_mgr_set_parent_id(handle, parent_id);
        list_cntx = cui_phb_list_select_contact_create_cntx(MMI_PHB_LIST_TYPE_MULTI_SELECT);

        list_cntx->sg_id = sg_id;
        list_cntx->parent_id = parent_id;
        
        mmi_phb_cntx_mgr_set_data(handle, list_cntx);

        mmi_frm_group_create(parent_id, sg_id, cui_phb_list_multi_select_contact_proc, list_cntx);
    }

    return sg_id;

}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_multi_select_contact_entry
 * DESCRIPTION
 *  Phonebook Cui - multi select contact, entry funtion
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_list_multi_select_contact_entry(mmi_id phb_select_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;    
    }

    mmi_phb_entry_generic_mark_several();
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_set_count
 * DESCRIPTION
 *  Phonebook Cui - multi select contact set max select count
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 *  select_count                 :         [IN]       max select count
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_list_select_contact_set_count(mmi_id phb_select_sg_id, U16 select_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_list_cntx_struct *list_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_select_sg_id);
    list_cntx = (mmi_phb_list_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);

    list_cntx->select_count = select_count;

}


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
void cui_phb_list_multi_select_contact_run(mmi_id phb_select_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_list_cntx_struct *list_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG1(TRC_CUI_PHB_LIST_SELECT_CONTACT_RUN, phb_select_sg_id);

    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_select_sg_id);
    list_cntx = mmi_phb_cntx_mgr_get_data(handle);

    cui_phb_list_select_contact_set_cntx(list_cntx);
    
    mmi_frm_group_enter(phb_select_sg_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    cui_phb_list_multi_select_contact_entry(phb_select_sg_id);
}


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
void cui_phb_list_multi_select_contact_close(mmi_id phb_select_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(phb_select_sg_id);
}
#ifndef __MMI_MAINLCD_96X64__

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_group_select_contact_proc
 * DESCRIPTION
 *  Phonebook Cui - tab select contacts list: proc function
 * PARAMETERS
 *  evt                   [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret cui_phb_list_group_select_contact_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_list_cntx_struct *list_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_cntx = (mmi_phb_list_cntx_struct *) evt->user_data;
    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(list_cntx->sg_id);

    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_FIRST_ENTRY:
            break;
            
        case EVT_ID_GROUP_INACTIVE:
        {
            if (!list_cntx->evt_out && mmi_frm_scrn_get_count(list_cntx->sg_id) == 0)
            {
                cui_phb_multi_select_contact_result_struct evt;

                evt.evt_id = EVT_ID_PHB_SELECT_MULTI_CONTACT_CANCEL;
                evt.size = sizeof(cui_phb_multi_select_contact_result_struct);
                evt.user_data = NULL;
                evt.sender_id = list_cntx->sg_id;
                list_cntx->evt_out = MMI_TRUE;
                
                mmi_phb_cntx_mgr_post_evt(list_cntx->sg_id, MMI_FALSE, (mmi_event_struct*)&evt);
            }
            break;
        }
        
        case EVT_ID_GROUP_ACTIVE:
            cui_phb_list_select_contact_set_cntx(list_cntx);
            break;
            
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
            break;
            
        case EVT_ID_GROUP_DEINIT:
            cui_phb_list_select_contact_release_cntx(list_cntx);
            mmi_phb_cntx_mgr_release_handle(handle);
            break;

        case EVT_ID_GROUP_FOCUSED:
        case EVT_ID_GROUP_REDRAW_START:
            cui_phb_list_select_contact_set_cntx(list_cntx);
            break;

        case EVT_ID_POPUP_QUIT:
        {
            mmi_phb_sg_data_struct *instance;
            
            instance = mmi_phb_cntx_mgr_get_instance(list_cntx->sg_id);

            if (instance && instance->delay_event)
            {
                list_cntx->evt_out = MMI_TRUE;
                mmi_phb_cntx_mgr_post_evt(list_cntx->sg_id, MMI_FALSE, instance->delay_event);
            }
            
            break;
        }

        default:
            break;
    }
 
    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_group_select_contact_create
 * DESCRIPTION
 *  Phonebook Cui - tab multi select contact, create function
 * PARAMETERS
 *  parent_id          :         [IN]       Caller screen group id
 * RETURNS
 *  mmi_id
 *****************************************************************************/
mmi_id cui_phb_list_group_select_contact_create(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;    
    mmi_phb_list_cntx_struct *list_cntx;
    mmi_id sg_id = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if (mmi_phb_check_ready(TRUE))
    {
        handle = mmi_phb_cntx_mgr_create_handle(MMI_PHB_SG_CUI_LIST_GROUP_TAB);
        sg_id = mmi_phb_cntx_mgr_get_sg_id(handle);
        mmi_phb_cntx_mgr_set_parent_id(handle, parent_id);
        list_cntx = cui_phb_list_select_contact_create_cntx(MMI_PHB_LIST_TYPE_MULTI_SELECT_AND_GROUP);

        list_cntx->sg_id = sg_id;
        list_cntx->parent_id = parent_id;
        
        mmi_phb_cntx_mgr_set_data(handle, list_cntx);

        mmi_frm_group_create(parent_id, sg_id, cui_phb_list_group_select_contact_proc, list_cntx);
    }

    return sg_id;

}



/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_group_select_contact_entry
 * DESCRIPTION
 *  Phonebook Cui - tab multi select contact, entry function
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_list_group_select_contact_entry(mmi_id phb_select_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;    
    }

    mmi_phb_entry_generic_mark_several_tab();
}




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
void cui_phb_list_group_select_contact_run(mmi_id phb_select_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_list_cntx_struct *list_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG1(TRC_CUI_PHB_LIST_SELECT_CONTACT_RUN, phb_select_sg_id);

    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_select_sg_id);

    list_cntx = mmi_phb_cntx_mgr_get_data(handle);
    cui_phb_list_select_contact_set_cntx(list_cntx);
    
    mmi_frm_group_enter(phb_select_sg_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    cui_phb_list_group_select_contact_entry(phb_select_sg_id);
}



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
void cui_phb_list_group_select_contact_close(mmi_id phb_select_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(phb_select_sg_id);
}

#else

#ifdef __MMI_PHB_CALLER_GROUP__

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_group_select_contact_proc
 * DESCRIPTION
 *  Phonebook Cui - tab select contacts list: proc function
 * PARAMETERS
 *  evt                   [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret cui_phb_list_group_select_contact_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_list_cntx_struct *list_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_cntx = (mmi_phb_list_cntx_struct *) evt->user_data;
    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(list_cntx->sg_id);

    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_FIRST_ENTRY:
            break;
            
        case EVT_ID_GROUP_INACTIVE:
        {
            if (!list_cntx->evt_out && mmi_frm_scrn_get_count(list_cntx->sg_id) == 0)
            {
                cui_phb_multi_select_contact_result_struct evt;

                evt.evt_id = EVT_ID_PHB_SELECT_MULTI_CONTACT_CANCEL;
                evt.size = sizeof(cui_phb_multi_select_contact_result_struct);
                evt.user_data = NULL;
                evt.sender_id = list_cntx->sg_id;
                list_cntx->evt_out = MMI_TRUE;
                
                mmi_phb_cntx_mgr_post_evt(list_cntx->sg_id, MMI_FALSE, (mmi_event_struct*)&evt);
            }
            break;
        }
        
        case EVT_ID_GROUP_ACTIVE:
            cui_phb_list_select_contact_set_cntx(list_cntx);
            break;
            
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
            break;
            
        case EVT_ID_GROUP_DEINIT:
            cui_phb_list_select_contact_release_cntx(list_cntx);
            mmi_phb_cntx_mgr_release_handle(handle);
            break;

        case EVT_ID_GROUP_FOCUSED:
        case EVT_ID_GROUP_REDRAW_START:
            cui_phb_list_select_contact_set_cntx(list_cntx);
            break;

        case EVT_ID_POPUP_QUIT:
        {
            mmi_phb_sg_data_struct *instance;
            
            instance = mmi_phb_cntx_mgr_get_instance(list_cntx->sg_id);

            if (instance && instance->delay_event)
            {
                list_cntx->evt_out = MMI_TRUE;
                mmi_phb_cntx_mgr_post_evt(list_cntx->sg_id, MMI_FALSE, instance->delay_event);
            }
            
            break;
        }

        default:
            break;
    }
 
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_group_select_contact_create
 * DESCRIPTION
 *  Phonebook Cui - tab multi select contact, create function
 * PARAMETERS
 *  parent_id          :         [IN]       Caller screen group id
 * RETURNS
 *  mmi_id
 *****************************************************************************/
mmi_id cui_phb_list_group_select_contact_create(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;    
    mmi_phb_list_cntx_struct *list_cntx;
    mmi_id sg_id = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if (mmi_phb_check_ready(TRUE))
    {
        handle = mmi_phb_cntx_mgr_create_handle(MMI_PHB_SG_CUI_LIST_GROUP_TAB);
        sg_id = mmi_phb_cntx_mgr_get_sg_id(handle);
        mmi_phb_cntx_mgr_set_parent_id(handle, parent_id);
        list_cntx = cui_phb_list_select_contact_create_cntx(MMI_PHB_LIST_TYPE_MULTI_SELECT_AND_GROUP);

        list_cntx->sg_id = sg_id;
        list_cntx->parent_id = parent_id;
        
        mmi_phb_cntx_mgr_set_data(handle, list_cntx);

        mmi_frm_group_create(parent_id, sg_id, cui_phb_list_group_select_contact_proc, list_cntx);
    }

    return sg_id;

}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_group_select_contact_entry
 * DESCRIPTION
 *  Phonebook Cui - tab multi select contact, entry function
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_list_group_select_contact_entry(mmi_id phb_select_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;    
    }

    mmi_phb_entry_generic_mark_several_tab();
}


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
void cui_phb_list_group_select_contact_run(mmi_id phb_select_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_list_cntx_struct *list_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG1(TRC_CUI_PHB_LIST_SELECT_CONTACT_RUN, phb_select_sg_id);

    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_select_sg_id);

    list_cntx = mmi_phb_cntx_mgr_get_data(handle);
    cui_phb_list_select_contact_set_cntx(list_cntx);
    
    mmi_frm_group_enter(phb_select_sg_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    cui_phb_list_group_select_contact_entry(phb_select_sg_id);
}


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
void cui_phb_list_group_select_contact_close(mmi_id phb_select_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(phb_select_sg_id);
}
#endif
#endif

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_group_select_contact_emit
 * DESCRIPTION
 *  Phonebook Cui - tab multi select contact, emit event
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_list_multi_select_contact_emit(
         mmi_id parent_id,
         U16 evt_id,
         U16 count,
         U16 *store_index,
         U8 *field_index,
         MMI_BOOL is_group)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_phb_multi_select_contact_result_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt.evt_id = evt_id;
    evt.size = sizeof(cui_phb_multi_select_contact_result_struct);
    evt.sender_id = parent_id;
    evt.user_data = NULL;
    
    evt.count = count;
    evt.store_index = store_index;
    evt.field = field_index;
    evt.is_group = is_group;
    
    cui_phb_send_data_to_sa(parent_id, &evt);
}
#endif /* __MMI_PHB_GENERIC_MULTI_SELECT__ */

#define CUI_PHB_VIEW_CONTACT


/*****************************************************************************
 * FUNCTION
 *  cui_phb_view_contact_create_cntx
 * DESCRIPTION
 *  Phonebook Cui - create view contact cntx
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_phb_view_contact_cntx_struct* cui_phb_view_contact_create_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_view_contact_cntx_struct *view_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    view_cntx = (mmi_phb_view_contact_cntx_struct *) srv_phb_mem_malloc(sizeof(mmi_phb_view_contact_cntx_struct), SRV_PHB_MEMORY_TYPE_ADM);
    
    /**
     * init contact list cntx
     */
    memset(view_cntx, 0, sizeof(mmi_phb_view_contact_cntx_struct));

    view_cntx->store_index = MMI_PHB_STORE_INDEX_INVALID;
    view_cntx->first_highlight_type = 0xff;
    
    /**
     * malloc contact buffer for displaying
     */
    view_cntx->contact = (mmi_phb_contact_info_struct *) srv_phb_mem_malloc(sizeof(mmi_phb_contact_info_struct), SRV_PHB_MEMORY_TYPE_ADM);
    memset(view_cntx->contact, 0, sizeof(mmi_phb_contact_info_struct));

    /**
     * malloc contact resource buffer
     */
    view_cntx->res = (mmi_phb_caller_res_struct *) srv_phb_mem_malloc(sizeof(mmi_phb_caller_res_struct), SRV_PHB_MEMORY_TYPE_ADM);

    return view_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_view_contact_release_cntx
 * DESCRIPTION
 *  Phonebook Cui - release view contact cntx
 * PARAMETERS
 *  phb_view_sg_id                   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_phb_view_contact_release_cntx(mmi_id phb_view_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_view_contact_cntx_struct *view_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_view_sg_id);
    view_cntx = (mmi_phb_view_contact_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);

    if (view_cntx != NULL)
    {
        if (view_cntx->contact != NULL)
        {
            srv_phb_mem_free(view_cntx->contact);
            view_cntx->contact = NULL;
        }

        if (view_cntx->res != NULL)
        {
            srv_phb_mem_free(view_cntx->res);
            view_cntx->res = NULL;
        }

#ifdef __MMI_SNS_CONTACTS__
        if (view_cntx->list_id > 0)
        {
            srv_sns_release_list(view_cntx->list_id, MMI_TRUE);  
        }
#endif
        srv_phb_mem_free(view_cntx);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_view_contact_set_cntx
 * DESCRIPTION
 *  Phonebook Cui - set view contact cntx
 * PARAMETERS
 *  view_cntx                 :       [IN]          cui view contact cntx
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_phb_view_contact_set_cntx(mmi_phb_view_contact_cntx_struct *view_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_CUI_PHB_VIEW_CONTACT_SET_CNTX);
    
    mmi_phb_contact_get_contact_info(view_cntx->store_index, view_cntx->contact);

    view_cntx->field_mask |= SRV_PHB_ENTRY_FIELD_NAME | SRV_PHB_ENTRY_FIELD_NUMBER;

#ifdef __MMI_PHB_CALLER_RES__
    mmi_phb_contact_res_value_assign(view_cntx->sg_id, view_cntx->res, view_cntx->contact);
#endif

    g_mmi_phb_contact_p = view_cntx->contact;
    g_mmi_phb_view_contact_p = view_cntx;
#ifdef __MMI_PHB_CALLER_RES__
    g_mmi_phb_res_p = view_cntx->res;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_view_contact_create
 * DESCRIPTION
 *  Phonebook Cui - view a contact
 * PARAMETERS
 *  parent_id             :      [IN]           Caller screen group id
 * RETURNS
 *  mmi_id
 *****************************************************************************/
mmi_id cui_phb_view_contact_create(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;    
    mmi_phb_view_contact_cntx_struct *view_cntx;
    mmi_id sg_id = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_check_ready(MMI_TRUE))
    {
        handle = mmi_phb_cntx_mgr_create_handle(MMI_PHB_SG_CUI_VIEW);
        sg_id = mmi_phb_cntx_mgr_get_sg_id(handle);
        mmi_phb_cntx_mgr_set_parent_id(handle, parent_id);
        view_cntx = cui_phb_view_contact_create_cntx();

        /**
         * set sg it to user data, then group proc function can use the sg it to distinguish instance
         */
        view_cntx->sg_id = sg_id;
        view_cntx->parent_id = parent_id;
        
        mmi_phb_cntx_mgr_set_data(handle, view_cntx);

        mmi_frm_group_create(parent_id, sg_id, cui_phb_view_contact_proc, view_cntx);
    }

    MMI_PHB_LOG2(TRC_CUI_PHB_VIEW_CONTACT_CREATE, parent_id, sg_id);

    return sg_id;
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_view_contact_set_store_index
 * DESCRIPTION
 *  Phonebook Cui - view a contact: set store index
 * PARAMETERS
 *  phb_view_sg_id             :      [IN]      view contact sg id
 *  store_index                   :      [IN]      contact store index
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_view_contact_set_store_index(mmi_id phb_view_sg_id, U8 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_view_contact_cntx_struct *view_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG2(TRC_CUI_PHB_VIEW_CONTACT_SET_STORE_INDEX, phb_view_sg_id, store_index);
    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_view_sg_id);
    view_cntx = (mmi_phb_view_contact_cntx_struct *)mmi_phb_cntx_mgr_get_data(handle);

    view_cntx->store_index = store_index;
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_view_contact_entry
 * DESCRIPTION
 *  Phonebook Cui - entry view contact
 * PARAMETERS
 *  sg_id                  :        [IN]           View contact sg id
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_phb_view_contact_entry(mmi_phb_view_contact_cntx_struct *view_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_phb_view_contact_set_cntx(view_cntx);

    mmi_frm_scrn_first_enter(
        view_cntx->sg_id,
        SCR_ENTRY_VIEW,
        (FunctionPtr)mmi_phb_entry_op_view_entry,
        view_cntx);
}


#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  cui_phb_view_contact_tcard_proc
 * DESCRIPTION
 *  receive plug out event of memory card
 * PARAMETERS
 *  mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret cui_phb_view_contact_tcard_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tcard_event_struct *event = (srv_tcard_event_struct*)evt;
    mmi_phb_view_contact_cntx_struct *view_cntx = (mmi_phb_view_contact_cntx_struct*)evt->user_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((srv_tcard_event_tcard_ready_struct*)(event->event_info))->is_tcard_ready == MMI_FALSE)
    { 
        if (PHB_STORAGE_TCARD == (phb_storage_enum)srv_phb_get_storage(view_cntx->store_index))
        {
            mmi_frm_group_close(view_cntx->sg_id);
        }
    }
    return MMI_RET_OK;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  cui_phb_view_contact_proc
 * DESCRIPTION
 *  Phonebook Cui - view a contact, proc function
 * PARAMETERS
 *  evt                     :    [IN]           evt structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret cui_phb_view_contact_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_view_contact_cntx_struct *view_cntx;
    mmi_ret menu_cui_proc;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    view_cntx = (mmi_phb_view_contact_cntx_struct *) evt->user_data;
    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(view_cntx->sg_id);

    menu_cui_proc = mmi_phb_view_contact_menu_cui_proc(evt);
    if (menu_cui_proc == MMI_RET_OK)
    {
        return MMI_RET_OK;
    }

    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_FIRST_ENTRY:
        case EVT_ID_GROUP_INACTIVE:
            break;
        
        case EVT_ID_GROUP_ACTIVE:
            break;
            
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
            break;
            
        case EVT_ID_GROUP_DEINIT:
            cui_phb_view_contact_release_cntx(view_cntx->sg_id);
            mmi_phb_cntx_mgr_release_handle(handle);
        #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
            mmi_frm_cb_dereg_event(EVT_ID_SRV_TCARD_READY, cui_phb_view_contact_tcard_proc, view_cntx);
        #endif
            break;
            
        case EVT_ID_GROUP_FOCUSED:
        case EVT_ID_GROUP_REDRAW_START:
            cui_phb_view_contact_set_cntx(view_cntx);
            break;

        case EVT_ID_PHB_SAVE_CONTACT:
        {
            cui_phb_save_contact_result_struct *save_result = (cui_phb_save_contact_result_struct *) evt;
            mmi_phb_view_contact_cntx_struct *view_cntx = (mmi_phb_view_contact_cntx_struct *) evt->user_data;

            if (save_result->store_index != view_cntx->store_index)
            {
                mmi_frm_group_close(view_cntx->sg_id);
            }
            else
            {
                cui_phb_view_contact_set_cntx(view_cntx);
                view_cntx->first_highlight_type = save_result->field_type;
                cui_phb_save_contact_close(view_cntx->child_id);
            }

            break;
        }
        
        case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
        {
            cui_phb_save_contact_result_struct *save_result = (cui_phb_save_contact_result_struct *) evt;
            mmi_phb_view_contact_cntx_struct *view_cntx = (mmi_phb_view_contact_cntx_struct *) evt->user_data;

            view_cntx->first_highlight_type = save_result->field_type;
            
            cui_phb_save_contact_close(view_cntx->child_id);
            break;
        }
        
        default:
            break;
    }
 
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_view_contact_run
 * DESCRIPTION
 *  Phonebook Cui - view a contact
 * PARAMETERS
 *  phb_view_sg_id                :    [IN]         view contact sg id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_view_contact_run(mmi_id phb_view_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_view_contact_cntx_struct *view_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(phb_view_sg_id);
    view_cntx = mmi_phb_cntx_mgr_get_data(handle);
    
    MMI_PHB_LOG1(TRC_CUI_PHB_VIEW_CONTACT_RUN, handle);

    MMI_ASSERT(srv_phb_check_entry_exist(view_cntx->store_index));
    
    mmi_frm_group_enter(phb_view_sg_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    cui_phb_view_contact_entry(view_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_view_contact_close
 * DESCRIPTION
 *  Phonebook Cui - view a contact, close function
 * PARAMETERS
 *  phb_view_sg_id                :    [IN]         view contact sg id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_view_contact_close(mmi_id phb_view_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG1(TRC_CUI_PHB_VIEW_CONTACT_CLOSE, phb_view_sg_id);
    mmi_frm_group_close(phb_view_sg_id);
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_view_contact
 * DESCRIPTION
 *  Phonebook Cui - view a contact
 * PARAMETERS
 *  parent_id                :    [IN]           Caller sg id
 *  store_index             :    [IN]           contact store index
 * RETURNS
 *  mmi_id
 *****************************************************************************/
mmi_id cui_phb_view_contact(mmi_id parent_id, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle = 0;    
    mmi_phb_view_contact_cntx_struct *view_cntx;
    mmi_id sg_id = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_check_ready(MMI_TRUE))
    {
        handle = mmi_phb_cntx_mgr_create_handle(MMI_PHB_SG_CUI_VIEW);
        sg_id = mmi_phb_cntx_mgr_get_sg_id(handle);
        mmi_phb_cntx_mgr_set_parent_id(handle, parent_id);
        view_cntx = cui_phb_view_contact_create_cntx();

        view_cntx->sg_id = sg_id;
        view_cntx->store_index = store_index;
        view_cntx->parent_id = parent_id;

        mmi_phb_cntx_mgr_set_data(handle, view_cntx);
        
        mmi_frm_group_create(parent_id, sg_id, cui_phb_view_contact_proc, view_cntx);
        mmi_frm_group_enter(sg_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        mmi_frm_cb_reg_event(EVT_ID_SRV_TCARD_READY, cui_phb_view_contact_tcard_proc, view_cntx);
    #endif
        cui_phb_view_contact_entry(view_cntx);
    }

    MMI_PHB_LOG3(TRC_CUI_PHB_VIEW_CONTACT, parent_id, handle, store_index);
    return sg_id;
}


#define MMI_PHB_DIRECT_DIAL
#ifdef __OP01_FWPBW__
/*****************************************************************************
 * FUNCTION
 *  cui_phb_view_contact_close
 * DESCRIPTION
 *  Phonebook Cui - view a contact, close function
 * PARAMETERS
 *  phb_view_sg_id                :    [IN]         view contact sg id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_direct_dial_close(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_view_contact_run
 * DESCRIPTION
 *  Phonebook Cui - view a contact
 * PARAMETERS
 *  phb_view_sg_id                :    [IN]         view contact sg id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_direct_dial_launch(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_frm_group_enter(cui_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_phb_entry_direct_dial_edit();
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_direct_dial_set_index
 * DESCRIPTION
 *  Phonebook Cui - set view contact cntx
 * PARAMETERS
 *  view_cntx                 :       [IN]          cui view contact cntx
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_direct_dial_set_index(mmi_id cui_id, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_dialer_direct_dial_cntx_struct *obj = (mmi_phb_dialer_direct_dial_cntx_struct *)
        mmi_frm_group_get_user_data(cui_id);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_CUI_PHB_VIEW_CONTACT_SET_CNTX);
    
    obj->index = index;
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_view_contact_create
 * DESCRIPTION
 *  Phonebook Cui - view a contact
 * PARAMETERS
 *  parent_id             :      [IN]           Caller screen group id
 * RETURNS
 *  mmi_id
 *****************************************************************************/
mmi_id cui_phb_direct_dial_create(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_dialer_direct_dial_cntx_struct *user_data;
    mmi_id sg_id = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_check_ready(MMI_TRUE))
    {
        user_data = srv_phb_mem_malloc(sizeof(mmi_phb_dialer_direct_dial_cntx_struct), SRV_PHB_MEMORY_TYPE_ADM);
        memset(user_data, 0x00, sizeof(mmi_phb_dialer_direct_dial_cntx_struct));
    
        mmi_frm_group_create(GRP_ID_PHB_SETTING, GRP_ID_PHB_DIRECT_DIAL, mmi_phb_dialer_direct_dial_proc, user_data);
        sg_id = GRP_ID_PHB_DIRECT_DIAL;
    }
    MMI_PHB_LOG2(TRC_CUI_PHB_VIEW_CONTACT_CREATE, parent_id, sg_id);

    return sg_id;
}
#endif

#define MMI_PHB_LAUNCH

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_launch
 * DESCRIPTION
 *  Phonebook launch proc function
 * PARAMETERS
 *  evt
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_phb_launch_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_list_cntx_struct *main_cntx;
    mmi_ret menu_cui_proc;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    main_cntx = (mmi_phb_list_cntx_struct *) evt->user_data;
    
    handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(main_cntx->sg_id);

    menu_cui_proc = mmi_phb_main_list_menu_cui_proc(evt);
    if (menu_cui_proc == MMI_RET_OK)
    {
        return MMI_RET_OK;
    }

#ifdef __MMI_BPP20_SUPPORT__
    if (mmi_phb_bpp_cui_proc(evt) == MMI_RET_OK)
    {
        return MMI_RET_OK;
    }
#endif /* __MMI_BPP20_SUPPORT__ */

    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_FIRST_ENTRY:
            break;
            
        case EVT_ID_GROUP_INACTIVE:
        {
            if (mmi_frm_scrn_get_count(main_cntx->sg_id) == 0)
            {
                mmi_frm_group_close(main_cntx->sg_id);
            }
            break;
        }
        case EVT_ID_GROUP_ACTIVE:
            cui_phb_list_select_contact_set_cntx(main_cntx);
            break;
            
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
            break;
            
        case EVT_ID_GROUP_DEINIT:
            cui_phb_list_select_contact_release_cntx(main_cntx);
            mmi_phb_cntx_mgr_release_handle(handle);
        #ifdef __MMI_SNS_CONTACTS__
            mmi_frm_cb_dereg_event(EVT_ID_SRV_SNS_PLUGINS_UNLOADED, mmi_phb_sns_unload_proc, NULL);
            srv_sns_exit_app();
        #endif
            break;
            
        case EVT_ID_GROUP_FOCUSED:
        case EVT_ID_GROUP_REDRAW_START:
            cui_phb_list_select_contact_set_cntx(main_cntx);
            break;
            
    #ifdef __MMI_VCARD__
        case EVT_ID_VCARD_DONE:
        case EVT_ID_VCARD_CANCEL:
            cui_vcard_build_vcard_close(main_cntx->child_id);
            break;
    #endif /* __MMI_VCARD__ */

        case EVT_ID_PHB_SAVE_CONTACT:
        case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
            cui_phb_save_contact_close(main_cntx->child_id);
            break;

	#ifdef __MMI_SNS_CONTACTS__
		case EVT_ID_CUI_SNS_FRIEND_LINK:
		{
			cui_sns_result_event_struct *sns_evt = (cui_sns_result_event_struct*)evt;
			cui_sns_friend_link_close(sns_evt->sender_id);
            mmi_frm_cb_dereg_event(EVT_ID_SRV_SNS_READY, mmi_phb_sns_link_not_ready_proc, (void*)sns_evt->sender_id);
            g_mmi_phb_sns_misc.sns_cui_link = GRP_ID_INVALID;
			mmi_phb_sns_entry_contact_link(sns_evt->result);
			break;
		}

		case EVT_ID_CUI_SNS_FILTER:
		{
			cui_sns_filter_event_struct *sns_evt = (cui_sns_filter_event_struct*)evt;
			mmi_phb_sns_entry_filter(sns_evt->result, sns_evt->list_id, sns_evt->is_group, sns_evt->provider);
			cui_sns_filter_close(sns_evt->sender_id);
            mmi_frm_cb_dereg_event(EVT_ID_SRV_SNS_READY, mmi_phb_sns_filter_not_ready_proc, (void*)sns_evt->sender_id);
            g_mmi_phb_sns_misc.sns_cui_filter = GRP_ID_INVALID;
			break;
		}
	#endif

        default:
            break;
    }
 
    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_launch_init
 * DESCRIPTION
 *  Phonebook launch for ASM 2.0
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_launch_init(mmi_id app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 handle;
    mmi_phb_list_cntx_struct *main_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = mmi_phb_cntx_mgr_create_handle(MMI_PHB_SG_MAIN);
    main_cntx = cui_phb_list_select_contact_create_cntx(MMI_PHB_LIST_TYPE_SINGLE_SELECT);

    main_cntx->sg_id = GRP_ID_PHB_MAIN;
    main_cntx->parent_id = GRP_ID_INVALID;
    
    mmi_phb_cntx_mgr_set_data(handle, main_cntx);

    mmi_frm_group_create(app_id, GRP_ID_PHB_MAIN, mmi_phb_launch_proc, main_cntx);
    mmi_frm_group_enter(GRP_ID_PHB_MAIN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
#ifdef __MMI_SNS_CONTACTS__
    mmi_frm_cb_reg_event(EVT_ID_SRV_SNS_PLUGINS_UNLOADED, mmi_phb_sns_unload_proc, NULL);
    srv_sns_enter_app();
#endif
    mmi_phb_launch_entry();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_launch_init_proc
 * DESCRIPTION
 *  Phonebook launch proc function for ASM 2.0
 * PARAMETERS
 *  evt
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_phb_launch_init_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_ID app_id;
	mmi_frm_asm_property_struct p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	app_id = GET_APP_ID(evt);
	switch (evt->evt_id)
	{
		case EVT_ID_APP_ENTER:
			mmi_frm_asm_get_property(app_id,&p);
            p.f_prepare_w_reserve=0;
	        mmi_frm_asm_set_property(app_id,&p);
			mmi_phb_launch_init(app_id);
			break;

		default:
			break;
	}
	
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_launch
 * DESCRIPTION
 *  Phonebook launch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_LANUCH);

    if (srv_phb_startup_is_phb_ready())
    {
        MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, 805);

        if (!mmi_phb_check_ready(MMI_TRUE))
        {
            MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, 806);
            return;
        }
    }

    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, 807);

    /* re-entry phonebook, delete old history */
    mmi_phb_cntx_mgr_clear_history();
    
	if (mmi_frm_app_is_launched(APP_PHONEBOOK))
	{
		mmi_frm_app_close(APP_PHONEBOOK);
	}

	mmi_frm_app_launch(APP_PHONEBOOK, 0, 0, mmi_phb_launch_init_proc, NULL, MMI_FRM_APP_SKIP_SIZE_CHECK | MMI_FRM_APP_SKIP_RESVERVE_CHECK);
}

MMI_ID mmi_phb_pre_entry_main_screen(void* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_launch();
    return GRP_ID_PHB_MAIN;
}

void mmi_phb_idle_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_launch();
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_send_data_to_sa
 * DESCRIPTION
 *  Phonebook Cui - send select data to parent sg
 * PARAMETERS
 *  parent_id                   [IN]
 *  evt                            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_send_data_to_sa(mmi_id parent_id, void* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG1(TRC_CUI_PHB_SEND_DATA_TO_SA, parent_id);
    mmi_frm_group_send_to_parent(parent_id, (mmi_group_event_struct *) evt);
}


/** 
  * CUI: sample code
  */

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

