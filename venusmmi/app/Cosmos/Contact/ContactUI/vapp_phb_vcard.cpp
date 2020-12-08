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
 *  vapp_phb_vcard.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "vapp_phb_vcard.h"
#include "vapp_contact_vcard.h"
#include "vapp_phb_info.h"
#include "vapp_sms_provider.h"
#include "mmi_rp_vapp_contact_def.h"
#include "vcp_global_popup.h"
#include "vcp_form.h"
#include "mmi_rp_app_usbsrv_def.h"
#include "vapp_nmgr_gprot.h"

#ifdef __MMI_VCARD__
extern "C"
{
typedef struct
{
    CHAR  *data;
    U32    data_lengh;
    WCHAR *path;
}vcui_vcard_launch_data_struct;
}


/***************************************************************************** 
 * Class ContactVcardViewer
 *****************************************************************************/
void ContactVcardViewer::onInit()
{
    VfxPage::onInit();

    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, ContactVcardViewer::listener, this);
    mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, ContactVcardViewer::listener, this);

    m_leftNav = NULL;
    m_rightNav = NULL;
    m_title = NULL;
    m_isVertical = VFX_TRUE;

    m_path = ((VappVcardCUI *)getApp())->getPath();

    m_fieldCount = 0;
    placeComponent();
    VFX_OBJ_CREATE_EX(m_dateProvider, ContactVcardViewerData, this, (m_path));
    m_dateProvider->m_signalPassDone.connect(this, &ContactVcardViewer::vcardPassDone);
    createVcardForm();
#ifdef __MMI_MULTI_VACRD__
    m_restore = NULL;
    m_progress = NULL;
#endif
}


void ContactVcardViewer::onDeinit()
{
#ifdef __MMI_MULTI_VCARD__
    if (m_restore)
    {
        m_restore->complete();
        m_restore = NULL;
    }
#endif
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, ContactVcardViewer::listener, this);
    mmi_frm_cb_dereg_event(EVT_ID_USB_ENTER_MS_MODE, ContactVcardViewer::listener, this);

    VfxPage::onDeinit();
}


mmi_ret ContactVcardViewer::onProc(mmi_event_struct *evt)
{
    if (evt->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT)
    {
        if (srv_fmgr_drv_is_removable((U8)m_path[0]))
        {
            getMainScr()->popPage();
        }
    }
    if (evt->evt_id == EVT_ID_USB_ENTER_MS_MODE)
    {
        getMainScr()->popPage();
    }
    return MMI_RET_OK;
}


mmi_ret ContactVcardViewer::listener(mmi_event_struct* evt)
{
    ContactVcardViewer *obj = (ContactVcardViewer *)evt->user_data;
    return obj->onProc(evt);
}


void ContactVcardViewer::vcardPassDone()
{
    if (m_dateProvider->getTotalCount() == 0)
    {
        ContactVcardViewer *obj = this;
        VFX_OBJ_CLOSE(obj);
    }
    else
    {
        ((VcpToolBar *)getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))->setDisableItem(1, VFX_FALSE);
        VFX_OBJ_CLOSE(m_form);
        createVcardForm();
    }
}


void ContactVcardViewer::placeComponent()
{
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_PHB_VCARD_DETAILS));
    setTopBar(titleBar);

    VcpToolBar *bottom_bar;
    VFX_OBJ_CREATE(bottom_bar, VcpToolBar, this);
