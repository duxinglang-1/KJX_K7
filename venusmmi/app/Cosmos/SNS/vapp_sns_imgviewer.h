/*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_sns_imgviewer.h
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
#ifndef __VAPP_SNS_IMGVIEWER__
#define __VAPP_SNS_IMGVIEWER__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"

#ifdef __SOCIAL_NETWORK_SUPPORT__
#include "vapp_sns_base.h"
#include "vfx_frame.h"
#include "vfx_text_frame.h"
#include "vcp_text_view.h"
#include "vapp_sns_gprot.h"
#include "vapp_sns_factory.h"
#include "vapp_image_viewer_cp.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "SnsSrvGprot.h"
#ifdef __cplusplus
}
#endif

#ifdef __MMI_SNS_ALBUM__
#define __SNS_TURN_ALBUM_FUNC_ON__
#endif

class VappSnsBaseImgControl : public VfxControl
{
    VFX_DECLARE_CLASS(VappSnsBaseImgControl);
public:
    VfxSignal1 <VappSnsBaseImgControl *>m_signalClicked;
    
protected:
    virtual VfxBool onPenInput(VfxPenEvent & event);

private:
#if defined(__MMI_MAINLCD_480X800__)
    #define VAPP_SNS_IMGCTRL_TAP_DISTANCE_RADIUS        20
#else
    #define VAPP_SNS_IMGCTRL_TAP_DISTANCE_RADIUS        10
#endif
};

class VappSnsBaseImgViewer : public VappSnsBasePage, public IVappGalleryAsyncProvider
{
    VFX_DECLARE_CLASS(VappSnsBaseImgViewer);
public:
    VappSnsBaseImgViewer();
    VappSnsBaseImgViewer(VfxU32 provider, VfxS32 aListId, VfxS32 index, VfxS32 total, VfxWChar *name, VfxChar* photoId, VfxChar* albumId, VfxBool isCommentTappable, VfxChar *userId = NULL, VfxBool supportRotate = VFX_FALSE);
    VappSnsBaseImgViewer(VfxU32 provider, VfxChar* photoId, VfxChar *userId = NULL, VfxBool isCommentTappable = VFX_TRUE, VfxBool supportRotate = VFX_FALSE);

public:
    /* This signal is invoked in onExit() when image viewer was closed.
       So shouldn't do too many things in the callback */
    VfxSignal2 <VfxS32,              // [IN] current listId
                VfxS32>              // [IN] current index
        m_signalGetCurrentState;

public:
    // initialize the content provider
    // after provider is prepared, the total file count should be uptated
    virtual void prepare();
    virtual VfxBool isPrepared() const; 

    // check if content provider is dirty
    // if it's dirty, it should re-prepare 
    virtual VfxBool canCheckDirty();
    virtual VfxBool isDirty();
    
    // get total file count (sum of all forlders)
    virtual VfxU32 getTotalFileCount();

    // get file count in a list
    virtual VfxU32 getFileCount(VfxS32 listIndex);

    virtual VfxBool cancelFilePathQuery();
    virtual VfxBool cancelFilePathQuery(const VcpMenuPos index);
    
    // get file path by index
    // note getFilePath() is an async funciton since we need to query from Internet/SN
    // while file is ready, provider should call FileReadyCallback to update file path info according to the index
    virtual void getFilePath(const VcpMenuPos index, FileReadyCallback fileReadyCB, void* userData);
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackWard);
    virtual void onExit(VfxBool isBackward);
    virtual void onExited2();
    virtual void onEntered();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
    virtual void onBack();
    virtual void onRotate(const VfxScreenRotateParam &param);
    virtual void setBounds(const VfxRect &value);
    
protected:
    VfxFrame *m_titleBg;
    VfxTextFrame *m_albumName;
    VfxTextFrame *m_picIdx;
    VfxFrame *m_descBg;
    VcpTextView *m_desc;
    VappSnsBaseImgControl *m_imgFrame;
    VappImageViewerComponent *m_imgViewer;
    VcpIndicatorPopup *m_saving;

