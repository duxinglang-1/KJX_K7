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
 *  vapp_music_player_slim_ctrlplaybackt.cpp
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

#include "vapp_bt_a2dp_gprot.h"
#include "vapp_music_player_slim_ctrlplayback.h"
#include "vfx_adp_device.h" // For touch feedback
#include "vapp_vol_dialog_gprot.h"
#include "mmi_rp_vapp_vol_dialog_def.h"
#include "mmi_rp_vapp_music_player_slim_def.h"

extern "C"
{
#include "mdi_include.h"
#include "A2DPSrvGProt.h"
#include "ProfilesSrvGprot.h"
#include "BTMMIA2DPScr.h"
#include "gpiosrvgprot.h"
#include "UcmSrvGprot.h"
#include "L1audio.h"
#include "..\..\..\..\plutommi\service\inc\SoundEffectSrvGProt.h"
}


#define MDI_CACHE_SIZE 2*1024

/***************************************************************************** 
 * VappMusicPlayerCtrlPlaybackSlim Implementation
 *****************************************************************************/
VfxU32 VappMusicPlayerCtrlPlaybackSlim::m_objReg[MAX_PLAYBACK_OBJECT] = {0};

VFX_IMPLEMENT_CLASS("VappMusicPlayerCtrlPlaybackSlim", VappMusicPlayerCtrlPlaybackSlim, VfxObject);

void VappMusicPlayerCtrlPlaybackSlim::onInit()
{
    VfxObject::onInit();

    setPlaybackState(PB_STATE_STOP);
    cleanInterruptInfo();
    cleanCurrFileInfo();
    cleanSeekInfo();

#if defined (__MMI_A2DP_SUPPORT__)
    openBTAud();
#endif

    saveObject();

    /* register events to handle in onProc. */
    mmi_frm_cb_reg_event(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, 
                         (mmi_proc_func)&VappMusicPlayerCtrlPlaybackSlim::onProcCheckVolType, 
                         this);
#ifdef __MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__
    enableSoundEffect(VFX_TRUE);
#endif  //__MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__
}

void VappMusicPlayerCtrlPlaybackSlim::onDeinit()
{
    stop();
    close();
    freeCache();

    deregisterInterruptCallback();
    deregisterBckgrounCallback();
    setPlaybackState(PB_STATE_NONE);

#if defined (__MMI_A2DP_SUPPORT__)
    closeBTAud();
#endif

    freeObject();
    VfxObject::onDeinit();

    /* deregister events callback. */
    mmi_frm_cb_dereg_event(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE,
                           (mmi_proc_func)&VappMusicPlayerCtrlPlaybackSlim::onProcCheckVolType, 
                           this);
}

void VappMusicPlayerCtrlPlaybackSlim::saveObject()
{
    /* create success, keep current object info. */
    for (int i=0; i<MAX_PLAYBACK_OBJECT; i++)
    {
        if (0 == m_objReg[i])
        {
            m_objReg[i] = (VfxU32)this;
            return;
        }
        else if (((VfxU32)this) == m_objReg[i])
        {
            return;
        }
    }

    /* reach the max count. */
    MMI_ASSERT(0);
}

void VappMusicPlayerCtrlPlaybackSlim::freeObject()
{
    for (int i=0; i<MAX_PLAYBACK_OBJECT; i++)
    {
        if (((VfxU32)this) == m_objReg[i])
        {
            m_objReg[i] = 0;
            return;
        }
    }
}

void VappMusicPlayerCtrlPlaybackSlim::setPlaybackState(PlaybackStateEnum state)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_PLAYBACK_SET_PLAYSTATE, state);
    
    m_playbackState = state;
}

void VappMusicPlayerCtrlPlaybackSlim::setBackgroundPlay(VfxBool gotoBg)
{
    m_inBackground = gotoBg;
}

PlaybackStateEnum VappMusicPlayerCtrlPlaybackSlim::getPlaybackState()
{
    return m_playbackState;
}

PlaybackStateEnum VappMusicPlayerCtrlPlaybackSlim::getPBStateBeforeSeek()
{
    if (PB_STATE_SEEKING != m_playbackState)
    {
        return PB_STATE_NONE;
    }

    return m_seekingInfo.state;
}

VfxBool VappMusicPlayerCtrlPlaybackSlim::getInterruptState()
{
    return m_interruptInfo.isInterrupted;
}

void VappMusicPlayerCtrlPlaybackSlim::notifyEvtListener(MusicPlayCBEvtEnum cb_event, S32 result, VfxU32 ca_para_2)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_PLAYBACK_NOTIFY_LISTENER, cb_event, result, ca_para_2);

    m_signalCtrlPlayback.emit(cb_event, result, ca_para_2);
}

/* initialize cache table. */
void VappMusicPlayerCtrlPlaybackSlim::setCache(const VfxWString filePath)
{
    if (filePath != m_cacheFilePath)
    {
        freeCache();
        VFX_ALLOC_MEM(m_cacheTable, MDI_CACHE_SIZE, this);
        memset(m_cacheTable, 0, MDI_CACHE_SIZE);
    }

    if (m_mdiHandle)
    {
        mdi_audio_mma_set_cache_table(m_mdiHandle, m_cacheTable);
        m_cacheFilePath = filePath;
    }
}

/* free cache table. */
void VappMusicPlayerCtrlPlaybackSlim::freeCache()
{
    if (NULL == m_cacheTable)
    {
        return;
    }

    VFX_FREE_MEM(m_cacheTable);
    m_cacheTable = NULL;
    m_cacheFilePath.setEmpty();
}

mmi_ret VappMusicPlayerCtrlPlaybackSlim::onProcCheckVolType(mmi_event_struct *param)
{
    vapp_vol_dialog_evt_struct *volEvent = NULL;
    VappMusicPlayerCtrlPlaybackSlim *pThis = NULL;

    pThis = reinterpret_cast<VappMusicPlayerCtrlPlaybackSlim*>(param->user_data);
    if (!pThis)
    {
        return MMI_RET_OK;
    }

    MMI_TRACE(TRACE_GROUP_2, 
              TRC_VAPP_MUSICPLY_PLAYBACK_CHECK_VOLUME, 
              pThis->m_playbackState, 
              pThis->m_inBackground);

    volEvent = (vapp_vol_dialog_evt_struct*)param;
    if (VAPP_VOL_DIALOG_IS_MEDIA != volEvent->type)
    {
        /* only handle MEDIA TYPE. */
        return MMI_RET_OK;
    }

    /* adjust valume, when playing or forground. */
    if ((PB_STATE_PLAY == pThis->m_playbackState)
         || (!pThis->m_inBackground))
    {
        return (!MMI_RET_OK);
    }

    return MMI_RET_OK;
}

