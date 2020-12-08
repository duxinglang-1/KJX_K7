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
 * UcCui.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file have UC application core part.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//#include "MMI_include.h"
#include "MMIDataType.h"
#include "MMI_features.h"

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
#include "UcResDef.h"
#include "Ucappgprot.h"
#include "UcSrvGprot.h"
#include "UcSrvIprot.h"
#include "filemgrsrvgprot.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif
//SUGGESTED ADD
#include "mmi_frm_scenario_gprot.h"
    #include "GlobalResDef.h"
    #include "CustDataRes.h"
    #include "mmi_frm_events_gprot.h"
    #include "gui_data_types.h"
    //#include "kal_general_types.h"
    #include "mma_api.h"
    #include "fs_type.h"
    #include "fs_func.h"
/*Build warning*/
#include "AlertScreen.h"
#include "UcAppProt.h"
#include "TimerEvents.h"
/*****************************************************************************
 * FUNCTION
 *  cui_uc_write_msg_launch
 * DESCRIPTION
 *  Launch editor from UM.
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cui_uc_write_msg_launch(mmi_id parent_grp_id) 
{


	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_MMS_POSTCARD__
        mmi_uc_entry_write_msg_selection_launch(parent_grp_id);
        return;
    #endif /* __MMI_MMS_POSTCARD__ */ 

    mmi_uc_write_msg_launch(parent_grp_id);
}

