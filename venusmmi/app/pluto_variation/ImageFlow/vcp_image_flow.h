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
 *  vcp_image_flow.h
 *
 * Project:
 * --------
 *  Venus UI Component
 *
 * Description:
 * ------------
 *  Venus Image Flow Component
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VCP_IMAGE_FLOW_MAIN_H__
#define __VCP_IMAGE_FLOW_MAIN_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_base_menu.h"
#include "vcp_wheel_menu.h"
#include "vcp_content_clone.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_basic_type.h"
#include "vfx_frame.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_input_event.h"
#include "vfx_signal.h"
#include "vfx_transform.h"
#include "vfx_timer.h"
#include "vrt_datatype.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

//#define VCP_IMAGE_FLOW_REFLECTED_ENABLE    (1)
#ifndef __CPU_ARM7EJ_S__
#define VCP_IMAGE_FLOW_REFLECTED_ENABLE_2  (1)
#endif

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

struct VcpImageFlowFrameData
{
    VfxS32 posX;
    VfxS32 width;
    VfxS32 height;
    VfxS32 secondWidth;
    VfxS32 thirdWidth;
    VfxS32 upShift;
    VfxBool disable;
};
/***************************************************************************** 
 * Global Function 
 *****************************************************************************/

/*****************************************************************************
 * Class IVcpImageFlowContentProvider
 *****************************************************************************/

/*
 *  IVcpImageFlowContentProvider is a interface which provides the image 
 *  Contents for VcpImageFlow. The virtual function getImageContent() should be
 *  implemented to return a decoded image immediately. Otherwise it will affect
 *  the smoothness of scrolling. A good method is to return a default image
 *  (from ResID) if the image content is not ready. then call updateImageContent()
 *  of VcpImageFlow to replace this image when image content is ready. Becasue
 *  this class is a interface, the APP should inherit it as follow form.
 *  EXAMPLE
 * <code>
 *  class ImageFlowData : public VfxObject, public IVcpImageFlowContentProvider
 *  {}
 * </code>
 *  VfxObject can be replaced as any non-interface class.
 */
class IVcpImageFlowContentProvider 
{
public:
    // Overridable
    virtual VfxImageSrc& getImageContent(
        VfxS32 index    // [IN] the index of images
        ) = 0;
};

/*****************************************************************************
 * Class VcpImageFlowLayout
 *****************************************************************************/

/*
 *  VcpImageFlowLayout decribes the layout of VcpImageFlow. It aslo stores
 *  information of layout such like number of content and current focus item.
 *  The methods of VcpImageFlowLayout is design for VcpImageFlow to use. APP 
 *  should not call this methods.
 */
