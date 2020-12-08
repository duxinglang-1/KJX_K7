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
 *  vapp_gallery_viewer.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/

#ifndef __VAPP_IMAGE_VIEWER_CP_H__
#define __VAPP_IMAGE_VIEWER_CP_H__


/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_page_panel.h"
#include "vapp_gallery_gprot.h"
#include "vapp_media_list.h"
#include "vapp_mav_motion_translator.h"

extern "C"
{
#include "fs_errcode.h"
#include "fs_type.h"
#include "fs_func.h"
#include "drm_errcode.h"
}

/*****************************************************************************
 * ImageViewCP Feature Option Define
 *****************************************************************************/
#if defined(__MMI_COSMOS_GALLERY_SLIM_PROFILE_5M__)
    // feature set in low cost support with ASM 5M project
#define __VAPP_IMAGE_VIEWER_CP_ENABLE_DECODE_FULL_ENHANCE_IMG__
#define __VAPP_IMAGE_VIEWER_CP_ENABLE_RESERVE_ADJACENT_PREVIEW_IMG__    
#elif defined(__LOW_COST_SUPPORT_COMMON__)
    // low cost support feature speficific config
#else
    // advanced feature set
#define __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
#define __VAPP_IMAGE_VIEWER_CP_ENABLE_VIDEO_THUMBAIL__
#define __VAPP_IMAGE_VIEWER_CP_ENABLE_DECODE_FULL_ENHANCE_IMG__
#define __VAPP_IMAGE_VIEWER_CP_ENABLE_RESERVE_ADJACENT_PREVIEW_IMG__
#endif

// enhance image decode feature option
// viewerCP supports full or partial enhnace decode, both are async image decode in MMI task
#if !defined(__VAPP_IMAGE_VIEWER_CP_ENABLE_DECODE_FULL_ENHANCE_IMG__)
#define __VAPP_IMAGE_VIEWER_CP_ENABLE_PARTIAL_ENHANCE_DECODE__
#endif

// MAV image support
#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
    // UI type
    #if defined(__VAPP_MAV_MOTION_TRANSLATOR_SUPPORT__)
    #undef __VAPP_GALLERY_MAV_VIEW_CONTROL__
    #else
    #define __VAPP_GALLERY_MAV_VIEW_CONTROL__
    #endif
#endif

// 3D red blue image support
#if defined(__3D_IMAGE_SUPPORT__) && defined(EXIF_SUPPORT)
#define __VAPP_IMAGE_VIEWER_CP_3D_RED_BLUE_SUPPORT__
#endif

/*****************************************************************************
 * Struct
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    WCHAR file_path[260]; // the number is reference to FMGR_MAX_PATH_LEN
    int serial_num;
} mmi_gallery_image_viewer_file_path_req_struct;

/*****************************************************************************
 * Typedef
 *****************************************************************************/
typedef VfxS32 MediaIndex;
typedef VfxS32 panelID;
const static MediaIndex INVALID_MEDIA_INDEX = -1;
class VappGalleryImageDrawer;
class VappVideoPlayerComponent;
class VappGalleryGestureTranslator;
class VappGalleryInertiaPan;
class IVappGalleryMediaListAsyncProvider;
#ifdef __MMI_GALLERY_SLIM__
class VappGalleryMediaListCommon;
#else
class VappGalleryMediaListMediaCache;
#endif
class VappGalleryImageThumbnail;
class SimpleBitSet;
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
class VappGallerySlideShowSetting;
#endif
class IVappGalleryMediaList;
class VappGalleryMediaListAsync;
class VappGalleryDecoderBase;
class VappGalleryCachedImage;

/*****************************************************************************
 * Class
 *****************************************************************************/
enum VappGalleryGesture
{
    VG_NONE,        // no gesture or not recognized
    VG_TAP,         // user taps
    VG_DOUBLE_TAP,  // user double taps
    VG_DRAG,        // user drags around
    VG_DRAG_END,    // continue sliding after user drag endes
    VG_GO_PREV,     // user fast swipe to go previous
    VG_GO_NEXT,     // user fast swipe to go next
};

enum ViewIconType
{
    VIT_DEFAULT,    // show this during decoding
    VIT_ERROR,      // show this when encounter decoding error
    VIT_DRM,        // show this for DRM files
};

enum DrawHint
{
    DH_NONE,
    DH_RECOMMAND_LT,
};

// Display transformed image
class VappGalleryPreviewImage : public VfxAnimImageFrame
{
public:
    VappGalleryPreviewImage();
    virtual void onInit();
    virtual void onDeinit();
};

#ifdef __MMI_GALLERY_SLIM__
class VappGalleryViewerPanel : public VfxFrame
{
public:
    enum PreviewRotation
    {
        ROTATE_0,
        ROTATE_90,
        ROTATE_180,
        ROTATE_270,

        ROTATE_ENUM_COUNT,
    };

    enum PanningHint
    {
        MOVE,       // ordinary finger-move
        INERTIA,    // finger release, move with inertia
        STOP,       // finger pressed, stop move immediately.
    };

    // partial enhance decode support
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_PARTIAL_ENHANCE_DECODE__
    // decoded target size, clip rect(x, y ,original_img_size_w, original_img_size_h)
    VfxSignal2<VfxSize, VfxRect> m_signalStartDecodeL1EnhanceBuf;
#endif

public:
    VappGalleryViewerPanel();
// override
public:
    virtual void onInit();
    virtual void onDeinit();

// methods
public:
    void clear();
    VfxBool hasMediaIndex() const;
    void setMediaIndex(MediaIndex idx, VfxBool isVideo = VFX_FALSE);
    MediaIndex getMediaIndex() const;

    VfxBool isLoading();
    void setIsLoading();
    void setIcon(ViewIconType icon);

    // set the preview image. This preview image
    // comes from MediaList, so it should be properly locked & unlocked.
    void setPreviewCachedBuffer(
        const VfxImageBuffer &imgBuf,
        VfxS32 maxZoomDim,
        const VfxSize *originalImageSize = NULL,
        const VfxWString &path = VFX_WSTR_EMPTY,
        VfxRect clipWindow = VfxRect(0, 0, 0,0));

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    // set the enhanced image. This is not from MediaList,
    // requires ViewerPage to properly switch it
    void setEnhancedBuffer(const VfxImageBuffer &imgBuf);
    // is this panel display enhanced buffer?
    VfxBool hasEnhancedBuffer();
    // stop display the enhanced buffer and use cached preview if any.
    void clearEnhnacedBuffer();
#endif

    void setupOwnerDraw();
    void teardownOwnerDraw();

    void setPreviewImageAnimated(VfxBool isAnim);
    VfxBool isPreviewImageAnimated();
    VfxBool isDisplayImage();
    VfxBool isOwnerDraw();
    VfxBool setOwnerDrawHint(DrawHint hint);
    VfxBool setOwnerDrawBufferHint(VfxBool forceUsePreviewBuf);

    // VFX_TRUE if the current display content is cached (via setPreviewCachedBuffer)
    VfxBool hasCachedBuffer()const;

    // only valid when hasCachedBuffer() is VFX_TRUE
    // buf will be filled with info of preview buffer.
    VfxBool getPreviewCachedBuffer(VfxImageBuffer &buf);

    // set the preview image. This preview image
    // is a general VfxImageSrc, and not related to
    // media cache.
    void setPreviewImage(const VfxImageSrc &imgSrc, VfxBool drmCheck = VFX_FALSE);

    VfxBool getPreviewImage(VfxImageSrc &imgSrc);

    void resetViewState(VfxBool resetSize = VFX_TRUE);

    // query if this panel is showing the video "play" button
    VfxBool hasPlayButton();

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    // query valid zoom level range.
    // note that zoom level is based on Preview Buffer size, not actual image size nor view panel size.
    void getZoomRange(VfxFloat &zoomMin, VfxFloat &zoomMax);

    // is the view panel in zoom-in state?
    VfxBool isZoomed();

    // must zoomMin <= zoomLevel <= zoomMax
    void getZoom(VfxFloat &zoomLevel);

    // get current zoom level
    void setZoom(VfxFloat zoomLevel);

    // get the zoom level that'll fit the viewer panel size
    void getMinZoom(VfxFloat &zoomLevel);

    void getMaxZoom(VfxFloat &zoomLevel);

    // get the default zoom level when the image is double-tapped
    void getDoubleTapZoom(VfxFloat &zoomLevel);
#endif

    // handle file type
    void setIsVideo(const VfxBool isVideo);
    void setImageType(const VfxU16 imageType);
    void setImageOriginalDimension(const VfxSize s);
    void setIsAnimedGif(const VfxBool isAnim);
    void setIs3DRedBlueImage(const VfxBool is3DRedBlue);

    VfxU16 getImageType() const;
    VfxBool getIsVideo() const;
    VfxBool getIsAnimedGif() const;
    VfxBool getIs3DRedBlueImage() const;
    VfxSize getImageOriginalDimension() const;

    // MAV(Multi-Angle View) support
    void setFrameIndex(VfxS32 frameIndex);
    VfxS32 getFrameIndex();
    VfxS32 getMaxFrameIndex();
    VfxS32 getMinFrameIndex();
    void setFrameCount(VfxS32 frameCount){m_frameCount = frameCount;};
    VfxS32 getFrameCount(){return m_frameCount;}
    VfxBool getIsMAV();

    // the margin from possible anchor point to image boundary
    VfxFPoint getMaxAnchorMargin() const;
    void clampAnchorPointWithinMargin(VfxFPoint &anchorPoint) const;
    // pan the image and get unused offset (when hit boundary) in X direction
    void offsetView(VfxS32 offsetX,         // [IN] pan offset X, in pixels
                    VfxS32 offsetY,         // [IN] pan offset Y, in pixels
                    PanningHint hint,       // [IN] hint of movement
                    VfxS32 &remainOffsetX   // [OUT] remaining offset after hitting boundary
                    );

    // rotate to designated orientation
    void setRotate(PreviewRotation r, VfxBool isAnim = VFX_TRUE);

    // get current rotation orientation
    PreviewRotation getRotate();

    // rotate the preview image clockwise 90 degree
    void rotateCW(VfxBool isAnim = VFX_TRUE);

// signal
public:
    // signal to play a video
    VfxSignal1<MediaIndex> m_signalPlayCommand;

protected:
    void calculateBaseSizeFromSourceImage(VfxSize &rect);

    // calculate current on-screen preview size, after zoom & rotate.
    VfxSize getCurrentPreviewSize() const;

