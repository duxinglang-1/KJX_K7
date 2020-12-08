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
 *  FileMgrSrvFileList.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File list part of Filemgr service
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#define _FMGR_INTERNAL_SOURCE_C_
#define _FMGR_GPROT_H_

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
// by RHR //#include "MMI_include.h"

#include "FileMgrSrvProt.h"

#include "Fs_type.h"

#include "fmt_struct.h"
#include "fmt_main.h"
#if !defined(MED_NOT_PRESENT)
#include "med_api.h"
#include "med_smalloc.h"
#endif

#include "string.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "kal_public_api.h"

#include "stack_msgs.h"
#include "stack_config.h"
#include "app_ltlcom.h"

#include "fs_errcode.h"
#include "fs_func.h"

#include "fmt_trc.h"

#include "MMIDataType.h"
#include "mmi_rp_file_type_def.h"

#include "mmi_frm_events_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "Unicodexdcl.h"

#include "FileMgrSrvGProt.h"

/****************************************************************************
* Define
*****************************************************************************/
#define MEM_MED     1
#define MEM_ASM     2
#define MEM_GLOBAL  3

#if !defined(__COSMOS_MMI__)
    // Support 1 stock object (Use med or global memory)
    #if !defined(MED_NOT_PRESENT) && defined(__FS_SORT_SUPPORT__)
        #define FMGR_SRV_FFL_STOCK_OBJ_SUPPORT  MEM_MED
    #else
        #define FMGR_SRV_FFL_STOCK_OBJ_SUPPORT  MEM_GLOBAL
    #endif
#endif

#if defined(__FS_SORT_SUPPORT__)
    #if defined(__COSMOS_MMI__)
    #ifdef __FMGR_SRV_WORK_BUF_FROM_ASM__
        #define FMGR_SRV_FFL_WORK_BUF_FROM  MEM_ASM
        /* both sorting buffer and working buffer are from ASM allocated by App 
           so DONOT define FMGR_SRV_FFL_STOCK_OBJ_SUPPORT */
        #ifdef FMGR_SRV_FFL_STOCK_OBJ_SUPPORT
        #error "FMGR_SRV_FFL_STOCK_OBJ_SUPPORT can't be defined when FMGR_SRV_FFL_WORK_BUF_FROM is MEM_ASM!"
        #endif
    #else
        #define FMGR_SRV_FFL_WORK_BUF_FROM  MEM_GLOBAL
    #endif
    #elif !defined(MED_NOT_PRESENT) && (!defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__) || !defined(__MMI_VUI_SHELL_IMAGE_VIEWER__))
        #define FMGR_SRV_FFL_WORK_BUF_FROM  MEM_MED
    #else
        #define FMGR_SRV_FFL_WORK_BUF_FROM  MEM_GLOBAL
    #endif
#endif

#if defined(__FS_SORT_SUPPORT__)
#define SRV_FMGR_FFL_WORKING_BUFFER_SIZE   (FS_SORT_WORKING_BUFFER_SIZE_FOR_FILES(FS_SORT_MAX_ENTRY))
#define SRV_FMGR_FFL_SORTING_BUFFER_SIZE   (FS_SORT_SORTING_BUFFER_SIZE_FOR_FILES(FS_SORT_MAX_ENTRY))
#else
#define SRV_FMGR_FFL_SORTING_BUFFER_SIZE   (1024)
#endif

typedef struct _srv_fmgri_ffl_struct
{
    srv_fmgr_filelist_base_struct base;

    struct _srv_fmgri_ffl_struct *prev_obj, *next_obj;

    U32                 total_count;
    U32                 progress_count;
    
    U8                  state;
    U8                  dummy1;
    U8                  dummy2;
    U8                  dummy3;
    
    void*               buffer;
    S32                 buffer_size;

    U32                 sort_handle;
    FS_HANDLE           list_handle;

    S32                 cache_start_index;
    S32                 cache_count;

    U32                 seq;
    mmi_proc_func       user_proc;
    void*               user_data;

    void*               memory_pool;
    S32                 memory_pool_size;
    
    U32                 sort_option;
    FMGR_FILTER         filter;
    WCHAR               path[SRV_FMGR_PATH_MAX_LEN+1];

#if defined(SRV_FMGR_TESTBED_ENABLE)
    MMI_BOOL            disable_sort;
#endif
} srv_fmgri_ffl_struct;

typedef struct
{
    U32                     working_seq;
    srv_fmgri_ffl_struct    *active_obj_head, *active_obj_tail;

#if defined(FMGR_SRV_FFL_WORK_BUF_FROM)
#if (FMGR_SRV_FFL_WORK_BUF_FROM == MEM_GLOBAL)
    U8                      working_buffer[SRV_FMGR_FFL_WORKING_BUFFER_SIZE];
#else
    void*                   working_buffer;
#endif
#endif

#if defined(FMGR_SRV_FFL_STOCK_OBJ_SUPPORT)
    U32                     stock_in_used;
    #if (FMGR_SRV_FFL_STOCK_OBJ_SUPPORT == MEM_GLOBAL)
    U8                      stock_sort_buffer[SRV_FMGR_FFL_SORTING_BUFFER_SIZE];
    #else
    void*                   stock_sort_buffer;
    #endif
    srv_fmgri_ffl_struct    stock_obj;
#endif

} srv_fmgri_ffl_context_struct;

