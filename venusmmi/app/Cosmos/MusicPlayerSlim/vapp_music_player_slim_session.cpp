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
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH´Ë
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
 *  vapp_music_player_slim_session.cpp
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/***************************************************************************** 
 * Include header file
 *****************************************************************************/
#include "mmi_features.h"
#ifdef __MMI_MUSIC_PLAYER_SLIM__

#include "vapp_vol_dialog_gprot.h"
#include "mmi_rp_vapp_vol_dialog_def.h"
#include "mmi_rp_srv_prof_def.h"
#include "vapp_screen_lock_gprot.h"
#include "mmi_rp_vapp_music_player_slim_def.h"
#include "vapp_music_player_slim_session.h"

extern "C"
{
#include "UcmSrvGprot.h"
#include "gpiosrvgprot.h"
#include "wgui_categories_util.h"

#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif
}


#define VAPP_MUSIC_PLAYER_SESSION_MEM_POOL_SIZE   10*1024

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
VappMusicPlayerSession* VappMusicPlayerSession::g_mSessionPtr = NULL;
static VfxU8 g_sessionMemPool[VAPP_MUSIC_PLAYER_SESSION_MEM_POOL_SIZE];

/***************************************************************************** 
 * VappMusicPlayerService Implementation
 *****************************************************************************/

//VFX_IMPLEMENT_CLASS("VappMusicPlayerSession", VappMusicPlayerSession, VfxObject);
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappMusicPlayerSession);


void VappMusicPlayerSession::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SESSION_ON_INIT);

    VFX_OBJ_CREATE(m_context, VfxContext, VFX_SYS_GLOBAL_CONTEXT);
    m_context->assignPool(g_sessionMemPool, VAPP_MUSIC_PLAYER_SESSION_MEM_POOL_SIZE);

    VfxObject::onInit();

    /* init this pointr. */
    g_mSessionPtr = this;
    memset(m_songValidState, 0xFF, SESSION_MAX_BITSET_SIZE*sizeof(VfxU8));

    VFX_OBJ_CREATE(m_ctrlPlaylist, VappMusicPlayerCtrlPlaylist, this);
    m_ctrlPlaylist->m_signalCtrlPlaylist.connect(this, &VappMusicPlayerSession::onPlaylistCallback);

    VFX_OBJ_CREATE(m_ctrlPlayback, VappMusicPlayerCtrlPlaybackSlim, this);
    m_ctrlPlayback->m_signalCtrlPlayback.connect(this, &VappMusicPlayerSession::onPlaybackCallback);

    m_signalInternalEvt.connect(this, &VappMusicPlayerSession::internalEvtHandler);

    VFX_OBJ_CREATE(m_delayPlayTimer, VfxTimer, this);
    m_delayPlayTimer->setStartDelay(SESSION_DELAY_PLAY_TIME);
    m_delayPlayTimer->m_signalTick.connect(this, &VappMusicPlayerSession::onDelayPlayTimerTick);

    VFX_OBJ_CREATE(m_delayNextTimer, VfxTimer, this);
    m_delayNextTimer->setStartDelay(SESSION_DELAY_NEXT_TIME);
    m_delayNextTimer->m_signalTick.connect(this, &VappMusicPlayerSession::onDelayNextTimerTick);

    VFX_OBJ_CREATE(m_openLibTimer, VfxTimer, this);
    m_openLibTimer->setStartDelay(SESSION_DELAY_OPEN_TIME);
    m_openLibTimer->m_signalTick.connect(this, &VappMusicPlayerSession::onOpenLibTimerTick);
    
    /* register events to handle in onProc. */
    mmi_frm_cb_reg_event(EVT_ID_SRV_PROF_IS_PLAYING, (mmi_proc_func)&VappMusicPlayerSession::onProcProfIsPlaying, this);
#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, (mmi_proc_func)&VappMusicPlayerSession::onProcUSBMsMode, this);
#endif

#if defined (__MMI_AVRCP_SUPPORT__)
    registerAVRCPcallbak();
#endif

    openLibrary(VFX_TRUE);
}

void VappMusicPlayerSession::onDeinit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SESSION_ON_DEINIT);

    /*notify ncener panel to close*/
    sendOpenCloseEvent(VFX_FALSE);
    hideStatusBarIcon();

    /* deregister events callback. */
    mmi_frm_cb_dereg_event(EVT_ID_SRV_PROF_IS_PLAYING,(mmi_proc_func)&VappMusicPlayerSession::onProcProfIsPlaying, this);
#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_dereg_event(EVT_ID_USB_ENTER_MS_MODE, (mmi_proc_func)&VappMusicPlayerSession::onProcUSBMsMode, this);
#endif

#if defined (__MMI_AVRCP_SUPPORT__)
    deregisterAVRCPcallback();
