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
*  MFreeSrv.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  M-Free download service
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
*
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "vmswitch.h"

#include "MASSrvGprot.h"

#include "DevConfigDef.h"
#include "DevConfigGprot.h"
#include "lcd_sw_rnd.h" /* for LCD size */
#include "PixcomFontEngine.h"
#include "fs_gprot.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "common_nvram_editor_data_item.h"
#include "gdi_include.h"
#include "gui_setting.h"
#include "MREAppMgrSrvGprot.h"
#include "Conversions.h"
#include "verno.h"

#include "mmi_trc.h"
#include "MMI_mre_trc.h"

#include "vmsys.h"
#include "vmpromng.h"
#include "vmsock.h"
#include "vmsim.h"
#include "vmmem.h"
#include "vmio.h"
#include "vmcert.h"
#include "vmgettag.h"
#include "vmopt.h"

#if defined(__MMI_MRE_MSPACE__) && defined(__MRE_CORE_BASE__) && defined(__MRE_SAL_SIM__) && defined(__MRE_SAL_SOCKET__)
#define MAS_SRV_MSPACE
#endif

#define LIS_MAX_SIZE 200 // KB
#define MSPACE_PATH "MSPACE"
#define MAS_PATH_LEN 64

typedef struct
{
    //VM_P_HANDLE handle;
    dl_callback cb;
    void * user_data;
    VMCHAR * ua;
    srv_as_data_query_e qry;
}srv_app_data_t;

typedef struct
{
    U16 app_path[260];
    dl_callback cb;
    void * app_user_data;
    S32 hdl;
    S32 idx;
}srv_app_ctx_t;

typedef enum
{
    E_SRV_RESOLUTION_WVGA,
    E_SRV_RESOLUTION_HVGA,
    E_SRV_RESOLUTION_WQVGA,
    E_SRV_RESOLUTION_QVGA,
    E_SRV_RESOLUTION_LS_QVGA,
    E_SRV_RESOLUTION_QCIF_PLUS,
    E_SRV_RESOLUTION_LSQCIF_PLUS,
    E_SRV_RESOLUTION_QQVGA,
    E_SRV_RESOLUTION_END
}srv_resolution_e;

typedef struct
{
    S8 lang[8];
    srv_resolution_e er;
    U32 app_id;
}srv_lis_record_t;


typedef struct
{
    S32 num;
    S32 freshed;
    U16 * map;
}srv_lis_map_ctx_t;

static S32 is_list_set = 0;
static srv_lis_map_ctx_t g_map_ctx = {0};
static void * int_srv_alloc(U32 size);
static void int_srv_free(void * ptr);
static S32 int_srv_get_drv();
static void int_srv_string_print(const WCHAR * log, S32 idx, S32 line);
static S16 int_srv_get_url_update(CHAR url[], UINT size);
static U16 int_srv_get_server_port(void);
static void int_srv_common_cb(VMINT hdl, void * para);
static U32 int_srv_get_lis_appid();
static S32 int_srv_set_lis_path(const WCHAR * list_path, VMINT size);
static S32 int_srv_get_lis_path(WCHAR * list_path, VMINT size);
static S32 int_srv_gen_lis_path(WCHAR * list_path, VMINT size);
static S32 int_srv_check_lis();
static S32 int_srv_rename_lis();
static const S8 * int_srv_get_lis_ver();
static S32 int_srv_gen_app_path(const srv_as_app_node_t * node, WCHAR * app_path);
static S32 int_srv_get_app_ver(WCHAR * appPath, CHAR buff[], S32 size);
static srv_resolution_e int_srv_get_resolution();
static S32 int_srv_as_lis_query(const srv_as_data_query_t * query_app, dl_callback cb, void * user_data);
static S32 int_srv_as_app_query(const srv_as_data_query_t * query_app, dl_callback cb, void * user_data);
static S32 int_srv_as_app_qd_cb(S32 hdl, void * para);
static S32 int_srv_gen_mapping(const WCHAR * path);

#ifdef __MMI_MRE_MSPACE__
kal_int8 const NVRAM_MSPACE_URL[NVRAM_EF_SRV_MSPACE_SIZE] = 
{
    "http://appupgrade.services-mtk.com/gmas/AppsUpdate"
};
#endif

#ifdef MAS_SRV_MSPACE

extern MMI_BOOL srv_mre_appmgr_get_installed_info(
                    U16 *app_name,
                    srv_mre_appmgr_installed_info_struct *info);
extern MMI_BOOL srv_mre_appmgr_is_app_installed_by_develop_and_name(S32 app_type, U16 *app_name,U16* app_dev,U16 *app_package_name);


static void * int_srv_alloc(U32 size)
{
    return _vm_kernel_calloc((int)size);
}
static void int_srv_free(void * ptr)
{
    _vm_kernel_free(ptr);
}

static  S32 int_srv_get_drv()
{
    int drv = 0;
    
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_S, 23, __LINE__);
    if (FS_NO_ERROR == FS_GetDevStatus((unsigned int)FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE), FS_MOUNT_STATE_ENUM))
    {
        drv = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
        if (drv <= 0)
        {
            drv = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL);
            if (drv <= 0)
            {
                MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E1, 23, __LINE__);
                return -2;
            }
        }
    }
    else
    {
        drv = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL);
        if (drv <= 0)
        {
            MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E2, 23, __LINE__);
            return -3;
        }
    }

    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_S, 23, drv);
    return drv;

}
static S16 int_srv_get_url_update(CHAR url[], UINT size)
{
    S16 error = 0;
    ASSERT(url && size > 0);
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_S, 9, __LINE__);
    ReadRecord(
        NVRAM_EF_SRV_MSPACE_LID,
        1,
        (void*)url,
        size,
        &error); // "http://appupgrade.services-mtk.com/gmas/AppsUpdate"
        
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_LOG, 
        error,
        0,
        0,
        0,
        0,
        url,
        90, __LINE__);
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_S, 9, __LINE__);
    return error;
}

static void int_srv_string_print(const WCHAR * log, S32 idx, S32 line)
{
    CHAR *dst = (CHAR *)int_srv_alloc(MAS_PATH_LEN);
    kal_int32 result = 0;
#ifdef __MMI_CHSET_GB2312__
    result = mmi_chset_convert(
        MMI_CHSET_UCS2, 
        MMI_CHSET_GB2312, 
        (char*)log, 
        dst, 
        MAS_PATH_LEN);
#else
    result = mmi_chset_convert(
        MMI_CHSET_UCS2, 
        MMI_CHSET_ASCII, 
        (char*)log, 
        dst, 
        MAS_PATH_LEN);
#endif
    MMI_PRINT(MOD_MRE, TRACE_GROUP_7, "[DLS] [%s] @[%d][%d]", dst, idx, line);
    int_srv_free(dst);


}
static U16 int_srv_get_server_port(void)
{
    return (U16)80;
}

