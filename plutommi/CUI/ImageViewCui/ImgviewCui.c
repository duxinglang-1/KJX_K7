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
 *  ImgViewCui.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is image view CUI API implimentation.
 *
 * Author:
 * -------
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_IMAGE_VIEWER__)
#include "GlobalResDef.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_scenario_gprot.h"

#include "CommonScreensResDef.h"
#include "AlertScreen.h"
#include "InlineCuiGprot.h"
#include "FileMgrType.h"
#include "FileMgrSrvGprot.h"

#include "ImgviewerConfig.h"
#include "ImgViewerGprot.h"
#include "ImageViewCuiGprot.h"
#include "ImgviewCui.h"
#include "Menucuigprot.h"

/*
 * external Util functions
 */
 #if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__) 
 extern MMI_BOOL mmi_camera_enter_imageviewer_check(void);
 #endif
/* 
 * the memory alloc and free is just a temporary solution for allocating memory for CUI by user 
 * is not applied commonly. When the new memory mechanism is applied, we can replace these functions.
 */
static cui_iv_cntx g_ivcui_cntx;

static S32 cui_iv_fl_init(void);


extern MMI_BOOL enter_imageviewer;

#ifdef __MMI_AP_DCM_CAMIMGV__
#pragma arm section rodata = "DYNAMIC_CODE_CAMIMGV_RODATA",code = "DYNAMIC_CODE_CAMIMGV_ROCODE"
#endif

/*****************************************************************************
 * FUNCTION
 *  cui_iv_malloc_base
 * DESCRIPTION
 *  allocate App base memory.
 * PARAMETERS
 *  app_id      [IN]        
 *  size        [IN]        
 * RETURNS
 *  address of memory.(?)
 *****************************************************************************/
IV_MOD_API void *cui_iv_malloc_base(U16 app_id, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *pmem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_IV_NEW_MEM__
    pmem = applib_mem_ap_alloc_framebuffer(app_id, size);
    MMI_ASSERT(pmem != NULL);
#else /* __MMI_IV_NEW_MEM__ */ 
    if (g_ivcui_cntx.cui_gid != GRP_ID_INVALID)
    {
        mmi_group_event_struct evt;

        /* single instance will use global context */
        evt.evt_id = EVT_ID_IMGVIEW_CLOSE;
        evt.sender_id = g_ivcui_cntx.cui_gid;
        evt.size = sizeof(mmi_group_event_struct);
        mmi_frm_group_send_to_parent(g_ivcui_cntx.cui_gid, &evt);

    }

    pmem = &g_ivcui_cntx;

#endif /* __MMI_IV_NEW_MEM__ */ 

    return pmem;

}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_free_base
 * DESCRIPTION
 *  free App base memory.
 * PARAMETERS
 *  app_id      [IN]        
 *  pmem        [IN]        Memory to free
 * RETURNS
 *  void
 *****************************************************************************/
