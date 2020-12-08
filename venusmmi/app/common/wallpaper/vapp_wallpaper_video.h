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
 *  vapp_wallpaper_video.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen video wallpaper class header file
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
#ifndef __VAPP_WALLPAPER_VIDEO_H__
#define __VAPP_WALLPAPER_VIDEO_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__

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
#include "vfx_text_frame.h"
/* RHR end */

extern "C"
{
#include "mdi_datatype.h"
}

/*****************************************************************************
 * Home screen UI componet: video wallpaper class
 *****************************************************************************/
class VappVideoPlayerComponent;
class VappWallpaperVideo : public VappWallpaper
{
    VFX_DECLARE_CLASS(VappWallpaperVideo);

    VAPP_WALLPAPER_CREATE(VappWallpaperVideo);

// Constructor / Destructor
public:
    // Default constructor
    VappWallpaperVideo();

    virtual void onInit();
    virtual void onDeinit();

    // for screen enter/exit event
    virtual void onObjectNotify(VfxId id, void *userData);

// Method: general operation for Homescreen
public:
    void setResId(VfxId resId);
    void setPath(const VfxWString &path);
    
// Method
protected:

    // create wallpaper
    virtual void onCreateView();

    // release wallpaper
    virtual void onReleaseView();

    // wallpaper save more memory
    virtual void onSerializeView();
    // wallpaper restore memory
    virtual void onRestoreView();

    virtual void onSuspend();
    virtual void onResume();

    // Is allow suspend wallpaper when desktop swipe
    virtual VfxBool onAllowSuspendOnSwipe();
    virtual VfxBool onAllowSuspendOnPenDown();

    virtual VfxU32 getVrtMemFactor();

private:
    VfxBool getWallpaperSource(VfxBool &isResource, VfxWString &filename, VfxResId &resId);
    void playIfPossible();
    void onVideoOpened(VappVideoPlayerComponent *sender, MDI_RESULT result);
    void onVideoFinished(VappVideoPlayerComponent *sender, MDI_RESULT result);
    void handleVideoError(MDI_RESULT result);
    void onDelayPlay(VfxTimer *sender);
    void onHideErrText(VfxTimer *sender);
    VfxBool getVideoSnapshot(VfxBool isResource, const VfxWString &filename, VfxResId resId);
    void createImageBufferFromSnapshotBuffer(VfxImageBuffer &imgBuf);
    void releaseSnapshotBuffer();
    VfxBool isStaticWallpaper();
    VfxBool checkUSBMode();         // check if USB MSC mode before playback
    virtual mmi_ret handleEvent(mmi_event_struct *param);

    // for ASM memory allocation
    VfxBool initASMScreenGroup();
    void deinitASMScreenGroup();
    static mmi_ret onScreenGroupEvent(mmi_event_struct *evt);
    
// Variable
protected:
    VfxBool m_isUSBErrorPopped;     // Flag to ensure only 1 error per USB MSC mode.
    VfxId m_resId;                  // if non-zero, resource video is used.
    VfxWString m_path;              // if non-empty and m_resId is not used, this path is the video wallpaer path
    VappVideoPlayerComponent *m_video;
    VfxTextFrame *m_errText;
    VfxU8 *m_bufSnapshot;
    MMI_ID m_asmGroupId;
};

#endif  // __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
#endif  // __VAPP_WALLPAPER_VIDEO_H__