static void int_srv_common_cb(VMINT hdl, void * para)
{
    vm_common_t * comm = NULL;
    srv_app_data_t * int_data = NULL;
    ASSERT(para);

    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_S, 5, __LINE__);

    comm = (vm_common_t *)para;
    int_data = comm->user_data;
 
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_LOG, 
        comm->state,
        hdl,
        0,
        0,
        0,
        int_data->user_data,
        50, __LINE__);

    switch (comm->state)
    {
    case E_PRELOAD_QUERYING:
    case E_PRELOAD_CONNECTING:
    case E_PRELOAD_CONNECTED:
    case E_PRELOAD_AVAILABLE_UPDATE:
    case E_PRELOAD_NO_UPDATE:
    case E_PRELOAD_HOST_NOT_FOUND:
    case E_PRELOAD_PIPE_CLOSED:
    case E_PRELOAD_PIPE_BROKEN:
    case E_PRELOAD_FAILURE:
    case E_PRELOAD_ERR_PATH:
        {
            vm_common_t * ext_data = (vm_common_t *)para;
            srv_as_cb_app_query_t app_query = {0};
            app_query.state = ext_data->state;
            app_query.user_data = int_data->user_data;//ext_data->user_data;
            
            MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_LOG, 
                hdl,
                app_query.state,
                int_data->cb,
                0,
                0,
                app_query.user_data,
                51, __LINE__);
                
            if (int_data->cb)
            {
                int_data->cb(hdl, &app_query);
            }
        }break;
    case E_PRELOAD_DOWNLOADING:
    case E_PRELOAD_DOWNLOADED:
        {
            vm_preload_recv_data_t * ext_data = (vm_preload_recv_data_t *)para;
            srv_as_cb_app_download_t app_download = {0};
            app_download.state = ext_data->head.state;
            app_download.user_data = int_data->user_data;//ext_data->head.user_data;
            app_download.received = ext_data->received;
            app_download.total = ext_data->total;
            
            MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_LOG, 
                hdl,
                app_download.state,
                int_data->cb,
                app_download.received,
                app_download.total,
                app_download.user_data,
                52, __LINE__);

            if (E_PRELOAD_DOWNLOADED == app_download.state)
            {
                // rename lis.tmp => lis
                if (E_SRV_AS_APP_QUERY_LIS == int_data->qry)
                {
                    if (0 != int_srv_rename_lis())
                    {
                        app_download.state = E_PRELOAD_FAILURE;
                    }
                    else
                    {
                        WCHAR *list_path = (WCHAR *)int_srv_alloc(MAS_PATH_LEN);
                        int_srv_get_lis_path(list_path, MAS_PATH_LEN);
                        g_map_ctx.freshed = 0;
                        int_srv_gen_mapping(list_path);
                        int_srv_free(list_path);
                    }
                }
            }
                
            if (int_data->cb)
            {
                int_data->cb(hdl, &app_download);
            }
        }break;
    default:
        {
            MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E1, 5, __LINE__);
        }break;
    }
    

	
    if (E_PRELOAD_QUERYING != comm->state &&
            E_PRELOAD_CONNECTING != comm->state &&
            E_PRELOAD_CONNECTED != comm->state &&
            E_PRELOAD_DOWNLOADING != comm->state)
    {        
        int_srv_free(int_data->ua);
        int_data->ua = NULL;
        int_srv_free(int_data);
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E2, 5, __LINE__);
    }
    
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E, 5, __LINE__);
}

static srv_resolution_e int_srv_get_resolution() // TODO:
{
    S32 scr_w = MAIN_LCD_DEVICE_WIDTH, scr_h = MAIN_LCD_DEVICE_HEIGHT;  
    S32 i = 0, j = 0;
    static S32 resolution_support[][3] = 
    {
        {E_SRV_RESOLUTION_WVGA, 480, 800},
        {E_SRV_RESOLUTION_HVGA, 320, 480},
        {E_SRV_RESOLUTION_WQVGA, 240, 400},
        {E_SRV_RESOLUTION_QVGA, 240, 320},
        {E_SRV_RESOLUTION_LS_QVGA, 320, 240},
        {E_SRV_RESOLUTION_QCIF_PLUS,176, 220},
        {E_SRV_RESOLUTION_LSQCIF_PLUS, 220, 176},
        {E_SRV_RESOLUTION_QQVGA, 128, 160},
        {E_SRV_RESOLUTION_END, 0, 0}
    };
    
    //gdi_lcd_get_dimension(&scr_w, &scr_h);

    for (; E_SRV_RESOLUTION_END != resolution_support[i][0]; i++)
    {
        if (scr_w == resolution_support[i][1] && scr_h == resolution_support[i][2])
        {
            return resolution_support[i][0];
        }
    }
    
    return E_SRV_RESOLUTION_END;
}
static U32 int_srv_get_lis_appid(S32 def)
{
    S32 i = 0;
    srv_resolution_e res_e;
    U32 def_appid = 0;
    static srv_lis_record_t lis_info[] = 
    {
        {"en-US", E_SRV_RESOLUTION_WVGA, 0x63348000},
        {"en-US", E_SRV_RESOLUTION_HVGA, 0x63348001},
        {"en-US", E_SRV_RESOLUTION_WQVGA, 0x63348002},
        {"en-US", E_SRV_RESOLUTION_QVGA, 0x63348003},
        {"en-US", E_SRV_RESOLUTION_LS_QVGA, 0x63348004},
        {"en-US", E_SRV_RESOLUTION_QCIF_PLUS, 0x63348005},
        {"en-US", E_SRV_RESOLUTION_LSQCIF_PLUS, 0x63348006},
        {"en-US", E_SRV_RESOLUTION_QQVGA, 0x63348007},
        {"zh-TW", E_SRV_RESOLUTION_WVGA, 0xffffffff},
        {"zh-CH", E_SRV_RESOLUTION_WVGA, 0xffffffff},
    };
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_S, 6, __LINE__);
    res_e = int_srv_get_resolution();
    if (E_SRV_RESOLUTION_END == res_e)
    {
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E1, 6, __LINE__);
        return 0;
    }
    
    for (i = 0; i < (sizeof(lis_info)/sizeof(srv_lis_record_t)); i++)
    {
        if (lis_info[i].er != res_e)
        {
            continue;
        }
        else
        {
            if (def)
            {
                return lis_info[i].app_id;
            }
            if (0 == strcmp(lis_info[i].lang, Get_Current_Lang_CountryCode()))
            {
                MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E2, 6, lis_info[i].app_id);
                return lis_info[i].app_id;
            }
        }
    }

    def_appid = int_srv_get_lis_appid(1);
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E, 6, def_appid);
    return def_appid;
}

static S32 int_srv_set_lis_path(const WCHAR * list_path, VMINT size)
{
    S16 error = 0;
    WCHAR list_path_nv[MAS_PATH_LEN] = {0};
    kal_wstrcpy(list_path_nv, list_path);
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_S, 70, __LINE__);
    WriteRecord(
        NVRAM_EF_SRV_MSPACE_LID,
        2,
        (void*)list_path_nv,
        NVRAM_EF_SRV_MSPACE_SIZE,
        &error);
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E, 70, error);
    /*
    if (error > 0)
        is_list_set = 1;
    */
    return error;
}

static S32 int_srv_get_lis_path(WCHAR * list_path, VMINT size)
{
    S16 error = 0;
    //WCHAR list_path_nv[260] = {0};
    //kal_wstrcpy(list_path_nv, list_path);
    ASSERT(list_path);
    /*
    if (!is_list_set)
    {
        return -3;
    }
    */
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_S, 71, __LINE__);
    ReadRecord(
        NVRAM_EF_SRV_MSPACE_LID,
        2,
        (void*)list_path,
        size,
        &error);
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E, 71, error);
    return error;
}

