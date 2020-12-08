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
 *  vapp_shell_multi_page_cp.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file defines the shell component header declaration
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_SHELL_MULTI_PAGE_H__
#define __VAPP_SHELL_MULTI_PAGE_H__

#include "MMI_features.h"

/***************************************************************************** 
 * Include
 *****************************************************************************/

#ifdef __MMI_VUI_SHELL_MULTI_PAGE__

#include "vfx_frame.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_basic_type.h"
#include "vfx_object.h"
#include "vfx_signal.h"
#include "vfx_primitive_frame.h"
#include "vfx_control.h"
#include "vfx_class_info.h"
#include "vfx_text_frame.h"
#include "vcp_content_clone.h"
#include "vfx_input_event.h"
#include "vfx_timer.h"
#include "vfx_transform.h"
#include "vrt_datatype.h"
#include "vfx_object_list.h"
#include "vcp_pluto_control.h"
#include "vcp_app_scr.h"
#include "vcp_wheel_menu.h"
#include "vcp_page_panel.h"
#include "vapp_shell_panel.h"
#include "vapp_shell_panel_cfg.h"
#include "vapp_shell_page_order.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_SHELL_SHORTCUT_HEIGHT (VappShellShortCutPanel::PAGE_SHORTCUT_HEIGHT + VappShellShortCutPanel::PAGE_IND_HEIGHT)

#define VAPP_SHELL_OVERVIEW_CAMERA_NEARPLANE      (350)
#define VAPP_SHELL_FRONTVIEW_CAMERA_NEARPLANE      (240)

#if defined(__MMI_MAINLCD_320X480__)
#define VAPP_SHELL_MULTI_PAGE_CP_SCALE_FACTOR  (1.70212765)
#elif defined(__MMI_MAINLCD_240X400__)
#define VAPP_SHELL_MULTI_PAGE_CP_SCALE_FACTOR  (1.53846153)
#else
#ifdef __MMI_VUI_SHELL_BASE_SLIM__
#define VAPP_SHELL_MULTI_PAGE_CP_SCALE_FACTOR  (2.0)
#else
#define VAPP_SHELL_MULTI_PAGE_CP_SCALE_FACTOR  (1.56862745)
#endif
#endif

#define VAPP_SHELL_BORDER_WIDTH                (9)

#if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__)
#if defined(__MMI_VUI_SHELL_BASE_SLIM__)
#define VAPP_SHELL_FRONTVIEW_CAMERA_DISTANCE       (910)
#else
#define VAPP_SHELL_FRONTVIEW_CAMERA_DISTANCE       (900)
#endif
#define VAPP_SHELL_FRONTVIEW_SEMIMINOR             (505)
#define VAPP_SHELL_FRONTVIEW_SEMIMAJOR             (430)
#define VAPP_SHELL_FRONTVIEW_SHIFT_X               (-135)
#define VAPP_SHELL_FRONTVIEW_ANGLE                 (42)
#define VAPP_SHELL_FRONTVIEW_FOCUSED_ANGLE         (90)
#define VAPP_SHELL_FRONTVIEW_SEC_ANGLE             (1.9)

#define VAPP_SHELL_TEXT_RESERV_Y                  (50)
#define VAPP_SHELL_TEXT_SCALE_RATIO               (1.5)

#if defined(__MMI_MAINLCD_240X320__)
#define VAPP_SHELL_REAL_CELL_WIDTH                 (120.0f)
#define VAPP_SHELL_REAL_CELL_HEIGHT                (122.0f)
#define VAPP_SHELL_SHIFT_X_POS                          (-64)
#define VAPP_SHELL_SHIFT_Y_POS                          (-93)
#else /* defined(__MMI_MAINLCD_240X320__) */
#define VAPP_SHELL_REAL_CELL_WIDTH                 (159.0f)
#define VAPP_SHELL_REAL_CELL_HEIGHT                (210.0f)
#define VAPP_SHELL_SHIFT_X_POS                          (-44)
#define VAPP_SHELL_SHIFT_Y_POS                          (-87)
#endif /* !defined(__MMI_MAINLCD_240X320__) */
#elif defined(__MMI_MAINLCD_320X480__) /* defined(__MMI_MAINLCD_320X480__) */
#define VAPP_SHELL_FRONTVIEW_CAMERA_DISTANCE       (930)
#define VAPP_SHELL_FRONTVIEW_SEMIMINOR             (500)
#define VAPP_SHELL_FRONTVIEW_SEMIMAJOR             (550)
#define VAPP_SHELL_FRONTVIEW_SHIFT_X               (-180)
#define VAPP_SHELL_FRONTVIEW_ANGLE                 (44)
#define VAPP_SHELL_FRONTVIEW_FOCUSED_ANGLE         (90)
#define VAPP_SHELL_FRONTVIEW_SEC_ANGLE             (1.7)

