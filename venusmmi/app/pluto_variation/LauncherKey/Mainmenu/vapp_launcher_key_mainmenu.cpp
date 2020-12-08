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
 *  vapp_drawer.cpp
 *
 * Project:
 * --------
 *  Launcher
 *
 * Description:
 * ------------
 *  Launcher Key mainmenu
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_features.h"

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MMI_VUI_LAUNCHER_KEY__

#include "GlobalResDef.h"
#include "MMIDataType.h"
#include "nvram_common_defs.h"
#include "vrt_system.h"
#include "vfx_async_signal.h"
#include "vapp_launcher_key_mainmenu.h"
#include "vapp_launcher_key_mainmenu_builder.h"
#include "vapp_launcher_key_mainmenu_page_menu.h"
#include "vapp_drawer_shortcut_bar.h"   /* for cache interface */
#include "mmi_rp_vapp_key_mainmenu_def.h"
#include "vcp_page_menu_transition.h"
#include "vapp_wallpaper.h"
#include "vcp_sse.h"  // for 3D sse
#include "vapp_launcher_key_director.h" // for wallpaper pointer
#include "vapp_wallpaper_wide.h"  // for dynamic cast
#include "vapp_launcher_key_gprot.h"

extern "C" {
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "app_mem.h"
#include "CommonScreensResDef.h"
#include "AppMgrSrvGprot.h"
#include "Wgui.h" // for MMI_STATUS_BAR_HEIGHT
#include "CommonScreens.h"
#include "MenuCuiGprot.h"
#include "gui_effect_oem.h"
#include "PhoneSetupGprots.h"
#include "mmi_common_app_trc.h"
#include "MREAppMgrSrvGprot.h"
#include "FileMgrSrvGProt.h"
}

#define __VAPP_LAUNCHER_KEY_INSTANTIATE_DEFAULT_ORDER__
#include "vapp_launcher_key_mainmenu_default_order.h"
#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif 

/*****************************************************************************
 * Define
 *****************************************************************************/
#define VAPP_KMM_MAX_CNTX_MEM_SIZE (450 * 1024)  // temp define for asm

#if defined(__MMI_MAINLCD_240X320__)
static const VfxS32 VAPP_KMM_SCREEN_WIDTH = 240;
static const VfxS32 VAPP_KMM_SCREEN_HEIGHT = 320;

static const VfxS32 VAPP_KMM_CELL_ROW_COUNT = 4;
static const VfxS32 VAPP_KMM_CELL_COLUMN_COUNT = 4;

static const VfxS32 VAPP_KMM_CELL_START_X = 0;
static const VfxS32 VAPP_KMM_CELL_START_Y = 0;

static const VfxS32 VAPP_KMM_CELL_OFFSET_X = 59;
static const VfxS32 VAPP_KMM_CELL_OFFSET_Y = 67;

static const VfxS32 VAPP_KMM_PAGE_MARGIN = 15;

#elif defined(__MMI_MAINLCD_240X400__)
static const VfxS32 VAPP_KMM_SCREEN_WIDTH = 240;
static const VfxS32 VAPP_KMM_SCREEN_HEIGHT = 400;

static const VfxS32 VAPP_KMM_CELL_ROW_COUNT = 5;
static const VfxS32 VAPP_KMM_CELL_COLUMN_COUNT = 4;

static const VfxS32 VAPP_KMM_CELL_START_X = 0;
static const VfxS32 VAPP_KMM_CELL_START_Y = 0;

static const VfxS32 VAPP_KMM_CELL_OFFSET_X = 59; //60;
static const VfxS32 VAPP_KMM_CELL_OFFSET_Y = 67;

static const VfxS32 VAPP_KMM_PAGE_MARGIN = 15;

#elif defined(__MMI_MAINLCD_320X240__)
static const VfxS32 VAPP_KMM_SCREEN_WIDTH = 320;
static const VfxS32 VAPP_KMM_SCREEN_HEIGHT = 240;

static const VfxS32 VAPP_KMM_CELL_ROW_COUNT = 3;
static const VfxS32 VAPP_KMM_CELL_COLUMN_COUNT = 5;

static const VfxS32 VAPP_KMM_CELL_START_X = 0;
static const VfxS32 VAPP_KMM_CELL_START_Y = 0;

static const VfxS32 VAPP_KMM_CELL_OFFSET_X = 59;//60;
static const VfxS32 VAPP_KMM_CELL_OFFSET_Y = 67;

static const VfxS32 VAPP_KMM_PAGE_MARGIN = 15;

#else // default HVGA 320X480
static const VfxS32 VAPP_KMM_SCREEN_WIDTH = 320;
static const VfxS32 VAPP_KMM_SCREEN_HEIGHT = 480;

static const VfxS32 VAPP_KMM_CELL_ROW_COUNT = 4;
static const VfxS32 VAPP_KMM_CELL_COLUMN_COUNT = 4;

static const VfxS32 VAPP_KMM_CELL_START_X = 0;
static const VfxS32 VAPP_KMM_CELL_START_Y = 30; //40;

static const VfxS32 VAPP_KMM_CELL_OFFSET_X = 79;//80;
static const VfxS32 VAPP_KMM_CELL_OFFSET_Y = 94;

static const VfxS32 VAPP_KMM_PAGE_MARGIN = 20;

#endif

// need adjust

static const VfxS32  VAPP_KMM_POS_Y  = MMI_STATUS_BAR_HEIGHT;
static const VfxS32  VAPP_KMM_HEIGHT = VAPP_KMM_SCREEN_HEIGHT - MMI_STATUS_BAR_HEIGHT;



#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X240__)
#define  VAPP_KMM_MENU_HEIGHT (VAPP_KMM_HEIGHT)
#define  VAPP_KMM_SOFTKEY_BAR_Y (VAPP_KMM_MENU_HEIGHT- VAPP_KMM_SOFTKEY_BAR_HEIGHT)
#else
#define  VAPP_KMM_MENU_HEIGHT (VAPP_KMM_HEIGHT - VAPP_KMM_SOFTKEY_BAR_HEIGHT)
#define  VAPP_KMM_SOFTKEY_BAR_Y VAPP_KMM_MENU_HEIGHT
#endif

#if defined(__MMI_MAINLCD_240X320__)
#define VAPP_KMM_MENU_BG_X (0)
#define  VAPP_KMM_MENU_BG_HEIGHT (274)
#elif defined(__MMI_MAINLCD_240X400__)
#define VAPP_KMM_MENU_BG_X (0)
#define  VAPP_KMM_MENU_BG_HEIGHT (346)
#elif defined(__MMI_MAINLCD_320X240__)
#define VAPP_KMM_MENU_BG_X (4)
#define  VAPP_KMM_MENU_BG_HEIGHT (202)
#else
#define VAPP_KMM_MENU_BG_X (0)
#define  VAPP_KMM_MENU_BG_HEIGHT (389)
#endif

/*****************************************************************************
 * Enum
 *****************************************************************************/

/*****************************************************************************
 * Global Variable
 *****************************************************************************/
static mmi_id g_vapp_key_mainmenu_group_id = GRP_ID_INVALID;
static mmi_app_package_name_struct g_vapp_key_mainmenu_highlight_name;
static VfxBool g_vapp_key_mainmenu_show_popup = MMI_FALSE; 
static VfxBool g_vapp_key_mainmenu_preinsatll_change = VFX_TRUE;
/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

static mmi_ret vapp_post_display_confirm(mmi_event_struct *evt);
static mmi_ret vapp_key_mainmenu_confirm_proc(mmi_alert_result_evt_struct *evt);
static void vapp_display_popup(VappKeyMainmenuPopupCtx *popupCtx);
static void vapp_key_mainmenu_uninstall_app_callback(srv_appmgr_cb_event_enum result, void *user_data);
static void vapp_key_mainmenu_uninstall_app_by_name(void);

void vappKeyMainmenuSaveData();

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

static mmi_ret vapp_post_display_confirm(mmi_event_struct *evt)
{
    if (evt)
    {		
        mmi_confirm_property_struct confirmProperty;
        mmi_confirm_property_init(&confirmProperty, CNFM_TYPE_YESNO);
        confirmProperty.callback = (mmi_proc_func)vapp_key_mainmenu_confirm_proc;
        confirmProperty.parent_id = GRP_ID_ROOT; 
        confirmProperty.f_auto_question_mark = MMI_TRUE;
       // confirmProperty.f_enter_history = MMI_TRUE;
        
        const MMI_STR_ID string_id = STR_ID_VAPP_KMM_UNINSTALL;
        mmi_event_notify_enum event = MMI_EVENT_QUERY;
        
        mmi_confirm_display_ext(
            string_id,
            event,
            &confirmProperty);
    }
    
    return MMI_RET_OK;
}