    void onBoundsChange(VfxFrame *frm, const VfxRect &rect);

    void onPlayBtnClicked(VfxObject *sender, VfxId btnId);

    VfxBool checkImageDRMRights(const VfxImageSrc src);

// data member
protected:
    // file type info
    VfxBool m_isVideo;
    VfxU16 m_imageFileType;     // GDI image type
    VfxSize m_imageOriginalDimension;
    VfxBool m_isAnimedGif;
    VfxBool m_is3DRedBlue;
    VfxRect m_frameClipWindow;
    VfxS32 m_frameCount;        // total frame count

    VfxBool m_isLoading;        // VFX_TRUE if the waiting icon is being displayed (decoding content)
    MediaIndex m_mediaIndex;    // the index into a medialist.
    VappGalleryPreviewImage *m_previewImg;     // displays preview image
    VcpActivityIndicator *m_waitIcon;   // wait spin icon
    VfxImageFrame *m_errIcon;   // icon for DRM/Error/Unsupported files
    VcpImageButton *m_playBtn;  // click to video playback. Only available for video.
    
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    VfxS32 m_maxZoomDim;        // image maxmum zoomed size. may be different for different image types.
#endif

    VfxSize m_sizeOriginal;     // image "original" size
    VfxSize m_baseSize;         // size of the preview area, fitting into viewing panel
    PreviewRotation m_currentRotation; // keep tracking of current preview rotation. this is NOT screen orientation.
    VfxImageBuffer m_cachedBuffer;      // this is the "locked" preview (LCD size) buffer

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    VfxImageBuffer m_enhancedBuffer;    // this is the enhanced buffer (not locked but assigned)
#endif

    VappGalleryImageDrawer *m_draw;     // drawing function for  drawing enhanced image with GDI 2D transform

private:
#ifdef __VENUS_3D_UI_ENGINE__
    void setupZoomFrames();
    void teardownZoomFrames();
    VfxFrame *m_enhancedImg;
#endif

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__

// partial enhnace decode support
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_PARTIAL_ENHANCE_DECODE__
private:
    void onStartPartialEnhanceDecode(VfxSize decodedLayerSize, VfxRect clipRect);
public:
    void onCancelPartialEnhanceDecode();
    void onFinishPartialEnhanceDecode(const VfxRect clipRectCheckSum);
    VfxBool updateEnhanceBufToDraw(const VfxRect clipRectCheckSum);
#endif
#endif

public:
    void startAnimTimer(const VfxBool disabledAnimTimer, const VfxMsec duration, const VfxU32 line);
    void stopAnimTimer();
    void closeAnimTimer();
    void onAnimTimeout(VfxTimer *timer);
private:
    VfxTimer* m_animTimer;
};

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
class VappGalleryEnhancedImage : public VfxObject
{
public:
    static const VfxS32 LCD_BUF_SIZE = GDI_LCD_WIDTH * GDI_LCD_HEIGHT * VAPP_GALLERY_IMG_VIEWER_BPP;
    // define temp buffer size for decoded enhnace image
    // in full enhance decode case, buffer szie is same  as the 9x or 4x LCD
    // otherwise, the buffer length is same as LCD buf (partial enhance image decode case)
    #ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_DECODE_FULL_ENHANCE_IMG__
    static const VfxS32 IMAGE_BUF_SIZE = LCD_BUF_SIZE * VAPP_GALLERY_IMG_VIEWER_ENHANCE_BUFFER_RATIO;
    #else
    static const VfxS32 IMAGE_BUF_SIZE = GDI_LCD_WIDTH * GDI_LCD_HEIGHT * VAPP_GALLERY_IMG_VIEWER_BPP;
    #endif

    static VfxS32 getMaxImageFrameSize();
    static VfxS32 getMaxEnhanceDimensionByPath(const VfxWString &path, VfxU16 fileTypeHint = GDI_IMAGE_TYPE_INVALID);
    static VfxS32 getMaxEnhanceDimensionByType(VfxU16 gdiImageType);

public:
    VappGalleryEnhancedImage();
    virtual void onInit();
    virtual void onDeinit();

    VfxBool reset();
    void finishDecode();
    VfxBool isReadyToDecode(MediaIndex index);
    VfxBool isDecoding(MediaIndex index);

    // in partial enhance decode scenario, the decoded size is according to watch frame size, anchor and pos
    // so decoderd size is not same as the size queried from getEnhancedImageSize
    VfxBool setFileAndGetOutputBuffer(MediaIndex mediaIdx, const VfxWString &path, VfxImageBuffer &outputBuf, VfxSize bufferSizeHint = VfxSize(0, 0));
    VfxBool getOutputBuffer(VfxImageBuffer &outputBuf);

public:
    // VFX_FALSE is returned if this image needs no enhance
    // query size of enhnace image in full decoded scenario
    VfxBool getEnhancedImageSize(
        const VfxWString &path, VfxSize &size,
        VfxU16 fileTypeHint = GDI_IMAGE_TYPE_INVALID,
        VfxSize originalDim = VfxSize(0, 0));

protected:
    VfxBool m_isDecoding;
    MediaIndex m_mediaIndex;
    VfxWString m_mediaPath;

    void *m_rawBuf;
    VfxS32 m_bufLength;
    VfxImageBuffer m_imgBuf;
};
#endif

class VappGalleryViewerMediaState
{
public:
    VappGalleryViewerMediaState();
	#ifdef __MMI_GALLERY_SLIM__
	VappGalleryMediaListCommon* createMediaList(VfxObject *parent);
	#else
    VappGalleryMediaListMediaCache* createMediaList(VfxObject *parent);
	#endif
    VfxBool isSingleFile();
public:
    VfxBool m_refreshed;      // VFX_TRUE if this initial state has constructed file list.
    VfxBool m_displayed;      // VFX_TRUE if this initial state is already displayed
    VfxBool m_useIndexInList; // if VFX_TRUE, use focusIndex instead of focusFile
    VfxBool m_imageOnly;      // if VFX_TRUE, only enumerate images. Otherwise also enumerate videos
    VfxBool m_videoOnly;      // if VFX_TRUE, only enumerate videos. Otherwise also enumerate images    
    VfxBool m_autoPlaySlideshow; // if VFX_TRUE, slideshow are started after media list is ready.
    VfxBool m_allowEmptyPage;    // if VFX_TRUE, do not exit() page when there is no image available.
    VfxBool m_confirmScenario;       // if VFX_TRUE, show ok and delete. While user pressed button, exist image viewer.
    VappGalleryDecodeResult m_singleFileCheckResult;  // Stores checked result of single file case. only valid when isSingleFile() is VFX_TRUE.
    VfxS32 m_focusIndex;
    VfxS32 m_sortMethod; // refer to fs_gprot.h
    VfxWString m_focusFile;
    VfxWString m_folderPath;  // the folder to scan
    VfxImageSrc m_singleFileSrc;    // for single media mode records media source
    VfxBool m_isSyncContentProvider;
    VfxBool m_hasCustomFilter;
    FMGR_FILTER m_fileFilter;
    VfxS32 m_cacheCount;
    VfxBool m_disableSwitchBalloon;
};

#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
class VappGallerySlideshowBase : public VfxFrame
{
public:
    virtual void onInit();
    virtual void onDeinit();

    virtual void getOrientationLimit(VfxBool &hasLimit, VfxScrRotateTypeEnum &orientation) = 0;

    virtual void playOpening() = 0;
    virtual void playEnding() = 0;

    virtual void setNextMedia(VfxFrame *frame) = 0;
    virtual void playMedia() = 0;

    virtual VfxBool handleGesture(VappGalleryGestureTranslator *sender, VappGalleryGesture gesture) {return VFX_FALSE;};
    virtual VfxBool canPlayMedia() {return VFX_TRUE;};
public:
    enum FinishType
    {
        FT_OPENING,
        FT_ENDING,
        FT_MEDIA,
    };

    // notify APP when an animation is finished. the frame which is switched to
    // will be passed as parameter. The effect is complete or not is also passed.
    VfxSignal3 <
        VfxFrame *,             // target media frame, may be NULL
        FinishType,             // animation type
        VfxBool                 // is completed
        > m_signalFinished;
};

class VappGalleryTransitionSlideshow : public VappGallerySlideshowBase
{
public:
    VappGalleryTransitionSlideshow();
    virtual void onInit();
    virtual void onDeinit();

    virtual void getOrientationLimit(VfxBool &hasLimit, VfxScrRotateTypeEnum &orientation);

    virtual void playOpening();
    virtual void playEnding();

    virtual void setNextMedia(VfxFrame *frame);
    virtual void playMedia();

public:
    void configEffectType(VcpPageEffectType effectType);

protected:
    void onPageEffectFinish(VfxFrame *target, VfxBool isCompleted);

protected:
    VfxFrame *m_currentMedia;
    VfxFrame *m_nextMedia;
    VcpPagePanel *m_pagePanel;
    VcpPageEffectType m_effectType;
};

class VappGalleryShuffleIndex : public VfxObject
{
public:
    VappGalleryShuffleIndex(VfxU16 mediaCount);
    virtual void onInit();
    virtual void onDeinit();

public:
    // get shuffled index by original index
    MediaIndex getShuffledIndex(MediaIndex originalIndex);

    // make sure originalIndex is in its own pos
    // e.g. ensureMediaIndexInPos(3) makes getShuffledIndex(3) == 3
    void ensureMediaIndexInPos(MediaIndex originalIndex);

private:
    VfxU16 m_mediaCount;
    VfxU16 *m_indices;
};
#endif

class VappGalleryInertiaPan
{
public:
    static const VfxMsec INERTIA_ANIM_TIME = 400;

    VappGalleryInertiaPan();

    void processPenEvent(const VfxPenEvent &e);

    VfxBool getInertiaPan(VfxS32 &offsetX, VfxS32 &offsetY);

protected:
    VfxS32 m_lastOffsetX;
    VfxS32 m_lastOffsetY;
    VfxMsec m_lastTimeDiff;
};

class VappGalleryGestureTranslator : public VfxObject
{
public:
    VappGalleryGestureTranslator();
    virtual void onInit();

public:
    // Client should feed pen event and itself with this function
    void processPenEvent(VfxFrame *component, const VfxPenEvent &evt);
    // Retrieve last pen event fed to the translator
    const VfxPenEvent& getLastPenEvent();
    // signal invoked when a gesture is recognized
    VfxSignal2<VappGalleryGestureTranslator*,   // sender object
               VappGalleryGesture>             // gesture recognized
               m_signalGestureRecognized;