#endif

    m_delayPlayTimer->stop();
    m_delayNextTimer->stop();
    m_openLibTimer->stop();
    
    /* reset this pointer. */
    g_mSessionPtr = NULL;
    
    VfxObject::onDeinit();
}

void VappMusicPlayerSession::onObjectNotify(VfxId id, void *userData)
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

vrt_allocator_handle VappMusicPlayerSession::getAllocator()
{
    return m_context->getAllocator();
}

void VappMusicPlayerSession::destorySession()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SESSION_DESTORY);

    m_signalInternalEvt.postEmit(SESSION_EVT_DESTORY, 0);
}

// tell session if goto background
void VappMusicPlayerSession::setBackgroundPlay(VfxBool inBgPlay, PlaybackStateEnum &playState)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SESSION_ON_SET_BACKGROUND, inBgPlay);

    m_inBackground = inBgPlay;
    m_ctrlPlayback->setBackgroundPlay(inBgPlay);
    playState = m_ctrlPlayback->getPlaybackState();
    
    if (inBgPlay)
    {
        if ((PB_STATE_STOP == playState) && (!m_inSeriesPlay))
        {
            destorySession();
        }
    }
}

mmi_ret VappMusicPlayerSession::onProcProfIsPlaying(mmi_event_struct *param)
{
    VappMusicPlayerSession *pThis = NULL;
    PlaybackStateEnum playbackState = PB_STATE_NONE;

    pThis = reinterpret_cast<VappMusicPlayerSession*>(param->user_data);
    if (!pThis)
    {
        return MUSIC_RET_OK;
    }

    playbackState = pThis->m_ctrlPlayback->getPlaybackState();
    if (PB_STATE_PLAY == playbackState)
    {
        return (!MMI_RET_OK);
    }
    else
    {
        return MMI_RET_OK;
    }
}

mmi_ret VappMusicPlayerSession::onProcUSBMsMode(mmi_event_struct *param)
{
#ifdef __MMI_USB_SUPPORT__    
    VappMusicPlayerSession *pThis = reinterpret_cast<VappMusicPlayerSession*>(param->user_data);
    if (!pThis)
    {
        return MUSIC_RET_OK;
    }

    /* cancel current operation. */
    if (SESSION_ACT_OPEN == pThis->m_currOperation)
    {
    
    }
    else if (SESSION_ACT_ADD == pThis->m_currOperation)
    {
        pThis->addMusicCancel();
    }
    else if (SESSION_ACT_DELETE == pThis->m_currOperation)
    {
        pThis->delCancel();
    }

    if (pThis->m_inBackground)
    {
        /* in background, stop play and exit. */
        pThis->destorySession();
    }
    else
    {
        /* in foreground, notify ap. */
        pThis->notifyEvtListener(MUSIC_CB_USB_MS_MODE, MUSIC_RET_OK, 0);
    }
#endif  // __MMI_USB_SUPPORT__

    return MUSIC_RET_OK;
}

void VappMusicPlayerSession::notifyEvtListener(MusicPlayCBEvtEnum cb_event, S32 result, VfxU32 ca_para_2)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SESSION_NOTIFY_LISTENER, cb_event, result, ca_para_2);

    m_signalSessionEvt.emit(cb_event, result, ca_para_2);
}

void VappMusicPlayerSession::notifyEvtListenerAsync(MusicPlayCBEvtEnum cb_event, S32 result, VfxU32 ca_para_2)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SESSION_NOTIFY_LISTENER_ASYNC, cb_event, result, ca_para_2);

    m_signalSessionEvt.postEmit(cb_event, result, ca_para_2);
}

void VappMusicPlayerSession::internalEvtHandler(SessionEvtEnum cb_event, VfxU32 cb_para)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SESSION_INTERNAL_EVT, cb_event, cb_para);

    switch (cb_event)
    {
        /* error handling, close background play. */
        case SESSION_EVT_DESTORY:
        {
            VFX_OBJ_CLOSE_INSTANCE(VappMusicPlayerSession);
            break;
        }

        default:
            break;
    }
}

