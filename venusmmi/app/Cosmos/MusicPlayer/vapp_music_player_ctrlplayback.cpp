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
 *  vapp_music_player_ctrlplayback.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  FTO Music Player playback control
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"
#ifdef __COSMOS_MUSICPLY__

#include "vapp_music_player.h"
#include "vapp_music_player_ctrlplayback.h"
#include "vapp_music_player_datatype.h"
#include "vapp_music_player_util.h"
#include "vfx_adp_device.h" // For touch feedback

extern "C"
{
#include "mdi_include.h"
#include "ProfilesSrvGprot.h"
#include "vapp_bt_a2dp_gprot.h"
#include "A2DPSrvGProt.h"
#include "BTMMIA2DPScr.h"
#include "gpiosrvgprot.h"
#include "UcmSrvGprot.h"
#include "L1audio.h"
}

#define MDI_CACHE_SIZE 2*1024

/***************************************************************************** 
 * VappMusicPlayerCtrlPlayback Implementation
 *****************************************************************************/

VappMusicPlayerCtrlPlayback* VappMusicPlayerCtrlPlayback::g_thisPtrForApp = NULL;
VappMusicPlayerCtrlPlayback* VappMusicPlayerCtrlPlayback::g_thisPtrForCui = NULL;

VFX_IMPLEMENT_CLASS("VappMusicPlayerCtrlPlayback", VappMusicPlayerCtrlPlayback, VfxObject);

void VappMusicPlayerCtrlPlayback::onInit()
{
    VfxObject::onInit();

    m_filePath.setEmpty();
    m_cacheFilePath.setEmpty();
    m_interruptInfo.isInterrupted = VFX_FALSE;
    m_interruptInfo.interruptedDuration = 0;
    m_interruptInfo.totalDuration = 0;
    m_interruptInfo.state = PB_STATE_NONE;

    VFX_OBJ_CREATE(m_ctrlSoundEffect, VappMusicPlayerSoundEffect, this);

#if defined(__MMI_A2DP_SUPPORT__)
    m_btaudHandle = srv_btaud_open(BTAUD_LEVEL_NORMAL, BTAUD_CHNL_ANY);
    srv_btaud_set_notify(
        m_btaudHandle, 
        BTAUD_EV_STEREO_CONFIG_IND, 
        (BtAudNotify)&VappMusicPlayerCtrlPlayback::BTAudEventHandler, 
        getObjHandle()
        );
#endif
}

void VappMusicPlayerCtrlPlayback::onDeinit()
{
    stop();
    closeFile();
    freeCache();

    deregisterInterruptCallback();

#if defined(__MMI_A2DP_SUPPORT__)
    srv_btaud_close(m_btaudHandle);
#endif

    if (m_isAppMode)
    {
        g_thisPtrForApp = NULL;
    }
    else
    {
        g_thisPtrForCui = NULL;
    }

    VfxObject::onDeinit();
}

void VappMusicPlayerCtrlPlayback::setIsAppMode(VfxBool isApp)
{
    m_isAppMode = isApp;

    if (isApp)
    {
        g_thisPtrForApp = this;
        g_thisPtrForCui = NULL;
    }
    else
    {
        // store this pointer if is CUI mode
        g_thisPtrForApp = NULL;
        g_thisPtrForCui = this;
    }
}

VfxS32 VappMusicPlayerCtrlPlayback::getHandle()
{
    return (VfxS32)m_mdiHandle;
}

void VappMusicPlayerCtrlPlayback::setHandle(VfxS32 handle)
{
    m_mdiHandle = (mdi_handle)handle;
}

void VappMusicPlayerCtrlPlayback::setCache(VfxBool reallocate)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_SET_CACHE, reallocate);

    if (reallocate)
    {
        VFX_ALLOC_MEM(m_cacheTable, MDI_CACHE_SIZE, this);
        memset(m_cacheTable, 0, MDI_CACHE_SIZE);
    }
    mdi_audio_mma_set_cache_table(m_mdiHandle, m_cacheTable);   
}

void VappMusicPlayerCtrlPlayback::freeCache()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_FREE_CACHE);

    if (m_cacheTable != NULL)
    {
        VFX_FREE_MEM(m_cacheTable);
        m_cacheTable = NULL;
    }
    m_isPreciseDuration = VFX_FALSE;

    m_cacheFilePath.setEmpty();
}

void VappMusicPlayerCtrlPlayback::setPreciseDuration()
{
    m_isPreciseDuration = VFX_TRUE;
}

void VappMusicPlayerCtrlPlayback::registerInterruptCallback(VfxBool force_register)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_REG_INT_CB, force_register, m_interruptInfo.isInterrupted, m_isRegsterIntrCallback);

    // If currently interrupted, do not register interrupt callback
    if(!force_register && m_interruptInfo.isInterrupted)
    {
        registerBackgroundCallback();
        return;
    }

    // interrupt callback
    if (m_isRegsterIntrCallback)
    {
        mdi_audio_clear_interrupt_callback();
    }
    mdi_audio_register_interrupt_callback(&VappMusicPlayerCtrlPlayback::onMDIInterruptCallback, getObjHandle());
    m_isRegsterIntrCallback = VFX_TRUE;

    registerBackgroundCallback();
}

void VappMusicPlayerCtrlPlayback::deregisterInterruptCallback()
{
    if (m_isRegsterIntrCallback)
    {
        mdi_audio_clear_interrupt_callback();
        m_isRegsterIntrCallback = VFX_FALSE;
    }
}

