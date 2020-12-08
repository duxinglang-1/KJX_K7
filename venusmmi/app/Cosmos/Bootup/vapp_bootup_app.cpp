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
 *  vapp_bootup_app.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  App of Venus bootup UI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "mmi_frm_mem_gprot.h"

#include "vfx_main_scr.h"
#include "vcp_indicator_popup.h"

#include "vapp_bootup.h"
#include "vapp_bootup_app.h"
#pragma arm section code = "DYNAMIC_CODE_BOOTUP_ROCODE", rodata = "DYNAMIC_CODE_BOOTUP_RODATA"

VFX_IMPLEMENT_CLASS("VappBootupApp", VappBootupApp, VfxApp);


VappBootupApp* VappBootupApp::s_singletonApp = NULL;

void VappBootupApp::onInit()
{
    VfxApp::onInit();

    VFX_ASSERT(s_singletonApp == NULL);
    s_singletonApp = this;

    // Set not to be shown in out-of-memory list
    mmi_frm_asm_property_struct property;
    if (mmi_frm_asm_get_property(getGroupId(), &property))
    {
        property.f_hide_in_oom = 1;
		property.f_prepare_w_reserve = 0;
        mmi_frm_asm_set_property(getGroupId(), &property);
    }

    VFX_OBJ_CREATE_EX(m_mainScr, VfxMainScrEx, this, (this));
    m_mainScr->setAutoClose(VFX_FALSE);
//    m_mainScr->setAllowDelete(VFX_FALSE);
}


void VappBootupApp::onDeinit()
{
    VFX_ASSERT(s_singletonApp != NULL);
    s_singletonApp = NULL;

    VfxApp::onDeinit();
}


VfxAppCloseAnswerEnum VappBootupApp::onProcessClose(VfxAppCloseOption option)
{
    return VFX_APP_CLOSE_ANSWER_NO; /* Not allow closing */
}


void VappBootupApp::closePage(VfxId pageId)
{
    if (m_mainScr != NULL &&
        m_mainScr->isPageIdValid(pageId))
    {
        m_mainScr->closePage(pageId);
    }
}


//void VappBootupApp::showWaiting(const VfxWString &msg)
void VappBootupApp::showWaiting(const VfxResId msg_id)
{
    if (m_waitingInd == NULL)
    {
        showMainScr();
		
        VFX_OBJ_CREATE(m_waitingInd, VcpIndicatorPopup, m_mainScr);
        m_waitingInd->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        m_waitingInd->setText(msg_id);
        m_waitingInd->setAutoDestory(VFX_FALSE);
        m_waitingInd->show(VFX_TRUE);
    }
    else
    {
    	m_waitingInd->setText(msg_id);
        m_waitingInd->bringToFront();
    }
}


void VappBootupApp::closeWaiting(VfxBool isAnim)
{
    if (m_waitingInd != NULL)
    {
        // m_waitingInd will destroy(close) automatically
        m_waitingInd->exit(isAnim);
        m_waitingInd = NULL;
    }
}

#pragma arm section code, rodata
