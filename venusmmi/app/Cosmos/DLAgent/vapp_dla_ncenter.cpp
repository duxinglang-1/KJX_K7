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
 *  vapp_dla_ncenter.cpp
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"
#include "vapp_dla_ncenter.h"
#include "vapp_usb_gprot.h"
#include "vcp_global_popup.h"
#include "mmi_rp_app_ncenter_def.h"
#include "NotificationGprot.h"
#include "mmi_rp_srv_status_icons_def.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __CPLUSPLUS__ */

#include "USBSrvGprot.h"
#include "DLAgentSrvProt.h"

#ifdef __cplusplus
}
#endif /* __CPLUSPLUS__ */


VsrvNGroupSingleTitle *m_DLAgent_Group;
extern void onPauseSuccess (srv_da_job_struct *arg, U16 string_id);

typedef struct 
{
    MMI_EVT_PARAM_HEADER
    VfxS32		popup_id;
} vapp_da_cancel_global_popup_event_struct;


VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VAppDLAgentNCenterInterface);

//terminate DLAgent App first and then show job list for each case
void DLAgentNCenterIntentCallback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize)
{
	if(intent.type == VSRV_NINTENT_TYPE_LAUNCH)
	{
		srv_da_display_job_list_event_struct	evt;
		U32										job_id;
		memcpy(&job_id, userData, sizeof(U32));
		MMI_FRM_INIT_EVENT(&evt, EVT_ID_DLA_SRV_DISPLAY_JOB_LIST);
		evt.job = srv_da_job_get_job_by_id(job_id);
		//for some case, the job will be NULL for some completed download,     eg: MAUI_03192467
		evt.check_complete = MMI_FALSE;
		if(evt.job == NULL)
			evt.list_type = SRV_DA_LIST_TYPE_COMPLETED;
		else
		    evt.list_type = (evt.job->state == SRV_DA_JOB_STATE_COMPLETED? SRV_DA_LIST_TYPE_COMPLETED: SRV_DA_LIST_TYPE_DOWNLOADED);
		MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);
	}
}

mmi_ret DLAgentNSSCallback(mmi_event_struct *evt)
{
	if (evt->evt_id == EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH || evt->evt_id == EVT_ID_NMGR_POPUP_APP_LAUNCH)
	{
		VsrvNIntent intent;
		intent.type = VSRV_NINTENT_TYPE_LAUNCH;
		DLAgentNCenterIntentCallback(NULL, intent, evt->user_data, 0);
	}
	return MMI_TRUE;
}

mmi_ret vapp_dla_cancel_global_popup(mmi_event_struct *evt)
{
	vapp_da_cancel_global_popup_event_struct *evnt = (vapp_da_cancel_global_popup_event_struct *)evt;
	vcp_global_popup_cancel(evnt->popup_id);
	return MMI_RET_OK;
}

void DLAgentPushNCenterIntentCallback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize)
{
	srv_da_push_item_struct *active_item;
	active_item = srv_da_push_get_top_screen_stack_item();
	if(intent.type == VSRV_NINTENT_TYPE_LAUNCH)
	{
		if (!active_item)
		{
			return;
		}
		srv_da_push_remove_item_processed (active_item);		
		{
			srv_da_show_choice_screen_event_struct	evt;			
			MMI_FRM_INIT_EVENT(&evt, EVT_ID_DLA_SRV_SHOW_NEW_DOWNLOAD_CONFIRM_SCREEN);
			evt.arg = (void*)active_item;
			//evt.fill_msg_string = srv_da_push_confirm_fill_msg_string;
			evt.lsk_hdlr = srv_da_push_confirm_start_to_download_callback;
			evt.rsk_hdlr = srv_da_push_confirm_cancel_callback;
			evt.delete_hdlr = srv_da_push_confirm_cancel_callback;
			evt.arg_size = sizeof (srv_da_push_item_struct);
			MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);
		}		
		VappDLAgentNCenterNew::vapp_dla_update_ncenter_push_object();
	}
	else if(intent.type == VSRV_NINTENT_TYPE_CLEAR)
	{
		srv_da_push_remove_item_processed (active_item);
		VappDLAgentNCenterNew::vapp_dla_update_ncenter_push_object();
	}
}

