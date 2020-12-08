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
 *  vcp_fancy_mode_menu.h
 *
 * Project:
 * --------
 *  Venus UI Component
 *
 * Description:
 * ------------
 *  Venus Fancy Mode Menu Component
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_3D_MAINMENU_FANCY__

#ifndef __VCP_FANCY_MODE_MENU_H__
#define __VCP_FANCY_MODE_MENU_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_wheel_menu.h"
// TODO: may remove it 
#include "vcp_normal_mode_menu.h"
#include "vfx_object.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_cpp_base.h"
#include "vfx_frame.h"
#include "vfx_signal.h"
#include "vfx_text_frame.h"
#include "vfx_animation.h"
#include "vfx_transform.h"
#include "vfx_basic_type.h"
#include "vfx_input_event.h"
#include "vrt_datatype.h"
#include "vfx_timer.h"
#include "vfx_control.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

// Please refer the 3D_MM_Fancy_mode_customize_guide_lien to know How to 
// adjust these parameters
#if defined(__MMI_MAINLCD_320X480__)
 
#define VCP_TORNADO_MENU_CAMERA_DISTANCE                    (502)
#define VCP_TORNADO_MENU_NEAR_PLANE                         (340)
#define VCP_TORNADO_MENU_Y_SHIFT                            (-55)
#define VCP_TORNADO_MENU_ANGLE                              (45) 
#define VCP_TORNADO_MENU_FROM_RADIUS                        (202)
#define VCP_TORNADO_MENU_TO_RADIUS                          (50)
#define VCP_TORNADO_MENU_Y_GAP                            (97)
#define VCP_TORNADO_MENU_AHEAD_COUNT                        (9) 
#define VCP_TORNADO_MENU_BEHIND_COUNT                       (24)
#define VCP_TORNADO_MENU_CELL_COUNT_IN_CIRCLE          (360/VCP_TORNADO_MENU_ANGLE) 
#define VCP_TORNADO_MENU_TEXT_COUNT                         (5) 


#define VCP_SPACE_BEAM_MENU_CAMERA_DISTANCE       (600)
#define VCP_SPACE_BEAM_MENU_NEAR_PLANE            (600)
#define VCP_SPACE_BEAM_MENU_Y_SHIFT               (-220)
#define VCP_SPACE_BEAM_MENU_GAP              (11)
#define VCP_SPACE_BEAM_MENU_Z_GAP            (180) 
#define VCP_SPACE_BEAM_MENU_CAMERA_UP        (300)
#define VCP_SPACE_BEAM_MENU_AHEAD_COUNT      (0)
#define VCP_SPACE_BEAM_MENU_BEHIND_COUNT      (6)
#define VCP_SPACE_BEAM_MENU_CELL_COUNT_IN_ROW  (4)
#define VCP_SPACE_BEAM_MENU_TEXT_COUNT            (VCP_SPACE_BEAM_MENU_CELL_COUNT_IN_ROW)


#define VCP_FANCY_MODE_CELL_WIDTH            (65) 
#define VCP_FANCY_MODE_CELL_HEIGHT           (65)

#define VCP_FANCY_MODE_TRANSITION_CELL_COUNT           (16) 
#define VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW    (4) 
#define VCP_FANCY_MODE_TRANSITION_CELL_ROW_COUNT       (4) 
#define VCP_FANCY_MODE_TRANSITION_CELL_X_START         (14) 
#define VCP_FANCY_MODE_TRANSITION_CELL_Y_START         (11) 
#define VCP_FANCY_MODE_TRANSITION_CELL_TEXT_X_START    (10) 
#define VCP_FANCY_MODE_TRANSITION_CELL_TEXT_Y_START    (82)
#define VCP_FANCY_MODE_TRANSITION_CELL_TEXT_SIZE       (13)
#define VCP_FANCY_MODE_TRANSITION_CELL_TEXT_WIDTH      (73)
#define VCP_FANCY_MODE_TRANSITION_CELL_TEXT_HEIGHT     (16)
#define VCP_FANCY_MODE_TRANSITION_CELL_X_GAP           (76) 
#define VCP_FANCY_MODE_TRANSITION_CELL_Y_GAP           (92) 
#define VCP_FANCY_MODE_TRANSITION_TORNADO_VANISH_POINT_X (130)
#define VCP_FANCY_MODE_TRANSITION_TORNADO_VANISH_POINT_Y (500)
#define VCP_FANCY_MODE_TRANSITION_TORNADO_VANISH_POINT_SCALE (0.75f)
#define VCP_FANCY_MODE_TRANSITION_SPACE_BEAM_VANISH_POINT_X (140)
#define VCP_FANCY_MODE_TRANSITION_SPACE_BEAM_VANISH_POINT_Y (80)
#define VCP_FANCY_MODE_TRANSITION_SPACE_BEAM_VANISH_POINT_SCALE (0.36f)

#elif defined(__MMI_MAINLCD_240X320__)


