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
 *  vapp_dla_scr.cpp
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "vapp_dla_main.h"
#include "vapp_usb_gprot.h"
#include "vapp_nmgr_gprot.h"
#include "FileMgrSrvIProt.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __CPLUSPLUS__ */

#include "USBSrvGprot.h"

#ifdef __cplusplus
}
#endif /* __CPLUSPLUS__ */

#define IS_SPACE(c) (c == WCHAR(0x20))



#ifndef __COSMOS_NO_USER_DRIVE__
	VfxU16 VappDLAgentNewDownloadPage::m_user_prefered_drive = VappDLAgentNewDownloadPage::DLA_DRIVE_PHONE;
#else
	VfxU16 VappDLAgentNewDownloadPage::m_user_prefered_drive = VappDLAgentNewDownloadPage::DLA_DRIVE_MEMORY_CARD;
#endif

VappDLAgentDownloadListControl* VappDLAgentMainPageContentProvider::getCustomShellAtIndex (VfxS32 index)
{
    return list[index].get();
}


void VappDLAgentMainPageContentProvider::UpdateDisplayedList (void)
{
    srv_da_job_struct *job = NULL;
    for (int i = 0; i < 10; i++)
    {
        if (list[i].get() != NULL)
        {
            if (m_list_type == VappDLAgentDownloadListPage::DLA_LIST_TYPE_DOWNLOADING_LIST)
            {
                job = srv_da_get_nth_job_in_downloading_list (i);
            }
            else
            {
                job = srv_da_get_nth_job_in_completed_list (i);
            }
            if (job)
            {
                list[i]->setArgID ((VfxS32)DA_JOB_GET_ID (job));
                fillCustomFieldData (list[i].get(), job, !(list[i]->unfolded));
            }
        }
    }
}


void VappDLAgentMainPageContentProvider::updateItemContent (void *arg)
{
    VfxS32 index = 0;
    VfxU32 job_count = 0;
    srv_da_job_struct *job = NULL;

    for (int i = 0; i < 10; i++)
    {
        if (list[i].get() != NULL)
        {
            job = srv_da_job_get_job_by_id (list[i]->getArgID());
            if (job)
            {
                VappDLAgentMainPageContentProvider::fillCustomFieldData (list[i].get(), (void*)job, !(list[i]->unfolded));
                job_count++;
            }
            else
            {
                if (list[i]->getArgID() < 0)
                {
                    /* Setting null to list pointers when object is already removed from list */
                    list[i] = NULL;
                }
            }
            index++;
        }
    }

    if (job_count < index)
    {
        UpdateDisplayedList();
    }
    return;
}

void VappDLAgentMainPageContentProvider::fillStatusFieldToShell(srv_da_job_state_enum job_state, 
	VfxS8 *file_curr_size, VappDLAgentDownloadListControl *shell)
{
	switch(job_state)
	{
	case SRV_DA_JOB_STATE_DOWNLOADING:
	case SRV_DA_JOB_STATE_COMPLETED:
		shell->set_text ((VfxWChar*)file_curr_size, shell->LIST_CONTROL_TEXT_STATUS);
		break;
	case SRV_DA_JOB_STATE_INIT:
		shell->set_text ((VfxWChar*)(VFX_WSTR_RES(VAPP_STR_DLA_INITIALIZING).getBuf()), shell->LIST_CONTROL_TEXT_STATUS);
		break;
	case SRV_DA_JOB_STATE_PAUSED:
	case SRV_DA_JOB_STATE_RESUMING:
		shell->set_text ((VfxWChar*)(VFX_WSTR_RES(VAPP_STR_DLA_PAUSED).getBuf()), shell->LIST_CONTROL_TEXT_STATUS);
		break;
	case SRV_DA_JOB_STATE_FAILED:
	case SRV_DA_JOB_STATE_ABORTED:
		shell->set_text ((VfxWChar*)(VFX_WSTR_RES(STR_GLOBAL_FAILED).getBuf()), shell->LIST_CONTROL_TEXT_STATUS);
		break;
	case SRV_DA_JOB_STATE_WAITING:
		shell->set_text ((VfxWChar*)(VFX_WSTR_RES(VAPP_STR_DLA_WAITING).getBuf()), shell->LIST_CONTROL_TEXT_STATUS);
		break;
	case SRV_DA_JOB_STATE_ABORTING:
		shell->set_text ((VfxWChar*)(VFX_WSTR_RES(STR_GLOBAL_FAILED).getBuf()), shell->LIST_CONTROL_TEXT_STATUS);
		break;
	}
}


void VappDLAgentMainPageContentProvider::fillCustomFieldData (VappDLAgentDownloadListControl *shell, void *arg, VfxBool isFolded)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct *job = (srv_da_job_struct*)arg;
    srv_da_item_progress_struct        info;
    VfxFloat                           percentage;
    VfxS8                              *dl_str;
    VfxS8                              buffer_temp [300] = {'\0',};
    VfxU16                             file_name_buffer [SRV_FMGR_PATH_MAX_LEN + 2] = {'\0',};
	VfxU16                             time_buffer [100] = {'\0',};
    VfxWString                         time_str;
    VfxWString                         string;
    VfxU16                             *temp_str = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//get file name
    srv_da_job_get_name(job, file_name_buffer, SRV_FMGR_PATH_MAX_LEN + 1);
    temp_str = (U16*)srv_da_util_get_filename ((U16*)file_name_buffer);
    if (mmi_ucs2strlen ((S8*)temp_str) > MMI_DA_MAX_FILENAME_INPUT_LEN)
    {
        mmi_ucs2ncpy ((S8*)buffer_temp, (S8*)temp_str, (MMI_DA_MAX_FILENAME_INPUT_LEN - 3));
        mmi_ucs2cat ((S8*)buffer_temp, (S8*)L"...");
    }
    else
    {
        mmi_ucs2ncpy ((S8*)buffer_temp, (S8*)temp_str, MMI_DA_MAX_FILENAME_INPUT_LEN);
    }
    memset (file_name_buffer, 0, (SRV_FMGR_PATH_MAX_LEN + 2));
    mmi_ucs2ncpy ((S8*)file_name_buffer, (S8*)buffer_temp, MMI_DA_MAX_FILENAME_INPUT_LEN);
    memset (buffer_temp, 0, (300));
	shell->set_text (file_name_buffer, shell->LIST_CONTROL_TEXT_FILENAME);

    percentage = (VfxFloat) DA_JOB_GET_PROGRESS(job, info);

    if (job->state == SRV_DA_JOB_STATE_COMPLETED)
    {
        dl_str = (VfxS8*)srv_da_util_format_size (info.currSize);
    }
    else
    {
        dl_str = (VfxS8*)srv_da_util_format_size_total(info.currSize, info.fileSize);
    }
    mmi_asc_to_ucs2((S8*) buffer_temp, (S8*)dl_str);
    
    if(percentage == MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN)
    {
        mmi_ucs2cat((S8*) time_buffer, (S8*) get_string (VAPP_STR_DLA_UNKNOWN_TIME_REMAINING));
    }
    else
    {
        vapp_da_app_util_format_time((U16*)time_buffer, info.secs_remain);
        time_str = VFX_WSTR(" ");
        time_str += VFX_WSTR_RES(VAPP_STR_DLA_PROMPT_TIME_REMAIN);
        mmi_ucs2cat((S8*) time_buffer, (S8*) time_str.getBuf());
    }
    if (!isFolded)
    {
	    shell->set_text ((VfxWChar*)buffer_temp, shell->LIST_CONTROL_TEXT_SIZE);
	    if (m_list_type == VappDLAgentDownloadListPage::DLA_LIST_TYPE_DOWNLOADING_LIST)
	    {
            shell->set_text ((VfxWChar*)time_buffer, shell->LIST_CONTROL_TEXT_TIME);
			if (job->state == SRV_DA_JOB_STATE_DOWNLOADING || job->state == SRV_DA_JOB_STATE_PROCESSING || job->state == SRV_DA_JOB_STATE_WAITING)
            {
				srv_da_set_need_notify (job);
				string = VFX_WSTR_RES (STR_GLOBAL_PAUSE);
            }
			else if (job->state == SRV_DA_JOB_STATE_PAUSED || job->state == SRV_DA_JOB_STATE_PAUSED_WAITING || job->state == SRV_DA_JOB_STATE_RESUMING)
            {
				string = VFX_WSTR_RES (STR_GLOBAL_RESUME);
            }
			else if (job->state == SRV_DA_JOB_STATE_FAILED || job->state == SRV_DA_JOB_STATE_ABORTED)
            {
                string = VFX_WSTR_RES (VAPP_STR_DLA_RETRY);
            }
            shell->set_button_text(shell->m_left_button, string);
			string = VFX_WSTR_RES (VAPP_STR_DLA_DISCARD);
            shell->set_button_text(shell->m_right_button, string);

			if (job->state == SRV_DA_JOB_STATE_PROCESSING || job->setting_info.can_minimize == MMI_FALSE)
            {
                shell->set_button_enable(shell->m_left_button, VFX_FALSE);
            }
			else
            {
                shell->set_button_enable(shell->m_left_button, VFX_TRUE);
            }
            shell->set_button_enable(shell->m_right_button, VFX_TRUE);
        }
        else
        {
			shell->set_text ((VfxWChar*)(VFX_WSTR_RES(VAPP_STR_DLA_COMPLETED).getBuf()), shell->LIST_CONTROL_TEXT_TIME);
            string = VFX_WSTR_RES (STR_GLOBAL_OPEN);
            shell->set_button_text(shell->m_left_button, string);
            string = VFX_WSTR_RES (STR_GLOBAL_REMOVE);
            shell->set_button_text(shell->m_right_button, string);        
        }
    }
    else
    {
		fillStatusFieldToShell(job->state, buffer_temp, shell);	
    }
    if (m_list_type == VappDLAgentDownloadListPage::DLA_LIST_TYPE_DOWNLOADING_LIST)
    {
        if(percentage == MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN)
        {
            shell->set_progress (0.0);
        }
        else
        {
            shell->set_progress ((percentage/100));
        }
    }
    if ((job->state != SRV_DA_JOB_STATE_DOWNLOADING) && (job->state != SRV_DA_JOB_STATE_PROCESSING))
    {
        // We can stop progress bar animation here 
		if(job->state != SRV_DA_JOB_STATE_COMPLETED)
		{
        shell->progress_bar->pauseProgress();
			return;
		}
    }
	else 
	{
		shell->progress_bar->resumeProgress();
	}
}

