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
 *  Vapp_email_setting.cpp
 *
 * Project:
 * --------
 *  COSMOS Email Account Global Setting
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "vapp_email_setting.h"
#include "vapp_email_acct_wizard.h"
#include "vapp_email_acct_setting.h"
#include "vapp_email_mgr.h"
#include "vapp_email_composer.h"

VappEmailGlobalSettingScr *globalSettingScrPtr = NULL;

#ifdef __MTK_INTERNAL__
#ifdef __EMAIL_COSMOS_DBG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

/****************** Account Setting Main Screen (Account List)*****************/
VappEmailGlobalSettingScr::VappEmailGlobalSettingScr()
{
    globalSettingScrPtr = this;
}

VappEmailGlobalSettingScr::~VappEmailGlobalSettingScr()
{
    globalSettingScrPtr = NULL;
}

void VappEmailGlobalSettingScr::on1stReady()
{
    VfxMainScr::on1stReady();

    VappEmailGlobalSettingMainPage *acctSettingMainPage;
    VFX_OBJ_CREATE(acctSettingMainPage, VappEmailGlobalSettingMainPage, this);
    pushPage(0, acctSettingMainPage);
}


void VappEmailSettingSwitch::setChecked(VfxBool checked, VfxBool isAnimated)
{
    m_switch->setChecked(checked, isAnimated);
}


void VappEmailSettingSwitch::show()
{
    setHidden(VFX_FALSE);
    m_switch->setHidden(VFX_FALSE);
}

   
void VappEmailSettingSwitch::hide()
{
    m_switch->setHidden(VFX_TRUE);
    setHidden(VFX_TRUE);
}


void VappEmailSettingSwitch::onInit()
{
    VcpListMenuCellBaseControl::onInit();
    
    VFX_OBJ_CREATE(m_switch, VcpSwitch, this);
    m_switch->setAnchor((VfxFloat)0.5, (VfxFloat)0.5);
    
    setSize(m_switch->getSize());
    
    m_switch->m_signalSwitchChanged.connect(
        this, &VappEmailSettingSwitch::emitSignal);
}


void VappEmailSettingSwitch::setBounds(const VfxRect &value)
{
    VcpListMenuCellBaseControl::setBounds(value);
    
    m_switch->setPos(getSize().width / 2, getSize().height / 2);
}


void VappEmailSettingSwitch::emitSignal(VcpSwitch *sender, VfxBool state)
{
    m_signalSwitchChanged.emit(this, state);
}

void VappEmailGlobalSettingCustomContentFrame::onLayoutElements()
{
    m_textFrame1->setRect(
        VfxRect(
            TEXT1_LEFT_GAPS, 
            TEXT1_TOP_GAPS,
        getRect().getWidth() - TEXT1_LEFT_GAPS - TEXT1_RIGHT_GAPS,
        m_textFrame1->getRect().getHeight()));

    m_textFrame1->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    
    m_textFrame2->setRect(
        VfxRect(
            TEXT2_LEFT_GAPS,
            getRect().getHeight() - TEXT2_BOTTOM_GAPS - m_textFrame2->getRect().getHeight(),
        getRect().getWidth() - TEXT2_LEFT_GAPS - TEXT2_RIGHT_GAPS,
        m_textFrame2->getRect().getHeight()));

    m_textFrame2->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
}

/****************** Account Create Wizard Main Screen ******************/
VappEmailGlobalSettingMainPage::VappEmailGlobalSettingMainPage()
    :
    selectedIndex(VcpMenuPos(0, 0)),
    totalAcct(0),
    showCcBcc(VFX_FALSE),
    priority(EMAIL_MSG_PRIO_MED),
    defaultAcctID(EMAIL_ACCT_INVALID_ID)
{
    initData();
}

void VappEmailGlobalSettingMainPage::initData(void)
{
    srv_email_result_enum res;
    
    for (VfxU32 i = 0; i < MMI_EMAIL_MAX_ACCTS; ++i)
    {
        acctIdArray[i] = EMAIL_ACCT_INVALID_ID;
    }

    res = srv_email_acct_get_default(&defaultAcctID);
    VEMAIL_TRC_GET_DFT_ACCT(res);

    res = srv_email_acct_get_num(&totalAcct);
    VEMAIL_TRC_ACCT_NUM(res, totalAcct);

    VfxS32 realGetTotalAcct = (VfxS32)totalAcct;
    res = srv_email_acct_get_acct_id(0, &realGetTotalAcct, &acctIdArray[0]);
    VEMAIL_TRC_ACCT_NUM(res, realGetTotalAcct);
    
    showCcBcc = VappEmailAcct::getAlwaysShowCcBcc();
    priority = VappEmailAcct::getPriority();
}

