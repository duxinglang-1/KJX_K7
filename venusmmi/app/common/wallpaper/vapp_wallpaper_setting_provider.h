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
 *  vapp_wallpaper_setting_provider.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the setting provider of the screen lock.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_WALLPAPER_SETTING_PROVIDER_H
#define VAPP_WALLPAPER_SETTING_PROVIDER_H

#include "MMI_features.h"

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "archive\vapp_archive_file.h"
#include "vapp_wallpaper_id.h"


/*****************************************************************************
 * Setting Provider
 *****************************************************************************/

class VappWallpaperSettingProvider : public VfxObject
{
    VFX_DECLARE_CLASS(VappWallpaperSettingProvider);

    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappWallpaperSettingProvider);

// Constructor / Destructor
public:
    // Default constructor
    VappWallpaperSettingProvider();

    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

// Override
public:
    virtual vrt_allocator_handle getAllocator();

// Method
public:
    // This function gets the default screen lock.
    // RETURNS: Screen lock ID.
    VappWallpaperId getDefaultWallpaper(
        const VappWallpaperSrcEnum src, // [IN] Home screen or lock screen
        VfxObject *parentObj            // [IN]  Parent object
    ) const;

    // This functions sets the default screen lock.
    void setDefaultWallpaper(
        const VappWallpaperSrcEnum src, // [IN] Home screen or lock screen
        const VappWallpaperId &id,      // [IN] Wallpaper ID
        VfxObject *parentObj            // [IN] Parent object
    ) const;

    // retrieve a system-wide default fallback wallpaper.
    // this wallpaper ID is guranteed to be usable.
    static void getFallbackWallpaperId(
        VappWallpaperId &id,                     // [OUT] the fallback id
        VfxBool dueToError                       // [IN] VFX_TRUE means fallback from error, VFX_FALSE means fallback from initialization
    );

    // Notify USB mass storage mode
    // returns VFX_TRUE if wallpaper needs to change
    VfxBool setUsbMassStorageMode(
        VfxBool isMSCMode              // [IN] VFX_TRUE if enter mass storage mode
    );

    static void notifyWallpaperUpdate(VappWallpaperSrcEnum src);
#if (!defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__)) && defined(__MMI_USB_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
    static mmi_ret usbMassStorageModeHdlr(mmi_event_struct *evt);
    void enterMassStorageMode();
    void exitMassStorageMode();
#endif /* __MMI_USB_SUPPORT__  && undefied __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__*/
    

// Implementation
private:    
#ifndef __COSMOS_MMI_PACKAGE__

    // This function formats the archive filename to the provided buffer.
    VfxS32 formatArchiveFilename(
        const VappWallpaperId &id,     // [IN]  Screen lock ID
        VfxId archiveId,                // [IN]  Archive ID
        kal_char *buf,                  // [OUT] Buffer
        VfxS32 size                     // [IN]  Buffer size
    ) const;

    // This functions gets the archive filename of a screen lock.
    void getArchiveFilename(
        const VappWallpaperId &id,     // [IN]  Screen lock ID
        VfxId archiveId,                // [IN]  Archive ID
        VfxWString &archiveFilename     // [OUT] Archive filename
    ) const;

    // This function formats the system archive filename to the provided buffer.
    VfxS32 formatSystemArchiveFilename(
        const VappWallpaperSrcEnum src, // [IN] Home screen or lock screen
        kal_char *buf,                  // [OUT] Buffer
        VfxS32 size                     // [IN]  Buffer size
    ) const;

    // This function gets the system archive filename.
    void getSystemArchiveFilename(
        const VappWallpaperSrcEnum src, // [IN] Home screen or lock screen
        VfxWString &archiveFilename     // [OUT] System archive filename
    ) const;

    // This function converts a ASCII string to a UCS2 string.
    void convertAscii2Ucs2(
        VfxWString &ucs2,                       // [OUT] UCS2 string
        const VfxChar *ascii                    // [IN]  ASCII string
    ) const;
#endif

    // This function creates an archive using the system archive file.
    // RETURN: archive.
    VfxArchive *createArchive(
        const VappWallpaperSrcEnum src,             // [IN] Home screen or lock screen
        const VfxWString &archiveFilename,          // [IN] Archive filename
        VappArchiveFileSource::SourceModeEnum mode, // [IN] Source mode
        VfxObject *parentObj                        // [IN] Parent object
    ) const;

    

    VappWallpaperId getDefaultWallpaperInternal(
        const VappWallpaperSrcEnum src, // [IN] Home screen or lock screen
        VfxObject *parentObj            // [IN]  Parent object
    ) const;

    void handleUninstall(const VfxChar *appName);
    static mmi_ret eventProc(mmi_event_struct *evt);

private:
    VfxBool m_mscMode;
};

#endif /* VAPP_WALLPAPER_SETTING_PROVIDER_H */

