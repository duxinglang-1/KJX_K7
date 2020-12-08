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
 *  vapp_launcher_robot_page_transition.cpp
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


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_include.h"
#include "vfx_uc_include.h"

#include "vapp_launcher_robot_page_transition.h"


//
// C headers
//
extern "C"
{
#include "math.h"
#if defined(VAPP_HOME_UT_ENABLE_SWLA_LOG)
#include "SST_sla.h"
#endif
}

VFX_IMPLEMENT_VIRTUAL_CLASS("VappLauncherRobotPageTransition", VappLauncherRobotPageTransition, VfxObject);


/*****************************************************************************
 * Normal Transition class
 *****************************************************************************/
VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_IMPLEMENT_CLASS(VappLauncherRobotPageTransitionNormal, VappLauncherRobotPageTransition);

vrt_render_dirty_type_enum VappLauncherRobotPageTransitionNormal::onTransition(
    vrt_float ratio,
    vrt_float t,
    vrt_s32 homeWidth,
    vrt_s32 homeHeight,
    vrt_s32 oriDesktopBoundsX,
    vrt_s32 nexDesktopBoundsX,
    vrt_s32 totalTranslateLength,
    vrt_frame_visual_property_struct *target_frame
) const
{
    target_frame->opacity = 1;
    target_frame->transform.type = VRT_TRANSFORM_TYPE_IDENTITY;

    target_frame->pos.x = homeWidth * t + oriDesktopBoundsX;
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
VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_IMPLEMENT_CLASS(VappLauncherRobotPageTransitionPhotoWall, VappLauncherRobotPageTransition);

// 1: inner grid
// 2: outer grid
const VfxS32 VappLauncherRobotPageTransitionPhotoWall::s_transitionPhotoWallType = 2;

vrt_render_dirty_type_enum VappLauncherRobotPageTransitionPhotoWall::onTransition(
    vrt_float ratio,
    vrt_float t,
    vrt_s32 homeWidth,
    vrt_s32 homeHeight,
    vrt_s32 oriDesktopBoundsX,
    vrt_s32 nexDesktopBoundsX,
    vrt_s32 totalTranslateLength,
    vrt_frame_visual_property_struct *target_frame
) const
{
    target_frame->opacity = 1;

    VfxMatrix4x4 camera;
    // camera Matrix
    camera.setCamera(
                1.0f,
                1.0f,
                VfxFloat(homeWidth / 2)  + oriDesktopBoundsX, // desktop has bounds changed,
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
 * Robot Transition class
 *****************************************************************************/
VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_IMPLEMENT_CLASS(VappLauncherRobotPageTransitionRobot, VappLauncherRobotPageTransition);

#if defined(__MMI_MAINLCD_480X800__)
#define VAPP_LAUNCHER_ROBOT_ROBOT_TRANSITION_CAMERA_DISTANCE                              (1000)
#else // __MMI_MAINLCD_320X480__ __MMI_MAINLCD_240X400__ __MMI_MAINLCD_240X320__
#define VAPP_LAUNCHER_ROBOT_ROBOT_TRANSITION_CAMERA_DISTANCE                              (520) 
#endif

void VappLauncherRobotPageTransitionRobot::onInit()
{
    VappLauncherRobotPageTransition::onInit();
    m_angle = 120.0f;
}


vrt_render_dirty_type_enum VappLauncherRobotPageTransitionRobot::onTransition(
    vrt_float ratio,
    vrt_float t,
    vrt_s32 homeWidth,
    vrt_s32 homeHeight,
    vrt_s32 oriDesktopBoundsX,
    vrt_s32 nexDesktopBoundsX,
    vrt_s32 totalTranslateLength,
    vrt_frame_visual_property_struct *target_frame
) const
{
    target_frame->opacity = 1;

    VFX_DEV_ASSERT(target_frame != NULL);

    // avoid compute transform when t is integrer,
    // because when t == 0, computing transform will have error that is not computed as indentity matrix
    if(t == -1 || t == 0 || t == 1)
    {
        target_frame->pos.x = homeWidth * t + oriDesktopBoundsX;
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
        cameraDistance = VAPP_LAUNCHER_ROBOT_ROBOT_TRANSITION_CAMERA_DISTANCE + 0.414214f * homeWidth/2 * vfxSin(VFX_ABS(tempYAngle)/90.0f * VFX_PI);
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
        cameraDistance = VAPP_LAUNCHER_ROBOT_ROBOT_TRANSITION_CAMERA_DISTANCE + 0.133975f * tmpHomeWidth * vfxSin(VFX_ABS(tempYAngle)/60.0f * VFX_PI);
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
        (VfxFloat)(homeWidth/2) + oriDesktopBoundsX, // desktop has bounds changed
        (VfxFloat)(homeHeight/2), 
        VAPP_LAUNCHER_ROBOT_ROBOT_TRANSITION_CAMERA_DISTANCE - ZShift, 
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
 * Class VappLauncherRobotPageTransitionPentangleZoomIn
 *****************************************************************************/

#if defined(__MMI_MAINLCD_320X480__)
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_PENTANGLE_ZOOM_IN_CAMERA_DISTANCE (500)
#elif defined(__MMI_MAINLCD_480X800__)
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_PENTANGLE_ZOOM_IN_CAMERA_DISTANCE (800)
#else
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_PENTANGLE_ZOOM_IN_CAMERA_DISTANCE (500)
#endif

#define PI 3.1415926535897932384626433832795f

VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_IMPLEMENT_CLASS(VappLauncherRobotPageTransitionPentangleZoomIn, VappLauncherRobotPageTransition);

void VappLauncherRobotPageTransitionPentangleZoomIn::onDeinit()
{
    for (VfxS32 i = 0; i < m_maxNumDesktopPage; i++)
    {
        VFX_DELETE(m_model[i]);
    }

    VFX_FREE_MEM(m_model);
}


void VappLauncherRobotPageTransitionPentangleZoomIn::onInitTransition(
    VfxS32 homeWidth,
    VfxS32 homeHeight,
    VfxS32 maxNumDesktopPage)
{
    m_maxNumDesktopPage = maxNumDesktopPage;
    
    VFX_ALLOC_MEM(m_model, maxNumDesktopPage * sizeof(VfxMatrix4x4 *), this);

    for (VfxS32 i = 0; i < maxNumDesktopPage; i++)
    {
        VFX_ALLOC_NEW(m_model[i], VfxMatrix4x4, this);
    }

    VfxFloat perAngle = 360.0f / maxNumDesktopPage;
    VfxFloat angle = 54.0 * PI / 180.0f;
    VfxFloat dist1 = (vrt_float)homeWidth * tan(angle) / 2;
    
    for(VfxS32 i=0; i<maxNumDesktopPage; i++)
    {
        VfxMatrix4x4 model1;
        model1.setTranslation(VfxFloat(-homeWidth/2), VfxFloat(-homeHeight/2), 0); 

        VfxFloat angleB;
        angleB = -i*perAngle;

        VfxMatrix4x4 rotate2;
        rotate2.setRotateByZ(VFX_DEG_TO_RAD(angleB));
        
        VfxFloat radius = dist1 + homeHeight/2;
        
        VfxMatrix4x4 model2;
        VfxFloat sinB = vfxSin(VFX_DEG_TO_RAD(angleB));
        VfxFloat cosB = vfxCos(VFX_DEG_TO_RAD(angleB));
        
        model2.setTranslation(-radius * sinB, radius * cosB, 0);
        
        *(m_model[i]) =  model2 * rotate2 * model1;

    }
}


vrt_render_dirty_type_enum VappLauncherRobotPageTransitionPentangleZoomIn::onTransition(
    vrt_float ratio,
    vrt_float t,
    vrt_s32 homeWidth,
    vrt_s32 homeHeight,
    vrt_s32 oriDesktopBoundsX,
    vrt_s32 nexDesktopBoundsX,
    vrt_s32 totalTranslateLength,
    vrt_frame_visual_property_struct *target_frame) const
{
    target_frame->opacity = 1;

    VfxMatrix4x4 camera;
    camera.setCamera(
                1.0f,
                1.0f,
                VfxFloat(homeWidth / 2) + oriDesktopBoundsX,
                VfxFloat(homeHeight / 2) /* - 175 */,
                VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_PENTANGLE_ZOOM_IN_CAMERA_DISTANCE),
                VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_PENTANGLE_ZOOM_IN_CAMERA_DISTANCE),
                VfxFloat(0.0f),   // 400
                VfxFloat(0.0f),
                VfxFloat(0.0f)); 

    // rotate Matrix

    VfxFloat fromFloat = 0;
    VfxFloat toFloat = -360.0f / m_maxNumDesktopPage; // -180
    VfxFloat interpolate;

    VfxS32 pageIndex = target_frame->fpe_user_0/homeWidth;

    interpolate = (fromFloat) + (toFloat - fromFloat) * (t - pageIndex);
    //interpolate = 0;

    VfxMatrix4x4 rotateByZ;
    rotateByZ.setRotateByZ(VFX_DEG_TO_RAD(interpolate));

    //VfxFloat perAngle = 360.0f / m_maxNumDesktopPage;
    VfxFloat angle = 54.0f * PI/ 180.0f;
    VfxFloat dist1 = (vrt_float)homeWidth * tan(angle)/2;
    VfxMatrix4x4 trans3;
    trans3.setTranslation(0,-(dist1 + homeHeight/2),0);

    // rotate Matrix
    target_frame->pos.x = 0;
    target_frame->pos.y = 0;

    VfxMatrix4x4 totalProject;
    //totalProject = camera * rotateByY * *(m_model[pageIndex]);
    totalProject = camera * trans3 * rotateByZ * *(m_model[pageIndex]);

    target_frame->pos_z = totalProject.m[14];

    VfxTransform tempTransform;
    totalProject.initMatrix3x3(tempTransform.data.matrix3x3);
    tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

    tempTransform.initVrtTransform(target_frame->transform);
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}


/*****************************************************************************
 * Class VappLauncherRobotPageTransitionTrangleZoomIn
 *****************************************************************************/

#if defined(__MMI_MAINLCD_320X480__)
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_TRANGLE_ZOOM_IN_CAMERA_DISTANCE (500)
#elif defined(__MMI_MAINLCD_480X800__)
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_TRANGLE_ZOOM_IN_CAMERA_DISTANCE (500)
#else
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_TRANGLE_ZOOM_IN_CAMERA_DISTANCE (500)
#endif

#define PI 3.1415926535897932384626433832795f

VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_IMPLEMENT_CLASS(VappLauncherRobotPageTransitionTrangleZoomIn, VappLauncherRobotPageTransition);


void VappLauncherRobotPageTransitionTrangleZoomIn::onInitTransition(
    VfxS32 homeWidth,
    VfxS32 homeHeight,
    VfxS32 maxNumDesktopPage)
{
    m_maxNumDesktopPage = maxNumDesktopPage;
}


vrt_render_dirty_type_enum VappLauncherRobotPageTransitionTrangleZoomIn::onTransition(
    vrt_float ratio,
    vrt_float t,
    vrt_s32 homeWidth,
    vrt_s32 homeHeight,
    vrt_s32 oriDesktopBoundsX,
    vrt_s32 nexDesktopBoundsX,
    vrt_s32 totalTranslateLength,
    vrt_frame_visual_property_struct *target_frame) const
{
        VfxS32 pivotValue = (m_maxNumDesktopPage+1)/2;
        if(t >= pivotValue)
        {
            t = t - m_maxNumDesktopPage;
        }
        else if(t <= -pivotValue)
        {
            t = t + m_maxNumDesktopPage;
        }
    
        target_frame->pos.x = 0;
        target_frame->pos.y = 0;
    
        // rotate Matrix
        //VfxFloat toFloat2 = VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_TRANGLE_ZOOM_IN_CAMERA_DISTANCE;
        //VfxFloat interpolate2;
        
        VfxFloat objectDis = VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_TRANGLE_ZOOM_IN_CAMERA_DISTANCE;

        VfxMatrix4x4 camera;
        camera.setCamera(
                    1.0f,
                    1.0f,
                    VfxFloat(homeWidth / 2) + oriDesktopBoundsX,
                    VfxFloat(homeHeight / 2) /* - 175 */,
                    VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_TRANGLE_ZOOM_IN_CAMERA_DISTANCE),
                    objectDis, //VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_TRANGLE_ZOOM_OUT_CAMERA_DISTANCE*2),
                    VfxFloat(0.0f),   // 400
                    VfxFloat(0.0f),
                    VfxFloat(0.0f)); 
    
    
        VfxMatrix4x4 model1;
        model1.setTranslation(VfxFloat(-homeWidth/2), VfxFloat(-homeHeight/2), 0); 
        
        vrt_float angleB;
        angleB = 40.0f * t;

/*
        if(t > 0)
        {
            kal_printf("angleB = %f, t = %f \n", angleB, t);
        }
 */       
        VfxMatrix4x4 rotate2;
        rotate2.setRotateByY(VFX_DEG_TO_RAD(angleB));
        
        VfxFloat shiftPerT = (vrt_float)homeWidth * 1.5f;
    
        VfxFloat transX = shiftPerT*VFX_ABS(t)*vfxCos(VFX_DEG_TO_RAD(55.0f));
        VfxFloat transZ = shiftPerT*VFX_ABS(t)*vfxSin(VFX_DEG_TO_RAD(55.0f));
    
        VfxMatrix4x4 translate;
        if(t<0)
        {
            transX = -transX;
        }
        translate.setTranslation(transX, 0, transZ);
        
        VfxMatrix4x4 totalProject;
        totalProject = camera * translate * rotate2 * model1;
    
        target_frame->pos_z = totalProject.m[14];
    
        VfxTransform tempTransform;
        totalProject.initMatrix3x3(tempTransform.data.matrix3x3);
        tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;
    
        tempTransform.initVrtTransform(target_frame->transform);

        if (VFX_ABS(t) > 0.9f)
        {
            VfxFloat tempT = (VFX_ABS(t) - 0.9f)/0.1f;
            target_frame->opacity = 1.0f - tempT;
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


#if !defined(VAPP_LAUNCHER_ROBOT_REDUCE_PAGE_SIZE_DURING_TRANSITION)
/*****************************************************************************
 * Class VappLauncherRobotPageTransitionCylinder
 *****************************************************************************/

#if defined(__MMI_MAINLCD_320X480__)
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_RADIUS (500)
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_NEAR   (600)
#elif defined(__MMI_MAINLCD_480X800__)
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_RADIUS (500)
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_NEAR   (600)
#else
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_RADIUS (500)
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_NEAR   (600)
#endif

VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_IMPLEMENT_CLASS(VappLauncherRobotPageTransitionCylinder, VappLauncherRobotPageTransition);

void VappLauncherRobotPageTransitionCylinder::onDeinit()
{
    for (VfxS32 i = 0; i < m_maxNumDesktopPage; i++)
    {
        VFX_DELETE(m_model[i]);
    }

    VFX_FREE_MEM(m_model);
}


void VappLauncherRobotPageTransitionCylinder::onInitTransition(
    VfxS32 homeWidth,
    VfxS32 homeHeight,
    VfxS32 maxNumDesktopPage)
{
    m_maxNumDesktopPage = maxNumDesktopPage;
    
    VFX_ALLOC_MEM(m_model, maxNumDesktopPage * sizeof(VfxMatrix4x4 *), this);

    for (VfxS32 i = 0; i < maxNumDesktopPage; i++)
    {
        VFX_ALLOC_NEW(m_model[i], VfxMatrix4x4, this);
    }

    VfxS32 perAngle = 360.0f / maxNumDesktopPage;

    for(VfxS32 i=0; i<maxNumDesktopPage; i++)
    {
        VfxMatrix4x4 model1;
        model1.setTranslation(VfxFloat(-homeWidth/2), VfxFloat(-homeHeight/2), 0); 
        VfxFloat angleB;
        angleB = i*perAngle;

        VfxMatrix4x4 rotate2;
        rotate2.setRotateByY(VFX_DEG_TO_RAD(-angleB));
        
        VfxFloat radius = VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_RADIUS;
        
        VfxMatrix4x4 model2;
        VfxFloat sinB = vfxSin(VFX_DEG_TO_RAD(angleB));
        VfxFloat cosB = vfxCos(VFX_DEG_TO_RAD(angleB));
        
        model2.setTranslation(radius * sinB, 0, -radius * cosB);
        
        *(m_model[i]) =  model2 * rotate2 * model1;

    }
}


vrt_render_dirty_type_enum VappLauncherRobotPageTransitionCylinder::onTransition(
    vrt_float ratio,
    vrt_float t,
    vrt_s32 homeWidth,
    vrt_s32 homeHeight,
    vrt_s32 oriDesktopBoundsX,
    vrt_s32 nexDesktopBoundsX,
    vrt_s32 totalTranslateLength,
    vrt_frame_visual_property_struct *target_frame) const
{
    target_frame->opacity = 1;

    // rotate Matrix
    //VfxFloat toFloat2 = 500;
    //VfxFloat interpolate2;
    
    //VfxFloat objDis = 100 + toFloat2*ratio;
    VfxFloat objDis = VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_NEAR*0.2;
    
    VfxMatrix4x4 camera;
    camera.setCamera(
                1.0f,
                1.0f,
                VfxFloat(homeWidth / 2) + oriDesktopBoundsX,
                VfxFloat(homeHeight / 2 - 175) /* - 175 */,
                VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_NEAR),
                VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_NEAR + VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_RADIUS + objDis),
                VfxFloat(300.0f),   // 400
                VfxFloat(0.0f),
                VfxFloat(0.0f)); 

    // rotate Matrix

    VfxFloat fromFloat = 0;
    VfxFloat toFloat = -360.0f/m_maxNumDesktopPage; // -180
    VfxFloat interpolate;

    VfxS32 pageIndex = target_frame->fpe_user_0/homeWidth;

    interpolate = (fromFloat) + (toFloat - fromFloat) * (t - pageIndex);
    //interpolate = 0;

    VfxMatrix4x4 rotateByY;
    rotateByY.setRotateByY(VFX_DEG_TO_RAD(interpolate));

    // rotate Matrix
    target_frame->pos.x = 0;
    target_frame->pos.y = 0;

    VfxMatrix4x4 totalProject;
    totalProject = camera * rotateByY * *(m_model[pageIndex]);

    target_frame->pos_z = totalProject.m[14];

    VfxTransform tempTransform;
    totalProject.initMatrix3x3(tempTransform.data.matrix3x3);
    tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

    tempTransform.initVrtTransform(target_frame->transform);

    vrt_float zoomInBoundary = VFX_ABS(vrt_float(homeWidth)/totalTranslateLength);
    //if((target_frame->fpe_user_0 == nexDesktopBoundsX && (ratio >= 1-zoomInBoundary && ratio <= 1.0f)) ||
    //   (target_frame->fpe_user_0 == oriDesktopBoundsX && (ratio <= zoomInBoundary && ratio >= 0.0f )))
    if((target_frame->fpe_user_0 == nexDesktopBoundsX && (ratio >= 1-zoomInBoundary && ratio <= 1.0f)))
    {
        VfxMatrix4x4 camera2;
        VfxMatrix4x4 model2;
        VfxMatrix4x4 trans2;

        camera2.setCamera(
                    1.0f,
                    1.0f,
                    VfxFloat(homeWidth / 2) + oriDesktopBoundsX,
                    VfxFloat(homeHeight / 2) /* - 175 */,
                    VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_NEAR),
                    VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_NEAR),
                    VfxFloat(0.0f),   // 400
                    VfxFloat(0.0f),
                    VfxFloat(0.0f)); 

        model2.setTranslation(VfxFloat(-homeWidth/2), VfxFloat(-homeHeight/2), 0); 

        if(ratio <= zoomInBoundary && ratio >= 0.0f )
        {
            trans2.setTranslation(target_frame->fpe_user_0 - oriDesktopBoundsX,0,0);
        }
        else if(ratio >= 1-zoomInBoundary && ratio <= 1.0f)
        {
            trans2.setTranslation(target_frame->fpe_user_0 - nexDesktopBoundsX,0,0);
        }

        VfxMatrix4x4 totalProject2;
        totalProject2 = camera2 * trans2 * model2;

        VfxTransform tempTransform2;
        totalProject2.initMatrix3x3(tempTransform2.data.matrix3x3);
        tempTransform2.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

        if(ratio >= 1-zoomInBoundary)
        {
            ratio = 1-ratio;
        }
        VfxFloat tempT = VFX_ABS(ratio)/zoomInBoundary;
        target_frame->transform.data.matrix3x3.m[0] = (tempT)  * target_frame->transform.data.matrix3x3.m[0] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[0]);
        target_frame->transform.data.matrix3x3.m[1] = (tempT)  * target_frame->transform.data.matrix3x3.m[1] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[1]);
        target_frame->transform.data.matrix3x3.m[2] = (tempT)  * target_frame->transform.data.matrix3x3.m[2] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[2]);
        target_frame->transform.data.matrix3x3.m[3] = (tempT)  * target_frame->transform.data.matrix3x3.m[3] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[3]);
        target_frame->transform.data.matrix3x3.m[4] = (tempT)  * target_frame->transform.data.matrix3x3.m[4] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[4]);
        target_frame->transform.data.matrix3x3.m[5] = (tempT)  * target_frame->transform.data.matrix3x3.m[5] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[5]);
        target_frame->transform.data.matrix3x3.m[6] = (tempT)  * target_frame->transform.data.matrix3x3.m[6] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[6]);
        target_frame->transform.data.matrix3x3.m[7] = (tempT)  * target_frame->transform.data.matrix3x3.m[7] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[7]);
        target_frame->transform.data.matrix3x3.m[8] = (tempT)  * target_frame->transform.data.matrix3x3.m[8] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[8]);
    }
    else
    {
        if (VFX_ABS(ratio) > 0.9)
        {
            VfxFloat tempT = (VFX_ABS(ratio) - 0.9f)/0.1f;
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
    }
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}