VfxU32 VappDLAgentMainPageContentProvider::getCount() const 
{
    VfxU32   count; 
    if (m_list_type == VappDLAgentDownloadListPage::DLA_LIST_TYPE_DOWNLOADING_LIST)
    {
        count = (VfxU32) (srv_da_get_curr_job_count() - 
            srv_da_count_job(srv_da_job_match_state_func, SRV_DA_JOB_STATE_COMPLETED));
    }
    else
    {
        count = (VfxU32)(srv_da_count_job(srv_da_job_match_state_func, SRV_DA_JOB_STATE_COMPLETED));
    }
    return count;
}

VfxBool VappDLAgentMainPageContentProvider::getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color)
{
    if (m_list_type == VappDLAgentDownloadListPage::DLA_LIST_TYPE_DOWNLOADING_LIST)
    {
        text += VFX_WSTR_RES(VAPP_STR_DLA_NO_DOWNLOADING);
    }
    else
    {
        text += VFX_WSTR_RES(VAPP_STR_DLA_NO_COMPLETED);
    }
    return VFX_TRUE;
}


VcpListMenuCellClientBaseFrame *VappDLAgentMainPageContentProvider::getItemCustomContentFrame(
        VfxU32 index,        // [IN] index of the item
        VfxFrame *parentFrame // [IN] parent frame of the custom content frame
        )
{
    srv_da_job_struct *job = NULL;
    VfxS32            job_id;

    if (m_list_type == VappDLAgentDownloadListPage::DLA_LIST_TYPE_DOWNLOADING_LIST)
    {
        job = srv_da_get_nth_job_in_downloading_list (index);
    }
    else
    {
        job = srv_da_get_nth_job_in_completed_list (index);
    }
    if ((job == NULL) && (m_list_type == VappDLAgentDownloadListPage::DLA_LIST_TYPE_DOWNLOADING_LIST))
    {
        /* This condition occur only when a download just completed at service and MMI still have it in downloading list*/
        job = srv_da_get_nth_job_in_completed_list ((srv_da_count_job(srv_da_job_match_state_func, SRV_DA_JOB_STATE_COMPLETED) - (index + 1)));
    }

    if (list[index].get() == NULL)
    {
        VFX_OBJ_CREATE_EX(list[index], VappDLAgentDownloadListControl, parentFrame, (index, m_list_type));
        job_id = DA_JOB_GET_ID (job);
        list[index]->setArgID (job_id);
    }
    fillCustomFieldData (list[index].get(), job, !(list[index]->unfolded));
	return list[index].get();
}


//VFX_IMPLEMENT_CLASS("VappDLAgentDownloadListPage", VappDLAgentDownloadListPage, VfxPage);

void VappDLAgentDownloadListPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
	if(!(param.rotateTo == VFX_SCR_ROTATE_TYPE_0 || param.rotateTo == VFX_SCR_ROTATE_TYPE_270 || param.rotateTo == VFX_SCR_ROTATE_TYPE_90)) 
		param.rotateTo = VFX_SCR_ROTATE_TYPE_NORMAL;
}

void VappDLAgentDownloadListPage::onToolBarClick(VfxObject* sender, VfxId id)
{
    switch(id)
    {
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    case DLA_MAIN_PAGE_TB_PAUSE_ALL:
        srv_da_suspend_all_job(SRV_DA_ERROR_USER_CANCELLED);
        break;
    case DLA_MAIN_PAGE_TB_RESUME_ALL:
        if (srv_da_is_in_voice_call())
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_GENERAL,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_INFO,
                (WCHAR*)(VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL).getBuf()));
        }
        else
        {
            srv_da_resume_all_jobs ();
        }
        break;
    case DLA_MAIN_PAGE_TB_REMOVE_ALL:
        srv_da_remove_all_completed();
        //VcpDLAgentNCenter::updateAllCells();
        //VcpDLAgentNCenter::updateCompletedCells();
        VappDLAgentNCenterNew::vapp_dla_update_ncenter(NULL, 0);
        updateToolBar();
        break;
#endif /* __MMI_DOWNLOAD_AGENT_MULTI_DL__ */
    }
    if (m_download_list != NULL)
    {
        m_download_list->updateAllItems();
    }
    if (m_completed_list != NULL)
    {
        m_completed_list->updateAllItems();
    }
}


void VappDLAgentDownloadListPage::updateToolBar (void)
{
    if (m_download_list != NULL)
    {
        if (srv_da_count_special_job(srv_da_job_match_state_func, SRV_DA_JOB_STATE_DOWNLOADING) > 0)
        {
            m_downloadToolbar->setDisableItem(DLA_MAIN_PAGE_TB_PAUSE_ALL, VFX_FALSE);
        }
        else
        {
            m_downloadToolbar->setDisableItem(DLA_MAIN_PAGE_TB_PAUSE_ALL, VFX_TRUE);
        }


        if (srv_da_count_job(srv_da_job_match_state_func, SRV_DA_JOB_STATE_PAUSED) > 0 ||
			srv_da_count_job(srv_da_job_match_state_func, SRV_DA_JOB_STATE_RESUMING) > 0)
        {
            m_downloadToolbar->setDisableItem(DLA_MAIN_PAGE_TB_RESUME_ALL, VFX_FALSE);
        }
		else
        {
            m_downloadToolbar->setDisableItem(DLA_MAIN_PAGE_TB_RESUME_ALL, VFX_TRUE);
        }
    }

    if (m_completed_list != NULL)
    {
        if (srv_da_get_nth_job_in_completed_list(0) != NULL)
        {
            m_completedToolbar->setDisableItem(DLA_MAIN_PAGE_TB_REMOVE_ALL, VFX_FALSE);
        }
        else
        {
            m_completedToolbar->setDisableItem(DLA_MAIN_PAGE_TB_REMOVE_ALL, VFX_TRUE);
        }
    }
}

void VappDLAgentDownloadListPage::createAndSetListMenu (VcpListMenu *&list_menu, U16 height, U16 emhasisHeight)
{
	VFX_OBJ_CREATE(list_menu, VcpListMenu, this);
    list_menu->setBounds(VfxRect(0,0,getRect().getWidth(),getRect().getHeight()));
    list_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_CUSTOM);
	list_menu->setItemHeight(height);
    list_menu->setFocusStyle(VCP_LIST_MENU_FOCUS_BEHAVIOR_EMPHASIS);
	list_menu->setEmphasisFocusItemHeight(emhasisHeight);
    list_menu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);
}

void VappDLAgentDownloadListPage::createAndSetContentProvider(VappDLAgentMainPageContentProvider *&contentProvider, VfxU8 dla_list_type)
{
    VFX_OBJ_CREATE_EX(contentProvider, VappDLAgentMainPageContentProvider, this, (dla_list_type));
    for (int i = 0; i < 10; i++)
    {
        contentProvider->list[i] = NULL;
    }    
}

void VappDLAgentDownloadListPage::createAndSetToolBar(VcpToolBar *&toolbar)
{
	VFX_OBJ_CREATE(toolbar, VcpToolBar, this);
	toolbar->m_signalButtonTap.connect(this, &VappDLAgentDownloadListPage::onToolBarClick);
	setBottomBar(toolbar);
}


