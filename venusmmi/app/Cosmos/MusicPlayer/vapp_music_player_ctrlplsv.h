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
 *  vapp_music_player_ctrlplsv.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  FTO Music Player PLSV control and ListMenuContentProvider
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"
#ifdef __COSMOS_MUSICPLY__

#ifndef __VAPP_MUSIC_PLAYER_CTRLPLSV_H__
#define __VAPP_MUSIC_PLAYER_CTRLPLSV_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_music_player.h"
#include "vapp_music_player_datatype.h"
#include "vapp_music_player_ctrlmediacache.h"
#include "vapp_music_player_include.h"

extern "C"
{
#include "PlstSrvGprot.h"
}

typedef struct
{
    VfxU32 ID;
    VfxU32 index;
    srv_plst_media_details_struct info;
    VfxBool hasInfo;
    VfxBool titleOnly;    
} ListItemDataStruct;

typedef struct
{
    ViewTypeEnum viewType;
    VfxS32 plstID;
    VfxS32 hlIdx;
    VfxS32 preHlIdx;
} HighLightInfoStruct;

/***************************************************************************** 
 * Music Player Control componet: Playlist Service Control class
 *****************************************************************************/

class VappMusicPlayerContentProvider;
class VappMusicPlayerService;

class VappMusicPlayerCtrlPLSV : public VfxObject
{
    VFX_DECLARE_CLASS(VappMusicPlayerCtrlPLSV);

// Variables
private:
    VappMusicPlayerContentProvider *m_parent;
    VappMusicPlayerService *m_mplayerSrv;
    VfxS32 m_srvHandle;
    VfxBool m_isReady;
    ViewTypeEnum m_viewType;
    VfxU32 m_itemCount;
    VfxS32 m_activeIdx;
    VfxU32 m_activeID;
    srv_plst_media_details_struct m_activeInfo;
    KAL_ADM_ID m_admID;
    void *m_memPtr;
    U8 *m_tempBuffer;
    VfxObject *m_cbReceiver;
    srv_plst_repeat_enum m_repeatState;
    srv_plst_shuffle_enum m_shuffleState;
    VfxBool m_waitSearchResult;
    
// Constructor / Destructor
public:
    VappMusicPlayerCtrlPLSV() :
        m_parent(NULL),
        m_mplayerSrv(NULL),
        m_srvHandle(0),
        m_isReady(VFX_FALSE),
        m_viewType(VIEW_TYPE_NONE),
        m_itemCount(0),
        m_activeIdx(-1),
        m_activeID(0),
        m_admID(0),
        m_memPtr(NULL),
        m_tempBuffer(NULL),
        m_cbReceiver(NULL),
        m_repeatState(SRV_PLST_REPEAT_OFF),
        m_shuffleState(SRV_PLST_SHUFFLE_OFF),
        m_waitSearchResult(VFX_FALSE)
        {};

public:
    virtual void onInit();
    virtual void onDeinit();

// Implementations
private:
    void PLSVCallback(srv_plst_cb_evt_enum cb_event, S32 result, VfxU32 ca_para_2);
    void PLSVHandleChanged(VfxS32 handle);

// Public Methods
public:
    void initRepeatShuffle();
    void saveRepeatShuffle();
    void setCBReceiver(VfxObject *obj);
    void setIsReady(VfxBool isReady);
    VfxBool getIsReady();
    VfxU32 getCount() const;
    VfxU32 getCountFromPLSV() const;
    VfxU32 getFixedCount(const ViewTypeEnum viewType, const VfxU32 index) const; // Get count under specific view
    void updateCount();
    void updateCount(VfxU32 count);
    void getID(VfxU32 index, VfxU32 &ID);
    VfxBool getTitle(const VfxU32 index, srv_plst_list_get_display_struct &displayStruct) const;
    VfxBool getDetailInfo(VfxU32 index, srv_plst_media_details_struct *infoStruct, VfxBool getTitleOnly = VFX_FALSE);
    VfxBool getDetailInfoByID(VfxU32 ID, srv_plst_media_details_struct *infoStruct, VfxBool getTitleOnly = VFX_FALSE );
    VfxBool getCurrDetailInfo(srv_plst_media_details_struct *infoStruct);
    void getFilePath(VfxU32 index, VfxWString &filePath);
    void getAlbumCoverPathBySongID(VfxU32 ID, VfxWString &filePath);
    void setActiveNoUpdateDB(VfxU32 index);
    void setActiveToDBUseCurrent(void);
    srv_plst_active_list_enum getActiveListType();  
    VfxBool isPlayingFavorite();
    void getAlbumArtistName(VfxU32 ID, VfxWString &name);
    VfxU32 getHintCount(VfxU32 index, srv_plst_view_type_enum getCountType);
    void getContext(srv_plst_get_cntx_param_struct inParam, VfxWString &context);
    VfxS32 getAlbumCoverAsync(srv_plst_list_get_display_struct *displayStruct);
    void getAlbumCoverAsyncCancel();
    VfxU32 getActiveCount() const;
    void updateActiveCount();
    VfxU32 getActiveIndex() const;
    VfxU32 getActiveIndexFromPLSV() const;
    void updateActiveIndex() const;
    VfxU32 updateActiveID() const;
    VfxS32 getActiveAlbumIndex() const;
    void setDuration(VfxU32 ID, VfxU32 duration);
    void resetPLSV();
    void refreshDB();
    void refreshDBCancel();
    void resetDB();
    VfxResId getErrorStrId(VfxS32 errorCode);
    void setTempBuffer();
    void clearTempBuffer();
    void selectStart();
    void selectEnd();
    void selectAll();
    void deselectAll();
    void select(VfxU32 index);
    void deselect(VfxU32 index);
    VfxBool isSelected(VfxU32 index);
    void del(VfxU32 index);
    void delSelected();
    VfxU32 delCancel();
    void configDefaultPlaylist();
    VfxU32 getDefaultPlaylistType(VfxU32 index);
    void createPlaylist(VfxWString name);
    VfxBool isPlaylistExist(VfxWString name);
    void addToPlaylist(VfxU32 index, VfxU32 playlistIdx);
    void addSelectedToPlaylist(VfxU32 playlistIdx);
    void addToPlaylistCancel();
    void renamePlaylist(VfxWString name, VfxU32 playlistIdx);
    VfxBool getPlaylistIndexByName(VfxWString &name, VfxU32 *playlistIdx);
    VfxBool isActiveSongInFavorite();
    void addActiveSongToFavorite();
    void removeActiveSongFromFavorite();
    void rearrangeStart();
    void rearrangeEnd();
    void rearrangeSwapPos(const VfxU32 from, const VfxU32 to);
    void rearrangeSave(VfxBool save);
    void setRepeat(srv_plst_repeat_enum repeatState);
    void setShuffle(srv_plst_shuffle_enum shuffleState);
    srv_plst_repeat_enum getRepeat();
    srv_plst_shuffle_enum getShuffle();
    srv_plst_repeat_enum nextRepeatState();
    srv_plst_shuffle_enum nextShuffleState();
    void searchStart();
    void searchEnd();
    void search(VfxWString &searchText);
    VfxBool isWaitSearchResult(void);
    void clearCurrCache();
    VfxBool setViewType(const ViewTypeEnum viewType, const ChangeViewMode mode, const VfxU32 index);
};