/*****************************************************************************
 * Class VappLauncherRobotPageTransitionPentangleZoomOut
 *****************************************************************************/

#if defined(__MMI_MAINLCD_320X480__)
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_PENTANGLE_ZOOM_OUT_CAMERA_DISTANCE (500)
#elif defined(__MMI_MAINLCD_480X800__)
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_PENTANGLE_ZOOM_OUT_CAMERA_DISTANCE (800)
#else
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_PENTANGLE_ZOOM_OUT_CAMERA_DISTANCE (500)
#endif

#define PI 3.1415926535897932384626433832795f

VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_IMPLEMENT_CLASS(VappLauncherRobotPageTransitionPentangleZoomOut, VappLauncherRobotPageTransition);

void VappLauncherRobotPageTransitionPentangleZoomOut::onDeinit()
{
    for (VfxS32 i = 0; i < m_maxNumDesktopPage; i++)
    {
        VFX_DELETE(m_model[i]);
    }

    VFX_FREE_MEM(m_model);
}


void VappLauncherRobotPageTransitionPentangleZoomOut::onInitTransition(
    VfxS32 homeWidth,
    VfxS32 homeHeight,
    VfxS32 maxNumDesktopPage)
{
    m_maxNumDesktopPage = maxNumDesktopPage;
    
    VFX_ALLOC_MEM(m_model, maxNumDesktopPage * sizeof(VfxMatrix4x4 *), this);

    for (VfxS32 i = 0; i < maxNumDesktopPage; i++)
    {
        VFX_ALLOC_NEW(m_model[i], VfxMatrix4x4, this);
    }

    VfxFloat perAngle = 360.0f / maxNumDesktopPage;
    VfxFloat angle = 54.0 * PI / 180.0f;
    VfxFloat dist1 = homeWidth*tan(angle)/2;
    
    for(VfxS32 i=0; i<maxNumDesktopPage; i++)
    {
        VfxMatrix4x4 model1;
        model1.setTranslation(VfxFloat(-homeWidth/2), VfxFloat(-homeHeight/2), 0); 

        VfxFloat angleB;
        angleB = -i*perAngle;

        VfxMatrix4x4 rotate2;
        rotate2.setRotateByZ(VFX_DEG_TO_RAD(angleB));
        
        VfxFloat radius = dist1 + homeHeight/2;
        
        VfxMatrix4x4 model2;
        VfxFloat sinB = vfxSin(VFX_DEG_TO_RAD(angleB));
        VfxFloat cosB = vfxCos(VFX_DEG_TO_RAD(angleB));
        
        model2.setTranslation(-radius * sinB, radius * cosB, 0);
        
        *(m_model[i]) =  model2 * rotate2 * model1;

    }
}


