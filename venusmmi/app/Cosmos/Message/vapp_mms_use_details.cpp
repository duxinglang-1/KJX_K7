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
 *  vapp_mms_viewer.cpp
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
#include "UCMGProt.h"
#include "UcmSrvGprot.h"
#include "MmsMemoryManagerSrv.h"
#include "Conversions.h"
#include "EmailAppGProt.h"
#include "PhbSrvGprot.h"
#include "Dialercuigprot.h"
#include "Wapadp.h"
#include "browser_api.h"  
#include "mmi_inet_app_trc.h"
}
#include "vapp_uc_gprot.h"
#include "vcui_dialer_gprot.h"
#include "vcui_phb_gprot.h"
#include "vadp_mmi_frm.h"
#include "vfx_uc_include.h"
#include "../xml/vfx_xml_loader.h"
#include "vcp_text_view.h"
#include "vcp_app_scr.h"
#include "vapp_mms_data.h"
#include "vapp_mms_use_details.h"
#include "vapp_mms_viewer.h"
#include "vapp_mms_appcore.h"
#include "vcp_include.h"
#include "ui_core\mvc\vfx_mmi.h"

#include "vcp_status_icon_bar.h"
#include "vcp_page_panel.h"
#include "vcp_list_menu.h"
#include "vcp_popup.h"
#include "vcp_image_button.h"

#if defined( __MMI_VUI_SAVE_BOOKMARK_SUPPORT__) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
#include "vcui_bookmark_gprot.h"
#endif
#ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__

VFX_IMPLEMENT_CLASS("VappMmsUseDetailsPage", VappMmsUseDetailsPage, VfxPage);
void VappMmsUseDetailsPage::onInit()
{
	VfxPage::onInit();
	VFX_OBJ_CREATE(m_use_details, VappMmsUseDetails, this);
	if(m_use_details->getUseDetailsFromSrv() == VFX_FALSE)
	{
		return;
	}
	VfxXmlLoader::loadBegin(this, VENUS_MMS_LAYOUT_MMS_USE_DETAILS);
	m_list = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("UseDetailsList")), VcpListMenu);
	m_list->setContentProvider(this);
	m_list->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_FALSE); 
	m_list->m_signalItemTapped.connect(this, &VappMmsUseDetailsPage::onUseDetialTapped);
	m_list->m_signalCmdButtonClicked.connect(this, &VappMmsUseDetailsPage::onClickLaunchers);
	m_list->setSize(getSize());
	m_list->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE);
	VfxXmlLoader::loadEnd();
	
}

void VappMmsUseDetailsPage::onClickLaunchers(VcpListMenu *list, // Sender
        VfxU32  index)
{
    applib_address_node_struct *node;
    node = m_use_details->getUseDetailsNode(index);
    VappMmsUseDetailHandler *useDetailHdlr = NULL;
    VfxFrame *childFrame = getLastChildFrame();
    while(childFrame != NULL)
    {
        if(childFrame->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsUseDetailHandler)))
        {
            VFX_OBJ_CLOSE(childFrame);
            break;
        }
        childFrame = childFrame->getPrevFrame();
    }
    if(node->dataType == APPLIB_ADDR_TYPE_PHONENUMBER)
    {
        VFX_OBJ_CREATE_EX(useDetailHdlr, VappMmsUseDetailHandler, this, (node->data2, node->dataType, m_sim));
    }
    else
    {
        VFX_OBJ_CREATE_EX(useDetailHdlr, VappMmsUseDetailHandler, this, (node->data, node->dataType, m_sim));
    }
    switch(node->dataType)
    {
        case APPLIB_ADDR_TYPE_PHONENUMBER:
            useDetailHdlr->call();
        break;
        case APPLIB_ADDR_TYPE_EMAIL:
            useDetailHdlr->SendEmail();
        break;
        case APPLIB_ADDR_TYPE_URL:
            useDetailHdlr->goToUrl();
        break;
    }  
}
VfxBool VappMmsUseDetailsPage::getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc &image)
{
    applib_address_node_struct *node;
    VfxU16 n = 0, p = 0, d = 0;
    node = m_use_details->getUseDetailsNode(index);
    switch(node->dataType)
    {
        case APPLIB_ADDR_TYPE_PHONENUMBER:
        {
            n = IMG_ID_VENUS_MMS_SIM_CALL_N; 
            p =	IMG_ID_VENUS_MMS_SIM_CALL_P;
            d = IMG_ID_VENUS_MMS_SIM_CALL_D;
        }
        break;
        case APPLIB_ADDR_TYPE_EMAIL:
        {
            n = IMG_ID_VENUS_MMS_LAUNCH_EMAIL_N; 
            p =	IMG_ID_VENUS_MMS_LAUNCH_EMAIL_P;
            d = IMG_ID_VENUS_MMS_LAUNCH_EMAIL_D;
        }
        break;
        case APPLIB_ADDR_TYPE_URL:
        {
            n = IMG_ID_VENUS_MMS_GO_TO_URL_N; 
            p =	IMG_ID_VENUS_MMS_GO_TO_URL_P;
            d = IMG_ID_VENUS_MMS_GO_TO_URL_D;
        }
        break;
    }   
    switch(fieldType)
    {
        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL:
            image.setResId(n);
        break;
        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED:
            image.setResId(p);
        break;
        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED:
            image.setResId(d);
        break;

    }
    return VFX_TRUE;
}