void VappMusicPlayerSession::onPlaylistCallback(MusicPlayCBEvtEnum cb_event, S32 result, VfxU32 ca_para_2)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SESSION_PLST_CB, cb_event, result, ca_para_2);

    switch (cb_event)
    {
        case MUSIC_CB_OPEN:
        {
            /* open library failed and AP in background, destory session. */
            if ((MUSIC_RET_OK != result) && (m_inBackground))
            {
                destorySession();
            }

            /* open done. */
            setActionMode(SESSION_ACT_NONE);
            break;
        }

        case MUSIC_CB_ADD:
        {
            /* add done. */
            memset(m_songValidState, 0xFF, SESSION_MAX_BITSET_SIZE*sizeof(VfxU8));
            setActionMode(SESSION_ACT_NONE);
            break;
        }

        case MUSIC_CB_DELETE:
        {
            memset(m_songValidState, 0xFF, SESSION_MAX_BITSET_SIZE*sizeof(VfxU8));
            setActionMode(SESSION_ACT_NONE);
            break;
        }

        case MUSIC_CB_MSDC_PLUG_OUT:
        {
        #ifndef __MMI_MUSIC_PLAYER_PHONE_DRIVE__
            /* if start timer to open library, stop it. */
            if (m_openLibTimer->getIsEnabled())
            {
                m_openLibTimer->stop();
            }
		#endif
            /* cancel current operation. */
            if (SESSION_ACT_DELETE == m_currOperation)
            {
                delCancel();
            }
            else if (SESSION_ACT_ADD == m_currOperation)
            {
                addMusicCancel();
            }
            else if (SESSION_ACT_SEEKING == m_currOperation)
            {
                 m_ctrlPlayback->seekStop();
            }

            hideStatusBarIcon();
            m_inSeriesPlay = VFX_FALSE;
            setActionMode(SESSION_ACT_NONE);
            m_ctrlPlayback->interruptEvtHandler(MUSIC_CB_MSDC_PLUG_OUT, 0);            
            m_ctrlPlaylist->setActiveItem(-1);
            break;
        }

        case MUSIC_CB_MSDC_PLUG_IN:
        {
            memset(m_songValidState, 0xFF, SESSION_MAX_BITSET_SIZE*sizeof(VfxU8));

#ifndef __MMI_MUSIC_PLAYER_PHONE_DRIVE__
            openLibrary(VFX_TRUE);
#endif  // __MMI_MUSIC_PLAYER_PHONE_DRIVE__
            break;
        }

        case MUSIC_CB_EVT_PRE_FORMAT:
        {
            if (m_inBackground)
            {
                destorySession();
            }
            break;
        }

        default:
            break;
    
    }

    notifyEvtListener(cb_event, result, ca_para_2);
}

void VappMusicPlayerSession::onOpenLibTimerTick(VfxTimer *timer)
{
    m_openLibTimer->stop();
    (void)openLibrary(VFX_FALSE);
}

VfxS32 VappMusicPlayerSession::openLibrary(VfxBool delayOpen)
{
    VfxS32 nRet = MUSIC_RET_OK;

    if (!m_ctrlPlaylist)
    {
        return MUSIC_RET_FAILED;
    }

    /* if timer on, stop it first. */
    m_openLibTimer->stop();
    
    if (delayOpen)
    {
        m_openLibTimer->start();
        return MUSIC_RET_OK;
    }

    nRet = m_ctrlPlaylist->openLibrary();
    if (MUSIC_RET_OK == nRet)
    {
        /* open success. */
        setActionMode(SESSION_ACT_NONE);
    }
    else if (MUSIC_RET_ASYNC == nRet)
    {
        /* async open library, will notify result from callback func. */
        setActionMode(SESSION_ACT_OPEN); 
    }
    else
    {
        setActionMode(SESSION_ACT_NONE);
    
        /* if open failed and in background, destory session. */
        if (m_inBackground)
        {
            destorySession();
        }
    }

    notifyEvtListener(MUSIC_CB_OPEN, nRet, 0);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SESSION_OPEN_LIBRARY, nRet);
    return nRet;
}

/* add music into library. */
VfxS32 VappMusicPlayerSession::addMusic(VfxWString fileName)
{
    VfxS32 nRet = MUSIC_RET_OK;
   
    if ((!m_ctrlPlaylist) || (!fileName))
    {
        return MUSIC_RET_FAILED;
    }

    /* sync operation, add one file into current playlist. */
    nRet = m_ctrlPlaylist->addFile(fileName);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SESSION_ADD_MUSIC, 0, nRet);
    return nRet;
}

/* search and add music into library. */
VfxS32 VappMusicPlayerSession::addMusicFromFolder(VfxWString folderName)
{
    VfxS32 nRet = MUSIC_RET_OK;
   
    if ((!m_ctrlPlaylist) || (!folderName))
    {
        return MUSIC_RET_FAILED;
    }

    /* async operation, search and add file from folder. */
    nRet = m_ctrlPlaylist->addFromFolder(folderName);
    if (MUSIC_RET_ASYNC == nRet)
    {
        /* async operation, waitting result. */
        setActionMode(SESSION_ACT_ADD);
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SESSION_ADD_FROMFOLDER, 0, nRet);
    return nRet;
}

/* stop current add file operation. */
VfxS32 VappMusicPlayerSession::addMusicCancel(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SESSION_ADD_CANCEL);

    VfxS32 nRet = MUSIC_RET_OK;
   
    /* check session action. */
    if (SESSION_ACT_ADD != m_currOperation)
    {
        return MUSIC_RET_OK;
    }

    nRet = m_ctrlPlaylist->addFileCancel();
    return nRet;
}

