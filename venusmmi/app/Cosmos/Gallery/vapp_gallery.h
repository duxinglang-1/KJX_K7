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
 *  vapp_gallery_app.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Gallery APP, screen and CUI classes
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/

#ifndef __VAPP_GALLERY_APP_H__
#define __VAPP_GALLERY_APP_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_gallery_gprot.h"
#include "vcui_gallery_gprot.h"
#include "vapp_image_viewer_cp.h"
extern "C"
{
#include "FileMgrSrvGProt.h"
}

/*****************************************************************************
 * Gallery Feature Option Define
 *****************************************************************************/
#if defined(__LOW_COST_SUPPORT_COMMON__)
    /*** low cost support feature set ***/
    // note multimedia app dose not support phone drive in SLIM project
    #undef __VAPP_GALLERY_ENABLE_USER_DRIVE__
    #define __VAPP_GALLERY_ENABLE_FS_RELOAD__
#else
    /*** advanced feature set ***/
    #ifndef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
	#define __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
	#endif
    #define __VAPP_GALLERY_ENABLE_IMAGE_INFO_PAGE__
    #define __VAPP_GALLERY_ENABLE_LAST_PLAY_INFO__
    #define __VAPP_GALLERY_ENABLE_VIDEO_BOOKMARK__
    #define __VAPP_GALLERY_ENABLE_MY_RECEIVED_FOLDER__
    #define __VAPP_GALLERY_ENABLE_IMAGE_COLLECTION_WAITING_ICON__
    #define __VAPP_GALLERY_ENABLE_CAMERA__
    #ifdef __COSMOS_NO_USER_DRIVE__
    #undef __VAPP_GALLERY_ENABLE_USER_DRIVE__
    #else
    #define __VAPP_GALLERY_ENABLE_USER_DRIVE__
    #endif
#endif

/*
Streaming, turn on setting since 11BW1220 for SLIM project
*/
#if defined(STREAM_SUPPORT)
    #define __VAPP_GALLERY_ENABLE_STREAMING__
    #define __VAPP_GALLERY_ENABLE_STREAMING_SETTING_PAGE__
#endif
#if defined(__VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__)
    #define __VAPP_GALLERY_ENABLE_SLIDESHOW_SETTING_PAGE__
#endif
#if defined(__VAPP_GALLERY_ENABLE_STREAMING_SETTING_PAGE__) || defined(__VAPP_GALLERY_ENABLE_SLIDESHOW_SETTING_PAGE__)
    #define __VAPP_GALLERY_ENABLE_SETTING_PAGE__
#endif


/*
UE features, turn off defaultly since 11BW1220
*/
// always show "My Picture" button no matter whether folder content is empty
//#define __VAPP_GALLERY_ENABLE_PICTURE_PAGE_ALWAYS_SHOW_IMAGE_BUTTON__
// treat "My Received" folder as the first entry folder
//#define __VAPP_GALLERY_ENABLE_MY_RECEIVED_AS_THE_FIRST_FOLDER__
// always show delete count
#define __VAPP_GALLERY_ENABLE_ALWAYS_SHOW_DELETE_COUNT__

/*
Capacity
*/
#define VAPP_GALLERY_FS_MAX_FILE_COUNT 20000

/*****************************************************************************
 * Global Variable & Define
 *****************************************************************************/
#define VAPP_GALLERY_URL_MAX_BUF_LENGTH 521      // This comes from MEDPLY_URL_MAX_LENGTH

typedef enum
{
    EVT_ID_VAPP_GALLERY_DA_USER_CANCEL = GET_RESOURCE_BASE(VAPP_GALLERY) + 1, 
    EVT_ID_VAPP_GALLERY_DA_PAUSE,
    EVT_ID_VAPP_GALLERY_DA_RESUME,
    MMI_VAPP_GALLERY_EVENT_END_OF_ENUM
} vapp_gallery_event_enum;

