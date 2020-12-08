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
 *   ImageViewCui.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Image Viewer Common UI header file.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_IMAGE_VIEWER__)
/*******************************************************************************
* Include Header File
*******************************************************************************/
#include "GlobalConstants.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "string.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "AlertScreen.h"
#include "mmi_rp_app_filemanager_def.h"
#include "GlobalMenuItems.h"
#include "CommonScreensResDef.h"
#include "DebugInitDef_Int.h"
#include "Unicodexdcl.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "mmi_rp_file_type_def.h"
#include "FileMgrType.h"
#include "wgui_categories_popup.h"
#include "wgui_categories_util.h"
#include "ImageViewerEXAppGprot.h"
#include "ImageViewerAdvGprot.h"
#include "FileMgrSrvGProt.h"

#include "CommonScreens.h"      /* popup */

#include "ImageViewCui.h"
#include "ImageViewCuiGprot.h"
#include "ImageViewerGprot.h"
//#include "ImageViewerResDef.h"
#include "mmi_rp_app_imageviewer_def.h"
#include "menucuigprot.h"
#include "inlinecuigprot.h"
#ifdef __MMI_RMGR__
#include "RightsMgrGprot.h"
#endif

/* FMGR browse cui */
#include "FileMgrCUIGProt.h"
#include "Filemgrsrvgprot.h"
/*******************************************************************************
* Structure Define
*******************************************************************************/
void(*entry_fun)(void) = NULL;
void(*filelist_config_fun)(SRV_FMGR_FILELIST_HANDLE filelist, U32 start_index, U32 total_count) = NULL;
cui_imgview_context_struct g_imgview_cui_cntx;
cui_imgview_context_struct *g_imgview_cui_ptr = NULL;
CHAR g_imgview_cui_filepath[2][SRV_FMGR_PATH_BUFFER_SIZE];

cui_mediaview_context_struct g_mediaview_cui_cntx;
cui_mediaview_context_struct *g_mediaview_cui_ptr = NULL;
CHAR g_mediaview_cui_folderpath[SRV_FMGR_PATH_BUFFER_SIZE];

/*******************************************************************************
* Function Realization 
*******************************************************************************/
#define  IMGVIEW_COMMON
/*****************************************************************************
 * FUNCTION
 *  cui_view_close_existed_group
 * DESCRIPTION
 *  This function will close all both mediaview and imgview existed cui group.
 *  Because view image view and media view will use the same code to view image,
 *  and at present, only support single instance view, so only support one cui running.
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL.
 *****************************************************************************/
MMI_BOOL cui_view_close_existed_group(mmi_id parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_event_struct evt;
    mmi_group_node_struct group_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* single instance will use global context */
    if (g_imgview_cui_ptr != NULL &&
       (g_imgview_cui_ptr->imgview_cui_gid != GRP_ID_INVALID ||
        g_imgview_cui_ptr->imgview_cui_gid != 0))
    {
        mmi_frm_group_get_info(g_imgview_cui_ptr->imgview_cui_gid, &group_info);
        if(group_info.state == MMI_SCENARIO_STATE_CREATE)
        {
            mmi_frm_group_close(g_imgview_cui_ptr->imgview_cui_gid);
        }
        else
        {
            evt.evt_id = EVT_ID_IMGVIEW_CLOSE_GID;
            evt.sender_id = g_imgview_cui_ptr->imgview_cui_gid;
            evt.size = sizeof(mmi_group_event_struct);
            mmi_frm_group_send_to_parent(g_imgview_cui_ptr->imgview_cui_gid, &evt);
        }
    }

    if (g_mediaview_cui_ptr != NULL &&
       (g_mediaview_cui_ptr->mediaview_cui_gid != GRP_ID_INVALID ||
        g_mediaview_cui_ptr->mediaview_cui_gid != 0))
    {
        if (parent_gid != g_mediaview_cui_ptr->mediaview_cui_gid)
        {
            mmi_frm_group_get_info(g_mediaview_cui_ptr->mediaview_cui_gid, &group_info);
            if(group_info.state == MMI_SCENARIO_STATE_CREATE)
            {
                mmi_frm_group_close(g_mediaview_cui_ptr->mediaview_cui_gid);
            }
            else
            {
                evt.evt_id = EVT_ID_MEDIAVIEW_CLOSE_GID;
                evt.sender_id = g_mediaview_cui_ptr->mediaview_cui_gid;
                evt.size = sizeof(mmi_group_event_struct);
                mmi_frm_group_send_to_parent(g_mediaview_cui_ptr->mediaview_cui_gid, &evt);
            }
        }
    }
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_app_reset
 * DESCRIPTION
 *  Close function for image view cui.
 * PARAMETERS
 *  Void
 * RETURNS
 *  None.
 *****************************************************************************/
void cui_imgview_app_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, CUI_IMGVIEW_RESET_APP);
#ifdef __MMI_IMAGE_VIEWER_EX__
    mmi_ivex_app_reset();
#elif defined  __MMI_IMAGE_VIEWER_ADV__
    mmi_imgadv_app_reset();
#else
    mmi_imgview_app_reset();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_construct_user_data
 * DESCRIPTION
 *  This function get memory of context varialbe needed and construct user date structure.
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL.
 *****************************************************************************/
MMI_BOOL cui_imgview_construct_user_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* single instance will use global context */
    g_imgview_cui_ptr = &g_imgview_cui_cntx;
    memset(g_imgview_cui_ptr, 0, sizeof(*g_imgview_cui_ptr));
    g_imgview_cui_ptr->view_mode.buff_ptr = &g_imgview_cui_filepath[0][0];
    g_imgview_cui_ptr->title_confing.title_string = &g_imgview_cui_filepath[1][0];
    if (g_imgview_cui_ptr->imgview_cui_gid == 0)
    {
        g_imgview_cui_ptr->imgview_cui_gid = GRP_ID_INVALID;
    }
    return MMI_TRUE;
    /* ToDo, multi instance will malloc memory for cui context and imageviwer context */
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_disconstruct_user_data
 * DESCRIPTION
 *  This function reset user date structure.
 * PARAMETERS
 * Void.
 * RETURNS
 *  Void.
 *****************************************************************************/