#ifdef __MMI_MULTI_VCARD__
    bottom_bar->addItem(1, VFX_WSTR_RES(STR_ID_VAPP_PHB_VCARD_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    bottom_bar->setDisableItem(1, VFX_TRUE);
#endif
    bottom_bar->addItem(2, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    setBottomBar(bottom_bar);
    bottom_bar->m_signalButtonTap.connect(this, &ContactVcardViewer::onToolbarClicked);
}


void ContactVcardViewer::createNavBtn()
{
	#ifdef __MMI_MULTI_VCARD__
    if (!m_leftNav && m_dateProvider->getActiveCount() != 0)
    {
        VFX_OBJ_CREATE(m_leftNav, VcpImageButton, this);
        m_leftNav->setRect(VfxRect(30, 30, vcard_nav_icon_size, vcard_nav_icon_size));
        m_leftNav->setAnchor(0.5f, 0.5f);
        m_leftNav->setId(0);
        m_leftNav->setImage(VcpStateImage(VAPP_PHB_VCARD_LEFT_ARROW));
        m_leftNav->setIsEffect(VFX_TRUE);
        m_leftNav->setEffectRatio(1.1f);
        m_leftNav->m_signalClicked.connect(this, &ContactVcardViewer::onBtnClick);
    }

    if (!m_rightNav && m_dateProvider->getTotalCount() != 0xffffffff && m_dateProvider->getActiveCount() != m_dateProvider->getTotalCount() - 1)
    {
        VFX_OBJ_CREATE(m_rightNav, VcpImageButton, this);
        m_rightNav->setRect(VfxRect(getSize().width - 30, 30, vcard_nav_icon_size, vcard_nav_icon_size));
        m_rightNav->setAnchor(0.5f, 0.5f);
        m_rightNav->setId(1);
        m_rightNav->setImage(VcpStateImage(VAPP_PHB_VCARD_RIGHT_ARROW));
        m_rightNav->setIsEffect(VFX_TRUE);
        m_rightNav->setEffectRatio(1.1f);
        m_rightNav->m_signalClicked.connect(this, &ContactVcardViewer::onBtnClick);
    }
#endif
    if (m_leftNav && m_dateProvider->getActiveCount() == 0)
    {
        VFX_OBJ_CLOSE(m_leftNav);
    }
    if (m_rightNav && m_dateProvider->getActiveCount() == m_dateProvider->getTotalCount() - 1)
    {
        VFX_OBJ_CLOSE(m_rightNav);
    }
}


void ContactVcardViewer::createVcardForm()
{
    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setPos(0, 60);
    m_form->setSize(getSize().width, getSize().height - 60);
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    if (!m_title)
    {
        VFX_OBJ_CREATE(m_title, VfxTextFrame, this);
        m_title->setAnchor(0.5f, 0.5f);
        m_title->setPos(getSize().width/2, 30);
        m_title->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        m_title->setColor(VCP_FORM_DARK_FONT_COLOR);
    }

    if (!m_dateProvider->isSingleVcard())
    {
        createNavBtn();
        if (m_dateProvider->getTotalCount() == 0xffffffff)
        {
            m_title->setString(VFX_WSTR_RES(STR_GLOBAL_LOADING));
        }
        else
        {
            m_titleString.format("%d/%d", m_dateProvider->getActiveCount() + 1, m_dateProvider->getTotalCount());
            m_title->setString(m_titleString);
        }
    }
    else
    {
        ((VcpToolBar *)getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))->setDisableItem(1, VFX_FALSE);
        m_title->setString(VFX_WSTR("1/1"));
    }

    nameFieldCreate();
    numberFieldCreate();
    emailFieldCreate();
#ifdef __MMI_PHB_INFO_FIELD__
    addressFieldCreate();
#endif
    birthdayFieldCreate();
#ifdef __MMI_PHB_INFO_FIELD__
    titleFieldCreate();
#endif
#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
    companyFieldCreate();
#endif
#ifdef __MMI_PHB_INFO_FIELD__
    noteFieldCreate();
#endif
}


void ContactVcardViewer::onToolbarClicked(VfxObject* obj, VfxId id)
{
    switch (id)
    {
#ifdef __MMI_MULTI_VCARD__    	
        case 1:
            saveVcard();
            break;
#endif
        case 2:
            getMainScr()->popPage();
            break;
    }
}

#ifdef __MMI_MULTI_VCARD__
void ContactVcardViewer::saveVcard()
{
    VFX_OBJ_CREATE(m_restore, ContactRestore, this);
    if (m_restore->prepare(CONTACT_BACKUP, CONTACT_WANT) == CONTACT_RUN)
    {
        VFX_OBJ_CREATE(m_progress, VcpIndicatorPopup, this);
        m_progress->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON);
        m_progress->setText(VFX_WSTR_RES(STR_ID_VAPP_PHB_VCARD_SAVING));
        m_progress->setProgress(0);
        m_progress->show(VFX_TRUE);
        m_progress->m_signalCanceled.connect(this, &ContactVcardViewer::onCancelClick);

        m_restore->setPath(m_path);
        m_restore->setCB(&ContactVcardViewer::onSaveVcardCB);
        m_restore->setUserData(this);
    #ifdef __VCARD_CLOUD_SUPPORT__
        m_restore->setMode(SRV_PHB_BACKUP_RESTORE_MODE_T_CARD);
    #endif
        m_restore->run();
    }
    else
    {
        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
        balloon->addItem(VCP_INFO_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_PHB_PROCESSING));
    }
}


