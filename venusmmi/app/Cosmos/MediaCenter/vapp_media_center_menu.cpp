/*****************************************************************************
*  Copyright Statement:
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
 *  vapp_media_center_menu.cpp
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

#include "MMI_features.h" 
#ifdef __MMI_3D_MEDIA_CENTER__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_config.h"
#include "vfx_object.h"
#include "vcp_include.h"
#include "vfx_compositing_mode.h";

#include "vapp_media_center_menu.h"
#include "vapp_media_center_util.h"

extern "C"
{
#include "mmi_rp_vapp_media_center_def.h"
#include "AppMgrSrvGprot.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/
//#define __MEDIA_CENTER_LOOP_MENU__ 
//static VfxBool g_loopMenuSupported = VFX_FALSE;
extern VfxBool g_debugMode;

#define MEDIA_CEMTER_LOOP_MENU_ORIGN 50000
#define MEDIA_CEMTER_LOOP_MENU_MIN_INDEX 0 
#define MEDIA_CEMTER_LOOP_MENU_MAX_INDEX (100000)
#define MEDIA_CEMTER_LOOP_MENU_ENTRY_ANIM_TURNS (2)

/***************************************************************************** 
 * Class Implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappMediaCenterPage", VappMediaCenterPage, VfxPage);
VFX_IMPLEMENT_CLASS("VappMediaCenterMenu", VappMediaCenterMenu, VfxControl);
VFX_IMPLEMENT_CLASS("VappMediaCenterTextBoard",VappMediaCenterTextBoard, VfxGroup);

/***************************************************************************** 
 * Class Implementation : VappMediaCenterPage
 *****************************************************************************/

VappMediaCenterPage::VappMediaCenterPage():
    m_world(NULL),
    m_bgAnimPly(NULL),
    m_menu(NULL),
    m_delayEnteredTimer(NULL),
    m_mementoFocus(0)
{
} 

void VappMediaCenterPage::onInit()
{
    _ME_TRACE("[MediaCenter][Page] onInit()");
    MEDIA_CENTER_MEASURE_TIME_START("MP0");

    VfxPage::onInit();

    // Rendering hints
    setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
    setHints((VfxFrameHintsEnum)(VFX_FRAME_HINTS_DISABLE_COLOR_KEY | VFX_CACHE_MODE_PREVENT_PARENTS));
    setBgColor(VFX_COLOR_TRANSPARENT);
    
    // Layout
    setStatusBar(VFX_FALSE);
    setSize(LCD_WIDTH, LCD_HEIGHT);

    // background anim
    setupBackground();

    MEDIA_CENTER_MEASURE_TIME_STOP("MPI");
}

void VappMediaCenterPage::onEnter(VfxBool isBack)
{
    _ME_TRACE_1("[MediaCenter][Page] onEnter[%d]", isBack);
    VfxPage::onEnter(isBack);

    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        _ME_TRACE_1("[MediaCenter][Page] onEnter[%d], snapshot drawing", isBack); 
    }
}

void VappMediaCenterPage::onExit(VfxBool isBack)
{
    destroyDelayEnteredTimer();

    _ME_TRACE_1("[MediaCenter][Page] onExit[%d]", isBack);
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        _ME_TRACE_1("[MediaCenter][Page] onExit[%d], snapshot drawing", isBack); 
    }

    VfxPage::onExit(isBack);
}

void VappMediaCenterPage::onEntered()
{
    _ME_TRACE_1("[MediaCenter][Page] onEntered, snapshot[%d]", (getMainScr() && getMainScr()->getIsSnapshotDrawing()));

    VfxPage::onEntered();

    // two pass content creation to enhance respond time of app entry 
    createDelayEnteredTimer();
}

void VappMediaCenterPage::onExited()
{
    _ME_TRACE_1("[MediaCenter][Page] onExited, snapshot[%d]", (getMainScr() && getMainScr()->getIsSnapshotDrawing()));
    VfxPage::onExited();
}

void VappMediaCenterPage::onExited2()
{
    _ME_TRACE_2("[MediaCenter][Page] onExited2_1, m_mementoFocus[%d], snapshot[%d]", m_mementoFocus, (getMainScr() && getMainScr()->getIsSnapshotDrawing()));
    if(m_menu)
    {
        m_mementoFocus = m_menu->getFocus();
        _ME_TRACE_1("[MediaCenter][Page] onExited2_2, m_mementoFocus[%d]", m_mementoFocus);
        m_mementoFocus = vfxMax(0, vfxMin(m_mementoFocus, m_menu->getCount() -1));
        _ME_TRACE_1("[MediaCenter][Page] onExited2_3, m_mementoFocus[%d]", m_mementoFocus);
    }

    VFX_OBJ_CLOSE(m_menu);
    VfxPage::onExited2();
}

VfxBool VappMediaCenterPage::onPenInput(VfxPenEvent &event)
{
    return VfxPage::onPenInput(event);
}

void VappMediaCenterPage::get3DResourcePath(VfxId id, VfxWString &path) const
{
    switch(id)
    {
        case 'BGS':
            path = VFX_WSTR("D:\\MediaCenter\\scene\\scene.scn");
            return;
        case 'BGA':
            path = VFX_WSTR("D:\\MediaCenter\\scene\\scene.ani");
            return;
        default:
            path = VFX_WSTR_EMPTY;
            return;
    }
}
void VappMediaCenterPage::get3DResourcePath(VfxId id, VfxResId &path) const
{
    switch(id)
    {
        case 'BGS':
            path = SCN_ID_VAPP_MEDIA_CENTER_SCENE;
            return;
        case 'BGA':
            //path = ANI_ID_VAPP_MEDIA_CENTER_ANIM;
            return;
        default:
            return;
    }
}

// TODO: motify background image (size and  mesh) if  we turn on change camera view in future
// TODO: check render_option aspect ratio if scene distortion happened (we need to define different aspect ratio for different resultion)
void VappMediaCenterPage::setupBackground()
{
/*
    setImgContent(VfxImageSrc(IMG_ID_VAPP_MEDIA_CENTER_APP_BG));
    
    VfxFrame *frame = NULL;
    VFX_OBJ_CREATE(frame, VfxFrame, this);
    frame->setSize(getSize());
    frame->setHints((VfxFrameHintsEnum)(VFX_FRAME_HINTS_DISABLE_COLOR_KEY | VFX_CACHE_MODE_PREVENT_PARENTS));
    frame->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
    frame->setAnchor(0.5f, 0.5f);
    frame->setPos(getSize().width/2, getSize().height/2);
    frame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    // 3D world
    VFX_OBJ_CREATE(m_world, VfxWorld, this);
    frame->setWorld(m_world);
    setWorld(m_world);    
*/
    // 3D world
    VFX_OBJ_CREATE(m_world, VfxWorld, this);
    setWorld(m_world);

    // load background source
    do
    {
        VappMediaCenter3DResPath scenePath;
        get3DResourcePath('BGS', scenePath);
        VfxAssetLoader::loadScene(m_world, scenePath, VFX_TRUE, VFX_TRUE);
/*
        VappMediaCenter3DResPath animPath;
        get3DResourcePath('BGA', animPath);        
        VFX_OBJ_CREATE(m_bgAnimPly, VappMediaCenterAnimTimeline, m_world);
        m_bgAnimPly->configAnim(animPath, m_world);
        m_bgAnimPly->m_signalStopped.connect(this, &VappMediaCenterPage::onBgAnimPlayFinished);
*/
    }while(0);
}

void VappMediaCenterPage::onBgAnimPlayFinished(VfxBaseTimeline *timeline, VfxBool isStop)
{
    VFX_UNUSED(isStop);
    if(timeline)
    {
        timeline->m_signalStopped.disconnect(this, &VappMediaCenterPage::onBgAnimPlayFinished);
    }
    if(NULL == m_menu)
    {
        // setup menu
        setupMenu();
    }
}
// TODO: modify loop menu impletation
void VappMediaCenterPage::setupMenu()
{
    _ME_TRACE("[MediaCenter][Page] setupMenu()");
    MEDIA_CENTER_MEASURE_TIME_START("MPM");

    VFX_OBJ_CREATE(m_menu, VappMediaCenterMenu, this);
    m_menu->setPos(VfxPoint(0, 0));
    m_menu->setBounds(this->getBounds());
    m_menu->setFocused(VFX_TRUE);

    m_menu->configWorldAndCamera(m_world);
    VappMediaCenterAppItems *provider;
    VFX_OBJ_CREATE(provider, VappMediaCenterAppItems, this);
    m_menu->configContentProvider(provider);  

    //VfxS32 focusIndex = (0 < provider->getAppItemCount())? (provider->getAppItemCount() - 1): 0;
    //m_menu->setFocus(focusIndex, 0); 
    m_menu->setFocus(m_mementoFocus, 0); 
    
    MEDIA_CENTER_MEASURE_TIME_STOP("MPM");
}
// TODO: evaluate loading resource time
void VappMediaCenterPage::createDelayEnteredTimer()
{
    if(NULL == m_delayEnteredTimer)
    {
        VFX_OBJ_CREATE(m_delayEnteredTimer, VfxTimer, this);
        m_delayEnteredTimer->setStartDelay(10);
        m_delayEnteredTimer->setDuration(0);
    }
    m_delayEnteredTimer->m_signalTick.connect(this, &VappMediaCenterPage::onDelayEntered );
    m_delayEnteredTimer->start();
}

