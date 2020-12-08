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
 *  vapp_shell_scr.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  shell control application
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
 * removed!
 * removed!
 * removed!
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

#define SHELL_CP_DEFINE_IN_SCR

#ifdef __MMI_VUI_SHELL_APP__

#include "vfx_cpp_base.h"
#include "vfx_screen.h"
#include "vfx_basic_type.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vapp_hs_cp.h"
#include "vrt_datatype.h"
#include "vapp_shell_multi_page_cp.h"
#include "vfx_datatype.h"
#include "vfx_signal.h"
#include "vfx_system.h"
#include "vfx_input_event.h"
#include "vfx_auto_animate.h"
#include "vfx_timer.h"
#include "vrt_system.h"
#include "vfx_primitive_frame.h"
#include "vfx_frame.h"
#include "vfx_transform.h"
#include "vfx_context.h"
#include "vfx_top_level.h"
#include "vrt_canvas.h"
#include "ui_core\mvc\vfx_mmi.h"
#include "vcp_status_icon_bar.h"
#include "vadp_app_trc.h"

#include "vapp_shell_scr.h"
#include "ShellAppGprot.h"
#include "vadp_p2v_shell.h"

#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
#include "vcp_page_panel.h"
#include "vcp_frame_effect.h"
#include "vcp_content_clone.h"
#include "mmi_rp_app_shellapp_base_def.h"
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */

#include "vapp_shell_page_order.h"
#include "vapp_shell_panel.h"
#include "vapp_shell_panel_cfg.h"
#include "vadp_v2p_hs.h"
#include "vadp_v2p_op01_hs.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "math.h"

#include "kal_general_types.h"    
#include "kal_public_api.h"
#include "kal_trace.h"

#include "MMIDataType.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "gdi_include.h"
#include "GpioSrvGprot.h"
#include "IdleGprot.h"
#include "ScrLockerGprot.h"

extern void GoBackHistory(void);
extern S32 mmi_is_redrawing_bk_screens();

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * VappShellScr
 *****************************************************************************/

VappShellScr::VappShellScr() :
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    m_pageScPanel(NULL),
    m_ind_num(0),
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__    
    m_is_loop(VFX_FALSE),
    m_do_change_page(VFX_TRUE),
    m_is_critira_matched(VFX_FALSE),
    m_shell_menu(NULL),
    m_switch_bg(NULL),
    m_page_panel(NULL),
    m_timer(NULL),
    m_next_scr_idx(0),
    m_vrt_cache_mem(NULL),
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */
    m_page_bounds(0, 0, 0, 0),
    m_cur_scr_idx(0),
    m_cur_view_state(APP_SHELL_FULL_VIEW),
    m_icon_bar(NULL),
    m_is_in_history(VFX_FALSE)
{
}


void VappShellScr::onInit()
{
     VfxScreen::onInit();
     
    // set shell application bounds
    VfxSize size = getScreenSize();
    VfxRect rect;
    rect.origin = VfxPoint(0, 0);
    rect.size = size;
    setRect(rect);
    
    // Common outlook: Create status bar
    VFX_OBJ_CREATE(m_icon_bar, VappHsStatusIcon, this);

    // create status bar
    m_icon_bar->setPos(0, 0);
 #ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    m_icon_bar->setBgColor(VFX_COLOR_BLACK);
    m_icon_bar->setOpacity(1.0f);
 #endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */
    
    VfxPoint app_pos = VfxPoint(0, 0);
    VfxSize app_size = VfxSize(size.width, size.height);
    app_pos = VfxPoint(0, m_icon_bar->getBounds().getHeight());
    app_size = VfxSize(app_size.width, 
                       app_size.height - 
			   #ifdef __MMI_VUI_SHELL_MULTI_PAGE__
                       VappShellShortCutPanel::PAGE_SHORTCUT_HEIGHT -
                       VappShellShortCutPanel::PAGE_IND_HEIGHT -
               #endif
					   m_icon_bar->getBounds().getHeight());    
    m_page_bounds = VfxRect(app_pos, app_size);
    
    // display a specific shell screen component
    const vapp_shell_panel_tbl_struct *tbl = g_vapp_shell_panel_create_tbl;

    VfxU8 page_pos = 0;
    VfxS32 i = 0;
   
    VdatShellPageOrder* order = VFX_OBJ_GET_INSTANCE(VdatShellPageOrder);
    order->m_signalChange.connect(this, &VappShellScr::onOrderChange);
    
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    VfxBool order_get = VFX_FALSE;
    VfxBool page_state = VFX_TRUE;
    VfxU16 page_num = VAPP_SHELL_PANEL_TOTAL;

    for (i = 0; i < APP_PANEL_NUM; i++)
    {
    #ifdef __MMI_VUI_SHELL_SETTINGS__
        // get order from setting service
        order_get = order->getOrderById(tbl[i].panel_id, page_pos, page_state);
        
        VFX_LOG(VFX_INFO2, VAPP_SHELL_BASE_GET_ORDER, 
            i, tbl[i].panel_id, page_pos, page_state);
        
        VFX_DEV_ASSERT(order_get != VFX_FALSE);
    #else /* __MMI_VUI_SHELL_SETTINGS__ */
        // no setting, we get order from table directly
        page_pos = i;
        page_state = VFX_TRUE;
        order_get = VFX_TRUE;
    #endif /* !__MMI_VUI_SHELL_SETTINGS__ */

        if (order_get == VFX_TRUE)
        {
            if (page_state == VFX_FALSE)
            {
                // panel is closed
                m_shell_cp[page_pos] = NULL;
            }
            else
            {
#endif /* !__MMI_VUI_SHELL_MULTI_PAGE__ */
                m_shell_cp[page_pos] = tbl[i].func_ptr(this);
                m_shell_cp[page_pos]->setPanelId((VfxU8)tbl[i].panel_id);
                m_shell_cp[page_pos]->setPanelOrder(page_pos);
                m_shell_cp[page_pos]->setPanelStrId((VfxResId)tbl[i].str_id);
                m_shell_cp[page_pos]->setAppBounds(m_page_bounds);
                // register abort change page event
            #if defined(__MMI_VUI_SHELL_MULTI_PAGE__)
                m_shell_cp[page_pos]->m_signalAbort.connect(this, 
                                      &VappShellScr::onAbortPageAct);
            #endif
                
            #ifdef __MMI_VUI_SHELL_MULTI_PAGE__
                m_shell_cp[page_pos]->m_signalHideShortCut.connect(this, 
                                      &VappShellScr::onHideShortCut);
                m_ind_num++;
            #endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */

                m_shell_cp[page_pos]->setHidden(VFX_TRUE);
                m_shell_cp[page_pos]->setPos(0,0);

                if (m_shell_cp[page_pos]->getPanelId() == VAPP_SHELL_PANEL_HOME)
                {
                    m_cur_scr_idx = page_pos;
                }
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
            }
        }
    }
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */

    m_icon_bar->bringToFront();
    
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    // create page shortcut
    VFX_OBJ_CREATE_EX(m_pageScPanel, VappShellShortCutPanel, this, (m_ind_num));
    
    m_pageScPanel->m_signalEnterSwitch.connect(this, &VappShellScr::onEnterSwitch);
    m_pageScPanel->m_signalEnterMenu.connect(this, &VappShellScr::onEnterMenu);
    m_pageScPanel->m_signalEnterDial.connect(this, &VappShellScr::onEnterDial);
    m_pageScPanel->m_signalEnterLock.connect(this, &VappShellScr::onEnterLock);
    m_pageScPanel->setPos(0, size.height - 
    VappShellShortCutPanel::PAGE_SHORTCUT_HEIGHT - VappShellShortCutPanel::PAGE_IND_HEIGHT);
 
    VfxU8 ind_idx = m_cur_scr_idx;
    for (i = 0; i < m_cur_scr_idx; i++)
    {
        if (m_shell_cp[i] == NULL &&
            ind_idx > 0)
            ind_idx--;
    }
    m_pageScPanel->displayInd(ind_idx);
    m_pageScPanel->bringToFront();
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */
}


