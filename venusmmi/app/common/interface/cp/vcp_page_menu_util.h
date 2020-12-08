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
 *  vcp_page_menu_util.h
 *
 * Project:
 * --------
 *  3D Main Menu
 *
 * Description:
 * ------------
 *  3D Main Menu
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
 *
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/

#ifndef __VCP_PAGE_MENU_UTIL_H__
#define __VCP_PAGE_MENU_UTIL_H__

#include "MMI_features.h"

#if defined(__MMI_VUI_3D_MAINMENU__) || defined(__COSMOS_MMI__) || defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_VUI_LAUNCHER_KEY__)

 /*****************************************************************************
  * Include
  *****************************************************************************/
#include "vfx_datatype.h"
#include "vfx_frame.h"
#include "vfx_cpp_base.h"
#include "vfx_control.h"
#include "vfx_basic_type.h"
#include "vfx_signal.h"
#include "vfx_input_event.h"
#include "vfx_object.h"
#include "vfx_transform.h"
#include "vfx_animation.h"
#include "vfx_text_frame.h"
#include "vrt_datatype.h"


 /*****************************************************************************
  * Define
  *****************************************************************************/

#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_VUI_LAUNCHER_KEY__)
#define MAINMENU_NO_INDICATOR_TRANSFORMATION_ANIMATION
#endif

static const VfxS32 VCP_PAGE_MENU_INDICATOR_MAX_PAGE_COUNT = 10;

static const VfxS32 MAINMENU_HITTEST_NOT_FOUND = -1;


/*****************************************************************************
  * Enum
  *****************************************************************************/

enum VcpPageMenuGroupEnum
{
    VCP_PAGE_MENU_GROUP_MAIN = 0,
    VCP_PAGE_MENU_GROUP_SCREEN,
    VCP_PAGE_MENU_GROUP_BOTTOM_BAR,
    VCP_PAGE_MENU_GROUP_FOLDER_ICON_TEMP,
    VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON,
    VCP_PAGE_MENU_GROUP_BOTTOM_BAR_FOLDER_ICON,
    VCP_PAGE_MENU_GROUP_FOLDER_EDITOR,
    VCP_PAGE_MENU_GROUP_ANIM,
    VCP_PAGE_MENU_GROUP_SIZE
};

enum VcpPageMenuCellHitAreaEnum
{
    VCP_PAGE_MENU_CELL_HIT_AREA_LEFT_TOP = 0,
    VCP_PAGE_MENU_CELL_HIT_AREA_CENTER_TOP,
    VCP_PAGE_MENU_CELL_HIT_AREA_RIGHT_TOP,
    VCP_PAGE_MENU_CELL_HIT_AREA_LEFT_CENTER,
    VCP_PAGE_MENU_CELL_HIT_AREA_CENTER,
    VCP_PAGE_MENU_CELL_HIT_AREA_RIGHT_CENTER,
    VCP_PAGE_MENU_CELL_HIT_AREA_LEFT_DOWN,
    VCP_PAGE_MENU_CELL_HIT_AREA_CENTER_DOWN,
    VCP_PAGE_MENU_CELL_HIT_AREA_RIGHT_DOWN,
    VCP_PAGE_MENU_CELL_HIT_AREA_INVALID,
    VCP_PAGE_MENU_CELL_HIT_AREA_SIZE
};

enum VcpPageMenuFolderStateEnum
{
    VCP_PAGE_MENU_NOT_FOLDER_MODE = 0,
    VCP_PAGE_MENU_FIRST_PREPARE_TO_FOLDER_MODE,
    VCP_PAGE_MENU_PREPARE_TO_FOLDER_MODE,
    VCP_PAGE_MENU_FIRST_FOLDER_MODE,
    VCP_PAGE_MENU_FOLDER_MODE,
    VCP_PAGE_MENU_FOLDER_STATE_SIZE
};


/*****************************************************************************
  * Class
  *****************************************************************************/

