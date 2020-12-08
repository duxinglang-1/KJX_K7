/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_mms_common.cpp
 *
 * Project:
 * --------
 *  
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * -------
 *  
 ============================================================================
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/

/***************************************************************************** 
 * Include
 *****************************************************************************/
// This include is for proc call
#include "MMI_features.h"
#include "vapp_msg_features.h"

#ifdef __MMI_MMS_2__
extern "C"
{
#include"mma_struct.h"
//#include "CommonScreens.h"
#include "GlobalDefs.h"
#include "SettingProfileEnum.h"
#include "MmsXMLDefSrv.h"
#include "MmsSrvGprot.h"
//#include "SimDetectionstruct.h" 
//#include "SimDetectionStruct.h"
#include "MmsMemoryManagerSrv.h"
#include "mms_sap_struct.h"
#include "MmsSrvExt.h"
#include "MmsSrvProt.h"
#include "Mmi_frm_mem_gprot.h"
#include "notificationgprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
}
#include "vapp_uc_gprot.h"
#include "vadp_mmi_frm.h"
#include "vfx_uc_include.h"
#include "vcp_text_view.h"
#include "vcp_app_scr.h"
#include "vapp_mms_data.h"
//#include "vapp_mms_viewer.h"
#include "vapp_mms_toolbar.h"
#include "vcp_include.h"
#include "ui_core\mvc\vfx_mmi.h"

#include "vcp_status_icon_bar.h"
#include "vcp_page_panel.h"
#include "vcp_list_menu.h"
#include "vcp_popup.h"
#include "vcp_image_button.h"
#include "mmi_rp_vapp_mms_def.h"
#include "vapp_mms_details_viewer.h"
#include "vapp_mms_common.h"
#include "vapp_mms_appcore.h"
#include "vapp_mms_viewer.h"
#include "vcp_global_popup.h"
#include "vapp_mms_gprot.h"

typedef void *(*umms_sync_op_mem_alloc_fn) (kal_uint32);
typedef void (*umms_sync_op_mem_free_fn) (void *);
extern "C"
{
    extern mma_result_enum mma_mms_get_mms_msg_addr_info(kal_uint32 msg_id, mma_msg_addr_info_struct *mms_msg_addr_info, umms_sync_op_mem_alloc_fn mem_alloc_fn,  umms_sync_op_mem_free_fn mem_free_fn);
}

static mmi_id uc_cui_id;

#ifdef __MMI_MMS_URI_AGENT__
#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
static srv_mms_entry_write_struct *data;


static mmi_ret vapp_mms_uri_uc_proc(mmi_event_struct *evt);
static void vapp_mms_uri_uc_launch(void);
static mmi_ret vapp_mms_uri_uc_prepare(mmi_frm_asm_evt_struct *evt);
static void vapp_mms_uri_send_mms(void);
#endif /*((__UNIFIED_COMPOSER_SUPPORT__) || (__MMS_STANDALONE_COMPOSER_SUPPORT__))*/
#endif /*__MMI_MMS_URI_AGENT__*/
void *vapp_mms_alloc_ext(U32 size);
static srv_mms_func_mem_alloc_user_data mms_alloc_ext = NULL;
static void *mms_user_data = NULL;