/****************************************************************************
* Global Variable
*****************************************************************************/


/****************************************************************************
* Static Variable
*****************************************************************************/

static void        srv_fmgri_ffl_release(srv_fmgr_filelist_base_struct* obj);
static srv_fmgr_filelist_state_enum srv_fmgri_ffl_get_state(srv_fmgr_filelist_base_struct* obj);
static S32          srv_fmgri_ffl_get_capability(srv_fmgr_filelist_base_struct* obj);
static U32         srv_fmgri_ffl_count(srv_fmgr_filelist_base_struct* obj);
static MMI_BOOL    srv_fmgri_ffl_is_empty(srv_fmgr_filelist_base_struct* obj);
static MMI_BOOL    srv_fmgri_ffl_is_dirty(srv_fmgr_filelist_base_struct* obj);
static S32         srv_fmgri_ffl_get_filepath(srv_fmgr_filelist_base_struct* obj, S32 index, WCHAR* buffer, S32 buffer_size);
static S32         srv_fmgri_ffl_get_filename(srv_fmgr_filelist_base_struct* obj, S32 index, WCHAR* buffer, S32 buffer_size);
static S32         srv_fmgri_ffl_get_fileinfo(srv_fmgr_filelist_base_struct* obj, S32 index, srv_fmgr_fileinfo_struct* fileinfo);
static S32         srv_fmgri_ffl_load_file(srv_fmgr_filelist_base_struct* obj, S32 index,
                             mmi_proc_func user_proc, void* user_data);
static S32         srv_fmgri_ffl_refresh(srv_fmgr_filelist_base_struct* obj, const WCHAR* pattern, S32 start_index, 
                                         S32 flag, mmi_proc_func user_proc, void* user_data);
static S32         srv_fmgri_ffl_abort(srv_fmgr_filelist_base_struct* obj);
static void        srv_fmgri_ffl_get_setting(srv_fmgr_filelist_base_struct* obj, FMGR_FILTER* filter, U32* sort_option);
static void        srv_fmgri_ffl_set_setting(srv_fmgr_filelist_base_struct* obj, const FMGR_FILTER* filter, U32 sort_option);

const static srv_fmgr_filelist_interface_struct g_srv_fmgri_ffl_impl_table = 
{
    srv_fmgri_ffl_release,
    srv_fmgri_ffl_get_state,
    srv_fmgri_ffl_get_capability,
    srv_fmgri_ffl_count,
    srv_fmgri_ffl_is_empty,
    srv_fmgri_ffl_is_dirty,
    srv_fmgri_ffl_get_filepath,
    srv_fmgri_ffl_get_filename,
    srv_fmgri_ffl_get_fileinfo,
    srv_fmgri_ffl_load_file,
    srv_fmgri_ffl_refresh,
    srv_fmgri_ffl_abort,
    srv_fmgri_ffl_get_setting,
    srv_fmgri_ffl_set_setting
};

static srv_fmgri_ffl_context_struct g_fmgri_ffl_ctxt;

/****************************************************************************
* Function Forward Declaration
*****************************************************************************/

static void srv_fmgri_ffl_load_dir_rsp_hdlr(void *local_para);
static void srv_fmgri_ffl_load_dir_progress_ind_hdlr(void *local_para);

#define END_OF_FUNCTION_DECLARATION
/****************************************************************************
* Function Body
*****************************************************************************/

void srv_fmgr_folder_filelist_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(srv_fmgri_ffl_load_dir_rsp_hdlr,          MSG_ID_FMT_ADV_LOAD_FOLDER_RSP);
    SetProtocolEventHandler(srv_fmgri_ffl_load_dir_progress_ind_hdlr, MSG_ID_FMT_ADV_LOAD_FOLDER_PROGRESS_IND);

    FMGR_ASSERT(sizeof(srv_fmgri_ffl_struct) + SRV_FMGR_FFL_SORTING_BUFFER_SIZE < SRV_FMGR_FOLDER_FILELIST_MEM_SIZE);
}