static S32 int_srv_gen_lis_path(WCHAR * list_path, VMINT size)
{
    S16 error = 0;
    S32 ret = 0;
    int drv = 0;
    VMWCHAR drv_ucs[4] = {'x', ':', '\\', 0};
    FS_DiskInfo disk_info;
    S32 fs_handle = 0;
    S64 tmp_lis_size = LIS_MAX_SIZE * 1024;
    S64 tmp_disk_free = 0;

    ASSERT(list_path);
    
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_S, 22, __LINE__);

    drv = int_srv_get_drv();
    if (0 >= drv)
    {
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E2, 22, __LINE__);
        return -3;
    }
    
    //kal_wsprintf(drv_ucs, "%c", drv);
    drv_ucs[0] = drv;
    fs_handle = FS_GetDiskInfo((WCHAR *)drv_ucs, &disk_info, FS_DI_BASIC_INFO|FS_DI_FREE_SPACE);
    if (0 > fs_handle)
    {
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E3, 22, __LINE__);
        return -4;
    }

    tmp_disk_free = disk_info.FreeClusters*disk_info.SectorsPerCluster*disk_info.BytesPerSector;
    if (tmp_lis_size > tmp_disk_free)
    {
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E4, 22, __LINE__);
        return -5;
    }


    kal_wsprintf(list_path, "%c:\\"MSPACE_PATH"\\", drv);
    ret = FS_CreateDir((WCHAR *)list_path);
    kal_wstrcat(list_path, (WCHAR *)L"lis");

    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E, 22, __LINE__);
    return 0;
}

#ifdef CHG_FORMAT
static S32 int_srv_check_lis(const WCHAR * list_path)
{
    int ret = 0;
    FS_HANDLE hdl = 0;
    //WCHAR list_path[260] = {0};
    U32 size = 0;
    UINT read = 0;
    U32 id = 0;

    ASSERT(list_path);
    
    hdl = FS_Open(list_path, FS_READ_ONLY);
    if (0 > hdl)
    {
        return -2;
    }
    
    ret = FS_Seek(hdl, 4, FS_FILE_BEGIN); // span header size
    if (ret < 0)
    {
        FS_Close(hdl);
        return -3;
    }
    
    ret = FS_Read(hdl, &size, 4, &read); // lis size
    if (ret < 0)
    {
        FS_Close(hdl);
        return -4;
    }
    ret = FS_Seek(hdl, 4, FS_FILE_CURRENT); // span lis version
    if (ret < 0)
    {
        FS_Close(hdl);
        return -5;
    }
    ret = FS_Read(hdl, &id, 4, &read); // read lis id
    if (ret < 0)
    {
        FS_Close(hdl);
        return -6;
    }
    if (id != int_srv_get_lis_appid(0))
    {
        FS_Close(hdl);
        FS_Delete(list_path);
        return -10; // the lis is fake
    }
    
    ret = FS_Seek(hdl, 0, FS_FILE_BEGIN); // tell file size
    if (ret < 0)
    {
        FS_Close(hdl);
        return -7;
    }
    ret = FS_Seek(hdl, 0, FS_FILE_END); // tell file size
    if (ret < 0)
    {
        FS_Close(hdl);
        return -8;
    }

    if ((U32)ret != size)
    {
        FS_Close(hdl);
        FS_Delete(list_path);
        return -9;
    }
    
    FS_Close(hdl);
    return 0;
}
#else
static S32 int_srv_check_lis(const WCHAR * list_path)
{
    return -11;
}
#endif /* CHG_FORMAT */

static S32 int_srv_rename_lis()
{
    int ret = 0;
    S32 attr = 0;
    S32 retval = -1;
    WCHAR list_path[MAS_PATH_LEN] = {0};
    WCHAR list_path_tmp[MAS_PATH_LEN] = {0};
    
    if (0 > int_srv_get_lis_path(list_path, MAS_PATH_LEN))
    {
        return -3;
    }
    attr = FS_GetAttributes((WCHAR *)list_path);
    if ((attr & FS_ATTR_READ_ONLY))
    FS_SetAttributes((WCHAR *)list_path, (U8) (attr & ~(FS_ATTR_READ_ONLY)));
    FS_Delete(list_path);
    kal_wstrcat(list_path_tmp, list_path);
    kal_wstrcat(list_path_tmp, L".tmp");
    ret = FS_Rename(list_path_tmp, list_path);
    return ret;
}
static const S8 * int_srv_get_lis_ver()
{
    static S8 gsz_buf[12] = {0};
    FS_HANDLE hdl = 0;
    U32 ver = 0;
    UINT read = 0;
    WCHAR list_path_nv[MAS_PATH_LEN] = {0};
    S32 error = 0;
    
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_S, 8, __LINE__);

    error = int_srv_get_lis_path(list_path_nv, MAS_PATH_LEN);
    
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_LOG, 
        error,
        0,
        0,
        0,
        0,
        list_path_nv,
        80, __LINE__);
    if (0 > error)
    {
        return NULL;
    }
    
    hdl = FS_Open(list_path_nv, FS_READ_ONLY);
    if (0 > hdl)
    {
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E1, 8, __LINE__);
        return "00.00.00";
    }

    FS_Seek(hdl, 2 * sizeof(int), FS_FILE_BEGIN); // span header size & totoal size
    if (FS_NO_ERROR != FS_Read(hdl, &ver, sizeof(int), &read))
    {
        FS_Close(hdl);
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E2, 8, __LINE__);
        return "00.00.00";
    }
    FS_Close(hdl);
    sprintf(gsz_buf, "%02d.%02d.%02d", ver/10000, ver%10000/100, ver%100);
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E, 8, __LINE__);
    return gsz_buf;
}

static S32 int_srv_gen_app_path(const srv_as_app_node_t * node, WCHAR * app_path)
{
    S16 error = 0;
    S32 ret = 0;
    int drv = 0;
    VMWCHAR drv_ucs[4] = {'x', ':', '\\', 0};
    FS_DiskInfo disk_info;
    S32 fs_handle = 0;
    S64 tmp_app_size = 0;
    S64 tmp_disk_free = 0;

    ASSERT(app_path);
    
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_S, 21, __LINE__);
    if (FS_NO_ERROR == FS_GetDevStatus((unsigned int)FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE), FS_MOUNT_STATE_ENUM))
    {
        drv = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
        if (drv <= 0)
        {
            drv = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL);
            if (drv <= 0)
            {
                MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E1, 21, __LINE__);
                return -2;
            }
        }
    }
    else
    {
        drv = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL);
        if (drv <= 0)
        {
            MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E2, 21, __LINE__);
            return -3;
        }
    }
    
    //kal_wsprintf(drv_ucs, "%c", drv);
    drv_ucs[0] = drv;
    fs_handle = FS_GetDiskInfo((WCHAR *)drv_ucs, &disk_info, FS_DI_BASIC_INFO|FS_DI_FREE_SPACE);
    if (0 > fs_handle)
    {
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E3, 21, __LINE__);
        return -3;
    }

    tmp_disk_free = (disk_info.FreeClusters*disk_info.SectorsPerCluster*disk_info.BytesPerSector)/1024;
    tmp_app_size = node->app_size;
    if (tmp_app_size > tmp_disk_free)
    {
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E4, 21, __LINE__);
        return -4;
    }


    kal_wsprintf(app_path, "%c:\\"MSPACE_PATH"\\", drv);
    ret = FS_CreateDir((WCHAR *)app_path);
    kal_wstrcat(&app_path[kal_wstrlen(app_path)], node->name);
    kal_wsprintf(&app_path[kal_wstrlen(app_path)], "_%d.vxp", node->appid);

    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E, 21, __LINE__);
    return 0;
}


