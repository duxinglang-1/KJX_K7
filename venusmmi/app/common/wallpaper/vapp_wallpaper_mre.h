/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vapp_wallpaper_mre.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the MRE wallpaper.
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

#ifndef VAPP_WALLPAPER_MRE_H
#define VAPP_WALLPAPER_MRE_H

#include "MMI_features.h"

#if defined(__MMI_VUI_WALLPAPER_MRE__)

/*****************************************************************************
* Include
*****************************************************************************/
#include "vfx_uc_include.h"
#include "vapp_wallpaper_def.h"
#include "vapp_wallpaper.h"
#include "vpi_app_launcher.h"
#include "vpi_wallpaper_provider_interface.h"
extern "C"
{
#include "MREAppMgrSrvGprot.h"
}

/*****************************************************************************
* MRE Screen Lock
*****************************************************************************/

class VappWallpaperMre;

typedef enum
{
  VAPP_WP_PROVIDER_SUSPEND_ON_DESKTOP_SWIPE,
  VAPP_WP_PROVIDER_SUSPEND_ON_PEN_DOWN,
}vapp_wp_provider_suspend_type_enum;

typedef enum
{
  VAPP_WP_PROVIDER_EVENT_DRAGGED,    // userData is (vm_wallpaper_provider_pos_struct *)
  VAPP_WP_PROVIDER_EVENT_MOVED,      // userData is (vm_wallpaper_provider_pos_struct *)
  VAPP_WP_PROVIDER_EVENT_DROPPED,    // userData is (vm_wallpaper_provider_pos_struct *)
}vapp_wp_provider_event_enum;

typedef struct
{
    VfxPoint pos;
    VfxFrame *targetWidget;
}vapp_wp_provider_pos_struct;

typedef struct
{
  vapp_wp_provider_event_enum event;
  VfxU32 size;
  void *userData;
}vapp_wp_provider_event_struct;

typedef enum
{
    VAPP_WP_PROVIDER_ENV_SRC_TYPE // env is (vm_wallpaper_src_type_enum)
}vapp_wp_provider_env_enum;


class VappWallpaperMreProvider : public VfxControl
{
    VFX_DECLARE_CLASS(VappWallpaperMreProvider);

// Constructor / Destructor
public:
    // Default constructor
    VappWallpaperMreProvider();

// Override
protected:
    // Please refer to VfxFrame.
    virtual void onObjectNotify(VfxId id, void *userData);

// Method
public:

    VfxS32 getTotalPage();
    void suspend();
    void resume();
    VfxBool isSuspended();
    VfxU32 getEnv(
        vapp_wp_provider_env_enum env,
        void *value);

// Override
protected:
    friend class VappWallpaperMre;

    virtual void onCreateView();
    virtual void onReleaseView();
    virtual void onSerializeView();
    virtual void onRestoreView();
    virtual void onSuspend();
    virtual void onResume();
    virtual void onDesktopCursorChanged(VfxFloat curPos, VfxFloat oldPos);
    virtual VfxBool onQuerySuspend(vapp_wp_provider_suspend_type_enum suspendType);
    virtual void onEvent(vapp_wp_provider_event_struct* event);

// Method
private:
    // MRE wiget provider.
    VfxWeakPtr<VappWallpaperMre> m_wallpaperMre;
};


/*****************************************************************************
* MRE Wallpaper (host for MRE wallpaper provider)
*****************************************************************************/
class VappWallpaperMre : public VappWallpaper
{
    VFX_DECLARE_CLASS(VappWallpaperMre);
    VAPP_WALLPAPER_CREATE(VappWallpaperMre);
// Constructor / Destructor
public:
    VappWallpaperMre();
    ~VappWallpaperMre();
    void initMreWallpaperState();

// Method
public:
    void setMreId(const VfxString &mreId);
    void setMreProvider(VappWallpaperMreProvider *provider);

// Method
public:
    // Please refer to VappWallpaper.
    virtual void getName(VfxWString &wallpaperName);

