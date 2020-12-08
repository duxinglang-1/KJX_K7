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
 *  vapp_widget_mre.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the MRE widget.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_WIDGET_MRE_H
#define VAPP_WIDGET_MRE_H

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_MRE__)

/*****************************************************************************
 * Include
 *****************************************************************************/

extern "C"
{
#include "custom_widget_config.h"
#include "MMIDataType.h"
}

#include "vfx_uc_include.h"
#include "vapp_widget.h"
#include "vpi_app_launcher.h"
#include "vapp_archive_nvram.h"


/*****************************************************************************
 * MRE Widget Placard
 *****************************************************************************/

class VappWidgetMrePlacard : public VfxFrame
{
    VFX_DECLARE_CLASS(VappWidgetMrePlacard);

// Constructor / Destructor
public:
    // Default constructor
    VappWidgetMrePlacard();

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

// Method
public:
    // This function sets the icon of the placard.
    void setIcon(
        VfxResId imageId            // [IN] Image ID
    );

    // This function sets the text of the placard.
    void setText(
        const VfxWString &string    // [IN] String
    );

// Enum
private:
    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)
        FONT_SIZE = 21,
        MARGIN = 10,
        MARGIN_TOP = 15
    #elif defined(__MMI_MAINLCD_320X480__)
        FONT_SIZE = 14,
        MARGIN = 5,
        MARGIN_TOP = 10
    #elif defined(__MMI_MAINLCD_240X400__)
        FONT_SIZE = 13,
        MARGIN = 5,
        MARGIN_TOP = 10
    #else /* defined(__MMI_MAINLCD_240X320__) */
        FONT_SIZE = 12,
        MARGIN = 5,
        MARGIN_TOP = 10
    #endif /* defined(__MMI_MAINLCD_240X320__) */
    };

// Variable
private:
    // Hint text.
    VfxTextFrame *m_textFrame;

    // Hint icon.
    VfxImageFrame *m_icon;

    // Max ratio of the icon size compared to the placard size.
    static const VfxFloat s_iconSizeRatio;
};


/*****************************************************************************
 * MRE Widget Provider
 *****************************************************************************/

class VappWidgetMre;

class VappWidgetMreProvider : public VfxControl
{
    VFX_DECLARE_CLASS(VappWidgetMreProvider);

// Constructor / Destructor
public:
    // Default constructor
    VappWidgetMreProvider();

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
    // This function requests the provider to create its view.
    void createView();

    // This function requests the provider to release its view.
    void releaseView();

    // This function requests the provider to serialize its view.
    void serializeView();

    // This function requests the provider to restore its view.
    void restoreView();

    // This fucntion gets the delete button offset.
    VfxPoint getDeleteButtonOffset() const;

// Override
protected:
    // Provider could override this function to create its view.
    virtual void onCreateView();

    // Provider could override this function to release its view.
    virtual void onReleaseView();

    // Provider could override this function to serialize its view.
    virtual void onSerializeView();

    // Provider could override this function to restore its view.
    virtual void onRestoreView();

    // Provider could override this function to set the delete button position.
    virtual VfxPoint onGetDeleteButtonOffset() const;

// Enum
private:
    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)
        EDIT_BUTTON_OFFSET_X = 20,
        EDIT_BUTTON_OFFSET_Y = 25
    #elif defined(__MMI_MAINLCD_320X480__)
        EDIT_BUTTON_OFFSET_X = 16,
        EDIT_BUTTON_OFFSET_Y = 20
    #elif defined(__MMI_MAINLCD_240X400__)
        EDIT_BUTTON_OFFSET_X = 13,
        EDIT_BUTTON_OFFSET_Y = 18
    #else /* defined(__MMI_MAINLCD_240X320__) */
        EDIT_BUTTON_OFFSET_X = 13,
        EDIT_BUTTON_OFFSET_Y = 18
    #endif /* defined(__MMI_MAINLCD_240X320__) */
    };

// Variable
private:
    // MRE wiget.
    VfxWeakPtr<VappWidgetMre> m_widget;

