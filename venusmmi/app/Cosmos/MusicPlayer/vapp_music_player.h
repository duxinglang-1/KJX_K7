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
 *  vapp_music_player.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  FTO Music Player App, screen, tabpage, subpage
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
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"
#ifdef __COSMOS_MUSICPLY__

#ifndef __VAPP_MUSIC_PLAYER_H__
#define __VAPP_MUSIC_PLAYER_H__

//#define __COSMOS_MUSICPLY_DEBUG__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_status_icon_bar.h"
#include "vcp_page_panel.h"
#include "vcp_list_menu.h"
#include "vcp_tabctrl_page.h"
#include "vcp_menu_popup.h"
#include "Vapp_ncenter.h"
#include "vapp_music_player_datatype.h"
#include "vapp_music_player_include.h"
#include "vapp_music_player_ctrlplsv.h"
#include "vapp_music_player_nowplaying.h"
#ifdef __COSMOS_3D_V10__
#include "vapp_music_player_coverflow_3d.h"
#else
#include "vapp_music_player_coverflow.h"
#endif
#include "vapp_music_player_ctrlplayback.h"
#include "vapp_music_player_service.h"
#include "ScreenRotationGprot.h"

extern "C"
{
#include "PlstSrvGprot.h"
}


/***************************************************************************** 
 * Enumeration
 *****************************************************************************/

enum
{
    FUNC_ID_START = 1000,

    // Tab bar
    FUNC_ID_TAB_ALL_SONG,               // 1001
    FUNC_ID_TAB_ARTIST,                 // 1002
    FUNC_ID_TAB_ALBUM,                  // 1003
    FUNC_ID_TAB_PLAYLIST,               // 1004

    // Command toolbar
    FUNC_ID_TB_BTN_NOW_PLAYING,         // 1005
    FUNC_ID_TB_BTN_ADD_TO_PLAYLIST,     // 1006
    FUNC_ID_TB_BTN_NEW_PLAYLIST,        // 1007
    FUNC_ID_TB_BTN_PLAY,                // 1008
    FUNC_ID_TB_BTN_REFRESH,             // 1009
    FUNC_ID_TB_BTN_DELETE,              // 1010
    FUNC_ID_TB_BTN_PLAYLIST_REMOVE,     // 1011
    FUNC_ID_TB_BTN_PLAYLIST_RENAME,     // 1012
    FUNC_ID_TB_BTN_PLAYLIST_ADD_SONG,   // 1013
    FUNC_ID_TB_BTN_PLAYLIST_ARRANGE,    // 1014

    // Confirm toolbar
    FUNC_ID_TB_BTN_OK,                  // 1015
    FUNC_ID_TB_BTN_CANCEL,              // 1016
    FUNC_ID_TB_BTN_SELECT_ALL,          // 1017

    // Context menu item
    FUNC_ID_CM_PLAY,                    // 1018
    FUNC_ID_CM_ADD_TO_PLAYLIST,         // 1019
    FUNC_ID_CM_DELETE,                  // 1020
    FUNC_ID_CM_RENAME,                  // 1021
    FUNC_ID_CM_REMOVE,                  // 1022

    // Setting
    FUNC_ID_GO_TO_SOUND_EFFECT,         // 1023
    FUNC_ID_SOUND_EFFECT_CLOSE,         // 1024

    ///// test
    FUNC_ID_TB_BTN_COVER_FLOW,          // 1025

    FUNC_ID_END
};

typedef struct
{
    VfxBool raised;
    VfxBool isNext;
    GetNextModeEnum nextMode;
    VfxBool delayPlay;
}PlayAfterActionStruct;

typedef struct
{
    VfxId id;
    VfxWString str;
    VfxResId iconResID;
}VappMusicPlayerToolbarItemStruct;

typedef struct
{
    VfxId id;
    VfxWString str;
}VappMusicPlayerMenuPopupItemStruct;

typedef struct
{
    ActionEnum action;
    VfxU32 index;
}VappMusicPlayerLongTapCommStruct;

typedef struct  
{
    MMI_EVT_GROUP_PARAM_HEADER
    VfxBool isOpen;
}VappMusicPlayerOpenCloseEvtStruct;

typedef struct  
{
    MMI_EVT_GROUP_PARAM_HEADER
    VfxBool isShow;
    VfxWChar artist[SRV_PLST_META_INFO_MAX_LEN + 1];
    VfxWChar title[SRV_PLST_META_INFO_MAX_LEN + 1];
}VappMusicPlayerShowHideEvtStruct;

typedef struct  
{
    MMI_EVT_GROUP_PARAM_HEADER
    VfxWChar artist[SRV_PLST_META_INFO_MAX_LEN + 1];
    VfxWChar title[SRV_PLST_META_INFO_MAX_LEN + 1];
    VfxBool isPlayStart;
}VappMusicPlayerPlayStartEvtStruct;

#ifdef __COSMOS_MUSICPLY_COVER_FLOW__
#define MUSICPLY_MAX_VIEW_STACK_DEPTH 8
#else
#define MUSICPLY_MAX_VIEW_STACK_DEPTH 6
#endif

#define MUSICPLY_PLST_NAME_MAX_LENGTH 40

/***************************************************************************** 
 * Music Player UI componet: Music player app class
 *****************************************************************************/