void VappMusicPlayerCtrlPlayback::registerBackgroundCallback()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_REG_BG_CB);

	// Interrupt resume callback, only register this callback in App mode
    if (m_isAppMode)
    {
        mdi_audio_set_background_handler(
            MDI_BACKGROUND_APP_MEDPLY, 
            (mdi_bg_callback)(&VappMusicPlayerCtrlPlayback::onMDIBackgroundCallback), 
            getObjHandle()
            );
    }
}

void VappMusicPlayerCtrlPlayback::setConsumeDRM(VfxBool consume)
{
    m_consumeDRM = consume;
}

VfxBool VappMusicPlayerCtrlPlayback::open(const VfxWString &filePath)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_OPEN);

    if (filePath.isEmpty())
    {
        return VFX_FALSE;
    }

    m_duration = 0;

    VfxWChar *fullPath = const_cast<VfxWChar*>(filePath.getBuf());
    
    if (m_playState != PB_STATE_NONE && m_playState != PB_STATE_CLOSE && m_playState != PB_STATE_INTERRUPTED)
    {
        stop();
        closeFile();
    }

    mmi_id groupID = 0;
    if (!m_isAppMode)
    {
        // only single player can play the memory needed format
        VfxApp *singlePlayer = findRootApp(this);
        groupID = singlePlayer->getGroupId();
    }

    if (m_isAppMode)
    {
        // Terminate background play
        // set this flag to skip self interruption
        if (getMusicPlayerSrv()->getPlayAfterSwitchSong())
        {
            m_doTerminateBgPlay = VFX_TRUE;
            terminateBackgroundPlay();
            m_doTerminateBgPlay = VFX_FALSE;
        }
    }
    else
    {
        terminateBackgroundPlay();
    }

#ifdef __DRM_SUPPORT__
    if (m_filePath == filePath)
    {
        // if playing the same file because of interrupting, disable the DRM count consuming (consume in play request)
        mdi_audio_drm_disable_consume_count();
        m_consumeDRM = VFX_FALSE;
    }
    else
    {
        m_consumeDRM = VFX_TRUE;
    }
#endif


    // MAUI_03099761: Get sample rate and stereo type before open. (Video type only has two handle, and can get in background)
#if defined(__MMI_A2DP_SUPPORT__)
    audInfoStruct *audioInfo = NULL;
    VFX_ALLOC_MEM(audioInfo, sizeof(audInfoStruct), this);

    mdi_audio_mma_get_audio_info(
        groupID,
        fullPath,
        0,
        NULL,
        0,
        audioInfo
        );
        
    m_sampleRate = audioInfo->sampleRate;
    m_stereo = audioInfo->stereo;

    VFX_FREE_MEM(audioInfo);
#endif /*__MMI_A2DP_SUPPORT__*/


    // Open file
    mdi_handle handle = 0;
    
    mdi_mma_open_struct openStruct;
    openStruct.app_id = groupID;
    openStruct.file_name = fullPath;
    openStruct.data = NULL;
    openStruct.data_len = 0;
    openStruct.mdi_format = 0;
    openStruct.repeats = 1;
    openStruct.is_pdl = MMI_FALSE;
    openStruct.callback = &VappMusicPlayerCtrlPlayback::onMDICallback;
    openStruct.user_data = this;
    openStruct.handle_p = &handle;
    openStruct.output_path = MDI_DEVICE_SPEAKER2;

    m_doTerminateBgPlay = VFX_TRUE;
    mdi_result result = mdi_audio_mma_open(&openStruct);
    m_doTerminateBgPlay = VFX_FALSE;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_OPEN_RESULT, result);

    if(*openStruct.handle_p == 0)
    {
        m_mdiHandle = 0;
        
        // return error code to APP to display error message
        m_signalMDICallback.emit(result);

        setPlayState(PB_STATE_PLAYBACK_FAIL);

        return VFX_FALSE;
    }

    m_mdiHandle = *(openStruct.handle_p);

    if (m_cacheFilePath == filePath)
    {
        setCache(VFX_FALSE);
    }
    else
    {
        freeCache();
        setCache(VFX_TRUE);

        m_cacheFilePath = filePath;
    }

    m_filePath = filePath;

    updateDuration();

    // check if song pausable and seekable
    m_isSongPausable = mdi_audio_is_file_pausable(fullPath);
    m_isSongSeekable = mdi_audio_is_file_seekable(fullPath);

    // Change state
    setPlayState(PB_STATE_OPEN);
    
    // interrupt callback
    registerInterruptCallback(VFX_TRUE);

    // trigger updating duration in DB
    m_signalMDICallback.emit(MDI_AUDIO_DUR_UPDATED);

    return VFX_TRUE;
}

void VappMusicPlayerCtrlPlayback::play()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_PLAY, m_playState);

    VappMusicPlayerService *srv = getMusicPlayerSrv();

    if (srv->blockActionInCall())
    {
        return;
    }

    clearInterruptState();

    if (m_playState != PB_STATE_NONE && m_playState != PB_STATE_CLOSE)
    {
        // Set effect for app only
        if (m_ctrlSoundEffect && m_isAppMode)
        {
            m_ctrlSoundEffect->turnOnEffect();
        }

    #if defined(__MMI_A2DP_SUPPORT__)
        if (vapp_a2dp_is_output_to_bt())
        {
            // If output to BT device, initialize the BT connection then do the play action in onBTOpenCallback
            if (m_playState == PB_STATE_INTERRUPTED)
            {
                setPlayState(PB_STATE_BT_CONNECTING_WHILE_INTERRUPTED);
            }
            else
            {
                setPlayState(PB_STATE_BT_CONNECTING);
            }
            openA2DP();
        }
        else
    #else
        if (1)
    #endif  //__MMI_A2DP_SUPPORT__
        {
            // If not output to BT, do the play action
            doPlay();
        }
    }
}

