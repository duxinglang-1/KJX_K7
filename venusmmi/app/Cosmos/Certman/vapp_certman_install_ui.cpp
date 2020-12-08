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
*  vapp_certman_install_ui.cpp
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
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
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifdef __CERTMAN_SUPPORT__
#ifdef __COSMOS_MMI_PACKAGE__ 

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vapp_certman_install_ui.h"
#include "vapp_certman_cfg.h"
#include "vapp_certman_gprot.h"
#include "vapp_certman_pluto_adaptor.h"
#include "vapp_certman_util.h"
#include "mmi_rp_vapp_certman_def.h"
#include "GlobalResDef.h"
#include "vcp_status_icon_bar.h"
#include "vapp_nmgr_gprot.h"
#ifdef __MMI_VUI_COSMOS_CP__
#include "mmi_rp_app_cosmos_global_def.h"
#endif

/*------Install app launch function----------*/

void vapp_certman_install_cert_file(VfxWChar *filename)
{
    VfxAppLauncher::launch(
        VAPP_CERTMAN,                            // todo: use own app base
        VFX_OBJ_CLASS_INFO(VappCertmanInstall),
        GRP_ID_ROOT,
        filename,
        VAPP_CERTMAN_MAX_FILE_PATH_LENGTH);

}


VFX_IMPLEMENT_CLASS("VappCertmanInstall", VappCertmanInstall, VfxApp) ;

/*------Install app on run function----------*/
void VappCertmanInstall::onRun(void* filename, VfxU32 filename_max_size)
{
    VfxApp::onRun(filename, filename_max_size);

    VappCertmanCertInstallScr *scr;

    /* Create screen object */
    VFX_OBJ_CREATE_EX(scr, VappCertmanCertInstallScr, this, ((VfxWChar *)filename));
    scr->show();
}


/*---------------------screen----------------------------------*/
VappCertmanCertInstallScr::VappCertmanCertInstallScr(VfxWChar *filename): file_data(filename, this)
{
    /* filename is used only till we get a job id from certman task */
    this->filename = filename;
    cert_installed = 0;
    m_inputPopup = NULL;

    setIsSmallScreen();
}

void VappCertmanCertInstallScr::on1stReady(void)
{

    VcpStatusIconBar *statusBar;

    VfxMainScr::on1stReady();

    VFX_OBJ_CREATE(statusBar, VcpStatusIconBar, this);
    statusBar->setAutoAnimate(VFX_TRUE);
    statusBar->setPos(0, 0);
    statusBar->bringToFront();

    setBgColor(VFX_COLOR_TRANSPARENT);
    setAutoClose(VFX_FALSE);
    VfxKeypad::registerHandler(VFX_KEY_CODE_SPECIAL_ALL, this);
    VfxU32 err = file_data.get_data_pre_func();

    if (err==CERTMAN_ERR_NONE)
    {
        file_data.get_data_post_func();
    }
    else if (err == CERTMAN_ERR_NEED_PASSWORD)
    {
        VFX_OBJ_CREATE(m_inputPopup, VcpInputPopup, this);
        m_inputPopup->setTitle(VfxWString(STR_ID_VAPP_CERTMAN_CERT_PASSWORD));
        m_inputPopup->setHintText(VFX_WSTR(""));
        m_inputPopup->setIME(IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD);

        VcpTextEditor *Inputbox = m_inputPopup->getInputbox();
        Inputbox->setMaxLength(CERTMAN_PASSWORD_LENGTH);

        m_inputPopup->m_signalButtonClicked.connect(this, &VappCertmanCertInstallScr::ipOnButtonClicked);
        m_inputPopup->setAutoDestory(VFX_FALSE);
        m_inputPopup->show(VFX_TRUE);
        button_pressed = VFX_FALSE;
    }
    else
    {
        /* wrong file type. Show error popup and exit APP */
        VcpConfirmPopup *m_confirm;
        VFX_OBJ_CREATE(m_confirm, VcpConfirmPopup, this);
        m_confirm->setInfoType(VCP_POPUP_TYPE_FAILURE);
        m_confirm->setText(VfxWString(STR_ID_VAPP_CERTMAN_CORRUPTED_FILE));
        m_confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        m_confirm->show(VFX_TRUE);
        m_confirm->m_signalButtonClicked.connect(this, &VappCertmanCertInstallScr::InvalidFilePopupStateChanged);

    }
}

