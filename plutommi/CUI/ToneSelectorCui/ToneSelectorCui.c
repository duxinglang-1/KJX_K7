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
*  ToneSelectorCui.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Tone selector common UI.
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "MMI_features.h"

#if !defined(__MMI_BASIC_UI_STYLE__) && !defined(__OP01_FWPBW__)

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "wgui_touch_screen.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "GlobalResDef.h"
#include "kal_public_api.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "wgui_categories.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_res_range_def.h"
#include "device.h"
#include "gui_typedef.h"
#include "gui_data_types.h"
#include "fs_type.h"
#include "drm_def.h"
#include "fs_errcode.h"
#include "mmi_rp_file_type_def.h"
#include "CustDataRes.h"
#include "AlertScreen.h"
#include "string.h"
#include "FileMgrType.h"
#include "mmi_theme_mgr.h"
#include "fs_func.h"
#include "custom_mmi_default_value.h"
#include "Unicodexdcl.h"
#include "mmi_rp_cui_toneselector_def.h"
#include "mmi_frm_timer_gprot.h"

#include "mmi_media_app_trc.h"


//#include "MMI_include.h"
#include "mmi_frm_scenario_gprot.h"

#include "DRM_gprot.h"
//#include "UsbDeviceGprot.h"
#include "UCMGProt.h"
#include "UcmSrvGprot.h"
//#include "CommonScreens.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mmi_rp_app_profiles_def.h"

//#include "FileMgr.h"
//#include "FileManagerDef.h"
//#include "FileManagerGProt.h"
//#include "Conversions.h"
#include "FileMgrCuiGProt.h"
#include "FileMgrSrvGProt.h"

#include "ProfilesSrvGProt.h"
#include "custom_srv_prof_defs.h"
#include "ProfilesAppGprot.h"
//#include "ProfileGprots.h"
//#include "ProfilesGexdcl.h"
//#include "ProfilesDefs.h"

#include "ToneSelectorCuiGprot.h"
#include "ToneSelectorCui.h"
#include "Gpiosrvgprot.h"

static mmi_ret cui_tone_selector_group_proc(mmi_event_struct* evt);
static cui_tonesel_mem_struct * cui_tone_selector_get_memory(void);
static void cui_tone_selector_free_memory(cui_tonesel_mem_struct * p);
static void cui_tone_selector_listscr_entry (void);
static void cui_tone_selector_listscr_exit (void);
static U16 cui_tone_selector_creat_tone_list(U16 cur_audio_id, U16 tone_filter, U16 *selecteditem);
static void cui_tone_selector_listscr_highlight_hdlr(S32 index);
static void cui_tone_selector_tone_selected(void);
static void cui_tone_selector_exit_req (void);
static void cui_tone_selector_post_res_to_parent(MMI_BOOL is_default_sound);

static void cui_tone_selector_play_tone_callback(mdi_result result, void *user_data);
static void cui_tone_selector_preview_play_tone(void);
static void cui_tone_selector_preview_stop_tone(void);
static void cui_tone_selector_inc_volume(void);
static void cui_tone_selector_dec_volume(void);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void cui_tone_selector_list_tap_callback(mmi_tap_type_enum tap_type,S32 index);
#endif

static void cui_tone_selector_extmld_add_hdlr (void);
static void cui_tone_selector_fmgr_selected(mmi_id fs_gid);

#ifdef __BT_SPK_VOL_CONTROL__
static MMI_BOOL cui_tone_selector_handfree_volume_sync_callback(U8 volume, MMI_BOOL is_mute);
#endif

#if defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
static MMI_BOOL cui_tone_selector_check_theme_audio(U16 tone_id);
#endif

#ifdef __GAIN_TABLE_SUPPORT__
static void cui_tone_selector_set_audio(void);
static void cui_tone_selector_reset_audio(void);
#endif

#define max_instances   2
cui_tonesel_mem_struct g_tonesel_mem_a[max_instances];
static cui_tonesel_cntx_struct g_tonesel_cntx;

/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_create
 * DESCRIPTION
 *  creat the CUI.
 * PARAMETERS
 *  mmi_id parent_gid
 * RETURNS
 *  void
 *****************************************************************************/
mmi_id cui_tone_selector_create(mmi_id parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id ts_gid;
    cui_tonesel_mem_struct *instance_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUI_TONESEL_CREATE, parent_gid);

#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
	    mmi_ucm_app_entry_error_message();
        return GRP_ID_INVALID;
    }
#endif /* __MMI_BACKGROUND_CALL__ */

    instance_data = cui_tone_selector_get_memory(); 
    if (instance_data != NULL)
    {
        ts_gid = mmi_frm_group_create(parent_gid, GRP_ID_AUTO_GEN, cui_tone_selector_group_proc, instance_data);
        if (ts_gid == GRP_ID_INVALID)
        {
            cui_tone_selector_free_memory(instance_data);
            return GRP_ID_INVALID;
        }
        /*set default value*/
        instance_data->str_id = STR_GLOBAL_LIST;
        instance_data->img_id = IMG_NONE;
        instance_data->tone_filter = 0x3F;
        instance_data->selected_tone = 0;
    }
	else
	{
		return GRP_ID_INVALID; /*fail!*/
	}
    return ts_gid;
}


