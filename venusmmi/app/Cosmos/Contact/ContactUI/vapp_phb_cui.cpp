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
 *  vapp_phb_cui.cpp
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMI_features.h"

#include "mmi_rp_srv_venus_component_tool_bar_def.h"

#include "vapp_phb_cui.h"
#include "vapp_phb_group.h"
#include "vapp_phb_app.h"
#include "vapp_ncenter.h"
#include "vapp_uc_prot.h"
#include "vapp_uc_gprot.h"
#ifdef __cplusplus
extern "C"
{
#endif
#include "SimCtrlSrvGprot.h"
#ifdef __cplusplus
}
#endif


extern "C"
{

mmi_id vcui_phb_list_create(mmi_id parent_id)
{
    mmi_id cui_id = VfxAppLauncher::createCui(
                                        VCUI_CONTACT_LIST,
                                        VFX_OBJ_CLASS_INFO(VappPhbListCui),
                                        parent_id);
    return cui_id;
}


void vcui_phb_list_set_user_data(mmi_id cui_id, U32 user_data)
{
    VappPhbListCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbListCui);
    VFX_ASSERT(obj != NULL);

    obj->setUserData(user_data);
}


void vcui_phb_list_set_req_type(mmi_id cui_id, vcui_phb_list_type_enum list_type)
{
    VappPhbListCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbListCui);
    VFX_ASSERT(obj != NULL);

    obj->setListType(list_type);
}


U32 vcui_phb_list_get_user_data(mmi_id cui_id)
{
    VappPhbListCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbListCui);
    VFX_ASSERT(obj != NULL);

    return obj->getUserData();
}


void vcui_phb_list_set_req_field(mmi_id cui_id, U32 field_mask)
{
    VappPhbListCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbListCui);
    VFX_ASSERT(obj != NULL);

    obj->setReqField(field_mask);
}


void vcui_phb_list_set_req_count(mmi_id cui_id, U32 req_count)
{
    VappPhbListCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbListCui);
    VFX_ASSERT(obj != NULL);

    obj->setReqCount(req_count);
}


void vcui_phb_list_set_drag_ncenter_flag(mmi_id cui_id, MMI_BOOL is_drag)
{
    VappPhbListCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbListCui);
    VFX_ASSERT(obj != NULL);

    obj->setDragNCenterFlag(is_drag == MMI_TRUE ? VFX_TRUE : VFX_FALSE);
}

#ifdef __MMI_PHB_CALLER_GROUP__
void vcui_phb_list_set_group(mmi_id cui_id, U32 groupId, MMI_BOOL thisGroup)
{
    VappPhbListCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbListCui);
    VFX_ASSERT(obj != NULL);

    obj->setGroupField(groupId, (thisGroup != MMI_FALSE) ? VFX_TRUE : VFX_FALSE);
}
#endif /* vcui_phb_list_set_group */

void vcui_phb_list_set_storage(mmi_id cui_id, U32 storageMask)
{
    VappPhbListCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbListCui);
    VFX_ASSERT(obj != NULL);

    obj->m_data.m_storageMask = storageMask;
}


void vcui_phb_list_set_title_str(mmi_id cui_id, U32 str_id)
{
    VappPhbListCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbListCui);
    VFX_ASSERT(obj != NULL);

    obj->m_data.m_titleStr.loadFromRes(str_id);
}


U32 vcui_phb_list_get_selected_count(mmi_id cui_id)
{
    VappPhbListCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbListCui);
    VFX_ASSERT(obj != NULL);

    return obj->getSelectedCount();
}


mmi_phb_contact_id vcui_phb_list_get_contact_id(mmi_id cui_id)
{
    return vcui_phb_list_get_contact_id_by_index(cui_id, 0);
}


mmi_phb_contact_id vcui_phb_list_get_contact_id_by_index(mmi_id cui_id, U16 index)
{
    VappPhbListCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbListCui);
    VFX_ASSERT(obj != NULL);

    return obj->getId(index);
}


void vcui_phb_list_get_selected_contact_name(mmi_id cui_id, WCHAR* buf, U16 length)
{
    vcui_phb_list_get_selected_contact_name_by_index(cui_id, buf, length, 0);
}


void vcui_phb_list_get_selected_contact_name_by_index(mmi_id cui_id, WCHAR* buf, U16 length, U16 index)
{
    VappPhbListCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbListCui);
    VFX_ASSERT(obj != NULL);

    obj->getName(buf, length, index);
}


void vcui_phb_list_get_selected_contact_data(mmi_id cui_id, WCHAR* buf, U16 length)
{
    vcui_phb_list_get_selected_contact_data_by_index(cui_id, buf, length, 0);
}


void vcui_phb_list_get_selected_contact_data_by_index(mmi_id cui_id, WCHAR* buf, U16 length, U16 index)
{
    VappPhbListCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbListCui);
    VFX_ASSERT(obj != NULL);

    obj->getData(buf, length, index);
}


void vcui_phb_list_get_selected_contact_data_type(mmi_id cui_id, U32 *type, U32 *sub_type, U32 *sub_id)
{
   vcui_phb_list_get_selected_contact_data_type_by_index(cui_id, type, sub_type, sub_id, 0);
}


void vcui_phb_list_get_selected_contact_data_type_by_index(mmi_id cui_id, U32 *type, U32 *sub_type, U32 *sub_id, U16 index)
{
    VappPhbListCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbListCui);
    VFX_ASSERT(obj != NULL);

    obj->getDataType(type, sub_type, sub_id, index);
}


void vcui_phb_list_run(mmi_id cui_id)
{
    VfxAppLauncher::runCui(cui_id);
}


void vcui_phb_list_close(mmi_id cui_id)
{
    VfxAppLauncher::terminate(cui_id);
}


mmi_id vcui_phb_contact_saver_create(mmi_id parent_id)
{
    if (!vapp_phb_ready_balloon())
    {
        return GRP_ID_INVALID;
    }

    mmi_id cui_id = VfxAppLauncher::createCui(
                                        VCUI_CONTACT_SAVE,
                                        VFX_OBJ_CLASS_INFO(VappPhbSaveContactCui),
                                        parent_id);
    VappPhbSaveContactCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbSaveContactCui);
    VFX_ASSERT(obj != NULL);

    obj->setFromPhb(VFX_FALSE);
    return cui_id;
}


