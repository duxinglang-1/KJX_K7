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
 *  vcp_page_menu_transition.h
 *
 * Project:
 * --------
 *  Cosmos Launcher 2.0 - Main Menu
 *
 * Description:
 * ------------
 *  Transition effect of page swipe
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
 *****************************************************************************/

#ifndef __VCP_PAGE_MENU_TRANSITION_H__
#define __VCP_PAGE_MENU_TRANSITION_H__

#include "MMI_features.h"

#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)

#if defined(__MMI_VUI_3D_MAINMENU__) || defined(__COSMOS_MMI__)|| defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_VUI_LAUNCHER_KEY__)


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vrt_datatype.h"
#include "vfx_object.h"
#include "vcp_page_menu_util.h"


/*****************************************************************************
 * Macro
 *****************************************************************************/

#define __VCP_PAGE_MENU_TRANSITION_BALL__
#define __VCP_PAGE_MENU_TRANSITION_SPACE_BEAM__
#define __VCP_PAGE_MENU_TRANSITION_JUMP_UP__
#define __VCP_PAGE_MENU_TRANSITION_PHOTO_TILT__
#if defined __VCP_PAGE_MENU_TRANSITION_PHOTO_TILT__
    #define __VCP_PAGE_MENU_TRANSITION_WAVE__
#endif
#define __VCP_PAGE_MENU_TRANSITION_ROLL__
#define __VCP_PAGE_MENU_TRANSITION_SLIDE_DOWN__
#if defined __VCP_PAGE_MENU_TRANSITION_SLIDE_DOWN__
    #define __VCP_PAGE_MENU_TRANSITION_SLIDE_UP__
#endif
#define __VCP_PAGE_MENU_TRANSITION_COLLECTION_MM__
#if defined __VCP_PAGE_MENU_TRANSITION_COLLECTION_MM__
    #define __VCP_PAGE_MENU_TRANSITION_COLLECTION_TB__
#endif
#define __VCP_PAGE_MENU_TRANSITION_CYLINDER__
#define __VCP_PAGE_MENU_TRANSITION_TORNADO__
#define __VCP_PAGE_MENU_TRANSITION_CUBE__

// Macro to add a transition object create function
#define VCP_PAGE_MENU_TRANSITION_OBJ_ADD(_imageId, _stringId, _className)                                            \
    _imageId, _stringId, _className##CreateFunc

// Macro to declare a transition object create function
#define VCP_PAGE_MENU_TRANSITION_OBJ_DECLARE(_className)                        \
    extern VcpPageMenuTransition *_className##CreateFunc(VfxObject *parentObj);

// Macro to implement a transition object create function.
#define VCP_PAGE_MENU_TRANSITION_OBJ_IMPLEMENT(_className)                      \
    VcpPageMenuTransition *_className##CreateFunc(VfxObject *parentObj)         \
    {                                                                           \
        VcpPageMenuTransition *transition = NULL;                               \
        VFX_OBJ_CREATE(transition, _className, parentObj);                      \
        return transition;                                                      \
    }


/*****************************************************************************
 * Enum
 *****************************************************************************/

enum VcpPageMenuTransitionType
{
    VCP_PAGE_MENU_TRANSITION_TYPE_NORMAL = 0,

    // Add new transition below this line
#ifdef __VCP_PAGE_MENU_TRANSITION_BALL__
    VCP_PAGE_MENU_TRANSITION_TYPE_BALL,
#endif
#ifdef __VCP_PAGE_MENU_TRANSITION_SPACE_BEAM__
    VCP_PAGE_MENU_TRANSITION_TYPE_SPACE_BEAM,
#endif
#ifdef __VCP_PAGE_MENU_TRANSITION_JUMP_UP__
    VCP_PAGE_MENU_TRANSITION_TYPE_JUMP_UP,
#endif
#ifdef __VCP_PAGE_MENU_TRANSITION_WAVE__
    VCP_PAGE_MENU_TRANSITION_TYPE_WAVE,
#endif
#ifdef __VCP_PAGE_MENU_TRANSITION_PHOTO_TILT__
    VCP_PAGE_MENU_TRANSITION_TYPE_PHOTO_TILT,
#endif
#ifdef __VCP_PAGE_MENU_TRANSITION_ROLL__
    VCP_PAGE_MENU_TRANSITION_TYPE_ROLL,
#endif
#ifdef __VCP_PAGE_MENU_TRANSITION_SLIDE_DOWN__
    VCP_PAGE_MENU_TRANSITION_TYPE_SLIDE_DOWN,
#endif
#ifdef __VCP_PAGE_MENU_TRANSITION_SLIDE_UP__
    VCP_PAGE_MENU_TRANSITION_TYPE_SLIDE_UP,
#endif
#ifdef __VCP_PAGE_MENU_TRANSITION_COLLECTION_MM__
    VCP_PAGE_MENU_TRANSITION_TYPE_COLLECTION_MM,
#endif
#ifdef __VCP_PAGE_MENU_TRANSITION_COLLECTION_TB__
    VCP_PAGE_MENU_TRANSITION_TYPE_COLLECTION_TB,
#endif
#ifdef __VCP_PAGE_MENU_TRANSITION_CYLINDER__
    VCP_PAGE_MENU_TRANSITION_TYPE_CYLINDER,
#endif
#ifdef __VCP_PAGE_MENU_TRANSITION_TORNADO__
    VCP_PAGE_MENU_TRANSITION_TYPE_TORNADO,
#endif
#ifdef __VCP_PAGE_MENU_TRANSITION_CUBE__
    VCP_PAGE_MENU_TRANSITION_TYPE_CUBE,
#endif
    // Add new transition above this line
    VCP_PAGE_MENU_TRANSITION_TYPE_MAX
};


