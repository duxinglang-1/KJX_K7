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
*  ToneSelectorCui_menucui.c
*
* Project:
* --------
*   CMCC TD WB FWT
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
*
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "MMI_features.h"

#if defined(__MMI_BASIC_UI_STYLE__) || defined(__OP01_FWPBW__)

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

//#include "ProfileGprots.h"
//#include "ProfilesGexdcl.h"
//#include "ProfilesDefs.h"

#include "ToneSelectorCuiGprot.h"
#include "ToneSelectorCui.h"
#include "Gpiosrvgprot.h"

static cui_tonesel_cntx_struct g_tonesel_cntx;

static mmi_ret cui_tone_selector_group_proc(mmi_event_struct* evt);
static void cui_tone_selector_preview_play_tone(void);
static void cui_tone_selector_preview_stop_tone(void);
static void cui_tone_selector_listscr_entry (void);
#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
static void cui_tone_selector_fmgr_selected(mmi_id fs_gid);
static void cui_tone_selector_extmld_add_hdlr (void);
#endif    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */
static void cui_tone_selector_post_res_to_parent(MMI_BOOL is_default_sound);
static void cui_tone_selector_exit_req(void);
static void cui_tone_selector_creat_tone_list(mmi_id cui_menu_id);


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

    ts_gid = mmi_frm_group_create(parent_gid, GRP_ID_AUTO_GEN, cui_tone_selector_group_proc, NULL);
    if (ts_gid != GRP_ID_INVALID)
    {
        mmi_frm_group_enter(ts_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG); 
        g_tonesel_cntx.cur_gid = ts_gid;    
    }
    return ts_gid;
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
    g_tonesel_cntx.tone_filter = tone_filter;
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
    g_tonesel_cntx.str_id = str_id;
    g_tonesel_cntx.img_id = img_id;
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
    g_tonesel_cntx.highlight_audioid = highlight_tone;
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
#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
	    mmi_ucm_app_entry_error_message();
        cui_tone_selector_exit_req();
        return;
    }
#endif /* __MMI_BACKGROUND_CALL__ */

    g_tonesel_cntx.volume = MDI_AUD_VOL_MUTE(MDI_AUD_VOL_3);
    g_tonesel_cntx.is_playing = MMI_FALSE;
    cui_tone_selector_listscr_entry();
}

#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_get_selected_filepath
 * DESCRIPTION
 *  Query more information of current selected file/folder from a file selector CUI.  Including file information and full filepath.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  info                    : [OUT] a pointer to file info. structure. Can not be NULL.  It will be reset if there is any error to prevent mis-usage.
 *  path_buffer             : [OUT] buffer to store full filepath of selected file/folder
 *  path_size               : [IN]  size of path_buffer, in bytes, including null terminated.
 * RETURNS
 *  Refer to FS error, ok if == 0, error if < 0.
 *****************************************************************************/