void VappMediaCenterPage::destroyDelayEnteredTimer()
{
    if(m_delayEnteredTimer)
    {
        m_delayEnteredTimer->m_signalTick.disconnect(this, &VappMediaCenterPage::onDelayEntered);
        m_delayEnteredTimer->stop();
        VFX_OBJ_CLOSE(m_delayEnteredTimer);
        m_delayEnteredTimer = NULL;
    }
}

//#define __MEDIA_CENTER_ANIM_BG__
void VappMediaCenterPage::onDelayEntered(VfxTimer *timer)
{
    _ME_TRACE("[MediaCenter][Page] onDelayEntered()");
    MEDIA_CENTER_MEASURE_TIME_START("MP3");
    
#if defined(__MEDIA_CENTER_ANIM_BG__)        
    if(m_bgAnimPly)
    {
        m_bgAnimPly->start();
    }
#else 
    onBgAnimPlayFinished(NULL, VFX_FALSE);
#endif
        
    MEDIA_CENTER_MEASURE_TIME_START("MP3");
}

/***************************************************************************** 
 * Class Implementation : VappMediaCenterMenuCache
 *****************************************************************************/
VappMediaCenterMenuCache::VappMediaCenterMenuCache() : 
    m_itemCount(0), 
    m_itemTotalCount(VCP_MENUCACHE_ADDITION),
    m_items(NULL),
    m_menu(NULL)
{
}

VappMediaCenterMenuCache::~VappMediaCenterMenuCache()
{
    VFX_DEV_ASSERT(m_itemTotalCount == 0);
    VFX_DEV_ASSERT(m_itemCount == 0);
    VFX_DEV_ASSERT(m_items == NULL);
}

void VappMediaCenterMenuCache::init(VappMediaCenterMenu* parent)
{
    VFX_DEV_ASSERT(m_menu == NULL);
    m_menu = parent;
   
    VFX_ALLOC_MEM(m_items, m_itemTotalCount * sizeof(ItemPtr), m_menu);
    memset(m_items, 0, sizeof(ItemPtr) * m_itemTotalCount);
}

void VappMediaCenterMenuCache::deinit()
{
    VFX_DEV_ASSERT(m_itemCount == 0);
    VFX_DEV_ASSERT(m_menu);

    VFX_FREE_MEM(m_items);

    m_menu = NULL;
    m_items = NULL;
    m_itemCount = 0;
    m_itemTotalCount = 0;
}

VfxBool VappMediaCenterMenuCache::isInCache(Key p)
{
    if (!p.isValid())
        return VFX_FALSE;

    VfxS32 idx = bisect_left(p);

    if (idx < m_itemCount && m_items[idx]->key == p)
        return VFX_TRUE;
    
    return VFX_FALSE;
}

VfxGroup* VappMediaCenterMenuCache::getItem(Key p)
{
    if (!p.isValid())
        return NULL;
    
    VfxS32 idx = bisect_left(p);
    if (idx >= m_itemCount) // cannot find
        return NULL;

    if (m_items[idx]->key != p)
        return NULL;

    return m_items[idx]->ptr.get();
}

void VappMediaCenterMenuCache::setItem(Key p, VfxGroup* group)
{
    if (!p.isValid())
    {
        VFX_ASSERT(0);
        return;
    }
    
    VfxS32 idx = bisect_left(p);

    if (idx < m_itemCount && m_items[idx]->key == p)
    {
        m_items[idx]->ptr = group;
    }
    else
    {
        VFX_DEV_ASSERT(idx <= m_itemCount);

        if (m_itemCount == m_itemTotalCount)
        {
            // the space is not enough
            ItemPtr *new_items;

            m_itemTotalCount += VCP_MENUCACHE_ADDITION;

            //VFX_NEW_ARRAY(new_items, ItemPtr, m_itemTotalCount);
            VFX_ALLOC_MEM(new_items, m_itemTotalCount * sizeof(ItemPtr), m_menu);

            memset(new_items, 0, sizeof(ItemPtr) * m_itemTotalCount);
            memcpy(new_items, m_items, sizeof(ItemPtr) * m_itemCount);
            
            VFX_FREE_MEM(m_items);

            m_items = new_items;
        }
    
        VFX_DEV_ASSERT(m_itemTotalCount > m_itemCount);

        m_itemCount++;
        for (VfxS32 i = m_itemCount - 1; i > idx; i--)
        {
            m_items[i] = m_items[i - 1];
        }
        VFX_ALLOC_NEW(m_items[idx], Item, m_menu);
        m_items[idx]->key = p;
        m_items[idx]->ptr = group;
    }
}


void VappMediaCenterMenuCache::closeItem(Key p)
{
    VFX_DEV_ASSERT(m_menu);
    VfxGroup* group = getItem(p);
    removeItem(p);
    if (group)
    {
        m_menu->closeCell(p.cell, p.subCell, group);
    }
}

void VappMediaCenterMenuCache::removeItem(Key p)
{
    if (!p.isValid())
    {
        VFX_DEV_ASSERT(0);
        return;
    }

    if (m_itemCount == 0)
    {
        // nothing can remove
        return;
    }

    VfxS32 idx = bisect_left(p);

    if (idx >= m_itemCount || m_items[idx]->key != p)
    {
        // Cannot found item
        return;
    }

    if (idx < m_itemCount && m_items[idx]->key == p)
    {
        VFX_DELETE(m_items[idx]);
        for (VfxS32 i = idx; i < m_itemCount - 1; i++)
        {
            m_items[i] = m_items[i + 1];
        }
        m_itemCount--;
    }

    // we can reduce space
    if (m_itemTotalCount - m_itemCount >= 2 * VCP_MENUCACHE_ADDITION)
    {
        // the space is not enough

        VfxS32 newTotal = VFX_MAX(m_itemCount, VCP_MENUCACHE_ADDITION);

        newTotal = VCP_MENUCACHE_ADDITION * ((newTotal + VCP_MENUCACHE_ADDITION - 1) / VCP_MENUCACHE_ADDITION);

        ItemPtr *new_items;
        //VFX_NEW_ARRAY(new_items, ItemPtr, newTotal);
        VFX_ALLOC_MEM(new_items, newTotal * sizeof(ItemPtr), m_menu);
        memset(new_items, 0, sizeof(ItemPtr) * newTotal);

        memcpy(new_items, m_items, sizeof(ItemPtr) * m_itemCount);
        m_itemTotalCount = newTotal;
        //VFX_DELETE_ARRAY(m_items);
        VFX_FREE_MEM(m_items);
        m_items = new_items;

    }
}

void VappMediaCenterMenuCache::clear()
{
    for (VfxS32 i = m_itemCount - 1; i >= 0; i--)
    {
        Key p = m_items[i]->key;            

        m_menu->closeCell(p.cell, p.subCell, m_items[i]->ptr.get());
        VFX_DELETE(m_items[i]);

        m_itemCount--;
    }
    VFX_DEV_ASSERT(m_itemCount == 0);
}

VfxS32 VappMediaCenterMenuCache::getChellIndex(Key key)
{
    return bisect_left(key);
}