VfxU32 VappEmailGlobalSettingMainPage::getCount(VfxU32 group) const 
{
    if (totalAcct == 0 || group == 1)
    {
        return ITEM_TOTAL;
    }
    return totalAcct;
}

VfxU32 VappEmailGlobalSettingMainPage::getGroupCount() const
{
    return 1 + (totalAcct == 0 ? 0 : 1);
}

VfxBool VappEmailGlobalSettingMainPage::getItemText(
    VcpMenuPos pos,
    VcpListMenuFieldEnum fieldType,
    VfxWString &text,
    VcpListMenuTextColorEnum &color)
{
    if (totalAcct == 0 || pos.group == 1)
    {
        switch (pos.pos)
        {
            case -1:
                // group name, index is -1
                text = VFX_WSTR_RES(STR_EMAIL_FTO_GLOBAL_SETTING);
                break;
            case ITEM_SHOW_CC_BCC:
                text = VFX_WSTR_RES(STR_EMAIL_FTO_ALWAYS_SHOW_CC);
                break;
            case ITEM_DEFAULT_ACCT:
                if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
                {
                    text = VFX_WSTR_RES(STR_EMAIL_FTO_DEFAULT_ACCT);
                }
                else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
                {
                    if(defaultAcctID == EMAIL_ACCT_INVALID_ID)
                    {
                        text.loadFromRes(STR_GLOBAL_NONE);
                    }
                    else
                    {
                        srv_email_acct_info_cache_struct acctInfo;
                        srv_email_acct_cache_get(defaultAcctID, &acctInfo);
                        text.loadFromMem((const VfxWChar*)&acctInfo.acct_name);
                    }
                }
                break;

#ifdef __MMI_EMAIL_IMAP_PUSH__
            case ITEM_PUSH_ACCT:
                if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
                {
                    text = VFX_WSTR_RES(STR_EMAIL_FTO_PUSH_ACCT);
                }
                else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
                {
                    EMAIL_ACCT_ID pushAcctId = VappEmailPush::getPushAcctId();

                    if(pushAcctId == EMAIL_ACCT_INVALID_ID)
                    {
                        text.loadFromRes(STR_GLOBAL_NONE);
                    }
                    else
                    {
                        srv_email_acct_info_cache_struct acctInfo;
                        srv_email_acct_cache_get(pushAcctId, &acctInfo);
                        text.loadFromMem((const VfxWChar*)&acctInfo.acct_name);
                    }
                }
                break;
#endif /* #ifdef __MMI_EMAIL_IMAP_PUSH__ */
#ifndef __MMI_EMAIL_STOR_CANNOT_SWITCH__
            case ITEM_STORAGE:
                if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
                {
                    text = VFX_WSTR_RES(STR_GLOBAL_STORAGE);
                }
                else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
                {
                    if (srv_fmgr_drv_get_type(srv_email_get_drive()) ==
                        SRV_FMGR_DRV_PHONE_TYPE)
                    {
                        text = VFX_WSTR_RES(STR_GLOBAL_PHONE);
                    }
                    else
                    {
                        text = VFX_WSTR_RES(STR_GLOBAL_MEMORY_CARD);
                    }
                }
                break;
#endif /* #ifndef __MMI_EMAIL_STOR_CANNOT_SWITCH__ */
            case ITEM_PRIORITY:
                if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
                {
                    text = VFX_WSTR_RES(STR_GLOBAL_PRIORITY);
                }
                else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
                {
                    VfxResId prioStr = STR_GLOBAL_MEDIUM;
                    switch(priority)
                    {
                    case EMAIL_MSG_PRIO_MED:  prioStr = STR_GLOBAL_MEDIUM; break;
                    case EMAIL_MSG_PRIO_LOW:  prioStr = STR_GLOBAL_LOW;    break;
                    case EMAIL_MSG_PRIO_HIGH: prioStr = STR_GLOBAL_HIGH;   break;
                    }
                    text = VFX_WSTR_RES(prioStr);
                }
                break;
        }
        return VFX_TRUE;
    }
    
    if (pos.group == 0)
    {
        if (pos.pos == -1)
        {
            text = VFX_WSTR_RES(STR_EMAIL_FTO_ACCOUNTS);
        }
        else
        {
            srv_email_acct_info_cache_struct acctInfo;
            srv_email_acct_cache_get(acctIdArray[pos.pos], &acctInfo);
            text.loadFromMem((const VfxWChar*)&acctInfo.acct_name);
        }
    }
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    return VFX_TRUE;
}