S32 srv_fmgr_folder_filelist_create(const WCHAR* folderpath, const FMGR_FILTER* filter, U32 sort, 
                                    void* buffer, S32 buffer_size,
                                    SRV_FMGR_FILELIST_HANDLE* list_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgri_ffl_struct *obj;
    S32 len, fs_ret;
#ifdef __FMGR_SRV_WORK_BUF_FROM_ASM__
    S32 filelist_buffer_size = -1, sort_files = 0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    do {
        if(!list_handle)
        {
            fs_ret = FS_PARAM_ERROR;
            break;
        }

        if(buffer && buffer_size <= 1024)
        {
            fs_ret = FS_PARAM_ERROR;
            break;
        }
        
#ifdef __FMGR_SRV_WORK_BUF_FROM_ASM__
        /* In COSMOS project, buffer size must be 
           SRV_FMGR_FFL_SORTING_BUFFER_SIZE+1024+SRV_FMGR_FFL_WORKING_BUFFER_SIZE */

        filelist_buffer_size = buffer_size - 1024;
        
        sort_files = FS_SORT_FILES_FOR_TOTAL_BUFFER_SIZE(filelist_buffer_size);

        FMGR_TRACE3(TGL1, TRC_SRV_FMGR_FILELIST_BUFFER, "[SRV_FMGR] > FFL > buffer(0x%08X) size: %d, sort_files: %d", buffer, buffer_size, sort_files);
        FMGR_ASSERT(sort_files >= 0);
#endif

        len = srv_fmgri_path_check_folderpath(folderpath);
        if(len < 0)
        {
            fs_ret = len;
            break;
        }

        if(buffer)
        {
            obj = (srv_fmgri_ffl_struct*)buffer;
        }
        else
        {
#if defined(FMGR_SRV_FFL_STOCK_OBJ_SUPPORT)
            /* only 1 stock object */
            FMGR_ASSERT(!g_fmgri_ffl_ctxt.stock_in_used);
            g_fmgri_ffl_ctxt.stock_in_used = MMI_TRUE;

            obj = &g_fmgri_ffl_ctxt.stock_obj;
#else
            obj = NULL;
#endif
        }
        if(!obj)
        {
            fs_ret = SRV_FMGR_ERROR_OUT_OF_MEMORY;
            break;
        }

        memset(obj, 0, sizeof(srv_fmgri_ffl_struct));
        obj->base.fl_if = &g_srv_fmgri_ffl_impl_table;
        obj->memory_pool = buffer;
        obj->memory_pool_size = buffer_size;

        if(filter)
            obj->filter = *filter;
        else
            FMGR_FILTER_SET_ALL(&obj->filter);

        switch(sort)
        {
        case FS_NO_SORT:
        case FS_SORT_NAME:
        case FS_SORT_SIZE:
        case FS_SORT_TYPE:
        case FS_SORT_TIME:
            break;

        default:
#if defined(SRV_FMGR_TESTBED_ENABLE)
            if(sort == FS_SORT_USER)
                obj->disable_sort = MMI_TRUE;
#endif            
            sort = FS_SORT_NAME;
            break;
        }
        
        obj->sort_option = sort;
        mmi_wcsncpy(obj->path, folderpath, len);

        // Append '\\' if necessary
        if(obj->path[len-1] != '\\')
        {
            obj->path[len++] = '\\';
            obj->path[len] = 0;
        }        

        /* buffer */
        if(buffer)
        {
            obj->buffer = (U8*)buffer + 1024;
#ifdef __FMGR_SRV_WORK_BUF_FROM_ASM__
            obj->buffer_size = FS_SORT_SORTING_BUFFER_SIZE_FOR_FILES(sort_files);
            FMGR_TRACE2(TGL1, TRC_SRV_FMGR_FILELIST_SORTING_BUFFER, "[SRV_FMGR] > FFL > sorting buffer(0x%08X) size: %d", obj->buffer, obj->buffer_size);
#else
            obj->buffer_size = buffer_size - 1024;
#endif
        }
#if defined(FMGR_SRV_FFL_STOCK_OBJ_SUPPORT)
        else
        {
        #if (FMGR_SRV_FFL_STOCK_OBJ_SUPPORT == MEM_MED)
            S32 result;
            FMGR_ASSERT(!g_fmgri_ffl_ctxt.stock_sort_buffer);
            result = media_get_ext_buffer_topmost_noncacheable(MOD_MMI, (void**)&g_fmgri_ffl_ctxt.stock_sort_buffer, SRV_FMGR_FFL_SORTING_BUFFER_SIZE);
            FMGR_ASSERT(result == 0);
        #endif
            obj->buffer = g_fmgri_ffl_ctxt.stock_sort_buffer;
            obj->buffer_size = SRV_FMGR_FFL_SORTING_BUFFER_SIZE;
        }
#endif        
        /* clear sort buffer */
        kal_mem_set(obj->buffer, 0, obj->buffer_size);

        /* add to link list */
        if(!g_fmgri_ffl_ctxt.active_obj_tail)
        {
            g_fmgri_ffl_ctxt.active_obj_head = g_fmgri_ffl_ctxt.active_obj_tail = obj;
        }
        else
        {
            g_fmgri_ffl_ctxt.active_obj_tail->next_obj = obj;
            obj->prev_obj = g_fmgri_ffl_ctxt.active_obj_tail;
            g_fmgri_ffl_ctxt.active_obj_tail = obj;
        }

        *list_handle = (SRV_FMGR_FILELIST_HANDLE)obj;
        fs_ret = 0;
    } while(0);

    FMGR_TRACE2(TGL1, TRC_SRV_FMGR_C59851F0C6D34FC4BE4766B22BFD67E7, 
        "[SRV_FMGR] > FFL > create(%x): %d", list_handle ? *list_handle : 0, fs_ret);
    
    return fs_ret;
}

#define LOCAL_FUNCTION

