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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"
#ifdef __COSMOS_MUSICPLY__
#ifdef __COSMOS_3D_V10__

#ifndef __VAPP_MUSIC_PLAYER_COVERFLOW_3D_H__
#define __VAPP_MUSIC_PLAYER_COVERFLOW_3D_H__

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_music_player.h"
#include "vapp_music_player_datatype.h"
#include "vapp_music_player_playerbase.h"
#include "vapp_music_player_ctrlplsv.h"
#include "vapp_music_player_ctrlplayback.h"

#include "vfx_world.h"
#include "vfx_camera.h"
#include "vfx_light.h"
#include "vfx_mesh.h"
#include "vfx_pass.h"
#include "vfx_shader_uniforms.h"
#include "vfx_texture.h"

/***************************************************************************** 
 * Music Player Control componet: Cover flow class
 *****************************************************************************/

class VappMusicPlayerCoverFlow3DMenu;
class VappMusicPlayerCoverFlow3DSongListPanel;
class VappMusicPlayerContentProvider;
class VappMusicPlayerListMenuProvider;
class VappMusicPlayerCtrlMediaCahce;

class CDBoxItem : public VfxObject
{
    VFX_DECLARE_CLASS(CDBoxItem);

public:
    VfxS32 index;
    VfxGroup *item;
    VfxMesh *boxMesh;
    VfxMesh *discMesh;
    VfxShaderUniforms *texUniforms;
    VfxShaderUniforms *reflectUniforms;
    VfxShaderUniforms *CDtexUniforms;
    VfxShaderUniforms *CDreflectUniforms;
    VfxAnimation *anim;
    VfxFloatTimeline *opacityTL;
	VfxImage2D *image;
	VfxTexture2D *texture;
    
    CDBoxItem():
        index(-1),
        item(NULL),
        discMesh(NULL),
        texUniforms(NULL),
        reflectUniforms(NULL),
        CDtexUniforms(NULL),
        CDreflectUniforms(NULL),
        anim(NULL),
        opacityTL(NULL),
		image(NULL),
		texture(NULL)
    {};
};

class VappMusicPlayerCoverFlow3DPage : public VappMusicPlayerPlayerBase
{
    VFX_DECLARE_CLASS(VappMusicPlayerCoverFlow3DPage);

// Variables
private:
    VfxScrRotateTypeEnum m_pageOrientation;
    VappMusicPlayerCoverFlow3DSongListPanel *m_panelSongList;

    // for 3D
    VfxWorld *m_3dWorld;
    VfxCamera *m_camera;
    VfxLight *m_light;
    VfxMesh *m_floor;
    VfxMesh *m_bgPlane;
    VfxFrame *m_frame;
    VfxTextureFrame *m_textureList;
    
    VfxArray <CDBoxItem*> m_cdboxPool;
    CDBoxItem           m_openCDBoxItem;

    VfxAnimation        *m_openCDBoxCamAnim;
    VfxFloatTimeline    *m_openCDBoxAnimTL;
    
    VfxTextFrame *m_textAlbumTitle;
    VfxTextFrame *m_textAlbumArtist;
    VfxTextFrame *m_textEmptyDB;

    VfxS32 m_zfactor;
    VfxS32 m_zoffset;

    VfxS32 m_playingAlbumIdx;

    VfxTimer *m_onEnteredTimer;
    
public:
    VappMusicPlayerContentProvider *m_provider;
    VappMusicPlayerListMenuProvider *m_listMenuProvider;
    VappMusicPlayerCtrlMediaCahce *m_ctrlMediaCache;
    VappMusicPlayerCoverFlow3DMenu *m_menu;
    VfxBool m_hasStartPlayback;
    VfxS32 m_openCDBoxIndex;

// Constructor / Destructor
public:
    VappMusicPlayerCoverFlow3DPage():
        m_menu(NULL),
        m_provider(NULL),
        m_listMenuProvider(NULL),
        m_ctrlMediaCache(NULL),
        m_pageOrientation(VFX_SCR_ROTATE_TYPE_NORMAL),
        m_panelSongList(NULL),
        m_hasStartPlayback(VFX_FALSE),
        m_3dWorld(NULL),
        m_camera(NULL),
        m_light(NULL),
        m_floor(NULL),
        m_bgPlane(NULL),
        m_frame(NULL),
        m_textureList(NULL),
        m_textAlbumTitle(NULL),
        m_textAlbumArtist(NULL),
        m_textEmptyDB(NULL),
        m_openCDBoxCamAnim(NULL),
        m_openCDBoxAnimTL(NULL),
        m_openCDBoxIndex(-1),
        m_playingAlbumIdx(-1),
        m_onEnteredTimer(NULL)
    {};