#define VCP_TORNADO_MENU_CAMERA_DISTANCE                    (502)
#define VCP_TORNADO_MENU_NEAR_PLANE                         (340)
#define VCP_TORNADO_MENU_Y_SHIFT                            (-23)
#define VCP_TORNADO_MENU_ANGLE                              (45) 
#define VCP_TORNADO_MENU_FROM_RADIUS                        (136)
#define VCP_TORNADO_MENU_TO_RADIUS                          (50)
#define VCP_TORNADO_MENU_Y_GAP                              (79)
#define VCP_TORNADO_MENU_AHEAD_COUNT                        (9) 
#define VCP_TORNADO_MENU_BEHIND_COUNT                       (16)
#define VCP_TORNADO_MENU_CELL_COUNT_IN_CIRCLE          (360/VCP_TORNADO_MENU_ANGLE) 
#define VCP_TORNADO_MENU_TEXT_COUNT                         (4)


#define VCP_SPACE_BEAM_MENU_CAMERA_DISTANCE       (600)
#define VCP_SPACE_BEAM_MENU_NEAR_PLANE            (600)
#define VCP_SPACE_BEAM_MENU_Y_SHIFT               (-220)
#define VCP_SPACE_BEAM_MENU_GAP              (18)
#define VCP_SPACE_BEAM_MENU_Z_GAP            (180) 
#define VCP_SPACE_BEAM_MENU_CAMERA_UP        (300)
#define VCP_SPACE_BEAM_MENU_AHEAD_COUNT      (0)
#define VCP_SPACE_BEAM_MENU_BEHIND_COUNT      (5)
#define VCP_SPACE_BEAM_MENU_CELL_COUNT_IN_ROW  (3)
#define VCP_SPACE_BEAM_MENU_TEXT_COUNT            (VCP_SPACE_BEAM_MENU_CELL_COUNT_IN_ROW)

#define VCP_FANCY_MODE_CELL_WIDTH            (52) 
#define VCP_FANCY_MODE_CELL_HEIGHT           (52)

#define VCP_FANCY_MODE_TRANSITION_CELL_COUNT           (9) 
#define VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW    (3) 
#define VCP_FANCY_MODE_TRANSITION_CELL_ROW_COUNT       (3) 
#define VCP_FANCY_MODE_TRANSITION_CELL_X_START         (24) 
#define VCP_FANCY_MODE_TRANSITION_CELL_Y_START         (6) 
#define VCP_FANCY_MODE_TRANSITION_CELL_TEXT_X_START    (15+1) 
#define VCP_FANCY_MODE_TRANSITION_CELL_TEXT_Y_START    (6+52+4)
#define VCP_FANCY_MODE_TRANSITION_CELL_TEXT_SIZE       (13)
#define VCP_FANCY_MODE_TRANSITION_CELL_TEXT_WIDTH      (60)
#define VCP_FANCY_MODE_TRANSITION_CELL_TEXT_HEIGHT     (20)
#define VCP_FANCY_MODE_TRANSITION_CELL_X_GAP           (70) 
#define VCP_FANCY_MODE_TRANSITION_CELL_Y_GAP           (77) 
#define VCP_FANCY_MODE_TRANSITION_TORNADO_VANISH_POINT_X (100)
#define VCP_FANCY_MODE_TRANSITION_TORNADO_VANISH_POINT_Y (360)
#define VCP_FANCY_MODE_TRANSITION_TORNADO_VANISH_POINT_SCALE (0.75f)
#define VCP_FANCY_MODE_TRANSITION_SPACE_BEAM_VANISH_POINT_X (110)
#define VCP_FANCY_MODE_TRANSITION_SPACE_BEAM_VANISH_POINT_Y (20)
#define VCP_FANCY_MODE_TRANSITION_SPACE_BEAM_VANISH_POINT_SCALE (0.4f)

#elif defined(__MMI_MAINLCD_240X400__)

#define VCP_TORNADO_MENU_CAMERA_DISTANCE                    (502)
#define VCP_TORNADO_MENU_NEAR_PLANE                         (340)
#if defined(__MMI_FTE_SUPPORT_SLIM__)
#define VCP_TORNADO_MENU_Y_SHIFT                            (0)//(-20)
#else
#define VCP_TORNADO_MENU_Y_SHIFT                            (-55)
#endif
#if defined(__MMI_FTE_SUPPORT_SLIM__)
#define VCP_TORNADO_MENU_ANGLE                              (60)
#else
#define VCP_TORNADO_MENU_ANGLE                              (45)
#endif
#define VCP_TORNADO_MENU_FROM_RADIUS                        (152)
#define VCP_TORNADO_MENU_TO_RADIUS                          (50)
#if defined(__MMI_FTE_SUPPORT_SLIM__)
#define VCP_TORNADO_MENU_Y_GAP                              (160)//(110)
#else
#define VCP_TORNADO_MENU_Y_GAP                              (85)
#endif

#if defined(__MMI_FTE_SUPPORT_SLIM__)
#define VCP_TORNADO_MENU_AHEAD_COUNT                        (7) 
#define VCP_TORNADO_MENU_BEHIND_COUNT                       (6)
#else
#define VCP_TORNADO_MENU_AHEAD_COUNT                        (9) 
#define VCP_TORNADO_MENU_BEHIND_COUNT                       (24)
#endif
#define VCP_TORNADO_MENU_CELL_COUNT_IN_CIRCLE          (360/VCP_TORNADO_MENU_ANGLE) 
#define VCP_TORNADO_MENU_TEXT_COUNT                         (5)