static void srv_fmgri_ffl_load_dir_rsp_hdlr(void *local_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_load_folder_rsp_struct  *msg_rsp = (fmt_adv_load_folder_rsp_struct*)local_para;
    srv_fmgri_ffl_struct            *obj;
    union {
        srv_fmgr_filelist_refresh_result_event_struct refresh;
        srv_fmgr_filelist_load_result_event_struct load;
    } evt;
    U16 rsp_evt_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* it is a skipped response */
    if(msg_rsp->req_seq != g_fmgri_ffl_ctxt.working_seq)
        return;

    obj = (srv_fmgri_ffl_struct*)msg_rsp->user_data;

    /* free working buffer */
    FMGR_ASSERT(g_fmgri_ffl_ctxt.working_seq && 
           g_fmgri_ffl_ctxt.working_seq == obj->seq);

#if defined(FMGR_SRV_FFL_WORK_BUF_FROM) && (FMGR_SRV_FFL_WORK_BUF_FROM == MEM_MED)
    {
        S32 result;
        FMGR_ASSERT(g_fmgri_ffl_ctxt.working_buffer);
        result = media_free_ext_buffer(MOD_MMI, (void**)&g_fmgri_ffl_ctxt.working_buffer);
        FMGR_ASSERT(result == 0);
        g_fmgri_ffl_ctxt.working_buffer = NULL;
    }
#endif
    g_fmgri_ffl_ctxt.working_seq = 0;
    obj->seq = 0;

    if(obj->state == SRV_FMGR_FILELIST_STATE_REFRESHING)
        rsp_evt_id = EVT_ID_SRV_FMGR_FILELIST_REFRESH_RESULT;
    else
        rsp_evt_id = EVT_ID_SRV_FMGR_FILELIST_LOAD_RESULT;

    /* update status */
    if(msg_rsp->result >= 0)
    {
        obj->state = SRV_FMGR_FILELIST_STATE_READY;
    }
    else
    {
        obj->state = SRV_FMGR_FILELIST_STATE_INIT;
    }
    
    obj->total_count = msg_rsp->total_count;
    if(msg_rsp->cache_count)
    {
        obj->list_handle = (FS_HANDLE)msg_rsp->sort_handle;
        obj->cache_start_index = msg_rsp->cache_start_index;
        obj->cache_count = msg_rsp->cache_count;
        obj->sort_handle = 0;
    }
    else
    {
        obj->list_handle = 0;
        obj->cache_start_index = 0;
        obj->cache_count = 0;
        obj->sort_handle = msg_rsp->sort_handle;
    }

    /* callback via user_proc */
    memset(&evt, 0, sizeof(evt));
    if(rsp_evt_id == EVT_ID_SRV_FMGR_FILELIST_REFRESH_RESULT)
    {
        evt.refresh.evt_id = rsp_evt_id;
        evt.refresh.size = sizeof(evt.refresh);

        evt.refresh.handle = (SRV_FMGR_FILELIST_HANDLE)obj;

        evt.refresh.result = msg_rsp->result;
        evt.refresh.search_index = msg_rsp->found_index;
        evt.refresh.total_count = msg_rsp->total_count;
        evt.refresh.number_of_folder = msg_rsp->total_folder_count;
    }
    else
    {
        evt.load.evt_id = rsp_evt_id;
        evt.load.size = sizeof(evt.load);

        evt.load.handle = (SRV_FMGR_FILELIST_HANDLE)obj;

        evt.load.result = msg_rsp->result;
        evt.load.ready_index_start = msg_rsp->cache_start_index;
        evt.load.ready_index_end = msg_rsp->cache_start_index + msg_rsp->cache_count;
    }

    MMI_FRM_POST_EVENT(&evt, obj->user_proc, obj->user_data);
    
}

static void srv_fmgri_ffl_load_dir_progress_ind_hdlr(void *local_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_load_folder_progress_ind_struct         *msg_ind = (fmt_adv_load_folder_progress_ind_struct*)local_para;
    srv_fmgri_ffl_struct                            *obj;
    srv_fmgr_filelist_refresh_progress_event_struct evt;
    U16 rsp_evt_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* it is a skipped response */
    if(msg_ind->req_seq != g_fmgri_ffl_ctxt.working_seq)
        return;

    obj = (srv_fmgri_ffl_struct*)msg_ind->user_data;

    FMGR_ASSERT(obj->state == SRV_FMGR_FILELIST_STATE_REFRESHING);
    rsp_evt_id = EVT_ID_SRV_FMGR_FILELIST_REFRESH_PROGRESS;

    /* update status */
    obj->total_count = msg_ind->total_count;
    obj->progress_count = msg_ind->complete_count;

    if(msg_ind->cache_count)
    {
        obj->list_handle = (FS_HANDLE)msg_ind->sort_handle;
        obj->cache_start_index = msg_ind->cache_start_index;
        obj->cache_count = msg_ind->cache_count;
        obj->sort_handle = 0;
    }
    else
    {
        obj->list_handle = 0;
        obj->cache_start_index = 0;
        obj->cache_count = 0;
        obj->sort_handle = msg_ind->sort_handle;
    }

    /* callback via user_proc */
    memset(&evt, 0, sizeof(evt));
    evt.evt_id = rsp_evt_id;
    evt.size = sizeof(evt);

    evt.handle = (SRV_FMGR_FILELIST_HANDLE)obj;

    evt.total_count = msg_ind->total_count;
    evt.completed_count = msg_ind->complete_count;

    MMI_FRM_POST_EVENT(&evt, obj->user_proc, obj->user_data);

}

