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
 *  vadp_v2p_hs_widget_dualclock.c
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions of dual clock widget from Venus MMI to PlutoMMI.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/**********************************************************************
 * Include
 **********************************************************************/
#include "MMI_features.h"

#if defined(__MMI_VUI_HOMESCREEN_CLOCK__) || defined(__MMI_VUI_HOMESCREEN_DUALCLOCK__)

/* Pluto headers: */
#include "CommonScreens.h"
#include "PhoneSetup.h"
#include "Worldclock.h"
#ifdef __MMI_SCREEN_SWITCH_EFFECT__    
#include "gui_effect_oem.h"
#endif 

/* Venus headers: */
#include "vadp_v2p_hs_widget_dualclock.h"

#include "nvram_common_defs.h"

#include "WorldClockCuiGprot.h"
#include "custom_mmi_default_value.h"
#include "MMIDataType.h"
#include "common_nvram_editor_data_item.h"
#include "mmi_frm_nvram_gprot.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "vfx_datatype.h"
#include "app_datetime.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_rp_app_venus_homescreen_wg_clock_def.h"
#include "mmi_frm_mem_gprot.h"
#include "wgui_inline_edit.h"
#include "mmi_frm_history_gprot.h"
#include "CustDataRes.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "wgui_categories_list.h"
#include "commonscreensresdef.h"
/**********************************************************************
 * Extern function
 **********************************************************************/

extern void mmi_wc_get_foreign_city_info(MYTIME *foreign_time, PU8 *city_name);
#ifdef __MMI_DUAL_CLOCK__
extern void PhnsetSetForeignCity(void);
#endif
/**********************************************************************
 * Define
 **********************************************************************/


/**********************************************************************
 * Global variables
 **********************************************************************/
static vadp_v2p_hs_clock_struct g_vadp_v2p_hs_widget_clock;
static vadp_v2p_hs_clock_setting_struct* vadp_v2p_hs_clock = NULL;


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_clock_save_nvram
 * DESCRIPTION
 *  save buffer data to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_clock_save_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(
        NVRAM_EF_VENUS_HS_WIDGET_CLOCK_CNTX_LID,
        1,
        &g_vadp_v2p_hs_widget_clock,
        NVRAM_EF_VENUS_HS_WIDGET_CLOCK_CNTX_SIZE,
        &error);
    MMI_ASSERT(error == NVRAM_WRITE_SUCCESS);

}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_clock_read_nvram
 * DESCRIPTION
 *  read data to buffer from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_clock_read_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_VENUS_HS_WIDGET_CLOCK_CNTX_LID, 
        1, 
        &g_vadp_v2p_hs_widget_clock, 
        NVRAM_EF_VENUS_HS_WIDGET_CLOCK_CNTX_SIZE, 
        &error);
    MMI_ASSERT(error == NVRAM_READ_SUCCESS);

}

U32 vadp_v2p_hs_clock_get_type(void)
{
    return g_vadp_v2p_hs_widget_clock.type;
}

U32 vadp_v2p_hs_clock_get_style(void)
{
    return g_vadp_v2p_hs_widget_clock.style;
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_dualclock_get_name
 * DESCRIPTION
 *  get foreign city name for dual clock widget
 * PARAMETERS
 *  void
 * RETURNS
 *  VfxWChar*
 *****************************************************************************/
VfxWChar* vadp_v2p_hs_dualclock_get_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct foreign_time = {0};
    PU8 city_name = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VUI_HOMESCREEN_CLOCK__) || defined(__MMI_VUI_HOMESCREEN_DUALCLOCK__)
    mmi_wc_get_foreign_city_info((MYTIME *)&foreign_time, &city_name);
#endif /* defined(__MMI_VUI_HOMESCREEN_CLOCK__) || defined(__MMI_VUI_HOMESCREEN_DUALCLOCK__) */

    return (VfxWChar*)city_name;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_dualclock_get_name
 * DESCRIPTION
 *  get foreign city name for dual clock widget
 * PARAMETERS
 *  void
 * RETURNS
 *  VfxWChar*
 *****************************************************************************/
