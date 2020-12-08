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
 *  vapp_mms_lite_viewer.cpp
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

#include "MMI_features.h"
#include "vapp_msg_features.h"

#ifdef __MMI_MMS_2__
#include "vadp_mmi_frm.h"
#include "vfx_uc_include.h"
#include "vcp_text_view.h"
#include "vcp_app_scr.h"
#include "vcp_include.h"
#include "ui_core\mvc\vfx_mmi.h"

#include "vcp_status_icon_bar.h"
#include "vcp_page_panel.h"
#include "vcp_list_menu.h"
#include "vcp_popup.h"
#include "vcp_image_button.h"
#include "vapp_mms_details_viewer.h"
#include "fileMgrGProt.h"
#include "mmi_include.h"
#include "ctype.h" 
#include "kal_release.h"
#include "MMIDataType.h"
#include "mmi_include.h"
#include "kal_trace.h"
#include "SettingProfile.h"
#include "fileMgrGProt.h"
#include "Fs_type.h"
#include "med_api.h"
#include "med_smalloc.h"
#include "gdi_include.h"
#include "gdi_layer.h"
/* Venus MMI headers: */
#include "ui_core\base\vfx_datatype.h"
#include "ui_core\base\vfx_base.h"
#include "trc\vadp_app_trc.h"
#include "MMI_features.h"



#include "mmi_include.h"
#include "ctype.h" 
#include "kal_release.h"
#include "MMIDataType.h"
#include "mmi_include.h"
#include "kal_trace.h"
#include "SettingProfile.h"
#include "fileMgrGProt.h"
#include "Fs_type.h"
#include "med_api.h"
#include "med_smalloc.h"
#include "gdi_include.h"
#include "gdi_layer.h"

#include "CubeAppGprot.h"
#include "CubeAppProt.h"
#include "CubeApp\vadp_p2v_cube.h"
#include "CubeApp\vadp_v2p_cube.h"

/* Venus MMI headers: */
#include "ui_core\base\vfx_datatype.h"
#include "ui_core\base\vfx_base.h"
#include "trc\vadp_app_trc.h"
#include "DateTimeGprot.h"
#include "vapp_mms_toolbar.h"
#include "mmi_rp_vapp_mms_def.h"
extern "C"
{
#include "MmsSrvGprot.h"
#include "MMSSRVProt.h"
#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGProt.h"
#include "mms_sap_struct.h"

#ifdef __MMI_VIDEO_PLAY_SUPPORT__
#include "gdi_include.h"
#include "mdi_video.h"
#endif
}
//#include "vcp_msg_contact_bar.h"
#include "vapp_mms_lite_viewer.h"
#include "vapp_mms_viewer.h"
#include "vcp_photo_border_frame.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "vapp_mms_appcore.h"
#include "vapp_mms_common.h"
#include "vapp_mms_gprot.h"
#include "mdi_include.h"



	

VFX_IMPLEMENT_CLASS("VappMMSLiteViewer", VappMMSLiteViewer, VappMsgViewerCp);




void VappMMSLiteViewer::onInit()
{

	VappMsgViewerCp::onInit(); // call base class    
	//VfxU32 data_size = sizeof(srv_mms_get_lite_view_data_struct);    
    //VFX_ALLOC_MEM(m_th_data, data_size, this);
	//memset(m_th_data, 0, sizeof(srv_mms_get_lite_view_data_struct));
    //VfxS32 result = srv_mms_get_lite_view_data(m_msg_id, m_th_data);
	VfxU32 data_size = sizeof(srv_mms_get_lite_view_data_struct);
	VFX_ALLOC_MEM(m_th_data, data_size, this);
	memset(m_th_data, 0, sizeof(srv_mms_get_lite_view_data_struct));
	data_size = sizeof(srv_mms_sync_msg_info_struct);
	VFX_ALLOC_MEM(m_sync_info, data_size, this);
	memset(m_sync_info, 0, sizeof(srv_mms_sync_msg_info_struct));
    srv_mms_get_lite_viewer_data_req_struct req;
    memset(&req,0, sizeof(srv_mms_get_lite_viewer_data_req_struct));
    req.user_data = (void *)getObjHandle();                 
    req.call_back = VappMMSLiteViewer::dataReadyCb;      
    req.msg_id = m_msg_id;                         
    req.app_id =  MMA_APP_ID_MMS_APP;  
	VfxS32 result = srv_mms_get_lite_viewer_data(&req);
	if(SRV_MMS_RESULT_MAX_SRV_REACHED == result)
	{	
		m_is_reg_free_ev = VFX_TRUE;
		mmi_frm_cb_reg_event(EVT_ID_SRV_MMS_READY_FOR_LITE_VIEWER, VappMMSLiteViewer::serviceFree, getObjHandle());  
	}
	
    if((m_msg_type == MMA_MSG_TYPE_NOTIFICATION) || MMA_FOLDER_OUTBOX == mma_get_box(m_msg_id))
	{
         mmi_frm_cb_reg_event(EVT_ID_SRV_SHOW_BGSR_POPUP, VappMMSLiteViewer::listener, getObjHandle());  
		 mmi_frm_cb_reg_event(EVT_ID_SRV_MMS_UPDATE_STATUS, VappMMSLiteViewer::listener, getObjHandle());  
         m_is_register = VFX_TRUE;
	}

//	vfxPostInvoke0(this, &VappMMSLiteViewer::onMmsContentReady);

}


void VappMMSLiteViewer::onMmsContentReady()
{
     setContentReady(VFX_TRUE);
}

void VappMMSLiteViewer::onDeinit()
{
	VappMsgViewerCp::onDeinit();
	closeCommonObjects();
	if(m_parent_file_handle)
	{
	    FS_Close(m_parent_file_handle);
		m_parent_file_handle = 0;
	}	
    if(m_video_th_memory != NULL)
    {
       VFX_FREE_MEM(m_video_th_memory);
       m_video_th_memory = NULL; 
    }
    if(m_yuv_video_th_memory != NULL)
    {
        VFX_FREE_MEM(m_yuv_video_th_memory);
        m_yuv_video_th_memory = NULL; 
    }
    if(m_file_path)
    {
          VFX_FREE_MEM(m_file_path);
          m_file_path = NULL;
    }
	if(m_th_data)
	{
	
   		 VFX_FREE_MEM(m_th_data);
		 m_th_data = NULL;
	}
	if(m_sync_info)
	{

   		 VFX_FREE_MEM(m_sync_info);
		 m_sync_info = NULL;
	}

	if(VFX_TRUE == m_is_register)
	{
         mmi_frm_cb_dereg_event(EVT_ID_SRV_SHOW_BGSR_POPUP, VappMMSLiteViewer::listener, getObjHandle());  
		 mmi_frm_cb_dereg_event(EVT_ID_SRV_MMS_UPDATE_STATUS, VappMMSLiteViewer::listener, getObjHandle()); 
	}
	if(VFX_TRUE == m_is_reg_free_ev)
	{	
		
		m_is_reg_free_ev = VFX_FALSE;
		mmi_frm_cb_dereg_event(EVT_ID_SRV_MMS_READY_FOR_LITE_VIEWER, VappMMSLiteViewer::serviceFree, getObjHandle());	
	}


}