/* handle MDI callback. */
void VappMusicPlayerCtrlPlaybackSlim::onMDICallback(kal_int32 handle, kal_int32 result, void* user_data)
{
    VappMusicPlayerCtrlPlaybackSlim *pThis = reinterpret_cast<VappMusicPlayerCtrlPlaybackSlim*>(user_data);
    MusicPlayCBEvtEnum cbEvent = MUSIC_CB_MAX;
    S32 nRet = MUSIC_RET_OK;

    if ((!pThis) || (handle != pThis->m_mdiHandle))
    {
        return;
    }

    MMI_TRACE(TRACE_GROUP_2, 
              TRC_VAPP_MUSICPLY_PLAYBACK_MDI_CB, 
              result, 
              pThis->m_playbackState);
    
    switch (result)
    {
        case MDI_AUDIO_END_OF_FILE:
        {
            pThis->stop();
            pThis->close();
            cbEvent = MUSIC_CB_FILE_END;
            break;
        }

        case MDI_AUDIO_DUR_UPDATED:
        {
            pThis->updateAudDuration(VFX_TRUE);
            cbEvent = MUSIC_CB_DUR_UPDATED;
            break;
        }
        
        default:
        {
            if (MDI_AUDIO_BUSY != result)
            {
                pThis->setPlaybackState(PB_STATE_STOP);
                pThis->close();
                cbEvent = MUSIC_CB_PLAY;
                nRet = MUSIC_RET_FAILED;
            }
            
            break;
        } 
    }

    pThis->notifyEvtListener(cbEvent, nRet, 0);
}

/* handle MDI background interrupt callback. */
void VappMusicPlayerCtrlPlaybackSlim::onMDIInterruptCallback(mdi_result result, void *user_data)
{
    VappMusicPlayerCtrlPlaybackSlim* pThis = NULL;

    pThis = (VappMusicPlayerCtrlPlaybackSlim*)handleToObject((VfxObjHandle)user_data);
    if (!pThis)
    {
        return;
    }

    MMI_TRACE(TRACE_GROUP_2, 
              TRC_VAPP_MUSICPLY_PLAYBACK_INTERRUPT_CB, 
              result, 
              pThis->m_playbackState);

    if (MDI_AUDIO_TERMINATED == result)
    {
        PlaybackStateEnum state = pThis->getPlaybackState();

        /* only handle one time. */
        if (pThis->m_interruptInfo.isInterrupted)
        {
            return;
        }

        /* save play back info first. */
        pThis->m_interruptInfo.state = state;
        pThis->m_interruptInfo.interruptFile = pThis->m_currFileInfo.m_currFilePath;
        pThis->m_interruptInfo.interruptedDuration = pThis->getCurrTime();
        pThis->m_interruptInfo.totalDuration = pThis->m_currFileInfo.m_duration;
        pThis->m_interruptInfo.isInterrupted = VFX_TRUE;

        /* if in seeking, will seek to seeking time when resume. */
        if (PB_STATE_SEEKING == state)
        {
            pThis->m_interruptInfo.state = pThis->m_seekingInfo.state;
            pThis->m_interruptInfo.interruptedDuration = pThis->m_seekingInfo.seekTime;
            pThis->seekStop();
        }

        /* notify user, and close file. */
        pThis->stop();
        pThis->close();

        /* clear interrupt callback, and register background callback. */
        pThis->registerBckgrounCallback();
        pThis->notifyEvtListener(MUSIC_CB_INTERRUPT, 0, 0);
    }
}

/* handle MDI background resuem callback. */
VfxBool VappMusicPlayerCtrlPlaybackSlim::onMDIBackgroundCallback(mdi_result result, void *user_data)
{
    VappMusicPlayerCtrlPlaybackSlim* pThis = NULL;

    pThis = (VappMusicPlayerCtrlPlaybackSlim*)handleToObject((VfxObjHandle)user_data);
    if (!pThis)
    {
        return VFX_TRUE;
    }

    MMI_TRACE(TRACE_GROUP_2, 
              TRC_VAPP_MUSICPLY_PLAYBACK_BACKGROUND_CB, 
              result, 
              pThis->m_playbackState);

    if (MDI_AUDIO_RESUME == result)
    {
        PlaybackStateEnum state = pThis->getPlaybackState();

        /* only handle one time. */
        if (!pThis->m_interruptInfo.isInterrupted)
        {
            return VFX_TRUE;
        }

        /* auto start play if before state is playing, \
           will clear background callback, and register interrupt callback\ 
           when resume interrupt play in open(). */
        if (PB_STATE_PLAY == pThis->m_interruptInfo.state)
        {
            pThis->resumeInterrupt(pThis->m_interruptInfo.interruptFile);
            pThis->notifyEvtListener(MUSIC_CB_INTERRUPT_RESUME, MUSIC_SUB_RESUME_AUTO, 0);
        }
        else if (PB_STATE_STOP == pThis->m_interruptInfo.state)
        {
            pThis->notifyEvtListener(MUSIC_CB_INTERRUPT_RESUME, MUSIC_SUB_RESUME_REQUEST, 0);
        }
    }

    return VFX_TRUE;
}

void VappMusicPlayerCtrlPlaybackSlim::interruptEvtHandler(MusicPlayCBEvtEnum evt, VfxS32 para)
{
    switch (evt)
    {
        /* memory card plug out, cancel current operation. */
        case MUSIC_CB_MSDC_PLUG_OUT:
        {
            if (PB_STATE_SEEKING == m_playbackState)
            {
                seekStop();
                stop();
                
            }
            else if ((PB_STATE_PLAY == m_playbackState)
                     || (PB_STATE_PAUSE == m_playbackState))
            {
                stop();
            }
            
            close();
            cleanCurrFileInfo();
            cleanInterruptInfo();
            break;
        }

        case MUSIC_CB_MSDC_PLUG_IN:
        {
            break;
        }

        default:
            break;
    }
}