#define VCP_SPACE_BEAM_MENU_CAMERA_DISTANCE       (600)
#define VCP_SPACE_BEAM_MENU_NEAR_PLANE            (700)
#define VCP_SPACE_BEAM_MENU_Y_SHIFT               (-250)
#define VCP_SPACE_BEAM_MENU_GAP              (18)
#define VCP_SPACE_BEAM_MENU_Z_GAP            (180) 
#define VCP_SPACE_BEAM_MENU_CAMERA_UP        (300)
#define VCP_SPACE_BEAM_MENU_AHEAD_COUNT      (0)
#if defined(__MMI_FTE_SUPPORT_SLIM__)
#define VCP_SPACE_BEAM_MENU_BEHIND_COUNT      (3)
#else
#define VCP_SPACE_BEAM_MENU_BEHIND_COUNT      (6)
#endif
#define VCP_SPACE_BEAM_MENU_CELL_COUNT_IN_ROW  (3)
#define VCP_SPACE_BEAM_MENU_TEXT_COUNT            (VCP_SPACE_BEAM_MENU_CELL_COUNT_IN_ROW)

#define VCP_FANCY_MODE_CELL_WIDTH            (52)
#define VCP_FANCY_MODE_CELL_HEIGHT           (52)

#define VCP_FANCY_MODE_TRANSITION_CELL_COUNT           (12) 
#define VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW    (3) 
#define VCP_FANCY_MODE_TRANSITION_CELL_ROW_COUNT       (4) 
#define VCP_FANCY_MODE_TRANSITION_CELL_X_START         (24) 
#define VCP_FANCY_MODE_TRANSITION_CELL_Y_START         (6) 
#define VCP_FANCY_MODE_TRANSITION_CELL_TEXT_X_START    (15+1) 
#define VCP_FANCY_MODE_TRANSITION_CELL_TEXT_Y_START    (6+52+4)
#define VCP_FANCY_MODE_TRANSITION_CELL_TEXT_SIZE       (13)
#define VCP_FANCY_MODE_TRANSITION_CELL_TEXT_WIDTH      (60)
#define VCP_FANCY_MODE_TRANSITION_CELL_TEXT_HEIGHT     (20)
#define VCP_FANCY_MODE_TRANSITION_CELL_X_GAP           (70) 
#define VCP_FANCY_MODE_TRANSITION_CELL_Y_GAP           (80) 
#define VCP_FANCY_MODE_TRANSITION_TORNADO_VANISH_POINT_X (101)
#define VCP_FANCY_MODE_TRANSITION_TORNADO_VANISH_POINT_Y (460)
#define VCP_FANCY_MODE_TRANSITION_TORNADO_VANISH_POINT_SCALE (0.75f)
#define VCP_FANCY_MODE_TRANSITION_SPACE_BEAM_VANISH_POINT_X (109)
#define VCP_FANCY_MODE_TRANSITION_SPACE_BEAM_VANISH_POINT_Y (35)
#define VCP_FANCY_MODE_TRANSITION_SPACE_BEAM_VANISH_POINT_SCALE (0.42f)

#else
 
#define VCP_TORNADO_MENU_CAMERA_DISTANCE                    (502)
#define VCP_TORNADO_MENU_NEAR_PLANE                         (340)
#define VCP_TORNADO_MENU_Y_SHIFT                            (-55)
#define VCP_TORNADO_MENU_ANGLE                              (45) 
#define VCP_TORNADO_MENU_FROM_RADIUS                        (202)
#define VCP_TORNADO_MENU_TO_RADIUS                          (50)
#define VCP_TORNADO_MENU_Y_GAP                            (97)
#define VCP_TORNADO_MENU_AHEAD_COUNT                        (9) 
#define VCP_TORNADO_MENU_BEHIND_COUNT                       (24)
#define VCP_TORNADO_MENU_CELL_COUNT_IN_CIRCLE          (360/VCP_TORNADO_MENU_ANGLE) 
#define VCP_TORNADO_MENU_TEXT_COUNT                         (4)
#define VCP_SPACE_BEAM_MENU_TEXT_COUNT            (VCP_SPACE_BEAM_MENU_CELL_COUNT_IN_ROW)


#define VCP_SPACE_BEAM_MENU_CAMERA_DISTANCE       (600)
#define VCP_SPACE_BEAM_MENU_NEAR_PLANE            (600)
#define VCP_SPACE_BEAM_MENU_Y_SHIFT               (-220)
#define VCP_SPACE_BEAM_MENU_GAP              (11)
#define VCP_SPACE_BEAM_MENU_Z_GAP            (180) 
#define VCP_SPACE_BEAM_MENU_CAMERA_UP        (300)
#define VCP_SPACE_BEAM_MENU_AHEAD_COUNT      (0)
#define VCP_SPACE_BEAM_MENU_BEHIND_COUNT      (6)
#define VCP_SPACE_BEAM_MENU_CELL_COUNT_IN_ROW  (4)

#define VCP_FANCY_MODE_CELL_WIDTH            (65) 
#define VCP_FANCY_MODE_CELL_HEIGHT           (65)

