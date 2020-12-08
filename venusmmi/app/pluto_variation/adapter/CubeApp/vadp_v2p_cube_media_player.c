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
 *  vadp_v2p_cube_media_player.c
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Media Player Cube Screen
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
 #include "MMI_Features.h" 
#include "mmi_include.h"

#ifdef __MMI_VUI_3D_CUBE_APP_MEDIA_PLAYER__



/* cube relate header files */
#include "CubeAppGprot.h"
#include "CubeAppProt.h"
#include "CubeApp\vadp_p2v_cube_media_player.h"
#include "CubeApp\vadp_v2p_cube_media_player.h"
#include "vapp_cube_res.h"

/* media cache  engine header files */
#include "math.h"
#include "ctype.h"
#include "FileManagerGProt.h"
#include "FileMgr.h"
#include "FileMgrServiceHdlr.h"
#include "Gdi_util.h"
#include "MMIDataType.h"
#include "custom_events_notify.h"
#include "med_api.h"

#include "MediaCacheSrvGprot.h"
#if defined(__SQLITE3_SUPPORT__)
#include "..\..\..\applib\sqlite3\inc\sqlite3.h"
#include "..\..\..\applib\sqlite3\inc\sqlite3ex.h"
#include "ImageViewerDaemonGprot.h"
#endif /* defined(__SQLITE3_SUPPORT__) */ 
#include "MediaCacheSrvGprot.h"
#include "MediaCacheSrv.h"

/* list service headers */
#include "PlstSrvGprot.h"

/* Pluto headers */
#include "SettingProfileEnum.h"
#include "MediaPlayerGProt.h"
#include "MediaPlayerEnumDef.h"
#include "MediaAppWidgetDef.h"
#include "AudioPlayerProt.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "MediaPlayerProt.h"
#include "GeneralDeviceGprot.h"

typedef struct
{
    S32 curr_cache_index;
    S32 curr_focus_index;
    U32 plst_srv_hdlr;
    S32 *cache_srv_hdl;
    
    void (*imageflow_callback) (void *user_data, S32 index);
    void *imageflow_userdata;
    
    U8 *cache_runbuf_ptr;
    U8 *l2_cache_ptr;
    U8 *artwork_image_ptr;
    srv_plst_list_get_display_struct artwork_para;    
    U8 state;
} vadp_cube_media_player_info_struct;




cube_medply_plymode_layout_struct g_cube_medply_plymode_layout = 
{
#ifdef __MMI_MAINLCD_240X320__
    /*play_panel*/
    {0, 2, 240, 291},
    /*cover*/
    {58, 33, 135, 137},
    /*song_name*/
    {11, 179, 218, 26},
    /*cur time*/
    {11, 211, 56, 11},
    /*progress*/
    {11, 226, 218, 6},
    /*total time*/
    {179, 211, 56, 11},
    /*stop button*/
    {136, 222, 60, 60},
    /*play button */
    {49, 222, 60, 60},
    /* close button */
    {185, 12, 60, 60},
    /*repeat panel */
    {0, 0, 0, 0},
    /* shuffle button*/
    {-6, 132, 60, 60},
    /* reteat button */
    {185, 133, 60, 60}, 
    /* up arrow button */
    {105, 32, 33, 24},
    /* down arrow button */
    {105, 146, 33, 24}
#endif

#ifdef __MMI_MAINLCD_240X400__
    /*play_panel*/
    {0, 22, 240, 305},
    /*cover*/
    {58, 60, 135, 137},
    /*song_name*/
    {11, 206, 218, 26},
    /*cur time*/
    {11, 238, 56, 11},
    /*progress*/
    {11, 253, 218, 6},
    /*total time*/
    {179, 238, 56, 11},
    /*stop button*/
    {136, 249, 60, 60},
    /*play button */
    {49, 249, 60, 60},
    /* close button */
    {185, 39, 60, 60},
    /*repeat panel */
    {185, 160, 60, 60},
    /* shuffle button*/
    {-6, 159, 60, 60},
    /* reteat button */
    {185, 160, 60, 60}, 
    /* up arrow button */
    {105, 59, 33, 24},
    /* down arrow button */
    {105, 173, 33, 24}    
#endif

#ifdef  __MMI_MAINLCD_320X480__  //need the final layout
    /*play_panel*/
    {0, 19, 320, 385},
    /*cover*/
    {78, 64, 179, 181},
    /*song_name*/
    {17, 262, 286, 26},
    /*cur time*/
    {17, 294, 72, 14},
    /*progress*/
    {17, 312, 286, 7},
    /*total time*/
    {238, 294, 72, 14},
    /*stop button*/
    {169, 297, 99, 99},
    /*play button */
    {58, 297, 99, 99},
    /* close button */
    {236, 28, 99, 99},
    /*repeat panel */
    {236, 186, 99, 99},
    /* shuffle button*/
    {-17, 186, 99, 99},
    /* reteat button */
    {236, 186, 99, 99}, 
    /* up arrow button */
    {141, 66, 40, 29},
    /* down arrow button */
    {141, 214, 40, 29}    
#endif

};

cube_medply_navmode_layout_struct g_cube_medply_navmode_layout = 
{
#ifdef __MMI_MAINLCD_240X320__    
    {0,   13},
    {240, 54},
    {57, 54},
    {8, 3, 47, 48},   
    {-7, 225, 60, 60}

#endif

#ifdef __MMI_MAINLCD_240X400__
    {0,   13},
    {240, 70},
    {75, 70},
    {10, 3, 62, 64}, 
    {-7, 292, 60, 60}
#endif

#ifdef  __MMI_MAINLCD_320X480__  // need the final layout
    {0,   8},
    {320, 85},
    {90, 85},
    {11, 3, 77, 79}, 
    {-33, 340, 99, 99}
#endif    
};

U8 *vapp_cube_medply_s_cover_buf[VAPP_CUBE_MEDPLY_S_COVER_BUF_NUM];
U8 *vapp_cube_medply_l_cover_buf[VAPP_CUBE_MEDPLY_L_COVER_BUF_NUM];



U16 test_string[10][128] = 
{
    L"audio list not ready",
    L"Pretty Boy A B C D E F G H I J K",
    L"The day you went away",
    L"Right there waiting for you",
    L"little girl A B C D E F G H I J K",
    L"Yesterday once more A B C D E F G H I J K",
    L"Love story A B C D E F G H I J K",
    L"All for one A B C D E F G H I J K",
    L"River A B C D E F G H I J K",
    L"My love will go on A B C D E F G H I J K"
};

