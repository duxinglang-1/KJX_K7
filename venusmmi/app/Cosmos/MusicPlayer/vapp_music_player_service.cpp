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
 *  vapp_music_player_service.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Music Player service
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
 * removed!
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"
#ifdef __COSMOS_MUSICPLY__

#include "vapp_music_player.h"
#include "vapp_music_player_service.h"
#include "vapp_music_player_util.h"
#include "mmi_rp_vapp_music_player_def.h"
#include "vapp_vol_dialog_gprot.h"
#include "mmi_rp_vapp_vol_dialog_def.h"
#include "mmi_rp_srv_prof_def.h"
#include "vapp_screen_lock_gprot.h"

extern "C"
{
#include "UcmSrvGprot.h"
#include "gpiosrvgprot.h"
#include "wgui_categories_util.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif
}

#define VAPP_MUSIC_PLAYER_SRV_MEM_POOL_SIZE 10*1024

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
VappMusicPlayerService* VappMusicPlayerService::g_mplayerSrvPtr = NULL;


#if defined(__COSMOS_MUSICPLY_COVER_FLOW__) || defined(__COSMOS_WIDGET_MUSICPLY_COVER_SUPPORT__) || defined(__MMI_VUI_WIDGET_3D_MUSIC_PLAYER__)
// Image buffer for getAlbumCover()
#ifdef __MTK_TARGET__
#pragma arm section zidata = "NONCACHEDZI", rwdata = "NONCACHEDRW"
#endif 
#ifndef __MTK_TARGET__
#define __align(X)
#endif
/* 32-byte alignment for ARM9 cache */
__align(32) U8 g_albumCoverBuffer[SRV_PLST_ARTWORK_RESIZED_WIDTH * SRV_PLST_ARTWORK_RESIZED_HEIGHT * 2];
#ifdef __MTK_TARGET__
#pragma arm section rwdata , zidata
#endif 
// Album ID for g_albumCoverBuffer
VfxU32 g_albumCoverSongID;
VfxBool g_albumCoverValid;
#endif /*#if defined(__COSMOS_MUSICPLY_COVER_FLOW__) || defined(__COSMOS_WIDGET_MUSICPLY_COVER_SUPPORT__) || defined(__MMI_VUI_WIDGET_3D_MUSIC_PLAYER__)*/