vrt_render_dirty_type_enum VappLauncherRobotPageTransitionPentangleZoomOut::onTransition(
    vrt_float ratio,
    vrt_float t,
    vrt_s32 homeWidth,
    vrt_s32 homeHeight,
    vrt_s32 oriDesktopBoundsX,
    vrt_s32 nexDesktopBoundsX,
    vrt_s32 totalTranslateLength,
    vrt_frame_visual_property_struct *target_frame) const
{
    target_frame->opacity = 1;

    // rotate Matrix
    VfxFloat toFloat2 = VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_PENTANGLE_ZOOM_OUT_CAMERA_DISTANCE*2;
    //VfxFloat interpolate2;
    
    VfxFloat objectDis = VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_PENTANGLE_ZOOM_OUT_CAMERA_DISTANCE*1.5 + toFloat2*ratio;
    
    VfxMatrix4x4 camera;
    camera.setCamera(
                1.0f,
                1.0f,
                VfxFloat(homeWidth / 2) + oriDesktopBoundsX,
                VfxFloat(homeHeight / 2) /* - 175 */,
                VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_PENTANGLE_ZOOM_OUT_CAMERA_DISTANCE),
                objectDis, //VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_PENTANGLE_ZOOM_OUT_CAMERA_DISTANCE*2),
                VfxFloat(0.0f),   // 400
                VfxFloat(-15.0f),
                VfxFloat(0.0f)); 

    // rotate Matrix
    VfxFloat fromFloat = 0;
    VfxFloat toFloat = -360.0f/m_maxNumDesktopPage; // -180
    VfxFloat interpolate;

    VfxS32 pageIndex = target_frame->fpe_user_0/homeWidth;

    interpolate = (fromFloat) + (toFloat - fromFloat) * (t - pageIndex);
    //interpolate = 0;

    VfxMatrix4x4 rotateByZ;
    rotateByZ.setRotateByZ(VFX_DEG_TO_RAD(interpolate));

    // rotate Matrix
    target_frame->pos.x = 0;
    target_frame->pos.y = 0;

    // translate down a little for better UI 
    VfxMatrix4x4 trans3;
    trans3.setTranslation(0,-homeHeight/5,0);

    VfxMatrix4x4 totalProject;
    totalProject = camera * trans3 * rotateByZ * *(m_model[pageIndex]);

    target_frame->pos_z = totalProject.m[14];

    VfxTransform tempTransform;
    totalProject.initMatrix3x3(tempTransform.data.matrix3x3);
    tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

    tempTransform.initVrtTransform(target_frame->transform);

    vrt_float zoomInBoundary = VFX_ABS(vrt_float(homeWidth)/totalTranslateLength);
    //if((target_frame->fpe_user_0 == nexDesktopBoundsX && (ratio >= 1-zoomInBoundary && ratio <= 1.0f)) ||
    //   (target_frame->fpe_user_0 == oriDesktopBoundsX && (ratio <= zoomInBoundary && ratio >= 0.0f )))
    if((target_frame->fpe_user_0 == nexDesktopBoundsX && (ratio >= 1-zoomInBoundary && ratio <= 1.0f)))
    {
        VfxMatrix4x4 camera2;
        VfxMatrix4x4 model2;
        VfxMatrix4x4 trans2;

        camera2.setCamera(
                    1.0f,
                    1.0f,
                    VfxFloat(homeWidth / 2) + oriDesktopBoundsX,
                    VfxFloat(homeHeight / 2) /* - 175 */,
                    VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_PENTANGLE_ZOOM_OUT_CAMERA_DISTANCE),
                    VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_PENTANGLE_ZOOM_OUT_CAMERA_DISTANCE),
                    VfxFloat(0.0f),   // 400
                    VfxFloat(0.0f),
                    VfxFloat(0.0f)); 

        model2.setTranslation(VfxFloat(-homeWidth/2), VfxFloat(-homeHeight/2), 0); 

        if(ratio <= zoomInBoundary && ratio >= 0.0f )
        {
            trans2.setTranslation(target_frame->fpe_user_0 - oriDesktopBoundsX,0,0);
        }
        else if(ratio >= 1-zoomInBoundary && ratio <= 1.0f)
        {
            trans2.setTranslation(target_frame->fpe_user_0 - nexDesktopBoundsX,0,0);
        }

        VfxMatrix4x4 totalProject2;
        totalProject2 = camera2 * trans2 * model2;

        VfxTransform tempTransform2;
        totalProject2.initMatrix3x3(tempTransform2.data.matrix3x3);
        tempTransform2.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

        if(ratio >= 1-zoomInBoundary)
        {
            ratio = 1-ratio;
        }
        VfxFloat tempT = VFX_ABS(ratio)/zoomInBoundary;
        target_frame->transform.data.matrix3x3.m[0] = (tempT)  * target_frame->transform.data.matrix3x3.m[0] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[0]);
        target_frame->transform.data.matrix3x3.m[1] = (tempT)  * target_frame->transform.data.matrix3x3.m[1] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[1]);
        target_frame->transform.data.matrix3x3.m[2] = (tempT)  * target_frame->transform.data.matrix3x3.m[2] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[2]);
        target_frame->transform.data.matrix3x3.m[3] = (tempT)  * target_frame->transform.data.matrix3x3.m[3] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[3]);
        target_frame->transform.data.matrix3x3.m[4] = (tempT)  * target_frame->transform.data.matrix3x3.m[4] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[4]);
        target_frame->transform.data.matrix3x3.m[5] = (tempT)  * target_frame->transform.data.matrix3x3.m[5] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[5]);
        target_frame->transform.data.matrix3x3.m[6] = (tempT)  * target_frame->transform.data.matrix3x3.m[6] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[6]);
        target_frame->transform.data.matrix3x3.m[7] = (tempT)  * target_frame->transform.data.matrix3x3.m[7] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[7]);
        target_frame->transform.data.matrix3x3.m[8] = (tempT)  * target_frame->transform.data.matrix3x3.m[8] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[8]);
    }
    else
    {
        if (VFX_ABS(ratio) > 0.9)
        {
            VfxFloat tempT = (VFX_ABS(ratio) - 0.9f)/0.1f;
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
    }
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}