void ContactVcardViewer::onSaveVcardCB(ContactOP* op, CONTACT_STATE state, srv_phb_async_op_cb_struct* result)
{
    ContactRestore *restore = (ContactRestore *)op;
    if (result->type == SRV_PHB_OP_CB_TYPE_RESTORE)
    {
        srv_phb_restore_cb_struct *backUpFinish = (srv_phb_restore_cb_struct *)result;
        MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_RESTORE_DONE, 2, backUpFinish->type, backUpFinish->finish_count,
                    backUpFinish->fail_count, backUpFinish->total_count, backUpFinish->user_data, backUpFinish->result);

        ContactVcardViewer *obj = (ContactVcardViewer *)(restore->getUserData());
        if (obj->m_restore)
        {
            obj->m_restore->complete();
            obj->m_restore = NULL;
        }
        if (obj->m_progress)
        {
            obj->m_progress->exit(VFX_TRUE);
            obj->m_progress = NULL;
        }

        obj->getMainScr()->popPage();

        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
        STORAGE_STATUS status = ContactStorage::getStatus(PHB_STORAGE_NVRAM);
        VfxWString errorStr;
        if (status == STORAGE_FULL && backUpFinish->finish_count != obj->getDateProvider()->getTotalCount())
        {
            errorStr = ContactStorage::getName(PHB_STORAGE_NVRAM);
            errorStr += VFX_WSTR_RES(STR_ID_VAPP_PHB_STORAGE_IS_FULL);
        }
        else if (backUpFinish->result == SRV_PHB_NO_ERROR)
        {
            errorStr = VFX_WSTR_RES(STR_GLOBAL_SAVED);
        }
        else if (backUpFinish->finish_count >= obj->getDateProvider()->getTotalCount())
        {
            errorStr = VFX_WSTR_RES(STR_GLOBAL_SAVED);
        }
        else
        {
            errorStr = VFX_WSTR_RES(STR_GLOBAL_UNFINISHED);
        }
        balloon->addItem(VCP_INFO_BALLOON_TYPE_INFO, errorStr);
    }
    else
    {
        srv_phb_multi_op_status_cb_struct *backUpUpdata = (srv_phb_multi_op_status_cb_struct *)result;
        MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_RESTORE_CB, 2, backUpUpdata->type, backUpUpdata->finish_count,
                    backUpUpdata->fail_count, backUpUpdata->total_count, backUpUpdata->user_data);

        ContactVcardViewer *obj = (ContactVcardViewer *)(restore->getUserData());
        if (obj->m_progress)
        {
            obj->m_progress->setProgress((VfxFloat)backUpUpdata->finish_count/obj->getDateProvider()->getTotalCount());
        }
    }
}


void ContactVcardViewer::onCancelClick(VfxObject* obj, VfxFloat num)
{
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_SAVE_VCARD_CANCEL]totalCount: %d\n", m_dateProvider->getTotalCount());

    if (m_progress)
    {
        VFX_OBJ_CLOSE(m_progress);
    }
    if (m_restore)
    {
        m_restore->complete();
        m_restore = NULL;
    }
}