/***************************************************************************** 
 * VappMusicPlayerService Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerService", VappMusicPlayerService, VfxObject);
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappMusicPlayerService);

static VfxU8 g_musicPlayerSrvMemPool[VAPP_MUSIC_PLAYER_SRV_MEM_POOL_SIZE];
static VfxU8 g_musicPlayerPLSTBgMemPool[VAPP_MUSICPLY_PLST_DB_BACKGROUND_MEM_SIZE + SRV_PLST_MIN_MEM_CONTROL_BACKGROUND];

void VappMusicPlayerService::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_ONINIT);

    VFX_OBJ_CREATE(m_context, VfxContext, VFX_SYS_GLOBAL_CONTEXT);
    m_context->assignPool(g_musicPlayerSrvMemPool, VAPP_MUSIC_PLAYER_SRV_MEM_POOL_SIZE);

    VfxObject::onInit();

    g_mplayerSrvPtr = this;

    // check memory card status
    checkMemoryCardReady();

#if defined(__MMI_AVRCP_SUPPORT__)
    srv_avrcp_set_cmd_hdlr(onAVRCPCmdCallback);
#endif

    kal_mem_set(&m_activeInfo, 0, sizeof(SongInfoStruct));
    kal_mem_set(&m_activeDetailInfo, 0, sizeof(srv_plst_media_details_struct));

    VFX_OBJ_CREATE(m_delayPlayTimer, VfxTimer, this);
    m_delayPlayTimer->setStartDelay(300);
    m_delayPlayTimer->m_signalTick.connect(this, &VappMusicPlayerService::onDelayPlayTimerTick);

    VFX_OBJ_CREATE(m_playbackErrTimer, VfxTimer, this);
    m_playbackErrTimer->setStartDelay(1500);
    m_playbackErrTimer->m_signalTick.connect(this, &VappMusicPlayerService::onPlaybackErrTimerTick);

    VFX_OBJ_CREATE(m_ctrlPlayback, VappMusicPlayerCtrlPlayback, this);
    m_ctrlPlayback->m_signalMDICallback.connect(this, &VappMusicPlayerService::onMDICallback);
    m_ctrlPlayback->m_signalPlaybackStateChange.connect(this, &VappMusicPlayerService::onPlaybackStateChange);

    VFX_OBJ_CREATE(m_statusIconTimer, VfxTimer, this);
    m_statusIconTimer->setStartDelay(1000);
    m_statusIconTimer->m_signalTick.connect(this, &VappMusicPlayerService::onStatusIconTimerTick);

    // register events to handle in onProc
    mmi_frm_cb_reg_event(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, (mmi_proc_func)&VappMusicPlayerService::onProcCheckVolType, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_PROF_IS_PLAYING, (mmi_proc_func)&VappMusicPlayerService::onProcProfIsPlaying, this);
#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, (mmi_proc_func)&VappMusicPlayerService::onProcEnterUsbMsMode, this);
#endif
}

void VappMusicPlayerService::onDeinit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_ONDEINIT);

    m_isDying = VFX_TRUE;

    hideStatusBarIcon(VFX_FALSE);

    if (m_DBState == DB_OPENING)
    {
        openDBCancel();
    }
    else
    {
        closeDB();
    }

    if(m_plsvHandle)
    {
        srv_plst_library_close(m_plsvHandle);
        srv_plst_destroy(m_plsvHandle);

        m_plsvHandle = 0;
        m_signalPLSVHandleChanged.emit(m_plsvHandle);
    }

    if(m_memPtr && m_memPtr != g_musicPlayerPLSTBgMemPool)
    {
        kal_adm_delete(m_admID);
        VFX_FREE_MEM(m_memPtr);
    }    

    deinitActiveListValidState();

    // deregister events
    mmi_frm_cb_dereg_event(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE,(mmi_proc_func)&VappMusicPlayerService::onProcCheckVolType, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_PROF_IS_PLAYING,(mmi_proc_func)&VappMusicPlayerService::onProcProfIsPlaying, this);
#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_dereg_event(EVT_ID_USB_ENTER_MS_MODE, (mmi_proc_func)&VappMusicPlayerService::onProcEnterUsbMsMode, this);
#endif

#if defined(__MMI_AVRCP_SUPPORT__)
    // unregister AVRCP
    srv_avrcp_clear_cmd_hdlr(onAVRCPCmdCallback);
#endif

    VappMusicPlayerApp *app = getMusicPlayerApp();
    if (app)
    {
        app->exit();
    }
    else
    {
        sendOpenCloseEvent(VFX_FALSE);
    }

    g_mplayerSrvPtr = NULL;

    VfxObject::onDeinit();
}

void VappMusicPlayerService::onObjectNotify(VfxId id, void *userData)
{
    switch (id)
    {
        case VFX_OBJECT_NOTIFY_ID_AFTER_DEINIT:
        {          
            VFX_OBJ_CLOSE(m_context);
            return;
        }
       
        default:
        {
            VfxObject::onObjectNotify(id, userData);
            return;
        }
    }
}

void VappMusicPlayerService::closeMusicPlayer()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_CLOSE_MPLAYER);

    if (!m_isDying)
    {
        VFX_OBJ_CLOSE_INSTANCE(VappMusicPlayerService);
    }
}

VfxBool VappMusicPlayerService::getIsDying()
{
    return m_isDying;
}

vrt_allocator_handle VappMusicPlayerService::getAllocator()
{
    return m_context->getAllocator();
}


// Event handling

void VappMusicPlayerService::sendOpenCloseEvent(VfxBool isOpen)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_SEND_OPEN_CLOSE_EVENT, isOpen);

    // send APP show/hide event
    VappMusicPlayerOpenCloseEvtStruct evt;
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_MUSICPLY_OPEN_CLOSE);
    evt.isOpen = isOpen;

    if(isOpen)
    {
        // Use post emit, app need to finish onRun() process so that widget can query from app launcher
        MMI_FRM_CB_EMIT_POST_EVENT(&evt);
    }
    else
    {
        // Inform widget to close right away. Using post emit may cause widget access variables that have been freed
        MMI_FRM_CB_EMIT_EVENT(&evt);
    }
}

void VappMusicPlayerService::sendPlayStartEvent(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_SEND_PLAY_START_EVENT);

    // event struct
    VappMusicPlayerPlayStartEvtStruct evt;
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_MUSICPLY_PLAY_START);
    evt.isPlayStart = VFX_TRUE;

    // Get detail info
    //MAUI_03215519
    srv_plst_media_details_struct detailInfo = {0};
    //kal_mem_set(&detailInfo, 0, sizeof(srv_plst_media_details_struct));
    
    if(getCurrDetailInfo(&detailInfo))
    {
        vfx_sys_wcscpy(evt.artist, detailInfo.artist);
        vfx_sys_wcscpy(evt.title, detailInfo.title);
    }
    else
    {
        vfx_sys_wcscpy(evt.artist, (const VfxWChar*)GetString(STR_ID_VAPP_MUSIC_PLAYER_UNKNOWN_ARTIST));
        vfx_sys_wcscpy(evt.title, (const VfxWChar *)GetString(STR_ID_VAPP_MUSIC_PLAYER_UNKNOWN_SONG));
    }

    // send APP play info
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}

void VappMusicPlayerService::sendPlayStopEvent()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_SEND_PLAY_STOP_EVENT);

    // send APP playback is stop event
    VappMusicPlayerPlayStartEvtStruct evt;
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_MUSICPLY_PLAY_START);
    evt.isPlayStart = VFX_FALSE;
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}

mmi_ret VappMusicPlayerService::onProcCheckVolType(mmi_event_struct *param)
{
    vapp_vol_dialog_evt_struct *volEvent = (vapp_vol_dialog_evt_struct*)param;
    if (volEvent->type != VAPP_VOL_DIALOG_IS_MEDIA)
    {
        // only handle MEDIA TYPE
        return MMI_RET_OK;
    }

    const PlaybackStateEnum state = g_mplayerSrvPtr->getCtrlPlayback()->getPlayState();

    VappMusicPlayerApp *app = getMusicPlayerApp();

    const VfxBool isTopActive = (app && app->isGroupTopActive());
    const ViewTypeEnum viewType = app ? app->getViewType() : VIEW_TYPE_NONE;
    const VfxBool isPlayerPage = app && ((app->getCoverFlow() && (viewType == VIEW_TYPE_COVER_FLOW || viewType == VIEW_TYPE_COVER_FLOW_SONG)) 
                                      || (app->getNowPlaying() && viewType == VIEW_TYPE_NOW_PLAYING));

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_ON_PROC_VOL_DIALOG_CHECK_VOL_TYPE, state, isTopActive, isPlayerPage, viewType);
    
    if (state == PB_STATE_PLAY 
     || state == PB_STATE_SWITCHING_PLAY 
     || state == PB_STATE_BT_CONNECTING 
     || state == PB_STATE_BT_CONNECTING_WHILE_PLAYING
     || state == PB_STATE_BT_CONNECTING_WHILE_RESUME
     || state == PB_STATE_BT_CONNECTING_WHILE_INTERRUPTED
     || (isTopActive && isPlayerPage))
    {
        // always config media volume if playback state is PLAY
        // in PAUSE state, config media volume if current page is now playing or cover flow
        return !MMI_RET_OK;
    }
    else
    {
        return MMI_RET_OK;
    }
}

mmi_ret VappMusicPlayerService::onProcProfIsPlaying(mmi_event_struct *param)
{
    const PlaybackStateEnum state = g_mplayerSrvPtr->getCtrlPlayback()->getPlayState();

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_ON_PROC_PROF_IS_PLAYING, state);
    
    if (state == PB_STATE_PLAY || state == PB_STATE_BT_CONNECTING_WHILE_PLAYING)
    {
        return !MMI_RET_OK;
    }
    else
    {
        return MMI_RET_OK;
    }
}

#ifdef __MMI_USB_SUPPORT__
mmi_ret VappMusicPlayerService::onProcEnterUsbMsMode(mmi_event_struct *param)
{
    VappMusicPlayerService *pThis = g_mplayerSrvPtr;
    SrvDBStateEnum DBState = pThis->getDBState();

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_ON_PROC_EVT_ID_USB_ENTER_MS_MODE, DBState);

    if (DBState == DB_OPENING)
    {
        pThis->openDBCancel();
    }

    VappMusicPlayerApp *app = getMusicPlayerApp();
    if (app)
    {
        app->onProcEnterUsbMsMode();
    }

    pThis->closeMusicPlayer();

    return MMI_RET_OK;
}
#endif

// General UI

void VappMusicPlayerService::showStatusBarIcon()
{
    wgui_status_icon_bar_show_icon(STATUS_ICON_MEDPLY);
    m_statusIconTimer->stop();
}

void VappMusicPlayerService::hideStatusBarIcon(VfxBool delay)
{
    if (delay && !m_isDying)
    {
        m_statusIconTimer->start();
    }
    else
    {
        onStatusIconTimerTick(NULL);
    }
}

void VappMusicPlayerService::onStatusIconTimerTick(VfxTimer *timer)
{
    wgui_status_icon_bar_hide_icon(STATUS_ICON_MEDPLY);
}

void VappMusicPlayerService::checkMemoryCardReady()
{
    m_memoryCardReady = FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) == FS_NO_ERROR;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_CHECK_MEM_CARD_READY, m_memoryCardReady);
}

VfxBool VappMusicPlayerService::getMemoryCardReady()
{
    return m_memoryCardReady;
}


// PLSV functions

SrvDBStateEnum VappMusicPlayerService::getDBState()
{
    return m_DBState;
}

VfxBool VappMusicPlayerService::getDBIsReady()
{
    return m_DBState == DB_NORMAL || m_DBState == DB_SHRINK;
}

void VappMusicPlayerService::setDBState(SrvDBStateEnum state)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_SET_DB_STATE, state);

    m_DBState = state;
}

void VappMusicPlayerService::initPLSV()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_INIT_PLSV, m_DBState);

    switch (m_DBState)
    {
        case DB_CLOSE:
            break;

        case DB_NORMAL:
            reallocMemory(VFX_TRUE);
            setDBState(DB_SHRINK);
            break;

        case DB_SHRINK:
            {
                VfxBool ret = reallocMemory(VFX_FALSE);
                setDBState(DB_NORMAL);
                if (ret)
                {
                    m_signalPLSVCallback.emit(SRV_PLST_CB_EVT_OPEN, SRV_PLST_OK, 0);
                }
            }
            break;

        case DB_OPENING:
            initDB();
            break;

        default:
            ;
    }
}

void VappMusicPlayerService::initDB()
{
    VfxS32 ret = SRV_PLST_OK;

    VfxBool createPLSV = m_plsvHandle == 0;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_INIT_DB, m_DBState, createPLSV, 1, 0);

    if (createPLSV)
    {
        VfxU32 srv_size = VAPP_MUSICPLY_PLST_DB_MEM_SIZE + SRV_PLST_MIN_MEM_CONTROL; // Shoule equal or larget than SRV_PLST_MIN_MEM_SIZE
        
        srv_plst_create_struct createStruct;
        createStruct.max_item_support = VAPP_MUSICPLY_PLSV_MAX_ITEM;
        VFX_ALLOC_MEM(m_memPtr, srv_size, getMusicPlayerApp());  
        m_admID = kal_adm_create(m_memPtr, srv_size, NULL, KAL_FALSE);
        createStruct.mem_ptr = (void*)m_admID;
        createStruct.mem_size = srv_size;
        createStruct.db_mem_size = VAPP_MUSICPLY_PLST_DB_MEM_SIZE;
        createStruct.gen_mem_size = SRV_PLST_MIN_MEM_CONTROL_GEN_DB;

        VappMusicPlayerService *_this = this;
        m_plsvHandle = srv_plst_create(&ret, _this, &VappMusicPlayerService::SrvPLSVCallback, &createStruct);
        if (m_plsvHandle != NULL)
        {
            VFX_ASSERT(ret >= SRV_PLST_OK);
        }
    }

    m_signalPLSVHandleChanged.emit(m_plsvHandle);

#ifdef __COSMOS_MUSICPLY_CARD_ONLY__
    if (!m_memoryCardReady)
    {
        m_signalPLSVCallback.emit(SRV_PLST_CB_EVT_OPEN, ret, 0);
        setDBState(DB_CLOSE);
        return;
    }
#endif

    // Default playlist: Favorite
    configDefaultPlaylist();
    
    // set reorder type
    ret = srv_plst_config_info(m_plsvHandle, SRV_PLST_CONFIG_REORDER_TYPE, SRV_PLST_PLST_REORDER_DERECTLY);

    // set sort type
    ret = srv_plst_config_info(m_plsvHandle, SRV_PLST_CONFIG_VIEW_SORT_CONTEXT, SRV_PLST_VIEW_SORT_BY_TITLE);

    // set playlist sort type
    ret = srv_plst_config_info(m_plsvHandle, SRV_PLST_CONFIG_PLST_VIEW_SORT_TYPE, SRV_PLST_LIST_SORT_BY_MODIFY_TIME);

    // set search type
    ret = srv_plst_config_info(m_plsvHandle, SRV_PLST_CONFIG_SEARCH_TYPE, SRV_PLST_SEARCH_BY_WORD_FIX);

    // pinyin sort
    if (srv_plst_check_sort_type_support(m_plsvHandle, SRV_PLST_LIST_SORT_BY_PINYIN))
    {
        ret = srv_plst_config_info(m_plsvHandle, SRV_PLST_CONFIG_LIST_VIEW_SORT_TYPE, SRV_PLST_LIST_SORT_BY_PINYIN);
    }

    // set not store last active song
    srv_plst_config_info(m_plsvHandle, SRV_PLST_CONFIG_PLAY_INFO, SRV_PLST_PLAY_INFO_NOT_STORE);

    // return value under repeat all mode
    srv_plst_config_info(m_plsvHandle, SRV_PLST_CONFIG_RET_PLAY_CYCLE_INFO,  SRV_PLST_NO_PLAY_CYCLE_INFO);

    UI_character_type path[SRV_FMGR_PATH_MAX_LEN + 1];
    kal_wsprintf(path, "%w", L"media_lib");
    ret = srv_plst_library_open(m_plsvHandle, path, SRV_PLST_OPEN_ONLY);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_INIT_DB, m_DBState, createPLSV, 2, ret);

    if (ret < SRV_PLST_OK)
    {
        ret = srv_plst_library_open(m_plsvHandle, path, SRV_PLST_OPEN_AUTO);
    }
        
    if (ret == SRV_PLST_OK)
    {
        setDBState(DB_NORMAL);

        // open success
        m_signalPLSVCallback.emit(SRV_PLST_CB_EVT_OPEN, SRV_PLST_OK, 0);
    }
    else if (ret > SRV_PLST_OK)
    {
        setDBState(DB_OPENING);

        // async
        m_signalPLSVCallback.emit(SRV_PLST_CB_EVT_OPEN, SRV_PLST_ASYNC, 0);
    }
    else// (ret < SRV_PLST_OK)
    {
        setDBState(DB_CLOSE);

        // open fail, show popup and close app
        m_signalPLSVCallback.postEmit(SRV_PLST_CB_EVT_OPEN, ret, 0);
    }

}

VfxS32 VappMusicPlayerService::getPLSVHandle()
{
    return m_plsvHandle;
}

void VappMusicPlayerService::openDBCancel()
{
    VfxS32 ret = SRV_PLST_OK;

    if (m_DBState == DB_OPENING)
    {
        if (m_plsvHandle)
        {
            ret = srv_plst_library_stop_open(m_plsvHandle);
        }

        setDBState(DB_CLOSE);
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_OPEN_DB_CANCEL, m_plsvHandle, ret);
}

void VappMusicPlayerService::closeDB()
{
    VfxS32 ret = SRV_PLST_OK;
    
    if (m_plsvHandle)
    {
        ret = srv_plst_library_close(m_plsvHandle);
    }

    setDBState(DB_CLOSE);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_CLOSE_DB, ret);
}

VfxS32 VappMusicPlayerService::reopenDB(VfxBool isPlugIn)
{
    if (!m_plsvHandle)
    {
        return -1;
    }

    closeDB();

    // For memory card plug in case or storage format
    configDefaultPlaylist();

    UI_character_type path[SRV_FMGR_PATH_MAX_LEN + 1];
    kal_wsprintf(path, "%w", L"media_lib");

    
    srv_plst_open_flag_enum openFlag = isPlugIn ? SRV_PLST_OPEN_AFTER_MEDIA_CHANGE : SRV_PLST_OPEN_ONLY;

    (void)srv_plst_plst_clear_curr_view_cache(m_plsvHandle, MMI_TRUE);
    VfxS32 ret = srv_plst_library_open(m_plsvHandle, path, openFlag);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_REOPEN_DB_SRV_PLST_OPEN_AFTER_MEDIA_CHANGE_RESULT_D, ret);

    if (ret > SRV_PLST_OK)
    {
        setDBState(DB_OPENING);
        m_signalPLSVCallback.emit(SRV_PLST_CB_EVT_OPEN, ret, 0);
    }
    else if (ret == SRV_PLST_OK)
    {
        setDBState(getMusicPlayerApp() != NULL ? DB_NORMAL : DB_SHRINK);
        m_signalPLSVCallback.emit(SRV_PLST_CB_EVT_OPEN, ret, 0);
    }
    else if (ret < SRV_PLST_OK)
    {
        ret = srv_plst_library_open(m_plsvHandle, path, SRV_PLST_OPEN_AUTO);

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_REOPEN_DB_SRV_PLST_OPEN_AFTER_MEDIA_CHANGE_RESULT_D, ret);

        if (ret > SRV_PLST_OK)
        {
            setDBState(DB_OPENING);
            m_signalPLSVCallback.emit(SRV_PLST_CB_EVT_OPEN, ret, 0);
        }
        else if (ret == SRV_PLST_OK)
        {
            setDBState(getMusicPlayerApp() != NULL ? DB_NORMAL : DB_SHRINK);
            m_signalPLSVCallback.emit(SRV_PLST_CB_EVT_OPEN, ret, 0);
        }
        else
        {
            closeMusicPlayer();
        }
    }

    return ret; 
}

VfxBool VappMusicPlayerService::reallocMemory(VfxBool shrink)
{
    kal_prompt_trace(MOD_MMI_MEDIA_APP, "[MUSICPLY] VappMusicPlayerService::reallocMemory(), shrink=[%d]", shrink);

    VfxS32 ret;
    KAL_ADM_ID new_admID;
    void *new_memPtr;
    VfxU32 size, db_size, gen_size;

    // Allocate new DB memory
    if(shrink)
    {
        size = VAPP_MUSICPLY_PLST_DB_BACKGROUND_MEM_SIZE + SRV_PLST_MIN_MEM_CONTROL_BACKGROUND; // Should less than SRV_PLST_MIN_MEM_SIZE
        
        db_size = VAPP_MUSICPLY_PLST_DB_BACKGROUND_MEM_SIZE;
        gen_size = 0;

        new_memPtr = g_musicPlayerPLSTBgMemPool;
    }
    else
    {
        size = VAPP_MUSICPLY_PLST_DB_MEM_SIZE + SRV_PLST_MIN_MEM_CONTROL; // Should equal SRV_PLST_MIN_MEM_SIZE
        
        db_size = VAPP_MUSICPLY_PLST_DB_MEM_SIZE;
        gen_size = SRV_PLST_MIN_MEM_CONTROL_GEN_DB;

        VfxApp *app = getMusicPlayerApp();

        // App should exist in this case
        VFX_ASSERT(app);

        VFX_ALLOC_MEM(new_memPtr, size, app);
    }
    
    new_admID = kal_adm_create(new_memPtr, size, NULL, KAL_FALSE);

    // Recreate DB with new memory and original context to keep state
    srv_plst_create_struct createStruct;
    createStruct.max_item_support = VAPP_MUSICPLY_PLSV_MAX_ITEM;
    createStruct.mem_ptr = (void*)new_admID;
    createStruct.mem_size = size;
    createStruct.db_mem_size = db_size;
    createStruct.gen_mem_size = gen_size;

    m_plsvHandle = srv_plst_realloc_memory(&ret, m_plsvHandle, &createStruct, NULL);
    m_signalPLSVHandleChanged.emit(m_plsvHandle);

    kal_adm_delete(m_admID);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_MUSICPLY_SRV_REALLOCMEMORY, shrink, size, db_size, m_DBState, ret);

    if(ret != SRV_PLST_OK)
    {
        // if handle is not null means create success but open fail, free memory in onDeinit()
        if(m_plsvHandle == 0)
        {
            kal_adm_delete(new_admID);

            if (!shrink)
            {
                VFX_FREE_MEM(new_memPtr);
            }
        }
        // open fail, show popup and close app
        m_signalPLSVCallback.postEmit(SRV_PLST_CB_EVT_OPEN, ret, 0);
    }

    if (shrink)
    {
        // Free original DB memory
        if(m_memPtr)
        {
            VFX_FREE_MEM(m_memPtr);
        }
    }

    m_admID = new_admID;
    m_memPtr = new_memPtr;

    return ret == SRV_PLST_OK;
}

void VappMusicPlayerService::configDefaultPlaylist()
{
    VfxS32 ret = srv_plst_default_playlist_configure(m_plsvHandle, SRV_PLST_DEF_MY_FAVOURITE);
    
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_CONFIG_DEFAULT_PLAYLIST, ret);
}

VfxS32 VappMusicPlayerService::SrvPLSVCallback(void* user_data, srv_plst_cb_evt_enum cb_event, S32 result, VfxU32 ca_para_2)
{
    VappMusicPlayerService *pThis = reinterpret_cast<VappMusicPlayerService*>(user_data);
    return pThis->doSrvPLSVCallback(user_data, cb_event, result, ca_para_2);
}

VfxS32 VappMusicPlayerService::doSrvPLSVCallback(void* user_data, srv_plst_cb_evt_enum cb_event, S32 result, VfxU32 ca_para_2)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_DO_PLSV_CALLBACK, cb_event, result, ca_para_2);

    VfxS32 ret = 1;

    switch (cb_event)
    {
        case SRV_PLST_CB_EVT_OPEN:
            {
                if (m_DBState == DB_OPENING)
                {
                    VappMusicPlayerApp *app = getMusicPlayerApp();

                    if (result == SRV_PLST_OK)
                    {
                        setDBState(app != NULL ? DB_NORMAL : DB_SHRINK);
                    }
                    else if (result < SRV_PLST_OK)
                    {
                        if (app == NULL)
                        {
                            closeMusicPlayer();
                        }
                    }
                }
            }
            break;

        case SRV_PLST_CB_EVT_DELETE_ACTIVE_MEDIA:   
            {
                // current playing song, return True to delete, False to keep
                // only deny deleting if active song is playing or paused
                if(isUndeletableState())
                {
                    ret = VFX_FALSE;
                }
                else
                {
                    m_ctrlPlayback->clearInterruptState();
                    clearActivePlaylist();
                    onStop();                
                    m_playAfterSwitchSong = VFX_TRUE;

                    ret = VFX_TRUE;
                }
            }
            break;

        case SRV_PLST_CB_EVT_DELETE_FROM_FMGR:
            {
                // We do not allow delete currnet playing song from file manager
                srv_plst_delete_file_from_fmgr_struct *fileInfo = reinterpret_cast<srv_plst_delete_file_from_fmgr_struct*>(ca_para_2);
                VfxWString strFilePath = VFX_WSTR_MEM((VfxWChar*)fileInfo->path);

                SongInfoStruct info;
                getCurrInfo(info);

                VfxBool isAllowDelete;

                if (info.filepath == strFilePath)
                {
                    isAllowDelete = VFX_FALSE;
                }
                else
                {
                    isAllowDelete = VFX_TRUE;
                }

                return isAllowDelete;
            }
            break;

        case SRV_PLST_CB_EVT_MSDC_PLUG_OUT: // SD card out
        case SRV_PLST_CB_EVT_MSDC_PLUG_IN:  // SD card in
            {
                m_memoryCardReady = cb_event == SRV_PLST_CB_EVT_MSDC_PLUG_IN;

#ifdef __COSMOS_MUSICPLY_CARD_ONLY__
                VappMusicPlayerApp *app = getMusicPlayerApp();
                if (app)
                {
                    if (!m_memoryCardReady)
                    {
                        m_ctrlPlayback->clearInterruptState();

                        clearActivePlaylist();

                        onStop();

                        m_ctrlPlayback->setPlayState(PB_STATE_NONE);

                        m_playAfterSwitchSong = VFX_TRUE;
                    }

                    if (m_DBState == DB_OPENING)
                    {
                        openDBCancel();
                    }
                    else if (m_DBState == DB_NORMAL)
                    {
                        // close DB in APP side
                        //closeDB();
                    }
                    else if (m_memoryCardReady && m_DBState == DB_CLOSE)
                    {
                        setDBState(DB_OPENING);
                    }
                }
                else
                {
                    closeMusicPlayer();
                }
#else
                m_ctrlPlayback->clearInterruptState();
                clearActivePlaylist();
                onStop();                
                m_playAfterSwitchSong = VFX_TRUE;

                VappMusicPlayerApp *app = getMusicPlayerApp();
                if (app)
                {
                    ActionEnum action = app->getActionMode();
                    if ((action == ACTION_LAUNCHING || action == ACTION_LAUNCHING_FROM_BG) && m_DBState != DB_OPENING)
                    {
                        // plug in/out while launching/relaunching
                        if(m_plsvHandle)
                        {
                            closeDB();
                            srv_plst_destroy(m_plsvHandle);
                            m_plsvHandle = 0;
                            m_signalPLSVHandleChanged.emit(m_plsvHandle);
                        }
                        setDBState(DB_OPENING);
                        break;
                    }
                }
                else
                {
                    result = reopenDB(cb_event == SRV_PLST_CB_EVT_MSDC_PLUG_IN);
                }
#endif
            }
            break;

        case SRV_PLST_CB_EVT_PRE_FORMAT:
            //VFX_OBJ_CLOSE_INSTANCE(VappMusicPlayerService);
            closeMusicPlayer();
            break;

        case SRV_PLST_CB_EVT_AFT_FORMAT:
            break;
    }

    m_signalPLSVCallback.emit(cb_event, result, ca_para_2);

    return ret;
}

void VappMusicPlayerService::signalOpenDBOK()
{
    // for the case opening DB ok during App launching and init2ndStage connecting App::onPLSVCallback to signal
    // the OPEN OK callback will not be handled by App::onPLSVCallback
    m_signalPLSVHandleChanged.emit(m_plsvHandle);
    m_signalPLSVCallback.emit(SRV_PLST_CB_EVT_OPEN, SRV_PLST_OK, 0);
}

VfxU32 VappMusicPlayerService::getActiveListID(VfxU32 index)
{
    VfxU32 ID = 0;

    if (getDBIsReady() && m_plsvHandle)
    {
        srv_plst_media_get_id(m_plsvHandle, index, &ID);
    }
    else
    {
        ID = 0;
    }

    return ID;
}

VfxBool VappMusicPlayerService::setActive(VfxU32 index, VfxBool updateDB)
{
    VfxS32 ret = SRV_PLST_OK;

    if (getDBIsReady() && m_plsvHandle)
    {
        if (updateDB)
        {
            ret = srv_plst_list_set_as_active(m_plsvHandle, index);
        }
        else
        {
            ret = srv_plst_list_set_as_active_ex(m_plsvHandle, index, MMI_FALSE);
        }
        getCurrInfo(m_activeInfo, VFX_TRUE);
    }

    updateActiveCount();
    
    if (getMusicPlayerApp())
    {
        VappMusicPlayerContentProvider *provider = getMusicPlayerApp()->getProvider();
        if (provider)
        {
            provider->setHighLightInfo(index);
            HighLightInfoStruct hlInfo = provider->getHighLightInfo();
            m_activeViewType = hlInfo.viewType;
        }
    }

    return ret == SRV_PLST_OK;
}

void VappMusicPlayerService::getCurrInfo(SongInfoStruct &info, VfxBool query)
{
    if (!query)
    {
        info = m_activeInfo;
        return;
    }

    if (getDBIsReady() && m_plsvHandle)
    {
        // for list view, the info.index should be set first
        UI_string_type buffer = NULL;
        VFX_ALLOC_MEM(buffer, sizeof(UI_character_type)*SRV_PLST_MAX_PATH_LEN, this);

        VfxS32 ret = srv_plst_plst_item_get_active_media_info_curr(m_plsvHandle, &info.id, &info.index, buffer);
        if (ret == SRV_PLST_OK)
        {
            info.filepath.loadFromMem(buffer);
        }
        else
        {
            info.filepath.format("");
            info.id = 0;
        }

        m_activeInfo = info;
        m_activeInfo.retValue = ret;

        VFX_FREE_MEM(buffer);
        buffer = NULL;
    }
}

VfxBool VappMusicPlayerService::getCurrDetailInfo(srv_plst_media_details_struct *infoStruct)
{
    if (getDBIsReady() && m_plsvHandle)
    {
        SongInfoStruct info;
        getCurrInfo(info);

        // Compare cache id with active ID
        if (m_activeDetailInfo.media_id == info.id && m_activeDetailInfo.media_id != 0)
        {
            memcpy(infoStruct, &m_activeDetailInfo, sizeof(srv_plst_media_details_struct));
            return VFX_TRUE;
        }
        else
        {
            if(info.id != 0)
            {
                VfxS32 ret = srv_plst_media_get_details(m_plsvHandle, info.id, infoStruct);
                if (ret == SRV_PLST_OK)
                {
                    memcpy(&m_activeDetailInfo, infoStruct, sizeof(srv_plst_media_details_struct));
                    return VFX_TRUE;
                }
            }
        }
    }

    return VFX_FALSE;
}

void VappMusicPlayerService::getAlbumCoverByDefaultBuffer(VfxU32 ID, VfxImageBuffer &imgBuf)
{
#if defined(__COSMOS_MUSICPLY_COVER_FLOW__) || defined(__COSMOS_WIDGET_MUSICPLY_COVER_SUPPORT__) || defined(__MMI_VUI_WIDGET_3D_MUSIC_PLAYER__)
    
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_GET_ALBUM_COVER_BY_DEF_BUF, ID, g_albumCoverSongID, g_albumCoverValid);

    imgBuf.ptr = g_albumCoverBuffer;

    // check if the requested image is the same as current one
    if (g_albumCoverSongID == ID)
    {
        imgBuf.pitchBytes = SRV_PLST_ARTWORK_RESIZED_WIDTH * 2;
        imgBuf.width = SRV_PLST_ARTWORK_RESIZED_WIDTH;
        imgBuf.height = SRV_PLST_ARTWORK_RESIZED_HEIGHT;
        imgBuf.colorFormat = VRT_COLOR_TYPE_RGB565;

        if(!g_albumCoverValid)
        {
            imgBuf.ptr = NULL;
        }
        return;
    }
    else
    {
        getAlbumCover(ID, imgBuf);
        g_albumCoverSongID = ID;

        if(imgBuf.ptr == NULL)
        {
            g_albumCoverValid = VFX_FALSE;
        }
        else
        {
            g_albumCoverValid = VFX_TRUE;
        }
    }

#else

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_GET_ALBUM_COVER_BY_DEF_BUF, ID, 0, 0);

    imgBuf.ptr = NULL;

#endif
}

void VappMusicPlayerService::getAlbumCover(VfxU32 ID, VfxImageBuffer &imgBuf)
{
    if (imgBuf.ptr == NULL)
    {
        return;
    }

    imgBuf.pitchBytes = SRV_PLST_ARTWORK_RESIZED_WIDTH * 2;
    imgBuf.width = SRV_PLST_ARTWORK_RESIZED_WIDTH;
    imgBuf.height = SRV_PLST_ARTWORK_RESIZED_HEIGHT;
    imgBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
    
    VfxU32 dataSize = imgBuf.pitchBytes * imgBuf.height;

    U8 *jpgRawData = (U8*)mmi_frm_asm_alloc_anonymous(dataSize);
    if (!jpgRawData)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_MUSICPLY_SRV_GET_ALBUM_COVER_ALLOC_MEM_FAIL);
        imgBuf.ptr = NULL;
        return;
    }

    VfxBool hasCover = getAlbumCoverByID(ID, jpgRawData, dataSize);

    if (!hasCover)
    {
        mmi_frm_asm_free_anonymous(jpgRawData);
        imgBuf.ptr = NULL;
        return;
    }

    // decode JPG
    if (dataSize > 0)
    {
        VfxS32 ret, w, h;
        ret = gdi_image_get_dimension_mem(
                GDI_IMAGE_TYPE_JPG,
                jpgRawData,
                dataSize,
                &w,
                &h);

        U8 *bufPtr = imgBuf.ptr;

        if (ret == GDI_SUCCEED)
        {
            if (w > SRV_PLST_ARTWORK_RESIZED_WIDTH || h > SRV_PLST_ARTWORK_RESIZED_HEIGHT)
            {
                w = SRV_PLST_ARTWORK_RESIZED_WIDTH;
                h = SRV_PLST_ARTWORK_RESIZED_HEIGHT; 
            }

            VfxU32 bufferSize = w * h * 2;

            gdi_handle tmpLayer;
            gdi_layer_create_using_outside_memory(
                    0,
                    0,
                    w,
                    h,
                    &tmpLayer,
                    bufPtr,
                    bufferSize);
            gdi_layer_push_and_set_active(tmpLayer);
            gdi_push_and_set_alpha_blending_source_layer(tmpLayer);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
            ret = gdi_image_draw_resized_mem(
                    0,
                    0,
                    w,
                    h,
                    jpgRawData,
                    GDI_IMAGE_TYPE_JPG,
                    bufferSize);
            gdi_pop_and_restore_alpha_blending_source_layer();
            gdi_layer_pop_and_restore_active();
            gdi_layer_free(tmpLayer);

            if(ret != GDI_SUCCEED)
            {
                imgBuf.ptr = NULL;
            }
        }
        else
        {
            imgBuf.ptr = NULL;
        }
    }
    else
    {
        imgBuf.ptr = NULL;
    }
    
    mmi_frm_asm_free_anonymous(jpgRawData);
    jpgRawData = NULL;
}

VfxBool VappMusicPlayerService::getAlbumCoverByID(VfxU32 ID, void *buffer, VfxU32 &bufferSize)
{
    if (getDBIsReady() && m_plsvHandle)
    {
        srv_plst_list_get_display_struct cover;
        cover.index = ID;//media_id;
        cover.buff_size = bufferSize;
        cover.string_ptr= (U32)buffer;
        
        VfxS32 ret = srv_plst_list_get_artwork_by_media_id(m_plsvHandle, &cover);
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_GET_ALBUM_COVER_BY_ID, ret);

        bufferSize = cover.buff_size;

        return ret == SRV_PLST_OK;
    }
    else
    {
        return VFX_FALSE;
    }
}

VfxWString VappMusicPlayerService::getActiveFilePath()
{
    return m_activeInfo.filepath;
}

void VappMusicPlayerService::clearActiveFilePath()
{
    m_activeInfo.filepath.setEmpty();
}

ViewTypeEnum VappMusicPlayerService::getActiveViewType()
{
    return m_activeViewType;
}

VfxU32 VappMusicPlayerService::getActiveCount()
{
    return m_activeCount;
}

void VappMusicPlayerService::updateActiveCount()
{
    if (getDBIsReady() && m_plsvHandle)
    {
        VfxU32 count;
        VfxS32 ret = srv_plst_get_active_plst_item_count(m_plsvHandle, &count);
        m_activeCount = count;

        ////>m_parent->m_signalPLSVReturn.emit(ret);
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_UPDATE_ACITVE_COUNT, ret);
    }
}

VfxU32 VappMusicPlayerService::getActiveIndex()
{
    return m_activeInfo.index;
}

void VappMusicPlayerService::updateActiveIndex()
{
    if (getDBIsReady() && m_plsvHandle)
    {
        VfxS32 ret = srv_plst_plst_get_active_plst_item_index(m_plsvHandle, &m_activeInfo.index);
        
        ////>m_parent->m_signalPLSVReturn.emit(ret);
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_GET_ACTIVE_INDEX_FROM_PLSV, ret);
    }
}

VfxU32 VappMusicPlayerService::getActiveID()
{
    return m_activeInfo.id;
}

void VappMusicPlayerService::updateActiveID()
{
    SongInfoStruct info;
    getCurrInfo(info);
}

VfxU32 VappMusicPlayerService::getActivePlayListID()
{
    return m_activePlayListID;
}

void VappMusicPlayerService::setActivePlayListID(VfxS32 listID)
{
    m_activePlayListID = listID;
}

void VappMusicPlayerService::clearActivePlaylist()
{
    VfxS32 ret = 0;
    
    if (getDBIsReady() && m_plsvHandle)
    {
        ret = srv_plst_plst_clear_active_list(m_plsvHandle);
        ////>m_parent->m_signalPLSVReturn.emit(ret);
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_MUSICPLY_SRV_CLR_ACTIVE_PLAYLIST, ret);
    
    // Force to clear
    m_activeCount = 0;
    m_activeInfo.index = 0;
    m_activeInfo.filepath.setEmpty();
    m_activeInfo.id = 0;

    deinitActiveListValidState();

    vfxPostInvoke1(m_ctrlPlayback, &VappMusicPlayerCtrlPlayback::setPlayState, PB_STATE_NONE);
}

void VappMusicPlayerService::setDuration(VfxU32 ID, VfxU32 duration)
{
    VfxS32 ret = 0;
    VfxBool isIDMatch = VFX_FALSE;

    if (getDBIsReady() && m_plsvHandle)
    {   
        VfxBool isIDMatch = ID == m_activeInfo.id;
        if (isIDMatch)
        {
            if ((S32)duration != m_activeDetailInfo.duration)
            {
                m_activeDetailInfo.duration = (S32)duration;
                ret = srv_plst_media_update_details(m_plsvHandle, ID, &m_activeDetailInfo);
                ////>m_parent->m_signalPLSVReturn.emit(ret);
            }
        }
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_MUSICPLY_SRV_SET_DURATION, ret, isIDMatch);
}

VfxS32 VappMusicPlayerService::prev(SongInfoStruct &info)
{
    vfx_sys_mem_pool_status_struct status;
    m_context->statistics(status);  //to get the context statistics

    if (getDBIsReady() && m_plsvHandle)
    {
        UI_string_type buffer = NULL;
        VFX_ALLOC_MEM(buffer, sizeof(UI_character_type)*SRV_PLST_MAX_PATH_LEN, this);

        VfxS32 ret = srv_plst_plst_item_get_active_media_info_manul_prev(m_plsvHandle, &info.id, &info.index, buffer);
        
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_PREV, ret);

        if (ret == SRV_PLST_OK || ret == SRV_PLST_RET_EMPTY)
        {
            info.filepath.loadFromMem(buffer);
        }
        else
        {
            info.filepath.format("");
        }

        VFX_FREE_MEM(buffer);
        buffer = NULL;

        updateActiveIndex();

        ////>m_parent->m_signalPLSVReturn.emit(ret);

        return ret;
    }
    else
    {
        return -1;
    }
}

VfxS32 VappMusicPlayerService::next(SongInfoStruct &info, VfxBool delayUpdateIndex)
{
    if (getDBIsReady() && m_plsvHandle)
    {
        UI_string_type buffer = NULL;
        VFX_ALLOC_MEM(buffer, sizeof(UI_character_type)*SRV_PLST_MAX_PATH_LEN, this);

        VfxS32 ret;

        if(delayUpdateIndex)
        {
            // Set index to 0 and update later
            ret = srv_plst_plst_item_get_active_media_info_manul_next(m_plsvHandle, &info.id, NULL, buffer);
            info.index = 0;
        }
        else
        {
            ret = srv_plst_plst_item_get_active_media_info_manul_next(m_plsvHandle, &info.id, &info.index, buffer);
        }

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_NEXT, ret);

        if (ret == SRV_PLST_OK || ret == SRV_PLST_RET_EMPTY)
        {
            info.filepath.loadFromMem(buffer);
        }
        else
        {
            info.filepath.format("");
        }

        VFX_FREE_MEM(buffer);
        buffer = NULL;

        if(!delayUpdateIndex)
        {
            updateActiveIndex();
        }

        ////>m_parent->m_signalPLSVReturn.emit(ret);

        return ret;
    }
    else
    {
        return -1;
    }    
}

VfxS32 VappMusicPlayerService::autoNext(SongInfoStruct &info)
{
    if (getDBIsReady() && m_plsvHandle)
    {
        //VfxS32 ret = srv_plst_plst_item_get_active_media_info_auto(m_plsvHandle, &info.id, &info.index, ((UI_string_type)&info.filepath));
        UI_string_type buffer = NULL;
        VFX_ALLOC_MEM(buffer, sizeof(UI_character_type)*SRV_PLST_MAX_PATH_LEN, this);

        VfxS32 ret = srv_plst_plst_item_get_active_media_info_auto(m_plsvHandle, &info.id, &info.index, buffer);

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_AUTO_NEXT, ret);

        if (ret == SRV_PLST_OK || ret == SRV_PLST_RET_EMPTY)
        {
            info.filepath.loadFromMem(buffer);
        }
        else
        {
            info.filepath.format("");
        }

        VFX_FREE_MEM(buffer);
        buffer = NULL;

        updateActiveIndex();

        ////>m_parent->m_signalPLSVReturn.emit(ret);

        return ret;
    }
    else
    {
        return -1;
    }    
}

void VappMusicPlayerService::setRepeat(srv_plst_repeat_enum repeatState)
{
    VfxS32 ret = 0;

    if (getDBIsReady() && m_plsvHandle)
    {
        ret = srv_plst_config_repeat(m_plsvHandle, repeatState);
        m_repeatState = repeatState;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_SET_REPEAT, ret, repeatState);
}

void VappMusicPlayerService::setShuffle(srv_plst_shuffle_enum shuffleState)
{
    VfxS32 ret = 0;

    if (getDBIsReady() && m_plsvHandle)
    {
        ret = srv_plst_config_shuffle(m_plsvHandle, shuffleState);
        m_shuffleState = shuffleState;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_SET_SHUFFLE, ret, shuffleState);
}

srv_plst_repeat_enum VappMusicPlayerService::getRepeat()
{
    return m_repeatState;
}

srv_plst_shuffle_enum VappMusicPlayerService::getShuffle()
{
    return m_shuffleState;
}


// Playback functions

VappMusicPlayerCtrlPlayback* VappMusicPlayerService::getCtrlPlayback()
{
    return m_ctrlPlayback;
}

void VappMusicPlayerService::onPlaybackStateChange(PlaybackStateEnum state)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_PLAYBACK_STATE_CHANGE, state);

    if (state == PB_STATE_OPEN)
    {
        sendPlayStartEvent();
    }

    // show/hide play icon while playing
    if (state == PB_STATE_PLAY 
     || state == PB_STATE_BT_CONNECTING_WHILE_PLAYING 
     || state == PB_STATE_SWITCHING_PLAY)
    {
        // set the validation flag to TRUE if play success
        setSongValid(getActiveIndex(), VFX_TRUE);

        m_playAfterSwitchSong = VFX_TRUE;

        showStatusBarIcon();
    }
    else
    {
        VappMusicPlayerApp *app = getMusicPlayerApp();
        ActionEnum action = app ? app->getActionMode() : ACTION_NONE;

        VfxBool delayHide = action != ACTION_REFRESH 
                         && action != ACTION_RESET 
						 && state != PB_STATE_INTERRUPTED
                         && getPlayAfterSwitchSong();

        hideStatusBarIcon(delayHide);
    }
}

void VappMusicPlayerService::onPrev(VfxBool delayPlay)
{
    onPrevNext(VFX_FALSE, PREV, delayPlay);
}

void VappMusicPlayerService::onNext(GetNextModeEnum nextMode, VfxBool delayPlay)
{
    onPrevNext(VFX_TRUE, nextMode, delayPlay);
}

void VappMusicPlayerService::onPrevNext(VfxBool isNext, GetNextModeEnum nextMode, VfxBool delayPlay)
{
    if (m_isDying)
    {
        return;
    }
    
    VappMusicPlayerApp *app = getMusicPlayerApp();

    // Disable delay play if backlight is off
    VfxBool bIsBackLightOn = isBackLightOn();
    if(!bIsBackLightOn)
    {
        delayPlay = VFX_FALSE;
    }

    PlaybackStateEnum state = m_ctrlPlayback->getPlayState();

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_ON_PREV_NEXT, isNext, nextMode, delayPlay, state, m_playAfterSwitchSong, bIsBackLightOn);

    stopFindNextTimer();
    stopDelayPlayTimer();
    stopPlaybackErrTimer();

    m_playAfterSwitchSong = m_playAfterSwitchSong
                         && state != PB_STATE_OPEN 
                         && state != PB_STATE_PAUSE 
                         && state != PB_STATE_STOP
                         && state != PB_STATE_CLOSE
                         && state != PB_STATE_INTERRUPTED
                         && state != PB_STATE_SWITCHING_NOT_PLAY;

    // get info of next song
    SongInfoStruct info;
    info.id = 0;
    info.index = 0;
    info.retValue = 0;

    VfxS32 ret = SRV_PLST_OK;

    switch (nextMode)
    {
        case NEXT:
            // If in now playing screen, delay update index/count to speed up page change
            if (app && app->getNowPlaying() && getShuffle())
            {
                ret = next(info, VFX_TRUE);
            }
            else
            {
                ret = next(info);
            }
            break;

        case AUTO_NEXT:
            ret = autoNext(info);
            break;

        case CURRENT:
            getCurrInfo(info);
            break;
            
        case PREV:
            ret = prev(info);
            break;
    }
    
    //info.retValue = ret;
    if (ret == SRV_PLST_RET_EMPTY)
    {
        // for repeat none, switch to next song and stop
        if (delayPlay)
        {
            m_playAfterSwitchSong = VFX_FALSE;
        }
    }
    else if (ret < SRV_PLST_OK)
    {
        // handle fail to get next song
        onStop();

        if (app)
        {
            app->onPrevNext(isNext, nextMode, delayPlay, ret);
        }
        return;
    }

    // update active info
    getCurrInfo(m_activeInfo, VFX_TRUE);
    m_activeInfo.retValue = ret;

    m_ctrlPlayback->clearInterruptState(VFX_TRUE, VFX_FALSE);
    m_ctrlPlayback->clearFilePath();

    // clear duration to 0 and update after open
    m_ctrlPlayback->resetDuration();

    // emit signal and event and then play
    m_signalOnPrevNext.emit(isNext);
    sendPlayStartEvent();

    if (info.id == 0 && info.index == 0)
    {
        onStop();
    }
    else
    {
        if (!app)
        {
            onPlay(delayPlay);
        }

        if (delayPlay)
        {
            m_ctrlPlayback->setPlayState(m_playAfterSwitchSong ? PB_STATE_SWITCHING_PLAY : PB_STATE_SWITCHING_NOT_PLAY);
        }
        else
        {
            if (!m_playAfterSwitchSong)
            {
                m_ctrlPlayback->stop();
            }
        }
    }

    m_ctrlPlayback->clearSeekInfo();

    if (app)
    {
        // update high light index before play
        if (app->getProvider())
        {
            app->getProvider()->updateHighLightInfo(m_activeInfo);
        }

        app->onPrevNext(isNext, nextMode, delayPlay, ret);
    }
}

void VappMusicPlayerService::onDelayPlayTimerTick(VfxTimer *t)
{
    m_delayPlayTimer->stop();

    const PlaybackStateEnum state = m_ctrlPlayback->getPlayState();
    const VfxBool isInterrupted = m_ctrlPlayback->getInterruptedInfo().isInterrupted;

    if (isInterrupted)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_ON_PLAYER_BTN_TIMER_TICK_IS_INTERRUPTED, isInterrupted, state);

        m_ctrlPlayback->setPlayState(PB_STATE_INTERRUPTED);
        return;
    }
    
    // user stop rapidly click the playback button, do the play action
    VappMusicPlayerApp *app = getMusicPlayerApp();
    if (app && (app->getCoverFlow() || app->getNowPlaying()))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_ON_PLAYER_BTN_TIMER_TICK_PLAYER_PAGE, state);

        VfxBool isCoverFlow;
        VappMusicPlayerPlayerBase *player = app->getTopPlayer(isCoverFlow);
        
        if (state == PB_STATE_SWITCHING_NOT_PLAY)
        {
            player->open(getActiveFilePath());

            m_ctrlPlayback->stop();

        }
        else
        {
            player->play(getActiveFilePath());
        }

        // Delay play when rotating back to now playing screen, the now playing screen duration will be 0 when enter. Force update here
        if(app->getCoverFlow() && app->getNowPlaying())
        {
            app->getNowPlaying()->updateTimeInfo();
        }
    }
    else
    {
        if (state == PB_STATE_SWITCHING_NOT_PLAY)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_ON_PLAYER_BTN_TIMER_TICK_PB_STATE_SWITCHING_NOT_PLAY);

            m_ctrlPlayback->open(getActiveFilePath());
            m_ctrlPlayback->stop();
        }
        else
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_ON_PLAYER_BTN_TIMER_TICK_PLAY_SONG, state);

            onPlay(VFX_FALSE);
        }
    }

    m_isDelayPlay = VFX_FALSE;
    
    m_playAfterSwitchSong = (state == PB_STATE_SWITCHING_PLAY);
}

void VappMusicPlayerService::onPlay(VfxBool delayPlay)
{
    const PlaybackStateEnum state = m_ctrlPlayback->getPlayState();
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_ON_PLAY, delayPlay, state);

    if (delayPlay)
    {
        m_delayPlayTimer->start();
        if(m_playAfterSwitchSong)
        {
            m_ctrlPlayback->registerInterruptCallback();
        }
        m_ctrlPlayback->setPlayState(m_playAfterSwitchSong ? PB_STATE_SWITCHING_PLAY : PB_STATE_SWITCHING_NOT_PLAY);
    }
    else if (m_activeInfo.retValue == SRV_PLST_RET_EMPTY || !m_playAfterSwitchSong)
    {
        // If song is valid, then open it and stop on the song
        if(getSongValid(m_activeInfo.index))
        {
            m_ctrlPlayback->open(m_activeInfo.filepath);
        }
        // Just set file path to control playback. (Open it will open fail and jump to next song to play)
        else
        {
            m_ctrlPlayback->setFilePath(m_activeInfo.filepath);
            m_ctrlPlayback->setPlayState(PB_STATE_PLAYBACK_FAIL);
        }
    }
    else
    {
        if(m_ctrlPlayback && m_ctrlPlayback->open(m_activeInfo.filepath))
        {
            m_ctrlPlayback->play();
        }
    }

    m_ctrlPlayback->clearInterruptState(VFX_TRUE, VFX_TRUE);

    setIsDelayPlay(delayPlay);
}

void VappMusicPlayerService::onStop(VfxBool sendStopEvent)
{
    const PlaybackStateEnum state = m_ctrlPlayback->getPlayState();
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_ON_STOP, state);

    stopFindNextTimer();
    stopDelayPlayTimer();

    m_ctrlPlayback->stop();
    m_ctrlPlayback->closeFile();

    VappMusicPlayerApp *app = getMusicPlayerApp();
    if (app)
    {
        app->onStop();
    }

    if (sendStopEvent)
    {
        sendPlayStopEvent();
    }
}

void VappMusicPlayerService::startDelayPlayTimer()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_START_DELAY_PLAY_TIMER);
    if (m_delayPlayTimer)
    {
        m_delayPlayTimer->stop();
        m_delayPlayTimer->start();
    }
}

void VappMusicPlayerService::stopDelayPlayTimer()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_STOP_DELAY_PLAY_TIMER);
    if (m_delayPlayTimer)
    {
        m_delayPlayTimer->stop();
    }
}

VfxBool VappMusicPlayerService::getIsDelayPlayTimerEnable()
{
    return m_delayPlayTimer->getIsEnabled();
}

VfxBool VappMusicPlayerService::getIsDelayPlay()
{
    return m_isDelayPlay;
}

void VappMusicPlayerService::setIsDelayPlay(VfxBool isDelayPlay)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_SET_DELAY_PLAY, isDelayPlay);

    m_isDelayPlay = isDelayPlay;
}

VfxBool VappMusicPlayerService::getPlayAfterSwitchSong()
{
    return m_playAfterSwitchSong;
}

void VappMusicPlayerService::setPlayAfterSwitchSong(VfxBool isPlay)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_SET_PLAY_AFTER_SWITCH, isPlay);

    m_playAfterSwitchSong = isPlay;
}

void VappMusicPlayerService::initActiveListValidState()
{
    ///// to enhance: cache more info of song in active playlist, ex: id, valid state...etc

    deinitActiveListValidState();

    const VfxU32 listCount = getActiveCount();

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_INIT_ACTIVE_LIST_VALID_STATE, listCount);

    if (listCount > 0)
    {
        m_activeListValidStateCount = listCount;

        VfxU32 quotient = listCount/(sizeof(VfxU8)*8);
        VfxU32 remainder = listCount%(sizeof(VfxU8)*8);
        VfxU32 num = quotient + (remainder ? 1 : 0);

        VFX_ALLOC_MEM(m_activeListValidState, sizeof(VfxU8) * num, this);
        VFX_ALLOC_MEM(m_activeListLyricsState, sizeof(VfxU8) * num, this);

        for (VfxU32 i = 0; i < num; i++)
        {
            m_activeListValidState[i] = 0xFF;
            m_activeListLyricsState[i] = 0xFF;
        }
    }
}

void VappMusicPlayerService::deinitActiveListValidState()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_DEINIT_ACTIVE_LIST_VALID_STATE, m_activeListValidState);

    if (m_activeListValidState)
    {
        VFX_FREE_MEM(m_activeListLyricsState);
        m_activeListLyricsState = NULL;
        VFX_FREE_MEM(m_activeListValidState);
        m_activeListValidState = NULL;

        m_activeListValidStateCount = 0;
    }
}

void VappMusicPlayerService::setSongValid(const VfxU32 index, const VfxBool isValid)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_SET_SONG_VALID, m_activeListValidState, index, isValid, m_activeListValidStateCount);

    if (m_activeListValidState && (index < m_activeListValidStateCount))
    {
        VfxU32 quotient = index/(sizeof(VfxU8)*8);
        VfxU32 remainder = index%(sizeof(VfxU8)*8);
        VfxU8 oper = 0x0;

        if (isValid)
        {
            oper = 0x01<<remainder; 
            m_activeListValidState[quotient] = m_activeListValidState[quotient] | oper;
        }
        else
        {
            oper = ~(0x01<<remainder); 
            m_activeListValidState[quotient] = m_activeListValidState[quotient] & oper;
        }
    }
}

VfxBool VappMusicPlayerService::getSongValid(const VfxU32 index)
{
    VfxU32 quotient = index/(sizeof(VfxBool)*8);
    VfxU32 remainder = index%(sizeof(VfxBool)*8);

    if (m_activeListValidState)
    {  
        VfxU8 bValid = m_activeListValidState[quotient] & (0x01<<remainder);
        return (VfxBool)bValid;
    }

    return VFX_TRUE;
}

void VappMusicPlayerService::setSongLyricsState(const VfxU32 index, const VfxBool isValid)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_SET_SONG_LYRICS_VALID, m_activeListLyricsState, index, isValid, m_activeListValidStateCount);

    if (m_activeListLyricsState && (index < m_activeListValidStateCount))
    {
        VfxU32 quotient = index/(sizeof(VfxU8)*8);
        VfxU32 remainder = index%(sizeof(VfxU8)*8);
        VfxU8 oper = 0x0;

        if (isValid)
        {
            oper = 0x01<<remainder; 
            m_activeListLyricsState[quotient] = m_activeListLyricsState[quotient] | oper;
        }
        else
        {
            oper = ~(0x01<<remainder); 
            m_activeListLyricsState[quotient] = m_activeListLyricsState[quotient] & oper;
        } 
    }
}

VfxBool VappMusicPlayerService::getSongLyricsState(const VfxU32 index)
{
    VfxU32 quotient = index/(sizeof(VfxBool)*8);
    VfxU32 remainder = index%(sizeof(VfxBool)*8);

    if (m_activeListLyricsState)
    {  
        VfxU8 bValid = m_activeListLyricsState[quotient] & (0x01<<remainder);
        return (VfxBool)bValid;
    }

    return VFX_FALSE;
}

void VappMusicPlayerService::startFindNextTimer(void)
{
    // Use Plutommi timer for backlight on and off situation
    StopTimer(COSMOS_MUSICPLY_TIMER_FIND_NEXT);
    StartTimer(COSMOS_MUSICPLY_TIMER_FIND_NEXT, 100, VappMusicPlayerService::findNextTimerTimeout);
}

void VappMusicPlayerService::stopFindNextTimer(void)
{
    StopTimer(COSMOS_MUSICPLY_TIMER_FIND_NEXT);
}

VfxBool VappMusicPlayerService::isFindNextTimerEnabled(void)
{
    if(IsMyTimerExist(COSMOS_MUSICPLY_TIMER_FIND_NEXT))
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;
}

VfxBool VappMusicPlayerService::getIsFindNextTimerSuspended()
{
    return m_isFindNextTimerSuspended;
}

void VappMusicPlayerService::setIsFindNextTimerSuspended(VfxBool suspend)
{
    m_isFindNextTimerSuspended = suspend;
}

void VappMusicPlayerService::findNextTimerTimeout(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_FIND_NEXT_TIMER_TIMEOUT);

    VappMusicPlayerService *pThis = g_mplayerSrvPtr;

    if(pThis != NULL && pThis->isValid())
    {
        pThis->handlePostOnInvalidFile(NULL);
    }
}

void VappMusicPlayerService::startPlaybackErrTimer()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_START_PB_ERR_TIMER);

    if (m_playbackErrTimer)
    {
        m_playbackErrTimer->stop();
        m_playbackErrTimer->start();
    }
}

void VappMusicPlayerService::stopPlaybackErrTimer()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_STOP_PB_ERR_TIMER);

    if (m_playbackErrTimer)
    {
        m_playbackErrTimer->stop();
    }
}

VfxBool VappMusicPlayerService::getIsPlaybackErrTimerEnabled()
{
    return m_playbackErrTimer && m_playbackErrTimer->getIsEnabled();
}

void VappMusicPlayerService::onPlaybackErrTimerTick(VfxTimer *t)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_ON_PB_ERR_TIMER_TICK);

    VappMusicPlayerApp *app = getMusicPlayerApp();

    VappMusicPlayerPlayerBase *player = NULL;
    
    if (app)
    {
        VfxBool isCoverFlow = VFX_FALSE;
        player = app->getTopPlayer(isCoverFlow);
    }

    if (!app || (app && !player) || (app && player && player->onPlaybackErrTimerTimeout()))
    {
        onInvalidFile(VFX_FALSE);
    }
}

void VappMusicPlayerService::onPlaybackFail(VfxS32 result)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_ON_PLAYBACK_FAIL, result);

    onStop(VFX_FALSE);

    // set the error flag of this file, and skip this file on next playback
    const VfxU32 activeIdx = getActiveIndex();
    setSongValid(activeIdx, VFX_FALSE);

    if (!m_playAfterSwitchSong)
    {
        return;
    }

    m_ctrlPlayback->setPlayState(PB_STATE_PLAYBACK_FAIL);

    VappMusicPlayerApp *app = getMusicPlayerApp();
    if (!(app && app->onPlaybackFail(result)))
    {
        onInvalidFile(VFX_TRUE);
    }

    setSongLyricsState(activeIdx, VFX_FALSE);
}

void VappMusicPlayerService::onInvalidFile(VfxBool delayExecute)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_ON_INVALID_FILE, delayExecute);

    const VfxU32 count = getActiveCount();
    VfxBool hasValidSong = VFX_FALSE;

    // check for valid song in active playlist
    if (m_activeListValidState)
    {
        for(VfxU32 idx = 0; idx < count; idx++)
        {
            if (getSongValid(idx))
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_ON_INVALID_FILE_HAS_VALID_SONG, idx);
                hasValidSong = VFX_TRUE;
                break;
            }
        }
    }

    // if no valid song, stop the playback
    if (hasValidSong)
    {
        if (delayExecute)
        {
            VappMusicPlayerApp *app = getMusicPlayerApp();
            if (app && app->isListMenuPenDown())
            {
                // due to rapidly calling onNext would block UI, hold the onNext action while user is dragging list menu
                setIsFindNextTimerSuspended(VFX_TRUE);
            }
            else
            {
                // Use a timer to delay more time to call onNext, to avoid async signal infinite loop
                startFindNextTimer();

                m_ctrlPlayback->setPlayState(PB_STATE_SWITCHING_PLAY);

                m_ctrlPlayback->registerInterruptCallback();
            }
        }
        else
        {
            handlePostOnInvalidFile(NULL);
        }
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_ON_INVALID_FILE_NO_VALID_SONG);
        vfxPostInvoke1(this, &VappMusicPlayerService::onStop, VFX_FALSE);
    }
}

void VappMusicPlayerService::handlePostOnInvalidFile(VfxTimer *timer)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_HANDLE_POST_ON_INVALID_FILE);

    stopFindNextTimer();

    const VfxBool isRepeatOne = getRepeat() == SRV_PLST_REPEAT_ONE;
    const GetNextModeEnum nextMode = isRepeatOne ? NEXT : AUTO_NEXT;
    vfxPostInvoke2(this, &VappMusicPlayerService::onNext, nextMode, VFX_FALSE);
}

void VappMusicPlayerService::onMDICallback(VfxS32 result)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_ON_MDI_CALLBACK, result);

    switch (result)
    {
        // For playback
        case VAPP_MUSICPLY_PRE_END_OF_FILE:
            // not handle pre-EOF
            break;

        case MDI_AUDIO_END_OF_FILE:
            {
                VappMusicPlayerApp *app = getMusicPlayerApp();
                if (!app || (app && !(app->getActionMode() == ACTION_REFRESH && app->m_popupWaiting)))
                {
                    /* The event is sent by app in play request, delay play to avoid infinite loop for repeat 1 */
                    /* Always delay play in this case, some file need to parse lyrics (MAUI_03094183, MAUI_03104009)*/
                    onNext(AUTO_NEXT, VFX_TRUE);
                    return;
                }
            }
            break;

        case MDI_AUDIO_TERMINATED:
            onStop();
            break;

        // For duration
        case MDI_AUDIO_DUR_UPDATED:
            {
                VfxU32 curDuration = m_ctrlPlayback->getDuration()/1000; // Duration unit in DB is second

                if (m_activeDetailInfo.duration != curDuration)
                {
                    // update duration to PLSV DB
                    SongInfoStruct info;
                    getCurrInfo(info);
                    setDuration(info.id, curDuration);
                }
            }
            break;

        // For seek
        case AUD_SEEK_REASON_DONE:
            {
                if(!m_ctrlPlayback->seek(m_ctrlPlayback->m_seekTime))
                {
                    return;
                }

                // m_playStateBeforeSeek can be set before seeking or be set by resumeInterruptPlay() (interruptedInfo.state)
                PlaybackStateEnum state = m_ctrlPlayback->m_playStateBeforeSeek;

                // normal seeking should only handle PLAY state, the other states are from interrupted state
                if (state == PB_STATE_NONE  // this case is interrupedInfo.state cleared by clearInterruptState(TRUE, FALSE) in VappMusicPlayerApp::onPrevNext()
                 || state == PB_STATE_PLAY
                 || state == PB_STATE_SWITCHING_PLAY
                 || state == PB_STATE_SEEKING
                 || state == PB_STATE_BT_CONNECTING
                 || state == PB_STATE_BT_CONNECTING_WHILE_PLAYING
                 || state == PB_STATE_BT_CONNECTING_WHILE_RESUME
                 || (!m_ctrlPlayback->isSongPausable(NULL) && state == PB_STATE_STOP))
                {
                    VappMusicPlayerApp *app = getMusicPlayerApp();
                    if (!app || (app && !app->getCoverFlow() && !app->getNowPlaying()))
                    {
                        m_ctrlPlayback->play();
                        return;
                    }
                }
                else if (state == PB_STATE_PAUSE
                      || state == PB_STATE_STOP
                      || state == PB_STATE_INTERRUPTED
                      || state == PB_STATE_OPEN)
                {
                    m_ctrlPlayback->setPlayState(state);
                }
                else
                {
                    m_ctrlPlayback->stop();
                }
            }
            break;

        case AUD_SEEK_REASON_FAIL:
        case AUD_SEEK_REASON_TERMINATED:
            break;

        // For interrupt
        case VAPP_MUSICPLY_INTERRUPT_CB_INTERRUPT:
            stopDelayPlayTimer();            
            stopFindNextTimer();
            if (getIsPlaybackErrTimerEnabled())
            {
                stopPlaybackErrTimer();
            }
            
            break;

        case VAPP_MUSICPLY_INTERRUPT_CB_RESUME:
            if (getIsDelayPlayTimerEnable())
			{
				// go prev/next during seeking, cancel the seeking
				m_ctrlPlayback->seekStop();
			}

            break;

        // For playback error
        default:
            {
                if (result != MDI_AUDIO_BUSY)
                {
                    onPlaybackFail(result);
                    return;
                }
            }   
            break;
    };

    m_signalMDICallback.emit(result);
}