void VappMusicPlayerCtrlPlaybackSlim::close()
{
    /* file have been closed, \
       not open or be interrupted. */
    if(!m_mdiHandle)
    {
        return;
    }

    /* when close file, must be stop first. */
    if (PB_STATE_STOP != m_playbackState)
    {
        return;
    }

    /* clear interrupt callback handler, opened when open. */
    //mdi_audio_clear_interrupt_callback();
    mdi_audio_mma_close(m_mdiHandle);
    m_mdiHandle = 0;

    /* clean current file info. */
    //cleanCurrFileInfo();
}

void VappMusicPlayerCtrlPlaybackSlim::stop()
{
    /* file have been closed, \
       not open or be interrupted. */
    if(!m_mdiHandle)
    {
        return;
    }

    if (PB_STATE_STOP == m_playbackState)
    {
        return;
    }
    else if (PB_STATE_SEEKING == m_playbackState)
    {
        seekStop();
    }

    mdi_audio_mma_stop(m_mdiHandle);
    vfx_adp_touch_fb_enable_tone();  /* Enable touch feedback when music stop play. */
    turnOnSoundEffect(VFX_FALSE);

#if defined(__MMI_A2DP_SUPPORT__)
    closeA2DP();
#endif

    setPlaybackState(PB_STATE_STOP);
    notifyEvtListener(MUSIC_CB_STOP, 0, 0);
}
  
/* playback APIs. */
VfxS32 VappMusicPlayerCtrlPlaybackSlim::open(const VfxWString &filePath)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_PLAYBACK_OPEN, m_playbackState);

    if (filePath.isEmpty())
    {
        return MUSIC_RET_ERR_BAD_PARA;
    }

    /* close current open file first. */
    if (m_mdiHandle)
    {
        stop();
        close();
    }

    /* deregister interrupt callback before terminate and open, \
       to avoid terminate self. */
    deregisterInterruptCallback();

    /* terminate background play must before open, \
       MDI will clean the handle info when terminate background play. */  
    mdi_audio_terminate_background_play();

    /* open file. */
    VfxWChar *fullPath = const_cast<VfxWChar*>(filePath.getBuf());
    mdi_handle handle = 0;

    mdi_mma_open_struct openStruct;
    openStruct.app_id = 0; /* App ID. This is required for RM playback. Don't care for other formats */
    openStruct.file_name = fullPath;
    openStruct.data = NULL;
    openStruct.data_len = 0;
    openStruct.mdi_format = 0;
    openStruct.repeats = 1;
    openStruct.is_pdl = MMI_FALSE;
    openStruct.callback = &VappMusicPlayerCtrlPlaybackSlim::onMDICallback;
    openStruct.user_data = this;
    openStruct.handle_p = &handle;
    openStruct.output_path = MDI_DEVICE_SPEAKER2;
    
    mdi_result result = mdi_audio_mma_open(&openStruct);

    /* register interrupt callback must after open, \
       MDI will clean the interrupt callback when open. */
    registerInterruptCallback();

    /* file open failed, invalid song. */
    if (0 == *openStruct.handle_p)
    {
        return MUSIC_RET_FAILED;
    }

    m_mdiHandle = *(openStruct.handle_p);
    getAudioInfo(filePath);
    updateAudDuration(VFX_FALSE);
    setCache(filePath);

    return MUSIC_RET_OK;
}

VfxS32 VappMusicPlayerCtrlPlaybackSlim::play()
{
    VfxBool inCall = VFX_FALSE;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_PLAYBACK_PLAY, m_seekingInfo.isNeedSeek);

    /* if making call, not allowed to start play. */
    inCall = isMakingCall();
    if (inCall)
    {
        return MUSIC_RET_FAILED;
    }

    /* check if file has be opened. */
    if (!m_mdiHandle)
    {
        return MUSIC_RET_ERR_BAD_STATE;
    }

    /* if current file need seeking, start seeking */
    if (m_seekingInfo.isNeedSeek 
        && (m_seekingInfo.seekFile == m_currFileInfo.m_currFilePath))
    {
        /* set state as PLAY, will auto start play when seeking done. */
        (void)seekStart(m_seekingInfo.seekTime);
        m_seekingInfo.state = PB_STATE_PLAY;
    }
    else
    {
    #if defined (__MMI_A2DP_SUPPORT__)
        if (vapp_a2dp_is_output_to_bt())
        {
            /* If output to BT device, initialize the BT connection then \
               do the play action in onA2DPOpenCallback. */
            openA2DP();
        }
        else
    #endif //__MMI_A2DP_SUPPORT__
        {
            doPlay();
        }
    }
    
    /* if play interrupted, clear interrupt state. */
    if (m_interruptInfo.isInterrupted)
    {
        cleanInterruptInfo();
    }
    
    return MUSIC_RET_OK;
}

void VappMusicPlayerCtrlPlaybackSlim::doPlay()
{
#ifdef __DRM_SUPPORT__
    if (!m_consumeDRM)
    {
        /* disable the DRM count consuming (consume in play request). */
        mdi_audio_drm_disable_consume_count();
        m_consumeDRM = VFX_TRUE;
    }
#endif

    /* call this API to output sound to correct speaker. */
    mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2);
    mdi_audio_set_volume(MDI_VOLUME_MEDIA, srv_prof_get_media_vol());
    turnOnSoundEffect(VFX_TRUE);
    
    mdi_result result = mdi_audio_mma_play(m_mdiHandle);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_PLAYBACK_DOPLAY, result);
    if (MDI_AUDIO_END_OF_FILE == result)
    {
        /* notify file play done event. */
        stop();
        close();
        notifyEvtListener(MUSIC_CB_FILE_END, 0, 0);
    }
    else if (MDI_AUDIO_SUCCESS == result)
    {
        vfx_adp_touch_fb_disable_tone();
        
        /* notify file play success event. */
        setPlaybackState(PB_STATE_PLAY);
        notifyEvtListener(MUSIC_CB_PLAY, MUSIC_RET_OK, 0);
    }
    else
    {
        /* notify file play failed event. */
        setPlaybackState(PB_STATE_STOP);
        close();
        notifyEvtListener(MUSIC_CB_PLAY, MUSIC_RET_FAILED, 0);
    }

    return;
}
    