static S32 int_srv_get_app_ver(WCHAR * appPath, CHAR buff[], S32 size)
{
    VMINT bufSize = 4;
    VMUINT version = 0;

	if(vm_get_vm_tag(appPath, VM_CE_INFO_VER, &version, &bufSize) == GET_TAG_TRUE)
	{
	    if (buff)
	    {
	        VMCHAR* p = (VMCHAR*)&version;
	        _snprintf(buff,size,"%d.%d.%d",*(p+1),*(p+2),*(p+3));
        }  
        return (version >> 24)&0x000000ff | ((version >> 8)&0x0000ff00 ) | ((version << 8)&0x00ff0000);
	}
	else
	{
		return -1;
	}
}

static S32 int_srv_as_lis_query(const srv_as_data_query_t * query_app, dl_callback cb, void * user_data)
{
    VMINT ret = 0;
    vm_preload_query_info_t info = {0};
    srv_app_data_t * data = NULL;
    CHAR url[260] = {0};
    S16 read = 0;
    
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_S, 3, __LINE__);
    data = (srv_app_data_t*)int_srv_alloc(sizeof(srv_app_data_t));
    if (!data)
    {
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E1, 3, __LINE__);
        return -2;
    }
    
    data->ua = (VMCHAR*)int_srv_alloc(1024);
    if (!data->ua)
    {
        int_srv_free(data);
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E2, 3, __LINE__);
        return -3;
    }

    data->cb = cb;
    data->user_data = user_data;
    data->qry = E_SRV_AS_APP_QUERY_LIS;

    sprintf(data->ua,"app_id=%d&", int_srv_get_lis_appid(0));
    sprintf(data->ua + strlen(data->ua), "ver=%s", int_srv_get_lis_ver());
    
    info.app_id = query_app->app_id; // TODO: it seems no need.
    info.ua = data->ua;
    
    if (0 >= (read = int_srv_get_url_update(url, 260)))
    {
        int_srv_free(data->ua);
        int_srv_free(data);
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E3, 3, __LINE__);
        return -4;
    }

    ret = vm_preload_query(1, 
                        url,
                        int_srv_get_server_port(), 
                        &info, 
                        int_srv_common_cb, 
                        data);
                        
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_LOG, 
        ret,
        int_srv_get_lis_appid(0),
        info.app_id,
        0,
        0,
        user_data,
        30, __LINE__);
                        
    if (0 > ret)
    {
        int_srv_free(data->ua);
        int_srv_free(data);
    }

    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E, 3, __LINE__);
    return ret;
}

S32 int_srv_as_app_query(const srv_as_data_query_t * query_app, dl_callback cb, void * user_data)
{
    VMINT ret = 0;
    vm_preload_query_info_t info = {0};
    mmi_devconfig_system_config_struct config;
    srv_app_data_t * data = NULL;
    CHAR url[260] = {0};
    S16 read = 0;
    memset(&config,0,sizeof(config));
    mmi_devconfig_get_system_config(&config);

    
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_S, 4, __LINE__);
    data = (srv_app_data_t*)int_srv_alloc(sizeof(srv_app_data_t));
    if (!data)
    {
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E1, 4, __LINE__);
        return -2;
    }
    
    data->ua = (VMCHAR*)int_srv_alloc(1024);
    if (!data->ua)
    {
        int_srv_free(data);
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E2, 4, __LINE__);
        return -3;
    }

    data->cb = cb;
    data->user_data = user_data;
    data->qry = E_SRV_AS_APP_QUERY_APP;

    if (0 >= (read = int_srv_get_url_update(url, 260)))
    {
        int_srv_free(data->ua);
        int_srv_free(data);
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E3, 4, __LINE__);
        return -4;
    }

    sprintf(data->ua,"app_id=%d&",query_app->app_id);

    
    if (query_app->app_ver)
    {
        strcat(data->ua,"ver=");
        strcat(data->ua,query_app->app_ver);
    }
    sprintf(data->ua+strlen(data->ua),"&imsi=%s&imei=%s&",vm_get_imsi(),vm_get_imei());
    if (query_app->app_info)
    {
        strcat(data->ua,"ua=");
        strcat(data->ua,query_app->app_info);
    }
    sprintf(data->ua+strlen(data->ua),"&MRE_ver=%d.%d.%02d&",MRE_VERSION/1000,(MRE_VERSION%1000)/100,MRE_VERSION%100);
    
    sprintf(data->ua+strlen(data->ua),"mem=%d&",config.memory_size>>10);
    sprintf(data->ua+strlen(data->ua),"touch=%d&",config.input_device.touch_screen);
    sprintf(data->ua+strlen(data->ua),"fingtouch=%d&",config.input_device.figner_touch_support);
    sprintf(data->ua+strlen(data->ua),"camera=%d&",config.camera_device.camera_support);
    sprintf(data->ua+strlen(data->ua),"sensor=%d&",config.remote_sensing.motion_sensor);
    strcat(data->ua,"keyboard=");
    
    if (MMI_DEVCONFIG_KEYPAD_TYPE_NORMAL == config.input_device.keypad_type)
    {
        strcat(data->ua,"normal&");
    }
    else if (MMI_DEVCONFIG_KEYPAD_TYPE_REDUCED == config.input_device.keypad_type)
    {
        strcat(data->ua,"reduced&");
    }
    else if (MMI_DEVCONFIG_KEYPAD_TYPE_QWERTY == config.input_device.keypad_type)
    {
        strcat(data->ua,"qwerty&");
    }
    sprintf(data->ua+strlen(data->ua),"lang=%s&",Get_Current_Lang_CountryCode());
    sprintf(data->ua+strlen(data->ua),"w=%d&",LCD_WIDTH);
    sprintf(data->ua+strlen(data->ua),"h=%d&",LCD_HEIGHT);
    sprintf(data->ua+strlen(data->ua),"platform=%s&",PLATFORM);
    sprintf(data->ua+strlen(data->ua),"module=%s", HW_VER_STR);

    info.app_id = query_app->app_id;
    info.ua = data->ua; // TODO: find where is the '?'


    ret = vm_preload_query(1, 
                        url, 
                        int_srv_get_server_port(), 
                        &info, 
                        int_srv_common_cb, 
                        data);

    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_LOG, 
        ret,
        info.app_id,
        0,
        0,
        info.ua,
        user_data,
        40, __LINE__);
        
    if (0 > ret)
    {
        int_srv_free(data->ua);
        int_srv_free(data);
    }

    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E, 4, __LINE__);
    return ret;

}

static void int_srv_as_app_install_cb(VMINT result, VMWSTR path, void* user_data)
{
    srv_app_ctx_t * app_ctx_p = (srv_app_ctx_t*)user_data;
    srv_as_cb_app_install_t app_install = {0};
    ASSERT(app_ctx_p);
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_S, 14, __LINE__);

    app_install.user_data = app_ctx_p->app_user_data;

    if (result)
    {
        app_install.state = E_SRV_AS_INSTALL_FAIL;
    }
    else
    {
        app_install.state = E_SRV_AS_INSTALL_SUCC;
    }

    app_install.index = app_ctx_p->idx;
    
    if (app_ctx_p->cb)
    {
        app_ctx_p->cb(app_ctx_p->hdl, &app_install);
    }

    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_LOG, 
        app_install.index,
        app_install.state,
        app_ctx_p->cb,
        0,
        0,
        app_install.user_data,
        14, __LINE__);
        
    int_srv_free(app_ctx_p);

    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E, 14, __LINE__);
}

