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
 *  vadp_shell_mediaplayer.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/ 
#include "MMI_features.h"
#ifdef __MMI_VUI_SHELL_MEDIA_PLAYER__
//#include "vfx_uc_include.h"
//#include "vcp_include.h"
//#include "vdat_include.h"
#include "vadp_shell_mediaplayer.h"
#include "trc/vadp_app_trc.h"
/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
//#include "Mmi_frm_gprot.h"
//#include "FileMgrType.h"
//#include "app_mem.h"
#include "Gdi_include.h"
//#include "Gdi_util.h"
//#include "med_utility.h"
//#include "gui_typedef.h"
#ifdef __DRM_SUPPORT__
//#include "drm_def.h"
#endif
//#include "KeyBrd.h"
//#include "ImageViewCui.h"
#ifdef MOTION_SENSOR_SUPPORT
//#include "mdi_motion.h"
#endif
#ifdef __MMI_SCREEN_SWITCH_EFFECT__    
#include "gui_effect_oem.h"
#endif

#include "MediaCacheSrvGprot.h"
#if defined(__SQLITE3_SUPPORT__)
#include "..\..\..\applib\sqlite3\inc\sqlite3.h"
#include "..\..\..\applib\sqlite3\inc\sqlite3ex.h"
//#include "ImageViewerDaemonGprot.h"
#endif /* defined(__SQLITE3_SUPPORT__) */ 
#include "MediaCacheSrv.h"
#include "PlstSrvGprot.h"
#include "MediaPlayerProt.h"

#include "FileMgrSrvGProt.h"

#include "vadp_app_trc.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "MediaPlayerGProt.h"
#include "kal_public_api.h"
#include "stack_config.h"
#include "med_api.h"
#include "string.h"
#include "lcd_sw_rnd.h"
#include "MediaCacheSrvMem.h"
#include "kal_trace.h"
#include "kurodatatype.h"
#include "lcd_sw_inc.h"
#include "mmi_frm_events_gprot.h"
#include "MediaPlayerEnumDef.h"
#include "MediaAppWidgetDef.h"
#include "BTMMIAVRCPGProt.h"
//#include "ImageViewerGprot.h"
// TODO: ask Ham to add into MediaCache's gprot.h
/* extern from  media cache service */
extern void srv_mediacache_register_engine(srv_mediacache_eng_callbacks_struct *engine_p);
extern void srv_mediacache_decode_nb_decode_callback(S32 result, srv_mediacache_err_group_enum group, void *user_data);
extern MMI_BOOL srv_mediacache_cache_cell_can_draw(srv_mediacache_cell_struct *cell);
extern void mmi_medply_app_pre_entry(void);
extern void (*g_medply_shell_play_callback)(void);
#ifdef __cplusplus
}
#endif

#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vapp_shell_mediaplayer.h"
#include "vfx_system.h"

S32 vadp_shell_mediaplayer_list_srv_callback(srv_plst_cb_evt_enum cb_event, S32 result, U32 ca_para_2);
void vadp_shell_mediaplayer_mediacache_prepare(void);
S32 vadp_shell_mediaplayer_mediacache_get_data_cb(S32 index, WCHAR *buffer, U32 length, void *user_data);
MMI_BOOL vadp_shell_mediaplayer_mediacache_cancel_decode_cell(U32 handle);
MMI_BOOL vadp_shell_mediaplayer_mediacache_decode_cell(U32 *handle,srv_mediacache_cell_struct *cell_p,srv_mediacache_nb_decode_callback done_callback,void *user_data);
void vadp_shell_mediaplayer_cancel_get_image(void);
S32 vadp_shell_mediaplayer_get_image_from_db(S32 index);
MMI_BOOL vadp_shell_mediaplayer_mediacache_engine_nb_decode(S32 ret, U8 *img_buf, S32 img_width, S32 img_height,S32 size);
static void vadp_shell_mediaplayer_mediacache_decode_done_cb(GDI_RESULT result, gdi_handle handle);
void vadp_shell_mediaplayer_image_decode_done(void);

#define PREPARE()\
        kal_uint32 start_time;\
        kal_uint32 end_time;

#define START_TIME() \
        kal_get_time(&start_time);

#define STOP_TIME(_trace_)\
        kal_get_time(&end_time);\
        VFX_TRACE((_trace_, kal_ticks_to_milli_secs(end_time - start_time)));


/**********************************************************************
 * Structure Definitions:
 **********************************************************************/
typedef struct
{
    vapp_shell_mediaplayer_decode_callback decode_cb;
    vapp_shell_mediaplayer_list_ready_callback list_ready_cb;
    vapp_shell_mediaplayer_delete_done_callback delete_done_cb;
    U32 med_mem_buf_size;
    U32 cellcount;
    VfxS32 focus_idx;
    void *med_mem_buf_p;
    void *srv_mediacache_run_buf;
    void*  menu_ptr;
    void*  panel_ptr;
    VfxBool is_list_ready;
    VfxBool is_over_sorting_limit;
    MMI_ID scrn_gid;    
    //vadp_shell_image_view_mode_enum view_mode;
    WCHAR folder_buf[(SRV_FMGR_PATH_MAX_LEN+1)];    
//    SRV_FMGR_FILELIST_HANDLE list_handle;
    U8 storage; // storage letter

    // TODO: check what is able to be removed.
    S32 curr_cache_index;
    S32 curr_focus_index;
    U32 plst_srv_hdlr;
    S32 *cache_srv_hdl;
    
    void (*imageflow_callback) (void *user_data, S32 index);
    void *imageflow_userdata;

    // MediaCache working buf ptr
    U8 *working_buf_ptr;   
    U8 *cache_runbuf_ptr;
    U8 *l2_cache_ptr;

    // Plst working buf ptr
	U8 *plst_working_buf_ptr;
    U8 *artwork_image_ptr;
    U8 *g_smp_photo_ptr;
    U8 *g_smp_photo_ptr2;
    U8 *g_active_photo_ptr;
    U8 *detail_cache_ptr; 
    srv_plst_list_get_display_struct artwork_para;    
    S32 *detail_cache_slot_array_ptr;

    U8 state;
    U32 decode_handle;
    gdi_handle cache_layer;
    gdi_handle tmp_layer; 
    void *user_data;

    srv_mediacache_cell_struct *cache_cell_p;
} vadp_shell_mediaplayer_context;



/* NVRAM part
    storage letter
    list start idx
    list end idx
    list focus idx
*/

/**********************************************************************
 * Global variables:
 **********************************************************************/
static vadp_shell_mediaplayer_context g_smp_cntx;
static vadp_shell_mediaplayer_context *g_smp_cntx_p = &g_smp_cntx;

#define g_adp_cube_mp_cntx g_smp_cntx
#define g_vadp_shell_mediaplayer_cntx g_smp_cntx

U32 g_smp_photo_width;
U32 g_smp_photo_height;


VfxBool vadp_shell_mediaplayer_is_list_ready(void)
{
    return mmi_medply_widget_is_plst_ready();
}

