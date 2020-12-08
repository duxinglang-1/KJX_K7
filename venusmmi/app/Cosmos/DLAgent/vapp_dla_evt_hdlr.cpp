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
 *  vapp_helloworld.cpp
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
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vapp_dla_main.h"
#include "vcp_global_popup.h"
#include "vapp_nmgr_gprot.h"
#include "NotificationGprot.h"
#include "SimCtrlSrvGprot.h"
#include "vapp_usb_gprot.h"
#include "Das_struct.h"
#include "ModeSwitchSrvGprot.h"
#ifdef __cplusplus
extern "C"
{
#endif /* __CPLUSPLUS__ */

#include "cbm_api.h"
#include "CbmSrvGprot.h"
#include "cbm_consts.h"

#ifdef __cplusplus
}
#endif /* __CPLUSPLUS__ */


typedef struct
{    
    MMI_BOOL            job_list_dirty_flag;
} mmi_da_context_struct;
static mmi_da_context_struct   g_mmi_da_context;

extern vapp_da_app_launch_struct	*launcherRecord;
extern "C" void vapp_da_app_launch(void *arg);
extern "C" MMI_BOOL vapp_da_notify_app_launch(mmi_scenario_id scen_id, void *arg);

mmi_ret vapp_da_close_app_if_app_exist(void)
{
    if (m_DLAgentAppID)
    {
        VfxAppLauncher::terminate(m_DLAgentAppID);
		//since onDeinit can not be called if OOM cancel, here App ID is assign "0"
		m_DLAgentAppID = 0;
    }
    return MMI_RET_OK;
}


mmi_ret vapp_da_callback_interface(vapp_da_app_launch_struct app_launch, U16 paramSize, 
	VfxBool need_Launch)
{
    if (m_DLAgentAppID)
    {
        VAppDLAgentInterface::OnServiceCallback ((void*)&app_launch);
    }
	else
	{
	    if (need_Launch == VFX_TRUE)
	    {
			app_launch.argSize = paramSize;
			vapp_da_app_launch ((void*)&app_launch);
		}
    }
    return MMI_RET_OK;
}

extern "C"  mmi_ret vapp_da_evt_enter_usb_mode(mmi_event_struct* para)
{
	return vapp_da_close_app_if_app_exist();
}

extern "C"  mmi_ret vapp_da_evt_flight_mode(mmi_event_struct* para)
{
    srv_mode_switch_notify_struct *evt = (srv_mode_switch_notify_struct *)para;
	if(evt->curr_flight_mode == SRV_MODE_SWITCH_OFF &&
       evt->select_flight_mode == SRV_MODE_SWITCH_ON)
	{
		return vapp_da_close_app_if_app_exist();
	}
	return MMI_RET_OK;
}

extern "C" mmi_ret vapp_da_evt_usb_available(mmi_event_struct* para)
{
#ifdef __MMI_USB_SUPPORT__      
    vapp_usb_unavailable_popup(0);
#endif
	return MMI_RET_OK;
}

extern "C"  mmi_ret vapp_da_evt_close_app(mmi_event_struct* para)
{
	return vapp_da_close_app_if_app_exist();
}

extern "C"  mmi_ret vapp_da_evt_show_progress(mmi_event_struct *evnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	vapp_da_app_launch_struct  app_launch = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        app_launch.type = SRV_DA_APP_LAUNCH_PROGRESSING;
        app_launch.arg = evnt;
	return vapp_da_callback_interface(app_launch, 
		                              sizeof(srv_da_show_progressing_event_struct), 
		                              VFX_TRUE);
    }




void vapp_da_dummy_api (VfxId id, void *userData) 
{
}

extern "C" mmi_ret vapp_da_return_mmi_ok(mmi_event_struct *event)
{
	return MMI_OK;
}



/*****************************************************************************
 * FUNCTION
 *  vapp_da_popup_message_right_now
 * DESCRIPTION
 *  Popup message for job RIGHT NOW regardless current condition.
 *  NOTE: The message content will be cleaned after popup.
 * PARAMETERS
 *  message     [IN/OUT] Message
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_da_popup_message_right_now(srv_da_popup_message_struct* message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VcpPopupTypeEnum popup_type = VCP_POPUP_TYPE_INFO;
    VfxWString  popup_str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_da_is_popup_allowed())
    {
        switch (message->type)
        {
            case SRV_DA_POPUP_TYPE_NONE:
                return;

            case SRV_DA_POPUP_TYPE_MESSAGE:
                popup_type = VCP_POPUP_TYPE_INFO;
                break;

            case SRV_DA_POPUP_TYPE_LONG_MESSAGE:
                popup_type = VCP_POPUP_TYPE_INFO;
                break;
        
            case SRV_DA_POPUP_TYPE_ERROR:
				popup_type = VCP_POPUP_TYPE_FAILURE;
                break;
            case SRV_DA_POPUP_TYPE_DONE:
            case SRV_DA_POPUP_TYPE_SAVED:
				popup_type = VCP_POPUP_TYPE_SUCCESS;
                break;
            case SRV_DA_POPUP_TYPE_INFO:
			    popup_type = VCP_POPUP_TYPE_INFO;
                break;
        #ifdef __DRM_SUPPORT__
            case SRV_DA_POPUP_TYPE_DRM_PROCESSING_INFO:
                {
                    srv_da_drm_popup_info *drm_popup_info;
                    drm_popup_info = (srv_da_drm_popup_info*)message->info;
                    if (drm_popup_info != NULL)
                    {
                        srv_da_drm_show_process_info(
                            drm_popup_info->result,
                            drm_popup_info->mime_type,
                            &(drm_popup_info->result_info),
                            drm_popup_info->action);

                        OslMfree(drm_popup_info); /* message->info will be cleaned afterward */
                    }
                }
                break;
        #endif

            default:
                break;
        }
    }


    popup_str.loadFromMem ((VfxWChar*)message->string); 

    /*
    vcp_global_popup_show_confirm_one_button_str(
        GRP_ID_ROOT,
        popup_type,
        popup_str,
        VFX_WSTR_RES(STR_GLOBAL_OK),
        VCP_POPUP_BUTTON_TYPE_NORMAL,        
        vapp_da_dummy_api,
        NULL);
    */

    
    vapp_nmgr_global_popup_show_confirm_one_button_str(
        MMI_SCENARIO_ID_DEFAULT,
        popup_type, 
        popup_str,
        VFX_WSTR_RES(STR_GLOBAL_OK),
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        vapp_da_dummy_api,
        NULL);



    if (message->free_string_after_popup)
    {
        OslMfree(message->string);
    }
}


