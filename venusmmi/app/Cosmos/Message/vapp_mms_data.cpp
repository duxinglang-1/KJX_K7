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
 *  vapp_mms_data.cpp
 *
 * Project:
 * --------
 *  MMS Viewer
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
 *------------------------------------------------------------------------------*/

// This include is for proc call
#include "MMI_features.h"
#include "vapp_msg_features.h"
#ifdef __MMI_MMS_2__
#include "mmi_rp_vapp_mms_def.h"
extern "C"
{
//#include "CommonScreens.h"
#include "GlobalDefs.h"
#include "SettingProfileEnum.h"
#include "MmsXMLDefSrv.h"
#include "MmsSrvGprot.h"
#include "MmsMemoryManagerSrv.h"
#include "vapp_mms_appcore.h"
#include "mms_sap_struct.h"
#include "mmi_inet_app_trc.h"
#include "MmsSrvProt.h"
}

#include "vadp_mmi_frm.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "ui_core\mvc\vfx_mmi.h"
#include "vapp_mms_data.h"
#include "vapp_mms_viewer.h"
#include "vapp_mms_gprot.h"
#include "vapp_mms_appcore.h"
static MMI_BOOL mmi_umms_app_dtmgr_add_node_to_addr_list(srv_mms_addr_struct **list_addr, srv_mms_msg_addr_info_struct *node);
static MMI_BOOL mmi_umms_app_dtmgr_add_node_to_from_list(srv_mms_addr_struct **list_addr, U8 *addr, U8 addr_type);
static void mmi_umms_free_address_list(srv_mms_addr_struct *addr);
VFX_IMPLEMENT_CLASS("VappMmsViewerData", VappMmsViewerData, VfxObject);
VfxBool VappMmsViewerData::checkDataReady(void)
{
    if(m_srv_index)
    {
        srv_mms_xml_parse_rsp_struct xml_rsp_struct;
        mma_mms_description_struct *desc = NULL;
        //VfxBool result;
        //result = getviewerHeaderMsgInfo();
        srv_mms_viewer_fill_data_from_index(m_srv_index, &xml_rsp_struct);
        if(!m_viewer_info.cat_info)
        {
            VFX_ALLOC_MEM(m_viewer_info.cat_info, sizeof(mmi_umms_app_dtmgr_viewer_cateory_info_data), this);
            memset(m_viewer_info.cat_info, 0, sizeof(mmi_umms_app_dtmgr_viewer_cateory_info_data));
        }
        //(m_viewer_info.cat_info)->msg_cntx = xml_rsp_struct.msg_cntx;
        desc= srv_mms_get_desc_pointer();
        //(m_viewer_info.cat_info)->msg_cntx = xml_rsp_struct->msg_cntx;
        if(!(m_viewer_info.cat_info)->msg_cntx)
        {
            VFX_ALLOC_MEM((m_viewer_info.cat_info)->msg_cntx, sizeof(srv_mms_viewer_xml_msg_struct), this);
        }
        if(desc && desc->body)
        {
            (m_viewer_info.cat_info)->msg_cntx->slide_head=desc->body->slides;
            (m_viewer_info.cat_info)->msg_cntx->background_color=desc->body->bgColor;
            (m_viewer_info.cat_info)->msg_cntx->current_slide=&(desc->body->curr_slide);
            (m_viewer_info.cat_info)->msg_cntx->current_slide_num=0;
            (m_viewer_info.cat_info)->msg_cntx->foreground_color=desc->body->fgColor;
            (m_viewer_info.cat_info)->msg_cntx->layout=(srv_mms_viewer_slide_layout_enum)desc->body->layout;
            (m_viewer_info.cat_info)->msg_cntx->total_slide_num = desc->body->slide_no;
            /******************ASM ALLOCATION FOR CATEGORY BUFFERS*******************/
            (m_viewer_info.cat_info)->slide_txt_buffer = srv_mms_get_slide_txt_buffer();
            //(m_viewer_info.cat_info)->src_buffer = xml_rsp_struct.src_buffer;
            (m_viewer_info.cat_info)->inputbox_buffer = srv_mms_get_pinputbox_buffer();
            (m_viewer_info.cat_info)->ptxtbuffersize = srv_mms_get_ptxt_buffer_size();
            (m_viewer_info.cat_info)->msg_cntx->show_attachment_icon = (srv_mms_viewer_is_attachment_in_mms() == WGUI_MV_VIEW_ONLY) ? MMI_TRUE : MMI_FALSE;
        }
        /*ASSERT((m_viewer_info.cat_info)->msg_cntx);
            ASSERT((m_viewer_info.cat_info)->slide_txt_buffer);
            ASSERT((m_viewer_info.cat_info)->inputbox_buffer);
            ASSERT((m_viewer_info.cat_info)->msg_cntx);*/
        m_msg_info.msg_type = MMA_MSG_TYPE_MMS;
        //((m_viewer_info.cat_info)->msg_cntx)->current_slide = ((m_viewer_info.cat_info)->msg_cntx)->slide_head;
        m_state = MMI_UMMS_APP_DTMGR_MSG_DATA_READY;
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

VfxBool VappMmsViewerData::checkViewerDataReady(void)
{
	if (m_state == MMI_UMMS_APP_DTMGR_MSG_DATA_READY) 
    {
        return VFX_TRUE;
    }
	return VFX_FALSE;
}

void VappMmsViewerData::setBasicProp(VfxU32 msg_id_x, VfxBool is_preview, VfxU32 srv_index)
{
	msg_id = msg_id_x;
}
VfxBool VappMmsViewerData::checkMsgInfoDataReady(void)
{
    m_srv_index = srv_mms_create_main_instance(VappMmsViewerPage::deleteAppInstance, (void *)getParent(), msg_id);
    getAsmPoolInit();
    if (m_state == MMI_UMMS_APP_DTMGR_MSG_DATA_READY) 
    {
        return VFX_TRUE;
    }
    VfxBool result;
    result = getviewerHeaderMsgInfo();
    if(result == VFX_TRUE)
    {
        m_state = MMI_UMMS_APP_DTMGR_MSG_DATA_READY;
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

VfxBool VappMmsViewerData::getDataReady(void)
{
    VfxBool result = VFX_TRUE;
    m_srv_index = srv_mms_create_main_instance(VappMmsViewerPage::deleteAppInstance, (void *)getParent(), msg_id);
    getAsmPoolInit();
    result = getviewerHeaderMsgInfo();
    if(result == VFX_TRUE)
    {
        m_signalMmsViewerServiceDone.postEmit(SRV_MMS_VIEWER_OK, 0);
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

VfxBool VappMmsViewerData::getViewerContentReady(void)
{
    srv_mms_get_content_req_struct msg_req;
    memset(&msg_req, 0, sizeof(srv_mms_get_content_req_struct));
    msg_req.msg_id = msg_id;
    msg_req.user_data = (void *)getObjHandle();
    msg_req.call_back = (srv_mms_funcptr_type) VappMmsViewerData::viewerDataReadyCbRspHldr;
#ifdef __MMI_MMS_USE_ASM__
    msg_req.app_id = VfxMainScr::findMainScr((VfxFrame *)this->getParent())->getApp()->getGroupId();
#else
    msg_req.app_id = MMA_APP_ID_VIEWER;
#endif/*__MMI_MMS_USE_ASM__*/
    msg_req.mode = MMA_MODE_VIEW;
    srv_mms_get_content(&msg_req);
	m_state = MMI_UMMS_APP_DTMGR_GET_CONTENT_INFO_WAIT;
	return VFX_TRUE;
	
}
void VappMmsViewerData::getAsmPoolInit(void)
{
    srv_mms_mem_mgr_get_asm_alloc_struct asm_cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&asm_cntx, 0, sizeof(srv_mms_mem_mgr_get_asm_alloc_struct));
    asm_cntx.img_id = IMG_ID_SRV_MMS_VIEWER_APP;
    asm_cntx.str_id = STR_ID_VAPP_MMS_VIEWER_APP;
    asm_cntx.success_cb = mmi_umms_app_core_mms_app_asm_success_callback;
    asm_cntx.stop_cb = VappMmsViewerData::appAsmStopCb;
    asm_cntx.user_data = (void *)getObjHandle();
    asm_cntx.alloc_fn = &VappMmsViewerData::allocMem;
    asm_cntx.free_fn = (mem_free_fn)&VappMmsViewerData::freeMem;
    srv_mms_mem_mgr_init_app_asm_pool(
                                        APPLIB_MEM_AP_ID_UMMS,
                                        m_srv_index,		
                                        &asm_cntx);
    memset(&asm_cntx, 0, sizeof(srv_mms_mem_mgr_get_asm_alloc_struct));
    asm_cntx.img_id = IMG_ID_SRV_MMS_VIEWER_APP;
    asm_cntx.str_id = STR_GLOBAL_MULTIMEDIA_MESSAGE;
    asm_cntx.success_cb = mmi_umms_app_core_asm_viewer_success_callback;
    asm_cntx.stop_cb = VappMmsViewerData::viewerAsmStopCb;
    asm_cntx.user_data = (void *)getObjHandle();
    asm_cntx.alloc_fn = &VappMmsViewerData::allocMem;
    asm_cntx.free_fn = (mem_free_fn)&VappMmsViewerData::freeMem;
    srv_mms_mem_mgr_init_viewer_asm_pool(
                                            APPLIB_MEM_AP_ID_MMS_VIEWER,
                                            m_srv_index,
                                            &asm_cntx);
}

void VappMmsViewerData::onDeinit(void)
{
    VfxObject::onAfterDeinit();
    /*Special Check to Handle Multiple View*/
    /*Abort Old Request if Object is getting Destroyed*/
    if(m_state == MMI_UMMS_APP_DTMGR_GET_CONTENT_INFO_WAIT)
    {
        srv_mms_get_content_req_struct msg_req;
        memset(&msg_req, 0, sizeof(srv_mms_get_content_req_struct));
        msg_req.msg_id = msg_id;
        msg_req.user_data = (void *)getObjHandle();
        msg_req.call_back = (srv_mms_funcptr_type) VappMmsViewerData::viewerDataReadyCbRspHldr;
        msg_req.app_id = MMA_APP_ID_VIEWER;
        msg_req.mode = MMA_MODE_ABORT;
        srv_mms_get_content(&msg_req);
    }
    VappMmsViewerPage *my_page = (VappMmsViewerPage *)this->getParent();
    if(m_viewer_info.cat_info)
    {
        if((m_viewer_info.cat_info)->msg_cntx)
        {
            VFX_FREE_MEM((m_viewer_info.cat_info)->msg_cntx);
        }
        VFX_FREE_MEM(m_viewer_info.cat_info);
    }
    if(my_page->getMode() == MODE_STOP || is_preview == VFX_TRUE || m_mode == MODE_LIGHT)
    {
        srv_mms_mem_mgr_copy_pools(m_srv_index, APPLIB_MEM_AP_ID_UMMS);
        srv_mms_mem_mgr_copy_pools(m_srv_index, APPLIB_MEM_AP_ID_MMS_VIEWER);
        mmi_umms_free_address_list(m_header_info.to_head);
        mmi_umms_free_address_list(m_header_info.cc_head);
        mmi_umms_free_address_list(m_header_info.bcc_head);
        mmi_umms_free_address_list(m_header_info.from);
        srv_mms_mem_mgr_asm_deinit_memory(APPLIB_MEM_AP_ID_UMMS, m_srv_index);
        if(m_msg_info.msg_type == MMA_MSG_TYPE_MMS)
        {
            srv_mms_deinit_viewer(m_srv_index);
            {
                MmsSendReadReport();
            }
        }
        srv_mms_delete_instance(m_srv_index);
        resendMMS();
        if(m_dataTimer)
        {
            m_dataTimer->stop();
        }
    }
}

void VappMmsViewerData::resendOnExit(VfxBool resend_on_exit )
{
	m_resend_on_exit = resend_on_exit;
}

void VappMmsViewerData::resendMMS(void )
{
    if(m_resend_on_exit)
    {
        srv_mms_send_req_struct req; 
        memset(&req, 0, sizeof(srv_mms_send_req_struct));
        req.sim_id = m_msg_info.msg_sim_info;
        req.send_setting = SRV_MMS_SETTING_SAVE_AND_SEND;       /* SRV_MMS_SETTING_SAVE_AND_SEND;SRV_MMS_SETTING_SEND_ONLY */
        req.msg_id = msg_id;
        req.is_rr = (kal_bool)VFX_FALSE;
        req.storage_type = m_msg_info.storage_location;
        vapp_mms_send_msg(&req, VappMmsViewerData::allocMem, VappMmsViewerData::freeMem,this);

        /*Updating Lite */
        if(srv_mms_bgsr_get_msg_status(msg_id) == SRV_MMS_BGSR_STATUS_SENDING)
        {
            srv_mms_bgsr_popup_data  popup_data;
            memset(&popup_data,0, sizeof(srv_mms_bgsr_popup_data));
            popup_data.rsp_type = SRV_MMS_BGSR_RSP_TYPE_NONE;
            popup_data.msg_id = msg_id;
            popup_data.result = 0;
            srv_mms_send_events_ex(EVT_ID_SRV_SHOW_BGSR_POPUP, (void *)(&popup_data));
        }
        m_resend_on_exit = VFX_FALSE;
    }
}
#ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__

VfxBool VappMmsViewerData::checkUseDetailsDataReady(void)
{
    if (m_shown_slide_num == (*(m_viewer_info.cat_info->msg_cntx->current_slide))->slide_num)
    {
        return VFX_TRUE;
    }
    else
    {
        if ((*(m_viewer_info.cat_info->msg_cntx->current_slide))->txt.id == 0 ||
        (*(m_viewer_info.cat_info->msg_cntx->current_slide))->txt.str_id != 0)
        {
            srv_mms_get_use_details_viewer_req_struct msgreq;
            memset(&msgreq, 0, sizeof(srv_mms_get_use_details_viewer_req_struct));
            msgreq.call_back = (srv_mms_funcptr_type)VappMmsViewerData::viewerUseDetailsReadyCbRspHldr;
            msgreq.user_data = (void *)getObjHandle();
            msgreq.index = m_srv_index;
            srv_mms_get_use_details_for_slide(&msgreq);	
            m_shown_slide_num = (*(m_viewer_info.cat_info->msg_cntx->current_slide))->slide_num;
            return VFX_TRUE;
        }
        return VFX_FALSE;
    }
}
VfxBool VappMmsViewerData::getUseDetailsDataReady(void)
{
    srv_mms_get_use_details_viewer_req_struct msgreq;
    memset(&msgreq, 0, sizeof(srv_mms_get_use_details_viewer_req_struct));
    msgreq.call_back = (srv_mms_funcptr_type)VappMmsViewerData::viewerUseDetailsReadyCbRspHldr;
    msgreq.user_data = (void *)getObjHandle();
    msgreq.index = m_srv_index;
    m_req_slide_num = (*(m_viewer_info.cat_info->msg_cntx->current_slide))->slide_num;
    if(srv_mms_get_use_details_for_slide((void*)&msgreq) == SRV_MMS_RESULT_NEED_LEAVE_TIMER)
    {
        if(m_dataTimer == NULL)
        {
            VFX_OBJ_CREATE(m_dataTimer, VfxTimer, this);
        }
        m_dataTimer->setStartDelay(0);
        m_dataTimer->setDuration(SRV_MMS_VIEWER_UNBLOCK_TIME);
        m_use_detail_state = MMI_UMMS_APP_DTMGR_USE_DETAIL_START;
        m_dataTimer->m_signalTick.connect(this, &VappMmsViewerData::onMmsUseDetailsTimerExpiry);
        m_dataTimer->start();
    }
    return VFX_TRUE;
}

void VappMmsViewerData::onMmsUseDetailsTimerExpiry(VfxTimer *timer)
{
    VfxBool result = VFX_FALSE;
    m_dataTimer->stop();
    if(srv_mms_search_instance_ext(m_srv_index) == MMI_FALSE)
    {
        /*MAUI_03100559 , because service is controlled by stop page, which may be removed before play page*/
        /*if instance is deleted and control comes due to timer expiry first and plugout event later, should exit*/
        return;
    }
    switch(m_use_detail_state)
    {
        case MMI_UMMS_APP_DTMGR_USE_DETAIL_START:
            result = srv_mms_viewer_start_compute_use_details(m_srv_index);
            if(result == VFX_TRUE)
            {
                m_use_detail_state = MMI_UMMS_APP_DTMGR_USE_DETAIL_NUMBER;
            }
        break;
        case MMI_UMMS_APP_DTMGR_USE_DETAIL_NUMBER:
            result = srv_mms_viewer_get_numbers_on_slide(m_srv_index);
            if(result == VFX_TRUE)
            {
                m_use_detail_state = MMI_UMMS_APP_DTMGR_USE_DETAIL_EMAIL;
            }
        break;
        case MMI_UMMS_APP_DTMGR_USE_DETAIL_EMAIL:
            result = srv_mms_viewer_get_emails_on_slide(m_srv_index);
            if(result == VFX_TRUE)
            {
                m_use_detail_state = MMI_UMMS_APP_DTMGR_USE_DETAIL_URL;
            }
        break;
        case MMI_UMMS_APP_DTMGR_USE_DETAIL_URL:
            result = srv_mms_viewer_get_urls_on_slide(m_srv_index);
            if(result == VFX_TRUE)
            {
                m_use_detail_state = MMI_UMMS_APP_DTMGR_USE_DETAIL_SORT;
            }
        break;
        case MMI_UMMS_APP_DTMGR_USE_DETAIL_SORT:
            srv_mms_viewer_rsp_for_use_details_for_category(m_srv_index);
        break;
    }
    if(result == VFX_TRUE)
    {
        m_dataTimer->setStartDelay(0);
        m_dataTimer->setDuration(SRV_MMS_VIEWER_UNBLOCK_TIME);
        m_dataTimer->m_signalTick.connect(this, &VappMmsViewerData::onMmsUseDetailsTimerExpiry);
        m_dataTimer->start();
    }
}
#endif/*__MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__*/
VfxU32 VappMmsViewerData::getMyIndex(void)
{
	return m_srv_index;
}

VfxBool VappMmsViewerData::getIsPreview(void)
{
	return is_preview;
}

VfxBool VappMmsViewerData::getviewerHeaderMsgInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* MMI_UMMS_ERROR result; */
    srv_mms_mma_get_msg_info_struct *msg_info;
    U8 count = 0;
    srv_mms_result_enum srv_result = SRV_MMS_RESULT_OK;
    U8 asm_error = 0;
    MMI_BOOL status = MMI_FALSE;
    mma_folder_enum folder_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&m_msg_info, 0, sizeof(mmi_umms_app_dtmgr_msg_info_data_struct));
    memset(&m_header_info, 0, sizeof(mmi_umms_app_dtmgr_xml_header_info_struct));
    if (m_state == MMI_UMMS_APP_DTMGR_GET_DATA_NONE)
    {
        /* asm_error = srv_mms_mem_mgr_check_asm_total_pool(mmi_umms_app_core_asm_viewer_success_callback, m_srv_index);
            if (asm_error == MMI_UMMS_ASM_DRAW_SCR)
            {
            //COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_VIEW_ASM_ERROR);
            m_signalMmsViewerServiceDone.postEmit(SRV_MMS_VIEWER_ASM_ERROR, 0);
            return VFX_FALSE;
            }*/
        asm_error = srv_mms_mem_mgr_alloc_asm_pool(APPLIB_MEM_AP_ID_UMMS, m_srv_index);
        if (asm_error == MMI_UMMS_ASM_DRAW_SCR)
        {
            //COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_VIEW_ASM_ERROR);
            m_signalMmsViewerServiceDone.postEmit(SRV_MMS_VIEWER_ASM_ERROR, 0);
            return VFX_FALSE;
        }
        memset(&m_msg_info, 0, sizeof(mmi_umms_app_dtmgr_msg_info_data_struct));
        memset(&m_header_info, 0, sizeof(mmi_umms_app_dtmgr_xml_header_info_struct));
        msg_info = (srv_mms_mma_get_msg_info_struct*)srv_mms_mem_mgr_app_asm_alloc(sizeof(srv_mms_mma_get_msg_info_struct));
        ASSERT(msg_info);
        memset(msg_info, 0, sizeof(srv_mms_mma_get_msg_info_struct));

        srv_result = (srv_mms_result_enum )srv_mms_mma_get_sync_msg_info(msg_id, msg_info, srv_mms_mem_mgr_app_asm_alloc, srv_mms_mem_mgr_app_asm_free);
        if(srv_result != SRV_MMS_RESULT_OK)
        {
            //mmi_umms_app_if_show_error_pop_up(MMA_RESULT_FAIL);//todo
            srv_mms_mem_mgr_app_asm_free(msg_info);//Similar to MAUI_02296975 Group close request from UM Menu CUI when popup is drawn has already called reset data, that is deleting whole asm pool 
            return VFX_FALSE;
        }

        m_msg_info.result = msg_info->result;
        m_msg_info.storage_location = msg_info->storage_type;
        if(m_msg_info.result == MMA_RESULT_OK)
        {
            m_msg_info.media_type                      = msg_info->msg_media_type;
            m_msg_info.from_address_type               = msg_info->from_address_type;
            m_msg_info.msg_class                       = msg_info->msg_class;
            m_msg_info.priority                        = msg_info->priority;
            m_msg_info.msg_size                        = msg_info->msg_size;
            m_msg_info.date                            = msg_info->date;
            m_msg_info.receive_date                    = msg_info->received_date;
            m_msg_info.expiry_time                     = msg_info->expiry_date + msg_info->received_date;
            m_msg_info.isRead                          = msg_info->isRead;
            m_msg_info.need_read_report                = msg_info->need_read_report;
        #ifdef  __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__
            m_msg_info.need_delivery_report            = msg_info->need_delivery_report;
        #endif/*__MMI_MMS_REPORT_STATUS_MENU_SUPPORT__*/
            m_msg_info.isForwardLock                   = msg_info->isForwardlock;
            m_msg_info.isFollowPhoneMMSContentClass    = msg_info->is_follow_phone_mms_content_class;
            m_msg_info.msg_type                        = msg_info->msg_type;
            m_msg_info.msg_sim_info                    = msg_info->sim_id;
            m_msg_info.lock_mode                       = msg_info->app_data[0];
            m_msg_info.notification_error_type         = msg_info->app_data[1];
            m_msg_info.from_folder                     = msg_info->app_data[2];
            mmi_ucs2ncpy((PS8) m_msg_info.app_id, (PS8) msg_info->java_app_id, /* MAX_PROGRESS_STRING_LENGTH */ 100);
            mmi_ucs2ncpy((PS8) m_msg_info.from_address, (PS8) msg_info->from_address, MMA_MAX_ADDR_LEN);
            mmi_ucs2ncpy((PS8) m_msg_info.subject, (PS8) msg_info->subject, MMA_MAX_SUBJECT_LEN);

        #ifdef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
            m_msg_info.user_element_size               = msg_info->user_elements_size;
        #endif/*__MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__*/
            srv_mms_set_message_type(m_msg_info.msg_type);
            if (!msg_info->isRead)
            {
                //data->set_read_mark = 1;
            }
            m_header_info.download_size                  = msg_info->msg_download_size;
            m_header_info.to_num                         = msg_info->to_addr_count;
            m_header_info.cc_num                         = msg_info->cc_addr_count;
            m_header_info.bcc_num                        = msg_info->bcc_addr_count;
            m_header_info.status                         = msg_info->msg_report_status;
            m_header_info.ph_num                         = msg_info->ph_num;
            m_header_info.email_num                      = msg_info->email_num;
            mmi_ucs2ncpy((PS8) m_header_info.reported_subject, (PS8) msg_info->reported_subject, SRV_MMS_XML_MAX_SUBJECT_LEN + 1);
            if(msg_info->from_address[0] != '\0')
            {
                mmi_umms_app_dtmgr_add_node_to_from_list(&(m_header_info.from), (U8*)msg_info->from_address, msg_info->from_address_type);
            }
            for(count =0; count < MMA_MAX_SUPPORT_ADDR_COUNT; ++count)
            {
                if(msg_info->address[count].addr_len > 0)
                {
                    if(m_header_info.to_head || m_header_info.cc_head || m_header_info.bcc_head)  
                    {
                        if(srv_mms_is_duplicate_address((U8 *)(msg_info->address[count].address), (srv_mms_address_type_enum)msg_info->address[count].addr_type,  m_header_info.to_head,  m_header_info.cc_head, m_header_info.bcc_head))
                        {
                            if(msg_info->address[count].addr_type == SRV_MMS_ADDRESS_TYPE_PHONE_NUMBER)
                            {
                                --m_header_info.ph_num;
                            }
                            else if(msg_info->address[count].addr_type == SRV_MMS_ADDRESS_TYPE_EMAIL)
                            {
                                --m_header_info.email_num;
                            }

                            if(msg_info->address[count].addr_group ==  SRV_MMS_ADDRESS_GROUP_TYPE_TO)
                            {
                                --m_header_info.to_num;
                            }
                            else if(msg_info->address[count].addr_group ==  SRV_MMS_ADDRESS_GROUP_TYPE_CC)
                            {
                                --m_header_info.cc_num;
                            }
                            else if(msg_info->address[count].addr_group ==  SRV_MMS_ADDRESS_GROUP_TYPE_BCC)
                            {
                                --m_header_info.bcc_num;
                            }
                            continue;
                        }   
                    }
                    switch (msg_info->address[count].addr_group)
                    {  
                        case SRV_MMS_ADDRESS_GROUP_TYPE_TO:
                        #ifdef __MMI_MMS_POSTCARD__
                            if(msg_info->msg_type == MMA_MSG_TYPE_POSTCARD)
                            {
                            msg_info->address[count].addr_type = SRV_MMS_ADDRESS_TYPE_EMAIL;
                            }
                        #endif/*__MMI_MMS_POSTCARD__*/
                            mmi_umms_app_dtmgr_add_node_to_addr_list(&(m_header_info.to_head), &msg_info->address[count]);
                            break;

                        case SRV_MMS_ADDRESS_GROUP_TYPE_CC:
                            mmi_umms_app_dtmgr_add_node_to_addr_list(&(m_header_info.cc_head), &msg_info->address[count]);
                            break;

                        case SRV_MMS_ADDRESS_GROUP_TYPE_BCC:
                            mmi_umms_app_dtmgr_add_node_to_addr_list(&(m_header_info.bcc_head), &msg_info->address[count]);
                            break;
                        /*case SRV_MMS_ADDRESS_GROUP_TYPE_FROM:
                                                mmi_umms_app_dtmgr_add_node_to_addr_list(&(m_header_info.from), &msg_info->address[count]);
                                                break;*/
                        default:
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            if (m_msg_info.result == MMA_RESULT_FAIL_FILE_CORRUPTED)
            {
                m_signalMmsViewerServiceDone.postEmit(SRV_MMS_VIEWER_CORRUPT_MMS, 0);
            }
            /*need new MMA enum for fail result*/
            else if(m_msg_info.result == MMA_RESULT_FAIL_UNSUPPORT_MMS_TYPE) 
            {
                m_signalMmsViewerServiceDone.postEmit(SRV_MMS_VIEWER_UNSUPPORT_MMS, 0);
            }
            else
            {
                m_signalMmsViewerServiceDone.postEmit(SRV_MMS_VIEWER_PARSE_FAIL, 0);
            }
            srv_mms_mem_mgr_app_asm_free(msg_info);
            return VFX_FALSE;
        }
        folder_id = mma_get_box(msg_id);
        switch (folder_id)
        {
            case MMA_FOLDER_INBOX:
            case MMA_FOLDER_OUTBOX:
                status = MMI_TRUE;
            break;
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            case MMA_FOLDER_ARCHIVE:
                switch (m_msg_info.from_folder)
                {
                    case MMA_FOLDER_INBOX:
                    case MMA_FOLDER_OUTBOX:
                    status = MMI_TRUE;
                    break;
                }   
            break;
        #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 
        }
        if(status == MMI_TRUE)
        {
        #if(0)
            data->bgsr_msg_info =
            (srv_mms_bgsr_msg_info_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_bgsr_msg_info_struct));
            ASSERT(data->bgsr_msg_info);
            memset(data->bgsr_msg_info, 0, sizeof(srv_mms_bgsr_msg_info_struct));
            data->bgsr_msg_info->status = srv_mms_bgsr_update_msg_status_info(data->msg_id, &(data->bgsr_msg_info->ntt), &(data->bgsr_msg_info->quota));
        #endif
        }
        srv_mms_mem_mgr_app_asm_free(msg_info);
    }
    else
    {
        return VFX_TRUE;
    }
    //return VFX_FALSE;
    return VFX_TRUE;
}

void * VappMmsViewerData::allocMem(U32 size, void *user_data)
{
    VappMmsViewerData *my_data = (VappMmsViewerData *)VfxObject::handleToObject((VfxObjHandle)user_data);
    void *mem = NULL;
    if(my_data && my_data->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsViewerData)) )
    {
        VFX_ALLOC_MEM(mem, size, my_data);
    }
    return mem;
}
void  VappMmsViewerData::freeMem(void *mem)
{
	VFX_FREE_MEM(mem);
}

void VappMmsViewerData::viewerDataReadyCb(srv_mms_result_enum result, void *msgrsp)
{
    srv_mms_get_content_rsp_struct *rsp_content = NULL;
    srv_mms_xml_parse_req_struct xml_req;
    U8 asm_error;
    mma_mms_description_struct *desc = NULL;
    mma_mms_description_struct *description = NULL;
    srv_mms_viewer_result_enum srv_viewer_result;
    switch(m_state)
    {
        case MMI_UMMS_APP_DTMGR_GET_CONTENT_INFO_WAIT:
            rsp_content = (srv_mms_get_content_rsp_struct*) msgrsp;
            if(rsp_content->msg_id != msg_id)
            {
                return;
            }
            if (rsp_content->result != MMA_RESULT_OK)
            {
                //COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, MMI_MV_TRACE_GET_CONTENT_RSP_ERR);
                m_signalMmsViewerServiceDone.postEmit(SRV_MMS_VIEWER_PARSE_FAIL, 0);
                return;
            }
            m_state = MMI_UMMS_APP_DTMGR_ASM_INFO_WAIT;
        case MMI_UMMS_APP_DTMGR_ASM_INFO_WAIT:
            /* Check for ASM */
            /*asm_error = srv_mms_mem_mgr_check_asm_total_pool(mmi_umms_app_core_asm_viewer_success_callback, m_srv_index);
                    if (asm_error == MMI_UMMS_ASM_DRAW_SCR)
                    {
                    //COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_VIEW_ASM_ERROR);
                    m_signalMmsViewerServiceDone.postEmit(SRV_MMS_VIEWER_ASM_ERROR, 0);
                    return;
                    }*/
            asm_error = srv_mms_mem_mgr_alloc_asm_pool(APPLIB_MEM_AP_ID_UMMS, m_srv_index);
            if (asm_error == MMI_UMMS_ASM_DRAW_SCR)
            {
                //COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_VIEW_ASM_ERROR);
                m_signalMmsViewerServiceDone.postEmit(SRV_MMS_VIEWER_ASM_ERROR, 0);
                return;
            }
            asm_error = srv_mms_mem_mgr_alloc_asm_pool(APPLIB_MEM_AP_ID_MMS_VIEWER, m_srv_index);
            if (asm_error == MMI_UMMS_ASM_DRAW_SCR)
            {
                //COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_VIEW_ASM_ERROR);
                m_signalMmsViewerServiceDone.postEmit(SRV_MMS_VIEWER_ASM_ERROR, 0);
                return;
            }
            /* prepare xml parser data */
            memset(&xml_req, 0, sizeof(srv_mms_xml_parse_req_struct));
            xml_req.user_data = (void *)this;
            xml_req.call_back = (srv_mms_funcptr_type) VappMmsViewerData::viewerDataReadyCbRspHldr;
            xml_req.app_id = MMA_APP_ID_VIEWER;
            /* check for header info */
            xml_req.mode = SRV_MMS_XML_PARSE_BODY_ONLY;
            xml_req.index = m_srv_index;
            description =(mma_mms_description_struct *)rsp_content->content_info;
            srv_viewer_result = srv_mms_process_data_init(description, &xml_req);
            //            COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_VIEW_MODE_FOR_XML_PARSE, xml_req.mode);
            if(srv_viewer_result != SRV_MMS_VIEWER_OK)
            {
                m_signalMmsViewerServiceDone.postEmit((srv_mms_viewer_result_enum)srv_viewer_result, 0);
                return;
            }
            m_state = MMI_UMMS_APP_DTMGR_MSG_PARSE_DATA_WAIT;
        case MMI_UMMS_APP_DTMGR_MSG_PARSE_DATA_WAIT:
            if(m_viewer_info.cat_info == NULL)
            {
                VFX_ALLOC_MEM(m_viewer_info.cat_info, sizeof(mmi_umms_app_dtmgr_viewer_cateory_info_data), this);
                memset(m_viewer_info.cat_info, 0, sizeof(mmi_umms_app_dtmgr_viewer_cateory_info_data));
            }
            desc= srv_mms_get_desc_pointer();
            VFX_ALLOC_MEM((m_viewer_info.cat_info)->msg_cntx, sizeof(srv_mms_viewer_xml_msg_struct), this);
            (m_viewer_info.cat_info)->msg_cntx->slide_head=desc->body->slides;
            desc->body->curr_slide=desc->body->slides;
            (m_viewer_info.cat_info)->msg_cntx->background_color=desc->body->bgColor;
            (m_viewer_info.cat_info)->msg_cntx->current_slide=&(desc->body->curr_slide);
            (m_viewer_info.cat_info)->msg_cntx->current_slide_num=0;
            (m_viewer_info.cat_info)->msg_cntx->foreground_color=desc->body->fgColor;
            (m_viewer_info.cat_info)->msg_cntx->layout=(srv_mms_viewer_slide_layout_enum)desc->body->layout;
            (m_viewer_info.cat_info)->msg_cntx->total_slide_num = desc->body->slide_no;
            /******************ASM ALLOCATION FOR CATEGORY BUFFERS*******************/
            (m_viewer_info.cat_info)->slide_txt_buffer = srv_mms_get_slide_txt_buffer();
            //(m_viewer_info.cat_info)->src_buffer = xml_rsp_struct->src_buffer;
            (m_viewer_info.cat_info)->inputbox_buffer = srv_mms_get_pinputbox_buffer();
            (m_viewer_info.cat_info)->ptxtbuffersize = srv_mms_get_ptxt_buffer_size();
            (m_viewer_info.cat_info)->msg_cntx->show_attachment_icon = (srv_mms_viewer_is_attachment_in_mms() == WGUI_MV_VIEW_ONLY) ? MMI_TRUE : MMI_FALSE;
            ASSERT((m_viewer_info.cat_info)->msg_cntx);
            ASSERT((m_viewer_info.cat_info)->slide_txt_buffer);
            ASSERT((m_viewer_info.cat_info)->inputbox_buffer);
            ASSERT((m_viewer_info.cat_info)->msg_cntx);
        case MMI_UMMS_APP_DTMGR_MSG_PARSE_DRM_WAIT:
            m_state = MMI_UMMS_APP_DTMGR_MSG_DATA_READY;
            m_signalMmsViewerServiceDone.postEmit(SRV_MMS_VIEWER_OK, 0);
        break;
    }
}
VfxU32 VappMmsViewerData::getMsgId(void)
{
	return msg_id;
}

void VappMmsViewerData::onMmsTimerExpiry(VfxTimer *timer)
{
    VfxBool result = MMI_FALSE;
    m_dataTimer->stop();
    if(m_state == MMI_UMMS_APP_DTMGR_MSG_PARSE_DATA_WAIT)
    {
        //result = srv_mms_parse_xml_resume(m_srv_index);
        if(result == VFX_TRUE)
        {
            m_dataTimer->setStartDelay(0);
            m_dataTimer->setDuration(SRV_MMS_VIEWER_UNBLOCK_TIME);
            m_dataTimer->m_signalTick.connect(this, &VappMmsViewerData::onMmsTimerExpiry);
            m_dataTimer->start();
        }
    }
}
void VappMmsViewerData::viewerDataReadyCbRspHldr(srv_mms_result_enum result, void *msgrsp, void* user_data)
{
    VappMmsViewerData *my_data = (VappMmsViewerData *)VfxObject::handleToObject((VfxObjHandle)user_data);
    if(my_data && my_data->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsViewerData)) )
    {
        my_data->viewerDataReadyCb( result, msgrsp);
    }
}

#ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
void VappMmsViewerData::viewerUseDetailsReadyCbRspHldr(srv_mms_result_enum result, void *msgrsp, void* user_data)
{
    VappMmsViewerData *my_data = (VappMmsViewerData *)VfxObject::handleToObject((VfxObjHandle)user_data);
    if(my_data && my_data->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsViewerData)) )
    {
        my_data->viewerUseDetailsReadyCb( result, msgrsp);
    }
}