void VappDLAgentDownloadListPage::onInit (void)
 {
    VfxPage::onInit();

    switch (m_curr_list_type)
    {
    case DLA_LIST_TYPE_DOWNLOADING_LIST:
        {
			createAndSetListMenu(m_download_list, VAPP_DLA_DOWNLOAD_LIST_ITEM_FOLDED_HEIGHT, 
				VAPP_DLA_DOWNLOAD_LIST_ITEM_UNFOLDED_HEIGHT);
			createAndSetContentProvider(m_downloading_list_cp, DLA_LIST_TYPE_DOWNLOADING_LIST);
	        m_download_list->setContentProvider(m_downloading_list_cp);
			createAndSetToolBar(m_downloadToolbar);
            m_downloadToolbar->addItem(DLA_MAIN_PAGE_TB_PAUSE_ALL, VFX_WSTR_RES(VAPP_STR_DLA_PAUSE_ALL),VAPP_IMG_ID_DLA_TB_PAUSE_ALL);
            m_downloadToolbar->addItem(DLA_MAIN_PAGE_TB_RESUME_ALL, VFX_WSTR_RES(VAPP_STR_DLA_RESUME_ALL),VAPP_IMG_ID_DLA_RESUME_ALL);
        }
        break;
    case DLA_LIST_TYPE_COMPLETED_LIST:
        {
			createAndSetListMenu(m_completed_list, VAPP_DLA_COMPLETED_LIST_ITEM_FOLDED_HEIGHT, 
				VAPP_DLA_COMPLETED_LIST_ITEM_UNFOLDED_HEIGHT);
			createAndSetContentProvider(m_completed_list_cp, DLA_LIST_TYPE_COMPLETED_LIST);
	        m_completed_list->setContentProvider(m_completed_list_cp);
			createAndSetToolBar(m_completedToolbar);
            m_completedToolbar->addItem(DLA_MAIN_PAGE_TB_REMOVE_ALL, VFX_WSTR_RES(VAPP_STR_DLA_REMOVE_ALL),VAPP_IMG_ID_DLA_TB_REMOVE_ALL);
        }
        break;
    }
    updateToolBar();
}


//VFX_IMPLEMENT_CLASS("VappDLAgentMainPage", VappDLAgentMainPage, VcpTabCtrlPage);
void VappDLAgentMainPage::onInit(void)
{
    VcpTabCtrlPage::onInit();
    addTab(VAPP_DLA_TAB_DOWNLOAD, VFX_WSTR_RES (STR_GLOBAL_DOWNLOADING), VcpStateImage(VAPP_IMG_ID_DLA_TAB_DOWNLOADING));
    addTab(VAPP_DLA_TAB_COMPLETED, VFX_WSTR_RES (VAPP_STR_DLA_COMPLETED), VcpStateImage(VAPP_IMG_ID_DLA_COMPLETED_TAB_ICON));

    setCurrTab(m_selectedTab);
}

void VappDLAgentMainPage::onRotate(const VfxScreenRotateParam &param)
{
    VappDLAgentApp *m_dlaApp = (VappDLAgentApp *)getApp();
    if(!((param.rotateTo != VFX_SCR_ROTATE_TYPE_270) || (param.rotateTo != VFX_SCR_ROTATE_TYPE_0) || !(m_dlaApp->scr->m_tabbedDownload_page)))
    {
        return;
    }
    VappDLAgentMainPageContentProvider  *cp = NULL;

    if (m_dlaApp->scr->m_tabbedDownload_page->m_downloadingPage)
    {
        if (m_dlaApp->scr->m_tabbedDownload_page->m_downloadingPage->m_download_list != NULL)
        {
            cp = m_dlaApp->scr->m_tabbedDownload_page->m_downloadingPage->m_downloading_list_cp;
        }
		if (cp != NULL)
		{
			for (int i = 0; i < 10; i++)
			{
				if (cp->list[i].get() != NULL)
				{
					cp->list[i].get()->VappDLAgentDownloadListControl::resetPosition();
				}
			}
		}
		cp = NULL;
    }
    if (m_dlaApp->scr->m_tabbedDownload_page->m_CompletedPage)
    {
        
        if (m_dlaApp->scr->m_tabbedDownload_page->m_CompletedPage->m_completed_list != NULL)
        {
            cp = m_dlaApp->scr->m_tabbedDownload_page->m_CompletedPage->m_completed_list_cp;
        }
		if (cp != NULL)
		{
			for (int i = 0; i < 10; i++)
			{
				if (cp->list[i].get() != NULL)
				{
					cp->list[i].get()->VappDLAgentDownloadListControl::resetPosition();
				}
			}
		}
		cp = NULL;
    }
}


void VappDLAgentMainPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
    isRotated = (param.rotateTo == VFX_SCR_ROTATE_TYPE_270);
	if(!(param.rotateTo == VFX_SCR_ROTATE_TYPE_0 || param.rotateTo == VFX_SCR_ROTATE_TYPE_270 || param.rotateTo == VFX_SCR_ROTATE_TYPE_90)) 
		param.rotateTo = VFX_SCR_ROTATE_TYPE_NORMAL;
}

VfxPage* VappDLAgentMainPage::onCreateTabPage(VfxId tabId)
{
    switch (tabId)
    {
    case VAPP_DLA_TAB_DOWNLOAD:
        if (m_downloadingPage == NULL)
        {
            VFX_OBJ_CREATE_EX(m_downloadingPage, VappDLAgentDownloadListPage, this, (VappDLAgentDownloadListPage::DLA_LIST_TYPE_DOWNLOADING_LIST));
            //m_downloadingPage->m_arg_id = m_download_arg_id;
        }
        else
        {
            m_downloadingPage->updateToolBar();
            m_downloadingPage->m_download_list->updateAllItems();
        }
        srv_da_set_notified_failed ();
        //VcpDLAgentNCenter::updateFailedCells();
        return m_downloadingPage;
        //break;
    case VAPP_DLA_TAB_COMPLETED:
        if (m_CompletedPage == NULL)
        {
            VFX_OBJ_CREATE_EX(m_CompletedPage, VappDLAgentDownloadListPage, this, (VappDLAgentDownloadListPage::DLA_LIST_TYPE_COMPLETED_LIST));
            //m_CompletedPage->m_arg_id = m_completed_arg_id;
        }
        else
        {
            m_CompletedPage->updateToolBar();
            m_CompletedPage->m_completed_list->updateAllItems();
        }
        srv_da_set_notified_completed ();
        //VcpDLAgentNCenter::updateCompletedCells();
        return m_CompletedPage;
        //break;
    }
    return NULL;
}


/************************************************ START OF NEW DOWNLOAD RELATED MEMBER FUNCTION ********************************************/
#ifdef __MMI_MAINLCD_320X480__
	#define DLA_TEXT_VIEW_MARGIN 8
	#define DLA_BODY_FONT_SIZE 20
#elif __MMI_MAINLCD_480X800__

	#define DLA_TEXT_VIEW_MARGIN 14
	#define DLA_BODY_FONT_SIZE 26
#elif __MMI_MAINLCD_240X320__
	#define DLA_TEXT_VIEW_MARGIN 5
	#define DLA_BODY_FONT_SIZE 14
#elif __MMI_MAINLCD_432X240__
	#define DLA_TEXT_VIEW_MARGIN 5
	#define DLA_BODY_FONT_SIZE 14
#else
	#define DLA_TEXT_VIEW_MARGIN 10
	#define DLA_BODY_FONT_SIZE 18
#endif

#define VAPP_DA_GET_STRING(str_src) \
    (str_src == NULL || mmi_ucs2strlen(str_src) == 0) ? (const VfxWChar*)GetString(VAPP_STR_DLA_PROMPT_UNKNOWN) : (const VfxWChar*)(str_src)


void createAndSetPopup(VcpConfirmPopup *&confirmPopup, VcpPopupTypeEnum popuptype,
	VcpConfirmPopupButtonSetEnum buttonSet, const VfxWString &popuptext, VfxObject *parent)
{
	VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, parent);
	confirmPopup->setInfoType(popuptype);
	confirmPopup->setText(popuptext);
	confirmPopup->setButtonSet(buttonSet);
	confirmPopup->setAutoDestory(VFX_TRUE);
	confirmPopup->show(VFX_TRUE);
}