/*****************************************************************************
 * Class VappLauncherRobotPageTransitionTrangleZoomOut
 *****************************************************************************/

#if defined(__MMI_MAINLCD_320X480__)
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_TRANGLE_ZOOM_OUT_CAMERA_DISTANCE (400)
#elif defined(__MMI_MAINLCD_480X800__)
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_TRANGLE_ZOOM_OUT_CAMERA_DISTANCE (400)
#else
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_TRANGLE_ZOOM_OUT_CAMERA_DISTANCE (400)
#endif

#define PI 3.1415926535897932384626433832795f

VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_IMPLEMENT_CLASS(VappLauncherRobotPageTransitionTrangleZoomOut, VappLauncherRobotPageTransition);


void VappLauncherRobotPageTransitionTrangleZoomOut::onInitTransition(
    VfxS32 homeWidth,
    VfxS32 homeHeight,
    VfxS32 maxNumDesktopPage)
{
    m_maxNumDesktopPage = maxNumDesktopPage;
}


vrt_render_dirty_type_enum VappLauncherRobotPageTransitionTrangleZoomOut::onTransition(
    vrt_float ratio,
    vrt_float t,
    vrt_s32 homeWidth,
    vrt_s32 homeHeight,
    vrt_s32 oriDesktopBoundsX,
    vrt_s32 nexDesktopBoundsX,
    vrt_s32 totalTranslateLength,
    vrt_frame_visual_property_struct *target_frame) const
{
    target_frame->opacity = 1;

    VfxS32 pivotValue = (m_maxNumDesktopPage+1)/2;
    if(t >= pivotValue)
    {
        t = t - m_maxNumDesktopPage;
    }
    else if(t <= -pivotValue)
    {
        t = t + m_maxNumDesktopPage;
    }

    target_frame->pos.x = 0;
    target_frame->pos.y = 0;

    // rotate Matrix
    VfxFloat toFloat2 = VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_TRANGLE_ZOOM_OUT_CAMERA_DISTANCE;
    //VfxFloat interpolate2;
    
    VfxFloat objectDis = VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_TRANGLE_ZOOM_OUT_CAMERA_DISTANCE + toFloat2*ratio;
    
    VfxMatrix4x4 camera;
    camera.setCamera(
                1.0f,
                1.0f,
                VfxFloat(homeWidth / 2) + oriDesktopBoundsX,
                VfxFloat(homeHeight / 2) - 200 /* - 175 */,
                VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_TRANGLE_ZOOM_OUT_CAMERA_DISTANCE),
                objectDis, //VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_TRANGLE_ZOOM_OUT_CAMERA_DISTANCE*2),
                VfxFloat(400.0f),   // 400
                VfxFloat(0.0f),
                VfxFloat(0.0f)); 


    VfxMatrix4x4 model1;
    model1.setTranslation(VfxFloat(-homeWidth/2), VfxFloat(-homeHeight/2), 0); 
    
    vrt_float angleB;
    angleB = 40.0f * t;

    VfxMatrix4x4 rotate2;
    rotate2.setRotateByY(VFX_DEG_TO_RAD(angleB));
    
    VfxFloat shiftPerT = (vrt_float)homeWidth * 1.5f;

    VfxFloat transX = shiftPerT*VFX_ABS(t)*vfxCos(VFX_DEG_TO_RAD(55.0f));
    VfxFloat transZ = shiftPerT*VFX_ABS(t)*vfxSin(VFX_DEG_TO_RAD(55.0f));

    VfxMatrix4x4 translate;
    if(t<0)
    {
        transX = -transX;
    }
    translate.setTranslation(transX, 0, transZ);
    
    VfxMatrix4x4 totalProject;
    totalProject = camera * translate * rotate2 * model1;

    target_frame->pos_z = totalProject.m[14];

    VfxTransform tempTransform;
    totalProject.initMatrix3x3(tempTransform.data.matrix3x3);
    tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

    tempTransform.initVrtTransform(target_frame->transform);

    vrt_float zoomInBoundary = VFX_ABS(vrt_float(homeWidth)/totalTranslateLength);

    //if((target_frame->fpe_user_0 == nexDesktopBoundsX && (ratio >= 1-zoomInBoundary && ratio <= 1.0f)) ||
    //   (target_frame->fpe_user_0 == oriDesktopBoundsX && (ratio <= zoomInBoundary && ratio >= 0.0f )))
    if((target_frame->fpe_user_0 == nexDesktopBoundsX && (ratio >= 1-zoomInBoundary && ratio <= 1.0f)))
    {
        VfxMatrix4x4 camera2;
        VfxMatrix4x4 model2;
        VfxMatrix4x4 trans2;

        camera2.setCamera(
                    1.0f,
                    1.0f,
                    VfxFloat(homeWidth / 2) + oriDesktopBoundsX,
                    VfxFloat(homeHeight / 2) /* - 175 */,
                    VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_NEAR),
                    VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_NEAR),
                    VfxFloat(0.0f),   // 400
                    VfxFloat(0.0f),
                    VfxFloat(0.0f)); 

        model2.setTranslation(VfxFloat(-homeWidth/2), VfxFloat(-homeHeight/2), 0); 

        if(ratio <= zoomInBoundary && ratio >= 0.0f )
        {
            trans2.setTranslation(target_frame->fpe_user_0 - oriDesktopBoundsX,0,0);
        }
        else if(ratio >= 1-zoomInBoundary && ratio <= 1.0f)
        {
            trans2.setTranslation(target_frame->fpe_user_0 - nexDesktopBoundsX,0,0);
        }

        VfxMatrix4x4 totalProject2;
        totalProject2 = camera2 * trans2 * model2;

        VfxTransform tempTransform2;
        totalProject2.initMatrix3x3(tempTransform2.data.matrix3x3);
        tempTransform2.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

        if(ratio >= 1-zoomInBoundary)
        {
            ratio = 1-ratio;
        }
        
        VfxFloat tempT = VFX_ABS(ratio)/zoomInBoundary;
        target_frame->transform.data.matrix3x3.m[0] = (tempT)  * target_frame->transform.data.matrix3x3.m[0] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[0]);
        target_frame->transform.data.matrix3x3.m[1] = (tempT)  * target_frame->transform.data.matrix3x3.m[1] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[1]);
        target_frame->transform.data.matrix3x3.m[2] = (tempT)  * target_frame->transform.data.matrix3x3.m[2] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[2]);
        target_frame->transform.data.matrix3x3.m[3] = (tempT)  * target_frame->transform.data.matrix3x3.m[3] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[3]);
        target_frame->transform.data.matrix3x3.m[4] = (tempT)  * target_frame->transform.data.matrix3x3.m[4] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[4]);
        target_frame->transform.data.matrix3x3.m[5] = (tempT)  * target_frame->transform.data.matrix3x3.m[5] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[5]);
        target_frame->transform.data.matrix3x3.m[6] = (tempT)  * target_frame->transform.data.matrix3x3.m[6] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[6]);
        target_frame->transform.data.matrix3x3.m[7] = (tempT)  * target_frame->transform.data.matrix3x3.m[7] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[7]);
        target_frame->transform.data.matrix3x3.m[8] = (tempT)  * target_frame->transform.data.matrix3x3.m[8] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[8]);
    }
    else
    {
        if (VFX_ABS(ratio) > 0.9)
        {
            VfxFloat tempT = (VFX_ABS(ratio) - 0.9f)/0.1f;
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
    }

    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}