VfxS32 VappMusicPlayerCtrlPlaybackSlim::pause()
{
    mdi_result result = 0;

    if(!m_mdiHandle)
    {
        return MUSIC_RET_ERR_BAD_STATE;
    }
    
    /* only in playing state can be paused. */
    if (PB_STATE_PLAY != m_playbackState)
    {
        return MUSIC_RET_ERR_BAD_STATE;
    }

    /* check if song is pauseable. */
    if (VFX_FALSE == m_currFileInfo.m_isSongPausable)
    {
        notifyEvtListener(MUSIC_CB_PAUSE, VFX_FALSE, 0);
        return MUSIC_RET_FAILED;
    }

    result = mdi_audio_mma_pause(m_mdiHandle);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_PLAYBACK_PAUSE, result);
    if (MDI_AUDIO_SUCCESS == result)
    {
        setPlaybackState(PB_STATE_PAUSE);
        notifyEvtListener(MUSIC_CB_PAUSE, VFX_TRUE, 0);
    }
    else
    {
        /* notify file play failed event. */
        notifyEvtListener(MUSIC_CB_PAUSE, VFX_FALSE, 0);
        return MUSIC_RET_FAILED;
    }

    // Enable touch feedback when music stop play
    vfx_adp_touch_fb_enable_tone();
    turnOnSoundEffect(VFX_FALSE);

#if defined(__MMI_A2DP_SUPPORT__)
    closeA2DP();
#endif

    return MUSIC_RET_OK;
}
    
VfxS32 VappMusicPlayerCtrlPlaybackSlim::resume()
{
    if (!m_mdiHandle)
    {
        return MUSIC_RET_ERR_BAD_STATE;
    }

    /* only can be resume in pause state. */
    if (PB_STATE_PAUSE != m_playbackState)
    {
        return MUSIC_RET_ERR_BAD_STATE;
    }

#if defined(__MMI_A2DP_SUPPORT__)
    if (vapp_a2dp_is_output_to_bt())
    {
        /* If output to BT device, initialize the BT connection \
           then do the play action in onA2DPOpenCallback. */
        openA2DP();
    }
    else
#endif  //__MMI_A2DP_SUPPORT__
    {
        // If not output to BT, do the resume action
        doResume();
    }

    return MUSIC_RET_OK;
}

void VappMusicPlayerCtrlPlaybackSlim::doResume()
{
   mdi_result result = 0;

    /* call this API to output sound to correct speaker. */
    mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2);
    mdi_audio_set_volume(MDI_VOLUME_MEDIA, srv_prof_get_media_vol());
    turnOnSoundEffect(VFX_TRUE);

    result = mdi_audio_mma_resume(m_mdiHandle);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_PLAYBACK_RESUME, result);
    if (MDI_AUDIO_END_OF_FILE == result)
    {
        /* notify file play done event. */
        stop();
        close();
        notifyEvtListener(MUSIC_CB_FILE_END, 0, 0);
    }
    else if (MDI_AUDIO_SUCCESS == result)
    {
        vfx_adp_touch_fb_disable_tone();
        
        /* notify file play success event. */
        notifyEvtListener(MUSIC_CB_RESUME, VFX_TRUE, 0);
        setPlaybackState(PB_STATE_PLAY);
    }
    else
    {
        /* notify file play failed event. */
        notifyEvtListener(MUSIC_CB_RESUME, VFX_FALSE, 0);
        stop();
        close();
    }
}

/*
  user should provide the file name,
  this name can dynamicly get from playlist service.
*/
VfxS32 VappMusicPlayerCtrlPlaybackSlim::resumeInterrupt(const VfxWString &filePath)
{
    VfxS32 result = MUSIC_RET_OK;

    MMI_TRACE(TRACE_GROUP_2, 
              TRC_VAPP_MUSICPLY_PLAYBACK_RESUME_INTERRUPT, 
              m_interruptInfo.isInterrupted);

    /* check input para. */
    if (filePath.isEmpty())
    {
        return MUSIC_RET_ERR_BAD_PARA;
    }

    if (!m_interruptInfo.isInterrupted)
    {
        return MUSIC_RET_FAILED;
    }

    m_interruptInfo.isInterrupted = VFX_FALSE;
    
    /* the file be closed when interrupted . */
    result = open(filePath);
    if (MUSIC_RET_OK == result)
    {
        /* set state as PLAY, will auto start play when seeking done. */
        result = seekStart(m_interruptInfo.interruptedDuration);
        m_seekingInfo.state = PB_STATE_PLAY;
    }

    /* if playing the same file because of interrupt, disable the 
       DRM count consuming (consume in play request). */
    if (m_interruptInfo.interruptFile == filePath)
    {
        m_consumeDRM = VFX_FALSE;
    }

    return result;
}

/* This function is to set play start time. */
VfxS32 VappMusicPlayerCtrlPlaybackSlim::setStartTime(VfxU32 time)
{
    mdi_result result = MUSIC_RET_OK;
    VfxU32 newTime = 0;

    /* file be closed. */
    if (!m_mdiHandle)
    {
        return MUSIC_RET_FAILED;
    }

    /* max play start time is current seeking time, \
       or from begaining to play. */
    if (time > m_seekingInfo.seekTime)
    {
        return MUSIC_RET_FAILED;
    }

    newTime = vfxMin(time, m_currFileInfo.m_duration);
    result = mdi_audio_mma_set_start_time(m_mdiHandle, newTime);
    if (MDI_AUDIO_END_OF_FILE == result)
    {
        /* Seek fail for MPL files (ie. RA, M4A...). */
        result = MUSIC_RET_FAILED;
    }
    else if (MDI_AUDIO_SUCCESS != result)
    {
        result = MUSIC_RET_FAILED;
    }

    return result;
}

