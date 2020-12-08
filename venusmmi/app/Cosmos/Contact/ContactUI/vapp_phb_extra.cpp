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
 *  vapp_phb_extra.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#include "vapp_contact_storage.h"
#include "vapp_phb_extra.h"
#include "vapp_phb_editor.h"
#include "vapp_phb_app.h"
#include "vcui_secset_gprot.h"
#include "mmi_rp_vapp_contact_def.h"
#include "vapp_phb_gprot.h" 

#ifdef __cplusplus
extern "C"
{
#endif
#include "SimCtrlSrvGprot.h"
#include "PhbSrvGprot.h"
#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Class VappContactSettingFdnList
 *****************************************************************************/
void VappContactSettingExtraSimSelect::onPageInit(VfxPageEx * page)
{
    VfxPageHandler::onPageInit(page);

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, page);
    bar->setTitle(STR_ID_VAPP_PHB_FND_SIM_SELECT);
    page->setTopBar(bar);

    VFX_OBJ_CREATE(m_form, VcpForm, page);
    m_form->setSize(page->getSize());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    for (VfxU32 i = 0; i < ContactSim::getTotal(); i++)
    {
        mmi_sim_enum sim = mmi_frm_index_to_sim(i);
        if (srv_sim_ctrl_is_inserted(sim) )
        {
            VFX_OBJ_CREATE(m_item[i], VcpFormItemLauncherCell, m_form);
            m_item[i]->setMainText(ContactSim::getName(sim));
            m_item[i]->setAccessory(VCPFORM_NEXT_ITEM_ICON);
            m_form->addItem(m_item[i], sim);

            if (!srv_phb_startup_is_phb_support((U8) i, PHB_FDN))
            {
                m_item[i]->setIsDisabled(VFX_TRUE);
            }
            m_item[i]->m_signalTap.connect(this, &VappContactSettingExtraSimSelect::onButtonClicked);
        }
    }
}


void VappContactSettingExtraSimSelect::onButtonClicked(VcpFormItemCell* sender, VfxId id)
{
    VappContactSettingFdnList *page;
    VFX_OBJ_CREATE_EX(page, VappContactSettingFdnList, getPage()->getMainScr(), ((mmi_sim_enum) id));
    getPage()->getMainScr()->pushPage(VFX_ID_NULL, page);
}


/***************************************************************************** 
 * Class VappContactSettingFdnList
 *****************************************************************************/
VappContactSettingFdnList::VappContactSettingFdnList()
{
    m_list = NULL;
    m_form = NULL;
    m_fdnSwitch = NULL;
    m_simType = MMI_SIM1;
    m_index = 0xFFFF;
    m_isNew = VFX_TRUE;
}


VappContactSettingFdnList::VappContactSettingFdnList(mmi_sim_enum type)
{
    m_list = NULL;
    m_form = NULL;
    m_fdnSwitch = NULL;
    m_simType = type;
    m_index = 0xFFFF;
    m_isNew = VFX_TRUE;
}


