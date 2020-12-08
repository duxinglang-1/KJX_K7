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
 *  vapp_secset_cui_phone.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "vapp_secset_cui.h"
#include "vapp_secset_phone.h"


using namespace VappSecSetPhone;


VFX_IMPLEMENT_CLASS("VcuiSecSetVerifyPhonePwd", VcuiSecSetVerifyPhonePwd, VcuiSecSetVerify);


void VcuiSecSetVerifyPhonePwd::onDeinit()
{
    if (m_verifySeq.isValid())
    {
        VFX_OBJ_CLOSE(m_verifySeq);
    }

    VcuiSecSetVerify::onDeinit();
}


void VcuiSecSetVerifyPhonePwd::onRun(void* args, VfxU32 argSize)
{
    createMainScr();

    VFX_OBJ_CREATE(m_verifySeq, VappSecSetPhoneVerifySeq, this);
    m_verifySeq->m_signalDone.connect(this, &VcuiSecSetVerifyPhonePwd::onVerifyDone);
    m_verifySeq->show(getMainScr());

    getMainScr()->show();
}


void VcuiSecSetVerifyPhonePwd::onVerifyDone(VappSecSetPageSeq *pageSeq, VfxS32 result)
{
    MMI_TRACE(VCUI_SECSET_TRC_GROUP, TRC_VCUI_SECSET_PHONE_VERIFY_DONE, result);

    switch (result)
    {
        case RESULT_SUCCESS:
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
        case RESULT_GO_BACK:
        case RESULT_CANCEL:
        {
            vcui_verify_cancel_evt_struct cancel_evt;
            MMI_FRM_INIT_EVENT(&cancel_evt, EVT_ID_VCUI_VERIFY_CANCEL);
            cancel_evt.cause = VCUI_VERIFY_CANCEL_CAUSE_USER_CANCEL;
            sendToCallerExt(&cancel_evt, VFX_FALSE);
            break;
        }
        default:
            VFX_ASSERT(0);
            break;
    }
}