void cui_imgview_disconstruct_user_data(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_evt_struct *evt_s = (mmi_scenario_evt_struct *)evt;
    cui_imgview_context_struct *instance_data = NULL;
    mmi_id imgview_cui_gid = evt_s->targ_group;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, CUI_IMGVIEW_DISCONS, imgview_cui_gid);
    instance_data = (cui_imgview_context_struct*)mmi_frm_group_get_user_data(imgview_cui_gid);
    if (instance_data != NULL)
    {
        instance_data->imgview_cui_gid = GRP_ID_INVALID;
        /* ToDo, Free g_imgview_cui_ptr->view_mode.buff_ptr and g_imgview_cui_ptr memory for multi instance */
        g_imgview_cui_ptr = NULL;
        cui_imgview_app_reset();
    }
    else
    {
        //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, CUI_IMGVIEW_DISCONS, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_init_user_data
 * DESCRIPTION
 *  This function initinalize user data.
 * PARAMETERS
 *  
 * RETURNS
 *  None.
 *****************************************************************************/
void cui_imgview_init_user_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* buffer_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)(&(g_imgview_cui_ptr->cap_enable[0])), 0, sizeof(cui_imgview_cap_enum) * CUI_IMGVIEW_CAP_ALL);
    memset((void*)(&(g_imgview_cui_ptr->lsk_setting)), 0, sizeof(cui_imgview_lsk_custom_struct));
    buffer_ptr = g_imgview_cui_ptr->view_mode.buff_ptr;
    memset((void*)(&(g_imgview_cui_ptr->view_mode)), 0, sizeof(cui_imgview_mode_struct));
    g_imgview_cui_ptr->view_mode.buff_ptr = buffer_ptr;
    if (g_imgview_cui_ptr->view_mode.buff_ptr != NULL)
    {
        memset((void*)(g_imgview_cui_ptr->view_mode.buff_ptr), 0, SRV_FMGR_PATH_BUFFER_SIZE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_close_cui
 * DESCRIPTION
 *  Close view cui group when can not enter successfuly
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_imgview_close_cui(mmi_id image_viewer_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_event_struct evt;
    mmi_group_node_struct group_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGVIEW_IVEX_CUI_CLOSE_BLOCK, image_viewer_id;
    mmi_frm_group_get_info(image_viewer_id, &group_info);

    if(group_info.state == MMI_SCENARIO_STATE_CREATE)
    {
        mmi_frm_group_close(image_viewer_id);
    }
    else
    {
        evt.evt_id = EVT_ID_IMGVIEW_CLOSE_GID;
        evt.sender_id = image_viewer_id;
        evt.size = sizeof(mmi_group_event_struct);
        mmi_frm_group_send_to_parent(image_viewer_id, &evt);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_alert_proc
 * DESCRIPTION
 *  Image view cui process function.
 * PARAMETERS
 *  evt         :  [IN]  Events pointer.
 * RETURNS
 *  mmi_ret.
 *****************************************************************************/
mmi_ret cui_imgview_alert_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((mmi_alert_result_evt_struct*)evt)->user_tag == (void*)MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP)
    {
        cui_imgview_close_cui(g_imgview_cui_ptr->imgview_cui_gid);
    }
#ifdef __MMI_IMAGE_VIEWER_EX__
    if (((mmi_alert_result_evt_struct*)evt)->user_tag == (void*)MMI_IMGVIEW_POPUP_RESULT_PROCESS_CONFIRM)
    {
        mmi_alert_result_evt_struct *alert_evt = (mmi_alert_result_evt_struct*)evt;
        if (alert_evt->result == MMI_ALERT_CNFM_YES)
        {
            mmi_ivex_view_option_settings_save();
        }
        if (alert_evt->result == MMI_ALERT_CNFM_NO)
        {
            mmi_ivex_close_settings_inline_cui();
        }
    }
#endif
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_inline_cui_proc
 * DESCRIPTION
 *  Image view cui process function.
 * PARAMETERS
 *  evt         :  [IN]  Events pointer.
 * RETURNS
 *  mmi_ret.
 *****************************************************************************/
mmi_ret cui_imgview_inline_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, CUI_IMGVIEW_PROC, evt->evt_id);
#ifdef __MMI_IMAGE_VIEWER_EX__
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_NOTIFY:
        {
            cui_event_inline_notify_struct *evt_inline_notify = (cui_event_inline_notify_struct *)evt;
            if (evt_inline_notify->event_type == CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED)
            {
                if(evt_inline_notify->item_id == MMI_IVEX_SETTINGS_SPEED)
                {
                    mmi_ivex_settings_speed_change_value(evt_inline_notify->param);
                }
            }
            break;
        }
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            mmi_ivex_view_option_settings_done();
            break;
        }
        case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_abort_struct *abort = (cui_event_inline_abort_struct*)evt;
            cui_inline_close(abort->sender_id);
            break;
        }
    }
#endif
    return MMI_RET_OK;
}

#ifdef __FS_CARD_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_entry_set_storage_screen
 * DESCRIPTION
 *  enter set storage screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_imgview_entry_set_storage_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id fmgr_storage_selector_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((fmgr_storage_selector_gid = cui_storage_selector_create(g_imgview_cui_ptr->imgview_cui_gid, g_imgview_cui_ptr->storage, 0)) != GRP_ID_INVALID)
    {
        cui_storage_selector_set_title(fmgr_storage_selector_gid, NULL, GetRootTitleIcon(MENU_ID_IMGVIEW_APP));
        cui_storage_selector_set_ui_style(fmgr_storage_selector_gid, CUI_FMGR_UI_STYLE_BANNER_LIST);//NEED TEST
        cui_storage_selector_run(fmgr_storage_selector_gid);
    }
    else
    {
        /*TODO: add trace, create error*/
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_select_drive_callback
 * DESCRIPTION
 *  entry storage screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_imgview_select_drive_callback( CHAR drv_letter )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 create_result;
    MMI_ID_TYPE error_str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(drv_letter <= 0 || drv_letter == g_imgview_cui_ptr->storage){
        return;
    }

    create_result = mmi_imgview_set_storage((U16) drv_letter);
    if(create_result < FS_NO_ERROR){
        
        error_str_id = srv_fmgr_fs_error_get_string(create_result);
        mmi_imgview_display_popup_sg(g_imgview_cui_ptr->imgview_cui_gid, (UI_string_type)GetString(error_str_id), 
            (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(create_result), 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);

        mmi_imgview_set_storage(g_imgview_cui_ptr->storage);
    }else{  //notify user
        
        /*----------------------------------------------------------------*/
        /* Local Variables                                                */
        /*----------------------------------------------------------------*/
        mmi_group_event_struct evt;

        evt.evt_id = EVT_ID_IMGVIEW_STORAGE_CHANGE;
        evt.sender_id = g_imgview_cui_ptr->imgview_cui_gid;
        evt.size = sizeof(mmi_group_event_struct);
        mmi_frm_group_post_to_parent(g_imgview_cui_ptr->imgview_cui_gid, &evt);
    }

}
#endif /*__FS_CARD_SUPPORT__*/
/*****************************************************************************
 * FUNCTION
 *  cui_imgview_menu_cui_proc
 * DESCRIPTION
 *  Image view cui process function.
 * PARAMETERS
 *  evt         :  [IN]  Events pointer.
 * RETURNS
 *  mmi_ret.
 *****************************************************************************/
mmi_ret cui_imgview_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, CUI_IMGVIEW_PROC, evt->evt_id);
    switch (evt->evt_id)
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
        #ifdef __MMI_IMAGE_VIEWER_EX__
            cui_menu_event_struct* menu_event = (cui_menu_event_struct*)evt;
            cui_menu_enable_center_softkey(
                menu_event->sender_id,
                0,
                IMG_GLOBAL_COMMON_CSK);
            switch (menu_event->parent_menu_id)
            {
                case MENU_ID_IMGVIEW_VIEW_OPTION:
                {
                    cui_menu_set_non_leaf_item(
                                    menu_event->sender_id,
                                    MENU_ID_IMGVIEW_VIEW_OPTION_SEND,
                                    MMI_TRUE);
                    cui_menu_set_non_leaf_item(
                                    menu_event->sender_id,
                                    MENU_ID_IMGVIEW_VIEW_OPTION_USE,
                                    MMI_TRUE);
#ifdef __FS_CARD_SUPPORT__
					if(g_imgview_cui_ptr->storage_select_enable == MMI_TRUE){
						mmi_menu_id id_list[1];
						id_list[0] = MENU_ID_IMGVIEW_STORAGE;
						cui_menu_insert_currlist(menu_event->sender_id, 1, id_list, MENU_ID_IMGVIEW_VIEW_OPTION_INFO);
						cui_menu_set_item_string_by_id(menu_event->sender_id, MENU_ID_IMGVIEW_STORAGE, STR_GLOBAL_STORAGE);
					} 

#endif

                    mmi_ivex_view_preentry_option_screen();
                }
                break;
                case MENU_ID_IMGVIEW_VIEW_OPTION_SEND:
                {
                    mmi_ivex_option_send_init_list();
                }
                break;
                case MENU_ID_IMGVIEW_VIEW_OPTION_USE:
                {
                    mmi_ivex_option_use_init_list();
                }
                break;
            }
        #endif /* __MMI_IMAGE_VIEWER_EX__ */
        }
        break;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        {
            cui_menu_event_struct* menu_event = (cui_menu_event_struct*)evt;
            switch (menu_event->highlighted_menu_id)
            {
        #ifdef __MMI_IMAGE_VIEWER_EX__
        #ifdef __MMI_RMGR__
            case MENU_ID_FMGR_GEN_OPTION_MORE_RITS:
                mmi_ivex_option_more_licence_execute_forward(menu_event->highlighted_menu_id);
                break;
        #endif
            case MENU_ID_IMGVIEW_VIEW_OPTION_HELP:
                mmi_ivex_view_option_entry_help_screen();
                break;
            case MENU_ID_IMGVIEW_VIEW_OPTION_SETTINGS:
                mmi_ivex_settings_prepare_inline_data();
                break;
            case MENU_ID_IMGVIEW_VIEW_OPTION_INFO:
                mmi_ivex_view_option_entry_info_screen();
                break;
        #if defined(__MMI_PHOTOEDITOR__)
            case MENU_ID_IMGVIEW_VIEW_OPTION_EDITOR:
                mmi_ivex_view_option_entry_photoeditor();
                break;
        #endif
            case MENU_ID_IMGVIEW_VIEW_OPTION_SEND:
            case MENU_ID_IMGVIEW_VIEW_OPTION_USE:
                break;
            case MENU_ID_IMGVIEW_VIEW_OPTION_PLAY:
                mmi_ivex_view_option_entry_prepare_play();
                break;

#ifdef __FS_CARD_SUPPORT__
            case MENU_ID_IMGVIEW_STORAGE:
                cui_imgview_entry_set_storage_screen();
                break;
#endif

        #endif /* __MMI_IMAGE_VIEWER_EX__ */
            default:
                {
                    switch (menu_event->parent_menu_id)
                    {
                #ifdef __MMI_IMAGE_VIEWER_EX__
                    case MENU_ID_IMGVIEW_VIEW_OPTION_USE:
                        mmi_ivex_option_use_execute_forward(menu_event->highlighted_menu_id);
                        break;
                    case MENU_ID_IMGVIEW_VIEW_OPTION_SEND:
                        mmi_ivex_option_send_execute_forward(menu_event->highlighted_menu_id);
                        break;
                #endif /* __MMI_IMAGE_VIEWER_EX__ */
                #if defined(__MMI_BPP_SUPPORT__) || defined(__MMI_PICT_BRIDGE_SUPPORT__)
                    case MENU_ID_FMGR_IMG_OPTION_PRINT:
                        {
                        #ifdef __MMI_IMAGE_VIEWER_EX__
                            mmi_ivex_option_print_execute_forward(menu_event->highlighted_menu_id);
                        #elif defined (__MMI_IMAGE_VIEWER_ADV__)
                            mmi_imgadv_option_print_execute_forward(menu_event->highlighted_menu_id);
                        #else
                            mmi_imgview_option_print_execute_forward(menu_event->highlighted_menu_id);
                        #endif /* __MMI_IMAGE_VIEWER_EX__ */
                        }
                        break;
                #endif /* defined(__MMI_BPP_SUPPORT__) || defined(__MMI_PICT_BRIDGE_SUPPORT__) */
                    }
                }
                break;
            }
        }
        break;

    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
        #ifdef __MMI_IMAGE_VIEWER_EX__
            mmi_ivex_close_option_menu_cui();
        #else
            cui_menu_event_struct* menu_event = (cui_menu_event_struct*)evt;
            cui_menu_close(menu_event->sender_id);
        #endif
        }
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_group_proc
 * DESCRIPTION
 *  Image view cui process function.
 * PARAMETERS
 *  evt         :  [IN]  Events pointer.
 * RETURNS
 *  mmi_ret.
 *****************************************************************************/
