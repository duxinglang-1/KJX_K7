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
 *  vcp_page_menu_transition.cpp
 *
 * Project:
 * --------
 *  Cosmos Launcher 2.0 - Main Menu
 *
 * Description:
 * ------------
 *  Transition effect of page menu swipe
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
 * removed!
 * removed!
 * removed!
 *
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

#include "MMI_features.h"

#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)

#if defined(__MMI_VUI_3D_MAINMENU__) || defined(__COSMOS_MMI__) || defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_VUI_LAUNCHER_KEY__)


/*****************************************************************************
 * Include
 *****************************************************************************/
 
#include "vrt_datatype.h"
#include "vfx_datatype.h"
#include "vfx_basic_type.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_transform.h"
#include "vcp_page_menu_transition.h"
#include "mmi_rp_vcp_page_menu_transition_def.h"


/*****************************************************************************
 * Typedef
 *****************************************************************************/

typedef VcpPageMenuTransition *(*VcpPageMenuTransitionObjCreateFunc)(VfxObject *parentObj);


/*****************************************************************************
 * Structure
 *****************************************************************************/
struct VcpPageMenuTransitionData
{
    VfxResId imageId;
    VfxResId stringId;
    VcpPageMenuTransitionObjCreateFunc createFunc;
};


/*****************************************************************************
 * Global Variable
 *****************************************************************************/

// Note: Transition order should be the same as VcpPageMenuTransitionType
static VcpPageMenuTransitionData s_vcpPageMenuTransitionTable[VCP_PAGE_MENU_TRANSITION_TYPE_MAX - 1] = {
#ifdef __VCP_PAGE_MENU_TRANSITION_BALL__
    // VCP_PAGE_MENU_TRANSITION_TYPE_BALL
    VCP_PAGE_MENU_TRANSITION_OBJ_ADD(IMG_ID_VCP_PAGE_MENU_TRANSITION_TYPE_BALL,
                                     STR_ID_VCP_PAGE_MENU_TRANSITION_TYPE_BALL,
                                     VcpPageMenuBallTransition),
#endif
#ifdef __VCP_PAGE_MENU_TRANSITION_SPACE_BEAM__
    // VCP_PAGE_MENU_TRANSITION_TYPE_SPACE_BEAM
    VCP_PAGE_MENU_TRANSITION_OBJ_ADD(IMG_ID_VCP_PAGE_MENU_TRANSITION_TYPE_SPACE_BEAM,
                                     STR_ID_VCP_PAGE_MENU_TRANSITION_TYPE_SPACE_BEAM,
                                     VcpPageMenuSpaceBeamTransition),
#endif
#ifdef __VCP_PAGE_MENU_TRANSITION_JUMP_UP__
    // VCP_PAGE_MENU_TRANSITION_TYPE_JUMP_UP
    VCP_PAGE_MENU_TRANSITION_OBJ_ADD(IMG_ID_VCP_PAGE_MENU_TRANSITION_TYPE_JUMP_UP,
                                     STR_ID_VCP_PAGE_MENU_TRANSITION_TYPE_JUMP_UP,
                                     VcpPageMenuJumpUpTransition),
#endif
#ifdef __VCP_PAGE_MENU_TRANSITION_WAVE__
    // VCP_PAGE_MENU_TRANSITION_TYPE_WAVE
    VCP_PAGE_MENU_TRANSITION_OBJ_ADD(IMG_ID_VCP_PAGE_MENU_TRANSITION_TYPE_WAVE,
                                     STR_ID_VCP_PAGE_MENU_TRANSITION_TYPE_WAVE,
                                     VcpPageMenuWaveTransition),
#endif
#ifdef __VCP_PAGE_MENU_TRANSITION_PHOTO_TILT__
    // VCP_PAGE_MENU_TRANSITION_TYPE_TILT
    VCP_PAGE_MENU_TRANSITION_OBJ_ADD(IMG_ID_VCP_PAGE_MENU_TRANSITION_TYPE_TILT,
                                     STR_ID_VCP_PAGE_MENU_TRANSITION_TYPE_TILT,
                                     VcpPageMenuTiltTransition),
#endif
#ifdef __VCP_PAGE_MENU_TRANSITION_ROLL__
    // VCP_PAGE_MENU_TRANSITION_TYPE_ROLL
    VCP_PAGE_MENU_TRANSITION_OBJ_ADD(IMG_ID_VCP_PAGE_MENU_TRANSITION_TYPE_ROLL,
                                     STR_ID_VCP_PAGE_MENU_TRANSITION_TYPE_ROLL,
                                     VcpPageMenuRollTransition),
#endif
#ifdef __VCP_PAGE_MENU_TRANSITION_SLIDE_DOWN__
    // VCP_PAGE_MENU_TRANSITION_TYPE_SLIDE_DOWN
    VCP_PAGE_MENU_TRANSITION_OBJ_ADD(IMG_ID_VCP_PAGE_MENU_TRANSITION_TYPE_SLIDE_DOWN,
                                     STR_ID_VCP_PAGE_MENU_TRANSITION_TYPE_SLIDE_DOWN,
                                     VcpPageMenuSlideDownTransition),
#endif
#ifdef __VCP_PAGE_MENU_TRANSITION_SLIDE_UP__
    // VCP_PAGE_MENU_TRANSITION_TYPE_SLIDE_UP
    VCP_PAGE_MENU_TRANSITION_OBJ_ADD(IMG_ID_VCP_PAGE_MENU_TRANSITION_TYPE_SLIDE_UP,
                                     STR_ID_VCP_PAGE_MENU_TRANSITION_TYPE_SLIDE_UP,
                                     VcpPageMenuSlideUpTransition),
#endif
#ifdef __VCP_PAGE_MENU_TRANSITION_COLLECTION_MM__
    // VCP_PAGE_MENU_TRANSITION_TYPE_COLLECTION_MM
    VCP_PAGE_MENU_TRANSITION_OBJ_ADD(IMG_ID_VCP_PAGE_MENU_TRANSITION_TYPE_COLLECTION_MM,
                                     STR_ID_VCP_PAGE_MENU_TRANSITION_TYPE_COLLECTION_MM,
                                     VcpPageMenuCollectionMMTransition),
#endif
#ifdef __VCP_PAGE_MENU_TRANSITION_COLLECTION_TB__
    // VCP_PAGE_MENU_TRANSITION_TYPE_COLLECTION_TB
    VCP_PAGE_MENU_TRANSITION_OBJ_ADD(IMG_ID_VCP_PAGE_MENU_TRANSITION_TYPE_COLLECTION_TB,
                                     STR_ID_VCP_PAGE_MENU_TRANSITION_TYPE_COLLECTION_TB,
                                     VcpPageMenuCollectionTBTransition),
#endif
#ifdef __VCP_PAGE_MENU_TRANSITION_CYLINDER__
    // VCP_PAGE_MENU_TRANSITION_TYPE_CYLINDER
    VCP_PAGE_MENU_TRANSITION_OBJ_ADD(IMG_ID_VCP_PAGE_MENU_TRANSITION_TYPE_CYLINDER,
                                     STR_ID_VCP_PAGE_MENU_TRANSITION_TYPE_CYLINDER,
                                     VcpPageMenuCylinderTransition),
#endif
#ifdef __VCP_PAGE_MENU_TRANSITION_TORNADO__
    // VCP_PAGE_MENU_TRANSITION_TYPE_TORNADO
    VCP_PAGE_MENU_TRANSITION_OBJ_ADD(IMG_ID_VCP_PAGE_MENU_TRANSITION_TYPE_TORNADO,
                                     STR_ID_VCP_PAGE_MENU_TRANSITION_TYPE_TORNADO,
                                     VcpPageMenuTornadoTransition),

#endif
#ifdef __VCP_PAGE_MENU_TRANSITION_CUBE__
    // VCP_PAGE_MENU_TRANSITION_TYPE_CUBE
    VCP_PAGE_MENU_TRANSITION_OBJ_ADD(IMG_ID_VCP_PAGE_MENU_TRANSITION_TYPE_CUBE,
                                     STR_ID_VCP_PAGE_MENU_TRANSITION_TYPE_CUBE,
                                     VcpPageMenuHexagonalPrismTransition)
#endif
};


/*****************************************************************************
 * Global Function
 *****************************************************************************/

VfxU32 vcpPageMenuGetTransitionNum()
{
    return VCP_PAGE_MENU_TRANSITION_TYPE_MAX;
}