/* async seek. */
VfxS32 VappMusicPlayerCtrlPlaybackSlim::seekStart(VfxU32 time)
{
    VfxU32 newTime = time;
    
    MMI_TRACE(TRACE_GROUP_2, 
              TRC_VAPP_MUSICPLY_PLAYBACK_SEEK_START, 
              m_mdiHandle, 
              m_playbackState, 
              m_interruptInfo.isInterrupted);

    newTime = vfxMin(time, m_currFileInfo.m_duration);

    /* if interrupted not start seeking imediately, \
       will start seeking when resume interrupt play. */
    if (m_interruptInfo.isInterrupted)
    {
        newTime = vfxMin(time, m_interruptInfo.totalDuration);
        m_interruptInfo.interruptedDuration = newTime;
        return MUSIC_RET_OK;
    }

    /* if current file closed, not start seeking imediately, \
       will start seeking when play. */
    if (!m_mdiHandle)
    {
        m_seekingInfo.isNeedSeek = VFX_TRUE;
        m_seekingInfo.seekFile = m_currFileInfo.m_currFilePath;
        m_seekingInfo.seekTime = newTime;
        m_seekingInfo.state = m_playbackState;
        return MUSIC_RET_OK;
    }

    /* not allow to seeking when in seeking state, \
       or stop current seeking first. */
    if (PB_STATE_SEEKING == m_playbackState)
    {
        return MUSIC_RET_OK;
    }
    else if (PB_STATE_PLAY == m_playbackState)
    {
        /* if in playing state, must stop playing first, \
           else MDI will block start seek. */
        mdi_audio_mma_stop(m_mdiHandle);
    }

    /* save playback info before seeking. */
    m_seekingInfo.isNeedSeek = VFX_FALSE;
    m_seekingInfo.seekFile = m_currFileInfo.m_currFilePath;
    m_seekingInfo.state = m_playbackState;
    m_seekingInfo.seekTime = newTime;
            
    mdi_audio_start_seek(
        reinterpret_cast<void*>(const_cast<VfxWChar*>(m_currFileInfo.m_currFilePath.getBuf())), 
        m_cacheTable, 
        MDI_CACHE_SIZE, 
        newTime, 
        &VappMusicPlayerCtrlPlaybackSlim::onSeekCallback, 
        (void*)this
        );

    /* notify seeking start event, let ap waitting. */
    notifyEvtListener(MUSIC_CB_SEEKING, MUSIC_SUB_SEEKING_START, 0);
    setPlaybackState(PB_STATE_SEEKING);
    return MUSIC_RET_ASYNC;
}

/*
* cancel or pause seeking 
* VFX_TRUE, keep current seek info, need to restart seek before start play
* VFX_FALSE, cancel seeking
*/
void VappMusicPlayerCtrlPlaybackSlim::seekStop(VfxBool pauseSeek)
{
    if (PB_STATE_SEEKING != m_playbackState)
    {
        return;
    }

    if (!m_mdiHandle)
    {
        return;
    }

    m_seekingInfo.isNeedSeek = pauseSeek;
    mdi_audio_stop_seek();

    /* set playback state as STOP, because start seek will terminate play. */
    notifyEvtListener(MUSIC_CB_SEEKING, MUSIC_SUB_SEEKING_DONE, 0);
    setPlaybackState(PB_STATE_STOP);
}

/* handle seek callback. */
void VappMusicPlayerCtrlPlaybackSlim::onSeekCallback(kal_uint8 reason, void* user_data)
{
    VappMusicPlayerCtrlPlaybackSlim *pThis = NULL;

    pThis = reinterpret_cast<VappMusicPlayerCtrlPlaybackSlim*>(user_data);
    if (!pThis)
    {
        return;
    }

    MMI_TRACE(TRACE_GROUP_2, 
              TRC_VAPP_MUSICPLY_PLAYBACK_SEEK_CB, 
              reason, 
              pThis->m_seekingInfo.state);

    pThis->notifyEvtListener(MUSIC_CB_SEEKING, MUSIC_SUB_SEEKING_DONE, 0);

    switch (reason)
    {
        /* seeking success. */
        case AUD_SEEK_REASON_DONE:
        {
            /* set play start time to seeking time. */
            (void)pThis->setStartTime(pThis->m_seekingInfo.seekTime);
            if (PB_STATE_PLAY == pThis->m_seekingInfo.state)
            {
                pThis->setPlaybackState(PB_STATE_STOP);
                pThis->play();
            }
            else
            {
                pThis->setPlaybackState(pThis->m_seekingInfo.state);
            }
            break;
        }

        case AUD_SEEK_REASON_FAIL:
        {
            if (PB_STATE_PLAY == pThis->m_seekingInfo.state)
            {
                pThis->setPlaybackState(PB_STATE_STOP);
                pThis->play();
            }
            else
            {
                pThis->setPlaybackState(pThis->m_seekingInfo.state);
            }
            break;
        }

        case AUD_SEEK_REASON_TERMINATED:
        {
            break;
        }

        default:
            break;
    }

    pThis->cleanSeekInfo();
}

/* check if current song pausable. */
VfxBool VappMusicPlayerCtrlPlaybackSlim::isSongPausable()
{
    VfxWChar *fullPath = const_cast<VfxWChar*>(m_currFileInfo.m_currFilePath.getBuf());
    
    m_currFileInfo.m_isSongPausable = (VfxBool)mdi_audio_is_file_pausable(fullPath);
    return m_currFileInfo.m_isSongPausable;
}

/* check if current song seekable. */
VfxBool VappMusicPlayerCtrlPlaybackSlim::isSongSeekable()
{
    VfxWChar *fullPath = const_cast<VfxWChar*>(m_currFileInfo.m_currFilePath.getBuf());

    m_currFileInfo.m_isSongSeekable = (VfxBool)mdi_audio_is_file_seekable(fullPath);
    return  m_currFileInfo.m_isSongSeekable;
}

/* update duration from mdi. */
void VappMusicPlayerCtrlPlaybackSlim::updateAudDuration(VfxBool isPrecise)
{   
    if (isPrecise)
    {
        (void)mdi_audio_mma_get_updated_duration(m_mdiHandle, &(m_currFileInfo.m_duration));
    }
    else
    {
        (void)mdi_audio_mma_get_estimated_duration(m_mdiHandle, &(m_currFileInfo.m_duration));
    }   
}