mmi_id vcui_phb_contact_saver_create2(mmi_id parent_id)
{
    if (!vapp_phb_ready_balloon())
    {
        return GRP_ID_INVALID;
    }

    mmi_id cui_id = VfxAppLauncher::createCui(
                                        VCUI_CONTACT_SAVE2,
                                        VFX_OBJ_CLASS_INFO(VappPhbSaveContactCui),
                                        parent_id);
    return cui_id;
}


void vcui_phb_contact_saver_set_user_data(mmi_id cui_id, U32 user_data)
{
    VappPhbSaveContactCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id) ,VappPhbSaveContactCui);
    VFX_ASSERT(obj != NULL);

    obj->setUserData(user_data);
}


U32 vcui_phb_contact_saver_get_user_data(mmi_id cui_id)
{
    VappPhbSaveContactCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbSaveContactCui);
    VFX_ASSERT(obj != NULL);

    return obj->getUserData();
}


void vcui_phb_contact_saver_set_type(mmi_id cui_id, vcui_phb_save_contact_type_enum type)
{
    VappPhbSaveContactCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbSaveContactCui);
    VFX_ASSERT(obj != NULL);

    obj->setType(type);
}


void vcui_phb_contact_saver_set_contact_id(mmi_id cui_id, mmi_phb_contact_id id)
{
    VappPhbSaveContactCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbSaveContactCui);
    VFX_ASSERT(obj != NULL);

    obj->setId(id);
}


void vcui_phb_contact_saver_set_name(mmi_id cui_id, WCHAR* name, U32 length)
{
    VappPhbSaveContactCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbSaveContactCui);
    VFX_ASSERT(obj != NULL);

    obj->setData((VfxWChar*)name, length, 0, MMI_PHB_CONTACT_FIELD_NAME);
}


void vcui_phb_contact_saver_set_number(mmi_id cui_id, WCHAR* number, U32 length)
{
    VappPhbSaveContactCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbSaveContactCui);
    VFX_ASSERT(obj != NULL);

    obj->setData((VfxWChar*)number, length, 0, MMI_PHB_CONTACT_FIELD_NUMBER);
}


void vcui_phb_contact_saver_set_email(mmi_id cui_id, WCHAR* email, U32 length)
{
    VappPhbSaveContactCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbSaveContactCui);
    VFX_ASSERT(obj != NULL);

    obj->setData((VfxWChar*)email, length, 0, MMI_PHB_CONTACT_FIELD_EMAIL);
}


void vcui_phb_contact_saver_set_image(mmi_id cui_id, WCHAR* path, U32 length, VfxU32 id)
{
    VappPhbSaveContactCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbSaveContactCui);
    VFX_ASSERT(obj != NULL);

    obj->setData((VfxWChar*)path, length, id, MMI_PHB_CONTACT_FIELD_IMAGE);
}


void vcui_phb_contact_saver_run(mmi_id cui_id)
{
    VfxAppLauncher::runCui(cui_id);
}


void vcui_phb_contact_saver_close(mmi_id cui_id)
{
    VfxAppLauncher::terminate(cui_id);
}


mmi_id vcui_phb_contact_viewer_create(mmi_id parent_id)
{
    mmi_id cui_id = VfxAppLauncher::createCui(
                                        VCUI_CONTACT_VIEW,
                                        VFX_OBJ_CLASS_INFO(VappPhbViewContactCui),
                                        parent_id);
    return cui_id;
}


void vcui_phb_contact_viewer_set_contact_id(mmi_id cui_id, mmi_phb_contact_id id)
{
    VappPhbViewContactCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbViewContactCui);
    VFX_ASSERT(obj != NULL);

    obj->setId(id);
}


void vcui_phb_contact_viewer_set_sub_app(mmi_id cui_id, vcui_phb_viewer_type_enum type)
{
    VappPhbViewContactCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbViewContactCui);
    VFX_ASSERT(obj != NULL);

    obj->setSubAppId(type);
}


void vcui_phb_contact_viewer_set_user_data(mmi_id cui_id, vcui_phb_viewer_type_enum type, void* user_data)
{
    VappPhbViewContactCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbViewContactCui);
    VFX_ASSERT(obj != NULL);

    obj->setUserData(user_data, type);
}


void* vcui_phb_contact_viewer_get_user_data(mmi_id cui_id, vcui_phb_viewer_type_enum type)
{
    VappPhbViewContactCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbViewContactCui);
    VFX_ASSERT(obj != NULL);

    return obj->getUserData(type);
}


void vcui_phb_contact_viewer_run(mmi_id cui_id)
{
    VfxAppLauncher::runCui(cui_id);
}


void vcui_phb_contact_viewer_close(mmi_id cui_id)
{
    VfxAppLauncher::terminate(cui_id);
}


mmi_id vcui_phb_sim_locator_create(mmi_id parent_id, U16 index)
{
    if (!vapp_phb_ready_balloon())
    {
        return GRP_ID_INVALID;
    }

    phb_storage_enum storage = PHB_STORAGE_NONE;

    for (VfxU32 i = 0; i < ContactSim::getTotal(); i++)
    {
        mmi_sim_enum sim = mmi_frm_index_to_sim(i);
        if (srv_sim_ctrl_is_available(sim) && srv_phb_check_storage_accessible(PHB_STORAGE_SIM + i))
        {
            storage = (phb_storage_enum) (PHB_STORAGE_SIM + i);
            break;
        }
    }

    if (storage == PHB_STORAGE_NONE)
    {
        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
        balloon->addItem(VCP_INFO_BALLOON_TYPE_FAILURE, (VfxResId)STR_ID_VAPP_PHB_ADN_FORBID);
        return GRP_ID_INVALID;
    }

    if (index == 0 || index > srv_phb_get_total_contact(storage))
    {
        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
        balloon->addItem(VCP_INFO_BALLOON_TYPE_FAILURE, (VfxResId)STR_ID_VAPP_PHB_INVALID_LOCATION);
        return GRP_ID_INVALID;
    }

    mmi_phb_contact_id id;
    srv_phb_record_index_to_store_index(storage, index, &id);

    if (!ContactEntry::isValid(id))
    {
        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
        balloon->addItem(VCP_INFO_BALLOON_TYPE_FAILURE, (VfxResId)STR_ID_VAPP_PHB_NO_CONTACT);
        return GRP_ID_INVALID;
    }

    mmi_id cui_id = VfxAppLauncher::createCui(
                                        VCUI_SIM_LOCATE,
                                        VFX_OBJ_CLASS_INFO(VappPhbLocateSimCui),
                                        parent_id);
    VappPhbLocateSimCui *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappPhbLocateSimCui);
    VFX_ASSERT(obj != NULL);

    obj->setId(id);
    return cui_id;
}


