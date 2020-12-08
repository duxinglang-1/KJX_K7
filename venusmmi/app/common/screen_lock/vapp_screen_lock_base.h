/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_screen_lock_base.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the screen lock's base class.
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

#ifndef VAPP_SCREEN_LOCK_BASE_H
#define VAPP_SCREEN_LOCK_BASE_H

#include "MMI_features.h"

#if defined(__MMI_VUI_SCREEN_LOCK_FACTORY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_archive_file.h"
#include "vapp_screen_lock_primitive.h"


/*****************************************************************************
 * Screen Lock Base Class
 *****************************************************************************/

typedef VfxBool (*vapp_screen_lock_block_interaction_callback)();

/*
 * Macro to declare a screen lock.
 */
#define VAPP_SCREEN_LOCK_DECLARE_CLASS(_className)                          \
                                                                            \
    VFX_DECLARE_CLASS(_className);                                          \
                                                                            \
    public:                                                                 \
        static VappScreenLock *createScreenLock(VfxObject *parentObj)


/*
 * Macro to implement a screen lock.
 */
#define VAPP_SCREEN_LOCK_IMPLEMENT_CLASS(_className, _parentClassName)      \
                                                                            \
    VFX_IMPLEMENT_CLASS(#_className, _className, _parentClassName);         \
                                                                            \
    VappScreenLock *_className::createScreenLock(VfxObject *parentObj)      \
    {                                                                       \
        _className *screenLock;                                             \
        VFX_OBJ_CREATE(screenLock, _className, parentObj);                  \
        return screenLock;                                                  \
    }


/*
 * Screen Lock Base Class
 */
class VappScreenLock : public VfxControl
{
    VFX_DECLARE_CLASS(VappScreenLock);

// Constructor / Destructor
public:
    // Default constructor
    VappScreenLock();

    // Default destructor
    virtual ~VappScreenLock();

// Signal
public:
    // This signal is emitted when unlock happens
    VfxSignal1 <VappScreenLock *> m_signalUnlock;

// Method
public:
    // Check if the screen lock view is created.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isCreated() const
    {
        return m_isCreated;
    }

    // Check if the screen lock view is entered.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE;
    VfxBool isEntered() const
    {
        return m_isEntered;
    }

    // Check if the screen lock view is serialized.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isSerialized() const
    {
        return m_isSerialized;
    }

    //
    // Create the screen lock view.
    //
    void createView();

    //
    // Release the screen lock view.
    //
    void releaseView();

    //
    // notify when screen lock page enter
    //
    void processPageEnter();

    //
    // notify when screen lock page exit
    //
    void processPageExit();

    // screen lock becomes inactive. You can serialize your view.
    //
    // NOTE: Internal used only.
    void serializeView();

    // screen lock becomes active. You can restore your view.
    //
    // NOTE: Internal used only.
    void restoreView();

    //
    // notify when backlight Off
    //
    void notifyBacklightOff();

    //
    // notify when screen lock page exit
    //
    void notifyBacklightOn();

    //
    // get customize status bar BG resId
    // Default: NULL
    //
    VfxResId getStatusBarBg();

    //
    // get if status bar needs translucent
    // Default: VFX_FALSE
    //
    VfxBool getStatusBarTranslucent();

// Override.
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

    // Stop home key routing if screen lock app is active.
    // The reason for write onkeyInput on screen lock base is that,
    // key routing is working based on 'focus', so it will not route to its parent,
    // and therefore, screen lock app(lock_main) will not receive onKeyInput.
    // MAUI_03189891
    virtual VfxBool onKeyInput(
        VfxKeyEvent &event
    );

// Overridable
public:
    // Get Id for this screen lock
    // RETURNS: string ID
    virtual VappScreenLockId getId() const = 0;

    // Get string resource ID for the name of this screen lock
    // RETURNS: length of the screen lock name
    virtual VfxS32 getName(
        VfxWChar *string,           // [OUT] String buffer
        VfxS32 size                 // [IN] Buffer size in wchar
    ) const = 0;

    // Create screen lock icon.
    // RETURNS: frame
    virtual VfxFrame *createIcon(
        VfxObject *parentObj        // [IN] Parent object
    ) = 0;

// Overridable
public:
    // This function gets the number of the screenshots.
    // RETURNS: Number of screenshots.
    virtual VfxS32 getScreenshotNum() const;

    // This function creates the screenshots.
    // RETURNS: Array of the screenshots.
    virtual VfxFrame **createScreenshot(
        VfxObject *parent           // [IN] Parent of the screenshots
    ) const;

// Signal
public:
    // This signal must be emitted when the configuration is completed.
    VfxSignal2 <
        VappScreenLock *,           // [IN] This screen lock
        VfxBool                     // [IN] Success or cancel
    > m_signalConfigurationCompleted;

// Method
public:
    // This function checks if the screen lock supports the configuration.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    //
    // SEE ALSO: createConfiguration
    VfxBool isConfigurationSupported() const;

    // This function creates the configuration for the user to config this
    // screen lock.
    //
    // SEE ALSO: isConfigurationSupported
    void createConfiguration();

// Override
protected:
    // Override this function to declare if the screen lock supports the
    // configuration.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    virtual VfxBool onGetConfigurationSupported() const;

    // Override this function to create the configuration for the user to config
    // the screen lock. Note that after the configuration completes, remember
    // to emit the m_signalConfigurationCompleted signal.
    //
    // SEE ALSO: m_signalConfigurationCompleted
    virtual void onCreateConfiguration();

// Override
public:
    // This function provides a early timing for users to check if the screen
    // lock can be used now. This is mainly used to improve the user experiences
    // such that we can know the screen lock cannot be used early. If it isn't
    // available, 'errorString' can be used to prompt the user about the error.
    // If it's available, 'errorString' is undefined.
    // RETURNS: If available, return VFX_TRUE; otherwise, return VFX_FALSE.
    virtual VfxBool checkAvailable(
        VfxWString &errorString     // [OUT] Error string.
    );

// Overridable
protected:
    // Override this virtual to create the screen lock's view.
    virtual void onCreateView();

    // Override this virtual to release the screen lock's view.
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
        VfxWString &errorString     // [OUT] Prompt message for the user
    );

// Overridable
protected:
    // While entering the screen lock page
    virtual void onPageEnter();

    // While leaving the screen lock page, it will be called before snapshot
    // It needs to suspend wallpaper at this moment for video wallpaper snapshot.
    virtual void onPageExit();

    // Override this virtual to serialize your view. This virtual is mainly used
    // to save more memory. Generally, it is called when the screen lock screen becomes
    // inactive.
    //
    // SEE ALSO: onRestoreView
    virtual void onSerializeView();

    // Override this virtual to restore your view.
    //
    // SEE ALSO: onSerializeView
    virtual void onRestoreView();

    virtual VfxResId onGetStatusBarBg();

    virtual VfxBool onGetStatusBarTranslucent();

    virtual void onBacklightOn();

    virtual void onBacklightOff();

// Variable
private:
    // If the screen lock's view is created or not.
    VfxBool     m_isCreated;

    // If the screen lock's view is entered or not.
    VfxBool     m_isEntered;

    // If the launcher's view is serialized or not.
    VfxBool     m_isSerialized;

    // The number of children objects (used to check memory leak between
    // create and release the view).
    VfxS32      m_numOfChild;
};

#endif /* defined(__MMI_VUI_SCREEN_LOCK_FACTORY__) */
#endif /* VAPP_SCREEN_LOCK_H */