/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_set_title_id
 * DESCRIPTION
 *  set string id and image id for title.
 * PARAMETERS
 *  mmi_id ts_gid
 *  mmi_id str_id
 *  mmi_id img_id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_tone_selector_set_title_id (mmi_id ts_gid, mmi_id str_id, mmi_id img_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_tonesel_mem_struct *instance_data = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    instance_data = (cui_tonesel_mem_struct *) mmi_frm_group_get_user_data(ts_gid);
    if (instance_data != NULL)
    {
        instance_data->str_id = str_id;
        instance_data->img_id = img_id;
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_set_highlight_tone
 * DESCRIPTION
 *  set current tone for the CUI.
 * PARAMETERS
 *  mmi_id ts_gid
 *  mmi_id selected_tone
 * RETURNS
 *  void
 *****************************************************************************/
void cui_tone_selector_set_highlight_tone(mmi_id ts_gid, mmi_id highlight_tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_tonesel_mem_struct *instance_data = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUI_TONESEL_SET_TONE, highlight_tone);

    instance_data = (cui_tonesel_mem_struct *) mmi_frm_group_get_user_data(ts_gid);
    if (instance_data != NULL)
    {
        if ((highlight_tone >= SRV_PROF_AUD_TONE1 && highlight_tone < SRV_PROF_AUD_TONE_END_OF_ENUM) ||
            (highlight_tone >= SRV_PROF_AUD_RING1 && highlight_tone < SRV_PROF_AUD_RING_END_OF_ENUM))
        {
            instance_data->selected_tone = srv_prof_transform_audio_id_for_read_nvram(highlight_tone);
        }
        else
        {
            instance_data->selected_tone = highlight_tone;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_set_filter
 * DESCRIPTION
 *  set filter.
 * PARAMETERS
 *  mmi_id ts_gid
 *  U16 tone_filter
 * RETURNS
 *  void
 *****************************************************************************/
void cui_tone_selector_set_filter (mmi_id ts_gid, U16 tone_filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_tonesel_mem_struct *instance_data = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUI_TONESEL_SET_FILTER, tone_filter);
    instance_data = (cui_tonesel_mem_struct *) mmi_frm_group_get_user_data(ts_gid);
    if (instance_data != NULL)
    {
        instance_data->tone_filter = tone_filter;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_run
 * DESCRIPTION
 *  run CUI.
 * PARAMETERS
 *  mmi_id ts_gid,  the group which need to be run.
 * RETURNS
 *  void
 *****************************************************************************/
void cui_tone_selector_run (mmi_id ts_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUI_TONESEL_RUN, ts_gid);
    
#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
	    mmi_ucm_app_entry_error_message();
        g_tonesel_cntx.cur_gid = ts_gid;
        cui_tone_selector_exit_req();
        return;
    }
#endif /* __MMI_BACKGROUND_CALL__ */

    mmi_frm_group_enter(ts_gid, (mmi_group_enter_flag)0);

    g_tonesel_cntx.volume = MDI_AUD_VOL_MUTE(MDI_AUD_VOL_2);
    g_tonesel_cntx.is_playing = MMI_FALSE;
    g_tonesel_cntx.cur_gid = ts_gid;

    cui_tone_selector_listscr_entry();
}

/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_get_selected_filepath
 * DESCRIPTION
 *  Query more information of current selected file/folder from a file selector CUI.
 *  Including file information and full filepath.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  info                    : [OUT] a pointer to file info. structure. Can not be NULL.
 *                                  It will be reset if there is any error to prevent mis-usage.
 *  path_buffer             : [OUT] buffer to store full filepath of selected file/folder
 *  path_size               : [IN]  size of path_buffer, in bytes, including null terminated.
 * RETURNS
 *  Refer to FS error, ok if == 0, error if < 0.
 *****************************************************************************/
S32 cui_tone_selector_get_selected_filepath(mmi_id cui_id, srv_fmgr_fileinfo_struct* info, 
                                            WCHAR* path_buffer, S32 path_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_tonesel_mem_struct *instance_data = NULL;
    S32 error_code = CUI_TONE_SELECTOR_ERROR_NO_EXT_FILE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    instance_data = (cui_tonesel_mem_struct *) mmi_frm_group_get_user_data(cui_id);
    if (instance_data != NULL)
    {
        if(CUI_TONE_SELECTOR_FILTER_IS_SET(instance_data->tone_filter, CUI_TONE_SELECTOR_FILTER_EXT_FILE))
        {
            if (g_tonesel_cntx.fmgr_id != GRP_ID_INVALID)
            {
                error_code = cui_file_selector_get_selected_filepath(g_tonesel_cntx.fmgr_id, info, path_buffer, path_size);
            #ifdef __GAIN_TABLE_SUPPORT__
                error_code = mmi_extmelody_play_and_check_if_supported(path_buffer);
            #endif
            }
            else
            {
                error_code = CUI_TONE_SELECTOR_ERROR_INVALID_GID;
            }
        }
    }
    return error_code;
}


/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_close
 * DESCRIPTION
 *  close the CUI, depends the input group id
 * PARAMETERS
 *  mmi_id ts_gid, the group which need to be closed.
 * RETURNS
 *  void
 *****************************************************************************/
void cui_tone_selector_close(mmi_id ts_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUI_TONESEL_CLOSE, ts_gid);
    mmi_frm_group_close(ts_gid);
}

/*****************************************************************************  
 * FUNCTION
 *  cui_tone_selector_close
 * DESCRIPTION
 *  close the CUI, depends the input group id
 * PARAMETERS
 *  mmi_id ts_gid, the group which need to be closed.
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret cui_tone_selector_notify_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_GPIO_EARPHONE_PLUG_IN || 
        evt->evt_id == EVT_ID_GPIO_EARPHONE_PLUG_OUT)
    {
        cui_tone_selector_preview_stop_tone();
    }
    return MMI_RET_OK;
}

/*****************************************************************************  
*   The following is static functions 
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_get_memory
 * DESCRIPTION
 *  get memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static cui_tonesel_mem_struct * cui_tone_selector_get_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(g_tonesel_mem_a[i].is_used == MMI_TRUE && i < max_instances)
    {
        i++;
    }
    if (i < max_instances)
    {
        g_tonesel_mem_a[i].is_used = MMI_TRUE;
        return &g_tonesel_mem_a[i];
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUI_TONESEL_EXCEPTION, CUI_TONESEL_GET_MEMORY_FAIL);
        return NULL;
    }

}

/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_free_memory
 * DESCRIPTION
 *  free memory
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_tone_selector_free_memory(cui_tonesel_mem_struct * p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->is_used = MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_event_struct* evt
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret cui_tone_selector_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_tonesel_mem_struct *instance_data = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE:
        {
            mmi_scenario_evt_struct * evt_s = (mmi_scenario_evt_struct *)evt;
            g_tonesel_cntx.cur_gid = evt_s->targ_group;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUI_TONESEL_GROUP_AVTIVE, g_tonesel_cntx.cur_gid);
            break;
        }
        case EVT_ID_GROUP_DEINIT:
        {
            mmi_scenario_evt_struct * evt_s = (mmi_scenario_evt_struct *)evt;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUI_TONESEL_DEINIT, evt_s->targ_group); 
            
            instance_data = (cui_tonesel_mem_struct *) mmi_frm_group_get_user_data(evt_s->targ_group);
            MMI_ASSERT(instance_data);
            cui_tone_selector_free_memory(instance_data);
            break;
        }
        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
        {
            cui_file_selector_result_event_struct * evt_fs = (cui_file_selector_result_event_struct *)evt;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUI_TONESEL_FMGR_RES, evt_fs->result); 
            if (evt_fs->result > 0)
            {
                /*user selected a file*/
                g_tonesel_cntx.fmgr_id = evt_fs->sender_id;
                cui_tone_selector_fmgr_selected(evt_fs->sender_id);
            }
            else
            {   /*user cancel or FS error*/
                mmi_group_node_struct node_info;
                if (mmi_frm_group_get_info (evt_fs->sender_id, &node_info) == MMI_RET_OK)
                {
                    instance_data = (cui_tonesel_mem_struct *) mmi_frm_group_get_user_data(node_info.parent);
                    MMI_ASSERT(instance_data);
                    g_tonesel_cntx.fmgr_id = GRP_ID_INVALID;
                }
                cui_file_selector_close(evt_fs->sender_id);
            }
            break;
        }
    #ifdef __GAIN_TABLE_SUPPORT__
        case EVT_ID_CUI_FILE_SELECTOR_PREVIEW_START:
        {
            cui_tone_selector_set_audio();
            break;
        }
        case EVT_ID_CUI_FILE_SELECTOR_PREVIEW_STOP:
        {
            cui_tone_selector_reset_audio();
            break;
        }
    #endif
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_listscr_entry
 * DESCRIPTION
 *  run CUI.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_tone_selector_listscr_entry (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  
    U16 selected_item = 0;
    U16 totalItems = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUI_TONESEL_ENTRY_MAIN_SCRN, g_tonesel_cntx.cur_gid);
