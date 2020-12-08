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
*  CatScreenBrowser.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Category Screen Browser
*
* Author:
* -------
*  
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
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_CSB_BROWSER__

#include "FileMgrSrvGProt.h"
#include "menucuigprot.h"
#include "fseditorcuigprot.h"

#ifdef __MMI_CSB_BROWSER__
#include "mmi_rp_app_csb_def.h"
#endif

#include "CatScreenBrowserDefs.h"
#include "CatScreenBrowserProts.h"
#include "MMIDataType.h"
#include "CatScreenBrowserResDef.h"
#include "fs_type.h"
#include "fs_func.h"
#include "stdio.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "ImeGprot.h"
#include "mmi_frm_history_gprot.h"
#include "CustMenuRes.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "GlobalConstants.h"
#include "wgui_categories.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "AlertScreen.h"
#include "mmi_frm_input_gprot.h"
#include "fs_errcode.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "wgui_categories_popup.h"
#include "mmi_rp_file_type_def.h"
#include "FileMgrGProt.h"
#include "mmi_res_range_def.h"
#include "gui.h"
/* Global Variables */
csb_struct g_CSB_struct;
U8 csb_buffer[MAX_CSB_SCREEN_NAME_LENGTH];
extern csb_screen_info screen_info[TOTAL_CATEGORY_SCREENS];

csb_category_screen csb_category_screen_list[TOTAL_CATEGORY_SCREENS];

U16 csb_search_hint_popups[CSB_TOTAL_CONTROLS] = {0};
U16 csb_app_hint_popups[CSB_TOTAL_APP] = {0};

S32 g_csb_timer;
U8 g_csb_highlighted_item;
U16 g_csb_index;

U8 g_buffer[MAX_LOCAL_BUFFER];
U8 g_buffer1[MAX_LOCAL_BUFFER_1];

/* Global image list array */
U16 g_image_id_list[2];

#ifdef __MMI_PREFER_INPUT_METHOD__
extern void SetInputMethod(U16 index);
#endif /* __MMI_PREFER_INPUT_METHOD__ */

static mmi_ret mmi_csb_proc(mmi_event_struct *evt);


/**************************************************************
********************* HIGHLIGHT HANDLERS **********************
***************************************************************/

/*****************************************************************************
 * FUNCTION
 *  InitCSB
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitCSB(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 csb_default_folder_path_ansii[MAX_CSB_PATH_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
	/* Commented as suggested by MTK */
    //csb_frm_read_from_nvram();

    g_CSB_struct.csb_settings.timer_value = 2000;
	g_CSB_struct.csb_settings.view_mode		= VIEW_MODE_MANUAL;
	g_CSB_struct.csb_settings.manual_mode	= MANUAL_MODE_INTERACTIVE;

        sprintf(csb_default_folder_path_ansii, "%c%s", SRV_FMGR_PUBLIC_DRV, CSB_DEFAULT_FOLDER);
        mmi_asc_to_ucs2(
            (PS8) g_CSB_struct.csb_settings.csb_screenshots_folder_path,
            (PS8) csb_default_folder_path_ansii);
  
    g_CSB_struct.pscreen_info = (csb_screen_info*) screen_info;

    /* Prepares the HINT pop-ups */
    csb_frm_prepare_search_hint_popups();
    csb_frm_prepare_app_hint_popups();
}


/*****************************************************************************
 * FUNCTION
 *  PreEntryCSBMainMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PreEntryCSBMainMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Resets the counter for the next show */
    g_CSB_struct.screen_counter = 0;
    /* Resets the buffer for the editor screens */
    memset(csb_buffer, CSB_NULL, MAX_CSB_SCREEN_NAME_LENGTH);

    /* It creates the CSB folder both in Phone Memory and Card Memory */
    csb_frm_create_csb_folder();

    /* Call the CSB main menu */
    EntryCSBMainMenu();
}