static S32 int_srv_as_app_qd_cb(S32 hdl, void * para)
{
    VMCHAR buff[256] = {0};
    vm_update_download_param param;
    vm_preload_recv_data_t* data = (vm_preload_recv_data_t*)para;
    srv_as_cb_app_download_t info = {0};
    srv_app_ctx_t * app_ctx_p = (srv_app_ctx_t*)data->head.user_data;

    ASSERT(app_ctx_p && data);
    
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_S, 13, __LINE__);
    
    app_ctx_p->hdl = hdl;
    info.state = data->head.state;
    info.user_data = app_ctx_p->app_user_data;
    info.index = app_ctx_p->idx;

    if (E_PRELOAD_DOWNLOADING == info.state ||
        E_PRELOAD_DOWNLOADED == info.state)
    {
        info.received = data->received;
        info.total = data->total;
    }
    
    if (app_ctx_p->cb)
    {
        app_ctx_p->cb(hdl, &info);
    }
    
    if (E_PRELOAD_AVAILABLE_UPDATE == data->head.state)
    {
        if (FS_GetDevStatus((unsigned int)FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, 	FS_NO_ALT_DRIVE), FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
        {
            param.bSaveOnCard = 1;
        }
        else
        {
            param.bSaveOnCard = 0;
        }
        
        param.callback = int_srv_as_app_qd_cb;
        param.user_data = app_ctx_p;
        param.handle = hdl;
        param.app_path = (VMWSTR)app_ctx_p->app_path;
        param.bUseDLA = 1;
        
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_LOG, 
            param.bSaveOnCard,
            param.handle,
            param.bUseDLA,
            info.index,
            app_ctx_p->cb,
            param.app_path,
            130, __LINE__);

        if (VM_UPDATE_OK != vm_update_download_ex(&param))
        {
            srv_as_cb_app_query_t app_query = {0};
            info.state = E_PRELOAD_FAILURE;
            if (app_ctx_p->cb)
            {
                app_ctx_p->cb(hdl, &info);
            }
            MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E1, 13, __LINE__);
            int_srv_free(app_ctx_p);
        }
    }
    else if (E_PRELOAD_DOWNLOADED == data->head.state)
    {
        if (VM_UPDATE_OK != vm_update_update_file_ex((VMWSTR)app_ctx_p->app_path, 
                                                    int_srv_as_app_install_cb, app_ctx_p))
        {
            int_srv_as_app_install_cb(1, NULL, app_ctx_p);
            MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E2, 13, __LINE__);
        }
        
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E3, 13, __LINE__);
    }
    else if (data->head.state != E_PRELOAD_DOWNLOADING && data->head.state != E_PRELOAD_QUERYING &&
        data->head.state != E_PRELOAD_CONNECTING && data->head.state != E_PRELOAD_CONNECTED)
    {
        int_srv_free(app_ctx_p);
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E4, 13, __LINE__);
    }

    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E, 13, __LINE__);
    return 0;
}

static S32 int_srv_gen_mapping(const WCHAR * path)
{
    mmi_devconfig_system_config_struct *config;
    S32 num = 0;
    srv_as_app_node_t * node = NULL;
    srv_as_app_info_t * info = NULL;
    S32 i = 0;
    S32 valid = 0;

    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_S, 24, __LINE__);
    if (g_map_ctx.freshed)
    {
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E1, 24, __LINE__);
        return 0;
    }

    //memset(&config,0,sizeof(config));
    config = (mmi_devconfig_system_config_struct *)int_srv_alloc(sizeof(mmi_devconfig_system_config_struct));
    mmi_devconfig_get_system_config(config);

    num = srv_as_list_get_record_num();
    if (0 > num)
    {
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E2, 24, __LINE__);
        int_srv_free(config);
        return -2;
    }
    
    if (g_map_ctx.map)
    {
        int_srv_free(g_map_ctx.map);
        memset(&g_map_ctx, 0, sizeof(g_map_ctx));
    }
    g_map_ctx.map = int_srv_alloc(sizeof(U16) * num);
    node = int_srv_alloc(sizeof(srv_as_app_node_t) * num);
    info = int_srv_alloc(sizeof(srv_as_app_info_t) * num);
    srv_as_list_get_info(0, num, node, info);
    
    for (i = 0; i < num; i++)
    {            
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_LOG, 
            i,
            0,
            0,
            0,
            0,
            0,
            node[i].flag, __LINE__);
        int_srv_string_print(node[i].name, 24, __LINE__);
        int_srv_string_print(node[i].provider, 24, __LINE__);

        // project keypad only
        if (!config->input_device.touch_screen && !config->input_device.figner_touch_support)
        {
            // game not support key
            if (!(node[i].flag & IS_SUPPORT_NORMAL) && 
                !(node[i].flag & IS_SUPPORT_QUERTY))
            {
                continue;
            }
        }

        // pen only
        if (MMI_DEVCONFIG_KEYPAD_TYPE_REDUCED == config->input_device.keypad_type)
        {
            // not support pen
            if (!(node[i].flag & IS_SUPPORT_TOUCH) && 
                !(node[i].flag & IS_SUPPORT_FINGTOUCH))
            {
                continue;
            }
        }
        
#if 0        
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif        
        // sys memory lack
        if (MRE_SYS_ASM_APP_MEMPOOL_SIZE < (node[i].ram_size<<10))
        {
            continue;
        }
        
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E3, 24, __LINE__);
        g_map_ctx.map[g_map_ctx.num++] = i;
        
    }

    g_map_ctx.freshed = 1;

    int_srv_free(node);
    int_srv_free(info);
    int_srv_free(config);
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E, 24, __LINE__);

    return 0;
}

#endif /* MAS_SRV_MSPACE */

S32 srv_as_data_query(const srv_as_data_query_t * query, dl_callback cb, void * user_data)
{
#ifndef MAS_SRV_MSPACE
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E1, 1, __LINE__);
    return -1;
#else
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_S, 1, __LINE__);
    if (NULL == query || NULL == cb)
    {
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E1, 1, __LINE__);
        return -2;
    }

    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_LOG, 
        query->qry,
        0,
        query->app_id,
        0,
        0,
        user_data,
        10, __LINE__);

    switch (query->qry)
    {
    case E_SRV_AS_APP_QUERY_LIS:
        {
            S32 query_list_hdl = 0;
            query_list_hdl = int_srv_as_lis_query(query, cb, user_data);
            
            MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_LOG, 
                query->qry,
                0,
                query_list_hdl,
                0,
                0,
                user_data,
                11, __LINE__);
            MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E2, 1, __LINE__);
            return query_list_hdl;
        }
        break;
    case E_SRV_AS_APP_QUERY_APP:
        {
            MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E3, 1, __LINE__);
            return int_srv_as_app_query(query, cb, user_data);
        }
        break;
    }

    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_S, 1, __LINE__);
    return -3;
#endif
}
S32 srv_as_data_download(S32 hdl, const WCHAR * path, dl_callback cb, void * user_data)
{
#ifndef MAS_SRV_MSPACE
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E1, 2, __LINE__);
        return -1;
