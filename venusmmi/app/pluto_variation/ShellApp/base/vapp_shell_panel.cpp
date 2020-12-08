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
 *  vapp_shell_panel.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  shell base panel 
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
#include "MMI_features.h"

#ifdef __MMI_VUI_SHELL_APP__
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vapp_shell_panel.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_datatype.h"
#include "vfx_system.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_object_list.h"
#include "vrt_system.h"
#include "vfx_input_event.h"
#include "vfx_signal.h"
#include "vcp_status_icon_bar.h"
#include "vadp_app_trc.h"
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
#include "vapp_shell_multi_page_cp.h"
#endif

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "MMIDataType.h"

extern void GoBackHistory(void);
extern S32 mmi_is_redrawing_bk_screens();

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * VappShellPanel
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("ShellPanel", VappShellPanel, VfxControl);

VappShellPanel::VappShellPanel() :
    m_panel_state(0),
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    m_is_ScHide(VFX_FALSE),
#endif
    m_app_bounds(0, 0, 0, 0),
    m_scr_order(0),
    m_scr_id(0),
    m_str_id(0)
{
}
    

void VappShellPanel::onInit()
{
    VFX_LOG(VFX_STATE, VAPP_SHELL_BASE_LIFE_CYCLE, 1);
    
    VfxControl::onInit();
    
    setIsOpaque(VFX_TRUE);
    m_panel_state = APP_SHELL_INIT;

    VfxSize size = getScreenSize();
    m_app_bounds = VfxRect(VfxPoint(0, 0), size);
}


void VappShellPanel::onDeinit()
{
    VFX_LOG(VFX_STATE, VAPP_SHELL_BASE_LIFE_CYCLE, 0);

    m_panel_state = APP_SHELL_DEINIT;
    VfxControl::onDeinit();
}


void VappShellPanel::onScreenEnter(VfxBool isBackward)
{
    // Do nothing.
}


void VappShellPanel::onScreenExit(VfxBool isBackward)
{
    // Do nothing.
}


void VappShellPanel::onInitView()
{
    VFX_LOG(VFX_STATE, VAPP_SHELL_BASE_LIFE_CYCLE, 2);
    
    m_isRedrawingBkScreens = mmi_is_redrawing_bk_screens() ? VFX_TRUE : VFX_FALSE;
    
    m_panel_state = APP_SHELL_INIT_VIEW;

    VfxSize size = getScreenSize();
    setSize(size);
}


void VappShellPanel::onEnterView()
{
    VFX_LOG(VFX_STATE, VAPP_SHELL_BASE_LIFE_CYCLE, 3);
    m_panel_state = APP_SHELL_ENTER_VIEW;
}


void VappShellPanel::onExitView(ShellExitCauseEnum cause)
{
    VFX_LOG(VFX_STATE, VAPP_SHELL_BASE_LIFE_CYCLE, 2);
    m_panel_state = APP_SHELL_INIT_VIEW;
    
    // empty the list to avoid memory leak
#if defined(__MMI_VUI_SHELL_MULTI_PAGE__)
    m_exp_list.clear();
#endif

}


void VappShellPanel::onDeinitView()
{
    VFX_LOG(VFX_STATE, VAPP_SHELL_BASE_LIFE_CYCLE, 1);
    m_panel_state = APP_SHELL_INIT;
}


void VappShellPanel::onUpdateView()
{
    // do nothing
}


void VappShellPanel::onSwitchBegin(VfxBool isSwitchOut)
{
    VFX_UNUSED(isSwitchOut);

    // Do nothing.
}


void VappShellPanel::onSwitchEnd()
{
    // Do nothing.
}


void VappShellPanel::regDefaultPageAct(VfxControl  *obj)
{
#if defined(__MMI_VUI_SHELL_MULTI_PAGE__)
    VFX_OBJ_ASSERT_VALID(obj);

    VFX_LOG(VFX_INFO, VAPP_SHELL_BASE_REG_DEF_PAGE_ACT, obj);
    m_exp_list.removeOne(obj);
#endif /* defined(__MMI_VUI_SHELL_MULTI_PAGE__) */
}