void VappMmsUseDetailsPage::onDeInit(void)
{
	VfxPage::onDeinit();
}

VfxBool VappMmsUseDetailsPage::getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        ) 
 {
		VfxWString txt;
		applib_address_node_struct *node;
		node = m_use_details->getUseDetailsNode(index);
		text.loadFromMem((VfxU16 *)node->data);
		m_hilited_index = index;
		return VFX_TRUE;
 }

void VappMmsUseDetailsPage::onUseDetialTapped(VcpListMenu *listmenu, VfxU32 index)
{
    applib_address_node_struct *node = m_use_details->getUseDetailsNode(index);
    VcpCommandPopup *m_commandPopup;
    VFX_OBJ_CREATE(m_commandPopup, VcpCommandPopup, this);
    VappMmsUseDetailHandler *useDetailHdlr = NULL;
    VfxFrame *childFrame = getLastChildFrame();
    while(childFrame != NULL)
    {
        if(childFrame->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsUseDetailHandler)))
        {
            VFX_OBJ_CLOSE(childFrame);
            break;
        }
        childFrame = childFrame->getPrevFrame();
    }
    if(node->dataType == APPLIB_ADDR_TYPE_PHONENUMBER)
    {
        VFX_OBJ_CREATE_EX(useDetailHdlr, VappMmsUseDetailHandler, this, (node->data2, node->dataType, m_sim));
    }
    else
    {
        VFX_OBJ_CREATE_EX(useDetailHdlr, VappMmsUseDetailHandler, this, (node->data, node->dataType, m_sim));
    }
    m_commandPopup->setAutoDestory(VFX_TRUE);
    VfxWString title1;
    title1.loadFromMem(node->data);
    m_commandPopup->setInfoType(VCP_POPUP_TYPE_INFO);
    m_commandPopup->setText(title1);
	switch(node->dataType)
    {
        case APPLIB_ADDR_TYPE_PHONENUMBER:
            //BD Comment*if Edit Before Call is already provided when tap for call, no need to show in the list*
            //m_commandPopup->addItem(VAPP_MMS_USE_DETAILS_ADDRESSES_EDIT_BEFORE_CALL, VFX_WSTR_RES(STR_ID_VAPP_MMS_EDIT_BEFORE_CALL));
            m_commandPopup->addItem(VAPP_MMS_USE_DETAILS_SEND_MESSAGE, VFX_WSTR_RES(STR_ID_VAPP_MMS_SEND_MESSAGE));
            m_commandPopup->addItem(VAPP_MMS_USE_DETAILS_ADDRESSES_NEW_CONTACT, VFX_WSTR_RES(STR_ID_VAPP_MMS_ADD_AS_NEW_CONTACT));
            m_commandPopup->addItem(VAPP_MMS_USE_DETAILS_ADDRESSES_SAVE_TO_PHBOOK, VFX_WSTR_RES(STR_ID_VAPP_MMS_ADD_AS_EXISTING_CONTACT));
            m_commandPopup->m_signalButtonClicked.connect(useDetailHdlr,&VappMmsUseDetailHandler::VappMmsUseNumberCb);
        break;
        case APPLIB_ADDR_TYPE_EMAIL:
            m_commandPopup->addItem(VAPP_MMS_USE_DETAILS_SEND_EMAIL, VFX_WSTR_RES(STR_ID_VAPP_MMS_SEND_EMAIL));
            m_commandPopup->addItem(VAPP_MMS_USE_DETAILS_ADDRESSES_NEW_CONTACT, VFX_WSTR_RES(STR_ID_VAPP_MMS_ADD_AS_NEW_CONTACT));
            m_commandPopup->addItem(VAPP_MMS_USE_DETAILS_ADDRESSES_SAVE_TO_PHBOOK, VFX_WSTR_RES(STR_ID_VAPP_MMS_ADD_AS_EXISTING_CONTACT));
            m_commandPopup->m_signalButtonClicked.connect(useDetailHdlr,&VappMmsUseDetailHandler::VappMmsUseEmailCb);
        break;
        case APPLIB_ADDR_TYPE_URL:
            m_commandPopup->m_signalButtonClicked.connect(useDetailHdlr,&VappMmsUseDetailHandler::VappMmsUseUrlCb);
            m_commandPopup->addItem(VAPP_MMS_USE_DETAILS_ADDRESSES_GO_TO, VFX_WSTR_RES(STR_ID_VAPP_MMS_GO_TO_URL));
        #if defined( __MMI_VUI_SAVE_BOOKMARK_SUPPORT__) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
            m_commandPopup->addItem(VAPP_MMS_USE_DETAILS_ADDRESSES_ADD_BOOKMARK, VFX_WSTR_RES(STR_ID_VAPP_MMS_SAVE_TO_BOOKMARK));
        #endif/*__MMI_VUI_SAVE_BOOKMARK_SUPPORT__,__MMI_BRW_BKM_INTERFACE_SUPPORT__*/
        break;
        default:
        ASSERT(0);
    }
	m_commandPopup->addItem(VAPP_MMS_USE_DETAILS_TOTAL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
	m_commandPopup->setAutoDestory(VFX_TRUE);
	m_commandPopup->show(VFX_TRUE);
}