mmi_ret DLAgentPushNSSCallback(mmi_event_struct *evt)
{
	if (evt->evt_id == EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH || evt->evt_id == EVT_ID_NMGR_POPUP_APP_LAUNCH)
	{
		VsrvNIntent intent;
		intent.type = VSRV_NINTENT_TYPE_LAUNCH;
		DLAgentPushNCenterIntentCallback(NULL, intent, NULL, 0);		
	}
	return MMI_RET_OK;
}

void DLAgentsetPushNotification(VsrvNotificationEvent* noti)
{
    srv_da_push_item_struct *active_item;	
    active_item = srv_da_push_get_top_screen_stack_item();
	
    VfxU16    *tempFilename = NULL;
    VfxU16    filename[MMI_DA_MAX_FILENAME_INPUT_LEN + 1];
    VfxU16    fileext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    if(active_item->filename)
    {
        tempFilename = srv_da_util_get_filename(active_item->filename);
    }
    else if(active_item->filepath)
    {
        tempFilename = srv_da_util_get_filename(active_item->filepath);
    }
    else
    {
        VFX_ASSERT(0);
    }
    srv_da_extract_filepath(tempFilename, filename, fileext);
	
	VfxWString sub_text;
	sub_text.loadFromMem(filename);

	noti->setIcon(VfxImageSrc(VAPP_IMG_ID_DLA_NC_DOWNLOADING_ICON));
	noti->setMainText(VFX_WSTR_RES(VAPP_STR_DLA_PUSHED_OBJECT));
	noti->setSubText(sub_text);
	noti->setAutoLaunch(VFX_TRUE);
	noti->setAutoClose(VFX_FALSE);
	noti->setIntentCallback(DLAgentPushNCenterIntentCallback);
	noti->notify();
}

void DLAgentsetNSSGeneralParam(mmi_frm_nmgr_alert_struct *alert_info, WCHAR *popup_button_string, mmi_proc_func scrn_group_proc, U32 *job_id)
{
	memset(alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));
	alert_info->app_id = VAPP_DLAGENT;
	alert_info->scen_id = MMI_SCENARIO_ID_DEFAULT;
	alert_info->alert_option = MMI_FRM_NMGR_DISABLE_STATUS_ICON;
	alert_info->ui_mask = MMI_FRM_NMGR_UI_STATUS_BAR_MASK|MMI_FRM_NMGR_UI_POPUP_MASK;
	alert_info->behavior_mask = PREFER_DEFAULT;
	alert_info->status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
	alert_info->status_bar_para.image_type = MMI_NMGR_IMG_RES_ID;
	alert_info->popup_para.popup_type = MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE;
	alert_info->popup_para.image_type = MMI_NMGR_IMG_RES_ID;
	alert_info->popup_para.image.id = VAPP_IMG_ID_DLA_MAIN_ICON;
	alert_info->popup_para.popup_button_string = popup_button_string;
	alert_info->app_proc_para.scrn_group_proc = scrn_group_proc;
	alert_info->app_proc_para.user_data = job_id;
	if(job_id != NULL)
		alert_info->app_proc_para.data_size =  sizeof(U32);
}


void VappDLAgentNCenterNew::vapp_dla_remove_junk_item(VsrvNGroup *group)
{
	int notify_temp_array[10];
	for(int i = 0; i < 10; i++)
	{
	    notify_temp_array[i] = -1;
	}
    VfxList<VsrvNotification*>::It notifies;
	int notify_num = 0;
	for(notifies = group->getNotifications(); !notifies.isNull(); notifies++)
	{
		VsrvNotification *notify = (*notifies);
		srv_da_job_struct *job = srv_da_job_get_job_by_id(notify->getId());
		if(!job)
		{
		    notify_temp_array[notify_num] = notify->getId();			
		}
		notify_num++;
	}
	for(int i = 0; i < 10; i++)
	{
	    if (-1 != notify_temp_array[i])
		{
		    VSRV_NOTIFICATION_CLOSE_EX(group->getId(),notify_temp_array[i]);
		}
	}
}

/*****
1. get the first job
2. create new notification for new job
3. update all cells
*****/

