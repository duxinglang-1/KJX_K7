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
 *  vapp_mms_toolbar.cpp
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
//#include "CommonScreens.h"
#include "GlobalDefs.h"
#include "SettingProfileEnum.h"
#include "MmsXMLDefSrv.h"
#include "MmsSrvGprot.h"
#include "MmsSrvprot.h"
//#include "SimDetectionGprot.h"
	#include "UCMGProt.h"
#include "UcmSrvGprot.h"
	#include "MMSMemoryManagerSrv.h"
//#include "SimDetectionStruct.h"
#include "mms_sap_struct.h"
	#include "MMSAppCommonGprot.h"
#include "mma_struct.h"
#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGProt.h"
#include "UcSrvGprot.h"
	#include "mmi_frm_scenario_gprot.h"
	#include "Conversions.h"
	#include "Dialercuigprot.h"
}

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
#include "vapp_mms_appcore.h"
#include "vapp_mms_common.h"
#include "vapp_mms_view_objects.h"
#ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
#include "vapp_mms_use_details.h"
#endif
#include "vapp_mms_viewer.h"
#include "vcp_include.h"
#include "vapp_uc_gprot.h"
#include "vcp_navi_title_bar.h"
#include "mmi_rp_vapp_unifiedcomposer_def.h"
#include "vapp_mms_gprot.h"
#include "DialerCuiGprot.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"

//VfxU8 VappMmsToolBar::s_op_type  = VappMmsToolBar::COPY_MMS_TO_TOTAL;

VFX_IMPLEMENT_CLASS("VappMmsToolBar", VappMmsToolBar, VcpToolBar);


