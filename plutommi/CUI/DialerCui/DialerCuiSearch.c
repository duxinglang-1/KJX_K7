/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  DialerCuiSearch.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the dialer search common UI.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_DIALER_SEARCH__)

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "PhoneBookGprot.h"
#include "UcmSrvGprot.h"
#include "UcmGprot.h"
#include "SearchWebGprot.h"

#ifdef __MMI_FTE_SUPPORT__
#include "mmi_rp_app_calllog_def.h"
#include "SimCtrlSrvGprot.h"
#if defined(__MMI_DUAL_SIM_MASTER__)
#include "NwUsabSrvGprot.h"
#endif
#include "UcAppGProt.h"
#include "PhoneBookSpeedDial.h"
#endif /* __MMI_FTE_SUPPORT__ */

#include "ModeSwitchSrvGprot.h"
#include "mmi_rp_app_phonebook_def.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "DialerCuiGprot.h"
#include "mmi_rp_cui_dialer_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "AlertScreen.h"
#include "DialerCuiObject.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "CommonScreensResDef.h"
#include "DialerCuiFactory.h"
#include "DialerCuiMain.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "wgui_categories_list.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "wgui_categories_idlescreen_op.h"
#include "DialerCuiCommon.h"
#include "DialerCuiSearch.h"
#include "gui_data_types.h"
#include "wgui_touch_screen.h"
#include "Unicodexdcl.h"
#include "mms_api.h"
#include "ImeGprot.h"
#include "mmi_frm_input_gprot.h"
#include "gui_typedef.h"
#include "wgui_inputs.h"
#include "custom_phb_config.h"
#include "wgui_categories.h"
#include "mmi_rp_srv_phb_def.h"

#include "ProfilesSrvGprot.h"
#include "Resource_audio.h"
#include "SmsSrvGprot.h"
/****************************************************************************
 * Global Context
 ****************************************************************************/

typedef struct
{
    U8 index;
    MMI_BOOL is_enable;
} cui_dialer_search_cntx_struct;

static cui_dialer_search_cntx_struct g_cui_dialer_search_cntx;


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_search_read_setting
 * DESCRIPTION
 *  This function reads the dialer search setting from NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void cui_dialer_search_read_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_search_cntx_struct *cntx = &g_cui_dialer_search_cntx;
    U8 setting;
    S16 err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_IDLE_DIALER_SEARCH_SETTING, &setting, DS_BYTE, &err);

    if (err != NVRAM_READ_SUCCESS)
    {
        cntx->is_enable = MMI_TRUE; /* default: on */
    }
    else
    {
        cntx->is_enable = (setting ? MMI_TRUE : MMI_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_search_save_setting
 * DESCRIPTION
 *  This function saves the dialer search setting to NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_search_save_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 setting;
    S16 err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting = (cui_dialer_search_is_enable() ? 0x01 : 0x00);

    WriteValue(NVRAM_IDLE_DIALER_SEARCH_SETTING, &setting, DS_BYTE, &err);
}


/* For the detail information, please refer to the DialerCuiGprot.h */
MMI_BOOL cui_dialer_search_is_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_search_cntx_struct *cntx = &g_cui_dialer_search_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cntx->is_enable;
}