    VappMusicPlayerCoverFlow3DPage(VfxScrRotateTypeEnum pageOrientation):
        m_menu(NULL),
        m_provider(NULL),
        m_listMenuProvider(NULL),
        m_ctrlMediaCache(NULL),
        m_pageOrientation(pageOrientation),
        m_panelSongList(NULL),
        m_hasStartPlayback(VFX_FALSE),
        m_3dWorld(NULL),
        m_camera(NULL),
        m_light(NULL),
        m_floor(NULL),
        m_frame(NULL),
        m_textureList(NULL),
        m_textAlbumTitle(NULL),
        m_textAlbumArtist(NULL),
        m_textEmptyDB(NULL),
        m_openCDBoxCamAnim(NULL),
        m_openCDBoxAnimTL(NULL),
        m_openCDBoxIndex(-1),
        m_playingAlbumIdx(-1),
        m_onEnteredTimer(NULL)
    {};
      
// Public methods
public:
    void setAlbumCover(VfxImageBuffer &imgBuf);
    VfxU32 getAlbumCount();
    void getAlbumInfo(VfxU32 idx, VfxWString& artist, VfxWString& album);
    VfxU32 getAlbumID(VfxU32 idx);
    void getAlbumImage(VfxU32 idx, VfxImageSrc &imgSrc);
    void getOpenAlbumImage(VfxImageSrc &imgSrc);
    void hideAlbumDetailPanel(VfxBool anim = VFX_TRUE);
    void updateCellImage(VfxU32 index, VfxImageBuffer imgBuf);
    void hideAllCellImages(VfxBool isAnim = VFX_FALSE);
    void updateAlbumInfo(VfxU32 index);
    void updateAlbumPanelItem(VfxS32 index);
    void updateCellInfo(VfxU32 index) {};

    CDBoxItem* getCDBox(VfxU32 index, VfxBool &isNewCreated);
    void releaseCDBox(VfxU32 index, VfxGroup *item);
    void onPlaybackStateChange(PlaybackStateEnum state);
    void setCDBoxCover(VfxU32 index, VfxImageSrc &imgSrc);
    void setOpenCDBoxCover(VfxImageSrc &imgSrc);
    CDBoxItem* findCDBoxItem(VfxU32 index);
    void openCDBoxSongList(VfxU32 index);
    void closeCDBoxSongList();
    void setSceneTreeOrder();
    void setBgPlaneOrder();
    VfxFrame* get3DFrame();
    VfxS32 findPickedNode(VfxNode *node);
    VfxBool isCDBoxOpened();
    VfxBool isCDBoxOpeningAnimation();

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
    void onQueryRotateEx(VfxScreenRotateParam &param);
    VfxBool onPenInput(VfxPenEvent &event);
    VfxBool onKeyInput(VfxKeyEvent &event);

// Implementation
private:
    void bindLightPos(VfxPass *pass);
    VfxPass* addReflectionPass(VfxMaterial *mtl, VfxResId vs, VfxResId fs);
    void swapPass(VfxMaterial *mtl, VfxU32 index1, VfxU32 index2);
	void focusActiveAlbum();
    void onCDBoxOpenAnimTLStopped(VfxBaseTimeline *timeline, VfxBool stopped);
    void doCloseCDBoxSongList();

    static vrt_render_dirty_type_enum fpeCallback(vrt_frame_visual_property_struct *target_frame,
                                            const vrt_frame_visual_property_struct *watch_frame,
                                            void *user_data,
                                            vrt_u32 user_data_size);

	void showHideAlbumPlayIcon(VfxS32 index, VfxBool isShow);
    void onEnteredPostProc(VfxTimer *t);
    void onMenuScrollStateChanged(VfxObject* obj);
};


/***************************************************************************** 
 * VappMusicPlayerCoverFlow3DMenuCache is the class to store the data of 3D cover flow menu cells
 *****************************************************************************/