    // clear internal state of gesture recognizer.
    void reset();
protected:
    void onTapTimer(VfxTimer *sender);
    static VfxS32 getSquaredDistance(const VfxPoint &p1, const VfxPoint &p2);

private:
    static const VfxMsec DOUBLE_TAP_INTERVAL = 300;
    // we track movement by ourselves,
    // because VfxPenEvent may have exactly the same prevPos,
    // which breaks the swipe detection.
    VfxMsec m_prevTimeStamp;
    VfxS32 m_prevX;
    VfxBool m_draggingMode;
    VfxBool m_delayedTap;       // VFX_TRUE if a VG_TAP is recognized but haven't sent
    VfxPoint m_delayedTapPos;   // records position of the delayed tap gesture
    VfxTimer *m_tapTimer;       // delay timer. because we want to distinguish tap from double-tap
    VfxPenEvent m_lastPenEvent; // last pen event received
};

// Load a file (DRM or not, Locked or not)
// and consume its right if possible (possible means DRM AND UNLOCKED)
class VappGalleryDRMConsumer : public VfxObject
{
public:
    VappGalleryDRMConsumer();
    virtual void onInit();
    virtual void onDeinit();

    void setFileAndUserData(const VfxWString &filePath, VfxS32 userData);

    void startConsume();    // for count consume
    void stopConsume();     // for count consume

    void pauseConsume();    // for timed consume
    void resumeConsume();   // for timed consume

    // sender, consume_reason
    VfxSignal3<VappGalleryDRMConsumer*, VfxS32, drm_proc_enum> m_signalRightExpired;
protected:
    enum DRMConsumeState
    {
        STATE_IDLE,
        STATE_CONSUME,
        STATE_PAUSED_CONSUME,
    };

protected:
    static const VfxS32 MAX_CONSUMER_INSTANCE = 3;
    static VfxObjHandle g_instances[MAX_CONSUMER_INSTANCE];
    // callback from DRM when rights has depleted
    static void onRightExpired(kal_int32 result, kal_int32 id);
    void handleRightExpired(kal_int32 result);

    // returns VFX_FALSE if registration failed (e.g. table full)
    VfxBool registerInstance();
    void unregisterInstance();
    void consumeDRMCountImpl();

protected:
    VfxS32 m_userData;
    VfxS32 m_jobId;
    VfxBool m_shouldConsume;
    DRMConsumeState m_state;
    VfxWString m_filePath;
};

class VappImageViewerComponentOption : public VfxBase
{
public:
    VfxBool supportZoom;
    VfxBool supportMultiTouch;
    VfxBool isSyncContentProvider;

public:
    VappImageViewerComponentOption()
        :supportZoom(VFX_FALSE)
        ,supportMultiTouch(VFX_FALSE)
        ,isSyncContentProvider(VFX_TRUE)
        {};
};

class VappImageViewerComponent : public VfxControl
{
    VFX_DECLARE_CLASS(VappImageViewerComponent);

    enum PanelPosition
    {
        CURRENT_PANEL,
        LEFT_PANEL,
        RIGHT_PANEL
    };

    enum ImageVerifySize
    {
        VERIFY_DIM = 10,
    };

    enum EnhanceMediaCheckResult
    {
        ENHANCE_MEDIA_CHECK_BUF_NOT_READY = -2,
        ENHANCE_MEDIA_CHECK_ERROR = -1,
        ENHANCE_MEDIA_CHECK_SUCCESS = 0,
        ENHANCE_MEDIA_CHECK_IS_DECODING = 1
    };

public:
    typedef VfxSignal2<VappGalleryGesture, VfxS32> GestureEvent;
    typedef VfxSignal1<VfxS32> CurrentPanelChangedEvent;
    typedef VfxSignal1<VfxS32> ProviderUpdatedEvent;
    typedef VfxSignal1<VfxWString> MediaPlayCommandEvent;
    typedef VfxSignal1<VfxBool> ZoomSliderEvent;
    typedef VfxSignal1<VfxBool> ViewSliderEvent;
    typedef VfxSignal0 SlideshowStoppedEvent;
    typedef VfxSignal0 StartDisplayMediaEvent;

// utility
public:
    static VfxBool isAnimatedImage(const VfxWString &filePath);

// ctor
public:
    VappImageViewerComponent();
    VappImageViewerComponent(VappImageViewerComponentOption option);
    void configAsyncProvider(IVappGalleryAsyncProvider * provider)
    {
        m_asyncProvider = provider;
    }
    IVappGalleryMediaList* getMediaList()
    {
        return m_mediaList;
    }

private:
    IVappGalleryAsyncProvider *m_asyncProvider;
// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

    virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

// event handler
public:
    void handleEnter(const VfxBool blockRefresh, VappGalleryViewerMediaState initState);
    void handleEntered(const VfxBool blockRefresh);
    void handleExit();
    void handleExited2(const VfxBool releaseForegroundOnly);

    // return true if parent page no need to process back event
    VfxBool handleBack();
    void handleQueryRotate();
    void handleRotate();

// methods
public:
    // TODO: for async case, medialist is not triger while page onEnter / onEntered
    void setInitState(VappGalleryViewerMediaState initState);
    VappGalleryViewerMediaState getInitState() const;
    void startUpdate();

    void consumeDRM(VfxImageSrc src);

    // get singal ptr which is responsible to notify provider is updated
    GestureEvent* getGestureEvent();
    CurrentPanelChangedEvent* getCurrentPanelChangedEvent();
    ProviderUpdatedEvent* getProviderUpdatedEvent();
    MediaPlayCommandEvent* getMediaPlayCommandEvent();
    ZoomSliderEvent* getZoomSliderEvent();
    ViewSliderEvent* getViewSliderEvent();
    StartDisplayMediaEvent* getStartDisplayMediaEvent();

    //  retrieve panel info
    VappGalleryDecodeResult getMediaPath(VappGalleryViewerPanel *panel, VfxWString &path);

    // returns currently active view panel
    VappGalleryViewerPanel* getCurrentPanel();

    // retrieve path of currently displayed media
    VappGalleryDecodeResult getCurrentMediaPath(VfxWString &path);
    void getCurrentMediaName(VfxWString &fileName);

    VfxBool isCurrentPreviewImageVisible();
    VfxBool isCurrentPreviewVideo();
    VfxBool isCurrentPreviewMAV();

    VfxBool hasValidMediaList() const;
    VfxBool isProviderPrepared() const;
    VfxBool canCheckDirty() const;
    VfxBool checkDirty() const;
    VfxBool canRefresh() const;
    VfxBool shouldRefreshProvider() const;
    void refresh();
    void hideAllPanel(const VfxBool isHide);
    // rotate the current image clock-wise 90 degree
    void rotateImagePreview();

    void suspendDecodeByFileOpInterrupt();
    void resumeDecodeAfterFileOpInterrupt();

    void handleFileDeleted(const VfxBool result);

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    // create zoom slider if page support slider
    void createZoomSlider();
    void layoutZoomSlider();
    void hideZoomSlider(const VfxBool hide);
    VcpSlider* getZoomSlider();
    VfxImageFrame* getZoomOutLabel();
    VfxImageFrame* getZoomInLabel();
#endif

    void createViewControl();
    void layoutViewControl();
    void updateViewControlByPanel(VappGalleryViewerPanel *panel);
    VcpSlider* getViewSlider();
    VfxFrame* getViewPrevLabel();
    VfxFrame* getViewNextLabel();
    VfxFrame* getMavIconFrame();

    void setupGSensor();
    void teardownGSensor();
    void enableGSensorSupport(const VfxBool enable);

    void create3DRedBlueIcon();
    void layout3DRedBlueIcon();
    void update3DRedBlueIcon(VappGalleryViewerPanel *panel);
    VfxFrame* get3DRedBlueIcon();

    void handlePageUiAnim(const VfxBool disableAutoAnim, const VfxU64 duration);

// Overridable
protected:

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    // override to provide zoom slider or not
    virtual VfxBool hasZoomSlider();
#endif

    // allow change position of viewer panel container
    virtual void layoutViewerPanelContainer(VfxFrame *viewerPanelContainer);

    void createKeypadLongPressTimer();

// public singals
public:
    // this signal is emitted when the "current viewing" image is changed.
    // the params are;
    //  - index (group-pos) of the new current viewing image
    VfxSignal1<VcpMenuPos> m_signalActiveImageChanged;

// constants
public:
    const static int TOTAL_PANEL_NUM = 3;
    const static int KEYPAD_LONG_PRESS_TIMER_DURATION = 40;
	
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    const static float ZOOM_MIN;
    const static float ZOOM_MAX;
#endif

    const static VfxMsec PANNING_ANIM_DURATION = 50;
    const static VfxMsec SLIDE_ANIM_DURATION = 400;
    const static VfxS32 PANEL_PADDING = GDI_LCD_WIDTH / 5;
    const static VfxMsec SLIDESHOW_WAIT_IMG_INTERVAL = 500; // polling interval when wait next image to decode
    const static VfxFloat GESTURE_FACTOR;

// event handler
protected:
    void onBoundsChange(VfxFrame *frm, const VfxRect &oldRect);

    // handle media list count/content update
    void onListUpdated(VappGalleryPrepareResult prepareResult);

    // when "current viewing panel" has changed.
    // note the current panel may be empty.
    void onCurrentPanelChanged();

    // called when a media index is about
    // to be displayed (only on current panel)
    void onStartDisplayMedia(MediaIndex mediaIdx);

    // handles DRM rights expiration
    void onFileRightExpired(VappGalleryDRMConsumer *sender, VfxS32 index, drm_proc_enum reason);

    // handle gestures
    void createGSensor();
    void destroyGSensor();
    void onGSensorEvent(VfxFloat offset);

    void onGesture(VappGalleryGestureTranslator *sender, VappGalleryGesture gesture);
    void onPan(VfxS32 xOffset, VfxS32 yOffset, VfxBool treatAsDragEnd);
    void onDragEnd(const VfxBool needInertia);

    // delay handle switch panel
    void onTimer0(VfxTimer *sender);

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    // handle zoom in/out by slider
    void onBeginZoom(VcpSlider *slider, VfxFloat value);
    void onZoom(VcpSlider *slider, VfxFloat value);
    void onEndZoom(VcpSlider *slider, VfxFloat value);
#endif