#define VCP_FANCY_MODE_TRANSITION_CELL_COUNT           (16) 
#define VCP_FANCY_MODE_TRANSITION_CELL_COUNT_IN_ROW    (4) 
#define VCP_FANCY_MODE_TRANSITION_CELL_ROW_COUNT       (4) 
#define VCP_FANCY_MODE_TRANSITION_CELL_X_START         (14) 
#define VCP_FANCY_MODE_TRANSITION_CELL_Y_START         (11) 
#define VCP_FANCY_MODE_TRANSITION_CELL_TEXT_X_START    (10) 
#define VCP_FANCY_MODE_TRANSITION_CELL_TEXT_Y_START    (82) 
#define VCP_FANCY_MODE_TRANSITION_CELL_TEXT_SIZE       (13)
#define VCP_FANCY_MODE_TRANSITION_CELL_TEXT_WIDTH      (73)
#define VCP_FANCY_MODE_TRANSITION_CELL_TEXT_HEIGHT     (16)
#define VCP_FANCY_MODE_TRANSITION_CELL_X_GAP           (76) 
#define VCP_FANCY_MODE_TRANSITION_CELL_Y_GAP           (92) 
#define VCP_FANCY_MODE_TRANSITION_TORNADO_VANISH_POINT_X (130)
#define VCP_FANCY_MODE_TRANSITION_TORNADO_VANISH_POINT_Y (500)
#define VCP_FANCY_MODE_TRANSITION_TORNADO_VANISH_POINT_SCALE (0.75f)
#define VCP_FANCY_MODE_TRANSITION_SPACE_BEAM_VANISH_POINT_X (140)
#define VCP_FANCY_MODE_TRANSITION_SPACE_BEAM_VANISH_POINT_Y (80)
#define VCP_FANCY_MODE_TRANSITION_SPACE_BEAM_VANISH_POINT_SCALE (0.36f)

#endif

// If you make a new style of fancy mode, add your enum here. 
enum VcpFancyModeMenuType
{
    VCP_FANCY_MODE_MENU_NULL,
    VCP_FANCY_MODE_MENU_TORNADO,
    VCP_FANCY_MODE_MENU_SPACE_BEAM,
    VCP_FANCY_MODE_MENU_END
};

// This is the data manager mode.
// None means when meet space in normal mode, it will discard it.
// ROW means when meet space in normal mode, it will preserve a row space.
// ex. if a row only has 2 items, it will add two blank item after that if a row contain 4 items.
// Page means when meet space in normal mode, it will preserve a page space.
// ex. if a page only has 10 items, it will add 6 blank item after that if a page contain 16 items.
enum VcpFancyModeDataMgrBlankMode
{
    VCP_FANCY_MODE_DATA_MGR_NONE,
    VCP_FANCY_MODE_DATA_MGR_ROW,
    VCP_FANCY_MODE_DATA_MGR_PAGE,
    VCP_FANCY_MODE_DATA_MGR_END
};

/*****************************************************************************
 * Class VcpFancyModeDataMgr
 *****************************************************************************/
/*
 *  VcpFancyModeDataMgr take response for the arrange data used in fancy mode menu.
 *  It will get icon and text of normal mode and transfer to the data that fancy
 *  mode menu used. The data can have blank items or not define in 
 *  VcpFancyModeDataMgrBlankMode. for example, transition may need VCP_FANCY_MODE_DATA_MGR_PAGE
 *  data, but Tornado may need VCP_FANCY_MODE_DATA_MGR_NONE.
 */