void VappShellScr::onDeinit()
{ 
    VfxScreen::onDeinit();
}


void VappShellScr::onEnter(VfxBool isBackward)
{
    VfxScreen::onEnter(isBackward);

    for (VfxS32 i = 0; i < APP_PANEL_NUM; i++)
    {
        if (m_shell_cp[i])
        {
            m_shell_cp[i]->onScreenEnter(isBackward);
        }
    }
}


void VappShellScr::onExit(VfxBool isBackward)
{
    VfxScreen::onExit(isBackward);

    for (VfxS32 i = 0; i < APP_PANEL_NUM; i++)
    {
        if (m_shell_cp[i])
        {
            m_shell_cp[i]->onScreenExit(isBackward);
        }
    }

    clearPopupStack();
}

VfxBool VappShellScr::onKeyInput(VfxKeyEvent &event)
{
#if defined(__MMI_VUI_SHELL_MULTI_PAGE__)   
    if (event.keyCode != VFX_KEY_CODE_END &&
        event.keyCode != VFX_KEY_CODE_POWER &&
        event.keyCode != VFX_KEY_CODE_SEND)
    {
	/* in switch mode or swipe mode, don't process end key and send key in shell screen */
        if(m_cur_view_state == APP_SHELL_SWITCH_VIEW)
        {
            VFX_LOG(VFX_INFO, VAPP_SHELL_BASE_SCR_KEY_EVENT, 0);
            return VFX_TRUE;
        }
    }
    
    if ((event.keyCode == VFX_KEY_CODE_ARROW_RIGHT ||
         event.keyCode == VFX_KEY_CODE_ARROW_LEFT) &&
         (event.type == VFX_KEY_EVENT_TYPE_DOWN || 
          event.type == VFX_KEY_EVENT_TYPE_REPEAT))
    {
        VFX_LOG(VFX_INFO, VAPP_SHELL_BASE_SCR_KEY_EVENT, 1);
        
        if (!m_shell_cp[m_cur_scr_idx]->isShortcutBarHide())
        {
            VFX_LOG(VFX_INFO, VAPP_SHELL_BASE_SCR_KEY_EVENT, 2);
            VfxS8 scr_idx = m_cur_scr_idx;
            
            // shortcut bar is not hide, we can change page
            if (event.keyCode == VFX_KEY_CODE_ARROW_RIGHT)
            {
                // switch to next page
              swipePanel(VFX_TRUE);
            }
            else
            {
                // switch to previous page
                swipePanel(VFX_FALSE);
            }
        }
        
        return VFX_TRUE;
    }
    else if (event.keyCode == VFX_KEY_CODE_END && event.type == VFX_KEY_EVENT_TYPE_UP)
    {
        VFX_LOG(VFX_INFO, VAPP_SHELL_BASE_SCR_KEY_EVENT, 3);
        
        // switch page back to home no matter we are in what state
        // any status should be aborted even if it is in animation
        clearPopupStack();
            
        if (m_timer)
        {
            /* stop the timer if necessary */
            m_timer->stop();
            m_timer->m_signalTick.disconnect(this, &VappShellScr::onDelayPageFinish);
            m_timer->m_signalTick.disconnect(this, &VappShellScr::onPageSwitch);
            m_timer->m_signalTick.disconnect(this, &VappShellScr::onPageSelectFinish);
        }

        VfxU8 home_scr_idx = 0;
        VfxU8 i;
        for (i = 0; i < APP_PANEL_NUM; i++)
        {
            if (m_shell_cp[i] != NULL)
            {
                addChildFrame(m_shell_cp[i]);

                // let all penal's short in unhide stage
                if (m_shell_cp[i]->isShortcutBarHide())
                {
                    VfxAutoAnimate::begin();
                    VfxAutoAnimate::setDisable(VFX_TRUE);
                    m_shell_cp[i]->hideShortcutBar(VFX_FALSE);
                    VfxAutoAnimate::commit();
                }
                
                if (m_shell_cp[i]->getPanelId() == VAPP_SHELL_PANEL_HOME)
                {
                    home_scr_idx = i;
                    continue;
                }

                m_shell_cp[i]->setHidden(VFX_TRUE);
                m_shell_cp[i]->setFocused(VFX_FALSE);
                m_shell_cp[i]->setIsUnhittable(VFX_TRUE);
                
                if (m_shell_cp[i]->getPanelState() == 
                    VappShellPanel::APP_SHELL_ENTER_VIEW)
                {
                    m_shell_cp[i]->onExitView(VappShellPanel::APP_SHELL_END_KEY_EXIT);    
                }
                if (m_shell_cp[i]->getPanelState() == 
                    VappShellPanel::APP_SHELL_INIT_VIEW &&
                    m_shell_cp[i]->isPanelAlwaysExist() == VFX_FALSE
                    )
                {
                    m_shell_cp[i]->onDeinitView();
                }
            }
        }

        // process home related logic
        // we supposed the home is page one
        VFX_DEV_ASSERT(m_shell_cp[home_scr_idx] != NULL);

        m_shell_cp[home_scr_idx]->setHidden(VFX_FALSE);
        m_shell_cp[home_scr_idx]->setFocused(VFX_TRUE);
        m_shell_cp[home_scr_idx]->setIsUnhittable(VFX_FALSE);


        /* check if we need to change screen 0's state */
        if (m_shell_cp[home_scr_idx]->getPanelState() == VappShellPanel::APP_SHELL_INIT)
        {
            m_shell_cp[home_scr_idx]->onInitView();
        }
        if (m_shell_cp[home_scr_idx]->getPanelState() == VappShellPanel::APP_SHELL_INIT_VIEW)
        {
            m_shell_cp[home_scr_idx]->onEnterView();
        }
        
        // close wheel menu
        VFX_OBJ_CLOSE(m_switch_bg);
        VFX_OBJ_CLOSE(m_shell_menu);
        VFX_OBJ_CLOSE(m_page_panel);
        m_cur_scr_idx = home_scr_idx;
        m_next_scr_idx = home_scr_idx;    

        if (m_icon_bar)
        {
            m_icon_bar->bringToFront();
        }
        // set page index
    #ifdef __MMI_VUI_SHELL_MULTI_PAGE__
        if (m_pageScPanel)
        {
            m_pageScPanel->bringToFront();

            VfxU8 ind_idx = m_next_scr_idx;
            for (i = 0; i < m_next_scr_idx; i++)
            {
                if (m_shell_cp[i] == NULL &&
                    ind_idx > 0)
                    ind_idx--;
            }
                
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);
            m_pageScPanel->displayInd(ind_idx);
            VfxAutoAnimate::commit();
        }
    #endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */
        
        m_cur_view_state = APP_SHELL_FULL_VIEW;
       

        return VFX_TRUE;  
    }
    else if ((event.keyCode != VFX_KEY_CODE_END &&
              event.keyCode != VFX_KEY_CODE_POWER &&
              event.keyCode != VFX_KEY_CODE_SEND) &&
             m_shell_cp[m_cur_scr_idx] &&
             m_shell_cp[m_cur_scr_idx]->getPanelId() != VAPP_SHELL_PANEL_HOME)
    {
        /* retrieve all other key events */
        VFX_LOG(VFX_INFO, VAPP_SHELL_BASE_SCR_KEY_EVENT, 4);
        return VFX_TRUE;
    }