mmi_ret cui_imgview_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, CUI_IMGVIEW_PROC, evt->evt_id);
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_ENTER:
        /* enter group ToDo1 */
            break;
        case EVT_ID_GROUP_ACTIVE:
        /* enter group ToDo2 */
            break;
        case EVT_ID_GROUP_FOCUSED:
        /* enter group ToDo3 */
            break;
        case EVT_ID_GROUP_GOBACK:
        /* gobackhistory ToDo1 */
            break;
        case EVT_ID_GROUP_INACTIVE:
        /* gobackhistory ToDo1 */
            break;
        case EVT_ID_GROUP_EXIT:
        /* gobackhistory ToDo1 */
            break;
        case EVT_ID_GROUP_DEINIT:
        /* gobackhistory ToDo1 */
            cui_imgview_disconstruct_user_data(evt);
            break;
        case EVT_ID_ALERT_QUIT:
            cui_imgview_alert_proc(evt);
            break;
        case EVT_ID_CUI_INLINE_NOTIFY:
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        case EVT_ID_CUI_INLINE_ABORT:
            cui_imgview_inline_cui_proc(evt);
            break;

#ifdef __FS_CARD_SUPPORT__
            
        case EVT_ID_CUI_STORAGE_SELECTOR_RESULT:
            {
                cui_imgview_select_drive_callback(((cui_storage_selector_result_event_struct*)evt)->result);
                cui_storage_selector_close(((cui_storage_selector_result_event_struct*)evt)->sender_id);
            }
            break;
#endif /*__FS_CARD_SUPPORT__*/

        default:
            if(cui_menu_is_menu_event(evt->evt_id))
            {
                cui_imgview_menu_cui_proc(evt);
            }
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_create
 * DESCRIPTION
 *  Creat image view cui.
 * PARAMETERS
 *  parent_gid  :  [IN]  parent id.
 * RETURNS
 *  mmi_id.
 *****************************************************************************/
mmi_id cui_imgview_create(mmi_id parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_success = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, CUI_IMGVIEW_CREATE, parent_gid,g_imgview_cui_ptr->imgview_cui_gid);
    cui_view_close_existed_group(parent_gid);

    is_success = cui_imgview_construct_user_data();
    if (is_success == MMI_FALSE)
    {
        return GRP_ID_INVALID;
    }
    
    cui_imgview_init_user_data();
    
    g_imgview_cui_ptr->imgview_cui_gid = mmi_frm_group_create (parent_gid,  GRP_ID_AUTO_GEN, cui_imgview_group_proc, (void*)g_imgview_cui_ptr);
    cui_imgview_set_ui_direction(g_imgview_cui_ptr->imgview_cui_gid, CUI_IMGVIEW_UI_DIRECTION_VERTICAL);
    return g_imgview_cui_ptr->imgview_cui_gid;
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, CUI_IMGVIEW_CREATE, parent_gid,g_imgview_cui_ptr->imgview_cui_gid);
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_close
 * DESCRIPTION
 *  Close function for image view cui.
 * PARAMETERS
 *  image_viewer_id   :  [IN]  Image view group id.
 * RETURNS
 *  None.
 *****************************************************************************/
void cui_imgview_close(mmi_id image_viewer_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, CUI_IMGVIEW_CLOSE, image_viewer_id);
    static void cui_imgview_fl_restore_file_list();

    cui_imgview_filelist_free();
    cui_imgview_fl_restore_file_list();
    mmi_frm_group_close(image_viewer_id);
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_run
 * DESCRIPTION
 *  Run image view cui.
 * PARAMETERS
 *  image_viewer_id   :  [IN]  Image view group id.
 * RETURNS
 *  None.
 *****************************************************************************/
void cui_imgview_run(mmi_id image_viewer_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, CUI_IMGVIEW_RUN, image_viewer_id);
    MMI_ASSERT(g_imgview_cui_ptr != NULL);
    if (g_imgview_cui_ptr->view_mode.viewmode != CUI_IMGVIEW_VIEWMODE_FILENAME)
    {
        g_imgview_cui_ptr->lsk_setting.is_customized = MMI_FALSE;
    }
#ifdef __MMI_IMAGE_VIEWER_EX__
    mmi_ivex_enter_view_from_cui(image_viewer_id);
#elif defined  __MMI_IMAGE_VIEWER_ADV__
    mmi_imgadv_enter_view_from_cui(image_viewer_id);
#else
    mmi_imgview_enter_view_from_cui(image_viewer_id);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_set_ui_direction
 * DESCRIPTION
 *  Configure the item display of ui.
 * PARAMETERS
 *  image_viewer_id     :   [IN]  Image view group id.
 *  direction           :   [IN]  The init ui rotate
 * RETURNS
 *  None.
 *****************************************************************************/