#else /* !defined(VAPP_LAUNCHER_ROBOT_REDUCE_PAGE_SIZE_DURING_TRANSITION) */

/*****************************************************************************
 * Class VappLauncherRobotPageTransitionCylinderSlim
 *****************************************************************************/

#if defined(__MMI_MAINLCD_320X480__)
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_SLIM_RADIUS (480)
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_SLIM_NEAR   (600)
#elif defined(__MMI_MAINLCD_480X800__)
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_SLIM_RADIUS (500)
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_SLIM_NEAR   (600)
#else
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_SLIM_RADIUS (500)
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_SLIM_NEAR   (600)
#endif

VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_IMPLEMENT_CLASS(VappLauncherRobotPageTransitionCylinderSlim, VappLauncherRobotPageTransition);

void VappLauncherRobotPageTransitionCylinderSlim::onDeinit()
{
    for (VfxS32 i = 0; i < m_maxNumDesktopPage; i++)
    {
        VFX_DELETE(m_model[i]);
    }

    VFX_FREE_MEM(m_model);
}


void VappLauncherRobotPageTransitionCylinderSlim::onInitTransition(
    VfxS32 homeWidth,
    VfxS32 homeHeight,
    VfxS32 maxNumDesktopPage)
{
    m_maxNumDesktopPage = maxNumDesktopPage;
    
    VFX_ALLOC_MEM(m_model, maxNumDesktopPage * sizeof(VfxMatrix4x4 *), this);

    for (VfxS32 i = 0; i < maxNumDesktopPage; i++)
    {
        VFX_ALLOC_NEW(m_model[i], VfxMatrix4x4, this);
    }
}


void VappLauncherRobotPageTransitionCylinderSlim::onInitTransitionForSlim(
        VfxRect oriPageRect,
        VfxRect resizePageRect)
{
    m_oriPageRect = oriPageRect;
    m_resizePageRect = resizePageRect;
}