extern "C" mmi_ret vapp_da_evt_memory_card_plug(mmi_event_struct *evnt)
{
	VappDLAgentApp *m_dlaApp = ((VappDLAgentApp *)VfxApp::getObject(m_DLAgentAppID));
	if(m_dlaApp && m_dlaApp->scr->m_new_download_page && m_dlaApp->scr->m_new_download_page->m_selectDrive)
	{
		VfxWString driveString;
		VfxWString tempString;
		VfxU16     availableSize[50] = {'0', };
		driveString.setNull();
		tempString.setNull();
		srv_da_util_get_available_size (availableSize, SRV_DA_DRIVE_MEMORY_CARD);
		driveString = VFX_WSTR_RES(STR_GLOBAL_MEMORY_CARD);
		driveString += VFX_WSTR (" ");
		tempString.loadFromMem((VfxWChar*)availableSize);
		driveString += tempString;
		m_dlaApp->scr->m_new_download_page->m_selectDrive->updateItem(VappDLAgentNewDownloadPage::DLA_DRIVE_MEMORY_CARD, driveString);
		if(evnt->evt_id == EVT_ID_SRV_FMGRI_CARD_PLUG_IN)
		{
			m_dlaApp->scr->m_new_download_page->m_selectDrive->setIsDisableItem(VappDLAgentNewDownloadPage::DLA_DRIVE_MEMORY_CARD, VFX_FALSE);
		}
		else if(evnt->evt_id == EVT_ID_SRV_FMGRI_CARD_PLUG_OUT)
		{
			m_dlaApp->scr->m_new_download_page->m_selectDrive->setIsDisableItem(VappDLAgentNewDownloadPage::DLA_DRIVE_MEMORY_CARD, VFX_TRUE);
		}
	}
	return MMI_RET_OK;
}


void VappDLAgentNewDownloadPage::mreConfirmFillMsgString(void *arg, VcpTextView *mainText)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct  *job = (srv_da_job_struct*)arg;
	srv_da_item_progress_struct        info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	DA_JOB_GET_PROGRESS(job, info);
	FillConfirmPageItemString(VAPP_STR_DLA_PROMPT_SIZE, NULL, srv_da_util_format_size(info.fileSize),mainText);

	VfxWString promptType = VFX_WSTR_RES(VAPP_STR_DLA_PROMPT_TYPE);
	promptType += VFX_WSTR("\n");
	mainText->addDetail(promptType, VCP_TEXT_DETAIL_TITLE, SRV_DA_MAX_TEXT_BUFFER_LENGTH);
    
	VfxWString promptFile = VFX_WSTR("VXP ");
        promptFile += VFX_WSTR_RES(VAPP_DLA_STR_FILE);
	promptFile += VFX_WSTR("\n");
	promptFile += VFX_WSTR_RES(VAPP_STR_DLA_PROMPT_NEED_DOWNLOADING_NOTIFY_CHARGE);
	mainText->addDetail(promptFile, VCP_TEXT_DETAIL_CONTENT, SRV_DA_MAX_TEXT_BUFFER_LENGTH);
}

void VappDLAgentNewDownloadPage::httpConfirmFillMsgString(void *arg, VcpTextView *mainText)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct           *job;
    srv_da_normal_dl_job_struct *job_data;
    VfxU32 estimated_secs;
    VfxU16 time_buffer[MMI_DA_UTIL_ESTIMATED_TIME_FORMAT_LEN]; /* xx min. xx sec. */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    job = (srv_da_job_struct*)arg;
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

    if(job_data->size)
    {
		FillConfirmPageItemString(VAPP_STR_DLA_PROMPT_SIZE, NULL, srv_da_util_format_size(job_data->size),mainText);

        /* calculte the time require to DL */
        estimated_secs = srv_da_wps_estimate_time_to_download((U32)job, MMI_FALSE, job_data->size);
        if(MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN != estimated_secs)
        {
            vapp_da_app_util_format_time(time_buffer, estimated_secs);
			FillConfirmPageItemString(VAPP_STR_DLA_PROMPT_ESTIMATED, (VfxWChar *)time_buffer,NULL, mainText);
        }
    }
    else
    {
		FillConfirmPageItemString(VAPP_STR_DLA_PROMPT_SIZE, NULL, NULL,mainText);		
    }

    if(job->mime_type)
    {
		FillConfirmPageItemString(VAPP_STR_DLA_PROMPT_TYPE, NULL, (job->mime_type->mime_string),mainText);
    }
    else
    {
		VfxWString promptName = VFX_WSTR_RES(VAPP_STR_DLA_PROMPT_TYPE);
		promptName += VFX_WSTR("\n");
		mainText->addDetail(promptName, VCP_TEXT_DETAIL_TITLE, SRV_DA_MAX_TEXT_BUFFER_LENGTH);
		
		VfxWString ddInfoName = VFX_WSTR_RES(STR_GLOBAL_UNSUPPORTED_FORMAT);
        ddInfoName += VFX_WSTR("(");
        ddInfoName += m_ext;
        ddInfoName += VFX_WSTR(" ");
        ddInfoName += VFX_WSTR_RES(VAPP_DLA_STR_FILE);
        ddInfoName += VFX_WSTR(")");
		mainText->addDetail(ddInfoName, VCP_TEXT_DETAIL_CONTENT, SRV_DA_MAX_TEXT_BUFFER_LENGTH);
    }

}


void VappDLAgentNewDownloadPage::pushConfirmFillMsgString (void *arg, VcpTextView *mainText)
{
	U32 size = 0;
	srv_da_push_item_struct     *item;
	item = (srv_da_push_item_struct*)arg;
	size = srv_da_util_get_file_size (item->filepath);
	FillConfirmPageItemString(VAPP_STR_DLA_PROMPT_SIZE, NULL, srv_da_util_format_size(size),mainText);
    if (item->mime_type)
	{
		FillConfirmPageItemString(VAPP_STR_DLA_PROMPT_TYPE, NULL, (item->mime_type->mime_string),mainText);
	}
    else
    {
		VfxWString promptName = VFX_WSTR_RES(VAPP_STR_DLA_PROMPT_TYPE);
		promptName += VFX_WSTR("\n");
		mainText->addDetail(promptName, VCP_TEXT_DETAIL_TITLE, SRV_DA_MAX_TEXT_BUFFER_LENGTH);
		VfxWString ddInfoName = VFX_WSTR_RES(STR_GLOBAL_UNSUPPORTED_FORMAT);
        ddInfoName += VFX_WSTR("(");
        ddInfoName += m_ext;
        ddInfoName += VFX_WSTR(" ");
        ddInfoName += VFX_WSTR_RES(VAPP_DLA_STR_FILE);
        ddInfoName += VFX_WSTR(")");
		mainText->addDetail(ddInfoName, VCP_TEXT_DETAIL_CONTENT, SRV_DA_MAX_TEXT_BUFFER_LENGTH);
    }
}


void VappDLAgentNewDownloadPage::FillConfirmPageItemString(VfxU32 strID, VfxWChar* srcStr1, VfxChar* srcStr2, VcpTextView *mainText)
{
	VfxWString promptName = VFX_WSTR_RES(strID);
	promptName += VFX_WSTR("\n");
	mainText->addDetail(promptName, VCP_TEXT_DETAIL_TITLE, SRV_DA_MAX_TEXT_BUFFER_LENGTH);
	
	VfxWString ddInfoName;
	if (srcStr2)
	{
		VfxWChar *buff = ddInfoName.lockBuf((strlen(srcStr2)+ 1) * ENCODING_LENGTH);
		mmi_asc_to_ucs2((S8*) buff, (S8*) srcStr2);
		ddInfoName.unlockBuf();
	}
	else if (srcStr1)
		ddInfoName.loadFromMem((const VfxWChar *)VAPP_DA_GET_STRING((const S8*)srcStr1));
	else
		ddInfoName = VFX_WSTR_RES(VAPP_STR_DLA_PROMPT_UNKNOWN);
	ddInfoName += VFX_WSTR("\n");
	mainText->addDetail(ddInfoName, VCP_TEXT_DETAIL_CONTENT, SRV_DA_MAX_TEXT_BUFFER_LENGTH);

}