S32 cui_tone_selector_get_selected_filepath(mmi_id cui_id, srv_fmgr_fileinfo_struct* info, 
                                            WCHAR* path_buffer, S32 path_size)
{
    return cui_file_selector_get_selected_filepath(g_tonesel_cntx.fmgr_id, info, path_buffer, path_size);        
}
#endif    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */

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
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUI_TONESEL_CLOSE, ts_gid);
    StopTimer(CUI_TONE_SELECTOR_PLAY_TIMER);
    if (g_tonesel_cntx.is_playing)
    {
        cui_tone_selector_preview_stop_tone();
    }
    mmi_frm_group_close(ts_gid);
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
    cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {            
            if (menu_evt->parent_menu_id == MENU_ID_TONE_SELECTOR)
            {
                cui_tone_selector_creat_tone_list(menu_evt->sender_id);
            }     
            break;
        }
        case EVT_ID_CUI_MENU_LIST_EXIT:
        {
            cui_tone_selector_preview_stop_tone();
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
        #ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
            if (menu_evt->highlighted_menu_id == MENU_ID_PROF_OPEN_GALLERY)
            {
                cui_tone_selector_extmld_add_hdlr();
                break;
            }
        #endif    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */

            if (menu_evt->highlighted_menu_id == MENU_ID_PROF_TONE_SILENT)
            {
                g_tonesel_cntx.highlight_audioid = 0;
            }            
            else if (menu_evt->highlighted_menu_id >= MENU_ID_PROF_RING_1 && menu_evt->highlighted_menu_id <= MENU_ID_PROF_RING_END)
            {
                g_tonesel_cntx.highlight_audioid = AUD_ID_PROF_RING1+menu_evt->highlighted_menu_id - MENU_ID_PROF_RING_1;
            }
            else
            {
                g_tonesel_cntx.highlight_audioid = AUD_ID_PROF_TONE1+menu_evt->highlighted_menu_id - MENU_ID_PROF_TONE_1;
            }

            cui_tone_selector_post_res_to_parent(MMI_TRUE);
            cui_tone_selector_exit_req();
            break;
        }    

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {            
        	cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
            StopTimer(CUI_TONE_SELECTOR_PLAY_TIMER);
            if (g_tonesel_cntx.is_playing)
            {
                cui_tone_selector_preview_stop_tone();
            }
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
        #ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
			if (menu_evt->highlighted_menu_id == MENU_ID_PROF_TONE_SILENT || menu_evt->highlighted_menu_id == MENU_ID_PROF_OPEN_GALLERY)
            {
                g_tonesel_cntx.highlight_audioid = 0;
            }            
        #else    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */
            if (menu_evt->highlighted_menu_id == MENU_ID_PROF_TONE_SILENT)
            {
                g_tonesel_cntx.highlight_audioid = 0;
            }			 
        #endif    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */
            else if (menu_evt->highlighted_menu_id >= MENU_ID_PROF_RING_1 && menu_evt->highlighted_menu_id <= MENU_ID_PROF_RING_END)
            {
                g_tonesel_cntx.highlight_audioid = AUD_ID_PROF_RING1+menu_evt->highlighted_menu_id - MENU_ID_PROF_RING_1;
            }
            else
            {
                g_tonesel_cntx.highlight_audioid = AUD_ID_PROF_TONE1+menu_evt->highlighted_menu_id - MENU_ID_PROF_TONE_1;
            }

            StopTimer(CUI_TONE_SELECTOR_PLAY_TIMER);
            if (g_tonesel_cntx.is_playing)
            {
                cui_tone_selector_preview_stop_tone();
            }
            StartTimer(CUI_TONE_SELECTOR_PLAY_TIMER, 1000, cui_tone_selector_preview_play_tone);
            break;
        }

        #ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
        {
            cui_file_selector_result_event_struct * evt_fs = (cui_file_selector_result_event_struct *)evt;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUI_TONESEL_FMGR_RES, evt_fs->result); 
            if (evt_fs->result > 0)
            {
                g_tonesel_cntx.fmgr_id = evt_fs->sender_id;
                cui_tone_selector_fmgr_selected(evt_fs->sender_id);
            }
            else
            {   /*user cancel or FS error*/
                mmi_group_node_struct node_info;
                if (mmi_frm_group_get_info (evt_fs->sender_id, &node_info) == MMI_RET_OK)
                {
                    g_tonesel_cntx.fmgr_id = GRP_ID_INVALID;
                }
                cui_file_selector_close(evt_fs->sender_id);
            }
            break;
        }
        #endif    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */
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
    mmi_id cui_menu_id;
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
    cui_menu_id = cui_menu_create(g_tonesel_cntx.cur_gid, 
                                      CUI_MENU_SRC_TYPE_APPCREATE, 
                                      CUI_MENU_TYPE_APPSUB, 
                                      MENU_ID_TONE_SELECTOR, 
                                      MMI_FALSE, 
                                      NULL);
    
    cui_menu_run(cui_menu_id);  
}