class VappMusicPlayerCoverFlow3DMenuCache : public VfxBase
{
// Declaration
public:
    typedef void* DATAPTR;
    typedef VfxWeakPtr <VfxFloatTimeline> VfxFloatTimelineWeakPtr;
    typedef VfxWeakPtr <VfxGroup> VfxFloatMeshPtr;

    class Key : public VfxBase
    {
    public:
        VfxS32 cell;
        VfxS32 subCell;

        Key() : 
            cell(-1), subCell(-1) {}

        Key(const Key& another) : 
            cell(another.cell), subCell(another.subCell) {}

        Key(VfxS32 _cell, VfxS32 _subCell) :  
            cell(_cell), subCell(_subCell) {}

        bool operator == (const Key& another)
        {
            return cell == another.cell && subCell == another.subCell;
        }
        bool operator != (const Key& another)
        {
            return cell != another.cell || subCell != another.subCell;
        }
        bool operator < (const Key& another)
        {
            VfxU64 key1 = VfxU64((VfxU64(cell) << 32) + (VfxU32)subCell);
            VfxU64 key2 = VfxU64((VfxU64(another.cell) << 32) + (VfxU32)another.subCell);

            return key1 < key2;
        }
        bool isValid()
        {
            return cell >= 0 && subCell >= 0;
        }
    };

    class Item : public VfxBase
    {
    public:
        Key                         key;
        VfxFloatMeshPtr             ptr;
    };
    typedef Item* ItemPtr;
    
// Constructor / Destructor
public:
    // <group DOM_WheelMenu_VcpWheelMenuCache_Constructor/Destructor>
    // Constructor
    VappMusicPlayerCoverFlow3DMenuCache();
    // <group DOM_WheelMenu_VcpWheelMenuCache_Constructor/Destructor>
    // Destructor
    virtual ~VappMusicPlayerCoverFlow3DMenuCache();

// Method
public:
    // <group DOM_WheelMenu_VcpWheelMenuCache_Method>
    // Correlate the menu and the cache
    void init(VappMusicPlayerCoverFlow3DMenu* parent);

    // <group DOM_WheelMenu_VcpWheelMenuCache_Method>
    // Disconnect the menu and the cache
    void deinit();

    // <group DOM_WheelMenu_VcpWheelMenuCache_Method>
    // Whether a pos is in cache
    VfxBool isInCache(Key p);

    // <group DOM_WheelMenu_VcpWheelMenuCache_Method>
    // Get a item by position
    VfxGroup* getItem(Key p);
    
    // <group DOM_WheelMenu_VcpWheelMenuCache_Method>
    // Set a item to cahce.
    void setItem(Key p, VfxGroup* group);

    // <group DOM_WheelMenu_VcpWheelMenuCache_Method>
    // Remove a item by position
    void removeItem(Key p);

    // <group DOM_WheelMenu_VcpWheelMenuCache_Method>
    // Close a item (remove it from cache and close it)
    void closeItem(Key p);
    
    // <group DOM_WheelMenu_VcpWheelMenuCache_Method>
    // Clear all cache
    void clear();

    // <group DOM_WheelMenu_VcpWheelMenuCache_Method>
    // Get Item count
    VfxS32 getCount()
    {
        return m_itemCount;
    }

// Variable
protected:
    // <group DOM_WheelMenu_VcpWheelMenuCache_Variable>
    VfxS32          m_itemCount;        // Item count in cache.
    // <group DOM_WheelMenu_VcpWheelMenuCache_Variable>
    VfxS32          m_itemTotalCount;   // Item pool size.
    // <group DOM_WheelMenu_VcpWheelMenuCache_Variable>
    ItemPtr         *m_items;           // Item pool.
    // <group DOM_WheelMenu_VcpWheelMenuCache_Variable>
    VappMusicPlayerCoverFlow3DMenu    *m_menu;            // The menu object.

// Implementation
protected:
    // <group DOM_WheelMenu_VcpWheelMenuCache_Implementation>
    // Binary search in the cache pool.
    // RETURNS: the search index in the pool.
    VfxS32 bisect_left(Key key);
};


/***************************************************************************** 
 * VappMusicPlayerCoverFlow3DMenu is the layout of cover flow menu
 *****************************************************************************/