/***************************************************************************** 
 * Music Player UI componet: List menu content provider class
 *****************************************************************************/
class VappMusicPlayerAlbumListCell;
class VappMusicPlayerAlbumSongCell;
class VappMusicPlayerListMenu;

class VappMusicPlayerListMenuProvider : public VfxObject, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappMusicPlayerListMenuProvider);

// Variables
private:
    VappMusicPlayerService *m_mplayerSrv;
    ViewTypeEnum m_viewType; // View type of this provider
    VappMusicPlayerListMenu *m_listMenu;
    VappMusicPlayerContentProvider *m_dataProvider;
    mutable VfxU32 m_count;
    VfxBool m_isScrolling;
    VfxBool m_isEntering;
    VfxBool m_isCheckingDuplicatedPlaylist;

// Constructor
public:
    VappMusicPlayerListMenuProvider():
        m_mplayerSrv(NULL),
        m_viewType(VIEW_TYPE_NONE),
        m_listMenu(NULL),
        m_dataProvider(NULL),
        m_count(0),
        m_isScrolling(VFX_FALSE),
        m_isEntering(VFX_FALSE),
        m_isCheckingDuplicatedPlaylist(VFX_FALSE)
        {};

// Override content provider
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxU32 getCount() const;
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(VfxU32 index, VfxFrame *parentFrame);
    virtual void closeItemCustomContentFrame(VfxU32 index, VcpListMenuCellClientBaseFrame *pCell);
    virtual VfxBool getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color);
    virtual VfxBool getItemTextFormat(VfxU32 index, VcpListMenuFieldEnum fieldType, VcpRichText &format);
    virtual VfxBool getItemTextFrameFormat(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxTextFrame *frame);
    virtual VfxBool getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc &image);
    virtual void closeItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc Image);
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;
    virtual VfxBool getItemIsDisabled(VfxU32 index) const;
    virtual VfxBool getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color);
    virtual VfxBool swapItem(VfxU32 to, VfxU32 from);