/*****************************************************************************
 * FUNCTION
 *  cui_uc_launch
 * DESCRIPTION
 *  Launch Editor from MMS application
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cui_uc_write_msg_close(mmi_id cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(cui_gid);
}

/*****************************************************************************
 * FUNCTION
 *  cui_uc_group_proc
 * DESCRIPTION
 *  create the cui id of unified composer.
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret cui_uc_group_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
    case EVT_ID_GROUP_DEINIT:
        {
            cui_uc_write_msg_close(GRP_ID_UNIFIED_COMPOSER);
        }
        break;
    default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_uc_write_msg_create
 * DESCRIPTION
 *  create the cui id of unified composer.
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
 mmi_id cui_uc_write_msg_create(mmi_id parent_gid)
{
	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_frm_group_create (parent_gid,  GRP_ID_UNIFIED_COMPOSER, cui_uc_group_proc, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  cui_uc_write_msg_with_content_launch
 * DESCRIPTION
 *  launch editor with content
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cui_uc_write_msg_with_content_launch(mmi_id parent_cui_gid, mmi_uc_done_type_enum type, mmi_uc_entry_write_struct *data) /*why no parent gid*/
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!mmi_uc_is_uc_ready())
    {
        mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_AVAILABLE)), MMI_EVENT_FAILURE, NULL);
        mmi_uc_handle_progress_entry_composer_write_msg_on_fail();
        if (data->callback != NULL)
        {
            data->callback((void*)data->callback_para);
        }
        return;
    }

    if (mmi_uc_is_uc_reenter())
    {
        //mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE)), MMI_EVENT_FAILURE, NULL);

        mmi_uc_write_msg_delete_history_hdlr(NULL);
        //return;
    }

    if (g_uc_p->srv_send_info->action == SRV_UC_ACTION_SAVE_IN_BACKGROUND)
    {
        g_uc_p->main.callback_id = parent_cui_gid;

        g_uc_p->main.operation_reentry = (uc_confirm_func_ptr)cui_uc_write_msg_with_content_launch;

        mmi_uc_copy_reentry_struct(type, data);

        if (g_uc_p->main.reentry_struct != NULL)

        {

        mmi_uc_show_progress_in_reentry(0);

       StartTimer(
                                UC_CREATE_RSP_REENTRY_RETRY_TIMER_ID,
                                MMI_UC_CREATE_RSP_REENTRY_RETRY_TIME,
                                mmi_uc_create_msg_rsp_timeout_callback);
        }
       
       return;
    }

	#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode() && mma_is_storage_exported_to_pc())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*)SRV_UC_FOLDER_DRV))
        {
            /* MMI public drive is exported, cannot use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            mmi_uc_handle_progress_entry_composer_write_msg_on_fail();
            if (data->callback != NULL)
            {
                data->callback((void*)data->callback_para);
            }
            return;
        }
    }
	#endif /* __USB_IN_NORMAL_MODE__ */ 
    mmi_uc_set_parent_group_id(parent_cui_gid);
    cui_id = cui_uc_write_msg_create(parent_cui_gid);
    mmi_uc_set_main_group_id(cui_id);
    mmi_frm_group_enter(cui_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_uc_entry_write_msg_with_content(type, data);
    if(g_uc_p->main.reentry_struct)
    {
        mmi_uc_free_reentry_struct();
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_uc_launch
 * DESCRIPTION
 *  Launch Editor from MMS application
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U32 cui_uc_write_msg_from_mms_launch(mmi_id parent_cui_gid, mmi_uc_start_struct *msg_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cui_id;
    U32 result = MMA_RESULT_OK ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!mmi_uc_is_uc_ready())
    {
        mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_AVAILABLE)), MMI_EVENT_FAILURE, NULL);
        return MMI_FALSE;
    }

    if (mmi_uc_is_uc_reenter())
    {
        //mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE)), MMI_EVENT_FAILURE, NULL);

        mmi_uc_write_msg_delete_history_hdlr(NULL);
        //return;
    }

    if (g_uc_p->srv_send_info->action == SRV_UC_ACTION_SAVE_IN_BACKGROUND)
    {
        g_uc_p->main.callback_id = parent_cui_gid;

        g_uc_p->main.operation_reentry = (uc_confirm_func_ptr)cui_uc_write_msg_from_mms_launch; 

        g_uc_p->main.reentry_msg = OslMalloc(sizeof(mmi_uc_start_struct));

        memset(g_uc_p->main.reentry_msg, 0, sizeof(mmi_uc_start_struct));
        memcpy(g_uc_p->main.reentry_msg, msg_req, sizeof(mmi_uc_start_struct));

        mmi_uc_show_progress_in_reentry(parent_cui_gid);

       StartTimer(
                                UC_CREATE_RSP_REENTRY_RETRY_TIMER_ID,
                                MMI_UC_CREATE_RSP_REENTRY_RETRY_TIME,
                                mmi_uc_create_msg_rsp_timeout_callback);
        
       
       return MMI_TRUE;
    }

	#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode()
         && mma_is_storage_exported_to_pc())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*) SRV_UC_FOLDER_DRV))
        {
            /* MMI public drive is exported, cannot use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return MMI_FALSE;
        }
    }
	#endif /* __USB_IN_NORMAL_MODE__ */

	if (mmi_uc_is_uc_screen_alraedy_present())
    {
        return MMA_RESULT_FAIL_BUSY;
    }
    mmi_uc_set_parent_group_id(parent_cui_gid);
    cui_id = cui_uc_write_msg_create(parent_cui_gid);
    mmi_uc_set_main_group_id(cui_id);
    result = mmi_uc_launch(msg_req);
    if(g_uc_p->main.reentry_msg)
    {
        OslMfree(g_uc_p->main.reentry_msg);
        g_uc_p->main.reentry_msg = NULL ;
    }
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  cui_uc_entry_msg_operation_launch
 * DESCRIPTION
 *  Api to launch the operation via UC over a SMS, MMS or Postcard
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE:   Success
 *  MMI_FALSE:  Failure
 *****************************************************************************/
MMI_BOOL cui_uc_entry_msg_operation_launch( mmi_id parent_cui_gid, U32 msg_id, U16 msg_type, mmi_uc_msg_operation_enum operation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!mmi_uc_is_uc_ready())
    {
        mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_AVAILABLE)), MMI_EVENT_FAILURE, NULL);
        return MMI_FALSE;
    }

    if (mmi_uc_is_uc_reenter())
    {
        //mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE)), MMI_EVENT_FAILURE, NULL);

        mmi_uc_write_msg_delete_history_hdlr(NULL);
        //return;
    }

    if (g_uc_p->srv_send_info->action == SRV_UC_ACTION_SAVE_IN_BACKGROUND)
    {
        g_uc_p->main.callback_id = parent_cui_gid;

        g_uc_p->main.operation_reentry = (uc_confirm_func_ptr)cui_uc_entry_msg_operation_launch; 

        g_uc_p->main.reentry_msg_operation = operation;

        g_uc_p->main.reentry_msg_id = msg_id;

        g_uc_p->main.reentry_msg_type = msg_type;

        mmi_uc_show_progress_in_reentry(parent_cui_gid);

       StartTimer(
                                UC_CREATE_RSP_REENTRY_RETRY_TIMER_ID,
                                MMI_UC_CREATE_RSP_REENTRY_RETRY_TIME,
                                mmi_uc_create_msg_rsp_timeout_callback);
        
       
       return MMI_TRUE;
    }

	#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode()
         && mma_is_storage_exported_to_pc())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*) SRV_UC_FOLDER_DRV))
        {
            /* MMI public drive is exported, cannot use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return MMI_FALSE;
        }
    }
	#endif /* __USB_IN_NORMAL_MODE__ */
    cui_id = cui_uc_write_msg_create(parent_cui_gid);
    mmi_uc_set_main_group_id(cui_id);
    return mmi_uc_entry_msg_operation_launch(msg_id, msg_type, operation);
}
#endif