#ifdef __MMI_OMA_DD_DOWNLOAD__
void VappDLAgentNewDownloadPage::omaConfirmFillMsgString(void *arg, VcpTextView *mainText)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct          *job;
    srv_da_omadl_job_struct    *job_data;
    const srv_da_oma_dd_struct *dd_info;

    VfxS32 i, j;
    VfxU32 estimated_secs;
    VfxU16 time_buffer[MMI_DA_UTIL_ESTIMATED_TIME_FORMAT_LEN]; /* xx min. xx sec. */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    job = (srv_da_job_struct*)arg;
    job_data = (srv_da_omadl_job_struct*)job->data_ptr;
    
    dd_info = &job_data->dd_info;
    /* attribute display must follow ORDER appeared in Descriptor */
    /* name, vendor, type, size, description, infoURL, estimated time */
    //buffer[0] = 0;
    for(i = 0; i < dd_info->attr_num; i++)
    {
        switch(dd_info->attr_order[i])
        {
        case DD_ELEM_NAME:
			{
				FillConfirmPageItemString(VAPP_STR_DLA_PROMPT_NAME, (VfxWChar*)dd_info->name, NULL,mainText);
			}
            

            break;
            
        case DD_ELEM_VENDOR:
			{
				FillConfirmPageItemString(VAPP_STR_DLA_PROMPT_VENDOR, (VfxWChar*)dd_info->vendor, NULL,mainText);
			}
            break;

        case DD_ELEM_TYPE:
			{
				for(j=0;j<4;j++)
				{
					if(dd_info->type[j])
					{
						FillConfirmPageItemString(VAPP_STR_DLA_PROMPT_TYPE, NULL, dd_info->type[j],mainText);
					}
				}
			}
            break;
            
        case DD_ELEM_SIZE:
			{
            if(dd_info->size != 0)
            {
				FillConfirmPageItemString(VAPP_STR_DLA_PROMPT_SIZE, NULL, srv_da_util_format_size(dd_info->size),mainText);
            }
            else
            {
				FillConfirmPageItemString(VAPP_STR_DLA_PROMPT_SIZE, NULL,NULL, mainText);
            }
			}
            break;
            
        case DD_ELEM_DESCRIPTION:
			{
			    FillConfirmPageItemString(VAPP_STR_DLA_PROMPT_DESC, (VfxWChar*)dd_info->description,NULL, mainText);
			}
            break;

        case DD_ELEM_INFO_URL:
			{
 			    FillConfirmPageItemString(VAPP_STR_DLA_PROMPT_INFOURL, (VfxWChar*)dd_info->infoURL, NULL, mainText);
			}
            break;
            
        default:
            break;
        }

    }


    estimated_secs = srv_da_wps_estimate_time_to_download_by_channel((U32)job, job_data->channel, job_data->dd_info.size);
    
    if(MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN != estimated_secs)
    {
        vapp_da_app_util_format_time(time_buffer, estimated_secs);
        FillConfirmPageItemString(VAPP_STR_DLA_PROMPT_ESTIMATED, (VfxWChar *)time_buffer, NULL, mainText);
    }
}
#endif

void VappDLAgentNewDownloadPage::createDescription()
{
    srv_da_job_struct                           *job;
	job = (srv_da_job_struct*)m_arg;

    if (m_argSize == sizeof (srv_da_push_item_struct))
    {
        pushConfirmFillMsgString (m_arg, m_information_text->m_mainText);
        m_information_text->m_mainText->forceUpdate();
        m_information_text->setHeight (m_information_text->m_mainText->getSize().height);
        return;
    }
	switch (job->type)
	{
		case SRV_DA_JOB_TYPE_NORMAL:
		case SRV_DA_JOB_TYPE_HTTP_DOWNLOAD:
				httpConfirmFillMsgString(m_arg, m_information_text->m_mainText);
			break;
#ifdef __MMI_OMA_DD_DOWNLOAD__
		case SRV_DA_JOB_TYPE_OMADL:
				omaConfirmFillMsgString(m_arg, m_information_text->m_mainText);
			break;
#endif
		case SRV_DA_JOB_TYPE_MREDL:
				mreConfirmFillMsgString(m_arg, m_information_text->m_mainText);
			break;
		default :
				pushConfirmFillMsgString (m_arg, m_information_text->m_mainText);
			break;
	}

    m_information_text->m_mainText->forceUpdate();
    m_information_text->setHeight (m_information_text->m_mainText->getSize().height);

}




void VappDLAgentNewDownloadPage::set_default_location (VfxU32 drive) 
{
    if (drive == DLA_DRIVE_PHONE)
    {
        this->m_selectedDrive->setHintText (VFX_WSTR_RES (STR_GLOBAL_PHONE));
    }
    else
    {
        this->m_selectedDrive->setHintText (VFX_WSTR_RES (STR_GLOBAL_MEMORY_CARD));
    }
}


void VappDLAgentNewDownloadPage::setDownloadSize(VfxU32 size)
{
    this->m_downloadSize = size;
}


void VappDLAgentNewDownloadPage::set_display_text(VfxU16 *text)
{
    VfxWString  temp_str;
    temp_str.loadFromMem (text);
    this->m_information_text->setMainText(temp_str);
}


#ifndef __COSMOS_NO_USER_DRIVE__
void VappDLAgentNewDownloadPage::onStorageButtonClick (VfxBasePopup* popup, VfxBasePopupStateEnum state)
{
    VcpSelectPopup *selectPopup = (VcpSelectPopup *)popup;
    if (state == VFX_BASE_POPUP_AFTER_END_ANIMATION)
    {
        switch (selectPopup->getFirstSeletedId())
        {
        case DLA_DRIVE_PHONE:
            VappDLAgentNewDownloadPage::m_user_prefered_drive = DLA_DRIVE_PHONE;
            break;
        case DLA_DRIVE_MEMORY_CARD:
            VappDLAgentNewDownloadPage::m_user_prefered_drive = DLA_DRIVE_MEMORY_CARD;
            break;
        }
        this->set_default_location(VappDLAgentNewDownloadPage::m_user_prefered_drive);
		VFX_OBJ_CLOSE(m_selectDrive);
		m_selectDrive = NULL;
    }
}
#endif

void VappDLAgentNewDownloadPage::onOverwriteClick (void)
{
    VfxWString   filename;
    filename = filename_edit->getText();
    VfxU16     drive;
    VfxU16  filepath [SRV_FMGR_PATH_MAX_LEN + 2] = {'\0', };
    if (VappDLAgentNewDownloadPage::m_user_prefered_drive == DLA_DRIVE_MEMORY_CARD)
    {
        drive = SRV_DA_DRIVE_MEMORY_CARD;
    }
    else
    {
        drive = SRV_DA_DRIVE_PHONE;
    }
    srv_da_make_complete_filepath (filepath, m_arg, (U16*)(filename_edit->getText().getBuf()), (U16*)m_ext.getBuf(), drive, m_argSize);
    if(srv_da_util_file_delete(filepath) < 0)
    {
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_GENERAL,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_FAILURE,
            (WCHAR*)(VFX_WSTR_RES(VAPP_STR_DLA_ACCESS_FAILED).getBuf()));
        return;
    }

    VfxS32 result;
    result = srv_da_util_create_file_dir(filepath, MMI_TRUE);
    if (result < 0)
    {
        VappDLAgentApp *m_dlaApp = (VappDLAgentApp *)this->getPage()->getApp();
        m_dlaApp->scr->createPopup(VCP_INFO_BALLOON_TYPE_FAILURE, srv_fmgr_fs_error_get_string(result));
    }

    startNewDownloadMemCheck (filepath);
}

void VappDLAgentNewDownloadPage::startNewDownloadMemCheck(U16 *filepath)
{
    //extern void vapp_da_show_display_confirm (srv_da_confirm_struct  *confPara);
    srv_fmgr_drv_type_enum drv = SRV_FMGR_DRV_PHONE_TYPE;
    VfxU8 drvLetter;
    switch (VappDLAgentNewDownloadPage::m_user_prefered_drive)
    {
    case DLA_DRIVE_PHONE:
        drv = SRV_FMGR_DRV_PHONE_TYPE;
        break;
    case DLA_DRIVE_MEMORY_CARD:
        drv = SRV_FMGR_DRV_CARD_TYPE;
        break;
    }
    drvLetter = srv_fmgr_drv_get_letter_by_type (drv);
    if (srv_fmgr_drv_is_accessible(drvLetter))
    {
        VfxU64 totalSize, freeSize;
        srv_fmgr_drv_get_size(drvLetter, &totalSize, &freeSize);
        if (freeSize > m_downloadSize)
        {
            isCalledBack = VFX_TRUE;
            VfxS32 result;
            result = srv_da_util_create_file_dir(filepath, MMI_TRUE);
            if (result < 0)
            {
                VappDLAgentApp *m_dlaApp = (VappDLAgentApp *)this->getPage()->getApp();
                m_dlaApp->scr->createPopup(VCP_INFO_BALLOON_TYPE_FAILURE, srv_fmgr_fs_error_get_string(result));
                return;
            }
            downloadLSK   start = m_downloadStart;
            void *arg = m_arg;
			//first close the app and then launch it again.
            VfxAppLauncher::terminate(m_DLAgentAppID);
            start (arg, filepath);
        }
        else
        {
			createAndSetPopup(m_confirmPopup, VCP_POPUP_TYPE_FAILURE, VCP_CONFIRM_BUTTON_SET_OK, VFX_WSTR_RES(STR_GLOBAL_NOT_ENOUGH_MEMORY), this->getPage());
        }
    }
    else
    {
		createAndSetPopup(m_confirmPopup, VCP_POPUP_TYPE_FAILURE, VCP_CONFIRM_BUTTON_SET_OK, VFX_WSTR_RES(STR_GLOBAL_INSERT_MEMORY_CARD), this->getPage());
    }
}


