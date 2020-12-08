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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  MediaCacheDaemon.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Image Viewer Daemon.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "MediaCacheSrvGprot.h"
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)

#include "kal_general_types.h"
#include "stack_config.h"
#include "stack_ltlcom.h"
#include "app_ltlcom.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "kal_trace.h"
#include "string.h"
#include "lcd_sw_inc.h"
#include "fs_func.h"
#include "kal_release.h"
#include "Unicodexdcl.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "mmi_media_app_trc.h"
#include "gdi_const.h"
#include "fs_type.h"
#include "lcd_sw_rnd.h"
#include "MediaCacheSrvMem.h"
#include "task_main_func.h"
#include "task_config.h"
#include "syscomp_config.h"
#include "app_datetime.h"

#include "sqlite3.h"
#include "sqlite3ex.h"
#include "sqlite3kal.h"
#include "MMIDataType.h"
#include "custom_events_notify.h"
#include "FileMgrGProt.h"

#include "MediaCacheSrvGprot.h"

#include "MediaCacheDaemonGprot.h"
#include "MediaCacheDaemon.h"

/***************************************************************************** 
* Options
*****************************************************************************/
#if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
// Support 32K page and out-of memory blob writing
#define __SRV_MEDIACACHE_SQL_LARGE_PAGE__
#endif

/***************************************************************************** 
* Local Variable
*****************************************************************************/
ivd_iv_cntx_struct g_ivd_db_cntx;
static MMI_BOOL g_use_early_cancel = MMI_FALSE;

static const CHAR ivd_iv_db_cmd_create_image_base[] = 
    "CREATE TABLE IF NOT EXISTS image_base(filename TEXT PRIMARY KEY NOT NULL UNIQUE, height INTEGER, width INTEGER, o_height INTEGER, o_width INTEGER, file_time INTEGER, file_date INTEGER, file_size INTEGER, update_time INTEGER, update_date INTEGER,  crc INTEGER, data BLOB, data_length INTEGER, err_group INTEGER, err_code INTEGER)";
static const CHAR ivd_iv_db_cmd_create_image_base_filename_idx[] = 
    "CREATE INDEX IF NOT EXISTS idx_filename ON image_base (filename)";
static const CHAR ivd_iv_db_cmd_create_image_base_filename_idx2[] = 
    "CREATE INDEX IF NOT EXISTS idx_update_date ON image_base (update_date)";
static const CHAR ivd_iv_db_cmd_insert_img[] = 
    "INSERT INTO image_base(filename, height, width, o_height, o_width, file_time, file_date, file_size, update_time, update_date, crc, data, data_length, err_group, err_code) values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
static const CHAR ivd_iv_db_cmd_query_img_by_filename[] = 
    "SELECT filename, height, width, o_height, o_width, file_time, file_date, file_size, update_time, update_date, crc, err_group, err_code FROM image_base WHERE filename=?";
static const CHAR ivd_iv_db_cmd_get_img_by_filename[] = 
    "SELECT * FROM image_base WHERE filename=?";
static const CHAR ivd_iv_db_cmd_del_img_before_the_date[] = 
    "DELETE FROM image_base WHERE update_date<?";
static const CHAR ivd_iv_db_cmd_del_img_by_name[] = 
    "DELETE FROM image_base WHERE filename=?";
//static const CHAR ivd_iv_db_cmd_query_all[] = 
    //"SELECT * FROM image_base";
static const CHAR ivd_iv_db_cmd_query_verno[] = 
    "SELECT * FROM db_ver";
static const CHAR ivd_iv_db_cmd_insert_verno[] = 
    "INSERT INTO db_ver(verno, width, height) values(?,?,?)";
static const CHAR ivd_iv_db_cmd_begin_transcation[] = 
    "BEGIN TRANSACTION";
static const CHAR ivd_iv_db_cmd_commit_transcation[] = 
    "COMMIT TRANSACTION";
static const CHAR ivd_iv_db_cmd_end_transcation[] = 
    "END TRANSACTION";
static const CHAR ivd_iv_db_cmd_is_meta_existed[] = 
    "SELECT * FROM meta";        
    
#ifdef __COSMOS_MMI_PACKAGE__
static const CHAR ivd_iv_db_cmd_create_video_info[] =\
    "CREATE TABLE IF NOT EXISTS video_info(filename TEXT PRIMARY KEY UNIQUE, folder_id INTEGER, duration_sec INTEGER, bookmark_sec INTEGER, jpeg_thumb BLOB, thumb_size_bytes INTEGER, access_time REAL, file_size INTEGER);"\
    "CREATE TABLE IF NOT EXISTS folder_info(id INTEGER PRIMARY KEY UNIQUE, folder_path TEXT NOT NULL)";

static const CHAR ivd_iv_db_cmd_create_video_info_indices[] =\
    "CREATE INDEX IF NOT EXISTS idx_access_time ON video_info (access_time);";

static MMI_BOOL ivd_iv_db_get_video_info(ivd_db_video_msg_base *ilm_ptr);
static MMI_BOOL ivd_iv_db_put_video_info(ivd_db_video_msg_base *video_info);
static void ivd_iv_db_handle_video_msg(ilm_struct *ilm_ptr);
#endif

#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
static const CHAR ivd_iv_db_cmd_create_meta[] = 
    "CREATE TABLE IF NOT EXISTS meta(filename TEXT PRIMARY KEY, data BLOB, buf_length INTEGER, update_time INTEGER, update_date INTEGER)";
static const CHAR ivd_iv_db_cmd_insert_meta[] = 
    "INSERT INTO meta(filename, data, buf_length, update_time, update_date) values(?,?,?,?,?)";
static const CHAR ivd_iv_db_cmd_get_meta_by_filename[] = 
    "SELECT * FROM meta WHERE filename=?";
static const CHAR ivd_iv_db_cmd_del_meta_by_name[] = 
    "DELETE FROM meta WHERE filename=?";
static const CHAR ivd_iv_db_cmd_del_meta_before_the_date[] = 
    "DELETE FROM meta WHERE update_date<?";
#endif
extern MMI_BOOL srv_mediacache_is_current_cache_using_ies(void); //this is for special request. for db campatibility

static GDI_RESULT ivd_iv_db_encode_image_to_data_buffer(
                                    ivd_db_handle_struct *db_handle,
                                    S32 *buffer_size_out,
                                    U8 *image_ptr,
                                    U8 image_color_format,
                                    S32 image_width,
                                    S32 image_height
                                    );

/***************************************************************************** 
* Local Variable
*****************************************************************************/
#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
void ivd_ivsrv_db_put_meta(ivd_db_meta_info_struct *meta_info, ivd_req_callback callback, void* user_data);
void ivd_iv_db_put_meta(ilm_struct *ilm_ptr);
S32 ivd_iv_db_write_meta2db(ivd_db_put_meta_req_struct *local_para_ptr);
MMI_BOOL ivd_iv_db_get_meta(ilm_struct *ilm_ptr);
S32 ivd_iv_db_get_meta_by_filename(PS8 o_buffer, CHAR *filename);
S32 ivd_iv_db_del_meta_by_name(CHAR *path);
#endif /* __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__ */

#ifdef __COSMOS_MMI_PACKAGE__
static MMI_BOOL ivd_iv_db_remove_video_info_by_filename(ivd_db_handle_struct* db_handle, const WCHAR* filename);
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_ivsrv_create
 * DESCRIPTION
 *  image viewer service create function 
 * PARAMETERS
 *  buffer      [IN]    buffer for sqlite database usage
 *  length      [IN]    length of buffer
 *  en_update   [IN]    enable update picture to database
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL ivd_iv_db_check_need_jpeg(U32 width, U32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
    return MMI_TRUE;
#endif


#ifndef __MTK_TARGET__
    return MMI_FALSE;
#else
    return MMI_TRUE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivsrv_create
 * DESCRIPTION
 *  image viewer service create function 
 * PARAMETERS
 *  buffer      [IN]    buffer for sqlite database usage
 *  length      [IN]    length of buffer
 *  en_update   [IN]    enable update picture to database
 * RETURNS
 *  void
 *****************************************************************************/
void ivd_iv_db_send_msg(module_type src, module_type dst, U32 msg_id, void *local_param_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = allocate_ilm(src);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr->src_mod_id = src;
    ilm_ptr->dest_mod_id = dst;
    ilm_ptr->sap_id = MMI_MMI_SAP;
    ilm_ptr->msg_id = (msg_type)msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*)local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;
    
    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  ivd_iv_db_sqlite3_exec
 * DESCRIPTION
 *  sqlite exec
 * PARAMETERS
 *  command     [IN]    SQL command want to run
 *  callback    [IN]    callback function
 * RETURNS
 *  SQLITE error code
 *****************************************************************************/
static S32 ivd_iv_db_sqlite3_exec(const CHAR* command, sqlite3_callback callback)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    CHAR* error_msg = NULL;
    
    SRV_MEDIACACHE_START_MEASURE("DSE");

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "[IVSRV]DB IVD sqlite3_exec, cmd = [%s], cb = [%d].\n", command, callback);
    ret = sqlite3_exec(g_ivd_db_cntx.g_ivd_db_handle_p->db, command, callback, 0, &error_msg);
    if (ret != SQLITE_OK)
    {
        kal_prompt_trace(MOD_MMI,"[IVSRV]DB IVD prepare failed! SQLite error msg: %s", error_msg);
        sqlite3_free(error_msg);
    }
    SRV_MEDIACACHE_STOP_MEASURE("DSE");
    return ret;
}

static MMI_BOOL ivd_ivsrv_db_check_free_space(U8 drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_DiskInfo disk_info;
    U64 disk_free_space = 0;
    S32 fs_ret = 0;
    UI_character_type path[10] = {0};
    S32 req_size = 1 * 1024 * 1024;     // 1MB limit
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_wsprintf(path, "%c:\\", drv_letter);    
    fs_ret = FS_GetDiskInfo((kal_uint16*)path, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

    if (fs_ret < 0)
    {
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SRVMC][IVD] ivd_ivsrv_db_check_free_space, invalid free space");
        return MMI_FALSE;
    }
    else
    {        
        disk_free_space = disk_info.FreeClusters * 
                          disk_info.SectorsPerCluster * 
                          disk_info.BytesPerSector;
        if (disk_free_space < req_size + disk_info.BytesPerSector)    /* more a sector free space to keep file system other operation normal. */
        {
            kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SRVMC][IVD] ivd_ivsrv_db_check_free_space, low free space");
            return MMI_FALSE;
        }
        else
        {
            kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SRVMC][IVD] ivd_ivsrv_db_check_free_space, sufficient free space");
            return MMI_TRUE;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  ivd_iv_db_open_create_db
 * DESCRIPTION
 *  image viewer daemon open database
 * PARAMETERS
 *  path      [IN]    database filepath
 * RETURNS
 *  void
 *****************************************************************************/
void ivd_iv_db_open_create_db(CHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sqlite3_stmt *stmt_p = NULL;
    S32 ret = MMI_IVD_OK, meta_ret = MMI_IVD_OK;
    CHAR* cmd = (CHAR*)ivd_iv_db_cmd_query_verno;
    CHAR* cmd_insert = (CHAR*)ivd_iv_db_cmd_insert_verno;
    U32 ver = 0;
    U32 witdh = 0, height = 0;
    MMI_BOOL need_renew = MMI_FALSE, meta_exist = MMI_FALSE;
    const int MAX_SUPPORTED_CLUSTER_SIZE = 32 * 1024;
    MMI_BOOL is_enough_free_space = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_MEDIACACHE_START_MEASURE("DBS");
    is_enough_free_space = ivd_ivsrv_db_check_free_space(path[0]);
    
    SRV_MEDIACACHE_START_MEASURE("DBA");
    sqlite3_init_instance(
        &(g_ivd_db_cntx.g_ivd_db_handle_p->db_instance), 
        g_ivd_db_cntx.g_ivd_db_handle_p->db_buffer.buffer, 
        g_ivd_db_cntx.g_ivd_db_handle_p->db_buffer.length, 
        0);
    sqlite3_enter_instance(&(g_ivd_db_cntx.g_ivd_db_handle_p->db_instance));
    ret = sqlite3_open16(path, &(g_ivd_db_cntx.g_ivd_db_handle_p->db));
    SRV_MEDIACACHE_STOP_MEASURE("DBA");
    if (ret != SQLITE_OK)
    {
        SRV_MEDIACACHE_STOP_MEASURE("DBS");
        return;
    }
    SRV_MEDIACACHE_START_MEASURE("DBb");
    ret = sqlite3_prepare(
        g_ivd_db_cntx.g_ivd_db_handle_p->db,
        cmd,
        strlen(cmd),
        &stmt_p,
        NULL);
    ret = sqlite3_step(stmt_p);
    if (ret == SQLITE_ROW)
    {
        ver     = sqlite3_column_int64(stmt_p, 0);
        witdh   = sqlite3_column_int64(stmt_p, 1);
        height  = sqlite3_column_int64(stmt_p, 2);
    }
    if (stmt_p != NULL)
    {
        sqlite3_finalize(stmt_p);
    }
    SRV_MEDIACACHE_STOP_MEASURE("DBb");
    /*
     IES related use, for this case, if you use not ies DB in ies project. 
     and if you use ies db in not ies project, it is disallowed too.
     this is disallowed, so I will remove DB andcreate 
     */
    cmd = (CHAR*)ivd_iv_db_cmd_is_meta_existed;
    meta_ret = sqlite3_prepare(
        g_ivd_db_cntx.g_ivd_db_handle_p->db,
        cmd,
        strlen(cmd),
        &stmt_p,
        NULL);
    meta_ret = sqlite3_step(stmt_p);
    if (meta_ret != SQLITE_MISUSE)
    {
        meta_exist = MMI_TRUE;
    }
    if (stmt_p != NULL)
    {
        sqlite3_finalize(stmt_p);
    }

    if (srv_mediacache_is_current_cache_using_ies())
    {
        if (meta_exist == MMI_FALSE)
        {
            need_renew = MMI_TRUE;
            //here means you use ies, but do not have meta table, maybe use not ies DB
        }
    }
    else
    {
        if (meta_exist == MMI_TRUE)
        {
            need_renew = MMI_TRUE;
            //here means you do not use ies, but have meta table, maybe use ies DB
        }
    }

    if (ret != SQLITE_ROW || ver != IVD_DATABASE_VER_4_DB || witdh != LCD_WIDTH || height != LCD_HEIGHT || need_renew)
    {
        SRV_MEDIACACHE_START_MEASURE("DBC");
        sqlite3_close(g_ivd_db_cntx.g_ivd_db_handle_p->db);
        g_ivd_db_cntx.g_ivd_db_handle_p->is_db_inited = MMI_FALSE;
        ret = FS_Delete((const WCHAR*)path);
        if (ret < 0)
        {
            SRV_MEDIACACHE_STOP_MEASURE("DBS");
            return;
        }
        ret = sqlite3_open16(path, &(g_ivd_db_cntx.g_ivd_db_handle_p->db));
        if (ret < 0)
        {
            SRV_MEDIACACHE_STOP_MEASURE("DBS");
            return;
        }
        #if defined(__SRV_MEDIACACHE_SQL_LARGE_PAGE__)
        do{
            int clusterSize = FS_GetClusterSize(path[0]);
            if(clusterSize > MAX_SUPPORTED_CLUSTER_SIZE)
            {
                clusterSize = MAX_SUPPORTED_CLUSTER_SIZE;
            }
            kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SRVMC][IVD] ivd_iv_db_open_create_db, cluster size[%d]", clusterSize);
            
            if(g_ivd_db_cntx.g_ivd_db_handle_p->io_buf.max_length <= clusterSize)
            {
                char page_pragma_stmt[50] = {0};
                kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SRVMC][IVD] ivd_iv_db_open_create_db, use large page size");
                kal_sprintf(page_pragma_stmt, "PRAGMA page_size = %d", clusterSize);
                ret = ivd_iv_db_sqlite3_exec(page_pragma_stmt, NULL);
                if(is_enough_free_space)
                {
                    // disable journal mode with low free space may cause SQLite to hang
                    ret = ivd_iv_db_sqlite3_exec("PRAGMA journal_mode = OFF", NULL);
                }
            }
            else
            {
                // larger than cluster.
                // this means we may write very large blob.
                // when writing very large blob, a larger page size consumes more RAM.
                // so here we use 2K page size.
                kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SRVMC][IVD] ivd_iv_db_open_create_db, use 2K page size");
                ret = ivd_iv_db_sqlite3_exec("PRAGMA page_size = 2048", NULL);
                if(is_enough_free_space)
                {
                    // disable journal mode with low free space may cause SQLite to hang
                    ret = ivd_iv_db_sqlite3_exec("PRAGMA journal_mode = OFF", NULL);
                }
            }
        }while(0);
        #else
        ret = ivd_iv_db_sqlite3_exec("PRAGMA page_size = 2048", NULL);
        #endif
        ret = ivd_iv_db_sqlite3_exec("CREATE TABLE db_ver(verno INTEGER,width INTEGER,height INTEGER)", NULL);
        if (ret != SQLITE_OK)
        {
            SRV_MEDIACACHE_STOP_MEASURE("DBS");
            return;
        }
        ret = sqlite3_prepare(
            g_ivd_db_cntx.g_ivd_db_handle_p->db,
            cmd_insert,
            strlen(cmd_insert),
            &stmt_p,
            NULL);
        ret = sqlite3_bind_int(stmt_p, 1, IVD_DATABASE_VER_4_DB);
        ret = sqlite3_bind_int(stmt_p, 2, LCD_WIDTH);
        ret = sqlite3_bind_int(stmt_p, 3, LCD_HEIGHT);
        ret = sqlite3_step(stmt_p);
        if (stmt_p != NULL)
        {
            sqlite3_finalize(stmt_p);
        }
        SRV_MEDIACACHE_STOP_MEASURE("DBC");
    }
    else
    {
        #if defined(__SRV_MEDIACACHE_SQL_LARGE_PAGE__)
        if(is_enough_free_space)
        {
            // disable journal mode with low free space may cause SQLite to hang
            ret = ivd_iv_db_sqlite3_exec("PRAGMA journal_mode = OFF", NULL);
        }
        #endif
    }
    SRV_MEDIACACHE_START_MEASURE("DBD");
    ret = ivd_iv_db_sqlite3_exec(ivd_iv_db_cmd_create_image_base, NULL);
    SRV_MEDIACACHE_STOP_MEASURE("DBD");
    if (ret != SQLITE_OK)
    {
        SRV_MEDIACACHE_STOP_MEASURE("DBS");
        return;
    }
    
    #if !defined(__SRV_MEDIACACHE_SQL_LARGE_PAGE__)
    SRV_MEDIACACHE_START_MEASURE("DBE");
    ret = ivd_iv_db_sqlite3_exec(ivd_iv_db_cmd_create_image_base_filename_idx, NULL);
    SRV_MEDIACACHE_STOP_MEASURE("DBE");
    #endif
    
    if (ret != SQLITE_OK)
    {
        SRV_MEDIACACHE_STOP_MEASURE("DBS");
        return;
    }