VfxU32 VappMusicPlayerCtrlPlaybackSlim::getDurationByPath(const VfxWString filePath)
{
    VfxWChar *fullPath = NULL;
    VfxU32 duration = 0;

    fullPath = const_cast<VfxWChar*>(filePath.getBuf());
    (void)mdi_audio_get_duration(fullPath, &duration);
    return duration;
}

VfxU32 VappMusicPlayerCtrlPlaybackSlim::getDuration(const VfxWString filePath)
{
    VfxU32 duration = 0;

    duration = m_currFileInfo.m_duration;
    if (filePath != m_currFileInfo.m_currFilePath)
    {
        duration = getDurationByPath(filePath);
    }

    return duration;
}

/* get current play time. */
VfxU32 VappMusicPlayerCtrlPlaybackSlim::getCurrTime()
{
    VfxU32 currTime = 0;

    if (m_interruptInfo.isInterrupted)
    {
        currTime = m_interruptInfo.interruptedDuration;
    }
    else if ((PB_STATE_SEEKING == m_playbackState)
             || (m_seekingInfo.isNeedSeek))
    {
        currTime = m_seekingInfo.seekTime;
    }
    else if (m_mdiHandle)
    {
        (void)mdi_audio_mma_get_current_time(m_mdiHandle, &currTime);
    }

    return currTime;
}

void VappMusicPlayerCtrlPlaybackSlim::songSwitched(const VfxWString filePath)
{
    VfxU32 duration = 0;

    /* song switched, update current song info. */
    //if (filePath != m_currFileInfo.m_currFilePath)
    {
        /* if current file opend, close it first, \
           if switch song after seek, must close it. */
        if (m_mdiHandle)
        {
            stop();
            close();
        }

        duration = getDurationByPath(filePath);
        m_currFileInfo.m_currFilePath = filePath;
        m_currFileInfo.m_isSongPausable = VFX_TRUE;
        m_currFileInfo.m_isSongSeekable = VFX_TRUE;
        m_currFileInfo.m_duration = duration;
        m_currFileInfo.m_sampleRate = 0;
        m_currFileInfo.m_stereo = 0;
    }
    
    /* switch song when interrupted, need to update interrupt info. */
    if (m_interruptInfo.isInterrupted 
        && (filePath != m_interruptInfo.interruptFile))
    {
        m_interruptInfo.interruptFile = filePath;
        m_interruptInfo.totalDuration = duration;
        m_interruptInfo.interruptedDuration = 0;
    }
    
    cleanSeekInfo();
}

/* get MDI error message. */
VfxResId VappMusicPlayerCtrlPlaybackSlim::getMDIErrorMessage(mdi_result result)
{
    mmi_event_notify_enum popupType;
    MMI_ID_TYPE errID = 0;

    errID = mdi_util_get_mdi_error_info(result, &popupType);
    return (VfxResId)errID;
}

VfxBool VappMusicPlayerCtrlPlaybackSlim::isMakingCall()
{
    VfxBool inCall = VFX_FALSE;
    VfxS32 callCount = 0;

    callCount = srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL);
    if (callCount > 0)
    {
        inCall = VFX_TRUE;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_PLAYBACK_INCALL, inCall);
    return inCall;
}

void VappMusicPlayerCtrlPlaybackSlim::getAudioInfo(const VfxWString &filePath)
{
    /* Get sample rate and stereo for A2DP. */
    VfxWChar *fullPath = const_cast<VfxWChar*>(filePath.getBuf());
    audInfoStruct *audioInfo = NULL;
    mmi_id groupID = 0;

    VFX_ALLOC_MEM(audioInfo, sizeof(audInfoStruct), this);

    mdi_audio_mma_get_audio_info(
        groupID,
        fullPath,
        0,
        NULL,
        0,
        audioInfo
        );

    m_currFileInfo.m_currFilePath = filePath;
    m_currFileInfo.m_duration = audioInfo->time;
    m_currFileInfo.m_sampleRate = audioInfo->sampleRate;
    m_currFileInfo.m_stereo = audioInfo->stereo;
    m_currFileInfo.m_isSongPausable = (VfxBool)mdi_audio_is_file_pausable(fullPath);
    m_currFileInfo.m_isSongSeekable = (VfxBool)mdi_audio_is_file_seekable(fullPath);

    VFX_FREE_MEM(audioInfo);
}

void VappMusicPlayerCtrlPlaybackSlim::cleanCurrFileInfo()
{
    m_currFileInfo.m_currFilePath.setEmpty();
    m_currFileInfo.m_isSongPausable = VFX_TRUE;
    m_currFileInfo.m_isSongSeekable = VFX_TRUE;
    m_currFileInfo.m_duration = 0;
    m_currFileInfo.m_sampleRate = 0;
    m_currFileInfo.m_stereo = 0;
}

void VappMusicPlayerCtrlPlaybackSlim::cleanInterruptInfo()
{
    m_interruptInfo.interruptFile.setEmpty();
    m_interruptInfo.isInterrupted = VFX_FALSE;
    m_interruptInfo.interruptedDuration = 0;
    m_interruptInfo.totalDuration = 0;
    m_interruptInfo.state = PB_STATE_NONE;
}

void VappMusicPlayerCtrlPlaybackSlim::cleanSeekInfo()
{
    m_seekingInfo.seekFile.setEmpty();
    m_seekingInfo.isNeedSeek = VFX_FALSE;
    m_seekingInfo.state = PB_STATE_NONE;
    m_seekingInfo.seekTime = 0;
}

void VappMusicPlayerCtrlPlaybackSlim::registerInterruptCallback()
{
   /* first clear background play callback.  */
   deregisterBckgrounCallback();

   /* if have been registered, must clear it first. */
   if (m_isRegInterrupt)
   {
       deregisterInterruptCallback();
   }

    /* Be sure to clear this hanlder when not used. MDI Only one instance currently. */
    mdi_audio_register_interrupt_callback(
        (mdi_ext_callback)&VappMusicPlayerCtrlPlaybackSlim::onMDIInterruptCallback, 
        getObjHandle()
        );

    m_isRegInterrupt = VFX_TRUE;
}