void VappMusicPlayerCtrlPlayback::doPlay()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_DO_PLAY, m_playState);

    if (m_playState != PB_STATE_NONE)
    {
        if ((m_playState == PB_STATE_CLOSE || m_playState == PB_STATE_INTERRUPTED) && m_interruptInfo.isInterrupted)
        {
            resumeInterruptPlay();
        }
        else
        {
            if(m_mdiHandle)
            {
                #ifdef __DRM_SUPPORT__
                    // Only consume once for each open to close session
                    if (m_consumeDRM)
                    {
                        // Not to disable consume for this play request
                        m_consumeDRM = VFX_FALSE;
                    }
                    else
                    {
                        mdi_audio_drm_disable_consume_count();                    
                    }
                #endif

                // call this API to output sound to correct speaker
                mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2);

                mdi_audio_set_volume(MDI_VOLUME_MEDIA, srv_prof_get_media_vol());
                mdi_result result = mdi_audio_mma_play(m_mdiHandle);

                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_DO_PLAY_1, result);

                if(result == MDI_AUDIO_END_OF_FILE)
                {
                    VfxTimer *timerEOF;
                    VFX_OBJ_CREATE(timerEOF, VfxTimer, this);
                    timerEOF->setStartDelay(0); // Repeate Once
                    timerEOF->m_signalTick.connect(this, &VappMusicPlayerCtrlPlayback::onEOFTimerExpir);
                    timerEOF->start();

                    setPlayState(PB_STATE_PLAY);
                    m_signalMDICallback.emit(VAPP_MUSICPLY_PRE_END_OF_FILE);
                }
                else if(result != MDI_AUDIO_SUCCESS)
                {
                    closeFile();
                    freeCache();
                    setPlayState(PB_STATE_PLAYBACK_FAIL);

                    // return error code to APP to display error message
                    m_signalMDICallback.emit(result);

                    return;
                }
                else
                {
                    setPlayState(PB_STATE_PLAY);

                    // Disable touch feedback when play music
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_TOUCH_FB_OFF);
                    vfx_adp_touch_fb_disable_tone();
                }
            }
        }

        m_playStateBeforeSeek = PB_STATE_NONE;
    }
}

void VappMusicPlayerCtrlPlayback::resumeInterruptPlay()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_RESUME_INT_PLAY, m_playState);

    if (m_interruptInfo.isInterrupted)
    {
        VfxWString filePath = getFilePath();

        if (m_isAppMode)
        {
            VappMusicPlayerApp *pApp = getMusicPlayerApp();
            if(pApp && pApp->m_actionMode == ACTION_REFRESH)
            {
                // Not resume while app refreshing
                return;
            }
        
            if (filePath.isEmpty())
            {
                filePath = getMusicPlayerSrv()->getActiveFilePath();
            }

            if (m_interruptInfo.state == PB_STATE_PLAY
            || m_interruptInfo.state == PB_STATE_SWITCHING_PLAY
            || (m_interruptInfo.state == PB_STATE_SEEKING && m_playStateBeforeSeek == PB_STATE_PLAY)
            || m_interruptInfo.state == PB_STATE_BT_CONNECTING
            || m_interruptInfo.state == PB_STATE_BT_CONNECTING_WHILE_PLAYING
            || m_interruptInfo.state == PB_STATE_BT_CONNECTING_WHILE_RESUME)
            {
                // reset this flag to TRUE to start playback after switch
                getMusicPlayerSrv()->setPlayAfterSwitchSong(VFX_TRUE);
            }
        }

        if (open(filePath))
        {
			m_playStateBeforeSeek = m_interruptInfo.state;

            seekStart(m_interruptInfo.interruptedDuration);

            m_interruptInfo.isInterrupted = VFX_FALSE;
        }

        // Clear state after resume
        clearInterruptState();
    }
}

void VappMusicPlayerCtrlPlayback::pause()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_PAUSE, m_playState);

    if (m_playState != PB_STATE_NONE && m_playState != PB_STATE_CLOSE)
    {
        if(m_mdiHandle)
        {
            seekStop();

            mdi_result result = mdi_audio_mma_pause(m_mdiHandle);
            
            if (result == MDI_AUDIO_SUCCESS)
            {
                setPlayState(PB_STATE_PAUSE);
            }
            else if (result == MDI_AUDIO_END_OF_FILE)
            {
                setPlayState(PB_STATE_STOP);
                m_signalMDICallback.emit(MDI_AUDIO_END_OF_FILE);
            }
            else if (result == MDI_AUDIO_UNSUPPORTED_OPERATION)
            {
                // do nothing for this case
            }
            else
            {
                closeFile();
                freeCache();

                // return error code to APP to display error message
                m_signalMDICallback.emit(result);
            }

            // Enable touch feedback when music stop play
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_TOUCH_FB_ON);
            vfx_adp_touch_fb_enable_tone();
        }

        if (m_ctrlSoundEffect && m_isAppMode)
        {
            m_ctrlSoundEffect->turnOffEffect();
        }

        closeA2DP();
    }
}

void VappMusicPlayerCtrlPlayback::resume()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_RESUME, m_playState);

    if (m_playState != PB_STATE_NONE && m_playState != PB_STATE_CLOSE)
    {
        if (m_ctrlSoundEffect && m_isAppMode)
        {
            m_ctrlSoundEffect->turnOnEffect();
        }

        if(m_mdiHandle)
        {
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, srv_prof_get_media_vol());
        }

    #if defined(__MMI_A2DP_SUPPORT__)
        if (vapp_a2dp_is_output_to_bt())
        {
            // If output to BT device, initialize the BT connection then do the play action in onBTOpenCallback
            setPlayState(PB_STATE_BT_CONNECTING_WHILE_RESUME);
            openA2DP();
        }
        else
    #else
        if (1)
    #endif  //__MMI_A2DP_SUPPORT__
        {
            // If not output to BT, do the resume action

            doResume();
        }
    }
}

