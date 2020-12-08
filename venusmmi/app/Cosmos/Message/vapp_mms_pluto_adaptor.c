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
 * MMSAppSrvHdlr.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * 
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
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "MMI_include.h"
#include "vapp_msg_features.h"

#ifdef __MMI_MMS_2__
#include "CommonScreens.h"

#include "MMSAppCommonGprot.h"

#include "MMSSrvSendRcv.h"
#include "custom_events_notify.h"
#include "mmi_rp_vapp_mms_def.h"
 #include "mms_sap_struct.h"
#include "mmsadp.h"
//#include "SimDetectionStruct.h"
//#include "SimDetectionGprot.h"
#include "MmsSrvGprot.h"
#include "MmsSrvProt.h"
#include "vapp_mms_interface.h"
#include "vapp_mms_cntrl.h"

#include "MMSMemoryManagerSrv.h"
#include "MMSBGSRSrvProt.h"
#include "vapp_mms_appcore.h"
#include "vapp_mms_dtmgr.h"
//#include "DLAgentDef.h"
#include "DLAgentSrvDef.h"

#include "vapp_mms_gprot.h"
#include "Wgui_categories_util.h"
#include "mmi_inet_app_trc.h"   
/*Only for the Applications who care about viewer open*/
extern MMI_BOOL vapp_mms_check_template_req(void *msg);
extern void mmi_umms_send_template_check_rsp(U8 result);
static U32 g_current_msg_id;

void mmi_umms_set_current_msg_id_in_view(U32 msg_id)
{
	g_current_msg_id = msg_id;
}

U32 mmi_umms_get_current_msg_id_in_view(void)
{
	return g_current_msg_id;
}


mmi_id cui_umms_mms_templates_launch(mmi_id parent_id)
{

	return MMI_RET_OK;
}