static mmi_ret vapp_key_mainmenu_confirm_proc(mmi_alert_result_evt_struct *evt)
{
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
            case MMI_ALERT_CNFM_YES:
                VappKeyMainmenuPopupCtx popupCtx;
                popupCtx.string_id = STR_ID_VAPP_KMM_UNINSTALLING;
                popupCtx.event = MMI_EVENT_PROGRESS;
                popupCtx.parent_id = GRP_ID_ROOT;
                vapp_display_popup(&popupCtx);
                
                if (srv_appmgr_uninstall_app(g_vapp_key_mainmenu_highlight_name, vapp_key_mainmenu_uninstall_app_callback, NULL) == MMI_RET_ERR)
                {
                    VappKeyMainmenuPopupCtx popupCtx;
                    popupCtx.string_id = STR_GLOBAL_FAILED;
                    popupCtx.event = MMI_EVENT_FAILURE;
                    popupCtx.parent_id = GRP_ID_ROOT;
                    vapp_display_popup(&popupCtx);
                }
            	break;
            	
            case MMI_ALERT_CNFM_NO:
            	break;
        }
    }
    
    return MMI_RET_OK;
}

static void vapp_display_popup(VappKeyMainmenuPopupCtx *popupCtx)
{
    mmi_popup_property_struct popup_property;
    mmi_popup_property_init(&popup_property);
    
    if (popupCtx)
    {
        if (popupCtx->event == MMI_EVENT_PROGRESS)
        {
            popup_property.f_auto_dismiss = MMI_FALSE;
        }
        else
        {
            popup_property.f_auto_dismiss = MMI_TRUE;
        }
        popup_property.parent_id = popupCtx->parent_id;
        mmi_popup_display_ext(popupCtx->string_id, popupCtx->event, &popup_property);
    }
}

static mmi_ret vapp_key_mainmenu_uninstall_app_proc(mmi_event_struct *evt)
{
	mmi_frm_scrn_close_active_id();
	return MMI_RET_OK;
}
static void vapp_key_mainmenu_uninstall_app_callback(srv_appmgr_cb_event_enum result, void *user_data)
{
    VappKeyMainmenuPopupCtx popupCtx;
    
    switch (result)
    {
        case SRV_APPMGR_CB_EVENT_DONE:
           // popupCtx.string_id = STR_GLOBAL_DELETED;
           // popupCtx.event = MMI_EVENT_SUCCESS;
			//mmi_frm_scrn_close_active_id();  // enhance UE
			mmi_event_struct evt;
 
			MMI_FRM_INIT_EVENT(&evt, 0);
			mmi_frm_post_event(&evt, vapp_key_mainmenu_uninstall_app_proc, 0);
			return;
            //break;
            
        case SRV_APPMGR_CB_EVENT_ERROR:
        case SRV_APPMGR_CB_EVENT_CANCEL:
        default:
            popupCtx.string_id = STR_GLOBAL_FAILED;
            popupCtx.event = MMI_EVENT_FAILURE;
            break;
    }

    if (g_vapp_key_mainmenu_group_id != GRP_ID_INVALID)
    {
        popupCtx.parent_id  = g_vapp_key_mainmenu_group_id;
    }
    else
    {
        popupCtx.parent_id  = GRP_ID_ROOT;
    }
    vapp_display_popup(&popupCtx);
}

static void vapp_key_mainmenu_display_limit_popup()
{
    VappKeyMainmenuPopupCtx popupCtx;
	popupCtx.string_id = STR_ID_VAPP_KMM_LIMIT_NUM;
    popupCtx.event = MMI_EVENT_INFO;
	popupCtx.parent_id  = GRP_ID_ROOT;
	vapp_display_popup(&popupCtx);
}


static void vapp_key_mainmenu_uninstall_app_by_name()
{
#ifdef __OP01__
    if (strncmp(g_vapp_key_mainmenu_highlight_name, "java", 4) == 0)
    {
        if (srv_appmgr_uninstall_app(g_vapp_key_mainmenu_highlight_name, vapp_key_mainmenu_uninstall_app_callback, NULL) == MMI_RET_ERR)
        {
            VappKeyMainmenuPopupCtx popupCtx;
            popupCtx.string_id = STR_GLOBAL_FAILED;
            popupCtx.event = MMI_EVENT_FAILURE;
            popupCtx.parent_id = GRP_ID_ROOT;
            vapp_display_popup(&popupCtx);
        }
    }
    else
#endif
    {
		VfxBool is_bg_running = VFX_FALSE;
		if(strncmp(g_vapp_key_mainmenu_highlight_name, "mre", 3) == 0)
		{
			is_bg_running = srv_mre_appmgr_is_bg_running(g_vapp_key_mainmenu_highlight_name);
		}

		if(is_bg_running)
		{
            VappKeyMainmenuPopupCtx popupCtx;
            popupCtx.string_id = STR_ID_KMM_EXIT_RUNNING_APP;
            popupCtx.event = MMI_EVENT_FAILURE;
            popupCtx.parent_id = GRP_ID_ROOT;
            vapp_display_popup(&popupCtx);
		}
		else
		{
            mmi_event_struct evt;
            MMI_FRM_INIT_EVENT(&evt, 0);
            MMI_FRM_POST_EVENT(&evt, vapp_post_display_confirm, 0);
	        g_vapp_key_mainmenu_group_id = GRP_ID_ROOT;
        }
    }
}
/*****************************************************************************
 * Global Function
 *****************************************************************************/
void vapp_key_mainmenu_uninstall_app(VappKeyMainmenuCell *cell) // invoke by pen
{
   // mmi_app_package_name_struct appName;
	cell->getCellAppName(g_vapp_key_mainmenu_highlight_name);
	g_vapp_key_mainmenu_group_id = mmi_frm_group_get_active_id();
	vapp_key_mainmenu_uninstall_app_by_name();
}


MMI_BOOL vapp_key_mainmenu_option_menu_hdlr(VfxU16 menu_id)
{
	switch (menu_id)
	{
		case MENU_ID_VAPP_KMM_MOVE:
		{
			VappKeyMainmenu::m_isOrganizeMode = VFX_TRUE;
			return MMI_TRUE;
		}
		case MENU_ID_VAPP_KMM_OPEN:
		{
			srv_appmgr_launch(g_vapp_key_mainmenu_highlight_name);
			break;
		}
		case MENU_ID_VAPP_KMM_UNINSTALL:
		{
			vapp_key_mainmenu_uninstall_app_by_name();
			break;
		}
#ifdef __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
		case MENU_ID_VAPP_KMM_EFFECT:
		{
			break;
		}
		case MENU_ID_VAPP_KMM_EFFECT_NONE:
		{
			VappKeyMainmenu::m_animType = VCP_PAGE_MENU_TRANSITION_TYPE_NORMAL;
			VappKeyMainmenu::m_isRandom = VFX_FALSE;
			mmi_phnset_menu_effect_set_menu_transition_type(MMI_PHNSET_VCP_PAGE_MENU_TRANSITION_TYPE_NORMAL);
			return MMI_TRUE;
	    }
		case MENU_ID_VAPP_KMM_EFFECT_RANDOM:
		{
			VappKeyMainmenu::m_isRandom = VFX_TRUE;
			mmi_phnset_menu_effect_set_menu_transition_type(MMI_PHNSET_VCP_PAGE_MENU_TRANSITION_TYPE_SHUFFLE);
			return MMI_TRUE;
		}
		case MENU_ID_VAPP_KMM_BALL:
		case MENU_ID_VAPP_KMM_SPACE_BEAM:
		case MENU_ID_VAPP_KMM_JUMP_UP:
		case MENU_ID_VAPP_KMM_PHOTO_WAVE:
		case MENU_ID_VAPP_KMM_TILT:
		case MENU_ID_VAPP_KMM_ROLL:
		case MENU_ID_VAPP_KMM_SLIDE_DOWN:
		case MENU_ID_VAPP_KMM_SLIDE_UP:
		case MENU_ID_VAPP_KMM_EFFECT_COLLECTION_MM:
		case MENU_ID_VAPP_KMM_COLLECTION_TB:
		case MENU_ID_VAPP_KMM_CYLINDER:
		case MENU_ID_VAPP_KMM_TORNADO:
		case MENU_ID_VAPP_KMM_CUBE:
		{
			VappKeyMainmenu::m_isRandom = VFX_FALSE;
			VappKeyMainmenu::m_animType = (VcpPageMenuTransitionType)(VCP_PAGE_MENU_TRANSITION_TYPE_NORMAL + (menu_id - MENU_ID_VAPP_KMM_BALL + 1));
			mmi_phnset_menu_effect_set_menu_transition_type(mmi_phnset_menu_transition_type_enum(VappKeyMainmenu::m_animType+1));
			return MMI_TRUE;
		}
#endif
		default: 
			break;
	}
	return MMI_FALSE;
}
static mmi_ret vapp_key_mainmenu_option_menu_proc(mmi_event_struct *evt)
{
	MMI_BOOL closeMenu = MMI_FALSE;

	switch(evt->evt_id)
	{
		case EVT_ID_CUI_MENU_LIST_ENTRY:
		{
#ifdef __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__	
            cui_menu_event_struct *event = (cui_menu_event_struct *)evt;
			if(event->parent_menu_id == MENU_ID_VAPP_KMM_EFFECT)
			{
				if(VappKeyMainmenu::m_isRandom)
				    cui_menu_set_radio_list_item(event->sender_id, MENU_ID_VAPP_KMM_EFFECT_RANDOM);
				else
					cui_menu_set_radio_list_item(event->sender_id, MENU_ID_VAPP_KMM_EFFECT_NONE + VappKeyMainmenu::m_animType);
			}
#endif
			break;
		}
		case EVT_ID_CUI_MENU_ITEM_SELECT:
		{
			cui_menu_event_struct *event = (cui_menu_event_struct *)evt;
			
			closeMenu = vapp_key_mainmenu_option_menu_hdlr(event->highlighted_menu_id);
			if(closeMenu)
			cui_menu_close(event->sender_id);
			break;
		}
		case EVT_ID_CUI_MENU_CLOSE_REQUEST:
		{
			cui_menu_event_struct *event = (cui_menu_event_struct *)evt;
			
			cui_menu_close(event->sender_id);
			break;
		}
		default:
			break;
	}
	 return MMI_RET_OK;
}
void vapp_key_mainmenu_display_option_menu(VfxBool isUnstalled)
{
	mmi_id menu_gid;

	if(isUnstalled == VFX_FALSE)
		mmi_frm_hide_menu_item(MENU_ID_VAPP_KMM_UNINSTALL);
	else
		mmi_frm_unhide_menu_item(MENU_ID_VAPP_KMM_UNINSTALL);
	
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_KEY_MAINMENU_OPTION, vapp_key_mainmenu_option_menu_proc, (void*)NULL);

    mmi_frm_group_enter(GRP_ID_KEY_MAINMENU_OPTION, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    menu_gid = cui_menu_create(
                GRP_ID_KEY_MAINMENU_OPTION,
                CUI_MENU_SRC_TYPE_RESOURCE,
                CUI_MENU_TYPE_OPTION,
                MENU_ID_VAPP_KMM_OPTION,
                MMI_TRUE,
                NULL);
	cui_menu_enable_cascading_option_menu(menu_gid);
    cui_menu_run(menu_gid);
}