struct VappMusicPlayerCoverFlow3DMenuCellHeader
{
    VfxU32 flag;
    VfxS32 cell;
    VfxS32 subCell;
    VfxS32 indexOffset;
    VfxU32 indexOffsetTick;
    void *self;
};

#define CELL_HEADER_SIZE sizeof(VappMusicPlayerCoverFlow3DMenuCellHeader)

class VappMusicPlayerCoverFlow3DMenu : public VfxControl
{
    VFX_DECLARE_CLASS(VappMusicPlayerCoverFlow3DMenu);

    typedef VappMusicPlayerCoverFlow3DMenu              Self;
    typedef VfxControl                                  Super;
    typedef VappMusicPlayerCoverFlow3DMenuCache         Cache;
    typedef VappMusicPlayerCoverFlow3DMenuCache::Key    Key;

// Declaration
public:

// Constructor / Destructor
public:
    // <group DOM_WheelMenu_VcpWheelMenu_Constructor/Destructor>
    VappMusicPlayerCoverFlow3DMenu():
        m_subCellCount(1),
        m_focus(-1),
        m_firstVisibleItem(0), 
        m_lastVisibleItem(0),
        m_visibleItemCount(15),
        m_focusedNum(3),
        m_defaultAnimTime(500),
        m_maxMoveOffset(0),
        m_isToSendWarning(VFX_FALSE),
        m_isToSendError(VFX_FALSE),
	    m_isScrolling(VFX_FALSE),
	    m_isTappedItemFocusing(VFX_FALSE),
        m_changeStateTimer(NULL),
        m_isSliding(VFX_FALSE),
        m_page(NULL),
		m_preCreatedCell(-1),
		m_prevTapTimeStamp(-1)
        {};

    // <group DOM_WheelMenu_VcpWheelMenu_Constructor/Destructor>
    virtual ~VappMusicPlayerCoverFlow3DMenu(){}

// Method
public:

// Override
public:
    // <group DOM_WheelMenu_VcpWheelMenu_Override>
    virtual void onInit();
    // <group DOM_WheelMenu_VcpWheelMenu_Override>
    virtual void onDeinit();

// Method
public:
    // <group DOM_WheelMenu_VcpWheelMenu_Method>
    // Get the cell frame if the frame is exist
    VfxGroup* getCellIfPresent(
        VfxS32 cell,        // [IN] The cell index
        VfxS32 subCell = 0  // [IN] The sub cell index
    );

    // <group DOM_WheelMenu_VcpWheelMenu_Method>
    // Set the focus item to index.
    void setFocus(
        VfxS32 index,               // [IN] The focus item
        VfxMsec animTime = -1,      // [IN] The animation time, 0 means no need animation. -1 means use default value.
        VfxFloat velocity = 0
    );

    // <group DOM_WheelMenu_VcpWheelMenu_Method>
    // Set the scrolling index.
    void setScrollIndex(
        VfxFloat perc,              // [IN] The focus item
        VfxMsec animTime = -1,       // [IN] The animation time, 0 means no need animation. -1 means use default value.
        VfxFloat velocity = 0
    );

    // <group DOM_WheelMenu_VcpWheelMenu_Method>
    // Get the scrolling index.
    VfxFloat getScrollIndex();

    // <group DOM_WheelMenu_VcpWheelMenu_Method>
    // Get the focus index.
    VfxS32 getFocus() const
    {
        return m_focus;
    }

    // <group DOM_WheelMenu_VcpWheelMenu_Method>
    // Whenever any property change, call it to refresh wheel menu.
    void update();

    // <group DOM_WheelMenu_VcpWheelMenu_Method>
    // Return the min index that is visible in the screen.
    VfxS32 getFirstVisibleIndex();

    // <group DOM_WheelMenu_VcpWheelMenu_Method>
    // Return the max index that is visible in the screen.
    // NOTE: This return index is not visible in the screen, if you would like to loop all visible
    //       items, you don't need to include this value.
    // EXAMPLES:
    //      <code>for (VfxS32 i = getFirstVisibleIndex(); i < getLastVisibleIndex(); i++) {} </code>
    VfxS32 getLastVisibleIndex();