#endif /* defined(__MMI_VUI_SHELL_MULTI_PAGE__) */
    
    VFX_LOG(VFX_INFO, VAPP_SHELL_BASE_SCR_KEY_EVENT, 5);
    return VfxScreen::onKeyInput(event);
}


void VappShellScr::onAbortPageAct()
{
#if defined(__MMI_VUI_SHELL_MULTI_PAGE__)
    m_do_change_page = VFX_FALSE;
#endif
}


void VappShellScr::onHideShortCut(VfxBool isHide)
{
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    VFX_LOG(VFX_INFO, VAPP_SHELL_BASE_HIDE_SHORTCUT, 3, isHide);

    hideShortcutBar(isHide);
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */
}


void VappShellScr::onDelayPageFinish(VfxTimer *source)
{
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    VFX_UNUSED(source);

    m_timer->m_signalTick.disconnect(this, &VappShellScr::onDelayPageFinish);

    if (m_is_in_history == VFX_TRUE)
    {
        VFX_LOG(VFX_INFO2, VAPP_SHELL_BASE_IS_IN_HISTORY);
        return;
    }

    VFX_DEV_ASSERT(m_shell_cp[m_cur_scr_idx] != NULL);
    
    if (m_shell_cp[m_cur_scr_idx]->getPanelState() == VappShellPanel::APP_SHELL_INIT_VIEW)
    {
        m_shell_cp[m_cur_scr_idx]->onEnterView();
    }
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */
}

void VappShellScr::onEnterSwitchFinish(VfxTimer *source)
{
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    VfxU8 i;
    VfxU8 panel_num = 0;
    VfxU8 cur_page_idx = 0;

    VFX_UNUSED(source);

    m_timer->m_signalTick.disconnect(this, &VappShellScr::onEnterSwitchFinish);
    
        VFX_DEV_ASSERT(m_shell_cp[m_cur_scr_idx] != NULL);
            
        VfxU8 cur_scr_id = m_shell_cp[m_cur_scr_idx]->getPanelId();
        
        for (i = 0; i < APP_PANEL_NUM; i++)
        {
            if (m_shell_cp[i] != NULL)
            {
                m_shell_cp[i]->setHidden(VFX_TRUE);
                m_shell_cp[i]->setFocused(VFX_FALSE);
                m_shell_cp[i]->setIsUnhittable(VFX_TRUE);
                if (m_shell_cp[i]->getPanelState() ==
                    VappShellPanel::APP_SHELL_ENTER_VIEW)
                {
                    m_shell_cp[i]->onExitView(VappShellPanel::APP_SHELL_PANEL_SWITCH_EXIT);    
                }
                m_shell_cp[i]->setIsOpaque(VFX_TRUE);
                
                // change pos in array
                for (VfxU8 j = 0; j < i; j++)
                {
                    if (m_shell_cp[j] == NULL)
                    {
                        m_shell_cp[j] = m_shell_cp[i];
                        m_shell_cp[i] = NULL;
                    }
                }
                panel_num++;
            }
        }
        
        // find current screen index 
        for (i = 0; i < APP_PANEL_NUM; i++)
        {
            if (m_shell_cp[i]->getPanelId() == cur_scr_id)
            {
                m_cur_scr_idx = i;
                break;
            }
        }
        // create shell switch menu
        VFX_LOG(VFX_INFO2, VAPP_SHELL_BASE_CREATE_SWITCH_MENU);
    
        // set VRT additional cache pool
        m_vrt_cache_mem = vadp_p2v_shell_vrt_cache_mem_alloc(MAX_SHELL_VRT_CACHE_SIZE);
        if (m_vrt_cache_mem != NULL)
        {
            vrt_cache_mem_attach((void *)m_vrt_cache_mem, MAX_SHELL_VRT_CACHE_SIZE);
        }
    
        VfxSize size = getScreenSize();
        VFX_OBJ_CREATE_EX(m_shell_menu, VappShellWheelMenu, this, 
                         (m_cur_scr_idx, panel_num, m_shell_cp));
        m_shell_menu->setRect(0, SWITCH_MENU_Y_POS, size.width, size.height);
        m_shell_menu->m_signalSelect.connect(this, &VappShellScr::onPageSelect);
        m_shell_menu->setFocused(VFX_TRUE);
        m_icon_bar->bringToFront();
        m_pageScPanel->setHidden(VFX_TRUE);
        m_pageScPanel->setIsUnhittable(VFX_TRUE);
    #endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */
    }


void VappShellScr::onEnterSwitch()
{
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    // create switch backround image
    if (m_shell_menu == NULL)
    {
        if (!mmi_frm_is_scenario_started(MMI_SCENARIO_ID_DEFAULT))
        {
            mmi_frm_start_scenario(MMI_SCENARIO_ID_DEFAULT);
        }
        
        if (m_page_panel != NULL)
        {
            VFX_LOG(VFX_INFO, VAPP_SHELL_BASE_CANCEL_PANEL_SWIPE);
        
            /* change parent */
            m_shell_cp[m_cur_scr_idx]->removeFromParentFrame();
            m_shell_cp[m_next_scr_idx]->removeFromParentFrame();
            addChildFrame(m_shell_cp[m_cur_scr_idx]);
            addChildFrame(m_shell_cp[m_next_scr_idx]);
            m_next_scr_idx = m_cur_scr_idx;
            VFX_OBJ_CLOSE(m_page_panel);
        }
        
        m_cur_view_state = APP_SHELL_SWITCH_VIEW;
        
        if (m_timer)
        {
            /* stop the timer if necessary */
            m_timer->stop();
            m_timer->m_signalTick.disconnect(this, &VappShellScr::onDelayPageFinish);
            m_timer->m_signalTick.disconnect(this, &VappShellScr::onPageSwitch);
            m_timer->m_signalTick.disconnect(this, &VappShellScr::onPageSelectFinish);
        }
        
        // fold all bar if needed
        VFX_DEV_ASSERT(m_shell_cp[m_cur_scr_idx] != NULL);
        
        VFX_OBJ_CREATE(m_switch_bg, VfxImageFrame, this);
        
        m_switch_bg->setResId(VAPP_SHELL_IMG_SWITCH_SCENE);
        m_switch_bg->setBgColor(VFX_COLOR_BLACK);
        m_switch_bg->setRect(0, 0, 
        m_switch_bg->getBounds().getWidth(),
        m_switch_bg->getBounds().getHeight());
        m_switch_bg->setIsCached(VFX_TRUE);
        m_switch_bg->setIsOpaque(VFX_TRUE);
        m_icon_bar->bringToFront();

        if (m_timer == NULL)
        {
            VFX_OBJ_CREATE(m_timer, VfxTimer, this);
        }

        m_timer->setStartDelay(0);
        m_timer->m_signalTick.connect(this, &VappShellScr::onEnterSwitchFinish);
        m_timer->start();
    }
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */
}