void vcui_phb_sim_locator_run(mmi_id cui_id)
{
    VfxAppLauncher::runCui(cui_id);
}


void vcui_phb_sim_locator_close(mmi_id cui_id)
{
    VfxAppLauncher::terminate(cui_id);
}

}


/***************************************************************************** 
 * Class VappPhbListCui
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappPhbListCui", VappPhbListCui, VfxCui);

VappPhbListCui::VappPhbListCui():
    m_listType(VAPP_PHB_LIST_SINGLE_SELECTOR),
    m_selector(NULL)
{
    m_data.m_storageMask = ContactStorage::getMask();
    m_dragNCenter = VFX_TRUE;
}


void VappPhbListCui::onRun(void* args, VfxU32 argSize)
{
    VfxCui::onRun(args, argSize);

    VappPhbListCuiScr *scr;
    VFX_OBJ_CREATE(scr, VappPhbListCuiScr, this);

    scr->show();
}


void VappPhbListCui::setReqField(VfxU32 fieldMask)
{
     m_data.m_fieldMask = fieldMask;
}


VfxU32 VappPhbListCui::getReqField() const
{
    return m_data.m_fieldMask;
}


void VappPhbListCui::setReqCount(VfxU32 count)
{
    m_data.m_reqCount = count;

    if (count > 1 && m_listType == VAPP_PHB_LIST_SINGLE_SELECTOR)
    {
        m_listType = VAPP_PHB_LIST_GROUP_MULTI_SELECTOR;
    }
}


VfxU32 VappPhbListCui::gettReqCount() const
{
    return m_data.m_reqCount;
}


void VappPhbListCui::setListType(vcui_phb_list_type_enum type)
{
    m_listType = type;
}


vcui_phb_list_type_enum VappPhbListCui::getListType() const
{
    return m_listType;
}


#ifdef __MMI_PHB_CALLER_GROUP__
void VappPhbListCui::setGroupField(VfxU8 groupId, VfxBool thisGroup)
{
    m_data.m_groupId = groupId;
    m_data.m_thisGroup = thisGroup;
}
#endif /* __MMI_PHB_CALLER_GROUP__ */

void VappPhbListCui::setUserData(VfxU32 userData)
{
    m_data.m_userData = userData;
}


VfxU32 VappPhbListCui::getUserData()
{
    return m_data.m_userData;
}


VfxU32 VappPhbListCui::getSelectedCount() const
{
    return m_selector->getSelectedCount();
}


mmi_phb_contact_id VappPhbListCui::getId(VfxU32 index)
{
    return m_selector->getId(index);
}


void VappPhbListCui::getName(VfxWChar* name, VfxU32 length, VfxU32 index)
{
    m_selector->getName(name, length, index);
}


void VappPhbListCui::getData(VfxWChar* data, VfxU32 length, VfxU32 index)
{
    m_selector->getData(data, length, index);
}


void VappPhbListCui::getDataType(VfxU32 *type, VfxU32 *sub_type, VfxU32 *sub_id, VfxU32 index)
{
    m_selector->getDataType(type, sub_type, sub_id, index);
}


void VappPhbListCui::setDragNCenterFlag(VfxBool dragNCenter)
{
    m_dragNCenter = dragNCenter;
}


void VappPhbListCui::onSelectedDone(VappPhbListCuiSelector* selector, VfxBool success)
{
    m_selector = selector;

    vcui_phb_list_result_event_struct evt;

    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_PHB_LIST_RESULT, m_groupId);
    
    evt.result = (success) ? 1 : -1;
    if (success)
    {
        evt.select_count = selector->getSelectedCount();
    }
    else
    {
        evt.select_count = 0;
    }

    postToCaller((mmi_group_event_struct*)&evt);
}


VfxAppCloseAnswerEnum VappPhbListCui::onProcessClose(VfxAppCloseOption options)
{
    onSelectedDone(NULL, VFX_FALSE);

    return VfxApp::onProcessClose(options);
}


/***************************************************************************** 
 * Class VappPhbListCuiScr
 *****************************************************************************/
VappPhbListCuiScr::VappPhbListCuiScr()
{
    m_tabCtrlPage = NULL;
    setAppContextShareForVrt(VFX_TRUE);
}


void VappPhbListCuiScr::on1stReady()
{
    VfxMainScr::on1stReady();

    VappPhbListCui *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VappPhbListCui);
#ifdef __MMI_PHB_CALLER_GROUP__
    if (cui->m_listType == VAPP_PHB_LIST_GROUP_SINGLE_SELECTOR)
    {
        VappPhbListCuiWithGroupSingleSelectorPage *page;
        VFX_OBJ_CREATE(page, VappPhbListCuiWithGroupSingleSelectorPage, this);
        page->setTitle(cui->m_data.m_titleStr);

        pushPage(VFX_ID_NULL, page);

        m_tabCtrlPage = page;
        page->m_signalGroupTaped.connect(this, &VappPhbListCuiScr::onGroupTaped);
    }
    else if (cui->m_listType == VAPP_PHB_LIST_GROUP_MULTI_SELECTOR)
    {
        VappPhbListCuiWithGroupMultiSelectorPage *page;
        VFX_OBJ_CREATE(page, VappPhbListCuiWithGroupMultiSelectorPage, this);
        page->setTitle(cui->m_data.m_titleStr);
        
        pushPage(VFX_ID_NULL, page);
		m_tabCtrlPage = page;
        page->m_signalGroupTaped.connect(this, &VappPhbListCuiScr::onGroupTaped);
    }