VfxBool vcpPageMenuGetTransitionInfoList(VcpPageMenuTransitionInfo *transitionInfoList, VfxU32 num)
{
    if (num < VCP_PAGE_MENU_TRANSITION_TYPE_MAX)
    {
        return VFX_FALSE;
    }
    
    transitionInfoList->typeId = VCP_PAGE_MENU_TRANSITION_TYPE_NORMAL;
    transitionInfoList->imageId = IMG_ID_VCP_PAGE_MENU_TRANSITION_TYPE_NORMAL;
    transitionInfoList->stringId = STR_ID_VCP_PAGE_MENU_TRANSITION_TYPE_NORMAL;
    
    for (VfxU32 i = VCP_PAGE_MENU_TRANSITION_TYPE_NORMAL + 1; i < VCP_PAGE_MENU_TRANSITION_TYPE_MAX; ++i)
    {
        (transitionInfoList+i)->typeId = (VcpPageMenuTransitionType)i;
        (transitionInfoList+i)->imageId = s_vcpPageMenuTransitionTable[i - 1].imageId;
        (transitionInfoList+i)->stringId = s_vcpPageMenuTransitionTable[i - 1].stringId;
    }

    return VFX_TRUE;
}

VcpPageMenuTransition *vcpPageMenuCreateTransition(VcpPageMenuTransitionType type, VfxObject *parent)
{
    VFX_ASSERT(type < VCP_PAGE_MENU_TRANSITION_TYPE_MAX);
    
    VcpPageMenuTransition *transition = NULL;
    if (type != VCP_PAGE_MENU_TRANSITION_TYPE_NORMAL)
    {
        transition = s_vcpPageMenuTransitionTable[type - 1].createFunc(parent);
        VFX_ASSERT(transition != NULL);
    }
    
    return transition;
}


/*****************************************************************************
 * Animation sample code
 *****************************************************************************/