void VappShellScr::onEnterMenu()
{
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    vadp_v2p_hs_launch_main_menu();
#endif
}


void VappShellScr::onEnterDial()
{
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    vadp_v2p_hs_launch_dialer();
#endif
}


void VappShellScr::onEnterLock()
{
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    mmi_scr_locker_launch();
#endif
}


void VappShellScr::onOrderChange(const VdatShellPageOrder::PageState *page_order, 
                                 const VfxU16 &num)
{
#if defined(__MMI_VUI_SHELL_MULTI_PAGE__)
    VFX_DEV_ASSERT(page_order != NULL);
    VFX_DEV_ASSERT(num == APP_PANEL_NUM);
    
    VappShellPanel *tmp_shell_cp[APP_PANEL_NUM];
    const vapp_shell_panel_tbl_struct *tbl = g_vapp_shell_panel_create_tbl;

    VfxBool num_change = VFX_FALSE;
    VfxU8 display_scr_idx = m_cur_scr_idx;
    VfxU8 i, j, k;

    for (i = 0; i < APP_PANEL_NUM; i++)
    {
        for (j = 0; j < APP_PANEL_NUM; j++)
        {
            if (m_shell_cp[j] &&
                m_shell_cp[j]->getPanelId() == page_order[i].value)
            {
                // change order
                if (page_order[i].state == VFX_TRUE)
                {
                    VFX_LOG(VFX_INFO, VAPP_SHELL_BASE_CHANGE_ORDER, 
                            page_order[i].value, j, i);
                    if (m_cur_scr_idx == j)
                    {
                        // update new display position
                        display_scr_idx = i;
                    }
                    tmp_shell_cp[i] = m_shell_cp[j];
                    m_shell_cp[j]->setPanelOrder(i);
                    
                }
                else
                {
                    VFX_LOG(VFX_INFO, VAPP_SHELL_BASE_CLOSE_PANEL, 
                            page_order[i].value, j, i);
                    // panel is closed
                    VFX_OBJ_CLOSE(m_shell_cp[j]);
                    tmp_shell_cp[i] = NULL;
                #ifdef __MMI_VUI_SHELL_MULTI_PAGE__
                    if (m_ind_num > 0)
                    {
                        m_ind_num--;
                        num_change = VFX_TRUE;
                    }
                #endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */
                }
                
                break;
            }
        }
        if (j >= VAPP_SHELL_PANEL_TOTAL)
        {
            // page doesn't exist in current list. we need to create it
            for (k = 0; k < APP_PANEL_NUM; k++)
            {
                if (tbl[k].panel_id == page_order[i].value)
                {
                    VFX_LOG(VFX_INFO, VAPP_SHELL_BASE_ADD_PANEL, 
                            page_order[i].value, page_order[i].state, i);
                    if (page_order[i].state == VFX_TRUE)
                    {
                        tmp_shell_cp[i] = tbl[k].func_ptr(this);
                        tmp_shell_cp[i]->setPanelId(tbl[k].panel_id);
                        tmp_shell_cp[i]->setPanelOrder(i);
                        tmp_shell_cp[i]->setPanelStrId((VfxResId)tbl[k].str_id);
                        tmp_shell_cp[i]->setAppBounds(m_page_bounds);
                        // register abort change page event
                        tmp_shell_cp[i]->m_signalAbort.connect(this, 
                                  &VappShellScr::onAbortPageAct);
                    
                    #ifdef __MMI_VUI_SHELL_MULTI_PAGE__
                        tmp_shell_cp[i]->m_signalHideShortCut.connect(this, 
                                  &VappShellScr::onHideShortCut);
                    #endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */

                        tmp_shell_cp[i]->setHidden(VFX_TRUE);
                        tmp_shell_cp[i]->setPos(0,0);
                        m_ind_num++;
                        num_change = VFX_TRUE;
                        break;
                    }
                    else
                    {
                        tmp_shell_cp[i] = NULL;
                    }
                }
            }
        }
        
    }
    // config new order table
    for (i = 0; i < APP_PANEL_NUM; i++)
    {
        m_shell_cp[i] = tmp_shell_cp[i];
    }

#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    if (m_pageScPanel)
    {
        if (num_change == VFX_TRUE)
        {
            // create new ind bar with new ind numbers
            m_pageScPanel->createIndBar(m_ind_num);
        }

        m_cur_scr_idx = display_scr_idx;

        for (i = 0; i < m_cur_scr_idx; i++)
        {
            if (m_shell_cp[i] == NULL &&
                display_scr_idx > 0)
                display_scr_idx--;
        }
        m_pageScPanel->displayInd(display_scr_idx);
    }
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */
}