#ifdef __COSMOS_MMI_PACKAGE__
    SRV_MEDIACACHE_START_MEASURE("DBF");
    // create My Video related info table
    ret = ivd_iv_db_sqlite3_exec(ivd_iv_db_cmd_create_video_info, NULL);
    SRV_MEDIACACHE_STOP_MEASURE("DBF");
    if (ret != SQLITE_OK)
    {
        SRV_MEDIACACHE_STOP_MEASURE("DBS");
        return;
    }

    SRV_MEDIACACHE_START_MEASURE("DBG");
    ret = ivd_iv_db_sqlite3_exec(ivd_iv_db_cmd_create_video_info_indices, NULL);
    SRV_MEDIACACHE_STOP_MEASURE("DBG");
		if (ret != SQLITE_OK)
    {
        SRV_MEDIACACHE_STOP_MEASURE("DBS");
        return;
    }
#endif /* __COSMOS_MMI_PACKAGE__ */
	
#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__ 
    if (srv_mediacache_is_current_cache_using_ies())
    {
        ret = ivd_iv_db_sqlite3_exec(ivd_iv_db_cmd_create_meta, NULL);
        if (ret != SQLITE_OK)
        {
            SRV_MEDIACACHE_STOP_MEASURE("DBS");
            return;
        }
    }
#endif
    SRV_MEDIACACHE_START_MEASURE("DBH");
    ret = ivd_iv_db_sqlite3_exec(ivd_iv_db_cmd_create_image_base_filename_idx2, NULL);
    SRV_MEDIACACHE_STOP_MEASURE("DBH");
    if (ret != SQLITE_OK)
    {
        SRV_MEDIACACHE_STOP_MEASURE("DBS");
        return;
    }
   
    g_ivd_db_cntx.g_ivd_db_handle_p->is_db_inited = MMI_TRUE;
    SRV_MEDIACACHE_STOP_MEASURE("DBS");
}


/*****************************************************************************
 * FUNCTION
 *  ivd_iv_db_close_stop_db
 * DESCRIPTION
 *  image viewer daemon stop database
 * PARAMETERS
 *  null
 * RETURNS
 *  void
 *****************************************************************************/
void ivd_iv_db_close_stop_db(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int maxMem = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    maxMem = (int)sqlite3_memory_highwater(1);
    #if defined(__SRV_MEDIACACHE_SQL_LARGE_PAGE__)
    sqlite3_finalize(g_ivd_db_cntx.g_ivd_db_handle_p->query_stmt);
    g_ivd_db_cntx.g_ivd_db_handle_p->query_stmt = NULL;
    #endif
    
    sqlite3_close(g_ivd_db_cntx.g_ivd_db_handle_p->db);
    sqlite3_exit_instance(&(g_ivd_db_cntx.g_ivd_db_handle_p->db_instance));
    sqlite3_free_instance(&(g_ivd_db_cntx.g_ivd_db_handle_p->db_instance));
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SRVMC][IVD] ivd_iv_db_close_stop_db end, max mem = %d", maxMem);
    g_ivd_db_cntx.g_ivd_db_handle_p->is_db_inited = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  ivd_iv_db_start
 * DESCRIPTION
 *  image viewer database start msg process handler
 * PARAMETERS
 *  *ilm_ptr    [IN]    msg pointer
 * RETURNS
 *  void
 *****************************************************************************/
void ivd_iv_db_start(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_start_req_struct *local_para_ptr;
    ivd_db_start_rsp_struct *rsp_local_para_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_para_ptr = (ivd_db_start_req_struct*)ilm_ptr->local_para_ptr;
    g_ivd_db_cntx.g_ivd_db_handle_p = local_para_ptr->db_handle;
    g_ivd_db_cntx.g_ivd_db_handle_p->is_db_stopping = MMI_FALSE;
    ivd_iv_db_open_create_db(local_para_ptr->path);
    ivd_iv_db_sqlite3_exec(ivd_iv_db_cmd_begin_transcation, NULL);
    rsp_local_para_ptr = (ivd_db_start_rsp_struct*) construct_local_para(sizeof(ivd_db_start_rsp_struct), TD_CTRL);
    rsp_local_para_ptr->callback = local_para_ptr->callback;
    rsp_local_para_ptr->db_handle = g_ivd_db_cntx.g_ivd_db_handle_p;
    if (g_ivd_db_cntx.g_ivd_db_handle_p->is_db_inited == MMI_TRUE)
    {
        rsp_local_para_ptr->error_code = 0;
    }
    else
    {
        rsp_local_para_ptr->error_code = -1;
    }
    ivd_iv_db_send_msg(MOD_IVD, MOD_MMI, MSG_ID_IVD_DB_START_RSP, rsp_local_para_ptr);
    
}


/*****************************************************************************
 * FUNCTION
 *  ivd_iv_db_stop
 * DESCRIPTION
 *  image viewer database stop msg process handler
 * PARAMETERS
 *  *ilm_ptr    [IN]    msg pointer
 * RETURNS
 *  void
 *****************************************************************************/
void ivd_iv_db_stop(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_stop_req_struct *local_para_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_MEDIACACHE_START_MEASURE("DB1");
    local_para_ptr = (ivd_db_stop_req_struct*)ilm_ptr->local_para_ptr;
    g_ivd_db_cntx.g_ivd_db_handle_p = local_para_ptr->db_handle;
    g_ivd_db_cntx.g_ivd_db_handle_p->is_db_stopping = MMI_TRUE;
    ivd_iv_db_sqlite3_exec(ivd_iv_db_cmd_end_transcation, NULL);
    ivd_iv_db_close_stop_db();
    g_use_early_cancel = MMI_FALSE;    // reset early cancel flag
    SRV_MEDIACACHE_STOP_MEASURE("DB1");
    kal_set_eg_events(g_ivd_db_cntx.g_ivd_iv_event,IVD_IV_DATABASE_STOP,KAL_OR);
}


/*****************************************************************************
 * FUNCTION
 *  ivd_iv_db_query_img_by_filename
 * DESCRIPTION
 *  image viewer database query image by filename
 * PARAMETERS
 *  filename    [IN]    file want to query
 *  *file_info  [OUT]   *file_info of image
 * RETURNS
 *  MMI_IVD_OK  find the file
 *  MMI_IVD_ERR_EMPTY   file not found
 *****************************************************************************/
S32 ivd_iv_db_query_img_by_filename(CHAR *filename, ivd_iv_file_info_struct *file_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sqlite3_stmt *stmt_p = NULL;
    S32 ret = MMI_IVD_OK;
    const CHAR *cmd = (CHAR*)ivd_iv_db_cmd_query_img_by_filename;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = sqlite3_prepare(
        g_ivd_db_cntx.g_ivd_db_handle_p->db,
        cmd,
        strlen(cmd),
        &stmt_p,
        NULL);
    if (ret == 0)
    {
        ret = sqlite3_bind_text16(stmt_p, 1, filename, mmi_ucs2strlen(filename) * 2, SQLITE_STATIC);
        ret = sqlite3_step(stmt_p);
    }
    if (ret == SQLITE_ROW)
    {
        /* table image_base                                                                                         
         *0         1       2      3         4        5          6          7          8            9            10 
         *filename, height, width, o_height, o_width, file_time, file_date, file_size, update_time, update_date, crc,
          11         12   
          err_group, err_code*/
        file_info->height =  sqlite3_column_int64(stmt_p, 1);
        file_info->width =  sqlite3_column_int64(stmt_p, 2);
        file_info->o_height =  sqlite3_column_int64(stmt_p, 3);
        file_info->o_width =  sqlite3_column_int64(stmt_p, 4);
        file_info->file_time =  sqlite3_column_int64(stmt_p, 5);
        file_info->file_date =  sqlite3_column_int64(stmt_p, 6);
        file_info->file_size =  sqlite3_column_int64(stmt_p, 7);
        file_info->update_time =  sqlite3_column_int64(stmt_p, 8);
        file_info->update_date =  sqlite3_column_int64(stmt_p, 9);
        file_info->crc =  sqlite3_column_int64(stmt_p, 10);
        file_info->err_group =  sqlite3_column_int64(stmt_p, 11);
        file_info->err_code =  sqlite3_column_int64(stmt_p, 12);
    }
    else
    {
        ret = MMI_IVD_ERR_EMPTY;
    }
    if (stmt_p != NULL)
    {
        sqlite3_finalize(stmt_p);
    }
    return ret;
}

void ivd_ivsrv_db_config_early_cancel(MMI_BOOL useEarlyCancel)
{
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SRVMC]ivd_ivsrv_db_config_early_cancel = %d", useEarlyCancel);
    g_use_early_cancel = useEarlyCancel;
}

static MMI_BOOL should_continue_db_operation(S32 reqId)
{
    if(MMI_TRUE == g_use_early_cancel)
    {
        if(g_ivd_db_cntx.g_ivd_db_handle_p->is_db_stopping == MMI_FALSE
           && reqId == g_ivd_db_cntx.g_ivd_db_handle_p->io_buf.req_seq_id)
        {
            return MMI_TRUE;
        }
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SRVMC]IVD abort db operation, reqId = %d, context_reqId = %d", reqId, g_ivd_db_cntx.g_ivd_db_handle_p->io_buf.req_seq_id);
        return MMI_FALSE;
    }
    else
    {
        if(g_ivd_db_cntx.g_ivd_db_handle_p->is_db_stopping == MMI_FALSE)
        {
            return MMI_TRUE;
        }
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SRVMC]IVD abort db operation due to DB stopping");
        return MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  ivd_iv_db_get_img_by_filename
 * DESCRIPTION
 *  image viewer database get image by filename
 * PARAMETERS
 *  filename    [IN]    file want to query
 *  *file_info  [OUT]   *file_info of image
 * RETURNS
 *  MMI_IVD_OK  find the file
 *  MMI_IVD_ERR_EMPTY   file not found
 *****************************************************************************/
S32 ivd_iv_db_get_img_by_filename(ivd_iv_file_info_struct *file_info, CHAR *filename, S32 reqId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sqlite3_stmt *stmt_p = NULL;
    S32 ret = MMI_IVD_ERR_EMPTY;
    S32 buffer_size;
    gdi_handle src_layer = NULL;
    const CHAR *cmd = ivd_iv_db_cmd_get_img_by_filename;
    U8  *buffer = NULL;
#ifdef __SRV_MEDIACACHE_DEBUG_MEASURE__
    U32 ticks = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(file_info->data != NULL);
    SRV_MEDIACACHE_START_MEASURE("DB3");
#if defined(__SRV_MEDIACACHE_SQL_LARGE_PAGE__)
    if(NULL == g_ivd_db_cntx.g_ivd_db_handle_p->query_stmt)
    {
        ret = sqlite3_prepare(
            g_ivd_db_cntx.g_ivd_db_handle_p->db,
            cmd,
            strlen(cmd),
            &stmt_p,
            NULL);
        g_ivd_db_cntx.g_ivd_db_handle_p->query_stmt = stmt_p;
    }
    else
    {
        ret = 0;
        stmt_p = g_ivd_db_cntx.g_ivd_db_handle_p->query_stmt;
    }
#else
    ret = sqlite3_prepare(
            g_ivd_db_cntx.g_ivd_db_handle_p->db,
            cmd,
            strlen(cmd),
            &stmt_p,
            NULL);
#endif

    if (ret == 0 && MMI_TRUE == should_continue_db_operation(reqId))
    {
        SRV_MEDIACACHE_START_MEASURE("DBQ");
        ret = sqlite3_bind_text16(stmt_p, 1, filename, mmi_ucs2strlen(filename) * 2, SQLITE_STATIC);
        ret = sqlite3_step(stmt_p);
        SRV_MEDIACACHE_STOP_MEASURE("DBQ");
    }
    if (ret == SQLITE_ROW  && MMI_TRUE == should_continue_db_operation(reqId))
    {
        /* table image_base                                                                                                                 *
         *        1         2       3       4           5           6           7           8           9                  10               11     12     13  *
         *(filename, height, width, o_height, o_width, file_time, file_date, file_size, update_time, update_date, crc, data)*/
        SRV_MEDIACACHE_START_MEASURE("DBR");
        file_info->height =  sqlite3_column_int64(stmt_p, 1);
        file_info->width =  sqlite3_column_int64(stmt_p, 2);
        file_info->o_height =  sqlite3_column_int64(stmt_p, 3);
        file_info->o_width =  sqlite3_column_int64(stmt_p, 4);
        file_info->file_time =  sqlite3_column_int64(stmt_p, 5);
        file_info->file_date =  sqlite3_column_int64(stmt_p, 6);
        file_info->file_size =  sqlite3_column_int64(stmt_p, 7);
        file_info->update_time =  sqlite3_column_int64(stmt_p, 8);
        file_info->update_date =  sqlite3_column_int64(stmt_p, 9);
        file_info->crc =  sqlite3_column_int64(stmt_p, 10);
        buffer = (U8*)sqlite3_column_blob(stmt_p, 11);
        buffer_size = sqlite3_column_int64(stmt_p, 12);
        file_info->err_group =  sqlite3_column_int64(stmt_p, 13);
        file_info->err_code =  sqlite3_column_int64(stmt_p, 14);
        SRV_MEDIACACHE_STOP_MEASURE("DBR");
        if (file_info->err_code == 0 && 
            buffer != NULL &&
            file_info->height * file_info->width * g_ivd_db_cntx.g_ivd_db_handle_p->bytes_per_pixel <= g_ivd_db_cntx.g_ivd_db_handle_p->io_buf.i_length &&
            MMI_TRUE == should_continue_db_operation(reqId))
        {
            if (ivd_iv_db_check_need_jpeg(file_info->width, file_info->height) == MMI_TRUE)
            {
                SRV_MEDIACACHE_START_MEASURE("DGI");
                SRV_MEDIACACHE_START_MEASURE("CRL");
                gdi_layer_create_cf_using_outside_memory(
                    g_ivd_db_cntx.g_ivd_db_handle_p->color_format,
                    0,
                    0,
                    file_info->width,
                    file_info->height,
                    &src_layer,
                    file_info->data,
                    file_info->width * file_info->height * g_ivd_db_cntx.g_ivd_db_handle_p->bytes_per_pixel);
                SRV_MEDIACACHE_STOP_MEASURE("CRL");
                gdi_layer_push_and_set_active(src_layer);
                gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
                gdi_layer_clear(GDI_COLOR_BLACK);
                gdi_layer_pop_and_restore_active();
                
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_IVD_INFO_DB_GET_MEM_LENGTH,buffer_size);
                if (MMI_TRUE == should_continue_db_operation(reqId))
                {
                    SRV_MEDIACACHE_START_MEASURE("DB5");
                    //ret = gdi_image_draw_mem(0, 0, buffer, GDI_IMAGE_TYPE_JPG, buffer_size);
                    //changing this , do not using gdi lock
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_IOBUF_HERE_WE_START_TO_USE_UPPER_BUFFER_D, __LINE__);
                    ret = gdi_imgdec_draw_mem(src_layer, 0, 0, buffer, GDI_IMAGE_TYPE_JPG, buffer_size);
                    SRV_MEDIACACHE_STOP_MEASURE("DB5");
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_IVD_INFO_DB_GET_DECODE_MEM,ret);
                }
#ifdef __SRV_MEDIACACHE_DEBUG_MEASURE__
                kal_get_time(&ticks);
                ticks = ticks - g_ivd_db_cntx.g_ivd_db_handle_p->ticks;
#endif

                gdi_layer_free(src_layer);
                SRV_MEDIACACHE_STOP_MEASURE("DGI");
            }
            else
            {
                // DB is raw pixel buffer, no encoding.
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_IOBUF_HERE_WE_START_TO_USE_UPPER_BUFFER_D, __LINE__);                
                memcpy(file_info->data, buffer, file_info->width * file_info->height * g_ivd_db_cntx.g_ivd_db_handle_p->bytes_per_pixel);
                ret = MMI_IVD_OK;
            }

            // Add debug marker
            if (g_ivd_db_cntx.g_ivd_db_handle_p->is_mark &&
                file_info->height > 24 && 
                file_info->width > 24)
            {
                U8* m_data_p = file_info->data;
                U8* m_data_end_p = file_info->data + file_info->width * 24 * g_ivd_db_cntx.g_ivd_db_handle_p->bytes_per_pixel;
                S32 m_pitch = file_info->width * g_ivd_db_cntx.g_ivd_db_handle_p->bytes_per_pixel;
                S32 m_length = 24 * g_ivd_db_cntx.g_ivd_db_handle_p->bytes_per_pixel;
                while (m_data_p<m_data_end_p)
                {
                    memset(m_data_p,0xAA,m_length);
                    m_data_p += m_pitch;
                }
            }
            
            if (ret >= 0)
            {
                ret = MMI_IVD_OK;
            }
        }
    }
    else
    {
        const char *errmsg = sqlite3_errmsg(g_ivd_db_cntx.g_ivd_db_handle_p->db);
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SRVMC][IVD] SQLite line %d: %s", __LINE__, errmsg);
        ret = MMI_IVD_ERR_EMPTY;
    }
    
    if (stmt_p != NULL)
    {
#if defined(__SRV_MEDIACACHE_SQL_LARGE_PAGE__)
        sqlite3_reset(stmt_p);
        sqlite3_clear_bindings(stmt_p);
#else
        sqlite3_finalize(stmt_p);
#endif
    }
    SRV_MEDIACACHE_STOP_MEASURE("DB3");
    return ret;
}

#if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
static void ivd_iv_db_get_temp_file_path(
                                ivd_db_handle_struct *db_handle, 
                                CHAR* path_buf, 
                                U32 buf_size
                                )
{
    ASSERT(buf_size >= IVD_FILE_MAX_PATH_LEN);
    memcpy(path_buf, db_handle->db_cache_folder, IVD_FILE_MAX_PATH_LEN);
    mmi_ucs2cat(path_buf, (CHAR*)L"cache_temp.jpg");
}
#endif

/*****************************************************************************
 * FUNCTION
 *  ivd_iv_db_encode_image_to_data_buffer
 * DESCRIPTION
 *  encode image buffer to data buffer
 * PARAMETERS
 *  db_handle           [IN]    DB handle with valid io_buf. The result is encoded to io_buf.o_buffer
 *  buffer_size_out     [OUT]   encoded data length in bytes
 *  image_ptr           [IN]    image pixel buffer
 *  image_color_format  [IN]    color format of the buffer
 *  image_width         [IN]    width of image, in pixels
 *  image_height        [IN]    height of image, in pixels
 * RETURNS
 *  encoding result
 *****************************************************************************/