void  VappMmsToolBar::onInit(void)
{
    VcpToolBar::onInit();
    this->m_signalButtonTap.connect(this, &VappMmsToolBar::onToolBarClick);
    this->m_signalBarFolded.connect(this, &VappMmsToolBar::onFolding);
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__        
    mmi_frm_cb_reg_event(EVT_ID_SRV_CHANGE_STORAGE, VappMmsToolBar::listener, getObjHandle());
#endif/*__MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__*/
    //setBottomBar(this);
}
void  VappMmsToolBar::onDeinit(void)
{
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__        		
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CHANGE_STORAGE, VappMmsToolBar::listener, getObjHandle());
#endif/*__MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__*/
    //setBottomBar(this);
    if(m_string)
    {
        srv_mms_mem_mgr_app_asm_free(m_string);
        m_string = NULL;
    }
    if(m_has_register)
    {
        mmi_frm_cb_dereg_event(EVT_ID_SRV_UC_MESSAGE_DELETED, VappMmsToolBar::onUcClose, getObjHandle());       
    }
    VcpToolBar::onDeinit();
}
void  VappMmsToolBar::setData(VappMmsViewerData *data)
{

    m_data = data;
    mmi_umms_app_dtmgr_msg_info_data_struct * msg_info = m_data->getMsgInfo();
    mmi_umms_app_dtmgr_xml_header_info_struct *header_info = m_data->getHeaderInfo();
    mmi_sim_enum  sim_id = vapp_mms_convert_mma_sim_to_mmi_sim(msg_info->msg_sim_info);
    m_msg_id =  m_data->getMsgId();
    m_msg_type = msg_info->msg_type; 
    m_box_type = mma_get_box(m_msg_id);
    deleteOld();
    if(msg_info->result == MMA_RESULT_FAIL_FILE_CORRUPTED
    ||msg_info->result == MMA_RESULT_FAIL_UNSUPPORT_MMS_TYPE)
    {
        this->addItem(ACTION_DELETE,VFX_WSTR_RES(VCP_STR_TOOL_BAR_DELETE),  VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
        return;
    }
    if(((msg_info->msg_type == MMA_MSG_TYPE_MMS) || (msg_info->msg_type == MMA_MSG_TYPE_NOTIFICATION))&& 
    ((m_box_type == MMA_FOLDER_INBOX) || ((m_box_type == MMA_FOLDER_ARCHIVE) && (msg_info->from_folder == MMA_FOLDER_INBOX))))
    {
        this->addItem(ACTION_REPLY,VFX_WSTR_RES(VCP_STR_TOOL_BAR_REPLY),  VCP_IMG_TOOL_BAR_COMMON_ITEM_REPLY);
        this->addItem(ACTION_CALL,VFX_WSTR_RES(STR_GLOBAL_DIAL),  IMG_ID_VAPP_MMS_CALL); 
        if (msg_info->from_address_type != MMA_ADDR_TYPE_PHONE_NUMBER)
        {
            this->setDisableItem(ACTION_CALL, VFX_TRUE);
        }
        if ((msg_info->from_address_type != MMA_ADDR_TYPE_PHONE_NUMBER) && (msg_info->from_address_type != MMA_ADDR_TYPE_EMAIL))
        {
            this->setDisableItem(ACTION_REPLY, VFX_TRUE);
        }
    }
    this->addItem(ACTION_DELETE,VFX_WSTR_RES(VCP_STR_TOOL_BAR_DELETE),  VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    if(((msg_info->msg_type == MMA_MSG_TYPE_MMS) || (msg_info->msg_type == MMA_MSG_TYPE_NOTIFICATION)) && 
    (((m_box_type == MMA_FOLDER_INBOX) || ((m_box_type == MMA_FOLDER_ARCHIVE) && (msg_info->from_folder == MMA_FOLDER_INBOX)))
    || ((m_box_type == MMA_FOLDER_SENT) || ((m_box_type == MMA_FOLDER_ARCHIVE) && (msg_info->from_folder == MMA_FOLDER_SENT)))))
    {
        this->addItem(ACTION_FORWARD,VFX_WSTR_RES(VCP_STR_TOOL_BAR_FORWARD),  VCP_IMG_TOOL_BAR_COMMON_ITEM_FORWARD);
        if(msg_info->isForwardLock)
        {
            this->setDisableItem(ACTION_FORWARD, VFX_TRUE);
        }
    }

    if(((msg_info->msg_type == MMA_MSG_TYPE_MMS) || (msg_info->msg_type == MMA_MSG_TYPE_NOTIFICATION)) && 
    m_box_type != MMA_FOLDER_TEMPLATE && m_box_type != MMA_FOLDER_USRDEF_TEMPLATE)
    {

    #ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
        this->addItem(ACTION_USE_DETAILS,VFX_WSTR_RES(STR_ID_VAPP_MMS_DETAIL_TBAR),  IMG_ID_VENUS_MMS_USE_DETAIL);
    #endif/*__MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__*/
        this->addItem(ACTION_VIEW_OBJECTS,VFX_WSTR_RES(STR_ID_VAPP_MMS_OBJECT_TBAR),  IMG_ID_VENUS_MMS_VIEW_OBJECT);
    }

#ifndef __COSMOS_NO_USER_DRIVE__    
    if(((msg_info->msg_type == MMA_MSG_TYPE_MMS) || (msg_info->msg_type == MMA_MSG_TYPE_NOTIFICATION)) && 
    ((m_box_type == MMA_FOLDER_INBOX)||(m_box_type == MMA_FOLDER_SENT)))
    {
        this->addItem(ACTION_COPY_TO,VFX_WSTR_RES(STR_ID_VAPP_MMS_COPY_MESSAGES),  VCP_IMG_TOOL_BAR_COMMON_ITEM_COPY);
    }
#endif /* __COSMOS_NO_USER_DRIVE__*/
    if(m_box_type == MMA_FOLDER_OUTBOX)
    {
        this->addItem(ACTION_RESEND,VFX_WSTR_RES(STR_ID_VAPP_MMS_RESEND),  IMG_ID_VAPP_MMS_RESEND);
        if(!srv_sim_ctrl_is_available(sim_id) || (SRV_MODE_SWITCH_OFF == srv_mode_switch_get_network_mode(sim_id)))
        {
            this->setDisableItem(ACTION_RESEND, VFX_TRUE);
        }
        this->addItem(ACTION_EDIT,VFX_WSTR_RES(VCP_STR_TOOL_BAR_EDIT),  VCP_IMG_TOOL_BAR_COMMON_ITEM_EDIT);
        if(msg_info->isForwardLock)
        {
            this->setDisableItem(ACTION_EDIT, VFX_TRUE);
        }
    }
    if(m_box_type == MMA_FOLDER_TEMPLATE || m_box_type == MMA_FOLDER_USRDEF_TEMPLATE)
    {
        this->removeItem(ACTION_DELETE);
        this->addItem(ACTION_USE,VFX_WSTR_RES(STR_ID_VAPP_MMS_WRITE_MESSAGE),  IMG_ID_VENUS_MMS_USE);
        this->addItem(ACTION_EDIT,VFX_WSTR_RES(VCP_STR_TOOL_BAR_EDIT),  VCP_IMG_TOOL_BAR_COMMON_ITEM_EDIT);
        if(msg_info->isForwardLock)
        {
            this->setDisableItem(ACTION_EDIT, VFX_TRUE);
        }
        this->addItem(ACTION_DELETE,VFX_WSTR_RES(VCP_STR_TOOL_BAR_DELETE),  VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    }

#ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__
    if(m_box_type == MMA_FOLDER_SENT)
    {
        this->addItem(ACTION_REPORTS,VFX_WSTR_RES(STR_ID_VAPP_MMS_REPORTS), IMG_ID_VAPP_MMS_REPORTS );
        /*#ifdef  __MMI_MMS_REPORT_STATUS_SUPPORT__
            if(!(msg_info->need_delivery_report) && !(msg_info->need_read_report))
            {
            this->setDisableItem(ACTION_REPORTS, VFX_TRUE);
            }
            #endif*/
    }

#endif/*__MMI_MMS_REPORT_STATUS_SUPPORT__*/
    if( msg_info->msg_type == MMA_MSG_TYPE_NOTIFICATION)
    {
        updatToolbar();
    }
    if(srv_mms_bgsr_get_msg_status(m_msg_id) == SRV_MMS_BGSR_STATUS_SENDING)
    {
        this->setDisableItem(ACTION_DELETE, VFX_TRUE);
    }

}


VfxBool VappMmsToolBar::deleteOld(void)
{
	this->removeItem(ACTION_REPLY);
	this->removeItem(ACTION_CALL);
	this->removeItem(ACTION_FORWARD);
	this->removeItem(ACTION_DELETE);
#ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__	
	this->removeItem(ACTION_USE_DETAILS);
#endif/*__MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__*/
	this->removeItem(ACTION_VIEW_OBJECTS);
#ifndef __COSMOS_NO_USER_DRIVE__   
	this->removeItem(ACTION_COPY_TO);
#endif/*__COSMOS_NO_USER_DRIVE__*/
	this->removeItem(ACTION_RESEND);
	this->removeItem(ACTION_EDIT);
	this->removeItem(ACTION_USE);
#ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__	
	this->removeItem(ACTION_REPORTS);
#endif/*__MMI_MMS_REPORT_STATUS_SUPPORT__*/
	return VFX_TRUE;
}
void VappMmsToolBar::updatToolbar(void)
{
    mmi_umms_app_dtmgr_msg_info_data_struct * msg_info = m_data->getMsgInfo();
    if(m_msg_type == MMA_MSG_TYPE_NOTIFICATION)
    {
        if(srv_mms_bgsr_get_msg_status(m_msg_id) == SRV_MMS_BGSR_STATUS_DOWNLOADING)
        {
            this->setDisableItem(ACTION_DELETE, VFX_TRUE);
            this->setDisableItem(ACTION_CALL, VFX_TRUE);
            this->setDisableItem(ACTION_REPLY, VFX_TRUE);
            this->setDisableItem(ACTION_FORWARD, VFX_TRUE);
        #ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__			
            this->setDisableItem(ACTION_USE_DETAILS, VFX_TRUE);
        #endif/*__MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__*/
            this->setDisableItem(ACTION_VIEW_OBJECTS, VFX_TRUE);
        #ifndef __COSMOS_NO_USER_DRIVE__    
            this->setDisableItem(ACTION_COPY_TO, VFX_TRUE);
        #endif/*__COSMOS_NO_USER_DRIVE__*/
        }
        else
        {
            this->setDisableItem(ACTION_DELETE, VFX_FALSE);
            if (msg_info->from_address_type != MMA_ADDR_TYPE_PHONE_NUMBER)
            {
                this->setDisableItem(ACTION_CALL, VFX_TRUE);
            }
            else
            {
                this->setDisableItem(ACTION_CALL, VFX_FALSE);
            }
            if ((msg_info->from_address_type != MMA_ADDR_TYPE_PHONE_NUMBER) && (msg_info->from_address_type != MMA_ADDR_TYPE_EMAIL))
            {
                this->setDisableItem(ACTION_REPLY, VFX_TRUE);
            }
            else
            {
                this->setDisableItem(ACTION_REPLY, VFX_FALSE);
            }
            this->setDisableItem(ACTION_FORWARD, VFX_TRUE);
        #ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
            this->setDisableItem(ACTION_USE_DETAILS, VFX_TRUE);
        #endif/*__MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__*/
            this->setDisableItem(ACTION_VIEW_OBJECTS, VFX_TRUE);
        #ifndef __COSMOS_NO_USER_DRIVE__  
            this->setDisableItem(ACTION_COPY_TO, VFX_TRUE);
        #endif/*__COSMOS_NO_USER_DRIVE__*/

        }
    }
    else
    {
    #ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
        VappMmsUseDetails useDetail(m_data->getMyIndex());
        useDetail.getUseDetailsFromSrv();
        if(useDetail.getUseDetailsCount() == 0)
        {
            this->setDisableItem(ACTION_USE_DETAILS, VFX_TRUE);
        }
        else
        {
            this->setDisableItem(ACTION_USE_DETAILS, VFX_FALSE);
        }
    #endif/*__MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__*/
        if(srv_mms_viewer_get_total_obj_count() == 0)
        {
            this->setDisableItem(ACTION_VIEW_OBJECTS, VFX_TRUE);
        }
        else
        {
            this->setDisableItem(ACTION_VIEW_OBJECTS, VFX_FALSE);
        }
    }
}

void VappMmsToolBar::onToolBarClick(VfxObject* sender, VfxId id)
{
	if(m_data->getMsgInfo()->msg_type == MMA_MSG_TYPE_MMS && m_data->checkViewerDataReady() == VFX_FALSE)
	{
		return;
	}
	switch(id)
	{
		case ACTION_REPLY:
			reply();
			break;
		case ACTION_CALL:
			call();
			break;
		case ACTION_FORWARD:
			forward();
			break; 
		case ACTION_DELETE:
			deleteMsg();
			break;
    #ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__		
		case ACTION_USE_DETAILS:
			useDetails();
            break;
    #endif/*__MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__*/
        case ACTION_VIEW_OBJECTS:
             viewObjects();
            break;
    #ifndef __COSMOS_NO_USER_DRIVE__        
		case ACTION_COPY_TO:
			copyTo();
			break;
    #endif/* __COSMOS_NO_USER_DRIVE__    */    
		case ACTION_RESEND:
			resend();
			break;
		case ACTION_EDIT:
    #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
            if((m_box_type == MMA_FOLDER_USRDEF_TEMPLATE)||(m_box_type == MMA_FOLDER_TEMPLATE))
			{
				editTemplate();
            }
			else
    #endif/*__MMI_MMS_TEMPLATE_SUPPORT__*/
            {
			    edit();
			}
			
			break;
		case ACTION_USE:
			edit();
			break;
    #ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__
	   case ACTION_REPORTS:
			reports();
			break;
    #endif/*__MMI_MMS_REPORT_STATUS_SUPPORT__*/			
	}	
}

mmi_ret VappMmsToolBar::handleCuiProc(mmi_event_struct *evt)
{   
    VappMmsToolBar* user_data  =  (VappMmsToolBar*)VfxObject::handleToObject((VfxObjHandle)evt->user_data);
    mmi_group_event_struct *groupEvent = (mmi_group_event_struct*)evt;
    mmi_id senderId = groupEvent->sender_id;
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_DIALER_CLOSED_IND:
            break;
        case EVT_ID_CUI_DIALER_CLOSE_REQ:
            cui_dialer_close(senderId);
        break;
        default:
        break;
    }
    if(user_data)
    {
        switch(evt->evt_id)
        {
            case EVT_ID_CUI_DIALER_CLOSED_IND:
                user_data->m_curr_cui_id = GRP_ID_INVALID;
                if(user_data->m_string)
                {
                srv_mms_mem_mgr_app_asm_free(user_data->m_string);
                user_data->m_string = NULL;
                }
            break;
            case EVT_ID_CUI_DIALER_CLOSE_REQ:
                break;
            default:
            break;
        }
    }
    return MMI_RET_OK;
}


void VappMmsToolBar::call(void) 
{
    mmi_umms_app_dtmgr_msg_info_data_struct * msg_info = m_data->getMsgInfo();
    mmi_id grpId = VfxMainScr::findMainScr((VfxFrame *)getParent())->getApp()->getGroupId();
    /*if(!srv_mode_switch_is_network_service_available())
        {
        mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_MMS_INFO,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_INFO,
        (WCHAR*)GetString(STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE));
        return;
        }*/
    VfxU32 len = mmi_ucs2strlen((PS8)msg_info->from_address);
    m_string =  (U16*) srv_mms_mem_mgr_app_asm_alloc((len + 1)  * ENCODING_LENGTH);
    memset(m_string, 0, (len + 1) * ENCODING_LENGTH);
    mmi_ucs2ncpy((S8 *)m_string, (S8 *)msg_info->from_address, len);
    m_curr_cui_id = cui_dialer_create_ex(grpId, CUI_DIALER_TYPE_CLASSIC);
    mmi_frm_group_set_caller_proc(m_curr_cui_id, &VappMmsToolBar::handleCuiProc, (void*)getObjHandle());
    if(m_curr_cui_id != GRP_ID_INVALID)
    {
        cui_dialer_set_phb_data(m_curr_cui_id, NULL);
        cui_dialer_set_dial_string(m_curr_cui_id, (const WCHAR*)m_string);
        cui_dialer_run(m_curr_cui_id);
    }
//srv_mms_mem_mgr_app_asm_free(m_string);
}

void VappMmsToolBar::reply(void)
{
	vapp_mms_start_uc_struct uc_start;
    
    mmi_umms_app_dtmgr_msg_info_data_struct * msg_info = m_data->getMsgInfo();
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&uc_start, 0, sizeof(vapp_mms_start_uc_struct));
    uc_start.msg_id = m_msg_id;
    uc_start.uc_mode = MMA_MODE_REPLY;
    uc_start.sim_id = msg_info->msg_sim_info;
    uc_start.storage_type = msg_info->storage_location;
    uc_start.uc_type = SRV_UC_STATE_REPLY;
	uc_start.uc_op = UC_OPERATION_REPLY;
	uc_start.grp_id = VfxMainScr::findMainScr((VfxFrame *)getParent())->getApp()->getGroupId();
	vapp_mms_start_uc(&uc_start);
 }
void VappMmsToolBar::resend(void)
{
    mmi_umms_app_dtmgr_msg_info_data_struct * msg_info = m_data->getMsgInfo();
    mmi_sim_enum  sim_id = vapp_mms_convert_mma_sim_to_mmi_sim(msg_info->msg_sim_info);
    if(srv_sim_ctrl_chv1_is_blocked(sim_id))
    {
        mmi_frm_nmgr_balloon(
                                MMI_SCENARIO_ID_MMS_INFO,
                                MMI_EVENT_INFO_BALLOON,
                                MMI_NMGR_BALLOON_TYPE_INFO,
                                (WCHAR*)GetString(STR_GLOBAL_UNAVAILABLE_SIM));
        return;
    }
    if(!srv_mode_switch_is_network_service_available())
    {
        mmi_frm_nmgr_balloon(
                                MMI_SCENARIO_ID_MMS_INFO,
                                MMI_EVENT_INFO_BALLOON,
                                MMI_NMGR_BALLOON_TYPE_INFO,
                                (WCHAR*)GetString(STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE));
        return;
    }

    m_data->resendOnExit(VFX_TRUE);
    VfxMainScr * p_scr = (VfxMainScr *)this->findScreen();
    p_scr->popPage();
}

void VappMmsToolBar::forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vapp_mms_start_uc_struct uc_start;
    mmi_umms_app_dtmgr_msg_info_data_struct * msg_info = m_data->getMsgInfo();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (msg_info->isFollowPhoneMMSContentClass == KAL_FALSE)
    {
        mma_creation_mode_enum creation_mode;

        creation_mode = srv_mms_compose_settings_creation_mode();
        //msg_info->uc_mode = MMA_MODE_FORWARD;
        if (creation_mode == MMA_CREATION_MODE_RESTRICTED)
        {
            VcpConfirmPopup *m_confirmPopup ;
            VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
            m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
            m_confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_MMS_RESTRICTED_MODE));
            m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
            m_confirmPopup->setCustomButton(
                                            VFX_WSTR_RES(STR_ID_VAPP_MMS_CONTINUE), 
                                            VFX_WSTR_RES(STR_GLOBAL_CANCEL), 
                                            VCP_POPUP_BUTTON_TYPE_NORMAL, 
                                            VCP_POPUP_BUTTON_TYPE_CANCEL);
            m_confirmPopup->m_signalButtonClicked.connect(this, &VappMmsToolBar::onForwardPopCallback);
            m_confirmPopup->setAutoDestory(VFX_TRUE);
            m_confirmPopup->show(VFX_TRUE);
        }
        else if (creation_mode == MMA_CREATION_MODE_WARNING)
        {
            VcpConfirmPopup *m_confirmPopup ;
            VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
            m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
            m_confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_MMS_MODE_WARNING_CONFIRM));
            m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
            m_confirmPopup->setCustomButton(
                                            VFX_WSTR_RES(STR_ID_VAPP_MMS_CONTINUE), 
                                            VFX_WSTR_RES(STR_GLOBAL_CANCEL), 
                                            VCP_POPUP_BUTTON_TYPE_NORMAL, 
                                            VCP_POPUP_BUTTON_TYPE_CANCEL);
            m_confirmPopup->m_signalButtonClicked.connect(this, &VappMmsToolBar::onForwardPopCallback);
            m_confirmPopup->setAutoDestory(VFX_TRUE);
            m_confirmPopup->show(VFX_TRUE);

        }
        else
        {
            memset(&uc_start, 0, sizeof(vapp_mms_start_uc_struct));
            uc_start.msg_id = m_msg_id;
            uc_start.uc_mode = MMA_MODE_FORWARD;
            uc_start.sim_id = msg_info->msg_sim_info;;
            uc_start.storage_type = msg_info->storage_location;
            uc_start.uc_type = SRV_UC_STATE_FORWARD;
            uc_start.uc_op = UC_OPERATION_FORWARD;
            uc_start.grp_id = VfxMainScr::findMainScr((VfxFrame *)getParent())->getApp()->getGroupId();
            vapp_mms_start_uc(&uc_start);
        }
    }
    else
    {
        memset(&uc_start, 0, sizeof(vapp_mms_start_uc_struct));
        uc_start.msg_id = m_msg_id;
        uc_start.uc_mode = MMA_MODE_FORWARD;
        uc_start.sim_id = msg_info->msg_sim_info;;
        uc_start.storage_type = msg_info->storage_location;
        uc_start.uc_type = SRV_UC_STATE_FORWARD;
        uc_start.uc_op = UC_OPERATION_FORWARD;
        uc_start.grp_id = VfxMainScr::findMainScr((VfxFrame *)getParent())->getApp()->getGroupId();
        vapp_mms_start_uc(&uc_start);
    }

}
void VappMmsToolBar::onForwardPopCallback(VfxObject *obj, VfxId id)
{
    vapp_mms_start_uc_struct uc_start;
    mmi_umms_app_dtmgr_msg_info_data_struct * msg_info = m_data->getMsgInfo();
    if (id == VCP_CONFIRM_POPUP_BUTTON_YES)
    {
        memset(&uc_start, 0, sizeof(vapp_mms_start_uc_struct));
        uc_start.msg_id = m_msg_id;
        uc_start.uc_mode = MMA_MODE_FORWARD;
        uc_start.sim_id = msg_info->msg_sim_info;;
        uc_start.storage_type = msg_info->storage_location;
        uc_start.uc_type = SRV_UC_STATE_FORWARD;
        uc_start.uc_op = UC_OPERATION_FORWARD;
        uc_start.grp_id = VfxMainScr::findMainScr((VfxFrame *)getParent())->getApp()->getGroupId();
        vapp_mms_start_uc(&uc_start);
    }
}

