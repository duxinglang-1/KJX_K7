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
 *  vadp_shell_imageviewer.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions from the Venus MMI to the Pluto
 *  MMI.
 *
 *      Pluto APP <---> adaptor <---> Venus APP
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/ 
#include "MMI_features.h"
#ifdef __MMI_VUI_SHELL_IMAGE_VIEWER__
#include "vadp_shell_imageviewer.h"
#include "trc/vadp_app_trc.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_system.h"
/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
#include "FileMgrType.h"
#include "Gdi_include.h"
#include "med_api.h"
#ifdef __DRM_SUPPORT__
#include "drm_def.h"
#include "drm_errcode.h"
#endif
#ifdef MOTION_SENSOR_SUPPORT
#include "SensorSrvGport.h"
#endif
#ifdef __MMI_SCREEN_SWITCH_EFFECT__    
#include "gui_effect_oem.h"
#endif
#include "MediaCacheSrvGprot.h"
#include "FileMgrSrvGProt.h"
#include "ImageViewerGprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "fs_type.h"
#include "vadp_shell_imageviewer_config.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "mmi_frm_mem_gprot.h"
#include "string.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "stdio.h"
#include "Unicodexdcl.h"
#include "ImageViewCuiGprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "mmi_rp_file_type_def.h"
#include "lcd_sw_rnd.h"
#include "MediaCacheSrvMem.h"
#include "DebugInitDef_Int.h"
#include "gdi_const.h"
#ifdef __cplusplus
}
#endif

/**********************************************************************
 * Structure Definitions:
 **********************************************************************/
typedef struct
{
    vapp_shell_imgviewer_decode_callback decode_cb;
    vapp_shell_imgviewer_list_ready_callback list_ready_cb;
    vapp_shell_imgviewer_delete_done_callback delete_done_cb;
    vapp_shell_imgviewer_refreshing_filelist_callback refreshing_list_cb;
    srv_mediacache_engine_clip resize_img_cb;
    U32 med_mem_buf_size;
    U32 cellcount;
    VfxU32      focus_idx;
    srv_handle srv_mediacache_handle;
    void *med_mem_buf_p;
    void *filelist_buf_p;
    void *srv_mediacache_run_buf;
    void*  menu_ptr;
    void*  panel_ptr;
    vadp_shell_iv_fl_state_enum     fl_state;
    VfxBool is_over_sorting_limit;
    VfxBool is_paused;
    MMI_ID scrn_gid;    
    WCHAR folder_buf[SRV_FMGR_PATH_MAX_LEN + 1];    
    SRV_FMGR_FILELIST_HANDLE list_handle;
    VfxS32      delete_idx;
#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__MM_DEBUG_MEASURE__) 
/* under construction !*/
/* under construction !*/
#endif    
} vadp_shell_imgviewer_context;


/**********************************************************************
 * Global variables:
 **********************************************************************/
static U8 g_vadp_shell_imgviewer_filelist_buffer[VADP_SHELLIV_FILELIST_MEM_SIZE];
static vadp_shell_imgviewer_context g_vadp_shell_imgviewer_cntx;


/**********************************************************************
 * Defines:
 **********************************************************************/
#define VADP_SHELLIV_FILELIST_MAPPED_INX(idx)   \
    (((g_vadp_shell_imgviewer_cntx.delete_idx != VADP_SHELLIV_FILELIST_EMPTY) &&    \
       ((idx) >= g_vadp_shell_imgviewer_cntx.delete_idx)) ?                         \
     ((idx) + 1) : (idx))


/*****************************************************************************
* Local Function 
*****************************************************************************/
mmi_ret vadp_shell_imgviewer_proc(mmi_event_struct *param);