    // This function used to get image id of wallpaper thumbnail
    // RETURN resource id of the thumbnail. 0 if there is no build-in thumbnail.
    virtual MMI_IMG_ID getThumbnail();

    // return image source of thumbnail.
    // if the image source is VfxImageBuffer, the memory is
    // provided by the wallpaper object itself.
    virtual VfxBool getThumbnailImageSrc(VfxImageSrc &output);
// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();
    
    // Please refer to VappWallpaper.

    virtual void onCreateView();
    virtual void onReleaseView();
    virtual void onSerializeView();
    virtual void onRestoreView();
    virtual void onSuspend();
    virtual void onResume();

    virtual void onDesktopCursorChanged(VfxFloat curPos, VfxFloat oldPos);

    virtual VfxBool onAllowSuspendOnSwipe();
    virtual VfxBool onAllowSuspendOnPenDown();

    virtual void onWidgetDragged(
        VfxPoint pos,
        VfxControl *targetWidget
    );
    virtual void onWidgetMoved(
        VfxPoint pos,
        VfxControl *targetWidget
    );
    virtual void onWidgetDropped(
        VfxPoint pos,
        VfxControl *targetWidget
    );

    virtual VfxBool onPenInput(VfxPenEvent &event);

    virtual VfxBool checkResource();
// Variable
private:
    // VSO launcher.
    VpiAppLauncher *m_launcher;

    // MRE id string
    VfxString m_mreId;

    // MRE wiget provider.
    VfxWeakPtr<VappWallpaperMreProvider> m_wallpaperProvider;
    friend class VappWallpaperMreProvider;
    
    // ASM memory group ID.
    MMI_ID m_asmGid;

    // Preload App info.
    vm_preload_app_info_t m_preloadInfo;
    
    VfxFloat m_curPos;

    VfxTextFrame *m_textFrmErr;
    
    VfxS32 m_errStrId;
    
    VfxBool m_isSelfClose;

    VfxBool m_isCardPlugOut;

    VfxBool m_isCreateView;
    
    VfxBool launchVpi();
    void terminateVpi();

    void getResource();
    void releaseResource();

    void handleCardPlugOut();
    
    VfxBool isDriveLetterMatch(
        const VfxU8 *driveLetter,
        VfxU32 count) const;
    
    // This function is the main event hanndler.
    static mmi_ret eventProc(
        mmi_event_struct *evt   // [IN] Event structure
    );

    // memory APIs
    void initMemory();    
    void deinitMemory();
    void *malloc(VfxS32 size);
    void free(void *mem);

    void showDefault();

    // This function handles the 'destroy' signal of the VPP launcher.
    void onDestroy(
        VfxObject *obj      // [IN] VPP launcher
    );

    // This function handles the interrupt that makes the VPI quit.
    void onQuitByInterrupt(
        VfxObject *obj,                                 // [IN] VPI launcher
        VpiAppLauncher::QuitByInterrupTypeEnum cause    // [IN] Cause
    );
    
    // This function handles the ASM events from the framework.
    static mmi_ret onAsmGroupEvent(
        mmi_event_struct *evt   // [IN] Event structure
    );

    // Prepare the preload APP info structure.
    // RETURNS: error code.
    VfxBool preparePreloadAppInfo(
        VpiAppLauncher *launcher,       // [IN]  VPP launcher
        const WCHAR *path,              // [IN]  VPP path
        vm_preload_app_info_t &info     // [OUT] APP info
    );

    // Release the preload APP info structure.
    void releasePreloadAppInfo(
        VpiAppLauncher *launcher,       // [IN] VPP launcher
        vm_preload_app_info_t &info     // [IN] APP info
    );
    
};

#endif /* defined(__MMI_VUI_WALLPAPER_MRE__) */
#endif /* VAPP_WIDGET_MRE_H */