#else
    if ( cui->m_listType == VAPP_PHB_LIST_GROUP_SINGLE_SELECTOR )
    {
        VappPhbListCuiSingleSelectorPage *page;
        VFX_OBJ_CREATE(page, VappPhbListCuiSingleSelectorPage, this);
        page->setTitle(cui->m_data.m_titleStr);

        page->m_signalSelected.connect(cui, &VappPhbListCui::onSelectedDone);
        pushPage(VFX_ID_NULL, page);
    }
    else if (cui->m_listType == VAPP_PHB_LIST_GROUP_MULTI_SELECTOR)
    {
        VappPhbListCuiMultiSelectorPage *page;
        VFX_OBJ_CREATE(page, VappPhbListCuiMultiSelectorPage, this);
        page->setTitle(cui->m_data.m_titleStr);

        page->m_signalSelected.connect(cui, &VappPhbListCui::onSelectedDone);
        
        pushPage(VFX_ID_NULL, page);
    }

#endif /* __MMI_PHB_CALLER_GROUP__ */
if (cui->m_listType == VAPP_PHB_LIST_SINGLE_SELECTOR)
{
    VappPhbListCuiSingleSelectorPage *page;
    VFX_OBJ_CREATE(page, VappPhbListCuiSingleSelectorPage, this);
    page->setTitle(cui->m_data.m_titleStr);

    page->m_signalSelected.connect(cui, &VappPhbListCui::onSelectedDone);
    pushPage(VFX_ID_NULL, page);
}
else if (cui->m_listType == VAPP_PHB_LIST_MULTI_SELECTOR)
{
    VappPhbListCuiMultiSelectorPage *page;
    VFX_OBJ_CREATE(page, VappPhbListCuiMultiSelectorPage, this);
    page->setTitle(cui->m_data.m_titleStr);

    page->m_signalSelected.connect(cui, &VappPhbListCui::onSelectedDone);  
    pushPage(VFX_ID_NULL, page);
}
}


void VappPhbListCuiScr::onQueryRotateEx(VfxScreenRotateParam &param)
{
}


void VappPhbListCuiScr::onEnter(VfxBool isBackward)
{
    VfxMainScr::onEnter(isBackward);

    VappPhbListCui *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VappPhbListCui);

    if (!cui->m_dragNCenter)
    {
        VappNCenter *NCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
        NCenter->setDisableDrag(VFX_TRUE);
    }
}


void VappPhbListCuiScr::onExit(VfxBool isBackward)
{
    VappPhbListCui *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VappPhbListCui);

    if (!cui->m_dragNCenter)
    {
        VappNCenter *NCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
        NCenter->setDisableDrag(VFX_FALSE);
    }

    VfxMainScr::onExit(isBackward);
}


void VappPhbListCuiScr::onGroupTaped(VfxU8 groupId, VfxWString groupName)
{
    // VFX_OBJ_CLOSE(m_tabCtrlPage); // close tab page
    popPage(); // notice: 

    VappPhbListCui *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VappPhbListCui);
    
    if (cui->m_listType == VAPP_PHB_LIST_GROUP_SINGLE_SELECTOR)
    {
        VappPhbListCuiSingleSelectorPage *page;
        VFX_OBJ_CREATE(page, VappPhbListCuiSingleSelectorPage, this);

        page->setTitle(groupName);
        page->getListCp()->setMenuMode(VCP_LIST_MENU_MODE_NORMAL);
#ifdef __MMI_PHB_CALLER_GROUP__
        page->getListCp()->getListObject()->setGroup(groupId, VFX_TRUE);
#endif /* __MMI_PHB_CALLER_GROUP__ */
        pushPage(VFX_ID_NULL, page);

        page->m_signalSelected.connect(cui, &VappPhbListCui::onSelectedDone);
    }
    else
    {
        VappPhbListCuiMultiSelectorPage *page;
        VFX_OBJ_CREATE(page, VappPhbListCuiMultiSelectorPage, this);

        page->setTitle(groupName);
#ifdef __MMI_PHB_CALLER_GROUP__        
        page->setGroupId(groupId);
#endif /* __MMI_PHB_CALLER_GROUP__ */
        pushPage(VFX_ID_NULL, page);

        page->m_signalSelected.connect(cui, &VappPhbListCui::onSelectedDone);
    }
}


/***************************************************************************** 
 * Class VappPhbListCuiSingleSelectorPage
 *****************************************************************************/
void VappPhbListCuiSingleSelectorPage::onInit()
{
    VfxPage::onInit();

    VappPhbListCui *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VappPhbListCui);

    // create title bar
    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);

    // create contact list
    VFX_OBJ_CREATE(m_list, VappPhbListCp, this);
    m_list->setListType(VAPP_PHB_LIST_SINGLE);
    m_list->setAlignField(cui->m_data.m_fieldMask);
    m_list->getListObject()->setField(cui->m_data.m_fieldMask);
#ifdef __MMI_PHB_CALLER_GROUP__
    m_list->getListObject()->setGroup(cui->m_data.m_groupId, cui->m_data.m_thisGroup);
#endif /*__MMI_PHB_CALLER_GROUP__*/

    m_list->getListObject()->setStorage(cui->m_data.m_storageMask);

    m_list->setSize(getSize());
    m_list->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    m_list->m_signalItemTapped.connect(this, &VappPhbListCuiSingleSelectorPage::onItemTaped);
}


void VappPhbListCuiSingleSelectorPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}


void VappPhbListCuiSingleSelectorPage::setTitle(const VfxWString& title)
{
    m_titleBar->setTitle(title);
    setTopBar(m_titleBar);
}


VfxU32 VappPhbListCuiSingleSelectorPage::getSelectedCount()
{
    // always return 1
    return 1;
}


mmi_phb_contact_id VappPhbListCuiSingleSelectorPage::getId(VfxU32 index)
{
    return m_id;
}


void VappPhbListCuiSingleSelectorPage::getName(VfxWChar* name, VfxU32 length, VfxU32 index)
{
    mmi_wcsncpy(name, ContactEntry(m_id).getName().getString().getBuf(), length);
}


void VappPhbListCuiSingleSelectorPage::getData(VfxWChar* data, VfxU32 length, VfxU32 index)
{
    switch (m_fieldType)
    {
        case MMI_PHB_CONTACT_FIELD_ID_NUMBER:
        {
            VappContactNumber number = ContactEntry(m_id).getNumberById(m_subId);
            mmi_wcsncpy(data, number.getBuf(), length);
            break;
        }
        case MMI_PHB_CONTACT_FIELD_ID_EMAIL:
        {
            VappContactEmail email = ContactEntry(m_id).getEmailById(m_subId);
            mmi_wcsncpy(data, email.getBuf(), length);
            break;
        }
    }
}