VfxWChar* vadp_v2p_hs_dualclock_get_home_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VUI_HOMESCREEN_CLOCK__) || defined(__MMI_VUI_HOMESCREEN_DUALCLOCK__)
    return (VfxWChar*)mmi_wc_get_home_city();
#endif /* defined(__MMI_VUI_HOMESCREEN_CLOCK__) || defined(__MMI_VUI_HOMESCREEN_DUALCLOCK__) */
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_dualclock_get_time
 * DESCRIPTION
 *  get foreign city time for dual clock widget
 * PARAMETERS
 *  hour            : [OUT] hours
 *  mins            : [OUT] minutes
 *  secs            : [OUT] seconds
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_dualclock_get_time(VfxU32 *hour, VfxU32 *mins, VfxU32 *secs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct foreign_time = {0};
    PU8 city_name = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VUI_HOMESCREEN_CLOCK__) || defined(__MMI_VUI_HOMESCREEN_DUALCLOCK__)
    mmi_wc_get_foreign_city_info((MYTIME *)&foreign_time, &city_name);
#endif /* defined(__MMI_VUI_HOMESCREEN_CLOCK__) || defined(__MMI_VUI_HOMESCREEN_DUALCLOCK__) */

    *hour = (VfxU32)foreign_time.nHour;
    *mins = (VfxU32)foreign_time.nMin;
    *secs = (VfxU32)foreign_time.nSec;
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
#ifdef __MMI_WC_TZ_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_WC_TZ_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_VUI_HOMESCREEN_CLOCK__) || defined(__MMI_VUI_HOMESCREEN_DUALCLOCK__)
/* under construction !*/
#ifndef __MMI_WC_TZ_SUPPORT__
/* under construction !*/
#else /* __MMI_WC_TZ_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_WC_TZ_SUPPORT__ */
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_VUI_HOMESCREEN_CLOCK__) || defined(__MMI_VUI_HOMESCREEN_DUALCLOCK__) */
/* under construction !*/
#endif

static mmi_ret vadp_v2p_hs_dualclock_select_city_proc(mmi_event_struct *param)
{
#if defined(__MMI_VUI_HOMESCREEN_CLOCK__) || defined(__MMI_VUI_HOMESCREEN_DUALCLOCK__)
	cui_worldclock_event_struct *wc_evt = (cui_worldclock_event_struct *)param;

	switch(wc_evt->evt_id)
	{
	case CUI_WC_SELECT_EVENT_OK:

#ifdef __MMI_DUAL_CLOCK__
		PhnsetSetForeignCity();
                mmi_frm_group_close(wc_evt->sender_id);
#endif /* __MMI_DUAL_CLOCK__ */

		break;
	case CUI_WC_SELECT_EVENT_CANCEL:
	case CUI_WC_SELECT_EVENT_CLOSE_REQ:
		mmi_frm_group_close(wc_evt->sender_id);
		
		break;
	default:
		break;
	}
#endif /* defined(__MMI_VUI_HOMESCREEN_CLOCK__) || defined(__MMI_VUI_HOMESCREEN_DUALCLOCK__) */

	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_dualclock_entry_setting
 * DESCRIPTION
 *  entry setting of dual clock in phone setup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_dualclock_entry_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id grp_id, sub_grp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VUI_HOMESCREEN_CLOCK__) || defined(__MMI_VUI_HOMESCREEN_DUALCLOCK__)

    g_phnset_cntx_p->city_flag = PHNSET_FOREIGN_CITY;

#if !defined(__MMI_HIDE_HOMECITY__)
    g_phnset_cntx_p->curHightlightItem = 1;
#else /* !defined(__MMI_HIDE_HOMECITY__)*/
    g_phnset_cntx_p->curHightlightItem = 0;
#endif /* !defined(__MMI_HIDE_HOMECITY__) */

#if defined(__MMI_SCREEN_SWITCH_EFFECT__) && defined(__MMI_VUI_ENGINE__)
    gui_screen_switch_effect_v2p_setup_widget();
#endif


#ifndef __MMI_WC_TZ_SUPPORT__
    EntryPhnsetSetHomeCity();
