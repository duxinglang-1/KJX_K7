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
 *  vadp_p2v_mediawall.cpp
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
 *      Pluto APP ---> p2v adaptor ---> Venus APP
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/ 
#include "MMI_features.h"
#ifdef __MMI_VUI_MEDIAWALL__
#include "MediaWall\vadp_mediawall.h"
#include "MediaWall\vapp_mediawall.h"
#include "vfx_datatype.h"
#include "vrt_system.h"
#include "vfx_app_cat_scr.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_cpp_base.h"
#include "trc/vadp_app_trc.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
#include "MediaCacheSrvGprot.h"
#include "Gdi_include.h"
#include "gui_typedef.h"
#include "ScreenRotationGprot.h"
#ifdef __DRM_SUPPORT__
#include "drm_def.h"
#include "drm_gprot.h"
#endif
#include "MMIDataType.h"
#include "wgui_categories_list.h"
#include "wgui.h"
#include "mdi_datatype.h"
#include "kal_general_types.h"
#include "FileMgrSrvGProt.h"
#include "string.h"
#include "lcd_sw_inc.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_media_app_trc.h"
#include "lcd_sw_rnd.h"
#include "MediaCacheSrvMem.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_rp_file_type_def.h"
#include "Unicodexdcl.h"

#ifdef MOTION_SENSOR_SUPPORT
#include "SensorSrvGport.h"
#endif
#ifdef __MMI_SCREEN_SWITCH_EFFECT__    
#include "gui_effect_oem.h"
#endif

extern void mmi_imgview_enter_view_screen(void);
extern void mmi_imgview_set_rotate(U16 rotate_value);
extern FuncPtr get_softkey_function(MMI_key_event_type k, WGUI_SOFTKEY_ENUM key);
#ifdef __cplusplus
}
#endif

/**********************************************************************
 * Structure Definitions:
 **********************************************************************/

typedef struct
{
    VappMediaWallScr *userdata;
    vapp_get_file_info_callback get_fileinfo_cb;
    vapp_get_file_path_callback get_filepath_cb;
    vapp_mediawall_memory_release_callback mem_release_cb;
    vapp_mediawall_memory_allocate_callback mem_allocate_cb;
    vapp_mediawall_decode_callback decode_cb;
    vadp_mediawall_view_info_struct view_info;
    void *app_mem_buf_p;
    void *med_mem_buf_p;
    void *scr_mem_buf_p;
    U32 app_mem_buf_size;
    U32 med_mem_buf_size;
    U32 scr_mem_buf_size;
    void *srv_mediacache_run_buf;
    srv_handle srv_mediacache_handle;
    VfxBool is_rotating;
    VfxBool is_over_sorting_limit;
    VfxBool is_paused;
    VfxBool is_lsk_on;
    mdi_handle tilt_handle;
    void*  menu_ptr;
} vadp_mediawall_context;

/**********************************************************************
 * Global variables:
 **********************************************************************/
//extern void (*MMI_matrix_highlight_handler) (S32 index);
static vadp_mediawall_context g_vadp_mediawall_cntx;

/*****************************************************************************
* Local Function 
*****************************************************************************/
void vadp_mediawall_exit(void);
void vadp_mediawall_entry(vadp_mediawall_init_struct init);
S32 vadp_mediawall_srv_get_filepath_cb(S32 index, WCHAR *buffer, U32 length, void *user_data);
void vadp_mediawall_csk_dummy_hdlr(void);
#ifdef MOTION_SENSOR_SUPPORT
void vadp_mediawall_motion_tilt_hdlr(srv_sensor_type_enum sensor_type,
                     void *sensor_data, void *user_data);