VfxS32 VappMusicPlayerSession::delMusic(VfxU32 index)
{
    VfxS32 nRet = m_ctrlPlaylist->delFile(index);
    if (MUSIC_RET_ASYNC == nRet)
    {
        setActionMode(SESSION_ACT_DELETE);
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SESSION_DEL_MUSIC, index, nRet);
    return nRet;
}

VfxS32 VappMusicPlayerSession::delSelectedMusic(void)
{
    VfxS32 nRet = MUSIC_RET_OK;

    nRet = m_ctrlPlaylist->delSelected();
    if (MUSIC_RET_ASYNC == nRet)
    {
        setActionMode(SESSION_ACT_DELETE);
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SESSION_DEL_SELECTED, nRet);
    return nRet;
}

void VappMusicPlayerSession::delCancel(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SESSION_DEL_CANCEL);

    if (!m_ctrlPlaylist)
    {
        return;
    }
    
    m_ctrlPlaylist->delCancel();
}

void VappMusicPlayerSession::delMultiSelectStart(void)
{
    if (!m_ctrlPlaylist)
    {
        return;
    }

    m_ctrlPlaylist->selectStart();
}

void VappMusicPlayerSession::delMultiSelectEnd(void)
{
    if (!m_ctrlPlaylist)
    {
        return;
    }

    m_ctrlPlaylist->selectEnd();
}

void VappMusicPlayerSession::delSelectAll(void)
{
    if (!m_ctrlPlaylist)
    {
        return;
    }

    m_ctrlPlaylist->selectAll();
}

void VappMusicPlayerSession::delDeselectAll(void)
{
    if (!m_ctrlPlaylist)
    {
        return;
    }

    m_ctrlPlaylist->deselectAll();
}

void VappMusicPlayerSession::delSelectItem(VfxU32 index)
{
    if (!m_ctrlPlaylist)
    {
        return;
    }

    m_ctrlPlaylist->select(index);
}

void VappMusicPlayerSession::delDeselectItem(VfxU32 index)
{
    if (!m_ctrlPlaylist)
    {
        return;
    }

    m_ctrlPlaylist->deselect(index);
}

VfxBool VappMusicPlayerSession::delIsSelectedItem(VfxU32 index)
{
    if (!m_ctrlPlaylist)
    {
        return VFX_FALSE;
    }

    return m_ctrlPlaylist->isSelected(index);
}

void VappMusicPlayerSession::onPlaybackCallback(MusicPlayCBEvtEnum cb_event, S32 result, VfxU32 ca_para_2)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SESSION_PLAYBACK_CB, cb_event, result, ca_para_2);

    VfxS32 index = -1;

    switch (cb_event)
    {
        case MUSIC_CB_PLAY:
        {
            if (MUSIC_RET_OK == result)
            {
                index = m_ctrlPlaylist->getActiveItemIndex();
                SetBitSet(index, m_songValidState);
                showStatusBarIcon();
            }
            else
            {
                /* play failed, auto switch to next song. */
                index = m_ctrlPlaylist->getActiveItemIndex();
                ClrBitSet(index, m_songValidState);
                autoNext(index, VFX_TRUE, SESSION_DELAY_NEXT_TIME);
            }
            
            break;
        }

        case MUSIC_CB_PAUSE:
        {
            hideStatusBarIcon();
            if (VFX_TRUE != result)
            {
                (void)stopPlay();
            }
            break;
        }

        case MUSIC_CB_RESUME:
        {
            showStatusBarIcon();
            break;
        }

        case MUSIC_CB_SEEKING:
        {
            setActionMode(SESSION_ACT_NONE);
            break;
        }

        case MUSIC_CB_INTERRUPT:
        {
            /* cancel current operation. */
            if (SESSION_ACT_DELETE == m_currOperation)
            {
                delCancel();
            }
            else if (SESSION_ACT_ADD == m_currOperation)
            {
                addMusicCancel();
            }
            
            stopDelayPlay();
            hideStatusBarIcon();
            setActionMode(SESSION_ACT_NONE);
            break;
        }

        case MUSIC_CB_INTERRUPT_RESUME:
        {
            if (MUSIC_SUB_RESUME_REQUEST == result)
            {
                resumeInterruptPlay();
            }
            
            break;
        }

        case MUSIC_CB_FILE_END:
        {
            /* prev song play end, auto switch to next. */
            VfxBool bBacklightOn = isBackLightOn();
            (void)autoNext(index, bBacklightOn, SESSION_DELAY_PLAY_TIME);
            break;
        }

        case MUSIC_CB_BT_CONNECT:
        {
            m_btConnecting = VFX_FALSE;
            if (MUSIC_SUB_BT_CONNECT_START == result)
            {
                m_btConnecting = VFX_TRUE;
            }
            break;
        }

        default:
            break;
    }

    notifyEvtListener(cb_event, result, ca_para_2);
}

