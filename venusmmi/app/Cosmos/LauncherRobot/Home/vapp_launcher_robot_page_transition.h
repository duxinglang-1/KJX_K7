/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_launcher_robot_page_transition.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the desktop page transition.
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

#ifndef VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_H
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_H

#include "MMI_features.h"
#include "vfx_uc_include.h"

#include "vapp_launcher_robot_def.h"
#include "vapp_launcher_robot_page_transition_def.h"


/*****************************************************************************
 * Include
 *****************************************************************************/


/*****************************************************************************
 * Define
 *****************************************************************************/
#define VAPP_HOME_DESKTOP_PAGE_BG_OPACITY 0.3

class VappLauncherRobotDesktop;
class VappLauncherRobotDesktopPage;
class VappLauncherRobotPageTransition;


typedef struct
{
    VfxS32 totalPage;
    VfxS32 pageWidth;
    VfxS32 pageHeight;
    VappLauncherRobotPageTransition *transitionEffect;
} VappLauncherRobotPageTransPara;


/*****************************************************************************
 * VappLauncherRobotPageTransition Base Class
 *****************************************************************************/

/*
 * Macro to declare a page transition class
 */
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_DECLARE_CLASS(_className)      \
                                                                            \
    VFX_DECLARE_CLASS(_className);                                          \
                                                                            \
    public:                                                                 \
        static VappLauncherRobotPageTransition *createPageTransition(VfxObject *parentObj)


/*
 * Macro to implement a page transition class.
 */
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_IMPLEMENT_CLASS(_className, _parentClassName)      \
                                                                                                \
    VFX_IMPLEMENT_CLASS(#_className, _className, _parentClassName);                             \
                                                                                                \
    VappLauncherRobotPageTransition *_className::createPageTransition(VfxObject *parentObj)    \
    {                                                                                           \
        _className *VappLauncherRobotPageTransition;                                           \
        VFX_OBJ_CREATE(VappLauncherRobotPageTransition, _className, parentObj);                \
        return VappLauncherRobotPageTransition;                                                \
    }

/*****************************************************************************
 * Class VappLauncherRobotPageTransition
 *****************************************************************************/

class VappLauncherRobotPageTransition : public VfxObject
{
    VFX_DECLARE_CLASS(VappLauncherRobotPageTransition);
    
public:
    virtual VappRobotPageTransitionTypeEnum getId() const = 0;
    
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float ratio,
        vrt_float t,
        vrt_s32 homeWidth,
        vrt_s32 homeHeight,
        vrt_s32 oriDesktopBoundsX,
        vrt_s32 nexDesktopBoundsX,
        vrt_s32 totalTranslateLength,
        vrt_frame_visual_property_struct *target_frame
    ) const = 0;

    virtual void onInitTransition(
            VfxS32 homeWidth,
            VfxS32 homeHeight,
            VfxS32 maxNumDesktopPage){};

    // for slim project, cache memory is not enough, so reduce page during animation
    // in this scenario, transform matrix needs to adjust by origin/resize page size
    virtual void onInitTransitionForSlim(
            VfxRect oriPageRect,
            VfxRect resizePageRect){};

    virtual vrt_bool isShowPageBgDuringSlide(){return VRT_FALSE;}
    virtual vrt_bool isShowAllPage(){return VRT_FALSE;}

    // default support quick swipe
    virtual vrt_bool isSupportQuickSwipe(){return VFX_TRUE;}
    virtual vrt_bool isResizePageForSlim(){return VRT_FALSE;}
    virtual VfxS32 getExtendAnimationTime(){return 1;}

    virtual VfxFrameCullingTypeEnum getCullingType(){return VFX_FRAME_CULLING_TYPE_BACK;}
};


/*****************************************************************************
 * Normal Transition Class
 *****************************************************************************/

class VappLauncherRobotPageTransitionNormal : public VappLauncherRobotPageTransition
{
    VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_DECLARE_CLASS(VappLauncherRobotPageTransitionNormal);
    
public:
    virtual VappRobotPageTransitionTypeEnum getId() const {return VAPP_PAGE_TRANSITION_TYPE_NORMAL;}
    
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float ratio,
        vrt_float t,
        vrt_s32 homeWidth,
        vrt_s32 homeHeight,
        vrt_s32 oriDesktopBoundsX,
        vrt_s32 nexDesktopBoundsX,
        vrt_s32 totalTranslateLength,
        vrt_frame_visual_property_struct *target_frame
    ) const;

    virtual vrt_bool isSupportQuickSwipe(){return VFX_FALSE;}
};


/*****************************************************************************
 * Photo Wall Transition Class
 *****************************************************************************/