void VappDLAgentNewDownloadPage::onRenameConfirmation(VfxObject* obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        (filename_edit->getTextBox())->activate ();
    }
    else if (id == VCP_CONFIRM_POPUP_BUTTON_USER_2)
    {
        onOverwriteClick();
    }
}

void VappDLAgentNewDownloadPage::wcharTrim(const VfxWChar *str, VfxWChar *strout)
{
    VfxU8 endtemp = 0, end = 0;
	if(str == NULL)
		return;
	while (IS_SPACE(*str)) {str++;}
	for (int i = 0; *(str + i) != '\0'; i++)
	{
		endtemp++;
		if(!IS_SPACE(*(str + i)))
		{
			end = endtemp;
		}	
	}
	mmi_wcsncpy(strout, str, end);
}


void VappDLAgentNewDownloadPage::onNewDownloadToolbarClick(VfxObject* sender, VfxId id)
{
    switch (id)
	{
	case DLA_NEW_DL_TB_DOWNLOAD:
    case DLA_NEW_DL_DOWNLOAD_FUNC_BAR:
        {
            VfxWString   filename;
			VfxWChar     filenametemp[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 2] = {0};
            VcpTextEditor *editor = filename_edit->getTextBox();
            filename = filename_edit->getText();
            //before check the file name, using the function to remove spaces at the start and the tail of the name.
            wcharTrim(filename.getBuf(), filenametemp);
			filename.loadFromMem(filenametemp);
            if (filename.isEmpty() || !srv_fmgr_path_is_filename_valid(filename.getBuf()))
            {
                filename_edit->setWarningText(VFX_WSTR_RES(STR_GLOBAL_INVALID_FILENAME));
                return;
            }

            VfxU16     drive;
            VfxU16  filepath [SRV_FMGR_PATH_MAX_LEN + 2] = {'\0', };
            if (VappDLAgentNewDownloadPage::m_user_prefered_drive == DLA_DRIVE_MEMORY_CARD)
            {
                drive = SRV_DA_DRIVE_MEMORY_CARD;
            }
            else
            {
                drive = SRV_DA_DRIVE_PHONE;
            }

        #ifdef __MMI_USB_SUPPORT__
            if (srv_usb_is_in_mass_storage_mode())
            {
                vapp_usb_unavailable_popup(0);
                return;
            }
        #endif /* __MMI_USB_SUPPORT__ */

            srv_da_make_complete_filepath (filepath, m_arg, (U16*)(filename.getBuf()), (U16*)m_ext.getBuf(), drive, m_argSize);
            if (srv_da_does_job_with_filepath_exist (filepath, MMI_FALSE))
            {
                vapp_nmgr_global_popup_show_confirm_one_button_str(
                    MMI_SCENARIO_ID_DEFAULT,
                    VCP_POPUP_TYPE_FAILURE, 
                    VFX_WSTR_RES(VAPP_STR_DLA_JOB_EXIST),
                    VFX_WSTR_RES(STR_GLOBAL_RENAME),
                    VCP_POPUP_BUTTON_TYPE_NORMAL,
                    NULL,
                    NULL);
                return;
            }
			
            else if (srv_da_util_does_file_exist (filepath))
            {
				createAndSetPopup(m_confirmPopup, VCP_POPUP_TYPE_FAILURE, VCP_CONFIRM_BUTTON_SET_USER_DEFINE, VFX_WSTR_RES(VAPP_STR_DLA_FILENAME_ALREADY_EXISTS), this->getPage());
                m_confirmPopup->setCustomButton(VFX_WSTR_RES (STR_GLOBAL_RENAME),
                    VFX_WSTR_RES (VAPP_STR_DLA_OVERWRITE), 
                    VCP_POPUP_BUTTON_TYPE_NORMAL, 
                    VCP_POPUP_BUTTON_TYPE_NORMAL);
                m_confirmPopup->m_signalButtonClicked.connect(this, &VappDLAgentNewDownloadPage::onRenameConfirmation);
                return;
            }
            else
            {
                startNewDownloadMemCheck (filepath);
            }
        }
		break;
	case DLA_NEW_DL_TB_CANCEL:
        {
            isCalledBack = VFX_TRUE;
            m_downloadCancel (m_arg);

            VappDLAgentScreen *screen = (VappDLAgentScreen*) this->getPage()->getMainScr();
            screen->closePage(screen->DLA_PAGE_NEW_DOWNLOAD_PAGE);
        }
		break;

#ifndef __COSMOS_NO_USER_DRIVE__
	case DLA_NEW_DL_STORAGE_BUTTON:
        {
            VfxWString driveString;
            VfxWString tempString;
            VfxU16      availableSize[50] = {'0', };

			ASSERT(m_selectDrive == NULL);
			//m_selectDrive = NULL;
            VFX_OBJ_CREATE(m_selectDrive, VcpSelectPopup, this->getPage());
            m_selectDrive->setText(VFX_WSTR_RES(VAPP_STR_DLA_SELECT_STORAGE));

            driveString = VFX_WSTR_RES(STR_GLOBAL_PHONE);
            srv_da_util_get_available_size (availableSize, SRV_DA_DRIVE_PHONE);
            driveString += VFX_WSTR (" ");
            tempString.loadFromMem((VfxWChar*)availableSize);
            driveString += tempString;
            m_selectDrive->addItem(DLA_DRIVE_PHONE, driveString, (VappDLAgentNewDownloadPage::m_user_prefered_drive == DLA_DRIVE_PHONE));

            memset (availableSize, 0, 50);
            driveString.setNull();
            tempString.setNull();
            srv_da_util_get_available_size (availableSize, SRV_DA_DRIVE_MEMORY_CARD);
            driveString = VFX_WSTR_RES(STR_GLOBAL_MEMORY_CARD);
            driveString += VFX_WSTR (" ");
            tempString.loadFromMem((VfxWChar*)availableSize);
            driveString += tempString;
            m_selectDrive->addItem(DLA_DRIVE_MEMORY_CARD, driveString, (VappDLAgentNewDownloadPage::m_user_prefered_drive == DLA_DRIVE_MEMORY_CARD));

            m_selectDrive->setAutoDestory(VFX_FALSE);
            m_selectDrive->setType (VCP_SELECT_POPUP_BUTTON_TYPE_QUICK);
            m_selectDrive->m_signalPopupState.connect(this, &VappDLAgentNewDownloadPage::onStorageButtonClick);
            if (!srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type (SRV_FMGR_DRV_CARD_TYPE)))
            {
                m_selectDrive->setIsDisableItem(DLA_DRIVE_MEMORY_CARD, VFX_TRUE);
            }

            (filename_edit->getTextBox())->deactivate();
            m_selectDrive->show(VFX_TRUE);
        }
		break;
#endif
    default:
        ASSERT(0);
        break;
    }
}

void VappDLAgentNewDownloadPage::onPageDeinit(VfxPageEx *page)
{
    if (!isCalledBack)
    {
        isCalledBack = VFX_TRUE;
        m_downloadCancel (m_arg);
    }
    VfxPageHandler::onPageDeinit(page);
}



void VappDLAgentNewDownloadPage::onPageBack(VfxPageEx * page)
{
    VappDLAgentApp *m_dlaApp = (VappDLAgentApp *)this->getPage()->getApp();
    isCalledBack = VFX_TRUE;
    m_dlaApp->scr->closePage(m_dlaApp->scr->DLA_PAGE_NEW_DOWNLOAD_PAGE);
    m_downloadCancel (m_arg);
}

void VappDLAgentNewDownloadPage::onPageRotate(VfxPageEx * page,const VfxScreenRotateParam & param)
{
    m_information_text->m_mainText->setSize(page->getParentFrame()->getSize().width, 300);
}


void VappDLAgentNewDownloadPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
	if(!(param.rotateTo == VFX_SCR_ROTATE_TYPE_0 || param.rotateTo == VFX_SCR_ROTATE_TYPE_270 || param.rotateTo == VFX_SCR_ROTATE_TYPE_90)) 
		param.rotateTo = VFX_SCR_ROTATE_TYPE_NORMAL;
}