#else
	grp_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, vadp_v2p_hs_dualclock_select_city_proc,NULL);
	if (grp_id != GRP_ID_INVALID)
	{
		mmi_frm_group_enter(grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
		sub_grp = cui_worldclock_create(grp_id);
		if (grp_id != GRP_ID_INVALID)
		{
			cui_worldclock_run(sub_grp);
		}
		else
		{
			mmi_frm_group_close(grp_id);
		}
	}
	
	// comment out by wen
    //EntryWcBrowseCityEx(vadp_v2p_hs_dualclock_entry_setting, vadp_v2p_hs_dualclock_exit_setting);
#endif

#endif /* defined(__MMI_VUI_HOMESCREEN_CLOCK__) || defined(__MMI_VUI_HOMESCREEN_DUALCLOCK__) */
}


extern void vadp_v2p_hs_clock_entry_display_setting(void);


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_clock_exit_disp_setting
 * DESCRIPTION
 *  Exit function of Jump To screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vadp_v2p_hs_clock_exit_disp_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    GenericExitInlineScreen(VAPP_HS_SCR_CLOCK_DISPLAY_SETTING, vadp_v2p_hs_clock_entry_display_setting);
    
    mmi_frm_scrmem_free(vadp_v2p_hs_clock);
    vadp_v2p_hs_clock = NULL;

    vadp_v2p_hs_clock_read_nvram();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_clock_save_setting_popup_cb
 * DESCRIPTION
 *  callback function of popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret vadp_v2p_hs_clock_save_setting_popup_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    case EVT_ID_ALERT_QUIT:
        CloseCategory57Screen();

        /* go back to home screen */
        mmi_frm_scrn_close_active_id();
        mmi_frm_scrn_close_active_id();
        break;

    default:
        break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_clock_save_setting
 * DESCRIPTION
 *  save setting when press ok.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vadp_v2p_hs_clock_save_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg_popup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Save to NVRAM */
    vadp_v2p_hs_clock_save_nvram();
    
    mmi_popup_property_init(&arg_popup);
    arg_popup.callback = (mmi_proc_func)vadp_v2p_hs_clock_save_setting_popup_cb;

    mmi_popup_display((WCHAR*) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, &arg_popup);

}



/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_clock_disp_setting_highlight
 * DESCRIPTION
 *  Highlight handler of inline editor items.
 * PARAMETERS
 *  nIndex      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_clock_disp_setting_highlight(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	SetCenterSoftkeyFunction(vadp_v2p_hs_clock_save_setting, KEY_EVENT_UP);
	SetLeftSoftkeyFunction(vadp_v2p_hs_clock_save_setting, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_clock_entry_display_setting
 * DESCRIPTION
 *  enter display screen, show category57
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_clock_entry_display_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer; 
    U8 *input_buffer;
    U16 input_size;
    mmi_id group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_id = mmi_frm_group_get_active_id();
    if(mmi_frm_scrn_enter(group_id, VAPP_HS_SCR_CLOCK_DISPLAY_SETTING, vadp_v2p_hs_clock_exit_disp_setting, vadp_v2p_hs_clock_entry_display_setting, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    vadp_v2p_hs_clock = mmi_frm_scrmem_alloc(sizeof(vadp_v2p_hs_clock_setting_struct));
    ASSERT(vadp_v2p_hs_clock != NULL);
    
    InitializeCategory57Screen();
    RegisterHighlightHandler(vadp_v2p_hs_clock_disp_setting_highlight);

    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[0], (U8*)GetString(VAPP_HS_STR_CLOCK_STR_TYPE));

    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    vadp_v2p_hs_clock->type_option[0] = (U8*)get_string(VAPP_HS_STR_CLOCK_STR_TYPE_LOCAL);
    vadp_v2p_hs_clock->type_option[1] = (U8*)get_string(VAPP_HS_STR_CLOCK_STR_TYPE_ECDEMIC);
    vadp_v2p_hs_clock->type_option[2] = (U8*)get_string(VAPP_HS_STR_CLOCK_STR_TYPE_DUAL);
    SetInlineItemSelect(
        &wgui_inline_items[1],
        (S32) VADP_V2P_HS_CLOCK_TYPE_COUNT,
        (U8 **) vadp_v2p_hs_clock->type_option,
        (S32*) & g_vadp_v2p_hs_widget_clock.type);


    SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[2], (U8*)GetString(VAPP_HS_STR_CLOCK_STR_STYLE));

    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    vadp_v2p_hs_clock->style_option[0] = (U8*)get_string(VAPP_HS_STR_CLOCK_STR_STYLE_ANALOG);
    vadp_v2p_hs_clock->style_option[1] = (U8*)get_string(VAPP_HS_STR_CLOCK_STR_STYLE_ANALOG2);
    vadp_v2p_hs_clock->style_option[2] = (U8*)get_string(VAPP_HS_STR_CLOCK_STR_STYLE_DIGITAL);
    SetInlineItemSelect(
        &wgui_inline_items[3],
        (S32) VADP_V2P_HS_CLOCK_STYLE_COUNT,
        (U8 **) vadp_v2p_hs_clock->style_option,
        (S32*) & g_vadp_v2p_hs_widget_clock.style);    

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    input_buffer = (U8*)mmi_frm_scrn_get_active_input_buf();
    
    if (input_buffer != NULL)    /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, 4, input_buffer);   /* sets the data */
    }
    DisableCategory57ScreenDone();
    ShowCategory57Screen(
        VAPP_HS_STR_CLOCK_STR_DISPLAY_SETTING,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        4,
        NULL,
        wgui_inline_items,
        1,
        gui_buffer);
    
    SetLeftSoftkeyFunction(vadp_v2p_hs_clock_save_setting, KEY_EVENT_UP);
    SetCategory57RightSoftkeyFunctions(vadp_v2p_hs_clock_save_setting, mmi_frm_scrn_close_active_id);
     
}



