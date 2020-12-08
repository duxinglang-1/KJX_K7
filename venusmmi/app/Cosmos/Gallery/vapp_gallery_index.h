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
 *  vapp_gallery_index.h
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

#ifndef __VAPP_GALLERY_INDEX_H__
#define __VAPP_GALLERY_INDEX_H__


/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_gallery_db.h"
#include "vapp_gallery_player.h"
#include "vapp_gallery_picture.h"
#include "vapp_gallery_setting.h"

/*****************************************************************************
 * Enum and constants
 *****************************************************************************/
enum PageName
{
    PN_MY_SHOOTING = 'SHOT',
    PN_MY_PICTURE = 'PICT',
    PN_MY_VIDEO = 'VIDO',
    PN_WEB_ALBUM = 'WEBB',
    PN_SETTING = 'SETT',

    PN_INVALID = -1,
};

/*****************************************************************************
 * Foward declaration
 *****************************************************************************/
class VappGalleryLastPlayFrame;
class IVappGalleryMediaCollection;
class VappGalleryCollectionSetting;
typedef IVappGalleryMediaCollection* (*PfnCollectionFactory)(PageName name, VfxObject *parent, VfxApp *app);

/*****************************************************************************
 * Class
 *****************************************************************************/
// This data structure records differnt menu items in index menu.
class VappGalleryIndexMenuItem
{
public:
    PageName pageName;
    PfnCollectionFactory itemFactory;
    MMI_ID captionStrID;
    MMI_IMG_ID defaultImgID;
    MMI_IMG_ID badgeImgID;
};

class VappGalleryCollectionSetting
{
public:
    VappGalleryCollectionSetting():
        m_pDB(NULL)
    {
        // default no extra filters,
        // use collection defaults.
        FMGR_FILTER_INIT(&m_filter);
        FMGR_FILTER_SET_ALL(&m_filter);

        // read default setting from global option
        VappGalleryStorageSetting setting;
        m_storage = setting.getDefaultStorage();
    }

    U8 getDefaultDrive()
    {
        const U8 drv = srv_fmgr_drv_get_letter_by_type(m_storage);
        return drv;
    }

public:
    srv_fmgr_drv_type_enum m_storage;
    FMGR_FILTER m_filter;
    VappGalleryDB *m_pDB;
};


// This MediaCollection class represents
// "My Photo", "My Video", ...
// It also responsible for generating description text,
// and query & cache related thumbnail resources.
class IVappGalleryMediaCollection
{
public:
    enum QueryResult
    {
        DONE,
        QUERYING,
        ERROR,
    };

    typedef VfxSignal2<VfxU32, QueryResult> DescriptionUpdateSignal;
    typedef VfxSignal2<VfxU32, QueryResult> ThumbnailUpdateSignal;

public:
    virtual void reset(const VappGalleryCollectionSetting &setting) = 0;
    virtual void destroy() = 0;

    // start query procedure
    virtual VfxBool startQuery() = 0;
    // force cancel query procedure.
    // it does nothing if the query is already finished
    virtual void stopQuery() = 0;
    // check if query is already finished (whether sucess or not)
    virtual VfxBool isQueryFinished() = 0;

    virtual void releaseLists() = 0;

    virtual QueryResult queryDescriptionCount(VfxU32 &count) = 0;
    virtual QueryResult queryDescription(VfxU32 index, VfxWString &description) = 0;

    // IVappGalleryMediaCollection is responsible for keeping
    // image source resources.
    virtual QueryResult queryThumbnailCount(VfxU32 &count) = 0;
    virtual QueryResult lockThumbnail(VfxU32 index, VfxImageSrc &imgSrc) = 0;

    // For MediaCollections, thumbnails are freed altogether.
    virtual void unlockAllThumbnail(VfxU32 index, VfxImageSrc &imgSrc) = 0;

    // can be connected to
    // YouClass::onQueryUpdate(VfxU32 descIndex, QueryResult res);
    virtual DescriptionUpdateSignal* getDescriptionUpdateSignal() = 0;
    virtual ThumbnailUpdateSignal* getThumbnailUpdateSignal() = 0;
};

class VappGalleryIndexPage : public VappGalleryPage, public IVcpListMenuContentProvider, public IVappGalleryMenuUpdatable
{
    VFX_DECLARE_CLASS(VappGalleryIndexPage);

public:
    static const VfxS32 INDEX_MENU_ITEM_COUNT = 3;  // Shooting, Picture, and Video.
    static const VfxS32 INDEX_MENU_ITEM_COUNT_CUI = 2; // Shooting, and only one of Picture and Video

// Override
public:
    VappGalleryIndexPage();
    virtual void onInit();
    virtual void onDeinit();
    virtual void onUpdate();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onExit(VfxBool isBackward);
    virtual void onExited2();

    void onDelayEntered(VfxTimer *timer);

// Implement IVcpListMenuContentProvider
public:
    virtual VfxU32 getCount() const;
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;

    // Provide custom layout cells
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(VfxU32 index, VfxFrame *parentFrame);
    virtual void closeItemCustomContentFrame(VfxU32 index, VcpListMenuCellClientBaseFrame *cell);

// Implement IVappGalleryMenuUpdatable
public:
    virtual VfxRect getViewRect();

