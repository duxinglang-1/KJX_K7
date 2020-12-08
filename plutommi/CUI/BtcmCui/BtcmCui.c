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
 * BtcmCui.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for MMI BT CM common UI function body
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __BT_MMI_CUI_C__
#define __BT_MMI_CUI_C__
#include "MMI_features.h"

/*******************************************************************************
* Include Header File
*******************************************************************************/
#ifdef __MMI_BT_SUPPORT__
#include "BtcmSrvGprot.h" 
#include "BTMMIScrGprots.h"
#include "BTMMIScr.h"
#include "BtcmCui.h"
#include "BtcmCuiGprot.h"
#include "UcmSrvGprot.h"

/* menu CUI */
#include "MenuCuiGprot.h"
/* editor CUI */
#include "FSEditorCuiGprot.h"
#include "BthSCOPathSrvGProt.h"

#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "kal_general_types.h"
#include "AlertScreen.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "string.h"
#include "bt_a2dp_base_struct.h"

/*******************************************************************************
* Structure Define
*******************************************************************************/

/*******************************************************************************
* Macro Define
*******************************************************************************/

/*******************************************************************************
* Function Declaration
*******************************************************************************/

/*******************************************************************************
* External Function Declaration
*******************************************************************************/

/*******************************************************************************
* Function Realization 
*******************************************************************************/

/* power on confirm screen common UI */
/*****************************************************************************
 * FUNCTION
 *  cui_bt_power_on_create
 * DESCRIPTION
 *  This function is to create power on confirm screen common UI
 *  if the common UI is unable to entry, it will return GRP_ID_INVALID
 *  caller need to check the returned group id to see if the common UI can be entry
 * PARAMETERS
 *  parent_gid : parent or caller id
 * RETURNS
 *  mmi_id        return GRP_ID_BT_CM_POWER_ON_CNF, which is power on confirm group id
 *                or return GRP_ID_INVALID if common UI can not be entry
 *****************************************************************************/
mmi_id cui_bt_power_on_create(mmi_id parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id g_id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SWITCH_POWER_OFF ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_INQ_AUDIO_DEV ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_OPT ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL_ALL ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_INQ_ALL_DEV ||
        // #ifdef __MMI_SIMAP_SUPPORT__
        // g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SIMAP_SET ||
        // #endif  // __MMI_SIMAP_SUPPORT__
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SET ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SET_DEV_NAME ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SET_VISIBILITY ||        
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SPECIFIC_DEV ||
#ifdef __MMI_BT_AUTHORIZE__
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_AUTHORIZE_REJECT  ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_UNBLOCK||
#endif /* __MMI_BT_AUTHORIZE__ */
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_CONNECT_AUDIO ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_RELEASE_AUDIO_DEV_BEFORE_CONNECT ||
        mmi_frm_scrn_is_present(GRP_ID_BT_CM_POWER_ON_CNF, SCR_BT_POWER_ON_CNF, MMI_FRM_NODE_ALL_FLAG)||
        mmi_frm_scrn_is_present(g_mmi_bt_scr_cntx.main_gid, SCR_BT_POWER_ON_CNF, MMI_FRM_NODE_ALL_FLAG) || 
        g_mmi_bt_scr_cntx.pwr_cnf_cui_state == MMI_TRUE ||
        g_mmi_bt_scr_cntx.device_select_cui_state == MMI_TRUE)
    {
        mmi_popup_display_ext(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            NULL);
    }
    else
    {
        g_id = mmi_frm_group_create(parent_gid, GRP_ID_BT_CM_POWER_ON_CNF, cui_bt_power_on_proc, &g_mmi_bt_scr_cntx);
        g_mmi_bt_scr_cntx.main_gid = GRP_ID_BT_CM_POWER_ON_CNF;
        g_mmi_bt_scr_cntx.pwr_cnf_cui_state = MMI_TRUE;
        g_mmi_bt_scr_cntx.pwf_cnf_cui_notify_flag = MMI_FALSE;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_CUI_BT_POWER_ON_CREATE, parent_gid, g_id);
    
    return g_id;
}