class VcpImageFlowLayout : public VcpBaseMenuLayout
{
// Constructor / Destructor
public:
    // <group DOM_ImageFlow_VcpImageFlowLayout_Constructor/Destructor>
    VcpImageFlowLayout(VcpBaseMenu* menu);

// Method
public:
    // <group DOM_ImageFlow_VcpImageFlowLayout_Method>
    // query the Menu position that the point hit. 
    VcpMenuPos getCellByPos(
        VfxPoint pt             // [IN] The point wants to do hit test
        );
    // <group DOM_ImageFlow_VcpImageFlowLayout_Method>
    // set the total number of cells
    void setCellNumber(
        VfxS32 number           // [IN] number of cell
        );
    // <group DOM_ImageFlow_VcpImageFlowLayout_Method>
    // set the width of cell which is not focused
    void setCellWidth(
        VfxS32 width            // [IN] width of cell which is unfocused
        );
    // <group DOM_ImageFlow_VcpImageFlowLayout_Method>
    // set the height of cell
    void setCellHeight(
        VfxS32 height           // [IN] height of cell
        );
    // <group DOM_ImageFlow_VcpImageFlowLayout_Method>
    // set the width of cell which is focused
    void setFocusCellWidth(
        VfxS32 width            // [IN] width of cell which is focused
        );
    // <group DOM_ImageFlow_VcpImageFlowLayout_Method>
    // set the width of cell which is next to focused cell
    void  setSecCellWidth(
        VfxS32 width            // [IN] width of cell which is next focused cell
        );
    // <group DOM_ImageFlow_VcpImageFlowLayout_Method>
    // set total number of cell, width of cell which is focused/unfocused and height of cell.
    void setCellParameter(
        VfxS32 number,          // [IN] number of cell
        VfxS32 focusCellWidth,  // [IN] width of cell which is focused
        VfxS32 secCellWidth,    // [IN] width of cell which is next to focused cell
        VfxS32 cellWidth,       // [IN] width of cell which is unfocused
        VfxS32 cellHeight       // [IN] height of cell
        );

// Override
public:
    // <group DOM_ImageFlow_VcpImageFlowLayout_Override>
    virtual ScrollDirEnum getScrollDir() 
    {
        return SCROLLDIR_HORZ;
    }
    // <group DOM_ImageFlow_VcpImageFlowLayout_Override>
    virtual int getCellCount(VfxS32 group);
    // <group DOM_ImageFlow_VcpImageFlowLayout_Override>
    virtual VfxS32 getContentLength();
    // <group DOM_ImageFlow_VcpImageFlowLayout_Override>
    virtual VcpMenuRegion queryRegion(const VfxRect & rect);
    // <group DOM_ImageFlow_VcpImageFlowLayout_Override>
    virtual VfxRect queryCellRect(VcpMenuPos pos);
    // <group DOM_ImageFlow_VcpImageFlowLayout_Override>
    virtual void onViewChanged();
    // <group DOM_ImageFlow_VcpImageFlowLayout_Override>
    virtual VfxBool navDir(NavDirEnum dir);
    // <group DOM_ImageFlow_VcpImageFlowLayout_Override>
    virtual void getPreferFocusMargin(VfxS32 margin[4]);
    // <group DOM_ImageFlow_VcpImageFlowLayout_Override>
    virtual void onStopPosFix(VfxPoint& pos);

// Implementation
private:
    // <group DOM_ImageFlow_VcpImageFlowLayout_Implementation>
    VfxS32 getNewFocusByX(VfxS32 posX, VfxS32 &shift);

public: 
    // <group DOM_ImageFlow_VcpImageFlowLayout_Implementation>
    VfxS32 getAnchorPosX(VfxS32 index);
    
// Variable
private:
    // <group DOM_ImageFlow_VcpImageFlowLayout_Variable>
    VfxS32 m_cellNumber;
    // <group DOM_ImageFlow_VcpImageFlowLayout_Variable>
    VfxS32 m_focusCellWidth;
    // <group DOM_ImageFlow_VcpImageFlowLayout_Variable>
    VfxS32 m_secCellWidth;
    // <group DOM_ImageFlow_VcpImageFlowLayout_Variable>
    VfxS32 m_cellWidth;
    // <group DOM_ImageFlow_VcpImageFlowLayout_Variable>
    VfxS32 m_cellHeight;
    // <group DOM_ImageFlow_VcpImageFlowLayout_Variable>
    VfxS32 m_margin;
};

/*****************************************************************************
 * Class VcpImageFlowCell
 *****************************************************************************/

/*
 *  VcpImageFlowCell is a cell of VcpImageFlow
 */
class VcpImageFlowCell : public VfxFrame
{
// Constructor / Destructor
public:
    // <group DOM_ImageFlow_VcpImageFlowCell_Constructor/Destructor>
    VcpImageFlowCell(){}
    // <group DOM_ImageFlow_VcpImageFlowCell_Constructor/Destructor>
    virtual ~VcpImageFlowCell(){}
// Override
protected:
#ifdef VCP_IMAGE_FLOW_REFLECTED_ENABLE
    // <group DOM_ImageFlow_VcpImageFlowCell_Override>
    virtual void onInit()
    {
        VfxFrame::onInit();
        VFX_OBJ_CREATE(m_shadow, VfxFrame, this);
        setBgColor(VFX_COLOR_BLACK);
        m_shadow->setOpacity(0.3f);
        //m_shadow->setIsCached(VFX_TRUE);
        m_shadow->setIsOpaque(VFX_TRUE);
    };

