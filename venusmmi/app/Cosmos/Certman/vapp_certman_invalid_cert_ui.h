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
*  vapp_certman_invalid_cert_ui.h
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
 * removed!
 * removed!
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
#ifndef __VAPP_CERTMAN_INVALID_CERT_UI_H__
#define __VAPP_CERTMAN_INVALID_CERT_UI_H__
#ifdef __CERTMAN_SUPPORT__
#ifdef __COSMOS_MMI_PACKAGE__ 

#include "vapp_certman_base_ui.h"
#include "vapp_certman_gprot.h"
#include "certManAgentSrvGprot.h"


class VappCertmanInvalidCert : public VfxApp
{
    VFX_DECLARE_CLASS(VappCertmanInvalidCert);
    vapp_certman_invalid_cert_ind_struct invalid_cert_ind;
    VfxBool is_close_by_back;
public:
    void onRun(void* args, VfxU32 argSize);
    ~VappCertmanInvalidCert(void);
    static void PopUpCallBack(VfxId id, void *userData);
	
	static VfxBool launch_invalid_certman_app(mmi_scenario_id scen_id,void *userData);
    static void ShowPopUp(void* msg);
    static VfxBool ShowPopUp2(mmi_scenario_id scen_id, void* msg);
    static void vapp_certman_invalid_certificates_rsp(VfxU16 invalid_cert_action, VfxU32 trans_id, module_type src_mod);
    static void ClosePostfunc(void *arg1, void *arg2, void *arg3);
    static void PostInvokePopup2(void *arg1, void *arg2, void *arg3);
    static void agent_callbak_func(S32 job_id, srv_certman_error_enum status, U8* label, srv_certman_dcs_enum dcs_label, U32 cert_id);
    virtual VfxBool onScrBack(VfxAppScr *scr);
	static VfxBool is_popup_exist;
};

typedef enum
{
    ACCEPT_THIS_TIME_BUTTON_ID,
    ACCEPT_PERMANENTLY_BUTTON_ID,
    CERT_DETAILS_BUTTON_ID,
    CANCEL_BUTTON_ID,
    ACCEPT_FOR_FUTURE_CONTINUE_BUTTON_ID,
    ACCEPT_FOR_FUTURE_CANCEL_BUTTON_ID,
    MAX_BUTTON_ID
}vapp_certman_invalid_cert_popup_button_id_enum;

class VappCertmanCertInvalidCertScr : public VfxMainScr, public VappCertmanDataUser
{
    typedef enum
    {
        CERT_DETAILS_PAGE = 1
    }vapp_certman_invalid_cert_page_id_enum;

    vapp_certman_invalid_certificate_action_enum result;

    /* invalid cert file data */
    VappCertmanCertFileData file_data;
    void VappCertmanDataRspHndlr(void* msg);

public:
    VappCertmanCertInvalidCertScr(void *msg);
    void onQueryRotateEx(
         VfxScreenRotateParam &param
        );
};


class VappCertmanInvalidDetailsPage : public VappCertmanDetailsPage
{
public:
    virtual void onQueryRotateEx(
         VfxScreenRotateParam &param
        );
    VappCertmanInvalidDetailsPage(VfxU32 cert_id, VfxU32 job_id);
};

#endif /* __COSMOS_MMI_PACKAGE__  */
#endif /* __CERTMAN_SUPPORT__ */
#endif /* __VAPP_CERTMAN_INVALID_CERT_UI_H__ */