static GDI_RESULT ivd_iv_db_encode_image_to_data_buffer(
                                    ivd_db_handle_struct *db_handle,
                                    S32 *buffer_size_out,
                                    U8 *image_ptr,
                                    U8 image_color_format,
                                    S32 image_width,
                                    S32 image_height
                                    )
{
    const S32 image_buf_size = (gdi_bits_per_pixel(image_color_format) / 8) * image_width * image_height;
    if (NULL == buffer_size_out)
    {
        return GDI_FAILED;
    }

    #if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
    if(image_buf_size > IVD_DB_TEMP_BUF_LEN)
    {
        GDI_RESULT ret;
        #ifdef __MTK_TARGET__
        MMI_BOOL is_force_sw_encode = MMI_FALSE;
        #else
        MMI_BOOL is_force_sw_encode = MMI_TRUE;
        #endif

        SRV_MEDIACACHE_START_MEASURE("DEN");
        ASSERT(db_handle->db_temp_buf != NULL);
        ivd_iv_db_get_temp_file_path(db_handle, (CHAR*)db_handle->db_temp_buf, IVD_DB_TEMP_BUF_LEN);

        FS_Delete((WCHAR*)db_handle->db_temp_buf);

        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[IVD] gdi_image_encode_buffer_to_jpeg_with_exp_size begin");
        ret = gdi_image_encode_buffer_to_jpeg_with_exp_size(
                                                        image_ptr, 
                                                        image_width,
                                                        image_height,
                                                        image_color_format,
                                                        (PS8)db_handle->db_temp_buf, 
                                                        image_width * image_height * 2, 
                                                        buffer_size_out,
                                                        is_force_sw_encode);
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[IVD] gdi_image_encode_buffer_to_jpeg_with_exp_size end");
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SRVIVD_ENCODE_JPEG_BUF_RESULT, ret, *buffer_size_out, image_color_format);
        SRV_MEDIACACHE_STOP_MEASURE("DEN");
        return ret;
    }
    #endif
    
    if (ivd_iv_db_check_need_jpeg(image_width, image_height) != MMI_TRUE)
    {
        // DB is raw pixel buffer
        const S32 buf_size = image_width * image_height * db_handle->bytes_per_pixel;
        *buffer_size_out = buf_size;
        memcpy(db_handle->io_buf.o_buffer, image_ptr, buf_size);
        return GDI_SUCCEED;
    }
    else
    {
        GDI_RESULT ret;
        SRV_MEDIACACHE_START_MEASURE("DEN");
        ret = gdi_image_encode_buffer_to_jpeg_in_memory(
                                                        image_ptr, 
                                                        image_width,
                                                        image_height,
                                                        image_color_format,
                                                        #if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
                                                        db_handle->db_temp_buf,
                                                        IVD_DB_TEMP_BUF_LEN,
                                                        #else
                                                        db_handle->io_buf.o_buffer, 
                                                        db_handle->io_buf.o_length, 
                                                        #endif
                                                        buffer_size_out,
                                                        GDI_JPEG_ENCODE_QUALITY_EXCELLENT);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SRVIVD_ENCODE_JPEG_BUF_RESULT, ret, *buffer_size_out, image_color_format);
        SRV_MEDIACACHE_STOP_MEASURE("DEN");
        return ret;
    }
}

/*****************************************************************************
 * FUNCTION
 *  ivd_iv_db_write_img2db
 * DESCRIPTION
 *  image viewer database write image to database
 * PARAMETERS
 *  *local_para_ptr    [IN]    put request
 * RETURNS
 *  MMI_IVD_ERR_PUT_SKIP  write failed
 *  Other   sqlite return code
 *****************************************************************************/
S32 ivd_iv_db_write_img2db(ivd_db_put_img_req_struct *local_para_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sqlite3_stmt *stmt_p = NULL;
    //ivd_iv_file_info_struct file_info;
    S32 buffer_size;
    U32 file_size;
    S32 ret = MMI_IVD_ERR_PUT_SKIP;
    //S32 temp = MMI_IVD_ERR_PUT_SKIP;
    const CHAR *cmd = ivd_iv_db_cmd_insert_img;
    //CHAR *del_cmd = ivd_iv_db_cmd_del_img_by_name;
    FS_HANDLE fs_hdle;
    U8  *buffer = NULL;
    //MMI_BOOL    is_need_update = MMI_FALSE;
    ivd_db_handle_struct *db_handle = NULL;
    MMI_BOOL encode_to_file = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db_handle = local_para_ptr->db_handle;
    if (local_para_ptr->db_handle->io_buf.i_seq_id == local_para_ptr->seq_id)
    {
        SRV_MEDIACACHE_START_MEASURE("FSO");
        fs_hdle = FS_Open((WCHAR*)local_para_ptr->path, FS_READ_ONLY );
        FS_GetFileSize(fs_hdle, &file_size);
        FS_Close(fs_hdle);
        SRV_MEDIACACHE_STOP_MEASURE("FSO");
        local_para_ptr->file_size = file_size;
        if (local_para_ptr->db_handle->is_db_stopping == MMI_FALSE &&
            local_para_ptr->db_handle->io_buf.i_seq_id == local_para_ptr->seq_id)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVD_INFO_DB_NEED_UPDATE);
            ret = sqlite3_prepare(
                db_handle->db,
                cmd,
                strlen(cmd),
                &stmt_p,
                NULL);
            #if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
            if((IVD_DB_TEMP_BUF_LEN < ((gdi_bits_per_pixel(local_para_ptr->color_format) / 8) * local_para_ptr->image_width * local_para_ptr->image_height)))
            {
                encode_to_file = MMI_TRUE;
            }
            else
            {
                encode_to_file = MMI_FALSE;
            }
            #endif
            if (local_para_ptr->err_code == 0)
            {
                ivd_iv_db_encode_image_to_data_buffer(
                                local_para_ptr->db_handle,
                                &buffer_size,
                                local_para_ptr->db_handle->io_buf.i_buffer,
                                local_para_ptr->color_format,
                                local_para_ptr->image_width,
                                local_para_ptr->image_height
                                );
                #if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
                if(!encode_to_file)
                {
                    buffer = db_handle->db_temp_buf;
                }
                else
                {
                    buffer = local_para_ptr->db_handle->io_buf.o_buffer;
                }
                #else
                buffer = local_para_ptr->db_handle->io_buf.o_buffer;
                #endif
            }
            else
            {
                buffer_size = 0;
                buffer = local_para_ptr->db_handle->io_buf.i_buffer;
            }
            if (local_para_ptr->err_code != 0 || buffer_size > 0 && ret == 0 &&
                local_para_ptr->db_handle->io_buf.i_seq_id == local_para_ptr->seq_id &&
                local_para_ptr->db_handle->is_db_stopping == MMI_FALSE)
            {
                /* table image_base                                                                                                 *
                 *     1         2       3       4       5           6           7           8           9       10          11  12  *
                 *(filename, height, width, o_height, o_width, file_time, file_date, file_size, update_time, update_date, crc, data)*/
                /*filename 1 */
                SRV_MEDIACACHE_START_MEASURE("DWR");
                ret = sqlite3_bind_text16(stmt_p, 1, 
                    local_para_ptr->path, 
                    mmi_ucs2strlen(local_para_ptr->path) * 2, 
                    SQLITE_STATIC);
                /*height 2 */
                ret = sqlite3_bind_int(stmt_p, 2, local_para_ptr->image_height);
                /*width 3 */
                ret = sqlite3_bind_int(stmt_p, 3, local_para_ptr->image_width);
                /*o_height 4 */
                ret = sqlite3_bind_int(stmt_p, 4, local_para_ptr->org_image_height);
                /*o_width 5 */
                ret = sqlite3_bind_int(stmt_p, 5, local_para_ptr->org_image_width);
                /*file_time 6 */
                ret = sqlite3_bind_int(stmt_p, 6, local_para_ptr->file_time);
                /*file_date 7 */
                ret = sqlite3_bind_int(stmt_p, 7, local_para_ptr->file_date);
                /*file_size 8 */
                ret = sqlite3_bind_int(stmt_p, 8, local_para_ptr->file_size);
                /*update_time 9 */
                ret = sqlite3_bind_int(stmt_p, 9, local_para_ptr->sys_time);
                /*update_date 10 */
                ret = sqlite3_bind_int(stmt_p, 10, local_para_ptr->sys_date);
                /*crc 11 */
                ret = sqlite3_bind_int(stmt_p, 11, local_para_ptr->file_CRC);
                /*data 12 */
                #if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
                if(MMI_TRUE == encode_to_file)
                {
                    // encode to file
                    ret = sqlite3_bind_zeroblob(stmt_p, 12, buffer_size);
                }
                else
                {
                    // encode to temp buffer directly
                    ret = sqlite3_bind_blob(stmt_p, 12, buffer, buffer_size, SQLITE_STATIC);    
                }
                #else
                ret = sqlite3_bind_blob(stmt_p, 12, buffer, buffer_size, SQLITE_STATIC);
                #endif
                /*data_length 13*/
                ret = sqlite3_bind_int(stmt_p, 13, buffer_size);
                /*err_group 14*/
                ret = sqlite3_bind_int(stmt_p, 14, local_para_ptr->err_group);
                /*err_code 15*/
                ret = sqlite3_bind_int(stmt_p, 15, local_para_ptr->err_code);
                
                if (local_para_ptr->db_handle->io_buf.i_seq_id == local_para_ptr->seq_id &&
                    local_para_ptr->db_handle->is_db_stopping == MMI_FALSE)
                {
                    
                    ret = sqlite3_step(stmt_p);
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVD_INFO_DB_UPDATE_STEP_RET, ret);
                    if (ret != SQLITE_DONE)
                    {
                        const char *errmsg = sqlite3_errmsg(g_ivd_db_cntx.g_ivd_db_handle_p->db);
                        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SRVMC][IVD] SQLite line %d: %s", __LINE__, errmsg);
                        ret = -2;
                    }
                }
                else
                {
                    ret = -1;
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVD_INFO_DB_UPDATE_STEP_RET, 13579);
                }
                SRV_MEDIACACHE_STOP_MEASURE("DWR");
            }
            if (stmt_p != NULL)
            {
                sqlite3_finalize(stmt_p);
            }

            #if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
            // incremental BLOB insert
            do
            {
                sqlite3_blob *pBlob = NULL;
                sqlite3_int64 rowid = 0;
                if(MMI_FALSE == encode_to_file)
                {
                    break;
                }
                rowid = sqlite3_last_insert_rowid(db_handle->db);
                ret = sqlite3_blob_open(
                    db_handle->db,
                    "main",
                    "image_base",
                    "data",
                    rowid,
                    1,          // for read-write
                    &pBlob);
                if(pBlob)
                {
                    // read cluster by cluser
                    U32 written = 0;
                    U32 WRITE_UNIT = IVD_DB_TEMP_BUF_LEN;
                    U32 read = WRITE_UNIT;
                    U8 *temp = NULL;
                    int blobSize = sqlite3_blob_bytes(pBlob);
                    FS_HANDLE hFile = NULL;
                    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[IVD] insert blob begin");
                    // use temp buffer to store path and open file
                    ivd_iv_db_get_temp_file_path(db_handle, (CHAR*)db_handle->db_temp_buf, IVD_DB_TEMP_BUF_LEN);
                    hFile = FS_Open((WCHAR*)db_handle->db_temp_buf, FS_READ_ONLY);
                    // then use temp buffer to read file content into blob
                    temp = db_handle->db_temp_buf;
                    while(hFile > 0 && FS_NO_ERROR == FS_Read(hFile, temp, WRITE_UNIT, &read) && read > 0)
                    {
                        ret = sqlite3_blob_write(pBlob, temp, read, written);
                        written += read;
                    }
                    if(hFile > 0)
                    {
                        FS_Close(hFile);
                        hFile = NULL;
                    }
                    ret = sqlite3_blob_close(pBlob);
                    pBlob = NULL;
                    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[IVD] insert blob end");
                }
            }while(0);
            #endif
            
            SRV_MEDIACACHE_START_MEASURE("Dct");
            ivd_iv_db_sqlite3_exec(ivd_iv_db_cmd_commit_transcation, NULL);
            SRV_MEDIACACHE_STOP_MEASURE("Dct");
            SRV_MEDIACACHE_START_MEASURE("Dbt");
            ivd_iv_db_sqlite3_exec(ivd_iv_db_cmd_begin_transcation, NULL);
            SRV_MEDIACACHE_STOP_MEASURE("Dbt");
        }
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVD_INFO_DB_WRITE_TO_DB_END, ret);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  ivd_iv_db_del_img_before_the_date
 * DESCRIPTION
 *  image viewer database delete file in db that before a date
 * PARAMETERS
 *  date    [IN]    date
 * RETURNS
 *  sqlite return code
 *****************************************************************************/
