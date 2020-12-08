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
 *  vapp_music_player_ctrlmediacache.h
 *
 * Project:
 * --------
 *  Media cache control
 *
 * Description:
 * ------------
 *  Media cache control header
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef __VAPP_MUSIC_PLAYER_CTRLMEDIACACHE_H__
#define __VAPP_MUSIC_PLAYER_CTRLMEDIACACHE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"

extern "C"
{
#include "MediaCacheSrvGprot.h"
#include "MediaCacheSrv.h"
#include "gdi_datatype.h"
#include "PlstSrvGprot.h"
}

enum DecodeResult
{
    MC_OK,
    GDI_OK,
    BUSY,
    DECODING,
    EMPTY,
    FORMAT_UNSUPPORTED,
    DRM_LOCKED,
    UNEXPECTED,
    MC_NOT_READY,
};

enum MCStateEnum
{
    RUN,
    PAUSE,
    IDLE,
};

typedef void(*VappMusicPlayerCtrlMediaCacheDecodeCallback)(VfxU32 index, DecodeResult result, VfxImageBuffer imageBuffer, void *user_data);

/***************************************************************************** 
 * Music Player UI componet: Album cover decoding task class
 *****************************************************************************/

class MediaCacheTask
{   
// Variables
public:
    enum ThumbState{
        // default state
        NONE_PROC,

        // getting image buffer from media cache
        PROCESSING,

        // this cell has no alubm cover
        NO_THUMB,

        // this cell is DRM locked
        DRM_THUMB,

        // this cell as album cover
        HAS_THUMB,

        // dump cell
        DUMP
    };

    MediaCacheTask():
        isLocked(VFX_FALSE),
        m_state(NONE_PROC)
        {};

    // current ThumbState
    ThumbState m_state;

    // image buffer
    VfxImageBuffer m_imageBuffer;

    // is this buffer is locked
    VfxBool isLocked;
};

/***************************************************************************** 
 * VappMusicPlayerCtrlMediaCahce is a control to handle none-blocking image decode schedule
 *****************************************************************************/

class VappMusicPlayerCtrlMediaCahce : public VfxObject
{
    VFX_DECLARE_CLASS(VappMusicPlayerCtrlMediaCahce);

// Variables
private:
    // this pointer
    static VappMusicPlayerCtrlMediaCahce* g_this;

    // media cache handle
    srv_handle m_hMediaCache;

    // current state
    MCStateEnum m_state;

    // gdi decode handle
    VfxU32 m_hGdiDecode;

    // heap memory pointer
    void *m_pMediaCacheHeap;

    // cache memory pointer
    void *m_pCachePtr;

    // item count
    VfxU32 m_count;

    // decode result callback
    VappMusicPlayerCtrlMediaCacheDecodeCallback m_decodeCallback;

    // decode result callback user data
    void *m_userData;

    // task array
    MediaCacheTask *m_mcTasks;

public:
    // flag to indicate that media cache 
    VfxBool m_isBusy;

    // temp gdi layer
    gdi_handle m_gdiLayer;

    // the size to resize to
    VfxSize m_imageSize;

    // buffer for JPG draw data
    U8 *m_bufferImage;

    // structure to query album cover from PLSV
    srv_plst_list_get_display_struct m_plsvImageStruct;

    // media cache context struct
    srv_mediacache_cntx_struct *m_mediaCacheContext;

    // media cache cell structure
    srv_mediacache_cell_struct *m_decodingCell;

public:

// Constructor / Destructor
public:
    VappMusicPlayerCtrlMediaCahce():
      m_count(0),
      m_isBusy(NULL),
      m_hMediaCache(0),
      m_state(IDLE),
      m_hGdiDecode(0),
      m_pMediaCacheHeap(NULL),
      m_pCachePtr(NULL),
      m_gdiLayer(0),
      m_imageSize(0, 0),
      m_bufferImage(NULL),
      m_mediaCacheContext(NULL),
      m_decodingCell(NULL),
      m_userData(NULL),
      m_mcTasks(NULL)
      {};

// Public methods
public:
    // initialize media cache service, allocate memory
    void initMediaCache(VfxU32 itemCount, VfxU32 width, VfxU32 height, VfxU32 goToIndex = 0);

    // pause media cache decode scheduling
    void pauseMediaCache();

    // resume media cache decode scheduling
    void resumeMediaCache();

    // close media cahce service, free memory
    void closeMediaCache();

    // set decode result callback
    void setDecodeCallback(VappMusicPlayerCtrlMediaCacheDecodeCallback callback, void *user_data);

    // get cell count
    VfxU32 getCount();

    // get media cache state
    MCStateEnum getState();
    
    // get image buffer of specific index
    DecodeResult getImageBuffer(VfxU32 index, VfxImageBuffer& buffer, VfxBool forceGet = VFX_FALSE);

    // free cache buffer
    VfxBool freeImageBuffer(void* buffer, const VfxU32 index);

    // stop GDI decode and free GDI layer
    void stopGDI();

    // set one task
    void setTask(const VfxU32 index, MediaCacheTask &task);

    // get one task
    MediaCacheTask getTask(const VfxU32 index);

    // find next NONE_PROC task index with specific range
    VfxBool findNextNoneProcTask(const VfxU32 start, const VfxU32 end, VfxU32 &index);

    // reset all task to NON_PROC
    void resetTask();

// Override methods
protected:
    virtual void onInit();
    virtual void onDeinit();
    
// Implementation
private:

    // start running media cache
    void startMediaCache(VfxTimer *timer);

    // ?
    static VfxS32 getDataCallback(S32 index, WCHAR *buffer, U32 length, void *user_data);

    // scheduling decoding function
    static MMI_BOOL decodeCell(
                        U32 *handle,
                        srv_mediacache_cell_struct *cell_p,
                        srv_mediacache_nb_decode_callback done_callback,
                        void *user_data);

    // scheduling decode canceling function
    static MMI_BOOL decodeCellCancel(U32 handle);/////, void* user_data);

    // decode JPG image
    VfxBool decodeImage(
            S32 ret,
            U8 *imgBuffer,
            S32 imgWidth,
            S32 imgHeight,
            S32 bufferSize);

    // callback function for GDI decode complete
    static void gdiDecodeDoneCallback(GDI_RESULT result,gdi_handle handle);

    // ?
    static void onMediaCacheDecodeResult(S32 errGroup, S32 errCode, void *userData);

    // PLSV callback, handle async get image event only
    void onPLSVCallback(srv_plst_cb_evt_enum cb_event, S32 result, VfxU32 ca_para_2);
};


#endif // __VAPP_MUSIC_PLAYER_CTRLMEDIACACHE_H__

#endif //__COSMOS_MUSICPLY__