void vappKeyMainmenuCheckLoadOrderData();
mmi_app_package_name_struct * vappKeyMainmenuGetAllOrderData();
static void vappKeyMainmenuSetNeedSycn();
/***************************************************************************** 
 * Class VappLauncherMainmenuScr for Background call
 *****************************************************************************/
static mmi_id g_vapp_launcher_mm_group_id = GRP_ID_INVALID;
static VappLauncherMmScr *g_vapp_launcher_mm_scr = NULL;
static mmi_ret vapp_launcher_mm_group_proc(mmi_event_struct* evt)
{
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_INACTIVE:
           // VappDrawerScr::setOrganizeChanged(VFX_FALSE);
            break;
        case EVT_ID_GROUP_DEINIT:
            g_vapp_launcher_mm_group_id = GRP_ID_INVALID;
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}

static void vapp_launcher_mm_init()
{
    VfxAppCatScr::initalizeWithScrAsmSize(VAPP_KMM_MAX_CNTX_MEM_SIZE);
    
	VFX_OBJ_CREATE(g_vapp_launcher_mm_scr, VappLauncherMmScr, VfxAppCatScr::getContext());
}

static void vapp_launcher_mm_exit()
{
    VFX_OBJ_CLOSE(g_vapp_launcher_mm_scr);
    
    VfxAppCatScr::deinitalize();
}
static void vapp_launcher_mm_entry()
{
    if (mmi_frm_scrn_enter(g_vapp_launcher_mm_group_id,
                           VAPP_LAUNCHER_MM_SCRN_ID,
                           vapp_launcher_mm_exit,
                           vapp_launcher_mm_entry,
                           MMI_FRM_FULL_SCRN))
    {
        vapp_launcher_mm_init();
    }
}

extern "C" MMI_ID vapp_launcher_mm_launch(void *param, U32 param_size)
{
    g_vapp_launcher_mm_group_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, vapp_launcher_mm_group_proc, NULL);
    mmi_frm_group_enter(g_vapp_launcher_mm_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    vapp_launcher_mm_entry();

    return g_vapp_launcher_mm_group_id;
}
VFX_IMPLEMENT_CLASS("VappLauncherMmWallpaper", VappLauncherMmWallpaper, VfxFrame);


VFX_IMPLEMENT_CLASS("VappLauncherMmScr", VappLauncherMmScr, VfxAppCatScr);
VfxBool VappLauncherMmScr::m_isActive = VFX_FALSE;
VappLauncherMmScr::VappLauncherMmScr():
    m_statusBar(NULL),
    m_wallpaper(NULL),
	m_menu(NULL)
{

}
void VappLauncherMmScr::onInit()
{
    VfxAppCatScr::onInit();
	m_isActive = VFX_TRUE;
	VFX_OBJ_CREATE(m_wallpaper, VappLauncherMmWallpaper, this);
	m_wallpaper->setPos(0,0);
	m_wallpaper->setSize(LCD_WIDTH, LCD_HEIGHT);
	if(current_MMI_theme->sub_menu_bkg_filler->b)
	{
		m_wallpaper->setImgContent(VfxImageSrc(current_MMI_theme->sub_menu_bkg_filler->b));
		m_wallpaper->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	}
	else
		m_wallpaper->setBgColor(VFX_COLOR_BLACK);

    // create status bar
    VFX_OBJ_CREATE(m_statusBar, VcpStatusIconBar, this);
    m_statusBar->setAutoAnimate(VFX_TRUE);
    m_statusBar->setPos(0, 0);

	VFX_OBJ_CREATE(m_menu, VappKeyMainmenu, this);
	m_menu->show(VAPP_LAUNCHER_KMM_ENTRY_ANIM_TYPE_NONE);

	m_menu->m_backFromMainmenu.connect(this, &VappLauncherMmScr::onMainMenuBack);
}
void VappLauncherMmScr::onMainMenuBack()
{
	 MMI_ID before_id = mmi_frm_scrn_get_neighbor_id(GRP_ID_ROOT, g_vapp_launcher_mm_group_id, MMI_FRM_NODE_BEFORE_FLAG);
	 if(before_id == APP_IDLE)
	 {
		 vapp_launcher_key_on_before_idle_display();
	 }
	 mmi_frm_scrn_close_active_id();
}
void VappLauncherMmScr::onDeinit()
{
	m_isActive = VFX_FALSE;
	VFX_OBJ_CLOSE(m_menu);
	VFX_OBJ_CLOSE(m_statusBar);
	VFX_OBJ_CLOSE(m_wallpaper);
    VfxAppCatScr::onDeinit();
}

/***************************************************************************** 
 * Class VappLauncherMmScr for Background call - end
 *****************************************************************************/
VfxS32 vappKeyMainmenuGetCellCountInPage()
{
    return VAPP_KMM_CELL_ROW_COUNT * VAPP_KMM_CELL_COLUMN_COUNT;
}


VfxS32 VappKeyMainmenu::m_currentPage = 0;
VfxBool VappKeyMainmenu::m_isOrganizeMode = VFX_FALSE;
VfxS32 VappKeyMainmenu::m_highlightIndex = 0;
#ifdef __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
VcpPageMenuTransitionType VappKeyMainmenu::m_animType = VCP_PAGE_MENU_TRANSITION_TYPE_NORMAL;
VfxBool VappKeyMainmenu::m_isRandom = VFX_TRUE;
#endif
VappKeyMainmenu::VappKeyMainmenu():
    m_menu(NULL),
    m_builder(NULL),
    m_softkeybar(NULL),
    m_highlightCell(NULL),
	m_isAnmiation(VFX_FALSE),
#ifdef __VAPP_KMM_SHOW_MENU_BG__
	m_menu_bg(NULL),
#endif
	m_isHidden(VFX_FALSE),
	m_isCskDown(VFX_FALSE)
{

}

VfxBool VappKeyMainmenu::onKeyInput(VfxKeyEvent & event)
{
	if(m_isHidden)
		return VFX_FALSE;
	if(m_isAnmiation)
		return VFX_TRUE;

	switch(event.keyCode)
	{
		case VFX_KEY_CODE_0:
		case VFX_KEY_CODE_1:
		case VFX_KEY_CODE_2:
		case VFX_KEY_CODE_3:
		case VFX_KEY_CODE_4:
		case VFX_KEY_CODE_5:
		case VFX_KEY_CODE_6:
		case VFX_KEY_CODE_7:
		case VFX_KEY_CODE_8:
		case VFX_KEY_CODE_9:
		case VFX_KEY_CODE_POUND:
		case VFX_KEY_CODE_STAR:
		case VFX_KEY_CODE_SEND:
			return VFX_TRUE;
		case VFX_KEY_CODE_LSK:
		{
			if(m_isAnmiation)
				return VFX_TRUE;
			else
				return VFX_FALSE;
		}
		case VFX_KEY_CODE_RSK:
		{
			if(m_isOrganizeMode)
			{
				if(event.type == VFX_KEY_EVENT_TYPE_UP)
					m_menu->cancelOrganization();
					//vfxPostInvoke(this, &VappKeyMainmenu::handleRsk);
				 return VFX_TRUE;
			}
			else
			{
				 return VFX_FALSE;
			}
		}
		case VFX_KEY_CODE_CSK:
		{
			if (event.type == VFX_KEY_EVENT_TYPE_DOWN && m_isOrganizeMode == VFX_FALSE)
			{
				suspendWallpaper(); 
				m_isCskDown = VFX_TRUE;
			}
			if(event.type == VFX_KEY_EVENT_TYPE_UP && m_isAnmiation == VFX_FALSE)
			{
				if(m_isOrganizeMode)
				{
					m_menu->leaveOrganizationMode(VFX_TRUE);
					m_builder->saveMenu(m_menu);
					vappKeyMainmenuSaveData();
				}
				else
			    {
			    	if(m_isCskDown)
					onAppClicked(m_highlightCell);
				}
			}
			return VFX_TRUE;
		}
		case VFX_KEY_CODE_CLEAR:
		{
			if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
			{
				vfxPostInvoke(this, &VappKeyMainmenu::handleClearKey);
			}
			return VFX_TRUE;
		}
		default:
			return VfxControl::onKeyInput(event);
	}
				
}