S32 ivd_iv_db_del_img_before_the_date(U32 date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sqlite3_stmt *stmt_p = NULL;
    S32 ret;
    const CHAR *cmd = ivd_iv_db_cmd_del_img_before_the_date;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_MEDIACACHE_START_MEASURE("DBD");
    ret = sqlite3_prepare(
        g_ivd_db_cntx.g_ivd_db_handle_p->db,
        cmd,
        strlen(cmd),
        &stmt_p,
        NULL);
    if (ret == 0 && g_ivd_db_cntx.g_ivd_db_handle_p->is_db_stopping == MMI_FALSE)
    {
        ret = sqlite3_bind_int(stmt_p, 1, date);
        ret = sqlite3_step(stmt_p);
    }
    if (stmt_p != NULL)
    {
        sqlite3_finalize(stmt_p);
    }
    SRV_MEDIACACHE_STOP_MEASURE("DBD");
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  ivd_iv_db_del_img_by_name
 * DESCRIPTION
 *  image viewer database delete file in db by filename
 * PARAMETERS
 *  path    [IN]    filename
 * RETURNS
 *  sqlite return code
 *****************************************************************************/
S32 ivd_iv_db_del_img_by_name(CHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sqlite3_stmt *stmt_p = NULL;
    S32 ret = 0;
    CHAR* cmd = (CHAR*)ivd_iv_db_cmd_del_img_by_name;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_ivd_db_cntx.g_ivd_db_handle_p)
    {
        return ret;
    }
    ret = sqlite3_prepare(
        g_ivd_db_cntx.g_ivd_db_handle_p->db,
        cmd,
        strlen(cmd),
        &stmt_p,
        NULL);
    if (ret == 0 && g_ivd_db_cntx.g_ivd_db_handle_p->is_db_stopping == MMI_FALSE)
    {
        ret = sqlite3_bind_text16(stmt_p, 1, 
            path, 
            mmi_ucs2strlen(path) * 2, 
            SQLITE_STATIC);
        ret = sqlite3_step(stmt_p);
    }
    if (stmt_p != NULL)
    {
        sqlite3_finalize(stmt_p);
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  ivd_iv_db_put_img
 * DESCRIPTION
 *  image viewer database put image handler
 * PARAMETERS
 *  *ilm_ptr    [IN]    MSG pointer
 * RETURNS
 *  void
 *****************************************************************************/
void ivd_iv_db_put_img(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_put_img_req_struct *local_para_ptr = NULL;
    ivd_db_put_img_rsp_struct *rsp_local_para_ptr = NULL;
    S32 ret = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_para_ptr = (ivd_db_put_img_req_struct*)ilm_ptr->local_para_ptr;
    g_ivd_db_cntx.g_ivd_db_handle_p = local_para_ptr->db_handle;
    
    ret = ivd_iv_db_write_img2db(local_para_ptr);
    
    if(MMI_FALSE == local_para_ptr->blocking)
    {
        rsp_local_para_ptr = (ivd_db_put_img_rsp_struct*) construct_local_para(sizeof(ivd_db_put_img_rsp_struct), TD_CTRL);
        rsp_local_para_ptr->callback = local_para_ptr->callback;
        rsp_local_para_ptr->user_data = local_para_ptr->user_data;
        rsp_local_para_ptr->db_handle = g_ivd_db_cntx.g_ivd_db_handle_p;
        if (ret >= 0)
        {
            rsp_local_para_ptr->error_code = 0;
        }
        else
        {
            rsp_local_para_ptr->error_code = -1;
        }
        ivd_iv_db_send_msg(MOD_IVD, MOD_MMI, MSG_ID_IVD_DB_PUT_IMG_RSP, rsp_local_para_ptr);
    }
    else
    {
        // set event to make caller task continue
        kal_set_eg_events(g_ivd_db_cntx.g_ivd_iv_event,IVD_IV_DATABASE_GET,KAL_OR);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ivd_iv_db_get_img
 * DESCRIPTION
 *  image viewer database get image handler
 * PARAMETERS
 *  *ilm_ptr    [IN]    MSG pointer
 * RETURNS
 *  void
 *****************************************************************************/
void ivd_iv_db_send_skip_get_img(S32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //ivd_db_get_img_req_struct *local_para_ptr;
    ivd_db_get_img_rsp_struct *rsp_local_para_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_local_para_ptr = (ivd_db_get_img_rsp_struct*) construct_local_para(sizeof(ivd_db_get_img_rsp_struct), TD_CTRL);
    rsp_local_para_ptr->callback = g_ivd_db_cntx.g_ivd_db_handle_p->img_get_req.callback;
    rsp_local_para_ptr->db_handle = g_ivd_db_cntx.g_ivd_db_handle_p;
    rsp_local_para_ptr->req_id = req_id;

    rsp_local_para_ptr->error_code = 0;
    rsp_local_para_ptr->image_err_code = 0;
    rsp_local_para_ptr->image_err_group = 0;
    rsp_local_para_ptr->image_height= 0;
    rsp_local_para_ptr->image_width = 0;
    rsp_local_para_ptr->image_org_height = 0;
    rsp_local_para_ptr->image_org_width = 0;
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_IOBUF_HERE_WE_SKIP_TO_USE_UPPER_BUFFER_D, __LINE__);
    ivd_iv_db_send_msg(MOD_IVD, MOD_MMI, MSG_ID_IVD_DB_GET_IMG_RSP, rsp_local_para_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  ivd_iv_db_get_img
 * DESCRIPTION
 *  image viewer database get image handler
 * PARAMETERS
 *  *ilm_ptr    [IN]    MSG pointer
 * RETURNS
 *  void
 *****************************************************************************/
void ivd_iv_db_get_img(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_get_img_req_struct *local_para_ptr;
    ivd_db_get_img_rsp_struct *rsp_local_para_ptr;
    ivd_iv_file_info_struct file_info;
    S32 ret, req_id, meta_ret = -1;
    U32 file_size;
    S32 image_width, image_height;
    WCHAR *file_path = NULL;
    FS_HANDLE fs_hdle;
    U32 event_group;
    MMI_BOOL isBlocking = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&file_info, 0, sizeof(ivd_iv_file_info_struct));
    local_para_ptr = (ivd_db_get_img_req_struct*)ilm_ptr->local_para_ptr;
    g_ivd_db_cntx.g_ivd_db_handle_p = local_para_ptr->db_handle;
    g_ivd_db_cntx.g_ivd_db_handle_p->is_msg_sent = MMI_FALSE;
    if (g_ivd_db_cntx.g_ivd_db_handle_p->is_db_stopping == MMI_TRUE)
    {
        return;
    }
    if (local_para_ptr->req_id != local_para_ptr->db_handle->io_buf.req_seq_id)
    {
        ivd_iv_db_send_skip_get_img(local_para_ptr->req_id);
        return;
    }
    g_ivd_db_cntx.g_ivd_db_handle_p->ticks = local_para_ptr->ticks;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVD_INFO_GET,g_ivd_db_cntx.g_ivd_db_handle_p->img_get_req.file_size);
    if (local_para_ptr->buffer == NULL)
    {
        file_info.data = g_ivd_db_cntx.g_ivd_db_handle_p->io_buf.o_buffer;
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_IOBUF_HERE_WE_USE_MAYBE_OUTPUT_BUFFER_D, __LINE__);
    }
    else
    {
        file_info.data = local_para_ptr->buffer;
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_IOBUF_HERE_WE_USE_EXTRA_BUFFER_D, __LINE__);
    }
    req_id = local_para_ptr->req_id;
    file_size = g_ivd_db_cntx.g_ivd_db_handle_p->img_get_req.file_size;
    image_width = g_ivd_db_cntx.g_ivd_db_handle_p->img_get_req.image_width;
    image_height = g_ivd_db_cntx.g_ivd_db_handle_p->img_get_req.image_height;
    file_path = (WCHAR*)g_ivd_db_cntx.g_ivd_db_handle_p->img_get_req.path;
    if (local_para_ptr->db_handle->is_db_stopping == MMI_FALSE)
    {
        ret = ivd_iv_db_get_img_by_filename(&file_info, g_ivd_db_cntx.g_ivd_db_handle_p->img_get_req.path, req_id);

        //here we also get meta for image
    #ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
        if (local_para_ptr->with_meta)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_META_START_TO_GET_META_D, __LINE__);
            meta_ret = ivd_iv_db_get_meta_by_filename(g_ivd_db_cntx.g_ivd_db_handle_p->io_buf.meta_buffer, 
                g_ivd_db_cntx.g_ivd_db_handle_p->img_get_req.path);
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_META_END_TO_GET_META_D, __LINE__);
            
            if (meta_ret == SQLITE_ROW || (meta_ret == SQLITE_DONE))
            {
                meta_ret = 0;
            }
            else
            {
                meta_ret = -1;
            }
        }
        else
    #endif /*__MMI_SRV_MEDIA_CACHE_USE_SRV_IES__*/
        {
            meta_ret = -1;
        }
    }
    else
    {
        ret = -1;
        meta_ret = -1;
    }
    if (local_para_ptr->req_id != local_para_ptr->db_handle->io_buf.req_seq_id)
    {
        ivd_iv_db_send_skip_get_img(local_para_ptr->req_id);
        return;
    }

    /* send message back to MMI task to invoke callback if assigned */
    if (local_para_ptr->buffer == NULL || 
        #if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
        NULL != g_ivd_db_cntx.g_ivd_db_handle_p->img_get_req.callback
        #else
        MMI_FALSE
        #endif
        )
    {
        rsp_local_para_ptr = (ivd_db_get_img_rsp_struct*) construct_local_para(sizeof(ivd_db_get_img_rsp_struct), TD_CTRL);
        rsp_local_para_ptr->callback = g_ivd_db_cntx.g_ivd_db_handle_p->img_get_req.callback;
        rsp_local_para_ptr->db_handle = g_ivd_db_cntx.g_ivd_db_handle_p;
        g_ivd_db_cntx.g_ivd_db_handle_p->io_buf.ret_seq_id = req_id;
        rsp_local_para_ptr->error_code = 0;
        rsp_local_para_ptr->image_err_code = file_info.err_code;
        rsp_local_para_ptr->image_err_group = file_info.err_group;

        rsp_local_para_ptr->image_height= file_info.height;
        rsp_local_para_ptr->image_width = file_info.width;
        rsp_local_para_ptr->image_org_height = file_info.o_height;
        rsp_local_para_ptr->image_org_width = file_info.o_width;
        rsp_local_para_ptr->req_id = req_id;

        if (local_para_ptr->with_meta)
        {
            rsp_local_para_ptr->with_meta = local_para_ptr->with_meta;
            rsp_local_para_ptr->meta_ret = meta_ret;
        }
        else
        {
            rsp_local_para_ptr->with_meta = MMI_FALSE;
            rsp_local_para_ptr->meta_ret = 0;
        }
        
        rsp_local_para_ptr->ticks = local_para_ptr->ticks;
        SRV_MEDIACACHE_START_MEASURE("FSO");
        fs_hdle = FS_Open((WCHAR*)file_path, FS_READ_ONLY );
        FS_GetFileSize(fs_hdle, &file_size);
        FS_Close(fs_hdle);
        SRV_MEDIACACHE_STOP_MEASURE("FSO");
        
        if (ret < 0 || file_info.file_size != file_size)
        {
            if(ret >= 0)
            {
                // remove unmatched file entry
                ivd_iv_db_del_img_by_name((CHAR*)file_path);
            }
            rsp_local_para_ptr->error_code = -1;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVD_INFO_ERR_RETURN,
                    ret,
                    file_info.file_size,
                    file_info.width,
                    file_info.height,
                    file_size,
                    image_width,
                    image_height);
        }
        /*clear before flag if has it*/
        kal_retrieve_eg_events(g_ivd_db_cntx.g_ivd_iv_event,IVD_IV_DATABASE_NB_GET_DONE,KAL_OR_CONSUME,&event_group,KAL_NO_SUSPEND);
        if (g_ivd_db_cntx.g_ivd_db_handle_p->is_db_stopping == MMI_TRUE)
        {
            return;
        }
        ivd_iv_db_send_msg(MOD_IVD, MOD_MMI, MSG_ID_IVD_DB_GET_IMG_RSP, rsp_local_para_ptr);
        /*wait until mmi fetch the data*/
        kal_retrieve_eg_events(g_ivd_db_cntx.g_ivd_iv_event,IVD_IV_DATABASE_NB_GET_DONE,KAL_OR_CONSUME,&event_group,KAL_SUSPEND);
    }
    else
    {
        g_ivd_db_cntx.g_ivd_db_handle_p->error_code = 0;
        g_ivd_db_cntx.g_ivd_db_handle_p->image_err_code = file_info.err_code;
        g_ivd_db_cntx.g_ivd_db_handle_p->image_err_group = file_info.err_group;
        g_ivd_db_cntx.g_ivd_db_handle_p->image_height= file_info.height;
        g_ivd_db_cntx.g_ivd_db_handle_p->image_width = file_info.width;
        g_ivd_db_cntx.g_ivd_db_handle_p->org_image_height = file_info.o_height;
        g_ivd_db_cntx.g_ivd_db_handle_p->org_image_width  = file_info.o_width;

        if (local_para_ptr->with_meta)
        {
            g_ivd_db_cntx.g_ivd_db_handle_p->meta_ret = meta_ret;
        }
        else
        {
            g_ivd_db_cntx.g_ivd_db_handle_p->meta_ret = meta_ret;
        }
        
        SRV_MEDIACACHE_START_MEASURE("FSO");
        fs_hdle = FS_Open((WCHAR*)file_path, FS_READ_ONLY );
        FS_GetFileSize(fs_hdle, &file_size);
        FS_Close(fs_hdle);
        SRV_MEDIACACHE_STOP_MEASURE("FSO");
        if (ret < 0 || file_info.file_size != file_size)
        {
            if(ret >= 0)
            {
                // remove unmatched file entry
                ivd_iv_db_del_img_by_name((CHAR*)file_path);
            }
            g_ivd_db_cntx.g_ivd_db_handle_p->error_code = -1;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVD_INFO_ERR_RETURN,
                ret,
                file_info.file_size,
                file_info.width,
                file_info.height,
                file_size,
                image_width,
                image_height);
        }
        
        kal_set_eg_events(g_ivd_db_cntx.g_ivd_iv_event,IVD_IV_DATABASE_GET,KAL_OR);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ivd_iv_db_remove_img
 * DESCRIPTION
 *  image viewer remove image handler, only support before a date now
 * PARAMETERS
 *  *ilm_ptr    [IN]    MSG pointer
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL ivd_iv_db_remove_img(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_remove_img_req_struct *local_para_ptr = (ivd_db_remove_img_req_struct*)ilm_ptr->local_para_ptr;
    ivd_db_remove_img_rsp_struct *rsp_local_para_ptr = (ivd_db_remove_img_rsp_struct*)ilm_ptr->local_para_ptr;
    S32 ret;
#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
    S32 ret_meta;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_local_para_ptr = (ivd_db_remove_img_rsp_struct*) construct_local_para(sizeof(ivd_db_remove_img_rsp_struct), TD_CTRL);
    g_ivd_db_cntx.g_ivd_db_handle_p = local_para_ptr->db_handle;
    rsp_local_para_ptr->callback = local_para_ptr->callback;
    rsp_local_para_ptr->user_data = local_para_ptr->user_data;
    rsp_local_para_ptr->db_handle = local_para_ptr->db_handle;
    rsp_local_para_ptr->error_code = MMI_IVD_ERR_UNKNOW;
    if (local_para_ptr->db_handle->is_db_inited == MMI_TRUE &&
        g_ivd_db_cntx.g_ivd_db_handle_p->is_db_stopping == MMI_FALSE)
    {
        switch(local_para_ptr->remove_type)
        {
        case MMI_IVD_REMOVE_IMG_TYPE_BEFORE_DATE:
            ret = ivd_iv_db_del_img_before_the_date(local_para_ptr->date);
        #ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
            //ret_meta = ivd_iv_db_del_meta_before_the_date(local_para_ptr->path);
        #endif
            rsp_local_para_ptr->error_code = ret;
            break;
        case MMI_IVD_REMOVE_IMG_TYPE_NAME:
            ret = ivd_iv_db_del_img_by_name(local_para_ptr->path);
        #ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
            ret_meta = ivd_iv_db_del_meta_by_name(local_para_ptr->path);
        #endif
            rsp_local_para_ptr->error_code = ret;
            break;
            
        #ifdef __COSMOS_MMI_PACKAGE__
        case MMI_IVD_REMOVE_IMG_TYPE_VIDEO:
            ret = ivd_iv_db_remove_video_info_by_filename(local_para_ptr->db_handle, (const WCHAR*)local_para_ptr->path);
            rsp_local_para_ptr->error_code = ret == MMI_TRUE ? 0 : -1;
            break;
        #endif
        
        default:
            ASSERT(0);
        }
    }
    local_para_ptr->db_handle->is_remove_msg_sent = MMI_FALSE;
    ivd_iv_db_send_msg(MOD_IVD, MOD_MMI, MSG_ID_IVD_DB_REMOVE_IMG_RSP, rsp_local_para_ptr);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  ivd_main
 * DESCRIPTION
 *  image viewer daemon main MSG loop
 * PARAMETERS
 *  *ilm_ptr    [IN]    MSG pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void ivd_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(ilm_ptr->msg_id)
    {
    case MSG_ID_IVD_DB_START_REQ:
        SRV_MEDIACACHE_START_MEASURE("DB6");
        ivd_iv_db_start(ilm_ptr);
        SRV_MEDIACACHE_STOP_MEASURE("DB6");
        break;
    case MSG_ID_IVD_DB_STOP_REQ:
        ivd_iv_db_stop(ilm_ptr);
        break;
    case MSG_ID_IVD_DB_GET_IMG_REQ:
        SRV_MEDIACACHE_START_MEASURE("DB7");
        ivd_iv_db_get_img(ilm_ptr);
        SRV_MEDIACACHE_STOP_MEASURE("DB7");
        break;
    case MSG_ID_IVD_DB_PUT_IMG_REQ:
        SRV_MEDIACACHE_START_MEASURE("DB8");
        ivd_iv_db_put_img(ilm_ptr);
        SRV_MEDIACACHE_STOP_MEASURE("DB8");
        break;
    case MSG_ID_IVD_DB_REMOVE_IMG_REQ:
        ivd_iv_db_remove_img(ilm_ptr);
        break;
#ifdef __COSMOS_MMI_PACKAGE__
    case MSG_ID_IVD_DB_VDO_REQ:
        ivd_iv_db_handle_video_msg(ilm_ptr);
        break;
#endif    

    case MSG_ID_IVD_DB_PUT_META_REQ:
        SRV_MEDIACACHE_START_MEASURE("DB9");
    #ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
        ivd_iv_db_put_meta(ilm_ptr);
    #endif /*__MMI_SRV_MEDIA_CACHE_USE_SRV_IES__*/
        SRV_MEDIACACHE_STOP_MEASURE("DB9");
        break;
 
    case MSG_ID_IVD_DB_GET_META_REQ:
        SRV_MEDIACACHE_START_MEASURE("DBA");
    #ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
        ivd_iv_db_get_meta(ilm_ptr);
    #endif /*__MMI_SRV_MEDIA_CACHE_USE_SRV_IES__*/
        SRV_MEDIACACHE_STOP_MEASURE("DBA");
        break;

    default:
        break;
    }

   
}


/*****************************************************************************
 * FUNCTION
 *  ivd_task_main
 * DESCRIPTION
 *  image viewer daemon task main function
 * PARAMETERS
 *  *task_entry_ptr    [IN]    task entry structure
 * RETURNS
 *  void
 *****************************************************************************/
static void ivd_task_main(task_entry_struct *task_entry_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;
    kal_uint32   my_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_my_task_index(&my_index);
    stack_set_active_module_id (my_index, MOD_IVD);

    while (1)
    {
        receive_msg_ext_q_for_stack( task_info_g[task_entry_ptr->task_indx].task_ext_qid,
                         &current_ilm);
        ivd_main(&current_ilm);
        free_ilm(&current_ilm);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ivd_init
 * DESCRIPTION
 *  image viewer daemon task init function
 * PARAMETERS
 *  *task_indx    [IN]    task index
 * RETURNS
 *  KAL_TRUE init OK
 *****************************************************************************/
kal_bool ivd_init(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ivd_db_cntx.g_ivd_iv_event = kal_create_event_group("ivd_evt");
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  ivd_reset
 * DESCRIPTION
 *  image viewer daemon task reset function
 * PARAMETERS
 *  *task_indx    [IN]    task index
 * RETURNS
 *  KAL_TRUE    reset OK
 *****************************************************************************/
static kal_bool ivd_reset( task_indx_type task_indx )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_TRUE;
}


/******************************************************************
 * FUNCTION
 *    ivd_create
 * DESCRIPTION
 *  image viewer daemon task create function
 * PARAMETERS
 *  *handle    [IN]    task handle
 * RETURNS
 *  KAL_TRUE    create OK
 ******************************************************************/
kal_bool ivd_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct ivd_handler_info = 
    {
       ivd_task_main,         /* task entry function */
       ivd_init,         /* task initialization function */
       NULL,      /* task configuration function */
       ivd_reset,            /* task reset handler */
       NULL,            /* task termination handler */
    };
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   *handle = (comptask_handler_struct*)&ivd_handler_info;
   return KAL_TRUE;
}


/******************************************************************
 * FUNCTION
 *  ivd_ivsrv_db_start_rsp_hdler
 * DESCRIPTION
 *  image viewer daemon request response handler
 * PARAMETERS
 *  *msg    [IN]    msg pointer
 * RETURNS
 *  void
 ******************************************************************/
void ivd_ivsrv_db_start_rsp_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_start_rsp_struct* ivd_db_open_rsp_ptr = (ivd_db_start_rsp_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ivd_db_open_rsp_ptr->callback != NULL)
    {
        (ivd_db_open_rsp_ptr->callback)(ivd_db_open_rsp_ptr->error_code,ivd_db_open_rsp_ptr->user_data);
    }
}


/******************************************************************
 * FUNCTION
 *  ivd_ivsrv_db_put_img_rsp_hdler
 * DESCRIPTION
 *  image viewer daemon request response handler
 * PARAMETERS
 *  *msg    [IN]    msg pointer
 * RETURNS
 *  void
 ******************************************************************/
void ivd_ivsrv_db_put_img_rsp_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_put_img_rsp_struct* ivd_db_put_img_rsp_ptr = (ivd_db_put_img_rsp_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ivd_db_put_img_rsp_ptr->db_handle->io_buf.i_state != MMI_IVD_IO_BUF_STATE_PUT)
    {
        //for we give up this image, so we reset the put image state
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_IOBUF_HERE_WE_END_TO_USE_PUT_IMAGE_BUFFER_O_BUFFER_D, __LINE__);
        return;
    }
    
    ivd_db_put_img_rsp_ptr->db_handle->io_buf.i_state = MMI_IVD_IO_BUF_STATE_IDLE;
    if (ivd_db_put_img_rsp_ptr->callback != NULL)
    {
        (ivd_db_put_img_rsp_ptr->callback)(ivd_db_put_img_rsp_ptr->error_code, ivd_db_put_img_rsp_ptr->user_data);
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_IOBUF_HERE_WE_END_TO_USE_PUT_IMAGE_BUFFER_O_BUFFER_D, __LINE__);
}


/******************************************************************
 * FUNCTION
 *  ivd_ivsrv_db_get_img_rsp_hdler
 * DESCRIPTION
 *  image viewer daemon request response handler
 * PARAMETERS
 *  *msg    [IN]    msg pointer
 * RETURNS
 *  void
 ******************************************************************/
void ivd_ivsrv_db_get_img_rsp_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_get_img_rsp_struct* ivd_db_get_img_rsp_ptr = (ivd_db_get_img_rsp_struct*)msg;
    ivd_db_imageinfo_struct image_info;
    U32 end_ticks = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_set_eg_events(g_ivd_db_cntx.g_ivd_iv_event,IVD_IV_DATABASE_NB_GET_DONE,KAL_OR);
    if (ivd_db_get_img_rsp_ptr->db_handle->io_buf.state != MMI_IVD_IO_BUF_STATE_GET ||
        ivd_db_get_img_rsp_ptr->db_handle->io_buf.req_seq_id != ivd_db_get_img_rsp_ptr->req_id)
    {
        //for we give up this image, so we reset the get image state
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_IOBUF_HERE_WE_END_TO_USE_GET_IMAGE_BUFFER_D, __LINE__);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVD_INFO_GET_IMG_CB_HDLR,
            ivd_db_get_img_rsp_ptr->db_handle->io_buf.state,
            ivd_db_get_img_rsp_ptr->db_handle->io_buf.ret_seq_id,
            ivd_db_get_img_rsp_ptr->db_handle->io_buf.req_seq_id,
            ivd_db_get_img_rsp_ptr->db_handle->io_buf.ret_seq_id == ivd_db_get_img_rsp_ptr->req_id);

        //here is meta pat    
        image_info.with_meta = ivd_db_get_img_rsp_ptr->with_meta;
        image_info.meta_ret = ivd_db_get_img_rsp_ptr->meta_ret;
        
        (ivd_db_get_img_rsp_ptr->callback)(MMI_IVD_ERR_GET_SKIP, &image_info, ivd_db_get_img_rsp_ptr->user_data);
        return;
    }
    ivd_db_get_img_rsp_ptr->db_handle->io_buf.state = MMI_IVD_IO_BUF_STATE_IDLE;
    kal_get_time(&end_ticks);
    kal_print_string_trace(MOD_MMI_MEDIA_APP,TRACE_GROUP_2,"[srvmc]get image from db use ticks=%d",end_ticks - ivd_db_get_img_rsp_ptr->ticks);
    if (ivd_db_get_img_rsp_ptr->callback != NULL)
    {
        image_info.err_group = ivd_db_get_img_rsp_ptr->image_err_group;
        image_info.err_code = ivd_db_get_img_rsp_ptr->image_err_code;

        image_info.image_width = ivd_db_get_img_rsp_ptr->image_width;
        image_info.image_height = ivd_db_get_img_rsp_ptr->image_height;
        image_info.org_image_width = ivd_db_get_img_rsp_ptr->image_org_width;
        image_info.org_image_height= ivd_db_get_img_rsp_ptr->image_org_height;

        //here is meta pat    
        image_info.with_meta = ivd_db_get_img_rsp_ptr->with_meta;
        image_info.meta_ret = ivd_db_get_img_rsp_ptr->meta_ret;
        
        (ivd_db_get_img_rsp_ptr->callback)(ivd_db_get_img_rsp_ptr->error_code, &image_info, ivd_db_get_img_rsp_ptr->user_data);
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_IOBUF_HERE_WE_END_TO_USE_GET_IMAGE_BUFFER_D, __LINE__);
    }
}