void VappDLAgentNewDownloadPage::onPageInit (VfxPageEx *page)
{
	VfxPageHandler::onPageInit(page);

	
	VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, page);
   
    srv_da_job_struct *job = (srv_da_job_struct*)m_arg;

    if ((job->type == SRV_DA_JOB_TYPE_NORMAL) 
#ifdef __MMI_OMA_DD_DOWNLOAD__
	|| (job->type == SRV_DA_JOB_TYPE_OMADL) 
#endif
	|| (job->type == SRV_DA_JOB_TYPE_MREDL) || (job->type == SRV_DA_JOB_TYPE_HTTP_DOWNLOAD))
    {
        bar->setTitle(VFX_WSTR_RES(VAPP_STR_DLA_FILE_DOWNLOADING));
    }
    else
    {
        bar->setTitle(VFX_WSTR_RES(VAPP_STR_DLA_FILE_SAVE_TO));
    }

    page->setTopBar(bar);

    /* Setting flag to check whether callback is called or not */
    isCalledBack = VFX_FALSE;

    VFX_OBJ_CREATE(m_form, VcpForm, page);

    VfxRect   rectangle = page->getRect();

    m_form->setPos(rectangle.getX(), rectangle.getY());
    m_form->setBounds(VfxRect(0,0,rectangle.size.width, rectangle.size.height));
	m_form->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
   
    /* File name editor */
    VFX_OBJ_CREATE(filename_edit, VcpFormItemTextInput, m_form);
    filename_edit->setLabelPosition (VCPFORM_TOP_LEFT);
    filename_edit->setLabelText (VFX_WSTR_RES(VAPP_STR_DA_FILE_NAME));
    (filename_edit->getTextBox())->setMaxLength(MMI_DA_MAX_FILENAME_INPUT_LEN);
	VsrvInputBinding inputBinding(
		IMM_INPUT_TYPE_SENTENCE,
		IME_DISABLE_NEW_LINE_SYMBOL,
		IME_INPUT_STYLE_NONE,
		(filename_edit->getTextBox())->m_editing
		);
	inputBinding.setDisabledChars(VFX_WSTR_MEM((VfxWChar*)srv_fmgr_path_get_invalid_chars()));
	(filename_edit->getTextBox())->setIME(inputBinding);
  
    /* Download function bar */
    VFX_OBJ_CREATE(m_downloadFuncBar, VcpFunctionBar, page);
    if ((job->type == SRV_DA_JOB_TYPE_NORMAL) 
#ifdef __MMI_OMA_DD_DOWNLOAD__
		|| (job->type == SRV_DA_JOB_TYPE_OMADL) 
#endif
		|| (job->type == SRV_DA_JOB_TYPE_MREDL) || (job->type == SRV_DA_JOB_TYPE_HTTP_DOWNLOAD))
    {
	    m_downloadFuncBar->addItem(DLA_NEW_DL_DOWNLOAD_FUNC_BAR, VFX_WSTR_RES(STR_GLOBAL_START));
    }
    else
    {
	    m_downloadFuncBar->addItem(DLA_NEW_DL_DOWNLOAD_FUNC_BAR, VFX_WSTR_RES(STR_GLOBAL_SAVE));
    }
    m_downloadFuncBar->setItemSpecial(DLA_NEW_DL_DOWNLOAD_FUNC_BAR);
    //m_downloadFuncBar->setBgColor(VfxColor(VFX_COLOR_BLACK));
    (filename_edit->getTextBox())->setFunctionBar(m_downloadFuncBar);
    m_downloadFuncBar->m_signalButtonTap.connect(this, &VappDLAgentNewDownloadPage::onNewDownloadToolbarClick);

#ifndef __COSMOS_NO_USER_DRIVE__
    /* storage selection button */
    VFX_OBJ_CREATE(m_selectedDrive, VcpFormItemBigButton, m_form);
    m_selectedDrive->setButtonText (VFX_WSTR_RES(STR_GLOBAL_STORAGE));

    if (VappDLAgentNewDownloadPage::m_user_prefered_drive == DLA_DRIVE_PHONE)
    {
        m_selectedDrive->setHintText (VFX_WSTR_RES(STR_GLOBAL_PHONE));
    }
    else
    {
        m_selectedDrive->setHintText (VFX_WSTR_RES (STR_GLOBAL_MEMORY_CARD));
    }
    m_selectedDrive->getButton()->setId (DLA_NEW_DL_STORAGE_BUTTON);
    m_selectedDrive->getButton()->m_signalClicked.connect(this, &VappDLAgentNewDownloadPage::onNewDownloadToolbarClick);
#endif

    /* Download hint text custom control frame */
    VFX_OBJ_CREATE(m_information_text, VcpDLAgentNewDownloadFormItemViewerCell, m_form);
    m_form->addItem (filename_edit, DLA_NEW_DL_FILENAME);
#ifndef __COSMOS_NO_USER_DRIVE__
    m_form->addItem (m_selectedDrive, DLA_NEW_DL_STORAGE);
#endif
    m_form->addItem (m_information_text, DLA_NEW_DL_DETAIL_TEXT);

    /* Download toolbar */
	VFX_OBJ_CREATE(m_toolbar, VcpToolBar,page);
    m_toolbar->m_signalButtonTap.connect(this, &VappDLAgentNewDownloadPage::onNewDownloadToolbarClick);
    page->setBottomBar(m_toolbar);//NOTICE THIS PART
    if ((job->type == SRV_DA_JOB_TYPE_NORMAL) 
#ifdef __MMI_OMA_DD_DOWNLOAD__
		|| (job->type == SRV_DA_JOB_TYPE_OMADL) 
#endif
		|| (job->type == SRV_DA_JOB_TYPE_MREDL) || (job->type == SRV_DA_JOB_TYPE_HTTP_DOWNLOAD))
    {
        m_toolbar->addItem(DLA_NEW_DL_TB_DOWNLOAD, VFX_WSTR_RES(STR_GLOBAL_DOWNLOAD),VAPP_IMG_ID_DLA_TB_DOWNLOAD);
    }
    else
    {
        m_toolbar->addItem(DLA_NEW_DL_TB_DOWNLOAD, VFX_WSTR_RES(STR_GLOBAL_SAVE), VAPP_IMG_ID_DLA_TB_SAVE);
    }
    m_toolbar->addItem(DLA_NEW_DL_TB_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL),VAPP_IMG_ID_DLA_TB_CANCEL);
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
#ifdef __MMI_OMA_DD_DOWNLOAD__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_OMA_DD_DOWNLOAD__
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
#ifndef __COSMOS_NO_USER_DRIVE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#ifndef __COSMOS_NO_USER_DRIVE__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_OMA_DD_DOWNLOAD__
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
#endif
/************************************************ END OF NEW DOWNLOAD RELATED MEMBER FUNCTION  *********************************************/

void VcpDLAgentNewDownloadFormItemViewerCell::onInit(void)
{
	VfxControl::onInit();
    setSize(getParentFrame()->getSize().width, 300);	
    VFX_OBJ_CREATE(m_mainText, VcpTextView, this);
    m_mainText->setSize(getParentFrame()->getSize().width, 300);
    m_mainText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(DLA_BODY_FONT_SIZE)));
	m_mainText->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
    m_mainText->setMargins(DLA_TEXT_VIEW_MARGIN,DLA_TEXT_VIEW_MARGIN,DLA_TEXT_VIEW_MARGIN,DLA_TEXT_VIEW_MARGIN);
	m_mainText->setAutoResized(VFX_TRUE);
	VFX_ALLOC_MEM(m_bodyText, SRV_DA_MAX_TEXT_BUFFER_LENGTH, this);
	memset(m_bodyText, 0, SRV_DA_MAX_TEXT_BUFFER_LENGTH);
	m_mainText->setText(m_bodyText, VFX_TRUE);
    setHeight (300);
}

void VcpDLAgentNewDownloadFormItemViewerCell::onDeinit(void)
{
	VFX_FREE_MEM (m_bodyText);
	VfxControl::onDeinit();
}


void VcpDLAgentNewDownloadFormItemViewerCell::setMainText(const VfxWString &text)
{
    m_mainText->setText(text);
    m_mainText->forceUpdate();
    setHeight (m_mainText->getSize().height);
}



/**********************************************************************************************************************************************/
/*                                          STARTING AUTHENTICATION SCREEN DRAW                                                               */
/**********************************************************************************************************************************************/

void VappDLAgentUserAuthPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
	if(!(param.rotateTo == VFX_SCR_ROTATE_TYPE_0 || param.rotateTo == VFX_SCR_ROTATE_TYPE_270 || param.rotateTo == VFX_SCR_ROTATE_TYPE_90)) 
		param.rotateTo = VFX_SCR_ROTATE_TYPE_NORMAL;
}

void VappDLAgentUserAuthPage::onUserAuthToolbarClick(VfxObject* sender, VfxId id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void                                 *arg;
    srv_da_show_user_auth_event_struct   *auth_arg;

    VfxWString                           username;
    VfxWString                           password;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VappDLAgentApp *m_dlaApp = (VappDLAgentApp *)getApp();
    arg = getCallbackArgument();
    auth_arg = (srv_da_show_user_auth_event_struct*)arg;

    switch (id)
	{
	case DLA_USERAUTH_SUBMIT:
    case DLA_USER_AUTH_FUNCBAR:
        username = m_username->getText();
        password = m_password->getText();
        auth_arg->auth_callback (auth_arg->arg, (U16*)username.getBuf(), (U16*)password.getBuf());
        m_isCalledBack = VFX_TRUE;
        break;
	case DLA_USERAUTH_CANCEL:
        auth_arg->auth_callback (auth_arg->arg, NULL, NULL);
        m_isCalledBack = VFX_TRUE;
        break;
	case DLA_FUNCBAR_NEXT:
	case DLA_FUNCBAR_PREV:
		if(m_pwEditor)
			m_pwEditor->activate();
		else if(m_nameEditor)
			m_nameEditor->activate();
		return;
    }
    m_dlaApp->scr->closePage(m_dlaApp->scr->DLA_PAGE_USER_AUTH_PAGE);
}