class VappLauncherRobotPageTransitionPhotoWall : public VappLauncherRobotPageTransition
{
    VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_DECLARE_CLASS(VappLauncherRobotPageTransitionPhotoWall);
    
public:
    virtual VappRobotPageTransitionTypeEnum getId() const {return VAPP_PAGE_TRANSITION_TYPE_PHOTO_WALL;}
    
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float ratio,
        vrt_float t,
        vrt_s32 homeWidth,
        vrt_s32 homeHeight,
        vrt_s32 oriDesktopBoundsX,
        vrt_s32 nexDesktopBoundsX,
        vrt_s32 totalTranslateLength,
        vrt_frame_visual_property_struct *target_frame
    ) const;

private:
    const static VfxS32 s_transitionPhotoWallType;
};


/*****************************************************************************
 * Robot Transition Class
 *****************************************************************************/

class VappLauncherRobotPageTransitionRobot : public VappLauncherRobotPageTransition
{
    VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_DECLARE_CLASS(VappLauncherRobotPageTransitionRobot);
    
public:
    virtual VappRobotPageTransitionTypeEnum getId() const {return VAPP_PAGE_TRANSITION_TYPE_ROBOT;}
    
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float ratio,
        vrt_float t,
        vrt_s32 homeWidth,
        vrt_s32 homeHeight,
        vrt_s32 oriDesktopBoundsX,
        vrt_s32 nexDesktopBoundsX,
        vrt_s32 totalTranslateLength,
        vrt_frame_visual_property_struct *target_frame
    ) const;
    
protected:
    virtual void onInit();

protected:
    VfxFloat m_angle;

};


/*****************************************************************************
 * Class VappLauncherRobotPageTransitionPentangleZoomIn
 *****************************************************************************/

class VappLauncherRobotPageTransitionPentangleZoomIn : public VappLauncherRobotPageTransition
{
    VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_DECLARE_CLASS(VappLauncherRobotPageTransitionPentangleZoomIn);

protected:
    virtual void onDeinit();

public:
    virtual VappRobotPageTransitionTypeEnum getId() const {return VAPP_PAGE_TRANSITION_TYPE_PENTANGLE_ZOOM_IN;}
    
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float ratio,
        vrt_float t,
        vrt_s32 homeWidth,
        vrt_s32 homeHeight,
        vrt_s32 oriDesktopBoundsX,
        vrt_s32 nexDesktopBoundsX,
        vrt_s32 totalTranslateLength,
        vrt_frame_visual_property_struct *target_frame
        ) const;

    virtual void onInitTransition(
            VfxS32 homeWidth,
            VfxS32 homeHeight,
            VfxS32 maxNumDesktopPage);

private:
    VfxS32 m_maxNumDesktopPage;
    VfxMatrix4x4 **m_model;
};


/*****************************************************************************
 * Class VappLauncherRobotPageTransitionTrangleZoomIn
 *****************************************************************************/

class VappLauncherRobotPageTransitionTrangleZoomIn : public VappLauncherRobotPageTransition
{
    VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_DECLARE_CLASS(VappLauncherRobotPageTransitionTrangleZoomIn);

public:
    virtual VappRobotPageTransitionTypeEnum getId() const {return VAPP_PAGE_TRANSITION_TYPE_TRANGLE_ZOOM_IN;}
    
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float ratio,
        vrt_float t,
        vrt_s32 homeWidth,
        vrt_s32 homeHeight,
        vrt_s32 oriDesktopBoundsX,
        vrt_s32 nexDesktopBoundsX,
        vrt_s32 totalTranslateLength,
        vrt_frame_visual_property_struct *target_frame
        ) const;

    virtual void onInitTransition(
            VfxS32 homeWidth,
            VfxS32 homeHeight,
            VfxS32 maxNumDesktopPage);
    
    virtual vrt_bool isShowAllPage(){return VFX_TRUE;}

private:
    VfxS32 m_maxNumDesktopPage;
    VfxMatrix4x4 **m_model;
};


#if !defined(VAPP_LAUNCHER_ROBOT_REDUCE_PAGE_SIZE_DURING_TRANSITION)
/*****************************************************************************
 * Class VappLauncherRobotPageTransitionCylinder
 *****************************************************************************/

class VappLauncherRobotPageTransitionCylinder : public VappLauncherRobotPageTransition
{
    VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_DECLARE_CLASS(VappLauncherRobotPageTransitionCylinder);

protected:
    virtual void onDeinit();

public:
    virtual VappRobotPageTransitionTypeEnum getId() const {return VAPP_PAGE_TRANSITION_TYPE_CYLINDER;}
    
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float ratio,
        vrt_float t,
        vrt_s32 homeWidth,
        vrt_s32 homeHeight,
        vrt_s32 oriDesktopBoundsX,
        vrt_s32 nexDesktopBoundsX,
        vrt_s32 totalTranslateLength,
        vrt_frame_visual_property_struct *target_frame
        ) const;

    virtual void onInitTransition(
            VfxS32 homeWidth,
            VfxS32 homeHeight,
            VfxS32 maxNumDesktopPage);
    
    virtual vrt_bool isShowAllPage(){return VFX_TRUE;}
    virtual vrt_bool isShowPageBgDuringSlide(){return VRT_TRUE;}
    virtual VfxS32 getExtendAnimationTime(){return 6;}
    virtual VfxFrameCullingTypeEnum getCullingType(){return VFX_FRAME_CULLING_TYPE_NONE;}