// Public methods
public:
    VfxU32 getID(VfxU32 index);
    void setViewType(ViewTypeEnum viewType); // Set view type to this provider
    ViewTypeEnum getViewType() const; // Get view type of this provider
    void setListMenu(VappMusicPlayerListMenu *listmenu); // Set list menu of using this provider
    void setDataProvider(VappMusicPlayerContentProvider *provider);
    void pauseMediaCache(void);
    void resumeMediaCache(void);
    void setMenuScrolling(VfxBool isScrolling);

    // Is page screen in entering state (onEnter() to onEntered() phase)
    void setEntering(VfxBool isEntering);

    // Is App checking duplicated playlist
    void setCheckingDuplicatedPlaylist(VfxBool isChecking);

};


/***************************************************************************** 
 * Music Player UI componet: List service data content provider class
 *****************************************************************************/
class VappMusicPlayerContentProvider : public VfxObject, public IVcpListMenuContentProvider
{   
    VFX_DECLARE_CLASS(VappMusicPlayerContentProvider);

// Variables
private:
    VappMusicPlayerService *m_mplayerSrv;
    VappMusicPlayerCtrlPLSV *m_ctrlPLSV;
    VappMusicPlayerCtrlMediaCahce *m_ctrlMediaCache;
    VappMusicPlayerListMenu *m_listMenu;
    ViewTypeEnum m_currentView;
    ChangeViewMode m_changeViewMode;
    VfxU32 m_curArtistIdx;
    ViewTypeEnum m_curMediaCacheView;
    VfxU32 m_curMediaCacheArtistIdx;
    VfxU32 m_selectingCount;
    VfxBool *m_selectingState;
    VfxBool m_isSelectStart;
    void *m_imageBuffer;
    VfxU32 m_imageSongID;
    VfxBool m_isSearching;
    VfxWString m_searchText;
    VfxId m_activeID;
    VfxWString m_myFavHint;
    VfxBool m_showPlayIcon;
    ListItemDataStruct m_listItemCache;
    HighLightInfoStruct m_hlInfo;
    
public:
    VfxSignal1 <VfxS32> m_signalPLSVReturn;