VfxS32 VappMediaCenterMenuCache::bisect_left(Key key)
{
    VfxS32 lo = 0, hi = m_itemCount, mid;
    while (lo < hi)
    {
        mid = (lo + hi) / 2;
        if (m_items[mid]->key < key) 
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

/***************************************************************************** 
 * Class Implementation : VappMediaCenterMenu
 *****************************************************************************/
 VappMediaCenterMenu::VappMediaCenterMenu():
            m_mainTimeline(NULL)        
            ,m_subCellCount(1)
            ,m_focus(-1)
            ,m_firstVisibleItem(0) 
            ,m_lastVisibleItem(0)
            ,m_visibleItemCount(4)
            ,m_focusedNum(2)
            ,m_defaultAnimTime(500)
            ,m_maxMoveOffset(0)
            ,m_isToSendWarning(VFX_FALSE)
            ,m_isToSendError(VFX_FALSE)
            ,m_isScrolling(VFX_FALSE)
            ,m_changeStateTimer(NULL)
            ,m_isSliding(VFX_FALSE)
            ,m_preCreatedCell(-1)
            ,m_totalCount(0)
            ,m_world(NULL)
            ,m_camera(NULL)
            ,m_cameraQTL(NULL)  
            ,m_provider(NULL)
            ,m_titleTextBoard(NULL)
            ,m_delayFocusCellOpeningTimer(NULL)
            ,m_isDraging(VFX_FALSE)
            {};
void VappMediaCenterMenu::onInit()
{
    Super::onInit();

    m_cache.init(this);
    m_signalBoundsChanged.connect(this, &Self::onViewBoundsChanged);
    registerKeyHandler(VFX_KEY_CODE_SPECIAL_ALL_ARROW);

	// Tracker is a invisible object for FPE
    VFX_OBJ_CREATE(m_tracker, VfxFrame, this);
    m_tracker->setOpacity(0);
    m_tracker->setAutoAnimate(VFX_TRUE);
    m_tracker->setFilterTiming(0.0f);

	// Create the monitor timeline
    VFX_OBJ_CREATE(m_monitorTl, VfxFloatTimeline, this);

	// Create the timer to detect scrolling state
    VFX_OBJ_CREATE(m_timer, VfxTimer, this);
    m_timer->m_signalTick.connect(this, &Self::onTimerTick);

    // Create the timer to detect scrolling state
    //VFX_OBJ_CREATE(m_changeStateTimer, VfxTimer, this);
    //m_changeStateTimer->m_signalTick.connect(this, &Self::onEndofChangeTimer);

    // Get the sub cell count
    m_subCellCount = getSubCellCount();

    VFX_OBJ_CREATE(m_mainTimeline, VfxFloatTimeline, this);
    m_mainTimeline->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_mainTimeline->setTarget(this);
    m_mainTimeline->setFromValue(0);
    m_mainTimeline->setRepeatCount(1);
    m_mainTimeline->setCustomInterpolateFunc(freezeFunc, NULL, 0);

    m_endScrolling.connect(this, &VappMediaCenterMenu::onEndScrolling);

    checkUpdate();
}

void VappMediaCenterMenu::onDeinit()
{
    m_endScrolling.disconnect(this, &VappMediaCenterMenu::onEndScrolling);
    closeDelayFocusCellOpeningTimer();
    destroyTitleBoard();

    m_cache.clear();
    m_cache.deinit();
    Super::onDeinit();
}

VfxS32 VappMediaCenterMenu::getSubCellCount()
{
    return m_subCellCount;
}

VfxGroup* VappMediaCenterMenu::getCellIfPresent(VfxS32 cell, VfxS32 subcell)
{
    // if dummy cell, just return NULL
    return m_cache.getItem(Key(cell, subcell));
}

void VappMediaCenterMenu::setFocus(VfxS32 focus, VfxMsec animTime)
{
    VFX_TRACE(("[MediaCenter][Menu] setFocus(), focus:%d, animTime:%d\n", focus, animTime));
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[MediaCenter][Menu] setFocus[%d], oldFocus[%d], animT[%d]", focus, m_focus, animTime);

    VfxS32 preFocus = m_focus;
    focus = VFX_MAX(0, VFX_MIN(focus, getCount() - 1));
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[MediaCenter][Menu] setFocus_2, count[%d], f[%d]", getCount(), focus);
    
    // Update property
    m_focus = focus;

    // Set the animating index value
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    m_tracker->setPos(VfxPoint(m_tracker->getPos().x, m_focus));
    VfxAutoAnimate::commit(); 

    setScrollIndex(VfxFloat(focus), animTime);
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[MediaCenter][Menu] setFocuse_3, isScrolling[%d]", getIsScrolling());
    onFocusIndexChange(m_focus, preFocus);
}
void VappMediaCenterMenu::setScrollIndex(VfxFloat perc, VfxMsec animTime)
{
    VFX_TRACE(("[MediaCenter][Menu] setScrollIndex(), %f, %d\n", perc, animTime));
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[MediaCenter][Menu] setScrollIndex[%d][%d]", (VfxS32(perc)), animTime);


    VfxFloat preIndex = getScrollIndex();
	// Stop the timer fisrt
	m_timer->stop();

	// detect whether we need to fire scrolling event
	if (!m_isScrolling)
	{
		m_isScrolling = VFX_TRUE;
		m_beginScrolling.postEmit(this);
	}

	// If the timer value is -1, means use default value
    if (animTime == -1)
        animTime = m_defaultAnimTime;

    // Set the animating index value
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(animTime <= 0);
    VfxAutoAnimate::setTimingFunc(getMoveTimeFunction());
    VfxAutoAnimate::setDuration(animTime);
    m_tracker->setFilterTiming(perc);
    VfxAutoAnimate::commit();

    if (m_mainTimeline->getIsEnabled())
    {
        m_mainTimeline->setIsFromCurrent(VFX_TRUE);
    }
    else
    {
        m_mainTimeline->setFromValue(preIndex);
    }
    m_mainTimeline->setToValue(perc);
    m_mainTimeline->setDuration(animTime);

    if (animTime <= 0)
    {
        // becasue when animTime <= 0, 
        // we can directly use vfx value to gain better performance
        updateContent(VFX_TRUE);
    }
    else
    {
        updateContent(VFX_FALSE);
    }

    m_mainTimeline->start();

    m_timer->setStartDelay(animTime);
	m_timer->start();

}

struct VcpWheelMenuMonitorData
{
    VfxS32 cstart;
    VfxS32 cend;
    VfxS32 wstart;
    VfxS32 wend;
    VfxS32 ahead;
    VfxS32 behind;
    VfxS32 count;
    void* self;
};

VfxFloat VappMediaCenterMenu::getScrollIndex()
{
    return m_tracker->getFilterTiming();
}

void VappMediaCenterMenu::update()
{
    _ME_TRACE("[MediaCenter][Menu] update()");
    MEDIA_CENTER_MEASURE_TIME_START("MUP");

    checkUpdate();

    MEDIA_CENTER_MEASURE_TIME_STOP("MUP");
}

void VappMediaCenterMenu::updateMenu()
{
    _ME_TRACE("[MediaCenter][Menu] updateMenu()");
    MEDIA_CENTER_MEASURE_TIME_START("MUM");

	//updateContent(VFX_TRUE);
	setFocus(m_focus, 0);
    
    MEDIA_CENTER_MEASURE_TIME_STOP("MUM");
}

void VappMediaCenterMenu::cleanAllCell()
{
    // Clear cache and sub cell item
    m_cache.clear();
    
    
    m_focus             = -1;
    m_firstVisibleItem  = 0;
    m_lastVisibleItem   = 0;

    checkUpdate();
}

VfxS32 VappMediaCenterMenu::getRealCellIndex(const VfxS32 item)
{
    if(0 == getCount()){return -1;}

    if(!isValidCellIndex(item))
    {
        return -1;
    }    
    return item;
}
VfxBool VappMediaCenterMenu::isValidCellIndex(const VfxS32 item)
{
    if(getFirstVisibleIndex() > item || getLastVisibleIndex() < item)
    { 
        return VFX_FALSE;
    }

    return VFX_TRUE;
}

void VappMediaCenterMenu::setFirstVisibleIndex(const VfxS32 index)
{
    m_firstVisibleItem = index;
}

void VappMediaCenterMenu::setLastVisibleIndex(const VfxS32 index)
{
    m_lastVisibleItem = index;
}

void VappMediaCenterMenu::updateContent(bool force)
{
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[MediaCenter][Menu] updateContent=======================================[start]====");
    MEDIA_CENTER_MEASURE_TIME_START("MUC");

    // Backup
    VfxS32 preFirstVisibleItem = m_firstVisibleItem;
    VfxS32 preLastVisibleItem  = m_lastVisibleItem;
    _ME_TRACE_3("[MediaCenter][Menu] updateContent, force[%d], index[%d][%d]", force, preFirstVisibleItem, preLastVisibleItem);

    VfxFloat index;
    if (force)
    {
        index = m_tracker->getFilterTiming();
    }
    else
    {   
        index = m_tracker->forceGetFilterTiming();
    }

    // change region
    m_firstVisibleItem = VfxS32(index) - getAheadCount();
    if (m_firstVisibleItem < 0)
    {
        m_firstVisibleItem = 0;
    }
    m_lastVisibleItem = VfxS32(index + 0.999f) + getBehindCount() + 1;
    if (m_lastVisibleItem > getCount())
    {
        m_lastVisibleItem = getCount();
    }
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[MediaCenter][Menu] updateContent_2, index[%d], view[%d][%d], coumt[%d][%d]", 
        ((VfxS32)index), preFirstVisibleItem, preLastVisibleItem, getAheadCount(), getBehindCount());

    onBeforeUpdateCell();

    for (int i = preFirstVisibleItem; i < preLastVisibleItem; i++)
    {
        if (i >= m_firstVisibleItem && i < m_lastVisibleItem)
            continue;

        
        // transfor to real cell index
        VfxS32 realIndex = getRealCellIndex( i);
        closeCell(realIndex);
    }        

    //for (int i = m_firstVisibleItem; i < m_lastVisibleItem; i++)
    for (int c = m_firstVisibleItem; c < m_lastVisibleItem; c++)
    {
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[MediaCenter][Menu] updateContent_3, item[%d]",c);
        for (VfxS32 j = 0; j < m_subCellCount; j++)
        {
            int i = getRealCellIndex(c);
            VfxGroup* item = m_cache.getItem(Key(i, j));

            // // create sub cell if need 
            if (item == NULL)
            {
                // Set for adding a new entry
                VfxBool isNewCreated = VFX_TRUE;
                Key key(i, j);
                kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[MediaCenter][Menu] item[%d][%d], not exist, Key[%d][%d]", i, j, key.cell, key.subCell);

                m_cache.setItem(key, NULL);  
                item = createCell(i, j, isNewCreated);
                m_cache.setItem(key, item);

                VappMediaCenterMenuCellHeader header = {0};
                header.cell = i;
                header.subCell = j;
                header.self = this;

                setCellHeader(key, &header, isNewCreated);
            }
           
            onUpdateCell(i, j, item);
        }
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[MediaCenter][Menu] --------------------------------------------");
    }
    onAfterUpdateCell();

    // Start Monitor
    VcpWheelMenuMonitorData data;
    data.cstart = m_firstVisibleItem;
    data.cend = m_lastVisibleItem;
    data.wstart = m_firstVisibleItem;
    data.wend = m_lastVisibleItem;
    data.ahead = getAheadCount();
    data.behind = getBehindCount();
    data.count = getCount();

    data.self = this;

    // reset m_isToSendError , m_isToSendWarning
    m_isToSendError = VFX_TRUE;
    m_isToSendWarning = VFX_TRUE;

    // Set monitor
    m_monitorTl->setTarget(m_tracker);
    m_monitorTl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
    m_monitorTl->setCustomInterpolateFunc(indexMonitorFuncCallback, &data, sizeof(VcpWheelMenuMonitorData));
    m_monitorTl->setDurationTime(0xFFFFFF);
    m_monitorTl->setRepeatDuration(0xFFFFFF);
    m_monitorTl->start();

    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[MediaCenter][Menu] updateContent=======================================[end]====");
    MEDIA_CENTER_MEASURE_TIME_STOP("MUC");
    VFX_TRACE(("VappMediaCenter::updateContent(), index:%f, focus:%d, firstVisible:%d, lastVisible:%d\n", index, m_focus, m_firstVisibleItem, m_lastVisibleItem));
}

VfxS32 VappMediaCenterMenu::getFirstVisibleIndex()
{
    return m_firstVisibleItem;
}

VfxS32 VappMediaCenterMenu::getLastVisibleIndex()
{
    return m_lastVisibleItem;
}

void VappMediaCenterMenu::resetCell(VfxS32 index)
{
    closeCell(index);
    update();
}

VfxGroup* VappMediaCenterMenu::createCell(VfxS32 cell, VfxS32 subCell, VfxBool &isNewCreated)
{
    VFX_TRACE(("[MediaCenter][Menu] create Cell() index: %d, focus: %d\n", cell, m_focus));
    _ME_TRACE_3("[MediaCenter][Menu] createCell[%d][%d], isNewCreated[%d]", cell, subCell, isNewCreated);

    VfxGroup *g = NULL;
    g = m_provider->createAppItem(cell, m_world);
    return g;
}

void VappMediaCenterMenu::onCloseCell(VfxS32 cell, VfxS32 subCell, VfxGroup* group)
{
    if(0 == subCell)
    {
        VappMediaCenterAppItem *item = VFX_OBJ_DYNAMIC_CAST(group, VappMediaCenterAppItem);
        VFX_OBJ_CLOSE(item);
    }
}

void VappMediaCenterMenu::onBeforeUpdateCell() 
{
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[MediaCenter][Menu] onBeforeUpdateCell");
}

void VappMediaCenterMenu::onAfterUpdateCell()
{
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[MediaCenter][Menu] onAfterUpdateCell");

    // check if focus item has flash mesh, 
    //onFocusIndexChangedImpl(m_focus);
}

void VappMediaCenterMenu::onFocusIndexChange(VfxS32 focusItem, VfxS32 preFocusItem) 
{
    _ME_TRACE_2("[MediaCenter][Menu] onFocusIndexChange, curFocus = %d, preFocus = %d", focusItem, preFocusItem);
    MEDIA_CENTER_MEASURE_TIME_START("MFC");
    
    if(focusItem != preFocusItem)
    {
        VfxGroup* gPrev = m_cache.getItem(Key(preFocusItem, 0));
        VappMediaCenterAppItem* pPrevFocus = (VappMediaCenterAppItem*)gPrev;
        if(pPrevFocus)
            pPrevFocus->unfocus();
    }

    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[MediaCenter][Menu] onFocusIndexChange, scrolling[%d]", getIsScrolling());
    onFocusIndexChangedImpl(focusItem);
    MEDIA_CENTER_MEASURE_TIME_STOP("MFC");
}

void VappMediaCenterMenu::onFocusIndexChangedImpl(const VfxS32 focusIndex)
{
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[MediaCenter][Menu] onFocusIndexChangeImpl[%d]", focusIndex);    

    VfxGroup* g = m_cache.getItem(Key(focusIndex, 0));
    VappMediaCenterAppItem* pFocus = (VappMediaCenterAppItem*)g;
    if(NULL == pFocus)
    {
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[MediaCenter][Menu] onFocusIndexChangeImpl, focus not exist");
        return;
    }
 
    if(pFocus->isItemFocusHidden())
    {
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[MediaCenter][Menu] onFocusIndexChangeImpl, focus is hidden");    
        pFocus->focus();

        // update title
        VfxWString title = VFX_WSTR_EMPTY;
        m_provider->getAppItemTitle(m_focus, title);
        updateTitleBoardString(title);
        playTitleBoardTransitionAnim(VFX_TRUE);
        VfxImageSrc iconSrc = m_provider->getAppItemTitleBoardIconScr(m_focus);
        m_titleTextBoard->setIcon(iconSrc);        
    }
    
    // check if focus item has flash mesh, 
    if(pFocus->hasFlashMesh())
    {
        pFocus->resetFlahMeshInSceneThree();
    }
}

void VappMediaCenterMenu::handleDragStart()
{   
    onDragStart();
}

void VappMediaCenterMenu:: onDragStart() 
{
    MEDIA_CENTER_START("[MediaCenter][Menu] onDragStart()");
    
    VfxS32 index = m_focus;
    if(0 > index || getCount() < index){return;}

    _ME_TRACE_1("MediaCenter][Menu] onDragStart, m_focus[%d]", m_focus);

    // title frame
    playTitleBoardTransitionAnim(VFX_FALSE);

    // item
    VfxGroup* g = m_cache.getItem(Key(index, 0));
    VappMediaCenterAppItem* item = (VappMediaCenterAppItem*)g;

    if(item)
        item->unfocus();
    MEDIA_CENTER_STOP("[MediaCenter][Menu] onDragStart()");
}

void VappMediaCenterMenu::handleDragEnd(VfxS32 xspeed, VfxS32 yspeed)
{
    onDragEnd(xspeed, yspeed);
}

void VappMediaCenterMenu::onDragEnd(VfxS32 xspeed, VfxS32 yspeed)
{
    MEDIA_CENTER_START("[MediaCenter][Menu] onDragEnd()");

    changeCameraView(VfxVector3f(0, 0, 1.f), 0, 0);

    const VfxFloat v = sqrt((VfxFloat)(xspeed * xspeed + yspeed * yspeed));
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[MediaCenter][Menu] onDragEnd, [%d][%d][%d]", xspeed, yspeed, v);
        
    // ccalculate new scroll index
    const VfxS32 sign = (yspeed > 0) ? 1 : -1;
    const VfxFloat m = VFX_ABS(v) / 333.3f;
    const VfxFloat curScrollIndex = getScrollIndex();

    const VfxS32 newFocus = VfxS32(curScrollIndex + sign * m + 0.5f);
    const VfxS64 animTime = 100 * m;

    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[MediaCenter][Menu] onDragEnd_2, [%d][%d][%d], ", 
        sign, (VfxS32)(m*100.f), (VfxS32)(curScrollIndex*100.f), newFocus, animTime);   
    
    setFocus(newFocus, animTime);
    
    MEDIA_CENTER_STOP("[MediaCenter][Menu] onDragEnd()");
} 