void VappMmsViewerData::viewerUseDetailsReadyCb(srv_mms_result_enum result, void *msgrsp)
{
    if(m_req_slide_num != (*(m_viewer_info.cat_info->msg_cntx->current_slide))->slide_num)
    {
        m_signalMmsViewerUseDetailsDone.postEmit(SRV_MMS_VIEWER_PARSE_FAIL);
        return;
    }
    srv_mms_get_use_details_viewer_rsp_struct *rsp = (srv_mms_get_use_details_viewer_rsp_struct*) msgrsp;
    m_list_head = rsp->list_head;
    m_shown_slide_num = (*(m_viewer_info.cat_info->msg_cntx->current_slide))->slide_num;
    m_signalMmsViewerUseDetailsDone.postEmit(SRV_MMS_VIEWER_OK);
}
#endif/*__MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__*/
mmi_umms_app_dtmgr_msg_info_data_struct *VappMmsViewerData::getMsgInfo(void)
{
	return &(m_msg_info);
}
mmi_umms_app_dtmgr_xml_header_info_struct *VappMmsViewerData::getHeaderInfo(void)
{
	return &(m_header_info);
}
mmi_umms_app_dtmgr_viewer_info_data *VappMmsViewerData::getViewerInfo(void)	
{
	return &(m_viewer_info);
}

