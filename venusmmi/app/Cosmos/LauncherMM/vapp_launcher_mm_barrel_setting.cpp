/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *  vapp_launcher_MM_barrel_setting.cpp
 *
 * Project:
 * --------
 *  Launcher 
 *
 * Description:
 * ------------
 *  Launcher MM barrel setting
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 

#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
#include "vapp_launcher_mm_barrel_setting.h"
#include "vapp_launcher_mm.h"
#include "vcp_page_menu_transition.h"
#include "mmi_rp_vapp_launcher_mm_barrel_setting_def.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/ 

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
extern "C"
{
    MMI_ID vapp_launcher_mm_barrel_setting_launch(void* param, U32 param_size)
    {
        VappLauncherMm *launcherMM = vappLauncherMmGetInstance();

        VappLauncherMmBarrelSetting *barrelSetting;
        VFX_OBJ_CREATE(barrelSetting, VappLauncherMmBarrelSetting, launcherMM);
		VFX_ASSERT(barrelSetting);
            
        //Not return app group ID cuz it's not app, return GRP_ID_INVALID to Launcher MM to enable menuAnim
        return GRP_ID_INVALID; 
    }
}


VFX_IMPLEMENT_CLASS("VappLauncherMmBarrelSetting", VappLauncherMmBarrelSetting, VfxObject);

VappLauncherMmBarrelSetting::VappLauncherMmBarrelSetting():
    m_menuPop(NULL)
{
    //do nothing
}

VfxS32 VappLauncherMmBarrelSetting::s_barrelSettingLastSelected = VCP_PAGE_MENU_TRANSITION_TYPE_NORMAL;

void VappLauncherMmBarrelSetting::onInit()
{
    VfxObject::onInit();

    // get mainmenu's pointer
    VappLauncherMm *launcherMM = vappLauncherMmGetInstance();
#ifdef VAPP_LAUNCHER_MM_MOTION_DOUBLE_TAP_TO_CHANGE_SWITCH_EFFECT
    launcherMM->stopListenMotionSensor();
#endif

    //Read last selected item from NVram
    readFromNVRAM();

    VfxU32 transitionNum = vcpPageMenuGetTransitionNum();
    VcpPageMenuTransitionInfo *transitionInfoList;
    VFX_ALLOC_MEM(transitionInfoList, sizeof(VcpPageMenuTransitionInfo) * transitionNum, this);
    vcpPageMenuGetTransitionInfoList(transitionInfoList, transitionNum);

    VFX_OBJ_CREATE(m_menuPop, VcpSelectPopup, launcherMM);
    m_menuPop->setText((STR_ID_VAPP_LAUNCHER_MM_BARREL_SETTING_NAME));
    m_menuPop->setType(VCP_SELECT_POPUP_BUTTON_TYPE_QUICK);

    ///Read last selected item from NVram
    readFromNVRAM();

    for (VfxU32 i = 0; i < transitionNum; ++i)
    {
       m_menuPop->addItem(transitionInfoList[i].typeId,
                VFX_WSTR_RES(transitionInfoList[i].stringId),
                ((transitionInfoList[i].typeId == m_selectedID))
                ? VFX_TRUE : VFX_FALSE);
    }

    VFX_TRACE(("===== getFirstSelectedId %d======\n", m_menuPop->getFirstSeletedId()));
    m_menuPop->m_signalButtonClicked.connect(this, &VappLauncherMmBarrelSetting::onBarrelSettingMenuCallack); 
    m_menuPop->show(VFX_TRUE);

    VFX_FREE_MEM(transitionInfoList);
}


void VappLauncherMmBarrelSetting::onDeinit()
{
#ifdef VAPP_LAUNCHER_MM_MOTION_DOUBLE_TAP_TO_CHANGE_SWITCH_EFFECT
    // get mainmenu's pointer
    VappLauncherMm *launcherMM = vappLauncherMmGetInstance();
    launcherMM->startListenMotionSensor();
#endif
        
    VFX_OBJ_CLOSE(m_menuPop);    

    VfxObject::onDeinit();
}


void VappLauncherMmBarrelSetting::onBarrelSettingMenuCallack(VfxObject* sender, VfxId id)
{
    VappLauncherMm *launcherMM = vappLauncherMmGetInstance();

    VFX_TRACE(("===== onPopupButtonClicked %d======\n", id));
    if(VCP_SELECT_POPUP_BUTTON_OK == id)
    {
        VFX_TRACE(("===== VCP_SELECT_POPUP_BUTTON_OK======\n"));
        launcherMM->setTransitionEffect((VcpPageMenuTransitionType)m_menuPop->getFirstSeletedId());
    }

    // write to NVRAM
    writeToNVRAM(m_menuPop->getFirstSeletedId());

    //Since it's not lauched by normal app way,
    //therefore, it(VappLauncherCosmosMmBarrelSetting) needs to closeed by itself when popup closed 
    VfxObject *barrelSettingObject = this; // this means VappLauncherCosmosMmBarrelSetting
    VFX_OBJ_CLOSE(barrelSettingObject);
}

void VappLauncherMmBarrelSetting::writeToNVRAM(VfxU32 writeValue)
{
    m_selectedID= writeValue;

    // write to NVRAM
    VfxS16 sError = 0;
    WriteValue(NVRAM_VAPP_LAUNCHER_MM_BARREL_SETTING, (void*)&writeValue, DS_BYTE, & sError);

    //MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_LAUNCHER_MM_BARREL_SETTING_WRITE_TO_NVRAM, ret);
}


void VappLauncherMmBarrelSetting::readFromNVRAM()
{
    // read MMI_CACHE
    VfxS16 sError = 0;

    if(m_menuPop != NULL)
    {
        VfxU8 selected = 0;
        ReadValue(NVRAM_VAPP_LAUNCHER_MM_BARREL_SETTING, (void*)&selected, DS_BYTE, & sError);

		setSelectedValue(selected);
    }

    //MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_LAUNCHER_MM_BARREL_SETTING_READ_FROM_NVRAM, ret);
}


void VappLauncherMmBarrelSetting::setSelectedValue(VfxU32 selectedID)
{
    m_selectedID = selectedID;
}
#endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__