void VappMusicPlayerSession::onDelayPlayTimerTick(VfxTimer *timer)
{
    m_delayPlayTimer->stop();
    m_switchingSong = VFX_FALSE;
    (void)playMusic(m_nextSongPath, VFX_FALSE);
}

void VappMusicPlayerSession::onDelayNextTimerTick(VfxTimer *timer)
{
    VfxS32 index = 0;

    m_delayNextTimer->stop();
    m_switchingSong = VFX_FALSE;
    (void)autoNext(index, VFX_FALSE, 0);
}

void VappMusicPlayerSession::stopDelayPlay()
{
    VfxBool bStarted = VFX_FALSE;

    bStarted = m_delayPlayTimer->getIsEnabled();
    if (bStarted)
    {
        m_delayPlayTimer->stop();
    }

    bStarted = m_delayNextTimer->getIsEnabled();
    if (bStarted)
    {
        m_delayNextTimer->stop();
    }
}

VfxS32 VappMusicPlayerSession::playMusic(const VfxWString &filePath, VfxBool delayStartPlay)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SESSION_PLAY_MUSIC);
    VfxS32 nRet = MUSIC_RET_OK;

    if (filePath.isEmpty())
    {
        return MUSIC_RET_FAILED;
    }

    /* if timer on, stop it first. */
    m_delayPlayTimer->stop();

    /* for delay start play. */
    if (delayStartPlay)
    {
        m_nextSongPath = filePath;
        m_switchingSong = VFX_TRUE;
        m_delayPlayTimer->start();
        return MUSIC_RET_OK;
    }

    nRet = m_ctrlPlayback->open(filePath);
    if (MUSIC_RET_OK != nRet)
    {
        /* invalid file open failed, notyfy view to show ballon. */
        onPlaybackCallback(MUSIC_CB_PLAY, MUSIC_RET_FAILED, 0);
    }
    else
    {
        /* start play,  result will be notify by callback func.*/
        nRet = m_ctrlPlayback->play();
    }

    return nRet;
}

/* 
* for switch song case, if currently play stoped,
* just open this file for get info, not need to terminate background play,
* so when start play, must open it again.
*/
VfxS32 VappMusicPlayerSession::switchMusic(VfxS32 &index, VfxBool bNext)
{
    PlaybackStateEnum prePlayState;
    VfxS32 nRet = MUSIC_RET_FAILED;
    VfxWString filePath;

    /* forbid to switch when seeking. */
    if (SESSION_ACT_SEEKING == m_currOperation)
    {
        return MUSIC_RET_FAILED;
    }

    /* forbid to switch when BT connecting. */
    if (m_btConnecting)
    {
        return MUSIC_RET_FAILED;
    }

    stopDelayPlay();

    if (bNext)
    {
        nRet = m_ctrlPlaylist->getNextActiveItemManul(index, filePath);
    }
    else
    {
        nRet = m_ctrlPlaylist->getPrevActiveItemManul(index, filePath);
    }
    
    if (MUSIC_RET_OK != nRet)
    {
        return nRet;
    }

    /* notify song switched, stop play and update current file info. */
    prePlayState = m_ctrlPlayback->getPlaybackState();
    m_ctrlPlayback->songSwitched(filePath);

    if ((PB_STATE_PLAY == prePlayState)
        || ((PB_STATE_STOP == prePlayState) && m_switchingSong))
    {
        VfxBool bBacklightOn = isBackLightOn();
        nRet = playMusic(filePath, bBacklightOn);
    }

    notifyEvtListener(MUSIC_CB_SONG_SWITCHED, MUSIC_RET_OK, index);
    return nRet;
}

VfxS32 VappMusicPlayerSession::startPlay(VfxU32 index)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SESSION_START_PLAY);

    VfxWString filePath = NULL;
    VfxS32 nRet = MUSIC_RET_OK;

    m_inSeriesPlay = VFX_TRUE;    
    stopDelayPlay();

    /* set index item as active to playlist service. */
    m_ctrlPlaylist->setActiveItem(index);

    /* get file path from playst service, according to index. */
    nRet = m_ctrlPlaylist->getFilePath(index, filePath);
    if (!nRet)
    {
        return MUSIC_RET_FAILED;
    }

    /* start play. */
    nRet = playMusic(filePath, VFX_FALSE);
    return nRet;
}

VfxS32 VappMusicPlayerSession::stopPlay()
{
    m_ctrlPlayback->stop();
    m_delayPlayTimer->stop();
    return MUSIC_RET_OK;
}

