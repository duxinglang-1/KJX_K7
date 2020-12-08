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
 *  vapp_music_player_slim_ctrlplaylist.cpp
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

#include "Vfx_config.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "drm_errcode.h"
#include "mmi_frm_mem_gprot.h"
#include "vapp_music_player_slim_ctrlplaylist.h"

extern "C"
{
#include "gdi_include.h"
}


static VfxU8 g_playlistSRVMemPool[SRV_PLAYLIST_MIN_MEM_SIZE];


/***************************************************************************** 
 * VappMusicPlayerCtrlPlaylist Implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappMusicPlayerCtrlPlaylist", VappMusicPlayerCtrlPlaylist, VfxObject);



/*****************************************************************************
 * FUNCTION
 *  onInit
 * DESCRIPTION
 *  class init virtual func
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/ 
void VappMusicPlayerCtrlPlaylist::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_PLAYLIST_INIT);
    VfxObject::onInit();

    setPlaylistState(PL_STATE_NONE);    
    (void)initPlaylistService();
}

/*
 class deinit func
*/
void VappMusicPlayerCtrlPlaylist::onDeinit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_PLAYLIST_DEINIT);
    deInitPlaylistService();

    VfxObject::onDeinit();
}

void VappMusicPlayerCtrlPlaylist::setPlaylistState(PlaylistStateEnum state)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_PLAYLIST_SET_STATE, state);
    m_playlistState = state;
}

PlaylistStateEnum VappMusicPlayerCtrlPlaylist::getPlaylistState()
{
    return m_playlistState;
}

/*****************************************************************************
 * FUNCTION
 *  deInitPlaylistService
 * DESCRIPTION
 *  destory service instance, free memory, deregister callback, close library.
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/ 
void VappMusicPlayerCtrlPlaylist::deInitPlaylistService()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_PLAYLIST_DEINIT_PLSTSRV);

    /* close library and destory playlist service handle. */
    if (m_plstSrvHandle)
    {
        (void)srv_playlist_deregister_callback(m_plstSrvHandle);
        (void)srv_playlist_close_library(m_plstSrvHandle);
        (void)srv_playlist_destroy_instance(m_plstSrvHandle);
        m_plstSrvHandle = 0;
    }

    /* free adm memory. */
    if (m_admID)
    {
        kal_adm_delete(m_admID);
        m_admID = 0;
    }

    if (m_plstSrvMemPtr)
    {
        memset(m_plstSrvMemPtr, 0x00, SRV_PLAYLIST_MIN_MEM_SIZE);
        m_plstSrvMemPtr = NULL;
    }
    
    setPlaylistState(PL_STATE_NONE);
}

/*****************************************************************************
 * FUNCTION
 *  initPlaylistService
 * DESCRIPTION
 *  create service instance, alloc memory for it, the memory must be adm memory, \
 *  and register callback func.
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/ 
S32 VappMusicPlayerCtrlPlaylist::initPlaylistService()
{
    srv_playlist_create_struct createInfo = {0};
    VfxU32 memSize = SRV_PLAYLIST_MIN_MEM_SIZE; // Shoule equal or larget than SRV_PLAYLIST_MIN_MEM_SIZE
    S32 nRet = SRV_PLAYLIST_OK;

    /* init create para for service. */
    m_plstSrvMemPtr = g_playlistSRVMemPool;
    memset(m_plstSrvMemPtr, 0x00, SRV_PLAYLIST_MIN_MEM_SIZE);
    m_admID = kal_adm_create(m_plstSrvMemPtr, memSize, NULL, KAL_FALSE);
    createInfo.mem_ptr = (void*)m_admID;
    createInfo.mem_size = SRV_PLAYLIST_MIN_MEM_SIZE;
    createInfo.gen_mem_size = 0;
    createInfo.max_item_support = 0; // defined by service, 1024

    nRet = srv_playlist_create_instance(&createInfo, (U32*)&m_plstSrvHandle);
    if (SRV_PLAYLIST_OK != nRet)
    {
        VFX_ASSERT(0);
    }

    /* register playlist service notify event callback func. */
    (void)srv_playlist_register_callback(m_plstSrvHandle, 
                 (cb_func)&VappMusicPlayerCtrlPlaylist::onPlaylistSrvCallback, 
                 (void *)this
                 );

    /* before opend, the state must be none, will be changed to normal after open. */
    setPlaylistState(PL_STATE_NONE);
    
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_PLAYLIST_INIT_PLSTSRV);
    return nRet;
}

