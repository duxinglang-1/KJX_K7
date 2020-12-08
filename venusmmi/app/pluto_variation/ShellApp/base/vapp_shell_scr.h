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
 *  vapp_shell_scr.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file defines the shell control application
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_SHELL_SCR_H__
#define __VAPP_SHELL_SCR_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_SHELL_APP__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_screen.h"
#include "vfx_context.h"
#include "vfx_cpp_base.h"
#include "vfx_input_event.h"
#include "vfx_datatype.h"
#include "vfx_primitive_frame.h"
#include "vfx_timer.h"
#include "vfx_basic_type.h"
#include "vfx_frame.h"
#include "vcp_pluto_control.h"
#include "vcp_app_scr.h"
#include "vcp_wheel_menu.h"
#include "vcp_page_panel.h"
#include "vapp_hs_cp.h"
#include "vapp_shell_panel.h"
#include "vapp_shell_panel_cfg.h"
#include "vapp_shell_page_order.h"
#include "vapp_shell_multi_page_cp.h"
#include "vapp_op01_hs_cp.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_SHELL_MOVED_ANGLE    (0.577350269f)

/***************************************************************************** 
 * Class VappShell
 *****************************************************************************/

class VappShellScr : public VfxScreen
{
// Declaration
private:
    // cube application enum
    enum
    {
        SWITCH_MENU_Y_POS = 20,
        SHELL_SWITCH_TIME = 250,
        APP_PANEL_NUM = VAPP_SHELL_PANEL_TOTAL,    // surface number
        END_OF_ENUM
    };

    enum ShellViewCycle
    {
        APP_SHELL_FULL_VIEW,
        APP_SHELL_SWITCH_VIEW,
        APP_SHELL_VIEW_STATE_TOTAL
    };
    
// Constructor / Destructor
public:
    // This function is the constructor for a hello test screen.
    VappShellScr();

// Method
public:
    void exit();
    void entry(VfxContext *context, VfxScreen *screen);
    void closeScreen(VfxBool force_release);
    VfxBool isActive();
    
// Override
protected:
    // on init
    virtual void onInit();
    // on deinit
    virtual void onDeinit();

    virtual void onEnter(VfxBool isBackward);

    virtual void onExit(VfxBool isBackward);

    // key input handler
    virtual VfxBool onKeyInput(
        VfxKeyEvent &event // [IN] key input event
    );
    virtual VfxBool onPreviewPenInput(VfxPenEvent &event);

// Variable      
private:
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    VappShellShortCutPanel *m_pageScPanel;
    VfxU8          m_ind_num;
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */
    
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    // loop occur or not
    VfxBool m_is_loop;
    // do the aciont of changing page or not
    VfxBool  m_do_change_page;
    // change page threthold is matched
    VfxBool m_is_critira_matched;
    // shell switch menu
    VappShellWheelMenu *m_shell_menu;  
    // switch menu background
    VfxImageFrame *m_switch_bg;
    // page panel
    VcpPagePanel *m_page_panel;
    // shell timer
    VfxTimer *m_timer;
    VfxU8   m_next_scr_idx;
    VfxU8   *m_vrt_cache_mem;
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */
    // page bounds
    VfxRect m_page_bounds;
    // shell screen component (full view)
    VappShellPanel *m_shell_cp[APP_PANEL_NUM];
    // shell current screen index
    VfxS8   m_cur_scr_idx;    
    // shell view stage
    VfxU8 m_cur_view_state;
    
    // shell page icon bar
    VappHsStatusIcon  *m_icon_bar;
    VfxBool            m_is_in_history;

// Implementation
private:
    // update shortcut range
    void updateShortcutRect(VfxBool isHide);
    
    // hide shortcut bar
    void hideShortcutBar(VfxBool isHide);
    
    // swipe panel
    void swipePanel(VfxBool goto_next);
    
    // goto previous or next page
    void switchTo(
        VfxU8 page_idx // [IN] page index
    );
    
    void onOrderChange(const VdatShellPageOrder::PageState *page_order, 
                       const VfxU16 &num);
    
    void onPageSwitch(VfxTimer *source);
    
    // callback function for shell switch application to know 
    // when the switch transition is finish
    void onPageSwitchFinish(
        VfxFrame *panel, // [IN] switch panel
        VfxBool result   // [IN] switch result
    );

    // abort page action
    void onAbortPageAct();

    // select page
    void onPageSelect(
        VfxS32 select_scr_idx   // [IN] selected screen index
    );
    
    // page select finish
    void onPageSelectFinish(VfxTimer *source);

    void onDelayPageFinish(VfxTimer *source);

    void onEnterSwitchFinish(VfxTimer *source);

    // enter shell switch mode
    void onEnterSwitch();
    
    // enter main menu
    void onEnterMenu();

    // enter dial pad
    void onEnterDial();

    // enter keypad lock
    void onEnterLock();
    
    // hide shortcut bar
    void onHideShortCut(VfxBool isHide);
   
    // get screen size
    VfxSize getScreenSize() const;

};


#endif /* __MMI_VUI_SHELL_APP__ */

#endif /* __VAPP_SHELL_SCR_H__ */