VfxBool VappShellScr::onPreviewPenInput(VfxPenEvent &event)
{
#if defined(__MMI_VUI_SHELL_MULTI_PAGE__)

    VFX_LOG(VFX_INFO2, VAPP_CUBE_ON_PREVIEW_PEN_INPUT, 0, event.pos.x, event.pos.y);

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        // initialize auto change page
        VFX_LOG(VFX_INFO2, VAPP_CUBE_ON_PREVIEW_PEN_INPUT, 1, event.pos.x, event.pos.y);
        m_do_change_page = VFX_TRUE;
        m_is_critira_matched = VFX_FALSE;
    }
    
    if( (isPopupPresent() == VFX_TRUE) ||
        (m_cur_view_state == APP_SHELL_SWITCH_VIEW) || !m_do_change_page ||
        event.pos.y > (getScreenSize().height - 
                       m_pageScPanel->getBounds().getHeight()))
    {
        VFX_LOG(VFX_INFO2, VAPP_CUBE_ON_PREVIEW_PEN_INPUT, 2, event.pos.x, event.pos.y);
        return VfxScreen::onPreviewPenInput(event);
    }
    
    if (m_shell_cp[m_cur_scr_idx] &&
        !m_shell_cp[m_cur_scr_idx]->isShortcutBarHide())
    {
        if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
        {
            VFX_LOG(VFX_INFO, VAPP_CUBE_ON_PREVIEW_PEN_INPUT, 3, event.pos.x, event.pos.y);

             VappShellPanel *panel = m_shell_cp[m_cur_scr_idx];
            if ((panel->isRegDefaultPageAct(event.relObjList) == VFX_FALSE))
            {
                m_do_change_page = VFX_FALSE;
                VFX_LOG(VFX_INFO2, VAPP_CUBE_ON_PREVIEW_PEN_INPUT, 2, event.pos.x, event.pos.y);
                return VfxScreen::onPreviewPenInput(event);
            }
        }
        else if (event.type == VFX_PEN_EVENT_TYPE_UP ||
                   event.type == VFX_PEN_EVENT_TYPE_MOVE)
        {
            VFX_LOG(VFX_INFO, VAPP_CUBE_ON_PREVIEW_PEN_INPUT, 4, 
                        event.pos.x, event.pos.y);
            
            if (m_shell_cp[m_cur_scr_idx]->isRegDefaultPageAct(event.relObjList) == VFX_FALSE)
            {
                m_do_change_page = VFX_FALSE;
                return VfxScreen::onPreviewPenInput(event);
            }

            VfxFloat   x_moved_distance;
            VfxFloat   y_moved_distance;
               
            x_moved_distance = (VfxFloat)(event.pos.x - event.downPos.x);
            y_moved_distance = (VfxFloat)(event.pos.y - event.downPos.y);

            /* check if y > tan*r or y < -1*tan*r */
            VfxSize size = getScreenSize();
            VfxFloat radius = size.width/4.0f;
            if  (!m_is_critira_matched &&
                VFX_ABS(y_moved_distance) > (radius * VAPP_SHELL_MOVED_ANGLE))
            {
                /* angle is over and we don' t need to do change page decision */
                VFX_LOG(VFX_INFO, VAPP_CUBE_ON_PREVIEW_PEN_INPUT, 5, 
                        VFX_ABS(y_moved_distance), radius * VAPP_SHELL_MOVED_ANGLE);
                m_do_change_page = VFX_FALSE;
                return VfxScreen::onPreviewPenInput(event);
            }
            
            VfxFloat total_moved_r = sqrt(x_moved_distance*x_moved_distance + y_moved_distance*y_moved_distance );
                VFX_LOG(VFX_INFO, VAPP_CUBE_ON_PREVIEW_PEN_INPUT, 6, 
                        total_moved_r, radius);
            
            if (total_moved_r >= radius || m_is_critira_matched)
            {
                VFX_LOG(VFX_INFO, VAPP_CUBE_ON_PREVIEW_PEN_INPUT, 7, 
                        event.pos.x, event.pos.y);
                if (event.type == VFX_PEN_EVENT_TYPE_MOVE)
                {
                    m_is_critira_matched = VFX_TRUE;
                }
                else
                {
                    if (x_moved_distance > 0)
                    {
                        capture();
                        swipePanel(VFX_FALSE);
                        return VFX_TRUE;
                    }
                    else
                    {
                        // switch to next page
                        capture();
                        swipePanel(VFX_TRUE);
                        return VFX_TRUE;
                    }
                    m_is_critira_matched = VFX_FALSE;
                    m_do_change_page = VFX_TRUE;
                }
            }
        }
    }

#endif /* defined(__MMI_VUI_SHELL_MULTI_PAGE__) */

    return VfxScreen::onPreviewPenInput(event);
}


void VappShellScr::onPageSwitchFinish(VfxFrame *panel, VfxBool result)
{
#if defined(__MMI_VUI_SHELL_MULTI_PAGE__)

    VFX_LOG(VFX_INFO2, VAPP_SHELL_BASE_PANEL_SWIPE_FINISH);

    if (m_shell_cp[m_cur_scr_idx])
    {
        m_shell_cp[m_cur_scr_idx]->onSwitchEnd();
    }

    if (m_shell_cp[m_next_scr_idx])
    {
        m_shell_cp[m_next_scr_idx]->onSwitchEnd();
    }

    // if page panel is already close, we need not handle this event
    if (m_page_panel == NULL)
        return;
    
    if (result == VFX_TRUE)
    {
        VFX_DEV_ASSERT(m_shell_cp[m_cur_scr_idx] && m_shell_cp[m_next_scr_idx]);

        /* change parent */
        m_shell_cp[m_cur_scr_idx]->setIsCached(VFX_FALSE);
        m_shell_cp[m_cur_scr_idx]->removeFromParentFrame();
        m_shell_cp[m_next_scr_idx]->setIsCached(VFX_FALSE);
        m_shell_cp[m_next_scr_idx]->removeFromParentFrame();
        addChildFrame(m_shell_cp[m_cur_scr_idx]);
        addChildFrame(m_shell_cp[m_next_scr_idx]);

        VFX_OBJ_CLOSE(m_page_panel);
            
        // close original panel
        VfxSize size = getScreenSize();

        /* exit previous page */
        VfxU8 state = m_shell_cp[m_cur_scr_idx]->getPanelState();
        if (state == VappShellPanel::APP_SHELL_ENTER_VIEW)
        {
            m_shell_cp[m_cur_scr_idx]->onExitView(VappShellPanel::APP_SHELL_PANEL_SWITCH_EXIT);
        }
        
        // restore the freezed frame cache mode to AUTO
        m_shell_cp[m_cur_scr_idx]->setCacheMode(VFX_CACHE_MODE_AUTO);        

        if (m_shell_cp[m_cur_scr_idx]->getPanelState() == 
            VappShellPanel::APP_SHELL_INIT_VIEW &&
            m_shell_cp[m_cur_scr_idx]->isPanelAlwaysExist() == VFX_FALSE)
        {
            m_shell_cp[m_cur_scr_idx]->onDeinitView();
        }
        
        // let previous to be invisiable
        //m_shell_cp[m_cur_scr_idx]->setPos(0 - size.width, 0);
        m_shell_cp[m_cur_scr_idx]->setHidden(VFX_TRUE);  
        
        // set current screen index
        m_cur_scr_idx = m_next_scr_idx;
        // Register abort change page event
        VFX_DEV_ASSERT(m_shell_cp[m_cur_scr_idx]);
        
        // enter screen view
        //m_shell_cp[m_cur_scr_idx]->setPos(0, 0);
        m_shell_cp[m_cur_scr_idx]->setHidden(VFX_FALSE);

        // start a timer to delay enter the screen
         // start a timer to enter the switch mode
        if (m_timer == NULL)
        {
            VFX_OBJ_CREATE(m_timer, VfxTimer, this);
        }

        m_shell_cp[m_cur_scr_idx]->setFocused(VFX_TRUE);
        m_shell_cp[m_cur_scr_idx]->setIsUnhittable(VFX_FALSE);
        
        m_timer->setStartDelay(300);
        m_timer->m_signalTick.connect(this, &VappShellScr::onDelayPageFinish);
        m_timer->start();
        
        if (m_icon_bar)
        {
            m_icon_bar->bringToFront();
        }
    #ifdef __MMI_VUI_SHELL_MULTI_PAGE__
        if (m_pageScPanel)
        {
            m_pageScPanel->bringToFront();
        }
    #endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */
    
        m_cur_view_state = APP_SHELL_FULL_VIEW;
    }
    
#endif /* defined(__MMI_VUI_SHELL_MULTI_PAGE__) */
}