    // <group DOM_ImageFlow_VcpImageFlowCell_Override>
    virtual void onDraw(VfxDrawContext &dc);
#endif

#ifdef VCP_IMAGE_FLOW_REFLECTED_ENABLE_2
    // <group DOM_ImageFlow_VcpImageFlowCell_Override>
    virtual void onInit()
    {
        VfxFrame::onInit();
        VFX_OBJ_CREATE(m_main, VfxFrame, this);
        m_main->setIsCached(VFX_TRUE);
        m_main->setIsOpaque(VFX_TRUE);

        VFX_OBJ_CREATE(m_shadow, VcpContentClone, this);
        m_shadow->setIsCached(VFX_TRUE);
        m_shadow->setIsOpaque(VFX_TRUE);
        //m_shadow->setOutputAlpha(VFX_TRUE);
    };
#endif
// Variable
public:
#ifdef VCP_IMAGE_FLOW_REFLECTED_ENABLE
    // <group DOM_ImageFlow_VcpImageFlowCell_Variable>
    VfxImageSrc m_image;
    // <group DOM_ImageFlow_VcpImageFlowCell_Variable>
    //VfxFrame *m_main;
    VfxFrame *m_shadow;
    //VfxFrame *m_shadowMask;
#endif
#ifdef VCP_IMAGE_FLOW_REFLECTED_ENABLE_2
    // <group DOM_ImageFlow_VcpImageFlowCell_Variable>
    VfxFrame *m_main;
    // <group DOM_ImageFlow_VcpImageFlowCell_Variable>
    VcpContentClone *m_shadow;
#endif
};

/*****************************************************************************
 * Class VcpImageFlow
 *****************************************************************************/

/*
 *  VcpImageFlow provide a horizental scrollable UI to view a set of images.
 *  The APP who use VcpImageFlow need to provide the images of each cell by
 *  inheriting from IVcpImageFlowContentProvider. VcpImageFlow will notify 
 *  APP by emiting m_signalSelected and m_signalFocusChanged when user select
 *  a cell or the focus of VcpImageFlow is changed. 
 *
 * EXAMPLE
 * <code>
 *  VcpImageFlow *m_imageFlow;
 *  VFX_OBJ_CREATE(m_imageFlow, VcpImageFlow, this);
 *  m_imageFlow->setPos(VfxPoint(10, 120));
 *  m_imageFlow->setBounds(VfxRect(0, 0, 220, 150));
 *  m_imageFlow->setCellParameter(15,120,150,60,20,105);
 *
 *  // need to set ContentProvider 
 *  m_imageFlow->setContentProvider(m_imageFlowData);
 *  m_imageFlow->m_signalSelected.connect(this, &VtstStringScr::onSelected);
 * </code>
 */