class VappMusicPlayerContentProvider;
class VappMusicPlayerListMenuProvider;
class VappMusicPlayerScreen;
class VappMusicPlayerTabPage;
class VappMusicPlayerSubPage;
class VappMusicPlayerListMenu;
class VappMusicPlayerSettingPage;
class VappMusicPlayerCtrlPlayback;

class VappMusicPlayerApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappMusicPlayerApp);

    friend class VappMusicPlayerContentProvider;
    friend class VappMusicPlayerScreen;
    friend class VappMusicPlayerTabPage;
    friend class VappMusicPlayerSubPage;
    friend class VappMusicPlayerSettingPage;
    friend class VappMusicPlayerCoverFlowAlbumDetailPanel;
    friend class VappMusicPlayerCtrlPlayback;
    friend class VappMusicPlayerNowPlayingPage; // For accessing m_filePathToPlay
    friend class VappMusicPlayerService;
	friend class VappNcenterMusicPlayerInfoPanel;
private:
    // Music player service pointer
    VappMusicPlayerService *m_mplayerSrv;

    // App is going to exit, used to block some unnecessary process
    VfxBool m_isDying;

    // Flag to indicate that APP is launch by main menu or not
    VfxBool m_isLaunchByMainMenu;

    // Flag to call setViewType in DB open completed
    VfxBool m_nowPlayingSetViewType;

    // App is going to background by home key
    VfxBool m_homeKeyToBG;

    // content provider control, provider the data of all list menus
    VappMusicPlayerContentProvider *m_provider;

    // playback control, handle MDI playback function and callback
    VappMusicPlayerCtrlPlayback *m_ctrlPlayback;

    // first screen of APP
    VappMusicPlayerScreen *m_rootScreen;
    VfxWeakPtr<VappMusicPlayerScreen> m_rootScreenWeakPtr;

    // first page of root screen, it's a tab page
    VappMusicPlayerTabPage *m_tabPage;

    // now playing page
    VappMusicPlayerNowPlayingPage *m_nowPlaying;

    // cover flow page
#ifdef __COSMOS_3D_V10__
    VappMusicPlayerCoverFlow3DPage *m_coverFlow;
#else    
    VappMusicPlayerCoverFlowPage *m_coverFlow;
#endif    

    // current global orientatation
    mmi_frm_screen_rotate_enum m_curGblOrientation;

    // current global orientatation
    mmi_frm_screen_rotate_enum m_snapGblOrientation;

    // current app orientatation
    mmi_frm_screen_rotate_enum m_curAppOrientation;

    // confirm popup
    VcpConfirmPopup *m_popupConfirm;

    // indicator popup
    VcpIndicatorPopup *m_popupIndicator;

    // waiting popup
    VcpIndicatorPopup *m_popupWaiting;

    // input popup
    VcpInputPopup *m_popupInput;

    // menu popup
    VcpMenuPopup *m_popupMenu;

    // original input text
    VfxWString m_oriPopupInputText;

    // current view type
    ViewTypeEnum m_curViewType;

    // current action mode
    ActionEnum m_actionMode;

    // the selected item index, used for long press flow control
    VfxU32 m_selectItemIdx;

    // the selected item ID, used for query artist or album data because of searching only support entry next view with ID
    VfxU32 m_selectItemId;

    // the item count of selected item, used for long press flow control
    VfxU32 m_selectItemCount;

    // If add to play list from all songs, albums, ... keep play list ID for later checking if add to active play list
    VfxU32 m_playListId;

    // timer to block search while continuous text input
    VfxTimer *m_searchTimer;

    // search key
    VfxWString m_searchText;

    // previous search key
    VfxWString m_preSearchText;

    // if in the delay play state, used to let m_showPlayIcon set to correct state
    VfxBool m_isDelayPlay;

    // timer to block search while continuous text input
    VfxTimer *m_delayUpdatePrevNext;

    // timer to find next valid song
    //VfxTimer *m_findNextTimer;

    // this flag indicates that when doing adding or deleting song action, AP try to play the next song
    // the behavior is to hold the next action until complete adding or deleting
    PlayAfterActionStruct m_playAfterAction;

    // timer to delay first initialization of PLSV
    VfxTimer *m_delayPLSVTimer;

    // delay init state
    VfxU8 m_delayInitStage;

    // timer to hide status bar icon
    VfxTimer *m_statusIconTimer;

    // timer to show wait icon
    VfxTimer *m_waitIconTimer;

    // this flag is used to indicate that do the checking for duplicated playlist after memory card is inserted
    VfxBool m_needCheckDuplicatedPlaylist;

    // this flag is used to indicate that the checking of duplicated playlist is still going or not ex: canceld by switching to other tabs
    VfxBool m_checkDuplicatedPlaylistRunning;

    // temp string for checking duplicated play list
    VfxWString m_dupListString;

    // timer to continue to check duplicated playlist
    VfxTimer *m_checkDupliactedPlaylistTimer;

    // this bool array is used to store the validation state of each song in active playlist
    // for first round playing, if the song is fail to play, set the state to VFX_FALSE and display error message
    // for second round, skip this song directly and display nothing
    // PS: only display error message in now playing page
    VfxBool *m_activeListValidState;

    // active list state count
    VfxU32 m_activeListValidStateCount;

    VfxBool *m_activeListLyricsState;

    // for A2DP and AVRCP
    static VappMusicPlayerApp *g_this;

    // info for long tap action
    VappMusicPlayerLongTapCommStruct m_longTapComm;

    // return value of PLSV APIs
    VfxS32 m_plsvReturnValue;

    // index for item reorder
    VfxU32 m_reorderStartIdx;
    VfxU32 m_reorderCurrIdx;

    // play state before onPrev/onNext
    VfxBool m_playAfterSwitchSong;

    // use this flag to go to now playing in onGroupUnhidden
    VfxBool m_unhiddenGoToNowPlaying;

    // use to block key back event to pass to VcpTabCtrlPage
    VfxBool m_passBackKey;

    // is subpage during onEnter() and onEntered() phase
    VfxBool m_isEntering;

    // if NCenter is visible
    VfxBool m_isNCenterVisable;

    // reset Media cache because of entering search result page
    VfxBool m_resetMcOnBack;

    // reset list menu because of canceling search
    VfxBool m_resetListOnBack;

    // go to nowplaying if start playback in coverflow
    VfxBool m_coverFlowToNowPlaying;