/*****************************************************************************
 * FUNCTION
 *  cui_bt_power_on_run
 * DESCRIPTION
 *  This function is to run power on confirm screen common UI
 *  It will entry a screen group and entry power on confirm screen
 * PARAMETERS
 *  cui_id : common UI ID
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret cui_bt_power_on_run(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_BT_G7_CUI_BT_POWER_ON_RUN,
        cui_id,
        g_mmi_bt_scr_cntx.pwr_cnf_cui_state);

    MMI_ASSERT(g_mmi_bt_scr_cntx.pwr_cnf_cui_state);

    mmi_frm_group_enter(GRP_ID_BT_CM_POWER_ON_CNF, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_bt_display_power_on_confirm(cui_id);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_bt_power_on_result_hdlr
 * DESCRIPTION
 *  This function is to handle power on confirm result, and return to parent
 * PARAMETERS
 *  result : the result of power on confirm
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bt_power_on_result_hdlr(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_bt_cm_power_on_result_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_CUI_BT_CM_POWER_ON_RESULT);
    evt.result = result;
    evt.gid = GRP_ID_BT_CM_POWER_ON_CNF;
    mmi_frm_group_post_to_parent(GRP_ID_BT_CM_POWER_ON_CNF, (mmi_group_event_struct*)&evt);

    g_mmi_bt_scr_cntx.pwf_cnf_cui_notify_flag = MMI_TRUE;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_CUI_BT_POWER_ON_RESULT_HDLR, result);
}


/*****************************************************************************
 * FUNCTION
 *  cui_bt_power_on_close
 * DESCRIPTION
 *  This function is to close power on confirm common UI
 * PARAMETERS
 *  cui_gid : common UI group ID
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bt_power_on_close(mmi_id cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_BT_G7_CUI_BT_POWER_ON_CLOSE,
        cui_gid,
        g_mmi_bt_scr_cntx.pwr_cnf_cui_state);

    g_mmi_bt_scr_cntx.pwr_cnf_cui_state = MMI_FALSE;
    //if (cui_gid == 0)
    //{
    //    cui_gid = GRP_ID_BT_CM_POWER_ON_CNF;
    //}

    mmi_frm_group_close(cui_gid);
}


/*****************************************************************************
 * FUNCTION
 *  cui_bt_power_on_proc
 * DESCRIPTION
 *  This function is to handle event from framework on power on confirm common UI
 * PARAMETERS
 *  evt : mmi event
 * RETURNS
 *  mmi_ret     return MMI_RET_OK
 *****************************************************************************/
mmi_ret cui_bt_power_on_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        {
            mmi_bt_entry_power_on_confirm_del_cb();
            if (g_mmi_bt_scr_cntx.pwr_cnf_cui_state && 
                (g_mmi_bt_scr_cntx.pwf_cnf_cui_notify_flag == MMI_FALSE))
            {
                cui_bt_power_on_result_hdlr(MMI_FALSE);
            }

            g_mmi_bt_scr_cntx.main_gid = 0;
            g_mmi_bt_scr_cntx.pwr_cnf_cui_state = MMI_FALSE;
            g_mmi_bt_scr_cntx.pwf_cnf_cui_notify_flag = MMI_FALSE;
        }
        break;
    }

    return MMI_RET_OK;
}


/* device select screen common UI */
/*****************************************************************************
 * FUNCTION
 *  cui_bt_device_select_screen_create
 * DESCRIPTION
 *  This function is to create device select screen common UI
 *  if the common UI is unable to entry, it will return GRP_ID_INVALID
 *  caller need to check the returned group id to see if the common UI can be entry
 * PARAMETERS
 *  parent_gid : parent or caller id
 * RETURNS
 *  mmi_id        return GRP_ID_BT_CM_SELECT_DEVICE, which is device select screen group id
 *                or return GRP_ID_INVALID if common UI can not be entry 
 *****************************************************************************/