MMI_BOOL vapp_da_app_popup_for_job_msg_ext(srv_da_job_struct *job, srv_da_popup_message_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
      
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Don't popup during reporting */
    if (job->reporting)
    {
        if (msg->free_string_after_popup &&
            msg->string != NULL)
        {
            srv_srv_da_adp_mem_free(msg->string);
            msg->string = NULL;
        }
        if (msg->info != NULL)
        {
            srv_srv_da_adp_mem_free(msg->info);
            msg->info = NULL;
        }
        msg->type = SRV_DA_POPUP_TYPE_NONE;
        return MMI_TRUE;
    }

    if (msg != &(job->pending_popup))
    {
        srv_da_discard_pending_popup(job);
    }
    
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__

    if (srv_da_is_popup_allowed())
    {
        if (msg->type == SRV_DA_POPUP_TYPE_LONG_MESSAGE)
        {
             srv_da_set_curr_job(job);
        }
    
        goto POPUP;
    }
    else if (msg != &(job->pending_popup))
    {
        memcpy(&(job->pending_popup), msg, sizeof(srv_da_popup_message_struct));
        msg->type = SRV_DA_POPUP_TYPE_NONE;
    }
    
#else /* __MMI_DOWNLOAD_AGENT_MULTI_DL__ */

    if (srv_da_is_popup_allowed())
    {
        if (msg->type == SRV_DA_POPUP_TYPE_LONG_MESSAGE)
        {
             srv_da_set_curr_job(job);
        }
    
        goto POPUP;
    }

#endif /* __MMI_DOWNLOAD_AGENT_MULTI_DL__ */

POPUP:
	vapp_da_popup_message_right_now(msg);

	return MMI_TRUE;

}

MMI_BOOL vapp_da_app_popup_for_job_ext(
    srv_da_job_struct *job,	
    U16 title_string_id,
    U16 title_icon_id,
    srv_da_popup_type_enum type,
    U16 *message_str,
    MMI_BOOL free_string_after_popup,
    void *info)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_popup_message_struct message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_EXT_ASSERT(type != SRV_DA_POPUP_TYPE_NONE, type, 0, free_string_after_popup);

    /* Don't popup during reporting */
    if (job->reporting)
    {
        if (free_string_after_popup)
        {
            srv_srv_da_adp_mem_free(message_str);
        }
        if (info != NULL)
        {
            srv_srv_da_adp_mem_free(info);
        }
        return MMI_TRUE;
    }
    
    message.type = type;
    message.title_string_id = title_string_id;
    message.title_icon_id = title_icon_id;
    message.string = message_str;
    message.free_string_after_popup = free_string_after_popup;
    message.info = info;

    return vapp_da_app_popup_for_job_msg_ext(job, &message);
}


//show popup for DRM. eg: rights has not received
void vapp_da_app_popup_for_job_msg(
    srv_da_job_struct *job,
	U16 *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 *popup_string;
    const U16 *popup_suffix;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/            
    popup_suffix = (const U16*)get_string(VAPP_STR_DLA_RIGHTS_DELAYED_SUFFIX);
    popup_string = (U16 *)srv_da_adp_mem_allocate((mmi_wcslen(filepath) + mmi_wcslen(popup_suffix) + 10) * sizeof(U16));
    kal_wsprintf(popup_string, "%w%w", filepath, popup_suffix);
    vapp_da_app_popup_for_job_ext(job, VAPP_STR_DLA_NO_RIGHTS, srv_da_job_get_title_icon(job), SRV_DA_POPUP_TYPE_LONG_MESSAGE, popup_string,  MMI_TRUE, NULL);
}