void VappMusicPlayerCtrlPlaybackSlim::deregisterInterruptCallback()
{
    if (m_isRegInterrupt)
    {
        mdi_audio_clear_interrupt_callback(); 
        m_isRegInterrupt = VFX_FALSE;
    }
}

void VappMusicPlayerCtrlPlaybackSlim::registerBckgrounCallback()
{
    /* first clear interrupt callback.  */
    if (m_isRegInterrupt)
    {
        deregisterInterruptCallback();
    }

    mdi_audio_set_background_handler(
        MDI_BACKGROUND_APP_MEDPLY,
        (mdi_bg_callback)(&VappMusicPlayerCtrlPlaybackSlim::onMDIBackgroundCallback), 
        getObjHandle()
        );
}

void VappMusicPlayerCtrlPlaybackSlim::deregisterBckgrounCallback()
{
    mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
}

void VappMusicPlayerCtrlPlaybackSlim::turnOnSoundEffect(VfxBool turnOn)
{
#ifdef __MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__
    if (m_soundEffectAdpt)
    {
        if (turnOn)
        {
            m_soundEffectAdpt->turnOnEffect();
        }
        else
        {
            m_soundEffectAdpt->turnOffEffect();
        }
    }
#endif
}

#if defined (__MMI_A2DP_SUPPORT__)
void VappMusicPlayerCtrlPlaybackSlim::openA2DP()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_PLAYBACK_OPEN_A2DP);

    /* if A2DP has been opened, close it first. */
    if (m_isA2DPOpen)
    {
        closeA2DP();
    }

    /* notify bt connecting start event. */
    notifyEvtListener(MUSIC_CB_BT_CONNECT, MUSIC_SUB_BT_CONNECT_START, 0);
    m_isA2DPOpen = VFX_TRUE;

    srv_a2dp_open(
        vapp_a2dp_get_bt_headset(), 
        m_currFileInfo.m_sampleRate, 
        m_currFileInfo.m_stereo, 
        &VappMusicPlayerCtrlPlaybackSlim::onA2DPOpenCallback, 
        MMI_TRUE
        );
}

void VappMusicPlayerCtrlPlaybackSlim::closeA2DP()
{
    /* only allowed to close when opened by music player APP, \
       not to affect other APPS' connect. */
    if (m_isA2DPOpen)
    {
        srv_a2dp_close_codec();
        srv_a2dp_close(MMI_FALSE);

        m_isA2DPOpen = VFX_FALSE;
    }
}

/* handle BT callback. */
void VappMusicPlayerCtrlPlaybackSlim::onA2DPOpenCallback(VfxS32 result)
{
    VappMusicPlayerCtrlPlaybackSlim *pThis = NULL;

    /* get current playback object, APP or CUI. */
    for (int i=0; i<MAX_PLAYBACK_OBJECT; i++)
    {
        VappMusicPlayerCtrlPlaybackSlim *pObj = NULL;
        pObj = (VappMusicPlayerCtrlPlaybackSlim *)(m_objReg[i]);
        
        if (pObj && pObj->m_isA2DPOpen)
        {
            pThis = (VappMusicPlayerCtrlPlaybackSlim *)(m_objReg[i]);
            break;
        }
    }

    /* notify bt connecting start event. */
    pThis->notifyEvtListener(MUSIC_CB_BT_CONNECT, MUSIC_SUB_BT_CONNECT_DONE, 0);

    PlaybackStateEnum state = PB_STATE_NONE;
    state = pThis->getPlaybackState();
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_PLAYBACK_A2DP_CB, result, state);

    switch (result)
    {
        case SRV_A2DP_CALLBACK_EVENT_OPEN_OK:
        {
            if (PB_STATE_PLAY == state)
            {
                srv_a2dp_open_codec(MMI_TRUE);
            }
            else
            {
                srv_a2dp_open_codec(MMI_FALSE);
            }
            
            break;
        };

        case SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED:
        case SRV_A2DP_CALLBACK_EVENT_OPEN_STOPPED:
        case SRV_A2DP_CALLBACK_EVENT_OPEN_SCO:
        case SRV_A2DP_CALLBACK_EVENT_STREAM_ABORT_IND:
        case SRV_A2DP_CALLBACK_EVENT_STREAM_CLOSE_IND:
        case SRV_A2DP_CALLBACK_EVENT_STREAM_SUSPEND_IND:
        case SRV_A2DP_CALLBACK_EVENT_UNEXPECTED_DISCONNECT_IND:
        {
            if (PB_STATE_PLAY == state)
            {
                pThis->closeA2DP();
            }
            
            break;
        }

        case SRV_A2DP_CALLBACK_EVENT_OPEN_CANCELED:
        {
            /* this result means someone else is using mdi audio \
               thus current playing is canceled. */
            break;
        }

        case SRV_A2DP_CALLBACK_EVENT_INQUIRY_START_IND:
        {
            /* Shall not happen. */
            break;
        }

        case SRV_A2DP_CALLBACK_EVENT_INQUIRY_STOP_IND:
        {
            /* Shall not happen. */
            break;
        }

        case SRV_A2DP_CALLBACK_EVENT_STREAM_START_IND:
        {
            /* not support. */
            break;
        }

        default:
            break;
    }

    /* start play. */
    if (PB_STATE_PLAY == state)
    {
        return;
    }
    else if (PB_STATE_PAUSE == state)
    {
        pThis->doResume();
    }
    else
    {
        pThis->doPlay();
    }
    
    return;
}

void VappMusicPlayerCtrlPlaybackSlim::openBTAud()
{
    m_btaudHandle = srv_btaud_open(BTAUD_LEVEL_NORMAL, BTAUD_CHNL_ANY);
    
    srv_btaud_set_notify(
        m_btaudHandle, 
        BTAUD_EV_STEREO_CONFIG_IND, 
        (BtAudNotify)&VappMusicPlayerCtrlPlaybackSlim::onBTAudEventCallback, 
        getObjHandle()
        );
}

void VappMusicPlayerCtrlPlaybackSlim::closeBTAud()
{
    if (m_btaudHandle)
    {
        srv_btaud_close(m_btaudHandle);
    }
}