#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
	    mmi_ucm_app_entry_error_message();
        cui_tone_selector_exit_req();
        return;
    }
#endif /* __MMI_BACKGROUND_CALL__ */

    if (mmi_frm_scrn_enter(
	    g_tonesel_cntx.cur_gid, 
	    SCR_CUI_TONE_SELECTOR_LIST, 
	    cui_tone_selector_listscr_exit, 
	    cui_tone_selector_listscr_entry, 
	    MMI_FRM_FULL_SCRN))
    {
        cui_tonesel_mem_struct *instance_data = NULL;
        
        mdi_audio_suspend_background_play();

        instance_data = (cui_tonesel_mem_struct *) mmi_frm_group_get_user_data(g_tonesel_cntx.cur_gid);
        MMI_ASSERT(instance_data);

        totalItems = cui_tone_selector_creat_tone_list(instance_data->selected_tone, instance_data->tone_filter, &selected_item);

        guiBuffer = mmi_frm_scrn_get_gui_buf(g_tonesel_cntx.cur_gid, SCR_CUI_TONE_SELECTOR_LIST);
        RegisterHighlightHandler(cui_tone_selector_listscr_highlight_hdlr);

        ShowCategory89Screen(
            instance_data->str_id,
            instance_data->img_id,
            STR_GLOBAL_SELECT,
            IMG_GLOBAL_OK,      /*There is no select image*/
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            totalItems,
            subMenuDataPtrs,
            hintDataPtrs,
            0,
            selected_item,
            guiBuffer);
	#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_tap_callback(cui_tone_selector_list_tap_callback);
    #endif /* __MMI_FTE_SUPPORT__ */

        SetKeyHandler(cui_tone_selector_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
        SetKeyHandler(cui_tone_selector_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetRightSoftkeyFunction(cui_tone_selector_exit_req, KEY_EVENT_UP);

    #ifdef __BT_SPK_VOL_CONTROL__
        mdi_audio_bt_register_volume_sync_callback(CUI_TONE_SELECTOR, MDI_AUD_VOL_LEVEL_NORMAL_MUTE, cui_tone_selector_handfree_volume_sync_callback);
    #endif
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUI_TONESEL_EXCEPTION, CUI_TONESEL_GRP_NOT_ACTIVE);
    }

}