void VappPhbListCuiSingleSelectorPage::getDataType(VfxU32* type, VfxU32* subType, VfxU32* subId, VfxU32 index)
{
    *type = m_fieldType;
    *subId = m_subId;
}


VappPhbListCp* VappPhbListCuiSingleSelectorPage::getListCp()
{
    return m_list;
}


void VappPhbListCuiSingleSelectorPage::onItemTaped(VcpGroupListMenu *list, VcpMenuPos pos)
{
    ContactList *contactList = m_list->getListObject();
    m_id =  contactList->getId(pos.pos, pos.group);
    m_fieldType = contactList->getType(pos.pos, pos.group);
    m_subId = contactList->getSubId(pos.pos, pos.group);

    m_signalSelected.postEmit(this, VFX_TRUE);
}


void VappPhbListCuiSingleSelectorPage::onBack()
{
 //   VappPhbListCui *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VappPhbListCui);

 //   cui->onSelectedDone(this, VFX_FALSE);
    m_signalSelected.postEmit(this, VFX_FALSE);

 //   VfxPage::onBack();
}


/***************************************************************************** 
 * Class VappPhbListCuiWithGroupSingleSelectorPage
 *****************************************************************************/
#ifdef __MMI_PHB_CALLER_GROUP__ 
void VappPhbListCuiWithGroupSingleSelectorPage::onInit()
{
    VcpTabCtrlPage::onInit();

    addTab(PHB_LIST_CUI_TAB_CONTACT, VFX_WSTR_RES(VAPP_PHB_STR_CONTACTS), VcpStateImage(VAPP_PHB_IMG_TAB_CONTACT));
    addTab(PHB_LIST_CUI_TAB_GROUP, VFX_WSTR_RES(VAPP_PHB_STR_GROUPS), VcpStateImage(VAPP_PHB_IMG_TAB_GROUP));

    setCurrTab(PHB_LIST_CUI_TAB_CONTACT);
}


void VappPhbListCuiWithGroupSingleSelectorPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}


void VappPhbListCuiWithGroupSingleSelectorPage::onRotate(const VfxScreenRotateParam &param)
{
    if (param.rotateTo == VFX_SCR_ROTATE_TYPE_90 || param.rotateTo == VFX_SCR_ROTATE_TYPE_270)
    {
        toggleBar(VFX_PAGE_BAR_LOCATION_TOP, VFX_FALSE);

    }
    else
    {
        toggleBar(VFX_PAGE_BAR_LOCATION_TOP, VFX_TRUE);
    }
}


void VappPhbListCuiWithGroupSingleSelectorPage::setTitle(VfxWString& str)
{
    VcpTitleBar *title;
    VFX_OBJ_CREATE(title, VcpTitleBar, this);
    title->setTitle(str);

    setTopBar(title);
}


VfxPage *VappPhbListCuiWithGroupSingleSelectorPage::onCreateTabPage(VfxId tabId)
{
    VappPhbListCui *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VappPhbListCui);

    switch (tabId)
    {
        case PHB_LIST_CUI_TAB_CONTACT:
        {
            VappPhbListCuiSingleSelectorPage *page;
            VFX_OBJ_CREATE(page, VappPhbListCuiSingleSelectorPage, this);
            page->getListCp()->setMenuMode(VCP_LIST_MENU_MODE_NORMAL);

            page->m_signalSelected.connect(cui, &VappPhbListCui::onSelectedDone);
            return page;
        }
#ifdef	__MMI_PHB_CALLER_GROUP__
        case PHB_LIST_CUI_TAB_GROUP:
        {
            VappPhbListCuiTabGroupPage *page;
            VFX_OBJ_CREATE(page, VappPhbListCuiTabGroupPage, this);
            return page;
        }
#endif /* __MMI_PHB_CALLER_GROUP__ */

    }

    return NULL;
}
#endif /* __MMI_PHB_CALLER_GROUP__ */


/***************************************************************************** 
 * Class VappPhbListCuiMultiSelectorPage
 *****************************************************************************/
VappPhbListCuiMultiSelectorPage::VappPhbListCuiMultiSelectorPage():
    m_list(NULL),
    m_titleBar(NULL),
    m_toolBar(NULL)
{
}