#endif /* MOTION_SENSOR_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  vapp_mediawall_cat
 * DESCRIPTION
 *  MediaWall entry function
 * PARAMETERS
 *  title               [IN]    screen title
 *  title_icon          [IN]    title icon
 *  left_softkey        [IN]    left softkey string ID
 *  left_softkey_icon   [IN]    left softkey icon ID
 *  right_softkey       [IN]    right softkey string ID
 *  right_softkey_icon  [IN]    right softkey icon ID
 *  num_of_items        [IN]    file count
 *  highlighted_item    [IN]    highlight index
 *  display_index       [IN]    top-left item index
 *  folder_path         [IN]    folder path
 *  folder_path_length  [IN]    the length of folder path
 *  get_fileinfo_cb     [IN]    file info callback function 
 *  get_filepath_cb     [IN]    file path callback function
 *  history_buffer      [IN]    gui buffer
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_mediawall_cat(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U16 num_of_items,
        S32 highlighted_item,
        S32 display_index,
        S8 *folder_path,
        U32 folder_path_length,
        vapp_get_file_info_callback get_fileinfo_cb,
        vapp_get_file_path_callback get_filepath_cb,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vadp_mediawall_init_struct init;
    S8 curr_folder_path[SRV_FMGR_PATH_BUFFER_SIZE];
    U32 work_buf_num = 0;
    U32 total_cache_buf_size = 0;
    U32 per_cache_size = 0;
    U32 mediacache_work_buf_size = 0;
    U32 sqlite_buf_size = 0;
    vadp_mediawall_memory_struct mem_info;
    struct{
        char *buf;
        S32 size;
    }buf[2], *pbuf= NULL;
#ifdef MOTION_SENSOR_SUPPORT
    //modify for sensor split
    srv_sensor_motion_direct_cfg_struct sensitive;
#endif    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VAPP_MEDIAWALL_START_LOGGING("BEG");
    
    memset(curr_folder_path, 0, SRV_FMGR_PATH_BUFFER_SIZE);
    memcpy(curr_folder_path, folder_path, vfxMin((int)SRV_FMGR_PATH_BUFFER_SIZE,(int)folder_path_length));

    init.cellcount = num_of_items;
    init.cell_height = VappMediaWallMenu::CELL_WIDTH;
    init.cell_width = VappMediaWallMenu::CELL_HEIGHT;
    init.cell_inner_x = 8;
    init.cell_inner_y = 8;
    init.cellnum_per_row = LCD_WIDTH/init.cell_height;
    init.highlight_idx = highlighted_item;
    init.title_string_id = title;
    if (left_softkey)
    {
        init.is_lsk_on = MMI_TRUE;
        g_vadp_mediawall_cntx.is_lsk_on = VFX_TRUE;
    }
    else
    {
        init.is_lsk_on = MMI_FALSE;
        g_vadp_mediawall_cntx.is_lsk_on = VFX_FALSE;
    }
    
    g_vadp_mediawall_cntx.get_fileinfo_cb = get_fileinfo_cb;
    g_vadp_mediawall_cntx.get_filepath_cb = get_filepath_cb;

    if (init.cellcount > FS_SORT_MAX_ENTRY)
    {
        g_vadp_mediawall_cntx.is_over_sorting_limit = VFX_TRUE;
    }
    else
    {
        g_vadp_mediawall_cntx.is_over_sorting_limit = VFX_FALSE;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, VADP_MEDIAWALL_FS_LIMIT, g_vadp_mediawall_cntx.is_over_sorting_limit);
    
    if (init.cellcount && !g_vadp_mediawall_cntx.is_rotating)
    {
        if (g_vadp_mediawall_cntx.mem_allocate_cb)
        {
            g_vadp_mediawall_cntx.mem_allocate_cb(&mem_info);
            vapp_mediawall_set_memory(mem_info);
        }
        
        if (g_vadp_mediawall_cntx.med_mem_buf_p && g_vadp_mediawall_cntx.app_mem_buf_p)
        {
    #if defined(__MMI_IMAGE_VIEWER_EX_DB__) && defined(__SQLITE3_SUPPORT__)
            sqlite_buf_size = SRV_MEDIACACHE_SQLITE_DB_BUF_SIZE_DEFAULT;
    #else
            sqlite_buf_size = 0;
    #endif 
            per_cache_size = (init.cell_width- init.cell_inner_x) * (init.cell_height - init.cell_inner_y) * (GDI_MAINLCD_BIT_PER_PIXEL >> 3);
            total_cache_buf_size =  g_vadp_mediawall_cntx.app_mem_buf_size + 
                            g_vadp_mediawall_cntx.med_mem_buf_size - 
                            sqlite_buf_size -       
                            SRV_MEDIACACHE_RUN_BUF_BASE;

            work_buf_num = total_cache_buf_size/(per_cache_size + (SRV_MEDIACACHE_RUN_BUF_SIZE(work_buf_num) - SRV_MEDIACACHE_RUN_BUF_BASE));
            mediacache_work_buf_size = SRV_MEDIACACHE_RUN_BUF_SIZE(work_buf_num);
            buf[0].buf = (char*)g_vadp_mediawall_cntx.app_mem_buf_p;
            buf[0].size = g_vadp_mediawall_cntx.app_mem_buf_size;
            buf[1].buf = (char*)g_vadp_mediawall_cntx.med_mem_buf_p;
            buf[1].size = g_vadp_mediawall_cntx.med_mem_buf_size;

            if(buf[0].size > mediacache_work_buf_size)
                pbuf = &buf[0];
            else if(buf[1].size > mediacache_work_buf_size)
                pbuf = &buf[1];
            else{
                //assert
                }
            g_vadp_mediawall_cntx.srv_mediacache_handle = 
                srv_mediacache_create(pbuf->buf, SRV_MEDIACACHE_RUN_BUF_SIZE(work_buf_num));
            pbuf->size -= mediacache_work_buf_size;
            pbuf->buf += mediacache_work_buf_size;
        #if defined(__MMI_IMAGE_VIEWER_EX_DB__) && defined(__SQLITE3_SUPPORT__)
        
            if(buf[0].size > sqlite_buf_size)
                pbuf = &buf[0];
            else if(buf[1].size > sqlite_buf_size)
                pbuf = &buf[1];
            else{
                //assert
                }
            srv_mediacache_config_db(
                g_vadp_mediawall_cntx.srv_mediacache_handle, 
                pbuf->buf, 
                sqlite_buf_size,
                (WCHAR *)curr_folder_path,(WCHAR *)L"mediawall.db"); 
            
            pbuf->size -= sqlite_buf_size;
            pbuf->buf += sqlite_buf_size;
        #endif

            srv_mediacache_config_level2_size(
                g_vadp_mediawall_cntx.srv_mediacache_handle, 
                init.cell_width - init.cell_inner_x,
                init.cell_height - init.cell_inner_y);
        
            srv_mediacache_config_work_mode_to_prefetch_func(
                g_vadp_mediawall_cntx.srv_mediacache_handle, 
                init.cellcount, 
                vadp_mediawall_srv_get_filepath_cb);

            srv_mediacache_add_cache(
                g_vadp_mediawall_cntx.srv_mediacache_handle, 
                SRV_MEDIACACHE_CACHE_TYPE_L2, 
                buf[0].buf, 
                buf[0].size);

            srv_mediacache_add_cache(
                g_vadp_mediawall_cntx.srv_mediacache_handle, 
                SRV_MEDIACACHE_CACHE_TYPE_L2, 
                buf[1].buf, 
                buf[1].size);
            
            VAPP_MEDIAWALL_START_LOGGING("MST");
            srv_mediacache_start(g_vadp_mediawall_cntx.srv_mediacache_handle, init.highlight_idx);
            VAPP_MEDIAWALL_STOP_LOGGING("MST");

            if (g_vadp_mediawall_cntx.is_over_sorting_limit)
            {
                srv_mediacache_pause_decode(g_vadp_mediawall_cntx.srv_mediacache_handle);
            }
        }
    }
#if !defined(__MMI_MAINLCD_320X240__)
#ifdef MOTION_SENSOR_SUPPORT
    sensitive.angle_threshold = 30;
    g_vadp_mediawall_cntx.tilt_handle = -1;
    g_vadp_mediawall_cntx.tilt_handle = srv_sensor_start_listen(SRV_SENSOR_MOTION_DIRECT,
                  &sensitive, vadp_mediawall_motion_tilt_hdlr ,NULL);
    
#endif
#endif /* !defined(__MMI_MAINLCD_320X240__) */
    if (g_vadp_mediawall_cntx.is_rotating)
        g_vadp_mediawall_cntx.is_rotating = VFX_FALSE;
    
    vadp_mediawall_entry(init);
#if !(defined(MOTION_SENSOR_SUPPORT) && defined(__MTK_TARGET__))
    SetKeyHandler(vadp_mediawall_csk_dummy_hdlr, KEY_ENTER, KEY_EVENT_UP);
    SetKeyHandler(vadp_mediawall_csk_dummy_hdlr, KEY_ENTER, KEY_EVENT_DOWN);
#endif    
    ExitCategoryFunction = vadp_mediawall_exit;
    VAPP_MEDIAWALL_STOP_LOGGING("BEG");
}