void VappKeyMainmenu::suspendWallpaper()
{
	if(VappLauncherMmScr::m_isActive)
		return;
	((VappKeyLauncherDirector*)getParent())->m_wallpaper->suspend();
}

void VappKeyMainmenu::resumeWallpaper()
{
	if(VappLauncherMmScr::m_isActive)
		return;
	((VappKeyLauncherDirector*)getParent())->m_wallpaper->resume();
}

void VappKeyMainmenu::onSuspendWallpaper(VfxBool is_suspend)
{
	if(is_suspend)
		suspendWallpaper();
	else
		resumeWallpaper();
}

void VappKeyMainmenu::onEntryAnimTimer(VfxTimer *source)
{
	if(m_isHidden)
	{
		resumeWallpaper();
		VFX_OBJ_CLOSE(source);
		return;
	}
	m_isAnmiation = VFX_FALSE;
#ifdef __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
	m_menu->setTransitionEffect(m_animType);
#endif
#ifdef __VAPP_KMM_SHOW_MENU_BG__
	VappWallpaper *pWallpaper;  // set as wallpaper 's child frame for performance
	pWallpaper = ((VappKeyLauncherDirector*)getParent())->getWallpaper();
	VappWallpaperWide *wide = VFX_OBJ_DYNAMIC_CAST(pWallpaper, VappWallpaperWide);
	if(wide && wide->getFirstChildFrame() && (wide->getFirstChildFrame()->getSize().width == VAPP_KMM_SCREEN_WIDTH) && (wide->getFirstChildFrame()->getSize().height == VAPP_KMM_SCREEN_HEIGHT))
	{
		 pWallpaper->getFirstChildFrame()->addChildFrame(m_menu_bg);
	}
	else
	{
		// pWallpaper->addChildFrame(m_menu_bg);
		((VappKeyLauncherDirector*)getParent())->getContainer()->addChildFrame(m_menu_bg);
	}
	m_menu_bg->setPos(VAPP_KMM_MENU_BG_X, VAPP_KMM_CELL_START_Y + MMI_STATUS_BAR_HEIGHT);
#endif
	resumeWallpaper();
	m_softkeybar->disableSoftkey(VFX_FALSE);
	VFX_OBJ_CLOSE(source);
}
void VappKeyMainmenu::onRestoreTimer(VfxTimer *source)
{
#ifdef __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
	m_menu->setTransitionEffect(m_animType);
#endif
	resumeWallpaper();
	VFX_OBJ_CLOSE(source);
}

void VappKeyMainmenu::onShowPopup(VfxTimer *source)
{
	VFX_OBJ_CLOSE(source);
	if(g_vapp_key_mainmenu_show_popup)
	{
		g_vapp_key_mainmenu_show_popup = VFX_FALSE;
		vapp_key_mainmenu_display_limit_popup();
	}
}

void VappKeyMainmenu::showAnimation()
{
	suspendWallpaper();
	setAutoAnimate(VFX_TRUE);  	
#ifdef __VAPP_KMM_SHOW_MENU_BG__
	insertChildFrameBefore(m_menu, m_menu_bg);
	m_menu_bg->setHidden(VFX_FALSE);
	m_menu_bg->setPos(VAPP_KMM_MENU_BG_X, VAPP_KMM_CELL_START_Y);
#endif
	VfxAutoAnimate::initAnimateBegin();
	VfxAutoAnimate::begin(); 
	VfxAutoAnimate::setDisable(VFX_TRUE);
	setPos(VfxPoint(0, VAPP_KMM_HEIGHT+VAPP_KMM_POS_Y));
	VfxAutoAnimate::setDuration(ENTRY_ANIM_DURATION);
	VfxAutoAnimate::setDisable(VFX_FALSE);
	setPos(VfxPoint(0, VAPP_KMM_POS_Y));
	VfxAutoAnimate::commit();	 
	VfxAutoAnimate::initAnimateEnd();

	m_isAnmiation = VFX_TRUE;

	m_softkeybar->disableSoftkey(VFX_TRUE);
    VfxTimer *timer;
    VFX_OBJ_CREATE(timer, VfxTimer, this);
    timer->setStartDelay(ENTRY_ANIM_DURATION);
    timer->m_signalTick.connect(this, &VappKeyMainmenu::onEntryAnimTimer);
    timer->start();
}

void VappKeyMainmenu::show(VappLauncherKmmEntryAnimType type)
{
	 VfxBool isCellAnim = VFX_FALSE;

#ifdef __MAUI_SOFTWARE_LA__
	 SLA_CustomLogging("KSH", SA_start);
#endif
	//type = VAPP_LAUNCHER_KMM_ENTRY_ANIM_TYPE_NONE;
    setHidden(VFX_FALSE);
	setPos(VfxPoint(0, VAPP_KMM_POS_Y));
#ifdef __VAPP_KMM_SHOW_MENU_BG__
	if(VappLauncherMmScr::m_isActive == VFX_FALSE && type != VAPP_LAUNCHER_KMM_ENTRY_ANIM_TYPE_FROM_IDLE)
	{
		VappWallpaper *pWallpaper;  // set as wallpaper 's child frame for performance
		pWallpaper = ((VappKeyLauncherDirector*)getParent())->getWallpaper();
		VappWallpaperWide *wide = VFX_OBJ_DYNAMIC_CAST(pWallpaper, VappWallpaperWide);
		if(wide && wide->getFirstChildFrame() && \
			(wide->getFirstChildFrame()->getSize().width == VAPP_KMM_SCREEN_WIDTH) && \
			(wide->getFirstChildFrame()->getSize().height == VAPP_KMM_SCREEN_HEIGHT))
		{
			(pWallpaper->getFirstChildFrame())->addChildFrame(m_menu_bg);
		}
		else
		{
			//pWallpaper->addChildFrame(m_menu_bg);
			((VappKeyLauncherDirector*)getParent())->getContainer()->addChildFrame(m_menu_bg);
		}
		m_menu_bg->setPos(VAPP_KMM_MENU_BG_X, VAPP_KMM_CELL_START_Y + MMI_STATUS_BAR_HEIGHT);
	}
#endif /* #ifdef __VAPP_KMM_SHOW_MENU_BG__ */
#ifdef __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
	 if(m_isRandom)			
	    m_animType = (VcpPageMenuTransitionType)(VCP_PAGE_MENU_TRANSITION_TYPE_NORMAL + (rand()%VCP_PAGE_MENU_TRANSITION_TYPE_MAX));
	 m_menu->setTransitionEffect(VCP_PAGE_MENU_TRANSITION_TYPE_NORMAL);
	 if(type == VAPP_LAUNCHER_KMM_ENTRY_ANIM_TYPE_NONE && m_isOrganizeMode != VFX_TRUE)
	 {
	 	suspendWallpaper();
	    VfxTimer *timer;
		VFX_OBJ_CREATE(timer, VfxTimer, this);
		timer->setStartDelay(RESTORE_EFFECT_DURATION);
		timer->m_signalTick.connect(this, &VappKeyMainmenu::onRestoreTimer);
		timer->start();
	 }
#endif	 
	 if(type == VAPP_LAUNCHER_KMM_ENTRY_ANIM_TYPE_FROM_WIDGET)
	 {
		isCellAnim = VFX_TRUE;
	 }
	 m_menu->showMenuItems(isCellAnim);
	 if(type == VAPP_LAUNCHER_KMM_ENTRY_ANIM_TYPE_FROM_IDLE)
	 {
		showAnimation();
	 }
	 if(g_vapp_key_mainmenu_show_popup)
	 {
 	    VfxTimer *timer;
		VFX_OBJ_CREATE(timer, VfxTimer, this);
		timer->setStartDelay(SHOW_POPUP_DELAY);
		timer->m_signalTick.connect(this, &VappKeyMainmenu::onShowPopup);
		timer->start();
	 }
#ifdef __MAUI_SOFTWARE_LA__
	 SLA_CustomLogging("KSH", SA_stop);
#endif

}
#ifdef __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
void VappKeyMainmenu::initPageMenuSwitchAnimType()
{

	mmi_phnset_menu_transition_type_enum anim_type = mmi_phnset_menu_effect_get_menu_transition_type();

	if(anim_type == MMI_PHNSET_VCP_PAGE_MENU_TRANSITION_TYPE_SHUFFLE)
	{
		m_isRandom = VFX_TRUE;
	}
	else
	{
		m_isRandom = VFX_FALSE;
		m_animType = VcpPageMenuTransitionType(anim_type - 1); 
	}
}
#endif
void VappKeyMainmenu::onInit()
{
	VfxControl::onInit();
	MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_VAPP_LAUNCHER_KEY_MM_ON_INIT);
	g_vapp_key_mainmenu_group_id = mmi_frm_group_get_active_id();
