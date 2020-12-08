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
 *  MediaCacheSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Image Viewer Ex Srv.
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
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
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

#if defined(__MMI_SRV_MEDIACACHE__)

#include "gui.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "mmi_media_app_trc.h"
#include "kal_trace.h"
#include "string.h"
#include "app_str.h"
#include "stdio.h"
#include "stack_config.h"
#include "gdi_datatype.h"
#include "gdi_const.h"
#include "lcd_sw_rnd.h"
#include "gdi_include.h"
#include "lcd_sw_inc.h"
#include "MediaCacheSrvMem.h"
#include "Unicodexdcl.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "fs_type.h"
#include "app_datetime.h"
#include "gdi_imgdec.h"
#include "drm_def.h"
#include "drm_errcode.h"
#include "FileMgrType.h"
#include "FileMgrGProt.h"


#include "math.h"
#include "MMIDataType.h"
#include "custom_events_notify.h"
#include "Drm_gprot.h"         /* DRM support */

#if defined(__SQLITE3_SUPPORT__)
#include "sqlite3.h"
#include "sqlite3ex.h"
#include "MediaCacheDaemonGprot.h"
#endif
#include "MediaCacheSrvGprot.h"
#include "MediaCacheSrv.h"
#include "FileMgrSrvGProt.h"


#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
#include "med_utility.h"
#include "ImgEdtSrvGprot.h"
#endif  /*__MMI_SRV_MEDIA_CACHE_USE_SRV_IES__*/

#if defined(__MTK_INTERNAL_TTTTTTTTTT__)
#define SRV_MEDIACACHE_CACHE_PRINT_DBGTRACE()       srv_mediacache_cache_print_dbgtrace_func()
#define SRV_MEDIACACHE_CACHE_INDEX_PRINT_DBGTRACE() srv_mediacache_cache_index_print_dbgtrace_func()
#define SRV_MEDIACACHE_LINK_ASSERT_NO_RING(curr_p)  srv_mediacache_link_assert_no_ring_func(curr_p)
#define SRV_MEDIACACHE_CB_CHANGED()                 MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_CB_CHANGED,g_mediacache_cntx_p->app_data_cb, g_mediacache_cntx_p->cb_file_idx, __LINE__)
#else
#define SRV_MEDIACACHE_CACHE_PRINT_DBGTRACE()   
#define SRV_MEDIACACHE_CACHE_INDEX_PRINT_DBGTRACE()
#define SRV_MEDIACACHE_LINK_ASSERT_NO_RING(curr_p)
#define SRV_MEDIACACHE_CB_CHANGED()
#endif

#ifdef __MMI_MEDIA_CACHE_YUV_THUMB__
#include "iul_color_convert.h"
#include "iul_csc_y2r.h"
#endif

#define __SRV_USE_GDI_CODEC_BACKGROUND_DECODE__

//add by scalado vincent

#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__MM_DEBUG_MEASURE_SRVMC__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    #define IES_START_CTX_LOGGING(_symbol_)
    #define IES_STOP_CTX_LOGGING(_symbol_)
#endif

/***************************************************************************** 
* Local Variable
*****************************************************************************/
srv_mediacache_cntx_struct *g_mediacache_cntx_p_array[SRV_MEDIACACHE_INSTANCE_NUM];
srv_mediacache_cntx_struct *g_mediacache_cntx_p = NULL;
srv_mediacache_engine_cntx_struct g_mediacache_engine_cntx;

/***************************************************************************** 
* Function Declaration
*****************************************************************************/
#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
static MMI_BOOL srv_mediacache_is_have_ies_image_handle(srv_mediacache_cell_struct* curr_p, void *user_data);
static void srv_mediacache_release_ies_handle(void);
static MMI_BOOL _srv_mediacache_decode_need_ies_check(srv_mediacache_cell_struct *cell_p);
static MMI_BOOL _srv_mediacache_decode_cell_with_ies(srv_mediacache_cell_struct *cell_p, 
                                                         const WCHAR* filename_p, 
                                                         U32 buf_length, 
                                                         S32 layer_w, 
                                                         S32 layer_h,
                                                         U32 *pDecodeHandle);
static MMI_BOOL srv_mediacache_preview_render_buffer_to_cell_async(srv_mediacache_cell_struct *cell_p);
static MMI_BOOL srv_mediacache_is_ies_image_ready(srv_mediacache_cell_struct *cell_p, srv_mediacache_img_to_layer_struct *area);
static void srv_mediacache_delete_image_handle_if_needed(srv_mediacache_cell_struct *curr_p);
static void srv_mediacache_create_image_handle_if_needed(srv_mediacache_cell_struct *curr_p);

static void srv_mediacache_save_meta_to_db_callback(S32 err, void *user_data);
static void srv_mediacache_db_put_meta(srv_mediacache_cell_struct *cell, ivd_req_callback finish_callback, void *user_data);
static MMI_BOOL srv_mediacache_db_get_meta(srv_mediacache_cell_struct *cell, MMI_BOOL is_blocking, ivd_req_callback finish_callback);
static MMI_BOOL srv_mediacache_create_meta_if_needed(srv_handle handle, 
                                                         srv_mediacache_cell_struct *cell_p, 
                                                         const WCHAR* filename_p, 
                                                         S32 layer_w, 
                                                         S32 layer_h);
static MMI_BOOL srv_mediacache_image_render_buffer_to_cell_async(srv_handle handle, 
                                                         srv_mediacache_cell_struct *cell_p, 
                                                         const WCHAR* filename_p, 
                                                         U32 buf_length, 
                                                         S32 layer_w, 
                                                         S32 layer_h);
static MMI_BOOL srv_mediacache_cache_meta_is_not_saved(srv_mediacache_cell_struct* curr_p, void *user_data);
static void srv_mediacache_save_cell_img_to_file(srv_mediacache_cell_struct *cell_p);
static void srv_mediacache_copy_the_buffer_if_needed(PU8 source, PU8 dest, S32 length);
static  void _srv_mediacache_release_image_handle_if_needed(void);
static void srv_mediacache_free_meta_handle_if_needed(srv_handle handle, srv_mediacache_cell_struct *cell_p);
static void srv_mediacache_cancel_nb_render(srv_mediacache_cell_struct *cell_p, MMI_BOOL reNew);
static void _srv_mediacache_get_filetype_if_needed(srv_mediacache_cell_struct *cell_p);
static void srv_mediacache_create_meta_handle(S32 meta_ret, U8* meta_buffer, S32 meta_buffer_length, srv_mediacache_cell_struct* cell_p);
static void srv_mediacache_create_meta_handle_for_rest_cell(srv_handle handle);
static void srv_mediacache_meta_save_to_db_callback(S32 err, void *user_data);

static GDI_RESULT _srv_mediacache_gdi_result_from_ies_result(srv_ies_result ies_result);

//#define __SRV_MEDIACACHE_INTERNAL_TEST__

#endif

static MMI_BOOL srv_mediacache_cache_cell_finished2(srv_mediacache_cell_struct *cell);

/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_check_and_start_decode
 * DESCRIPTION
 *  check if decode timer is started, if not start it
 * PARAMETERS
 *  void
 * RETURNS
 *  NULL
 *****************************************************************************/
static void srv_mediacache_check_and_start_decode(void)
{
    if (NULL == g_mediacache_cntx_p)
    {
        return;
    }
    if (MMI_FALSE == g_mediacache_cntx_p->is_schedule_timer_started)
    {
        g_mediacache_cntx_p->is_schedule_timer_started = MMI_TRUE;
        gui_start_timer(SRV_MEDIACACHE_DECODE_TIME_GAP_SHORT, srv_mediacache_decode_schedule);  
    }
}


static void srv_mediacache_check_and_start_decode_at_once(void)
{
    if (NULL == g_mediacache_cntx_p)
    {
        return;
    }
    if (MMI_FALSE == g_mediacache_cntx_p->is_schedule_timer_started)
    {
        g_mediacache_cntx_p->is_schedule_timer_started = MMI_TRUE;
        srv_mediacache_decode_schedule();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_stop_decode
 * DESCRIPTION
 *  check if decode timer is stoped, if not stop it
 * PARAMETERS
 *  void
 * RETURNS
 *  NULL
 *****************************************************************************/
static void srv_mediacache_stop_decode(void)
{
    if (NULL == g_mediacache_cntx_p)
    {
        return;
    }
    if (MMI_TRUE == g_mediacache_cntx_p->is_schedule_timer_started)
    {
        g_mediacache_cntx_p->is_schedule_timer_started = MMI_FALSE;
        gui_cancel_timer(srv_mediacache_decode_schedule);  
    }
}


#if defined(__MTK_INTERNAL_TTTTTTTTTT__)
/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_link_assert_no_ring
 * DESCRIPTION
 *  simple check if double link has ring, need improve later
 * PARAMETERS
 *  curr_p   [IN]  any cell of the link
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mediacache_link_assert_no_ring_func(srv_mediacache_cell_struct *curr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *temp_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == curr_p)
    {
        return;
    }
    temp_p = curr_p;
    if (NULL != temp_p->next)
    { 
        temp_p = temp_p->next;
        while (NULL != temp_p)
        {
            temp_p = temp_p->next;
            ASSERT(curr_p != temp_p);
        }
        
    }
    temp_p = curr_p;
    if (NULL != temp_p->prev)
    { 
        temp_p = temp_p->prev;
        while (NULL != temp_p)
        {
            temp_p = temp_p->prev;
            ASSERT(curr_p != temp_p);
        }
        
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_link_get_prev_block_count
 * DESCRIPTION
 *  get the count of the blocks prev
 * PARAMETERS
 *  cell_p   [IN]  cell of the link
 * RETURNS
 *  the count
 *****************************************************************************/
static S32 srv_mediacache_link_get_prev_block_count(srv_mediacache_cell_struct *cell_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *temp_p = cell_p;
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_MEDIACACHE_LINK_ASSERT_NO_RING(cell_p);
    i = -1;
    while (temp_p != NULL)
    {
        temp_p = temp_p->prev;
        i++;
    }
    return i;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_link_get_next_block_count
 * DESCRIPTION
 *  get the count of the blocks next
 * PARAMETERS
 *  cell_p   [IN]  cell of the link
 * RETURNS
 *  the count
 *****************************************************************************/
static S32 srv_mediacache_link_get_next_block_count(srv_mediacache_cell_struct *cell_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *temp_p = cell_p;
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_MEDIACACHE_LINK_ASSERT_NO_RING(cell_p);
    if(NULL == cell_p)
    {
        return 0;
    }

    i = -1;
    while (temp_p != NULL)
    {
        temp_p = temp_p->next;
        i++;
    }
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_link_get_first
 * DESCRIPTION
 *  get the head of the link
 * PARAMETERS
 *  *cell_p   [IN]   any cell
 * RETURNS
 *  the first cell
 *****************************************************************************/
static srv_mediacache_cell_struct *srv_mediacache_link_get_first(srv_mediacache_cell_struct *cell_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *first_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cell_p == NULL)
    {
        return NULL;
    }
    SRV_MEDIACACHE_LINK_ASSERT_NO_RING(cell_p);
    first_p = cell_p;
    while (first_p->prev != NULL)
    {
        first_p = first_p->prev;
    }
    return first_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cache_print_dbgtrace
 * DESCRIPTION
 *  print SRV cache state, for debug
 * PARAMETERS
 *  *cache   [IN]   pointer of cache
 * RETURNS
 *  void
 *****************************************************************************/
static srv_mediacache_cell_struct *srv_mediacache_link_get_last(srv_mediacache_cell_struct *cell_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *last_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cell_p == NULL)
    {
        return NULL;
    }
    SRV_MEDIACACHE_LINK_ASSERT_NO_RING(cell_p);
    last_p = cell_p;
    while (last_p->next != NULL)
    {
        last_p = last_p->next;
    }
    return last_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cache_print_dbgtrace
 * DESCRIPTION
 *  print SRV cache state, for debug
 * PARAMETERS
 *  *cache   [IN]   pointer of cache
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mediacache_link_remove_cell(srv_mediacache_cell_struct *cell_p, srv_mediacache_cell_struct *cell_to_remove_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *first_p;
    srv_mediacache_cell_struct *prev_p;
    srv_mediacache_cell_struct *next_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cell_p == NULL)
    { 
        return;
    }
    first_p = srv_mediacache_link_get_first(cell_p);
    while (first_p != NULL)
    {
        if (first_p == cell_to_remove_p)
        {
            prev_p = cell_to_remove_p->prev;
            next_p = cell_to_remove_p->next;
            if (NULL != prev_p)
            {
                prev_p->next = next_p;
            }
            if (NULL != next_p)
            {
                next_p->prev = prev_p;
            }
            cell_to_remove_p->prev = NULL;
            cell_to_remove_p->next = NULL;
            break;
        }
        first_p = first_p->next;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cache_print_dbgtrace
 * DESCRIPTION
 *  print SRV cache state, for debug
 * PARAMETERS
 *  *cache   [IN]   pointer of cache
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mediacache_link_add_to_end(srv_mediacache_cell_struct *curr_p, srv_mediacache_cell_struct *new_cell_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *last_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_CC_ADD_END);
    ASSERT (curr_p != NULL);
    ASSERT (curr_p != new_cell_p);
    SRV_MEDIACACHE_LINK_ASSERT_NO_RING(curr_p);
    last_p = curr_p;
    while (NULL != last_p->next)
    {
        last_p = last_p->next;
    }
    last_p->next = new_cell_p;
    new_cell_p->prev = last_p;
    SRV_MEDIACACHE_LINK_ASSERT_NO_RING(curr_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cache_print_dbgtrace
 * DESCRIPTION
 *  print SRV cache state, for debug
 * PARAMETERS
 *  *cache   [IN]   pointer of cache
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mediacache_link_add_to_head(srv_mediacache_cell_struct *curr_p, srv_mediacache_cell_struct *new_cell_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *first_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_CC_ADD_HEAD);
    ASSERT (curr_p != NULL);
    ASSERT (curr_p != new_cell_p);
    SRV_MEDIACACHE_LINK_ASSERT_NO_RING(curr_p);
    first_p = curr_p;
    while (NULL != first_p->prev)
    {
        first_p = first_p->prev;
    }
    first_p->prev = new_cell_p;
    new_cell_p->next = first_p;
    SRV_MEDIACACHE_LINK_ASSERT_NO_RING(curr_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cache_print_dbgtrace
 * DESCRIPTION
 *  print SRV cache state, for debug
 * PARAMETERS
 *  *cache   [IN]   pointer of cache
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mediacache_link_balance_add(srv_mediacache_cell_struct *curr_p, srv_mediacache_cell_struct *new_cell_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *prev_p;
    srv_mediacache_cell_struct *next_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT (curr_p != NULL);
    prev_p = curr_p;
    next_p = curr_p;
    while (NULL != next_p && NULL != prev_p)
    {
        if (NULL == next_p->next)
        {
            next_p->next = new_cell_p;
            new_cell_p->prev = next_p;
            new_cell_p->next = NULL;
            break;
        }
        if (NULL == prev_p->prev)
        {
            prev_p->prev = new_cell_p;
            new_cell_p->next = prev_p;
            new_cell_p->prev = NULL;
            break;
        }
        next_p = next_p->next;
        prev_p = prev_p->prev;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_decode_level2_default_method
 * DESCRIPTION
 *  find unfinished cell of previous or next at group 2
 * PARAMETERS
 *  void
 * RETURNS
 *  NULL or the pointer to the unfinished cell
 *****************************************************************************/
static srv_mediacache_cell_struct *srv_mediacache_link_line_check(
                srv_mediacache_cell_struct* curr_p, 
                srv_mediacache_cache_finish_check_func cell_finished_check_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *next_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NULL == curr_p)
    {
        return NULL;
    }
    next_p = curr_p;
    while (next_p != NULL)
    {
        if (cell_finished_check_func(next_p, user_data) == MMI_TRUE)
        {
            return next_p;
        }
        if (next_p != NULL)
        {
            next_p = next_p->next;
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_decode_level2_default_method
 * DESCRIPTION
 *  find unfinished cell of previous or next at group 2
 * PARAMETERS
 *  void
 * RETURNS
 *  NULL or the pointer to the unfinished cell
 *****************************************************************************/
static srv_mediacache_cell_struct *srv_mediacache_link_pingpang_check(
                srv_mediacache_cell_struct* curr_p, 
                MMI_BOOL is_prev_first,
                srv_mediacache_cache_finish_check_func cell_finished_check_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *prev_p;
    srv_mediacache_cell_struct *next_p;
    srv_mediacache_cell_struct *first_check_p = NULL;
    srv_mediacache_cell_struct *second_check_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NULL == curr_p)
    {
        return NULL;
    }
    SRV_MEDIACACHE_LINK_ASSERT_NO_RING(curr_p);
    prev_p = curr_p->prev;
    next_p = curr_p->next;
    if (cell_finished_check_func(curr_p, user_data) == MMI_TRUE)
    {
        return curr_p;
    }
    while (prev_p != NULL || next_p != NULL)
    {
        if (is_prev_first == MMI_TRUE)
        {
            first_check_p = prev_p;
            second_check_p = next_p;
        }
        else
        {
            first_check_p = next_p;
            second_check_p = prev_p;
        }
        if (first_check_p != NULL)
        {
            if (cell_finished_check_func(first_check_p, user_data) == MMI_TRUE)
            {
                return first_check_p;
            }
        }
        if (second_check_p != NULL)
        {
            if (cell_finished_check_func(second_check_p, user_data) == MMI_TRUE)
            {
                return second_check_p;
            }
        }
        if (prev_p != NULL)
        {
            prev_p = prev_p->prev;
        }
        if (next_p != NULL)
        {
            next_p = next_p->next;
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_switch_next
 * DESCRIPTION
 *  move the image to left
 * PARAMETERS
 *  void
 * RETURNS
 *  error code
 *****************************************************************************/
static srv_mediacache_cell_struct* srv_mediacache_link_roll_next(srv_mediacache_cell_struct *curr_p, srv_mediacache_cell_struct **new_first_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *first_p;
    srv_mediacache_cell_struct *last_p;
    S32 file_index;
    S32 new_curr_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == curr_p)
    {
        return NULL;
    }
    new_curr_index = curr_p->file_index + 1;
    if (new_curr_index >= g_mediacache_engine_cntx.file_count)
    {
        new_curr_index = 0;
    }
    kal_get_time(&g_mediacache_cntx_p->start_ticks);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_CC_ROLL_NEXT);
    first_p = srv_mediacache_link_get_first(curr_p);
    last_p = srv_mediacache_link_get_last(curr_p);
    ASSERT(NULL != first_p);
    ASSERT(NULL != last_p);
    ASSERT(NULL != curr_p);
    file_index = last_p->file_index + 1;
    if (file_index >= g_mediacache_engine_cntx.file_count)
    {
        file_index = 0;
    }
    if (srv_mediacache_link_get_next_block_count(first_p) == 1)
    {
        if (NULL != curr_p->next)
        {
            curr_p = curr_p->next;
        }
        else
        {

            curr_p = curr_p->prev;
        }
    }
    else if (NULL != curr_p->next)
    {
        curr_p = curr_p->next;
        /*break first from list, add to last*/
        srv_mediacache_link_remove_cell(curr_p, first_p);
        if (file_index == first_p->file_index)
        {
            srv_mediacache_link_add_to_end(curr_p, first_p);
        }
        else if (MMI_TRUE == first_p->is_lock)
        {
            if (NULL == g_mediacache_cntx_p->locked_cell_p)
            { 
                g_mediacache_cntx_p->locked_cell_p = first_p;
            }
            else
            {
                srv_mediacache_link_add_to_end(g_mediacache_cntx_p->locked_cell_p, first_p);
            }
        }
        else
        {
            srv_mediacache_link_add_to_end(curr_p, first_p);
            /*check file next here*/
            if (file_index != first_p->file_index)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_RESET_CELL_LINE, __LINE__);
                srv_mediacache_cache_reset_cell(first_p, MMI_FALSE);
                first_p->file_index = file_index;
            }
        }
        SRV_MEDIACACHE_LINK_ASSERT_NO_RING(curr_p);
    }
    else
    {
        /*only one cache*/
        if (MMI_TRUE == curr_p->is_lock)
        {
            ASSERT(curr_p->prev == NULL);
            /*Add locked to locked link*/
            if (NULL == g_mediacache_cntx_p->locked_cell_p)
            { 
                g_mediacache_cntx_p->locked_cell_p = curr_p;
            }
            else
            {
                srv_mediacache_link_add_to_end(g_mediacache_cntx_p->locked_cell_p, curr_p);
            }
            curr_p = NULL;
        }
        else
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_RESET_CELL_LINE, __LINE__);
            srv_mediacache_cache_reset_cell(curr_p, MMI_FALSE);
            curr_p->file_index = file_index;
        }
    }
    if (NULL != curr_p)
    {
        if (curr_p->file_index != new_curr_index)
        {
            srv_mediacache_cache_fill_index_to_link(
                curr_p, 
                new_curr_index, 
                g_mediacache_engine_cntx.file_count);
        }
    }
    *new_first_p = srv_mediacache_link_get_first(curr_p);
    SRV_MEDIACACHE_LINK_ASSERT_NO_RING(curr_p);
    srv_mediacache_check_and_start_decode();  
    return curr_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_switch_next
 * DESCRIPTION
 *  move the image to left
 * PARAMETERS
 *  void
 * RETURNS
 *  error code
 *****************************************************************************/
static srv_mediacache_cell_struct* srv_mediacache_link_roll_prev(srv_mediacache_cell_struct *curr_p, srv_mediacache_cell_struct **new_first_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *first_p;
    srv_mediacache_cell_struct *last_p;
    S32 file_index;
    S32 new_curr_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == curr_p)
    {
        return NULL;
    }
    new_curr_index = curr_p->file_index - 1;
    if (new_curr_index < 0)
    {
        new_curr_index = g_mediacache_engine_cntx.file_count - 1;
    }
    kal_get_time(&g_mediacache_cntx_p->start_ticks);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_CC_ROLL_PREV);
    first_p = srv_mediacache_link_get_first(curr_p);
    last_p = srv_mediacache_link_get_last(curr_p);
    ASSERT(NULL != first_p);
    ASSERT(NULL != last_p);
    ASSERT(NULL != curr_p);
    file_index = first_p->file_index - 1;
    if (file_index < 0)
    {
        file_index = g_mediacache_engine_cntx.file_count - 1;
    }
    if (srv_mediacache_link_get_next_block_count(first_p) == 1)
    {
        if (NULL != curr_p->next)
        {
            curr_p = curr_p->next;
        }
        else
        {

            curr_p = curr_p->prev;
        }
    }
    else if (NULL != curr_p->prev)
    {
        curr_p = curr_p->prev;
        /*break first from list, add to last*/
        srv_mediacache_link_remove_cell(curr_p, last_p);
        if (file_index == last_p->file_index)
        {
            srv_mediacache_link_add_to_head(curr_p, last_p);
        }
        else if (MMI_TRUE == last_p->is_lock)
        {
            if (NULL == g_mediacache_cntx_p->locked_cell_p)
            { 
                g_mediacache_cntx_p->locked_cell_p = last_p;
            }
            else
            {
                srv_mediacache_link_add_to_end(g_mediacache_cntx_p->locked_cell_p, last_p);
            }
        }
        else
        {
            srv_mediacache_link_add_to_head(curr_p, last_p);
            /*check file next here*/
            if (file_index != last_p->file_index)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_RESET_CELL_LINE, __LINE__);
                srv_mediacache_cache_reset_cell(last_p, MMI_FALSE);
                last_p->file_index = file_index;
            }
        }
        SRV_MEDIACACHE_LINK_ASSERT_NO_RING(curr_p);
    }
    else
    {
        /*only one cache*/
        if (MMI_TRUE == curr_p->is_lock)
        {
            ASSERT(curr_p->next == NULL);
            /*Add locked to locked link*/
            if (NULL == g_mediacache_cntx_p->locked_cell_p)
            { 
                g_mediacache_cntx_p->locked_cell_p = curr_p;
            }
            else
            {
                srv_mediacache_link_add_to_end(g_mediacache_cntx_p->locked_cell_p, curr_p);
            }
            curr_p = NULL;
        }
        else
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_RESET_CELL_LINE, __LINE__);
            srv_mediacache_cache_reset_cell(curr_p, MMI_FALSE);
            curr_p->file_index = file_index;
        }
    }
    if (NULL != curr_p)
    {
        if (curr_p->file_index != new_curr_index)
        {
            srv_mediacache_cache_fill_index_to_link(
                curr_p, 
                new_curr_index, 
                g_mediacache_engine_cntx.file_count);
        }
    }
    *new_first_p = srv_mediacache_link_get_first(curr_p);
    SRV_MEDIACACHE_LINK_ASSERT_NO_RING(curr_p);
    srv_mediacache_check_and_start_decode();  
    return curr_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_switch_next
 * DESCRIPTION
 *  move the image to left
 * PARAMETERS
 *  void
 * RETURNS
 *  error code
 *****************************************************************************/
static srv_mediacache_cell_struct* srv_mediacache_link_get_center(srv_mediacache_cell_struct *curr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *first_p;
    srv_mediacache_cell_struct *temp_p;
    S32 count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == curr_p)
    {
        return NULL;
    }
    kal_get_time(&g_mediacache_cntx_p->start_ticks);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_CC_GET_CENTER);
    first_p = srv_mediacache_link_get_first(curr_p);
    temp_p = first_p;
    count = srv_mediacache_link_get_next_block_count(first_p);
    count = count/2;
    while (count > 0 && NULL != temp_p)
    {
        temp_p = temp_p->next;
        count--;
    }
    return temp_p;
}


#if defined(__MTK_INTERNAL_TTTTTTTTTT__)
/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cache_print_dbgtrace
 * DESCRIPTION
 *  print SRV cache state, for debug
 * PARAMETERS
 *  *cache   [IN]   pointer of cache
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mediacache_cache_index_print_dbgtrace_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *first_p;
    CHAR tempbuff[202];
    CHAR tt[10];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    first_p = srv_mediacache_link_get_first(g_mediacache_cntx_p->level1_curr_p);
    memset(tempbuff, 0, 2);
    while (NULL != first_p)
    {
        sprintf(tt,"%d%c ",first_p->file_index, '@' + first_p->is_lock);
        strcat(tempbuff, tt);
        if (first_p->next != NULL)
        {
            if (first_p->file_index <= first_p->next->file_index)
            {
                ASSERT(first_p->file_index + 1 == first_p->next->file_index);
            }
            else
            {
                ASSERT(0 == first_p->next->file_index);
            }
        }
        first_p = first_p->next;
        if (strlen(tempbuff) > 100)
        {
            kal_print_string_trace(MOD_MMI_MEDIA_APP, MMI_MEDIA_TRC_G3_APP_DETAIL, "[MEDCACHE][L1]%s", tempbuff);
            memset(tempbuff, 0, 2);
        }
    }
    if (strlen(tempbuff) > 0)
    {
        kal_print_string_trace(MOD_MMI_MEDIA_APP, MMI_MEDIA_TRC_G3_APP_DETAIL, "[MEDCACHE][L1]%s", tempbuff);
    }

    first_p = srv_mediacache_link_get_first(g_mediacache_cntx_p->level2_curr_p);
    memset(tempbuff, 0, 2);
    while (NULL != first_p)
    {
        if (g_mediacache_cntx_p->level2_curr_p == first_p)
        {
            strcat(tempbuff, "Curr>>");
        }
        if (first_p->is_lock)
        {
            strcat(tempbuff, "@");
        }
        sprintf(tt,"%d ",first_p->file_index);
        strcat(tempbuff, tt);
        if (first_p->next != NULL)
        {
            if (first_p->file_index <= first_p->next->file_index)
            {
                ASSERT(first_p->file_index == first_p->next->file_index - 1);
            }
            else
            {
                ASSERT(0 == first_p->next->file_index);
            }
        }
        first_p = first_p->next;
        if (strlen(tempbuff) > 100)
        {

            kal_print_string_trace(MOD_MMI_MEDIA_APP, MMI_MEDIA_TRC_G3_APP_DETAIL, "[MEDCACHE][L2]%s", tempbuff);
            memset(tempbuff, 0, 2);
        }
    }
    if (strlen(tempbuff) > 0)
    {
        kal_print_string_trace(MOD_MMI_MEDIA_APP, MMI_MEDIA_TRC_G3_APP_DETAIL, "[MEDCACHE][L2]%s", tempbuff);
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_set_qulity_high
 * DESCRIPTION
 *  set the qulity to high use LRZ resizer. After resize APIs are called, restore to default.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mediacache_set_qulity_high(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NULL == g_mediacache_cntx_p)
    {
        return;
    }
    g_mediacache_cntx_p->qulity = SRV_MEDIACACHE_RESIZE_QULITY_HIGH;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_set_qulity_low
 * DESCRIPTION
 *  set the qulity to fast, in case mcu too slow. After resize APIs are called, restore to default.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mediacache_set_qulity_low(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NULL == g_mediacache_cntx_p)
    {
        return;
    }
    g_mediacache_cntx_p->qulity = SRV_MEDIACACHE_RESIZE_QULITY_FAST;
}


/*****************************************************************************
 * FUNCTION
 *  _srv_mediacache_quality_to_gdi_quality
 * DESCRIPTION
 *  convert quality enum to GDI quality
 * PARAMETERS
 *  quality [IN] quality enum
 * RETURNS
 *  GDI quality enum
 *****************************************************************************/
static gdi_resizer_enum _srv_mediacache_quality_to_gdi_quality(srv_mediacache_resize_qulity_enum quality)
{
    switch(quality)
    {
    case SRV_MEDIACACHE_RESIZE_QULITY_DEFAULT:
        return GDI_RESIZER_SW_QUALITY_MEDIUM;

    case SRV_MEDIACACHE_RESIZE_QULITY_HIGH:
        return GDI_RESIZER_SW_QUALITY_HIGH;

    case SRV_MEDIACACHE_RESIZE_QULITY_FAST:
        return GDI_RESIZER_SW_QUALITY_LOW;

    default:
        return GDI_RESIZER_SW_QUALITY_MEDIUM;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_set_last_err
 * DESCRIPTION
 *  when find error ivsrv will set last error by this function, app can get it
 *  by call srv_mediacache_get_last_err.
 * PARAMETERS
 *  err_group   [IN]   error group
 *  err_code    [IN]   error code
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mediacache_set_last_err(S32 err_group, S32 err_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mediacache_cntx_p->last_err_grp   = err_group;
    g_mediacache_cntx_p->last_err_code  = err_code;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_set_last_err
 * DESCRIPTION
 *  when find error ivsrv will set last error by this function, app can get it
 *  by call srv_mediacache_get_last_err.
 * PARAMETERS
 *  err_group   [IN]   error group
 *  err_code    [IN]   error code
 * RETURNS
 *  void
 *****************************************************************************/
static S32 srv_mediacache_get_bits_per_pixel(gdi_color_format cf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GDI_COLOR_FORMAT_16 == cf)
    {
        return 2;
    }
    else if (GDI_COLOR_FORMAT_24 == cf)
    {
        return 3;
    }
    else if (GDI_COLOR_FORMAT_32 == cf)
    {
        return 4;
    }
    else if (GDI_COLOR_FORMAT_32_PARGB == cf)
    {
        return 5;
    }
    else if(cf == GDI_COLOR_FORMAT_MAINLCD)
    {
        return GDI_MAINLCD_BIT_PER_PIXEL;
    }
    ASSERT(0);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_check_cb_and_call
 * DESCRIPTION
 *  check if the callback function if ok and file is the app want one
 * PARAMETERS
 *  file_index  [IN]    file index
 *  clear_cb    [IN]    clear the callback after called it
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mediacache_check_cb_and_call(srv_mediacache_cell_struct  *cell_p, S32 file_index, MMI_BOOL clear_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_data_cb    app_data_cb;
    void *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mediacache_cntx_p->app_data_cb != NULL && file_index == cell_p->file_index)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_DECODE_CB_APP, file_index, cell_p->err_code);
        app_data_cb = g_mediacache_cntx_p->app_data_cb;
        user_data = g_mediacache_cntx_p->user_data;
        if (clear_cb == MMI_TRUE)
        {
            g_mediacache_cntx_p->app_data_cb = NULL;
            g_mediacache_cntx_p->cb_file_idx = SRV_MEDIACACHE_DUMMY_FILE_IDX;
            SRV_MEDIACACHE_CB_CHANGED();
        }
        srv_mediacache_set_last_err(cell_p->err_group, cell_p->err_code);
        app_data_cb(cell_p->err_group, cell_p->err_code, user_data);
    }
}

static void srv_mediacache_callback_to_app_if_needed()
{
    srv_mediacache_cell_struct  *decoding_p = g_mediacache_cntx_p->decoding_p;
    // clear decoding_p before callback to APP.
    // because APP may start another decoding job during the callback.
    g_mediacache_cntx_p->decoding_p = NULL;
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_DECODING_P_IS_NULL_D, __LINE__);
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SRVMC] srv_mediacache_callback_to_app_if_needed @%d", __LINE__);

    if (g_mediacache_cntx_p->app_data_cb != NULL &&
        g_mediacache_cntx_p->cb_file_idx == decoding_p->file_index)
    {
        srv_mediacache_set_last_err(decoding_p->err_group, decoding_p->err_code);
        if (g_mediacache_cntx_p->large_p == NULL && g_mediacache_cntx_p->level1_curr_p == NULL ||
            g_mediacache_cntx_p->large_p == NULL && decoding_p->type == SRV_MEDIACACHE_CACHE_TYPE_L1)
        {
            srv_mediacache_check_cb_and_call(decoding_p, decoding_p->file_index, MMI_TRUE);
        }
        else if (g_mediacache_cntx_p->large_p != NULL)
        {
            if (g_mediacache_cntx_p->large_p->file_index != decoding_p->file_index ||
                decoding_p == g_mediacache_cntx_p->large_p ||
                srv_mediacache_cache_cell_finished(g_mediacache_cntx_p->large_p) == MMI_TRUE)
            {
                srv_mediacache_check_cb_and_call(decoding_p, decoding_p->file_index, MMI_TRUE);
            }
            else
            {
                srv_mediacache_check_cb_and_call(decoding_p, decoding_p->file_index, MMI_FALSE);
            }
        }
        else
        {
            srv_mediacache_check_cb_and_call(decoding_p, decoding_p->file_index, MMI_FALSE);
        }
    }
}
   
/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_is_index_match
 * DESCRIPTION
 *  find unfinished cell of previous or next at group 2
 * PARAMETERS
 *  void
 * RETURNS
 *  NULL or the pointer to the unfinished cell
 *****************************************************************************/
static MMI_BOOL srv_mediacache_is_index_match(srv_mediacache_cell_struct* curr_p, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = *((S32*)user_data);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (curr_p->file_index == index)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_ex_define_db_io_buffer_length
 * DESCRIPTION
 *  set IO buffer size
 * PARAMETERS
 *  length            [IN]    IO buffer length 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mediacache_ex_define_db_io_buffer_length(U32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mediacache_cntx_p->userdef_db_io_buffer_length = length;
}

static MMI_BOOL srv_mediacache_file_limit_check(WCHAR *filename, CHAR **error_str_pp)
{
#ifdef __COSMOS_MMI_PACKAGE__
    // COSMOS does not have fmgr limit check
    return MMI_TRUE;
#else
    return (MMI_BOOL)mmi_fmgr_util_file_limit_check(FMGR_LIMIT_IMAGE_VIEWER, (CHAR*)filename, error_str_pp);    
#endif
}

#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)

static void srv_mediacache_db_start_cb(S32 err, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (err < 0)
    {
        g_mediacache_cntx_p->is_db_start_ok = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_create
 * DESCRIPTION
 *  image viewer service create function 
 * PARAMETERS
 *  canvas_width            [IN]    The canvas width(will be the width of L1 buffer) 
 *  canvas_height           [IN]    The canvas height(will be the heigth of L1 buffer) 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mediacache_start_db(U8 *buf, U32 length, WCHAR *path, WCHAR *db_name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path_p;
    U32 io_buf_length = 0;
    U32 str_length;
    static WCHAR filepath[SRV_FMGR_PATH_MAX_LEN+1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(length >= SRV_MEDIACACHE_SQLITE_DB_BUF_SIZE_MIN);
    g_mediacache_cntx_p->is_db_start_ok = MMI_TRUE;
    if (path == NULL)
    {
        srv_fmgr_filelist_get_filepath(g_mediacache_cntx_p->config.flist_handle, 0, filepath, sizeof(filepath));
        str_length = mmi_ucs2strlen((CHAR*)filepath);
        while (str_length > 0)
        {
            if (filepath[str_length - 1] == '\\')
            {
                break;
            }
            str_length--;
        }
        if (str_length > 0)
        {
            filepath[str_length] = 0;
        }
        path_p = filepath;
    }
    else
    {
        path_p = path;
    }
    if (g_mediacache_cntx_p->db_store_cache_group == SRV_MEDIACACHE_CACHE_TYPE_L2)
    {
        io_buf_length = g_mediacache_cntx_p->level2_buffer_size;
    }
    else if (g_mediacache_cntx_p->db_store_cache_group == SRV_MEDIACACHE_CACHE_TYPE_L1)
    {
        io_buf_length = g_mediacache_cntx_p->level1_buffer_size;
    }
    else
    {
        ASSERT(0);
    }
    if (g_mediacache_cntx_p->userdef_db_io_buffer_length != 0)
    {
        io_buf_length = g_mediacache_cntx_p->userdef_db_io_buffer_length;
    }

    // adjust length and buffer starting address
    if(g_mediacache_cntx_p->is_align_cache)
    {
        U8 *buf_temp = buf;
        // adjust io_buf_length according to cache line
        io_buf_length = ((io_buf_length + 31) / 32) * 32; /*32 bytes align*/

        // make sure starting address is aligned,
        // and adjust length left
        buf = (PS8)(((U32)(buf + 31) / 32) * 32); /*32 bytes align*/
        length -= (buf - buf_temp);
    }

    g_mediacache_cntx_p->db_handle.io_buf.max_length = io_buf_length;

    g_mediacache_cntx_p->db_handle.io_buf.i_buffer = buf;
    g_mediacache_cntx_p->db_handle.io_buf.i_length = io_buf_length;
    g_mediacache_cntx_p->db_handle.io_buf.i_state = MMI_IVD_IO_BUF_STATE_IDLE;
    buf += io_buf_length;
    ASSERT(length >= io_buf_length);
    length -= io_buf_length;

    #if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
    // Do not use o_buffer for COSMOS slim
    g_mediacache_cntx_p->db_handle.io_buf.o_buffer = NULL;
    g_mediacache_cntx_p->db_handle.io_buf.o_length = 0;
    g_mediacache_cntx_p->db_handle.io_buf.state = MMI_IVD_IO_BUF_STATE_IDLE;

    // But we need a small buffer to write DB blob
    if(IVD_DB_TEMP_BUF_LEN)
    {
        g_mediacache_cntx_p->db_handle.db_temp_buf = buf;
    }
    else
    {
        g_mediacache_cntx_p->db_handle.db_temp_buf = NULL;
    }
    buf += IVD_DB_TEMP_BUF_LEN;
    ASSERT(length >= IVD_DB_TEMP_BUF_LEN);
    length -= IVD_DB_TEMP_BUF_LEN;
    #else
    g_mediacache_cntx_p->db_handle.io_buf.o_buffer = buf;
    g_mediacache_cntx_p->db_handle.io_buf.o_length = io_buf_length;
    g_mediacache_cntx_p->db_handle.io_buf.state = MMI_IVD_IO_BUF_STATE_IDLE;
    buf += io_buf_length;
    ASSERT(length >= io_buf_length);
    length -= io_buf_length;
    #endif
    

    // config DB meta
    if (g_mediacache_cntx_p->is_using_ies && g_mediacache_cntx_p->is_meta_using_db)
    {
        g_mediacache_cntx_p->db_handle.io_buf.meta_buffer = buf;
        g_mediacache_cntx_p->db_handle.io_buf.meta_length = SRV_MEDIACACHE_META_SLICE_SIZE;
        g_mediacache_cntx_p->db_handle.io_buf.meta_state = MMI_IVD_IO_BUF_STATE_IDLE;
        buf += SRV_MEDIACACHE_META_SLICE_SIZE;
        ASSERT(length >= SRV_MEDIACACHE_META_SLICE_SIZE);
        length -= SRV_MEDIACACHE_META_SLICE_SIZE;
    }

    // config SQL buffer
    g_mediacache_cntx_p->db_handle.db_buffer.buffer = buf;
    g_mediacache_cntx_p->db_handle.db_buffer.length = length; 
    
    g_mediacache_cntx_p->db_handle.is_mark = MMI_FALSE;
#if defined(__SRV_MEDIACACHE_DEBUG_MEASURE__)
    g_mediacache_cntx_p->db_handle.is_mark = MMI_TRUE;
#endif
    ivd_ivsrv_db_start(&g_mediacache_cntx_p->db_handle, path_p, srv_mediacache_db_start_cb, db_name_p);
    
    SetProtocolEventHandler(ivd_ivsrv_db_start_rsp_hdler, MSG_ID_IVD_DB_START_RSP);
    SetProtocolEventHandler(ivd_ivsrv_db_put_img_rsp_hdler, MSG_ID_IVD_DB_PUT_IMG_RSP);
    SetProtocolEventHandler(ivd_ivsrv_db_get_img_rsp_hdler, MSG_ID_IVD_DB_GET_IMG_RSP);
    SetProtocolEventHandler(ivd_ivsrv_db_remove_img_rsp_hdler, MSG_ID_IVD_DB_REMOVE_IMG_RSP);

#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
    SetProtocolEventHandler(ivd_ivsrv_db_put_meta_rsp_hdler, MSG_ID_IVD_DB_PUT_META_RSP);
    SetProtocolEventHandler(ivd_ivsrv_db_get_meta_rsp_hdler, MSG_ID_IVD_DB_GET_META_RSP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_create
 * DESCRIPTION
 *  image viewer service create function 
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mediacache_stop_db(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*process searching one*/
    if (g_mediacache_cntx_p->searching_p != NULL)
    {
        srv_mediacache_db_cancel_get_img(&g_mediacache_cntx_p->db_handle);
        g_mediacache_cntx_p->searching_p = NULL;
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_SEARCH_CHANGE_SEARCHING_POINT_TO_NULL_AT_D, __LINE__);
    }
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_CANCEL_DECODE_CELL_AT_D, __LINE__);
    g_mediacache_cntx_p->engine.cancel_decode_cell(g_mediacache_cntx_p->image_hdl_decoding);
    g_mediacache_cntx_p->image_hdl_decoding = 0;
    g_mediacache_cntx_p->decoding_p = NULL;
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_DECODING_P_IS_NULL_D, __LINE__);
    SRV_MEDIACACHE_START_MEASURE("DB0");
    ivd_ivsrv_db_stop(&g_mediacache_cntx_p->db_handle);
    SRV_MEDIACACHE_STOP_MEASURE("DB0");
    ClearProtocolEventHandler(MSG_ID_IVD_DB_START_RSP);
    ClearProtocolEventHandler(MSG_ID_IVD_DB_PUT_IMG_RSP);
    ClearProtocolEventHandler(MSG_ID_IVD_DB_GET_IMG_RSP);
    ClearProtocolEventHandler(MSG_ID_IVD_DB_REMOVE_IMG_RSP);
#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
    ClearProtocolEventHandler(MSG_ID_IVD_DB_PUT_META_RSP);
    ClearProtocolEventHandler(MSG_ID_IVD_DB_GET_META_RSP);
#endif
    if (g_mediacache_cntx_p->state == SRV_MEDIACACHE_STATE_RUNNING)
    {
        srv_mediacache_check_and_start_decode();  
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_create
 * DESCRIPTION
 *  image viewer service create function 
 * PARAMETERS
 *  canvas_width            [IN]    The canvas width(will be the width of L1 buffer) 
 *  canvas_height           [IN]    The canvas height(will be the heigth of L1 buffer) 
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mediacache_db_put_img(srv_mediacache_cell_struct *cell, ivd_req_callback finish_callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_img_info_struct img_info;
#ifdef __SRV_MEDIACACHE_CHECK_DIMENSION__    
    FS_HANDLE fs_hdle;
#endif
    U32 file_size = 0;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* don't check io_buf.i_state here. It should be checked in IVD */
    if (g_mediacache_cntx_p->is_db_start_ok != MMI_TRUE)
    {
        return;
    }
    
    if (cell->type != g_mediacache_cntx_p->db_store_cache_group)
    {
        return;
    }
    if (SRV_MEDIACACHE_CACHE_STATE_DECODE_OK != cell->state)
    {
        return;
    }
    img_info.db_handle = &g_mediacache_cntx_p->db_handle;
    img_info.org_image_width = cell->org_image_width;
    img_info.org_image_height = cell->org_image_height;
    img_info.image_width = cell->image_width;
    img_info.image_height = cell->image_height;
    img_info.buffer = cell->buffer;
    #ifdef __MMI_MEDIA_CACHE_YUV_THUMB__
    img_info.color_format = cell->buffer_format;
    #else
    img_info.color_format = g_mediacache_cntx_p->color_format;
    #endif
    SRV_MEDIACACHE_START_MEASURE("FSG");
    ASSERT(NULL != g_mediacache_cntx_p->engine.get_file_name);
    ret = g_mediacache_cntx_p->engine.get_file_name(
        cell->file_index, 
        (U16*)g_mediacache_cntx_p->config.filename, 
        SRV_FMGR_PATH_BUFFER_SIZE,
        NULL);
    SRV_MEDIACACHE_STOP_MEASURE("FSG");
    if (ret < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_GET_NAME_FAILED,ret,__LINE__);
        return;
    }
    img_info.path = g_mediacache_cntx_p->config.filename;
    img_info.file_date = 0;
    img_info.file_time = 0;
    img_info.err_group = cell->err_group;
    img_info.err_code = cell->err_code;
    img_info.file_idx = cell->file_index;
#ifdef __SRV_MEDIACACHE_CHECK_DIMENSION__    
    SRV_MEDIACACHE_START_MEASURE("FSO");
    fs_hdle = FS_Open((WCHAR*)img_info.path, FS_READ_ONLY );
    FS_GetFileSize(fs_hdle, &file_size);
    FS_Close(fs_hdle);
    SRV_MEDIACACHE_STOP_MEASURE("FSO");
#endif
    img_info.file_size = file_size;
    img_info.file_CRC = 0;
    ASSERT(mmi_ucs2strlen(img_info.path) * 2 < IVD_FILE_MAX_PATH_LEN);
    ivd_ivsrv_db_put_img(&img_info, finish_callback, user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_create
 * DESCRIPTION
 *  image viewer service create function 
 * PARAMETERS
 *  canvas_width            [IN]    The canvas width(will be the width of L1 buffer) 
 *  canvas_height           [IN]    The canvas height(will be the heigth of L1 buffer) 
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mediacache_db_get_img_cb(S32 err, ivd_db_imageinfo_struct *image_info, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SRV_MEDIACACHE_DEBUG_MEASURE__
    U32 ticks;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_DB_GET_IMG_CB,err);

    if (NULL == g_mediacache_cntx_p)
    {
        return;
    }
    if (NULL == g_mediacache_cntx_p->searching_p)
    {
        if (g_mediacache_cntx_p->state == SRV_MEDIACACHE_STATE_RUNNING || g_mediacache_cntx_p->state == SRV_MEDIACACHE_STATE_PAUSED);
        {
            srv_mediacache_check_and_start_decode();  
        }
        return;
    }
    if (err == MMI_IVD_ERR_GET_SKIP)
    {
        // we may be already starting a new searching_p already,
        // and this is a response to previously cancelled decode.
        // so do not set searching_p to NULL here.
        if (g_mediacache_cntx_p->state == SRV_MEDIACACHE_STATE_RUNNING || g_mediacache_cntx_p->state == SRV_MEDIACACHE_STATE_PAUSED);
        {
            srv_mediacache_check_and_start_decode();  
        }
        return;
    }
#ifdef __SRV_MEDIACACHE_DEBUG_MEASURE__
    kal_get_time(&ticks);
    g_mediacache_cntx_p->searching_p->db_ticks = ticks - g_mediacache_cntx_p->searching_p->db_ticks;
#endif
    if (err >= 0 && image_info->err_code == 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_IDX_DBSTATE_CHANGE, 
            g_mediacache_cntx_p->searching_p->file_index, 
            g_mediacache_cntx_p->searching_p->state_4_db,
            SRV_MEDIACACHE_CACHE_STATE_DECODE_DB_OK,
            __LINE__);
        g_mediacache_cntx_p->searching_p->state_4_db = SRV_MEDIACACHE_CACHE_STATE_DECODE_DB_OK;
        if(g_mediacache_cntx_p->is_using_ies)
        {
            g_mediacache_cntx_p->searching_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_DB_OK;
        }
        else
        {
            g_mediacache_cntx_p->searching_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_OK;
        }
        g_mediacache_cntx_p->searching_p->err_group = SRV_MEDIACACHE_ERR_GROUP_OK;
        g_mediacache_cntx_p->searching_p->err_code = SRV_MEDIACACHE_OK;
        g_mediacache_cntx_p->searching_p->is_saved = MMI_TRUE;

        g_mediacache_cntx_p->searching_p->image_height = image_info->image_height;
        g_mediacache_cntx_p->searching_p->image_width = image_info->image_width;
        g_mediacache_cntx_p->searching_p->org_image_height = image_info->org_image_height;
        g_mediacache_cntx_p->searching_p->org_image_width= image_info->org_image_width;
        
        /*If the cell is L2 change state to Decode OK no need to decode again*/
        if (SRV_MEDIACACHE_CACHE_TYPE_L2 == g_mediacache_cntx_p->searching_p->type)
        {
            g_mediacache_cntx_p->searching_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_OK;
        }

        #if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
        // Do not use o_buffer for COSMOS slim
        if(g_mediacache_cntx_p->db_handle.io_buf.o_buffer)
        {
            memcpy(g_mediacache_cntx_p->searching_p->buffer,
                   g_mediacache_cntx_p->db_handle.io_buf.o_buffer,
                   g_mediacache_cntx_p->searching_p->image_height * g_mediacache_cntx_p->searching_p->image_width * g_mediacache_cntx_p->bytes_per_pixel);
        }
        #else
        memcpy(g_mediacache_cntx_p->searching_p->buffer,
            g_mediacache_cntx_p->db_handle.io_buf.o_buffer,
            g_mediacache_cntx_p->searching_p->image_height * g_mediacache_cntx_p->searching_p->image_width * g_mediacache_cntx_p->bytes_per_pixel);
        #endif
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_IOBUF_HERE_WE_COPY_BUF_FROM_DB_O_BUF_TO_CELL_BUFFER_D, __LINE__);

        //here is meta part
        #ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
        if (image_info->with_meta && g_mediacache_cntx_p->ies_app_session)
        {
            srv_mediacache_create_meta_handle(
                image_info->meta_ret,
                g_mediacache_cntx_p->db_handle.io_buf.meta_buffer,
                g_mediacache_cntx_p->db_handle.io_buf.meta_length,
                g_mediacache_cntx_p->searching_p);
        }
        #endif
        
        srv_mediacache_check_cb_and_call(g_mediacache_cntx_p->searching_p, g_mediacache_cntx_p->cb_file_idx, MMI_FALSE);
        if (g_mediacache_cntx_p->db_failed_query_count > 0)
        {
            g_mediacache_cntx_p->db_failed_query_count--;
        }
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_IDX_DBSTATE_CHANGE, 
            g_mediacache_cntx_p->searching_p->file_index, 
            g_mediacache_cntx_p->searching_p->state_4_db,
            SRV_MEDIACACHE_CACHE_STATE_DECODE_DB_SKIP,
            __LINE__);

        //here is meta part
        #ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
        if (image_info->with_meta && g_mediacache_cntx_p->ies_app_session)
        {
            srv_mediacache_create_meta_handle(
                image_info->meta_ret,
                g_mediacache_cntx_p->db_handle.io_buf.meta_buffer,
                g_mediacache_cntx_p->db_handle.io_buf.meta_length,
                g_mediacache_cntx_p->searching_p);
        }
        #endif

        g_mediacache_cntx_p->searching_p->state_4_db = SRV_MEDIACACHE_CACHE_STATE_DECODE_DB_SKIP;
        if (err >= 0 && image_info->err_code != 0)
        {
            g_mediacache_cntx_p->searching_p->err_code  = image_info->err_code;
            g_mediacache_cntx_p->searching_p->err_group = image_info->err_group;
            g_mediacache_cntx_p->searching_p->is_saved = MMI_TRUE;
            srv_mediacache_set_last_err(image_info->err_group, image_info->err_code);
        }
    }
    srv_mediacache_db_cancel_get_img(&g_mediacache_cntx_p->db_handle);
    g_mediacache_cntx_p->searching_p = NULL;
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_SEARCH_CHANGE_SEARCHING_POINT_TO_NULL_AT_D, __LINE__);
    if (g_mediacache_cntx_p->state == SRV_MEDIACACHE_STATE_RUNNING || g_mediacache_cntx_p->state == SRV_MEDIACACHE_STATE_PAUSED);
    {
        srv_mediacache_check_and_start_decode();  
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_create
 * DESCRIPTION
 *  image viewer service create function 
 * PARAMETERS
 *  canvas_width            [IN]    The canvas width(will be the width of L1 buffer) 
 *  canvas_height           [IN]    The canvas height(will be the heigth of L1 buffer) 
 * RETURNS
 *  MMI_TRUE start OK 
 *  MMI_FALSE start error
 *****************************************************************************/
static MMI_BOOL srv_mediacache_db_get_img(srv_mediacache_cell_struct *cell, MMI_BOOL is_blocking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_img_info_struct img_info;
    U32 buffer_size, file_size = 0;
    S32 error_code, ret;
#ifdef __SRV_MEDIACACHE_CHECK_DIMENSION__    
    FS_HANDLE fs_hdle;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_START_GET_FROM_DB,g_mediacache_cntx_p->searching_p->file_index, is_blocking);
    g_mediacache_cntx_p->searching_p = cell;
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_SEARCH_CHANGE_SEARCHING_POINT_TO_SOME_ONE_AT_D_INDEX_D, __LINE__, cell->file_index);
    
    ASSERT(g_mediacache_cntx_p->db_handle.io_buf.state != MMI_IVD_IO_BUF_STATE_GET);
    buffer_size = srv_mediacache_cache_get_img_size_by_type(cell->type);
    if (cell->type != g_mediacache_cntx_p->db_store_cache_group ||
        g_mediacache_cntx_p->is_db_start_ok != MMI_TRUE ||
        g_mediacache_cntx_p->db_handle.io_buf.state == MMI_IVD_IO_BUF_STATE_GET)
    {
        ASSERT(g_mediacache_cntx_p->state == SRV_MEDIACACHE_STATE_RUNNING || g_mediacache_cntx_p->state == SRV_MEDIACACHE_STATE_PAUSED);
        srv_mediacache_check_and_start_decode();  
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_GET_FROM_DB_RET,
            cell->type , 
            g_mediacache_cntx_p->is_db_start_ok,
            g_mediacache_cntx_p->db_handle.io_buf.state);
        return MMI_FALSE;
    }

    img_info.db_handle = &g_mediacache_cntx_p->db_handle;
    img_info.image_width = cell->image_width;
    img_info.image_height = cell->image_height;
    img_info.color_format = g_mediacache_cntx_p->color_format;
    img_info.org_image_width = cell->org_image_width;
    img_info.org_image_height = cell->org_image_height;

    if (g_mediacache_cntx_p->is_using_ies && 
        g_mediacache_cntx_p->is_using_meta && 
        g_mediacache_cntx_p->is_meta_using_db)
    {
        img_info.with_meta = MMI_TRUE;
    }
    else
    {
        img_info.with_meta = MMI_FALSE;
    }
    ASSERT(NULL != g_mediacache_cntx_p->engine.get_file_name);
    SRV_MEDIACACHE_START_MEASURE("FSG");
    ret = g_mediacache_cntx_p->engine.get_file_name(
        cell->file_index, 
        (U16*)g_mediacache_cntx_p->config.filename, 
        SRV_FMGR_PATH_BUFFER_SIZE,
        NULL);
    if (ret < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_GET_NAME_FAILED,ret,__LINE__);
        if (SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY != ret && SRV_FMGR_FILELIST_ERROR_BUSY != ret)
        {
            g_mediacache_cntx_p->searching_p->err_code = ret;
            g_mediacache_cntx_p->searching_p->err_group= SRV_MEDIACACHE_ERR_GROUP_APP;
            g_mediacache_cntx_p->searching_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
            g_mediacache_cntx_p->searching_p->is_saved = MMI_TRUE;
            srv_mediacache_check_cb_and_call(g_mediacache_cntx_p->searching_p, g_mediacache_cntx_p->cb_file_idx, MMI_TRUE);
        }
        srv_mediacache_db_cancel_get_img(&g_mediacache_cntx_p->db_handle);
        g_mediacache_cntx_p->searching_p = NULL;
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_SEARCH_CHANGE_SEARCHING_POINT_TO_NULL_AT_D, __LINE__);
        return MMI_FALSE;
    }
    SRV_MEDIACACHE_STOP_MEASURE("FSG");
    img_info.path = g_mediacache_cntx_p->config.filename;
#ifdef __SRV_MEDIACACHE_CHECK_DIMENSION__    
    SRV_MEDIACACHE_START_MEASURE("FSO");
    fs_hdle = FS_Open((WCHAR*)img_info.path, FS_READ_ONLY );
    FS_GetFileSize(fs_hdle, &file_size);
    FS_Close(fs_hdle);
    SRV_MEDIACACHE_STOP_MEASURE("FSO");
#endif
    img_info.file_date = 0;
    img_info.file_time = 0;
    img_info.file_size = file_size;
    img_info.file_CRC = 0;
    ASSERT(mmi_ucs2strlen(img_info.path) * 2 < IVD_FILE_MAX_PATH_LEN);
    if (is_blocking == MMI_TRUE)
    {
        error_code = ivd_ivsrv_db_get_img_blocking(&img_info, cell->buffer, buffer_size);
        if (0 == error_code && img_info.err_code == 0)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_IDX_DBSTATE_CHANGE, 
                cell->file_index, 
                cell->state_4_db,
                SRV_MEDIACACHE_CACHE_STATE_DECODE_DB_OK,
                __LINE__);
            cell->state_4_db = SRV_MEDIACACHE_CACHE_STATE_DECODE_DB_OK;
            cell->err_group = SRV_MEDIACACHE_ERR_GROUP_OK;
            cell->err_code = SRV_MEDIACACHE_OK_FROM_DB;
            /*no need decode again*/
            cell->err_code = SRV_MEDIACACHE_OK;
            if(g_mediacache_cntx_p->is_using_ies)
            {
                cell->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_DB_OK;
            }
            else
            {
                cell->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_OK;
            }
            cell->is_saved = MMI_TRUE;
            cell->image_width = img_info.image_width;
            cell->image_height= img_info.image_height;
            cell->org_image_width = img_info.org_image_width;
            cell->org_image_height= img_info.org_image_height;

        #ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
            if (img_info.with_meta && g_mediacache_cntx_p->ies_app_session)
            {
                srv_mediacache_create_meta_handle(
                    img_info.meta_ret,
                    img_info.db_handle->io_buf.meta_buffer,
                    img_info.db_handle->io_buf.meta_length,
                    g_mediacache_cntx_p->searching_p);
            }
        #endif
        }
        else
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_IDX_DBSTATE_CHANGE, 
                cell->file_index, 
                cell->state_4_db,
                SRV_MEDIACACHE_CACHE_STATE_DECODE_DB_SKIP,
                __LINE__);
            cell->state_4_db = SRV_MEDIACACHE_CACHE_STATE_DECODE_DB_SKIP;
            if (0 <= error_code && img_info.err_code != 0)
            {
                cell->err_group = img_info.err_group;
                cell->err_code = img_info.err_code;
                cell->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
                cell->is_saved = MMI_TRUE;
                srv_mediacache_set_last_err(cell->err_group, cell->err_code);
            }

        #ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
            if (img_info.with_meta && g_mediacache_cntx_p->ies_app_session)
            {
                srv_mediacache_create_meta_handle(
                    img_info.meta_ret,
                    img_info.db_handle->io_buf.meta_buffer,
                    img_info.db_handle->io_buf.meta_length,
                    g_mediacache_cntx_p->searching_p);
            }
        #endif
            return MMI_FALSE;
        }
    }
    else
    {
        S32 ret = 0;
        #if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
        // Do not use o_buffer for COSMOS slim,
        // so directly decode in to cell buffer
        img_info.buffer = cell->buffer;
        img_info.length4get = buffer_size;
        #endif
        ret = ivd_ivsrv_db_get_img(&img_info, srv_mediacache_db_get_img_cb);
        /* ret 0 means it succeeds to send get img request, else means it is fail to get img */
        if (ret == 0)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_db_clear_old_record
 * DESCRIPTION
 *  image viewer clear old records
 * PARAMETERS
 *  days            [IN]    How many days old that the records will be cleared
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mediacache_db_clear_old_record(U32 days)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 date;
    applib_time_struct   rtc_time;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mediacache_cntx_p->is_db_start_ok == MMI_FALSE)
    {
        return;
    }
    applib_dt_get_rtc_time(&rtc_time);
    date = rtc_time.nYear % 10;
    date = date * 100 + (rtc_time.nMonth % 100);
    date = date * 100 + (rtc_time.nDay % 100);
    date -= days;/*clear record added days before*/ 
    ivd_ivsrv_db_remove_img_before_date(&g_mediacache_cntx_p->db_handle, date, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_create
 * DESCRIPTION
 *  image viewer service create function 
 * PARAMETERS
 *  canvas_width            [IN]    The canvas width(will be the width of L1 buffer) 
 *  canvas_height           [IN]    The canvas height(will be the heigth of L1 buffer) 
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_mediacache_db_cancel_get_img(ivd_db_handle_struct *db_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ivd_ivsrv_db_cancel_get(db_handle);
    g_mediacache_cntx_p->searching_p = NULL;
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_SEARCH_CHANGE_SEARCHING_POINT_TO_NULL_AT_D, __LINE__);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_decode_schedule
 * DESCRIPTION
 *  start schedule the pre buffer process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 srv_mediacache_decode_by_database(srv_mediacache_cell_struct *new_cell, MMI_BOOL is_blocking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_pre_decode_enum    is_user_cancel = SRV_MEDIACACHE_PRE_DECODE_CONTINUE;
    S32 img_width, img_height, file_index;
    S32 ret = 0;
    WCHAR  *filename;
#ifdef __SRV_MEDIACACHE_CHECK_DIMENSION__    
    CHAR *error_str;
#endif
    GDI_RESULT  result;    
    MMI_BOOL    is_fmgr_pass;
    MMI_BOOL    is_dim_need_reset = MMI_FALSE;
    MMI_BOOL    is_start_ok = MMI_FALSE;
    srv_mediacache_rect_struct img_org, img_resized;
    S32 layer_w, layer_h;
#ifdef __SRV_MEDIACACHE_DEBUG_MEASURE__
    U32 ticks = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_DECODE_BY_DB);
    if (g_mediacache_cntx_p->searching_p == new_cell || 
        NULL == new_cell ||
        g_mediacache_cntx_p->is_db_start_ok != MMI_TRUE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_BY_DB_RETURN1,
            g_mediacache_cntx_p->searching_p == new_cell,
            new_cell,
            g_mediacache_cntx_p->is_db_start_ok == MMI_TRUE);        
        return SRV_MEDIACACHE_INTERNAL_ERR_SEARCHING_SAME_ONE;
    }
    if (g_mediacache_cntx_p->db_store_cache_group != new_cell->type)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_BY_DB_RETURN1,
            g_mediacache_cntx_p->searching_p == new_cell,
            new_cell,
            g_mediacache_cntx_p->is_db_start_ok == MMI_TRUE);
        return -1;
    }
    srv_mediacache_db_cancel_get_img(&g_mediacache_cntx_p->db_handle);
    g_mediacache_cntx_p->searching_p = new_cell;
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_SEARCH_CHANGE_SEARCHING_POINT_TO_SOME_ONE_AT_D_INDEX_D, __LINE__, new_cell->file_index);
    
#ifdef __SRV_MEDIACACHE_DEBUG_MEASURE__
    kal_get_time(&new_cell->db_ticks);
#endif
    file_index = g_mediacache_cntx_p->searching_p->file_index;
    ASSERT(NULL != g_mediacache_cntx_p->engine.get_file_name);
    result = g_mediacache_cntx_p->engine.get_file_name(
        file_index, 
        (U16*)g_mediacache_cntx_p->config.filename, 
        SRV_FMGR_PATH_BUFFER_SIZE,
        NULL);
    if (result < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_GET_NAME_FAILED,result,__LINE__);
        if (SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY != result && SRV_FMGR_FILELIST_ERROR_BUSY != result)
        {
            new_cell->err_code = result;
            new_cell->err_group= SRV_MEDIACACHE_ERR_GROUP_APP;
            new_cell->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
            new_cell->is_saved = MMI_TRUE;
            srv_mediacache_check_cb_and_call(new_cell, g_mediacache_cntx_p->cb_file_idx, MMI_TRUE);
        }
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_BY_DB_FILESIZE,result);
        return result;
    }
    filename = (WCHAR*)g_mediacache_cntx_p->config.filename;
#ifdef __SRV_MEDIACACHE_CHECK_DIMENSION__    
    is_fmgr_pass = srv_mediacache_file_limit_check(filename , &error_str);
#else
    is_fmgr_pass = MMI_TRUE;
    if (new_cell->org_image_width <= 0 || new_cell->org_image_height<= 0)
    {
        new_cell->image_width = 1;
        new_cell->image_height= 1;
        result = 0;
        if(g_mediacache_cntx_p->is_using_ies)
        {
            SRV_MEDIACACHE_START_MEASURE("GDG");
            new_cell->image_type = gdi_image_get_type_from_file(g_mediacache_cntx_p->config.filename);
            SRV_MEDIACACHE_STOP_MEASURE("GDG");
        }
        else
        {
            new_cell->image_type = GDI_IMAGE_TYPE_JPG;
        }
        new_cell->org_image_width = 1;
        new_cell->org_image_height = 1;
        is_dim_need_reset = MMI_TRUE;
    }
#endif
    if (is_fmgr_pass == MMI_FALSE)
    {
        img_width = -1;
        img_height = -1;
        result = 0;
    }
    else
    {
        if (new_cell->image_width == -1 && new_cell->image_height == -1)
        {
            SRV_MEDIACACHE_START_MEASURE("FU3");
            result = gdi_imgdec_get_dimension_file((CHAR*)filename, &img_width, &img_height);
            if (result < 0)
            {
                result = gdi_image_get_dimension_file((CHAR*)filename, &img_width, &img_height);
            }
            SRV_MEDIACACHE_STOP_MEASURE("FU3");
        }
        else
        {
            img_width = new_cell->org_image_width;
            img_height = new_cell->org_image_height;
            result = 0;
        }
    }
    if (img_width <= 0 || img_height <= 0 || result < 0 || img_width > SRV_MEDIACACHE_DECODE_MAX_W_H || img_height > SRV_MEDIACACHE_DECODE_MAX_W_H)
    {        
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_NOT_SUPPORT,img_width, img_height, result);
        g_mediacache_cntx_p->searching_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
        if (result < 0)
        {
            g_mediacache_cntx_p->searching_p->err_code = result;
            g_mediacache_cntx_p->searching_p->err_group= SRV_MEDIACACHE_ERR_GROUP_GDI;
            ret = result;
        }
        else
        {
            g_mediacache_cntx_p->searching_p->err_code = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
            g_mediacache_cntx_p->searching_p->err_group= SRV_MEDIACACHE_ERR_GROUP_MEDIACACHE;
            ret = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
        }
        srv_mediacache_check_cb_and_call(g_mediacache_cntx_p->searching_p, g_mediacache_cntx_p->cb_file_idx, MMI_TRUE);
        srv_mediacache_db_cancel_get_img(&g_mediacache_cntx_p->db_handle);
        g_mediacache_cntx_p->searching_p = NULL;
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_SEARCH_CHANGE_SEARCHING_POINT_TO_NULL_AT_D, __LINE__);
    }
    else
    {
        is_user_cancel = SRV_MEDIACACHE_PRE_DECODE_CONTINUE;
        if (g_mediacache_cntx_p->pre_decode_cb != NULL)
        {
            is_user_cancel = g_mediacache_cntx_p->pre_decode_cb(filename, NULL);
        }
        if (is_user_cancel != SRV_MEDIACACHE_PRE_DECODE_CANCEL_THIS)
        {
            if (g_mediacache_cntx_p->searching_p->image_type == GDI_IMAGE_TYPE_INVALID)
            {
                SRV_MEDIACACHE_START_MEASURE("GDG");
                g_mediacache_cntx_p->searching_p->image_type = gdi_image_get_type_from_file((CHAR*)filename);
                SRV_MEDIACACHE_STOP_MEASURE("GDG");
            }
            srv_mediacache_cache_fill_cell_by_img(img_width, img_height, g_mediacache_cntx_p->searching_p);
            if (g_mediacache_cntx_p->searching_p->image_width <= 0 || g_mediacache_cntx_p->searching_p->image_height <= 0)
            {        
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_CALC_W_H_ERR,
                    g_mediacache_cntx_p->searching_p->image_width, g_mediacache_cntx_p->searching_p->image_height);
                g_mediacache_cntx_p->searching_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
                g_mediacache_cntx_p->searching_p->err_code = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
                g_mediacache_cntx_p->searching_p->err_group= SRV_MEDIACACHE_ERR_GROUP_MEDIACACHE;
                srv_mediacache_check_cb_and_call(g_mediacache_cntx_p->searching_p, g_mediacache_cntx_p->cb_file_idx, MMI_TRUE);
                srv_mediacache_db_cancel_get_img(&g_mediacache_cntx_p->db_handle);
                g_mediacache_cntx_p->searching_p = NULL;
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_SEARCH_CHANGE_SEARCHING_POINT_TO_NULL_AT_D, __LINE__);
                ret = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
            }
            else
            {
                img_org.x = 0;
                img_org.y = 0;
                img_org.width = g_mediacache_cntx_p->searching_p->org_image_width;
                img_org.height = g_mediacache_cntx_p->searching_p->org_image_height;
                img_resized.x = 0;
                img_resized.y = 0;
                img_resized.width = g_mediacache_cntx_p->searching_p->image_width;
                img_resized.height = g_mediacache_cntx_p->searching_p->image_height;
                if (g_mediacache_engine_cntx.is_to_buffer == MMI_TRUE &&
                    g_mediacache_cntx_p->searching_p != g_mediacache_cntx_p->large_p)
                {
                    g_mediacache_cntx_p->searching_p->image_width = g_mediacache_engine_cntx.width;
                    g_mediacache_cntx_p->searching_p->image_height = g_mediacache_engine_cntx.height;
                }
                layer_w = g_mediacache_cntx_p->searching_p->image_width;
                layer_h = g_mediacache_cntx_p->searching_p->image_height;
                g_mediacache_cntx_p->engine.set_clip((U32*)g_mediacache_cntx_p,&layer_w,&layer_h,&img_org,&img_resized,g_mediacache_cntx_p->engine.user_data);
                g_mediacache_cntx_p->searching_p->image_width = layer_w;
                g_mediacache_cntx_p->searching_p->image_height = layer_h;

                is_start_ok = srv_mediacache_db_get_img(g_mediacache_cntx_p->searching_p, is_blocking);
#ifdef __SRV_MEDIACACHE_DEBUG_MEASURE__
                if (MMI_TRUE == is_blocking)
                {
                    kal_get_time(&ticks);
                    new_cell->db_ticks = ticks - new_cell->db_ticks;
                    kal_print_string_trace(MOD_MMI_MEDIA_APP, MMI_MEDIA_TRC_G2_APP, "[srvmc]decode time cost db [%d]=%d", new_cell->file_index, new_cell->db_ticks);
                }
#endif
                if (is_start_ok == MMI_FALSE)
                {
                    ret = SRV_MEDIACACHE_ERR_DECODING;
                }
            }
        }
        else
        {
            g_mediacache_cntx_p->searching_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
            g_mediacache_cntx_p->searching_p->err_code = SRV_MEDIACACHE_ERR_USER_CANCEL_DECODE;
            g_mediacache_cntx_p->searching_p->err_group= SRV_MEDIACACHE_ERR_GROUP_MEDIACACHE;
            srv_mediacache_check_cb_and_call(g_mediacache_cntx_p->searching_p, g_mediacache_cntx_p->cb_file_idx, MMI_TRUE);
            srv_mediacache_db_cancel_get_img(&g_mediacache_cntx_p->db_handle);
            g_mediacache_cntx_p->searching_p = NULL;
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_SEARCH_CHANGE_SEARCHING_POINT_TO_NULL_AT_D, __LINE__);
            
            ret = SRV_MEDIACACHE_ERR_USER_CANCEL_DECODE;
        }
    }
#ifndef __SRV_MEDIACACHE_CHECK_DIMENSION__
    if ((MMI_FALSE == is_start_ok || MMI_FALSE == is_blocking) &&
        MMI_TRUE == is_dim_need_reset)
    {
        new_cell->image_width = -1;
        new_cell->image_height= -1;
        new_cell->image_type = GDI_IMAGE_TYPE_INVALID;
        new_cell->org_image_width = -1;
        new_cell->org_image_height = -1;
    }
#endif
    return ret;
}
   
    
    
/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_decode_level2_default_method
 * DESCRIPTION
 *  find unfinished cell of previous or next at group 2
 * PARAMETERS
 *  void
 * RETURNS
 *  NULL or the pointer to the unfinished cell
 *****************************************************************************/
static MMI_BOOL srv_mediacache_cache_db_cell_is_unfinished(srv_mediacache_cell_struct* curr_p, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_cell_finished = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == curr_p)
    {
        return MMI_FALSE;
    }
    if (SRV_MEDIACACHE_CACHE_STATE_DECODE_DB_NEED_CHECK == curr_p->state_4_db &&
        SRV_MEDIACACHE_CACHE_STATE_EMPTY == curr_p->state)
    {
        is_cell_finished = MMI_TRUE;
    }
    return is_cell_finished;
}
#endif

    
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_decode_level2_default_method
 * DESCRIPTION
 *  find unfinished cell of previous or next at group 2
 * PARAMETERS
 *  void
 * RETURNS
 *  NULL or the pointer to the unfinished cell
 *****************************************************************************/
static MMI_BOOL srv_mediacache_cache_cell_is_not_saved(srv_mediacache_cell_struct* curr_p, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_cell_finished = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == curr_p)
    {
        return MMI_FALSE;
    }
    if (curr_p->err_group == SRV_MEDIACACHE_ERR_GROUP_APP)
    {
        curr_p->is_saved = MMI_TRUE;
    }
    if (GDI_IMAGE_ERR_DECODE_TIME_OUT == curr_p->err_code)
    {
        curr_p->is_saved = MMI_TRUE;
    }
    if (MMI_FALSE == curr_p->is_saved && (SRV_MEDIACACHE_CACHE_STATE_DECODE_OK == curr_p->state))
    {
        is_cell_finished = MMI_TRUE;
    }
    return is_cell_finished;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cache_reset_cell
 * DESCRIPTION
 *  reset a cache cell.
 * PARAMETERS
 *  *cell           [OUT]   the pointer to the cell 
 *  include_buffer  [IN]    if include the buffer pointer slot
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mediacache_cache_reset_cell(srv_mediacache_cell_struct *cell, MMI_BOOL include_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cell == NULL)
    {
        return;
    }
    if (g_mediacache_cntx_p->decoding_p == cell)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_CANCEL_DECODE_CELL_AT_D, __LINE__);
        g_mediacache_cntx_p->engine.cancel_decode_cell(g_mediacache_cntx_p->image_hdl_decoding);
        g_mediacache_cntx_p->image_hdl_decoding = 0;
        g_mediacache_cntx_p->decoding_p = NULL;
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_DECODING_P_IS_NULL_D, __LINE__);
        srv_mediacache_check_and_start_decode();  
    }
    if (g_mediacache_cntx_p->searching_p == cell)
    {
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
        srv_mediacache_db_cancel_get_img(&g_mediacache_cntx_p->db_handle);
#endif
        g_mediacache_cntx_p->searching_p = NULL;
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_SEARCH_CHANGE_SEARCHING_POINT_TO_NULL_AT_D, __LINE__);
        srv_mediacache_check_and_start_decode();  
    }
    if (include_buffer == MMI_TRUE)
    {
        cell->buffer = NULL;
        cell->type = SRV_MEDIACACHE_CACHE_TYPE_UNUSED;
    }
    else
    {
        ASSERT(cell->is_lock == MMI_FALSE);
    }
//add by scalado vincent
#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__

    srv_mediacache_free_meta_handle_if_needed((srv_handle)g_mediacache_cntx_p, cell);
       
    if(cell->ies_preview_handle)
    {
        srv_ies_preview_destroy(cell->ies_preview_handle);
        cell->ies_preview_handle = NULL;
        cell->ies_preview_gdi_layer = NULL;
    }

    if(cell->ies_image_handle)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MEDIA_CACHE_RELEASE_IMAGE_X_BY_CELL_X, cell->ies_image_handle, cell);
        srv_ies_image_destroy(cell->ies_image_handle);
        cell->ies_image_handle = NULL;
    }

    cell->ies_image_handle = 0;
    cell->ies_preview_handle = 0;
    cell->ies_preview_gdi_layer = 0;
    cell->ies_meta_job_handle = 0;
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_META_SET_META_JOB_HANDLE_TO_NULL_FILE_INDEX_D_D, cell->file_index, __LINE__);
    
    cell->ies_meta_handle = 0;
    cell->is_ies_meta_saved = MMI_FALSE;
    cell->ies_meta_state = SRV_MEDIACACHE_META_STATE_IDLE;
    
#endif
    cell->err_code = SRV_MEDIACACHE_OK;
    cell->err_group = SRV_MEDIACACHE_ERR_GROUP_OK;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_IDX_DBSTATE_CHANGE, cell->file_index, cell->state_4_db,SRV_MEDIACACHE_CACHE_STATE_DECODE_DB_NEED_CHECK,__LINE__);
    cell->state_4_db = SRV_MEDIACACHE_CACHE_STATE_DECODE_DB_NEED_CHECK;
    cell->file_index = SRV_MEDIACACHE_DUMMY_FILE_IDX;
    cell->org_image_width= -1;
    cell->org_image_height= -1;
    cell->image_width= -1;
    cell->image_height = -1;
    cell->state = SRV_MEDIACACHE_CACHE_STATE_EMPTY;
    cell->is_lock = MMI_FALSE;
    cell->is_saved = MMI_FALSE;
    cell->image_type = GDI_IMAGE_TYPE_INVALID;
#ifdef __MMI_MEDIA_CACHE_YUV_THUMB__
    cell->buffer_format = g_mediacache_cntx_p->color_format;
#endif
#ifdef __SRV_MEDIACACHE_DEBUG_MEASURE__
    cell->decode_ticks = 0;
    cell->db_ticks = 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_remove_cache
 * DESCRIPTION
 *  remove a cache from IVSRV
 * PARAMETERS
 *  *buffer   [IN]  buffer pointer
 * RETURNS
 *  error code
 *****************************************************************************/
static void srv_mediacache_cache_fill_index_to_link(srv_mediacache_cell_struct *curr_p, S32 curr_index, S32 file_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *temp_cell_p = curr_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == curr_p)
    {
        return;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_RESET_CELL_LINE, __LINE__);
    srv_mediacache_cache_reset_cell(curr_p, MMI_FALSE);
    curr_p->file_index = curr_index;
    temp_cell_p = curr_p;
    while (NULL != temp_cell_p->next)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_RESET_CELL_LINE, __LINE__);
        srv_mediacache_cache_reset_cell(temp_cell_p->next, MMI_FALSE);
        if (temp_cell_p->file_index + 1 < file_count)
        {
            temp_cell_p->next->file_index = temp_cell_p->file_index + 1;
        }
        else
        {
            temp_cell_p->next->file_index = 0;
        }
        temp_cell_p = temp_cell_p->next;
    }
    temp_cell_p = curr_p;
    while (NULL != temp_cell_p->prev)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_RESET_CELL_LINE, __LINE__);
        srv_mediacache_cache_reset_cell(temp_cell_p->prev, MMI_FALSE);
        if (temp_cell_p->file_index > 0)
        {
            temp_cell_p->prev->file_index = temp_cell_p->file_index - 1;
        }
        else
        {
            temp_cell_p->prev->file_index = file_count - 1;
        }
        temp_cell_p = temp_cell_p->prev;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cache_get_img_size_by_type
 * DESCRIPTION
 *  get image size type by cache type
 * PARAMETERS
 *  cahce_type  [IN]    cache type
 * RETURNS
 *  image size type
 *****************************************************************************/
U32 srv_mediacache_cache_get_img_size_by_type(U8 cahce_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 cache_img_size = SRV_MEDIACACHE_CACHE_TYPE_UNUSED;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(cahce_type)
    {
    case SRV_MEDIACACHE_CACHE_TYPE_UNUSED:
        cache_img_size = SRV_MEDIACACHE_CACHE_TYPE_UNUSED;
        break;
    case SRV_MEDIACACHE_CACHE_TYPE_LARGE:
        cache_img_size = g_mediacache_cntx_p->large_buffer_size;
        break;
    case SRV_MEDIACACHE_CACHE_TYPE_L1:
        cache_img_size = g_mediacache_cntx_p->level1_buffer_size;
        break;
    case SRV_MEDIACACHE_CACHE_TYPE_L2:
        cache_img_size = g_mediacache_cntx_p->level2_buffer_size;
        break;
    default:
        ASSERT(0);
    }
    return cache_img_size;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cache_fill_cell_by_img_and_canves
 * DESCRIPTION
 *  the the data to cell by image size canves
 * PARAMETERS
 *
 *  length          [IN]        buffer length
 *  canvas_width    [IN]        canvas width
 *  canvas_height   [IN]       canvas height
 *  img_width       [IN]        image width
 *  img_height      [IN]        image height
 *  *cache_cell     [OUT]    cell
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mediacache_cache_fill_cell_by_img_and_canves(U32 length, U32 canvas_width, U32 canvas_height, S32 img_width, S32 img_height,srv_mediacache_cell_struct *cache_cell)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 resized_img_width = 0, resized_img_height = 0;
    U32 img_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(cache_cell != NULL);
    if(img_width <= 0 || img_height <= 0)
    {

        cache_cell->image_width = -1;
        cache_cell->image_height = -1;
        cache_cell->org_image_width     = img_width;
        cache_cell->org_image_height    = img_height;
        return;
    }
    img_length = img_width * img_height * g_mediacache_cntx_p->bytes_per_pixel;
    resized_img_width = img_width;
    resized_img_height = img_height;
    if (img_length > length)
    {
        if (img_width >= canvas_width)
        {
            resized_img_width = canvas_width;
            resized_img_height = (img_height * canvas_width) / img_width;
        }
        if (img_height >= canvas_height &&
            (U32)(resized_img_width * resized_img_height) * g_mediacache_cntx_p->bytes_per_pixel > length)
        {
            resized_img_height = canvas_height;
            resized_img_width = (img_width * canvas_height) / img_height;
        }
    }
    if (resized_img_width == 0 && resized_img_height != 0)
    {
        resized_img_width = 1;
    }
    if (resized_img_width != 0 && resized_img_height == 0)
    {
        resized_img_height = 1;
    }
    ASSERT((resized_img_width * resized_img_height) * g_mediacache_cntx_p->bytes_per_pixel <= length);
    ASSERT(resized_img_width > 0 && resized_img_height > 0);
    cache_cell->org_image_width     = img_width;
    cache_cell->org_image_height    = img_height;
    cache_cell->image_width         = resized_img_width;
    cache_cell->image_height        = resized_img_height;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_CALC_RESULT, img_width, img_height, resized_img_width, resized_img_height);
}


void srv_mediacache_cache_calc_fit_lcd(S32 img_width, S32 img_height, S32 *out_w, S32 *out_h)
{
    S32 x=0, y=0, w=0, h=0;
    
    gdi_image_util_fit_bbox(LCD_WIDTH,LCD_HEIGHT,img_width,img_height,&x,&y,out_w,out_h);
    gdi_image_util_fit_bbox(LCD_HEIGHT,LCD_WIDTH,img_width,img_height,&x,&y,&w,&h);
    if (w * h > (*out_w)*(*out_h))
    {
        *out_w = w;
        *out_h = h;
    }
}

void srv_mediacache_cache_calc_fit_lcd2(S32 img_width, S32 img_height, S32 *out_w, S32 *out_h)
{
#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
    S32 x=0, y=0, w=0, h=0;
    srv_ies_util_fit_bbox(LCD_WIDTH,LCD_HEIGHT,img_width,img_height,&x,&y,out_w,out_h);
    srv_ies_util_fit_bbox(LCD_HEIGHT,LCD_WIDTH,img_width,img_height,&x,&y,&w,&h);
    if (w * h > (*out_w)*(*out_h))
    {
        *out_w = w;
        *out_h = h;
    }
#endif    
}

/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cache_fill_cell_by_img_and_length
 * DESCRIPTION
 *  the the data to cell by image size and cell type
 * PARAMETERS
 *  lengh       [IN]        buffer length
 *  img_width   [IN]        image width
 *  img_height  [IN]        image height
 *  *cache_cell [OUT]       cell
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mediacache_cache_fill_cell_by_img_and_length(U32 length, S32 img_width, S32 img_height,srv_mediacache_cell_struct *cache_cell)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 resized_img_width = 0, resized_img_height = 0;
    U64 img_length;
    double  r_width_x_height;
    U64  width_x_height;
    U64 scale = 0;
    S32 lcd_fit_w=0, lcd_fit_h=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(cache_cell != NULL);
    if(img_width <= 0 || img_height <= 0 || cache_cell->image_type == GDI_IMAGE_TYPE_INVALID)
    {

        cache_cell->image_width = -1;
        cache_cell->image_height = -1;
        cache_cell->org_image_width     = img_width;
        cache_cell->org_image_height    = img_height;
        return;
    }
    img_length = img_width * img_height * g_mediacache_cntx_p->bytes_per_pixel;
    width_x_height = img_width * img_height;
    scale = SRV_MEDIACACHE_DECODE_SCALE;
    resized_img_width = img_width;
    resized_img_height = img_height;
    if (img_length > length)
    {
        r_width_x_height = length / g_mediacache_cntx_p->bytes_per_pixel;
        scale = (int)(sqrt(r_width_x_height / width_x_height) * SRV_MEDIACACHE_DECODE_SCALE);
        resized_img_width = img_width * scale / SRV_MEDIACACHE_DECODE_SCALE;
        resized_img_height = img_height * scale / SRV_MEDIACACHE_DECODE_SCALE;
    }
    /*Check GDI Limitation*/
    if (resized_img_width > SRV_MEDIACACHE_GDI_WIDTH_LIMITATION)
    {
        resized_img_width = SRV_MEDIACACHE_GDI_WIDTH_LIMITATION;
        resized_img_height= img_height * SRV_MEDIACACHE_GDI_WIDTH_LIMITATION / img_width;
    }
    if (resized_img_width == 0 && resized_img_height != 0)
    {
        resized_img_width = 1;
        resized_img_height = (length / g_mediacache_cntx_p->bytes_per_pixel) - 1;
        if (resized_img_height > img_height)
        {
            resized_img_height = img_height;
        }
        /*Check GDI layer structure Limitation Width Height to U16*/
        if (resized_img_height > 0xFFFF)
        {
            resized_img_height = 0xFFFF;
        }
    }
    if (resized_img_width != 0 && resized_img_height == 0)
    {
        resized_img_height = 1;
        resized_img_width = (length / g_mediacache_cntx_p->bytes_per_pixel) - 1;
        if (resized_img_width > img_width)
        {
            resized_img_width = img_width;
        }
        /*Check GDI layer structure Limitation Width Height to U16*/
        if (resized_img_width > 0xFFFF)
        {
            resized_img_width = 0xFFFF;
        }
    }
    if (cache_cell->image_type == GDI_IMAGE_TYPE_GIF_FILE_OFFSET ||
        cache_cell->image_type == GDI_IMAGE_TYPE_GIF ||
        cache_cell->image_type == GDI_IMAGE_TYPE_GIF_FILE ||
        cache_cell->image_type == GDI_IMAGE_TYPE_BMP ||
        cache_cell->image_type == GDI_IMAGE_TYPE_BMP_SEQUENCE ||
        cache_cell->image_type == GDI_IMAGE_TYPE_BMP_FILE ||
        cache_cell->image_type == GDI_IMAGE_TYPE_WBMP_FILE ||
        cache_cell->image_type == GDI_IMAGE_TYPE_WBMP)
    {
        if (resized_img_width > GDI_MAX_RESIZE_WIDTH)
        {
            resized_img_width = GDI_MAX_RESIZE_WIDTH;
            resized_img_height= img_height * GDI_MAX_RESIZE_WIDTH / img_width;
            if (resized_img_height == 0)
            {
                resized_img_height = 1;
            }
        }
    }
    if (SRV_MEDIACACHE_CACHE_TYPE_L1 == cache_cell->type)
    {
        if (g_mediacache_cntx_p->is_using_ies)
        {
            if (cache_cell->image_type == GDI_IMAGE_TYPE_JPG_FILE)
            {
                srv_mediacache_cache_calc_fit_lcd2(img_width,img_height,&lcd_fit_w,&lcd_fit_h);
            }
            else
            {
                srv_mediacache_cache_calc_fit_lcd(img_width,img_height,&lcd_fit_w,&lcd_fit_h);
            }
        }
        else
        {
            srv_mediacache_cache_calc_fit_lcd(img_width,img_height,&lcd_fit_w,&lcd_fit_h);
        }

        if (resized_img_width * resized_img_height > lcd_fit_w * lcd_fit_h)
        {
            resized_img_width = lcd_fit_w;
            resized_img_height = lcd_fit_h;
        }
    }

    // check for possible overflow cases, make sure it'll be at least 2.
    if(resized_img_width <= 0)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_SRV_MEDIACACHE_CACHE_FILL_CELL_BY_IMG_AND_LENGTH_OVERFLOW);
        resized_img_width = 2;
    }
    if(resized_img_height <= 0)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_SRV_MEDIACACHE_CACHE_FILL_CELL_BY_IMG_AND_LENGTH_OVERFLOW);
        resized_img_height = 2;
    }
    ASSERT((resized_img_width * resized_img_height) * g_mediacache_cntx_p->bytes_per_pixel <= length);
    cache_cell->org_image_width     = img_width;
    cache_cell->org_image_height    = img_height;
    cache_cell->image_width         = resized_img_width;
    cache_cell->image_height        = resized_img_height;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_CALC_RESULT, img_width, img_height, resized_img_width, resized_img_height, cache_cell->file_index);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cache_fill_cell_by_img
 * DESCRIPTION
 *  the the data to cell by image size and cell type
 * PARAMETERS
 *  img_width   [IN]        image width
 *  img_height  [IN]        image height
 *  *cache_cell [IN/OUT]    cell
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mediacache_cache_fill_cell_by_img(S32 img_width, S32 img_height,srv_mediacache_cell_struct *cache_cell)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 cache_img_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_CALC_ENTER, img_width, img_height);
    ASSERT(g_mediacache_cntx_p->bytes_per_pixel > 0);
    ASSERT(cache_cell != NULL);
    if(img_width <= 0 || img_height <= 0)
    {

        cache_cell->image_width = -1;
        cache_cell->image_height = -1;
        cache_cell->org_image_width     = img_width;
        cache_cell->org_image_height    = img_height;
        return;
    }
    cache_img_size = srv_mediacache_cache_get_img_size_by_type(cache_cell->type);
    srv_mediacache_cache_fill_cell_by_img_and_length(cache_img_size, img_width, img_height, cache_cell);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cache_cell_can_draw
 * DESCRIPTION
 *  check if the cell have right data to draw
 * PARAMETERS
 *  *cell   [IN]    the cell handle
 * RETURNS
 *  MMI_TRUE    can draw the data of cell to layer
 *  MMI_FALSE   can't draw the data to layer
 *****************************************************************************/
MMI_BOOL srv_mediacache_cache_cell_can_draw(srv_mediacache_cell_struct *cell)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == cell)
    {
        return MMI_FALSE;
    }
    if ((cell->state == SRV_MEDIACACHE_CACHE_STATE_DECODE_OK ||
        cell->state == SRV_MEDIACACHE_CACHE_STATE_RESIZE_FROM_L1 ||
        cell->state_4_db == SRV_MEDIACACHE_CACHE_STATE_DECODE_DB_OK ||
        cell->state == SRV_MEDIACACHE_CACHE_STATE_RESIZE_FROM_L2) &&
        cell->image_width > 0 && cell->image_height > 0)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cache_cell_finished
 * DESCRIPTION
 *  check if the cell buffer operation finished
 * PARAMETERS
 *  *cell   [IN] the cell handle
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_mediacache_cache_cell_finished(srv_mediacache_cell_struct *cell)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == cell)
    {
        return MMI_TRUE;
    }
    if (cell->state == SRV_MEDIACACHE_CACHE_STATE_DECODE_OK ||
        cell->state == SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR ||
        //cell->state_4_db == SRV_MEDIACACHE_CACHE_STATE_DECODE_DB_OK ||
        cell->file_index < 0)
    {
        return MMI_TRUE;
    }
    if (cell->state == SRV_MEDIACACHE_CACHE_STATE_RESIZE_FROM_L1 ||
        cell->state == SRV_MEDIACACHE_CACHE_STATE_RESIZE_FROM_L2 ||
        (cell->state == SRV_MEDIACACHE_CACHE_STATE_EMPTY))
    {
        return MMI_FALSE;
    }

    if (g_mediacache_cntx_p->is_using_ies)
    {
        if (cell->state == SRV_MEDIACACHE_CACHE_STATE_DECODE_DB_OK)
        {
            return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}


static MMI_BOOL srv_mediacache_cache_cell_finished2(srv_mediacache_cell_struct *cell)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == cell)
    {
        return MMI_FALSE;
    }
    if (cell->state == SRV_MEDIACACHE_CACHE_STATE_DECODE_OK ||
        cell->state == SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR ||
        //cell->state_4_db == SRV_MEDIACACHE_CACHE_STATE_DECODE_DB_OK ||
        cell->file_index < 0)
    {
        return MMI_TRUE;
    }
    if (cell->state == SRV_MEDIACACHE_CACHE_STATE_RESIZE_FROM_L1 ||
        cell->state == SRV_MEDIACACHE_CACHE_STATE_RESIZE_FROM_L2 ||
        (cell->state == SRV_MEDIACACHE_CACHE_STATE_EMPTY && cell->file_index >= 0))
    {
        return MMI_FALSE;
    }

    if (g_mediacache_cntx_p->is_using_ies)
    {
        if (cell->state == SRV_MEDIACACHE_CACHE_STATE_DECODE_DB_OK)
        {
            return MMI_TRUE;
        }
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cache_cell_finished
 * DESCRIPTION
 *  check if the cell buffer operation finished
 * PARAMETERS
 *  *cell   [IN] the cell handle
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_mediacache_cache_cell_is_unfinished(srv_mediacache_cell_struct *cell, void *user_dara)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_TRUE == srv_mediacache_cache_cell_finished(cell) ? MMI_FALSE : MMI_TRUE);
}


static MMI_BOOL srv_mediacache_cache_cell_is_unfinished2(srv_mediacache_cell_struct *cell, void *user_dara)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
    if (_srv_mediacache_decode_need_ies_check(cell))
    {
        return (MMI_TRUE == srv_mediacache_cache_cell_finished(cell) ? MMI_FALSE : MMI_TRUE);
    }
    else
    {
        return (MMI_TRUE == srv_mediacache_cache_cell_finished2(cell) ? MMI_FALSE : MMI_TRUE);
    }
#else /*__MMI_SRV_MEDIA_CACHE_USE_SRV_IES__*/
    return (MMI_TRUE == srv_mediacache_cache_cell_finished(cell) ? MMI_FALSE : MMI_TRUE);
#endif /*__MMI_SRV_MEDIA_CACHE_USE_SRV_IES__*/
}

/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cache_fit_type_cpy_buf_only
 * DESCRIPTION
 *  copy and resize the buffer data to another buffer
 * PARAMETERS
 *  dst   [IN/OUT]  cell that data will cpy to
 *  src   [IN]      cell that provide the data
 * RETURNS
 *  error code
 *****************************************************************************/
static S32 srv_mediacache_cache_fit_type_cpy_buf_only(srv_mediacache_cell_struct *dst,srv_mediacache_cell_struct *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle src_layer;
    gdi_handle dst_layer;
    U32 dst_buf_length = 0, src_buf_length = 0;
    S32 ret_code = SRV_MEDIACACHE_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((srv_mediacache_cache_cell_finished(src) == MMI_FALSE) ||
        src->image_width    <= 0 || 
        src->image_height   <  0 || 
        dst->image_width    <  0 || 
        dst->image_height   <  0)
    {
        return SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
    }
    /*DST and SRC all L1 or L2 buffer*/
    src_buf_length = srv_mediacache_cache_get_img_size_by_type(src->type);
    dst_buf_length = srv_mediacache_cache_get_img_size_by_type(dst->type);
    if (src->type == dst->type)
    {
        memcpy((U8*)dst->buffer, (U8*)src->buffer, dst_buf_length);
    }
    /*DST and SRC in different image size*/
    else
    {
        gdi_layer_create_cf_using_outside_memory(
            g_mediacache_cntx_p->color_format,
            0,
            0,
            src->image_width,
            src->image_height,
            &src_layer,
            src->buffer,
            src_buf_length);
        gdi_layer_create_cf_using_outside_memory(
            g_mediacache_cntx_p->color_format,
            0,
            0,
            dst->image_width,
            dst->image_height,
            &dst_layer,
            dst->buffer,
            dst_buf_length);
        gdi_layer_push_and_set_active(dst_layer);
        gdi_layer_set_source_key_nb_concurrent(src_layer, MMI_TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_set_source_key_nb_concurrent(dst_layer, MMI_TRUE, GDI_COLOR_TRANSPARENT);
        ret_code = gdi_bitblt_resized_with_resizer(
            src_layer,
            0,
            0,
            src->image_width - 1,
            src->image_height - 1,
            0,
            0,
            dst->image_width - 1,
            dst->image_height - 1,
            GDI_RESIZER_SW_QUALITY_HIGH);
        gdi_layer_pop_and_restore_active();
        gdi_layer_free(src_layer);
        gdi_layer_free(dst_layer);
        dst->org_image_width    = src->org_image_width;
        dst->org_image_height   = src->org_image_height;
    }
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cache_cpy_cb_and_buffer
 * DESCRIPTION
 *  cpy control block and buffer to another
 * PARAMETERS
 *  dst   [IN/OUT]  the cell will copy to
 *  src   [IN]      the cell provide data
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mediacache_cache_cpy_cb_and_buffer(srv_mediacache_cell_struct *dst,srv_mediacache_cell_struct *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dst->image_type = GDI_IMAGE_TYPE_BMP_MEM;
    srv_mediacache_cache_fill_cell_by_img(src->org_image_width, src->org_image_height, dst);
    srv_mediacache_cache_fit_type_cpy_buf_only(dst,src);
    dst->file_index         = src->file_index;
    dst->org_image_width    = src->org_image_width;
    dst->org_image_height   = src->org_image_height;
    dst->err_code           = src->err_code;
    dst->err_group          = src->err_group;
    dst->state              = src->state;
    dst->state_4_db         = src->state_4_db;
}


#if defined(__MTK_INTERNAL_TTTTTTTTTT__)
/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cache_print_dbgtrace
 * DESCRIPTION
 *  print SRV cache state, for debug
 * PARAMETERS
 *  *cache   [IN]   pointer of cache
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mediacache_cache_print_dbgtrace_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *cell_p;
    srv_mediacache_cell_struct *cache_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mediacache_cntx_p)
    {
        return;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_DBG_HEAD,
        g_mediacache_cntx_p->mode_cntx.filelist.num_level1_used,
        g_mediacache_cntx_p->mode_cntx.filelist.has_large, 
        0, 
        g_mediacache_cntx_p->mode_cntx.filelist.num_level1_next, 
        g_mediacache_cntx_p->mode_cntx.filelist.num_level1_prev,
        g_mediacache_cntx_p->mode_cntx.filelist.num_level2_next,
        g_mediacache_cntx_p->mode_cntx.filelist.num_level2_prev,
        0);
    cell_p = g_mediacache_cntx_p->large_p;
    if (cell_p != NULL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_DBG_LARGE_INFO,
            cell_p->buffer,
            cell_p->err_code,
            cell_p->err_group,
            cell_p->file_index,
            cell_p->image_width,
            cell_p->image_height,
            cell_p->org_image_width,
            cell_p->org_image_height,
            cell_p->state,
            cell_p->type);
    }
    cache_p = g_mediacache_cntx_p->level1_first_p;
    if (cache_p == NULL)
    {
        return;
    }
    while (cache_p != NULL)
    {
        cell_p = cache_p;
        if (cell_p == g_mediacache_cntx_p->level1_curr_p)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_SRV_MEDIACACHE_DBG_ITEM_CURR, 1);
        }
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_SRV_MEDIACACHE_DBG_ITEM_INFO,
            1,
            cell_p->buffer,
            cell_p->err_code,
            cell_p->err_group,
            cell_p->file_index,
            cell_p->image_width,
            cell_p->image_height,
            cell_p->org_image_width,
            cell_p->org_image_height,
            cell_p->state,
            cell_p->type);
        cache_p = cache_p->next;
    }
    
    cache_p = g_mediacache_cntx_p->level2_first_p;
    if (cache_p == NULL)
    {
        return;
    }
    while (cache_p != NULL)
    {
        cell_p = cache_p;
        if (cell_p == g_mediacache_cntx_p->level2_curr_p)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_SRV_MEDIACACHE_DBG_ITEM_CURR, 2);
        }
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_SRV_MEDIACACHE_DBG_ITEM_INFO,
            2,
            cell_p->buffer,
            cell_p->err_code,
            cell_p->err_group,
            cell_p->file_index,
            cell_p->image_width,
            cell_p->image_height,
            cell_p->org_image_width,
            cell_p->org_image_height,
            cell_p->state,
            cell_p->type);
        cache_p = cache_p->next;
    }
    if (g_mediacache_cntx_p->level1_curr_p != NULL && g_mediacache_cntx_p->level2_curr_p != NULL)
    {
        if (g_mediacache_cntx_p->level1_curr_p->file_index >= 0 &&
            g_mediacache_cntx_p->level2_curr_p->file_index >= 0)
        {
            ASSERT(g_mediacache_cntx_p->level1_curr_p->file_index == g_mediacache_cntx_p->level2_curr_p->file_index);
        }
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cache_resize2layer
 * DESCRIPTION
 *  resize the cache to layer by group and index
 * PARAMETERS
 *  dest_layer  [IN]    dest layer to draw to
 *  dest_x      [IN]    offset of x according to dest
 *  dest_y      [IN]    offest of y according to dest
 *  zoomfactor  [IN]    zoom factor * 1000
 *  x           [IN]    x after zoom of org image
 *  y           [IN]    y after zoom of org image
 *  width       [IN]    width after zoom of org image
 *  height      [IN]    height after zoom of org image
 *  group       [IN]    gourp index
 *  index       [IN]    index
 * RETURNS
 *  error code        
 *****************************************************************************/
static S32 srv_mediacache_cache_resize2layer(srv_mediacache_cell_struct *cell_p, srv_mediacache_img_to_layer_struct *area)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret_code = SRV_MEDIACACHE_OK;
    U32 src_buf_length;
    gdi_handle src_layer;
    srv_mediacache_rect_struct src;
#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
    srv_ies_result ies_ret_code = SRV_IES_OK;
    MMI_BOOL is_give_up_ies_render = MMI_FALSE;
#endif
    
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_RESIZE2LAYER_INTERNAL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(cell_p != NULL);
    ASSERT(srv_mediacache_cache_cell_can_draw(cell_p) == MMI_TRUE);
    ASSERT(cell_p->image_width > 0 && cell_p->image_height > 0);
    ASSERT(area->src.x >= 0);
    ASSERT(area->src.y >= 0);
    ASSERT(area->src.width > 0);
    ASSERT(area->src.height > 0);
    ASSERT(area->dst.width > 0);
    ASSERT(area->dst.height > 0);
    if (area->src.x + area->src.width > cell_p->org_image_width ||
        area->src.y + area->src.height > cell_p->org_image_height)
    {
        ret_code = SRV_MEDIACACHE_ERR_SOURCE_AREA;
        srv_mediacache_set_last_err(SRV_MEDIACACHE_ERR_GROUP_MEDIACACHE, SRV_MEDIACACHE_ERR_SOURCE_AREA);
        return ret_code;
    }
    memcpy(&src, &area->src, sizeof(srv_mediacache_rect_struct));
    src.x = (area->src.x) * cell_p->image_width / cell_p->org_image_width;
    src.y = (area->src.y) * cell_p->image_height / cell_p->org_image_height;
    src.width = (area->src.width - 1) * cell_p->image_width / cell_p->org_image_width;
    src.height = (area->src.height - 1) * cell_p->image_height / cell_p->org_image_height;
    src_buf_length = srv_mediacache_cache_get_img_size_by_type(cell_p->type);

//add by scalado vincent
#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__

    /*if current image is in render buffer async, will cancel render,
      for we want to use render at one. but scalado only allow one render at the sam time
      so we cancel previous one*/

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_JUDEGE_NEED_SCALADO);

    if (g_mediacache_cntx_p->decoding_p && (g_mediacache_cntx_p->decoding_p == cell_p)) 
    {
        /* kill image handle and create new one for him*/
        if (g_mediacache_cntx_p->level1_curr_p == cell_p)
        {
            srv_mediacache_cancel_nb_render(cell_p, MMI_TRUE);
        }
        else
        {
            srv_mediacache_cancel_nb_render(cell_p, MMI_FALSE);
        }

        // here we give up using ies to render, for it render speed is slow.
        // we will use L1 cache image for app
        is_give_up_ies_render = MMI_TRUE;
    }

    if (!is_give_up_ies_render && srv_mediacache_is_ies_image_ready(cell_p, area))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_USING_IES);

        if (g_mediacache_cntx_p->decoding_p && (g_mediacache_cntx_p->decoding_p == cell_p)) 
        {
            /* kill image handle and create new one for him*/
            //srv_mediacache_cancel_nb_render(cell_p, MMI_TRUE);
        }
    
        IES_START_CTX_LOGGING("SPZ");

        if(NULL == cell_p->ies_image_handle)
        {
            ASSERT(0);
        }

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_DESTROY_PREVIEW_HANDLE_IF_NEEDED);
        // check if we should destroy the preview since client changed target layer
        if(cell_p->ies_preview_handle && cell_p->ies_preview_gdi_layer != area->dst_layer)
        {
            if (cell_p->ies_preview_gdi_layer == NULL)
            {
                cell_p->ies_preview_gdi_layer = area->dst_layer;
            }
            else
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRV_IES_PREVIEW_DESTROY);
                srv_ies_preview_destroy(cell_p->ies_preview_handle);
                cell_p->ies_preview_handle = NULL;
                cell_p->ies_preview_gdi_layer = NULL;
            }
        }

        if (area->anim_hint == SRV_MEDIACACHE_ANIM_HINT_ROTATION)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRV_IES_PREVIEW_DESTROY);
            if (cell_p->ies_preview_handle)
            {
                srv_ies_preview_destroy(cell_p->ies_preview_handle);
            }
            cell_p->ies_preview_handle = NULL;
            cell_p->ies_preview_gdi_layer = NULL;
        }

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_DESTROY_PREVIEW_HANDLE_IF_NEEDED);

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_CREATE_PREVIEW_HANDLE_IF_NEEDED);
        if(NULL == cell_p->ies_preview_handle)
        {
            S32 layer_w = 0;
            S32 layer_h = 0;
            gdi_color_format layer_format = 0;
            U8 *layer_buf_ptr = NULL;

            gdi_layer_push_and_set_active(area->dst_layer);
            gdi_layer_get_dimension(&layer_w, &layer_h);
            gdi_layer_get_color_format(&layer_format);
            gdi_layer_get_buffer_ptr(&layer_buf_ptr);
            ASSERT(GDI_COLOR_FORMAT_16 == layer_format);
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRV_IES_PREVIEW_CREATE);
            ies_ret_code = srv_ies_preview_create(cell_p->ies_image_handle, 
                                   &cell_p->ies_preview_handle, 
                                   layer_buf_ptr,
                                   layer_w * 2 * layer_h,
                                   layer_w, 
                                   layer_h, 
                                   layer_w * 2, 
                                   SRV_IES_COLORFORMAT_RGB565);
            gdi_layer_pop_and_restore_active();
            cell_p->ies_preview_gdi_layer = area->dst_layer;
            
            if(ies_ret_code != SRV_IES_OK)
            {
                srv_mediacache_set_last_err(SRV_MEDIACACHE_ERR_GROUP_GDI, SRV_MEDIACACHE_ERR_IES_PREVIEW_FAIL);
                srv_mediacache_resume_decode_with_delay(g_mediacache_cntx_p);
                srv_mediacache_decode_schedule();
                IES_STOP_CTX_LOGGING("SPZ");
                return SRV_MEDIACACHE_ERR_IES_PREVIEW_FAIL;
            }
        }
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_CREATE_PREVIEW_HANDLE_IF_NEEDED);

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_IES_DRAWING_SWITCH);

        // HACK: ies screen preview is always full-screen,
        // so we ignore the area->dst and draw to entire dst_layer.
        if(cell_p->ies_preview_handle)
        {
            U8 *verify_buf_ptr = NULL;

            ASSERT(cell_p->ies_preview_gdi_layer == area->dst_layer);

            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_IES_DRAWING_SWITCH);
            gdi_layer_push_and_set_active(area->dst_layer);

            gdi_layer_get_buffer_ptr(&verify_buf_ptr);

            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_IES_DRAWING_SWITCH);

            switch(area->anim_hint)
            {
            case SRV_MEDIACACHE_ANIM_HINT_NEUTRAL:
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_SRV_IES_PREVIEW_RENDER);
                    ies_ret_code = srv_ies_preview_render(cell_p->ies_preview_handle);
                    if (ies_ret_code != SRV_IES_OK)
                    {
                        srv_mediacache_set_last_err(SRV_MEDIACACHE_ERR_GROUP_GDI, SRV_MEDIACACHE_ERR_IES_RENDER_FAIL);
                    }

                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_SRV_IES_PREVIEW_RENDER);
                }
                break;

            case SRV_MEDIACACHE_ANIM_HINT_ROTATION:
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_SRV_IES_IMAGE_ROTATE_ADJUST);

                    /*
                    srv_ies_image_rotate_begin(cell_p->ies_image_handle);
                    srv_ies_image_rotate_adjust(cell_p->ies_image_handle,area->rotation_step);
                    srv_ies_image_rotate_end(cell_p->ies_image_handle);
                    srv_ies_preview_render(cell_p->ies_preview_handle);
                    srv_ies_preview_rotate(cell_p->ies_preview_handle, area->rotation_step);
                    */
                    ies_ret_code = srv_ies_preview_render(cell_p->ies_preview_handle);
                    if (ies_ret_code != SRV_IES_OK)
                    {
                        srv_mediacache_set_last_err(SRV_MEDIACACHE_ERR_GROUP_GDI, SRV_MEDIACACHE_ERR_IES_RENDER_FAIL);
                    }
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_SRV_IES_IMAGE_ROTATE_ADJUST);
                }
                break;

            case SRV_MEDIACACHE_ANIM_HINT_PAN:
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_SRV_IES_PREVIEW_SET_PAN_DELTA);
                    ies_ret_code = srv_ies_preview_set_pan_delta(cell_p->ies_preview_handle, area->delta_x, area->delta_y);
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_IES_SET_PAN_ERROR_D, ies_ret_code);
                    if (ies_ret_code != SRV_IES_OK)
                    {
                        srv_mediacache_set_last_err(SRV_MEDIACACHE_ERR_GROUP_GDI, SRV_MEDIACACHE_ERR_IES_SET_PAN_FAIL);
                    }
                    ies_ret_code = srv_ies_preview_render(cell_p->ies_preview_handle);
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_SRV_IES_PREVIEW_SET_PAN_DELTA);
                }
                break;

            case SRV_MEDIACACHE_ANIM_HINT_RUNNING:
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_SRV_IES_PREVIEW_RENDER_ANIMATED);
                    ies_ret_code = srv_ies_preview_render_animated(
                        cell_p->ies_preview_handle,
                        area->zoom_target,
                        area->anim_progress,
                        MMI_FALSE);
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_SRV_IES_PREVIEW_RENDER_ANIMATED_D, ies_ret_code);
                    
                    if (ies_ret_code != SRV_IES_OK)
                    {
                        srv_mediacache_set_last_err(SRV_MEDIACACHE_ERR_GROUP_GDI, SRV_MEDIACACHE_ERR_IES_ANIM_END_FAIL);
                    }

                }
                break;

            case SRV_MEDIACACHE_ANIM_HINT_END:
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_RUNNING_ANIM_OVER);
                    ies_ret_code = srv_ies_preview_render_animated(
                        cell_p->ies_preview_handle,
                        area->zoom_target,
                        area->anim_progress,
                        MMI_TRUE);
                    if (ies_ret_code != SRV_IES_OK)
                    {
                        srv_mediacache_set_last_err(SRV_MEDIACACHE_ERR_GROUP_GDI, SRV_MEDIACACHE_ERR_IES_ANIM_END_FAIL);
                    }
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_RUNNING_ANIM_OVER);
                }
                break;

            /* Removed by CHYang
            case SRV_MEDIACACHE_ANIM_HINT_FORCE_FLUSH:
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_SRV_IES_PREVIEW_RENDER_FORCE_DRAW_ANIM_OVER);
                    ies_ret_code = srv_ies_preview_render_force_draw(cell_p->ies_preview_handle);
                    if (ies_ret_code != SRV_IES_OK)
                    {
                        srv_mediacache_set_last_err(SRV_MEDIACACHE_ERR_GROUP_GDI, SRV_MEDIACACHE_ERR_IES_ANIM_END_FAIL);
                    }
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_SRV_IES_PREVIEW_RENDER_FORCE_DRAW);
                }
                break;
            */
            }

            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_IES_DRAWING_SWITCH);

            gdi_layer_pop_and_restore_active();
            
        #ifdef __SRV_MEDIACACHE_INTERNAL_TEST__
            if (1)
            {
                S32 layer_w = 0;
                S32 layer_h = 0;

                gdi_layer_push_and_set_active(area->dst_layer);
                gdi_layer_get_dimension(&layer_w, &layer_h);
                gdi_layer_pop_and_restore_active();

                if (layer_w > 24 && layer_h > 24)
                {
                    U8* m_data_p = verify_buf_ptr;
                    U8* m_data_end_p = verify_buf_ptr + layer_w * 24 * 2;
                    S32 m_pitch = layer_w * 2;
                    S32 m_length = 24 * 2;

                    while (m_data_p<m_data_end_p)
                    {
                        memset(m_data_p,0xBB,m_length);
                        m_data_p += m_pitch;
                    }

                    if (srv_ies_is_image_handle_has_meta(cell_p->ies_image_handle))
                    {
                        m_data_end_p += layer_w * 24 * 2; 

                        while (m_data_p<m_data_end_p)
                        {
                            memset(m_data_p,0xEE,m_length);
                            m_data_p += m_pitch;
                        }
                    }
                }
            }
        #endif

        }

        // TODO: re-organize the control flow here since we early-return.
        srv_mediacache_decode_schedule();
        IES_STOP_CTX_LOGGING("SPZ");
    }
    else
#endif /* __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__ */
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_JUDEGE_DO_NOT_NEED_TO_IES);

        gdi_layer_create_cf_using_outside_memory(
            g_mediacache_cntx_p->color_format,
            0,
            0,
            cell_p->image_width,
            cell_p->image_height,
            &src_layer,
            cell_p->buffer,
            src_buf_length);

        gdi_layer_push_and_set_active(area->dst_layer);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
            MMI_TRC_SRV_MEDIACACHE_INFO_REZIER_SRC_DST,
            src.x,
            src.y,
            src.x + src.width,
            src.y + src.height,
            area->dst.x,
            area->dst.y,
            area->dst.x + area->dst.width - 1,
            area->dst.y + area->dst.height - 1);
    #ifndef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
        srv_mediacache_pause_decode((srv_handle)g_mediacache_cntx_p);
    #endif

        kal_get_time(&g_mediacache_cntx_p->start_ticks);
        if (NULL != g_mediacache_cntx_p->decoding_p)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_CANCEL_DECODE_CELL_AT_D, __LINE__);
            g_mediacache_cntx_p->engine.cancel_decode_cell(g_mediacache_cntx_p->image_hdl_decoding);
            g_mediacache_cntx_p->image_hdl_decoding = 0;
            g_mediacache_cntx_p->decoding_p = NULL;
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_DECODING_P_IS_NULL_D, __LINE__);
        }
        
        if (g_mediacache_cntx_p->is_using_ies && (cell_p->image_type == GDI_IMAGE_TYPE_JPG_FILE))
        {
            // Scalado won't avoid color key, so disable color key in source layer.
            gdi_layer_set_source_key_nb_concurrent(src_layer, MMI_FALSE, GDI_COLOR_TRANSPARENT);
            //for ies, we always do nto use gdi resizer. only use 1X image. can not enlarge image
            ret_code = gdi_bitblt_resized_with_resizer(
                        src_layer,
                        0,
                        0,
                        cell_p->image_width - 1,
                        cell_p->image_height - 1,
                        area->dst.x,
                        area->dst.y,
                        area->dst.x + area->dst.width - 1,
                        area->dst.y + area->dst.height - 1,
                        _srv_mediacache_quality_to_gdi_quality(g_mediacache_cntx_p->qulity));
        }
        else
        {
            gdi_layer_set_source_key_nb_concurrent(src_layer, MMI_TRUE, GDI_COLOR_TRANSPARENT);
            ret_code = gdi_bitblt_resized_with_resizer(
                        src_layer,
                        src.x,
                        src.y,
                        src.x + src.width,
                        src.y + src.height,
                        area->dst.x,
                        area->dst.y,
                        area->dst.x + area->dst.width - 1,
                        area->dst.y + area->dst.height - 1,
                        GDI_RESIZER_DEFAULT);
                        // MAUI_03146953: use GDI_RESIZER_DEFAULT to use HW resizer.
                        // note that HW resizer now supports source clipping region.
                        // _srv_mediacache_quality_to_gdi_quality(g_mediacache_cntx_p->qulity));
        }
        
        if(g_mediacache_cntx_p->qulity == SRV_MEDIACACHE_RESIZE_QULITY_HIGH)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_HIGH_QUALITY_RESIZER);
        }
        g_mediacache_cntx_p->qulity = SRV_MEDIACACHE_RESIZE_QULITY_DEFAULT;    
        kal_get_time(&g_mediacache_cntx_p->end_ticks);
    #ifndef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
        srv_mediacache_resume_decode_with_delay(g_mediacache_cntx_p);
    #endif
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_REZIER_TICKS,g_mediacache_cntx_p->end_ticks - g_mediacache_cntx_p->start_ticks);
        gdi_layer_pop_and_restore_active();
        gdi_layer_free(src_layer);
    }

#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
    if (g_mediacache_cntx_p->is_using_ies)
    {
        if (ies_ret_code != SRV_IES_OK)
        {        
            cell_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
            cell_p->err_code = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
            cell_p->err_group = SRV_MEDIACACHE_ERR_GROUP_GDI;

            return ies_ret_code; 
        }
    }
#endif

    if (ret_code < 0)
    {
        srv_mediacache_set_last_err(SRV_MEDIACACHE_ERR_GROUP_GDI, ret_code);
    }
    else
    {
        switch(cell_p->type)
        {
        case SRV_MEDIACACHE_CACHE_TYPE_L1:
            g_mediacache_cntx_p->last_source = SRV_MEDIACACHE_OK_L1;
            break;
        case SRV_MEDIACACHE_CACHE_TYPE_L2:
            g_mediacache_cntx_p->last_source = SRV_MEDIACACHE_OK_L2;
            break;
        case SRV_MEDIACACHE_CACHE_TYPE_LARGE:
            g_mediacache_cntx_p->last_source = SRV_MEDIACACHE_OK_LARGE;
            break;
        default:
            ASSERT(0);
        }
    }
#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
    srv_mediacache_resume_decode_with_delay(g_mediacache_cntx_p);
    // do not start decode immediately because decode may destroy IES preview handle
    srv_mediacache_check_and_start_decode();
#else
    srv_mediacache_decode_schedule();
#endif

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_RESIZE2LAYER_INTERNAL);

    return ret_code;
}


#if defined(__MTK_INTERNAL_TTTTTTTTTT__)
/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cache_resize2layer
 * DESCRIPTION
 *  resize the cache to layer by group and index
 * PARAMETERS
 *  dest_layer  [IN]    dest layer to draw to
 *  dest_x      [IN]    offset of x according to dest
 *  dest_y      [IN]    offest of y according to dest
 *  zoomfactor  [IN]    zoom factor * 1000
 *  x           [IN]    x after zoom of org image
 *  y           [IN]    y after zoom of org image
 *  width       [IN]    width after zoom of org image
 *  height      [IN]    height after zoom of org image
 *  group       [IN]    gourp index
 *  index       [IN]    index
 * RETURNS
 *  error code        
 *****************************************************************************/
static S32 srv_mediacache_cache_resize2buffer(srv_mediacache_cell_struct *cell_p, srv_mediacache_img_to_buffer_struct *buf_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret_code = SRV_MEDIACACHE_OK;
    U32 src_buf_length;
    gdi_handle dst_layer;
    gdi_handle src_layer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(cell_p != NULL);
    ASSERT(srv_mediacache_cache_cell_can_draw(cell_p) == MMI_TRUE);
    ASSERT(cell_p->image_width > 0 && cell_p->image_height > 0);
    ASSERT(buf_p->width >= 0);
    ASSERT(buf_p->height >= 0);
    src_buf_length = srv_mediacache_cache_get_img_size_by_type(cell_p->type);
    gdi_layer_create_cf_using_outside_memory(
        g_mediacache_cntx_p->color_format,
        0,
        0,
        cell_p->image_width,
        cell_p->image_height,
        &src_layer,
        cell_p->buffer,
        src_buf_length);
    gdi_layer_create_cf_using_outside_memory(
        g_mediacache_cntx_p->color_format,
        0,
        0,
        buf_p->width,
        buf_p->height,
        &dst_layer,
        buf_p->buffer,
        buf_p->length);
    gdi_layer_set_source_key_nb_concurrent(src_layer, MMI_TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key_nb_concurrent(dst_layer, MMI_TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_push_and_set_active(dst_layer);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
        MMI_TRC_SRV_MEDIACACHE_INFO_REZIER_SRC_DST,
        0,
        0,
        cell_p->image_width,
        cell_p->image_height,
        0,
        0,
        buf_p->width,
        buf_p->height);
    kal_get_time(&g_mediacache_cntx_p->start_ticks);    
    ret_code = gdi_bitblt_resized_with_resizer(
            src_layer,
            0,
            0,
            cell_p->image_width,
            cell_p->image_height,
            0,
            0,
            buf_p->width,
            buf_p->height,
            _srv_mediacache_quality_to_gdi_quality(g_mediacache_cntx_p->qulity));
    if(g_mediacache_cntx_p->qulity == GDI_RESIZER_SW_QUALITY_HIGH)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_HIGH_QUALITY_RESIZER);
    }
    g_mediacache_cntx_p->qulity = SRV_MEDIACACHE_RESIZE_QULITY_DEFAULT;

    kal_get_time(&g_mediacache_cntx_p->end_ticks);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_REZIER_TICKS,g_mediacache_cntx_p->end_ticks - g_mediacache_cntx_p->start_ticks);
    gdi_layer_pop_and_restore_active();
    gdi_layer_free(src_layer);
    gdi_layer_free(dst_layer);
    if (ret_code < 0)
    {
        srv_mediacache_set_last_err(SRV_MEDIACACHE_ERR_GROUP_GDI, ret_code);
    }
    return ret_code;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_decode_schedule
 * DESCRIPTION
 *  start schedule the pre buffer process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 srv_mediacache_decode_get_filename_by_index(S32 index, U16 *buffer, U32 length, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    static U8 m_test = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_SRV_FMGR_FILELIST_GET_FILEPATH);
    ret = srv_fmgr_filelist_get_filepath(g_mediacache_engine_cntx.flist_handle, index, (WCHAR*)buffer, length);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_SRV_FMGR_FILELIST_GET_FILEPATH);
    
    if (ret < 0 && NULL != g_mediacache_cntx_p->events_callback)
    {
        g_mediacache_cntx_p->events_getfilename_err.error_code = ret;
        g_mediacache_cntx_p->events_getfilename_err.file_index = index;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_DRM_GET_OBJECT_METHOD);
#ifdef __DRM_SUPPORT__
    if (DRM_get_object_method(NULL, (kal_wchar*)buffer) != DRM_METHOD_NONE)
    {
        if(ret >= 0 && !DRM_validate_permission(0, (kal_wchar*)buffer, DRM_PERMISSION_DISPLAY))
        {
            return DRM_RESULT_NO_PERMISSION;
        }
    }
#endif
    if (ret < 0 && m_test == 1)
    {
        ASSERT(0);
    }
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_DRM_GET_OBJECT_METHOD);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_decode_schedule
 * DESCRIPTION
 *  start schedule the pre buffer process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 srv_mediacache_engine_file_get_filename(S32 index, U16 *buffer, U32 length, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_SRV_MEDIACACHE_ENGINE_FILE_GET_FILENAME);
    
    if ((U16*)g_mediacache_cntx_p->config.filename != buffer)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_COPY_FILE_NAME_IN_ENGIEN_GET_FILE_NAME);
        memcpy(buffer, g_mediacache_cntx_p->config.filename, SRV_FMGR_PATH_BUFFER_SIZE);
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_COPY_FILE_NAME_IN_ENGIEN_GET_FILE_NAME);
    }
    length = mmi_ucs2strlen((CHAR*)buffer) * 2;
    ASSERT(SRV_FMGR_PATH_BUFFER_SIZE >= length);
#ifdef __DRM_SUPPORT__
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_DRM_GET_OBJECT_METHOD);
    if (DRM_get_object_method(NULL, (kal_wchar*)buffer) != DRM_METHOD_NONE)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_DRM_VALIDATE_PERMISSION);
        if(!DRM_validate_permission(0, (kal_wchar*)buffer, DRM_PERMISSION_DISPLAY))
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_DRM_VALIDATE_PERMISSION);
            return DRM_RESULT_NO_PERMISSION;
        }
    }
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_DRM_GET_OBJECT_METHOD);
#endif

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_SRV_MEDIACACHE_ENGINE_FILE_GET_FILENAME);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_decode_pre_clear_bg_cb
 * DESCRIPTION
 *  callback function of non-block image decode pre-decode clear background
 * PARAMETERS
 *  result  [IN]   result
 *  handle  [IN]   GDI handle
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mediacache_decode_pre_clear_bg_cb(GDI_RESULT result,gdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mediacache_cntx_p->is_srv_clear_bg == MMI_TRUE)
    {
        gdi_layer_clear(g_mediacache_cntx_p->bg_color);
    }
    else
    {
        gdi_layer_clear(GDI_COLOR_BLACK);
    }
}


void srv_mediacache_decode_nb_decode_callback(S32 result, srv_mediacache_err_group_enum group, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *first_p;
    srv_mediacache_cell_struct  *decoding_p;
    srv_mediacache_cell_struct *cache_cell = NULL;
    S32 index;
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
    U16 key_code[SRV_MEDIACACHE_KEY_CODE_SIZE], *m_buffer_p = NULL;
    U32 key_code_step = 1;
    U32 mem_size = 0, i;
	S32 ret = 0;
#endif
#ifdef __SRV_MEDIACACHE_DEBUG_MEASURE__
    U32 ticks;
    U16 temp_string[30];
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mediacache_cntx_p = (srv_mediacache_cntx_struct*)user_data;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_DECODE_CB);
    if (NULL == g_mediacache_cntx_p)
    {
        return;
    }
    if (g_mediacache_cntx_p->state != SRV_MEDIACACHE_STATE_RUNNING && g_mediacache_cntx_p->state != SRV_MEDIACACHE_STATE_PAUSED)
    {
        return;
    }
    if (g_mediacache_cntx_p->decoding_p == NULL)
    {
        /*App may stop and destory SRV at callback so here need check state*/
        if (g_mediacache_cntx_p->state == SRV_MEDIACACHE_STATE_RUNNING)
        {
            srv_mediacache_check_and_start_decode();  
        }
        return;
    }
    decoding_p = g_mediacache_cntx_p->decoding_p;
#ifdef __SRV_MEDIACACHE_DEBUG_MEASURE__
    kal_get_time(&ticks);
    decoding_p->decode_ticks = ticks - decoding_p->decode_ticks;
    kal_print_string_trace(MOD_MMI_MEDIA_APP, MMI_MEDIA_TRC_G2_APP, "[srvmc]decode time cost [%d]=%d", decoding_p->file_index, decoding_p->decode_ticks);
    /*if (NULL != g_mediacache_cntx_p->layer)
    {
        gdi_layer_push_and_set_active(g_mediacache_cntx_p->layer);
        kal_wsprintf(temp_string, "Dec %d",decoding_p->decode_ticks);
        gui_print_bordered_text(temp_string);
        gdi_layer_pop_and_restore_active();
    }*/
#endif
    if (result == GDI_SUCCEED)
    {
        ASSERT(decoding_p->image_width > 0);
        ASSERT(decoding_p->image_height > 0);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_DECODE_OK);
        decoding_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_OK;
        decoding_p->err_code = SRV_MEDIACACHE_OK;
        decoding_p->err_group = SRV_MEDIACACHE_ERR_GROUP_OK;
        index = decoding_p->file_index;
        if (SRV_MEDIACACHE_CACHE_TYPE_LARGE == g_mediacache_cntx_p->decoding_p->type)
        {
            g_mediacache_cntx_p->large_image_dec_hdlr = 0;
        }
        /*if (decoding_p->type == SRV_MEDIACACHE_CACHE_TYPE_LARGE &&
            NULL != g_mediacache_cntx_p->level1_curr_p)
        {
            ASSERT(decoding_p->file_index == g_mediacache_cntx_p->level1_curr_p->file_index);

        #if 0    
        #ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
            //this code should not run there, for we do not use large if image is JPG type. so I 
            //remove this code.
            if (!_srv_mediacache_decode_need_ies_check(g_mediacache_cntx_p->decoding_p))
            {
            srv_mediacache_cache_cpy_cb_and_buffer(
                g_mediacache_cntx_p->level1_curr_p,
                decoding_p);
            }
        #endif
        #endif
            srv_mediacache_cache_cpy_cb_and_buffer(
                g_mediacache_cntx_p->level1_curr_p,
                decoding_p);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_DECODE_THE_ONE_IS_LARGE);
        }*/
        if (decoding_p->type == SRV_MEDIACACHE_CACHE_TYPE_L1 || 
            decoding_p->type == SRV_MEDIACACHE_CACHE_TYPE_LARGE)
        {
            first_p = srv_mediacache_link_get_first(g_mediacache_cntx_p->level2_curr_p);
            while (first_p != NULL)
            {
                if (decoding_p->file_index == first_p->file_index)
                {
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
                    if (first_p->image_width > 0 && first_p->image_height > 0)
                    {
                        mem_size = first_p->image_width * first_p->image_height * 2;
                    }
                    else
                    {
                        mem_size = 0;
                    }
                    key_code_step = mem_size/SRV_MEDIACACHE_KEY_CODE_SIZE;
                    m_buffer_p = (U16*)first_p->buffer;
                    for (i = 0; i<SRV_MEDIACACHE_KEY_CODE_SIZE; i++)
                    {
                        key_code[i] = *(m_buffer_p + key_code_step * i);
                    }
#endif
                    if (srv_mediacache_cache_cell_can_draw(first_p) == MMI_FALSE)
                    {
                        srv_mediacache_cache_cpy_cb_and_buffer(
                            first_p,
                            decoding_p);
                    }
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
                    m_buffer_p = (U16*)first_p->buffer;
                    if (srv_mediacache_cache_cell_can_draw(g_mediacache_cntx_p->level1_curr_p) == MMI_TRUE)
                    {
                        if (decoding_p->type == SRV_MEDIACACHE_CACHE_TYPE_LARGE && GDI_MAINLCD_BIT_PER_PIXEL == 2)
                        {
                            for (i = 0; i<SRV_MEDIACACHE_KEY_CODE_SIZE; i++)
                            {
                                if ((key_code[i] & 0x8610) != *(m_buffer_p + key_code_step * i) & 0x8610)
                                {
                                    ASSERT(NULL != g_mediacache_cntx_p->engine.get_file_name);
                                    ret = g_mediacache_cntx_p->engine.get_file_name(
                                        first_p->file_index, 
                                        (U16*)g_mediacache_cntx_p->config.filename, 
                                        SRV_FMGR_PATH_BUFFER_SIZE,
                                        NULL);
                                    if (ret < 0)
                                    {
                                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_GET_NAME_FAILED,ret,__LINE__);
                                    }
                                    break;
                                }
                            }
                            if (SRV_MEDIACACHE_KEY_CODE_SIZE != i)
                            {
                                srv_mediacache_cache_cpy_cb_and_buffer(
                                    first_p,
                                    g_mediacache_cntx_p->level1_curr_p);
                                m_buffer_p = (U16*)first_p->buffer;
                                for (i = 0; i<SRV_MEDIACACHE_KEY_CODE_SIZE; i++)
                                {
                                    if ((key_code[i] & 0x8610) != *(m_buffer_p + key_code_step * i) & 0x8610)
                                    {
                                        ASSERT(NULL != g_mediacache_cntx_p->engine.get_file_name);
                                        ret = g_mediacache_cntx_p->engine.get_file_name(
                                            first_p->file_index, 
                                            (U16*)g_mediacache_cntx_p->config.filename, 
                                            SRV_FMGR_PATH_BUFFER_SIZE,
                                            NULL);
                                        if (ret < 0)
                                        {
                                            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_GET_NAME_FAILED,ret,__LINE__);
                                        }
                                        ivd_ivsrv_db_remove_img_by_name(&g_mediacache_cntx_p->db_handle, g_mediacache_cntx_p->config.filename, NULL);
                                        break;
                                    }
                                }
                            }
                        }
                    }
#endif
                    break;
                }
                first_p = first_p->next;
            }
        }
        
        #if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
        if (g_mediacache_cntx_p->db_store_cache_group == SRV_MEDIACACHE_CACHE_TYPE_L2)
        {
            if(decoding_p && SRV_MEDIACACHE_CACHE_TYPE_L2 == decoding_p->type)
            {
                cache_cell = decoding_p;
            }
            else
            {
                cache_cell = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level2_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
            }
        }
        else if (g_mediacache_cntx_p->db_store_cache_group == SRV_MEDIACACHE_CACHE_TYPE_L1)
        {
            cache_cell = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
        }
        if (NULL != cache_cell && MMI_TRUE == srv_mediacache_cache_cell_finished(cache_cell))
        {
            #ifdef __SRV_MEDIACACHE_PUT_HIGH_PRIORITY__
            if (cache_cell->is_saved == MMI_FALSE)
            {
                srv_mediacache_db_put_img(cache_cell, srv_mediacache_save_to_db_callback, (void*)cache_cell->file_index);

                #ifdef __MMI_MEDIA_CACHE_YUV_THUMB__
                if(cache_cell->buffer_format == GDI_COLOR_FORMAT_UYVY422 && 
                   cache_cell->buffer_format != g_mediacache_cntx_p->color_format)
                {
                    // since srv_mediacache_db_put_img copies input buffer before sending to IVD task,
                    // we can convert YUV back to RGB565 here before passing back to application
                    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SRVMC][YUV] put img sent, convert YUV to RGB @%d", __LINE__);
                    SRV_MEDIACACHE_START_MEASURE("MCV");
                    // only 565 cells requires UYUV422 for better thumbnail quality.
                    ASSERT(g_mediacache_cntx_p->color_format == GDI_COLOR_FORMAT_16);
                    // convert YUV422 to RGB565 and perform dithering
                    iul_csc_yuv422itlv_to_rgb565_mwc_dithering((unsigned int*)cache_cell->buffer, (unsigned short*)cache_cell->buffer, cache_cell->image_width, cache_cell->image_height);
                    cache_cell->buffer_format = g_mediacache_cntx_p->color_format;
                    // we need to replace source key, since dithering may produce color key color
                    gd_replace_src_key_16(
                            cache_cell->buffer,
                            cache_cell->image_width,
                            0,
                            0,
                            0,
                            0,
                            cache_cell->image_width - 1,
                            cache_cell->image_height - 1,
                            GDI_COLOR_TRANSPARENT,
                            cache_cell->image_width,
                            cache_cell->image_height);
                    
                    SRV_MEDIACACHE_STOP_MEASURE("MCV");
                }
                #endif
            }
            #endif
        }
        #endif
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_DECODE_GDI_ERR, result);
        decoding_p->state       = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
        decoding_p->err_group   = SRV_MEDIACACHE_ERR_GROUP_GDI;
        decoding_p->err_code    = result;
        srv_mediacache_set_last_err(SRV_MEDIACACHE_ERR_GROUP_GDI, result);
        if (result != GDI_IMAGE_ERR_DECODE_TIME_OUT)
        {
            index = decoding_p->file_index;
            if (decoding_p && g_mediacache_cntx_p->is_using_ies && (decoding_p->image_type == GDI_IMAGE_TYPE_JPG_FILE))
            {
                //do nothing, for we do not use large
            }
            else
            {
                cache_cell = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->large_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
                if (NULL != cache_cell && decoding_p != cache_cell && MMI_FALSE == srv_mediacache_cache_cell_finished(cache_cell))
                {
                    srv_mediacache_cache_cpy_cb_and_buffer(cache_cell,decoding_p);
                }
            }

            cache_cell = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
            if (NULL != cache_cell && decoding_p != cache_cell && MMI_FALSE == srv_mediacache_cache_cell_finished(cache_cell))
            {
                srv_mediacache_cache_cpy_cb_and_buffer(cache_cell,decoding_p);
            }
            cache_cell = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level2_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
            if (NULL != cache_cell && decoding_p != cache_cell && MMI_FALSE == srv_mediacache_cache_cell_finished(cache_cell))
            {
                srv_mediacache_cache_cpy_cb_and_buffer(cache_cell,decoding_p);
            }
        }
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
        if (result != GDI_IMAGE_ERR_DECODE_TIME_OUT && g_mediacache_cntx_p->is_db_start_ok == MMI_TRUE)
        {
            ASSERT(NULL != g_mediacache_cntx_p->engine.get_file_name);
            ret = g_mediacache_cntx_p->engine.get_file_name(
                decoding_p->file_index, 
                (U16*)g_mediacache_cntx_p->config.filename, 
                SRV_FMGR_PATH_BUFFER_SIZE,
                NULL);
            if (ret < 0)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_GET_NAME_FAILED,ret, __LINE__);
            }
            ivd_ivsrv_db_remove_img_by_name(&g_mediacache_cntx_p->db_handle, g_mediacache_cntx_p->config.filename, NULL);
        }
#endif
        srv_mediacache_check_cb_and_call(decoding_p, g_mediacache_cntx_p->cb_file_idx, MMI_TRUE);
    }

    /*Report to application if a callback has been assigned */
    srv_mediacache_callback_to_app_if_needed();
    
    /*App may stop and destory SRV at callback so here need check state*/
    if (g_mediacache_cntx_p->state == SRV_MEDIACACHE_STATE_RUNNING)
    {
        srv_mediacache_check_and_start_decode();  
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_decode_check_and_free_layer
 * DESCRIPTION
 *  safe function of layer free
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mediacache_decode_check_and_free_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mediacache_cntx_p->layer != NULL)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_CANCEL_DECODE_CELL_AT_D, __LINE__);
        g_mediacache_cntx_p->engine.cancel_decode_cell(g_mediacache_cntx_p->image_hdl_decoding);
        g_mediacache_cntx_p->image_hdl_decoding = 0;
        g_mediacache_cntx_p->decoding_p = NULL;
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_DECODING_P_IS_NULL_D, __LINE__);
        gdi_layer_free(g_mediacache_cntx_p->layer);
        g_mediacache_cntx_p->layer = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_decode_check_curr
 * DESCRIPTION
 *  check if curr one is finished buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  NULL or pointer to the unfinished cell
 *****************************************************************************/
static srv_mediacache_cell_struct *srv_mediacache_decode_check_curr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *level1_curr_p = g_mediacache_cntx_p->level1_curr_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == level1_curr_p)
    {
        return NULL;
    }
    switch(g_mediacache_cntx_p->decode_method)
    {
    case SRV_MEDIACACHE_CACHE_METHOD_DEFAULT:
    case SRV_MEDIACACHE_CACHE_METHOD_M1:
        if (level1_curr_p->state == SRV_MEDIACACHE_CACHE_STATE_EMPTY ||
            level1_curr_p->state == SRV_MEDIACACHE_CACHE_STATE_RESIZE_FROM_L2)
        {
            return level1_curr_p;
        }
        break;
    default:
        ASSERT(0);
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_decode_check_large
 * DESCRIPTION
 *  check if large image is finished buffer process
 * PARAMETERS
 *  void
 * RETURNS
 *  NULL or the pointer of unfinished cell
 *****************************************************************************/
static srv_mediacache_cell_struct *srv_mediacache_decode_check_large(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_mediacache_cntx_p->decode_method)
    {
    case SRV_MEDIACACHE_CACHE_METHOD_DEFAULT:
    case SRV_MEDIACACHE_CACHE_METHOD_M1:
        /*Decode small first for decode thumbnail is fast*/
        if (srv_mediacache_cache_cell_finished(g_mediacache_cntx_p->level2_curr_p) == MMI_FALSE)
        {
            return g_mediacache_cntx_p->level2_curr_p;
        }

#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
        if (_srv_mediacache_decode_need_ies_check(g_mediacache_cntx_p->level1_curr_p))
        {
            if (srv_mediacache_cache_cell_finished(g_mediacache_cntx_p->level1_curr_p) == MMI_FALSE)
            {
                return g_mediacache_cntx_p->level1_curr_p;
            }
            else
            {
                if (g_mediacache_cntx_p->level1_curr_p)
                {
                    if (g_mediacache_cntx_p->level1_curr_p == g_mediacache_cntx_p->level1_curr_p)
                    {
                        if(g_mediacache_cntx_p->level1_curr_p->ies_image_handle == NULL)
                        {
                            return g_mediacache_cntx_p->level1_curr_p;
                        }
                    }
                }
            }
        }
        else 
        {
            if (srv_mediacache_cache_cell_finished2(g_mediacache_cntx_p->level1_curr_p) == MMI_FALSE)
            {
                return g_mediacache_cntx_p->level1_curr_p;
            }
        }
#else /*__MMI_SRV_MEDIA_CACHE_USE_SRV_IES__*/
        if (srv_mediacache_cache_cell_finished(g_mediacache_cntx_p->level1_curr_p) == MMI_FALSE)
        {
            return g_mediacache_cntx_p->level1_curr_p;
        }
#endif /*__MMI_SRV_MEDIA_CACHE_USE_SRV_IES__*/

        if (NULL != g_mediacache_cntx_p->large_p)
        {
            if (NULL != g_mediacache_cntx_p->level1_curr_p)
            {
                if (g_mediacache_cntx_p->large_p->file_index != g_mediacache_cntx_p->level1_curr_p->file_index)
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_RESET_CELL_LINE, __LINE__);
                    srv_mediacache_cache_reset_cell(g_mediacache_cntx_p->large_p,MMI_FALSE);
                    g_mediacache_cntx_p->large_p->file_index = g_mediacache_cntx_p->level1_curr_p->file_index;
                }
            }
            if (NULL != g_mediacache_cntx_p->level1_curr_p)
            {
            #ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
                if (_srv_mediacache_decode_need_ies_check(g_mediacache_cntx_p->level1_curr_p->next))
                {
                    if (srv_mediacache_cache_cell_finished(g_mediacache_cntx_p->level1_curr_p->next) == MMI_FALSE)
                    {
                        return g_mediacache_cntx_p->level1_curr_p->next;
                    }
                }
                else
                {
                    if (srv_mediacache_cache_cell_finished2(g_mediacache_cntx_p->level1_curr_p->next) == MMI_FALSE)
                    {
                        return g_mediacache_cntx_p->level1_curr_p->next;
                    }
                }
            #else /*__MMI_SRV_MEDIA_CACHE_USE_SRV_IES__*/
                if (srv_mediacache_cache_cell_finished(g_mediacache_cntx_p->level1_curr_p->next) == MMI_FALSE)
                {
                    return g_mediacache_cntx_p->level1_curr_p->next;
                }
            #endif /*__MMI_SRV_MEDIA_CACHE_USE_SRV_IES__*/

            #ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
                if (_srv_mediacache_decode_need_ies_check(g_mediacache_cntx_p->level1_curr_p->prev))
                {
                    if (srv_mediacache_cache_cell_finished(g_mediacache_cntx_p->level1_curr_p->prev) == MMI_FALSE)
                    {
                        return g_mediacache_cntx_p->level1_curr_p->prev;
                    }
                }
                else
                {
                    if (srv_mediacache_cache_cell_finished2(g_mediacache_cntx_p->level1_curr_p->prev) == MMI_FALSE)
                    {
                        return g_mediacache_cntx_p->level1_curr_p->prev;
                    }
                }
            #else /*__MMI_SRV_MEDIA_CACHE_USE_SRV_IES__*/
                if (srv_mediacache_cache_cell_finished(g_mediacache_cntx_p->level1_curr_p->prev) == MMI_FALSE)
                {
                    return g_mediacache_cntx_p->level1_curr_p->prev;
                }
            #endif /*__MMI_SRV_MEDIA_CACHE_USE_SRV_IES__*/
            }

        #ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
            if (g_mediacache_cntx_p->level1_curr_p && g_mediacache_cntx_p->is_using_ies && (g_mediacache_cntx_p->level1_curr_p->image_type == GDI_IMAGE_TYPE_JPG_FILE))
            {
                /* here means, we always using L1 to create image handle, do not use large */
                return NULL;
            }
        #endif

            if (srv_mediacache_cache_cell_finished(g_mediacache_cntx_p->large_p) == MMI_FALSE)
            {
                return g_mediacache_cntx_p->large_p;
            }
        }
        break;
    default:
        ASSERT(0);
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_decode_check_l1
 * DESCRIPTION
 *  check if L1 has unfinished cache cell
 * PARAMETERS
 *  void
 * RETURNS
 *  Null or pointer to the unfinshed buffer cell
 *****************************************************************************/
static srv_mediacache_cell_struct *srv_mediacache_decode_check_l1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *cache_cell;
    srv_mediacache_cell_struct *cache_cell_return = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_mediacache_cntx_p->decode_method)
    {
    case SRV_MEDIACACHE_CACHE_METHOD_DEFAULT:
        cache_cell = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p,MMI_FALSE,
            srv_mediacache_cache_cell_is_unfinished2,NULL);
        if (NULL != cache_cell)
        {
            cache_cell->state = SRV_MEDIACACHE_CACHE_STATE_EMPTY;
        }
        cache_cell_return = cache_cell;
        break;
    case SRV_MEDIACACHE_CACHE_METHOD_M1:
        cache_cell = srv_mediacache_link_line_check(g_mediacache_cntx_p->level1_curr_p,
            srv_mediacache_cache_cell_is_unfinished2,NULL);
        if (NULL != cache_cell)
        {
            cache_cell->state = SRV_MEDIACACHE_CACHE_STATE_EMPTY;
        }
        cache_cell_return = cache_cell;
        break;
    default:
        ASSERT(0);
    }

    return cache_cell_return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_decode_check_l2
 * DESCRIPTION
 *  check if L2 has unfinished cache cell
 * PARAMETERS
 *  void
 * RETURNS
 *  Null or pointer to the unfinshed buffer cell
 *****************************************************************************/
static srv_mediacache_cell_struct *srv_mediacache_decode_check_l2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *cache_cell;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_mediacache_cntx_p->decode_method)
    {
    case SRV_MEDIACACHE_CACHE_METHOD_DEFAULT:
        cache_cell = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level2_curr_p,MMI_FALSE,srv_mediacache_cache_cell_is_unfinished,NULL);
        if (NULL != cache_cell)
        {
            cache_cell->state = SRV_MEDIACACHE_CACHE_STATE_EMPTY;
        }
        return cache_cell;
    case SRV_MEDIACACHE_CACHE_METHOD_M1:
        cache_cell = srv_mediacache_link_line_check(g_mediacache_cntx_p->level2_curr_p,srv_mediacache_cache_cell_is_unfinished,NULL);
        if (NULL != cache_cell)
        {
            cache_cell->state = SRV_MEDIACACHE_CACHE_STATE_EMPTY;
        }
        return cache_cell;
    default:
        ASSERT(0);
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_decode_schedule
 * DESCRIPTION
 *  start schedule the pre buffer process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_mediacache_cell_struct *srv_mediacache_decode_schedule_find_search_cell(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
    srv_mediacache_cell_struct *new_decode_p;
    srv_mediacache_cell_struct *search_list_p = NULL;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_DECODE_SCHEDULE);
    if (g_mediacache_cntx_p->db_store_cache_group == SRV_MEDIACACHE_CACHE_TYPE_L2)
    {
        search_list_p = g_mediacache_cntx_p->level2_curr_p;
    }
    else if (g_mediacache_cntx_p->db_store_cache_group == SRV_MEDIACACHE_CACHE_TYPE_L1)
    {
        search_list_p = g_mediacache_cntx_p->level1_curr_p;
    }
    else
    {

        search_list_p = NULL;
    }

    switch(g_mediacache_cntx_p->decode_method)
    {
    case SRV_MEDIACACHE_CACHE_METHOD_DEFAULT:
        if (MMI_TRUE == srv_mediacache_cache_cell_finished(g_mediacache_cntx_p->large_p))
        {
            new_decode_p = srv_mediacache_link_pingpang_check(search_list_p,MMI_FALSE,srv_mediacache_cache_db_cell_is_unfinished, NULL);
            if (NULL != new_decode_p)
            {
                new_decode_p->state = SRV_MEDIACACHE_CACHE_STATE_EMPTY;
            }
            return new_decode_p;
        }
        else
        {
            new_decode_p = search_list_p;
            if (MMI_TRUE == srv_mediacache_cache_db_cell_is_unfinished(new_decode_p, NULL))
            {
                return new_decode_p;
            }
            if (NULL != search_list_p)
            {
                new_decode_p = search_list_p->next;
                if (MMI_TRUE == srv_mediacache_cache_db_cell_is_unfinished(new_decode_p, NULL))
                {
                    return new_decode_p;
                }
                new_decode_p = search_list_p->prev;
                if (MMI_TRUE == srv_mediacache_cache_db_cell_is_unfinished(new_decode_p, NULL))
                {
                    return new_decode_p;
                }
            }
        }
        break;
    case SRV_MEDIACACHE_CACHE_METHOD_M1:
        new_decode_p = srv_mediacache_link_line_check(search_list_p,srv_mediacache_cache_db_cell_is_unfinished, NULL);
        if (NULL != new_decode_p)
        {
            new_decode_p->state = SRV_MEDIACACHE_CACHE_STATE_EMPTY;
            if (NULL != search_list_p)
            {
                if (new_decode_p->file_index < search_list_p->file_index)
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_RESET_CELL_LINE, __LINE__);
                    srv_mediacache_cache_reset_cell(new_decode_p,MMI_FALSE);
                    new_decode_p = NULL;
                }
            }
        }
        return new_decode_p;
    }
#endif
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_decode_schedule
 * DESCRIPTION
 *  start schedule the pre buffer process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_mediacache_cell_struct *srv_mediacache_decode_schedule_find_decode_cell(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *new_decode_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_DECODE_SCHEDULE);
    if (g_mediacache_cntx_p->state != SRV_MEDIACACHE_STATE_RUNNING)
    {
        return NULL;
    } 
    
    new_decode_p = srv_mediacache_decode_check_large();
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_DECODE_SCHEDULE_CHECK_LARGE,new_decode_p);
    if (new_decode_p == NULL)
    {
        new_decode_p = srv_mediacache_decode_check_curr();
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_DECODE_SCHEDULE_CHECK_CURR,new_decode_p);
    }
    if (new_decode_p == NULL)
    {
        new_decode_p = srv_mediacache_decode_check_l1();
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_DECODE_SCHEDULE_CHECK_LX, 1, new_decode_p);
    }
    if (new_decode_p == NULL)
    {
        new_decode_p = srv_mediacache_decode_check_l2();
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_DECODE_SCHEDULE_CHECK_LX, 2, new_decode_p);
    }
    if (new_decode_p != NULL)
    {
        kal_print_string_trace(MOD_MMI_MEDIA_APP, MMI_MEDIA_TRC_G2_APP, 
            "[SRVMC]cache index=%d type=%d",new_decode_p->file_index, new_decode_p->type);
    }
    return new_decode_p;
}

void srv_mediacache_db_save_schedule(void)
{
    if (NULL == g_mediacache_cntx_p)
    {
        return;
    }
    g_mediacache_cntx_p->db_save_is_timer_start = MMI_FALSE;
    g_mediacache_cntx_p->db_save_count++;
#ifdef __SRV_MEDIACACHE_PUT_HIGH_PRIORITY__
    srv_mediacache_save_to_db_schedule();
#else
    if (g_mediacache_cntx_p->db_save_count > 10 && g_mediacache_cntx_p->db_save_decode_count > 3 ||
        g_mediacache_cntx_p->db_save_count > 80 && g_mediacache_cntx_p->db_save_decode_count > 1 ||
        g_mediacache_cntx_p->db_save_count > 100)
    {
        srv_mediacache_save_to_db_schedule();
    }
    else
    {
        gui_start_timer(SRV_MEDIACACHE_SAVE2DB_TIME_GAP_NORMAL, srv_mediacache_db_save_schedule);
        g_mediacache_cntx_p->db_save_is_timer_start = MMI_TRUE;
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_decode_schedule
 * DESCRIPTION
 *  start schedule the pre buffer process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mediacache_decode_schedule(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *new_decode_p;
    srv_mediacache_cell_struct *cache_cell;
    S32 index;
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
    S32 err_code;
#endif
#if 0 //defined(__SRV_MEDIACACHE_DB_SUPPORT__)
/* under construction !*/
#endif
    MMI_BOOL    is_need_loop;
    MMI_BOOL    is_start_ok;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_DECODE_SCHEDULE);
    SRV_MEDIACACHE_CACHE_PRINT_DBGTRACE();
    if (NULL == g_mediacache_cntx_p)
    {
        return;
    }
    g_mediacache_cntx_p->is_schedule_timer_started = MMI_FALSE;
    if (g_mediacache_cntx_p->state != SRV_MEDIACACHE_STATE_RUNNING)
    {
        srv_mediacache_check_and_start_decode();
        return;
    }
#if 0 //defined(__SRV_MEDIACACHE_DB_SUPPORT__)
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

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_FIND_DECODE_CELL);

    g_mediacache_cntx_p->db_failed_query_count = 0;
    is_need_loop = MMI_TRUE;
    while(MMI_TRUE == is_need_loop)
    {
        is_need_loop = MMI_FALSE;
        new_decode_p = srv_mediacache_decode_schedule_find_decode_cell();
        if (new_decode_p != NULL)
        {
            switch (new_decode_p->type)
            {
            case SRV_MEDIACACHE_CACHE_TYPE_LARGE:
                index = new_decode_p->file_index;
                cache_cell = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
                if (NULL != cache_cell && MMI_TRUE == srv_mediacache_cache_cell_finished(cache_cell))
                {
                    if (cache_cell->err_code < 0)
                    {
                        srv_mediacache_cache_cpy_cb_and_buffer(new_decode_p,cache_cell);
                        new_decode_p = srv_mediacache_decode_schedule_find_decode_cell();
                        is_need_loop = MMI_TRUE;
                    }
                }
                else
                {
                    cache_cell = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level2_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
                    if (NULL != cache_cell && MMI_TRUE == srv_mediacache_cache_cell_finished(cache_cell))
                    {
                        if (cache_cell->err_code < 0)
                        {
                            srv_mediacache_cache_cpy_cb_and_buffer(new_decode_p,cache_cell);
                            new_decode_p = srv_mediacache_decode_schedule_find_decode_cell();
                            is_need_loop = MMI_TRUE;
                        }
                    }
                }
                break;
            case SRV_MEDIACACHE_CACHE_TYPE_L1:
                index = new_decode_p->file_index;
                cache_cell = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level2_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
                if (NULL != cache_cell && MMI_TRUE == srv_mediacache_cache_cell_finished(cache_cell))
                {
                    if (cache_cell->err_code < 0)
                    {
                        srv_mediacache_cache_cpy_cb_and_buffer(new_decode_p,cache_cell);
                        new_decode_p = srv_mediacache_decode_schedule_find_decode_cell();
                        is_need_loop = MMI_TRUE;
                    }
                }
                break;
            default:
                break;
            }
        }
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_FIND_DECODE_CELL);

#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
    if (new_decode_p == NULL)
    {
        /*
         * here means all cell is decode done. 
         * so we create meta handle for some cell if he miss the meta create
         */
       srv_mediacache_create_meta_handle_for_rest_cell((srv_handle)g_mediacache_cntx_p);
    }
#endif

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_DECODE_BY_DB);

    if (new_decode_p != NULL && g_mediacache_cntx_p->decoding_p != new_decode_p)
    {
        g_mediacache_cntx_p->is_can_saving = MMI_FALSE;
        if (NULL != g_mediacache_cntx_p->decoding_p || g_mediacache_cntx_p->image_hdl_decoding != 0)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_CANCEL_DECODE_CELL_AT_D, __LINE__);
            g_mediacache_cntx_p->engine.cancel_decode_cell(g_mediacache_cntx_p->image_hdl_decoding);
            g_mediacache_cntx_p->image_hdl_decoding = 0;
            g_mediacache_cntx_p->decoding_p = NULL;
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_DECODING_P_IS_NULL_D, __LINE__);
        }
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
        if (new_decode_p->state_4_db == SRV_MEDIACACHE_CACHE_STATE_DECODE_DB_NEED_CHECK)
        {
            if (g_mediacache_cntx_p->searching_p != new_decode_p)
            {
                err_code = srv_mediacache_decode_by_database(new_decode_p, MMI_FALSE);
                if (err_code < 0)
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_IDX_DBSTATE_CHANGE, 
                        new_decode_p->file_index, 
                        new_decode_p->state_4_db,
                        SRV_MEDIACACHE_CACHE_STATE_DECODE_DB_SKIP,
                        __LINE__);
                    new_decode_p->state_4_db = SRV_MEDIACACHE_CACHE_STATE_DECODE_DB_SKIP;
                    g_mediacache_cntx_p->searching_p = NULL;
                }
                else
                {
                    kal_print_string_trace(
                        MOD_MMI_MEDIA_APP, 
                        MMI_MEDIA_TRC_G2_APP, 
                        "[srvmc]return from L%d",__LINE__);
                    return;
                }
            }
            else
            {
                kal_print_string_trace(
                    MOD_MMI_MEDIA_APP, 
                    MMI_MEDIA_TRC_G2_APP, 
                    "[srvmc]return from L%d",__LINE__);
                return;
            }
        }
#endif
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_DECODE_BY_DB);

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_DECODE_CELL_USING_GDI);

        is_start_ok = g_mediacache_cntx_p->engine.decode_cell(
            (U32*)&g_mediacache_cntx_p->image_hdl_decoding, 
            new_decode_p, 
            srv_mediacache_decode_nb_decode_callback, 
            g_mediacache_cntx_p);

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_DECODE_CELL_USING_GDI);

        if (is_start_ok != MMI_TRUE)
        {
            srv_mediacache_check_and_start_decode();
        }
        else
        {
            g_mediacache_cntx_p->decoding_p = new_decode_p;
        }
    }
    else if(new_decode_p == NULL)
    {
        /* here we should create image handle for background case will not create image handle for current image*/
    #ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
        srv_mediacache_create_image_handle_if_needed(g_mediacache_cntx_p->level1_curr_p);
    #endif
        g_mediacache_cntx_p->is_can_saving = MMI_TRUE;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_DECODE_SCHEDULE_FINISHED);
    }
    if (MMI_FALSE == g_mediacache_cntx_p->db_save_is_timer_start)
    {
        gui_start_timer(SRV_MEDIACACHE_SAVE2DB_TIME_GAP_NORMAL, srv_mediacache_db_save_schedule);
        g_mediacache_cntx_p->db_save_is_timer_start = MMI_TRUE;
    }
    gui_cancel_timer(srv_mediacache_save_to_db_schedule);  
    if (NULL != g_mediacache_cntx_p->events_callback &&
        g_mediacache_cntx_p->events_getfilename_err.error_code < 0)
    {
        g_mediacache_cntx_p->events_callback(
            SRV_MEDIACACHE_EVENTS_GET_FILENAME_ERR,
            &g_mediacache_cntx_p->events_getfilename_err,
            g_mediacache_cntx_p->events_callback_user_data);
        
        if (NULL != g_mediacache_cntx_p)
        {
            g_mediacache_cntx_p->events_getfilename_err.error_code = 0;
        }
    }
}


#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_decode_schedule
 * DESCRIPTION
 *  start schedule the pre buffer process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mediacache_save_to_db_callback(S32 err, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *cell_found = NULL;
    S32 saved_index = (S32)user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SRVMC]srv_mediacache_save_to_db_callback data=%d @%d", user_data, __LINE__);
    
    switch(g_mediacache_cntx_p->db_store_cache_group)
    {
    case SRV_MEDIACACHE_CACHE_TYPE_L1:
        cell_found = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p, MMI_FALSE, srv_mediacache_is_index_match, &saved_index);
        break;
    case SRV_MEDIACACHE_CACHE_TYPE_L2:
        cell_found = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level2_curr_p, MMI_FALSE, srv_mediacache_is_index_match, &saved_index);
        break;
    }
    
    if (!cell_found)
    {
        //here means the cell is out of your view
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_WARING_WHEN_CALLBACK_THE_CELL_IS_NO_LONG_USED_INDEX_IS_D, saved_index);
        return ;
    }

    if (err >= 0)
    {
        cell_found->is_saved = MMI_TRUE;
    }
    else
    {
        //although can not save to DB, we still go to next one
        cell_found->is_saved = MMI_TRUE;
    }

    gui_start_timer(SRV_MEDIACACHE_SAVE2DB_TIME_GAP_NORMAL, srv_mediacache_save_to_db_schedule);  
}
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_decode_schedule
 * DESCRIPTION
 *  start schedule the pre buffer process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mediacache_save_to_db_schedule(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
    srv_mediacache_cell_struct *cell_p = NULL;
    srv_mediacache_cell_struct *cell_grp_p = NULL;
    srv_mediacache_cell_struct *cell_meta_p = NULL;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mediacache_cntx_p)
    {
        return;
    }
    if (g_mediacache_cntx_p->state != SRV_MEDIACACHE_STATE_RUNNING)
    {
        return;
    }
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
    /*if (MMI_FALSE == g_mediacache_cntx_p->is_can_saving)
    {
        return;
    }*/
    ivd_ivsrv_db_enable_get_cancel_put(&g_mediacache_cntx_p->db_handle,MMI_FALSE);
    if (g_mediacache_cntx_p->is_db_start_ok != MMI_TRUE ||
        g_mediacache_cntx_p->db_handle.io_buf.i_state != MMI_IVD_IO_BUF_STATE_IDLE)
    {
        return;
    }
    cell_grp_p = g_mediacache_cntx_p->level2_curr_p;
    switch(g_mediacache_cntx_p->decode_method)
    {
    case SRV_MEDIACACHE_CACHE_METHOD_DEFAULT:
        if (g_mediacache_cntx_p->db_store_cache_group == SRV_MEDIACACHE_CACHE_TYPE_L2)
        {
            cell_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level2_curr_p,MMI_FALSE,srv_mediacache_cache_cell_is_not_saved, NULL);
        }
        else if (g_mediacache_cntx_p->db_store_cache_group == SRV_MEDIACACHE_CACHE_TYPE_L1)
        {
            cell_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p,MMI_FALSE,srv_mediacache_cache_cell_is_not_saved, NULL);
            cell_grp_p = g_mediacache_cntx_p->level1_curr_p;

        #ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
            if (!cell_p) //if all image saved, begin to save meta
            {
                if (g_mediacache_cntx_p->is_using_meta && g_mediacache_cntx_p->is_meta_using_db)
                {
                    if (g_mediacache_cntx_p->is_using_ies)
                    {
                        cell_meta_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p,MMI_FALSE,srv_mediacache_cache_meta_is_not_saved, NULL);
                        cell_grp_p = g_mediacache_cntx_p->level1_curr_p;
                    }
                }
            }
        #endif
        }
        break;
    case SRV_MEDIACACHE_CACHE_METHOD_M1:
        if(MMI_TRUE == srv_mediacache_cache_cell_is_not_saved(g_mediacache_cntx_p->level2_curr_p, NULL))
        {
            cell_p = g_mediacache_cntx_p->level2_curr_p;
        }
        break;
    default:
        break;
    }

    
    if (NULL != cell_p)
    {
        srv_mediacache_db_put_img(cell_p, srv_mediacache_save_to_db_callback, (void*)cell_p->file_index);
        gui_start_timer(SRV_MEDIACACHE_SAVE2DB_TIME_GAP_NORMAL, srv_mediacache_save_to_db_schedule);  
    }
    else if (NULL != cell_meta_p)
    {
    #ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
        srv_mediacache_db_put_meta(cell_meta_p, srv_mediacache_meta_save_to_db_callback, cell_meta_p);
    #endif
        gui_start_timer(SRV_MEDIACACHE_SAVE2DB_TIME_GAP_NORMAL, srv_mediacache_save_to_db_schedule);  
    }
    else
    {
        cell_p = srv_mediacache_link_pingpang_check(cell_grp_p,MMI_FALSE,srv_mediacache_cache_cell_is_unfinished, NULL);
        if (g_mediacache_cntx_p->is_clear_done == MMI_FALSE && NULL == cell_p)
        {
            g_mediacache_cntx_p->is_clear_done = MMI_TRUE;
            srv_mediacache_db_clear_old_record(SRV_MEDIACACHE_DB_IMG_EXPIRE_DAYS);
        }
    }
#endif
}

#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__

static void srv_mediacache_copy_the_buffer_if_needed(PU8 source, PU8 dest, S32 length)
{
    memcpy(dest, source, length);
}

static  void _srv_mediacache_release_image_handle_if_needed(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_SRV_MEDIACACHE_RELEASE_IMAGE_HANDLE_IF_NEEDED);
    if (g_mediacache_cntx_p->decoding_p == NULL)
    {
        MMI_ASSERT(0);
    }

    if (g_mediacache_cntx_p->level1_curr_p != NULL)
    {
        if (g_mediacache_cntx_p->decoding_p->file_index == g_mediacache_cntx_p->level1_curr_p->file_index)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_SRV_MEDIACACHE_RELEASE_IMAGE_HANDLE_IF_NEEDED);
            return;
        }
    }

    if (g_mediacache_cntx_p->level2_curr_p != NULL)
    {
        if (g_mediacache_cntx_p->decoding_p->file_index == g_mediacache_cntx_p->level2_curr_p->file_index)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_SRV_MEDIACACHE_RELEASE_IMAGE_HANDLE_IF_NEEDED);
            return;
        }
    }

    //need release image handle for next one use
    MMI_ASSERT(g_mediacache_cntx_p->decoding_p->ies_image_handle != NULL);
    MMI_ASSERT(g_mediacache_cntx_p->decoding_p->ies_preview_handle == NULL);

    if (g_mediacache_cntx_p->decoding_p->ies_image_handle)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_SRV_IES_IMAGE_DESTROY);
        srv_ies_image_destroy(g_mediacache_cntx_p->decoding_p->ies_image_handle);
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_SRV_IES_IMAGE_DESTROY);
        g_mediacache_cntx_p->decoding_p->ies_image_handle = NULL;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_SRV_MEDIACACHE_RELEASE_IMAGE_HANDLE_IF_NEEDED);
}


static void _srv_mediacache_engine_ies_decode_cb(srv_ies_result result, void *pUserData)
{
    // TODO: translate IES result to GDI result
    g_mediacache_cntx_p->ies_decoding_handle = NULL;

    if (g_mediacache_cntx_p->decoding_p)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_IES_IES_DECODE_CALLBACK_CELL_INDEX_IS_D_RESULT_IS_D,
            g_mediacache_cntx_p->decoding_p->file_index, result);
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_IESXX_IES_DECODE_CALLBACK_CELL_INDEX_IS_D_RESULT_IS_D,
            -1, result);
    }
    
    /* if the decoding cell is not equals to the current, we will delate the curent image handle */
    _srv_mediacache_release_image_handle_if_needed();
    srv_mediacache_copy_the_buffer_if_needed(g_mediacache_cntx_p->ies_render_buffer, g_mediacache_cntx_p->decoding_p->buffer, 
        g_mediacache_cntx_p->decoding_p->image_width * g_mediacache_cntx_p->decoding_p->image_height * 2);
    //currently we assume it is 16 bit.
#ifdef __SRV_MEDIACACHE_INTERNAL_TEST__
    //srv_mediacache_save_cell_img_to_file(g_mediacache_cntx_p->decoding_p);
#endif
    
#ifdef __SRV_MEDIACACHE_INTERNAL_TEST__
    if (g_mediacache_cntx_p->decoding_p)
    {
        U8 *verify_buf_ptr = g_mediacache_cntx_p->decoding_p->buffer;
        
        U8* m_data_p = verify_buf_ptr;
        U8* m_data_end_p = verify_buf_ptr + g_mediacache_cntx_p->decoding_p->image_width * 24 * 2;
        S32 m_pitch = g_mediacache_cntx_p->decoding_p->image_width * 2;
        S32 m_length = 24 * 2;

        while (m_data_p<m_data_end_p)
        {
            memset(m_data_p,0xCC,m_length);
            m_data_p += m_pitch;
        }

        if (srv_ies_is_image_handle_has_meta(g_mediacache_cntx_p->decoding_p->ies_image_handle))
        {
            m_data_end_p += g_mediacache_cntx_p->decoding_p->image_width * 24 * 2; 

            while (m_data_p<m_data_end_p)
            {
                memset(m_data_p,0xEE,m_length);
                m_data_p += m_pitch;
            }
        }
    }
#endif

    srv_mediacache_decode_nb_decode_callback((S32)result, SRV_MEDIACACHE_ERR_GROUP_GDI, g_mediacache_cntx_p);   
}
#endif

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
static void srv_mediacache_engine_gdi_decode_done_cb(GDI_RESULT result,gdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mediacache_cntx_p == NULL)
    {
        return;
    }

    if (g_mediacache_cntx_p->decoding_p)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_GDI_IES_DECODE_CALLBACK_CELL_INDEX_IS_D, g_mediacache_cntx_p->decoding_p->file_index);
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_GDI_WHAT_HAPPENED_SOMETHING_IS_WRONG);
    }
    if (g_mediacache_engine_cntx.image_hdl_decoding != handle)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_DECODE_CB_NOT_MY);
        return;
    }
    srv_mediacache_decode_nb_decode_callback((S32)result, SRV_MEDIACACHE_ERR_GROUP_GDI, g_mediacache_cntx_p);
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
MMI_BOOL srv_mediacache_engine_gdi_nb_decode_cancel(U32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
    if(g_mediacache_cntx_p->ies_decoding_handle)
    {
        if (g_mediacache_cntx_p->ies_decoding_handle)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_IES_IES_CANCEL_RENDER_CELL_INDEX_IS_D,
                g_mediacache_cntx_p->decoding_p->file_index);
            srv_ies_job_cancel(g_mediacache_cntx_p->ies_decoding_handle);
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_IES_IES_CANCEL_RENDER_END);
        }
        g_mediacache_cntx_p->ies_decoding_handle = NULL;
        g_mediacache_engine_cntx.image_hdl_decoding = NULL;
            
        if (g_mediacache_cntx_p->decoding_p)
        {
            if (g_mediacache_cntx_p->decoding_p->ies_preview_handle)
            {
                srv_ies_preview_destroy(g_mediacache_cntx_p->decoding_p->ies_preview_handle);
                g_mediacache_cntx_p->decoding_p->ies_preview_handle = NULL;
                g_mediacache_cntx_p->decoding_p->ies_preview_gdi_layer = NULL;
            } 

            if (g_mediacache_cntx_p->decoding_p->ies_image_handle)
            {
                srv_ies_image_destroy(g_mediacache_cntx_p->decoding_p->ies_image_handle);
                g_mediacache_cntx_p->decoding_p->ies_image_handle = NULL;
            } 
        }
    }

    if (g_mediacache_cntx_p->ies_meta_p)
    {
        if (g_mediacache_cntx_p->ies_meta_p->ies_meta_job_handle)
        {
            srv_ies_job_cancel(g_mediacache_cntx_p->ies_meta_p->ies_meta_job_handle);
            g_mediacache_cntx_p->ies_meta_p->ies_meta_job_handle = 0;
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_META_SET_META_JOB_HANDLE_TO_NULL_FILE_INDEX_D_D, g_mediacache_cntx_p->ies_meta_p->file_index, __LINE__);
        }  
        g_mediacache_cntx_p->ies_meta_p->ies_meta_state = SRV_MEDIACACHE_META_STATE_IDLE;
        g_mediacache_cntx_p->ies_meta_p = NULL;
    }
#endif

    if (handle == g_mediacache_cntx_p->large_image_dec_hdlr &&
        0 != g_mediacache_cntx_p->large_image_dec_hdlr)
    {
        kal_print_string_trace(
            MOD_MMI_MEDIA_APP, 
            MMI_MEDIA_TRC_G2_APP, 
            "[srvmc]cancel decode large hand=%d",g_mediacache_cntx_p->large_image_dec_hdlr);
    }

    if (g_mediacache_engine_cntx.image_hdl_decoding)
    {
        if (MMI_TRUE == g_mediacache_engine_cntx.is_use_gdi)
        {
            SRV_MEDIACACHE_START_MEASURE("GCN");
            gdi_image_nb_stop((gdi_handle)g_mediacache_engine_cntx.image_hdl_decoding);
            SRV_MEDIACACHE_STOP_MEASURE("GCN");
        }
        else
        {
            SRV_MEDIACACHE_START_MEASURE("GCD");
            gdi_imgdec_nb_stop((gdi_handle)g_mediacache_engine_cntx.image_hdl_decoding);
            SRV_MEDIACACHE_STOP_MEASURE("GCD");
        }
    }

    srv_mediacache_check_and_start_decode();  
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_CANCEL_DECODE, handle);
    return MMI_TRUE;
}

void srv_mediacache_engine_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mediacache_engine_cntx.is_to_buffer = MMI_FALSE;
    g_mediacache_engine_cntx.is_lock_level2_only = MMI_FALSE;
    g_mediacache_engine_cntx.is_use_gdi = MMI_FALSE;
}

GDI_RESULT srv_mediacache_engine_gdi_blocking_decode(srv_mediacache_cell_struct *cell_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT             result;    
    S32 img_width, img_height;
    WCHAR*  filename_p;
    srv_mediacache_pre_decode_enum    is_user_cancel = SRV_MEDIACACHE_PRE_DECODE_CONTINUE;
    srv_mediacache_rect_struct img_org, img_resized;
    CHAR *error_str;
    U32 buf_length = 0;
    S32 x,y,w,h, layer_w,layer_h;
    MMI_BOOL    is_fmgr_pass;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == cell_p)
    {
        return MMI_FALSE;
    }
    SRV_MEDIACACHE_START_MEASURE("BLD");
    result = g_mediacache_cntx_p->engine.get_file_name(
        cell_p->file_index, 
        (U16*)g_mediacache_cntx_p->config.filename, 
        SRV_FMGR_PATH_BUFFER_SIZE,
        NULL);
    if (result < 0)
    {
        g_mediacache_cntx_p->decoding_p->err_code = result;
        g_mediacache_cntx_p->decoding_p->err_group= SRV_MEDIACACHE_ERR_GROUP_APP;
        g_mediacache_cntx_p->decoding_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_GET_NAME_FAILED,result, __LINE__);
        SRV_MEDIACACHE_STOP_MEASURE("BLD");
        return result;
    }
    filename_p = (WCHAR*)g_mediacache_cntx_p->config.filename;
    if (NULL == cell_p)
    {
        SRV_MEDIACACHE_STOP_MEASURE("BLD");
        return SRV_MEDIACACHE_ERR_UNKNOW;
    }
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_CANCEL_DECODE_CELL_AT_D, __LINE__);
    g_mediacache_cntx_p->engine.cancel_decode_cell(g_mediacache_cntx_p->image_hdl_decoding);
    g_mediacache_cntx_p->image_hdl_decoding = 0;
    g_mediacache_cntx_p->decoding_p = NULL;
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_DECODING_P_IS_NULL_D, __LINE__);
    
    srv_mediacache_decode_check_and_free_layer();
    g_mediacache_cntx_p->decoding_p = cell_p;
    buf_length = srv_mediacache_cache_get_img_size_by_type(cell_p->type);
    is_fmgr_pass = srv_mediacache_file_limit_check(filename_p , &error_str);
    if (is_fmgr_pass == MMI_FALSE)
    {
        img_width = -1;
        img_height = -1;
        result = 0;
    }
    else
    {
        if (cell_p->image_width == -1 && cell_p->image_height == -1)
        {
            SRV_MEDIACACHE_START_MEASURE("FU3");
            result = gdi_imgdec_get_dimension_file((CHAR*)filename_p, &img_width, &img_height);
            if (result < 0)
            {
                result = gdi_image_get_dimension_file((CHAR*)filename_p, &img_width, &img_height);
            }
            SRV_MEDIACACHE_STOP_MEASURE("FU3");
        }
        else
        {
            img_width = cell_p->org_image_width;
            img_height = cell_p->org_image_height;
            result = 0;
        }
    }
    if (img_width <= 0 || img_height <= 0 || result < 0 || img_width > SRV_MEDIACACHE_DECODE_MAX_W_H || img_height > SRV_MEDIACACHE_DECODE_MAX_W_H)
    {        
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_NOT_SUPPORT,img_width, img_height, result);
        g_mediacache_cntx_p->decoding_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
        if (result < 0)
        {
            g_mediacache_cntx_p->decoding_p->err_code = result;
            g_mediacache_cntx_p->decoding_p->err_group= SRV_MEDIACACHE_ERR_GROUP_GDI;
        }
        else
        {
            g_mediacache_cntx_p->decoding_p->err_code = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
            g_mediacache_cntx_p->decoding_p->err_group= SRV_MEDIACACHE_ERR_GROUP_MEDIACACHE;
        }
        g_mediacache_cntx_p->decoding_p = NULL;
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_DECODING_P_IS_NULL_D, __LINE__);
    }
    else
    {
        is_user_cancel = SRV_MEDIACACHE_PRE_DECODE_CONTINUE;
        if (g_mediacache_cntx_p->pre_decode_cb != NULL)
        {
            is_user_cancel = g_mediacache_cntx_p->pre_decode_cb(filename_p, NULL);
        }
        if (is_user_cancel != SRV_MEDIACACHE_PRE_DECODE_CANCEL_THIS)
        {
            if (g_mediacache_cntx_p->decoding_p->image_type == GDI_IMAGE_TYPE_INVALID)
            {
                SRV_MEDIACACHE_START_MEASURE("GDG");
                g_mediacache_cntx_p->decoding_p->image_type = gdi_image_get_type_from_file((CHAR*)filename_p);
                SRV_MEDIACACHE_STOP_MEASURE("GDG");
            }
            srv_mediacache_cache_fill_cell_by_img(img_width, img_height, g_mediacache_cntx_p->decoding_p);
            if (g_mediacache_cntx_p->decoding_p->image_width <= 0 || g_mediacache_cntx_p->decoding_p->image_height <= 0)
            {        
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_CALC_W_H_ERR,
                    g_mediacache_cntx_p->decoding_p->image_width, g_mediacache_cntx_p->decoding_p->image_height);
                g_mediacache_cntx_p->decoding_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
                g_mediacache_cntx_p->decoding_p->err_code = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
                g_mediacache_cntx_p->decoding_p->err_group= SRV_MEDIACACHE_ERR_GROUP_MEDIACACHE;
                g_mediacache_cntx_p->decoding_p = NULL;
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_DECODING_P_IS_NULL_D, __LINE__);
            }
            else
            {
                img_org.x = 0;
                img_org.y = 0;
                img_org.width = g_mediacache_cntx_p->decoding_p->org_image_width;
                img_org.height = g_mediacache_cntx_p->decoding_p->org_image_height;
                img_resized.x = 0;
                img_resized.y = 0;
                img_resized.width = g_mediacache_cntx_p->decoding_p->image_width;
                img_resized.height = g_mediacache_cntx_p->decoding_p->image_height;
                if (g_mediacache_engine_cntx.is_to_buffer == MMI_TRUE &&
                    g_mediacache_cntx_p->decoding_p != g_mediacache_cntx_p->large_p)
                {
                    g_mediacache_cntx_p->decoding_p->image_width = g_mediacache_engine_cntx.width;
                    g_mediacache_cntx_p->decoding_p->image_height = g_mediacache_engine_cntx.height;
                }
                layer_w = g_mediacache_cntx_p->decoding_p->image_width;
                layer_h = g_mediacache_cntx_p->decoding_p->image_height;
                g_mediacache_cntx_p->engine.set_clip((U32*)g_mediacache_cntx_p,&layer_w,&layer_h,&img_org,&img_resized,g_mediacache_cntx_p->engine.user_data);
                g_mediacache_cntx_p->decoding_p->image_width = layer_w;
                g_mediacache_cntx_p->decoding_p->image_height = layer_h;
                x = img_resized.x;
                y = img_resized.y;
                w = img_resized.width;
                h = img_resized.height;
                gdi_layer_create_cf_using_outside_memory(
                    g_mediacache_cntx_p->color_format,
                    0,
                    0,
                    layer_w,
                    layer_h,
                    &g_mediacache_cntx_p->layer,
                    g_mediacache_cntx_p->decoding_p->buffer,
                    buf_length);
                gdi_layer_push_and_set_active(g_mediacache_cntx_p->layer);
                gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
                gdi_push_and_set_alpha_blending_source_layer(g_mediacache_cntx_p->layer);
                srv_mediacache_decode_pre_clear_bg_cb(0, 0);
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_SRV_MEDIACACHE_INFO_START_BLOCKING_DECODE);
                SRV_MEDIACACHE_START_MEASURE("BDD");
                g_mediacache_cntx_p->decoding_p->err_code = gdi_image_draw_resized_file(x, y, w, h, filename_p);
                SRV_MEDIACACHE_START_MEASURE("BDD");
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_SRV_MEDIACACHE_CC_DECODE2LAYER,layer_w,layer_h,x,y,w,h,g_mediacache_cntx_p->decoding_p->file_index);
                gdi_pop_and_restore_alpha_blending_source_layer();
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
                            MMI_TRC_SRV_MEDIACACHE_DECODE_SCHEDULE_START_IMG,
                            g_mediacache_cntx_p->decoding_p->image_width, 
                            g_mediacache_cntx_p->decoding_p->image_height,
                            g_mediacache_cntx_p->decoding_p->file_index);
                gdi_layer_pop_and_restore_active();
            }
        }
        else
        {
            g_mediacache_cntx_p->decoding_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
            g_mediacache_cntx_p->decoding_p->err_code = SRV_MEDIACACHE_ERR_USER_CANCEL_DECODE;
            g_mediacache_cntx_p->decoding_p->err_group= SRV_MEDIACACHE_ERR_GROUP_MEDIACACHE;
            g_mediacache_cntx_p->decoding_p = NULL;
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_DECODING_P_IS_NULL_D, __LINE__);
        }
    }
    SRV_MEDIACACHE_STOP_MEASURE("BLD");
    if (g_mediacache_cntx_p->state == SRV_MEDIACACHE_STATE_RUNNING)
    {
        srv_mediacache_check_and_start_decode();  
    }
    return cell_p->err_code;
}


//e add by scalado vincent
MMI_BOOL srv_mediacache_engine_gdi_nb_decode(U32 *handle, srv_mediacache_cell_struct *cell_p, srv_mediacache_nb_decode_callback done_callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_pre_decode_enum    is_user_cancel = SRV_MEDIACACHE_PRE_DECODE_CONTINUE;
    S32 img_width, img_height;
    WCHAR*  filename_p;
    CHAR *error_str;
    PU8 img = NULL;
    srv_mediacache_rect_struct img_org, img_resized;
    U32 buf_length = 0;
    S32 x, y, w, h, layer_w,layer_h;
    GDI_RESULT  result;    
    U16 res_id = 0;
    MMI_BOOL    is_fmgr_pass;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_GDI_NB_DECODE_INTERNAL);

    if (NULL == cell_p)
    {
        return MMI_FALSE;
    }
    SRV_MEDIACACHE_START_MEASURE("DCC");
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_CANCEL_DECODE_CELL_AT_D, __LINE__);
    g_mediacache_cntx_p->engine.cancel_decode_cell(g_mediacache_cntx_p->image_hdl_decoding);
    g_mediacache_cntx_p->image_hdl_decoding = 0;
    g_mediacache_cntx_p->decoding_p = NULL;
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_DECODING_P_IS_NULL_D, __LINE__);
    SRV_MEDIACACHE_STOP_MEASURE("DCC");
    srv_mediacache_decode_check_and_free_layer();
    g_mediacache_cntx_p->decoding_p = cell_p;
#ifdef __SRV_MEDIACACHE_DEBUG_MEASURE__
    kal_get_time(&cell_p->decode_ticks);
#endif
    SRV_MEDIACACHE_START_MEASURE("DCI");
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_GET_FILE_NAME);

    result = g_mediacache_cntx_p->engine.get_file_name(
        cell_p->file_index, 
        (U16*)g_mediacache_cntx_p->config.filename, 
        SRV_FMGR_PATH_BUFFER_SIZE,
        NULL);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_GET_FILE_NAME);
    if (result < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_GET_NAME_FAILED,result, __LINE__);
        if (SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY != result && SRV_FMGR_FILELIST_ERROR_BUSY != result)
        {
            g_mediacache_cntx_p->decoding_p->err_code = result;
            g_mediacache_cntx_p->decoding_p->err_group= SRV_MEDIACACHE_ERR_GROUP_APP;
            g_mediacache_cntx_p->decoding_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
            g_mediacache_cntx_p->decoding_p->is_saved = MMI_TRUE;
            srv_mediacache_check_cb_and_call(g_mediacache_cntx_p->decoding_p, g_mediacache_cntx_p->cb_file_idx, MMI_TRUE);
        }
        SRV_MEDIACACHE_STOP_MEASURE("DCI");
        g_mediacache_cntx_p->decoding_p = NULL;
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_DECODING_P_IS_NULL_D, __LINE__);
        return MMI_FALSE;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_ERROR_CHECK);

    filename_p = (WCHAR*)g_mediacache_cntx_p->config.filename;
    buf_length = srv_mediacache_cache_get_img_size_by_type(cell_p->type);
    SRV_MEDIACACHE_START_MEASURE("FUC");
    if (SRV_MEDIACACHE_WORKMODE_IDARRAY != g_mediacache_cntx_p->work_mode)
    {
        is_fmgr_pass = srv_mediacache_file_limit_check(filename_p , &error_str);   
    }
    else
    {
        res_id = app_ucs2_atoi((kal_int8 *)&filename_p[2]);
        img = (PU8) GetImage(res_id);
        is_fmgr_pass = MMI_TRUE;
    }
    SRV_MEDIACACHE_STOP_MEASURE("FUC");
    if (is_fmgr_pass == MMI_FALSE)
    {
        img_width = -1;
        img_height = -1;
        result = 0;
    }
    else if (SRV_MEDIACACHE_WORKMODE_IDARRAY == g_mediacache_cntx_p->work_mode)
    {
        if (cell_p->image_width == -1 && cell_p->image_height == -1)
        {
            SRV_MEDIACACHE_START_MEASURE("FU3");
            result = gdi_imgdec_get_dimension(img, &img_width, &img_height);
            if (result < 0)
            {
                result = gdi_image_get_dimension(img, &img_width, &img_height);
            }
            SRV_MEDIACACHE_STOP_MEASURE("FU3");
        }
        else
        {
            img_width = cell_p->org_image_width;
            img_height = cell_p->org_image_height;
            result = 0;
        }
    }
    else
    {
        if (cell_p->image_width == -1 && cell_p->image_height == -1)
        {
            SRV_MEDIACACHE_START_MEASURE("FU3");
            result = gdi_imgdec_get_dimension_file((CHAR*)filename_p, &img_width, &img_height);
            if (result < 0)
            {
                result = gdi_image_get_dimension_file((CHAR*)filename_p, &img_width, &img_height);
            }
            SRV_MEDIACACHE_STOP_MEASURE("FU3");
        }
        else
        {
            img_width = cell_p->org_image_width;
            img_height = cell_p->org_image_height;
            result = 0;
        }
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_ERROR_CHECK);

    if (img_width <= 0 || img_height <= 0 || result < 0 || img_width > SRV_MEDIACACHE_DECODE_MAX_W_H || img_height > SRV_MEDIACACHE_DECODE_MAX_W_H)
    {        
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_NOT_SUPPORT,img_width, img_height, result);
        g_mediacache_cntx_p->decoding_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
        if (result < 0)
        {
            g_mediacache_cntx_p->decoding_p->err_code = result;
            g_mediacache_cntx_p->decoding_p->err_group= SRV_MEDIACACHE_ERR_GROUP_GDI;
        }
        else
        {
            g_mediacache_cntx_p->decoding_p->err_code = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
            g_mediacache_cntx_p->decoding_p->err_group= SRV_MEDIACACHE_ERR_GROUP_MEDIACACHE;
        }
        srv_mediacache_check_cb_and_call(g_mediacache_cntx_p->decoding_p, g_mediacache_cntx_p->cb_file_idx, MMI_TRUE);
        g_mediacache_cntx_p->decoding_p = NULL;
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_DECODING_P_IS_NULL_D, __LINE__);
    }
    else
    {
        is_user_cancel = SRV_MEDIACACHE_PRE_DECODE_CONTINUE;
        if (g_mediacache_cntx_p->pre_decode_cb != NULL)
        {
            is_user_cancel = g_mediacache_cntx_p->pre_decode_cb(filename_p, NULL);
        }
    #ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
        if (is_user_cancel == SRV_MEDIACACHE_PRE_DECODE_CANCEL_THIS)
        {
            g_mediacache_cntx_p->decoding_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
            g_mediacache_cntx_p->decoding_p->err_code = SRV_MEDIACACHE_ERR_USER_CANCEL_DECODE;
            g_mediacache_cntx_p->decoding_p->err_group= SRV_MEDIACACHE_ERR_GROUP_MEDIACACHE;
            srv_mediacache_check_cb_and_call(g_mediacache_cntx_p->decoding_p, g_mediacache_cntx_p->cb_file_idx, MMI_TRUE);
            g_mediacache_cntx_p->decoding_p = NULL;
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_DECODING_P_IS_NULL_D, __LINE__);
        }
        else
    #else /* __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__ */
        if (is_user_cancel != SRV_MEDIACACHE_PRE_DECODE_CANCEL_THIS)
    #endif  /* __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__ */
        {
            if (SRV_MEDIACACHE_WORKMODE_IDARRAY == g_mediacache_cntx_p->work_mode)
            {
                g_mediacache_cntx_p->decoding_p->image_type = gdi_image_get_type_from_id(res_id);
            }
            else if (g_mediacache_cntx_p->decoding_p->image_type == GDI_IMAGE_TYPE_INVALID)
            {
                SRV_MEDIACACHE_START_MEASURE("GDG");
                g_mediacache_cntx_p->decoding_p->image_type = gdi_image_get_type_from_file((CHAR*)filename_p);
                SRV_MEDIACACHE_STOP_MEASURE("GDG");
            }
            srv_mediacache_cache_fill_cell_by_img_and_length(buf_length, img_width, img_height, g_mediacache_cntx_p->decoding_p);
            
            if (g_mediacache_cntx_p->decoding_p->image_width <= 0 || g_mediacache_cntx_p->decoding_p->image_height <= 0)
            {        
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_CALC_W_H_ERR,
                    g_mediacache_cntx_p->decoding_p->image_width, g_mediacache_cntx_p->decoding_p->image_height);
                g_mediacache_cntx_p->decoding_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
                g_mediacache_cntx_p->decoding_p->err_code = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
                g_mediacache_cntx_p->decoding_p->err_group= SRV_MEDIACACHE_ERR_GROUP_MEDIACACHE;
                srv_mediacache_check_cb_and_call(g_mediacache_cntx_p->decoding_p, g_mediacache_cntx_p->cb_file_idx, MMI_TRUE);
                g_mediacache_cntx_p->decoding_p = NULL;
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_DECODING_P_IS_NULL_D, __LINE__);
            }
            else
            {
                img_org.x = 0;
                img_org.y = 0;
                img_org.width = g_mediacache_cntx_p->decoding_p->org_image_width;
                img_org.height = g_mediacache_cntx_p->decoding_p->org_image_height;
                img_resized.x = 0;
                img_resized.y = 0;
                img_resized.width = g_mediacache_cntx_p->decoding_p->image_width;
                img_resized.height = g_mediacache_cntx_p->decoding_p->image_height;
                if (g_mediacache_engine_cntx.is_to_buffer == MMI_TRUE &&
                    g_mediacache_cntx_p->decoding_p != g_mediacache_cntx_p->large_p)
                {
                    g_mediacache_cntx_p->decoding_p->image_width = g_mediacache_engine_cntx.width;
                    g_mediacache_cntx_p->decoding_p->image_height = g_mediacache_engine_cntx.height;
                }
                layer_w = g_mediacache_cntx_p->decoding_p->image_width;
                layer_h = g_mediacache_cntx_p->decoding_p->image_height;
                g_mediacache_cntx_p->engine.set_clip((U32*)g_mediacache_cntx_p,&layer_w,&layer_h,&img_org,&img_resized,g_mediacache_cntx_p->engine.user_data);
                g_mediacache_cntx_p->decoding_p->image_width = layer_w;
                g_mediacache_cntx_p->decoding_p->image_height = layer_h;
                x = img_resized.x;
                y = img_resized.y;
                w = img_resized.width;
                h = img_resized.height;

            #ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
                if (_srv_mediacache_decode_need_ies_check(g_mediacache_cntx_p->decoding_p))
                {
                    if(_srv_mediacache_decode_cell_with_ies(g_mediacache_cntx_p->decoding_p, 
                        filename_p,
                        buf_length,
                        layer_w,
                        layer_h,
                        handle))
                    {
                        return MMI_TRUE;
                    }
                    else
                    {
                        S32 err_group = SRV_MEDIACACHE_ERR_GROUP_MEDIACACHE;
                        S32 err_code = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
                        srv_mediacache_get_last_err(handle, &err_group, &err_code);
                        g_mediacache_cntx_p->decoding_p->err_group = err_group;
                        g_mediacache_cntx_p->decoding_p->err_code = err_code;
                        g_mediacache_cntx_p->decoding_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
                        g_mediacache_cntx_p->decoding_p->is_saved = MMI_TRUE;
                        srv_mediacache_check_cb_and_call(g_mediacache_cntx_p->decoding_p, g_mediacache_cntx_p->cb_file_idx, MMI_TRUE);
                        return MMI_FALSE;
                    }
                }
            #endif /* __IES_SUPPORT__ */
                SRV_MEDIACACHE_START_MEASURE("CRL");
                gdi_layer_create_cf_using_outside_memory(
                    g_mediacache_cntx_p->color_format,
                    0,
                    0,
                    layer_w,
                    layer_h,
                    &g_mediacache_cntx_p->layer,
                    g_mediacache_cntx_p->decoding_p->buffer,
                    buf_length);
                gdi_layer_set_source_key_nb_concurrent(g_mediacache_cntx_p->layer, MMI_TRUE, GDI_COLOR_TRANSPARENT);
                SRV_MEDIACACHE_STOP_MEASURE("CRL");
                SRV_MEDIACACHE_START_MEASURE("DC0");
                gdi_push_and_set_alpha_blending_source_layer(g_mediacache_cntx_p->layer);
                #ifdef __SRV_USE_GDI_CODEC_BACKGROUND_DECODE__
                    if (g_mediacache_cntx_p->is_srv_clear_bg == MMI_TRUE)
                    {
                        gdi_layer_clear_nb_concurrent(g_mediacache_cntx_p->layer, g_mediacache_cntx_p->bg_color);
                    }
                    else
                    {
                        gdi_layer_clear_nb_concurrent(g_mediacache_cntx_p->layer, GDI_COLOR_BLACK);
                    }
                    if (SRV_MEDIACACHE_WORKMODE_IDARRAY == g_mediacache_cntx_p->work_mode)
                    {

                        gdi_layer_push_and_set_active(g_mediacache_cntx_p->layer);
                        gdi_nb_set_anim_before_frame_callback(srv_mediacache_decode_pre_clear_bg_cb);
                        gdi_nb_set_done_callback(srv_mediacache_engine_gdi_decode_done_cb);
                        gdi_nb_set_blt(MMI_FALSE, MMI_FALSE);
                        g_mediacache_engine_cntx.image_hdl_decoding = (gdi_handle)gdi_image_nb_draw_resized(
                                                                x,
                                                                y,
                                                                w,
                                                                h,
                                                                img);  
                        g_mediacache_engine_cntx.is_use_gdi = MMI_TRUE;
                        gdi_layer_pop_and_restore_active();
                    }
                    else if (g_mediacache_cntx_p->decoding_p->image_type != GDI_IMAGE_TYPE_SVG_FILE)
                    {
                        g_mediacache_engine_cntx.image_hdl_decoding = gdi_imgdec_nb_draw_resized_file(
                                                            g_mediacache_cntx_p->layer,
                                                            x,
                                                            y,
                                                            w,
                                                            h,
                                                            (U8*)filename_p,
                                                            srv_mediacache_engine_gdi_decode_done_cb);  
                        g_mediacache_engine_cntx.is_use_gdi = MMI_FALSE;
                    }
                    else
                    {

                        gdi_layer_push_and_set_active(g_mediacache_cntx_p->layer);
                        gdi_nb_set_anim_before_frame_callback(srv_mediacache_decode_pre_clear_bg_cb);
                        gdi_nb_set_done_callback(srv_mediacache_engine_gdi_decode_done_cb);
                        gdi_nb_set_blt(MMI_FALSE, MMI_FALSE);
                        g_mediacache_engine_cntx.image_hdl_decoding = (gdi_handle)gdi_image_nb_draw_resized_file(
                                                                x,
                                                                y,
                                                                w,
                                                                h,
                                                                filename_p);  
                        g_mediacache_engine_cntx.is_use_gdi = MMI_TRUE;
                        gdi_layer_pop_and_restore_active();
                    }
                #else
                    gdi_layer_push_and_set_active(g_mediacache_cntx_p->layer);
                    gdi_nb_set_anim_before_frame_callback(srv_mediacache_decode_pre_clear_bg_cb);
                    gdi_nb_set_done_callback(srv_mediacache_engine_gdi_decode_done_cb);
                    gdi_nb_set_blt(MMI_FALSE, MMI_FALSE);
                    g_mediacache_engine_cntx.image_hdl_decoding = gdi_image_nb_draw_resized_file(
                                                            x,
                                                            y,
                                                            w,
                                                            h,
                                                            filename_p);  
                    g_mediacache_engine_cntx.is_use_gdi = MMI_TRUE;
                    gdi_layer_pop_and_restore_active();
                #endif
            #ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
                gdi_pop_and_restore_alpha_blending_source_layer();
            #endif
                *handle =(U32)g_mediacache_engine_cntx.image_hdl_decoding;
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_START_DECODE, *handle);
                if (SRV_MEDIACACHE_CACHE_TYPE_LARGE == g_mediacache_cntx_p->decoding_p->type)
                {
                    g_mediacache_cntx_p->large_image_dec_hdlr = g_mediacache_engine_cntx.image_hdl_decoding;
                    kal_print_string_trace(
                        MOD_MMI_MEDIA_APP, 
                        MMI_MEDIA_TRC_G2_APP, 
                        "[srvmc]start decode large[%d]hand=%d",g_mediacache_cntx_p->decoding_p->file_index,g_mediacache_cntx_p->large_image_dec_hdlr);
                }
                SRV_MEDIACACHE_STOP_MEASURE("DC0");
            #ifndef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
                gdi_pop_and_restore_alpha_blending_source_layer();
            #endif
                g_mediacache_cntx_p->db_save_decode_count++;
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_SRV_MEDIACACHE_CC_DECODE2LAYER,layer_w,layer_h,x,y,w,h,g_mediacache_cntx_p->decoding_p->file_index);
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
                            MMI_TRC_SRV_MEDIACACHE_DECODE_SCHEDULE_START_IMG,
                            g_mediacache_cntx_p->decoding_p->image_width, 
                            g_mediacache_cntx_p->decoding_p->image_height,
                            g_mediacache_cntx_p->decoding_p->file_index);
            }
        }

    #ifndef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
        else
        {
            g_mediacache_cntx_p->decoding_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
            g_mediacache_cntx_p->decoding_p->err_code = SRV_MEDIACACHE_ERR_USER_CANCEL_DECODE;
            g_mediacache_cntx_p->decoding_p->err_group= SRV_MEDIACACHE_ERR_GROUP_MEDIACACHE;
            srv_mediacache_check_cb_and_call(g_mediacache_cntx_p->decoding_p, g_mediacache_cntx_p->cb_file_idx, MMI_TRUE);
            g_mediacache_cntx_p->decoding_p = NULL;
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_DECODING_P_IS_NULL_D, __LINE__);
        }
    #endif /* __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__ */
    }
    SRV_MEDIACACHE_STOP_MEASURE("DCI");
    if (g_mediacache_cntx_p->decoding_p == NULL)
    {
        return MMI_FALSE;
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_DECODE_SCHEDULE_START_NEW, g_mediacache_cntx_p->decoding_p->file_index, g_mediacache_cntx_p->decoding_p->buffer);
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_GDI_NB_DECODE_INTERNAL);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_resize_to_layer
 * DESCRIPTION
 *  resize the cache to layer
 * PARAMETERS
 *  grp1_index  [IN]    index
 *  dest_layer  [IN]    dest layer to draw to
 *  dest_x      [IN]    offset of x according to dest
 *  dest_y      [IN]    offest of y according to dest
 *  zoomfactor  [IN]    zoom factor * 1000
 *  x           [IN]    x after zoom of org image
 *  y           [IN]    y after zoom of org image
 *  width       [IN]    width after zoom of org image
 *  height      [IN]    height after zoom of org image
 *  app_cb      [IN]    call back function of app
 * RETURNS
 *  error code
 *****************************************************************************/
static srv_mediacache_cell_struct *srv_mediacache_cache_get_draw_cell_by_fileindex(S32 file_index, MMI_BOOL is_auto_update_from_db)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *cell_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mediacache_cntx_p->large_p != NULL)
    {
        if (g_mediacache_cntx_p->large_p->file_index == file_index &&
            srv_mediacache_cache_cell_can_draw(g_mediacache_cntx_p->large_p) == MMI_TRUE)
        {
            return g_mediacache_cntx_p->large_p;
        }
    }
    cell_p = g_mediacache_cntx_p->level1_first_p;
    if (cell_p != NULL)
    {
        while (cell_p != NULL)
        {
            if (cell_p->file_index == file_index)
            {
                if (srv_mediacache_cache_cell_can_draw(cell_p) == MMI_TRUE)
                {
                    return cell_p;
                }
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
                else if(MMI_TRUE == is_auto_update_from_db)
                {
                    srv_mediacache_db_cancel_get_img(&g_mediacache_cntx_p->db_handle);
                    srv_mediacache_decode_by_database(cell_p, MMI_TRUE);
                    if (srv_mediacache_cache_cell_can_draw(cell_p) == MMI_TRUE)
                    {
                        return cell_p;
                    }
                }
#endif
                break;
            }
            cell_p = cell_p->next;
        }
    }
    cell_p = g_mediacache_cntx_p->level2_first_p;
    if (cell_p != NULL)
    {
        while (cell_p != NULL)
        {
            if (cell_p->file_index == file_index)
            {
                if (srv_mediacache_cache_cell_can_draw(cell_p) == MMI_TRUE)
                {
                    return cell_p;
                }
                break;
            }
            cell_p = cell_p->next;
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_resize_to_layer
 * DESCRIPTION
 *  resize the cache to layer
 * PARAMETERS
 *  grp1_index  [IN]    index
 *  dest_layer  [IN]    dest layer to draw to
 *  dest_x      [IN]    offset of x according to dest
 *  dest_y      [IN]    offest of y according to dest
 *  zoomfactor  [IN]    zoom factor * 1000
 *  x           [IN]    x after zoom of org image
 *  y           [IN]    y after zoom of org image
 *  width       [IN]    width after zoom of org image
 *  height      [IN]    height after zoom of org image
 *  app_cb      [IN]    call back function of app
 * RETURNS
 *  error code
 *****************************************************************************/
static S32 srv_mediacache_resize_to_layer(S32 file_index, srv_mediacache_img_to_layer_struct *area)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *use_cell_p;
    S32 err_code = SRV_MEDIACACHE_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(file_index >= 0);
    use_cell_p = srv_mediacache_cache_get_draw_cell_by_fileindex(file_index, MMI_FALSE);
    if (use_cell_p == NULL)
    {
        g_mediacache_cntx_p->app_data_cb = area->callback;
        g_mediacache_cntx_p->cb_file_idx = file_index;
        SRV_MEDIACACHE_CB_CHANGED();
        srv_mediacache_set_last_err(SRV_MEDIACACHE_ERR_GROUP_MEDIACACHE, SRV_MEDIACACHE_ERR_DECODING);
        err_code = SRV_MEDIACACHE_ERR_DECODING;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_DRAW_DECODING,
            g_mediacache_cntx_p->cb_file_idx,
            -1);
    }
    else
    {
        g_mediacache_cntx_p->app_data_cb = NULL;
        g_mediacache_cntx_p->cb_file_idx = SRV_MEDIACACHE_DUMMY_FILE_IDX;
        SRV_MEDIACACHE_CB_CHANGED();
        ASSERT(srv_mediacache_cache_cell_can_draw(use_cell_p) == MMI_TRUE);
        err_code = srv_mediacache_cache_resize2layer(use_cell_p, area);
    }
    return err_code;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_start
 * DESCRIPTION
 *  start the IVSRV engine
 * PARAMETERS
 *  start_flist_index   [IN]    start index of file
 * RETURNS
 *  error code
 *****************************************************************************/
S32 srv_mediacache_start(srv_handle handle, S32 start_flist_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *temp_cell_p;
    U32  i, cache_count;
    S32 result = 0;
    SRV_MEDIACACHE_MEAS_DEC(m_start);
    SRV_MEDIACACHE_MEAS_DEC(m_start_stage_1);
    SRV_MEDIACACHE_MEAS_DEC(m_start_stage_2);
    SRV_MEDIACACHE_MEAS_DEC(m_start_stage_3);
    SRV_MEDIACACHE_MEAS_DEC(m_start_stage_0);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_CT_START);
    SRV_MEDIACACHE_MEAS_START(m_start);
    ASSERT(g_mediacache_cntx_p->state == SRV_MEDIACACHE_STATE_INITED);
    ASSERT(sizeof(srv_mediacache_cntx_struct) <= SRV_MEDIACACHE_RUN_BUF_BASE);

#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
    if (g_mediacache_cntx_p->is_using_ies)
    {
        do
        {
            void *ies_heap = NULL;
            U32 ies_heap_size = srv_ies_app_session_get_required_mem_size(SRV_IES_FEATURE_VIEW);
            if (NULL != g_mediacache_cntx_p->ies_app_working_buf)
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_START_USING_APP_IES_BUFFER_X, g_mediacache_cntx_p->ies_app_working_buf);
                ies_heap = g_mediacache_cntx_p->ies_app_working_buf;
                MMI_ASSERT(g_mediacache_cntx_p->ies_app_working_buf_size >= ies_heap_size);
            }
            else
            {
                ies_heap = (void*)med_alloc_ext_mem_cacheable(ies_heap_size);
            }
            
            MMI_ASSERT(ies_heap);
            g_mediacache_cntx_p->ies_decoding_handle = NULL;
            // initialize IES application session
            g_mediacache_cntx_p->ies_app_session = NULL;
            // TODO: for testing, we're using MED
            
            srv_ies_app_session_create(
                0, 
                SRV_IES_FEATURE_VIEW, 
                ies_heap, 
                ies_heap_size, 
                &g_mediacache_cntx_p->ies_app_session);
            ASSERT(NULL != g_mediacache_cntx_p->ies_app_session);
        }while(0);
    }
#endif /* __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__ */

#if defined(__FS_SORT_SUPPORT__)
    // Only use M1 if cache count is larger than sort buffer
    if ((FS_SORT_MAX_ENTRY) < srv_mediacache_link_get_next_block_count(g_mediacache_cntx_p->level1_free_p) ||
        (FS_SORT_MAX_ENTRY) < srv_mediacache_link_get_next_block_count(g_mediacache_cntx_p->level2_free_p))
    {
        g_mediacache_cntx_p->decode_method = SRV_MEDIACACHE_CACHE_METHOD_M1;
    }
#endif
    if (start_flist_index < 0 || start_flist_index > g_mediacache_engine_cntx.file_count)
    {
        return SRV_MEDIACACHE_ERR_NOT_SUPPORT;
    }
    g_mediacache_cntx_p->state = SRV_MEDIACACHE_STATE_RUNNING;
    /*Check if first start, yes adjust cache link*/
    /*if (g_mediacache_cntx_p->is_srv_first_start == MMI_TRUE)*/
    SRV_MEDIACACHE_MEAS_START(m_start_stage_0);
    {
        if (NULL != g_mediacache_cntx_p->large_p)
        {
            if (g_mediacache_cntx_p->large_p->file_index != start_flist_index)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_RESET_CELL_LINE, __LINE__);
                srv_mediacache_cache_reset_cell(g_mediacache_cntx_p->large_p, MMI_FALSE);
                g_mediacache_cntx_p->large_p->file_index = start_flist_index;
            }
        }
        if (NULL != g_mediacache_cntx_p->level1_free_p && NULL == g_mediacache_cntx_p->level1_curr_p)
        {
            SRV_MEDIACACHE_MEAS_START(m_start_stage_1);
            g_mediacache_cntx_p->level1_first_p = g_mediacache_cntx_p->level1_free_p;
            temp_cell_p = g_mediacache_cntx_p->level1_first_p;
            cache_count = srv_mediacache_link_get_next_block_count(temp_cell_p) + 1;
            if (cache_count > g_mediacache_engine_cntx.file_count)
            {
                for (i = 0 ; i < g_mediacache_engine_cntx.file_count; i++)
                {
                    temp_cell_p = temp_cell_p->next;
                }
                g_mediacache_cntx_p->level1_free_p = temp_cell_p;
                temp_cell_p->prev->next = NULL;
                temp_cell_p->prev = NULL;
                cache_count = srv_mediacache_link_get_next_block_count(g_mediacache_cntx_p->level1_first_p) + 1;
            }
            else
            {
                g_mediacache_cntx_p->level1_free_p = NULL;
            }
            temp_cell_p = g_mediacache_cntx_p->level1_first_p;
            for (i = 0 ; i < cache_count / 2; i++)
            {
                temp_cell_p = temp_cell_p->next;
            }
            g_mediacache_cntx_p->level1_curr_p = temp_cell_p;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_RESET_CELL_LINE, __LINE__);
            srv_mediacache_cache_reset_cell(g_mediacache_cntx_p->level1_curr_p, MMI_FALSE);
            g_mediacache_cntx_p->level1_curr_p->file_index = start_flist_index;
            srv_mediacache_cache_fill_index_to_link(
                g_mediacache_cntx_p->level1_curr_p, 
                start_flist_index, 
                g_mediacache_engine_cntx.file_count);
            srv_mediacache_cache_fill_index_to_link(
                g_mediacache_cntx_p->level2_curr_p, 
                start_flist_index, 
                g_mediacache_engine_cntx.file_count);
            SRV_MEDIACACHE_MEAS_STOP(m_start_stage_1);
        }
        if (NULL != g_mediacache_cntx_p->level2_free_p && NULL == g_mediacache_cntx_p->level2_curr_p)
        {
            SRV_MEDIACACHE_MEAS_START(m_start_stage_2);
            g_mediacache_cntx_p->level2_free_p = srv_mediacache_link_get_first(g_mediacache_cntx_p->level2_free_p);
            g_mediacache_cntx_p->level2_first_p = g_mediacache_cntx_p->level2_free_p;
            temp_cell_p = g_mediacache_cntx_p->level2_first_p;
            cache_count = srv_mediacache_link_get_next_block_count(temp_cell_p) + 1;
            if (cache_count > g_mediacache_engine_cntx.file_count)
            {
                for (i = 0 ; i < g_mediacache_engine_cntx.file_count; i++)
                {
                    temp_cell_p = temp_cell_p->next;
                }
                g_mediacache_cntx_p->level2_free_p = temp_cell_p;
                temp_cell_p->prev->next = NULL;
                temp_cell_p->prev = NULL;
                cache_count = srv_mediacache_link_get_next_block_count(g_mediacache_cntx_p->level2_first_p) + 1;
            }
            else
            {
                g_mediacache_cntx_p->level2_free_p = NULL;
            }
            temp_cell_p = g_mediacache_cntx_p->level2_first_p;
            for (i = 0 ; i < cache_count / 2; i++)
            {
                temp_cell_p = temp_cell_p->next;
            }
            g_mediacache_cntx_p->level2_curr_p = temp_cell_p;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_RESET_CELL_LINE, __LINE__);
            srv_mediacache_cache_reset_cell(g_mediacache_cntx_p->level2_curr_p, MMI_FALSE);
            g_mediacache_cntx_p->level2_curr_p->file_index = start_flist_index;
            srv_mediacache_cache_fill_index_to_link(
                g_mediacache_cntx_p->level1_curr_p, 
                start_flist_index, 
                g_mediacache_engine_cntx.file_count);
            srv_mediacache_cache_fill_index_to_link(
                g_mediacache_cntx_p->level2_curr_p, 
                start_flist_index, 
                g_mediacache_engine_cntx.file_count);
            SRV_MEDIACACHE_MEAS_STOP(m_start_stage_2);
        }
    }
    SRV_MEDIACACHE_MEAS_STOP(m_start_stage_0);
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
    SRV_MEDIACACHE_MEAS_STOP(m_start_stage_3);
    if (MMI_TRUE == g_mediacache_cntx_p->is_blocking_get_first)
    {
        if (g_mediacache_cntx_p->db_store_cache_group == SRV_MEDIACACHE_CACHE_TYPE_L2)
        {
            result = srv_mediacache_decode_by_database(g_mediacache_cntx_p->level2_curr_p, MMI_TRUE);
        }
        else if (g_mediacache_cntx_p->db_store_cache_group == SRV_MEDIACACHE_CACHE_TYPE_L1)
        {
            result = srv_mediacache_decode_by_database(g_mediacache_cntx_p->level1_curr_p, MMI_TRUE);
        }
    }
    SRV_MEDIACACHE_MEAS_STOP(m_start_stage_3);
#endif

    g_mediacache_cntx_p->is_srv_first_start = MMI_FALSE;
    g_mediacache_cntx_p->is_schedule_timer_started = MMI_FALSE;
    
    /* 
     *  for the first image, we create image handle , and render preview buffer async ,
     *  so if you press zoom between, DB image and preview buffer render and. we can cancel preview, 
     *  and render zoom image for you.
     *  this happens when DB image is OK
    */
    /*
    if (result == 0) // means db get block image OK
    {
        if (g_mediacache_cntx_p->is_using_ies)
        {
            srv_mediacache_cell_struct *cell_p;

            cell_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &start_flist_index);
            if (cell_p && _srv_mediacache_decode_need_ies_check(cell_p))
            {
                srv_mediacache_preview_render_buffer_to_cell_async(cell_p);
            }
        }
    }
    */

    /* here means db can get this image, so */
    if (result == 0 && g_mediacache_cntx_p->is_using_ies)
    {
        srv_mediacache_check_and_start_decode_at_once();
    }
    
    SRV_MEDIACACHE_MEAS_STOP(m_start);
#ifdef __MM_DEBUG_MEASURE_SRVMC__
    kal_print_string_trace(
        MOD_MMI_MEDIA_APP, 
        MMI_MEDIA_TRC_G2_APP, 
        "[srvmc]meas start [%d] stage0[%d] 1[%d] 2[%d] 3[%d]", 
        m_start,m_start_stage_0,m_start_stage_1,m_start_stage_2,m_start_stage_3);
#endif
    return SRV_MEDIACACHE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_stop
 * DESCRIPTION
 *  stop the SRV
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mediacache_stop(srv_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_CT_STOP);

    if (g_mediacache_cntx_p->state == SRV_MEDIACACHE_STATE_RUNNING ||
        g_mediacache_cntx_p->state == SRV_MEDIACACHE_STATE_PAUSED)
    {
        g_mediacache_cntx_p->state = SRV_MEDIACACHE_STATE_INITED;
    }
    g_mediacache_cntx_p->state = SRV_MEDIACACHE_STATE_INITED;
    g_mediacache_cntx_p->app_data_cb = NULL;
    g_mediacache_cntx_p->cb_file_idx = SRV_MEDIACACHE_DUMMY_FILE_IDX;
    SRV_MEDIACACHE_CB_CHANGED();
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_CANCEL_DECODE_CELL_AT_D, __LINE__);
    g_mediacache_cntx_p->engine.cancel_decode_cell(g_mediacache_cntx_p->image_hdl_decoding);
    g_mediacache_cntx_p->image_hdl_decoding = 0;
    srv_mediacache_decode_check_and_free_layer();
    srv_mediacache_stop_decode();
    if (g_mediacache_cntx_p->decoding_p != NULL)
    {
        if (g_mediacache_cntx_p->decoding_p->state == SRV_MEDIACACHE_CACHE_STATE_DECODING)
        {

            g_mediacache_cntx_p->decoding_p->state = SRV_MEDIACACHE_CACHE_STATE_EMPTY;
        }
    }
    g_mediacache_cntx_p->decoding_p = NULL;
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_DECODING_P_IS_NULL_D, __LINE__);

#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
    if (g_mediacache_cntx_p->is_using_ies)
    {
        srv_mediacache_release_ies_handle();

        if(g_mediacache_cntx_p->ies_app_session)
        {
            void *buffer_p = NULL;
            srv_ies_app_session_get_buf_ptr(g_mediacache_cntx_p->ies_app_session, &buffer_p);
            srv_ies_app_session_destroy(g_mediacache_cntx_p->ies_app_session);
            g_mediacache_cntx_p->ies_app_session = NULL;
            
            
            if (NULL != g_mediacache_cntx_p->ies_app_working_buf)
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_STOP_BUT_STILL_USING_APP_BUFFER_X, g_mediacache_cntx_p->ies_app_working_buf);
            }
            else
            {
                med_free_ext_mem((void**)&buffer_p);
            }
        }
    }
#endif /* __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__ */

}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_retry_decode_curr
 * DESCRIPTION
 *  retry decode current image to SRV buffer, will not decode if large is OK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mediacache_retry_decode_curr(srv_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL    is_start_ok;
    S32 file_index = SRV_MEDIACACHE_DUMMY_FILE_IDX;
    srv_mediacache_cell_struct  *new_cell = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mediacache_cntx_p->state != SRV_MEDIACACHE_STATE_RUNNING && g_mediacache_cntx_p->state != SRV_MEDIACACHE_STATE_PAUSED)
    {
        return;
    }
    if (g_mediacache_cntx_p->level1_curr_p != NULL)
    {
        file_index = g_mediacache_cntx_p->level1_curr_p->file_index;
    }
    else if (g_mediacache_cntx_p->level2_curr_p != NULL)
    {
        file_index = g_mediacache_cntx_p->level2_curr_p->file_index;
    }
    else if (g_mediacache_cntx_p->large_p != NULL)
    {
        file_index = g_mediacache_cntx_p->large_p->file_index;
    }
    if (NULL != g_mediacache_cntx_p->level2_curr_p)
    {        
        if (g_mediacache_cntx_p->level2_curr_p->state != SRV_MEDIACACHE_CACHE_STATE_DECODE_OK)
        {        
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_RESET_CELL_LINE, __LINE__);
            srv_mediacache_cache_reset_cell(g_mediacache_cntx_p->level2_curr_p, MMI_FALSE);
            g_mediacache_cntx_p->level2_curr_p->file_index = file_index;
            new_cell = g_mediacache_cntx_p->level2_curr_p;
        }
    }
    if (NULL != g_mediacache_cntx_p->level1_curr_p)
    {        
        if (g_mediacache_cntx_p->level1_curr_p->state != SRV_MEDIACACHE_CACHE_STATE_DECODE_OK)
        {        
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_RESET_CELL_LINE, __LINE__);
            srv_mediacache_cache_reset_cell(g_mediacache_cntx_p->level1_curr_p, MMI_FALSE);
            g_mediacache_cntx_p->level1_curr_p->file_index = file_index;
            new_cell = g_mediacache_cntx_p->level1_curr_p;
        }
    }
    if (NULL != g_mediacache_cntx_p->large_p)
    {   
        if (g_mediacache_cntx_p->is_using_ies)
        {
            //here we do nothing. for we do not fill large in this case. so do not use it
        }
        else
        {
            if (g_mediacache_cntx_p->large_p->state != SRV_MEDIACACHE_CACHE_STATE_DECODE_OK)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_RESET_CELL_LINE, __LINE__);
                srv_mediacache_cache_reset_cell(g_mediacache_cntx_p->large_p, MMI_FALSE);
                g_mediacache_cntx_p->large_p->file_index = file_index;
                new_cell = g_mediacache_cntx_p->large_p;
            }
        }
    }
    if (NULL != new_cell)
    {        
        if (g_mediacache_cntx_p->decoding_p != NULL)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_CANCEL_DECODE_CELL_AT_D, __LINE__);
            g_mediacache_cntx_p->engine.cancel_decode_cell(g_mediacache_cntx_p->image_hdl_decoding);
            g_mediacache_cntx_p->image_hdl_decoding = 0;
            g_mediacache_cntx_p->decoding_p = NULL;
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_DECODING_P_IS_NULL_D, __LINE__);
        }
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
        /*process searching one*/
        if (g_mediacache_cntx_p->searching_p != NULL)
        {
            srv_mediacache_db_cancel_get_img(&g_mediacache_cntx_p->db_handle);
            g_mediacache_cntx_p->searching_p = NULL;
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_SEARCH_CHANGE_SEARCHING_POINT_TO_NULL_AT_D, __LINE__);
        }
#endif
        g_mediacache_cntx_p->decoding_p = new_cell;
        is_start_ok = g_mediacache_cntx_p->engine.decode_cell(
            &g_mediacache_cntx_p->image_hdl_decoding, 
            new_cell, 
            srv_mediacache_decode_nb_decode_callback, 
            g_mediacache_cntx_p);
        if (is_start_ok != MMI_TRUE)
        {
            g_mediacache_cntx_p->decoding_p = NULL;
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_DECODING_P_IS_NULL_D, __LINE__);
            srv_mediacache_check_and_start_decode();  
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_can_draw_curr
 * DESCRIPTION
 *  check current if can draw.
 * PARAMETERS
 *  void
 * RETURNS
 *  SRV_MEDIACACHE_ERR_NOT_READY   error can't draw
 *  SRV_MEDIACACHE_OK_LARGE              can draw from large buffer
 *  SRV_MEDIACACHE_OK_L1                 can draw from L1 buffer
 *  SRV_MEDIACACHE_OK_L2                 can draw from L2 buffer
 *****************************************************************************/
srv_mediacache_err_enum srv_mediacache_can_draw_curr(srv_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL    can_draw;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    can_draw = srv_mediacache_cache_cell_can_draw(g_mediacache_cntx_p->large_p);
    if (can_draw == MMI_TRUE)
    {
        return SRV_MEDIACACHE_OK_LARGE;
    }
    can_draw = srv_mediacache_cache_cell_can_draw(g_mediacache_cntx_p->level1_curr_p);
    if (can_draw == MMI_TRUE)
    {
        return SRV_MEDIACACHE_OK_L1;
    }
    can_draw = srv_mediacache_cache_cell_can_draw(g_mediacache_cntx_p->level2_curr_p);
    if (can_draw == MMI_TRUE)
    {
        return SRV_MEDIACACHE_OK_L2;
    }
    return SRV_MEDIACACHE_ERR_NOT_READY;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_can_draw_curr
 * DESCRIPTION
 *  check current if can draw.
 * PARAMETERS
 *  void
 * RETURNS
 *  SRV_MEDIACACHE_ERR_NOT_READY   error can't draw
 *  SRV_MEDIACACHE_OK_LARGE              can draw from large buffer
 *  SRV_MEDIACACHE_OK_L1                 can draw from L1 buffer
 *  SRV_MEDIACACHE_OK_L2                 can draw from L2 buffer
 *****************************************************************************/
srv_mediacache_err_enum srv_mediacache_can_draw_by_index(srv_handle handle, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *cache_cell;
    MMI_BOOL    can_draw;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cache_cell = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->large_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
    can_draw = srv_mediacache_cache_cell_can_draw(cache_cell);
    if (can_draw == MMI_TRUE)
    {
        return SRV_MEDIACACHE_OK_LARGE;
    }
    cache_cell = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
    can_draw = srv_mediacache_cache_cell_can_draw(cache_cell);
    if (can_draw == MMI_TRUE)
    {
        return SRV_MEDIACACHE_OK_L1;
    }
    cache_cell = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level2_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
    can_draw = srv_mediacache_cache_cell_can_draw(cache_cell);
    if (can_draw == MMI_TRUE)
    {
        return SRV_MEDIACACHE_OK_L2;
    }
    return SRV_MEDIACACHE_ERR_NOT_READY;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_get_last_source
 * DESCRIPTION
 *  check last resize source.
 * PARAMETERS
 *  void
 * RETURNS
 *  SRV_MEDIACACHE_ERR_UNKNOW            call this before resize
 *  SRV_MEDIACACHE_OK_LARGE              can draw from large buffer
 *  SRV_MEDIACACHE_OK_L1                 can draw from L1 buffer
 *  SRV_MEDIACACHE_OK_L2                 can draw from L2 buffer
 *****************************************************************************/
srv_mediacache_err_enum srv_mediacache_get_last_source(srv_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mediacache_cntx_p->last_source;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cell_can_draw_by_index
 * DESCRIPTION
 *  check current if can draw.
 * PARAMETERS
 *  void
 * RETURNS
 *  SRV_MEDIACACHE_ERR_NOT_READY   error can't draw
 *  SRV_MEDIACACHE_OK_LARGE              can draw from large buffer
 *  SRV_MEDIACACHE_OK_L1                 can draw from L1 buffer
 *  SRV_MEDIACACHE_OK_L2                 can draw from L2 buffer
 *****************************************************************************/
srv_mediacache_err_enum srv_mediacache_cell_can_draw_by_index(srv_handle handle, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL    can_draw;
    srv_mediacache_cell_struct *cell_found_p;
    S32 ret_code = SRV_MEDIACACHE_ERR_NOT_READY;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cell_found_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->large_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
    can_draw = srv_mediacache_cache_cell_can_draw(cell_found_p);
    if (can_draw == MMI_TRUE)
    {
        ret_code = SRV_MEDIACACHE_OK_LARGE;
    }
    if (NULL == cell_found_p || can_draw == MMI_FALSE)
    {
        cell_found_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
        can_draw = srv_mediacache_cache_cell_can_draw(cell_found_p);
        if (can_draw == MMI_TRUE)
        {
            ret_code = SRV_MEDIACACHE_OK_L1;
        }
    }
    if (NULL == cell_found_p || can_draw == MMI_FALSE)
    {
        cell_found_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level2_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
        can_draw = srv_mediacache_cache_cell_can_draw(cell_found_p);
        if (can_draw == MMI_TRUE)
        {
            ret_code = SRV_MEDIACACHE_OK_L2;
        }
    }
    return (srv_mediacache_err_enum)ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_get_curr_file_index
 * DESCRIPTION
 *  get current file index
 * PARAMETERS
 *  void
 * RETURNS
 *  file index
 *****************************************************************************/
S32 srv_mediacache_get_curr_index(srv_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != g_mediacache_cntx_p->level1_curr_p)
    {
        index = g_mediacache_cntx_p->level1_curr_p->file_index;
    }
    else if (NULL != g_mediacache_cntx_p->level2_curr_p)
    {
        index = g_mediacache_cntx_p->level2_curr_p->file_index;
    }
    else if (NULL != g_mediacache_cntx_p->large_p)
    {
        index = g_mediacache_cntx_p->large_p->file_index;
    }
    return index;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_get_curr_img
 * DESCRIPTION
 *  get current image to layer
 *  x,y mean offset of zoomed image, zoomfactor will div 100, 
 *  if miss it will call data_cb after decode finish.
 * PARAMETERS
 *  dest_layer  [IN]    dest layer to draw to
 *  dest_x      [IN]    offset of x according to dest
 *  dest_y      [IN]    offest of y according to dest
 *  zoomfactor  [IN]    zoom factor * 1000
 *  x           [IN]    x after zoom of org image
 *  y           [IN]    y after zoom of org image
 *  width       [IN]    width after zoom of org image
 *  height      [IN]    height after zoom of org image
 *  app_cb      [IN]    call back function of app
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_mediacache_get_curr_img_to_layer(srv_handle handle, srv_mediacache_img_to_layer_struct *area)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 err_code = SRV_MEDIACACHE_OK;
    S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_SRV_MEDIACACHE_GET_CURR_IMG_TO_LAYER);
    index = srv_mediacache_get_curr_index(handle);
    area->source = SRV_MEDIACACHE_IMAGE_SOURCE_CACHE;
    err_code = srv_mediacache_get_img_to_layer_internal(handle, index, area, MMI_FALSE);
    if (err_code == SRV_MEDIACACHE_ERR_NOT_READY)
    {
        err_code = SRV_MEDIACACHE_ERR_DECODING;
    }
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_SRV_MEDIACACHE_GET_CURR_IMG_TO_LAYER);

    return err_code;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_get_next_img
 * DESCRIPTION
 *  get next image to layer
 * PARAMETERS
 *  dest_layer  [IN]    dest layer to draw to
 *  dest_x      [IN]    offset of x according to dest
 *  dest_y      [IN]    offest of y according to dest
 *  zoomfactor  [IN]    zoom factor * 1000
 *  x           [IN]    x after zoom of org image
 *  y           [IN]    y after zoom of org image
 *  width       [IN]    width after zoom of org image
 *  height      [IN]    height after zoom of org image
 *  app_cb      [IN]    call back function of app
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_mediacache_get_next_img_to_layer(srv_handle handle, srv_mediacache_img_to_layer_struct *area)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 err_code = SRV_MEDIACACHE_OK;
    S32 index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&g_mediacache_cntx_p->start_ticks);
    g_mediacache_cntx_p->app_data_cb = NULL;
    g_mediacache_cntx_p->cb_file_idx = SRV_MEDIACACHE_DUMMY_FILE_IDX;

    /*calc next file index*/
    index = srv_mediacache_get_curr_index(handle);
    if (index + 1 < g_mediacache_engine_cntx.file_count)
    {
        index++;
    }
    else
    {
        index = 0;
    }
    
    err_code = srv_mediacache_resize_to_layer(index, area);
    kal_get_time(&g_mediacache_cntx_p->end_ticks);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_DRAW_GET_NEXT_TIKCS,g_mediacache_cntx_p->end_ticks - g_mediacache_cntx_p->start_ticks);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_DRAW_GET_RETURN_CODE,err_code);
    return err_code;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_get_next_img
 * DESCRIPTION
 *  get next image to layer
 * PARAMETERS
 *  dest_layer  [IN]    dest layer to draw to
 *  dest_x      [IN]    offset of x according to dest
 *  dest_y      [IN]    offest of y according to dest
 *  zoomfactor  [IN]    zoom factor * 1000
 *  x           [IN]    x after zoom of org image
 *  y           [IN]    y after zoom of org image
 *  width       [IN]    width after zoom of org image
 *  height      [IN]    height after zoom of org image
 *  app_cb      [IN]    call back function of app
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_mediacache_get_prev_img_to_layer(srv_handle handle, srv_mediacache_img_to_layer_struct *area)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 err_code = SRV_MEDIACACHE_OK;
    S32 index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&g_mediacache_cntx_p->start_ticks);
    g_mediacache_cntx_p->app_data_cb = NULL;
    g_mediacache_cntx_p->cb_file_idx = SRV_MEDIACACHE_DUMMY_FILE_IDX;

    /*calc next file index*/
    index = srv_mediacache_get_curr_index(handle);
    if (index > 0)
    {
        index--;
    }
    else
    {
        index = g_mediacache_engine_cntx.file_count - 1;
    }
    
    err_code = srv_mediacache_resize_to_layer(index, area);

    kal_get_time(&g_mediacache_cntx_p->end_ticks);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_DRAW_GET_NEXT_TIKCS,g_mediacache_cntx_p->end_ticks - g_mediacache_cntx_p->start_ticks);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_DRAW_GET_RETURN_CODE,err_code);
    return err_code;
}

extern void srv_mediacache_config_schedule_policy(srv_handle handle, srv_mediacache_schedule_policy policy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cntx_struct *cntx_p = (srv_mediacache_cntx_struct *)handle;
    if (NULL == cntx_p)
    {
        return;
    }

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p->decode_method = policy;
    return;
}

extern void srv_mediacache_config_database(srv_handle handle, void* buffer, U32 length, WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
    U16 db_name[IVD_FILE_MAX_PATH_LEN];
    srv_mediacache_cntx_struct *medialib_cntx_p = (srv_mediacache_cntx_struct *)handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(buffer != NULL);
    ASSERT(handle == medialib_cntx_p->medialib_mark);
    kal_wsprintf(db_name, "%s%dx%d%s","thumb",g_mediacache_engine_cntx.width,g_mediacache_engine_cntx.height,".db");
    if (g_mediacache_engine_cntx.width == 0 || g_mediacache_engine_cntx.height == 0)
    {
        kal_wsprintf(db_name, "%6d%s",(U32)(length + path),"thumb.db");
    }
    srv_mediacache_config_db(handle, buffer, length, path, db_name);
#endif
}


extern void srv_mediacache_config_db(srv_handle handle, void* buffer, U32 length, WCHAR *path, WCHAR *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
    srv_mediacache_cntx_struct *medialib_cntx_p = (srv_mediacache_cntx_struct *)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(buffer != NULL);
    ASSERT(name != NULL);
    if (medialib_cntx_p->db_store_cache_group == SRV_MEDIACACHE_CACHE_TYPE_L2)
    {
    ASSERT(length >= SRV_MEDIACACHE_SQLITE_DB_BUF_SIZE_MIN);
    }
    else if (medialib_cntx_p->db_store_cache_group == SRV_MEDIACACHE_CACHE_TYPE_L1)
    {
        ASSERT(length >= SRV_MEDIACACHE_SQLITE_DB_L1_BUF_SIZE_MIN);
    }
    else
    {
        ASSERT(0);
    }
    ASSERT(handle == medialib_cntx_p->medialib_mark);
    medialib_cntx_p->config.db_buf = buffer;
    medialib_cntx_p->config.db_buf_length = length;
    medialib_cntx_p->is_db_start_ok = MMI_FALSE;
    medialib_cntx_p->is_clear_done = MMI_FALSE;
    medialib_cntx_p->searching_p = NULL;
    srv_mediacache_start_db(medialib_cntx_p->config.db_buf, medialib_cntx_p->config.db_buf_length, path, name);
#endif
}


extern void srv_mediacache_config_database_debug_showmark(srv_handle handle, MMI_BOOL is_show)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
    srv_mediacache_cntx_struct *medialib_cntx_p = (srv_mediacache_cntx_struct *)handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(handle == medialib_cntx_p->medialib_mark);
    medialib_cntx_p->db_handle.is_mark = is_show;
#endif
}


void srv_mediacache_config_color_format(srv_handle handle, U8 color_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cntx_struct *medialib_cntx_p = (srv_mediacache_cntx_struct *)handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(medialib_cntx_p->state != SRV_MEDIACACHE_STATE_RUNNING);
    ASSERT(medialib_cntx_p->state != SRV_MEDIACACHE_STATE_PAUSED);
    ASSERT(handle == medialib_cntx_p->medialib_mark);
    switch(color_format)
    {
    case GDI_COLOR_FORMAT_16:
        g_mediacache_cntx_p->color_format = GDI_COLOR_FORMAT_16;
        g_mediacache_cntx_p->bytes_per_pixel = 2;
        g_mediacache_cntx_p->level1_buffer_size = g_mediacache_cntx_p->config.level1_width * g_mediacache_cntx_p->config.level1_height * g_mediacache_cntx_p->bytes_per_pixel;
        g_mediacache_cntx_p->level2_buffer_size = g_mediacache_cntx_p->config.level2_width * g_mediacache_cntx_p->config.level2_height * g_mediacache_cntx_p->bytes_per_pixel;
        break;
    case GDI_COLOR_FORMAT_24:
        g_mediacache_cntx_p->color_format = GDI_COLOR_FORMAT_24;
        g_mediacache_cntx_p->bytes_per_pixel = 3;
        g_mediacache_cntx_p->level1_buffer_size = g_mediacache_cntx_p->config.level1_width * g_mediacache_cntx_p->config.level1_height * g_mediacache_cntx_p->bytes_per_pixel;
        g_mediacache_cntx_p->level2_buffer_size = g_mediacache_cntx_p->config.level2_width * g_mediacache_cntx_p->config.level2_height * g_mediacache_cntx_p->bytes_per_pixel;
        break;
    default:
        /*not supported color format*/
        break;
    }
#if defined(__SQLITE3_SUPPORT__)
    g_mediacache_cntx_p->db_handle.color_format = g_mediacache_cntx_p->color_format;
    g_mediacache_cntx_p->db_handle.bytes_per_pixel = g_mediacache_cntx_p->bytes_per_pixel;
#endif
}


void srv_mediacache_config_blocking_get_first(srv_handle handle, MMI_BOOL is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cntx_struct *medialib_cntx_p = (srv_mediacache_cntx_struct *)handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(handle == medialib_cntx_p->medialib_mark);
    medialib_cntx_p->is_blocking_get_first = is_enable;
}



extern void srv_mediacache_config_database_store_group(srv_handle handle, U32 group)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
    srv_mediacache_cntx_struct *medialib_cntx_p = (srv_mediacache_cntx_struct *)handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(handle == medialib_cntx_p->medialib_mark);
    ASSERT(medialib_cntx_p->state != SRV_MEDIACACHE_STATE_RUNNING);
    switch (group)
    {
    case SRV_MEDIACACHE_CACHE_TYPE_L1:
    case SRV_MEDIACACHE_CACHE_TYPE_L2:
        break;
    default:
        ASSERT(0);
    }
    medialib_cntx_p->db_store_cache_group = group;
#endif
}


extern void srv_mediacache_config_database_store_cache_type(srv_handle handle, srv_mediacache_cache_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
    srv_mediacache_cntx_struct *medialib_cntx_p = (srv_mediacache_cntx_struct *)handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(handle == medialib_cntx_p->medialib_mark);
    /*not change if state is running or database is started*/
    if(medialib_cntx_p->state == SRV_MEDIACACHE_STATE_RUNNING ||
       medialib_cntx_p->config.db_buf != NULL)
    {
        return;
    }
    if (type == SRV_MEDIACACHE_CACHE_TYPE_L1 || type == SRV_MEDIACACHE_CACHE_TYPE_L2)
    {
        medialib_cntx_p->db_store_cache_group = type;
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_config_db
 * DESCRIPTION
 *  service database config function.
 * PARAMETERS
 *  path      :  [IN]  browse path.
 *  buffer    :  [IN]  buffer for database use.
 *  length    :  [IN]  buffer length.
 * RETURNS
 *  None.
 *****************************************************************************/
void srv_mediacache_config_work_mode_to_prefetch_func(srv_handle handle, S32 num_all, srv_mediacache_get_filename_cb callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cntx_struct *medialib_cntx_p = (srv_mediacache_cntx_struct *)handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(handle == medialib_cntx_p->medialib_mark);
    g_mediacache_engine_cntx.file_count = num_all;
    g_mediacache_cntx_p->engine.get_file_name = callback;
}


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_config_db
 * DESCRIPTION
 *  service database config function.
 * PARAMETERS
 *  path      :  [IN]  browse path.
 *  buffer    :  [IN]  buffer for database use.
 *  length    :  [IN]  buffer length.
 * RETURNS
 *  None.
 *****************************************************************************/
extern void srv_mediacache_config_level2_size(srv_handle handle, U32 width, U32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 bits;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(NULL != g_mediacache_cntx_p);
    g_mediacache_engine_cntx.width = width;
    g_mediacache_engine_cntx.height = height;
    g_mediacache_engine_cntx.is_to_buffer = MMI_TRUE;
    g_mediacache_engine_cntx.is_lock_level2_only = MMI_TRUE;
    bits = srv_mediacache_get_bits_per_pixel(g_mediacache_cntx_p->config.level2_cf);
    g_mediacache_cntx_p->config.level2_width = width;
    g_mediacache_cntx_p->config.level2_height = height;
    g_mediacache_cntx_p->level2_buffer_size = width * height * bits / 8;
}


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_config_db
 * DESCRIPTION
 *  service database config function.
 * PARAMETERS
 *  path      :  [IN]  browse path.
 *  buffer    :  [IN]  buffer for database use.
 *  length    :  [IN]  buffer length.
 * RETURNS
 *  None.
 *****************************************************************************/
void srv_mediacache_disable_level2_clip_head(srv_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mediacache_engine_cntx.is_to_buffer = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_config_db
 * DESCRIPTION
 *  service database config function.
 * PARAMETERS
 *  path      :  [IN]  browse path.
 *  buffer    :  [IN]  buffer for database use.
 *  length    :  [IN]  buffer length.
 * RETURNS
 *  None.
 *****************************************************************************/
void srv_mediacache_config_work_mode_to_filelist(srv_handle handle, SRV_FMGR_FILELIST_HANDLE filelist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cntx_struct *medialib_cntx_p = (srv_mediacache_cntx_struct *)handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(handle == medialib_cntx_p->medialib_mark);
    medialib_cntx_p->config.flist_handle = filelist;
    g_mediacache_cntx_p->engine.get_file_name = srv_mediacache_decode_get_filename_by_index;
    medialib_cntx_p->work_mode = SRV_MEDIACACHE_WORKMODE_FILELIST;
    g_mediacache_engine_cntx.flist_handle = filelist;
    g_mediacache_engine_cntx.file_count = srv_fmgr_filelist_count(filelist);
}


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_config_db
 * DESCRIPTION
 *  service database config function.
 * PARAMETERS
 *  path      :  [IN]  browse path.
 *  buffer    :  [IN]  buffer for database use.
 *  length    :  [IN]  buffer length.
 * RETURNS
 *  None.
 *****************************************************************************/
static S32 srv_mediacache_work_mode_idarray_get_name_cb(S32 index, WCHAR *buffer, U32 length, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cntx_struct *medialib_cntx_p = (srv_mediacache_cntx_struct *)user_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == user_data)
    {
        medialib_cntx_p = g_mediacache_cntx_p;
    }
    ASSERT((srv_handle)medialib_cntx_p == medialib_cntx_p->medialib_mark);
    if (index >= medialib_cntx_p->mode_cntx.idarray.count)
    {
        return -1;
    }
    kal_wsprintf(buffer, "@:%d", medialib_cntx_p->mode_cntx.idarray.idarray_p[index]);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_config_db
 * DESCRIPTION
 *  service database config function.
 * PARAMETERS
 *  path      :  [IN]  browse path.
 *  buffer    :  [IN]  buffer for database use.
 *  length    :  [IN]  buffer length.
 * RETURNS
 *  None.
 *****************************************************************************/
void srv_mediacache_config_work_mode_to_id_array(srv_handle handle, S32 num_all, U16 *id_array_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cntx_struct *medialib_cntx_p = (srv_mediacache_cntx_struct *)handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(handle == medialib_cntx_p->medialib_mark);
    medialib_cntx_p->mode_cntx.idarray.count = num_all;
    medialib_cntx_p->mode_cntx.idarray.idarray_p = id_array_p;
    medialib_cntx_p->work_mode = SRV_MEDIACACHE_WORKMODE_IDARRAY;
    srv_mediacache_config_work_mode_to_prefetch_func(handle, num_all, srv_mediacache_work_mode_idarray_get_name_cb);
}


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_config_db
 * DESCRIPTION
 *  service database config function.
 * PARAMETERS
 *  filename      :  [IN]  image file name with path.
 * RETURNS
 *  None.
 *****************************************************************************/
void srv_mediacache_config_work_mode_to_filename(srv_handle handle, const WCHAR *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cntx_struct *medialib_cntx_p = (srv_mediacache_cntx_struct *)handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(handle == medialib_cntx_p->medialib_mark);
    memcpy(medialib_cntx_p->config.filename, filename, SRV_FMGR_PATH_BUFFER_SIZE);
    g_mediacache_engine_cntx.file_count = 1;
    medialib_cntx_p->work_mode = SRV_MEDIACACHE_WORKMODE_FILENAME;
    g_mediacache_cntx_p->engine.get_file_name = srv_mediacache_engine_file_get_filename;
}


/*****************************************************************************
 * FUNCTION
 *    SRV_MEDIACACHE_create
 * DESCRIPTION
 *  service create function.
 * PARAMETERS
 *  configure    :  [IN]  the configuration of service.
 * RETURNS
 *  None.
 *****************************************************************************/
void srv_mediacache_register_engine(srv_mediacache_eng_callbacks_struct *engine_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == engine_p)
    {
        return;
    }
    if (NULL != engine_p->get_file_name)
    {
        g_mediacache_cntx_p->engine.get_file_name = engine_p->get_file_name;
    }
    if (NULL != engine_p->decode_cell)
    {
        g_mediacache_cntx_p->engine.decode_cell = engine_p->decode_cell;
    }
    if (NULL != engine_p->cancel_decode_cell)
    {
        g_mediacache_cntx_p->engine.cancel_decode_cell = engine_p->cancel_decode_cell;
    }
    if (NULL != engine_p->search_cell)
    {
        g_mediacache_cntx_p->engine.search_cell = engine_p->search_cell;
    }
    if (NULL != engine_p->cancel_search_cell)
    {
        g_mediacache_cntx_p->engine.cancel_search_cell = engine_p->cancel_search_cell;
    }
}


/*****************************************************************************
 * FUNCTION
 *    SRV_MEDIACACHE_create
 * DESCRIPTION
 *  service create function.
 * PARAMETERS
 *  configure    :  [IN]  the configuration of service.
 * RETURNS
 *  None.
 *****************************************************************************/
void srv_mediacache_register_engine_clip_function(srv_mediacache_engine_clip clip_funcion, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != clip_funcion)
    {
        g_mediacache_cntx_p->engine.set_clip = clip_funcion;
        g_mediacache_cntx_p->engine.user_data = user_data;
    }
}


/*****************************************************************************
 * FUNCTION
 *    SRV_MEDIACACHE_create
 * DESCRIPTION
 *  service create function.
 * PARAMETERS
 *  configure    :  [IN]  the configuration of service.
 * RETURNS
 *  None.
 *****************************************************************************/
void srv_mediacache_engine_set_clip(U32* handle, S32 *layer_w, S32 *layer_h, srv_mediacache_rect_struct *img_org, srv_mediacache_rect_struct *img_resized, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cntx_struct *m_cntx_p = (srv_mediacache_cntx_struct*) handle;
    U32 width, height, v_rate, h_rate;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mediacache_engine_cntx.is_to_buffer == MMI_TRUE &&
        m_cntx_p->decoding_p != m_cntx_p->large_p)
    {
        if (img_org->width > *layer_w && img_org->height > *layer_h)
        {
            v_rate = img_org->height * 1000 / *layer_h;
            h_rate = img_org->width * 1000 / *layer_w;
            if (v_rate < h_rate)
            {
                height = *layer_h;
                width = *layer_h * img_org->width / img_org->height;
            }
            else
            {
                width = *layer_w;
                height = *layer_w * img_org->height / img_org->width;
            }
            img_resized->width = width;
            img_resized->height = height;
        }
        if (img_resized->width > *layer_w)
        {
            img_resized->x-= (img_resized->width - *layer_w)/2;
        }
        else
        {
            img_resized->x += (*layer_w - img_resized->width)/2;
        }
        if (img_resized->height > *layer_h)
        {
            img_resized->y -= (img_resized->height - *layer_h)/3;
        }
        else
        {
            img_resized->y += (*layer_h - img_resized->height)/2;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *    SRV_MEDIACACHE_create
 * DESCRIPTION
 *  service create function.
 * PARAMETERS
 *  configure    :  [IN]  the configuration of service.
 * RETURNS
 *  None.
 *****************************************************************************/
srv_handle srv_mediacache_create(void *run_buf, U32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 bits;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != g_mediacache_cntx_p)
    {
        
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_NOT_SUPPORT_MULT_INST);
        return NULL;
    }
    if (run_buf == NULL || length < SRV_MEDIACACHE_RUN_BUF_BASE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_PARAM_ERR ,run_buf,length);
        return NULL;
    }
    ASSERT(sizeof(srv_mediacache_cntx_struct) <= SRV_MEDIACACHE_RUN_BUF_BASE);
    /*globe setting for srv*/
    g_mediacache_cntx_p = run_buf;
    memset(g_mediacache_cntx_p, 0, sizeof(srv_mediacache_cntx_struct));
    g_mediacache_cntx_p->medialib_mark = run_buf;
    g_mediacache_cntx_p->medialib_mark_buf_length = length;
    g_mediacache_cntx_p->cache_block_start = (U8*)g_mediacache_cntx_p + sizeof(srv_mediacache_cntx_struct);
    g_mediacache_cntx_p->cache_block_current = g_mediacache_cntx_p->cache_block_start;
    g_mediacache_cntx_p->cache_block_end = (U8*)g_mediacache_cntx_p + length;
    memset(g_mediacache_cntx_p->cache_block_start, 0, (U8*)g_mediacache_cntx_p->cache_block_end - (U8*)g_mediacache_cntx_p->cache_block_start);

    /*init configuration*/
    g_mediacache_cntx_p->config.level1_width = LCD_WIDTH;
    g_mediacache_cntx_p->config.level1_height = LCD_HEIGHT;
    g_mediacache_cntx_p->config.level2_width = LCD_WIDTH / SRV_MEDIACACHE_LEVEL2_IMG_DIV;
    g_mediacache_cntx_p->config.level2_height = LCD_HEIGHT / SRV_MEDIACACHE_LEVEL2_IMG_DIV;
    g_mediacache_cntx_p->config.large_cf = SRV_MEDIACACHE_LARGE_COLOR_FORMAT;
    g_mediacache_cntx_p->config.level1_cf = SRV_MEDIACACHE_LEVEL1_COLOR_FORMAT;
    g_mediacache_cntx_p->config.level2_cf = SRV_MEDIACACHE_LEVEL2_COLOR_FORMAT;
    bits = srv_mediacache_get_bits_per_pixel(g_mediacache_cntx_p->config.level1_cf);
    g_mediacache_cntx_p->level1_buffer_size = g_mediacache_cntx_p->config.level1_width * g_mediacache_cntx_p->config.level1_height * bits / 8;
    bits = srv_mediacache_get_bits_per_pixel(g_mediacache_cntx_p->config.level2_cf);
    g_mediacache_cntx_p->level2_buffer_size = g_mediacache_cntx_p->config.level2_width * g_mediacache_cntx_p->config.level2_height * bits / 8;
    g_mediacache_cntx_p->is_schedule_timer_started = MMI_FALSE;

    g_mediacache_cntx_p->decode_method = SRV_MEDIACACHE_CACHE_METHOD_DEFAULT;
    g_mediacache_cntx_p->decoding_p = NULL;
    g_mediacache_cntx_p->prev_first = MMI_FALSE;
    g_mediacache_cntx_p->large_p = NULL;
    g_mediacache_cntx_p->level1_curr_p = NULL;
    g_mediacache_cntx_p->level2_curr_p = NULL;
    g_mediacache_cntx_p->level1_free_p = NULL;
    g_mediacache_cntx_p->level2_free_p = NULL;
    g_mediacache_cntx_p->is_srv_first_start = MMI_TRUE;
    g_mediacache_cntx_p->engine.get_file_name = srv_mediacache_decode_get_filename_by_index;
    g_mediacache_cntx_p->engine.decode_cell = srv_mediacache_engine_gdi_nb_decode;
    g_mediacache_cntx_p->engine.cancel_decode_cell = srv_mediacache_engine_gdi_nb_decode_cancel;
    g_mediacache_cntx_p->pre_decode_cb = NULL;
    g_mediacache_cntx_p->engine.decode_cell_blocking = srv_mediacache_engine_gdi_blocking_decode;
    g_mediacache_cntx_p->engine.set_clip = srv_mediacache_engine_set_clip;

    g_mediacache_cntx_p->qulity = SRV_MEDIACACHE_RESIZE_QULITY_DEFAULT;
    g_mediacache_cntx_p->is_waiting_resume = MMI_FALSE;
    g_mediacache_cntx_p->db_failed_query_count = 0;
    g_mediacache_cntx_p->db_store_cache_group = SRV_MEDIACACHE_CACHE_TYPE_L2;
    g_mediacache_cntx_p->color_format = GDI_LCD->cf;
    g_mediacache_cntx_p->bytes_per_pixel = SRV_MEDIACACHE_BYTES_PER_PIXEL;
#if defined(__SQLITE3_SUPPORT__)
    g_mediacache_cntx_p->db_handle.color_format = g_mediacache_cntx_p->color_format;
    g_mediacache_cntx_p->db_handle.bytes_per_pixel = g_mediacache_cntx_p->bytes_per_pixel;
#endif

    g_mediacache_cntx_p->locked_cell_p = NULL;
    g_mediacache_cntx_p->userdef_db_io_buffer_length = 0;
    g_mediacache_cntx_p->last_source = SRV_MEDIACACHE_ERR_UNKNOW;
    g_mediacache_cntx_p->is_blocking_get_first = MMI_FALSE;
    g_mediacache_cntx_p->events_getfilename_err.error_code = 0;
    g_mediacache_cntx_p->work_mode = SRV_MEDIACACHE_WORKMODE_FILELIST;
    
    /* by Wenyan */
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
    g_mediacache_cntx_p->db_handle.io_buf.max_length = SRV_MEDIACACHE_DB_IO_BUF_SIZE;
    ivd_ivsrv_db_enable_get_cancel_put(&g_mediacache_cntx_p->db_handle,MMI_TRUE);
#endif
    g_mediacache_cntx_p->db_save_is_timer_start = MMI_FALSE;
    g_mediacache_cntx_p->db_save_count = 0;
    g_mediacache_cntx_p->db_save_decode_count = 0;
    g_mediacache_cntx_p->is_using_ies = MMI_FALSE;
    g_mediacache_cntx_p->is_using_meta = MMI_FALSE;  
    g_mediacache_cntx_p->is_meta_using_db = MMI_FALSE;
    g_mediacache_cntx_p->is_align_cache = MMI_FALSE;
    g_mediacache_cntx_p->is_put_meta_urgent = MMI_FALSE;
    g_mediacache_cntx_p->ies_render_buffer = NULL;
    g_mediacache_cntx_p->ies_meta_p = NULL;    
    
    srv_mediacache_engine_init();
    g_mediacache_cntx_p->state  = SRV_MEDIACACHE_STATE_INITED;
    return (srv_handle)g_mediacache_cntx_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_destory
 * DESCRIPTION
 *  image viewer 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mediacache_destroy(srv_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cntx_struct *medialib_cntx_p = (srv_mediacache_cntx_struct *)handle;
    SRV_MEDIACACHE_MEAS_DEC(m_stop);
    SRV_MEDIACACHE_MEAS_DEC(m_db_stop);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_MEDIACACHE_MEAS_START(m_stop);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_CT_DESTORY);
    ASSERT((srv_mediacache_cntx_struct*)medialib_cntx_p->medialib_mark == medialib_cntx_p);
    ASSERT(medialib_cntx_p->state == SRV_MEDIACACHE_STATE_INITED);
    SRV_MEDIACACHE_MEAS_START(m_db_stop);
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
    if (NULL != g_mediacache_cntx_p->config.db_buf)
    {
        srv_mediacache_stop_db();
    }
#endif
    SRV_MEDIACACHE_MEAS_STOP(m_db_stop);
    medialib_cntx_p->state = SRV_MEDIACACHE_STATE_UNINITED;
    medialib_cntx_p->medialib_mark = NULL;
    SRV_MEDIACACHE_MEAS_STOP(m_stop);
#ifdef __MM_DEBUG_MEASURE_SRVMC__
        kal_print_string_trace(
            MOD_MMI_MEDIA_APP, 
            MMI_MEDIA_TRC_G2_APP, 
            "[srvmc]meas destory [%d] db_destory[%d]", 
            m_stop,m_db_stop);
#endif
    g_mediacache_cntx_p = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cache_get_control_block
 * DESCRIPTION
 *  add a cache to image viewer SRV
 * PARAMETERS
 *  type    [IN]    type of the cache
 *  *buffer [IN]    buffer pointer
 *  length  [IN]    the length of the buffer
 * RETURNS
 *  void
 *****************************************************************************/
srv_mediacache_cell_struct *srv_mediacache_cache_get_control_block(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *cell_p;
    U32 m_size;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m_size = sizeof(srv_mediacache_cell_struct);
    cell_p = (srv_mediacache_cell_struct*)g_mediacache_cntx_p->cache_block_current;
    if ((U8*)cell_p <= (U8*)g_mediacache_cntx_p->cache_block_end - m_size)
    {
        if (cell_p->next == NULL && cell_p->prev == NULL && cell_p->buffer == NULL)
        {
            g_mediacache_cntx_p->cache_block_current = (U8*)cell_p + m_size;
            return cell_p;
        }
    }

    cell_p = (srv_mediacache_cell_struct*)g_mediacache_cntx_p->cache_block_start;
    while ((U8*)cell_p <= (U8*)g_mediacache_cntx_p->cache_block_end - m_size)
    {
        if (cell_p->next == NULL && cell_p->prev == NULL && cell_p->buffer == NULL)
        {
            g_mediacache_cntx_p->cache_block_current = (U8*)cell_p;
            return cell_p;
        }
        cell_p++;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cache_get_control_block
 * DESCRIPTION
 *  add a cache to image viewer SRV
 * PARAMETERS
 *  type    [IN]    type of the cache
 *  *buffer [IN]    buffer pointer
 *  length  [IN]    the length of the buffer
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mediacache_cache_free_control_block(srv_mediacache_cell_struct *cell_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT((U8*)cell_p >= (U8*)g_mediacache_cntx_p->cache_block_start);
    ASSERT((U8*)cell_p < (U8*)g_mediacache_cntx_p->cache_block_end);
    cell_p->next = NULL;
    cell_p->prev = NULL;
    cell_p->buffer = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cache_add
 * DESCRIPTION
 *  add a cache to image viewer SRV
 * PARAMETERS
 *  type    [IN]    type of the cache
 *  *buffer [IN]    buffer pointer
 *  length  [IN]    the length of the buffer
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mediacache_cache_add_internal_one(srv_mediacache_cache_type_enum type, void *buffer, U32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *cell_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cell_p = srv_mediacache_cache_get_control_block();
    ASSERT(cell_p != NULL);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_RESET_CELL_LINE, __LINE__);
    srv_mediacache_cache_reset_cell(cell_p, MMI_TRUE);
    cell_p->buffer = buffer;
    cell_p->type = type;
    
    switch (cell_p->type)
    {
    case SRV_MEDIACACHE_CACHE_TYPE_LARGE:
        ASSERT(length > 0);
        ASSERT(g_mediacache_cntx_p->large_p == NULL);
        g_mediacache_cntx_p->large_p = cell_p;
        g_mediacache_cntx_p->large_buffer_size = length;
        if (g_mediacache_cntx_p->level1_curr_p != NULL)
        {
            g_mediacache_cntx_p->large_p->file_index = g_mediacache_cntx_p->level1_curr_p->file_index;
        }
        else if (g_mediacache_cntx_p->level2_curr_p != NULL)
        {
            g_mediacache_cntx_p->large_p->file_index = g_mediacache_cntx_p->level2_curr_p->file_index;
        }
        break;
    case SRV_MEDIACACHE_CACHE_TYPE_L1:
        ASSERT(0 != g_mediacache_cntx_p->level1_buffer_size);
        ASSERT(length >= g_mediacache_cntx_p->level1_buffer_size);
        /*Add new free one to the end of free list*/
        if (g_mediacache_cntx_p->level1_free_p != NULL)
        {
            srv_mediacache_link_add_to_head(g_mediacache_cntx_p->level1_free_p, cell_p);
        }
        g_mediacache_cntx_p->level1_free_p = cell_p;
        break;
    case SRV_MEDIACACHE_CACHE_TYPE_L2:
        ASSERT(0 != g_mediacache_cntx_p->level2_buffer_size);
        /*Add new free one to the end of free list*/
        if (g_mediacache_cntx_p->level2_free_p != NULL)
        {
            srv_mediacache_link_add_to_head(g_mediacache_cntx_p->level2_free_p, cell_p);
        }
        g_mediacache_cntx_p->level2_free_p = cell_p;
        break;
    default:
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_cache_add
 * DESCRIPTION
 *  add a cache to image viewer SRV
 * PARAMETERS
 *  type    [IN]    type of the cache
 *  *buffer [IN]    buffer pointer
 *  length  [IN]    the length of the buffer
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_mediacache_add_cache(srv_handle handle, srv_mediacache_cache_type_enum type, void *buffer, U32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 buf_p;
    U32 cell_buffer_length = 0, i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT (g_mediacache_cntx_p->state != SRV_MEDIACACHE_STATE_RUNNING);
    if (NULL == buffer)
    {
        return SRV_MEDIACACHE_ERR_NOT_SUPPORT;
    }
    buf_p = buffer;
    
    if(g_mediacache_cntx_p->is_align_cache)
    {
        buf_p = (PS8)(((U32)(buf_p + 31) / 32) * 32); /*32 bytes align*/
        length -= (buf_p - (PS8)buffer);
    }
    else
    {
        while (((U32)buf_p & 0x03) != 0) /*4 bytes align*/
        {
            buf_p = (S8*)buf_p + 1;
            length--;
        }
    }
        
    switch (type)
    {
    case SRV_MEDIACACHE_CACHE_TYPE_LARGE:
        g_mediacache_cntx_p->large_buffer_size = length;
        cell_buffer_length = length;
        srv_mediacache_cache_add_internal_one(type, buf_p,cell_buffer_length);
        break;
    case SRV_MEDIACACHE_CACHE_TYPE_L1:
        cell_buffer_length = g_mediacache_cntx_p->level1_buffer_size;
        break;
    case SRV_MEDIACACHE_CACHE_TYPE_L2:
        cell_buffer_length = g_mediacache_cntx_p->level2_buffer_size;
        break;
    default:
        ASSERT(0);
    }
    ASSERT(length != 0);
    ASSERT(cell_buffer_length != 0);
    if(g_mediacache_cntx_p->is_align_cache)
    {
        cell_buffer_length = ((cell_buffer_length + 31) / 32) * 32; /*32 bytes align*/
    }
    else
    {
        while ((cell_buffer_length & 0x03) != 0)/*4 bytes align*/
        {
            cell_buffer_length++;
        }
    }
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_ADD_CACHE, type, length, buffer);
    for (i=0 ; i<SRV_MEDIACACHE_BUF_ADD_TIMES_MAX ; i++)
    {
        if (g_mediacache_cntx_p->buffers[i].buffer == NULL)
        {
            g_mediacache_cntx_p->buffers[i].buffer = buffer;
            g_mediacache_cntx_p->buffers[i].length = length;
            break;
        }
    }

    if (g_mediacache_cntx_p->is_using_ies)
    {
        if (type == SRV_MEDIACACHE_CACHE_TYPE_L1)
        {
            if (g_mediacache_cntx_p->ies_render_buffer == NULL)
            {
                g_mediacache_cntx_p->ies_render_buffer = buf_p;
                buf_p += cell_buffer_length;
                length -= cell_buffer_length;
            }
        }
    }
    
    if (type != SRV_MEDIACACHE_CACHE_TYPE_LARGE)
    {
        while (length >= cell_buffer_length)
        {
            srv_mediacache_cache_add_internal_one(type, buf_p,cell_buffer_length);
            buf_p += cell_buffer_length;
            length -= cell_buffer_length;
        }
    }
    return SRV_MEDIACACHE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_remove_cache
 * DESCRIPTION
 *  remove a cache from IVSRV
 * PARAMETERS
 *  *buffer   [IN]  buffer pointer
 * RETURNS
 *  error code
 *****************************************************************************/
S32 srv_mediacache_remove_cache(srv_handle handle, void *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *cell_p;
    U32 i, length = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mediacache_cntx_p->large_p != NULL)
    {
        if (g_mediacache_cntx_p->large_p->buffer == buffer)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_RESET_CELL_LINE, __LINE__);
            srv_mediacache_cache_reset_cell(g_mediacache_cntx_p->large_p,MMI_TRUE);
            srv_mediacache_cache_free_control_block(g_mediacache_cntx_p->large_p);
            g_mediacache_cntx_p->large_p = NULL;
            return SRV_MEDIACACHE_OK;
        }
    }
    ASSERT (g_mediacache_cntx_p->state != SRV_MEDIACACHE_STATE_RUNNING);
    cell_p = (srv_mediacache_cell_struct*)g_mediacache_cntx_p->cache_block_start;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_REMOVE_CACHE, buffer);
    for (i=0 ; i<SRV_MEDIACACHE_BUF_ADD_TIMES_MAX ; i++)
    {
        if (g_mediacache_cntx_p->buffers[i].buffer == buffer)
        {
            length = g_mediacache_cntx_p->buffers[i].length;
            memset(&g_mediacache_cntx_p->buffers[i],0,sizeof(srv_mediacache_buffers_struct));
            break;
        }
    }
    while ((U8*)cell_p <= (U8*)g_mediacache_cntx_p->cache_block_end - sizeof(srv_mediacache_cell_struct))
    {
        if ((cell_p->next != NULL || cell_p->prev != NULL) && 
            (cell_p->buffer >= (U8*)buffer && cell_p->buffer < (U8*)buffer + length))
        {
            if (cell_p->next != NULL)
            {
                cell_p->next->prev = cell_p->prev;
            }
            if (cell_p->prev != NULL)
            {
                cell_p->prev->next = cell_p->next;
            }
            if (g_mediacache_cntx_p->level1_free_p == cell_p)
            {
                g_mediacache_cntx_p->level1_free_p = cell_p->next;
            }
            if (g_mediacache_cntx_p->level2_free_p == cell_p)
            {
                g_mediacache_cntx_p->level2_free_p = cell_p->next;
            }
            if (g_mediacache_cntx_p->level1_curr_p == cell_p)
            {
                g_mediacache_cntx_p->level1_curr_p = cell_p->next;
                if (NULL != g_mediacache_cntx_p->level1_curr_p)
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_RESET_CELL_LINE, __LINE__);
                    srv_mediacache_cache_reset_cell(g_mediacache_cntx_p->level1_curr_p, MMI_FALSE);
                    g_mediacache_cntx_p->level1_curr_p->file_index = cell_p->file_index;
                }
            }
            if (g_mediacache_cntx_p->level2_curr_p == cell_p)
            {
                g_mediacache_cntx_p->level2_curr_p = cell_p->next;
                if (NULL != g_mediacache_cntx_p->level2_curr_p)
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_RESET_CELL_LINE, __LINE__);
                    srv_mediacache_cache_reset_cell(g_mediacache_cntx_p->level2_curr_p, MMI_FALSE);
                    g_mediacache_cntx_p->level2_curr_p->file_index = cell_p->file_index;
                }
            }
            if (g_mediacache_cntx_p->large_p == cell_p)
            {
                g_mediacache_cntx_p->large_p = NULL;
            }
            srv_mediacache_cache_free_control_block(cell_p);
        }
        else if (cell_p->buffer >= (U8*)buffer && cell_p->buffer < (U8*)buffer + length)
        {
            if (g_mediacache_cntx_p->level1_free_p == cell_p)
            {
                g_mediacache_cntx_p->level1_free_p = NULL;
            }
            else if (g_mediacache_cntx_p->level2_free_p == cell_p)
            {
                g_mediacache_cntx_p->level2_free_p = NULL;
            }
            else if (g_mediacache_cntx_p->level1_curr_p == cell_p)
            {
                g_mediacache_cntx_p->level1_curr_p = NULL;
            }
            else if (g_mediacache_cntx_p->level2_curr_p == cell_p)
            {
                g_mediacache_cntx_p->level2_curr_p = NULL;
            }
            else if (g_mediacache_cntx_p->large_p == cell_p)
            {
                g_mediacache_cntx_p->large_p = NULL;
            }
            srv_mediacache_cache_free_control_block(cell_p);
        }
        cell_p++;
    }
    return SRV_MEDIACACHE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_switch_next
 * DESCRIPTION
 *  move the image to left
 * PARAMETERS
 *  void
 * RETURNS
 *  error code
 *****************************************************************************/
S32 srv_mediacache_switch_next(srv_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 err_code = SRV_MEDIACACHE_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&g_mediacache_cntx_p->start_ticks);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_CT_SWITCH_NEXT);
    SRV_MEDIACACHE_CACHE_PRINT_DBGTRACE();
    g_mediacache_cntx_p->app_data_cb = NULL;
    g_mediacache_cntx_p->cb_file_idx = SRV_MEDIACACHE_DUMMY_FILE_IDX;
    SRV_MEDIACACHE_CB_CHANGED();

#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_CANCEL_DECODE_CELL_AT_D, __LINE__);
    g_mediacache_cntx_p->engine.cancel_decode_cell(g_mediacache_cntx_p->image_hdl_decoding);
    g_mediacache_cntx_p->image_hdl_decoding = 0;
    g_mediacache_cntx_p->decoding_p = NULL;
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_DECODING_P_IS_NULL_D, __LINE__);
#endif

#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
    srv_mediacache_delete_image_handle_if_needed(g_mediacache_cntx_p->level1_curr_p);
#endif

    ASSERT(g_mediacache_cntx_p->state == SRV_MEDIACACHE_STATE_RUNNING || g_mediacache_cntx_p->state == SRV_MEDIACACHE_STATE_PAUSED);
    g_mediacache_cntx_p->level1_curr_p = srv_mediacache_link_roll_next(g_mediacache_cntx_p->level1_curr_p, &g_mediacache_cntx_p->level1_first_p);
    g_mediacache_cntx_p->level2_curr_p = srv_mediacache_link_roll_next(g_mediacache_cntx_p->level2_curr_p, &g_mediacache_cntx_p->level2_first_p);

#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
    srv_mediacache_create_image_handle_if_needed(g_mediacache_cntx_p->level1_curr_p);
#endif

    if (NULL != g_mediacache_cntx_p->large_p)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_RESET_CELL_LINE, __LINE__);
        srv_mediacache_cache_reset_cell(g_mediacache_cntx_p->large_p, MMI_FALSE);
        if (NULL != g_mediacache_cntx_p->level1_curr_p)
        {
            g_mediacache_cntx_p->large_p->file_index = g_mediacache_cntx_p->level1_curr_p->file_index;
        }
        else
        {
            ASSERT(NULL != g_mediacache_cntx_p->level2_curr_p);
            g_mediacache_cntx_p->large_p->file_index = g_mediacache_cntx_p->level2_curr_p->file_index;
        }
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_AFTER_OP);
    SRV_MEDIACACHE_CACHE_PRINT_DBGTRACE();
    if (g_mediacache_cntx_p->decoding_p == NULL && g_mediacache_cntx_p->searching_p == NULL)
    {
        srv_mediacache_check_and_start_decode();  
    }
    kal_get_time(&g_mediacache_cntx_p->end_ticks);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_SWITCH_NEXT_TIKCS,g_mediacache_cntx_p->end_ticks - g_mediacache_cntx_p->start_ticks);
    return err_code;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_switch_prev
 * DESCRIPTION
 *  move the image to right
 * PARAMETERS
 *  void
 * RETURNS
 *  error code
 *****************************************************************************/
S32 srv_mediacache_switch_prev(srv_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 err_code = SRV_MEDIACACHE_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&g_mediacache_cntx_p->start_ticks);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_CT_SWITCH_PREV);
    SRV_MEDIACACHE_CACHE_PRINT_DBGTRACE();
    g_mediacache_cntx_p->app_data_cb = NULL;
    g_mediacache_cntx_p->cb_file_idx = SRV_MEDIACACHE_DUMMY_FILE_IDX;
    SRV_MEDIACACHE_CB_CHANGED();
    ASSERT(g_mediacache_cntx_p->state == SRV_MEDIACACHE_STATE_RUNNING || g_mediacache_cntx_p->state == SRV_MEDIACACHE_STATE_PAUSED);
    if (g_mediacache_engine_cntx.file_count <= 1)
    {
        return SRV_MEDIACACHE_OK;
    }

    /*process decoding one*/
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_CANCEL_DECODE_CELL_AT_D, __LINE__);
    g_mediacache_cntx_p->engine.cancel_decode_cell(g_mediacache_cntx_p->image_hdl_decoding);
    g_mediacache_cntx_p->image_hdl_decoding = 0;
    g_mediacache_cntx_p->decoding_p = NULL;
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_DECODING_P_IS_NULL_D, __LINE__);
#endif

#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
    srv_mediacache_delete_image_handle_if_needed(g_mediacache_cntx_p->level1_curr_p);
#endif
    g_mediacache_cntx_p->level1_curr_p = srv_mediacache_link_roll_prev(g_mediacache_cntx_p->level1_curr_p, &g_mediacache_cntx_p->level1_first_p);
    g_mediacache_cntx_p->level2_curr_p = srv_mediacache_link_roll_prev(g_mediacache_cntx_p->level2_curr_p, &g_mediacache_cntx_p->level2_first_p);

#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
    srv_mediacache_create_image_handle_if_needed(g_mediacache_cntx_p->level1_curr_p);
#endif

    if (NULL != g_mediacache_cntx_p->large_p)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_RESET_CELL_LINE, __LINE__);
        srv_mediacache_cache_reset_cell(g_mediacache_cntx_p->large_p, MMI_FALSE);
        if (NULL != g_mediacache_cntx_p->level1_curr_p)
        {
            g_mediacache_cntx_p->large_p->file_index = g_mediacache_cntx_p->level1_curr_p->file_index;
        }
        else
        {
            ASSERT(NULL != g_mediacache_cntx_p->level2_curr_p);
            g_mediacache_cntx_p->large_p->file_index = g_mediacache_cntx_p->level2_curr_p->file_index;
        }
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_AFTER_OP);
    SRV_MEDIACACHE_CACHE_PRINT_DBGTRACE();
    if (g_mediacache_cntx_p->decoding_p == NULL && g_mediacache_cntx_p->searching_p == NULL)
    {
        srv_mediacache_check_and_start_decode();  
    }
    kal_get_time(&g_mediacache_cntx_p->end_ticks);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_SWITCH_PREV_TIKCS,g_mediacache_cntx_p->end_ticks - g_mediacache_cntx_p->start_ticks);
    return err_code;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_get_last_err
 * DESCRIPTION
 *  get last error code and group index
 * PARAMETERS
 *  *err_group  [OUT]   pointer to error group let SRV write
 *  *err_code   [OUT]   pointer to error code let SRV write
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mediacache_get_last_err(srv_handle handle, S32 *err_group, S32 *err_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *err_group  = g_mediacache_cntx_p->last_err_grp;
    *err_code   = g_mediacache_cntx_p->last_err_code;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_register_pre_pre_decode_cb
 * DESCRIPTION
 *  will call the callback function before every pre-cache
 * PARAMETERS
 *  decode_callback     [IN]    decode callback
 *
 *  return of callback function
 *  MMI_FALSE   decode will continue
 *  MMI_TRUE    means user will cancel the decode process of this one
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mediacache_register_pre_decode_cb(srv_handle handle, srv_mediacache_pre_decode_cb callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mediacache_cntx_p->pre_decode_cb = callback;
}

void srv_mediacache_register_filename_cb(srv_handle handle,srv_mediacache_get_filename_cb callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mediacache_cntx_p->engine.get_file_name = callback;
}

void srv_mediacache_register_events_cb(srv_handle handle,srv_mediacache_events_cb callback,void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mediacache_cntx_struct *medialib_cntx_p = (srv_mediacache_cntx_struct *)handle;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(handle == medialib_cntx_p->medialib_mark);
    medialib_cntx_p->events_callback = callback;
    medialib_cntx_p->events_callback_user_data = user_data;
}

MMI_ID_TYPE srv_mediacache_get_err_string(srv_handle handle, S32 err_group,S32 err_code, mmi_event_notify_enum* popup_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE string_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *popup_type = MMI_EVENT_FAILURE;
    switch(err_group)
    {

    case SRV_MEDIACACHE_ERR_GROUP_MEDIACACHE:
        break;
    case SRV_MEDIACACHE_ERR_GROUP_GDI:
        break;
    case SRV_MEDIACACHE_ERR_GROUP_FS:
        string_id = srv_fmgr_fs_error_get_string(err_code);
        break;
    case SRV_MEDIACACHE_ERR_GROUP_OK:
        break;
    default:
        break;
    }
    return string_id;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_register_pre_pre_decode_cb
 * DESCRIPTION
 *  will call the callback function before every pre-cache
 * PARAMETERS
 *  decode_callback     [IN]    decode callback
 *
 *  return of callback function
 *  MMI_FALSE   decode will continue
 *  MMI_TRUE    means user will cancel the decode process of this one
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mediacache_calc_h_w_by_image_and_length(S32 index, U32 buf_length, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct cell;
    srv_mediacache_cell_struct *cell_p = NULL;
    S32 img_width, img_height;
    S32 result, ret;
    CHAR *error_str;
    MMI_BOOL is_fmgr_pass;
    WCHAR *filename_p;
    CHAR  filename[SRV_FMGR_PATH_BUFFER_SIZE];
    MMI_BOOL is_can_draw = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *width = -1;
    *height = -1;
    cell_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->large_p,MMI_FALSE,srv_mediacache_is_index_match, &index);

    if (g_mediacache_cntx_p->is_using_ies)
    {
        is_can_draw = srv_mediacache_cache_cell_finished2(cell_p);
        
        if (MMI_FALSE == is_can_draw)
        {
            cell_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
            is_can_draw = srv_mediacache_cache_cell_finished2(cell_p);
        }
        
        if (MMI_FALSE == is_can_draw)
        {
            cell_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level2_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
            is_can_draw = srv_mediacache_cache_cell_finished2(cell_p);
        }

    }
    else
    {
        is_can_draw = srv_mediacache_cache_cell_finished(cell_p);
        if (MMI_FALSE == is_can_draw)
        {
            cell_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
            is_can_draw = srv_mediacache_cache_cell_finished(cell_p);
        }
        
        if (MMI_FALSE == is_can_draw)
        {
            cell_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level2_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
            is_can_draw = srv_mediacache_cache_cell_finished(cell_p);
        }
    }
    
    if (MMI_FALSE == is_can_draw)
    {
        cell.image_width = -1;
        cell.image_height = -1;

        if (NULL != g_mediacache_cntx_p->engine.get_file_name)
        {
            ret = g_mediacache_cntx_p->engine.get_file_name(index, (U16*)filename, SRV_FMGR_PATH_BUFFER_SIZE, NULL);
            if (ret < 0)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_GET_NAME_FAILED,ret, __LINE__);
                return;
            }
        }
        filename_p = (WCHAR*)filename;
        is_fmgr_pass = srv_mediacache_file_limit_check(filename_p , &error_str);
        if (is_fmgr_pass == MMI_TRUE)
        {
            SRV_MEDIACACHE_START_MEASURE("FU3");
                result = gdi_imgdec_get_dimension_file((CHAR*)filename_p, &img_width, &img_height);
            if (result < 0)
            {
                    result = gdi_image_get_dimension_file((CHAR*)filename_p, &img_width, &img_height);
            }
            SRV_MEDIACACHE_STOP_MEASURE("FU3");
            if (result >= 0 && img_width <= SRV_MEDIACACHE_DECODE_MAX_W_H && img_height <= SRV_MEDIACACHE_DECODE_MAX_W_H)
            {
                SRV_MEDIACACHE_START_MEASURE("GDG");
                    cell.image_type = gdi_image_get_type_from_file((CHAR*)filename_p);
                SRV_MEDIACACHE_STOP_MEASURE("GDG");
                srv_mediacache_cache_fill_cell_by_img_and_length(buf_length, img_width, img_height,&cell);
            }
        }
    }
    else
    {
        img_width = cell_p->org_image_width;
        img_height = cell_p->org_image_height;
        memcpy(&cell,cell_p,sizeof(srv_mediacache_cell_struct));
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_META_SET_META_JOB_HANDLE_TO_NULL_FILE_INDEX_D_D, cell_p->file_index, __LINE__);
        
        //do not know what he does, so I remove this code
        cell.type = SRV_MEDIACACHE_CACHE_TYPE_LARGE;
        cell.image_type = GDI_IMAGE_TYPE_BMP;
        srv_mediacache_cache_fill_cell_by_img_and_length(buf_length, img_width, img_height,&cell);
    }
    *width = cell.image_width;
    *height = cell.image_height;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_enable_clear_bg
 * DESCRIPTION
 *  let SRV clear bg or not
 * PARAMETERS
 *  enable     [IN]    switch
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mediacache_enable_clear_bg(MMI_BOOL enable, gdi_color color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mediacache_cntx_p->is_srv_clear_bg = enable;
    g_mediacache_cntx_p->bg_color = color;
}

    
/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_decode_level2_default_method
 * DESCRIPTION
 *  find unfinished cell of previous or next at group 2
 * PARAMETERS
 *  void
 * RETURNS
 *  NULL or the pointer to the unfinished cell
 *****************************************************************************/
static MMI_BOOL srv_mediacache_is_buffer_match(srv_mediacache_cell_struct* curr_p, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *buffer = *((U8**)user_data);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (curr_p->buffer == buffer)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_switch_prev
 * DESCRIPTION
 *  move the image to right
 * PARAMETERS
 *  void
 * RETURNS
 *  error code
 *****************************************************************************/
MMI_BOOL srv_mediacache_get_num_and_direct_by_index(srv_mediacache_cell_struct *curr_p, S32 file_index, S32 *steps, MMI_BOOL *is_roll_right)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *next_p;
    srv_mediacache_cell_struct *prev_p;
    MMI_BOOL is_found = MMI_FALSE;
    S32  i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    next_p = curr_p;
    prev_p = curr_p;
    while (NULL != next_p || NULL != prev_p)
    {
        if (NULL != next_p)
        {
            if (next_p->file_index == file_index)
            {
                *is_roll_right = MMI_TRUE;
                break;
            }
            next_p = next_p->next;
        }
        if (NULL != prev_p)
        {
            if (prev_p->file_index == file_index)
            {
                *is_roll_right = MMI_FALSE;
                break;
            }
            prev_p = prev_p->prev;
        }
        i++;
    }
    *steps = i;
    if (NULL != next_p || NULL != prev_p)
    {
        is_found = MMI_TRUE;
    }
    return is_found;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_check_and_move_locked_cell
 * DESCRIPTION
 *  move all locked cell from L1/L2 list to locked list,
 *  and choose a new current_p from remain L1/L2 cells
 * PARAMETERS
 *  first_pp    [IN/OUT] pointer to beginning of L1/L2 list, may be updated if it is locked
 *  curr_pp     [IN/OUT] pointer to new current cell. may be NULL if no unlocked cells available in first_pp list
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mediacache_check_and_move_locked_cell(srv_handle handle, srv_mediacache_cell_struct **first_pp, srv_mediacache_cell_struct **curr_pp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *itr_p = NULL;
    srv_mediacache_cell_struct *next_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == first_pp || NULL == curr_pp)
    {
        return;
    }

    // extra check to ensure first_pp is valid (must have valid list start)
    itr_p = srv_mediacache_link_get_first(*curr_pp);
    if (NULL == *first_pp)
    {
        *first_pp = itr_p;
    }

    // starting from 1st cell,
    // check if any cell is locked.
    // if locked, move to locked list.
    next_p = itr_p;
    while (NULL != next_p)
    {
        itr_p = next_p;
        next_p = itr_p->next;
        if (MMI_TRUE == itr_p->is_lock)
        {
            // remove locked cell from L1/L2 list
            srv_mediacache_link_remove_cell(*first_pp, itr_p);

            // 1st L1/L2 is locked, update to next L1/L2 cell
            if (*first_pp == itr_p)
            {
                *first_pp = next_p;
            }
            
            // then, put locked cell to global locked list
            if (NULL == g_mediacache_cntx_p->locked_cell_p)
            {
                g_mediacache_cntx_p->locked_cell_p = itr_p;
            }
            else
            {
                srv_mediacache_link_add_to_end(g_mediacache_cntx_p->locked_cell_p, itr_p);
            }
        }
    }

    // finally, find an unlocked cell from L1/L2 list and
    // assign it as curr_p
    // note: both *first_pp and *curr_pp can be NULL.
    *curr_pp = srv_mediacache_link_get_center(*first_pp);
}

/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_switch_by_get_to_buffer
 * DESCRIPTION
 *  update current image to locked index
 * PARAMETERS
 *  void
 * RETURNS
 *  error code
 *****************************************************************************/
static void srv_mediacache_switch_by_get_to_buffer(srv_handle handle, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 steps;
    MMI_BOOL  is_roll_right = MMI_FALSE;
    MMI_BOOL  is_found;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&g_mediacache_cntx_p->start_ticks);
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_CT_SWITCH_PREV);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_SWITCH_BY_GET);
    SRV_MEDIACACHE_CACHE_INDEX_PRINT_DBGTRACE();
    is_found = srv_mediacache_get_num_and_direct_by_index(g_mediacache_cntx_p->level1_curr_p, index, &steps, &is_roll_right);
    if (MMI_FALSE == is_found)
    {
        is_found = srv_mediacache_get_num_and_direct_by_index(g_mediacache_cntx_p->level2_curr_p, index, &steps, &is_roll_right);
    }
    if (MMI_FALSE == is_found)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_FILL_INDEX);

        // move all locked cell from L1/L2 list to locked list,
        // and choose a new current_p from remain L1/L2 cells
        srv_mediacache_check_and_move_locked_cell(handle,
                                                  &g_mediacache_cntx_p->level1_first_p,
                                                  &g_mediacache_cntx_p->level1_curr_p);
        srv_mediacache_check_and_move_locked_cell(handle,
                                                  &g_mediacache_cntx_p->level2_first_p,
                                                  &g_mediacache_cntx_p->level2_curr_p);
        
        // update cell's index
        srv_mediacache_cache_fill_index_to_link(
            g_mediacache_cntx_p->level1_curr_p, 
            index, 
            g_mediacache_engine_cntx.file_count);
        srv_mediacache_cache_fill_index_to_link(
            g_mediacache_cntx_p->level2_curr_p, 
            index, 
            g_mediacache_engine_cntx.file_count);
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_ROLL_AND_DIRECT, steps, is_roll_right);
        SRV_MEDIACACHE_LINK_ASSERT_NO_RING(g_mediacache_cntx_p->level2_curr_p);
        SRV_MEDIACACHE_CACHE_INDEX_PRINT_DBGTRACE();
        if (MMI_TRUE == is_roll_right)
        {
            while (steps > 0)
            {

                g_mediacache_cntx_p->level1_curr_p = srv_mediacache_link_roll_next(g_mediacache_cntx_p->level1_curr_p, &g_mediacache_cntx_p->level1_first_p);
                g_mediacache_cntx_p->level2_curr_p = srv_mediacache_link_roll_next(g_mediacache_cntx_p->level2_curr_p, &g_mediacache_cntx_p->level2_first_p);
                SRV_MEDIACACHE_LINK_ASSERT_NO_RING(g_mediacache_cntx_p->level2_curr_p);
                SRV_MEDIACACHE_CACHE_INDEX_PRINT_DBGTRACE();
                steps--;
            }
        }
        else
        {
            while (steps > 0)
            {

                g_mediacache_cntx_p->level1_curr_p = srv_mediacache_link_roll_prev(g_mediacache_cntx_p->level1_curr_p, &g_mediacache_cntx_p->level1_first_p);
                g_mediacache_cntx_p->level2_curr_p = srv_mediacache_link_roll_prev(g_mediacache_cntx_p->level2_curr_p, &g_mediacache_cntx_p->level2_first_p);
                SRV_MEDIACACHE_LINK_ASSERT_NO_RING(g_mediacache_cntx_p->level2_curr_p);
                SRV_MEDIACACHE_CACHE_INDEX_PRINT_DBGTRACE();
                steps--;
            }
        }
    }
    /*process decoding one*/
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
    if (MMI_FALSE == is_found)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_CANCEL_DECODE_CELL_AT_D, __LINE__);
        g_mediacache_cntx_p->engine.cancel_decode_cell(g_mediacache_cntx_p->image_hdl_decoding);
        g_mediacache_cntx_p->image_hdl_decoding = 0;
        g_mediacache_cntx_p->decoding_p = NULL;
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_DECODING_P_IS_NULL_D, __LINE__);
    }
#endif
    if (NULL != g_mediacache_cntx_p->large_p)
    {
        if (NULL != g_mediacache_cntx_p->level1_curr_p)
        {
            index = g_mediacache_cntx_p->level1_curr_p->file_index;
        }
        else
        {
            if (NULL != g_mediacache_cntx_p->level2_curr_p)
            {
                index = g_mediacache_cntx_p->level2_curr_p->file_index;
            }
        }
        if (g_mediacache_cntx_p->large_p->file_index != index)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_RESET_CELL_LINE, __LINE__);
            srv_mediacache_cache_reset_cell(g_mediacache_cntx_p->large_p, MMI_FALSE);
            g_mediacache_cntx_p->large_p->file_index = index;
        }
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_AFTER_OP);
    SRV_MEDIACACHE_CACHE_INDEX_PRINT_DBGTRACE();
    if (g_mediacache_cntx_p->decoding_p == NULL && g_mediacache_cntx_p->searching_p == NULL)
    {
        srv_mediacache_check_and_start_decode();  
    }
    kal_get_time(&g_mediacache_cntx_p->end_ticks);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_SWITCH_PREV_TIKCS,g_mediacache_cntx_p->end_ticks - g_mediacache_cntx_p->start_ticks);
}


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_goto_index
 * DESCRIPTION
 *  goto a index
 * PARAMETERS
 *  handle   :  [IN]  the handle
 *  index    :  [IN]  index want to go
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mediacache_goto_index(srv_handle handle, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mediacache_switch_by_get_to_buffer(handle, index);
}



/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_get_curr_img
 * DESCRIPTION
 *  get current image to layer
 *  x,y mean offset of zoomed image, zoomfactor will div 100, 
 *  if miss it will call data_cb after decode finish.
 * PARAMETERS
 *  dest_layer  [IN]    dest layer to draw to
 *  dest_x      [IN]    offset of x according to dest
 *  dest_y      [IN]    offest of y according to dest
 *  zoomfactor  [IN]    zoom factor * 1000
 *  x           [IN]    x after zoom of org image
 *  y           [IN]    y after zoom of org image
 *  width       [IN]    width after zoom of org image
 *  height      [IN]    height after zoom of org image
 *  app_cb      [IN]    call back function of app
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_mediacache_get_img_to_layer_internal(srv_handle handle, U32 index, srv_mediacache_img_to_layer_struct *area, MMI_BOOL is_blocking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret_code = SRV_MEDIACACHE_ERR_NOT_READY;
    srv_mediacache_cell_struct *cell_level1_p = NULL;
    srv_mediacache_cell_struct *cell_found_p = NULL;
    srv_mediacache_cell_struct *cell_found_reserve_p = NULL;
    MMI_BOOL is_can_draw = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_GET_IMG_TO_LAYER, index);
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
    ivd_ivsrv_db_enable_get_cancel_put(&g_mediacache_cntx_p->db_handle,MMI_TRUE);
#endif

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_IVD_IVSRV_DB_ENABLE_GET_CANCEL_PUT);

    if (NULL != area->callback || g_mediacache_cntx_p->cb_file_idx == SRV_MEDIACACHE_DUMMY_FILE_IDX)
    {
        srv_mediacache_switch_by_get_to_buffer(handle, index);
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_CELL_FIND);

    cell_found_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->large_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
    if (NULL != cell_found_p)
    {
        cell_found_reserve_p = cell_found_p;
    }
    if (srv_mediacache_cache_cell_can_draw(cell_found_p) == MMI_FALSE)
    {
        cell_found_p = NULL;
    }
    if (NULL == cell_found_p)
    {
        cell_found_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
    }
    if (NULL != cell_found_p)
    {
        cell_found_reserve_p = cell_found_p;
    }
    if (srv_mediacache_cache_cell_can_draw(cell_found_p) == MMI_FALSE)
    {
        cell_found_p = NULL;
    }
    if (NULL == cell_found_p)
    {
        cell_found_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level2_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
    }
    if (NULL != cell_found_p)
    {
        cell_found_reserve_p = cell_found_p;
    }
    if (srv_mediacache_cache_cell_can_draw(cell_found_p) == MMI_FALSE)
    {
        cell_level1_p = cell_found_p;
        cell_found_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level2_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
    }
    if (srv_mediacache_cache_cell_can_draw(cell_found_p) == MMI_TRUE)
    {
        is_can_draw = MMI_TRUE;
    }
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
    if (MMI_TRUE != is_can_draw && 
        MMI_TRUE == is_blocking &&
        (area->source == SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE ||
        area->source == SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE_AND_DECODE))
    {
        if (cell_level1_p != NULL)
        {
            srv_mediacache_decode_by_database(cell_level1_p, MMI_TRUE);
            if (srv_mediacache_cache_cell_can_draw(cell_level1_p) == MMI_TRUE)
            {
                cell_found_p = cell_level1_p;
            }
        }
        else if (cell_found_p != NULL)
        {
            srv_mediacache_decode_by_database(cell_found_p, MMI_TRUE);
        }
        else if(NULL != cell_found_reserve_p)
        {
            srv_mediacache_decode_by_database(cell_found_reserve_p, MMI_TRUE);
        }
        else
        {
            srv_mediacache_cache_fill_index_to_link(
                g_mediacache_cntx_p->level1_curr_p, 
                index, 
                g_mediacache_engine_cntx.file_count);
            srv_mediacache_cache_fill_index_to_link(
                g_mediacache_cntx_p->level2_curr_p, 
                index, 
                g_mediacache_engine_cntx.file_count);
            cell_found_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
            if (NULL == cell_found_p)
            {
                cell_found_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level2_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
            }
            srv_mediacache_decode_by_database(cell_found_p, MMI_TRUE);
        }
    }    
    if (srv_mediacache_cache_cell_can_draw(cell_found_p) == MMI_TRUE)
    {
        is_can_draw = MMI_TRUE;
    }
#endif

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_DECODE_FROM_DB);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_BLOCKING_DECODE);

    /*source equ database then decode*/
    if (MMI_TRUE != is_can_draw &&
        MMI_TRUE == is_blocking && 
        area->source == SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE_AND_DECODE)
    {
        if (cell_level1_p != NULL)
        {
            cell_found_p = cell_level1_p;
            cell_found_p->err_code = g_mediacache_cntx_p->engine.decode_cell_blocking(cell_level1_p);
        }
        else if (cell_found_p != NULL)
        {
            cell_found_p->err_code = g_mediacache_cntx_p->engine.decode_cell_blocking(cell_found_p);
        }
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
        else if(NULL != cell_found_reserve_p)
        {
            srv_mediacache_decode_by_database(cell_found_reserve_p, MMI_TRUE);
        }
#endif
        else
        {
            srv_mediacache_cache_fill_index_to_link(
                g_mediacache_cntx_p->level1_curr_p, 
                index, 
                g_mediacache_engine_cntx.file_count);
            srv_mediacache_cache_fill_index_to_link(
                g_mediacache_cntx_p->level2_curr_p, 
                index, 
                g_mediacache_engine_cntx.file_count);
            cell_found_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
            if (NULL == cell_found_p)
            {
                cell_found_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level2_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
            }
            if (NULL == cell_found_p)
            {
                ret_code = SRV_MEDIACACHE_ERR_NOT_ENOUGH_CACHE;
            }

            else
            {
                cell_found_p->err_code = g_mediacache_cntx_p->engine.decode_cell_blocking(cell_found_p);
            }
        }
        if (NULL != cell_found_p)
        {
            if (cell_found_p->err_code < 0)
            {
                cell_found_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
            }
            else
            {
                cell_found_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_OK;
            }
        }
    }   

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_BLOCKING_DECODE);

    is_can_draw = srv_mediacache_cache_cell_can_draw(cell_found_reserve_p);
    if(MMI_FALSE == is_can_draw && NULL != cell_found_reserve_p)
    {
        ret_code = SRV_MEDIACACHE_ERR_DECODING;
        if (cell_found_reserve_p->err_code != 0 && SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR == cell_found_reserve_p->state)
        {
            ret_code = cell_found_reserve_p->err_code;
            srv_mediacache_set_last_err(cell_found_reserve_p->err_group, cell_found_reserve_p->err_code);
        }
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_RESET_CELL_IF_NEEDED);

    if (MMI_FALSE == is_blocking && MMI_FALSE == is_can_draw && NULL != area->callback)
    {
        g_mediacache_cntx_p->app_data_cb = area->callback;
        g_mediacache_cntx_p->user_data = area->user_data;
        g_mediacache_cntx_p->cb_file_idx = index;
        SRV_MEDIACACHE_CB_CHANGED();
        if (NULL == cell_level1_p && NULL == cell_found_p && NULL == cell_found_reserve_p)
        {
            srv_mediacache_cache_fill_index_to_link(
                g_mediacache_cntx_p->level1_curr_p, 
                index, 
                g_mediacache_engine_cntx.file_count);
            srv_mediacache_cache_fill_index_to_link(
                g_mediacache_cntx_p->level2_curr_p, 
                index, 
                g_mediacache_engine_cntx.file_count);
            cell_found_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
            if (NULL == cell_found_p)
            {
                cell_found_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level2_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
            }
            if (NULL == cell_found_p && NULL != g_mediacache_cntx_p->large_p)
            {
                cell_found_p = g_mediacache_cntx_p->large_p;
            }
            if (NULL == cell_found_p)
            {
                ret_code = SRV_MEDIACACHE_ERR_NOT_ENOUGH_CACHE;
                srv_mediacache_set_last_err(SRV_MEDIACACHE_ERR_GROUP_MEDIACACHE, SRV_MEDIACACHE_ERR_NOT_ENOUGH_CACHE);
            }
        }
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_RESET_CELL_IF_NEEDED);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_RESIZE2LAYER);

    if (MMI_TRUE == is_can_draw)
    {
        if (cell_found_p->type == SRV_MEDIACACHE_CACHE_TYPE_L2 || 
            cell_found_p->type == SRV_MEDIACACHE_CACHE_TYPE_L1 && g_mediacache_cntx_p->large_p != NULL)
        {
            g_mediacache_cntx_p->app_data_cb = area->callback;
            g_mediacache_cntx_p->user_data = area->user_data;
            g_mediacache_cntx_p->cb_file_idx = index;
            SRV_MEDIACACHE_CB_CHANGED();
        }
        ret_code = srv_mediacache_cache_resize2layer(cell_found_p, area);
    }
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_RESIZE2LAYER);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_GET_IMG_TO_LAYER_RET, index, ret_code);
    srv_mediacache_check_and_start_decode();
    return ret_code;
}



/*****************************************************************************
 * FUNCTION
 *    SRV_MEDIACACHE_get_img_to_buffer
 * DESCRIPTION
 *  get an area of the image to buffer with resize
 * PARAMETERS
 *  index   :  [IN]  the index of image want to get
 *  area    :  [IN]  setting of source area and destination area
 * RETURNS
 *  the error code, you can call get last err for detail error.
 *****************************************************************************/
S32 srv_mediacache_get_img_to_layer(srv_handle handle, U32 index, srv_mediacache_img_to_layer_struct *area)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret_code;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_code = srv_mediacache_get_img_to_layer_internal(handle, index, area, MMI_FALSE);
    if (ret_code == SRV_MEDIACACHE_ERR_NOT_READY)
    {
        ret_code = SRV_MEDIACACHE_ERR_DECODING;
    }
    return ret_code;
}

/*****************************************************************************
 * FUNCTION
 *    SRV_MEDIACACHE_get_img_to_buffer
 * DESCRIPTION
 *  get an area of the image to buffer with resize
 * PARAMETERS
 *  index   :  [IN]  the index of image want to get
 *  area    :  [IN]  setting of source area and destination area
 * RETURNS
 *  the error code, you can call get last err for detail error.
 *****************************************************************************/
static S32 srv_mediacache_get_img_to_buffer_internal(srv_handle handle, U32 index, void *buf, MMI_BOOL is_blocking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret_code = SRV_MEDIACACHE_ERR_NOT_READY;
    srv_mediacache_img_to_buffer_struct *buf_nb_p = (srv_mediacache_img_to_buffer_struct*)buf;
    srv_mediacache_img_to_layer_struct area;
    gdi_handle layer;
    srv_mediacache_get_img_info_struct img_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*source equ cache*/
    if (buf_nb_p->length < buf_nb_p->width * buf_nb_p->height * 2)
    {
        return SRV_MEDIACACHE_ERR_NOT_ENOUGH_CACHE;
    }
    srv_mediacache_get_image_info(handle, index, &img_info);
    area.callback = buf_nb_p->callback;
    area.user_data = buf_nb_p->user_data;
    area.source = buf_nb_p->source;
    gdi_layer_create_cf_using_outside_memory(
        g_mediacache_cntx_p->color_format,
        0,
        0,
        buf_nb_p->width,
        buf_nb_p->height,
        &layer,
        buf_nb_p->buffer,
        buf_nb_p->length);
    gdi_layer_set_source_key_nb_concurrent(layer, MMI_TRUE, GDI_COLOR_TRANSPARENT);
    area.dst_layer = layer;
    area.src.x = 0;
    area.src.y = 0;
    area.src.width = img_info.org_width;
    area.src.height = img_info.org_height;
    area.dst.x = 0;
    area.dst.y = 0;
    area.dst.width = buf_nb_p->width;
    area.dst.height = buf_nb_p->height;
    ret_code = srv_mediacache_get_img_to_layer_internal(handle, index, &area, is_blocking);
    gdi_layer_free(layer);
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *    SRV_MEDIACACHE_get_img_to_buffer
 * DESCRIPTION
 *  get an area of the image to buffer with resize
 * PARAMETERS
 *  index   :  [IN]  the index of image want to get
 *  area    :  [IN]  setting of source area and destination area
 * RETURNS
 *  the error code, you can call get last err for detail error.
 *****************************************************************************/
S32 srv_mediacache_get_img_to_buffer(srv_handle handle, U32 index, srv_mediacache_img_to_buffer_struct *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret_code;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_code = srv_mediacache_get_img_to_buffer_internal(handle, index, buf, MMI_FALSE);
    return ret_code;
}
    
    
/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_lock_and_get_img_buffer_addr
 * DESCRIPTION
 *  get an area of the image to buffer with resize
 * PARAMETERS
 *  index   :  [IN]  the index of image want to get
 *  buf    :  [OUT]  setting of source area and destination area
 * RETURNS
 *  the error code, you can call get last err for detail error.
 *****************************************************************************/
extern S32 srv_mediacache_lock_img_buffer_addr_internal(srv_handle handle, U32 index, void *buf, MMI_BOOL is_blocking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret_code = SRV_MEDIACACHE_ERR_NOT_READY;
    srv_mediacache_cell_struct *cell_level1_p = NULL;
    srv_mediacache_lock_img_buffer_addr_struct *buf_nb_p = (srv_mediacache_lock_img_buffer_addr_struct*)buf;
    srv_mediacache_cell_struct *cell_found_p = NULL;
    MMI_BOOL is_can_draw = MMI_FALSE;
    SRV_MEDIACACHE_MEAS_DEC(lock_stage_0);
    SRV_MEDIACACHE_MEAS_DEC(lock_stage_1);
    SRV_MEDIACACHE_MEAS_DEC(lock_stage_2);
    SRV_MEDIACACHE_MEAS_DEC(lock_stage_3);
    SRV_MEDIACACHE_MEAS_DEC(lock_stage_4);
    SRV_MEDIACACHE_MEAS_DEC(lock_stage_5);
    SRV_MEDIACACHE_MEAS_DEC(lock_stage_6);
    SRV_MEDIACACHE_MEAS_DEC(lock_stage_7);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*source equ cache*/
    SRV_MEDIACACHE_MEAS_START(lock_stage_0);
    SRV_MEDIACACHE_MEAS_START(lock_stage_1);
    g_mediacache_cntx_p->db_save_count = 0;
    g_mediacache_cntx_p->db_save_decode_count = 0;
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
    ivd_ivsrv_db_enable_get_cancel_put(&g_mediacache_cntx_p->db_handle,MMI_TRUE);
#endif
    if (NULL != buf_nb_p->callback || g_mediacache_cntx_p->cb_file_idx == SRV_MEDIACACHE_DUMMY_FILE_IDX)
    {
        srv_mediacache_switch_by_get_to_buffer(handle, index);
    }
    SRV_MEDIACACHE_MEAS_STOP(lock_stage_1);
    
    SRV_MEDIACACHE_MEAS_START(lock_stage_2);
    if (g_mediacache_engine_cntx.is_lock_level2_only != MMI_TRUE)
    {
        cell_found_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->large_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
        if (NULL == cell_found_p)
        {
            cell_found_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
        }
        else
        {
            if (srv_mediacache_cache_cell_can_draw(cell_found_p) == MMI_FALSE)
            {
                cell_found_p = NULL;
            }
        }
    }
    SRV_MEDIACACHE_MEAS_STOP(lock_stage_2);
    
    SRV_MEDIACACHE_MEAS_START(lock_stage_3);
    if (NULL == cell_found_p)
    {
        cell_found_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level2_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
    }
    else
    {
        if (srv_mediacache_cache_cell_can_draw(cell_found_p) == MMI_FALSE)
        {
            cell_level1_p = cell_found_p;
            cell_found_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level2_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
        }
    }
    SRV_MEDIACACHE_MEAS_STOP(lock_stage_3);
    
    if (srv_mediacache_cache_cell_can_draw(cell_found_p) == MMI_TRUE)
    {
        is_can_draw = MMI_TRUE;
    }
    
    SRV_MEDIACACHE_MEAS_START(lock_stage_4);
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
    if (MMI_TRUE != is_can_draw && 
        MMI_TRUE == is_blocking &&
        (buf_nb_p->source == SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE ||
        buf_nb_p->source == SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE_AND_DECODE))
    {
        if (cell_level1_p != NULL)
        {
            srv_mediacache_decode_by_database(cell_level1_p, MMI_TRUE);
            if (srv_mediacache_cache_cell_can_draw(cell_level1_p) == MMI_TRUE)
            {
                cell_found_p = cell_level1_p;
            }
        }
        else if (cell_found_p != NULL)
        {

            srv_mediacache_decode_by_database(cell_found_p, MMI_TRUE);
        }
        else
        {
            srv_mediacache_cache_fill_index_to_link(
                g_mediacache_cntx_p->level1_curr_p, 
                index, 
                g_mediacache_engine_cntx.file_count);
            srv_mediacache_cache_fill_index_to_link(
                g_mediacache_cntx_p->level2_curr_p, 
                index, 
                g_mediacache_engine_cntx.file_count);
            cell_found_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
            if (NULL == cell_found_p)
            {
                cell_found_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level2_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
            }
            srv_mediacache_decode_by_database(cell_found_p, MMI_TRUE);
        }
    }    
    if (srv_mediacache_cache_cell_can_draw(cell_found_p) == MMI_TRUE)
    {
        is_can_draw = MMI_TRUE;
    }
#endif
    SRV_MEDIACACHE_MEAS_STOP(lock_stage_4);

    SRV_MEDIACACHE_MEAS_START(lock_stage_5);
    /*source equ database then decode*/
    if (MMI_TRUE != is_can_draw &&
        MMI_TRUE == is_blocking && 
        buf_nb_p->source == SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE_AND_DECODE)
    {
        if (cell_level1_p != NULL)
        {
            cell_found_p = cell_level1_p;
            cell_found_p->err_code = g_mediacache_cntx_p->engine.decode_cell_blocking(cell_level1_p);
        }
        else if (cell_found_p != NULL)
        {
            cell_found_p->err_code = g_mediacache_cntx_p->engine.decode_cell_blocking(cell_found_p);
        }
        else
        {
            srv_mediacache_cache_fill_index_to_link(
                g_mediacache_cntx_p->level1_curr_p, 
                index, 
                g_mediacache_engine_cntx.file_count);
            srv_mediacache_cache_fill_index_to_link(
                g_mediacache_cntx_p->level2_curr_p, 
                index, 
                g_mediacache_engine_cntx.file_count);
            cell_found_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
            if (NULL == cell_found_p)
            {
                cell_found_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level2_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
            }
            if (NULL == cell_found_p)
            {
                ret_code = SRV_MEDIACACHE_ERR_NOT_ENOUGH_CACHE;
            }

            else
            {
                cell_found_p->err_code = g_mediacache_cntx_p->engine.decode_cell_blocking(cell_found_p);
            }
        }
        if (NULL != cell_found_p)
        {
            if (cell_found_p->err_code < 0)
            {
                cell_found_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
            }
            else
            {
                cell_found_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_OK;
            }
        }
    }   
    SRV_MEDIACACHE_MEAS_STOP(lock_stage_5);
    
    SRV_MEDIACACHE_MEAS_START(lock_stage_6);
    is_can_draw = srv_mediacache_cache_cell_can_draw(cell_found_p);
    if (MMI_TRUE == is_can_draw)
    {
        do
        {
            // UYVY422 must wait for DB sav
            #if defined(__MMI_MEDIA_CACHE_YUV_THUMB__)
            if(cell_found_p->buffer_format == GDI_COLOR_FORMAT_UYVY422)
            {
                kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SRVMC][YUV] SRV_MEDIACACHE_ERR_DECODING due to YUV format");
                ret_code = SRV_MEDIACACHE_ERR_DECODING;
                break;
            }
            #endif

            ASSERT(cell_found_p->is_lock == MMI_FALSE);
            cell_found_p->is_lock = MMI_TRUE;
            ret_code = SRV_MEDIACACHE_OK;
            buf_nb_p->buffer = cell_found_p->buffer;
            if (SRV_MEDIACACHE_CACHE_TYPE_L2 == cell_found_p->type)
            {
                buf_nb_p->length = g_mediacache_cntx_p->level2_buffer_size;
            }
            else if (SRV_MEDIACACHE_CACHE_TYPE_L1 == cell_found_p->type)
            {
                buf_nb_p->length = g_mediacache_cntx_p->level1_buffer_size;
            }
        }while(0);        
    }
    else if(NULL != cell_found_p)
    {
        ret_code = SRV_MEDIACACHE_ERR_DECODING;
        if (cell_found_p->err_code != 0 && SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR == cell_found_p->state)
        {
            ret_code = cell_found_p->err_code;
        }
    }
    else if(NULL == g_mediacache_cntx_p->level2_curr_p && NULL != cell_level1_p)
    {
		// there is no Level2 at all, and L1 already have decoded result.
		// if it is an error, we should return it directly.
        ret_code = SRV_MEDIACACHE_ERR_DECODING;
        if (cell_level1_p->err_code != 0 && SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR == cell_level1_p->state)
        {
            ret_code = cell_level1_p->err_code;
        }
    }
    SRV_MEDIACACHE_MEAS_STOP(lock_stage_6);
    
    SRV_MEDIACACHE_MEAS_START(lock_stage_7);
    if (MMI_FALSE == is_blocking && MMI_FALSE == is_can_draw && NULL != buf_nb_p->callback)
    {
        g_mediacache_cntx_p->app_data_cb = buf_nb_p->callback;
        g_mediacache_cntx_p->user_data = buf_nb_p->user_data;
        g_mediacache_cntx_p->cb_file_idx = index;
        SRV_MEDIACACHE_CB_CHANGED();
        if (NULL == cell_level1_p && NULL == cell_found_p)
        {
            srv_mediacache_cache_fill_index_to_link(
                g_mediacache_cntx_p->level1_curr_p, 
                index, 
                g_mediacache_engine_cntx.file_count);
            srv_mediacache_cache_fill_index_to_link(
                g_mediacache_cntx_p->level2_curr_p, 
                index, 
                g_mediacache_engine_cntx.file_count);
            cell_found_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
            if (NULL == cell_found_p)
            {
                cell_found_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level2_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
            }
            if (NULL == cell_found_p)
            {
                ret_code = SRV_MEDIACACHE_ERR_NOT_ENOUGH_CACHE;
            }
        }
    }
    SRV_MEDIACACHE_MEAS_STOP(lock_stage_7);
    SRV_MEDIACACHE_MEAS_STOP(lock_stage_0);
#ifdef __MM_DEBUG_MEASURE_SRVMC__
    kal_print_string_trace(
        MOD_MMI_MEDIA_APP, 
        MMI_MEDIA_TRC_G2_APP, 
        "[srvmc]meas lock [%d] stage[%d][%d][%d][%d][%d][%d][%d]", 
        lock_stage_0,lock_stage_1,lock_stage_2,lock_stage_3,lock_stage_4,lock_stage_5,lock_stage_6,lock_stage_7);
#endif
    srv_mediacache_check_and_start_decode();
    return ret_code;
}



/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_lock_and_get_img_buffer_addr
 * DESCRIPTION
 *  get an area of the image to buffer with resize
 * PARAMETERS
 *  index   :  [IN]  the index of image want to get
 *  buf    :  [OUT]  setting of source area and destination area
 * RETURNS
 *  the error code, you can call get last err for detail error.
 *****************************************************************************/
extern S32 srv_mediacache_lock_img_buffer_addr(srv_handle handle, U32 index, srv_mediacache_lock_img_buffer_addr_struct *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret_code;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_MEDIACACHE_START_MEASURE("LCB");
/*
    if (NULL == buf->callback)
    {
        ret_code = srv_mediacache_lock_img_buffer_addr_internal(handle, index, buf, MMI_TRUE);
    }
    else
*/
    {
        ret_code = srv_mediacache_lock_img_buffer_addr_internal(handle, index, buf, MMI_FALSE);
    }
    SRV_MEDIACACHE_STOP_MEASURE("LCB");
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_LOCK, buf->source, buf->callback, index, ret_code);
    return ret_code;
}



/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_lock_and_get_img_buffer_addr
 * DESCRIPTION
 *  get an area of the image to buffer with resize
 * PARAMETERS
 *  index   :  [IN]  the index of image want to get
 *  group   :  [IN]  group
 *  cell_info   :  [OUT]  cell info
 * RETURNS
 *  the error code, you can call get last err for detail error.
 *****************************************************************************/
extern S32 srv_mediacache_get_cell_info(srv_handle handle, U32 index, U8 group, srv_mediacache_cell_info_struct* cell_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret_code = -1;
    srv_mediacache_cell_struct *cell_p = NULL;
    MMI_BOOL is_finished;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(cell_info,0,sizeof(srv_mediacache_cell_info_struct));
    switch(group)
    {
    case SRV_MEDIACACHE_CACHE_TYPE_LARGE:
        cell_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->large_p, MMI_FALSE, srv_mediacache_is_index_match, &index);
        break;
    case SRV_MEDIACACHE_CACHE_TYPE_L1:
        cell_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p, MMI_FALSE, srv_mediacache_is_index_match, &index);
        break;
    case SRV_MEDIACACHE_CACHE_TYPE_L2:
        cell_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level2_curr_p, MMI_FALSE, srv_mediacache_is_index_match, &index);
        break;
    }
    is_finished = srv_mediacache_cache_cell_finished(cell_p);
    if (is_finished)
    {
        ret_code = 0;
#ifdef __SRV_MEDIACACHE_DEBUG_MEASURE__
        cell_info->decode_ticks = cell_p->decode_ticks;
        cell_info->db_search_ticks = cell_p->db_ticks;
#endif
        cell_info->is_from_db = MMI_FALSE;
        if (SRV_MEDIACACHE_CACHE_STATE_DECODE_DB_OK == cell_p->state)
        {

            cell_info->is_from_db = MMI_TRUE;
        }
    }
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_get_image_info
 * DESCRIPTION
 *  get image infomation
 * PARAMETERS
 *  handle      [IN]    service handle
 *  index       [IN]    image index
 *  img_info    [OUT]   the structure store the image infomation
 *
 * RETURNS
 *  SRV_MEDIACACHE_ERR_NOT_READY   the index not found at cached cell
 *  SRV_MEDIACACHE_OK              find the index
 *****************************************************************************/


S32 srv_mediacache_get_image_info(srv_handle handle, S32 index, srv_mediacache_get_img_info_struct* img_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_MEDIACACHE_ERR_NOT_READY;
    srv_mediacache_cell_struct *cell_p = NULL;
    MMI_BOOL is_can_draw = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cell_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->locked_cell_p, MMI_FALSE, srv_mediacache_is_index_match, &index);
    if (NULL == cell_p)
    {
        if (g_mediacache_engine_cntx.is_lock_level2_only != MMI_TRUE)
        {
            cell_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p, MMI_FALSE, srv_mediacache_is_index_match, &index);
            is_can_draw = srv_mediacache_cache_cell_can_draw(cell_p);
        }
        if (NULL == cell_p)
        {
            cell_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level2_curr_p, MMI_FALSE, srv_mediacache_is_index_match, &index);
        }
        else
        {
            if (is_can_draw == MMI_FALSE && cell_p->state != SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR)
            {
                cell_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level2_curr_p, MMI_FALSE, srv_mediacache_is_index_match, &index);
            }
        }
    }
    is_can_draw = srv_mediacache_cache_cell_can_draw(cell_p);
    if (NULL != cell_p && MMI_TRUE == is_can_draw)
    {
        ret = cell_p->err_code;
        img_info->org_width  = cell_p->org_image_width;
        img_info->org_height = cell_p->org_image_height;
        img_info->resized_width  = cell_p->image_width;
        img_info->resized_height = cell_p->image_height;
        img_info->is_cached = srv_mediacache_cache_cell_finished(cell_p);
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_pause_decode
 * DESCRIPTION
 *  start the service.
 * PARAMETERS
 *  start_flist_index    :  [IN]  current file index set to service.
 * RETURNS
 *  SRV_MEDIACACHE_OK: start ok.
 *****************************************************************************/
extern S32 srv_mediacache_pause_decode(srv_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mediacache_cntx_p->state == SRV_MEDIACACHE_STATE_RUNNING)
    {
        srv_mediacache_stop_decode();
        if (g_mediacache_cntx_p->decoding_p != NULL)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_CANCEL_DECODE_CELL_AT_D, __LINE__);
            g_mediacache_cntx_p->engine.cancel_decode_cell(g_mediacache_cntx_p->image_hdl_decoding);
            g_mediacache_cntx_p->image_hdl_decoding = 0;
            g_mediacache_cntx_p->decoding_p = NULL;
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_DECODING_P_IS_NULL_D, __LINE__);
        }
#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
        /*process searching one*/
        if (g_mediacache_cntx_p->searching_p != NULL)
        {
            srv_mediacache_db_cancel_get_img(&g_mediacache_cntx_p->db_handle);
            g_mediacache_cntx_p->searching_p = NULL;
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_SEARCH_CHANGE_SEARCHING_POINT_TO_NULL_AT_D, __LINE__);
        }
#endif
        g_mediacache_cntx_p->state = SRV_MEDIACACHE_STATE_PAUSED;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_PAUSE_DECODE);
    }
    return SRV_MEDIACACHE_OK;
}


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_resume_decode
 * DESCRIPTION
 *  start the service.
 * PARAMETERS
 *  handle  :  [IN]  srv handle.
 *  start_flist_index    :  [IN]  current file index set to service.
 * RETURNS
 *  SRV_MEDIACACHE_OK: start ok.
 *****************************************************************************/
extern S32 srv_mediacache_resume_decode(srv_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mediacache_cntx_p->state == SRV_MEDIACACHE_STATE_PAUSED)
    {
        g_mediacache_cntx_p->state = SRV_MEDIACACHE_STATE_RUNNING;
        srv_mediacache_check_and_start_decode();  
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_RESUME_DECODE);
    }
    return SRV_MEDIACACHE_OK;
}


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_resume_decode
 * DESCRIPTION
 *  start the service.
 * PARAMETERS
 *  handle  :  [IN]  srv handle.
 *  start_flist_index    :  [IN]  current file index set to service.
 * RETURNS
 *  SRV_MEDIACACHE_OK: start ok.
 *****************************************************************************/
static void srv_mediacache_resume_decode_with_delay_timer_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_mediacache_cntx_p)
    {
        return;
    }
    g_mediacache_cntx_p->is_waiting_resume = MMI_FALSE;
    if(g_mediacache_cntx_p->backup_state == SRV_MEDIACACHE_STATE_PAUSED &&
       g_mediacache_cntx_p->state == SRV_MEDIACACHE_STATE_PAUSED)
    {
        srv_mediacache_resume_decode((srv_handle)g_mediacache_cntx_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_resume_decode
 * DESCRIPTION
 *  start the service.
 * PARAMETERS
 *  handle  :  [IN]  srv handle.
 *  start_flist_index    :  [IN]  current file index set to service.
 * RETURNS
 *  SRV_MEDIACACHE_OK: start ok.
 *****************************************************************************/
static void srv_mediacache_resume_decode_with_delay(srv_mediacache_cntx_struct* handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mediacache_cntx_p->state == SRV_MEDIACACHE_STATE_PAUSED &&
        g_mediacache_cntx_p->is_waiting_resume != MMI_TRUE)
    {
        g_mediacache_cntx_p->backup_state = g_mediacache_cntx_p->state;
        gui_start_timer(SRV_MEDIACACHE_RESUME_TIME_GAP_NORMAL, srv_mediacache_resume_decode_with_delay_timer_callback);  
        g_mediacache_cntx_p->is_waiting_resume = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *    SRV_MEDIACACHE_get_img_to_buffer
 * DESCRIPTION
 *  get an area of the image to buffer with resize
 * PARAMETERS
 *  handle   :  [IN]  the handle of image buffer for unlock
 * RETURNS
 *  the error code, you can call get last err for detail error.
 *****************************************************************************/
S32 srv_mediacache_unlock_img_buffer(srv_handle handle, void *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *cell_found_p = NULL;
    S32 err_code = SRV_MEDIACACHE_OK;
    S32 file_index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_UNLOCK);
    SRV_MEDIACACHE_CACHE_INDEX_PRINT_DBGTRACE();
    cell_found_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p,MMI_FALSE,srv_mediacache_is_buffer_match, &buffer);
    if (NULL == cell_found_p)
    {
        cell_found_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level2_curr_p,MMI_FALSE,srv_mediacache_is_buffer_match, &buffer);
    }
    if (NULL != cell_found_p)
    {
        cell_found_p->is_lock = MMI_FALSE;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_UNLOCK_INDEX, cell_found_p->file_index);
    }
    else
    {
        cell_found_p = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->locked_cell_p,MMI_FALSE,srv_mediacache_is_buffer_match, &buffer);
        if (NULL != cell_found_p)
        {
            cell_found_p->is_lock = MMI_FALSE;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_UNLOCK_INDEX, cell_found_p->file_index);
            if (cell_found_p == g_mediacache_cntx_p->locked_cell_p)
            {
                g_mediacache_cntx_p->locked_cell_p = g_mediacache_cntx_p->locked_cell_p->next;
            }
            srv_mediacache_link_remove_cell(g_mediacache_cntx_p->locked_cell_p, cell_found_p);
            SRV_MEDIACACHE_CACHE_INDEX_PRINT_DBGTRACE();
            if (SRV_MEDIACACHE_CACHE_TYPE_L1 == cell_found_p->type)
            {
                if (NULL == g_mediacache_cntx_p->level1_curr_p)
                {
                    g_mediacache_cntx_p->level1_curr_p = cell_found_p;
                }
                else
                {
                    srv_mediacache_link_balance_add(g_mediacache_cntx_p->level1_curr_p, cell_found_p);
                }
                g_mediacache_cntx_p->level1_first_p = srv_mediacache_link_get_first(g_mediacache_cntx_p->level1_curr_p);
            }
            else if (SRV_MEDIACACHE_CACHE_TYPE_L2 == cell_found_p->type)
            {
                if (NULL == g_mediacache_cntx_p->level2_curr_p)
                {
                    g_mediacache_cntx_p->level2_curr_p = cell_found_p;
                }
                else
                {
                    srv_mediacache_link_balance_add(g_mediacache_cntx_p->level2_curr_p, cell_found_p);
                }
                g_mediacache_cntx_p->level2_first_p = srv_mediacache_link_get_first(g_mediacache_cntx_p->level2_curr_p);
            }
            /*correct the index*/
            if (NULL != cell_found_p->next)
            {
                if (cell_found_p->next->file_index > 0)
                {
                    file_index = cell_found_p->next->file_index - 1; 
                }
                else
                {
                    file_index = g_mediacache_engine_cntx.file_count - 1; 
                }
            }
            else if(NULL != cell_found_p->prev)
            {
                if (cell_found_p->prev->file_index < g_mediacache_engine_cntx.file_count - 1)
                {
                    file_index = cell_found_p->prev->file_index + 1; 
                }
                else
                {
                    file_index = 0; 
                }
            }
            if (file_index != cell_found_p->file_index)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_RESET_CELL_LINE, __LINE__);
                srv_mediacache_cache_reset_cell(cell_found_p, MMI_FALSE);
                cell_found_p->file_index = file_index;
            }
            SRV_MEDIACACHE_CACHE_INDEX_PRINT_DBGTRACE();
        }
        else
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_UNLOCK_FAILED, buffer);
            err_code = SRV_MEDIACACHE_ERR_BUFFER_NOT_FOUND;
        }
    }
    g_mediacache_cntx_p->level1_first_p = srv_mediacache_link_get_first(g_mediacache_cntx_p->level1_curr_p);
    g_mediacache_cntx_p->level2_first_p = srv_mediacache_link_get_first(g_mediacache_cntx_p->level2_curr_p);
    SRV_MEDIACACHE_CACHE_INDEX_PRINT_DBGTRACE();
    return err_code;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_rotate_array
 * DESCRIPTION
 *  rotate a 2D image buffer at 3D zoom
 * PARAMETERS
 *  void *src       [IN]    source buffer
 *  S32 x            [IN]   rotate pointer x
 *  S32 y            [IN]   rotate pointer y
 *  U32 src_w      [IN]   source width
 *  U32 src_h      [IN] source height
 *  void* dst       [OUT] out buffer
 *  U32 dst_w      [IN] out width
 *  U32 dst_h       [IN] out height
 *  double argx     [IN] angle 1
 *  double argy     [IN] angle 2
 *  double argz     [IN] angle 3
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mediacache_rotate_array(void *src, S32 x, S32 y, U32 src_w, U32 src_h, void* dst, U32 dst_w, U32 dst_h, double argx, double argy, double argz)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define SRV_MEDIACACHE_T_ROTATE_ZOOM     (10000)
    S32 i, j;
    S32 src_x, src_y;
    S32 dst_x, dst_y;
    S32 r[3][3];
    U16 *src_p = (U16*)src;
    U16 *dst_p = (U16*)dst;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    r[0][0] = SRV_MEDIACACHE_T_ROTATE_ZOOM *(cos(argx)*cos(argz)+ sin(argx)*sin(argy)*sin(argz));
    r[0][1] = SRV_MEDIACACHE_T_ROTATE_ZOOM * (sin(argx)*cos(argy));    
    r[0][2] = SRV_MEDIACACHE_T_ROTATE_ZOOM*((-1)*cos(argx)*sin(argz)+ sin(argx)*sin(argy)*cos(argz));

    r[1][0] = SRV_MEDIACACHE_T_ROTATE_ZOOM*((-1)*sin(argx)*cos(argz)+ cos(argx)*sin(argy)*sin(argz));    
    r[1][1] = SRV_MEDIACACHE_T_ROTATE_ZOOM*(cos(argx)*cos(argy));
    r[1][2] = SRV_MEDIACACHE_T_ROTATE_ZOOM*(sin(argx)*sin(argz)+ cos(argx)*sin(argy)*cos(argz));

    r[2][0] = SRV_MEDIACACHE_T_ROTATE_ZOOM*(sin(argz));    
    r[2][1] = SRV_MEDIACACHE_T_ROTATE_ZOOM*((-1)*sin(argy));    
    r[2][2] = SRV_MEDIACACHE_T_ROTATE_ZOOM*(cos(argy)*cos(argz));

    for (i = 0; i < src_w; i++)
    {
        for (j = 0; j < src_h; j++)
        {
            src_x = i - x;
            src_y = j - y;
            dst_x = (r[0][0]*src_x + r[0][1] * src_y + r[0][2] * 0)/SRV_MEDIACACHE_T_ROTATE_ZOOM;
            dst_y = (r[1][0]*src_x + r[1][1] * src_y + r[0][2] * 0)/SRV_MEDIACACHE_T_ROTATE_ZOOM;
            /*dummy*/
            /*dst_z = r[2][0]*src_x + r[2][1] * src_y + r[2][2] * 0;*/
            dst_x = dst_x + x;
            dst_y = dst_y + y;
            src_x = src_x + x;
            src_y = src_y + y;
            if (dst_x >=0 && dst_x < dst_w &&
                dst_y >=0 && dst_y < dst_h &&
                src_x >=0 && src_x < src_w &&
                src_y >=0 && src_y < src_h)
            {
                *(dst_p + (dst_y * dst_w + dst_x)) = *(src_p + (src_y * src_w + src_x));
            }
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_rotate_layer
 * DESCRIPTION
 *  rotate src to dst, them must not same
 * PARAMETERS
 *  enable     [IN]    switch
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mediacache_rotate_layer(gdi_handle src_layer, S32 x, S32 y, gdi_handle dst_layer, double z_angle, double y_angle, double x_angle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  *dst_buf, *src_buf, m_src_bits, m_dst_bits;
    S32 src_width, src_height, dst_width, dst_height;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(src_layer != dst_layer);
    gdi_layer_set_active(src_layer);
    gdi_layer_get_buffer_ptr(&src_buf);
    gdi_layer_get_dimension(&src_width, &src_height);
    m_src_bits = gdi_layer_get_bit_per_pixel();
    gdi_layer_set_active(dst_layer);
    gdi_layer_get_buffer_ptr(&dst_buf);
    gdi_layer_get_dimension(&dst_width, &dst_height);
    m_dst_bits = gdi_layer_get_bit_per_pixel();
    ASSERT(m_src_bits == m_dst_bits);
    ASSERT(m_src_bits == 16);
    ASSERT(src_buf != dst_buf);
    srv_mediacache_rotate_array(
                        src_buf, 
                        x, 
                        y, 
                        src_width, 
                        src_height, 
                        dst_buf, 
                        dst_width, 
                        dst_height, 
                        z_angle,  
                        y_angle, 
                        x_angle);
}



#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__

/*****************************************************************************
 * FUNCTION
 *  _srv_mediacache_gdi_result_from_ies_result
 * DESCRIPTION
 *  convert IES error to GDI error result
 * PARAMETERS
 *  ies_result [IN] IES error code
 * RETURNS
 *  matching GDI error code
 *****************************************************************************/
static GDI_RESULT _srv_mediacache_gdi_result_from_ies_result(srv_ies_result ies_result)
{
    switch(ies_result)
    {
    // resolution, too large
    case SRV_IES_E_RESOLUTION_TOO_LARGE:
    case SRV_IES_E_NOT_ENOUGH_BUFFER:
    case SRV_IES_E_FILE_SIZE_TOO_LARGE:
        return GDI_JPEG_ERR_IMAGE_TOO_LARGE;

    // file error
    case SRV_IES_E_FILE_WRITE_FAILED:
    case SRV_IES_E_FILE_ACCESS_DENIED:
    // generic
    default:
        return GDI_IMAGE_ERR_UNSUPPORTED_FORMAT;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_is_have_ies_image_handle
 * DESCRIPTION
 *  check if cell hae image handle or not
 * PARAMETERS
 *  curr_p : [IN] cell pointer
 *  user_data : [in] Currently not use
 * RETURNS
 *  Cell have image handle or not
 *****************************************************************************/
static MMI_BOOL srv_mediacache_is_have_ies_image_handle(srv_mediacache_cell_struct* curr_p, void *user_data)
{
    if (curr_p->ies_image_handle)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_release_ies_handle
 * DESCRIPTION
 *  release ies image hanlde and preview handle
 * PARAMETERS
 *  NULL
 * RETURNS
 *  NULL
 *****************************************************************************/
static void srv_mediacache_release_ies_handle(void)
{
    srv_mediacache_cell_struct *cache_cell;

    // release preview handle of L1
    cache_cell = srv_mediacache_link_get_first(g_mediacache_cntx_p->level1_curr_p);   
    while (cache_cell)
    {
        //release preview handle 
        if(cache_cell->ies_preview_handle)
        {
            srv_ies_preview_destroy(cache_cell->ies_preview_handle);
            cache_cell->ies_preview_handle = NULL;
            cache_cell->ies_preview_gdi_layer = NULL;
        }

        //release image handle 
        if (cache_cell->ies_image_handle)
        {
            srv_ies_image_destroy(cache_cell->ies_image_handle);
            cache_cell->ies_image_handle = NULL;
        }

        srv_mediacache_free_meta_handle_if_needed((srv_handle)g_mediacache_cntx_p, cache_cell);

        //release meta handle
        cache_cell = cache_cell->next;
    }
}


static void _srv_mediacache_get_filetype_if_needed(srv_mediacache_cell_struct *cell_p)
{
    S32 result = 0;

    if (cell_p && cell_p->image_type == GDI_IMAGE_TYPE_INVALID)
    {
        SRV_MEDIACACHE_START_MEASURE("SLF");
        result = g_mediacache_cntx_p->engine.get_file_name(
            cell_p->file_index, 
            (U16*)g_mediacache_cntx_p->config.filename, 
            SRV_FMGR_PATH_BUFFER_SIZE,
            NULL);
        SRV_MEDIACACHE_STOP_MEASURE("SLF");            
        if (result >= 0)
        {
            SRV_MEDIACACHE_START_MEASURE("SLG");
            cell_p->image_type = gdi_image_get_type_from_file(g_mediacache_cntx_p->config.filename);
            SRV_MEDIACACHE_STOP_MEASURE("SLG"); 
        }
    }
}


static MMI_BOOL _srv_mediacache_decode_need_ies_check(srv_mediacache_cell_struct *cell_p)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_SRV_MEDIACACHE_DECODE_NEED_IES_CHECK_INTERNAL);

    if (g_mediacache_cntx_p->is_using_ies == MMI_FALSE)
    {
       return MMI_FALSE; 
    }
    
    if (cell_p == NULL)
    {
        return MMI_FALSE;
    }

    _srv_mediacache_get_filetype_if_needed(cell_p);

    if(GDI_IMAGE_TYPE_JPG_FILE == cell_p->image_type && 
       (SRV_MEDIACACHE_CACHE_TYPE_L1 == cell_p->type))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_SRV_MEDIACACHE_DECODE_NEED_IES_CHECK_INTERNAL);
        return MMI_TRUE;
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_SRV_MEDIACACHE_DECODE_NEED_IES_CHECK_INTERNAL);
        return MMI_FALSE;
    }
}

static MMI_BOOL srv_mediacache_preview_render_buffer_to_cell_async(srv_mediacache_cell_struct *cell_p)
{
    S32 ret = 0;
    srv_ies_result result;
    S32 img_width, img_height;
    U32 buf_length = 0;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_SRV_MEDIACACHE_PREVIEW_RENDER_BUFFER_TO_CELL_ASYNC_INTERNAL);

    ret = g_mediacache_cntx_p->engine.get_file_name(
        cell_p->file_index, 
        (U16*)g_mediacache_cntx_p->config.filename, 
        SRV_FMGR_PATH_BUFFER_SIZE,
        NULL);
    if (ret < 0)
    {
        if (SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY != ret && SRV_FMGR_FILELIST_ERROR_BUSY != ret)
        {
            cell_p->err_code = ret;
            cell_p->err_group= SRV_MEDIACACHE_ERR_GROUP_APP;
            cell_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
            cell_p->is_saved = MMI_TRUE;
        }
        return MMI_FALSE;
    }

    if (cell_p->image_width == -1 && cell_p->image_height == -1)
    {
        SRV_MEDIACACHE_START_MEASURE("FU3");
        result = gdi_imgdec_get_dimension_file(g_mediacache_cntx_p->config.filename, &img_width, &img_height);
        if (result < 0)
        {
            result = gdi_image_get_dimension_file(g_mediacache_cntx_p->config.filename, &img_width, &img_height);
        }
        SRV_MEDIACACHE_STOP_MEASURE("FU3");
    }
    else
    {
        img_width = cell_p->org_image_width;
        img_height = cell_p->org_image_height;
    }
    
    buf_length = srv_mediacache_cache_get_img_size_by_type(cell_p->type);
    srv_mediacache_cache_fill_cell_by_img_and_length(buf_length, img_width, img_height, cell_p);
    
    if (cell_p->image_width <= 0 || cell_p->image_height <= 0)
    {        
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_CALC_W_H_ERR,
            cell_p->image_width, cell_p->image_height);
        cell_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
        cell_p->err_code = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
        cell_p->err_group= SRV_MEDIACACHE_ERR_GROUP_MEDIACACHE;

        srv_mediacache_set_last_err(SRV_MEDIACACHE_ERR_GROUP_GDI, SRV_MEDIACACHE_ERR_IES_RENDER_FAIL);
        return MMI_FALSE;
    }
    // currently do not support L1 clip
    

    if(NULL == cell_p->ies_image_handle)
    {
        U32 meta_size = 0;
        const WCHAR* path = (const WCHAR*)g_mediacache_cntx_p->config.filename;
        
        if(cell_p->ies_preview_handle)
        {
            srv_ies_preview_destroy(cell_p->ies_preview_handle);
            cell_p->ies_preview_handle = NULL;
            cell_p->ies_preview_gdi_layer = NULL;
        }

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRV_IES_IMAGE_CREATE_FROM_FILE);
        result = srv_ies_image_create_from_file(g_mediacache_cntx_p->ies_app_session,
            path, 
            NULL,
            &cell_p->ies_image_handle);
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MEDIA_CACHE_CREATED_IMAGE_X_ON_CELL_X, cell_p->ies_image_handle, cell_p);

        if(result == SRV_IES_OK)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_META_DATA_SIZE_D, meta_size);
        }
        else
        {
            cell_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
            cell_p->err_group = SRV_MEDIACACHE_ERR_GROUP_GDI;
            cell_p->err_code = _srv_mediacache_gdi_result_from_ies_result(result);
            srv_mediacache_set_last_err(SRV_MEDIACACHE_ERR_GROUP_GDI, cell_p->err_code);
            return MMI_FALSE;
        }
    }

    if (result == SRV_IES_OK && (cell_p->ies_image_handle))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_START_OF_SRV_IES_PREVIEW_CREATE);
        result = srv_ies_preview_create(cell_p->ies_image_handle, 
                               &cell_p->ies_preview_handle, 
                               g_mediacache_cntx_p->ies_render_buffer,
                               cell_p->image_width * 2 * cell_p->image_height,
                               cell_p->image_width,
                               cell_p->image_height, 
                               cell_p->image_width * 2, 
                               SRV_IES_COLORFORMAT_RGB565);
        cell_p->ies_preview_gdi_layer = NULL;
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_END_OF_SRV_IES_PREVIEW_CREATE);
        
        if(result != SRV_IES_OK)
        {
            srv_mediacache_set_last_err(SRV_MEDIACACHE_ERR_GROUP_GDI, SRV_MEDIACACHE_ERR_IES_PREVIEW_FAIL);
            return MMI_TRUE;
        }
        
    }
    
    if (result == SRV_IES_OK)
    {        
        result = srv_ies_preview_render_async(
             cell_p->ies_preview_handle, 
             _srv_mediacache_engine_ies_decode_cb, NULL,
             &g_mediacache_cntx_p->ies_decoding_handle);
             

        if (result == SRV_IES_OK)
        {
            //cell_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODING;
            //here cell->state should be DB decode OK
            g_mediacache_cntx_p->decoding_p = cell_p;
        }
        else
        {
            cell_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
            cell_p->err_code = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
            cell_p->err_group = SRV_MEDIACACHE_ERR_GROUP_GDI;

            srv_mediacache_set_last_err(SRV_MEDIACACHE_ERR_GROUP_GDI, SRV_MEDIACACHE_ERR_IES_RENDER_FAIL);
            
            return MMI_FALSE;
        }
    }
    else
    {
        cell_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
        cell_p->err_code = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
        cell_p->err_group = SRV_MEDIACACHE_ERR_GROUP_GDI;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_SRV_MEDIACACHE_PREVIEW_RENDER_BUFFER_TO_CELL_ASYNC_INTERNAL);

    return MMI_TRUE;
}


// returns TRUE if we can use ies to decode this cell and store the session
static MMI_BOOL _srv_mediacache_decode_cell_with_ies(srv_mediacache_cell_struct *cell_p, 
                                                         const WCHAR* filename_p, 
                                                         U32 buf_length, 
                                                         S32 layer_w, 
                                                         S32 layer_h,
                                                         U32 *pDecodeHandle)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_SRV_MEDIACACHE_DECODE_CELL_WITH_IES_INTERNAL);

    // we hijack JPEG LARGE & L1 case to IES
    if(GDI_IMAGE_TYPE_JPG_FILE == cell_p->image_type &&
        (SRV_MEDIACACHE_CACHE_TYPE_LARGE == cell_p->type))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_CANCEL_DECODE_LARGE);
        return MMI_FALSE;
    }

    if(GDI_IMAGE_TYPE_JPG_FILE == cell_p->image_type &&
        (SRV_MEDIACACHE_CACHE_TYPE_L1 == cell_p->type))
    {
        MMI_BOOL result = MMI_FALSE;  

        srv_mediacache_create_meta_if_needed((srv_handle)g_mediacache_cntx_p, cell_p, (WCHAR*)filename_p, layer_w, layer_h);

        // do not allow simultaneous decoding.
        ASSERT(NULL == g_mediacache_cntx_p->ies_decoding_handle);

        result = srv_mediacache_image_render_buffer_to_cell_async((srv_handle)g_mediacache_cntx_p, cell_p, filename_p, buf_length, layer_w, layer_h);

        return result;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_SRV_MEDIACACHE_DECODE_CELL_WITH_IES_INTERNAL);

    return MMI_FALSE;
}


static MMI_BOOL srv_mediacache_is_ies_image_ready(srv_mediacache_cell_struct *cell_p, srv_mediacache_img_to_layer_struct *area)
{
    S32 index = cell_p->file_index;
    srv_mediacache_cell_struct *cache_cell;

    if (g_mediacache_cntx_p->is_using_ies == MMI_FALSE)
    {
        return MMI_FALSE;
    }
    
    if (!cell_p)
    {
        return MMI_FALSE;
    }

    if (cell_p->ies_image_handle)
    {
        return MMI_TRUE;
    }

    if (SRV_MEDIACACHE_CACHE_TYPE_LARGE == cell_p->type)
    {
        cache_cell = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
    }
    else
    {
        cache_cell = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->large_p,MMI_FALSE,srv_mediacache_is_index_match, &index);
    }
    if (cache_cell)
    {
        if (cache_cell->ies_image_handle)
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}

static void srv_mediacache_delete_image_handle_if_needed(srv_mediacache_cell_struct *curr_p)
{
    if (!g_mediacache_cntx_p->is_using_ies)
    {
        return;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_SRV_MEDIACACHE_DELETE_IMAGE_HANDLE_IF_NEEDED_PREVIEW_HANDLE_IS_D_IMAGE_HANDLE_IS_D,
        curr_p->ies_preview_handle, curr_p->ies_image_handle);

    if (curr_p && curr_p->ies_preview_handle)
    {
        srv_ies_preview_destroy(curr_p->ies_preview_handle);
        curr_p->ies_preview_handle = NULL;
        curr_p->ies_preview_gdi_layer = NULL;
    }

    if (curr_p && curr_p->ies_image_handle)
    {
        srv_ies_image_destroy(curr_p->ies_image_handle);
        curr_p->ies_image_handle = NULL;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_SRV_MEDIACACHE_DELETE_IMAGE_HANDLE_IF_NEEDED);
}


static void srv_mediacache_create_image_handle_if_needed(srv_mediacache_cell_struct *curr_p)
{
    srv_mediacache_cell_struct *cache_cell_p = NULL;
    srv_ies_result result = SRV_IES_OK;

    if (!g_mediacache_cntx_p->is_using_ies)
    {
        return;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_SRV_MEDIACACHE_CREATE_IMAGE_HANDLE_IF_NEEDED);

    if (curr_p)
    {
        if (curr_p->image_type == GDI_IMAGE_TYPE_INVALID)
        {
            /* will create image handle in decode schedule*/
            return ;
        }

        if (curr_p->state != SRV_MEDIACACHE_CACHE_STATE_DECODE_OK)
        {
            /* will create image handle in decode schedule*/
            return;
        }

        if (curr_p->image_type == GDI_IMAGE_TYPE_JPG_FILE)
        {
            if (g_mediacache_cntx_p->decoding_p == NULL)
            {
                if (curr_p->ies_image_handle == NULL)
                {
                    /* although maybe the cell is ready, but if the current cell do not have image handle, we create it for it */
                    cache_cell_p = curr_p;
                }
            }
            else
            {
                if (g_mediacache_cntx_p->decoding_p->file_index != curr_p->file_index)
                {
                    if (curr_p->ies_image_handle == NULL)
                    {
                        /* although maybe the cell is ready, but if the current cell do not have image handle, we create it for it */
                        cache_cell_p = curr_p;
                    }
                }
            }
        }
    }

    if (cache_cell_p)
    {
        if (cache_cell_p->ies_meta_handle == 0)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_WARNING_CREATE_IMAGE_HANDLE_BUT_DO_NOT_HAVE_META_HANDLE);
        }

        if(NULL == cache_cell_p->ies_image_handle)
        {
            U32 meta_size = 0;
            S32 ret = 0;

            srv_ies_meta_handle meta_handle = NULL;

            if (cache_cell_p->ies_meta_handle)
            {
                meta_handle = cache_cell_p->ies_meta_handle;
            }
        
            ret = g_mediacache_cntx_p->engine.get_file_name(
                cache_cell_p->file_index, 
                (U16*)g_mediacache_cntx_p->config.filename, 
                SRV_FMGR_PATH_BUFFER_SIZE,
                NULL);

            if (ret < 0)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_GET_NAME_FAILED,ret,__LINE__);
                cache_cell_p->err_code = ret;
                cache_cell_p->err_group= SRV_MEDIACACHE_ERR_GROUP_APP;
                cache_cell_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
                cache_cell_p->is_saved = MMI_TRUE;
                return;
            }

            if(cache_cell_p->ies_preview_handle)
            {
                srv_ies_preview_destroy(cache_cell_p->ies_preview_handle);
                cache_cell_p->ies_preview_handle = NULL;
                cache_cell_p->ies_preview_gdi_layer = NULL;
            }

            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_SRV_IES_IMAGE_CREATE_FROM_FILE_META_HANDLE_IS_D, meta_handle);
            //holy light
            result = srv_ies_image_create_from_file(g_mediacache_cntx_p->ies_app_session,
                (WCHAR*)g_mediacache_cntx_p->config.filename, 
                meta_handle,
                &cache_cell_p->ies_image_handle);
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_SRV_IES_IMAGE_CREATE_FROM_FILE_HANDLE_IS_D_CELL_INDEX_ID_D,
                cache_cell_p->ies_image_handle, cache_cell_p->file_index);

            if(result == SRV_IES_OK)
            {
                srv_ies_image_increase_user_counter(cache_cell_p->ies_image_handle);
                //srv_ies_image_query_meta_data(cache_cell_p->ies_image_handle, NULL, &meta_size);
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_META_DATA_SIZE_D, meta_size);
            }
            else
            {
                srv_mediacache_set_last_err(SRV_MEDIACACHE_ERR_GROUP_GDI, _srv_mediacache_gdi_result_from_ies_result(result));
            }
        }
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_SRV_MEDIACACHE_CREATE_IMAGE_HANDLE_IF_NEEDED);
}


static void srv_mediacache_db_put_meta(srv_mediacache_cell_struct *cell_p, ivd_req_callback finish_callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_meta_info_struct meta_info;
    S32 ret = 0;
    srv_ies_result ies_ret = SRV_IES_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mediacache_cntx_p->is_db_start_ok != MMI_TRUE ||
        g_mediacache_cntx_p->db_handle.io_buf.meta_state != MMI_IVD_IO_BUF_STATE_IDLE)
    {
        return;
    }

    if (SRV_MEDIACACHE_CACHE_STATE_DECODE_OK == cell_p->state || (SRV_MEDIACACHE_CACHE_STATE_DECODE_DB_OK == cell_p->state))
    {
        //can go on
    }
    else
    {
        return ;
    }

    if (cell_p->ies_meta_handle == 0)
    {
        return;
    }

    SRV_MEDIACACHE_START_MEASURE("FSG");
    ASSERT(NULL != g_mediacache_cntx_p->engine.get_file_name);
    ret = g_mediacache_cntx_p->engine.get_file_name(
        cell_p->file_index, 
        (U16*)g_mediacache_cntx_p->config.filename, 
        SRV_FMGR_PATH_BUFFER_SIZE,
        NULL);
    SRV_MEDIACACHE_STOP_MEASURE("FSG");
    if (ret < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_GET_NAME_FAILED,ret,__LINE__);
        return;
    }

    mmi_ucs2cpy(meta_info.path, g_mediacache_cntx_p->config.filename);
    meta_info.db_handle = &g_mediacache_cntx_p->db_handle;

    //here we get meta data
    srv_ies_meta_query_data(cell_p->ies_meta_handle, SRV_MEDIACACHE_META_SLICE_SIZE, meta_info.db_handle->io_buf.meta_buffer, 
        &meta_info.db_handle->io_buf.meta_length);
    if (ies_ret != SRV_IES_OK)
    {
        cell_p->is_ies_meta_saved = MMI_TRUE; //here means wo do not save this meta do db
        cell_p->ies_meta_state = SRV_MEDIACACHE_META_STATE_FINISHED_BUT_ERROR;
        return ;
    }
    
    ASSERT(mmi_ucs2strlen(meta_info.path) * 2 < IVD_FILE_MAX_PATH_LEN);
    ivd_ivsrv_db_put_meta(&meta_info, finish_callback, user_data);
}


static void srv_mediacache_save_meta_to_db_callback(S32 err, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *cell_p = (srv_mediacache_cell_struct *)user_data;
    srv_mediacache_cell_struct *cell_tmp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //to check if the cell is still alive or not
    cell_tmp = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p, MMI_FALSE, srv_mediacache_is_index_match, &cell_p->file_index);
    if (!cell_tmp)
    {
        //here means the cell is out of your view
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_WARING_WHEN_CALLBACK_THE_CELL_IS_NO_LONG_USED_INDEX_IS_D, cell_p->file_index);
        return ;
    }
    
    if (err >= 0)
    {
        cell_p->is_saved = MMI_TRUE;
    }
    gui_start_timer(SRV_MEDIACACHE_SAVE2DB_TIME_GAP_NORMAL, srv_mediacache_save_to_db_schedule);  
}


static void srv_mediacache_db_put_spmo_cb(S32 err, ivd_db_imageinfo_struct *image_info, void *user_data)
{
    srv_mediacache_cell_struct *cell_p = (srv_mediacache_cell_struct *)user_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (err >= 0)
    {
        cell_p->is_ies_meta_saved = MMI_TRUE;
    }
    else
    {
        //although can not save to DB, we still go to next one
        cell_p->is_ies_meta_saved = MMI_TRUE;
    }
    
    gui_start_timer(SRV_MEDIACACHE_SAVE2DB_TIME_GAP_NORMAL, srv_mediacache_save_to_db_schedule);  
}

static MMI_BOOL srv_mediacache_db_get_meta(srv_mediacache_cell_struct *cell_p, MMI_BOOL is_blocking, ivd_req_callback finish_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ivd_db_meta_info_struct meta_info;
    S32 ret;
    MMI_BOOL meta_ret = MMI_FALSE;
    srv_ies_result ies_ret = SRV_IES_OK;
    PS8 o_buffer = NULL;
    S32 o_buffer_size = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mediacache_cntx_p->is_db_start_ok == MMI_FALSE)
    {
        return MMI_FALSE;
    }

    meta_info.db_handle = &g_mediacache_cntx_p->db_handle;
    
    ASSERT(NULL != g_mediacache_cntx_p->engine.get_file_name);
    SRV_MEDIACACHE_START_MEASURE("FSG");
    ret = g_mediacache_cntx_p->engine.get_file_name(
        cell_p->file_index, 
        (U16*)g_mediacache_cntx_p->config.filename, 
        SRV_FMGR_PATH_BUFFER_SIZE,
        NULL);
    if (ret < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_GET_NAME_FAILED,ret,__LINE__);
        if (SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY != ret && SRV_FMGR_FILELIST_ERROR_BUSY != ret)
        {
            g_mediacache_cntx_p->searching_p->err_code = ret;
            g_mediacache_cntx_p->searching_p->err_group= SRV_MEDIACACHE_ERR_GROUP_APP;
            g_mediacache_cntx_p->searching_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
            g_mediacache_cntx_p->searching_p->is_saved = MMI_TRUE;
            if (finish_callback)
            {
                finish_callback(g_mediacache_cntx_p->searching_p->err_code, (void*)g_mediacache_cntx_p->searching_p);
            }
        }
        return MMI_FALSE;
    }
    SRV_MEDIACACHE_STOP_MEASURE("FSG");

    mmi_ucs2cpy(meta_info.path, g_mediacache_cntx_p->config.filename);
    ASSERT(mmi_ucs2strlen(meta_info.path) * 2 < IVD_FILE_MAX_PATH_LEN);

    if (is_blocking == MMI_TRUE)
    {
        meta_ret = ivd_ivsrv_db_get_meta_blocking(&meta_info, finish_callback, &o_buffer, &o_buffer_size);

        if (meta_ret)
        {
            cell_p->is_ies_meta_saved = MMI_TRUE;
            ies_ret = srv_ies_meta_create_from_buffer(g_mediacache_cntx_p->ies_app_session, o_buffer, o_buffer_size, &(cell_p->ies_meta_handle));
            if (ies_ret == SRV_IES_OK)
            {
                cell_p->ies_meta_state = SRV_MEDIACACHE_META_STATE_FINISHED;
                MMI_ASSERT(cell_p->ies_meta_handle); // we should get meta handle, else should ask ies why
            }
            else
            {
                //why create meta failed? it will lead the image display too late.
                //MMI_ASSERT(0);
                cell_p->ies_meta_state = SRV_MEDIACACHE_META_STATE_FINISHED_BUT_ERROR;
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_META_SRV_IES_META_CREATE_FROM_BUFFER_RESULT_IS_D, ies_ret);
            }
        }
    }
    else
    {
        //currently do not support his 
        meta_ret = ivd_ivsrv_db_get_meta(&meta_info, finish_callback);
    }

    return meta_ret;
}


static MMI_BOOL srv_mediacache_create_meta_callback(srv_ies_result callback_result, void *pUserData)
{
    srv_mediacache_cell_struct *cell_p = (srv_mediacache_cell_struct *)pUserData;
    srv_ies_result ies_ret;
    srv_mediacache_cell_struct *cell_tmp = NULL;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_META_CREATE_META_CALLBACK_RESULT_IS_D, callback_result);

    if (g_mediacache_cntx_p->ies_meta_p)
    {
        g_mediacache_cntx_p->ies_meta_p = NULL;
    }
    
    if (cell_p)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_META_CREATE_META_CALLBACK_FILE_INDEX_D, cell_p->file_index);
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_META_CREATE_META_CALLBACK_FILE_INDEX_D, -1);
    }

    //here we may callback for meta, but maybe meta and image not saved to db. so start it.
    gui_start_timer(SRV_MEDIACACHE_DECODE_TIME_GAP_SHORT, srv_mediacache_decode_schedule);

    //to check if the cell is still alive or not
    cell_tmp = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p, MMI_FALSE, srv_mediacache_is_index_match, &cell_p->file_index);
    if (!cell_tmp)
    {
        //here means the cell is out of your view
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_WARING_WHEN_CALLBACK_THE_CELL_IS_NO_LONG_USED_INDEX_IS_D, cell_p->file_index);
        return MMI_FALSE;
    }

    if (callback_result == SRV_IES_OK)
    {
        ies_ret = srv_ies_job_get_meta(cell_p->ies_meta_job_handle, &cell_p->ies_meta_handle);
        //srv_ies_job_cancel(cell_p->ies_meta_job_handle);
        //ies_ret = srv_ies_meta_query_data(cell_p->ies_meta_handle, cell_p->ies_meta_buffer, &cell_p->ies_meta_buffer_size);
        //here we do not query meta data, we will query meta data when put meta        
        cell_p->ies_meta_job_handle = 0;
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_META_SET_META_JOB_HANDLE_TO_NULL_FILE_INDEX_D_D, cell_p->file_index, __LINE__);

        if (ies_ret != SRV_IES_OK)
        {
            /* even if create meta failed, we still think it is valid image
            cell_p->err_code = result;
            cell_p->err_group= SRV_MEDIACACHE_ERR_GROUP_APP;
            cell_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
            srv_mediacache_check_cb_and_call(cell_p, cell_p->file_index, MMI_TRUE);
            */
            
            cell_p->is_ies_meta_saved = MMI_TRUE; //here means wo do not save this meta do db
            cell_p->ies_meta_state = SRV_MEDIACACHE_META_STATE_FINISHED_BUT_ERROR;
        }
        else
        {
            cell_p->ies_meta_state = SRV_MEDIACACHE_META_STATE_FINISHED;

            //TODO :: the code is not right, need modify.
            if (g_mediacache_cntx_p->is_meta_using_db)
            {
                if (g_mediacache_cntx_p->is_put_meta_urgent)
                {
                    srv_mediacache_db_put_meta(cell_p, srv_mediacache_meta_save_to_db_callback, cell_p);
                }
            }
        }
    }
    else
    {
        cell_p->ies_meta_state = SRV_MEDIACACHE_META_STATE_FINISHED_BUT_ERROR;
        cell_p->is_ies_meta_saved = MMI_TRUE;
    }

    return MMI_TRUE;
}


static MMI_BOOL srv_mediacache_create_meta_if_needed(srv_handle handle, 
                                                         srv_mediacache_cell_struct *cell_p, 
                                                         const WCHAR* filename_p, 
                                                         S32 layer_w, 
                                                         S32 layer_h)
{
    srv_ies_result ies_ret = SRV_IES_OK;
    srv_mediacache_cntx_struct *medialib_cntx_p = (srv_mediacache_cntx_struct *)handle;

    if (!medialib_cntx_p)
    {
        MMI_ASSERT(0);
    }
    
    if (!g_mediacache_cntx_p->is_using_meta)
    {
        return MMI_FALSE;
    }
    
    if (cell_p->ies_meta_state == SRV_MEDIACACHE_META_STATE_IDLE)
    {
        if (cell_p->ies_meta_handle == 0 && (cell_p->ies_meta_job_handle == 0) && (cell_p->ies_meta_state != SRV_MEDIACACHE_META_STATE_FINISHED_BUT_ERROR))
        {
            cell_p->ies_meta_state = SRV_MEDIACACHE_META_STATE_GETTING_FROM_IES;

            if(medialib_cntx_p->ies_meta_p)
            {
                MMI_ASSERT(0);
            }
            
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_META_START_OF_CREATE_META_FILE_INDEX_IS_D, cell_p->file_index);
            ies_ret = srv_ies_meta_create_from_file_async(g_mediacache_cntx_p->ies_app_session, filename_p, layer_w, layer_h, 
                srv_mediacache_create_meta_callback, (void*)cell_p, &cell_p->ies_meta_job_handle);
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_META_END_OF_CREATE_META_RET_D_JOB_HANDLE_D, ies_ret, cell_p->ies_meta_job_handle);
            
            if (ies_ret != SRV_IES_OK)
            {
                medialib_cntx_p->ies_meta_p = NULL;
                cell_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
                cell_p->err_code = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
                cell_p->err_group = SRV_MEDIACACHE_ERR_GROUP_GDI;

                cell_p->ies_meta_state = SRV_MEDIACACHE_META_STATE_FINISHED_BUT_ERROR;
                
                srv_mediacache_set_last_err(SRV_MEDIACACHE_ERR_GROUP_GDI, SRV_MEDIACACHE_ERR_IES_META_CREATE_FAIL);
            } 
            else
            {
                medialib_cntx_p->ies_meta_p = cell_p;
                MMI_ASSERT(cell_p->ies_meta_job_handle);
            }
        }
        else
        {
            //do nothing, the meta is wrong.
        }

        return MMI_TRUE;
    }
    
    return MMI_FALSE;    
}


static MMI_BOOL srv_mediacache_image_render_buffer_to_cell_async(srv_handle handle, 
                                                         srv_mediacache_cell_struct *cell_p, 
                                                         const WCHAR* filename_p, 
                                                         U32 buf_length, 
                                                         S32 layer_w, 
                                                         S32 layer_h)
{
    MMI_BOOL render_started_ok = MMI_FALSE;  
    srv_ies_result res;
        
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_CREATE_IMAGE_HANDLE);
    if(NULL == cell_p->ies_image_handle)
    {
        srv_ies_image_handle hImg = NULL;
        srv_ies_meta_handle meta_handle = NULL;

        if (cell_p->ies_meta_handle)
        {
            meta_handle = cell_p->ies_meta_handle;
        }

        res = srv_ies_image_create_from_file(
            g_mediacache_cntx_p->ies_app_session,
            (WCHAR*)filename_p, 
            meta_handle,
            &hImg);
        if(SRV_IES_OK == res)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MEDIA_CACHE_CREATED_IMAGE_X_ON_CELL_X, hImg, cell_p);
            cell_p->ies_image_handle = hImg;
            render_started_ok = MMI_TRUE;
        }
        else
        {
            cell_p->ies_image_handle = NULL;
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MEDIA_CACHE_CREATED_IMAGE_X_ON_CELL_X, hImg, cell_p);
            srv_mediacache_set_last_err(SRV_MEDIACACHE_ERR_GROUP_GDI, _srv_mediacache_gdi_result_from_ies_result(res));
            return MMI_FALSE;
        }
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_IT_IS_WRONG_FOR_WHAT);
        g_mediacache_cntx_p->decoding_p = NULL;
        g_mediacache_cntx_p->ies_decoding_handle = NULL;
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_DECODING_P_IS_NULL_D, __LINE__);
         if (g_mediacache_cntx_p->state == SRV_MEDIACACHE_STATE_RUNNING)
        {
            srv_mediacache_check_and_start_decode();  
        }
        return MMI_TRUE;
    }
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_CREATE_IMAGE_HANDLE);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_RENDER_ASYNC);
    res = srv_ies_image_render_buffer_async(
        cell_p->ies_image_handle,
        g_mediacache_cntx_p->ies_render_buffer, // here use ies working buffer, to avoid ies write to buffer while mmi is get this buffer
        buf_length,
        layer_w,
        layer_h,
        layer_w * 2,    // TODO: get bpp from color_format
        SRV_IES_COLORFORMAT_RGB565,
        _srv_mediacache_engine_ies_decode_cb,
        NULL,
        &g_mediacache_cntx_p->ies_decoding_handle);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_RENDER_ASYNC);
    render_started_ok = SRV_IES_OK == res ? MMI_TRUE : MMI_FALSE;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_IES_IES_START_RENDER_CELL_INDEX_IS_D_RESULT_IS_D,
        g_mediacache_cntx_p->decoding_p->file_index, res);
        
    // TODO: should not early return here.
    // Currently, if everything's fine, we early-return here
    // and pass the job handle back to client.
    if(render_started_ok)
    {
        MMI_ASSERT(g_mediacache_cntx_p->ies_decoding_handle);
        g_mediacache_cntx_p->db_save_decode_count++;
        return MMI_TRUE;
    }
    else
    {
        srv_mediacache_delete_image_handle_if_needed(cell_p);

        cell_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
        cell_p->err_code = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
        cell_p->err_group = SRV_MEDIACACHE_ERR_GROUP_GDI;

        srv_mediacache_set_last_err(SRV_MEDIACACHE_ERR_GROUP_GDI, SRV_MEDIACACHE_ERR_IES_RENDER_FAIL);

        return MMI_FALSE;
    }
}


static MMI_BOOL srv_mediacache_cache_meta_is_not_saved(srv_mediacache_cell_struct* curr_p, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_cell_finished = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == curr_p)
    {
        return MMI_FALSE;
    }
    if (curr_p->image_type != GDI_IMAGE_TYPE_JPG_FILE)
    {
        return MMI_FALSE;
    }
    /*
    if (curr_p->err_group == SRV_MEDIACACHE_ERR_GROUP_APP)
    {
        curr_p->is_ies_meta_saved = MMI_TRUE;
    }
    */
    if (MMI_FALSE == curr_p->is_ies_meta_saved && (SRV_MEDIACACHE_CACHE_STATE_DECODE_OK == curr_p->state))
    {
        is_cell_finished = MMI_TRUE;
    }
    return is_cell_finished;
}


S32 srv_mediacache_preview_get_current_size(srv_handle handle, S32 *width, S32 *height)
{
    S32 result = SRV_MEDIACACHE_OK;
    srv_ies_result ies_ret = SRV_IES_OK;
    S32 index = 0;
    srv_mediacache_cntx_struct *medialib_cntx_p = (srv_mediacache_cntx_struct *)handle;
    srv_mediacache_cell_struct *cell_tmp = NULL;
    
    index = srv_mediacache_get_curr_index(handle);
    
    cell_tmp = srv_mediacache_link_pingpang_check(medialib_cntx_p->level1_curr_p, MMI_FALSE, srv_mediacache_is_index_match, &index);

    if (cell_tmp)
    {
        if (cell_tmp->ies_preview_handle)
        {
            ies_ret = srv_ies_preview_get_current_size(cell_tmp->ies_preview_handle, width, height);

            if (ies_ret != SRV_IES_OK)
            {
                result = SRV_MEDIACACHE_ERR_IES_PREVIEW_GET_SIZE_FAIL;
            }
        }
        else
        {
            result = SRV_MEDIACACHE_ERR_IES_NO_PREVIEW_HANDLE;
        }
    }
    else
    {
        result = SRV_MEDIACACHE_ERR_NOT_READY;
    }

    return result;
}

S32 srv_mediacache_preview_get_current_rect(srv_handle handle, S32 *pLeft, S32 * pTop, S32 *pWidth, S32*pHeight)
{
    S32 result = SRV_MEDIACACHE_OK;
    srv_ies_result ies_ret = SRV_IES_OK;
    S32 index = 0;
    srv_mediacache_cntx_struct *medialib_cntx_p = (srv_mediacache_cntx_struct *)handle;
    srv_mediacache_cell_struct *cell_tmp = NULL;
    
    index = srv_mediacache_get_curr_index(handle);
    
    cell_tmp = srv_mediacache_link_pingpang_check(medialib_cntx_p->level1_curr_p, MMI_FALSE, srv_mediacache_is_index_match, &index);

    if (cell_tmp)
    {
        if (cell_tmp->ies_preview_handle)
        {
            ies_ret = srv_ies_preview_get_current_rect(cell_tmp->ies_preview_handle, pLeft, pTop, pWidth, pHeight);

            if (ies_ret != SRV_IES_OK)
            {
                result = SRV_MEDIACACHE_ERR_IES_PREVIEW_GET_SIZE_FAIL;
            }
        }
        else
        {
            result = SRV_MEDIACACHE_ERR_IES_NO_PREVIEW_HANDLE;
        }
    }
    else
    {
        result = SRV_MEDIACACHE_ERR_NOT_READY;
    }

    return result; 
}


static void srv_mediacache_free_meta_handle_if_needed(srv_handle handle, srv_mediacache_cell_struct *cell_p)
{   
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_META_START_OF_SRV_MEDIACACHE_FREE_META_BUFFER_HANDLE_IS_D_JOB_IS_D, cell_p->ies_meta_handle, cell_p->ies_meta_job_handle);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_META_SRV_MEDIACACHE_FREE_META_BUFFER_CELL_INDEX_IS_D_TYPE_IS_D, cell_p->file_index, cell_p->type);
    
    if (cell_p->ies_meta_handle)
    {
        srv_ies_meta_destroy(cell_p->ies_meta_handle);
        cell_p->ies_meta_handle = NULL;
    }

    if (cell_p->ies_meta_job_handle)
    {
        srv_ies_job_cancel(cell_p->ies_meta_job_handle);
        cell_p->ies_meta_job_handle = 0;
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_META_SET_META_JOB_HANDLE_TO_NULL_FILE_INDEX_D_D, cell_p->file_index, __LINE__);
    }

    cell_p->ies_meta_state = SRV_MEDIACACHE_META_STATE_IDLE;
    
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_META_END_OF_SRV_MEDIACACHE_FREE_META_BUFFER);
}

/* these code will be removed
static S32 srv_mediacache_malloc_meta_buffer(srv_handle handle, srv_mediacache_cell_struct *cell_p)
{
    U8 i = 0;
    srv_mediacache_cntx_struct *medialib_cntx_p = (srv_mediacache_cntx_struct *)handle;
    
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_SRV_MEDIACACHE_MALLOC_META_BUFFER);

    for (i = 0 ; i < SRV_MEDIACACHE_META_COUNT ; i++)
    {
        if (medialib_cntx_p->ies_meta[i].is_used == MMI_FALSE)
        {
            cell_p->ies_meta_buffer = medialib_cntx_p->ies_meta[i].buffer;
            cell_p->ies_meta_buffer_size = medialib_cntx_p->ies_meta[i].buffer_size;
            medialib_cntx_p->ies_meta[i].is_used = MMI_TRUE;
            break;
        }
    }
    
    if (i == SRV_MEDIACACHE_META_COUNT)
    {
        MMI_ASSERT(0);
    }
    
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_SRV_MEDIACACHE_MALLOC_META_BUFFER_HANDLE_POS_IS_D, i);

    return SRV_MEDIACACHE_OK;
}

static S32 srv_mediacache_free_meta_buffer(srv_handle handle, srv_mediacache_cell_struct *cell_p)
{
    U8 i = 0;
    srv_mediacache_cntx_struct *medialib_cntx_p = (srv_mediacache_cntx_struct *)handle;
    
    if (!cell_p)
    {
        MMI_ASSERT(0);
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_SRV_MEDIACACHE_FREE_META_BUFFER_HANDLE_IS_D_JOB_IS_D, cell_p->ies_meta_handle, cell_p->ies_meta_job_handle);

    if (cell_p->ies_meta_handle)
    {
        srv_ies_meta_destroy(cell_p->ies_meta_handle);
        cell_p->ies_meta_handle = NULL;
    }

    if (cell_p->ies_meta_job_handle)
    {
        srv_ies_job_cancel(cell_p->ies_meta_job_handle);
    }

    for (i = 0 ; i < SRV_MEDIACACHE_META_COUNT ; i++)
    {
        if (medialib_cntx_p->ies_meta[i].buffer == cell_p->ies_meta_buffer && (medialib_cntx_p->ies_meta[i].is_used == MMI_TRUE))
        {
            cell_p->ies_meta_buffer = NULL;
            cell_p->ies_meta_buffer_size = 0;
            medialib_cntx_p->ies_meta[i].is_used = MMI_FALSE;
            break;
        }
    }
    
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_SRV_MEDIACACHE_FREE_META_BUFFER);

    return SRV_MEDIACACHE_OK;
}

*/


static void srv_mediacache_cancel_nb_render(srv_mediacache_cell_struct *cell_p, MMI_BOOL reNew)
{
    if (g_mediacache_cntx_p->ies_decoding_handle)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_IES_IES_CANCEL_RENDER_CELL_INDEX_IS_D,
            g_mediacache_cntx_p->decoding_p->file_index);
        srv_ies_job_cancel(g_mediacache_cntx_p->ies_decoding_handle);
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_IES_IES_CANCEL_RENDER_END);
    }
    
    /* here is work around, for we want to draw image , but ies do not allow to draw. 
      so we destroy image and create it for draw */
    if (g_mediacache_cntx_p->decoding_p->ies_image_handle)
    {
        srv_ies_result ies_result;
        srv_ies_meta_handle meta_handle = NULL;

        if (g_mediacache_cntx_p->decoding_p->ies_meta_handle)
        {
            meta_handle = g_mediacache_cntx_p->decoding_p->ies_meta_handle;
        }

        ies_result = srv_ies_image_destroy(g_mediacache_cntx_p->decoding_p->ies_image_handle);
        g_mediacache_cntx_p->decoding_p->ies_image_handle = NULL;

        if (reNew)
        {
            S32 result;
            
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_SRV_IES_IMAGE_CREATE_FROM_FILE_HANDLE_IS_D_CELL_INDEX_ID_D,
                cell_p->ies_image_handle, cell_p->file_index);

            result = g_mediacache_cntx_p->engine.get_file_name(
                cell_p->file_index, 
                (U16*)g_mediacache_cntx_p->config.filename, 
                SRV_FMGR_PATH_BUFFER_SIZE,
                NULL);

            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_GET_FILE_NAME_RESULT_IS_D, result);
                
            result = srv_ies_image_create_from_file(g_mediacache_cntx_p->ies_app_session,
                (WCHAR*)g_mediacache_cntx_p->config.filename, 
                meta_handle,
                &cell_p->ies_image_handle);

            /* force the state to OK. so will not draw this image */
            cell_p->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_OK;
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_SRV_IES_IMAGE_CREATE_FROM_FILE_HANDLE_IS_D_CELL_INDEX_ID_D_META_IS_D,
                cell_p->ies_image_handle, cell_p->file_index, meta_handle);

            //MMI_ASSERT(result == SRV_IES_OK);
        }
    }

    g_mediacache_cntx_p->ies_decoding_handle = NULL;
    g_mediacache_engine_cntx.image_hdl_decoding = NULL;
    g_mediacache_cntx_p->image_hdl_decoding = 0;
    g_mediacache_cntx_p->decoding_p = NULL;
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_DECODING_P_IS_NULL_D, __LINE__);
}


#ifdef __SRV_MEDIACACHE_INTERNAL_TEST__
U8 path_buffer_temp[200];
U8 index_buffer[20];
U8 file_count = 0;
static void srv_mediacache_save_cell_img_to_file(srv_mediacache_cell_struct *cell_p)
{
    gdi_handle src_layer;
    
    gdi_layer_create_cf_using_outside_memory(
            g_mediacache_cntx_p->color_format,
            0,
            0,
            cell_p->image_width,
            cell_p->image_height,
            &src_layer,
            cell_p->buffer,
            g_mediacache_cntx_p->level1_buffer_size);
    
    kal_wsprintf((WCHAR*)path_buffer_temp, "%s%d%s", (PU8)"D:\\src", file_count, (PU8)".bmp");
    file_count++;
    gdi_layer_save_bmp_file(src_layer, (char*)path_buffer_temp);
    gdi_layer_free(src_layer);            
}
#endif


static void srv_mediacache_create_meta_handle(S32 meta_ret, U8* meta_buffer, S32 meta_buffer_length, srv_mediacache_cell_struct* cell_p)
{
    srv_ies_result ies_ret = SRV_IES_OK;
    
    if (meta_ret != 0)
    {
        //here means meta read from db fail
    }
    else
    {
        ies_ret = srv_ies_meta_create_from_buffer(g_mediacache_cntx_p->ies_app_session, meta_buffer, meta_buffer_length, &(cell_p->ies_meta_handle));
        if (ies_ret == SRV_IES_OK)
        {
            cell_p->ies_meta_state = SRV_MEDIACACHE_META_STATE_FINISHED;
            MMI_ASSERT(cell_p->ies_meta_handle); // we should get meta handle, else should ask ies why
        }
        else
        {
            //why create meta failed? it will lead the image display too late.
            //MMI_ASSERT(0);
            cell_p->ies_meta_state = SRV_MEDIACACHE_META_STATE_FINISHED_BUT_ERROR;
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_META_SRV_IES_META_CREATE_FROM_BUFFER_RESULT_IS_D, ies_ret);
        }
        cell_p->is_ies_meta_saved = MMI_TRUE;
    }
}


static MMI_BOOL srv_mediacache_cache_cell_is_meta_finished(srv_mediacache_cell_struct *cell)
{
    if (NULL == cell)
    {
        return MMI_FALSE;
    }

    if (cell->image_type != GDI_IMAGE_TYPE_JPG_FILE)
    {
        return MMI_TRUE;
    }
    
    if (cell->ies_meta_handle)
    {
        return MMI_TRUE;
    }

    if (cell->ies_meta_state == SRV_MEDIACACHE_META_STATE_FINISHED_BUT_ERROR)
    {
        return MMI_TRUE;
    }
    
    if (cell->ies_meta_job_handle)
    {
        return MMI_FALSE;
    }

    return MMI_FALSE;
}


static MMI_BOOL srv_mediacache_cache_cell_is_meta_unfinished(srv_mediacache_cell_struct *cell, void *user_dara)
{
    return (!srv_mediacache_cache_cell_is_meta_finished(cell));
}


static srv_mediacache_cell_struct *srv_mediacache_find_no_meta_cell(srv_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cntx_struct *medialib_cntx_p = (srv_mediacache_cntx_struct *)handle;   
    srv_mediacache_cell_struct *cache_cell= NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!medialib_cntx_p)
    {
        return NULL;
    }
    
    switch(medialib_cntx_p->decode_method)
    {
    case SRV_MEDIACACHE_CACHE_METHOD_DEFAULT:
        cache_cell = srv_mediacache_link_pingpang_check(medialib_cntx_p->level1_curr_p,MMI_FALSE,
            srv_mediacache_cache_cell_is_meta_unfinished,NULL);
        break;
        
    case SRV_MEDIACACHE_CACHE_METHOD_M1:
        cache_cell = srv_mediacache_link_line_check(medialib_cntx_p->level1_curr_p,
            srv_mediacache_cache_cell_is_meta_unfinished,NULL);
        break;
        
    default:
        ASSERT(0);
    }

    return cache_cell;
}


static void srv_mediacache_create_meta_handle_for_rest_cell(srv_handle handle)
{
    srv_mediacache_cntx_struct *medialib_cntx_p = (srv_mediacache_cntx_struct *)handle;
    srv_mediacache_cell_struct *cell_p = NULL;

    if (!medialib_cntx_p->is_using_ies)
    {
        return ;
    }
    
    if (!medialib_cntx_p->ies_meta_p)
    {
        cell_p = srv_mediacache_find_no_meta_cell(handle);
    }

    if (cell_p)
    {
        S32 result;

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_GET_FILE_NAME);
        result = g_mediacache_cntx_p->engine.get_file_name(
            cell_p->file_index, 
            (U16*)g_mediacache_cntx_p->config.filename, 
            SRV_FMGR_PATH_BUFFER_SIZE,
            NULL);
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_GET_FILE_NAME);
        
        if (result < 0)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SRV_MEDIACACHE_INFO_GET_NAME_FAILED,result, __LINE__);            
        }
        else
        {
            srv_mediacache_create_meta_if_needed(
                handle, 
                cell_p, 
                (WCHAR*)g_mediacache_cntx_p->config.filename, 
                cell_p->image_width, 
                cell_p->image_height);
        }
    }
}


static void srv_mediacache_meta_save_to_db_callback(S32 err, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_cell_struct *cell_p = (srv_mediacache_cell_struct *)user_data;
    srv_mediacache_cell_struct *cell_tmp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cell_tmp = srv_mediacache_link_pingpang_check(g_mediacache_cntx_p->level1_curr_p, MMI_FALSE, srv_mediacache_is_index_match, &cell_p->file_index);
    if (!cell_tmp)
    {
        //here means the cell is out of your view
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_WARING_WHEN_CALLBACK_THE_CELL_IS_NO_LONG_USED_INDEX_IS_D, cell_p->file_index);
        return ;
    }

    cell_p->is_ies_meta_saved = MMI_TRUE;
    gui_start_timer(SRV_MEDIACACHE_SAVE2DB_TIME_GAP_NORMAL, srv_mediacache_save_to_db_schedule);  
}

#endif /* __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__*/


void srv_mediacache_util_fix_box(
        S32 bbox_width,
        S32 bbox_height,
        S32 src_width,
        S32 src_height,
        S32 *offset_x,
        S32 *offset_y,
        S32 *dest_width,
        S32 *dest_height,
        U16 image_type)
{
#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
    if (image_type == GDI_IMAGE_TYPE_JPG_FILE)
    {
        srv_ies_util_fit_bbox(bbox_width,bbox_height,src_width,src_height,offset_x,offset_y,dest_width,dest_height);
    }
    else
    {
        gdi_util_fit_box(GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT, bbox_width,bbox_height,src_width,src_height,offset_x,offset_y,dest_width,dest_height);
        //gdi_image_util_fit_bbox(bbox_width,bbox_height,src_width,src_height,offset_x,offset_y,dest_width,dest_height);
    }
#else
    gdi_util_fit_box(GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT, bbox_width,bbox_height,src_width,src_height,offset_x,offset_y,dest_width,dest_height);
#endif
}

void srv_mediacache_config_image_decode_and_get_source(srv_handle handle, MMI_BOOL is_from_ies_first, U8 *working_buffer, U32 buf_size)
{
#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_mediacache_cntx_struct *medialib_cntx_p = (srv_mediacache_cntx_struct *)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_START_OF_SRV_MEDIACACHE_CONFIG_IMAGE_DECODE_AND_GET_SOURCE_USE_SCALADO_D, is_from_ies_first);

    if (is_from_ies_first)
    {
        medialib_cntx_p->is_using_ies = MMI_TRUE;
    #ifdef __MMI_SRV_IES_META__
        g_mediacache_cntx_p->is_using_meta = MMI_TRUE;
    #endif
    #ifdef __MMI_SRV_IES_META_DB__
        g_mediacache_cntx_p->is_meta_using_db = MMI_TRUE;
    #endif
        g_mediacache_cntx_p->is_put_meta_urgent = MMI_FALSE;
        
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_DECODING_APP_ASSIGN_IES_BUFFER_X_D, working_buffer, buf_size);
        g_mediacache_cntx_p->ies_app_working_buf = working_buffer;
        g_mediacache_cntx_p->ies_app_working_buf_size = buf_size;
    }
    else
    {
        g_mediacache_cntx_p->ies_app_working_buf = NULL;
        g_mediacache_cntx_p->ies_app_working_buf_size = NULL;
    }    

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_SRVMC_PMD_END_OF_SRV_MEDIACACHE_CONFIG_IMAGE_DECODE_AND_GET_SOURCE);
#endif
}


MMI_BOOL srv_mediacache_is_current_cache_using_ies(void)
{
    MMI_BOOL ret = MMI_FALSE;

    if (g_mediacache_cntx_p)
    {
        if ((g_mediacache_cntx_p->medialib_mark == (srv_handle)g_mediacache_cntx_p) && 
            (g_mediacache_cntx_p->is_using_ies == MMI_TRUE))
        {
            ret = MMI_TRUE;
        }
    }

    return ret;
}

void srv_mediacache_config_alignment(srv_handle handle, MMI_BOOL use_cache_align)
{
    g_mediacache_cntx_p->is_align_cache = use_cache_align;
}

void* srv_mediacache_get_ivd_handle(srv_handle handle)
{
#if defined(__SQLITE3_SUPPORT__)
    if((U32)g_mediacache_cntx_p != (U32)handle)
    {
        return NULL;
    }
    
    if(g_mediacache_cntx_p->is_db_start_ok)
    {
        return &g_mediacache_cntx_p->db_handle;
    }
    else
    {
        return NULL;
    }
#else
    return NULL;
#endif
}

#endif /* defined(__MMI_SRV_MEDIACACHE__*/

