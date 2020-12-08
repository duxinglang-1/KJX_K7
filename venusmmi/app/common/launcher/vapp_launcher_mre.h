/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *  vapp_launcher_mre.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the MRE launcher and its content provider.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_LAUNCHER_MRE_H
#define VAPP_LAUNCHER_MRE_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER_MRE__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vfx_page.h"
#include "vapp_launcher.h"
#include "vpi_app_launcher.h"
#include "vapp_launcher_mre_def.h"


/*****************************************************************************
 * Enum
 *****************************************************************************/

// Event ID for a universal use.
enum VappLauncherProviderEventEnum
{
    // Launcher page is entered.
    VAPP_LAUNCHER_PROVIDER_EVENT_ENTERED,

    // Wallpaper is changed.
    VAPP_LAUNCHER_PROVIDER_EVENT_WALLPAPER_CHANGED,

    // Notification center is entered.
    VAPP_LAUNCHER_PROVIDER_EVENT_NOTIFICATION_ENTER,

    // Notification center is exited.
    VAPP_LAUNCHER_PROVIDER_EVENT_NOTIFICATION_EXITED
};


/*****************************************************************************
 * Typedef
 *****************************************************************************/

// Event structure for a universal use.
struct VappLauncherProviderEventStruct
{
    // Event ID.
    VappLauncherProviderEventEnum id;

    // Event data.
    void *userData;

    // Data size.
    VfxU32 size;
};


/*****************************************************************************
 * Utility Class
 *****************************************************************************/

class VappLauncherMreUtil : public VfxBase
{
// Constructor / Destructor
public:
    // Default constructor
    VappLauncherMreUtil();

public:
    // Get the drive letter of the specified MRE launcher.
    // RETURNS: drive letter.
    static VfxU8 getDriveLetter(
        const VappLauncherId &id        // [IN] Launcher Id
    );

    // Check if the drive letter of the specified launcher is matched on the
    // drive letter array.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    static VfxBool isDriveMatch(
        const VappLauncherId &id,       // [IN] Launcher Id
        const VfxU8 *target,            // [IN] Array of the drive letters.
        VfxU32 count                    // [IN] Size of the array
    );

    // Checks if the 'source' drive letter is matched on the specified drive
    // array.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    static VfxBool isDriveMatch(
        VfxU8 source,                   // [IN] Drive letter
        const VfxU8 *target,            // [IN] Array of the drive letters.
        VfxU32 count                    // [IN] Size of the array
    );
};


/*****************************************************************************
 * Error Mask
 *****************************************************************************/

class VappLauncherMreErrorMask : public VfxBase
{
// Typedef
public:
    typedef VfxU32 ErrorMask;

// Constructor / Destructor
public:
    // Default constructor
    VappLauncherMreErrorMask();

    // Constructed with the specified error.
    VappLauncherMreErrorMask(
        ErrorMask error     // [IN] Error
    );

// Error Bit Const
public:
    // No Error.
    static const ErrorMask NULL_STATE       = 0;

    // File not found.
    static const ErrorMask FILE_NOT_FOUND   = (0x01 << 0);

    // VPI fails.
    static const ErrorMask VPI_FAIL         = (0x01 << 1);

    // USB mass storage.
    static const ErrorMask MASS_STORAGE     = (0x01 << 2);

    // Drive plug-out.
    static const ErrorMask DRIVE_PLUG_OUT   = (0x01 << 3);

    // Out of memory.
    static const ErrorMask OUT_OF_MEM       = (0x01 << 4);

// Method
public:
    // Turn on a error bit in the mask.
    void set(
        ErrorMask value         // [IN]  Error
    );

    // Turn on error bits based on the specified error.
    void set(
        const VappLauncherMreErrorMask &error   // [IN] Error
    );

    // Clear a error bit in the mask.
    void clear(
        ErrorMask value         // [IN]  Error
    );

    // Check if the bit mask has this specific error.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool has(
        ErrorMask value         // [IN] The one you want to check
    ) const;

    // Check if any bit is turned on on the mask.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isAnyError() const;

    // Check if the set of errors can be recovered automatically without user's
    // interaction.
    // RETURNS: If recoverable, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isRecoverable() const;

    // Synchronize the system error state to this error mask.
    void syncSystemState(
        VfxU8 driveLetter       // [IN] Drive letter of VPP
    );

    // Get the error prompt message.
    // RETURNS: string resource ID.
    VfxResId getPrompt() const;

    // Reset the error mask.
    void reset();

