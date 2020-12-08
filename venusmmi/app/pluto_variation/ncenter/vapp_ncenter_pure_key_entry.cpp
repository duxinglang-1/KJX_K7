/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_ncenter_table.cpp
 *
 * Project:
 * --------
 *  COSMOS Notification Center
 *
 * Description:
 * ------------
 *  
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "Vapp_ncenter_pure_key_entry.h"

#if defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_KEY_ONLY_NCENTER__)

#include "Vapp_ncenter_pure_key.h"
#include "mmi_rp_app_ncenter_def.h"
#include "vfx_app_cat_scr.h"
#include "vapp_ncenter_gprot.h"
#include "vfx_app_scr.h"
#include "vfx_top_level.h"



extern "C"
{
#include "GlobalResDef.h"
#include "bootupsrvgprot.h"
#include "MMIDataType.h" //for MMI_BOOL
#include "wgui_include.h"
#include "wgui_categories_util.h"
#include "GeneralSettingSrvGprot.h" // for EVT_ID_SETTING_LANGUAGE_CHANGED
#include "notificationGprot.h"
}

/***************************************************************************** 
 * Static Variable
 *****************************************************************************/
static VappNCenterScr* g_ncenter_small_screen_ptr;
#ifdef __MMI_TOUCH_SCREEN__
extern "C" void mmi_pen_send_event_to_new_screen(void);
#endif
extern "C" void gui_screen_switch_effect_block(MMI_BOOL);
extern "C" void wgui_status_icon_bar_reset_display(wgui_status_icon_bar_enum bar_id);

/*****************************************************************************
 * FUNCTION
 *  vapp_ncenter_disable_leave
 * DESCRIPTION
 *  Venus application test screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ncenter_disable_leave()
{
    VappNCenter *NCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    NCenter->disableLeaveOnScreenChange();
}



/*****************************************************************************
 * FUNCTION
 *  vapp_ncenter_enable_drag
 * DESCRIPTION
 *  Venus application test screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ncenter_enable_drag()
{
    VappNCenter *NCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    NCenter->setDisableDrag(VFX_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  vapp_ncenter_disable_drag
 * DESCRIPTION
 *  Venus application test screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ncenter_disable_drag()
{
    VappNCenter *NCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    NCenter->setDisableDrag(VFX_TRUE);
}

static void vapp_ncenter_pen_up_hdlr(mmi_pen_point_struct pos)
{
    mmi_frm_nmgr_alert_struct alert_info;

    memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct)); 

    alert_info.app_id = APP_NCENTER; 
    alert_info.scen_id = MMI_SCENARIO_ID_DEFAULT;

    alert_info.event_type = MMI_EVENT_DEFAULT; 

    alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_BAR_MASK; 
    alert_info.behavior_mask = FORCE_STATUS_BAR; 
    alert_info.status_bar_para.status_bar_type =MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
    alert_info.status_bar_para.display_string = (WCHAR*)GetString(STR_ID_VAPP_NCENTER_OOM);
    alert_info.alert_option= MMI_FRM_NMGR_DISABLE_TONE | MMI_FRM_NMGR_DISABLE_VIB;

    mmi_frm_nmgr_alert(&alert_info); 



    mmi_frm_scrn_close(GRP_ID_ROOT, SCR_ID_NCENTER);  
}


/*****************************************************************************
 * FUNCTION
 *  vapp_ncenter_entry_small_screen
 * DESCRIPTION
 *  Venus application test screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ncenter_entry_small_screen(void)
{
    VfxU16 entry_flag = 0xffff;
    S16 error;

    if (!mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_ID_NCENTER, vapp_ncenter_leave_small_screen, (FuncPtr)vapp_ncenter_entry_small_screen, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    WriteValue(NVRAM_NCENTER_PURE_KEY_IS_ENTERED, &entry_flag, DS_SHORT, &error);
    wgui_status_icon_bar_hide_warning_info();

    gui_screen_switch_effect_block(MMI_TRUE); //disable SSE
    set_small_screen();

    /* Enter the APP category screen */
    if (vfx_sys_mem_config_is_vrt_able_to_run(150 * 1024))
    {
        VfxAppCatScr::initalizeWithScrAsmSize(150 * 1024);
    
        VFX_OBJ_CREATE(
            g_ncenter_small_screen_ptr, 
            VappNCenterScr, 
            VfxAppCatScr::getContext());
    }
    else
    {       
#ifdef __MMI_TOUCH_SCREEN__
        mmi_pen_register_up_handler(vapp_ncenter_pen_up_hdlr);
#endif
    } 

}