void VappMediaCenterMenu::handleDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    onDrag(xoffset, yoffset);
}
//const VfxFloat dragFactor = 40.f;
void VappMediaCenterMenu::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    MEDIA_CENTER_START("[MediaCenter][Menu] onDrag()");

    // change camera view
    {
        VfxFloat range = 50.f;
        VfxFloat width = (VfxFloat)LCD_WIDTH;
        VfxFloat theta = - xoffset / (width * 0.5f) * 90.f;
        theta = VFX_MAX(-range, VFX_MIN(range,  theta));
        
        VfxVector3f axis = VfxVector3f(0.f, 0.f, 1.f);
        changeCameraView(axis, DEGREES_TO_RADIANS(theta));
    }

    // note the index+ is opposite to Y+
    // calculate new scroll index
    const VfxFloat prevScrollIndex = getScrollIndex();
#if 1
    const VfxFloat W = getSize().width;
    const VfxFloat H = getSize().height;
    const VfxFloat D = sqrt((VfxFloat)(W*W +H*H));
    const VfxFloat d = sqrt((VfxFloat)(xoffset*xoffset + yoffset*yoffset));
    const VfxFloat dragFactor      = VfxFloat(D) / getVisibleCount();

    const VfxS32 sign = (yoffset > 0) ? 1 : -1;
    const VfxFloat dScrollIndex = sign * d / dragFactor;