void VappShellPanel::deregDefaultPageAct(VfxControl  *obj)
{
#if defined(__MMI_VUI_SHELL_MULTI_PAGE__)
    VFX_OBJ_ASSERT_VALID(obj);
 
    VFX_LOG(VFX_INFO, VAPP_SHELL_BASE_DEREG_DEF_PAGE_ACT, obj);
    if (!m_exp_list.contains(obj))
    {
        m_exp_list.append(obj);
    }
#endif /* defined(__MMI_VUI_SHELL_MULTI_PAGE__) */
}


VfxBool VappShellPanel::isRegDefaultPageAct(VfxObjList &relObjList)
{

#if defined(__MMI_VUI_SHELL_MULTI_PAGE__)
    if (noDefaultPageAction(relObjList))
    {
        return VFX_FALSE;
    }

    return VFX_TRUE;
#else /* defined(__MMI_VUI_SHELL_MULTI_PAGE__) */
    return VFX_FALSE;
#endif /* !/* defined(__MMI_VUI_SHELL_MULTI_PAGE__) */
}


void VappShellPanel::cancelDefaultPageAct()
{
#if defined(__MMI_VUI_SHELL_MULTI_PAGE__)
    // cancel page action
    VFX_LOG(VFX_INFO, VAPP_SHELL_BASE_CANCEL_PAGE_ACT);
    // notify the change page has been aborted
    m_signalAbort.emit();
#endif /* defined(__MMI_VUI_SHELL_MULTI_PAGE__) */
}


VfxRect VappShellPanel::getAppBounds() const
{
    return m_app_bounds;
}


void VappShellPanel::setAppBounds(VfxRect bounds)
{
    m_app_bounds = bounds;
}


VfxSize VappShellPanel::getScreenSize(void) const
{
    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;
    
    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);
    return VfxSize(main_screen_size.width, main_screen_size.height); 
}


VfxBool VappShellPanel::noDefaultPageAction(VfxObjList &relObjList) const
{
#if defined(__MMI_VUI_SHELL_MULTI_PAGE__)
    VfxObjListEntry *i;
    
    // foreach item in list
    for (i = relObjList.getValidHead(); i != NULL; i = i->getValidNext())
    {
        VfxControl *control = (VfxControl *)i->get();

        if (m_exp_list.contains((VfxObject *)control))
        {
            VFX_LOG(VFX_INFO, VAPP_SHELL_BASE_ON_EXP_LIST, control);
            return VFX_TRUE;
        }
    }
#endif /* defined(__MMI_VUI_SHELL_MULTI_PAGE__) */

    return VFX_FALSE;
}


VfxBool VappShellPanel::onPenInput(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        return VFX_TRUE;
    }
    
    return VFX_FALSE;
}


VfxU8 VappShellPanel::getPanelState()
{
    return m_panel_state;
}


void VappShellPanel::hideShortcutBar(VfxBool isHide)
{
#if defined(__MMI_VUI_SHELL_MULTI_PAGE__)
    VFX_LOG(VFX_INFO, VAPP_SHELL_BASE_HIDE_SHORTCUT, 2, isHide);
    if (m_is_ScHide != isHide)
    {
        m_is_ScHide = isHide;
        m_signalHideShortCut.emit(isHide);
    }
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */
}


VfxBool VappShellPanel::isShortcutBarHide()
{
#if defined(__MMI_VUI_SHELL_MULTI_PAGE__)
    return m_is_ScHide;
#else
    return VFX_FALSE;
#endif
}


VfxSize VappShellPanel::getShortcutSize()
{
    VfxSize size = VfxSize(0,0);
    
#if defined(__MMI_VUI_SHELL_MULTI_PAGE__)
    VfxSize scr_size = getScreenSize();
    size = VfxSize(scr_size.width, VAPP_SHELL_SHORTCUT_HEIGHT);
#endif

    VFX_LOG(VFX_INFO, VAPP_SHELL_BASE_GET_SHORTCUT_SIZE, size.width, size.height) ;   
    return size;
}

#endif /* __MMI_VUI_SHELL_APP__ */
