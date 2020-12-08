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
 *  vapp_wallpaper_mav.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen frame video wallpaper class header file
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if 1
// #ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MAV__

#ifndef __VAPP_WALLPAPER_MAV_H__
#define __VAPP_WALLPAPER_MAV_H__

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
#include "vapp_mav_motion_translator.h"
/* RHR end */

// decoder related interface
extern "C"
{
#include "vapp_wallpaper_video_decoder.h"
#include "FileMgrSrvGProt.h"
#include "gdi_datatype.h"
#include "gdi_const.h"
}

/*****************************************************************************
 * Macros
 *****************************************************************************/
#if defined(MOTION_SENSOR_SUPPORT)
#define __VAPP_WALLPAPER_MAV_MOTION_SENSOR_SUPPORT__
#endif

#define STATE_SCALE (100)

class VappMAVDraw;
class VappMavMotionTranslator;
/*****************************************************************************
 * Home screen UI componet: frame video wallpaper class
 *****************************************************************************/
class VappWallpaperMAV : public VappWallpaper
{
    VFX_DECLARE_CLASS(VappWallpaperMAV);

    VAPP_WALLPAPER_CREATE(VappWallpaperMAV);

// Constructor / Destructor
public:
    // Default constructor
    VappWallpaperMAV();

// Configuration before createView
public:
    void setSourceFile(WCHAR *srcFile);

// Override
public:
    // decode file to retrieve thumbnail
    virtual VfxBool getThumbnailImage(VfxImageBuffer &output);

    // use file name as wallpaper name
    virtual void getName(VfxWString &wallpaperName);
    
    // check if the already exists
    virtual VfxBool checkResource();

    virtual mmi_ret handleEvent(mmi_event_struct *param);

protected:
    // create wallpaper
    virtual void onCreateView();

    // release wallpaper
    virtual void onReleaseView();

    virtual void onSerializeView();
    virtual void onRestoreView();

    // Is allow suspend wallpaper when desktop swipe
    virtual VfxBool onAllowSuspendOnSwipe();

    // Is allow suspend wallpaper when receive pen down
    virtual VfxBool onAllowSuspendOnPenDown();

    // callback for suspend and resume wallpaper
    virtual void onSuspend();
    virtual void onResume();
    virtual void onDesktopCursorChanged(
        VfxFloat curPos,     
        VfxFloat oldPos);

    void checkPlay(void);

//Override
protected:
    virtual VfxBool onPenInput(VfxPenEvent & event);
    VfxBool initASMScreenGroup();
    void deinitASMScreenGroup();
    static mmi_ret onScreenGroupEvent(mmi_event_struct *evt);

    VfxBool trySetupMotionSensor();
    void handleSensorEvent(VfxFloat tilt);
    void teardownMotionSensor();

public:
    static void* mem_alloc(mmi_id asmGroup, unsigned int items, unsigned int size);
    static void mem_free(mmi_id asmGroup, void *address);

private:
    VappMAVDraw   *m_draw;
    VfxFloatTimeline     *m_timeline;

    WCHAR                 m_sourceFileName[FS_MAX_PATH + 1];  // the wallpaper file path
    VfxBool               m_isFileValid;

    VfxU16                m_fallbackImgId;
    VfxFrame             *m_fallbackWallpaper;

    MMI_ID                m_asmGroupId;

#ifdef __VAPP_WALLPAPER_MAV_MOTION_SENSOR_SUPPORT__
private:
    VappMavMotionTranslator *m_sensor;
#endif
};

/*****************************************************************************
 * Class VappMAVDraw
 *****************************************************************************/

class VappMAVDraw : public VfxOwnerDraw
{
// Constructor
public:
    // Default constructor
    VappMAVDraw(mmi_id asmGroupId);

// Override
public:
    static vrt_render_dirty_type_enum VappMAVDraw::onUpdate(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size);

    virtual void onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect);

    void setFileSrc(WCHAR* src);
    void setFallbackImgId(VfxResId imgId);
    VfxBool destoryFileInfo(void);
    VfxBool createFileInfo(void);

protected:
    virtual void onInit();
    virtual void onDeinit();
    static void VappMAVDraw::onVRTError(void *arg);
    void restoreWallpaperSetting(VfxU32 errCode);

// Method
private:
    GDI_RESULT drawFrame(VfxU32 frameIdx);


// Variable
public:
    mmi_id                  m_asmGroupId;         // asm group id used for memory allocation
    VfxBool                 m_isSuspend;
    VfxS32                  m_totalPage;          // total page of wallpaper
    VfxResId                m_fallbackImgId;      // Resource id of fallback image
    VfxU8                  *m_contentBuffer;                // the decoded data buffer for show the wallpaper
                                                            // for cosmos project, it will be allocated from anomynous ASM
                                                            // for pluto project, it will be allocated from  MED memory

    WCHAR                   m_sourceFileName[FS_MAX_PATH + 1];          // the wallpaper file path

    VfxU32                  m_framePtr;                     // decoder current decoding frame pointer

    VfxU32                  m_frameCnt;                     // the total frame counts in the file

    VfxS32                  m_bpp;                          // the number of byte per pixel

    vrt_color_type_enum     m_cf;                           // VRT color format for m_contentBuffer    

    VfxU32                  m_FrameWidth;                   // the frame width

    VfxU32                  m_FrameHeight;                  // the frame height

    VfxBool                 m_isErrorHappended;
    VfxU32                  m_errorCode;

};
#endif /* __VAPP_WALLPAPER_MAV_H__ */
#endif /* __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MAV__ */

