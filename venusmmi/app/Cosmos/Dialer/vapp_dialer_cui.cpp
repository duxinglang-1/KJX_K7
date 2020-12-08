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
 *  vapp_dialer_cui.cpp
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
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "vapp_dialer_cui.h"
#include "vapp_dialer_main.h"
#include "vcui_dialer_gprot.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "custom_ecc.h"
#include "mmi_rp_cui_dialer_def.h"
#include "mmi_rp_srv_ucm_def.h"
#include "PhoneSetupResList.h"
#include "ModeSwitchSrvGprot.h"
#include "mmi_frm_utility_gprot.h"

#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

/***************************************************************************** 
 * Class VappDialerCUI
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappDialerCUI", VappDialerCUI, VfxCui);

void VappDialerCUI::onRun(void* args, VfxU32 argSize)
{
    VfxCui::onRun(args, argSize);

    VappDialerCuiMainScr *scr;
    VFX_OBJ_CREATE_EX(scr, VappDialerCuiMainScr, this, (m_type));
    scr->show();
}


void VappDialerCUI::dialCallback(mmi_ucm_after_make_call_cb_struct* para)
{
    if (para->result != SRV_UCM_RESULT_CANCEL)
    {
        VappDialerCUI *cui = NULL;

        cui = (VappDialerCUI *)VfxObject::handleToObject((VfxObjHandle) para->user_data);
        if (!cui)
        {
            return;
        }

        mmi_group_event_struct evt;
        MMI_FRM_INIT_GROUP_EVENT(
            &evt,
            EVT_ID_CUI_DIALER_CLOSE_REQ,
            cui->getGroupId());
        
        cui->sendToCaller(&evt);
    }
}


/***************************************************************************** 
  * Class VappDialerCuiMainScr
  *****************************************************************************/
void VappDialerCuiMainScr::on1stReady()
{
    VfxMainScr::on1stReady();

    VfxImageFrame *edit_backgroup;
    VFX_OBJ_CREATE(edit_backgroup, VfxImageFrame, this);
    edit_backgroup->setResId(IMG_ID_PHNSET_WP_0);
    edit_backgroup->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    edit_backgroup->setPos(0, 0);
    edit_backgroup->setSize(getSize().width, getSize().height);
    edit_backgroup->setPosZ(10.0f);

    VappDialerCuiPage *page;
    VFX_OBJ_CREATE(page, VappDialerCuiPage, this);
    pushPage(VFX_ID_NULL, page);
}


void VappDialerCuiMainScr::on2ndReady()
{
    VfxMainScr::on2ndReady();

    VappDialerCuiPage *page = VFX_OBJ_DYNAMIC_CAST(getPage(getBottomPageId()), VappDialerCuiPage);
    VFX_ASSERT(page != NULL);
    page->m_dialPad->getEditBox()->activate();
}