    // <group DOM_WheelMenu_VcpWheelMenu_Method>
    // Set an userdata to all subcell of a cell. 
    // The user data will pass to frame effect callback.
    // This function will copy the data.
    void setCellUserData(
        VfxS32 index,       // [IN] The cell index
        void* data,         // [IN] The user data pointer
        VfxU32 dataSize     // [IN] The user data size
    );

    // <group DOM_WheelMenu_VcpWheelMenu_Method>
    // Set an userdata to a cell. 
    // The user data will pass to frame effect callback.
    // This function will copy the data.
    void setCellUserData(
        VfxS32 cell,        // [IN] The cell index
        VfxS32 subCell,     // [IN] The sub cell index
        VfxGroup* group,    // [IN] The cell frame pointer
        void* data,         // [IN] The user data pointer
        VfxU32 dataSize     // [IN] The user data size
    );

	// <group DOM_WheelMenu_VcpWheelMenu_Method>
	// Return the state of scroll animation.
	// If the menu is scrolling, the return value is VFX_TRUE;
	VfxBool getIsScrolling()
	{
		return m_isScrolling;
	}

    // <group DOM_WheelMenu_VcpWheelMenu_Method>
    // Force close a cell (including subcell) and re-create cell again.
    // This is usually used when users want to change the cell objects.
    void resetCell(
        VfxS32 index    // [IN] The cell index which will be create again.
    );

    // <group DOM_WheelMenu_VcpWheelMenu_Method>
    // Remove this cell and move proceed object to new index.
    // For example, if you withdraw cell n, then n+1 will change index to n, 
    // and n+2 will change index to n+1.
    void withdrawCell(
        VfxS32 index,                           // [IN] Cell index
        VfxBool behindItemGoAhead = VFX_TRUE    // True means n+1 item will move to n position.
                                                // False means n-1 item will move to n position.
    );

    // <group DOM_WheelMenu_VcpWheelMenu_Method>
    // Pull out this sub cell from menu.
    // RETURNS: the original sub-cell frame. NULL means this cell is not in screen now.
    VfxGroup* pullOutSubCell(
        VfxS32 cell,                            // [IN] The cell index
        VfxS32 subCell                          // [IN] The sub cell index
    );

    // <group DOM_WheelMenu_VcpWheelMenu_Method>
    // Push In this sub cell from menu.
    void pushInSubCell(
        VfxGroup *group,                        // [IN] The frame be put in
        VfxS32 cell,                            // [IN] The cell index
        VfxS32 subCell                          // [IN] The sub cell index
    );

    VfxS32 getVisibleCount();

    VfxS32 getFocusedNum();

    VfxS32 getFocus();

    VcpMenuRegion getRealContentRegion();

    void updateMenu();