VfxBool VappEmailGlobalSettingMainPage::getItemTextFormat(
    VcpMenuPos pos, VcpListMenuFieldEnum fieldType, VcpRichText &format)
{
    if ((totalAcct == 0 || pos.group == 1) &&
        pos.pos >= 0 &&
        fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        format.setRange(0, 100);

        VcpListMenuCell* menuCell = m_menu->getCell(pos);
        if (menuCell != NULL && menuCell->m_isHighlight)
        {
            format.setTextColor(VCP_FORM_HIGHLIGHTED_FONT_COLOR);
        }
        else
        {
            format.setTextColor(VCP_FORM_HINT_TEXT_COLOR);
        }
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

VcpListMenuCellClientBaseFrame *
    VappEmailGlobalSettingMainPage::getItemCustomContentFrame(
        VcpMenuPos pos, VfxFrame *parentFrame)
{
    if (((totalAcct == 0 && pos.group == 0) || pos.group == 1) && 
        (pos.pos == ITEM_DEFAULT_ACCT ||
#ifdef __MMI_EMAIL_IMAP_PUSH__
         pos.pos == ITEM_PUSH_ACCT ||
#endif
#ifndef __MMI_EMAIL_STOR_CANNOT_SWITCH__
         pos.pos == ITEM_STORAGE ||
#endif
         pos.pos == ITEM_PRIORITY))
    {
        VappEmailGlobalSettingCustomContentFrame* custFrame;
        VFX_OBJ_CREATE(
            custFrame,
            VappEmailGlobalSettingCustomContentFrame,
            parentFrame);
        return (VcpListMenuCellClientBaseFrame *)custFrame;
    }
    return NULL;
}

VcpListMenuCellBaseControl*
    VappEmailGlobalSettingMainPage::getItemCustomControl(
    VcpMenuPos pos,
    VcpListMenuCellControlLocationTypeEnum location, 
    VfxFrame *parentFrame)
{
    if (((totalAcct == 0 && pos.group == 0) || pos.group == 1) && 
        pos.pos == ITEM_SHOW_CC_BCC && 
        location == VCP_LIST_MENU_CELL_CONTROL_LOCATION_TYPE_TAIL)
    {
        VappEmailSettingSwitch *showCcBccSwitch;
        VFX_OBJ_CREATE(showCcBccSwitch, VappEmailSettingSwitch, parentFrame);
        
        showCcBccSwitch->setChecked(this->showCcBcc, VFX_TRUE);
        showCcBccSwitch->m_signalSwitchChanged.connect(
            this, 
            &VappEmailGlobalSettingMainPage::onShowCcBccSwitchClick);
        
        return (VcpListMenuCellBaseControl*)showCcBccSwitch;
    }

#ifdef __MMI_EMAIL_IMAP_PUSH__
    if (((totalAcct == 0 && pos.group == 0) || pos.group == 1) && 
        pos.pos == ITEM_PUSH_ACCT&& 
        location == VCP_LIST_MENU_CELL_CONTROL_LOCATION_TYPE_TAIL)
    {
        VappEmailSettingSwitch *pushEnableSwitch;
        VFX_OBJ_CREATE(pushEnableSwitch, VappEmailSettingSwitch, parentFrame);
        EMAIL_ACCT_ID imapAcctId[MMI_EMAIL_MAX_ACCTS];
        VfxU32 imapAcctNum;

        VappEmailAcct::getImap4Acct(imapAcctId, imapAcctNum, MMI_EMAIL_MAX_ACCTS);

        if (imapAcctNum == 0)
        {
            VappEmailPush::setEnable(VFX_FALSE);
        }
        
        pushEnableSwitch->setChecked(VappEmailPush::isEnable(), VFX_TRUE);
        pushEnableSwitch->m_signalSwitchChanged.connect(
            this, 
            &VappEmailGlobalSettingMainPage::onPushEnableSwitchClick);
        
        return (VcpListMenuCellBaseControl*)pushEnableSwitch;
    }
#endif /* #ifdef __MMI_EMAIL_IMAP_PUSH__ */
    
    return NULL;
}

VfxBool VappEmailGlobalSettingMainPage::getItemImage(
    VcpMenuPos pos,
    VcpListMenuFieldEnum fieldType, 
    VfxImageSrc &image)
{
    if (fieldType == VCP_LIST_MENU_FIELD_DISCLOSURE_IMG)
    {
        if ((totalAcct != 0 && pos.group == 0) || 
            (((totalAcct != 0 ? 1 : 0) - pos.group == 0) && 
            (pos.pos == ITEM_DEFAULT_ACCT || 
#ifndef __MMI_EMAIL_STOR_CANNOT_SWITCH__
             pos.pos == ITEM_STORAGE || 
#endif
             pos.pos == ITEM_PRIORITY)))
        {
            image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}

VfxBool VappEmailGlobalSettingMainPage::getItemIsHighlightable(
    VcpMenuPos pos) const
{
    if (((totalAcct ? 1 : 0) - pos.group) == 0 && pos.pos == ITEM_SHOW_CC_BCC)
    {
        return VFX_FALSE;
    }
    return VFX_TRUE;
}

VfxBool VappEmailGlobalSettingMainPage::getItemIsDisabled(VcpMenuPos pos) const 
{
#ifdef __MMI_EMAIL_IMAP_PUSH__

    if (((totalAcct ? 1 : 0) - pos.group) == 0 && pos.pos == ITEM_PUSH_ACCT)
    {
        /* disable push email item if there are no IMAP accounts */
        EMAIL_ACCT_ID imapAcctId[MMI_EMAIL_MAX_ACCTS];
        VfxU32 imapAcctNum;
        
        VappEmailAcct::getImap4Acct(imapAcctId, imapAcctNum, MMI_EMAIL_MAX_ACCTS);

        if (imapAcctNum == 0)
        {
            return VFX_TRUE;
        }
        else
        {
            return VFX_FALSE;            
        }
    }
#endif /* #ifdef __MMI_EMAIL_IMAP_PUSH__ */
    return VFX_FALSE;
}


void VappEmailGlobalSettingMainPage::onShowCcBccSwitchClick(
    VappEmailSettingSwitch*,
    VfxBool show_cc_bcc)
{
    VappEmailAcct::setAlwaysShowCcBcc(show_cc_bcc);
}


#ifdef __MMI_EMAIL_IMAP_PUSH__

void VappEmailGlobalSettingMainPage::onPushEnableSwitchClick(
    VappEmailSettingSwitch*,
    VfxBool enable)
{
    VfxBool oldValue = VappEmailPush::isEnable();

    /* Push enable changed */
    if (oldValue != enable)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_SWITCH, enable);
        
        VappEmailPush::setEnable(enable);

        if (enable)
        {
            VappEmailStateEnum emailState = 
                VFX_OBJ_GET_INSTANCE(VappEmailMgr)->getEmailAppState();
            if (emailState == VAPP_EMAIL_STATE_FLIGHT_MODE)
            {
                vapp_email_util_nmgr_balloon(STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE);
                return;
            }
            
            VappEmailMgr::getInstance()->pushStartService();
        }
        else
        {
            VappEmailMgr::getInstance()->pushStopService(VAPP_EMAIL_MGR_STOP_CAUSE_NONE);
        }
    }

}

#endif /* #ifdef __MMI_EMAIL_IMAP_PUSH__ */

EMAIL_ACCT_ID VappEmailGlobalSettingMainPage::getAcctId(VfxU32 index) const
{
    if (index >= totalAcct)
    {
        return EMAIL_ACCT_INVALID_ID;
    }
    return acctIdArray[index];
}

void VappEmailGlobalSettingMainPage::onInit()
{
    VfxPage::onInit();

    vapp_email_set_titlebar(VFX_WSTR_RES(STR_EMAIL_FTO_EMAIL_SETTING), this);

    // Create the list menu object
    VFX_OBJ_CREATE(m_menu, VcpGroupListMenu, this); 

    // Assign content provider 
    m_menu->setContentProvider(this);
    m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT_EX);
    m_menu->setMenuControlMode(
        VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE,
        VFX_FALSE);
    m_menu->m_signalItemTapped.connect(
        this, &VappEmailGlobalSettingMainPage::onMenuItemTapped);
#ifdef __MTK_INTERNAL__
#ifdef __EMAIL_COSMOS_DBG__
/* under construction !*/
/* under construction !*/
#endif
#endif
    m_menu->setRect(0, 0, getSize().width, getSize().height);
    m_menu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);
    
    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->m_signalButtonTap.connect(
        this, &VappEmailGlobalSettingMainPage::onToolBarClick);
    m_toolBar->addItem(
        'NEWA',
        VFX_WSTR_RES(STR_EMAIL_FTO_NEW_ACCOUNT),
        IMG_EMAIL_FTO_ADD);

    setBottomBar(m_toolBar);
}