private:
    VfxS32 m_maxNumDesktopPage;
    VfxMatrix4x4 **m_model;
};


/*****************************************************************************
 * Class VappLauncherRobotPageTransitionPentangleZoomOut
 *****************************************************************************/

class VappLauncherRobotPageTransitionPentangleZoomOut : public VappLauncherRobotPageTransition
{
    VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_DECLARE_CLASS(VappLauncherRobotPageTransitionPentangleZoomOut);

protected:
    virtual void onDeinit();

public:
    virtual VappRobotPageTransitionTypeEnum getId() const {return VAPP_PAGE_TRANSITION_TYPE_PENTANGLE_ZOOM_OUT;}
    
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float ratio,
        vrt_float t,
        vrt_s32 homeWidth,
        vrt_s32 homeHeight,
        vrt_s32 oriDesktopBoundsX,
        vrt_s32 nexDesktopBoundsX,
        vrt_s32 totalTranslateLength,
        vrt_frame_visual_property_struct *target_frame
        ) const;

    virtual void onInitTransition(
            VfxS32 homeWidth,
            VfxS32 homeHeight,
            VfxS32 maxNumDesktopPage);
    
    virtual vrt_bool isShowAllPage(){return VFX_TRUE;}
    virtual vrt_bool isShowPageBgDuringSlide(){return VRT_TRUE;}
    virtual VfxS32 getExtendAnimationTime(){return 6;}
    virtual VfxFrameCullingTypeEnum getCullingType(){return VFX_FRAME_CULLING_TYPE_NONE;}
    
private:
    VfxS32 m_maxNumDesktopPage;
    VfxMatrix4x4 **m_model;
};


/*****************************************************************************
 * Class VappLauncherRobotPageTransitionTrangleZoomOut
 *****************************************************************************/

class VappLauncherRobotPageTransitionTrangleZoomOut : public VappLauncherRobotPageTransition
{
    VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_DECLARE_CLASS(VappLauncherRobotPageTransitionTrangleZoomOut);

public:
    virtual VappRobotPageTransitionTypeEnum getId() const {return VAPP_PAGE_TRANSITION_TYPE_PENTANGLE_ZOOM_OUT;}
    
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float ratio,
        vrt_float t,
        vrt_s32 homeWidth,
        vrt_s32 homeHeight,
        vrt_s32 oriDesktopBoundsX,
        vrt_s32 nexDesktopBoundsX,
        vrt_s32 totalTranslateLength,
        vrt_frame_visual_property_struct *target_frame
        ) const;

    virtual void onInitTransition(
            VfxS32 homeWidth,
            VfxS32 homeHeight,
            VfxS32 maxNumDesktopPage);

    virtual vrt_bool isShowAllPage(){return VFX_TRUE;}
    virtual vrt_bool isShowPageBgDuringSlide(){return VRT_TRUE;}
    virtual VfxS32 getExtendAnimationTime(){return 6;}
    virtual VfxFrameCullingTypeEnum getCullingType(){return VFX_FRAME_CULLING_TYPE_NONE;}
    
private:
    VfxS32 m_maxNumDesktopPage;
};


#else /* !defined(VAPP_LAUNCHER_ROBOT_REDUCE_PAGE_SIZE_DURING_TRANSITION) */


/*****************************************************************************
 * Class VappLauncherRobotPageTransitionCylinderSlim
 *****************************************************************************/

class VappLauncherRobotPageTransitionCylinderSlim : public VappLauncherRobotPageTransition
{
    VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_DECLARE_CLASS(VappLauncherRobotPageTransitionCylinderSlim);

protected:
    virtual void onDeinit();

public:
    virtual VappRobotPageTransitionTypeEnum getId() const {return VAPP_PAGE_TRANSITION_TYPE_CYLINDER_SLIM;}
    
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float ratio,
        vrt_float t,
        vrt_s32 homeWidth,
        vrt_s32 homeHeight,
        vrt_s32 oriDesktopBoundsX,
        vrt_s32 nexDesktopBoundsX,
        vrt_s32 totalTranslateLength,
        vrt_frame_visual_property_struct *target_frame
        ) const;

    virtual void onInitTransition(
            VfxS32 homeWidth,
            VfxS32 homeHeight,
            VfxS32 maxNumDesktopPage);
    
    virtual void onInitTransitionForSlim(
            VfxRect oriPageRect,
            VfxRect resizePageRect);
    
    virtual vrt_bool isShowAllPage(){return VFX_TRUE;}
    virtual vrt_bool isShowPageBgDuringSlide(){return VRT_TRUE;}
    virtual vrt_bool isResizePageForSlim(){return VRT_TRUE;}
    virtual VfxS32 getExtendAnimationTime(){return 6;}
    virtual VfxFrameCullingTypeEnum getCullingType(){return VFX_FRAME_CULLING_TYPE_NONE;}