    // handle view angle changed
    void onBeginChangeView(VcpSlider *slider, VfxFloat value);
    void onChangeView(VcpSlider *slider, VfxFloat value);
    void onEndChangeView(VcpSlider *slider, VfxFloat value);
    void resetToInitViewedFrame(VappGalleryViewerPanel *panel);
    void updateImageFrame(VappGalleryViewerPanel *panel, const VfxFloat frameIndexHint, VfxBool isRelativeHint = VFX_FALSE);
    void updateCurrentImageFrame(const VfxFloat frameIndexHint, VfxBool isRelativeHint = VFX_FALSE);
    void calculateClipWindow(VfxImageBuffer buffer, VfxWString filePath, VfxRect &clipWindow);

    // handle toolbar commands
    void onPlayMedia(MediaIndex mediaIdx);
    ///VfxBool playSlideshow();    // return TRUE while play slideshow sucessfully
    ////void stopSlideshow(const VfxBool shouldHideAllBars = VFX_FALSE);
    void playFirstMedia(VfxTimer *sender);

    // handle multitouch gesture
    virtual void setMultiTouchMode(VfxBool isMultiTouchMode);
    VfxBool handleSingleTouchPenInput(VfxPenEvent &event);
    VfxBool handleMultiTouchPenInput(VfxPenEvent &event);

    // handle long press event in keypad
    void onKeypadLongPressimeout(VfxTimer *timer);

// implementations
protected:

    // create and initialize a view panel
    VappGalleryViewerPanel* createViewerPanel();
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    inline panelID getLeftPanelIndex()
    {

        return (m_currentPanel + 2) % TOTAL_PANEL_NUM;
    }

    inline panelID getRightPanelIndex()
    {
        return (m_currentPanel + 1) % TOTAL_PANEL_NUM;
    }

    // returns panel adjacent to left of current panel
    VappGalleryViewerPanel* getPanel(PanelPosition panelPos);

    // cleanup resources used by a given panel.
    void clearPanel(VappGalleryViewerPanel *panel);
    // release all image resources
    void clearAllPanel();
    // VFX_TRUE if the panel haven't been assigned with the mediaIdx or not ready(decoding)
    VfxBool isPanelReady(VappGalleryViewerPanel *panel, MediaIndex mediaIdx);
    // VFX_TRUE if the panel is updated
    // VFX_FALSE if the panel is already displaying mediaIdx
    VfxBool updatePanelMedia(VappGalleryViewerPanel *panel, MediaIndex mediaIdx);
    void updatePanelFileInfoImpl(VappGalleryViewerPanel *panel, VfxBool isVideo);

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    // VFX_TRUE if the enhancement has started
    // VFX_FALSE if the panel is already enhanced, or there is no need to enhance
    VfxBool enhancePanelMedia(VappGalleryViewerPanel *panel, MediaIndex mediaIdx);
    void onEnhanceResult(VappGalleryDecoderBase *sender, VappGalleryDecodeResult result);
    void stopEnhance();
    VfxBool canEnhanceMedia(MediaIndex mediaIdx);

    EnhanceMediaCheckResult enhancePanelMediaPreCheckImpl(VappGalleryViewerPanel *panel, MediaIndex mediaIdx);

#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_PARTIAL_ENHANCE_DECODE__
        void onPartialEnhnaceDecodeStart(VfxSize decodedLayerSize, VfxRect clipRect);
        void onPartialEnhnaceDecodeFinished(VappGalleryDecoderBase *sender, VappGalleryDecodeResult result);
#endif
        void onPartialEnhnaceDecodeCanceled();
#endif

        VfxRect m_enhanceChecksum;

    // single file case, see if input file is already verified.
    // if it is already verified
    void verifyInputFile();
    // cancel verifying operation
    void stopVerifyInputFile();
    // callback for receiving verify result
    void onVerifyResult(VappGalleryDecoderBase *sender, VappGalleryDecodeResult result);
    // set single file view panel according to verified result
    void displaySingleFileImage();

    // stop all decoding activities (preview, enhance, preload)
    void stopAllDecoding();

    VfxBool isAsyncMediaListScenario();
    VfxBool shouldReserveAdjacentPreview();

    // check if all panels have preview display. if not, start decoding them.
    void checkAllPanel(const VfxU32 line, VfxBool startEnhance = VFX_TRUE);
    // returns initial X-offset of a givent panel (left, current, right)
    // this considers the padding between panels
    VfxS32 getPanelInitialPos(PanelPosition panelPos);
    // restore panel to its initial position
    void snapPanelToInitialPosition(PanelPosition panelPos, VfxBool isAnim);
    // move panel to reveal next/previous media
    void shiftPanel(VfxBool isGoNext);
    // change the position of all visible panels.
    // mainly used for dragging
    void offsetVisiblePanels(VfxS32 offsetX, VfxBool isAnim);

    VappGalleryViewerPanel* getPanelByMediaIndex(MediaIndex index);

    VfxBool canGoNext();
    VfxBool canGoPrevious();
    MediaIndex getNextIndex()const;
    MediaIndex getPrevIndex()const;
    void showBallonIfMultiFile(const VfxId ballonTextId);

    // translate low-level pen input into high-level gesture
    VappGalleryGesture translateGesture(const VfxPenEvent &event);

    void onPreviewTimerCheck(VfxTimer *sender);
    void onShiftAnimationFinish(VfxTimer *sender);
    void onDecodeResult(VcpMenuPos index, VappGalleryDecodeResult result);

    // This functions binds to display current
    // media to current panel.
    void assignLockResultToPanel(MediaIndex mediaIndex,             // [IN] index of the media
                                 VappGalleryViewerPanel *panel,     // [IN] the panel to assign media
                                 const VappGalleryDecodeResult result,         // [IN] the result, e.g. panel may display error icon
                                 const VfxImageBuffer imgBuf);      // [IN] image buffer of the media if result is OK

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    void updateZoomSliderByPanel(VappGalleryViewerPanel *panel);
    VfxBool canZoomPanel(VappGalleryViewerPanel *panel);            // returns VFX_TRUE if the panel content can zoom and ready to zoom.
#endif

    // Animated GIF handling
    VfxBool isAnimatedImage(MediaIndex mediaIdx);

    // MAV(multiple angle view) handling
    VfxBool isMAVImage(MediaIndex mediaIdx);
    VfxBool isMAVImage(const VfxWString &filePath);
    void getViewFrameCount(const VfxWString &filePath, VfxS32 &frameCount);

public:
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
    SlideshowStoppedEvent* getSlideshowStoppedEvent();
    // check if viewer is playing slideshow
    VfxBool isPlayingSlideshow() const;
    // check if current slideshow have orientation limitation.
    VfxBool getSlideshowOrientationLimit(VfxBool &hasOrientationLimit, VfxScrRotateTypeEnum &orientation);
    // return TRUE while play slideshow sucessfully
    VfxBool playSlideshow();
    void stopSlideshow();
    // handles slideshow playback
    void onSlideshowAnimFinish(VfxFrame *target,
                               VappGallerySlideshowBase::FinishType finishType,
                               VfxBool isCompleted);
    // create slideshow container
    void createSlideshowContainer();
    VappGallerySlideshowBase *createSlideshowInstance(VfxBool isTransition, VcpPageEffectType type);
    // destroy slideshow container and leave slideshow
    void closeSlideshowContainer();
    // should skip media or not
    VfxBool canSlideshowMedia(MediaIndex mediaIndex);
    // handles still image timer. when this timer ticked, start transition.
    void onSlideshowStillImageTimer(VfxTimer *source);
    // prepate next slideshow panel
    // VFX_TRUE if a decoding action is triggered or running
    VfxBool prepareNextSlideshowMediaPanel();
    // get next media index to display according to setting
    // note the index may repeat, loop or shuffled
    // INVALID_MEDIA_INDEX means there is no next playback index.
    MediaIndex getNextPlaybackIndex();
    // Adjust panel content for slideshow switch effect
    // e.g. turn off GIF animation
    void setupSlideshowPanel(VappGalleryViewerPanel *panel);
#endif

// implementations
private:
    void notifyGestureEvent(VappGalleryGesture gesture, VfxS32 index);
    void notifyCurrentPanelChanged(const VfxS32 currentIndex);
    void notifyProviderUpdatedEvent(const VfxS32 meidaCount);
    void notifyMediaPlayCommand(VfxWString &path);

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    void notifyZoomSliderEvent(VfxBool isZooming);
#endif
    void notifyViewSliderEvent(VfxBool isDragging);
    void notifySlideshowStopped();
    void notifyStartDisplayMedia();

    // find the App which uses viewerCP
    VfxApp* getRootApp()const;
    // get screen rotation
    VfxScrRotateTypeEnum getScreenRotation() const;
    // test utility for IOT
    void sendCurrentViewedFilePathMsg();
    void sendFilePathMsg(const VcpMenuPos menuPos, const VfxS32 serialNum);

// data member
protected:
    VappImageViewerComponentOption m_option;
	
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    // zoom slider
    VcpSlider *m_zoomSlider;
    VfxImageFrame *m_zoomInLabel;
    VfxImageFrame *m_zoomOutLabel;
#endif
    // keypad support
    VfxTimer *m_keypadLongPressTimer;
    VfxFloat m_zoomOffset;
    // MAV(Multi-Angle View) support
    VcpSlider *m_viewSlider;
    VfxFrame *m_viewPrevLabel;
    VfxFrame *m_viewNextLabel;
    VfxFrame *m_mavIconFrame;
    VfxBool m_isViewSliderDraging;
    VfxBool m_enableGSensorSupport; // VFX_FALSE, if disable g sensor support forcely
#ifdef __VAPP_MAV_MOTION_TRANSLATOR_SUPPORT__
    VappMavMotionTranslator* m_gSensor;
#endif
    VfxFrame* m_3dRedBlueImageIcon;
    VfxBool m_isDuringFileOperation;
    // viewer panel container (to maintain proper z-order)
    VfxFrame *m_viewerPanelContainer;
    // the data source
    IVappGalleryMediaList *m_mediaList;
    // focus (currently active) media
    MediaIndex m_currentIndex;
    VappGalleryViewerMediaState m_initState;
    // Panels that used to display a single image.
    VappGalleryViewerPanel *m_viewPanels[TOTAL_PANEL_NUM];
    // DRM consumer
    VappGalleryDRMConsumer *m_drmConsumer;

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    // Enhanced image
    VappGalleryEnhancedImage *m_enhancedImage;
    // Image decoder for enhance
    VappGalleryImageThumbnail *m_enhancer;
#endif

