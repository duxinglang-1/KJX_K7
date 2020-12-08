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
 *  vapp_music_player_coverflow.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  FTO Music Player cover flow page
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"
#ifdef __COSMOS_MUSICPLY__

#ifndef __VAPP_MUSIC_PLAYER_COVERFLOW_H__
#define __VAPP_MUSIC_PLAYER_COVERFLOW_H__

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_music_player_datatype.h"
#include "vapp_music_player_playerbase.h"
#include "vapp_music_player_ctrlplsv.h"
#include "vapp_music_player_ctrlplayback.h"

/***************************************************************************** 
 * Music Player Control componet: Cover flow class
 *****************************************************************************/

class VappMusicPlayerCoverFlowMenu;
class VappMusicPlayerCoverFlowAlbumDetailPanel;
class VappMusicPlayerContentProvider;
class VappMusicPlayerCtrlMediaCahce;
class VappMusicPlayerListMenuProvider;

class VappMusicPlayerCoverFlowPage : public VappMusicPlayerPlayerBase
{
    VFX_DECLARE_CLASS(VappMusicPlayerCoverFlowPage);

// Variables
private:
    VfxFrame *m_albumCoverFrame;
    VfxScrRotateTypeEnum m_pageOrientation;
    VappMusicPlayerCoverFlowAlbumDetailPanel *m_panelAlbumDetail;
    VfxS32 m_focusAlbumIdx;
    VfxTimer *m_onEnteredTimer;
    
public:
    VappMusicPlayerCoverFlowMenu *m_menu;
    VappMusicPlayerContentProvider *m_provider;
    VappMusicPlayerListMenuProvider *m_listMenuProvider;
    VappMusicPlayerCtrlMediaCahce *m_ctrlMediaCache;
    VfxBool m_hasStartPlayback;

// Constructor / Destructor
public:
    VappMusicPlayerCoverFlowPage():
        m_menu(NULL),
        m_provider(NULL),
        m_listMenuProvider(NULL),
        m_ctrlMediaCache(NULL),
        m_albumCoverFrame(NULL),
        m_pageOrientation(VFX_SCR_ROTATE_TYPE_90),
        m_panelAlbumDetail(NULL),
        m_hasStartPlayback(VFX_FALSE),
        m_focusAlbumIdx(-1),
        m_onEnteredTimer(NULL)
    {};

    VappMusicPlayerCoverFlowPage(VfxScrRotateTypeEnum pageOrientation):
        m_menu(NULL),
        m_provider(NULL),
        m_listMenuProvider(NULL),
        m_ctrlMediaCache(NULL),
        m_albumCoverFrame(NULL),
        m_pageOrientation(pageOrientation),
        m_panelAlbumDetail(NULL),
        m_hasStartPlayback(VFX_FALSE),
        m_focusAlbumIdx(-1),
        m_onEnteredTimer(NULL)
    {};
      
// Public methods
public:
    void setAlbumCover(VfxImageBuffer &imgBuf);
    VfxU32 getAlbumCount();
    void getAlbumInfo(VfxU32 idx, VfxWString& artist, VfxWString& album);
    VfxU32 getAlbumID(VfxU32 idx);
	void getAlbumImage(VfxU32 idx, VfxImageSrc &imgSrc);
    void makeFocusCellVisible(VfxTimer *timer);
    void showAlbumDetailPanel(VfxU32 index);
    void hideAlbumDetailPanel(VfxBool anim = VFX_TRUE);
    void onAlbumDetailPanelShow();
    void onAlbumDetailPanelClosed();
    VfxBool isDetailPanelAlive();
    void updateCellImage(VfxU32 index, VfxImageBuffer imgBuf);
    void updateCellInfo(VfxU32 index);
    void hideAllCellImages();
    void updateAlbumPanelItem(VfxS32 index);
    
// Override methods
protected:
    void onInit();
    void onDeinit();
    void initUI();
    void onEnter(VfxBool isBackward);
    void onEntered();
    void onExit(VfxBool isBackward);
    void onExited();
    void onExited2();
    VfxBool onKeyInput(VfxKeyEvent &event);
    void onQueryRotateEx(VfxScreenRotateParam &param);
    VfxBool onPenInput(VfxPenEvent &event);
    void setInfoText(VfxWString &title, VfxWString &artist, VfxWString &count);

public:
    void onPlaybackStateChange(PlaybackStateEnum state);

// Implementation
private:
    void onEnteredPostProc(VfxTimer *t);
    void onMenuScrollStopped(VcpScrollable* sender);
    void doShowAlbumDetailPanel();
};