#else
/* under construction !*/
/* under construction !*/
#endif

    VfxFloat newScrollIndex  = prevScrollIndex + dScrollIndex;
    newScrollIndex = vfxMax(0.f, vfxMin(getCount() - 1.f, newScrollIndex));
    setScrollIndex(newScrollIndex, 0);

    
    MEDIA_CENTER_STOP("[MediaCenter][Menu] onDrag()");
}

VfxBool VappMediaCenterMenu::handleTap(VfxPoint pt)
{
    
    if (!m_isSliding)
    {
        return onTap(pt);
    }

    return VFX_FALSE;
}

VfxBool VappMediaCenterMenu::onTap(VfxPoint pt)
{
    // note pt is the relative position of VappMediaCenterMenu, 
    // so we do not need convert pt to VappMediaCenterMenu local coorinate again
    VfxVector3f pCamera, pClicked, vIncidentRay;
    do
    {
        VfxCamera *camera = m_world->getActiveCamera();
        camera->getWorldPosition(pCamera);
        
        const VfxSize size = getSize();
        const VfxFloat w = (VfxFloat)size.width;
        const VfxFloat h = (VfxFloat)size.height;

        pClicked = camera->unproject(VfxVector3f(
                                    (VfxFloat)(pt.x * 2) / w - 1.0f,
                                    -((VfxFloat)(pt.y * 2) / h - 1.0f),
                                    -1.0f));
        vIncidentRay = pClicked- pCamera;
        VFX_TRACE(("[MediaCenter] onPetInput(), camera (%f, %f, %f)\n", pCamera.x, pCamera.y, pCamera.z));
        VFX_TRACE(("[MediaCenter] onPetInput(), dir(%f, %f, %f)\n", vIncidentRay.x, vIncidentRay.y, vIncidentRay.z));
    }while(0);

    VfxNode *pickedNode = m_world->pick(pCamera, vIncidentRay);

    for(int i = m_firstVisibleItem; i < m_lastVisibleItem; i++)
    {
        //VfxGroup* g = m_cache.getItem(Key(i, 0));
        VfxS32 index = getRealCellIndex(i);
        VfxGroup* g = m_cache.getItem(Key(index, 0));
        VappMediaCenterAppItem* item = (VappMediaCenterAppItem*)g;
        if(item->isPicked(pickedNode))
        {        
            return m_provider->launchAppItem(item->getIndex());
        }
    }

    return VFX_FALSE;
}


VfxS32 VappMediaCenterMenu::getCount()
{
    return m_totalCount;
};

VfxS32 VappMediaCenterMenu::getBehindCount()
{
    VfxU32 count = getVisibleCount() - getFocusedNum();
    return count;
};

VfxS32 VappMediaCenterMenu::getAheadCount()
{
    return getFocusedNum() - 1;
};

VfxS32 VappMediaCenterMenu::getFocusedNum()
{
    return m_focusedNum;
}

VfxS32 VappMediaCenterMenu::getVisibleCount()
{
    return m_visibleItemCount;
}


VfxTimelineInterpolationRetEnum VappMediaCenterMenu::indexMonitorFuncCallback(
    void *output,
    const void *fromValue,
    const void *toValue,
    VfxTypeIdEnum typeId,
    VfxFloat t, 
    void *data,
    VfxU32 dataSize
)
{
    vrt_float now, begin, end;
    VcpWheelMenuMonitorData *mdata = (VcpWheelMenuMonitorData*)data;
    VappMediaCenterMenu *wheelMenu = (VappMediaCenterMenu*)mdata->self;
    
    VFX_UNUSED(fromValue);
    VFX_UNUSED(toValue);
    VFX_UNUSED(typeId);
    VFX_UNUSED(t);
    VFX_UNUSED(data);
    VFX_UNUSED(dataSize);

    now = *((vrt_float*)output);

    begin = now - mdata->ahead;
    if (begin < 0)
        begin = 0;

    end = now + mdata->behind + 1;
    if (end > mdata->count)
        end = VfxFloat(mdata->count);

    // check if the view port is outside the warning content rect

    if (end > mdata->cend || begin < mdata->cstart)
    {
        // emit stop signal
        if (wheelMenu->m_isToSendError)
        {
            vrt_invoke_mmi_rpc(emitContentError, mdata->self);
        }                

        wheelMenu->m_isToSendError = VRT_FALSE;
        return VFX_TIMELINE_INTERPOLATION_RET_MONITOR_FREEZE;
        //return VFX_TIMELINE_INTERPOLATION_RET_MONITOR;
    }
    else if (end > mdata->wend || begin < mdata->wstart)
    {
         // emit stop signal
        if (wheelMenu->m_isToSendWarning)
        {
            vrt_invoke_mmi_rpc(emitContentWarning, mdata->self);
        }                

        wheelMenu->m_isToSendWarning = VRT_FALSE;
    }
    return VFX_TIMELINE_INTERPOLATION_RET_MONITOR;
}

VfxTimelineInterpolationRetEnum VappMediaCenterMenu::interpolateFunc(
    void *output,
    const void *fromValue,
    const void *toValue,
    VfxTypeIdEnum typeId,
    VfxFloat t, 
    void *data,
    VfxU32 dataSize
)
{
    _ME_TRACE("[MediaCenter][Menu] interpolateFunc()");
    MEDIA_CENTER_MEASURE_TIME_START("MIF");
    
    VappMediaCenterMenuCellHeader* header = (VappMediaCenterMenuCellHeader*)data;
    VfxFloat cellRelPos = header->cell - t;
    
    *((vrt_float*)output) = cellRelPos/5.0f + 0.5f;

    MEDIA_CENTER_MEASURE_TIME_STOP("MIF");    
    return VFX_TIMELINE_INTERPOLATION_RET_MONITOR;
}

VfxTimelineInterpolationRetEnum VappMediaCenterMenu::opacityFunc(
    void *output,
    const void *fromValue,
    const void *toValue,
    VfxTypeIdEnum typeId,
    VfxFloat t, 
    void *data,
    VfxU32 dataSize
)
{    
    _ME_TRACE("[MediaCenter][Menu] opacityFunc()");
    MEDIA_CENTER_MEASURE_TIME_START("MOF");

    if (t < 0.05 || t > 1.0f)
    {
        *((vrt_float*)output) = 0;
    }
    else
    {
        *((vrt_float*)output) = 1;
    }

    MEDIA_CENTER_MEASURE_TIME_STOP("MOF");        
    return VFX_TIMELINE_INTERPOLATION_RET_DONE;
}

VfxTimelineInterpolationRetEnum VappMediaCenterMenu::freezeFunc(
    void *output,
    const void *fromValue,
    const void *toValue,
    VfxTypeIdEnum typeId,
    VfxFloat t,
    void *data,
    VfxU32 dataSize
)
{    
    _ME_TRACE("[MediaCenter][Menu] freezeFunc()");
    MEDIA_CENTER_MEASURE_TIME_START("MFF");

    *((vrt_float*)output) = (*((vrt_float *)toValue)- *((vrt_float *)fromValue)) * t + *((vrt_float *)fromValue);
    
    MEDIA_CENTER_MEASURE_TIME_START("MFF");
    return VFX_TIMELINE_INTERPOLATION_RET_MONITOR;
}

void VappMediaCenterMenu::emitContentWarning(void *arg)
{
    VappMediaCenterMenu *menu = (VappMediaCenterMenu*)arg;

    // TODO: threading issue here
    if (menu == NULL || !menu->isValid() || !menu->isKindOf(VFX_OBJ_CLASS_INFO(VappMediaCenterMenu)))
        return;

    menu->updateContent(VFX_FALSE);
}

void VappMediaCenterMenu::emitContentError(void *arg)
{
    VappMediaCenterMenu *menu = (VappMediaCenterMenu*)arg;

    // TODO: threading issue here
    if (menu == NULL || !menu->isValid() || !menu->isKindOf(VFX_OBJ_CLASS_INFO(VappMediaCenterMenu)))
        return;

    menu->updateContent(VFX_FALSE);
}