/*****************************************************************************
 * Structure
 *****************************************************************************/
struct VcpPageMenuTransitionInfo
{
    VcpPageMenuTransitionType   typeId;
    VfxResId                    imageId;
    VfxResId                    stringId;
};


/*****************************************************************************
 * Global Function
 *****************************************************************************/

VfxU32 vcpPageMenuGetTransitionNum();
VfxBool vcpPageMenuGetTransitionInfoList(VcpPageMenuTransitionInfo *transitionInfoList, VfxU32 num);
VcpPageMenuTransition * vcpPageMenuCreateTransition(VcpPageMenuTransitionType type, VfxObject *parent);


/*****************************************************************************
 * Class VcpPageMenuTransition
 *****************************************************************************/

class VcpPageMenuTransition : public VfxObject
{
public:
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float t,
        VfxS32 direction,
        vrt_s32 indexX, vrt_s32 indexY,
        const VcpPageMenuLayout & layout,
        vrt_s32 mainmenuWidth,
        vrt_s32 mainmenuHeight,
        vrt_frame_visual_property_struct *target_frame) const = 0;

    virtual void onInitTransition(
        const VcpPageMenuLayout & layout,
        vrt_s32 mainmenuWidth,
        vrt_s32 mainmenuHeight) {}
};

#ifdef __VCP_PAGE_MENU_TRANSITION_BALL__

/*****************************************************************************
 * Class VcpPageMenuBallTransition
 *****************************************************************************/

VCP_PAGE_MENU_TRANSITION_OBJ_DECLARE(VcpPageMenuBallTransition);

class VcpPageMenuBallTransition : public VcpPageMenuTransition
{
public:
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float t,
        VfxS32 direction,
        vrt_s32 indexX, vrt_s32 indexY,
        const VcpPageMenuLayout & layout,
        vrt_s32 mainmenuWidth,
        vrt_s32 mainmenuHeight,
        vrt_frame_visual_property_struct *target_frame) const;

    virtual void onInitTransition(
        const VcpPageMenuLayout & layout,
        vrt_s32 mainmenuWidth,
        vrt_s32 mainmenuHeight);

private:
    VfxMatrix4x4 m_camera;
    // current only support max 5x5 menu
    VfxMatrix4x4 m_model[5][5]; 
};

#endif//__VCP_PAGE_MENU_TRANSITION_BALL__

#ifdef __VCP_PAGE_MENU_TRANSITION_SPACE_BEAM__

/*****************************************************************************
 * Class VcpPageMenuSpaceBeamTransition
 *****************************************************************************/

VCP_PAGE_MENU_TRANSITION_OBJ_DECLARE(VcpPageMenuSpaceBeamTransition);

class VcpPageMenuSpaceBeamTransition : public VcpPageMenuTransition
{
public:
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float t,
        VfxS32 direction,
        vrt_s32 indexX, vrt_s32 indexY,
        const VcpPageMenuLayout & layout,
        vrt_s32 mainmenuWidth,
        vrt_s32 mainmenuHeight,
        vrt_frame_visual_property_struct *target_frame) const;
};

#endif//__VCP_PAGE_MENU_TRANSITION_SPACE_BEAM__

#ifdef __VCP_PAGE_MENU_TRANSITION_JUMP_UP__

/*****************************************************************************
 * Class VcpPageMenuJumpUpTransition
 *****************************************************************************/

VCP_PAGE_MENU_TRANSITION_OBJ_DECLARE(VcpPageMenuJumpUpTransition);

