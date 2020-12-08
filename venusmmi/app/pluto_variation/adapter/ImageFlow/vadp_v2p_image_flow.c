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
 *  vadp_v2p_media_player.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  .
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
//#include "MMI_include.h"

#ifdef __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__
#include "MMIDataType.h"
#include "PlstSrvGprot.h"
//#include "MediaplayerGProt.h"
#include "MediaPlayerProt.h"
//#include "MediaPlayerEnumDef.h"
#include "vadp_v2p_image_flow.h"
#include "mmi_rp_app_imageflow_def.h"
/* media cache  engine header files */
//#include "math.h"
//#include "ctype.h"
//#include "FileManagerGProt.h"
//#include "FileMgr.h"
//#include "FileMgrServiceHdlr.h"
//#include "Gdi_util.h"
#include "MMIDataType.h"
//#include "custom_events_notify.h"
#include "med_api.h"
#include "gdi_datatype.h"
#include "vfx_datatype.h"
#include "kal_general_types.h"
#include "gdi_const.h"
#include "string.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "gdi_include.h"
#include "meta_tag_api.h"
#include "FileMgrSrvGProt.h"
#include "Unicodexdcl.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_util.h"
#include "AlertScreen.h"
#include "MediaCacheSrvMem.h"
#include "gdi_imgdec.h"
#include "lcd_sw_inc.h"

#include "MediaCacheSrvGprot.h"
#if defined(__SQLITE3_SUPPORT__)
#include "..\..\..\applib\sqlite3\inc\sqlite3.h"
#include "..\..\..\applib\sqlite3\inc\sqlite3ex.h"
#include "ImageViewerDaemonGprot.h"
#endif /* defined(__SQLITE3_SUPPORT__) */ 
#include "MediaCacheSrv.h"

/***********************************************************
 *  Debug_ex info
 ************************************************************/
//#define __IMGFLOW_CP_PERF_TEST
#undef __IMGFLOW_CP_PERF_TEST
//#define __IMGFLOW_PERF_MONITOR 
#undef __IMGFLOW_PERF_MONITOR

#ifdef __IMGFLOW_PERF_MONITOR
static S32 _time_b, _time_e;

#define PERF_MONITOR_BEGIN(x)            do{\
    kal_get_time(&_time_b);                 \
}while(0)

#define PERF_MONITOR_END(x)              do{\
    kal_get_time(&_time_e);                 \
    IMGFLOW_TRACE2(                         \
    VAPP_TRACE_IMAGEFLOW_DURATION,  \
    x, _time_e - _time_b);                  \
}while(0)
#else
#define PERF_MONITOR_BEGIN(x)
#define PERF_MONITOR_END(x)
#endif /*__IMGFLOW_PERF_MONITOR*/


/***********************************************************
*  define
************************************************************/
#define IMGFLOW_HAS_MEMORY_ALLOC            0x00000001
#define IMGFLOW_HAS_LIST_SRV_INIT           0x00000002
#define IMGFLOW_HAS_CACHE_SRV_INIT          0x00000004
#define IMGFLOW_CACHE_SRV_HAS_START         0x00000004

#define IMGFLOW_CELL_BORDER_COLOR   gdi_act_color_from_rgb(255, 120, 120, 120)


/***********************************************************
 *  structure declearation
 ************************************************************/
typedef struct
{
    srv_mediacache_cell_struct*  cache_cell_p;
    gdi_handle  cache_layer;
    gdi_handle  decode_handle;
    void*       user_data;
}vapp_imgflow_cache_engine_struct;

typedef struct
{
    gdi_handle temp_layer;
    S32  cell_size;
    S32  focus_index;
    S32* cache_srv_hdl;
    U8*  large_med_hdlr;
    U8*  cell_med_hdlr;
    U8*  temp_image_buff;
    U8*  runbuf;
    U8*  strbuf;
}vapp_imgflow_cache_info_struct;


typedef struct
{
    vapp_imgflow_cache_info_struct   cache_info;
    srv_plst_list_get_display_struct artwork_para;
#if 0 //def MOTION_SENSOR_SUPPORT
/* under construction !*/
#endif
    U32   flag;
    S32   last_error;
    U32   count;
    S32   curr_cache_index;
    void  (*imageflow_callback)(void* user_data, S32 index);
    void* imageflow_userdata;
    U8*   def_image_buf;
    U8    state;
}vapp_imgflow_info_struct;


vapp_imgflow_skin_struct g_image_flow_skin_layout =
{
    VAPP_IMG_IMAGE_FLOW_BG,
    /* 240 X 320*/
#ifdef __MMI_MAINLCD_240X320__
    5, 29, 310, 230,
    0, 25, 20,
#if VAPP_IMAGE_FLOW_REFLECTED_ENABLE
    113, 113, 
    60, 
    40, 50,
#else
    113, 113, 
    60, 
    40, 50,
#endif /* VAPP_IMAGE_FLOW_REFLECTED_ENABLE */

    VAPP_IMG_COVER_FLOW_PLAY,    //lsk
    282, 208, 32, 26,
    VAPP_IMG_COVER_FLOW_BACK,    //rsk
    282, 5, 32, 26,
    60, 190, 200, 20,                //title
    60, 216, 200, 20,                //artist
    VAPP_IMG_IMAGE_FLOW_HL_IMG, //high light
    46, 47

    /* 240 X 400*/
#elif defined(__MMI_MAINLCD_240X400__)
    10, 30, 380, 210,
    0, 25, -18,
#if VAPP_IMAGE_FLOW_REFLECTED_ENABLE
    126, 126, 
    80, 
    50, 128,
#else
    120, 120, 
    68, 
    40, 128,
#endif /* VAPP_IMAGE_FLOW_REFLECTED_ENABLE */
    VAPP_IMG_COVER_FLOW_PLAY,    //lsk
    362, 209, 32, 26,
    VAPP_IMG_COVER_FLOW_BACK,    //rsk
    362, 6, 32, 26,    
    50, 200, 300, 20,               //title
    50, 223, 300, 15,               //artist
    VAPP_IMG_IMAGE_FLOW_HL_IMG, //high light
    46, 47

    /* 320 X 480*/
#elif defined(__MMI_MAINLCD_320X480__)
    10, 44, 460, 276,
    0,  30, -6,
#if VAPP_IMAGE_FLOW_REFLECTED_ENABLE
    150,150,
    100,
    60,128,
#else
    150,150,
    80,
    40,128,
#endif
    VAPP_IMG_COVER_FLOW_PLAY,    //lsk
    431, 275, 43, 39, 
    VAPP_IMG_COVER_FLOW_BACK,    //rsk
    431, 6, 43, 39,   
    60, 266, 360, 20,                 //title
    60, 290, 360, 20,               //artist
    VAPP_IMG_IMAGE_FLOW_HL_IMG, //high light
    79, 79
/* 320 X 240*/
#elif defined(__MMI_MAINLCD_320X240__)
    5, 29, 310, 230,
    0, 25, 20,
#if VAPP_IMAGE_FLOW_REFLECTED_ENABLE
    113, 113, 
    60, 
    40, 50,
#else
    113, 113, 
    60, 
    40, 50,
#endif /* VAPP_IMAGE_FLOW_REFLECTED_ENABLE */

    VAPP_IMG_COVER_FLOW_PLAY,    //lsk
    6, 208, 32, 26,
    VAPP_IMG_COVER_FLOW_BACK,    //rsk
    282, 208, 32, 26,
    60, 190, 200, 20,                //title
    60, 216, 200, 20,                //artist
    VAPP_IMG_IMAGE_FLOW_HL_IMG, //high light
    46, 47
#endif
};