mmi_ret VappMmsToolBar::onUcClose(mmi_event_struct *evt)
{
    VappMmsToolBar* tool_bar =  (VappMmsToolBar*)VfxObject::handleToObject((evt->user_data));
    if(tool_bar &&  tool_bar->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsToolBar)))
    {
        tool_bar->m_has_register = VFX_FALSE;
        VfxMainScr * p_scr = (VfxMainScr *)tool_bar->findScreen();
        if(p_scr)
        {
            p_scr->popPage();
        }
        mmi_frm_cb_dereg_event(EVT_ID_SRV_UC_MESSAGE_DELETED, VappMmsToolBar::onUcClose, tool_bar);
        }
        return MMI_RET_OK;
}
void VappMmsToolBar::edit(void)
{
    vapp_mms_start_uc_struct uc_start;
    mmi_umms_app_dtmgr_msg_info_data_struct * msg_info = m_data->getMsgInfo();
    if (msg_info->isFollowPhoneMMSContentClass == KAL_FALSE)
    {
        mma_creation_mode_enum creation_mode;
        creation_mode = srv_mms_compose_settings_creation_mode();
        //info->uc_mode = MMA_MODE_EDIT;
        if (creation_mode == MMA_CREATION_MODE_RESTRICTED)
        {
            VcpConfirmPopup *m_confirmPopup ;
            VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
            m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
            m_confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_MMS_RESTRICTED_MODE));
            m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
            m_confirmPopup->setCustomButton(
            VFX_WSTR_RES(STR_ID_VAPP_MMS_CONTINUE), 
            VFX_WSTR_RES(STR_GLOBAL_CANCEL), 
            VCP_POPUP_BUTTON_TYPE_NORMAL, 
            VCP_POPUP_BUTTON_TYPE_CANCEL);
            m_confirmPopup->m_signalButtonClicked.connect(this, &VappMmsToolBar::onEditPopCallback);
            m_confirmPopup->setAutoDestory(VFX_TRUE);
            m_confirmPopup->show(VFX_TRUE);
        }
        else if (creation_mode == MMA_CREATION_MODE_WARNING)
        {
            VcpConfirmPopup *m_confirmPopup ;
            VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
            m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
            m_confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_MMS_MODE_WARNING_CONFIRM));
            m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
            m_confirmPopup->setCustomButton(
            VFX_WSTR_RES(STR_ID_VAPP_MMS_CONTINUE), 
            VFX_WSTR_RES(STR_GLOBAL_CANCEL), 
            VCP_POPUP_BUTTON_TYPE_NORMAL, 
            VCP_POPUP_BUTTON_TYPE_CANCEL);
            m_confirmPopup->m_signalButtonClicked.connect(this, &VappMmsToolBar::onEditPopCallback);
            m_confirmPopup->setAutoDestory(VFX_TRUE);
            m_confirmPopup->show(VFX_TRUE);
        }
        else
        {
            memset(&uc_start, 0, sizeof(vapp_mms_start_uc_struct));
            uc_start.msg_id = m_msg_id;
            uc_start.uc_mode = MMA_MODE_EDIT;
            uc_start.sim_id = MMI_SIM_NONE;
            uc_start.storage_type = msg_info->storage_location;
            uc_start.uc_type = SRV_UC_STATE_EDIT_EXISTED_MSG;
            uc_start.uc_op = UC_OPERATION_EDIT_EXISTED_MSG;
            uc_start.grp_id = VfxMainScr::findMainScr((VfxFrame *)getParent())->getApp()->getGroupId();
            mmi_frm_cb_dereg_event(EVT_ID_SRV_UC_MESSAGE_DELETED, VappMmsToolBar::onUcClose, getObjHandle());
            mmi_frm_cb_reg_event(EVT_ID_SRV_UC_MESSAGE_DELETED, VappMmsToolBar::onUcClose, getObjHandle());
            m_has_register = VFX_TRUE;
            vapp_mms_start_uc(&uc_start);
        }
    }
    else
    {
        memset(&uc_start, 0, sizeof(vapp_mms_start_uc_struct));
        uc_start.msg_id = m_msg_id;
        uc_start.uc_mode = MMA_MODE_EDIT;
        uc_start.sim_id = MMI_SIM_NONE;
        uc_start.storage_type = msg_info->storage_location;
        uc_start.uc_type = SRV_UC_STATE_EDIT_EXISTED_MSG;
        uc_start.uc_op = UC_OPERATION_EDIT_EXISTED_MSG;
        uc_start.grp_id = VfxMainScr::findMainScr((VfxFrame *)getParent())->getApp()->getGroupId();
        mmi_frm_cb_dereg_event(EVT_ID_SRV_UC_MESSAGE_DELETED, VappMmsToolBar::onUcClose, getObjHandle());
        mmi_frm_cb_reg_event(EVT_ID_SRV_UC_MESSAGE_DELETED, VappMmsToolBar::onUcClose, getObjHandle());
        m_has_register = VFX_TRUE;
        vapp_mms_start_uc(&uc_start);
    }
}

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__