mmi_id cui_bt_device_select_screen_create(mmi_id parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_id g_id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parent_gid != GRP_ID_BT_CM)
    {
        if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SWITCH_POWER_OFF ||
            g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_INQ_AUDIO_DEV ||
            g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_OPT ||
            g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL ||
            g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL_ALL ||
            g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_INQ_ALL_DEV ||
            // #ifdef __MMI_SIMAP_SUPPORT__
            // g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SIMAP_SET ||
            // #endif  // __MMI_SIMAP_SUPPORT__
            g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SET ||
            g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SET_DEV_NAME ||
            g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SET_VISIBILITY ||        
            g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SPECIFIC_DEV ||
#ifdef __MMI_BT_AUTHORIZE__
            g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_AUTHORIZE_REJECT  ||
            g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_UNBLOCK||
#endif /* __MMI_BT_AUTHORIZE__ */
            g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_CONNECT_AUDIO ||
            g_mmi_bt_scr_cntx.flag & MMI_BT_RELEASE_AUDIO_DEV_BEFORE_CONNECT ||
            g_mmi_bt_scr_cntx.device_select_cui_state == MMI_TRUE ||
            g_mmi_bt_scr_cntx.pwr_cnf_cui_state == MMI_TRUE ||
            mmi_frm_scrn_is_present(GRP_ID_BT_CM_POWER_ON_CNF, SCR_BT_POWER_ON_CNF, MMI_FRM_NODE_ALL_FLAG)||
            mmi_frm_scrn_is_present(g_mmi_bt_scr_cntx.main_gid, SCR_BT_POWER_ON_CNF, MMI_FRM_NODE_ALL_FLAG) ||
            mmi_frm_group_is_present(g_mmi_bt_scr_cntx.mydev_gid)
        )
        {
            mmi_popup_display_ext(
                STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
                MMI_EVENT_FAILURE,
                NULL);
            
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_CUI_BT_DEVICE_SELECT_SCREEN_CREATE, parent_gid, g_id);
            return GRP_ID_INVALID;
        }
        // #ifdef __MMI_SIMAP_SUPPORT__
        //         /* prohibited by simap, shall deactivate simap first */
        //         else if (srv_bt_cm_is_simap_activate())
        //         {
        //             mmi_bt_popup_prohibited_by_simap();
        //             MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_CUI_BT_DEVICE_SELECT_SCREEN_CREATE, parent_gid, g_id);
        //             return GRP_ID_INVALID;
        //         }
        // #endif //__MMI_SIMAP_SUPPORT__
#ifdef __MMI_BT_AUDIO_SUPPORT__
        else if (srv_btsco_is_sco_open() &&
                 srv_ucm_is_any_call())
        {
            mmi_bt_popup_operation_not_allowed();
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_CUI_BT_DEVICE_SELECT_SCREEN_CREATE, parent_gid, g_id);
            return GRP_ID_INVALID;
        }
#endif
    }
   
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_CUI_BT_DEVICE_SELECT_SCREEN_CREATE, parent_gid, g_id);
        return GRP_ID_INVALID;
    }

    if (parent_gid == GRP_ID_BT_CM)
    {
        g_mmi_bt_scr_cntx.device_select_cui_state = MMI_FALSE;
    }
    else
    {
        g_mmi_bt_scr_cntx.device_select_cui_state = MMI_TRUE;
    }

    g_id = mmi_frm_group_create(
        parent_gid,
        GRP_ID_BT_CM_SELECT_DEVICE,
        cui_bt_device_select_screen_proc,
        &g_mmi_bt_scr_cntx);
    g_mmi_bt_scr_cntx.mydev_gid = GRP_ID_BT_CM_SELECT_DEVICE;
    g_mmi_bt_scr_cntx.dev_select_cui_notify_flag = MMI_FALSE;
    
    /* set default value */
    g_mmi_bt_scr_cntx.dev_cod_mask = 0;
    g_mmi_bt_scr_cntx.dev_service_id = 0;
    g_mmi_bt_scr_cntx.specific_hilight_dev.nap = 0;
    g_mmi_bt_scr_cntx.specific_hilight_dev.uap = 0;
    g_mmi_bt_scr_cntx.specific_hilight_dev.lap = 0;
    g_mmi_bt_scr_cntx.dev_select_option_flag = CUI_BT_CM_DEVICE_SELECT_OPTION_SELECT;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_CUI_BT_DEVICE_SELECT_SCREEN_CREATE, parent_gid, g_id);    

    return g_id;
}


