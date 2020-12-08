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
 *  vapp_wallpaper_wave.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen wave wallpaper class header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WAVE__

#ifndef __VAPP_WALLPAPER_WAVE_H__
#define __VAPP_WALLPAPER_WAVE_H__

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vapp_wallpaper.h"

/* RHR start */
#include "vfx_object.h"   
#include "vfx_class_info.h"
#include "vfx_datatype.h"   
#include "vfx_cpp_base.h"
#include "vapp_wallpaper_cfg.h"
#include "vfx_sys_memory.h"
#include "vfx_frame.h"    
#include "vfx_basic_type.h"
#include "vfx_input_event.h"
#include "vfx_primitive_frame.h"  
#include "vfx_animation.h"
#include "vfx_owner_draw.h"   
#include "vrt_datatype.h"
#include "vfx_image_src.h"
/* RHR end */

#ifdef __cplusplus
extern "C"
{
#endif

#include "gdi_primitive.h"

#ifdef __cplusplus
}
#endif


class VappWaveDraw;
/*****************************************************************************
 * Home screen UI componet: wave wallpaper class
 *****************************************************************************/
class VappWallpaperWave : public VappWallpaper
{
    VFX_DECLARE_CLASS(VappWallpaperWave);

    VAPP_WALLPAPER_CREATE(VappWallpaperWave);

// Constructor / Destructor
public:
    // Default constructor
    VappWallpaperWave();

// Override
public:
    // This function used to get image id of wallpaper thumbnail
    virtual MMI_IMG_ID getThumbnail();
    virtual void getName(VfxWString &wallpaperName);

protected:
    // create wallpaper
    virtual void onCreateView();

    // release wallpaper
    virtual void onReleaseView();

    // callback for suspend and resume wallpaper
    virtual void onSuspend();
    virtual void onResume();
    virtual void onDesktopCursorChanged(VfxFloat curPos, VfxFloat oldPos);

private:
    void rotateResID();

//Override
protected:
    virtual VfxBool onPenInput(VfxPenEvent & event);

//Variable
public:
    // wallpaper background frame
    VfxImageFrame *m_imgBg;

    // Wallpaper foreground frame
    VfxImageFrame *m_imgFg;

private:
    VappWaveDraw *m_draw;

    VfxFloatTimeline *m_timeline;

};


/*****************************************************************************
 * Class VappWaveDraw
 *****************************************************************************/

class VappWaveDraw : public VfxOwnerDraw
{
// Constructor
public:
    // Default constructor
    VappWaveDraw();

// Override
public:
    static vrt_render_dirty_type_enum VappWaveDraw::onUpdate(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size);

    virtual void onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect);

protected:
    virtual void onInit();

// Method
private:
    void drawReflection(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect);
    gdi_img_buf_color_format_enum transformVRTColorFormatToGDIColorFormat(VfxColorTypeEnum vrtColorFormat);

// Variable
public:
	VfxBool m_isSuspend;

private:
    VfxS32 m_debug;
    VfxFloat m_level;
};
#endif /* __VAPP_WALLPAPER_WAVE_H__ */
#endif /* __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WAVE__ */