/******************************************************************
 * FUNCTION
 *  ivd_ivsrv_db_remove_img_rsp_hdler
 * DESCRIPTION
 *  image viewer daemon request response handler
 * PARAMETERS
 *  *msg    [IN]    msg pointer
 * RETURNS
 *  void
 ******************************************************************/
void ivd_ivsrv_db_remove_img_rsp_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_remove_img_rsp_struct* ivd_db_get_img_rsp_ptr = (ivd_db_remove_img_rsp_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ivd_db_get_img_rsp_ptr->callback != NULL)
    {
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SRVMC][IVD]ivd_ivsrv_db_remove_img_rsp_hdler calls %d", &ivd_db_get_img_rsp_ptr->callback);
        (ivd_db_get_img_rsp_ptr->callback)(ivd_db_get_img_rsp_ptr->error_code, ivd_db_get_img_rsp_ptr->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ivd_ivsrv_db_start
 * DESCRIPTION
 *  image viewer service start function 
 * PARAMETERS
 *  *db_handle [IN]    database handle
 *  *path      [IN]    filepath of database
 *  callback   [IN]    callback function
 * RETURNS
 *  void
 *****************************************************************************/
S32 ivd_ivsrv_db_start(ivd_db_handle_struct *db_handle, const WCHAR *path, ivd_req_callback callback, const WCHAR *db_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_start_req_struct    *local_para_ptr;
    U32 length = 0;
    U32 name_length = 0;
    S32 ret_val = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_DB_DB_START_D, __LINE__);
    local_para_ptr = (ivd_db_start_req_struct*) construct_local_para(sizeof(ivd_db_start_req_struct), TD_CTRL);
    local_para_ptr->db_handle = db_handle;
    local_para_ptr->db_handle->is_msg_sent = MMI_FALSE;
    local_para_ptr->db_handle->is_remove_msg_sent = MMI_FALSE;
    local_para_ptr->db_handle->is_db_inited = MMI_TRUE;
    #if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
    local_para_ptr->db_handle->query_stmt = NULL;
    #endif
    local_para_ptr->callback = callback;
    memcpy(local_para_ptr->path, path, IVD_FILE_MAX_PATH_LEN);
    kal_wsprintf((WCHAR*)local_para_ptr->path, "%c%s",path[0],":\\");
    length = mmi_ucs2strlen(local_para_ptr->path);
    kal_print_string_trace(MOD_MMI_MEDIA_APP,TRACE_GROUP_2,"[srvmc]database run buf=%d length=%d",local_para_ptr->db_handle->db_buffer.buffer,local_para_ptr->db_handle->db_buffer.length);
    if (local_para_ptr->path[length * 2 - 2] != '\\' && length < IVD_FILE_MAX_PATH_LEN - 1)
    {
        mmi_ucs2cat(local_para_ptr->path, (CHAR*)L"\\");
    }
    if (length < IVD_FILE_MAX_PATH_LEN - (12 * 2) - 1)
    {
        mmi_ucs2cat(local_para_ptr->path, (CHAR*)L"@MediaCache\\");
        FS_CreateDir((WCHAR*)local_para_ptr->path);
        FS_SetAttributes((WCHAR*)local_para_ptr->path, FS_ATTR_DIR | FS_ATTR_HIDDEN);    
    }
    length = mmi_ucs2strlen(local_para_ptr->path);
    name_length = mmi_ucs2strlen((CHAR*)db_name);
    if (length + name_length + 2 < IVD_FILE_MAX_PATH_LEN)
    {
        mmi_ucs2cat(local_para_ptr->path, (CHAR*)db_name);
        
        #if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
        // construct cache file folder by appending "@" at end of DB file name
        memcpy(db_handle->db_cache_folder, local_para_ptr->path, IVD_FILE_MAX_PATH_LEN);
        name_length = mmi_ucs2strlen((CHAR*)db_handle->db_cache_folder);
        // 6 comes from "@\\" and NULL terminator
        if(name_length + 6 < IVD_FILE_MAX_PATH_LEN)
        {
            mmi_ucs2cat(db_handle->db_cache_folder, (CHAR*)L"@\\");
            FS_CreateDir((WCHAR*)db_handle->db_cache_folder);
            FS_SetAttributes((WCHAR*)db_handle->db_cache_folder, FS_ATTR_DIR | FS_ATTR_HIDDEN);    
        }
        else
        {
            ASSERT(0);  // cannot construct DB cache file folder
        }
        #endif

        ivd_iv_db_send_msg(MOD_MMI, MOD_IVD, MSG_ID_IVD_DB_START_REQ, local_para_ptr);
    }
    else
    {
        free_local_para((local_para_struct*)local_para_ptr);
        ret_val = -1;
    }
    return ret_val;
}