IV_MOD_API void cui_iv_free_base(U16 app_id, void *pmem)
{
#ifdef __MMI_IV_NEW_MEM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_free(pmem);
    applib_mem_ap_notify_stop_finished(app_id, KAL_TRUE);

#else /* __MMI_IV_NEW_MEM__ */ 
    g_ivcui_cntx.cui_gid = GRP_ID_INVALID;
#endif /* __MMI_IV_NEW_MEM__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_malloc_fg
 * DESCRIPTION
 *  allocate App foreground memory.
 * PARAMETERS
 *  app_id      [IN]        
 *  size        [IN]        
 * RETURNS
 *  address of memory.(?)
 *****************************************************************************/
IV_MOD_API void *cui_iv_malloc_fg(U16 app_id, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_free_fg
 * DESCRIPTION
 *  allocate App foreground memory.
 *  app_id:     [IN]
 *  pmem:       [IN]    memory to free
 * RETURNS
 *  void
 *****************************************************************************/
IV_MOD_API void cui_iv_free_fg(U16 app_id, void *pmem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

/*
 * external Util functions end **************************
 */


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_free_cntx
 * DESCRIPTION
 *  This function reset user date structure.
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_imgview_free_cntx(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_evt_struct *evt_s = (mmi_scenario_evt_struct*) evt;
    cui_iv_cntx *pcui;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pcui = (cui_iv_cntx*) mmi_frm_group_get_user_data(evt_s->targ_group);
    if (pcui != NULL)
    {
        /* need check: free other member */
        cui_iv_restore_file_list(pcui);
        cui_iv_free_base(pcui->app_id, pcui);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_group_proc
 * DESCRIPTION
 *  Image view cui process function.
 * PARAMETERS
 *  evt     [IN]        Events pointer.
 * RETURNS
 *  mmi_ret.
 *****************************************************************************/
static mmi_ret cui_imgview_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_TRACE(MMI_MEDIA_TRC_G2_APP, CUI_IMGVIEW_PROC, evt->evt_id); */
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            /* gobackhistory ToDo1 */
            cui_imgview_free_cntx(evt);
		#ifdef __MMI_AP_DCM_CAMIMGV__
			if(!enter_imageviewer
		#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__) 
        	&& !mmi_camera_enter_imageviewer_check()
		#endif
			)
        	{
        		mmi_ap_post_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_CAMIMGV);
    		}
        #endif
            break;
        case EVT_ID_ALERT_QUIT:
            /* cui_imgview_alert_proc(evt); */
            break;
        case EVT_ID_CUI_INLINE_NOTIFY:
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        case EVT_ID_CUI_INLINE_ABORT:
            /* cui_imgview_inline_cui_proc(evt); */
            break;
        default:
    #ifdef __MMI_IVF_OPTION__

            if (cui_menu_is_menu_event(evt->evt_id))
            {
                cui_iv_menu_proc(evt);
            }
    #endif /* __MMI_IVF_OPTION__ */ 
            break;
    }
    return MMI_RET_OK;
}

#ifdef __MMI_AP_DCM_CAMIMGV__
#pragma arm section rodata,code
#endif

/*****************************************************************************
 * FUNCTION
 *  cui_imgview_create_ex
 * DESCRIPTION
 *  Create imageview CUI.
 * PARAMETERS
 *  app_id          [IN]        App for memory allocation.
 *  parent_gid      [IN]        Group id of the CUI's parent.
 * RETURNS
 *  id of the CUI created.
 *****************************************************************************/
IV_API mmi_id cui_imgview_create_ex(U16 app_id, mmi_id parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_cntx *pcui;
    mmi_id cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AP_DCM_CAMIMGV__
    mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_CAMIMGV);
#endif
    /* Create cui object */
    pcui = (cui_iv_cntx*) cui_iv_malloc_base(app_id, sizeof(cui_iv_cntx));
    kal_mem_set(pcui, 0, sizeof(cui_iv_cntx));
    pcui->disp_cap = CUI_IV_INIT_DISP_CAP;
    cui_id = mmi_frm_group_create(parent_gid, GRP_ID_AUTO_GEN, cui_imgview_group_proc, (void*)pcui);
    pcui->app_id = app_id;
    pcui->cui_gid = cui_id;
    return cui_id;

}

#ifdef __MMI_AP_DCM_CAMIMGV__
#pragma arm section rodata = "DYNAMIC_CODE_CAMIMGV_RODATA",code = "DYNAMIC_CODE_CAMIMGV_ROCODE"
#endif

/*****************************************************************************
 * FUNCTION
 *  cui_imgview_run
 * DESCRIPTION
 *  Run image view cui.
 * PARAMETERS
 *  cui_id      [IN]        Image view cui id.
 * RETURNS
 *  void
 *****************************************************************************/
IV_API void cui_imgview_run(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_cntx *pcui;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pcui = (cui_iv_cntx*) mmi_frm_group_get_user_data(cui_id);
    MMI_ASSERT(pcui != NULL && pcui->src_mode != IMGVIEW_SRC_INVALID);
    cui_iv_fl_init();
    cui_iv_create_mscrn(pcui);
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_close
 * DESCRIPTION
 *  Close image view cui.
 * PARAMETERS
 *  cui_id      [IN]        Image view cui id.
 * RETURNS
 *  void
 *****************************************************************************/
IV_API void cui_imgview_close(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_init_display
 * DESCRIPTION
 *  Set the display capbility of the CUI.
 *  Must call it after cui_imgview_create()and before cui_imgview_run().
 *  CUI will have the default display screen if user don't call this function.
 * PARAMETERS
 *  cui_id              [IN]        Image view cui id.
 *  cap                 [IN]        Can be or by the available values. See capbility values.
 * RETURNS
 *  MMI_TRUE : success.
 *  MMI_TRUE : failed.
 *****************************************************************************/
IV_API MMI_BOOL cui_imgview_init_display(mmi_id cui_id, U32 cap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_cntx *pcui;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pcui = (cui_iv_cntx*) mmi_frm_group_get_user_data(cui_id);
    MMI_ASSERT(pcui != NULL);
    /* to check: validate the value of ablility */
    pcui->disp_cap = cap;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_get_dispcap
 * DESCRIPTION
 *  Get display capbility.
 *  User can use the result of this function to cui_imgview_init_display by set
 *  or clear specified bits.
 * PARAMETERS
 *  cui_id      [IN]        Image view cui id.
 * RETURNS
 *  Display capbility
 *****************************************************************************/
IV_API U32 cui_imgview_get_dispcap(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_cntx *pcui;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pcui = (cui_iv_cntx*) mmi_frm_group_get_user_data(cui_id);
    MMI_ASSERT(pcui != NULL);
    return pcui->disp_cap;
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_is_rotate
 * DESCRIPTION
 *  If the UI is roate.
 * PARAMETERS
 *  cui_id      [IN]        Image view cui id.
 * RETURNS
 *  
 *****************************************************************************/
IV_API MMI_BOOL cui_imgview_is_rotate(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_cntx *pcui;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pcui = (cui_iv_cntx*) mmi_frm_group_get_user_data(cui_id);
    MMI_ASSERT(pcui != NULL);

    return pcui->disp_cap & CUI_IMGVIEW_DISP_ROT ? MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_set_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cui_id      [IN]        
 *  ptitle      [IN]        
 *  icon        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
IV_API void cui_imgview_set_title(mmi_id cui_id, const WCHAR *ptitle, U16 icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_cntx *pcui;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pcui = (cui_iv_cntx*) mmi_frm_group_get_user_data(cui_id);
    MMI_ASSERT(pcui != NULL);

    pcui->ptitle = ptitle;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_load_file_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret cui_iv_load_file_cb(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param->evt_id == EVT_ID_SRV_FMGR_FILELIST_LOAD_RESULT)
    {
        srv_fmgr_filelist_load_result_event_struct *evt = (srv_fmgr_filelist_load_result_event_struct*) param;
        cui_iv_cntx *pcui = (cui_iv_cntx*) evt->user_data;
        cui_iv_scrndata *pscrn = &pcui->scrn_data;

        if (evt->result == 0)
        {
            if (pcui->index >= (U32) (evt->ready_index_start) && pcui->index < (U32) (evt->ready_index_end))
            {
                srv_fmgr_filelist_get_filepath(
                    pcui->h_list,
                    pcui->index,
                    (WCHAR*) pcui->file_name,
                    SRV_FMGR_PATH_BUFFER_SIZE);
            }
            else
            {
                cui_iv_load_filename(pcui, pcui->index, pscrn->load_file_usrdata, pscrn->load_file_complete_cb);
                return MMI_RET_OK;
            }
        }

        if (pscrn->load_file_complete_cb)
        {
            pscrn->load_file_complete_cb(pscrn->load_file_usrdata, evt->result);
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_get_cur_index
 * DESCRIPTION
 *  Get index of the image currently view.
 * PARAMETERS
 *  cui_id                  [IN]        
 * RETURNS
 *  Image index
 *****************************************************************************/
IV_API S32 cui_imgview_get_cur_index(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_cntx *pcui;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pcui = (cui_iv_cntx*) mmi_frm_group_get_user_data(cui_id);
    MMI_ASSERT(pcui != NULL);

    return pcui->index;
}

IV_API const WCHAR *cui_imgview_get_cur_filename(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_cntx *pcui;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pcui = (cui_iv_cntx*) mmi_frm_group_get_user_data(cui_id);
    MMI_ASSERT(pcui != NULL);

    return srv_fmgr_path_get_filename_ptr(pcui->file_name);
    
}

/*****************************************************************************
 *
 *  For srv_fmgr_filelist_abort not complete the excepted function. 
 *  So emulate the cancel function here.
 *
 *****************************************************************************/
static mmi_proc_func cui_iv_load_file_cb_p = NULL;


/*****************************************************************************
 * FUNCTION
 *  cui_iv_cancel_load_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
IV_MOD_API void cui_iv_cancel_load_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_iv_load_file_cb_p = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_emu_load_file_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret cui_iv_emu_load_file_cb(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cui_iv_load_file_cb_p)
    {
        cui_iv_load_file_cb_p(param);
    }

    return MMI_RET_OK;
}

/*
 * File list state.
 */
enum {
    CUI_IV_FL_STAT_INIT = 0,
    CUI_IV_FL_STAT_REFRESH, /* use new and waiting for refreshing result */
    CUI_IV_FL_STAT_CHANGED    /* use new and refreshing terminate */
};

/*
 * context of file list
 */
typedef struct{
    U32         stat;
    FMGR_FILTER filter;
    U32         sort;
}cui_iv_fl_context_t;

static cui_iv_fl_context_t g_fl_cntx;

/*****************************************************************************
 * FUNCTION
 *  cui_iv_fl_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param            
 * RETURNS
 *  
 *****************************************************************************/
static S32 cui_iv_fl_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&g_fl_cntx, 0, sizeof(g_fl_cntx));

    return 1;
}

/*****************************************************************************
 * FUNCTION
 *  cui_iv_fl_refresh_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param            
 * RETURNS
 *  
 *****************************************************************************/

static mmi_ret cui_iv_fl_refresh_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_filelist_refresh_result_event_struct *evt = (srv_fmgr_filelist_refresh_result_event_struct*) param;
    cui_iv_cntx *pcui = (cui_iv_cntx *)evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(param->evt_id) 
    {
    case EVT_ID_SRV_FMGR_FILELIST_REFRESH_RESULT:
        {  
            if (evt->result >= 0)
            {
                pcui->index = evt->search_index;
                pcui->count = evt->total_count;
                g_fl_cntx.stat = CUI_IV_FL_STAT_CHANGED;
                cui_iv_load_file_cb_p = NULL;
                cui_iv_create_mscrn(pcui);
                mmi_alert_dismiss(pcui->wait_scrn_id);
            }
        }
        break;
    }

    return MMI_RET_OK;
    
}

/*****************************************************************************
 * FUNCTION
 *  cui_iv_init_file_list
 * DESCRIPTION
 *  Check if the file list need to refresh with image filter.
 * PARAMETERS
 *  param            
 * RETURNS
 *  0 -- File list is OK
 *  1 -- Refreshing list.
 *****************************************************************************/
IV_MOD_API S32 cui_iv_init_file_list(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(pcui->src_mode != IMGVIEW_SRC_FILELIST){
        return 0;
    }
    
    if(g_fl_cntx.stat == CUI_IV_FL_STAT_CHANGED){
        return 0;
    }
    
    mmi_imgview_init_img_filter(&filter);
    srv_fmgr_filelist_get_setting(pcui->h_list, &g_fl_cntx.filter, &g_fl_cntx.sort);

    if(!memcmp(&filter, &g_fl_cntx.filter, sizeof(FMGR_FILTER))){
        
        return 0;
    }

    g_fl_cntx.stat = CUI_IV_FL_STAT_REFRESH;

    srv_fmgr_filelist_get_filename(
                            pcui->h_list,
                            pcui->index,
                            (WCHAR*) pcui->file_name,
                            SRV_FMGR_PATH_BUFFER_SIZE);

    srv_fmgr_filelist_set_setting(pcui->h_list, &filter, g_fl_cntx.sort);
    cui_iv_load_file_cb_p = cui_iv_fl_refresh_proc;
    srv_fmgr_filelist_refresh(pcui->h_list, pcui->file_name, 0, 0, cui_iv_emu_load_file_cb, pcui);
    return 1;
}

/*****************************************************************************
 * FUNCTION
 *  cui_iv_restore_file_list
 * DESCRIPTION
 *  Restore file list. Only be called from group de-init process.
 * PARAMETERS
 *  param            
 * RETURNS
 *  0 -- File list is OK
 *  1 -- Refreshing list.
 *****************************************************************************/

IV_MOD_API void cui_iv_restore_file_list(cui_iv_cntx *pcui)
{
     if(g_fl_cntx.stat != CUI_IV_FL_STAT_INIT){
        srv_fmgr_filelist_set_setting(pcui->h_list, &g_fl_cntx.filter, g_fl_cntx.sort);
        srv_fmgr_filelist_abort(pcui->h_list);
    }

    cui_iv_load_file_cb_p = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  cui_iv_get_filename
 * DESCRIPTION
 *  If the UI is roate.
 * PARAMETERS
 *  pcui            [?]         
 *  index           [IN]        
 *  filepath        [OUT]       
 *  loadProc        [IN]        
 *  userData        [?]         
 * RETURNS
 *  0  -- success(?)
 *  1  -- loading(?)
 *  -1 -- error(?)
 *****************************************************************************/
IV_MOD_API S32 cui_iv_get_filename(
                cui_iv_cntx *pcui,
                U32 index,
                WCHAR *filepath,
                mmi_proc_func loadProc,
                void *userData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (pcui->src_mode)
    {
        case IMGVIEW_SRC_FILELIST:
        {
            result = srv_fmgr_filelist_get_filepath(pcui->h_list, index, filepath, SRV_FMGR_PATH_BUFFER_SIZE);
            if (result >= 0)
                result = 0; /* Success */
            else if (result == SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY || result == SRV_FMGR_FILELIST_ERROR_BUSY)
            {
                result = 1; /* Loading */

                if (NULL != loadProc)
                {
                    S32 ret = srv_fmgr_filelist_load_file(pcui->h_list, index, cui_iv_emu_load_file_cb, userData);

                    if (SRV_FMGR_FILELIST_ERROR_FILE_READY == ret)
                    {
                        result = 0; /* Success */
                        cui_iv_load_file_cb_p = NULL;

                        srv_fmgr_filelist_get_filepath(
                            pcui->h_list,
                            index,
                            (WCHAR*) pcui->file_name,
                            SRV_FMGR_PATH_BUFFER_SIZE);
                    }
                    else
                    {
                        cui_iv_load_file_cb_p = loadProc;
                    }
                }
            }
            else
                result = -1;    /* Error */
        }
            break;
        case IMGVIEW_SRC_FILE:
            kal_wstrcpy(filepath, pcui->file_name);
            result = 0;
            break;

        case IMGVIEW_SRC_GET_FILE:
        {
            cui_imgview_get_filename_event_struct evt;

            evt.index = index;
            evt.path_buffer = (WCHAR*) pcui->file_name;
            evt.path_buffer_size = SRV_FMGR_PATH_BUFFER_SIZE;
            evt.evt_id = EVT_ID_IMGVIEW_GET_FILENAME;
            evt.sender_id = pcui->cui_gid;
            evt.size = sizeof(cui_imgview_get_filename_event_struct);
            mmi_frm_group_send_to_parent(pcui->cui_gid, (mmi_group_event_struct*) & evt);
        }
            break;

        default:
            break;

    };
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_load_filename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pcui            [?]         
 *  index           [IN]        
 *  userData        [?]         
 *  complete        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
IV_MOD_API void cui_iv_load_filename(cui_iv_cntx *pcui, U32 index, void *userData, async_cb_t complete)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = cui_iv_get_filename(pcui, index, pcui->file_name, cui_iv_load_file_cb, (void*)pcui);
    if (1 == ret)
    {
        pcui->scrn_data.load_file_complete_cb = complete;
        pcui->scrn_data.load_file_usrdata = userData;
    }

    if(complete)
        complete(userData, ret);
}

#if defined(__MMI_IVF_CACHE_DB__)


/*****************************************************************************
 * FUNCTION
 *  cui_iv_get_folder_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pcui            [?]     
 *  folderPath      [?]     
 * RETURNS
 *  0--ok
 *  1--loading
 *  -1--error
 *****************************************************************************/
IV_MOD_API S32 cui_iv_get_folder_path(cui_iv_cntx *pcui, WCHAR *folderPath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(pcui->src_mode == IMGVIEW_SRC_FILELIST)
    {
        S32 ret = srv_fmgr_filelist_get_filepath(
                    pcui->h_list,
                    pcui->index,
                    folderPath,
                    SRV_FMGR_PATH_BUFFER_SIZE);

        if (FS_NO_ERROR == ret)
        {
            srv_fmgr_path_get_filename_ptr(folderPath)[0] = 0;
            return 0;
        }
        else if (SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY == ret ||
            SRV_FMGR_FILELIST_ERROR_BUSY == ret)
        {
            return 1;
        }
        else
        {
            folderPath[0] = 0;
            return -1;
        }
    }

    return 0;
}
#endif /* defined(__MMI_IVF_CACHE_DB__) */ 


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_init_source
 * DESCRIPTION
 *  Init source for CUI.
 * PARAMETERS
 *  cui_id      [IN]        Image view cui id.
 *  mode        [IN]        Source mode.
 *  pdata       [IN]        Data of source. See cui_imgview_src_data.
 * RETURNS
 *  Default ability
 *****************************************************************************/
IV_API MMI_BOOL cui_imgview_init_source(mmi_id cui_id, cui_imgview_src_mode mode, const cui_imgview_src_data *pdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_iv_cntx *pcui;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(pdata != NULL);

    pcui = (cui_iv_cntx*) mmi_frm_group_get_user_data(cui_id);
    MMI_ASSERT(pcui != NULL);
    pcui->src_mode = mode;

    switch (mode)
    {
        case IMGVIEW_SRC_FILELIST:
            pcui->h_list = pdata->file_list.h_list;
            pcui->index = pdata->file_list.cur_index;
            pcui->count = srv_fmgr_filelist_count(pcui->h_list);
            break;

        case IMGVIEW_SRC_FILE:
            kal_wstrcpy(pcui->file_name, pdata->file.pname);
            if (!pcui->ptitle)
                pcui->ptitle = srv_fmgr_path_get_filename_const_ptr(pcui->file_name);
            pcui->count = 1;
            break;

        case IMGVIEW_SRC_GET_FILE:
            pcui->count = pdata->get_file.count;
            pcui->index = pdata->get_file.cur_index;
            break;

        default:
            return MMI_FALSE;

    };

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pcui        [?]     
 * RETURNS
 *  
 *****************************************************************************/
IV_MOD_API S32 cui_iv_close(cui_iv_cntx *pcui)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_group_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* single instance will use global context */
    evt.evt_id = EVT_ID_IMGVIEW_CLOSE;
    evt.sender_id = pcui->cui_gid;
    evt.size = sizeof(mmi_group_event_struct);
    mmi_frm_group_send_to_parent(pcui->cui_gid, &evt);
    return 0;
}

#ifdef __MMI_AP_DCM_CAMIMGV__
#pragma arm section rodata,code
#endif
#endif /* defined(__MMI_IMAGE_VIEWER__) */ 