    // Image decoder for checking if single-file case is a valid file.
    VappGalleryImageThumbnail *m_imageChecker;
    VappGalleryCachedImage *m_imageCheckerOutput;
    // timer for preview display (make sure each panel has decoded preview)
    VfxTimer *m_previewTimer;
    // timer for finishing panel shifting animation
    VfxTimer *m_panelShiftFinishTimer;
    // currently focused (active) Panels
    panelID m_currentPanel;

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    // VFX_TRUE if we're zooming (dragging zoom slider)
    VfxBool m_isSliderZooming;
#endif

    // VFX_TRUE if a warning popup is already popped in a pen down-up period.
    // This flag is used to prevent generating too much
    // warning popup in a down-up period (e.g. move picture when reaching last picture)
    VfxBool m_warningPoppedDuringGesture;
    // VFX_TRUE if a warning popup is already popped for same current viewed image
    // both flags are reset while current panel is changed
    VfxBool m_hasShownLastPhotoHint; 
    VfxBool m_hasShownFirstPhotoHint;
    // for gesture parsing
    VappGalleryGestureTranslator *m_gestureTranslator;
    // for pan inertia
    VappGalleryInertiaPan m_inertiaPan;
    // for multitouch gesture support
    VfxBool m_isMultiTouchMode;
    VfxBool m_multiTouchZoomGesture;
    // for slideshow playback.
    // this is only used during playback
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
    VappGallerySlideshowBase *m_slideshowContainer;
    VfxTimer *m_slideshowStillImageTimer;
    VappGalleryShuffleIndex *m_shuffleIndex;
    SimpleBitSet m_slideshowBlackList;  // a bit is set if the corresponding MediaIndex is already played and cannot be played
    MediaIndex m_slideshowStartIndex;   // media index that starts playing slideshow
    MediaIndex m_slideshowCurrentIndex; // media index that is currently being displayed
    VappGallerySlideShowSetting m_slideshowSetting;
#endif
    GestureEvent m_signalGesture;
    CurrentPanelChangedEvent m_signalCurrentPanelChanged;
    ProviderUpdatedEvent m_signalProviderUpdated;
    MediaPlayCommandEvent m_signalMediaPlayCommand;

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    ZoomSliderEvent m_signalZoomSlider;
#endif

    ViewSliderEvent m_signalViewSlider;

#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
    SlideshowStoppedEvent  m_signalSideshowStopped;
#endif
    StartDisplayMediaEvent m_signalStartDisplayMedia;
};

#else
class VappGalleryViewerPanel : public VfxFrame
{
public:
    enum PreviewRotation
    {
        ROTATE_0,
        ROTATE_90,
        ROTATE_180,
        ROTATE_270,

        ROTATE_ENUM_COUNT,
    };

    enum PanningHint
    {
        MOVE,       // ordinary finger-move
        INERTIA,    // finger release, move with inertia
        STOP,       // finger pressed, stop move immediately.
    };

    // partial enhance decode support
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_PARTIAL_ENHANCE_DECODE__
    // decoded target size, clip rect(x, y ,original_img_size_w, original_img_size_h)
    VfxSignal2<VfxSize, VfxRect> m_signalStartDecodeL1EnhanceBuf;
#endif

public:
    VappGalleryViewerPanel();
// override
public:
    virtual void onInit();
    virtual void onDeinit();

// methods
public:
    void clear();
    VfxBool hasMediaIndex() const;
    void setMediaIndex(MediaIndex idx, VfxBool isVideo = VFX_FALSE);
    MediaIndex getMediaIndex() const;

    VfxBool isLoading();
    void setIsLoading();
    void setIcon(ViewIconType icon);

    // set the preview image. This preview image
    // comes from MediaList, so it should be properly locked & unlocked.
    void setPreviewCachedBuffer(
        const VfxImageBuffer &imgBuf,
        VfxS32 maxZoomDim,
        const VfxSize *originalImageSize = NULL,
        const VfxWString &path = VFX_WSTR_EMPTY,
        VfxRect clipWindow = VfxRect(0, 0, 0,0));

    // set the enhanced image. This is not from MediaList,
    // requires ViewerPage to properly switch it
    void setEnhancedBuffer(const VfxImageBuffer &imgBuf);
    // is this panel display enhanced buffer?
    VfxBool hasEnhancedBuffer();
    // stop display the enhanced buffer and use cached preview if any.
    void clearEnhnacedBuffer();
    void setupOwnerDraw();
    void teardownOwnerDraw();

    void setPreviewImageAnimated(VfxBool isAnim);
    VfxBool isPreviewImageAnimated();
    VfxBool isDisplayImage();
    VfxBool isOwnerDraw();
    VfxBool setOwnerDrawHint(DrawHint hint);
    VfxBool setOwnerDrawBufferHint(VfxBool forceUsePreviewBuf);

    // VFX_TRUE if the current display content is cached (via setPreviewCachedBuffer)
    VfxBool hasCachedBuffer()const;

    // only valid when hasCachedBuffer() is VFX_TRUE
    // buf will be filled with info of preview buffer.
    VfxBool getPreviewCachedBuffer(VfxImageBuffer &buf);

    // set the preview image. This preview image
    // is a general VfxImageSrc, and not related to
    // media cache.
    void setPreviewImage(const VfxImageSrc &imgSrc, VfxBool drmCheck = VFX_FALSE);

    VfxBool getPreviewImage(VfxImageSrc &imgSrc);

    void resetViewState(VfxBool resetSize = VFX_TRUE);

    // query if this panel is showing the video "play" button
    VfxBool hasPlayButton();

    // query valid zoom level range.
    // note that zoom level is based on Preview Buffer size, not actual image size nor view panel size.
    void getZoomRange(VfxFloat &zoomMin, VfxFloat &zoomMax);

    // is the view panel in zoom-in state?
    VfxBool isZoomed();

    // must zoomMin <= zoomLevel <= zoomMax
    void getZoom(VfxFloat &zoomLevel);

    // get current zoom level
    void setZoom(VfxFloat zoomLevel);

    // get the zoom level that'll fit the viewer panel size
    void getMinZoom(VfxFloat &zoomLevel);

    void getMaxZoom(VfxFloat &zoomLevel);

    // get the default zoom level when the image is double-tapped
    void getDoubleTapZoom(VfxFloat &zoomLevel);

    // handle file type
    void setIsVideo(const VfxBool isVideo);
    void setImageType(const VfxU16 imageType);
    void setImageOriginalDimension(const VfxSize s);
    void setIsAnimedGif(const VfxBool isAnim);
    void setIs3DRedBlueImage(const VfxBool is3DRedBlue);

    VfxU16 getImageType() const;
    VfxBool getIsVideo() const;
    VfxBool getIsAnimedGif() const;
    VfxBool getIs3DRedBlueImage() const;
    VfxSize getImageOriginalDimension() const;

    // MAV(Multi-Angle View) support
    void setFrameIndex(VfxS32 frameIndex);
    VfxS32 getFrameIndex();
    VfxS32 getMaxFrameIndex();
    VfxS32 getMinFrameIndex();
    void setFrameCount(VfxS32 frameCount){m_frameCount = frameCount;};
    VfxS32 getFrameCount(){return m_frameCount;}
    VfxBool getIsMAV();

    // the margin from possible anchor point to image boundary
    VfxFPoint getMaxAnchorMargin() const;
    void clampAnchorPointWithinMargin(VfxFPoint &anchorPoint) const;
    // pan the image and get unused offset (when hit boundary) in X direction
    void offsetView(VfxS32 offsetX,         // [IN] pan offset X, in pixels
                    VfxS32 offsetY,         // [IN] pan offset Y, in pixels
                    PanningHint hint,       // [IN] hint of movement
                    VfxS32 &remainOffsetX   // [OUT] remaining offset after hitting boundary
                    );

    // rotate to designated orientation
    void setRotate(PreviewRotation r, VfxBool isAnim = VFX_TRUE);

    // get current rotation orientation
    PreviewRotation getRotate();

    // rotate the preview image clockwise 90 degree
    void rotateCW(VfxBool isAnim = VFX_TRUE);

// signal
public:
    // signal to play a video
    VfxSignal1<MediaIndex> m_signalPlayCommand;

protected:
    void calculateBaseSizeFromSourceImage(VfxSize &rect);

    // calculate current on-screen preview size, after zoom & rotate.
    VfxSize getCurrentPreviewSize() const;

    void onBoundsChange(VfxFrame *frm, const VfxRect &rect);

    void onPlayBtnClicked(VfxObject *sender, VfxId btnId);

    VfxBool checkImageDRMRights(const VfxImageSrc src);

// data member
protected:
    // file type info
    VfxBool m_isVideo;
    VfxU16 m_imageFileType;     // GDI image type
    VfxSize m_imageOriginalDimension;
    VfxBool m_isAnimedGif;
    VfxBool m_is3DRedBlue;
    VfxRect m_frameClipWindow;
    VfxS32 m_frameCount;        // total frame count

    VfxBool m_isLoading;        // VFX_TRUE if the waiting icon is being displayed (decoding content)
    MediaIndex m_mediaIndex;    // the index into a medialist.
    VappGalleryPreviewImage *m_previewImg;     // displays preview image
    VcpActivityIndicator *m_waitIcon;   // wait spin icon
    VfxImageFrame *m_errIcon;   // icon for DRM/Error/Unsupported files
    VcpImageButton *m_playBtn;  // click to video playback. Only available for video.
    VfxS32 m_maxZoomDim;        // image maxmum zoomed size. may be different for different image types.
    VfxSize m_sizeOriginal;     // image "original" size
    VfxSize m_baseSize;         // size of the preview area, fitting into viewing panel
    PreviewRotation m_currentRotation; // keep tracking of current preview rotation. this is NOT screen orientation.
    VfxImageBuffer m_cachedBuffer;      // this is the "locked" preview (LCD size) buffer
    VfxImageBuffer m_enhancedBuffer;    // this is the enhanced buffer (not locked but assigned)

