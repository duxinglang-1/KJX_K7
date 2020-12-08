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
 *  vapp_launcher_cosmos_page_transition.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the desktop page transition class.
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

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_include.h"
#include "vfx_uc_include.h"

#include "vapp_launcher_cosmos_page_transition.h"


//
// C headers
//
extern "C"
{
#if defined(VAPP_HOME_UT_ENABLE_SWLA_LOG)
#include "SST_sla.h"
#endif
}

VFX_IMPLEMENT_VIRTUAL_CLASS("VappLauncherCosmosPageTransition", VappLauncherCosmosPageTransition, VfxObject);


/*****************************************************************************
 * Normal Transition class
 *****************************************************************************/
VAPP_LAUNCHER_COSMOS_PAGE_TRANSITION_IMPLEMENT_CLASS(VappLauncherCosmosPageTransitionNormal, VappLauncherCosmosPageTransition);

vrt_render_dirty_type_enum VappLauncherCosmosPageTransitionNormal::onTransition(
    vrt_float t,
    vrt_s32 homeWidth,
    vrt_s32 homeHeight,
    vrt_s32 pagePosX, 
    vrt_s32 pagePosY,
    vrt_s32 boundsTranslateX,
    vrt_frame_visual_property_struct *target_frame
) const
{
    target_frame->pos.x = homeWidth * t + boundsTranslateX;
    target_frame->pos.y = 0;

    return VRT_RENDER_DIRTY_TYPE_DIRTY;


/*

    VfxMatrix4x4 camera;
    // camera Matrix
    camera.setCamera(
                1.0f,
                1.0f,
                VfxFloat(homeWidth / 2),
                VfxFloat(homeHeight / 2),
                VfxFloat(240.0f),
                VfxFloat(240.0f),
                VfxFloat(0.0f),
                VfxFloat(0.0f),
                VfxFloat(0.0f) );

    VfxMatrix4x4 transform = camera;

    target_frame->pos.x = 0;
    target_frame->pos.y = 0;
    VfxMatrix4x4 model, totalProject;
    model.setTranslation(homeWidth * t - homeWidth/2, -homeHeight/2, 0);

    totalProject = camera * model;

    // because desktop will chagne bounds when slide, 
    // so the target which is put on desktop needs to modify translation for it's bounds changed.
    VfxMatrix4x4 translationForBoundsChanged;
    translationForBoundsChanged.setTranslation(boundsTranslateX, 0, 0);

    //totalProject = translationForBoundsChanged * totalProject;
    totalProject = camera * translationForBoundsChanged * model;
    
    VfxTransform tempTransform;
    totalProject.initMatrix3x3(tempTransform.data.matrix3x3);
    tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

    tempTransform.initVrtTransform(target_frame->transform);
    
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
*/
}


/*****************************************************************************
 * Photo Wall Transition class
 *****************************************************************************/
VAPP_LAUNCHER_COSMOS_PAGE_TRANSITION_IMPLEMENT_CLASS(VappLauncherCosmosPageTransitionPhotoWall, VappLauncherCosmosPageTransition);

// 1: inner grid
// 2: outer grid
const VfxS32 VappLauncherCosmosPageTransitionPhotoWall::s_transitionPhotoWallType = 2;

vrt_render_dirty_type_enum VappLauncherCosmosPageTransitionPhotoWall::onTransition(
    vrt_float t,
    vrt_s32 homeWidth,
    vrt_s32 homeHeight,
    vrt_s32 pagePosX, 
    vrt_s32 pagePosY,
    vrt_s32 boundsTranslateX,
    vrt_frame_visual_property_struct *target_frame
) const
{
    VfxMatrix4x4 camera;
    // camera Matrix
    camera.setCamera(
                1.0f,
                1.0f,
                VfxFloat(homeWidth / 2)  + boundsTranslateX, // desktop has bounds changed,
                VfxFloat(homeHeight / 2),
                VfxFloat(240.0f),
                VfxFloat(240.0f),
                VfxFloat(0.0f),
                VfxFloat(0.0f),
                VfxFloat(0.0f) );

    // rotate Matrix

    VfxFloat fromFloat = 0;
    VfxFloat toFloat = -25;
    VfxFloat interpolate;

    if (s_transitionPhotoWallType == 1)
    {
        toFloat = 25;
    }
    
    if (1)
    {
        interpolate = fromFloat + (toFloat - fromFloat) * vfxSin(t * VFX_PI);
    }
    else
    {
        interpolate = (fromFloat) + (toFloat - fromFloat) * t;
    }

    if (s_transitionPhotoWallType == 0)
    {
        interpolate = VFX_ABS(interpolate);
    }

    VfxMatrix4x4 rotateByY;
    rotateByY.setRotateByY(VFX_DEG_TO_RAD(interpolate) );


    VfxMatrix4x4 transform = camera * rotateByY;

    target_frame->pos.x = 0;
    target_frame->pos.y = 0;
    VfxMatrix4x4 model, totalProject;
    model.setTranslation(homeWidth*t-homeWidth/2, -homeHeight/2, 0);

    totalProject = transform * model;

    //VfxMatrix4x4 translationForBoundsChanged;
    //translationForBoundsChanged.setTranslation(boundsTranslateX, 0, 0);

    //totalProject = translationForBoundsChanged * totalProject;
    
    VfxTransform tempTransform;
    totalProject.initMatrix3x3(tempTransform.data.matrix3x3);
    tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

    tempTransform.initVrtTransform(target_frame->transform);
    
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}