void cui_imgview_set_ui_direction(mmi_id image_viewer_id,cui_imgview_ui_direction_enum direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, CUI_IMGVIEW_UI_DIRECT, direction);
#ifdef __MMI_IMAGE_VIEWER_EX__
    mmi_ivex_set_ui_direct(image_viewer_id,direction);
#elif defined  __MMI_IMAGE_VIEWER_ADV__
    mmi_imgadv_set_ui_direct(image_viewer_id,direction);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_set_ui_item_display
 * DESCRIPTION
 *  Configure the item display of ui.
 * PARAMETERS
 *  image_viewer_id        :   [IN]  Image view group id.
 *  item_id                :   [IN]  zoom_in zoom_out rotate ...
 *  is_enable              :   [IN]  TRUE for enable and FALSE for disable.
 * RETURNS
 *  None.
 *****************************************************************************/
void cui_imgview_set_display_cap(
                    mmi_id image_viewer_id, 
                    cui_imgview_cap_enum item_id, 
                    MMI_BOOL is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_id == CUI_IMGVIEW_CAP_ALL)
    {
        for (index = 0; index < CUI_IMGVIEW_CAP_ALL; index++)
        {
            g_imgview_cui_ptr->cap_enable[index] = is_enable;
        }
    }
    else
    {
        g_imgview_cui_ptr->cap_enable[item_id] = is_enable;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_set_title
 * DESCRIPTION
 *  Set title string and title icon of image view CUI,
 *  mainly serve ADV and or original image viewer,
 *  this is for user special case, such as email.
 * PARAMETERS
 *  media_viewer_id         :  [IN]  Image view group id.
 *  string                  :  [IN]  new resource id of title string
 *  icon                    :  [IN]  new resource id of title icon
 * RETURNS
 *  None.
 *****************************************************************************/
void cui_imgview_set_title(mmi_id image_viewer_id, const WCHAR* string, U16 icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgview_cui_ptr->title_confing.is_customized = MMI_TRUE;
    g_imgview_cui_ptr->title_confing.title_icon = icon;
    mmi_ucs2cpy(g_imgview_cui_ptr->title_confing.title_string, (CHAR*)string);
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_set_lsk_id
 * DESCRIPTION
 *  Configure LSK style.
 *  If user call this API, the display cap CUI_IMGVIEW_CAP_OPTION will invalid,
 * PARAMETERS
 *  image_viewer_id     :   [IN]  Image view group id.
 *  stringid            :   [IN]  String ID
 *  imageid             :   [IN]  Image ID.
 * RETURNS
 *  None.
 *****************************************************************************/
void cui_imgview_set_lsk_id(mmi_id image_viewer_id, U16 stringid, U16 imageid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgview_cui_ptr->lsk_setting.is_customized = MMI_TRUE;
    g_imgview_cui_ptr->lsk_setting.imageid = imageid;
    g_imgview_cui_ptr->lsk_setting.stringid = stringid;
    /* if user set lsk himself, the option will disable automaticly */
    g_imgview_cui_ptr->cap_enable[CUI_IMGVIEW_CAP_OPTION] = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_set_lsk_enable_even_view_err
 * DESCRIPTION
 *  This function set if LSK enable when can view an image.
 *  It is only valid for NON-OPTION lable 
 * PARAMETERS
 *  image_viewer_id     :   [IN]  Image view group id.
 *  is_enable           :   [IN]  TRUE is enable
 * RETURNS
 *  None.
 *****************************************************************************/
void cui_imgview_set_lsk_enable_even_view_err(mmi_id image_viewer_id, MMI_BOOL is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgview_cui_ptr->lsk_setting.is_force_enable = is_enable;
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_set_mode_filename
 * DESCRIPTION
 *  This function is for viewing a single file.
 * PARAMETERS
 *  image_viewer_id     :   [IN]  Image view group id.
 *  filename            :   [IN]  Filename.
 * RETURNS
 *  None.
 *****************************************************************************/
void cui_imgview_set_mode_filename(mmi_id image_viewer_id, CHAR* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_imgview_cui_ptr->view_mode.buff_ptr != NULL);
    MMI_ASSERT(filename != NULL);
    mmi_ucs2cpy(g_imgview_cui_ptr->view_mode.buff_ptr, filename);
    g_imgview_cui_ptr->view_mode.viewmode = CUI_IMGVIEW_VIEWMODE_FILENAME;
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_set_mode_filelist
 * DESCRIPTION
 *  This function is for viewing file list.
 * PARAMETERS
 *  image_viewer_id      :  [IN]  Image view group id.
 *  filelist             :  [IN]  File list.
 *  start_index          :  [IN]  Start view index.
 * RETURNS
 *  None.
 *****************************************************************************/
void cui_imgview_set_mode_filelist(
                    mmi_id image_viewer_id, 
                    SRV_FMGR_FILELIST_HANDLE filelist, 
                    U32 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(filelist != 0);
    g_imgview_cui_ptr->view_mode.viewmode = CUI_IMGVIEW_VIEWMODE_FILELIST;
    g_imgview_cui_ptr->view_mode.filelist = filelist;
    g_imgview_cui_ptr->view_mode.start_index = start_index;
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_set_mode_filename_array
 * DESCRIPTION
 *  This function is for viewing array of filename.
 * PARAMETERS
 *  image_viewer_id     :  [IN]  Image view group id.
 *  name_array          :  [IN]  Filename array. app must keep this until stop cui
 *  array_count         :  [IN]  Number of the file in the array.
 *  start_index         :  [IN]  Start index.
 * RETURNS
 *  None.
 *****************************************************************************/
void cui_imgview_set_mode_filename_array(
                    mmi_id image_viewer_id, 
                    CHAR* *name_array, 
                    U32 array_count, 
                    U32 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_imgview_cui_ptr->view_mode.buff_ptr != NULL);
    MMI_ASSERT(name_array != NULL);
    g_imgview_cui_ptr->view_mode.viewmode = CUI_IMGVIEW_VIEWMODE_FILENAME_ARRAY;
    g_imgview_cui_ptr->view_mode.buff_ptr = *name_array; /* Here keep a pointer of array [Jibin] */
    g_imgview_cui_ptr->view_mode.start_index = start_index;
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_set_mode_prefetch_filename_func
 * DESCRIPTION
 *  View the image get by dynamic filename function. user should add function 
 *  to process EVT_ID_IMGVIEW_GET_FILENAME event and pass path at this event.
 * PARAMETERS
 *  image_viewer_id       :  [IN]  Image view group id.
 *  start_index           :  [IN]  Start index.
 *  user_data             :  [IN]  User data.
 * RETURNS
 *  None.
 *****************************************************************************/
void cui_imgview_set_mode_prefetch_filename_func(
                mmi_id image_viewer_id, 
                U32 start_index,
                U32 total_count,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_imgview_cui_ptr->view_mode.buff_ptr != NULL);
    g_imgview_cui_ptr->view_mode.viewmode = CUI_IMGVIEW_VIEWMODE_PREFETCH;
    g_imgview_cui_ptr->view_mode.start_index = start_index;
    g_imgview_cui_ptr->view_mode.total_count = total_count;
    //g_imgview_cui_ptr->view_mode.buff_ptr = user_data;
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_set_mode_imageid_array
 * DESCRIPTION
 *  This function is for viewing image id array.
 * PARAMETERS
 *  image_viewer_id      :  [IN]  Image view group id.
 *  imageid_array        :  [IN]  Image id array.
 *  count                :  [IN]  Image count.
 *  start_index          :  [IN]  Start index.
 * RETURNS
 *  None.
 *****************************************************************************/
void cui_imgview_set_mode_imageid_array(
                mmi_id image_viewer_id,
                U32 *imageid_array, 
                U32 count,
                U32 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_imgview_cui_ptr->view_mode.buff_ptr != NULL);
    MMI_ASSERT(imageid_array != NULL);
    MMI_ASSERT(count > 0);
    g_imgview_cui_ptr->view_mode.viewmode = CUI_IMGVIEW_VIEWMODE_IMAGEID_ARRAY;
    //g_imgview_cui_ptr->view_mode.buff_ptr = imageid_array; /* Here keep a pointer of array [Jibin] */
    g_imgview_cui_ptr->view_mode.start_index = start_index;
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_set_mode_folder_path
 * DESCRIPTION
 *  This function is for viewing image under a folder.
 * PARAMETERS
 *  image_viewer_id      :  [IN]  Image view group id.
 *  path                 :  [IN]  Folder path for browse.
 *  sort_by              :  [IN]  Set sort by filename or time or not.
 *  start_index          :  [IN]  Start index.
 * RETURNS
 *  None.
 *****************************************************************************/
void cui_imgview_set_mode_folder_path(
                mmi_id image_viewer_id,
                const WCHAR* path, 
                cui_imgview_sort_enum sort_by,
                U32 start_index,
                void* filelist_buffer,
                S32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_imgview_cui_ptr->view_mode.buff_ptr != NULL);
    MMI_ASSERT(path != NULL);
    MMI_ASSERT(filelist_buffer != NULL);
    MMI_ASSERT(buffer_size >= SRV_FMGR_FOLDER_FILELIST_MEM_SIZE);
    g_imgview_cui_ptr->view_mode.viewmode = CUI_IMGVIEW_VIEWMODE_FOLDER;
    mmi_ucs2cpy(g_imgview_cui_ptr->view_mode.buff_ptr, (const CHAR*)path); /* Here keep a folder path */
    g_imgview_cui_ptr->view_mode.start_index = start_index;
    g_imgview_cui_ptr->view_mode.sort_by = sort_by;
    g_imgview_cui_ptr->view_mode.filelist_buffer = filelist_buffer;
    g_imgview_cui_ptr->view_mode.filelist_buffer_size = buffer_size;
}

void cui_imgiew_set_storage_enable(mmi_id cui_id)
{
    g_imgview_cui_ptr->storage_select_enable = MMI_TRUE;
}


#define  IMGVIEW_HANDLE_LIST
/*
 * File list state.
 */
enum {
    CUI_IMGVIEW_FL_STAT_INIT = 0,
    CUI_IMGVIEW_FL_STAT_REFRESH, /* use new and waiting for refreshing result */
    CUI_IMGVIEW_FL_STAT_CHANGED    /* use new and refreshing terminate */
};

/*
 * context of file list
 */
typedef struct{
    U32         stat;
    FMGR_FILTER filter;
    U32         sort;
    WCHAR       *filepath;
    MMI_ID      waiting_scrn_id;
}cui_imgview_fl_context_t;

static cui_imgview_fl_context_t g_fl_cntx;


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_fl_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param            
 * RETURNS
 *  
 *****************************************************************************/
static void cui_imgview_fl_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_fl_cntx, 0, sizeof(g_fl_cntx));
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_set_enter_view_fun
 * DESCRIPTION
 *  Set enter function
 * PARAMETERS
 *  image_viewer_id              :   [IN]  Image view group id.
 * RETURNS
 *  void
 *****************************************************************************/
void cui_imgview_reset_fun(mmi_id image_viewer_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry_fun = NULL;
    filelist_config_fun = NULL;
}



/*****************************************************************************
 * FUNCTION
 *  cui_imgview_set_enter_view_fun
 * DESCRIPTION
 *  Set enter function
 * PARAMETERS
 *  image_viewer_id              :   [IN]  Image view group id.
 *  enter_view_screen            :   [IN]  View enter function
 * RETURNS
 *  void
 *****************************************************************************/
void cui_imgview_set_enter_view_fun(mmi_id image_viewer_id, void(*enter_view_screen)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry_fun = enter_view_screen;
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_set_enter_view_fun
 * DESCRIPTION
 *  Set enter function
 * PARAMETERS
 *  image_viewer_id              :   [IN]  Image view group id.
 *  enter_view_screen            :   [IN]  View enter function
 * RETURNS
 *  void
 *****************************************************************************/
void cui_imgview_set_filelist_config_fun(mmi_id image_viewer_id, void(*filelist_config)(SRV_FMGR_FILELIST_HANDLE filelist, U32 start_index, U32 total_count))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filelist_config_fun = filelist_config;
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_cancel_waiting
 * DESCRIPTION
 *  This function is cancel sorting.
 * PARAMETERS
 *  void
 * RETURNS
 *  Void.
 *****************************************************************************/
void cui_imgview_cancel_waiting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgview_cui_ptr->view_mode.viewmode == CUI_IMGVIEW_VIEWMODE_FOLDER)
    {
        cui_imgview_filelist_free();
    }
    else if (g_imgview_cui_ptr->view_mode.viewmode == CUI_IMGVIEW_VIEWMODE_FILELIST)
    {
        cui_imgview_fl_restore_file_list();
    }
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_enter_waiting_screen
 * DESCRIPTION
 *  This function is entrance of sorting.
 * PARAMETERS
 *  image_viewer_id        :  [IN]  Image view group id.
 * RETURNS
 *  Void.
 *****************************************************************************/
void cui_imgview_enter_waiting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 guiBuffer;
    MMI_BOOL entry_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_is_in_backward_scenario() && !mmi_frm_group_is_present(g_imgview_cui_ptr->imgview_cui_gid))
    {
        mmi_frm_group_enter(g_imgview_cui_ptr->imgview_cui_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }
    
    entry_ret = mmi_frm_scrn_enter(g_imgview_cui_ptr->imgview_cui_gid, SCR_ID_IMGVIEW_SORTING, NULL, cui_imgview_enter_waiting_screen, MMI_FRM_FULL_SCRN);
    if (!entry_ret)
    {
        return;
    }
    
    guiBuffer = mmi_frm_scrn_get_gui_buf(g_imgview_cui_ptr->imgview_cui_gid, SCR_ID_IMGVIEW_SORTING);
    g_fl_cntx.stat = CUI_IMGVIEW_FL_STAT_REFRESH;
        
    ShowCategory165Screen(
        0, 
        0, 
        STR_GLOBAL_CANCEL, 
        0, 
        (UI_string_type) GetString(STR_GLOBAL_PLEASE_WAIT), 
        (U16) IMG_GLOBAL_LOADING, 
        guiBuffer);
    SetRightSoftkeyFunction(cui_imgview_cancel_waiting, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_filelist_refresh_proc
 * DESCRIPTION
 *  This function create a list.
 * PARAMETERS
 *  image_viewer_id      :  [IN]  Image view group id.
 * RETURNS
 *  S32.
 *****************************************************************************/
mmi_ret cui_imgview_filelist_refresh_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_filelist_refresh_result_event_struct *evt = (srv_fmgr_filelist_refresh_result_event_struct*) param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id) 
    {
        case EVT_ID_SRV_FMGR_FILELIST_REFRESH_RESULT:
        {
            if (g_fl_cntx.stat == CUI_IMGVIEW_FL_STAT_REFRESH)
            {
                if (evt->result >= 0)
                {
                    g_fl_cntx.stat = CUI_IMGVIEW_FL_STAT_CHANGED;
                    g_imgview_cui_ptr->view_mode.start_index = evt->search_index;
                    g_imgview_cui_ptr->view_mode.total_count = evt->total_count;
                    if (g_imgview_cui_ptr->view_mode.total_count > 0)
                    {
                        filelist_config_fun(g_imgview_cui_ptr->view_mode.filelist, g_imgview_cui_ptr->view_mode.start_index, g_imgview_cui_ptr->view_mode.total_count);
                        entry_fun();
                        cui_imgview_reset_fun(g_imgview_cui_ptr->imgview_cui_gid);
                        mmi_frm_scrn_close(g_imgview_cui_ptr->imgview_cui_gid, SCR_ID_IMGVIEW_SORTING);
                    }
                    else
                    {
                        mmi_imgview_display_popup_sg(g_imgview_cui_ptr->imgview_cui_gid, (UI_string_type)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);
                        cui_imgview_close_cui(g_imgview_cui_ptr->imgview_cui_gid);
                    }
                }
                else
                {
                    mmi_str_id error_str_id;
                    error_str_id = srv_fmgr_fs_error_get_string(evt->result);
                    mmi_imgview_display_popup_sg(g_imgview_cui_ptr->imgview_cui_gid, (UI_string_type)GetString(error_str_id), (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(evt->result), 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);
                    cui_imgview_close_cui(g_imgview_cui_ptr->imgview_cui_gid);
                }
            }
        }
        break;
    }
    
    return MMI_RET_OK;
}


#define  IMGVIEW_CREATE_LIST
/*****************************************************************************
 * FUNCTION
 *  cui_imgview_filelist_get_sort_by
 * DESCRIPTION
 *  This function get sort type for a list.
 * PARAMETERS
 *  image_viewer_id      :  [IN]  Image view group id.
 *  sort_by              :  [IN]  Set sort by filename or time or not.
 * RETURNS
 *  FMGR sort type.
 *****************************************************************************/
U16 cui_imgview_filelist_get_sort_by(mmi_id image_viewer_id, cui_imgview_sort_enum sort_by)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 sort_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sort_by)
    {
        case CUI_IMGVIEW_SORT_NONE:
            sort_type = FS_NO_SORT;
            break;

        case CUI_IMGVIEW_SORT_NAME:
            sort_type = FS_SORT_NAME;
            break;

        case CUI_IMGVIEW_SORT_TYPE:
            sort_type = FS_SORT_TYPE;
            break;

        case CUI_IMGVIEW_SORT_TIME:
            sort_type = FS_SORT_TIME;
            break;

        case CUI_IMGVIEW_SORT_SIZE:
            sort_type = FS_SORT_SIZE;
            break;

        default:
            sort_type = FS_NO_SORT;
            break;
    }
    return sort_type;
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_filelist_create
 * DESCRIPTION
 *  This function create a list.
 * PARAMETERS
 *  image_viewer_id      :  [IN]  Image view group id.
 * RETURNS
 *  S32.
 *****************************************************************************/
S32 cui_imgview_filelist_create(mmi_id image_viewer_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    S32 result;
    U16 sort_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_imgview_cui_ptr != NULL);
    MMI_ASSERT(g_imgview_cui_ptr->view_mode.viewmode == CUI_IMGVIEW_VIEWMODE_FOLDER);
    MMI_ASSERT(g_imgview_cui_ptr->view_mode.buff_ptr != NULL);
    if (g_imgview_cui_ptr->view_mode.filelist != 0) /*has created*/
    {
        /* should not enter here */
        ASSERT(0);
        return 0;
    }

    /* Set filter */
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_IMAGE(&filter);
    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_ANM);
    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_EMS);

    #if defined(__DRM_V02__)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
    #endif
    sort_type = cui_imgview_filelist_get_sort_by(image_viewer_id, g_imgview_cui_ptr->view_mode.sort_by);
    result = srv_fmgr_folder_filelist_create(
            (WCHAR*)g_imgview_cui_ptr->view_mode.buff_ptr,
            &filter, sort_type,
            g_imgview_cui_ptr->view_mode.filelist_buffer,
            g_imgview_cui_ptr->view_mode.filelist_buffer_size,
            &g_imgview_cui_ptr->view_mode.filelist);
    srv_fmgr_filelist_refresh(g_imgview_cui_ptr->view_mode.filelist, NULL, 0, 0, cui_imgview_filelist_refresh_proc, NULL);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_filelist_free
 * DESCRIPTION
 *  This function free a list.
 * PARAMETERS
 *  void
 * RETURNS
 *  S32.
 *****************************************************************************/