/*****************************************************************************
 * FUNCTION
 *  EntryCSBMainMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBMainMenu(void)
{
    mmi_id menu_gid;
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_CSB_ROOT, mmi_csb_proc, NULL);
    mmi_frm_group_enter(GRP_ID_CSB_ROOT, MMI_FRM_NODE_NONE_FLAG);
    
    menu_gid = cui_menu_create(
        GRP_ID_CSB_ROOT,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_APPSUB,
        CSB_MENUID,
        MMI_TRUE,NULL);
    cui_menu_run(menu_gid);

}

static mmi_ret mmi_csb_proc(mmi_event_struct *evt)
{
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    cui_fseditor_evt_struct *editor_evt = (cui_fseditor_evt_struct*)evt;
    S32 scrn_id;
    
    switch(evt->evt_id)
    {
    /**********************************************/
    /*                 Menu CUI                   */
    /**********************************************/          
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
        break;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
        switch(menu_evt->highlighted_menu_id)
        {
        case CSB_VIEW_MENUID:
            csb_frm_set_search_mode(SEARCH_BY_VIEW);
            break;
            
        case CSB_START_VIEW_MENUID:
            PreEntryCSBStartView();
            break;
            
        case CSB_START_VIEW_X_MENUID:
            EntryCSBStartViewX();
            break;
                       
        case CSB_VIEW_OPTIONS_VIEW_MODE_MENUID:
            EntryCSBOptionsViewMode();
            break;
                        
        case CSB_OPTIONS_SETTING_MANUAL_MODE_MENUID:
            EntryCSBOptionsManualMode();
            break;
            
        case CSB_OPTIONS_SETTING_AUTO_MODE_TIME_MENUID:
            EntryCSBOptionsAutoModeTime();
            break;
            
        case CSB_SEARCH_CONTROL_MENUID:
            EntryCSBSearchByControl();
            break;
            
        case CSB_SEARCH_APP_MENUID:
            EntryCSBSearchByApp();
            break;
            
        case CSB_SEARCH_SCREENID_MENUID:
            EntryCSBSearchByScrID();
            break;
            
        case CSB_TESTOOL_RUN_MENUID:
            PreEntryCSBTestToolRun();
            break;
            
        case CSB_TESTOOL_SET_LOC_MENUID:
            EntryCSBTestToolSetLoc();
            break;
            
        case CSB_TESTOOL_VIEW_IMAGES_MENUID:
            EntryCSBTestToolViewImages();
            break;
        }
        break;
        
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(menu_evt->sender_id);
        mmi_frm_group_close(GRP_ID_CSB_ROOT);
        break;

    /**********************************************/
    /*                Editor CUI                  */
    /**********************************************/    
    case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        scrn_id = cui_fseditor_get_parent_data(editor_evt->sender_id);

        if (scrn_id == SCR_ID_CSB_START_VIEW_X_SCR_ID)
        {
            cui_fseditor_get_text(editor_evt->sender_id, (WCHAR*)csb_buffer, MAX_CSB_SCREEN_NAME_LENGTH);
            csb_frm_validate_screen_name();
            cui_fseditor_close(editor_evt->sender_id);
        }
        else if (scrn_id == SCR_ID_CSB_SEARCH_BY_SCRID_SCR_ID)
        {
            cui_fseditor_get_text(editor_evt->sender_id, (WCHAR*)csb_buffer, MAX_CSB_SCREEN_NAME_LENGTH);
            csb_frm_validate_screen_name();
            cui_fseditor_close(editor_evt->sender_id);
        }
        else
        {
            ASSERT(0);
        }
        break;

    case EVT_ID_CUI_FSEDITOR_ABORT:
        cui_fseditor_close(editor_evt->sender_id);
        break;
        
    default:
        break;
    }
    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  PreEntryCSBStartView
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PreEntryCSBStartView(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Reset the counter */
    g_CSB_struct.screen_counter = 0;

    EntryCSBStartView();
}


