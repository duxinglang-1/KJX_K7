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
 *  vapp_wallpaper_wide.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen wide wallpaper class
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

#include "vapp_wallpaper_wide.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vapp_wallpaper.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_primitive_frame.h"
#include "vfx_rect_frame.h"
#include "vfx_basic_type.h"
#include "vfx_string.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "vfx_frame.h"
#include "vfx_auto_animate.h"
#include "lcd_sw_inc.h"
#include "vapp_wallpaper_setting_provider.h"

#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_wallpaper_setting_method_gprot.h"
#endif

extern "C"
{
#include "MMI_include.h"
#include "GlobalResDef.h"
#include "drm_errcode.h"
#include "drm_def.h"
#include "DRM_gprot.h"
#include "WPSSProtos.h"
#include "SettingGprots.h"

extern S8 *idle_screen_wallpaper_name;
extern S8 *idle_screen_wallpaper_name_original;
extern MMI_ID_TYPE idle_screen_wallpaper_ID;
extern MMI_theme *current_MMI_theme;
}


/*****************************************************************************
 * Home screen UI componet: wide wallpaper
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("Wide Wallpaper", VappWallpaperWide, VappWallpaper);

VfxS32 VappWallpaperWide::s_drmConsumer = -1;

/*
 * Cosmos:
 *  the max wallpaper width is the LCD height.
 * 
 * Cosmos Slim:
 *  the max wallpaper width is the LCD height;
 *  but only display center region of the image (__VAPP_WALLPAPER_WIDE_SINGLE_PAGE__)
 *
 * Pluto:
 *  1) Lite project: the max wallpaper width is the LCD width.
 *  2) general project: the max wallpaper width is the 1.5 times LCD width.
 */
#if defined(__COSMOS_MMI_PACKAGE__) || (defined(__MMI_VUI_LAUNCHER__) && !defined(__MMI_VUI_LAUNCHER_KEY__))
const VfxS32 VappWallpaperWide::s_maxWallpaperWidth = LCD_HEIGHT;
#else /* defined(__PLUTO_MMI_PACKAGE__) */
#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) || defined(__MMI_VUI_SHELL_OP01_HOMESCREEN__) || defined(__MMI_VUI_LAUNCHER_KEY__)
const VfxS32 VappWallpaperWide::s_maxWallpaperWidth = LCD_WIDTH;
#else
const VfxS32 VappWallpaperWide::s_maxWallpaperWidth = (VfxS32)(LCD_WIDTH * 1.5f);
#endif 
#endif /* defined(__PLUTO_MMI_PACKAGE__) */
#if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
#define __VAPP_WALLPAPER_WIDE_SINGLE_PAGE__
#endif


VappWallpaperWide::VappWallpaperWide()  :
    m_imgBg(NULL)
{
}

void VappWallpaperWide::setResId(VfxId resId)
{
    m_customImageSrc.setResId(resId);
}

void VappWallpaperWide::setPath(const VfxWString &path)
{
    m_customImageSrc.setPath(path);
}

void VappWallpaperWide::onSerializeView()
{
    registerEvents(VFX_FALSE);
}

void VappWallpaperWide::onRestoreView()
{
    registerEvents(VFX_TRUE);
    // Both Pluto/COSMOS, requires DRM check
    if(VFX_IMAGE_SRC_TYPE_PATH == m_customImageSrc.getType())
    {
        VfxBool isProhibited = VFX_FALSE;
        VfxBool fileReady = getWallpaperDRMRight(
                                (VfxWChar*)m_customImageSrc.getPath().getBuf(), 
                                isProhibited);
        if(!fileReady)
        {
            // Reset default wallpaper directly
            restoreWallpaperSetting(isProhibited ? STR_GLOBAL_DRM_PROHIBITED : 0);
        }
    }
}

VfxBool VappWallpaperWide::checkResource()
{
    // Both Pluto/COSMOS, requires DRM check
    if(VFX_IMAGE_SRC_TYPE_PATH == m_customImageSrc.getType())
    {
        VfxBool isProhibited = VFX_FALSE;
        VfxBool fileReady = getWallpaperDRMRight(
                                (VfxWChar*)m_customImageSrc.getPath().getBuf(), 
                                isProhibited,
                                VFX_FALSE       // don't conusme since we're just checking
                                );
        if(!fileReady)
        {
            return VFX_FALSE;
        }
    }

    return VFX_TRUE;
}