VfxS32 VappMusicPlayerSession::autoNext(VfxS32 &index, VfxBool delayNext, VfxU32 delayTime)
{
    VfxWString filePath = NULL;
    VfxS32 nRet = MUSIC_RET_OK;

    /* if timer on, stop it first. */
    m_delayNextTimer->stop();

    if (delayNext)
    {
        m_switchingSong = VFX_TRUE;
        m_delayNextTimer->setStartDelay(delayTime);
        m_delayNextTimer->start();
        return MUSIC_RET_OK;
    }

    /* get prev\next music index and file path. */
    nRet = m_ctrlPlaylist->getNextActiveItemAuto(index, filePath);
    if (MUSIC_RET_LIST_END == nRet)
    {
        /* song list play to end, switch to first and stop play. */
        m_inSeriesPlay = VFX_FALSE;
        hideStatusBarIcon();
        notifyEvtListener(MUSIC_CB_LIST_END, 0, 0);
        (void)switchNext(index);
        return nRet;
    }
    else if (MUSIC_RET_NEXT_LOOP == nRet)
    {
        /* current loop done, and auto switch to first. */
        VfxBool hasValidSong = isHasValidSong();
        if (!hasValidSong)
        {
            /* stop play if no valid songs. */
            m_inSeriesPlay = VFX_FALSE;
            hideStatusBarIcon();
            notifyEvtListener(MUSIC_CB_LIST_END, 0, 0);
            notifyEvtListener(MUSIC_CB_SONG_SWITCHED, MUSIC_RET_OK, index);
            return MUSIC_RET_OK;
        }
    }
    else if (MUSIC_RET_OK != nRet)
    {
        return nRet;
    }

    /* get next song success, check valid state. */
    if (IsBitSetOn(index, m_songValidState))
    {
        m_ctrlPlayback->songSwitched(filePath);
        notifyEvtListener(MUSIC_CB_SONG_SWITCHED, MUSIC_RET_OK, index);
        nRet = playMusic(filePath, VFX_FALSE);
    }
    else
    {
        /* skip invalid songs. */
        autoNext(index, VFX_TRUE, SESSION_ASYNC_TIME);
    }

    return nRet;
}

VfxS32 VappMusicPlayerSession::switchNext(VfxS32 &index)
{
    VfxS32 nRet = MUSIC_RET_FAILED;

    nRet = switchMusic(index, VFX_TRUE);
    return nRet;
}

VfxS32 VappMusicPlayerSession::switchPrev(VfxS32 &index)
{
    VfxS32 nRet = MUSIC_RET_FAILED;

    nRet = switchMusic(index, VFX_FALSE);
    return nRet;
}

VfxS32 VappMusicPlayerSession::resumeInterruptPlay()
{
    VfxWString filePath;
    VfxS32 index = 0;
    VfxS32 nRet = MUSIC_RET_OK;
    
    m_ctrlPlaylist->getActiveItemInfo(index, filePath);
    nRet = m_ctrlPlayback->resumeInterrupt(filePath);
    if ((MUSIC_RET_OK != nRet)
        && (MUSIC_RET_ASYNC != nRet))
    {
        onPlaybackCallback(MUSIC_CB_PLAY, MUSIC_RET_FAILED, 0);
    }

    return nRet;
}

VfxS32 VappMusicPlayerSession::pauseResumePlay()
{
    PlaybackStateEnum playbackState;
    VfxBool isInterrupted = VFX_FALSE;
    VfxS32 nRet = MUSIC_RET_OK;
    VfxWString filePath;
    VfxS32 index = 0;

    playbackState = m_ctrlPlayback->getPlaybackState();
    isInterrupted = m_ctrlPlayback->getInterruptState();
    
    MMI_TRACE(TRACE_GROUP_2, 
              TRC_VAPP_MUSICPLY_SESSION_PAUSE_RESUME, 
              playbackState,
              isInterrupted);

    if (PB_STATE_PLAY == playbackState)
    {
        /* whether can be pause defined by ctrl-playback, user should \
           handle the error code here, but the real result will be callback \
           from callback func, and notify APP to update UI .*/
        nRet = m_ctrlPlayback->pause();
    }
    else if (PB_STATE_PAUSE == playbackState)
    {
        nRet = m_ctrlPlayback->resume();
    }
    else if (PB_STATE_STOP == playbackState)
    {
        if (isInterrupted)
        {
            /* play terminated by interrupt, user resume play. */
            resumeInterruptPlay();
        }
        else if (m_switchingSong)
        {
            /* pause play when switching song, swith to next song and stop play. */
            m_switchingSong = VFX_FALSE;
            (void)switchNext(index);
            onPlaybackCallback(MUSIC_CB_PAUSE, VFX_TRUE, 0);
        }
        else
        {
            /* play stoped, resume play. for case switch song when pause. */
            m_ctrlPlaylist->getActiveItemInfo(index, filePath);
            nRet = playMusic(filePath, VFX_FALSE);
        }
    }
    else
    {
        nRet = MUSIC_RET_FAILED;
    }

    return nRet;
}

