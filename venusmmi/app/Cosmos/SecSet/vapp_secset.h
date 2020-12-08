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
 *  vapp_secset.h
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

#ifndef __VAPP_SECSET_H__
#define __VAPP_SECSET_H__


#include "MMI_features.h"
#include "vfx_uc_include.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "mmi_rp_vapp_secset_def.h"
#include "vapp_password_page_gprot.h"
#include "vapp_secset_page_seq.h"
#include "vapp_secset_chv.h"
#include "vapp_secset_phone.h"
#include "vapp_secset_str.h"
#include "GlobalResDef.h"
extern "C"
{
#include "MMIDataType.h"
#include "SimCtrlSrvGprot.h"
#include "mmi_trc.h"
}


#define VAPP_SECSET_TRC_GROUP MMI_COMMON_TRC_G7_SETTING


class VappSecSetPage : public VfxPage
{
 //   VFX_DECLARE_CLASS(VappSecSetPage);

private:
    VcpForm *m_form;

    VfxWeakPtr<VappSecSetPageSeq> m_actionPageSeq;
    VcpFormItemCaption *m_phoneCaption;
    VcpFormItemSwitchCell *m_phoneLock;
    VcpFormItemLauncherCell *m_phoneChangePwd;
    
    void updateSimFormEnableness(mmi_sim_enum sim, VfxS32 simIndex);
    void onPhoneLockSwitching(VcpFormItemSwitchCell *cell, VfxId id, VfxBool newVal);
    void onPhoneLockSwitchDone(VappSecSetPageSeq *actionPageSeq, VfxS32 result);
    void onPhoneChangePwdTapped(VcpFormItemCell *item, VfxId id);
    void onPhoneChangePwdDone(VappSecSetPageSeq *actionPageSeq, VfxS32 result);

    struct SimSettingForm
    {
        VcpFormItemCaption *caption;
        VcpFormItemSwitchCell *chv1Lock;
        VcpFormItemLauncherCell *changeChv1;
        VcpFormItemLauncherCell *changeChv2;
    };

    SimSettingForm m_simSetting[MMI_SIM_TOTAL];

    void createSimSettingItems(mmi_sim_enum sim, VfxS32 simIndex);
    VfxBool getSimAndChvType(
        VcpFormItemCell *cell,
        VfxId id,
        mmi_sim_enum *outSim,
        srv_sim_ctrl_pwd_type_enum *outChvType);
    void onChvLockSwitching(VcpFormItemSwitchCell *cell, VfxId id, VfxBool newVal);
    void onChvLockSwitchDone(VappSecSetPageSeq *actionPageSeq, VfxS32 result);
    void onSimChangeChvTapped(VcpFormItemCell *item, VfxId id);
    void onSimChangeChvDone(VappSecSetPageSeq *pageSeq, VfxS32 result);
    
protected:
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);

    static inline VfxBool toVfxBool(MMI_BOOL val)
    {
        return (val ? VFX_TRUE : VFX_FALSE);
    }

public:
    VappSecSetPage();
   	virtual ~VappSecSetPage();
};


#define VAPP_SECSET_HANDLE_TO_OBJECT(out_ptr, exp_type, handle) \
    do { \
        out_ptr = static_cast<exp_type*>( \
            VfxObject::handleToObject(reinterpret_cast<VfxObjHandle>(handle))); \
        if (out_ptr != NULL) \
        { \
            if (!out_ptr->isKindOf(VFX_OBJ_CLASS_INFO(exp_type))) \
            { \
                out_ptr = NULL; \
            } \
        } \
    } while (0)


#endif