/*****************************************************************************
 * FUNCTION
 *  EntryCSBStartViewX
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBStartViewX(void)
{
    mmi_id fseditor_gid;

    if ((fseditor_gid = cui_fseditor_create(GRP_ID_CSB_ROOT)) != 0)
    {
        cui_fseditor_set_title(fseditor_gid, STR_ID_CSB_START_VIEW_X_TEXT, 0);
        cui_fseditor_set_text(fseditor_gid, (WCHAR*)csb_buffer, MAX_CSB_SCREEN_NAME_LENGTH, MAX_CSB_SCREEN_NAME_LENGTH);
        cui_fseditor_set_input_method(fseditor_gid, IMM_INPUT_TYPE_NUMERIC, NULL, 0);
        cui_fseditor_set_parent_data(fseditor_gid, SCR_ID_CSB_START_VIEW_X_SCR_ID);
        cui_fseditor_run(fseditor_gid);       
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryCSBOptionsViewMode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBOptionsViewMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[VIEW_MODE_TOTAL];
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            GRP_ID_CSB_ROOT,
            SCR_ID_CSB_OPTIONS_VIEW_MODE_SCR_ID,
            NULL,
            EntryCSBOptionsViewMode,
            MMI_FRM_FULL_SCRN))
    {
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();

        nItems = GetNumOfChild(CSB_VIEW_OPTIONS_VIEW_MODE_MENUID);
        GetSequenceStringIds(CSB_VIEW_OPTIONS_VIEW_MODE_MENUID, ItemList);
        SetParentHandler(CSB_VIEW_OPTIONS_VIEW_MODE_MENUID);
        RegisterHighlightHandler(csb_frm_set_current_view_mode);

        ShowCategory11Screen(
            STR_ID_CSB_OPTIONS_VIEW_MODE_TEXT,
            0,
            STR_GLOBAL_OK,
            0,
            STR_GLOBAL_BACK,
            0,
            nItems,
            ItemList,
            g_CSB_struct.csb_settings.view_mode,
            guiBuffer);

        SetLeftSoftkeyFunction(csb_frm_save_view_mode, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  csb_frm_set_current_view_mode
 * DESCRIPTION
 *  Set the current view mode
 * PARAMETERS
 *  nIndex      [IN]        
 *  RETURNS           void(?)
 *****************************************************************************/