class VcpImageFlow : public VcpBaseMenu
{
// Constructor / Destructor
public:
    // <group DOM_ImageFlow_VcpImageFlow_Constructor/Destructor>
    VcpImageFlow();
    
// Method
public:
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // update Image Content when image is ready.
    // Because getImageContent() of IVcpImageFlowContentProvider may get a 
    // default image when image content is not ready. APP may call this 
    // function later when image content is ready.
    void updateImageContent(
        VfxS32 index,           // [IN] the index of image  
        VfxImageSrc &image      // [IN] the image content
        );
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // set content provider of VcpImageFlow
    void setContentProvider(
        IVcpImageFlowContentProvider *contentProvider // [IN] content provider 
        );
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // set focus index of VcpImageFlow. the cell of focus will put into center of view.
    void setFocusIndex(
        VfxS32 index            // [IN] the index of image
        );
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // set the total number of cells
    void setCellNumber(
        VfxS32 number           // [IN] number of cell
        );
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // set the width of cell which is not focused
    void setCellWidth(
        VfxS32 width            // [IN] width of cell which is unfocused
        );
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // set the height of cell
    void setCellHeight(
        VfxS32 height           // [IN] height of cell
        );
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // set the width of cell which is focused
    void setFocusCellWidth(
        VfxS32 width            // [IN] width of cell which is focused
        );
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // set the width of cell which is focused
    void setFocusCellHeight(
        VfxS32 height           // [IN] height of cell which is focused
        );
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // set total number of cell, width of cell which is focused/unfocused and height of cell.
    void setCellParameter(
        VfxS32 number,          // [IN] number of cell
        VfxS32 focusCellWidth,  // [IN] width of cell which is focused
        VfxS32 focusCellHeight, // [IN] height of cell which is focused
        VfxS32 secCellWidth,    // [IN] width of cell which is next to focused cell 
        VfxS32 cellWidth,       // [IN] width of cell which is unfocused
        VfxS32 cellHeight       // [IN] height of cell
        );
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // set RotateAngle of unFocus cell. default value is 90. 
    void setRotateAngle(
        VfxFloat angle          // [IN] angle in degree
        );
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // set up shift of unFocus cell. 
    void setUpShift(
        VfxFloat upShift          // [IN] up shift
        );
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // set camera distance of VcpImageFlow. the camera distance will affect the perspective 
    // degree of the unFocus cell. if the distance is short, the perspective will strong. So
    // you can see the difference between near edge and far edge will become large. the 
    // default value of distance is 240.
    void setCameraDistance(
        VfxFloat distance       // [IN] camera distance
        );
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // set the number of cell which is out of screen for cached. if the number is too large,
    // it will create a lot of cells at the same time. it will affect the memory use and block
    // MMI task when create those cells.
    void setCachedCellNumber(
        VfxS32 number           // [IN] number of cells
        );
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // set the backward distance between focused cell and unfocused cell
    void setBackDistance(
        VfxFloat distance       // [IN] backward distance 
        );
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // set the shadow factor to change shadow length.
    void setShadowFactor(
        VfxFloat value          // [IN] shadow factor
        );
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // set the up Shift on Focus item.
    void setFocusUpShift(
        VfxS32 upShift          // [IN] up shift on focus item
        );
    
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // get focus index of VcpImageFlow.
    VfxS32 getFocusIndex() const;
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // get the total number of cells
    VfxS32 getCellNumber() const;
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // get the width of cell which is not focused
    VfxS32 getCellWidth() const;
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // get the height of cell
    VfxS32 getCellHeight() const;
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // get the width of cell which is focused
    VfxS32 getFocusCellWidth() const;
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // get the height of cell which is focused
    VfxS32 getFocusCellHeight() const;
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // get RotateAngle of unFocus cell.
    VfxFloat getRotateAngle() const;
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // get camera distance of VcpImageFlow. 
    VfxFloat getCameraDistance() const;
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // get the backward distance between focus cell and unfocus cell
    VfxFloat getBackDistance() const;
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // get the shadow factor.
    VfxFloat getShadowFactor() const;
    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // get the up Shift on Focus item.
    VfxS32 getFocusUpShift() const;

    // <group DOM_ImageFlow_VcpImageFlow_Method>
    // set all cell isCached attribute
    void setAllCellisCached(VfxBool value);

// Override
protected:
    // <group DOM_ImageFlow_VcpImageFlow_Override>
    virtual void onInit();
    // <group DOM_ImageFlow_VcpImageFlow_Override>
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

    // VcpBaseMenu virtual function

    // <group DOM_ImageFlow_VcpImageFlow_Override>
    virtual VcpBaseMenuLayout* createLayout();
    // <group DOM_ImageFlow_VcpImageFlow_Override>
    virtual VfxFrame* createCell(VfxS32 group, VfxS32 pos);  
    // <group DOM_ImageFlow_VcpImageFlow_Override>
    virtual void onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame);
    // <group DOM_ImageFlow_VcpImageFlow_Override>
    virtual void onUpdateCell(const VfxRect &rect, VfxS32 group, VfxS32 pos, VfxFrame* cell, VfxU32 flag);  
    // <group DOM_ImageFlow_VcpImageFlow_Override>
    virtual void onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos previousFocusItem);
    // <group DOM_ImageFlow_VcpImageFlow_Override>
    virtual void onDragEnd();
    // <group DOM_ImageFlow_VcpImageFlow_Override>
    virtual void onTap(const VfxPoint &pt);
    // <group DOM_ImageFlow_VcpImageFlow_Override>
    virtual void onUpdate();