    VfxBool isScrolling();

// Overridable
protected:  

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Return the sub cell count of a cell.
    virtual VfxS32 getSubCellCount();

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Return the count of menu items.
    // Derived class should override this function.
    virtual VfxS32 getCount();
    
    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Return the visible menu item count which behind the focus item.
    // Derived class should override this function.
    virtual VfxS32 getBehindCount();

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Return the visible menu item count which ahead the focus item.
    // Derived class should override this function.
    virtual VfxS32 getAheadCount();

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Create a cell object.
    // Inheritor should override this function.
    // RETURNS: a sub cell object 
    virtual VfxGroup* createCell(
        VfxS32 cell,             // [IN] The cell index
        VfxS32 subCell,          // [IN] The sub cell index
        VfxBool &isNewCreated    // [OUT] If the cell is new created
    );
    
    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Notify to update a cell's position.
    // Inheritor should override this function.
    virtual void onUpdateCell(
        VfxS32      cell,        // [IN] The cell index
        VfxS32      subCell,     // [IN] The sub cell index
        VfxGroup*   group        // [IN] The cell object
    ){};

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // A notify that menu is going to close a cell
    virtual void onCloseCell(
        VfxS32 cell,             // [IN] The cell index
        VfxS32 subCell,          // [IN] The sub cell index
        VfxGroup* group          // [IN] The sub cell frame which will be closed
    );

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // A notify about Wheel menu is starting updating cell.
    virtual void onBeforeUpdateCell() {}

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // A notify about Wheel menu has completed updating cell.
    virtual void onAfterUpdateCell() {}

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Notify when the focus item is change
    virtual void onFocusIndexChange(
        VfxS32 focusItem,               // [IN] The focus item index now
        VfxS32 preFocusItem             // [IN] The previous focus item index
    );
    
    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Notify when the user start drag the menu
    virtual void handleDragStart();

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Notify when the user start drag the menu except enter/leave state
    virtual void onDragStart() {}

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Notify when the user stop drag the menu 
    virtual void handleDragEnd(
        VfxS32 xspeed,        // [IN] how fast to release the pen in x direction. Unit is point / 1sec.
        VfxS32 yspeed         // [IN] how fast to release the pen in y direction. Unit is point / 1sec.
        );

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Notify when the user stop drag the menu except enter/leave state
    virtual void onDragEnd(
        VfxS32 xspeed,        // [IN] how fast to release the pen in x direction. Unit is point / 1sec.
        VfxS32 yspeed         // [IN] how fast to release the pen in y direction. Unit is point / 1sec.
    ); 

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Notify when the menu is dragged
    virtual void handleDrag(
        VfxS32 xoffset, 
        VfxS32 yoffset);

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Notify when the menu is dragged except enter/leave state
    virtual void onDrag(
        VfxS32 xoffset, 
        VfxS32 yoffset); 

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Notify when the menu is tapped
    virtual VfxBool handleTap(VfxPoint pt);
    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Notify when the menu is tapped and cell does not move.
    virtual VfxBool onTap(VfxPoint pt);

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Notify when withdraw cell closed 
    virtual void onAfterWithdrawCellClosed()
        {}

    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Get the threshold to trigger onTap()
    virtual VfxS32 getTapThreshold()
        {
            return 20;
        }
    // <group DOM_WheelMenu_VcpWheelMenu_Overridable>
    // Get the time function when setFocus()
    virtual VfxTimingFuncIdEnum getMoveTimeFunction()
    {
        return VFX_TIMING_FUNC_ID_LINEAR;
    }

// Event
public:
	// <group DOM_WheelMenu_VcpWheelMenu_Event>
	// Emit Signal when menu is at start of scrolling.
	// void YourClass::onBeginScrolling(VfxObject* sender)
	VfxSignal1<VfxObject*> m_beginScrolling;

	// <group DOM_WheelMenu_VcpWheelMenu_Event>
	// Emit Signal when menu is at end of scrolling.
	// void YourClass::onEndScrolling(VfxObject* sender)
	VfxSignal1<VfxObject*> m_endScrolling;

// Override    
protected:
    // <group DOM_WheelMenu_VcpWheelMenu_Override>
    virtual void onUpdate();
    // <group DOM_WheelMenu_VcpWheelMenu_Override>
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    // <group DOM_WheelMenu_VcpWheelMenu_Override>
    virtual VfxBool onPenInput(VfxPenEvent &event);

// Slot
protected:
    // <group DOM_WheelMenu_VcpWheelMenu_Slot>
    void onViewBoundsChanged(VfxFrame *view, const VfxRect &old);
	// <group DOM_WheelMenu_VcpWheelMenu_Slot>
	void onTimerTick(VfxTimer *source);

// Variable
protected:
    VfxFloatTimeline *m_mainTimeline;
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
    VfxS32              m_subCellCount;
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
    VfxS32              m_focus;            // The focus index
    VfxS32              m_firstVisibleItem, // The first visible index
                        m_lastVisibleItem;  // The last visible index
    VfxS32              m_visibleItemCount;
    VfxS32              m_focusedNum;
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
    VfxFrame            *m_tracker;         // Tracker is a invisible frame. Use for frame property effect.
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
    VappMusicPlayerCoverFlow3DMenuCache   m_cache;            // The cache pool object.
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
    VfxBool             m_updating;         // Whether need to update the menu.
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
                                            // This variable is planned to removed.
    VfxFloatTimeline    *m_monitorTl;       // The timeline is used to monitor the menu region.
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
    VfxMsec             m_defaultAnimTime;  // Default item change aniamtion time.
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
                                            // For example, in setScrollIndex, you can assign -1 to use this value.
    VfxS32              m_maxMoveOffset;    // The max offset when drag. This is used for detecting tap or scroll.
	// <group DOM_WheelMenu_VcpWheelMenu_Variable>
	VfxTimer            *m_timer;
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
    VfxBool             m_isToSendWarning;
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
    VfxBool             m_isToSendError;
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
    VfxBool             m_isScrolling;
    VfxBool             m_isTappedItemFocusing;
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
    VfxMsec             m_durationPerCell[2];                
    VfxMsec             m_delay[2];                          
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
    VfxU32              m_stateTimelineCount;
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
    VfxTimer            *m_changeStateTimer;
    // <group DOM_WheelMenu_VcpWheelMenu_Variable>
    VfxBool             m_isSliding;
    // cover flow page
    VappMusicPlayerCoverFlow3DPage *m_page;
	// Last created cell index
	VfxS32				m_preCreatedCell;