extern "C"  mmi_ret vapp_da_evt_popup_for_job_msg(mmi_event_struct *evnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_popup_for_job_msg_event_struct *evt = (srv_da_popup_for_job_msg_event_struct*)evnt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //vapp_da_popup_message_right_now (evt->msg);
	vapp_da_app_popup_for_job_msg(evt->job, evt->filepath);
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
U16  vapp_da_app_get_wap_error_string_id(S32 dls_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (dls_error < 0)
    {
        return (U16)srv_fmgr_fs_error_get_string(dls_error);
    }
        
    switch (dls_error)
    {
        case WAP_DL_ERROR_CONNECTION_CLOSED:
            string_id = VAPP_STR_DLA_ERROR_CONNECT_CLOSED;
            break;
            
        case WAP_DL_ERROR_INVALID_FILE:
            string_id = STR_GLOBAL_INVALID_FILENAME;
            break;
            
        case WAP_DL_ERROR_DISK_FULL:
            string_id = (U16)srv_fmgr_fs_error_get_string(FS_DISK_FULL);
            break;
            
        case WAP_DL_ERROR_FILE_ACCESS:
            string_id = (U16)srv_fmgr_fs_error_get_string(FS_ACCESS_DENIED);
            break;
            
        case WAP_DL_ERROR_FILE_READ_ONLY:
            string_id = (U16)srv_fmgr_fs_error_get_string(FS_READ_ONLY_ERROR);
            break;

        case WAP_DL_ERROR_CANCELLED:
        case WAP_DL_ERROR_INVALID_SESSION_ID:
        case WAP_DL_ERROR_OK:
        default:
            string_id = STR_GLOBAL_ERROR;
            break;
    }

    return string_id;
}

UI_string_ID_type vapp_da_app_map_string(U32 string_id, S32 cause, srv_da_popup_type_enum type)
{
	UI_string_ID_type str_id = 1;
	if (type == SRV_DA_POPUP_TYPE_FS_ERROR)
	{
		str_id = srv_fmgr_fs_error_get_string(cause);
		return str_id;
	}
	else if (type == SRV_DA_POPUP_TYPE_WAP_ERROR)
	{
		str_id = vapp_da_app_get_wap_error_string_id(cause);
		return str_id;
	}
	else
	{
		switch (string_id)
		{
			case SRV_DA_GLOBAL_NOT_SUPPORTED:
				str_id = STR_GLOBAL_NOT_SUPPORTED;
				break;
			case SRV_DA_GLOBAL_UNSUPPORTED_FORMAT:
				str_id = STR_GLOBAL_UNSUPPORTED_FORMAT;
				break;
			case SRV_DA_RIGHTS_DID_NOT_ARRIVE_ON_TIME:
				str_id = VAPP_STR_DLA_RIGHTS_DID_NOT_ARRIVE_ON_TIME;
				break;
			case SRV_DA_JAVA_JOB_EXIST:
				str_id = VAPP_STR_DLA_JAVA_JOB_EXIST;
				break;
			case SRV_DA_GLOBAL_NOT_ENOUGH_MEMORY:
				str_id = STR_GLOBAL_NOT_ENOUGH_MEMORY;
				break;
			case SRV_DA_GLOBAL_INSERT_MEMORY_CARD:
				str_id = STR_GLOBAL_INSERT_MEMORY_CARD;
				break;
			case SRV_DA_GLOBAL_DRM_INVALID_FORMAT:
				str_id = STR_GLOBAL_DRM_INVALID_FORMAT;
				break;
			case SRV_DA_JOB_EXIST:
				str_id = VAPP_STR_DLA_JOB_EXIST;
				break;
			case SRV_DA_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL:
				str_id = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL;
				break;
			case SRV_DA_PROMPT_EXCEED_MAX_DL:
				str_id = VAPP_STR_DLA_PROMPT_EXCEED_MAX_DL;
				break;
			case SRV_DA_AHTUENTICATION_FAILED:
				str_id = VAPP_STR_DLA_AHTUENTICATION_FAILED;
				break;
			case SRV_DA_OMA_ERROR_SEND_REPORT_FAIL:
				str_id = VAPP_STR_DLA_OMA_ERROR_SEND_REPORT_FAIL;
				break;
			case SRV_DA_GLOBAL_SAVED:
				str_id = STR_GLOBAL_SAVED;
				break;
			case SRV_DA_SAVED_TO_CARD:
				str_id = VAPP_STR_DLA_SAVED_TO_CARD;
				break;
			case SRV_DA_GLOBAL_SAVED_TO_PHONE:
				str_id = VAPP_STR_DLA_SAVED_TO_PHONE;
				break;
			case SRV_DA_UNABLE_TO_SAVE_FILE:
				str_id = VAPP_STR_DLA_UNABLE_TO_SAVE_FILE;
				break;
			case SRV_DA_GLOBAL_INSUFFICIENT_MEMORY:
				str_id = STR_GLOBAL_INSUFFICIENT_MEMORY;
				break;
#ifdef __MMI_DA_RESUME__
			case SRV_DA_ERROR_RESUME_FAIL:
				str_id = VAPP_STR_DLA_ERROR_RESUME_FAIL;
				break;
#endif
			case SRV_DA_ERROR_CONNECT_CLOSED:
				str_id = VAPP_STR_DLA_ERROR_CONNECT_CLOSED;
				break;
			case SRV_DA_OMA_ERROR_SEND_REPORT_CANCEL:
				str_id = VAPP_STR_DLA_OMA_ERROR_SEND_REPORT_CANCEL;
				break;
			case SRV_DA_PROMPT_DL_COMPLETE:
				str_id = VAPP_STR_DLA_PROMPT_DL_COMPLETE;
				break;
			case SRV_DA_GLOBAL_CANCELLING:
				str_id = STR_GLOBAL_CANCELLING;
				break;
			case SRV_DA_PLEASE_WAIT:
				str_id = STR_GLOBAL_PLEASE_WAIT;
				break;
			case SRV_DA_PROCESSING:
				str_id = VAPP_STR_DLA_PROCESSING;
				break;
			case SRV_DA_DRM_PROCESSING:
				str_id = STR_GLOBAL_DRM_PROCESSING;
				break;
			case SRV_DA_GLOBAL_SAVING:
				str_id = STR_GLOBAL_SAVING;
				break;
			case SRV_DA_GLOBAL_DONE:
				str_id = STR_GLOBAL_DONE;
				break;
			case SRV_DA_GLOBAL_MOVING:
				str_id= STR_GLOBAL_MOVING;
				break;
			case SRV_DA_NEW_PUSH:
				str_id = VAPP_STR_DLA_NEW_PUSH;
				break;
			case SRV_DA_INSERT_MEMORY_CARD:
				str_id = VAPP_STR_DLA_INSERT_MEMORY_CARD;
				break;
            default:
                str_id = string_id;
                break;
		}
	}
	
	return str_id;
}


extern "C"  mmi_ret vapp_da_evt_popup(mmi_event_struct *evnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_ID_type str_id;
    srv_da_popup_event_struct *evt = (srv_da_popup_event_struct*)evnt;
    //vapp_da_app_launch_struct  app_launch;
    mmi_nmgr_balloon_type_enum balloonType = MMI_NMGR_BALLOON_TYPE_FAILURE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	str_id = vapp_da_app_map_string(evt->string_id, evt->cause, evt->type);
    switch (evt->type)
    {
    case SRV_DA_POPUP_TYPE_LONG_MESSAGE:
    case SRV_DA_POPUP_TYPE_INFO:
    case SRV_DA_POPUP_TYPE_MESSAGE:
        balloonType = MMI_NMGR_BALLOON_TYPE_INFO;
        break;
    case SRV_DA_POPUP_TYPE_ERROR:
        balloonType = MMI_NMGR_BALLOON_TYPE_FAILURE;
        break;
    case SRV_DA_POPUP_TYPE_SAVED:
    case SRV_DA_POPUP_TYPE_DONE:
        balloonType = MMI_NMGR_BALLOON_TYPE_SUCCESS;
        break;
    case SRV_DA_POPUP_TYPE_DRM_PROCESSING_INFO:
        balloonType = MMI_NMGR_BALLOON_TYPE_PROGRESS;
        break;
    }

    mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_GENERAL,
        MMI_EVENT_INFO_BALLOON,
        balloonType,
        (WCHAR*)(VFX_WSTR_RES(str_id).getBuf()));

    return MMI_RET_OK;
    //app_launch.type = SRV_DA_APP_LAUNCH_POPUP;
    //app_launch.arg = evt;
    //VAppDLAgentInterface::OnServiceCallback ((void*)&app_launch);
    //return MMI_RET_OK;
}