public:
    // waiting icon
    VcpActivityIndicator *m_waitIcon;

    // this flag indicates that when tapping a song to play, the play action is hold until now playing page is entered
    VfxBool m_doPlayOnEntered;
    

public:
    VappMusicPlayerApp() :
    m_mplayerSrv(NULL),
    m_isDying(VFX_FALSE),
    m_isLaunchByMainMenu(VFX_TRUE),
    m_nowPlayingSetViewType(VFX_FALSE),
    m_homeKeyToBG(VFX_FALSE),
    m_waitIcon(NULL),
    m_provider(NULL),
    m_ctrlPlayback(NULL),
    m_rootScreen(NULL),
    m_tabPage(NULL),
    m_nowPlaying(NULL),
    m_coverFlow(NULL),
    m_curGblOrientation(MMI_FRM_SCREEN_ROTATE_0),
    m_snapGblOrientation(MMI_FRM_SCREEN_ROTATE_0),
    m_curAppOrientation(MMI_FRM_SCREEN_ROTATE_0),
    m_popupConfirm(NULL),
    m_popupIndicator(NULL),
    m_popupWaiting(NULL),
    m_popupInput(NULL),
    m_popupMenu(NULL),
    m_curViewType(VIEW_TYPE_ALL_SONGS),
    m_actionMode(ACTION_NONE),
    m_selectItemIdx(VAPP_MUSICPLY_DEF_LARGE_NUM),
    m_selectItemId(0),
    m_selectItemCount(VAPP_MUSICPLY_DEF_LARGE_NUM),
    m_searchTimer(NULL),
    m_resetMcOnBack(VFX_FALSE),
    m_resetListOnBack(VFX_FALSE),
    m_isDelayPlay(VFX_FALSE),
    m_delayUpdatePrevNext(NULL),
    m_doPlayOnEntered(VFX_FALSE),
    m_delayPLSVTimer(NULL),
    m_statusIconTimer(NULL),
    m_waitIconTimer(NULL),
#ifdef __COSMOS_MUSICPLY_CARD_ONLY__
    m_needCheckDuplicatedPlaylist(VFX_FALSE),
#else
    m_needCheckDuplicatedPlaylist(VFX_TRUE),
#endif
    m_checkDuplicatedPlaylistRunning(VFX_FALSE),
    m_checkDupliactedPlaylistTimer(NULL),
    m_activeListValidState(NULL),
    m_activeListLyricsState(NULL),
    m_activeListValidStateCount(0),
    m_plsvReturnValue(0),
    m_reorderStartIdx(0xFFFFFFFF),
    m_reorderCurrIdx(0xFFFFFFFF),
    m_playAfterSwitchSong(VFX_TRUE),
    m_unhiddenGoToNowPlaying(VFX_FALSE),
    m_passBackKey(VFX_TRUE),
    m_isEntering(VFX_FALSE),
    m_isNCenterVisable(VFX_FALSE),
    m_coverFlowToNowPlaying(VFX_FALSE)
    {};

// Override
protected:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onGroupActive(void);
    virtual void onGroupInactive(void);
    virtual void onGroupHidden(void);
    virtual void onGroupUnhidden(void);
    virtual void onDeinit();
    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options, VfxAppCloseReason reason);
    virtual mmi_ret onProc(mmi_event_struct *evt);

