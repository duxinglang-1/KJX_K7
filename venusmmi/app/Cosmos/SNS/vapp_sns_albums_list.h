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
 *  vapp_sns_albums_list.h
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifndef __VAPP_SNS_ALBUMS_LIST_H__
#define __VAPP_SNS_ALBUMS_LIST_H__

#include "mmi_features.h"

#ifdef __MMI_SNS_ALBUM__
#include "vapp_sns_base.h"
#include "vcp_indicator_popup.h"
#include "vcp_text_view.h"
#include "vcp_photo_border_frame.h"
#include "vapp_sns_gprot.h"
#include "vapp_sns_base_cp.h"
#include "vapp_media_grid_cp.h"
#include "vapp_media_list.h"
#include "vapp_gallery_data.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "SnsSrvGprot.h"
#ifdef __cplusplus
}
#endif

#define VAPP_SNS_MAX_PHOTOS 90

class VappSnsPicGridsView;

class VappSnsAlbumsListPage : public VappSnsBasePage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappSnsAlbumsListPage);

public:
    VappSnsAlbumsListPage();
    VappSnsAlbumsListPage(VfxU32 provider, VfxChar* userId, VfxBool isAutoClose = VFX_FALSE, VfxBool isEmbeddedInTab = VFX_FALSE);
    
protected:
    virtual void onInit();
    virtual void onDeinit();

    virtual void onEntered();
    virtual void onExited2();

    virtual void buttonTap(VfxObject *obj, VfxId buttonId);
    virtual void bottomMarginFrameTap(VcpTextView *obj, VcpTextTapAreaEnum area, VcpRichTextFormat *format);
    virtual void listItemTap(VcpListMenu *list, VfxU32 index);
    
public:
    // <group DOM_ListMenu_IVcpListMenuContentProvider_Overridable>
    virtual VfxU32 getCount() const;

    virtual VfxBool getMenuEmptyText(VfxWString & text,VcpListMenuTextColorEnum & color);

    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(VfxU32 index, VfxFrame *parentFrame);
    virtual void closeItemCustomContentFrame(VfxU32 index, VcpListMenuCellClientBaseFrame * cell);
    
private:
    void onViewMoreTap(VfxObject *obj, VfxId buttonId);
    void onBottomMarginFrameTap(VcpTextView *obj, VcpTextTapAreaEnum area, VcpRichTextFormat *format);
    void onListItemTap(VcpListMenu *list, VfxU32 index);
    void onViewScrollStart(VcpBaseListMenu* list);
    void onViewScrollEnd(VcpBaseListMenu* list);
    
    void showAlbumsList();
    VfxS32 loadIndex(VfxS32 index);
    void updateList(VfxS16 start_index = -1, VfxS16 end_index = -1, VfxBool changed = VFX_FALSE);
    void updateIndex(VfxS16 index);
    void searchNewLoadIndex(VfxS16 start_index, VfxS16 end_index);

    VcpIndicatorPopup *popup;
private:
    static mmi_ret onLoadListCb(mmi_event_struct *param);
    static mmi_ret onEvtHdlr(mmi_event_struct *param);
    void handleEvtHdlr(mmi_event_struct *param);
    void handleLoadList(mmi_event_struct *param);
protected:
    VcpTitleBar *m_title;
    VcpToolBar *m_toolbar;
    VcpListMenu *m_list;
    VcpButton *m_button;
    VappSnsItemViewMoreCell *m_textView;

private:
    VfxBool m_isEmbeddedInTab;
    VfxBool m_setAutoClose;
    VfxBool m_scrolling;
    VfxBool m_doRefresh;
    VfxS32 m_downIdx;
    VfxS32 m_downReqId;
    VfxS32 m_listId;
    VfxS32 m_latest_req_index;
    VfxS32 m_total_album_count;
    VfxS32 m_loadIdx;
    srv_sns_account_struct* m_account;
    VfxU32 m_provider;
    VfxChar *m_userId;
    VfxU8 *m_updateArray;
    VfxS32 m_arraySize;
};