static void cui_imgview_filelist_free(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgview_cui_ptr->view_mode.filelist && g_imgview_cui_ptr->view_mode.viewmode == CUI_IMGVIEW_VIEWMODE_FOLDER)
    {
        srv_fmgr_filelist_destroy(g_imgview_cui_ptr->view_mode.filelist);
        g_imgview_cui_ptr->view_mode.filelist = 0;
        cui_imgview_fl_init();
    }
}


#define IMGVIEW_REFRESH_LIST
/*****************************************************************************
 * FUNCTION
 *  cui_imgview_fl_init_file_list
 * DESCRIPTION
 *  Check if the file list need to refresh with image filter.
 * PARAMETERS
 *  param            
 * RETURNS
 *  0 -- File list is OK
 *  1 -- Refreshing list.
 *****************************************************************************/
static S32 cui_imgview_fl_init_file_list()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    S32         i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_imgview_cui_ptr->view_mode.viewmode != CUI_IMGVIEW_VIEWMODE_FILELIST){
        return 0;
    }

    srv_fmgr_filelist_get_filepath(
        g_imgview_cui_ptr->view_mode.filelist,
        g_imgview_cui_ptr->view_mode.start_index,
        (WCHAR*)g_imgview_cui_ptr->view_mode.buff_ptr,
        SRV_FMGR_PATH_BUFFER_SIZE);
    
    g_imgview_cui_ptr->storage = *((U16*)g_imgview_cui_ptr->view_mode.buff_ptr);
    
    /* Configure filter */
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_IMAGE(&filter);
    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_ANM);
    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_EMS);