void vapp_da_app_popup_for_job(
    srv_da_job_struct *job,
    srv_da_popup_type_enum type,
    U16 *message_str,
    MMI_BOOL free_string_after_popup,
	void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vapp_da_app_popup_for_job_ext(job, 0, 0, type, message_str, free_string_after_popup, info);
}

void vapp_da_app_popup_error_for_job(srv_da_job_struct *job, srv_da_popup_type_enum type, S32 cause, U16 error_str_id, MMI_BOOL terminate_job)
{
	UI_string_ID_type str_id;
    str_id = vapp_da_app_map_string(error_str_id, cause, type);
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__

    vapp_da_app_popup_for_job(job, SRV_DA_POPUP_TYPE_ERROR, (U16*)get_string(str_id), MMI_FALSE, NULL);
    if (job->reporting)
    {
        if (terminate_job)
        {
            job->state = SRV_DA_JOB_STATE_ABORTED;
        }
    }
    else
    {
        if (terminate_job)
        {
			if (job->setting_info.can_minimize)
            job->state = SRV_DA_JOB_STATE_FAILED;
		else
			job->state = SRV_DA_JOB_STATE_ABORTED;

		}

    }
    
#else /* __MMI_DOWNLOAD_AGENT_MULTI_DL__ */

    vapp_da_app_popup_for_job(job, SRV_DA_POPUP_TYPE_ERROR, (U16*)get_string(str_id), MMI_FALSE, NULL);
    
    if (terminate_job)
    {
        job->state = SRV_DA_JOB_STATE_ABORTED;
    }
#endif /* __MMI_DOWNLOAD_AGENT_MULTI_DL__ */

}

extern "C"  mmi_ret vapp_da_evt_popup_error_for_job(mmi_event_struct *evnt)
{
	srv_da_popup_error_for_job_struct *evt = (srv_da_popup_error_for_job_struct *)evnt;
	vapp_da_app_popup_error_for_job(evt->job, evt->type, evt->cause, evt->error_str_id, evt->terminate_job);
	return MMI_RET_OK;


}

extern "C"  mmi_ret vapp_da_evt_popup_for_job(mmi_event_struct *evnt)
{
	srv_da_popup_message_for_job_struct *evt = (srv_da_popup_message_for_job_struct *)evnt;
	UI_string_ID_type str_id;
    str_id = vapp_da_app_map_string(evt->error_str_id, 0, evt->type);
	vapp_da_app_popup_for_job (evt->job, evt->type,  (U16*)get_string(str_id), evt->free_string_after_popup, evt->info);

	return MMI_RET_OK;

}