/*****************************************************************************
 * IGlobal Variable & Define
 *****************************************************************************/
#define VAPP_GALLERY_INTERNAL_UNUSED_PARAM (-999)

/***************************************************************************** 
 * Class forward declaration
 *****************************************************************************/
class IVappGalleryMediaList;
class SimpleBitSet;

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappGalleryApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappGalleryApp);

// Override
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onRun(void* args, VfxU32 argSize);
    virtual mmi_ret onProc(mmi_event_struct *evt);

    virtual mmi_ret handleDevicePlugOut(srv_fmgr_notification_dev_plug_event_struct* evt);    
public:
    static mmi_ret onUSBEnterMS(mmi_event_struct *param);
    static mmi_ret onDevicePlugIn(mmi_event_struct *param);
    static mmi_ret onDevicePlugOut(mmi_event_struct *param);

public:
    static kal_uint8 getCBMAppId();
    static VfxBool isMatchingStorage(const srv_fmgr_notification_dev_plug_event_struct &evt, U8 drv);
    VfxS32 getPDLSessionId();
    
protected:
    U8 queryActiveDrive();

private:
    U8 m_overrideCurrentDrive;
    VfxBool m_noDriveUsed;
    
#ifdef __MMI_VIDEO_PDL__
    VfxS32 m_pdlSessionId;  // if > 0, this app is launched from an PDL session
#endif
};

class VappGalleryScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappGalleryScreen);

public:
    VappGalleryScreen();

// Override
protected:
    // override to display proper page
    virtual void on1stReady();

    // override to enter/exit screen
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);

    // override to check last-page exit
    virtual VfxBool onPageBack(VfxPage* page);

    // override onkey
    virtual VfxBool onKeyInput(
        VfxKeyEvent &event
    );

// Method
public:
    // change the first page shown on the screen.
    // It is Index Page by default.
    void setFirstPage(VfxPage *firstPage);

    // retrieve setted first page
    VfxPage *getFirstPage();

    // set SSE disabled option
    // It sould be set before entry Gallery screen
    void setIsSSEDisabled(const VfxBool disabled);

    // this signal is emitted when the last page is being popped.
    // this allows Vapp/Vcui to know that it maybe going to terminate.
    VfxSignal0 m_signalLastPagePopped;
private:
    VfxPage *m_firstPage;
    VfxBool m_isSSEDisabled;
};

// Base class of Gallery CUI pages.
// These pages may assign custom title bar caption,
// and may show an default string when content is empty.
class VappGalleryPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappGalleryPage);    
public:
    VappGalleryPage();
    virtual void onInit();
// Method
public:
    // allow overriding page title bar's caption
    virtual void setCustomTitle(const VfxWString &title);
    
    // check if a custom title is assigned
    VfxBool hasCustomTitle()const;

    // change custom title. If there is already a title, change it.
    void getCustomTitle(VfxWString &title)const;

    // change the custom message in page center
    void setPageMessage(const VfxWString &message);

    // if isShow is VFX_TRUE, show message in page center.
    void showPageMessage(VfxBool isShow, VfxBool whiteText = VFX_FALSE);

    // show waiting icon
    void showPageWaitIcon(VfxBool isShow);

// overridable
public:
    // if VFX_FALSE is returned, means no "current storage" defined for this page.
    virtual VfxBool getPageCurrentStorage(U8 &drvLetter);

// Common operations for pages
protected:
    
    // modify the icon and string of 'SALL' button
    // to be "Select all" or "Unselect all"
    void setSelectUnselectButton(VfxBool selectAll);

    // disables the current "multi-file" operation button.
    void disableMultiCommandButton(VfxBool isDisabled);
    // retrieve button name and image from id
    void getButtonNameImageById(VfxId id, VfxWString &name, MMI_IMG_ID &imgId);

