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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_gallery_db.cpp
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 

#ifdef __MMI_FTO_GALLERY__

#include "mmi_rp_vapp_gallery_def.h"
#include "vapp_gallery_db.h"
#include "vcp_include.h"
#include "vcp_list_menu.h"
#include "../xml/vfx_xml_loader.h"
#include "vapp_gallery_db.h"
#include "vapp_gallery_util.h"

extern "C"
{
#include "kal_release.h"

/* FS */
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"

#include "app_datetime.h"
#include "app_str.h"
#include "sqlite3.h"
#include "sqlite3ex.h"
#include "sqlite3kal.h"
}

extern "C"
{
#include "MMI_media_app_trc.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Class VappGalleryDB Implementation
 *****************************************************************************/
VappGalleryDB::VappGalleryDB():
    m_pDBWorkingBuf(NULL),
    m_pIOBufPool(NULL),
    m_defaultDrv(0),
    m_IOBufHeap(NULL)
{

}

VappGalleryDB::VappGalleryDB(const U8 currentDrv):
    m_pDBWorkingBuf(NULL),
    m_pIOBufPool(NULL),
    m_defaultDrv(currentDrv),
    m_IOBufHeap(NULL)
{
}

VappGalleryDB::VappGalleryDB(VappGalleryStorageSetting &storageSetting):
	m_pDBWorkingBuf(NULL),
    m_pIOBufPool(NULL),
    m_defaultDrv(0),
    m_IOBufHeap(NULL)
{
    m_defaultDrv = srv_fmgr_drv_get_letter_by_type(storageSetting.getDefaultStorage(VFX_FALSE));
}

void VappGalleryDB::onInit()
{
    VfxObject::onInit();

    m_appId = findRootAppId(this);
    // assign 200K working buffer to SQLite
    kal_mem_set(&m_dbContext, 0, sizeof(m_dbContext));
    m_pDBWorkingBuf = (U8*)applib_asm_alloc_r(m_appId, DB_WORKING_BUF_SIZE);
    VFX_ASSERT(m_pDBWorkingBuf);
    m_dbContext.db_buffer.buffer = m_pDBWorkingBuf;
    m_dbContext.db_buffer.length = DB_WORKING_BUF_SIZE;
 
    // configuare input / output buffers
    m_dbContext.io_buf.max_length = IO_BUFFER_SIZE;
    const VfxU32 IO_POOL_SIZE = IO_BUFFER_SIZE * 5 / 2;
    m_pIOBufPool = (U8*)applib_asm_alloc_r(m_appId, IO_POOL_SIZE);
    VFX_ASSERT(m_pIOBufPool);
    m_IOBufHeap = kal_adm_create(m_pIOBufPool, IO_POOL_SIZE, NULL, KAL_TRUE);
    
    
    #if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
    // Do not use o_buffer for COSMOS slim
    m_dbContext.io_buf.o_buffer = NULL;
    m_dbContext.io_buf.o_length = 0;
    m_dbContext.io_buf.state = MMI_IVD_IO_BUF_STATE_IDLE;

    // But we need a small buffer to write DB blob
    if(IVD_DB_TEMP_BUF_LEN)
    {
        m_dbContext.db_temp_buf = (U8*)kal_adm_alloc_noncacheable(m_IOBufHeap, IVD_DB_TEMP_BUF_LEN, NULL);;
    }
    else
    {
        m_dbContext.db_temp_buf = NULL;
    }
    #else
    m_dbContext.io_buf.o_buffer = (U8*)kal_adm_alloc_noncacheable(m_IOBufHeap, IO_BUFFER_SIZE, NULL);
    m_dbContext.io_buf.o_length = IO_BUFFER_SIZE;
    m_dbContext.io_buf.state = MMI_IVD_IO_BUF_STATE_IDLE;
    #endif

    
    m_dbContext.io_buf.i_buffer = (U8*)kal_adm_alloc_noncacheable(m_IOBufHeap, IO_BUFFER_SIZE, NULL);
    m_dbContext.io_buf.i_length = IO_BUFFER_SIZE;
    m_dbContext.io_buf.i_state = MMI_IVD_IO_BUF_STATE_IDLE;
    m_dbContext.color_format = GALLERY_GDI_CF_THUMB;
    m_dbContext.bytes_per_pixel = VAPP_GALLERY_THUMB_BPP;
#if defined(__SRV_MEDIACACHE_DEBUG_MEASURE__)
    m_dbContext.is_mark = MMI_TRUE;
#endif

    U8 defaultDrv = m_defaultDrv;
    if(0 == defaultDrv)
    {
        VappGalleryStorageSetting setting;
        defaultDrv = srv_fmgr_drv_get_letter_by_type(setting.getDefaultStorage(VFX_FALSE));
    }    
    VfxWString dbFolder;
    VfxWString dbName;
    getDBFolderPath(defaultDrv, dbFolder);
    getDBName(dbName);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_DB_IVD_IVSRV_DB_START);
    ivd_ivsrv_db_start(&m_dbContext, dbFolder, &onDBServiceCallback, dbName);

    SetProtocolEventHandler(ivd_ivsrv_db_remove_img_rsp_hdler, MSG_ID_IVD_DB_REMOVE_IMG_RSP);
}