static U32 srv_fmgri_ffl_send_load_dir_req(srv_fmgri_ffl_struct *obj,
                                            S32 prefer_index,
                                            const WCHAR* search_filename,
                                            S32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_load_folder_req_struct *msg_req;
    peer_buff_struct            *peer_buff_ptr;
    U16                         len;
    S32                         peer_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    // cancel current ongoing request
    if(g_fmgri_ffl_ctxt.working_seq)
    {
        fmt_adv_load_folder_rsp_struct abort_rsp;
        srv_fmgri_ffl_struct *curr_obj = g_fmgri_ffl_ctxt.active_obj_head;

        // find ongoing object
        while(curr_obj)
        {
            if(curr_obj->seq == g_fmgri_ffl_ctxt.working_seq)
                break;
            curr_obj = curr_obj->next_obj;
        }
        FMGR_ASSERT(curr_obj);

        // abort it
        fmt_adv_abort_message(g_fmgri_ffl_ctxt.working_seq, KAL_TRUE, KAL_TRUE);
        kal_mem_set(curr_obj->buffer, 0, curr_obj->buffer_size);
        
        // fake a response
        kal_mem_set(&abort_rsp, 0, sizeof(abort_rsp));
        abort_rsp.req_seq = g_fmgri_ffl_ctxt.working_seq;
        abort_rsp.user_data = (U32)curr_obj;
        abort_rsp.result = FS_ABORTED_ERROR;
        srv_fmgri_ffl_load_dir_rsp_hdlr(&abort_rsp);
    }

    FMGR_ASSERT(obj->state == SRV_FMGR_FILELIST_STATE_INIT || obj->state == SRV_FMGR_FILELIST_STATE_READY);

    if(obj->state == SRV_FMGR_FILELIST_STATE_READY)
    {
        /* release check */
        fmt_adv_load_folder_check_release(obj->path);

#if defined(__FS_SORT_SUPPORT__)
        /* release handle */
        if(obj->sort_handle)
        {
            FS_XFindClose(&obj->sort_handle);
            obj->sort_handle = 0;
        }
#endif

        if(obj->list_handle)
        {
            FS_ListClose(obj->list_handle);
            obj->list_handle = 0;
        }
    }
    
    /* prepare message data */
    msg_req = (fmt_adv_load_folder_req_struct*) OslConstructDataPtr(sizeof(fmt_adv_load_folder_req_struct));
    
    mmi_ucs2cpy((CHAR*)msg_req->folderpath, (CHAR*)obj->path);
    msg_req->AttrMask = FS_ATTR_HIDDEN | FS_ATTR_SYSTEM | FS_ATTR_VOLUME;
    msg_req->ArrayMask = 0;
    msg_req->Flag = FS_FILE_TYPE | obj->sort_option;

    msg_req->filter_count = srv_fmgri_construct_filter_pattern(&obj->filter, NULL, 0);

    /* alloc peer_buff if necessary */
    peer_size = 0;
    if(search_filename)
    {
        peer_size = ((mmi_wcslen(search_filename) + 1) * ENCODING_LENGTH + 3) / 4 * 4;
    }
    peer_size += msg_req->filter_count * sizeof(FS_Pattern_Struct);

    if(peer_size)
    {
        peer_buff_ptr = construct_peer_buff((U16)peer_size, 0, 0, TD_RESET);

        if(search_filename)
        {
            msg_req->search_filename = (WCHAR*)get_pdu_ptr(peer_buff_ptr, &len);
            mmi_wcscpy(msg_req->search_filename, search_filename);
        }

        if(msg_req->filter_count)
        {
            peer_size -= msg_req->filter_count * sizeof(FS_Pattern_Struct);
            
            msg_req->filter_array = (FS_Pattern_Struct*)((U32)get_pdu_ptr(peer_buff_ptr, &len) + peer_size);
            srv_fmgri_construct_filter_pattern(&obj->filter, msg_req->filter_array, msg_req->filter_count);
        }
    }
    else
    {
        peer_buff_ptr = NULL;
    }

    if(FMGR_FILTER_IS_SET(&obj->filter, FMGR_TYPE_FOLDER))
    {
        if(msg_req->filter_count == 1)
        {
            /* folder only, remove file */
            msg_req->Flag &= ~FS_FILE_TYPE;
        }

        if (msg_req->filter_count > 0)
        {
            msg_req->filter_count--;
        }

        msg_req->ArrayMask |= FS_ATTR_DIR;
        msg_req->Flag |= FS_DIR_TYPE;
    }

    msg_req->load_index = prefer_index;
    msg_req->total_count = -1;
    if(prefer_index >= 0 && obj->total_count > 0)
        msg_req->total_count = obj->total_count;

    /* obtain working buffer */
    FMGR_ASSERT(!g_fmgri_ffl_ctxt.working_seq);
    
    FMGR_ASSERT(obj->buffer);

    msg_req->sort_buffer = obj->buffer;
    msg_req->sort_buffer_size = obj->buffer_size;

#if defined(FMGR_SRV_FFL_WORK_BUF_FROM)
    #if (FMGR_SRV_FFL_WORK_BUF_FROM == MEM_ASM)
    {
        msg_req->work_buffer = (void*)((U8*)obj->memory_pool + (obj->buffer_size+1024));
        msg_req->work_buffer_size = obj->memory_pool_size-(obj->buffer_size+1024);
        FMGR_TRACE2(TGL1, TRC_SRV_FMGR_FILELIST_WORKING_BUFFER, "[SRV_FMGR] > FFL > working buffer(0x%08X) size: %d", msg_req->work_buffer, msg_req->work_buffer_size);
    }
    #else
    {
        #if (FMGR_SRV_FFL_WORK_BUF_FROM == MEM_MED)
        {
            S32 result;
            FMGR_ASSERT(!g_fmgri_ffl_ctxt.working_buffer);
            result = media_get_ext_buffer_topmost_cacheable(MOD_MMI, (void**)&g_fmgri_ffl_ctxt.working_buffer, SRV_FMGR_FFL_WORKING_BUFFER_SIZE);
            FMGR_ASSERT(result == 0 && g_fmgri_ffl_ctxt.working_buffer);
        }
        #endif
        msg_req->work_buffer = g_fmgri_ffl_ctxt.working_buffer;
        msg_req->work_buffer_size = SRV_FMGR_FFL_WORKING_BUFFER_SIZE;
    }
    #endif
#endif

#if defined(SRV_FMGR_TESTBED_ENABLE)
    if(obj->disable_sort)
    {
        msg_req->work_buffer = NULL;
        msg_req->work_buffer_size = 0;
    }
#endif


#ifdef FMGR_SORT_BY_USER_SAMPLE_CODE   /* If user want to overwrite a exist sort type */
    if(obj->sort_option == FS_SORT_NAME)
    {
        msg_req->Flag &= ~FS_SORT_NAME;
        msg_req->Flag |= FS_SORT_USER;
        msg_req->sort_compare_func = (void*)fmgr_sort_by_user;
    }
#endif

    ASSERT(!(msg_req->Flag & 0xF0000000));  // make sure FS dont use last 4 bit.
    if(flag & SRV_FMGR_FILELIST_REFRESH_PROGRESS_ON)
        msg_req->Flag |= 0x80000000;        // because we will use it.

    msg_req->user_data = (U32)obj;

    g_fmgri_ffl_ctxt.working_seq = fmt_adv_send_message(MSG_ID_FMT_ADV_LOAD_FOLDER_REQ, (local_para_struct*)msg_req, peer_buff_ptr);
    FMGR_ASSERT(g_fmgri_ffl_ctxt.working_seq);
    return g_fmgri_ffl_ctxt.working_seq;
}
#define FL_TABLE