// Get the item count of the a group
VfxU32 VappMmsUseDetailsPage::getCount(void) const
{
	VfxU32 count = m_use_details->getUseDetailsCount();
	return count;
}

VfxBool VappMmsUseDetailsPage::onKeyInput(VfxKeyEvent &event)
{
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            if (event.keyCode == VFX_KEY_CODE_2)
            {
                getMainScr()->popPage();
                return VFX_TRUE;
            }
        }
		return VfxPage::onKeyInput(event);
}

void VappMmsUseDetailsPage::onEnter(VfxBool isBackward)
{
	VfxPage::onEnter(isBackward);
	if(isBackward && (m_srv_index != 0))
	{
		srv_mms_mem_mgr_copy_pools(m_srv_index, APPLIB_MEM_AP_ID_MMS_VIEWER);  
		//m_list->setVisibleMenuRegion(-1, m_hilited_index, VFX_FALSE);
	}
}
void VappMmsUseDetailsPage::onRotate(const VfxScreenRotateParam &param)
{
	//m_list->setVisibleMenuRegion(-1, m_hilited_index, VFX_FALSE);
}
void VappMmsUseDetailsPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
	//return param.rotateTo;
}
#endif /*__MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__*/
VFX_IMPLEMENT_CLASS("VappMmsUseDetailHandler", VappMmsUseDetailHandler, VfxFrame);
void VappMmsUseDetailHandler::VappMmsUseNumberCb(VfxObject *obj, VfxId id)
{
    m_operation = (vapp_mms_use_detail_enum)id;
    switch(id)
    {
        case VAPP_MMS_USE_DETAILS_ADDRESSES_NEW_CONTACT:
            useCui();
        break;
        case VAPP_MMS_USE_DETAILS_ADDRESSES_SAVE_TO_PHBOOK:
            useCui();
        break;
        case VAPP_MMS_USE_DETAILS_SEND_MESSAGE:
            useCui();
        break;
        case VAPP_MMS_USE_DETAILS_ADDRESSES_EDIT_BEFORE_CALL:
            useCui();
        break;
    }
}