// Public methods
public:
    // update position of wait icon
    void updateWaitIconPos(VfxBool autoCheck = VFX_TRUE, VfxBool isPortrait = VFX_TRUE);

    // set the flag m_isLaunchByMainMenu
    void setIsUnhiddenByNCenter();

    // launch to nowplaying
    void checkLaunchToNowPlaying();

    // set the APP to be dying
    void setIsDying();

    // get if APP is dying
    VfxBool getIsDying();

    // check if is making call
    VfxBool isMakingCall();
    
    // check if in calling and popup warning balloon
    VfxBool blockActionInCall(VfxBool showMessage = VFX_TRUE);

    // turn on back light
    void turnOnBackLight();

    // check if back light is on
    VfxBool isBackLightOn();

    // send EVT_ID_VAPP_MUSICPLY_SHOW_HIDE event
    void sendShowHideEvent(VfxBool isShow);

    // get root screen
    VappMusicPlayerScreen* getRootScreen();

    // get current top page
    VappMusicPlayerSubPage* getCurrPage();

    // get the page before current action
    VappMusicPlayerSubPage* getPageBeforeAction();

    // get list menu of current top page
    VappMusicPlayerListMenu* getCurrListMenu();

    // check if current list menu is being dragging
    VfxBool isListMenuPenDown();

    // get tab page
    VappMusicPlayerSubPage* getTabPage(VfxId ID);

    // get current tab page
    VappMusicPlayerSubPage* getCurrTabPage();

    // close tab page
    VfxBool closeTabPage(VfxId ID);

    // Disable all tab in tab page
    void disableTabPageTab(VfxBool isDisable);

    // handler toolbar and popup events
    void eventHandler(VfxObject* sender, VfxId id);

    // this function is called while search text changed
    void onSearchTextChange(VcpTextEditor *editor);

    // the search timer tick, assume that user stop input text
    void onSearchTimerTick(VfxTimer *timer);

    // cancel waiting popup
    void onWaitingCanceled(VfxObject* obj, VfxFloat curr_progress);

    // cancel progress popup
    void onProgressCanceled(VfxObject* obj, VfxFloat curr_progress);

    // confirm input popup
    void onInputPopupConfirm(VfxObject* sender, VcpInputPopupButtonEnum id);

    // is any popup opening
    VfxBool hasPopup();

    // close all popup
    VfxBool closeAllPopup(VfxBool doClose = VFX_TRUE);

    // list menu item is tapped
    void onListMenuItemTapped(VcpListMenu *sender, VfxU32 index);

    // list menu item is long tapped
    void onListMenuItemLongTapped(VcpListMenu *sender, VfxU32 index);
    
    // connect to list menu m_signalDragCell
    void onListMenuDragCell(VfxBool isStartDrag, VfxU32 index);

    // swap the cells and update content
    void doListMenuCellSwap();

    // call swap item to ctrlPLSV and swap song validation array
    void rearrangeSwapPos(VfxU32 index1, VfxU32 index2);

    // menu item is tapped
    void onMenuItemTapped(VcpMenuPopup* menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem* item);

    // Show popup in foreground when encounter error or exit directly in background
    void exitOnError(VfxResId strID);
    
    // PLSV callback, passed from content provider
    void onPLSVCallback(srv_plst_cb_evt_enum data, S32 result, VfxU32 ca_para_2);

    // MDI callback function
    void onMDICallback(VfxS32 result);

    // Player page (now playing, cover flow...etc) callback
    void onPlayerPageCallback(VfxS32 action);

    // get control playback
    VappMusicPlayerCtrlPlayback* getCtrlPlayback();

    // get content provider
    VappMusicPlayerContentProvider* getProvider();

    // get now playing page
    VappMusicPlayerNowPlayingPage* getNowPlaying();

    // set m_nowPlaying to NULL
    void clearNowPlayingPtr(VappMusicPlayerNowPlayingPage *nowPlaying);

#ifdef __COSMOS_3D_V10__
    // get cover flow page
    VappMusicPlayerCoverFlow3DPage* getCoverFlow();

    // set m_coverFlow to NULL
    void clearCoverFlowPtr(VappMusicPlayerCoverFlow3DPage *coverFlow);

#else 
    // get cover flow page
    VappMusicPlayerCoverFlowPage* getCoverFlow();   

    // set m_coverFlow to NULL
    void clearCoverFlowPtr(VappMusicPlayerCoverFlowPage *coverFlow);
#endif 

    // should check if player is NULL, then check return value: TRUE for coverflow, FALSE for nowplaying
    VappMusicPlayerPlayerBase* getTopPlayer(VfxBool &isCoverFlow);

    // get previous view type
    ViewTypeEnum getPreViewType();

    // get last change view mode
    ChangeViewMode getChangeViewMode();

    // get current view type
    ViewTypeEnum getViewType();

    // set view type with ENTER, BACK, SWITCH mode
    VfxBool setViewType(ViewTypeEnum viewTypw, ChangeViewMode mode=CHANGE_VIEW_MODE_NONE, VfxU32 index = 0xFFFFFFFF, VfxBool useRootScr = VFX_FALSE);

    // get current action mode
    ActionEnum getActionMode();

    // get selected item index
    VfxU32 getSelectItemIdx();

    // get selected item ID
    VfxU32 getSelectItemId();

    // hint count of selected item
    VfxU32 getSelectItemCount();

    // update content of list menu, pass -1 means update all items
    void updateContent(VfxS32 index = -1, VfxBool updateCount = VFX_TRUE, VfxBool updateActive = VFX_TRUE, VfxBool bReset = VFX_FALSE);

    // update list menu previous and current high light items
    void updateHighLight();

    // enable/disable toolbar buttons based on content of list menu is empty or not
    void updateToolbarItemState();

    // invoke by updateToolbarItemState
    void doUpdateToolbarItemState(ViewTypeEnum requestView);

    // if in multi selection mode
    VfxBool isSelecting();

    // if current page is tab page
    VfxBool isTabPage();

    // clear queued pen input
    void resetPenInput();

    // clear queued key input
    void resetKeyInput();

    // handle back key
    void onKeyBack();

    // handle screen rotation event
    void onScreenRotate(VfxScrRotateTypeEnum rotateTo);

    // handle pre/next event from player page
    void onPrevNext(VfxBool isNext, GetNextModeEnum nextMode, VfxBool delayPlay, VfxS32 plsvRet);

    // handle stop event from MDI
    void onStop();

    // start multi selection, update UI and some flags
    void pageMultiSelectOn(VappMusicPlayerSubPage *page, VfxWString str, VfxBool isAnim = VFX_TRUE);

    // finish multi selection, update UI and some flags 
    void pageMultiSelectOff(VappMusicPlayerSubPage *page, VfxBool isAnim = VFX_TRUE);

    // update toolbar button in multi selection mode
    void updateSelectingUI();

    // launch cover flow page
    void goToCoverFlow(VfxScrRotateTypeEnum pageOrientation);

    // exit cover flow page
    void exitCoverFlow();

    // handle list menu pen event
    void onListMenuDragStateChange(VfxBool isDragStart);

    // on PLSV return error
    void onPLSVReturn(VfxS32 ret);

    // show hide wait icon
    void onShowHideWaitIcon(VfxBool isShow, VfxBool delayShow);

    // show wait icon
    void showWaitIcon(VfxBool delayShow = VFX_FALSE);

    // hide wait icon
    void hideWaitIcon();

    // get reorder start index
    VfxU32 getReorderStartIndex();

    // set reorder start index
    void setReorderStartIndex(const VfxU32 idx);

    // return m_playAfterSwitchSong
    VfxBool getPlayAfterSwitchSong();

    // set m_playAfterSwitchSong
    void setPlayAfterSwitchSong(VfxBool isPlay);

    // set entering flag when sub page is from onEnter() to onEntered() phase
    void setSubPageEntering(VfxBool entering);