/*****************************************************************************
 * FUNCTION
 *  onPlaylistSrvCallback
 * DESCRIPTION
 *  callback func for play list service notify event, ctrl-playlist will handle first, \
 *  then transfer and send to its listener handle it.
 * PARAMETERS
 *  cb_event  :  [IN]  openration type
 *  result    :  [IN]  operate result
 *  ca_para_2 :  [IN]  secondary para, commonly is the completed number
 * RETURNS
 *  void
 *****************************************************************************/ 
void VappMusicPlayerCtrlPlaylist::onPlaylistSrvCallback(void* user_data, srv_playlist_cb_evt_enum cb_event, S32 result, VfxU32 ca_para_2)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_PLAYLIST_PLSTSRV_CB, cb_event, result, ca_para_2);

    VappMusicPlayerCtrlPlaylist *pThis = reinterpret_cast<VappMusicPlayerCtrlPlaylist*>(user_data);
    MusicPlayCBEvtEnum evt = MUSIC_CB_MAX;
    MusicPlayRetEnum ret = MUSIC_RET_OK;
    
    // TODO: error handler
    /* handle the common errors here. */

    /* 1. ctrl-palylist handle the event first. */
    switch (cb_event)
    {
        case SRV_PLAYLIST_CB_EVT_OPEN:
        {
            pThis->setPlaylistState(PL_STATE_NORMAL);
            evt = MUSIC_CB_OPEN;
            ret = pThis->getErrorMsg(result);
            break;
        }

        case SRV_PLAYLIST_CB_EVT_ADD:
        {
            pThis->setPlaylistState(PL_STATE_NORMAL);
            evt = MUSIC_CB_ADD;
            ret = pThis->getErrorMsg(result);
            break;
        }

        case SRV_PLAYLIST_CB_EVT_DELETE:
        {
            pThis->setPlaylistState(PL_STATE_NORMAL);
            evt = MUSIC_CB_DELETE;
            ret = pThis->getErrorMsg(result);
            break;
        }

        case SRV_PLAYLIST_CB_EVT_DELETE_ACTIVE:
        {
            pThis->setPlaylistState(PL_STATE_NORMAL);
            evt = MUSIC_CB_DELETE_ACTIVE;
            ret = MUSIC_RET_FAILED;
            break;
        }

        case SRV_PLAYLIST_CB_EVT_DELETE_PROGRESS:
        {
            /* delete progress, saved in ca_para_2. */
            evt = MUSIC_CB_DELETE_PROGRESS;
            break;
        }

        case SRV_PLAYLIST_CB_EVT_MSDC_PLUG_OUT:
        {
        #ifndef __MMI_MUSIC_PLAYER_PHONE_DRIVE__
            pThis->setPlaylistState(PL_STATE_NONE);
        #else
            pThis->setPlaylistState(PL_STATE_NORMAL);
        #endif  // __MMI_MUSIC_PLAYER_PHONE_DRIVE__
        
            evt = MUSIC_CB_MSDC_PLUG_OUT;
            break;
        }

        case SRV_PLAYLIST_CB_EVT_MSDC_PLUG_IN:
        {
            evt = MUSIC_CB_MSDC_PLUG_IN;
            break;
        }

        case SRV_PLAYLIST_CB_EVT_PRE_FORMAT:
        {        
            pThis->setPlaylistState(PL_STATE_NONE);
            evt = MUSIC_CB_EVT_PRE_FORMAT;
            break;
        }

        case SRV_PLAYLIST_CB_EVT_AFT_FORMAT:
        {        
            pThis->setPlaylistState(PL_STATE_NORMAL);
            evt = MUSIC_CB_EVT_AFT_FORMAT;
            break;
        }

        default:
            break;
    }

    /* 2. notify lisener. */
    pThis->m_signalCtrlPlaylist.emit(evt, ret, ca_para_2);
}

VfxS32 VappMusicPlayerCtrlPlaylist::openLibrary()
{
    S32 nRet = MUSIC_RET_FAILED;
    S32 result = SRV_PLAYLIST_OK;

    if (!m_plstSrvHandle)
    {
        return MUSIC_RET_ERR_BAD_PARA;
    }

    if (PL_STATE_OPEN == m_playlistState)
    {
        nRet = MUSIC_RET_OK;
    }

    result = srv_playlist_open_library(m_plstSrvHandle);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_PLAYLIST_OPEN_LIBRARY, result);
    nRet = getErrorMsg(result);
    if (MUSIC_RET_OK == nRet)
    {
        setPlaylistState(PL_STATE_NORMAL);
    }
    else if (MUSIC_RET_ASYNC == nRet)
    {
        setPlaylistState(PL_STATE_OPEN);
    }

    return nRet;
}