// Variable
private:
    // Overall error mask.
    ErrorMask m_mask;
};


/*****************************************************************************
 * MRE Launcher Screenshot
 *****************************************************************************/

class VappLauncherMreScreenshot : public VfxFrame
{
    VFX_DECLARE_CLASS(VappLauncherMreScreenshot);

// Constructor / Destructor
public:
    // Default constructor
    VappLauncherMreScreenshot();

public:
    // Show the screenshot.
    void show(
        const VfxChar *package,     // [IN] VPP package name
        VfxU8 driveLetter           // [IN] Drive where VPP is installed
    );

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

// Enum
private:
    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)
        SCREENSHOT_WIDTH  = 312,
        SCREENSHOT_HEIGHT = 520
    #elif defined(__MMI_MAINLCD_320X480__)
        SCREENSHOT_WIDTH  = 208,
        SCREENSHOT_HEIGHT = 312
    #elif defined(__MMI_MAINLCD_240X400__)
        SCREENSHOT_WIDTH  = 140,
        SCREENSHOT_HEIGHT = 233
    #else /* defined(__MMI_MAINLCD_240X320__) */
        SCREENSHOT_WIDTH  = 140,
        SCREENSHOT_HEIGHT = 187
    #endif /* defined(__MMI_MAINLCD_240X320__) */
    };

// Variable
private:
    // Drive where VPP is installed.
    VfxU8 m_driveLetter;

    // Package name.
    VfxChar *m_package;

    // Memory for screenshot image.
    VfxU8 *m_memPtr;

    // Prompt text.
    VfxTextFrame *m_prompt;

    // Screenshot resource ID.
    static const VfxChar s_resId[];

// Implementation
private:
    // This function registers the event handler.
    void registerEvent();

    // This function de-registers the event handler.
    void deregisterEvent();

    // This function is the main event hanndler.
    static mmi_ret eventProc(
        mmi_event_struct *evt
    );

// Implementation
private:
    // Update the view.
    void updateView();

    // Create the screenshot image content.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool createImageContent(
        VfxResId &errorStr          // [OUT] Error string.
    );

    // Create the error prompt.
    void createErrorPrompt(
        const VfxResId &errorStr    // [IN] Error string.
    );

    // Clear resources.
    void clear();
};


/*****************************************************************************
 * MRE Launcher Provider
 *****************************************************************************/

class VappLauncherMre;

class VappLauncherMreProvider : public VfxControl
{
    VFX_DECLARE_CLASS(VappLauncherMreProvider);

// Constructor / Destructor
public:
    // Default constructor
    VappLauncherMreProvider();

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

    // Please refer to VfxObject.
    virtual void onObjectNotify(
        VfxId id,
        void *userData
    );

// Method
public:
    // Hide or unhide the status bar.
    void setStatusBarHidden(
        VfxBool isHidden    // [IN] Hide or not
    );

    // Check if the launcher needs to restore its previous status.
    // RETURNS: If needed, return VFX_TRUE; otherwise, VFX_FALSE.
    VfxBool isRestoreState() const;

    // Check if the Home key is pressed to launch the launcher.
    // RETURNS: If yes, return VFX_TRUE; otherwise, VFX_FALSE.
    VfxBool isHomeKeyPressed() const;

//
// This section implements the part of manipulating launcher's view.
//

// Method
public:
    // This function requests the provider to create its view.
    void createView();

    // This function requests the provider to release its view.
    void releaseView();

    // This function requests the provider to enter its view.
    void enter();

    // This function requests the provider to exit its view.
    void exit();

    // This function requests the provider to serialize its view.
    void serializeView();

    // This function requests the provider to restore its view.
    void restoreView();

    // This function notifies the event to MRE launcher providier.
    VfxBool notifyEvent(
        VappLauncherProviderEventStruct *event  // [IN] Event
    );

// Override
protected:
    // Override this function to create your view.
    virtual void onCreateView();

    // Override this function to release your view.
    virtual void onReleaseView();

    // Override this function to handle the "enter" event.
    virtual void onEnter();