void VappMmsToolBar::editTemplate(void)
{
    vapp_mms_start_uc_struct uc_start;
    mmi_umms_app_dtmgr_msg_info_data_struct * msg_info = m_data->getMsgInfo();
    if (msg_info->isFollowPhoneMMSContentClass == KAL_FALSE)
    {
        mma_creation_mode_enum creation_mode;
        creation_mode = srv_mms_compose_settings_creation_mode();
        //info->uc_mode = MMA_MODE_EDIT;
        if (creation_mode == MMA_CREATION_MODE_RESTRICTED)
        {
            VcpConfirmPopup *m_confirmPopup ;
            VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
            m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
            m_confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_MMS_RESTRICTED_MODE));
            m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
            m_confirmPopup->setCustomButton(
            VFX_WSTR_RES(STR_ID_VAPP_MMS_CONTINUE), 
            VFX_WSTR_RES(STR_GLOBAL_CANCEL), 
            VCP_POPUP_BUTTON_TYPE_NORMAL, 
            VCP_POPUP_BUTTON_TYPE_CANCEL);
            m_confirmPopup->m_signalButtonClicked.connect(this, &VappMmsToolBar::oneEditTemplatePopCallback);
            m_confirmPopup->setAutoDestory(VFX_TRUE);
            m_confirmPopup->show(VFX_TRUE);
        }
        else if (creation_mode == MMA_CREATION_MODE_WARNING)
        {
            VcpConfirmPopup *m_confirmPopup ;
            VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
            m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
            m_confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_MMS_MODE_WARNING_CONFIRM));
            m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
            m_confirmPopup->setCustomButton(
            VFX_WSTR_RES(STR_ID_VAPP_MMS_CONTINUE), 
            VFX_WSTR_RES(STR_GLOBAL_CANCEL), 
            VCP_POPUP_BUTTON_TYPE_NORMAL, 
            VCP_POPUP_BUTTON_TYPE_CANCEL);
            m_confirmPopup->m_signalButtonClicked.connect(this, &VappMmsToolBar::oneEditTemplatePopCallback);
            m_confirmPopup->setAutoDestory(VFX_TRUE);
            m_confirmPopup->show(VFX_TRUE);
        }
        else
        {
            memset(&uc_start, 0, sizeof(vapp_mms_start_uc_struct));
            uc_start.msg_id = m_msg_id;
            uc_start.uc_mode = MMA_MODE_EDIT;
            uc_start.sim_id = MMI_SIM_NONE;
            uc_start.storage_type = msg_info->storage_location;
            uc_start.uc_type = SRV_UC_STATE_EDIT_EXISTED_MSG;
            uc_start.uc_op = UC_OPERATION_EDIT_MMS_TEMPLATE;
            uc_start.grp_id = VfxMainScr::findMainScr((VfxFrame *)getParent())->getApp()->getGroupId();
            mmi_frm_cb_dereg_event(EVT_ID_SRV_UC_MESSAGE_DELETED, VappMmsToolBar::onUcClose, getObjHandle());
            mmi_frm_cb_reg_event(EVT_ID_SRV_UC_MESSAGE_DELETED, VappMmsToolBar::onUcClose, getObjHandle());
            m_has_register = VFX_TRUE;
            vapp_mms_start_uc(&uc_start);
        }
    }
    else
    {
        memset(&uc_start, 0, sizeof(vapp_mms_start_uc_struct));
        uc_start.msg_id = m_msg_id;
        uc_start.uc_mode = MMA_MODE_EDIT;
        uc_start.sim_id = MMI_SIM_NONE;
        uc_start.storage_type = msg_info->storage_location;
        uc_start.uc_type = SRV_UC_STATE_EDIT_EXISTED_MSG;
        uc_start.uc_op = UC_OPERATION_EDIT_MMS_TEMPLATE;
        uc_start.grp_id = VfxMainScr::findMainScr((VfxFrame *)getParent())->getApp()->getGroupId();
        mmi_frm_cb_dereg_event(EVT_ID_SRV_UC_MESSAGE_DELETED, VappMmsToolBar::onUcClose, getObjHandle());
        mmi_frm_cb_reg_event(EVT_ID_SRV_UC_MESSAGE_DELETED, VappMmsToolBar::onUcClose, getObjHandle());
        m_has_register = VFX_TRUE;
        vapp_mms_start_uc(&uc_start);
    }
}
void VappMmsToolBar::oneEditTemplatePopCallback(VfxObject *obj, VfxId id)
{
    vapp_mms_start_uc_struct uc_start;
    mmi_umms_app_dtmgr_msg_info_data_struct * msg_info = m_data->getMsgInfo();
    if (id == VCP_CONFIRM_POPUP_BUTTON_YES)
    {
        memset(&uc_start, 0, sizeof(vapp_mms_start_uc_struct));
        uc_start.msg_id = m_msg_id;
        uc_start.uc_mode = MMA_MODE_EDIT;
        uc_start.sim_id = MMI_SIM_NONE;
        uc_start.storage_type = msg_info->storage_location;
        uc_start.uc_type = SRV_UC_STATE_EDIT_EXISTED_MSG;
        uc_start.uc_op = UC_OPERATION_EDIT_MMS_TEMPLATE;
        uc_start.grp_id = VfxMainScr::findMainScr((VfxFrame *)getParent())->getApp()->getGroupId();
        mmi_frm_cb_dereg_event(EVT_ID_SRV_UC_MESSAGE_DELETED, VappMmsToolBar::onUcClose, getObjHandle());
        mmi_frm_cb_reg_event(EVT_ID_SRV_UC_MESSAGE_DELETED, VappMmsToolBar::onUcClose, getObjHandle());
        m_has_register = VFX_TRUE;
        vapp_mms_start_uc(&uc_start);
    }
}
#endif/*__MMI_MMS_TEMPLATE_SUPPORT__*/
void VappMmsToolBar::onEditPopCallback(VfxObject *obj, VfxId id)
{
    vapp_mms_start_uc_struct uc_start;
    mmi_umms_app_dtmgr_msg_info_data_struct * msg_info = m_data->getMsgInfo();
    if (id == VCP_CONFIRM_POPUP_BUTTON_YES)
    {
        memset(&uc_start, 0, sizeof(vapp_mms_start_uc_struct));
        uc_start.msg_id = m_msg_id;
        uc_start.uc_mode = MMA_MODE_EDIT;
        uc_start.sim_id = MMI_SIM_NONE;
        uc_start.storage_type = msg_info->storage_location;
        uc_start.uc_type = SRV_UC_STATE_EDIT_EXISTED_MSG;
        uc_start.uc_op = UC_OPERATION_EDIT_EXISTED_MSG;
        uc_start.grp_id = VfxMainScr::findMainScr((VfxFrame *)getParent())->getApp()->getGroupId();
        mmi_frm_cb_dereg_event(EVT_ID_SRV_UC_MESSAGE_DELETED, VappMmsToolBar::onUcClose, getObjHandle());
        mmi_frm_cb_reg_event(EVT_ID_SRV_UC_MESSAGE_DELETED, VappMmsToolBar::onUcClose, getObjHandle());
        m_has_register = VFX_TRUE;
        vapp_mms_start_uc(&uc_start);
    }
}