srv_mms_viewer_use_details_list *VappMmsViewerData::getUseDetailsListHead(void)	
{
	return m_list_head;
}

MmsRRResultTypeEnum VappMmsViewerData::decideReadReport(void)
{
    mma_folder_enum folder_id;
    m_need_rr_viewer = m_msg_info.need_read_report ? VFX_TRUE : VFX_FALSE;
    folder_id = mma_get_box(msg_id);
    if (
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    ((folder_id == MMA_FOLDER_ARCHIVE) && (m_msg_info.from_folder != MMA_FOLDER_INBOX)) ||
#endif/*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/ 
    ((folder_id != MMA_FOLDER_INBOX)
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    && (folder_id != MMA_FOLDER_ARCHIVE)
#endif/*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/ 
    ) || !(((applib_is_valid_number_unicode((kal_wchar*) m_msg_info.from_address))
    && (m_msg_info.from_address_type == MMA_ADDR_TYPE_PHONE_NUMBER))
    || ((applib_is_valid_email_address_unicode((kal_wchar*) m_msg_info.from_address))
    && (m_msg_info.from_address_type == MMA_ADDR_TYPE_EMAIL)))
    || (E_READ_REPORT_SEND_NEVER == srv_mms_retrieval_settings_read_report()))
    {
        m_need_rr_viewer = VFX_FALSE;
    }
    if (m_need_rr_viewer == VFX_TRUE)
    {
        umms_read_report_enum rr_status = (umms_read_report_enum) srv_mms_retrieval_settings_read_report();
        if (rr_status == E_READ_REPORT_SEND_ALWAYS)
        {
            m_need_rr_viewer = VFX_FALSE;   
            return MMS_SEND_RR_TRUE;
        }
        else if (rr_status == E_READ_REPORT_SEND_NEVER)
        {
            m_need_rr_viewer = VFX_FALSE;
            if (m_msg_info.isRead == MMI_FALSE)
            {
                MmsSetReadmark(VFX_TRUE);
                m_msg_info.isRead = MMI_TRUE;
            }
            return MMS_SEND_RR_FALSE;
        }
    }
    else
    {
        if (m_msg_info.isRead == MMI_FALSE)
        {
            MmsSetReadmark(VFX_TRUE);
            m_msg_info.isRead = MMI_TRUE;
        }
        return MMS_SEND_RR_FALSE;
    }
    
    return MMS_SEND_RR_FALSE;
}