void VappCertmanCertInstallScr::ipOnButtonClicked(VfxObject* sender, VcpInputPopupButtonEnum id)
{
    VfxWString inputText;
    switch (id)
    {
    case VCP_INPUT_POPUP_BTN_OK:
        {
            if(button_pressed == VFX_TRUE)
                return;

            button_pressed = VFX_TRUE;
            inputText = m_inputPopup->getText();
            const VfxWChar* passwd= inputText.getBuf();
            VfxU32 error = file_data.get_data_set_passwd(passwd);

            if (error != CERTMAN_ERR_NONE )
            {
                m_inputPopup->setErrorText(VfxWString(STR_ID_VAPP_CERTMAN_INCORRECT_PASSWORD));
            }
            else
            {
                file_data.get_data_post_func();
            }
        }
        break;
    case VCP_INPUT_POPUP_BTN_CANCEL:
        {
            /* close app */
            VfxAppLauncher::terminate(getApp()->getGroupId());
        }
        break;
    default:
        break;
    }
}

void VappCertmanInstallDetailsPage::HandleDetailsPageError(certman_error_enum err)
{
        VcpConfirmPopup *m_confirm;
        VFX_OBJ_CREATE(m_confirm, VcpConfirmPopup, this);
        m_confirm->setInfoType(VCP_POPUP_TYPE_FAILURE);
        m_confirm->setText(VfxWString(STR_ID_VAPP_CERTMAN_CORRUPTED_FILE));
        m_confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        m_confirm->show(VFX_TRUE);
        m_confirm->m_signalButtonClicked.connect(getMainScr(), &VappCertmanCertInstallScr::InvalidFilePopupStateChanged);
}


void VappCertmanCertInstallScr::InvalidFilePopupStateChanged(VfxObject* sender, VfxId id)
{

    VfxAppLauncher::terminate(getApp()->getGroupId());

}

void VappCertmanCertInstallScr::ErrorPopupContinueInstall(VfxObject* sender, VfxId id)
{
    popPage();
    VappCertmanInstallOneByOne();
}

VfxBool VappCertmanCertInstallScr::onKeyInput(VfxKeyEvent &event)
{
    if ((event.keyCode == VFX_KEY_CODE_RSK) && (event.type == VFX_KEY_EVENT_TYPE_DOWN) &&
        (getPageCount()<=1))
    {
        VappCertmanInstallOneByOne();
        return VFX_TRUE;
    }
    return VfxMainScr::onKeyInput(event);
}


void VappCertmanCertInstallScr::VappCertmanDataRspHndlr(void* msg)
{
    /* post function callback */
    VfxU32 error = *(VfxU32*)(msg);
    /* check correct password */
    if (error == CERTMAN_ERR_NONE)
    {
        if ((file_data.num_priv_key>0) && (m_inputPopup))
        {
            m_inputPopup->exit(VFX_TRUE);
        }
        VappCertmanInstallOneByOne();
    }
    else if (error == CERTMAN_ERR_INCORRECT_PASSWORD)
    {
        m_inputPopup->setErrorText(VfxWString(STR_ID_VAPP_CERTMAN_INCORRECT_PASSWORD));
        button_pressed = VFX_FALSE;
    }
    else
    {
        VcpConfirmPopup *confirm_p;
        VFX_OBJ_CREATE(confirm_p, VcpConfirmPopup, this);
        confirm_p->setInfoType(VCP_POPUP_TYPE_FAILURE);
        confirm_p->setText(VfxWString(STR_ID_VAPP_CERTMAN_CORRUPTED_FILE));
        confirm_p->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        confirm_p->show(VFX_TRUE);
        confirm_p->m_signalButtonClicked.connect(this, &VappCertmanCertInstallScr::InvalidFilePopupStateChanged);
    }
}

void VappCertmanCertInstallScr::VappCertmanInstallOneByOne(void)
{
    if (file_data.cert_total == cert_installed)
    {
        VfxAppLauncher::terminate(getApp()->getGroupId());
    }
    else
    {
    	  setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
        VappCertmanInstallDetailsPage *page;
        VFX_OBJ_CREATE_EX(page, VappCertmanInstallDetailsPage , this, (file_data.job_id, file_data.cert_ref_ids[cert_installed]));
        cert_installed++;
        pushPage(SHOW_CERT_DETAILS_PAGE_ID, page);
    }
}


/*------------------------install page---------------------------*/

VappCertmanInstallDetailsPage::VappCertmanInstallDetailsPage(VfxU32 param1, VfxU32 param2) : VappCertmanDetailsPage(param1, param2)
{

}