class VcpFancyModeDataMgr : public VfxObject
{
// Constructor / Destructor
public:
    // <group DOM_FancyModeMenu_VcpFancyModeDataMgr_Constructor/Destructor>
    VcpFancyModeDataMgr();

// Override
protected:
    // <group DOM_FancyModeMenu_VcpFancyModeDataMgr_Override>
    virtual void onInit();
    // <group DOM_FancyModeMenu_VcpFancyModeDataMgr_Override>
    virtual void onDeinit();

// Method
public:
    // <group DOM_FancyModeMenu_VcpFancyModeDataMgr_Method>
    // Tell VcpFancyModeDataMgr how all app data and count
    void setAllAppData(
        AppEntry appEntry[],        // [IN] app data
        VfxS32 count                // [IN] app count
        );
    // <group DOM_FancyModeMenu_VcpFancyModeDataMgr_Method>
    // Tell VcpFancyModeDataMgr how the order of app and count
    void setAppOrderData(
        VfxS32 appOrder[],          // [IN] app order
        VfxS32 count                // [IN] order count
        );
    // <group DOM_FancyModeMenu_VcpFancyModeDataMgr_Method>
    // Tell VcpFancyModeDataMgr which blank mode should used
    void setBlankMode(
        VcpFancyModeDataMgrBlankMode value  // [IN] blank mode
        )
    {
        m_blankMode = value;
    }
    // <group DOM_FancyModeMenu_VcpFancyModeDataMgr_Method>
    // Set max page count
    void setPageCount(
        VfxS32 pageCount            // [IN] page count
        )
    {
        m_pageCount = pageCount;
    }    
    // <group DOM_FancyModeMenu_VcpFancyModeDataMgr_Method>
    // Get the icon image by index
    VfxResId getIconId(
        VfxS32 index                // [IN] order index
        );
    // <group DOM_FancyModeMenu_VcpFancyModeDataMgr_Method>
    // Get the title string by index
    VfxWString getTitle(
        VfxS32 index                // [IN] order index
        );
    // <group DOM_FancyModeMenu_VcpFancyModeDataMgr_Method>
    // Get original index by order index
    VfxS32 getIndex(
        VfxS32 index                // [IN] order index
        );
    // <group DOM_FancyModeMenu_VcpFancyModeDataMgr_Method>
    // Get the blank mode
    VcpFancyModeDataMgrBlankMode getBlankMode()
    {
        return m_blankMode;
    }
    // <group DOM_FancyModeMenu_VcpFancyModeDataMgr_Method>
    // Get the max page count
    VfxS32 getPageCount()
    {
        return m_pageCount;
    }
    // <group DOM_FancyModeMenu_VcpFancyModeDataMgr_Method>
    // Get the total App count;
    VfxS32 getTotalCount()
    {
        return m_mappingTableCount;
    }
    // <group DOM_FancyModeMenu_VcpFancyModeDataMgr_Method>
    // Get app index disregarding to blank item.
    VfxS32 getFocusedIndex(
        VfxS32 screenIndex    // index disregarding to blank item
        );

// Implementation
private:
    // <group DOM_FancyModeMenu_VcpFancyModeDataMgr_Implementation>
    void makeMappingTable();

// Variable
private:
    // <group DOM_FancyModeMenu_VcpFancyModeDataMgr_Variable>
    AppEntry * m_allAppData;
    // <group DOM_FancyModeMenu_VcpFancyModeDataMgr_Variable>
    VfxS32 m_allAppCount;
    // <group DOM_FancyModeMenu_VcpFancyModeDataMgr_Variable>
    VfxS32 *m_appOrderData;
    // <group DOM_FancyModeMenu_VcpFancyModeDataMgr_Variable>
    VfxS32 m_appOrderCount;
    // <group DOM_FancyModeMenu_VcpFancyModeDataMgr_Variable>
    VfxBool m_ready1;
    // <group DOM_FancyModeMenu_VcpFancyModeDataMgr_Variable>
    VfxBool m_ready2;
    // <group DOM_FancyModeMenu_VcpFancyModeDataMgr_Variable>
    VfxS32 *m_mappingTable;
    // <group DOM_FancyModeMenu_VcpFancyModeDataMgr_Variable>
    VfxS32 m_mappingTableCount;
    // <group DOM_FancyModeMenu_VcpFancyModeDataMgr_Variable>
    VcpFancyModeDataMgrBlankMode m_blankMode;
    // <group DOM_FancyModeMenu_VcpFancyModeDataMgr_Variable>
    VfxS32  m_pageCount;
};


/***************************************************************************** 
 * Class VcpFancyModeMenuTransition
 *****************************************************************************/
/*
 *  VcpFancyModeMenuTransition take response for transition between normal mode and
 *  fancy mode. Because use wheel menu structure to do transition between normal
 *  mode to fancy mode is very diffcult and unnecessary (Transition does not need
 *  3D information). So we delegate VcpFancyModeMenuTransition to do this job.
 *  VcpFancyModeMenuTransition do the job let normal mode disappear, then fancy mode
 *  menu (tornado or space beam) to their enter transition. When leaving fancy mode,
 *  the fancy mode menu (tornado or space beam) to their leave transition, then 
 *  VcpFancyModeMenuTransition do the enter transition to the normal mode.
 */
class VcpFancyModeMenuTransition : public VfxFrame
{
// Constructor / Destructor
public:
    // <group DOM_FancyModeMenu_VcpFancyModeMenuTransition_Constructor/Destructor>
    VcpFancyModeMenuTransition();

// Override
protected:
    // <group DOM_FancyModeMenu_VcpFancyModeMenuTransition_Override>
    virtual void onInit();

// Method
public:
    // <group DOM_FancyModeMenu_VcpFancyModeMenuTransition_Method>
    // Set the data manager.
    void setDataMgr(
        VcpFancyModeDataMgr  *dataMgr   // [IN] data manager
        )
    {
        m_dataMgr = dataMgr;
    }
    // <group DOM_FancyModeMenu_VcpFancyModeMenuTransition_Method>
    // Set the Focus Index. The focus index means the leading app inde of this page.
    void setFocusIndex(
        VfxS32 index               // [IN] The focus item
    )
    {
        m_focus = index;
    }
    // <group DOM_FancyModeMenu_VcpFancyModeMenuTransition_Method>
    // switch to tornado mode
    void switchToTornado(
        VfxBool isReverse         // [IN] enter or leave
        );
    // <group DOM_FancyModeMenu_VcpFancyModeMenuTransition_Method>
    // switch to space beam mode
    void switchToSpaceBeam(
        VfxBool isReverse         // [IN] enter or leave
        );
    
// Signal
public:
    // <group DOM_FancyModeMenu_VcpFancyModeMenuTransition_Signal>
    // notify when transition finished 
    VfxSignal0  m_signalTransitionFinished;

// Variable
protected:
    // <group DOM_FancyModeMenu_VcpFancyModeMenuTransition_Variable>
    VcpFancyModeDataMgr  *m_dataMgr;
    // <group DOM_FancyModeMenu_VcpFancyModeMenuTransition_Variable>
    VfxS32 m_focus;
    // <group DOM_FancyModeMenu_VcpFancyModeMenuTransition_Variable>
    VfxFrame *m_menuIcon[VCP_FANCY_MODE_TRANSITION_CELL_COUNT];
    // <group DOM_FancyModeMenu_VcpFancyModeMenuTransition_Variable>
    VfxTextFrame *m_menuText[VCP_FANCY_MODE_TRANSITION_CELL_COUNT];
    // <group DOM_FancyModeMenu_VcpFancyModeMenuTransition_Variable>
    VfxPointTimeline *m_menuItemTimeline[VCP_FANCY_MODE_TRANSITION_CELL_COUNT];
    // <group DOM_FancyModeMenu_VcpFancyModeMenuTransition_Variable>
    VfxPointTimeline *m_menuItemTimeline2[VCP_FANCY_MODE_TRANSITION_CELL_COUNT];
    // <group DOM_FancyModeMenu_VcpFancyModeMenuTransition_Variable>
    VfxFloatTimeline *m_menuItemAlphaTimeline[VCP_FANCY_MODE_TRANSITION_CELL_COUNT];
    // <group DOM_FancyModeMenu_VcpFancyModeMenuTransition_Variable>
    VfxTransformTimeline *m_menuItemScaleTimeline[VCP_FANCY_MODE_TRANSITION_CELL_COUNT];
    // <group DOM_FancyModeMenu_VcpFancyModeMenuTransition_Variable>
    VfxFloatTimeline *m_menuItemOpacityTimeline[VCP_FANCY_MODE_TRANSITION_CELL_COUNT];
    // <group DOM_FancyModeMenu_VcpFancyModeMenuTransition_Variable>
    VfxBool m_isReverse;

// Implementation
private:
    // <group DOM_FancyModeMenu_VcpFancyModeMenuTransition_Implementation>
    void onEndOfItemTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted);
    // <group DOM_FancyModeMenu_VcpFancyModeMenuTransition_Implementation>
    void VcpFancyModeMenuTransition::onEndOfItemTextTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted);
};