/*****************************************************************************
 * FUNCTION
 *  vtst_main_leave
 * DESCRIPTION
 *  Venus application test screen exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ncenter_leave_small_screen(void)
{
    if (g_ncenter_small_screen_ptr)
    {
        /* Leave the APP category screen */
        VFX_OBJ_CLOSE(g_ncenter_small_screen_ptr);
        g_ncenter_small_screen_ptr = NULL;
        VfxAppCatScr::deinitalize();
    }

    ExitCategoryFunction = reset_small_screen;
    gui_screen_switch_effect_block(MMI_TRUE); //disable SSE

}



/*****************************************************************************
 * FUNCTION
 *  vapp_ncenter_is_entered
 * DESCRIPTION
 *  check ncenter is active
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL vapp_ncenter_is_entered(void)
{
   VappNCenter *NCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
   return NCenter->getNCenterEntered();
}


/*****************************************************************************
* FUNCTION
*  vapp_ncenter_pure_key_routing_cb
* DESCRIPTION
*  This function is EVT_ID_PRE_KEY_EVT_ROUTING events call back function
*
* PARAMETERS
*  evt                   :[IN] key event  
* RETURNS
*  MMI_RET_OK
*****************************************************************************/
mmi_ret vapp_ncenter_pure_key_routing_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
    VappNCenter *NCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(key_evt->evt_id == EVT_ID_PRE_KEY_EVT_ROUTING);

    if (wgui_status_icon_bar_is_display(WGUI_STATUS_ICON_BAR_H_BAR) == MMI_FALSE)
    {
        return MMI_RET_OK;
    }

    if (NCenter->getNCenterEntered() || NCenter->getDisableDrag() || !srv_bootup_is_completed())
    {
        return MMI_RET_OK;
    }

    if (KEY_LSK == key_evt->key_code)
    {
        if (KEY_LONG_PRESS == key_evt->key_type)
        {
            MMI_ID group_id, scrn_id;

            vapp_ncenter_entry(NULL);

            mmi_frm_get_active_scrn_id(&group_id, &scrn_id);
            if (g_ncenter_small_screen_ptr == NULL && (scrn_id == SCR_ID_NCENTER))
            {
                mmi_pen_point_struct pos = {0};
                vapp_ncenter_pen_up_hdlr(pos);
            }
        }

        if (g_ncenter_small_screen_ptr)
        {
            NCenter->entryByKey(key_evt->key_type);
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_ncenter_entry
 * DESCRIPTION
 *  Venus application test screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ncenter_entry(void* handle)
{
    VappNCenter *NCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);

    if (!NCenter->getNCenterEntered() && !NCenter->getDisableDrag() && srv_bootup_is_completed())
    {
        mmi_group_event_struct evt;
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_NCENTER_DRAG);
        MMI_ID groupId, scrnId;
        mmi_frm_get_active_scrn_id(&groupId, &scrnId);

        if (MMI_RET_ERR != mmi_frm_send_event_to_group(groupId, &evt) && MMI_FRM_CB_EMIT_EVENT(&evt) != MMI_RET_ERR)
        {
            // close previous one if re-entry
            mmi_frm_scrn_close(GRP_ID_ROOT, SCR_ID_NCENTER);
#ifdef __MMI_TOUCH_SCREEN__
            mmi_pen_send_event_to_new_screen();
#endif
            mmi_frm_send_incomplete_key_event_to_new_screen(MMI_TRUE);
            vapp_ncenter_entry_small_screen();
        }
    }

}


mmi_ret vapp_ncenter_pure_key_bootup_handler(mmi_event_struct *evt)
{
    VfxS16 error;
    VfxU16 entry_flag;
    
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_BOOTUP_COMPLETED:
        case EVT_ID_SETTING_LANGUAGE_CHANGED:
            {
                ReadValue(NVRAM_NCENTER_PURE_KEY_IS_ENTERED, &entry_flag, DS_SHORT, &error);
                if (entry_flag != 0xFFFF)
                {
                    wgui_status_icon_bar_show_warning_info(get_string(STR_ID_VAPP_NCENTER_USAGE_HINT));
                }
            }
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}

#endif /* defined(__MMI_NCENTER_SUPPORT__) */