void VappMusicPlayerCtrlPlayback::doResume()
{
    // call this API to output sound to correct speaker
    mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2);

    mdi_result result = mdi_audio_mma_resume(m_mdiHandle);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_DO_RESUME, result);

    if(result == MDI_AUDIO_END_OF_FILE)
    {
        setPlayState(PB_STATE_PLAY);
        m_signalMDICallback.postEmit(MDI_AUDIO_END_OF_FILE);
    }
    else if(result != MDI_AUDIO_SUCCESS)
    {
        closeFile();
        freeCache();
        setPlayState(PB_STATE_PLAYBACK_FAIL);

        // return error code to APP to display error message
        m_signalMDICallback.emit(result);
        return;
    }
    else
    {
        // Disable touch feedback when play music
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_TOUCH_FB_OFF);
        vfx_adp_touch_fb_disable_tone();

        setPlayState(PB_STATE_PLAY);
    }
}

void VappMusicPlayerCtrlPlayback::stop()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_STOP, m_playState);

    if (m_playState != PB_STATE_NONE && m_playState != PB_STATE_STOP && m_playState != PB_STATE_CLOSE && m_playState != PB_STATE_INTERRUPTED)
    {
        if(m_mdiHandle)
        {
            seekStop();
            mdi_audio_mma_stop(m_mdiHandle);
            
            // Enable touch feedback when music stop play
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_TOUCH_FB_ON);
            vfx_adp_touch_fb_enable_tone();
        }

        setPlayState(PB_STATE_STOP);

        if (m_ctrlSoundEffect && m_isAppMode)
        {
            m_ctrlSoundEffect->turnOffEffect();
        }

        closeA2DP();
    }
}

void VappMusicPlayerCtrlPlayback::closeFile(VfxBool clearFilePath)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_CLOSE_FILE, m_playState);

    if (m_playState != PB_STATE_NONE && m_playState != PB_STATE_CLOSE && m_playState != PB_STATE_INTERRUPTED)
    {
        if(m_mdiHandle)
        {
            mdi_audio_mma_close(m_mdiHandle);
            m_mdiHandle = 0;

            deregisterInterruptCallback();
            setPlayState(PB_STATE_CLOSE);
        }
        
        if (clearFilePath)
        {
            m_filePath.setEmpty();
        }
        
        closeA2DP();
    }

    m_playStateBeforeSeek = PB_STATE_NONE;
}

VfxBool VappMusicPlayerCtrlPlayback::isSongPausable(VfxWChar *filePath)
{
    /* If file already opened, return flag directly */
    if(m_playState == PB_STATE_NONE || m_playState == PB_STATE_CLOSE)
    {
        const VfxBool isPausable = mdi_audio_is_file_pausable(filePath);
        return isPausable;
    }
    else
    {
        return m_isSongPausable;
    }
}

VfxBool VappMusicPlayerCtrlPlayback::isSongSeekable(VfxWChar *filePath)
{
    /* If file already opened, return flag directly */
    if(m_playState == PB_STATE_NONE || m_playState == PB_STATE_CLOSE)
    {
        const VfxBool isSeekable = mdi_audio_is_file_seekable(filePath);
        return isSeekable;
    }
    else
    {
        return m_isSongSeekable;
    }
}

void VappMusicPlayerCtrlPlayback::playpause()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_PLAYPAUSE, m_playState, m_interruptInfo.isInterrupted, m_interruptInfo.state);

    if (m_playState == PB_STATE_PLAY || m_playState == PB_STATE_BT_CONNECTING_WHILE_PLAYING)
    {
        pause();
    }
    else if (m_playState == PB_STATE_OPEN || (m_playState == PB_STATE_PAUSE && !m_isSongPausable))
    {
        play();
    }
    else if (m_playState == PB_STATE_STOP)
    {
        if (!m_mdiHandle)
        {
            VfxWString filePath = getFilePath();
            if (filePath.isEmpty() && m_isAppMode)
            {
                filePath = getMusicPlayerSrv()->getActiveFilePath();
            }

            if (open(filePath))
            {
                play();
            }
        }
        else
        {
            play();
        }
    }
    else if (m_playState == PB_STATE_PAUSE)
    {
        resume();
    }    
    else if (m_interruptInfo.isInterrupted)
    {
        // only consider the flag isInterrupted because playback state may be not PB_STATE_INTERRUPTED 

        if (m_interruptInfo.state == PB_STATE_NONE  // already switch song
         || m_interruptInfo.state == PB_STATE_OPEN
         || m_interruptInfo.state == PB_STATE_PAUSE
         || m_interruptInfo.state == PB_STATE_STOP
         || m_interruptInfo.state == PB_STATE_SWITCHING_NOT_PLAY)
        {
            // this case is user manually click the play button, set the play state to PLAY to start the playback
            m_interruptInfo.state = PB_STATE_PLAY;
        }

        resumeInterruptPlay();
    }
    else if(m_playState == PB_STATE_INTERRUPTED)
    {
        // for the case interruptInfo.isInterrupted was clear
        m_interruptInfo.isInterrupted = VFX_TRUE;
        m_interruptInfo.state = PB_STATE_PLAY;
        m_interruptInfo.interruptedDuration = m_seekTime;
        resumeInterruptPlay();
    }
    else
    {
        //VFX_ASSERT(0);
    }
}