static ivd_ivsrv_db_put_img_internal(ivd_db_img_info_struct *img_info, ivd_req_callback callback, void* user_data, MMI_BOOL is_blocking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_put_img_req_struct *local_para_ptr;
    U32 date, time;
    applib_time_struct   rtc_time;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (img_info->db_handle->io_buf.i_state != MMI_IVD_IO_BUF_STATE_IDLE)
    {
        return;
    }
    img_info->db_handle->io_buf.i_state = MMI_IVD_IO_BUF_STATE_PUT;
    local_para_ptr = (ivd_db_put_img_req_struct*) construct_local_para(sizeof(ivd_db_put_img_req_struct), TD_CTRL);
    
    local_para_ptr->db_handle = img_info->db_handle;
    local_para_ptr->org_image_width = img_info->org_image_width;
    local_para_ptr->org_image_height = img_info->org_image_height;
    local_para_ptr->image_width = img_info->image_width;
    local_para_ptr->image_height = img_info->image_height;
    local_para_ptr->color_format = img_info->color_format;
    local_para_ptr->callback = callback;
    local_para_ptr->db_handle->io_buf.i_seq_id++;
    local_para_ptr->seq_id = local_para_ptr->db_handle->io_buf.i_seq_id;

    local_para_ptr->file_date = img_info->file_date;
    local_para_ptr->file_time = img_info->file_time;
    local_para_ptr->file_size = img_info->file_size;
    local_para_ptr->file_CRC = img_info->file_CRC;
    local_para_ptr->user_data = user_data;
    local_para_ptr->err_group = img_info->err_group;
    local_para_ptr->err_code = img_info->err_code;
    local_para_ptr->file_idx = img_info->file_idx;
    local_para_ptr->blocking = is_blocking;

    applib_dt_get_rtc_time(&rtc_time);
    date = rtc_time.nYear % 10;
    date = date * 100 + (rtc_time.nMonth % 100);
    date = date * 100 + (rtc_time.nDay % 100);
    local_para_ptr->sys_date = date;

    time = rtc_time.nHour % 24;
    time = time * 100 + (rtc_time.nMin % 100);
    local_para_ptr->sys_time = time;
        
    memcpy(local_para_ptr->path, img_info->path, IVD_FILE_MAX_PATH_LEN);
    ASSERT(img_info->db_handle->io_buf.i_length >= img_info->image_width * img_info->image_height * g_ivd_db_cntx.g_ivd_db_handle_p->bytes_per_pixel);
    memcpy(img_info->db_handle->io_buf.i_buffer, img_info->buffer, img_info->image_width * img_info->image_height * g_ivd_db_cntx.g_ivd_db_handle_p->bytes_per_pixel);

    // send request to IVD
    ivd_iv_db_send_msg(MOD_MMI, MOD_IVD, MSG_ID_IVD_DB_PUT_IMG_REQ, local_para_ptr);

    if(MMI_TRUE == is_blocking)
    {   
        // wait for event
        U32 event_group = 0;
        kal_retrieve_eg_events(g_ivd_db_cntx.g_ivd_iv_event,IVD_IV_DATABASE_GET,KAL_OR_CONSUME,&event_group,KAL_SUSPEND);

        // event retrieved, we no longer need the put buffer
        img_info->db_handle->io_buf.i_state = MMI_IVD_IO_BUF_STATE_IDLE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  ivd_ivsrv_db_put_img
 * DESCRIPTION
 *  image viewer service put image to database
 * PARAMETERS
 *  *img_info       [IN]    image info
 *  callback        [IN]    callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void ivd_ivsrv_db_put_img(ivd_db_img_info_struct *img_info, ivd_req_callback callback, void* user_data)
{
    ivd_ivsrv_db_put_img_internal(img_info, callback, user_data, MMI_FALSE);
}

/*****************************************************************************
 * FUNCTION
 *  ivd_ivsrv_db_put_img_blocking
 * DESCRIPTION
 *  image viewer service put image to database, blocking until written
 * PARAMETERS
 *  *img_info       [IN]    image info
 * RETURNS
 *  void
 *****************************************************************************/
extern void ivd_ivsrv_db_put_img_blocking(ivd_db_img_info_struct *img_info)
{
    ivd_ivsrv_db_put_img_internal(img_info, NULL, NULL, MMI_TRUE);   
}

/*****************************************************************************
 * FUNCTION
 *  ivd_ivsrv_db_get_img
 * DESCRIPTION
 *  image viewer service get image function 
 * PARAMETERS
 *  *img_info       [IN]    image info
 *  callback        [IN]    callback function
 * RETURNS
 *  0: Successfully sent get img request
 * -1: Fail to sent get img request
 *****************************************************************************/
S32 ivd_ivsrv_db_get_img(ivd_db_img_info_struct *img_info, ivd_req_callback_with_info callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_get_img_req_struct *local_para_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(img_info->db_handle->io_buf.state != MMI_IVD_IO_BUF_STATE_GET);
    img_info->db_handle->io_buf.state = MMI_IVD_IO_BUF_STATE_GET;

    memcpy(img_info->db_handle->img_get_req.path, img_info->path, IVD_FILE_MAX_PATH_LEN);
    img_info->db_handle->io_buf.req_seq_id++;
    img_info->db_handle->img_get_req.org_image_width = img_info->org_image_width;
    img_info->db_handle->img_get_req.org_image_height = img_info->org_image_height;
    img_info->db_handle->img_get_req.image_width = img_info->image_width;
    img_info->db_handle->img_get_req.image_height = img_info->image_height;
    img_info->db_handle->img_get_req.callback = callback;
    img_info->db_handle->img_get_req.seq_id = img_info->db_handle->io_buf.req_seq_id;
    img_info->db_handle->img_get_req.file_date = img_info->file_date;
    img_info->db_handle->img_get_req.file_time = img_info->file_time;
    img_info->db_handle->img_get_req.file_size = img_info->file_size;
    img_info->db_handle->img_get_req.file_CRC = img_info->file_CRC;
    #if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
    img_info->db_handle->buffer = img_info->buffer;
    img_info->db_handle->length = img_info->length4get;
    #else
    img_info->db_handle->buffer = NULL;
    img_info->db_handle->length = 0;
    #endif

    //here we use meta buffer for meta data
    //img_info->db_handle->io_buf.meta_buffer;
    //img_info->db_handle->io_buf.meta_length;
    
    if (MMI_TRUE == img_info->db_handle->is_get_cancel_put)
    {
        ivd_ivsrv_db_cancel_put(img_info->db_handle);
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVD_INFO_GET_IMG_FILESIZE, img_info->file_size);
    if (img_info->db_handle->is_msg_sent == MMI_FALSE)
    {
        local_para_ptr = (ivd_db_get_img_req_struct*) construct_local_para(sizeof(ivd_db_get_img_req_struct), TD_CTRL);
        local_para_ptr->db_handle = img_info->db_handle;
        #if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
        local_para_ptr->buffer = img_info->db_handle->buffer;
        #else
        local_para_ptr->buffer = NULL;
        #endif
        local_para_ptr->req_id = img_info->db_handle->io_buf.req_seq_id;
        img_info->db_handle->is_msg_sent = MMI_TRUE;
        if (img_info->with_meta)
        {
            local_para_ptr->with_meta = MMI_TRUE;
        }
        else
        {
            local_para_ptr->with_meta = MMI_FALSE;
        }
        kal_get_time(&local_para_ptr->ticks);
        ivd_iv_db_send_msg(MOD_MMI, MOD_IVD, MSG_ID_IVD_DB_GET_IMG_REQ, local_para_ptr);
        return 0;
    }
    else
    {
        return -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ivd_ivsrv_db_get_img_blocking
 * DESCRIPTION
 *  image viewer service get image function 
 * PARAMETERS
 *  *img_info       [IN]    image info
 *  callback        [IN]    callback function
 * RETURNS
 *  void
 *****************************************************************************/
S32 ivd_ivsrv_db_get_img_blocking(ivd_db_img_info_struct *img_info, U8* buffer, U32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_get_img_req_struct *local_para_ptr;
    U32 event_group;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (img_info->db_handle->is_db_inited == MMI_FALSE)
    {
        return -1;
    }
    memcpy(img_info->db_handle->img_get_req.path, img_info->path, IVD_FILE_MAX_PATH_LEN);
    img_info->db_handle->io_buf.req_seq_id++;
    img_info->db_handle->img_get_req.org_image_width = img_info->org_image_width;
    img_info->db_handle->img_get_req.org_image_height = img_info->org_image_height;
    img_info->db_handle->img_get_req.image_width = img_info->image_width;
    img_info->db_handle->img_get_req.image_height = img_info->image_height;
    #if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
    img_info->db_handle->img_get_req.callback = NULL;
    #endif
    img_info->db_handle->img_get_req.seq_id = img_info->db_handle->io_buf.req_seq_id;
    img_info->db_handle->img_get_req.file_date = img_info->file_date;
    img_info->db_handle->img_get_req.file_time = img_info->file_time;
    img_info->db_handle->img_get_req.file_size = img_info->file_size;
    img_info->db_handle->img_get_req.file_CRC = img_info->file_CRC;
    img_info->db_handle->buffer = buffer;
    img_info->db_handle->length = length;
    local_para_ptr = (ivd_db_get_img_req_struct*) construct_local_para(sizeof(ivd_db_get_img_req_struct), TD_CTRL);
    local_para_ptr->db_handle = img_info->db_handle;
    local_para_ptr->buffer = buffer;
    local_para_ptr->req_id = img_info->db_handle->io_buf.req_seq_id;

    if (img_info->with_meta)
    {   
        local_para_ptr->with_meta = MMI_TRUE;
    }
    else
    {
        local_para_ptr->with_meta = MMI_FALSE;
    }

    img_info->db_handle->is_msg_sent = MMI_TRUE;
    ivd_iv_db_send_msg(MOD_MMI, MOD_IVD, MSG_ID_IVD_DB_GET_IMG_REQ, local_para_ptr);
    kal_retrieve_eg_events(g_ivd_db_cntx.g_ivd_iv_event,IVD_IV_DATABASE_GET,KAL_OR_CONSUME,&event_group,KAL_SUSPEND);

#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
    if (img_info->with_meta)
    {   
        img_info->meta_ret = img_info->db_handle->meta_ret;
    }
    else
    {
        img_info->meta_ret = 0;
    }
#endif

    img_info->err_group = img_info->db_handle->image_err_group;
    img_info->err_code = img_info->db_handle->image_err_code;
    
    img_info->image_width = img_info->db_handle->image_width;
    img_info->image_height = img_info->db_handle->image_height;
    img_info->org_image_width = img_info->db_handle->org_image_width;
    img_info->org_image_height = img_info->db_handle->org_image_height;
    return img_info->db_handle->error_code;
}


/*****************************************************************************
 * FUNCTION
 *  ivd_ivsrv_db_remove_img_before_date
 * DESCRIPTION
 *  image viewer service remove image function 
 * PARAMETERS
 *  *db_handle  [IN]    database handle
 *  date        [IN]    date
 *  callback    [IN]    callback function
 * RETURNS
 *  void
 *****************************************************************************/
void ivd_ivsrv_db_remove_img_before_date(ivd_db_handle_struct *db_handle, U32 date, ivd_req_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_remove_img_req_struct *local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (db_handle->is_remove_msg_sent == MMI_TRUE || db_handle->is_db_inited == MMI_FALSE)
    {
        return;
    }
    local_para_ptr = (ivd_db_remove_img_req_struct*) construct_local_para(sizeof(ivd_db_remove_img_req_struct), TD_CTRL);
    local_para_ptr->db_handle = db_handle;
    local_para_ptr->callback = callback;
    local_para_ptr->remove_type = MMI_IVD_REMOVE_IMG_TYPE_BEFORE_DATE;
    local_para_ptr->date = date;
    db_handle->is_remove_msg_sent = MMI_TRUE;
    ivd_iv_db_send_msg(MOD_MMI, MOD_IVD, MSG_ID_IVD_DB_REMOVE_IMG_REQ, local_para_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  ivd_ivsrv_db_remove_img_by_name
 * DESCRIPTION
 *  image viewer service remove image function 
 * PARAMETERS
 *  *db_handle  [IN]    database handle
 *  path        [IN]    filename
 *  callback    [IN]    callback function
 * RETURNS
 *  void
 *****************************************************************************/
void ivd_ivsrv_db_remove_img_by_name(ivd_db_handle_struct *db_handle, CHAR *path, ivd_req_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_remove_img_req_struct *local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (db_handle->is_remove_msg_sent == MMI_TRUE || db_handle->is_db_inited == MMI_FALSE)
    {
        return;
    }
    local_para_ptr = (ivd_db_remove_img_req_struct*) construct_local_para(sizeof(ivd_db_remove_img_req_struct), TD_CTRL);
    local_para_ptr->db_handle = db_handle;
    local_para_ptr->callback = callback;
    local_para_ptr->remove_type = MMI_IVD_REMOVE_IMG_TYPE_NAME;
    memcpy(local_para_ptr->path, path, IVD_FILE_MAX_PATH_LEN);
    db_handle->is_remove_msg_sent = MMI_TRUE;
    ivd_iv_db_send_msg(MOD_MMI, MOD_IVD, MSG_ID_IVD_DB_REMOVE_IMG_REQ, local_para_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  ivd_ivsrv_db_cancel
 * DESCRIPTION
 *  image viewer service cancel get image function 
 * PARAMETERS
 *  *db_handle            [IN]    cancel get image function
 * RETURNS
 *  MMI_TRUE    cancel OK
 *****************************************************************************/
void ivd_ivsrv_db_enable_get_cancel_put(ivd_db_handle_struct *db_handle,MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_MEDIACACHE_PUT_HIGH_PRIORITY__
    db_handle->is_get_cancel_put = MMI_FALSE;
#else
    db_handle->is_get_cancel_put = enable;
    if (MMI_IVD_IO_BUF_STATE_IDLE != db_handle->io_buf.state)
    {
        ivd_ivsrv_db_cancel_put(db_handle);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  ivd_ivsrv_db_cancel
 * DESCRIPTION
 *  image viewer service cancel get image function 
 * PARAMETERS
 *  *db_handle            [IN]    cancel get image function
 * RETURNS
 *  MMI_TRUE    cancel OK
 *****************************************************************************/
MMI_BOOL ivd_ivsrv_db_cancel_get(ivd_db_handle_struct *db_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db_handle->io_buf.state = MMI_IVD_IO_BUF_STATE_IDLE;
    db_handle->io_buf.req_seq_id++;
    kal_set_eg_events(g_ivd_db_cntx.g_ivd_iv_event,IVD_IV_DATABASE_NB_GET_DONE,KAL_OR);
    // since msg are cancelled, do not block further messages
    db_handle->is_msg_sent = MMI_FALSE;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  ivd_ivsrv_db_cancel
 * DESCRIPTION
 *  image viewer service cancel get image function 
 * PARAMETERS
 *  *db_handle            [IN]    cancel get image function
 * RETURNS
 *  MMI_TRUE    cancel OK
 *****************************************************************************/
MMI_BOOL ivd_ivsrv_db_cancel_put(ivd_db_handle_struct *db_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db_handle->io_buf.i_seq_id++;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  ivd_ivsrv_db_stop
 * DESCRIPTION
 *  image viewer service stop database function 
 * PARAMETERS
 *  *db_handle      [IN]    database handle
 * RETURNS
 *  MMI_IVD_OK      stop OK
 *****************************************************************************/
S32 ivd_ivsrv_db_stop(ivd_db_handle_struct *db_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_stop_req_struct    *local_para_ptr;
    U32 event_group;
    S32 ret_val = MMI_IVD_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_DB_DB_STOP_D, __LINE__);
    local_para_ptr = (ivd_db_stop_req_struct*) construct_local_para(sizeof(ivd_db_stop_req_struct), TD_CTRL);
    local_para_ptr->db_handle = db_handle;
    db_handle->is_db_stopping = MMI_TRUE;
    ivd_iv_db_send_msg(MOD_MMI, MOD_IVD, MSG_ID_IVD_DB_STOP_REQ, local_para_ptr);
    kal_set_eg_events(g_ivd_db_cntx.g_ivd_iv_event,IVD_IV_DATABASE_NB_GET_DONE,KAL_OR);
    kal_retrieve_eg_events(g_ivd_db_cntx.g_ivd_iv_event,IVD_IV_DATABASE_STOP,KAL_OR_CONSUME,&event_group,KAL_SUSPEND);
    return ret_val;
}

#ifdef __COSMOS_MMI_PACKAGE__

static void ivd_iv_db_handle_video_msg(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_video_msg_base *msg = (ivd_db_video_msg_base*)ilm_ptr->local_para_ptr;
    MMI_BOOL handler_result = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg->handler_func);
    handler_result = msg->handler_func(msg);

    // if blocking, wait for event
    if(msg->blocking_call)
    {
        kal_set_eg_events(g_ivd_db_cntx.g_ivd_iv_event,IVD_IV_DATABASE_GET,KAL_OR);
    }
}

static MMI_BOOL ivd_iv_db_util_has_video_info(ivd_db_handle_struct* db_handle, const WCHAR* file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    // sqlite working vars
    sqlite3_stmt *stmt = NULL;
    kal_int32 res = 0;
    MMI_BOOL ret = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NULL == db_handle)
    {
        return MMI_FALSE;
    }

    do
    {
        // check if a file exists
        res = sqlite3_prepare_v2(
                        db_handle->db, 
                        "SELECT 1 AS found WHERE EXISTS(SELECT NULL FROM video_info WHERE filename=?)",
                        -1, 
                        &stmt, 
                        NULL);
        res = sqlite3_bind_kal_wstr(stmt, 1, file_name);
        if(SQLITE_ROW == sqlite3_step(stmt))
        {
            if(1 == sqlite3_column_int(stmt, 0))
            {
                ret = MMI_TRUE;
            }
        }
    }while(0);

    if(stmt)
    {
        sqlite3_reset(stmt);
        sqlite3_finalize(stmt);    
    }
    
    return ret;
}

static MMI_BOOL ivd_iv_db_remove_video_info_by_filename(ivd_db_handle_struct* db_handle, const WCHAR* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    // sqlite working vars
    sqlite3_stmt *stmt = NULL;
    kal_int32 res = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SRVMC][IVD]ivd_iv_db_remove_video_info_by_filename");
    do
    {
        res = sqlite3_prepare_v2(
                        db_handle->db, 
                        "DELETE FROM video_info WHERE filename=?",
                        -1, 
                        &stmt, 
                        NULL);
        if(NULL == stmt)
        {
            break;
        }
        
        res = sqlite3_bind_kal_wstr(stmt, 1, filename);
        res = sqlite3_step(stmt);
        res = sqlite3_finalize(stmt);
    }while(0);
    
    // force commit
    ivd_iv_db_sqlite3_exec(ivd_iv_db_cmd_commit_transcation, NULL);
    ivd_iv_db_sqlite3_exec(ivd_iv_db_cmd_begin_transcation, NULL);
    return MMI_TRUE;
}

static MMI_BOOL ivd_iv_db_has_video_info(ivd_db_video_msg_base *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_video_msg_has_info *get_msg = NULL;
    ivd_db_video_result_has_info *out = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg->type_id == 'INFO');
    ASSERT(msg->msg_size == sizeof(ivd_db_video_msg_has_info));
    get_msg = (ivd_db_video_msg_has_info*)msg;
    out = (ivd_db_video_result_has_info*)get_msg->result;
    ASSERT(out);
    
    out->has_video_info = ivd_iv_db_util_has_video_info(
                                            get_msg->db_handle,
                                            get_msg->file_name);
    return MMI_TRUE;
}

static MMI_BOOL ivd_iv_db_get_video_info(ivd_db_video_msg_base *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_video_msg_get_info *get_msg = NULL;
    ivd_db_video_result_info *out = NULL;

    // sqlite working vars
    sqlite3_stmt *stmt = NULL;
    kal_int32 res = 0;

    // for check file modification
    FS_HANDLE hFile = NULL;
    UINT file_size_db = 0;
    UINT file_size_fs = 0;
    MMI_BOOL should_remove_entry = MMI_FALSE;

    // for decoding thumbnails
    GDI_RESULT gdi_res;
    GDI_HANDLE thumbLayer = GDI_LAYER_EMPTY_HANDLE;
    const BPP = 2;
    U8* jpeg_buf = NULL;
    U32 jpeg_buf_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg->type_id == 'GVID');
    ASSERT(msg->msg_size == sizeof(ivd_db_video_msg_get_info));
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SRVMC][IVD] ivd_iv_db_get_video_info enter @%d", __LINE__);
    get_msg = (ivd_db_video_msg_get_info*)msg;
    out = (ivd_db_video_result_info*)get_msg->result;
    if(NULL == out)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_VIDEO_RESULT_BUFFER_IS_NULL);
        ASSERT(0);
    }
    
    res = sqlite3_prepare_v2(
                        get_msg->db_handle->db, 
                        "SELECT duration_sec, bookmark_sec, jpeg_thumb, thumb_size_bytes, file_size FROM video_info WHERE filename=?",
                        -1, 
                        &stmt, 
                        NULL);
                        
    res = sqlite3_bind_kal_wstr(stmt, 1, get_msg->file_name);
    do
    {
        // there should be only 1 or 0 match
        if(sqlite3_step(stmt) != SQLITE_ROW)
        {
            kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SRVMC][IVD] ivd_iv_db_get_video_info fail @%d", __LINE__);
            out->result_code = MMI_IVD_ERR_EMPTY;
            break;
        }
        
        out->result_code = MMI_IVD_OK;
        out->duration_sec = sqlite3_column_kal_uint32(stmt, 0);
        out->bookmark_sec = sqlite3_column_kal_uint32(stmt, 1);
        jpeg_buf = (U8*)sqlite3_column_blob(stmt, 2);
        jpeg_buf_size = sqlite3_column_kal_uint32(stmt, 3);
        file_size_db = sqlite3_column_kal_uint32(stmt, 4);
        
        // check if the file is modified
        SRV_MEDIACACHE_START_MEASURE("FSO");
        hFile = FS_Open((WCHAR*)get_msg->file_name, FS_READ_ONLY);
        file_size_fs = 0;
        if(hFile > 0)
        {
            FS_GetFileSize(hFile, &file_size_fs);
            FS_Close(hFile);
            hFile = NULL;
        }
        SRV_MEDIACACHE_STOP_MEASURE("FSO");
        
        if (0 == file_size_fs ||
            (file_size_db != file_size_fs))
        {
            out->result_code = MMI_IVD_ERR_EMPTY;
            should_remove_entry = MMI_TRUE;
            kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SRVMC][IVD] ivd_iv_db_get_video_info fail @%d", __LINE__);
            break;
        }

        // decode thumbnail and fill output buffer
        if(out->thumb_buf_ptr &&
           out->thumb_buf_len &&
           out->thumb_buf_len >= out->thumb_width * out->thumb_height * BPP)
        {
            gdi_res = gdi_layer_create_cf_using_outside_memory(
                    g_ivd_db_cntx.g_ivd_db_handle_p->color_format,
                    0,
                    0,
                    out->thumb_width,
                    out->thumb_height,
                    &thumbLayer,
                    out->thumb_buf_ptr,
                    out->thumb_buf_len);
            if(GDI_SUCCEED == gdi_res)
            {
                gdi_layer_push_and_set_active(thumbLayer);
                gdi_layer_set_source_key(MMI_FALSE, GDI_COLOR_TRANSPARENT);
                gdi_res = gdi_image_draw_mem(0, 0, jpeg_buf, GDI_IMAGE_TYPE_JPG, jpeg_buf_size);
                gdi_layer_pop_and_restore_active();
            }
            gdi_layer_free(thumbLayer);
            thumbLayer = NULL;
            if (g_ivd_db_cntx.g_ivd_db_handle_p->is_mark &&
                out->thumb_width > 24 && 
                out->thumb_height > 24)
            {
                U8* m_data_p = out->thumb_buf_ptr;
                U8* m_data_end_p = out->thumb_buf_ptr + out->thumb_width * 24 * g_ivd_db_cntx.g_ivd_db_handle_p->bytes_per_pixel;
                S32 m_pitch = out->thumb_width * g_ivd_db_cntx.g_ivd_db_handle_p->bytes_per_pixel;
                S32 m_length = 24 * g_ivd_db_cntx.g_ivd_db_handle_p->bytes_per_pixel;
                while (m_data_p<m_data_end_p)
                {
                    memset(m_data_p,0xAA,m_length);
                    m_data_p += m_pitch;
                }
            }

            // thumbnail decode fail, treat as no info
            if(GDI_SUCCEED != gdi_res)
            {
                out->result_code = MMI_IVD_ERR_EMPTY;
                kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SRVMC][IVD] ivd_iv_db_get_video_info fail @%d", __LINE__);
            }
        }
    }while(0);
    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);

    // see if we need to remove entry
    if(MMI_TRUE == should_remove_entry)
    {
        ivd_iv_db_remove_video_info_by_filename(get_msg->db_handle, (const WCHAR*)get_msg->file_name);
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  ivd_iv_db_put_video
 * DESCRIPTION
 *  insert video info in IVD task
 * PARAMETERS
 *  *ilm_ptr    [IN]    MSG pointer
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL ivd_iv_db_put_video_info(ivd_db_video_msg_base *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_video_msg_put_info *put_msg = NULL;
    sqlite3_stmt *stmt = NULL;
    kal_int32 res = 0;
    S32 encode_req_size = 0;
    GDI_RESULT gdi_res = GDI_FAILED;
    ivd_db_video_result_info *out = NULL;
    MMI_BOOL already_has_info = MMI_FALSE;
    UINT file_size_fs = 0;
    FS_HANDLE hFile = NULL;
    MMI_BOOL encode_to_file = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg->type_id == 'PVID');
    ASSERT(msg->msg_size == sizeof(ivd_db_video_msg_put_info));
    put_msg = (ivd_db_video_msg_put_info*)msg;
    out = (ivd_db_video_result_info*)msg->result;

    // get file size
    // to allow check if the file is modified when query
    SRV_MEDIACACHE_START_MEASURE("FSO");
    hFile = FS_Open((WCHAR*)put_msg->file_name, FS_READ_ONLY);
    file_size_fs = 0;
    if(hFile > 0)
    {
        FS_GetFileSize(hFile, &file_size_fs);
        FS_Close(hFile);
        hFile = NULL;
    }
    SRV_MEDIACACHE_STOP_MEASURE("FSO");

    #if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
    if((IVD_DB_TEMP_BUF_LEN < ((gdi_bits_per_pixel(put_msg->db_handle->color_format) / 8) * put_msg->thumb_width * put_msg->thumb_height)))
    {
        encode_to_file = MMI_TRUE;
    }
    else
    {
        encode_to_file = MMI_FALSE;
    }
    #endif
    // encode pixel buffer into JPEG data
    gdi_res = ivd_iv_db_encode_image_to_data_buffer(
                                put_msg->db_handle,
                                &encode_req_size,
                                put_msg->thumb_buf_ptr,
                                put_msg->db_handle->color_format,
                                put_msg->thumb_width,
                                put_msg->thumb_height
                                );

    // insert or update information, depending on if the video info already exists or not.
    already_has_info = ivd_iv_db_util_has_video_info(put_msg->db_handle, put_msg->file_name);

    if(MMI_FALSE == already_has_info)
    {
        sqlite3_prepare_v2(
                       put_msg->db_handle->db, 
                       "INSERT INTO video_info(filename, duration_sec, jpeg_thumb, thumb_size_bytes, file_size) values(?,?,?,?,?)",
                       -1, &stmt, NULL);
        sqlite3_bind_kal_wstr(stmt, 1, put_msg->file_name);
        sqlite3_bind_kal_uint32(stmt, 2, put_msg->duration_sec);
        #if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
        if(!encode_to_file)
        {
            res = sqlite3_bind_blob(stmt, 3, put_msg->db_handle->db_temp_buf, encode_req_size, SQLITE_STATIC);
        }
        else
        {
            res = sqlite3_bind_zeroblob(stmt, 3, encode_req_size);
        }
        #else
        res = sqlite3_bind_blob(stmt, 3, put_msg->db_handle->io_buf.o_buffer, encode_req_size, SQLITE_STATIC);
        #endif
        sqlite3_bind_kal_uint32(stmt, 4, encode_req_size);
        sqlite3_bind_kal_uint32(stmt, 5, file_size_fs);
    }
    else
    {
        // already has video info, UPDATE instead of INSERT
        sqlite3_prepare_v2(
                       put_msg->db_handle->db, 
                       "UPDATE video_info SET duration_sec=?, jpeg_thumb=?, thumb_size_bytes=?, file_size=? WHERE filename=?",
                       -1, &stmt, NULL);
        sqlite3_bind_kal_uint32(stmt, 1, put_msg->duration_sec);
        #if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
        if(!encode_to_file)
        {
            res = sqlite3_bind_blob(stmt, 2, put_msg->db_handle->db_temp_buf, encode_req_size, SQLITE_STATIC);
        }
        else
        {
            res = sqlite3_bind_zeroblob(stmt, 2, encode_req_size);
        }
        #else
        res = sqlite3_bind_blob(stmt, 2, put_msg->db_handle->io_buf.o_buffer, encode_req_size, SQLITE_STATIC);
        #endif
        sqlite3_bind_kal_uint32(stmt, 3, encode_req_size);
        sqlite3_bind_kal_uint32(stmt, 4, file_size_fs);
        sqlite3_bind_kal_wstr(stmt, 5, put_msg->file_name);
    }
    
    res = sqlite3_step(stmt);
    if(SQLITE_DONE != res)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_VIDEO_PUT_VIDEO_INFO_FAIL_D, res);
        if(out)
        {
            out->result_code = MMI_IVD_ERR_PUT_SKIP;
        }
    }
    else
    {
        // insert ROW success
        #if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
        // incremental BLOB insert on 
        do
        {
            ivd_db_handle_struct *db_handle = put_msg->db_handle;
            sqlite3_blob *pBlob = NULL;
            sqlite3_int64 rowid = sqlite3_last_insert_rowid(db_handle->db);
            if(MMI_FALSE == encode_to_file)
            {
                break;
            }
            res = sqlite3_blob_open(
                db_handle->db,
                "main",
                "video_info",
                "jpeg_thumb",
                rowid,
                1,          // for read-write
                &pBlob);
            if(pBlob)
            {
                // read cluster by cluser
                U32 written = 0;
                U32 WRITE_UNIT = IVD_DB_TEMP_BUF_LEN;
                U32 read = WRITE_UNIT;
                U8 *temp = NULL;
                int blobSize = sqlite3_blob_bytes(pBlob);
                FS_HANDLE hFile = NULL;
                kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[IVD] insert blob to video_info begin");
                // use temp buffer to store path and open file
                ivd_iv_db_get_temp_file_path(db_handle, (CHAR*)db_handle->db_temp_buf, IVD_DB_TEMP_BUF_LEN);
                hFile = FS_Open((WCHAR*)db_handle->db_temp_buf, FS_READ_ONLY);
                // then use temp buffer to read file content into blob
                temp = db_handle->db_temp_buf;
                while(hFile > 0 && FS_NO_ERROR == FS_Read(hFile, temp, WRITE_UNIT, &read) && read > 0)
                {
                    res = sqlite3_blob_write(pBlob, temp, read, written);
                    written += read;
                }
                if(hFile > 0)
                {
                    FS_Close(hFile);
                    hFile = NULL;
                }
                res = sqlite3_blob_close(pBlob);
                pBlob = NULL;
                kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[IVD] insert blob to video_info end");
            }
        }while(0);
        #endif
        
        if(out)
        {
            out->result_code = MMI_IVD_OK;
        }
    }
    sqlite3_finalize(stmt);

    // force commit
    ivd_iv_db_sqlite3_exec(ivd_iv_db_cmd_commit_transcation, NULL);
    ivd_iv_db_sqlite3_exec(ivd_iv_db_cmd_begin_transcation, NULL);
    return MMI_TRUE;
}

static MMI_BOOL ivd_iv_db_update_video_duration(ivd_db_video_msg_base *msg)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_video_msg_update_total_duration *update_msg = NULL;
    sqlite3_stmt *stmt = NULL;
    kal_int32 res = 0;
    ivd_db_video_result_base *out = NULL;
    UINT file_size_fs = 0;
    FS_HANDLE hFile = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    update_msg = (ivd_db_video_msg_update_total_duration*)msg;
    ASSERT(update_msg);
    ASSERT(msg->type_id == 'UTTD');
    ASSERT(msg->msg_size == sizeof(ivd_db_video_msg_update_total_duration));
    out = update_msg->result;
    
    // insert or update information, depending on if the video info already exists or not.
    res = sqlite3_prepare_v2(
                   update_msg->db_handle->db, 
                   "UPDATE video_info SET duration_sec=? WHERE filename=?",
                   -1, &stmt, NULL);
    res = sqlite3_bind_kal_uint32(stmt, 1, update_msg->total_duration);
    res = sqlite3_bind_kal_wstr(stmt, 2, update_msg->file_name);
    res = sqlite3_step(stmt);
    
    if(SQLITE_DONE != res)
    {
        // MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_VIDEO_UPDATE_VIDEO_DURATION_FAIL_D, res);
        if(out)
        {
            out->result_code = MMI_IVD_ERR_PUT_SKIP;
        }
    }
    else
    {
        if(out)
        {
            out->result_code = MMI_IVD_OK;
        }
    }
    sqlite3_finalize(stmt);

    // force commit
    ivd_iv_db_sqlite3_exec(ivd_iv_db_cmd_commit_transcation, NULL);
    ivd_iv_db_sqlite3_exec(ivd_iv_db_cmd_begin_transcation, NULL);
    return MMI_TRUE;
}