void VappWallpaperWide::onCreateView()
{
    setBgColor(VFX_COLOR_BLACK);
    setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
    #if defined(__VAPP_WALLPAPER_WIDE_SINGLE_PAGE__)
    setCacheMode(VFX_CACHE_MODE_FREEZE);
    #else
    setCacheMode(VFX_CACHE_MODE_PREVENT);
    #endif
    
    // listen to device removal
    registerEvents(VFX_TRUE);

    VfxBool isSuccess = VFX_FALSE;

    // Show static wallpaper
    if(!m_customImageSrc.isNull())
    {
        do
        {
            if(VFX_IMAGE_SRC_TYPE_PATH == m_customImageSrc.getType())
            {
                // Both Pluto/COSMOS, requires DRM check
                VfxBool isProhibited = VFX_FALSE;
                VfxBool fileReady = getWallpaperDRMRight(
                                        (VfxWChar*)m_customImageSrc.getPath().getBuf(), 
                                        isProhibited);
                if(!fileReady)
                {
                    // Reset default wallpaper directly
                    restoreWallpaperSetting(isProhibited ? STR_GLOBAL_DRM_PROHIBITED : 0);
                    isSuccess = VFX_FALSE;
                    break;
                }
            }
            
            VfxImageFrame *imgBg;
            VFX_OBJ_CREATE(imgBg, VfxImageFrame, this);
            imgBg->setImgContent(m_customImageSrc);
            m_imgBg = imgBg; // save
            isSuccess = VFX_TRUE;
        }while(0);
        
    }
    else
    {
        loadWallpaperSetting(isSuccess);
    }
    
    // Finally:
    // If the wallpaper is present, set the property and tune the size and
    // position.
    //
    // The default background color should be the same as the background color
    // of App category such that if the wallpaper is translucent, the colors are
    // the same.

    if (isSuccess && m_imgBg)
    {
        #if defined(__VAPP_WALLPAPER_WIDE_SINGLE_PAGE__)
        #else
        m_imgBg->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
        m_imgBg->setBgColor(VFX_COLOR_BLACK);
        m_imgBg->setCacheMode(VFX_CACHE_MODE_FORCE);
        m_imgBg->setAutoAnimate(VFX_TRUE);
        #endif
        tuneWallpaper(m_imgBg);
    }
}


void VappWallpaperWide::loadWallpaperSetting(VfxBool &isSuccess)
{
#ifndef __COSMOS_MMI_PACKAGE__
    // Priority 1:
    // Take the wallpaper from the image resource or from the theme.
    VfxU16 resId = getWallpaperId();

    if (!isSuccess && resId != 0)
    {
        if (!isThemeWallpaper(resId))
        {
            VfxImageFrame *imgBg;
            VFX_OBJ_CREATE(imgBg, VfxImageFrame, this);
            imgBg->setResId(resId);

            m_imgBg = imgBg; // save
        }
        else
        {
            // from theme
            VfxRectFrame *imgBg;

            VFX_OBJ_CREATE(imgBg, VfxRectFrame, this);
            imgBg->setBounds(VfxRect(VfxPoint(0, 0), getScreenSize()));
            imgBg->setFilledArea(getThemeBgFilledArea());

            m_imgBg = imgBg; // save
        }
        isSuccess = VFX_TRUE;
    }


    // Priority 2:
    // From image file in ME. We should use the original wallpaper file to
    // check whether the file is present and whether the DRM is granted. Use
    // the cached file for display alternatively.
    VfxWChar *filename = getWallpaperFilenameOriginal();
    VfxBool isProhibited = VFX_FALSE;

    if (!isSuccess && filename)
    {
        VfxBool is_granted = getWallpaperDRMRight(filename, isProhibited);

        if (is_granted)
        {
            VfxImageFrame *imgBg;

            VFX_OBJ_CREATE(imgBg, VfxImageFrame, this);

            filename = getWallpaperFilenameCached();

            VFX_OBJ_CREATE(imgBg, VfxImageFrame, this);
            imgBg->setSrc(VFX_WSTR_MEM(filename));

            m_imgBg = imgBg; // save

            isSuccess = VFX_TRUE;
        }
    }

    // Priority 3:
    // Error. Callback to phone setup. It will display a popup and reset the
    // wallpaper to the default one. After the popup disappears, the idle screen
    // will be redrawed.

    if (!isSuccess)
    {
        displayErrorPopupForBadFile(isProhibited);
    }
#endif /* __COSMOS_MMI_PACKAGE__ */
}

void VappWallpaperWide::onReleaseView()
{
#if !defined(__COSMOS_MMI_PACKAGE__) && defined(__DRM_SUPPORT__)
    if (s_drmConsumer >= DRM_RESULT_OK)
    {
        DRM_stop_consume(s_drmConsumer);
        s_drmConsumer = -1; // reset
    }
#endif /* !defined(__COSMOS_MMI_PACKAGE__) && defined(__DRM_SUPPORT__) */

    if(m_imgBg)
    {
        VFX_OBJ_CLOSE(m_imgBg);
    }
    registerEvents(VFX_FALSE);
}