/*****************************************************************************
 * FUNCTION
 *  vapp_mediawall_set_softkey
 * DESCRIPTION
 *  MediaWall set softkey function
 * PARAMETERS
 *  type        [IN]        key type
 *  str_id      [IN]        string ID
 *  icon_id     [IN]        icon ID
 * RETURNS
 *  MMI_TRUE    Success
 *  MMI_FALSE   Failure
 *****************************************************************************/
MMI_BOOL vapp_mediawall_set_softkey(U16 type, U16 str_id, U16 icon_id)
{
    if (g_vadp_mediawall_cntx.userdata)
    {
        if (type == MMI_LEFT_SOFTKEY)
        {
            g_vadp_mediawall_cntx.userdata->changeLsk((VfxU16) str_id);

            if (str_id)
            {
                g_vadp_mediawall_cntx.is_lsk_on = VFX_TRUE;
            }
            else
            {
                g_vadp_mediawall_cntx.is_lsk_on = VFX_FALSE;
            }
        }
        
        return MMI_TRUE;
    }   
    else
        return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_mediawall_vcat_get_view_info
 * DESCRIPTION
 *  Get the current MediaWall information
 * PARAMETERS
 *  view_info       [OUT]        info
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_mediawall_vcat_get_view_info(vadp_mediawall_view_info_struct *view_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vadp_mediawall_cntx.userdata)
    {
        g_vadp_mediawall_cntx.view_info.highlight_index = g_vadp_mediawall_cntx.userdata->getHighLightIndex();
        g_vadp_mediawall_cntx.view_info.display_index = g_vadp_mediawall_cntx.userdata->getDisplayIndex();
    }

    view_info->display_index = g_vadp_mediawall_cntx.view_info.display_index;
    view_info->highlight_index = g_vadp_mediawall_cntx.view_info.highlight_index;
    view_info->current_view_count = 25;
}