#ifdef __MAUI_SOFTWARE_LA__
	SLA_CustomLogging("KOI", SA_start);
#endif
    setPos(VfxPoint(0, VAPP_KMM_POS_Y));   // set default pos & size
    setSize(VfxSize(VAPP_KMM_SCREEN_WIDTH, VAPP_KMM_HEIGHT));
	setCacheMode(VFX_CACHE_MODE_PREVENT);
    // create VappDrawerPageMenu
#ifdef __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
	initPageMenuSwitchAnimType();
#endif
    initMenu();
	
    mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE,&VappKeyMainmenu::EventHandler, this);
	VFX_OBJ_CREATE(m_softkeybar, VcpSoftkey, this);
	m_softkeybar->setPos(VfxPoint(0, VAPP_KMM_SOFTKEY_BAR_Y));
	m_softkeybar->setBounds(VfxRect(0, 0, VAPP_KMM_SCREEN_WIDTH, VAPP_KMM_SOFTKEY_BAR_HEIGHT));
    m_softkeybar->getCallback(VCP_SOFTKEY_LSK).connect(this, &VappKeyMainmenu::onEventLsk);
    m_softkeybar->getCallback(VCP_SOFTKEY_RSK).connect(this, &VappKeyMainmenu::onEventRsk);
	m_softkeybar->setSoftkeyWidth(VCP_SOFTKEY_LSK, VAPP_KMM_SOFTKEY_WIDTH - (m_softkeybar->getBorderGap() + m_softkeybar->getShiftOffset()));
	m_softkeybar->setSoftkeyWidth(VCP_SOFTKEY_RSK, VAPP_KMM_SOFTKEY_WIDTH - m_softkeybar->getBorderGap());
	m_softkeybar->setBorderGap(VAPP_KMM_SOFTKEY_BAR_GAP);
#ifndef __MMI_MAINLCD_320X240__	
	m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_RES(STR_GLOBAL_OPTIONS), VFX_IMAGE_SRC_NULL);
	m_softkeybar->setSoftkey(VCP_SOFTKEY_RSK, VFX_WSTR_RES(STR_GLOBAL_BACK), VFX_IMAGE_SRC_NULL);

	m_softkeybar->setImgContent(VfxImageSrc(IMG_ID_VAPP_KMM_SOFTKEY_BG));
	m_softkeybar->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	m_softkeybar->setFont(VfxFontDesc(VAPP_LAUNCHER_KEY_MM_SOFTKEY_FONT_SIZE));
#else
	m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_NULL, VfxImageSrc(IMG_ID_VAPP_KMM_SOFTKEY_OPTION));
	m_softkeybar->setSoftkey(VCP_SOFTKEY_RSK, VFX_WSTR_NULL, VfxImageSrc(IMG_ID_VAPP_KMM_SOFTKEY_BACK));

	
	m_softkeybar->setSoftkeyBackground(VCP_SOFTKEY_LSK, VfxImageSrc(IMG_ID_VAPP_KMM_SOFTKEY_BG));
	m_softkeybar->setSoftkeyBackground(VCP_SOFTKEY_RSK, VfxImageSrc(IMG_ID_VAPP_KMM_SOFTKEY_BG));
	m_softkeybar->setSoftkeyBackgroundContentPlacement(VCP_SOFTKEY_LSK, VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	m_softkeybar->setSoftkeyBackgroundContentPlacement(VCP_SOFTKEY_RSK, VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
#endif /* __MMI_MAINLCD_320X240__ */
    registerKeyHandler(VFX_KEY_CODE_0);
    registerKeyHandler(VFX_KEY_CODE_1);
    registerKeyHandler(VFX_KEY_CODE_2);
    registerKeyHandler(VFX_KEY_CODE_3);
	registerKeyHandler(VFX_KEY_CODE_4);
    registerKeyHandler(VFX_KEY_CODE_5);
    registerKeyHandler(VFX_KEY_CODE_6);
    registerKeyHandler(VFX_KEY_CODE_7);
    registerKeyHandler(VFX_KEY_CODE_8);
	registerKeyHandler(VFX_KEY_CODE_9);
	registerKeyHandler(VFX_KEY_CODE_STAR);
	registerKeyHandler(VFX_KEY_CODE_POUND);
	registerKeyHandler(VFX_KEY_CODE_LSK);
	registerKeyHandler(VFX_KEY_CODE_RSK);
	registerKeyHandler(VFX_KEY_CODE_CSK);
	registerKeyHandler(VFX_KEY_CODE_CLEAR);
	registerKeyHandler(VFX_KEY_CODE_SEND);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("KOI", SA_stop);
#endif
}

mmi_ret VappKeyMainmenu::EventHandler(mmi_event_struct *event)
{
    VappKeyMainmenu *keyMainmenu = (VappKeyMainmenu *)event->user_data;
    if(keyMainmenu->getIsHidden() == VFX_FALSE)
    {
        keyMainmenu->reloadMainmenu();
    }
    return MMI_RET_OK;
}

void VappKeyMainmenu::reloadMainmenu()
{
    vappKeyMainmenuCheckLoadOrderData();

    if (m_builder != NULL)
    {            
        m_menu->clearAllMenuItems();

        m_builder->loadMenu(m_menu, g_vapp_key_mainmenu_preinsatll_change);

        m_menu->setHighlightIndex(m_highlightIndex, VFX_FALSE);

        if (m_isOrganizeMode)
        {
            m_menu->entryOrganization();
        }
    }
}
void VappKeyMainmenu::onDeinit()
{
	VfxBool isDataDirty = VFX_FALSE;
	MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_VAPP_LAUNCHER_KEY_MM_ON_DEINIT);
	g_vapp_key_mainmenu_group_id = GRP_ID_INVALID;
#ifdef __MAUI_SOFTWARE_LA__
	SLA_CustomLogging("KDI", SA_start);
#endif

    m_currentPage = m_menu->getCurrentPageIndex();
	m_highlightIndex = m_menu->getHighlightIndex();
    if (m_isOrganizeMode)
    {
        m_menu->leaveOrganizationMode(VFX_FALSE);
        isDataDirty = VFX_TRUE;
        m_isOrganizeMode = VFX_FALSE;
    }

    if (isDataDirty)
    {
        m_builder->saveMenu(m_menu);
        vappKeyMainmenuSaveData();
    }
	m_builder->savePreinstallInfo(m_menu);
	//g_vapp_key_mainmenu_preinsatll_change = VFX_FALSE;
    mmi_frm_cb_dereg_event(EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE,&VappKeyMainmenu::EventHandler, this);
    VFX_OBJ_CLOSE(m_builder);
    VFX_OBJ_CLOSE(m_menu);
#ifdef __VAPP_KMM_SHOW_MENU_BG__
	VFX_OBJ_CLOSE(m_menu_bg);
#endif
#ifdef __MAUI_SOFTWARE_LA__
	SLA_CustomLogging("KDI", SA_stop);
#endif

    VfxControl::onDeinit();
}

void VappKeyMainmenu::setHidden(VfxBool value)
{
	MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_VAPP_LAUNCHER_KEY_MM_HIDDEN, value);
	setFocused(!value);
	if(value)
	{
		setAutoAnimate(VFX_FALSE);
#ifdef __VAPP_KMM_SHOW_MENU_BG__
		insertChildFrameBefore(m_menu, m_menu_bg);
#endif
		setPos(0, LCD_HEIGHT);
	}
	m_isHidden = value;

	m_menu->setHidden(value);
	m_softkeybar->disableSoftkey(value);
}

VfxBool VappKeyMainmenu::getIsHidden()
{
    return m_isHidden;
}
void VappKeyMainmenu::initMenu()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("KIM", SA_start);
#endif
	// Load data
	vappKeyMainmenuCheckLoadOrderData();
#ifdef __VAPP_KMM_SHOW_MENU_BG__
	if(VappLauncherMmScr::m_isActive)  // from goto_main_menu
	{
		VFX_OBJ_CREATE(m_menu_bg, VfxFrame, ((VappLauncherMmScr*)getParent())->m_wallpaper);
		m_menu_bg->setPos(VAPP_KMM_MENU_BG_X, VAPP_KMM_CELL_START_Y + MMI_STATUS_BAR_HEIGHT);
	}
	else
	{
		VappWallpaper *pWallpaper;  // set as wallpaper 's child frame for performance
		pWallpaper = ((VappKeyLauncherDirector*)getParent())->getWallpaper();
		VappWallpaperWide *wide = VFX_OBJ_DYNAMIC_CAST(pWallpaper, VappWallpaperWide);
		if(wide && wide->getFirstChildFrame() && (wide->getFirstChildFrame()->getSize().width == VAPP_KMM_SCREEN_WIDTH) && (wide->getFirstChildFrame()->getSize().height == VAPP_KMM_SCREEN_HEIGHT))
		{
			VFX_OBJ_CREATE(m_menu_bg, VfxFrame, pWallpaper->getFirstChildFrame());
		}
		else
		{
			//VFX_OBJ_CREATE(m_menu_bg, VfxFrame, pWallpaper);
			VFX_OBJ_CREATE(m_menu_bg, VfxFrame, ((VappKeyLauncherDirector*)getParent())->getContainer());
		}
		m_menu_bg->setPos(VAPP_KMM_MENU_BG_X, VAPP_KMM_CELL_START_Y + MMI_STATUS_BAR_HEIGHT);
	}

	m_menu_bg->setSize(VfxSize(VAPP_KMM_SCREEN_WIDTH - 2*VAPP_KMM_MENU_BG_X, VAPP_KMM_MENU_BG_HEIGHT));
	m_menu_bg->setImgContent(VfxImageSrc(IMG_ID_VAPP_KMM_BG));
	m_menu_bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
