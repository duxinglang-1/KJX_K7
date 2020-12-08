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
 *  vapp_widget_gallery_viewer.h
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

#ifndef __VAPP_WIDGET_GALLERY_VIEWER_H__
#define __VAPP_WIDGET_GALLERY_VIEWER_H__

#include "mmi_features.h"

#if defined(__MMI_VUI_WIDGET_GALLERY__)

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"

#include "vcp_activity_indicator.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(__MMI_MAINLCD_480X800__)
#define VAPP_WIDGET_GALLERY_PANEL_ORI_POS_X                 193
#define VAPP_WIDGET_GALLERY_PANEL_ORI_POS_Y                 128
#define VAPP_WIDGET_GALLERY_PHOTO_FRAME_POS_X               11
#define VAPP_WIDGET_GALLERY_PHOTO_FRAME_POS_Y               11
#define VAPP_WIDGET_GALLERY_PHOTO_WIDTH                     276
#define VAPP_WIDGET_GALLERY_PHOTO_HEIGHT                    202
#define VAPP_WIDGET_GALLERY_PHOTO_RANDOM_X_RANGE            25
#define VAPP_WIDGET_GALLERY_PHOTO_RANDOM_Y_RANGE            3
#elif defined(__MMI_MAINLCD_320X480__) 
#define VAPP_WIDGET_GALLERY_PANEL_ORI_POS_X                 124
#define VAPP_WIDGET_GALLERY_PANEL_ORI_POS_Y                 90
#define VAPP_WIDGET_GALLERY_PHOTO_FRAME_POS_X               7
#define VAPP_WIDGET_GALLERY_PHOTO_FRAME_POS_Y               7
#define VAPP_WIDGET_GALLERY_PHOTO_WIDTH                     187
#define VAPP_WIDGET_GALLERY_PHOTO_HEIGHT                    138
#define VAPP_WIDGET_GALLERY_PHOTO_RANDOM_X_RANGE            14
#define VAPP_WIDGET_GALLERY_PHOTO_RANDOM_Y_RANGE            5
#elif defined(__MMI_MAINLCD_240X400__)  || defined(__MMI_MAINLCD_240X320__)
#define VAPP_WIDGET_GALLERY_PANEL_ORI_POS_X                 97
#define VAPP_WIDGET_GALLERY_PANEL_ORI_POS_Y                 64
#define VAPP_WIDGET_GALLERY_PHOTO_FRAME_POS_X               4
#define VAPP_WIDGET_GALLERY_PHOTO_FRAME_POS_Y               4
#define VAPP_WIDGET_GALLERY_PHOTO_WIDTH                     138
#define VAPP_WIDGET_GALLERY_PHOTO_HEIGHT                    100
#define VAPP_WIDGET_GALLERY_PHOTO_RANDOM_X_RANGE            13
#define VAPP_WIDGET_GALLERY_PHOTO_RANDOM_Y_RANGE            3
#else
#define VAPP_WIDGET_GALLERY_PANEL_ORI_POS_X                 124
#define VAPP_WIDGET_GALLERY_PANEL_ORI_POS_Y                 90
#define VAPP_WIDGET_GALLERY_PHOTO_FRAME_POS_X               7
#define VAPP_WIDGET_GALLERY_PHOTO_FRAME_POS_Y               7
#define VAPP_WIDGET_GALLERY_PHOTO_WIDTH                     187
#define VAPP_WIDGET_GALLERY_PHOTO_HEIGHT                    138
#define VAPP_WIDGET_GALLERY_PHOTO_RANDOM_X_RANGE            14
#define VAPP_WIDGET_GALLERY_PHOTO_RANDOM_Y_RANGE            5
#endif

#define VAPP_WIDGET_GALLERY_MAX_SLIDE_SHOW_FRAME    3
#define VAPP_WIDGET_GALLERY_MAX_IMAGE_FRAME         (VAPP_WIDGET_GALLERY_MAX_SLIDE_SHOW_FRAME+2)

#define VAPP_WIDGET_GALLERY_FADE_OUT_TIME                   2000
#define VAPP_WIDGET_GALLERY_FADE_IN_TIME                    2000


class VappGalleryMediaListMediaCache;
enum VappGalleryDecodeResult;
enum VappGalleryPrepareResult;
/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/***************************************************************************** 
 * VappWidgetGalleryViewerPanel
 *****************************************************************************/
class VappWidgetGalleryViewerPanel : public VfxImageFrame
{
    VFX_DECLARE_CLASS(VappWidgetGalleryViewerPanel);
    
// Constructor
public:
    VappWidgetGalleryViewerPanel();

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

// Method
public: 
    void setPanelId(VfxS32 id);
    VfxS32 getPanelId() const;
    void setPicIndex(VfxS32 id);
    VfxS32 getPicIndex() const;
    void setPrepared(VfxBool isPrepared);
    VfxBool getIsPrepared();
    void setDefaultPic();
    VfxBool isDefaultPic();
    void setErrorPic();
    void setBackgroundPic();
    void clear();
    void setRotation(const VfxFloat degree);
    void setPicImageContent(const VfxImageSrc &value);
    const VfxImageSrc getPicImageContent();
    void viewPhoto();

    // show loading indicator when decode photo
    void showLoading();

    // replace loading indicator with decoded photo
    void hideLoading();
    