void VappMmsUseDetailHandler::onDeinit(void)
{
	VfxFrame::onDeinit();
	if(m_string)
	{
		VFX_FREE_MEM(m_string);
		m_string = NULL;
	}
}
void VappMmsUseDetailHandler::VappMmsUseEmailCb(VfxObject *obj, VfxId id)
{
    m_operation = (vapp_mms_use_detail_enum)id;
    switch(id)
    {
        case VAPP_MMS_USE_DETAILS_SEND_EMAIL:
            SendEmail();
        break;
        case VAPP_MMS_USE_DETAILS_ADDRESSES_SAVE_TO_PHBOOK:
            useCui();
        break;
        case VAPP_MMS_USE_DETAILS_ADDRESSES_NEW_CONTACT:
            useCui();
        break;
    }
}

void VappMmsUseDetailHandler::VappMmsUseUrlCb(VfxObject *obj, VfxId id)
{
    m_operation = (vapp_mms_use_detail_enum)id;
    switch(id)
    {
        case VAPP_MMS_USE_DETAILS_ADDRESSES_GO_TO:
            goToUrl();
        break;
    #if defined( __MMI_VUI_SAVE_BOOKMARK_SUPPORT__) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
        case VAPP_MMS_USE_DETAILS_ADDRESSES_ADD_BOOKMARK:
            saveToBookmark();
        break;
    #endif/*__MMI_VUI_SAVE_BOOKMARK_SUPPORT__,__MMI_BRW_BKM_INTERFACE_SUPPORT__*/
    }
}

VappMmsUseDetailHandler::VappMmsUseDetailHandler(U16 *data, VfxS32 len, U16 mode, VfxU8 sim = 0)
{
    kal_wchar *m_text;
    U16  *m_temp;
    m_string =  (U16*) srv_mms_mem_mgr_viewer_asm_alloc((len + 1)  * ENCODING_LENGTH);
    ASSERT(m_string);
    memset(m_string, 0, (len + 1) * ENCODING_LENGTH);
    mmi_ucs2ncpy((S8 *)m_string, (S8 *)data, len);
    m_type = mode;
    m_sim = sim;
    if(mode == APPLIB_ADDR_TYPE_PHONENUMBER)
    {
        m_text =  (kal_wchar*) srv_mms_duplicate_phoneno_no_written_sep(
                                                                        srv_mms_mem_mgr_viewer_asm_alloc,
                                                                        m_string);
        m_temp = m_text;
        m_text = m_string;
        m_string = m_temp;
        VFX_FREE_MEM(m_text);
        m_text = NULL;
    }	
}

VappMmsUseDetailHandler::VappMmsUseDetailHandler(U16 *data, U16 mode, VfxU8 sim = 0)
{
    VfxU32 len = mmi_ucs2strlen((PS8)data);
    m_string =  (U16*) srv_mms_mem_mgr_viewer_asm_alloc((len + 1)  * ENCODING_LENGTH);
    ASSERT(m_string);
    memset(m_string, 0, (len + 1) * ENCODING_LENGTH);
    mmi_ucs2ncpy((S8 *)m_string, (S8 *)data, len);
    m_type = mode;
    m_sim = sim;
}