#endif /* #ifdef __VAPP_KMM_SHOW_MENU_BG__ */
    VFX_OBJ_CREATE(m_menu, VappKeyMainmenuPageMenu, this);
    VcpPageMenuLayout layout;
    layout.rowCount = VAPP_KMM_CELL_ROW_COUNT;
    layout.columnCount = VAPP_KMM_CELL_COLUMN_COUNT;
    layout.cellStartX = VAPP_KMM_CELL_START_X;
    layout.cellStartY = VAPP_KMM_CELL_START_Y;
    layout.cellOffsetX = VAPP_KMM_CELL_OFFSET_X;
    layout.cellOffsetY = VAPP_KMM_CELL_OFFSET_Y;
    layout.pageMargin = VAPP_KMM_PAGE_MARGIN;
	layout.bottomBarOffsetY = VAPP_KMM_SOFTKEY_BAR_Y;  // for ball effect
    m_menu->setMenuLayout(layout);
    m_menu->setCellIconSize(VfxSize(VAPP_KMM_CELL_OFFSET_X, VAPP_KMM_CELL_OFFSET_Y) );

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("KIM", SA_stop);
    SLA_CustomLogging("KIM", SA_start);
#endif
    mmi_app_package_name_struct * orderList = vappKeyMainmenuGetAllOrderData();//+ VAPP_DRAWER_MAX_GROUP_APP_DATA;
    
    VFX_OBJ_CREATE(m_builder, VappKeyMainmenuBuilder, this);
    m_builder->setAppOrderData(orderList, VAPP_KEY_MAINMENU_SAVED_DATA_COUNT);
    m_builder->loadMenu(m_menu, g_vapp_key_mainmenu_preinsatll_change);
    if(g_vapp_key_mainmenu_preinsatll_change)
	{
		vappKeyMainmenuSaveData();  // reserve pre installed mre order.
		g_vapp_key_mainmenu_preinsatll_change = VFX_FALSE;
	}
    m_menu->setPos(VfxPoint(VAPP_KMM_MENU_MARGERN_X, 0));
    m_menu->setSize(VfxSize(VAPP_KMM_SCREEN_WIDTH- 2*VAPP_KMM_MENU_MARGERN_X, VAPP_KMM_MENU_HEIGHT));
	//m_menu->setBounds(VfxRect(VAPP_KMM_MENU_MARGERN_X, 0, VAPP_KMM_SCREEN_WIDTH-2*VAPP_KMM_MENU_MARGERN_X, VAPP_KMM_MENU_HEIGHT));
    m_menu->m_appClicked.connect(this, &VappKeyMainmenu::onAppClicked);
	m_menu->m_highlightChanged.connect(this, &VappKeyMainmenu::onHighlightChanged);
    m_menu->m_organizationChanged.connect(this, &VappKeyMainmenu::onOrganizeChanged);
	m_menu->setHighlightIndex(m_highlightIndex, VFX_FALSE);
	m_menu->setCurrentPageIndex(m_currentPage, VFX_FALSE);
	m_menu->registerCellEvent();
	m_menu->m_suspendWallpaper.connect(this, &VappKeyMainmenu::onSuspendWallpaper);
	if(m_isOrganizeMode)
		m_menu->entryOrganization();
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("KIM", SA_stop);
#endif
}

void VappKeyMainmenu::handleClearKey(void * data)
{
	mmi_app_package_name_struct *installedAppArray = NULL;
	U32 installedAppCount = srv_appmgr_get_app_package_num(SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE);
	if (installedAppCount)
	{
		VFX_SYS_ALLOC_MEM(installedAppArray, sizeof(mmi_app_package_name_struct) * installedAppCount );
		mmi_ret result;
		result = srv_appmgr_get_app_package_list(SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE, installedAppArray, installedAppCount);
		VFX_ASSERT(result != MMI_RET_ERR);
	}
	VappKeyMainmenuCell *mmCell = static_cast<VappKeyMainmenuCell*>(m_highlightCell);
	VfxBool isInstalled = VFX_FALSE;
	mmi_app_package_name_struct appName;
	mmCell->getCellAppName(appName);
	if (installedAppArray)
	{
		isInstalled = isKmmInstalledApp(appName, installedAppArray, installedAppCount);
		VFX_SYS_FREE_MEM(installedAppArray);
	}
	if(isInstalled)
	{
		strncpy(g_vapp_key_mainmenu_highlight_name, appName, MMI_APP_NAME_MAX_LEN);
		vapp_key_mainmenu_uninstall_app_by_name();
	}

}

void VappKeyMainmenu::onRestoreWallpaperTimer(VfxTimer *source)
{
	resumeWallpaper();
	VFX_OBJ_CLOSE(source);
}

void VappKeyMainmenu::onEventLsk(VcpSoftkeyEventEnum event_type)
{
	if(m_isAnmiation)
		return;
	if (event_type == VCP_SOFTKEY_DOWN && m_isOrganizeMode == VFX_FALSE)
	{
#ifdef __MAUI_SOFTWARE_LA__
		SLA_CustomLogging("M00", SA_start);
#endif

		suspendWallpaper(); 
	    VfxTimer *timer; // softkey cp not abort event, so start a timer to resume wallpaper. 
		VFX_OBJ_CREATE(timer, VfxTimer, this);
		timer->setStartDelay(RESTORE_WALLPAPER_DURATION);
		timer->m_signalTick.connect(this, &VappKeyMainmenu::onRestoreWallpaperTimer);
		timer->start();
#ifdef __MAUI_SOFTWARE_LA__
		SLA_CustomLogging("M00", SA_stop);
#endif

	}
    if (event_type == VCP_SOFTKEY_UP)
    {
		if(m_isOrganizeMode)
		{
			m_menu->leaveOrganizationMode(VFX_TRUE);
			m_builder->saveMenu(m_menu);
			vappKeyMainmenuSaveData();
		}
		else
		{
		    #ifdef __MAUI_SOFTWARE_LA__
		    SLA_CustomLogging("MLK", SA_start);
		    kal_prompt_trace(MOD_MMI, "[Launcher Key]MLK, SA_start");
		    #endif
			CreateOptionList();
		    #ifdef __MAUI_SOFTWARE_LA__
		    SLA_CustomLogging("MLK", SA_stop);
		    kal_prompt_trace(MOD_MMI, "[Launcher Key]MLK, SA_stop");
		    #endif
	    }
	}
}

void VappKeyMainmenu::onEventRsk(VcpSoftkeyEventEnum event_type)
{
	if(m_isAnmiation)
		return;

	if (event_type == VCP_SOFTKEY_DOWN)
	{
		suspendWallpaper(); 
	    VfxTimer *timer; // softkey cp not abort event, so start a timer to resume wallpaper. 
		VFX_OBJ_CREATE(timer, VfxTimer, this);
		timer->setStartDelay(RESTORE_WALLPAPER_DURATION);
		timer->m_signalTick.connect(this, &VappKeyMainmenu::onRestoreWallpaperTimer);
		timer->start();
	}

    else if (event_type == VCP_SOFTKEY_UP)
    {
		//vfxPostInvoke(this, &VappKeyMainmenu::handleRsk);
		if(m_isOrganizeMode)
		{
			m_menu->cancelOrganization();
		}
		else
		{
			m_backFromMainmenu.emit();
		}

    }
}

void VappKeyMainmenu::CreateOptionList()
{
	VfxBool isInstalled = VFX_FALSE;
	mmi_app_package_name_struct appName;

	VappKeyMainmenuCell *mmCell = static_cast<VappKeyMainmenuCell*>(m_highlightCell);

	mmCell->getCellAppName(appName);

	if (strncmp(appName, "native", 5) == 0)
	{
		isInstalled = VFX_FALSE;
	}
	else
	{
		mmi_app_package_name_struct *installedAppArray = NULL;
		U32 installedAppCount = srv_appmgr_get_app_package_num(SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE);
		if (installedAppCount)
		{
			VFX_SYS_ALLOC_MEM(installedAppArray, sizeof(mmi_app_package_name_struct) * installedAppCount );
			mmi_ret result;
			result = srv_appmgr_get_app_package_list(SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE, installedAppArray, installedAppCount);
			VFX_ASSERT(result != MMI_RET_ERR);
		}

		if (installedAppArray)
		{
			isInstalled = isKmmInstalledApp(appName, installedAppArray, installedAppCount);
            VFX_SYS_FREE_MEM(installedAppArray);
		}
	}
	strncpy(g_vapp_key_mainmenu_highlight_name, appName, MMI_APP_NAME_MAX_LEN);
	#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MOP", SA_start);
    #endif
	vapp_key_mainmenu_display_option_menu(isInstalled);
	#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MOP", SA_stop);
    #endif
}

void VappKeyMainmenu::onHighlightChanged(VcpPageMenuCell *cell)
{
	m_highlightCell = cell;
}