void VappGalleryDB::onDeinit()
{
    m_defaultDrv = 0;
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_DB_IVD_IVSRV_DB_CANEL_STOP);
    ivd_ivsrv_db_cancel_get(&m_dbContext);
    ivd_ivsrv_db_cancel_put(&m_dbContext);
    ivd_ivsrv_db_stop(&m_dbContext);
    ClearProtocolEventHandler(MSG_ID_IVD_DB_REMOVE_IMG_RSP);
    kal_adm_free(m_IOBufHeap, m_dbContext.io_buf.i_buffer);
    kal_adm_free(m_IOBufHeap, m_dbContext.io_buf.o_buffer);
    kal_adm_delete(m_IOBufHeap);
    m_IOBufHeap = NULL;
    applib_asm_free_r(m_appId, m_pIOBufPool);
    m_pIOBufPool = NULL;
    applib_asm_free_r(m_appId, m_pDBWorkingBuf);
    m_pDBWorkingBuf = NULL;
    memset(&m_dbContext, 0, sizeof(m_dbContext));

    VfxObject::onDeinit();
}

void VappGalleryDB::convertPath(WCHAR *src, WCHAR* dst, U32 size)
{
    mmi_ucs2ncpy((CHAR*)dst, (CHAR*)src, size - 1);
    dst = (WCHAR*)mmi_ucs2lwr((CHAR*)dst);
}

void VappGalleryDB::updateItemBookmarkBlocking(WCHAR *path, U32 bookmark_sec)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_DB_UPDATE_ITEM_BOOKMARK_BLOCKING);

    WCHAR tPath[PATH_LENGTH];
    convertPath(path, tPath, PATH_LENGTH); 
    ivd_ivsrv_db_update_video_bookmark_blocking(&m_dbContext, tPath, bookmark_sec);
}

void VappGalleryDB::updateItemTotalDurationBlocking(WCHAR *path, U32 totalDuration)
{
    //MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_DB_SET_ITEM_INFO_BLOCKING);
    WCHAR tPath[PATH_LENGTH];
    convertPath(path, tPath, PATH_LENGTH); 
    ivd_ivsrv_db_update_video_total_duration_blocking(&m_dbContext, tPath, totalDuration);
}

void VappGalleryDB::getRecentPlayVideoBlocking(ivd_db_video_result_last_play_info *result)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_DB_GET_RECENT_PLAY_VIDEO_BLOCKING);
    ivd_ivsrv_db_get_most_recent_play_video_blocking(&m_dbContext, result);
}

VfxBool VappGalleryDB::hasItemInfoBlocking(WCHAR *path)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_DB_HAS_ITEM_INFO_BLOCKING);
    ivd_db_video_result_has_info result;
    kal_mem_set(&result, 0, sizeof(result));

    WCHAR tPath[PATH_LENGTH];
    convertPath(path, tPath, PATH_LENGTH); 
    ivd_ivsrv_db_has_video_info_blocking(&m_dbContext, tPath, &result);
    
    return (MMI_IVD_OK == result.result_code
            && MMI_TRUE == result.has_video_info);
}

void VappGalleryDB::getItemInfoBlocking(WCHAR *path, ivd_db_video_result_info *result)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_DB_GET_ITEM_INFO_BLOCKING);

    WCHAR tPath[PATH_LENGTH];
    convertPath(path, tPath, PATH_LENGTH);
    ivd_ivsrv_db_get_video_info_blocking(&m_dbContext, tPath, result);
}

void VappGalleryDB::setItemInfoBlocking(WCHAR *path, ivd_db_video_result_info *item)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_DB_SET_ITEM_INFO_BLOCKING);

    WCHAR tPath[PATH_LENGTH];
    convertPath(path, tPath, PATH_LENGTH);
    ivd_ivsrv_db_put_video_info_blocking(&m_dbContext, (WCHAR*)tPath, item);
}

VfxBool VappGalleryDB::removeItem(WCHAR *path)
{
    WCHAR tPath[PATH_LENGTH];
    convertPath(path, tPath, PATH_LENGTH);
    ivd_ivsrv_db_remove_video_info_by_name(&m_dbContext, (WCHAR*)tPath, &onDBServiceCallback, getObjHandle());
    return VFX_TRUE; 
}

void VappGalleryDB::getDBFolderPath(U8 drv, VfxWString &dbFolderPath)
{
    // FIXME: should use the input drive as root of dbFolderPath
    S32 drvType = srv_fmgr_drv_get_type(drv);
    const WCHAR* drvPath = srv_fmgr_drv_get_path_by_type((srv_fmgr_drv_type_enum)drvType);
    if(NULL == drvPath)
    {
        return;
    }

    dbFolderPath = VFX_WSTR_MEM(drvPath);
    WCHAR* pathBuf = dbFolderPath.lockBuf(SRV_FMGR_PATH_MAX_LEN + 1);
    VfxWString folderName = VFX_WSTR("Gallery");
    srv_fmgr_path_append_ex(pathBuf, sizeof(WCHAR) * (SRV_FMGR_PATH_MAX_LEN + 1), folderName.getBuf(), MMI_FALSE);
    dbFolderPath.unlockBuf();
}

void VappGalleryDB::getDBName(VfxWString &dbName, DBType dbType)
{
    switch(dbType)
    {
    case THUMBNAIL:
        dbName = VFX_WSTR("Gallery.db");
        break;
    case PREVIEW:
        dbName = VFX_WSTR("GalleryPreview.db");
        break;   
    }
}

ivd_db_handle_struct* VappGalleryDB::getDBHnadle()
{
    return (&m_dbContext);
}
#endif