/*****************************************************************************
 * Cube Transition class
 *****************************************************************************/
VAPP_LAUNCHER_COSMOS_PAGE_TRANSITION_IMPLEMENT_CLASS(VappLauncherCosmosPageTransitionCube, VappLauncherCosmosPageTransition);

#define VAPP_LAUNCHER_COSMOS_CUBE_TRANSITION_CAMERA_DISTANCE                              (520) 

void VappLauncherCosmosPageTransitionCube::onInit()
{
    VappLauncherCosmosPageTransition::onInit();
    m_angle = 120.0f;
}


vrt_render_dirty_type_enum VappLauncherCosmosPageTransitionCube::onTransition(
    vrt_float t,
    vrt_s32 homeWidth,
    vrt_s32 homeHeight,
    vrt_s32 pagePosX, 
    vrt_s32 pagePosY,
    vrt_s32 boundsTranslateX,
    vrt_frame_visual_property_struct *target_frame
) const
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
        cameraDistance = VAPP_LAUNCHER_COSMOS_CUBE_TRANSITION_CAMERA_DISTANCE + 0.414214f * homeWidth/2 * vfxSin(VFX_ABS(tempYAngle)/90.0f * VFX_PI);
        // Zhift = tan(m_angle/2) * mainmenuWidth/2
        ZShift = (VfxFloat)homeWidth/2;
    }
    else
    {
        //m_angle 120 degree :  60 = 180 - m_angle;
        tempYAngle =  -t * (60.0f);
        //0.133975f * mainmenuWidth = mainmenuWidth/2 / cos(m_angle/2) - mainmenuWidth/2 * tan(m_angle/2)
        //                          = mainmenuWidth - sqrt(3) * mainmenuWidth;
        //                          = 0.133975f * mainmenuWidth
        cameraDistance = VAPP_LAUNCHER_COSMOS_CUBE_TRANSITION_CAMERA_DISTANCE + 0.133975f * homeWidth * vfxSin(VFX_ABS(tempYAngle)/60.0f * VFX_PI);
        // Zhift = tan(m_angle/2) * mainmenuWidth/2
        ZShift = homeWidth * 0.866025f;
    }
    
    VfxMatrix4x4 RotatebyYMatrix;
    VfxMatrix4x4 totalProject;
   
    VfxMatrix4x4 model;
    RotatebyYMatrix.setRotateByY(VFX_DEG_TO_RAD(tempYAngle));

    totalProject.setCamera( 
        1.0f,
        1.0f, 
        (VfxFloat)(homeWidth/2) + boundsTranslateX, // desktop has bounds changed, 
        (VfxFloat)(homeHeight/2), 
        VAPP_LAUNCHER_COSMOS_CUBE_TRANSITION_CAMERA_DISTANCE - ZShift, 
        cameraDistance, 
        0,
        0, 
        0);
    
    //VfxMatrix4x4 translationForBoundsChanged;
    //translationForBoundsChanged.setTranslation(boundsTranslateX, 0, 0);

    //totalProject = translationForBoundsChanged * totalProject;

    totalProject *= RotatebyYMatrix;

    model.setTranslation(VfxFloat(-homeWidth/2), VfxFloat(-homeHeight/2), -ZShift);
    
    totalProject *= model;
    
    VfxTransform tempTransform;
    totalProject.initMatrix3x3(tempTransform.data.matrix3x3);
    tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

    tempTransform.initVrtTransform(target_frame->transform);