    VfxS32              m_totalCount;

    // signature to verify menu life
    VfxU32 m_signature;

    // Last tapping time
    VfxMsec              m_prevTapTimeStamp;
    
// Implementation
protected:
    // <group DOM_WheelMenu_VcpWheelMenu_Implementation>
    void cleanAllCell();
    // <group DOM_WheelMenu_VcpWheelMenu_Implementation>
    void resetInternal(VfxS32 focus, VfxFloat index, VfxBool isAnim);
    // Force update menu cell
    // <group DOM_WheelMenu_VcpWheelMenu_Implementation>
    void updateContent(
        bool force  // [IN] FALSE means use VRT runtime position to update menu.
    );

    // <group DOM_WheelMenu_VcpWheelMenu_Implementation>
    friend class VappMusicPlayerCoverFlow3DMenuCache;

    // Wapper for frame property effect.
    // <group DOM_WheelMenu_VcpWheelMenu_Implementation>
    static vrt_render_dirty_type_enum framePropertyEffectCallback(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size);

    // A dummy frame property effect.
    // <group DOM_WheelMenu_VcpWheelMenu_Implementation>
    static vrt_render_dirty_type_enum dummyFramePropertyEffectCallback(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size);

    // Timeline monitor callback.
    // <group DOM_WheelMenu_VcpWheelMenu_Implementation>
    static VfxTimelineInterpolationRetEnum indexMonitorFuncCallback(
        void *output,
        const void *fromValue,
        const void *toValue,
        VfxTypeIdEnum typeId,
        VfxFloat t, 
        void *data,
        VfxU32 dataSize
    );

    static VfxTimelineInterpolationRetEnum interpolateFunc(
        void *output,
        const void *fromValue,
        const void *toValue,
        VfxTypeIdEnum typeId,
        VfxFloat t, 
        void *data,
        VfxU32 dataSize
    );

    static VfxTimelineInterpolationRetEnum opacityFunc(
        void *output,
        const void *fromValue,
        const void *toValue,
        VfxTypeIdEnum typeId,
        VfxFloat t, 
        void *data,
        VfxU32 dataSize
    );

    static VfxTimelineInterpolationRetEnum freezeFunc(
        void *output,
        const void *fromValue,
        const void *toValue,
        VfxTypeIdEnum typeId,
        VfxFloat t, 
        void *data,
        VfxU32 dataSize
    );

    // Notify content warning callback.
    // <group DOM_WheelMenu_VcpWheelMenu_Implementation>
    static void emitContentWarning(void *arg);

    // Notify content error callback.
    // <group DOM_WheelMenu_VcpWheelMenu_Implementation>
    static void emitContentError(void *arg);

private:
    // Get the cell header that in front of userdata.
    // <group DOM_WheelMenu_VcpWheelMenu_Implementation>
    //const VappMusicPlayerCoverFlow3DMenuCellHeader* getCellHeader(Key key);

    // Set the cell header
    // <group DOM_WheelMenu_VcpWheelMenu_Implementation>
    void setCellHeader(Key key, VappMusicPlayerCoverFlow3DMenuCellHeader* header, VfxBool isNewCreated);

    // Check if the this tap is too closed to previous
    VfxBool isTapTimeout(VfxMsec timeStamp);

// API that Cache will use
protected:
    // <group DOM_WheelMenu_VcpWheelMenu_Implementation>
    friend class VappMusicPlayerCoverFlow3DMenuCache;
    // <group DOM_WheelMenu_VcpWheelMenu_Implementation>
    void closeCell(VfxS32 cell, VfxS32 subCell, VfxGroup* group);
    // <group DOM_WheelMenu_VcpWheelMenu_Implementation>
    void closeCell(VfxS32 cell);
};



