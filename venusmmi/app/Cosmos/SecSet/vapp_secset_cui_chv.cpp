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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_secset_cui_chv.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Security setting
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "vapp_secset_cui.h"
#include "vapp_secset_str.h"
#include "vapp_secset_chv.h"
#include "GlobalResDef.h"


using namespace VappSecSetStr;
using namespace VappSecSetChv;


VFX_IMPLEMENT_CLASS("VcuiSecSetVerifyChv", VcuiSecSetVerifyChv, VcuiSecSetVerify);


void VcuiSecSetVerifyChv::run()
{
    if (!srv_sim_ctrl_pwd_is_enabled(m_sim, m_type))
    {
        MMI_TRACE(VCUI_SECSET_TRC_GROUP, TRC_VCUI_SECSET_CHV_NOT_ENABLED, m_sim, m_type);
    
        vcui_verify_result_evt_struct result_evt;
        MMI_FRM_INIT_EVENT(&result_evt, EVT_ID_VCUI_VERIFY_RESULT);
        result_evt.success = MMI_TRUE;
        result_evt.fail_cause = VCUI_VERIFY_FAIL_CAUSE_DISABLED;
        sendToCallerExt(&result_evt, VFX_TRUE);
        return;
    }

    VfxAppLauncher::runCui(getGroupId());
}


void VcuiSecSetVerifyChv::onRun(void* args, VfxU32 argSize)
{
    MMI_TRACE(VCUI_SECSET_TRC_GROUP, TRC_VCUI_SECSET_VERIFY_CHV_ON_RUN, m_sim, m_type);

    if (!srv_sim_ctrl_is_available(m_sim))
    {
        popupAndNotifyCancel(
            VFX_WSTR_RES(STR_GLOBAL_UNAVAILABLE_SIM),
            VCUI_VERIFY_CANCEL_CAUSE_UNAVAILABLE);
        return;
    }

    if (srv_sim_ctrl_pwd_is_blocked(m_sim, m_type))
    {
        if (m_type == SRV_SIM_CTRL_PWD_TYPE_CHV2 &&
            !srv_sim_ctrl_pwd_is_blocked(m_sim, SRV_SIM_CTRL_PWD_TYPE_UBCHV2))
        {
            // Allow to unblock CHV2
        }
        else
        {
            popupAndNotifyFailure(
                getChvStr(m_sim, m_type, STR_CHV_BLOCKED),
                VCUI_VERIFY_FAIL_CAUSE_OPERATION_BLOCKED);
            return;
        }
    }

    createMainScr();

    VappSecSetVerifyChvSeq *chvSeq;
    VFX_OBJ_CREATE(chvSeq, VappSecSetVerifyChvSeq, this);
    chvSeq->setSimAndType(m_sim, m_type);
    chvSeq->m_signalDone.connect(this, &VcuiSecSetVerifyChv::onVerifyDone);
    
    m_verifySeq = chvSeq;
    m_verifySeq->show(getMainScr());

    getMainScr()->show();
}


void VcuiSecSetVerifyChv::onDeinit()
{
    if (m_verifySeq.isValid())
    {
        VFX_OBJ_CLOSE(m_verifySeq);
    }

    VcuiSecSetVerify::onDeinit();
}