void ContactVcardViewer::onBtnClick(VfxObject* obj, VfxId id)
{
    switch (id)
    {
        case 0:
            viewFront();
            break;
        case 1:
            viewNext();
            break;
    }
}


void ContactVcardViewer::viewFront()
{
    VFX_OBJ_CLOSE(m_form);
    m_dateProvider->getFront();
    createVcardForm();
}


void ContactVcardViewer::viewNext()
{
    VFX_OBJ_CLOSE(m_form);
    m_dateProvider->getNext();
    createVcardForm();
}
#endif

void ContactVcardViewer::nameFieldCreate()
{
    VfxU16 count = m_dateProvider->queryCount(VAPP_VCARD_NAME_FIELD);
    VappPhbViewerNameFormItem *m_name;
    VFX_OBJ_CREATE(m_name, VappPhbViewerNameFormItem, m_form);
    if (count > 0)
    {
        m_name->setName(m_dateProvider->getName());
    }
    else
    {
        m_name->setName(VFX_WSTR_RES(VAPP_PHB_STR_UNNAMED));
    }
    m_name->setImage(m_dateProvider->getImage());
    m_form->addItem(m_name, m_fieldCount++);
}


void ContactVcardViewer::numberFieldCreate()
{
    VfxU16 count = m_dateProvider->queryCount(VAPP_VCARD_NUMBER_FIELD);
    VfxU16 index = 0;
    VcpFormItemCell *m_number[VCARD_MAX_TEL_COUNT];
    while (count > 0)
    {
        if (m_dateProvider->checkNumberValid(index))
        {
            VFX_OBJ_CREATE(m_number[index], VcpFormItemCell, m_form);
            m_number[index]->setMainText(m_dateProvider->getNumberLabel(index));
            m_number[index]->setHintText(m_dateProvider->getNumber(index));
            m_number[index]->setIsTappable(VFX_FALSE);
            m_form->addItem(m_number[index], m_fieldCount++);
            count--;
        }
        index++;
    }
}


void ContactVcardViewer::emailFieldCreate()
{
    VfxU16 count = m_dateProvider->queryCount(VAPP_VCARD_EMAIL_FIELD);
    VfxU16 index = 0;
    VcpFormItemCell *m_email[VCARD_MAX_EMAIL_COUNT];
    while (count > 0)
    {
        if (m_dateProvider->checkEmailValid(index))
        {
            VFX_OBJ_CREATE(m_email[index], VcpFormItemCell, m_form);
            m_email[index]->setMainText(m_dateProvider->getEmailLabel(index));
            m_email[index]->setHintText(m_dateProvider->getEmail(index));
            m_email[index]->setIsTappable(VFX_FALSE);
            m_form->addItem(m_email[index], m_fieldCount++);
            count--;
        }
        index++;
    }
}


#ifdef __MMI_PHB_INFO_FIELD__
void ContactVcardViewer::addressFieldCreate()
{
    VfxU16 count = m_dateProvider->queryCount(VAPP_VCARD_ADDRESS_FIELD);
    VfxU16 index = 0;
    VfxU16 sub_index = 0;
    VcpFormItemCell *m_address[VCARD_MAX_ADR_COUNT][7];
    while (count > 0)
    {
        if (m_dateProvider->addressIsValid(index))
        {
            for (sub_index = 0; sub_index < VAPP_VCARD_ADDRESS_ADDRESS_FIELD_END; sub_index++)
            {
                if (m_dateProvider->checkAddressValid(index, (VappVcardAddressFieldEnum)sub_index))
                {
                    VFX_OBJ_CREATE(m_address[index][sub_index], VcpFormItemCell, m_form);
                    m_address[index][sub_index]->setMainText(m_dateProvider->getAddressTitle(index, (VappVcardAddressFieldEnum)sub_index));
                    m_address[index][sub_index]->setHintText(m_dateProvider->getAddress(index, (VappVcardAddressFieldEnum)sub_index));
                    m_address[index][sub_index]->setIsTappable(VFX_FALSE);
                    m_form->addItem(m_address[index][sub_index], m_fieldCount++);
                }
            }
            count--;
        }
        index++;
    }
}
#endif /* __MMI_PHB_INFO_FIELD__ */