VfxFrame* VappWallpaperWide::createDefaultWallpaperFrame(VfxFrame *parentFrame)
{
    VappWallpaperSettingProvider *setting = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingProvider);
    VappWallpaperId fallbackWallpaperId;
    setting->getFallbackWallpaperId(fallbackWallpaperId, VFX_TRUE);
    if(VAPP_WALLPAPER_FACTORY_IMAGE != fallbackWallpaperId.getSource())
    {
        // default fallback wallpaper must be image wallpaper
        VFX_ASSERT(VFX_FALSE);
        return NULL;
    }
    const VfxResId imgId = (VfxResId)fallbackWallpaperId.getIntType();

    // Show static wallpaper
    VfxImageFrame *imgBg = NULL;
    VFX_OBJ_CREATE(imgBg, VfxImageFrame, parentFrame);
    imgBg->setResId(imgId);

    tuneWallpaper(imgBg);
    return imgBg;
}

void VappWallpaperWide::tuneWallpaper(VfxFrame *imgBg)
{
    VfxSize screenSize, imgSize;

    screenSize = getScreenSize();
    imgSize = imgBg->getBounds().size;

    if ((screenSize.width >= imgSize.width) &&
        (screenSize.height >= imgSize.height))
    {
        // Background image is smaller than the screen size. Centralize the
        // image in both vertical and horizontal direction.
        VfxPoint p;

        p.x = (screenSize.width - imgSize.width) >> 1;
        p.y = (screenSize.height - imgSize.height) >> 1;

        imgBg->setPos(p);
    }
    else
    {
        // Background is larger than the screen size.

        VfxFloat sx = 1.0, sy = 1.0, sMin;

        // Find the scaling ratio in the y-direction.
        if (imgSize.height > screenSize.height)
        {
            sy = (VfxFloat)screenSize.height / imgSize.height;
        }

        // Find the scaling ratio in the x-direction.
        if (imgSize.width > s_maxWallpaperWidth)
        {
            sx = (VfxFloat)s_maxWallpaperWidth / imgSize.width;
        }

        sMin = (sx < sy? sx: sy);

        VfxRect rect = imgBg->getBounds();

        // Calculate the resized width (plus 0.5 to round to the nearest
        // number).
        rect.size.width = (VfxS32)(sMin * rect.size.width + 0.5);

        if (rect.size.width <= 0)
        {
            rect.size.width = 1;
        }

        if (rect.size.width > s_maxWallpaperWidth)
        {
            rect.size.width = s_maxWallpaperWidth;
        }

        // Calculate the resized height (plus 0.5 to round to the nearest
        // number).
        rect.size.height = (VfxS32)(sMin * rect.size.height + 0.5);

        if (rect.size.height <= 0)
        {
            rect.size.height = 1;
        }

        if (rect.size.height > screenSize.height)
        {
            rect.size.height = screenSize.height;
        }

        // Set up the content placement & resize property.
        imgBg->setBounds(rect);
        imgBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

        imgSize = rect.size; // re-get the new image bounds

        // Vertical: alway central-alignment.
        //
        // Horizontal:
        //      1) small than screen width: left-alignment
        //      2) otherwise, central-alignment

        VfxPoint p;

        p.y = (screenSize.height - imgSize.height) >> 1;

        if (imgSize.width > screenSize.width)
        {
            p.x = 0;
        }
        else
        {
            p.x = (screenSize.width - imgSize.width) >> 1;
        }

        imgBg->setPos(p);
    }
}

void VappWallpaperWide::onDesktopCursorChanged(
        VfxFloat curPos,
        VfxFloat oldPos)
{
    if (getTotalPage() <= 1 || NULL == m_imgBg)
    {
        return;
    }
    adjustWallpaperByDesktopCursor(m_imgBg, curPos);
}

void VappWallpaperWide::adjustWallpaperByDesktopCursor(VfxFrame *imgBg, VfxFloat cursor)
{
    #if defined(__VAPP_WALLPAPER_WIDE_SINGLE_PAGE__)
    return;
    #else
    if(NULL == imgBg)
    {
        return;
    }
    
    const VfxSize size = imgBg->getBounds().size;
    VfxPoint pos = imgBg->getPos();
    const VfxSize screenSize = getScreenSize();
    
    // Change the wallpaper position:
    //
    //               page width   page width   page width
    //   desktop   |------------|------------|------------|
    //
    //                 wallpaper width
    //   wallpaper |----------------------|
    //
    //                          |<---------- A ---------->|
    //
    //                          |<-- B -->|
    //
    // If the desktop moves X, the wallpaper should move M = X * (B / A).
    const VfxS32 b = size.width - screenSize.width;
    if(b > 0)
    {
        // calculate the bounds of the wallpaper
        VfxS32 m = b * cursor;

        // Check x value for fail-safe
        m = (m < 0) ? (0) : (m);
        m = (m > b) ? (b) : (m);

        // Change wallpaper position
        pos.x = -m;

        VfxAutoAnimate::begin();
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);

        imgBg->setPos(pos);

        VfxAutoAnimate::commit();
    }
    #endif  /*__VAPP_WALLPAPER_WIDE_SINGLE_PAGE__*/
}