void VappEmailGlobalSettingMainPage::onEnter(VfxBool isBackward)
{
    if (isBackward)
    {
        initData();
        m_menu->resetAllItems(VFX_TRUE);
    }
    m_toolBar->setDisableItem('NEWA', totalAcct == MMI_EMAIL_MAX_ACCTS);
}


void VappEmailGlobalSettingMainPage::onToolBarClick(VfxObject* sender, VfxId id)
{
    switch(id)
    {
    case 'NEWA':
        VappEmailAcctWizardScreen *aws;
        VFX_OBJ_CREATE(aws, VappEmailAcctWizardScreen, getApp());
        aws->show();
        break;
    }
}

#ifdef __MTK_INTERNAL__
#ifdef __EMAIL_COSMOS_DBG__
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
#endif
#endif

void VappEmailGlobalSettingMainPage::onMenuItemTapped(
    VcpGroupListMenu *menu,
    VcpMenuPos pos)
{
    if (pos.pos < 0)
    {
        return;
    }
    
    if (getGroupCount() == 2 && pos.group == 0)
    {
        VappEmailAcctSettingScreen *ass;
        EMAIL_ACCT_ID selectedAcctId = getAcctId(pos.pos);

        VappEmailResEnum vres;
        vres = VappEmailMgr::getInstance()->editAcctStart(selectedAcctId);
        if (vres != VAPP_EMAIL_RES_SUCC)
        {
            VfxResId errStrId;
            if (vres == VAPP_EMAIL_RES_NETWORK_RUNNING)
            {
                errStrId = STR_EMAIL_FTO_EDIT_ACCT_USING;
            }
            else
            {
                errStrId = STR_GLOBAL_ERROR;
            }
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_INFO,
                (WCHAR*)(GetString(errStrId)));
            VEMAIL_TRC_EDIT_ACCT_BGN(vres);
            return;
        }
            
        VFX_OBJ_CREATE_EX(
            ass,
            VappEmailAcctSettingScreen,
            getApp(),
            (selectedAcctId));

        srv_email_result_enum res = ass->show();
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            VFX_OBJ_CLOSE(ass);

            VEMAIL_TRC_CREATE_ACCT_SCR(res);

            vapp_email_alert_cfm(STR_GLOBAL_ERROR);
        }
    }
    else if (getGroupCount() - 1 == pos.group)
    {
        switch(pos.pos)
        {
            case VappEmailGlobalSettingMainPage::ITEM_DEFAULT_ACCT:
            {
                VappEmailGlobalSettingDftAcctPage *dftAcctPage;
                VFX_OBJ_CREATE(
                    dftAcctPage,
                    VappEmailGlobalSettingDftAcctPage,
                    this);
                getMainScr()->pushPage(0, dftAcctPage);
                break;
            }

#ifdef __MMI_EMAIL_IMAP_PUSH__
            case VappEmailGlobalSettingMainPage::ITEM_PUSH_ACCT:
            {
                VappEmailGlobalSettingPushAcctPage *pushAcctPage;
                VFX_OBJ_CREATE(
                    pushAcctPage,
                    VappEmailGlobalSettingPushAcctPage,
                    this);
                getMainScr()->pushPage(0, pushAcctPage);
                break;                
            }
#endif /* #ifdef __MMI_EMAIL_IMAP_PUSH__ */
#ifndef __MMI_EMAIL_STOR_CANNOT_SWITCH__
            case VappEmailGlobalSettingMainPage::ITEM_STORAGE:
            {
                VappEmailGlobalSettingStoragePage *storagePage;
                VFX_OBJ_CREATE(
                    storagePage,
                    VappEmailGlobalSettingStoragePage,
                    this);
                getMainScr()->pushPage(0, storagePage);
                break;
            }
#endif
            case VappEmailGlobalSettingMainPage::ITEM_PRIORITY:
            {
                VfxResId item_res[] =
                    {
                        STR_GLOBAL_LOW,
                        STR_GLOBAL_MEDIUM,
                        STR_GLOBAL_HIGH
                    };
                VappEmailListSingleSelectTmplPage *prioPage;
                VFX_OBJ_CREATE_EX(
                    prioPage,
                    VappEmailListSingleSelectTmplPage,
                    this,
                    (VFX_FALSE));
                prioPage->setListItem(3, STR_GLOBAL_PRIORITY, item_res);

                VfxU32 index = 1;
                switch(VappEmailAcct::getPriority())
                {
                    case EMAIL_MSG_PRIO_LOW: index = 0; break;
                    case EMAIL_MSG_PRIO_MED: index = 1; break;
                    case EMAIL_MSG_PRIO_HIGH: index = 2; break;
                }
                prioPage->setInitSelectItem(index);
                prioPage->m_signal_save.connect(
                    this, &VappEmailGlobalSettingMainPage::onPrioritySave);
                getMainScr()->pushPage(0, prioPage);
                break;
            }
        }
    }
}