/*****************************************************************************
 * FUNCTION
 *  vapp_mms_show_error_pop_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  error_result        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_mms_show_error_pop_up(const VfxU8 error_result, VfxScreen *scr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxU16 string = 0;
	//VcpAlertPopup *alertPopup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//VFX_OBJ_CREATE(alertPopup, VcpAlertPopup, scr);

    switch ((mma_result_enum)error_result)
    {
        case MMA_RESULT_OK:
			{
			    VappMmsPopup m_popup(STR_GLOBAL_DONE, VCP_POPUP_TYPE_SUCCESS, scr, NULL);           
			    m_popup.displayPopup();
                return;
			}
        case MMA_RESULT_FAIL:
            string = STR_ID_VAPP_MMS_MMA_RESULT_FAIL;
            break;    
        case MMA_RESULT_FAIL_NOT_READY:
            string = STR_GLOBAL_NOT_AVAILABLE;
            break;
        case MMA_RESULT_FAIL_BUSY:
            string = STR_GLOBAL_BUSY_TRY_LATER;
            break;
        case MMA_RESULT_FAIL_INSUFFICIENT_MEMORY:
			string = STR_GLOBAL_INSUFFICIENT_MEMORY;
            break;
        case MMA_RESULT_FAIL_INSUFFICIENT_STORAGE:
			string = STR_GLOBAL_NOT_ENOUGH_MEMORY;
            break;
        case MMA_RESULT_FAIL_MAX_MSG_NUM_REACHED:
        case MMA_RESULT_FAIL_MAX_MSG_REACHED_ON_PHONE_MEMORY:
			string = STR_ID_VAPP_MMS_RESULT_FAIL_MAX_MSG_NUM_REACHED;           
            break;
        case MMA_RESULT_FAIL_MAX_MSG_SIZE_REACHED:
			string = STR_ID_VAPP_MMS_RESULT_FAIL_MAX_MSG_SIZE_REACHED;
            break;
        case MMA_RESULT_FAIL_FILE_NOT_FOUND:
			string = STR_GLOBAL_FILE_NOT_FOUND;            
            break;
        case MMA_RESULT_FAIL_FILE_CORRUPTED:
			string = STR_ID_VAPP_MMS_RESULT_FAIL_FILE_CORRUPTED;           
            break;
        case MMA_RESULT_FAIL_FILE_IN_USE:
			string = STR_ID_VAPP_MMS_RESULT_FAIL_FILE_IN_USE;
            break;
        case MMA_RESULT_FAIL_FILE_IO:
			string = STR_ID_VAPP_MMS_RESULT_FAIL_FILE_IO;
            break;
        case MMA_RESULT_FAIL_UNSUPPORT_CONTENT:
			string = STR_ID_VAPP_MMS_RESULT_FAIL_UNSUPPORT_CONTENT;
            break;
        case MMA_RESULT_FAIL_INVALID_PARAMETER:
			string = STR_ID_VAPP_MMS_RESULT_FAIL_INVALID_PARAMETER;
            break;
        case MMA_RESULT_FAIL_MAX_SLIDE_NUM_REACHED:
			string = STR_ID_VAPP_MMS_RESULT_FAIL_MAX_SLIDE_NUM_REACHED;
            break;
        case MMA_RESULT_FAIL_MAX_ATTACHMENT_NUM_REACHED:
			string = STR_ID_VAPP_MMS_RESULT_FAIL_MAX_ATTACHMENT_NUM_REACHED;
            break;
        case MMA_RESULT_FAIL_INVALID_MSGID:
			string = STR_ID_VAPP_MMS_RESULT_FAIL_INVALID_MSGID;
            break;
        case MMA_RESULT_FAIL_INVALID_FOLDER:
			string = STR_ID_VAPP_MMS_RESULT_FAIL_INVALID_FOLDER;
            break;
        case MMA_RESULT_FAIL_PARSE:
			string = STR_ID_VAPP_MMS_RESULT_FAIL_PARSE;
            break;
        case MMA_RESULT_FAIL_MSGID_IS_USING:
			string = STR_ID_VAPP_MMS_RESULT_FAIL_MSGID_IS_USING;
            break;
        case MMA_RESULT_FAIL_CREATION_MODE_MAX_MSG_SIZE_REACHED:
			string = STR_ID_VAPP_MMS_RESULT_FAIL_CREATION_MODE_MAX_MSG_SIZE_REACHED;
            break;
        
        case MMA_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE:
			string = STR_ID_VAPP_MMS_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE;
            break;
        case MMA_RESULT_FAIL_IN_VIDEO_CALL:
			string = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL;
            break;
        case MMA_RESULT_FAIL_IMAGE_TOO_LARGE:
			string = STR_ID_VAPP_MMS_RESULT_FAIL_FILE_LARGE;
            break;
        case MMA_RESULT_FAIL_ROOT_DIR_FULL:
			string = STR_ID_VAPP_MMS_ROOT_DIR_FULL;
            break;
        default:
			string = STR_ID_VAPP_MMS_MMA_RESULT_FAIL;
            break;

    }
           VappMmsPopup m_popup(string, VCP_POPUP_TYPE_FAILURE, scr, NULL);           
			m_popup.displayPopup();
    return;

}

/*****************************************************************************
 * FUNCTION
 *  vapp_mms_show_bgsr_pop_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  error_result        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret vapp_mms_show_bgsr_pop_up(mmi_event_struct* evt)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_SLIM_MMS_2__
/* under construction !*/
#else
/* under construction !*/
#endif /* __MMI_SLIM_MMS_2__ */  
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_SLIM_MMS_2__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#if(MMI_MAX_SIM_NUM >= 2)
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
#if(MMI_MAX_SIM_NUM >= 2)
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
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SLIM_MMS_2__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif/*0*/
		return MMI_RET_OK;
}