// Implementation
private:
    // handle onProc event
    void onProcEnterUsbMsMode();

    // handle onProc event
    void onProcShutDownDeinit();

    // handle onProc event
    mmi_ret onProcPreLockRouting();

    // handle onProc event
    void onProcUcmStatusChange();
    
    // handle onProc event
    void onProcOrientationChange(mmi_frm_screen_rotate_enum degree);

    // handle NCenter status events
    void onNCenterStatus(VappNCenterEventEnum evt);

    // Init basic UI before screen enter
    void init1stStage();

    // Init after screen entered
    void init2ndStage(VfxBool showWaiting = VFX_TRUE);
    void stopInit2ndStage(void);
    void init2ndStageTimerTimeout(VfxTimer *timer);

    // handle cancel reorder mode after page exited
    void handlePostPageExited(VfxTimer *timer);

    // handle memory card inserted/removed
    void onMemoryCardChange(void);

    // post handle 300 ms after onMemoryCardChange
    void handlePostMemoryCardChange(VfxTimer *t);

    // set m_actionMode
    void setActionMode(ActionEnum action);

    // handle new playlist action
    void onFuncNewPlaylist();

    // handle add to playlist action
    void onFuncAddToPlaylist();

    // add to playlist action finish or canceled
    void onFuncAddToPlaylistStop();

    // delay executing onFuncAddToPlaylistStop
    void postProcFuncAddToPlaylistStop(VfxTimer *t);

    // handle select playlist action
    void onFuncAddToPlaylistSelect();

    // delay executing add to playlist and popup waiting
    void postProcAddToPlaylist(VfxTimer *t);

    // handle playlist add song action
    void onFuncPlaylistAddSong();

    // do add song action and show waiting popup
    void doAddToPlaylist(VfxU32 index, VfxBool isMulti = VFX_TRUE);

    // handle delete action part1
    void onFuncDeleteStep1();

    // handle delete action part2
    void onFuncDeleteStep2(VfxBool isMulti = VFX_TRUE);

    // handle delete stop or canceled
    void onFuncDeleteStop();

    // handle delete stop after delete popup maximized
    void postProcFuncDeleteStop(VfxTimer *t);

    // Update view if nubmer or info changed by delete
    void onFuncDeleteStopUpdateView();

    // handle playlist rename
    void onFuncPlaylistRename();

    // handle start rearrange mode
    void onFuncRearrangeStart();

    // handle stop rearrange mode
    void onFuncRearrangeStop();

    // handle refresh DB
    void onFuncRefreshDB();

    // handle refresh DB canceling
    void onFuncRefreshDBCancel();

    // handle reset DB
    void onFuncResetDB();

    // phone and memory card may have playlists with the same name, add a serial number (#) at the end if duplicated
    // to prevent from blocking mmi, we only process 20 playlists and start a timer to continue till finish or canceled
    VfxBool checkDuplicatedPlaylist(VfxBool isFristStart);

    // cancel the unfinish checking, and will restart at next time
    void cancelCheckDuplicatedPlaylist();

    // continue to check duplicated playlist
    void checkDuplicatedPlaylistHdlr(VfxTimer *timer);

    // start checking duplicated playlist
    void startCheckDuplicatedPlaylist(void);

    // cancel search
    void searchCancel();

    // pop all pages until the page == viewType
    void popToPage(ViewTypeEnum viewType);

    // close all screens and pages to go back to first page
    void goToRoot(void);

    // use ctrl playback to play a song 
    void playSong(const VfxWChar *filePath, VfxBool delayPlay = VFX_FALSE);

    // play a song and update now playing or cover flow
    void playerPagePlaySong(SongInfoStruct &info, VappMusicPlayerPageSwitchDirEnum dir, VfxBool delayPlay);

    // clear player page error message and stop error timer
    void playerPageResetErrorMsg();

    // Delay update count when on prev/next
    void onPrevNextDelayUpdateTimeout(VfxTimer *Timer);

    // set slider of player page to 0
    void playerPageResetSlider();

    // set slider of player to full size
    void playerPageMaximizeSlider();

    // launch now playing page
    void goToNowPlaying(VfxS32 index = 0, VfxBool isStartPlay = VFX_FALSE);

    // use now playing page to play song
    void nowPlayingPlaySong(SongInfoStruct &info, VfxBool delayPlay = VFX_FALSE);

    // handle set favorite action
    void nowPlayingSetFavorite();

    // handle MDI callback playback fail event
    VfxBool onPlaybackFail(VfxS32 result);

    // use cover flow page to play song
    void coverFlowPlaySong(SongInfoStruct &info, VfxBool delayPlay = VFX_FALSE);

    // initialize song info of player page
    void playerPageSetInfo(VappMusicPlayerPlayerBase *playerPage);

    // launch setting page
    void goToSetting();

    // launch sound effect selecting page
    void goToSoundEffect();

    // back from sound effect selecting page
    void backFromSoundEffect();

    // leave & close sound effect selecting and setting page
    void closeSetting();

    // item is selected / deselected in multi selection mode
    void onItemSelectionStateChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState);

    // playback state changed
    void onPlaybackStateChange(PlaybackStateEnum state);