void VappDLAgentNCenterNew::vapp_dla_update_ncenter(void *args, VfxU32 argSize)
{
	VSRV_NGROUP_CREATE_EX(m_DLAgent_Group,VsrvNGroupSingleTitle,(VAPP_DLAGENT));
	//extrat job count that more than those can be displayed
	U32						job_count_extrat = ((srv_da_get_curr_job_count() - VAPP_DLAGENT_NCENTER_CELL_COUNT) > 0 ? srv_da_get_curr_job_count() - VAPP_DLAGENT_NCENTER_CELL_COUNT: 0);
	srv_da_job_struct		*first_job = srv_da_get_first_job();
	srv_da_job_struct		*current_job = NULL;

	vapp_dla_update_statusbar();

	if(first_job == NULL)
	{
		VSRV_NGROUP_CLOSE(m_DLAgent_Group);
		return;
	}

    vapp_dla_remove_junk_item(m_DLAgent_Group);

	VfxWChar titletemp[50] = {L'\0',};
	kal_wsprintf(titletemp, "%w(%d)", VFX_WSTR_RES(VAPP_STR_DLA_DOWNLOAD_AGENT).getBuf(), srv_da_get_curr_job_count());
	VfxWString title;
	title.loadFromMem(titletemp);
	m_DLAgent_Group->setTitle(title);
	while((job_count_extrat--) > 0)
	{
		first_job = first_job->next_job;
	}
	
	current_job = first_job;
	
	while(current_job)
	{
		VSRV_NGROUP_CREATE_EX(m_DLAgent_Group,VsrvNGroupSingleTitle,(VAPP_DLAGENT));
		VsrvNotificationCustom	*ncust = NULL;
		srv_da_job_struct		*job = current_job;
		U32 					job_id = (U32)DA_JOB_GET_ID(job);
		//existed notification
		if((job->type == SRV_DA_JOB_TYPE_YT_DOWNLOAD)||(m_DLAgent_Group->queryNotification(job_id)))			                
		{
			current_job = current_job->next_job;
			continue;
		}
		//create new notification (if the notification has existed, just using it by the MACRO: VSRV_NOTIFICATION_CREATE_EX)
		VSRV_NOTIFICATION_CREATE_EX(ncust, VsrvNotificationCustom, (VAPP_DLAGENT, DA_JOB_GET_ID(job)));
		ncust->setIntentCallback(DLAgentNCenterIntentCallback, &job_id, sizeof(U32));
		ncust->setAutoLaunch(VFX_TRUE);	//call launch callback after NCenter leave animation
		ncust->setAutoClose(VFX_FALSE);	//close notification after clicking the cell
		ncust->addCustomViewInfo(VFX_OBJ_CLASS_INFO(VappDLAgentNcenterBaseCell), VSRV_NVIEWER_TYPE_GENERAL, &job_id, sizeof(U32));
		ncust->notify();
		current_job = current_job->next_job;
	}
	//update contents of all Cells
	VAppDLAgentNCenterInterface::OnNCenterCallback(NULL);
}

void VappDLAgentNCenterNew::vapp_dla_update_ncenter_push_object()
{
	VsrvNGroupSingleTitle *dlagent_push_object_group;
	VSRV_NGROUP_CREATE_EX(dlagent_push_object_group,VsrvNGroupSingleTitle,(VAPP_DLAGENT + 100));
	VsrvNotificationEvent *noti = NULL;
	VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationEvent, (VAPP_DLAGENT + 100, 0));
	//each case will update status bar for push object
	vapp_dla_update_statusbar_push_object();
	if(srv_da_push_get_top_screen_stack_item() == NULL)
	{
		VSRV_NOTIFICATION_CLOSE(noti);
		VSRV_NGROUP_CLOSE(dlagent_push_object_group);		
		return;
	}
	dlagent_push_object_group->setTitle(VFX_WSTR_RES(VAPP_STR_DLA_DOWNLOAD_AGENT));
	DLAgentsetPushNotification(noti);
}