/***************************************************************************** 
 * VappMusicPlayerCoverFlowMenuLayout is the layout of cover flow menu
 *****************************************************************************/

class VappMusicPlayerCoverFlowMenuLayout : public VcpBaseMenuLayout
{
    VFX_DECLARE_CLASS(VappMusicPlayerCoverFlowMenuLayout );

// Variables
private:
    enum
    {
        CellWidth = VAPP_MUSICPLY_CF_CELL_WIDTH,
        CellHeight = VAPP_MUSICPLY_CF_CELL_HEIGHT,

        StartEndSpace = VAPP_MUSICPLY_CF_CELL_WIDTH / 5,

#if defined(__MMI_MAINLCD_240X320__)
        CellGapX = 8,
        CellGapY = 8,
#elif defined(__MMI_MAINLCD_240X400__)
        CellGapX = 8,
        CellGapY = 8,
#elif defined(__MMI_MAINLCD_320X480__)
        CellGapX = 4,
        CellGapY = 4,
#else //(__MMI_MAINLCD_480X800__)
        CellGapX = 6,
        CellGapY = 6,
#endif 
    };

public:
    VfxU32 m_itemCount;

// Constructor / Destructor
public:
    VappMusicPlayerCoverFlowMenuLayout() : 
      VcpBaseMenuLayout(NULL),
      m_itemCount(0)
    {}

    VappMusicPlayerCoverFlowMenuLayout(VcpBaseMenu* menu) : 
      VcpBaseMenuLayout(menu),
      m_itemCount(0)
    {}

// Public methods
public:
    VcpMenuPos getCellByPos(VfxPoint pt);
    void setItemCount(VfxS32 cnt);
    VfxU32 getItemCount();
    VfxS32 getStartEndSpace();

// Override methods
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual ScrollDirEnum getScrollDir();
    virtual VfxS32 getGroupCount();    
    virtual VfxS32 getCellCount(VfxS32 group);
    virtual VfxS32 getContentLength();
    virtual VfxBool hasGroupHeader(VfxS32 group);
    virtual VcpMenuRegion queryRegion(const VfxRect& r);
    virtual VfxRect queryCellRect(VcpMenuPos pos);
    virtual void getPreferFocusMargin(VfxS32 margin[4]);
    
// Implementation
private:

};


/***************************************************************************** 
 * VappMusicPlayerCoverFlowMenuCell is the cell of cover flow menu
 *****************************************************************************/

class VappMusicPlayerCoverFlowMenuCell : public VfxControl
{
    VFX_DECLARE_CLASS(VappMusicPlayerCoverFlowMenuCell);

// Variables
private:
    VfxTextFrame     *m_textArtist;
    VfxTextFrame     *m_textAlbum;
    VfxBool          m_highlight;

    enum
    {
        ANIM_DURATION_SHOW = 300,

#if defined(__MMI_MAINLCD_240X320__)
        TextArtistMarginX = 5,
        TextArtistPosY = 54,
        TextAlbumPosX = 5,
        TextAlbumPosY = 74,
        ArtistFontSize = 16,
        AlbumFontSize = 12,
        HighLightBorderSize = 3,

#elif defined(__MMI_MAINLCD_240X400__)
        TextArtistMarginX = 5,
        TextArtistPosY = 54,
        TextAlbumPosX = 5,
        TextAlbumPosY = 74,
        ArtistFontSize = 16,
        AlbumFontSize = 12,
        HighLightBorderSize = 3,

#elif defined(__MMI_MAINLCD_320X480__)
        TextArtistMarginX = 5,
        TextArtistPosY = 59,
        TextAlbumPosX = 5,
        TextAlbumPosY = 72,
        ArtistFontSize = 12,
        AlbumFontSize = 12,
        HighLightBorderSize = 3,

#else //(__MMI_MAINLCD_480X800__)
        TextArtistMarginX = 7,
        TextArtistPosY = 88,
        TextAlbumPosX = 7,
        TextAlbumPosY = 108,
        ArtistFontSize = 18,
        AlbumFontSize = 18,
        HighLightBorderSize = 5,
#endif      
    };

// Constructor / Destructor
public:
    VappMusicPlayerCoverFlowMenuCell():
      m_textArtist(NULL),
      m_textAlbum(NULL),
      m_highlight(VFX_FALSE)
    {};

// Public methods
public:
    void setHighlight(VfxBool isHighLight, VfxBool isAnim);
    void enter(const VfxRect& r, VfxBool animation);
    void leave(const VfxRect& r);
    void updatePos(const VfxRect& r, VfxBool isAnim);
    void setTextInfo(const VfxWString& textArtist, const VfxWString& textAlbum);
    void click(VcpMenuPos index);
    void setImage(VfxImageSrc imgSrc);
    void hideImage();

// Override methods
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void setBounds(const VfxRect &value);
    
// Implementation
private:
};


