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
 *  vapp_dialer_main.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"
#include "vapp_dialer_main.h"
#include "vapp_dialer_main.h"
#include "vapp_dialer_cui.h"
#include "vapp_dialer_core.h"
#include "vapp_dialer_cp.h"
#include "vcui_phb_gprot.h"
#include "vcui_language_setting_gprot.h"
#include "vapp_phb_gprot.h"
#include "vapp_clog_gprot.h"
#include "vapp_sms_gprot.h"
#include "vapp_phb_launch.h"
#include "vapp_clog_ui.h"
#include "vfx_adp_device.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "GlobalResDef.h"
#include "mmi_rp_cui_dialer_def.h"
#include "mmi_rp_vapp_dialer_def.h"
#include "mmi_rp_vapp_contact_def.h"
#include "mmi_rp_srv_calllog_def.h"
#include "GeneralSettingSrvGprot.h"
#include "CallLogSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "TimerEvents.h"
#include "FileMgrSrvGProt.h"
#include "mmi_rp_app_usbsrv_def.h"

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
VfxBool  vapp_dialer_page_exit_g;
#if defined ( __MMI_DIALER_SLIM__) && defined (__MMI_MAINLCD_240X320__)
#else
void    *vapp_dialer_page_p_g;
#endif /* __MMI_DIALER_SLIM_SEARCH__ && __MMI_MAINLCD_240X320__*/
/***************************************************************************** 
 * Function
 *****************************************************************************/

extern "C"
{

static mmi_id vapp_dialer_pre_launch(mmi_sim_enum type)
{
    VfxApp *old_app = VfxAppLauncher::findApp(
                        VAPP_DIALER,
                        VFX_OBJ_CLASS_INFO(VappDialerCalllogContactApp),
                        VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);
    if (old_app)
    {
        VfxAppLauncher::terminate(old_app->getGroupId());
    }

    return VfxAppLauncher::launch(
        VAPP_DIALER,
        VFX_OBJ_CLASS_INFO(VappDialerCalllogContactApp),
        GRP_ID_ROOT,
        &type,
        sizeof(mmi_sim_enum));
}


mmi_id vapp_dialer_launch(void)
{
    mmi_id new_app_id = vapp_dialer_pre_launch(MMI_SIM_NONE);
    return new_app_id;
}


mmi_id vapp_dialer_launch_ex(mmi_sim_enum sim_type)
{
    mmi_id new_app_id = vapp_dialer_pre_launch(sim_type);
    return new_app_id;
}

}


/***************************************************************************** 
 * Class VappDialerCalllogContactApp
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappDialerCalllogContactApp", VappDialerCalllogContactApp, VfxApp);

void VappDialerCalllogContactApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    if (args)
    {
        m_sim = *((mmi_sim_enum *)args);
    }
    else
    {
        m_sim = MMI_SIM_NONE;
    }

    // create and display main screen
    VappDialerCalllogContactScreen *scr;
    VFX_OBJ_CREATE(scr, VappDialerCalllogContactScreen, this);
    scr->show();
}


/***************************************************************************** 
 * Class VappDialerCalllogContactScreen
 *****************************************************************************/
void VappDialerCalllogContactScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    // create and display first page
    VappDialerCalllogContactPage *page;
    VFX_OBJ_CREATE(page, VappDialerCalllogContactPage, this);
    pushPage(0, page);
}


/***************************************************************************** 
 * Class VappDialerCalllogContactPage
 *****************************************************************************/
void VappDialerCalllogContactPage::onInit()
{
    VcpTabCtrlPage::onInit(); // call base class

    // add page to tab control page
    addTab(DCC_PAGE_DIALER + 1, VFX_WSTR_RES(VAPP_PHB_STR_DIAL), VcpStateImage(VAPP_PHB_IMG_TAB_DIALPAD));
    addTab(DCC_PAGE_CALLLOG + 1, VFX_WSTR_RES(VAPP_PHB_STR_CLOGS), VcpStateImage(VAPP_PHB_IMG_TAB_CLOG));
    addTab(DCC_PAGE_CONTACT + 1, VFX_WSTR_RES(VAPP_PHB_STR_CONTACTS), VcpStateImage(VAPP_PHB_IMG_TAB_CONTACT));
    setCurrTab(DCC_PAGE_DIALER + 1);
}