    VfxBool isLoading();
    
// Variable
public:
    VfxBool m_isPanelPrepared;
    VfxS32  m_panelId;
    VfxS32  m_picIndex;
    VfxImageFrame   *m_imgPhoto;
    VcpActivityIndicator *m_indicator;
};


/***************************************************************************** 
 * VappWidgetGalleryViewer
 *****************************************************************************/
class VappWidgetGalleryViewer : public VfxFrame
{
    VFX_DECLARE_CLASS(VappWidgetGalleryViewer);

private:
// State enum
enum GalleryWidgetStateEnum
{
    STATE_INIT,     // Init state   : decode photos regardless of slide show timer
    STATE_ACTIVE    // Active state : change the next photo only after timeout
};

// Constructor
public:
    VappWidgetGalleryViewer();

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

// Method
public: 
    void createMediaList();
    VfxBool isAllowSlideShow();
    void startSlideShowTimer();
    void stopSlideShowTimer();
    void setDisableSlideShow(VfxBool disable);
    void setPauseSlideShow(VfxBool pause);
    void changeToNextPhoto();
    void viewCurrentPhoto();
    
    // set next picture index
    void setNextLockPicId(VfxS32 index);

    // record current pic id for SerializeView
    VfxS32 getFadeoutPicId();

    // record current file folder for SerializeView
    VfxWString getSelectedFolderPath();
    
private:
    void resetPanelPos(VappWidgetGalleryViewerPanel *panel);
    void onMediaListReady(VappGalleryPrepareResult prepareResult);
    void onDecodeResult(VcpMenuPos menuPos, VappGalleryDecodeResult result);
    void decodeResultHandler(const VappGalleryDecodeResult result, VfxS32 picIndex, const VfxImageBuffer imgBuf);
    void decodeFinishedHandler(VappWidgetGalleryViewerPanel *panel, VfxS32 picIndex, const VfxImageBuffer imgBuf, VfxBool isSuccess);
    void prepareDefaultPanel(VappWidgetGalleryViewerPanel *panel, VfxS32 picIndex);
    void preparePanel(VappWidgetGalleryViewerPanel *panel, VfxS32 picIndex, const VfxImageBuffer imgBuf);
    void onSlideShowTimeout(VfxTimer* pTime);
    void setImageBufferToPanel(VappWidgetGalleryViewerPanel *panel, VfxS32 picIndex, const VfxImageBuffer imgBuf);

    void tlFadeOutStoppedHandler(
        VfxBaseTimeline *timeline, 
        VfxBool isCompleted
    );

    void tlFadeInStoppedHandler(
        VfxBaseTimeline *timeline, 
        VfxBool isCompleted
    );

    VfxS32 getNextAvailablePanelId();
    VfxS32 getFadeOutPanelId();
    VfxS32 getFadeInPanelId();
    VappWidgetGalleryViewerPanel* getNextAvailablePanel();
    VappWidgetGalleryViewerPanel* getPanelById(VfxS32 id);
    VfxMsec getSlideShowTime();
    VfxS32 getNextPanelIdAfterIndex(VfxS32 index);
    void onFadeOutFinished(VfxFrame *frame, VfxBool isComplete);
    void panelAppearingControlHandler();
    void switchImgSrcBetweenPanels();
    void showDefaultPic();

    // rotate panel with random deg. and translate panel with random offset
    void transformPanel(VappWidgetGalleryViewerPanel* panel);

    // get next picture index
    VfxS32 getNextLockPicId();

    VfxBool isCacheEnough();

// Variable
public:
    VfxBool         m_prepareMemoryFail;
    
    // disalbe slide show when control bar exist
    VfxBool         m_disableSlideShow;

    // pause slide show after user press pause button
    VfxBool         m_pauseSlideShow;

    // used to determined the rotation direction, clockwise or anticlockwise
    VfxBool         m_rotateDirFlag;
    
    VfxS32          m_nextLockPicId;

    VfxS32          m_fadeOutPanelId;
    VfxS32          m_fadeInPanelId;

    // after lock image, it will assign to m_nextPanelId
    VfxS32          m_nextAvailablePanelId;
    VfxS32          m_totalPicNum;
    VfxS32          m_lockedCacheNum;
    VfxS32          m_totalCacheNum;  

    VfxS32          m_usedPanelNum;  

    // m_totalPanelNum = m_maxConcurrentShowingPanelNum 
    //                    + one fade in panel
    //                    + one backup panel which is used to decode previously
    VfxS32          m_totalPanelNum;    

    VfxS32          m_maxConcurrentShowingPanelNum;

    VfxWString      m_folderPath;  // the folder to scan
    VfxTimer        *m_timerSlideShow;

    // used to control white arrow animation
    VfxFloatTimeline    *m_tlFrameFadeOut;

    // used to control white arrow animation
    VfxFloatTimeline    *m_tlFrameFadeIn;

    VcpFrameEffect  *m_fadeOutEffect;
    VcpFrameEffect  *m_fadeInEffect;

    GalleryWidgetStateEnum          m_state;

    VappWidgetGalleryViewerPanel   *m_picPanel[VAPP_WIDGET_GALLERY_MAX_IMAGE_FRAME];
    VappGalleryMediaListMediaCache *m_mediaList;
};
#endif /* __MMI_VUI_WIDGET_GALLERY__ */
#endif /* __VAPP_WIDGET_GALLERY_VIEWER_H__ */