    virtual VfxBool needUpdate(
                        const VcpMenuPos &pos,
                        VfxFrame *frame);

    virtual VfxBool updateMenuCell(
                        const VcpMenuPos &pos,
                        const VfxFrame *frame,
                        VfxBool canEnhance);

// methods
public:
    virtual void refreshStorage(VfxBool directRefresh);

protected:
    void onToolbarCommand(VfxObject *sender, VfxId id);
    void onIndexItemTapped(VcpListMenu *sender, VfxU32 index);
    void onGotoPage(PageName pageID);
    void onSelectStorage(VfxObject *sender, VfxId btnId);

    // returns Picker CUI instance if hosted
    // under it. NULL if hosted under ordinary APP
    VcuiGalleryPickerBase *getParentPickerCUI() const;

    // returns Picker CUI instance if hosted
    // under it. NULL if hosted under ordinary APP
    VcuiGalleryImagePicker *getParentImagePickerCUI() const;

    // returns Picker CUI instance if hosted
    // under it. NULL if hosted under ordinary APP
    VcuiGalleryVideoPicker *getParentVideoPickerCUI() const;

    // create Page instnaces from a given name
    // and perform page-specific initialization
    VfxPage* createPageFromName(PageName name);

    void createLastPlayPanel();

    void createStorageSelectionTab(
                    VfxBool updateStorage    // VFX_TRUE means automatically update storage. Otherwise keep current focus.
                    );

    // create Page instances from index menu index
    PageName getPageNameFromCellIndex(VfxU32 index);

    // retrieve item info from the index
    VappGalleryIndexMenuItem* getItemInfoFromIndex(VfxS32 index);

    void onDescriptionUpdate(VfxU32 descIndex, IVappGalleryMediaCollection::QueryResult result);
    void onCollectionUpdate(VfxU32 descIndex, IVappGalleryMediaCollection::QueryResult result);

    // only update page message (does not requrie FG memory)
    // VFX_FALSE is returned if no further update is required.
    VfxBool handleStorageChangeLite(VappGalleryStorageSetting &storageSetting);

    // initializes DB &  (requires FG memory)
    void handleStorageChange(VappGalleryStorageSetting &storageSetting);

    // prepare buffer that is used to display last play video thumbnail
    void allocLastPlayInfoBuffer();
    void freeLastPlayInfoBuffer();

    // handle user tapping last played video
    void onLastPlayTapped(VfxObject *lastPlay, VfxId btnId);

    static mmi_ret onDevicePlugInOut(mmi_event_struct *param);
    mmi_ret handleDevicePlugInOut(mmi_event_struct *param);

private:
    VappGalleryDB *m_galleryDB;
    VappGalleryLastPlayFrame *m_lastPlayPanel;          // last play panel
    VcpListMenu *m_indexMenu;                           // the menu component
    VappGalleryMenuUpdater *m_updater;                  // menu update logic
    VfxBool m_querying;                                 // VFX_TRUE if some collection is being queried.
    VfxBool m_shouldRefreshOnEnter;                     // VFX_TRUE if we should refresh the storage upon re-enter
    IVappGalleryMediaCollection *m_collections[INDEX_MENU_ITEM_COUNT];
    VfxS32 m_itemIndices[INDEX_MENU_ITEM_COUNT];          // map item order to index in g_indexMenuItems
    ivd_db_video_result_last_play_info m_lastPlayVideoInfo;

    VfxTimer *m_delayEnteredTimer;

// Index item list definition
private:
    static VappGalleryIndexMenuItem g_indexMenuItems[INDEX_MENU_ITEM_COUNT];
};

class VappGalleryLastPlayFrame : public VcpImageButton
{
public:
    VappGalleryLastPlayFrame();

// override
public:
    virtual void onInit();

// method
public:
    void setInfo(const ivd_db_video_result_last_play_info &videoInfo);

// data member
private:
    VfxFrame *m_thumbnail;
    VfxTextFrame *m_caption;
    VfxTextFrame *m_filename;
    VfxTextFrame *m_duration;
    VfxTextFrame *m_bookmark;
};

// This class represents thumbnail pile in the index menu
class VappGalleryIndexCollage : public VfxFrame
{
public:
    VappGalleryIndexCollage();

public:
    virtual void onInit();

public:
    void setAndDisplayCollageSources(const VfxImageSrc &front, const VfxImageSrc &back);
    void setAndDisplayDefaultIcon(VfxId defaultIconID);
    void setBadge(VfxId badgeIconID);

private:
    VfxFrame *m_thumbGroup;         // group of thumbnail related frames
    VfxFrame *m_frontThumb;         // front thumbnail image itself. Use VfxFrame to avoid auto-resize.
    VfxFrame *m_backThumb;          // back thumbnail (mostly overlapped by front thumb)
    VfxImageFrame *m_frontBorder;   // round-cornered border of the thumbnail
    VfxImageFrame *m_backBorder;    // round-cornered border of the thumbnail in the back
    VfxImageFrame *m_imgBadge;      // badge is the small "camera" or "play icon" on thumbnail
    VfxBool m_isDisplayCollage;
};

#endif /* __VAPP_GALLERY_INDEX_H__ */