/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VfxU16 vapp_mms_get_msg_icon(VfxU8 msg_status)
{
 
   switch(msg_status)
   {
                case MMA_MSG_ICON_STATUS_JAVA_MMS:
			return IMG_ID_VENUS_MMS_JAVA;
		case MMA_MSG_ICON_STATUS_PRIO_HIGH_MMS:
			return IMG_ID_VENUS_MMS_HIGH_PRIORITY;
		case MMA_MSG_ICON_STATUS_PRIO_LOW_MMS:
			return IMG_ID_VENUS_MMS_LOW_PRIORITY;
		case MMA_MSG_ICON_STATUS_PRIO_MED_MMS:
			return IMG_ID_VENUS_MMS_NORMAL_PRIORITY;
        case MMA_MSG_ICON_STATUS_NOTIFICATION_MMS:
			return IMG_ID_VENUS_MMS_NOTIFICATION_ICON;
		case MMA_MSG_ICON_STATUS_SEND_FAIL:	
			return IMG_ID_VENUS_MMS_SEND_FAIL;
		case MMA_MSG_ICON_STATUS_NONE:
		case MMA_MSG_ICON_STATUS_WAITING_FOR_SEND:
		case MMA_MSG_ICON_STATUS_SENDING:
		case MMA_MSG_ICON_STATUS_POSTPONE_FOR_SEND:
		case MMA_MSG_ICON_STATUS_CORRUPTED_MMS:
		case MMA_MSG_ICON_STATUS_DRAFT_MMS:
		case MMA_MSG_ICON_STATUS_DR_MMS:
		case MMA_MSG_ICON_STATUS_RR_MMS:
		default:
		   return 0;
   }
}