mmi_ret VappWallpaperWide::handleEvent(mmi_event_struct *param)
{
    if(NULL == param)
    {
        return MMI_RET_OK;
    }

    switch(param->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
            if(!checkResource())
            {
                restoreWallpaperSetting(0);
            }
            break;
    }
    return MMI_RET_OK;
}

VfxBool VappWallpaperWide::getWallpaperDRMRight(
    VfxWChar *filename,
    VfxBool &isProhibited,
    VfxBool consume)
{
    FS_HANDLE handle;
    VfxBool ret = VFX_TRUE; // default

    isProhibited = VFX_FALSE;

    handle = DRM_open_file(filename, FS_READ_ONLY, DRM_PERMISSION_DISPLAY);

    if (handle >= FS_NO_ERROR)
    {
    #ifdef __DRM_SUPPORT__
        // Check DRM right is granted or not.
        if (DRM_validate_forward_rule(handle, DRM_PERMISSION_DISPLAY))
        {
            if(consume)
            {
                s_drmConsumer = DRM_consume_rights(
                                handle,
                                DRM_PERMISSION_DISPLAY,
                                stopDrmRight);
            }
            ret = VFX_TRUE;
        }
        else
        {
            isProhibited = VFX_TRUE; // failed because of DRM prohibited
            ret = VFX_FALSE;
        }
    #endif /* __DRM_SUPPORT__ */

        DRM_close_file(handle);
    }
    else
    {
        ret = VFX_FALSE;
    }

    return ret;
}

void VappWallpaperWide::stopDrmRight(VfxS32 result, VfxS32 id)
{
    VFX_UNUSED(result);
    VFX_UNUSED(id);

#ifdef __DRM_SUPPORT__

    // This function is the callback when DRM grants the right, but some error
    // happens during the usage of the content. For example, the error might be
    // the DRM right expires.
    if (s_drmConsumer >= DRM_RESULT_OK)
    {
        DRM_stop_consume(s_drmConsumer);
        s_drmConsumer = -1; // reset
    }
#endif /* __DRM_SUPPORT__ */
}

static MMI_IMG_ID get_static_wallpaper_thumb_with_id(VfxU32 imageId)
{
#ifdef __COSMOS_MMI_PACKAGE__
    if (IMG_ID_WP_THEME_START<=imageId && (imageId<IMG_ID_WP_THEME_START+MMI_WP_THEME_NUM))
    {
        return IMG_ID_WP_THEME_THUMB_START + (imageId - IMG_ID_WP_THEME_START);
    }
    else
    {
        return (IMG_ID_PHNSET_WP_THUMB_START + imageId - IMG_ID_PHNSET_WP_START);
    }
#else
    return 0;
#endif
}

MMI_IMG_ID VappWallpaperWide::getThumbnail()
{
    if(VFX_IMAGE_SRC_TYPE_RES_ID == m_customImageSrc.getType())
    {
        return get_static_wallpaper_thumb_with_id(m_customImageSrc.getResId());
    }
    return 0;        
}

#if !defined(__COSMOS_MMI_PACKAGE__)

VfxU16 VappWallpaperWide::getWallpaperId(void)
{
    return (VfxU16)idle_screen_wallpaper_ID;
}


VfxWChar* VappWallpaperWide::getWallpaperFilenameOriginal(void)
{
    return (VfxWChar*)idle_screen_wallpaper_name_original;
}


VfxWChar* VappWallpaperWide::getWallpaperFilenameCached(void)
{
    return (VfxWChar*)idle_screen_wallpaper_name;
}


VfxBool VappWallpaperWide::isThemeWallpaper(VfxU16 id)
{
    return mmi_phnset_check_themeid_wallpaper(id)? VFX_TRUE: VFX_FALSE;
}


UI_filled_area *VappWallpaperWide::getThemeBgFilledArea(void)
{
    if (current_MMI_theme && current_MMI_theme->idle_bkg_filler)
    {
        return current_MMI_theme->idle_bkg_filler;
    }
    else
    {
        return NULL;
    }
}


void VappWallpaperWide::displayErrorPopupForBadFile(VfxS8 isProhibited)
{
    if (isProhibited)
    {
        restoreWallpaperSetting(STR_GLOBAL_DRM_PROHIBITED);
    }
    else
    {
        restoreWallpaperSetting(0);
    }
}
#endif /* !defined(__COSMOS_MMI_PACKAGE__) */

