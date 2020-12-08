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
 *  vapp_launcher.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the launcher base class.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_LAUNCHER_H
#define VAPP_LAUNCHER_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER_FACTORY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_archive_file.h"
#include "vapp_launcher_primitive.h"


/*****************************************************************************
 * Launcher Provider Class
 *****************************************************************************/

/*
 * Macro to declare a launcher.
 */
#define VAPP_LAUNCHER_DECLARE_CLASS(_className)                             \
                                                                            \
    VFX_DECLARE_CLASS(_className);                                          \
                                                                            \
    public:                                                                 \
        static VappLauncher *createLauncher(VfxObject *parentObj)


/*
 * Macro to implement a launcher.
 */
#define VAPP_LAUNCHER_IMPLEMENT_CLASS(_className, _parentClassName)         \
                                                                            \
    VFX_IMPLEMENT_CLASS(#_className, _className, _parentClassName);         \
                                                                            \
    VappLauncher *_className::createLauncher(VfxObject *parentObj)          \
    {                                                                       \
        _className *launcher;                                               \
        VFX_OBJ_CREATE(launcher, _className, parentObj);                    \
        return launcher;                                                    \
    }


/*
 * Launcher Base Class
 */
class VappLauncher : public VfxControl
{
    VFX_DECLARE_CLASS(VappLauncher);

// Constructor / Destructor
public:
    // Default constructor
    VappLauncher();

    // Default destructor
    virtual ~VappLauncher();

// Override.
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

// Override
public:
    // Get Id for this launcher.
    // RETURNS: string ID
    virtual VappLauncherId getId() const = 0;

    // Get string resource ID for the name of this launcher.
    // RETURNS: length of the launcher name
    virtual VfxS32 getName(
        VfxWChar *string,           // [OUT] String buffer
        VfxS32 size                 // [IN] Buffer size in wchar
    ) const = 0;

    // Create launcher icon.
    // RETURNS: Launcher icon.
    virtual VfxFrame *createIcon(
        VfxObject *parentObj        // [IN] Parent object
    ) = 0;

// Override
public:
    // This function gets the number of the screenshots.
    // RETURNS: Number of screenshots.
    virtual VfxS32 getScreenshotNum() const;

    // This function creates the screenshots.
    // RETURNS: Array of the screenshots.
    virtual VfxFrame **createScreenshot(
        VfxObject *parentObj        // [IN] Parent of the screenshots
    ) const;

// Signal
public:
    // This signal could be emitted when the launcher cannot run anymore. The
    // launcher application will try to select a usable launcher for the mobile.
    //
    // Note that please post-emit this signal because the handler of this signal
    // generally will deal with this launcher's life cycle.
    VfxSignal1 <
        VappLauncher *              // [IN] This launcher
    > m_signalAbnormalReset;

    // This signal must be emitted when the configuration is completed.
    VfxSignal2 <
        VappLauncher *,             // [IN] This launcher
        VfxBool                     // [IN] Success or cancel
    > m_signalConfigurationCompleted;

// Method
public:
    // This function checks if the launcher supports the configuration.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    //
    // SEE ALSO: createConfiguration,
    VfxBool isConfigurationSupported() const;

    // This function creates the configuration for the user to config this
    // launcher.
    //
    // SEE ALSO: isConfigurationSupported
    void createConfiguration();

// Override
protected:
    // Override this function to declare if the launcher supports the
    // configuration interface.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    virtual VfxBool onGetConfigurationSupported() const;

    // Override this function to create the configuration for the user to config
    // the launcher. Note that after the configuration is completed, remember to
    // emit the m_signalConfigurationCompleted signal.
    //
    // SEE ALSO: m_signalConfigurationCompleted
    virtual void onCreateConfiguration();

// Override
public:
    // This function provides a early timing for users to check if the launcher
    // can be used now. This is mainly used to improve the user experiences such
    // that we can know the launcher cannot be used early. If it isn't
    // available, 'errorString' can be used to prompt the user about the error.
    // If it's available, 'errorString' is undefined.
    // RETURNS: If available, return VFX_TRUE; otherwise, return VFX_FALSE.
    virtual VfxBool checkAvailable(
        VfxWString &errorString     // [OUT] Error string.
    );

// Override
protected:
    // Override this virtual to create the launcher's view.
    virtual void onCreateView();

    // Override this virtual to release the launcher's view.
    virtual void onReleaseView();

// Override
public:
    // Override this virtual to tell if the CreateView is failed. This function
    // is generally called after the createView function to check if the view
    // is created successfully. If it is failed, the 'errorString' is used to
    // prompt the user about the error message. If it is successful,
    // 'errorString' is undefined.
    // RETURNS: If failure exists, return VFX_TRUE; otherwise, return VFX_FALSE.
    //
    // SEE ALSO: createView
    virtual VfxBool getCreateViewFailure(
        VfxWString &errorString     // [OUT] Error string.
    );

// Override
protected:
    // Override this virtual to handle the scenario when the mobile enters the
    // launcher page.
    virtual void onEnter();

    // Override this virtual to handle the scenario after the mobile enters the
    // launcher page.
    virtual void onEntered();

    // Override this virtual to handle the scenario when the mobile exits the
    // launcher page.
    virtual void onExit();

    // Override this virtual to serialize your view. This virtual is mainly used
    // to save more memory. Generally, it is called when the home screen becomes
    // inactive.
    //
    // SEE ALSO: onRestoreView
    virtual void onSerializeView(
        VfxArchive *ar      // [OUT] Archive to save your history
    );

    // Override this virtual to restore your view.
    //
    // SEE ALSO: onSerializeView
    virtual void onRestoreView(
        VfxArchive *ar      // [IN] Archive containing your previous history
    );

    // Override this virtual to use specific status bar bg
    // RETURNS: 9-slice image resource ID.
    virtual VfxResId onGetStatusBarBg();

    // Override this virtual to change status bar to translucent
    // RETURNS: On yes, bar is translucent; otherwise, bar isn't translucent.
    virtual VfxBool onGetStatusBarTranslucent();

    // Override this virtual to handle wallpaper changed event.
    virtual void onWallpaperChanged();

    // Override this virtual to handle the notification center enter event.
    virtual void onNotificationCenterEnter();

    // Override this virtual to handle the notification center exited event.
    virtual void onNotificationCenterExited();

//
// This part implements the functionalities to let launcher manipulate their
// UI component.
//

// Variable
private:
    // If the launcher's view is created from bootup, not reload
    VfxBool     m_isFirstInit;

    // If the launcher's view is created or not.
    VfxBool     m_isCreated;

    // If the launcher's view is entered or not.
    VfxBool     m_isEntered;

    // If the launcher's status is restored or not.
    VfxBool     m_isRestoreStatus;

    // If the home key is been pressed.
    VfxBool     m_isProcessHomeKey;

    // If the launcher's view is serialized or not.
    VfxBool     m_isSerialized;

    // The number of children objects (used to check memory leak between we
    // create and release the view).
    VfxS32      m_numOfChild;

    // Used to backup the serialized view of the launcher.
    VfxMemArchiveSource *m_archiveSource;

// Method
public:
    // Check if the launcher view is created.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isCreated() const
    {
        return m_isCreated;
    }

    // Check if the launcher view is entered.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE;
    VfxBool isEntered() const
    {
        return m_isEntered;
    }

    // Check if the launcher view is serialized.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isSerialized() const
    {
        return m_isSerialized;
    }

    // Check if the launcher is initialized at the first time.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isFirstInit() const
    {
        return m_isFirstInit;
    }

    // Check if the launcher needs to restroe status
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isRestoreStatus() const
    {
        return m_isRestoreStatus;
    }

    // Check if the home key is been pressed
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isProcessHomeKey() const
    {
        return m_isProcessHomeKey;
    }

// Method
public:
    // Create the launcher view.
    void createView();

    // Release the launcher view.
    void releaseView();

    // Enter the view.
    void enter();

    // Enter the view after page SSE.
    void entered();

    // Release the view.
    void exit();

    // Lauincher becomes inactive. You can serialize your view.
    void serializeView();

    // Launcher becomes active. You can restore your view.
    void restoreView();

    // Get customize status bar BG resId.
    // RETURNS: VFX_RES_ID_NULL by Default.
    VfxResId getStatusBarBg();

    // Get if status bar needs translucent.
    // RETURNS: VFX_FALSE by default.
    VfxBool getStatusBarTranslucent();

    // Notify the launcher that the wallpaper is changed.
    void notifyWallpaperChanged();

    // Notify the launcher that the notification center is entered.
    void notifyNotificationCenterEnter();

    // Notify the launcher that the notification center is exited.
    void notifyNotificationCenterExited();

    // Set is first init launcher.
    void setFirstInit(
        VfxBool isFirstInit     // [IN] Is first initialized
    );

    // Set is restore launcher status
    void setIsRestoreStatus(
        VfxBool isRestoreStatus     // [IN] Is restore status
    );

    // Set home key is pressed
    void setIsProcessHomeKey(
        VfxBool isProcessHomeKey     // [IN] Is restore status
    );

};

#endif /* defined(__MMI_VUI_LAUNCHER_FACTORY__) */
#endif /* VAPP_LAUNCHER_H */