/*****************************************************************************
 * FUNCTION
 *  cui_bt_device_select_screen_set_mask
 * DESCRIPTION
 *  This function is to set cod bit mask and service id on device select screen 
 * PARAMETERS
 *  cui_id : common UI id
 *  cod_bit_mask : cod bit mask
 *  service_id  : service id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bt_device_select_screen_set_mask(mmi_id cui_id, U32 cod_bit_mask, U32 service_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_CUI_BT_DEVICE_SELECT_SCREEN_SET_MASK, cod_bit_mask, service_id);    

    g_mmi_bt_scr_cntx.dev_cod_mask = cod_bit_mask;
    g_mmi_bt_scr_cntx.dev_service_id = service_id;
}


/*****************************************************************************
 * FUNCTION
 *  cui_bt_device_select_screen_set_default_device
 * DESCRIPTION
 *  This function is to set default device
 * PARAMETERS
 *  cui_id : common UI id
 *  nap : device address
 *  uap : device address 
 *  lap : device address 
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bt_device_select_screen_set_default_device(mmi_id cui_id, U32 lap, U8 uap, U16 nap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_CUI_BT_DEVICE_SELECT_SCREEN_SET_DEFAULT_DEVICE, lap, uap, nap);    

    g_mmi_bt_scr_cntx.specific_hilight_dev.lap = lap;
    g_mmi_bt_scr_cntx.specific_hilight_dev.uap = uap;
    g_mmi_bt_scr_cntx.specific_hilight_dev.nap = nap;    
}


/*****************************************************************************
 * FUNCTION
 *  cui_bt_device_select_screen_set_option_flag
 * DESCRIPTION
 *  This function is to set flag, 
 *  it¡¦s for show the LSK option and option menu, use bit mask of bt_cm_device_select_option_enum
 * PARAMETERS
 *  cui_id : common UI id
 *  flag : flag to set
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bt_device_select_screen_set_option_flag(mmi_id cui_id, U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_CUI_BT_DEVICE_SELECT_SCREEN_SET_OPTION_FLAG, flag);    

    g_mmi_bt_scr_cntx.dev_select_option_flag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  cui_bt_device_select_screen_run
 * DESCRIPTION
 *  This function is to run device select screen common UI
 *  It will entry a screen group and entry device select screen
 * PARAMETERS
 *  cui_id : common UI ID
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret cui_bt_device_select_screen_run(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_id menu_gid;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_BT_G7_CUI_BT_DEVICE_SELECT_SCREEN_RUN,
        cui_id,
        g_mmi_bt_scr_cntx.device_select_cui_state);

    mmi_frm_group_enter(GRP_ID_BT_CM_SELECT_DEVICE, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_bt_entry_mydev_menu();

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_bt_device_set_default_hdlr
 * DESCRIPTION
 *  This function is to set default device, and return to parent 
 * PARAMETERS
 *  result : result of set default device
 *  lap : device address
 *  uap : device address
 *  nap : device address
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bt_device_set_default_hdlr(MMI_BOOL result, U32 lap, U8 uap, U16 nap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_bt_cm_device_select_result_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_CUI_BT_CM_DEFAULT_DEVICE);
    evt.result = result;
    evt.lap = lap;
    evt.uap = uap;    
    evt.nap = nap;    
    evt.gid = GRP_ID_BT_CM_SELECT_DEVICE;
    mmi_frm_group_send_to_parent(GRP_ID_BT_CM_SELECT_DEVICE ,(mmi_group_event_struct*)&evt);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_CUI_BT_DEVICE_SET_DEFAULT_HDLR, result, lap, uap, nap);
}


/*****************************************************************************
 * FUNCTION
 *  cui_bt_device_select_hdlr
 * DESCRIPTION
 *  This function is to handle device select screen result, and return to parent
 * PARAMETERS
 *  result : the result of device select
 *  lap : device address
 *  uap : device address
 *  nap : device address
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bt_device_select_hdlr(MMI_BOOL result, U32 lap, U8 uap, U16 nap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_bt_cm_device_select_result_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_CUI_BT_CM_DEVICE_SELECT);
    evt.result = result;
    evt.lap = lap;
    evt.uap = uap;    
    evt.nap = nap;    
    evt.gid = GRP_ID_BT_CM_SELECT_DEVICE;
    mmi_frm_group_post_to_parent(GRP_ID_BT_CM_SELECT_DEVICE, (mmi_group_event_struct*)&evt);

    g_mmi_bt_scr_cntx.dev_select_cui_notify_flag = MMI_TRUE;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_CUI_BT_DEVICE_SELECT_HDLR, result, lap, uap, nap);    
}


/*****************************************************************************
 * FUNCTION
 *  cui_bt_device_select_screen_close
 * DESCRIPTION
 *  This function is to close device select screen common UI
 * PARAMETERS
 *  cui_gid : common UI group ID
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bt_device_select_screen_close(mmi_id cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_BT_G7_CUI_BT_DEVICE_SELECT_SCREEN_CLOSE,
        cui_gid,
        g_mmi_bt_scr_cntx.device_select_cui_state);
    g_mmi_bt_scr_cntx.device_select_cui_state = MMI_FALSE;

    //if (cui_gid == 0)
    //{
    //    cui_gid = GRP_ID_BT_CM_SELECT_DEVICE;
    //}

    mmi_frm_group_close(cui_gid);

    //g_mmi_bt_scr_cntx.mydev_gid = 0;
    //g_mmi_bt_scr_cntx.dev_cod_mask = 0;
    //g_mmi_bt_scr_cntx.dev_service_id = 0;
    //g_mmi_bt_scr_cntx.specific_hilight_dev.nap = 0;
    //g_mmi_bt_scr_cntx.specific_hilight_dev.uap = 0;
    //g_mmi_bt_scr_cntx.specific_hilight_dev.lap = 0;
    //g_mmi_bt_scr_cntx.dev_select_option_flag = 0;
}


/*****************************************************************************
 * FUNCTION
 *  cui_bt_device_select_screen_proc
 * DESCRIPTION
 *  This function is to handle event from framework on device select screen
 * PARAMETERS
 *  evt : mmi event
 * RETURNS
 *  mmi_ret     return MMI_RET_OK
 *****************************************************************************/