class VcpPageMenuCellPos : public VfxBase
{
public:
    VcpPageMenuCellPos(VfxS32 g, VfxS32 i): group(g), index(i)
    {
    }
    VfxS32 group;
    VfxS32 index;
    bool operator == (const VcpPageMenuCellPos rhs) const
    {
        return (group == rhs.group) && (index == rhs.index);
    }
    bool operator != (const VcpPageMenuCellPos rhs) const
    {
        return (group != rhs.group) || (index != rhs.index);
    }
};

/*****************************************************************************
 * Class VcpPageMenuIndicator
 *****************************************************************************/
class VcpPageMenuIndicatorLayout : public VfxBase
{
public:
    VcpPageMenuIndicatorLayout();

    VfxS32 indicatorWidthBase;
    VfxS32 indicatorWidthIncrement;
    VfxS32 indicatorHeight;
    VfxS32 bgOffsetY;
    VfxS32 bgHeight;
    VfxS32 cellSpacing;
    VfxS32 cellOffsetX;
    VfxS32 cellOffsetY;
    VfxS32 cellWidth;
    VfxS32 cellHeight;
    VfxS32 cellHighlightWidth;
    VfxS32 cellHighlightHeight;
};

/*****************************************************************************
 * Class VcpPageMenuIndicator
 *****************************************************************************/

class VcpPageMenuIndicator: public VfxControl
{
public:
    typedef VcpPageMenuIndicator Self;
    typedef VfxControl   Super;
public:
    VcpPageMenuIndicator();

    VfxS32 getCurrentPage();

    void setCurrentPage(VfxS32 currentPage);

    VfxS32 getIndicatorPageCount();

    void setIndicatorPageCount(VfxS32 pageCount);

    void update();

    VfxS32 getTouchPageIndex(VfxPoint pos);

    VfxSignal1<VfxS32> m_pageSelected;

    // appearance setting
    void setBgImage(VfxImageSrc bgImage);
    void setCellImage(VfxImageSrc cellNormal, VfxImageSrc cellHighlight, VfxS32 cellHighlightImgCount = 1);
    void setLayout(const VcpPageMenuIndicatorLayout layout);
    VcpPageMenuIndicatorLayout getLayout() const;

protected:
    virtual void onInit();

    virtual VfxBool onPenInput(VfxPenEvent &event);

private:
    VfxS32 m_pageCount;
    VfxS32 m_currentPage;
    VfxFrame * m_indicators[VCP_PAGE_MENU_INDICATOR_MAX_PAGE_COUNT];
    VfxFrame * m_highlight;
#ifndef MAINMENU_NO_INDICATOR_TRANSFORMATION_ANIMATION
    VfxFrame * m_easeOut;
#endif
    VfxFrame * m_background;

    VfxImageSrc m_cellNormal;
    VfxImageSrc m_cellHighlight;
    VfxS32      m_cellHighlightImgCount;
    VcpPageMenuIndicatorLayout m_layout;

    VfxPoint getIndicatorPos(VfxS32 i) const;
};

/*****************************************************************************
 * Class VcpPageMenuCell
 *****************************************************************************/

class VcpPageMenuCell: public VfxFrame
{
public:
    VcpPageMenuCell();

    void setCellIndex(VfxS32 index);
    VfxS32 getCellIndex() const;

    void setCellGroup(VfxS32 group);
    VfxS32 getCellGroup() const;

    void setCellPosY(VfxS32 posY);
    VfxS32 getCellPosY() const;
    VfxS32 forceGetCellPosY() const;
    
    void setCellScale(VfxFloat scale);
    VfxFloat getCellScale() const;
    VfxFloat forceGetCellScale() const;
    
    void setNeedSetExactPos(VfxBool needSetExactPos);
    VfxBool getNeedSetExactPos() const;
    
    virtual void onCellDisplay();

// Override
protected:
    virtual void onInit();
    
private:
    VfxFrame    *m_fpePropertyFrame;
    
    VfxBool m_needSetExactPos;
    
    VfxS32 m_cellGroup;
    VfxS32 m_cellIndex;
};