extern "C"  mmi_ret vapp_da_evt_display_job_detail(mmi_event_struct *evnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_display_job_detail_event_struct *evt = (srv_da_display_job_detail_event_struct*)evnt;
    vapp_da_app_launch_struct  app_launch = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    app_launch.type = SRV_DA_APP_LAUNCH_DISPLAY_JOB_DETAIL;
    app_launch.arg = evt;
	return vapp_da_callback_interface(app_launch, 
                                      sizeof (srv_da_display_job_detail_event_struct), 
		                              VFX_TRUE);
}


extern "C"  mmi_ret vapp_da_evt_display_job_list(mmi_event_struct *evnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_display_job_list_event_struct *evt = (srv_da_display_job_list_event_struct*)evnt;
    vapp_da_app_launch_struct  app_launch = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->list_type == SRV_DA_LIST_TYPE_COMPLETED)
    {
        app_launch.type = SRV_DA_APP_LAUNCH_COMPLETED_LIST;
    }
    else
    {
        app_launch.type = SRV_DA_APP_LAUNCH_DOWNLOADING_LIST;
    }
    
    app_launch.arg = evt;    
	vapp_da_close_app_if_app_exist();
	return vapp_da_callback_interface(app_launch, 
                                      sizeof (srv_da_display_job_list_event_struct), 
		                              VFX_TRUE);

}

extern "C"  mmi_ret vapp_da_evt_close_processing(mmi_event_struct *evnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_progressing_close_event_struct *evt = (srv_da_progressing_close_event_struct*)evnt;
    vapp_da_app_launch_struct  app_launch = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        app_launch.type = SRV_DA_APP_CLOSE_PROGRESSING;
        app_launch.arg = evt;
		if (m_DLAgentAppID)
		{
			VAppDLAgentInterface::OnServiceCallback ((void*)&app_launch);
		}
		else
		{
			mmi_frm_nmgr_cancel_deferred_scenario(MMI_SCENARIO_ID_DEFAULT, vapp_da_notify_app_launch, (void *)launcherRecord);
		}
		return MMI_RET_OK;
}

extern "C"  mmi_ret vapp_da_evt_wps_http_rsp_callback(mmi_event_struct *evnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_wps_http_response_event_struct *evt = (srv_da_wps_http_response_event_struct*)evnt;
    vapp_da_app_launch_struct  app_launch = {0};
    VfxBool                    is_resume = VFX_FALSE;

    srv_da_job_struct           *job;
    srv_da_normal_dl_job_struct *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (srv_da_job_struct*)evt->job;
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

    //is_resume = (job_data->curr_size == 0);

	if(job->type == SRV_DA_JOB_TYPE_NORMAL || job->type == SRV_DA_JOB_TYPE_HTTP_DOWNLOAD)
	{
		is_resume = (job_data->curr_size > 0);
	}
	#ifdef __MMI_OMA_DD_DOWNLOAD__
	else if(job->type == SRV_DA_JOB_TYPE_OMADL)
	{
		is_resume = ((srv_da_omadl_job_struct*)job_data->curr_size > 0);
	}
	#endif
#ifdef __MMI_DA_RESUME__
    if (is_resume && evt->status == 200)
    {
        srv_da_popup_event_struct popupData;
        popupData.string_id = VAPP_STR_DLA_PROMPT_RESUME_NOT_SUPPORTED_BY_SERVER;
        popupData.type = SRV_DA_POPUP_TYPE_INFO;
        vapp_da_evt_popup ((mmi_event_struct*)&popupData);
    }
#endif
        app_launch.type = SRV_DA_APP_CLOSE_PROGRESSING;
        app_launch.arg = evt;
	return vapp_da_callback_interface(app_launch, 
                                      sizeof (srv_da_wps_http_response_event_struct), 
		                              VFX_FALSE);
}

extern "C"  mmi_ret vapp_da_evt_show_user_auth_screen(mmi_event_struct *evnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_show_user_auth_event_struct *evt = (srv_da_show_user_auth_event_struct*)evnt;
    vapp_da_app_launch_struct  app_launch = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    app_launch.type = SRV_DA_APP_LAUNCH_AUTH_SCREEN;
    app_launch.arg = evt;   
	return vapp_da_callback_interface(app_launch, 
                                      sizeof (srv_da_show_user_auth_event_struct), 
		                              VFX_TRUE);
}