void VappMMSLiteViewer::onClickResend(VfxObject *obj, VfxId id)
{
    VFX_OBJ_CREATE_EX(m_data, VappMmsViewerData, this, (m_msg_id, VappMmsViewerData::MODE_LIGHT));
    if(m_data->checkMsgInfoDataReady() == VFX_FALSE)
    {
        VappMmsPopup popup(STR_GLOBAL_ERROR, VCP_POPUP_TYPE_SUCCESS, findScreen(), NULL);           
        popup.displayPopup();
        VFX_OBJ_CLOSE(m_data);
        m_data = NULL;
        return ;
    }
    mmi_umms_app_dtmgr_msg_info_data_struct * msg_info = m_data->getMsgInfo();
    srv_mms_send_req_struct req; 
    mmi_sim_enum  sim_id = vapp_mms_convert_mma_sim_to_mmi_sim(msg_info->msg_sim_info);
    if(srv_sim_ctrl_chv1_is_blocked(sim_id))
    {
        mmi_frm_nmgr_balloon(
                            MMI_SCENARIO_ID_MMS_INFO,
                            MMI_EVENT_INFO_BALLOON,
                            MMI_NMGR_BALLOON_TYPE_INFO,
                            (WCHAR*)GetString(STR_GLOBAL_UNAVAILABLE_SIM));
        VFX_OBJ_CLOSE(m_data);
        m_data = NULL;
        return;
    }
    if(!srv_mode_switch_is_network_service_available())
    {
        mmi_frm_nmgr_balloon(
                            MMI_SCENARIO_ID_MMS_INFO,
                            MMI_EVENT_INFO_BALLOON,
                            MMI_NMGR_BALLOON_TYPE_INFO,
                            (WCHAR*)GetString(STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE));
        VFX_OBJ_CLOSE(m_data);
        m_data = NULL;
        return;
    }
    memset(&req, 0, sizeof(srv_mms_send_req_struct));
    req.sim_id = msg_info->msg_sim_info;
    req.send_setting = SRV_MMS_SETTING_SAVE_AND_SEND;       /* SRV_MMS_SETTING_SAVE_AND_SEND;SRV_MMS_SETTING_SEND_ONLY */
    req.msg_id = m_msg_id;
    req.is_rr = (kal_bool)VFX_FALSE;
    req.storage_type = msg_info->storage_location;
    VFX_OBJ_CLOSE(m_data);
    m_data = NULL;
    vapp_mms_send_msg(&req, VappMMSLiteViewer::allocMem, VappMMSLiteViewer::freeMem,this);
    if(srv_mms_bgsr_get_msg_status(m_msg_id) == SRV_MMS_BGSR_STATUS_SENDING)
    {
        m_is_inter_update = VFX_TRUE;
        forceUpdate();
    }
}

void VappMMSLiteViewer::onClickDownload(VfxObject *obj, VfxId id)
{
    VfxU32 current_secs_since_1970 = 0;
    srv_mms_download_req_struct req;
    VFX_OBJ_CREATE_EX(m_data, VappMmsViewerData, this, (m_msg_id, VappMmsViewerData::MODE_LIGHT));
    if(m_data->checkMsgInfoDataReady() == VFX_FALSE)
    {
        VappMmsPopup popup(STR_GLOBAL_ERROR, VCP_POPUP_TYPE_SUCCESS, findScreen(), NULL);           
        popup.displayPopup();
        VFX_OBJ_CLOSE(m_data);
        m_data = NULL;
        return ;
    }

    mmi_umms_app_dtmgr_msg_info_data_struct * msg_info = m_data->getMsgInfo();
    mmi_umms_app_dtmgr_xml_header_info_struct *header_info = m_data->getHeaderInfo();
    mmi_sim_enum  sim_id = vapp_mms_convert_mma_sim_to_mmi_sim(msg_info->msg_sim_info);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
	VfxU8 check_storage = 0;
	if(m_th_data)
	{
		check_storage = srv_mms_check_memory_usage(m_th_data->msg_download_size);
	}
	if(check_storage == SRV_MMS_CARD_NOT_PRESENT_USE_PHONE)
	{
		mmi_frm_nmgr_balloon(
							MMI_SCENARIO_ID_MMS_INFO,
							MMI_EVENT_INFO_BALLOON,
							MMI_NMGR_BALLOON_TYPE_INFO,
							(WCHAR*)GetString(STR_ID_VAPP_MMS_SAVE_TO_PHONE));
		
		srv_mms_set_prefered_storage(E_PREFER_STORAGE_MODE_PHONE,0);
	}
	else if(check_storage == SRV_MMS_CARD_PHONE_FULL_USE_CARD_MEM)
	{
		mmi_frm_nmgr_balloon(
							MMI_SCENARIO_ID_MMS_INFO,
							MMI_EVENT_INFO_BALLOON,
							MMI_NMGR_BALLOON_TYPE_INFO,
							(WCHAR*)GetString(STR_ID_VAPP_MMS_SAVE_TO_MEMORY_CARD));
		
		srv_mms_set_prefered_storage(E_PREFER_STORAGE_MODE_CARD,0);
	
	}
	else if(check_storage == SRV_MMS_CARD_FULL_USE_PHONE_MEM)
	{
		mmi_frm_nmgr_balloon(
							MMI_SCENARIO_ID_MMS_INFO,
							MMI_EVENT_INFO_BALLOON,
							MMI_NMGR_BALLOON_TYPE_INFO,
							(WCHAR*)GetString(STR_ID_VAPP_MMS_SAVE_TO_PHONE));
		
		srv_mms_set_prefered_storage(E_PREFER_STORAGE_MODE_PHONE,0);
	}
	else if(check_storage == SRV_MMS_CARD_NOT_ENOUGH_MEMORY)
	{
		mmi_frm_nmgr_balloon(
							MMI_SCENARIO_ID_MMS_INFO,
							MMI_EVENT_INFO_BALLOON,
							MMI_NMGR_BALLOON_TYPE_INFO,
							(WCHAR*)GetString(STR_ID_VAPP_MMS_MEMORY_CARD_PHONE_BOTH_FULL));
		VFX_OBJ_CLOSE(m_data);
		m_data = NULL;
		return ;
	}
#endif/*__MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__*/
    if(srv_sim_ctrl_chv1_is_blocked(sim_id))
    {
        mmi_frm_nmgr_balloon(
                                MMI_SCENARIO_ID_MMS_INFO,
                                MMI_EVENT_INFO_BALLOON,
                                MMI_NMGR_BALLOON_TYPE_INFO,
                                (WCHAR*)GetString(STR_GLOBAL_UNAVAILABLE_SIM));
        VFX_OBJ_CLOSE(m_data);
        m_data = NULL;
        return;
    }
    if(!srv_mode_switch_is_network_service_available())
    {
        mmi_frm_nmgr_balloon(
                                MMI_SCENARIO_ID_MMS_INFO,
                                MMI_EVENT_INFO_BALLOON,
                                MMI_NMGR_BALLOON_TYPE_INFO,
                                (WCHAR*)GetString(STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE));
        VFX_OBJ_CLOSE(m_data);
        m_data = NULL;
        return;
    }
	
    current_secs_since_1970 = srv_mms_get_current_utc_time();
    if (current_secs_since_1970 > msg_info->expiry_time)
    {

        mmi_frm_nmgr_balloon(
                                MMI_SCENARIO_ID_MMS_INFO,
                                MMI_EVENT_INFO_BALLOON,
                                MMI_NMGR_BALLOON_TYPE_FAILURE,
                                (WCHAR*)GetString(STR_ID_VAPP_MMS_NOTIFICATION_EXPIRED));
        VFX_OBJ_CLOSE(m_data);
        m_data = NULL;
        return;
    }
    memset(&req, 0, sizeof(srv_mms_download_req_struct));
    req.sim_id = msg_info->msg_sim_info;
    req.msg_id = m_msg_id;
    req.storage_type = msg_info->storage_location;
#ifdef __MMI_MMS_ITERATOR_VIEWER__
    //ret_val = mmi_umms_app_core_prepare_data_before_deinit(&other_msg_data, &folder_id, &um_data);
#endif

    srv_mms_download(&req);
    if(srv_mms_bgsr_get_msg_status(m_msg_id) == SRV_MMS_BGSR_STATUS_DOWNLOADING)
    {
        m_is_inter_update = VFX_TRUE;
        forceUpdate();
    }
		

#ifdef __MMI_MMS_ROAMING_NO_ACCEPT_SUPPORT__
    srv_mms_delete_single_msg_from_notify_list(m_msg_id);
#endif /*__MMI_MMS_ROAMING_NO_ACCEPT_SUPPORT__*/
	VFX_OBJ_CLOSE(m_data);
	m_data = NULL;
}