// Variable
public:
    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    // when user tap the focused cell, m_signalSelected will emit.
    VfxSignal3 <VcpImageFlow *, VfxFrame*, VfxS32> m_signalSelected;
    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    // when the focus index changed, m_signalFocusChanged will emit.
    VfxSignal2 <VcpImageFlow *, VfxS32> m_signalFocusChanged;
    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    // when the cell of index is closed, m_signalCellClosed will emit.
    VfxSignal2 <VcpImageFlow *, VfxS32> m_signalCellClosed;

private:  
    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    VfxMatrix4x4 m_compositeMatrix;
    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    VfxMatrix4x4 m_centerMatrix;
    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    VfxMatrix4x4 m_leftMatrix;
    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    VfxMatrix4x4 m_rightMatrix;
    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    VfxTransform m_centerTransform;
    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    VfxTransform m_leftTransform;
    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    VfxTransform m_rightTransform;
    
    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    VfxS32       m_focusCellWidth;
    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    VfxS32       m_focusCellHeight;
    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    VfxS32       m_cellWidth;
    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    VfxS32       m_cellHeight;
    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    VfxS32       m_secCellWidth;
    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    VfxS32       m_secCellHeight;
    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    VfxFloat     m_rotateAngle;
    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    VfxFloat     m_upShift;
    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    VfxFloat     m_cameraDistance;
    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    VfxFloat     m_backDistance;
    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    VfxBool      m_updateBackDistance;
    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    VfxS32       m_shift;
    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    VfxFloat     m_shadowFactor;
    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    VfxS32       m_focusUpShift;

    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    IVcpImageFlowContentProvider *m_contentProvider;

    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    VfxTimer     *m_animationTimer;
    // <group DOM_ImageFlow_VcpImageFlow_Variable>
    VfxBool      m_useFPE;
    
// Implementation
private:
    // <group DOM_ImageFlow_VcpImageFlow_Implementation>
    void updateTransform();
    // <group DOM_ImageFlow_VcpImageFlow_Implementation>
    void adjustRenderSequence();
    // <group DOM_ImageFlow_VcpImageFlow_Implementation>
    void setAllAutoAnimate(VfxBool value);
    // <group DOM_ImageFlow_VcpImageFlow_Implementation>
    void onAnimationTimerStop(VfxTimer *source);
    // <group DOM_ImageFlow_VcpImageFlow_Implementation>
    static vrt_render_dirty_type_enum framePropertyEffectCallback(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size);
};



/***************************************************************************** 
 * Class VcpMyWheelMenu
 *****************************************************************************/