void vapp_mms_start_uc(vapp_mms_start_uc_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    VappUcEntryStruct *req;
    //mma_result_enum uc_error = MMA_RESULT_OK;
	//MMI_ID parent_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (VappUcEntryStruct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(VappUcEntryStruct));
	ASSERT(req);
    memset(req, 0, sizeof(VappUcEntryStruct));
    req->app_id = MMA_APP_ID_MMS_APP;
    req->mode = para->uc_mode;
#if(MMI_MAX_SIM_NUM >= 2)
    req->sim_id = (srv_uc_sim_id)srv_mms_convert_to_uc_sim_id(para->sim_id);
#else 
    req->sim_id = SRV_UC_SIM_ID_UNCLASSIFIED;
#endif/*MMI_MAX_SIM_NUM*/ 
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    req->curr_storage = para->storage_type;
#else 
    req->curr_storage = 0;
#endif/*__MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__*/ 

    req->edit_mode = para->edit_mode;
    req->msg_id = para->msg_id;
	req->type = (srv_uc_state_enum)para->uc_type;
	req->operation = (vappUcMsgOperationEnum)para->uc_op; 
	req->info_type = SRV_UC_INFO_TYPE_MMS;
    //COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_ENTRY_DUMMY_SCR);
    //vappUcAppLauncher(req);
    uc_cui_id = vcui_unifiedcomposer_create(para->grp_id, req);
	mmi_frm_group_set_caller_proc(uc_cui_id, vapp_mms_proc, (void*)&uc_cui_id);
	if(uc_cui_id != GRP_ID_INVALID)
	{
		vcui_unifiedcomposer_run(uc_cui_id);
	}
    /*if (uc_error != MMA_RESULT_OK)
    {
        srv_mms_send_events(EVT_ID_SRV_BGSR_RESULT, (void *)&uc_error);
    }*/
    srv_mms_mem_mgr_app_adm_free(req);

    return ;
}
mmi_ret vapp_mms_proc(mmi_event_struct *evt)
{
	switch(evt->evt_id)
    {
		case EVT_ID_CUI_UC_MSGCOMPOSER_CLOSE:
			vcui_unifiedcomposer_close(uc_cui_id);
			uc_cui_id = GRP_ID_INVALID;
			break;
		default:
			break;
	}
    return MMI_RET_OK;
}

#ifdef  __MMI_MMS_REPORT_STATUS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  vapp_mms_get_string_for_msg_dr_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  
 *****************************************************************************/
VfxU16 vapp_mms_get_string_for_msg_dr_status(VfxU8 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  	
    switch (status)
    {
        case MMA_DR_STATUS_RETRIEVED:
            return STR_ID_UMMS_STATUS_DELIVERED;
        case MMA_DR_STATUS_FORWARDED:
            return STR_ID_UMMS_STATUS_DELIVERED;
        case MMA_DR_STATUS_DEFERRED:
            return STR_ID_UMMS_STATUS_PENDING;
        case MMA_DR_STATUS_PENDING:
            return STR_ID_UMMS_STATUS_PENDING;
        case MMA_DR_STATUS_EXPIRED:
            return STR_GLOBAL_FAILED;
        case MMA_DR_STATUS_REJECTED:
            return STR_GLOBAL_FAILED;
        case MMA_DR_STATUS_UNRECOGNISED:
            return STR_ID_UMMS_STATUS_DELIVERED;
        case MMA_DR_STATUS_UNREACHABLE:
            return STR_GLOBAL_FAILED;
        case MMA_DR_STATUS_INDETERMINATE:
            return STR_ID_UMMS_STATUS_PENDING;
    }
	return STR_ID_UMMS_STATUS_PENDING;
}



/*****************************************************************************
 * FUNCTION
 *  vapp_mms_get_string_for_msg_rr_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *            
 * RETURNS
 *  
 *****************************************************************************/
VfxU16 vapp_mms_get_string_for_msg_rr_status(VfxU8 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (status)
    {
        case MMA_RR_STATUS_READ:
            return STR_ID_UMMS_STATUS_READ;
        case MMA_RR_STATUS_DELETED_NO_READ:
            return STR_ID_UMMS_STATUS_PENDING;
        case MMA_RR_STATUS_PENDING:
            return STR_ID_UMMS_STATUS_PENDING;
    }
	return STR_ID_UMMS_STATUS_PENDING;
}


#endif/*__MMI_MMS_REPORT_STATUS_SUPPORT__*/


VfxBool vapp_mms_show_uri_invalid_pop_up_cb(mmi_scenario_id scen_id, void *arg)
{
	vcp_global_popup_show_confirm_one_button_id(
                GRP_ID_ROOT,
                VCP_POPUP_TYPE_FAILURE,
                STR_GLOBAL_INVALID_URL,
                STR_GLOBAL_OK,
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                NULL,
                NULL
                );
				  
	return VFX_TRUE;
}