void ContactVcardViewer::birthdayFieldCreate()
{
    VfxU16 count = m_dateProvider->queryCount(VAPP_VCARD_BIRTHDAY_FIELD);
    if (count > 0)
    {
        VcpFormItemCell *m_birthday;
        VFX_OBJ_CREATE(m_birthday, VcpFormItemCell, m_form);
        m_birthday->setMainText(VFX_WSTR_RES(VAPP_PHB_STR_BDAY));
        m_birthday->setHintText(m_dateProvider->getBirthday());
        m_birthday->setIsTappable(VFX_FALSE);
        m_form->addItem(m_birthday, m_fieldCount++);
    }
}


#ifdef __MMI_PHB_INFO_FIELD__
void ContactVcardViewer::titleFieldCreate()
{
    VfxU16 count = m_dateProvider->queryCount(VAPP_VCARD_TITLE_FIELD);
    if (count > 0)
    {
        VcpFormItemCell *m_title;
        VFX_OBJ_CREATE(m_title, VcpFormItemCell, m_form);
        m_title->setMainText(VFX_WSTR_RES(VAPP_PHB_STR_TITLE));
        m_title->setHintText(m_dateProvider->getTitle());
        m_title->setIsTappable(VFX_FALSE);
        m_form->addItem(m_title, m_fieldCount++);
    }
}
#endif /* __MMI_PHB_INFO_FIELD__ */


#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
void ContactVcardViewer::companyFieldCreate()
{
    VfxU16 count = m_dateProvider->queryCount(VAPP_VCARD_COMPANY_FIELD);
    if (count > 0)
    {
        VcpFormItemCell *m_company;
        VFX_OBJ_CREATE(m_company, VcpFormItemCell, m_form);
        m_company->setMainText(VFX_WSTR_RES(VAPP_PHB_STR_COMPANY));
        m_company->setHintText(m_dateProvider->getCompany());
        m_company->setIsTappable(VFX_FALSE);
        m_form->addItem(m_company, m_fieldCount++);
    }
}
#endif /* __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__ */


#ifdef __MMI_PHB_INFO_FIELD__
void ContactVcardViewer::noteFieldCreate()
{
    VfxU16 count = m_dateProvider->queryCount(VAPP_VCARD_NOTE_FIELD);
    if (count > 0)
    {
        VcpFormItemCell *m_note;
        VFX_OBJ_CREATE(m_note, VcpFormItemCell, m_form);
        m_note->setMainText(VFX_WSTR_RES(VAPP_PHB_STR_NOTE));
        m_note->setHintText(m_dateProvider->getNote());
        m_note->setIsTappable(VFX_FALSE);
        m_form->addItem(m_note, m_fieldCount++);
    }
}
#endif /* __MMI_PHB_INFO_FIELD__ */


void ContactVcardViewer::onQueryRotateEx(VfxScreenRotateParam &param)
{
}


void ContactVcardViewer::onRotate(
    const VfxScreenRotateParam &param // The parameter to rotate
)
{
    if (param.rotateTo == VFX_SCR_ROTATE_TYPE_90 || param.rotateTo == VFX_SCR_ROTATE_TYPE_270)
    {
        m_isVertical = VFX_FALSE;
    }
    else
    {
        m_isVertical = VFX_TRUE;
    }

    if (m_title)
    {
        m_title->setPos(getSize().width/2, 30);
    }
    if (m_rightNav)
    {
        m_rightNav->setPos(getSize().width - 30, 30);
    }
}