class VcpImageFlowWheel : public VcpWheelMenu
{

struct VcpImageFlowWheelUserData
{
    VfxS32 index;
    VfxS32 width;
    VfxS32 height;
    VfxS32 secondWidth;
    VfxS32 thirdWidth;
    VfxFloat upShift;
    VfxS32 focusUpShift;
    VfxFloat scaleSlope;
    VfxBool disable;
};

// Constructor / Destructor
public:
    // <group DOM_ImageFlow_VcpImageFlowWheel_Constructor/Destructor>
    VcpImageFlowWheel();
    // <group DOM_ImageFlow_VcpImageFlowWheel_Constructor/Destructor>
    virtual ~VcpImageFlowWheel(){}

// Method
public:
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // update Image Content when image is ready.
    // Because getImageContent() of IVcpImageFlowContentProvider may get a 
    // default image when image content is not ready. APP may call this 
    // function later when image content is ready.
    void updateImageContent(
        VfxS32 index,           // [IN] the index of image  
        VfxImageSrc &image      // [IN] the image content
        );
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // set content provider of VcpImageFlow
    void setContentProvider(
        IVcpImageFlowContentProvider *contentProvider // [IN] content provider 
        );
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // set focus index of VcpImageFlow. the cell of focus will put into center of view.
    void setFocusIndex(
        VfxS32 index            // [IN] the index of image
        );
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // set the total number of cells
    void setCellNumber(
        VfxS32 number           // [IN] number of cell
        );
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // set the width of cell which is not focused
    void setCellWidth(
        VfxS32 width            // [IN] width of cell which is unfocused
        );
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // set the height of cell
    void setCellHeight(
        VfxS32 height           // [IN] height of cell
        );
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // set the width of cell which is focused
    void setFocusCellWidth(
        VfxS32 width            // [IN] width of cell which is focused
        );
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // set the width of cell which is focused
    void setFocusCellHeight(
        VfxS32 height           // [IN] height of cell which is focused
        );
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // set total number of cell, width of cell which is focused/unfocused and height of cell.
    void setCellParameter(
        VfxS32 number,          // [IN] number of cell
        VfxS32 focusCellWidth,  // [IN] width of cell which is focused
        VfxS32 focusCellHeight, // [IN] height of cell which is focused
        VfxS32 secCellWidth,    // [IN] width of cell which is next to focused cell 
        VfxS32 cellWidth,       // [IN] width of cell which is unfocused
        VfxS32 cellHeight       // [IN] height of cell
        );
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // set RotateAngle of unFocus cell. default value is 90. 
    void setRotateAngle(
        VfxFloat angle          // [IN] angle in degree
        );
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // set up shift of unFocus cell. 
    void setUpShift(
        VfxFloat upShift          // [IN] up shift
        );
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // set camera distance of VcpImageFlow. the camera distance will affect the perspective 
    // degree of the unFocus cell. if the distance is short, the perspective will strong. So
    // you can see the difference between near edge and far edge will become large. the 
    // default value of distance is 240.
    void setCameraDistance(
        VfxFloat distance       // [IN] camera distance
        );
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // set the number of cell which is out of screen for cached. if the number is too large,
    // it will create a lot of cells at the same time. it will affect the memory use and block
    // MMI task when create those cells.
    void setCachedCellNumber(
        VfxS32 number           // [IN] number of cells
        );
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // set the backward distance between focused cell and unfocused cell
    void setBackDistance(
        VfxFloat distance       // [IN] backward distance 
        );
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // set the shadow factor to change shadow length.
    void setShadowFactor(
        VfxFloat value          // [IN] shadow factor
        );
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // set the up Shift on Focus item.
    void setFocusUpShift(
        VfxS32 upShift          // [IN] up shift on focus item
        );
    
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // get focus index of VcpImageFlow.
    VfxS32 getFocusIndex() const;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // get the total number of cells
    VfxS32 getCellNumber() const;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // get the width of cell which is not focused
    VfxS32 getCellWidth() const;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // get the height of cell
    VfxS32 getCellHeight() const;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // get the width of cell which is focused
    VfxS32 getFocusCellWidth() const;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // get the height of cell which is focused
    VfxS32 getFocusCellHeight() const;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // get RotateAngle of unFocus cell.
    VfxFloat getRotateAngle() const;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // get camera distance of VcpImageFlow. 
    VfxFloat getCameraDistance() const;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // get the backward distance between focus cell and unfocus cell
    VfxFloat getBackDistance() const;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // get the shadow factor.
    VfxFloat getShadowFactor() const;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // get the up Shift on Focus item.
    VfxS32 getFocusUpShift() const;
    

    // <group DOM_ImageFlow_VcpImageFlowWheel_Method>
    // set all cell isCached attribute
    void setAllCellisCached(VfxBool value);

// Override
protected:
    // <group DOM_ImageFlow_VcpImageFlowWheel_Override>
    virtual void onInit();
    // <group DOM_ImageFlow_VcpImageFlowWheel_Override>
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

    // VcpWheelMenu virtual function