VfxBool VappMusicPlayerCtrlPlayback::seek(VfxU32 time)
{
    mdi_result result;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_SEEK, m_playState, time);

    if (m_playState != PB_STATE_NONE && m_playState != PB_STATE_CLOSE)
    {
        if (m_mdiHandle)
        {
            VfxU32 duration = getDuration();
            VfxU32 newTime = vfxMin(time, duration);

            result = mdi_audio_mma_set_start_time(m_mdiHandle, newTime);

            // Seek fail for MPL files (ie. RA, M4A...)
            if(result == MDI_AUDIO_END_OF_FILE)
            {
                m_signalMDICallback.emit(MDI_AUDIO_END_OF_FILE);
                return VFX_FALSE;
            }
            else if(result != MDI_AUDIO_SUCCESS)
            {
                closeFile();
                freeCache();
                setPlayState(PB_STATE_PLAYBACK_FAIL);
            
                // return error code to APP to display error message
                m_signalMDICallback.emit(result);
                return VFX_FALSE;
            }
        }
        else if (m_playState == PB_STATE_INTERRUPTED && m_playStateBeforeSeek == PB_STATE_INTERRUPTED)
        {
            m_interruptInfo.interruptedDuration = time;
        }
    }
    return VFX_TRUE;
}

void VappMusicPlayerCtrlPlayback::seekStart(VfxU32 time)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_SEEK_START, m_playState, time);

    m_seekTime = time;

    if (m_mdiHandle)
    {
        seekStop();

        m_signalShowHideWaitIcon.emit(VFX_TRUE, VFX_TRUE);

        VfxU32 duration = getDuration();
        VfxU32 newTime = vfxMin(time, duration);

        mdi_audio_start_seek(reinterpret_cast<void*>(const_cast<VfxWChar*>(m_filePath.getBuf())), 
            m_cacheTable, 
            MDI_CACHE_SIZE, 
            time, 
            &VappMusicPlayerCtrlPlayback::onSeekCallback, 
            this
            );

        setPlayState(PB_STATE_SEEKING);
    }
    
    if (m_interruptInfo.isInterrupted
      || (getPlayState() == PB_STATE_INTERRUPTED && m_playStateBeforeSeek == PB_STATE_INTERRUPTED)
      || (getPlayState() == PB_STATE_PAUSE && (m_playStateBeforeSeek == PB_STATE_PAUSE || m_playStateBeforeSeek == PB_STATE_STOP)))
    {
        m_interruptInfo.interruptedDuration = time;
    }
}

void VappMusicPlayerCtrlPlayback::seekStop()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_SEEK_STOP);

    VappMusicPlayerApp *app = getMusicPlayerApp();
    if (!m_isAppMode 
        || !app 
        || (app->getActionMode() != ACTION_LAUNCHING 
            && app->getActionMode() != ACTION_LAUNCHING_FROM_BG
            && !app->m_checkDuplicatedPlaylistRunning)
        )
    {
        m_signalShowHideWaitIcon.emit(VFX_FALSE, VFX_FALSE);
    }

    if (m_mdiHandle)
    {
        mdi_audio_stop_seek();
    }
}

void VappMusicPlayerCtrlPlayback::clearSeekInfo()
{
    m_playStateBeforeSeek = PB_STATE_NONE;
    m_seekTime = 0;
}

VfxWString VappMusicPlayerCtrlPlayback::getFilePath()
{
    return m_filePath;
}

void VappMusicPlayerCtrlPlayback::setFilePath(VfxWString filePath)
{
    m_filePath = filePath;
}

void VappMusicPlayerCtrlPlayback::clearFilePath()
{
    m_filePath.setEmpty();
}

void VappMusicPlayerCtrlPlayback::updateDuration(VfxBool force_precise)
{
    if (m_isPreciseDuration || force_precise)
    {
        mdi_result ret = mdi_audio_mma_get_updated_duration(m_mdiHandle, &m_duration);
    }
    else
    {
        mdi_result ret = mdi_audio_mma_get_estimated_duration(m_mdiHandle, &m_duration);
    }
}

void VappMusicPlayerCtrlPlayback::updateDurationByPath(const VfxWChar *filePath)
{
    // update current file duration when player is not open
    m_duration = getDurationByPath(filePath);
}

void VappMusicPlayerCtrlPlayback::resetDuration(void)
{
    m_duration = 0;
}

VfxU32 VappMusicPlayerCtrlPlayback::getDuration()
{
    VfxU32 duration = 0;
    if (m_interruptInfo.isInterrupted
     || m_playState == PB_STATE_INTERRUPTED)
    {
        duration = m_interruptInfo.totalDuration;
        if (duration == 0)
        {
            VfxWString filePath = getFilePath();
            if (filePath.isEmpty() && m_isAppMode)
            {
                filePath = getMusicPlayerSrv()->getActiveFilePath();
            }
            if(!filePath.isEmpty())
            {
                m_interruptInfo.totalDuration = duration = getDurationByPath(filePath.getBuf());
            }
        }
    }
    else if (m_playState != PB_STATE_NONE)
    {
        duration = m_duration;
    }

    return duration;
}

VfxU32 VappMusicPlayerCtrlPlayback::getDurationByPath(const VfxWChar *filePath)
{
    VfxU32 duration = 0;
    mdi_result ret = mdi_audio_get_duration(const_cast<VfxWChar*>(filePath), &duration);
    return duration;
}