protected:
    enum
    {
#if defined(__MMI_MAINLCD_320X480__)
        PAGE_MESSAGE_FONT_SIZE = 20,
#elif defined(__MMI_MAINLCD_480X800__)
        PAGE_MESSAGE_FONT_SIZE = 30,
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
        PAGE_MESSAGE_FONT_SIZE = 16,
#else
        PAGE_MESSAGE_FONT_SIZE = 16,
#endif
    };
protected:
    VfxWString m_customTitle;
    VfxWString m_pageMessage;
    VfxTextFrame *m_messageFrame;    // lazy-initialized text, used to display note like "No Photos" in page center.
    VcpActivityIndicator *m_waitIcon;  // lazy-init wait icon   
};

class VcuiGalleryBase : public VfxCui
{
    VFX_DECLARE_CLASS(VcuiGalleryBase);
// ctor
public:
    VcuiGalleryBase();

// Override
public:
    virtual void onRun(void *arg, VfxU32 argSize);
    virtual void onInit();
    virtual void onDeinit();

// method
public:
    // Set the title caption of the CUI
    // Derived child may override this.
    virtual void setTitleCatpion(const VfxWString &caption);

    // retrieve the title caption set by CUI client.
    // VFX_FALSE is returned if CUI client did not set any
    // custom title caption.
    virtual VfxBool getTitleCaption(VfxWString &caption);

    // workaround for "quickly press back twice to exit CUI" bug.
    // this causes VfxPage's onExited()/onEntered() sequence to reverse.
    VfxBool isDestroying();

// Overridable
protected:
    // Create first page of the CUI.
    // Derived child MUST override this method.
    virtual VfxPage* createFirstPage(VfxAppScr *screen);

    // assign custom title to a page object
    virtual void setPageCustomTitle(VfxPage *page);

    // intercept last page, to notify CUI client
    // that we should be close
    void onLastPagePopped();

    // handles device plug out
    virtual mmi_ret handleDevicePlugOut(srv_fmgr_notification_dev_plug_event_struct* evt);
    // VcuiGalleryBase use this function to help leave APP when device plugged out
    virtual U8 onQueryActiveDrive();

    // VcuiGalleryBase use this function to help leave APP when device plugged out,
    // and the file is no longer available.
    virtual VfxBool onQueryActiveFile(VfxWString &activePath);

    virtual mmi_ret handleUSBEnterMS(mmi_event_struct *param);

protected:
    VfxWString m_customTitleCaption;
    VappGalleryScreen *m_cuiScreen;
    VfxBool m_isDestroying;
    
public:
    static mmi_ret onDevicePlugOut(mmi_event_struct *param);
    static mmi_ret onDevicePlugIn(mmi_event_struct *param);
    static mmi_ret onUSBEnterMS(mmi_event_struct *param);
};

class VcuiGalleryImageViewer : public VcuiGalleryBase
{
    VFX_DECLARE_CLASS(VcuiGalleryImageViewer);

// Override
public:
    virtual void onRun(void *arg, VfxU32 argSize);

protected:
    virtual VfxPage* createFirstPage(VfxAppScr *screen);
    virtual U8 onQueryActiveDrive();
    virtual VfxBool onQueryActiveFile(VfxWString &activePath);
private:
    VfxWString m_inputPath;
};

class VcuiGalleryVideoPlayer : public VcuiGalleryBase
{
    VFX_DECLARE_CLASS(VcuiGalleryVideoPlayer);

// Override
public:
    virtual void onRun(void *arg, VfxU32 argSize);

protected:
    virtual VfxPage* createFirstPage(VfxAppScr *screen);
    virtual U8 onQueryActiveDrive();
    virtual VfxBool onQueryActiveFile(VfxWString &activePath);
private:
    VfxWString m_inputPath;
};

class VcuiGalleryPickerLaunchParam
{
public:
    VcuiGalleryPickerLaunchParam();
public:
    VfxBool m_multiSelect;            // VFX_TRUE if we're multi-select
    FMGR_FILTER m_customFileFilter;   // filter provided by CUI client
};