// Implementation
private:
    // This function handles the "parent frame changed" event.
    void handleParentFrameChanged(
        VfxFrame *origParentFrame   // [IN] Original parent frame
    );
};


/*****************************************************************************
 * MRE Widget
 *****************************************************************************/

class VappWidgetMre : public VappWidget
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidgetMre);

    // Manager is allowed to access any member data of the MRE widget.
    friend class VappWidgetMreManager;

// Typedef
public:
    typedef VfxU32 ErrorMask;

// Constructor / Destructor
public:
    // Default constructor
    VappWidgetMre();

    // Default destructor
    virtual ~VappWidgetMre();

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

// Method
public:
    // This function gets the drive letter where this MRE widget is installed.
    // RETURNS: drive leter.
    VfxU8 getDriveLetter() const;

    // This function sets the widget provider.
    void setMreProvider(
        VappWidgetMreProvider *widgetProvider   // [IN] Widget provider
    );

    // This function sets the id for this MRE widget.
    void setId(
        const VappWidgetId &id                  // [IN] MRE widget ID.
    );

// Method
public:
    // Please refer to VappWidget.
    virtual VappWidgetId getId() const;

    // Please refer to VappWidget.
    virtual VfxS32 getName(
        VfxWChar *string,
        VfxS32 size
    ) const;

    // Please refer to VappWidget.
    virtual VfxSize getMaxSize() const;

    // Please refer to VappWidget.
    virtual VfxFrame *createIcon(
        VfxObject *parentObj
    );

// Override
protected:
    // Please refer to VappWidget.
    virtual VfxPoint onGetEditButtonOffset();

    // Please refer to VappWidget.
    virtual void onCreateView();

    // Please refer to VappWidget.
    virtual VfxBool getCreateViewFailure(
        VfxWString &errorString
    );

    // Please refer to VappWidget.
    virtual void onReleaseView();

    // Please refer to VappWidget.
    virtual void onSerializeView(
        VfxArchive *ar
    );

    // Please refer to VappWidget.
    virtual void onRestoreView(
        VfxArchive *ar
    );

// Enum
private:
    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)
        EDIT_BUTTON_OFFSET_X = 20,
        EDIT_BUTTON_OFFSET_Y = 25
    #elif defined(__MMI_MAINLCD_320X480__)
        EDIT_BUTTON_OFFSET_X = 16,
        EDIT_BUTTON_OFFSET_Y = 20
    #elif defined(__MMI_MAINLCD_240X400__)
        EDIT_BUTTON_OFFSET_X = 13,
        EDIT_BUTTON_OFFSET_Y = 18
    #else /* defined(__MMI_MAINLCD_240X320__) */
        EDIT_BUTTON_OFFSET_X = 13,
        EDIT_BUTTON_OFFSET_Y = 18
    #endif /* defined(__MMI_MAINLCD_240X320__) */
    };

// Variable
private:
    // MRE widget ID.
    VappWidgetId m_mreId;

    // Preload App info.
    vm_preload_app_info_t m_preloadInfo;

    // VSO launcher.
    VpiAppLauncher *m_launcher;

    // String ID for the failure of the createView.
    VfxResId m_createViewFailurePrompt;

    // If the VPP will be closed by itself.
    VfxBool m_isSelfClose;

    // MRE wiget provider.
    VfxWeakPtr<VappWidgetMreProvider> m_widgetProvider;

// Implementation
private:
    // This function starts the VPI.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool startVpi();

    // This function shutdowns the VPI.
    void shutdownVpi();

    // This function handles the 'destroy' signal of the VPP launcher.
    void onDestroy(
        VfxObject *obj      // [IN] VPP launcher
    );

    // This function releases all objects.
    void clear();

    // This function handles the interrupt that makes the VPI quit.
    void onQuitByInterrupt(
        VfxObject *obj,                                 // [IN] VPI launcher
        VpiAppLauncher::QuitByInterrupTypeEnum cause    // [IN] Cause
    );

    // Prepare the preload APP info structure.
    // RETURNS: error code.
    ErrorMask preparePreloadAppInfo(
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
        VfxFrame *source,           // [IN] Widget provider
        const VfxRect &oldBounds    // [IN] Old bounds
    );

