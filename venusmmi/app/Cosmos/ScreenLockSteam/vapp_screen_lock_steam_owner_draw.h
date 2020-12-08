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
 *  vtst_rt_3d_owner_draw.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for 3d owner draw
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_SCREEN_LOCK_STEAM_OWNER_DRAW_H__
#define __VAPP_SCREEN_LOCK_STEAM_OWNER_DRAW_H__

#ifdef __COSMOS_3D_SCREEN_LOCK__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_config.h"

#include <stdio.h>
#include "vtst_rt_main.h"
#include "vfx_frame.h"
#include "vfx_owner_draw.h"
#include "gles2\gl2.h"
#include "vfx_container.h"

#include "fs_type.h"
#include "fs_func.h"

#include "Stroke.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

#if defined(__MMI_MAINLCD_480X800__)
#define VAPP_STEAM_SCREEN_LOCK_WATER_DROP_BASE_HALF_WIDTH   6.0
#define VAPP_STEAM_SCREEN_LOCK_WATER_DROP_MAX_HALF_WIDTH    12.0
#define VAPP_STEAM_SCREEN_LOCK_WATER_DROP_BASE_HALF_HEIGHT  14.0
#define VAPP_STEAM_SCREEN_LOCK_WATER_DROP_MAX_HALF_HEIGHT   30.0
#define VAPP_STEAM_SCREEN_LOCK_STROKE_RADIUS                15.0
#elif defined(__MMI_MAINLCD_320X480__) 
#define VAPP_STEAM_SCREEN_LOCK_WATER_DROP_BASE_HALF_WIDTH   3.0
#define VAPP_STEAM_SCREEN_LOCK_WATER_DROP_MAX_HALF_WIDTH    6.0
#define VAPP_STEAM_SCREEN_LOCK_WATER_DROP_BASE_HALF_HEIGHT  7.0
#define VAPP_STEAM_SCREEN_LOCK_WATER_DROP_MAX_HALF_HEIGHT   15.0
#define VAPP_STEAM_SCREEN_LOCK_STROKE_RADIUS                10.0
#elif defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__)
#define VAPP_STEAM_SCREEN_LOCK_WATER_DROP_BASE_HALF_WIDTH   3.0
#define VAPP_STEAM_SCREEN_LOCK_WATER_DROP_MAX_HALF_WIDTH    6.0
#define VAPP_STEAM_SCREEN_LOCK_WATER_DROP_BASE_HALF_HEIGHT  7.0
#define VAPP_STEAM_SCREEN_LOCK_WATER_DROP_MAX_HALF_HEIGHT   15.0
#define VAPP_STEAM_SCREEN_LOCK_STROKE_RADIUS                10.0
#else
#define VAPP_STEAM_SCREEN_LOCK_WATER_DROP_BASE_HALF_WIDTH   3.0
#define VAPP_STEAM_SCREEN_LOCK_WATER_DROP_MAX_HALF_WIDTH    6.0
#define VAPP_STEAM_SCREEN_LOCK_WATER_DROP_BASE_HALF_HEIGHT  7.0
#define VAPP_STEAM_SCREEN_LOCK_WATER_DROP_MAX_HALF_HEIGHT   15.0
#define VAPP_STEAM_SCREEN_LOCK_STROKE_RADIUS                10.0
#endif


#define VAPP_STEAM_SCREEN_LOCK_MAX_WATER_DROP    5
#define VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO    2.0

typedef struct
{
    // Handle to a program object
    GLuint programObject;
    GLint uFrameAnchorLoc; 
    GLint uViewPortSizeLoc;
    GLint uTextureLoc;
    GLint uTextureLevelLoc;
    GLint uBackgroundLoc;
    GLint uConstAlphaLoc;   
    GLint uNeedFogUpLoc;
    GLint aPositionLoc;
    GLint aTexCoordLoc;
    GLuint textureId;
    GLint textureLevelId;
    
    GLuint frameBuffer;
    GLuint textureBuffer;
} userdata_stroke;

typedef struct
{
   // Handle to a program object
   GLuint programObject;
   GLint uFrameAnchorLoc; 
   GLint uViewPortSizeLoc;
   GLint uTextureLoc;
   GLint uTextureStrokeLoc;
   GLint aPositionLoc;
   GLint aTexCoordLoc;
   GLuint textureId;
   
} userdata_waterglass;

typedef struct
{
   // Handle to a program object
   GLuint programObject;
   GLint uFrameAnchorLoc;
   GLint uViewPortSizeLoc;
   GLint uTextureLoc;
   GLint aPositionLoc;
   GLint aTexCoordLoc;
   GLuint textureId;

   GLuint frameBuffer;
   GLuint textureBuffer;
   
} userdata_droplet;


/***************************************************************************** 
 * Class
 *****************************************************************************/

class VappSteamScreenLockDroplet
{
// Constructor
public:
    VappSteamScreenLockDroplet();
    ~VappSteamScreenLockDroplet();

// Variable
public:
    VfxFPoint m_pos;
    VfxFloat m_weight;
    VfxFloat m_acceleration;
    VfxFloat m_gravityAcceleration;
    VfxFloat m_distanceToWeightRatio;
};


class VappSteamScreenLockOwenerDraw : public VfxOwnerDraw
{
// Constructor
public:
    VappSteamScreenLockOwenerDraw(VfxSize size);

// Method
public:
    void addWaterDrop(VfxPoint pos, VfxS32 weight = 100);
    void setGravity(VfxFloat g_x, VfxFloat g_y, VfxFloat g_z);
    void reset();
    void addStrokeLine(VfxFloat x0, VfxFloat y0, VfxFloat x1, VfxFloat y1);
    void releaseResource();
    
// Override
protected:
    virtual void onInit();
    
private:
    virtual void onInitResource();
    virtual void onDeinitResource();
    virtual void onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect);
    virtual vrt_bool isUsingGLAPI() const { return VFX_TRUE; }
    VfxSize getScreenSize();
    void clearBuffer(vrt_color_type color);
    
// Variable
public:
    Stroke m_stroke;
    Stroke m_strokeWaterDrop;
    VfxFloat m_gravity[3]; //gravity direction
    VfxBool m_redrawWaterDrop;

    // it represents the number times of redraw fog
    // it start to fog up when this value > 0
    VfxS32 m_fogUpTimes;
    VfxList <VappSteamScreenLockDroplet> m_dropWaterList;

private:
    VfxBool m_isInit;
    VfxSize m_size;

    VfxFloat m_acceleration; // gravity acceleration
    VfxFloat m_frictionFactor;
    VfxFloat m_defaultNormalForce;

    userdata_stroke m_dataStroke;
    userdata_waterglass m_dataGlass;
    userdata_droplet m_dataDroplet;
};
#endif /*#ifdef __COSMOS_3D_SCREEN_LOCK__*/
#endif /*  __VAPP_SCREEN_LOCK_STEAM_OWNER_DRAW_H__ */