/***************************************************************************** 
  * Class VappDialerCuiPage
  *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappDialerCuiPage", VappDialerCuiPage, VfxPage);

void VappDialerCuiPage::onInit()
{
    VfxPage::onInit();

    VcpDialerPad::VappDialerTypeEnum type;
    if (((VappDialerCuiMainScr *)getMainScr())->getType() == VCUI_DIALER_TYPE_CLASSIC)
    {
        type = VcpDialerPad::VCP_DIALER_EDIT_BEFORE_CALL;
    }
    else
    {
        type = VcpDialerPad::VCP_DIALER_EMERGENCY;
    }
    VFX_OBJ_CREATE_EX(m_dialPad, VcpDialerPad, this, (type, MMI_SIM_NONE));
    VFX_ALLOC_NEW(m_operate, DialerOperationCUI, this);

    m_operate->setParentScr(getMainScr());

    m_dialPad->getEditBox()->setText(((VappDialerCUI *)getApp())->getString(), MMI_PHB_NUMBER_LENGTH);
    if (m_dialPad->m_type == VcpDialerPad::VCP_DIALER_EDIT_BEFORE_CALL)
    {
        m_dialPad->getEditBox()->setCursorIndex(0);
    }
    else
    {
        m_dialPad->getEditBox()->setCursorIndex(mmi_wcslen(((VappDialerCUI *)getApp())->getString()));
    }
#if defined(__MMI_MAINLCD_320X480__)
    m_dialPad->setRect(0, 87, getSize().width, 320);
#elif defined(__MMI_MAINLCD_480X800__)
    m_dialPad->setRect(0, 126, getSize().width, 520);
#elif defined(__MMI_MAINLCD_240X320__)
    m_dialPad->setRect(0, 28, getSize().width, 250);
#else
    m_dialPad->setRect(0, 78, getSize().width, 250);
#endif
    setComponentAction();
    mmi_frm_cb_reg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, VappDialerCuiPage::refleshCallBtn, this);
}


void VappDialerCuiPage::onDeinit()
{
    mmi_group_event_struct evt;
    MMI_FRM_INIT_GROUP_EVENT(
        &evt,
        EVT_ID_CUI_DIALER_CLOSED_IND,
        getApp()->getGroupId());
    
    getApp()->sendToCaller(&evt);

    VFX_FREE_MEM(m_operate);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, VappDialerCuiPage::refleshCallBtn, this);

    VfxPage::onDeinit();
}


void VappDialerCuiPage::onEntered()
{
    m_dialPad->m_dialButton->setPreferSIM(m_dialPad->getPreferSIM());
    m_dialPad->m_dialButton->refleshComboBtn();
}


void VappDialerCuiPage::onEnter(VfxBool isBackward)
{
    m_dialPad->registerExtraControl();
}


void VappDialerCuiPage::onExit(VfxBool isBackward)
{
    m_dialPad->unRegisterExtraControl();
}


VfxBool VappDialerCuiPage::onKeyInput(VfxKeyEvent &event)
{
    switch (event.keyCode)
    {
        case VFX_KEY_CODE_SEND:
        {
            if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
            {
                mmi_group_event_struct evt;
                MMI_FRM_INIT_GROUP_EVENT(
                    &evt,
                    EVT_ID_CUI_DIALER_BEFORE_CALL_LAUNCHED,
                    getApp()->getGroupId());
                
                getApp()->sendToCaller(&evt);

                if (m_dialPad->m_type == VcpDialerPad::VCP_DIALER_EMERGENCY)
                {
                    m_operate->onSendKey(m_dialPad->getEditBox()->getText(), MMI_SIM_END_OF_ENUM);
                }
                else
                {
                    m_operate->onSendKey(m_dialPad->getEditBox()->getText(), m_dialPad->m_dialButton->getPreferSIM());
                }
            }
            return VFX_TRUE;
        }
        case VFX_KEY_CODE_0:
        case VFX_KEY_CODE_1:
        case VFX_KEY_CODE_2:
        case VFX_KEY_CODE_3:
        case VFX_KEY_CODE_4:
        case VFX_KEY_CODE_5:
        case VFX_KEY_CODE_6:
        case VFX_KEY_CODE_7:
        case VFX_KEY_CODE_8:
        case VFX_KEY_CODE_9:
        case VFX_KEY_CODE_CLEAR:
        case VFX_KEY_CODE_STAR:
        case VFX_KEY_CODE_POUND:
    #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
        case VFX_KEY_CODE_O:
        case VFX_KEY_CODE_P:
        case VFX_KEY_CODE_W:
        case VFX_KEY_CODE_BACKSPACE:
    #endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */
        {
            m_dialPad->getEditBox()->activate();
            m_dialPad->getEditBox()->processKeyInput(event);
            break;
        }
    }

    return VFX_FALSE;
}


void VappDialerCuiPage::setComponentAction()
{
    m_dialPad->m_dialButton->m_signalCallButtonPress.connect(this, &VappDialerCuiPage::onCallButtonClick);
    m_dialPad->m_signalDialerStringChanged.connect(this, &VappDialerCuiPage::onDialerStringChange);
}


void VappDialerCuiPage::onCallButtonClick(VcpGroupButton::VcpGroupButtonTypeEnum type)
{
    mmi_group_event_struct evt;
    MMI_FRM_INIT_GROUP_EVENT(
        &evt,
        EVT_ID_CUI_DIALER_BEFORE_CALL_LAUNCHED,
        getApp()->getGroupId());
    
    getApp()->sendToCaller(&evt);

    DialerOperationCUI::DialerCallTypeEnum callType = (DialerOperationCUI::DialerCallTypeEnum) type;
    if (type == VcpGroupButton::VCP_BUTTON_EMERGENCY)
    {
        m_operate->onSendKey(m_dialPad->getEditBox()->getText(), MMI_SIM_END_OF_ENUM);
    }
    else
    {
        m_operate->onCallBtn(callType, m_dialPad->getEditBox()->getText());
    }
}