mmi_id cui_umms_mms_settings_launch(mmi_id parent_id)
{
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_is_option_screen_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_app_if_is_option_screen_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  

    return MMI_FALSE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_end_call_is_download_in_progress
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_app_if_end_call_is_download_in_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_message_settings_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_message_settings_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_show_template_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_show_template_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_interface_entry_from_um
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_umms_app_interface_entry_from_um(U16 key, U32 msg_id, void *user_data, mmi_id parent_grp_id)
{

    
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_start_viewer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_start_viewer(U16 parent_grp_id, U32 msg_id, void *um_data, cui_msg_viewer_type_enum view_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	vapp_mms_viewer_launch(msg_id, parent_grp_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_hs_get_recent_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  num     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_op_hs_get_recent_mms(S32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

}



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_is_msg_screen_active
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_app_if_is_msg_screen_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return MMI_FALSE;
}

#ifdef __DM_LAWMO_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_bgsr_free_mms_data_for_wipe_callback
 * DESCRIPTION
 *  Call Back from BGSR after trying cancelling any send receive MMS and  
 *  resetting read report flag at MMA end
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_bgsr_free_mms_data_for_wipe_callback(U8 result)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 folder_id = 0;
    srv_mms_delete_folder_req_struct req;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder_id = 
    SRV_UM_MSG_BOX_INBOX |
    SRV_UM_MSG_BOX_UNSENT |
    SRV_UM_MSG_BOX_SENT |
    SRV_UM_MSG_BOX_DRAFT |
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    SRV_UM_MSG_BOX_ARCHIVE |
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    SRV_UM_MSG_BOX_PREDEF_TEMPLATES |
    SRV_UM_MSG_BOX_USRDEF_TEMPLATES;
    
    
    req.user_data = 0;
    req.msg_type = SRV_UM_MSG_MMS;
    req.msg_box_type = folder_id;
    req.app_id = MMA_APP_ID_MMS_LAWMO;
    req.call_back = mmi_umms_app_core_remove_all_mms_rsp;
    srv_mms_delete_folder(&req);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_msg_in_view
 * DESCRIPTION
 *  Checks whether msg is currently viewed or not
 * PARAMETERS
 *  msg_id      [IN]        [In]
 * RETURNS
 *  TRUE: If msg_id is same as viewer contaxt's msg_id
 *  FALSE:Otherwise
 *****************************************************************************/
mmi_ret mmi_umms_app_if_msg_in_view(mmi_event_struct *evt)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_mms_base_event_struct *pevt = (srv_mms_base_event_struct *)evt;
	U32 *curr_msg_id = (U32 *)pevt->sender_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(curr_msg_id)
	{
		srv_mms_set_is_mms_in_use_flag(srv_mms_search_instance_ext(*curr_msg_id));
	}
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_lang_changed_hdlr
 * DESCRIPTION
 *  Checks whether msg is currently viewed or not
 * PARAMETERS
 *  msg_id      [IN]        [In]
 * RETURNS
 *  TRUE: If msg_id is same as viewer contaxt's msg_id
 *  FALSE:Otherwise
 *****************************************************************************/
mmi_ret mmi_umms_app_lang_changed_hdlr(mmi_event_struct *evt)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	srv_mms_um_refresh_ind(MMA_FOLDER_TEMPLATE);
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_is_mms_in_open_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_umms_app_if_is_mms_in_open_state(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_mms_base_event_struct *pevt = (srv_mms_base_event_struct *)evt;
	U32 *curr_msg_id = (U32 *)pevt->sender_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(curr_msg_id)
	{
		srv_mms_set_is_mms_in_use_flag(srv_mms_search_instance_ext(*curr_msg_id));
	}
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_show_status_icon_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  icon_id
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_umms_app_show_status_icon_by_id(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
#endif
}



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_hide_status_icon_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  icon_id
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_umms_app_hide_status_icon_by_id(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_blink_status_icon_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  icon_id
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_umms_app_blink_status_icon_by_id(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_op_update_recent_event_list_from_phone_suit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_umms_op_update_recent_event_list_from_phone_suit(mmi_event_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    return MMI_RET_OK;
}


void mmi_umms_fmgr_forward_mms_enabler(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S8* filepath;
#ifdef __MMI_MMS_2__
#ifdef __MMI_MMS_POSTCARD__
    MMI_BOOL can_insert = MMI_FALSE;
    mmi_fmgr_filetype_enum type;
#endif
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //filepath = mmi_fmgr_get_current_fileinfo(NULL, &app_id);
    //filepath = mmi_fmgr_util_extract_filename(filepath);
    
    if (mms_is_content_forward((char*)filepath) == MMI_FALSE)
    {
#ifdef __MMI_MMS_2__
#ifdef __MMI_OP11_MMS_SEND_TO_PHOTO_BLOG__
/* under construction !*/
#endif
#ifdef __MMI_MMS_POSTCARD__
        mmi_frm_hide_menu_item(MENU_ID_UMMS_FMGR_SEND_TO_POSTCARD);
#endif
#endif
     //   mmi_frm_hide_menu_item(MENU_ID_FMGR_FWD_MMS);
        return;
    }
    
#ifdef __MMI_MMS_2__
#ifdef __MMI_MMS_POSTCARD__
    
    type = srv_fmgr_types_find_type_by_filename_str((WCHAR*) filepath);
    can_insert = mmi_umms_app_if_check_mms_insert_postcard(type,(char *)filepath);
    if(!can_insert)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_FMGR_SEND_TO_POSTCARD);
    }
#endif
#endif
}





/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_uc_request_to_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_uc_request_to_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    mmi_umms_app_if_deinit_viewer();

}

 
mmi_ret umms_cb_hdlr(mmi_event_struct *evt, void * para)
{
        return MMI_RET_OK;

}


extern kal_uint8 mma_get_mms_msg_type(kal_uint32 msg_id);
mmi_menu_id umms_menu_query_function(U32 msg_id)
{
      return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_get_um_box_type_from_msg_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id
 * RETURNS
 *  Um box type
 *****************************************************************************/
U16 mmi_umms_app_if_get_um_box_type_from_msg_id(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 msg_box_type = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	msg_box_type = srv_mms_convert_mma_folder_to_umbox_type(mma_get_box(msg_id));
	return msg_box_type;
}


#ifdef __MMI_FTE_SUPPORT__
void mmi_umms_app_if_reply_mms(mmi_id parent_id, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

}

void mmi_umms_app_if_forward_mms(mmi_id parent_id, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

        }

void mmi_umms_app_if_edit_mms(mmi_id parent_id, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
}




void mmi_umms_app_if_send_mms(mmi_id parent_id, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

}

void mmi_umms_app_if_resend_mms(mmi_id parent_id, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
      
}



void mmi_umms_app_if_delete_mms(mmi_id parent_id, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
}

#endif /*__MMI_FTE_SUPPORT__*/


/*UC Preview related*/
void *cui_umms_app_set_uc_preview_msg(U32 msg_id, U8 msg_type, U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_start_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (mmi_umms_app_start_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(mmi_umms_app_start_struct));
	memset(msg, 0, sizeof(mmi_umms_app_start_struct));
    msg->msg_id = msg_id;    /* function to get current msg_id ke index pe jo hilight hai */
    msg->msg_box_type = 0;
    return (void*) msg;
}

mmi_id cui_umms_preview_mms_create(mmi_id parent_id)
{
	//return vapp_mms_viewer_preview_cui_create(parent_id);
    return 0;
}


void cui_umms_preview_mms_run(mmi_id parent_id, void *msg)
{
	//mmi_umms_app_start_struct *data = (mmi_umms_app_start_struct *)msg;
	//vapp_mms_viewer_preview_launch(data->msg_id, parent_id);
}
void cui_umms_preview_mms_close(mmi_id parent_id)
{
	//mmi_frm_group_close(parent_id);
}

/*UC Preview Related*/

//******************Callback Manager**********************

mmi_ret mmi_umms_drv_format_hdlr_cb(mmi_event_struct *param)
{
	srv_fmgr_notification_format_event_struct *format_evt;


	switch(param->evt_id)
	{
		case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT:
			format_evt = (srv_fmgr_notification_format_event_struct*)param;
			if(format_evt->state == SRV_FMGR_NOTIFICATION_STATE_AFTER)
			{
				srv_mms_drv_format_hdlr();
                                 srv_mms_um_refresh_ind(MMA_FOLDER_ALL);
			}
			if(format_evt->state == SRV_FMGR_NOTIFICATION_STATE_BEFORE)
			{
				srv_mms_um_refresh_ind(MMA_FOLDER_ALL);
			}
            break;
		default:
			break;
	}
	return MMI_RET_OK;
}


#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
mmi_ret mmi_umms_sd_card_plug_in_hdlr_cb(mmi_event_struct *param)
{
	U8 i = 0;
	U8 drive_counter = 0;
	srv_fmgr_notification_dev_plug_event_struct *plug_in_info;
	switch(param->evt_id)
	{
		case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
			
			plug_in_info = (srv_fmgr_notification_dev_plug_event_struct*)param;

			for (i = 0; i < plug_in_info->count; i++)
			{
				if (plug_in_info->drv_letters[i] == SRV_FMGR_CARD_DRV)
				{
					drive_counter++;
				}
			}
			if(drive_counter)
			{
				srv_mms_sd_card_plug_in_hdlr(drive_counter);
			}
			break;
		default:
			break;
	}
	return MMI_RET_OK;
	
}

mmi_ret mmi_umms_sd_card_plug_out_hdlr_cb (mmi_event_struct *param)
{
	U8 i = 0;
	U8 drive_counter = 0;
	srv_fmgr_notification_dev_plug_event_struct *plug_in_info;
	switch(param->evt_id)
	{
		case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
			
			plug_in_info = (srv_fmgr_notification_dev_plug_event_struct*)param;

			for (i = 0; i < plug_in_info->count; i++)
			{
				if (plug_in_info->drv_letters[i] == SRV_FMGR_CARD_DRV)
				{
					drive_counter++;
				}
			}
			if(drive_counter)
			{
				mmi_umms_app_core_handle_sd_card_plug_out(NULL);
				srv_mms_sd_card_plug_out_hdlr(drive_counter);
			}
			
			break;
		default:
			break;
	}
	return MMI_RET_OK;
}
#endif /*__MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__*/

MMI_RET mmi_umms_app_ui_plug_in_check_and_delete_progress_screen(mmi_event_struct *evt)
{
   srv_mms_save_obj_req_struct *rsp_user = (srv_mms_save_obj_req_struct *)evt->user_data;
   if(rsp_user->fs_error != FS_NO_ERROR)
   {
		rsp_user->save_obj_fn(rsp_user->user_data, EVT_ID_SRV_TEMPLATE_ERROR, (void *)&(rsp_user->fs_error));
   }
	if(rsp_user && rsp_user->save_obj_fn)
	{
			rsp_user->save_obj_fn(rsp_user->user_data, EVT_ID_SRV_CHECK_AND_DELETE_PROGRESS, NULL);
	}
	return MMI_RET_OK;
}

void mmi_umms_app_core_save_object(srv_mms_viewer_object_struct *object, void *user_data)
{
	srv_mms_save_object(object, user_data);
}

extern int mmi_charset_ucs2_to_utf8_length_in_bytes(const kal_uint8 *raw);

extern kal_int32 mmi_chset_ucs2_to_utf8_string(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);

MMI_RET mmi_umms_app_core_hanlde_save_objects_copy_result(mmi_event_struct *evt)
{
	srv_mms_save_obj_rsp_evt_struct *rsp = (srv_mms_save_obj_rsp_evt_struct *)evt->user_data;
	S32 copy_result = (S32 )(rsp->copy_result);
	S8 *temp_url = NULL;
	mmi_da_dispatch_file_req_struct *mmi_da_dispatch_file_req = NULL;
    ilm_struct *ilm_ptr = NULL;
	S8 *url = NULL;
    U32 len = 0;
	applib_mime_type_struct *srv_mms_applib_mime_type = NULL;
    S8 *mime_type_string = NULL;
    U16 *media_file_path = NULL;
    PU16 src_file_name;
    U8 drm_type;
	srv_mms_save_obj_req_struct *rsp_user = (srv_mms_save_obj_req_struct *)rsp->user_data;
	media_file_path = srv_mms_get_media_file_path();
    src_file_name = srv_mms_get_src_file_name();
	
	
#if(0)
	if (mmi_umms_app_ui_plug_in_check_progress_is_active() == MMI_FALSE)
    {
        if (srv_mms_is_usb_mode())
        {
            goto END;
        }
        else
        {
            //mmi_umms_app_ui_plug_in_check_and_delete_progress_screen(NULL);
            goto END;
        }
    }
#endif
	if (copy_result >= 0)
    {
        if(rsp_user->save_obj_fn && rsp_user->is_preview == MMI_TRUE)
		{
			rsp_user->save_obj_fn(rsp_user->user_data, EVT_ID_SRV_SAVE_OBJECT_COPY_RESULT_HDL, (void *)&copy_result);
			goto END;
		}
		else if(rsp_user->save_obj_fn)
		{
			rsp_user->save_obj_fn(rsp_user->user_data, EVT_ID_SRV_SAVE_OBJECT_COPY_RESULT_HDL, (void *)&copy_result);
		}
		temp_url = (S8*) srv_mms_mem_mgr_app_adm_alloc((strlen((S8*) "mms://") + 1) * ENCODING_LENGTH);
        if (temp_url != NULL)
        {
            mmi_asc_to_ucs2((S8*) temp_url, (S8*) ("mms://"));
        }
        else
        {
			   srv_mms_send_save_objects_error(STR_GLOBAL_INSUFFICIENT_MEMORY, 0);
            goto END;
        }
        mmi_da_dispatch_file_req =
            (mmi_da_dispatch_file_req_struct*) construct_local_para(sizeof(mmi_da_dispatch_file_req_struct), TD_CTRL);
        
        mmi_da_dispatch_file_req->url[0] = '\0';
        mmi_da_dispatch_file_req->mime_type_string[0] = '\0';
        mmi_da_dispatch_file_req->filepath[0] = '\0';
        mmi_da_dispatch_file_req->action = MMI_DA_DOWNLOAD;
        mmi_da_dispatch_file_req->mime_type = 0;
        mmi_da_dispatch_file_req->mime_subtype = 0;

        mmi_ucs2ncpy(
            (S8*) mmi_da_dispatch_file_req->filename,
            (S8*) src_file_name,
            (sizeof(mmi_da_dispatch_file_req->filename) / ENCODING_LENGTH) - 1);

        drm_type = srv_mms_get_drm_type();

        if (drm_type == MMA_DRM_FL_CD)
        {
            strcpy(mmi_da_dispatch_file_req->mime_type_string, "application/vnd.oma.drm.message");
        }
        else if (drm_type != 0)
        {
            strcpy(mmi_da_dispatch_file_req->mime_type_string, "application/vnd.oma.drm.content");
        }
        else if (srv_fmgr_path_get_extension_ptr((WCHAR*) src_file_name) != NULL)
        {
            srv_mms_applib_mime_type = applib_mime_get_file_type(src_file_name);
            if (NULL == srv_mms_applib_mime_type)
            {
                mime_type_string = NULL;
            }
            else
            {
                mime_type_string = srv_mms_applib_mime_type->mime_string;
            }
            if (mime_type_string != NULL)
            {
                strcpy(mmi_da_dispatch_file_req->mime_type_string, mime_type_string);
            }
            else
            {
                U16 *str_ptr = NULL;
                U8 str_temp[SRV_FMGR_PATH_MAX_FILE_EXT_LEN  + 1] = {0};

                str_ptr = (U16*) srv_fmgr_path_get_extension_ptr((WCHAR*) src_file_name);
				ASSERT(str_ptr);
                mmi_ucs2_n_to_asc((S8*) str_temp, (S8*) str_ptr, SRV_FMGR_PATH_MAX_FILE_EXT_LEN  * ENCODING_LENGTH);
                strcpy(mmi_da_dispatch_file_req->mime_type_string, (S8*) "application/");
                strcat(mmi_da_dispatch_file_req->mime_type_string, (S8*) str_temp);
            }
        }
        else
        {
            strcpy(mmi_da_dispatch_file_req->mime_type_string, (S8*) "application/octet-stream");
        }

        len = (mmi_charset_ucs2_to_utf8_length_in_bytes((U8*) (temp_url)) + 1);
        url = (S8*) srv_mms_mem_mgr_app_adm_alloc(len);
        if (NULL == url)
        {
            srv_mms_send_save_objects_error(STR_GLOBAL_INSUFFICIENT_MEMORY, 0);            
			OslMfree(mmi_da_dispatch_file_req);
            goto END;
        }
        mmi_chset_ucs2_to_utf8_string((U8*) url, len, (U8*) temp_url);
        memset((void*)mmi_da_dispatch_file_req->url, 0, sizeof(mmi_da_dispatch_file_req->url));
        strncpy(mmi_da_dispatch_file_req->url, url, (sizeof(mmi_da_dispatch_file_req->url) - 1));
        srv_mms_mem_mgr_app_adm_free(url);

        memset((void*)mmi_da_dispatch_file_req->filepath, 0, sizeof(mmi_da_dispatch_file_req->filepath));
        mmi_ucs2ncpy(
            (S8*) mmi_da_dispatch_file_req->filepath,
            (S8*) media_file_path,
            ((sizeof(mmi_da_dispatch_file_req->filepath) / ENCODING_LENGTH) - 1));

        mmi_da_dispatch_file_req->extra_info.size = 0;
        mmi_da_dispatch_file_req->extra_info.data[0] = '\0';
        mmi_da_dispatch_file_req->ui_setting.title_string_id = STR_GLOBAL_MMS;
        mmi_da_dispatch_file_req->ui_setting.title_icon_id = 0;
        mmi_umms_app_core_show_progress_screen_with_no_history();
        ilm_ptr = allocate_ilm(mms_get_service_module(MSG_ID_MMI_DA_DISPATCH_FILE_REQ));
        ilm_ptr->src_mod_id = mms_get_service_module(MSG_ID_MMI_DA_DISPATCH_FILE_REQ);
        ilm_ptr->dest_mod_id = MOD_MMI;
        ilm_ptr->sap_id = WAP_MMI_SAP;
        ilm_ptr->msg_id = MSG_ID_MMI_DA_DISPATCH_FILE_REQ;
        ilm_ptr->local_para_ptr = (local_para_struct*) mmi_da_dispatch_file_req;
        ilm_ptr->peer_buff_ptr = NULL;
        msg_send_ext_queue(ilm_ptr);
    }
    else
    {
       // srv_mms_send_events(EVT_ID_SRV_TEMPLATE_ERROR, (void *)copy_result);
        rsp_user->save_obj_fn(rsp_user->user_data, EVT_ID_SRV_CHECK_AND_DELETE_PROGRESS, NULL);
    }

  END:
    if (temp_url != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(temp_url);
        temp_url = NULL;
    }
    if (media_file_path != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(media_file_path);
        media_file_path = NULL;
    }

    if (src_file_name != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(src_file_name);
        srv_mms_set_src_file_name(NULL);
    }
    srv_mms_set_file_handle(FS_NO_ERROR);
    srv_mms_set_media_info(NULL);
    srv_mms_set_media_file_path(NULL);
    srv_mms_set_virtual_file_name(NULL);

	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 * mmi_umms_app_core_display_bgsr_popup
 *
 * DESCRIPTION
 *  To display BGSR popup
 * PARAMETERS
 *  in_msg              [IN]
 * RETURNS
 *  MMI_RET
 *****************************************************************************/
MMI_RET mmi_umms_app_core_display_bgsr_popup (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
					
		return MMI_RET_OK;
		
}

#ifdef __MMI_MMS_USE_ASM__
mmi_ret mmi_umms_app_core_asm_success(mmi_event_struct *param)
{
	return MMI_RET_OK;
}
mmi_ret mmi_umms_app_core_asm_stop(mmi_event_struct *param)
{
	return MMI_RET_OK;
}
mmi_ret mmi_umms_app_core_asm_cancel(mmi_event_struct *param)
{
	return MMI_RET_OK;
}
#endif /*__MMI_MMS_USE_ASM__*/


MMI_RET mmi_umms_app_dtmgr_send_set_settings_to_service(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mma_set_settings_req_struct set_setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&set_setting, 0, sizeof(srv_mms_mma_set_settings_req_struct));
    set_setting.user_data = 0;
    set_setting.app_id = MMA_APP_ID_SETTING;
    set_setting.call_back = mmi_umms_app_core_set_setting_rsp_cb;
    srv_mms_set_setting((void*)&set_setting);
    return MMI_RET_OK;
}


MMI_RET mmi_umms_app_core_show_error_popup(mmi_event_struct *evt)
{
	//U8 *error = (U8 *)(evt->user_data);
	//mmi_umms_app_if_show_error_pop_up(*error);	
    return MMI_RET_OK;
}



MMI_RET mmi_umms_app_ui_plug_in_save_object_error_handling(mmi_event_struct *evt)
{
	srv_mms_save_object_event_data_struct *data = (srv_mms_save_object_event_data_struct *)evt->user_data;
	srv_mms_save_obj_req_struct *rsp_user = (srv_mms_save_obj_req_struct *)data->user_data;
	if(rsp_user->save_obj_fn /*&& rsp_user->is_preview == MMI_TRUE*/)
	{
			rsp_user->save_obj_fn(rsp_user->user_data, EVT_ID_SRV_SAVE_OBJECTS_ERROR, (void *)data);
	}
	return MMI_RET_OK;
}


MMI_RET mmi_umms_app_core_handle_template_error_event(mmi_event_struct *evt)
{
	//S32 *result = (S32 *)evt->user_data;
	//mmi_umms_app_ui_plug_in_template_error_popup_handling(*result);
	return MMI_RET_OK;
}


#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_update_template_list_after_phone_suite_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_umms_app_core_update_template_list_after_phone_suite_delete(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	return MMI_RET_OK;
}
#endif



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_userdef_template_del_from_phone_suite_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_umms_app_dtmgr_set_userdef_template_del_from_phone_suite_flag(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	return MMI_RET_OK;
}


MMI_RET mmi_umms_app_core_show_popup(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  #ifdef __MMI_MMS_MMA_MMS_OBJECT_IND__
   // COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_FULL_INDICATION, g_full_ind_counter, g_obj_ind_flag);

    /* For Object indication interaction between MMS Application and send-receive core, after every 60th Full Ind, 
       MMS Application will show full popup to user.*/
    if((srv_mms_get_obj_ind_flag() == MMI_TRUE) && (((srv_mms_get_full_ind_counter() - 1)%SRV_MMS_SHOW_FULL_POPUP_COUNT) != 0))
    {
        srv_mms_set_obj_ind_flag(MMI_FALSE);
        return MMI_RET_OK;
    }
    srv_mms_set_obj_ind_flag(MMI_FALSE);
#endif
     if(srv_mms_is_wap_ready())
	 {	    
	    vapp_mms_show_full_pop_up(evt);
	 }
	 return MMI_RET_OK;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_show_mms_status_icon
 * DESCRIPTION
 *  To show MMS indicator icon
 * PARAMETERS
 *  status      [IN]        
 * STATUS
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_umms_app_core_show_mms_status_icon(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     /*if(srv_mms_is_wap_ready())
	 {

	const U32 *status = (U32 *)(evt->user_data);
	if((*status) == UMMS_STATUS_FULL)
	{
		ShowStatusIcon(STATUS_ICON_MMS_FULL);
		BlinkStatusIcon(STATUS_ICON_MMS_FULL);
	}
	else
	{
		HideStatusIcon(STATUS_ICON_MMS_FULL);
	}
	 }*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if(MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
#else /* #if(MMI_MAX_SIM_NUM >= 2) */ 
/* under construction !*/
#endif /* #if(MMI_MAX_SIM_NUM >= 2) */ 
/* under construction !*/
/* under construction !*/
    #if(MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
    #endif /* #if(MMI_MAX_SIM_NUM >= 2) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if(MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
    #endif /* #if(MMI_MAX_SIM_NUM >= 2) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if(MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
    #endif /* #if(MMI_MAX_SIM_NUM >= 2) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if(MMI_MAX_SIM_NUM >= 2)
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
    #endif /* #if(MMI_MAX_SIM_NUM >= 2) */ 
/* under construction !*/
/* under construction !*/
    #if(MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
    #endif /* #if(MMI_MAX_SIM_NUM >= 2) */ 
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
	return MMI_RET_OK;
}


MMI_RET mmi_umms_app_core_save_rsp_from_uc(mmi_event_struct *evt)
{

	return MMI_RET_OK;
}


MMI_RET mmi_umms_app_core_bootup_init(mmi_event_struct *evt)
{
	#if 0
/* under construction !*/
	#endif

	#if defined(__MMI_OP11_HOMESCREEN__)
/* under construction !*/
/* under construction !*/
    #endif

    #if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    mmi_umms_op_init_hs32_context();
    mmi_umms_op_reset_op11_hs32_data();
	#endif

	#ifdef __MMI_OP12_TOOLBAR__
		mmi_umms_op_init_tb_context();
        mmi_umms_op_reset_op12_data();
	#endif
#ifdef __DM_LAWMO_SUPPORT__
    if (mmi_dmui_lawmo_register_notify(MMI_DMUI_APP_ID_MMS, MMI_DMUI_MO_TYPE_LAWMO_LOCK, mmi_umms_app_core_mo_type_lawmo_lock_callback_hdlr) < 0)
    {
	/* error handling or assert */
    }
    if (mmi_dmui_lawmo_register_notify(MMI_DMUI_APP_ID_MMS, MMI_DMUI_MO_TYPE_LAWMO_WIPE, mmi_umms_app_core_mo_type_lawmo_wipe_callback_hdlr) < 0)
    {
	/* error handling or assert */
    }
#endif /*__DM_LAWMO_SUPPORT__*/

	/*srv_mms_mem_mgr_init_app_asm_pool(
        APPLIB_MEM_AP_ID_UMMS,
		STR_ID_VAPP_MMS_VIEWER_APP,
		IMG_ID_MMS_VIEWER_APP,
        mmi_ummsapp_core_mms_app_asm_stop_callback,
        mmi_umms_app_core_mms_app_asm_success_callback);*/

    /*srv_mms_mem_mgr_init_viewer_asm_pool(
        APPLIB_MEM_AP_ID_MMS_VIEWER,
		STR_GLOBAL_MULTIMEDIA_MESSAGE,
		IMG_ID_MMS_VIEWER_APP,
        mmi_umms_app_core_asm_viewer_stop_callback,
        mmi_umms_app_core_asm_viewer_success_callback);*/

	return MMI_RET_OK;

}




/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_display_invalid_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_umms_app_core_display_invalid_popup(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_INVALID), MMI_EVENT_FAILURE);
    //mmi_umms_app_if_show_display_popup_screen();
	vapp_mms_uri_show_invalid_popup();
	return MMI_RET_OK;
}


#ifdef __MMI_MMS_URI_AGENT__

#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_mms_display_uri_confirm_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_umms_app_core_mms_display_uri_confirm_popup(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vapp_mms_show_uri_confirm_pop_up(evt);
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
#endif
        return MMI_RET_OK;

}
#endif /*(defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__)) */ 
#endif /* __MMI_MMS_URI_AGENT__ */ 
MMI_RET mmi_umms_app_core_update_use_details_list(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_update_use_details_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_umms_app_core_update_use_details_list(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
		
		return MMI_RET_OK;
	}
#endif /*__MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__*/


/*****************************************************************************
 * FUNCTION
  *  mmi_umms_app_core_exit_viewer_application
 * DESCRIPTION
 *  deinit and go back
 * PARAMETERS
 *  result              [IN]        
 *  file_error_type     [IN]        
 *  srv_mms_result_enum(?)
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_umms_app_core_exit_viewer_application(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_check_crnt_selected_msg_for_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_umms_app_core_check_crnt_selected_msg_for_update(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	return MMI_RET_OK;
}


#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_app_core_get_recent_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_app_core_get_hs_active(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_RET mmi_umms_app_core_set_new_mms_arrived(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  return MMI_RET_OK;

}   

#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_check_crnt_selected_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_umms_app_core_check_crnt_selected_msg(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	return MMI_RET_OK;
}

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
#endif /*0*/
MMI_RET mmi_umms_app_core_mms_update_status_hdlr(mmi_event_struct *evt)
{
	srv_mms_base_event_struct* param =  (srv_mms_base_event_struct*) evt;
	static U32 msg_id = 0;

	
	switch (param->evt_id)
    {
        
		case EVT_ID_SRV_MMS_UPDATE_STATUS:
			 {
				 srv_mms_update_status_struct * sender_data =  (srv_mms_update_status_struct*)  param->sender_data;
				
				if(!msg_id || (msg_id == sender_data->msg_id))
				{
					 switch (sender_data->status)
                     {
	                     case SRV_MMS_MSG_STATUS_DOWNLOADING:
			               {
							   if(!msg_id)
							   {
							      msg_id = sender_data->msg_id;
								 ShowStatusIcon(STATUS_ICON_MMS_RECEIVING);
								 UpdateStatusIcons();
		                          AnimateStatusIcon(STATUS_ICON_MMS_RECEIVING);
		                          UpdateStatusIcons();
	                           }
					       }
                           break;
                        case SRV_MMS_MSG_STATUS_DOWNLOADED:
			               {
							  if(msg_id)
							  {
					              msg_id = 0;
								  HideStatusIcon(STATUS_ICON_MMS_RECEIVING);
							  }
                           }
                           break;
						case SRV_MMS_MSG_STATUS_PENDING_DOWNLOAD:
			               {
					          if(msg_id)
							  {
					              msg_id = 0;
								  HideStatusIcon(STATUS_ICON_MMS_RECEIVING);
							  }
                           }
                           break;
						 case SRV_MMS_MSG_STATUS_DOWNLOADING_FAILED:
			               {  
							  if(msg_id)
							  {
					              msg_id = 0;
								  HideStatusIcon(STATUS_ICON_MMS_RECEIVING);
							  }
					       }
                           break;
					}
				}
            }
            break;
	}
	return MMI_RET_OK;
}


MMI_RET mmi_umms_app_core_wap_ready_hdlr(mmi_event_struct *evt)
{
	//mmi_umms_op_wap_ready_hdlr();

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*0*/
	//COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_WAP_READY);

    mmi_frm_cb_reg_event(EVT_ID_SRV_MMS_UPDATE_STATUS, mmi_umms_app_core_mms_update_status_hdlr, 0); 
	return MMI_RET_OK;
}





MMI_RET mmi_umms_app_core_get_storage_full_ind_data(mmi_event_struct *evt)
{
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
#ifdef __DM_LAWMO_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__DM_LAWMO_SUPPORT__*/
/* under construction !*/
#ifdef __MMI_MMS_MMA_MMS_OBJECT_IND__
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
	return MMI_RET_OK;
}




MMI_RET mmi_umms_app_core_memory_status_screen_update(mmi_event_struct *evt)
{

   	return MMI_RET_OK;
}



MMI_RET mmi_umms_app_core_check_card_plug_out_handling(mmi_event_struct *evt)
{
	/* SIM hot plug-out is not supported yet  */
	return MMI_RET_OK;
}




MMI_RET mmi_umms_app_core_mms_display_popup_for_bgsr(mmi_event_struct *evt)
{
return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *	mmi_umms_app_core_nmgr_alert
 * DESCRIPTION
 *	
 * PARAMETERS
 *	evt 	[?] 	
 * RETURNS
 *	
*****************************************************************************/
mmi_ret mmi_umms_app_core_nmgr_alert(mmi_event_struct *evt)
{ 
	return MMI_RET_OK;
}

mmi_ret mmi_umms_app_core_mma_insuf_mem(mmi_event_struct *param)
{
		//mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_INSUFFICIENT_MEMORY), MMI_EVENT_PROPLEM);
        //mmi_umms_app_if_show_display_popup_screen();
		return MMI_RET_OK;
}



mmi_ret mmi_umms_app_core_mms_deinit(mmi_event_struct *param)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	 return MMI_RET_OK;
}


#endif /* __MMI_MMS_2__ */ 