//send close event to ncenter to close panel
void VappMusicPlayerSession::sendOpenCloseEvent(VfxBool isOpen)
{
    VappMusicPlayerOpenCloseEvtStruct evt;
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_MUSICPLY_OPEN_CLOSE);
    evt.isOpen = isOpen;

    if(isOpen)
    {
        MMI_FRM_CB_EMIT_POST_EVENT(&evt);
    }
    else
    {
        MMI_FRM_CB_EMIT_EVENT(&evt);
    }
}


// show playing icon on status bar
void VappMusicPlayerSession::showStatusBarIcon()
{
    wgui_status_icon_bar_show_icon(STATUS_ICON_MEDPLY);
}

// hide playing icon on status bar, 
void VappMusicPlayerSession::hideStatusBarIcon()
{
    wgui_status_icon_bar_hide_icon(STATUS_ICON_MEDPLY);
}

// set session operation, forbid other modules to set
void VappMusicPlayerSession::setActionMode(SessionActionEnum action)
{
    m_currOperation = action;
}

SessionActionEnum VappMusicPlayerSession::getActionMode()
{
    return m_currOperation;
}

PlaybackStateEnum VappMusicPlayerSession::getPlayState()
{
    PlaybackStateEnum playState = PB_STATE_NONE;

    if (m_ctrlPlayback)
    {
        playState = m_ctrlPlayback->getPlaybackState();
    }
    
    return playState;
}

PlaybackStateEnum VappMusicPlayerSession::getPlayStateBeforeSeek()
{
    PlaybackStateEnum playState = PB_STATE_NONE;

    if (m_ctrlPlayback)
    {
        playState = m_ctrlPlayback->getPBStateBeforeSeek();
    }
    
    return playState;
}

VfxS32 VappMusicPlayerSession::getActiveIndex()
{
    /* check para. */
    if (!m_ctrlPlaylist)
    {
        return MUSIC_RET_ERR_BAD_PARA;
    }

    return m_ctrlPlaylist->getActiveItemIndex();
}

void VappMusicPlayerSession::setRepeat(srv_playlist_repeat_enum repeatState)
{
    /* check para. */
    if (!m_ctrlPlaylist)
    {
        return;
    }

    m_ctrlPlaylist->setRepeatMode(repeatState);
}

void VappMusicPlayerSession::setShuffle(srv_playlist_shuffle_enum shuffleState)
{
    /* check para. */
    if (!m_ctrlPlaylist)
    {
        return;
    }

    m_ctrlPlaylist->setShuffleMode(shuffleState);
}

srv_playlist_repeat_enum VappMusicPlayerSession::getRepeat()
{
    /* check para. */
    if (!m_ctrlPlaylist)
    {
        return SRV_PLAYLIST_REPEAT_OFF;
    }

    return m_ctrlPlaylist->getRepeatMode();
}

srv_playlist_shuffle_enum VappMusicPlayerSession::getShuffle()
{
    /* check para. */
    if (!m_ctrlPlaylist)
    {
        return SRV_PLAYLIST_SHUFFLE_OFF;
    }

    return m_ctrlPlaylist->getShuffleMode();
}

VfxS32 VappMusicPlayerSession::getTitle(const VfxU32 index, VfxWString &title)
{
    VfxS32 nRet = m_ctrlPlaylist->getTitle(index, title);
    return nRet;
}

VfxBool VappMusicPlayerSession::getPath(const VfxU32 index, VfxWString &path)
{
    VfxBool nRet = m_ctrlPlaylist->getFilePath(index, path);
    return nRet;
}

VfxU32 VappMusicPlayerSession::getCount()
{
    VfxU32 nRet = m_ctrlPlaylist->getCount();
    return nRet;
}

VfxU32 VappMusicPlayerSession::getDuration()
{
    VfxWString filePath;
    VfxS32 index = 0;
    VfxU32 duration = 0;

    m_ctrlPlaylist->getActiveItemInfo(index, filePath);
    duration = m_ctrlPlayback->getDuration(filePath);

    return duration;
}

VfxU32 VappMusicPlayerSession::getCurrTime()
{
    VfxU32 time = m_ctrlPlayback->getCurrTime();
    return time;
}

VfxS32 VappMusicPlayerSession::seekStart(VfxU32 time)
{
    VfxU32 nRet = m_ctrlPlayback->seekStart(time);
    if (MUSIC_RET_ASYNC == nRet)
    {
        setActionMode(SESSION_ACT_SEEKING);
    }
    
    return nRet;
}