void VappMmsToolBar::deleteMsg(void)
{
    mmi_umms_app_dtmgr_msg_info_data_struct * msg_info = m_data->getMsgInfo();
    VfxU16 message;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((srv_mms_bgsr_is_rr_pending(m_msg_id) || msg_info->need_read_report) && (m_box_type == MMA_FOLDER_INBOX)) 
    {
        message = STR_ID_VAPP_MMS_CONFM_DELETE_READ_REPORT_MMS;
    }
    else if((m_box_type == MMA_FOLDER_TEMPLATE) ||(m_box_type == MMA_FOLDER_USRDEF_TEMPLATE))
    {
        message = STR_ID_VAPP_MMS_DELETE_TEMPLATE;
    }
    else
    {
        message = STR_ID_VAPP_MMS_DELETE_CONRM;
    }

    VcpConfirmPopup *m_confirmPopup ;
    VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
    m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
    m_confirmPopup->setText(VFX_WSTR_RES(message));
    m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    m_confirmPopup->setCustomButton(
    VFX_WSTR_RES(STR_GLOBAL_DELETE),
    VFX_WSTR_RES(STR_GLOBAL_CANCEL),
    VCP_POPUP_BUTTON_TYPE_WARNING,
    VCP_POPUP_BUTTON_TYPE_CANCEL);
    m_confirmPopup->m_signalButtonClicked.connect(this, &VappMmsToolBar::onDeletePopCallback);
    m_confirmPopup->setAutoDestory(VFX_TRUE);
    m_confirmPopup->show(VFX_TRUE);
    return ;
}
			
		
void VappMmsToolBar::onDeletePopCallback(VfxObject *obj, VfxId id)
{

    mmi_umms_app_dtmgr_msg_info_data_struct * msg_info = m_data->getMsgInfo();
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        srv_mms_bgsr_msg_box_enum bgsr_folder_id = SRV_MMS_BGSR_FOLDER_NONE;
        VfxU8 error = 0;
        VfxU8 srv_result = 0;
        mma_folder_enum	 folder_id = mma_get_box(m_msg_id);
        U8 bgsr_result = SRV_MMS_BGSR_RESULT_NOT_USED;
        bgsr_folder_id = (srv_mms_bgsr_msg_box_enum)srv_mms_mma_folder_to_bgsr_folder(folder_id);//todo
        switch (folder_id)
        {
            case MMA_FOLDER_OUTBOX:
            case MMA_FOLDER_INBOX:
                bgsr_result = srv_mms_bgsr_change_msg_notify(
                                                                m_msg_id,
                                                                SRV_MMS_BGSR_OP_DELETE,
                                                                bgsr_folder_id,
                                                                NULL,
                                                                msg_info->storage_location);

                if ((bgsr_result != SRV_MMS_BGSR_RESULT_OK) && (bgsr_result != SRV_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND))
                {
                    /* Show Error PopUp */
                    VappMmsPopup popup(STR_GLOBAL_ERROR, VCP_POPUP_TYPE_FAILURE, findScreen(), NULL);           
                    popup.displayPopup();
                }
                else
                {
                    /* Tell MMS Viewer Not to send any Read report req as all the messages will be deleted */

                    // mmi_umms_app_dtmgr_abort_send_read_report(msg_id); todo
                    m_data->MmsAbortSendReadReport(m_msg_id);
                    srv_result = srv_mms_delete_msg(m_msg_id, &error);
                    if(srv_result != SRV_MMS_RESULT_OK)
                    {
                        vapp_mms_show_error_pop_up(MMA_RESULT_FAIL, findScreen());//todo
                        return;
                    }
                    if (error == MMA_RESULT_OK)
                    {
                        /*VappMmsPopup popup(STR_GLOBAL_DELETED, VCP_POPUP_TYPE_SUCCESS, findScreen(), NULL);           
                                        popup.displayPopup();*/
                        VfxMainScr * p_scr = (VfxMainScr *)this->findScreen();
                        p_scr->popPage();
                        srv_mms_show_status_icon();
                    }
                    else
                    {
                        vapp_mms_show_error_pop_up(error, findScreen());/*todo*/
                    }
                }
            break;

            case MMA_FOLDER_ARCHIVE:
                if (msg_info->from_folder == MMA_FOLDER_INBOX)
                {
                    bgsr_result =  srv_mms_bgsr_change_msg_notify(m_msg_id,
                                                                SRV_MMS_BGSR_OP_DELETE,
                                                                bgsr_folder_id,
                                                                NULL,
                                                                msg_info->storage_location);
                    if ((bgsr_result != SRV_MMS_BGSR_RESULT_OK) && (bgsr_result != SRV_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND))
                    {
                        /* Show Error PopUp */
                        VappMmsPopup popup(STR_GLOBAL_ERROR, VCP_POPUP_TYPE_FAILURE, findScreen(), NULL);           
                        popup.displayPopup();
                    }
                    else
                    {
                        /* Tell MMS Viewer Not to send any Read report req as all the messages will be deleted */

                        // mmi_umms_app_dtmgr_abort_send_read_report(msg_id); todo
                        m_data->MmsAbortSendReadReport(m_msg_id);
                        srv_result = srv_mms_delete_msg(m_msg_id, &error);
                        if(srv_result != SRV_MMS_RESULT_OK)
                        {
                            vapp_mms_show_error_pop_up(MMA_RESULT_FAIL, findScreen());/*todo*/
                            return;
                        }
                        if (error == MMA_RESULT_OK)
                        {
                            /*VappMmsPopup popup(STR_GLOBAL_DELETED, VCP_POPUP_TYPE_SUCCESS, findScreen(), NULL);           
                                                popup.displayPopup();*/
                            VfxMainScr * p_scr = (VfxMainScr *)this->findScreen();
                            p_scr->popPage();
                            srv_mms_show_status_icon();
                        }
                        else
                        {
                            vapp_mms_show_error_pop_up(error, findScreen());/*todo*/
                        }
                    }
                break;
                }

        #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
            case MMA_FOLDER_USRDEF_TEMPLATE:
            case MMA_FOLDER_TEMPLATE:
            //mmi_umms_app_dtmgr_reset_template_list_data();  todo
        #endif/*__MMI_MMS_TEMPLATE_SUPPORT__*/
            default:
                srv_result = srv_mms_delete_msg(m_msg_id, &error);
                if(srv_result != SRV_MMS_RESULT_OK)
                {
                    vapp_mms_show_error_pop_up(MMA_RESULT_FAIL, findScreen());/*todo*/
                    return;
                }
                if (error == MMA_RESULT_OK)
                {
                    /*VappMmsPopup popup(STR_GLOBAL_DELETED, VCP_POPUP_TYPE_SUCCESS, this, (clickOk)&VappMmsToolBar::onClickOk);           
                                popup.displayPopup();*/
                    VfxMainScr * p_scr = (VfxMainScr *)this->findScreen();
                    p_scr->popPage();
                    srv_mms_show_status_icon();

                }
                else
                {
                    vapp_mms_show_error_pop_up(error, findScreen()); /*todo*/
                }
            break;
        }
    }

}

