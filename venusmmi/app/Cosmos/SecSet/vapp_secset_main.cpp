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
 *  vapp_secset_main.cpp
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
#include "vapp_secset_gprot.h"
#include "GlobalResDef.h"
extern "C"
{
#include "SimCtrlSrvGprot.h"
#include "SecSetSrvGprot.h"

#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_B__) 
#include "dcmgr.h" // DCM
#endif
}
#include "vapp_sim_setting_gprot.h"

#if !defined(__CERTMAN_SUPPORT__) && !defined(__MMI_RMGR__)
#include "mmi_rp_vapp_setting_def.h"  //STR_ID_VAPP_SETTING_SECURITY_SETTING
#endif  //#if !defined(__CERTMAN_SUPPORT__) && !defined(__MMI_RMGR__)

#if defined(__CERTMAN_SUPPORT__) || defined(__MMI_RMGR__)
VFX_IMPLEMENT_CLASS("VappSecSetEntryCell", VappSecSetEntryCell, VcpFormItemLauncherCell);
void VappSecSetEntryCell::onInit()
{
    VcpFormItemLauncherCell::onInit();

    setMainText(STR_ID_VAPP_SECSET_PHONE_AND_SIM);
    setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_signalTap.connect(this, &VappSecSetEntryCell::onTap);
}


void VappSecSetEntryCell::onTap(VcpFormItemCell *cell, VfxId id)
{
    VfxMainScr *mainScr = VFX_OBJ_DYNAMIC_CAST(findScreen(), VfxMainScr);

    if (mainScr != NULL)
    {
        VappSecSetPage *secPage;
        VFX_OBJ_CREATE(secPage, VappSecSetPage, mainScr);

        mainScr->pushPage(0, secPage);
    }
}

#else
/* Only used in global settings */
extern "C" void vapp_setting_secset_cell(VfxMainScr *mainScr)
{
   VappSecSetPage *secPage;
   VFX_OBJ_CREATE(secPage, VappSecSetPage, mainScr);
   mainScr->pushPage(0, secPage); 
}
#endif //#if defined(__CERTMAN_SUPPORT__) || defined(__MMI_RMGR__)

//VFX_IMPLEMENT_CLASS("VappSecSetPage", VappSecSetPage, VfxPage);
VappSecSetPage::VappSecSetPage() : m_actionPageSeq(NULL)
{
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_B__)
    DCM_Load(DYNAMIC_CODE_COMPRESS_SECSET, 0, 0);
#endif
}

VappSecSetPage::~VappSecSetPage()
{
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_B__)
    DCM_Unload(DYNAMIC_CODE_COMPRESS_SECSET);
#endif
}

#pragma arm section code = "DYNAMIC_CODE_SECSET_ROCODE", rodata = "DYNAMIC_CODE_SECSET_RODATA" 
void VappSecSetPage::onInit()
{
    VfxPage::onInit();

    // Title bar
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
#if defined(__CERTMAN_SUPPORT__) || defined(__MMI_RMGR__)    
    titleBar->setTitle(STR_ID_VAPP_SECSET_PHONE_AND_SIM);
#else
    titleBar->setTitle(STR_ID_VAPP_SETTING_SECURITY_SETTING);
#endif  //#if defined(__CERTMAN_SUPPORT__) || defined(__MMI_RMGR__) 
    setTopBar(titleBar);

    // Setting form
    VfxSize pageSize = getSize();

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(pageSize);
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    // Phone
    // Caption
    VFX_OBJ_CREATE(m_phoneCaption, VcpFormItemCaption, m_form);
    m_phoneCaption->setText(STR_GLOBAL_PHONE);
    m_form->addItem(m_phoneCaption);
    // Phone lock
    VFX_OBJ_CREATE(m_phoneLock, VcpFormItemSwitchCell, m_form);
    m_phoneLock->setMainText(STR_ID_VAPP_SECSET_PHONE_LOCK);
    m_phoneLock->setIsTappable(VFX_FALSE);
    m_phoneLock->m_signalSwitchChangeReq.connect(this, &VappSecSetPage::onPhoneLockSwitching);
    m_phoneLock->setSwitchStatus(toVfxBool(srv_secset_phone_lock_is_enabled()));
    m_form->addItem(m_phoneLock);
    // Change phone password
    VFX_OBJ_CREATE(m_phoneChangePwd, VcpFormItemLauncherCell, m_form);
    m_phoneChangePwd->setMainText(STR_ID_VAPP_SECSET_CHANGE_PASSWORD);
    m_phoneChangePwd->m_signalTap.connect(this, &VappSecSetPage::onPhoneChangePwdTapped);
    m_form->addItem(m_phoneChangePwd);

    if (srv_sim_ctrl_get_num_of_inserted() >= 1)
    {
        for (VfxS32 i = 0; i < MMI_SIM_TOTAL; i++)
        {
            mmi_sim_enum sim = srv_sim_ctrl_get_sim_by_index(i);
            
            // Dynamic SIM UI design. SIM options are available only if inserted
            if (srv_sim_ctrl_is_inserted(sim))
            {
                createSimSettingItems(sim, i);
                updateSimFormEnableness(sim, i);
            }
            else
            {
                SimSettingForm *simForm = &m_simSetting[i];
                simForm->caption = NULL;
                simForm->chv1Lock = NULL;
                simForm->changeChv1 = NULL;
                simForm->changeChv2 = NULL;
            }
        }
    }
    else
    {
        createSimSettingItems(MMI_SIM1, 0);
        updateSimFormEnableness(MMI_SIM1, 0);
        m_simSetting[0].caption->setText(STR_GLOBAL_SIM);

        for (VfxS32 i = 1; i < MMI_SIM_TOTAL; i++)
        {
            SimSettingForm *simForm = &m_simSetting[i];
            simForm->caption = NULL;
            simForm->chv1Lock = NULL;
            simForm->changeChv1 = NULL;
            simForm->changeChv2 = NULL;
        }
    }
}