void VappContactSettingFdnList::onInit()
{
    VfxPage::onInit();

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(STR_ID_VAPP_PHB_FND_TITLE);
    setTopBar(bar);

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setPos(0, 0);
#if defined(__MMI_MAINLCD_320X480__)
    m_form->setSize(getSize().width, 110);
#elif defined(__MMI_MAINLCD_480X800__)
    m_form->setSize(getSize().width, 184);
#else
    m_form->setSize(getSize().width, 100);
#endif

    VcpFormItemCaption *caption;
    VFX_OBJ_CREATE(caption, VcpFormItemCaption, m_form);
    caption->setText(STR_ID_VAPP_PHB_FND_ON_OFF);
    m_form->addItem(caption, 0);

    VFX_OBJ_CREATE(m_fdnSwitch, VcpFormItemSwitchCell, m_form);
    if (srv_phb_xmgnt_query_dial_mode((U8) mmi_frm_sim_to_index(m_simType), PHB_FDN))
    {
        m_fdnSwitch->setSwitchStatus(VFX_TRUE);
    }
    else
    {
        m_fdnSwitch->setSwitchStatus(VFX_FALSE);
    }
    m_fdnSwitch->setIsTappable(VFX_FALSE);
    m_form->addItem(m_fdnSwitch, 1);

    m_fdnSwitch->m_signalSwitchChangeReq.connect(this, &VappContactSettingFdnList::onFdnModeChange);

    VcpFormItemCaption *caption2;
    VFX_OBJ_CREATE(caption2, VcpFormItemCaption, m_form);
    VfxWString title = ContactSim::getName(m_simType);
    title += VFX_WSTR(" ");
    title += VFX_WSTR_RES(STR_ID_VAPP_PHB_FND_LIST_TITLE);
    caption2->setText(title);
    m_form->addItem(caption2, 2);

    m_handle = srv_phb_xdnmgr_get_list((U8) mmi_frm_sim_to_index(m_simType), PHB_FDN, &VappContactSettingFdnList::getListCB, this);

    VcpToolBar *bottom_bar;
    VFX_OBJ_CREATE(bottom_bar, VcpToolBar, this);
    bottom_bar->addItem(1, (VfxResId)(STR_GLOBAL_ADD), VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);
    bottom_bar->addItem(2, (VfxResId)(STR_GLOBAL_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    bottom_bar->setDisableItem(2, VFX_TRUE);
    setBottomBar(bottom_bar);

    bottom_bar->m_signalButtonTap.connect(this, &VappContactSettingFdnList::onToolBarClicked);
}


VfxU32 VappContactSettingFdnList::getCount() const
{
    return (VfxU32) srv_phb_xmgnt_get_list_count(m_handle);
}


VfxBool VappContactSettingFdnList::getItemText(
         VfxU32 index,                    // [IN] the index of item
         VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
         VfxWString &text,                // [OUT] the text resource
         VcpListMenuTextColorEnum &color  // [OUT] the text color
         )
{
    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        if (mmi_wcslen(srv_phb_xmgnt_get_entry_name(m_handle, index)))
        {
            text.loadFromMem(srv_phb_xmgnt_get_entry_name(m_handle, index));
        }
        else
        {
            text.loadFromRes(VAPP_PHB_STR_UNNAMED);
        }
    }

    if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        text.loadFromMem(srv_phb_xmgnt_get_entry_number(m_handle, index));
    }

    return VFX_TRUE;
}


mmi_ret VappContactSettingFdnList::onProc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_VCUI_VERIFY_RESULT:
        {
            vcui_verify_result_evt_struct *obj = (vcui_verify_result_evt_struct *)evt;
            if (obj->success)
            {
                if (m_secset == TYPE_MODE_SWITCH)
                {
                    setFdnMode();
                    vcui_verify_close(obj->sender_id);
                }
                else if (m_secset == TYPE_EDIT)
                {
                    editFdn();
                    vcui_verify_close(obj->sender_id);
                }
                else if (m_secset == TYPE_DELETE)
                {
                    deleteFdn();
                    vcui_verify_close(obj->sender_id);
                }
                else
                {
                    VFX_ASSERT(0);
                }
            }
            else
            {
                vcui_verify_close(obj->sender_id);
            }
            break;
        }
        case EVT_ID_VCUI_VERIFY_CANCEL:
        {
            vcui_verify_passive_closing_evt_struct *obj = (vcui_verify_passive_closing_evt_struct *)evt;
            vcui_verify_close(obj->sender_id);
        }
    }

    return MMI_RET_OK;
}


void VappContactSettingFdnList::secsetCuiRun()
{
    mmi_id cui_id = vcui_verify_create(getApp()->getGroupId(), VCUI_VERIFY_TYPE_CHV2);
    vcui_verify_set_sim(cui_id, m_simType);
    vfxSetCuiCallerScr(cui_id, getMainScr());
    vcui_verify_run(cui_id);
}


void VappContactSettingFdnList::onFdnModeChange(VcpFormItemSwitchCell* obj, VfxId id, VfxBool value)
{
    if (!vapp_phb_check_ready() || vapp_phb_check_processing())
    {
        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
        balloon->addItem(VCP_INFO_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_PHB_PROCESSING));
        return;
    }

    m_fdnStatus = value;

    if (srv_sim_ctrl_pwd_is_enabled(m_simType, SRV_SIM_CTRL_PWD_TYPE_CHV2))
    {
        secsetCuiRun();
        m_secset = TYPE_MODE_SWITCH;
    }
    else
    {
        setFdnMode();
    }
}