#else

    srv_app_data_t * data = NULL;
    VMINT result;
    WCHAR path_int[MAS_PATH_LEN] = {0};
    
    ASSERT(NULL == path);// it is noly for lis download currently.
    
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_S, 2, __LINE__);
    data = (srv_app_data_t *)int_srv_alloc(sizeof(srv_app_data_t));
    if (!data)
    {
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E1, 2, __LINE__);
        return -2;
    }
    
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_LOG, 
        hdl,
        0,
        cb,
        path,
        0,
        user_data,
        20, __LINE__);

    // it is noly for lis download currently.
    if (NULL == path)
    {
        if (0 != int_srv_gen_lis_path(path_int, MAS_PATH_LEN))
        {
            MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E4, 2, __LINE__);
            return -4;
        }
    }
    else
    {
        kal_wstrcpy(path_int, path);
    }
    if (0 > int_srv_set_lis_path(path_int, MAS_PATH_LEN))
    {
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E2, 2, __LINE__);
        return -3;
    }

    //data->handle = vm_pmng_get_current_handle();
    data->cb = cb;
    data->user_data = user_data;
    
    kal_wstrcat(path_int, (WCHAR*)L".tmp");
    
    result = vm_preload_download(hdl, path_int, int_srv_common_cb, data);
    if (result < 0)
    {
        int_srv_free(data);
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E3, 2, __LINE__);
        return result;
    }
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E, 2, __LINE__);
    
    return 0;
#endif
}

S32 srv_as_data_cancel(S32 hdl)
{
#ifndef MAS_SRV_MSPACE
        return -1;
#else
    S32 ret = 0;
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_S, 10, __LINE__);
    ret = (VMINT)vm_preload_cancel(hdl);
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E, 10, __LINE__);
    return ret;
#endif
}

VMINT vm_preload_status(VMINT app_id);
S32 srv_as_app_download(U32 index, dl_callback cb, void * user_data)
{
#ifndef MAS_SRV_MSPACE
    return -1;
#else

    vm_update_check_version_param param;
    srv_as_app_node_t node = {0};
    CHAR url[260] = {0};
    WCHAR app_name[260] = {0};
    S32 ret = 0;
    srv_app_ctx_t * app_ctx_p = NULL;
    S32 result = 0;
    U32 app_id = 0;
    static CHAR app_version[16] = {0};
    MMI_BOOL installed = 0;
    U32 mapped_index = index;
    
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_S, 12, MRE_SYS_ASM_APP_MEMPOOL_SIZE);

    if (g_map_ctx.freshed)
    {
        mapped_index = g_map_ctx.map[index];
    }

    if (index >= (U32)srv_as_list_get_record_num())
    {
        return -12;
    }

    app_ctx_p = (srv_app_ctx_t*)int_srv_alloc(sizeof(srv_app_ctx_t));

    if (0 > (ret = srv_as_list_get_info(index, 1, &node, NULL)))
    {
        int_srv_free(app_ctx_p);
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E1, 12, __LINE__);
        return -13;
    }

    if (MRE_SYS_ASM_APP_MEMPOOL_SIZE < (node.ram_size<<10))
    {
        int_srv_free(app_ctx_p);
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E8, 12, node.ram_size);
        return -17;
    }

    //app_id = srv_mre_appmgr_get_appid(node.name);
    if (E_PRELOAD_DOWNLOADING == vm_preload_status(node.appid))
    {
        int_srv_free(app_ctx_p);
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E2, 12, __LINE__);
        return -14;
    }
    
    int_srv_get_url_update(url, 260);

    param.app_id = (VMINT)node.appid;
    param.URL = url;
    param.port = int_srv_get_server_port();
    param.apn = 1;
    //srv_mre_appmgr_get_shortcut_app_name_package(param.app_id, app_name);
    {
        //WCHAR app_name[260] = {0};
        extern MMI_BOOL srv_mre_appmgr_is_shortcut_app_by_id(U32 app_id);
        MMI_BOOL is_shortcut = 0;

        if (MMI_FALSE == (is_shortcut = srv_mre_appmgr_is_shortcut_app_by_id(node.appid)))
        {
            U32 all_installed = 0;
            installed = srv_mre_appmgr_is_app_installed_by_develop_and_name(
                SRV_MRE_APPMGR_APP_TYPE_VXP, 
                node.name,
                node.provider,
                app_name);

            all_installed = srv_mre_appmgr_get_app_num(SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE)+srv_mre_appmgr_get_app_num(SRV_APPMGR_INSTALLED_VPP_PACKAGE_FLAG_TYPE);
            all_installed += srv_mre_appmgr_get_app_num(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE);
            if(all_installed>=SRV_MRE_APPMGR_INSTALLED_APP_MAX)
            {
                MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E8, 12, result);
                int_srv_free(app_ctx_p);
                return -18;
            }
        }
        else
        {
            mmi_app_package_char tmp[260] = {0};
            srv_mre_appmgr_get_shortcut_app_name_package(node.appid, tmp);
            mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)tmp, (char *)app_name, MMI_APP_NAME_MAX_LEN);
            if (srv_mre_appmgr_is_app_installed(tmp))
                installed = MMI_TRUE;
            else
                installed = MMI_FALSE;
        }
        if (installed) // the path only could be gotten by installed app
        {
            srv_mre_appmgr_installed_info_struct installed_info = {0};
            if (!srv_mre_appmgr_get_installed_info(app_name, &installed_info))
            {
                MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E3, 12, __LINE__);
                return -15;
            }
            kal_wstrcpy(app_ctx_p->app_path, installed_info.app_path);
            param.app_path = (VMWSTR)app_ctx_p->app_path;
            memset(app_version, 0, sizeof(app_version));
            if (-1 == int_srv_get_app_ver(param.app_path, app_version, 16))
            {
                param.app_ver = "0.0.0";
                MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E4, 12, __LINE__);
            }
            else
            {
                param.app_ver = app_version;
            }
        }
        // app did not install at first time.
        else
        {
            param.app_ver = "0.0.0";
            if (0 > int_srv_gen_app_path(&node, app_ctx_p->app_path))
            {
                MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E5, 12, __LINE__);
                return -16;
            }
            param.app_path = (VMWSTR)app_ctx_p->app_path;
        }
    }

    param.app_info = NULL;
    param.callback = int_srv_as_app_qd_cb;
    app_ctx_p->cb = cb;
    app_ctx_p->app_user_data = user_data;
    app_ctx_p->idx = index;
    param.user_data = app_ctx_p;

    
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_LOG, 
        index,
        param.app_id,
        param.port,
        cb,
        installed,
        user_data,
        12, __LINE__);
        
    result = vm_update_check_version_ex(&param);
    if (VM_UPDATE_OK_ALREADY_DOWNLOADED == result)
    {
        VMINT ret = 0;
        ret = vm_update_update_file_ex((VMWSTR)app_ctx_p->app_path, int_srv_as_app_install_cb, app_ctx_p);
        if (ret) // TODO: 
        {
            int_srv_free(app_ctx_p);
        }
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E6, 12, ret);
        return ret;
    }
    else if (VM_UPDATE_OK  != result)
    {
        int_srv_free(app_ctx_p);
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E7, 12, result);
        return result;
    }
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E, 12, __LINE__);
    return VM_UPDATE_OK;
#endif
}