    VfxSignal3 <srv_plst_cb_evt_enum, S32, VfxU32> m_signalPLSVCallback;

// Constructor
public:
    VappMusicPlayerContentProvider():
        m_mplayerSrv(NULL),
        m_ctrlPLSV(NULL),
        m_ctrlMediaCache(NULL),
        m_listMenu(NULL),
        m_currentView(VIEW_TYPE_NONE),
        m_changeViewMode(CHANGE_VIEW_MODE_NONE),
        m_curArtistIdx(0),
        m_curMediaCacheView(VIEW_TYPE_NONE),
        m_curMediaCacheArtistIdx(0),
        m_selectingCount(0),
        m_selectingState(NULL),
        m_isSelectStart(VFX_FALSE),
        m_imageBuffer(NULL),
        m_imageSongID(0),
        m_isSearching(VFX_FALSE),
        m_activeID(VAPP_MUSICPLY_DEF_LARGE_NUM),
        m_showPlayIcon(VFX_FALSE)
    {};

// Override
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxU32 getCount() const;
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(VfxU32 index, VfxFrame *parentFrame);
    virtual void closeItemCustomContentFrame(VfxU32 index, VcpListMenuCellClientBaseFrame *pCell);
    virtual VfxBool getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color);
    VfxBool getItemTextEx(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color, VfxBool isScrolling, VfxBool isCellLoad);
    virtual VfxBool getItemTextFormat(VfxU32 index, VcpListMenuFieldEnum fieldType, VcpRichText &format, VfxBool isScroll);
    virtual VfxBool getItemTextFrameFormat(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxTextFrame *frame);
    virtual VfxBool getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc &image);
    virtual void closeItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc Image);
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;
    virtual VfxBool getItemIsDisabled(VfxU32 index) const;
    virtual VfxBool getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color);
    virtual VfxBool swapItem(VfxU32 to, VfxU32 from);

// Implementations
private:
    VfxBool checkHighLight(VfxU32 index);
    void setSelectingState(VfxU32 idx, VfxBool isSelect);
    void setAllSelectingState(VfxBool isSelect);
    VappMusicPlayerAlbumListCell* getAlbumListCell(VfxU32 index);
    VappMusicPlayerAlbumSongCell* getAlbumSongCell(VfxU32 index);
    void setAlbumListCellBorder(const VfxU32 index, const VfxBool hasBorder);
    void doSetAlbumListCellBorder(const VfxU32 index, const VfxBool hasBorder);
    void setAlbumSongCellColor(VfxU32 index, VfxBool isHighLight);
    