void VappContactSettingFdnList::getListCB(VfxU16 result, void* user_data)
{
    VappContactSettingFdnList *op = (VappContactSettingFdnList *)user_data;
    op->asycPostInit();
}


void VappContactSettingFdnList::asycPostInit()
{
    if (m_list == NULL)
    {
        VFX_OBJ_CREATE(m_list, VcpListMenu, this);
    }
    m_list->setPos(0, m_form->getSize().height);
    m_list->setSize(getSize().width, getSize().height - m_form->getSize().height);
    m_list->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_list->setContentProvider(this);
    m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
    m_list->setMenuMode(VCP_LIST_MENU_MODE_NORMAL);

    m_list->m_signalItemTapped.connect(this, &VappContactSettingFdnList::onNameItemClick);

    if (getCount() == 0)
    {
        ((VcpToolBar *)getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))->setDisableItem(2, VFX_TRUE);
    }
    else
    {
        ((VcpToolBar *)getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))->setDisableItem(2, VFX_FALSE);
    }
}


void VappContactSettingFdnList::setFdnMode()
{
    m_fdnSwitch->setSwitchStatus(m_fdnStatus);
    fdnModeReq();
}


void VappContactSettingFdnList::fdnModeReq()
{
    VfxBool value = VFX_FALSE;

    if (srv_phb_xdnmgr_toggle_dial_mode((U8) mmi_frm_sim_to_index(m_simType), PHB_FDN, &VappContactSettingFdnList::fdnModeRsp, this) != MMI_FALSE)
    {
        value = VFX_TRUE;
    }

    VappContactSettingFdnList *op = (VappContactSettingFdnList *)this;
    if (!value)
    {
        op->getMainScr()->popPage();
    }
}


void VappContactSettingFdnList::fdnModeRsp(VfxU16 result, void* user_data)
{
    VappContactSettingFdnList *op = (VappContactSettingFdnList *)user_data;
    if (op)
    {
        op->getMainScr()->popPage();
        if (srv_sim_ctrl_get_num_of_inserted() >= 2)
        {
            op->getMainScr()->popPage();
        }
        op->getMainScr()->popPage();
    }
}


void VappContactSettingFdnList::onNameItemClick(VcpListMenu *obj, VfxU32 index)
{
    m_index = index;
    m_isNew = VFX_FALSE;

    if (srv_sim_ctrl_pwd_is_enabled(m_simType, SRV_SIM_CTRL_PWD_TYPE_CHV2))
    {
        secsetCuiRun();
        m_secset = TYPE_EDIT;
    }
    else
    {
        editFdn();
    }
}


void VappContactSettingFdnList::editFdn()
{
    VappContactSettingFdnEdit *page;

    if (m_isNew)
    {
        VFX_OBJ_CREATE_EX(page,
            VappContactSettingFdnEdit, 
            getMainScr(), 
            (NULL, NULL, m_simType, m_handle, 0xFFFF, VFX_TRUE));
    }
    else
    {
        VFX_OBJ_CREATE_EX(page,
            VappContactSettingFdnEdit, 
            getMainScr(), 
            ((VfxWChar *)srv_phb_xmgnt_get_entry_name(m_handle, m_index), (VfxWChar *)srv_phb_xmgnt_get_entry_number(m_handle, m_index), m_simType, m_handle, m_index, VFX_FALSE));
    }
    getMainScr()->pushPage(VFX_ID_NULL, page);

    page->m_signalSave.connect(this, &VappContactSettingFdnList::onEditDone);

    m_index = 0xFFFF;
    m_isNew = VFX_TRUE;
}


void VappContactSettingFdnList::deleteFdn()
{
    VappContactSettingFdnMarkDeleteList *page;
    VFX_OBJ_CREATE_EX(page, VappContactSettingFdnMarkDeleteList, getMainScr(), (m_simType));
    getMainScr()->pushPage(VFX_ID_NULL, page);

    page->m_signaldelete.connect(this, &VappContactSettingFdnList::onEditDone);
}