void VappDialerCuiPage::onDialerStringChange(VcpTextEditor *edit_box)
{
    vcui_dialer_set_dial_string(getApp()->getGroupId(), VfxWString().loadFromMem(edit_box->getText()));
}


mmi_ret VappDialerCuiPage::refleshCallBtn(mmi_event_struct* evt)
{
    VappDialerCuiPage *obj = (VappDialerCuiPage *)evt->user_data;
    obj->m_dialPad->m_dialButton->refleshComboBtn();

    return MMI_RET_OK;
}


extern "C"
{
    mmi_id vcui_dialer_create(mmi_id parent_id)
    {
        mmi_id cui_id = VfxAppLauncher::createCui(
                        VCUI_DIALER_MAKE_CALL,
                        VFX_OBJ_CLASS_INFO(VappDialerCUI),
                        parent_id);
        return cui_id;
    }


    mmi_id cui_dialer_create(mmi_id parent_id)
    {
        return vcui_dialer_create(parent_id);
    }


    mmi_id vcui_dialer_create_ex(mmi_id parent_id, vcui_dialer_type_enum type)
    {
        mmi_id cui_id = VfxAppLauncher::createCui(
                        VCUI_DIALER_MAKE_CALL,
                        VFX_OBJ_CLASS_INFO(VappDialerCUI),
                        parent_id);

        VappDialerCUI *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id) ,VappDialerCUI);
        VFX_ASSERT(obj != NULL);

        obj->setType(type);
        return cui_id;
    }


    mmi_id cui_dialer_create_ex(mmi_id parent_id, cui_dialer_type_enum type)
    {
        switch (type)
        {
            case CUI_DIALER_TYPE_CLASSIC:
            {
                return vcui_dialer_create_ex(parent_id, VCUI_DIALER_TYPE_CLASSIC);
            }
            case CUI_DIALER_TYPE_SOS:
            {
                return vcui_dialer_create_ex(parent_id, VCUI_DIALER_TYPE_EMERGENCY);
            }
        }

        return GRP_ID_INVALID;
    }


    void vcui_dialer_run(mmi_id cui_id)
    {
        VfxAppLauncher::runCui(cui_id);
    }


    void cui_dialer_run(mmi_id cui_id)
    {
        vcui_dialer_run(cui_id);
    }


    void vcui_dialer_close(mmi_id cui_id)
    {
        VfxAppLauncher::terminate(cui_id);
    }


    void cui_dialer_close(mmi_id cui_id)
    {
        vcui_dialer_close(cui_id);
    }


    void vcui_dialer_set_dial_string(mmi_id cui_id, const VfxWString &string)
    {
        VappDialerCUI *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id) ,VappDialerCUI);
        VFX_ASSERT(obj != NULL);
        
        obj->setString(string);
    }


    void cui_dialer_set_dial_string(mmi_id cui_id, const WCHAR *string)
    {
        vcui_dialer_set_dial_string(cui_id, VfxWString().loadFromMem((VfxWChar *)string));
    }


    const VfxWString &vcui_dialer_get_dial_string(mmi_id cui_id)
    {
        VappDialerCUI *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id) ,VappDialerCUI);
        VFX_ASSERT(obj != NULL);
        
        return obj->getString();
    }


    const WCHAR *cui_dialer_get_dial_string(mmi_id cui_id)
    {
        return vcui_dialer_get_dial_string(cui_id).getBuf();
    }


    void vcui_dialer_set_phb_data(mmi_id cui_id, void *phb_data)
    {
        VappDialerCUI *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id) ,VappDialerCUI);
        VFX_ASSERT(obj != NULL);
        
        obj->setPhbData(phb_data);
    }


    void cui_dialer_set_phb_data(mmi_id cui_id, void *phb_data)
    {
        vcui_dialer_set_phb_data(cui_id, phb_data);
    }


    void *vcui_dialer_get_phb_data(mmi_id cui_id)
    {
        VappDialerCUI *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id) ,VappDialerCUI);
        VFX_ASSERT(obj != NULL);
        
        return obj->getPhbData();
    }


    void *cui_dialer_get_phb_data(mmi_id cui_id)
    {
        return vcui_dialer_get_phb_data(cui_id);
    }
}