VfxBool ContactVcardViewer::onKeyInput(VfxKeyEvent &event)
{
    if (m_dateProvider->getTotalCount() != 0xffffffff)
    {
        if (event.keyCode == VFX_KEY_CODE_ARROW_LEFT && event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            if (m_dateProvider->getActiveCount() != 0)
            {
        #ifdef __MMI_MULTI_VCARD__
                viewFront();
        #endif
            }
        }
        else if (event.keyCode == VFX_KEY_CODE_ARROW_RIGHT && event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            if (m_dateProvider->getActiveCount() != m_dateProvider->getTotalCount() - 1)
            {
        #ifdef  __MMI_MULTI_VCARD__   
                viewNext();
        #endif
            }
        }
    }

    return VfxPage::onKeyInput(event);
}


/***************************************************************************** 
 * Class VappVcardCUI
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappVcardCUI", VappVcardCUI, VfxCui);
 
void VappVcardCUI::onRun(void* args, VfxU32 argSize)
{
    VfxCui::onRun(args, argSize);

    if (args)
    {
        vcui_vcard_launch_data_struct *data = (vcui_vcard_launch_data_struct *)args;
        if (data->data)
        {
            m_content = data->data;
            m_length = data->data_lengh;
            m_isFromPath = VFX_FALSE;
        }
        if (data->path)
        {
            m_path.loadFromMem(data->path);
            m_isFromPath = VFX_TRUE;
        }
    }

    if (!m_isFromPath)
    {
        deleteTempPath();
        if (!createTempPath())
        {
            VfxAppLauncher::terminate(getGroupId());
            return;
        }
    }

    VappVcardCuiMainScr *scr;
    VFX_OBJ_CREATE(scr, VappVcardCuiMainScr, this);
    scr->show();
}


void VappVcardCUI::setPath(const VfxWString &path)
{
    m_path = path;
    m_isFromPath = VFX_TRUE;
}


void VappVcardCUI::setContent(void *content, VfxU32 len)
{
    m_content = content;
    m_length = len;
    m_isFromPath = VFX_FALSE;
}


void VappVcardCUI::deleteTempPath()
{
    WCHAR path[SRV_FMGR_PATH_MAX_LEN + 1];

    kal_wsprintf(path, "%c:\\%s\\%d.vcf", SRV_FMGR_PUBLIC_DRV, SRV_PHB_VCARD_FILE_PATH, SRV_PHB_VCARD_PORT);
    if (srv_fmgr_fs_path_exist((WCHAR*)path) >= 0)
    {
        FS_Delete(path);
    }
}


void VappVcardCUI::createFolder()
{
    WCHAR path[SRV_FMGR_PATH_MAX_LEN + 1];

    kal_wsprintf(path, "%c:\\%s", SRV_FMGR_PUBLIC_DRV, SRV_PHB_VCARD_FILE_PATH);
    FS_HANDLE handle = FS_Open(path, FS_READ_ONLY| FS_OPEN_DIR);

    if (handle < 0)
    {
        handle = FS_CreateDir(path);
        if (handle < FS_NO_ERROR)
        {
            /* Do not care error. */
            return;
        }
        else
        {
            FS_SetAttributes(path, FS_ATTR_DIR /*| FS_ATTR_HIDDEN*/);
        }
    }
    FS_Close(handle);
}


VfxBool VappVcardCUI::createTempPath()
{
    createFolder();

    WCHAR path[SRV_FMGR_PATH_MAX_LEN + 1];
    kal_wsprintf((WCHAR*)path, "%c:\\%s\\%d.vcf", SRV_FMGR_PUBLIC_DRV, SRV_PHB_VCARD_FILE_PATH, SRV_PHB_VCARD_PORT);
    m_path.loadFromMem(path);

    FS_HANDLE fh;
    fh = FS_Open(path, FS_CREATE_ALWAYS | FS_READ_WRITE);
    
    if (fh > 0)
    {
        /* hide this received file*/
        FS_SetAttributes((const WCHAR *)path, (U8) FS_ATTR_HIDDEN);
        VfxU32 write_len;
        VfxS32 check_result;
        check_result = FS_Write(fh, m_content, m_length, &write_len);
        FS_Close(fh);
    
        if (check_result == FS_NO_ERROR)
        {
            return VFX_TRUE;
        }
        else
        {
            fh = check_result;
        }
    }

    vapp_nmgr_global_popup_show_confirm_one_button_id(
            MMI_SCENARIO_ID_DEFAULT,
            VCP_POPUP_TYPE_FAILURE,
            srv_fmgr_fs_error_get_string(fh),
            STR_GLOBAL_OK,
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            NULL,
            NULL);

    return VFX_FALSE;
}