#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_get_focus_index
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vadp_shell_imgviewer_get_focus_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_vadp_shell_imgviewer_cntx.focus_idx;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_set_focus_index
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_shell_imgviewer_set_focus_index(VfxS32 focus_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vadp_shell_imgviewer_cntx.focus_idx = focus_index;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_get_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
VfxU8 vadp_shell_imgviewer_get_storage()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (VfxU8)mmi_imgview_get_storage();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_set_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_shell_imgviewer_set_storage(VfxU8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imgview_set_storage((U16)storage);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_register_list_ready_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_shell_imgviewer_register_list_ready_callback(void* user_data, vapp_shell_imgviewer_list_ready_callback cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vadp_shell_imgviewer_cntx.list_ready_cb = cb;
    g_vadp_shell_imgviewer_cntx.panel_ptr = user_data;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_register_delete_done_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_shell_imgviewer_register_delete_done_callback(void* user_data, vapp_shell_imgviewer_delete_done_callback cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vadp_shell_imgviewer_cntx.delete_done_cb = cb;
    g_vadp_shell_imgviewer_cntx.panel_ptr = user_data;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_is_list_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
VfxBool vadp_shell_imgviewer_is_list_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;
    S32 result = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_LOG(VFX_INFO, VADP_SHELLIV_FL_STATE, __LINE__, g_vadp_shell_imgviewer_cntx.fl_state);

    if (g_vadp_shell_imgviewer_cntx.fl_state != VADP_SHELLIV_FL_STATE_EXIT)
    {
        ret = srv_fmgr_filelist_is_dirty(g_vadp_shell_imgviewer_cntx.list_handle); 

        if (ret == MMI_TRUE &&
            g_vadp_shell_imgviewer_cntx.fl_state != VADP_SHELLIV_FL_STATE_REFRESHING)
        {
            g_vadp_shell_imgviewer_cntx.fl_state = VADP_SHELLIV_FL_STATE_DIRTY;

            VFX_LOG(VFX_INFO, VADP_SHELLIV_REFRESH_LIST, __LINE__, g_vadp_shell_imgviewer_cntx.focus_idx);
            
            result = srv_fmgr_filelist_refresh(
                        g_vadp_shell_imgviewer_cntx.list_handle, 
                        NULL, 
                        g_vadp_shell_imgviewer_cntx.focus_idx, 
                        0, 
                        vadp_shell_imgviewer_proc, 
                        NULL);

            VFX_LOG(VFX_INFO, VADP_SHELLIV_RESULT, __LINE__, result);

            if (result >= 0)
            {
                g_vadp_shell_imgviewer_cntx.fl_state = VADP_SHELLIV_FL_STATE_REFRESHING;
            }
            else if (vadp_shell_imgviewer_check_is_valid_drv(vadp_shell_imgviewer_get_storage()))
            {
                if (result == SRV_FMGR_FILELIST_ERROR_FILE_READY)
                {
                    g_vadp_shell_imgviewer_cntx.cellcount = srv_fmgr_filelist_count(g_vadp_shell_imgviewer_cntx.list_handle);
                    g_vadp_shell_imgviewer_cntx.fl_state = VADP_SHELLIV_FL_STATE_READY;

                    if (g_vadp_shell_imgviewer_cntx.focus_idx > g_vadp_shell_imgviewer_cntx.cellcount - 1)
                        g_vadp_shell_imgviewer_cntx.focus_idx = 0;
                    
                    if (g_vadp_shell_imgviewer_cntx.list_ready_cb)
                    {
                        g_vadp_shell_imgviewer_cntx.list_ready_cb(g_vadp_shell_imgviewer_cntx.panel_ptr);
                    }
                }
                else if (result == SRV_FMGR_FILELIST_ERROR_BUSY)
                {
                    vadp_shell_imgviewer_free_filelist();
                    vadp_shell_imgviewer_create_filelist();
                }
            }
        }
    }
    else
    {
        vadp_shell_imgviewer_create_filelist();
    }

    VFX_LOG(VFX_INFO, VADP_SHELLIV_FL_STATE, __LINE__, g_vadp_shell_imgviewer_cntx.fl_state);

    return (g_vadp_shell_imgviewer_cntx.fl_state == VADP_SHELLIV_FL_STATE_READY) ? VFX_TRUE : VFX_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_is_filepath_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
VfxBool vadp_shell_imgviewer_is_filepath_ready(VfxS32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path_ptr;
    VfxBool ret = VFX_FALSE;
    S32 result = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vadp_shell_imgviewer_cntx.list_handle)
    {
        path_ptr = (WCHAR*)mmi_malloc(SRV_FMGR_PATH_BUFFER_SIZE);
        result = srv_fmgr_filelist_get_filepath(
                    g_vadp_shell_imgviewer_cntx.list_handle, 
                    index,
                    path_ptr,
                    SRV_FMGR_PATH_BUFFER_SIZE);
        mmi_mfree((void*)path_ptr);

        if(result >= 0)
        {
            ret = VFX_TRUE;
        }
        else
        {
            ret = VFX_FALSE;
        }
    }    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
VfxU32 vadp_shell_imgviewer_get_folder_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 storage = (U8)vadp_shell_imgviewer_get_storage();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_vadp_shell_imgviewer_cntx.folder_buf, 0, SRV_FMGR_PATH_MAX_LEN + 1);
    if (FS_NO_ERROR == FS_GetDevStatus(storage, FS_MOUNT_STATE_ENUM))
    {
        kal_wsprintf(g_vadp_shell_imgviewer_cntx.folder_buf, "%c:\\%w", storage, FMGR_DEFAULT_FOLDER_PHOTOS);

        return (VfxU32)MMI_TRUE;
    }
    else
    {
        return (VfxU32)MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret vadp_shell_imgviewer_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_filelist_refresh_result_event_struct *refresh_evt;
    srv_fmgr_filelist_load_result_event_struct *reload_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
        case EVT_ID_SRV_FMGR_FILELIST_REFRESH_RESULT:
        {
            refresh_evt = (srv_fmgr_filelist_refresh_result_event_struct*)param;
            g_vadp_shell_imgviewer_cntx.list_handle = refresh_evt->handle;
            g_vadp_shell_imgviewer_cntx.cellcount = srv_fmgr_filelist_count(refresh_evt->handle);
            g_vadp_shell_imgviewer_cntx.fl_state = VADP_SHELLIV_FL_STATE_READY;
            VFX_LOG(VFX_INFO, VADP_SHELLIV_FL_STATE, __LINE__, g_vadp_shell_imgviewer_cntx.fl_state);

            if (g_vadp_shell_imgviewer_cntx.focus_idx > g_vadp_shell_imgviewer_cntx.cellcount - 1)
                g_vadp_shell_imgviewer_cntx.focus_idx = 0;
            
            if (g_vadp_shell_imgviewer_cntx.list_ready_cb)
            {
                g_vadp_shell_imgviewer_cntx.list_ready_cb(g_vadp_shell_imgviewer_cntx.panel_ptr);
            }
            break;
        }

        case EVT_ID_SRV_FMGR_FILELIST_LOAD_RESULT:
        {
            reload_evt = (srv_fmgr_filelist_load_result_event_struct*)param;
            g_vadp_shell_imgviewer_cntx.list_handle = reload_evt->handle;
            g_vadp_shell_imgviewer_cntx.fl_state = VADP_SHELLIV_FL_STATE_READY;
            VFX_LOG(VFX_INFO, VADP_SHELLIV_FL_STATE, __LINE__, g_vadp_shell_imgviewer_cntx.fl_state);

            if (g_vadp_shell_imgviewer_cntx.list_ready_cb)
            {
                g_vadp_shell_imgviewer_cntx.list_ready_cb(g_vadp_shell_imgviewer_cntx.panel_ptr);
            }            
            break;
        }
        
        case EVT_ID_SRV_FMGR_ASYNC_DONE:
        {   
            if (g_vadp_shell_imgviewer_cntx.delete_done_cb)
            {
                g_vadp_shell_imgviewer_cntx.delete_done_cb(g_vadp_shell_imgviewer_cntx.panel_ptr);
            }            
            break;
        }
        
        case EVT_ID_IMGVIEW_CLOSE_GID:
        {
            mmi_group_event_struct *cui_evt;

            g_vadp_shell_imgviewer_cntx.focus_idx = mmi_imgview_get_highlight_idx();
            cui_evt = (mmi_group_event_struct*)param;
            cui_imgview_close(cui_evt->sender_id);
            mmi_frm_group_close(g_vadp_shell_imgviewer_cntx.scrn_gid);
            break;
        }

        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        {
            g_vadp_shell_imgviewer_cntx.focus_idx = mmi_imgview_get_highlight_idx();
            break;
        }
        
        default:
            break;
    }

    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_create_filelist
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_shell_imgviewer_create_filelist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    S32 result = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_IMAGE(&filter);
    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_ANM);
    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_EMS);
#ifdef __MMI_IMAGE_VIEWER_EX__
    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_SVG);