    // Override this function to handle the "exit" event.
    virtual void onExit();

    // Override this function to serialize its view.
    virtual void onSerializeView();

    // Override this function to restore its view.
    virtual void onRestoreView();

    // Override this function to handle the universal events.
    virtual VfxBool onEvent(
        VappLauncherProviderEventStruct *event  // [IN] Event
    );

//
// Others
//

// Variable
private:
    // MRE launcher.
    VfxWeakPtr<VappLauncherMre> m_launcher;

// Implementation
private:
    // This function handles the "parent frame changed" event.
    void handleParentFrameChanged(
        VfxFrame *origParentFrame   // [IN] Original parent frame
    );

    // Get the page containing this object.
    // RETURNS: Page.
    VfxPage *getPage();
};


/*****************************************************************************
 * MRE Launcher
 *****************************************************************************/

class VappLauncherMre : public VappLauncher
{
    VAPP_LAUNCHER_DECLARE_CLASS(VappLauncherMre);

// Constructor / Destructor
public:
    // Default constructor
    VappLauncherMre();

    // Default destructor
    virtual ~VappLauncherMre();

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

// Method
public:
    // This function gets the drive letter where this MRE widget is installed.
    // RETURNS: drive letter.
    VfxU8 getDriveLetter() const;

    // This function sets the launcher provider.
    void setMreProvider(
        VappLauncherMreProvider *launcherProvider   // [IN] Launcher provider
    );

    // This function sets the ID for this MRE launcher.
    void setId(
        const VappLauncherId &id                    // [IN] MRE launcher ID.
    );

// Method
public:
    // Please refer to VappLauncher.
    virtual VappLauncherId getId() const;

    // Please refer to VappLauncher.
    virtual VfxS32 getName(
        VfxWChar *string,
        VfxS32 size
    ) const;

    // Please refer to VappLauncher.
    virtual VfxFrame *createIcon(
        VfxObject *parentObj
    );

// Override
public:
    // Please refer to VappLauncher.
    virtual VfxS32 getScreenshotNum() const;

    // Please refer to VappLauncher.
    virtual VfxFrame **createScreenshot(
        VfxObject *parentObj
    ) const;

// Override
protected:
    // Please refer to VappLauncher.
    virtual VfxBool checkAvailable(
        VfxWString &errorString
    );

    // Please refer to VappLauncher.
    virtual void onCreateView();

    // Please refer to VappLauncher.
    virtual VfxBool getCreateViewFailure(
        VfxWString &errorString
    );

    // Please refer to VappLauncher.
    virtual void onReleaseView();

    // Please refer to VappLauncher.
    virtual void onEnter();

    // Please refer to VappLauncher.
    virtual void onEntered();

    // Please refer to VappLauncher.
    virtual void onExit();

    // Please refer to VappLauncher.
    virtual void onSerializeView(
        VfxArchive *ar
    );

    // Please refer to VappLauncher.
    virtual void onRestoreView(
        VfxArchive *ar
    );

    // Please refer to VappLauncher.
    virtual void onWallpaperChanged();

    // Please refer to VappLauncher.
    virtual void onNotificationCenterEnter();

    // Please refer to VappLauncher.
    virtual void onNotificationCenterExited();

// Variable
private:
    // MRE launcher ID.
    VappLauncherId m_mreId;

    // Preload App info.
    vm_preload_app_info_t m_preloadInfo;

    // VSO launcher.
    VpiAppLauncher *m_launcher;

    // If the VPP will be closed by itself.
    VfxBool m_isSelfClose;

    // If the VPP is abnormal reset.
    VfxBool m_isAbnormalReset;

    // Error mask.
    VappLauncherMreErrorMask m_errorMask;

    // MRE wiget provider.
    VfxWeakPtr<VappLauncherMreProvider> m_launcherProvider;

//
// Start / Stop VPI.
//

// Method
public:
    // This function starts the VPI.
    VfxBool startVpi();

    // This function shutdowns the VPI.
    void shutdownVpi();

    // This function resets the launcher.
    void abnormalReset();

// Implementation
private:
    // This function handles the 'destroy' signal of the VPP launcher.
    void onVppLauncherDestroy(
        VfxObject *obj      // [IN] VPP launcher
    );

