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
 *  vapp_gallery_db.h
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

#ifndef __VAPP_GALLERY_DB_H__
#define __VAPP_GALLERY_DB_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "trc/vadp_app_trc.h"
#include "vapp_gallery_setting.h"
#include "vapp_gallery_util.h"

extern "C"
{
#include "FileMgrSrvGprot.h"
#include "FileMgrType.h"

#if defined(__SQLITE3_SUPPORT__)
#include "sqlite3.h"
#include "sqlite3ex.h"
#include "MediaCacheDaemonGprot.h"
#endif
}

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class VappGalleryDB
 *****************************************************************************/
class VappGalleryDB : public VfxObject
{
public:
    enum DBType
    {
        THUMBNAIL,
        PREVIEW,
    };
    
    static void getDBFolderPath(U8 drv, VfxWString &dbFolderPath);
    static void getDBName(VfxWString &dbName, DBType dbType = THUMBNAIL);
    
public:
    VappGalleryDB();
    VappGalleryDB(const U8 currentDrv);
    VappGalleryDB(VappGalleryStorageSetting &storageSetting);
    virtual void onInit();
    virtual void onDeinit();

    void convertPath(WCHAR *src, WCHAR* dst, U32 size);
    void updateItemBookmarkBlocking(WCHAR *path, U32 bookmark_sec);
    void updateItemTotalDurationBlocking(WCHAR *path, U32 totalDuration);
    void getRecentPlayVideoBlocking(ivd_db_video_result_last_play_info *result);
    VfxBool hasItemInfoBlocking(WCHAR *path);
    void getItemInfoBlocking(WCHAR *path, ivd_db_video_result_info *result);
    void setItemInfoBlocking(WCHAR *path, ivd_db_video_result_info *item);
    VfxBool removeItem(WCHAR *path);

    ivd_db_handle_struct* getDBHnadle();

private:
    static const VfxS32 DB_WORKING_BUF_SIZE = 200 * 1024;                     // assign 200 K, need to enlarge if larger blob may be written
    static const VfxS32 IO_BUFFER_SIZE = 128 * 128 * VAPP_GALLERY_THUMB_BPP;  // assume a 128x128 RGB565 pixel buffer
    static const U32 PATH_LENGTH = SRV_FMGR_PATH_MAX_LEN + 1;

    ivd_db_handle_struct m_dbContext;
    U8 *m_pDBWorkingBuf;
    U8 *m_pIOBufPool;
    U8 m_defaultDrv;
    mmi_id m_appId;
    KAL_ADM_ID m_IOBufHeap;

private:
    static void onDBServiceCallback(S32 err, void *user_data)
    {
        return;
    }
};

#endif /* __VAPP_GALLERY_DB_H__ */