#ifdef MOTION_SENSOR_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  vadp_mediawall_motion_tilt_hdlr
 * DESCRIPTION
 *  tilt motin handler
 * PARAMETERS
 *  direction   [IN]
 *  action      [IN]
 *  detail      [IN]
 *  user data   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_mediawall_motion_tilt_hdlr(srv_sensor_type_enum sensor_type, void *sensor_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sensor_motion_direct_enum direction;
    srv_sensor_motion_direct_struct *p_direct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_direct = (srv_sensor_motion_direct_struct *)sensor_data;

    direction = p_direct->direct;

    VFX_LOG(VFX_INFO, VADP_MEDIAWALL_MOTION_TILT, direction);
    
    switch(direction)
    {
        case SRV_SENSOR_MOTION_ANGLE_GX180:
        {
            /*horizontal*/
            if(VappMediaWallScr::getViewMode() == VappMediaWallScr::VIEW_PORTRAIT)
            {
                if (g_vadp_mediawall_cntx.userdata)
                {
                    g_vadp_mediawall_cntx.userdata->setRotate();
                }
            }
            break;
        }

        case SRV_SENSOR_MOTION_ANGLE_GY180:
        {
            /*vertical*/
            if(VappMediaWallScr::getViewMode() == VappMediaWallScr::VIEW_LANDSCAPE)
            {
                if (g_vadp_mediawall_cntx.userdata)
                {
                    g_vadp_mediawall_cntx.userdata->setRotate();
                }               
            }
            break;
        }

        default:
        {
            break;
        }
    }
}
#endif /* MOTION_SENSOR_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  vadp_mediawall_entry
 * DESCRIPTION
 *  Venus MediaWall entry function
 * PARAMETERS
 *  init        [IN]    initial setting
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_mediawall_entry(vadp_mediawall_init_struct init)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (VappMediaWallScr::getViewMode() == VappMediaWallScr::VIEW_LANDSCAPE)
    {
        vrt_sys_set_screen_rotation(VRT_SYS_SCREEN_ROTATE_270);
    }
    else
    {
        vrt_sys_set_screen_rotation(VRT_SYS_SCREEN_ROTATE_0);
    }
    VAPP_MEDIAWALL_START_LOGGING("SST");
    // initalize app category
    VfxAppCatScr::initalize();

    VFX_OBJ_CREATE_EX(
        g_vadp_mediawall_cntx.userdata,
        VappMediaWallScr, 
        VfxAppCatScr::getContext(), 
        (init));    /* constructor parameters */
    VAPP_MEDIAWALL_STOP_LOGGING("SST");
}