/*****************************************************************************
 * Class VcpPageMenuLayout
 *****************************************************************************/

class VcpPageMenuLayout : public VfxBase
{
public:
    VcpPageMenuLayout();

    VfxS32 rowCount;
    VfxS32 columnCount;

    VfxS32 cellStartX;
    VfxS32 cellStartY;
    VfxS32 cellOffsetX;
    VfxS32 cellOffsetY;

    VfxS32 rowCountInFolderIcon;
    VfxS32 columnCountInFolderIcon;
    
    VfxS32 cellInFolderIconStartX;
    VfxS32 cellInFolderIconStartY;
    VfxS32 cellInFolderIconOffsetX;
    VfxS32 cellInFolderIconOffsetY;

    VfxFloat cellInFolderIconScale;
    
    VfxS32 pageMargin;

    VfxS32 bottomBarOffsetY;
    VfxS32 bottomBarVisibleShiftY;
};


/*****************************************************************************
 * Class VcpPageMenuFolderEditorLayout
 *****************************************************************************/

class VcpPageMenuFolderEditorLayout : public VfxBase
{
public:
    VcpPageMenuFolderEditorLayout();

    VfxS32 folderEditorPosX;
    VfxS32 folderEditorPosY;
    VfxS32 folderEditorWidth;
    VfxS32 folderEditorHeight;

    VfxS32 folderEditorMainShiftY;
    
    VfxS32 rowCountInFolderEditor;
    VfxS32 columnCountInFolderEditor;
    
    VfxS32 cellInFolderEditorStartX;
    VfxS32 cellInFolderEditorStartY;
    VfxS32 cellInFolderEditorOffsetX;
    VfxS32 cellInFolderEditorOffsetY;
};


/*****************************************************************************
 * Interface IVcpPageView
 *****************************************************************************/

#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
enum VcpPageMenuTransitionType;
#endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__

class IVcpPageView
{
public:
    // initialization
    virtual void setSize(VfxS32 width, VfxS32 height) = 0;

    virtual void setCellIconSize(const VfxSize & size) = 0;

    virtual void initCellAnim(VcpPageMenuCell * cell, VfxS32 group) = 0;

    virtual void setLayout(const VcpPageMenuLayout & layout) = 0;

    virtual void reset() = 0;

    virtual void setOrganizeMode(VfxBool organizeMode) = 0;

    virtual void setIsUninstalling(VfxBool isUninstalling) = 0;
    virtual void setIsEnterNCenter(VfxBool isEnterNCenter) = 0;

#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
    virtual void setTransitionEffect(VcpPageMenuTransitionType transitionType) = 0;
    virtual void setTransitionDirection(VfxS32 direction) = 0;
#endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__

    // misc
    virtual VfxS32 getWidth() const = 0;
    virtual VfxS32 getHeight() const = 0;

    virtual VcpPageMenuCell * getDraggingFrame() const = 0;
    virtual void setDraggingFrame(VcpPageMenuCell * draggingFrame) = 0;

    virtual void setScaleFrame(VcpPageMenuCell * scaleFrame) = 0;

    virtual void changeCellGroup(VcpPageMenuCell * cell, VfxS32 newGroup) = 0;

    // cell position helpers
    virtual VfxS32 getCellPosX(VcpPageMenuCell * cell) const = 0;
    virtual void setCellPosX(VcpPageMenuCell * cell, VfxS32 posX) = 0;
    virtual VfxS32 getCellPosY(VcpPageMenuCell * cell) const = 0;
    virtual void setCellPosY(VcpPageMenuCell * cell, VfxS32 posY) = 0;

    // whole view property helpers
    virtual VfxS32 getCurrentTranslateX() const = 0;

    virtual void updateRotation(VfxS32 duration, VfxFloat rotateAngle, VfxBool rotateReset) = 0;
    virtual void updateTranslateX(VfxS32 duration, VfxFloat translate) = 0;
    virtual void updateTranslateXInstant(VfxFloat translate) = 0;
    virtual void updateScale(VfxS32 duration, VfxFloat targetScale) = 0;
    virtual void updateShakeTransform(VfxBool isOrganizeMode) = 0;
    virtual void setAnimDirty(VfxS32 duration) = 0;

