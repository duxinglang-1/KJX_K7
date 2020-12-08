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
 *  vapp_gallery_video.h
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

#ifndef __VAPP_GALLERY_VIDEO_H__
#define __VAPP_GALLERY_VIDEO_H__

#include "mmi_features.h"
#if defined(__MMI_GALLERY_SLIM__) && defined(__VAPP_GALLERY_ENABLE_VIDEO_MEDIA_LSIT__)
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_menu_popup.h"
#include "trc/vadp_app_trc.h"

#include "vapp_gallery_slim_data.h"
#include "vapp_gallery_slim_player.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappGalleryVideoPage : public VappGalleryPage, public IVcpGroupListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappGalleryVideoPage);
    
// Override VappGalleryPage
public:
    VappGalleryVideoPage();
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onUpdate();
    virtual void onExit(VfxBool isBackward);
    virtual void onExited2();
    virtual void onBack();

protected:
    virtual void onPageInactiveImpl();
    virtual void onPageInactived2Impl();

// method and event handler
public:
    void setupVideoMenu();

    void onItemTapped(VcpGroupListMenu *sender, VcpMenuPos index);

    void onItemLongTapped(VcpGroupListMenu *sender, VcpMenuPos index);

    void onItemSelectionChange(VcpGroupListMenu *sender, VcpMenuPos index, VcpListMenuItemStateEnum newState);
    
// data members
private:
    VappGalleryMediaListVideoInfo *m_mediaList;
    VcpGroupListMenu *m_videoMenu;
    VappGalleryDB *m_videoDB;
    VappGalleryMediaCacheFileSequence m_fileSequence;
    VcpBaseMenuViewState m_viewState; // restore folder view state after re-enter the page

// UI implementation
private:

    // create ordinary toolbar and set as bottom bar
    void createToolbar();

    // create multi-select toolbar and set as bottom bar
    void createSelectToolbar(VfxId mainCommandId);

    // create multi-select toolbar for Picker CUI (only OKAY)
    // and set as bottom bar
    void createCuiToolbar();

    // internal impelementation, used by createXXXToolbar
    typedef void (VappGalleryVideoPage::*ToolbarHandler)(VfxObject* sender, VfxId id);
    VcpToolBar* createToolbarImpl(const VfxId buttons[3], ToolbarHandler handlerMethod);

    void setupMediaList();
    void closeMediaList();
    void releaseMediaListForeground();
    // handles media list prepare result
    void onMediaListReady(VappGalleryPrepareResult prepareResult);

    // handles toolbar commands (normal state)
    void onToolbarCommand(VfxObject* sender, VfxId id);

    // handles long-tap popup menu (single-file)
    void onSingleItemMenuCommand(VcpMenuPopup* sender, VcpMenuPopupEventEnum evt, VcpMenuPopupItem *item);

    // handles toolbar commands (multi-select state)
    void onToolbarSelectCommand(VfxObject* sender, VfxId id);

    // handles CUI toolbar commands (multi-select case)
    void onCuiSelectCommand(VfxObject* sender, VfxId id);

    // cleanup & refresh state after multi-file operation finished (or cancelled)
    void onDeleteOperationDone(VfxObject* sender, VappGalleryFileOpResult result);

    // cleanup after multi-file operation finished (or cancelled)
    void onShareOperationDone(VfxObject* sender, VappGalleryFileOpResult result);

    // fileOP shrink memory handler, only work in UC app share in SLIM project 
    void onRequireResourceRelease();

    // query button name and button icon from toolbar button ID
    void getButtonNameImageById(VfxId id, VfxWString &name, MMI_IMG_ID &imgId);

    void onReloadListStart(VcpMenuPos mediaPos);

    void onReloadListFinished(VcpMenuPos mediaPos);

    void startRefreshTimer(const VfxBool start, const VfxU32 line);

// supporting IVappGalleryMediaList
public:
    void onDecodeResult(VcpMenuPos index, VappGalleryDecodeResult result);

// supporting list menu
public:
    // returns VFX_TRUE if the grid is in single or multi-select mode.
    // used by Video Picker CUI
    VfxBool isSelectOnlyMode() const;

    // enter multi-selection mode.
    // in this mode, the cell tap event is handled by grid itself.
    void beginMultiSelect();

    // returns VFX_TRUE if the grid is in multi-selection mode.
    VfxBool isMultiSelecting()const;
    
    // leave multi-selection mode.
    // all selection state will be cleared.
    void endMultiSelect();

    VfxBool isAllSelected();

    VfxBool isAnySelected();
    
    // Mark all or unmark all
    void setAllMarkState(VfxBool marked);



    // Provide custom cells for layout
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VcpMenuPos index,        // [IN] index of the item
        VfxFrame *parentFrame // [IN] parent frame of the custom content frame
        );

    // Check if there are thumbnails waiting to be decoded
    void onThumbRefresh(VfxTimer *source);

    // Notify the view is end of scrolling.
    void handleViewScrollStart(VcpBaseListMenu *menu);
    void handleViewScrollEnd(VcpBaseListMenu *menu);

    // Provide custom cells for layout
    virtual void closeItemCustomContentFrame(VcpMenuPos index,
                                             VcpListMenuCellClientBaseFrame *cell);

    virtual VfxU32 getGroupCount() const;
    
    virtual VfxBool hasGroupHeader(VfxS32 group) const;
    
    virtual VfxU32 getCount(VfxU32 group) const;

    virtual VfxBool getItemText(
        VcpMenuPos index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    virtual VfxBool getItemImage(
        VcpMenuPos index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        );

    virtual void closeItemImage(
        VcpMenuPos index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxImageSrc imgSrc               // [IN] the image resource
        );

    virtual VcpListMenuItemStateEnum getItemState(
        VcpMenuPos index   
        ) const;

// implementation of ListMenu & multi-selection
private:
    SimpleBitSet            m_selectedSet;
    VfxBool                 m_isScrolling;
    VfxBool                 m_isMultiSelecting;
    VfxBool                 m_isExit;       // use dummy content when page onExit() is called
    VappGalleryMultiFileOperationUI *m_multiFileOp;
    VfxTimer                *m_thumbRefreshTimer;
    VfxWeakPtr<VappGallerySingleFileMenuPopup> m_singleFilePopup;
};

class VappGalleryVideoMenuItemFrame : public VcpListMenuCellIconTripleTextFrameEx
{
public:
    VappGalleryVideoMenuItemFrame();

    // override layout method to customize thumbnail postion
    virtual void onLayoutElements();

    VfxBool getQueryFinished();

    void setQueryFinished(VfxBool finished);

    VfxBool isContentReady();

    vcui_gallery_media_state_enum getContentDecodeState() const;

private:

    // VFX_TRUE if this cell has all info (thumb, duration...)
    // filled, and no longer waiting for update
    VfxBool m_queryFinished;
};

#endif /* __VAPP_GALLERY_ENABLE_VIDEO_MEDIA_LSIT__ */
#endif /* __VAPP_GALLERY_VIDEO_H__ */