/*****************************************************************************
 * FUNCTION
 *  vadp_mediawall_notify_release_mem
 * DESCRIPTION
 *  Notify the caller to release memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_mediawall_notify_release_mem(void)
{
    if (g_vadp_mediawall_cntx.app_mem_buf_p || g_vadp_mediawall_cntx.med_mem_buf_p)
    {
        if (g_vadp_mediawall_cntx.mem_release_cb)
        {
            g_vadp_mediawall_cntx.mem_release_cb();
        }
        
        g_vadp_mediawall_cntx.app_mem_buf_p = NULL;
        g_vadp_mediawall_cntx.app_mem_buf_size = 0;
        g_vadp_mediawall_cntx.med_mem_buf_p = NULL;
        g_vadp_mediawall_cntx.med_mem_buf_size = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_mediawall_exit
 * DESCRIPTION
 *  MediaWall exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_mediawall_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VAPP_MEDIAWALL_START_LOGGING("END");
#ifdef MOTION_SENSOR_SUPPORT
    if(g_vadp_mediawall_cntx.tilt_handle >= 0)
    {
        srv_sensor_stop_listen(g_vadp_mediawall_cntx.tilt_handle);
        g_vadp_mediawall_cntx.tilt_handle = -1 ;
    }
#endif /* MOTION_SENSOR_SUPPORT */

    g_vadp_mediawall_cntx.view_info.highlight_index = g_vadp_mediawall_cntx.userdata->getHighLightIndex();
    g_vadp_mediawall_cntx.view_info.display_index = g_vadp_mediawall_cntx.userdata->getDisplayIndex();
        
    VAPP_MEDIAWALL_START_LOGGING("SEN");
    VFX_OBJ_CLOSE(g_vadp_mediawall_cntx.userdata);
    g_vadp_mediawall_cntx.userdata = NULL;
    
    VfxAppCatScr::deinitalize();
    VAPP_MEDIAWALL_STOP_LOGGING("SEN");

    if (!g_vadp_mediawall_cntx.is_rotating)
    {
        if (g_vadp_mediawall_cntx.srv_mediacache_handle)
        {
            srv_mediacache_stop(g_vadp_mediawall_cntx.srv_mediacache_handle);
            srv_mediacache_remove_cache(g_vadp_mediawall_cntx.srv_mediacache_handle, g_vadp_mediawall_cntx.app_mem_buf_p);

            srv_mediacache_destroy(g_vadp_mediawall_cntx.srv_mediacache_handle);
            g_vadp_mediawall_cntx.srv_mediacache_handle = NULL;
            g_vadp_mediawall_cntx.is_paused = VFX_FALSE;
        }
        vadp_mediawall_notify_release_mem();
    }
    VAPP_MEDIAWALL_STOP_LOGGING("END");
}


/*****************************************************************************
 * FUNCTION
 *  vadp_mediawall_set_highlight
 * DESCRIPTION
 *  Notify plutommi app to set highlight
 * PARAMETERS
 *  value   [IN]    highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_mediawall_set_highlight(VfxS32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_matrix_highlight_handler((S32)value);       
}


/*****************************************************************************
 * FUNCTION
 *  vadp_mediawall_lsk_up
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_mediawall_lsk_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vapp_mediawall_get_direction() == VADP_MEDIAWALL_LANDSCAPE)
    {
        mmi_imgview_set_rotate(TRUE);
        #ifdef __MMI_SCREEN_ROTATE__
        mmi_frm_enable_clear_rotated_screen(MMI_FALSE);
        #endif
    }
    else
        mmi_imgview_set_rotate(FALSE);
    
    (get_softkey_function(KEY_EVENT_UP,MMI_LEFT_SOFTKEY))();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_mediawall_rsk_up
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_mediawall_rsk_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    (get_softkey_function(KEY_EVENT_UP,MMI_RIGHT_SOFTKEY))();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_mediawall_csk_dummy_hdlr
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_mediawall_csk_dummy_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  vadp_mediawall_srv_get_filepath_cb
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  index       [IN]    file index
 *  buffer      [OUT]   file path buffer
 *  length      [IN]    file path buffer length
 *  user_data   [IN]    user data
 * RETURNS
 *  MMI_TRUE    Success
 *  MMI_FALSE   Failure   
 *****************************************************************************/
S32 vadp_mediawall_srv_get_filepath_cb(S32 index, WCHAR *buffer, U32 length, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vadp_mediawall_cntx.get_filepath_cb == NULL)
        return MMI_FALSE;

    ret = g_vadp_mediawall_cntx.get_filepath_cb(index, (S8*)buffer, (S32)length);
#ifdef __DRM_SUPPORT__
    if(ret >= 0)
    {
        ret = srv_fmgr_types_find_type_by_filepath(buffer);
        if(ret >= 0)
        {
            if (DRM_get_object_method(NULL, (kal_wchar*)buffer) != DRM_METHOD_NONE)
            {
                if(!DRM_validate_permission(0, buffer, DRM_PERMISSION_DISPLAY))
                    ret = VADP_MEDIAWALL_DRM_LOCKED;
            }
            else
            {
                ret = 0;
            }
        }
    }
#endif    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_mediawall_srv_get_filename
 * DESCRIPTION
 *  Get file name
 * PARAMETERS
 *  index       [IN]    file index
 *  buffer      [OUT]   file name buffer
 *  length      [IN]    buffer length
 * RETURNS
 *  MMI_TRUE    Success
 *  MMI_FALSE   Failure 
 *****************************************************************************/