//
// This section handles the interrupts that let the widget cannot work
// temporarily.
//

// Method
public:
    // This function notifies that the widget has error. It could show the image
    // or icon to let the users know the cause.
    void notifyError(
        ErrorMask value                      // [IN] Error
    );

    // This function fixes the error.
    void fixingError(
        ErrorMask value                      // [IN] Error
    );

    // This function is the callback handler to start the VPI.
    void onDelayStartVpi();

// Variable
private:
    // Error placard.
    VappWidgetMrePlacard *m_placard;

    // Error mask assocaited with the placard.
    ErrorMask m_placardErrorMask;

    // Error mask
    ErrorMask m_errorMask;

// Implementation
private:
    // Centralize the widget provider.
    void centralizeProvider();

    // Synchronize the system error state to this MRE widget.
    void syncSystemState();

    // Create the error placard.
    void createPlacard();

    // Close the error placard.
    void closePlacard();

    // Get the information about the next error we will prompt to the user.
    void getNextErrorPromptInfo(
        ErrorMask inValue,      // [IN]  Group of errors
        ErrorMask &outValue,    // [OUT] Next error we will prompt
        VfxResId &imgId,        // [OUT] Image ID
        VfxResId &strId         // [OUT] String ID
    ) const;

    // Check if the set of errors can be recovered automatically without user's
    // interaction. If yes, the user will see the error placard; otherwise, the
    // widget should be closed.
    // RETURNS: If recoverable, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isErrorRecoverable(
        ErrorMask mask          // [IN] Error
    ) const;

    // Turn on a error bit in the mask.
    void setErrorMask(
        ErrorMask &mask,        // [OUT] Group of errors
        ErrorMask value         // [IN]  Error
    ) const;

    // Clear a error bit in the mask.
    void clearErrorMask(
        ErrorMask &mask,        // [OUT] Group of errors
        ErrorMask value         // [IN]  Error
    ) const;

    // Check if the bit mask has this specific error.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool hasError(
        ErrorMask mask,         // [IN] Group of errors
        ErrorMask value         // [IN] The one you want to check
    ) const;

    // Check if any bit is turned on on the mask.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool getAnyError(
        ErrorMask mask          // [IN] Group of errors
    ) const;
};


/*****************************************************************************
 * MRE Widget Property
 *****************************************************************************/

// Property
typedef struct
{
    VfxU8 isUsed;       // Is used?
    VfxU16 isValid;     // Is valid?
    VfxU16 width;       // Width of the widget
    VfxU16 height;      // Height of the widget
    VappWidgetId id;    // Id of the widget
} VappWidgetMreProperty;


/*****************************************************************************
 * MRE Widget Manager
 *****************************************************************************/

class VappWidgetMreManager : public VfxObject
{
    VFX_DECLARE_CLASS(VappWidgetMreManager);

// Constructor / Destructor
public:
    // Default constructor
    VappWidgetMreManager();

    // Default destructor
    virtual ~VappWidgetMreManager();

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

//
// This section implements the part to add / remove widgets.
//

// Method
public:
    // This function gets the instance of the manager.
    // RETURNS: manager.
    static VappWidgetMreManager *getInstance();

    // This function adds MRE widget to the manager.
    static void add(
        VappWidgetMre *widget   // [IN] Manager
    );

    // This function removes the MRE widget from the manager.
    static void remove(
        VappWidgetMre *widget   // [IN] Manager
    );

// Variable
private:
    // Widget manager.
    static VappWidgetMreManager *s_mgr;

//
// This section implements the part to restore the widget one-by-one.
//

// Enum
private:
    enum
    {
        TIMER_DURATION    = 300
    };

// Struct
private:
    // Job object.
    class JobObj : public VfxObject
    {
    public:
        // Job's callback
        VfxCallback0 m_callback;
    };

// Variable
private:
    // Timer to schedule the job.
    VfxTimer *m_timer;

    // Job list.
    VfxObjList m_jobList;

// Method
public:
    // Submit a job to the manager scheduler.
    void submitJob(
        const VfxCallback0 &callback    // [IN] Job callback
    );