#ifdef __BT_SPK_VOL_CONTROL__
/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_handfree_volume_sync_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL cui_tone_selector_handfree_volume_sync_callback(U8 volume, MMI_BOOL is_mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUI_TONESEL_HFP_VOL_SYNC, volume, is_mute);
    ASSERT(volume <= MDI_AUD_VOL_NUM);
    
    g_tonesel_cntx.volume = MDI_AUD_VOL_MUTE(volume);
    if (g_tonesel_cntx.is_playing)
    {
        mdi_audio_set_volume(VOL_TYPE_MEDIA, g_tonesel_cntx.volume);
    }
    return MMI_TRUE;
}
#endif/*__BT_SPK_VOL_CONTROL__*/


/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_listscr_exit
 * DESCRIPTION
 *  run CUI.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_tone_selector_listscr_exit (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_tone_selector_preview_stop_tone();
    mdi_audio_resume_background_play();
#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_clear_volume_sync_callback(CUI_TONE_SELECTOR);
#endif
}

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_list_tap_callback
 * DESCRIPTION
 *  call back function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_tone_selector_list_tap_callback(mmi_tap_type_enum tap_type,S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM) 
    {
        if (get_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY) == cui_tone_selector_tone_selected)
        {
            cui_tone_selector_tone_selected();
        }
        else if (get_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY) == cui_tone_selector_extmld_add_hdlr)
        {
            cui_tone_selector_extmld_add_hdlr();
        }
    }
}
#endif /*__MMI_FTE_SUPPORT__*/

#if defined(__DRM_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_check_DRM_forwardable
 * DESCRIPTION
 *  check does the file is DRM prohibted to forward
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 * S32
 *****************************************************************************/
static S32 cui_tone_selector_check_DRM_forwardable(UI_string_type filename)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    S32 result = 0 ;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    handle = DRM_open_file((PU16)filename, FS_READ_ONLY, DRM_PERMISSION_PLAY);

    if (handle >= FS_NO_ERROR)
    {
        BOOL is_permitted = DRM_validate_forward_rule(handle, DRM_PERMISSION_PLAY);
        if(is_permitted)
        {
           result = 1 ;
        }
        DRM_close_file(handle);
    }
    else
    {
        return handle;
    }

    return result ;

}
#endif /* defined(__DRM_SUPPORT__) */ 