#if defined(__DRM_V02__)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
#endif
    srv_fmgr_filelist_get_setting(g_imgview_cui_ptr->view_mode.filelist, &g_fl_cntx.filter, &g_fl_cntx.sort);

    for (i = FMGR_TYPE_ALL; i < FMGR_TYPE_COUNT; i++)
    {
        if (FMGR_FILTER_IS_SET(&(g_fl_cntx.filter), i) && !FMGR_FILTER_IS_SET(&filter, i))
            break;
    }

    if (i == FMGR_TYPE_COUNT)
        return 0;

    g_fl_cntx.stat = CUI_IMGVIEW_FL_STAT_REFRESH;

    srv_fmgr_filelist_set_setting(g_imgview_cui_ptr->view_mode.filelist, &filter, g_fl_cntx.sort);
    srv_fmgr_filelist_refresh(g_imgview_cui_ptr->view_mode.filelist, srv_fmgr_path_get_filename_const_ptr((WCHAR*)g_imgview_cui_ptr->view_mode.buff_ptr), 0, 0, cui_imgview_filelist_refresh_proc, NULL);
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_fl_restore_file_list
 * DESCRIPTION
 *  Restore file list. Only be called from group de-init process.
 * PARAMETERS
 *  param            
 * RETURNS
 *  0 -- File list is OK
 *  1 -- Refreshing list.
 *****************************************************************************/