VfxPage* VappDialerCalllogContactPage::onCreateTabPage(VfxId tabId)
{
    // create tab page, and update its content
    //VappDialerCalllogContactApp *obj = VFX_OBJ_DYNAMIC_CAST(getApp(), VappDialerCalllogContactApp);
	VfxPage* page = NULL;

    switch (tabId)
    {
    case DCC_PAGE_DIALER + 1:
        VFX_OBJ_CREATE(page, VappDialerPage, this);
		break;
    case DCC_PAGE_CALLLOG + 1:
		{
		VappDialerCalllogContactApp *obj = VFX_OBJ_DYNAMIC_CAST(getApp(), VappDialerCalllogContactApp);
        VFX_OBJ_CREATE_EX(page,
            VappCLogList,
            this,
            (VAPP_CLOG_PAGE_FOR_DIALER, VFX_FALSE, VAPP_CLOG_LIST_ID_ALL_CALL, 0, (obj) ? obj->getSim() : MMI_SIM_NONE));
        break;
       	}
    case DCC_PAGE_CONTACT + 1:
       VFX_OBJ_CREATE(page, VappContactPageEx, this);
	   break;
    default:
       break;
    }

    return page;
}


/***************************************************************************** 
 * Class VappDialerPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappDialerPage", VappDialerPage, VfxPage);

void VappDialerPage::onInit()
{
    VfxPage::onInit();

    VappDialerCalllogContactApp *obj = VFX_OBJ_DYNAMIC_CAST(getApp(), VappDialerCalllogContactApp);
    if (obj)
    {
        if (obj->getSim() == MMI_SIM1 || obj->getSim() == MMI_SIM2 || obj->getSim() == MMI_SIM3 || obj->getSim() == MMI_SIM4)
        {
            VFX_OBJ_CREATE_EX(m_dialerPad, VcpDialerPad, this, (VcpDialerPad::VCP_DIALER_NEW_CALL, obj->getSim()));
        }
        else
        {
            VFX_OBJ_CREATE_EX(m_dialerPad, VcpDialerPad, this, (VcpDialerPad::VCP_DIALER_CLASSIC, MMI_SIM_NONE));
        }
    }
    else
    {
        VFX_OBJ_CREATE_EX(m_dialerPad, VcpDialerPad, this, (VcpDialerPad::VCP_DIALER_CLASSIC, MMI_SIM_NONE));
    }

    m_dialerPad->getEditBox()->setText(VFX_WSTR(""), MMI_PHB_NUMBER_LENGTH);
    vapp_dialer_page_exit_g = VFX_FALSE;
#if defined (__MMI_DIALER_SLIM__)  && defined (__MMI_MAINLCD_240X320__)
#else
    VFX_OBJ_CREATE(m_dataProvider, VappContactListMenuContentProvider, this);
    VFX_OBJ_CREATE(m_contactList, VcpListMenu, this);
#endif /* __MMI_DIALER_SLIM_SEARCH__ && __MMI_MAINLCD_240X320__ */
    VFX_ALLOC_NEW(m_operate, DialerOperationClassic, this);

    placeComponent();
    setComponentAction();
    regListener();
#if defined ( __MMI_DIALER_SLIM__) && defined (__MMI_MAINLCD_240X320__)
#else
    vapp_dialer_page_p_g = NULL;
#endif /* __MMI_DIALER_SLIM_SEARCH__  && __MMI_MAINLCD_240X320__ */
}


void VappDialerPage::onDeinit()
{
#if defined (__MMI_DIALER_SLIM__)&& defined (__MMI_MAINLCD_240X320__)
#else
    vapp_dialer_page_p_g = NULL;
#endif /* __MMI_DIALER_SLIM_SEARCH__ && __MMI_MAINLCD_240X320__ */
    deregListener();
    VFX_FREE_MEM(m_operate);
    VFX_OBJ_CLOSE(m_dialerPad);
    vapp_dialer_page_exit_g = VFX_TRUE;
#if defined (__MMI_DIALER_SLIM__) && defined (__MMI_MAINLCD_240X320__)
#else
    VFX_OBJ_CLOSE(m_dataProvider);
#endif /* __MMI_DIALER_SLIM_SEARCH__ && __MMI_MAINLCD_240X320__ */
    VfxPage::onDeinit();
}


mmi_ret VappDialerPage::onProc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_PHB_SAVE_RESULT:
        {
            vcui_phb_contact_saver_close(((vcui_phb_contact_save_result_event_struct*) evt)->sender_id);
            break;
        }
        case EVT_ID_CUI_SIM_LOCATE_RESULT:
        {
            vcui_phb_sim_locator_close(((vcui_phb_sim_locator_result_event_struct*) evt)->sender_id);
            break;
        }
        case EVT_ID_CUI_LANGUAGE_SETTING_CANCEL:
        case EVT_ID_CUI_LANGUAGE_SETTING_SAME_AS_CURRENT_LANGUAGE:
        case EVT_ID_CUI_LANGUAGE_SETTING_DONE:
        {
            mmi_group_event_struct *obj = (mmi_group_event_struct *)evt;
            cui_language_setting_close(obj->sender_id);
            break;
        }
    }

    return MMI_RET_OK;
}