void VappPhbListCuiMultiSelectorPage::onInit()
{
    VfxPage::onInit();

    VappPhbListCui *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VappPhbListCui);

    // create title bar
    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);

    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    setBottomBar(m_toolBar);
    m_toolBar->addItem(PHB_LIST_CUI_CONTACT_CMD_OK,(VfxResId)(STR_GLOBAL_OK), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    m_toolBar->addItem(PHB_LIST_CUI_CONTACT_CMD_CANCEL,(VfxResId)(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->setDisableItem(PHB_LIST_CUI_CONTACT_CMD_OK, VFX_TRUE);

    // create contact list
    VFX_OBJ_CREATE(m_list, VappPhbListCp, this);
    m_list->setListType(VAPP_PHB_LIST_MARK);
    m_list->setAlignField(cui->m_data.m_fieldMask);
    m_list->getListObject()->setField(cui->m_data.m_fieldMask);
#ifdef __MMI_PHB_CALLER_GROUP__
    m_list->getListObject()->setGroup(cui->m_data.m_groupId, cui->m_data.m_thisGroup);
#endif /* __MMI_PHB_CALLER_GROUP__ */
    m_list->getListObject()->setStorage(cui->m_data.m_storageMask);

    m_list->setSize(getSize());
    m_list->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    m_list->m_signalItemSelectionStateChanged.connect(this, &VappPhbListCuiMultiSelectorPage::onStateChanged);
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    m_list->m_signalCount.connect(this, &VappPhbListCuiMultiSelectorPage::onListCountChanged);
#endif

    // toolbar event handler
    m_toolBar->m_signalButtonTap.connect(this, &VappPhbListCuiMultiSelectorPage::onToolBarClick);
}


void VappPhbListCuiMultiSelectorPage::onEntered()
{
    if (getSelectedCount() == 0)
    {
        m_toolBar->setDisableItem(PHB_LIST_CUI_CONTACT_CMD_OK, VFX_TRUE);
    }
    else
    {
        m_toolBar->setDisableItem(PHB_LIST_CUI_CONTACT_CMD_OK, VFX_FALSE);
    }
}


void VappPhbListCuiMultiSelectorPage::onStateChanged(VcpGroupListMenu *list, VcpMenuPos pos, VcpListMenuItemStateEnum state)
{
    configToolBar();
}


void VappPhbListCuiMultiSelectorPage::configToolBar()
{
    if (getSelectedCount() > 0)
    {
        m_toolBar->setDisableItem(PHB_LIST_CUI_CONTACT_CMD_OK, VFX_FALSE);
    }
    else
    {
        m_toolBar->setDisableItem(PHB_LIST_CUI_CONTACT_CMD_OK, VFX_TRUE);
    }
}


#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
void VappPhbListCuiMultiSelectorPage::onListCountChanged(VappPhbListCp* list, VfxU32 count)
{
    configToolBar();
}
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */


void VappPhbListCuiMultiSelectorPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}


void VappPhbListCuiMultiSelectorPage::setTitle(const VfxWString& title)
{
    m_titleBar->setTitle(title);
    setTopBar(m_titleBar);
}


#ifdef __MMI_PHB_CALLER_GROUP__
void VappPhbListCuiMultiSelectorPage::setGroupId(VfxU8 groupId)
{
    m_list->getListObject()->setGroup(groupId, VFX_TRUE);
}
#endif /* __MMI_PHB_CALLER_GROUP__*/ 


VfxU32 VappPhbListCuiMultiSelectorPage::getSelectedCount()
{
    return m_list->getMarked()->getCount();
}


mmi_phb_contact_id VappPhbListCuiMultiSelectorPage::getId(VfxU32 index)
{
    return m_list->getMarked()->getMarkKey(index).m_id;
}


void VappPhbListCuiMultiSelectorPage::getName(VfxWChar* name, VfxU32 length, VfxU32 index)
{
    MarkKey markKey = m_list->getMarked()->getMarkKey(index);
    mmi_wcsncpy(name, ContactEntry(markKey.m_id).getName().getString().getBuf(), length);
}


void VappPhbListCuiMultiSelectorPage::getData(VfxWChar* data, VfxU32 length, VfxU32 index)
{
    MarkKey markKey = m_list->getMarked()->getMarkKey(index);

    switch (markKey.m_type)
    {
        case MMI_PHB_CONTACT_FIELD_ID_NUMBER:
        {
            VappContactNumber number = ContactEntry(markKey.m_id).getNumberById(markKey.m_subId);
            mmi_wcsncpy(data, number.getBuf(), length);
            break;
        }
        case MMI_PHB_CONTACT_FIELD_ID_EMAIL:
        {
            VappContactEmail email = ContactEntry(markKey.m_id).getEmailById(markKey.m_subId);
            mmi_wcsncpy(data, email.getBuf(), length);
            break;
        }
    }
}


void VappPhbListCuiMultiSelectorPage::getDataType(VfxU32* type, VfxU32* subType, VfxU32* subId, VfxU32 index)
{
    MarkKey markKey = m_list->getMarked()->getMarkKey(index);

    *type = markKey.m_type;
    *subType = markKey.m_subId;
    *subId = markKey.m_subId;
}


void VappPhbListCuiMultiSelectorPage::onToolBarClick(VfxObject *obj, VfxId id)
{
    switch (id)
    {
        case PHB_LIST_CUI_CONTACT_CMD_OK:
        {
            m_signalSelected.postEmit(this, VFX_TRUE);
            break;
        }
        case PHB_LIST_CUI_CONTACT_CMD_CANCEL:
        {
            m_signalSelected.postEmit(this, VFX_FALSE);
            break;
        }
    }
}


void VappPhbListCuiMultiSelectorPage::onBack()
{
    //VappPhbListCui *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VappPhbListCui);

    //cui->onSelectedDone(this, VFX_FALSE);
    m_signalSelected.postEmit(this, VFX_FALSE);

    //VfxPage::onBack();
}


/***************************************************************************** 
 * Class VappPhbListCuiWithGroupMultiSelectorPage
 *****************************************************************************/
#ifdef __MMI_PHB_CALLER_GROUP__ 
void VappPhbListCuiWithGroupMultiSelectorPage::onInit()
{
    VcpTabCtrlPage::onInit();

    addTab(PHB_LIST_CUI_TAB_CONTACT, VFX_WSTR_RES(VAPP_PHB_STR_CONTACTS), VcpStateImage(VAPP_PHB_IMG_TAB_CONTACT));
    addTab(PHB_LIST_CUI_TAB_GROUP, VFX_WSTR_RES(VAPP_PHB_STR_GROUPS), VcpStateImage(VAPP_PHB_IMG_TAB_GROUP));

    setCurrTab(PHB_LIST_CUI_TAB_CONTACT);
}


void VappPhbListCuiWithGroupMultiSelectorPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}


void VappPhbListCuiWithGroupMultiSelectorPage::onRotate(const VfxScreenRotateParam &param)
{
    if (param.rotateTo == VFX_SCR_ROTATE_TYPE_90 || param.rotateTo == VFX_SCR_ROTATE_TYPE_270)
    {
        toggleBar(VFX_PAGE_BAR_LOCATION_TOP, VFX_FALSE);
    }
    else
    {
       toggleBar(VFX_PAGE_BAR_LOCATION_TOP, VFX_TRUE);
    }
}


void VappPhbListCuiWithGroupMultiSelectorPage::setTitle(VfxWString& str)
{
    VcpTitleBar *title;
    VFX_OBJ_CREATE(title, VcpTitleBar, this);
    title->setTitle(str);
    setTopBar(title);
}


VfxPage *VappPhbListCuiWithGroupMultiSelectorPage::onCreateTabPage(VfxId tabId)
{
    VappPhbListCui *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VappPhbListCui);

    switch (tabId)
    {
        case PHB_LIST_CUI_TAB_CONTACT:
        {
            VappPhbListCuiMultiSelectorPage *page;
            VFX_OBJ_CREATE(page, VappPhbListCuiMultiSelectorPage, this);

            page->m_signalSelected.connect(cui, &VappPhbListCui::onSelectedDone);
            return page;
        }
        case PHB_LIST_CUI_TAB_GROUP:
        {
            VappPhbListCuiTabGroupPage *page;
            VFX_OBJ_CREATE(page, VappPhbListCuiTabGroupPage, this);
            return page;
        }
    }

    return NULL;
}

