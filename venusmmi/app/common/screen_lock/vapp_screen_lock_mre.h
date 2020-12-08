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
 *  vapp_screen_lock_mre.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the MRE screen lock.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_SCREEN_LOCK_MRE_H
#define VAPP_SCREEN_LOCK_MRE_H

#include "MMI_features.h"

#if defined(__MMI_VUI_SCREEN_LOCK_MRE__)

/*****************************************************************************
* Include
*****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_screen_lock_base.h"
#include "vpi_app_launcher.h"
#include "vapp_screen_lock_primitive.h"

/*****************************************************************************
* MRE Screen Lock
*****************************************************************************/

#define VAPP_SCREEN_LOCK_MRE_BACKLIGHT_OFF_TIME                (8)

class VappScreenLockMre;

class VappScreenLockMreUtil : public VfxBase
{
// Constructor / Destructor
public:
    // Default constructor
    VappScreenLockMreUtil();

public:

    // > 0: match. =0: not match, <0: error
    static VfxS32 isDriveLetterMatch(
        const VappScreenLockId mreId,
        const VfxU8 *driveLetter,
        VfxU32 count
    );

    static VfxU8 VappScreenLockMreUtil::getDriveLetter(
        const VappScreenLockId mreId);
};

class VappScreenLockMreScreenshot : public VfxFrame
{
    VFX_DECLARE_CLASS(VappScreenLockMreScreenshot);

// Constructor / Destructor
public:
    // Default constructor
    VappScreenLockMreScreenshot();

    // Construct
    VappScreenLockMreScreenshot(
        const VappScreenLockId &mreId
    );

    // Default destructor
    ~VappScreenLockMreScreenshot();

    virtual void onInit();

    virtual void onDeinit();

    void updateScreenshot();

    VfxBool getPreviewImg();

private:
    
    const VappScreenLockId m_mreId;

    VfxImageFrame *m_imgFrame;
    VfxU8 *m_imgBuf;

    VfxTextFrame *m_textFrmErr;
    VfxS32 m_errStrId;

    VfxBool isDriveLetterMatch(
        const VfxU8 *driveLetter,
        VfxU32 count) const;
    
    // This function is the main event hanndler.
    static mmi_ret eventProc(
        mmi_event_struct *evt   // [IN] Event structure
    );

    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)    
        PREVIEW_IMG_WIDTH   = 312,
        PREVIEW_IMG_HEIGHT  = 520    
    #elif defined(__MMI_MAINLCD_320X480__)    
        PREVIEW_IMG_WIDTH   = 208,
        PREVIEW_IMG_HEIGHT  = 312    
    #elif defined(__MMI_MAINLCD_240X400__)    
        PREVIEW_IMG_WIDTH   = 140,
        PREVIEW_IMG_HEIGHT  = 233    
    #else    
        PREVIEW_IMG_WIDTH   = 140,
        PREVIEW_IMG_HEIGHT  = 187
    #endif      
    };      
};

class VappScreenLockMreProvider : public VfxControl
{
    VFX_DECLARE_CLASS(VappScreenLockMreProvider);

// Constructor / Destructor
public:
    // Default constructor
    VappScreenLockMreProvider();

// callback
public:
    void onUnlock(VappScreenLockMreProvider *provider);
    void onConfigurationCompleted(VappScreenLockMreProvider *provider, VfxBool isSucces);

// Override
protected:
    // Please refer to VfxFrame.
    virtual void onObjectNotify(VfxId id, void *userData);

// Method
public:
    // This function requests the provider to create view
    virtual void createView();

    // This function requests the provider to release view
    virtual void releaseView();

    // This function requests the provider to enter page
    virtual void pageEnter();

    // This function requests the provider to exit page
    virtual void pageExit();    

    // This function notifies the provider backlight is on
    virtual void backlightOn();

    // This function notifies the provider backlight is off
    virtual void backlightOff();

// Override
protected:
    // Provider could override this function to create view
    virtual void onCreateView();

    // Provider could override this function to release view
    virtual void onReleaseView();

    // Provider could override this function to enter page
    virtual void onPageEnter();

    // Provider could override this function to exit page
    virtual void onPageExit();

    // Provider could override this function to handle backlight on
    virtual void onBacklightOn();

    // Provider could override this function to handle backlight off
    virtual void onBacklightOff();

// Method
private:
    // MRE wiget provider.
    VfxWeakPtr<VappScreenLockMre> m_screenLockMre;    
};


/*****************************************************************************
* MRE Screen Lock Delegator
*****************************************************************************/

class VappScreenLockMre : public VappScreenLock
{
    VAPP_SCREEN_LOCK_DECLARE_CLASS(VappScreenLockMre);

// Constructor / Destructor
public:
    // Default constructor
    VappScreenLockMre();

    // Default destructor
    ~VappScreenLockMre();

// Method
public:
    // This function sets the id for this MRE widget.
    void setId(
        const VappScreenLockId &id                  // [IN] MRE widget ID.
    );