/*
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
*/
    return VRT_RENDER_DIRTY_TYPE_DIRTY;

}


/*****************************************************************************
 * Robot Transition class
 *****************************************************************************/
VAPP_LAUNCHER_COSMOS_PAGE_TRANSITION_IMPLEMENT_CLASS(VappLauncherCosmosPageTransitionRobot, VappLauncherCosmosPageTransition);

#if defined(__MMI_MAINLCD_480X800__)
#define VAPP_LAUNCHER_COSMOS_ROBOT_TRANSITION_CAMERA_DISTANCE                              (1000)
#else // __MMI_MAINLCD_320X480__ __MMI_MAINLCD_240X400__ __MMI_MAINLCD_240X320__
#define VAPP_LAUNCHER_COSMOS_ROBOT_TRANSITION_CAMERA_DISTANCE                              (520) 
#endif

void VappLauncherCosmosPageTransitionRobot::onInit()
{
    VappLauncherCosmosPageTransition::onInit();
    m_angle = 120.0f;
}


vrt_render_dirty_type_enum VappLauncherCosmosPageTransitionRobot::onTransition(
    vrt_float t,
    vrt_s32 homeWidth,
    vrt_s32 homeHeight,
    vrt_s32 pagePosX, 
    vrt_s32 pagePosY,
    vrt_s32 boundsTranslateX,
    vrt_frame_visual_property_struct *target_frame
) const
{
    VFX_DEV_ASSERT(target_frame != NULL);

    // avoid compute transform when t is integrer,
    // because when t == 0, computing transform will have error that is not computed as indentity matrix
    if(t == -1 || t == 0 || t == 1)
    {
        target_frame->pos.x = homeWidth * t + boundsTranslateX;
        target_frame->pos.y = 0;
        target_frame->transform.type = VRT_TRANSFORM_TYPE_IDENTITY;
        
        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }

    VfxS32 tmpHomeWidth = 1.1 * homeWidth;
    
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
        cameraDistance = VAPP_LAUNCHER_COSMOS_ROBOT_TRANSITION_CAMERA_DISTANCE + 0.414214f * homeWidth/2 * vfxSin(VFX_ABS(tempYAngle)/90.0f * VFX_PI);
        // Zhift = tan(m_angle/2) * mainmenuWidth/2
        ZShift = (VfxFloat)homeWidth/2;
    }
    else
    {
        //m_angle 120 degree :  60 = 180 - m_angle;
        tempYAngle =  -t * (60.0f);
        //0.133975f * mainmenuWidth = mainmenuWidth/2 / cos(m_angle/2) - mainmenuWidth/2 * tan(m_angle/2)
        //                          = mainmenuWidth - sqrt(3) * mainmenuWidth;
        //                          = 0.133975f * mainmenuWidth
        cameraDistance = VAPP_LAUNCHER_COSMOS_ROBOT_TRANSITION_CAMERA_DISTANCE + 0.133975f * tmpHomeWidth * vfxSin(VFX_ABS(tempYAngle)/60.0f * VFX_PI);
        // Zhift = tan(m_angle/2) * mainmenuWidth/2
        ZShift = tmpHomeWidth * 0.866025f;
    }
    
    VfxMatrix4x4 RotatebyYMatrix;
    VfxMatrix4x4 totalProject;
   
    VfxMatrix4x4 model;
    RotatebyYMatrix.setRotateByY(VFX_DEG_TO_RAD(tempYAngle));

    totalProject.setCamera(
        1.0f,
        1.0f, 
        (VfxFloat)(homeWidth/2) + boundsTranslateX, // desktop has bounds changed
        (VfxFloat)(homeHeight/2), 
        VAPP_LAUNCHER_COSMOS_ROBOT_TRANSITION_CAMERA_DISTANCE - ZShift, 
        cameraDistance, 
        0,
        0, 
        0);
    
    //VfxMatrix4x4 translationForBoundsChanged;
    //translationForBoundsChanged.setTranslation(boundsTranslateX, 0, 0);

    //totalProject = translationForBoundsChanged * totalProject;

    totalProject *= RotatebyYMatrix;

    model.setTranslation(VfxFloat(-homeWidth/2), VfxFloat(-homeHeight/2), -ZShift);
    
    totalProject *= model;  
    
    VfxTransform tempTransform;
    totalProject.initMatrix3x3(tempTransform.data.matrix3x3);
    tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

    tempTransform.initVrtTransform(target_frame->transform);

/*
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
*/
    return VRT_RENDER_DIRTY_TYPE_DIRTY;

}