void VappDLAgentNCenterNew::vapp_dla_update_statusbar(void)
{
    VfxU16 job_count = 0;
    job_count = srv_da_count_job(srv_da_job_match_state_func, SRV_DA_JOB_STATE_DOWNLOADING) +
                srv_da_count_job(srv_da_job_match_state_func, SRV_DA_JOB_STATE_PROCESSING);

    if (job_count)
    {
        if (!wgui_status_icon_bar_whether_icon_display(STATUS_ICON_DOWNLOADING))
        {
            wgui_status_icon_bar_show_icon(STATUS_ICON_DOWNLOADING);
        }
    }
    else
    {
        if (wgui_status_icon_bar_whether_icon_display(STATUS_ICON_DOWNLOADING))
        {
            wgui_status_icon_bar_hide_icon(STATUS_ICON_DOWNLOADING);
        }
    }

    job_count = 0;
    job_count = srv_da_count_job(srv_da_job_match_state_func, SRV_DA_JOB_STATE_COMPLETED);
    if (job_count)
    {
        if (!wgui_status_icon_bar_whether_icon_display(STATUS_ICON_DOWNLOAD_COMPLETED))
        {
            wgui_status_icon_bar_show_icon(STATUS_ICON_DOWNLOAD_COMPLETED);
        }
    }
    else
    {
        if (wgui_status_icon_bar_whether_icon_display(STATUS_ICON_DOWNLOAD_COMPLETED))
        {
            wgui_status_icon_bar_hide_icon(STATUS_ICON_DOWNLOAD_COMPLETED);
        }
    }

    job_count = 0;
    job_count = srv_da_count_job(srv_da_job_match_state_func, SRV_DA_JOB_STATE_FAILED);
    if (job_count)
    {
        if (!wgui_status_icon_bar_whether_icon_display(STATUS_ICON_DOWNLOAD_FAILED))
        {
            wgui_status_icon_bar_show_icon(STATUS_ICON_DOWNLOAD_FAILED);
        }
    }
    else
    {
        if (wgui_status_icon_bar_whether_icon_display(STATUS_ICON_DOWNLOAD_FAILED))
        {
            wgui_status_icon_bar_hide_icon(STATUS_ICON_DOWNLOAD_FAILED);
        }
    }
}

void VappDLAgentNCenterNew::vapp_dla_update_statusbar_push_object(void)
{
	srv_da_push_item_struct *active_item;
	active_item = srv_da_push_get_top_screen_stack_item();
    if (active_item)
    {
        if (!wgui_status_icon_bar_whether_icon_display(STATUS_ICON_PUSHED_OBJ))
        {
            wgui_status_icon_bar_show_icon(STATUS_ICON_PUSHED_OBJ);
        }
    }
    else
    {
        if (wgui_status_icon_bar_whether_icon_display(STATUS_ICON_PUSHED_OBJ))
        {
            wgui_status_icon_bar_hide_icon(STATUS_ICON_PUSHED_OBJ);
        }
    }
}

void VappDLAgentNCenterNew::vapp_dla_show_push_notify (void *arg)
{
    srv_da_push_item_struct *item = (srv_da_push_item_struct*)arg;

    //VfxU16                ui_item_buffer [SRV_FMGR_PATH_MAX_LEN + 2] = {'\0',};
    VfxU16                temp_filename[MMI_DA_MAX_FILENAME_INPUT_LEN + 2] = {'\0', };
    VfxU16                ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
	VfxU16				  show_string[MMI_DA_MAX_FILENAME_INPUT_LEN + 20] = {'\0', };
	mmi_frm_nmgr_alert_struct alert_info;
	DLAgentsetNSSGeneralParam(&alert_info, (WCHAR *)VFX_WSTR_RES(STR_GLOBAL_DOWNLOAD).getBuf(), DLAgentPushNSSCallback, NULL);  //push object doesn't need job_id
    srv_da_push_get_filename (item, temp_filename, ext);
    kal_wsprintf(show_string, "%w %w", (U16 *)get_string (VAPP_DLA_STR_NEW_PUSHED_OBJECT), (U16 *)temp_filename);
	alert_info.event_type = MMI_EVENT_UNREAD_MSG;
	alert_info.status_bar_para.display_string = (WCHAR *)show_string;
	#ifdef __MMI_COSMOS_STATUS_BAR_SLIM__
	alert_info.status_bar_para.image.id = IMG_SI_COMMON_NEW;         //used for textpreview
	#else
	alert_info.status_bar_para.image.id = IMG_SI_PUSHED_OBJ;         //used for textpreview
	#endif
	alert_info.popup_para.popup_string = (WCHAR *)show_string;;
	alert_info.status_bar_icon_para.icon_id = STATUS_ICON_PUSHED_OBJ;     //used for statusbar
    mmi_frm_nmgr_alert(&alert_info);
}