class VcuiGalleryPickerBase : public VcuiGalleryBase
{
    VFX_DECLARE_CLASS(VcuiGalleryPickerBase);

public:
    VcuiGalleryPickerBase();
    
// Override
public:
    virtual void onRun(void *arg, VfxU32 argSize);

// method for CUI client
public:
    // return user-picked file count
    VfxS32 getPickCount();

    // index should range from 0 ~ (getPickCount() - 1)
    vcui_gallery_media_state_enum getPickedPath(VfxS32 index, VfxWString &filePath);

    const FMGR_FILTER *getTypeFilter();

    void setAutoClose(VfxBool isAutoClose);

    VfxBool getAutoClose();

// method for implementation, for derived class or child CP
public:
    // Derived class and child CP can call this method
    // to check if we're multi-select or single-select
    VfxBool isMultiSelectMode();

    // Derived classes call this method to notify CUI client
    // pick operation is done.
    // CUI client may then query selected paths.
    void notifyPickOperationDone(
                vcui_gallery_result_enum type,       // result, OK or CANCEL
                IVappGalleryMediaList *mediaList,    // pointer to resulting mediaList
                SimpleBitSet *selectedSet,           // pointer to bitset of selected files in mediaList
                vcui_gallery_media_state_enum mediaState = VCUI_GALLERY_MEDIA_STATE_UNKNOWN // Single media case, save the media state when tapped
                );
    
protected:
    VcuiGalleryPickerLaunchParam m_launchParam;
    VfxWeakPtr<IVappGalleryMediaList> m_mediaList;
    SimpleBitSet *m_selectedSet;
    vcui_gallery_media_state_enum m_singleMediaState;   // media state (decoded or not) for single pick case
    VfxBool m_isAutoClose;

    VfxWString m_pickedFilePath;
};

class VcuiGalleryImagePicker : public VcuiGalleryPickerBase
{
    VFX_DECLARE_CLASS(VcuiGalleryImagePicker);
protected:
    virtual VfxPage* createFirstPage(VfxAppScr *screen);
};

class VcuiGalleryVideoPicker : public VcuiGalleryPickerBase
{
    VFX_DECLARE_CLASS(VcuiGalleryVideoPicker);
protected:
    virtual VfxPage* createFirstPage(VfxAppScr *screen);    
};

class VcuiGalleryWallpaperPicker : public VcuiGalleryBase
{
    VFX_DECLARE_CLASS(VcuiGalleryWallpaperPicker);
// Types
public:
    enum ResultType
    {
        WALLPAPER_PICK_OK,
        WALLPAPER_PICK_Cancel
    };

    class Result
    {
    public:
        ResultType type;
        VcpMenuPos pickPos;
    };

// Constructor / Destructor
public:
    VcuiGalleryWallpaperPicker();
    
// Override
public:
    // create wallpaper thumb grid as first page
    virtual VfxPage* createFirstPage(VfxAppScr *screen);

    // for wallpaper picker, we want to ignore USB mode,
    // since we only pick system build in resources
    virtual mmi_ret handleUSBEnterMS(mmi_event_struct *param);

// Method
public:
    void setWallpaperSource(IWallpaperSourceStruct *sourceInfo);

    // called by client
    void getPickedWallpaper(VappWpResType &wallpaperType, U32 &selectedIndex);

    // called by child component (e.g. thumbnail list)
    void finishPickOperation(ResultType type, VcpMenuPos pickedPos);

protected:
    virtual mmi_ret handleDevicePlugOut(srv_fmgr_notification_dev_plug_event_struct* evt);
    
// Implementation
private:
    IWallpaperSourceStruct m_sourceInfo;
    Result m_pickResult;
    VfxPage *m_firstPage;
};


#endif /* __VAPP_GALLERY_APP_H__ */