void VappDialerPage::onEntered()
{
    VappPhbApp *obj = VFX_OBJ_DYNAMIC_CAST(getApp(), VappPhbApp);
    if (obj)
    {
        VfxKeyEvent key;
        key.keyCode = (VfxKeyCodeEnum)((U32)obj->getUserData(VAPP_PHB_SUB_APP_DIAL));
        key.type = VFX_KEY_EVENT_TYPE_DOWN;
        if (key.keyCode != VFX_KEY_CODE_UNKNOWN)
        {
            onKeyInput(key);
        }
        obj->setUserData((void *)((S32)VFX_KEY_CODE_UNKNOWN));
    }
    
#if defined (__MMI_DIALER_SLIM__) && defined (__MMI_MAINLCD_240X320__)
#else
    vapp_dialer_page_p_g = this;
    resetDialerList();
#endif /* __MMI_DIALER_SLIM_SEARCH__ && __MMI_MAINLCD_240X320__*/   
    m_dialerPad->refleshDialer();
}


void VappDialerPage::onEnter(VfxBool isBackward)
{
//    m_dialerPad->registerExtraControl();
}


void VappDialerPage::onExit(VfxBool isBackward)
{
   // m_dialerPad->unRegisterExtraControl();
}


void VappDialerPage::onBeforeKeyInput(VcpTextEditor *editor, VfxKeyEvent &event, VfxBool &ret)
{
    if ((event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS && (event.keyCode >= VFX_KEY_CODE_1 && event.keyCode <= VFX_KEY_CODE_9)) ||
         (event.type == VFX_KEY_EVENT_TYPE_DOWN && event.keyCode == VFX_KEY_CODE_POUND))
    {
        ret = VFX_FALSE;
    }
}


VfxBool VappDialerPage::onKeyInput(VfxKeyEvent &event)
{
    if (event.keyCode == VFX_KEY_CODE_SEND && event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        VappDialerCalllogContactApp *obj = VFX_OBJ_DYNAMIC_CAST(getApp(), VappDialerCalllogContactApp);
        if (obj)
        {
            if (obj->getSim() == MMI_SIM1 || obj->getSim() == MMI_SIM2 || obj->getSim() == MMI_SIM3 || obj->getSim() == MMI_SIM4)
            {
                m_operate->onCallBtn((DialerOperationClassic::DialerCallTypeEnum) obj->getSim(), m_dialerPad->getEditBox()->getText());
            }
            else
            {
                m_operate->onCallBtn(DialerOperationClassic::SIM_CALL_END, m_dialerPad->getEditBox()->getText());
            }
        }
        else
        {
            m_operate->onSendKey(m_dialerPad->getEditBox()->getText(), m_dialerPad->m_dialButton->getPreferSIM());
        }

        return VFX_TRUE;
    }

    if (dialerProcessKeyCode(event) && event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS)
    {
        onBtnLongPress((VcpDialerPad::VcpDialerButtonTypeEnum)(event.keyCode - 1), NULL);
        return VFX_TRUE;
    }

    if ((event.keyCode >= VFX_KEY_CODE_0 && event.keyCode <= VFX_KEY_CODE_9) && event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        VfxWString str;
        str.format("%d", event.keyCode - VFX_KEY_CODE_0);
        m_dialerPad->getEditBox()->insertText((VfxWChar *)str.getBuf());
        return VFX_TRUE;
    }

    if (event.keyCode == VFX_KEY_CODE_STAR && event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        m_dialerPad->getEditBox()->insertText('*');
        return VFX_TRUE;
    }

    if (event.keyCode == VFX_KEY_CODE_POUND && event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        m_dialerPad->getEditBox()->insertText('#');
        onPoundBtn(VcpDialerPad::VCP_BUTTON_DIALER_POUND, m_dialerPad->getEditBox()->getText());
        return VFX_TRUE;
    }

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    if (event.keyCode == VFX_KEY_CODE_O && event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        m_dialerPad->getEditBox()->insertText('+');
        return VFX_TRUE;
    }

    if (event.keyCode == VFX_KEY_CODE_P && event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        m_dialerPad->getEditBox()->insertText('p');
        return VFX_TRUE;
    }

    if (event.keyCode == VFX_KEY_CODE_W && event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        m_dialerPad->getEditBox()->insertText('w');
        return VFX_TRUE;
    }
#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */

    return m_dialerPad->getEditBox()->processKeyInput(event);
}


