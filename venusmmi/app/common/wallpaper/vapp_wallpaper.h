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
 *  vapp_wallpaper.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen wallpaper base class header file
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

#ifndef __VAPP_WALLPAPER_H__
#define __VAPP_WALLPAPER_H__

#include "MMI_features.h"

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vapp_wallpaper_def.h"
#include "vapp_wallpaper_cfg.h"
extern "C"
{
#include "CustDataRes.h"
#include "app_mem.h"
#include "app_mem_med.h"
#include "med_utility.h"
}

/* RHR start */
#include "vfx_object.h"   
#include "vfx_control.h"  
#include "vfx_class_info.h"	 
#include "vfx_datatype.h"   
#include "vfx_basic_type.h"	
#include "vfx_frame.h"
#include "vfx_input_event.h"
#include "vfx_cpp_base.h"
/* RHR end */

#ifdef __VENUS_3D_UI_ENGINE__
#include "gles2\gl2.h"
#endif // #ifdef __VENUS_3D_UI_ENGINE__

/****************************************************************************
 * Trace
 ****************************************************************************/

#if defined(__MTK_TARGET__)
/*
 * Only target compiler supports C99 __VA_ARGS__.
 */
#define MMI_WPR_LOG_EX(...) MMI_TRACE(MMI_COMMON_TRC_G3_WALLPAPER, __VA_ARGS__)
#define MMI_WPR_LOG(_x)     MMI_WPR_LOG_EX _x
#else
#define MMI_WPR_LOG(_x)
#endif /* defined(__MTK_TARGET__) */

/*****************************************************************************
 * Define
 *****************************************************************************/
#define VAPP_WALLPAPER_ID(_className)        \
            VAPP_WALLPAPER_ENUM_##_className


#define VAPP_WALLPAPER_CREATE(_className)                                   \
    public:                                                                 \
        static inline void *createWallpaper(void *parentObj)                \
        {                                                                   \
            _className *wallpaper;                                          \
            VFX_OBJ_CREATE(wallpaper, _className, (VfxObject *)parentObj);  \
            return wallpaper;                                               \
        }


/*****************************************************************************
 * Home screen UI componet: base wallpaper class
 *****************************************************************************/
class VappWallpaper : public VfxControl
{
    VFX_DECLARE_CLASS(VappWallpaper);

private:
    // State enum
    enum WallpaperStateEnum
    {
        STATE_NULL, // Null state
        STATE_INIT,     // Init state   : do first init
        STATE_ACTIVE    // Create state : do delay init
    };

// Constructor / Destructor
public:
    // Default constructor
    VappWallpaper();

// Method: general operation for Homescreen
public:
    // HS notify wall paper the event which the widget dragged
    void setWidgetDragged(
        VfxPoint pos,                   // pen event position
        VfxControl *targetWidget        // Target widget pointer
    );

    // HS notify wall paper the event which the widget moved
    void setWidgetMoved(
        VfxPoint pos,                   // pen event position
        VfxControl *targetWidget        // Target widget pointer
    );

    // HS notify wall paper the event which the widget dropped
    void setWidgetDropped(
        VfxPoint pos,                   // pen event position
        VfxControl *targetWidget        // Target widget pointer
    );

    // HS notify Wallpaper that the desktop bounds changed
    void setDesktopBoundsChanged(
        const VfxU32 totalPage,
        VfxFrame *source,
        const VfxRect &oldBounds
    );

    // HS notify Wallpaper to scroll.
    // Wallpaper only scrolls in 1-dimension.
    void setDesktopCursorChanged(
        VfxFloat curPos,     // [IN] Current scroll position, ranges from 0.0f ~ 1.0f
        VfxFloat oldPos      // [IN] Previous scroll position, ranges from 0.0f ~ 1.0f
    );

    // set source who create wallpaper
    void setSource(VfxS32 source);

    // tells the wallpaper if it is in "preview" mode or actually working
    void setPreview(VfxBool isPreview);
    
    // create wallpaper
    void createView();

    // release wallpaper
    void releaseView();

    // Serialize the wallpaper view.
    //
    // NOTE: Internal used only.
    void serializeView();

    // Restore the wallpaper view.
    //
    // NOTE: Internal used only.
    void restoreView();

    // HS notify Wallpaper to suspend (used to suspend when quick switch panel )
    void suspend();

    // HS notify Wallpaper to resume
    void resume();

    // HS query wallpaper if allow to suspend when desktop swipe
    VfxBool isAllowSuspendOnSwipe();

    // HS query wallpaper if allow to suspend when receive pen down
    VfxBool isAllowSuspendOnPenDown();

    // returns VFX_TRUE if the wallpaper is being suspended
    VfxBool isSuspended();

    // This function used to get image id of wallpaper thumbnail
    // RETURN resource id of the thumbnail. 0 if there is no build-in thumbnail.
    virtual MMI_IMG_ID getThumbnail();

    // return image source of thumbnail.
    // if the image source is VfxImageBuffer, the memory is
    // provided by the wallpaper object itself.
    virtual VfxBool getThumbnailImageSrc(VfxImageSrc &output);