void VappCertmanInstallDetailsPage::setuptoolbar(void)
{
    VFX_OBJ_CREATE(toolbar, VcpToolBar, this);
    setBottomBar(toolbar);
    toolbar->addItem(INSTALL_PAGE_INSTALL_BUTTON_ID, VfxWString(VCP_STR_TOOL_BAR_INSTALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_INSTALL);
    toolbar->m_signalButtonTap.connect(this, &VappCertmanInstallDetailsPage::onTBClick);
}

VfxBool VappCertmanInstallDetailsPage::onKeyInput(VfxKeyEvent &event)
{
    return VFX_FALSE;
}

void VappCertmanInstallDetailsPage::onTBClick(VfxObject* sender, VfxId id)
{
    switch(id)
    {
    case INSTALL_PAGE_INSTALL_BUTTON_ID:
        {
            if (cert_details.AlreadyExists())
            {
                VcpConfirmPopup *m_confirm;
                VFX_OBJ_CREATE(m_confirm, VcpConfirmPopup, this);
                m_confirm->setInfoType(VCP_POPUP_TYPE_FAILURE);
                m_confirm->setText(VfxWString(STR_ID_VAPP_CERTMAN_CERT_EXISTS));
                m_confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
                m_confirm->show(VFX_TRUE);

                m_confirm->m_signalButtonClicked.connect(getMainScr(), &VappCertmanCertInstallScr::ErrorPopupContinueInstall);
                return;
            }

            VfxU32 total = certman_get_cert_count(CERTMAN_CERTGRP_NONE, CERTMAN_KP_NONE);
            if (!(total < CERTMAN_NUM_CERT_IN_DATABASE))
            {
                VcpConfirmPopup *m_confirm;
                VFX_OBJ_CREATE(m_confirm, VcpConfirmPopup, this);
                m_confirm->setInfoType(VCP_POPUP_TYPE_FAILURE);
                m_confirm->setText(VfxWString(STR_ID_VAPP_CERTMAN_MAX_LIMIT));
                m_confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
                m_confirm->show(VFX_TRUE);

                m_confirm->m_signalButtonClicked.connect(getMainScr(), &VappCertmanCertInstallScr::ErrorPopupContinueInstall);
                return;
            }

            VcpConfirmPopup* m_confirmPopup;
            VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
            m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
            m_confirmPopup->setText(VfxWString(STR_ID_VAPP_CERTMAN_WARN_INSTALL));
            m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
            m_confirmPopup->setAutoDestory(VFX_TRUE);

            m_confirmPopup->setCustomButton(VfxWString(STR_GLOBAL_INSTALL),VfxWString(STR_GLOBAL_CANCEL),
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                VCP_POPUP_BUTTON_TYPE_CANCEL);

            m_confirmPopup->m_signalButtonClicked.connect(this, &VappCertmanInstallDetailsPage::onInstallCnfPopupClick);

            m_confirmPopup->show(VFX_TRUE);
        }
        break;
    default:
        break;
    }
}

void VappCertmanInstallDetailsPage::onInstallCnfPopupClick(VfxObject* sender, VfxId id)
{
    switch(id)
    {
    case VCP_CONFIRM_POPUP_BUTTON_USER_1:
        {
            VappCertmanInputDetailsPage *page;
            VFX_OBJ_CREATE_EX(page, VappCertmanInputDetailsPage, getMainScr(), (&cert_details));
            getMainScr()->pushPage(VappCertmanCertInstallScr::INPUT_CERT_DETAILS_PAGE_ID, page);
            /* install */
        }
        break;
    case VCP_CONFIRM_POPUP_BUTTON_USER_2:
    default: 
        {
            /* cancel */
        }
        break;
    }
}


VappCertmanInputDetailsPage::VappCertmanInputDetailsPage (VappCertmanCertDetailsData* cert_details) : inputdata(cert_details->getkeypurpose(), cert_details->getkeypurpose())
{
    this->cert_details = cert_details;
}


void VappCertmanInputDetailsPage::onInit(void)
{
    VfxPage::onInit();

    /*----------------------------------bars----------------------------------------*/

    VcpTitleBar* titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(VfxWString(STR_ID_VAPP_CERTMAN_CERTIFICATE_INFO));
    this->setTopBar(titleBar);


    VcpToolBar *bbar;
    VFX_OBJ_CREATE(bbar, VcpToolBar, this);
    setBottomBar(bbar);
    bbar->addItem(INSTALL_BUTTON_ID, VfxWString(STR_GLOBAL_INSTALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_INSTALL);
    bbar->addItem(DISCARD_BUTTON_ID, VfxWString(STR_GLOBAL_DISCARD), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    bbar->m_signalButtonTap.connect(this, &VappCertmanInputDetailsPage::onButtonClicked);

    /*---------------------------------function bar--------------------------------*/
    VFX_OBJ_CREATE(m_function_bar, VcpFunctionBar, this);
    m_function_bar->addItem(INSTALL_BUTTON_ID, VfxWString(STR_GLOBAL_INSTALL));
    m_function_bar->setItemSpecial(INSTALL_BUTTON_ID);
    m_function_bar->m_signalButtonTap.connect(this, &VappCertmanInputDetailsPage::onButtonClicked);


    VFX_OBJ_CREATE(inputform, VcpForm, this);
    VfxRect page_rect = getRect();
    VfxRect rect(0, 0, page_rect.size.width, page_rect.size.height);
    inputform->setRect(rect);
    inputform->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

    /* label input */
    VcpFormItemTextInput *labelInput;
    VFX_OBJ_CREATE(labelInput , VcpFormItemTextInput, inputform);

    /* suggest label */
    certman_dcs_enum dcs_type;
    VfxU8* label = VappCertmanUtilities::vapp_certman_suggest_label(cert_details->getsubject(), dcs_type);

    /* limit label to CERTMAN_LABEL_SIZE */
    VfxU8 temp[CERTMAN_LABEL_SIZE];
    VappCertmanUtilities::vapp_certman_cert_strncpy(temp, label, dcs_type, CERTMAN_LABEL_SIZE);
    temp[CERTMAN_LABEL_SIZE-1] = '\0';
    temp[CERTMAN_LABEL_SIZE-2] = '\0';

    VfxWString label_string;
	label_string.loadFromMem((VfxWChar*)temp);
   

    labelInput->setText(label_string);
    labelInput->setLabelText(VfxWString(STR_ID_VAPP_CERTMAN_CERTIFICATE_LABEL));

    /* set label max size */
    VcpTextEditor* label_text_box = labelInput->getTextBox();
    label_text_box->setMaxLength(CERTMAN_LABEL_LENGTH/2);
    active_editor_id = LABEL;

    /* set function bar */
    label_text_box->setFunctionBar((VfxFrame*)m_function_bar);
	label_text_box->m_signalActivated.connect(this, &VappCertmanInputDetailsPage::onButtonClicked_LABEL);
	

    /*key usage button */
    VcpFormItemBigArrowButton *keyusage;
    VFX_OBJ_CREATE(keyusage , VcpFormItemBigArrowButton, inputform);
    keyusage->setButtonText(VfxWString(STR_ID_VAPP_CERTMAN_CERTIFICATE_KEY_USAGE));
    (keyusage->getButton())->m_signalClicked.connect(this, &VappCertmanInputDetailsPage::onButtonClicked);
    (keyusage->getButton())->setId(KEY_USAGE);

    inputform->addItem(labelInput, LABEL);
    inputform->addItem(keyusage, KEY_USAGE);
    /*---------------segment button---------------------------*/

    if (cert_details->IsPersonalCert())
    {

        /* key protection caption */
        VcpFormItemCaption *key_prot_caption;
        VFX_OBJ_CREATE(key_prot_caption , VcpFormItemCaption, inputform);
        key_prot_caption->setText(VfxWString(STR_ID_VAPP_CERTMAN_CERTIFICATE_PRIVATE_KEY_PROTECTION)); 

        /* key protection button */
        VFX_OBJ_CREATE(key_prot_but, VcpFormItemCustomFrame, inputform);
        VFX_OBJ_CREATE(segment_btn, VcpSegmentButton, inputform);
        segment_btn->setType(VCP_SEGMENT_BUTTON_TYPE_RADIO);
        segment_btn->setStyle(VCP_SEGMENT_BUTTON_STYLE_TEXT_ONLY);
        segment_btn->addButton (PW_BUTTON_ID, IMG_GLOBAL_L1, VfxWString(STR_GLOBAL_PASSWORD));//VfxWString(STR_ID_CERTMAN_PASS_ABRV)
        segment_btn->addButton (NONE_BUTTON_ID, IMG_GLOBAL_L1, VfxWString(STR_GLOBAL_NONE));
        segment_btn->addButton (CONFIRM_BUTTON_ID, IMG_GLOBAL_L1, VfxWString(STR_ID_VAPP_CERTMAN_CONFIRM));
        segment_btn->setButtonIsHighlighted (NONE_BUTTON_ID, VFX_TRUE);
        
        VfxSize size((LCD_WIDTH - ((VCPFRM_INDENT_L1+VCPFRM_INDENT_L2)*2)) , VCPFRM_STD_UI_CNTRL_HEIGHT);

        VfxPoint pos(VCPFRM_INDENT_L2, 0);
        segment_btn->setSize(size);
        segment_btn->setPos(pos);

        key_prot_but->attachCustomFrame(segment_btn);
        inputform->addItem(key_prot_caption, PRIV_KEY_PROT_CAPTION);
        inputform->addItem(key_prot_but, PRIV_KEY_PROT);
        segment_btn->m_signalButtonClicked.connect(this, &VappCertmanInputDetailsPage::onButtonClicked);
    }
    pass_dialog_enable = VFX_FALSE;
}

void VappCertmanInputDetailsPage::onButtonClicked_LABEL(VcpTextEditor* obj, VfxBool id)
{
if(id)
    {
            active_editor_id = LABEL;
            VcpFormItemBase* input_pass_editor = inputform->getItem(LABEL);
            ((VcpFormItemTextInput*)input_pass_editor)->setFocused(VFX_TRUE);
			if(pass_dialog_enable==VFX_TRUE){
			m_function_bar->setDisableItem(PREV_BUTTON_ID,VFX_TRUE);
			m_function_bar->setDisableItem(NEXT_BUTTON_ID,VFX_FALSE);
			function_bar->setDisableItem(PREV_BUTTON_ID,VFX_TRUE);
			function_bar->setDisableItem(NEXT_BUTTON_ID,VFX_FALSE);
			}
      
    }
}

void VappCertmanInputDetailsPage::onButtonClicked_INPUT_PASSWD(VcpTextEditor* obj, VfxBool id)
{
    if(id)
      {
            active_editor_id = INPUT_PASSWD;
            VcpFormItemBase* input_pass_editor = inputform->getItem(INPUT_PASSWD);
            ((VcpFormItemTextInput*)input_pass_editor)->setFocused(VFX_TRUE);
			m_function_bar->setDisableItem(PREV_BUTTON_ID,VFX_FALSE);
			m_function_bar->setDisableItem(NEXT_BUTTON_ID,VFX_FALSE);
			function_bar->setDisableItem(PREV_BUTTON_ID,VFX_FALSE);
			function_bar->setDisableItem(NEXT_BUTTON_ID,VFX_FALSE);
      }

}

void VappCertmanInputDetailsPage::onButtonClicked_INPUT_CNF_PASSWD(VcpTextEditor* obj, VfxBool id)
{
    if(id)
      {
         active_editor_id = INPUT_CNF_PASSWD;
         VcpFormItemBase* input_pass_editor = inputform->getItem(INPUT_CNF_PASSWD);
         ((VcpFormItemTextInput*)input_pass_editor)->setFocused(VFX_TRUE);
	     m_function_bar->setDisableItem(PREV_BUTTON_ID,VFX_FALSE);
		 m_function_bar->setDisableItem(NEXT_BUTTON_ID,VFX_TRUE);
		  function_bar->setDisableItem(PREV_BUTTON_ID,VFX_FALSE);
		 function_bar->setDisableItem(NEXT_BUTTON_ID,VFX_TRUE);
      }

}

void VappCertmanInputDetailsPage::onButtonClicked(VfxObject* obj, VfxId id)
{
    switch(id)
    {
    case LABEL_CAPTION:
        break;
    case LABEL:
        {
        }
        break;
    case KEY_USAGE:
        {
            VappCertmanKeyUsagePage* page;
            VFX_OBJ_CREATE_EX(page, VappCertmanInstallKeyUsagePage, this, (&inputdata));
            getMainScr()->pushPage(VappCertmanCertInstallScr::KEY_USAGE_PAGE_ID, page);
        }
        break;
    case PRIV_KEY_PROT_CAPTION:
        break;
    case PRIV_KEY_PROT:
        {
        }
        break;
    case INPUT_PASSWD:
        break;
    case INPUT_CNF_PASSWD:
        break;
    case NONE_BUTTON_ID:
    case CONFIRM_BUTTON_ID:
        {
            if (pass_dialog_enable == VFX_TRUE)
            {
                inputform->removeItem(INPUT_CNF_PASSWD);
                inputform->removeItem(INPUT_PASSWD);
                m_function_bar->removeItem(PREV_BUTTON_ID);
                m_function_bar->removeItem(NEXT_BUTTON_ID);

                pass_dialog_enable = VFX_FALSE;
                if (id == CONFIRM_BUTTON_ID)
                {
                    inputdata.set_key_protection_method(CERTMAN_PROTECT_USAGE_CONFIRM);
                }
                else
                {
                    inputdata.set_key_protection_method(CERTMAN_PROTECT_NONE);
                }
            }
        }
        break;
    case PW_BUTTON_ID:
        {
            if (pass_dialog_enable == VFX_FALSE)
            {
                /* password */
                VFX_OBJ_CREATE(PasswordInput , VcpFormItemTextInput, inputform);
                PasswordInput->setText(VFX_WSTR(""));

                /* confirm password */
                VFX_OBJ_CREATE(ConfirmPasswordInput, VcpFormItemTextInput, inputform);
                ConfirmPasswordInput->setText(VFX_WSTR(""));

                VcpTextEditor* pwdeditor = PasswordInput->getTextBox();
                pwdeditor->setMaxLength(CERTMAN_PASSWORD_LENGTH);
                pwdeditor->setIME(IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD);
                pwdeditor->setHint(STR_ID_VAPP_CERTMAN_INPUT_PASSWORD);

                VcpTextEditor* cnfpwdeditor = ConfirmPasswordInput->getTextBox();
                cnfpwdeditor->setMaxLength(CERTMAN_PASSWORD_LENGTH);
                cnfpwdeditor->setIME(IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD);
                cnfpwdeditor->setHint(STR_ID_VAPP_CERTMAN_INPUT_PASS_AGAIN);

                inputform->addItem(PasswordInput, INPUT_PASSWD);
                inputform->addItem(ConfirmPasswordInput, INPUT_CNF_PASSWD);
                inputdata.set_key_protection_method(CERTMAN_PROTECT_USAGE_PASSWORD);

            
                VFX_OBJ_CREATE(function_bar, VcpFunctionBar, this);
                function_bar->addItem(INSTALL_BUTTON_ID, VfxWString(STR_GLOBAL_INSTALL));
                function_bar->setItemSpecial(INSTALL_BUTTON_ID);
                function_bar->m_signalButtonTap.connect(this, &VappCertmanInputDetailsPage::onButtonClicked);
                function_bar->addItem(PREV_BUTTON_ID, VfxWString(STR_ID_VAPP_CERTMAN_PREV));
                function_bar->addItem(NEXT_BUTTON_ID, VfxWString(STR_ID_VAPP_CERTMAN_NEXT));
                pwdeditor->setFunctionBar((VfxFrame*)function_bar);
                cnfpwdeditor->setFunctionBar((VfxFrame*)function_bar);
 
				
				pwdeditor->m_signalActivated.connect(this, &VappCertmanInputDetailsPage::onButtonClicked_INPUT_PASSWD);
				cnfpwdeditor->m_signalActivated.connect(this, &VappCertmanInputDetailsPage::onButtonClicked_INPUT_CNF_PASSWD);

                m_function_bar->addItem(PREV_BUTTON_ID, VfxWString(STR_ID_VAPP_CERTMAN_PREV));
                m_function_bar->addItem(NEXT_BUTTON_ID, VfxWString(STR_ID_VAPP_CERTMAN_NEXT));

                pass_dialog_enable = VFX_TRUE;

            }
        }
        break;
    case INSTALL_BUTTON_ID:
        {
            VcpFormItemTextInput *labelInput = (VcpFormItemTextInput*)inputform->getItem(LABEL);
            const VfxWChar* label = (labelInput->getText()).getBuf();
             VfxId focusItemId = LABEL;
            certman_error_enum error = certman_import_check_label_exists((const kal_uint8*)label, CERTMAN_DCS_UCS2);
            labelInput->setWarningText((VFX_WSTR_RES(0)));
            if (error == CERTMAN_ERR_LABEL_EXISTS)
            {
                /* show error popup */
               
                
                labelInput->setWarningText((VFX_WSTR_RES(STR_ID_VAPP_CERTMAN_LABEL_EXISTS)));
                inputform->scrollItemToView(focusItemId, VCPFORM_SCROLL_TOP);       
                break;
            }
            else if (error == CERTMAN_ERR_INVALID_LABEL)
            {
                

	        labelInput->setWarningText((VFX_WSTR_RES(STR_ID_VAPP_CERTMAN_INVALID_INPUT)));
                inputform->scrollItemToView(focusItemId, VCPFORM_SCROLL_TOP);
                break;
            }

            inputdata.set_label((VfxU8*)label);

            /* todo: match pass and cnfpass*/
            if (pass_dialog_enable == VFX_TRUE)
            {
                VcpFormItemTextInput *PasswordInput = (VcpFormItemTextInput*)inputform->getItem(INPUT_PASSWD);
                const VfxWChar* passwd = (PasswordInput->getText()).getBuf();

                VcpFormItemTextInput *CnfPasswordInput = (VcpFormItemTextInput*)inputform->getItem(INPUT_CNF_PASSWD);
                const VfxWChar* cnfpasswd = (CnfPasswordInput->getText()).getBuf();
                PasswordInput->setWarningText((VFX_WSTR_RES(0)));
                if (mmi_ucs2cmp((const CHAR*)passwd, (const CHAR*)cnfpasswd))
                {
                    /* show incorrect password popup */
                    

                    PasswordInput->setWarningText((VFX_WSTR_RES(STR_ID_VAPP_CERTMAN_MISMATCHED)));
                    focusItemId = INPUT_CNF_PASSWD;
                    inputform->scrollItemToView(focusItemId, VCPFORM_SCROLL_BOTTOM);
                    break;
                }
                else if (mmi_ucs2strlen((const CHAR*)passwd) < 1)
                {
                  

		    PasswordInput->setWarningText((VFX_WSTR_RES(STR_ID_VAPP_CERTMAN_INVALID_INPUT)));
                    focusItemId = INPUT_PASSWD;
                     inputform->scrollItemToView(focusItemId, VCPFORM_SCROLL_TOP);
                    break;
                }

                inputdata.set_key_protection_password((VfxU8*)passwd);
            }

            VappCertmanImportCertProgressPopup *install_activity;
            VFX_OBJ_CREATE_EX(install_activity, VappCertmanImportCertProgressPopup, getMainScr(), (cert_details, &inputdata));

            install_activity->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS);
            install_activity->setText(VfxWString(STR_GLOBAL_INSTALLING));

            install_activity->setAutoDestory(VFX_FALSE);
            install_activity->show(VFX_TRUE);
        }
        break;
    case DISCARD_BUTTON_ID:
        getMainScr()->closePage(VappCertmanCertInstallScr::SHOW_CERT_DETAILS_PAGE_ID);
        getMainScr()->closePage(VappCertmanCertInstallScr::INPUT_CERT_DETAILS_PAGE_ID);
        ((VappCertmanCertInstallScr*)getMainScr())->VappCertmanInstallOneByOne();
        break;
    case PREV_BUTTON_ID:
        {
           VFX_ASSERT(pass_dialog_enable);
           activate_prev_editor();
        }
        break;
    case NEXT_BUTTON_ID:
        {
           VFX_ASSERT(pass_dialog_enable);
           activate_next_editor();
        }
        break;
    }
}


void VappCertmanInputDetailsPage::activate_next_editor(void)
{
    switch(active_editor_id)
    {
        case LABEL:
        {
            active_editor_id = INPUT_PASSWD;
            VcpFormItemBase* input_pass_editor = inputform->getItem(INPUT_PASSWD);
            ((VcpFormItemTextInput*)input_pass_editor)->setFocused(VFX_TRUE);
            break;
        }
        case INPUT_PASSWD:
        {
            active_editor_id = INPUT_CNF_PASSWD;
            VcpFormItemBase* cnf_pass_editor = inputform->getItem(INPUT_CNF_PASSWD);
            ((VcpFormItemTextInput*)cnf_pass_editor)->setFocused(VFX_TRUE);
            break;
        }
        case INPUT_CNF_PASSWD:
        {
            active_editor_id = LABEL;
            VcpFormItemBase* label_editor = inputform->getItem(LABEL);
            ((VcpFormItemTextInput*)label_editor)->setFocused(VFX_TRUE);
            break;
        }
    }
}

void VappCertmanInputDetailsPage::activate_prev_editor(void)
{
    switch(active_editor_id)
    {
        case LABEL:
        {
            active_editor_id = INPUT_CNF_PASSWD;
            VcpFormItemBase* cnf_pass_editor = inputform->getItem(INPUT_CNF_PASSWD);
            ((VcpFormItemTextInput*)cnf_pass_editor)->setFocused(VFX_TRUE);
            break;
        }
        case INPUT_PASSWD:
        {
            active_editor_id = LABEL;
            VcpFormItemBase* label_editor = inputform->getItem(LABEL);
            ((VcpFormItemTextInput*)label_editor)->setFocused(VFX_TRUE);
            break;
        }
        case INPUT_CNF_PASSWD:
        {
            active_editor_id = INPUT_PASSWD;
            VcpFormItemBase* input_pass_editor = inputform->getItem(INPUT_PASSWD);
            ((VcpFormItemTextInput*)input_pass_editor)->setFocused(VFX_TRUE);
            break;
        }
    }
}

VappCertmanInstallKeyUsagePage::VappCertmanInstallKeyUsagePage(VappCertmanCertDetailsInputData* InstallInputData) : VappCertmanKeyUsagePage(InstallInputData->getallkeyusage(), InstallInputData->keyusage)
{
    this->InstallInputData = InstallInputData;
}

void VappCertmanInstallKeyUsagePage::onToolBarClick(VfxObject* sender, VfxId id)
{
    switch(id)
    {
    case KEY_OK_BUTTON_ID:
        {

            VfxU32 count_key_usages = 0;
            VfxU32 temp = 0x01;
            InstallInputData->keyusage = 0;

            for (VfxU32 count = 0; count < VAPP_CERTMAN_TOTAL_KEY_USAGE; count++)
            {
                if ((list_data.key_purpose_all & temp) == temp)
                {
                    if (list_data.list_of_state[count_key_usages] == VFX_TRUE)
                    {
                        InstallInputData->keyusage |= temp; 
                    }
                    count_key_usages++;
                }
                temp <<= 1;
            }
        }
        getMainScr()->popPage();
        break;
    case KEY_CANCEL_BUTTON_ID:
        {
            getMainScr()->popPage();
        }
        break;
    }
}


VappCertmanImportCertProgressPopup::VappCertmanImportCertProgressPopup(VappCertmanCertDetailsData *cert_details, VappCertmanCertDetailsInputData *inputdata) 
: import_req_data(this), key_usage_update_data(this)
{
    this->cert_details = cert_details;
    this->inputdata = inputdata;

    import_req_data.new_import_begin(cert_details->getcertid(), cert_details->getjobid());
    import_req_data.new_import_set_label((VfxU8*)inputdata->getlabel(), CERTMAN_DCS_UCS2);
    if(inputdata->getkeyprotection() == CERTMAN_PROTECT_USAGE_PASSWORD)/* must initialize this */
    {
        import_req_data.new_import_set_priv_key_protection(CERTMAN_PROTECT_USAGE_PASSWORD, (VfxU8*)inputdata->getpasswd());
    }
    import_req_data.new_import_req();
    state = IMPORTING_STATE;
}


void VappCertmanImportCertProgressPopup::VappCertmanDataRspHndlr(void* msg)
{
    switch(state)
    {
    case IMPORTING_STATE:
        {
            certman_import_cnf_struct *import_cnf_p = (certman_import_cnf_struct*)msg;

            if (import_cnf_p->status == CERTMAN_ERR_NONE)
            {
                key_usage_update_data.UpdateKeyUsage((import_cnf_p->cert_id), inputdata->keyusage);
                state = UPDATING_KEY_USAGE_STATE;
            }
            else if(import_cnf_p->status== CERTMAN_ERR_MEMFULL)
            {
                /* todo: error popup */
				 hide(VFX_FALSE);
				 vapp_nmgr_global_popup_show_confirm_one_button_id(
								MMI_SCENARIO_ID_DEFAULT,
								VCP_POPUP_TYPE_WARNING, 
								STR_GLOBAL_NOT_ENOUGH_MEMORY, 
								STR_GLOBAL_OK, 
								VCP_POPUP_BUTTON_TYPE_NORMAL, 
								NULL, 
								NULL);
				
            }
        }
        break;
    case UPDATING_KEY_USAGE_STATE:
        {
            hide(VFX_FALSE);
            ((VfxMainScr*)getParent())->closePage(VappCertmanCertInstallScr::SHOW_CERT_DETAILS_PAGE_ID);
            ((VfxMainScr*)getParent())->closePage(VappCertmanCertInstallScr::INPUT_CERT_DETAILS_PAGE_ID);
            ((VappCertmanCertInstallScr*)getParent())->VappCertmanInstallOneByOne();
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_GENERAL, MMI_EVENT_INFO_BALLOON, 
                MMI_NMGR_BALLOON_TYPE_SUCCESS, (WCHAR*)vfxSysResGetStr(STR_ID_VAPP_CERTMAN_CERT_INSTALLED));
        }
        break;
    }
}

#endif /* __COSMOS_MMI_PACKAGE__  */
#endif /* __CERTMAN_SUPPORT__ */