    // <group DOM_ImageFlow_VcpImageFlowWheel_Override>
    virtual VfxFrame* createCell(VfxS32 cell, VfxS32 subCell);
    // <group DOM_ImageFlow_VcpImageFlowWheel_Override>
    virtual void onUpdateCell(VfxS32 cell, VfxS32 subcell, VfxFrame* frame);
    // <group DOM_ImageFlow_VcpImageFlowWheel_Override>
    virtual void onCloseCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame);
    // <group DOM_ImageFlow_VcpImageFlowWheel_Override>
    virtual void onFocusIndexChange(VfxS32 focusItem, VfxS32 previousFocusItem);
    // <group DOM_ImageFlow_VcpImageFlowWheel_Override>
    virtual void onDragEnd(VfxS32 xspeed, VfxS32 yspeed);
    // <group DOM_ImageFlow_VcpImageFlowWheel_Override>
    virtual void onDrag(VfxS32 xoffset, VfxS32 yoffset);
    // <group DOM_ImageFlow_VcpImageFlowWheel_Override>
    virtual void onTap(VfxPoint pt);
    // <group DOM_ImageFlow_VcpImageFlowWheel_Override>
    virtual VfxS32 getCount();
    // <group DOM_ImageFlow_VcpImageFlowWheel_Override>
    virtual VfxS32 getBehindCount();
    // <group DOM_ImageFlow_VcpImageFlowWheel_Override>
    virtual VfxS32 getAheadCount();

    // <group DOM_ImageFlow_VcpImageFlowWheel_Override>
    static vrt_render_dirty_type_enum myFrameEffectCB(
        VfxS32                              cell,           // [IN] the cell index
        VfxS32                              subCell,        // [IN] the sub cell index
        VfxFloat                            cellRelPos,     // [IN] the cell position
        vrt_frame_visual_property_struct    *target_frame,  // [IN] the cell frame
        VfxFloat                            fPos,           // [IN] animating index value
        VfxS32                              focus,          // [IN] the focus value of the menu
        VfxRect                             viewBounds,     // [IN] the menu bounds
        void                                *userData,      // [IN] user data
        VfxU32                              userDataSize,   // [IN] user data size
        VcpWheelMenuState                   state,          // [IN] the state of Menu
        VfxFloat                            level           // [IN] the level of state
        );
   
    // <group DOM_ImageFlow_VcpImageFlowWheel_Override>
    virtual VcpWheelMenuFrameEffectCBFuncPtr getFrameEffectCB();
    // <group DOM_ImageFlow_VcpImageFlowWheel_Override>
    virtual void onUpdate();

// Variable
public:
    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    // when user tap the focused cell, m_signalSelected will emit.
    VfxSignal3 <VcpImageFlowWheel *, VfxFrame*, VfxS32> m_signalSelected;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    // when the focus index changed, m_signalFocusChanged will emit.
    VfxSignal2 <VcpImageFlowWheel *, VfxS32> m_signalFocusChanged;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    // when the cell of index is closed, m_signalCellClosed will emit.
    VfxSignal2 <VcpImageFlowWheel *, VfxS32> m_signalCellClosed;

private:  
    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    VfxMatrix4x4 m_compositeMatrix;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    VfxMatrix4x4 m_centerMatrix;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    VfxMatrix4x4 m_leftMatrix;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    VfxMatrix4x4 m_rightMatrix;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    VfxTransform m_centerTransform;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    VfxTransform m_leftTransform;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    VfxTransform m_rightTransform;

    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    VfxS32       m_count;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    VfxS32       m_focusCellWidth;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    VfxS32       m_focusCellHeight;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    VfxS32       m_cellWidth;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    VfxS32       m_cellHeight;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    VfxS32       m_secCellWidth;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    VfxS32       m_secCellHeight;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    VfxFloat     m_rotateAngle;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    VfxFloat     m_upShift;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    VfxFloat     m_cameraDistance;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    VfxFloat     m_backDistance;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    VfxBool      m_updateBackDistance;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    VfxS32       m_shift;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    VfxFloat     m_shadowFactor;
    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    VfxS32       m_focusUpShift;

    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    IVcpImageFlowContentProvider *m_contentProvider;

    // <group DOM_ImageFlow_VcpImageFlowWheel_Variable>
    VfxTimer     *m_animationTimer;
    
// Implementation
private:

    // <group DOM_ImageFlow_VcpImageFlowWheel_Implementation>
    void updateTransform();
    // <group DOM_ImageFlow_VcpImageFlowWheel_Implementation>
    void adjustRenderSequence();
    // <group DOM_ImageFlow_VcpImageFlowWheel_Implementation>
    void setAllAutoAnimate(VfxBool value);
    // <group DOM_ImageFlow_VcpImageFlowWheel_Implementation>
    void onAnimationTimerStop(VfxTimer *source);
    // <group DOM_ImageFlow_VcpImageFlowWheel_Implementation>
    static vrt_render_dirty_type_enum framePropertyEffectCallback(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size);
};

#endif /* __VCP_IMAGE_FLOW_MAIN_H__ */