    // Cancel the job from the manager scheduler.
    void cancelJob(
        const VfxCallback0 &callback    // [IN] Job callback
    );

// Implementation
private:
    // Append the job object to the list.
    void appendJobObj(
        const VfxCallback0 &callback    // [IN] Job callback
    );

    // Remove the job object from the list.
    void removeJobObj(
        const VfxCallback0 &callback    // [IN] Job callback
    );

    // Check if the job is found in the list.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isJobObjFound(
        const VfxCallback0 &callback    // [IN] Job callback
    ) const;

    // This is the handler function to invoke the job callback and schedule the
    // next job.
    void onScheduleNextJob(
        VfxTimer *timer                 // [IN] Timer
    );

//
// This section implements the part to handle the system events.
//

// Variable
private:
    // Widget list.
    VfxObjList m_widgetList;

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

//
// This section implements the memory model.
//

// Method
public:
    // Allocate memory from ASM pool.
    void *malloc(
        VfxS32 size     // [IN] Size
    );

    // Free the memory.
    void free(
        void *mem       // [IN] Memory pointer
    );

// Variable
private:
    // ASM memory group ID.
    MMI_ID m_asmGid;

// Implementation
private:
    // Init the memory pool.
    void initMemory();

    // Deinit the memory pool.
    void deinitMemory();

    // This function handles the ASM free request.
    void handleAsmFreeReq();

    // This function handles the ASM events from the framework.
    static mmi_ret onAsmGroupEvent(
        mmi_event_struct *evt   // [IN] Event structure
    );

//
// This section implements the part to save important properties of the widget.
//

// Method
public:
    // Set the property of the widget.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool setProperty(
        const VappWidgetId &id, // [IN] Widget ID
        const VfxSize &size     // [IN] Size of the widget
    );

    // Get the property of the widget.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool getProperty(
        const VappWidgetId &id, // [IN]  Widget ID
        VfxSize &size           // [OUT] Size of the widget
    );

// Enum
private:
    enum
    {
        // Property guard pattern.
        GUARD_PATTERN = 0xBABEC0DE,

        // Max number of widgets.
        WIDGET_NUM = CUSTOM_WIDGET_MRE_MAX_NUM
    };

// Variable
private:
    // Is property initialized?
    VfxBool isPropertyInit;

    // Property arrays.
    VappWidgetMreProperty m_property[WIDGET_NUM];

// Implementation
private:
    // Initialize the properties.
    void initProperty();

    // Save the property to the NVRAM.
    void saveProperty();

    // Find the slot of the property for this widget ID. If not existed, it will
    // try to find a unused slot for it.
    // RETURNS: -1: not found. Other values: slot index.
    VfxS32 find(
        const VappWidgetId &id  // [IN] Widget ID
    );

    // Create the NVRAM archive.
    // RETURNS: archive.
    VfxArchive *createArchive(
        nvram_lid_enum lid,                         // [IN] NVRAM logic ID
        VfxS32 lidIndex,                            // [IN] LID index
        VfxS32 lidSize,                             // [IN] LID size
        VappArchiveNvramSource::SourceModeEnum mode,// [IN] Mode
        VfxObject *parentObj                        // [IN] Memory source
    ) const;

    // Create the property archive.
    // RETURNS: archive.
    VfxArchive *createPropertyArchive(
        VappArchiveNvramSource::SourceModeEnum mode,// [IN] Mode
        VfxObject *parentObj                        // [IN] Memory source
    ) const;

//
// Misc. help functions.
//

// Implementation
private:
    // This function checks if the MRE widget's VPP file is installed on the
    // specified drive.
    // RETURN: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isDriveLetterMatch(
        const VappWidgetMre *widget,    // [IN] Widget
        const VfxU8 *driveLetter,       // [IN] Array of the drive letters.
        VfxU32 count                    // [IN] Size of the array
    ) const;
};

#endif /* defined(__MMI_VUI_WIDGET_MRE__) */
#endif /* VAPP_WIDGET_MRE_H */