void VappKeyMainmenu::onAppClicked(VcpPageMenuCell *cell)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("KOA", SA_start);
#endif
    VappKeyMainmenuCell *mmCell = static_cast<VappKeyMainmenuCell*>(cell);
    mmi_app_package_name_struct appName;
    mmCell->getCellAppName(appName);
	suspendWallpaper(); 
	gui_sse_setup_scenario(GUI_SSE_SCENARIO_FROM_MAINMENU);
	if(strncmp(appName, "native.mtk.3dgame", MMI_APP_NAME_MAX_LEN) == 0)
	{
		gui_sse_setup_scenario(GUI_SSE_SCENARIO_NONE);
	}
#if defined(__PLUTO_3D_V10__) && defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__)
	vcpSseSetupScenarioByApp(appName);
#endif
    srv_appmgr_launch(appName);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("KOA", SA_stop);
#endif
}
void VappKeyMainmenu::onOrganizeChanged(VfxBool organizeMode)
{
    m_isOrganizeMode = organizeMode;

#ifndef __MMI_MAINLCD_320X240__
	if(organizeMode)
	{
		m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_RES(STR_GLOBAL_OK), VFX_IMAGE_SRC_NULL);
		m_softkeybar->setSoftkey(VCP_SOFTKEY_RSK, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VFX_IMAGE_SRC_NULL);
	}
	else
	{
		m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_RES(STR_GLOBAL_OPTIONS), VFX_IMAGE_SRC_NULL);
		m_softkeybar->setSoftkey(VCP_SOFTKEY_RSK, VFX_WSTR_RES(STR_GLOBAL_BACK), VFX_IMAGE_SRC_NULL);
	}
#else
	if(organizeMode)
	{
		m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_NULL, VfxImageSrc(IMG_ID_VAPP_KMM_SOFTKEY_OK));
		m_softkeybar->setSoftkey(VCP_SOFTKEY_RSK, VFX_WSTR_NULL, VfxImageSrc(IMG_ID_VAPP_KMM_SOFTKEY_BACK));
	}
	else
	{
		m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_NULL, VfxImageSrc(IMG_ID_VAPP_KMM_SOFTKEY_OPTION));
		m_softkeybar->setSoftkey(VCP_SOFTKEY_RSK, VFX_WSTR_NULL, VfxImageSrc(IMG_ID_VAPP_KMM_SOFTKEY_BACK));
	}
#endif
}

static VfxBool s_vappKeyMainmenuIsFirstLoad = VFX_TRUE;
static VfxBool s_vappKeyMainmenuNeedSync = VFX_TRUE;
static VfxS32 s_vappKeyMainmenuOrderCount = 0;
static mmi_app_package_name_struct s_vappKeyMainmenuAllOrderData[VAPP_KEY_MAINMENU_SAVED_DATA_COUNT];

void vappKeyMainmenuSaveData()
{
    U8 * writeBufferPointer = (U8*)s_vappKeyMainmenuAllOrderData;
    for (VfxS32 i = 0; i < NVRAM_EF_VAPP_KMM_ORDER_DATA_TOTAL; ++i)
    {
        S16 error;

        WriteRecord(
            NVRAM_EF_VAPP_KMM_ORDER_DATA_LID,
            1+i,
            writeBufferPointer + NVRAM_EF_VAPP_KMM_ORDER_DATA_SIZE * i,
            NVRAM_EF_VAPP_KMM_ORDER_DATA_SIZE,
            &error);

        MMI_ASSERT(error == NVRAM_WRITE_SUCCESS);
    }
}