    VappGalleryImageDrawer *m_draw;     // drawing function for  drawing enhanced image with GDI 2D transform

private:
#ifdef __VENUS_3D_UI_ENGINE__
    void setupZoomFrames();
    void teardownZoomFrames();
    VfxFrame *m_enhancedImg;
#endif

// partial enhnace decode support
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_PARTIAL_ENHANCE_DECODE__
private:
    void onStartPartialEnhanceDecode(VfxSize decodedLayerSize, VfxRect clipRect);
public:
    void onCancelPartialEnhanceDecode();
    void onFinishPartialEnhanceDecode(const VfxRect clipRectCheckSum);
    VfxBool updateEnhanceBufToDraw(const VfxRect clipRectCheckSum);
#endif

public:
    void startAnimTimer(const VfxBool disabledAnimTimer, const VfxMsec duration, const VfxU32 line);
    void stopAnimTimer();
    void closeAnimTimer();
    void onAnimTimeout(VfxTimer *timer);
private:
    VfxTimer* m_animTimer;
};

class VappGalleryEnhancedImage : public VfxObject
{
public:
    static const VfxS32 LCD_BUF_SIZE = GDI_LCD_WIDTH * GDI_LCD_HEIGHT * VAPP_GALLERY_IMG_VIEWER_BPP;
    // define temp buffer size for decoded enhnace image
    // in full enhance decode case, buffer szie is same  as the 9x or 4x LCD
    // otherwise, the buffer length is same as LCD buf (partial enhance image decode case)
    #ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_DECODE_FULL_ENHANCE_IMG__
    static const VfxS32 IMAGE_BUF_SIZE = LCD_BUF_SIZE * VAPP_GALLERY_IMG_VIEWER_ENHANCE_BUFFER_RATIO;
    #else
    static const VfxS32 IMAGE_BUF_SIZE = GDI_LCD_WIDTH * GDI_LCD_HEIGHT * VAPP_GALLERY_IMG_VIEWER_BPP;
    #endif

    static VfxS32 getMaxImageFrameSize();
    static VfxS32 getMaxEnhanceDimensionByPath(const VfxWString &path, VfxU16 fileTypeHint = GDI_IMAGE_TYPE_INVALID);
    static VfxS32 getMaxEnhanceDimensionByType(VfxU16 gdiImageType);

public:
    VappGalleryEnhancedImage();
    virtual void onInit();
    virtual void onDeinit();

    VfxBool reset();
    void finishDecode();
    VfxBool isReadyToDecode(MediaIndex index);
    VfxBool isDecoding(MediaIndex index);

    // in partial enhance decode scenario, the decoded size is according to watch frame size, anchor and pos
    // so decoderd size is not same as the size queried from getEnhancedImageSize
    VfxBool setFileAndGetOutputBuffer(MediaIndex mediaIdx, const VfxWString &path, VfxImageBuffer &outputBuf, VfxSize bufferSizeHint = VfxSize(0, 0));
    VfxBool getOutputBuffer(VfxImageBuffer &outputBuf);

public:
    // VFX_FALSE is returned if this image needs no enhance
    // query size of enhnace image in full decoded scenario
    VfxBool getEnhancedImageSize(
        const VfxWString &path, VfxSize &size,
        VfxU16 fileTypeHint = GDI_IMAGE_TYPE_INVALID,
        VfxSize originalDim = VfxSize(0, 0));

protected:
    VfxBool m_isDecoding;
    MediaIndex m_mediaIndex;
    VfxWString m_mediaPath;

    void *m_rawBuf;
    VfxS32 m_bufLength;
    VfxImageBuffer m_imgBuf;
};

class VappGalleryViewerMediaState
{
public:
    VappGalleryViewerMediaState();
    VappGalleryMediaListMediaCache* createMediaList(VfxObject *parent);
    VfxBool isSingleFile();
public:
    VfxBool m_refreshed;      // VFX_TRUE if this initial state has constructed file list.
    VfxBool m_displayed;      // VFX_TRUE if this initial state is already displayed
    VfxBool m_useIndexInList; // if VFX_TRUE, use focusIndex instead of focusFile
    VfxBool m_imageOnly;      // if VFX_TRUE, only enumerate images. Otherwise also enumerate videos
    VfxBool m_videoOnly;      // if VFX_TRUE, only enumerate videos. Otherwise also enumerate images    
    VfxBool m_autoPlaySlideshow; // if VFX_TRUE, slideshow are started after media list is ready.
    VfxBool m_allowEmptyPage;    // if VFX_TRUE, do not exit() page when there is no image available.
    VfxBool m_confirmScenario;       // if VFX_TRUE, show ok and delete. While user pressed button, exist image viewer.
    VappGalleryDecodeResult m_singleFileCheckResult;  // Stores checked result of single file case. only valid when isSingleFile() is VFX_TRUE.
    VfxS32 m_focusIndex;
    VfxS32 m_sortMethod; // refer to fs_gprot.h
    VfxWString m_focusFile;
    VfxWString m_folderPath;  // the folder to scan
    VfxImageSrc m_singleFileSrc;    // for single media mode records media source
    VfxBool m_isSyncContentProvider;
    VfxBool m_hasCustomFilter;
    FMGR_FILTER m_fileFilter;
    VfxS32 m_cacheCount;
    VfxBool m_disableSwitchBalloon;
};

class VappGallerySlideshowBase : public VfxFrame
{
public:
    virtual void onInit();
    virtual void onDeinit();

    virtual void getOrientationLimit(VfxBool &hasLimit, VfxScrRotateTypeEnum &orientation) = 0;

    virtual void playOpening() = 0;
    virtual void playEnding() = 0;

    virtual void setNextMedia(VfxFrame *frame) = 0;
    virtual void playMedia() = 0;

    virtual VfxBool handleGesture(VappGalleryGestureTranslator *sender, VappGalleryGesture gesture) {return VFX_FALSE;};
    virtual VfxBool canPlayMedia() {return VFX_TRUE;};
public:
    enum FinishType
    {
        FT_OPENING,
        FT_ENDING,
        FT_MEDIA,
    };

    // notify APP when an animation is finished. the frame which is switched to
    // will be passed as parameter. The effect is complete or not is also passed.
    VfxSignal3 <
        VfxFrame *,             // target media frame, may be NULL
        FinishType,             // animation type
        VfxBool                 // is completed
        > m_signalFinished;
};

#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
class VappGalleryTransitionSlideshow : public VappGallerySlideshowBase
{
public:
    VappGalleryTransitionSlideshow();
    virtual void onInit();
    virtual void onDeinit();

    virtual void getOrientationLimit(VfxBool &hasLimit, VfxScrRotateTypeEnum &orientation);

    virtual void playOpening();
    virtual void playEnding();

    virtual void setNextMedia(VfxFrame *frame);
    virtual void playMedia();

public:
    void configEffectType(VcpPageEffectType effectType);

protected:
    void onPageEffectFinish(VfxFrame *target, VfxBool isCompleted);

protected:
    VfxFrame *m_currentMedia;
    VfxFrame *m_nextMedia;
    VcpPagePanel *m_pagePanel;
    VcpPageEffectType m_effectType;
};
#endif
class VappGalleryShuffleIndex : public VfxObject
{
public:
    VappGalleryShuffleIndex(VfxU16 mediaCount);
    virtual void onInit();
    virtual void onDeinit();

public:
    // get shuffled index by original index
    MediaIndex getShuffledIndex(MediaIndex originalIndex);

    // make sure originalIndex is in its own pos
    // e.g. ensureMediaIndexInPos(3) makes getShuffledIndex(3) == 3
    void ensureMediaIndexInPos(MediaIndex originalIndex);

private:
    VfxU16 m_mediaCount;
    VfxU16 *m_indices;
};

class VappGalleryInertiaPan
{
public:
    static const VfxMsec INERTIA_ANIM_TIME = 400;

    VappGalleryInertiaPan();

    void processPenEvent(const VfxPenEvent &e);

    VfxBool getInertiaPan(VfxS32 &offsetX, VfxS32 &offsetY);

protected:
    VfxS32 m_lastOffsetX;
    VfxS32 m_lastOffsetY;
    VfxMsec m_lastTimeDiff;
};

class VappGalleryGestureTranslator : public VfxObject
{
public:
    VappGalleryGestureTranslator();
    virtual void onInit();

public:
    // Client should feed pen event and itself with this function
    void processPenEvent(VfxFrame *component, const VfxPenEvent &evt);
    // Retrieve last pen event fed to the translator
    const VfxPenEvent& getLastPenEvent();
    // signal invoked when a gesture is recognized
    VfxSignal2<VappGalleryGestureTranslator*,   // sender object
               VappGalleryGesture>             // gesture recognized
               m_signalGestureRecognized;

    // clear internal state of gesture recognizer.
    void reset();
protected:
    void onTapTimer(VfxTimer *sender);
    static VfxS32 getSquaredDistance(const VfxPoint &p1, const VfxPoint &p2);

private:
    static const VfxMsec DOUBLE_TAP_INTERVAL = 300;
    // we track movement by ourselves,
    // because VfxPenEvent may have exactly the same prevPos,
    // which breaks the swipe detection.
    VfxMsec m_prevTimeStamp;
    VfxS32 m_prevX;
    VfxBool m_draggingMode;
    VfxBool m_delayedTap;       // VFX_TRUE if a VG_TAP is recognized but haven't sent
    VfxPoint m_delayedTapPos;   // records position of the delayed tap gesture
    VfxTimer *m_tapTimer;       // delay timer. because we want to distinguish tap from double-tap
    VfxPenEvent m_lastPenEvent; // last pen event received
};

// Load a file (DRM or not, Locked or not)
// and consume its right if possible (possible means DRM AND UNLOCKED)
class VappGalleryDRMConsumer : public VfxObject
{
public:
    VappGalleryDRMConsumer();
    virtual void onInit();
    virtual void onDeinit();

    void setFileAndUserData(const VfxWString &filePath, VfxS32 userData);

    void startConsume();    // for count consume
    void stopConsume();     // for count consume

    void pauseConsume();    // for timed consume
    void resumeConsume();   // for timed consume

    // sender, consume_reason
    VfxSignal3<VappGalleryDRMConsumer*, VfxS32, drm_proc_enum> m_signalRightExpired;
protected:
    enum DRMConsumeState
    {
        STATE_IDLE,
        STATE_CONSUME,
        STATE_PAUSED_CONSUME,
    };

protected:
    static const VfxS32 MAX_CONSUMER_INSTANCE = 3;
    static VfxObjHandle g_instances[MAX_CONSUMER_INSTANCE];
    // callback from DRM when rights has depleted
    static void onRightExpired(kal_int32 result, kal_int32 id);
    void handleRightExpired(kal_int32 result);

    // returns VFX_FALSE if registration failed (e.g. table full)
    VfxBool registerInstance();
    void unregisterInstance();
    void consumeDRMCountImpl();

protected:
    VfxS32 m_userData;
    VfxS32 m_jobId;
    VfxBool m_shouldConsume;
    DRMConsumeState m_state;
    VfxWString m_filePath;
};