/*void VappMmsToolBar::onClickOk(VfxObject* obj, VfxId id)
{
    VfxMainScr * p_scr = (VfxMainScr *)this->findScreen();
					p_scr->popPage();
                   
                    srv_mms_show_status_icon();
           
}*/

void VappMmsToolBar::onClickCmdBtn(VfxObject *obj, VfxId btn_id)
{
    m_btn_id = btn_id;
    switch(btn_id)
    {
    #ifdef __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__
        case COPY_MMS_TO_ARCHIVE:
        copyToArchive();
        break;
    #endif/*__MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__*/			
        case COPY_MMS_TO_CARD:
        copyToMemoryCard();
        break; 
    #ifndef __COSMOS_NO_USER_DRIVE__    
        case COPY_MMS_TO_PHONE:
        copyToPhone();
        break;
    #endif /*__COSMOS_NO_USER_DRIVE__*/
        case COPY_MMS_TO_CANCEL:
        break;
    }	
}
#ifdef __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__
void VappMmsToolBar::copyToArchive(void)
{
    mmi_umms_app_dtmgr_msg_info_data_struct * msg_info = m_data->getMsgInfo();
    srv_mms_copy_to_archive_req_struct req;
    memset(&req,0, sizeof(srv_mms_copy_to_archive_req_struct));
    req.user_data = (S32)getObjHandle();                 
    req.call_back = copyCbHdlr;      
    req.msg_id = m_msg_id;                         
    req.app_id =  MMA_APP_ID_MMS_APP;                         
    srv_mms_copy_to_archive(&req);
    VFX_OBJ_CREATE(m_popup,VcpIndicatorPopup,this);
    // Activity Indicator Popup without Cancel Button
    m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    m_popup->setText(VFX_WSTR_RES(STR_GLOBAL_COPYING));
    m_popup->show(VFX_TRUE);
    //s_op_type = (VfxU8)COPY_MMS_TO_ARCHIVE;
}
void VappMmsToolBar::copyCbHdlr(srv_mms_result_enum result, void *rsp_data, void* user_data)
{
	VappMmsToolBar *toolbar = (VappMmsToolBar *)VfxObject::handleToObject((VfxObjHandle)user_data);

	if(toolbar && toolbar->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsToolBar)))
	{
		VFX_OBJ_CLOSE(toolbar->m_popup);
		srv_mms_copy_to_archive_rsp_struct *rsp = (srv_mms_copy_to_archive_rsp_struct *)rsp_data;
		if(rsp->result == MMA_RESULT_OK)
		{
			mmi_frm_nmgr_balloon(
			MMI_SCENARIO_ID_MMS_INFO,
			MMI_EVENT_INFO_BALLOON,
			MMI_NMGR_BALLOON_TYPE_SUCCESS,
			(WCHAR*)GetString(STR_ID_VAPP_MMS_COPIED_TO_ARCHIVE));
			return;
		}
		else
		{
			vapp_mms_show_error_pop_up(rsp->result,(VfxScreen *)toolbar->findScreen());
			return;
		}
	}
}	
#endif/*__MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__*/
#ifndef __COSMOS_NO_USER_DRIVE__  
void VappMmsToolBar::copyTo(void)
{
    VcpCommandPopup * cmd_popup;
    mmi_umms_app_dtmgr_msg_info_data_struct * msg_info = m_data->getMsgInfo();
    VFX_OBJ_CREATE(cmd_popup, VcpCommandPopup, this);
    //cmd_popup->setSize(getSize().width,cmd_popup->getSize().height);
    cmd_popup->setAlignParent(VFX_FRAME_ALIGNER_SIDE_LEFT, VFX_FRAME_ALIGNER_MODE_SIDE);
    cmd_popup->setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT, VFX_FRAME_ALIGNER_MODE_SIDE);
    /*cmd_popup->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);*/
    cmd_popup->setInfoType(VCP_POPUP_TYPE_INFO);
    cmd_popup->setText(VFX_WSTR_RES(STR_ID_VAPP_MMS_COPY_MESSAGES));
