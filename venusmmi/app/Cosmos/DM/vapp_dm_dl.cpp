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
 *  Vapp_dm_dl.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Device management download cosmos UI.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef SYNCML_DM_SUPPORT

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_popup.h"
#include "vcp_form.h"
#include "vapp_dm_dl.h"
#include "vcp_global_popup.h"
#include "vapp_nmgr_gprot.h"

extern "C"
{
#include "GlobalResDef.h"
#include "mmi_rp_srv_dm_def.h"
#include "mmi_rp_vapp_dm_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "DmSrvIprot.h"
}

/***************************************************************************** 
 * Static Variable
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
VappDmDlCtrler *gDmDlCtrler;

/***************************************************************************** 
 * Function
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappDmDlCtrler", VappDmDlCtrler, VfxObject);
VappDmDlCtrler::VappDmDlCtrler() :
    m_dlProgress(NULL)
{
}


void VappDmDlCtrler::dlStartEvtHdlr(MMI_BOOL is_resume, MMI_BOOL auto_resume)
{
    if (is_resume == MMI_TRUE)
    {
        if (auto_resume == MMI_TRUE)
        {
            displayAutoResume();
            srv_dm_dl_start_app_rsp(DM_UI_INTERACTION_ACTION_ACCEPT);
        }
        else
        {
            displayResumeCnf();
        }
    }
    else
    {
        // let dl agent to show cnf screen
        srv_dm_dl_start_app_rsp(DM_UI_INTERACTION_ACTION_ACCEPT);
    }
}


void VappDmDlCtrler::displayAutoResume()
{
    vapp_nmgr_global_popup_show_confirm_one_button_id(
        MMI_SCENARIO_ID_DM,
        VCP_POPUP_TYPE_INFO,
        STR_ID_DMUI_NOTIF_DOWNLOAD_RESUME,
        STR_GLOBAL_OK,
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        NULL,
        NULL);
}


void VappDmDlCtrler::displayResumeCnf()
{
    mmi_id scrnId;
    scrnId = vapp_nmgr_global_popup_show_confirm_two_button_id(
        MMI_SCENARIO_ID_DM,
        VCP_POPUP_TYPE_QUESTION,
        STR_ID_DM_DL_RESUME_ASK,
        STR_GLOBAL_OK,
        STR_GLOBAL_CANCEL,
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        VCP_POPUP_BUTTON_TYPE_CANCEL,
        VappDmDlCtrler::resumeCnfHdlr,
        NULL);
}


void VappDmDlCtrler::resumeCnfHdlr(VfxId id, void *userData)
{
    switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_USER_1: // OK
        {
            srv_dm_dl_start_app_rsp(DM_UI_INTERACTION_ACTION_ACCEPT);
            break;
        }

        case VCP_CONFIRM_POPUP_BUTTON_USER_2: // CANCEL
        case VCP_POPUP_BUTTON_NO_PRESSED:
        case VCP_POPUP_BUTTON_CANCEL_PRESSED:
        {
            srv_dm_dl_start_app_rsp(DM_UI_INTERACTION_ACTION_CANCEL);
            break;
        }

        default:
            break;
    }
}


void VappDmDlCtrler::dlProgressHdlr(U32 accSize, U32 totalSize)
{
    VfxFloat cur_dl_percent;

    if (totalSize != 0)
    {
        cur_dl_percent = (VfxFloat)accSize / totalSize;
    }
    else
    {
        cur_dl_percent = 0;
    }
    return;

    if (m_dlProgress == NULL)
    {
        m_progressGId = VfxAppLauncher::launch(
            VAPP_DM,
            VFX_OBJ_CLASS_INFO(VappDmDlProgress),
            GRP_ID_ROOT,
            &cur_dl_percent,
            sizeof(cur_dl_percent));
        m_dlProgress = (VappDmDlProgress*)VfxAppLauncher::getObject(m_progressGId);
    }
    else
    {
        (m_dlProgress)->update(cur_dl_percent);
    }
}


void VappDmDlCtrler::dlFinishHdlr(srv_dm_app_adp_dl_finish_cause_enum cause)
{
    switch (cause)
    {
        case SRV_DM_APP_ADP_DL_FINISH:
            break;

        case SRV_DM_APP_ADP_DL_CANCEL:
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_FAILURE,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
                (WCHAR*)GetString(STR_ID_DMUI_DOWNLOAD_FAILURE));
            break;
        }

        case SRV_DM_APP_ADP_DL_NO_MEM:
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_FAILURE,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
                (WCHAR*)GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY));
            break;
        }

        case SRV_DM_APP_ADP_DL_NW_UNAVAIL:
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_FAILURE,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
                (WCHAR*)GetString(STR_ID_DMUI_DOWNLOAD_PAUSE_BY_NETWORK_ANOMALY));
            break;
        }

        default:
            break;
    }

    VfxAppLauncher::terminate(m_progressGId);
    m_dlProgress = NULL;
    VfxObject *self = this;
    VFX_OBJ_CLOSE(self);
}


VFX_IMPLEMENT_CLASS("VappDmDlProgress", VappDmDlProgress, VfxApp);
void VappDmDlProgress::onRun(void *args,VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);
    VfxFloat currPercent = *((VfxFloat*)args);

    VFX_OBJ_CREATE(m_mainScrn, VappDmDlProgressMainScrn, this);
    m_mainScrn->show();
}


void VappDmDlProgress::update(VfxFloat percent)
{
    m_mainScrn->update(percent);
}


VFX_IMPLEMENT_CLASS("VappDmDlProgressMainScrn", VappDmDlProgressMainScrn, VfxMainScr);
VappDmDlProgressMainScrn::VappDmDlProgressMainScrn()
{
    setIsSmallScreen();
}

void VappDmDlProgressMainScrn::on1stReady()
{
    VfxMainScr::on1stReady();

    setBgColor(VFX_COLOR_TRANSPARENT);
    setOpaqueMode(VFX_FRAME_OPAQUE_MODE_TRANSLUCENT);

    VFX_OBJ_CREATE(m_popup, VcpIndicatorPopup,this);
    m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON);
    m_popup->setText(STR_GLOBAL_PLEASE_WAIT);
    m_popup->m_signalCanceled.connect(this, &VappDmDlProgressMainScrn::onCanceled);
    m_popup->setProgress(0.0);
    m_popup->show(VFX_TRUE);
}


void VappDmDlProgressMainScrn::update(VfxFloat percent)
{
    m_popup->setProgress(percent);
    if (percent == 1.0)
    {
        m_popup->setText(STR_GLOBAL_PLEASE_WAIT);
    }
    else
    {
        VfxWChar percentStr[10];
        VfxWChar *percentSign = (VfxWChar*)L"%";
        VfxS32 per = percent*100;
        mmi_wcs_itow(per, percentStr, 10);
        mmi_wcscat(percentStr, percentSign);
        m_popup->setText(percentStr);
    }
}


void VappDmDlProgressMainScrn::onCanceled(VfxObject* obj, VfxFloat curr_progress)
{
    srv_dm_dl_progress_app_rsp(DM_DOWNLOADING_USER_CANCEL);
    exit();
}

#endif /* SYNCML_DM_SUPPORT */