MMI_BOOL vadp_mediawall_srv_get_filename(VfxS32 index, void *buffer, VfxU32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vapp_mediawall_fmgr_file_data_struct file_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vadp_mediawall_cntx.get_fileinfo_cb == NULL)
        return MMI_FALSE;

    g_vadp_mediawall_cntx.get_fileinfo_cb((S32)index, TRUE, &file_info);

    mmi_ucs2ncpy((S8*)buffer , (S8*)file_info.file_name, vfxMin((int)(SRV_FMGR_PATH_MAX_FILE_NAME_LEN+1)*2, (int)length));

    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  vadp_mediawall_srv_decode_callback
 * DESCRIPTION
 *  Decode callback function
 * PARAMETERS
 *  err_group       [IN]    error group
 *  err_code        [IN]    error code
 *  user_data       [IN]    user data
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_mediawall_srv_decode_callback(S32 err_group,S32 err_code, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error_code = SRV_MEDIACACHE_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (err_code == SRV_MEDIACACHE_OK)
    {
        error_code = SRV_MEDIACACHE_OK;
    }
    else if (err_code == SRV_MEDIACACHE_ERR_NOT_READY || 
             err_code == SRV_MEDIACACHE_ERR_NOT_ENOUGH_CACHE ||
             err_code == SRV_MEDIACACHE_ERR_DECODING ||
             err_code == VADP_MEDIAWALL_DRM_LOCKED ||
             err_code == SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY)
    {
        error_code = err_code;
    }
    else
    {
        error_code = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
    }
        
    if (g_vadp_mediawall_cntx.is_over_sorting_limit)
    {
        srv_mediacache_pause_decode(g_vadp_mediawall_cntx.srv_mediacache_handle);
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, VADP_MEDIAWALL_DECODE_CALLBACK, (S32)user_data, error_code);

    if (error_code == SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY)
    {
        return;
    }

    if (g_vadp_mediawall_cntx.decode_cb)
    {
        g_vadp_mediawall_cntx.decode_cb(g_vadp_mediawall_cntx.menu_ptr, (S32)user_data, error_code);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_mediawall_srv_get_lock_image_buffer
 * DESCRIPTION
 *  Blocking decode image & lock buffer function
 * PARAMETERS
 *  index       [IN]    file index
 *  source      [IN]    decode source type
 *  buffer      [OUT]   image bufer
 * RETURNS
 *  decode result
 *****************************************************************************/
S32 vadp_mediawall_srv_get_lock_image_buffer(S32 index, srv_mediacache_image_source_enum source, void** buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_lock_img_buffer_addr_struct lock_img;
    S32 ret = SRV_MEDIACACHE_OK;
    S32 error_code = SRV_MEDIACACHE_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lock_img.callback = NULL;
    lock_img.user_data = NULL;
    lock_img.source = source;

    if (g_vadp_mediawall_cntx.srv_mediacache_handle == NULL)
        return VADP_MEDIAWALL_NO_SERVICE;
    
    if (g_vadp_mediawall_cntx.is_over_sorting_limit)
    {
        srv_mediacache_resume_decode(g_vadp_mediawall_cntx.srv_mediacache_handle);
    }
            
    error_code = srv_mediacache_lock_img_buffer_addr(g_vadp_mediawall_cntx.srv_mediacache_handle, index, &lock_img);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, VADP_MEDIAWALL_BLOCKING_DECODE, index, lock_img.buffer, error_code);
    
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
    else if (error_code == VADP_MEDIAWALL_DRM_LOCKED)
    {
        ret = error_code;
    }      
    else if (error_code == SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY)
    {
        ret = SRV_MEDIACACHE_ERR_DECODING;
    }
    else
    {
        ret = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
    }

    if (g_vadp_mediawall_cntx.is_over_sorting_limit)
    {
        srv_mediacache_pause_decode(g_vadp_mediawall_cntx.srv_mediacache_handle);
    }
            
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_mediawall_srv_get_lock_image_buffer_nonblocking
 * DESCRIPTION
 *  Non-blocking decode image & lock buffer function
 * PARAMETERS
 *  user_data   [IN]    user data
 *  index       [IN]    file index
 *  callback    [OUT]   decode callback function
 * RETURNS
 *  decode result
 *****************************************************************************/
S32 vadp_mediawall_srv_get_lock_image_buffer_nonblocking(
    void *user_data, 
    S32 index,
    vapp_mediawall_decode_callback callback, void** buffer_pp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_lock_img_buffer_addr_struct lock_img;
    S32 ret;
    S32 error_code = SRV_MEDIACACHE_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lock_img.callback = vadp_mediawall_srv_decode_callback;
    lock_img.user_data = (void*)index;
    lock_img.source = SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE;

    g_vadp_mediawall_cntx.menu_ptr = user_data;
    g_vadp_mediawall_cntx.decode_cb = callback;

    if (g_vadp_mediawall_cntx.srv_mediacache_handle == NULL)
        return VADP_MEDIAWALL_NO_SERVICE;
    
    if (g_vadp_mediawall_cntx.is_over_sorting_limit)
    {
        srv_mediacache_resume_decode(g_vadp_mediawall_cntx.srv_mediacache_handle);
    }
            
    error_code = srv_mediacache_lock_img_buffer_addr(
                    g_vadp_mediawall_cntx.srv_mediacache_handle, 
                    index, 
                    &lock_img);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, VADP_MEDIAWALL_NONBLOCKING_DECODE, index, lock_img.buffer, error_code);

    if (error_code == SRV_MEDIACACHE_OK)
    {
        *buffer_pp = lock_img.buffer;
        ret = SRV_MEDIACACHE_OK;
    }
    else if (error_code == SRV_MEDIACACHE_ERR_DECODING)
    {
        ret = SRV_MEDIACACHE_ERR_DECODING;
    }
    else if (error_code == VADP_MEDIAWALL_DRM_LOCKED)
    {
        ret = error_code;
    }
    else if (error_code == SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY)
    {
        ret = SRV_MEDIACACHE_ERR_DECODING;
    }
    else
    {
        ret = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
    }

    if (ret != SRV_MEDIACACHE_ERR_DECODING)
    {
        if (g_vadp_mediawall_cntx.is_over_sorting_limit)
        {
            srv_mediacache_pause_decode(g_vadp_mediawall_cntx.srv_mediacache_handle);
        }
    }
            
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_mediawall_srv_free_image_buffer
 * DESCRIPTION
 *  Release the image buffer
 * PARAMETERS
 *  index       [IN]    file index
 *  buffer      [IN]    image buffer
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_mediawall_srv_free_image_buffer(S32 index, void* buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vadp_mediawall_cntx.srv_mediacache_handle == NULL)
        return;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, VADP_MEDIAWALL_FREE_BUFF, index, buffer);
    
    srv_mediacache_unlock_img_buffer(g_vadp_mediawall_cntx.srv_mediacache_handle, buffer);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_mediawall_srv_pause_bgdecode
 * DESCRIPTION
 *  Pause the background decode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_mediawall_srv_pause_bgdecode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_vadp_mediawall_cntx.is_over_sorting_limit && 
        g_vadp_mediawall_cntx.srv_mediacache_handle)
    {
        if (!g_vadp_mediawall_cntx.is_paused)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, VADP_MEDIAWALL_PAUSE);
            srv_mediacache_pause_decode(g_vadp_mediawall_cntx.srv_mediacache_handle);
            g_vadp_mediawall_cntx.is_paused = VFX_TRUE;
        }
    }   
}