/***************************************************************************** 
 * Class VcpTornadoMenu
 *****************************************************************************/
/*
 *  VcpTornadoMenu provide a tornado like UI.
 */
class VcpTornadoMenu : public VcpWheelMenu
{
// Constructor / Destructor
public:
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Constructor/Destructor>
    VcpTornadoMenu();

// structure  
struct VcpTwistMenuUserData
{
    VfxBool isOpacity;
    VfxMatrix4x4 camera;
};

// Override
public:
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Override>
    virtual void setBounds(const VfxRect &value);

// Override
protected:
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Override>
    virtual void onInit();
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Override>
    virtual VfxFrame* createCell(VfxS32 cell, VfxS32 subcell);
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Override>
    virtual void onUpdateCell(VfxS32 cell, VfxS32 subcell, VfxFrame* frame){};
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Override>
    virtual void onCloseCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame);
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Override>
    virtual void onFocusIndexChange(VfxS32 focusItem, VfxS32 previousFocusItem);
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Override>
    virtual void onDragEnd(VfxS32 xspeed, VfxS32 yspeed);
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Override>
    virtual void onDrag(VfxS32 xoffset, VfxS32 yoffset);
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Override>
    virtual void onTap(VfxPoint pt);
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Override>
    virtual VfxBool onPenInput(VfxPenEvent & event);
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Override>
    virtual VfxS32 getCount()
    {
        return m_count;
    }
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Override>
    virtual VfxS32 getBehindCount()
    {
        return m_count;
    }
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Override>
    virtual VfxS32 getAheadCount()
    {
        return m_count;
    }
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Override>
    virtual VfxS32 getSubCellCount()
    {
        return m_subCount; 
    }
    
    static vrt_render_dirty_type_enum myFrameEffectCB(
        VfxS32                              cell,           // [IN] the cell index
        VfxS32                              subCell,        // [IN] the sub cell index
        VfxFloat                            cellRelPos,     // [IN] the cell position
        vrt_frame_visual_property_struct    *target_frame,  // [IN] the cell frame
        VfxFloat                            fPos,           // [IN] animating index value
        VfxS32                              focus,          // the focus value of the menu
        VfxRect                             viewBounds,     // the menu bounds
        void                                *userData,      // user data
        VfxU32                              userDataSize,   // user data size
        VcpWheelMenuState                   state,          // [IN] the state of Menu
        VfxFloat                            level           // [IN] the level of state
    );
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Override>
    virtual VcpWheelMenuFrameEffectCBFuncPtr getFrameEffectCB()
    {
        return &VcpTornadoMenu::myFrameEffectCB;
    }
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Override>
    virtual void onStateChangeFinished(VcpWheelMenuState finishedState);
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Override>
    virtual VfxTimingFuncIdEnum getMoveTimeFunction()
    {
        return VFX_TIMING_FUNC_ID_EASE_OUT;
    }