void VappDialerPage::placeComponent()
{
#if defined (__MMI_DIALER_SLIM__) && defined (__MMI_MAINLCD_240X320__)
#else
    m_contactList->setRect(
        0,
        0,
        getSize().width,
    #if defined(__MMI_MAINLCD_320X480__)
        122);
    #elif defined(__MMI_MAINLCD_480X800__)
        223);
    #elif defined(__MMI_MAINLCD_240X320__)
        55);
    #else
        120);
    #endif

    m_contactList->setContentProvider(m_dataProvider);
    m_contactList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT);
    m_contactList->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, MMI_FALSE);
#endif /* __MMI_DIALER_SLIM_SEARCH__ && __MMI_MAINLCD_240X320__*/

    m_dialerPad->setRect(
        0,
    #if defined (__MMI_DIALER_SLIM__)&& defined (__MMI_MAINLCD_240X320__)   
        3,
    #else 
        m_contactList->getRect().getMaxY(),
    #endif /* __MMI_DIALER_SLIM__ && __MMI_MAINLCD_240X320__ */
        getSize().width,
    #if defined(__MMI_MAINLCD_320X480__)
        285
    #elif defined(__MMI_MAINLCD_480X800__)
        456
    #elif defined(__MMI_MAINLCD_240X320__)
      #if defined (__MMI_DIALER_SLIM__)
          245
      #else 
          197
      #endif
    #else
        212
    #endif
		);
     //m_dialerPad->getEditBox()->activate();
    //setFocused(VFX_TRUE);

    m_operate->setParentScr(getMainScr());
}


void VappDialerPage::setComponentAction()
{
    m_dialerPad->m_signalDialerPress.connect(this, &VappDialerPage::onPoundBtn);
    m_dialerPad->m_signalSaveToContactClick.connect(this, &VappDialerPage::onSaveToContact);
    m_dialerPad->m_dialButton->m_signalCallButtonPress.connect(this, &VappDialerPage::onCallButtonClick);
#if defined (__MMI_DIALER_SLIM__) && defined (__MMI_MAINLCD_240X320__)
#else
    m_dialerPad->getEditBox()->m_signalTextChanged.connect(this, &VappDialerPage::onEditChange);
#endif /* __MMI_DIALER_SLIM__  && __MMI_MAINLCD_240X320__*/
    m_dialerPad->getEditBox()->m_signalOnBeforeKeyInput.connect(this, &VappDialerPage::onBeforeKeyInput);
    m_dialerPad->m_signalDialerLongPress.connect(this, &VappDialerPage::onBtnLongPress);
#if defined (__MMI_DIALER_SLIM__) && defined (__MMI_MAINLCD_240X320__)  
#else
    m_contactList->m_signalItemTapped.connect(this, &VappDialerPage::onItemClick);
    m_dataProvider->m_signalRefresh.connect(this , &VappDialerPage::onRefresh);
#endif /* __MMI_DIALER_SLIM__ && __MMI_MAINLCD_240X320__*/  
}


void VappDialerPage::onPoundBtn(VcpDialerPad::VcpDialerButtonTypeEnum type, VfxWChar *str)
{
    if (m_dialerPad->m_type != VcpDialerPad::VCP_DIALER_NEW_CALL)
    {
        m_operate->onPoundBtn(str);
    }
}