private:
    void onToolbarButtonTap(VfxObject *obj, VfxId id);
    void onDescriptionTap(VcpTextView *obj, VcpTextTapAreaEnum area, VcpRichTextFormat *format);
    void onDetectGesture(VappGalleryGesture gesture, VfxS32 currentPreviewIndex);
    void onCurrentPanelChanged(const VfxS32 currentIndex);
    void onHandleClicked(VappSnsBaseImgControl *obj);
    void handleObjectHidden();

    void hideAllFrames(VfxBool isHide);
    void disableToolbar(VcpToolBar *toolbar, VfxBool isDisabled);
    void setCurrentPhotoInfo(srv_sns_photo_struct* photo);
    void setAlbumName(VfxWChar* name);
    void updateTitleIndex();
    void createImageViewCp();
    
    void saveToLocal();
    
    srv_sns_photo_struct* LoadAlbum(VfxS32 index);
    void loadAlbumInfo();
    
    void queryPicture(VfxS32 index, FileReadyCallback queryCB, void *user_data);
    
    /* For get photo information */
    static mmi_ret onLoadPhotoCb(mmi_event_struct *param);
    /* For load album contents */
    static mmi_ret onLoadAlbumListCb(mmi_event_struct *param);
    /* For download picture */
    static mmi_ret onEvtHdlr(mmi_event_struct *param);
    /* For save to local */
    static mmi_ret onAsyncCopyCb(mmi_event_struct *param);
    static mmi_ret onLoadAlbumInfoCb(mmi_event_struct *param);

    void handleLoadPhoto(mmi_event_struct * param);
    void handleLoadAlbumList(mmi_event_struct * param);
    void handleLoadAlbumInfo(mmi_event_struct * param);
    void handleEvtHdlr(mmi_event_struct *param);

    void updateCustomizedToolBar(VfxId updatedId);
    void updateCustomizedToolBarStatus(VfxId updatedId);

    void postToCaller(VfxS32 index, VfxChar* path, VfxS32 err, void *user_data);

    void setUndecodePic();