/* check if current song pausable. */
VfxBool VappMusicPlayerSession::isSongPausable()
{
    VfxBool bPauseable = m_ctrlPlayback->isSongPausable();
    return bPauseable;
}

/* check if current song seekable. */
VfxBool VappMusicPlayerSession::isSongSeekable()
{
    VfxBool bSeekable = m_ctrlPlayback->isSongSeekable();
    return bSeekable;
}

VfxBool VappMusicPlayerSession::isHasValidSong()
{
    srv_playlist_repeat_enum repeatMode;
    VfxBool hasValidSong = VFX_FALSE;

    repeatMode = getRepeat();
    if (SRV_PLAYLIST_REPEAT_ONE == repeatMode)
    {
        VfxS32 index = getActiveIndex();
        hasValidSong = IsBitSetOn(index, m_songValidState); 
    }
    else
    {
        VfxU16 count = getCount();
        for (int i=0; i<count; i++)
        {
            hasValidSong = IsBitSetOn(i, m_songValidState); 
            if (hasValidSong)
            {
                break;
            }
        }
    }

    return hasValidSong;
}

VfxBool VappMusicPlayerSession::isMakingCall()
{
    VfxBool inCall = VFX_FALSE;
    VfxS32 callCount = 0;

    callCount = srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL);
    if (callCount > 0)
    {
        inCall = VFX_TRUE;
    }

    return inCall;
}

VfxBool VappMusicPlayerSession::isBackLightOn()
{
    VfxBool nRet = VFX_FALSE;
    MMI_BOOL isOn = MMI_FALSE;
    
    isOn = srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD);
    if (MMI_TRUE == isOn)
    {
        nRet = VFX_TRUE;
    }

    return nRet;
}

#if defined (__MMI_AVRCP_SUPPORT__)
void VappMusicPlayerSession::registerAVRCPcallbak()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SESSION_REGISTER_AVRCP);
    srv_avrcp_set_cmd_hdlr(onAVRCPCmdCallback);
}

void VappMusicPlayerSession::deregisterAVRCPcallback()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SESSION_DEREGISTER_AVRCP);
    srv_avrcp_clear_cmd_hdlr(onAVRCPCmdCallback);
}

U8 VappMusicPlayerSession::onAVRCPCmdCallback(U8 command_type, srv_avrcp_key_events key_events)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SESSION_ON_AVRCP_CALLBACK);
    VappMusicPlayerSession *pThis = NULL;
    VfxS32 index = 0;

    pThis = g_mSessionPtr;
    if (NULL == pThis)
    {
        return SRV_AVRCP_CR_ACCEPT;
    }

    if (pThis->m_btConnecting)
    {
        return SRV_AVRCP_CR_ACCEPT;
    }

    /* only handle "down" events, don't handle \
       long-press, repeat, and up. */
    if (SRV_AVRCP_KEY_DOWN != key_events)
    {
        return SRV_AVRCP_CR_ACCEPT;
    }

    /* block operation when making call. */
    if (pThis->isMakingCall())
    {
        return SRV_AVRCP_CR_REJECT;
    }

    switch(command_type)
    {
        case SRV_AVRCP_POP_PLAY:
        case SRV_AVRCP_POP_PAUSE:
        {
            (void)pThis->pauseResumePlay();
            return SRV_AVRCP_CR_ACCEPT;
        }

        case SRV_AVRCP_POP_STOP:
        {
            (void)pThis->stopPlay();
            (void)pThis->m_ctrlPlayback->close();
            pThis->hideStatusBarIcon();
            pThis->notifyEvtListener(MUSIC_CB_TERMINATE, 0, 0);
            return SRV_AVRCP_CR_ACCEPT;
        }

        case SRV_AVRCP_POP_BACKWARD:
        {
            /* switch song and told ap to update UI. */
            (void)pThis->switchPrev(index);
            return SRV_AVRCP_CR_ACCEPT;
        }

        case SRV_AVRCP_POP_FORWARD:
        {
            /* switch song and told ap to update UI. */
            (void)pThis->switchNext(index);
            return SRV_AVRCP_CR_ACCEPT;
        }

        default:
            break;
    }

    return SRV_AVRCP_CR_NOT_IMPLEMENT;
}

#endif  //__MMI_AVRCP_SUPPORT__

#ifdef __MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__
VfxU8 VappMusicPlayerSession::getEffectGroup(void)
{
    return m_ctrlPlayback->getEffectGroup();
}

VfxU8 VappMusicPlayerSession::getEffectIndex(void)
{
    return m_ctrlPlayback->getEffectIndex();
}

void VappMusicPlayerSession::setEffect(VfxU8 group, VfxU8 index)
{
    m_ctrlPlayback->setEffect(group, index);
}
#endif  //__MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__

#endif  // __MMI_COSMOS_MUSIC_PLAYER_SLIM__