/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_clock_setting_highlight
 * DESCRIPTION
 *  Highlight handler of inline editor items.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_clock_setting_highlight(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (nIndex == 0)
	{
		SetCenterSoftkeyFunction(vadp_v2p_hs_clock_entry_display_setting, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(vadp_v2p_hs_clock_entry_display_setting, KEY_EVENT_UP);
	}
	else
	{
		SetCenterSoftkeyFunction(vadp_v2p_hs_dualclock_entry_setting, KEY_EVENT_UP);
	    SetLeftSoftkeyFunction(vadp_v2p_hs_dualclock_entry_setting, KEY_EVENT_UP);
	}
}

static mmi_id g_hs_clock_setting_group_id;
static void vadp_v2p_hs_clock_entry_setting_screen(void);

static mmi_ret mmi_hs_clock_proc(mmi_event_struct *evt)
{
    switch(evt->evt_id)
	{
        case EVT_ID_GROUP_ACTIVE:
        case EVT_ID_GROUP_INACTIVE:
        case EVT_ID_GROUP_DEINIT:
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_clock_entry_setting
 * DESCRIPTION
 *  enter clock widget setting screen, show category52
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_clock_entry_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     g_hs_clock_setting_group_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_hs_clock_proc, NULL);
     mmi_frm_group_enter(g_hs_clock_setting_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
     vadp_v2p_hs_clock_entry_setting_screen();
}

static void vadp_v2p_hs_clock_entry_setting_screen(void)
{           
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer; 
    U16 list_of_icons[2];
    U16 list_of_items[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__) && defined(__MMI_VUI_ENGINE__)
    gui_screen_switch_effect_v2p_setup_widget();
#endif

    if(mmi_frm_scrn_enter(g_hs_clock_setting_group_id, VAPP_HS_SCR_CLOCK_SETTING, NULL, vadp_v2p_hs_clock_entry_setting_screen, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    RegisterHighlightHandler(vadp_v2p_hs_clock_setting_highlight);

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    list_of_icons[0] = IMG_GLOBAL_L1;
    list_of_icons[1] = IMG_GLOBAL_L2;    

    list_of_items[0] = VAPP_HS_STR_CLOCK_STR_DISPLAY_SETTING;
    list_of_items[1] = VAPP_HS_STR_CLOCK_STR_SET_WC;
    
    ShowCategory52Screen(
        VAPP_HS_STR_CLOCK_STR_SETTING,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2,
        list_of_items,
        list_of_icons,
        NULL,
        0,
        0,
        gui_buffer);
    
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}



#endif /* __MMI_VUI_HOMESCREEN_CLOCK__ */