#ifdef __MMI_AVRCP_SUPPORT__
    // return TRUE if player page has handler this event
    VfxBool AVRCPCommHandler(U8 command_type);
#endif /*__MMI_AVRCP_SUPPORT__*/

    // show a confirm popup
    void popupConfirm(
        VfxWString strHint, 
        VfxWString strBtn, 
        VcpPopupTypeEnum popupType, 
        VcpConfirmPopupButtonSetEnum buttonSet = VCP_CONFIRM_BUTTON_SET_USER_DEFINE, 
        VcpPopupButtonTypeEnum buttonType = VCP_POPUP_BUTTON_TYPE_NORMAL);

    // close confirm popup
    void popupConfirmClose();

    // show a waiting popup
    void popupWaiting(VfxWString str, VfxBool withCancelBtn = VFX_TRUE);

    // close waiting popup
    void popupWaitingClose();

    // show a progress popup
    void popupProgress(VfxWString str);

    // close progress popup
    void popupProgressClose();

    // show input popup
    void popupInput(VfxWString title, VfxWString hint, VfxWString defString, VfxS32 maxLen = -1);

    // handle input popup text changed
    void popupInputTextBeforeChanged(VfxWChar *text, VfxS32 curPos, VcpTextChangeEnum type, VfxBool *ret);

    // show menu popup
    void popupMenu(VfxWString str, VappMusicPlayerMenuPopupItemStruct *itemList, VfxU32 itemCount);

    // close menu popup
    void popupMenuClose();

    // show balloon
    void showBalloon(mmi_nmgr_balloon_type_enum type, VfxWString str);

    // do show wait icon
    void doShowWaitIcon(VfxTimer *timer);

    // check PLSV return, return TRUE for OK, FALSE for error (and popup error message)
    VfxBool checkPLSVAction(VfxBool showPopup = VFX_TRUE, VfxBool resetValue = VFX_FALSE);

    // shrink DB on app closing
    void onAppClosingShrinkDB();
};

/***************************************************************************** 
 * Music Player UI componet: Music player screen class
 *****************************************************************************/

class VappMusicPlayerScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappMusicPlayerScreen);

// Variables
private:
    // view stack array
    ViewTypeEnum m_viewStack[MUSICPLY_MAX_VIEW_STACK_DEPTH];

    // view stack count
    VfxU32 m_viewStackCount;

public:
    VappMusicPlayerScreen():
        m_viewStackCount(0)
    {
#ifdef LOW_COST_SUPPORT
        setAppContextShareForVrt(VFX_TRUE);
#endif

#ifdef __COSMOS_3D_V10__
        setVrtCacheLimitSize(1);
#endif
    };

// Override
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void on1stReady();
    virtual void onEnter(VfxBool isBackward);
    virtual void onExited(VfxBool isBackward);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    virtual void onRotate(const VfxScreenRotateParam &param);
    
// Public methods
public:
    // get depth of view stack
    VfxU32 getViewStackCount();

    // get top view of view stack, 9999 means top
    ViewTypeEnum getViewStack(VfxU32 idx=9999);

    // Check if a view is in view statck
    VfxBool isViewInStack(ViewTypeEnum viewType);

    // push in new view
    VfxU32 pushViewStack(ViewTypeEnum viewType);

    // pop out the top view
    ViewTypeEnum popViewStack();

    // clear view stack
    void clearViewStack();

    // create a new page
    VfxBool goToNextPage(ViewTypeEnum viewType, VfxWString titleStr, VfxU32 index = 0xFFFFFFFF);

// Implementation
private:
    
};

/***************************************************************************** 
 * Music Player UI componet: Music player tab control page class
 *****************************************************************************/