#ifdef __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__
    if((m_box_type == MMA_FOLDER_INBOX)||(m_box_type == MMA_FOLDER_SENT))
    {
        cmd_popup->addItem(COPY_MMS_TO_ARCHIVE, VFX_WSTR_RES(STR_ID_VAPP_MMS_ARCHIVE));
    }
#endif/*__MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__*/
    if(msg_info->storage_location == MMA_MSG_STORAGE_PHONE)
    {
        cmd_popup->addItem(COPY_MMS_TO_CARD, VFX_WSTR_RES(STR_GLOBAL_MEMORY_CARD));
        if (!(FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) == FS_NO_ERROR))
        {
            cmd_popup->disableItem(COPY_MMS_TO_CARD);
        }
    }
#ifndef __COSMOS_NO_USER_DRIVE__   
    else
    {
        cmd_popup->addItem(COPY_MMS_TO_PHONE, VFX_WSTR_RES(STR_GLOBAL_PHONE));
    }
#endif/*__COSMOS_NO_USER_DRIVE__*/
    cmd_popup->addItem(COPY_MMS_TO_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
    cmd_popup->setAutoDestory(VFX_TRUE);
    cmd_popup->m_signalButtonClicked.connect(this, &VappMmsToolBar::onClickCmdBtn);
    cmd_popup->show(VFX_TRUE);    
}
void VappMmsToolBar::copyToPhone(void)
{
    mmi_umms_app_dtmgr_msg_info_data_struct * msg_info = m_data->getMsgInfo();
    srv_mms_change_msg_storage(MMA_MMS_STORAGE_ACTION_COPY_MMS, msg_info->storage_location, m_msg_id);
    VFX_OBJ_CREATE(m_popup,VcpIndicatorPopup,this);
    // Activity Indicator Popup without Cancel Button
    m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    m_popup->setText(VFX_WSTR_RES(STR_GLOBAL_COPYING));
    m_popup->show(VFX_TRUE);
    //s_op_type =  (VfxU8)COPY_MMS_TO_PHONE;
}
#endif/*__COSMOS_NO_USER_DRIVE__*/
void VappMmsToolBar::copyToMemoryCard(void)
{
    mmi_umms_app_dtmgr_msg_info_data_struct * msg_info = m_data->getMsgInfo();
    if (!(FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) == FS_NO_ERROR))
    {
        VappMmsPopup popup(STR_GLOBAL_NOT_AVAILABLE, VCP_POPUP_TYPE_FAILURE, this, NULL);           
        popup.displayPopup();
        return;
    }
    srv_mms_change_msg_storage(MMA_MMS_STORAGE_ACTION_COPY_MMS, msg_info->storage_location, m_msg_id);
    VFX_OBJ_CREATE(m_popup,VcpIndicatorPopup,this);
    // Activity Indicator Popup without Cancel Button
    m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    m_popup->setText(VFX_WSTR_RES(STR_GLOBAL_COPYING));
    m_popup->show(VFX_TRUE);
    //s_op_type =  (VfxU8)COPY_MMS_TO_CARD;
}


mmi_ret VappMmsToolBar::listener(mmi_event_struct* evt)
{
    srv_mms_base_event_struct* param =  (srv_mms_base_event_struct*) evt;
    VappMmsToolBar* tool_bar =  (VappMmsToolBar *)VfxObject::handleToObject((VfxObjHandle)param->user_data);
    wap_mma_change_msg_storage_rsp_struct * rsp =  (wap_mma_change_msg_storage_rsp_struct*)  param->sender_data;
    if(tool_bar && tool_bar->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsToolBar)))
    {
        VFX_OBJ_CLOSE(tool_bar->m_popup);
        if(tool_bar->m_msg_id == rsp->msg_id)
        {
            if(rsp->result == MMA_RESULT_OK)
            {
                VfxU16 txt;
                if(tool_bar->m_btn_id == (VfxId)COPY_MMS_TO_PHONE)
                {
                    txt = STR_ID_VAPP_MMS_COPIED_TO_PHONE;
                }
                else 
                {
                    txt = STR_ID_VAPP_MMS_COPIED_TO_CARD;
                }
                mmi_frm_nmgr_balloon(
                                    MMI_SCENARIO_ID_MMS_INFO,
                                    MMI_EVENT_INFO_BALLOON,
                                    MMI_NMGR_BALLOON_TYPE_SUCCESS,
                                    (WCHAR*)GetString(txt));
            }
            else
            {
                vapp_mms_show_error_pop_up(rsp->result,(VfxScreen *)tool_bar->findScreen());
            }
            return MMI_RET_OK;
        }
    }
    return MMI_RET_OK;
}

void VappMmsToolBar::viewObjects(void)
{
    VappMmsViewObjectsPage *m_view_objects;
    VFX_OBJ_CREATE_EX(m_view_objects, VappMmsViewObjectsPage, this->getMainScr(), (m_data->getMyIndex()));
    this->getMainScr()->pushPage(0, m_view_objects);
}
#ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
void VappMmsToolBar::useDetails(void)
{
    VappMmsUseDetailsPage *m_use_details;
    VFX_OBJ_CREATE_EX(m_use_details, VappMmsUseDetailsPage, this->getMainScr(), (m_data->getMyIndex(), m_data->getMsgInfo()->msg_sim_info));
    this->getMainScr()->pushPage(0, m_use_details);
}
#endif/*__MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__*/

void VappMmsToolBar::onFolding(VfxObject* sender, VfxBool is_fold)
{//

}

#ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__
void VappMmsToolBar::reports(void) 
{
    VappMMSReportsPage  *mmsReportsPage;
    VFX_OBJ_CREATE_EX(mmsReportsPage, VappMMSReportsPage, getMainScr(),(m_data));
    getMainScr()->pushPage(0, mmsReportsPage);
}
#endif/*__MMI_MMS_REPORT_STATUS_SUPPORT__*/

void * VappMmsToolBar::allocMem(U32 size, void *user_data)
{
    void *mem = NULL;
    VappMmsToolBar *my_data = (VappMmsToolBar *)user_data;
    if(my_data->isValid() && my_data->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsToolBar)) )
    {
        VFX_ALLOC_MEM(mem, size, my_data);
    }
    return mem;
}

void  VappMmsToolBar::freeMem(void *mem)
{
	VFX_FREE_MEM(mem);
}


#ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__
VFX_IMPLEMENT_CLASS("VappMMSReportsPage", VappMMSReportsPage, VfxPage);