extern "C" void vapp_mms_uri_show_invalid_popup(void)
{
	mmi_frm_nmgr_notify_by_app(
           MMI_SCENARIO_ID_MMS_INFO, 
           MMI_EVENT_FAILURE, 
           (mmi_noti_scrn_func_ptr)&vapp_mms_show_uri_invalid_pop_up_cb,
           NULL);    				  
}

#ifdef __MMI_MMS_URI_AGENT__
#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
/*****************************************************************************
 * FUNCTION
 *  vapp_mms_show_uri_confirm_pop_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  error_result        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" mmi_ret vapp_mms_show_uri_confirm_pop_up(mmi_event_struct* evt)
{

	if(evt->user_data)
	{   
    

		data = (srv_mms_entry_write_struct *)evt->user_data;
        vapp_mms_uri_uc_launch();

	   
    }
	else
	{
		mmi_frm_nmgr_notify_by_app(
           MMI_SCENARIO_ID_MMS_INFO, 
           MMI_EVENT_QUERY , 
           (mmi_noti_scrn_func_ptr)&vapp_mms_show_uri_confirm_pop_up_cb,
           NULL);

	}
	
	return MMI_RET_OK;
}



VfxBool vapp_mms_show_uri_confirm_pop_up_cb(mmi_scenario_id scen_id, void *arg)
{
		vcp_global_popup_show_confirm_two_button_id(
                GRP_ID_ROOT,
                VCP_POPUP_TYPE_QUESTION,
                STR_ID_VAPP_MMS_SEND_MMS_CONFIRM,
                STR_GLOBAL_SEND,
                STR_GLOBAL_CANCEL,
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                VCP_POPUP_BUTTON_TYPE_CANCEL,
                vapp_mms_uri_confirm_cb,
                NULL
                );
	return VFX_TRUE;
}


static mmi_ret vapp_mms_uri_uc_proc(mmi_event_struct *evt)
{
	mmi_group_event_struct *groupEvent = (mmi_group_event_struct*)evt;
    mmi_id senderId = groupEvent->sender_id;

	switch(evt->evt_id)
    {
		case EVT_ID_CUI_UC_MSGCOMPOSER_CLOSE:
			vcui_unifiedcomposer_close(senderId);
			break;

        case EVT_ID_ASM_FORCE_FREE:
            mmi_frm_group_close(VAPP_MMS_SEND_URI);
            break;

        case EVT_ID_GROUP_DEINIT:
            
            break;

		default:
			break;
	}

    return MMI_RET_OK;
}

static void vapp_mms_uri_uc_launch(void)
{
    if (mmi_frm_group_get_state(VAPP_MMS_SEND_URI) == MMI_SCENARIO_STATE_NONE)
    {
        mmi_frm_asm_property_struct property;

        mmi_frm_group_create(GRP_ID_ROOT, VAPP_MMS_SEND_URI, vapp_mms_uri_uc_proc, NULL);
        mmi_frm_group_enter(VAPP_MMS_SEND_URI, MMI_FRM_NODE_SMART_CLOSE_FLAG);

        mmi_frm_asm_property_init(&property);
        property.f_prepare_w_reserve = 1;
        mmi_frm_asm_set_property(VAPP_MMS_SEND_URI, &property);

        mmi_frm_asm_prepare(VAPP_MMS_SEND_URI, 0, (mmi_proc_func)vapp_mms_uri_uc_prepare, NULL, MMI_FRM_ASM_F_NONE);
    }
}
static mmi_ret vapp_mms_uri_uc_prepare(mmi_frm_asm_evt_struct *evt)
{   
    switch (evt->evt_id)
    {
    case EVT_ID_ASM_CANCELED:
        mmi_frm_group_close(VAPP_MMS_SEND_URI);
		srv_mms_de_init_uri();
        break;

    case EVT_ID_ASM_PREPARED:
        vapp_mms_uri_send_mms();
        break;
    }

    return MMI_RET_OK;
}
static void vapp_mms_uri_send_mms(void)
{
    
        VappUcEntryStruct *uc_data;
		uc_data = (VappUcEntryStruct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(VappUcEntryStruct));
	    ASSERT(uc_data);
        memset(uc_data, 0, sizeof(VappUcEntryStruct));

        uc_data->addr_num = data->addr_num;
		uc_data->addr = data->addr;
		uc_data->text_buffer = data->text_buffer;
		uc_data->text_num = data->text_num;
		uc_data->subject = data->subject;
		uc_data->callback = (vmsgc_func_ptr)data->callback;
		
		uc_data->msg_type = SRV_UC_MSG_TYPE_MMS_ONLY;
        uc_data->info_type = SRV_UC_INFO_TYPE_MMS;
		uc_data->operation = UC_OPERATION_WRITE_NEW_MSG;
		uc_data->type = SRV_UC_STATE_WRITE_NEW_MSG ;
        
		uc_cui_id = vcui_unifiedcomposer_create(VAPP_MMS_SEND_URI, uc_data);
	    
	    if(uc_cui_id != GRP_ID_INVALID)
	    {
		    vcui_unifiedcomposer_run(uc_cui_id);
	    }
	else
	{
            mmi_frm_group_close(VAPP_MMS_SEND_URI);
    }
        srv_mms_mem_mgr_app_adm_free(uc_data);
	
}

mmi_ret vapp_mms_uri_send_mms_evt_proc(mmi_event_struct *evt)
{
    srv_mms_launch_write_msg();

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  vapp_mms_uri_confirm_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void vapp_mms_uri_confirm_cb(VfxId id, void *userData)
{
	if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
	{    
		     mmi_event_struct post_evt;
            MMI_FRM_INIT_EVENT(&post_evt, EVT_ID_SRV_MMS_SEND_URI_IND);
            MMI_FRM_POST_EVENT(&post_evt, vapp_mms_uri_send_mms_evt_proc, NULL);
		
	}
    else if (id == VCP_CONFIRM_POPUP_BUTTON_USER_2)
    {
		srv_mms_send_call_back_to_uri_agnt();
	}
	else if (id == VCP_POPUP_BUTTON_NO_PRESSED)
    {
		srv_mms_send_call_back_to_uri_agnt();
	}
}
#endif /* (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__)) */ /* #ifdef __UNIFIED_COMPOSER_SUPPORT__ */
#endif /* __MMI_MMS_URI_AGENT__ */ 

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