void VappMusicPlayerCtrlPlaylist::closeLibrary()
{
    if (!m_plstSrvHandle)
    {
        return;
    }

    (void)srv_playlist_close_library(m_plstSrvHandle);
}

/*
 get index music title.
*/
VfxS32 VappMusicPlayerCtrlPlaylist::getTitle(const VfxU32 index, VfxWString &title)
{
    UI_string_type buffer = NULL;
    S32 nRet = SRV_PLAYLIST_OK;
    VfxS32 result = MUSIC_RET_OK;;

    if (!m_plstSrvHandle)
    {
        return VFX_FALSE;
    }

    /* check DB state. */
    if (PL_STATE_NORMAL != m_playlistState)
    {
        return VFX_FALSE;
    }

    VFX_ALLOC_MEM(buffer, sizeof(UI_character_type)*SRV_PLAYLIST_MAX_PATH_LEN, this);

    nRet = srv_playlist_get_item_title(m_plstSrvHandle, index, buffer);
    result = getErrorMsg(nRet);
    if (MUSIC_RET_OK == result)
    {
        title.loadFromMem(buffer);
    }
    else
    {
        title.format("");
    }
    
    VFX_FREE_MEM(buffer);
    buffer = NULL;
    return result;
}

VfxBool VappMusicPlayerCtrlPlaylist::getFilePath(VfxU32 index, VfxWString &filePath)
{
    UI_string_type buffer = NULL;
    S32 nRet = SRV_PLAYLIST_OK;
    VfxBool result = VFX_FALSE;

    if (!m_plstSrvHandle)
    {
        return VFX_FALSE;
    }

    /* check DB state. */
    if (PL_STATE_NORMAL != m_playlistState)
    {
        return VFX_FALSE;
    }

    VFX_ALLOC_MEM(buffer, sizeof(UI_character_type)*SRV_PLAYLIST_MAX_PATH_LEN, this);
    
    nRet = srv_playlist_get_item_path(m_plstSrvHandle, index, buffer);
    if (SRV_PLAYLIST_OK != nRet)
    {
        filePath.format("");
        result = VFX_FALSE;
    }
    else
    {
        filePath.loadFromMem(buffer);
        result = VFX_TRUE;
    }

    VFX_FREE_MEM(buffer);
    buffer = NULL;
    return result;
}

VfxU32 VappMusicPlayerCtrlPlaylist::getCount()
{
    S32 nRet = SRV_PLAYLIST_OK;

    if (!m_plstSrvHandle)
    {
        return 0;
    }

    /* check DB state. */
    if (PL_STATE_NORMAL != m_playlistState)
    {
        return 0;
    }

    nRet = srv_playlist_get_list_count(m_plstSrvHandle);
    if (nRet < 0)
    {
        return 0;
    }
    
    return nRet;
}

void VappMusicPlayerCtrlPlaylist::setRepeatMode(srv_playlist_repeat_enum repeat)
{
    if (!m_plstSrvHandle)
    {
        return;
    }
    
    (void)srv_playlist_config_repeat(m_plstSrvHandle, repeat);
}

void VappMusicPlayerCtrlPlaylist::setShuffleMode(srv_playlist_shuffle_enum shuffle)
{
    if (!m_plstSrvHandle)
    {
        return;
    }
    
    (void)srv_playlist_config_shuffle(m_plstSrvHandle, shuffle);
}

srv_playlist_repeat_enum VappMusicPlayerCtrlPlaylist::getRepeatMode()
{
    if (!m_plstSrvHandle)
    {
        return SRV_PLAYLIST_REPEAT_OFF;
    }
    
    return srv_playlist_get_repeat(m_plstSrvHandle);
}

srv_playlist_shuffle_enum VappMusicPlayerCtrlPlaylist::getShuffleMode()
{
    if (!m_plstSrvHandle)
    {
        return SRV_PLAYLIST_SHUFFLE_OFF;
    }
    
    return srv_playlist_get_shuffle(m_plstSrvHandle);
}

/*
 multi select mark begin.
*/
void VappMusicPlayerCtrlPlaylist::selectStart()
{
    if (!m_plstSrvHandle)
    {
        return;
    }

    (void)srv_playlist_multi_select_mark_begin(m_plstSrvHandle);
}