    // folder support
    virtual VfxFloat getCellScale(VcpPageMenuCell *cell) const = 0;
    virtual void setCellScale(VcpPageMenuCell *cell, VfxFloat scale) = 0;
    
    virtual const VcpPageMenuFolderEditorLayout &getFolderEditorLayout() const = 0;
    virtual void setFolderEditorLayout(const VcpPageMenuFolderEditorLayout &folderEditorLayout) = 0;
    
    virtual void setFolderState(VcpPageMenuFolderStateEnum folderState) = 0;
};
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
#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
/* under construction !*/
/* under construction !*/
#endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
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
/*****************************************************************************
 * Class VcpRotatePageView
 *****************************************************************************/

#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
class VcpPageMenuTransition;
#endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__

// handle the fpe effect for page animation
class VcpRotatePageView : public VfxObject, public IVcpPageView
{
public:
    VcpRotatePageView();

    // initialization
    virtual void setSize(VfxS32 width, VfxS32 height);

    virtual void setCellIconSize(const VfxSize & size);

    virtual void initCellAnim(VcpPageMenuCell * cell, VfxS32 group);

    virtual void setLayout(const VcpPageMenuLayout & layout);

    virtual void reset();

    virtual void setOrganizeMode(VfxBool organizeMode);

    virtual void setIsUninstalling(VfxBool isUninstalling);
    virtual void setIsEnterNCenter(VfxBool isEnterNCenter);
    
#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
    virtual void setTransitionEffect(VcpPageMenuTransitionType transitionType);
    virtual void setTransitionDirection(VfxS32 direction);
#endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__

    // misc
    virtual VfxS32 getWidth() const;
    virtual VfxS32 getHeight() const;

    virtual VcpPageMenuCell * getDraggingFrame() const;
    virtual void setDraggingFrame(VcpPageMenuCell * draggingFrame);

    virtual VcpPageMenuCell * getScaleFrame() const;
    virtual void setScaleFrame(VcpPageMenuCell * scaleFrame);

    virtual void changeCellGroup(VcpPageMenuCell * cell, VfxS32 newGroup);

    // cell position helpers
    virtual VfxS32 getCellPosX(VcpPageMenuCell * cell) const;
    virtual void setCellPosX(VcpPageMenuCell * cell, VfxS32 posX);
    virtual VfxS32 getCellPosY(VcpPageMenuCell * cell) const;
    virtual void setCellPosY(VcpPageMenuCell * cell, VfxS32 posY);

    // whole view property helpers
    virtual VfxS32 getCurrentTranslateX() const;

    virtual void updateRotation(VfxS32 duration, VfxFloat rotateAngle, VfxBool rotateReset);
    virtual void updateTranslateX(VfxS32 duration, VfxFloat translate);
    virtual void updateTranslateXInstant(VfxFloat translate);
    virtual void updateScale(VfxS32 duration, VfxFloat targetScale);
    virtual void updateShakeTransform(VfxBool isOrganizeMode);
    virtual void setAnimDirty(VfxS32 duration);

    // folder support
    virtual VfxFloat getCellScale(VcpPageMenuCell *cell) const;
    virtual void setCellScale(VcpPageMenuCell *cell, VfxFloat scale);
    
    virtual const VcpPageMenuFolderEditorLayout &getFolderEditorLayout() const;
    virtual void setFolderEditorLayout(const VcpPageMenuFolderEditorLayout &folderEditorLayout);

    virtual void setFolderState(VcpPageMenuFolderStateEnum folderState);
    
protected:
    virtual void onInit();
    virtual void onDeinit();

private:
    // member variables
    VfxS32                  m_width;
    VfxS32                  m_height;
    VfxSize                 m_cellIconSize;
    VfxFrame *              m_animDummyFrame[VCP_PAGE_MENU_GROUP_SIZE];
    VcpPageMenuCell *       m_draggingFrame;
    VcpPageMenuCell *       m_scaleFrame;
    VfxMsec                 m_animDirtyEndTime;
    VcpPageMenuLayout       m_layout;
    VfxBool                 m_organizeMode;