void VappMMSReportsPage::onInit()
{
    mmi_umms_app_dtmgr_msg_info_data_struct * info = m_data->getMsgInfo();
    VfxPage::onInit(); // call base class
    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_MMS_REPORTS));
    //titleBar->setSubtitle(VFX_WSTR("Test Subtitle\!"));
    this->setTopBar(m_titleBar); 
    VFX_OBJ_CREATE(m_menu, VcpListMenu, this);
    m_menu->setPos(0,0);
    //m_menu->setSize(320, 480);    
    m_menu->setSize(getSize());
    m_menu->setContentProvider(this);
    if(info->need_delivery_report || info->need_read_report)
    {
        m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_TRIPLE_TEXT);
    }
    else
    {
        m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    }
    m_menu->updateItem(0);
    m_menu->setAlignParent(
                            VFX_FRAME_ALIGNER_MODE_SIDE, 
                            VFX_FRAME_ALIGNER_MODE_SIDE, 
                            VFX_FRAME_ALIGNER_MODE_SIDE, 
                            VFX_FRAME_ALIGNER_MODE_SIDE);
}
VfxBool VappMMSReportsPage::getItemIsHighlightable(
        VfxU32 index       // [IN] the index of item
        ) const
{
	return VFX_FALSE;
}
VfxBool VappMMSReportsPage::getMenuEmptyText(
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        ) 
{

	text = VfxWString(VFX_WSTR_RES(STR_ID_VAPP_MMS_NO_REPORTS));
	color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    return VFX_TRUE;
}

void  VappMMSReportsPage::onDeinit()
{
    wap_mma_mms_msg_report_status_struct *temp;
    if(m_list)
    {
        while(m_list)
        {
            temp = m_list;
            m_list = m_list->next;
            VFX_FREE_MEM(temp);
            temp = NULL;
        }
        m_list = NULL;
    }
    VfxPage::onDeinit(); // call base class
}

void VappMMSReportsPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
	//return param.rotateTo;
}

VfxU32 VappMMSReportsPage::getCount()  const
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    VfxU32 count = 0;
    mmi_umms_app_dtmgr_msg_info_data_struct * info = m_data->getMsgInfo();
    mma_result_enum  result ;
    wap_mma_mms_msg_report_status_struct *temp= NULL,*list= NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!(info->need_delivery_report || info->need_read_report))
    {
        return 0;
    }
    if(m_list == NULL)
    {
        list = (wap_mma_mms_msg_report_status_struct*) srv_mms_mem_mgr_app_asm_alloc(sizeof(wap_mma_mms_msg_report_status_struct));
        MMI_ASSERT(list);
        result = mma_mms_get_msg_report_status_info(m_data->getMsgId(), list, srv_mms_mem_mgr_app_asm_alloc, srv_mms_mem_mgr_app_asm_free);
        //COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_UMMS_RR_DR_GET_DATA_1, info->msg_id, scr_id, result);
        if(result != MMA_RESULT_OK)
        {
            if(list)
            {
                while(list)
                {
                    temp = list;
                    list = list->next;
                    srv_mms_mem_mgr_app_asm_free(temp);
                    temp = NULL;
                }
            }
            return 0;
        }
        temp = list;
    }
    else
    {
        list =  m_list;
    }
    while(list)
    {
        if((list->dr_status == MMA_DR_STATUS_PENDING) && (list->rr_status == MMA_RR_STATUS_PENDING))
        {
            list = list->next;
            continue;
        }
        else 
        {
            if(list->dr_status != MMA_DR_STATUS_PENDING)
            {
                count++;
            }
            if(list->rr_status != MMA_RR_STATUS_PENDING)
            {
                count++;
            }
        }
        list = list->next;
    }

    if(m_list == NULL)
    {
        list = temp;
        if(list)
        {
            while(list)
            {
                temp = list;
                list = list->next;
                srv_mms_mem_mgr_app_asm_free(temp);
                temp = NULL;
            }
        }
    }
    return count;
}


VfxBool VappMMSReportsPage::getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        )
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    VfxU32 count = 0;
    S8 name[MMA_MAX_ADDR_LEN + 40];
    mmi_umms_app_dtmgr_msg_info_data_struct * info = m_data->getMsgInfo();
    mma_result_enum  result ;
    VfxU16 str_id = 0;
    MMI_BOOL is_found = MMI_FALSE;
    VfxBool is_DR = VFX_FALSE;
    wap_mma_mms_msg_report_status_struct* list = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(m_list == NULL)
    {
        m_list = (wap_mma_mms_msg_report_status_struct*) srv_mms_mem_mgr_app_asm_alloc(sizeof(wap_mma_mms_msg_report_status_struct));
        MMI_ASSERT(m_list);
        result = mma_mms_get_msg_report_status_info(m_data->getMsgId(), m_list, srv_mms_mem_mgr_app_asm_alloc, srv_mms_mem_mgr_app_asm_free);
        //COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_UMMS_RR_DR_GET_DATA_1, info->msg_id, scr_id, result);
        if(result != MMA_RESULT_OK)
        {
            wap_mma_mms_msg_report_status_struct *temp;
            if(m_list)
            {
                while(m_list)
                {
                    temp = m_list;
                    m_list = m_list->next;
                    srv_mms_mem_mgr_app_asm_free(temp);
                    temp = NULL;
                }
                m_list = NULL;
            }
            return VFX_FALSE;
        }
    }
    list = m_list;
    while(list)
    {
        if((list->dr_status == MMA_DR_STATUS_PENDING) && (list->rr_status == MMA_RR_STATUS_PENDING))
        {
            list = list->next;
            continue;
        }
        else 
        {
            if(list->rr_status != MMA_RR_STATUS_PENDING)
            {
                if(count >= index)
                {
                    is_DR = MMI_FALSE;
                    break;
                }
                count++;
            }
            if(list->dr_status != MMA_DR_STATUS_PENDING)
            {
                if(count >= index)
                {
                    is_DR = VFX_TRUE;
                    break;
                }
                count++;
            }
        }
        list = list->next;
    }
    if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {	
        if(!(info->need_delivery_report || info->need_read_report))
        {
            text.loadFromRes(STR_ID_VAPP_MMS_NO_REPORTS);
            return VFX_TRUE;
        }
        if (list->addr_type == MMA_ADDR_TYPE_PHONE_NUMBER)
        {
            memset(name, 0, MMA_MAX_ADDR_LEN + 40);    
            is_found = srv_phb_get_name_by_number(list->address, (U16*)name, (MMA_MAX_ADDR_LEN + 40)/2 - 1);
            if((is_found == MMI_FALSE)||((name[0] == 0) && (name[1] == 0)))
            {
                text.loadFromMem(list->address);
            }
            else
            {
                text.loadFromMem((VfxWChar *)name);
            }
        }
        else
        {
            text.loadFromMem(list->address);
        }

        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        return VFX_TRUE;
    }

    if(fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {								
        if(info->need_delivery_report && info->need_read_report)
        {
            if(is_DR)
            {
                str_id = vapp_mms_get_string_for_msg_dr_status(list->dr_status);

            }
            else
            {
                str_id = vapp_mms_get_string_for_msg_rr_status(list->rr_status);
            }
        }
        else if(info->need_delivery_report && !(info->need_read_report))
        {
            str_id = vapp_mms_get_string_for_msg_dr_status(list->dr_status);
        }
        else if(!(info->need_delivery_report) && info->need_read_report)
        {
            str_id = vapp_mms_get_string_for_msg_rr_status(list->rr_status);
        }
        else 
        {
            return VFX_FALSE;
        }
        text = VFX_WSTR_RES(str_id);
        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        return VFX_TRUE;
    }
    return VFX_FALSE;
}
#endif/*__MMI_MMS_REPORT_STATUS_SUPPORT__*/
#endif /* __MMI_MMS_2__  */