vrt_render_dirty_type_enum animationSample(
    vrt_float t,
    VfxS32 direction,
    vrt_s32 indexX, vrt_s32 indexY,
    const VcpPageMenuLayout & layout,
    vrt_s32 mainmenuWidth,
    vrt_s32 mainmenuHeight,
    vrt_frame_visual_property_struct *target_frame)
{
    target_frame->transform.type = VRT_TRANSFORM_TYPE_IDENTITY;

    vrt_s32 level = mainmenuWidth + layout.pageMargin;
    target_frame->pos.x = VfxS32(level * t + layout.cellStartX + indexX * layout.cellOffsetX);
    target_frame->pos.y = VfxS32(layout.cellStartY + indexY * layout.cellOffsetY);
    vrt_s32 visibleHeight = layout.rowCount * layout.cellOffsetY;
	target_frame->pos.y += VfxS32(visibleHeight * t);
    //target_frame->pos_z = 100 + indexX * 10 + indexY;
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

#ifdef __VCP_PAGE_MENU_TRANSITION_BALL__

/*****************************************************************************
 * Class VcpPageMenuBallTransition
 *****************************************************************************/
#if defined(__MMI_MAINLCD_320X480__)
#define VCP_PAGE_MENU_BALL_RADIUS (162)
#elif defined(__MMI_MAINLCD_480X800__)
#define VCP_PAGE_MENU_BALL_RADIUS (260)
#else
#define VCP_PAGE_MENU_BALL_RADIUS (140)
#endif


VCP_PAGE_MENU_TRANSITION_OBJ_IMPLEMENT(VcpPageMenuBallTransition);

void VcpPageMenuBallTransition::onInitTransition(
        const VcpPageMenuLayout & layout,
        vrt_s32 mainmenuWidth,
        vrt_s32 mainmenuHeight)
{
    m_camera.setCamera(
                1.0f,
                1.0f,
                VfxFloat(mainmenuWidth / 2),
                VfxFloat(layout.bottomBarOffsetY / 2),
                VfxFloat(340.0f),
                VfxFloat(340.0f + VCP_PAGE_MENU_BALL_RADIUS),
                VfxFloat(0.0f),
                VfxFloat(0.0f),
                VfxFloat(0.0f));

    VfxS32 indexX, indexY;
    for (indexX = 0; indexX < layout.columnCount; indexX ++)
    {
        for (indexY = 0; indexY < layout.rowCount; indexY ++)
        {
            VfxMatrix4x4 model1;
            model1.setTranslation((VfxFloat)-layout.cellOffsetX / 2, (VfxFloat)-layout.cellOffsetY / 2, 0);

            VfxFloat angleA;

            if (layout.rowCount == 4)
            {
                if (indexY == 0)
                {
                    angleA = 51;
                }
                else if (indexY == 1)
                {
                    angleA = 17;
                }
                else if (indexY == 2)
                {
                    angleA = -17;
                }
                else
                {
                    angleA = -51;
                }
            }
            else if(layout.rowCount == 5) 
            {
                if (indexY == 0)
                {
                    angleA = 51;
                }
                else if (indexY == 1)
                {
                    angleA = 26;
                }
                else if (indexY == 2)
                {
                    angleA = 0;
                }
                else if (indexY == 3)
                {
                    angleA = -26;
                }
                else
                {
                    angleA = -51;
                }
            }
            else // layout.rowCount == 3 
            {
                if (indexY == 0)
                {
                    angleA = 45;
                }
                else if (indexY == 1)
                {
                    angleA = 0;
                }
                else
                {
                    angleA = -45;
                }
            }
            

            VfxFloat angleB;

            if (layout.columnCount == 4)
            {
                if (indexX == 0)
                {
                    angleB = -51;
                }
                else if (indexX == 1)
                {
                    angleB = -17;
                }
                else if (indexX == 2)
                {
                    angleB = 17;
                }
                else
                {
                    angleB = 51;
                }
            }
			else if (layout.columnCount == 5)
			{
				if (indexX == 0)
                {
                    angleB = 51;
                }
                else if (indexX == 1)
                {
                    angleB = 26;
                }
                else if (indexX == 2)
                {
                    angleB = 0;
                }
                else if (indexX == 3)
                {
                    angleB = -26;
                }
                else
                {
                    angleB = -51;
                }
			}
            else // layout.columnCount == 3 
            {
                if (indexX == 0)
                {
                    angleB = -45;
                }
                else if (indexX == 1)
                {
                    angleB = 0;
                }
                else 
                {
                    angleB = 45;
                }
            }
            VfxMatrix4x4 rotate1;
            rotate1.setRotateByX(VFX_DEG_TO_RAD(-angleA));

            VfxMatrix4x4 rotate2;
            rotate2.setRotateByY(VFX_DEG_TO_RAD(-angleB));

            VfxFloat radius = VCP_PAGE_MENU_BALL_RADIUS;

            VfxMatrix4x4 model2;
            VfxFloat sinA = vfxSin(VFX_DEG_TO_RAD(angleA));
            VfxFloat cosA = vfxCos(VFX_DEG_TO_RAD(angleA));
            VfxFloat sinB = vfxSin(VFX_DEG_TO_RAD(angleB));
            VfxFloat cosB = vfxCos(VFX_DEG_TO_RAD(angleB));

            model2.setTranslation(radius * cosA * sinB, -radius * sinA, -radius * cosA * cosB);

            m_model[indexX][indexY] =  model2 * rotate2 * rotate1 * model1;
            
        }
    }

    
}

#ifdef __MTK_TARGET__
#pragma arm
#endif

vrt_render_dirty_type_enum VcpPageMenuBallTransition::onTransition(
    vrt_float t,
    VfxS32 direction,
    vrt_s32 indexX, vrt_s32 indexY,
    const VcpPageMenuLayout & layout,
    vrt_s32 mainmenuWidth,
    vrt_s32 mainmenuHeight,
    vrt_frame_visual_property_struct *target_frame) const
{
    //    t = 0.458824f; 

    VfxFloat fromFloat = 0;
    VfxFloat toFloat = -180;
    VfxFloat interpolate;

    interpolate = (fromFloat) + (toFloat - fromFloat) * t;

    VfxMatrix4x4 rotateByY;
    rotateByY.setRotateByY(VFX_DEG_TO_RAD(interpolate));

    // rotate Matrix
    VfxS32 orinX = layout.cellStartX + indexX * layout.cellOffsetX;
    VfxS32 orinY = layout.cellStartY + indexY * layout.cellOffsetY;

    target_frame->pos.x = 0;
    target_frame->pos.y = 0;

    VfxMatrix4x4 totalProject;
    VfxMatrix4x4 camera = m_camera;
    totalProject = camera * rotateByY * m_model[indexX][indexY];

    target_frame->pos_z = totalProject.m[14];

    VfxTransform tempTransform;
    totalProject.initMatrix3x3(tempTransform.data.matrix3x3);
    tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

    tempTransform.initVrtTransform(target_frame->transform);

    if (VFX_ABS(t) < 0.3f)
    {
        VfxFloat tempT = VFX_ABS(t)/0.3f;
        target_frame->transform.data.matrix3x3.m[0] = (tempT)  * target_frame->transform.data.matrix3x3.m[0] + (1 - tempT) * 1;
        target_frame->transform.data.matrix3x3.m[1] = (tempT)  * target_frame->transform.data.matrix3x3.m[1] ;
        target_frame->transform.data.matrix3x3.m[2] = (tempT)  * target_frame->transform.data.matrix3x3.m[2] ;
        target_frame->transform.data.matrix3x3.m[3] = (tempT)  * target_frame->transform.data.matrix3x3.m[3] ;
        target_frame->transform.data.matrix3x3.m[4] = (tempT)  * target_frame->transform.data.matrix3x3.m[4] + (1 - tempT) * 1;
        target_frame->transform.data.matrix3x3.m[5] = (tempT)  * target_frame->transform.data.matrix3x3.m[5] ;
        target_frame->transform.data.matrix3x3.m[6] = (tempT)  * target_frame->transform.data.matrix3x3.m[6] + (1 - tempT) * orinX;
        target_frame->transform.data.matrix3x3.m[7] = (tempT)  * target_frame->transform.data.matrix3x3.m[7] + (1 - tempT) * orinY;
        target_frame->transform.data.matrix3x3.m[8] = (tempT)  * target_frame->transform.data.matrix3x3.m[8] + (1 - tempT) * 1;
    }

    // do Culling
    VfxFloat det;
    VfxFloat *m = target_frame->transform.data.matrix3x3.m;

    det = ((m[0] * m[4] * m[8]) + (m[6] * m[1] * m[5]) + (m[3] * m[7] * m[2]) -
               (m[3] * m[1] * m[8]) - (m[0] * m[7] * m[5]) - (m[6] * m[4] * m[2])) *
              ((m[2] + m[8]) * (m[5] + m[8]) * m[8]);

   

    if (VFX_ABS(t) > 0.9)
    {
        VfxFloat tempT = (VFX_ABS(t) - 0.9f)/0.1f;
        target_frame->opacity = 1 - tempT;
		if (target_frame->opacity < 0)
		{
			target_frame->opacity = 0;
		}
    }
    else
    {
        target_frame->opacity = 1.0f;
    }

	if (VFX_ABS(det) < 0.001f)
    {
        target_frame->opacity = 0;
    }

    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

#ifdef __MTK_TARGET__
#pragma thumb
#endif

#endif//#ifdef __VCP_PAGE_MENU_TRANSITION_BALL__

#ifdef __VCP_PAGE_MENU_TRANSITION_SPACE_BEAM__
/*****************************************************************************
 * Class VcpPageMenuSpaceBeamTransition
 *****************************************************************************/

#if defined(__MMI_MAINLCD_320X480__)
#define VCP_PAGE_MENU_SPACE_BEAM_VANISH_POINT_X (140)
#define VCP_PAGE_MENU_SPACE_BEAM_VANISH_POINT_Y (140)
#define VCP_PAGE_MENU_SPACE_BEAM_VANISH_POINT_SCALE (0.36f)
#elif defined(__MMI_MAINLCD_480X800__)
#define VCP_PAGE_MENU_SPACE_BEAM_VANISH_POINT_X (214)
#define VCP_PAGE_MENU_SPACE_BEAM_VANISH_POINT_Y (210)
#define VCP_PAGE_MENU_SPACE_BEAM_VANISH_POINT_SCALE (0.36f)
#else // __MMI_MAINLCD_240X400__  __MMI_MAINLCD_240X320__
#define VCP_PAGE_MENU_SPACE_BEAM_VANISH_POINT_X (109)
#define VCP_PAGE_MENU_SPACE_BEAM_VANISH_POINT_Y (120)
#define VCP_PAGE_MENU_SPACE_BEAM_VANISH_POINT_SCALE (0.36f)
#endif

VCP_PAGE_MENU_TRANSITION_OBJ_IMPLEMENT(VcpPageMenuSpaceBeamTransition);

vrt_render_dirty_type_enum VcpPageMenuSpaceBeamTransition::onTransition(
    vrt_float t,
    VfxS32 direction,
    vrt_s32 indexX, vrt_s32 indexY,
    const VcpPageMenuLayout & layout,
    vrt_s32 mainmenuWidth,
    vrt_s32 mainmenuHeight,
    vrt_frame_visual_property_struct *target_frame) const
{
    if (t < - 0.5f || t > 0.5f)
    {
        target_frame->opacity = 0;
        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }

    VfxFloat normalT = vfxAbs(t) * 2;
    VfxFloat adjT;
    VfxFloat startT = (VfxFloat)(indexY * layout.columnCount + indexX) / (layout.columnCount * layout.rowCount) * 0.5f;
    if (normalT < startT)
    {
        adjT = 0;
    }
    else
    {
        //adjT = (normalT - startT)/ (1.0f - startT);
		adjT = (normalT - startT)/ (0.625f);
    }

    if (adjT < 0)
    {
        adjT = 0;
    }

    if (adjT > 1)
    {
        adjT = 1;
    }

    VfxS32 orinX = layout.cellStartX + indexX * layout.cellOffsetX;
    VfxS32 orinY = layout.cellStartY + indexY * layout.cellOffsetY;

    target_frame->pos.x = (VfxS32)((VCP_PAGE_MENU_SPACE_BEAM_VANISH_POINT_X - orinX) * adjT) + orinX;
    target_frame->pos.y = (VfxS32)((VCP_PAGE_MENU_SPACE_BEAM_VANISH_POINT_Y - orinY) * adjT) + orinY;
    target_frame->transform.type = VRT_TRANSFORM_TYPE_AFFINE;
    target_frame->transform.data.affine.sx = ((VCP_PAGE_MENU_SPACE_BEAM_VANISH_POINT_SCALE - 1) * adjT) + 1;
    target_frame->transform.data.affine.sy = ((VCP_PAGE_MENU_SPACE_BEAM_VANISH_POINT_SCALE - 1) * adjT) + 1;
    target_frame->opacity = 1.0f - adjT;

    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}
#endif//#ifdef __VCP_PAGE_MENU_TRANSITION_SPACE_BEAM__

#ifdef __VCP_PAGE_MENU_TRANSITION_JUMP_UP__

/*****************************************************************************
 * Class VcpPageMenuJumpUpTransition
 *****************************************************************************/

#if defined(__MMI_MAINLCD_320X480__)
#define VCP_PAGE_MENU_JUMP_UP_VANISH_POINT_X (130)
#define VCP_PAGE_MENU_JUMP_UP_VANISH_POINT_Y (500)
#define VCP_PAGE_MENU_JUMP_UP_VANISH_POINT_SCALE (0.75f)
#elif defined(__MMI_MAINLCD_240X320__)
#define VCP_PAGE_MENU_JUMP_UP_VANISH_POINT_X (101)
#define VCP_PAGE_MENU_JUMP_UP_VANISH_POINT_Y (360)
#define VCP_PAGE_MENU_JUMP_UP_VANISH_POINT_SCALE (0.75f)
#elif defined(__MMI_MAINLCD_480X800__)
#define VCP_PAGE_MENU_JUMP_UP_VANISH_POINT_X (200)
#define VCP_PAGE_MENU_JUMP_UP_VANISH_POINT_Y (900)
#define VCP_PAGE_MENU_JUMP_UP_VANISH_POINT_SCALE (0.75f)
#else // __MMI_MAINLCD_240X400__
#define VCP_PAGE_MENU_JUMP_UP_VANISH_POINT_X (101)
#define VCP_PAGE_MENU_JUMP_UP_VANISH_POINT_Y (460)
#define VCP_PAGE_MENU_JUMP_UP_VANISH_POINT_SCALE (0.75f)
#endif

VCP_PAGE_MENU_TRANSITION_OBJ_IMPLEMENT(VcpPageMenuJumpUpTransition);

vrt_render_dirty_type_enum VcpPageMenuJumpUpTransition::onTransition(
    vrt_float t,
    VfxS32 direction,
    vrt_s32 indexX, vrt_s32 indexY,
    const VcpPageMenuLayout & layout,
    vrt_s32 mainmenuWidth,
    vrt_s32 mainmenuHeight,
    vrt_frame_visual_property_struct *target_frame) const
{
    
    if (t < - 0.5f || t > 0.5f)
    {
        target_frame->opacity = 0;
        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }

    VfxFloat normalT = vfxAbs(t) * 2;
    VfxFloat adjT;
    VfxFloat endT;
    VfxFloat secStartT = 0.55f;

    if (indexX == 0)
    {
        endT = 0.91f;
    }
    else if (indexX == 1)
    {
        endT = 0.81f;
    }
    else if (indexX == 2)
    {
        endT = 0.72f;
    }
    else
    {
        endT = 1.0f;
    }
    
    if (normalT > endT)
    {
        adjT = 1.0f;
    }
    else
    {
		adjT = normalT/endT;
    }

    if (adjT < 0)
    {
        adjT = 0;
    }

    if (adjT > 1)
    {
        adjT = 1;
    }

    VfxS32 orinX;
    VfxS32 orinY;
    VfxS32 targetX;
    VfxS32 targetY;

    orinX = layout.cellStartX + indexX * layout.cellOffsetX;
    orinY = layout.cellStartY + indexY * layout.cellOffsetY;

    targetX = VCP_PAGE_MENU_JUMP_UP_VANISH_POINT_X;
    targetY = VCP_PAGE_MENU_JUMP_UP_VANISH_POINT_Y - 100;

    VfxFloat adjT2 = adjT;

    if (normalT > secStartT)
    {
        orinX = VfxS32(orinX + (targetX - orinX) * secStartT/endT);
        orinY = VfxS32(orinY + (targetY - orinY) * secStartT/endT);

        targetX = VCP_PAGE_MENU_JUMP_UP_VANISH_POINT_X;
        targetY = VCP_PAGE_MENU_JUMP_UP_VANISH_POINT_Y;

        adjT2 = (normalT - secStartT)/endT;
    }
    
    target_frame->pos.x = (VfxS32)((targetX - orinX) * adjT2) + orinX;
    target_frame->pos.y = (VfxS32)((targetY - orinY) * adjT2) + orinY;
    target_frame->transform.type = VRT_TRANSFORM_TYPE_AFFINE;
    target_frame->transform.data.affine.sx = ((VCP_PAGE_MENU_JUMP_UP_VANISH_POINT_SCALE - 1) * adjT) + 1;
    target_frame->transform.data.affine.sy = ((VCP_PAGE_MENU_JUMP_UP_VANISH_POINT_SCALE - 1) * adjT) + 1;
    target_frame->opacity = 1.0f - adjT;
    target_frame->pos_z = 300;

    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

#endif//#ifdef __VCP_PAGE_MENU_TRANSITION_JUMP_UP__

#ifdef __VCP_PAGE_MENU_TRANSITION_PHOTO_TILT__

/*****************************************************************************
 * Class VcpPageMenuTiltTransition
 *****************************************************************************/

VCP_PAGE_MENU_TRANSITION_OBJ_IMPLEMENT(VcpPageMenuTiltTransition);

void VcpPageMenuTiltTransition::onInitTransition(
        const VcpPageMenuLayout & layout,
        vrt_s32 mainmenuWidth,
        vrt_s32 mainmenuHeight)
{
    m_camera.setCamera(
                1.0f,
                1.0f,
                VfxFloat(mainmenuWidth / 2),
                VfxFloat(mainmenuHeight / 2),
                VfxFloat(240.0f),
                VfxFloat(240.0f),
                VfxFloat(0.0f),
                VfxFloat(0.0f),
                VfxFloat(0.0f));
}

#ifdef __MTK_TARGET__
#pragma arm
#endif

vrt_render_dirty_type_enum VcpPageMenuTiltTransition::onTransition(
    vrt_float t,
    VfxS32 direction,
    vrt_s32 indexX, vrt_s32 indexY,
    const VcpPageMenuLayout & layout,
    vrt_s32 mainmenuWidth,
    vrt_s32 mainmenuHeight,
    vrt_frame_visual_property_struct *target_frame) const
{

    VfxMatrix4x4 camera = m_camera;

    // rotate Matrix

    VfxFloat fromFloat = 0;
    VfxFloat toFloat = -30;
    VfxFloat interpolate;

    if (m_photoWallType == 1)
    {
        toFloat = 30;
    }
    
    if (1)
    {
        if (t < 0.5f)
        {
            interpolate = fromFloat + (toFloat - fromFloat) * vfxSin(t * VFX_PI);
        }
        else
        {
            interpolate = toFloat * vfxSin(t * VFX_PI);
        }
    }
    else
    {
        // linear interpolation 
        interpolate = (fromFloat) + (toFloat - fromFloat) * t;
    }

    if (m_photoWallType == 0)
    {
        interpolate = -direction * VFX_ABS(interpolate);
    }

    VfxMatrix4x4 rotateByY;
    rotateByY.setRotateByY(VFX_DEG_TO_RAD(interpolate) );


    VfxMatrix4x4 transform = camera * rotateByY;

    VfxS32 orinX = layout.cellStartX + indexX * layout.cellOffsetX;
    VfxS32 orinY = layout.cellStartY + indexY * layout.cellOffsetY;

    target_frame->pos.x = 0;
    target_frame->pos.y = 0;
    VfxMatrix4x4 model, totalProject;
    model.setTranslation(VfxFloat(orinX + mainmenuWidth * t - mainmenuWidth / 2), VfxFloat(orinY - mainmenuHeight / 2), 0);


    totalProject = transform * model;

    VfxTransform tempTransform;
    totalProject.initMatrix3x3(tempTransform.data.matrix3x3);
    tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

    tempTransform.initVrtTransform(target_frame->transform);
    

    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

#ifdef __MTK_TARGET__
#pragma thumb
#endif


void VcpPageMenuTiltTransition::onInit()
{
    VfxObject::onInit();
    m_photoWallType = 0;
}

#endif//#ifdef __VCP_PAGE_MENU_TRANSITION_PHOTO_TILT__

#ifdef __VCP_PAGE_MENU_TRANSITION_WAVE__

/*****************************************************************************
 * Class VcpPageMenuWaveTransition
 *****************************************************************************/

VCP_PAGE_MENU_TRANSITION_OBJ_IMPLEMENT(VcpPageMenuWaveTransition);

void VcpPageMenuWaveTransition::onInit()
{
    VfxObject::onInit();
    m_photoWallType = 2;
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
#endif
#endif//#ifdef __VCP_PAGE_MENU_TRANSITION_WAVE__

#ifdef __VCP_PAGE_MENU_TRANSITION_ROLL__

/*****************************************************************************
 * Class VcpPageMenuRollTransition
 *****************************************************************************/

VCP_PAGE_MENU_TRANSITION_OBJ_IMPLEMENT(VcpPageMenuRollTransition);

#ifdef __MTK_TARGET__
#pragma arm
#endif

vrt_render_dirty_type_enum VcpPageMenuRollTransition::onTransition(
    vrt_float t,
    VfxS32 direction,
    vrt_s32 indexX, vrt_s32 indexY,
    const VcpPageMenuLayout & layout,
    vrt_s32 mainmenuWidth,
    vrt_s32 mainmenuHeight,
    vrt_frame_visual_property_struct *target_frame) const
{

    
    target_frame->pos_z = VfxFloat(300 - (indexX + indexY * layout.columnCount));
    target_frame->anchor_point.x = 0.5;
    target_frame->anchor_point.y = 0.5;

    vrt_float pi = 3.14159265f;
    vrt_s32 idx = indexX + indexY * layout.columnCount;
    vrt_float theta = -idx * 2 * pi / layout.rowCount / layout.columnCount; 
            
    vrt_s32 radius = layout.cellOffsetY;
	vrt_s32 lcx = 0;
    vrt_s32 lcy = vrt_s32(0.5f * (layout.bottomBarOffsetY + layout.cellStartY));
    vrt_s32 rcx = mainmenuWidth;
    vrt_s32 rcy = vrt_s32(0.5f * (layout.bottomBarOffsetY + layout.cellStartY));
    
    vrt_s32 lx = vrt_s32(lcx + radius * vrt_cos(theta));
    vrt_s32 ly = vrt_s32(lcy + radius * vrt_sin(theta));
    vrt_float la = theta - 0.5f * pi;

    vrt_s32 rx = lx + mainmenuWidth;
    vrt_s32 ry = ly;   
    vrt_float ra = theta - 0.5f * pi;              
  

   vrt_s32 x = vrt_s32(layout.cellStartX + indexX * layout.cellOffsetX + 0.5f * layout.cellOffsetX);
   vrt_s32 y = vrt_s32(layout.cellStartY + indexY * layout.cellOffsetY + 0.5f * layout.cellOffsetY);


   vrt_float l = -0.5f, r = 0.5f;
   vrt_float factor = 3.2f;

   target_frame->transform.type = VRT_TRANSFORM_TYPE_AFFINE;


   if(t < l)
   {
       target_frame->pos.x = VfxS32(lcx + radius * factor * (t - l) + radius * vrt_sin(factor* (t - l) + theta + 0.5f * pi));
       target_frame->pos.y = VfxS32(lcy - radius * vrt_cos(factor* (t - l) + theta + 0.5f * pi ));
       target_frame->transform.data.affine.rz = la + factor * (t - l);       
	   
   }
   if(t >= l && t < 0)
   {
       target_frame->pos.x = VfxS32(x + (lx - x) * (t - 0) / (l - 0));
       target_frame->pos.y = VfxS32(y + (ly - y) * (t - 0) / (l - 0));
       target_frame->transform.data.affine.rz = 0 + (la - 0) * (t - 0) / (l - 0);       
   }
   if(t >= 0 && t < r)
   {
       target_frame->pos.x = VfxS32(rx + (x - rx) * (t - r) / (0 - r));
       target_frame->pos.y = VfxS32(ry + (y - ry) * (t - r) / (0 - r));
       target_frame->transform.data.affine.rz = ra + (0 - ra) * (t - r) / (0 - r);       

   }
   if(t >= r)
   {
       target_frame->pos.x = VfxS32(rcx + radius * factor * (t - r) + radius * vrt_sin(factor* (t - r) + theta  + 0.5f * pi));
       target_frame->pos.y = VfxS32(rcy - radius * vrt_cos(factor* (t - r) + theta + 0.5f * pi));
       target_frame->transform.data.affine.rz = ra + factor * (t - r);       
   }
	target_frame->transform.data.affine.sx = 1;
	target_frame->transform.data.affine.sy = 1;
	target_frame->transform.data.affine.tx = 0;
	target_frame->transform.data.affine.ty = 0;
    
   return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

#ifdef __MTK_TARGET__
#pragma thumb
#endif

#endif//#ifdef __VCP_PAGE_MENU_TRANSITION_ROLL__

#ifdef __VCP_PAGE_MENU_TRANSITION_SLIDE_DOWN__

/*****************************************************************************
 * Class VcpPageMenuSlideDownTransition
 *****************************************************************************/

VCP_PAGE_MENU_TRANSITION_OBJ_IMPLEMENT(VcpPageMenuSlideDownTransition);

vrt_render_dirty_type_enum VcpPageMenuSlideDownTransition::onTransition(
    vrt_float t,
    VfxS32 direction,
    vrt_s32 indexX, vrt_s32 indexY,
    const VcpPageMenuLayout & layout,
    vrt_s32 mainmenuWidth,
    vrt_s32 mainmenuHeight,
    vrt_frame_visual_property_struct *target_frame) const
{
    target_frame->transform.type = VRT_TRANSFORM_TYPE_IDENTITY;
    target_frame->pos_z = VfxFloat(300 - (indexX + indexY * layout.columnCount));

    vrt_s32 level = mainmenuWidth + layout.pageMargin;
    target_frame->pos.x = VfxS32(level * t + layout.cellStartX + indexX * layout.cellOffsetX);
    target_frame->pos.y = VfxS32(layout.cellStartY + indexY * layout.cellOffsetY);
    vrt_s32 visibleHeight = layout.rowCount * layout.cellOffsetY;
	if (m_slideType == 0)
		target_frame->pos.y += VfxS32(visibleHeight * VRT_ABS(t));   
	else
		target_frame->pos.y -= VfxS32(visibleHeight * VRT_ABS(t));   
    target_frame->opacity = 1.0f - VRT_ABS(t);   
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

void VcpPageMenuSlideDownTransition::onInit()
{
    VfxObject::onInit();
    m_slideType = 0;
}


#endif//#ifdef __VCP_PAGE_MENU_TRANSITION_SLIDE_DOWN__

#ifdef __VCP_PAGE_MENU_TRANSITION_SLIDE_UP__

/*****************************************************************************
 * Class VcpPageMenuSlideUpTransition
 *****************************************************************************/

VCP_PAGE_MENU_TRANSITION_OBJ_IMPLEMENT(VcpPageMenuSlideUpTransition);

void VcpPageMenuSlideUpTransition::onInit()
{
    VfxObject::onInit();
    m_slideType = 1;
}

#endif//#ifdef __VCP_PAGE_MENU_TRANSITION_SLIDE_UP__

#ifdef __VCP_PAGE_MENU_TRANSITION_COLLECTION_MM__

/*****************************************************************************
 * Class VcpPageMenuCollectionMMTransition
 *****************************************************************************/

VCP_PAGE_MENU_TRANSITION_OBJ_IMPLEMENT(VcpPageMenuCollectionMMTransition);

vrt_render_dirty_type_enum VcpPageMenuCollectionMMTransition::onTransition(
    vrt_float t,
    VfxS32 direction,
    vrt_s32 indexX, vrt_s32 indexY,
    const VcpPageMenuLayout & layout,
    vrt_s32 mainmenuWidth,
    vrt_s32 mainmenuHeight,
    vrt_frame_visual_property_struct *target_frame) const
{

   target_frame->transform.type = VRT_TRANSFORM_TYPE_IDENTITY;
   target_frame->pos_z = VfxFloat(300 - (indexX + indexY * layout.columnCount));

   vrt_s32 lX1 = VfxS32(-0.7f * layout.cellOffsetX);    
   vrt_s32 lX2 = VfxS32(-0.3f * layout.cellOffsetX);    
   vrt_s32 rX1 = VfxS32(mainmenuWidth - 0.7f * layout.cellOffsetX);
   vrt_s32 rX2 = VfxS32(mainmenuWidth - 0.3f * layout.cellOffsetX);
   
   vrt_s32 lY1, lY2, rY1, rY2;

   if (m_collectionType == 0)
   {
		lY1 = VfxS32(layout.cellStartY + 0.5f * layout.cellOffsetY * (layout.rowCount-1));	 
		lY2 = VfxS32(layout.cellStartY + 0.5f * layout.cellOffsetY * (layout.rowCount-1));	 
		rY1 = VfxS32(layout.cellStartY + 0.5f * layout.cellOffsetY * (layout.rowCount-1));
		rY2 = VfxS32(layout.cellStartY + 0.5f * layout.cellOffsetY * (layout.rowCount-1)); 
   }
   else
   {
		lY1 = layout.cellStartY;
		lY2 = layout.cellStartY;
		rY1 = layout.cellStartY + layout.cellOffsetY * (layout.rowCount-1);
		rY2 = layout.cellStartY + layout.cellOffsetY * (layout.rowCount-1); 	   
   }
  
   vrt_s32 level = mainmenuWidth + layout.pageMargin;    
   vrt_s32 x = layout.cellStartX + indexX * layout.cellOffsetX;
   vrt_s32 y = layout.cellStartY + indexY * layout.cellOffsetY;  


   vrt_float l1 = -0.7f, l2 = -0.5f, r1 = 0.5f, r2 = 0.7f;   


   if(t >= -1 && t < l1)
   {     
       x = lX1 -level;
       y = lY1;
       target_frame->pos.x = VfxS32(lX1 + (x - lX1) * (t - l1) / (-1 - l1));
       target_frame->pos.y = VfxS32(lY1 + (y - lY1) * (t - l1) / (-1 - l1));       
   }   
   if(t >= l1 && t < l2)
   {
       target_frame->pos.x = VfxS32(lX2 + (lX1 - lX2) * (t - l2) / (l1 - l2));
       target_frame->pos.y = VfxS32(lY2 + (lY1 - lY2) * (t - l2) / (l1 - l2));
   }
   if(t >= l2 && t < 0)
   {
       target_frame->pos.x = VfxS32(x + (lX2 - x) * (t - 0) / (l2 - 0));
       target_frame->pos.y = VfxS32(y + (lY2 - y) * (t - 0) / (l2 - 0));
   }
   if(t >= 0 && t < r1)
   {
       target_frame->pos.x = VfxS32(rX1 + (x - rX1) * (t - r1) / (0 - r1));
       target_frame->pos.y = VfxS32(rY1 + (y - rY1) * (t - r1) / (0 - r1));
   }
   if(t >= r1 && t < r2)
   {
       target_frame->pos.x = VfxS32(rX2 + (rX1 - rX2) * (t - r2) / (r1 - r2));
       target_frame->pos.y = VfxS32(rY2 + (rY1 - rY2) * (t - r2) / (r1 - r2));
   }
   if(t >= r2)
   {
       x = rX2 + level;
       y = rY2;
       target_frame->pos.x = VfxS32(x + (rX2 - x) * (t - 1) / (r2 - 1));
       target_frame->pos.y = VfxS32(y + (rY2 - y) * (t - 1) / (r2 - 1));
   }
    
   return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

void VcpPageMenuCollectionMMTransition::onInit()
{
    VfxObject::onInit();
    m_collectionType = 0;
}

#endif//#ifdef __VCP_PAGE_MENU_TRANSITION_COLLECTION_MM__

#ifdef __VCP_PAGE_MENU_TRANSITION_COLLECTION_TB__

/*****************************************************************************
 * Class VcpPageMenuCollectionTBTransition
 *****************************************************************************/

VCP_PAGE_MENU_TRANSITION_OBJ_IMPLEMENT(VcpPageMenuCollectionTBTransition);

void VcpPageMenuCollectionTBTransition::onInit()
{
    VfxObject::onInit();
    m_collectionType = 1;
}


#endif//#ifdef __VCP_PAGE_MENU_TRANSITION_COLLECTION_TB__

#ifdef __VCP_PAGE_MENU_TRANSITION_CYLINDER__

/*****************************************************************************
 * Class VcpPageMenuCylinderTransition
 *****************************************************************************/

#if defined(__MMI_MAINLCD_320X480__)
#define VCP_PAGE_MENU_CYLINDER_RADIUS (162)
#define VCP_PAGE_MENU_CYLINDER_NEAR   (340)
#elif defined(__MMI_MAINLCD_480X800__)
#define VCP_PAGE_MENU_CYLINDER_RADIUS (260)
#define VCP_PAGE_MENU_CYLINDER_NEAR   (600)
#else
#define VCP_PAGE_MENU_CYLINDER_RADIUS (140)
#define VCP_PAGE_MENU_CYLINDER_NEAR   (340)
#endif

VCP_PAGE_MENU_TRANSITION_OBJ_IMPLEMENT(VcpPageMenuCylinderTransition);

void VcpPageMenuCylinderTransition::onInitTransition(
        const VcpPageMenuLayout & layout,
        vrt_s32 mainmenuWidth,
        vrt_s32 mainmenuHeight)
{
    m_camera.setCamera(
                1.0f,
                1.0f,
                VfxFloat(mainmenuWidth / 2),
                VfxFloat(layout.bottomBarOffsetY / 2),
                VfxFloat(VCP_PAGE_MENU_CYLINDER_NEAR),
                VfxFloat(VCP_PAGE_MENU_CYLINDER_NEAR + VCP_PAGE_MENU_CYLINDER_RADIUS),
                VfxFloat(0.0f),
                VfxFloat(0.0f),
                VfxFloat(0.0f));

    VfxS32 indexX, indexY;
    for (indexX = 0; indexX < layout.columnCount; indexX ++)
    {
        for (indexY = 0; indexY < layout.rowCount; indexY ++)
        {
            VfxMatrix4x4 model1;
            model1.setTranslation((VfxFloat)-layout.cellOffsetX / 2, (VfxFloat)-layout.cellOffsetY / 2, 0); 

            VfxFloat angleB;
            if (layout.columnCount == 4)
            {
                if (indexX == 0)
                {
                    angleB = -51;
                }
                else if (indexX == 1)
                {
                    angleB = -17;
                }
                else if (indexX == 2)
                {
                    angleB = 17;
                }
                else
                {
                    angleB = 51;
                }
            }
            else if (layout.columnCount == 5)
			{
				if (indexX == 0)
                {
                    angleB = 51;
                }
                else if (indexX == 1)
                {
                    angleB = 26;
                }
                else if (indexX == 2)
                {
                    angleB = 0;
                }
                else if (indexX == 3)
                {
                    angleB = -26;
                }
                else
                {
                    angleB = -51;
                }
			}
            else //layout.columnCount == 3
            {
                if (indexX == 0)
                {
                    angleB = -45;
                }
                else if (indexX == 1)
                {
                    angleB = 0;
                }
                else 
                {
                    angleB = 45;
                }
            }

            VfxMatrix4x4 rotate2;
            rotate2.setRotateByY(VFX_DEG_TO_RAD(-angleB));

            VfxFloat radius = VCP_PAGE_MENU_CYLINDER_RADIUS;

            VfxMatrix4x4 model2;
            VfxFloat sinB = vfxSin(VFX_DEG_TO_RAD(angleB));
            VfxFloat cosB = vfxCos(VFX_DEG_TO_RAD(angleB));

            VfxFloat offsetY;

            if (layout.rowCount == 4)
            {
                offsetY = 1.5f;
            }
            else if (layout.rowCount == 5)
            {
                offsetY = 2.0f;
            }
            else //layout.rowCount == 3
            {
                offsetY = 1.0f;
            }

            model2.setTranslation(radius * sinB, layout.cellOffsetY * (indexY - offsetY), -radius * cosB);

            m_model[indexX][indexY] =  model2 * rotate2 * model1;
            
        }
    }

    
}

#ifdef __MTK_TARGET__
#pragma arm
#endif

vrt_render_dirty_type_enum VcpPageMenuCylinderTransition::onTransition(
    vrt_float t,
    VfxS32 direction,
    vrt_s32 indexX, vrt_s32 indexY,
    const VcpPageMenuLayout & layout,
    vrt_s32 mainmenuWidth,
    vrt_s32 mainmenuHeight,
    vrt_frame_visual_property_struct *target_frame) const
{

    // rotate Matrix

    VfxFloat fromFloat = 0;
    VfxFloat toFloat = -180;
    VfxFloat interpolate;

    interpolate = (fromFloat) + (toFloat - fromFloat) * t;

    VfxMatrix4x4 rotateByY;
    rotateByY.setRotateByY(VFX_DEG_TO_RAD(interpolate));

    // rotate Matrix
    VfxS32 orinX = layout.cellStartX + indexX * layout.cellOffsetX;
    VfxS32 orinY = layout.cellStartY + indexY * layout.cellOffsetY;

    target_frame->pos.x = 0;
    target_frame->pos.y = 0;

    VfxMatrix4x4 totalProject;
    VfxMatrix4x4 camera = m_camera;
    totalProject = camera * rotateByY * m_model[indexX][indexY];

    target_frame->pos_z = totalProject.m[14];

    VfxTransform tempTransform;
    totalProject.initMatrix3x3(tempTransform.data.matrix3x3);
    tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

    tempTransform.initVrtTransform(target_frame->transform);

    if (VFX_ABS(t) < 0.3f)
    {
        VfxFloat tempT = VFX_ABS(t)/0.3f;
        target_frame->transform.data.matrix3x3.m[0] = (tempT)  * target_frame->transform.data.matrix3x3.m[0] + (1 - tempT) * 1;
        target_frame->transform.data.matrix3x3.m[1] = (tempT)  * target_frame->transform.data.matrix3x3.m[1] ;
        target_frame->transform.data.matrix3x3.m[2] = (tempT)  * target_frame->transform.data.matrix3x3.m[2] ;
        target_frame->transform.data.matrix3x3.m[3] = (tempT)  * target_frame->transform.data.matrix3x3.m[3] ;
        target_frame->transform.data.matrix3x3.m[4] = (tempT)  * target_frame->transform.data.matrix3x3.m[4] + (1 - tempT) * 1;
        target_frame->transform.data.matrix3x3.m[5] = (tempT)  * target_frame->transform.data.matrix3x3.m[5] ;
        target_frame->transform.data.matrix3x3.m[6] = (tempT)  * target_frame->transform.data.matrix3x3.m[6] + (1 - tempT) * orinX;
        target_frame->transform.data.matrix3x3.m[7] = (tempT)  * target_frame->transform.data.matrix3x3.m[7] + (1 - tempT) * orinY;
        target_frame->transform.data.matrix3x3.m[8] = (tempT)  * target_frame->transform.data.matrix3x3.m[8] + (1 - tempT) * 1;
    }

    if (VFX_ABS(t) > 0.9)
    {
        VfxFloat tempT = (VFX_ABS(t) - 0.9f)/0.1f;
        target_frame->opacity = 1 - tempT;
		if (target_frame->opacity < 0)
		{
			target_frame->opacity = 0;
		}
    }
    else
    {
        target_frame->opacity = 1.0f;
    }

    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

#ifdef __MTK_TARGET__
#pragma thumb
#endif

#endif//#ifdef __VCP_PAGE_MENU_TRANSITION_CYLINDER__

#ifdef __VCP_PAGE_MENU_TRANSITION_TORNADO__

/*****************************************************************************
 * Class VcpPageMenuTornadoTransition
 *****************************************************************************/

#if defined(__MMI_MAINLCD_320X480__)
#define VCP_TORNADO_MENU_ANGLE                              (45) 
#define VCP_TORNADO_MENU_FROM_RADIUS                        (182)
#define VCP_TORNADO_MENU_TO_RADIUS                          (50)
#define VCP_TORNADO_MENU_Y_GAP                            (97)
#define VCP_TORNADO_MENU_AHEAD_COUNT                        (9) 
#define VCP_TORNADO_MENU_BEHIND_COUNT                       (16)
#define VCP_TORNADO_MENU_Y_SHIFT                            (0)
#elif defined(__MMI_MAINLCD_480X800__)
#define VCP_TORNADO_MENU_ANGLE                              (45) 
#define VCP_TORNADO_MENU_FROM_RADIUS                        (304)
#define VCP_TORNADO_MENU_TO_RADIUS                          (100)
#define VCP_TORNADO_MENU_Y_GAP                            (170)
#define VCP_TORNADO_MENU_AHEAD_COUNT                        (9) 
#define VCP_TORNADO_MENU_BEHIND_COUNT                       (24)
#define VCP_TORNADO_MENU_Y_SHIFT                            (-110)
#else // __MMI_MAINLCD_240X400__ __MMI_MAINLCD_240X320__
#define VCP_TORNADO_MENU_ANGLE                              (45) 
#define VCP_TORNADO_MENU_FROM_RADIUS                        (152)
#define VCP_TORNADO_MENU_TO_RADIUS                          (50)
#define VCP_TORNADO_MENU_Y_GAP                            (85)
#define VCP_TORNADO_MENU_AHEAD_COUNT                        (9) 
#define VCP_TORNADO_MENU_BEHIND_COUNT                       (16)
#define VCP_TORNADO_MENU_Y_SHIFT                            (0)
#endif

VCP_PAGE_MENU_TRANSITION_OBJ_IMPLEMENT(VcpPageMenuTornadoTransition);

void VcpPageMenuTornadoTransition::onInitTransition(
        const VcpPageMenuLayout & layout,
        vrt_s32 mainmenuWidth,
        vrt_s32 mainmenuHeight)
{
    m_camera.setCamera(
                1.0f,
                1.0f,
                VfxFloat(mainmenuWidth / 2),
                VfxFloat(mainmenuHeight / 2 + VCP_TORNADO_MENU_Y_SHIFT),
                VfxFloat(340.0f),
                VfxFloat(340.0f + VCP_TORNADO_MENU_FROM_RADIUS * 0.8f),
                VfxFloat(0.0f),
                VfxFloat(0.0f),
                VfxFloat(0.0f));
}

#ifdef __MTK_TARGET__
#pragma arm
#endif

vrt_render_dirty_type_enum VcpPageMenuTornadoTransition::onTransition(
    vrt_float t,
    VfxS32 direction,
    vrt_s32 indexX, vrt_s32 indexY,
    const VcpPageMenuLayout & layout,
    vrt_s32 mainmenuWidth,
    vrt_s32 mainmenuHeight,
    vrt_frame_visual_property_struct *target_frame) const
{

    VFX_DEV_ASSERT(target_frame != NULL);

    target_frame->pos.x = 0;
    target_frame->pos.y = 0;

    VfxS32 orinX = layout.cellStartX + indexX * layout.cellOffsetX;
    VfxS32 orinY = layout.cellStartY + indexY * layout.cellOffsetY;
    
    VfxFloat offset;
    //offset = cellIndex - focusIndex;
    offset = (t + indexX/(VfxFloat)(layout.columnCount * layout.rowCount) + indexY/(VfxFloat)layout.rowCount ) * (VCP_TORNADO_MENU_BEHIND_COUNT + 0) - 5;

    VfxMatrix4x4 totalProject;
    VfxMatrix4x4 cameraView;
    VfxMatrix4x4 modelView;
    VfxMatrix4x4 RT;
    
    cameraView = m_camera;
    
    // set Model View :
    // The model view matirx decides the origin and direction of model.
    // We set the origin of each item to the center of item.
    // So we need to apply a negative translate. 

    modelView.setTranslation((VfxFloat)((-1 * layout.cellOffsetX/2)), 
                    (VfxFloat)(-1 * layout.cellOffsetY/2), 
                    0);



    if (offset > VCP_TORNADO_MENU_BEHIND_COUNT)
    {
        
        VfxFloat tempOffset = VCP_TORNADO_MENU_BEHIND_COUNT;
        VfxFloat distance = ((tempOffset + VCP_TORNADO_MENU_AHEAD_COUNT) * (VCP_TORNADO_MENU_TO_RADIUS - VCP_TORNADO_MENU_FROM_RADIUS)/(VCP_TORNADO_MENU_AHEAD_COUNT + VCP_TORNADO_MENU_BEHIND_COUNT) + VCP_TORNADO_MENU_FROM_RADIUS);

        #define  VCP_TWIST_MENU_OPT_AAA  (VCP_TORNADO_MENU_ANGLE/ 180.0f * VFX_PI)
        VfxFloat angleAAA = tempOffset * VCP_TWIST_MENU_OPT_AAA - VFX_PI/2;
        
        RT.m[12] = vfxCos(angleAAA) * distance;
        RT.m[13] = (tempOffset * 0.125f + (offset - tempOffset)) * VCP_TORNADO_MENU_Y_GAP;
        RT.m[14] = vfxSin(angleAAA) * distance;

        #define  VCP_TWIST_MENU_OPT_BBB  (-1.0f * VCP_TORNADO_MENU_ANGLE/ 180.0f * VFX_PI)
        VfxFloat angleBBB = tempOffset * VCP_TWIST_MENU_OPT_BBB;
        
        RT.m[0] = RT.m[10] = vfxCos(angleBBB);
        RT.m[8] = vfxSin(angleBBB);
        RT.m[2] = -1 * RT.m[8];
    }
    else
    {
        VfxFloat distance = ((offset + VCP_TORNADO_MENU_AHEAD_COUNT) * (VCP_TORNADO_MENU_TO_RADIUS - VCP_TORNADO_MENU_FROM_RADIUS)/(VCP_TORNADO_MENU_AHEAD_COUNT + VCP_TORNADO_MENU_BEHIND_COUNT) + VCP_TORNADO_MENU_FROM_RADIUS);
        //VfxFloat distance = 150;
        
        #define  VCP_TWIST_MENU_OPT_AAA  (VCP_TORNADO_MENU_ANGLE/ 180.0f * VFX_PI)
        VfxFloat angleAAA = offset * VCP_TWIST_MENU_OPT_AAA - VFX_PI/2;

        RT.m[12] = vfxCos(angleAAA) * distance;
        RT.m[13] = offset * 0.125f * VCP_TORNADO_MENU_Y_GAP; 
        RT.m[14] = vfxSin(angleAAA) * distance;

        #define  VCP_TWIST_MENU_OPT_BBB  (-1.0f * VCP_TORNADO_MENU_ANGLE/ 180.0f * VFX_PI)
        VfxFloat angleBBB = offset * VCP_TWIST_MENU_OPT_BBB;

        RT.m[0] = RT.m[10] = vfxCos(angleBBB);
        RT.m[8] = vfxSin(angleBBB);
        RT.m[2] = -1 * RT.m[8];
    }
    
    // Now we multiply cameraView, RT and modelview to get totalProject. 
    //totalProject = cameraView * RT * modelView;
    
    //totalProject = cameraView;
    //totalProject *= RT;
    //totalProject *= modelView;

    // Set as 3x3 matrix for VRT rendering.
    //target_frame->transform.type = VRT_TRANSFORM_TYPE_MATRIX3X3; 
    //totalProject.initMatrix3x3(target_frame->transform.data.matrix3x3);

    // optimize above code
    target_frame->transform.type = VRT_TRANSFORM_TYPE_MATRIX3X3; 
    VfxFloat temp = RT.m[2] * modelView.m[12] + RT.m[14];
    target_frame->transform.data.matrix3x3.m[0] = RT.m[0] + cameraView.m[8] * RT.m[2];
    target_frame->transform.data.matrix3x3.m[3] = 0;
    target_frame->transform.data.matrix3x3.m[6] = RT.m[0] * modelView.m[12] + RT.m[12] + cameraView.m[8] * temp + cameraView.m[12];
    target_frame->transform.data.matrix3x3.m[1] = cameraView.m[9] * RT.m[2];
    target_frame->transform.data.matrix3x3.m[4] = 1.0f;
    target_frame->transform.data.matrix3x3.m[7] = modelView.m[13] + RT.m[13] + cameraView.m[9] * temp + cameraView.m[13];
    target_frame->transform.data.matrix3x3.m[2] = cameraView.m[11] * RT.m[2];
    target_frame->transform.data.matrix3x3.m[5] = 0;
    target_frame->transform.data.matrix3x3.m[8] = cameraView.m[11] * temp + cameraView.m[15];
    
    target_frame->pos_z = RT.m[14];

    // adjust opacity
    // boundary check
    
    // check addional 10 item
    if (offset > VCP_TORNADO_MENU_BEHIND_COUNT + 10)
    {
        target_frame->opacity = 1.0f - (offset - VCP_TORNADO_MENU_BEHIND_COUNT);
        if (target_frame->opacity < 0)
        {
            target_frame->opacity = 0;
        }    
    }
    else if (offset < -1 * VCP_TORNADO_MENU_AHEAD_COUNT)
    {
        //target_frame->opacity = 1.0f - (-1 * VCP_TORNADO_MENU_AHEAD_COUNT - offset);
        target_frame->opacity = 1.0f + VCP_TORNADO_MENU_AHEAD_COUNT + offset;
        if (target_frame->opacity < 0)
        {
            target_frame->opacity = 0;
        }
    }
    else
    {
        if (1)
        {
            VfxFloat shift;
            // We want the item far from the screen opacity near to 0.5,
            // and close to screen near to 1.
            // This code also relative to the number in a circle and the
            // total number of cell in screen. if you add more items,
            // you need to add enough if check
            if (offset > -16 && offset <= -8)
            {
                shift = VFX_ABS(offset - (-12));
            }
            else if (offset > -8  && offset <= 0)
            {
                shift = VFX_ABS(offset - (-4));
            }
            else if (offset > 0 && offset <= 8)
            {
                shift = VFX_ABS(offset - (4));
            }
            else if (offset > 8 && offset <= 16)
            {
                shift = VFX_ABS(offset - (12));
            }
            else if (offset > 16 && offset <= 24)
            {
                shift = VFX_ABS(offset - (20));
            }
            else
            {
                shift = 4;
            }
            //target_frame->opacity = shift / 4 * 0.5 + 0.5;
            target_frame->opacity = shift * 0.125f + 0.5f;
        }
        else
        {
            target_frame->opacity = 1;
        }
    }

#if 1
    if (VFX_ABS(t) < 0.3f)
    {
        VfxFloat tempT = VFX_ABS(t)/0.3f;
        target_frame->transform.data.matrix3x3.m[0] = (tempT)  * target_frame->transform.data.matrix3x3.m[0] + (1 - tempT) * 1;
        target_frame->transform.data.matrix3x3.m[1] = (tempT)  * target_frame->transform.data.matrix3x3.m[1] ;
        target_frame->transform.data.matrix3x3.m[2] = (tempT)  * target_frame->transform.data.matrix3x3.m[2] ;
        target_frame->transform.data.matrix3x3.m[3] = (tempT)  * target_frame->transform.data.matrix3x3.m[3] ;
        target_frame->transform.data.matrix3x3.m[4] = (tempT)  * target_frame->transform.data.matrix3x3.m[4] + (1 - tempT) * 1;
        target_frame->transform.data.matrix3x3.m[5] = (tempT)  * target_frame->transform.data.matrix3x3.m[5] ;
        target_frame->transform.data.matrix3x3.m[6] = (tempT)  * target_frame->transform.data.matrix3x3.m[6] + (1 - tempT) * orinX;
        target_frame->transform.data.matrix3x3.m[7] = (tempT)  * target_frame->transform.data.matrix3x3.m[7] + (1 - tempT) * orinY;
        target_frame->transform.data.matrix3x3.m[8] = (tempT)  * target_frame->transform.data.matrix3x3.m[8] + (1 - tempT) * 1;
    }

    if (VFX_ABS(t) > 0.9)
    {
        VfxFloat tempT = (VFX_ABS(t) - 0.9f)/0.1f;
        target_frame->opacity = 1 - tempT;
		if (target_frame->opacity < 0)
		{
			target_frame->opacity = 0;
		}
    }
    else if (t == 0)
    {
        target_frame->opacity = 1.0f;
    }
#endif
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

#ifdef __MTK_TARGET__
#pragma thumb
#endif

#endif//#ifdef __VCP_PAGE_MENU_TRANSITION_TORNADO__

#ifdef __VCP_PAGE_MENU_TRANSITION_CUBE__

/*****************************************************************************
 * Class VcpPageMenuCubeTransition
 *****************************************************************************/
#if defined(__MMI_MAINLCD_480X800__)
#define VCP_CUBE_TRANSITION_CAMERA_DISTANCE                              (1000)
#else // __MMI_MAINLCD_320X480__ __MMI_MAINLCD_240X400__ __MMI_MAINLCD_240X320__
#define VCP_CUBE_TRANSITION_CAMERA_DISTANCE                              (520) 
#endif

VCP_PAGE_MENU_TRANSITION_OBJ_IMPLEMENT(VcpPageMenuCubeTransition);

void VcpPageMenuCubeTransition::onInit()
{
    m_angle = 90.0f;
}

#ifdef __MTK_TARGET__
#pragma arm
#endif

vrt_render_dirty_type_enum VcpPageMenuCubeTransition::onTransition(
    vrt_float t,
    VfxS32 direction,
    vrt_s32 indexX, vrt_s32 indexY,
    const VcpPageMenuLayout & layout,
    vrt_s32 mainmenuWidth,
    vrt_s32 mainmenuHeight,
    vrt_frame_visual_property_struct *target_frame) const
{

    VFX_DEV_ASSERT(target_frame != NULL);

    target_frame->pos.x = 0;
    target_frame->pos.y = 0;

    VfxFloat tempYAngle;
    VfxFloat cameraDistance;
    VfxFloat ZShift;
    if (m_angle == 90.0f)
    {
        //m_angle 90 degree : 90 = 180 - m_angle;
        tempYAngle =  -t * (90.0f);
        //0.414214f * mainmenuWidth/2 = mainmenuWidth/2 / cos(m_angle/2) - mainmenuWidth/2 * tan(m_angle/2)
        //                            =  mainmenuWidth/2 * (sqrt(2) - 1)
        //                            =  0.414214f * mainmenuWidth/2
        cameraDistance = VCP_CUBE_TRANSITION_CAMERA_DISTANCE + 0.414214f * mainmenuWidth/2 * vfxSin(VFX_ABS(tempYAngle)/90.0f * VFX_PI);
        // Zhift = tan(m_angle/2) * mainmenuWidth/2
        ZShift = (VfxFloat)mainmenuWidth/2;
    }
    else
    {
        //m_angle 120 degree :  60 = 180 - m_angle;
        tempYAngle =  -t * (60.0f);
        //0.133975f * mainmenuWidth = mainmenuWidth/2 / cos(m_angle/2) - mainmenuWidth/2 * tan(m_angle/2)
        //                          = mainmenuWidth - sqrt(3)/2 * mainmenuWidth;
        //                          = 0.133975f * mainmenuWidth
        cameraDistance = VCP_CUBE_TRANSITION_CAMERA_DISTANCE + 0.133975f * mainmenuWidth * vfxSin(VFX_ABS(tempYAngle)/60.0f * VFX_PI);
        // Zhift = tan(m_angle/2) * mainmenuWidth/2
        ZShift = mainmenuWidth * 0.866025f;
    }
    
    VfxMatrix4x4 RotatebyYMatrix;
    VfxMatrix4x4 totalProject;
   
    VfxMatrix4x4 model;
    VfxS32 orinX = layout.cellStartX + indexX * layout.cellOffsetX;
    VfxS32 orinY = layout.cellStartY + indexY * layout.cellOffsetY;

    RotatebyYMatrix.setRotateByY(VFX_DEG_TO_RAD(tempYAngle));

    totalProject.setCamera( 
        1.0f,
        1.0f, 
        (VfxFloat)(mainmenuWidth/2), 
        (VfxFloat)(mainmenuHeight/2), 
        VCP_CUBE_TRANSITION_CAMERA_DISTANCE - ZShift, 
        cameraDistance, 
        0,
        0, 
        0);
    
    totalProject *= RotatebyYMatrix;

    model.setTranslation(VfxFloat(orinX - mainmenuWidth / 2), VfxFloat(orinY - mainmenuHeight / 2), -ZShift);
    
    totalProject *= model;

    VfxTransform tempTransform;
    totalProject.initMatrix3x3(tempTransform.data.matrix3x3);
    tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

    tempTransform.initVrtTransform(target_frame->transform);

    // do Culling
    VfxFloat det;
    VfxFloat *m = target_frame->transform.data.matrix3x3.m;
    det = ((m[0] * m[4] * m[8]) + (m[6] * m[1] * m[5]) + (m[3] * m[7] * m[2]) -
               (m[3] * m[1] * m[8]) - (m[0] * m[7] * m[5]) - (m[6] * m[4] * m[2])) *
              ((m[2] + m[8]) * (m[5] + m[8]) * m[8]);

    if (det < 0)
    {
        target_frame->opacity = 0;
    }
    
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

#ifdef __MTK_TARGET__
#pragma thumb
#endif


/*****************************************************************************
 * Class VcpPageCubeTransition
 *****************************************************************************/

VCP_PAGE_MENU_TRANSITION_OBJ_IMPLEMENT(VcpPageMenuHexagonalPrismTransition);

void VcpPageMenuHexagonalPrismTransition::onInit()
{
    m_angle = 120.0f;
}
#endif//#ifdef __VCP_PAGE_MENU_TRANSITION_CUBE__

#endif // defined(__MMI_VUI_3D_MAINMENU__) || defined(__COSMOS_MMI__) || defined(__MMI_VUI_LAUNCHER__)|| defined(__MMI_VUI_LAUNCHER_KEY__)

#endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__