/*
 multi select mark end.
*/
void VappMusicPlayerCtrlPlaylist::selectEnd()
{
    if (!m_plstSrvHandle)
    {
        return;
    }

    (void)srv_playlist_multi_select_mark_end(m_plstSrvHandle);
}

/*
 multi select mark all.
*/
void VappMusicPlayerCtrlPlaylist::selectAll()
{
    if (!m_plstSrvHandle)
    {
        return;
    }

    (void)srv_playlist_multi_select_mark_all(m_plstSrvHandle, MMI_TRUE); 
}

/*
 multi de-select mark all.
*/
void VappMusicPlayerCtrlPlaylist::deselectAll()
{
    if (!m_plstSrvHandle)
    {
        return;
    }

    (void)srv_playlist_multi_select_mark_all(m_plstSrvHandle, MMI_FALSE); 
}

void VappMusicPlayerCtrlPlaylist::select(VfxU32 index)
{
    if (!m_plstSrvHandle)
    {
        return;
    }

    (void)srv_playlist_multi_select_set_mark(m_plstSrvHandle, index, MMI_TRUE);
}

void VappMusicPlayerCtrlPlaylist::deselect(VfxU32 index)
{
    if (!m_plstSrvHandle)
    {
        return;
    }

    (void)srv_playlist_multi_select_set_mark(m_plstSrvHandle, index, MMI_FALSE);
}

VfxBool VappMusicPlayerCtrlPlaylist::isSelected(VfxU32 index)
{
    MMI_BOOL bMarked = MMI_FALSE;
    VfxBool nRet = VFX_TRUE;

    if (!m_plstSrvHandle)
    {
        return MMI_FALSE;
    }

    bMarked = srv_playlist_multi_select_get_mark(m_plstSrvHandle, index);
    nRet = ((MMI_TRUE == bMarked) ? VFX_TRUE : VFX_FALSE);
    return nRet;
}

VfxBool VappMusicPlayerCtrlPlaylist::isSelectedAll()
{
    MMI_BOOL selectedAll = MMI_FALSE;
    VfxBool nRet = VFX_TRUE;

    if (!m_plstSrvHandle)
    {
        return MMI_FALSE;
    }

    selectedAll = srv_playlist_multi_select_get_mark_all(m_plstSrvHandle);
    nRet = ((MMI_TRUE == selectedAll) ? VFX_TRUE : VFX_FALSE);
    return nRet;
}

/*
 delete index file.
*/
VfxS32 VappMusicPlayerCtrlPlaylist::delFile(VfxU32 index)
{
    S32 nRet = MUSIC_RET_FAILED;

    if (!m_plstSrvHandle)
    {
        return MUSIC_RET_ERR_BAD_PARA;
    }

    /* check DB state. */
    if (PL_STATE_NORMAL != m_playlistState)
    {
        return MUSIC_RET_FAILED;
    }

    nRet = srv_playlist_delete_item(m_plstSrvHandle, index);
    if (SRV_PLAYLIST_ASYNC == nRet)
    {
        setPlaylistState(PL_STATE_DELETE);
        return MUSIC_RET_ASYNC;
    }

    return MUSIC_RET_FAILED;
}

/*
 delete multi selected files.
*/
VfxS32 VappMusicPlayerCtrlPlaylist::delSelected()
{
    S32 nRet = MUSIC_RET_FAILED;

    if (!m_plstSrvHandle)
    {
        return MUSIC_RET_ERR_BAD_PARA;
    }

    /* check DB state. */
    if (PL_STATE_NORMAL != m_playlistState)
    {
        return MUSIC_RET_FAILED;
    }

    nRet = srv_playlist_delete_marked_item(m_plstSrvHandle);
    if (SRV_PLAYLIST_OK == nRet)
    {
        return MUSIC_RET_OK;
    }
    else if (SRV_PLAYLIST_ASYNC == nRet)
    {
        setPlaylistState(PL_STATE_DELETE);
        return MUSIC_RET_ASYNC;
    }

    return MUSIC_RET_FAILED;
}

/*
 cancel current deleting operation.
*/
void VappMusicPlayerCtrlPlaylist::delCancel()
{
    if (!m_plstSrvHandle)
    {
        return;
    }
    
    (void)srv_playlist_delete_cancel(m_plstSrvHandle);
}