    // This function handles the interrupt that makes the VPI quit.
    void onQuitByInterrupt(
        VfxObject *obj,                                 // [IN] VPI launcher
        VpiAppLauncher::QuitByInterrupTypeEnum cause    // [IN] Cause
    );

    // Prepare the preload APP info structure.
    // RETURNS: Error string.
    VappLauncherMreErrorMask::ErrorMask preparePreloadAppInfo(
        VpiAppLauncher *launcher,       // [IN]  VPP launcher
        const WCHAR *path,              // [IN]  VPP path
        vm_preload_app_info_t &info     // [OUT] APP info
    );

    // Release the preload APP info structure.
    void releasePreloadAppInfo(
        VpiAppLauncher *launcher,       // [IN] VPP launcher
        vm_preload_app_info_t &info     // [IN] APP info
    );

    // This function handles the bounds changed signal of the widget provider.
    void onProviderBoundsChange(
        VfxFrame *source,           // [IN] Launcher provider
        const VfxRect &oldBounds    // [IN] Old bounds
    );

    // Centralize the launcher provider.
    void centralizeProvider();

//
// This section implements the memory model.
//
private:
    // Initialize the memory pool.
    void universalInitMemory();

    // De-initialize the memory pool.
    void universalDeinitMemory();

    // Allocate the memory.
    // RETURNS: memory.
    void *universalMalloc(
        VfxU32 size         // [IN] Size
    );

    // Free the memory.
    void universalFree(
        void *mem           // [IN] Memory
    );

#if defined(__MMI_VUI_LAUNCHER_MRE_USE_ASM__)
// Method
private:
    // Allocate memory from ASM pool.
    void *asmMalloc(
        VfxU32 size     // [IN] Size
    );

    // Free the memory.
    void asmFree(
        void *mem       // [IN] Memory pointer
    );

// Variable
private:
    // ASM memory group ID.
    MMI_ID m_asmGid;

// Implementation
private:
    // Init the ASM memory pool.
    void initAsmMemory();

    // Deinit the ASM memory pool.
    void deinitAsmMemory();

    // This function handles the ASM free request.
    void handleAsmFreeReq();

    // This function handles the ASM events from the framework.
    static mmi_ret onAsmGroupEvent(
        mmi_event_struct *evt   // [IN] Event structure
    );
#else
// Method
private:
    // Allocate memory from global pool.
    void *globalMalloc(
        VfxU32 size     // [IN] Size
    );

    // Free the memory.
    void globalFree(
        void *mem       // [IN] Memory
    );

    // Make the 'val' 4-bytes aligned.
    VfxU32 align4Bytes(
        VfxU32 val      // [IN] Value
    ) const;

private:
    // Size of the global memory pool.
    static const VfxU32 m_size;

    // Current offset in the global memory pool.
    static VfxU32 m_offset;

    // Global memory pool.
    static VfxU32 m_pool[];
#endif /* defined(__MMI_VUI_LAUNCHER_MRE_USE_ASM__) */
};


/*****************************************************************************
 * MRE Launcher Manager
 *****************************************************************************/

class VappLauncherMreManager : public VfxObject
{
    VFX_DECLARE_CLASS(VappLauncherMreManager);

    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappLauncherMreManager);

// Constructor / Destructor
public:
    // Default Constructor
    VappLauncherMreManager();

    // Default destructor
    virtual ~VappLauncherMreManager();

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

//
// Add / Remove launcher to the manager.
//

// Method
public:
    // This function adds MRE launcher to the manager.
    void add(
        VappLauncherMre *launcher
    );

    // This function removes the MRE launcher from the manager.
    void remove(
        VappLauncherMre *launcher
    );

// Variable
private:
    // Pointer to the launcher. At present, launcher is singleton.
    VfxWeakPtr<VappLauncherMre> m_launcher;

//
// Reviver, which will revive the MRE launcher after the abnormal condition
// ends. Abnormal condition could be USB mass storage mode or memory card
// plug-out.
//

// Method
public:
    // Initialize the reviver. The reviver will wait for the timing that the
    // errors are all fixed. At that time, it will revive the MRE launcher.
    void initReviver(
        const VappLauncherId &id,               // [IN] Launcher ID
        const VappLauncherMreErrorMask &error   // [IN] Error
    );

    // Deinitialize the reviver.
    void deinitReviver();

    // Invoke the reviver to revive the MRE launcher.
    void invokeReviver();