VfxBool VappDialerPage::dialerProcessKeyCode(VfxKeyEvent &event)
{
    switch (event.keyCode)
    {
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
            m_dialerPad->getEditBox()->activate();
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}


void VappDialerPage::onSaveToContact(VfxWChar *str)
{
    m_operate->onSaveToContactBtn(str);
}


void VappDialerPage::onCallButtonClick(VcpGroupButton::VcpGroupButtonTypeEnum type)
{
    DialerOperationClassic::DialerCallTypeEnum callType = (DialerOperationClassic::DialerCallTypeEnum) type;
    m_operate->onCallBtn(callType, m_dialerPad->getEditBox()->getText());
    if (!vapp_dialer_page_exit_g && m_dialerPad->m_type != VcpDialerPad::VCP_DIALER_NEW_CALL)
    {
        m_dialerPad->m_dialButton->setPreferSIM(m_dialerPad->getPreferSIM());
        m_dialerPad->m_dialButton->refleshComboBtn();
    }
}


/*VfxBool VappDialerPage::isNewCall()
{
    VappDialerCalllogContactApp *obj = VFX_OBJ_DYNAMIC_CAST(getApp(), VappDialerCalllogContactApp);
    return (obj ? VFX_TRUE : VFX_FALSE);
}*/


#if defined (__MMI_DIALER_SLIM__) && defined (__MMI_MAINLCD_240X320__) 
#else
void VappDialerPage::onEditChange(VcpTextEditor *obj)
{
    m_dataProvider->search(m_dialerPad->getEditBox()->getText());
}


void VappDialerPage::onRefresh()
{
    m_contactList->resetAllItems(VFX_TRUE);
}


void VappDialerPage::onItemClick(VcpListMenu * list, VfxU32 index)
{
    VfxWString temp;
    VcpListMenuTextColorEnum colour;
    m_dataProvider->getItemText(index, VCP_LIST_MENU_FIELD_SUB_TEXT1, temp, colour);
    m_dialerPad->getEditBox()->setText(
        temp,
        MMI_PHB_NUMBER_LENGTH);
    m_dialerPad->getEditBox()->setCursorIndex(mmi_wcslen(m_dialerPad->getEditBox()->getText()));
}

#endif /* __MMI_DIALER_SLIM__ && __MMI_MAINLCD_240X320__  */


void VappDialerPage::onVoiceMailBtnClicked(VfxObject* obj, VfxId id)
{
    switch (id)
    {
        case MMI_SIM1:
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
    #if (MMI_MAX_SIM_NUM >= 4)
        case MMI_SIM4:
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        {
            vapp_sms_call_voicemail((mmi_sim_enum) id);
            break;
        }
    }
}


void VappDialerPage::voiceMailProcess()
{
#if (MMI_MAX_SIM_NUM >= 2)
    MMI_BOOL sim1 = MMI_FALSE, sim2 = MMI_FALSE, sim3 = MMI_FALSE, sim4 = MMI_FALSE;
    sim1 = vapp_sms_check_is_voicemail_valid(MMI_SIM1);
    sim2 = vapp_sms_check_is_voicemail_valid(MMI_SIM2);
#if (MMI_MAX_SIM_NUM >= 3)
    sim3 = vapp_sms_check_is_voicemail_valid(MMI_SIM3);
#if (MMI_MAX_SIM_NUM >= 4)
    sim4 = vapp_sms_check_is_voicemail_valid(MMI_SIM4);
#endif /* (MMI_MAX_SIM_NUM >= 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */

    if (sim1 || sim2 || sim3 || sim4)
    {
        vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
    }

    if (sim1 + sim2 + sim3 + sim4 >= 2)
    {
        VcpCommandPopup *m_commandPopup;
        VFX_OBJ_CREATE(m_commandPopup, VcpCommandPopup, this);
        m_commandPopup->setInfoType(VCP_POPUP_TYPE_INFO);
        m_commandPopup->setText(STR_ID_VAPP_DIALER_VOICE_MAIL);
        if (sim1)
        {
            //m_commandPopup->addItem(MMI_SIM1, VFX_WSTR_RES(STR_GLOBAL_SIM_1));
            m_commandPopup->addItem(MMI_SIM1, (VfxResId)STR_GLOBAL_SIM_1);
        }
        if (sim2)
        {
            //m_commandPopup->addItem(MMI_SIM2, VFX_WSTR_RES(STR_GLOBAL_SIM_2));
            m_commandPopup->addItem(MMI_SIM2, (VfxResId)STR_GLOBAL_SIM_2);
        }
    #if (MMI_MAX_SIM_NUM >= 3)
        if (sim3)
        {
            //m_commandPopup->addItem(MMI_SIM3, VFX_WSTR_RES(STR_GLOBAL_SIM_3));
            m_commandPopup->addItem(MMI_SIM3, (VfxResId)STR_GLOBAL_SIM_3);
        }
    #if (MMI_MAX_SIM_NUM >= 4)
        if (sim4)
        {
            //m_commandPopup->addItem(MMI_SIM4, VFX_WSTR_RES(STR_GLOBAL_SIM_4));
            m_commandPopup->addItem(MMI_SIM4, (VfxResId)STR_GLOBAL_SIM_4);
        }
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
       // m_commandPopup->addItem(MMI_SIM_END_OF_ENUM, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
       m_commandPopup->addItem(MMI_SIM_END_OF_ENUM,(VfxResId)STR_GLOBAL_CANCEL, VCP_POPUP_BUTTON_TYPE_CANCEL);
        m_commandPopup->setAutoDestory(VFX_TRUE);
        m_commandPopup->m_signalButtonClicked.connect(this, &VappDialerPage::onVoiceMailBtnClicked);
        m_commandPopup->show(VFX_TRUE);

        //m_dialerPad->setBtnNormal();
    }
    else
    {
        if (sim1)
        {
            vapp_sms_call_voicemail(MMI_SIM1);
        }
        else if (sim2)
        {
            vapp_sms_call_voicemail(MMI_SIM2);
        }
    #if (MMI_MAX_SIM_NUM >= 3)
        else if (sim3)
        {
            vapp_sms_call_voicemail(MMI_SIM3);
        }
    #if (MMI_MAX_SIM_NUM >= 4)
        else if (sim4)
        {
            vapp_sms_call_voicemail(MMI_SIM4);
        }
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    }
#else /* (MMI_MAX_SIM_NUM >= 2) */
    if (vapp_sms_check_is_voicemail_valid(MMI_SIM1))
    {
        vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
        vapp_sms_call_voicemail(MMI_SIM1);
    }
#endif /* (MMI_MAX_SIM_NUM >= 2) */
}


void VappDialerPage::onBtnLongPress(VcpDialerPad::VcpDialerButtonTypeEnum btn, VfxWChar *ch)
{
    if (m_dialerPad->getEditBox()->getText() && (mmi_wcslen(m_dialerPad->getEditBox()->getText()) != 0))
    {
        return;
    }

    if (btn == VcpDialerPad::VCP_BUTTON_DIALER_1)
    {
        voiceMailProcess();
    }
#ifdef __MMI_PHB_SPEED_DIAL__
    else if (btn >= VcpDialerPad::VCP_BUTTON_DIALER_2 && btn <= VcpDialerPad::VCP_BUTTON_DIALER_9 && srv_phb_speed_dial_is_sync(btn -1))
    {
        vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
        m_dialerPad->getEditBox()->setText(
            VfxWString().loadFromMem(srv_phb_speed_dial_get_number(btn - 1)),
            MMI_PHB_NUMBER_LENGTH);
        m_dialerPad->getEditBox()->setCursorIndex(mmi_wcslen(srv_phb_speed_dial_get_number(btn - 1)));
        ClearKeyEvents();
    }
#endif
}


#if defined (__MMI_DIALER_SLIM__) && defined (__MMI_MAINLCD_240X320__)
#else
void VappDialerPage::resetDialerList()
{
    if (vapp_dialer_page_p_g)
    {
        VappDialerPage *obj = (VappDialerPage *)vapp_dialer_page_p_g;
        obj->m_dataProvider->search(obj->m_dialerPad->getEditBox()->getText());
        obj->m_contactList->resetAllItems(VFX_TRUE);
        vapp_dialer_page_p_g = NULL;
    }
}
#endif /* __MMI_DIALER_SLIM__ && __MMI_MAINLCD_240X320__*/


void VappDialerPage::regListener()
{
#if defined (__MMI_DIALER_SLIM__) && defined (__MMI_MAINLCD_240X320__) 
#else
    mmi_frm_cb_reg_event(EVT_ID_PHB_READY, VappDialerPage::lisener, this);
    mmi_frm_cb_reg_event(EVT_ID_PHB_ADD_CONTACT, VappDialerPage::lisener, this);
    mmi_frm_cb_reg_event(EVT_ID_PHB_DEL_CONTACT, VappDialerPage::lisener, this);
    mmi_frm_cb_reg_event(EVT_ID_PHB_UPD_CONTACT, VappDialerPage::lisener, this);
    mmi_frm_cb_reg_event(EVT_ID_PHB_STORAGE_CHANGE, VappDialerPage::lisener, this);
#ifdef __MMI_PHB_LAST_NAME_FIELD__
    mmi_frm_cb_reg_event(EVT_ID_PHB_NAME_SEQUENCE_CHANGE, VappDialerPage::lisener, this);
#endif
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_ADD_LOG, VappDialerPage::lisener, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_UPDATE_LOG, VappDialerPage::lisener, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_UPDATE_ALL, VappDialerPage::lisener, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_DEL_LOG, VappDialerPage::lisener, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_DEL_ALL, VappDialerPage::lisener, this);
#endif /* __MMI_DIALER_SLIM__ && __MMI_MAINLCD_240X320__ */  
    mmi_frm_cb_reg_event(EVT_ID_PHB_READY, VappDialerPage::refleshDialer, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, VappDialerPage::refleshCallBtn, this);
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, VappDialerPage::onResetStorage, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, VappDialerPage::onResetStorage, this);
    mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, VappDialerPage::onResetStorage, this);
    mmi_frm_cb_reg_event(EVT_ID_USB_EXIT_MS_MODE, VappDialerPage::onResetStorage, this);
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */
}