static MMI_BOOL ivd_iv_db_update_video_last_play(ivd_db_video_msg_base *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_video_msg_put_bookmark *update_msg = NULL;
    sqlite3_stmt *stmt = NULL;
    kal_int32 res = 0;
    ivd_db_video_result_info *out = NULL;
    MMI_BOOL already_has_info = MMI_FALSE;
    UINT file_size_fs = 0;
    FS_HANDLE hFile = NULL;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    update_msg = (ivd_db_video_msg_put_bookmark*)msg;
    ASSERT(update_msg);
    ASSERT(msg->type_id == 'PBMK');
    ASSERT(msg->msg_size == sizeof(ivd_db_video_msg_put_bookmark));
    out = (ivd_db_video_result_info*)msg->result;
    
    // insert or update information, depending on if the video info already exists or not.
    already_has_info = ivd_iv_db_util_has_video_info(update_msg->db_handle, update_msg->file_name);

    if(MMI_FALSE == already_has_info)
    {
        // get file size
        // to allow check if the file is modified when query
        SRV_MEDIACACHE_START_MEASURE("FSO");
        hFile = FS_Open((WCHAR*)update_msg->file_name, FS_READ_ONLY);
        file_size_fs = 0;
        if(hFile > 0)
        {
            FS_GetFileSize(hFile, &file_size_fs);
            FS_Close(hFile);
            hFile = NULL;
        }
        SRV_MEDIACACHE_STOP_MEASURE("FSO");
        
        sqlite3_prepare_v2(
                       update_msg->db_handle->db, 
                       "INSERT INTO video_info(filename, bookmark_sec, access_time, file_size) values(?,?,?)",
                       -1, &stmt, NULL);
        res = sqlite3_bind_kal_wstr(stmt, 1, update_msg->file_name);
        res = sqlite3_bind_kal_uint32(stmt, 2, update_msg->bookmark_sec);
        res = sqlite3_bind_double(stmt, 3, update_msg->access_time);
        res = sqlite3_bind_kal_uint32(stmt, 4, file_size_fs);
    }
    else
    {
        res = sqlite3_prepare_v2(
                       update_msg->db_handle->db, 
                       "UPDATE video_info SET bookmark_sec=?, access_time=? WHERE filename=?",
                       -1, &stmt, NULL);
        res = sqlite3_bind_kal_uint32(stmt, 1, update_msg->bookmark_sec);
        res = sqlite3_bind_double(stmt, 2, update_msg->access_time);
        res = sqlite3_bind_kal_wstr(stmt, 3, update_msg->file_name);
    }

    res = sqlite3_step(stmt);
    if(SQLITE_DONE != res)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_VIDEO_UPDATE_VIDEO_LAST_PLAY_FAIL_D, res);
        if(out)
        {
            out->result_code = MMI_IVD_ERR_PUT_SKIP;
        }
    }
    else
    {
        if(out)
        {
            out->result_code = MMI_IVD_OK;
        }
    }
    sqlite3_finalize(stmt);

    // force commit
    ivd_iv_db_sqlite3_exec(ivd_iv_db_cmd_commit_transcation, NULL);
    ivd_iv_db_sqlite3_exec(ivd_iv_db_cmd_begin_transcation, NULL);
    return MMI_TRUE;
}

static MMI_BOOL ivd_iv_db_get_video_last_play(ivd_db_video_msg_base *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_video_msg_get_bookmark *get_msg = NULL;
    ivd_db_video_result_bookmark *out = NULL;
    sqlite3_stmt *stmt = NULL;
    kal_int32 res = 0;
    // for check file modification
    FS_HANDLE hFile = NULL;
    UINT file_size_db = 0;
    UINT file_size_fs = 0;
    MMI_BOOL should_remove_entry = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg->type_id == 'GBMK');
    ASSERT(msg->msg_size == sizeof(ivd_db_video_msg_get_bookmark));
    get_msg = (ivd_db_video_msg_get_bookmark*)msg;
    out = (ivd_db_video_result_bookmark*)get_msg->result;
    ASSERT(out);
    
    // insert bookmark information.
    res = sqlite3_prepare_v2(
                       get_msg->db_handle->db, 
                       "SELECT bookmark_sec, file_size from video_info WHERE filename=?",
                       -1, &stmt, NULL);
                       
    res = sqlite3_bind_kal_wstr(stmt, 1, get_msg->file_name);
    
    if(sqlite3_step(stmt) != SQLITE_ROW)
    {
        out->result_code = MMI_IVD_ERR_EMPTY;
    }
    else
    {
        file_size_db = sqlite3_column_kal_uint32(stmt, 1);
        // check if the file is modified
        SRV_MEDIACACHE_START_MEASURE("FSO");
        hFile = FS_Open((WCHAR*)get_msg->file_name, FS_READ_ONLY);
        file_size_fs = 0;
        if(hFile > 0)
        {
            FS_GetFileSize(hFile, &file_size_fs);
            FS_Close(hFile);
            hFile = NULL;
        }
        SRV_MEDIACACHE_STOP_MEASURE("FSO");
        if (0 == file_size_fs ||
            (file_size_db != file_size_fs))
        {
            out->result_code = MMI_IVD_ERR_EMPTY;
            should_remove_entry = MMI_TRUE;
        }
        else
        {
            out->result_code = MMI_IVD_OK;
            out->bookmark_sec = sqlite3_column_kal_uint32(stmt, 0);
        }
    }
    sqlite3_finalize(stmt);

    // see if we need to remove entry
    if(MMI_TRUE == should_remove_entry)
    {
        ivd_iv_db_remove_video_info_by_filename(get_msg->db_handle, get_msg->file_name);
    }
    return MMI_TRUE;
}

static MMI_BOOL ivd_iv_db_get_most_recent_play_video(ivd_db_video_msg_base *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_video_result_last_play_info *out = NULL;
    sqlite3_stmt *stmt = NULL;
    kal_int32 res = 0;

    kal_wchar* file_name = NULL;
    U8 *jpeg_buf = NULL;
    U32 jpeg_buf_size = 0;
    GDI_RESULT gdi_res = 0;
    GDI_HANDLE thumbLayer = NULL;
    const U32 BPP = 2;
    // for check file modification
    FS_HANDLE hFile = NULL;
    UINT file_size_db = 0;
    UINT file_size_fs = 0;
    MMI_BOOL should_remove_entry = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg->type_id == 'RCNT');
    ASSERT(msg->msg_size == sizeof(ivd_db_video_msg_base));
    out = (ivd_db_video_result_last_play_info*)msg->result;
    ASSERT(out);
    
    // query most recent played video
    res = sqlite3_prepare_v2(
                       msg->db_handle->db, 
                       "SELECT filename, duration_sec, bookmark_sec, jpeg_thumb, thumb_size_bytes, file_size from video_info WHERE (bookmark_sec != 0) ORDER BY access_time DESC",
                       -1, &stmt, NULL);

    do
    {
        if(SQLITE_ROW != sqlite3_step(stmt))
        {
            // no entires found
            out->result_code = MMI_IVD_ERR_EMPTY;
            break;
        }

        // entires found, fill info
        out->result_code = MMI_IVD_OK;
        file_name = (kal_wchar*)sqlite3_column_kal_wstr(stmt, 0);
        mmi_wcsncpy(out->file_name, file_name, SRV_FMGR_PATH_MAX_LEN);
        
        out->duration_sec = sqlite3_column_kal_uint32(stmt, 1);
        out->bookmark_sec = sqlite3_column_kal_uint32(stmt, 2);

        jpeg_buf = (U8*)sqlite3_column_blob(stmt, 3);
        jpeg_buf_size = sqlite3_column_kal_uint32(stmt, 4);
        file_size_db = sqlite3_column_kal_uint32(stmt, 5);

        
        // check if the file is modified
        SRV_MEDIACACHE_START_MEASURE("FSO");
        hFile = FS_Open((WCHAR*)file_name, FS_READ_ONLY);
        file_size_fs = 0;
        if(hFile > 0)
        {
            FS_GetFileSize(hFile, &file_size_fs);
            FS_Close(hFile);
            hFile = NULL;
        }
        SRV_MEDIACACHE_STOP_MEASURE("FSO");
        
        if (0 == file_size_fs ||
            (file_size_db != file_size_fs))
        {
            out->result_code = MMI_IVD_ERR_EMPTY;
            should_remove_entry = MMI_TRUE;
            break;
        }
        

        // decode thumbnail and fill output buffer
        if(out->thumb_buf_ptr &&
           out->thumb_buf_len &&
           out->thumb_buf_len >= out->thumb_width * out->thumb_height * BPP)
        {
            gdi_res = gdi_layer_create_cf_using_outside_memory(
                    g_ivd_db_cntx.g_ivd_db_handle_p->color_format,
                    0,
                    0,
                    out->thumb_width,
                    out->thumb_height,
                    &thumbLayer,
                    out->thumb_buf_ptr,
                    out->thumb_buf_len);
            if(GDI_SUCCEED == gdi_res)
            {
                gdi_layer_push_and_set_active(thumbLayer);
                gdi_layer_set_source_key(MMI_FALSE, GDI_COLOR_TRANSPARENT);
                gdi_res = gdi_image_draw_mem(0, 0, jpeg_buf, GDI_IMAGE_TYPE_JPG, jpeg_buf_size);
                gdi_layer_pop_and_restore_active();
            }
            gdi_layer_free(thumbLayer);
            thumbLayer = NULL;
        }
        
        
    }while(0);

    sqlite3_finalize(stmt);

    // see if we need to remove entry
    if(MMI_TRUE == should_remove_entry)
    {
        ivd_iv_db_remove_video_info_by_filename(msg->db_handle, file_name);
    }
    
    return MMI_TRUE;
}

static double compute_julian_day(applib_time_struct *p)
{
    kal_int32 Y, M, D, A, B, X1, X2;
    double rJD;

    Y = p->nYear;
    M = p->nMonth;
    D = p->nDay;

    if (M <= 2)
    {
        Y--;
        M += 12;
    }

    A = Y / 100;
    B = 2 - A + (A / 4);
    X1 = (kal_int32)(365.25 * (Y + 4716));
    X2 = (kal_int32)(30.6001 * (M + 1));
    rJD = X1 + X2 + D + B - 1524.5;
    rJD += (p->nHour * 3600.0 + p->nMin * 60.0 + p->nSec) / 86400.0;

    return rJD;
}

#define INIT_VIDEO_MSG_STRUCT(_symbol_ptr, _type, _type_id, _blocking, _db_handle, _stub_func) \
                                                        _type *_symbol_ptr = NULL;\
                                                        _symbol_ptr = (_type*)construct_local_para(sizeof(_type), TD_CTRL);\
                                                        _symbol_ptr->type_id = _type_id;\
                                                        _symbol_ptr->msg_size = sizeof(_type);\
                                                        _symbol_ptr->blocking_call = _blocking;\
                                                        _symbol_ptr->db_handle = _db_handle;\
                                                        _symbol_ptr->result = NULL;\
                                                        _symbol_ptr->handler_func = _stub_func;

extern void ivd_ivsrv_db_update_video_bookmark_blocking(ivd_db_handle_struct *db_handle, WCHAR *path, U32 bookmark_sec)
{
    applib_time_struct rtc_time;
    INIT_VIDEO_MSG_STRUCT(msg, ivd_db_video_msg_put_bookmark, 'PBMK', MMI_TRUE, db_handle, ivd_iv_db_update_video_last_play);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // insert additional parameters
    msg->bookmark_sec = bookmark_sec;

    // get access time
    applib_dt_get_rtc_time(&rtc_time);
    msg->access_time = compute_julian_day(&rtc_time);
    
    mmi_wcsncpy(msg->file_name, path, SRV_FMGR_PATH_MAX_LEN);
    
    ivd_ivsrv_db_send_video_msg((ivd_db_video_msg_base*)msg);
}

extern void ivd_ivsrv_db_update_video_total_duration_blocking(ivd_db_handle_struct *db_handle, WCHAR *path, U32 duration_sec)
{
    applib_time_struct rtc_time;
    INIT_VIDEO_MSG_STRUCT(msg, ivd_db_video_msg_update_total_duration, 'UTTD', MMI_TRUE, db_handle, ivd_iv_db_update_video_duration);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // insert additional parameters
    msg->total_duration = duration_sec;
    mmi_wcsncpy(msg->file_name, path, SRV_FMGR_PATH_MAX_LEN);
    ivd_ivsrv_db_send_video_msg((ivd_db_video_msg_base*)msg);
}

extern void ivd_ivsrv_db_get_video_bookmark_blocking(ivd_db_handle_struct *db_handle, WCHAR *path, U32 *bookmark_sec)
{
    ivd_db_video_result_bookmark result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    INIT_VIDEO_MSG_STRUCT(msg, ivd_db_video_msg_get_bookmark, 'GBMK', MMI_TRUE, db_handle, ivd_iv_db_get_video_last_play);

    // insert additional parameters
    mmi_wcsncpy(msg->file_name, path, SRV_FMGR_PATH_MAX_LEN);
    msg->result = (ivd_db_video_result_base*)&result;
    
    ivd_ivsrv_db_send_video_msg((ivd_db_video_msg_base*)msg);

    // pass results back to client
    if(bookmark_sec && result.result_code == MMI_IVD_OK)
    {
        *bookmark_sec = result.bookmark_sec;
    }
}

extern void ivd_ivsrv_db_get_video_info_blocking(ivd_db_handle_struct *db_handle, WCHAR* path, ivd_db_video_result_info *query_result)
{
    INIT_VIDEO_MSG_STRUCT(msg, ivd_db_video_msg_get_info, 'GVID', MMI_TRUE, db_handle, ivd_iv_db_get_video_info);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg->result = (ivd_db_video_result_base*)query_result;
    mmi_wcsncpy(msg->file_name, path, SRV_FMGR_PATH_MAX_LEN);
    
    ivd_ivsrv_db_send_video_msg((ivd_db_video_msg_base*)msg);
}

extern void ivd_ivsrv_db_put_video_info_blocking(ivd_db_handle_struct *db_handle, WCHAR* path, ivd_db_video_result_info *video_info)
{
    INIT_VIDEO_MSG_STRUCT(msg, ivd_db_video_msg_put_info, 'PVID', MMI_TRUE, db_handle, ivd_iv_db_put_video_info);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg->duration_sec = video_info->duration_sec;
    msg->bookmark_sec = video_info->bookmark_sec;
    msg->thumb_width = video_info->thumb_width;
    msg->thumb_height = video_info->thumb_height;
    msg->thumb_buf_len = video_info->thumb_buf_len;
    msg->thumb_buf_ptr = video_info->thumb_buf_ptr;
    mmi_wcsncpy(msg->file_name, path, SRV_FMGR_PATH_MAX_LEN);
    
    ivd_ivsrv_db_send_video_msg((ivd_db_video_msg_base*)msg);
}

extern void ivd_ivsrv_db_remove_video_info_by_name(ivd_db_handle_struct *db_handle, const WCHAR *path, ivd_req_callback callback, void *userdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_remove_img_req_struct *local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (db_handle->is_remove_msg_sent == MMI_TRUE || db_handle->is_db_inited == MMI_FALSE)
    {
        return;
    }
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SRVMC][IVD]ivd_ivsrv_db_remove_video_info_by_name");
    local_para_ptr = (ivd_db_remove_img_req_struct*) construct_local_para(sizeof(ivd_db_remove_img_req_struct), TD_CTRL);
    local_para_ptr->db_handle = db_handle;
    local_para_ptr->callback = callback;
    local_para_ptr->user_data = userdata;
    local_para_ptr->remove_type = MMI_IVD_REMOVE_IMG_TYPE_VIDEO;
    memcpy(local_para_ptr->path, path, IVD_FILE_MAX_PATH_LEN);
    db_handle->is_remove_msg_sent = MMI_TRUE;
    ivd_iv_db_send_msg(MOD_MMI, MOD_IVD, MSG_ID_IVD_DB_REMOVE_IMG_REQ, local_para_ptr);
}

extern void ivd_ivsrv_db_get_most_recent_play_video_blocking(ivd_db_handle_struct *db_handle, ivd_db_video_result_last_play_info *query_result)
{
    INIT_VIDEO_MSG_STRUCT(msg, ivd_db_video_msg_base, 'RCNT', MMI_TRUE, db_handle, ivd_iv_db_get_most_recent_play_video);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg->result = (ivd_db_video_result_base*)query_result;
    
    ivd_ivsrv_db_send_video_msg((ivd_db_video_msg_base*)msg);
}

extern void ivd_ivsrv_db_has_video_info_blocking(ivd_db_handle_struct *db_handle, WCHAR *path, ivd_db_video_result_has_info *query_result)
{
    INIT_VIDEO_MSG_STRUCT(msg, ivd_db_video_msg_has_info, 'INFO', MMI_TRUE, db_handle, ivd_iv_db_has_video_info);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg->result = (ivd_db_video_result_base*)query_result;
    mmi_wcsncpy(msg->file_name, path, SRV_FMGR_PATH_MAX_LEN);
    
    ivd_ivsrv_db_send_video_msg((ivd_db_video_msg_base*)msg);
}