// AVRCP functions

#ifdef __MMI_AVRCP_SUPPORT__
U8 VappMusicPlayerService::onAVRCPCmdCallback(U8 command_type, srv_avrcp_key_events key_events)
{
    // TODO: service would provide user data.
    VappMusicPlayerService *pThis = g_mplayerSrvPtr;
    VFX_ASSERT(pThis);
    return pThis->onAVRCPCommand(command_type, key_events);
}

U8 VappMusicPlayerService::onAVRCPCommand(U8 command_type, srv_avrcp_key_events key_events)
{
    // only handle "down" events, don't handle long-press, repeat, and up
    if (key_events != SRV_AVRCP_KEY_DOWN)
    {
        return SRV_AVRCP_CR_ACCEPT;
    }

    VappMusicPlayerApp *app = getMusicPlayerApp();
    ActionEnum action = app ? app->getActionMode() : ACTION_NONE;
    VfxBool isAppTopActive = app && app->isGroupTopActive();
    PlaybackStateEnum playState = m_ctrlPlayback->getPlayState();
    VfxBool isBGPlayValid = m_ctrlPlayback->isBackgroundPlayValid();


    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_ON_AVRCP_COMMAND, command_type, app != NULL, action, isAppTopActive, playState, isBGPlayValid);

    U8 ret = 0;

    // reject all command while processing specific commands
    if (app)
    {
        if (action == ACTION_REFRESH
         || action == ACTION_RESET
         || action == ACTION_FATAL_ERROR)
        {
            return SRV_AVRCP_CR_REJECT;
        }
    }

    if (m_ctrlPlayback->getPlayState() == PB_STATE_NONE)
    {
        return SRV_AVRCP_CR_REJECT;
    }

    //MAUI_03217025
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    if (command_type == SRV_AVRCP_POP_PLAY
     || command_type == SRV_AVRCP_POP_PAUSE
     || command_type == SRV_AVRCP_POP_BACKWARD
     || command_type == SRV_AVRCP_POP_FORWARD
     || command_type == SRV_AVRCP_POP_STOP)
    {
        if (blockActionInCall())
        {
            return SRV_AVRCP_CR_REJECT;
        }
    }
    
    switch(command_type)
    {
        case SRV_AVRCP_POP_PLAY:
        case SRV_AVRCP_POP_PAUSE:
            // for BT AVRCP, we always treat play/pause as "toggle",
            // this is the behavior of Pluto MMI media player.

            m_playAfterSwitchSong = VFX_TRUE;

            if (!app || !app->AVRCPCommHandler(command_type))
            {
                if (!m_ctrlPlayback->isSongPausable(NULL))
                {
                    return SRV_AVRCP_CR_NOT_IMPLEMENT;
                }
                m_ctrlPlayback->playpause();
            }
            return SRV_AVRCP_CR_ACCEPT;

        case SRV_AVRCP_POP_BACKWARD:
            onPrev(VFX_TRUE);
            return SRV_AVRCP_CR_ACCEPT;

        case SRV_AVRCP_POP_FORWARD:
            onNext(NEXT, VFX_TRUE);
            return SRV_AVRCP_CR_ACCEPT;

        case SRV_AVRCP_POP_STOP:
            if (!app || !app->AVRCPCommHandler(command_type))
            {
                m_ctrlPlayback->stop();
            }
            return SRV_AVRCP_CR_ACCEPT;

        default:
            return SRV_AVRCP_CR_NOT_IMPLEMENT;
    }

    return SRV_AVRCP_CR_NOT_IMPLEMENT;
}
#endif /*__MMI_AVRCP_SUPPORT__*/