void VappMediaCenterMenu::onUpdate()
{
    _ME_TRACE("[MediaCenter][Menu] onUpdate()");
    MEDIA_CENTER_MEASURE_TIME_START("MOU");

    Super::onUpdate();

    VfxS32 preCellCount = m_subCellCount;
    m_subCellCount = getSubCellCount();
    VFX_ASSERT(m_subCellCount >= 1);

    // check whether need to remove extra sub cell
    if (preCellCount > m_subCellCount)
    {
        for (VfxS32 i = getFirstVisibleIndex(); i < getLastVisibleIndex(); i++)
        {
            for (VfxS32 j = m_subCellCount; j < preCellCount; j++)
            {
                m_cache.closeItem(Key(i, j));
            }
        }
    }

    // adjust focus index
    if (getCount() > 0)
    {
        if (m_focus < 0)
        {
            m_focus = 0;
        }

        if (m_focus >= getCount())
        {
            m_focus = getCount() - 1;
        }

        setScrollIndex(VfxFloat(m_focus), m_defaultAnimTime);
    }
    else
    {
        m_focus             = -1;
        m_firstVisibleItem  = 0;
        m_lastVisibleItem   = 0;
    }
    
    MEDIA_CENTER_MEASURE_TIME_STOP("MOU");
}

VfxS32 g_debugFocus = 0;
//#define __MEDIA_CENTER_KEY_INPUT_DEBUG__
VfxBool VappMediaCenterMenu::onKeyInput(VfxKeyEvent &event)
{
   
#if defined(__MEDIA_CENTER_KEY_INPUT_DEBUG__)
    if(VFX_KEY_EVENT_TYPE_UP != event.type)
    {
        return Super::onKeyInput(event);
    }
    
    if(VFX_KEY_CODE_SEND == event.keyCode)
    {
        //g_debugFocus = (getCount() < g_debugFocus + 1)? (0) : (g_debugFocus + 1);
        //setFocus(g_debugFocus);

        VfxGroup *focus = getCellIfPresent(m_focus, 0);
        VappMediaCenterAppItem *focusAppItem = ((VappMediaCenterAppItem*)focus);
        focusAppItem->focus();
        return VFX_TRUE; 
    }
    else if(VFX_KEY_CODE_END == event.keyCode)
    {
        //VFX_OBJ_GET_INSTANCE(VfxRenderer)->debugDump();
        VfxGroup *focus = getCellIfPresent(m_focus, 0);
        VappMediaCenterAppItem *focusAppItem = ((VappMediaCenterAppItem*)focus);
        focusAppItem->unfocus();  
        return VFX_TRUE;
    }
    else if(VFX_KEY_CODE_CAMERA == event.keyCode)
    {
        //VfxVector3f p = m_titleTextBoard->getTranslation();
        //m_titleTextBoard->setTranslation(p);
        m_titleTextBoard->meshTest();
    }
#endif
    return Super::onKeyInput(event);
}

void VappMediaCenterMenu::setIsDragging(const VfxBool b)
{
    m_isDraging = b;
}
VfxBool VappMediaCenterMenu::getIsDragging() const
{
    return m_isDraging;
}

void VappMediaCenterMenu::onEndScrolling(VfxObject *sender)
{
    VFX_UNUSED(sender);
    _ME_TRACE_2("[MediaCenter][Menu] onEndScrolling, scrolling[%d], draging[%d]", getIsScrolling(), getIsDragging());
    if(getIsScrolling() || getIsDragging()){return;}
#if 1
    onFocusIndexChangedImpl(m_focus);
#else
/* under construction !*/
#endif
}

void VappMediaCenterMenu::startDelayFocusCellOpeningTimer()
{
    if(NULL == m_delayFocusCellOpeningTimer)
    {
        VFX_OBJ_CREATE(m_delayFocusCellOpeningTimer, VfxTimer, this);
    }
    m_delayFocusCellOpeningTimer->setStartDelay(100);
    m_delayFocusCellOpeningTimer->m_signalTick.connect(this, &VappMediaCenterMenu::onDelayFocusCellOpeningTimeout);
}

void VappMediaCenterMenu::stopDelayFocusCellOpeningTimer()
{
    if(m_delayFocusCellOpeningTimer)
    {
        m_delayFocusCellOpeningTimer->m_signalTick.disconnect(this, &VappMediaCenterMenu::onDelayFocusCellOpeningTimeout);
        m_delayFocusCellOpeningTimer->stop();
    }
}

void VappMediaCenterMenu::closeDelayFocusCellOpeningTimer()
{
    stopDelayFocusCellOpeningTimer();
    VFX_OBJ_CLOSE(m_delayFocusCellOpeningTimer);
}

void VappMediaCenterMenu::onDelayFocusCellOpeningTimeout(VfxTimer *timer)
{
    _ME_TRACE_2("[MediaCenter][Menu] onEndScrolling, scrolling[%d], draging[%d]", getIsScrolling(), getIsDragging());

    stopDelayFocusCellOpeningTimer();
    if(getIsScrolling() || getIsDragging()){return;}
    onFocusIndexChangedImpl(m_focus);
}

void VappMediaCenterMenu::calculatePenEventSpeed(VfxPenEvent &event, VfxFloat &xSpeed, VfxFloat &ySpeed)
{
    VfxPoint dowmpt = event.getRelDownPos(this);
    VfxPoint pt     = event.getRelPos(this);
    xSpeed = (1000 * (pt.x - dowmpt.x)) / (event.timeStamp - event.downTimeStamp);
    ySpeed = (1000 * (pt.y - dowmpt.y)) / (event.timeStamp - event.downTimeStamp);

    _ME_TRACE_4("[MediaCenter][Menu] calculatePenEventSpeed(), pt(%d, %d), xSpeed = %d, ySpeed = %d", pt.x, pt.y, (VfxS32)(xSpeed*100), (VfxS32)(ySpeed*100));
}

void VappMediaCenterMenu::calcualteMaxAndCurrentMoveOffset(VfxPenEvent &event, VfxS32 &dX, VfxS32 &dY)
{
    VfxPoint dowmpt = event.getRelDownPos(this);
    VfxPoint prept  = event.getRelPrevPos(this);
    VfxPoint pt     = event.getRelPos(this);

    // calculate the move offset with the pen down position 
    VfxS32 xoffset = VFX_ABS(pt.x - dowmpt.x);
    VfxS32 yoffset = VFX_ABS(pt.y - dowmpt.y);
    
    // update the max move offsect since pen down event happened
    m_maxMoveOffset = xoffset > m_maxMoveOffset ? xoffset : m_maxMoveOffset;    
    m_maxMoveOffset = yoffset > m_maxMoveOffset ? yoffset : m_maxMoveOffset;

    // calcuate the move offset with the prev pos
    dX = pt.x - prept.x;
    dY = pt.y - prept.y;

    _ME_TRACE_4("[MediaCenter][Menu] calcualteMaxAndCurrentMoveOffset(), pt(%d, %d), dX = %d, dY = %d", pt.x, pt.y, dX, dY);
}

// TODO: Fix jump issue >> onTap()
// TODO: Fix never call item->focus() while focus is not  change
VfxBool VappMediaCenterMenu::onPenInput(VfxPenEvent &event)
{
    _ME_TRACE_1("[MediaCenter][Menu] onPenInput, type = %d", event.type);
    
    if(VFX_PEN_EVENT_TYPE_DOWN == event.type)
    {
        setIsDragging(VFX_TRUE);
        m_maxMoveOffset = 0;
        handleDragStart();
        return VFX_TRUE;
    }
	else if(VFX_PEN_EVENT_TYPE_UP == event.type)
	{
        setIsDragging(VFX_FALSE);
        // check if the valid tap event frist
		if (m_maxMoveOffset <= getTapThreshold())
		{
			// pick the tapped item 
			// if item dose not exist,  treat as drag end event			
			VfxPoint dowmpt = event.getRelDownPos(this);
			if(!handleTap(dowmpt))
            {
                onFocusIndexChangedImpl(m_focus);
            }            
            return VFX_TRUE;
		}
        
        // treat as drag event            
		if (event.timeStamp > event.downTimeStamp)
		{
			// disable onTap event (why)
			m_isSliding = VFX_TRUE;

            VfxFloat xSpeed = 0.f;
            VfxFloat ySpeed = 0.f;
            calculatePenEventSpeed(event, xSpeed, ySpeed);   
			handleDragEnd(xSpeed, ySpeed);
		}
		else
		{
			handleDragEnd(0, 0);            
		}           
		return VFX_TRUE;
	}
	else if(VFX_PEN_EVENT_TYPE_ABORT == event.type)
	{
		handleDragEnd(0, 0);
		return VFX_TRUE;
	}
    else if(VFX_PEN_EVENT_TYPE_LONG_TAP == event.type || VFX_PEN_EVENT_TYPE_MOVE == event.type)
	{   
        VfxS32 dX = 0, dY = 0;
		calcualteMaxAndCurrentMoveOffset(event, dX, dY);
		if (m_maxMoveOffset > getTapThreshold())
		{
			handleDrag(dX, dY);
		}
		return VFX_TRUE;
	}

    return Super::onPenInput(event);
}

void VappMediaCenterMenu::onViewBoundsChanged(VfxFrame *view, const VfxRect &old)
{
    checkUpdate();

    // Set the animating index value
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    m_tracker->setBounds(getBounds());
    VfxAutoAnimate::commit(); 
}