void VappDLAgentNCenterNew::vapp_dla_show_job_notify (void *arg)
{
    srv_da_job_struct *job = (srv_da_job_struct*)arg;
	U32					job_id = (U32)DA_JOB_GET_ID(job);	

    //VfxS8                 buffer_temp [300] = {'\0',};
    VfxU16                ui_item_buffer [SRV_FMGR_PATH_MAX_LEN + 2] = {'\0',};
    VfxU16                *temp_str = NULL;

	mmi_frm_nmgr_alert_struct alert_info;
    srv_da_job_get_name(job, ui_item_buffer, SRV_FMGR_PATH_MAX_LEN + 1);
    temp_str = (U16*)srv_da_util_get_filename ((U16*)ui_item_buffer);

    if((job->type == SRV_DA_JOB_TYPE_YT_DOWNLOAD)  
#ifdef __MMI_OMA_DD_DOWNLOAD__
	   || (srv_da_oma_is_oma_processing_required(job->mime_type))
#endif
      )
		return;

	DLAgentsetNSSGeneralParam(&alert_info, (WCHAR *)VFX_WSTR_RES(STR_GLOBAL_VIEW).getBuf(), DLAgentNSSCallback, &job_id);
    if (job->state == SRV_DA_JOB_STATE_FAILED)
    {
	    kal_wsprintf(temp_str, "%w %w", temp_str, (U16 *)get_string (VAPP_STR_DLA_FILES_ARE_FAILED_TO_DOWNLOAD));
		alert_info.event_type = MMI_EVENT_DA_DOWNLOAD_FAILED;
		alert_info.status_bar_para.display_string = (WCHAR *)temp_str;
		#ifdef __MMI_COSMOS_STATUS_BAR_SLIM__
		alert_info.status_bar_para.image.id = IMG_SI_COMMON_ERROR;
		#else
		alert_info.status_bar_para.image.id = IMG_SI_DOWNLOAD_ERROR;
		#endif
		alert_info.popup_para.popup_string = (WCHAR *)temp_str;;
		alert_info.status_bar_icon_para.icon_id = STATUS_ICON_DOWNLOAD_FAILED;
    }
    else
    {
	    kal_wsprintf(temp_str, "%w %w", temp_str, (U16 *)get_string (VAPP_STR_DLA_DOWNLOADED));
		alert_info.event_type = MMI_EVENT_DA_DOWNLOAD_COMPLETED;
		alert_info.status_bar_para.display_string = (WCHAR *)temp_str;
		alert_info.status_bar_para.image.id = IMG_SI_DOWNLOAD_COMPLETE;
		alert_info.popup_para.popup_string = (WCHAR *)temp_str;
		alert_info.status_bar_icon_para.icon_id = STATUS_ICON_DOWNLOAD_COMPLETED;
    }
    mmi_frm_nmgr_alert(&alert_info);
}


void VappDLAgentonGoingCell::onInit()
{
	VappNCenterOngoingCell::onInit();
	VFX_OBJ_CREATE(m_status_button, VcpImageButton, this);
	m_status_button->setAnchor(1.0f, 0.5f);
	m_status_button->setPos(VAPP_NCENTER_ONGOING_CELL_WIDTH - VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_X - VAPP_DLAGENT_NCENTER_CELL_ICON_X - VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_WIDTH, VAPP_NCENTER_ONGOING_CELL_HEIGHT/2);
	m_status_button->setSize(VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_WIDTH, VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_HEIGHT);
	m_status_button->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);
	m_status_button->m_signalClicked.connect(this, &VappDLAgentonGoingCell::onStatusButtonClick);
    //set the length of Maintext to show the correct filename with "..."
    m_mainText->setSize(m_mainText->getSize().width - VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_WIDTH - VAPP_DLAGENT_NCENTER_CELL_ICON_X, m_mainText->getSize().height);
    m_mainText->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);
	//to use the notification when the cell is tapped
	this->setNotification(m_DLAgent_Group->queryNotification(((VappDLAgentNcenterBaseCell *)(this->getParent()))->getJobID()));
}