    // This function used to get image buffer of wallpaper thumbnail
    // RETURN VFX_TRUE if the output is filled with thumbnail
    //        VFX_FALSE if it is not supported or failed to generate thumbnail.
    virtual VfxBool getThumbnailImage(VfxImageBuffer &output);

    // retrieve name of the wallpaper
    virtual void getName(VfxWString &wallpaperName);

    // when enumerating, this function is called to check if 
    // dependent resource (e.g. some external file on memory card)
    // is available. This function very be very fast.
    // return VFX_TRUE means resource is Okay to use.
    virtual VfxBool checkResource();

    // get extra memory for VRT 
    // (unit in Bytes)
    // This is mainly used for Venus 3D, 
    // where wallpaper may require extra OpenGL memory
    virtual VfxU32 getVrtMemFactor();

    // Do pen input
    // callback child class onpenInput
    void doPenInput(VfxPenEvent &event);

    // Get number of total desktop pages
    void setTotalPage(VfxS32 page);

    VfxS32 getTotalPage();
    
    VfxBool getIsPreview() const {return m_isPreview;};

    // allows setting a special app id used for wallpaper to allocate memory.
    void setExternalMemorySource(VfxId appId);

    // 0 By default.
    VfxId getExternalMemorySource() const;

    // restores wallpaper setting.
    // This method does nothing if the wallpaper instance
    // is set to preview mode.
    void restoreWallpaperSetting(VfxId errStr = 0);

    // when error and child class needs temporary wallpaper
    // call this function to setup an image frame
    void showDefaultWallpaperFrame(
                        VfxBool show    // [IN] VFX_TRUE to show default wallpaper, VFX_FALSE to destory it
                        );

protected:
    static VfxSize getScreenSize();

    VfxU32 getTotalDesktopPage();
    
    // return who create wallpaper
    S32 getSource();

// Override
protected:

    // Init wallpaper
    virtual void onInit();

    // Deinit
    virtual void onDeinit();

    // Create wallpaper
    virtual void onCreateView();

    // Release wallpaper
    virtual void onReleaseView();

    // Override this virtual to serialize your view. This virtual is mainly used
    // to save more memory. Generally, it is called when the home screen becomes
    // inactive.
    //
    // SEE ALSO: onRestoreView
    virtual void onSerializeView();

    // Override this virtual to restore your view.
    //
    // SEE ALSO: onSerializeView
    virtual void onRestoreView();

    // Suspend wallpaper (used to suspend when quick switch panel )
    virtual void onSuspend();

    // Resume wallpaper
    virtual void onResume();

    // Is allow suspend wallpaper when desktop swipe
    virtual VfxBool onAllowSuspendOnSwipe();

    // Is allow suspend wallpaper when receive pen down
    virtual VfxBool onAllowSuspendOnPenDown();

    // On pen input
    // RETURNS: VfxBool
    virtual VfxBool onPenInput(VfxPenEvent &event);

    // This function rotates the wallpaper and highlights the corresponding
    // navigation dot when the desktop changes its bounds.
    virtual void onDesktopBoundsChanged(
        const VfxU32 totalPage,
        VfxFrame *source,
        const VfxRect &oldBounds
    );

    // Wallpaper can motion when the widget dragged
    virtual void onWidgetDragged(
        VfxPoint pos,               // Wallpaper position
        VfxControl *targetWidget    // Target widget pointer
    );

    // Wallpaper can motion when the widget move
    virtual void onWidgetMoved(
        VfxPoint pos,
        VfxControl *targetWidget
    );

    // Wallpaper can motion when the widget dropped
    virtual void onWidgetDropped(
        VfxPoint pos,
        VfxControl *targetWidget
    );

    // This function rotates the wallpaper and highlights the corresponding
    // navigation dot when the desktop changes its bounds.
    virtual void onDesktopCursorChanged(
        VfxFloat curPos,
        VfxFloat oldPos
    );

    // Register common events like USB, Device In/Out, screen lock.
    void registerEvents(VfxBool isReg);
    static mmi_ret onEvent(mmi_event_struct *param);
    // Override to handle event
    virtual mmi_ret handleEvent(mmi_event_struct *param);
    
// Slot
private:
    void backlightSwitchHdlr(
        VfxBool on          // [IN] backlight on or off
    );

    void onShelterExist(VfxBool isExist);

//Variable
private:
    // If the wallpaper's view is created or not.
    VfxBool     m_isCreated;

    // If the widget's view is serialized or not.
    VfxBool     m_isSerialized;

       // who create wallpaper
    VfxS32      m_source;
    
    VfxU32   m_suspendCount;

    // The number of children objects (used to check memory leak between
    // create and release the view).
    VfxS32      m_numOfChild;

    
    // Is this wallpaper created for preview purpose
    VfxBool     m_isPreview; 

    // fallback default wallpaper frame
    VfxFrame *m_fallbackImgFrame;
    
// Variable
protected:
    // State
    WallpaperStateEnum m_state;

private:
    // Number of desktop pages
    // Live wallpaper can do some effect based on this info
    VfxS32          m_totalDesktopPage;
    VfxId           m_extAppId;

public:
    static mmi_id findRootAppGroupId(VfxFrame *obj);
#ifdef __VENUS_3D_UI_ENGINE__
    static GLuint loadResourceTexture(const U16 resId);
#endif
};
#endif

