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
 *  vapp_secset_page_seq.h
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

#ifndef __VAPP_SECSET_PAGE_SEQ_H__
#define __VAPP_SECSET_PAGE_SEQ_H__

#include "MMI_features.h"
#include "vfx_uc_include.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_password_page_gprot.h"
#include "GlobalResDef.h"


class VappSecSetPageSeq : public VfxObject
{
    VFX_DECLARE_CLASS(VappSecSetPageSeq);

private:
    VfxMainScr *m_mainScr;
    VfxWeakPtr<VfxBasePopup> m_popup;
    VfxS32 m_popupId;
    VfxWeakPtr<VcpIndicatorPopup> m_waitingInd;
    VfxS32 m_result;

    void onPopupConfirmedForDone(VfxObject *obj, VfxId id);
    void onPopupConfirmedForBack(VfxObject *obj, VfxId id);

protected:

    inline VfxMainScr *getMainScr()
    {
        return m_mainScr;
    }
    
    virtual void onShow() = 0;
    virtual void onDeinit();
    virtual void onPopupBack(VfxS32 id);
    void notifyDone(VfxS32 result);

    void setResult(VfxS32 result)
    {
        m_result = result;
    }

    void displayPopupAndDone(
        VcpPopupTypeEnum type,
        const VfxWString &msg,
        VfxS32 result);
        
    void displayPopupAndBack(
        VcpPopupTypeEnum type,
        const VfxWString &msg,
        VfxS32 id = 0);

    void showWaiting(const VfxWString &msg = VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT));
    void closeWaiting();

    static inline MMI_BOOL to_MMI_BOOL(VfxBool val)
    {
        return (val ? MMI_TRUE : MMI_FALSE);
    }

public:
    VfxSignal2<VappSecSetPageSeq*, VfxS32> m_signalDone;

    VappSecSetPageSeq() :
        m_mainScr(NULL),
        m_popup(NULL),
        m_popupId(0),
        m_waitingInd(NULL),
        m_result(0)
    {
    }

    void show(VfxMainScr *mainScr)
    {
        VFX_ASSERT(m_mainScr == NULL && mainScr != NULL);
        m_mainScr = mainScr;
        onShow();
    }
    
    VfxS32 getResult()
    {
        return m_result;
    }


protected:

    template <VfxS32 _result>
    void notifyResultOnGoBack(VappPasswordPage *page, VappPasswordPage::BackEventEnum backEvt)
    {
        if (backEvt == VappPasswordPage::GO_BACK)
        {
            notifyDone(_result);
        }
    }
};


#endif /* __VAPP_SECSET_PAGE_SEQ_H__ */