    // This function sets the screen lock provider.
    void setMreProvider(
        VappScreenLockMreProvider *widgetProvider   // [IN] Screen lock provider
    );

// Method
public:    
    
    // Please refer to VappScreenLock.
    virtual VappScreenLockId getId() const;

    // Please refer to VappScreenLock.
    virtual VfxS32 getName(
        VfxWChar *string,
        VfxS32 size
    ) const;

    // Please refer to VappScreenLock.
    virtual VfxFrame *createIcon(
        VfxObject *parentObj
    );

    // Please refer to VappScreenLock.
    virtual VfxS32 getScreenshotNum() const;

    // Please refer to VappScreenLock.
    virtual VfxFrame **createScreenshot(
        VfxObject *parent
    )  const;

    void onUnlock();

    void onConfigurationCompleted(VfxBool isSucces);

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();
    
    // Please refer to VappScreenLock.
    virtual void onCreateView();

    // Please refer to VappScreenLock.
    virtual void onReleaseView();

    // Please refer to VappScreenLock.
    virtual void onPageEnter();

    // Please refer to VappScreenLock.
    virtual void onPageExit();    

    // Please refer to VappScreenLock.
    virtual void onBacklightOn();

    // Please refer to VappScreenLock.
    virtual void onBacklightOff();

    // Please refer to VappScreenLock.
    virtual VfxBool getCreateViewFailure(
        VfxWString &errorString     // [OUT] Prompt message for the user
    );

    // Please refer to VappScreenLock.
    virtual VfxBool checkAvailable(
        VfxWString &errorString     // [OUT] Error string.
    );
// Variable
private:
    // MRE screen lock ID.
    VappScreenLockId m_mreId;

    // VSO launcher.
    VpiAppLauncher *m_launcher;
    
    // MRE screen lock provider.
    VfxWeakPtr<VappScreenLockMreProvider> m_screenLockProvider;

    VfxWeakPtr<VappScreenLockMreScreenshot> m_screenShot;
    
    VfxBool m_isSelfClose;

    VfxBool m_isCardPlugOut;
    VfxBool m_isUSBMode;

    VfxS32 m_errStrId;
    // Preload App info.
    vm_preload_app_info_t m_preloadInfo;
    
    // This function is the main event hanndler.
    static mmi_ret eventProc(
        mmi_event_struct *evt   // [IN] Event structure
    );

    void handleInterrupt();
    
    void entryMassStorageMode();

    void entryCardPlugOut();
    
    VfxBool isDriveLetterMatch(
        const VfxU8 *driveLetter,
        VfxU32 count) const;

    VfxBool launchVpi();
    void terminateVpi();    
    static mmi_ret createDefaultScreenLock(mmi_event_struct *evt);
        
    // This function handles the 'destroy' signal of the VPP launcher.
    void onDestroy(
        VfxObject *obj      // [IN] VPP launcher
    );

    // This function handles the interrupt that makes the VPI quit.
    void onQuitByInterrupt(
        VfxObject *obj,                                 // [IN] VPI launcher
        VpiAppLauncher::QuitByInterrupTypeEnum cause    // [IN] Cause
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

#ifdef __MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__

    // ASM memory group ID.
    MMI_ID m_asmGid;

    // memory APIs
    void initMemory();
    
    void deinitMemory();

    void *malloc(VfxS32 size);

    void free(void *mem);    

    // This function handles the ASM events from the framework.
    static mmi_ret onAsmGroupEvent(
       mmi_event_struct *evt   // [IN] Event structure
    );

#endif /* __MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__ */

   
};


/*****************************************************************************
 * MRE Launcher Manager
 *****************************************************************************/

class VappScreenLockMreManager : public VfxObject
{
    VFX_DECLARE_CLASS(VappScreenLockMreManager);

    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappScreenLockMreManager);

// Constructor / Destructor
public:
    // Default Constructor
    VappScreenLockMreManager();

    // Default destructor
    ~VappScreenLockMreManager();

public:

    void add(VappScreenLockMre *lock);
    
    void remove(VappScreenLockMre *lock);
    
    // Initialize the reviver.
    void initReviver(
        const VappScreenLockId mreId   // [IN] screen lock
    );

    // Deinitialize the reviver.
    void deinitReviver();

    // Invoke the reviver to revive the MRE screen lock.
    void invokeReviver();
    
// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

// Variable
private:
    // If the revivier is waiting to revive the MRE launcher.
    VfxBool m_reviverInited;

    // The drive which the launcher is installed.
    VfxU8 m_driveLetter;

    // Launcher ID
    VappScreenLockId m_mreId;

    VfxBool m_firstSkipped;    

    VfxWeakPtr<VappScreenLockMre> m_screenLockMre;
    
    // Handle the screen lock changed signal.
    void onScreenLockChanged();

    // This function is the main event hanndler.
    static mmi_ret eventProc(
        mmi_event_struct *evt   // [IN] Event structure
    );
    
};


#endif /* defined(__MMI_VUI_SCREEN_LOCK_MRE__) */
#endif /* VAPP_SCREEN_LOCK_MRE_H */