// Variable
private:
    // If the revivier is waiting to revive the MRE launcher.
    VfxBool m_isWaitForRevive;

    // The drive which the launcher is installed.
    VfxU8 m_driveLetter;

    // Launcher ID
    VappLauncherId m_launcherId;

    // Launcher ID of the fallback launcher during the abnormal condition.
    VappLauncherId m_fallbackLauncherId;

    // Error mask.
    VappLauncherMreErrorMask m_remainedError;

// Implementation
private:
    // Handle the launcher changed signal.
    void onLauncherChanged();

//
// This section implements the part to handle the system events.
//

// Method
public:
    // This function handles the "uninstall" event.
    void handleUninstall(
        const VfxChar *appName      // [IN] MRE widget name
    );

    // This function handles the "drive-plug-in" event.
    void handleDrivePlugIn(
        const VfxU8 *driveLetter,   // [IN] Array of drive letters
        VfxU32 count                // [IN] Size of the array
    );

    // This function handles the "drive-plug-out" event.
    void handleDrivePlugOut(
        const VfxU8 *driveLetter,   // [IN] Array of the drive letters
        VfxU32 count                // [IN] Size of the array
    );

    // This function handles the "drive-formated" event.
    void handleDriveFormat(
        VfxU8 driveLetter           // [IN] Drive letter
    );

    // this function handles the "USB-mass-storage-mode" event.
    void handleMassStorageMode(
        VfxBool isEnter             // [IN] Enter or exit the mode
    );

// Implementation
private:
    // This function registers the event handler.
    void registerEvent();

    // This function de-registers the event handler.
    void deregisterEvent();

    // This function is the main event hanndler.
    static mmi_ret eventProc(
        mmi_event_struct *evt   // [IN] Event structure
    );
};


#if defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__)

/*****************************************************************************
 * Downloadable APP Icon
 *****************************************************************************/

class VappLauncherMreDltAppIconMgr : public VfxObject
{
    VFX_DECLARE_CLASS(VappLauncherMreDltAppIconMgr);

    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappLauncherMreDltAppIconMgr);

// Constructor / Destructor
public:
    // Default Constructor
    VappLauncherMreDltAppIconMgr();

    // Default destructor
    virtual ~VappLauncherMreDltAppIconMgr();

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

// Enum
private:
    enum
    {
        MAX_RAND_FILENAME_TIME = 10,
        FS_BUF_SIZE = 8192
    };

// Variable
private:
    // MRE resource 1.0 ID for DLT App icon.
    static const VfxChar s_resId[];

    // Base folder for DLT App icon embedded in the MRE launcher.
    static const VfxChar s_basePath[];

    // File extension for DLT App icon.
    static const VfxChar s_fileExt[];

    // Default name for DLT App icon.
    static const VfxChar s_defaultName[];

// Implementation
private:
    void onLauncherChangedFront();

    VfxBool activate(
        const VappLauncherId &id
    );

    void clear();

    void onPostClear();

    VfxBool extractFile(
        const WCHAR *vppPath,
        VfxU32 fileOffset,
        VfxU32 fileSize,
        VfxWString &output
    );

    VfxBool extractFileFromDisk(
        const WCHAR *vppPath,
        const VfxU32 fileOffset,
        const VfxU32 fileSize,
        const VfxWString &iconPath
    );

    VfxBool extractFileFromRom(
        const WCHAR *vppPath,
        const VfxU32 fileOffset,
        const VfxU32 fileSize,
        const VfxWString &iconPath
    );

    VfxBool updateSetting(
        const VfxWString &iconPath
    );

    void getIconPath(
        VfxWString &iconPath
    );

    VfxBool createFolder(
        const VfxWString &path
    );
};


/*****************************************************************************
 * FUNCTION
 *  vapp_launcher_mre_activate_dlt_app_icon_mgr
 * DESCRIPTION
 *  This function activates the DLT app icon manager.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vapp_launcher_mre_activate_dlt_app_icon_mgr();


#endif /* defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__) */

#endif /* defined(__MMI_VUI_LAUNCHER_MRE__) */
#endif /* VAPP_LAUNCHER_MRE_H */