void VappDialerPage::deregListener()
{
#if defined ( __MMI_DIALER_SLIM__) && defined (__MMI_MAINLCD_240X320__)
#else
    mmi_frm_cb_dereg_event(EVT_ID_PHB_READY, VappDialerPage::lisener, this);
    mmi_frm_cb_dereg_event(EVT_ID_PHB_ADD_CONTACT, VappDialerPage::lisener, this);
    mmi_frm_cb_dereg_event(EVT_ID_PHB_DEL_CONTACT, VappDialerPage::lisener, this);
    mmi_frm_cb_dereg_event(EVT_ID_PHB_UPD_CONTACT, VappDialerPage::lisener, this);
    mmi_frm_cb_dereg_event(EVT_ID_PHB_STORAGE_CHANGE, VappDialerPage::lisener, this);
#ifdef __MMI_PHB_LAST_NAME_FIELD__
    mmi_frm_cb_dereg_event(EVT_ID_PHB_NAME_SEQUENCE_CHANGE, VappDialerPage::lisener, this);
#endif
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_ADD_LOG, VappDialerPage::lisener, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_UPDATE_LOG, VappDialerPage::lisener, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_UPDATE_ALL, VappDialerPage::lisener, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_DEL_LOG, VappDialerPage::lisener, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_DEL_ALL, VappDialerPage::lisener, this);
#endif /* __MMI_DIALER_SLIM__ && __MMI_MAINLCD_240X320__*/    
    mmi_frm_cb_dereg_event(EVT_ID_PHB_READY, VappDialerPage::refleshDialer, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, VappDialerPage::refleshCallBtn, this);
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, VappDialerPage::onResetStorage, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, VappDialerPage::onResetStorage, this);
    mmi_frm_cb_dereg_event(EVT_ID_USB_ENTER_MS_MODE, VappDialerPage::onResetStorage, this);
    mmi_frm_cb_dereg_event(EVT_ID_USB_EXIT_MS_MODE, VappDialerPage::onResetStorage, this);
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */    
}