#define VAPP_SHELL_TEXT_RESERV_Y                  (50)
#define VAPP_SHELL_TEXT_SCALE_RATIO               (1.5)

#define VAPP_SHELL_REAL_CELL_WIDTH                 (190.0f)
#define VAPP_SHELL_REAL_CELL_HEIGHT                (239.0f)
#define VAPP_SHELL_SHIFT_X_POS                          (-68)
#define VAPP_SHELL_SHIFT_Y_POS                          (-114)
#else /* defined(__MMI_MAINLCD_320X480__) */
#define VAPP_SHELL_FRONTVIEW_CAMERA_DISTANCE       (900)
#define VAPP_SHELL_FRONTVIEW_SEMIMINOR             (505)
#define VAPP_SHELL_FRONTVIEW_SEMIMAJOR             (430)
#define VAPP_SHELL_FRONTVIEW_SHIFT_X               (-135)
#define VAPP_SHELL_FRONTVIEW_ANGLE                 (42)
#define VAPP_SHELL_FRONTVIEW_FOCUSED_ANGLE         (90)
#define VAPP_SHELL_FRONTVIEW_SEC_ANGLE             (1.9)

#define VAPP_SHELL_TEXT_RESERV_Y                  (50)
#define VAPP_SHELL_TEXT_SCALE_RATIO               (1.5)

#define VAPP_SHELL_REAL_CELL_WIDTH                 (159.0f)
#define VAPP_SHELL_REAL_CELL_HEIGHT                (210.0f)
#define VAPP_SHELL_SHIFT_X_POS                          (-44)
#define VAPP_SHELL_SHIFT_Y_POS                          (-87)
#endif /* !defined(__MMI_MAINLCD_320X480__) */


/***************************************************************************** 
 * Class VappShellShortCutPanel
 *****************************************************************************/
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__

class VappShellShortCutPanel : public VfxFrame
{
public:
    // shell enum
    enum
    {
        PAGE_IND_HEIGHT = 7,
        PAGE_SHORTCUT_HEIGHT = 50,
        END_OF_PUBLIC_ENUM
    };    

private:
    enum
    {
        MAX_SHORTCUT_NUM = 4,
    #ifdef __MMI_MAINLCD_320X480__
        SHORTCUT_FONT_SIZE = 14,
    #else
        SHORTCUT_FONT_SIZE = 13,
    #endif
    #if defined(__MMI_MAINLCD_320X480__)
        TOP_MARGIN = 6,
        BOTTOM_MARGIN = 4,
    #elif defined(__MMI_MAINLCD_240X400__)
        TOP_MARGIN = 5,
        BOTTOM_MARGIN = 3,
    #else /* defined(__MMI_MAINLCD_240X320__) */
        TOP_MARGIN = 4,
        BOTTOM_MARGIN = 2,
    #endif /* defined(__MMI_MAINLCD_240X320__) */
        END_OF_PRIVATE_ENUM
    };    

// Constructor / Destructor
public:
    VappShellShortCutPanel(VfxU8 ind_num);

// Override
protected:
    // On init. application can do component initalization here. Don't 
    // create components here. In this stage, it is only supposed to
    // do some component initialization, such as send message to other
    // task to gather some data.
    virtual void onInit();
    // On Deinit. application can do component deinitalization here.
    virtual void onDeinit();

// Method
public:
    void hide(VfxBool isHidden);
    VfxBool isHide();
    VfxSize getBarSize();
    void displayInd(VfxU8 ind_idx);
    void createIndBar(VfxU8 ind_num);
    void createShortCut();
    void closeShortCut();

// Method
private:
    void adjustIndWidth(VfxU8 ind_idx, VfxS32 *ind_width);
    void onEnterSwitch(VfxObject*, VfxId);
    void onEnterMenu(VfxObject*, VfxId);
    void onEnterDial(VfxObject*, VfxId);
    void onEnterLock(VfxObject*, VfxId);
    VfxSize getScreenSize() const;
    
// Signal
public:
    // enter shell switch mode
    VfxSignal0 m_signalEnterSwitch;
    // enter menu
    VfxSignal0 m_signalEnterMenu;
    // enter dial
    VfxSignal0 m_signalEnterDial;
    // enter keypad lock
    VfxSignal0 m_signalEnterLock;

// Variable
private:
    VfxFrame        *m_ScBgImg;
    VfxBool         m_is_hide;
    // indicator image
    VfxFrame      *m_ind_bg_panel;
    VfxImageFrame *m_ind_bg[VAPP_SHELL_PANEL_TOTAL];
    VfxImageFrame *m_ind;
    VfxU8          m_ind_num;

};