static void cui_imgview_fl_restore_file_list()
{
     if(g_fl_cntx.stat != CUI_IMGVIEW_FL_STAT_INIT && 
        g_imgview_cui_ptr->view_mode.viewmode == CUI_IMGVIEW_VIEWMODE_FILELIST){
        srv_fmgr_filelist_set_setting(g_imgview_cui_ptr->view_mode.filelist, &g_fl_cntx.filter, g_fl_cntx.sort);
        srv_fmgr_filelist_abort(g_imgview_cui_ptr->view_mode.filelist);
        cui_imgview_fl_init();
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_enter_before_play
 * DESCRIPTION
 *  This function ready to play for folder mode.
 * PARAMETERS
 *  image_viewer_id        :  [IN]  Image view group id.
 * RETURNS
 *  Void.
 *****************************************************************************/
void cui_imgview_enter_before_play(mmi_id image_viewer_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 retValue;
    MMI_ID_TYPE error_str_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgview_cui_ptr->view_mode.viewmode == CUI_IMGVIEW_VIEWMODE_FOLDER)
    {
        cui_imgview_filelist_free();
        retValue = cui_imgview_filelist_create(image_viewer_id);
        if (retValue == FS_NO_ERROR)
        {
            cui_imgview_enter_waiting_screen();
        }
        else
        {
            /* error handle */
            error_str_id = srv_fmgr_fs_error_get_string(retValue);
            mmi_imgview_display_popup_sg(g_imgview_cui_ptr->imgview_cui_gid, (UI_string_type)GetString(error_str_id), (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(retValue), 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);
            cui_imgview_close_cui(image_viewer_id);
        }
    }
    else if (g_imgview_cui_ptr->view_mode.viewmode == CUI_IMGVIEW_VIEWMODE_FILELIST)
    {
        if (cui_imgview_fl_init_file_list())
        {
            cui_imgview_enter_waiting_screen();
        }
        else
        {
            g_imgview_cui_ptr->view_mode.total_count = srv_fmgr_filelist_count(g_imgview_cui_ptr->view_mode.filelist);
            filelist_config_fun(g_imgview_cui_ptr->view_mode.filelist, g_imgview_cui_ptr->view_mode.start_index, g_imgview_cui_ptr->view_mode.total_count);
            entry_fun();
            cui_imgview_reset_fun(g_imgview_cui_ptr->imgview_cui_gid);
        }
    }
}


#define  IMGVIEW_EX
/*****************************************************************************
 * FUNCTION
 *  cui_imgview_set_no_first_loading
 * DESCRIPTION
 *  Set not show loading at first image for special usage.
 * PARAMETERS
 *  image_viewer_id         :  [IN]  Image View group id.
 *  has_loading             :  [IN]  If has loading state for the first image.
 * RETURNS
 *  None.
 *****************************************************************************/
void cui_imgview_set_first_loading(mmi_id image_viewer_id, MMI_BOOL has_loading)
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
 *  cui_imgview_set_app_id
 * DESCRIPTION
 *  This function is for setting caller (parent) app id.
 * PARAMETERS
 *  image_viewer_id            :  [IN]  Image view group id.
 *  app_id                     :  [IN]  Caller (parent) app id.
 * RETURNS
 *  None.
 *****************************************************************************/
void cui_imgview_set_app_id(mmi_id image_viewer_id, U16 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgview_cui_ptr->parent_app_id = app_id;
}

/*****************************************************************************
 * FUNCTION
 *  cui_imgview_set_app_id
 * DESCRIPTION
 *  This function is for setting caller (parent) app id.
 * PARAMETERS
 *  image_viewer_id            :  [IN]  Image view group id.
 *  app_id                     :  [IN]  Caller (parent) app id.
 * RETURNS
 *  None.
 *****************************************************************************/
MMI_BOOL cui_imgview_get_file_name(mmi_id image_viewer_id, CHAR* file_name, S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    CHAR* ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_imgview_cui_ptr == NULL || file_name == NULL)
        return MMI_FALSE;
    if(image_viewer_id != g_imgview_cui_ptr->imgview_cui_gid)
        return MMI_FALSE;

    switch(g_imgview_cui_ptr->view_mode.viewmode){
    case CUI_IMGVIEW_VIEWMODE_FILENAME:
    case CUI_IMGVIEW_VIEWMODE_PREFETCH:
        ptr = g_imgview_cui_ptr->view_mode.buff_ptr;
        if(ptr != NULL){
            if(size >= (mmi_ucs2strlen(ptr) + 1) * ENCODING_LENGTH){
                mmi_ucs2cpy(file_name, ptr);
                ret = MMI_TRUE;
            }
        }
        break;

    case CUI_IMGVIEW_VIEWMODE_FILELIST:
    case CUI_IMGVIEW_VIEWMODE_FOLDER:
        {            
            if(srv_fmgr_filelist_get_filepath(g_imgview_fl_hdl, g_imgview_fl_idx, (WCHAR*)file_name, size) >= 0)
            {
                ret = MMI_TRUE;
            }
        }
        break;
        
    default:
        break;
        
    };

    return ret;
}

extern S32 cui_imgview_get_cur_index(mmi_id cui_id)
{
    return g_imgview_fl_idx;
}


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_get_cur_filename
 * DESCRIPTION
 *  Caution: this is not for external use, please use cui_imgview_get_file_name instead
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
extern const WCHAR* cui_imgview_get_cur_filename(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_imgview_cui_ptr == NULL)
        return NULL;
    if(cui_id != g_imgview_cui_ptr->imgview_cui_gid)
        return NULL;

    switch(g_imgview_cui_ptr->view_mode.viewmode){
    case CUI_IMGVIEW_VIEWMODE_FILENAME:
    case CUI_IMGVIEW_VIEWMODE_PREFETCH:
        return srv_fmgr_path_get_filename_const_ptr((WCHAR*)g_imgview_cui_ptr->view_mode.buff_ptr);

    case CUI_IMGVIEW_VIEWMODE_FILELIST:
    case CUI_IMGVIEW_VIEWMODE_FOLDER:
        if(srv_fmgr_filelist_get_filepath(g_imgview_fl_hdl, g_imgview_fl_idx, (WCHAR*)g_imgview_cui_ptr->view_mode.buff_ptr, SRV_FMGR_PATH_BUFFER_SIZE) >= 0)
            return srv_fmgr_path_get_filename_const_ptr((WCHAR*)g_imgview_cui_ptr->view_mode.buff_ptr);
        break;
        
    default:
        break;
        
    }

    return NULL;
}

#define  IMGVIEW_ADV


#define  IMGVIEW_ORIG


#define  IMGVIEW_ORIG_ADV_SINGLE


#define  MEDIAVIE_COMMON
/*****************************************************************************
 * FUNCTION
 *  cui_mediaview_construct_user_data
 * DESCRIPTION
 *  This function get memory of context varialbe needed and construct user date structure.
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL.
 *****************************************************************************/
MMI_BOOL cui_mediaview_construct_user_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* single instance will use global context */
    g_mediaview_cui_ptr = &g_mediaview_cui_cntx;
    g_mediaview_cui_ptr->folder_path = &g_mediaview_cui_folderpath[0];
    if (g_mediaview_cui_ptr->mediaview_cui_gid == 0)
    {
        g_mediaview_cui_ptr->mediaview_cui_gid = GRP_ID_INVALID;
    }
    return MMI_TRUE;
    /* ToDo, multi instance will malloc memory for cui context and imageviwer context */
}


/*****************************************************************************
 * FUNCTION
 *  cui_mediaview_disconstruct_user_data
 * DESCRIPTION
 *  This function reset user date structure.
 * PARAMETERS
 * Void.
 * RETURNS
 *  Void.
 *****************************************************************************/