void mmi_umms_free_address_list(srv_mms_addr_struct *addr)
{
    srv_mms_addr_struct *temp = NULL;
    while(addr != NULL)
    {
        temp = addr;
        addr = addr->next;
        srv_mms_mem_mgr_app_asm_free(temp->addr);
        srv_mms_mem_mgr_app_asm_free(temp);
        temp = NULL;
    }
}
/*****************************************************************************
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *****************************************************************************/
MMI_BOOL mmi_umms_app_dtmgr_add_node_to_addr_list(srv_mms_addr_struct **list_addr, srv_mms_msg_addr_info_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_addr_struct *temp = NULL, *list = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list = *list_addr;
    if(!list)
    {
        list           = (srv_mms_addr_struct *)srv_mms_mem_mgr_app_asm_alloc(sizeof(srv_mms_addr_struct));
        MMI_ASSERT(list);
        memset(list,0, sizeof(srv_mms_addr_struct));
        list->addr     = (kal_uint8 *)srv_mms_mem_mgr_app_asm_alloc((node->addr_len +1) * ENCODING_LENGTH);
        MMI_ASSERT(list->addr);
        memset(list->addr, 0, (node->addr_len+1) * ENCODING_LENGTH);
        list->group    = (srv_mms_address_group_type_enum)node->addr_group; 	                 
        list->type     = (srv_mms_address_type_enum)node->addr_type;
        list->next     = NULL;
        list->previous = NULL;
        mmi_ucs2ncpy((PS8)list->addr, (PS8)node->address, node->addr_len);
        *list_addr = list;
        return MMI_TRUE;
    }
    while(list->next != NULL)
    {
        list = list->next;
    }
    if(list)
    {
        temp           = (srv_mms_addr_struct *)srv_mms_mem_mgr_app_asm_alloc(sizeof(srv_mms_addr_struct));
        MMI_ASSERT(temp);
        memset(temp,0, sizeof(srv_mms_addr_struct));
        temp->addr     = (kal_uint8 *)srv_mms_mem_mgr_app_asm_alloc((node->addr_len+1) * ENCODING_LENGTH);
        MMI_ASSERT(temp->addr);
        memset(temp->addr,0, (node->addr_len+1) * ENCODING_LENGTH);
        temp->group    = (srv_mms_address_group_type_enum)node->addr_group; 	                 
        temp->type     = (srv_mms_address_type_enum)node->addr_type;
        temp->next     = NULL;
        temp->previous = list;
        list->next     = temp;
        if(node->addr_type == SRV_MMS_ADDRESS_TYPE_PHONE_NUMBER)
        {
            mmi_ucs2_n_to_asc((CHAR *)temp->addr, (CHAR *)node->address, node->addr_len* ENCODING_LENGTH);
        }
        else
        {
            mmi_ucs2ncpy((PS8)temp->addr, (PS8)node->address, node->addr_len);
        }
        return MMI_TRUE;
    }
   return MMI_FALSE;
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
MMI_BOOL mmi_umms_app_dtmgr_add_node_to_from_list(srv_mms_addr_struct **list_addr, U8 *addr, U8 addr_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_addr_struct *list = NULL;
    S32 len = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list = *list_addr;
    if(!list)
    {
        list           = (srv_mms_addr_struct *)srv_mms_mem_mgr_app_asm_alloc(sizeof(srv_mms_addr_struct));
        MMI_ASSERT(list);
        memset(list,0, sizeof(srv_mms_addr_struct));
        len = mmi_ucs2strlen((const CHAR *)addr);
        list->addr     = (kal_uint8 *)srv_mms_mem_mgr_app_asm_alloc((len + 1) * ENCODING_LENGTH);
        MMI_ASSERT(list->addr);
        memset(list->addr, 0, (len + 1) * ENCODING_LENGTH);
        list->group    = SRV_MMS_ADDRESS_GROUP_TYPE_FROM; 	                 
        //list->type     = (srv_mms_address_type_enum)srv_mms_convert_mma_addr_type_to_srv_addr_type((mma_addr_type_enum)addr_type);
        list->next     = NULL;
        list->previous = NULL;
        if(list->type == SRV_MMS_ADDRESS_TYPE_PHONE_NUMBER)
        {
            mmi_ucs2_n_to_asc((CHAR *)list->addr, (CHAR *)addr, len * ENCODING_LENGTH);
        }
        else
        {
            mmi_ucs2ncpy((PS8)list->addr, (PS8)addr, len);
        }
        *list_addr = list;
        return MMI_TRUE;
    }
    return MMI_FALSE;

}

#ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
VFX_IMPLEMENT_CLASS("VappMmsUseDetails", VappMmsUseDetails, VfxObject);

VfxBool VappMmsUseDetails::getUseDetailsFromSrv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_get_use_details_req_struct req;
    srv_mms_get_use_details_rsp_struct *use_detail_rsp = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&req, 0, sizeof(srv_mms_get_use_details_req_struct));
    req.data_type = APPLIB_ADDR_TYPE_PHONENUMBER;  
    use_detail_rsp = (srv_mms_get_use_details_rsp_struct *)srv_mms_get_use_details_req_hdlr((void*)&req);
    if(SRV_MMS_GET_USE_DETAILS_RESULT_SUCCESS != use_detail_rsp->result && 
    SRV_MMS_GET_USE_DETAILS_RESULT_OUT_OF_MEM != use_detail_rsp->result)
    {
        ASSERT(0);
    }
    m_data.get_use_details_rsp.num_list = use_detail_rsp->num_list;
    req.data_type = APPLIB_ADDR_TYPE_EMAIL;
    use_detail_rsp = (srv_mms_get_use_details_rsp_struct *)srv_mms_get_use_details_req_hdlr((void*)&req);
    if(SRV_MMS_GET_USE_DETAILS_RESULT_SUCCESS != use_detail_rsp->result && 
    SRV_MMS_GET_USE_DETAILS_RESULT_OUT_OF_MEM != use_detail_rsp->result)
    {
        ASSERT(0);
    }
    m_data.get_use_details_rsp.email_list = use_detail_rsp->email_list;
    req.data_type = APPLIB_ADDR_TYPE_URL;
    use_detail_rsp = (srv_mms_get_use_details_rsp_struct *)srv_mms_get_use_details_req_hdlr((void*)&req);
    if(SRV_MMS_GET_USE_DETAILS_RESULT_SUCCESS != use_detail_rsp->result && 
    SRV_MMS_GET_USE_DETAILS_RESULT_OUT_OF_MEM != use_detail_rsp->result)
    {
        ASSERT(0);
    }
    m_data.get_use_details_rsp.url_list = use_detail_rsp->url_list;
    return VFX_TRUE;
}