class VappImageViewerComponentOption : public VfxBase
{
public:
    VfxBool supportZoom;
    VfxBool supportMultiTouch;
    VfxBool isSyncContentProvider;

public:
    VappImageViewerComponentOption()
        :supportZoom(VFX_FALSE)
        ,supportMultiTouch(VFX_FALSE)
        ,isSyncContentProvider(VFX_TRUE)
        {};
};

class VappImageViewerComponent : public VfxControl
{
    VFX_DECLARE_CLASS(VappImageViewerComponent);

    enum PanelPosition
    {
        CURRENT_PANEL,
        LEFT_PANEL,
        RIGHT_PANEL
    };

    enum ImageVerifySize
    {
        VERIFY_DIM = 10,
    };

    enum EnhanceMediaCheckResult
    {
        ENHANCE_MEDIA_CHECK_BUF_NOT_READY = -2,
        ENHANCE_MEDIA_CHECK_ERROR = -1,
        ENHANCE_MEDIA_CHECK_SUCCESS = 0,
        ENHANCE_MEDIA_CHECK_IS_DECODING = 1
    };

public:
    typedef VfxSignal2<VappGalleryGesture, VfxS32> GestureEvent;
    typedef VfxSignal1<VfxS32> CurrentPanelChangedEvent;
    typedef VfxSignal1<VfxS32> ProviderUpdatedEvent;
    typedef VfxSignal1<VfxWString> MediaPlayCommandEvent;
    typedef VfxSignal1<VfxBool> ZoomSliderEvent;
    typedef VfxSignal1<VfxBool> ViewSliderEvent;
    typedef VfxSignal0 SlideshowStoppedEvent;
    typedef VfxSignal0 StartDisplayMediaEvent;

// utility
public:
    static VfxBool isAnimatedImage(const VfxWString &filePath);

// ctor
public:
    VappImageViewerComponent();
    VappImageViewerComponent(VappImageViewerComponentOption option);
    void configAsyncProvider(IVappGalleryAsyncProvider * provider)
    {
        m_asyncProvider = provider;
    }
    IVappGalleryMediaList* getMediaList()
    {
        return m_mediaList;
    }

private:
    IVappGalleryAsyncProvider *m_asyncProvider;
// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

    virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

// event handler
public:
    void handleEnter(const VfxBool blockRefresh, VappGalleryViewerMediaState initState);
    void handleEntered(const VfxBool blockRefresh);
    void handleExit();
    void handleExited2(const VfxBool releaseForegroundOnly);

    // return true if parent page no need to process back event
    VfxBool handleBack();
    void handleQueryRotate();
    void handleRotate();

// methods
public:
    // TODO: for async case, medialist is not triger while page onEnter / onEntered
    void setInitState(VappGalleryViewerMediaState initState);
    VappGalleryViewerMediaState getInitState() const;
    void startUpdate();

    void consumeDRM(VfxImageSrc src);

    // get singal ptr which is responsible to notify provider is updated
    GestureEvent* getGestureEvent();
    CurrentPanelChangedEvent* getCurrentPanelChangedEvent();
    ProviderUpdatedEvent* getProviderUpdatedEvent();
    MediaPlayCommandEvent* getMediaPlayCommandEvent();
    ZoomSliderEvent* getZoomSliderEvent();
    ViewSliderEvent* getViewSliderEvent();
    StartDisplayMediaEvent* getStartDisplayMediaEvent();

    //  retrieve panel info
    VappGalleryDecodeResult getMediaPath(VappGalleryViewerPanel *panel, VfxWString &path);

    // returns currently active view panel
    VappGalleryViewerPanel* getCurrentPanel();

    // retrieve path of currently displayed media
    VappGalleryDecodeResult getCurrentMediaPath(VfxWString &path);
    void getCurrentMediaName(VfxWString &fileName);

    VfxBool isCurrentPreviewImageVisible();
    VfxBool isCurrentPreviewVideo();
    VfxBool isCurrentPreviewMAV();

    VfxBool hasValidMediaList() const;
    VfxBool isProviderPrepared() const;
    VfxBool canCheckDirty() const;
    VfxBool checkDirty() const;
    VfxBool canRefresh() const;
    VfxBool shouldRefreshProvider() const;
    void refresh();
    void hideAllPanel(const VfxBool isHide);
    // rotate the current image clock-wise 90 degree
    void rotateImagePreview();

    void suspendDecodeByFileOpInterrupt();
    void resumeDecodeAfterFileOpInterrupt();

    void handleFileDeleted(const VfxBool result);

    // create zoom slider if page support slider
    void createZoomSlider();
    void layoutZoomSlider();
    void hideZoomSlider(const VfxBool hide);
    VcpSlider* getZoomSlider();
    VfxImageFrame* getZoomOutLabel();
    VfxImageFrame* getZoomInLabel();

    void createViewControl();
    void layoutViewControl();
    void updateViewControlByPanel(VappGalleryViewerPanel *panel);
    VcpSlider* getViewSlider();
    VfxFrame* getViewPrevLabel();
    VfxFrame* getViewNextLabel();
    VfxFrame* getMavIconFrame();

    void setupGSensor();
    void teardownGSensor();
    void enableGSensorSupport(const VfxBool enable);

    void create3DRedBlueIcon();
    void layout3DRedBlueIcon();
    void update3DRedBlueIcon(VappGalleryViewerPanel *panel);
    VfxFrame* get3DRedBlueIcon();

    void handlePageUiAnim(const VfxBool disableAutoAnim, const VfxU64 duration);

// Overridable
protected:
    // override to provide zoom slider or not
    virtual VfxBool hasZoomSlider();

    // allow change position of viewer panel container
    virtual void layoutViewerPanelContainer(VfxFrame *viewerPanelContainer);

    void createKeypadLongPressTimer();

// public singals
public:
    // this signal is emitted when the "current viewing" image is changed.
    // the params are;
    //  - index (group-pos) of the new current viewing image
    VfxSignal1<VcpMenuPos> m_signalActiveImageChanged;

// constants
public:
    const static int TOTAL_PANEL_NUM = 3;
    const static int KEYPAD_LONG_PRESS_TIMER_DURATION = 40;
    const static float ZOOM_MIN;
    const static float ZOOM_MAX;
    const static VfxMsec PANNING_ANIM_DURATION = 50;
    const static VfxMsec SLIDE_ANIM_DURATION = 400;
    const static VfxS32 PANEL_PADDING = GDI_LCD_WIDTH / 5;
    const static VfxMsec SLIDESHOW_WAIT_IMG_INTERVAL = 500; // polling interval when wait next image to decode
    const static VfxFloat GESTURE_FACTOR;

// event handler
protected:
    void onBoundsChange(VfxFrame *frm, const VfxRect &oldRect);

    // handle media list count/content update
    void onListUpdated(VappGalleryPrepareResult prepareResult);

    // when "current viewing panel" has changed.
    // note the current panel may be empty.
    void onCurrentPanelChanged();

    // called when a media index is about
    // to be displayed (only on current panel)
    void onStartDisplayMedia(MediaIndex mediaIdx);

    // handles DRM rights expiration
    void onFileRightExpired(VappGalleryDRMConsumer *sender, VfxS32 index, drm_proc_enum reason);

    // handle gestures
    void createGSensor();
    void destroyGSensor();
    void onGSensorEvent(VfxFloat offset);

    void onGesture(VappGalleryGestureTranslator *sender, VappGalleryGesture gesture);
    void onPan(VfxS32 xOffset, VfxS32 yOffset, VfxBool treatAsDragEnd);
    void onDragEnd(const VfxBool needInertia);

    // delay handle switch panel
    void onTimer0(VfxTimer *sender);

    // handle zoom in/out by slider
    void onBeginZoom(VcpSlider *slider, VfxFloat value);
    void onZoom(VcpSlider *slider, VfxFloat value);
    void onEndZoom(VcpSlider *slider, VfxFloat value);

    // handle view angle changed
    void onBeginChangeView(VcpSlider *slider, VfxFloat value);
    void onChangeView(VcpSlider *slider, VfxFloat value);
    void onEndChangeView(VcpSlider *slider, VfxFloat value);
    void resetToInitViewedFrame(VappGalleryViewerPanel *panel);
    void updateImageFrame(VappGalleryViewerPanel *panel, const VfxFloat frameIndexHint, VfxBool isRelativeHint = VFX_FALSE);
    void updateCurrentImageFrame(const VfxFloat frameIndexHint, VfxBool isRelativeHint = VFX_FALSE);
    void calculateClipWindow(VfxImageBuffer buffer, VfxWString filePath, VfxRect &clipWindow);

    // handle toolbar commands
    void onPlayMedia(MediaIndex mediaIdx);
    ///VfxBool playSlideshow();    // return TRUE while play slideshow sucessfully
    ////void stopSlideshow(const VfxBool shouldHideAllBars = VFX_FALSE);
    void playFirstMedia(VfxTimer *sender);

    // handle multitouch gesture
    virtual void setMultiTouchMode(VfxBool isMultiTouchMode);
    VfxBool handleSingleTouchPenInput(VfxPenEvent &event);
    VfxBool handleMultiTouchPenInput(VfxPenEvent &event);

    // handle long press event in keypad
    void onKeypadLongPressimeout(VfxTimer *timer);

// implementations
protected:

    // create and initialize a view panel
    VappGalleryViewerPanel* createViewerPanel();
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    inline panelID getLeftPanelIndex()
    {

        return (m_currentPanel + 2) % TOTAL_PANEL_NUM;
    }

    inline panelID getRightPanelIndex()
    {
        return (m_currentPanel + 1) % TOTAL_PANEL_NUM;
    }

    // returns panel adjacent to left of current panel
    VappGalleryViewerPanel* getPanel(PanelPosition panelPos);

    // cleanup resources used by a given panel.
    void clearPanel(VappGalleryViewerPanel *panel);
    // release all image resources
    void clearAllPanel();
    // VFX_TRUE if the panel haven't been assigned with the mediaIdx or not ready(decoding)
    VfxBool isPanelReady(VappGalleryViewerPanel *panel, MediaIndex mediaIdx);
    // VFX_TRUE if the panel is updated
    // VFX_FALSE if the panel is already displaying mediaIdx
    VfxBool updatePanelMedia(VappGalleryViewerPanel *panel, MediaIndex mediaIdx);
    void updatePanelFileInfoImpl(VappGalleryViewerPanel *panel, VfxBool isVideo);