private:
    VfxS32 m_maxNumDesktopPage;
    VfxMatrix4x4 **m_model;

    VfxRect m_oriPageRect;
    VfxRect m_resizePageRect;
};


/*****************************************************************************
 * Class VappLauncherRobotPageTransitionPentangleZoomOutSlim
 *****************************************************************************/

class VappLauncherRobotPageTransitionPentangleZoomOutSlim : public VappLauncherRobotPageTransition
{
    VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_DECLARE_CLASS(VappLauncherRobotPageTransitionPentangleZoomOutSlim);

protected:
    virtual void onDeinit();

public:
    virtual VappRobotPageTransitionTypeEnum getId() const {return VAPP_PAGE_TRANSITION_TYPE_PENTANGLE_ZOOM_OUT_SLIM;}
    
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float ratio,
        vrt_float t,
        vrt_s32 homeWidth,
        vrt_s32 homeHeight,
        vrt_s32 oriDesktopBoundsX,
        vrt_s32 nexDesktopBoundsX,
        vrt_s32 totalTranslateLength,
        vrt_frame_visual_property_struct *target_frame
        ) const;

    virtual void onInitTransition(
            VfxS32 homeWidth,
            VfxS32 homeHeight,
            VfxS32 maxNumDesktopPage);
    
    virtual void onInitTransitionForSlim(
            VfxRect oriPageRect,
            VfxRect resizePageRect);
    
    virtual vrt_bool isShowAllPage(){return VFX_TRUE;}
    virtual vrt_bool isShowPageBgDuringSlide(){return VRT_TRUE;}
    virtual vrt_bool isResizePageForSlim(){return VRT_TRUE;}
    virtual VfxS32 getExtendAnimationTime(){return 6;}
    virtual VfxFrameCullingTypeEnum getCullingType(){return VFX_FRAME_CULLING_TYPE_NONE;}
    
private:
    VfxS32 m_maxNumDesktopPage;
    VfxMatrix4x4 **m_model;

    VfxRect m_oriPageRect;
    VfxRect m_resizePageRect;
};


/*****************************************************************************
 * Class VappLauncherRobotPageTransitionTrangleZoomOutSlim
 *****************************************************************************/

class VappLauncherRobotPageTransitionTrangleZoomOutSlim : public VappLauncherRobotPageTransition
{
    VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_DECLARE_CLASS(VappLauncherRobotPageTransitionTrangleZoomOutSlim);

public:
    virtual VappRobotPageTransitionTypeEnum getId() const {return VAPP_PAGE_TRANSITION_TYPE_TRANGLE_ZOOM_OUT_SLIM;}
    
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float ratio,
        vrt_float t,
        vrt_s32 homeWidth,
        vrt_s32 homeHeight,
        vrt_s32 oriDesktopBoundsX,
        vrt_s32 nexDesktopBoundsX,
        vrt_s32 totalTranslateLength,
        vrt_frame_visual_property_struct *target_frame
        ) const;

    virtual void onInitTransition(
            VfxS32 homeWidth,
            VfxS32 homeHeight,
            VfxS32 maxNumDesktopPage);
    
    virtual void onInitTransitionForSlim(
            VfxRect oriPageRect,
            VfxRect resizePageRect);
    
    virtual vrt_bool isShowAllPage(){return VFX_TRUE;}
    virtual vrt_bool isShowPageBgDuringSlide(){return VRT_TRUE;}
    virtual vrt_bool isResizePageForSlim(){return VRT_TRUE;}
    virtual VfxS32 getExtendAnimationTime(){return 6;}
    virtual VfxFrameCullingTypeEnum getCullingType(){return VFX_FRAME_CULLING_TYPE_NONE;}
    
private:
    VfxS32 m_maxNumDesktopPage;
    VfxMatrix4x4 **m_model;

    VfxRect m_oriPageRect;
    VfxRect m_resizePageRect;
};
#endif /* !defined(VAPP_LAUNCHER_ROBOT_REDUCE_PAGE_SIZE_DURING_TRANSITION) */
#endif /* VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_H */