/*****************************************************************************
 * FUNCTION
 *  addFile
 * DESCRIPTION
 *  sync operation, add input audio file into current view playlist, \
 *  user should guarantee that it's a file not folder.
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/ 
VfxS32 VappMusicPlayerCtrlPlaylist::addFile(VfxWString fileName)
{
    S32 result = SRV_PLAYLIST_OK;
    VfxS32 nRet = MUSIC_RET_FAILED;

    if ((!m_plstSrvHandle) || (!fileName))
    {
        return MUSIC_RET_ERR_BAD_PARA;
    }

    /* check DB state. */
    if (PL_STATE_NORMAL != m_playlistState)
    {
        return MUSIC_RET_FAILED;
    }

    /* sync add file, not need to change DB state. */
    result = srv_playlist_add_file(m_plstSrvHandle, (WCHAR*)fileName.getBuf());
    nRet = getErrorMsg(result);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_PLAYLIST_ADD_FILE, result);
    return nRet;
}

/*****************************************************************************
 * FUNCTION
 *  addFromFolder
 * DESCRIPTION
 *  async operation, search and add file from input folder, \
 *  service currently support max 16 levels. if you have more folders to search,\
 *  should add one by one in the callback function.
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/ 
VfxS32 VappMusicPlayerCtrlPlaylist::addFromFolder(VfxWString folderName)
{
    S32 result = SRV_PLAYLIST_OK;
    VfxS32 nRet = MUSIC_RET_FAILED;

    if ((!m_plstSrvHandle) || (!folderName))
    {
        return MUSIC_RET_ERR_BAD_PARA;
    }

    /* check DB state. */
    if (PL_STATE_NORMAL != m_playlistState)
    {
        return MUSIC_RET_FAILED;
    }

    /* async add file. */
    result = srv_playlist_add_from_folder(m_plstSrvHandle, (WCHAR*)folderName.getBuf());
    if (SRV_PLAYLIST_ASYNC == result)
    {
        setPlaylistState(PL_STATE_ADD);
        nRet = MUSIC_RET_ASYNC;
    }
    else if (SRV_PLAYLIST_PLST_FULL == result)
    {
        nRet =  MUSIC_RET_LIST_FULL;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_PLAYLIST_ADD_FROMFOLDER, result);
    return nRet;
}

VfxS32 VappMusicPlayerCtrlPlaylist::addFileCancel()
{
    S32 result = SRV_PLAYLIST_OK;
    VfxS32 nRet = MUSIC_RET_FAILED;

    if ((!m_plstSrvHandle) || (PL_STATE_ADD != m_playlistState))
    {
        return MUSIC_RET_FAILED;
    }

    result = srv_playlist_add_file_cancel(m_plstSrvHandle);
    if (SRV_PLAYLIST_ASYNC == result)
    {
        nRet = MUSIC_RET_ASYNC;
    }
    else
    {
        nRet = MUSIC_RET_FAILED;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_PLAYLIST_ADD_CANCEL, result);
    return nRet;
}

VfxS32 VappMusicPlayerCtrlPlaylist::setActiveItem(VfxS32 index)
{
    S32 nRet = MUSIC_RET_OK;

    if (!m_plstSrvHandle)
    {
        return MUSIC_RET_ERR_BAD_PARA;
    }

    /* check DB state. */
    if (PL_STATE_NORMAL != m_playlistState)
    {
        return MUSIC_RET_FAILED;
    }
    
    nRet = srv_playlist_set_as_active(m_plstSrvHandle, index);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_PLAYLIST_SET_ACTIVEITEM, index, nRet);
    return (VfxS32)nRet;
}

VfxS32 VappMusicPlayerCtrlPlaylist::getActiveItemIndex()
{
    S32 nRet = MUSIC_RET_OK;

    if (!m_plstSrvHandle)
    {
        return MUSIC_RET_ERR_BAD_PARA;
    }

    nRet = srv_playlist_get_active_index(m_plstSrvHandle);
    return (VfxS32)nRet;
}

VfxS32 VappMusicPlayerCtrlPlaylist::getActiveItemInfo(VfxS32 &index, VfxWString &filePath)
{
    UI_string_type buffer = NULL;
    S32 nRet = SRV_PLAYLIST_OK;
    VfxBool result = VFX_FALSE;

    if (!m_plstSrvHandle)
    {
        return VFX_FALSE;
    }

    VFX_ALLOC_MEM(buffer, sizeof(UI_character_type)*SRV_PLAYLIST_MAX_PATH_LEN, this);

    nRet = srv_playlist_get_active_info(m_plstSrvHandle, (S32 *)&index, buffer);
    if (SRV_PLAYLIST_OK != nRet)
    {
        filePath.format("");
        result = VFX_FALSE;
    }
    else
    {
        filePath.loadFromMem(buffer);
        result = VFX_TRUE;
    }

    VFX_FREE_MEM(buffer);
    buffer = NULL;
    return result;
}