VfxU32 VappMusicPlayerCtrlPlayback::getCurrTime()
{
    VfxU32 currTime = 0;
    PlaybackStateEnum state = m_playState;

    if (m_interruptInfo.isInterrupted)
    {
        currTime = m_interruptInfo.interruptedDuration;
    }
    else if ((state == PB_STATE_STOP || state == PB_STATE_CLOSE || state == PB_STATE_SEEKING || state == PB_STATE_PAUSE || state == PB_STATE_INTERRUPTED) && m_playStateBeforeSeek != PB_STATE_NONE)
    {
        currTime = m_seekTime;
    }
    else if (state != PB_STATE_NONE && state != PB_STATE_CLOSE && state != PB_STATE_STOP)
    {
        mdi_audio_mma_get_current_time(m_mdiHandle, &currTime);
    }
    return currTime;
}

PlaybackStateEnum VappMusicPlayerCtrlPlayback::getPlayState()
{
    return m_playState;
}

VfxBool VappMusicPlayerCtrlPlayback::getPlayPauseState()
{
    if (m_playState == PB_STATE_PLAY 
     || m_playState == PB_STATE_SWITCHING_PLAY 
     || m_playState == PB_STATE_BT_CONNECTING 
     || m_playState == PB_STATE_BT_CONNECTING_WHILE_PLAYING
     || m_playState == PB_STATE_BT_CONNECTING_WHILE_RESUME
     || m_playState == PB_STATE_BT_CONNECTING_WHILE_INTERRUPTED)
    {
        return VFX_FALSE;
    }
    else if (m_playState == PB_STATE_SEEKING 
         && (m_playStateBeforeSeek == PB_STATE_PLAY
          || m_playStateBeforeSeek == PB_STATE_BT_CONNECTING
          || m_playStateBeforeSeek == PB_STATE_BT_CONNECTING_WHILE_PLAYING
          || m_playStateBeforeSeek == PB_STATE_BT_CONNECTING_WHILE_RESUME))
    {
        return VFX_FALSE;
    }
    else
    {
        return VFX_TRUE;
    }
}

void VappMusicPlayerCtrlPlayback::setPlayState(PlaybackStateEnum state)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_SET_PLAY_STATE, m_playState, state);

    // Disable touch feedback when switching play, and enable it after switch done to make sure it pairs
    if(state == PB_STATE_SWITCHING_PLAY && m_playState != PB_STATE_SWITCHING_PLAY)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_TOUCH_FB_OFF);
        vfx_adp_touch_fb_disable_tone();
    }

    if(m_playState == PB_STATE_SWITCHING_PLAY && state!= PB_STATE_SWITCHING_PLAY)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_TOUCH_FB_ON);
        vfx_adp_touch_fb_enable_tone();
    }

    if (m_playState != state)
    {
        m_playState = state;
        m_signalPlaybackStateChange.emit(m_playState);
    }

    if (state == PB_STATE_NONE)
    {
        clearInterruptState();
    }
}

void VappMusicPlayerCtrlPlayback::onEOFTimerExpir(VfxTimer *timer)
{
    m_signalMDICallback.emit(MDI_AUDIO_END_OF_FILE);
    VFX_OBJ_CLOSE(timer);
}

void VappMusicPlayerCtrlPlayback::onMDICallback(kal_int32 handle, kal_int32 result, void* user_data)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_ON_MDI_CB, result);

    VappMusicPlayerCtrlPlayback *pThis = reinterpret_cast<VappMusicPlayerCtrlPlayback*>(user_data);

    if (!pThis->isValid())
    {
        return;
    }
    else if (handle != pThis->getHandle())
    {
        // check if handle is the same
        return;
    }

    // Handle result before emit signal
    switch (result)
    {
        case MDI_AUDIO_END_OF_FILE:
            // If backlight is on, start a short time to send out EOF signal for app to update screen
            if(srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD))
            {
                // Force to show frame for setStartDelay(0)
                VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
                renderer->mustShowNextFrame();
            
                VfxTimer *timerEOF;
                VFX_OBJ_CREATE(timerEOF, VfxTimer, pThis);
                timerEOF->setStartDelay(0); // Repeate Once
                timerEOF->m_signalTick.connect(pThis, &VappMusicPlayerCtrlPlayback::onEOFTimerExpir);
                timerEOF->start();

                result = VAPP_MUSICPLY_PRE_END_OF_FILE;
            }
            break;

        case MDI_AUDIO_DUR_UPDATED:
            pThis->setPreciseDuration();
            pThis->updateDuration();
            break;
            
        default:
            break;
    };

    pThis->m_signalMDICallback.emit(result);
}

VfxResId VappMusicPlayerCtrlPlayback::getMDIErrorMessage(mdi_result result)
{
    mmi_event_notify_enum popupType;
    MMI_ID_TYPE errID = mdi_util_get_mdi_error_info(result, &popupType);
    return (VfxResId)errID;
}

void VappMusicPlayerCtrlPlayback::terminateBackgroundPlay()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_TERMINATEBGPLAY);
    mdi_audio_terminate_background_play();
}

void VappMusicPlayerCtrlPlayback::onSeekCallback(kal_uint8 reason, void* user_data)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_ON_SEEK_CALLBACK, reason);

    VappMusicPlayerCtrlPlayback *pThis = reinterpret_cast<VappMusicPlayerCtrlPlayback*>(user_data);
    if (pThis->isValid())
    {
        VappMusicPlayerApp *app = getMusicPlayerApp();
        if (!pThis->m_isAppMode 
            || !app 
            || (app->getActionMode() != ACTION_LAUNCHING 
                && app->getActionMode() != ACTION_LAUNCHING_FROM_BG
                && !app->m_checkDuplicatedPlaylistRunning)
            )
        {
            pThis->m_signalShowHideWaitIcon.emit(VFX_FALSE, VFX_FALSE);
        }

        pThis->m_signalMDICallback.emit(reason);
    }
}