/***********************************************************
*  global varible declearation
************************************************************/
static vapp_imgflow_cache_engine_struct g_cache_engin_cntx;
/*extern from media cache engin*/
extern srv_mediacache_cntx_struct *g_mediacache_cntx_p;
static vapp_imgflow_info_struct         g_imgflow_cntx;


/***********************************************************
*  MACRO
************************************************************/
#define IMGFLOW_STATE_CHANGE(x, y)                       do{\
    IMGFLOW_TRACE3(                                         \
    VAPP_TRACE_IMAGEFLOW_INFO_STATE_CHANGE,   \
    g_imgflow_cntx.state, x,  y);                           \
    g_imgflow_cntx.state = (x);                             \
}while(0)

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
#endif

/***********************************************************
*  static function declearation
************************************************************/
static S32 vadp_v2p_imgflow_listsrv_init(void);
static S32 vadp_v2p_imgflow_listsrv_deinit(void);
static S32 vadp_v2p_imgflow_get_data_from_db(VfxS32 index);
static void vadp_v2p_imgflow_decode_done(VfxS32 result);
static void vadp_v2p_imgflow_cancel_get_data(void);
static void vadp_v2p_imgflow_get_album_cover_cb(S32 err_group, S32 err_code, void *user_data);

/* cache service adaption*/
static S32 vadp_v2p_imgflow_memory_alloc(void);
static S32 vadp_v2p_imgflow_memory_free(void);
static S32 vadp_v2p_imgflow_cachesrv_init(void);
static S32 vadp_v2p_imgflow_cachesrv_deinit(void);
static S32 vadp_v2p_imgflow_cachesrv_start(void);
static void vadp_v2p_imgflow_cachesrv_stop(void);

/*cache engine for image flow*/
static S32 srv_mediacache_imgflow_get_data_cb(S32 index, WCHAR *buffer, U32 length, void *user_data);
static MMI_BOOL srv_mediacache_imgflow_get_raw_data(
                    U32 *handle, 
                    srv_mediacache_cell_struct *cell_p, 
                    srv_mediacache_nb_decode_callback done_callback, void *user_data
                    );
static MMI_BOOL srv_mediacache_imgflow_nb_decode(S32 ret, U8* img_buf, S32 img_width, S32 img_height, S32 size);
static void srv_mediacache_imgflow_decode_done_cb(GDI_RESULT result,gdi_handle handle);
static MMI_BOOL srv_mediacache_imgflow_decode_cancel(U32 handle);
static S32 srv_mediacache_get_org_info(srv_handle handle, S32* w, S32* h);



#define EXT_INTERFACE
/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cf_init_db_srv
 * DESCRIPTION
 *  do int and start media cache service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vadp_v2p_imgflow_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_imgflow_cntx, 0 , sizeof(vapp_imgflow_info_struct));

    /* init list service and register callback */
    g_imgflow_cntx.last_error = vadp_v2p_imgflow_listsrv_init();
    if (VAPP_IMGFLOW_ERR_NONE == g_imgflow_cntx.last_error)
    {
        g_imgflow_cntx.flag |= IMGFLOW_HAS_LIST_SRV_INIT;
    }
    else
    {
        vadp_v2p_imgflow_listsrv_deinit();
        return g_imgflow_cntx.last_error;
    }
    
    /*Allocate memory*/
    g_imgflow_cntx.last_error = vadp_v2p_imgflow_memory_alloc();
    if (VAPP_IMGFLOW_ERR_NONE == g_imgflow_cntx.last_error)
    {
        g_imgflow_cntx.flag |= IMGFLOW_HAS_MEMORY_ALLOC;
    }
    else
    {
        vadp_v2p_imgflow_memory_free();
        return g_imgflow_cntx.last_error;
    }

    /* init cache service */
    g_imgflow_cntx.last_error = vadp_v2p_imgflow_cachesrv_init();
    if (VAPP_IMGFLOW_ERR_NONE == g_imgflow_cntx.last_error)
    {
        g_imgflow_cntx.flag |= IMGFLOW_HAS_CACHE_SRV_INIT;
    }
    else
    {
        vadp_v2p_imgflow_cachesrv_deinit();
        return g_imgflow_cntx.last_error;
    }

    /* Init context*/
    IMGFLOW_STATE_CHANGE(VAPP_IMGFLOW_STATE_INITED, __LINE__);
    g_imgflow_cntx.curr_cache_index = -1;

    return VAPP_IMGFLOW_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_imgflow_shutdown
 * DESCRIPTION
 *  deinit image flow
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vadp_v2p_imgflow_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_medply_listui_exit_image_flow();
    
    if (g_imgflow_cntx.flag & IMGFLOW_HAS_CACHE_SRV_INIT)
    {
        vadp_v2p_imgflow_cachesrv_deinit();
    }
    if (g_imgflow_cntx.flag & IMGFLOW_HAS_MEMORY_ALLOC)
    {
        vadp_v2p_imgflow_memory_free();
    }
    if (g_imgflow_cntx.flag & IMGFLOW_HAS_MEMORY_ALLOC)
    {
        vadp_v2p_imgflow_listsrv_deinit();
    }
    //mmi_medply_listui_imgflow_set_focus_idx(g_imgflow_cntx.cache_info.focus_index);

    memset(&g_imgflow_cntx, 0 , sizeof(vapp_imgflow_info_struct));
    
    return VAPP_IMGFLOW_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_imgflow_shutdown
 * DESCRIPTION
 *  deinit image flow
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vadp_v2p_imgflow_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(VAPP_IMGFLOW_STATE_INITED == g_imgflow_cntx.state);

    PERF_MONITOR_BEGIN(__LINE__);
    g_imgflow_cntx.last_error = vadp_v2p_imgflow_cachesrv_start();
    PERF_MONITOR_END(__LINE__);
    if (VAPP_IMGFLOW_ERR_NONE == g_imgflow_cntx.last_error)
    {
        IMGFLOW_STATE_CHANGE(VAPP_IMGFLOW_STATE_READY, __LINE__);
    }    
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* MOTION_SENSOR_SUPPORT */

    return g_imgflow_cntx.last_error;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_imgflow_shutdown
 * DESCRIPTION
 *  deinit image flow
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vadp_v2p_imgflow_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_imgflow_cntx.state >= VAPP_IMGFLOW_STATE_READY);