/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
extern "C" mmi_ret vapp_da_evt_update_ncenter (mmi_event_struct *evnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_update_ncenter_event_struct *evt = (srv_da_update_ncenter_event_struct*)evnt;
    vapp_da_app_launch_struct  app_launch = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    app_launch.type = SRV_DA_APP_UPDATE_NCENTER;
    app_launch.arg = evt;
    if (m_DLAgentAppID)
    {
        VAppDLAgentInterface::OnServiceCallback ((void*)&app_launch);
    }
    else
    {
        app_launch.argSize = sizeof (srv_da_update_ncenter_event_struct);
        //VcpDLAgentNCenter::updateAllCells();
		VappDLAgentNCenterNew::vapp_dla_update_ncenter(NULL, 0);
    }

    if ((evt->type == SRV_DA_JOB_TYPE_PUSH) && (evt->show == MMI_TRUE))
    {
        //VcpDLAgentNCenter::showPushStatus(evt->arg);
        VappDLAgentNCenterNew::vapp_dla_show_push_notify(evt->arg);
        VappDLAgentNCenterNew::vapp_dla_update_ncenter_push_object();
    }
    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  vapp_da_update_timer_handler
 * DESCRIPTION
 *  Refresh the screens for job(s).
 * PARAMETERS
 *  param       [IN] srv_da_job_struct*
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_da_update_timer_handler(void* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vapp_da_app_launch_struct  app_launch = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_da_context.job_list_dirty_flag = MMI_FALSE;
	VappDLAgentNCenterNew::vapp_dla_update_ncenter(NULL, 0);
    if (m_DLAgentAppID == 0)
    {
        /* APP is not active we can ignore */
        return ;
    }

    app_launch.type = SRV_DA_APP_UPDATE_DOWNLOAD;
    app_launch.arg = param;
	vapp_da_callback_interface(app_launch, 
                               sizeof (srv_da_update_job_event_struct), 
		                       VFX_FALSE);

}

void vapp_da_update_timer_handler_temp (void)
{
    vapp_da_update_timer_handler (NULL);
}


extern "C"  mmi_ret vapp_da_evt_update_job_status(mmi_event_struct *evnt)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_update_job_event_struct    *evt = (srv_da_update_job_event_struct*)evnt;
    srv_da_item_progress_struct       info;
    srv_da_job_struct                 *job;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (srv_da_job_struct*)evt->job;

    MMI_ASSERT(job);
#ifdef __MMI_OMA_DD_DOWNLOAD__
	if (job->type == SRV_DA_JOB_TYPE_OMADL)
	   vapp_da_oma_get_item_progress(job, &info);
	else
#endif
	{
		info.processing_string_id = 0;
		
	}
	DA_JOB_GET_PROGRESS(job, info);
    DA_TRACE_FUNC3(mmi_da_update_job_status, DA_JOB_UNIQUE_ID(job), job->state, info.currSize);

	if (job->reporting)
    {
        srv_da_report_to_app(job, &info);
    }

	 srv_da_send_download_info_ind();

    switch(job->state)
    {
    case SRV_DA_JOB_STATE_PROCESSING:
        if (g_mmi_da_context.job_list_dirty_flag)
        {
            StopTimer(SRV_DA_TIMER_UPDATE_STATUS);
        }
        g_mmi_da_context.job_list_dirty_flag = MMI_TRUE;
        vapp_da_update_timer_handler((void*)job);
        break;
    case SRV_DA_JOB_STATE_FAILED:
        srv_da_job_make_filestamp((srv_da_job_struct*)job);
        if (g_mmi_da_context.job_list_dirty_flag)
        {
            StopTimer(SRV_DA_TIMER_UPDATE_STATUS);
        }
        g_mmi_da_context.job_list_dirty_flag = MMI_TRUE;
        //VcpDLAgentNCenter::showJobStatus(job);
        VappDLAgentNCenterNew::vapp_dla_show_job_notify(job);
        vapp_da_update_timer_handler((void*)job);
        //VcpDLAgentNCenter::updateFailedCells();
        break;
    case SRV_DA_JOB_STATE_COMPLETED:
        {
            
            srv_da_job_make_filestamp((srv_da_job_struct*)job);

            if (g_mmi_da_context.job_list_dirty_flag)
            {
                StopTimer(SRV_DA_TIMER_UPDATE_STATUS);
            }
            g_mmi_da_context.job_list_dirty_flag = MMI_TRUE;
            //VcpDLAgentNCenter::showJobStatus(job);
            VappDLAgentNCenterNew::vapp_dla_show_job_notify(job);
			job->reporting = MMI_FALSE;
            vapp_da_update_timer_handler((void*)job);
        }
        break;
        
    case SRV_DA_JOB_STATE_DOWNLOADING:
        //job_id = DA_JOB_UNIQUE_ID(job);
        if(!g_mmi_da_context.job_list_dirty_flag)
        {
            StopTimer(SRV_DA_TIMER_UPDATE_STATUS);
            g_mmi_da_context.job_list_dirty_flag = MMI_TRUE;
//            StartTimerEx(SRV_DA_TIMER_UPDATE_STATUS, 500, vapp_da_update_timer_handler, (void*)job_id);
            StartTimer(SRV_DA_TIMER_UPDATE_STATUS, 500, vapp_da_update_timer_handler_temp);
        }
        break;
    case SRV_DA_JOB_STATE_ABORTED:
        vapp_da_update_timer_handler(job);
        srv_da_free_job(job);
        vapp_da_update_timer_handler_temp();
        break;

    case SRV_DA_JOB_STATE_ABORTING:
        /* the only case will run into here is:
            1. the report handler aborted the job 
        */
        MMI_ASSERT(job->setting_info.report_hdlr);
        break;
    case SRV_DA_JOB_STATE_PAUSED:
	{
        srv_da_job_make_filestamp((srv_da_job_struct*)job);
        if (g_mmi_da_context.job_list_dirty_flag)
        {
            StopTimer(SRV_DA_TIMER_UPDATE_STATUS);
        }
        g_mmi_da_context.job_list_dirty_flag = MMI_TRUE;
        vapp_da_update_timer_handler((void*)job);
        break;
	}
    case SRV_DA_JOB_STATE_WAITING:
    case SRV_DA_JOB_STATE_PAUSED_WAITING:
        vapp_da_update_timer_handler_temp();
        break;

    default:
        MMI_ASSERT(0); // not handled
        break;
    }
    if (job->state == SRV_DA_JOB_STATE_COMPLETED)
    {
        U32 total_completed = 0;
		if (srv_da_dispatch_http_job(job))
		{
			job->op->dispatch(job);
			srv_da_free_job(job);
			srv_da_send_download_info_ind();
			//StartTimer(SRV_DA_TIMER_UPDATE_STATUS, 500, vapp_da_update_timer_handler_temp);
			vapp_da_update_timer_handler_temp ();
			return MMI_RET_OK;
		}
        if (!(job->setting_info.confirm_dispatch))
        {
            job->op->dispatch(job);
            srv_da_free_job(job);
        }
        total_completed = srv_da_count_job(srv_da_job_match_state_func, SRV_DA_JOB_STATE_COMPLETED);
        if (total_completed > SRV_DA_MAX_NUM_OF_COMPLETED_DOWNLOAD)
        {
            srv_da_delete_extra_completed();
        }
        srv_da_send_download_info_ind();
        //StartTimer(SRV_DA_TIMER_UPDATE_STATUS, 500, vapp_da_update_timer_handler_temp);
        vapp_da_update_timer_handler_temp();
    }
    //VcpDLAgentNCenter::updateCompletedCells();
    //VcpDLAgentNCenter::updateAllCells();
    return MMI_RET_OK;
}