VfxBool vapp_mms_is_need_show_edit_cnfm(VfxU32 msg_id, VfxU16 *str_id)
{
	srv_mms_sync_msg_info_struct *sync_info = srv_mms_get_sync_msg_info_ex(msg_id);

    if (sync_info->msg_info.is_follow_phone_mms_content_class == KAL_FALSE)
    {
        mma_creation_mode_enum creation_mode;
        creation_mode = srv_mms_compose_settings_creation_mode();
      
        if (creation_mode == MMA_CREATION_MODE_RESTRICTED)
        {
              *str_id = STR_ID_VAPP_MMS_RESTRICTED_MODE;
			  return VFX_TRUE;
        }
        else if (creation_mode == MMA_CREATION_MODE_WARNING)
        {
			  *str_id = STR_ID_VAPP_MMS_MODE_WARNING_CONFIRM;
			  return VFX_TRUE;
        }
        else
        {
            return VFX_FALSE;
		}
    }
    else
    {
        return VFX_FALSE;     
	}
}


/*****************************************************************************
 * FUNCTION
 *  vapp_mms_convert_mma_sim_to_mmi_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_sim_enum vapp_mms_convert_mma_sim_to_mmi_sim(kal_uint8 sim_id)
{
	switch (sim_id)
    {
        case MMA_SIM_ID_SIM1:
            return MMI_SIM1;

        case MMA_SIM_ID_SIM2:
            return MMI_SIM2;

        default:
            return MMI_SIM1;
    }
}

void *vapp_mms_alloc_ext(kal_uint32 size)
{
	return mms_alloc_ext(size, mms_user_data);
}


void vapp_mms_send_msg(srv_mms_send_req_struct *req, srv_mms_func_mem_alloc_user_data alloc_fn, srv_mms_func_mem_free free_fn, void *user_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*U8 count = 0;
	U8 counter = 0;
	U32 msg_id = 0;
	mma_result_enum result = MMA_RESULT_OK;
	mma_msg_addr_info_struct *mms_msg_addr_info = NULL;
	umms_sync_op_mem_alloc_fn vapp_alloc_fn  = vapp_mms_alloc_ext;
	umms_sync_op_mem_free_fn  vapp_free_fn = free_fn;*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/*msg_id = req->msg_id;
	mms_alloc_ext = alloc_fn;
	mms_user_data = user_data;
     mms_msg_addr_info = (mma_msg_addr_info_struct *)vapp_mms_alloc_ext(SRV_MMS_MAX_SUPPORT_ADDR_COUNT * sizeof(mma_msg_addr_info_struct));
    result = mma_mms_get_mms_msg_addr_info(msg_id, mms_msg_addr_info,  vapp_alloc_fn, vapp_free_fn);

    if(result != MMA_RESULT_OK)
	{
		free_fn(mms_msg_addr_info);
        return ;
	}

    while(counter < SRV_MMS_MAX_SUPPORT_ADDR_COUNT)
	{
        if(mms_msg_addr_info[counter].address[0] != '\0')
		{
             srv_phb_set_preferred_sim (
               (U16*)mms_msg_addr_info[counter].address,
               MMI_PHB_INVALID_CONTACT_ID,
               (mmi_sim_enum)req->sim_id,
               SRV_PHB_NUMBER_OP_TYPE_MESSAGE);

			 counter++;
		}
		else
		{
			break;
		}
	}*/
	srv_mms_send(req);
	/*free_fn(mms_msg_addr_info);
	mms_alloc_ext = NULL;
	mms_user_data = NULL;*/
	return ;
}

