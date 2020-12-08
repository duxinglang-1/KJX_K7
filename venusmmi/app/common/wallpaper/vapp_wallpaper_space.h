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
 *  vapp_wallpaper_space.h
 *
 * Project:
 * --------
 *  Live Wallpaper
 *
 * Description:
 * ------------
 *  "Star" live wallpaper implementation 
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

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPACE__

#ifndef __VAPP_WALLPAPER_SPACE_H__
#define __VAPP_WALLPAPER_SPACE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_wallpaper.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vapp_wallpaper_cfg.h"
#include "vfx_sys_memory.h"
#include "vfx_animation.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"
#include "vfx_control.h"
#include "vfx_input_event.h"
#include "vfx_draw_context.h"
#include "gdi_lcd_config.h"
#include "lcd_sw_inc.h"
#include "vfx_frame_filter.h"
#include "vrt_datatype.h"
#include "vfx_image_src.h"


/***************************************************************************** 
 * Typedefs
 *****************************************************************************/
#ifdef __VENUS_3D_UI_ENGINE__
class VappHsSpaceOwnerDrawGL;
typedef VappHsSpaceOwnerDrawGL VappHsSpaceDrawer;
#else
class VappHsSpaceFilter;
typedef VappHsSpaceFilter VappHsSpaceDrawer;
#endif

/*
 * Class of Space walllpaper
 */
class VappWallpaperSpace : public VappWallpaper
{
    VFX_DECLARE_CLASS(VappWallpaperSpace);
	VAPP_WALLPAPER_CREATE(VappWallpaperSpace);

// Implementation
private:
    VappHsSpaceDrawer *m_wallpaperFilter;
    VfxBaseTimeline *m_animTimeline;
    VfxFloatTimeline *m_centerMoveTimeline;
    VfxFrame *m_bgFrame;

// Constructor / Destructor
public:
    // Default constructor
    VappWallpaperSpace();

// Override method
public:
    // This function used to get image id of wallpaper thumbnail
    virtual MMI_IMG_ID getThumbnail();
    virtual void getName(VfxWString &wallpaperName);

protected:
	// Init wallpaper
	virtual void onCreateView();

	// Deinit
	virtual void onReleaseView(); 
    	
    virtual VfxBool onAllowSuspendOnSwipe();

    // Wallpaper can motion when the widget dragged
	virtual void onWidgetDropped(
		VfxPoint pos,				// Wallpaper position
		VfxControl *targetWidget	// Target widget pointer
	);

    // TODO: widget interaction demo
    virtual VfxBool onPenInput(VfxPenEvent &e);

    virtual void onSuspend();
    virtual void onResume();

    // This function rotates the wallpaper and highlights the corresponding
    // navigation dot when the desktop changes its bounds.	
    virtual void onDesktopCursorChanged(VfxFloat curPos, VfxFloat oldPos);

    // override onDraw for resource preparation
    virtual void onDraw(VfxDrawContext &dc);
private:
    float screenOffsetToStarOffset(int screenOffset);
}; 


/*
 * SpaceStar represents a "line" of star in the wallpaper.
 */
class SpaceStar
{
private:
    static const int H = GDI_LCD_WIDTH / 2;
    static const int V = GDI_LCD_HEIGHT / 2;
    static const int MAX_DEPTH = 100;
    static const int NEAR_PLANE = 64;
    static const int PAST_TRAIL_DEPTH = 8;
    static const VfxMsec timeStep = 33;

private:
	VfxS32 x;
    VfxS32 y;
    VfxS32 m_z;
    VfxMsec m_timeResidual;
    VfxBool m_bVisible;

private:
    void calculateXY(int z, int &xOut, int &yOut, int vanishPointOffsetX) const;

public:
    SpaceStar();
    void setVisible(VfxBool bVisible);
    void init(VfxBool bStartup = VFX_FALSE);
    void update(VfxMsec timePassed, VfxS32 viewOffsetX);    
    void drawToActiveGDILayer(VfxS32 viewOffsetX) const;
    void getCanonicalLine(VfxS32 viewOffsetX, VfxFloat &srcX, VfxFloat &srcY, VfxFloat &dstX, VfxFloat &dstY);
};

#endif // #ifndef __VAPP_WALLPAPER_SPACE_H__
#endif // #ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPACE__