extern "C"  mmi_ret vapp_da_evt_job_aborted_callback(mmi_event_struct *evnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_curr_job_aborted_event_struct *evt = (srv_da_curr_job_aborted_event_struct*)evnt;
    srv_da_progressing_close_event_struct closeProgress;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->job->reporting)
    {
        srv_da_item_progress_struct info;
#ifdef __MMI_OMA_DD_DOWNLOAD__
		if (evt->job->type == SRV_DA_JOB_TYPE_OMADL)
		    vapp_da_oma_get_item_progress(evt->job, &info);
		else
#endif
		{
			info.processing_string_id = 0;		
		}
        DA_JOB_GET_PROGRESS(evt->job, info);
        srv_da_report_to_app(evt->job, &info);
    }
    if (m_DLAgentAppID)
    {
        closeProgress.screen_id = 0;
        vapp_da_evt_close_processing ((mmi_event_struct*)&closeProgress);
        vapp_da_update_timer_handler ((srv_da_job_struct*)evt->job);
    }
	srv_da_free_job((srv_da_job_struct*)evt->job);
	srv_da_send_download_info_ind();
    vapp_da_update_timer_handler_temp();

    return MMI_RET_OK;
}


extern "C"  mmi_ret vapp_da_evt_new_download_confirm_screen(mmi_event_struct *evnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_show_choice_screen_event_struct *evt = (srv_da_show_choice_screen_event_struct*)evnt;
    vapp_da_app_launch_struct  app_launch = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    app_launch.type = SRV_DA_APP_LAUNCH_NEW_DOWNLOAD;
    app_launch.arg = evt;
	vapp_da_close_app_if_app_exist();
	return vapp_da_callback_interface(app_launch, 
                                      sizeof (srv_da_show_choice_screen_event_struct), 
		                              VFX_TRUE);

}


/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
extern "C" U8 mmi_da_launch_ring_buffer_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef __USB_IN_NORMAL_MODE__
   // if(mmi_usb_is_in_mass_storage_mode())
        return MMI_FALSE;
#else
    if (srv_da_push_get_number_of_elements(srv_da_get_item_to_be_confirm()) > 0)
    {
        return MMI_TRUE;
    }else
    {
		return MMI_FALSE;
    }
#endif
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_da_entry_new_push_ind
 * DESCRIPTION
 *  Called when entering Idle screen. To show pushes to be processed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" void mmi_da_entry_new_push_ind(void) 
{

}