void VappMusicPlayerCtrlPlayback::onMDIInterruptCallback(mdi_result result, void *user_data)
{
    // Interrupt callback
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_ON_MDI_INTERRUPTCB, result);

    VappMusicPlayerCtrlPlayback* pThis = (VappMusicPlayerCtrlPlayback*)handleToObject((VfxObjHandle)user_data);
    if (pThis)
    {
        pThis->doMDIInterruptCallback(result);
    }
}

void VappMusicPlayerCtrlPlayback::doMDIInterruptCallback(mdi_result result)
{
    if(result == MDI_AUDIO_TERMINATED)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_ON_MDI_INTERRUPTCB_STATE, m_doTerminateBgPlay, getPlayState());

        if (m_doTerminateBgPlay)
        {
            // This case indicates that this interruption is caused by Music Player
            return;
        }

        PlaybackStateEnum state = getPlayState();
        if (state != PB_STATE_NONE && state != PB_STATE_CLOSE)
        {
            if (state == PB_STATE_PLAYBACK_FAIL)
            {
                // if state is PB_STATE_PLAYBACK_FAIL means it is in the timing that screen is displaying popup balloon and start timer to find next valid song
                // we can assume the playback will always be resumed after getting resume callback
                state = PB_STATE_SWITCHING_PLAY;
            }

            // If interrupt while switching songs, clear current time and duraiton to 0.
            if(state == PB_STATE_SWITCHING_PLAY || state == PB_STATE_SWITCHING_NOT_PLAY)
            {
                m_interruptInfo.interruptedDuration = 0;
                m_interruptInfo.totalDuration = 0;
            }
            else
            {
                // If not pausable, will reset time to 0 when interrupt
                if(m_isSongPausable)
                {
                    m_interruptInfo.interruptedDuration = getCurrTime();
                }
                else
                {
                    m_interruptInfo.interruptedDuration = 0;
                }

                m_interruptInfo.totalDuration = getDuration();
            }
            
            if (state == PB_STATE_SEEKING)
            {
                m_interruptInfo.state = m_playStateBeforeSeek;
            }
            else
            {
                m_interruptInfo.state = state;
            }

            // make sure this flag is set at the last, it decide the return value of getCurrTime()
            m_interruptInfo.isInterrupted = VFX_TRUE;

            stop();
            closeFile(VFX_FALSE);

            setPlayState(PB_STATE_INTERRUPTED);
        }

        m_signalMDICallback.emit(VAPP_MUSICPLY_INTERRUPT_CB_INTERRUPT);
    }
}

VfxBool VappMusicPlayerCtrlPlayback::onMDIBackgroundCallback(mdi_result result, void *user_data)
{
    // Resume callback
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_ON_MDI_BG_CB, result);

    VappMusicPlayerCtrlPlayback* pThis = (VappMusicPlayerCtrlPlayback*)handleToObject((VfxObjHandle)user_data);
    {
        if (pThis)
        {
            pThis->doMDIBackgroundCallback(result);
        }
    }

    return VFX_TRUE;
}

void VappMusicPlayerCtrlPlayback::doMDIBackgroundCallback(mdi_result result)
{
    switch (result)
    {
        case MDI_AUDIO_RESUME:
        {
            const PlaybackStateEnum state = getPlayState();

            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_ON_MDI_BG_CB_STATE, state, m_interruptInfo.isInterrupted, m_interruptInfo.state);

            if (m_interruptInfo.isInterrupted && m_interruptInfo.state == PB_STATE_SWITCHING_NOT_PLAY)
            {
                clearInterruptState(VFX_FALSE,VFX_FALSE);  
            }
            else if (state == PB_STATE_CLOSE || state == PB_STATE_INTERRUPTED || m_interruptInfo.isInterrupted)
            {
                // Only resume if the state before interrupt is not pause or stop
                if(m_interruptInfo.state != PB_STATE_PAUSE && m_interruptInfo.state != PB_STATE_STOP)
                {
                    resumeInterruptPlay();
                    m_signalMDICallback.emit(VAPP_MUSICPLY_INTERRUPT_CB_RESUME);
                }
            }

            break;
        }

        case MDI_AUDIO_TERMINATED:
        {
            if (!m_doTerminateBgPlay)
            {
                // clear interrupted state so that playback will not be resumed anyway
                m_interruptInfo.state = PB_STATE_STOP;
            }
            break;
        }
    }
}

VfxBool VappMusicPlayerCtrlPlayback::isBackgroundPlayValid()
{
    if(mdi_audio_is_background_play_suspended() || !hasBackgroundCallback())
    {
        return VFX_FALSE;
    }
    else
    {
        return VFX_TRUE;
    }
}

VfxBool VappMusicPlayerCtrlPlayback::hasBackgroundCallback()
{
    return mdi_audio_get_background_callback_order(MDI_BACKGROUND_APP_MEDPLY) == 0;
}

InterruptStruct VappMusicPlayerCtrlPlayback::getInterruptedInfo()
{
    return m_interruptInfo;
}

void VappMusicPlayerCtrlPlayback::clearInterruptState(VfxBool keepInterrupt, VfxBool keepState)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_CLEAR_INTR_STATE, keepInterrupt, keepState, m_interruptInfo.isInterrupted, m_interruptInfo.state);

    if (!keepInterrupt)
    {
        m_interruptInfo.isInterrupted = VFX_FALSE;
    }

    if (!keepState)
    {
        PlaybackStateEnum state = m_interruptInfo.state;
        if (state == PB_STATE_CLOSE
        || state == PB_STATE_PLAYBACK_FAIL
        || state == PB_STATE_PAUSE
        || state == PB_STATE_STOP)
        { 
            m_interruptInfo.state = PB_STATE_SWITCHING_NOT_PLAY;
        }
    }

    m_interruptInfo.interruptedDuration = 0;
    m_interruptInfo.totalDuration = 0;
}