void VappShellScr::onPageSwitch(VfxTimer *source)
{ 
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    VFX_LOG(VFX_INFO2, VAPP_SHELL_BASE_PANEL_START_SWIPE);

    // set page index
    VFX_UNUSED(source);

    m_timer->m_signalTick.disconnect(this, &VappShellScr::onPageSwitch);

    if (m_page_panel == NULL)
    {
        VFX_OBJ_CREATE(m_page_panel, VcpPagePanel, this);
    }
    
    VfxSize size = getScreenSize();
    m_page_panel->setRect(0, 0, size.width, size.height);
    m_page_panel->addChildFrame(m_shell_cp[m_cur_scr_idx]);
    m_page_panel->addChildFrame(m_shell_cp[m_next_scr_idx]);
    
    // freeze the current screen (to be pushed out)
    m_shell_cp[m_cur_scr_idx]->setCacheMode(VFX_CACHE_MODE_FREEZE);

    m_page_panel->setCurrentFrame((VfxFrame *)m_shell_cp[m_cur_scr_idx]);
    m_page_panel->m_signalFinished.connect(this, &VappShellScr::onPageSwitchFinish);

    m_shell_cp[m_cur_scr_idx]->onSwitchBegin(VFX_TRUE);
    m_shell_cp[m_next_scr_idx]->onSwitchBegin(VFX_FALSE);

    if (m_is_loop)
    {
        
        if (m_cur_scr_idx > m_next_scr_idx)
        {
            // change to previous page
            m_page_panel->switchTo((VfxFrame *)m_shell_cp[m_next_scr_idx], 
                                  VCP_PAGE_EFFECT_PUSH, SHELL_SWITCH_TIME, 
                                  VCP_PAGE_DIRECTION_FROM_RIGHT);
        }
        else
        {
            // change to next page
            m_page_panel->switchTo((VfxFrame *)m_shell_cp[m_next_scr_idx], 
                                 VCP_PAGE_EFFECT_PUSH, SHELL_SWITCH_TIME, 
                                 VCP_PAGE_DIRECTION_FROM_LEFT);
        }
    }
    else
    {
    if (m_cur_scr_idx > m_next_scr_idx)
    {
        // change to previous page
        m_page_panel->switchTo((VfxFrame *)m_shell_cp[m_next_scr_idx], 
                              VCP_PAGE_EFFECT_PUSH, SHELL_SWITCH_TIME, 
                              VCP_PAGE_DIRECTION_FROM_LEFT);
    }
    else
    {
        // change to next page
        m_page_panel->switchTo((VfxFrame *)m_shell_cp[m_next_scr_idx], 
                             VCP_PAGE_EFFECT_PUSH, SHELL_SWITCH_TIME, 
                             VCP_PAGE_DIRECTION_FROM_RIGHT);
    }
    }

    if (m_icon_bar)
    {
        m_icon_bar->bringToFront();
    }
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    if (m_pageScPanel)
    {
        m_pageScPanel->bringToFront();

        // set page index
        VfxU8 ind_idx = m_next_scr_idx;

        for (VfxU8 i = 0; i < m_next_scr_idx; i++)
        {
            if (m_shell_cp[i] == NULL &&
                ind_idx > 0)
                ind_idx--;
        }
        VfxAutoAnimate::begin();
        if (m_is_loop)
        {
            VfxAutoAnimate::setDisable(VFX_TRUE);
        }
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_pageScPanel->displayInd(ind_idx);
        VfxAutoAnimate::commit();
    }
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */

    m_is_loop = VFX_FALSE;
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */
}


void VappShellScr::onPageSelect(VfxS32 select_scr_idx)
{
#if defined(__MMI_VUI_SHELL_MULTI_PAGE__)
    VFX_DEV_ASSERT(m_shell_cp[m_cur_scr_idx] && m_shell_cp[select_scr_idx]);

    VFX_LOG(VFX_INFO2, VAPP_SHELL_BASE_PANEL_IS_SELECT, 0);
    
    // close wheel menu
    VFX_OBJ_CLOSE(m_switch_bg);
    
    if (m_shell_menu)
    {
        m_shell_menu->setHidden(VFX_TRUE);
        m_shell_menu->setFocused(VFX_FALSE);
        m_shell_menu->setIsUnhittable(VFX_TRUE);
    }

    // recover array order
    VfxU8 panel_order;
    select_scr_idx = m_shell_cp[select_scr_idx]->getPanelOrder();

    VfxU8 i;
    VappShellPanel *tmp_shell_cp[APP_PANEL_NUM];
    for (i = 0; i < APP_PANEL_NUM; i++)
        tmp_shell_cp[i] = NULL;
    
    for (i = 0; i < APP_PANEL_NUM; i++)
    {
        if (m_shell_cp[i])
        {
            m_shell_cp[i]->setPos(0, 0);
            m_shell_cp[i]->setBounds(VfxRect(0, 0, 
                getScreenSize().width, getScreenSize().height));
            panel_order = m_shell_cp[i]->getPanelOrder();
            tmp_shell_cp[panel_order] = m_shell_cp[i];
        }
    }
    for (i = 0; i < APP_PANEL_NUM; i++)
        m_shell_cp[i] = tmp_shell_cp[i];
    
    // update current screen index
    VfxSize size = getScreenSize();
    m_cur_scr_idx = select_scr_idx;

    VfxTransform affine;
    affine.data.affine.sx = 1.0f;
    affine.data.affine.sy = 1.0f;
    
    // change all others panel state back to onInit
    for (i = 0; i < APP_PANEL_NUM; i++)
    {
        if (m_shell_cp[i] != NULL)
        {
            addChildFrame(m_shell_cp[i]);
            m_shell_cp[i]->setTransform(affine);
            
            if (i != select_scr_idx)
            {
                if (m_shell_cp[i]->getPanelState() == VappShellPanel::APP_SHELL_INIT_VIEW &&
                    m_shell_cp[i]->isPanelAlwaysExist() == VFX_FALSE)
                {
                    m_shell_cp[i]->onDeinitView();
                }
                // Let other screen invisiable
                m_shell_cp[i]->setHidden(VFX_TRUE);
            }
        }
    }

    m_shell_cp[m_cur_scr_idx]->setHidden(VFX_FALSE);
    m_shell_cp[m_cur_scr_idx]->setFocused(VFX_TRUE);
    m_shell_cp[m_cur_scr_idx]->setIsUnhittable(VFX_FALSE);

    if (m_icon_bar)
    {
        m_icon_bar->bringToFront();
    }
    
    // start a timer to enter the switch mode
    if (m_timer == NULL)
    {
        VFX_OBJ_CREATE(m_timer, VfxTimer, this);
    }
 
    if (m_is_in_history == VFX_FALSE &&
        m_shell_cp[m_cur_scr_idx]->getPanelState() == VappShellPanel::APP_SHELL_INIT)
    {
        // enter screen view
        m_shell_cp[m_cur_scr_idx]->onInitView();
    }
        
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    if (m_pageScPanel)
    {
        m_pageScPanel->bringToFront();
        m_pageScPanel->setHidden(VFX_FALSE);
        m_pageScPanel->setIsUnhittable(VFX_FALSE);
     
        VfxU8 ind_idx = m_cur_scr_idx;
        for (i = 0; i < m_cur_scr_idx; i++)
        {
            if (m_shell_cp[i] == NULL &&
                ind_idx > 0)
            {
                ind_idx--;
            }
        }
        
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        m_pageScPanel->displayInd(ind_idx);
        VfxAutoAnimate::commit();
    }
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */
    
    /* draw one frame */
    m_timer->setStartDelay(0);
    m_timer->m_signalTick.connect(this, &VappShellScr::onPageSelectFinish);
    m_timer->start();
#endif /* defined(__MMI_VUI_SHELL_MULTI_PAGE__) */

}