void csb_frm_set_current_view_mode(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch ((U16) nIndex)
    {
        case VIEW_MODE_MANUAL:
            g_csb_highlighted_item = VIEW_MODE_MANUAL;
            break;
        case VIEW_MODE_AUTO:
            g_csb_highlighted_item = VIEW_MODE_AUTO;
            break;
        default:
            ASSERT(0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  EntryCSBOptionsAutoModeTime
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBOptionsAutoModeTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            GRP_ID_CSB_ROOT,
            SCR_ID_CSB_OPTIONS_AUTO_MODE_TIME_SCR_ID, 
            NULL /* TODO */ , 
            EntryCSBOptionsAutoModeTime, 
            MMI_FRM_FULL_SCRN))
    {

        guiBuffer = mmi_frm_scrn_get_active_gui_buf();

        /* Convert the timer value from milli seconds to seconds before passing to category */
        g_csb_timer = g_CSB_struct.csb_settings.timer_value / 1000;

        ShowCategory87Screen(
            STR_ID_CSB_AUTO_MODE_TIME_TEXT,
            0,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            MIN_CSB_AUTO_MODE_TIME,
            MAX_CSB_AUTO_MODE_TIME,
            &g_csb_timer,
            guiBuffer);

        SetLeftSoftkeyFunction(csb_frm_save_auto_mode_time, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryCSBOptionsManualMode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBOptionsManualMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[MAUNAL_MODE_TOTAL];
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            GRP_ID_CSB_ROOT,
            SCR_ID_CSB_OPTIONS_MANUAL_MODE_SCR_ID, \
            NULL, 
            EntryCSBOptionsManualMode, 
            MMI_FRM_FULL_SCRN))
    {
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();

        nItems = GetNumOfChild(CSB_OPTIONS_SETTING_MANUAL_MODE_MENUID);
        GetSequenceStringIds(CSB_OPTIONS_SETTING_MANUAL_MODE_MENUID, ItemList);
        SetParentHandler(CSB_OPTIONS_SETTING_MANUAL_MODE_MENUID);
        RegisterHighlightHandler(csb_frm_set_current_manual_mode);

        ShowCategory11Screen(
            STR_ID_CSB_MANUAL_MODE_TEXT,
            0,
            STR_GLOBAL_OK,
            0,
            STR_GLOBAL_BACK,
            0,
            nItems,
            ItemList,
            g_CSB_struct.csb_settings.manual_mode,
            guiBuffer);

        SetLeftSoftkeyFunction(csb_frm_save_manual_mode, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  csb_frm_set_current_manual_mode
 * DESCRIPTION
 *  Set the current manual mode
 * PARAMETERS
 *  nIndex      [IN]        
 *  RETURNS           void(?)
 *****************************************************************************/
void csb_frm_set_current_manual_mode(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch ((U16) nIndex)
    {
        case MANUAL_MODE_INTERACTIVE:
            g_csb_highlighted_item = MANUAL_MODE_INTERACTIVE;
            break;
        case MANUAL_MODE_NONINTERACTIVE:
            g_csb_highlighted_item = MANUAL_MODE_NONINTERACTIVE;
            break;
        default:
            ASSERT(0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  EntryCSBSearchByControl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBSearchByControl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[CSB_TOTAL_CONTROLS];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[CSB_TOTAL_CONTROLS];
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            GRP_ID_CSB_ROOT,
            SCR_ID_CSB_SEARCH_BY_CONT_SCR_ID, 
            NULL, 
            EntryCSBSearchByControl, 
            MMI_FRM_FULL_SCRN))
    {
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();

        nItems = GetNumOfChild(CSB_SEARCH_CONTROL_MENUID);
        GetSequenceStringIds(CSB_SEARCH_CONTROL_MENUID, ItemList);
        SetParentHandler(CSB_SEARCH_CONTROL_MENUID);
        RegisterHighlightHandler(csb_frm_set_current_control_name);

        csb_frm_set_search_mode(SEARCH_BY_CONTROL);

        for (index = 0; index < nItems; index++)
        {
            /* This call creates the hint data for each menu item in coming screen */
            csb_frm_prepare_hint_data((U16) index);

            /* ASSERT if the above API returns NULL in hintData */
            ASSERT(hintData[index] != NULL);
            PopUpList[index] = hintData[index];
        }

        ShowCategory55Screen(
            STR_ID_CSB_SEARCH_CONTROL_TEXT,
            0,
            STR_GLOBAL_OK,
            0,
            STR_GLOBAL_BACK,
            0,
            nItems,
            ItemList,
            (U8 **) PopUpList,
            0,
            guiBuffer);

        SetLeftSoftkeyFunction(pre_entry_csb_prepare_cat_scr_list, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  csb_frm_set_current_control_name
 * DESCRIPTION
 *  Set the current control flag
 * PARAMETERS
 *  nIndex      [IN]        
 *  RETURNS           void(?)
 *****************************************************************************/
void csb_frm_set_current_control_name(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Store the currently highlighted item to show caption on next screen */
    g_CSB_struct.caption_str_id = (U16)nIndex;
    /* switch case to set the current control flag */
    switch ((U16) nIndex)
    {
        case CSB_CONT_CALL_SCR:
            g_CSB_struct.current_flag = CSB_CALL_SCR;
            break;
        case CSB_CONT_COLOR_PICKER_SCR:
            g_CSB_struct.current_flag = CSB_COLOR_PICKER_SCR;
            break;
        case CSB_CONT_EDITOR_SCR:
            g_CSB_struct.current_flag = CSB_EDITOR_SCR;
            break;
        case CSB_CONT_IDLE_SCR:
            g_CSB_struct.current_flag = CSB_IDLE_SCR;
            break;
        case CSB_CONT_IMAGE_VIEWER_SCR:
            g_CSB_struct.current_flag = CSB_IMAGE_VIEWER_SCR;
            break;
        case CSB_CONT_LIST_MENU_SCR:
            g_CSB_struct.current_flag = CSB_LIST_MENU_SCR;
            break;
        case CSB_CONT_MATRIX_MENU_SCR:
            g_CSB_struct.current_flag = CSB_MATRIX_MENU_SCR;
            break;
        case CSB_CONT_POPUP_SCR:
            g_CSB_struct.current_flag = CSB_POPUP_SCR;
            break;
        case CSB_CONT_PROGRESS_BAR_SCR:
            g_CSB_struct.current_flag = CSB_PROGRESS_BAR_SCR;
            break;
        case CSB_CONT_SLIDER_SCR:
            g_CSB_struct.current_flag = CSB_SLIDER_SCR;
            break;
        case CSB_CONT_RADIO_BUTTON_SCR:
            g_CSB_struct.current_flag = CSB_RADIO_BUTTON_SCR;
            break;
        case CSB_CONT_CHECK_BOX_SCR:
            g_CSB_struct.current_flag = CSB_CHECK_BOX_SCR;
            break;
        case CSB_CONT_SUB_LCD:
            g_CSB_struct.current_flag = CSB_SUB_LCD;
            break;
        case CSB_CONT_PANEL:
            g_CSB_struct.current_flag = CSB_PANEL;
            break;
        default:
            ASSERT(0);

    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryCSBSearchByApp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBSearchByApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[CSB_TOTAL_APP];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[CSB_TOTAL_APP];
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            GRP_ID_CSB_ROOT,
            SCR_ID_CSB_SEARCH_BY_APP_SCR_ID, 
            NULL, 
            EntryCSBSearchByApp, 
            MMI_FRM_FULL_SCRN))
    {
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();

        nItems = GetNumOfChild(CSB_SEARCH_APP_MENUID);
        GetSequenceStringIds(CSB_SEARCH_APP_MENUID, ItemList);
        SetParentHandler(CSB_SEARCH_APP_MENUID);
        RegisterHighlightHandler(csb_frm_set_current_app_name);

        csb_frm_set_search_mode(SEARCH_BY_APP);

        for (index = 0; index < nItems; index++)
        {
            /* This call creates the hint data for each menu item in coming screen */
            csb_frm_prepare_hint_data((U16) index);

            /* ASSERT if the above API returns NULL in hintData */
            ASSERT(hintData[index] != NULL);
            PopUpList[index] = hintData[index];
        }

        ShowCategory55Screen(
            STR_ID_CSB_SEARCH_APP_TEXT,
            0,
            STR_GLOBAL_OK,
            0,
            STR_GLOBAL_BACK,
            0,
            nItems,
            ItemList,
            (U8 **) PopUpList,
            0,
            guiBuffer);

        SetLeftSoftkeyFunction(pre_entry_csb_prepare_cat_scr_list, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  csb_frm_set_current_app_name
 * DESCRIPTION
 *  Set the current application flag
 * PARAMETERS
 *  nIndex      [IN]        
 *  RETURNS           void(?)
 *****************************************************************************/
void csb_frm_set_current_app_name(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Store the currently highlighted item to show caption on next screen */
    g_CSB_struct.caption_str_id = (U16)nIndex;

    /* switch case to select the current application flag */
    switch ((U16) nIndex)
    {
        case CSB_APP_CALLS:
            g_CSB_struct.current_flag = CSB_CALLS;
            break;
        case CSB_APP_EDITOR:
            g_CSB_struct.current_flag = CSB_EDITOR;
            break;
        case CSB_APP_ENGG_MODE:
            g_CSB_struct.current_flag = CSB_ENGG_MODE;
            break;
        case CSB_APP_EXTRA:
            g_CSB_struct.current_flag = CSB_EXTRA;
            break;
        case CSB_APP_FUN_AND_GAMES:
            g_CSB_struct.current_flag = CSB_FUN_AND_GAMES;
            break;
        case CSB_APP_FILE_MANAGER:
            g_CSB_struct.current_flag = CSB_FILE_MANAGER;
            break;
        case CSB_APP_MESSAGES:
            g_CSB_struct.current_flag = CSB_MESSAGES;
            break;
        case CSB_APP_MISC:
            g_CSB_struct.current_flag = CSB_MISC;
            break;
        case CSB_APP_MULTIMEDIA:
            g_CSB_struct.current_flag = CSB_MULTIMEDIA;
            break;
        case CSB_APP_ORGANIZER:
            g_CSB_struct.current_flag = CSB_ORGANIZER;
            break;
        case CSB_APP_PHONEBOOK:
            g_CSB_struct.current_flag = CSB_PHONEBOOK;
            break;
        case CSB_APP_PROFILE:
            g_CSB_struct.current_flag = CSB_PROFILE;
            break;
        case CSB_APP_SERVICES:
            g_CSB_struct.current_flag = CSB_SERVICES;
            break;
        case CSB_APP_SHORTCUT:
            g_CSB_struct.current_flag = CSB_SHORTCUT;
            break;
        case CSB_APP_SETTINGS:
            g_CSB_struct.current_flag = CSB_SETTINGS;
            break;
        case CSB_APP_WAP:
            g_CSB_struct.current_flag = CSB_WAP;
            break;
        case CSB_APP_HID:
            g_CSB_struct.current_flag = CSB_HID;
            break;
        default:
            ASSERT(0);

    }
}


/*****************************************************************************
 * FUNCTION
 *  entry_csb_cat_scr_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_csb_cat_scr_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList_app[CSB_TOTAL_APP];
    U16 ItemList_control[CSB_TOTAL_CONTROLS];
    U8 *guiBuffer = NULL;
    S32 hiliteitem = 0;
    S32 nitem = 0;
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            GRP_ID_CSB_ROOT,
            SCR_ID_CSB_SEARCH_LIST_SCR_ID, 
            NULL, 
            entry_csb_cat_scr_list, 
            MMI_FRM_FULL_SCRN))
    {
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();
        RegisterHighlightHandler(csb_frm_set_current_screen_index);

        nitem = g_CSB_struct.number_of_screens;
        /* If the number of screens found is ZERO, so pop-up and return back */
        if (!nitem)
        {
            mmi_popup_display_simple((WCHAR*)((UI_string_type)GetString(STR_ID_CSB_NO_SCR_FOUND_TEXT)), MMI_EVENT_ERROR, GRP_ID_CSB_ROOT, NULL);
            mmi_frm_scrn_close(GRP_ID_CSB_ROOT, SCR_ID_CSB_SEARCH_LIST_SCR_ID);
            return;
        }

        /* Get the string list of the previous menu, so that we can get the Caption string according to the
           previous menu selected */
        if (SEARCH_MODE_APP == csb_frm_get_search_mode())
        {
            GetSequenceStringIds(CSB_SEARCH_APP_MENUID, ItemList_app);
            str_id = ItemList_app[g_CSB_struct.caption_str_id];
        }
        else if (SEARCH_MODE_CONTROL == csb_frm_get_search_mode())
        {
            GetSequenceStringIds(CSB_SEARCH_CONTROL_MENUID, ItemList_control);
            str_id = ItemList_control[g_CSB_struct.caption_str_id];
        }

        ShowCategory184Screen(
            str_id,
            0,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nitem,
            csb_cat_scr_list_get_item,
            0,
            hiliteitem,
            guiBuffer);

        SetLeftSoftkeyFunction(entry_csb_show_cat_scr, KEY_EVENT_UP);
        SetKeyHandler(entry_csb_show_cat_scr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  csb_frm_set_current_screen_index
 * DESCRIPTION
 *  Set current highlighted screen index
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void csb_frm_set_current_screen_index(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_CSB_struct.current_index = csb_category_screen_list[nIndex].screen_index;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCSBSearchByScrID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBSearchByScrID(void)
{
    mmi_id fseditor_gid;

    if ((fseditor_gid = cui_fseditor_create(GRP_ID_CSB_ROOT)) != 0)
    {
        csb_frm_set_search_mode(SEARCH_BY_SCREENID);
        cui_fseditor_set_title(fseditor_gid, STR_ID_CSB_SEARCH_SCREENID_TEXT, 0);
        cui_fseditor_set_text(fseditor_gid, (WCHAR*)csb_buffer, MAX_CSB_SCREEN_NAME_LENGTH, MAX_CSB_SCREEN_NAME_LENGTH);
        cui_fseditor_set_input_method(fseditor_gid, IMM_INPUT_TYPE_NUMERIC, NULL, 0);
        cui_fseditor_set_parent_data(fseditor_gid, SCR_ID_CSB_SEARCH_BY_SCRID_SCR_ID);
        cui_fseditor_run(fseditor_gid);       
    }
 
}

/*****************************************************************************
 * FUNCTION
 *  PreEntryCSBTestToolRun
 * DESCRIPTION
 *  Function to Run the test tool
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PreEntryCSBTestToolRun(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U64 disk_free_space = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_PATH_NOT_FOUND == FS_GetFolderSize((PU16) g_CSB_struct.csb_settings.csb_screenshots_folder_path, FS_COUNT_IN_BYTE, NULL, 0))
    {
        /* If the set path is invalid */
        
        mmi_popup_display_simple((WCHAR*)((UI_string_type)GetString(STR_GLOBAL_ERROR)), MMI_EVENT_ERROR, GRP_ID_CSB_ROOT, NULL);
        return;
    }

    if (*(g_CSB_struct.csb_settings.csb_screenshots_folder_path) == SRV_FMGR_CARD_DRV)
    {
        /* Check is memory card is present or not */
        if (srv_fmgr_drv_has_accessible_removable_drv())
        {
            if (csb_frm_check_disk_free_space(&disk_free_space))
            {
                EntryCSBTestToolRun();
            }
            else
            {
                /* If the disk space is less that required */
                csb_show_current_memory_status(&disk_free_space);
                
                mmi_frm_scrn_multiple_close(GRP_ID_CSB_ROOT, mmi_frm_scrn_get_active_id(),0,0, SCR_ID_CSB_TESTTOOL_SCR_ID,0);
                return;
            }
        }
        else
        {
            /* Once all the category screenshots are taken, show the DONE pop-up */
            
            mmi_popup_display_simple((WCHAR*)((UI_string_type)GetString(STR_ID_CSB_NO_MEMORY_CARD)), MMI_EVENT_ERROR, GRP_ID_CSB_ROOT, NULL);
            
            mmi_frm_scrn_multiple_close(GRP_ID_CSB_ROOT, mmi_frm_scrn_get_active_id(),0,0, SCR_ID_CSB_TESTTOOL_SCR_ID,0);
            return;
        }
    }
    else
    {
        if (csb_frm_check_disk_free_space(&disk_free_space))
        {
            EntryCSBTestToolRun();
        }
        else
        {
            /* If the disk space is less that required */
            csb_show_current_memory_status(&disk_free_space);
            
            mmi_frm_scrn_multiple_close(GRP_ID_CSB_ROOT, mmi_frm_scrn_get_active_id(),0,0, SCR_ID_CSB_TESTTOOL_SCR_ID,0);
            return;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  EntryCSBTestToolRun
 * DESCRIPTION
 *  Function to Run the test tool
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBTestToolRun(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/



    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	StartTimer(CSB_AUTO_MODE_TIMER_ID, 250, csb_frm_testtool_callback);
}


/*****************************************************************************
 * FUNCTION
 *  TestToolProcessingScr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void TestToolProcessingScr(U16 str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
        GRP_ID_CSB_ROOT, SCR_ID_CSB_PROCESSING_SCR_ID, NULL, csb_frm_testtool_callback, MMI_FRM_FG_ONLY_SCRN))
    {

        ShowCategory66Screen(
            STR_ID_CSB_PROCESSING_TEXT,
            0,
            0,
            0,
            0,
            0,
            (PU8) GetString(str_id),
            IMG_GLOBAL_PROGRESS,
            guiBuffer);

        SetKeyHandler(NULL, KEY_END, KEY_EVENT_DOWN);
        SetKeyHandler(NULL, KEY_END, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryCSBTestToolSetLoc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBTestToolSetLoc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    S8 file_path_in_ascii[CSB_DRIVE_LENGTH];
    S8 file_path[CSB_DRIVE_LENGTH * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    //Open the root directory of the file mgr in order to support
    // memory card as well as phone
    sprintf((S8*) file_path_in_ascii, "%s", "root");

    mmi_asc_to_ucs2((PS8) file_path, file_path_in_ascii);

    mmi_fmgr_select_path_and_enter(
        APP_CSB,
        FMGR_SELECT_FOLDER,
        filter,
        (S8*) file_path,
        csb_frm_select_folder_callback);
}


/*****************************************************************************
 * FUNCTION
 *  EntryCSBTestToolViewImages
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBTestToolViewImages(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    S8 file_path_in_unicode[MAX_CSB_PATH_LENGTH * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPG);

    mmi_ucs2cpy(file_path_in_unicode, (S8*) g_CSB_struct.csb_settings.csb_screenshots_folder_path);

    {
        mmi_fmgr_browse_setting_struct setting;
        mmi_fmgr_browse_init_setting(&setting);
        setting.display_type = FMGR_DISPLAY_TYPE_ICON_LIST;
        // TODO: double check the behavior.
        setting.quit_callback = mmi_csb_exit_from_fmgr_empty_folder;

        mmi_fmgr_browse_path(
            APP_CSB,
            0,
            filter,
            (S8*)file_path_in_unicode,
            &setting);
    }
}


/*****************************************************************************
 * FUNCTION
 *  csb_show_current_screen_ID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void csb_show_current_screen_ID(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 local_buffer_ansii[10];
    U8 screen_ID[40];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    {
        /* If the view mode is AUTO, STOP the timer till OK pressed */
        if (VIEW_MODE_AUTO == g_CSB_struct.csb_settings.view_mode)
        {
            StopTimer(CSB_AUTO_MODE_TIMER_ID);
        }

        /* NULLS the memory */
        memset(screen_ID, CSB_NULL, 40);

        /* Copy the string in the final buffer */
        mmi_asc_to_ucs2((PS8) screen_ID, (PS8) "Screen ID = ");

        /* Decrement the index of the database, as it is already incremented by 1 */
        if (g_CSB_struct.screen_counter)
            --g_CSB_struct.screen_counter;

        /* If the category ID is ZERO, append the category name */
        if (g_CSB_struct.pscreen_info[g_CSB_struct.screen_counter].cat_ID == 0)
        {
            mmi_ucs2cat((PS8) screen_ID, (PS8) g_CSB_struct.pscreen_info[g_CSB_struct.screen_counter].cat_scr_name);
        }
        /* If the category has ID, append the category ID */
        else
        {
            gui_itoa(
                (S32) g_CSB_struct.pscreen_info[g_CSB_struct.screen_counter].cat_ID,
                (UI_string_type) local_buffer_ansii,
                10);
            mmi_ucs2cat((PS8) screen_ID, (PS8) local_buffer_ansii);
        }

        /* Display the screen id in the pop up */
        
        mmi_popup_display_simple((WCHAR*)((UI_string_type)screen_ID), MMI_EVENT_INFO, GRP_ID_CSB_ROOT, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  csb_show_current_memory_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pdisk_free_space        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void csb_show_current_memory_status(U64 *pdisk_free_space)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *guiBuffer = NULL;
    U8 Mem_Error[90];
    S32 space_required;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            GRP_ID_CSB_ROOT,
            SCR_ID_CSB_MEM_ERROR_SCR_ID, 
            ExitScreen_Generic, 
            EntryCSBStartView, 
            MMI_FRM_FULL_SCRN))
    {
        /* NULLS the memory */
        memset(Mem_Error, CSB_NULL, 90);
        memset(g_buffer, 0, MAX_LOCAL_BUFFER);
        memset(g_buffer1, 0, MAX_LOCAL_BUFFER_1);

        space_required = TOTAL_CATEGORY_SCREENS * 11 * 1024;

        mmi_asc_to_ucs2((PS8) Mem_Error, (PS8) "Mem Error!!\n");
        mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Req:= ");

        /* Copy the string in the final buffer */
        mmi_ucs2cat((PS8) Mem_Error, (PS8) g_buffer);

        gui_itoa((S32) space_required, (UI_string_type) g_buffer1, 10);

        mmi_ucs2cat((PS8) Mem_Error, (PS8) g_buffer1);

        mmi_ucs2cat((PS8) Mem_Error, (PS8) "\n");

        mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Avl:= ");

        mmi_ucs2cat((PS8) Mem_Error, (PS8) g_buffer);

        gui_itoa((S32) * pdisk_free_space, (UI_string_type) g_buffer1, 10);

        mmi_ucs2cat((PS8) Mem_Error, (PS8) g_buffer1);

        ShowCategory151Screen(
            STR_ID_CSB_CATEGORY_TEXT,
            0,
            STR_ID_CSB_LSK_TEXT,
            0,
            STR_ID_CSB_RSK_TEXT,
            0,
            (PU8) Mem_Error,
            NULL,
            guiBuffer);

        ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
        ChangeRightSoftkey(0, 0);
        SetLeftSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
}

#endif /* __MMI_CSB_BROWSER__ */ 