/*****************************************************************************
 * FUNCTION
 *  vadp_mediawall_srv_resume_bgdecode
 * DESCRIPTION
 *  Resume background decode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_mediawall_srv_resume_bgdecode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_vadp_mediawall_cntx.is_over_sorting_limit && 
        g_vadp_mediawall_cntx.srv_mediacache_handle)
    {
        if (g_vadp_mediawall_cntx.is_paused)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, VADP_MEDIAWALL_RESUME);
            srv_mediacache_resume_decode(g_vadp_mediawall_cntx.srv_mediacache_handle);
            g_vadp_mediawall_cntx.is_paused = VFX_FALSE;
        }
    }   
}


/*****************************************************************************
 * FUNCTION
 *  vadp_mediawall_set_rotating
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  is_rotating     [IN]    rotate flag
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_mediawall_set_rotating(VfxBool is_rotating)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vadp_mediawall_cntx.is_rotating = is_rotating;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_mediawall_set_direction
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  direction       [IN]        MediaWall direction
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_mediawall_set_direction(vadp_mediawall_direct_enum direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (direction == VADP_MEDIAWALL_PORTRAIT)
    {
        VappMediaWallScr::setViewMode(VappMediaWallScr::VIEW_PORTRAIT);
    }
    else
    {
        VappMediaWallScr::setViewMode(VappMediaWallScr::VIEW_LANDSCAPE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vapp_mediawall_set_memory_notify_cb
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  allocate_callback   [IN]    allocate memory callback function
 *  terminate_callack   [IN]    release memory callback function
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_mediawall_set_memory_notify_cb(
    vapp_mediawall_memory_allocate_callback allocate_callback, 
    vapp_mediawall_memory_release_callback terminate_callack)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (allocate_callback && terminate_callack)
    {
        g_vadp_mediawall_cntx.mem_allocate_cb = allocate_callback;
        g_vadp_mediawall_cntx.mem_release_cb = terminate_callack;
    }
    else
    {
        g_vadp_mediawall_cntx.mem_allocate_cb = NULL;
        g_vadp_mediawall_cntx.mem_release_cb = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_mediawall_set_memory
 * DESCRIPTION
 *  Set MediaWall memory
 * PARAMETERS
 *  memory_info     [IN]    memory setting
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_mediawall_set_memory(vadp_mediawall_memory_struct memory_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (memory_info.app_mem_buf_p || memory_info.med_mem_buf_p)
    {
        g_vadp_mediawall_cntx.app_mem_buf_p = memory_info.app_mem_buf_p;
        g_vadp_mediawall_cntx.app_mem_buf_size = memory_info.app_mem_buf_size;
        g_vadp_mediawall_cntx.med_mem_buf_p = memory_info.med_mem_buf_p;
        g_vadp_mediawall_cntx.med_mem_buf_size = memory_info.med_mem_buf_size;
    }
    else
        return;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_mediawall_get_direction
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  direction   [OUT]   mediawall current direction
 *****************************************************************************/
