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
 *  vapp_wallpaper_wide.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen wide wallpaper class header file
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

#ifndef __VAPP_WALLPAPER_WIDE_H__
#define __VAPP_WALLPAPER_WIDE_H__

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
#include "vfx_frame.h"
#include "vfx_basic_type.h"

extern "C"
{
#include "CustThemesRes.h"
}


/*****************************************************************************
 * Home screen UI componet: wide wallpaper class
 *****************************************************************************/
class VappWallpaperWide : public VappWallpaper
{
    VFX_DECLARE_CLASS(VappWallpaperWide);

    VAPP_WALLPAPER_CREATE(VappWallpaperWide);

// Constructor / Destructor
public:
    // Default constructor
    VappWallpaperWide();

// Method: general operation for Homescreen
public:
    // optionally use a image id to override default behavior
    void setResId(VfxId resId);

    // optionally use a image path to override default behavior.
    void setPath(const VfxWString &path);

    // Create default wallpaper (for error handling)
    static VfxFrame* createDefaultWallpaperFrame(VfxFrame *parentFrame);
        
    // Adjust wallpaper by desktop cursor (0.0 ~ 1.0)
    static void adjustWallpaperByDesktopCursor(VfxFrame *imgBg, VfxFloat cursor);

// Method
protected:

    // create wallpaper
    virtual void onCreateView();

    // release wallpaper
    virtual void onReleaseView();

    // We still re-check image when serialize/restore
    virtual void onSerializeView();
    virtual void onRestoreView();

    // This function rotates the wallpaper and highlights the corresponding
    // navigation dot when the desktop changes its bounds.
    virtual void onDesktopCursorChanged(
        VfxFloat curPos,
        VfxFloat oldPos
    );

    virtual MMI_IMG_ID getThumbnail();

    virtual VfxBool checkResource();

    virtual mmi_ret handleEvent(mmi_event_struct *param);

// Variable
public:
    // Wallpaper frame
    VfxFrame *m_imgBg;
    VfxImageSrc m_customImageSrc;   // externally set image source

private:
    // This block declares the variable related to the wallpaper.

    // Wallpaper DRM right handle
    static VfxS32           s_drmConsumer;

    // The max. width of the wallpaper image for multi-desktop
    static const VfxS32     s_maxWallpaperWidth;

private:
    void loadWallpaperSetting(VfxBool &isSuccess);

    // Tune Wallpaper
    static void tuneWallpaper(VfxFrame *imgBg);

private:
    VfxBool getWallpaperDRMRight(   // returns VFX_TRUE if the file can be displayed
        VfxWChar *filename,         // [IN] path to check
        VfxBool &isProhibited,      // [OUT] VFX_TRUE if the file is prohibited due to DRM
        VfxBool consume = VFX_TRUE  // [IN] start consume DRM rights
        );

    static void stopDrmRight(VfxS32 result, VfxS32 id);

#if !defined(__COSMOS_MMI_PACKAGE__)
private:
    VfxU16 getWallpaperId();

    VfxWChar *getWallpaperFilenameOriginal();

    VfxWChar *getWallpaperFilenameCached();

    VfxBool isThemeWallpaper(
        VfxU16 id
    );

    UI_filled_area *getThemeBgFilledArea();

    void displayErrorPopupForBadFile(
        VfxS8 isProhibited
    );
#endif /* !defined(__COSMOS_MMI_PACKAGE__) */
};

#endif