#endif /* __MMI_PHB_CALLER_GROUP__ */ 

/***************************************************************************** 
 * Class VappPhbListCuiTabGroupPage
 *****************************************************************************/
#ifdef __MMI_PHB_CALLER_GROUP__
VappPhbListCuiTabGroupPage::VappPhbListCuiTabGroupPage():
    m_groupList(NULL)
{
}


void VappPhbListCuiTabGroupPage::onInit()
{
    VfxPage::onInit();

    VFX_OBJ_CREATE(m_groupManager, ContactGroupManager, this);

    VFX_OBJ_CREATE_EX(m_groupList, VappPhbGroupListCp, this, (m_groupManager));

#if defined (__MMI_PHB_USIM_SUPPORT__) || defined (__MMI_PHB_TCARD_STORAGE_SUPPORT__)

    VfxBool showIcon = VFX_FALSE;

#ifdef __MMI_PHB_USIM_SUPPORT__
    if (UsimGroup::getCount() > 0)
    {
        showIcon = VFX_TRUE;
       // m_groupList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT);
    }
#endif /* __MMI_PHB_USIM_SUPPORT__ */

#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    if (TcardGroup::getCount() > 0)
    {
        showIcon = VFX_TRUE;
    }
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */

    if (showIcon)
    {
        m_groupList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT);
    }
    else
#endif /* defined (__MMI_PHB_USIM_SUPPORT__) || defined (__MMI_PHB_TCARD_STORAGE_SUPPORT__) */
    {
        m_groupList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    }
    m_groupList->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE);
    m_groupList->setSize(getSize());
    m_groupList->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    m_groupList->m_signalItemTapped.connect(this, &VappPhbListCuiTabGroupPage::onItemTaped);
}


void VappPhbListCuiTabGroupPage::onBack()
{
    VappPhbListCui *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VappPhbListCui);

    cui->onSelectedDone(NULL, VFX_FALSE);

    VfxPage::onBack();
}


void VappPhbListCuiTabGroupPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}


void VappPhbListCuiTabGroupPage::onItemTaped(VcpListMenu* list, VfxU32 id)
{
    VcpTabCtrlPage *tabCtrlPage = VFX_OBJ_DYNAMIC_CAST(getParentFrame(), VcpTabCtrlPage);

    if (tabCtrlPage)
    {
        VappPhbListCui *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VappPhbListCui);

        if (cui->m_listType == VAPP_PHB_LIST_GROUP_SINGLE_SELECTOR)
        {
            VappPhbListCuiWithGroupSingleSelectorPage *tabPage = (VappPhbListCuiWithGroupSingleSelectorPage *)tabCtrlPage;

            tabPage->m_signalGroupTaped.postEmit(m_groupManager->getGroupId(id), m_groupManager->getGroupName(id));
        }
        else
        {
            VappPhbListCuiWithGroupMultiSelectorPage *tabPage = (VappPhbListCuiWithGroupMultiSelectorPage *)tabCtrlPage;

            tabPage->m_signalGroupTaped.postEmit(m_groupManager->getGroupId(id), m_groupManager->getGroupName(id));
        }
    }
}
#endif /* __MMI_PHB_CALLER_GROUP__ */