class VcpPageMenuJumpUpTransition : public VcpPageMenuTransition
{
public:
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float t,
        VfxS32 direction,
        vrt_s32 indexX, vrt_s32 indexY,
        const VcpPageMenuLayout & layout,
        vrt_s32 mainmenuWidth,
        vrt_s32 mainmenuHeight,
        vrt_frame_visual_property_struct *target_frame) const;
};

#endif//__VCP_PAGE_MENU_TRANSITION_JUMP_UP__

#ifdef __VCP_PAGE_MENU_TRANSITION_PHOTO_TILT__

/*****************************************************************************
 * Class VcpPageMenuTiltTransition
 *****************************************************************************/

VCP_PAGE_MENU_TRANSITION_OBJ_DECLARE(VcpPageMenuTiltTransition);

class VcpPageMenuTiltTransition : public VcpPageMenuTransition
{
public:
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float t,
        VfxS32 direction,
        vrt_s32 indexX, vrt_s32 indexY,
        const VcpPageMenuLayout & layout,
        vrt_s32 mainmenuWidth,
        vrt_s32 mainmenuHeight,
        vrt_frame_visual_property_struct *target_frame) const;

     virtual void onInitTransition(
        const VcpPageMenuLayout & layout,
        vrt_s32 mainmenuWidth,
        vrt_s32 mainmenuHeight);

protected:
    virtual void onInit();

protected:
    VfxS32 m_photoWallType;
private:
    VfxMatrix4x4 m_camera;
};

#endif//__VCP_PAGE_MENU_TRANSITION_PHOTO_TILT__

#ifdef __VCP_PAGE_MENU_TRANSITION_WAVE__

/*****************************************************************************
 * Class VcpPageMenuWaveTransition
 *****************************************************************************/

VCP_PAGE_MENU_TRANSITION_OBJ_DECLARE(VcpPageMenuWaveTransition);

class VcpPageMenuWaveTransition : public VcpPageMenuTiltTransition
{
protected:
    virtual void onInit();
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
#endif

#endif//__VCP_PAGE_MENU_TRANSITION_WAVE__

#ifdef __VCP_PAGE_MENU_TRANSITION_ROLL__

/*****************************************************************************
 * Class VcpPageMenuRollTransition
 *****************************************************************************/

VCP_PAGE_MENU_TRANSITION_OBJ_DECLARE(VcpPageMenuRollTransition);

class VcpPageMenuRollTransition : public VcpPageMenuTransition
{
public:
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float t,
        VfxS32 direction,
        vrt_s32 indexX, vrt_s32 indexY,
        const VcpPageMenuLayout & layout,
        vrt_s32 mainmenuWidth,
        vrt_s32 mainmenuHeight,
        vrt_frame_visual_property_struct *target_frame) const;
};

#endif//__VCP_PAGE_MENU_TRANSITION_ROLL__

#ifdef __VCP_PAGE_MENU_TRANSITION_SLIDE_DOWN__

/*****************************************************************************
 * Class VcpPageMenuSlideDownTransition
 *****************************************************************************/

VCP_PAGE_MENU_TRANSITION_OBJ_DECLARE(VcpPageMenuSlideDownTransition);

class VcpPageMenuSlideDownTransition : public VcpPageMenuTransition
{
public:
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float t,
        VfxS32 direction,
        vrt_s32 indexX, vrt_s32 indexY,
        const VcpPageMenuLayout & layout,
        vrt_s32 mainmenuWidth,
        vrt_s32 mainmenuHeight,
        vrt_frame_visual_property_struct *target_frame) const;
    
protected:
        virtual void onInit();

protected:
        VfxS32 m_slideType;

};

#endif//__VCP_PAGE_MENU_TRANSITION_ROLL__

#ifdef __VCP_PAGE_MENU_TRANSITION_SLIDE_UP__

/*****************************************************************************
 * Class VcpPageMenuSlideUpTransition
 *****************************************************************************/

VCP_PAGE_MENU_TRANSITION_OBJ_DECLARE(VcpPageMenuSlideUpTransition);

class VcpPageMenuSlideUpTransition : public VcpPageMenuSlideDownTransition
{
protected:
        virtual void onInit();
};

#endif//__VCP_PAGE_MENU_TRANSITION_SLIDE_UP__

#ifdef __VCP_PAGE_MENU_TRANSITION_COLLECTION_MM__

/*****************************************************************************
 * Class VcpPageMenuCollectionMMTransition
 *****************************************************************************/

VCP_PAGE_MENU_TRANSITION_OBJ_DECLARE(VcpPageMenuCollectionMMTransition);