void VappContactSettingFdnList::addClick()
{
    if (srv_phb_xmgnt_get_list_count(m_handle) == srv_phb_startup_get_fdn_total((U8) mmi_frm_sim_to_index(m_simType)))
    {
        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
        balloon->addItem(VCP_INFO_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_PHB_MAX_NUM_REACH));
    }
    else
    {
        if (srv_sim_ctrl_pwd_is_enabled(m_simType, SRV_SIM_CTRL_PWD_TYPE_CHV2))
        {
            secsetCuiRun();
            m_secset = TYPE_EDIT;
        }
        else
        {
            editFdn();
        }
    }
}


void VappContactSettingFdnList::onToolBarClicked(VfxObject* obj, VfxId id)
{
    if (!vapp_phb_check_ready() || vapp_phb_check_processing())
    {
        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
        balloon->addItem(VCP_INFO_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_PHB_PROCESSING));
        return;
    }

    if (id == 1)
    {
        m_isNew = VFX_TRUE;
        addClick();
    }
    else
    {
        if (srv_sim_ctrl_pwd_is_enabled(m_simType, SRV_SIM_CTRL_PWD_TYPE_CHV2))
        {
            secsetCuiRun();
            m_secset = TYPE_DELETE;
        }
        else
        {
            deleteFdn();
        }
    }
}


void VappContactSettingFdnList::onEditDone()
{
    m_handle = srv_phb_xdnmgr_get_list((U8) mmi_frm_sim_to_index(m_simType), PHB_FDN, &VappContactSettingFdnList::getListCB, this);
    m_list->resetAllItems(VFX_TRUE);

    if (getCount() == 0)
    {
        ((VcpToolBar *)getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))->setDisableItem(2, VFX_TRUE);
    }
    else
    {
        ((VcpToolBar *)getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))->setDisableItem(2, VFX_FALSE);
    }
}


/***************************************************************************** 
 * Class VappContactSettingFdnEdit
 *****************************************************************************/
VappContactSettingFdnEdit::VappContactSettingFdnEdit()
{
    m_form = NULL;
    m_formName = NULL;
    m_formNumber = NULL;
    name = VFX_WSTR("");
    number = VFX_WSTR("");
    m_isNew = MMI_TRUE;
}


VappContactSettingFdnEdit::VappContactSettingFdnEdit(
    VfxWChar *name_buf,
    VfxWChar *num_buf,
    mmi_sim_enum simType,
    SRV_PHB_XMGNT_HANDLE handle,
    VfxU16 index,
    VfxBool value)
{
    m_form = NULL;
    m_formName = NULL;
    m_formNumber = NULL;
    name.loadFromMem(name_buf);
    number.loadFromMem(num_buf);
    m_simType = simType;
    m_handle = handle;
    m_index = index;
    m_isNew = value;
}