mmi_ret VappMMSLiteViewer::serviceFree(mmi_event_struct* evt)
{
    srv_mms_base_event_struct* param =	(srv_mms_base_event_struct*) evt;
    VappMMSLiteViewer* lite_view = (VappMMSLiteViewer *)handleToObject((VfxObjHandle)param->user_data);
    if(lite_view && lite_view->isKindOf(VFX_OBJ_CLASS_INFO(VappMMSLiteViewer)))
    {
        srv_mms_get_lite_viewer_data_req_struct req;
        memset(&req,0, sizeof(srv_mms_get_lite_viewer_data_req_struct));
        req.user_data = (void *)lite_view->getObjHandle();                 
        req.call_back = VappMMSLiteViewer::dataReadyCb;      
        req.msg_id = lite_view->m_msg_id;                         
        req.app_id =  MMA_APP_ID_MMS_APP;  
        VfxS32 result = srv_mms_get_lite_viewer_data(&req);
        if(SRV_MMS_RESULT_INSUFFICIENT_MEMORY == result)
        {
            ASSERT(0); 
        }
        else if(SRV_MMS_RESULT_MAX_SRV_REACHED != result)
        {	
            lite_view->m_is_reg_free_ev = VFX_FALSE;
            mmi_frm_cb_dereg_event(EVT_ID_SRV_MMS_READY_FOR_LITE_VIEWER, VappMMSLiteViewer::serviceFree, lite_view->getObjHandle());	
        }
    }

    return MMI_RET_OK;

}

void VappMMSLiteViewer::dataReadyCb(srv_mms_result_enum result, void *rsp_data, void* user_data)
{
	
    VappMMSLiteViewer* lite_view = (VappMMSLiteViewer *)handleToObject((VfxObjHandle)user_data);
	if(lite_view && lite_view->isKindOf(VFX_OBJ_CLASS_INFO(VappMMSLiteViewer)))
	{
		srv_mms_get_lite_viewer_data_rsp_struct *rsp = (srv_mms_get_lite_viewer_data_rsp_struct *)rsp_data;
		if(rsp != NULL)
		{
			if(rsp->result == MMA_RESULT_OK)
			{

				memcpy(lite_view->m_th_data,&rsp->thumbnail_info,sizeof(srv_mms_get_lite_view_data_struct));
				lite_view->m_sync_info->msg_id = rsp->msg_id;
				lite_view->m_sync_info->msg_info.timestamp = rsp->timestamp;
				lite_view->m_sync_info->msg_info.msg_size = rsp->msg_size;
				lite_view->m_sync_info->msg_info.msg_type = rsp->msg_type;
				lite_view->m_sync_info->msg_info.msg_storage = rsp->storage_type;
				lite_view->m_sync_info->msg_info.msg_sim_id = rsp->msg_sim_id;

			}
			lite_view->m_sync_info->result = rsp->result;
			lite_view->m_is_read = VFX_TRUE;

			lite_view->m_is_inter_update = VFX_TRUE;
			lite_view->forceUpdate();
			vfxPostInvoke0(lite_view, &VappMMSLiteViewer::onMmsContentReady);
		}
	}

}

mmi_ret VappMMSLiteViewer::listener(mmi_event_struct* evt)
{
    srv_mms_base_event_struct* param =  (srv_mms_base_event_struct*) evt;
    VappMMSLiteViewer* lite_view =  (VappMMSLiteViewer*)VfxObject::handleToObject((param->user_data));
    if(lite_view &&  lite_view->isKindOf(VFX_OBJ_CLASS_INFO(VappMMSLiteViewer)))
    {
        switch (param->evt_id)
        {
            case EVT_ID_SRV_SHOW_BGSR_POPUP:
            {
                srv_mms_bgsr_popup_data * sender_data =  (srv_mms_bgsr_popup_data*)  param->sender_data;
                if(lite_view->m_msg_id == sender_data->msg_id)
                {
                    if(lite_view->m_button)
                    {
                    lite_view->m_button->setIsDisabled(VFX_FALSE);
                    }
                    if((lite_view->m_msg_type == MMA_MSG_TYPE_MMS) || (sender_data->new_msg_id == 0))
                    {
                    lite_view->m_is_inter_update = VFX_TRUE;
                    lite_view->forceUpdate();
                    }
                    /*if(sender_data->new_msg_id)
                                    {
                                    VFX_OBJ_CLOSE(lite_view->m_data);
                                    }*/
                }
            }
            break;
            case EVT_ID_SRV_MMS_UPDATE_STATUS:
            {
                srv_mms_update_status_struct * sender_data =  (srv_mms_update_status_struct*)  param->sender_data;
                if(lite_view->m_msg_id == sender_data->msg_id)
                {   
                    lite_view->m_is_inter_update = VFX_TRUE;
                    lite_view->forceUpdate();
                }
            }
            break;
        }
    }
    return MMI_RET_OK;
}


VfxU32 VappMMSLiteViewer::getTimestamp(void)
{

	return m_sync_info->msg_info.timestamp;
}


VfxBool VappMMSLiteViewer::isMsgInValid(void)
{
	return m_is_msg_invalid;
}