#if defined (__MMI_DIALER_SLIM__) && defined (__MMI_MAINLCD_240X320__)
#else
mmi_ret VappDialerPage::lisener(mmi_event_struct* evt)
{
    StopTimer(PHB_QUICK_SEARCH_TIMER);
    StartTimer(PHB_QUICK_SEARCH_TIMER, 300, VappDialerPage::resetDialerList);

    switch (evt->evt_id)
    {
        case EVT_ID_PHB_READY:
        case EVT_ID_PHB_ADD_CONTACT:
        case EVT_ID_PHB_DEL_CONTACT:
        case EVT_ID_PHB_UPD_CONTACT:
        case EVT_ID_PHB_STORAGE_CHANGE:
    #ifdef __MMI_PHB_LAST_NAME_FIELD__
        case EVT_ID_PHB_NAME_SEQUENCE_CHANGE:
    #endif
        case EVT_ID_SRV_CLOG_ADD_LOG:
        case EVT_ID_SRV_CLOG_UPDATE_LOG:
        case EVT_ID_SRV_CLOG_UPDATE_ALL:
        case EVT_ID_SRV_CLOG_DEL_LOG:
        case EVT_ID_SRV_CLOG_DEL_ALL:
        {
            vapp_dialer_page_p_g = evt->user_data;
            break;
        }
    }

    return MMI_RET_OK;
}
#endif /* __MMI_DIALER_SLIM__ && __MMI_MAINLCD_240X320__ */

mmi_ret VappDialerPage::refleshDialer(mmi_event_struct* evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_PHB_READY:
        {
            srv_phb_startup_evt_struct *event = (srv_phb_startup_evt_struct *)evt;
            if (event->phb_ready == MMI_TRUE)
            {
                ((VappDialerPage *)evt->user_data)->onEntered();
            }
            break;
        }
    }

    return MMI_RET_OK;
}


mmi_ret VappDialerPage::refleshCallBtn(mmi_event_struct* evt)
{
    VappDialerPage *obj = (VappDialerPage *)evt->user_data;
    obj->m_dialerPad->m_dialButton->refleshComboBtn();

    return MMI_RET_OK;
}


VfxWChar *VappDialerPage::getDialerString() const
{
    return m_dialerPad->getEditBox()->getText();
}