void VcuiSecSetVerifyChv::onVerifyDone(VappSecSetPageSeq *pageSeq, VfxS32 result)
{
    MMI_TRACE(VCUI_SECSET_TRC_GROUP, TRC_VCUI_SECSET_VERIFY_CHV_DONE, m_sim, m_type, result);

    switch (result)
    {
        case RESULT_SUCCESS:
        case RESULT_UNBLOCKED:
        {
            vcui_verify_result_evt_struct result_evt;
            MMI_FRM_INIT_EVENT(&result_evt, EVT_ID_VCUI_VERIFY_RESULT);
            result_evt.success = MMI_TRUE;
            result_evt.fail_cause = VCUI_VERIFY_FAIL_CAUSE_NONE;
            sendToCallerExt(&result_evt, VFX_FALSE);
            break;
        }
        case RESULT_WRONG_PASSWORD:
        {
            vcui_verify_result_evt_struct result_evt;
            MMI_FRM_INIT_EVENT(&result_evt, EVT_ID_VCUI_VERIFY_RESULT);
            result_evt.success = MMI_FALSE;
            result_evt.fail_cause = VCUI_VERIFY_FAIL_CAUSE_WRONG_PASSWORD;
            sendToCallerExt(&result_evt, VFX_FALSE);
            break;
        }
        case RESULT_ALREADY_BLOCKED:
        {
            vcui_verify_result_evt_struct result_evt;
            MMI_FRM_INIT_EVENT(&result_evt, EVT_ID_VCUI_VERIFY_RESULT);
            result_evt.success = MMI_FALSE;
            result_evt.fail_cause = VCUI_VERIFY_FAIL_CAUSE_OPERATION_BLOCKED;
            sendToCallerExt(&result_evt, VFX_FALSE);
            break;
        }
        case RESULT_DISABLED:
        {
            vcui_verify_result_evt_struct result_evt;
            MMI_FRM_INIT_EVENT(&result_evt, EVT_ID_VCUI_VERIFY_RESULT);
            result_evt.success = MMI_TRUE;
            result_evt.fail_cause = VCUI_VERIFY_FAIL_CAUSE_DISABLED;
            sendToCallerExt(&result_evt, VFX_FALSE);
            break;
        }
        case RESULT_TEMP_FAIL:
        {
            vcui_verify_result_evt_struct result_evt;
            MMI_FRM_INIT_EVENT(&result_evt, EVT_ID_VCUI_VERIFY_RESULT);
            result_evt.success = MMI_FALSE;
            result_evt.fail_cause = VCUI_VERIFY_FAIL_CAUSE_TEMP_FAIL;
            sendToCallerExt(&result_evt, VFX_FALSE);
            break;
        }
        case RESULT_SIM_ERROR:
        {
            vcui_verify_result_evt_struct result_evt;
            MMI_FRM_INIT_EVENT(&result_evt, EVT_ID_VCUI_VERIFY_RESULT);
            result_evt.success = MMI_FALSE;
            result_evt.fail_cause = VCUI_VERIFY_FAIL_CAUSE_SIM_ERROR;
            sendToCallerExt(&result_evt, VFX_FALSE);
            break;
        }
        case RESULT_GO_BACK:
        case RESULT_CANCEL:
        {
            vcui_verify_cancel_evt_struct cancel_evt;
            MMI_FRM_INIT_EVENT(&cancel_evt, EVT_ID_VCUI_VERIFY_CANCEL);
            cancel_evt.cause = VCUI_VERIFY_CANCEL_CAUSE_USER_CANCEL;
            sendToCallerExt(&cancel_evt, VFX_FALSE);
            break;
        }
        case RESULT_UNAVAILABLE:
        {
            vcui_verify_cancel_evt_struct cancel_evt;
            MMI_FRM_INIT_EVENT(&cancel_evt, EVT_ID_VCUI_VERIFY_CANCEL);
            cancel_evt.cause = VCUI_VERIFY_CANCEL_CAUSE_UNAVAILABLE;
            sendToCallerExt(&cancel_evt, VFX_FALSE);
            break;
        }
        case RESULT_ANOTHER_INST_RUN:
        {
            vcui_verify_cancel_evt_struct cancel_evt;
            MMI_FRM_INIT_EVENT(&cancel_evt, EVT_ID_VCUI_VERIFY_CANCEL);
            cancel_evt.cause = VCUI_VERIFY_CANCEL_CAUSE_ANOTHER_INST_RUN;
            sendToCallerExt(&cancel_evt, VFX_FALSE);
            break;
        }
        default:
            VFX_ASSERT(0);
            break;
    }
}