#endif
#if defined(__DRM_V02__)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
#endif

    g_vadp_shell_imgviewer_cntx.filelist_buf_p = (void*)g_vadp_shell_imgviewer_filelist_buffer;

    vadp_shell_imgviewer_get_folder_path();
    
    srv_fmgr_folder_filelist_create(
        g_vadp_shell_imgviewer_cntx.folder_buf, 
        &filter,
        FS_SORT_TIME,
        g_vadp_shell_imgviewer_cntx.filelist_buf_p,
        VADP_SHELLIV_FILELIST_MEM_SIZE,
        &g_vadp_shell_imgviewer_cntx.list_handle);

    VFX_LOG(VFX_INFO, VADP_SHELLIV_REFRESH_LIST, __LINE__, g_vadp_shell_imgviewer_cntx.focus_idx);
    
    result = srv_fmgr_filelist_refresh(
                g_vadp_shell_imgviewer_cntx.list_handle, 
                NULL, 
                g_vadp_shell_imgviewer_cntx.focus_idx, 
                0, 
                vadp_shell_imgviewer_proc, 
                NULL);
    
    VFX_LOG(VFX_INFO, VADP_SHELLIV_RESULT, __LINE__, result);

    if (vadp_shell_imgviewer_check_is_valid_drv(vadp_shell_imgviewer_get_storage()))
    {
    #if defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
    #endif
    }
    
    g_vadp_shell_imgviewer_cntx.fl_state = VADP_SHELLIV_FL_STATE_REFRESHING;

    VFX_LOG(VFX_INFO, VADP_SHELLIV_FL_STATE, __LINE__, g_vadp_shell_imgviewer_cntx.fl_state);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_free_filelist
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_shell_imgviewer_free_filelist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vadp_shell_imgviewer_cntx.list_handle)
    {
        srv_fmgr_filelist_destroy(g_vadp_shell_imgviewer_cntx.list_handle);
        g_vadp_shell_imgviewer_cntx.list_handle = NULL;
    }
    g_vadp_shell_imgviewer_cntx.fl_state = VADP_SHELLIV_FL_STATE_EXIT;

    VFX_LOG(VFX_INFO, VADP_SHELLIV_FL_STATE, __LINE__, g_vadp_shell_imgviewer_cntx.fl_state);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_get_file_count
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
VfxU32 vadp_shell_imgviewer_get_file_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vadp_shell_imgviewer_cntx.list_handle)
    {
        g_vadp_shell_imgviewer_cntx.cellcount = 
            srv_fmgr_filelist_count(g_vadp_shell_imgviewer_cntx.list_handle);

        if (g_vadp_shell_imgviewer_cntx.cellcount > VADP_SHELLIV_FILECOUNT_MAX)
        {
            g_vadp_shell_imgviewer_cntx.is_over_sorting_limit = VFX_TRUE;
        }
        else
        {
            g_vadp_shell_imgviewer_cntx.is_over_sorting_limit = VFX_FALSE;
        }
    }

    return g_vadp_shell_imgviewer_cntx.cellcount;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_withdraw_file
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_shell_imgviewer_withdraw_file(VfxS32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vadp_shell_imgviewer_cntx.delete_idx = index;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_delete_file
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vadp_shell_imgviewer_delete_file_nonblocking(VfxU32 index, void* user_data, vapp_shell_imgviewer_delete_done_callback cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path_ptr;
    VfxS32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    path_ptr = (WCHAR*)mmi_malloc(SRV_FMGR_PATH_BUFFER_SIZE);
    srv_fmgr_filelist_get_filepath(
        g_vadp_shell_imgviewer_cntx.list_handle, 
        index,
        path_ptr,
        SRV_FMGR_PATH_BUFFER_SIZE);

    ret = (VfxS32)srv_fmgr_async_delete(path_ptr, 0, vadp_shell_imgviewer_proc, NULL);
    mmi_mfree((void*)path_ptr);
    g_vadp_shell_imgviewer_cntx.delete_done_cb = cb;
    g_vadp_shell_imgviewer_cntx.panel_ptr = user_data;
    g_vadp_shell_imgviewer_cntx.fl_state = VADP_SHELLIV_FL_STATE_DELETING;

    VFX_LOG(VFX_INFO, VADP_SHELLIV_FL_STATE, __LINE__, g_vadp_shell_imgviewer_cntx.fl_state);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_cache_srv_init
 * DESCRIPTION
 *  MediaWall entry function
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_shell_imgviewer_cache_srv_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *mediacache_work_buf_p = NULL;
    void *sqlite_buf_p = NULL;
    U32 sqlite_buf_size = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vadp_shell_imgviewer_cntx.cellcount > VADP_SHELLIV_FILECOUNT_MAX)
    {
        g_vadp_shell_imgviewer_cntx.is_over_sorting_limit = VFX_TRUE;
    }
    else
    {
        g_vadp_shell_imgviewer_cntx.is_over_sorting_limit = VFX_FALSE;
    }
    
    if (g_vadp_shell_imgviewer_cntx.cellcount)
    {
        /* allocate memory */
        if (g_vadp_shell_imgviewer_cntx.med_mem_buf_p == NULL)
        {
            g_vadp_shell_imgviewer_cntx.med_mem_buf_size = VADP_SHELLIV_MED_MEM_SIZE;
            media_get_ext_buffer(
                stack_get_active_module_id(),
                &g_vadp_shell_imgviewer_cntx.med_mem_buf_p,
                g_vadp_shell_imgviewer_cntx.med_mem_buf_size);
            
            MMI_ASSERT(g_vadp_shell_imgviewer_cntx.med_mem_buf_p != NULL);
        }

        g_vadp_shell_imgviewer_cntx.delete_idx = VADP_SHELLIV_FILELIST_EMPTY;
        
        if (g_vadp_shell_imgviewer_cntx.med_mem_buf_p)
        {
    #if defined(__SQLITE3_SUPPORT__)
            sqlite_buf_size = VADP_SHELLIV_SQLITE_BUFFER_SIZE;
    #else
            sqlite_buf_size = 0;
    #endif 
            mediacache_work_buf_p = g_vadp_shell_imgviewer_cntx.med_mem_buf_p;

            sqlite_buf_p = (void*)((kal_uint32)mediacache_work_buf_p + VADP_SHELLIV_CACHE_RUN_BUFFER_SIZE);
        
            g_vadp_shell_imgviewer_cntx.srv_mediacache_handle = 
                srv_mediacache_create((void*)mediacache_work_buf_p, VADP_SHELLIV_CACHE_RUN_BUFFER_SIZE);

            MMI_ASSERT(g_vadp_shell_imgviewer_cntx.srv_mediacache_handle != NULL);

            srv_mediacache_ex_define_db_io_buffer_length(VADP_SHELLIV_CELL_SIZE);

        #if defined(__MMI_IMAGE_VIEWER_EX_DB__) && defined(__SQLITE3_SUPPORT__)
            srv_mediacache_config_db(
                g_vadp_shell_imgviewer_cntx.srv_mediacache_handle, 
                (void*)sqlite_buf_p, 
                sqlite_buf_size,
                (WCHAR *)g_vadp_shell_imgviewer_cntx.folder_buf,
                (WCHAR *)L"shelliv.db"); 
        #endif

            srv_mediacache_config_level2_size(
                g_vadp_shell_imgviewer_cntx.srv_mediacache_handle, 
                VADP_SHELLIV_CELL_WIDTH,
                VADP_SHELLIV_CELL_HEIGHT);

            srv_mediacache_config_work_mode_to_filelist(
                g_vadp_shell_imgviewer_cntx.srv_mediacache_handle, 
                g_vadp_shell_imgviewer_cntx.list_handle);            
            
            srv_mediacache_add_cache(
                g_vadp_shell_imgviewer_cntx.srv_mediacache_handle, 
                SRV_MEDIACACHE_CACHE_TYPE_L2, 
                (void*)((kal_uint32)sqlite_buf_p + sqlite_buf_size), 
                VADP_SHELLIV_MED_MEM_SIZE - VADP_SHELLIV_CACHE_RUN_BUFFER_SIZE - VADP_SHELLIV_SQLITE_BUFFER_SIZE);
            
            srv_mediacache_register_engine_clip_function(g_vadp_shell_imgviewer_cntx.resize_img_cb, g_vadp_shell_imgviewer_cntx.menu_ptr);
            
            srv_mediacache_start(g_vadp_shell_imgviewer_cntx.srv_mediacache_handle, g_vadp_shell_imgviewer_cntx.focus_idx);

            if (g_vadp_shell_imgviewer_cntx.is_over_sorting_limit)
            {
                srv_mediacache_pause_decode(g_vadp_shell_imgviewer_cntx.srv_mediacache_handle);
            }

            g_vadp_shell_imgviewer_cntx.delete_idx = VADP_SHELLIV_FILELIST_EMPTY;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_cache_srv_close
 * DESCRIPTION
 *  Close service
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_shell_imgviewer_cache_srv_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void* cache_buffer_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vadp_shell_imgviewer_cntx.srv_mediacache_handle)
    {
        cache_buffer_p = (void*)((kal_uint32)g_vadp_shell_imgviewer_cntx.med_mem_buf_p + 
                                    VADP_SHELLIV_CACHE_RUN_BUFFER_SIZE + 
                                    VADP_SHELLIV_SQLITE_BUFFER_SIZE);
        srv_mediacache_stop(g_vadp_shell_imgviewer_cntx.srv_mediacache_handle);
        srv_mediacache_remove_cache(g_vadp_shell_imgviewer_cntx.srv_mediacache_handle, cache_buffer_p);

        srv_mediacache_destroy(g_vadp_shell_imgviewer_cntx.srv_mediacache_handle);
        g_vadp_shell_imgviewer_cntx.srv_mediacache_handle = NULL;
        g_vadp_shell_imgviewer_cntx.is_paused = VFX_FALSE;
    }

    if (g_vadp_shell_imgviewer_cntx.med_mem_buf_p)
    {
        media_free_ext_buffer(stack_get_active_module_id(), (void**)&g_vadp_shell_imgviewer_cntx.med_mem_buf_p);
        g_vadp_shell_imgviewer_cntx.med_mem_buf_p = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_cache_srv_pause_bgdecode
 * DESCRIPTION
 *  Pause the background decode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_shell_imgviewer_cache_srv_pause_bgdecode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_vadp_shell_imgviewer_cntx.is_over_sorting_limit && 
        g_vadp_shell_imgviewer_cntx.srv_mediacache_handle)
    {
        if (!g_vadp_shell_imgviewer_cntx.is_paused)
        {
            VFX_TRACE(("[SHELL IV] pause service\n"));
            srv_mediacache_pause_decode(g_vadp_shell_imgviewer_cntx.srv_mediacache_handle);
            g_vadp_shell_imgviewer_cntx.is_paused = VFX_TRUE;
        }
    }   
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_cache_srv_resume_bgdecode
 * DESCRIPTION
 *  Resume background decode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_shell_imgviewer_cache_srv_resume_bgdecode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_vadp_shell_imgviewer_cntx.is_over_sorting_limit && 
        g_vadp_shell_imgviewer_cntx.srv_mediacache_handle)
    {   
        if (g_vadp_shell_imgviewer_cntx.is_paused)
        {
            VFX_TRACE(("[SHELL IV] resume service\n"));
            srv_mediacache_resume_decode(g_vadp_shell_imgviewer_cntx.srv_mediacache_handle);
            g_vadp_shell_imgviewer_cntx.is_paused = VFX_FALSE;
        }
    }   
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_cache_srv_decode_callback
 * DESCRIPTION
 *  Decode callback function
 * PARAMETERS
 *  err_group       [IN]    error group
 *  err_code        [IN]    error code
 *  user_data       [IN]    user data
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_shell_imgviewer_cache_srv_decode_callback(S32 err_group,S32 err_code, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error_code = SRV_MEDIACACHE_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_ASSERT(g_vadp_shell_imgviewer_cntx.srv_mediacache_handle != NULL);

    if (err_code == SRV_MEDIACACHE_OK)
    {
        error_code = SRV_MEDIACACHE_OK;
    #if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__MM_DEBUG_MEASURE__)        
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif      
    }
    else if (err_code == SRV_MEDIACACHE_ERR_NOT_READY || 
             err_code == SRV_MEDIACACHE_ERR_NOT_ENOUGH_CACHE ||
             err_code == SRV_MEDIACACHE_ERR_DECODING)
    {
        error_code = err_code;
    }
#ifdef __DRM_SUPPORT__
    else if (err_code == DRM_RESULT_NO_PERMISSION)
    {
        error_code = VADP_SHELLIV_DRM_LOCKED;
    }
#endif    
    else
    {
        error_code = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
    }
        
    if (g_vadp_shell_imgviewer_cntx.is_over_sorting_limit)
    {
        srv_mediacache_pause_decode(g_vadp_shell_imgviewer_cntx.srv_mediacache_handle);
    }

    VFX_LOG(VFX_INFO, VADP_SHELLIV_DECODECB_RET, error_code);

    if (err_code == SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY)
    {
        return;
    }
   
    if (g_vadp_shell_imgviewer_cntx.decode_cb)
    {
        g_vadp_shell_imgviewer_cntx.decode_cb(g_vadp_shell_imgviewer_cntx.menu_ptr, (S32)user_data, error_code);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_cache_srv_get_lock_image_buffer
 * DESCRIPTION
 *  Blocking decode image & lock buffer function
 * PARAMETERS
 *  index       [IN]    file index
 *  source      [IN]    decode source type
 *  buffer      [OUT]   image bufer
 * RETURNS
 *  decode result
 *****************************************************************************/
S32 vadp_shell_imgviewer_cache_srv_get_lock_image_buffer(S32 index, srv_mediacache_image_source_enum source, void** buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_lock_img_buffer_addr_struct lock_img;
    S32 ret = SRV_MEDIACACHE_OK;
    S32 error_code = SRV_MEDIACACHE_OK;
    S32 mapped_index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lock_img.callback = NULL;
    lock_img.user_data = NULL;
    lock_img.source = source;

    if (g_vadp_shell_imgviewer_cntx.srv_mediacache_handle == NULL)
        return VADP_SHELLIV_NO_SERVICE;

    mapped_index = VADP_SHELLIV_FILELIST_MAPPED_INX(index);

    VFX_LOG(VFX_INFO, VADP_SHELLIV_DECODEIMG, index, mapped_index);
    
    if (mapped_index < 0)
        return SRV_MEDIACACHE_ERR_NOT_SUPPORT;
    
    if (g_vadp_shell_imgviewer_cntx.is_over_sorting_limit)
    {
        srv_mediacache_resume_decode(g_vadp_shell_imgviewer_cntx.srv_mediacache_handle);
    }
            
    error_code = srv_mediacache_lock_img_buffer_addr(g_vadp_shell_imgviewer_cntx.srv_mediacache_handle, mapped_index, &lock_img);

    
    if (error_code == SRV_MEDIACACHE_OK)
    {
        *buffer = lock_img.buffer;
        ret = SRV_MEDIACACHE_OK;
    }
    else if (error_code == SRV_MEDIACACHE_ERR_NOT_READY || 
             error_code == SRV_MEDIACACHE_ERR_NOT_ENOUGH_CACHE ||
             error_code == SRV_MEDIACACHE_ERR_DECODING)
    {
        ret = error_code;
    }
#ifdef __DRM_SUPPORT__
    else if (error_code == DRM_RESULT_NO_PERMISSION)
    {
        ret = VADP_SHELLIV_DRM_LOCKED;
    }
#endif      
    else if (error_code == SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY)
    {
        ret = SRV_MEDIACACHE_ERR_DECODING;
    }
    else
    {
        ret = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
    }

    if (g_vadp_shell_imgviewer_cntx.is_over_sorting_limit)
    {
        srv_mediacache_pause_decode(g_vadp_shell_imgviewer_cntx.srv_mediacache_handle);
    }
            
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_cache_srv_get_lock_image_buffer_nonblocking
 * DESCRIPTION
 *  Non-blocking decode image & lock buffer function
 * PARAMETERS
 *  user_data   [IN]    user data
 *  index       [IN]    file index
 *  callback    [OUT]   decode callback function
 * RETURNS
 *  decode result
 *****************************************************************************/
S32 vadp_shell_imgviewer_cache_srv_get_lock_image_buffer_nonblocking(
    void *user_data, 
    S32 index,
    vapp_shell_imgviewer_decode_callback callback, void** buffer_pp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_lock_img_buffer_addr_struct lock_img;
    S32 ret;
    S32 error_code = SRV_MEDIACACHE_OK;
    S32 mapped_index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lock_img.callback = vadp_shell_imgviewer_cache_srv_decode_callback;
    lock_img.user_data = (void*)index;
    lock_img.source = SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE;

    g_vadp_shell_imgviewer_cntx.menu_ptr = user_data;
    g_vadp_shell_imgviewer_cntx.decode_cb = callback;

    if (g_vadp_shell_imgviewer_cntx.srv_mediacache_handle == NULL)
        return VADP_SHELLIV_NO_SERVICE;

    mapped_index = VADP_SHELLIV_FILELIST_MAPPED_INX(index);

    VFX_LOG(VFX_INFO, VADP_SHELLIV_NBDECODEIMG, index, mapped_index);
        
    if (mapped_index < 0)
        return SRV_MEDIACACHE_ERR_NOT_SUPPORT;
    
    if (g_vadp_shell_imgviewer_cntx.is_over_sorting_limit)
    {
        srv_mediacache_resume_decode(g_vadp_shell_imgviewer_cntx.srv_mediacache_handle);
    }
            
    error_code = srv_mediacache_lock_img_buffer_addr(
                    g_vadp_shell_imgviewer_cntx.srv_mediacache_handle, 
                    mapped_index, 
                    &lock_img);
    
    if (error_code == SRV_MEDIACACHE_OK)
    {
        *buffer_pp = lock_img.buffer;
        ret = SRV_MEDIACACHE_OK;
    }
    else if (error_code == SRV_MEDIACACHE_ERR_DECODING)
    {
        ret = SRV_MEDIACACHE_ERR_DECODING;
        #if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
        #endif
    }
#ifdef __DRM_SUPPORT__
    else if (error_code == DRM_RESULT_NO_PERMISSION)
    {
        ret = VADP_SHELLIV_DRM_LOCKED;
    }
#endif
    else if (error_code == SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY)
    {
        ret = SRV_MEDIACACHE_ERR_DECODING;
    }
    else
    {
        ret = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
    }
            
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_cache_srv_free_image_buffer
 * DESCRIPTION
 *  Release the image buffer
 * PARAMETERS
 *  buffer      [IN]    image buffer
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_shell_imgviewer_cache_srv_free_image_buffer(void* buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vadp_shell_imgviewer_cntx.srv_mediacache_handle == NULL)
        return;
    
    srv_mediacache_unlock_img_buffer(g_vadp_shell_imgviewer_cntx.srv_mediacache_handle, buffer);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_cache_srv_get_image_info
 * DESCRIPTION
 *  Release the image buffer
 * PARAMETERS
 *  index       [IN]    file index
 *  buffer      [IN]    image buffer
 * RETURNS
 *  void
 *****************************************************************************/
S32 vadp_shell_imgviewer_cache_srv_get_image_info(S32 index, S32 *resized_width, S32 *resized_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    srv_mediacache_get_img_info_struct img_info;
    S32 mapped_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vadp_shell_imgviewer_cntx.srv_mediacache_handle == NULL)
        return VADP_SHELLIV_NO_SERVICE;

    mapped_index = VADP_SHELLIV_FILELIST_MAPPED_INX(index);
    
    ret = srv_mediacache_get_image_info(
        g_vadp_shell_imgviewer_cntx.srv_mediacache_handle, 
        mapped_index, &img_info);

    if (ret >= SRV_MEDIACACHE_OK)
    {
        *resized_width = img_info.resized_width;
        *resized_height = img_info.resized_height;        
    }
    else
    {
        *resized_width = 0;
        *resized_height = 0;

        MMI_ASSERT(0);
    }
    return ret;
    
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_cache_srv_register_clip_cb
 * DESCRIPTION
 *  Release the image buffer
 * PARAMETERS
 *  index       [IN]    file index
 *  buffer      [IN]    image buffer
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_shell_imgviewer_cache_srv_register_clip_cb(void *user_data, srv_mediacache_engine_clip cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vadp_shell_imgviewer_cntx.menu_ptr = user_data;
    g_vadp_shell_imgviewer_cntx.resize_img_cb = cb;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_fit_img
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_shell_imgviewer_fit_img(
    VfxS32 dest_w, 
    VfxS32 dest_h, 
    VfxS32 source_w,
    VfxS32 source_h, 
    VfxS32* resized_offset_x, 
    VfxS32* resized_offset_y, 
    VfxS32* resized_width, 
    VfxS32* resized_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_util_fit_box(
        GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
        dest_w,
        dest_h,
        source_w,
        source_h,
        resized_offset_x,
        resized_offset_y,
        resized_width,
        resized_height);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_get_image_path_by_index
 * DESCRIPTION
 *  Release the image buffer
 * PARAMETERS
 *  index       [IN]    file index
 *  buffer      [IN]    image buffer
 * RETURNS
 *  void
 *****************************************************************************/
VfxBool vadp_shell_imgviewer_get_image_path_by_index(VfxS32 index, VfxWChar *buffer_ptr, VfxU32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(buffer_ptr, 0, length);
    if (g_vadp_shell_imgviewer_cntx.list_handle)
    {
        result = srv_fmgr_filelist_get_filepath(
                    g_vadp_shell_imgviewer_cntx.list_handle, 
                    index,
                    (WCHAR*)buffer_ptr,
                    length);
        
        if (result >= 0)
            return VFX_TRUE;
        else
            return VFX_FALSE;
    }
    else
        return VFX_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_enter_kernal_app
 * DESCRIPTION
 *  Enter kernal app to view the focus image
 * PARAMETERS
 *  index       [IN]    file index
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_shell_imgviewer_enter_kernal_app(VfxS32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID imgview_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__MM_DEBUG_MEASURE__)    
/* under construction !*/
#endif    
    g_vadp_shell_imgviewer_cntx.scrn_gid = 
        mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, vadp_shell_imgviewer_proc, NULL); 
    
    mmi_frm_group_enter(g_vadp_shell_imgviewer_cntx.scrn_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);    

    if ((imgview_gid = cui_imgview_create(g_vadp_shell_imgviewer_cntx.scrn_gid)) != GRP_ID_INVALID)
    {       
        cui_imgview_set_mode_filelist(imgview_gid, g_vadp_shell_imgviewer_cntx.list_handle, index);
        cui_imgview_set_app_id(imgview_gid, g_vadp_shell_imgviewer_cntx.scrn_gid);
        cui_imgview_set_ui_direction(imgview_gid, CUI_IMGVIEW_UI_DIRECTION_VERTICAL);
        cui_imgview_set_display_cap(imgview_gid, CUI_IMGVIEW_CAP_ALL, MMI_TRUE);  
        cui_imgview_run(imgview_gid);
    }
    else
    {
        mmi_frm_group_close(g_vadp_shell_imgviewer_cntx.scrn_gid);
    }    
#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__MM_DEBUG_MEASURE__)    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_check_is_valid_drv
 * DESCRIPTION
 *  check if the drv is valid
 * PARAMETERS
 *  drv_letter      [IN]    driver letter
 * RETURNS
 *  VFX_TRUE
 *  VFX_FALSE
 *****************************************************************************/
VfxBool vadp_shell_imgviewer_check_is_valid_drv(VfxU8 drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_NO_ERROR == FS_GetDevStatus(drv_letter, FS_MOUNT_STATE_ENUM))
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_cache_srv_filelist_refresh_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 vadp_shell_imgviewer_cache_srv_filelist_refresh_cb(srv_mediacache_events_enum evt, void* param, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;
    srv_mediacache_evt_get_filename_err_struct *err;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    err = (srv_mediacache_evt_get_filename_err_struct*)param;

    VFX_LOG(VFX_INFO, VADP_SHELLIV_RELOAD_FILELIST, err->error_code, err->file_index);
    VFX_LOG(VFX_INFO, VADP_SHELLIV_FL_STATE, __LINE__, g_vadp_shell_imgviewer_cntx.fl_state);
    
    if (evt == SRV_MEDIACACHE_EVENTS_GET_FILENAME_ERR && 
        err->error_code == SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY)
    {
        if (g_vadp_shell_imgviewer_cntx.refreshing_list_cb)
            g_vadp_shell_imgviewer_cntx.refreshing_list_cb(user_data);

        if (g_vadp_shell_imgviewer_cntx.fl_state != VADP_SHELLIV_FL_STATE_REFRESHING)
        {
            result = srv_fmgr_filelist_load_file(
                        g_vadp_shell_imgviewer_cntx.list_handle,
                        err->file_index,
                        vadp_shell_imgviewer_proc, 
                        NULL);

            VFX_LOG(VFX_INFO, VADP_SHELLIV_RESULT, __LINE__, result);

            if (vadp_shell_imgviewer_check_is_valid_drv(vadp_shell_imgviewer_get_storage()))
            {
            #if defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
            #endif
            }
        }
        g_vadp_shell_imgviewer_cntx.fl_state = VADP_SHELLIV_FL_STATE_REFRESHING;
    }

    VFX_LOG(VFX_INFO, VADP_SHELLIV_FL_STATE, __LINE__, g_vadp_shell_imgviewer_cntx.fl_state);

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  vadp_shell_imgviewer_cache_srv_register_event_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_shell_imgviewer_cache_srv_register_filelist_refresh_cb(void *user_data, vapp_shell_imgviewer_refreshing_filelist_callback cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    g_vadp_shell_imgviewer_cntx.refreshing_list_cb = cb;
    
    srv_mediacache_register_events_cb(
        g_vadp_shell_imgviewer_cntx.srv_mediacache_handle,
        vadp_shell_imgviewer_cache_srv_filelist_refresh_cb,
        user_data);
}


#endif /* __MMI_VUI_SHELL_IMAGE_VIEWER__ */