/* @TODO: no need this global variable in further intergration */
static U8 test[VAPP_CUBE_MEDPLY_RUN_BUF_SIZE_MIN];
static vadp_cube_media_player_info_struct g_adp_cube_mp_cntx;
static U32 g_cube_medply_decode_handle = 0;
static gdi_handle g_cube_medply_cache_layer = 0;
static gdi_handle g_cube_medply_tmp_layer = 0;
static void *g_cube_medply_user_data = NULL;
srv_mediacache_cell_struct *g_cube_medply_cache_cell_p = NULL;

extern srv_mediacache_cntx_struct *g_mediacache_cntx_p;

/***********************************************************
*  static function declearation
************************************************************/
static S32 srv_mediacache_get_org_info(srv_handle handle, S32 *w, S32 *h);
static void srv_mediacache_cube_media_player_decode_done_cb(GDI_RESULT result, gdi_handle handle);
static void srv_mediacache_cube_media_player_prepare(void);
static MMI_BOOL srv_mediacache_cube_media_player_gdi_nb_decode_cancel(U32 handle);
static MMI_BOOL srv_mediacache_cube_media_player_engine_nb_decode(
                    S32 ret,
                    U8 *img_buf,
                    S32 img_width,
                    S32 img_height,
                    S32 size);
static MMI_BOOL srv_mediacache_cube_media_player_get_data(
                    U32 *handle,
                    srv_mediacache_cell_struct *cell_p,
                    srv_mediacache_nb_decode_callback done_callback,
                    void *user_data);
static S32 srv_mediacache_cube_media_player_get_data_cb(S32 index, WCHAR *buffer, U32 length, void *user_data);

static S32 vadp_v2p_cube_media_player_list_srv_callback(srv_plst_cb_evt_enum cb_event, S32 result, U32 ca_para_2);

static void vadp_v2p_cube_media_player_get_curr_img_callback(S32 err_group, S32 err_code, void *user_data);