class VappSnsAlbumCell : public VcpListMenuCellClientBaseFrame
{
    VFX_DECLARE_CLASS(VappSnsAlbumCell);
public:
    VappSnsAlbumCell();
    
public:
#ifdef __MMI_MAINLCD_480X800__
    const static VfxS32 CELL_H = 116;
#elif __MMI_MAINLCD_320X480__
    const static VfxS32 CELL_H = 70;
#else
    const static VfxS32 CELL_H = 58;
#endif
    
    VappSnsAsyncPhotoBorderFrame* getPhotoBorderFrame();
    VfxTextFrame* getMainText();
    VfxTextFrame* getHintText();
    void setAlbum(srv_sns_album_struct* album);
public:
    // <group DOM_ListMenu_VcpListMenuCellClientBaseFrame_Overridable>
    // Create the elements (text, images...) in the client frame, sub-class should override this virtual function to create its own elements
    virtual void onCreateElements();

    // <group DOM_ListMenu_VcpListMenuCellClientBaseFrame_Overridable>
    // Close the elements (text, images...) in the client frame, sub-class should override this virtual function to close its own elements
    virtual void onCloseElements();

    // <group DOM_ListMenu_VcpListMenuCellClientBaseFrame_Overridable>
    // Layout the elements (text, images...) in the client frame
    virtual void onLayoutElements();

    // <group DOM_ListMenu_VcpListMenuCellClientBaseFrame_Overridable>
    // Get the latest data of the elements (text, images...) from content provider 
    virtual void onUpdateElements();

protected:
    enum {
#ifdef __MMI_MAINLCD_480X800__
        ITEM_W = 420,

        FONT_SIZE_CAPTION = 35,
        FONT_SIZE_DESC = 26,        

        FRONT_THUMB_W = 86,
        FRONT_THUMB_H = 86,
        THUMB_MARGIN_L = 14,
        THUMB_MARGIN_R = 16,
        THUMB_MARGIN_T = (CELL_H-FRONT_THUMB_H)/2,

        TEXT_MARGIN_L = (THUMB_MARGIN_L+FRONT_THUMB_H+THUMB_MARGIN_R),
        TEXT_W = (ITEM_W-TEXT_MARGIN_L-THUMB_MARGIN_L),
        TEXT_CAPTION_H = (FONT_SIZE_CAPTION+2),
        TEXT_DESC_H = (FONT_SIZE_DESC+2),
        TEXT_CAPTION_COLOR = 0xff151515,
        TEXT_DESC_COLOR = 0xff505050,

        PAD_TWO_LINE = 0,

        TEXT_CAPTION_MARGIN_T = ((CELL_H-TEXT_CAPTION_H-PAD_TWO_LINE-TEXT_DESC_H)/2),
        TEXT_DESC_MARGIN_T = (TEXT_CAPTION_MARGIN_T+TEXT_CAPTION_H+PAD_TWO_LINE)
#elif __MMI_MAINLCD_320X480__
        ITEM_W = 320,

        FONT_SIZE_CAPTION = 20,
        FONT_SIZE_DESC = 14,
        
        FRONT_THUMB_W = 56,
        FRONT_THUMB_H = 56,
        THUMB_MARGIN_L = 8,
        THUMB_MARGIN_R = 8,
        THUMB_MARGIN_T = (CELL_H-FRONT_THUMB_H)/2,

        TEXT_MARGIN_L = (THUMB_MARGIN_L+FRONT_THUMB_H+THUMB_MARGIN_R),
        TEXT_W = (ITEM_W-TEXT_MARGIN_L-THUMB_MARGIN_L),
        TEXT_CAPTION_H = (FONT_SIZE_CAPTION+2),
        TEXT_DESC_H = (FONT_SIZE_DESC+2),
        TEXT_CAPTION_COLOR = 0xff151515,
        TEXT_DESC_COLOR = 0xff505050,

        PAD_TWO_LINE = 0,

