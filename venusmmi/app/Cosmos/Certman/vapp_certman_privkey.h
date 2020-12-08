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
*  vapp_certman_privkey.h
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifndef __VAPP_CERTMAN_PRIVKEY_H__
#define __VAPP_CERTMAN_PRIVKEY_H__
#ifdef __CERTMAN_SUPPORT__
#ifdef __COSMOS_MMI_PACKAGE__ 


#include "vfx_mc_include.h"
#include "vcp_include.h"
extern "C"{
#include "certman_api.h"
}


class VappCertmanPrivKeyCnf : public VfxBase
{

    certman_privkey_usage_confirm_ind_struct ind;

public:

    /* constructor */
    VappCertmanPrivKeyCnf(void* msg);

    void show_priv_key_dialog(void);

    /* popup callback */
    static void popup_callback(VfxId id, void *userData);

    /* send msg to wps */
    void send_rsp(VfxU32 result);

    /* nmgr callback */
    static MMI_BOOL nmgr_notify_hdlr(mmi_scenario_id scen_id, void *msg);
};

/*-------------------------------------------------------------------------------------*/

class VappCertmanPrivKeyPasswdScr : public VfxMainScr
{
    VcpInputPopup* m_inputPopup;
    certman_privkey_usage_password_ind_struct *privkey_usage_password_ind_p;
    void on1stReady(void);
    VfxU8 result;
public:
    void ipOnButtonClicked(VfxObject* sender, VcpInputPopupButtonEnum id);
    VappCertmanPrivKeyPasswdScr(void*);
    void retry(void* arg);
    ~VappCertmanPrivKeyPasswdScr(void);
};



class VappCertmanPrivKeyPasswd : public VfxApp
{
    VFX_DECLARE_CLASS(VappCertmanPrivKeyPasswd);
    VappCertmanPrivKeyPasswdScr* scr;
    certman_privkey_usage_password_ind_struct privkey_usage_password_ind;
public:
    void onRun(void* args, VfxU32 argSize);
    void retry(void* arg);
    ~VappCertmanPrivKeyPasswd(void);
};

#endif /* __COSMOS_MMI_PACKAGE__  */
#endif /* __CERTMAN_SUPPORT__ */
#endif /**/