    // uninstalling state
    VfxBool m_isUninstalling;

    // NCenter state
    VfxBool m_isEnterNCenter;
    
    // folder support
    VcpPageMenuFolderStateEnum      m_folderState;
    VcpPageMenuFolderEditorLayout   m_folderEditorLayout;
    VfxS32                          m_tempCellInFolderIconOriginalPosX;
    VfxS32                          m_tempCellInFolderIconOriginalPosY;

    // transform data
    VfxMatrix4x4            m_camera;
    VfxMatrix4x4            m_transform;
    VfxMatrix4x4            m_scaleTransform;
    VfxFloat                m_currentRotation;
    VfxFloat                m_currentTranslate;
    VfxBool                 m_instantTranslate;
#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
    VcpPageMenuTransition * m_transition;
    VfxS32                  m_direction;
#endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__

    // timeline
    VfxS32Timeline *        m_translateXTimeline;
    VfxFloatTimeline *      m_rotateTimeline;
    VfxFloatTimeline *      m_scaleTimeline;
    VfxTransformTimeline    *m_shakeTransformTimeline;
    VfxTransformTimeline    *m_shakeTransfromTimelineBottom;
    VfxTransformTimeline    *m_shakeTransfromTimelineFolder;


    // helper functions

    void setCameraPara();

    VfxFrame * getAnimDummyFrame(VfxS32 group) const;

    VfxS32 getCurrentTranslateXInt(VfxS32 group) const;

    VfxTransform getCurrentShakeTransform();

    void initShakeTransformTimeline(VfxTransformTimeline *shakeTransformTimeline, VfxS32 type);
    
    // FPE callback
    static vrt_render_dirty_type_enum framePropertyEffectCallback(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size);

    static void framePropertyReset(vrt_frame_visual_property_struct *target_frame);
    
    static void framePropertyResetInt(vrt_frame_visual_property_struct *target_frame);
    
    static vrt_render_dirty_type_enum fpeMainGroup(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size);

    static vrt_render_dirty_type_enum fpeOtherGroup(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size);

    // folder support
    static vrt_render_dirty_type_enum fpeFolderIconTempGroup(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size);

    static vrt_render_dirty_type_enum fpeFolderIconGroup(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size);

    // custom timer callback
    static VfxTimelineInterpolationRetEnum translateTimelineFunc(
        void *output,
        const void *fromValue,
        const void *toValue,
        VfxTypeIdEnum typeId,
        VfxFloat t,
        void *data,
        VfxU32 data_size);

    static VfxTimelineInterpolationRetEnum rotateTimelineFunc(
        void *output,
        const void *fromValue,
        const void *toValue,
        VfxTypeIdEnum typeId,
        VfxFloat t,
        void *data,
        VfxU32 data_size);

    static VfxTimelineInterpolationRetEnum scaleTimelineFunc(
        void *output,
        const void *fromValue,
        const void *toValue,
        VfxTypeIdEnum typeId,
        VfxFloat t,
        void *data,
        VfxU32 data_size);
};


/*****************************************************************************
 * Class VcpPageMenuView
 *****************************************************************************/

class VcpPageMenuView : public VfxObject
{
public:
    VcpPageMenuView();

    // PageView wrapper
    void setSize(VfxS32 width, VfxS32 height);

    void setCellIconSize(const VfxSize & size);

    void initCellAnim(VcpPageMenuCell * cell, VfxS32 group);

    void reset();

    void changeCellGroup(VcpPageMenuCell * cell, VfxS32 newGroup);

    VcpPageMenuCell * getDraggingFrame() const;
    void setDraggingFrame(VcpPageMenuCell * draggingFrame);