class VappMusicPlayerTabPage : public VcpTabCtrlPage
{
    VFX_DECLARE_CLASS(VappMusicPlayerTabPage);

// Variables
private:
    // id of previous tab page
    VfxId m_preTabId;

    // id for page to close
    VfxId m_closingTabId;

    // timer for closing tab page
    VfxTimer *m_closeTabTimer;

// Constructor / Destructor
public:
    VappMusicPlayerTabPage() :
      m_preTabId(100),
      m_closingTabId(0),
      m_closeTabTimer(NULL)
      {};

    void disableAllTab(VfxBool isDisable);

// Override methods
protected:
    virtual void onInit();

    // this function is call while tab page is being created
    virtual VfxPage *onCreateTabPage(VfxId tabId);

    // this function is call at the beginning of tab switching
    virtual void onTabSwitching(VfxId tabId);

    // this function is call at the end of tab switching
    virtual void onTabSwitched(VfxId tabId);

    VfxBool onKeyInput(VfxKeyEvent &event);
    
// Implementation
private:

    void doTabPageClose(VfxTimer *t);
};


/***************************************************************************** 
 * Music Player UI componet: Music player sub page class
 *****************************************************************************/

class VappMusicPlayerSubPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappMusicPlayerSubPage);

    friend class VappMusicPlayerApp;
    friend class VappMusicPlayerTabPage;

// Variables
private:
    // VappMusicPlayerApp pointer
    VappMusicPlayerApp *m_app;

    // if this page has title bar
    VfxBool m_hasTitleBar;

    // title bar
    VcpTitleBar *m_titleBar;

    // list menu of this page
    VappMusicPlayerListMenu *m_listMenu;

    // search bar of list menu
    VcpListMenuSearchBar *m_searchBar;

    // is search bar enable in this menu
    VfxBool m_enableSearchBar;

    // in some cases, original toolbar would be replaced by a confirm toolbar, so keep the one for later toolbar restoration
    VcpToolBar *m_preToolBar;

    // view type of this page
    ViewTypeEnum m_viewType;

    // data provider for list menu
    VappMusicPlayerListMenuProvider *m_contentProvider;

    // Timer to update cell sub item in some view
    VfxTimer *m_cellTimer;

    // the isBack flag in onEnter() function
    VfxBool m_isBackward;

    // Timer to delay doing some process after onEntered
    VfxTimer *m_onEnteredTimer;
    
// Constructor / Destructor
public:
    VappMusicPlayerSubPage(VfxBool hasTitleBar):
        m_hasTitleBar(hasTitleBar),
        m_titleBar(NULL),
        m_listMenu(NULL),
        m_searchBar(NULL),
        m_enableSearchBar(VFX_FALSE),
        m_preToolBar(NULL),
        m_viewType(VIEW_TYPE_NONE),
        m_contentProvider(NULL),
        m_cellTimer(NULL),
        m_isBackward(VFX_FALSE),
        m_onEnteredTimer(NULL)
        {};

    VappMusicPlayerSubPage():
        m_hasTitleBar(VFX_FALSE),
        m_titleBar(NULL),
        m_listMenu(NULL),
        m_searchBar(NULL),
        m_enableSearchBar(VFX_FALSE),
        m_preToolBar(NULL),
        m_viewType(VIEW_TYPE_NONE),
        m_contentProvider(NULL),
        m_cellTimer(NULL),
        m_isBackward(VFX_FALSE),
        m_onEnteredTimer(NULL)
        {};

// Public methods
public:
    // set title
    void initTitleBar(VfxWString str);

    // set title bar text
    void setTitleBarText(VfxWString str);

    // initalize list menu
    void initListMenu(VcpListMenuCellStyleEnum style, VfxBool enableSearchBar = VFX_FALSE);

    // set control mode of list menu (normal, disclosure)
    void setListMenuControlMode(ViewTypeEnum viewType, VfxBool isAnim = VFX_TRUE);

    // set toolbar for this page
    void setToolbar(VappMusicPlayerToolbarItemStruct *itemsStruct, VfxU32 itemNum);

    // get view type
    ViewTypeEnum getViewType();

    // set view type
    void setPageViewType(ViewTypeEnum viewType);

    // reset change view mode
    void resetChangeViewMode();

    // set confirm toolbar with 1 button (OK)
    void initConfirmToolbar1();

    // set confirm toolbar with 2 buttons (OK / CANCEL)
    void initConfirmToolbar2();

    // set confirm toolbar with 3 buttons (Select all / (Confirm string) / Cancel)
    void initConfirmToolbar3(VfxWString &str);

    // update all item
    void updateAll(VfxBool keepViewState = VFX_TRUE);

    // update one item
    void updateItem(VfxU32 index);

    // reset all items
    void resetAll(void);

    // get title bar
    VcpTitleBar* getTitleBar();

    // get toolbar
    VcpToolBar* getToolBar();

    // restore to original toolbar
    void restorePreToolBar();

    // get list menu
    VappMusicPlayerListMenu* getListMenu();

    // enable / disable search bar
    void disableSearchBar(VfxBool isDisable);

    // set search hint text according to view type
    void setSearchBarHint(ViewTypeEnum viewType);

    // get search editor
    VcpTextEditor* getSearchEditor();

    // clear search editor
    void clearSearchEditor();

    // decativate search editor
    void deactivateSearchEditor();

    // if this page is using media cache
    VfxBool isUsingMediaCache();