void VappMusicPlayerCtrlPlayback::onBTOpenCallback(VfxS32 result)
{
#if defined(__MMI_A2DP_SUPPORT__)
    const VfxBool isAppMode = g_thisPtrForCui == NULL;
    VappMusicPlayerCtrlPlayback *pThis = isAppMode ? g_thisPtrForApp : g_thisPtrForCui;

    const PlaybackStateEnum state = pThis->getPlayState();

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_ON_BT_OPEN_CB, result, isAppMode, state);

    switch (result)
    {
        case SRV_A2DP_CALLBACK_EVENT_OPEN_OK:
        {
            switch (state)
            {
                case PB_STATE_BT_CONNECTING:
                case PB_STATE_BT_CONNECTING_WHILE_RESUME:
                case PB_STATE_BT_CONNECTING_WHILE_INTERRUPTED:
                    // Pass MMI_FALSE for not playing
                    srv_a2dp_open_codec(MMI_FALSE);
                    break;

                case PB_STATE_BT_CONNECTING_WHILE_PLAYING:
                    srv_a2dp_open_codec(MMI_TRUE);
                    break;

                default:
                    break;
            };

            break;  
        }

        case SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED:
        case SRV_A2DP_CALLBACK_EVENT_OPEN_STOPPED:
        case SRV_A2DP_CALLBACK_EVENT_OPEN_SCO:
        case SRV_A2DP_CALLBACK_EVENT_STREAM_ABORT_IND:
        case SRV_A2DP_CALLBACK_EVENT_STREAM_CLOSE_IND:
        case SRV_A2DP_CALLBACK_EVENT_STREAM_SUSPEND_IND:
        case SRV_A2DP_CALLBACK_EVENT_UNEXPECTED_DISCONNECT_IND:
            if (state == PB_STATE_PLAY)
            {
                pThis->closeA2DP();
            }
            break;

        case SRV_A2DP_CALLBACK_EVENT_OPEN_CANCELED:
            // this result means someone else is using mdi audio thus current playing is canceled
            break;

        case SRV_A2DP_CALLBACK_EVENT_INQUIRY_START_IND:
            // Shall not happen
            break;

        case SRV_A2DP_CALLBACK_EVENT_INQUIRY_STOP_IND:
            // Shall not happen
            break;

        case SRV_A2DP_CALLBACK_EVENT_STREAM_START_IND:
            // not support
            break;
    };

    switch (state)
    {
        case PB_STATE_BT_CONNECTING:
            pThis->doPlay();
            break;
        
        case PB_STATE_BT_CONNECTING_WHILE_PLAYING:
            pThis->setPlayState(PB_STATE_PLAY);
            break;

        case PB_STATE_BT_CONNECTING_WHILE_RESUME:
            pThis->doResume();
            break;

        case PB_STATE_BT_CONNECTING_WHILE_INTERRUPTED:
            pThis->setPlayState(PB_STATE_INTERRUPTED);
            pThis->resumeInterruptPlay();
            break;

        default:
            /*
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
                (WCHAR *)VFX_WSTR_RES("Invalid playback state").getBuf());
            */
            break;
    };

    VappMusicPlayerApp *app = getMusicPlayerApp();
    if (!pThis->m_isAppMode || !app || (app->getActionMode() != ACTION_LAUNCHING && app->getActionMode() != ACTION_LAUNCHING_FROM_BG))
    {
        pThis->m_signalShowHideWaitIcon.emit(VFX_FALSE, VFX_FALSE);
    }    
    
#endif
}

void VappMusicPlayerCtrlPlayback::openA2DP()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_OPEN_A2DP);

#if defined(__MMI_A2DP_SUPPORT__)
    // Get samplerate and stereo when open

    m_signalShowHideWaitIcon.emit(VFX_TRUE, VFX_TRUE);

    m_isA2DPOpen = VFX_TRUE;

    srv_a2dp_open(
        vapp_a2dp_get_bt_headset(), 
        m_sampleRate, 
        m_stereo, 
        &VappMusicPlayerCtrlPlayback::onBTOpenCallback, 
        MMI_TRUE
        );
#endif
}

void VappMusicPlayerCtrlPlayback::closeA2DP(VfxBool notifyOpener)
{
#if defined(__MMI_A2DP_SUPPORT__)
    if (m_isA2DPOpen)
    {
        //A2DP is opened by music player
        srv_a2dp_close_codec();
        srv_a2dp_close((MMI_BOOL)notifyOpener);
        
        m_isA2DPOpen = VFX_FALSE;
    }
#endif
}

S32 VappMusicPlayerCtrlPlayback::BTAudEventHandler(BtAudEvent event, U32 arg, void *user_data)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_CTRLPLAYBACK_BT_AUD_EVENT_HDLR, event);

#if defined(__MMI_A2DP_SUPPORT__)
    VappMusicPlayerCtrlPlayback* ptr = (VappMusicPlayerCtrlPlayback*)handleToObject((VfxObjHandle)user_data);
    if (ptr)
    {
        if (event == BTAUD_EV_STEREO_CONFIG_IND)
        {
            PlaybackStateEnum state = ptr->getPlayState();
            if (state == PB_STATE_PLAY)
            {
                ptr->setPlayState(PB_STATE_BT_CONNECTING_WHILE_PLAYING);
                ptr->openA2DP();
                return VFX_TRUE;
            }
        }    
    }
#endif
    return VFX_FALSE;
}

VappMusicPlayerSoundEffect* VappMusicPlayerCtrlPlayback::getCtrlSoundEffect()
{
    return m_ctrlSoundEffect;
}

#endif //__COSMOS_MUSICPLY__