void VappEmailGlobalSettingMainPage::onPrioritySave(
    VfxObject *obj, VfxS32 selectedIndex)
{
    EMAIL_MSG_PRIO prio = EMAIL_MSG_PRIO_MED;

    switch(selectedIndex)
    {
        case 0: prio = EMAIL_MSG_PRIO_LOW; break;
        case 1: prio = EMAIL_MSG_PRIO_MED; break;
        case 2: prio = EMAIL_MSG_PRIO_HIGH; break;
    }
    VappEmailAcct::setPriority(prio);
    getMainScr()->popPage();
}

#ifndef __MMI_EMAIL_STOR_CANNOT_SWITCH__
void VappEmailGlobalSettingStoragePage::initData(void)
{
    if (srv_email_get_drive() == 
        srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_PHONE_TYPE))
    {
        initDrvIndex = MENU_ITEM_PHONE;
    }
    else
    {
        initDrvIndex = MENU_ITEM_TCARD;
    }

    /* Check is memory card accessable */
    isMemoryCardValid = srv_fmgr_drv_is_accessible(
        srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)) == MMI_TRUE;
}


void VappEmailGlobalSettingStoragePage::onInit()
{
    VfxPage::onInit();

    initData();

    vapp_email_set_titlebar(STR_GLOBAL_STORAGE, this);   
    
    VFX_OBJ_CREATE(m_menu, VcpListMenu, this);
    m_menu->setContentProvider(this);
    m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_menu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_TRUE);
    m_menu->m_signalItemTapped.connect(
        this, &VappEmailGlobalSettingStoragePage::onItemTapped);
    m_menu->setRect(0, 0, getSize().width, getSize().height);    
    m_menu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);

    VappEmailMgr::getInstance()->m_signalTcardPlug.connect(
        this, &VappEmailGlobalSettingStoragePage::onTcardPlug);
}