// Override methods
protected:
    virtual void onInit();
    virtual void onDeinit();
    void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onExit(VfxBool isBackward);
    virtual void onExited();
    virtual void onExited2();
    virtual void onBack();
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    virtual void onRotate(const VfxScreenRotateParam &param);   

private:
    void onMenuStartFreerun(VcpScrollableView* view);
    void onMenuScrollStopped(VcpBaseListMenu *menu);
    void updateCellTimerTimeout(VfxTimer *timer);
    // Update content after page entered
    void updateListMenuContent(void);

    // Disable all toolbar
    void disableToolbar(VfxBool isDisable);

    void onEnteredPostProc(VfxTimer *t);
};


/***************************************************************************** 
 * Music Player UI componet: Music player custom list menu class
 *****************************************************************************/

class VappMusicPlayerListCell
{
// Constructor
public:
    VappMusicPlayerListCell() {};

// Variable
public:
    VfxS32 pos;
    VfxBool isSubTextLoad;
};


class VappMusicPlayerListMenu : public VcpListMenu
{
    VFX_DECLARE_CLASS(VappMusicPlayerListMenu);

// Variables
private:
    // flag to indicate if the list menu should be update
    VfxBool m_isFreezed;

    // flag to indicate if pen is down
    VfxBool m_isPenDown;

    // view state
    VcpBaseMenuViewState m_viewState;

    // A list to store which cell is created
    VfxList <VappMusicPlayerListCell> m_cellList;

public:
    // store the view type
    ViewTypeEnum m_viewType;

    // signal to notify dragging start / stop and index
    VfxSignal2 <VfxBool, VfxU32> m_signalDragCell;
    
// Constructor / Destructor
public:
    VappMusicPlayerListMenu():
      m_isFreezed(VFX_FALSE),
      m_isPenDown(VFX_FALSE),
      m_viewType(VIEW_TYPE_NONE)
      {};

protected:
    virtual void onInit();
    VfxFrame* createCell(VfxS32 group,VfxS32 pos);
    void onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame);
    virtual void onUpdate();
    VfxBool updateViewForIme(VfxFrame * focusFrame); // Change to non-virtual by FW
    virtual void onObjectNotify(VfxId id, void *userData);
    virtual void onDragStart();
    virtual void onDragEnd();
    virtual void startDragCell(VcpMenuPos pos, VfxFrame* dragCell);
    virtual void endDragCell(VcpMenuPos pos, VfxFrame* dragCell);

// Public methods
public:
    void savePosition();
    void restorePosition();
    void resetPosition();
    void setIsFreezed(VfxBool isFreezed);
    VfxBool getIsFreezed();
    VfxBool getIsCustomStyle();
    VfxBool getIsPenDown();
    VfxBool getIsDraggingCell();
    VfxS32 findNextCellToLoad(VfxS32 begin, VfxS32 end, VfxBool setLoadAfterFind);
    VfxBool isCellSubTextLoad(VfxS32 pos);
};


/***************************************************************************** 
 * Music Player UI componet: List menu custom cell class
 *****************************************************************************/

class VappMusicPlayerSongListCell : public VcpListMenuCellTripleTextFrameEx
{   
    VFX_DECLARE_CLASS(VappMusicPlayerSongListCell);

// Override
public:
    virtual void onUpdateElements();
};

/***************************************************************************** 
 * Music Player UI componet: List menu custom cell class
 *****************************************************************************/

class VappMusicPlayerArtistListCell : public VcpListMenuCellMultiTextFrame
{   
    VFX_DECLARE_CLASS(VappMusicPlayerArtistListCell);

// Override
public:
    virtual void onUpdateElements();
};

/***************************************************************************** 
 * Music Player UI componet: List menu custom cell class
 *****************************************************************************/

class VappMusicPlayerAlbumListCell : public VcpListMenuCellIconMultiTextFrame
{   
    VFX_DECLARE_CLASS(VappMusicPlayerAlbumListCell);

// Override
public:
    virtual void onLayoutElements();

    virtual void onUpdateElements();

    // enable border if not drawing default icon
    void enableImageBorder(VfxBool hasBorder);
};

/***************************************************************************** 
 * Music Player UI componet: List menu custom cell class
 *****************************************************************************/

class VappMusicPlayerAlbumSongCell : public VcpListMenuCellTripleTextFrameEx
{   
    VFX_DECLARE_CLASS(VappMusicPlayerAlbumSongCell);

private:
    VfxU32 m_serial;
    VfxBool m_prePlaying;
    VfxBool m_isPlaying;
    VfxTextFrame *m_textSerial;

// Constructor
public:
    VappMusicPlayerAlbumSongCell():
      m_serial(0),
      m_prePlaying(VFX_FALSE),
      m_isPlaying(VFX_FALSE),
      m_textSerial(NULL)
    {};

// Override
public:
    virtual void onLayoutElements();
    virtual void onUpdateElements();

// Public method
public:
    void setSerial(const VfxU32 serial);
    void setIsPlaying(const VfxBool isPlaying);

// Implementation
private:
    void updateSerialColor();
};



#endif /* __VAPP_MUSIC_PLAYER_H__ */

#endif //__COSMOS_MUSICPLY__