S32 srv_as_list_get_record_num()
{
#ifndef MAS_SRV_MSPACE
    return -1;
#else
    FS_HANDLE hdl = 0;
    S32 num = 0;
    UINT read = 0;
    WCHAR list_path[MAS_PATH_LEN] = {0};
    
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_S, 19, __LINE__);

    if (g_map_ctx.freshed)
    {
        return g_map_ctx.num;
    }
    
    if (0 > int_srv_get_lis_path(list_path, MAS_PATH_LEN))    
    {
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E1, 19, __LINE__);
        return -3;
    }
    
    if (NULL == list_path)
    {
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E2, 19, __LINE__);
        return -2;
    }

    hdl = FS_Open(list_path, FS_READ_ONLY);
    if (0 > hdl)
    {
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E3, 19, __LINE__);
        return -4;
    }
    #ifdef CHG_FORMAT
    FS_Seek(hdl, sizeof(int) * 5, FS_FILE_BEGIN); // header size, totoal size, verno, file id, struct size
    #else
    FS_Seek(hdl, sizeof(int) * 2, FS_FILE_BEGIN); // totoal size & verno
    #endif
    if (0 > FS_Read(hdl, &num, sizeof(int), &read))
    {
        FS_Close(hdl);
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E4, 19, __LINE__);
        return -5;
    }
    FS_Close(hdl);
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E, 19, __LINE__);
    return num;
#endif
}
S32 srv_as_list_get_info(U32 index, U32 num, srv_as_app_node_t * node, srv_as_app_info_t * info)
{
#ifndef MAS_SRV_MSPACE
    return -1;
#else
    FS_HANDLE hdl = 0;
    UINT read = 0;
    U32 i = 0, j = 0;
    int ret = 0;
    //srv_as_app_node_t *node_tmp = (srv_as_app_node_t *)int_srv_alloc(sizeof(srv_as_app_node_t));
    S32 list_num = 0;
    WCHAR *list_path = (WCHAR *)int_srv_alloc(MAS_PATH_LEN);
    U32 struct_size = sizeof(srv_as_app_node_t), seek_offset = 0, header_size = 0;
    U32 mapped_index = index;
    
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_S, 18, __LINE__);
    
    if (g_map_ctx.freshed)
    {
        mapped_index = g_map_ctx.map[index];
    }
    
    if (0 > int_srv_get_lis_path(list_path, MAS_PATH_LEN))
    {
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E1, 18, __LINE__);
        int_srv_free(list_path);
        return -2;
    }
    
    list_num = srv_as_list_get_record_num(list_path);
   
    if (NULL == list_path || 
        (S32)(index + num) > list_num)
    {
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E2, 18, __LINE__);
        int_srv_free(list_path);
        return -3;
    }
    
#ifdef CHG_FORMAT
    hdl = FS_Open(list_path, FS_READ_ONLY);
    if (0 > hdl)
    {
        int_srv_free(list_path);
        return -12;
    }
    ret = FS_Read(hdl, &header_size, 4, &read); // pos on struct size
    if (0 > ret)
    {
        int_srv_free(list_path);
        return -13;
    }
    
    ret = FS_Seek(hdl, sizeof(int) * 4, FS_FILE_BEGIN); // pos on struct size
    if (0 > ret)
    {
        int_srv_free(list_path);
        return -14;
    }
    ret = FS_Read(hdl, &struct_size, 4, &read);
    if (0 > ret)
    {
        int_srv_free(list_path);
        return -15;
    }
    if (struct_size < sizeof(srv_as_app_node_t)) // older lis
    {
        
    }
    else // match or newer lis (seek_offset >= 0) compatible newest lis.
    {
        seek_offset = struct_size - sizeof(srv_as_app_node_t);
    }
    FS_Close(hdl);
#endif

    

    if (NULL != node)
    {
        memset(node, 0, num * sizeof(srv_as_app_node_t));
        hdl = FS_Open(list_path, FS_READ_ONLY);
        if (0 > hdl)
        {
            MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E3, 18, __LINE__);
            int_srv_free(list_path);
            return -4;
        }

        
#ifdef CHG_FORMAT
        ret = FS_Seek(hdl, sizeof(int) * (header_size + 1), FS_FILE_BEGIN); // header size, totoal size, verno, file id, struct size app num, & 2 x reserved
#else
        ret = FS_Seek(hdl, LIS_HEADER_SIZE * sizeof(int), FS_FILE_BEGIN); // total size, verno & node num
#endif
        if (0 > ret)
        {
            FS_Close(hdl);
            MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E4, 18, __LINE__);
            int_srv_free(list_path);
            return -5;
        }

#ifdef CHG_FORMAT
        ret = FS_Seek(hdl, (mapped_index)*struct_size, FS_FILE_CURRENT);
#else
        ret = FS_Seek(hdl, (mapped_index)*sizeof(srv_as_app_node_t), FS_FILE_CURRENT);
#endif
        if (0 > ret)
        {
            FS_Close(hdl);
            MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E5, 18, __LINE__);
            int_srv_free(list_path);
            return -6;
        }

        
        for (i = 0; i < num; i++)
        {
            if (0 < i && g_map_ctx.freshed)
            {
                ret = FS_Seek(hdl, struct_size * (g_map_ctx.map[index + i] - g_map_ctx.map[index + i - 1] - 1), FS_FILE_CURRENT);
            }
            ret = FS_Read(hdl, &node[i], struct_size, &read);
            if (0 > ret)
            {
                FS_Close(hdl);
                MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E6, 18, __LINE__);
                int_srv_free(list_path);
                return -7;
            }       
            
            ret = FS_Seek(hdl, seek_offset, FS_FILE_CURRENT);
            if (0 > ret)
            {
                FS_Close(hdl);
                
                int_srv_free(list_path);
                return -16;
            }
        }


        //for (i = 0; (S32)i < list_num; i++)
        //{
        //    if (index <= i)
        //    {
        //        ret = FS_Read(hdl, &node[j], sizeof(srv_as_app_node_t), &read);
        //        if (0 > read)
        //            break;
        //        ret = FS_Seek(hdl, node[j].icon_size + 4 - node[j].icon_size%4, FS_FILE_CURRENT);
        //        if (0 > ret)
        //            break;
        //        ++j;
        //    }
        //    else
        //    {
        //        memset(&node_tmp, 0, sizeof(node_tmp));
        //        ret = FS_Read(hdl, &node_tmp, sizeof(srv_as_app_node_t), &read);
        //        if (0 > read)
        //            break;
        //        ret = FS_Seek(hdl, node_tmp.icon_size + 4 - node_tmp.icon_size%4, FS_FILE_CURRENT);
        //        if (0 > ret)
        //            break;

        //    }
        //}

        FS_Close(hdl);
    }

    
    if (NULL != info)
    {
        MMI_BOOL installed = MMI_FALSE;
        U32 i = 0;
        for (i = 0; i < num; i++)
        {
            extern MMI_BOOL srv_mre_appmgr_is_shortcut_app_by_id(U32 app_id);
            //WCHAR app_path[260] = {0};
            WCHAR *app_name = (WCHAR *)int_srv_alloc(128);
            MMI_BOOL is_shortcut = 0;

            if (MMI_FALSE == (is_shortcut = srv_mre_appmgr_is_shortcut_app_by_id(node[i].appid)))
            {
                
                installed = srv_mre_appmgr_is_app_installed_by_develop_and_name(
                    SRV_MRE_APPMGR_APP_TYPE_VXP, 
                    node[i].name,
                    node[i].provider,
                    app_name);
            }
            else
            {
                mmi_app_package_char tmp[128] = {0};
                srv_mre_appmgr_get_shortcut_app_name_package(node[i].appid, tmp);
                mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)tmp, (char *)app_name, 128);
                if (srv_mre_appmgr_is_app_installed(tmp))
                    installed = MMI_TRUE;
                else
                    installed = MMI_FALSE;
            }

            
            int_srv_string_print(node[i].name, 18, __LINE__);
            int_srv_string_print(node[i].provider, 18, __LINE__);
            int_srv_string_print(app_name, 18, __LINE__);
            //int_srv_string_print(app_path, 18, __LINE__);

            
            MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_LOG, 
                i,
                installed,
                num,
                is_shortcut,
                0,
                0,
                18, __LINE__);
            
            if (installed)
            {
                FS_HANDLE hdl = 0;
                srv_mre_appmgr_installed_info_struct *installed_info = (srv_mre_appmgr_installed_info_struct *)int_srv_alloc(sizeof(srv_mre_appmgr_installed_info_struct));
                if (!srv_mre_appmgr_get_installed_info(app_name, installed_info))
                {
                    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E7, 18, __LINE__);
                    int_srv_free(list_path);
                    int_srv_free(app_name);
                    int_srv_free(installed_info);
                    return -8;
                }
                
                hdl = FS_Open(installed_info->app_path, FS_READ_ONLY);
                if (hdl < 0)
                {
                    if (FS_ACCESS_DENIED != hdl) // -16
                    {
                        info[i].status = SRV_AS_APP_STATUS_GONE;
                    }
                    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E8, 18, hdl);
                }
                else
                {
                    VMINT bufSize = 4;
                    VMUINT version_app_local = 0;
                    srv_as_app_node_t node_lis = {0};
                    CHAR ver_buf[16] = {0};
                    if (-1 != (version_app_local = int_srv_get_app_ver(installed_info->app_path, ver_buf, 16)))
                    {
                        //srv_as_list_get_info(i, 1, &node_lis, NULL);
                        //node_lis.ver = (node_lis.ver >> 24)&0x000000ff | ((node_lis.ver >> 8)&0x0000ff00 ) | ((node_lis.ver << 8)&0x00ff0000);
                        node[i].ver = (node[i].ver >> 24)&0x000000ff | ((node[i].ver >> 8)&0x0000ff00 ) | ((node[i].ver << 8)&0x00ff0000);
                        if (node[i].ver > version_app_local)
                        {
                            info[i].status = SRV_AS_APP_STATUS_AVAIL_UPDATE;
                        }
                        else
                        {
                            info[i].status = SRV_AS_APP_STATUS_NO_AVAIL_UPDATE;                            
                        }
                    }
                    else
                    {
                        info[i].status = SRV_AS_APP_STATUS_GONE;
                    }
                    FS_Close(hdl);
                }
                
                int_srv_free(installed_info);
            }
            else
            {
                info[i].status = SRV_AS_APP_STATUS_NEW;
            }
            
            int_srv_free(app_name);
            MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E9, 18, info[i].status);
        }
    }

    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E, 18, __LINE__);
    int_srv_free(list_path);
    return 0;