VfxU32 VappMmsUseDetails::getUseDetailsCount(void)
{
    applib_address_node_struct *node1 = NULL;
    applib_address_node_struct *nodes[3] = {m_data.get_use_details_rsp.num_list, m_data.get_use_details_rsp.email_list, m_data.get_use_details_rsp.url_list};
    VfxU32 num_item = 0;
    for(int i =0;i < 3; i++)
    {
        node1 = nodes[i];
        while (node1 != NULL)
        {
            if ((node1->length != 0) || (node1->pos != 0))
            {
                num_item++;
            }
            node1 = node1->next;
        }
    }
    return num_item;
}
applib_address_node_struct *VappMmsUseDetails::getUseDetailsNode(VfxU32 index)
{
    VfxS32 count = -1;
    applib_address_node_struct *nodes[3] = {m_data.get_use_details_rsp.num_list, m_data.get_use_details_rsp.email_list, m_data.get_use_details_rsp.url_list};
    applib_address_node_struct *node1 = NULL;
    for(int i =0;i < 3; i++)    
    {
        node1 = nodes[i];
        while (node1 != NULL && count < (VfxS32)index)
        {
            if ((node1->length != 0) || (node1->pos != 0))
            {
                ++count;
            }
            if (count == index)
            {
                return node1;
            }
            node1 = node1->next;
        }
    }
    return NULL;
}
#endif/*__MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__*/
#ifdef __DRM_SUPPORT__
VfxBool VappMmsDrmHandler::checkRightsById(srv_mms_viewer_object_info_struct *obj, VfxU32 index)
{
    if(srv_mms_search_instance_ext(index) == MMI_FALSE)
    {
        return VFX_FALSE;
    }
    VfxBool result = srv_mms_check_rights_by_id(obj);
    return result;
}