// Method
public:
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Method>
    // Set the total count
    void setCount(
        VfxS32 count        // [IN] total count
        )
    {
        m_count = count;
        update();
    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Method>
    // Enter tornado menu
    void enter();
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Method>
    // Leave tornado menu
    void leave();
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Method>
    // Set data manager
    void setDataMgr(
        VcpFancyModeDataMgr  *dataMgr       // [IN] data manager
        )
    {
        m_dataMgr = dataMgr;
    }
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Method>
    // Set all text visible or not
    void setTextVisible(
        VfxBool value                       // [IN] visible or not
        );
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Method>
    // set all cell quality. We set quality low when moving,
    // and set Quality high when stable.
    void setAllCellQuality(
        VfxRenderQualityEnum value          // [IN] quality
        );

// Signal
public:
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Signal>
    // when user tap the focused cell, m_signalSelected will emit.
    VfxSignal2 <VfxObject *, VfxS32> m_signalSelected;
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Signal>
    // notify when enter transition is finished
    VfxSignal0 m_signalEnterFinished;

// Variable
private:
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Variable>
    VfxS32  m_count;
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Variable>
    VfxS32  m_subCount;
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Variable>
    VfxBool m_cellOpaque;
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Variable>
    VfxBool m_cellTextOn;
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Variable>
    VfxBool m_cellOpacity;
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Variable>
    VcpFancyModeDataMgr  *m_dataMgr;
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Variable>
    VfxMatrix4x4 m_camera;
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Variable>
    VfxFrame *m_clickBg;
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Variable>
    VfxTransform m_clickBgTransform;
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Variable>
    VfxBool  m_isSwipe;
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Variable>
    VfxTextFrame *m_text[5];
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Variable>
    VfxTimer *m_qualityTimer;
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Variable>
    VfxBool m_textVisible;

// Implementation
private:
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Implementation>
    VfxBool hitTestonCell(VfxPoint pt, VfxS32 cell, VfxS32 subCell);
    // <group DOM_FancyModeMenu_VcpTornadoMenu_Implementation>
    void onQualityTimerStop(VfxTimer *source);

};

/***************************************************************************** 
 * Class VcpSpaceBeamMenu
 *****************************************************************************/

/*
 *  VcpSpaceBeamMenu provide a space beam like UI.
 */

class VcpSpaceBeamMenu : public VcpWheelMenu
{
// Constructor / Destructor
public:
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Constructor/Destructor>
    VcpSpaceBeamMenu();

// structure  
struct VcpSpaceBeamMenuUserData
{
    VfxBool isOpacity;
    VfxMatrix4x4 camera;
    VfxS32  rowCount;
};

// Override
public:
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Override>
    virtual void setBounds(const VfxRect &value);
// Override 
protected:
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Override>
    virtual void onInit();
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Override>
    virtual VfxFrame* createCell(VfxS32 cell, VfxS32 subcell);
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Override>
    virtual void onUpdateCell(VfxS32 cell, VfxS32 subcell, VfxFrame* frame){};
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Override>
    virtual void onCloseCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame);
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Override>
    virtual void onFocusIndexChange(VfxS32 focusItem, VfxS32 previousFocusItem);
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Override>
    virtual void onDragEnd(VfxS32 xspeed, VfxS32 yspeed);
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Override>
    virtual void onDrag(VfxS32 xoffset, VfxS32 yoffset);
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Override>
    virtual void onTap(VfxPoint pt);
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Override>
    virtual VfxBool onPenInput(VfxPenEvent & event);
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Override>
    virtual VfxS32 getCount()
    {
        return m_count;
    }
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Override>
    virtual VfxS32 getBehindCount()
    {
        //return VCP_SPACE_BEAM_MENU_BEHIND_COUNT;
        return m_count;
    }
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Override>
    virtual VfxS32 getAheadCount()
    {
        //return VCP_SPACE_BEAM_MENU_AHEAD_COUNT;
        return m_count;
    }
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Override>
    virtual VfxS32 getSubCellCount()
    {
        return m_subCount; 
    }

    static vrt_render_dirty_type_enum myFrameEffectCB(
        VfxS32                              cell,           // [IN] the cell index
        VfxS32                              subCell,        // [IN] the sub cell index
        VfxFloat                            cellRelPos,     // [IN] the cell position
        vrt_frame_visual_property_struct    *target_frame,  // [IN] the cell frame
        VfxFloat                            fPos,           // [IN] animating index value
        VfxS32                              focus,          // the focus value of the menu
        VfxRect                             viewBounds,     // the menu bounds
        void                                *userData,      // user data
        VfxU32                              userDataSize,   // user data size
        VcpWheelMenuState                   state,          // [IN] the state of Menu
        VfxFloat                            level           // [IN] the level of state
    );
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Override>
    virtual VcpWheelMenuFrameEffectCBFuncPtr getFrameEffectCB()
    {
        return &VcpSpaceBeamMenu::myFrameEffectCB;
    }
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Override>
    virtual void onStateChangeFinished(VcpWheelMenuState finishedState);
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Override>
    virtual VfxTimingFuncIdEnum getMoveTimeFunction()
    {
        return VFX_TIMING_FUNC_ID_EASE_OUT;
    }