VfxBool vapp_mms_show_phone_full_pop_up_cb(mmi_scenario_id scen_id, void *arg)
{
	vcp_global_popup_show_confirm_one_button_id(
                GRP_ID_ROOT,
                VCP_POPUP_TYPE_INFO,
                STR_ID_VAPP_MMS_PHONE_FULL,
                STR_GLOBAL_OK,
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                NULL,
                NULL
                );
				  
	return VFX_TRUE;
}

VfxBool vapp_mms_show_mem_card_full_pop_up_cb(mmi_scenario_id scen_id, void *arg)
{
	vcp_global_popup_show_confirm_one_button_id(
                GRP_ID_ROOT,
                VCP_POPUP_TYPE_INFO,
                STR_ID_VAPP_MMS_MEMORY_CARD_FULL,
                STR_GLOBAL_OK,
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                NULL,
                NULL
                );
				  
	return VFX_TRUE;
}
extern "C" mmi_ret vapp_mms_show_full_pop_up(mmi_event_struct* evt)
{
	   srv_mms_mem_status_event_struct *event_data = (srv_mms_mem_status_event_struct *)evt;
       if(event_data->mms_mem_status == SRV_MMS_MEM_STATUS_PHONE_COUNT_ALREADY_MAX)
	   {
		mmi_frm_nmgr_notify_by_app(
           MMI_SCENARIO_ID_MMS_INFO, 
           MMI_EVENT_QUERY , 
           (mmi_noti_scrn_func_ptr)vapp_mms_show_phone_full_pop_up_cb,
           NULL);
	   }
	   else if(event_data->mms_mem_status == SRV_MMS_MEM_STATUS_CARD_COUNT_ALREADY_MAX)
	   {
		   mmi_frm_nmgr_notify_by_app(
           MMI_SCENARIO_ID_MMS_INFO, 
           MMI_EVENT_QUERY, 
           (mmi_noti_scrn_func_ptr)vapp_mms_show_mem_card_full_pop_up_cb,
           NULL);
	   }
		return MMI_RET_OK;
}

#endif/*__MMI_MMS_2__*/