void VappEmailGlobalSettingStoragePage::onEnter(VfxBool isBackward)
{
    if (isBackward)
    {
    initData();
}
}

void VappEmailGlobalSettingStoragePage::onTcardPlug(VfxBool in)
{
    initData();
    m_menu->updateAllItems();
}

void VappEmailGlobalSettingStoragePage::onItemTapped(VcpListMenu *, VfxU32 index)
{
    if (initDrvIndex == index)
    {
        getMainScr()->popPage();
        return;
    }

#ifdef __MTK_INTERNAL__
#ifdef __EMAIL_COSMOS_DBG__
/* under construction !*/
#endif
#endif

    // switch storage
    VEMAIL_TRC_SWITCH_STOR(0);
    VappEmailMgr::getInstance()->switchStorage(
        srv_fmgr_drv_get_letter_by_type(index == MENU_ITEM_PHONE ? 
                        SRV_FMGR_DRV_PHONE_TYPE : SRV_FMGR_DRV_CARD_TYPE));
    VappEmailMgr::getInstance()->m_signalStorageFinishSwitch.connect(
        this, &VappEmailGlobalSettingStoragePage::onSwitchStorage);

#ifdef __MTK_INTERNAL__
#ifdef __EMAIL_COSMOS_DBG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

    VFX_OBJ_CREATE(indicator_pop, VcpIndicatorPopup, this);
            vapp_email_indicator_pop(
                &indicator_pop,
                STR_EMAIL_FTO_SWITCHING,
                this,
                VCP_INDICATOR_POPUP_STYLE_ACTIVITY);

#ifdef __MTK_INTERNAL__
#ifdef __EMAIL_COSMOS_DBG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
}