static void srv_fmgri_ffl_release(srv_fmgr_filelist_base_struct* obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgri_ffl_struct* self = (srv_fmgri_ffl_struct*)obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* remove from link list */
    if(self->prev_obj)
        self->prev_obj->next_obj = self->next_obj;
    if(self->next_obj)
        self->next_obj->prev_obj = self->prev_obj;
    if(g_fmgri_ffl_ctxt.active_obj_head == self)
        g_fmgri_ffl_ctxt.active_obj_head = self->next_obj;
    if(g_fmgri_ffl_ctxt.active_obj_tail == self)
        g_fmgri_ffl_ctxt.active_obj_tail = self->prev_obj;

    /* cancel operation if ongoing */
    if(g_fmgri_ffl_ctxt.working_seq && g_fmgri_ffl_ctxt.working_seq == self->seq)
    {
        fmt_adv_abort_message(self->seq, KAL_TRUE, KAL_TRUE);
        g_fmgri_ffl_ctxt.working_seq = 0;

#if defined(FMGR_SRV_FFL_WORK_BUF_FROM) && (FMGR_SRV_FFL_WORK_BUF_FROM == MEM_MED)
        if(g_fmgri_ffl_ctxt.working_buffer)
        {
            S32 result;
            result = media_free_ext_buffer(MOD_MMI, (void**)&g_fmgri_ffl_ctxt.working_buffer);
            FMGR_ASSERT(result == 0);
            g_fmgri_ffl_ctxt.working_buffer = NULL;
        }
#endif
    }

    /* release check */
    fmt_adv_load_folder_check_release(self->path);

#if defined(__FS_SORT_SUPPORT__)
    /* release handle */
    if(self->sort_handle)
    {
        FS_XFindClose(&self->sort_handle);
        self->sort_handle = 0;
    }
#endif
    if(self->list_handle)
    {
        FS_ListClose(self->list_handle);
        self->list_handle = 0;
    }

#if defined(FMGR_SRV_FFL_STOCK_OBJ_SUPPORT)
    if(self == &g_fmgri_ffl_ctxt.stock_obj)
    {
    #if (FMGR_SRV_FFL_STOCK_OBJ_SUPPORT == MEM_MED)
        S32 result;
        result = media_free_ext_buffer(MOD_MMI, (void**)&g_fmgri_ffl_ctxt.stock_sort_buffer);
        FMGR_ASSERT(result == 0);
        g_fmgri_ffl_ctxt.stock_sort_buffer = NULL;
    #endif
        FMGR_ASSERT(g_fmgri_ffl_ctxt.stock_in_used);
        g_fmgri_ffl_ctxt.stock_in_used = MMI_FALSE;
    }
#endif

    if(self->buffer)
    {
        self->buffer = NULL;
    }

}

static srv_fmgr_filelist_state_enum srv_fmgri_ffl_get_state(srv_fmgr_filelist_base_struct* obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgri_ffl_struct* self = (srv_fmgri_ffl_struct*)obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (srv_fmgr_filelist_state_enum)(self->state);
}

