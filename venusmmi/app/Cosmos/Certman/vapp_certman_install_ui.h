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
*  vapp_certman_install_ui.h
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifndef __VAPP_CERTMAN_INSTALL_UI_H__
#define __VAPP_CERTMAN_INSTALL_UI_H__
#ifdef __CERTMAN_SUPPORT__
#ifdef __COSMOS_MMI_PACKAGE__ 

#include "vapp_certman_data.h"
#include "vcp_include.h"
#include "vapp_certman_base_ui.h"


/* Application class for certificate installation */
class VappCertmanInstall : public VfxApp
{
    VFX_DECLARE_CLASS(VappCertmanInstall);
public:
    void onRun(void* args, VfxU32 argSize);
};

/* Screen for certificate installation */
class VappCertmanCertInstallScr : public VfxMainScr, public VappCertmanDataUser
{
    VfxWChar *filename;
    VappCertmanCertFileData file_data;
    VcpInputPopup *m_inputPopup;
    VfxU32 cert_installed;  /* why is this here ?*/
    VfxU32 button_pressed;

public:

    typedef enum
    {
        SHOW_CERT_DETAILS_PAGE_ID = 1,
        INPUT_CERT_DETAILS_PAGE_ID,
        KEY_USAGE_PAGE_ID,
        MAX_PAGE_ID
    };


    VappCertmanCertInstallScr(VfxWChar *param);

    void VappCertmanInstallOneByOne(void);
    void ipOnButtonClicked(VfxObject* sender, VcpInputPopupButtonEnum id);
    void VappCertmanDataRspHndlr(void* msg);
    void on1stReady(void);

    VfxBool onKeyInput(VfxKeyEvent &event);
    void InvalidFilePopupStateChanged(VfxObject* sender, VfxId id);//generalize
    void ErrorPopupContinueInstall(VfxObject* sender, VfxId id);
};

/* Show certificate details to user before installtion */
/* Different types of pages would overide VappCertmanDetailsPage */

class VappCertmanInstallDetailsPage : public VappCertmanDetailsPage
{
    typedef enum
    {
        INSTALL_PAGE_INSTALL_BUTTON_ID
    };
    void cert_data_response_parse_func(void* msg);
    void onTBClick(VfxObject* sender, VfxId id);

    void onInstallCnfPopupClick(VfxObject* sender, VfxId id);
    void setuptoolbar(void);
    void HandleDetailsPageError(certman_error_enum err);
public:
    VappCertmanInstallDetailsPage(VfxU32 job_id, VfxU32 cert_id);
    VfxBool onKeyInput(VfxKeyEvent &event);
};


/* Input details to store a certificate */

/* VCP form component not ready */
class VappCertmanInputDetailsPage : public VfxPage
{

    typedef enum
    {
        LABEL_CAPTION = 1,
        LABEL,
        KEY_USAGE,
        PRIV_KEY_PROT_CAPTION,
        PRIV_KEY_PROT,
        INPUT_PASSWD,
        INPUT_CNF_PASSWD,
        TOTAL_ITEMS
    }InputDetailsPageItemIdEnum;

    typedef enum
    {
        INSTALL_BUTTON_ID = TOTAL_ITEMS,
        DISCARD_BUTTON_ID,
        PREV_BUTTON_ID,
        NEXT_BUTTON_ID,
        MAX_INPUT_DETAILS_PAGE_BUTTON_ID
    }InputDetailsPageButtonIdEnum;

    typedef enum
    {
        PW_BUTTON_ID = MAX_INPUT_DETAILS_PAGE_BUTTON_ID,
        NONE_BUTTON_ID,
        CONFIRM_BUTTON_ID,
        MAX_KEY_PROT_BUTTON_ID
    }VappCertmanKeyProtButtonEnum;

    VappCertmanCertDetailsData *cert_details;
    VappCertmanCertDetailsInputData inputdata;   /* change name to item. This does not qualify as data object in our design */
    VcpForm* inputform;
    VcpFormItemTextInput *ConfirmPasswordInput;
    VcpFormItemTextInput *PasswordInput;
    VcpFormItemCustomFrame *key_prot_but;
    VcpFunctionBar* m_function_bar;
    VfxBool pass_dialog_enable;
	VcpFunctionBar* function_bar;
	

    InputDetailsPageItemIdEnum active_editor_id;

    void activate_prev_editor(void);
    void activate_next_editor(void);

public:
    void onInit(void);
    VcpSegmentButton *segment_btn;
    VappCertmanInputDetailsPage (VappCertmanCertDetailsData* cert_details);
    void onButtonClicked(VfxObject* obj, VfxId id);
     void onButtonClicked_LABEL(VcpTextEditor* obj, VfxBool id);
	 void onButtonClicked_INPUT_PASSWD(VcpTextEditor* obj, VfxBool id);
	  void onButtonClicked_INPUT_CNF_PASSWD(VcpTextEditor* obj, VfxBool id);
};


class VappCertmanInstallKeyUsagePage: public VappCertmanKeyUsagePage
{
    VappCertmanCertDetailsInputData* InstallInputData;
public:
    VappCertmanInstallKeyUsagePage(VappCertmanCertDetailsInputData* InstallInputData);
    void onToolBarClick(VfxObject* sender, VfxId id);
};


/* 30/09/2010  */
class VappCertmanImportCertProgressPopup : public VcpIndicatorPopup, public VappCertmanDataUser
{
    typedef enum
    {
        IMPORTING_STATE,
        UPDATING_KEY_USAGE_STATE,
        MAX_STATE
    }VappCertmanImportProgressStateEnum;

    VappCertmanCertDetailsData *cert_details;
    VappCertmanCertDetailsInputData *inputdata;
    VappCertmanImportReqData import_req_data;
    VappCertmanKeyUsageUpdateReqData key_usage_update_data;
    VappCertmanImportProgressStateEnum state;
public:
    void VappCertmanDataRspHndlr(void* msg);
    VappCertmanImportCertProgressPopup(VappCertmanCertDetailsData *cert_details, VappCertmanCertDetailsInputData *inputdata);
};


#endif /* __COSMOS_MMI_PACKAGE__  */
#endif /* __CERTMAN_SUPPORT__ */
#endif /* __VAPP_CERTMAN_INSTALL_UI_H__ */