        TEXT_CAPTION_MARGIN_T = ((CELL_H-TEXT_CAPTION_H-PAD_TWO_LINE-TEXT_DESC_H)/2),
        TEXT_DESC_MARGIN_T = (TEXT_CAPTION_MARGIN_T+TEXT_CAPTION_H+PAD_TWO_LINE)
#else
        ITEM_W = 240,

        FONT_SIZE_CAPTION = 18,
        FONT_SIZE_DESC = 13,
        
        FRONT_THUMB_W = 45,
        FRONT_THUMB_H = 45,
        THUMB_MARGIN_L = 5,
        THUMB_MARGIN_R = 5,
        THUMB_MARGIN_T = (CELL_H-FRONT_THUMB_H)/2,

        TEXT_MARGIN_L = (THUMB_MARGIN_L+FRONT_THUMB_H+THUMB_MARGIN_R),
        TEXT_W = (ITEM_W-TEXT_MARGIN_L-THUMB_MARGIN_L),
        TEXT_CAPTION_H = (FONT_SIZE_CAPTION+2),
        TEXT_DESC_H = (FONT_SIZE_DESC+2),
        TEXT_CAPTION_COLOR = 0xff151515,
        TEXT_DESC_COLOR = 0xff505050,

        PAD_TWO_LINE = 0,

        TEXT_CAPTION_MARGIN_T = ((CELL_H-TEXT_CAPTION_H-PAD_TWO_LINE-TEXT_DESC_H)/2),
        TEXT_DESC_MARGIN_T = (TEXT_CAPTION_MARGIN_T+TEXT_CAPTION_H+PAD_TWO_LINE)
#endif
    };

    VfxTextFrame *m_caption;
    VfxTextFrame *m_hint;
    VappSnsAsyncPhotoBorderFrame *m_image;

private:
    VfxChar *m_name;
    VfxChar *m_thumbnail;
    VfxU32 m_timestamp;
};

class VappSnsPicGridsView : public VappSnsBasePage, public IVappGalleryAsyncProvider
{
    VFX_DECLARE_CLASS(VappSnsPicGridsView);

public:
    VappSnsPicGridsView();
    VappSnsPicGridsView(VfxU32 provider, VfxS32 aListHdlr, VfxChar* albumId, VfxChar* albumName, VfxS32 index, VfxS32 count, VfxBool isCommentTappable);

public:
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
    
    virtual void setBounds(const VfxRect &value);
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onExited2();
    virtual void onEnter(VfxBool isBackWard);
    virtual void onEntered();

protected:
    VfxWeakPtr<VappMediaGridComponent> m_grid;
    VappGalleryMediaListAsync* m_mediaList;
    
private:
    srv_sns_photo_struct* loadAlbumList(VfxS32 index);
    void getThumbPath(VfxS32 index, FileReadyCallback queryCB, void *user_data);

    static mmi_ret onEvtHdlr(mmi_event_struct *param);
    static mmi_ret onLoadAlbumListCb(mmi_event_struct *param);
    void handleEvtHdlr(mmi_event_struct *param);
    void handleLoadAlbumList(mmi_event_struct *param);
    void onMediaListReady(VappGalleryPrepareResult prepareResult);
    void onThumbTapped(VcpMenuPos tappedPos, VfxFrame* thumbTapped);
private:
#ifdef __MMI_MAINLCD_480X800__
    #define EMPTY_FONT_SIZE 30
#elif __MMI_MAINLCD_320X480__
    #define EMPTY_FONT_SIZE 20
#else
    #define EMPTY_FONT_SIZE 16
#endif

    VfxU32 m_provider;
    VfxBool m_isCommentTappable;
    VfxBool m_stopCallback;
    VfxBool m_prepared;
    VfxS32 m_downReqId;
    VfxS32 m_count;
    VfxS32 m_downloadIdx;
    VfxS32 m_loadIdx;
    VfxS32 m_aListHdlr;
    VfxChar *m_albumId;
    VfxChar *m_albumName;
    void *m_gUserData;
    FileReadyCallback m_queryCB;
};
#endif /* __MMI_SNS_ALBUM__ */

#endif /* __VAPP_SNS_ALBUMS_LIST_H__ */