#endif
}

S32 srv_as_list_get_icon(U32 index, void * data, U32 size)
{
#ifndef MAS_SRV_MSPACE
    return -1;
#else
    FS_HANDLE hdl = 0;
    UINT read = 0;
    S32 i = 0;
    int ret = 0;
    S32 list_num = 0; 
    srv_as_app_node_t node = {0};
    U32 header_size = 0;
    WCHAR list_path[MAS_PATH_LEN] = {0};
    U32 struct_size = 0;

    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_S, 17, __LINE__);
    list_num = srv_as_list_get_record_num();
    if (0 > int_srv_get_lis_path(list_path, MAS_PATH_LEN))
    {
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E1, 17, __LINE__);
        return -3;
    }
    
    if (NULL == list_path || 
        (S32)index >= list_num || 
        NULL == data)
    {
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E2, 17, __LINE__);
        return -2;
    }
    
    if (g_map_ctx.freshed)
    {
        index = g_map_ctx.map[index];
    }


    hdl = FS_Open(list_path, FS_READ_ONLY);
    if (0 > hdl)
    {
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E3, 17, __LINE__);
        return -4;
    }

#ifdef CHG_FORMAT
    ret = FS_Read(hdl, &header_size, 4, &read); // pos on struct size
    if (0 > ret)
    {
        return -5;
    }
    ret = FS_Seek(hdl, sizeof(int) * 4, FS_FILE_BEGIN); // pos on struct size
    if (0 > ret)
    {
        return -11;
    }
    ret = FS_Read(hdl, &struct_size, 4, &read);
    if (0 > ret)
    {
        return -12;
    }
    ret = FS_Seek(hdl, sizeof(int) * (header_size + 1) + index*struct_size, FS_FILE_BEGIN);
#else
    ret = FS_Seek(hdl, LIS_HEADER_SIZE * sizeof(int) + index*sizeof(srv_as_app_node_t), FS_FILE_BEGIN); // total size, verno & node num
#endif
    if (0 > ret)
    {
        FS_Close(hdl);
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E4, 17, __LINE__);
        return -6;
    }

    ret = FS_Read(hdl, &node, sizeof(srv_as_app_node_t), &read);
    if (0 > ret)
    {
        FS_Close(hdl);
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E5, 17, __LINE__);
        return -7;
    }

    if (size < node.icon_size)
    {
        FS_Close(hdl);
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E6, 17, __LINE__);
        return -8;
    }

    ret = FS_Seek(hdl, node.icon_offset, FS_FILE_BEGIN);
    if (0 > ret)
    {
        FS_Close(hdl);
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E7, 17, __LINE__);
        return -9;
    }

    ret = FS_Read(hdl, data, node.icon_size, &read);
    if (0 > ret)
    {
        FS_Close(hdl);
        MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E8, 17, __LINE__);
        return -10;
    }

    //for (i = 0; i < list_num; i++)
    //{               
    //    memset(&node, 0, sizeof(srv_as_app_node_t));
    //    if (index != i)
    //    {
    //        ret = FS_Read(hdl, &node, sizeof(srv_as_app_node_t), &read);
    //        if (0 > read)
    //            break;
    //        ret = FS_Seek(hdl, node.icon_size + 4 - node.icon_size%4, FS_FILE_CURRENT);
    //        if (0 > ret)
    //            break;
    //    }
    //    else
    //    {
    //        ret = FS_Read(hdl, &node, sizeof(srv_as_app_node_t), &read);
    //        if (0 > read)
    //        {
    //            break;
    //        }
    //        ret = FS_Read(hdl, data, node.icon_size, &read);
    //        if (node.icon_size != ret)
    //        {
    //            return -5;
    //        }

    //        break;
    //    }
    //}

    FS_Close(hdl);
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E, 17, __LINE__);
    return 0;
#endif
}

S32 srv_as_list_init()
{
#ifndef MAS_SRV_MSPACE
    return -1;
#else
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_S, 15, __LINE__);

    {
    WCHAR path_int[MAS_PATH_LEN] = {0};
    int_srv_gen_lis_path(path_int, MAS_PATH_LEN);
    int_srv_set_lis_path(path_int, MAS_PATH_LEN);
    if (0 == int_srv_check_lis(path_int))
    {
        int_srv_gen_mapping(path_int);
    }
    }
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E, 15, __LINE__);
    return 0;
#endif
}
S32 srv_as_list_deinit()
{
#ifndef MAS_SRV_MSPACE
    return -1;
#else
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_S, 16, __LINE__);
    if (g_map_ctx.map)
    {
        int_srv_free(g_map_ctx.map);
        memset(&g_map_ctx, 0, sizeof(g_map_ctx));
    }
    MMI_TRACE(TRACE_GROUP_7, TRC_MRE_SRV_MSPACE_E, 16, __LINE__);
    return 0;
#endif
}