/* extern from  media cache service */
extern void srv_mediacache_register_engine(srv_mediacache_eng_callbacks_struct *engine_p);
extern void srv_mediacache_decode_nb_decode_callback(S32 result, srv_mediacache_err_group_enum group, void *user_data);
extern MMI_BOOL srv_mediacache_cache_cell_can_draw(srv_mediacache_cell_struct *cell);
#define VADP_CUBE_MEDIA_PLAYER_CACHE_SERVICE_API


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_media_player_init_cache_srv
 * DESCRIPTION
 *  
 * PARAMETERS
 *  num_all     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 vadp_v2p_cube_media_player_init_cache_srv(S32 num_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    S32 media_get_ext_buffer_ret;
    S32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_adp_cube_mp_cntx.state = VAPP_CUBE_MEDIA_PLAYER_STATE_IDLE;
    g_adp_cube_mp_cntx.artwork_image_ptr = NULL;
    media_get_ext_buffer_ret = media_get_ext_buffer(MOD_MMI, (void **)&g_adp_cube_mp_cntx.artwork_image_ptr, VAPP_CUBE_MEDPLY_MEM_SIZE);   
    ASSERT(media_get_ext_buffer_ret == 0);
    ASSERT(g_adp_cube_mp_cntx.artwork_image_ptr != NULL); 

    memset((void *)g_adp_cube_mp_cntx.artwork_image_ptr, 0, VAPP_CUBE_MEDPLY_MEM_SIZE);
    vapp_cube_medply_s_cover_buf[0] = NULL;
    vapp_cube_medply_s_cover_buf[0] = g_adp_cube_mp_cntx.artwork_image_ptr + VAPP_CUBE_MEDPLY_ARTWORK_IMAGE_SIZE;
    for (i = 1; i < VAPP_CUBE_MEDPLY_S_COVER_BUF_NUM; i++)
    {
        vapp_cube_medply_s_cover_buf[i] = NULL;
        vapp_cube_medply_s_cover_buf[i] = vapp_cube_medply_s_cover_buf[i - 1] + VAPP_CUBE_MEDPLY_S_COVER_BUF_SIZE;
    }

    vapp_cube_medply_l_cover_buf[0] = NULL;
    vapp_cube_medply_l_cover_buf[0] = vapp_cube_medply_s_cover_buf[VAPP_CUBE_MEDPLY_S_COVER_BUF_NUM - 1] + VAPP_CUBE_MEDPLY_S_COVER_BUF_SIZE;
    for (i = 1; i < VAPP_CUBE_MEDPLY_L_COVER_BUF_NUM; i++)
    {
        vapp_cube_medply_l_cover_buf[i] = NULL;
        vapp_cube_medply_l_cover_buf[i] = vapp_cube_medply_l_cover_buf[i - 1] + VAPP_CUBE_MEDPLY_L_COVER_BUF_SIZE;   
    }
    
    g_adp_cube_mp_cntx.cache_runbuf_ptr = vapp_cube_medply_l_cover_buf[VAPP_CUBE_MEDPLY_L_COVER_BUF_NUM - 1] + VAPP_CUBE_MEDPLY_L_COVER_BUF_SIZE;
    g_adp_cube_mp_cntx.l2_cache_ptr = g_adp_cube_mp_cntx.cache_runbuf_ptr + VAPP_CUBE_MEDPLY_RUN_BUF_SIZE_MIN;

    ASSERT((g_adp_cube_mp_cntx.l2_cache_ptr + VAPP_CUBE_MEDPLY_L2_CACHE_SIZE) == (g_adp_cube_mp_cntx.artwork_image_ptr + VAPP_CUBE_MEDPLY_MEM_SIZE));    

    /* init Media cache service */
    g_adp_cube_mp_cntx.cache_srv_hdl = NULL;
    g_adp_cube_mp_cntx.cache_srv_hdl = srv_mediacache_create((void *)g_adp_cube_mp_cntx.cache_runbuf_ptr, VAPP_CUBE_MEDPLY_RUN_BUF_SIZE_MIN);
    if (g_adp_cube_mp_cntx.cache_srv_hdl == NULL)
    {
        if (g_adp_cube_mp_cntx.artwork_image_ptr)
        {
            media_free_ext_buffer(MOD_MMI, (void **)&g_adp_cube_mp_cntx.artwork_image_ptr);
            memset((void *)vapp_cube_medply_s_cover_buf, 0, VAPP_CUBE_MEDPLY_S_COVER_BUF_NUM);
            memset((void *)vapp_cube_medply_l_cover_buf, 0, VAPP_CUBE_MEDPLY_L_COVER_BUF_NUM);
        } 
        g_adp_cube_mp_cntx.artwork_image_ptr = NULL;
        return SRV_MEDIACACHE_ERR_NOT_SUPPORT;
    }
    srv_mediacache_cube_media_player_prepare();

    srv_mediacache_config_work_mode_to_prefetch_func(
        g_adp_cube_mp_cntx.cache_srv_hdl,
        num_all,
        srv_mediacache_cube_media_player_get_data_cb);

    ret = srv_mediacache_add_cache(
            g_adp_cube_mp_cntx.cache_srv_hdl,
            SRV_MEDIACACHE_CACHE_TYPE_L2,
            g_adp_cube_mp_cntx.l2_cache_ptr,
            VAPP_CUBE_MEDPLY_L2_CACHE_SIZE);

    if (ret != SRV_MEDIACACHE_OK)
    {
        srv_mediacache_destroy(g_adp_cube_mp_cntx.cache_srv_hdl);
        if (g_adp_cube_mp_cntx.artwork_image_ptr)
        {
            media_free_ext_buffer(MOD_MMI, (void **)&g_adp_cube_mp_cntx.artwork_image_ptr);
            memset((void *)vapp_cube_medply_s_cover_buf, 0, VAPP_CUBE_MEDPLY_S_COVER_BUF_NUM);
            memset((void *)vapp_cube_medply_l_cover_buf, 0, VAPP_CUBE_MEDPLY_L_COVER_BUF_NUM);
        }    
        g_adp_cube_mp_cntx.cache_srv_hdl = NULL;
        g_adp_cube_mp_cntx.artwork_image_ptr = NULL;
        return ret;
    }
    srv_mediacache_start(g_adp_cube_mp_cntx.cache_srv_hdl, 0);

    return ret;

}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_media_player_deinit_cache_srv
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_media_player_deinit_cache_srv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_adp_cube_mp_cntx.cache_srv_hdl)
    {
        srv_mediacache_stop(g_adp_cube_mp_cntx.cache_srv_hdl);
        srv_mediacache_destroy(g_adp_cube_mp_cntx.cache_srv_hdl);
        g_adp_cube_mp_cntx.cache_srv_hdl = NULL;
    }
    if (g_adp_cube_mp_cntx.artwork_image_ptr)
    {
        media_free_ext_buffer(MOD_MMI, (void **)&g_adp_cube_mp_cntx.artwork_image_ptr);
        memset((void *)vapp_cube_medply_s_cover_buf, 0, VAPP_CUBE_MEDPLY_S_COVER_BUF_NUM);
        memset((void *)vapp_cube_medply_l_cover_buf, 0, VAPP_CUBE_MEDPLY_L_COVER_BUF_NUM);
        g_adp_cube_mp_cntx.artwork_image_ptr = NULL;
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_media_player_set_focus_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
extern S32 vadp_v2p_cube_media_player_set_focus_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //////kal_printf("\n[Guoming] Vadp_v2p_cube_media_player_set_focus_index = %d\n", index);
    if (g_adp_cube_mp_cntx.cache_srv_hdl == NULL)
    {
        return MMI_FALSE;
    }
    g_adp_cube_mp_cntx.curr_focus_index = index;
    srv_mediacache_goto_index(g_adp_cube_mp_cntx.cache_srv_hdl, index);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_media_player_pause_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_media_player_pause_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_adp_cube_mp_cntx.cache_srv_hdl)
    {
        srv_mediacache_pause_decode(g_adp_cube_mp_cntx.cache_srv_hdl);
    }

}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_media_player_resume_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_media_player_resume_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_adp_cube_mp_cntx.cache_srv_hdl)
    {
        srv_mediacache_resume_decode(g_adp_cube_mp_cntx.cache_srv_hdl);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_media_player_register_cache_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  user_data       [?]         
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_media_player_register_cache_callback(void *user_data, void (*callback) (void *user_data, S32 index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_adp_cube_mp_cntx.imageflow_callback = callback;
    g_adp_cube_mp_cntx.imageflow_userdata = user_data;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_media_player_unregister_cache_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_media_player_unregister_cache_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_adp_cube_mp_cntx.imageflow_callback = NULL;
    g_adp_cube_mp_cntx.imageflow_userdata = NULL;
}

#define VADP_CUBE_MEDIA_PLAYER_SERVICE_API

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_media_player_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 vadp_v2p_cube_media_player_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = -1;
    S32 handle = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_adp_cube_mp_cntx.plst_srv_hdlr = 0;
    ret =   mmi_medply_list_extapp_startup(&handle, vadp_v2p_cube_media_player_list_srv_callback);  
    if (ret != 0)
    {
          return MMI_FALSE;
    }
    else
    {
        if (!mmi_medply_widget_is_plst_ready())
        {
            return MMI_FALSE;   
        }
        ret = srv_plst_list_default_list_entry(handle, SRV_PLST_DEF_ACTIVE_LIST);
        if (ret != SRV_PLST_OK)
        {
            srv_plst_list_default_list_exit(handle);
            mmi_medply_list_extapp_logoff();
            return MMI_FALSE;
        }

	ret = srv_plst_get_active_list_media_type(handle);
	if (ret != SRV_PLST_ACTIVE_LIST_TYPE_AUDIO)
	{
        srv_plst_list_default_list_exit(handle);	
        mmi_medply_list_extapp_logoff();
	    return MMI_FALSE;
	}
	
  	g_adp_cube_mp_cntx.plst_srv_hdlr = handle;      

    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_media_player_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_media_player_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_adp_cube_mp_cntx.plst_srv_hdlr == 0)
    {
        return;
    }
    srv_plst_list_default_list_exit(g_adp_cube_mp_cntx.plst_srv_hdlr);
    mmi_medply_list_extapp_logoff();
    g_adp_cube_mp_cntx.plst_srv_hdlr = 0;

  
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_media_player_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void vadp_v2p_cube_media_player_reset(void)
{
    S32 ret;
    S32 index;
    S32 total;
    
    if (g_adp_cube_mp_cntx.plst_srv_hdlr == 0)
    {
        return;
    }
    if (g_adp_cube_mp_cntx.cache_srv_hdl == NULL)
    {
        return;
    }
    srv_mediacache_stop(g_adp_cube_mp_cntx.cache_srv_hdl);
    srv_plst_list_default_list_exit(g_adp_cube_mp_cntx.plst_srv_hdlr);
    ret = srv_plst_list_default_list_entry(g_adp_cube_mp_cntx.plst_srv_hdlr, SRV_PLST_DEF_ACTIVE_LIST);
    EXT_ASSERT(ret == SRV_PLST_OK, ret, 0, 0);
    total = vadp_v2p_cube_media_player_get_item_count();
    EXT_ASSERT(total != 0, total, 0, 0);
    index = vadp_v2p_cube_media_player_get_active_index();
    srv_mediacache_start(g_adp_cube_mp_cntx.cache_srv_hdl, index);    
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_media_player_get_item_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 vadp_v2p_cube_media_player_get_item_count()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 total_number = 0;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_adp_cube_mp_cntx.plst_srv_hdlr == 0)
    {
        return 0;
    }

    ret = srv_plst_list_get_item_count(g_adp_cube_mp_cntx.plst_srv_hdlr, &total_number);
    if (total_number > 0x7fffffff)
    {
        return 0;
    }
    return (S32)total_number;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_media_player_get_song_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  title       [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 vadp_v2p_cube_media_player_get_song_title(S32 index, U16 *title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_get_display_struct temp_info;
    S32 srv_plst_list_get_item_display_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    title[0] = 0;
    title[1] = 0;
    title[80] = 0;
    if (!g_adp_cube_mp_cntx.plst_srv_hdlr)
    {
        return MMI_FALSE;
    }
    
    temp_info.index = index;
    temp_info.buff_size = 80;
    temp_info.string_ptr = (U32) title;
    
    srv_plst_list_get_item_display_ret = srv_plst_list_get_item_display(g_adp_cube_mp_cntx.plst_srv_hdlr, &temp_info);
    if (srv_plst_list_get_item_display_ret != SRV_PLST_OK)
    {
         title[0] = 0;
         title[1] = 0;        
         return MMI_FALSE;
    }
    
        
    //////kal_printf("\n[Guoming] %s", title);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_media_player_get_cover
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  layer       [IN]        
 *  flag        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL vadp_v2p_cube_media_player_get_cover(S32 index, U8 *buf, S32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 ret, w, h;
    srv_mediacache_img_to_layer_struct area;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // ////kal_printf("\n[Guoming] get_cover() index: %d ", index);
    ASSERT(buf != NULL);
    srv_mediacache_goto_index(g_adp_cube_mp_cntx.cache_srv_hdl, index);

    ret = srv_mediacache_get_org_info(g_adp_cube_mp_cntx.cache_srv_hdl, &w, &h);
    if (SRV_MEDIACACHE_OK == ret)
    {
        area.src.width = w - 1;
        area.src.height = h - 1;
    }
    else
    {
        area.src.width = -1;
        area.src.height = -1;
    }
    if (g_cube_medply_tmp_layer)
    {
        gdi_layer_free(g_cube_medply_tmp_layer);
        g_cube_medply_tmp_layer = 0;
    }
    
    if (flag == 0)  /* small image */
    {
        area.src.x = 0;
        area.src.y = 0;
        area.dst.x = 0;
        area.dst.y = 0;
        area.dst.width = VAPP_CUBE_MEDPLY_S_COVER_W - 1;
        area.dst.height = VAPP_CUBE_MEDPLY_S_COVER_H - 1;
        area.user_data = g_adp_cube_mp_cntx.imageflow_userdata;
        area.callback = vadp_v2p_cube_media_player_get_curr_img_callback;
        gdi_layer_create_using_outside_memory(
            0,
            0,
            VAPP_CUBE_MEDPLY_S_COVER_W,
            VAPP_CUBE_MEDPLY_S_COVER_H,
            &g_cube_medply_tmp_layer,
            buf,
            VAPP_CUBE_MEDPLY_S_COVER_BUF_SIZE);        
    }
    else    /* big image */
    {
        area.src.x = 0;
        area.src.y = 0;
        area.dst.x = 0;
        area.dst.y = 0;
        area.dst.width = VAPP_CUBE_MEDPLY_L_COVER_W - 1;
        area.dst.height = VAPP_CUBE_MEDPLY_L_COVER_H - 1;
        area.user_data = g_adp_cube_mp_cntx.imageflow_userdata;
        area.callback = vadp_v2p_cube_media_player_get_curr_img_callback;
        gdi_layer_create_using_outside_memory(
            0,
            0,
            VAPP_CUBE_MEDPLY_L_COVER_W,
            VAPP_CUBE_MEDPLY_L_COVER_H,
            &g_cube_medply_tmp_layer,
            buf,
            VAPP_CUBE_MEDPLY_L_COVER_BUF_SIZE);        
    }
    ASSERT(g_cube_medply_tmp_layer != 0);
    area.dst_layer = g_cube_medply_tmp_layer;   
    
    ret = srv_mediacache_get_curr_img_to_layer(g_adp_cube_mp_cntx.cache_srv_hdl, &area);
    //////kal_printf("\n[Guoming] get_cover()back to focus index: %d ", g_adp_cube_mp_cntx.curr_focus_index);
    srv_mediacache_goto_index(g_adp_cube_mp_cntx.cache_srv_hdl, g_adp_cube_mp_cntx.curr_focus_index);
    if (SRV_MEDIACACHE_OK == ret)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_media_player_get_next_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 vadp_v2p_cube_media_player_get_active_index(void)
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
    if (!g_adp_cube_mp_cntx.plst_srv_hdlr)
    {
        return -1;
    }
    ret = srv_plst_plst_get_active_plst_item_index(g_adp_cube_mp_cntx.plst_srv_hdlr, &index);
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
 *  vadp_v2p_cube_media_player_button_process
 * DESCRIPTION
 *  Map widget button actions to application relative functions.
 * PARAMETERS
 *  button_type     [IN]        Widget button type
 *  pen_event       [IN]        Widget pen event
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_media_player_button_process(
        vapp_cube_medply_button_type_enum button_type,
        vapp_cube_medply_pentype_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_widget_player_button_enum button = 0;
    mmi_widget_player_key_event_enum event = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, VADP_AUDPLY_BUTTON_PRECESS, button_type, pen_event);

    switch (button_type)
    {
        case VAPP_CUBE_MEDIA_PLAYER_BUTTON_PLAY:
        case VAPP_CUBE_MEDIA_PLAYER_BUTTON_PAUSE:
        {
            button = MMI_WIDGET_PLAYER_PLAY_PAUSE;
            break;
        }

        case VAPP_CUBE_MEDIA_PLAYER_BUTTON_STOP:
        {
            button = MMI_WIDGET_PLAYER_STOP;
            break;
        }

        case VAPP_CUBE_MEDIA_PLAYER_BUTTON_PREV:
        {
            button = MMI_WIDGET_PLAYER_PREV;
            break;
        }

        case VAPP_CUBE_MEDIA_PLAYER_BUTTON_NEXT:
        {
            button = MMI_WIDGET_PLAYER_NEXT;
            break;
        }

        default:
            ASSERT(0);
    }

    switch (pen_event)
    {
        case VAPP_CUBE_MEDIA_PLAYER_PEN_EVENT_DOWN:
        {
            event = MMI_WIDGET_PLAYER_KEY_DOWN;
            break;
        }

        case VAPP_CUBE_MEDIA_PLAYER_PEN_EVENT_UP:
        {
            event = MMI_WIDGET_PLAYER_KEY_UP;
            break;
        }

        case VAPP_CUBE_MEDIA_PLAYER_PEN_EVENT_CANCEL:
        {
            event = MMI_WIDGET_PLAYER_KEY_CANCELED;
            break;
        }

        default:
            ASSERT(0);
    }

    if (button == MMI_WIDGET_PLAYER_PLAY_PAUSE && event == MMI_WIDGET_PLAYER_KEY_UP)
    {
    #if defined __MMI_MEDIA_PLAYER__
        mdi_audio_set_background_handler(
            MDI_BACKGROUND_APP_MEDPLY,
            (mdi_bg_callback) mmi_medply_background_callback_hdlr, NULL);
        mdi_audio_clear_other_background_handler(MDI_BACKGROUND_APP_MEDPLY);
    #endif /* defined __MMI_MEDIA_PLAYER__ */ 
    }
    mmi_medply_widget_button_action(button, event);
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_media_player_continue_play
 * DESCRIPTION
 *  vadp_v2p_cube_media_player_continue_play
 * PARAMETERS
 *
 * RETURNSa
 *  void
 *****************************************************************************/
static void vadp_v2p_cube_media_player_continue_play(void)
{
    vadp_v2p_cube_media_player_button_process(VAPP_CUBE_MEDIA_PLAYER_BUTTON_PLAY, VAPP_CUBE_MEDIA_PLAYER_PEN_EVENT_DOWN);
    vadp_v2p_cube_media_player_button_process(VAPP_CUBE_MEDIA_PLAYER_BUTTON_PLAY, VAPP_CUBE_MEDIA_PLAYER_PEN_EVENT_UP);    
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_media_player_continue_play_after_exit
 * DESCRIPTION
 *  vadp_v2p_cube_media_player_continue_play_after_exit
 * PARAMETERS
 *
 * RETURNSa
 *  void
 *****************************************************************************/
void vadp_v2p_cube_media_player_continue_play_after_exit(void)
{
    gui_start_timer(200, vadp_v2p_cube_media_player_continue_play);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_media_player_register_callback
 * DESCRIPTION
 *  Register callback function.
 * PARAMETERS
 *  userdata        [IN]        C++ this pointer
 *  callback        [IN]        Callback function
 * RETURNSa
 *  void
 *****************************************************************************/
void vadp_v2p_cube_media_player_register_callback(void *userdata, void (*callback) (void *, U32, void *))
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
 *  vadp_v2p_cube_media_player_deregister_callback
 * DESCRIPTION
 *  De-register callback function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_media_player_deregister_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_widget_register_callbacks(NULL, (void (*)(void *, mmi_widget_player_callback_enum, void*))NULL);

}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_media_player_state_transform
 * DESCRIPTION
 *  Map application state to widget state
 * PARAMETERS
 *  audio_player_state      [IN]        Application state
 * RETURNS
 *  widget state            Widget state
 *****************************************************************************/
U8 vadp_v2p_cube_media_player_state_transform(U8 audio_player_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_state_enum media_player_state = audio_player_state;

    switch (media_player_state)
    {        
        case MEDPLY_WIDGET_STATE_IDLE:
        {

            return VAPP_CUBE_MEDIA_PLAYER_STATE_INIT;
        }
   
        case MEDPLY_WIDGET_STATE_PLAY:
        {

            return VAPP_CUBE_MEDIA_PLAYER_STATE_PLAY;
        }
    
        case MEDPLY_WIDGET_STATE_PROCESSING:
        {

            return VAPP_CUBE_MEDIA_PLAYER_STATE_PROCESS;
        }

        default:
        {
            ASSERT(0);
        }
    }

    return VAPP_CUBE_MEDIA_PLAYER_STATE_INIT;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_media_player_apply
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_media_player_apply(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    MMI_ID   err_str_id = STR_GLOBAL_ERROR;
    mmi_event_notify_enum event_type = MMI_EVENT_FAILURE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_medply_widget_set_and_apply_index(index);
    ret = mmi_medply_widget_set_and_apply_index(index, &err_str_id, &event_type);
    if (ret == MMI_FALSE)
    {
        //stop play first
        vadp_v2p_cube_media_player_button_process(
            VAPP_CUBE_MEDIA_PLAYER_BUTTON_STOP,
            VAPP_CUBE_MEDIA_PLAYER_PEN_EVENT_DOWN
        );
        vadp_v2p_cube_media_player_button_process(
            VAPP_CUBE_MEDIA_PLAYER_BUTTON_STOP,
            VAPP_CUBE_MEDIA_PLAYER_PEN_EVENT_UP
        );  
        
        //mmi_display_popup(GetString(err_str_id),event_type);
        mmi_popup_display_simple(                   
            (WCHAR *)GetString(err_str_id),                                
            event_type,                                   
            GRP_ID_ROOT,                                 
            NULL);        
        
    }
    
    //////kal_printf("\n[Guoming] vadp_v2p_cube_media_player_apply() index = %d", index);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_media_player_get_info
 * DESCRIPTION
 *  Get information
 * PARAMETERS
 *  info_type       [IN]        Information type
 *  result_ptr      [OUT]       Result
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_media_player_get_info(vapp_cube_medply_info_type_enum info_type, void *result_ptr)
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
        case VAPP_CUBE_MEDIA_PLAYER_INFO_STATE:
        {
            /* U8 */
            U8 state;

            mmi_medply_widget_get_value(MMI_WIDGET_PLAYER_CUR_STATE, &state);
            *((U8*) result_ptr) = vadp_v2p_cube_media_player_state_transform(state);
            break;
        }

        case VAPP_CUBE_MEDIA_PLAYER_INFO_TITLE:
        {
            /* assign title string to result_ptr, max lengh MEDPLY_MAX_FILE_LEN */
            mmi_medply_widget_get_value(MMI_WIDGET_PLAYER_FILENAME, result_ptr);
            break;
        }

        case VAPP_CUBE_MEDIA_PLAYER_INFO_DURATION:
        {
            /* U64 */
            mmi_medply_widget_get_value(MMI_WIDGET_PLAYER_TOTAL_DURATION, result_ptr);
            break;
        }

        case VAPP_CUBE_MEDIA_PLAYER_INFO_CURR_TIME:
        {
            /* U64 */
            mmi_medply_widget_get_value(MMI_WIDGET_PLAYER_CUR_TIME, result_ptr);
            break;
        }

        default:
            ASSERT(0);
    }

}

void vadp_v2p_cube_media_player_set_shuffle(S32 shuf)
{
    srv_plst_shuffle_enum s = SRV_PLST_SHUFFLE_OFF;
    
    if (shuf)
    {
        s = SRV_PLST_SHUFFLE_ON;
    }
    //mmi_medply_settings_write_value(MMI_MEDPLY_SETTINGS_SHUFFULE, &shuf); 
    if (!g_adp_cube_mp_cntx.plst_srv_hdlr)
    {
        return;      
    }
    srv_plst_config_shuffle(g_adp_cube_mp_cntx.plst_srv_hdlr, s);
}

void vadp_v2p_cube_media_player_store_shuffle(S32 shuf)
{
    mmi_medply_settings_write_value(MMI_MEDPLY_SETTINGS_SHUFFULE, &shuf); 
}

void vadp_v2p_cube_media_player_get_shuffle(S32 *p_shuf)
{
    U8 shuf;
    mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_SHUFFULE, &shuf);
    *p_shuf = shuf;
}

void vadp_v2p_cube_media_player_set_repeat(S32 one, S32 all, S32 off)
{
    srv_plst_repeat_enum p;

    if (!g_adp_cube_mp_cntx.plst_srv_hdlr)
    {
        return;      
    }
    
    if (one)
    {

        p = SRV_PLST_REPEAT_ONE;
    }
    else if (all)
    {

        p = SRV_PLST_REPEAT_ALL;
    }
    else
    {

        p = SRV_PLST_REPEAT_OFF;
    }  


    srv_plst_config_repeat(g_adp_cube_mp_cntx.plst_srv_hdlr, p); 
}

void vadp_v2p_cube_media_player_store_repeat(S32 one, S32 all, S32 off)
{
    mmi_medply_settings_on_off_enum  r;

    
    if (one)
    {
        r = MMI_MEDPLY_SETTINGS_REPEAT_ONE;

    }
    else if (all)
    {
        r = MMI_MEDPLY_SETTINGS_REPEAT_ALL;

    }
    else
    {
        r = MMI_MEDPLY_SETTINGS_REPEAT_OFF;

    }
    
    mmi_medply_settings_write_value(MMI_MEDPLY_SETTINGS_REPEAT, &r);

}


void vadp_v2p_cube_media_player_get_repeat(S32 *p_one, S32 *p_all, S32 *p_off)
{
    U8  r;
    
    mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_REPEAT, &r);
    if (r == MMI_MEDPLY_SETTINGS_REPEAT_ONE)
    {
        *p_one = 1;
        *p_all = 0;
        *p_off = 0;
    }
    else if (r == MMI_MEDPLY_SETTINGS_REPEAT_ALL)
    {
        *p_one = 0;
        *p_all = 1;
        *p_off = 0;    
    }
    else
    {
        *p_one = 0;
        *p_all = 0;
        *p_off = 1;    
    }
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
S32 vadp_v2p_cube_media_player_get_imge_from_db(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    S32 w = 0;
    S32 h = 0;
    S32 ret_val = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_adp_cube_mp_cntx.plst_srv_hdlr == 0)
    {
        return MMI_FALSE;        
    }
    g_adp_cube_mp_cntx.curr_cache_index = index;
    g_adp_cube_mp_cntx.artwork_para.index = index;
    g_adp_cube_mp_cntx.artwork_para.buff_size = SRV_PLST_ARTWORK_RESIZED_WIDTH * SRV_PLST_ARTWORK_RESIZED_HEIGHT * 2;
    g_adp_cube_mp_cntx.artwork_para.string_ptr = (U32) g_adp_cube_mp_cntx.artwork_image_ptr;

    
    //////kal_printf("\n[Guoming] vadp_v2p_cube_media_player_get_imge_from_db() index = %d\n", index);
    ret = srv_plst_list_get_item_artwork_async(g_adp_cube_mp_cntx.plst_srv_hdlr, &g_adp_cube_mp_cntx.artwork_para);
    if (SRV_PLST_ASYNC == ret)
    {
        g_adp_cube_mp_cntx.state = VAPP_CUBE_MEDIA_PLAYER_STATE_LOADING;
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
 *  vadp_v2p_cube_media_player_cancel_get_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_media_player_cancel_get_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //////kal_printf("Cancel get data\n");
    if (g_adp_cube_mp_cntx.plst_srv_hdlr)
    {
        srv_plst_list_get_item_artwork_async_stop(g_adp_cube_mp_cntx.plst_srv_hdlr);    
    }

    g_adp_cube_mp_cntx.state = VAPP_CUBE_MEDIA_PLAYER_STATE_IDLE;
    g_adp_cube_mp_cntx.curr_cache_index = 0xFF;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_media_player_image_decode_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_media_player_image_decode_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (VAPP_CUBE_MEDIA_PLAYER_STATE_DECODING == g_adp_cube_mp_cntx.state)
    {
        if (g_adp_cube_mp_cntx.imageflow_callback)
        {
            g_adp_cube_mp_cntx.imageflow_callback(
                                g_adp_cube_mp_cntx.imageflow_userdata,
                                g_adp_cube_mp_cntx.curr_cache_index);
        }
        g_adp_cube_mp_cntx.state = VAPP_CUBE_MEDIA_PLAYER_STATE_IDLE;
        //////kal_printf("\n[Guoming] image_decode_done():  redraw %d ", g_adp_cube_mp_cntx.curr_cache_index);
    }
}

/*****************************************************************************
* Local Function 
*****************************************************************************/

#define VAPP_CBUE_MEDIA_PLAYER_CACHE_SERVICE_STATIC_FUNC


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cube_media_player_prepare
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mediacache_cube_media_player_prepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_eng_callbacks_struct callback_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callback_struct.cancel_decode_cell = srv_mediacache_cube_media_player_gdi_nb_decode_cancel;
    callback_struct.decode_cell = srv_mediacache_cube_media_player_get_data;
    callback_struct.get_file_name = NULL;
    callback_struct.search_cell = NULL;
    callback_struct.cancel_search_cell = NULL;
    srv_mediacache_register_engine(&callback_struct);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cube_media_player_get_data
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
MMI_BOOL srv_mediacache_cube_media_player_get_data(
            U32 *handle,
            srv_mediacache_cell_struct *cell_p,
            srv_mediacache_nb_decode_callback done_callback,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result;

    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ////kal_printf("Get image data from ENGIN\n"); */
    if (NULL == cell_p)
    {
        return MMI_FALSE;
    }

    g_cube_medply_user_data = user_data;
    g_cube_medply_cache_cell_p = cell_p;
    index = g_cube_medply_cache_cell_p->file_index;

    /* for currently it's not circle list, should adjust the index */
    if (g_adp_cube_mp_cntx.curr_focus_index - index > 8)
    {

        return MMI_FALSE;
    }
    if ((g_adp_cube_mp_cntx.curr_focus_index - index) < (-8))
    {

        return MMI_FALSE;
    }
    /* current */
    gdi_image_nb_stop(g_cube_medply_decode_handle);
    g_cube_medply_decode_handle = 0;
    if (g_cube_medply_cache_layer != 0)
    {
        gdi_layer_free(g_cube_medply_cache_layer);
        g_cube_medply_cache_layer = 0;
    }

    result = vadp_v2p_cube_media_player_get_imge_from_db(g_cube_medply_cache_cell_p->file_index);
    if (result < 0)
    {
        g_cube_medply_cache_cell_p->err_code = result;
        g_cube_medply_cache_cell_p->err_group = SRV_MEDIACACHE_ERR_GROUP_FS;
        g_cube_medply_cache_cell_p = NULL;
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cube_media_player_engine_nb_decode
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
MMI_BOOL srv_mediacache_cube_media_player_engine_nb_decode(
            S32 ret,
            U8 *img_buf,
            S32 img_width,
            S32 img_height,
            S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result = 0;

    srv_mediacache_pre_decode_enum is_user_cancel = SRV_MEDIACACHE_PRE_DECODE_CONTINUE;

    U32 buf_length = 0;
    S32 x, y, w, h, layer_w, layer_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_cube_medply_cache_cell_p)
    {
        ASSERT(0);
    }
    buf_length = srv_mediacache_cache_get_img_size_by_type(g_cube_medply_cache_cell_p->type);

    if (ret < 0)
    {
        g_cube_medply_cache_cell_p->err_code = ret;
        g_cube_medply_cache_cell_p->err_group = SRV_MEDIACACHE_ERR_GROUP_FS;
        g_cube_medply_cache_cell_p = NULL;
        //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_OPEN_FILE_ERR,fs_handle);
        //srv_mediacache_check_cb_and_call(g_cube_medply_cache_cell_p->file_index, MMI_TRUE);\\yongdiaoma?
        //g_cube_medply_cache_cell_p = NULL;
        //@TODO: How to notice media cache to cancel this cache
        srv_mediacache_decode_nb_decode_callback(
            (S32) SRV_MEDIACACHE_ERR_NOT_SUPPORT,
            SRV_MEDIACACHE_ERR_GROUP_GDI,
            g_cube_medply_user_data);
        return MMI_FALSE;
    }

    if (img_width <= 0 || img_height <= 0 || img_width > SRV_MEDIACACHE_DECODE_MAX_W_H ||
        img_height > SRV_MEDIACACHE_DECODE_MAX_W_H)
    {
        g_cube_medply_cache_cell_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;

        g_cube_medply_cache_cell_p->err_code = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
        g_cube_medply_cache_cell_p->err_group = SRV_MEDIACACHE_ERR_GROUP_MEDIACACHE;
        g_cube_medply_cache_cell_p = NULL;
        //g_cube_medply_cache_cell_p = NULL;
        //@TODO: How to notice media cache to cancel this cache
        srv_mediacache_decode_nb_decode_callback(
            (S32) SRV_MEDIACACHE_ERR_NOT_SUPPORT,
            SRV_MEDIACACHE_ERR_GROUP_GDI,
            g_cube_medply_user_data);
        return MMI_FALSE;
    }

    g_cube_medply_cache_cell_p->image_type = GDI_IMAGE_TYPE_JPG_FILE;
    srv_mediacache_cache_fill_cell_by_img(img_width, img_height, g_cube_medply_cache_cell_p);
    if (g_cube_medply_cache_cell_p->image_width <= 0 || g_cube_medply_cache_cell_p->image_height <= 0)
    {
        g_cube_medply_cache_cell_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
        g_cube_medply_cache_cell_p->err_code = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
        g_cube_medply_cache_cell_p->err_group = SRV_MEDIACACHE_ERR_GROUP_MEDIACACHE;
        g_cube_medply_cache_cell_p = NULL;
        srv_mediacache_decode_nb_decode_callback(
            (S32) SRV_MEDIACACHE_ERR_NOT_SUPPORT,
            SRV_MEDIACACHE_ERR_GROUP_GDI,
            g_cube_medply_user_data);
        return MMI_FALSE;
    }
    else
    {
        x = 0;
        y = 0;
        w = g_cube_medply_cache_cell_p->image_width;
        h = g_cube_medply_cache_cell_p->image_height;
        layer_w = g_cube_medply_cache_cell_p->image_width;
        layer_h = g_cube_medply_cache_cell_p->image_height;
        ASSERT(g_cube_medply_cache_cell_p->image_width > 0);
        ASSERT(g_cube_medply_cache_cell_p->image_height > 0);
        gdi_layer_create_using_outside_memory(
            0,
            0,
            layer_w,
            layer_h,
            &g_cube_medply_cache_layer,
            g_cube_medply_cache_cell_p->buffer,
            buf_length);
        gdi_layer_push_and_set_active(g_cube_medply_cache_layer);
        gdi_nb_set_done_callback(srv_mediacache_cube_media_player_decode_done_cb);
        gdi_nb_set_blt(MMI_FALSE, MMI_FALSE);
        g_cube_medply_decode_handle = gdi_image_nb_draw_resized_mem(x, y, w, h, img_buf, GDI_IMAGE_TYPE_JPG, size);
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
static void srv_mediacache_cube_media_player_decode_done_cb(GDI_RESULT result, gdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cube_medply_decode_handle != handle)
    {
        /* MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_DECODE_CB_NOT_MY); */
        return;
    }
    srv_mediacache_decode_nb_decode_callback((S32) result, SRV_MEDIACACHE_ERR_GROUP_GDI, g_cube_medply_user_data);

    if (0 == result)
    {
        vadp_v2p_cube_media_player_image_decode_done();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cube_media_player_gdi_nb_decode_cancel
 * DESCRIPTION
 *  callback function of non-block image decode
 * PARAMETERS
 *  handle          [IN]        GDI handle
 *  result(?)       [IN]        Result
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_mediacache_cube_media_player_gdi_nb_decode_cancel(U32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ////kal_printf("Get image data CANCEL from ENGIN\n"); */
    gdi_image_nb_stop(g_cube_medply_decode_handle);
    vadp_v2p_cube_media_player_cancel_get_image();
    g_cube_medply_decode_handle = 0;
    /* @TODO: Notify image flow to cancel load image. */

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_get_org_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  w           [?]         
 *  h           [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_mediacache_get_org_info(srv_handle handle, S32 *w, S32 *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 err_code = SRV_MEDIACACHE_OK;
    srv_mediacache_cell_struct *cell_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_mediacache_cache_cell_can_draw(g_mediacache_cntx_p->large_p) == MMI_TRUE)
    {
        cell_p = g_mediacache_cntx_p->large_p;
    }
    else if (srv_mediacache_cache_cell_can_draw(g_mediacache_cntx_p->level1_curr_p) == MMI_TRUE)
    {
        cell_p = g_mediacache_cntx_p->level1_curr_p;
    }
    else if (srv_mediacache_cache_cell_can_draw(g_mediacache_cntx_p->level2_curr_p) == MMI_TRUE)
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


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cube_media_player_get_data_cb
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
S32 srv_mediacache_cube_media_player_get_data_cb(S32 index, WCHAR *buffer, U32 length, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //////kal_printf("\n[Guoming] none used get_data_cb \n");
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_media_player_list_srv_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cb_event        [IN]        
 *  result          [IN]        
 *  ca_para_2       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 vadp_v2p_cube_media_player_list_srv_callback(srv_plst_cb_evt_enum cb_event, S32 result, U32 ca_para_2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret, w, h;
    S32 img_w = 0;
    S32 img_h = 0;
    S32 img_size = 0;
    U8 *ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((SRV_PLST_CB_EVT_GET_IMAGE == cb_event))
    {
        if (g_adp_cube_mp_cntx.curr_cache_index != (S32) g_adp_cube_mp_cntx.artwork_para.index)
        {
            return 0;
        }
        if (VAPP_CUBE_MEDIA_PLAYER_STATE_LOADING != g_adp_cube_mp_cntx.state)
        {
            return 0;
        }
        if (SRV_PLST_OK == result)
        {

            if (g_adp_cube_mp_cntx.artwork_para.buff_size > 0)
            {
                ret = gdi_image_get_dimension_mem(
                        GDI_IMAGE_TYPE_JPG,
                        g_adp_cube_mp_cntx.artwork_image_ptr,
                        g_adp_cube_mp_cntx.artwork_para.buff_size,
                        &w,
                        &h);
                /* ////kal_printf("Get image data callback HAVE DATA %d, %d, %d\n", w, h,g_adp_cube_mp_cntx.artwork_para.buff_size); */

                img_w = w;
                img_h = h;
                img_size = g_adp_cube_mp_cntx.artwork_para.buff_size;
                ptr = g_adp_cube_mp_cntx.artwork_image_ptr;
                srv_mediacache_cube_media_player_engine_nb_decode(0, ptr, img_w, img_h, img_size);
                g_adp_cube_mp_cntx.state = VAPP_CUBE_MEDIA_PLAYER_STATE_DECODING;
                return 0;
            }
        }
        g_adp_cube_mp_cntx.state = VAPP_CUBE_MEDIA_PLAYER_STATE_IDLE;
        /* ////kal_printf("Get image data callback NO DATA \n"); */
        srv_mediacache_cube_media_player_engine_nb_decode(-1, ptr, img_w, img_h, img_size);
        return 0;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_media_player_get_curr_img_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  err_group       [IN]        
 *  err_code        [IN]        
 *  user_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_media_player_get_curr_img_callback(S32 err_group, S32 err_code, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (err_code == 0)
    {
        /* ////kal_printf("\n[Guoming]vadp_v2p_cube_media_player_get_curr_img_callback()\n"); */
        if (g_adp_cube_mp_cntx.imageflow_callback)
        {
            /* g_adp_cube_mp_cntx.imageflow_callback(user_data, -1); */
        }

    }
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_media_player_is_back_light_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL vadp_v2p_cube_media_player_is_back_light_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return IsBacklightOn();
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_media_player_set_back_light_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_media_player_set_back_light_on(void)
{
    TurnOnBacklight(1); // 1: will be on for a time period  0: always on
}
#endif