void cui_mediaview_disconstruct_user_data(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_evt_struct *evt_s = (mmi_scenario_evt_struct *)evt;
    cui_mediaview_context_struct *instance_data = NULL;
    mmi_id mediaview_cui_gid = evt_s->targ_group;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, CUI_MEDIAVIEW_DISCONS, mediaview_cui_gid);
    instance_data = (cui_mediaview_context_struct*)mmi_frm_group_get_user_data(mediaview_cui_gid);
    if (instance_data != NULL)
    {
        instance_data->mediaview_cui_gid = GRP_ID_INVALID;
        /* ToDo, Free g_mediaview_cui_ptr->folder_path and g_mediaview_cui_ptr memory for multi instance */
        g_mediaview_cui_ptr = NULL;
    }
    else
    {
        //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, CUI_MEDIAVIEW_DISCONS, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_mediaview_init_user_data
 * DESCRIPTION
 *  This function initinalize user data.
 * PARAMETERS
 *  
 * RETURNS
 *  None.
 *****************************************************************************/
void cui_mediaview_init_user_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_mediaview_cui_ptr->folder_path != NULL);
    memset((void*)(g_mediaview_cui_ptr->folder_path), 0, SRV_FMGR_PATH_BUFFER_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  cui_mediaview_close_view_cui
 * DESCRIPTION
 *  Close view cui group when browse is closed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_mediaview_close_cui(mmi_id media_viewer_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_event_struct evt;
    mmi_group_node_struct group_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDIAVIEW_IVEX_CUI_CLOSE_BLOCK, *media_viewer_id;
    mmi_frm_group_get_info(media_viewer_id, &group_info);

    if(group_info.state == MMI_SCENARIO_STATE_CREATE)
    {
        mmi_frm_group_close(media_viewer_id);
    }
    else
    {
        evt.evt_id = EVT_ID_MEDIAVIEW_CLOSE_GID;
        evt.sender_id = media_viewer_id;
        evt.size = sizeof(mmi_group_event_struct);
        mmi_frm_group_send_to_parent(media_viewer_id, &evt);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_mediaview_group_proc
 * DESCRIPTION
 *  Media view cui process function.
 * PARAMETERS
 *  evt         :  [IN]  Events pointer.
 * RETURNS
 *  mmi_ret.
 *****************************************************************************/
mmi_ret cui_mediaview_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, CUI_MEDIAVIEW_PROC, evt->evt_id);
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_ENTER:
        /* enter group ToDo1 */
            break;
        case EVT_ID_GROUP_ACTIVE:
        /* enter group ToDo2 */
            break;
        case EVT_ID_GROUP_FOCUSED:
        /* enter group ToDo3 */
            break;
        case EVT_ID_GROUP_GOBACK:
        /* gobackhistory ToDo1 */
            break;
        case EVT_ID_GROUP_INACTIVE:
        /* gobackhistory ToDo1 */
            break;
        case EVT_ID_GROUP_EXIT:
        /* gobackhistory ToDo1 */
            break;
        case EVT_ID_GROUP_DEINIT:
        /* gobackhistory ToDo1 */
            cui_mediaview_disconstruct_user_data(evt);
            cui_mediaview_close(((mmi_scenario_evt_struct *)evt)->targ_group);
            break;
        case EVT_ID_IMGVIEW_CLOSE_GID:
            cui_imgview_close(((mmi_group_event_struct*)evt)->sender_id);
            break;
        case EVT_ID_ALERT_QUIT:
            if (((mmi_event_popoupcallback_result_struct*)evt)->user_tag == (void*)MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP)
            {
                cui_mediaview_close_cui(g_mediaview_cui_ptr->mediaview_cui_gid);
            }
            if ((((mmi_alert_result_evt_struct*)evt)->user_tag == (void*)MMI_IMGVIEW_POPUP_RESULT_PROCESS_CONFIRM_STORAGE))
            {
                mmi_alert_result_evt_struct *alert_evt = (mmi_alert_result_evt_struct*)evt;
                if (alert_evt->result == MMI_ALERT_CNFM_YES)
                {
                    mmi_imgview_change_storage_confirm_yes();
                }
                else if (alert_evt->result == MMI_ALERT_CNFM_NO || /* select no */
                         alert_evt->result == MMI_ALERT_INTERRUPT_EXIT) /* interrupt close */
                {
                    mmi_imgview_change_storage_confirm_no();
                }
            }
            break;
        case EVT_ID_CUI_STORAGE_SELECTOR_RESULT:
            {
                mmi_imgview_storage_select_cb(((cui_storage_selector_result_event_struct*)evt)->result);
                cui_storage_selector_close(((cui_storage_selector_result_event_struct*)evt)->sender_id);
            }
            break;

        case EVT_ID_CUI_FOLDER_BROWSER_ON_QUIT:
        /* Quit browse cui */
            cui_mediaview_close_cui(g_mediaview_cui_ptr->mediaview_cui_gid);
            break;

        case EVT_ID_CUI_FOLDER_BROWSER_ON_OPTION:
        case EVT_ID_CUI_FOLDER_BROWSER_ON_ENTRY:    
        case EVT_ID_CUI_FOLDER_BROWSER_ON_EXIT:     
        case EVT_ID_CUI_FOLDER_BROWSER_ON_EMPTY:
        case EVT_ID_CUI_FOLDER_BROWSER_ON_MENU:
        case EVT_ID_CUI_FOLDER_BROWSER_ON_CSK:
            mmi_mediaview_browser_cui_proc(evt);
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_mediaview_create
 * DESCRIPTION
 *  Creat media view cui.
 * PARAMETERS
 *  parent_gid  :  [IN]  parent id.
 * RETURNS
 *  mmi_id.
 *****************************************************************************/
mmi_id cui_mediaview_create(mmi_id parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_success = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, CUI_MEDIAVIEW_CREATE, parent_gid,g_mediaview_cui_ptr->mediaview_cui_gid);
    cui_view_close_existed_group(parent_gid);

    is_success = cui_mediaview_construct_user_data();
    if (is_success == MMI_FALSE)
    {
        return GRP_ID_INVALID;
    }
    
    cui_mediaview_init_user_data();

    g_mediaview_cui_ptr->mediaview_cui_gid = mmi_frm_group_create (parent_gid,  GRP_ID_AUTO_GEN, cui_mediaview_group_proc, (void*)g_mediaview_cui_ptr);
    return g_mediaview_cui_ptr->mediaview_cui_gid;
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, CUI_MEDIAVIEW_CREATE, parent_gid,g_mediaview_cui_ptr->mediaview_cui_gid);
}


/*****************************************************************************
 * FUNCTION
 *  cui_mediaview_close
 * DESCRIPTION
 *  Close function for media view cui.
 * PARAMETERS
 *  media_viewer_id   :  [IN]  Media view group id.
 * RETURNS
 *  None.
 *****************************************************************************/
extern void mmi_mediaview_app_reset(void);
void cui_mediaview_close(mmi_id media_viewer_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, CUI_MEDIAVIEW_CLOSE, media_viewer_id);
    mmi_frm_group_close(media_viewer_id);
    mmi_mediaview_app_reset();
    mmi_mediaview_reset_browse_gid();
}


/*****************************************************************************
 * FUNCTION
 *  cui_mediaview_run
 * DESCRIPTION
 *  Run media view cui.
 * PARAMETERS
 *  media_viewer_id   :  [IN]  Media view group id.
 * RETURNS
 *  None.
 *****************************************************************************/
void cui_mediaview_run(mmi_id media_viewer_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, CUI_MEDIAVIEW_RUN, media_viewer_id);
    MMI_ASSERT(g_mediaview_cui_ptr != NULL);
    mmi_mediaview_enter_from_cui(media_viewer_id);
}


/*****************************************************************************
 * FUNCTION
 *  cui_mediaview_set_browse_style
 * DESCRIPTION
 *  Close function for media view cui.
 * PARAMETERS
 *  media_viewer_id   :  [IN]  Media viewer group id.
 *  browse_style      :  [IN]  Browse style
 * RETURNS
 *  None.
 *****************************************************************************/
void cui_mediaview_set_browse_style(mmi_id media_viewer_id, cui_mediaview_style_enum browse_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mediaview_cui_ptr->view_style = browse_style;
}


/*****************************************************************************
 * FUNCTION
 *  cui_mediaview_set_folder_path
 * DESCRIPTION
 *  Close function for media view cui.
 * PARAMETERS
 *  media_viewer_id   :  [IN]  Media viewer group id.
 *  path              :  [IN]  Folder path
 * RETURNS
 *  None.
 *****************************************************************************/
void cui_mediaview_set_folder_path(mmi_id media_viewer_id, CHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (media_viewer_id != 0 && media_viewer_id != GRP_ID_INVALID)
    {
        mmi_ucs2cpy(g_mediaview_cui_ptr->folder_path, path);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_mediaview_set_app_id
 * DESCRIPTION
 *  This function is for setting caller (parent) app id.
 * PARAMETERS
 *  media_viewer_id      :  [IN]  Media view group id.
 *  app_id               :  [IN]  Caller (parent) app id.
 * RETURNS
 *  None.
 *****************************************************************************/
void cui_mediaview_set_app_id(mmi_id media_viewer_id, U16 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mediaview_cui_ptr->parent_app_id = app_id;
}


/*****************************************************************************
 * FUNCTION
 *  cui_mediaview_set_filter
 * DESCRIPTION
 *  This function is for setting media filter, under construction.
 * PARAMETERS
 *  media_viewer_id      :  [IN]  Media view group id.
 * RETURNS
 *  None.
 *****************************************************************************/
//void cui_mediaview_set_filter(mmi_id media_viewer_id, ......);


#endif /* __MMI_IMAGE_VIEWER__ */ 