class VcpPageMenuCollectionMMTransition : public VcpPageMenuTransition
{
public:
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float t,
        VfxS32 direction,
        vrt_s32 indexX, vrt_s32 indexY,
        const VcpPageMenuLayout & layout,
        vrt_s32 mainmenuWidth,
        vrt_s32 mainmenuHeight,
        vrt_frame_visual_property_struct *target_frame) const;
    
protected:
        virtual void onInit();
    
protected:
        VfxS32 m_collectionType;
};

#endif//__VCP_PAGE_MENU_TRANSITION_COLLECTION_MM__

#ifdef __VCP_PAGE_MENU_TRANSITION_COLLECTION_TB__

/*****************************************************************************
 * Class VcpPageMenuCollectionTBTransition
 *****************************************************************************/

VCP_PAGE_MENU_TRANSITION_OBJ_DECLARE(VcpPageMenuCollectionTBTransition);

class VcpPageMenuCollectionTBTransition : public VcpPageMenuCollectionMMTransition
{
protected:
        virtual void onInit();
};

#endif//__VCP_PAGE_MENU_TRANSITION_COLLECTION_TB__

#ifdef __VCP_PAGE_MENU_TRANSITION_CYLINDER__

/*****************************************************************************
 * Class VcpPageMenuCylinderTransition
 *****************************************************************************/

VCP_PAGE_MENU_TRANSITION_OBJ_DECLARE(VcpPageMenuCylinderTransition);

class VcpPageMenuCylinderTransition : public VcpPageMenuTransition
{
public:
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float t,
        VfxS32 direction,
        vrt_s32 indexX, vrt_s32 indexY,
        const VcpPageMenuLayout & layout,
        vrt_s32 mainmenuWidth,
        vrt_s32 mainmenuHeight,
        vrt_frame_visual_property_struct *target_frame) const;

virtual void onInitTransition(
        const VcpPageMenuLayout & layout,
        vrt_s32 mainmenuWidth,
        vrt_s32 mainmenuHeight);

private:
    VfxMatrix4x4 m_camera;
    // current only support max 5x5 menu
    VfxMatrix4x4 m_model[5][5]; 
};

#endif//__VCP_PAGE_MENU_TRANSITION_CYLINDER__

#ifdef __VCP_PAGE_MENU_TRANSITION_TORNADO__

/*****************************************************************************
 * Class VcpPageMenuTornadoTransition
 *****************************************************************************/

VCP_PAGE_MENU_TRANSITION_OBJ_DECLARE(VcpPageMenuTornadoTransition);

class VcpPageMenuTornadoTransition : public VcpPageMenuTransition
{
public:
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float t,
        VfxS32 direction,
        vrt_s32 indexX, vrt_s32 indexY,
        const VcpPageMenuLayout & layout,
        vrt_s32 mainmenuWidth,
        vrt_s32 mainmenuHeight,
        vrt_frame_visual_property_struct *target_frame) const;

virtual void onInitTransition(
        const VcpPageMenuLayout & layout,
        vrt_s32 mainmenuWidth,
        vrt_s32 mainmenuHeight);

private:
    VfxMatrix4x4 m_camera;

};

#endif//__VCP_PAGE_MENU_TRANSITION_TORNADO__

#ifdef __VCP_PAGE_MENU_TRANSITION_CUBE__

/*****************************************************************************
 * Class VcpPageMenuCubeTransition
 *****************************************************************************/

VCP_PAGE_MENU_TRANSITION_OBJ_DECLARE(VcpPageMenuCubeTransition);

class VcpPageMenuCubeTransition : public VcpPageMenuTransition
{
public:
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float t,
        VfxS32 direction,
        vrt_s32 indexX, vrt_s32 indexY,
        const VcpPageMenuLayout & layout,
        vrt_s32 mainmenuWidth,
        vrt_s32 mainmenuHeight,
        vrt_frame_visual_property_struct *target_frame) const;

protected:
    virtual void onInit();

protected:
    VfxFloat m_angle;

};



/*****************************************************************************
 * Class VcpPageMenuHexagonalPrismTransition
 *****************************************************************************/

VCP_PAGE_MENU_TRANSITION_OBJ_DECLARE(VcpPageMenuHexagonalPrismTransition);

class VcpPageMenuHexagonalPrismTransition : public VcpPageMenuCubeTransition
{
protected:
    virtual void onInit();
};

#endif//__VCP_PAGE_MENU_TRANSITION_CUBE__

#endif // defined(__MMI_VUI_3D_MAINMENU__) || defined(__COSMOS_MMI__) || defined(__MMI_VUI_LAUNCHER__)|| defined(__MMI_VUI_LAUNCHER_KEY__)

#endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__

#endif // __VCP_PAGE_MENU_TRANSITION_H__