void ivd_ivsrv_db_send_video_msg(ivd_db_video_msg_base *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 event_group = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // send the ILM
    ivd_iv_db_send_msg(MOD_MMI, MOD_IVD, MSG_ID_IVD_DB_VDO_REQ, (void*)msg);

    // if blocking, wait for event
    if(msg->blocking_call)
    {
        kal_retrieve_eg_events(g_ivd_db_cntx.g_ivd_iv_event, IVD_IV_DATABASE_GET, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
    }
}

#endif /* __COSMOS_MMI_PACKAGE__ */




/*****************************************************************************
* Scalado related code
*****************************************************************************/

#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
/*****************************************************************************
 * FUNCTION
 *  ivd_ivsrv_db_put_img
 * DESCRIPTION
 *  image viewer service put image to database
 * PARAMETERS
 *  *img_info       [IN]    image info
 *  callback        [IN]    callback function
 * RETURNS
 *  void
 *****************************************************************************/
void ivd_ivsrv_db_put_meta(ivd_db_meta_info_struct *meta_info, ivd_req_callback callback, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_put_meta_req_struct *local_para_ptr;
    U32 date, time;
    applib_time_struct   rtc_time;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (meta_info->db_handle->io_buf.meta_state != MMI_IVD_IO_BUF_STATE_IDLE)
    {
        return;
    }

    meta_info->db_handle->io_buf.meta_state = MMI_IVD_IO_BUF_STATE_PUT;
    local_para_ptr = (ivd_db_put_meta_req_struct*) construct_local_para(sizeof(ivd_db_put_meta_req_struct), TD_CTRL);
    
    local_para_ptr->db_handle = meta_info->db_handle;
    local_para_ptr->callback = callback;
    local_para_ptr->db_handle->io_buf.i_seq_id++;
    local_para_ptr->seq_id = local_para_ptr->db_handle->io_buf.i_seq_id;
    local_para_ptr->user_data = user_data;
    local_para_ptr->err_group = meta_info->err_group;
    local_para_ptr->err_code = meta_info->err_code;
    local_para_ptr->db_handle->buffer = NULL;

    applib_dt_get_rtc_time(&rtc_time);
    date = rtc_time.nYear % 10;
    date = date * 100 + (rtc_time.nMonth % 100);
    date = date * 100 + (rtc_time.nDay % 100);
    local_para_ptr->sys_date = date;

    time = rtc_time.nHour % 24;
    time = time * 100 + (rtc_time.nMin % 100);
    local_para_ptr->sys_time = time;
    
    memcpy(local_para_ptr->path, meta_info->path, IVD_FILE_MAX_PATH_LEN);
    
    ivd_iv_db_send_msg(MOD_MMI, MOD_IVD, MSG_ID_IVD_DB_PUT_META_REQ, local_para_ptr);
}

void ivd_iv_db_put_meta(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_put_meta_req_struct *local_para_ptr;
    ivd_db_put_meta_rsp_struct *rsp_local_para_ptr;
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_META_START_TO_PUT_META_D, __LINE__);
    
    local_para_ptr = (ivd_db_put_meta_req_struct*)ilm_ptr->local_para_ptr;
    g_ivd_db_cntx.g_ivd_db_handle_p = local_para_ptr->db_handle;
    ret = ivd_iv_db_write_meta2db(local_para_ptr);
    rsp_local_para_ptr = (ivd_db_put_meta_rsp_struct*) construct_local_para(sizeof(ivd_db_put_meta_rsp_struct), TD_CTRL);
    rsp_local_para_ptr->callback = local_para_ptr->callback;
    rsp_local_para_ptr->user_data = local_para_ptr->user_data;
    rsp_local_para_ptr->db_handle = g_ivd_db_cntx.g_ivd_db_handle_p;
    if (ret >= 0)
    {
        rsp_local_para_ptr->error_code = 0;
    }
    else
    {
        rsp_local_para_ptr->error_code = -1;
    }
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_META_END_TO_PUT_META_D, __LINE__);
    
    ////TODO
    ivd_iv_db_send_msg(MOD_IVD, MOD_MMI, MSG_ID_IVD_DB_PUT_META_RSP, rsp_local_para_ptr);
}


S32 ivd_iv_db_write_meta2db(ivd_db_put_meta_req_struct *local_para_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sqlite3_stmt *stmt_p = NULL;
    S32 buffer_size;
    S32 ret = MMI_IVD_ERR_PUT_SKIP;
    const CHAR *cmd = ivd_iv_db_cmd_insert_meta;
    U8  *buffer = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ivd_db_cntx.g_ivd_db_handle_p = local_para_ptr->db_handle;
    if (local_para_ptr->db_handle->io_buf.i_seq_id == local_para_ptr->seq_id)
    {
        if (local_para_ptr->db_handle->is_db_stopping == MMI_FALSE)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVD_INFO_DB_NEED_UPDATE);
            ret = sqlite3_prepare(
                g_ivd_db_cntx.g_ivd_db_handle_p->db,
                cmd,
                strlen(cmd),
                &stmt_p,
                NULL);
            if (local_para_ptr->db_handle->buffer)
            {                
                buffer = local_para_ptr->db_handle->buffer;
                buffer_size = local_para_ptr->db_handle->length;
            }
            else
            {
                buffer = local_para_ptr->db_handle->io_buf.meta_buffer;
                buffer_size = local_para_ptr->db_handle->io_buf.meta_length;
                ASSERT(buffer);
            }

            if (buffer_size > 0 && ret == 0)
            {
                /* table meta                                                                                                 *
                 *     1           2       3           4            5
                 *     (filename,  data,   buf_length  update_time  update_date
                 */
                /*filename 1 */
                SRV_MEDIACACHE_START_MEASURE("DW1");

                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_META_START_TO_SQLITE3_BIND_TEXT16_D, __LINE__);
                ret = sqlite3_bind_text16(stmt_p, 1, 
                    local_para_ptr->path, 
                    mmi_ucs2strlen(local_para_ptr->path) * 2, 
                    SQLITE_STATIC);
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_META_END_TO_SQLITE3_BIND_TEXT16_D, __LINE__);
                
                /*data 2 */
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_META_START_TO_SQLITE3_BIND_BLOB_D, __LINE__);
                ret = sqlite3_bind_blob(stmt_p, 2, buffer, buffer_size, SQLITE_STATIC);
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_META_END_TO_SQLITE3_BIND_BLOB_D, __LINE__);
                
                /*buf_length 3 */
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_META_START_TO_SQLITE3_BIND_INT_D, __LINE__);
                ret = sqlite3_bind_int(stmt_p, 3, buffer_size);
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_META_END_TO_SQLITE3_BIND_INT_D, __LINE__);
                
                /*update_time 4 */
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_META_START_TO_SQLITE3_BIND_INT_D, __LINE__);
                ret = sqlite3_bind_int(stmt_p, 8, local_para_ptr->sys_time);
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_META_END_TO_SQLITE3_BIND_INT_D, __LINE__);
                
                /*upate_date 5 */
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_META_START_TO_SQLITE3_BIND_INT_D, __LINE__);
                ret = sqlite3_bind_int(stmt_p, 9, local_para_ptr->sys_date);
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_META_END_TO_SQLITE3_BIND_INT_D, __LINE__);

                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_META_START_TO_SQLITE3_STEP_D, __LINE__);
                ret = sqlite3_step(stmt_p);
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_META_START_TO_SQLITE3_STEP_D, __LINE__);
                
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_META_PUT_META_DB_SIZE_IS_D_D, buffer_size, __LINE__);
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVD_INFO_DB_UPDATE_STEP_RET, ret);
                if (ret != SQLITE_DONE)
                {
                    ret = -2;
                }
                SRV_MEDIACACHE_STOP_MEASURE("DW2");
            }

            if (stmt_p != NULL)
            {
                sqlite3_finalize(stmt_p);
            }
            ivd_iv_db_sqlite3_exec(ivd_iv_db_cmd_commit_transcation, NULL);
            ivd_iv_db_sqlite3_exec(ivd_iv_db_cmd_begin_transcation, NULL);
        }
    }
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVD_INFO_DB_WRITE_TO_DB_END, ret);
    return ret;
}


MMI_BOOL ivd_ivsrv_db_get_meta_blocking(ivd_db_meta_info_struct *meta_info, ivd_req_callback_with_info callback, PS8 *o_buffer, PS32 o_buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_get_meta_req_struct *local_para_ptr;
    MMI_BOOL meta_ret = MMI_FALSE;
    U32 event_group;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (meta_info->db_handle->io_buf.meta_state != MMI_IVD_IO_BUF_STATE_IDLE)
    {
        return MMI_FALSE;
    }

    ASSERT(meta_info->db_handle->io_buf.meta_state != MMI_IVD_IO_BUF_STATE_GET);
    meta_info->db_handle->io_buf.meta_state = MMI_IVD_IO_BUF_STATE_GET;
    
    meta_info->db_handle->io_buf.req_seq_id++;
    meta_info->db_handle->img_get_req.seq_id = meta_info->db_handle->io_buf.req_seq_id;
    meta_info->db_handle->buffer = NULL; //here means, we use meta working buffer.
    meta_info->db_handle->length = 0;
    
    local_para_ptr = (ivd_db_get_meta_req_struct*) construct_local_para(sizeof(ivd_db_get_meta_req_struct), TD_CTRL);
    local_para_ptr->db_handle = meta_info->db_handle;
    local_para_ptr->callback = callback;

    kal_get_time(&local_para_ptr->ticks);
    ivd_iv_db_send_msg(MOD_MMI, MOD_IVD, MSG_ID_IVD_DB_GET_META_REQ, local_para_ptr);
    kal_retrieve_eg_events(g_ivd_db_cntx.g_ivd_iv_event,IVD_IV_DATABASE_GET_META_DONE,KAL_OR_CONSUME,&event_group,KAL_SUSPEND);
    
    if (meta_info->db_handle->error_code == 0)
    {
        *o_buffer = local_para_ptr->db_handle->io_buf.meta_buffer;
        *o_buffer_size = local_para_ptr->db_handle->io_buf.meta_length;
        meta_ret = MMI_TRUE;
    }

    return meta_ret;
}



MMI_BOOL ivd_ivsrv_db_get_meta(ivd_db_meta_info_struct *meta_info, ivd_req_callback_with_info callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_get_meta_req_struct *local_para_ptr;
    MMI_BOOL meta_ret = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (meta_info->db_handle->io_buf.meta_state != MMI_IVD_IO_BUF_STATE_IDLE)
    {
        return MMI_FALSE;
    }

    ASSERT(meta_info->db_handle->io_buf.meta_state != MMI_IVD_IO_BUF_STATE_GET);
    meta_info->db_handle->io_buf.meta_state = MMI_IVD_IO_BUF_STATE_GET;
    
    meta_info->db_handle->io_buf.req_seq_id++;
    meta_info->db_handle->img_get_req.seq_id = meta_info->db_handle->io_buf.req_seq_id;
    meta_info->db_handle->buffer = NULL;
    meta_info->db_handle->length = 0;
    //meta_info->db_handle->meta_buffer = NULL;
    //meta_info->db_handle->meta_length = 0;
    
    local_para_ptr = (ivd_db_get_meta_req_struct*) construct_local_para(sizeof(ivd_db_get_meta_req_struct), TD_CTRL);
    local_para_ptr->db_handle = meta_info->db_handle;
    local_para_ptr->callback = callback;
    
    kal_get_time(&local_para_ptr->ticks);
    ivd_iv_db_send_msg(MOD_MMI, MOD_IVD, MSG_ID_IVD_DB_GET_META_REQ, local_para_ptr);
    
    if (meta_info->db_handle->error_code == 0)
    {
        meta_ret = MMI_TRUE;
    }
    
    return meta_ret;
}

MMI_BOOL ivd_iv_db_get_meta(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_get_meta_req_struct *local_para_ptr;
    ivd_db_get_meta_rsp_struct *rsp_local_para_ptr;
    S32 ret = -1;
    U8* buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_para_ptr = (ivd_db_get_meta_req_struct*)ilm_ptr->local_para_ptr;
    
    if (local_para_ptr->db_handle->is_db_stopping)
    {
        kal_set_eg_events(g_ivd_db_cntx.g_ivd_iv_event,IVD_IV_DATABASE_GET_META_DONE,KAL_OR);
        return -1;
    }

    g_ivd_db_cntx.g_ivd_db_handle_p->ticks = local_para_ptr->ticks;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVD_INFO_GET,g_ivd_db_cntx.g_ivd_db_handle_p->img_get_req.file_size);
    if (local_para_ptr->db_handle->io_buf.meta_buffer == NULL)
    {
        MMI_ASSERT(0);
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_META_START_TO_GET_META_D, __LINE__);    
    if (local_para_ptr->db_handle->buffer != NULL)
    {
        buffer = local_para_ptr->db_handle->buffer;
    }
    else
    {
        buffer= local_para_ptr->db_handle->io_buf.meta_buffer;
    }

    if (local_para_ptr->db_handle->is_db_stopping == MMI_FALSE)
    {
        ret = ivd_iv_db_get_meta_by_filename(buffer, g_ivd_db_cntx.g_ivd_db_handle_p->img_get_req.path);
    }
    else
    {
        ret = -1;
    }

    /* construt response callback */
    rsp_local_para_ptr = (ivd_db_get_meta_rsp_struct*) construct_local_para(sizeof(ivd_db_get_meta_rsp_struct), TD_CTRL);
    rsp_local_para_ptr->db_handle = local_para_ptr->db_handle;
    rsp_local_para_ptr->callback = local_para_ptr->callback;
    rsp_local_para_ptr->ticks = local_para_ptr->ticks;

    if (ret == SQLITE_ROW || (ret == SQLITE_DONE)) // means find successfully
    {
        local_para_ptr->db_handle->error_code = 0;
    }
    else
    {
        local_para_ptr->db_handle->error_code = -1;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_META_END_TO_GET_META_D, __LINE__);
    
    ivd_iv_db_send_msg(MOD_IVD, MOD_MMI, MSG_ID_IVD_DB_GET_META_RSP, rsp_local_para_ptr);
    kal_set_eg_events(g_ivd_db_cntx.g_ivd_iv_event,IVD_IV_DATABASE_GET_META_DONE,KAL_OR);
    return ret;
}


S32 ivd_iv_db_del_meta_by_name(CHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sqlite3_stmt *stmt_p = NULL;
    S32 ret = 0;
    const CHAR *cmd = ivd_iv_db_cmd_del_meta_by_name;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_ivd_db_cntx.g_ivd_db_handle_p)
    {
        return ret;
    }
    ret = sqlite3_prepare(
        g_ivd_db_cntx.g_ivd_db_handle_p->db,
        cmd,
        strlen(cmd),
        &stmt_p,
        NULL);
    if (ret == 0 && g_ivd_db_cntx.g_ivd_db_handle_p->is_db_stopping == MMI_FALSE)
    {
        ret = sqlite3_bind_text16(stmt_p, 1, 
            path, 
            mmi_ucs2strlen(path) * 2, 
            SQLITE_STATIC);
        ret = sqlite3_step(stmt_p);
    }
    if (stmt_p != NULL)
    {
        sqlite3_finalize(stmt_p);
    }
    return ret;
}


S32 ivd_iv_db_del_meta_before_the_date(U32 date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sqlite3_stmt *stmt_p = NULL;
    S32 ret;
    const CHAR *cmd = ivd_iv_db_cmd_del_meta_before_the_date;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_MEDIACACHE_START_MEASURE("DMD");
    ret = sqlite3_prepare(
        g_ivd_db_cntx.g_ivd_db_handle_p->db,
        cmd,
        strlen(cmd),
        &stmt_p,
        NULL);
    if (ret == 0 && g_ivd_db_cntx.g_ivd_db_handle_p->is_db_stopping == MMI_FALSE)
    {
        ret = sqlite3_bind_int(stmt_p, 1, date);
        ret = sqlite3_step(stmt_p);
    }
    if (stmt_p != NULL)
    {
        sqlite3_finalize(stmt_p);
    }
    SRV_MEDIACACHE_STOP_MEASURE("DMD");
    return ret;
}


S32 ivd_iv_db_get_meta_by_filename(PS8 o_buffer, CHAR *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sqlite3_stmt *stmt_p = NULL;
    S32 ret = MMI_IVD_ERR_EMPTY;
    S32 buffer_size;
    const CHAR *cmd = ivd_iv_db_cmd_get_meta_by_filename;
    U8  *buffer = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_MEDIACACHE_START_MEASURE("DB3");
    ret = sqlite3_prepare(
        g_ivd_db_cntx.g_ivd_db_handle_p->db,
        cmd,
        strlen(cmd),
        &stmt_p,
        NULL);
    if (ret == 0 && g_ivd_db_cntx.g_ivd_db_handle_p->is_db_stopping == MMI_FALSE)
    {
        SRV_MEDIACACHE_START_MEASURE("DBQ");
        ret = sqlite3_bind_text16(stmt_p, 1, filename, mmi_ucs2strlen(filename) * 2, SQLITE_STATIC);
        ret = sqlite3_step(stmt_p);
        SRV_MEDIACACHE_STOP_MEASURE("DBQ");
    }
    if (ret == SQLITE_ROW  && g_ivd_db_cntx.g_ivd_db_handle_p->is_db_stopping == MMI_FALSE)
    {
        /* table meta                                                                                                 *
        *     0           1       2          
        *     (filename,  data,   buf_length */

        SRV_MEDIACACHE_START_MEASURE("DBR");
        buffer = (U8*)sqlite3_column_blob(stmt_p, 1);
        buffer_size = sqlite3_column_int64(stmt_p, 2);
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_META_GET_META_SIZE_IS_D_D, buffer_size, __LINE__);
        SRV_MEDIACACHE_STOP_MEASURE("DBR");
                    
        memcpy(o_buffer, buffer, buffer_size);
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVIVD_META_GET_META_SIZE_IS_D_D, 0, __LINE__);
        ret = MMI_IVD_ERR_EMPTY;
    }
    if (stmt_p != NULL)
    {
        sqlite3_finalize(stmt_p);
    }
    SRV_MEDIACACHE_STOP_MEASURE("DB3");
    return ret;
}


void ivd_ivsrv_db_put_meta_rsp_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_put_meta_rsp_struct* ivd_db_put_meta_rsp_ptr = (ivd_db_put_meta_rsp_struct*)msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ivd_db_put_meta_rsp_ptr->db_handle->io_buf.meta_state = MMI_IVD_IO_BUF_STATE_IDLE;
    if (ivd_db_put_meta_rsp_ptr->callback != NULL)
    {
        (ivd_db_put_meta_rsp_ptr->callback)(ivd_db_put_meta_rsp_ptr->error_code, ivd_db_put_meta_rsp_ptr->user_data);
    }
}


void ivd_ivsrv_db_get_meta_rsp_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_get_meta_rsp_struct* ivd_db_get_meta_rsp_ptr = (ivd_db_get_meta_rsp_struct*)msg;
    ivd_db_metainfo_struct meta_info;
    U32 end_ticks = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_set_eg_events(g_ivd_db_cntx.g_ivd_iv_event,IVD_IV_DATABASE_NB_GET_META_DONE,KAL_OR);

    ivd_db_get_meta_rsp_ptr->db_handle->io_buf.meta_state = MMI_IVD_IO_BUF_STATE_IDLE;
    
    if (ivd_db_get_meta_rsp_ptr->db_handle->io_buf.meta_state != MMI_IVD_IO_BUF_STATE_GET ||
        ivd_db_get_meta_rsp_ptr->db_handle->io_buf.ret_seq_id != ivd_db_get_meta_rsp_ptr->db_handle->io_buf.req_seq_id)
    {
        (ivd_db_get_meta_rsp_ptr->callback)(MMI_IVD_ERR_GET_SKIP, &meta_info, ivd_db_get_meta_rsp_ptr->user_data);
        return;
    }
    
    kal_get_time(&end_ticks);
    kal_print_string_trace(MOD_MMI_MEDIA_APP,TRACE_GROUP_2,"[srvmc]get image from db use ticks=%d",end_ticks - ivd_db_get_meta_rsp_ptr->ticks);
    if (ivd_db_get_meta_rsp_ptr->callback != NULL)
    {
        (ivd_db_get_meta_rsp_ptr->callback)(ivd_db_get_meta_rsp_ptr->err_code, &meta_info, ivd_db_get_meta_rsp_ptr->user_data);
    }
}


#endif /* __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__ */

#else

#include "kal_general_types.h"
#include "syscomp_config.h"

/*****************************************************************************
 * FUNCTION
 *  ivd_create
 * DESCRIPTION
 *  avoid build error
 * PARAMETERS
 *  handle      [OUT]    task handle
 * RETURNS
 *  KAL_FALSE    always false
 *****************************************************************************/
kal_bool ivd_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_FALSE;
}
#endif /* defined(__SRV_MEDIACACHE_DB_SUPPORT__)*/


