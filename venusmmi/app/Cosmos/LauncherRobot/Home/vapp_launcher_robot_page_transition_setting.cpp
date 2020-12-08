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
 *  vapp_launcher_robot_page_transition_setting.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"

#if defined(__MMI_VUI_HOME_SCREEN_SWITCH_EFFECT__)

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vapp_launcher_app.h"
#include "vapp_launcher_robot_def.h"
#include "vapp_launcher_robot_page_transition_setting.h"
#include "mmi_rp_vapp_launcher_robot_page_transition_setting_def.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/


struct vapp_launcher_robot_page_transition_set_mapping_entry_struct
{
    VappRobotPageTransitionTypeEnum zoomInValue;
    VappRobotPageTransitionTypeEnum zoomOutValue;
    MMI_STR_ID stringId;
};

static const vapp_launcher_robot_page_transition_set_mapping_entry_struct vapp_launcher_robot_page_transition_set_mapping[] =
{
    { VAPP_PAGE_TRANSITION_TYPE_NORMAL,            VAPP_PAGE_TRANSITION_TYPE_NORMAL,                    STR_ID_VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_SETTING_CLASSIC},
        
#if defined(VAPP_LAUNCHER_ROBOT_REDUCE_PAGE_SIZE_DURING_TRANSITION)
    { VAPP_PAGE_TRANSITION_TYPE_ROBOT,             VAPP_PAGE_TRANSITION_TYPE_CYLINDER_SLIM,             STR_ID_VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_SETTING_CYLINDER},
    { VAPP_PAGE_TRANSITION_TYPE_PENTANGLE_ZOOM_IN, VAPP_PAGE_TRANSITION_TYPE_PENTANGLE_ZOOM_OUT_SLIM,   STR_ID_VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_SETTING_WINDMILL},
    { VAPP_PAGE_TRANSITION_TYPE_TRANGLE_ZOOM_IN,   VAPP_PAGE_TRANSITION_TYPE_TRANGLE_ZOOM_OUT_SLIM,     STR_ID_VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_SETTING_PAGEFLOW}
#else
    { VAPP_PAGE_TRANSITION_TYPE_ROBOT,             VAPP_PAGE_TRANSITION_TYPE_CYLINDER,                  STR_ID_VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_SETTING_CYLINDER},
    { VAPP_PAGE_TRANSITION_TYPE_PENTANGLE_ZOOM_IN, VAPP_PAGE_TRANSITION_TYPE_PENTANGLE_ZOOM_OUT,        STR_ID_VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_SETTING_WINDMILL},
    { VAPP_PAGE_TRANSITION_TYPE_TRANGLE_ZOOM_IN,   VAPP_PAGE_TRANSITION_TYPE_TRANGLE_ZOOM_OUT,          STR_ID_VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_SETTING_PAGEFLOW}
#endif
};

static const U32 vapp_launcher_robot_page_transition_set_max_mapping_num =
    sizeof(vapp_launcher_robot_page_transition_set_mapping) / sizeof(vapp_launcher_robot_page_transition_set_mapping[0]);

#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_SETTING_DEFAULT_VALUE VAPP_PAGE_TRANSITION_TYPE_ROBOT