/***************************************************************************** 
 * VappMusicPlayerCoverFlowMenu is the component shows all the album covers
 *****************************************************************************/

class VappMusicPlayerCoverFlowMenu : public VcpBaseMenu
{
    VFX_DECLARE_CLASS(VappMusicPlayerCoverFlowMenu);

// Variables
private:
    VfxS32 m_focusCellIdx;
    VappMusicPlayerCoverFlowPage *m_page;
    VfxS32 m_preCreatedCell;
    
// Constructor / Destructor
public:
    VappMusicPlayerCoverFlowMenu():
      m_focusCellIdx(-1),
      m_page(NULL),
      m_preCreatedCell(-1)
      {};

// Public methods
public:
    void updateCellImage(VfxU32 index, VfxImageBuffer imgBuf);
    void updateCellInfo(VfxU32 index);
    void hideAllCellImages();
    void setCellBorder(VfxBool isShow, VfxS32 pos = -1);
    
// Override methods
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual VcpBaseMenuLayout* createLayout();
    virtual VfxFrame* createGroupHeader(VfxS32 group);
    virtual VfxFrame* createCell(VfxS32 group, VfxS32 pos);
    virtual void onCloseGroupHeader(VfxS32 group, VfxFrame* groupFrame);
    virtual void onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame);
    virtual void onUpdateGroupHeader(const VfxRect &rect, VfxS32 group, VfxFrame* header, VfxU32 flag);
    virtual void onUpdateCell(const VfxRect &rect, VfxS32 group, VfxS32 pos, VfxFrame* cell, VfxU32 flag);
    virtual void onTouchCell(VcpMenuPos cellPos, CellTouchTypeEnum touchType, VfxPoint pt, VfxFrame *cell);
    
// Implementation
private:
};



/***************************************************************************** 
 * VappMusicPlayerCoverFlowAlbumDetailPanel is the component shows all songs in select album
 *****************************************************************************/

class VappMusicPlayerListMenu;

