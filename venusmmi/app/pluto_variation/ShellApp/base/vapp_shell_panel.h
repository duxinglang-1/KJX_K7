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
 *  vapp_shell_panel.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Shell panel header
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
#ifndef __VAPP_SHELL_PANEL_H__
#define __VAPP_SHELL_PANEL_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_SHELL_APP__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_object.h"
#include "vfx_control.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_signal.h"
#include "vfx_cpp_base.h"
#include "vfx_basic_type.h"
#include "vfx_object_list.h"
#include "vfx_input_event.h"

#include "vcp_app_scr.h"
#include "vcp_pluto_control.h"
#include "vapp_hs_cp.h"
#include "vapp_hs_shortcut_panel.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define  VAPP_SHELL_PANEL_CREATE(_className, _alwaysExist)                                 \
    public:                                                                                \
        static inline VappShellPanel* createShellPanel(VfxObject *parent)                  \
        {                                                                                  \
            _className *shell_cp;                                                          \
            VFX_OBJ_CREATE(shell_cp, _className, parent);                                  \
            ((VappShellPanel *)shell_cp)->setPanelAlwaysExist(_alwaysExist);               \
            return (VappShellPanel *)shell_cp;                                             \
        }
   
/***************************************************************************** 
 * Class VappShellPanel
 *****************************************************************************/
class VappShellPanel : public VfxControl
{
    VFX_DECLARE_CLASS(VappShellPanel);
    
// Declaration
public:
    // shell life cycle enum
    enum ShellLifeCycleEnum
    {
        APP_SHELL_DEINIT,
        APP_SHELL_INIT,
        APP_SHELL_INIT_VIEW,
        APP_SHELL_ENTER_VIEW,
        APP_SHELL_STATE_TOTAL
    };

    enum ShellExitCauseEnum
    {
        APP_SHELL_END_KEY_EXIT,
        APP_SHELL_PANEL_SWITCH_EXIT,
        APP_SHELL_SCREEN_EXIT,
        END_OF_APP_SHELL_CAUSE_ENUM
    };

// Signal
public:
    // abort change page signal
    VfxSignal0  m_signalAbort;
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    // hide shortcut bar
    VfxSignal1 <VfxBool> m_signalHideShortCut;
#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */

// Constructor / Destructor
public:
    VappShellPanel(); 

// Method
public:
    virtual void onScreenEnter(VfxBool isBackward);

    virtual void onScreenExit(VfxBool isBackward);

    // init view. application can create components here
    virtual void onInitView();
    
    // deinit view. applicaiton can close components which are created in onInitView stage
    virtual void onDeinitView();
    
    // enter view. Application can create components which waste
    // lots of resources here.
    virtual void onEnterView();
    
    // exit view. Application can release those resources which
    // is obtained in onEnterView
    virtual void onExitView(ShellExitCauseEnum cause);

    virtual void onUpdateView();

    virtual void onSwitchBegin(VfxBool isSwitchOut);

    virtual void onSwitchEnd();

     // This function let application to get applicatin's bounds
    // RETURNS: Application bounds
    VfxRect getAppBounds() const;

    void setAppBounds(VfxRect bounds);

    // This function is used to get shortcut size
    // RETURNS: size
    VfxSize getShortcutSize();
    
    // This function is used to get current panel's lifecycle
    VfxU8 getPanelState();

    // Check whether shortcut bar is hide or not
    VfxBool isShortcutBarHide(); 
    
    // set current Panel order
    void setPanelOrder(VfxU8 idx) { m_scr_order = idx; };

    // get current panel order
    VfxU8 getPanelOrder() { return m_scr_order; };

    // set current panel's identification
    void setPanelId(VfxU8 idx) { m_scr_id = idx; };

    // get current panel's identification
    VfxU8 getPanelId() { return m_scr_id; };

    void setPanelStrId(VfxResId strId) { m_str_id = strId; };
    
    VfxResId getPanelStrId() { return m_str_id; };
    
    void setPanelAlwaysExist(VfxBool always_exist) { m_always_exist = always_exist; };

    VfxBool isPanelAlwaysExist() { return m_always_exist; };

// Method
public:
    // This function hides shortcut bar
    void hideShortcutBar(
        VfxBool isHide          // [IN] VFX_TRUE: hide; VFX_FALSE: unhide
    );
    // This function is used to register default page action
    void regDefaultPageAct(
        VfxControl  *obj        // [IN] registered object pointer address
    ); 
    // This function is used to deregister default page action
    void deregDefaultPageAct(
        VfxControl *obj         // [IN] deregistered object pointer address
    );
    // Check whether the change page action has been register or not
    VfxBool isRegDefaultPageAct(
        VfxObjList &relObjList  // [IN] object list pointer address
    );
    // This function is used to cancel current default page action
    // RETURNS: void
    void cancelDefaultPageAct();
    
// Override
protected:
    // On init. application can do component initalization here. Don't 
    // create components here. In this stage, it is only supposed to
    // do some component initialization, such as send message to other
    // task to gather some data.
    virtual void onInit();

    // On Deinit. application can do component deinitalization here.
    virtual void onDeinit();
    
    // On Pen Input:
    //  We need to receive the pen event. To assure this, we will receive
    //  pen events by default
    // RETURNS: VfxBool
    virtual VfxBool onPenInput(VfxPenEvent &event);
    
// Variable
private:
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    // cube exception list
    VfxObjList m_exp_list;
#endif
    // shell life cycle state
    VfxU8 m_panel_state;
    VfxBool m_always_exist;
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    VfxBool m_is_ScHide;    
#endif
    VfxRect m_app_bounds;
    VfxU8   m_scr_order;
    VfxU8   m_scr_id;
    VfxResId m_str_id;

protected:
    // Is this screen created for small screen redrawing?
    VfxBool m_isRedrawingBkScreens;
    
// Implementation
private:
    // check if this object is in exception page list and doesn't need to apply the
    // default page action
    VfxBool noDefaultPageAction(
        VfxObjList &relObjList    // [IN]  object list
    ) const;

    VfxSize getScreenSize() const;
};
#endif /* __MMI_VUI_SHELL_APP__ */

#endif /* __VAPP_SHELL_PANEL_H__ */