vadp_mediawall_direct_enum vapp_mediawall_get_direction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (VappMediaWallScr::getViewMode()==VappMediaWallScr::VIEW_LANDSCAPE)
        return VADP_MEDIAWALL_LANDSCAPE;
    else
        return VADP_MEDIAWALL_PORTRAIT;

}


/*****************************************************************************
 * FUNCTION
 *  vadp_mediawall_is_over_fs_sorting_limit
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  VfxBool
 *****************************************************************************/
VfxBool vadp_mediawall_is_over_fs_sorting_limit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_vadp_mediawall_cntx.is_over_sorting_limit;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_mediawall_enter_imgviewer
 * DESCRIPTION
 *  Enter imageviewer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_mediawall_enter_imgviewer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_vadp_mediawall_cntx.is_lsk_on)
        return;
    
    if (g_vadp_mediawall_cntx.srv_mediacache_handle)
    {
        srv_mediacache_stop(g_vadp_mediawall_cntx.srv_mediacache_handle);
        srv_mediacache_remove_cache(g_vadp_mediawall_cntx.srv_mediacache_handle, g_vadp_mediawall_cntx.app_mem_buf_p);

        srv_mediacache_destroy(g_vadp_mediawall_cntx.srv_mediacache_handle);
        g_vadp_mediawall_cntx.srv_mediacache_handle = NULL;
    }
    
    vadp_mediawall_notify_release_mem();
    
    if (vapp_mediawall_get_direction() == VADP_MEDIAWALL_LANDSCAPE)
        mmi_imgview_set_rotate(TRUE);
    else
    {
    #if defined(__MMI_VUI_ENGINE__) && defined(__MMI_SCREEN_SWITCH_EFFECT__)
        gui_sse_setup_scenario(GUI_SSE_SCENARIO_FROM_PHOTOWALL_TO_IMGVIEWER);
    #endif
        mmi_imgview_set_rotate(FALSE);
    }
    
    mmi_imgview_enter_view_screen();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_mediawall_check_is_mediachange
 * DESCRIPTION
 *  Check if media is changed or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_mediawall_check_is_mediachange(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vadp_mediawall_cntx.userdata == NULL && g_vadp_mediawall_cntx.is_rotating)
    {
        if (g_vadp_mediawall_cntx.srv_mediacache_handle)
        {
            srv_mediacache_stop(g_vadp_mediawall_cntx.srv_mediacache_handle);
            srv_mediacache_remove_cache(g_vadp_mediawall_cntx.srv_mediacache_handle, g_vadp_mediawall_cntx.app_mem_buf_p);

            srv_mediacache_destroy(g_vadp_mediawall_cntx.srv_mediacache_handle);
            g_vadp_mediawall_cntx.srv_mediacache_handle = NULL;
        }
        vadp_mediawall_notify_release_mem();
        g_vadp_mediawall_cntx.is_rotating = VFX_FALSE;
    }
}
#endif /* __MMI_VUI_MEDIAWALL__ */