VfxS32 vadp_shell_mediaplayer_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxS32 ret = -1;
    VfxS32 handle = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_smp_cntx_p->plst_srv_hdlr = 0;

    PREPARE();
    START_TIME();
    ret =   mmi_medply_list_extapp_startup(&handle, vadp_shell_mediaplayer_list_srv_callback);  
    STOP_TIME("11 list_extapp_startup %dMSec\n");
    if (ret != 0)
    {
          return MMI_FALSE;
    }
    else
    {
        if (mmi_medply_widget_is_plst_ready()==MMI_FALSE)
        {
            mmi_medply_prepare_mediaplayer();
        }
   
        START_TIME();
        ret = srv_plst_list_default_list_entry(handle, SRV_PLST_DEF_ACTIVE_LIST);
        STOP_TIME("12 plst_list_default_list_entry %dMSec\n");
        if (ret != SRV_PLST_OK)
        {
            srv_plst_list_default_list_exit(handle);
            mmi_medply_list_extapp_logoff();
            return MMI_FALSE;
        }
        START_TIME();
    	ret = srv_plst_get_active_list_media_type(handle);
        STOP_TIME("13 plst_get_active_list_media_type %dMSec\n");
    	if (ret != SRV_PLST_ACTIVE_LIST_TYPE_AUDIO)
    	{
            srv_plst_list_default_list_exit(handle);	
            mmi_medply_list_extapp_logoff();
    	    return MMI_FALSE;
    	}
    	START_TIME();
      	g_smp_cntx_p->plst_srv_hdlr = handle;      

        // allocate working memory
        g_smp_cntx_p->plst_working_buf_ptr = NULL;
        g_smp_cntx_p->artwork_image_ptr = NULL;
        g_smp_cntx_p->detail_cache_ptr = NULL;
        g_smp_cntx_p->detail_cache_slot_array_ptr = NULL;
        
        media_get_ext_buffer(MOD_MMI, (void **)&g_smp_cntx_p->plst_working_buf_ptr, VADP_SHELL_MP_PLST_MEM_SIZE);   

        ASSERT(g_smp_cntx_p->plst_working_buf_ptr != NULL); 

        memset((void *)g_smp_cntx_p->plst_working_buf_ptr, 0, VADP_SHELL_MP_PLST_MEM_SIZE);	
        g_smp_cntx_p->artwork_image_ptr = g_smp_cntx_p->plst_working_buf_ptr;	
        g_smp_cntx_p->g_smp_photo_ptr = g_smp_cntx_p->artwork_image_ptr + VADP_SHELL_MP_ARTWORK_IMAGE_SIZE;
        g_smp_cntx_p->g_smp_photo_ptr2 = g_smp_cntx_p->g_smp_photo_ptr + VADP_SHELL_MP_ARTWORK_IMAGE_SIZE;
        g_smp_cntx_p->g_active_photo_ptr = g_smp_cntx_p->g_smp_photo_ptr;
        g_smp_cntx_p->detail_cache_ptr = g_smp_cntx_p->g_smp_photo_ptr2 + VADP_SHELL_MP_ARTWORK_IMAGE_SIZE;	
        g_smp_cntx_p->detail_cache_slot_array_ptr = (S32*)(g_smp_cntx_p->detail_cache_ptr + VADP_SHELL_MP_DETAILS_MEM_SIZE);
        g_smp_cntx_p->detail_cache_slot_array_ptr[0] = -1;
        STOP_TIME("14 plst_others %dMSec\n");
    }
    return MMI_TRUE;
}

void * g_vadp_shell_mediaplayer_userdata;
vadp_shell_mediaplay_callback g_vadp_shell_mediaplayer_callback;
VfxBool g_tapToPlay = VFX_FALSE;
void vadp_shell_mediaplayer_cb(void)
{
    g_tapToPlay = VFX_TRUE;
    g_vadp_shell_mediaplayer_callback (g_vadp_shell_mediaplayer_userdata );
}

void vadp_shell_mediaplayer_entry_library(vadp_shell_mediaplay_callback cb, void* user_data)
{
    g_tapToPlay = VFX_FALSE;
    g_vadp_shell_mediaplayer_userdata = user_data;
    g_vadp_shell_mediaplayer_callback = cb;
    g_medply_shell_play_callback = vadp_shell_mediaplayer_cb;
	//VFX_TRACE("%x %x", g_medply_shell_play_callback, cb);
    mmi_medply_app_pre_entry();
}

/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_get_active_item_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 vadp_shell_mediaplayer_get_active_item_count()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 total_number = 0;
    //S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_smp_cntx_p->plst_srv_hdlr == 0)
    {
        return 0;
    }

    srv_plst_get_active_plst_item_count(g_smp_cntx_p->plst_srv_hdlr, &total_number);
    if (total_number > 0x7fffffff)
    {
        return 0;
    }
    return (S32)total_number;
}

/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_get_menu_item_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 vadp_shell_mediaplayer_get_menu_item_count()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 total_number_menu = 0;
    //S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_smp_cntx_p->plst_srv_hdlr == 0)
    {
        return 0;
    }

    srv_plst_list_get_item_count(g_smp_cntx_p->plst_srv_hdlr, &total_number_menu);
    if (total_number_menu > 0x7fffffff)
    {
        return 0;
    }

    return (S32)total_number_menu;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_get_active_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 vadp_shell_mediaplayer_get_active_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* @TODO: add yaling's get next index when shuffle */
    if (!g_smp_cntx_p->plst_srv_hdlr)
    {
        return -1;
    }
    ret = srv_plst_plst_get_active_plst_item_index(g_smp_cntx_p->plst_srv_hdlr, &index);
    if (ret != SRV_PLST_OK)
    {
        return -1;
    }
    if (index > 0x7FFFFFFF)
    {
        return -1;
    }
    return index;    
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_cache_init_srv
 * DESCRIPTION
 *  
 * PARAMETERS
 *  num_all     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 vadp_shell_mediaplayer_cache_init_srv(S32 num_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    // allocate working memory
    g_smp_cntx_p->working_buf_ptr = NULL;
    media_get_ext_buffer(MOD_MMI, (void **)&g_smp_cntx_p->working_buf_ptr, VADP_SHELL_MP_MEM_SIZE);   
    ASSERT(g_smp_cntx_p->working_buf_ptr != NULL); 

    // assign media cache working memory
    g_smp_cntx_p->cache_runbuf_ptr = g_smp_cntx_p->working_buf_ptr;
    
    // create media cache service
    g_smp_cntx_p->cache_srv_hdl = NULL;
    g_smp_cntx_p->cache_srv_hdl = srv_mediacache_create((void *)g_smp_cntx_p->cache_runbuf_ptr, VADP_SHELL_MP_RUN_BUF_SIZE);

    if (g_smp_cntx_p->cache_srv_hdl == NULL)
    {
        media_free_ext_buffer(MOD_MMI, (void **)&g_smp_cntx_p->working_buf_ptr);
        g_smp_cntx_p->working_buf_ptr = NULL;
        return SRV_MEDIACACHE_ERR_NOT_SUPPORT;
    }

    // prepare mediacache decoder engine 
    vadp_shell_mediaplayer_mediacache_prepare();

#if 0  // Sqlite3
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


    // config l2 cache size
    srv_mediacache_config_level2_size(
        g_smp_cntx_p->cache_srv_hdl, 
        VappShellMediaplayerCell::CELL_ALBUM_WIDTH,
        VappShellMediaplayerCell::CELL_ALBUM_HEIGHT);
    // no need to disable clip head
    //srv_mediacache_disable_level2_clip_head(g_smp_cntx_p->cache_srv_hdl);
    
    // set mediacache to prefetch mode
    srv_mediacache_config_work_mode_to_prefetch_func(
        g_smp_cntx_p->cache_srv_hdl,
        num_all,
        vadp_shell_mediaplayer_mediacache_get_data_cb);

    // assign L2 cache working memory
    g_smp_cntx_p->l2_cache_ptr = g_smp_cntx_p->cache_runbuf_ptr + VADP_SHELL_MP_RUN_BUF_SIZE;

    // set memory for L2 cache
    ret = srv_mediacache_add_cache(
            g_smp_cntx_p->cache_srv_hdl,
            SRV_MEDIACACHE_CACHE_TYPE_L2,
            g_smp_cntx_p->l2_cache_ptr,
            VADP_SHELL_MP_SMALL_CACHE_BUF_SIZE);

    if (ret != SRV_MEDIACACHE_OK)
    {
        srv_mediacache_destroy(g_smp_cntx_p->cache_srv_hdl);
        media_free_ext_buffer(MOD_MMI, (void **)&g_smp_cntx_p->working_buf_ptr);
        g_smp_cntx_p->cache_srv_hdl = NULL;
        g_smp_cntx_p->working_buf_ptr = NULL;
        return ret;
    }
    
    // start media cache service 
    srv_mediacache_start(g_smp_cntx_p->cache_srv_hdl, 0);

    return ret;

}