void VappDLAgentonGoingCell::onDeinit()
{
	if(m_popup_id > -1)
	{
		vapp_da_cancel_global_popup_event_struct evt;
		MMI_FRM_INIT_EVENT(&evt, EVT_ID_DLA_NCENTER_CANCEL_GLOBAL_POPUP);
		evt.popup_id = m_popup_id;
		MMI_FRM_POST_EVENT(&evt, vapp_dla_cancel_global_popup, NULL);
	}
	VappNCenterOngoingCell::onDeinit();
}


/*********
1. get job info via job ID from the cell
2. call service API to do corresponding operation
3. fill data to cell
4. to-do: update the status bar
*********/
void VappDLAgentonGoingCell::onStatusButtonClick(VfxObject* sender, VfxId id)
{
	srv_da_job_struct			*job = NULL;
	VappDLAgentNcenterBaseCell	*cell;
	S32 						prev_state;

	cell = (VappDLAgentNcenterBaseCell *)(sender->getParent()->getParent());
	job = srv_da_job_get_job_by_id(cell->getJobID());
	//for some cases, the UI is not updated after the job downloading completed
	if(!job)
	{
		VappDLAgentNCenterNew::vapp_dla_update_statusbar();
		return;
	}
	prev_state = job->state;
	switch(prev_state)
	{
		case SRV_DA_JOB_STATE_DOWNLOADING:
		case SRV_DA_JOB_STATE_WAITING:
            job->state = SRV_DA_JOB_STATE_ABORTING;
            job->was_stopped_by_upper_layer = MMI_TRUE;           
            srv_da_stop_selected_job(job, prev_state, MMI_TRUE, onPauseSuccess);
			break;
		case SRV_DA_JOB_STATE_COMPLETED:
			if (!vapp_da_job_on_use_file_selected (job))
			{
				/* Updating the list in case if use item does not exists */
				vapp_da_app_launch_struct  app_launch;
				app_launch.type = SRV_DA_APP_UPDATE_DOWNLOAD;
				app_launch.arg = NULL;
				app_launch.argSize = sizeof (srv_da_update_job_event_struct);
				VAppDLAgentInterface::OnServiceCallback ((void*)&app_launch);
					
				VappDLAgentNCenterNew::vapp_dla_update_ncenter(NULL, 0);
			}
			break;
		case SRV_DA_JOB_STATE_PAUSED:
		case SRV_DA_JOB_STATE_PAUSED_WAITING:
		case SRV_DA_JOB_STATE_FAILED:
			MMI_ASSERT(srv_da_job_can_resume(job));
            srv_da_set_allow_to_trigger_connection(MMI_TRUE);
            job->reporting = MMI_FALSE;
            if(srv_da_count_job(srv_da_job_match_state_func, SRV_DA_JOB_STATE_DOWNLOADING) +
                srv_da_count_job(srv_da_job_match_state_func, SRV_DA_JOB_STATE_PROCESSING) >= MMI_DA_MAX_DL)
            {
                //do something---showPopup
            }
            else if (srv_da_is_in_voice_call())
            {
                mmi_frm_nmgr_balloon(
                    MMI_SCENARIO_ID_GENERAL,
                    MMI_EVENT_INFO_BALLOON,
                    MMI_NMGR_BALLOON_TYPE_INFO,
                    (WCHAR*)(VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL).getBuf()));
            }
            else
            {
#if defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__) && defined(__MMI_DA_RESUME__)
                srv_da_job_resume(job);
#endif
            }
			break;
		default:

			break;
	}
	if (prev_state != SRV_DA_JOB_STATE_COMPLETED)
		cell->fillNCenterCellData((void *)job);
	VappDLAgentNCenterNew::vapp_dla_update_statusbar();
}

void VappDLAgentonGoingCell::onButtonClick(VfxObject* sender, VfxId id)
{
	VappDLAgentNcenterBaseCell	*cell = NULL;
	cell = (VappDLAgentNcenterBaseCell *)(this->getParent());
	srv_da_job_struct			*job = srv_da_job_get_job_by_id(cell->getJobID());
	VfxResId					textRes, button1Res;

	textRes = VAPP_STR_DLA_DISCARD_DOWNLOADING_CONFIRM;
	button1Res = VAPP_STR_DLA_DISCARD;

	if(job->state == SRV_DA_JOB_STATE_COMPLETED)
	{
		textRes = VAPP_STR_DLA_REMOVE_COMPLETED_CONFIRM;
		button1Res = STR_GLOBAL_REMOVE;
	}
    m_popup_id = vcp_global_popup_show_confirm_two_button_id(
		        GRP_ID_ROOT,
		        VCP_POPUP_TYPE_WARNING,
		        textRes,
		        button1Res,
		        STR_GLOBAL_CANCEL,
		        VCP_POPUP_BUTTON_TYPE_WARNING,
		        VCP_POPUP_BUTTON_TYPE_CANCEL,
		        &VappDLAgentonGoingCell::onConfirmButtonClick,
		        (void *)cell);
}

