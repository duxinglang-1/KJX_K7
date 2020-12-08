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
 *  vapp_cube_scr.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  3D cube screen header
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_CUBE_SCR_H__
#define __VAPP_CUBE_SCR_H__

extern "C"
{
#include "MMI_features.h"
}

#ifdef __MMI_VUI_HOMESCREEN__

/***************************************************************************** 
 * Include
 *****************************************************************************/
 
#include "CubeAppGprot.h"
#include "CubeAppProt.h"
#include "vfx_uc_include.h"
#include "vcp_pluto_control.h"
#include "vcp_include.h"

#include "vcp_app_scr.h"
#include "vcp_cube.h"
#include "vapp_hs_res.h"
#include "HomeScreen\vapp_hs_cp.h"
#include "HomeScreen\vapp_hs_shortcut_panel.h"

#include "vfx_app_cat_scr.h"
#include "vfx_basic_type.h"
#include "vfx_cpp_base.h"
#include "vfx_control.h"
#include "vfx_object.h"
#include "vfx_input_event.h"
#include "vfx_timer.h"
#include "vfx_primitive_frame.h"
#include "vfx_datatype.h"
#include "vfx_object_list.h"
#include "vfx_frame.h"

/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/***************************************************************************** 
 * Class VappCubeScr
 *****************************************************************************/
class VappCubeScr : public VfxAppCatScr
{
// Declaration
private:
    // cube enum
    enum
    {
        DEFAULT_CUBE_EFFECT_TIME    = 500, // cube morphy animation time
    #if defined(__MMI_MAINLCD_240X320__)
        APP_ACTION_X_DISTANCE = 25,        // distance to judge change page
    #elif defined(__MMI_MAINLCD_320X480__)
        APP_ACTION_X_DISTANCE = 28,        // distance to judge change page
    #else
        APP_ACTION_X_DISTANCE = 25,        // distance to judge change page
    #endif
        END_OF_ENUM
    };
    
// Constructor / Destructor
public:
    VappCubeScr(); 

// Method
public:
    // Initalize the cube App Category
    static void initalize();
    // Detinialize the cube App Category
    static void deinitalize();

// Method
public:
    // This function let application to get applicatin's bounds
    // RETURNS: Application bounds
    VfxRect getAppBounds() const;

    // This function is used to fold shortcut and widget bar
    // RETURNS: void
    void foldAll();
    
    // This function checks if both the widget bar is fold or not.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isAllFold();

// Method
protected:
    // This function is to get the shortcut panel instance
    // RETURNS: shortcut panel
    VappHsShortcutPanel *getShortcutPanel();

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
    
    // This function is used to cancel current default page action
    // RETURNS: void
    void cancelDefaultPageAct();
    
// Override
protected:
    // On init
    virtual void onInit();
    // On Deinit
    virtual void onDeinit();
    // On add Child:
    // we overwirte this method to let all inherited child components showing below
    // our common screen components
    virtual void onAddChild(VfxObject *child);
    // On Pen Input:
    //  We need to receive the pen event. To assure this, we will receive
    //  pen events by default
    // RETURNS: VfxBool
    virtual VfxBool onPenInput(VfxPenEvent &event);
    // on Key Input:
    //  If pen down is triggered by right arrow or left arrow,
    //  we will change the page directly to next one or previous one
    // RETURNS: VfxBool
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    // On pre-pen Input:
    //  If pen down and move with the distance > APP_ACTION_X_DISTANCE,
    //  we will judge as change page
    // RETURNS: VfxBool
    virtual VfxBool onPreviewPenInput(VfxPenEvent &event);
    // This function is used to fold all shortcut and widget bar pool
    virtual void onFoldAll();
    // This function is used to check whether the shortcut or widget bar is fold
    virtual VfxBool onCheckFold();
    
// Variable
private:
   // cube morphy timer
   VfxTimer *m_timer;
   // cube old frame
   VfxImageFrame *m_old_cube_frame;
   // cube select action, such as next page or previous page
   VfxS32   m_select_action;
   // do the aciont of changing page or not
   VfxBool  m_do_change_page;
   // enable free mode or not
   VfxBool  m_free_mode;
   // cube exception list
   VfxObjList m_cube_exp_list;
   // shortcut panel
   VappHsShortcutPanel *m_shortcutPanel;   
   // icon bounds
   VfxRect m_icon_bounds;
   
// Variable
protected:
   // application writable background panel
   VfxFrame *m_bgPanel;

   
// Implementation
private:
    // Cube effect expiry handle function
    void onCubeEffectTimerExpir(
        VfxTimer *timer // [IN] timer
    );
    
    // check if this object is in exception page list and doesn't need to apply the
    // default page action
    VfxBool noDefaultPageAction(
        VfxObjList &relObjList    // [IN]  object list
    ) const;

    // entry cube application to display animation
    void entryCubeApp(
        void *data               // [IN] data
    );
    
};

/***************************************************************************** 
 * Class VappCube
 *****************************************************************************/

#ifdef __MMI_VUI_3D_CUBE_APP__

class VappCube : public VfxAppCatScr
{

// Declaration
private:
    // cube application enum
    enum
    {
        SHELL_APP_CUBE_SURFACE_NUM = 4    // surface number
    };

// Constructor / Destructor
public:
    // This function is the constructor for a hello test screen.
    VappCube(
            VfxBool is_small_cube,              // [IN] is small cube or not
            VfxBool is_free_mode,               // [IN] is free mode or not
            VfxBool cube_effect,                // [IN] with animation effect or not
            VfxU8 cur_scr_idx,                  // [IN] current screen index
            mmi_cube_vapp_dir_enum scr_dir      // [IN] screen direction
    );

// Method
public:
    // This function is used to get the history info
    void getHistory(
        VfxBool *small_cube     // [OUT] small cube or not
    );
    // Get current page index
    void getCurrentScrIndex(
        VfxU8 *index            // [OUT] current page index
    );

// Override
protected:
    // on init
    virtual void onInit();
    // on deinit
    virtual void onDeinit();

// Variable      
private:
    // cube instance
    VcpCube *m_cube;
    // pen event instance
    VfxPen *m_penSrv;
    // cube image
    VfxImage *m_cubeImage[SHELL_APP_CUBE_SURFACE_NUM];
    // small cube or not
    VfxBool m_small_cube;
    // free mode or not
    VfxBool m_free_mode;
    // cube animation effect
    VfxBool m_cube_effect;
    // cube current screen index
    VfxU8   m_cur_scr_idx;
    // cube direction
    mmi_cube_vapp_dir_enum m_action;
    
// Implementation
private:
    // this function is used to be called when cube page 
    // is selected by user
    void onCubeFinish(
        VfxS32 index    // [IN] selected cube index
    );
    // this function is used to entry big cube screen
    void entryAppScreen(
        void *data     // [IN] data
    );
    
};

#endif /* __MMI_VUI_3D_CUBE_APP__ */

#endif /* __MMI_VUI_HOMESCREEN__ */
#endif /* __VAPP_CUBE_SCR_H__ */

