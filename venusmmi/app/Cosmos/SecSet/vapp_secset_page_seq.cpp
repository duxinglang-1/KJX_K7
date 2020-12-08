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
 *  vapp_secset_page_seq.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "vapp_secset.h"
#include "vapp_secset_page_seq.h"



VFX_IMPLEMENT_VIRTUAL_CLASS("VappSecSetPageSeq", VappSecSetPageSeq, VfxObject);


void VappSecSetPageSeq::onDeinit()
{
    if (m_popup.isValid())
    {
        m_popup->exit(VFX_TRUE);
    }

    if (m_waitingInd.isValid())
    {
        m_waitingInd->exit(VFX_TRUE);
    }
}


void VappSecSetPageSeq::onPopupBack(VfxS32 id)
{
    // to overwrite this function
}


void VappSecSetPageSeq::showWaiting(const VfxWString &msg)
{
    if (!m_waitingInd.isValid())
    {
        VFX_OBJ_CREATE(m_waitingInd, VcpIndicatorPopup, getMainScr());
        m_waitingInd->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        m_waitingInd->setText(msg);
        m_waitingInd->show(VFX_TRUE);
    }
    else
    {
        m_waitingInd->bringToFront();
    }
}


void VappSecSetPageSeq::closeWaiting()
{
    if (m_waitingInd.isValid())
    {
        m_waitingInd->exit(VFX_TRUE);
        m_waitingInd = NULL;
    }
}

void VappSecSetPageSeq::notifyDone(VfxS32 result)
{
    MMI_TRACE(VAPP_SECSET_TRC_GROUP, TRC_VAPP_SECSET_PAGESEQ_NOTIFY_DONE, result);
    setResult(result);
    m_signalDone.emit(this, result);
}


void VappSecSetPageSeq::displayPopupAndDone(VcpPopupTypeEnum type, const VfxWString &msg, VfxS32 result)
{
    setResult(result);

    VcpConfirmPopup *confirmPopup;
    VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, getMainScr());
    confirmPopup->setInfoType(type);
    confirmPopup->setText(msg);
    confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    confirmPopup->setAutoDestory(VFX_TRUE);
    confirmPopup->show(VFX_TRUE);
    confirmPopup->m_signalButtonClicked.connect(this, &VappSecSetPageSeq::onPopupConfirmedForDone);
}


void VappSecSetPageSeq::onPopupConfirmedForDone(VfxObject *obj, VfxId id)
{
    notifyDone(getResult());
}


void VappSecSetPageSeq::displayPopupAndBack(VcpPopupTypeEnum type, const VfxWString &msg, VfxS32 id)
{
    m_popupId = id;

    VcpConfirmPopup *confirmPopup;
    VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, getMainScr());
    confirmPopup->setInfoType(type);
    confirmPopup->setText(msg);
    confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    confirmPopup->setAutoDestory(VFX_TRUE);
    confirmPopup->show(VFX_TRUE);
    confirmPopup->m_signalButtonClicked.connect(this, &VappSecSetPageSeq::onPopupConfirmedForBack);
}


void VappSecSetPageSeq::onPopupConfirmedForBack(VfxObject *obj, VfxId id)
{
    onPopupBack(m_popupId);
}