void VappEmailGlobalSettingStoragePage::onSwitchStorage(VappEmailResEnum res)
{
#ifdef __MTK_INTERNAL__
#ifdef __EMAIL_COSMOS_DBG__
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
#endif

    if (res != SRV_EMAIL_RESULT_SUCC)
    {
        vapp_email_alert_cfm(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);
        getApp()->exit();
        return;
    }
    VEMAIL_TRC_SWITCH_STOR(res);
    getMainScr()->popPage();
}

VfxBool VappEmailGlobalSettingStoragePage::getItemText(
    VfxU32 index,
    VcpListMenuFieldEnum fieldType,
    VfxWString &text,
    VcpListMenuTextColorEnum &color)
{
    if (index == MENU_ITEM_PHONE)
        {
            text = VFX_WSTR_RES(STR_GLOBAL_PHONE);
        }
    else if (index == MENU_ITEM_TCARD)
        {
            text = VFX_WSTR_RES(STR_GLOBAL_MEMORY_CARD);
        }
    else
    {
        return VFX_FALSE;
    }
        return VFX_TRUE;
    }

VfxBool VappEmailGlobalSettingStoragePage::getItemIsDisabled(
        VfxU32 index) const
{
    if (index == 0)
    {
    return VFX_FALSE;
}
    else
    {
        return !isMemoryCardValid;
    }
}

VfxU32 VappEmailGlobalSettingStoragePage::getCount() const
{
    return MENU_ITEM_TOTAL;
}

VcpListMenuItemStateEnum VappEmailGlobalSettingStoragePage::getItemState(
    VfxU32 index) const
{
    if (initDrvIndex == index)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}
#endif

void VappEmailGlobalSettingDftAcctPage::initData(void)
{
    m_acctCount = 0;
    m_dftAcctId = EMAIL_ACCT_INVALID_ID;

    srv_email_acct_get_default(&m_dftAcctId);
    srv_email_acct_get_num(&m_acctCount);

    for (VfxU32 i = 0; i < MMI_EMAIL_MAX_ACCTS + 1; ++i)
    {
        m_acctId[i] = EMAIL_ACCT_INVALID_ID;
    }

    if (m_acctCount != 0)
    {
        srv_email_acct_get_acct_id(
            0,
            (VfxS32*)&m_acctCount,
            (EMAIL_ACCT_ID*)&m_acctId[1]);
    }
}

void VappEmailGlobalSettingDftAcctPage::onInit()
{
    VfxPage::onInit();

    initData();

    vapp_email_set_titlebar(VFX_WSTR_RES(STR_EMAIL_FTO_DEFAULT_ACCT), this);

    VFX_OBJ_CREATE(m_menu, VcpListMenu, this);
    m_menu->setContentProvider(this);
    m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_menu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_TRUE);
    m_menu->m_signalItemTapped.connect(
        this, &VappEmailGlobalSettingDftAcctPage::onItemTapped);
    m_menu->setRect(0, 0, getSize().width, getSize().height);
    m_menu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);
}


void VappEmailGlobalSettingDftAcctPage::onEnter(VfxBool isBackward)
{
    if (isBackward)
    {
        initData();
    }
}