void VappMmsUseDetailHandler::useCui(void)
{
    mmi_id grpId = VfxMainScr::findMainScr((VfxFrame *)getParent())->getApp()->getGroupId();
    switch(m_operation)
    {
        case VAPP_MMS_USE_DETAILS_ADDRESSES_NEW_CONTACT:
        case VAPP_MMS_USE_DETAILS_ADDRESSES_SAVE_TO_PHBOOK:
        {
            vcui_phb_save_contact_type_enum type = m_operation == VAPP_MMS_USE_DETAILS_ADDRESSES_NEW_CONTACT ? VAPP_PHB_SAVE_CONTACT_NEW : VAPP_PHB_SAVE_CONTACT_REPLACE;
            m_curr_cui_id = vcui_phb_contact_saver_create(grpId);
            if(m_curr_cui_id != GRP_ID_INVALID)
            {
                mmi_frm_group_set_caller_proc(m_curr_cui_id, &VappMmsUseDetailHandler::handleCuiProc, (void*)getObjHandle());
                vcui_phb_contact_saver_set_type(m_curr_cui_id, type);
                if(m_type == APPLIB_ADDR_TYPE_PHONENUMBER)
                {
                    vcui_phb_contact_saver_set_number(m_curr_cui_id, m_string, mmi_ucs2strlen((PS8)m_string));
                }
                else if(m_type == APPLIB_ADDR_TYPE_EMAIL)
                {
                    vcui_phb_contact_saver_set_email(m_curr_cui_id, m_string, mmi_ucs2strlen((PS8)m_string));
                }
                vcui_phb_contact_saver_run(m_curr_cui_id);
            }
        }
        break;
    #if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
        case VAPP_MMS_USE_DETAILS_SEND_MESSAGE:
            {
                VappUcEntryStruct data;
                srv_uc_addr_struct addr;
                memset(&data, 0x00, sizeof(VappUcEntryStruct));
                memset(&addr, 0x00, sizeof(srv_uc_addr_struct));
                data.addr_num = 1;
                addr.addr = (kal_uint8*) m_string;
                addr.type = SRV_UC_ADDRESS_TYPE_PHONE_NUMBER;
                addr.group = SRV_UC_ADDRESS_GROUP_TYPE_TO;
                data.addr = &addr;
                m_curr_cui_id = vcui_unifiedcomposer_create(grpId, &data);
                mmi_frm_group_set_caller_proc(m_curr_cui_id, &VappMmsUseDetailHandler::handleCuiProc, (void*)getObjHandle());
                if(m_curr_cui_id != GRP_ID_INVALID)
                {
                    vcui_unifiedcomposer_run(m_curr_cui_id);
                }
                return;
            }
    #endif/*__UNIFIED_COMPOSER_SUPPORT__,__MMS_STANDALONE_COMPOSER_SUPPORT__*/

    #if defined( __MMI_VUI_SAVE_BOOKMARK_SUPPORT__) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
        case VAPP_MMS_USE_DETAILS_ADDRESSES_ADD_BOOKMARK:
        {
            U8 *temp_string = NULL;
            m_curr_cui_id = vcui_bkm_add_bkm_create(grpId);
            mmi_frm_group_set_caller_proc(m_curr_cui_id, &VappMmsUseDetailHandler::handleCuiProc, (void*)getObjHandle());
            if(m_curr_cui_id != GRP_ID_INVALID)
            {
                VFX_ALLOC_MEM(temp_string, (MMI_UMMS_MAX_URL_LENGTH+1) * ENCODING_LENGTH, this);; 
                memset(temp_string, 0, (MMI_UMMS_MAX_URL_LENGTH+1) * ENCODING_LENGTH);
                mmi_chset_ucs2_to_utf8_string( (U8*) temp_string, (MMI_UMMS_MAX_URL_LENGTH+1) * ENCODING_LENGTH, (U8*) m_string);
                vcui_bkm_add_bkm_run(m_curr_cui_id, (U8*)temp_string);
                VFX_FREE_MEM(temp_string);
            }
        }
        break;
    #endif/*__MMI_VUI_SAVE_BOOKMARK_SUPPORT__,__MMI_BRW_BKM_INTERFACE_SUPPORT__*/
        case VAPP_MMS_USE_DETAILS_ADDRESSES_EDIT_BEFORE_CALL:
            m_curr_cui_id = cui_dialer_create_ex(grpId, CUI_DIALER_TYPE_CLASSIC);
            mmi_frm_group_set_caller_proc(m_curr_cui_id, &VappMmsUseDetailHandler::handleCuiProc, (void*)getObjHandle());
            if(m_curr_cui_id != GRP_ID_INVALID)
            {
                cui_dialer_set_phb_data(m_curr_cui_id, NULL);
                cui_dialer_set_dial_string(m_curr_cui_id, (const WCHAR*)m_string);
                cui_dialer_run(m_curr_cui_id);
            }
        break;
        default:
        break;
    }
}
void VappMmsUseDetailHandler::call(void)
{
	/*Launch Dialer instead*/
	m_operation = VAPP_MMS_USE_DETAILS_ADDRESSES_EDIT_BEFORE_CALL;
	useCui();
#if(0)
	mmi_ucm_make_call_para_struct make_call_para;
	mmi_ucm_init_call_para(&make_call_para);
	srv_ucm_call_type_enum call_type;
	if(m_sim == MMA_SIM_ID_SIM1)
	{
		call_type = SRV_UCM_VOICE_CALL_TYPE;/* SIM1 voice call type */
	}
	else
	{
		call_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;/* SIM2 voice call type */
	}
    make_call_para.dial_type = (srv_ucm_call_type_enum)call_type;
	make_call_para.adv_para.after_make_call_callback = NULL;
    make_call_para.ucs2_num_uri = (U16*) m_string;
    mmi_ucm_call_launch(0, &make_call_para);
	if(m_string)
	{
		VFX_FREE_MEM(m_string);
		m_string = NULL;
	}
#endif
}
void VappMmsUseDetailHandler::goToUrl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tempstr[(MMI_UMMS_MAX_URL_LENGTH + 1) * ENCODING_LENGTH];
    S32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = mmi_ucs2strlen((S8*) (m_string));
    //   	COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PLUG_IN_VIEWER_LAUNCH_URL);
    if (len > MMI_UMMS_MAX_URL_LENGTH)
    {
        //COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_URL_LENGTH_EXCEED);
        VappMmsPopup m_popup(STR_ID_VAPP_MMS_URL_TOO_LONG, VCP_POPUP_TYPE_FAILURE, getParent(), (clickOk)&VappMmsUseDetailHandler::onClickOk);           
        m_popup.displayPopup();
        if(m_string)
        {
            VFX_FREE_MEM(m_string);
            m_string = NULL;
        }  
        return;
    }
    mmi_ucs2cpy((S8*) tempstr, (S8*) (m_string));
    if(m_string)
    {
        VFX_FREE_MEM(m_string);
        m_string = NULL;
    }