void VappContactSettingFdnEdit::onInit()
{
    VfxPage::onInit();

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    if (m_isNew)
    {
        bar->setTitle(STR_ID_VAPP_PHB_FDN_ADD_TITLE);
    }
    else
    {
        bar->setTitle(STR_ID_VAPP_PHB_FDN_EDIT_TITLE);
    }
    setTopBar(bar);

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    VFX_OBJ_CREATE(m_formName, VcpFormItemTextInput, m_form);
    m_formName->setText(name);
    m_formName->setLabelPosition(VCPFORM_TOP_LEFT);
    m_formName->setLabelText(VAPP_PHB_STR_NAME);

    m_editorName = m_formName->getTextBox();
    VfxS32 length = (VfxS32) srv_phb_startup_get_alpha_length((U8) mmi_frm_sim_to_index(m_simType), PHB_FDN);
    length = (length > MMI_PHB_NAME_FIELD_LENGTH) ? MMI_PHB_NAME_FIELD_LENGTH : length;
    m_editorName->setText(name, length, VFX_FALSE, VCP_TEXT_ENCODING_0X81);
    m_editorName->setIME(IMM_INPUT_TYPE_SENTENCE, IME_DISABLE_NEW_LINE_SYMBOL);
    m_form->addItem(m_formName, 0);

    VFX_OBJ_CREATE(m_formNumber, VcpFormItemTextInput, m_form);
    m_formNumber->setText(number);
    m_formNumber->setLabelPosition(VCPFORM_TOP_LEFT);
    m_formNumber->setLabelText(VAPP_PHB_STR_NUMBER);

    m_editorNumber = m_formNumber->getTextBox();
    m_editorNumber->setIME(IMM_INPUT_TYPE_PHONE_NUMBER_WILDCHAR, IME_PLUS_CHAR_HANDLING);
    m_editorNumber->setMaxLength(MMI_PHB_NUMBER_LENGTH);
    m_form->addItem(m_formNumber, 1);

    VcpFunctionBar *fBar;
    VFX_OBJ_CREATE(fBar, VcpFunctionBar, m_form);
    fBar->addItem((VfxResId)(STR_GLOBAL_PREV),(VfxId)VAPP_PHB_CONTACT_CMD_PREV);
    fBar->addItem((VfxResId)(STR_GLOBAL_NEXT), (VfxId)VAPP_PHB_CONTACT_CMD_NEXT);
    fBar->addItem((VfxResId)(STR_GLOBAL_DONE),(VfxId)VAPP_PHB_CONTACT_CMD_DONE);
    fBar->setItemSpecial(VAPP_PHB_CONTACT_CMD_DONE);
    fBar->setDisableItem(VAPP_PHB_CONTACT_CMD_PREV, VFX_FALSE);
    fBar->setDisableItem(VAPP_PHB_CONTACT_CMD_NEXT, VFX_TRUE);

    fBar->m_signalButtonTap.connect(this, &VappContactSettingFdnEdit::onFuncBarTapped);

    m_editorName->setFunctionBar(fBar, VFX_TRUE);
    m_editorNumber->setFunctionBar(fBar, VFX_TRUE);
    m_editorName->m_signalActivated.connect(this, &VappContactSettingFdnEdit::onEditorActived);
    m_editorNumber->m_signalActivated.connect(this, &VappContactSettingFdnEdit::onEditorActived);

    VcpToolBar *bottom_bar;
    VFX_OBJ_CREATE(bottom_bar, VcpToolBar, this);
    bottom_bar->addItem(1, (VfxResId)(STR_GLOBAL_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    bottom_bar->addItem(2, (VfxResId)(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    setBottomBar(bottom_bar);

    bottom_bar->m_signalButtonTap.connect(this, &VappContactSettingFdnEdit::onToolBarClicked);
}


void VappContactSettingFdnEdit::onFuncBarTapped(VfxObject* obj, VfxId id)
{
    switch (id)
    {
        case VAPP_PHB_CONTACT_CMD_DONE:
        {
            saveFdn();
            break;
        }
        case VAPP_PHB_CONTACT_CMD_PREV:
        {
            m_editorName->activate();
            break;
        }
        case VAPP_PHB_CONTACT_CMD_NEXT:
        {
            m_editorNumber->activate();
            break;
        }
    }
}


void VappContactSettingFdnEdit::onEditorActived(VcpTextEditor *editor, VfxBool isActived)
{
    if (isActived)
    {
        VcpFunctionBar *functionBar = (VcpFunctionBar*) editor->getFunctionBar();

        if (editor == m_editorName)
        {
            functionBar->setDisableItem(VAPP_PHB_CONTACT_CMD_PREV, VFX_TRUE);
            functionBar->setDisableItem(VAPP_PHB_CONTACT_CMD_NEXT, VFX_FALSE);
        }
        else
        {
            functionBar->setDisableItem(VAPP_PHB_CONTACT_CMD_NEXT, VFX_TRUE);
            functionBar->setDisableItem(VAPP_PHB_CONTACT_CMD_PREV, VFX_FALSE);
        }
    }
}


void VappContactSettingFdnEdit::onToolBarClicked(VfxObject* obj, VfxId id)
{
    if (id == 1)
    {
        saveFdn();
    }
    else
    {
        getMainScr()->popPage();
    }
}


void VappContactSettingFdnEdit::saveFdn()
{
    if (m_formNumber->getText().getLength() == 0)
    {
        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
        balloon->addItem(VCP_INFO_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_PHB_PLEASE_INPUT_NUMBER));
        return;
    }

    if (!srv_phb_check_valid_number((U16 *)m_formNumber->getText().getBuf()))
    {
        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
        balloon->addItem(VCP_INFO_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_PHB_INVALID_NUMBER));
        return;
    }

    save();
}


void VappContactSettingFdnEdit::save()
{
    VfxBool value = VFX_FALSE;

    if (srv_phb_fdnmgr_set_entry(
            (U8) mmi_frm_sim_to_index(m_simType),
            PHB_FDN,
            ((!m_isNew) ? srv_phb_xmgnt_get_entry_index(m_handle, m_index) : 0xFFFF),
            0xFFFF,
            (U16 *)m_formName->getText().getBuf(),
            (U16 *)m_formNumber->getText().getBuf(),
            &VappContactSettingFdnEdit::saveFdnRsp,
            m_handle,
            ((m_isNew) ? MMI_TRUE : MMI_FALSE),
            this) != MMI_FALSE)
    {
        value = VFX_TRUE;
    }

    if (!value)
    {
        VappContactSettingFdnEdit *op = (VappContactSettingFdnEdit *)this;
        op->getMainScr()->popPage();
    }
}


void VappContactSettingFdnEdit::saveFdnRsp(VfxU16 result, void* user_data)
{
    if (result != SRV_PHB_XMGNT_RESULT_OK)
    {
        if (result == SRV_PHB_XMGNT_RESULT_EF_FULL)
        {
            VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
            balloon->addItem(VCP_INFO_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_PHB_NUMBER_TOO_LONG));
        }
        else
        {
            VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
            balloon->addItem(VCP_INFO_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_GLOBAL_UNFINISHED));
        }
        return;
    }

    VappContactSettingFdnEdit *op = (VappContactSettingFdnEdit *)user_data;
    op->m_signalSave.emit();
    op->getMainScr()->popPage();
}