#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */



/***************************************************************************** 
 * Class IVappShellWheelBaseCell
 *****************************************************************************/
class IVappShellWheelBaseCell
{
public:
    // virtual get panel id function
    virtual VfxS8 getCellId() = 0;
};

/***************************************************************************** 
 * Class VappShellWheelCell
 *****************************************************************************/
class VappShellWheelCell :
    public VfxControl,
    public IVappShellWheelBaseCell
{
    VFX_DECLARE_CLASS(VappShellWheelCell);
// Constructor / Destructor
public:
    VappShellWheelCell() {};

    VappShellWheelCell(
        VappShellPanel *cell,
        VfxS8 cell_num 
    );

// Method
public:
    // get cell id
   virtual VfxS8 getCellId();
    // update cell content
   void updateCell();

// Override
protected:
    // initialization function
    virtual void onInit();
    // deinitialization function
    virtual void onDeinit();

// Variable      
private:
    VfxS8          m_cell_num;
    // cell
    VappShellPanel *m_cell;
    // null frame
    VfxImageFrame  *m_img_frame;
    VfxImageFrame  *m_panel_border;

//Implementation
private:
    VfxBool isCellInCurrentTree();
};


/***************************************************************************** 
 * Class VappShellWheelTextCell
 *****************************************************************************/
class VappShellWheelTextCell :
    public VfxTextFrame,
    public IVappShellWheelBaseCell
{
    VFX_DECLARE_CLASS(VappShellWheelTextCell);
private:
    // shell enum
    enum
    {
#if defined(__MMI_MAINLCD_320X480__)
        SHELL_APP_FONT_SIZE               = 30,
#else
        SHELL_APP_FONT_SIZE               = 27,
#endif
        END_OF_ENUM
    };

// Constructor / Destructor
public:
    VappShellWheelTextCell() {};

    VappShellWheelTextCell(
        VfxResId cell_str,
        VfxS8 cell_num 
    );

// Method
public:
    // get cell id
    virtual VfxS8 getCellId();

// Override
protected:
    // initialization function
    virtual void onInit();
    // deinitialization function
    virtual void onDeinit();

// Variable      
private:
    VfxS8          m_cell_num;
    VfxResId       m_cell_str;
};


/***************************************************************************** 
 * Class VappShellWheelReflectCell
 *****************************************************************************/
class VappShellWheelReflectCell :
    public VcpContentClone,
    public IVappShellWheelBaseCell
{
    VFX_DECLARE_CLASS(VappShellWheelReflectCell);
// Constructor / Destructor
public:
    VappShellWheelReflectCell() {};
    VappShellWheelReflectCell(
        VappShellWheelCell *target_item,
        VfxS8 cell_num 
    );

// Method
public:
    // get cell id
    virtual VfxS8 getCellId();

// Override
protected:
    // initialization function
    virtual void onInit();
    // deinitialization function
    virtual void onDeinit();

// Variable      
private:
    VfxS8          m_cell_num;
    VappShellWheelCell *m_target_item;
};


/***************************************************************************** 
 * Class VappShellWheelMenu
 *****************************************************************************/