// Method
public:
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Method>
    // Set the total count
    void setCount(VfxS32 count)
    {
        m_count = count;                    // [IN] total count
        update();
    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Method>
    // Set the count of Row
    void setCountOfRow(
        VfxS32 count                        // [IN] count of row
        )
    {
        setCount(count/VCP_SPACE_BEAM_MENU_CELL_COUNT_IN_ROW + (count%VCP_SPACE_BEAM_MENU_CELL_COUNT_IN_ROW > 0 ? 1 : 0));
    }
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Method>
    // Set focus index
    void setFocusIndex(
        VfxS32 index,                       // [IN] The focus item
        VfxMsec animTime = -1               // [IN] The animation time, 0 means no need animation. -1 means use default value.
    )
    {
        setFocus(index/VCP_SPACE_BEAM_MENU_CELL_COUNT_IN_ROW, animTime);
    }
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Method>
    // Enter space beam menu
    void enter();
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Method>
    // Leave space beam menu
    void leave();
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Method>
    // Set data manager
    void setDataMgr(
        VcpFancyModeDataMgr  *dataMgr       // [IN] data manager
        )
    {
        m_dataMgr = dataMgr;
    }
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Method>
    // Set all text visible or not
    void setTextVisible(
        VfxBool value                       // [IN] visible or not
        );
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Method>
    // set all cell quality. We set quality low when moving,
    // and set Quality high when stable.
    void setAllCellQuality(
        VfxRenderQualityEnum value          // [IN] quality
        );
// Signal
public:
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Signal>
    // when user tap the focused cell, m_signalSelected will emit.
    VfxSignal2 <VfxObject *, VfxS32> m_signalSelected;
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Signal>
    // notify when enter transition is finished. 
    VfxSignal0 m_signalEnterFinished;

// Variable
private:
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Variable>
    VfxS32  m_count;
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Variable>
    VfxS32  m_subCount;
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Variable>
    VfxBool m_cellOpaque;
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Variable>
    VfxBool m_cellTextOn;
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Variable>
    VfxBool m_cellOpacity;
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Variable>
    VcpFancyModeDataMgr  *m_dataMgr;
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Variable>
    VfxMatrix4x4 m_camera;
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Variable>
    VfxBool  m_isSwipe;
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Variable>
    VfxTextFrame *m_text[4];
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Variable>
    VfxTimer *m_qualityTimer;
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Variable>
    VfxBool m_textVisible;
// Implementation
private:
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Implementation>
    VfxBool hitTestonCell(VfxPoint pt, VfxS32 cell, VfxS32 subCell);
    // <group DOM_FancyModeMenu_VcpSpaceBeamMenu_Implementation>
    void onQualityTimerStop(VfxTimer *source);
};


/***************************************************************************** 
 * Class VcpFancyModeMenu
 *****************************************************************************/
/*
 *  VcpFancyModeMenu controll all the relative class used for fancy menu. 
 *  It is also an interface to outside application.
 */
class VcpFancyModeMenu : public VfxControl
{
// Constructor / Destructor
public:
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Constructor/Destructor>
    VcpFancyModeMenu();

// Method
public:
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Method>
    // Set all app data and count
    void setAllAppData(
        AppEntry appEntry[],                // [IN] all app data
        VfxS32 count                        // [IN] count
        );
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Method>
    // Enter fancy mode
    void enter(
        VcpFancyModeMenuType type,          // [IN] the type of fancy mode
        VfxS32 appOrder[],                  // [IN] app order 
        VfxS32 count,                       // [IN] app order count
        VfxS32 pageCount,                   // [IN] total page count
        VfxS32 focusedIndex,                // [IN] focused index
        VfxBool isAnim                      // [IN] is animate or not
        );
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Method>
    // Leave fancy mode
    void leave();
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Method>
    // Set focus item
    void setFocus(
        VfxS32 focus                        // [IN] focused index
        )
    {
        m_focus = focus;
    }
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Method>
    // Get focus item
    VfxS32 getFocus();

// Signal
public:
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Signal>
    // Notify when user click an app to launch, the app id is passed with signal
    VfxSignal1<VfxS32> m_appClicked;
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Signal>
    // Notify when leave transition is finished
    VfxSignal0 m_signalLeaveFinished;
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Signal>
    // Notify when enter transition is finished
    VfxSignal0 m_signalEnterFinished;
    
// Override 
protected:
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Override>
    virtual void onInit();


// Variable
private:
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Variable>
    // tornado menu
    VcpTornadoMenu        *m_tornadoMenu;
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Variable>
    // space beam menu
    VcpSpaceBeamMenu      *m_spaceBeamMenu;
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Variable>
    // menu transition
    VcpFancyModeMenuTransition *m_transition;
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Variable>
    VcpFancyModeDataMgr  *m_dataMgr;
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Variable>
    AppEntry *m_allAppData;
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Variable>
    VfxS32 m_allAppCount;
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Variable>
    VfxS32 *m_appOrder; 
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Variable>
    VfxS32 m_orderCount;
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Variable>
    VfxS32 m_pageCount;
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Variable>
    VfxS32 m_focusedIndex;
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Variable>
    VcpFancyModeMenuType m_type;
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Variable>
    VfxTimer  *m_timer;
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Variable>
    VfxS32     m_focus;
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Variable>
    VfxBool    m_isAnim;

// Implementation
private:
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Implementation>
    void onTransitionFinished();
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Implementation>
    void onTransitionFinished2();
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Implementation>
    void onEnterFinished();
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Implementation>
    void onUserSelected(VfxObject *menu, VfxS32 index);
    // <group DOM_FancyModeMenu_VcpFancyModeMenu_Implementation>
    void onTimerStop(VfxTimer *source);
};
#endif /* __VCP_FANCY_MODE_MENU_H__ */

#endif /* __MMI_VUI_3D_MAINMENU_FANCY__ */

