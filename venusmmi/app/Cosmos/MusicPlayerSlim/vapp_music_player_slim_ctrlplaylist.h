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
 *  vapp_music_player_slim_ctrlplaylist.h
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

#ifndef __VAPP_MUSIC_PLAYER_CTRL_PLAYLIST_H__
#define __VAPP_MUSIC_PLAYER_CTRL_PLAYLIST_H__

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_music_player_slim_dataDef.h"


extern "C"
{
#include "MusicPlaylistGprot.h"
}

/* library state, or operation. */
typedef enum
{
    PL_STATE_OPEN,    /* opening the  playlist library file */
    PL_STATE_NORMAL,  /* currently doing nothing, can transfer to any other states. */
    PL_STATE_ADD,     /* adding file. */
    PL_STATE_DELETE,  /* deleting file. */
    PL_STATE_NONE     /* init state. */
}PlaylistStateEnum;

/*----------------------------------------------------------------------------------------
 para define
------------------------------------------------------------------------------------------*/
class VappMusicPlayerCtrlPlaylist : public VfxObject
{
    VFX_DECLARE_CLASS(VappMusicPlayerCtrlPlaylist);

/* Variables. */
private:

    plst_handle m_plstSrvHandle;       // play list service handle
    PlaylistStateEnum m_playlistState; // play list service library state, or ctrl-playlist state
    void *m_plstSrvMemPtr;             // Memory pool for PLSV
    KAL_ADM_ID m_admID;                // ADM ID for plst service memory

public:

    VfxSignal3 <MusicPlayCBEvtEnum, S32, VfxU32> m_signalCtrlPlaylist; // Signal for playlist callback

/* Constractor & desstructor. */
public:
    VappMusicPlayerCtrlPlaylist() :
        m_plstSrvHandle(0),
        m_playlistState(PL_STATE_NONE),
        m_plstSrvMemPtr(NULL)
    { };

/* over write. */
public:
    virtual void onInit();
    virtual void onDeinit();

/* Implementations. */
private:
    void deInitPlaylistService(void);
    S32 initPlaylistService(void);
    void static onPlaylistSrvCallback(void* user_data, srv_playlist_cb_evt_enum cb_event, S32 result, VfxU32 ca_para_2);
    void setPlaylistState(PlaylistStateEnum state);
    VfxS32 pickNextActiveItem(VfxS32 &index, VfxWString &filePath, VfxBool isNext, VfxBool isAuto);
    MusicPlayRetEnum getErrorMsg(S32 result);
    
/* Public Methods. */
public:

    /* open playlist file. */
    VfxS32 openLibrary(void);
    void closeLibrary(void);

    PlaylistStateEnum getPlaylistState(void);

    /* set and get shufle & repeat mode. */
    void setRepeatMode(srv_playlist_repeat_enum repeat);
    void setShuffleMode(srv_playlist_shuffle_enum shuffle); 
    srv_playlist_repeat_enum getRepeatMode();
    srv_playlist_shuffle_enum getShuffleMode();

    /* multi select. */
    void selectStart();
    void selectEnd();
    void selectAll();
    void deselectAll();
    void select(VfxU32 index);
    void deselect(VfxU32 index);
    VfxBool isSelected(VfxU32 index);
    VfxBool isSelectedAll(void);

    /* add and delete file. */
    VfxS32 addFile(VfxWString fileName);
    VfxS32 addFromFolder(VfxWString folderName);
    VfxS32 addFileCancel(void);
    VfxS32 delFile(VfxU32 index);
    VfxS32 delSelected(void);
    void delCancel(void); 

    /* get music info. */
    VfxS32 getTitle(const VfxU32 index, VfxWString &title);
    VfxBool getFilePath(VfxU32 index, VfxWString &filePath);  
    VfxU32 getCount();
    VfxS32 setActiveItem(VfxS32 index);
    VfxS32 getActiveItemIndex();
    VfxS32 getActiveItemInfo(VfxS32 &index, VfxWString &filePath);
    VfxS32 getNextActiveItemAuto(VfxS32 &index, VfxWString &title);
    VfxS32 getNextActiveItemManul(VfxS32 &index, VfxWString &title);
    VfxS32 getPrevActiveItemManul(VfxS32 &index, VfxWString &title);
};

#endif  // __VAPP_MUSIC_PLAYER_CTRL_PLAYLIST_H__
#endif  // __MMI_MUSIC_PLAYER_SLIM__
