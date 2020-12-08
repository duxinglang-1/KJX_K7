/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_widget_key_image_viewer_cache.h
 *
 * Project:
 * --------
 *  MAUI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_WIDGET_KEY_IMAGE_VIEWER_CACHE_H
#define VAPP_WIDGET_KEY_IMAGE_VIEWER_CACHE_H

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_KEY_IMAGE_VIEWER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_widget_key_image_viewer_def.h"
#include "vapp_widget_key_image_viewer_mem_cfg.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "FileMgrSrvGProt.h"
#include "MediaCacheSrvGprot.h"

#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * VappWidgetKeyImageViewerCache
 *****************************************************************************/

class VappWidgetKeyImageViewerCache : public VfxObject
{
    VFX_DECLARE_CLASS(VappWidgetKeyImageViewerCache);

/*----------------------------------------------------------------*/
/* File List                                                      */
/*----------------------------------------------------------------*/

public:

    VappWidgetKeyImageViewerCache() :
        m_pFileListBuf(NULL),
        m_mediaCacheHandle(NULL),
        m_isOverSortLimit(VFX_FALSE),
        m_pMediaCacheBuf(NULL)
    {

    }

public:

    VfxU32 getImageCount();

    SRV_FMGR_FILELIST_HANDLE getFileList();

    VfxBool startCache(
        VfxS32 imgIdx
    );

    void stopCache(
        VfxBool isDestroyFileList
    );

    static mmi_ret fmgrEventHdlr(
        mmi_event_struct *evt
    );

    void fileListRefreshHdlr(
        mmi_event_struct *evt
    );

private: 

    VfxBool getFolderPath();

    VfxBool createFileList();

    void reset();

    void freeFileList();

public:

    VfxSignal1<VappWidgetKeyImageViewerMsgEnum> m_signalMsg;
    
    static SRV_FMGR_FILELIST_HANDLE m_fileListHandle;

private:

    void    *m_pFileListBuf;
    VfxS32   m_startIdx;
    VfxWChar m_pFolderBuf[SRV_FMGR_PATH_MAX_LEN + 1];
    
    static VfxU16 m_storage;
    static VfxU32 m_imgCount;

/*----------------------------------------------------------------*/
/* Media Cache                                                    */
/*----------------------------------------------------------------*/

public:

    static void imageClipHdlr(
        VfxU32* handle, 
        VfxS32 *layer_w, 
        VfxS32 *layer_h, 
        srv_mediacache_rect_struct *img_org, 
        srv_mediacache_rect_struct *img_resized, 
        void *user_data
    );

    VfxS32 lockImageBufferBlock(
        srv_mediacache_image_source_enum source, 
        VfxS32 imgIdx,
        void** buffer
    );

    VfxS32 lockImageBufferNonBlock(
        srv_mediacache_image_source_enum source, 
        srv_mediacache_data_cb cb,
        void *user_data,
        VfxS32 imgIdx,
        void** buffer
    );

    VfxS32 unlockImageBuffer(
        void* buffer
    );

    VfxS32 getImageInfo(
        VfxS32 imgIdx,
        VfxS32 *resized_width, 
        VfxS32 *resized_height
    );

    VfxS32 getErrorCode(
        VfxS32 ret
    );

    void goToIndex(VfxS32 idx);

private:

    void createMediaCache();

    void destroyMediaCahce();

/*----------------------------------------------------------------*/
/* Variables                                                      */
/*----------------------------------------------------------------*/

public:

    //VfxSignal0 m_signalCacheStarted;

private:

    srv_handle m_mediaCacheHandle;
    VfxBool    m_isOverSortLimit;
    void      *m_pMediaCacheBuf;

};


#endif

#endif