#ifdef BROWSER_SUPPORT
    wap_start_browser(WAP_BROWSER_GOTO_URL, (PU8) (tempstr));
#endif/*BROWSER_SUPPORT*/
}

void VappMmsUseDetailHandler::saveToBookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = mmi_ucs2strlen((S8*) (m_string));
    if (len > MMI_UMMS_MAX_URL_LENGTH)
    {
        //        COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_URL_LENGTH_EXCEED);
        VappMmsPopup m_popup(STR_ID_VAPP_MMS_URL_TOO_LONG, VCP_POPUP_TYPE_FAILURE, getParent(), (clickOk)&VappMmsUseDetailHandler::onClickOk);           
        m_popup.displayPopup();
        if(m_string)
        {
            VFX_FREE_MEM(m_string);
            m_string = NULL;
        }
        return;
    }
    useCui();	
}

void VappMmsUseDetailHandler::SendEmail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //    COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PLUG_IN_VIEWER_LAUNCH_EMAIL);
    if (mmi_ucs2strlen((S8*)m_string) > MMI_EMAIL_MAX_ADDR_LEN)
    {
        //COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_EMAIL_LENGTH_EXCEED);
        VcpConfirmPopup *m_alertPopup;
        VFX_OBJ_CREATE(m_alertPopup, VcpConfirmPopup, this);
        VfxWString txt(STR_ID_VAPP_MMS_TRUNCATE_NUMBER);
        m_alertPopup->setText(txt);
        m_alertPopup->setInfoType(VCP_POPUP_TYPE_INFO);
        m_alertPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        m_alertPopup->m_signalButtonClicked.connect(this, &VappMmsUseDetailHandler::onClickOk);
        m_alertPopup->m_signalPopupState.connect(this, &VappMmsUseDetailHandler::onEmailTruncated);
        m_alertPopup->show(VFX_TRUE);
        return;
    }
    else
    {
    #ifdef __MMI_EMAIL__       
        mmi_email_app_send_to((S8*) m_string);
    #endif/*__MMI_EMAIL__*/
        if(m_string)
        {
            VFX_FREE_MEM(m_string);
            m_string = NULL;
        }
    }
}