void VappDLAgentonGoingCell::onConfirmButtonClick (VfxId id, void *userData) 
{
	VappDLAgentNcenterBaseCell	*cell = NULL;
	srv_da_job_struct			*job = NULL;
	//sometimes, the popup will be cancelled without any button being clicked, userdata is invalid  eg: MAUI_03208676
	if ((id == VCP_CONFIRM_POPUP_BUTTON_USER_1) ||(id == VCP_CONFIRM_POPUP_BUTTON_USER_2))
	{
		cell = (VappDLAgentNcenterBaseCell *)userData;
		job = srv_da_job_get_job_by_id(cell->getJobID());
		if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
		{
			if(job->state != SRV_DA_JOB_STATE_COMPLETED)
			{
				srv_da_curr_job_do_abort(job);	 //abort the job first and then free the job
			}
			else 
			{
				srv_da_free_job(job);
				//if App exist, the list menu should be updated
				VappDLAgentApp *m_dlaApp = ((VappDLAgentApp *)VfxAppLauncher::getObject(m_DLAgentAppID));
				if(m_dlaApp != NULL)
				{
					if(m_dlaApp->scr->m_tabbedDownload_page != NULL)
					{
						if(m_dlaApp->scr->m_tabbedDownload_page->m_CompletedPage != NULL)
						{
							if(m_dlaApp->scr->m_tabbedDownload_page->m_CompletedPage->m_completed_list != NULL)
							{
								m_dlaApp->scr->m_tabbedDownload_page->m_CompletedPage->m_completed_list_cp->updateItemContent(NULL);
								m_dlaApp->scr->m_tabbedDownload_page->m_CompletedPage->updateToolBar();
								m_dlaApp->scr->m_tabbedDownload_page->m_CompletedPage->m_completed_list->updateAllItems();				
							}
						}
					}
				}
			}
		}
		vcp_global_popup_cancel(cell->getOnGoingCell()->getPopupID());
	}
	srv_da_send_download_info_ind();
	VappDLAgentNCenterNew::vapp_dla_update_ncenter(NULL, 0);
}

void VappDLAgentonGoingCell::setStatusButtonIcon(const VcpStateImage &imageList)
{
	this->m_status_button->setImage(imageList);
}

VfxS32 VappDLAgentonGoingCell::getPopupID()
{
	return m_popup_id;
}

void VappDLAgentonGoingCell::setStatusButtonEnabled(VfxBool enabled)
{
	m_status_button->setIsDisabled(!enabled);
	if(!enabled)
	{
	    m_status_button->setOpacity(0.5);
	}
}


VFX_IMPLEMENT_CLASS("VappDLAgentNcenterBaseCell", VappDLAgentNcenterBaseCell, VsrvNCell);


//according to the viewDate, drawing the cell
void VappDLAgentNcenterBaseCell::onCreateView(void *viewData,VfxU32 viewDataSize)
{
    //VfxS8                              	buffer_temp [300] = {'\0',};
    //VfxU16                             	file_name_buffer [SRV_FMGR_PATH_MAX_LEN + 2] = {'\0',};
    //VfxU16                             	*temp_str = NULL;
	VfxWString							file_name_string;
	VfxWString							file_size_string;
	void 								*args = NULL;

	//viewData will not be modified when content in customcell is changed, here is the latest value of a job
	args = (void *)srv_da_job_get_job_by_id(*(U32 *)viewData);
	//job maybe have been free before notification is closed, can't be asserted
	if(args == NULL)
		return;
	VsrvNCell::onCreateView(args, viewDataSize);	
	this->setSize(VAPP_NCENTER_ONGOING_CELL_WIDTH, VAPP_NCENTER_ONGOING_CELL_HEIGHT);
	this->setJobID(*(U32 *)viewData);
	VFX_OBJ_CREATE(cell, VappDLAgentonGoingCell, this);
	cell->setSize(VAPP_NCENTER_ONGOING_CELL_WIDTH, VAPP_NCENTER_ONGOING_CELL_HEIGHT);
	cell->setPos(0, 0);
	cell->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
	cell->setIcon(VfxImageSrc(VAPP_IMG_ID_DLA_NC_DOWNLOADING_ICON));
	((VAppDLAgentNCenterInterface *)VFX_OBJ_GET_INSTANCE(VAppDLAgentNCenterInterface))->m_ncenterCallback.connect(this, &VappDLAgentNcenterBaseCell::updateNCenterCellData);
	fillNCenterCellData(args);
}