void VappSecSetPage::createSimSettingItems(mmi_sim_enum sim, VfxS32 simIndex)
{
    SimSettingForm *simForm = &m_simSetting[simIndex];
    VfxResId simStrId = VappSecSetStr::getSimIDNameByIndex(simIndex);

    // Caption
    VFX_OBJ_CREATE(simForm->caption, VcpFormItemCaption, m_form);

    VfxWString simName = vapp_sim_settings_get_sim_name(sim);
    if (!simName.isNull())
    {
        static const VfxS32 MAX_SIM_NAME_STR_LEN = 128;
        
        VfxWChar *buffer;
        VFX_ALLOC_MEM(buffer, (MAX_SIM_NAME_STR_LEN + 1) * sizeof(VfxWChar), this);
        mmi_wsprintf_ex(
            buffer,
            (MAX_SIM_NAME_STR_LEN + 1) * sizeof(VfxWChar),
            (WCHAR*)L"%S (%w)",
            simStrId,
            simName.getBuf());

        simForm->caption->setText(buffer);
        VFX_FREE_MEM(buffer);
    }
    else
    {
        simForm->caption->setText(simStrId);
    }
    
    m_form->addItem(simForm->caption);
    // PIN lock
    VFX_OBJ_CREATE(simForm->chv1Lock, VcpFormItemSwitchCell, m_form);
    simForm->chv1Lock->setMainText(STR_ID_VAPP_SECSET_CHV1_LOCK);
    simForm->chv1Lock->setIsTappable(VFX_FALSE);
    simForm->chv1Lock->m_signalSwitchChangeReq.connect(this, &VappSecSetPage::onChvLockSwitching);
    m_form->addItem(simForm->chv1Lock);
    // Change PIN
    VFX_OBJ_CREATE(simForm->changeChv1, VcpFormItemLauncherCell, m_form);
    simForm->changeChv1->setMainText(STR_ID_VAPP_SECSET_CHANGE_CHV1_PASSWORD);
    simForm->changeChv1->m_signalTap.connect(this, &VappSecSetPage::onSimChangeChvTapped);
    m_form->addItem(simForm->changeChv1);
    // Change PIN2
    VFX_OBJ_CREATE(simForm->changeChv2, VcpFormItemLauncherCell, m_form);
    simForm->changeChv2->setMainText(STR_ID_VAPP_SECSET_CHANGE_CHV2_PASSWORD);
    simForm->changeChv2->m_signalTap.connect(this, &VappSecSetPage::onSimChangeChvTapped);
    m_form->addItem(simForm->changeChv2);
}


void VappSecSetPage::updateSimFormEnableness(mmi_sim_enum sim, VfxS32 simIndex)
{
    SimSettingForm *simForm = &m_simSetting[simIndex];
    VfxBool simIsInserted =
        srv_sim_ctrl_is_inserted(sim) ? VFX_TRUE : VFX_FALSE;

    simForm->chv1Lock->setIsDisabled(!simIsInserted);
    simForm->changeChv1->setIsDisabled(!simIsInserted);
    simForm->changeChv2->setIsDisabled(!simIsInserted);
}


void VappSecSetPage::onEnter(VfxBool isBackward)
{
    // Update newest status on page enter
    m_phoneLock->setSwitchStatus(toVfxBool(srv_secset_phone_lock_is_enabled()));

    for (VfxS32 i = 0; i < MMI_SIM_TOTAL; i++)
    {
        SimSettingForm *simForm = &m_simSetting[i];
        mmi_sim_enum sim = srv_sim_ctrl_get_sim_by_index(i);
        if (simForm->chv1Lock != NULL)
        {
            simForm->chv1Lock->setSwitchStatus(
                toVfxBool(srv_sim_ctrl_pwd_is_enabled(sim, SRV_SIM_CTRL_PWD_TYPE_CHV1)));
            
            updateSimFormEnableness(sim, i);
        }
    }

    if (m_actionPageSeq.isValid())
    {
        VFX_OBJ_CLOSE(m_actionPageSeq);
    }
}
#pragma arm section code, rodata