mmi_ret VappDialerPage::onResetStorage(mmi_event_struct* evt)
{
    VfxU16 storageMask = srv_phb_get_storage_mask();
    if (evt->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT || evt->evt_id == EVT_ID_USB_ENTER_MS_MODE)
    {
        storageMask &= ~SRV_PHB_STORAGE_MASK_TCARD;
        srv_phb_set_storage_mask(storageMask);
    }
    else if (evt->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN || evt->evt_id == EVT_ID_USB_EXIT_MS_MODE)
    {
        storageMask |= SRV_PHB_STORAGE_MASK_TCARD;
        srv_phb_set_storage_mask(storageMask);
    }
#if defined (__MMI_DIALER_SLIM__) && defined (__MMI_MAINLCD_240X320__)
#else
    vapp_dialer_page_p_g = evt->user_data;
    resetDialerList();
#endif
    return MMI_RET_OK;
}


/***************************************************************************** 
 * Class VappContactPageEx
 *****************************************************************************/
void VappContactPageEx::onInit()
{
    VfxPage::onInit();

    VFX_OBJ_CREATE(phb_list, VappPhbListCp, this);
    phb_list->setAlignField(MMI_PHB_CONTACT_FIELD_NUMBER);
    phb_list->setListType(VAPP_PHB_LIST_SINGLE);

    phb_list->setSize(getSize());
    phb_list->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    phb_list->m_signalItemTapped.connect(this, &VappContactPageEx::onItemClick);
}


void VappContactPageEx::onItemClick(VcpGroupListMenu *obj, VcpMenuPos index)
{
    IDialerOperation *m_operate;
    VFX_ALLOC_NEW(m_operate, DialerOperationClassic, this);

    m_operate->setParentScr(getMainScr());

    VfxWString num = phb_list->getAlignValue(index.pos, index.group);
    m_operate->onCallBtn((DialerOperationClassic::DialerCallTypeEnum) ((VappDialerCalllogContactApp *)getApp())->getSim(), (VfxWChar *)num.getBuf());

    VFX_FREE_MEM(m_operate);
}


/*****************************************************************************
 * Global Function
 *****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

MMI_ID vapp_dialer_classic_launch(void *param, U32 param_size)
{
    return vapp_dialer_launch();
}


MMI_ID vapp_dialer_launch_from_phb(void *args, U32 argSize)
{
    vapp_phb_sub_app_launch_struct phb_struct;
    phb_struct.sub_app = VAPP_PHB_SUB_APP_DIAL;
    phb_struct.user_data = (void *)((U32)VFX_KEY_CODE_UNKNOWN);
    return vapp_phb_launch(&phb_struct, sizeof(vapp_phb_sub_app_launch_struct));
}


MMI_ID vapp_dialer_launch_from_lock_screen(void *args, U32 argSize)
{
    vapp_phb_sub_app_launch_struct phb_struct;
    if (srv_clog_get_unread_missed_call_num())
    {
        vapp_clog_mclt_launch();
        return GRP_ID_INVALID;
    }
    else
    {
        phb_struct.sub_app = VAPP_PHB_SUB_APP_DIAL;
    }
    phb_struct.user_data = (void *)((U32)VFX_KEY_CODE_UNKNOWN);
    return vapp_phb_launch(&phb_struct, sizeof(vapp_phb_sub_app_launch_struct));
}


MMI_ID vapp_dialer_launch_by_key(VfxKeyCodeEnum key)
{
    vapp_phb_sub_app_launch_struct phb_struct;
    phb_struct.sub_app = VAPP_PHB_SUB_APP_DIAL;
    phb_struct.user_data = (void *)key;
    return vapp_phb_launch(&phb_struct, sizeof(vapp_phb_sub_app_launch_struct));
}


WCHAR * vapp_dialer_get_string()
{
    VfxApp *app = VfxAppLauncher::findApp(
                            VAPP_CONTACT,
                            VFX_OBJ_CLASS_INFO(VappPhbApp),
                            VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);

    if (app)
    {
        VappPhbScr *scr = VFX_OBJ_DYNAMIC_CAST(app->getScreen(app->getBottomScreenId()), VappPhbScr);
        if (!scr)
        {
            return NULL;
        }

        VappPhbPage *page = VFX_OBJ_DYNAMIC_CAST(scr->getPage(scr->getBottomPageId()), VappPhbPage);
        if (!page)
        {
            return NULL;
        }

        VappDialerPage *dialer_page = VFX_OBJ_DYNAMIC_CAST(page->getTabPage(1), VappDialerPage);
        if (!dialer_page)
        {
            return NULL;
        }

        return dialer_page->getDialerString();
    }

    return NULL;
}


WCHAR * mmi_dialer_get_dial_string(void)
{
    return vapp_dialer_get_string();
}

#ifdef __cplusplus
}
#endif