void VappDLAgentNcenterBaseCell::updateNCenterCellData(void *args)
{
	srv_da_job_struct					*job = NULL;
	job = srv_da_job_get_job_by_id(getJobID());	
	if(job == NULL)
	{
		VsrvNotification					*notify;
		notify = m_DLAgent_Group->queryNotification(getJobID());
		VSRV_NOTIFICATION_CLOSE(notify);
	}
	else
	{
		fillNCenterCellData(job);
	}
}

void VappDLAgentNcenterBaseCell::fillNCenterCellData(void *args)
{
	srv_da_item_progress_struct 	   	info;
    VfxS8                              	buffer_temp [300] = {'\0',};
    VfxU16                             	file_name_buffer [SRV_FMGR_PATH_MAX_LEN + 2] = {'\0',};
	VfxS8                              	*dl_str;
	VfxWString							file_name_string;
	VfxWString							file_size_string;
	srv_da_job_struct 					*job = (srv_da_job_struct *)args;
	VappDLAgentonGoingCell 				*cell = getOnGoingCell();

	ASSERT(job != NULL);
	setJobID(DA_JOB_GET_ID(job));	
	srv_da_job_get_name(job, file_name_buffer, SRV_FMGR_PATH_MAX_LEN + 1);
	file_name_string = (U16*)srv_da_util_get_filename ((U16*)file_name_buffer);
	cell->setMainText(file_name_string);
	DA_JOB_GET_PROGRESS(job, info);

	if (job->state == SRV_DA_JOB_STATE_COMPLETED)
	{
		if(!need_update)
			return;
		else
		{
			dl_str = (VfxS8*)srv_da_util_format_size (info.fileSize);
			cell->setStatusButtonIcon(VcpStateImage(VAPP_IMG_ID_DLA_NCENTER_COMPLETE));
			if(cell->getPopupID()> -1)
			{
				vcp_global_popup_cancel(cell->getPopupID());
			}
			need_update = VFX_FALSE;
		}
	}
	else
	{
		dl_str = (VfxS8*)srv_da_util_format_size_total(info.currSize, info.fileSize);
		if(job->state == SRV_DA_JOB_STATE_FAILED)
		{
			cell->setStatusButtonIcon(VcpStateImage(VAPP_IMG_ID_DLA_NCENTER_RESTART));
		}
		else if(job->state == SRV_DA_JOB_STATE_PAUSED)
		{
			cell->setStatusButtonIcon(VcpStateImage(VAPP_IMG_ID_DLA_NCENTER_RESUME));
		}
		else
		{
			cell->setStatusButtonIcon(VcpStateImage(VAPP_IMG_ID_DLA_NCENTER_PAUSE));
		}
		//check the job state and disable the button under these cases
		if (job->state == SRV_DA_JOB_STATE_PROCESSING || job->setting_info.can_minimize == MMI_FALSE)
		{
			cell->setStatusButtonEnabled(VFX_FALSE);
		}
		else
		{
			cell->setStatusButtonEnabled(VFX_TRUE);
		}

	}
	mmi_asc_to_ucs2((S8*) buffer_temp, (S8*)dl_str);
	file_size_string.loadFromMem((VfxU16 *)buffer_temp);
	if(job->state == SRV_DA_JOB_STATE_FAILED)
	{
		file_size_string = VFX_WSTR_RES(STR_GLOBAL_FAILED);
	}
	else if(job->state == SRV_DA_JOB_STATE_WAITING)
	{
		file_size_string = VFX_WSTR_RES(VAPP_STR_DLA_WAITING);
	}
	cell->setSubText(file_size_string);
}