VfxS32 VappMusicPlayerCtrlPlaylist::pickNextActiveItem(VfxS32 &index, VfxWString &filePath, VfxBool isNext, VfxBool isAuto)
{
    UI_string_type buffer = NULL;
    S32 nRet = SRV_PLAYLIST_OK;
    VfxS32 result = MUSIC_RET_OK;

    if (!m_plstSrvHandle)
    {
        return MUSIC_RET_ERR_BAD_PARA;
    }

    VFX_ALLOC_MEM(buffer, sizeof(UI_character_type)*SRV_PLAYLIST_MAX_PATH_LEN, this);

    /* get next active item index and file path, set it as active. */
    if (isAuto)
    {
        nRet = srv_playlist_get_next_auto(m_plstSrvHandle, (S32 *)&index, buffer);
    }
    else if (isNext)
    {
        nRet = srv_playlist_get_next_manul(m_plstSrvHandle, (S32 *)&index, buffer);
    }
    else
    {
        nRet = srv_playlist_get_prev_manul(m_plstSrvHandle, (S32 *)&index, buffer);
    }

    /* check result. */
    if (SRV_PLAYLIST_OK == nRet)
    {
        filePath.loadFromMem(buffer);
        result = MUSIC_RET_OK;
    }
    else if (SRV_PLAYLIST_NEXT_LOOP == nRet)
    {
        filePath.loadFromMem(buffer);
        result = MUSIC_RET_NEXT_LOOP;
    }
    else if (SRV_PLAYLIST_END == nRet)
    {
        /* reach the end of current list. */
        filePath.format("");
        result = MUSIC_RET_LIST_END;
    }
    else
    {
        /* read failed, invalid file. */
        filePath.format("");
        result = MUSIC_RET_FAILED;
    }

    VFX_FREE_MEM(buffer);
    buffer = NULL;
    return result;
}

VfxS32 VappMusicPlayerCtrlPlaylist::getNextActiveItemAuto(VfxS32 &index, VfxWString &filePath)
{
    return pickNextActiveItem(index, filePath, VFX_TRUE, VFX_TRUE);
}

VfxS32 VappMusicPlayerCtrlPlaylist::getNextActiveItemManul(VfxS32 &index, VfxWString &filePath)
{
    return pickNextActiveItem(index, filePath, VFX_TRUE, VFX_FALSE);
}

VfxS32 VappMusicPlayerCtrlPlaylist::getPrevActiveItemManul(VfxS32 &index, VfxWString &filePath)
{
    return pickNextActiveItem(index, filePath, VFX_FALSE, VFX_FALSE);
}

MusicPlayRetEnum VappMusicPlayerCtrlPlaylist::getErrorMsg(S32 result)
{
    MusicPlayRetEnum nRet = MUSIC_RET_FAILED;

    switch (result)
    {
        case SRV_PLAYLIST_PLST_FULL:
        {
            nRet = MUSIC_RET_LIST_FULL;
            break;
        }

        case SRV_PLAYLIST_ERR_MEMORY_NOT_ENOUGH:
        {
            nRet = MUSIC_RET_MEMORY_FULL;
            break;
        }

        case SRV_PLAYLIST_ERR_FS_ERROR:
        {
            nRet = MUSIC_RET_ERR_LIST_DAMAGE;
            break;
        }

        case SRV_PLAYLIST_ERR_FILE_DAMAGE:
        {
            nRet = MUSIC_RET_ERR_LIST_DAMAGE;
            break;
        }

        case SRV_PLAYLIST_MSDC_NOTEXIST:
        {
            nRet = MUSIC_RET_MSDC_NOTEXIST;
            break;
        }

        case SRV_PLAYLIST_ERR_UNSUPPORTED_FILE:
        {
            nRet = MUSIC_RET_UNSUPPORTED_FILE;
            break;
        }

        case SRV_PLAYLIST_ASYNC:
        {
            nRet = MUSIC_RET_ASYNC;
            break;
        }

        case SRV_PLAYLIST_OK:
        {
            nRet = MUSIC_RET_OK;
            break;
        }

        default:
        {
            nRet = MUSIC_RET_FAILED;
            break;
        }
    }

    return nRet;
}

#endif  // __MMI_MUSIC_PLAYER_SLIM__