// Helper functions

VfxBool VappMusicPlayerService::isMakingCall()
{
    return srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0;
}

VfxBool VappMusicPlayerService::blockActionInCall(VfxBool showMessage)
{
    if (isMakingCall())
    {
        if (showMessage)
        {
            VappMusicPlayerApp *app = getMusicPlayerApp();

            if (app)
            {
                app->showBalloon(
                    MMI_NMGR_BALLOON_TYPE_WARNING, 
                    VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL)
                    );
            }
        }

        return VFX_TRUE;
    }

    return VFX_FALSE;
}

VfxBool VappMusicPlayerService::isUndeletableState()
{
    PlaybackStateEnum state = m_ctrlPlayback->getPlayState();
    VappMusicPlayerApp *app = getMusicPlayerApp();

    return state != PB_STATE_NONE
        && state != PB_STATE_CLOSE 
        && state != PB_STATE_PLAYBACK_FAIL
        && (!app || (app && app->getActionMode() != ACTION_REFRESH));
}

void VappMusicPlayerService::turnOnBackLight()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_TURN_ON_BACK_LIGHT);

    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
}

VfxBool VappMusicPlayerService::isBackLightOn()
{
    VfxBool ret = srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD) == MMI_TRUE;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SRV_IS_BACK_LIGHT_ON, ret);

    return ret;
}

#endif //__COSMOS_MUSICPLY__