static mmi_ret vappKeyMainmenuEventHandler(mmi_event_struct *event)
{
    switch (event->evt_id)
    {
        case EVT_ID_SRV_APPMGR_INSTALL_PACKAGE:
        case EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE:
        case EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE:
		case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT:
            vappKeyMainmenuSetNeedSycn();
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}

static void vappKeyMainmenuSetNeedSycn()
{
    s_vappKeyMainmenuNeedSync = VFX_TRUE;
	g_vapp_key_mainmenu_preinsatll_change = VFX_TRUE;
}

VfxS32 vappKeyMainmenuCalculateOrderCount(mmi_app_package_name_struct *orderList)
{
    VfxS32 orderCount = VAPP_KEY_MAINMENU_SAVED_DATA_COUNT;
    for (VfxS32 i = 0; i < VAPP_KEY_MAINMENU_SAVED_DATA_COUNT - 1; ++i)
    {
        if (strncmp(orderList[i], "", MMI_APP_NAME_MAX_LEN) == 0)
        {
            if (strncmp(orderList[i + 1], "", MMI_APP_NAME_MAX_LEN) == 0)
            {
                orderCount = i;
                break;
            }
        }
    }
    return orderCount;
}

VfxS32 vappKeyMainmenuLoadData(mmi_app_package_name_struct * allOrderData, VfxBool * pIsNeedResetOrder)
{
    mmi_app_package_name_struct * orderList = allOrderData;
    mmi_app_package_name_struct * barOrderList = allOrderData;

    U8 * readBufferPointer = (U8*)allOrderData;
    for (VfxS32 i = 0; i < NVRAM_EF_VAPP_KMM_ORDER_DATA_TOTAL; ++i)
    {
        S16 error;

        ReadRecord(
            NVRAM_EF_VAPP_KMM_ORDER_DATA_LID,
            1+i,
            readBufferPointer + NVRAM_EF_VAPP_KMM_ORDER_DATA_SIZE * i,
            NVRAM_EF_VAPP_KMM_ORDER_DATA_SIZE,
            &error);

        MMI_ASSERT(error == NVRAM_READ_SUCCESS);
    }

    VfxS32 orderCount = vappKeyMainmenuCalculateOrderCount(orderList);
    
    VfxBool isNeedResetOrder = VFX_FALSE;
    if ( (orderCount == 0) && (strncmp(barOrderList[0], "", MMI_APP_NAME_MAX_LEN) == 0) )
    {
        isNeedResetOrder = VFX_TRUE;
    }

    if (isNeedResetOrder)
    {
        VfxS32 i = 0;
        orderCount = 0;
        VfxS32 countInPage = 0;
        while (i < vappKeyMainmenuDefaultOrderCount)
        {
            if (countInPage == vappKeyMainmenuGetCellCountInPage() )
            {
                strncpy(orderList[orderCount], "", MMI_APP_NAME_MAX_LEN - 1);
                ++orderCount;
                countInPage = 0;
            }

            // append
            strncpy(orderList[orderCount], vappKeyMainmenuDefaultOrder[i], MMI_APP_NAME_MAX_LEN - 1);
            ++orderCount;
            ++countInPage;
            ++i;
        }
        orderCount -= 2;
    }

    *pIsNeedResetOrder = isNeedResetOrder;

    return orderCount;
}

static VfxU32 getAppTypeOrder(mmi_app_package_name_struct appName)
{
    srv_appmgr_app_package_type_enum type = srv_appmgr_get_app_package_type(appName);
    if (type == SRV_APPMGR_NATIVE_APP_PACKAGE_TYPE)
    {
        return 0;
    }
    else if (type == SRV_APPMGR_MRE_APP_PACKAGE_TYPE)
    {
        return 1;
    }
    else if (type == SRV_APPMGR_JAVA_APP_PACKAGE_TYPE)
    {
        return 2;
    }
    return 100;
}

static void sortAppListByDisplayName(mmi_app_package_name_struct * appList, VfxS32 appCount)
{
    // construct the display name mapping
    mmi_ret result;
    WCHAR **names;
    VFX_SYS_ALLOC_MEM(names, sizeof(WCHAR*) * appCount + sizeof(WCHAR) * MMI_APP_NAME_MAX_LEN * appCount);
    memset(names, 0, sizeof(WCHAR) * MMI_APP_NAME_MAX_LEN * appCount);
    names[0] = (WCHAR*)(names + appCount );
    for (VfxS32 iPos = 0; iPos < appCount; ++iPos)
    {
        names[iPos] = names[0] + iPos * MMI_APP_NAME_MAX_LEN;
        result = srv_appmgr_get_app_package_name(appList[iPos], names[iPos]);
        VFX_ASSERT(result != MMI_RET_ERR);
    }

    // selection sort
    for (VfxS32 iPos = 0; iPos < appCount; ++iPos)
    {
        VfxS32 iMin = iPos;
        VfxU32 iMinTypeOrder = getAppTypeOrder(appList[iPos]);
        for (VfxS32 i = iPos + 1; i < appCount; ++i)
        {
            // first compare app type, then compare app display name
            VfxU32 typeOrder = getAppTypeOrder(appList[i]);
            if (typeOrder < iMinTypeOrder)
            {
                iMin = i;
                iMinTypeOrder = typeOrder;
            }
            else if (typeOrder == iMinTypeOrder)
            {
                if (wcsncmp((const wchar_t*)names[iMin], (const wchar_t*)names[i], MMI_APP_NAME_MAX_LEN) > 0)
                {
                    iMin = i;
                }
            }
        }
        // swap(iPos, iMin)
        mmi_app_package_name_struct packageTemp;
        strncpy(packageTemp, appList[iMin], MMI_APP_NAME_MAX_LEN - 1);
        strncpy(appList[iMin], appList[iPos], MMI_APP_NAME_MAX_LEN - 1);
        strncpy(appList[iPos], packageTemp, MMI_APP_NAME_MAX_LEN - 1);

        WCHAR* nameTemp;
        nameTemp = names[iMin];
        names[iMin] = names[iPos];
        names[iPos] = nameTemp;
    }

    VFX_SYS_FREE_MEM(names);
}

// order data utils
VfxS32 vappKeyMainmenuCompactData(mmi_app_package_name_struct * orderList, VfxS32 maxDataCount)
{
    VfxS32 orderCount = 0;
    VfxS32 i1 = 0;
    VfxS32 i2 = 0;
    while (i1 < maxDataCount)
    {
        if (strncmp(orderList[i1], "DELETED", MMI_APP_NAME_MAX_LEN) == 0)
        {
			/*  It is the case :
			 *  "" ,"deleted","","app","",""
			 */
			if(i1 > 1 && strncmp(orderList[i1 - 1], "", MMI_APP_NAME_MAX_LEN) == 0 &&  \
				strncmp(orderList[i1 + 1], "", MMI_APP_NAME_MAX_LEN) == 0)  
				i1 += 1;
            i1 += 1;

            continue;
        }

        if (i1 != i2)
        {
            strncpy(orderList[i2], orderList[i1], MMI_APP_NAME_MAX_LEN - 1);
        }

        // successive empty string means end of data
        if (strncmp(orderList[i2], "", MMI_APP_NAME_MAX_LEN) == 0)
        {
            if (i2 >= 1 && strncmp(orderList[i2 - 1], "", MMI_APP_NAME_MAX_LEN) == 0)
            {
               // i1 += 1;
               // i2 += 1;
                orderCount = i2;
                break;
            }
        }
        i1 += 1;
        i2 += 1;
        orderCount = i2;
    }
    orderCount -= 1;//2;

    // set the remaining to empty string
    if (i1 != i2)
    {
        while (i1 < maxDataCount)
        {
            strncpy(orderList[i1], "", MMI_APP_NAME_MAX_LEN - 1);
            i1 += 1;
        }
    }

    return orderCount;
}

VfxS32 vappKeyMainmenuSyncAppMgr(mmi_app_package_name_struct * allOrderData, VfxS32 initOrderCount, VfxBool isNeedResetOrder, VfxBool * pIsDataDirty)
{
    U32 count = srv_appmgr_get_app_package_num(SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("KM4", SA_start);
#endif
    U32 preCount = srv_appmgr_get_app_package_num(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE);

    U32 totalCount = count + preCount;
    mmi_app_package_name_struct * array = NULL;
    VFX_SYS_ALLOC_MEM(array, sizeof(mmi_app_package_name_struct) * totalCount);
    memset(array, 0, sizeof(mmi_app_package_name_struct) * totalCount);
    mmi_ret result;

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("KM4", SA_stop);
#endif
	/* pre installed app set first */
    result = srv_appmgr_get_app_package_list(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE, array, sizeof(mmi_app_package_name_struct) * preCount);
    VFX_ASSERT(result != MMI_RET_ERR);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("KM4", SA_start);
#endif
    result = srv_appmgr_get_app_package_list(SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE, array + preCount, sizeof(mmi_app_package_name_struct) * count);
    VFX_ASSERT(result != MMI_RET_ERR);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("KM4", SA_stop);
#endif
    if (isNeedResetOrder)
    {
        sortAppListByDisplayName(array + preCount, count);
    }
    // check if every thing in the current order list are in the app list
    VfxS32 countInPage = 0;
    VfxBool isDataDirty = VFX_FALSE;
    for (VfxS32 i = 0; i < initOrderCount; ++i)
    {
        VfxBool found = VFX_FALSE;
        if (strncmp(allOrderData[i], "", MMI_APP_NAME_MAX_LEN) == 0)
        {
            countInPage = 0;
            continue;
        }

        for (VfxU32 j = 0; j < totalCount; ++j)
        {
            if (strncmp(allOrderData[i], array[j], MMI_APP_NAME_MAX_LEN) == 0)
            {
                strncpy(array[j], "ADDED", MMI_APP_NAME_MAX_LEN - 1);
                found = VFX_TRUE;
                break;
            }
        }

        if (!found)
        {
            if (strncmp(allOrderData[i], "DELETED", MMI_APP_NAME_MAX_LEN) != 0)
            {
                strncpy(allOrderData[i], "DELETED", MMI_APP_NAME_MAX_LEN - 1);
                isDataDirty = VFX_TRUE;
            }
        }
        else
        {
            ++countInPage;
        }
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("KM4", SA_start);
#endif

    // append apps not in the order list
    mmi_app_package_name_struct * orderList = allOrderData;
   // VfxS32 newOrderCount = initOrderCount;
	VfxS32 newOrderCount = vappKeyMainmenuCompactData(orderList, VAPP_KEY_MAINMENU_SAVED_DATA_COUNT);
    if(isDataDirty) // find new countInpage
    {
		countInPage = 0;
		for (VfxS32 i = 0; i < newOrderCount; ++i)
        {

			if (strncmp(allOrderData[i], "", MMI_APP_NAME_MAX_LEN) == 0)
			{
				countInPage = 0;
				continue;
			}
            ++countInPage;
        }
	}
    for (VfxU32 i = 0; i < totalCount; ++i)
    {

        if (strncmp(array[i], "ADDED", MMI_APP_NAME_MAX_LEN) == 0)
        {
            continue;
        }
		if (strncmp(array[i], "native.mtk.drawer", MMI_APP_NAME_MAX_LEN) == 0)
		{
			continue;
		}
		if (strncmp(array[i], "native.mtk.desktop", MMI_APP_NAME_MAX_LEN) == 0)
		{
			continue;
		}
		if (strncmp(array[i], "native.mtk.keylauncher", MMI_APP_NAME_MAX_LEN) == 0)
		{
			continue;
		}
        if (countInPage >= vappKeyMainmenuGetCellCountInPage() )
        {
            strncpy(orderList[newOrderCount], "", MMI_APP_NAME_MAX_LEN - 1);
            ++newOrderCount;
            countInPage = 0;
        }

		if (VAPP_KEY_MAINMENU_SAVED_DATA_COUNT - newOrderCount <= 1)
		{
			newOrderCount = VAPP_KEY_MAINMENU_SAVED_DATA_COUNT;
			g_vapp_key_mainmenu_show_popup = VFX_TRUE;
			break;
		}
        // append
        strncpy(orderList[newOrderCount], array[i], MMI_APP_NAME_MAX_LEN - 1);
        isDataDirty = VFX_TRUE;
        ++newOrderCount;
        ++countInPage;
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("KM4", SA_stop);
#endif
    VFX_SYS_FREE_MEM(array);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("KM4", SA_start);
#endif
   // newOrderCount = vappKeyMainmenuCompactData(orderList, VAPP_KEY_MAINMENU_SAVED_DATA_COUNT);
    *pIsDataDirty = isDataDirty;
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("KM4", SA_stop);
#endif
    return newOrderCount;
}

void vappKeyMainmenuCheckLoadOrderData()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("KM0", SA_start);
#endif
    VfxBool isNeedResetOrder = VFX_FALSE;

    if (s_vappKeyMainmenuIsFirstLoad)
    {
		MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_VAPP_LAUNCHER_KEY_MM_FIRST_LOAD);
        s_vappKeyMainmenuIsFirstLoad = VFX_FALSE;
        s_vappKeyMainmenuOrderCount = vappKeyMainmenuLoadData(s_vappKeyMainmenuAllOrderData, &isNeedResetOrder);

        vappDrawerCreateCacheAdm();
        
        mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_INSTALL_PACKAGE, vappKeyMainmenuEventHandler, NULL);
        mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE, vappKeyMainmenuEventHandler, NULL);
        mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE, vappKeyMainmenuEventHandler, NULL);
        mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT, vappKeyMainmenuEventHandler, NULL);
    }

    VfxBool dirtyWhenSync = VFX_FALSE;
    if (s_vappKeyMainmenuNeedSync)
    {
		MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_VAPP_LAUNCHER_KEY_MM_SYNC_APPMGR);
        s_vappKeyMainmenuNeedSync = VFX_FALSE;
        mmi_app_package_name_struct *orderList = s_vappKeyMainmenuAllOrderData;
        s_vappKeyMainmenuOrderCount = vappKeyMainmenuCalculateOrderCount(orderList);
        s_vappKeyMainmenuOrderCount = vappKeyMainmenuSyncAppMgr(s_vappKeyMainmenuAllOrderData, s_vappKeyMainmenuOrderCount, isNeedResetOrder, &dirtyWhenSync);
        updateAppDataCache(s_vappKeyMainmenuAllOrderData, s_vappKeyMainmenuOrderCount);
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("KM0", SA_stop);
#endif
}

mmi_app_package_name_struct * vappKeyMainmenuGetAllOrderData()
{
    //VFX_ASSERT(VAPP_DRAWER_SAVED_DATA_COUNT >= (VAPP_DRAWER_MAX_APP_DATA + VAPP_DRAWER_MAX_GROUP_APP_DATA) );

    return s_vappKeyMainmenuAllOrderData;
}

VfxS32 vappKeyMainmenuGetOrderCount()
{
    return s_vappKeyMainmenuOrderCount;
}

#endif // __MMI_VUI_LAUNCHER__