vrt_render_dirty_type_enum VappLauncherRobotPageTransitionCylinderSlim::onTransition(
    vrt_float ratio,
    vrt_float t,
    vrt_s32 homeWidth,
    vrt_s32 homeHeight,
    vrt_s32 oriDesktopBoundsX,
    vrt_s32 nexDesktopBoundsX,
    vrt_s32 totalTranslateLength,
    vrt_frame_visual_property_struct *target_frame) const
{
    target_frame->opacity = 1;

    VfxS32 pageIndex = target_frame->fpe_user_0/m_oriPageRect.getWidth();

    // rotate Matrix
    //VfxFloat toFloat2 = 500;
    //VfxFloat interpolate2;
    
    //VfxFloat objDis = 100 + toFloat2*ratio;
    VfxFloat objDis = VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_SLIM_NEAR*0.2;
    
    VfxMatrix4x4 camera;
    camera.setCamera(
                1.0f,
                1.0f,
                VfxFloat(m_oriPageRect.getWidth() / 2) + oriDesktopBoundsX,
                VfxFloat(m_oriPageRect.getHeight() / 2 - 130) /* - 175 */,
                VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_SLIM_NEAR),
                VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_SLIM_NEAR + VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_SLIM_RADIUS + objDis),
                VfxFloat(200.0f),   // 400
                VfxFloat(0.0f),
                VfxFloat(0.0f)); 

    VfxS32 perAngle = 360/m_maxNumDesktopPage;
    
    VfxMatrix4x4 model1;
    model1.setTranslation(VfxFloat(-m_resizePageRect.getWidth()/2), VfxFloat(-m_resizePageRect.getHeight()/2), 0); 
    VfxFloat angleB;
    angleB = pageIndex*perAngle;

    VfxMatrix4x4 rotate2;
    rotate2.setRotateByY(VFX_DEG_TO_RAD(-angleB));
    
    VfxFloat radius = VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_SLIM_RADIUS;
    
    VfxMatrix4x4 model2;
    VfxFloat sinB = vfxSin(VFX_DEG_TO_RAD(angleB));
    VfxFloat cosB = vfxCos(VFX_DEG_TO_RAD(angleB));
    
    model2.setTranslation(radius * sinB, 0, -radius * cosB);
    
    *(m_model[pageIndex]) =  model2 * rotate2 * model1;

    // rotate Matrix
    VfxFloat fromFloat = 0;
    VfxFloat toFloat = -360.0f/m_maxNumDesktopPage; // -180
    VfxFloat interpolate;

    interpolate = (fromFloat) + (toFloat - fromFloat) * (t - pageIndex);
    //interpolate = 0;

    VfxMatrix4x4 rotateByY;
    rotateByY.setRotateByY(VFX_DEG_TO_RAD(interpolate));

    // rotate Matrix
    target_frame->pos.x = 0;
    target_frame->pos.y = 0;

    VfxMatrix4x4 totalProject;
    totalProject = camera * rotateByY * *(m_model[pageIndex]);

    target_frame->pos_z = totalProject.m[14];

    VfxTransform tempTransform;
    totalProject.initMatrix3x3(tempTransform.data.matrix3x3);
    tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

    tempTransform.initVrtTransform(target_frame->transform);

    vrt_float zoomInBoundary = VFX_ABS(vrt_float(homeWidth)/totalTranslateLength);
    //if((target_frame->fpe_user_0 == nexDesktopBoundsX && (ratio >= 1-zoomInBoundary && ratio <= 1.0f)) ||
    //   (target_frame->fpe_user_0 == oriDesktopBoundsX && (ratio <= zoomInBoundary && ratio >= 0.0f )))
    if((target_frame->fpe_user_0 == nexDesktopBoundsX && (ratio >= 1-zoomInBoundary && ratio <= 1.0f)))
    {
        VfxMatrix4x4 camera2;
        VfxMatrix4x4 model2;
        VfxMatrix4x4 trans2;
        VfxMatrix4x4 scale2;

        camera2.setCamera(
                    1.0f,
                    1.0f,
                    VfxFloat(m_oriPageRect.getWidth() / 2) + oriDesktopBoundsX,
                    VfxFloat(m_oriPageRect.getHeight() / 2) /* - 175 */,
                    VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_SLIM_NEAR),
                    VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_CYLINDER_SLIM_NEAR),
                    VfxFloat(0.0f),   // 400
                    VfxFloat(0.0f),
                    VfxFloat(0.0f)); 

        model2.setTranslation(VfxFloat(-m_resizePageRect.getWidth()/2), VfxFloat(-m_resizePageRect.getHeight()/2), 0); 

        if(ratio <= zoomInBoundary && ratio >= 0.0f )
        {
            trans2.setTranslation(target_frame->fpe_user_0 - oriDesktopBoundsX,0,0);
        }
        else if(ratio >= 1-zoomInBoundary && ratio <= 1.0f)
        {
            trans2.setTranslation(target_frame->fpe_user_0 - nexDesktopBoundsX,0,0);
        }

        // scale resized page to the full screen size
        if(homeWidth == m_resizePageRect.getWidth())
        {
            scale2.setScale((vrt_float)m_oriPageRect.getWidth()/m_resizePageRect.getWidth(), (vrt_float)m_oriPageRect.getHeight()/m_resizePageRect.getHeight(), 1.0);
        }

        VfxMatrix4x4 totalProject2;
        totalProject2 = camera2 * scale2 * trans2 * model2;

        VfxTransform tempTransform2;
        totalProject2.initMatrix3x3(tempTransform2.data.matrix3x3);
        tempTransform2.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

        if(ratio >= 1-zoomInBoundary)
        {
            ratio = 1-ratio;
        }
        VfxFloat tempT = VFX_ABS(ratio)/zoomInBoundary;
        target_frame->transform.data.matrix3x3.m[0] = (tempT)  * target_frame->transform.data.matrix3x3.m[0] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[0]);
        target_frame->transform.data.matrix3x3.m[1] = (tempT)  * target_frame->transform.data.matrix3x3.m[1] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[1]);
        target_frame->transform.data.matrix3x3.m[2] = (tempT)  * target_frame->transform.data.matrix3x3.m[2] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[2]);
        target_frame->transform.data.matrix3x3.m[3] = (tempT)  * target_frame->transform.data.matrix3x3.m[3] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[3]);
        target_frame->transform.data.matrix3x3.m[4] = (tempT)  * target_frame->transform.data.matrix3x3.m[4] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[4]);
        target_frame->transform.data.matrix3x3.m[5] = (tempT)  * target_frame->transform.data.matrix3x3.m[5] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[5]);
        target_frame->transform.data.matrix3x3.m[6] = (tempT)  * target_frame->transform.data.matrix3x3.m[6] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[6]);
        target_frame->transform.data.matrix3x3.m[7] = (tempT)  * target_frame->transform.data.matrix3x3.m[7] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[7]);
        target_frame->transform.data.matrix3x3.m[8] = (tempT)  * target_frame->transform.data.matrix3x3.m[8] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[8]);
    }
    else
    {
        if (VFX_ABS(ratio) > 0.7)
        {
            VfxFloat tempT = (VFX_ABS(ratio) - 0.7f)/0.3f;
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
    }
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}


/*****************************************************************************
 * Class VappLauncherRobotPageTransitionPentangleZoomOutSlim
 *****************************************************************************/

#if defined(__MMI_MAINLCD_320X480__)
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_PENTANGLE_ZOOM_OUT_SLIM_CAMERA_DISTANCE (500)
#elif defined(__MMI_MAINLCD_480X800__)
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_PENTANGLE_ZOOM_OUT_SLIM_CAMERA_DISTANCE (800)
#else
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_PENTANGLE_ZOOM_OUT_SLIM_CAMERA_DISTANCE (500)
#endif

#define PI 3.1415926535897932384626433832795f

VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_IMPLEMENT_CLASS(VappLauncherRobotPageTransitionPentangleZoomOutSlim, VappLauncherRobotPageTransition);

void VappLauncherRobotPageTransitionPentangleZoomOutSlim::onDeinit()
{
    for (VfxS32 i = 0; i < m_maxNumDesktopPage; i++)
    {
        VFX_DELETE(m_model[i]);
    }

    VFX_FREE_MEM(m_model);
}


void VappLauncherRobotPageTransitionPentangleZoomOutSlim::onInitTransition(
    VfxS32 homeWidth,
    VfxS32 homeHeight,
    VfxS32 maxNumDesktopPage)
{
    m_maxNumDesktopPage = maxNumDesktopPage;
    
    VFX_ALLOC_MEM(m_model, maxNumDesktopPage * sizeof(VfxMatrix4x4 *), this);

    for (VfxS32 i = 0; i < maxNumDesktopPage; i++)
    {
        VFX_ALLOC_NEW(m_model[i], VfxMatrix4x4, this);
    }
}


void VappLauncherRobotPageTransitionPentangleZoomOutSlim::onInitTransitionForSlim(
        VfxRect oriPageRect,
        VfxRect resizePageRect)
{
    m_oriPageRect = oriPageRect;
    m_resizePageRect = resizePageRect;
}