/***************************************************************************** 
 * Class VappPhbSaveContactCui
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappPhbSaveContactCui", VappPhbSaveContactCui, VfxCui);

VappPhbSaveContactCui::VappPhbSaveContactCui()
    :m_type(VAPP_PHB_SAVE_CONTACT_DEFAULT),
     m_id(MMI_PHB_INVALID_CONTACT_ID),
     m_dataList(NULL),
     m_userData(0),
     m_fromPhb(VFX_TRUE)
{}


void VappPhbSaveContactCui::onInit()
{
    VfxCui::onInit();

    VFX_OBJ_CREATE(m_dataList, VappContactFieldObjList, this);
}


VfxAppCloseAnswerEnum VappPhbSaveContactCui::onProcessClose(VfxAppCloseOption options)
{
    onSavedDone(m_id, VFX_FALSE);

    return VfxApp::onProcessClose(options);
}


void VappPhbSaveContactCui::onRun(void* args, VfxU32 argSize)
{
    VfxCui::onRun(args, argSize);

    VappPhbEditorScr *scr;
    VFX_OBJ_CREATE_EX(scr, VappPhbEditorScr, this, (this));
    scr->show();
}


void VappPhbSaveContactCui::setUserData(VfxU32 userData)
{
    m_userData = userData;
}


VfxU32 VappPhbSaveContactCui::getUserData() const
{
    return m_userData;
}


void VappPhbSaveContactCui::setFromPhb(VfxBool fromPhb)
{
    m_fromPhb = fromPhb;
}


VfxBool VappPhbSaveContactCui::getFromPhb(void)
{
    return m_fromPhb;
}


void VappPhbSaveContactCui::setType(vcui_phb_save_contact_type_enum type)
{
    m_type = type;
}


vcui_phb_save_contact_type_enum VappPhbSaveContactCui::getType() const
{
    return m_type;
}


void VappPhbSaveContactCui::setId(mmi_phb_contact_id id)
{
    if (id != MMI_PHB_INVALID_CONTACT_ID)
    {
        m_type = VAPP_PHB_SAVE_CONTACT_EDIT;
    }

    m_id = id;
}


mmi_phb_contact_id VappPhbSaveContactCui::getId() const
{
    return m_id;
}


void VappPhbSaveContactCui::setData(const VfxWChar* data, VfxU32 length, VfxU32 id, VfxU32 type)
{
    m_dataList->setField(data, length, id, type);
}


VappContactFieldObjList* VappPhbSaveContactCui::getFieldList()
{
    return m_dataList;
}


void VappPhbSaveContactCui::onSavedDone(mmi_phb_contact_id id, VfxBool success)
{
    vcui_phb_contact_save_result_event_struct evt;

    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_PHB_SAVE_RESULT, m_groupId);

    evt.result = (success) ? 1 : -1;
    evt.id = id;

    postToCaller((mmi_group_event_struct*)&evt);
}


/***************************************************************************** 
 * Class VappPhbViewContactCui
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappPhbViewContactCui", VappPhbViewContactCui, VfxCui);

void VappPhbViewContactCui::onRun(void* args, VfxU32 argSize)
{
    VfxCui::onRun(args, argSize);

    VappPhbViewerScr *scr;
    VFX_OBJ_CREATE_EX(scr, VappPhbViewerScr, this, (m_id));
#ifdef __MMI_PHB_NEED_SERIALZE__
    m_archive.m_id = m_id;
    m_archive.m_groupId = getGroupId();
#endif
    scr->show();
}


void VappPhbViewContactCui::setId(mmi_phb_contact_id id)
{
    m_id = id;
}


mmi_phb_contact_id VappPhbViewContactCui::getId() const
{
    return m_id;
}


void VappPhbViewContactCui::setSubAppId(vcui_phb_viewer_type_enum type)
{
    m_subAppId = type;
}


vcui_phb_viewer_type_enum VappPhbViewContactCui::getSubAppId() const
{
    return m_subAppId;
}


void* VappPhbViewContactCui::getUserData(vcui_phb_viewer_type_enum type)
{
    void* data = NULL;
    
    switch (type)
    {
        case VAPP_PHB_VIEWER_PROFILE:
            data = m_profileUserData;
            break;

        case VAPP_PHB_VIEWER_CLOG:
            data = m_clogUserData;
            break;

        case VAPP_PHB_VIEWER_MSG:
            data = m_messageUserData;
            break;
    }

    return data;
}


void VappPhbViewContactCui::setUserData(void* userData, vcui_phb_viewer_type_enum type)
{
    switch (type)
    {
        case VAPP_PHB_VIEWER_PROFILE:
            m_profileUserData = userData;
            break;

        case VAPP_PHB_VIEWER_CLOG:
            m_clogUserData = userData;
            break;

        case VAPP_PHB_VIEWER_MSG:
            m_messageUserData = userData;
            break;
    }
}

#ifdef __MMI_PHB_NEED_SERIALZE__
void VappPhbViewContactCui:: onSerialize(void * hint,VfxArchive & ar)
{ 
    VcuiViewUCSerialize Sarchive;
    Sarchive.m_id = m_archive.m_id;
    Sarchive.m_groupId = m_archive.m_groupId;
    ar.write((VfxU8 *)&Sarchive ,sizeof(Sarchive));
}


void VappPhbViewContactCui:: onRestore(VfxArchive &ar)
{
    VcuiViewUCSerialize Rarchive;
    ar.read((VfxU8 *)&Rarchive ,sizeof(Rarchive));
    m_archive.m_id = Rarchive.m_id;
    m_archive.m_groupId = Rarchive.m_groupId;
    {
        VappPhbViewerScr *scr;
        VFX_OBJ_CREATE_EX(scr, VappPhbViewerScr, this, (Rarchive.m_id));
        scr->show();
    }
}


VfxBool g_isUCPreClose = VFX_FALSE;

mmi_ret vapp_phb_proxy_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
#ifdef __MMI_UNIFIED_COMPOSER__
        case EVT_ID_CUI_UC_MSGCOMPOSER_PRECLOSE:
        {
            g_isUCPreClose = VFX_TRUE;
            
        }
        break;
        
        case EVT_ID_CUI_UC_MSGCOMPOSER_CLOSE:
        {
            VappPhbUcSerialze *serialzie = (VappPhbUcSerialze *)evt;
            /* just close it */
            vcui_unifiedcomposer_close(serialzie->m_cuiId); 
        }
            break;
#endif
        case EVT_ID_GROUP_DEINIT:
        {
            g_isUCPreClose = VFX_FALSE;
        }
            break;
        
        case EVT_ID_GROUP_ACTIVE:
            break;
        case EVT_ID_GROUP_FOCUSED:
            kal_prompt_trace(MOD_MMI, "EVT_ID_GROUP_FOCUSED: %d", g_isUCPreClose);
            if(g_isUCPreClose)
            {
                g_isUCPreClose = VFX_FALSE;
            }
            else
            {
                return MMI_RET_ERR;
            }
            break;
       
    }
    return MMI_RET_OK;
        
}


void vapp_phb_open_uc_cui(void *arg, VfxU32 argSize)
{
     mmi_id cuiId = GRP_ID_INVALID;
     VappPhbUcSerialze *serialize = (VappPhbUcSerialze*)arg;
     
#ifdef __MMI_UNIFIED_COMPOSER__
     cuiId = vcui_unifiedcomposer_create(serialize->m_groupId, serialize->entry);
     serialize->m_cuiId = cuiId;
    if (cuiId != GRP_ID_INVALID)
    {
         mmi_frm_group_set_caller_proc(cuiId, vapp_phb_proxy_proc, serialize);
         vcui_unifiedcomposer_run(cuiId);
    }
    else
    {
        g_isUCPreClose = VFX_TRUE;
    }
     srv_phb_mem_free(serialize->entry);
#endif
}
#endif


/***************************************************************************** 
 * Class VappPhbLocateSimCui
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappPhbLocateSimCui", VappPhbLocateSimCui, VfxCui);

void VappPhbLocateSimCui::onRun(void* args, VfxU32 argSize)
{
    VfxCui::onRun(args, argSize);

    VappPhbLocatorScr *scr;
    VFX_OBJ_CREATE_EX(scr, VappPhbLocatorScr, this, (m_id));
#ifdef __MMI_PHB_NEED_SERIALZE__
	m_archive.m_id = m_id;
#endif
    scr->show();
}


void VappPhbLocateSimCui::setId(mmi_phb_contact_id id)
{
    m_id = id;
}


mmi_phb_contact_id VappPhbLocateSimCui::getId() const
{
    return m_id;
}


#ifdef __MMI_PHB_NEED_SERIALZE__
void VappPhbLocateSimCui:: onSerialize(void * hint,VfxArchive & ar)
{ 
    VappPhbSimCuiSerialize Sarchive;
    Sarchive.m_id = m_archive.m_id;
    ar.write((VfxU8 *)&Sarchive ,sizeof(Sarchive));
}


void VappPhbLocateSimCui:: onRestore(VfxArchive &ar)
{
    VappPhbSimCuiSerialize Rarchive;
    ar.read((VfxU8 *)&Rarchive ,sizeof(Rarchive));
    m_archive.m_id = Rarchive.m_id;
    VappPhbLocatorScr *scr;
    VFX_OBJ_CREATE_EX(scr, VappPhbLocatorScr, this, (Rarchive.m_id));
    scr->show();    
}
#endif