class VappShellWheelMenu : public VcpWheelMenu
{
private:
    // shell enum
    enum
    {
        SHELL_APP_UPDATE_TIME             = 500,
        SHELL_APP_UPDATE_CONTENT_TIME     = 100,
        SHELL_MAX_CELL_NUM                = 1 << 21,
    #if defined(__MMI_VUI_SHELL_BASE_SLIM__)
        SHELL_MAX_SUB_CELL_COUNT          = 2,
    #else
        SHELL_MAX_SUB_CELL_COUNT          = 3,
    #endif
        SHELL_MAX_AHEAD_CELL_COUNT        = 0,
        SHELL_MAX_BEHIND_CELL_COUNT       = 2,
        SHELL_APP_CELL_START_IDX          = 0,
        SHELL_APP_STATUS_BAR_HEIGHT  = 20,
        END_OF_ENUM
    };

    struct MyWheelMenuUserData
    {
        VfxS32 ori_y;
        VfxS32 width;
        VfxS32 height;
    };

// Constructor / Destructor
public:
    VappShellWheelMenu(
        VfxU8 cur_scr_idx,
        VfxU8 max_panel_num,
        VappShellPanel **shell_panel_list
    );
    virtual ~VappShellWheelMenu(){}

// Signal
public:
    VfxSignal1 <VfxS32>      m_signalSelect;
   
// Override
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxFrame* createCell(VfxS32 cell, VfxS32 subCell);
    virtual void onUpdateCell(VfxS32 cell, VfxS32 subCell, VfxFrame* cellFrame);
    virtual void onCloseCell(VfxS32 cell, VfxS32 subCell, VfxFrame* cellFrame);
    virtual void onFocusIndexChange(VfxS32 focusItem, VfxS32 previousFocusItem);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual void onDragStart();
    virtual void onDragEnd(VfxS32 xspeed, VfxS32 yspeed);
    virtual void onDrag(VfxS32 xoffset, VfxS32 yoffset);
    virtual void onTap(VfxPoint pt);
    virtual VfxS32 getCount();
    virtual VfxS32 getSubCellCount();
    virtual VfxS32 getBehindCount();
    virtual VfxS32 getAheadCount();
    virtual VcpWheelMenuFrameEffectCBFuncPtr getFrameEffectCB();

// Implementation
private:
   void  onCellSelectFinish(VfxTimer *source);
   void  onCellSelect(VfxS32 cell, VfxS32 subCell);
    void updateCellContent(VfxTimer *source);
    
    void onUpdatePanel(VfxTimer *source);
        
    static void myFrontViewEffectCB(
        VfxS32                              cell,           // [IN] the cell index
        VfxS32                              subCell,        // [IN] the sub cell index
        VfxFloat                            cellRelPos,     // [IN] the cell position
        VfxMatrix4x4                        &totalProject,  // [OUT] total project result
        VfxFloat                            fPos,     // [IN] animating index value
        VfxS32                              focus,    // [IN] the focus balue of the menu
        VfxRect                             viewBounds, // the menu bounds
        void                                *userData, // user data
        VfxU32                              userDataSize  // user data size
        );
    
    static vrt_render_dirty_type_enum myAllInOneViewEffectCB(
        VfxS32                              cell,           // [IN] the cell index
        VfxS32                              subCell,        // [IN] the sub cell index
        VfxFloat                            cellRelPos,     // [IN] the cell position
        vrt_frame_visual_property_struct    *target_frame,
        VfxFloat                            fPos,     
        VfxS32                              focus,
        VfxRect                             viewBounds,
        void                                *userData,
        VfxU32                              userDataSize,
        VcpWheelMenuState state,
        VfxFloat level
        );
    
// Variable
protected: 
    VfxObjList m_cell_list;
    VfxObjList m_text_list;
    VfxObjList m_reflection_list;
    VfxRect m_cell_rect;
    VfxS32  m_count;
    VfxU8   m_cur_scr_idx;
    VfxS8   m_update_num;
    VappShellPanel **m_shell_panel;
    VfxTimer     *m_update_content_timer;
    VfxTimer     *m_update_timer;
    VfxTimer     *m_select_timer;
    VfxTextFrame *m_title_frame;
    VfxFrame *m_movingFrame;
    static VfxFloat s_camera_disc;
    static VfxFloat s_semininor;
    static VfxFloat s_seminajor;
    static VfxFloat s_shift_x;
    static VfxFloat s_angle;
    static VfxFloat s_overview_near_plane;
    static VfxFloat s_focused_angle;
    static VfxFloat s_aaa;
};

#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */

#endif /* __VAPP_SHELL_MULTI_PAGE_H__ */