/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_mediacache_prepare
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_shell_mediaplayer_mediacache_prepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_eng_callbacks_struct callback_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callback_struct.cancel_decode_cell = vadp_shell_mediaplayer_mediacache_cancel_decode_cell;
    callback_struct.decode_cell = vadp_shell_mediaplayer_mediacache_decode_cell;
    callback_struct.get_file_name = NULL;
    callback_struct.search_cell = NULL;
    callback_struct.cancel_search_cell = NULL;
    srv_mediacache_register_engine(&callback_struct);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_mediacache_cancel_decode_cell
 * DESCRIPTION
 *  callback function of non-block image decode
 * PARAMETERS
 *  handle          [IN]        GDI handle
 *  result(?)       [IN]        Result
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL vadp_shell_mediaplayer_mediacache_cancel_decode_cell(U32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_LOG(VFX_INFO, VADP_SHELL_MEDIAPLAYER_CANCEL_DECODE_CELL, __LINE__);

    gdi_image_nb_stop(g_smp_cntx_p->decode_handle);
    vadp_shell_mediaplayer_cancel_get_image();
    g_smp_cntx_p->decode_handle = 0;
    /* @TODO: Notify image flow to cancel load image. */

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_mediacache_decode_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle              [?]         
 *  cell_p              [?]         
 *  done_callback       [IN]        
 *  user_data           [?]         
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL vadp_shell_mediaplayer_mediacache_decode_cell(
            U32 *handle,
            srv_mediacache_cell_struct *cell_p,
            srv_mediacache_nb_decode_callback done_callback,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ////kal_printf("Get image data from ENGIN\n"); */
    if (NULL == cell_p)
    {
        return MMI_FALSE;
    }

    g_smp_cntx_p->user_data = user_data;
    g_smp_cntx_p->cache_cell_p = cell_p;

    /* current */
    gdi_image_nb_stop(g_smp_cntx_p->decode_handle);
    g_smp_cntx_p->decode_handle = 0;
    if (g_smp_cntx_p->cache_layer != 0)
    {
        gdi_layer_free(g_smp_cntx_p->cache_layer);
        g_smp_cntx_p->cache_layer = 0;
    }

    result = vadp_shell_mediaplayer_get_image_from_db(g_smp_cntx_p->cache_cell_p->file_index);
    VFX_LOG(VFX_INFO, VADP_SHELL_MEDIAPLAYER_GET_IMAGE_FROM_DB, g_smp_cntx_p->cache_cell_p->file_index, result, __LINE__);
    if (result < 0)
    {
        g_smp_cntx_p->cache_cell_p->err_code = result;
        g_smp_cntx_p->cache_cell_p->err_group = SRV_MEDIACACHE_ERR_GROUP_FS;
        g_smp_cntx_p->cache_cell_p = NULL;
        return MMI_FALSE;
    }
    return MMI_TRUE;
}

void vadp_shell_mediaplayer_get_cur_artwork(void** buf_ptr, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    S32 w = 0;
    S32 h = 0;

    U32 media_id;
    U32 idx;

    srv_plst_list_get_display_struct artwork_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    *buf_ptr = NULL;

	if(g_smp_cntx_p->plst_srv_hdlr == 0)
    {
        return ;        
    }

    ret = srv_plst_plst_item_get_active_media_info_curr(g_smp_cntx_p->plst_srv_hdlr, &media_id, &idx, NULL);

    if(ret < SRV_PLST_OK)
    {
        return;
    }

    artwork_para.index = media_id;
    artwork_para.buff_size = SRV_PLST_ARTWORK_RESIZED_WIDTH * SRV_PLST_ARTWORK_RESIZED_HEIGHT * 2;
    artwork_para.string_ptr = (U32) g_smp_cntx_p->artwork_image_ptr;
    
    ret =  srv_plst_list_get_artwork_by_media_id(g_smp_cntx_p->plst_srv_hdlr, &artwork_para);

    if (ret == SRV_PLST_OK)
    {
        gdi_handle tmp_layer;
        if (artwork_para.buff_size > 0)
        {
            ret = gdi_image_get_dimension_mem(
                    GDI_IMAGE_TYPE_JPG,
                    g_smp_cntx_p->artwork_image_ptr,
                    artwork_para.buff_size,
                    &w,
                    &h);

            if (ret == GDI_SUCCEED)
            {
                S32 real_offset_x, real_offset_y, real_width, real_height;

                if (g_smp_cntx_p->g_active_photo_ptr == g_smp_cntx_p->g_smp_photo_ptr)
                    g_smp_cntx_p->g_active_photo_ptr = g_smp_cntx_p->g_smp_photo_ptr2;
                else if (g_smp_cntx_p->g_active_photo_ptr == g_smp_cntx_p->g_smp_photo_ptr2)
                    g_smp_cntx_p->g_active_photo_ptr = g_smp_cntx_p->g_smp_photo_ptr;
                else
                    ASSERT(0);

                gdi_util_fit_box(
                    GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT, 
                    width, 
                    height, 
                    w, 
                    h,
                    &real_offset_x,
                    &real_offset_y,
                    &real_width,
                    &real_height);


                gdi_layer_create_using_outside_memory(
                    0,
                    0,
                    width,
                    height,
                    &tmp_layer,
                    g_smp_cntx_p->g_active_photo_ptr,
                    VADP_SHELL_MP_ARTWORK_IMAGE_SIZE);

                gdi_layer_push_and_set_active(tmp_layer);
                gdi_push_and_set_alpha_blending_source_layer(tmp_layer);
                gdi_layer_clear(GDI_COLOR_BLACK);
                gdi_layer_set_source_key(TRUE,GDI_COLOR_TRANSPARENT);
                gdi_image_draw_resized_mem(real_offset_x,real_offset_y,real_width,real_height,g_smp_cntx_p->artwork_image_ptr,GDI_IMAGE_TYPE_JPG,artwork_para.buff_size);
                gdi_pop_and_restore_alpha_blending_source_layer();
                gdi_layer_pop_and_restore_active();
                gdi_layer_free(tmp_layer);
                *buf_ptr = (void*) &g_smp_cntx_p->g_active_photo_ptr[0];
			}
            else
            {
                *buf_ptr = NULL;
            }
        }
    }

    return;

}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_cancel_get_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_shell_mediaplayer_cancel_get_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //////kal_printf("Cancel get data\n");
    VFX_LOG(VFX_INFO, VADP_SHELL_MEDIAPLAYER_CANCEL_GET_IMAGE, __LINE__);

    if (g_smp_cntx_p->plst_srv_hdlr)
    {
        VFX_LOG(VFX_INFO, VADP_SHELL_MEDIAPLAYER_ARTWORK_ASYNC_STOP, __LINE__);

        srv_plst_list_get_item_artwork_async_stop(g_smp_cntx_p->plst_srv_hdlr);    
    }

    g_smp_cntx_p->state = VADP_SHELL_MEDIAPLAYER_STATE_IDLE;
    g_smp_cntx_p->curr_cache_index = 0xFF;
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_media_player_get_imge_from_db
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 vadp_shell_mediaplayer_get_image_from_db(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_smp_cntx_p->plst_srv_hdlr == 0)
    {
        return MMI_FALSE;        
    }

    if (g_smp_cntx_p->state!=VADP_SHELL_MEDIAPLAYER_STATE_IDLE)
    {
        ASSERT(0);
        return MMI_FALSE;
    }
    
    g_smp_cntx_p->curr_cache_index = index;
    g_smp_cntx_p->artwork_para.index = index;
    g_smp_cntx_p->artwork_para.buff_size = SRV_PLST_ARTWORK_RESIZED_WIDTH * SRV_PLST_ARTWORK_RESIZED_HEIGHT * 2;
    g_smp_cntx_p->artwork_para.string_ptr = (U32) g_smp_cntx_p->artwork_image_ptr;

    ret = srv_plst_list_get_item_artwork_async(g_smp_cntx_p->plst_srv_hdlr, &g_smp_cntx_p->artwork_para);
    VFX_LOG(VFX_INFO, VADP_SHELL_MEDIAPLAYER_GET_ARTWORK_ASYNC, index, g_smp_cntx_p->state, ret, __LINE__);

    if (SRV_PLST_ASYNC == ret)
    {
        g_smp_cntx_p->state = VADP_SHELL_MEDIAPLAYER_STATE_LOADING;
        return MMI_TRUE;
    }
    else if (ret != SRV_PLST_OK)
    {
        return MMI_FALSE;
    }
    else    /* SRV_PLST_OK */
    {
        ASSERT(0);
    }

    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_mediacache_get_data_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 *  buffer          [?]         
 *  length          [IN]        
 *  user_data       [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 vadp_shell_mediaplayer_mediacache_get_data_cb(S32 index, WCHAR *buffer, U32 length, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //////kal_printf("\n[Guoming] none used get_data_cb \n");
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_set_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 vadp_shell_mediaplayer_cache_set_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //////kal_printf("\n[Guoming] Vadp_v2p_cube_media_player_set_index = %d\n", index);
    if (g_smp_cntx_p->cache_srv_hdl == NULL)
    {
        return MMI_FALSE;
    }
    g_smp_cntx_p->curr_focus_index = index;
    srv_mediacache_goto_index(g_smp_cntx_p->cache_srv_hdl, index);
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_deinit_cache_srv
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_shell_mediaplayer_deinit_cache_srv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_smp_cntx_p->cache_srv_hdl)
    {
        srv_mediacache_stop(g_smp_cntx_p->cache_srv_hdl);
        srv_mediacache_destroy(g_smp_cntx_p->cache_srv_hdl);
        g_smp_cntx_p->cache_srv_hdl = NULL;
    }

    if (g_smp_cntx_p->working_buf_ptr)
    {
        media_free_ext_buffer(MOD_MMI, (void **)&g_smp_cntx_p->working_buf_ptr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_unregister_cache_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_shell_mediaplayer_unregister_cache_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_smp_cntx_p->imageflow_callback = NULL;
    g_smp_cntx_p->imageflow_userdata = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_plst_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_shell_mediaplayer_deinit_plst(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_smp_cntx_p->plst_working_buf_ptr)
    {
        media_free_ext_buffer(MOD_MMI, (void **)&g_smp_cntx_p->plst_working_buf_ptr);
    }

    if (g_smp_cntx_p->plst_srv_hdlr == 0)
    {
        return;
    }

    srv_plst_list_default_list_exit(g_smp_cntx_p->plst_srv_hdlr);
    mmi_medply_list_extapp_logoff();
}

/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_list_srv_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cb_event        [IN]        
 *  result          [IN]        
 *  ca_para_2       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 vadp_shell_mediaplayer_list_srv_callback(srv_plst_cb_evt_enum cb_event, S32 result, U32 ca_para_2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h;
    S32 img_w = 0;
    S32 img_h = 0;
    S32 img_size = 0;
    U8 *ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    VFX_LOG(VFX_INFO, VADP_SHELL_MEDIAPLAYER_VADP_SHELL_MEDIAPLAYER_LIST_SRV_CALLBACK, result, g_smp_cntx_p->curr_cache_index ,g_smp_cntx_p->artwork_para.index, __LINE__);

    if ((SRV_PLST_CB_EVT_GET_IMAGE == cb_event))
    {
        if (ca_para_2 !=  g_smp_cntx_p->artwork_para.index)
        {
            return 0;
        }
        if (VADP_SHELL_MEDIAPLAYER_STATE_LOADING != g_smp_cntx_p->state)
        {
            VFX_LOG(VFX_INFO, VADP_SHELL_MEDIAPLAYER_LIST_SRV_CALLBACK_FAIL_1,__LINE__);
            return 0;
        }
        if (SRV_PLST_OK == result)
        {
            if (g_smp_cntx_p->artwork_para.buff_size > 0)
            {
                gdi_image_get_dimension_mem(
                        GDI_IMAGE_TYPE_JPG,
                        g_smp_cntx_p->artwork_image_ptr,
                        g_smp_cntx_p->artwork_para.buff_size,
                        &w,
                        &h);
                /* ////kal_printf("Get image data callback HAVE DATA %d, %d, %d\n", w, h,g_vadp_shell_mediaplayer_cntx.artwork_para.buff_size); */
                img_w = w;
                img_h = h;
                img_size = g_smp_cntx_p->artwork_para.buff_size;
                ptr = g_smp_cntx_p->artwork_image_ptr;
                VFX_LOG(VFX_INFO, VADP_SHELL_MEDIAPLAYER_LIST_SRV_CALLBACK_OK,g_smp_cntx_p->curr_cache_index,__LINE__);

                g_smp_cntx_p->state = VADP_SHELL_MEDIAPLAYER_STATE_DECODING;
                vadp_shell_mediaplayer_mediacache_engine_nb_decode(0, ptr, img_w, img_h, img_size);
                return 0;
            }
        }
        g_smp_cntx_p->state = VADP_SHELL_MEDIAPLAYER_STATE_IDLE;
        /* ////kal_printf("Get image data callback NO DATA \n"); */
        vadp_shell_mediaplayer_mediacache_engine_nb_decode(-1, ptr, img_w, img_h, img_size);
        return 0;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_mediacache_engine_nb_decode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret             [IN]        
 *  img_buf         [?]         
 *  img_width       [IN]        
 *  img_height      [IN]        
 *  size            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL vadp_shell_mediaplayer_mediacache_engine_nb_decode(
            S32 ret,
            U8 *img_buf,
            S32 img_width,
            S32 img_height,
            S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 buf_length = 0;
    S32 x, y, w, h, layer_w, layer_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_smp_cntx_p->cache_cell_p)
    {
        ASSERT(0);
    }
    buf_length = srv_mediacache_cache_get_img_size_by_type(g_smp_cntx_p->cache_cell_p->type);

    if (ret < 0)
    {
        g_smp_cntx_p->cache_cell_p->err_code = ret;
        g_smp_cntx_p->cache_cell_p->err_group = SRV_MEDIACACHE_ERR_GROUP_FS;
        g_smp_cntx_p->cache_cell_p = NULL;
        //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_OPEN_FILE_ERR,fs_handle);
        //srv_mediacache_check_cb_and_call(g_cube_medply_cache_cell_p->file_index, MMI_TRUE);\\yongdiaoma?
        //g_cube_medply_cache_cell_p = NULL;
        //@TODO: How to notice media cache to cancel this cache
        srv_mediacache_decode_nb_decode_callback(
            (S32) SRV_MEDIACACHE_ERR_NOT_SUPPORT,
            SRV_MEDIACACHE_ERR_GROUP_GDI,
            g_smp_cntx_p->user_data);
        VFX_LOG(VFX_INFO, VADP_SHELL_MEDIAPLAYER_ENGINE_CB_DECODE_FAIL,__LINE__);

        g_smp_cntx_p->state = VADP_SHELL_MEDIAPLAYER_STATE_IDLE;        
        return MMI_FALSE;
    }

    if (img_width <= 0 || img_height <= 0 || img_width > SRV_MEDIACACHE_DECODE_MAX_W_H ||
        img_height > SRV_MEDIACACHE_DECODE_MAX_W_H)
    {
        g_smp_cntx_p->cache_cell_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;

        g_smp_cntx_p->cache_cell_p->err_code = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
        g_smp_cntx_p->cache_cell_p->err_group = SRV_MEDIACACHE_ERR_GROUP_MEDIACACHE;
        g_smp_cntx_p->cache_cell_p = NULL;
        //g_cube_medply_cache_cell_p = NULL;
        //@TODO: How to notice media cache to cancel this cache
        srv_mediacache_decode_nb_decode_callback(
            (S32) SRV_MEDIACACHE_ERR_NOT_SUPPORT,
            SRV_MEDIACACHE_ERR_GROUP_GDI,
            g_smp_cntx_p->user_data);
        g_smp_cntx_p->state = VADP_SHELL_MEDIAPLAYER_STATE_IDLE;        
        VFX_LOG(VFX_INFO, VADP_SHELL_MEDIAPLAYER_ENGINE_CB_DECODE_FAIL,__LINE__);
        return MMI_FALSE;
    }

    g_smp_cntx_p->cache_cell_p->image_type = GDI_IMAGE_TYPE_JPG_FILE;
    srv_mediacache_cache_fill_cell_by_img(img_width, img_height, g_smp_cntx_p->cache_cell_p);
    if (g_smp_cntx_p->cache_cell_p->image_width <= 0 || g_smp_cntx_p->cache_cell_p->image_height <= 0)
    {
        g_smp_cntx_p->cache_cell_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
        g_smp_cntx_p->cache_cell_p->err_code = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
        g_smp_cntx_p->cache_cell_p->err_group = SRV_MEDIACACHE_ERR_GROUP_MEDIACACHE;
        g_smp_cntx_p->cache_cell_p = NULL;
        srv_mediacache_decode_nb_decode_callback(
            (S32) SRV_MEDIACACHE_ERR_NOT_SUPPORT,
            SRV_MEDIACACHE_ERR_GROUP_GDI,
            g_smp_cntx_p->user_data);
        g_smp_cntx_p->state = VADP_SHELL_MEDIAPLAYER_STATE_IDLE;        
        VFX_LOG(VFX_INFO, VADP_SHELL_MEDIAPLAYER_ENGINE_CB_DECODE_FAIL,__LINE__);
        return MMI_FALSE;
    }
    else
    {
        x = 0;
        y = 0;
        w = g_smp_cntx_p->cache_cell_p->image_width;
        h = g_smp_cntx_p->cache_cell_p->image_height;
        layer_w = g_smp_cntx_p->cache_cell_p->image_width;
        layer_h = g_smp_cntx_p->cache_cell_p->image_height;
        ASSERT(g_smp_cntx_p->cache_cell_p->image_width > 0);
        ASSERT(g_smp_cntx_p->cache_cell_p->image_height > 0);
        gdi_layer_create_using_outside_memory(
            0,
            0,
            layer_w,
            layer_h,
            &g_smp_cntx_p->cache_layer,
            g_smp_cntx_p->cache_cell_p->buffer,
            buf_length);
        gdi_layer_push_and_set_active(g_smp_cntx_p->cache_layer);
        gdi_nb_set_done_callback(vadp_shell_mediaplayer_mediacache_decode_done_cb);
        gdi_nb_set_blt(MMI_FALSE, MMI_FALSE);
        g_smp_cntx_p->decode_handle = gdi_image_nb_draw_internal(GDI_IMAGE_SRC_FROM_MEMORY,img_buf,GDI_IMAGE_TYPE_JPG, size,x, y, w, h, 0, 0, (gdc_job_flag_enum)0);
        gdi_layer_pop_and_restore_active();
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cube_media_player_decode_done_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 *  handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void vadp_shell_mediaplayer_mediacache_decode_done_cb(GDI_RESULT result, gdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_smp_cntx_p->decode_handle != handle)
    {
        VFX_LOG(VFX_INFO, VADP_SHELL_MEDIAPLAYER_GDI_DECODE_CB_HANDLE_ERROR,__LINE__);            
        /* MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_DECODE_CB_NOT_MY); */
        return;
    }

    srv_mediacache_decode_nb_decode_callback((S32) result, SRV_MEDIACACHE_ERR_GROUP_GDI, g_smp_cntx_p->user_data);

    if (0 == result)
    {
        VFX_LOG(VFX_INFO, VADP_SHELL_MEDIAPLAYER_GDI_DECODE_CB_OK,__LINE__);
        vadp_shell_mediaplayer_image_decode_done();
    }
    else
    {
        g_smp_cntx_p->state = VADP_SHELL_MEDIAPLAYER_STATE_IDLE;
        VFX_LOG(VFX_INFO, VADP_SHELL_MEDIAPLAYER_GDI_DECODE_CB_FAIL,__LINE__);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_image_decode_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_shell_mediaplayer_image_decode_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (VADP_SHELL_MEDIAPLAYER_STATE_DECODING == g_smp_cntx_p->state)
    {
        if (g_smp_cntx_p->imageflow_callback)
        {
            g_smp_cntx_p->imageflow_callback(
                                g_smp_cntx_p->imageflow_userdata,
                                g_smp_cntx_p->curr_cache_index);
        }

        g_smp_cntx_p->state = VADP_SHELL_MEDIAPLAYER_STATE_IDLE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_cache_srv_decode_callback
 * DESCRIPTION
 *  Decode callback function
 * PARAMETERS
 *  err_group       [IN]    error group
 *  err_code        [IN]    error code
 *  user_data       [IN]    user data
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_shell_mediaplayer_cache_srv_decode_callback(S32 err_group,S32 err_code, void *user_data)
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
             err_code == SRV_MEDIACACHE_ERR_DECODING)
    {
        error_code = err_code;
    }
    else
    {
        error_code = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
    }
        
    if (g_smp_cntx_p->decode_cb)
    {
        g_smp_cntx_p->decode_cb(g_smp_cntx_p->menu_ptr, (S32)user_data, error_code);
    }
}



/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_cache_srv_get_lock_image_buffer_nonblocking
 * DESCRIPTION
 *  Non-blocking decode image & lock buffer function
 * PARAMETERS
 *  user_data   [IN]    user data
 *  index       [IN]    file index
 *  callback    [OUT]   decode callback function
 * RETURNS
 *  decode result
 *****************************************************************************/
S32 vadp_shell_mediaplayer_cache_srv_get_lock_image_buffer_nonblocking(
    void *user_data, 
    S32 index,
    vapp_shell_mediaplayer_decode_callback callback, void** buffer_pp)
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
    VFX_TRACE(("[SHELL IV], NB decode image index= %d \n", index));
    
    lock_img.callback = vadp_shell_mediaplayer_cache_srv_decode_callback;
    lock_img.user_data = (void*)index;
    lock_img.source = SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE;

    g_smp_cntx_p->menu_ptr = user_data;
    g_smp_cntx_p->decode_cb = callback;

    if (g_smp_cntx_p->cache_srv_hdl == NULL)
        return VADP_SHELLMP_NO_SERVICE;

    if (index < 0)
        return SRV_MEDIACACHE_ERR_NOT_SUPPORT;
    
//    if (g_vadp_shell_imgviewer_cntx.is_over_sorting_limit)
//    {
//        srv_mediacache_resume_decode(g_vadp_shell_imgviewer_cntx.srv_mediacache_handle);
//    }
            
    error_code = srv_mediacache_lock_img_buffer_addr(
                    g_smp_cntx_p->cache_srv_hdl , 
                    index, 
                    &lock_img);
    
    if (error_code == SRV_MEDIACACHE_OK)
    {
        *buffer_pp = lock_img.buffer;
        ret = SRV_MEDIACACHE_OK;
    }
    else if (error_code == SRV_MEDIACACHE_ERR_DECODING)
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
 *  vadp_shell_mediaplayer_cache_srv_get_lock_image_buffer
 * DESCRIPTION
 *  Blocking decode image & lock buffer function
 * PARAMETERS
 *  index       [IN]    file index
 *  source      [IN]    decode source type
 *  buffer      [OUT]   image bufer
 * RETURNS
 *  decode result
 *****************************************************************************/
S32 vadp_shell_mediaplayer_cache_srv_get_lock_image_buffer(S32 index, srv_mediacache_image_source_enum source, void** buffer, S32 *resized_width, S32 *resized_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_lock_img_buffer_addr_struct lock_img;
    S32 ret = SRV_MEDIACACHE_OK;
    S32 error_code = SRV_MEDIACACHE_OK;
    srv_mediacache_get_img_info_struct img_info;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    VFX_TRACE(("[Mediaplayer], decode image index= %d\n", index));
    
    lock_img.callback = NULL;
    lock_img.user_data = NULL;
    lock_img.source = source;

    if (g_smp_cntx_p->cache_srv_hdl == NULL)
        return VADP_SHELLMP_NO_SERVICE;

    if (index < 0)
        return SRV_MEDIACACHE_ERR_NOT_SUPPORT;
               
    error_code = srv_mediacache_lock_img_buffer_addr(g_smp_cntx_p->cache_srv_hdl, index, &lock_img);

    
    if (error_code == SRV_MEDIACACHE_OK)
    {
        *buffer = lock_img.buffer;

        error_code = srv_mediacache_get_image_info(
            g_smp_cntx_p->cache_srv_hdl, 
            index, &img_info);

        if (error_code  == SRV_MEDIACACHE_OK)
        {
            *resized_width = img_info.resized_width;
            *resized_height = img_info.resized_height;        
        }
        else
        {
            *resized_width = 0;
            *resized_height = 0;
        }

        ret = error_code;
        
    }
    else if (error_code == SRV_MEDIACACHE_ERR_NOT_READY || 
             error_code == SRV_MEDIACACHE_ERR_NOT_ENOUGH_CACHE ||
             error_code == SRV_MEDIACACHE_ERR_DECODING)
    {
        ret = error_code;
    }
    else
    {
        ret = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
    }

            
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_cache_srv_get_image_info
 * DESCRIPTION
 *  Release the image buffer
 * PARAMETERS
 *  index       [IN]    file index
 *  buffer      [IN]    image buffer
 * RETURNS
 *  void
 *****************************************************************************/
S32 vadp_shell_mediaplayer_cache_srv_get_image_info(S32 index, S32 *resized_width, S32 *resized_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    srv_mediacache_get_img_info_struct img_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_smp_cntx_p->cache_srv_hdl== NULL)
        return VADP_SHELLMP_NO_SERVICE;
    
    ret = srv_mediacache_get_image_info(
        g_smp_cntx_p->cache_srv_hdl, 
        index, &img_info);

    if (ret == SRV_MEDIACACHE_OK)
    {
        *resized_width = img_info.resized_width;
        *resized_height = img_info.resized_height;        
    }
    else
    {
        *resized_width = 0;
        *resized_height = 0;
    }
    return ret;
    
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_cache_srv_free_image_buffer
 * DESCRIPTION
 *  Release the image buffer
 * PARAMETERS
 *  buffer      [IN]    image buffer
 * RETURNS
 *  void
 *****************************************************************************/
S32 vadp_shell_mediaplayer_cache_srv_free_image_buffer(void* buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error_code ;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_smp_cntx_p->cache_srv_hdl == NULL)
        return VADP_SHELLMP_NO_SERVICE;
    
    error_code = srv_mediacache_unlock_img_buffer(g_smp_cntx_p->cache_srv_hdl, buffer);

    return error_code;
}

/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_get_song_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  title       [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 vadp_shell_mediaplayer_get_song_title(S32 index, void* title_str, S32 title_str_buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_get_display_struct temp_info;
    S32 srv_plst_list_get_item_display_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_smp_cntx_p->plst_srv_hdlr)
    {
        return MMI_FALSE;
    }

    memset(title_str,0x0,title_str_buf_size);
    
    temp_info.index = index;
    temp_info.buff_size = title_str_buf_size;
    temp_info.string_ptr = (U32) title_str;
    
    srv_plst_list_get_item_display_ret = srv_plst_list_get_item_display(g_smp_cntx_p->plst_srv_hdlr, &temp_info);
    if (srv_plst_list_get_item_display_ret != SRV_PLST_OK)
    {
         return MMI_FALSE;
    }
    
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_get_details
 * DESCRIPTION
 *  If has in all songs list, do nothing.
 *  If do not in all songs list, entry list service all songs list
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
S32 vadp_shell_mediaplayer_get_details(S32 index, srv_plst_media_details_struct *details)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 media_id;
    S32 ret;
    S32 slot_idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*check current list is media file list*/

    slot_idx = index % VADP_SHELL_MP_DETAILS_COUNT;

    if (g_smp_cntx_p->detail_cache_slot_array_ptr[slot_idx] == index)
    {
        srv_plst_media_details_struct* cache_ptr = (srv_plst_media_details_struct*) g_smp_cntx_p->detail_cache_ptr;
        /* hit cache */
        memcpy(details, (void*) &cache_ptr[slot_idx],sizeof(srv_plst_media_details_struct));
        return SRV_PLST_OK; 
    }
    
	if (g_smp_cntx_p->plst_srv_hdlr == 0)
	{
		kal_prompt_trace(MOD_MMI_MEDIA_APP,"[SHELL][BAOQI][ERR]vadp_shell_mediaplayer_get_details at line = [%d]", __LINE__);
		return SRV_PLST_RET_ERR_UNKOWN_ERR;
	}
    ret = srv_plst_media_get_id(g_smp_cntx_p->plst_srv_hdlr, index, &media_id);
    if (ret < SRV_PLST_OK)
    {
         //TODO: add error logs
        VFX_LOG(VFX_INFO, VADP_SHELL_MEDIAPLAYER_FAIL_TO_GET_MEDIA_ID,__LINE__);
        //ASSERT(0);
    }
    else
    {
        ret = srv_plst_media_get_details(g_smp_cntx_p->plst_srv_hdlr, media_id, details);
        if (ret < SRV_PLST_OK)
        {
            //TODO: add error logs
            VFX_LOG(VFX_INFO, VADP_SHELL_MEDIAPLAYER_FAIL_TO_GET_DETAILS,__LINE__);
            //ASSERT(0);
        }
        else
        {
            srv_plst_media_details_struct* cache_ptr = (srv_plst_media_details_struct*) g_smp_cntx_p->detail_cache_ptr;
            /* hit cache */
            memcpy((void*) &cache_ptr[slot_idx], details, sizeof(srv_plst_media_details_struct));            
            g_smp_cntx_p->detail_cache_slot_array_ptr[slot_idx] = index;
        }
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_get_active_details
 * DESCRIPTION
 *  If has in all songs list, do nothing.
 *  If do not in all songs list, entry list service all songs list
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
S32 vadp_shell_mediaplayer_get_active_details(S32 index, srv_plst_media_details_struct *details)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 media_id;
    S32 ret;
    S32 slot_idx;
    U32 idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*check current list is media file list*/

    slot_idx = index % VADP_SHELL_MP_DETAILS_COUNT;

    if (g_smp_cntx_p->detail_cache_slot_array_ptr[slot_idx] == index)
    {
        srv_plst_media_details_struct* cache_ptr = (srv_plst_media_details_struct*) g_smp_cntx_p->detail_cache_ptr;
        /* hit cache */
        memcpy(details, (void*) &cache_ptr[slot_idx],sizeof(srv_plst_media_details_struct));
        return SRV_PLST_OK; 
    }
    

    ret = srv_plst_plst_item_get_active_media_info_curr(g_smp_cntx_p->plst_srv_hdlr, &media_id, &idx, NULL);    
    if (ret < SRV_PLST_OK)
    {
        //TODO: add error logs
        VFX_LOG(VFX_INFO, VADP_SHELL_MEDIAPLAYER_FAIL_TO_GET_MEDIA_ID,__LINE__);
        //ASSERT(0);
    }
    else
    {
        ret = srv_plst_media_get_details(g_smp_cntx_p->plst_srv_hdlr, media_id, details);
        if (ret < SRV_PLST_OK)
        {
            //TODO: add error logs
            VFX_LOG(VFX_INFO, VADP_SHELL_MEDIAPLAYER_FAIL_TO_GET_DETAILS,__LINE__);
            //ASSERT(0);
        }
        else
        {
            srv_plst_media_details_struct* cache_ptr = (srv_plst_media_details_struct*) g_smp_cntx_p->detail_cache_ptr;
            /* hit cache */
            memcpy((void*) &cache_ptr[slot_idx], details, sizeof(srv_plst_media_details_struct));            
            g_smp_cntx_p->detail_cache_slot_array_ptr[slot_idx] = index;
        }
    }
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_player_set_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL vadp_shell_mediaplayer_player_set_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE  str_id;
    mmi_event_notify_enum event_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_medply_widget_set_and_apply_index(index, &str_id, &event_type);

    //////kal_printf("\n[Guoming] vadp_v2p_cube_media_player_apply() index = %d", index);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_player_apply_picked_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL vadp_shell_mediaplayer_player_apply_picked_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE  str_id;
    mmi_event_notify_enum event_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_medply_widget_apply_picked_file(&str_id, &event_type);

    //////kal_printf("\n[Guoming] vadp_v2p_cube_media_player_apply() index = %d", index);
}



U8 vadp_shell_mediaplayer_state_transform(U8 audio_player_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_state_enum media_player_state = (mmi_medply_state_enum)audio_player_state;

    switch (media_player_state)
    {        
        case MEDPLY_WIDGET_STATE_IDLE:
        {

            return VADP_SHELL_MEDIAPLAYER_PLAYER_STATE_INIT;
        }
   
        case MEDPLY_WIDGET_STATE_PLAY:
        {

            return VADP_SHELL_MEDIAPLAYER_PLAYER_STATE_PLAY;
        }
    
        case MEDPLY_WIDGET_STATE_PROCESSING:
        {

            return VADP_SHELL_MEDIAPLAYER_PLAYER_STATE_PROCESS;
        }

        default:
        {
            ASSERT(0);
        }
    }

    return VADP_SHELL_MEDIAPLAYER_PLAYER_STATE_INIT;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_player_get_info
 * DESCRIPTION
 *  Get information
 * PARAMETERS
 *  info_type       [IN]        Information type
 *  result_ptr      [OUT]       Result
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_shell_mediaplayer_player_get_info(vadp_shell_mediaplayer_player_info_enum info_type, void *result_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_TRACE(MMI_MEDIA_TRC_G2_APP, VADP_AUDPLY_GET_INFO, info_type); */

    switch (info_type)
    {
        case VADP_SHELL_MEDIAPLAYER_PLAYER_INFO_DURATION:
        {
            U64* total_dur;
            /* U64 */
            mmi_medply_widget_get_value(MMI_WIDGET_PLAYER_TOTAL_DURATION, result_ptr);
            total_dur = (U64*)result_ptr;
            *total_dur += 500;
            break;
        }

        case VADP_SEHLL_MEDIAPLAYER_PLAYER_INFO_CURRENT_PLAYTIME:
        {
            /* U64 */
            mmi_medply_widget_get_value(MMI_WIDGET_PLAYER_CUR_TIME, result_ptr);
            break;
        }

        case VADP_SEHLL_MEDIAPLAYER_PLAYER_INFO_CURRENT_STATE:
        {
            /* U8 */
            U8 state;
            
            mmi_medply_widget_get_value(MMI_WIDGET_PLAYER_CUR_STATE, &state);
            *((U8*) result_ptr) = vadp_shell_mediaplayer_state_transform(state);
        }
			break;
        default:
            ASSERT(0);
    }

}

void vadp_shell_mediaplayer_player_set_shuffle(VfxBool shuf)
{
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
#else
    mmi_medply_settings_write_value_ext(MMI_MEDPLY_SETTINGS_SHUFFULE, &shuf,MMI_FALSE); 
#endif
}

void vadp_shell_mediaplayer_player_sync_shuffle_with_medply(VfxBool shuf)
{  
#if 0
/* under construction !*/
#endif
}

VfxBool vadp_shell_mediaplayer_player_is_shuffle()
{
    U8 shuf;
    mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_SHUFFULE, &shuf);
    if (shuf == 1)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

void vadp_shell_mediaplayer_player_set_repeat_mode(vadp_shell_mediaplayer_repeat_mode_enum  repeat_mode)
{
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
#else
    mmi_medply_settings_repeat_enum r = MMI_MEDPLY_SETTINGS_REPEAT_OFF;

    if (repeat_mode == VADP_SHELL_MEDIAPLAYER_REPEAT_ONE)
    {
        r = MMI_MEDPLY_SETTINGS_REPEAT_ONE;
    }
    else if (repeat_mode == VADP_SHELL_MEDIAPLAYER_REPEAT_ALL)
    {
        r = MMI_MEDPLY_SETTINGS_REPEAT_ALL;
    }
    else if (repeat_mode == VADP_SHELL_MEDIAPLAYER_REPEAT_OFF)
    {
        r = MMI_MEDPLY_SETTINGS_REPEAT_OFF;
    }
    else
    {
        ASSERT(0);
    }
    
    mmi_medply_settings_write_value_ext(MMI_MEDPLY_SETTINGS_REPEAT, &r,MMI_FALSE);
#endif

}

vadp_shell_mediaplayer_repeat_mode_enum vadp_shell_mediaplayer_player_get_repeat_mode()
{
    mmi_medply_settings_repeat_enum repeat;
    U8  r;    
    vadp_shell_mediaplayer_repeat_mode_enum ret = VADP_SHELL_MEDIAPLAYER_REPEAT_OFF;
    mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_REPEAT, &r);

    repeat = (mmi_medply_settings_repeat_enum) r;
    switch (repeat)
    {
        case MMI_MEDPLY_SETTINGS_REPEAT_ALL:
            ret = VADP_SHELL_MEDIAPLAYER_REPEAT_ALL;
            break;
        case MMI_MEDPLY_SETTINGS_REPEAT_ONE:
            ret = VADP_SHELL_MEDIAPLAYER_REPEAT_ONE;
            break;
        case MMI_MEDPLY_SETTINGS_REPEAT_OFF:
            ret = VADP_SHELL_MEDIAPLAYER_REPEAT_OFF;
            break;
        default:
            ASSERT(0);
            break;
    }

    return ret;
}

void vadp_shell_mediaplayer_player_sync_repeat_mode_to_medply(vadp_shell_mediaplayer_repeat_mode_enum  repeat_mode)
{
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
#endif    

}


VfxU8 vadp_shell_mediaplayer_player_get_volume()
{
	VfxU8 v;
	mmi_medply_widget_get_value(MMI_WIDGET_PLAYER_VOL,(void*) &v);
	return v;
}

void vadp_shell_mediaplayer_player_set_volume(VfxU8 volume)
{
	mmi_medply_widget_set_value(MMI_WIDGET_PLAYER_VOL,(void*)&volume);
}

#if defined(__MMI_AVRCP_SUPPORT__)
VfxU8(*g_avrcp_callback)(void*, VfxU8, mmi_avrcp_key_events);
void* g_userdata;

//VfxU8 vadp_shell_avrcp_callback_hdlr(VfxU8 command, mmi_avrcp_key_events event)
U8 vadp_shell_avrcp_callback_hdlr(U8 command, mmi_avrcp_key_events event)
{
    if (g_avrcp_callback!=NULL)
        return (U8)g_avrcp_callback(g_userdata, (VfxU8)command, event);
    else
        return MMI_AVRCP_CR_ACCEPT;
}
void vadp_shell_mediaplayer_player_avrcp_callback(void *userdata, VfxU8(*callback)(void*, VfxU8, mmi_avrcp_key_events))
{
    g_userdata = userdata;
    g_avrcp_callback = callback;

    if (callback == NULL)
    {
        mmi_bt_avrcp_clear_cmd_hdlr((AVRCPCmdFuncPtr)vadp_shell_avrcp_callback_hdlr);
    }
    else
    {
        mmi_bt_avrcp_set_cmd_hdlr((AVRCPCmdFuncPtr)vadp_shell_avrcp_callback_hdlr);
    }
}
#endif 

/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_player_register_callback
 * DESCRIPTION
 *  Register callback function.
 * PARAMETERS
 *  userdata        [IN]        C++ this pointer
 *  callback        [IN]        Callback function
 * RETURNSa
 *  void
 *****************************************************************************/
void vadp_shell_mediaplayer_player_register_callback(void *userdata, void(*callback)(void*, VfxU32, void*))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_widget_register_callbacks(userdata, (void (*)(void *, mmi_widget_player_callback_enum, void*))callback);
}

/*****************************************************************************
 * FUNCTION
 *  vadp_shell_mediaplayer_deregister_callback
 * DESCRIPTION
 *  De-register callback function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_shell_mediaplayer_deregister_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_widget_register_callbacks(NULL, (void (*)(void *, mmi_widget_player_callback_enum, void*))NULL);

}


void vadp_shell_mediaplayer_player_play(void)
{
    mmi_medply_widget_button_action(MMI_WIDGET_PLAYER_PLAY_PAUSE,MMI_WIDGET_PLAYER_KEY_DOWN);
    mmi_medply_widget_button_action(MMI_WIDGET_PLAYER_PLAY_PAUSE,MMI_WIDGET_PLAYER_KEY_UP);
}

void vadp_shell_mediaplayer_player_pause(void)
{
    mmi_medply_widget_button_action(MMI_WIDGET_PLAYER_PLAY_PAUSE,MMI_WIDGET_PLAYER_KEY_DOWN);
    mmi_medply_widget_button_action(MMI_WIDGET_PLAYER_PLAY_PAUSE,MMI_WIDGET_PLAYER_KEY_UP);
}

void vadp_shell_mediaplayer_player_stop(void)
{
    mmi_medply_widget_button_action(MMI_WIDGET_PLAYER_STOP,MMI_WIDGET_PLAYER_KEY_DOWN);
    mmi_medply_widget_button_action(MMI_WIDGET_PLAYER_STOP,MMI_WIDGET_PLAYER_KEY_UP);
}


S32 vadp_shell_mediaplayer_player_previous(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_widget_button_action(MMI_WIDGET_PLAYER_PREV,MMI_WIDGET_PLAYER_KEY_DOWN);
    mmi_medply_widget_button_action(MMI_WIDGET_PLAYER_PREV,MMI_WIDGET_PLAYER_KEY_UP);
    return vadp_shell_mediaplayer_get_active_index();
}

S32 vadp_shell_mediaplayer_player_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_widget_button_action(MMI_WIDGET_PLAYER_NEXT,MMI_WIDGET_PLAYER_KEY_DOWN);
    mmi_medply_widget_button_action(MMI_WIDGET_PLAYER_NEXT,MMI_WIDGET_PLAYER_KEY_UP);
    return vadp_shell_mediaplayer_get_active_index();
    
}
#endif /* __MMI_VUI_SHELL_MEDIA_PLAYER__ */