vrt_render_dirty_type_enum VappLauncherRobotPageTransitionPentangleZoomOutSlim::onTransition(
    vrt_float ratio,
    vrt_float t,
    vrt_s32 homeWidth,
    vrt_s32 homeHeight,
    vrt_s32 oriDesktopBoundsX,
    vrt_s32 nexDesktopBoundsX,
    vrt_s32 totalTranslateLength,
    vrt_frame_visual_property_struct *target_frame) const
{
    target_frame->opacity = 1;

    VfxFloat perAngle = 360.0f / m_maxNumDesktopPage;
    VfxFloat angle = 54.0f * PI / 180.0f;
    VfxFloat dist1 = m_resizePageRect.getWidth()*tan(angle)/2;

    VfxS32 pageIndex = target_frame->fpe_user_0/m_oriPageRect.getWidth();
    VfxMatrix4x4 model1;
    model1.setTranslation(VfxFloat(-m_resizePageRect.getWidth()/2), VfxFloat(-m_resizePageRect.getHeight()/2), 0);  

    VfxFloat angleB;
    angleB = -pageIndex*perAngle;

    VfxMatrix4x4 rotate2;
    rotate2.setRotateByZ(VFX_DEG_TO_RAD(angleB));
    
    VfxFloat radius = dist1 + m_resizePageRect.getHeight()/2;
    
    VfxMatrix4x4 model2;
    VfxFloat sinB = vfxSin(VFX_DEG_TO_RAD(angleB));
    VfxFloat cosB = vfxCos(VFX_DEG_TO_RAD(angleB));
    
    model2.setTranslation(-radius * sinB, radius * cosB, 0);
    
    *(m_model[pageIndex]) =  model2 * rotate2 * model1;

    // rotate Matrix
    VfxFloat toFloat2 = VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_PENTANGLE_ZOOM_OUT_SLIM_CAMERA_DISTANCE*1.7;
    //VfxFloat interpolate2;
    
    VfxFloat objectDis = VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_PENTANGLE_ZOOM_OUT_SLIM_CAMERA_DISTANCE*1 + toFloat2*ratio;
    
    VfxMatrix4x4 camera;
    camera.setCamera(
                1.0f,
                1.0f,
                VfxFloat(m_oriPageRect.getWidth()/2) + oriDesktopBoundsX,
                VfxFloat(m_oriPageRect.getHeight()/ 2) /* - 175 */,
                VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_PENTANGLE_ZOOM_OUT_SLIM_CAMERA_DISTANCE),
                objectDis, //VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_PENTANGLE_ZOOM_OUT_CAMERA_DISTANCE*2),
                VfxFloat(0.0f),   // 400
                VfxFloat(-15.0f),
                VfxFloat(0.0f)); 

    // rotate Matrix
    VfxFloat fromFloat = 0;
    VfxFloat toFloat = -360.0f / m_maxNumDesktopPage; // -180
    VfxFloat interpolate;

    interpolate = (fromFloat) + (toFloat - fromFloat) * (t - pageIndex);
    //interpolate = 0;

    VfxMatrix4x4 rotateByZ;
    rotateByZ.setRotateByZ(VFX_DEG_TO_RAD(interpolate));

    // rotate Matrix
    target_frame->pos.x = 0;
    target_frame->pos.y = 0;

    // translate down a little for better UI 
    VfxMatrix4x4 trans3;
    trans3.setTranslation(0,-m_oriPageRect.getHeight()/5,0);

    VfxMatrix4x4 totalProject;
    totalProject = camera * trans3 * rotateByZ * *(m_model[pageIndex]);

    target_frame->pos_z = totalProject.m[14];

    VfxTransform tempTransform;
    totalProject.initMatrix3x3(tempTransform.data.matrix3x3);
    tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

    tempTransform.initVrtTransform(target_frame->transform);

    // zoomIn the focused page in the first/last period of animation
    // and fade out others page
    vrt_float zoomInBoundary = VFX_ABS(vrt_float(m_oriPageRect.getWidth())/totalTranslateLength);
    //if((target_frame->fpe_user_0 == nexDesktopBoundsX && (ratio >= 1-zoomInBoundary && ratio <= 1.0f)) ||
    //   (target_frame->fpe_user_0 == oriDesktopBoundsX && (ratio <= zoomInBoundary && ratio >= 0.0f )))
    if((target_frame->fpe_user_0 == nexDesktopBoundsX && (ratio >= 1-zoomInBoundary && ratio <= 1.0f)))
    {
        VfxMatrix4x4 camera2;
        VfxMatrix4x4 model2;
        VfxMatrix4x4 trans2;
        VfxMatrix4x4 scale2;

        camera2.setCamera(
                    1.0f,
                    1.0f,
                    VfxFloat(m_oriPageRect.getWidth() / 2) + oriDesktopBoundsX,
                    VfxFloat(m_oriPageRect.getHeight()/ 2) /* - 175 */,
                    VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_PENTANGLE_ZOOM_OUT_SLIM_CAMERA_DISTANCE),
                    VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_PENTANGLE_ZOOM_OUT_SLIM_CAMERA_DISTANCE),
                    VfxFloat(0.0f),   // 400
                    VfxFloat(0.0f),
                    VfxFloat(0.0f)); 

        model2.setTranslation(VfxFloat(-m_resizePageRect.getWidth()/2), VfxFloat(-m_resizePageRect.getHeight()/2), 0); 

        if(ratio <= zoomInBoundary && ratio >= 0.0f )
        {
            trans2.setTranslation(target_frame->fpe_user_0 - oriDesktopBoundsX,0,0);
        }
        else if(ratio >= 1-zoomInBoundary && ratio <= 1.0f)
        {
            trans2.setTranslation(target_frame->fpe_user_0 - nexDesktopBoundsX,0,0);
        }

        // scale resized page to the full screen size
        if(homeWidth == m_resizePageRect.getWidth())
        {
            scale2.setScale((vrt_float)m_oriPageRect.getWidth()/m_resizePageRect.getWidth(), (vrt_float)m_oriPageRect.getHeight()/m_resizePageRect.getHeight(), 1.0);
        }
        
        VfxMatrix4x4 totalProject2;
        totalProject2 = camera2 * scale2 * trans2 * model2;

        VfxTransform tempTransform2;
        totalProject2.initMatrix3x3(tempTransform2.data.matrix3x3);
        tempTransform2.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

        if(ratio >= 1-zoomInBoundary)
        {
            ratio = 1-ratio;
        }
        VfxFloat tempT = VFX_ABS(ratio)/zoomInBoundary;
        target_frame->transform.data.matrix3x3.m[0] = (tempT)  * target_frame->transform.data.matrix3x3.m[0] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[0]);
        target_frame->transform.data.matrix3x3.m[1] = (tempT)  * target_frame->transform.data.matrix3x3.m[1] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[1]);
        target_frame->transform.data.matrix3x3.m[2] = (tempT)  * target_frame->transform.data.matrix3x3.m[2] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[2]);
        target_frame->transform.data.matrix3x3.m[3] = (tempT)  * target_frame->transform.data.matrix3x3.m[3] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[3]);
        target_frame->transform.data.matrix3x3.m[4] = (tempT)  * target_frame->transform.data.matrix3x3.m[4] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[4]);
        target_frame->transform.data.matrix3x3.m[5] = (tempT)  * target_frame->transform.data.matrix3x3.m[5] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[5]);
        target_frame->transform.data.matrix3x3.m[6] = (tempT)  * target_frame->transform.data.matrix3x3.m[6] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[6]);
        target_frame->transform.data.matrix3x3.m[7] = (tempT)  * target_frame->transform.data.matrix3x3.m[7] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[7]);
        target_frame->transform.data.matrix3x3.m[8] = (tempT)  * target_frame->transform.data.matrix3x3.m[8] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[8]);
    }
    else
    {
        if (VFX_ABS(ratio) > 0.7)
        {
            VfxFloat tempT = (VFX_ABS(ratio) - 0.7f)/0.3f;
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
    }
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}


/*****************************************************************************
 * Class VappLauncherRobotPageTransitionTrangleZoomOutSlim
 *****************************************************************************/

#if defined(__MMI_MAINLCD_320X480__)
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_TRANGLE_ZOOM_OUT_SLIM_CAMERA_DISTANCE (400)
#elif defined(__MMI_MAINLCD_480X800__)
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_TRANGLE_ZOOM_OUT_SLIM_CAMERA_DISTANCE (400)
#else
#define VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_TRANGLE_ZOOM_OUT_SLIM_CAMERA_DISTANCE (400)
#endif