void VappMediaCenterMenu::onTimerTick(VfxTimer *source)
{
	if (m_isScrolling)
	{
		m_isScrolling = VFX_FALSE;
		m_endScrolling.postEmit(this);
	}
    m_isSliding = VFX_FALSE;
}

static VfxBool g_cmdDebug = VFX_FALSE;
static VfxFloat g_shift = 0;
static VfxFloat g_tAnimMinValue = 0.2f;
static VfxFloat g_tAnimMaxValue = 0.9f;
VfxFloat VappMediaCenterMenu::normalizingTimingFuncCallback(VfxFloat t, void *data, VfxU32 dataSize)
{   
    MEDIA_CENTER_MEASURE_TIME_START("MNF");
    
    VappMediaCenterMenuCellHeader* header = (VappMediaCenterMenuCellHeader*)data;

    VappMediaCenterMenu *pThis = (VappMediaCenterMenu*)header->self;
    VfxFloat cell = pThis->getLoopRelCellIndex(header->cell);
    VfxFloat cellRelPos = cell - t + g_shift;

    _ME_TRACE_2("[MediaCenter][Menu] normalizingTimingFuncCallback, t[%d], cell[%d]", (VfxS32)(t * 100), (VfxS32)(cell * 100));


    VfxS32 visibleCount = pThis->getVisibleCount();
    VfxS32 focusedNum = pThis->getFocusedNum();
    VfxS32 behindCount = pThis->getBehindCount();
    _ME_TRACE_3("[MediaCenter][Menu] normalizingTimingFuncCallback_2, [%d][%d][%d]", visibleCount, focusedNum, behindCount);

    VfxFloat index = behindCount - cellRelPos;
    
    VfxFloat indexNormalized = index / (visibleCount - 1);
    VfxFloat output = indexNormalized * (g_tAnimMaxValue - g_tAnimMinValue) + g_tAnimMinValue;
    _ME_TRACE_2("[MediaCenter][Menu] normalizingTimingFuncCallback_3, [%d][%d]", (VfxS32)(indexNormalized * 100), (VfxS32)(output * 100));

    if(g_cmdDebug)
        VFX_TRACE(("[MediaCenter][Menu] normalizingTimingFuncCallback, cell = %f(%f), idx = %f, output = %f\n", cell, cellRelPos, indexNormalized, output));
    MEDIA_CENTER_MEASURE_TIME_STOP("MNF");
    return output;
}

VfxS32  VappMediaCenterMenu::getLoopRelCellIndex(const VfxS32 index)
{
    return index;
}

void VappMediaCenterMenu::setCellHeader(Key key, VappMediaCenterMenuCellHeader* header, VfxBool isNewCreated)
{
    VfxGroup* group = m_cache.getItem(key);
    if (group == NULL)
    {
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, 
            "[MediaCenter][Menu] setCellHeader, group is null, key[%d][%d]", key.cell, key.subCell);
        return;
    }
    MEDIA_CENTER_MEASURE_TIME_START("MSH");
    
    VappMediaCenterAppItem *item = (VappMediaCenterAppItem*)group;
    
    VfxAnimation *anim = NULL;
    VFX_OBJ_CREATE(anim, VfxAnimation, group);
    VappMediaCenter3DResPath path;
    m_provider->getAppItemPlateAnim(item->getIndex(), path);

    VfxAssetLoader::loadAnimation(anim, group, path);
    anim->setCustomTimingFunc(&VappMediaCenterMenu::normalizingTimingFuncCallback, header, sizeof(*header));
    anim->setTimelineTime(m_mainTimeline, 1.0f, 0.0f, VFX_TIMELINE_TIME_WRAP_TYPE_NONE);  
    item->configItemAnim(anim);
    
    VfxFloatTimeline *opacity_tl;
    VFX_OBJ_CREATE(opacity_tl, VfxFloatTimeline, group);
    opacity_tl->setTarget(group);
    opacity_tl->setTargetPropertyId(VRT_NODE_PROPERTY_ID_OPACITY);
    opacity_tl->setDuration(2000);
    opacity_tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
    opacity_tl->setFromValue(0);
    opacity_tl->setToValue(1);
    opacity_tl->setCustomTimingFunc(&VappMediaCenterMenu::normalizingTimingFuncCallback, header, sizeof(*header));
    opacity_tl->setCustomInterpolateFunc(opacityFunc, header, sizeof(*header));
    opacity_tl->setTimelineTime(m_mainTimeline, 1.0f, 0.0f, VFX_TIMELINE_TIME_WRAP_TYPE_NONE);
    item->configItemOpacTL(opacity_tl);

    MEDIA_CENTER_MEASURE_TIME_STOP("MSH");
    VFX_TRACE(("VappMediaCenter::setCellHeader(), index: %d, isNewCreated: %d\n", header->cell, isNewCreated));
}

void VappMediaCenterMenu::closeCell(VfxS32 cell, VfxS32 subCell, VfxGroup* group)
{
    if(cell < 0 || subCell < 0 ){return;}

    VFX_DEV_ASSERT(cell >= 0);
    VFX_DEV_ASSERT(subCell >= 0);

    onCloseCell(cell, subCell, group);
}

void VappMediaCenterMenu::closeCell(VfxS32 cell)
{
    if(cell < 0){return;}
    VFX_DEV_ASSERT(cell >= 0);

    for (VfxS32 i = 0; i < m_subCellCount; i++)
    {
        m_cache.closeItem(Key(cell, i));
    }
}

void VappMediaCenterMenu::configWorldAndCamera(VfxWorld *world)
{
    VFX_DEV_ASSERT(world);
    m_world = world;

    // setup camera rotation timeline
    VFX_OBJ_CLOSE(m_cameraQTL);
    m_camera = m_world->getActiveCamera();
    
    if(m_camera)
    {
        VFX_OBJ_CREATE(m_cameraQTL, VfxQuaternionfTimeline, m_world);
        m_cameraQTL->setTarget(m_camera);
        m_cameraQTL->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
    }   
}

void VappMediaCenterMenu::configContentProvider(VappMediaCenterAppItems *provider)
{
    VFX_DEV_ASSERT(provider);
    m_provider = provider;

    // update total count
    m_totalCount = provider->getAppItemCount();
}

static VfxBool g_viewInteractionSupported = VFX_FALSE;
void VappMediaCenterMenu::changeCameraView(
                            const VfxVector3f axis, 
                            const VfxFloat theta, 
                            const VfxS64 duration)
{    
    if(!g_viewInteractionSupported){return;}
    
    // stop timeline to avoid change view during rotating view 
    if(!stopChangingCameraView()){return;}
    
    // get camera current rotate angle
    VfxQuaternionf q1;
    m_camera->forceGetRotation(q1);

    // set rotation parameter
    const VfxFloat R = theta / 2;
    VfxQuaternionf q2 = VfxQuaternionf(axis * vfxSin(R), vfxCos(R)); 
    m_cameraQTL->setFromValue(q1);
    m_cameraQTL->setToValue(q2);
    m_cameraQTL->setDuration(duration);
    m_cameraQTL->setAutoReversed(VFX_FALSE);
    m_cameraQTL->setRepeatCount(1);

    // start rotate
    //m_cameraQTL->m_signalStopped.connect(this, &VappMediaCenterMenu::onChangeCameraView);    
    m_cameraQTL->start();
}

void VappMediaCenterMenu::onChangeCameraView(VfxBaseTimeline *timeline, VfxBool isStop)
{
    stopChangingCameraView();
}

void VappMediaCenterMenu::resetCameraView()
{
    if(!stopChangingCameraView()){return;}
    
    VfxQuaternionf q1;   m_camera->forceGetRotation(q1);
    VfxQuaternionf q2 = VfxQuaternionf(VfxVector3f(0, 0, 1.f) * vfxSin(0), vfxCos(0));
    if(q2 == q1 || VfxQuaternionf(0, 0, 0, 1) == q1)
    {
        return;
    }
    m_cameraQTL->setFromValue(q1);
    m_cameraQTL->setToValue(q2);
    m_cameraQTL->setDuration(250);
    m_cameraQTL->setAutoReversed(VFX_FALSE);
    m_cameraQTL->setRepeatCount(1);
	m_cameraQTL->start();
}

VfxBool VappMediaCenterMenu::stopChangingCameraView()
{
    if(NULL == m_camera || NULL == m_cameraQTL)
    {
        return VFX_FALSE;
    }
    m_cameraQTL->m_signalStopped.disconnect(this, &VappMediaCenterMenu::onChangeCameraView);
    m_cameraQTL->stop();
    return VFX_TRUE;
}