void VappMMSLiteViewer::closeCommonObjects(void)
{
	if(m_s_frame != NULL)
	{
	    VFX_OBJ_CLOSE(m_s_frame);
			m_s_frame = NULL;
	}
	if(m_indicator != NULL)
	{
	    VFX_OBJ_CLOSE(m_indicator);
			m_indicator = NULL;
	}
	if(m_txt_subject != NULL)
	{
	    VFX_OBJ_CLOSE(m_txt_subject);
			m_txt_subject = NULL;
	}
	if(m_txt_size != NULL)
	{
	    VFX_OBJ_CLOSE(m_txt_size);
			m_txt_size = NULL;
	}
	if(m_button != NULL)
	{
	    VFX_OBJ_CLOSE(m_button);
			m_button = NULL;
	}
	/*if(m_parent_file_handle)
	{
	   FS_Close(m_parent_file_handle);
	   m_parent_file_handle=0;
	}*/
	
   if(m_frame != NULL)
	{
	    VFX_OBJ_CLOSE(m_frame);
		m_frame = NULL;
	}
   /*if(m_video_th_memory != NULL)
   {
       VFX_FREE_MEM(m_video_th_memory);
       m_video_th_memory = NULL; 
   }*/
}
void VappMMSLiteViewer::forceUpdate(void)
{
    
	VfxSize size;
	VfxSize txt_size;
	VfxS32 temp_width; 
	VfxU32 obj_offset = 0;
	VfxU32 obj_size = 0;
	obj_type_enum obj_type ;
	VfxU32 total_width = 0;
	VfxU8 ntt = 0;
	VfxU8 quota = 0;
	srv_mms_bgsr_msg_info_struct bgsr_msg_info;
	//setInternalSize(m_outer_size.width, VAPP_MMS_THUMBNAIL_SIZE);
	//size  = getSize();
	if(m_is_read == VFX_FALSE)
	{
		setInternalSize(0,0);
		return;
	}
	//size  = getSize();
	if(m_is_inter_update == VFX_FALSE && m_old_outer_size == m_outer_size)
    {
        setInternalSize(m_liteview_size.width,m_liteview_size.height);
        return;
    } 
    
	closeCommonObjects();
    size.width = m_outer_size.width;
    size.height = VAPP_MMS_THUMBNAIL_SIZE;
	VFX_OBJ_CREATE(m_frame, VfxFrame, this);
	m_frame->setPos(0,0);
	m_frame->setSize(size.width,size.height);      
	if(m_sync_info->result != MMA_RESULT_OK)
	{
		VfxWString txt;
		txt.loadFromRes(STR_ID_VAPP_MMS_CORRUPTED_MESSAGE);
		if(!( m_sync_info->result == MMA_RESULT_FAIL_FILE_CORRUPTED
		|| m_sync_info->result == MMA_RESULT_FAIL_UNSUPPORT_MMS_TYPE))
		{
			txt.loadFromRes(STR_GLOBAL_ERROR);
			m_is_msg_invalid = VFX_FALSE;
		}
		else
		{
			m_is_msg_invalid = VFX_TRUE;
		}

		VFX_OBJ_CREATE(m_txt_subject, VfxTextFrame, this);
		txt_size = setTextData(m_txt_subject,
								txt,
								VFX_TRUE,
								VFX_FALSE,
								VAPP_MMS_SUBJECT_FONT_SIZE,
								VFX_COLOR_RES(VAPP_MMS_LITEVIEW_TEXT_COLOR),
								VfxTextFrame::ALIGN_MODE_LEFT, 
								VfxSize(0,0),
								VfxPoint(0, VAPP_MMS_SUBJECT_SINGLE_LINE_UPPER_MARGIN));
		 if(txt_size.width > size.width)
		 {
			 m_txt_subject->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
		 }
	     m_txt_subject->setSize(VfxSize(size.width, VAPP_MMS_SUBJECT_FONT_SIZE));
		 m_txt_subject->forceUpdate();
	     return;
	}
	else
	{
		m_is_msg_invalid = VFX_FALSE;
	}	
	
	m_msg_type = m_sync_info->msg_info.msg_type ;
	obj_offset = m_th_data->body_offset;
	obj_size = m_th_data->body_size ;
    
	switch(m_th_data->body_type)
	{
		case MMA_MEDIA_MSG_PHOTO:
			obj_type = OBJ_TYPE_IMAGE;
		break;
		case MMA_MEDIA_MSG_VIDEO:
			obj_type = OBJ_TYPE_VIDEO;
		break;
		default:
			obj_type = OBJ_TYPE_NONE;
		break;
	}  
	VfxU8 status =  srv_mms_bgsr_update_msg_status_info(m_msg_id, &ntt, &quota);
	memset(&bgsr_msg_info, 0, sizeof(srv_mms_bgsr_msg_info_struct));
	srv_mms_bgsr_get_msg_info(
								m_msg_id,
								&bgsr_msg_info,
								NULL,
								m_sync_info->msg_info.msg_storage,
								(mma_msg_type_enum)m_sync_info->msg_info.msg_type);
    	    
	if((MMA_MSG_TYPE_MMS  == m_msg_type) || (MMA_MSG_TYPE_JAVA == m_msg_type))
	{
		VfxU8 msg_file_path[(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH];
		VfxU8 msg_path[(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH];
		if(m_parent_file_handle == 0)
		{
			memset(msg_path, 0, (MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);
			memset(msg_file_path, 0, (MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);            
			mma_get_home_directory(
			(kal_wchar*) msg_path,
			MMA_MAX_INTERNAL_FILENAME_LENGTH,
			m_sync_info->msg_info.msg_storage);
			mma_get_msg_file_name(m_msg_id, (kal_wchar*) msg_file_path, MMA_MAX_INTERNAL_FILENAME_LENGTH);
			mmi_ucs2cat((S8*) msg_path, (S8*) "\\");
			mmi_ucs2cat((S8*) msg_path, (S8*) msg_file_path);
		}  	
		if(MMA_MSG_TYPE_JAVA != m_msg_type)
		{        
			VFX_OBJ_CREATE(m_s_frame, VcpPhotoBorderFrame, m_frame);
			total_width +=  VAPP_MMS_LITE_VIEWER_INNER_LEFT_MARGIN;
			VfxPoint th_point(total_width, VAPP_MMS_THUMBNAIL_UPPER_MARGIN);
			VfxSize th_size(VAPP_MMS_THUMBNAIL_SIZE, VAPP_MMS_THUMBNAIL_SIZE);
			m_s_frame->setPos(th_point);
			m_s_frame->setSize(th_size);			   
            #ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
			if(obj_type == OBJ_TYPE_VIDEO)
			{
				VfxBool draw_video_image = VFX_FALSE;
				draw_video_image = openFile((const WCHAR *)msg_path,obj_offset,obj_size);
				if(draw_video_image == VFX_TRUE)
				{
				
                #ifdef __MDI_DISPLAY_YUYV422_SUPPORT__  
					if(m_yuv_video_th_memory != NULL)
                #else             
					if(m_video_th_memory != NULL)
                #endif/*__MDI_DISPLAY_YUYV422_SUPPORT__*/
					{
						VfxImageBuffer imageBuf;
                    #ifdef __MDI_DISPLAY_YUYV422_SUPPORT__                  
                        imageBuf.ptr = (VfxU8*)m_yuv_video_th_memory;
                    #else
						imageBuf.ptr = (VfxU8*)m_video_th_memory;
                    #endif/*__MDI_DISPLAY_YUYV422_SUPPORT__*/
						imageBuf.pitchBytes = VAPP_MMS_THUMBNAIL_IMAGE_SIZE * 2;
						imageBuf.width = VAPP_MMS_THUMBNAIL_IMAGE_SIZE;
						imageBuf.height = VAPP_MMS_THUMBNAIL_IMAGE_SIZE;
						imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
						m_s_frame->setImgContent(VfxImageSrc(imageBuf));

					}
					else
					{
					#ifdef __MMI_VIDEO_PLAY_SUPPORT__
						mdi_video_info_struct *info;
						VFX_ALLOC_MEM(info, sizeof(mdi_video_info_struct), this);          
						mmi_id app_id = VfxMainScr::findMainScr((VfxFrame *)getParent())->getApp()->getGroupId();
						//mmi_ucs2cat((PS8) m_file_path, (PS8) ".");
						//mmi_ucs2ncat((PS8) m_file_path, (const CHAR *)temp_str, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
						mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_CIF);
						MDI_RESULT result = mdi_video_ply_open_clip_file((const U16) app_id, (const S8 *)m_file_path, info);
						//COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_LITE_VIDEO_RESULT, result, 1);							     
						if(MDI_RES_VDOPLY_SUCCEED == result)
						{ 
							gdi_handle image_layer_handle;
							VfxS32 outside_memory_size = VAPP_MMS_THUMBNAIL_IMAGE_SIZE*VAPP_MMS_THUMBNAIL_IMAGE_SIZE*2;
							VFX_ALLOC_MEM_EX(m_video_th_memory, outside_memory_size,VFX_SYS_MEM_ALLOC_FLAG_FB, this);
							vfx_sys_mem_zero(m_video_th_memory, outside_memory_size);                                                          
                        #ifdef __MDI_DISPLAY_YUYV422_SUPPORT__  
							GDI_RESULT gdi_result = gdi_layer_create_cf_using_outside_memory(GDI_COLOR_FORMAT_UYVY422,0,0,VAPP_MMS_THUMBNAIL_IMAGE_SIZE,VAPP_MMS_THUMBNAIL_IMAGE_SIZE,&image_layer_handle,m_video_th_memory,outside_memory_size);
                        #else
							GDI_RESULT gdi_result = gdi_layer_create_using_outside_memory(0,0,VAPP_MMS_THUMBNAIL_IMAGE_SIZE,VAPP_MMS_THUMBNAIL_IMAGE_SIZE,&image_layer_handle,m_video_th_memory,outside_memory_size);
                        #endif	/*__MDI_DISPLAY_YUYV422_SUPPORT__*/						
							if(GDI_SUCCEED == gdi_result)
							{
								MDI_RESULT result2 = mdi_video_ply_seek_and_get_frame(0, image_layer_handle);
								//COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_LITE_VIDEO_RESULT, result, 3);
								if(MDI_RES_VDOPLY_SUCCEED == result2)
								{
								    
                                #ifdef __MDI_DISPLAY_YUYV422_SUPPORT__    
								    gdi_handle temp_layer_handle;
									VFX_ALLOC_MEM_EX(m_yuv_video_th_memory, outside_memory_size,VFX_SYS_MEM_ALLOC_FLAG_FB, this);
									vfx_sys_mem_zero(m_yuv_video_th_memory, outside_memory_size);														   
									gdi_layer_create_cf_using_outside_memory(GDI_COLOR_FORMAT_16,0,0,VAPP_MMS_THUMBNAIL_IMAGE_SIZE,VAPP_MMS_THUMBNAIL_IMAGE_SIZE,&temp_layer_handle,m_yuv_video_th_memory,outside_memory_size);
									gdi_layer_push_and_set_active(temp_layer_handle);
									gdi_layer_flatten(image_layer_handle,0,0,0);
									gdi_layer_pop_and_restore_active();
									gdi_layer_free(temp_layer_handle);
                                #endif/*__MDI_DISPLAY_YUYV422_SUPPORT__*/
									VfxImageBuffer imageBuf;
                                #ifdef __MDI_DISPLAY_YUYV422_SUPPORT__   
									imageBuf.ptr = (VfxU8*)m_yuv_video_th_memory;
                                #else
									imageBuf.ptr = (VfxU8*)m_video_th_memory;
                                #endif/*__MDI_DISPLAY_YUYV422_SUPPORT__*/
									imageBuf.pitchBytes = VAPP_MMS_THUMBNAIL_IMAGE_SIZE * 2;
									imageBuf.width = VAPP_MMS_THUMBNAIL_IMAGE_SIZE;
									imageBuf.height = VAPP_MMS_THUMBNAIL_IMAGE_SIZE;
									imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
									m_s_frame->setImgContent(VfxImageSrc(imageBuf));
                                #ifdef __MDI_DISPLAY_YUYV422_SUPPORT__     
                                    VFX_FREE_MEM(m_video_th_memory);
									m_video_th_memory = NULL;
                                #endif/*__MDI_DISPLAY_YUYV422_SUPPORT__*/                                    
								}
								else
								{
									m_s_frame->setImgContent(VfxImageSrc(IMG_ID_VENUS_MMS_VIDEO_OVERLAY));
									draw_video_image = VFX_FALSE;
									VFX_FREE_MEM(m_video_th_memory);
									m_video_th_memory = NULL;
								}
								gdi_layer_free(image_layer_handle);
							}
							else
							{
								m_s_frame->setImgContent(VfxImageSrc(IMG_ID_VENUS_MMS_VIDEO_OVERLAY));
								draw_video_image = VFX_FALSE;
								VFX_FREE_MEM(m_video_th_memory);
								m_video_th_memory = NULL;
							}
							result = mdi_video_ply_close_clip_file();
							//COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_LITE_VIDEO_RESULT, result, 4);
						}
						else
                    #endif/*__MDI_DISPLAY_YUYV422_SUPPORT__*/
						{
							m_s_frame->setImgContent(VfxImageSrc(IMG_ID_VENUS_MMS_VIDEO_OVERLAY));
							draw_video_image = VFX_FALSE;
						}
                    #ifdef __MMI_VIDEO_PLAY_SUPPORT__
						VFX_FREE_MEM(info);
                    #endif/*__MMI_VIDEO_PLAY_SUPPORT__*/
					}
				}
				m_s_frame->setPlacement(VCP_PHOTO_BORDER_FRAME_PLACEMENT_FIT_EXACT_SIZE); 
				m_s_frame->setMaxSize(VfxSize(VAPP_MMS_THUMBNAIL_SIZE,VAPP_MMS_THUMBNAIL_SIZE));
				m_s_frame->setImageContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
				m_s_frame->forceUpdate();
				total_width += VAPP_MMS_THUMBNAIL_SIZE; 
				if(draw_video_image)
				{
					VfxImageFrame *overlay_img;
					VFX_OBJ_CREATE(overlay_img, VfxImageFrame, m_s_frame);
					overlay_img->setPos(VfxPoint((VAPP_MMS_THUMBNAIL_SIZE - VAPP_MMS_THUMBNAIL_IMAGE_SIZE),(VAPP_MMS_THUMBNAIL_SIZE - VAPP_MMS_THUMBNAIL_IMAGE_SIZE)));
					overlay_img->setSize(VfxSize(VAPP_MMS_THUMBNAIL_IMAGE_SIZE,VAPP_MMS_THUMBNAIL_IMAGE_SIZE));
					overlay_img->setImgContent(VfxImageSrc(IMG_ID_VENUS_MMS_VIDEO_OVERLAY));
					overlay_img->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL); 
				}
			}
			else 
          #endif      
			{  
			  if(obj_type == OBJ_TYPE_IMAGE)//if(image on first slide)
			  {
					VfxBool draw_result = VFX_FALSE;   
					draw_result = openFile((const WCHAR *)msg_path,obj_offset,obj_size);
					if(draw_result == VFX_TRUE)
					{
						VfxWString str;
						str.loadFromMem(m_file_path);
						m_s_frame->setImgContent(VfxImageSrc(str));
					}
				}
				else
				{
					m_s_frame->setImgContent(VfxImageSrc(IMG_ID_VENUS_MMS_NORMAL_PRIORITY));
				}
				m_s_frame->setPlacement(VCP_PHOTO_BORDER_FRAME_PLACEMENT_FIT_EXACT_SIZE); 
				m_s_frame->setMaxSize(VfxSize(VAPP_MMS_THUMBNAIL_SIZE,VAPP_MMS_THUMBNAIL_SIZE));
				m_s_frame->setImageContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);

				m_s_frame->forceUpdate();
				total_width += VAPP_MMS_THUMBNAIL_SIZE; 
			}
	    }
		       
		VfxWString str;
		VFX_OBJ_CREATE(m_txt_subject, VfxTextFrame, m_frame);
		if(MMA_MSG_TYPE_JAVA == m_msg_type)
		{
			total_width += VAPP_MMS_NOTIFICATION_SUBJECT_LEFT_MARGIN;
		}
		else
		{
			total_width += VAPP_MMS_THUMBNAIL_RIGHT_MARGIN;
		}

		if(m_th_data->subject[0]=='\0')
		{
			str.loadFromRes(STR_ID_VAPP_MMS_NO_SUBJECT);
		}
		else
		{
			VfxWString str_temp;
			str_temp.loadFromMem(m_th_data->subject);
			str.loadFromRes(STR_ID_VAPP_MMS_SUBJECT);
			str += str_temp;
		}
		txt_size = setTextData(m_txt_subject,
								str,
								VFX_TRUE,
								VFX_FALSE,
								VAPP_MMS_SUBJECT_FONT_SIZE,
								VFX_COLOR_RES(VAPP_MMS_LITEVIEW_TEXT_COLOR),
								VfxTextFrame::ALIGN_MODE_LEFT, 
								VfxSize(0,0),
								VfxPoint(total_width, VAPP_MMS_SUBJECT_UPPER_MARGIN));
						if(MMA_FOLDER_OUTBOX == mma_get_box(m_msg_id) 
                    && ((status == SRV_MMS_BGSR_STATUS_SENDING && SRV_MMS_BGSR_RESULT_NOT_USED == bgsr_msg_info.result) || 
                    ((SRV_MMS_BGSR_RESULT_NOT_USED != bgsr_msg_info.result) && (SRV_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND != bgsr_msg_info.result) )))
		{
			temp_width = size.width - total_width - VAPP_MMS_BUTTON_LEFT_MARGIN - VAPP_MMS_BUTTON_WIDTH - VAPP_MMS_BUTTON_RIGHT_MARGIN;
		}
		else
		{
			temp_width = size.width - total_width - VAPP_MMS_BUTTON_RIGHT_MARGIN;
		}
			                    
		if(txt_size.width > temp_width)
		{
			m_txt_subject->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
		}
		m_txt_subject->setSize(VfxSize(temp_width, VAPP_MMS_SUBJECT_FONT_SIZE));
		//m_txt_subject->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
		// m_txt_subject->setColor( VfxColor(0, VAPP_MMS_SUBJECT_FONT_COLOR_R, VAPP_MMS_SUBJECT_FONT_COLOR_G, VAPP_MMS_SUBJECT_FONT_COLOR_B));  
		m_txt_subject->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
		m_txt_subject->setMaxLines(2 );   
		m_txt_subject->forceUpdate();
		if ((m_txt_subject->getLineCount() < 2) || (MMA_FOLDER_OUTBOX == mma_get_box(m_msg_id)) || (MMA_MSG_TYPE_MMS != m_msg_type))
		{
			m_txt_subject->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
		}
		else
		{
			m_txt_subject->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
		}
		if ((m_txt_subject->getLineCount() < 2) && (MMA_FOLDER_OUTBOX != mma_get_box(m_msg_id)) && (MMA_MSG_TYPE_JAVA != m_msg_type))
		{
			m_txt_subject->setPos(VfxPoint(total_width, VAPP_MMS_SUBJECT_SINGLE_LINE_UPPER_MARGIN));
		}
		m_txt_subject->forceUpdate();              
		if((MMA_FOLDER_OUTBOX == mma_get_box(m_msg_id))||(MMA_MSG_TYPE_JAVA == m_msg_type))
		{
			VFX_OBJ_CREATE(m_txt_size, VfxTextFrame, m_frame);               
			VfxWString str11;
			VfxWString str4;
			char str5[10];
			VfxWString str6;			
			memset(str5,0,10);
			str4.loadFromRes(STR_ID_VAPP_MMS_SIZE);
			if(m_sync_info->msg_info.msg_size >= 1024)
			{
				sprintf(str5,"%d",m_sync_info->msg_info.msg_size/1024);
			}
			else
			{
				sprintf(str5,"%d",m_sync_info->msg_info.msg_size);
			}     
			str11.format("%s", str5);
			str4 += str11;
			if(m_sync_info->msg_info.msg_size >= 1024)
			{
				str6.loadFromRes(STR_ID_VAPP_MMS_KB);
			}
			else
			{
				str6.loadFromRes(STR_ID_VAPP_MMS_BYTES);
			}
			str4 += VFX_WSTR(" ");
			str4 += str6;
			txt_size = setTextData(m_txt_size,
									str4,
									VFX_TRUE,
									VFX_FALSE,
									VAPP_MMS_SIZE_FONT_SIZE,
									VFX_COLOR_RES(VAPP_MMS_LITEVIEW_SUB_TEXT_COLOR),
									VfxTextFrame::ALIGN_MODE_LEFT, 
									VfxSize(temp_width,VAPP_MMS_SIZE_FONT_SIZE),
									VfxPoint(m_txt_subject->getPos().x, m_txt_subject->getPos().y + VAPP_MMS_SUBJECT_FONT_SIZE + VAPP_MMS_TEXT_MARGIN));
                    
			if(txt_size.width > temp_width)
			{
				m_txt_size->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
			}			                           
			m_txt_size->forceUpdate();
		}
               
		if((MMA_FOLDER_OUTBOX == mma_get_box(m_msg_id))||(MMA_MSG_TYPE_JAVA == m_msg_type))
		{
			if(m_txt_size->getSize().width > m_txt_subject->getSize().width)
			{
				total_width += m_txt_size->getSize().width;
			}
			else
			{
				total_width += m_txt_subject->getSize().width;
			}
		}
		else
		{
			total_width += m_txt_subject->getSize().width;
		}
		if(MMA_FOLDER_OUTBOX == mma_get_box(m_msg_id))
		{
			if(status == SRV_MMS_BGSR_STATUS_SENDING)
			{
				VFX_OBJ_CREATE(m_indicator, VcpActivityIndicator, m_frame);
				total_width +=  VAPP_MMS_BUTTON_LEFT_MARGIN;
				m_indicator->setPos(VfxPoint(total_width,VAPP_MMS_STATUS_ICON_UPPER_MARGIN));
				m_indicator->setSize(VAPP_MMS_STATUS_ICON_SIZE,VAPP_MMS_STATUS_ICON_SIZE);
				total_width +=  VAPP_MMS_STATUS_ICON_SIZE;
				m_indicator->start();
			}
			else if((SRV_MMS_BGSR_RESULT_NOT_USED != bgsr_msg_info.result) && (SRV_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND != bgsr_msg_info.result) )
			{
				total_width += VAPP_MMS_BUTTON_LEFT_MARGIN;
				VFX_OBJ_CREATE(m_button, VcpImageButton, m_frame);
				m_button->setPos(VfxPoint(total_width, VAPP_MMS_BUTTON_UPPER_MARGIN));
				m_button->setSize(VAPP_MMS_BUTTON_WIDTH, VAPP_MMS_BUTTON_HEIGHT);
				m_button->setId(IMG_ID_VENUS_MMS_DIALOG_RESEND);
				m_button->setImage(VcpStateImage(
						IMG_ID_VENUS_MMS_DIALOG_RESEND,
						IMG_ID_VENUS_MMS_DIALOG_RESEND,
						IMG_ID_VENUS_MMS_DIALOG_RESEND,
						IMG_ID_VENUS_MMS_DIALOG_RESEND));
				if(!srv_sim_ctrl_is_available((mmi_sim_enum)m_sync_info->msg_info.msg_sim_id) || (SRV_MODE_SWITCH_OFF == srv_mode_switch_get_network_mode((mmi_sim_enum)m_sync_info->msg_info.msg_sim_id)))
				{
					m_button->setIsDisabled(VFX_TRUE);
					m_button->setOpacity(0.30f);
				}
				m_button->m_signalClicked.connect(this, &VappMMSLiteViewer::onClickResend);
				total_width += VAPP_MMS_BUTTON_WIDTH;
			}

		}
		total_width += VAPP_MMS_BUTTON_RIGHT_MARGIN;					
	  }
      else if(m_msg_type == MMA_MSG_TYPE_NOTIFICATION)
	  {       
		total_width +=  VAPP_MMS_LITE_VIEWER_INNER_LEFT_MARGIN;		    
		VFX_OBJ_CREATE(m_txt_subject, VfxTextFrame, this);
        m_txt_subject->setPos(VfxPoint(total_width, VAPP_MMS_SUBJECT_UPPER_MARGIN));
		VfxWString str;
		VfxWString str2;
		str2.loadFromMem(m_th_data->subject);
		str.loadFromRes(STR_ID_VAPP_MMS_SUBJECT);
		str += str2;               
		txt_size = setTextData(m_txt_subject,
								str,
								VFX_TRUE,
								VFX_FALSE,
								VAPP_MMS_SUBJECT_FONT_SIZE,
								VFX_COLOR_RES(VAPP_MMS_LITEVIEW_TEXT_COLOR),
								VfxTextFrame::ALIGN_MODE_LEFT, 
								VfxSize(0,0),
								VfxPoint(total_width, VAPP_MMS_SUBJECT_UPPER_MARGIN));
		        
        temp_width = size.width - total_width - VAPP_MMS_BUTTON_WIDTH - VAPP_MMS_BUTTON_LEFT_MARGIN - VAPP_MMS_BUTTON_RIGHT_MARGIN;
		if(txt_size.width > temp_width)
		{
			m_txt_subject->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
		}
		m_txt_subject->setSize(VfxSize(temp_width, VAPP_MMS_SUBJECT_FONT_SIZE));
		m_txt_subject->forceUpdate();				
		VfxWString str3;
		VfxWString str4;
		char str5[10];
		VfxWString str6;
		VFX_OBJ_CREATE(m_txt_size, VfxTextFrame, this);   
        str3.loadFromRes(STR_ID_VAPP_MMS_SIZE);
		memset(str5,0,10);
		//itoa(m_th_data->msg_download_size,str5,10);
		if(m_th_data->msg_download_size >= 1024)
		{
			sprintf(str5,"%d",m_th_data->msg_download_size/1024);
		}
		else
		{
			sprintf(str5,"%d",m_th_data->msg_download_size);
		}
		str4.format("%s", str5);
		str3 += str4;
		if(m_th_data->msg_download_size >= 1024)
		{
			str6.loadFromRes(STR_ID_VAPP_MMS_KB);
		}
		else
		{
			str6.loadFromRes(STR_ID_VAPP_MMS_BYTES);
		}
		str3 += VFX_WSTR(" ");
		str3 += str6;             
		txt_size = setTextData(m_txt_size,
								str3,
								VFX_TRUE,
								VFX_FALSE,
								VAPP_MMS_SIZE_FONT_SIZE,
								VFX_COLOR_RES(VAPP_MMS_LITEVIEW_SUB_TEXT_COLOR),
								VfxTextFrame::ALIGN_MODE_LEFT, 
								VfxSize(temp_width, VAPP_MMS_SIZE_FONT_SIZE),
								VfxPoint(total_width, VAPP_MMS_SUBJECT_UPPER_MARGIN + VAPP_MMS_TEXT_MARGIN + VAPP_MMS_SUBJECT_FONT_SIZE));
		if(txt_size.width > temp_width)
		{
			m_txt_size->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
		}
		m_txt_size->forceUpdate();
		if(m_txt_size->getSize().width > m_txt_subject->getSize().width)
		{
			total_width += m_txt_size->getSize().width;
		}
		else
		{
			total_width += m_txt_subject->getSize().width;
		}
		if(status == SRV_MMS_BGSR_STATUS_DOWNLOADING)
		{
			VFX_OBJ_CREATE(m_indicator, VcpActivityIndicator, m_frame);
			total_width += VAPP_MMS_BUTTON_LEFT_MARGIN;
			m_indicator->setPos(VfxPoint(total_width,VAPP_MMS_STATUS_ICON_UPPER_MARGIN));

			m_indicator->setSize(VAPP_MMS_STATUS_ICON_SIZE,VAPP_MMS_STATUS_ICON_SIZE);
			total_width +=  VAPP_MMS_STATUS_ICON_SIZE;
			m_indicator->start();
		}
		else 
		{
			total_width += VAPP_MMS_BUTTON_LEFT_MARGIN;
			VFX_OBJ_CREATE(m_button, VcpImageButton, m_frame);
			m_button->setPos(VfxPoint(total_width, VAPP_MMS_BUTTON_UPPER_MARGIN));
			m_button->setSize(VAPP_MMS_BUTTON_WIDTH, VAPP_MMS_BUTTON_HEIGHT);
			m_button->setId(IMG_ID_VENUS_MMS_DOWNLOAD);
			m_button->setImage(VcpStateImage(
												IMG_ID_VENUS_MMS_DOWNLOAD,
												IMG_ID_VENUS_MMS_DOWNLOAD,
												IMG_ID_VENUS_MMS_DOWNLOAD,
												IMG_ID_VENUS_MMS_DOWNLOAD));
			if(/*!(srv_sim_ctrl_is_inserted((mmi_sim_enum)sync_info->msg_info.msg_sim_id))*/!srv_sim_ctrl_is_available((mmi_sim_enum)m_sync_info->msg_info.msg_sim_id) || (SRV_MODE_SWITCH_OFF == srv_mode_switch_get_network_mode((mmi_sim_enum)m_sync_info->msg_info.msg_sim_id)))
			{
				m_button->setIsDisabled(VFX_TRUE);
				m_button->setOpacity(0.30f);
			}
			m_button->m_signalClicked.connect(this, &VappMMSLiteViewer::onClickDownload);
			total_width += VAPP_MMS_BUTTON_WIDTH;
		} 					
		total_width += VAPP_MMS_BUTTON_RIGHT_MARGIN;
	}
    else if(m_msg_type == MMA_MSG_TYPE_DELIVERY_REPORT)
    {
		total_width +=  VAPP_MMS_LITE_VIEWER_INNER_LEFT_MARGIN;		    
		VFX_OBJ_CREATE(m_txt_subject, VfxTextFrame, this);
        m_txt_subject->setPos(VfxPoint(total_width, VAPP_MMS_SUBJECT_UPPER_MARGIN));
		VfxWString str;
		VfxWString str2;
		str2.loadFromMem(m_th_data->subject);
		str.loadFromRes(STR_ID_VAPP_MMS_SUBJECT);
		str += str2;  
		txt_size = setTextData(m_txt_subject,
								str,
								VFX_TRUE,
								VFX_FALSE,
								VAPP_MMS_SUBJECT_FONT_SIZE,
								VFX_COLOR_RES(VAPP_MMS_LITEVIEW_TEXT_COLOR),
								VfxTextFrame::ALIGN_MODE_LEFT, 
								VfxSize(0,0),
								VfxPoint(total_width, VAPP_MMS_SUBJECT_UPPER_MARGIN));

        if(txt_size.width > size.width)
        {
        m_txt_subject->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        }
        m_txt_subject->setSize(VfxSize(size.width, VAPP_MMS_SUBJECT_FONT_SIZE));
        total_width += m_txt_subject->getSize().width;
        m_txt_subject->forceUpdate();
    }

 	setInternalSize(total_width,VAPP_MMS_THUMBNAIL_SIZE);
    m_old_outer_size = m_outer_size;
    m_liteview_size.width = total_width;
    m_liteview_size.height = VAPP_MMS_THUMBNAIL_SIZE;
	m_is_inter_update = VFX_FALSE;
     // VFX_FREE_MEM(m_th_data);

}

void VappMMSLiteViewer::setSize(VfxS32 w, VfxS32 h)
{
    VappMsgViewerCp::setSize(w,h);
    forceUpdate();
}

void VappMMSLiteViewer::setInternalSize(VfxS32 w, VfxS32 h)
{
	m_is_set_outer_size = VFX_FALSE;
	VappMsgViewerCp::setSize(w,h);
}

void VappMMSLiteViewer::setBounds(const VfxRect &value)
{
	if (m_is_set_outer_size)
	{
		m_outer_size = value.size;
	}
	else
	{
		m_is_set_outer_size = VFX_TRUE;
	}

	VappMsgViewerCp::setBounds(value);
}

void * VappMMSLiteViewer::allocMem(U32 size, void *user_data)
{
	void *mem = NULL;
	VappMMSLiteViewer *my_data = (VappMMSLiteViewer *)user_data;
	if(my_data->isValid() && my_data->isKindOf(VFX_OBJ_CLASS_INFO(VappMMSLiteViewer)) )
	{
		VFX_ALLOC_MEM(mem, size, my_data);
	}
	return mem;
}

void  VappMMSLiteViewer::freeMem(void *mem)
{
	VFX_FREE_MEM(mem);
}

void  VappMMSLiteViewer::setMsgId(VfxU32 msgId)
{

}

VfxBool  VappMMSLiteViewer::openFile(const WCHAR *msg_path,VfxU32 obj_offset, VfxU32 obj_size)
{
    VfxBool draw_result = VFX_FALSE;
    if(m_parent_file_handle == 0)
    {
        VFX_ALLOC_MEM(m_file_path, FS_GenVFN_SIZE * 2, this);
        memset(m_file_path, 0, FS_GenVFN_SIZE * 2);
        m_parent_file_handle = FS_Open((const WCHAR*)msg_path, FS_READ_ONLY | FS_OPEN_SHARED);
        m_result = FS_GenVirtualFileName(
                                            m_parent_file_handle,
                                            (U16*) m_file_path,
                                            (unsigned int)FS_GenVFN_SIZE,
                                            obj_offset,
                                            obj_size);
        if(m_result >= 0)
        {
            VfxS8 *temp_str = (VfxS8*) srv_fmgr_path_get_extension_ptr((WCHAR*) m_th_data->body_name);            
            mmi_ucs2cat((PS8) m_file_path, (PS8) ".");
            mmi_ucs2ncat((PS8) m_file_path, (const CHAR *)temp_str, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
        }
    }
    if (m_result < 0)
    {
        /* Can't create VF, close parent file handle */
        if(m_parent_file_handle)
        {
            FS_Close(m_parent_file_handle);
            m_parent_file_handle=0;
        }
        if(m_file_path)
        {
            VFX_FREE_MEM(m_file_path);
            m_file_path = NULL;
            }
      #ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__  
        if(m_th_data->body_type == MMA_MEDIA_MSG_VIDEO)
        {
            m_s_frame->setImgContent(VfxImageSrc(IMG_ID_VENUS_MMS_VIDEO_OVERLAY));
        }
      #endif  
        draw_result = VFX_FALSE;
    }
    else
    {
        VfxS8 *temp_str = (VfxS8*) srv_fmgr_path_get_extension_ptr((WCHAR*) m_th_data->body_name);
        //ASSERT(temp_str);
        if(!temp_str)
        {
            m_s_frame->setImgContent(VfxImageSrc(IMG_ID_VENUS_MMS_NORMAL_PRIORITY));
            draw_result = VFX_FALSE;
        }
    #ifdef __DRM_SUPPORT__					
        else if((mmi_ucs2cmp((const CHAR*)temp_str, (const CHAR*)L"dm") == 0) || (mmi_ucs2cmp((const CHAR*)temp_str, (const CHAR*)L"dcf") == 0))
        {
            m_s_frame->setImgContent(VfxImageSrc(IMG_ID_VENUS_MMS_DRM_DEFAULT));
            draw_result = VFX_FALSE;
        }
    #endif/*__DRM_SUPPORT__*/					
        else
        {
            draw_result = VFX_TRUE;
        }
    }
    return draw_result;
}

VfxSize VappMMSLiteViewer::setTextData(   VfxFrame *txt,
                                            const VfxWString &str,
                                            VfxBool autoResize,
                                            VfxBool autoFont,
                                            VfxU32 fontSize,
                                            const VfxColor &color,
                                            VfxTextFrame::AlignModeEnum alignMode,
                                            const VfxSize  &size,
                                            const VfxPoint &pos)
{
	VfxTextFrame *txt_data = (VfxTextFrame *)txt;
	txt_data->setString(str);
	txt_data->setPos(pos);
	txt_data->setSize(size);
	txt_data->setAlignMode(alignMode);
	txt_data->setAutoResized(autoResize);
	txt_data->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(fontSize)));
	txt_data->setColor(color);
	txt_data->setString(str);
	return txt_data->getSize();
}

/*void  VappMMSLiteViewer::setMsgType(VfxU32 msgType)
{
can be always set to UM MMS type

}*/

#endif /* __MMI_MMS_2__  */