void VappShellScr::onPageSelectFinish(VfxTimer *source)
{ 
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    // set page index
    VFX_UNUSED(source);

    VFX_LOG(VFX_INFO2, VAPP_SHELL_BASE_PANEL_IS_SELECT, 1);

    m_timer->m_signalTick.disconnect(this, &VappShellScr::onPageSelectFinish);

    VFX_DEV_ASSERT(m_shell_cp[m_cur_scr_idx] != NULL);
    
    if (m_is_in_history == VFX_FALSE &&
        m_shell_cp[m_cur_scr_idx]->getPanelState() == VappShellPanel::APP_SHELL_INIT_VIEW)
    {
        // enter screen view
        m_shell_cp[m_cur_scr_idx]->onEnterView();
    }

    // close wheel menu
    VFX_OBJ_CLOSE(m_shell_menu);
     
    m_cur_view_state = APP_SHELL_FULL_VIEW;
     
    // free vrt cache memory
    if (m_vrt_cache_mem != NULL)
    {
        vrt_cache_mem_detach((void *)m_vrt_cache_mem);
        vadp_p2v_shell_vrt_cache_mem_free(m_vrt_cache_mem);
        m_vrt_cache_mem = NULL;
    }
    
    if (mmi_frm_get_active_scenario_id() == MMI_SCENARIO_ID_DEFAULT)
    {
        mmi_idle_notify_event();
    }
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */
}


void VappShellScr::updateShortcutRect(VfxBool isHide)
{
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    if (m_pageScPanel)
    {
        VfxS32 i;
        VfxPoint pos = m_pageScPanel->getPos();
       
        if (m_pageScPanel->isHide() == isHide)
            return;
        
        if (isHide)
        {
            m_page_bounds = VfxRect(m_page_bounds.origin, 
                                    VfxSize(m_page_bounds.size.width, 
                                    m_page_bounds.size.height + 
                                    m_pageScPanel->getBounds().getHeight()));
        }
        else
        {
            m_page_bounds = VfxRect(m_page_bounds.origin, 
                                    VfxSize(m_page_bounds.size.width, 
                                    m_page_bounds.size.height - 
                                    m_pageScPanel->getBounds().getHeight()));
        }
        for (i = 0; i < APP_PANEL_NUM; i++)
        {
            if (m_shell_cp[i] != NULL)
            {
                // update application bounds
                m_shell_cp[i]->setAppBounds(m_page_bounds);
            }
        }
    }
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */
}


void VappShellScr::hideShortcutBar(VfxBool isHide)
{
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    VFX_DEV_ASSERT(m_pageScPanel);
 
    updateShortcutRect(isHide);
    m_pageScPanel->hide(isHide);
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */
}


void VappShellScr::swipePanel(VfxBool goto_next)
{
#if defined(__MMI_VUI_SHELL_MULTI_PAGE__)   
    if (m_timer)
    {
        /* stop the full view delay timer if necessary */
        m_timer->stop();
        m_timer->m_signalTick.disconnect(this, &VappShellScr::onDelayPageFinish);
    }

    VfxS8 i;
    m_is_loop = VFX_FALSE;
    
    if (goto_next)
    {
        // change to next panel
        if (m_cur_scr_idx < (APP_PANEL_NUM - 1))
        {
            for (i = m_cur_scr_idx + 1; i < APP_PANEL_NUM; i++)
            {
                if (m_shell_cp[i] != NULL)
                {
                    switchTo(i);
                    return;
                }
            }
        }

        // loop occur
        for (i = 0; i < APP_PANEL_NUM; i++)
        {
            if (m_shell_cp[i] != NULL)
            {
                m_is_loop = VFX_TRUE;
                switchTo(i);
                return;
            }
        }
    }
    else
    {
        // change to previous panel
        if(m_cur_scr_idx > 0)
        {
            for (i = m_cur_scr_idx - 1; i >= 0; i--)
            {
                if (m_shell_cp[i] != NULL)
                {
                    switchTo(i);
                    return;
                }
            }
        }
        // loop occur
        // switch to previous page
       for (i = APP_PANEL_NUM - 1; i >= 0; i--)
       {
            if (m_shell_cp[i] != NULL)
            {
                m_is_loop = VFX_TRUE;
                switchTo(i);
                return;
            }
        }
    }

    // it's impossible to go here
    VFX_DEV_ASSERT(0);
#endif /* defined(__MMI_VUI_SHELL_MULTI_PAGE__)   */
}

void VappShellScr::switchTo(VfxU8 page_idx)
{
#if defined(__MMI_VUI_SHELL_MULTI_PAGE__)    
    VFX_LOG(VFX_INFO2, VAPP_SHELL_BASE_TRIGGER_SWIPE_PANEL, page_idx);

    // exit view to release resource
    VFX_DEV_ASSERT(m_shell_cp[m_cur_scr_idx]);
    VFX_DEV_ASSERT(m_shell_cp[page_idx]);
 
    m_next_scr_idx = page_idx;

    if (m_shell_cp[page_idx]->getPanelState() != VappShellPanel::APP_SHELL_INIT_VIEW)
    {
        m_shell_cp[page_idx]->onInitView();
    }
    
    // set current frame
    m_shell_cp[page_idx]->setHidden(VFX_TRUE);
    m_shell_cp[page_idx]->setIsCached(VFX_TRUE);
    m_shell_cp[page_idx]->setIsOpaque(VFX_TRUE);
    m_shell_cp[page_idx]->setIsUnhittable(VFX_TRUE);
    m_shell_cp[page_idx]->setFocused(VFX_FALSE);    

    m_shell_cp[m_cur_scr_idx]->setIsUnhittable(VFX_TRUE);
    m_shell_cp[m_cur_scr_idx]->setIsCached(VFX_TRUE);
    m_shell_cp[m_cur_scr_idx]->setIsOpaque(VFX_TRUE);
    m_shell_cp[m_cur_scr_idx]->setFocused(VFX_FALSE);

    // prepare first two image at first
    if (m_timer == NULL)
    {
        VFX_OBJ_CREATE(m_timer, VfxTimer, this);
    }
    m_timer->setStartDelay(0);
    m_timer->m_signalTick.connect(this, &VappShellScr::onPageSwitch);
    m_timer->start();

    m_cur_view_state = APP_SHELL_SWITCH_VIEW;
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */

}