mmi_ret cui_bt_device_select_screen_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        /* menu CUI related events */
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_LIST_EXIT:
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
            mmi_bt_menu_cui_proc(evt);
            break;
            
        /* editor CUI related events*/
        case EVT_ID_CUI_FSEDITOR_ABORT:
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:    
            mmi_bt_editor_cui_proc(evt);
            break;
               
        case EVT_ID_GROUP_DEINIT:
            { 
                if (g_mmi_bt_scr_cntx.device_select_cui_state == MMI_TRUE &&
                    g_mmi_bt_scr_cntx.dev_select_cui_notify_flag == MMI_FALSE)
                {
                    cui_bt_device_select_hdlr(MMI_FALSE, 0, 0, 0);
                }
                else
                {
                    mmi_frm_group_close(GRP_ID_BT_CM_SELECT_DEVICE);
                }

                g_mmi_bt_scr_cntx.device_select_cui_state = MMI_FALSE;
                g_mmi_bt_scr_cntx.dev_select_cui_notify_flag = MMI_FALSE;

                g_mmi_bt_scr_cntx.mydev_gid = 0;
                g_mmi_bt_scr_cntx.dev_cod_mask = 0;
                g_mmi_bt_scr_cntx.dev_service_id = 0;
                g_mmi_bt_scr_cntx.specific_hilight_dev.nap = 0;
                g_mmi_bt_scr_cntx.specific_hilight_dev.uap = 0;
                g_mmi_bt_scr_cntx.specific_hilight_dev.lap = 0;
                g_mmi_bt_scr_cntx.dev_select_option_flag = 0;
            }
            break;
    }

    return MMI_RET_OK;
}

#endif/*__MMI_BT_SUPPORT__*/

#endif /*__BT_MMI_CUI_C__*/