/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
extern "C" mmi_ret mmi_da_scr_select_storage_on_dev_plug_out(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
extern "C" mmi_ret mmi_da_enter_idle_screen_notify(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*   mmi_da_init_app
* DESCRIPTION
*   initial download agent, set handler and state and initial table
* PARAMETERS
*   void
* RETURNS
*   void
*****************************************************************************/
extern "C" void mmi_da_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
	cbm_app_info_struct app_info;
#ifdef MMI_DA_WLAN_PREFER_SUPPORT
	U8 cbm_app_id1;
	U8 cbm_app_id2;
#else
	U8 cbm_app_id;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_da_adp_init();

#ifdef __HTTP_INTERFACE__
#ifdef MMI_DA_WLAN_PREFER_SUPPORT
    memset(&app_info, 0, sizeof(app_info));
    app_info.app_icon_id = GetRootTitleIcon(SERVICES_WAP_MENU_ID);
    app_info.app_str_id = STR_GLOBAL_DOWNLOAD;
    app_info.app_type = 0;
	cbm_app_id1 = srv_da_wps_get_cbm_id(SRV_DA_CBM_APP_ID1);
    cbm_register_app_id_with_app_info(&app_info, &cbm_app_id1);

     srv_da_wps_set_cbm_id(SRV_DA_CBM_APP_ID1, cbm_app_id1);

	srv_da_wps_register_bearer_fallback(cbm_app_id1);

    srv_cbm_register_bearer_info(
        cbm_app_id1,
        SRV_CBM_ACTIVATED | SRV_CBM_DEACTIVATED,
        SRV_CBM_BEARER_CSD | SRV_CBM_BEARER_PS | SRV_CBM_BEARER_WIFI,
        srv_da_wps_nwk_fsm_bearer_info_ind, NULL);

	
    srv_da_wps_register_bearer_fallback(cbm_app_id1);

    app_info.app_icon_id = IMG_GLOBAL_COMMON_CSK;
    app_info.app_type |= DTCNT_APPTYPE_SPECIFIC_PROFILE;
	cbm_app_id2 = srv_da_wps_get_cbm_id(SRV_DA_CBM_APP_ID2);
    cbm_register_app_id_with_app_info(&app_info, &cbm_app_id2);
	srv_da_wps_set_cbm_id(SRV_DA_CBM_APP_ID2, cbm_app_id2);   

		srv_da_wps_register_bearer_fallback(cbm_app_id2);

    srv_cbm_register_bearer_info(
        cbm_app_id2,
        SRV_CBM_ACTIVATED | SRV_CBM_DEACTIVATED,
        SRV_CBM_BEARER_CSD | SRV_CBM_BEARER_PS | SRV_CBM_BEARER_WIFI,
        srv_da_wps_nwk_fsm_bearer_info_ind, NULL);


    srv_da_wps_register_bearer_fallback(cbm_app_id2);


#else

	
    memset(&app_info, 0, sizeof(app_info));
    app_info.app_icon_id = GetRootTitleIcon(SERVICES_WAP_MENU_ID);
    app_info.app_str_id = STR_GLOBAL_DOWNLOAD;
    app_info.app_type = 0;
	cbm_app_id = srv_da_wps_get_cbm_id(SRV_DA_CBM_APP_ID_NONE);
    cbm_register_app_id_with_app_info(&app_info, &cbm_app_id);
	srv_da_wps_set_cbm_id(SRV_DA_CBM_APP_ID1, cbm_app_id);   
	srv_cbm_register_bearer_info(
        cbm_app_id,
        SRV_CBM_ACTIVATED | SRV_CBM_DEACTIVATED,
        SRV_CBM_BEARER_CSD | SRV_CBM_BEARER_PS | SRV_CBM_BEARER_WIFI,
        srv_da_wps_nwk_fsm_bearer_info_ind, NULL);

    
#ifdef __CBM_BEARER_FALLBACK__
    srv_da_wps_register_bearer_fallback(srv_da_wps_context.cbm_app_id);
#endif

#endif /* MMI_DA_WLAN_PREFER_SUPPORT */
#endif

}

void vapp_da_popup_error_code_callback(VfxId id, void *userData)
{
    if (id != VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        return;	
    }
    vapp_da_app_launch_struct  app_launch;
    srv_da_display_job_list_event_struct  evt;
    evt.job = NULL;
    app_launch.type = SRV_DA_APP_LAUNCH_DOWNLOADING_LIST;    
    app_launch.arg = (void*)&evt;    
    if (m_DLAgentAppID)
    {
        VAppDLAgentInterface::OnServiceCallback ((void*)&app_launch);
        return;
    }
    app_launch.argSize = sizeof (srv_da_display_job_list_event_struct);
    vapp_da_app_launch ((void*)&app_launch);
}

extern "C"  mmi_ret vapp_da_evt_popup_error_code_with_callback(mmi_event_struct *evnt)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_popup_for_error_code_event_struct *evt = (srv_da_popup_for_error_code_event_struct*)evnt;
    U16 string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->error_code)
    {
    case SRV_DA_IERROR_EXCEED_MAX_JOB:
    case SRV_DA_IERROR_EXCEED_MAX_DL:
        string_id = VAPP_STR_DLA_MAX_DOWNLOAD_EXCEEDS;
        break;
    case SRV_DA_IERROR_ANOTHER_JOB:
        string_id = VAPP_STR_DLA_EXIST_DOWNLOAD_IN_INIT;
        break;
    default:
        string_id = STR_GLOBAL_INSUFFICIENT_MEMORY;
        break;
    }

    /*
    vcp_global_popup_show_confirm_one_button_id(
        GRP_ID_ROOT,
        VCP_POPUP_TYPE_FAILURE,
        string_id,
        STR_GLOBAL_OK,
        VCP_POPUP_BUTTON_TYPE_NORMAL,        
        vapp_da_dummy_api,
        NULL);
    */
    
    vapp_nmgr_global_popup_show_confirm_one_button_id(
        MMI_SCENARIO_ID_DEFAULT,
        VCP_POPUP_TYPE_FAILURE, 
        string_id,
        STR_GLOBAL_OK,
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        vapp_da_popup_error_code_callback,
        NULL);


    return MMI_RET_OK;
}

#if defined (__SIM_HOT_SWAP_SUPPORT__)
extern "C" mmi_ret vapp_dla_evt_handle_sim_indication(mmi_event_struct *evnt)
{
    srv_sim_ctrl_unavailable_evt_struct *evt = (srv_sim_ctrl_unavailable_evt_struct*)evnt;
	srv_da_adp_on_sim_plug_out(evt->sim);
	return MMI_RET_OK;
}
#endif

void onPauseSuccess (srv_da_job_struct *job, U16 string_id)
{
    job->state = SRV_DA_JOB_STATE_PAUSED;

    srv_da_update_job_event_struct update;
    update.job = job;

    vapp_da_evt_update_job_status((mmi_event_struct*)&update);
    job->reporting = MMI_FALSE;
}