void VappDLAgentUserAuthPage::onDLTextEditorActivated(VcpTextEditor *sender, VfxBool isActive)
{
    if(isActive)
    {
        if(sender == m_username->getTextBox ())
        {
            m_nameEditor= NULL;
            m_pwEditor= m_password->getTextBox ();
        }
        else if(sender == m_password->getTextBox ())
        {
            m_nameEditor = m_username->getTextBox ();
            m_pwEditor = NULL;
        }      
        m_submitFuncBar->setDisableItem (DLA_FUNCBAR_PREV, m_nameEditor == NULL);
        m_submitFuncBar->setDisableItem (DLA_FUNCBAR_NEXT, m_pwEditor == NULL);
    }
}

void VappDLAgentUserAuthPage::onDeinit(void)
{
    if (!m_isCalledBack)
    {
        srv_da_show_user_auth_event_struct   *auth_arg;
        void                                 *arg;
        arg = getCallbackArgument();
        auth_arg = (srv_da_show_user_auth_event_struct*)arg;
        auth_arg->auth_callback (auth_arg->arg, NULL, NULL);
    }
    VfxPage::onDeinit();
}


void VappDLAgentUserAuthPage::onInit(void)
{
    VfxPage::onInit();

    m_isCalledBack = VFX_FALSE;
    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(STR_GLOBAL_AUTHENTICATION));
    setTopBar(bar);

    VFX_OBJ_CREATE(m_form, VcpForm, this);

    VfxRect   rectangle = getRect();

    m_form->setPos(rectangle.getX(), rectangle.getY());
    m_form->setBounds(VfxRect(0,0,getRect().getWidth(),getRect().getHeight()));

    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);

    VFX_OBJ_CREATE(m_username, VcpFormItemTextInput, m_form);
    m_username->setLabelPosition (VCPFORM_TOP_LEFT);
    m_username->setLabelText (VFX_WSTR_RES(STR_GLOBAL_USERNAME));
    (m_username->getTextBox())->setMaxLength(VAPP_DA_AUTH_LEN_USERNAME);
    m_form->addItem (m_username, DLA_USER_AUTH_USERNAME);
	m_username->getTextBox()->m_signalActivated.connect(
        this, &VappDLAgentUserAuthPage::onDLTextEditorActivated);

    /* Submit function bar */
    VFX_OBJ_CREATE(m_submitFuncBar, VcpFunctionBar, this);
    m_submitFuncBar->addItem(DLA_USER_AUTH_FUNCBAR, VFX_WSTR_RES(STR_GLOBAL_SUBMIT));
	m_submitFuncBar->addItem(DLA_FUNCBAR_PREV, 		VFX_WSTR_RES(STR_GLOBAL_PREV));
	m_submitFuncBar->addItem(DLA_FUNCBAR_NEXT, 		VFX_WSTR_RES(STR_GLOBAL_NEXT));
    m_submitFuncBar->setItemSpecial(DLA_USER_AUTH_FUNCBAR);
    (m_username->getTextBox())->setFunctionBar(m_submitFuncBar);
    m_submitFuncBar->m_signalButtonTap.connect(this, &VappDLAgentUserAuthPage::onUserAuthToolbarClick);

    VFX_OBJ_CREATE(m_password, VcpFormItemTextInput, m_form);
    m_password->setLabelPosition (VCPFORM_TOP_LEFT);
    m_password->setLabelText (VFX_WSTR_RES(STR_GLOBAL_PASSWORD));
    (m_password->getTextBox())->setMaxLength(VAPP_DA_AUTH_LEN_PASSWORD);
    (m_password->getTextBox())->setIME(IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD);
    m_form->addItem (m_password, DLA_USER_AUTH_PASSWORD);
    (m_password->getTextBox())->setFunctionBar(m_submitFuncBar);
	m_password->getTextBox()->m_signalActivated.connect(
        this, &VappDLAgentUserAuthPage::onDLTextEditorActivated);

	VFX_OBJ_CREATE(m_toolbar, VcpToolBar,this);
    m_toolbar->m_signalButtonTap.connect(this, &VappDLAgentUserAuthPage::onUserAuthToolbarClick);
    setBottomBar(m_toolbar);

    m_toolbar->addItem(DLA_USERAUTH_SUBMIT, VFX_WSTR_RES(STR_GLOBAL_SUBMIT),VAPP_IMG_ID_DLA_TB_SUBMIT);
    m_toolbar->addItem(DLA_USERAUTH_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL),VAPP_IMG_ID_DLA_TB_CANCEL);
}



void VappDLAgentUserAuthPage::onBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void                                 *arg;
    srv_da_show_user_auth_event_struct   *auth_arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VappDLAgentApp *m_dlaApp = (VappDLAgentApp *)getApp();

    arg = getCallbackArgument();
    auth_arg = (srv_da_show_user_auth_event_struct*)arg;
    auth_arg->auth_callback (auth_arg->arg, NULL, NULL);
    m_isCalledBack = VFX_TRUE;
    m_dlaApp->scr->closePage(m_dlaApp->scr->DLA_PAGE_USER_AUTH_PAGE);
}

/**********************************************************************************************************************************************/
/*                                          END AUTHENTICATION SCREEN DRAW                                                                    */
/**********************************************************************************************************************************************/



/**********************************************************************************************************************************************/
/*                                          STARTING JOB DETAIL SCREEN DRAW                                                                   */
/**********************************************************************************************************************************************/

void VappDLAgentJobDetailPage::onCancelClick(VfxObject* obj, VfxFloat curr_progress)
{
    srv_da_display_job_detail_event_struct *jobDetail = (srv_da_display_job_detail_event_struct*)m_arg;
    srv_da_job_struct *job = (srv_da_job_struct*)jobDetail->job;
    srv_da_curr_job_do_abort (job);
}

void VappDLAgentJobDetailPage::setProgress(VfxFloat value)
{
    m_progressIndicator->setProgress(value);
}


void VappDLAgentJobDetailPage::updateStatus (void *arg)
{
    if (arg)
    {
        srv_da_job_struct *job = (srv_da_job_struct*)arg;
        VfxS32 job_id = DA_JOB_GET_ID (job);

        if (job_id == m_argId)
        {
            VfxFloat                           percentage;
            srv_da_item_progress_struct        info;
            percentage = (VfxFloat) DA_JOB_GET_PROGRESS(job, info);            
            if ((job->state == SRV_DA_JOB_STATE_COMPLETED) || (job->state == SRV_DA_JOB_STATE_ABORTED) || (job->state == SRV_DA_JOB_STATE_FAILED))
            {
                VappDLAgentScreen *screen = (VappDLAgentScreen*) this->getMainScr();
                screen->closePage(screen->DLA_PAGE_JOB_DETAIL_PAGE);
				return;
            }
			if(percentage == MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN)
            {
                setProgress (0.0);
            }
            else
            {
                setProgress ((percentage/100));
            }
        }
    }
}


void VappDLAgentJobDetailPage::onInit(void)
{
    srv_da_display_job_detail_event_struct *jobDetail = (srv_da_display_job_detail_event_struct*)m_arg;
    srv_da_job_struct *job = (srv_da_job_struct*)jobDetail->job;
    VfxPage::onInit();
    m_argId = DA_JOB_GET_ID (job);
    VFX_OBJ_CREATE(m_progressIndicator, VcpIndicatorPopup, this);
    m_progressIndicator->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON);
#ifdef __MMI_OMA_DD_DOWNLOAD__
	if(srv_da_oma_is_oma_processing_required(job->mime_type))
	{
		m_progressIndicator->setText(VFX_WSTR_RES(VAPP_STR_DLA_DOWNLOADING_DESCRIPTOR));
	}
	else
#endif
	{
		m_progressIndicator->setText(VFX_WSTR_RES(jobDetail->str_id));
	}
    m_progressIndicator->m_signalCanceled.connect(this, &VappDLAgentJobDetailPage::onCancelClick);

    VfxFloat                           percentage;
    srv_da_item_progress_struct        info;
    percentage = (VfxFloat) DA_JOB_GET_PROGRESS(job, info);

    if(percentage == MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN)
    {
        m_progressIndicator->setProgress (0.0);
    }
    else
    {
        setProgress ((percentage/100));
    }
    m_progressIndicator->show (VFX_TRUE);
}
/**********************************************************************************************************************************************/
/*                                          END JOB DETAIL SCREEN DRAW                                                                        */
/**********************************************************************************************************************************************/