#define PI 3.1415926535897932384626433832795f

VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_IMPLEMENT_CLASS(VappLauncherRobotPageTransitionTrangleZoomOutSlim, VappLauncherRobotPageTransition);


void VappLauncherRobotPageTransitionTrangleZoomOutSlim::onInitTransition(
    VfxS32 homeWidth,
    VfxS32 homeHeight,
    VfxS32 maxNumDesktopPage)
{
    m_maxNumDesktopPage = maxNumDesktopPage;
}


void VappLauncherRobotPageTransitionTrangleZoomOutSlim::onInitTransitionForSlim(
        VfxRect oriPageRect,
        VfxRect resizePageRect)
{
    m_oriPageRect = oriPageRect;
    m_resizePageRect = resizePageRect;
}


vrt_render_dirty_type_enum VappLauncherRobotPageTransitionTrangleZoomOutSlim::onTransition(
    vrt_float ratio,
    vrt_float t,
    vrt_s32 homeWidth,
    vrt_s32 homeHeight,
    vrt_s32 oriDesktopBoundsX,
    vrt_s32 nexDesktopBoundsX,
    vrt_s32 totalTranslateLength,
    vrt_frame_visual_property_struct *target_frame) const
{
    target_frame->opacity = 1;

    VfxS32 pivotValue = (m_maxNumDesktopPage+1)/2;
    if(t >= pivotValue)
    {
        t = t - m_maxNumDesktopPage;
    }
    else if(t <= -pivotValue)
    {
        t = t + m_maxNumDesktopPage;
    }

    target_frame->pos.x = 0;
    target_frame->pos.y = 0;

    // rotate Matrix
    VfxFloat toFloat2 = VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_TRANGLE_ZOOM_OUT_SLIM_CAMERA_DISTANCE*0;
    //VfxFloat interpolate2;
    
    VfxFloat objectDis = VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_TRANGLE_ZOOM_OUT_SLIM_CAMERA_DISTANCE + toFloat2*ratio;
    
    VfxMatrix4x4 camera;
    camera.setCamera(
                1.0f,
                1.0f,
                VfxFloat(m_oriPageRect.getWidth() / 2) + oriDesktopBoundsX,
                VfxFloat(m_oriPageRect.getHeight() / 2) - 150,
                VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_TRANGLE_ZOOM_OUT_SLIM_CAMERA_DISTANCE),
                objectDis, //VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_TRANGLE_ZOOM_OUT_CAMERA_DISTANCE*2),
                VfxFloat(200.0f),   // 400
                VfxFloat(0.0f),
                VfxFloat(0.0f)); 


    VfxMatrix4x4 model1;
    model1.setTranslation(VfxFloat(-m_resizePageRect.getWidth()/2), VfxFloat(-m_resizePageRect.getHeight()/2), 0); 
    
    vrt_float angleB;
    angleB = 40.0f * t;

    VfxMatrix4x4 rotate2;
    rotate2.setRotateByY(VFX_DEG_TO_RAD(angleB));
    
    VfxFloat shiftPerT = m_resizePageRect.getWidth()*1.5;

    VfxFloat transX = shiftPerT*VFX_ABS(t)*vfxCos(VFX_DEG_TO_RAD(55));
    VfxFloat transZ = shiftPerT*VFX_ABS(t)*vfxSin(VFX_DEG_TO_RAD(55));

    VfxMatrix4x4 translate;
    if(t<0)
    {
        transX = -transX;
    }
    translate.setTranslation(transX, 0, transZ);
    
    VfxMatrix4x4 totalProject;
    totalProject = camera * translate * rotate2 * model1;

    target_frame->pos_z = totalProject.m[14];

    VfxTransform tempTransform;
    totalProject.initMatrix3x3(tempTransform.data.matrix3x3);
    tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

    tempTransform.initVrtTransform(target_frame->transform);

    vrt_float zoomInBoundary = VFX_ABS(vrt_float(homeWidth)/totalTranslateLength);

    //if((target_frame->fpe_user_0 == nexDesktopBoundsX && (ratio >= 1-zoomInBoundary && ratio <= 1.0f)) ||
    //   (target_frame->fpe_user_0 == oriDesktopBoundsX && (ratio <= zoomInBoundary && ratio >= 0.0f )))
    if((target_frame->fpe_user_0 == nexDesktopBoundsX && (ratio >= 1-zoomInBoundary && ratio <= 1.0f)))
    {
        VfxMatrix4x4 camera2;
        VfxMatrix4x4 model2;
        VfxMatrix4x4 trans2;
        VfxMatrix4x4 scale2;
        
        camera2.setCamera(
                    1.0f,
                    1.0f,
                    VfxFloat(m_oriPageRect.getWidth()/ 2) + oriDesktopBoundsX,
                    VfxFloat(m_oriPageRect.getHeight()/ 2) /* - 175 */,
                    VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_TRANGLE_ZOOM_OUT_SLIM_CAMERA_DISTANCE),
                    VfxFloat(VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_TRANGLE_ZOOM_OUT_SLIM_CAMERA_DISTANCE),
                    VfxFloat(0.0f),   // 400
                    VfxFloat(0.0f),
                    VfxFloat(0.0f)); 

        model2.setTranslation(VfxFloat(-m_resizePageRect.getWidth()/2), VfxFloat(-m_resizePageRect.getHeight()/2), 0); 

        if(ratio <= zoomInBoundary && ratio >= 0.0f )
        {
            trans2.setTranslation(target_frame->fpe_user_0 - oriDesktopBoundsX,0,0);
        }
        else if(ratio >= 1-zoomInBoundary && ratio <= 1.0f)
        {
            trans2.setTranslation(target_frame->fpe_user_0 - nexDesktopBoundsX,0,0);
        }

        // scale resized page to the full screen size
        if(homeWidth == m_resizePageRect.getWidth())
        {
            scale2.setScale((vrt_float)m_oriPageRect.getWidth()/m_resizePageRect.getWidth(), (vrt_float)m_oriPageRect.getHeight()/m_resizePageRect.getHeight(), 1.0);
        }

        VfxMatrix4x4 totalProject2;
        totalProject2 = camera2 * scale2 * trans2 * model2;

        VfxTransform tempTransform2;
        totalProject2.initMatrix3x3(tempTransform2.data.matrix3x3);
        tempTransform2.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

        if(ratio >= 1-zoomInBoundary)
        {
            ratio = 1-ratio;
        }
        
        VfxFloat tempT = VFX_ABS(ratio)/zoomInBoundary;
        target_frame->transform.data.matrix3x3.m[0] = (tempT)  * target_frame->transform.data.matrix3x3.m[0] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[0]);
        target_frame->transform.data.matrix3x3.m[1] = (tempT)  * target_frame->transform.data.matrix3x3.m[1] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[1]);
        target_frame->transform.data.matrix3x3.m[2] = (tempT)  * target_frame->transform.data.matrix3x3.m[2] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[2]);
        target_frame->transform.data.matrix3x3.m[3] = (tempT)  * target_frame->transform.data.matrix3x3.m[3] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[3]);
        target_frame->transform.data.matrix3x3.m[4] = (tempT)  * target_frame->transform.data.matrix3x3.m[4] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[4]);
        target_frame->transform.data.matrix3x3.m[5] = (tempT)  * target_frame->transform.data.matrix3x3.m[5] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[5]);
        target_frame->transform.data.matrix3x3.m[6] = (tempT)  * target_frame->transform.data.matrix3x3.m[6] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[6]);
        target_frame->transform.data.matrix3x3.m[7] = (tempT)  * target_frame->transform.data.matrix3x3.m[7] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[7]);
        target_frame->transform.data.matrix3x3.m[8] = (tempT)  * target_frame->transform.data.matrix3x3.m[8] + (1 - tempT) * (tempTransform2.data.matrix3x3.m[8]);
    }
    else
    {
        if (VFX_ABS(ratio) > 0.7)
        {
            VfxFloat tempT = (VFX_ABS(ratio) - 0.7f)/0.3f;
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
    }

    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}
#endif /* !defined(VAPP_LAUNCHER_ROBOT_REDUCE_PAGE_SIZE_DURING_TRANSITION) */