    // VFX_TRUE if the enhancement has started
    // VFX_FALSE if the panel is already enhanced, or there is no need to enhance
    VfxBool enhancePanelMedia(VappGalleryViewerPanel *panel, MediaIndex mediaIdx);
    void onEnhanceResult(VappGalleryDecoderBase *sender, VappGalleryDecodeResult result);
    void stopEnhance();
    VfxBool canEnhanceMedia(MediaIndex mediaIdx);

    EnhanceMediaCheckResult enhancePanelMediaPreCheckImpl(VappGalleryViewerPanel *panel, MediaIndex mediaIdx);

#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_PARTIAL_ENHANCE_DECODE__
        void onPartialEnhnaceDecodeStart(VfxSize decodedLayerSize, VfxRect clipRect);
        void onPartialEnhnaceDecodeFinished(VappGalleryDecoderBase *sender, VappGalleryDecodeResult result);
#endif
        void onPartialEnhnaceDecodeCanceled();
        VfxRect m_enhanceChecksum;

    // single file case, see if input file is already verified.
    // if it is already verified
    void verifyInputFile();
    // cancel verifying operation
    void stopVerifyInputFile();
    // callback for receiving verify result
    void onVerifyResult(VappGalleryDecoderBase *sender, VappGalleryDecodeResult result);
    // set single file view panel according to verified result
    void displaySingleFileImage();

    // stop all decoding activities (preview, enhance, preload)
    void stopAllDecoding();

    VfxBool isAsyncMediaListScenario();
    VfxBool shouldReserveAdjacentPreview();

    // check if all panels have preview display. if not, start decoding them.
    void checkAllPanel(const VfxU32 line, VfxBool startEnhance = VFX_TRUE);
    // returns initial X-offset of a givent panel (left, current, right)
    // this considers the padding between panels
    VfxS32 getPanelInitialPos(PanelPosition panelPos);
    // restore panel to its initial position
    void snapPanelToInitialPosition(PanelPosition panelPos, VfxBool isAnim);
    // move panel to reveal next/previous media
    void shiftPanel(VfxBool isGoNext);
    // change the position of all visible panels.
    // mainly used for dragging
    void offsetVisiblePanels(VfxS32 offsetX, VfxBool isAnim);

    VappGalleryViewerPanel* getPanelByMediaIndex(MediaIndex index);

    VfxBool canGoNext();
    VfxBool canGoPrevious();
    MediaIndex getNextIndex()const;
    MediaIndex getPrevIndex()const;
    void showBallonIfMultiFile(const VfxId ballonTextId);

    // translate low-level pen input into high-level gesture
    VappGalleryGesture translateGesture(const VfxPenEvent &event);

    void onPreviewTimerCheck(VfxTimer *sender);
    void onShiftAnimationFinish(VfxTimer *sender);
    void onDecodeResult(VcpMenuPos index, VappGalleryDecodeResult result);

    // This functions binds to display current
    // media to current panel.
    void assignLockResultToPanel(MediaIndex mediaIndex,             // [IN] index of the media
                                 VappGalleryViewerPanel *panel,     // [IN] the panel to assign media
                                 const VappGalleryDecodeResult result,         // [IN] the result, e.g. panel may display error icon
                                 const VfxImageBuffer imgBuf);      // [IN] image buffer of the media if result is OK

    void updateZoomSliderByPanel(VappGalleryViewerPanel *panel);
    VfxBool canZoomPanel(VappGalleryViewerPanel *panel);            // returns VFX_TRUE if the panel content can zoom and ready to zoom.

    // Animated GIF handling
    VfxBool isAnimatedImage(MediaIndex mediaIdx);

    // MAV(multiple angle view) handling
    VfxBool isMAVImage(MediaIndex mediaIdx);
    VfxBool isMAVImage(const VfxWString &filePath);
    void getViewFrameCount(const VfxWString &filePath, VfxS32 &frameCount);

public:
    SlideshowStoppedEvent* getSlideshowStoppedEvent();
    // check if viewer is playing slideshow
    VfxBool isPlayingSlideshow() const;
    // check if current slideshow have orientation limitation.
    VfxBool getSlideshowOrientationLimit(VfxBool &hasOrientationLimit, VfxScrRotateTypeEnum &orientation);
    // return TRUE while play slideshow sucessfully
    VfxBool playSlideshow();
    void stopSlideshow();
    // handles slideshow playback
    void onSlideshowAnimFinish(VfxFrame *target,
                               VappGallerySlideshowBase::FinishType finishType,
                               VfxBool isCompleted);
    // create slideshow container
    void createSlideshowContainer();
    VappGallerySlideshowBase *createSlideshowInstance(VfxBool isTransition, VcpPageEffectType type);
    // destroy slideshow container and leave slideshow
    void closeSlideshowContainer();
    // should skip media or not
    VfxBool canSlideshowMedia(MediaIndex mediaIndex);
    // handles still image timer. when this timer ticked, start transition.
    void onSlideshowStillImageTimer(VfxTimer *source);
    // prepate next slideshow panel
    // VFX_TRUE if a decoding action is triggered or running
    VfxBool prepareNextSlideshowMediaPanel();
    // get next media index to display according to setting
    // note the index may repeat, loop or shuffled
    // INVALID_MEDIA_INDEX means there is no next playback index.
    MediaIndex getNextPlaybackIndex();
    // Adjust panel content for slideshow switch effect
    // e.g. turn off GIF animation
    void setupSlideshowPanel(VappGalleryViewerPanel *panel);

// implementations
private:
    void notifyGestureEvent(VappGalleryGesture gesture, VfxS32 index);
    void notifyCurrentPanelChanged(const VfxS32 currentIndex);
    void notifyProviderUpdatedEvent(const VfxS32 meidaCount);
    void notifyMediaPlayCommand(VfxWString &path);
    void notifyZoomSliderEvent(VfxBool isZooming);
    void notifyViewSliderEvent(VfxBool isDragging);
    void notifySlideshowStopped();
    void notifyStartDisplayMedia();

    // find the App which uses viewerCP
    VfxApp* getRootApp()const;
    // get screen rotation
    VfxScrRotateTypeEnum getScreenRotation() const;
    // test utility for IOT
    void sendCurrentViewedFilePathMsg();
    void sendFilePathMsg(const VcpMenuPos menuPos, const VfxS32 serialNum);

// data member
protected:
    VappImageViewerComponentOption m_option;
    // zoom slider
    VcpSlider *m_zoomSlider;
    VfxImageFrame *m_zoomInLabel;
    VfxImageFrame *m_zoomOutLabel;
    // keypad support
    VfxTimer *m_keypadLongPressTimer;
    VfxFloat m_zoomOffset;
    // MAV(Multi-Angle View) support
    VcpSlider *m_viewSlider;
    VfxFrame *m_viewPrevLabel;
    VfxFrame *m_viewNextLabel;
    VfxFrame *m_mavIconFrame;
    VfxBool m_isViewSliderDraging;
    VfxBool m_enableGSensorSupport; // VFX_FALSE, if disable g sensor support forcely
#ifdef __VAPP_MAV_MOTION_TRANSLATOR_SUPPORT__
    VappMavMotionTranslator* m_gSensor;
#endif
    VfxFrame* m_3dRedBlueImageIcon;
    VfxBool m_isDuringFileOperation;
    // viewer panel container (to maintain proper z-order)
    VfxFrame *m_viewerPanelContainer;
    // the data source
    IVappGalleryMediaList *m_mediaList;
    // focus (currently active) media
    MediaIndex m_currentIndex;
    VappGalleryViewerMediaState m_initState;
    // Panels that used to display a single image.
    VappGalleryViewerPanel *m_viewPanels[TOTAL_PANEL_NUM];
    // DRM consumer
    VappGalleryDRMConsumer *m_drmConsumer;
    // Enhanced image
    VappGalleryEnhancedImage *m_enhancedImage;
    // Image decoder for enhance
    VappGalleryImageThumbnail *m_enhancer;
    // Image decoder for checking if single-file case is a valid file.
    VappGalleryImageThumbnail *m_imageChecker;
    VappGalleryCachedImage *m_imageCheckerOutput;
    // timer for preview display (make sure each panel has decoded preview)
    VfxTimer *m_previewTimer;
    // timer for finishing panel shifting animation
    VfxTimer *m_panelShiftFinishTimer;
    // currently focused (active) Panels
    panelID m_currentPanel;
    // VFX_TRUE if we're zooming (dragging zoom slider)
    VfxBool m_isSliderZooming;
    // VFX_TRUE if a warning popup is already popped in a pen down-up period.
    // This flag is used to prevent generating too much
    // warning popup in a down-up period (e.g. move picture when reaching last picture)
    VfxBool m_warningPoppedDuringGesture;
    // VFX_TRUE if a warning popup is already popped for same current viewed image
    // both flags are reset while current panel is changed
    VfxBool m_hasShownLastPhotoHint; 
    VfxBool m_hasShownFirstPhotoHint;
    // for gesture parsing
    VappGalleryGestureTranslator *m_gestureTranslator;
    // for pan inertia
    VappGalleryInertiaPan m_inertiaPan;
    // for multitouch gesture support
    VfxBool m_isMultiTouchMode;
    VfxBool m_multiTouchZoomGesture;
    // for slideshow playback.
    // this is only used during playback
    VappGallerySlideshowBase *m_slideshowContainer;
    VfxTimer *m_slideshowStillImageTimer;
    VappGalleryShuffleIndex *m_shuffleIndex;
    SimpleBitSet m_slideshowBlackList;  // a bit is set if the corresponding MediaIndex is already played and cannot be played
    MediaIndex m_slideshowStartIndex;   // media index that starts playing slideshow
    MediaIndex m_slideshowCurrentIndex; // media index that is currently being displayed
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
    VappGallerySlideShowSetting m_slideshowSetting;
#endif
    GestureEvent m_signalGesture;
    CurrentPanelChangedEvent m_signalCurrentPanelChanged;
    ProviderUpdatedEvent m_signalProviderUpdated;
    MediaPlayCommandEvent m_signalMediaPlayCommand;
    ZoomSliderEvent m_signalZoomSlider;
    ViewSliderEvent m_signalViewSlider;
    SlideshowStoppedEvent  m_signalSideshowStopped;
    StartDisplayMediaEvent m_signalStartDisplayMedia;
};
#endif

#endif /* __VAPP_GALLERY_VIEWER_H__ */