VfxBool VappMmsDrmHandler::startConsumeRights(srv_mms_viewer_object_info_struct *obj, VfxU16 *file_path, srv_mms_rights_expiry_notify_cb expiry_func, void *user_data, VfxU32 index)
{
    if(srv_mms_search_instance_ext(index) == MMI_FALSE)
    {
        return VFX_TRUE;
    }
    VfxBool result = srv_mms_start_consume_rights(obj, file_path, expiry_func, user_data);
    return result;
}

void VappMmsDrmHandler::stopConsumeRights(srv_mms_viewer_object_info_struct *obj, VfxU32 index)
{
    if(srv_mms_search_instance_ext(index) == MMI_FALSE)
    {
        return;
    }
    srv_mms_stop_consume_rights(obj);
}

void VappMmsDrmHandler::updateRightsById(srv_mms_viewer_object_info_struct *obj, VfxBool rightsExpired, VfxU32 index)
{
    if(srv_mms_search_instance_ext(index) == MMI_FALSE)
    {
        return;
    }
    srv_mms_update_rights_by_id(obj, (kal_bool)rightsExpired);
}
#endif/*__DRM_SUPPORT__*/
/*****************************************************************************
 * FUNCTION
 *  MmsSetReadmark
 * DESCRIPTION
 *  
 * PARAMETERS
 *  read        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void VappMmsViewerData::MmsSetReadmark(VfxBool read)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 error = 0;
    U8 srv_result = 0;
    srv_mms_um_refresh_ind_struct req;
    mma_folder_enum folder_id = mma_get_box(msg_id);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_result = srv_mms_set_read_status(msg_id, (kal_bool)read, &error);

    if(srv_result != SRV_MMS_RESULT_OK)
    {
        return;
    }
    if(error == MMA_RESULT_OK)
    {
        srv_mms_show_status_icon();
    }
    memset(&req, 0, sizeof(srv_mms_um_refresh_ind_struct));
    req.msg_box_type = folder_id;
    req.refresh_type = SRV_UM_REFRESH_MSG_STATUS_CHANGED;
    req.msg_id = msg_id;
    srv_mms_um_refresh_msg_list(&req);  
}

/*****************************************************************************
 * FUNCTION
 *  MmsSendReadReport
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void VappMmsViewerData::MmsSendReadReport(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_send_read_report_req_struct msgreq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(m_need_rr_viewer == VFX_TRUE)
    {
        srv_mms_bgsr_set_rr_flag(msg_id);
        if (m_msg_info.isRead == MMI_FALSE)
        {
            MmsSetReadmark(VFX_TRUE);
            m_msg_info.isRead = MMI_TRUE;
        }
        memset(&msgreq, 0, sizeof(srv_mms_send_read_report_req_struct));
        msgreq.sim_id =  m_msg_info.msg_sim_info ;
        msgreq.msg_id = msg_id;
        msgreq.storage_location = m_msg_info.storage_location;
        srv_mms_send_read_report_req(&msgreq);
    }
}

/*****************************************************************************
 * FUNCTION
 *  MmsAbortReadReport
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void VappMmsViewerData::MmsAbortSendReadReport(U32 msg_id_ex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(msg_id == msg_id_ex && m_need_rr_viewer == VFX_TRUE)
    {
        m_need_rr_viewer = VFX_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  MmsHandleReadReport
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MmsRRResultTypeEnum VappMmsViewerData::MmsHandleReadReport(VfxBool send)
{
    if(send == VFX_TRUE)
    {
        m_need_rr_viewer = VFX_TRUE;
    #if(MMI_MAX_SIM_NUM >= 2)
        if (MMI_FALSE == srv_mms_is_sim_valid((mmi_sim_enum) m_msg_info.msg_sim_info))
        {
            m_need_rr_viewer = VFX_FALSE;
            if (m_msg_info.isRead == MMI_FALSE)
            {
                MmsSetReadmark(VFX_TRUE);
                m_msg_info.isRead = MMI_TRUE;
            }
            return MMS_SEND_RR_ERROR;
        }
    #endif /* #if(MMI_MAX_SIM_NUM >= 2) */ 
        return MMS_SEND_RR_TRUE;
    }
    else
    {
        m_need_rr_viewer = VFX_FALSE;
        if (m_msg_info.isRead == MMI_FALSE)
        {
            MmsSetReadmark(VFX_TRUE);
            m_msg_info.isRead = MMI_TRUE;
        }
        return MMS_SEND_RR_FALSE;
    }
}
 void VappMmsViewerData::viewerAsmStopCb(void *user_data)
{
	VappMmsViewerData *my_data = (VappMmsViewerData *)VfxObject::handleToObject((VfxObjHandle)user_data);
	if(my_data && my_data->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsViewerData)) )
	{
		my_data->m_signalMmsViewerServiceDone.postEmit(SRV_MMS_VIEWER_ASM_ERROR, 0);
	}
}

 void VappMmsViewerData::appAsmStopCb(void *user_data)
{
	VappMmsViewerData *my_data = (VappMmsViewerData *)VfxObject::handleToObject((VfxObjHandle)user_data);
	if(my_data && my_data->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsViewerData)) )
	{
		my_data->m_signalMmsViewerServiceDone.postEmit(SRV_MMS_VIEWER_ASM_ERROR, 0);
	}
}
#endif /*  __MMI_MMS_2__ */		