void VappEmailGlobalSettingDftAcctPage::onItemTapped(VcpListMenu *, VfxU32 index)
{
    VFX_ASSERT(index <= m_acctCount);
    
    if (m_acctId[index] != m_dftAcctId)
    {
        srv_email_result_enum res;

        if (index == 0)
        {
            res = srv_email_acct_del_default();
        }
        else
        {
            res = srv_email_acct_set_default(m_acctId[index]);
        }

        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            VEMAIL_TRC_SET_DFT_ACCT(res);
        }
    }

    getMainScr()->popPage();
}

VfxBool VappEmailGlobalSettingDftAcctPage::getItemText(
    VfxU32 index,
    VcpListMenuFieldEnum fieldType,
    VfxWString &text,
    VcpListMenuTextColorEnum &color)
{
    if (index == 0)
    {
        text.loadFromRes(STR_GLOBAL_NONE);
        return VFX_TRUE;
    }
    else if (index <= (VfxU32)m_acctCount)
    {
        srv_email_acct_info_cache_struct acctInfo;
        srv_email_acct_cache_get(m_acctId[index], &acctInfo);
        text.loadFromMem((const VfxWChar*)&acctInfo.acct_name);

        return VFX_TRUE;
    }
    return VFX_FALSE;
}

VfxU32 VappEmailGlobalSettingDftAcctPage::getCount() const
{
    return m_acctCount + 1;
}

VcpListMenuItemStateEnum VappEmailGlobalSettingDftAcctPage::getItemState(
    VfxU32 index) const
{
    if (m_acctId[index] == m_dftAcctId)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}


#ifdef __MMI_EMAIL_IMAP_PUSH__


void VappEmailGlobalSettingPushAcctPage::initData(void)
{
    m_acctCount = 0;
    m_pushAcctId = VappEmailPush::getPushAcctId();
    VappEmailAcct::getImap4Acct(m_acctId, m_acctCount, MMI_EMAIL_MAX_ACCTS);
}

void VappEmailGlobalSettingPushAcctPage::onInit()
{
    VfxPage::onInit();

    initData();

    vapp_email_set_titlebar(VFX_WSTR_RES(STR_EMAIL_FTO_PUSH_ACCT), this);

    VFX_OBJ_CREATE(m_menu, VcpListMenu, this);
    m_menu->setContentProvider(this);
    m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_menu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_TRUE);
    m_menu->m_signalItemTapped.connect(
        this, &VappEmailGlobalSettingPushAcctPage::onItemTapped);
    m_menu->setRect(0, 0, getSize().width, getSize().height);
    m_menu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);
}


void VappEmailGlobalSettingPushAcctPage::onEnter(VfxBool isBackward)
{
    if (isBackward)
    {
        initData();
        m_menu->resetAllItems(VFX_TRUE);
    }
}

void VappEmailGlobalSettingPushAcctPage::onItemTapped(VcpListMenu *, VfxU32 index)
{
    VFX_ASSERT(index <= m_acctCount);
    EMAIL_ACCT_ID newPushAcctId = m_acctId[index];
    
    if (newPushAcctId != m_pushAcctId)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_SELECT_ACCT, m_pushAcctId, newPushAcctId);

        VappEmailPush::removePushAcctId(m_pushAcctId);        
        VappEmailPush::addPushAcctId(newPushAcctId);
    }

    getMainScr()->popPage();
}

VfxBool VappEmailGlobalSettingPushAcctPage::getItemText(
    VfxU32 index,
    VcpListMenuFieldEnum fieldType,
    VfxWString &text,
    VcpListMenuTextColorEnum &color)
{
    if (index <= m_acctCount)
    {
        srv_email_acct_info_cache_struct acctInfo;
        srv_email_acct_cache_get(m_acctId[index], &acctInfo);
        text.loadFromMem((const VfxWChar*)&acctInfo.acct_name);

        return VFX_TRUE;
    }
    return VFX_FALSE;
}

VfxU32 VappEmailGlobalSettingPushAcctPage::getCount() const
{
    return m_acctCount;
}

VcpListMenuItemStateEnum VappEmailGlobalSettingPushAcctPage::getItemState(
    VfxU32 index) const
{
    if (m_acctId[index] == m_pushAcctId)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}

#endif /* #ifdef __MMI_EMAIL_IMAP_PUSH__ */