static S32 srv_fmgri_ffl_get_capability(srv_fmgr_filelist_base_struct* obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgri_ffl_struct* self = (srv_fmgri_ffl_struct*)obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(self->state == SRV_FMGR_FILELIST_STATE_READY && self->sort_handle)
        return SRV_FMGR_FILELIST_CAP_RANDOM_ACCESS;

    return SRV_FMGR_FILELIST_CAP_LOAD_ON_DEMAND;
}

static U32 srv_fmgri_ffl_count(srv_fmgr_filelist_base_struct* obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgri_ffl_struct* self = (srv_fmgri_ffl_struct*)obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return self->total_count;
}

static MMI_BOOL srv_fmgri_ffl_is_empty(srv_fmgr_filelist_base_struct* obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgri_ffl_struct* self = (srv_fmgri_ffl_struct*)obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return self->total_count ? MMI_FALSE : MMI_TRUE;
}

static MMI_BOOL srv_fmgri_ffl_is_dirty(srv_fmgr_filelist_base_struct* obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgri_ffl_struct* self = (srv_fmgri_ffl_struct*)obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(self->state == SRV_FMGR_FILELIST_STATE_READY &&
        fmt_adv_load_folder_check_changed(self->path) >= 0)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}

static S32 srv_fmgri_ffl_get_filepath(srv_fmgr_filelist_base_struct* obj, S32 index, WCHAR* buffer, S32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgri_ffl_struct* self = (srv_fmgri_ffl_struct*)obj;
    S32 fs_ret, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    do {
        len = srv_fmgri_ffl_get_filename(obj, index, NULL, 0);
        if(len < 0)
        {
            fs_ret = len;
            break;
        }

        len = len + mmi_wcslen(self->path);

        if(len > SRV_FMGR_PATH_MAX_LEN)
        {
            fs_ret = FS_PATH_OVER_LEN_ERROR;
            break;
        }

        if(!buffer)
        {
            fs_ret = len;
            break;
        }

        if((len + 1)*ENCODING_LENGTH > buffer_size)
        {
            fs_ret = FS_STRING_BUFFER_TOO_SMALL;
            break;
        }

        len = mmi_wcslen(self->path);
        mmi_wcsncpy(buffer, self->path, len);
        fs_ret = srv_fmgri_ffl_get_filename(obj, index, buffer + len, buffer_size - len*ENCODING_LENGTH);

    } while(0);

    return fs_ret;
}

static S32 srv_fmgri_ffl_get_filename_ex(srv_fmgri_ffl_struct* self, S32 index, 
                                          WCHAR* buffer, S32 buffer_size, 
                                          srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret, len;
    WCHAR* filename;
    /*fmt_adv_load_folder_cache_item_struct *cache_item;*/
    /*FS_HANDLE fh;*/
    FS_DOSDirEntry  fs_entry;
    /*FS_FileInfo     fs_info;*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(self->state)
    {
    case SRV_FMGR_FILELIST_STATE_INIT:
        return SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY;

    case SRV_FMGR_FILELIST_STATE_LOADING:
        return SRV_FMGR_FILELIST_ERROR_BUSY;

    case SRV_FMGR_FILELIST_STATE_REFRESHING:
        if(index < 0 || index >= (S32)self->progress_count)
            return FS_PARAM_ERROR;
        break;
    }

    if(index < 0 || index >= (S32)self->total_count)
        return FS_PARAM_ERROR;

    filename = NULL;
    
    do {
        if(!self->sort_handle &&
            (index < self->cache_start_index || index >= self->cache_start_index + self->cache_count))
        {
            fs_ret = SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY;
            break;
        }

        filename = srv_fmgri_alloc_path_buffer();

    #ifdef __FS_SORT_SUPPORT__
        if(self->sort_handle)   
        {
            /*
             * random access
             */
            fs_ret = FS_XFindStart(
                self->path, 
                &fs_entry,
                filename,
                SRV_FMGR_PATH_BUFFER_SIZE,
                (U32)index,
                &self->sort_handle,
                FS_FIND_DEFAULT);

            if(fs_ret < 0)
                break;

            len = mmi_wcslen(filename);
        }
        else
    #endif
        {
            /*
             * load on demand and in cache
             */
#if 1
            fs_ret = FS_ListNext(
                self->list_handle,
                &fs_entry,
                self->path,
                filename, 
                SRV_FMGR_PATH_BUFFER_SIZE,
                index - self->cache_start_index);

            if(fs_ret < 0)
                break;

            len = mmi_wcslen(filename);
#else
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
        }

        FMGR_ASSERT(len <= SRV_FMGR_PATH_MAX_LEN);

        if(!buffer)
        {
            fs_ret = len;
            break;
        }

        if((len + 1)*ENCODING_LENGTH > buffer_size)
        {
            fs_ret = FS_STRING_BUFFER_TOO_SMALL;
            break;
        }

        mmi_wcscpy(buffer, filename);
        fs_ret = 0;
        break;

    } while(0);

    if(fs_ret >= 0 && fileinfo)
        srv_fmgri_convert_direntry(fileinfo, &fs_entry, filename);

    if(filename)
        srv_fmgri_free_path_buffer(filename);

    return fs_ret;
}