/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_fmgr_selected
 * DESCRIPTION
 *  file selector CUI result handler.
 * PARAMETERS
 *  mmi_id fs_gid: file selector CUI group id.
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_tone_selector_fmgr_selected(mmi_id fs_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR filepath[SRV_FMGR_PATH_BUFFER_SIZE];
#ifdef __DRM_SUPPORT__
    S32 result = 0;
#endif
    srv_fmgr_fileinfo_struct fileinfo;
    U8 mdi_type = MDI_FORMAT_SMF;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_file_selector_get_selected_filepath(fs_gid, &fileinfo, (WCHAR*)&filepath, SRV_FMGR_PATH_BUFFER_SIZE);
    if(fileinfo.type == FMGR_TYPE_IMY || fileinfo.type == FMGR_TYPE_MIDI || fileinfo.type == FMGR_TYPE_MID)
    {
        if(fileinfo.type == FMGR_TYPE_IMY)
        {
            mdi_type = MDI_FORMAT_IMELODY;
        }
        
        if (fileinfo.size > mdi_audio_get_size_limit(mdi_type))
        {
            mmi_popup_display_simple((UI_string_type)GetString(STR_ID_PROF_FILE_TOO_LARGE), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
            return;
        }
    }

    if (((U16*)filepath)[0] != 0)
    {
    #if defined(__DRM_SUPPORT__)
        result = cui_tone_selector_check_DRM_forwardable((UI_string_type) filepath);

        if ( result < 1 )
        {
            mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_DRM_PROHIBITED), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
        }
        else
    #endif /* defined(__DRM_SUPPORT__)*/ 
        {
            /*post result to parent*/
            cui_tone_selector_post_res_to_parent(MMI_FALSE);
            cui_tone_selector_exit_req();
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_extmld_add_hdlr
 * DESCRIPTION
 *  run CUI.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_tone_selector_extmld_add_hdlr (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id fs_gid;
    FMGR_FILTER filter;

	cui_tonesel_mem_struct *instance_data = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_AUDIO(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);
#if defined(__MMI_PURE_AUDIO__)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_3GP);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_3G2);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_MP4);
#endif
#ifdef __DRM_V02__
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF); 
#endif
    fs_gid = cui_file_selector_create(g_tonesel_cntx.cur_gid, 
                                      (WCHAR*) L"root", 
                                      &filter, 
                                      CUI_FILE_SELECTOR_STYLE_FILE_ONLY, 
                                      CUI_FILE_SELECTOR_OPT_AUDIO_PREVIEW_ON | CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON);

	instance_data = (cui_tonesel_mem_struct *) mmi_frm_group_get_user_data(g_tonesel_cntx.cur_gid);
	cui_file_selector_set_title(fs_gid , 0, instance_data->img_id);

    if (fs_gid != GRP_ID_INVALID)
    {  
        cui_file_selector_run(fs_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_tone_selected
 * DESCRIPTION
 *  run CUI.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_tone_selector_tone_selected (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*cui_tonesel_mem_struct *instance_data = NULL;*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*instance_data = (cui_tonesel_mem_struct *) mmi_frm_group_get_user_data(g_tonesel_cntx.cur_gid);*/
    cui_tone_selector_post_res_to_parent(MMI_TRUE);
    cui_tone_selector_exit_req();
}

/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_post_res_to_parent
 * DESCRIPTION
 *  run CUI.
 * PARAMETERS
 *  mmi_id ts_gid
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_tone_selector_post_res_to_parent(MMI_BOOL is_default_sound)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_tone_selector_evt_struct evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt.selected_tone = 0;
    evt.evt_id = EVT_ID_CUI_TONE_SELECTOR_RESULT;
    evt.size = sizeof(cui_tone_selector_evt_struct);
    evt.is_default_sound = is_default_sound;
    if (is_default_sound == MMI_TRUE)
    {
        evt.selected_tone = g_tonesel_cntx.highlight_audioid;
    }
    evt.sender_id = g_tonesel_cntx.cur_gid;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUI_TONESEL_RESULT, evt.selected_tone, g_tonesel_cntx.cur_gid);
    mmi_frm_group_post_to_parent(g_tonesel_cntx.cur_gid, (mmi_group_event_struct*) &evt);
}


#if defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_check_theme_audio
 * DESCRIPTION
 *  IF audio folder get deleted or fomatted
 *  from File manager activate default audio as incoming tone
 * PARAMETERS
 *  tone_id         [IN]        
 *  Audio(?)        [IN]        ID
 * RETURNS
 * BOOL
 *  
 *****************************************************************************/
static MMI_BOOL cui_tone_selector_check_theme_audio(U16 tone_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR buf[(SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH];
    FS_HANDLE file;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetAudioNameWithPathInFileSystem(tone_id, (CHAR*) buf);
    file = FS_Open((const WCHAR*)buf, FS_READ_ONLY);
    if (file < 0)
    {
        FS_Close(file);
        return MMI_FALSE;
    }
    else
    {
        FS_Close(file);
        return MMI_TRUE;
    }
}
#endif /* defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__) */ 

/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_creat_tone_list
 * DESCRIPTION
 *  close the CUI, depends the input group id
 * PARAMETERS
 *  mmi_id ts_gid, the group which need to be closed.
 * RETURNS
 *  U16
 *****************************************************************************/
static U16 cui_tone_selector_creat_tone_list(U16 cur_audio_id, U16 tone_filter, U16 *selecteditem)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    U16 n_items = 0; 
    MMI_BOOL is_selected = MMI_FALSE;
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    DYNAUDIOINFO *DownloadThemeTones;
#endif 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(hintData, 0, sizeof(hintData));
    for (i = 0; i < MAX_SUB_MENUS; i++)
    {
        hintDataPtrs[i] = hintData[i];
    }

    if(CUI_TONE_SELECTOR_FILTER_IS_SET(tone_filter, CUI_TONE_SELECTOR_FILTER_SILENT))
    {
        /* Add silent tone.*/
        mmi_ucs2ncpy((CHAR*) subMenuData[n_items], (CHAR*) GetString(STR_GLOBAL_SILENT), MAX_SUBMENU_CHARACTERS);
        if (cur_audio_id == 0)
        {
            *selecteditem = n_items;
            is_selected = MMI_TRUE;
        }
        n_items++;
    }

    if(CUI_TONE_SELECTOR_FILTER_IS_SET(tone_filter, CUI_TONE_SELECTOR_FILTER_TONE))
    {
        /* Add deafult tone.*/
        for (i = CUI_TONESEL_TONE_ID_BEGIN; i < CUI_TONESEL_TONE_ID_END; i++)
        {
            mmi_ucs2ncpy((CHAR*) subMenuData[n_items], 
                         (CHAR*) GetString(srv_prof_get_string_id_from_srv_audio_id(i)), 
                         MAX_SUBMENU_CHARACTERS);
            n_items++;
        }
        if (cur_audio_id >= CUI_TONESEL_TONE_ID_BEGIN && cur_audio_id < CUI_TONESEL_TONE_ID_END)
        {
            *selecteditem = n_items - CUI_TONESEL_TONE_ID_END + cur_audio_id ;
            is_selected = MMI_TRUE;
        }
    }
    
    if(CUI_TONE_SELECTOR_FILTER_IS_SET(tone_filter, CUI_TONE_SELECTOR_FILTER_RING))
    {
        /* Add deafult ring.*/
        for (i = CUI_TONESEL_RING_ID_BEGIN; i < CUI_TONESEL_RING_ID_END; i++)
        {
            mmi_ucs2ncpy((CHAR *) subMenuData[n_items], 
                         (CHAR *) GetString(srv_prof_get_string_id_from_srv_audio_id(i)), 
                         MAX_SUBMENU_CHARACTERS);
            n_items++;
        }
        if (cur_audio_id >= CUI_TONESEL_RING_ID_BEGIN && cur_audio_id < CUI_TONESEL_RING_ID_END)
        {
            *selecteditem = n_items - CUI_TONESEL_RING_ID_END + cur_audio_id ;
            is_selected = MMI_TRUE;
        }
    }

    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    if(CUI_TONE_SELECTOR_FILTER_IS_SET(tone_filter, CUI_TONE_SELECTOR_FILTER_DLT_RING))
    {   /* Add download theme tone*/
        if (GetThemeV2TonesInfo(&DownloadThemeTones) != 0 && mmi_tm_get_current_theme_ringtone())
        {
            mmi_ucs2cpy((CHAR *) subMenuDataPtrs[n_items], (CHAR *) GetString(STR_ID_PROF_CURR_THEME));
            if(!is_selected)
            {
                if ((U16)DownloadThemeTones[0].AudioId == cur_audio_id)
                {
                    is_selected = MMI_TRUE;
                    *selecteditem = n_items;
                }
            }
            n_items++;
        }
    }
    #endif

    if(CUI_TONE_SELECTOR_FILTER_IS_SET(tone_filter, CUI_TONE_SELECTOR_FILTER_EXT_FILE))
    {
        mmi_ucs2cpy((CHAR *) subMenuDataPtrs[n_items], (CHAR *) GetString(STR_ID_PROF_SELECT_FROM_FILE));
        n_items++;
    }
    if(!is_selected)
    {
        *selecteditem = 0;
    }
    return n_items;

}


/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_listscr_highlight_hdlr
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  S32 item_index
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_tone_selector_listscr_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_tonesel_mem_struct *instance_data = NULL;
    U16 tone_filter;
    U16 n_items = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    instance_data = (cui_tonesel_mem_struct *) mmi_frm_group_get_user_data(g_tonesel_cntx.cur_gid);
    MMI_ASSERT(instance_data);
    
    tone_filter = instance_data->tone_filter;
    StopTimer(CUI_TONE_SELECTOR_PLAY_TIMER);
    if (g_tonesel_cntx.is_playing)
    {
        cui_tone_selector_preview_stop_tone();
    }

    if (CUI_TONE_SELECTOR_FILTER_IS_SET(tone_filter, CUI_TONE_SELECTOR_FILTER_SILENT))
    {
        if(index == 0)
        {   //hightlight silent item.
            g_tonesel_cntx.highlight_audioid = 0; 
            StopTimer(CUI_TONE_SELECTOR_PLAY_TIMER);
            SetLeftSoftkeyFunction(cui_tone_selector_tone_selected, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(cui_tone_selector_tone_selected, KEY_EVENT_UP);
            return;
        }
        else
        {
            n_items++;
        }
    }

    if (CUI_TONE_SELECTOR_FILTER_IS_SET(tone_filter, CUI_TONE_SELECTOR_FILTER_TONE))
    {
        if(index >= n_items && index < n_items + CUI_TONESEL_TONE_ID_NUM)
        {
            g_tonesel_cntx.highlight_audioid = CUI_TONESEL_TONE_ID_BEGIN + index - n_items;
            StartTimer(CUI_TONE_SELECTOR_PLAY_TIMER, 1000, cui_tone_selector_preview_play_tone);
            SetLeftSoftkeyFunction(cui_tone_selector_tone_selected, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(cui_tone_selector_tone_selected, KEY_EVENT_UP);
            return;
        }
        else
        {
            n_items = n_items + CUI_TONESEL_TONE_ID_NUM;
        }
    }

    if (CUI_TONE_SELECTOR_FILTER_IS_SET(tone_filter, CUI_TONE_SELECTOR_FILTER_RING))
    {
        if(index >= n_items && index < n_items + CUI_TONESEL_RING_ID_NUM)
        {
            g_tonesel_cntx.highlight_audioid = CUI_TONESEL_RING_ID_BEGIN + index - n_items;
            StartTimer(CUI_TONE_SELECTOR_PLAY_TIMER, 1000, cui_tone_selector_preview_play_tone);
            SetLeftSoftkeyFunction(cui_tone_selector_tone_selected, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(cui_tone_selector_tone_selected, KEY_EVENT_UP);
            return;
        }
        else
        {
            n_items = n_items + CUI_TONESEL_RING_ID_NUM;
        }
    }
    
#if defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
    if(CUI_TONE_SELECTOR_FILTER_IS_SET(tone_filter, CUI_TONE_SELECTOR_FILTER_DLT_RING))
    {
        if (index == n_items)
        {
            DYNAUDIOINFO *download_theme_tones;
            if (GetThemeV2TonesInfo(&download_theme_tones) != 0 && mmi_tm_get_current_theme_ringtone())
            {
                g_tonesel_cntx.highlight_audioid = (U16) download_theme_tones[0].AudioId;
                if (cui_tone_selector_check_theme_audio(g_tonesel_cntx.highlight_audioid))
                {
                    StartTimer(CUI_TONE_SELECTOR_PLAY_TIMER, 1000, cui_tone_selector_preview_play_tone);
                }
                SetLeftSoftkeyFunction(cui_tone_selector_tone_selected, KEY_EVENT_UP);
                SetCenterSoftkeyFunction(cui_tone_selector_tone_selected, KEY_EVENT_UP);
                return;
            }
            else
            {
            }
        }
        else
        {
            n_items++;
        }
    }
#endif /* defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__) */ 

    if (CUI_TONE_SELECTOR_FILTER_IS_SET(tone_filter, CUI_TONE_SELECTOR_FILTER_EXT_FILE))
    {
        if(index == n_items)
        {
            g_tonesel_cntx.highlight_audioid = 0;
            SetLeftSoftkeyFunction(cui_tone_selector_extmld_add_hdlr, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(cui_tone_selector_extmld_add_hdlr, KEY_EVENT_UP);
            return;
        }
        else
        {
            n_items = n_items++;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_exit_req
 * DESCRIPTION
 *  exit CUI by right softkey.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_tone_selector_exit_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_tone_selector_evt_struct evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt.evt_id = EVT_ID_CUI_TONE_SELECTOR_CLOSE_REQUEST;
    evt.size = sizeof(cui_tone_selector_evt_struct);
    evt.selected_tone = g_tonesel_cntx.highlight_audioid;
    evt.sender_id = g_tonesel_cntx.cur_gid;

    mmi_frm_group_post_to_parent(g_tonesel_cntx.cur_gid, (mmi_group_event_struct*) &evt);
}

/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_play_tone_callback
 * DESCRIPTION
 *  play default tone callback
 * PARAMETERS
 *  MDI result
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_tone_selector_play_tone_callback(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == MDI_AUDIO_TERMINATED)
    {
        g_tonesel_cntx.is_playing = MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_preview_play_tone
 * DESCRIPTION
 *  preview tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_tone_selector_preview_play_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL    need_play = MMI_FALSE;
    U8          audio_type;
    U32         audio_len;
    U8 *        audio_data;
    mdi_result  result;
    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    WCHAR    buf[SRV_FMGR_PATH_MAX_LEN + 1];
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUI_TONESEL_PREVIEW_PLAY_TONE);

    if (MMI_FALSE == mdi_audio_is_background_play_suspended())
    {
        mdi_audio_suspend_background_play();
    }

    StopTimer(CUI_TONE_SELECTOR_PLAY_TIMER);
    if (g_tonesel_cntx.highlight_audioid == 0)
    {
        return;
    }
    
#if defined(__MMI_BACKGROUND_CALL__)
    if (srv_ucm_is_background_call())
    {
       return;
    }
#endif

    if (srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) != SRV_PROF_RET_PROFILE_ACTIVATED)
    {
    #ifdef __MMI_SILENT_MEETING_PROFILE__
        if (srv_prof_is_profile_activated(SRV_PROF_MEETING_MODE) != SRV_PROF_RET_PROFILE_ACTIVATED)
    #endif
        {
            need_play = MMI_TRUE;
        }
    }

    if (need_play)
    {
    #ifdef __GAIN_TABLE_SUPPORT__
        cui_tone_selector_set_audio();
    #endif

    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
        if (GetAudioNameWithPathInFileSystem(g_tonesel_cntx.highlight_audioid, (CHAR *)buf) != NULL)
        {
            result = mdi_audio_play_file_portion_with_vol_path(
                        (void *)buf, 
                        0, 
                        0, 
                        DEVICE_AUDIO_PLAY_INFINITE,
                        NULL,
                        cui_tone_selector_play_tone_callback,
                        NULL,
                        g_tonesel_cntx.volume,
                        MDI_DEVICE_SPEAKER2);
            if (result == MDI_AUDIO_SUCCESS)
            {
                g_tonesel_cntx.is_playing = MMI_TRUE;
            }
            return;
        }
    #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

        audio_data = get_audio((U16) (g_tonesel_cntx.highlight_audioid), &audio_type, &audio_len);
        if (audio_data != NULL)
        {
            result = mdi_audio_play_string_with_vol_path(
                        (void*)audio_data,
                        audio_len,
                        audio_type,
                        DEVICE_AUDIO_PLAY_INFINITE,
                        cui_tone_selector_play_tone_callback,
                        NULL,
                        g_tonesel_cntx.volume,
                        MDI_DEVICE_SPEAKER2);
            if (result == MDI_AUDIO_SUCCESS)
            {
                g_tonesel_cntx.is_playing = MMI_TRUE;
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_preview_stop_tone
 * DESCRIPTION
 *  stop preview tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_tone_selector_preview_stop_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(CUI_TONE_SELECTOR_PLAY_TIMER);

    if (MMI_TRUE == mdi_audio_is_background_play_suspended())
    {
        mdi_audio_resume_background_play();
    }

    if (g_tonesel_cntx.is_playing)
    {
        mdi_audio_stop_string();
        mdi_audio_stop_file();
        g_tonesel_cntx.is_playing = MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_inc_volume
 * DESCRIPTION
 *  include volume
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_tone_selector_inc_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __GAIN_TABLE_SUPPORT__
            cui_tone_selector_set_audio();
    #endif

    if (g_tonesel_cntx.volume < MDI_AUD_VOL_MUTE(MDI_AUD_VOL_NUM))
    {
        g_tonesel_cntx.volume++;
        if (g_tonesel_cntx.is_playing)
        {
            mdi_audio_set_volume(VOL_TYPE_MEDIA, g_tonesel_cntx.volume);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_inc_volume
 * DESCRIPTION
 *  include volume
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_tone_selector_dec_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __GAIN_TABLE_SUPPORT__
        cui_tone_selector_set_audio();
    #endif

    if (g_tonesel_cntx.volume > MDI_AUD_VOL_MUTE(MDI_AUD_VOL_0))
    {
        g_tonesel_cntx.volume--;
        if (g_tonesel_cntx.is_playing)
        {
            mdi_audio_set_volume(VOL_TYPE_MEDIA, g_tonesel_cntx.volume);
        }
    }
}

#ifdef __GAIN_TABLE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_set_audio
 * DESCRIPTION
 *  preview tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_tone_selector_set_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    U16 g_curr_tone_setting = mmi_prof_get_current_set_item();
    switch(g_curr_tone_setting)
    {
        case MMI_PROF_TYPE_RING:
        case MMI_PROF_TYPE_VIDEO_CALL:
        {
            mdi_audio_set_audio_type(MDI_AUDIO_TYPE_RING);
            break;
        }
        case MMI_PROF_TYPE_POWER_ON:
        case MMI_PROF_TYPE_POWER_OFF:
        {
            mdi_audio_set_audio_type(MDI_AUDIO_TYPE_POWER_OFF);
            break;
        }
        case MMI_PROF_TYPE_MESSAGE:
        {
            mdi_audio_set_audio_type(MDI_AUDIO_TYPE_MESSAGE);
            break;
        }
        default:
            //mdi_audio_set_audio_type(MDI_AUDIO_TYPE_EFFECT);
            break;
    }
/*
#if defined(__BES_LOUDNESS_SUPPORT__)
    if ((g_curr_tone_setting == MMI_PROF_TYPE_RING ||
         g_curr_tone_setting == MMI_PROF_TYPE_CARD2_RING)
         &&
        (gprofileId == MMI_PROFILE_OUTDOOR ||
         gprofileId == MMI_PROFILE_INDOOR ||
         gprofileId == MMI_PROFILE_GENERAL)
        )
    {
        mdi_audio_loudness_turn_on();
    }
#endif
*/
}

/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_reset_audio
 * DESCRIPTION
 *  preview tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_tone_selector_reset_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
    #if defined(__BES_LOUDNESS_SUPPORT__)
    if ((g_curr_tone_setting == MMI_PROF_TYPE_RING ||
         g_curr_tone_setting == MMI_PROF_TYPE_CARD2_RING)
         &&
        (gprofileId == MMI_PROFILE_OUTDOOR ||
         gprofileId == MMI_PROFILE_INDOOR ||
         gprofileId == MMI_PROFILE_GENERAL)
        )
    {
        mdi_audio_loudness_turn_off();
    }
    #endif
    */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_extmelody_play_and_check_if_supported
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_extmelody_play_and_check_if_supported(CHAR *pathfileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    srv_prof_volume_level volume;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined (__DRM_SUPPORT__)
    mdi_audio_drm_disable_consume_count();
#endif /* __DRM_SUPPORT__ */

#ifdef __GAIN_TABLE_SUPPORT__
    mdi_audio_set_audio_type(MDI_AUDIO_TYPE_RING);
#endif

    volume = srv_prof_get_ring_vol();

    result = mdi_audio_play_file_with_vol_path(
                (UI_string_type)pathfileName,
                DEVICE_AUDIO_PLAY_INFINITE,
                NULL,
                cui_tone_selector_play_tone_callback,
                volume,
                MDI_DEVICE_SPEAKER2);

    return result;
}

#endif

#endif /*#if !defined(__MMI_BASIC_UI_STYLE__) && !defined(__OP01_FWPBW__)*/