/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_creat_tone_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_id ts_gid, the group which need to be closed.
 * RETURNS
 *  U16
 *****************************************************************************/
static void cui_tone_selector_creat_tone_list(mmi_id cui_menu_id)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j = 2;
    U16 n_items = 0;
    mmi_menu_id temp_menu_id = 0;
    mmi_menu_id menu_list[30] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(CUI_TONE_SELECTOR_FILTER_IS_SET(g_tonesel_cntx.tone_filter, CUI_TONE_SELECTOR_FILTER_SILENT))
    {
        /* Add silent tone.*/
        j = 0;
        menu_list[n_items] = MENU_ID_PROF_TONE_SILENT;
        cui_menu_set_currlist(cui_menu_id, 1, &menu_list[n_items]);
        cui_menu_set_item_string(cui_menu_id, MENU_ID_PROF_TONE_SILENT, (WCHAR*)GetString(STR_GLOBAL_SILENT));
        n_items++;
    }
        
    if(CUI_TONE_SELECTOR_FILTER_IS_SET(g_tonesel_cntx.tone_filter, CUI_TONE_SELECTOR_FILTER_TONE))
    {
        /* Add deafult tone.*/
        for (i = CUI_TONESEL_TONE_ID_BEGIN; i < CUI_TONESEL_TONE_ID_END; i++)
        {
            menu_list[n_items] = MENU_ID_PROF_TONE_1+i-CUI_TONESEL_TONE_ID_BEGIN;
            if (j == 2 && i == CUI_TONESEL_TONE_ID_BEGIN)
            {
                cui_menu_set_currlist(cui_menu_id, 1, &menu_list[n_items]);
               
            }
            else
            {
                cui_menu_insert_currlist(cui_menu_id, 1, &menu_list[n_items], menu_list[n_items-1]);
            }
            cui_menu_set_item_string(cui_menu_id, menu_list[n_items], (WCHAR*)GetString(STR_ID_SRV_PROF_TONE_1+i-CUI_TONESEL_TONE_ID_BEGIN));           
            n_items++;
        }
         j = 1;
    }
    
    if(CUI_TONE_SELECTOR_FILTER_IS_SET(g_tonesel_cntx.tone_filter, CUI_TONE_SELECTOR_FILTER_RING))
    {
        /* Add deafult ring.*/
        for (i = CUI_TONESEL_RING_ID_BEGIN; i < CUI_TONESEL_RING_ID_END; i++)
        {
            menu_list[n_items] = MENU_ID_PROF_RING_1+i-CUI_TONESEL_RING_ID_BEGIN;
            if (i == CUI_TONESEL_RING_ID_BEGIN)
            {
                cui_menu_set_currlist(cui_menu_id, 1, &menu_list[n_items]);
            }
            else
            {
                cui_menu_insert_currlist(cui_menu_id, 1, &menu_list[n_items], menu_list[n_items-1]);
            }
            cui_menu_set_item_string(cui_menu_id, menu_list[n_items], (WCHAR*)GetString(STR_ID_SRV_PROF_RING_1+i-CUI_TONESEL_RING_ID_BEGIN));           
            n_items++;
        }
    }

#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
    if(CUI_TONE_SELECTOR_FILTER_IS_SET(g_tonesel_cntx.tone_filter, CUI_TONE_SELECTOR_FILTER_EXT_FILE))
    {
        menu_list[n_items] = MENU_ID_PROF_OPEN_GALLERY;
        cui_menu_insert_currlist(cui_menu_id, 1, &menu_list[n_items], menu_list[n_items-1]);
        cui_menu_set_item_string(cui_menu_id, menu_list[n_items], (WCHAR*)GetString(STR_ID_PROF_SELECT_FROM_FILE));
        n_items++;
    }