/* For the detail information, please refer to the DialerCuiGprot.h */
void cui_dialer_search_set_enable(MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_search_cntx_struct *cntx = &g_cui_dialer_search_cntx;
    MMI_BOOL is_modified = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->is_enable && !enable)
    {
        cntx->is_enable = MMI_FALSE;    /* turn off */
    }
    else if (!cntx->is_enable && enable)
    {
        cntx->is_enable = MMI_TRUE;     /* turn on */
    }
    else
    {
        is_modified = MMI_FALSE;
    }

    /* Only write NVRAM when the setting is changed. */
    if (is_modified)
    {
        cui_dialer_search_save_setting();
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_search_close_setting
 * DESCRIPTION
 *  This function completes the setting of the dialer search.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_search_close_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(GRP_ID_CUI_DIALER_SEARCH_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_search_change_setting
 * DESCRIPTION
 *  This function toggles the dialer search setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_search_change_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_search_cntx_struct *cntx = &g_cui_dialer_search_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	cntx->is_enable = (cntx->is_enable)? MMI_FALSE: MMI_TRUE;

    cui_dialer_search_save_setting();
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_search_confirm_setting_evt_hdlr
 * DESCRIPTION
 *  This function handles the event of the dialer search setting confirm screen.
 * PARAMETERS
 *  event               : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret cui_dialer_search_confirm_setting_evt_hdlr(
    mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt = (mmi_alert_result_evt_struct *)event;
    cui_dialer_obj_struct *obj;
    cui_dialer_type_enum new_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((evt->evt_id == EVT_ID_ALERT_QUIT) &&
        (evt->result == MMI_ALERT_CNFM_YES || evt->result == MMI_ALERT_CNFM_NO))
    {
        /* For "Yes", change the setting in NVRAM. */
        if (evt->result == MMI_ALERT_CNFM_YES)
        {
            cui_dialer_search_change_setting();
        }

        /* No matter the user presses "Yes" or "No", close the setting. */
        cui_dialer_search_close_setting();

        /* If dialer is present, e.g. the user changes setting from the dialer's
           option menu, we post event to change the dialer if needed. */
        obj = cui_dialer_get_obj_in_active_serial();
        if (obj)
        {
            if (evt->result == MMI_ALERT_CNFM_YES)
            {
				new_type = (obj->type == CUI_DIALER_TYPE_SEARCH)? CUI_DIALER_TYPE_CLASSIC: CUI_DIALER_TYPE_SEARCH;
                cui_dialer_emit_change_type(obj, new_type);
            }
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_search_confirm_setting
 * DESCRIPTION
 *  This function confirms the change of the dialer search setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_search_confirm_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_search_cntx_struct *cntx = &g_cui_dialer_search_cntx;
    mmi_confirm_property_struct arg;
    U16 str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->index == 0)   /* 0: on */
    {
        str_id = STR_ID_CUI_DIALER_SEARCH_ON;
    }
    else                    /* 1: off */
    {
        str_id = STR_ID_CUI_DIALER_SEARCH_OFF;
    }

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);

    arg.parent_id = GRP_ID_CUI_DIALER_SEARCH_SETTING;
    arg.callback = cui_dialer_search_confirm_setting_evt_hdlr;

    mmi_confirm_display((WCHAR *)get_string(str_id), MMI_EVENT_QUERY, &arg);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_search_setting_hilight_hdlr
 * DESCRIPTION
 *  This function is the highlight handler of the toggle dialer search screen.
 * PARAMETERS
 *  index           [IN]        The highlighted menu item index
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_search_setting_hilight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_search_cntx_struct *cntx = &g_cui_dialer_search_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->index = (U8)index;

    /* If setting is not changed, LSK will abort the setting and go back to the
       dialer. Otherwise, LSK will confirm the user's action. (0: on, 1: off) */
    if ((index == 0 && cui_dialer_search_is_enable()) ||
        (index == 1 && !cui_dialer_search_is_enable()))
    {
        SetLeftSoftkeyFunction(cui_dialer_search_close_setting, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(cui_dialer_search_close_setting, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(cui_dialer_search_confirm_setting, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(cui_dialer_search_confirm_setting, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_search_setting_enter
 * DESCRIPTION
 *  This function is the enter function of the setting screen.
 * PARAMETERS
 *  param           : [IN]          Screen parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_search_setting_enter(mmi_scrn_essential_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            param->group_id,
            param->scrn_id,
            NULL,
            (FuncPtr)cui_dialer_search_setting_enter,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    subMenuDataPtrs[0] = (PU8)GetString(STR_GLOBAL_ON);
    subMenuDataPtrs[1] = (PU8)GetString(STR_GLOBAL_OFF);
    index = cui_dialer_search_is_enable() ? 0 : 1;

    gui_buffer = mmi_frm_scrn_get_gui_buf(param->group_id, param->scrn_id);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    SetParentHandler(0);
    RegisterHighlightHandler(cui_dialer_search_setting_hilight_hdlr);

    ShowCategory36Screen(
        STR_ID_CUI_DIALER_SEARCH,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2,                      /* on and off */
        (PU8 *)subMenuDataPtrs,
        index,                  /* 0: on, 1: off */
        gui_buffer);

    SetRightSoftkeyFunction(cui_dialer_search_close_setting, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_search_entry_setting
 * DESCRIPTION
 *  This function entries the setting of the dialer search.
 * PARAMETERS
 *  group_id     [IN]    parent group id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_search_entry_setting(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_ID this_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	this_gid = mmi_frm_group_create_ex(
                group_id,
                GRP_ID_CUI_DIALER_SEARCH_SETTING,
                mmi_dummy_proc,
					NULL, 
					MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_first_enter(
        this_gid,
        SCR_ID_CUI_DIALER_SEARCH_CONFIG,
        (FuncPtr)cui_dialer_search_setting_enter,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_search_do_send_pen_dial
 * DESCRIPTION
 *  The function is the SEND pen handler of the "Dialer Search".
 * PARAMETERS
 *  call_type        [IN]    User press SIM1 call or SIM2 call
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_search_do_send_pen_dial(srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* If the focus isn't in the editor, phone book handles the SEND key event.
       Otherwise, idle dialer handles this SEND key event. */
    if (!wgui_cat203_is_editor_active())
    {
        mmi_phb_ds_sendkey_call_pre_entry(call_type);
    }
    else
    {
        if (call_type == SRV_UCM_VOICE_CALL_TYPE)
        {
			cui_dialer_do_key_dial_by_type(CUI_DIALER_SIM1);
        }
    #ifdef __MMI_DUAL_SIM_MASTER__
        else if(call_type == SRV_UCM_VOICE_CALL_TYPE_SIM2)
        {
			cui_dialer_do_key_dial_by_type(CUI_DIALER_SIM2);
        }
    #endif

	#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
		else if(call_type == SRV_UCM_VIDEO_CALL_TYPE)
		{
			cui_dialer_do_key_dial_by_type(CUI_DIALER_VIDEO);
		}
	#endif	
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_send_key
 * DESCRIPTION
 *  The function is the SEND handler of the "Dialer Search".
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_search_do_send_key_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* If the focus isn't in the editor, phone book handles the SEND key event.
       Otherwise, idle dialer handles this SEND key event. */
    if (!wgui_cat203_is_editor_active())
    {
        mmi_phb_ds_sendkey_call_pre_entry(SRV_UCM_VOICE_CALL_TYPE_ALL);
    }
    else
    {
        cui_dialer_do_send_key_dial();
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_search_do_csk_dial
 * DESCRIPTION
 *  The function is the CSK handler of the "Dialer Search".
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_search_do_center_key_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* If the focus isn't in the editor, phone book handles the SEND key event.
       Otherwise, idle dialer handles this SEND key event. */
    if (!wgui_cat203_is_editor_active())
    {
        mmi_phb_ds_csk_call_pre_entry();
    }
    else
    {
        cui_dialer_do_center_key_dial();
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_search_entry_menu
 * DESCRIPTION
 *  This function entries the option menu of the dialer search.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_search_entry_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* If the focus isn't in the editor, phone book handles the SEND key event.
       Otherwise, idle dialer handles this SEND key event. */
    if (!wgui_cat203_is_editor_active())
    {
        mmi_phb_ds_entry_options();
    }
    else
    {
        cui_dialer_entry_menu();
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_search_get_num_of_entry
 * DESCRIPTION
 *  This function gets the number of entries.
 * PARAMETERS
 *  obj             : [IN]      Dialer CUI object
 *  history         : [IN]      History buffer pointer
 * RETURNS
 *  Number of entries.
 *****************************************************************************/
static S32 cui_dialer_search_get_num_of_entry(
    cui_dialer_search_struct *obj,
    U8 *history)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history == NULL)
    {
        mmi_phb_ds_reset_result();
        return 0;
    }
    else
    {
        return mmi_phb_ds_find_entry((UI_buffer_type)obj->dial_string);
    }
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) 
/*****************************************************************************
 * FUNCTION
 *  cui_dialer_fte_search_list_tap_callback
 * DESCRIPTION
 *  fte contact main list tap callback
 * PARAMETERS
 *  tap_type            [IN]        Tap or hilite
 *  index                 [IN]        hilite index
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_fte_search_list_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        mmi_phb_ds_fte_entry_op_view();
    }
}
#endif


#if defined(__MMI_ICON_BAR_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  cui_dialer_fte_search_list_callback
 * DESCRIPTION
 *  This function is dialer search fte callback.
 * PARAMETERS
 *  item             : [IN]      Hilite toolbar index
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_fte_search_list_callback(S32 item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cui_dialer_obj_struct *obj;
	MMI_ID group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	obj = cui_dialer_get_obj_from_group();
	group_id = mmi_frm_group_get_active_id();

    if (item == 0)
    {
        if (wgui_cat203_is_editor_active())
        {
            cui_dialer_do_center_key_dial_ex(obj);
        }
		else
		{
		    mmi_phb_ds_csk_call_pre_entry();
		}
    }

#if defined(__MMI_UNIFIED_COMPOSER__)
    else if (item == 1)
    {
    	if (wgui_cat203_is_editor_active())
    	{
    	  	mmi_phb_ds_send_message_directly(obj->dial_string, (grp_id_phb_enum)group_id);
    	}	
    	else
    	{
            mmi_phb_ds_op_fte_send_message();
        }
    }
#else
    else if (item == 1)
    {
    	if (wgui_cat203_is_editor_active())
    	{
    	  	mmi_phb_ds_send_sms_directly(obj->dial_string, (grp_id_phb_enum)group_id);
    	}	
    	else
    	{
            mmi_phb_ds_op_fte_send_sms();
        }
    }
#ifdef __MMI_MMS__
    else if (item == 2)
    {
    	if (wgui_cat203_is_editor_active())
    	{
     	    mmi_phb_ds_send_mms_directly(obj->dial_string, (grp_id_phb_enum)group_id);
    	}	
    	else
    	{
            mmi_phb_ds_op_fte_send_mms();
        }
    }
#endif /* __MMI_MMS__ */
#endif /* __MMI_UNIFIED_COMPOSER__ */
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_toolbar_update
 * DESCRIPTION
 *  fte contact main list toolbar update callback
 * PARAMETERS
 *  MMI_BOOL        [IN]      is the edit box acitve
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_toolbar_update(MMI_BOOL set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = cui_dialer_get_obj_from_group();

    if (set)
    {
        if (mmi_wcslen(obj->dial_string))
        {
            wgui_icon_bar_set_item_enable_state(0, MMI_TRUE);
            wgui_icon_bar_set_item_enable_state(1, MMI_TRUE);
#if !defined(__MMI_UNIFIED_COMPOSER__) && defined(__MMI_MMS__)           
            wgui_icon_bar_set_item_enable_state(0, MMI_TRUE);
#endif
        }
    }
    else
    {
		if (srv_sim_ctrl_any_sim_is_available())
            {
            if (srv_mode_switch_is_network_service_available() == MMI_TRUE)
            {
                wgui_icon_bar_set_item_enable_state(0, MMI_TRUE);
            }
        }
    #if defined(__MMI_UNIFIED_COMPOSER__)
        if (mmi_uc_is_uc_ready())
		{
            wgui_icon_bar_set_item_enable_state(1, MMI_TRUE);
		}
    #else /* defined(__MMI_UNIFIED_COMPOSER__) */
        if (srv_sms_is_hide_send_sms_menu_item() == FALSE)
        {
            wgui_icon_bar_set_item_enable_state(1, MMI_TRUE);
        }
    #if defined(__MMI_MMS__)
        if (mms_is_ready())
        {
            wgui_icon_bar_set_item_enable_state(2, MMI_TRUE);
        }
    #endif /* defined(__MMI_MMS__) */
    #endif /* defined(__MMI_UNIFIED_COMPOSER__) */
    }
	
    wgui_icon_bar_update();
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_fte_input_empty_hdlr
 * DESCRIPTION
 *  when input box is empty, unlight the toolbar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_fte_input_empty_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_cat203_is_editor_active())
    {
        wgui_icon_bar_set_item_enable_state(0, MMI_FALSE);
        wgui_icon_bar_set_item_enable_state(1, MMI_FALSE);
    #if !defined(__MMI_UNIFIED_COMPOSER__) && defined(__MMI_MMS__)
        wgui_icon_bar_set_item_enable_state(2, MMI_FALSE);
	#endif
        wgui_icon_bar_update();
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_fte_input_empty_hdlr
 * DESCRIPTION
 *  when input box is empty, unlight the toolbar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_fte_input_not_empty_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_cat203_is_editor_active())
    {
        wgui_icon_bar_set_item_enable_state(0, MMI_TRUE);
        wgui_icon_bar_set_item_enable_state(1, MMI_TRUE);
    #if !defined(__MMI_UNIFIED_COMPOSER__) && defined(__MMI_MMS__)
        wgui_icon_bar_set_item_enable_state(2, MMI_TRUE);
	#endif
	
        wgui_icon_bar_update();
    }
}
#endif

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)

cui_dialer_stop_virtualkey_tone()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	srv_prof_stop_tone(SRV_PROF_TONE_KEYPAD);
}


cui_dialer_play_virtualkey_tone(mmi_imc_dialer_pen_code_enum pen_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//srv_prof_ret prof_ret;
	U16 audio_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	audio_id = TONE_DTMF_0;

	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_3, "[DIALER]cui_dialer_virtual_key_player(), pen_code is %d.", pen_code); 
	
	//if(pen_code >= MMI_IMC_VK_DIALER_PEN_0 && pen_code <= MMI_IMC_VK_DIALER_PEN_9)
	if(pen_code <= MMI_IMC_VK_DIALER_PEN_9)
	{
		audio_id = TONE_DTMF_0 + (pen_code - MMI_IMC_VK_DIALER_PEN_0);
		srv_prof_play_tone_with_id(SRV_PROF_TONE_KEYPAD, audio_id, SRV_PROF_RING_TYPE_ONCE, NULL);
	}

	if(pen_code == MMI_IMC_VK_DIALER_PEN_STAR)
	{
		audio_id = TONE_KEY_STAR;
		srv_prof_play_tone_with_id(SRV_PROF_TONE_KEYPAD, audio_id, SRV_PROF_RING_TYPE_ONCE, NULL);
	}

	if(pen_code == MMI_IMC_VK_DIALER_PEN_POUND)
	{
		audio_id = TONE_KEY_HASH;
		srv_prof_play_tone_with_id(SRV_PROF_TONE_KEYPAD, audio_id, SRV_PROF_RING_TYPE_ONCE, NULL);
	}
	

}
/*****************************************************************************
 * FUNCTION
 *  cui_dialer_vk_hdlr
 * DESCRIPTION
 *  fte vk pen event handler
 * PARAMETERS
 *  pen_code        [IN]      witch char pen tap
 *  pen_event       [IN]      pen event
 * RETURNS
 *  Whether app will process the pen event; MMI_TRUE for app handle the event, MMI_FALSE for not
 *****************************************************************************/
MMI_BOOL cui_dialer_vk_hdlr(mmi_imc_dialer_pen_code_enum pen_code,mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (pen_event)
    {
		case MMI_PEN_EVENT_DOWN:
			cui_dialer_play_virtualkey_tone(pen_code);
			break;
		case MMI_PEN_EVENT_ABORT:
			cui_dialer_stop_virtualkey_tone();
			break;
        case MMI_PEN_EVENT_UP:
        {
			cui_dialer_stop_virtualkey_tone();
			
            if (pen_code == MMI_IMC_VK_DIALER_PEN_POUND)
            {
                cui_dialer_do_abbrev_dial();
                result =  MMI_TRUE;
            }
		#if  defined(__MMI_DIALER_DYNAMIC_CALL_UI__) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
			if (pen_code == MMI_IMC_VK_DIALER_NORMAL_CALL || pen_code == MMI_IMC_VK_DIALER_EMERGENCY_CALL)
			{
				cui_dialer_sim_select_hdlr();
			}
		#endif	
            if (pen_code == MMI_IMC_VK_DIALER_PEN_CALL1)
            {
                cui_dialer_search_do_send_pen_dial(SRV_UCM_VOICE_CALL_TYPE);
            }
        #ifdef __MMI_DUAL_SIM_MASTER__
            if (pen_code == MMI_IMC_VK_DIALER_PEN_CALL2)
            {
                cui_dialer_search_do_send_pen_dial(SRV_UCM_VOICE_CALL_TYPE_SIM2);
            }
        #endif
		#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
			if (pen_code == MMI_IMC_VK_DIALER_PEN_VIDEO_CALL)
			{
				cui_dialer_search_do_send_pen_dial(SRV_UCM_VIDEO_CALL_TYPE);
			}
		#endif	
		
            break;
        }
        case MMI_PEN_EVENT_LONG_TAP:
        {

            #if defined(__MMI_DUAL_SIM_MASTER__)
                if (srv_nw_usab_any_sim_is_usable())
            #else
                if (srv_sim_ctrl_is_available(MMI_SIM1))
            #endif
                {
                    if (mmi_phb_get_speed_dial_status() == MMI_TRUE)
                    {
                        if (pen_code > MMI_IMC_VK_DIALER_PEN_1 && pen_code < MMI_IMC_VK_DIALER_PEN_STAR)
                        {
                            cui_dialer_pen_speed_dial((U16)pen_code);
                        result = MMI_TRUE;
                        }
                    }
                    if (pen_code == MMI_IMC_VK_DIALER_PEN_1)
                    {
                        cui_dialer_do_voice_mail_dial();
                    result = MMI_TRUE;
                    }
                }
		
            if (pen_code == MMI_IMC_VK_DIALER_PEN_POUND)
            {
                cui_dialer_do_toggle_silent_profile();
                result = MMI_TRUE;
            }
        #if defined(__MMI_SEARCH_WEB__)
            if (pen_code == MMI_IMC_VK_DIALER_PEN_STAR &&
                mmi_search_web_hot_key_is_enabled(MMI_SEARCH_WEB_HOT_KEY_LONG_PRESS_STAR))
            {
                cui_dialer_do_baidu_search();
				result = MMI_TRUE;
            }
        #endif /* defined(__MMI_SEARCH_WEB__) */
            break;
        }
        default:
            break;
    }
	return result;
}
#endif /* __MMI_FTE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_search_enter
 * DESCRIPTION
 *  This function is the enter function of the dialer search.
 * PARAMETERS
 *  param               : [IN]              Screen parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_search_enter(mmi_scrn_essential_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
	U8 count = 0;
	gui_virtual_keyboard_pen_enum call_icon[4]={GUI_VKBD_PEN_NONE, GUI_VKBD_PEN_NONE, GUI_VKBD_PEN_NONE, GUI_VKBD_PEN_NONE};
#endif
    cui_dialer_search_struct *p;
    U8 *history;
    S32 entry_count;
#ifdef __MMI_ICON_BAR_SUPPORT__
#ifdef __MMI_UNIFIED_COMPOSER__
    S32 item_count = 2;
    PU8 item_icon[2] = {NULL, NULL};
    PU8 item_disable_icon[2] = {NULL, NULL};
    PU8 string[2] = {NULL, NULL};
#else
#ifdef __MMI_MMS__
    S32 item_count = 3;
    PU8 item_icon[3] = {NULL, NULL, NULL};
    PU8 item_disable_icon[3] = {NULL, NULL, NULL};
    PU8 string[3] = {NULL, NULL, NULL};
#else
    S32 item_count = 2;
    PU8 item_icon[2] = {NULL, NULL};
    PU8 item_disable_icon[2] = {NULL, NULL};
    PU8 string[2] = {NULL, NULL};
#endif /* __MMI_MMS__ */
#endif /* __MMI_UNIFIED_COMPOSER__ */
#endif /* __MMI_FTE_SUPPORT__ */


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            param->group_id,
            param->scrn_id,
            NULL,
            (FuncPtr)cui_dialer_search_enter,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    p = (cui_dialer_search_struct *)param->user_data;

    history = mmi_frm_scrn_get_gui_buf(param->group_id, param->scrn_id);

	if (p->dial_string_change == MMI_TRUE)
    {
        history = NULL;
        p->dial_string_change = MMI_FALSE;
    }

    entry_count = cui_dialer_search_get_num_of_entry(p, history);

#ifdef __MMI_FTE_SUPPORT__
    wgui_cat203_register_highlight_handler(mmi_phb_ds_get_index);
#else
    RegisterHighlightHandler(mmi_phb_ds_get_index);
#endif

#if defined(CUI_DIALER_SEARCH_SUPPORT_CSK)
    EnableCenterSoftkey(0, IMG_GLOBAL_CALL_CSK);
#endif

#ifdef __MMI_ICON_BAR_SUPPORT__
#if defined(__MMI_UNIFIED_COMPOSER__)
    item_icon[0] = get_image(IMG_GLOBAL_TOOLBAR_CALL);
    item_icon[1] = get_image(IMG_GLOBAL_TOOLBAR_SEND_MESSAGE);
    item_disable_icon[0] = get_image(IMG_GLOBAL_TOOLBAR_CALL_DISABLED);
    item_disable_icon[1] = get_image(IMG_GLOBAL_TOOLBAR_SEND_MESSAGE_DISABLED);
    string[0] = (PU8)get_string((STR_GLOBAL_DIAL));
    string[1] = (PU8)get_string((STR_GLOBAL_SEND_MESSAGE));
#else
    item_icon[0] = get_image(IMG_GLOBAL_TOOLBAR_CALL);
    item_icon[1] = get_image(IMG_ID_CLOG_TB_SEND_SMS);
#ifdef __MMI_MMS__
    item_icon[2] = get_image(IMG_ID_CLOG_TB_SEND_MMS);
#endif
    item_disable_icon[0] = get_image(IMG_GLOBAL_TOOLBAR_CALL_DISABLED);
    item_disable_icon[1] = get_image(IMG_ID_CLOG_TB_SEND_SMS_DISABLE);
#ifdef __MMI_MMS__
    item_disable_icon[2] = get_image(IMG_ID_CLOG_TB_SEND_MMS_DISABLE);
#endif
    string[0] = (PU8)get_string((STR_GLOBAL_DIAL));
    string[1] = (PU8)get_string((STR_GLOBAL_SEND_TEXT_MESSAGE));
#ifdef __MMI_MMS__
    string[2] = (PU8)get_string((STR_GLOBAL_SEND_MULTIMEDIA_MESSAGE));
#endif
#endif /* __MMI_UNIFIED_COMPOSER__ */
    wgui_icon_bar_setup(item_count, item_icon, item_disable_icon, string, (GUIIconbarItemCallback)cui_dialer_fte_search_list_callback);
    wgui_inputs_register_empty_func(cui_dialer_fte_input_empty_hdlr);
    wgui_inputs_register_not_empty_func(cui_dialer_fte_input_not_empty_hdlr);
#endif

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    mmi_imc_set_dialer_callback(cui_dialer_vk_hdlr);

#if (!defined(__MMI_DIALER_DYNAMIC_CALL_UI__) && !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)) 
	if (!srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE))
	{
		call_icon[count] = GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL1;
		count++;
	}
	if (!srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE_SIM2))
	{
		call_icon[count] = GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL2;
		count++;
	}
#endif	

#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
	if (!srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE_ALL))
	{	
		call_icon[count] = GUI_VKBD_PEN_ALPHANUMERIC_KEY_VIDEO_CALL;
		count++;
	}
#endif

	if(count != 0)
	{
		mmi_imm_set_events(MMI_FALSE, call_icon);
	}
	
#endif /* __MMI_FTE_SUPPORT__ && __MMI_TOUCH_SCREEN__ */

    /* Set the default RSK handler of APP on the category 203. The category 203
       will change the RSK between "Clear" and the string registered by APP. */
    wgui_cat203_set_right_softkey_function(cui_dialer_do_close, KEY_EVENT_UP);

    ShowCategory203Screen(
        get_string(STR_GLOBAL_OPTIONS),
        get_image(IMG_GLOBAL_OPTIONS),
        get_string(STR_GLOBAL_BACK),
        get_image(IMG_GLOBAL_BACK),
        get_string(STR_ID_CUI_DIALER_SEARCH_CONTACTS),
        entry_count,
        mmi_phb_ds_get_item,
        mmi_phb_ds_get_hint,
        mmi_phb_ds_get_underline,
        mmi_phb_ds_find_entry,
        (PU8)p->dial_string,
        CUI_DIALER_MAX_DIAL_STR_LEN,
        history);

    /* play DTMF tone */
    mmi_frm_set_dial_key_tone_type(MMI_DIALER_KEY_TONE_DTMF);

    /* The LSK will open the option menu on the dialer search screen. Because
       the focus might be on the edit box or the phonebook entry, this option
       menu is handled by the phonebook. */
    SetLeftSoftkeyFunction(cui_dialer_search_entry_menu, KEY_EVENT_UP);

#if defined(CUI_DIALER_SEARCH_SUPPORT_CSK)
    SetCenterSoftkeyFunction(
        cui_dialer_search_do_center_key_dial,
        KEY_EVENT_UP);
#endif /* defined(CUI_DIALER_SEARCH_SUPPORT_CSK) */

    mmi_ucm_handle_sendkeys_for_call(
        cui_dialer_search_do_send_key_dial,
        KEY_EVENT_DOWN);

    /* Input the first digit, if present. */
    cui_dialer_input_first_char((cui_dialer_obj_struct *)p);

    /* Setup the key handler. */
    cui_dialer_set_handler((cui_dialer_obj_struct *)p);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) 
    wgui_register_tap_callback(cui_dialer_fte_search_list_tap_callback);
#endif /* __MMI_FTE_SUPPORT__ */

}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_search_on_run
 * DESCRIPTION
 *  This function runs the dialer search.
 * PARAMETERS
 *  obj           : [IN]      Object
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_search_on_run(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_enter(obj->this_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_first_enter(
        obj->this_gid,
        SCR_ID_CUI_DIALER_MAIN,
        (FuncPtr)cui_dialer_search_enter,
        obj);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_search_on_want_to_run
 * DESCRIPTION
 *  This function determines if dialer search wnats to run.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL cui_dialer_search_on_want_to_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cui_dialer_search_is_enable();
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_search_on_init
 * DESCRIPTION
 *  This function initializes the dialer search object.
 * PARAMETERS
 *  obj           : [IN]        Dialer search object
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_search_on_init(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_search_struct *p;
    cui_dialer_capability_struct *capability;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Initialized by parent.
     */
    cui_dialer_obj_on_init(obj);

    /*
     * Override parent's behavior.
     */
    p = (cui_dialer_search_struct *)obj;

    p->type = CUI_DIALER_TYPE_SEARCH;
    p->on_run = cui_dialer_search_on_run;

    /*
     * Change the capabilities.
     */
    capability = &p->capability;

    capability->enable_lsk = MMI_FALSE;
    capability->enable_csk = MMI_FALSE;
    capability->enable_send = MMI_FALSE;
}
#endif /* defined(__MMI_DIALER_SEARCH__) */