VfxBool VappShellScr::isActive()
{
    if (m_shell_cp[m_cur_scr_idx])
    {
        VFX_LOG(VFX_INFO2, VAPP_SHELL_BASE_IS_ACTIVE, 1);
        return VFX_TRUE;
    }

    VFX_LOG(VFX_INFO2, VAPP_SHELL_BASE_IS_ACTIVE, 0);
    return VFX_FALSE;
}


void VappShellScr::entry(VfxContext *context, VfxScreen *screen)
{
    // let the current screen stay in enterView if
    // we are not in animation stage   
    VFX_LOG(VFX_INFO, VAPP_CUBE_ON_INIT_MSG);
    
    VFX_DEV_ASSERT(m_shell_cp[m_cur_scr_idx] != NULL);

    m_is_in_history = VFX_FALSE;

#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    if (m_shell_menu != NULL)
    {
        /* start scenario again */
        if (!mmi_frm_is_scenario_started(MMI_SCENARIO_ID_DEFAULT))
        {
            mmi_frm_start_scenario(MMI_SCENARIO_ID_DEFAULT);
        }
    }
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */
    
    if (m_shell_cp[m_cur_scr_idx]->getPanelState() == 
        VappShellPanel::APP_SHELL_DEINIT)
    {
        /* impossible */
        VFX_DEV_ASSERT(0);
    }
        
    if (m_shell_cp[m_cur_scr_idx]->getPanelState() == 
        VappShellPanel::APP_SHELL_INIT)
    {
        m_shell_cp[m_cur_scr_idx]->onInitView();
    }

    // in small screen redraw, we don't do enterView 
    if (m_cur_view_state == APP_SHELL_FULL_VIEW)
    {
        if (m_shell_cp[m_cur_scr_idx]->getPanelState() == 
         VappShellPanel::APP_SHELL_INIT_VIEW)
        {
            m_shell_cp[m_cur_scr_idx]->onEnterView();
            m_shell_cp[m_cur_scr_idx]->setFocused(VFX_TRUE);
            m_shell_cp[m_cur_scr_idx]->setIsUnhittable(VFX_FALSE);
            m_shell_cp[m_cur_scr_idx]->setHidden(VFX_FALSE);
        }
    }
    
    // recreate status icon bar if 
    // it is not created when the screen is entered
    if (m_icon_bar == NULL)
    {
        VFX_OBJ_CREATE(m_icon_bar, VappHsStatusIcon, this);
        m_icon_bar->setPos(0, 0);
     #ifdef __MMI_VUI_SHELL_MULTI_PAGE__
        m_icon_bar->setBgColor(VFX_COLOR_BLACK);
        m_icon_bar->setOpacity(1.0f);
     #endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */
        m_icon_bar->bringToFront();
    }
    
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    // refresh shortcut 
    // workaround solution: venusmmi cannot support refresh 
    // screen function so we need to create the object to 
    // refresh the component. Otherwise, the string in button 
    // cannot be refresh
    if (m_pageScPanel != NULL)
    {
        // recover shortcut original state
        VfxBool is_shortcut_hide = m_pageScPanel->isHide();
        
        if (is_shortcut_hide)
        {
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);
            updateShortcutRect(VFX_FALSE);
            m_pageScPanel->hide(VFX_FALSE);
            VfxAutoAnimate::commit();
        }
        m_pageScPanel->closeShortCut();
        m_pageScPanel->createShortCut();
        m_pageScPanel->bringToFront();
        if (is_shortcut_hide)
        {
            // hide shortcut again
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);
            updateShortcutRect(VFX_TRUE);
            m_pageScPanel->hide(VFX_TRUE);
            VfxAutoAnimate::commit();
        }
    }
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */

#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    if (m_shell_menu != NULL)
    {
        for (VfxS32 i = 0; i < APP_PANEL_NUM; i++)
        {
            if (!m_shell_cp[i])
            {
                continue;
            }

            if (m_shell_cp[i]->getPanelState() == VappShellPanel::APP_SHELL_INIT)
            {
                m_shell_cp[i]->onInitView();
            }

            m_shell_cp[i]->setBounds(m_shell_cp[i]->getAppBounds());
        }

        // set VRT additional cache pool if we are still in switch mode
        m_vrt_cache_mem = vadp_p2v_shell_vrt_cache_mem_alloc(MAX_SHELL_VRT_CACHE_SIZE);
        if (m_vrt_cache_mem != NULL)
        {
            vrt_cache_mem_attach((void *)m_vrt_cache_mem, MAX_SHELL_VRT_CACHE_SIZE);
        }
    }
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */

    /* Enter top level screen */
    VfxTopLevel* topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->enterToScreen(screen);      
}


void VappShellScr::exit()
{    
    m_is_in_history = VFX_TRUE;

#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    // free vrt cache memory
    if (m_vrt_cache_mem != NULL)
    {
        vrt_cache_mem_detach((void *)m_vrt_cache_mem);
        vadp_p2v_shell_vrt_cache_mem_free(m_vrt_cache_mem);
        m_vrt_cache_mem = NULL;
    }
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */

    VFX_LOG(VFX_INFO, VAPP_CUBE_ON_DEINIT_MSG);

#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    if (m_page_panel &&
        m_shell_cp[m_next_scr_idx])
    {
        /* switch is under going so we drop it directly */
        onPageSwitchFinish((VfxFrame *)m_shell_cp[m_next_scr_idx], VFX_TRUE);
    }    
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */

    VfxTopLevel* topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->enterToScreen(NULL); 

    // temp solution: need to close status icon bar to 
    // release all VRT memory is occupied
    VFX_OBJ_CLOSE(m_icon_bar);
}


void VappShellScr::closeScreen(VfxBool force_release)
{
    // keep all panel stay in initView
    for (VfxS32 i = 0; i < APP_PANEL_NUM; i++)
    {
        if (m_shell_cp[i] &&
            (m_shell_cp[i]->getPanelState() == 
             VappShellPanel::APP_SHELL_ENTER_VIEW))
        {
            m_shell_cp[i]->onExitView(VappShellPanel::APP_SHELL_SCREEN_EXIT);
            m_shell_cp[i]->setFocused(VFX_FALSE);
            m_shell_cp[i]->setIsUnhittable(VFX_TRUE);
        }

        if (m_shell_cp[i] &&
            ((m_shell_cp[i]->isPanelAlwaysExist() == VFX_FALSE) ||
             force_release == VFX_TRUE))
        {
            if (m_shell_cp[i]->getPanelState() == 
                VappShellPanel::APP_SHELL_INIT_VIEW)
            {
                m_shell_cp[i]->onDeinitView();
            }
        }
    }
}


VfxSize VappShellScr::getScreenSize() const
{
    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;
    
    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);
    return VfxSize(main_screen_size.width, main_screen_size.height);   
}

#endif /* __MMI_VUI_SHELL_APP__ */