/***************************************************************************** 
 * Class VappVcardCuiMainScr
 *****************************************************************************/
void VappVcardCuiMainScr::on1stReady()
{
    VfxMainScr::on1stReady();
    ContactVcardViewer *page;
    VFX_OBJ_CREATE(page, ContactVcardViewer, this);
    pushPage(VFX_ID_NULL, page);
}



mmi_id vcui_vcard_create(mmi_id parent_id)
{

    mmi_id cui_id = VfxAppLauncher::createCui(
                    VCUI_CONTACT_VCARD_VIEW,
                    VFX_OBJ_CLASS_INFO(VappVcardCUI),
                    parent_id,
                    NULL,
                    0);
    return cui_id;

}


void vcui_vcard_run(mmi_id cui_id)
{
    VfxAppLauncher::runCui(cui_id);
}


void vcui_vcard_close(mmi_id cui_id)
{
    VfxAppLauncher::terminate(cui_id);
}


void vcui_vcard_set_path(mmi_id cui_id, const WCHAR *path)
{
//#ifdef __MMI_MULTI_VCARD__

    VappVcardCUI *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id) ,VappVcardCUI);
    VFX_ASSERT(obj != NULL);
    
    obj->setPath(VfxWString().loadFromMem(path));
//#endif
}


void vcui_vcard_set_content(mmi_id cui_id, void *content, U32 length)
{

    VappVcardCUI *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id) ,VappVcardCUI);
    VFX_ASSERT(obj != NULL);
    
    obj->setContent(content, length);
}
//#endif

extern "C"
{
static void vcui_vcard_launch(VfxChar* data, VfxU32 dataSize, WCHAR* filePath)
{
    vcui_vcard_launch_data_struct arg;
    arg.data = data;
    arg.data_lengh = dataSize;
    arg.path = filePath;
    VfxApp *app = VfxAppLauncher::findApp(
                        VCUI_CONTACT_VCARD_VIEW,
                        VFX_OBJ_CLASS_INFO(VappVcardCUI),
                        VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);
    if (app)
    {
        VfxAppLauncher::terminate(app->getGroupId());
    }
    VfxAppLauncher::launch(
                    VCUI_CONTACT_VCARD_VIEW,
                    VFX_OBJ_CLASS_INFO(VappVcardCUI),
                    GRP_ID_ROOT,
                    &arg,
                    sizeof(vcui_vcard_launch_data_struct));
}

#ifdef __MMI_SMS_PORT_MSG__

static void vapp_sms_vcard_port_reg_callback(VfxChar* data, VfxU32 dataSize, void* userData)
{
    vcui_vcard_launch(data, dataSize, NULL);
}

void vapp_phb_vcard_sms_register(void)
{
    VfxImageSrc img;
    img.setResId(IMG_ID_FMGR_LIST_ICON_FILE_TYPE_VCARD);

    VappSmsPortReg *obj = VappSmsPortReg::getInstance();
    obj->registerPort(SRV_PHB_VCARD_PORT,
        VfxWString().loadFromRes(STR_ID_VAPP_VCARD),
        img,
        vapp_sms_vcard_port_reg_callback,
        NULL);
}
#endif

void vapp_phb_vcard_view_from_fmgr(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    vcui_vcard_launch(NULL, 0, (WCHAR*) filepath);
}
}
#endif /* __MMI_VCARD__ */

