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
 *  vapp_launcher_cosmos_page_transition.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_LAUNCHER_COSMOS_PAGE_TRANSITION_H
#define VAPP_LAUNCHER_COSMOS_PAGE_TRANSITION_H

#include "MMI_features.h"
#include "vfx_uc_include.h"


/*****************************************************************************
 * Include
 *****************************************************************************/


/*****************************************************************************
 * Define
 *****************************************************************************/
#define VAPP_HOME_DESKTOP_PAGE_BG_OPACITY 0.3

class VappLauncherCosmosDesktop;
class VappLauncherCosmosDesktopPage;
class VappLauncherCosmosPageTransition;


typedef struct 
{
    VfxS32 totalPage;
    VfxS32 pageWidth;
    VfxS32 pageHeight;
    VfxS32 pagePosX;
    VfxS32 pagePosY;
    VfxPoint desktopBoundsOrigin;
    VappLauncherCosmosDesktop *desktop;
    VappLauncherCosmosDesktopPage *page;
    VappLauncherCosmosPageTransition *transitionEffect;
} VappLauncherCosmosPageTransPara;


/*****************************************************************************
 * VappLauncherCosmosPageTransition Base Class
 *****************************************************************************/

/*
 * Macro to declare a page transition class
 */
#define VAPP_LAUNCHER_COSMOS_PAGE_TRANSITION_DECLARE_CLASS(_className)      \
                                                                            \
    VFX_DECLARE_CLASS(_className);                                          \
                                                                            \
    public:                                                                 \
        static VappLauncherCosmosPageTransition *createPageTransition(VfxObject *parentObj)


/*
 * Macro to implement a page transition class.
 */
#define VAPP_LAUNCHER_COSMOS_PAGE_TRANSITION_IMPLEMENT_CLASS(_className, _parentClassName)      \
                                                                                                \
    VFX_IMPLEMENT_CLASS(#_className, _className, _parentClassName);                             \
                                                                                                \
    VappLauncherCosmosPageTransition *_className::createPageTransition(VfxObject *parentObj)    \
    {                                                                                           \
        _className *VappLauncherCosmosPageTransition;                                           \
        VFX_OBJ_CREATE(VappLauncherCosmosPageTransition, _className, parentObj);                \
        return VappLauncherCosmosPageTransition;                                                \
    }

/*****************************************************************************
 * Class VappLauncherCosmosPageTransition
 *****************************************************************************/

class VappLauncherCosmosPageTransition : public VfxObject
{
    VFX_DECLARE_CLASS(VappLauncherCosmosPageTransition);
    
public:
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float t,
        vrt_s32 homeWidth,
        vrt_s32 homeHeight,
        vrt_s32 pagePosX, 
        vrt_s32 pagePosY,
        vrt_s32 boundsTranslateX,
        vrt_frame_visual_property_struct *target_frame
    ) const = 0;
};


/*****************************************************************************
 * Normal Transition Class
 *****************************************************************************/

class VappLauncherCosmosPageTransitionNormal : public VappLauncherCosmosPageTransition
{
    VAPP_LAUNCHER_COSMOS_PAGE_TRANSITION_DECLARE_CLASS(VappLauncherCosmosPageTransitionNormal);
    
public:
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float t,
        vrt_s32 homeWidth,
        vrt_s32 homeHeight,
        vrt_s32 pagePosX, 
        vrt_s32 pagePosY,
        vrt_s32 boundsTranslateX,
        vrt_frame_visual_property_struct *target_frame
    ) const;
};


/*****************************************************************************
 * Photo Wall Transition Class
 *****************************************************************************/

class VappLauncherCosmosPageTransitionPhotoWall : public VappLauncherCosmosPageTransition
{
    VAPP_LAUNCHER_COSMOS_PAGE_TRANSITION_DECLARE_CLASS(VappLauncherCosmosPageTransitionPhotoWall);
    
public:
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float t,
        vrt_s32 homeWidth,
        vrt_s32 homeHeight,
        vrt_s32 pagePosX, 
        vrt_s32 pagePosY,
        vrt_s32 boundsTranslateX,
        vrt_frame_visual_property_struct *target_frame
    ) const;

private:
    const static VfxS32 s_transitionPhotoWallType;
};


/*****************************************************************************
 * Cube Transition Class
 *****************************************************************************/

class VappLauncherCosmosPageTransitionCube : public VappLauncherCosmosPageTransition
{
    VAPP_LAUNCHER_COSMOS_PAGE_TRANSITION_DECLARE_CLASS(VappLauncherCosmosPageTransitionCube);
    
public:
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float t,
        vrt_s32 homeWidth,
        vrt_s32 homeHeight,
        vrt_s32 pagePosX, 
        vrt_s32 pagePosY,
        vrt_s32 boundsTranslateX,
        vrt_frame_visual_property_struct *target_frame
    ) const;
    
protected:
    virtual void onInit();

protected:
    VfxFloat m_angle;

};


/*****************************************************************************
 * Robot Transition Class
 *****************************************************************************/

class VappLauncherCosmosPageTransitionRobot : public VappLauncherCosmosPageTransition
{
    VAPP_LAUNCHER_COSMOS_PAGE_TRANSITION_DECLARE_CLASS(VappLauncherCosmosPageTransitionRobot);
    
public:
    virtual vrt_render_dirty_type_enum onTransition(
        vrt_float t,
        vrt_s32 homeWidth,
        vrt_s32 homeHeight,
        vrt_s32 pagePosX, 
        vrt_s32 pagePosY,
        vrt_s32 boundsTranslateX,
        vrt_frame_visual_property_struct *target_frame
    ) const;
    
protected:
    virtual void onInit();

protected:
    VfxFloat m_angle;

};

#endif /* VAPP_LAUNCHER_COSMOS_PAGE_TRANSITION_H */