#if 0 //def MOTION_SENSOR_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* MOTION_SENSOR_SUPPORT */
    PERF_MONITOR_BEGIN(__LINE__);
    vadp_v2p_imgflow_cachesrv_stop();
    PERF_MONITOR_END(__LINE__);
    IMGFLOW_STATE_CHANGE(VAPP_IMGFLOW_STATE_INITED, __LINE__); 
    
    return VAPP_IMGFLOW_ERR_NONE;
}

#if 0 //def MOTION_SENSOR_SUPPORT
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
#endif /* MOTION_SENSOR_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cf_register_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_imgflow_reg_callback(void* user_data, void(*callback)(void* user_data, VfxS32 index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgflow_cntx.imageflow_callback = callback;
    g_imgflow_cntx.imageflow_userdata = user_data;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cf_register_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_imgflow_unreg_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgflow_cntx.imageflow_callback = NULL;
    g_imgflow_cntx.imageflow_userdata = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_imgflow_listsrv_callback
 * DESCRIPTION
 *  Database callback after get image data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vadp_v2p_imgflow_listsrv_callback(srv_plst_cb_evt_enum cb_event, S32 result, U32 ca_para_2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret, w, h, img_size;
    U8* ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMGFLOW_TRACE3(VAPP_TRACE_IMAGEFLOW_FETCH_RAW_DATA, 
                   g_imgflow_cntx.curr_cache_index, result, g_imgflow_cntx.artwork_para.buff_size);
    if (SRV_PLST_CB_EVT_GET_IMAGE != cb_event)
    {
        return 0;
    }
    if (VAPP_IMGFLOW_STATE_LOADING != g_imgflow_cntx.state)
    {
        return 0;
    }

    if(g_imgflow_cntx.curr_cache_index != ca_para_2)
    {
        return 0;
    }

    if (SRV_PLST_OK == result)
    {
        if (g_imgflow_cntx.artwork_para.buff_size > 0)
        {
            PERF_MONITOR_BEGIN(__LINE__);
            ret = gdi_image_get_dimension_mem(GDI_IMAGE_TYPE_JPG, 
                                              g_imgflow_cntx.cache_info.temp_image_buff, 
                                              g_imgflow_cntx.artwork_para.buff_size,
                                              &w, &h);
            IMGFLOW_TRACE3(VAPP_TRACE_IMAGEFLOW_GET_DIMENSION, 
                           ret, w, h);
            PERF_MONITOR_END(__LINE__);
            if (ret >= 0)
            {
                //kal_printf("[IMG_FLOW]DB calback: get valid image\n");
                img_size = g_imgflow_cntx.artwork_para.buff_size;
                ptr = g_imgflow_cntx.cache_info.temp_image_buff;
                PERF_MONITOR_BEGIN(__LINE__);
                if (srv_mediacache_imgflow_nb_decode(0, ptr, w, h, img_size))
                {
                    IMGFLOW_TRACE2(VAPP_TRACE_IMAGEFLOW_BEGIN_TO_DECODE, 
                                   g_imgflow_cntx.curr_cache_index, result);
                    IMGFLOW_STATE_CHANGE(VAPP_IMGFLOW_STATE_DECODING, __LINE__);
                }
                else
                {
                    IMGFLOW_TRACE0(VAPP_TRACE_IMAGEFLOW_DECORDE_ERROR);
                    IMGFLOW_STATE_CHANGE(VAPP_IMGFLOW_STATE_READY, __LINE__);
                }
                PERF_MONITOR_END(__LINE__);
                return 0;
            }
        }        
    }  

    PERF_MONITOR_BEGIN(__LINE__);
    srv_mediacache_imgflow_nb_decode(-1, NULL, 0, 0, 0);
    PERF_MONITOR_END(__LINE__);
    IMGFLOW_STATE_CHANGE(VAPP_IMGFLOW_STATE_READY, __LINE__);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cf_get_album_number
 * DESCRIPTION
 *  get album number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vadp_v2p_imgflow_get_focus_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (VAPP_IMGFLOW_STATE_NULL == g_imgflow_cntx.state)
    {
        return 0;
    }
    else
    {
        return g_imgflow_cntx.cache_info.focus_index;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  Vadp_v2p_cf_set_focus_index
 * DESCRIPTION
 *  set current focus index
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vadp_v2p_imgflow_set_focus_index(VfxS32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMGFLOW_TRACE1(VAPP_TRACE_IMAGEFLOW_SET_FOCUS_INDEX, index);
    mmi_medply_listui_imgflow_set_focus_idx(index);
#ifndef __IMGFLOW_CP_PERF_TEST
    if (NULL != g_imgflow_cntx.cache_info.cache_srv_hdl)
    {
        PERF_MONITOR_BEGIN(__LINE__);
        srv_mediacache_goto_index(g_imgflow_cntx.cache_info.cache_srv_hdl, index);
        PERF_MONITOR_END(__LINE__);
        g_imgflow_cntx.cache_info.focus_index = index;
        return VAPP_IMGFLOW_ERR_NONE;        
    }
#endif /* __IMGFLOW_CP_PERF_TEST */    
    return VAPP_IMGFLOW_ERR_CACHESRV_INVALID;    
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cf_get_album_number
 * DESCRIPTION
 *  get album number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vadp_v2p_imgflow_get_album_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (VAPP_IMGFLOW_STATE_NULL == g_imgflow_cntx.state)
    {
        return 0;
    }
    else
    {
        return g_imgflow_cntx.count;
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
#ifndef __IMGFLOW_CP_PERF_TEST
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
/* under construction !*/
/* under construction !*/
#endif /* __IMGFLOW_CP_PERF_TEST */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cf_get_album_info
 * DESCRIPTION
 *  get album info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vadp_v2p_imgflow_get_album_info(VfxS32 index, vapp_imgflow_album_info_enum type, VfxWChar* str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_get_display_struct temp_info;
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_info.index = index;
    
    switch (type)
    {
    case VAPP_IMGFLOW_INFO_TITLE:
        temp_info.buff_size = SRV_PLST_META_INFO_MAX_LEN;
        temp_info.string_ptr = (U32)str;
        ret = mmi_medply_listui_imgflow_get_item_name(&temp_info);
        break;

    case VAPP_IMGFLOW_INFO_ARTIST:
        temp_info.buff_size = SRV_PLST_MAX_PATH_LEN;
        temp_info.string_ptr = (U32)g_imgflow_cntx.cache_info.strbuf;
        ret = mmi_medply_listui_imgflow_get_artist(&temp_info);
        if (SRV_PLST_OK == ret)
        {
            mmi_ucs2ncpy((U8*) str, (U8*) g_imgflow_cntx.cache_info.strbuf, SRV_PLST_META_INFO_MAX_LEN);
        }
        break;

    default:
        ret = VAPP_IMGFLOW_ERR_PARA;
        break;
    }

    if (ret != SRV_PLST_OK)
    {
        return VAPP_IMGFLOW_ERR_PLST_QUERY_FAIL;
    }    

    return VAPP_IMGFLOW_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cf_get_album_cover
 * DESCRIPTION
 *  get cover image from plst service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxU8* vadp_v2p_imgflow_get_def_cover(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle layer = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(NULL != g_imgflow_cntx.def_image_buf);
    gdi_layer_create_using_outside_memory(
            0, 0,
            g_image_flow_skin_layout.cell_focus_w,
            g_image_flow_skin_layout.cell_focus_h,
            &layer,
            g_imgflow_cntx.def_image_buf,
            g_image_flow_skin_layout.cell_focus_w * 
            g_image_flow_skin_layout.cell_focus_h * 2);

    ASSERT(0 != layer);
    gdi_layer_push_and_set_active(layer);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_image_draw_resized_id(0,0,
                              g_image_flow_skin_layout.cell_focus_w, 
                              g_image_flow_skin_layout.cell_focus_h, 
                              VAPP_IMG_IMAGE_FLOW_DEF_COVER);
    gdi_layer_pop_and_restore_active();
    gdi_layer_free(layer);

    return g_imgflow_cntx.def_image_buf;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cf_get_album_cover
 * DESCRIPTION
 *  get cover image from plst service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vadp_v2p_imgflow_get_album_cover(VfxS32 index, VfxU8* buf, VfxS32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret,w,h;
    srv_mediacache_img_to_layer_struct area; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMGFLOW_TRACE2(VAPP_TRACE_IMAGEFLOW_GET_VCP_QUERY_INDEX, index, g_imgflow_cntx.state);

    ASSERT(NULL != buf);
    if (g_imgflow_cntx.state < VAPP_IMGFLOW_STATE_READY)
    {
        return VAPP_IMGFLOW_ERR_CACHESRV_INVALID;
    }
    
    PERF_MONITOR_BEGIN(__LINE__);
    srv_mediacache_goto_index(g_imgflow_cntx.cache_info.cache_srv_hdl, index);
    ret = srv_mediacache_get_org_info(g_imgflow_cntx.cache_info.cache_srv_hdl, &w, &h);
    PERF_MONITOR_END(__LINE__);
    if (SRV_MEDIACACHE_OK == ret)
    {
        area.src.width = w- 1;
        area.src.height = h - 1;
    }
    else
    {
        area.src.width = -1;
        area.src.height = -1;    
    }

    if (g_imgflow_cntx.cache_info.temp_layer)
    {
        gdi_layer_free(g_imgflow_cntx.cache_info.temp_layer);
        g_imgflow_cntx.cache_info.temp_layer = 0;
    }
    
    area.src.x = 0;
    area.src.y = 0;
    //area.dst.x = 0;    
    //area.dst.y = 0;
    area.dst.x = 1;
    area.dst.y = 1;
    area.dst.width  = g_image_flow_skin_layout.cell_focus_w - 1 - 2;
    area.dst.height = g_image_flow_skin_layout.cell_focus_h - 1 - 2;
    area.user_data  = g_imgflow_cntx.imageflow_userdata;
    area.callback   = vadp_v2p_imgflow_get_album_cover_cb;
    gdi_layer_create_using_outside_memory(
            0, 0,
            g_image_flow_skin_layout.cell_focus_w,
            g_image_flow_skin_layout.cell_focus_h,
            &g_imgflow_cntx.cache_info.temp_layer,
            buf,
            g_image_flow_skin_layout.cell_focus_w * 
            g_image_flow_skin_layout.cell_focus_h * 2);  
    ASSERT(g_imgflow_cntx.cache_info.temp_layer != 0);
    area.dst_layer = g_imgflow_cntx.cache_info.temp_layer;  

    gdi_layer_push_and_set_active(g_imgflow_cntx.cache_info.temp_layer);
    gdi_layer_clear(IMGFLOW_CELL_BORDER_COLOR);
    gdi_layer_pop_and_restore_active();
    
    PERF_MONITOR_BEGIN(__LINE__);
    ret = srv_mediacache_get_curr_img_to_layer(g_imgflow_cntx.cache_info.cache_srv_hdl, &area);
    srv_mediacache_goto_index(g_imgflow_cntx.cache_info.cache_srv_hdl, g_imgflow_cntx.cache_info.focus_index);
    PERF_MONITOR_END(__LINE__);
    if (SRV_MEDIACACHE_OK == ret)
    {
        IMGFLOW_TRACE0(VAPP_TRACE_IMAGEFLOW_GET_IMAGE_DIRECTLY);
        return VAPP_IMGFLOW_ERR_NONE;
    }

    /*no cache, draw default cover image*/   
    if (flag > 0)
    {
        IMGFLOW_TRACE0(VAPP_TRACE_IMAGEFLOW_FAIL_TO_GET_IMAGE);
        gdi_layer_push_and_set_active(g_imgflow_cntx.cache_info.temp_layer);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        ret = gdi_image_draw_resized_id(0,0,
                                        g_image_flow_skin_layout.cell_focus_w, 
                                        g_image_flow_skin_layout.cell_focus_h, 
                                        VAPP_IMG_IMAGE_FLOW_DEF_COVER);
        gdi_layer_pop_and_restore_active();
    }        
    return VAPP_IMGFLOW_ERR_NO_VALID_COVER;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cf_play
 * DESCRIPTION
 *  begin play
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vadp_v2p_imgflow_play_album(VfxS32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_medply_listui_imgflow_play((U32)index))
    {
        return VAPP_IMGFLOW_ERR_NONE;
    }
    else
    {
        return VAPP_IMGFLOW_ERR_PLAY_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_imgflow_lock_image_buffer
 * DESCRIPTION
 *  begin play
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vadp_v2p_imgflow_lock_image_buffer(S32 index, void** buffer, S32* w, S32* h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vapp_imgflow_cache_info_struct* cache_info = &g_imgflow_cntx.cache_info;
    srv_mediacache_lock_img_buffer_addr_struct  lock_img;
    srv_mediacache_get_img_info_struct          image_info;
    S32 ret;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMGFLOW_TRACE2(VAPP_TRACE_IMAGEFLOW_VCP_QUERY_INDEX, index, g_imgflow_cntx.state);
    
    if (NULL == cache_info->cache_srv_hdl)
    {
        return VAPP_IMGFLOW_ERR_CACHESRV_INVALID;
    }
#if 0        
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif   

    lock_img.callback = NULL;
    lock_img.user_data = NULL;
    lock_img.source = SRV_MEDIACACHE_IMAGE_SOURCE_CACHE;
    
    ret = srv_mediacache_lock_img_buffer_addr(cache_info->cache_srv_hdl, index, &lock_img);
    IMGFLOW_TRACE1(VAPP_TRACE_IMAGEFLOW_LOCK_FRAME_BUF, ret);
    if (SRV_MEDIACACHE_OK == ret)
    {
        *buffer = lock_img.buffer;
        g_imgflow_cntx.last_error = VAPP_IMGFLOW_ERR_NONE;
        ret = srv_mediacache_get_image_info(cache_info->cache_srv_hdl, index, &image_info);
        ASSERT(SRV_MEDIACACHE_OK == ret);
        *w = image_info.resized_height;
        *h = image_info.resized_width;
    }
    else if (ret < SRV_MEDIACACHE_OK)
    {
        g_imgflow_cntx.last_error = VAPP_IMGFLOW_ERR_NO_VALID_COVER;
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    srv_mediacache_goto_index(cache_info->cache_srv_hdl, g_imgflow_cntx.cache_info.focus_index);
    return g_imgflow_cntx.last_error;

}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_imgflow_unlock_image_buffer
 * DESCRIPTION
 *  begin play
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_imgflow_unlock_image_buffer(S32 index, void* buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vapp_imgflow_cache_info_struct* cache_info = &g_imgflow_cntx.cache_info;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == cache_info->cache_srv_hdl)
    {
        return ;
    }
    IMGFLOW_TRACE1(VAPP_TRACE_IMAGEFLOW_UNLOCK_FRAME_BUF,index);
    
    srv_mediacache_unlock_img_buffer(cache_info->cache_srv_hdl, buffer);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_imgflow_popup_error
 * DESCRIPTION
 *  begin play
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vadp_v2p_imgflow_popup_error(MMI_ID parent_id, S32 error_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = STR_GLOBAL_ERROR;
    mmi_event_notify_enum event_type = MMI_EVENT_FAILURE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMGFLOW_TRACE1( VAPP_TRACE_IMAGEFLOW_POPUP_ERROR, error_id);

    if ((error_id > SRV_PLST_RET_ERR_BEGIN) && (error_id < SRV_PLST_RET_END))
    {
        str_id = srv_plst_get_error_string(error_id, &event_type);
    }

    mmi_popup_display_simple((WCHAR*)get_string(str_id), event_type, parent_id, NULL);
}


#define LIST_SERVICE_ADPTION
/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_imgflow_listsrv_init
 * DESCRIPTION
 *  init plst service.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 vadp_v2p_imgflow_listsrv_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_medply_listui_imgflow_listsrv_init(vadp_v2p_imgflow_listsrv_callback))
    {
        return VAPP_IMGFLOW_ERR_LISTSRV_INVALID;
    }    

    ret = mmi_medply_listui_imgflow_get_count(&g_imgflow_cntx.count);
    /*if (0 == g_imgflow_cntx.count || ret < 0)
    {
        return VAPP_IMGFLOW_ERR_LIST_INVALID;
    }*/
    if (ret < 0)
    {
        return ret;
    }
    else if (0 == g_imgflow_cntx.count)
    {
        return VAPP_IMGFLOW_ERR_LIST_INVALID;
    }
    g_imgflow_cntx.cache_info.focus_index = mmi_medply_listui_imgflow_get_focus_idx();
    if (g_imgflow_cntx.cache_info.focus_index >= g_imgflow_cntx.count)
    {
        return VAPP_IMGFLOW_ERR_LIST_INVALID;
    }
    return VAPP_IMGFLOW_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_imgflow_listsrv_init
 * DESCRIPTION
 *  init plst service.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 vadp_v2p_imgflow_listsrv_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_listui_imgflow_listsrv_deinit();
    return VAPP_IMGFLOW_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_imgflow_get_data_from_db
 * DESCRIPTION
 *  get cover image from plst service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 vadp_v2p_imgflow_get_data_from_db(VfxS32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgflow_cntx.curr_cache_index = index;
    g_imgflow_cntx.artwork_para.index = (U32)index;
    g_imgflow_cntx.artwork_para.buff_size = SRV_CACHE_BIG_IMAGE_CACHE;
    g_imgflow_cntx.artwork_para.string_ptr = (U32)g_imgflow_cntx.cache_info.temp_image_buff;
  
    g_imgflow_cntx.last_error = mmi_medply_listui_imgflow_get_artwork_aync(&g_imgflow_cntx.artwork_para);
    if (SRV_PLST_ASYNC == g_imgflow_cntx.last_error)
    {
        ASSERT(VAPP_IMGFLOW_STATE_READY == g_imgflow_cntx.state);
        IMGFLOW_STATE_CHANGE(VAPP_IMGFLOW_STATE_LOADING, __LINE__);
    }
    else if (SRV_PLST_OK == g_imgflow_cntx.last_error)
    {
        ASSERT(0);
    }

    IMGFLOW_TRACE2(VAPP_TRACE_IMAGEFLOW_QUERY_RAW_DATA, index, g_imgflow_cntx.last_error);
    return g_imgflow_cntx.last_error;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cf_image_decode_done
 * DESCRIPTION
 *  get cover image from plst service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vadp_v2p_imgflow_decode_done(VfxS32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMGFLOW_TRACE3(VAPP_TRACE_IMAGEFLOW_DECODE_DONE,
                   result,  g_imgflow_cntx.curr_cache_index, g_imgflow_cntx.state);
    
    if (VAPP_IMGFLOW_STATE_DECODING != g_imgflow_cntx.state)
    {
        return;
    }    
    if (NULL == g_imgflow_cntx.imageflow_callback)
    {
        return;
    }

    IMGFLOW_STATE_CHANGE(VAPP_IMGFLOW_STATE_READY, __LINE__);
    
    if (0 == result)
    {
        gdi_layer_push_and_set_active(g_cache_engin_cntx.cache_layer);
        gdi_layer_reset_clip();
        gdi_layer_get_clip(&x1, &y1, &x2, &y2);
        gdi_draw_rect(x1, y1, x2, y2,
                      gdi_act_color_from_rgb(255, 145, 145, 145));
        gdi_layer_pop_and_restore_active();    
        g_imgflow_cntx.imageflow_callback(g_imgflow_cntx.imageflow_userdata, g_imgflow_cntx.curr_cache_index);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cf_cancel_get_image
 * DESCRIPTION
 *  cancel get cover image from plst service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vadp_v2p_imgflow_cancel_get_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMGFLOW_TRACE2(VAPP_TRACE_IMAGEFLOW_CALL_CANCEL,
                   g_imgflow_cntx.curr_cache_index, g_imgflow_cntx.state);
    if (VAPP_IMGFLOW_STATE_LOADING == g_imgflow_cntx.state)
    {
        mmi_medply_listui_imgflow_get_artwork_aync_stop();
    }    

    IMGFLOW_STATE_CHANGE(VAPP_IMGFLOW_STATE_READY, __LINE__);
    g_imgflow_cntx.curr_cache_index = -1;
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_imgflow_get_album_cover_cb
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vadp_v2p_imgflow_get_album_cover_cb(S32 err_group, S32 err_code, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //kal_printf("[IMG_FLOW]Cache service nb decode callback: ret:%d, index:%d, state:%d\n", 
     //          err_code, g_if_cntx.curr_cache_index, g_if_cntx.state);
    //ASSERT(VAPP_IF_STATE_DECODING == g_if_cntx.state);
    //g_if_cntx.state = VAPP_IF_STATE_READY;
    
    //g_imgflow_cntx.imageflow_callback(g_imgflow_cntx.imageflow_userdata, -1);//g_if_cntx.curr_cache_index);
}


#define CACHE_SERVICE_ADPTION
/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_imgflow_cachesrv_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 vadp_v2p_imgflow_memory_alloc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, ret;
    S32 total = 0;
    S32 cell_img_size = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Media cache service context buffer */
    total += SRV_CACHE_RUN_BUF_SIZE_MIN;
    ret = media_get_ext_buffer(MOD_MMI, (void **)&g_imgflow_cntx.cache_info.runbuf, 
                               SRV_CACHE_RUN_BUF_SIZE_MIN);
    if (ret < 0 || NULL == g_imgflow_cntx.cache_info.runbuf)
    {
        return VAPP_IMGFLOW_ERR_NO_MEMORY;
    } 

    /* Media cache service context buffer */
    total += SRV_PLST_MAX_PATH_LEN;
    ret = media_get_ext_buffer(MOD_MMI, (void **)&g_imgflow_cntx.cache_info.strbuf, 
                               SRV_PLST_MAX_PATH_LEN);
    if (ret < 0 || NULL == g_imgflow_cntx.cache_info.strbuf)
    {
        return VAPP_IMGFLOW_ERR_NO_MEMORY;
    }

    /* Media cache service L2 image buffer (Cell image buffer) */
    g_imgflow_cntx.cache_info.cell_size = 
        ((g_image_flow_skin_layout.cell_focus_w*g_image_flow_skin_layout.cell_focus_h*2)/4 + 1)*4;
    total += (g_imgflow_cntx.cache_info.cell_size * VAPP_IMGFLOW_CACHE_NUMBER);
    ret = media_get_ext_buffer(MOD_MMI, (void **)&g_imgflow_cntx.cache_info.cell_med_hdlr, 
                               g_imgflow_cntx.cache_info.cell_size * VAPP_IMGFLOW_CACHE_NUMBER);
    if (ret < 0 || NULL == g_imgflow_cntx.cache_info.cell_med_hdlr)
    {
        return VAPP_IMGFLOW_ERR_NO_MEMORY;
    }

    /* exchange image buffer */
    total += SRV_CACHE_BIG_IMAGE_CACHE;
    ret = media_get_ext_buffer(MOD_MMI, (void **)&g_imgflow_cntx.cache_info.temp_image_buff, 
                               SRV_CACHE_BIG_IMAGE_CACHE);
    if (ret < 0 || NULL == g_imgflow_cntx.cache_info.temp_image_buff)
    {
        return VAPP_IMGFLOW_ERR_NO_MEMORY;
    }

    /* Default image buffer*/
    total += g_imgflow_cntx.cache_info.cell_size;
    ret = media_get_ext_buffer(MOD_MMI, (void **)&g_imgflow_cntx.def_image_buf, 
                               g_imgflow_cntx.cache_info.cell_size);
    if (ret < 0 || NULL == g_imgflow_cntx.def_image_buf)
    {
        return VAPP_IMGFLOW_ERR_NO_MEMORY;
    }    

    return VAPP_IMGFLOW_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_imgflow_memory_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 vadp_v2p_imgflow_memory_free(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgflow_cntx.cache_info.runbuf)
    {
        ret = media_free_ext_buffer(MOD_MMI, (void **)&g_imgflow_cntx.cache_info.runbuf);
        ASSERT(0 == ret);
    }
    if (g_imgflow_cntx.cache_info.strbuf)
    {
        ret = media_free_ext_buffer(MOD_MMI, (void **)&g_imgflow_cntx.cache_info.strbuf);
        ASSERT(0 == ret);
    }
    if (g_imgflow_cntx.cache_info.cell_med_hdlr)
    {
        ret = media_free_ext_buffer(MOD_MMI, (void **)&g_imgflow_cntx.cache_info.cell_med_hdlr);
        ASSERT(0 == ret);
    }
    if (g_imgflow_cntx.cache_info.temp_image_buff)
    {
        ret = media_free_ext_buffer(MOD_MMI, (void **)&g_imgflow_cntx.cache_info.temp_image_buff);
        ASSERT(0 == ret);
    }
    if (g_imgflow_cntx.def_image_buf)
    {
        ret =  media_free_ext_buffer(MOD_MMI, (void **)&g_imgflow_cntx.def_image_buf);
        ASSERT(0 == ret);
    }
    return VAPP_IMGFLOW_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_imgflow_cachesrv_init
 * DESCRIPTION
 *  Init media cache service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 vadp_v2p_imgflow_cachesrv_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_eng_callbacks_struct callback_struct;
    vapp_imgflow_cache_info_struct* cache_info = &g_imgflow_cntx.cache_info;    
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Create serivce */
    cache_info->cache_srv_hdl = srv_mediacache_create(cache_info->runbuf, SRV_CACHE_RUN_BUF_SIZE_MIN);
    if (NULL == cache_info->cache_srv_hdl)
    {
        return VAPP_IMGFLOW_ERR_CACHESRV_INVALID;
    }

    /* Regsist engin */
    callback_struct.cancel_decode_cell = srv_mediacache_imgflow_decode_cancel;
    callback_struct.decode_cell = srv_mediacache_imgflow_get_raw_data;
    callback_struct.get_file_name = NULL;
    callback_struct.search_cell = NULL;
    callback_struct.cancel_search_cell = NULL;
    srv_mediacache_register_engine(&callback_struct);

    /* Set mode */
    srv_mediacache_config_work_mode_to_prefetch_func(
                            cache_info->cache_srv_hdl, 
                            g_imgflow_cntx.count, 
                            srv_mediacache_imgflow_get_data_cb);

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
#endif

    srv_mediacache_config_level2_size(
                            cache_info->cache_srv_hdl, 
                            g_image_flow_skin_layout.cell_focus_w, 
                            g_image_flow_skin_layout.cell_focus_h);
    
    ret = srv_mediacache_add_cache(
                            cache_info->cache_srv_hdl, 
                            SRV_MEDIACACHE_CACHE_TYPE_L2, 
                            cache_info->cell_med_hdlr, 
                            g_imgflow_cntx.cache_info.cell_size * VAPP_IMGFLOW_CACHE_NUMBER);
    if (SRV_MEDIACACHE_OK != ret)
    {
        return VAPP_IMGFLOW_ERR_CACHESRV_INVALID;
    }
    return VAPP_IMGFLOW_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_imgflow_cachesrv_deinit
 * DESCRIPTION
 *  destory media cache service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 vadp_v2p_imgflow_cachesrv_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vapp_imgflow_cache_info_struct* cache_info = &g_imgflow_cntx.cache_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != cache_info->cache_srv_hdl)
    {
        srv_mediacache_destroy(cache_info->cache_srv_hdl);
    }    
    return VAPP_IMGFLOW_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_imgflow_cachesrv_init
 * DESCRIPTION
 *  Init media cache service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 vadp_v2p_imgflow_cachesrv_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vapp_imgflow_cache_info_struct* cache_info = &g_imgflow_cntx.cache_info;
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(NULL != cache_info->cache_srv_hdl);
        
    ret = srv_mediacache_start(cache_info->cache_srv_hdl, cache_info->focus_index);
    if (SRV_MEDIACACHE_OK != ret)
    {
        return VAPP_IMGFLOW_ERR_CACHESRV_START_FAIL;
    }    
    return VAPP_IMGFLOW_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_imgflow_cachesrv_stop
 * DESCRIPTION
 *  stop media cache service
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
static void vadp_v2p_imgflow_cachesrv_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vapp_imgflow_cache_info_struct* cache_info = &g_imgflow_cntx.cache_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(NULL != cache_info->cache_srv_hdl);        
    srv_mediacache_stop(cache_info->cache_srv_hdl);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_imgflow_cachesrv_pause
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_imgflow_cachesrv_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vapp_imgflow_cache_info_struct* cache_info = &g_imgflow_cntx.cache_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cache_info->cache_srv_hdl)
    {
        IMGFLOW_TRACE0(VAPP_TRACE_IMAGEFLOW_PAUSE_CACHE_SERVICE);
        srv_mediacache_pause_decode(cache_info->cache_srv_hdl);
    }

}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_imgflow_cachesrv_resume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_imgflow_cachesrv_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vapp_imgflow_cache_info_struct* cache_info = &g_imgflow_cntx.cache_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cache_info->cache_srv_hdl)
    {
        IMGFLOW_TRACE0(VAPP_TRACE_IMAGEFLOW_RESUME_CACHE_SERVICE);
        srv_mediacache_resume_decode(cache_info->cache_srv_hdl);
    }
}


#define CACHE_ENGIN_FOR_IMGFLOW
/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_imgflow_get_data_cb
 * DESCRIPTION
 *  No use
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 srv_mediacache_imgflow_get_data_cb(S32 index, WCHAR *buffer, U32 length, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_imgflow_get_raw_data
 * DESCRIPTION
 *  Step 1: Media cache query raw data by index.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_mediacache_imgflow_get_raw_data(U32 *handle, srv_mediacache_cell_struct *cell_p, srv_mediacache_nb_decode_callback done_callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT  result;
    S32         index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMGFLOW_TRACE0(VAPP_TRACE_IMAGEFLOW_SCHEDULE_NEW_IMAGE);
    if (NULL == cell_p)
    {
        return MMI_FALSE;
    }

    g_cache_engin_cntx.user_data = user_data;
    g_cache_engin_cntx.cache_cell_p = cell_p;
    index = g_cache_engin_cntx.cache_cell_p->file_index;

#if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    PERF_MONITOR_BEGIN(__LINE__);
#ifdef __IMGFLOW_USE_GDI_BACKGROUND_DECODE__
    gdi_imgdec_nb_stop(g_cache_engin_cntx.decode_handle);
#else
    gdi_image_nb_stop(g_cache_engin_cntx.decode_handle);
#endif
    g_cache_engin_cntx.decode_handle = 0;
    if (g_cache_engin_cntx.cache_layer != NULL)
    {
        gdi_layer_free(g_cache_engin_cntx.cache_layer);
        g_cache_engin_cntx.cache_layer = NULL;
    }
    result = vadp_v2p_imgflow_get_data_from_db(g_cache_engin_cntx.cache_cell_p->file_index);
    PERF_MONITOR_END(__LINE__);
    if ( result < 0)
    {
        g_cache_engin_cntx.cache_cell_p->err_code = result;
        g_cache_engin_cntx.cache_cell_p->err_group= SRV_MEDIACACHE_ERR_GROUP_FS;
        g_cache_engin_cntx.cache_cell_p = NULL;
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_imgflow_nb_decode
 * DESCRIPTION
 *  Step 2: Send commond to decode after get raw data.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_mediacache_imgflow_nb_decode(S32 ret, U8* img_buf, S32 img_width, S32 img_height, S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 buf_length = 0;
    S32 x,y,w,h, layer_w,layer_h;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_cache_engin_cntx.cache_cell_p)
    {
        ASSERT(0);
    }
    
    if (ret < 0)
    {
        g_cache_engin_cntx.cache_cell_p->err_code = ret;
        g_cache_engin_cntx.cache_cell_p->err_group= SRV_MEDIACACHE_ERR_GROUP_FS;
        g_cache_engin_cntx.cache_cell_p = NULL;
        srv_mediacache_decode_nb_decode_callback(
                (S32)SRV_MEDIACACHE_ERR_NOT_SUPPORT, 
                SRV_MEDIACACHE_ERR_GROUP_GDI, 
                g_cache_engin_cntx.user_data);
        return MMI_FALSE;
    }

    buf_length = srv_mediacache_cache_get_img_size_by_type(g_cache_engin_cntx.cache_cell_p->type);
    if (img_width <= 0 || img_height <= 0 || 
        img_width > SRV_MEDIACACHE_DECODE_MAX_W_H ||
        img_height > SRV_MEDIACACHE_DECODE_MAX_W_H)
    {        
        g_cache_engin_cntx.cache_cell_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
        g_cache_engin_cntx.cache_cell_p->err_code = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
        g_cache_engin_cntx.cache_cell_p->err_group= SRV_MEDIACACHE_ERR_GROUP_MEDIACACHE;
        g_cache_engin_cntx.cache_cell_p = NULL;
        srv_mediacache_decode_nb_decode_callback(
                (S32)SRV_MEDIACACHE_ERR_NOT_SUPPORT, 
                SRV_MEDIACACHE_ERR_GROUP_GDI, 
                g_cache_engin_cntx.user_data);
        return MMI_FALSE;
    }

    if (g_cache_engin_cntx.cache_cell_p->file_index != g_imgflow_cntx.curr_cache_index)
    {
        ASSERT(0);
    }    
    g_cache_engin_cntx.cache_cell_p->image_type = GDI_IMAGE_TYPE_JPG;//GDI_IMAGE_TYPE_JPG_FILE;
    srv_mediacache_cache_fill_cell_by_img(img_width, img_height, g_cache_engin_cntx.cache_cell_p);
    if (g_cache_engin_cntx.cache_cell_p->image_width <= 0 || g_cache_engin_cntx.cache_cell_p->image_height <= 0)
    {        
        g_cache_engin_cntx.cache_cell_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
        g_cache_engin_cntx.cache_cell_p->err_code = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
        g_cache_engin_cntx.cache_cell_p->err_group= SRV_MEDIACACHE_ERR_GROUP_MEDIACACHE;
        g_cache_engin_cntx.cache_cell_p = NULL;
        srv_mediacache_decode_nb_decode_callback(
                    (S32)SRV_MEDIACACHE_ERR_NOT_SUPPORT, 
                    SRV_MEDIACACHE_ERR_GROUP_GDI, 
                    g_cache_engin_cntx.user_data);
        return MMI_FALSE;
    }
    else
    {
        x = 1;
        y = 1;
        w = g_cache_engin_cntx.cache_cell_p->image_width - 2;
        h = g_cache_engin_cntx.cache_cell_p->image_height - 2;
        layer_w = g_cache_engin_cntx.cache_cell_p->image_width;
        layer_h = g_cache_engin_cntx.cache_cell_p->image_height;
        ASSERT(g_cache_engin_cntx.cache_cell_p->image_width > 0);
        ASSERT(g_cache_engin_cntx.cache_cell_p->image_height > 0);
        gdi_layer_create_using_outside_memory(
                    0,
                    0,
                    layer_w,
                    layer_h,
                    &g_cache_engin_cntx.cache_layer,
                    g_cache_engin_cntx.cache_cell_p->buffer,
                    buf_length);
        gdi_layer_set_source_key_nb_concurrent(g_cache_engin_cntx.cache_layer, MMI_TRUE, GDI_COLOR_TRANSPARENT);
        gdi_push_and_set_alpha_blending_source_layer(g_cache_engin_cntx.cache_layer);
    #ifdef __IMGFLOW_USE_GDI_BACKGROUND_DECODE__
        gdi_layer_clear_nb_concurrent(g_cache_engin_cntx.cache_layer, GDI_COLOR_TRANSPARENT);
        g_cache_engin_cntx.decode_handle = gdi_imgdec_nb_draw_resized_mem(
                                                    g_cache_engin_cntx.cache_layer,
                                                    x, y, w, h,
                                                    GDI_IMAGE_TYPE_JPG,
                                                    size,
                                                    img_buf,
                                                    srv_mediacache_imgflow_decode_done_cb);  
    #else
        gdi_layer_push_and_set_active(g_cache_engin_cntx.cache_layer);
        gdi_nb_set_done_callback(srv_mediacache_imgflow_decode_done_cb);
        gdi_nb_set_blt(MMI_FALSE, MMI_FALSE);
        g_cache_engin_cntx.decode_handle = 
                    gdi_image_nb_draw_resized_mem(x, y, w, h, img_buf, GDI_IMAGE_TYPE_JPG, size);  
        gdi_layer_pop_and_restore_active();
    #endif
        gdi_pop_and_restore_alpha_blending_source_layer();
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_imgflow_decode_done_cb
 * DESCRIPTION
 *  Step 3: decode done.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mediacache_imgflow_decode_done_cb(GDI_RESULT result,gdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cache_engin_cntx.decode_handle != handle)
    {
        return;
    }    

    PERF_MONITOR_BEGIN(__LINE__);
    srv_mediacache_decode_nb_decode_callback((S32)result, 
                                             SRV_MEDIACACHE_ERR_GROUP_GDI, 
                                             g_cache_engin_cntx.user_data);

    //if (0 == result)
    //{
        vadp_v2p_imgflow_decode_done(result);
    //}
    PERF_MONITOR_END(__LINE__);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_decode_non_block_cb
 * DESCRIPTION
 *  callback function of non-block image decode
 * PARAMETERS
 *  result  [IN]   result
 *  handle  [IN]   GDI handle
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_mediacache_imgflow_decode_cancel(U32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PERF_MONITOR_BEGIN(__LINE__);
#ifdef __IMGFLOW_USE_GDI_BACKGROUND_DECODE__
    gdi_imgdec_nb_stop(g_cache_engin_cntx.decode_handle);
#else
    gdi_image_nb_stop(g_cache_engin_cntx.decode_handle);
#endif
    vadp_v2p_imgflow_cancel_get_data();
    g_cache_engin_cntx.decode_handle = NULL;
    PERF_MONITOR_END(__LINE__);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_get_org_info
 * DESCRIPTION
 *  callback function of non-block image decode
 * PARAMETERS
 *  result  [IN]   result
 *  handle  [IN]   GDI handle
 * RETURNS
 *  void
 *****************************************************************************/
static S32 srv_mediacache_get_org_info(srv_handle handle, S32* w, S32* h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 err_code = SRV_MEDIACACHE_OK;
    srv_mediacache_cell_struct *cell_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == srv_mediacache_cache_cell_can_draw(g_mediacache_cntx_p->large_p))
    {
        cell_p = g_mediacache_cntx_p->large_p;
    }
    else if (MMI_TRUE == srv_mediacache_cache_cell_can_draw(g_mediacache_cntx_p->level1_curr_p))
    {
        cell_p = g_mediacache_cntx_p->level1_curr_p;
    }
    else if (MMI_TRUE == srv_mediacache_cache_cell_can_draw(g_mediacache_cntx_p->level2_curr_p))
    {
        cell_p = g_mediacache_cntx_p->level2_curr_p;
    }
    if (NULL != cell_p)
    {
        *w = cell_p->org_image_width - 1;
        *h = cell_p->org_image_height - 1;
    }
    else
    {
        err_code = SRV_MEDIACACHE_ERR_DECODING;
    }
    return err_code;
}    

#endif /*__MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__*/