/***************************************************************************** 
 * Class VappContactSettingFdnMarkDeleteList
 *****************************************************************************/
VappContactSettingFdnMarkDeleteList::VappContactSettingFdnMarkDeleteList()
{
    m_simType = MMI_SIM1;
    m_list = NULL;
}


VappContactSettingFdnMarkDeleteList::VappContactSettingFdnMarkDeleteList(mmi_sim_enum type)
{
    m_simType = type;
    m_list = NULL;
}


void VappContactSettingFdnMarkDeleteList::onInit()
{
    VfxPage::onInit();

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(STR_ID_VAPP_PHB_FND_MULTI_DELETE_TITLE);
    setTopBar(bar);

    m_handle = srv_phb_xdnmgr_get_list((U8) mmi_frm_sim_to_index(m_simType), PHB_FDN, &VappContactSettingFdnMarkDeleteList::getListCB, this);

    VcpToolBar *bottom_bar;
    VFX_OBJ_CREATE(bottom_bar, VcpToolBar, this);
    bottom_bar->addItem(1, (VfxResId)(STR_GLOBAL_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    bottom_bar->addItem(2, (VfxResId)(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    setBottomBar(bottom_bar);

    bottom_bar->m_signalButtonTap.connect(this, &VappContactSettingFdnMarkDeleteList::onToolBarClicked);

    for (VfxU32 i = 0; i < SRV_PHB_XMGNT_SIM_ENTRIES; i++)
    {
        m_state[i] = MMI_FALSE;
    }
}


VfxU32 VappContactSettingFdnMarkDeleteList::getCount() const
{
    return (VfxU32) srv_phb_xmgnt_get_list_count(m_handle);
}


VfxBool VappContactSettingFdnMarkDeleteList::getItemText(
         VfxU32 index,                    // [IN] the index of item
         VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
         VfxWString &text,                // [OUT] the text resource
         VcpListMenuTextColorEnum &color  // [OUT] the text color
         )
{
    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        if (mmi_wcslen(srv_phb_xmgnt_get_entry_name(m_handle, index)))
        {
            text.loadFromMem(srv_phb_xmgnt_get_entry_name(m_handle, index));
        }
        else
        {
            text.loadFromRes(VAPP_PHB_STR_UNNAMED);
        }
    }

    if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        text.loadFromMem(srv_phb_xmgnt_get_entry_number(m_handle, index));
    }

    return VFX_TRUE;
}


void VappContactSettingFdnMarkDeleteList::onEntered()
{
    if (getSelectCount() == 0)
    {
        ((VcpToolBar *)getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))->setDisableItem(1, VFX_TRUE);
    }
    else
    {
        ((VcpToolBar *)getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))->setDisableItem(1, VFX_FALSE);
    }
    ((VcpToolBar *)getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))->setDisableItem(2, VFX_FALSE);
}


VcpListMenuItemStateEnum VappContactSettingFdnMarkDeleteList::getItemState(VfxU32 index) const
{
    if (m_state[index])
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    else
    {
        return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
    }
}