    void setClickFrame(VcpPageMenuCell * scaleFrame);

    void setAnimDirty(VfxS32 duration);

    // layout helpers
    const VcpPageMenuLayout &getLayout() const;
    void setLayout(const VcpPageMenuLayout & layout);
    VfxS32 getPageItemCount() const;
    VfxS32 getMaxPageCount(VfxS32 maxCellCount) const;

    // properties
    VfxS32 getTranslateX() const;
    void setTranslateX(VfxS32 translateX, VfxS32 translateDuration);
    void setRotateAngle(VfxFloat rotateAngle, VfxS32 rotateDuration, VfxBool rotateReset);

    void setOrganizeMode(VfxBool organizeMode);
    VfxBool getOrganizeMode();

    void setHover(VcpPageMenuCellPos hover);
    VcpPageMenuCellPos getHover();

    void setClipMargin(VfxS32 clipMargin);

    void setIsUninstalling(VfxBool isUninstalling);
    void setIsEnterNCenter(VfxBool isEnterNCenter);

#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
    VcpPageMenuTransitionType getTransitionEffect() const;
    void setTransitionEffect(VcpPageMenuTransitionType transitionType);
    void setTransitionDirection(VfxS32 direction);
#endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__

    // helper functions
    VfxS32 getPageTranslateX(VfxS32 pageIndex) const;
    VfxS32 getNearestPage() const;
    VfxS32 getNextPage() const;
    VfxS32 getPreviousPage() const;
    VfxBool isTransitioning() const;
    VfxPoint getOrganizeDragOffset() const;

    // hit test
    VcpPageMenuCellPos baseCellHittest(VfxPoint clickPoint, VfxS32 maxCellCount, VcpPageMenuCellHitAreaEnum *hitArea = NULL) const;
    VcpPageMenuCellPos baseCellHittestBar(VfxPoint clickPoint, VcpPageMenuCellHitAreaEnum *hitArea = NULL) const;

    // set only properties
    void setDragOnIndicator(VfxBool dragOnIndicator);

    void setHoldFrame(VcpPageMenuCell * holdFrame);
    void initDraggingFramePos(VcpPageMenuCell * hoverCell, VfxS32 cellGroup, VfxS32 touchPosX, VfxS32 touchPosY);
    void setDraggingFramePos(VfxS32 touchPosX, VfxS32 touchPosY);

    // set translate to current value
    void syncTranslateX();

    // misc
    void forceDirty();

    // update the view properties to screen
    void update(VcpPageMenuCell ** cells, VfxS32 cellCount, 
            VcpPageMenuCell ** groupCells, VfxS32 groupCellCount);

    // folder support
    // properties
    void setFolderState(VcpPageMenuFolderStateEnum folderState);
    VcpPageMenuFolderStateEnum getFolderState();
    
    void setFolderCellPos(VcpPageMenuCellPos folderCellPos);
    VcpPageMenuCellPos getFolderCellPos();

    // layout helpers
    VfxS32 getFolderIconItemCount() const;
    const VcpPageMenuFolderEditorLayout &getFolderEditorLayout() const;
    void setFolderEditorLayout(const VcpPageMenuFolderEditorLayout &folderEditorLayout);
    
    // update the view properties to screen with folder feature
    void updateEx(VcpPageMenuCell **cells, VfxS32 cellCount,
                  VcpPageMenuCell **groupCells, VfxS32 groupCellCount,
                  VcpPageMenuCell **cellsInFolderIcon, VfxS32 folderCount, VfxS32 cellInFolderIconCount,
                  VcpPageMenuCell **groupCellsInFolderIcon, VfxS32 groupFolderCount, VfxS32 groupCellInFolderIconCount,
                  VcpPageMenuCell **cellsInFolderEditor, VfxS32 cellInFolderEditorCount);
    
protected:
    virtual void onInit();

    virtual void updateCellAttribute(VcpPageMenuCell * cell, VcpPageMenuCellPos pos);

private:
    // member variable
    IVcpPageView *          m_pageView;
    VcpPageMenuCell *       m_clickFrame;