/* BTAud event handler. */
S32 VappMusicPlayerCtrlPlaybackSlim::onBTAudEventCallback(BtAudEvent event, U32 arg, void *user_data)
{
    VappMusicPlayerCtrlPlaybackSlim *pThis = NULL;
    
    pThis = (VappMusicPlayerCtrlPlaybackSlim*)handleToObject((VfxObjHandle)user_data);
    if (pThis)
    {
        if (BTAUD_EV_STEREO_CONFIG_IND == event)
        {
            PlaybackStateEnum state = pThis->getPlaybackState();

            /* bt connected when playing, switch to bt output. */
            if (PB_STATE_PLAY == state)
            {
                pThis->openA2DP();
                return VFX_TRUE;
            }
        }    
    }
    
    return VFX_FALSE;
}

#endif  //__MMI_A2DP_SUPPORT__

#ifdef __MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__
void VappMusicPlayerCtrlPlaybackSlim::enableSoundEffect(VfxBool enableSoundEffect)
{
    if (enableSoundEffect)
    {
        VFX_OBJ_CREATE(m_soundEffectAdpt, VappMusicPlayerSoundEffectAdapt, this);
    }
    else if (m_soundEffectAdpt)
    {
        VFX_OBJ_CLOSE(m_soundEffectAdpt);
        m_soundEffectAdpt = NULL;
    }
    return;
}

VfxU8 VappMusicPlayerCtrlPlaybackSlim::getEffectGroup(void)
{
    return m_soundEffectAdpt->getEffectGroup();
}

VfxU8 VappMusicPlayerCtrlPlaybackSlim::getEffectIndex(void)
{
    return m_soundEffectAdpt->getEffectIndex();
}

void VappMusicPlayerCtrlPlaybackSlim::setEffect(VfxU8 group, VfxU8 index)
{
    m_soundEffectAdpt->setEffect(group, index);
}
#endif  //__MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__

/***************************************************************************** 
 * VappMusicPlayerSoundEffectAdapt Implementation
 *****************************************************************************/
#ifdef __MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__

VFX_IMPLEMENT_CLASS("VappMusicPlayerSoundEffectAdapt", VappMusicPlayerSoundEffectAdapt, VfxObject);

VappMusicPlayerSoundEffectAdapt::VappMusicPlayerSoundEffectAdapt() :
    m_effectType(0),
    m_effectIndex(0),
    m_isEffectOn(VFX_FALSE)
{
    srv_sound_effect_init();
    
    VfxS16 error = 0;
    ReadValue(NVRAM_VAPP_MUSIC_PLAYER_SOUND_EFFECT_TYPE, &m_effectType, DS_BYTE, &error);
    ReadValue(NVRAM_VAPP_MUSIC_PLAYER_SOUND_EFFECT_INDEX, &m_effectIndex, DS_BYTE, &error);
}

VappMusicPlayerSoundEffectAdapt::~VappMusicPlayerSoundEffectAdapt()
{
    if(m_isEffectOn)
    {
        turnOffEffect();
    }
    saveEffect();
}

VfxU8 VappMusicPlayerSoundEffectAdapt::getEffectGroup(void)
{
    VfxU8 group;

    switch(m_effectType)
    {
        case SRV_SOUND_EFFECT_TYPE_NONE:
            group = SOUND_EFFECTS_NONE;
            break;
#ifdef __MMI_AUDIO_EQUALIZER__
        case SRV_SOUND_EFFECT_TYPE_EQ:
            group = SOUND_EFFECTS_EQ;
            break;
#endif
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SRV_SOUND_EFFECT_TYPE_SURROUND:
            group = SOUND_EFFECTS_SURROUND;
            break;
#endif
#ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SRV_SOUND_EFFECT_TYPE_REVERB:
            group = SOUND_EFFECTS_REVERB;
            break;
#endif
        default:
            group = SOUND_EFFECTS_NONE;
            break;
    }

    return group;
}

VfxU8 VappMusicPlayerSoundEffectAdapt::getEffectIndex(void)
{
    return m_effectIndex;
}

void VappMusicPlayerSoundEffectAdapt::setEffect(VfxU8 group, VfxU8 index)
{
    switch(group)
    {
        case SOUND_EFFECTS_NONE:
            m_effectType = SRV_SOUND_EFFECT_TYPE_NONE;
            break;
#ifdef __MMI_AUDIO_EQUALIZER__
        case SOUND_EFFECTS_EQ:
            m_effectType = SRV_SOUND_EFFECT_TYPE_EQ;
            break;
#endif
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SOUND_EFFECTS_SURROUND:
            m_effectType = SRV_SOUND_EFFECT_TYPE_SURROUND;
            break;
#endif
#ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SOUND_EFFECTS_REVERB:
            m_effectType = SRV_SOUND_EFFECT_TYPE_REVERB;
            break;
#endif
        default:
            m_effectType = SRV_SOUND_EFFECT_TYPE_NONE;
            break;
    }

    m_effectIndex = index;

    /* Change effect if audio is playing */
    if(m_isEffectOn)
    {
        turnOffEffect();
        turnOnEffect();
    }
}

void VappMusicPlayerSoundEffectAdapt::saveEffect(void)
{
    VfxS16 error = 0;
    WriteValue(NVRAM_VAPP_MUSIC_PLAYER_SOUND_EFFECT_TYPE, &m_effectType, DS_BYTE, &error);
    WriteValue(NVRAM_VAPP_MUSIC_PLAYER_SOUND_EFFECT_INDEX, &m_effectIndex, DS_BYTE, &error);
}

void VappMusicPlayerSoundEffectAdapt::turnOnEffect(void)
{
    if(m_effectType != 0 || m_effectIndex != 0)
    {
        /* May handle callback here if other app may use in the future */
        srv_sound_effect_turn_on(static_cast<srv_sound_effect_type_enum>(m_effectType), m_effectIndex, NULL, NULL);
    }

    m_isEffectOn = VFX_TRUE;
}

void VappMusicPlayerSoundEffectAdapt::turnOffEffect(void)
{
    srv_sound_effect_turn_off();
    m_isEffectOn = VFX_FALSE;
}
#endif  // __MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__

#endif  // __MMI_COSMOS_MUSIC_PLAYER_SLIM__