/***************************************************************************** 
 * VappLauncherRobotPageTransitionSettingPopup
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappLauncherRobotPageTransitionSettingPopup", VappLauncherRobotPageTransitionSettingPopup, VfxFrame);


VappRobotPageTransitionTypeEnum VappLauncherRobotPageTransitionSettingPopup::s_zoomInValue = VAPP_PAGE_TRANSITION_INVALID;
VappRobotPageTransitionTypeEnum VappLauncherRobotPageTransitionSettingPopup::s_zoomOutValue = VAPP_PAGE_TRANSITION_INVALID;

VappLauncherRobotPageTransitionSettingPopup::VappLauncherRobotPageTransitionSettingPopup():
    m_menuPop(NULL)
{
}


void VappLauncherRobotPageTransitionSettingPopup::onInit()
{
    VfxFrame::onInit();
    if(s_zoomInValue == VAPP_PAGE_TRANSITION_INVALID)
    {
        vapp_launcher_robot_page_transition_effect_get_type(s_zoomInValue, s_zoomOutValue);
    }
}


void VappLauncherRobotPageTransitionSettingPopup::createView()
{
    VFX_OBJ_CREATE(m_menuPop, VcpSelectPopup, this);
    m_menuPop->setText((STR_ID_VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_SETTING));
    m_menuPop->setType(VCP_SELECT_POPUP_BUTTON_TYPE_QUICK);

    for (VfxS32 i = 0; i < vapp_launcher_robot_page_transition_set_max_mapping_num; i++)
    {
        if(s_zoomInValue == vapp_launcher_robot_page_transition_set_mapping[i].zoomInValue)
        {
            m_menuPop->addItem(vapp_launcher_robot_page_transition_set_mapping[i].zoomInValue,
                VFX_WSTR_RES(vapp_launcher_robot_page_transition_set_mapping[i].stringId), VFX_TRUE);
        }
        else
        {
            m_menuPop->addItem(vapp_launcher_robot_page_transition_set_mapping[i].zoomInValue,
                VFX_WSTR_RES(vapp_launcher_robot_page_transition_set_mapping[i].stringId));
        }
    }

    m_menuPop->m_signalButtonClicked.connect(this, &VappLauncherRobotPageTransitionSettingPopup::onPopupMenuCallack); 
    m_menuPop->show(VFX_TRUE);
}


void VappLauncherRobotPageTransitionSettingPopup::getPageTransitionEffectType(
                VappRobotPageTransitionTypeEnum &zoomInType, 
                VappRobotPageTransitionTypeEnum &zoomOutType)
{
    if(s_zoomInValue == VAPP_PAGE_TRANSITION_INVALID)
    {
        vapp_launcher_robot_page_transition_effect_get_type(s_zoomInValue, s_zoomOutValue);
    }
    zoomInType = s_zoomInValue;
    zoomOutType = s_zoomOutValue;
}

void VappLauncherRobotPageTransitionSettingPopup::onPopupMenuCallack(VfxObject *obj, VfxId id)
{
    if( VCP_SELECT_POPUP_BUTTON_OK == id )
    {
        VcpSelectPopup *popMenu = (VcpSelectPopup *)obj;
        s_zoomInValue = (VappRobotPageTransitionTypeEnum)popMenu->getFirstSeletedId();
        VfxU8 value = s_zoomInValue;
        
        // write value to nvram
        VfxS16 error;
        WriteValue(NVRAM_SETTING_PAGE_TRANSITION_EFFECT_ZOOM_IN_TYPE, &value, DS_BYTE, &error);

        VfxS32 i=0;
        for (i = 0; i < vapp_launcher_robot_page_transition_set_max_mapping_num; i++)
        {
            if (vapp_launcher_robot_page_transition_set_mapping[i].zoomInValue == s_zoomInValue)
            {
                value = vapp_launcher_robot_page_transition_set_mapping[i].zoomOutValue;
                s_zoomOutValue = (VappRobotPageTransitionTypeEnum)value;
                WriteValue(NVRAM_SETTING_PAGE_TRANSITION_EFFECT_ZOOM_OUT_TYPE, &value, DS_BYTE, &error);
            }
        }
    }

    VappLauncherRobotPageTransitionSettingPopup *_this = this;
    VFX_OBJ_CLOSE(_this);
}


/***************************************************************************** 
 * Function
 *****************************************************************************/
extern "C" MMI_ID vapp_launcher_robot_page_transition_setting_launch(void* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxApp *app;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    app = VfxAppLauncher::findApp(
            VAPP_LAUNCHER,
            VFX_OBJ_CLASS_INFO(VappLauncherApp),
            VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG);

    if (app && app->isActive())
    {
        VappLauncherRobotPageTransitionSettingPopup *settingPopup;
        VFX_OBJ_CREATE(settingPopup, VappLauncherRobotPageTransitionSettingPopup, app->getScreen(app->getBottomScreenId()));
        settingPopup->createView();
    }

    //Not return app group ID cuz it's not app, return GRP_ID_INVALID to Launcher MM to enable menuAnim                
    return GRP_ID_INVALID;
}

void vapp_launcher_robot_page_transition_effect_get_type(VappRobotPageTransitionTypeEnum &zoomInType, VappRobotPageTransitionTypeEnum &zoomOutType)
{
    VfxU8 value;
    VfxS16 error;

    ReadValue(NVRAM_SETTING_PAGE_TRANSITION_EFFECT_ZOOM_IN_TYPE, &value, DS_BYTE, &error);
    if (value >= VAPP_PAGE_TRANSITION_TOTAL)
    {
        value = VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_SETTING_DEFAULT_VALUE;
        WriteValue(NVRAM_SETTING_PAGE_TRANSITION_EFFECT_ZOOM_IN_TYPE, &value, DS_BYTE, &error);
    }
    
    VappRobotPageTransitionTypeEnum stored_value;
    stored_value = (VappRobotPageTransitionTypeEnum)value;

    VfxS32 i=0;
    for (i = 0; i < vapp_launcher_robot_page_transition_set_max_mapping_num; i++)
    {
        if (vapp_launcher_robot_page_transition_set_mapping[i].zoomInValue == stored_value)
        {
            zoomInType = vapp_launcher_robot_page_transition_set_mapping[i].zoomInValue;
            zoomOutType = vapp_launcher_robot_page_transition_set_mapping[i].zoomOutValue;
        }
    }
}
#endif