private:
    #define SNS_MAX_RENAME_COUNTSTR_LEN 4 /* (50) <= 4 chars */
    #define SNS_MAX_RENAME_TIMES 50
    #define EXTEND_TOOLBAR_BUTTON_ID_BASE 1111
    #define CLR_DESC VfxColor(255, 80, 80, 80)
    #define IV_DEBUG_TAG 'IVwer'

    enum{
        IV_DEBUG_REQ = 0,
        IV_DEBUG_RSP
    };
    
    enum {
#ifdef __MMI_MAINLCD_480X800__
        ITEM_W = 480,
        ITEM_H = 800,
        ITEM_LAND_W = 800,
        ITEM_LAND_H = 480,
        
        STATUS_BAR_H = 38,
        TOOLBAR_H = 85,
        
        TITLE_H = 85,
        TITLE_LAND_H = 58,

        FONT_SIZE_ALBUM_NAME = 35,
        FONT_SIZE_PIC_COUNT = 26,
        FONT_SIZE_DESC = 21,
        
        ALBUM_NAME_LR_GAP = 14,
        ALBUM_NAME_LAND_LR_GAP = 16,
        ALBUM_NAME_T_GAP = 9,
        ALBUM_NAME_W = (ITEM_W - ALBUM_NAME_LR_GAP*2),
        ALBUM_NAME_LAND_W = ALBUM_NAME_W,
        ALBUM_NAME_H = (FONT_SIZE_ALBUM_NAME+2),

        PIC_COUNT_ALBUM_NAME_GAP = 1,
        PIC_COUNT_T_GAP = (ALBUM_NAME_T_GAP+ALBUM_NAME_H+PIC_COUNT_ALBUM_NAME_GAP),
        PIC_COUNT_W = ALBUM_NAME_W,
        PIC_COUNT_LAND_W = ITEM_LAND_W - ALBUM_NAME_LAND_W,
        PIC_COUNT_H = (FONT_SIZE_PIC_COUNT+2),

        DESC_TB_GAP = 12,
        DESC_LAND_T_GAP = 6,
        DESC_LAND_B_GAP = 12,
        DESC_LR_GAP = 14,
        DESC_LAND_LR_GAP = 16,
        DESC_W = (ITEM_W - DESC_LR_GAP*2),
        DESC_LAND_W = (ITEM_LAND_W - DESC_LAND_LR_GAP*2),
        DESC_MAX_H = (ITEM_H - TITLE_H*2 - DESC_TB_GAP*2),
        DESC_MIN_H = 100,
#elif __MMI_MAINLCD_320X480__
        ITEM_W = 320,
        ITEM_H = 480,
        ITEM_LAND_W = 480,
        ITEM_LAND_H = 320,
        
        STATUS_BAR_H = 24,
        TOOLBAR_H = 50,
        
        TITLE_H = 48,
        TITLE_LAND_H = 30,

        FONT_SIZE_ALBUM_NAME = 20,
        FONT_SIZE_PIC_COUNT = 14,
        FONT_SIZE_DESC = 14,
        
        ALBUM_NAME_LR_GAP = 14,
        ALBUM_NAME_LAND_LR_GAP = 10,
        ALBUM_NAME_T_GAP = 5,
        ALBUM_NAME_W = (ITEM_W - ALBUM_NAME_LR_GAP*2),
        ALBUM_NAME_LAND_W = ALBUM_NAME_W,
        ALBUM_NAME_H = (FONT_SIZE_ALBUM_NAME+2),

        PIC_COUNT_ALBUM_NAME_GAP = 1,
        PIC_COUNT_T_GAP = (ALBUM_NAME_T_GAP+ALBUM_NAME_H+PIC_COUNT_ALBUM_NAME_GAP),
        PIC_COUNT_W = ALBUM_NAME_W,
        PIC_COUNT_LAND_W = ITEM_LAND_W - ALBUM_NAME_LAND_W,
        PIC_COUNT_H = (FONT_SIZE_PIC_COUNT+2),

        DESC_TB_GAP = 8,
        DESC_LAND_T_GAP = 6,
        DESC_LAND_B_GAP = 8,
        DESC_LR_GAP = 8,
        DESC_LAND_LR_GAP = 10,
        DESC_W = (ITEM_W - DESC_LR_GAP*2),
        DESC_LAND_W = (ITEM_LAND_W - DESC_LAND_LR_GAP*2),
        DESC_MAX_H = (ITEM_H - TITLE_H*2 - DESC_TB_GAP*2),
        DESC_MIN_H = 74,
#else
        ITEM_W = 240,
    #ifdef __MMI_MAINLCD_240X320__
        ITEM_H = 320,
        ITEM_LAND_W = 320,
    #else
        ITEM_H = 400,
        ITEM_LAND_W = 400,
    #endif /* __MMI_MAINLCD_240X320__ */
        ITEM_LAND_H = 240,
        
        STATUS_BAR_H = 24,
        TOOLBAR_H = 45,
        
        TITLE_H = 42,
        TITLE_LAND_H = 26,

        FONT_SIZE_ALBUM_NAME = 16,
        FONT_SIZE_PIC_COUNT = 14,
        FONT_SIZE_DESC = 13,
        
        ALBUM_NAME_LR_GAP = 5,
        ALBUM_NAME_LAND_LR_GAP = 5,
        ALBUM_NAME_T_GAP = 3,
        ALBUM_NAME_W = (ITEM_W - ALBUM_NAME_LR_GAP*2),
        ALBUM_NAME_LAND_W = ALBUM_NAME_W,
        ALBUM_NAME_H = (FONT_SIZE_ALBUM_NAME+2),

        PIC_COUNT_ALBUM_NAME_GAP = 1,
        PIC_COUNT_T_GAP = (ALBUM_NAME_T_GAP+ALBUM_NAME_H+PIC_COUNT_ALBUM_NAME_GAP),
        PIC_COUNT_W = ALBUM_NAME_W,
        PIC_COUNT_LAND_W = ITEM_LAND_W - ALBUM_NAME_LAND_W,
        PIC_COUNT_H = (FONT_SIZE_PIC_COUNT+2),

        DESC_TB_GAP = 5,
        DESC_LAND_T_GAP = 5,
        DESC_LAND_B_GAP = 5,
        DESC_LR_GAP = 5,
        DESC_LAND_LR_GAP = 5,
        DESC_W = (ITEM_W - DESC_LR_GAP*2),
        DESC_LAND_W = (ITEM_LAND_W - DESC_LAND_LR_GAP*2),
        DESC_MAX_H = (ITEM_H - TITLE_H*2 - DESC_TB_GAP*2),
        DESC_MIN_H = 38,
#endif
    };

    VfxBool m_disableSwitchBalloon;
    VfxBool m_isFg;
    VfxBool m_stopCallback;
    // Custom tool bar controller
    VappSnsToolBarController *m_customizedTbCtrl;
    VfxS32 m_jobId;
    VfxS32 m_downIndex;
    VfxS32 m_downReqId;
    VfxS32 m_pListId;
    VfxS32 m_aListId;
    VfxS32 m_aInfoId;
    VfxBool m_prepare;
    VfxBool m_isCommentTappable;
    VfxBool m_supportRotate;
    VfxBool m_fromAlbum;
    VfxS32 m_index;
    VfxS32 m_loadIdx;
    VfxS32 m_total;
    VfxU32 m_provider;
    VfxChar *m_photoId;
    VfxChar *m_albumId;
    VfxChar *m_userId;
    VfxChar *m_name;
    VfxChar *m_path;
    VfxChar *m_descText;
    void *m_gUserData;   /* user data of gallery cp */
    FileReadyCallback m_queryCB;
    srv_sns_photo_struct* m_photo;
#ifdef __SNS_TURN_ALBUM_FUNC_ON__
    VappGalleryViewerMediaState m_initState;
#endif
};

#endif /* __SOCIAL_NETWORK_SUPPORT__ */

#endif /* __VAPP_SNS_IMGVIEWER__ */