class VappMusicPlayerCoverFlowAlbumDetailPanel : public VfxControl
{
    VFX_DECLARE_CLASS(VappMusicPlayerCoverFlowAlbumDetailPanel);

// Variables
private:
    enum
    {
        ANIM_DURATION_SHOW = 300,
        ANIM_DURATION_SHOW_FAST = 200,
        ANIM_DURATION_HIDE = 400,
        ANIM_DURATION_HIDE_FAST = 200,

#if defined(__MMI_MAINLCD_240X320__)
        contentAreaWidth = 320,
        contentAreaHeight = 240 - MMI_STATUS_BAR_HEIGHT,
        borderFrameWidth = 284,
        borderFrameHeight = 142,
        borderSize = 1,
        albumCoverWidth = 140,  //borderFrameHeight - 2 * borderFrameSize
        albumCoverHeight = 140, //albumCoverWidth
        titleBarWidth = 142,    //borderFrameWidth - borderFrameHeight
        titleBarHeight = 36,
        titleBarTextWidth = 84,
        titleBarTextHeight = 30,
        titleBarFontSize1 = 16,
        titleBarFontSize2 = 12,
        titleBarMarginX = 7,
        titleBarMarginY = 8,
        titleBarNumTextWidth = 50,
        titleBarNumTextHeight = 30,
        titleBarNumTextShiftY = 6,
        listMenuItemHeight = 36,
        shadowSize = 7,

#elif defined(__MMI_MAINLCD_240X400__)
        contentAreaWidth = 400,
        contentAreaHeight = 240 - MMI_STATUS_BAR_HEIGHT,
        borderFrameWidth = 364,
        borderFrameHeight = 164,
        borderSize = 1,
        albumCoverWidth = 162,  //borderFrameHeight - 2 * borderFrameSize
        albumCoverHeight = 162, //albumCoverWidth
        titleBarWidth = 200,    //borderFrameWidth - borderFrameHeight
        titleBarHeight = 36,
        titleBarTextWidth = 124,
        titleBarTextHeight = 30,
        titleBarFontSize1 = 18,
        titleBarFontSize2 = 12,
        titleBarMarginX = 7,
        titleBarMarginY = 8,
        titleBarNumTextWidth = 68,
        titleBarNumTextHeight = 30,
        titleBarNumTextShiftY = 6,
        listMenuItemHeight = 36,
        shadowSize = 7,

#elif defined(__MMI_MAINLCD_320X480__)
        contentAreaWidth = 480,
        contentAreaHeight = 196,
        borderFrameWidth = 406,
        borderFrameHeight = 182,
        borderSize = 1,
        albumCoverWidth = 180,  //borderFrameHeight - 2 * borderFrameSize
        albumCoverHeight = 180, //albumCoverWidth
        titleBarWidth = 224,    //borderFrameWidth - borderFrameHeight
        titleBarHeight = 36,
        titleBarTextWidth = 146,
        titleBarTextHeight = 30,
        titleBarFontSize1 = 20,
        titleBarFontSize2 = 16,
        titleBarMarginX = 7,
        titleBarMarginY = 8,
        titleBarNumTextWidth = 70,
        titleBarNumTextHeight = 30,
        titleBarNumTextShiftY = 8,
        listMenuItemHeight = 36,
        shadowSize = 7,

#else //(__MMI_MAINLCD_480X800__)
        contentAreaWidth = 800,
        contentAreaHeight = 296,
        borderFrameWidth = 700,
        borderFrameHeight = 272,
        borderSize = 2,
        albumCoverWidth = 268,  //borderFrameHeight - 2 * borderFrameSize
        albumCoverHeight = 268, //albumCoverWidth
        titleBarWidth = 428,    //borderFrameWidth - borderFrameHeight
        titleBarHeight = 54,
        titleBarTextWidth = 270,
        titleBarTextHeight = 45,
        titleBarFontSize1 = 30,
        titleBarFontSize2 = 24,
        titleBarMarginX = 10,
        titleBarMarginY = 12,
        titleBarNumTextWidth = 150,
        titleBarNumTextHeight = 45,
        titleBarNumTextShiftY = 10,
        listMenuItemHeight = 52,
        shadowSize = 12,
#endif
    };

    enum AnimState
    {
        IDLE,
        SHOW_STEP_1,
        SHOW_STEP_2,
        HIDE_STEP_1,
        HIDE_STEP_2,
    };

    VfxFrame *m_albumImage;
    VfxU32 m_albumIndex;
    VappMusicPlayerContentProvider *m_provider;
    VappMusicPlayerListMenuProvider *m_listMenuProvider;
    VfxTimer *m_timer;
    VfxFrame *m_borderFrame;
    VfxFrame *m_listFrame;
    VappMusicPlayerListMenu *m_listMenu;
    VfxFrame *m_shadowFrame;
    AnimState m_animState;

// Constructor / Destructor
public:
    VappMusicPlayerCoverFlowAlbumDetailPanel() :
        m_albumImage(NULL),
        m_albumIndex(0),
        m_provider(NULL),
        m_listMenuProvider(NULL),
        m_timer(NULL),
        m_borderFrame(NULL),
        m_listFrame(NULL),
        m_listMenu(NULL),
        m_shadowFrame(NULL),
        m_animState(IDLE)
      {};

    VappMusicPlayerCoverFlowAlbumDetailPanel(VfxU32 index) :
        m_albumImage(NULL),
        m_albumIndex(index),
        m_provider(NULL),
        m_listMenuProvider(NULL),
        m_timer(NULL),
        m_borderFrame(NULL),
        m_listFrame(NULL),
        m_listMenu(NULL),
        m_shadowFrame(NULL),
        m_animState(IDLE)
      {};

// Public methods
public:
    void updateListMenu(VfxS32 index = -1);
    void startShow();
    void startExit(VfxBool isAnim = VFX_TRUE);
    void closePanel();

    void setAlbumCover();

// Override methods
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    virtual VfxBool onPenInput(VfxPenEvent &event);

// Implementation
private:
    void _doClose();
    void showPanel();
    void hidePanel();
    void showListFrame();
    void hideListFrame();
    void showShadow();
    void hideShadow();
    void onTimerTick(VfxTimer *timer);
    void onListItemTapped(VcpListMenu *menu, VfxU32 index);
};

#endif /*   __VAPP_MUSIC_PLAYER_COVERFLOW_H__   */

#endif //__COSMOS_MUSICPLY__