    // grid layout parameters
    VcpPageMenuLayout     m_layout;

    // page-wise animation parameters
    VfxS32                      m_translateX;
    VfxMsec                     m_translateDuration;
    VfxBool                     m_translateDirty;
    VfxFloat                    m_rotateAngle;
    VfxMsec                     m_rotateDuration;
    VfxBool                     m_rotateReset;
    VfxBool                     m_rotateDirty;
    VfxS32                      m_clipMargin;
#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
    VfxS32                      m_transitionType;
#endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__

    // appearance parameters -- maintained by menu
    VfxBool                 m_organizeMode;
    VcpPageMenuCellPos      m_hover;
    VfxBool                 m_dragOnIndicator;

    // folder support
    VcpPageMenuFolderStateEnum  m_folderState;
    VcpPageMenuCellPos          m_folderCellPos;
    
    // dragging support
    VfxPoint                m_organizeDragOffset;

    // implementation
    VfxBool isCellInRange(VfxS32 index);
    VfxBool isCellInMiddleOfLongRange(VfxS32 index);

    // update cell frame properties
    void updateCells(VcpPageMenuCell ** cells, VfxS32 cellCount);
    void updateGroupCells(VcpPageMenuCell ** cells, VfxS32 cellCount);
    void updateCellPos(VcpPageMenuCell * cell, VfxS32 index);
    void updateGroupCellPos(VcpPageMenuCell * cell, VfxS32 index, VfxS32 shiftY);
    void updateCellPosInt(VcpPageMenuCell * cell, VfxS32 x, VfxS32 y, VfxBool isFolder);

    // folder support
    void updateCellsInFolderIcon(VcpPageMenuCell **cellsInFolderIcon, VfxS32 folderCount, VfxS32 cellInFolderIconCount);
    void updateCellInFolderIconPos(VcpPageMenuCell *cell, VfxS32 subIndex);
    void updateCellsInFolderEditor(VcpPageMenuCell **cellsInFolderEditor, VfxS32 cellInFolderEditorCount);
    void updateCellInFolderEditorPos(VcpPageMenuCell *cell, VfxS32 index);
    VcpPageMenuCellHitAreaEnum baseCellHittestArea(VfxPoint clickPoint,
                                                   VfxS32 topAreaBoundary,
                                                   VfxS32 downAreaBoundary,
                                                   VfxS32 leftAreaBoundary,
                                                   VfxS32 rightAreaBoundary) const;
    VcpPageMenuCellPos baseCellHittestFolderEditor(VfxPoint clickPoint) const;

    // helper functions
    VfxMsec getTranslateDuration() const;
    VfxMsec getRotateDuration() const;
    VfxFloat getRotateAngle() const;
    public:
    VfxS32 getPageLevel() const;
};


/*****************************************************************************
  * Menu Cell Utility Functions
  *****************************************************************************/

VfxBool vcpPageMenuIsPageEmpty(VcpPageMenuCell ** cells, VfxS32 pageItemCount,
        VfxS32 pageIndex);
void vcpPageMenuMovePageContent(VcpPageMenuCell **cells, VfxS32 pageItemCount, VfxS32 srcPageIndex, VfxS32 destPageIndex,
                                VcpPageMenuCell **cellsInFolderIcon = NULL, VfxS32 cellsCountPerFolder = 0);
void vcpPageMenuClearPageContent(VcpPageMenuCell **cells, VfxS32 pageItemCount, VfxS32 pageIndex,
                                 VcpPageMenuCell **cellsInFolderIcon = NULL, VfxS32 cellsCountPerFolder = 0);

void vcpPageMenuApplyFrameRenderHints(VfxFrame * frame);

#endif // defined(__MMI_VUI_3D_MAINMENU__) || defined(__COSMOS_MMI__) || defined(__MMI_VUI_LAUNCHER__)|| defined(__MMI_VUI_LAUNCHER_KEY__)

#endif // __VCP_PAGE_MENU_UTIL_H__

