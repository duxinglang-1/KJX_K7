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
 *  vapp_music_player_cui.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  FTO Music Player CUI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"
#ifdef __COSMOS_MUSICPLY__

#ifndef __VAPP_MUSIC_PLAYER_CUI_H__
#define __VAPP_MUSIC_PLAYER_CUI_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vapp_music_player_nowplaying.h"
#include "vapp_music_player_ctrlplayback.h"
#include "vcp_include.h"
#include "vcp_Form.h"
#include "vcp_list_menu.h"
#include "GlobalResDef.h"
#include "vapp_ncenter.h"

extern "C"
{
#include "AvrcpSrvGprot.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/

/***************************************************************************** 
 * Class VcuiSoundRecorder
 *****************************************************************************/

class VcuiMusicPlayerScreen;

class VcuiMusicPlayer : public VfxCui
{
    VFX_DECLARE_CLASS(VcuiMusicPlayer);

public:
    VcuiMusicPlayerScreen *m_scr;
    VfxBool m_screenClosing;
    VappMusicPlayerCtrlPlayback *m_ctrlPlayback;
    mmi_id m_cuiId;
    VfxBool m_isSongInCard;

private:
    VcpActivityIndicator *m_waitIcon;
    VfxWeakPtr<VfxTimer> m_waitIconTimer;
    VfxBool m_isFileValid;

public:
    VcuiMusicPlayer():
      m_scr(NULL),
      m_screenClosing(VFX_FALSE),
      m_ctrlPlayback(NULL),
      m_cuiId(GRP_ID_INVALID),
      m_isSongInCard(VFX_FALSE),
      m_waitIcon(NULL)
    {};
    
// Override
protected:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onDeinit();
    virtual void onGroupActive(void);
    virtual void onGroupInactive(void);
    virtual mmi_ret onProc(mmi_event_struct *evt);

// Public methods
public:
    void VcuiMusicPlayer::notifyCaller();

    // Set title and subtitle string, subtitle is on the above
    void setTitle(VfxWString str1, VfxWString str2);

    // Update layout
    void updateLayout(VfxBool isPortrait);

    // Receive callback from MDI, for example: END OF FILE, TERMINATED, DURAITON UPDATE...etc
    void onMDICallback(VfxS32 result);

	void onNCenterStatusChanged(VappNCenterEventEnum evt);

    // Return pointer of VcuiMusicPlayerScreen
    VcuiMusicPlayerScreen* getCUIScreen();

    // Return pointer of VappMusicPlayerNowPlayingPage
    VappMusicPlayerNowPlayingPage* getNowPlayingPage();

    // clear now playing page pointer
    void clearNowPlayingPtr(VappMusicPlayerNowPlayingPage *nowPlaying);

    // show hide wait icon
    void onShowHideWaitIcon(VfxBool isShow, VfxBool delayShow);

    // show wait icon
    void showWaitIcon(VfxBool delayShow = VFX_FALSE);

    // hide wait icon
    void hideWaitIcon();

private:
    void postProcess();

#ifdef __MMI_AVRCP_SUPPORT__
    // handle AVRCP commands (blue tooth remote)
    U8 onCuiAVRCPCommand(U8 command_type, srv_avrcp_key_events key_events);

    // for AVRCP events
    static U8 onCuiAVRCPCmdCallback(U8 command_type, srv_avrcp_key_events key_events);
#endif /*__MMI_AVRCP_SUPPORT__*/

    // do show wait icon
    void doShowWaitIcon(VfxTimer *timer);
};


/***************************************************************************** 
 * Class VcuiSoundRecorderScreen
 *****************************************************************************/
class VcuiMusicPlayerScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VcuiMusicPlayerScreen);

private:
    VfxBool m_firstEnter;
    VappMusicPlayerNowPlayingPage *m_nowPlaying;
    VfxWString m_filePath;
    VfxWString m_title;
    VfxWString m_subtitle;

public:
    VcuiMusicPlayerScreen():
      m_firstEnter(VFX_TRUE),
      m_nowPlaying(NULL)
    {};

// Override
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void on1stReady();
    virtual void on2ndReady();    
    virtual void queryRotate(VfxScreenRotateParam &param);

public:
    // Set playback ctrl to now playing page
    void setCtrlPlayback(VappMusicPlayerCtrlPlayback *ctrl);

    // Store file path to play
    void setFilePath(VfxWString &filePath);

    // Store title, subtitle
    void setTitle(VfxWString &title, VfxWString &subtitle);

    // Open the file
    void open();

    // Play the file
    void play();

    // return now playing page
    VappMusicPlayerNowPlayingPage* getNowPlaying();

    // clear now playing page pointer
    void clearNowPlayingPtr(VappMusicPlayerNowPlayingPage *nowPlaying);

// Implementation
private:
    void onNowPlayingCallabck(VfxS32 action);
    
};

#endif /* __VAPP_MUSIC_PLAYER_CUI_H__ */

#endif //__COSMOS_MUSICPLY__