static VfxPoint g_pTextBaord = VfxPoint(80, 120);
void VappMediaCenterMenu::createTitleBoard()
{
    VFX_OBJ_CLOSE(m_titleTextBoard);
    
    // setup scene
    VFX_OBJ_CREATE(m_titleTextBoard, VappMediaCenterTextBoard, m_world);
    VappMediaCenter3DResPath path;
    get3DResourcePath('TBS', path);
    m_titleTextBoard->setupAppearance(path);

    // set poistion
    VfxVector3f p = VfxVector3f(-12.f, -25.f, -20.f);
    //convertPos2DTo3D(g_pTextBaord, p);
    m_titleTextBoard->setTranslation(p);
    m_titleTextBoard->bringToFront();

    // setup animation
    VappMediaCenter3DResPath animIn, animOut;    
    get3DResourcePath('TBI', animIn);
    get3DResourcePath('TBO', animOut);
    m_titleTextBoard->setupAnims(animIn, animOut);
}

void VappMediaCenterMenu::destroyTitleBoard()
{
    VFX_OBJ_CLOSE(m_titleTextBoard);
}

void VappMediaCenterMenu::updateTitleBoardString(const VfxWString &title)
{
    if(NULL == m_titleTextBoard)
    {
        createTitleBoard();
    }
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[MediaCenter][Menu] updateTitleBoardString");
    m_titleTextBoard->setTitleString(title);
}

void VappMediaCenterMenu::playTitleBoardTransitionAnim(const VfxBool playInAnim)
{
    if(NULL == m_titleTextBoard)
    {
        createTitleBoard();
    }

    m_titleTextBoard->playAnim(playInAnim);
}

void VappMediaCenterMenu::get3DResourcePath(VfxId id, VfxWString &path) const
{
    switch(id)
    {
        case 'TBS':
            path = VFX_WSTR("D:\\MediaCenter\\textBoard\\textBoard.scn");
            return;
        case 'TBI':
            path = VFX_WSTR("D:\\MediaCenter\\textBoard.ani\\textBoard_0_533.ani");
            return;
        case 'TBO':
            path = VFX_WSTR("D:\\MediaCenter\\textBoard.ani\\textBoard_566_1000.ani");
            return;            
        default:
            path = VFX_WSTR_EMPTY;
            return;
    }
}
void VappMediaCenterMenu::get3DResourcePath(VfxId id, VfxResId &path) const
{
    switch(id)
    {
        case 'TBS':
            path = SCN_ID_VAPP_MEDIA_CENTER_TEXT_BOARD_SCENE;
            return;
        case 'TBI':
            path = ANI_ID_VAPP_MEDIA_CENTER_TEXT_BOARD_IN;
            return;
        case 'TBO':
            path = ANI_ID_VAPP_MEDIA_CENTER_TEXT_BOARD_OUT;
            return;            
        default:
            return;
    }
}

void VappMediaCenterMenu::convertPos2DTo3D(const VfxPoint pSrc, VfxVector3f &pDst)
{
    // calculate the incident ray 
    // which starts from camera and points to clicked pos in world coordinate
    do
    {
        VfxVector3f pCamera;
        if(!getCameraPos(pCamera)){return;}
        //const VfxPoint pos = pSrc.getRelPos(this);
        const VfxSize size = getSize();
        const VfxFloat w = (VfxFloat)size.width;
        const VfxFloat h = (VfxFloat)size.height;

        pDst = m_camera->unproject(VfxVector3f(
                                    (VfxFloat)(pSrc.x * 2) / w - 1.0f,
                                    -((VfxFloat)(pSrc.y * 2) / h - 1.0f),
                                    -1.0f));
        VFX_TRACE(("[MediaCenter] convertPos2DTo3D(), camera (%f, %f, %f)\n", pCamera.x, pCamera.y, pCamera.z));
    }while(0);

}

/***************************************************************************** 
 * Class Implementation : VappMediaCenterTextBoard
 *****************************************************************************/ 

void VappMediaCenterTextBoard::onDeinit()
{
    m_animPlayer->stop();
    VFX_OBJ_CLOSE(m_animPlayer);
    VfxGroup::onDeinit();
}

void VappMediaCenterTextBoard::setupAppearance(VappMediaCenter3DResPath path)
{
    VfxAssetLoader::loadSceneBegin(this, path);    
    m_boardRoot = (VfxGroup *)VfxAssetLoader::findObjByName(VFX_STR("textBoardTextRoot-node")); 
    m_iconMesh = (VfxMesh *) VfxAssetLoader::findObjByName(VFX_STR("textBoard-node_PIVOT")); 
    {
        VfxS32 Z_FACTOR = -1;
        VfxS32 Z_OFFSET = -1;
	    VfxPass *pass = m_iconMesh->getMaterial(1)->getPass(0);
        VfxCompositingMode *modeConfig;
        VFX_OBJ_CREATE(modeConfig, VfxCompositingMode, pass);
        modeConfig->setDepthOffset(Z_FACTOR, Z_OFFSET);
        pass->setCompositingMode(modeConfig);
    } 
    VfxAssetLoader::loadSceneEnd();
}

void VappMediaCenterTextBoard::setupAnims(const VappMediaCenter3DResPath inPath, const VappMediaCenter3DResPath outPath)
{
    VFX_OBJ_CLOSE(m_animPlayer);

    // create player
    VappMediaCenterAnimPlayerOption opt;
    opt.setShuffle(VFX_FALSE);
    opt.setRepeat(VFX_FALSE);
    opt.setRandomDecks(VFX_FALSE);
    VFX_OBJ_CREATE_EX(m_animPlayer, VappMediaCenterAnimPlayer, this, (opt));
    m_animPlayer->configTarget(this);

    // create animations
    VfxAnimation *inAnim = NULL; 
    VFX_OBJ_CREATE(inAnim, VfxAnimation, this);
    VfxAssetLoader::loadAnimation(inAnim, this, inPath);
    m_animPlayer->addToPlaylist(inAnim);

    VfxAnimation *outAnim = NULL;
    VFX_OBJ_CREATE(outAnim, VfxAnimation, this);
    VfxAssetLoader::loadAnimation(outAnim, this, outPath);
    m_animPlayer->addToPlaylist(outAnim);
}

void VappMediaCenterTextBoard::playAnim(const VfxBool playInAnim)
{
    if(NULL == m_animPlayer){return;}

    m_animPlayer->playAnAnim((playInAnim ? 0: 1));
}

void VappMediaCenterTextBoard::setIcon(const VfxImageSrc &imgSrc)
{
    if(NULL == m_iconMesh){return;}
    
    // get pass
    VfxPass *pass = m_iconMesh->getMaterial(2)->getPass(0);
    VfxShaderVariable *varTex = pass->getUniformVariable(VFX_STR("uAlphaSampler"));

    // create the new texture
    VfxImage2D *img2D;
    VFX_OBJ_CREATE_EX(img2D, VfxImage2D, pass, (imgSrc));
    VfxTexture2D *tex2D;
    VFX_OBJ_CREATE_EX(tex2D, VfxTexture2D, pass, (img2D));

    // update texture
    varTex->setValue(tex2D);
    pass->setPropertyDirty(VFX_PASS_SHADER_UNIFORMS_DIRTY);	

    // release previous resources
    VFX_OBJ_CLOSE(m_tex2D);
    VFX_OBJ_CLOSE(m_img2D);
    m_img2D = img2D;
    m_tex2D = tex2D;	
}

void VappMediaCenterTextBoard::setTitleString(const VfxWString &value)
{
    createTitleTextMesh();
    if(m_titleMesh)
    {
        m_titleMesh->setString(value);
    }
}

static VfxS32 g_textBoradW = 65;
static VfxS32 g_textBoradH = 10;
static VfxVector3f g_axis = VfxVector3f(1, 0.f, 0.f);
static VfxFloat g_angle = 0.f;//- 2.5f;
static VfxVector3f g_vTranslation = VfxVector3f(30, 0.f, 0.f);
static VfxBool g_setZOffsetBefore = VFX_TRUE;

void VappMediaCenterTextBoard::createTitleTextMesh()
{
    if(NULL == m_boardRoot){return;}

    VFX_OBJ_CLOSE(m_titleMesh);
    VFX_OBJ_CREATE_EX(m_titleMesh, VfxTextMesh, m_boardRoot, (g_textBoradW, g_textBoradH, VFX_WSTR("TEXT TEST"),0, VFX_TEXT_MESH_ALIGN_MODE_LEFT));
    m_titleMesh->setTextColor(VFX_COLOR_WHITE);     
    m_titleMesh->setFont(VfxFontDesc(VFX_FONT_DESC_SIZE_LARGE, VFX_FONT_DESC_EFFECT_BORDER));
    m_titleMesh->setTranslation(g_vTranslation);    
    //m_titleMesh->setBackgroundColor(VFX_COLOR_RED);    
    m_boardRoot->setRotation(g_axis, g_angle);
}

void VappMediaCenterTextBoard::meshTest()
{
    if(m_boardRoot)
    {
        m_boardRoot->setRotation(g_axis, g_angle);
        m_titleMesh->setTranslation(g_vTranslation);
    }
}

#endif // __COSMOS_3D_MEDIA_CENTER__