#endif    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */
    
    cui_menu_set_currlist_flags(cui_menu_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
    if (g_tonesel_cntx.highlight_audioid == 0)
    {
        if (j == 1 )
            temp_menu_id = MENU_ID_PROF_TONE_SILENT;
    #ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
        else
            temp_menu_id = MENU_ID_PROF_OPEN_GALLERY;
    #endif    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */
    }
    else
    {   
        if (j == 1)
            temp_menu_id = g_tonesel_cntx.highlight_audioid - CUI_TONESEL_TONE_ID_BEGIN + MENU_ID_PROF_TONE_1;
        else
            temp_menu_id = g_tonesel_cntx.highlight_audioid - CUI_TONESEL_RING_ID_BEGIN + MENU_ID_PROF_RING_1;
    }

    cui_menu_set_currlist_highlighted_id(cui_menu_id, temp_menu_id);
#ifndef __OP01_FWPBW__
    cui_menu_set_currlist_title(cui_menu_id, (WCHAR*)GetString(g_tonesel_cntx.str_id),(UI_image_type)get_image(g_tonesel_cntx.img_id));  
#endif
}

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
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = DRM_open_file((PU16)filename, FS_READ_ONLY, DRM_PERMISSION_PLAY);
    if (handle >= FS_NO_ERROR && (DRM_validate_forward_rule(handle, DRM_PERMISSION_PLAY)))
    {
        DRM_close_file(handle);
        return 1;
    }
    return 0;
}
#endif /* defined(__DRM_SUPPORT__) */

#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
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
        if ( (cui_tone_selector_check_DRM_forwardable((UI_string_type) filepath)) == 0 )
        {
            mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_DRM_PROHIBITED), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
        }
        else
    #endif /* defined(__DRM_SUPPORT__)*/ 
        {
            cui_tone_selector_post_res_to_parent(MMI_FALSE);
            cui_tone_selector_exit_req();
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_extmld_add_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
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

    //cui_tonesel_mem_struct *instance_data = NULL;
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

    //instance_data = (cui_tonesel_mem_struct *) mmi_frm_group_get_user_data(g_tonesel_cntx.cur_gid);
    //cui_file_selector_set_title(fs_gid , 0, instance_data->img_id);

    if (fs_gid != GRP_ID_INVALID)
    {  
        cui_file_selector_run(fs_gid);
    }
}
#endif    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  cui_tone_selector_post_res_to_parent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MMI_BOOL is_default_sound
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
    U8          audio_type;
    U32         audio_len;  
    U8 *        audio_data;
    mdi_result  result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUI_TONESEL_PREVIEW_PLAY_TONE);

    #if defined(__MMI_BACKGROUND_CALL__)
    if (srv_ucm_is_background_call())
    {
       return;
    }
#endif
    mdi_audio_suspend_background_play();

    StopTimer(CUI_TONE_SELECTOR_PLAY_TIMER);
    if (g_tonesel_cntx.highlight_audioid == 0)
    {
        return;
    }

    if (srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) != SRV_PROF_RET_PROFILE_ACTIVATED)
    {
    #ifdef __MMI_SILENT_MEETING_PROFILE__
        if (srv_prof_is_profile_activated(SRV_PROF_MEETING_MODE) != SRV_PROF_RET_PROFILE_ACTIVATED)
    #endif
        {
            audio_data = get_audio((U16) (g_tonesel_cntx.highlight_audioid), &audio_type, &audio_len);
            if (audio_data == NULL)
                return;
            
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
    StopTimer(CUI_TONE_SELECTOR_PLAY_TIMER);
    mdi_audio_resume_background_play();
    if (g_tonesel_cntx.is_playing)
    {
        mdi_audio_stop_string();
        mdi_audio_stop_file();
        g_tonesel_cntx.is_playing = MMI_FALSE;
    }
}

#endif /*#if defined(__MMI_BASIC_UI_STYLE__) || defined(__OP01_FWPBW__)*/