static S32 srv_fmgri_ffl_get_filename(srv_fmgr_filelist_base_struct* obj, S32 index, WCHAR* buffer, S32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgri_ffl_struct* self = (srv_fmgri_ffl_struct*)obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_fmgri_ffl_get_filename_ex(self, index, buffer, buffer_size, NULL);
}

static S32 srv_fmgri_ffl_get_fileinfo(srv_fmgr_filelist_base_struct* obj, S32 index, srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgri_ffl_struct* self = (srv_fmgri_ffl_struct*)obj;
    S32 fs_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_ret = srv_fmgri_ffl_get_filename_ex(self, index, NULL, 0, fileinfo);
    if(fs_ret > 0)
        fs_ret = 0;
    return fs_ret;
}

static S32 srv_fmgri_ffl_load_file(srv_fmgr_filelist_base_struct* obj, S32 index,
                             mmi_proc_func user_proc, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgri_ffl_struct* self = (srv_fmgri_ffl_struct*)obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* check if load required */
    if(self->state == SRV_FMGR_FILELIST_STATE_READY &&
        self->sort_handle || (index >= self->cache_start_index && index < self->cache_start_index + self->cache_count))
    {
        return SRV_FMGR_FILELIST_ERROR_FILE_READY;
    }
    
    /* check state */
    if(self->state == SRV_FMGR_FILELIST_STATE_REFRESHING ||
        self->state == SRV_FMGR_FILELIST_STATE_LOADING)
    {
        return SRV_FMGR_FILELIST_ERROR_BUSY;
    }

    /* send request */
    self->user_data = user_data;
    self->user_proc = user_proc;
    self->seq = srv_fmgri_ffl_send_load_dir_req(self, index, NULL, 0);
    self->state = SRV_FMGR_FILELIST_STATE_LOADING;

    return 0;
}

static S32 srv_fmgri_ffl_refresh(srv_fmgr_filelist_base_struct* obj, const WCHAR* pattern, S32 start_index, 
                                 S32 flag, mmi_proc_func user_proc, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgri_ffl_struct* self = (srv_fmgri_ffl_struct*)obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* check state */
    if(self->state == SRV_FMGR_FILELIST_STATE_REFRESHING ||
        self->state == SRV_FMGR_FILELIST_STATE_LOADING)
    {
        return SRV_FMGR_FILELIST_ERROR_BUSY;
    }

    /* send request */
    self->user_data = user_data;
    self->user_proc = user_proc;
    if(!pattern && start_index > 0)
    {
        self->total_count = 0;
        self->seq = srv_fmgri_ffl_send_load_dir_req(self, start_index, NULL, flag);
    }
    else
    {
        self->seq = srv_fmgri_ffl_send_load_dir_req(self, -1, pattern, flag);
    }
    self->state = SRV_FMGR_FILELIST_STATE_REFRESHING;

    return 0;
}

static S32 srv_fmgri_ffl_abort(srv_fmgr_filelist_base_struct* obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgri_ffl_struct* self = (srv_fmgri_ffl_struct*)obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(self->state != SRV_FMGR_FILELIST_STATE_REFRESHING &&
        self->state != SRV_FMGR_FILELIST_STATE_LOADING)
        return FS_NO_ERROR;

    /* cancel operation if ongoing */
    if(g_fmgri_ffl_ctxt.working_seq && g_fmgri_ffl_ctxt.working_seq == self->seq)
    {
        fmt_adv_abort_message(self->seq, KAL_TRUE, KAL_TRUE);
        g_fmgri_ffl_ctxt.working_seq = 0;

#if defined(FMGR_SRV_FFL_WORK_BUF_FROM) && (FMGR_SRV_FFL_WORK_BUF_FROM == MEM_MED)    
        if(g_fmgri_ffl_ctxt.working_buffer)
        {
            S32 result;
            result = media_free_ext_buffer(MOD_MMI, (void**)&g_fmgri_ffl_ctxt.working_buffer);
            FMGR_ASSERT(result == 0);
            g_fmgri_ffl_ctxt.working_buffer = NULL;
        }
#endif
    }

    self->seq = 0;
    self->state = SRV_FMGR_FILELIST_STATE_INIT;

    return FS_NO_ERROR;    
}

static void srv_fmgri_ffl_get_setting(srv_fmgr_filelist_base_struct* obj, FMGR_FILTER* filter, U32* sort_option)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgri_ffl_struct* self = (srv_fmgri_ffl_struct*)obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(filter)
        *filter = self->filter;
    if(sort_option)
        *sort_option = self->sort_option;
}

static void srv_fmgri_ffl_set_setting(srv_fmgr_filelist_base_struct* obj, const FMGR_FILTER* filter, U32 sort_option)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgri_ffl_struct* self = (srv_fmgri_ffl_struct*)obj;
    MMI_BOOL change = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(filter && kal_mem_cmp(&self->filter, filter, sizeof(self->filter)))
    {
        self->filter = *filter;
        change = MMI_TRUE;
    }
    if(self->sort_option != sort_option)
    {
        self->sort_option = sort_option;
        change = MMI_TRUE;
    }
    if(change)
        fmt_adv_load_folder_check_release(self->path);
}