/***************************************************************************** 
 * VappMusicPlayerCoverFlow3DSongListPanel is the layout of cover flow menu
 *****************************************************************************/

class VappMusicPlayerListMenu;

class VappMusicPlayerCoverFlow3DSongListPanel : public VfxControl
{
    VFX_DECLARE_CLASS(VappMusicPlayerCoverFlow3DSongListPanel);

// Variables
private:
    enum
    {
#if defined(__MMI_MAINLCD_240X320__)
        panelWidth = 128, 
        panelHeight = 127,
        titleBarHeight = 30,
        titleBarTextWidth = 70,
        titleBarTextHeight = 24,
        titleBarFontSize1 = 18,
        titleBarFontSize2 = 14,
        titleBarMarginX = 3,
        titleBarMarginY = 4,
        titleBarNumTextWidth = 64,
        titleBarNumTextHeight = 20,
        titleBarNumTextShiftY = 4,
        listMenuItemHeight = 30,
        panelSongListPosX = 22,
        panelSongListPosY = 49,

#elif defined(__MMI_MAINLCD_240X400__)
        panelWidth = 160, 
        panelHeight = 159,
        titleBarHeight = 36,
        titleBarTextWidth = 86,
        titleBarTextHeight = 30,
        titleBarFontSize1 = 20,
        titleBarFontSize2 = 16,
        titleBarMarginX = 7,
        titleBarMarginY = 8,
        titleBarNumTextWidth = 80,
        titleBarNumTextHeight = 30,
        titleBarNumTextShiftY = 8,
        listMenuItemHeight = 36,
        panelSongListPosX = 28,
        panelSongListPosY = 31,

#elif defined(__MMI_MAINLCD_320X480__)
        panelWidth = 192, 
        panelHeight = 192,
        titleBarHeight = 36,
        titleBarTextWidth = 110,
        titleBarTextHeight = 30,
        titleBarFontSize1 = 20,
        titleBarFontSize2 = 16,
        titleBarMarginX = 7,
        titleBarMarginY = 8,
        titleBarNumTextWidth = 80,
        titleBarNumTextHeight = 30,
        titleBarNumTextShiftY = 8,
        listMenuItemHeight = 36,
        panelSongListPosX = 30,
        panelSongListPosY = 53,

#else //(__MMI_MAINLCD_480X800__)
        panelWidth = 321, 
        panelHeight = 320,
        titleBarHeight = 52,
        titleBarTextWidth = 200,
        titleBarTextHeight = 45,
        titleBarFontSize1 = 30,
        titleBarFontSize2 = 24,
        titleBarMarginX = 10,
        titleBarMarginY = 12,
        titleBarNumTextWidth = 150,
        titleBarNumTextHeight = 45,
        titleBarNumTextShiftY = 10,
        listMenuItemHeight = 52,
        panelSongListPosX = 50,
        panelSongListPosY = 61,
#endif

    };

    VfxU32 m_albumIndex;
    VappMusicPlayerContentProvider *m_provider;    
    VappMusicPlayerListMenuProvider *m_listMenuProvider;
    VappMusicPlayerListMenu *m_listMenu;

public:
    
// Constructor / Destructor
public:
    VappMusicPlayerCoverFlow3DSongListPanel(){};
    
    VappMusicPlayerCoverFlow3DSongListPanel(VfxU32 index) :
      m_albumIndex(index),
      m_provider(NULL),
      m_listMenuProvider(NULL),
      m_listMenu(NULL)
    {};

// Public methods
public:
    void updateListMenu(VfxS32 index = -1);
    VfxU32 getFirstSongId();
    void setListMenuDisabled(VfxBool isDisabled);
    
// Override methods
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    virtual VfxBool onPenInput(VfxPenEvent &event);
    
// Implementation
private:
    void onListItemTapped(VcpListMenu *menu, VfxU32 index);
};


#endif /*   __VAPP_MUSIC_PLAYER_COVERFLOW_3D_H__   */

#endif //__COSMOS_3D_V10__
#endif //__COSMOS_MUSICPLY__