void VappContactSettingFdnMarkDeleteList::getListCB(VfxU16 result, void* user_data)
{
    VappContactSettingFdnMarkDeleteList *op = (VappContactSettingFdnMarkDeleteList *)user_data;
    op->asycPostInit();
}


void VappContactSettingFdnMarkDeleteList::asycPostInit()
{
    if (m_list == NULL)
    {
        VFX_OBJ_CREATE(m_list, VcpListMenu, this);
    }
    m_list->setSize(getSize());
    m_list->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_list->setContentProvider(this);
    m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
    m_list->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION);

    m_list->m_signalItemTapped.connect(this, &VappContactSettingFdnMarkDeleteList::onItemTapped);

    ((VcpToolBar *)getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))->setDisableItem(1, VFX_TRUE);
}


void VappContactSettingFdnMarkDeleteList::onToolBarClicked(VfxObject* obj, VfxId id)
{
    if (id == 1)
    {
        deleteTap();
    }
    else
    {
        getMainScr()->popPage();
    }
}


void VappContactSettingFdnMarkDeleteList::deleteTap()
{
    VcpConfirmPopup *confirm;
    VFX_OBJ_CREATE(confirm, VcpConfirmPopup, this);

    VfxWString text = VFX_WSTR_RES(STR_GLOBAL_DELETE);
    text += VFX_WSTR_RES(STR_ID_VAPP_PHB_QUESTION);

    confirm->setText(text);
    confirm->setInfoType(VCP_POPUP_TYPE_WARNING);
    confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    confirm->setCustomButton(
        STR_GLOBAL_DELETE,
        STR_GLOBAL_CANCEL,
        VCP_POPUP_BUTTON_TYPE_WARNING,
        VCP_POPUP_BUTTON_TYPE_CANCEL);

    confirm->m_signalButtonClicked.connect(this, &VappContactSettingFdnMarkDeleteList::onButtonClicked);

    confirm->show(VFX_TRUE);
}


void VappContactSettingFdnMarkDeleteList::onButtonClicked(VfxObject* obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        ((VcpToolBar *)getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))->setDisableItem(1, VFX_TRUE);
        ((VcpToolBar *)getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))->setDisableItem(2, VFX_TRUE);
        m_indexDeleting = getCount();
        deleteSelectItems();
    }
}


void VappContactSettingFdnMarkDeleteList::onItemTapped(VcpListMenu *list, VfxU32 index)
{
    VFX_ASSERT(index < SRV_PHB_XMGNT_SIM_ENTRIES);

    m_state[index] = !m_state[index];

    if (getSelectCount() == 0)
    {
        ((VcpToolBar *)getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))->setDisableItem(1, VFX_TRUE);
    }
    else
    {
        ((VcpToolBar *)getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))->setDisableItem(1, VFX_FALSE);
    }
}


void VappContactSettingFdnMarkDeleteList::deleteSelectItems()
{
    m_indexDeleting--;
    if (m_indexDeleting < 0)
    {
        m_signaldelete.emit();
        getMainScr()->popPage();
        return;
    }

    if (m_state[m_indexDeleting])
    {
        deleteOneItem();
    }
    else
    {
        deleteSelectItems();
    }
}


void VappContactSettingFdnMarkDeleteList::deleteOneItem()
{
    srv_phb_xdnmgr_delete_entry(
        (U8) mmi_frm_sim_to_index(m_simType),
        PHB_FDN,
        srv_phb_xmgnt_get_entry_index(m_handle, m_indexDeleting),
        0xFFFF,
        &VappContactSettingFdnMarkDeleteList::deleteFdnRsp,
        this);
}


void VappContactSettingFdnMarkDeleteList::deleteFdnRsp(VfxU16 result, void* user_data)
{
    VappContactSettingFdnMarkDeleteList *op = (VappContactSettingFdnMarkDeleteList *)user_data;
    op->deleteSelectItems();
}


VfxU32 VappContactSettingFdnMarkDeleteList::getSelectCount()
{
    VfxU32 result = 0;

    for (VfxU32 i = 0; i < SRV_PHB_XMGNT_SIM_ENTRIES; i++)
    {
        if (m_state[i])
        {
            result++;
        }
    }

    return result;
}