// Public methods
public:
    void initRepeatShuffle();
    void saveRepeatShuffle();
    void setCBReceiver(VfxObject *obj);
    void setIsReady(VfxBool isReady);
    VfxBool getIsReady(void);
    void setListMenu(VappMusicPlayerListMenu *listmenu);
    VcpListMenu* getListMenu();
    VfxBool setViewType(ViewTypeEnum viewType, const ChangeViewMode mode, const VfxU32 index = 0);
    ViewTypeEnum getViewType() const;
    ChangeViewMode getChangeViewMode() const;
    void resetChangeViewMode();
    VappMusicPlayerCtrlMediaCahce* getCtrlMediaCache() const;
    ViewTypeEnum getCurrMediaCacheViewType() const;
    MCStateEnum getMediaCacheState() const;
    ListItemDataStruct getListItemCache() const;
    VfxBool getTitle(VfxU32 index, VfxWString &title);
    VfxU32 getFixedCount(const ViewTypeEnum viewType, const VfxU32 index) const;
    void setHighLightInfo(VfxU32 index);
    void setActiveToDBUseCurrent();
    srv_plst_active_list_enum getActiveListType();
    VfxBool isPlayingFavorite();
    VfxU32 getID(VfxU32 index);
    void getInfo(VfxU32 index, SongInfoStruct &info);
    VfxBool getDetailInfo(VfxU32 index, srv_plst_media_details_struct *info);
    VfxBool getDetailInfoTitleOnly(VfxU32 index, srv_plst_media_details_struct *info);
    VfxBool getDetailInfoByID(VfxU32 ID, srv_plst_media_details_struct *info);
    VfxBool getCurrDetailInfo(srv_plst_media_details_struct *info);
    void getFilePath(VfxU32 index, VfxWString &filePath);
    void getAlbumCoverPathBySongID(VfxU32 ID, VfxWString &filePath);
    VfxU32 getHintCount(VfxU32 index, srv_plst_view_type_enum getCountType);
    void setDuration(VfxU32 ID, VfxU32 duration);
    void freeImageBuffer();
    void freeMediaCache();
    ViewTypeEnum getMediaCacheView();
    VfxS32 getAlbumCoverAsync(srv_plst_list_get_display_struct *displayStruct);
    void getAlbumCoverAsyncCancel();
    VfxResId getDefaultAlbumCover(ViewTypeEnum viewType, VfxBool isDRM = VFX_FALSE);
    VfxU32 getActiveCount();
    void updateActiveCount();
    VfxU32 getActiveIndex();
    void updateActiveIndex();
    void updateActiveID();
    VfxS32 getActiveAlbumIndex();
    void updateCount();
    void resetPLSV();
    void refreshDB();
    void refreshDBCancel();
    void resetDB();
    VfxResId getErrorStrId(VfxS32 errorCode);
    void onRefreshComplete();
    void selectStart();
    void postProcSelectStart(VfxTimer *t);
    void selectEnd();
    VfxBool isSelectStart();
    VfxBool isSelectAll();
    VfxBool isSelectNone();
    VfxU32 getSelectingCount();
    VfxBool getSelectingState(VfxU32 idx);
    void selectAll();
    void postProcSelectAll(VfxTimer *t);
    void deselectAll();
    void postProcDeselectAll(VfxTimer *t);
    void select(VfxU32 index);
    void deselect(VfxU32 index);
    VfxBool isSelected(VfxU32 index);
    void del(VfxU32 index);
    void delSelected();
    VfxU32 delCancel();
    void createPlaylist(VfxWString name);
    VfxBool isPlaylistExist(VfxWString name);
    void addToPlaylist(VfxU32 index, VfxU32 playlistIdx);
    void addSelectedToPlaylist(VfxU32 playlistIdx);
    void addToPlaylistCancel();
    void renamePlaylist(VfxWString name, VfxU32 playlistIdx);
    VfxBool getPlaylistIndexByName(VfxWString &name, VfxU32 *playlistIdx);
    VfxBool isActiveSongInFavorite();
    void addActiveSongToFavorite();
    void removeActiveSongFromFavorite();
    void rearrangeStart();
    void rearrangeEnd();
    void rearrangeSwapPos(const VfxU32 from, const VfxU32 to);
    void rearrangeSave(VfxBool save);
    void setRepeat(srv_plst_repeat_enum repeatState);
    void setShuffle(srv_plst_shuffle_enum shuffleState);
    srv_plst_repeat_enum getRepeat();
    srv_plst_shuffle_enum getShuffle();
    srv_plst_repeat_enum nextRepeatState();
    srv_plst_shuffle_enum nextShuffleState();
    void searchStart();
    void searchEnd();
    void search(VfxWString &searchText);
    VfxBool isSearching();
    void setShowPlayIcon(VfxBool show);
    VfxBool isUsingMediaCache();
    void setMediaCache();
    void pauseMediaCache();
    void resumeMediaCache();
    void resetMediaCache();
    VfxBool isSongView();
    VfxBool isActiveView(ViewTypeEnum view);
    VfxU32 getHighLightIndex();
    VfxU32 getPreHighLightIndex();
    VfxU32 getHighLightPlayListId();
    void resetHighLighIndex();
    void setHighLighIndex(VfxS32 index);
    void updateHighLightInfo(SongInfoStruct &info, ViewTypeEnum activeView = VIEW_TYPE_NONE);
    HighLightInfoStruct getHighLightInfo();
    void lockFirstVisibleCell();
    void clearCurrCache();

    static void onMediaCacheDecodeResultHandler(VfxU32 index, DecodeResult result, VfxImageBuffer imgBuf, void *user_data);
    void doMediaCacheDecodeResultHandler(VfxU32 index, DecodeResult result, VfxImageBuffer imgBuf, void *user_data);
    void getNextItemImage();
    VfxBool checkMediaCacheDecodeCellRange(VfxU32 index);
    VcpMenuRegion getCellRange();
};

#endif /* __VAPP_MUSIC_PLAYER_CTRLPLSV_H__ */

#endif //__COSMOS_MUSICPLY__