void VappMmsUseDetailHandler::onClickOk(VfxObject* obj, VfxId id)
{
	
}
void VappMmsUseDetailHandler::onEmailTruncated(VfxBasePopup* obj, VfxBasePopupStateEnum type)
{
    if(type == VFX_BASE_POPUP_AFTER_END_ANIMATION)
    {
        U8 temp[(MMI_EMAIL_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];
        memset(temp, 0, (MMI_EMAIL_MAX_ADDR_LEN + 1) * ENCODING_LENGTH);
        mmi_ucs2ncpy((S8*) temp, (S8*) m_string, MMI_EMAIL_MAX_ADDR_LEN);
    #ifdef __MMI_EMAIL__       
        mmi_email_app_send_to((S8*) temp);
    #endif/*__MMI_EMAIL__*/
        if(m_string)
        {
            VFX_FREE_MEM(m_string);
            m_string = NULL;
        }
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
mmi_ret VappMmsUseDetailHandler::handleCuiProc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VappMmsUseDetailHandler *my = (VappMmsUseDetailHandler *)VfxObject::handleToObject((VfxObjHandle)evt->user_data);
    mmi_group_event_struct *groupEvent = (mmi_group_event_struct*)evt;
    mmi_id senderId = groupEvent->sender_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_PHB_SAVE_RESULT:
            vcui_phb_contact_saver_close(senderId);
        break;
        case EVT_ID_CUI_UC_MSGCOMPOSER_CLOSE:
            vcui_unifiedcomposer_close(senderId);
        break;
        case EVT_ID_CUI_DIALER_CLOSED_IND:
        case EVT_ID_CUI_DIALER_CLOSE_REQ:
            cui_dialer_close(senderId);
        break;
    #if defined( __MMI_VUI_SAVE_BOOKMARK_SUPPORT__) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
        case EVT_ID_VCUI_BKM_SEL_BKM_RESULT:
        break;
        case EVT_ID_VCUI_BKM_ADD_BKM_CLOSE:
            vcui_bkm_add_bkm_close(senderId);
        break;
    #endif/*__MMI_VUI_SAVE_BOOKMARK_SUPPORT__, __MMI_BRW_BKM_INTERFACE_SUPPORT__*/
        default:
        break;
    }
    if(my && my->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsUseDetailHandler)) )
    {
        return my->handleCuiIntProc(evt);
    }
    return MMI_RET_OK;
}

mmi_ret VappMmsUseDetailHandler::handleCuiIntProc(mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_PHB_SAVE_RESULT:
            m_curr_cui_id = GRP_ID_INVALID;
        break;
        case EVT_ID_CUI_UC_MSGCOMPOSER_CLOSE:
            m_curr_cui_id = GRP_ID_INVALID;
            if(m_string)
            {
                VFX_FREE_MEM(m_string);
                m_string = NULL;
            }
        break;
        case EVT_ID_CUI_DIALER_CLOSED_IND:
        case EVT_ID_CUI_DIALER_CLOSE_REQ:
            m_curr_cui_id = GRP_ID_INVALID;
            if(m_string)
            {
                VFX_FREE_MEM(m_string);
                m_string = NULL;
            }
        break;
    #if defined( __MMI_VUI_SAVE_BOOKMARK_SUPPORT__) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
        case EVT_ID_VCUI_BKM_SEL_BKM_RESULT:
        break;
        case EVT_ID_VCUI_BKM_ADD_BKM_CLOSE:
            m_curr_cui_id = GRP_ID_INVALID;
            if(m_string)
            {
                VFX_FREE_MEM(m_string);
                m_string = NULL;
            }
        break;
    #endif/*__MMI_VUI_SAVE_BOOKMARK_SUPPORT__,__MMI_BRW_BKM_INTERFACE_SUPPORT__*/
        default:
        break;
    }
    return MMI_RET_OK;
}
#endif /* __MMI_MMS_2__  */