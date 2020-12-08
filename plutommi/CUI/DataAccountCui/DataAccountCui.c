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
 *   DataAccountCui.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Data account Common UI source file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#if defined(__TCPIP__)
/*******************************************************************************
* Include Header File
*******************************************************************************/
#include "MMI_features.h"
#include "DataAccountCui.h"
#include "WlanCuiGprot.h"
#include "DtcntSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "MMIDataType.h"
#include "DataAccountDef.h"
#include "DataAccountGProt.h"
#include "DataAccountStruct.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_dataaccount_def.h"
#include "kal_general_types.h"
#include "DataAccountCuiGprot.h"
#include "DtcntSrvIprot.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "cbm_api.h"
#include "cbm_consts.h"
#include "abm_api.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "CustDataRes.h"
#include "wgui_categories_list.h"
#include "wgui_categories_util.h"
#include "wgui_fixed_menus.h"
#include "GlobalConstants.h"
#include "NetSetSrvGprot.h"
#include "NetSetAppGprot.h"
#include "DataAccountEnum.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "mmi_frm_nvram_gprot.h"
#include "MenuCuiGprot.h"
#include "Dataaccountprot.h"
#include "CommonScreens.h"
#include "mmi_frm_utility_gprot.h"
#include "DataaccountProt.h"
#include "AlertScreen.h"
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
#include "NetSetAppGprot.h"
#endif

/*******************************************************************************
* Structure Define
*******************************************************************************/

/*******************************************************************************
* Macro Define
*******************************************************************************/

/*******************************************************************************
* Global Variable Declaration
*******************************************************************************/
U8 g_cui_dtcnt_sel_index;

cui_dtcnt_select_account_option_struct  g_cui_dtcnt_sel_acct[CUI_DTCNT_MAX_BEARER_LIST_NUM];

/* this struct array is used to store account name and address for showing list, include CUI and setting */
mmi_dtcnt_comm_disp_name_addr g_comm_disp_name_addr_arr[MMI_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM + MAX_DATA_ACCOUN_CUI_FIX_ITEM];

extern mmi_dtcnt_list_disp_struct g_mmi_dtcnt_list_item[MMI_DTCNT_PROF_MAX_ACCOUNT_NUM];

static const U16 cui_dtcnt_sim_str_id[] = 
{
    STR_GLOBAL_SIM_1,
    STR_GLOBAL_SIM_2,
    STR_GLOBAL_SIM_3,
    STR_GLOBAL_SIM_4,
};

static U8 cui_dtcnt_get_first_entry_highlight_item(U32 acct_id);
static mmi_ret cui_dtcnt_select_group_proc(mmi_event_struct *evt);
S32 cui_dtcnt_get_cntx_index_by_cui_id(mmi_id cui_id);
mmi_ret cui_dtcnt_cbm_normal_list_scrn_proc(mmi_event_struct *evt);
void cui_dtcnt_prepare_list_info(cui_dtcnt_select_account_option_struct *sel_acct);
void cui_dtcnt_prepare_list_info_dual(cui_dtcnt_select_account_option_struct *sel_acct);

static void cui_dtcnt_arrange_account_list(cui_dtcnt_list_disp_struct *prof_list, mmi_dtcnt_comm_disp_name_addr *name_addr_arr,S32 start, S32 end);
MMI_BOOL cui_dtcnt_is_account_use_proxy(U32 accountId);
MMI_BOOL cui_dtcnt_is_account_display(mmi_dtcnt_list_type_enum list_type, cui_dtcnt_select_account_option_struct *sel_acct, mmi_dtcnt_list_disp_struct *acct_info);
void cui_dtcnt_close_all_group(U32 sim_selection);


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_arrange_account_list
 * DESCRIPTION
 *  Arrange the account list in order.
 * PARAMETERS
 *  prof_list    [IN]  profile list
 *  name_addr_arr [IN] account name and address array point which is related to profile list
 *  start        [IN]  start position
 *  end          [IN]  end position
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dtcnt_arrange_account_list(cui_dtcnt_list_disp_struct *prof_list, mmi_dtcnt_comm_disp_name_addr *name_addr_arr,S32 start, S32 end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    S32 size1 = sizeof(cui_dtcnt_list_disp_struct);
    S32 size2 = sizeof(mmi_dtcnt_comm_disp_name_addr);
    cui_dtcnt_list_disp_struct g_account_temp;
    mmi_dtcnt_comm_disp_name_addr name_addr_tmp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (end <= (start + 1))
    {
        return;
    }

    for (i = start; i < end - 1; i++)
    {    
        for(j = i; j < end; j++)
        {
            if (mmi_ucs2cmp((CHAR*)name_addr_arr[i].data_account_name, (CHAR*)name_addr_arr[j].data_account_name) > 0)
            {
                /* the two array is related by the same index */
                memcpy(&g_account_temp, &prof_list[i], size1);
                memcpy(&prof_list[i], &prof_list[j], size1);
                memcpy(&prof_list[j], &g_account_temp, size1);

                memcpy(&name_addr_tmp, &name_addr_arr[i], size2);
                memcpy(&name_addr_arr[i], &name_addr_arr[j], size2);
                memcpy(&name_addr_arr[j], &name_addr_tmp, size2);
            }
        }
    }
}

#ifdef __MMI_WGUI_DISABLE_CSK__ 
/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_main_scrn_csk_hdlr
 * DESCRIPTION
 *  csk hdlr function for main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dtcnt_main_scrn_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, 0);
	evt.evt_id = EVT_ID_WGUI_CSK_CLICK;
    MMI_FRM_CB_EMIT_EVENT(&evt);
}
#endif

#define SELECTION_CUI
/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_show_acct_list_scrn
 * DESCRIPTION
 *  this function is used to show category, only be called when receive EVT_ID_SCRN_ACTIVE event
 * PARAMETERS
 *  evt                 [IN] EVT_ID_SCRN_ACTIVE event 
 *  sel_acct            [IN] select instance
 *  isBearfallback      [IN] is bearer fallback or not
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dtcnt_show_acct_list_scrn(mmi_event_struct *evt, cui_dtcnt_select_account_option_struct *sel_acct, MMI_BOOL isBearfallback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U8 *item_name[MMI_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM + MAX_DATA_ACCOUN_CUI_FIX_ITEM];
    U8 *PopUpDescription[MMI_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM + MAX_DATA_ACCOUN_CUI_FIX_ITEM];
    U16 title, title_icon;
    mmi_frm_scrn_active_evt_struct *active_evt;
    U32 sim_index = 0;
    WCHAR tempStr[DTCNT_DYNAMIC_SIM_NAME_MAX_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    active_evt = (mmi_frm_scrn_active_evt_struct *)evt;
    {
        cui_dtcnt_prepare_list_info(sel_acct); 
        sim_index = mmi_frm_sim_to_index(sel_acct->sim_enum);
        sel_acct->current_item_selected = cui_dtcnt_get_first_entry_highlight_item(sel_acct->sim_account_id[sim_index]);
    }
    
    for (i = 0; i < sel_acct->list_item_number; i++)
    {
        {
            item_name[i] = g_comm_disp_name_addr_arr[i].data_account_name;        
            PopUpDescription[i] = g_comm_disp_name_addr_arr[i].data_account_addr;            
        }
    }

    if (sel_acct->app_icon_id && sel_acct->app_str_id)
    {
        if (!sel_acct->sim_list_existed)
        {
            title = sel_acct->app_str_id;
        }
        else
        {
            title = cui_dtcnt_sim_str_id[sim_index];
        }
        title_icon = sel_acct->app_icon_id; 
    }
    else
    {
        if (!sel_acct->sim_list_existed)
        {
            title = STR_GLOBAL_DATA_ACCOUNT;
        }
        else
        {
            title = cui_dtcnt_sim_str_id[sim_index];
        }
        title_icon = GetRootTitleIcon(sel_acct->app_menu_id); 
    }
#ifndef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    mmi_wcscpy(tempStr, (WCHAR*)GetString(title));
#else
    if (!sel_acct->sim_list_existed)
    {
        mmi_wcscpy(tempStr, (WCHAR*)GetString(title));
    }
    else
    {
        mmi_netset_get_sim_name_with_simx_and_brace(
            mmi_frm_index_to_sim(sim_index),
            tempStr,
            DTCNT_DYNAMIC_SIM_NAME_MAX_LEN * ENCODING_LENGTH);
    }
#endif
    if (sel_acct->list_item_number)
    {
        wgui_list_menu_enable_access_by_shortcut();
        ShowCategory353Screen(
            (U8*)tempStr,
            title_icon,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            sel_acct->list_item_number,
            (U8 **)item_name,
            (U16*)gIndexIconsImageList,
            PopUpDescription,
            0,
            sel_acct->current_item_selected,
            active_evt->gui_buffer);
    #ifndef __MMI_WGUI_DISABLE_CSK__ 
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    #else
        SetCenterSoftkeyFunction(cui_dtcnt_main_scrn_csk_hdlr, KEY_EVENT_UP);
    #endif
    }
    else
    {
        ShowCategory353Screen(
            (U8*)tempStr,
            title_icon,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            sel_acct->list_item_number,
            (U8 **)item_name,
            (U16*)gIndexIconsImageList,
            PopUpDescription,
            0,
            sel_acct->current_item_selected,
            active_evt->gui_buffer);
    #ifndef __MMI_WGUI_DISABLE_CSK__ 
        ChangeCenterSoftkey(0, 0);
    #else
        SetCenterSoftkeyFunction(cui_dtcnt_main_scrn_csk_hdlr, KEY_EVENT_UP);
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_select_sim_account
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dtcnt_select_sim_account(cui_dtcnt_select_account_option_struct *sel_acct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 selected_index = sel_acct->current_item_selected;
    U32 acct_id = sel_acct->list_info[selected_index].profile_id;
    U8 app_id = sel_acct->app_id;
    cbm_sim_id_enum cbm_sim_id = CBM_SIM_ID_SIM1;
    U32 sim_index = 0;
    cui_dtcnt_select_event_result_struct result_evt;
    cui_dtcnt_select_event_any_sim_selected_struct sim_selected_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_index = mmi_frm_sim_to_index(sel_acct->sim_enum);
    cbm_sim_id = (cbm_sim_id_enum)sim_index;
    acct_id = cbm_encode_data_account_id(acct_id, cbm_sim_id, app_id, KAL_FALSE);
    sel_acct->sim_account_id[sim_index] = acct_id;

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DTCNT_APP_SELECT_OK, acct_id);

    MMI_FRM_INIT_GROUP_EVENT((mmi_group_event_struct*)&sim_selected_evt, CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED, sel_acct->curr_cui_id);
    sim_selected_evt.accountId = acct_id;
    sim_selected_evt.selectSim = (cui_dtcnt_sim_enum)sim_index;
    mmi_frm_group_send_to_parent(sel_acct->curr_cui_id, (mmi_group_event_struct*)&sim_selected_evt);

    if (!sel_acct->sim_list_existed)
    {
        MMI_FRM_INIT_GROUP_EVENT((mmi_group_event_struct*)&result_evt, CUI_DTCNT_SELECT_EVENT_RESULT_OK, sel_acct->curr_cui_id);
        mmi_frm_group_send_to_parent(sel_acct->curr_cui_id, (mmi_group_event_struct*)&result_evt);
    }
    else
    {
        mmi_frm_scrn_close_active_id();
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_close_account_list_scr
 * DESCRIPTION
 *  close the current CUI
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dtcnt_close_account_list_scr(cui_dtcnt_select_account_option_struct *sel_acct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dtcnt_select_event_result_struct result_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* return the encode acct id */
    if (sel_acct->sim_list_existed)
    {
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        MMI_FRM_INIT_GROUP_EVENT((mmi_group_event_struct*)&result_evt, CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL, sel_acct->curr_cui_id);
        mmi_frm_group_send_to_parent(sel_acct->curr_cui_id, (mmi_group_event_struct*)&result_evt);
    }
}


/*****************************************************************************
  * FUNCTION
  *  cui_dtcnt_select_close
  * DESCRIPTION
  *  to close data account select group
  * PARAMETERS
  *  cui_gid
  * RETURNS
  *  void
 *****************************************************************************/
void cui_dtcnt_select_close(mmi_id cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = cui_dtcnt_get_cntx_index_by_cui_id(cui_gid);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_DTCNT_SELECTION_CLOSE_INFO, cui_gid, index);

    if (index != -1)
    {
        g_cui_dtcnt_sel_index = 0;
        if (g_cui_dtcnt_sel_acct[index].curr_cui_id)
        {
            mmi_frm_group_close(g_cui_dtcnt_sel_acct[index].curr_cui_id);
        }
        memset(&g_cui_dtcnt_sel_acct[index], 0, sizeof(cui_dtcnt_select_account_option_struct));
    }

}


/*****************************************************************************
 * FUNCTION
 *    cui_dtcnt_select_create
 * DESCRIPTION
 *    to create data account select group
 * PARAMETERS
 *    group_id
 * RETURNS
 *    cui_gid
*****************************************************************************/
mmi_id cui_dtcnt_select_create(mmi_id parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* To find a empty CUI context slot to support multi-instance*/
    if (!mmi_dtcnt_get_ready_status())
    {
        return GRP_ID_INVALID;
    }

    for (i = 0; i < CUI_DTCNT_MAX_BEARER_LIST_NUM; i++)
    {
        if (!g_cui_dtcnt_sel_acct[i].valid)
        {
            break;
        }
    }
    /* If no CUI context, return error */
    if (i == CUI_DTCNT_MAX_BEARER_LIST_NUM)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_DTCNT_SELECTION_CREATE_ERROR);
        return GRP_ID_INVALID;
    }
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_DTCNT_SELECTION_CREATE_INFO, parent_gid, i);

    g_cui_dtcnt_sel_index = i;
    memset(&g_cui_dtcnt_sel_acct[i], 0, sizeof(cui_dtcnt_select_account_option_struct));

    g_cui_dtcnt_sel_acct[i].valid = 1;
    g_cui_dtcnt_sel_acct[i].curr_cui_id = mmi_frm_group_create(parent_gid, GRP_ID_AUTO_GEN, cui_dtcnt_select_group_proc, (void *)&i);
      
    return g_cui_dtcnt_sel_acct[i].curr_cui_id;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_sim_list_scrn_proc
 * DESCRIPTION
 *  proc function for sim list screen
 * PARAMETERS
 *  evt     [IN] 
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret cui_dtcnt_sim_list_scrn_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dtcnt_select_account_option_struct *sel_acct; // get by user data
    U8 *sim_item_name[MMI_SIM_TOTAL];
    U8 *PopUpDescription[MMI_SIM_TOTAL];
    srv_dtcnt_prof_str_info_qry_struct acct_data;
    srv_dtcnt_sim_type_enum sim_type = SRV_DTCNT_SIM_TYPE_1;
    S32 avail_sim_num = 0, highlight_id = 0;
    mmi_frm_scrn_active_evt_struct *active_evt;
    U16 title = 0, title_icon = 0;
    U32 i;
    MMI_BOOL ret;
    cui_dtcnt_select_event_result_struct result_evt;
    cbm_app_info_struct app_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sel_acct = (cui_dtcnt_select_account_option_struct *)evt->user_data;
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            active_evt = (mmi_frm_scrn_active_evt_struct *)evt;
            ret = srv_dtcnt_get_sim_preference(&sim_type);
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_DATA_CONNECTION_SIM_GET_SIM_PREFERENCE, sim_type, ret);
            memset(&app_info, 0, sizeof(cbm_app_info_struct));
            abm_get_registered_app_name((kal_uint8)sel_acct->app_id, &app_info);
            for (i = 0; i < MMI_SIM_TOTAL; i++)
            {
                if (srv_sim_ctrl_is_available(mmi_frm_index_to_sim(i)))
                {
                    sel_acct->avail_sim_enum[avail_sim_num] = mmi_frm_index_to_sim(i);
                #ifndef __MMI_DYNAMIC_SIM_DYNAMIC_UI__                    
                    sim_item_name[avail_sim_num] = (U8*)GetString(cui_dtcnt_sim_str_id[i]);
                #else
                    mmi_netset_get_sim_name_with_simx_and_brace(
                        mmi_frm_index_to_sim(i),
                        (WCHAR*)subMenuData[avail_sim_num],
                        DTCNT_DYNAMIC_SIM_NAME_MAX_LEN * ENCODING_LENGTH);
                    sim_item_name[avail_sim_num] = subMenuData[avail_sim_num];
                #endif
                    acct_data.dest_len = (SRV_DTCNT_PROF_MAX_ACC_NAME_LEN + 1) * ENCODING_LENGTH;
                    acct_data.dest = (CHAR*)hintData[avail_sim_num];
                    ret = srv_dtcnt_get_account_name(
                        sel_acct->sim_account_id[i],
                        &acct_data,
                        SRV_DTCNT_ACCOUNT_PRIMARY);
                    if (!ret)
                    {
                        mmi_ucs2ncpy((CHAR*)hintData[avail_sim_num], (CHAR*)GetString(STR_ID_DTCNT_NO_AVAILABLE_ACCOUNT), (SRV_DTCNT_PROF_MAX_ACC_NAME_LEN + 1) * ENCODING_LENGTH);
                    }
                    PopUpDescription[avail_sim_num] = hintData[avail_sim_num];
                    if (!(app_info.app_type & DTCNT_APPTYPE_MMS))
                    {
                        if (!active_evt->gui_buffer)
                        {
                            if ((srv_dtcnt_sim_type_enum)(i + 1) == sim_type)
                            {
                                highlight_id = avail_sim_num;
                            }
                        }
                    }
                    avail_sim_num ++;
                }
            }
            if (sel_acct->app_icon_id && sel_acct->app_str_id)
            {
                title = sel_acct->app_str_id;
                title_icon = sel_acct->app_icon_id; 
            }
            else
            {
                title = STR_GLOBAL_DATA_ACCOUNT;
                title_icon = GetRootTitleIcon(sel_acct->app_menu_id); 
            }
            wgui_list_menu_enable_access_by_shortcut();
            ShowCategory53Screen(
                title,
                title_icon,
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                avail_sim_num,
                (U8 **)sim_item_name,
                (U16*)gIndexIconsImageList,
                PopUpDescription,
                0,
                highlight_id,
                (U8*)active_evt->gui_buffer);
        #ifndef __MMI_WGUI_DISABLE_CSK__ 
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        #else
            SetCenterSoftkeyFunction(cui_dtcnt_main_scrn_csk_hdlr, KEY_EVENT_UP);
        #endif
            break;
        }
        case EVT_ID_WGUI_LSK_CLICK:
        case EVT_ID_WGUI_CSK_CLICK:
        {
            sel_acct->sim_enum = (mmi_sim_enum)sel_acct->avail_sim_enum[sel_acct->curr_sim_list_index];
            mmi_frm_scrn_create(
                sel_acct->curr_cui_id,
                SCR_ID_DTCNT_CUI_NORMAL_LIST,
                (mmi_proc_func)cui_dtcnt_cbm_normal_list_scrn_proc,
                sel_acct);
            return MMI_RET_KEY_HANDLED;
        }
        case EVT_ID_WGUI_RSK_CLICK:
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DTCNT_APP_SELECT_OK, 0);
            MMI_FRM_INIT_GROUP_EVENT((mmi_group_event_struct*)&result_evt, CUI_DTCNT_SELECT_EVENT_RESULT_OK, sel_acct->curr_cui_id);
            mmi_frm_group_send_to_parent(sel_acct->curr_cui_id, (mmi_group_event_struct*)&result_evt);
            return MMI_RET_KEY_HANDLED;
        }
        case EVT_ID_SCRN_HIGHLIGHT_CHANGE:
        {
            cat_evt_struct *cat_evt = (cat_evt_struct *)evt;
            U32 index = cat_evt->item_index;
            sel_acct->curr_sim_list_index = index;
            return MMI_RET_CHANGED;
        }
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        {
            memset(sel_acct, 0, sizeof(cui_dtcnt_select_account_option_struct));
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_cbm_normal_list_scrn_proc
 * DESCRIPTION
 *  proc function for cui CBM/normal list screen
 * PARAMETERS
 *  evt     [IN] 
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret cui_dtcnt_cbm_normal_list_scrn_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id scr_group_id = 0;
    cui_dtcnt_select_account_option_struct *sel_acct; // get by user data

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sel_acct = (cui_dtcnt_select_account_option_struct *)evt->user_data;
    scr_group_id = sel_acct->curr_cui_id;
    if (scr_group_id)
    {
        g_cui_dtcnt_sel_index = cui_dtcnt_get_cntx_index_by_cui_id(scr_group_id);
    }
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {            
            cui_dtcnt_show_acct_list_scrn(evt, sel_acct, MMI_FALSE);
            break;
        }
        case EVT_ID_WGUI_LSK_CLICK:
        case EVT_ID_WGUI_CSK_CLICK:
        {
            if (sel_acct->list_item_number)
            {
                cui_dtcnt_select_sim_account(sel_acct);
            }
            return MMI_RET_KEY_HANDLED;
        }
        case EVT_ID_WGUI_RSK_CLICK:
        {
            cui_dtcnt_close_account_list_scr(sel_acct);
            return MMI_RET_KEY_HANDLED;
        }
        case EVT_ID_SCRN_HIGHLIGHT_CHANGE:
        {
            cat_evt_struct *cat_evt = (cat_evt_struct *)evt;
            U32 index = cat_evt->item_index;
            sel_acct->current_item_selected = index;
            return MMI_RET_CHANGED;
        }
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        {
            memset(sel_acct, 0, sizeof(cui_dtcnt_select_account_option_struct));
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_is_account_use_proxy
 * DESCRIPTION
 *  check account id use proxy or not
 * PARAMETERS
 *  accountId       [IN] account id
 * RETURNS
 *  MMI_TRUE if the account use proxy, or MMI_FALSE
 *****************************************************************************/
MMI_BOOL cui_dtcnt_is_account_use_proxy(U32 accountId)
{
    MMI_BOOL result = MMI_FALSE;
    srv_dtcnt_prof_proxy_info_struct temp_proxy_info;
    if (MMI_TRUE == srv_dtcnt_get_proxy_info(
                        accountId,
                        &temp_proxy_info,
                        SRV_DTCNT_ACCOUNT_PRIMARY))
    {            
        if (temp_proxy_info.use_proxy)
        {
            result = MMI_TRUE;
        }
        else
        {
            result = MMI_FALSE;
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_is_account_display
 * DESCRIPTION
 *  check account id can be diaplayed in list or not
 * PARAMETERS
 *  list_type       [IN] list type
 *  sel_acct        [IN] select instance
 *  acct_info       [IN] account basic info
 * RETURNS
 *  MMI_TRUE if the account can be displayed, or MMI_FALSE
 *****************************************************************************/
MMI_BOOL cui_dtcnt_is_account_display(mmi_dtcnt_list_type_enum list_type, cui_dtcnt_select_account_option_struct *sel_acct, mmi_dtcnt_list_disp_struct *acct_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim = MMI_SIM1;
    MMI_BOOL ret = MMI_FALSE;
    U8 bearer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_type == MMI_DTCNT_LIST_TYPE_GPRS_USER || 
        list_type == MMI_DTCNT_LIST_TYPE_GPRS_FACTORY)
    {
        bearer = DATA_ACCOUNT_BEARER_GPRS;
    }
    else
    {
        bearer = DATA_ACCOUNT_BEARER_CSD;
    }
    if (!(sel_acct->bearers & bearer && acct_info->bearer_type == bearer))
    {
        return MMI_FALSE;
    }
    if (list_type == MMI_DTCNT_LIST_TYPE_GPRS_USER || 
        list_type == MMI_DTCNT_LIST_TYPE_CSD_USER)
    {
        if(!(acct_info->account_type == SRV_DTCNT_PROF_TYPE_USER_CONF ||
            acct_info->account_type == SRV_DTCNT_PROF_TYPE_OTA_CONF))
        {
            return MMI_FALSE;
        }
    }
    else
    {
        if (!(acct_info->account_type == SRV_DTCNT_PROF_TYPE_FACTORY_CONF ||
            (acct_info->account_type == SRV_DTCNT_PROF_TYPE_SIM_PROF &&
            sel_acct->option & CUI_DTCNT_SELECT_SIM_PROFILE)))
        {
            return MMI_FALSE;
        }
    }

    /* for with proxy or not profile filter */
    if ((sel_acct->option & CUI_DTCNT_SELECT_WITH_PROXY_ONLY) && 
        !(cui_dtcnt_is_account_use_proxy(acct_info->profile_id)))
    {
        return MMI_FALSE;
    }
    if ((sel_acct->option & CUI_DTCNT_SELECT_WITHOUT_PROXY_ONLY) && 
        (cui_dtcnt_is_account_use_proxy(acct_info->profile_id)))
    {
        return MMI_FALSE;
    }

    // check wap_only filter
    if ((sel_acct->option & CUI_DTCNT_SELECT_CONNTYPE_WAP_ONLY) && 
        (acct_info->connection_type == 1))
    {
        return MMI_FALSE;
    }

    /* for wap only http connection type profile filter */
    if (((sel_acct->option & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) && acct_info->connection_type == 1) || 
        ((sel_acct->option & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) == 0))
    {
        sim = mmi_frm_index_to_sim((U32)(acct_info->sim_info - 1));
        if (sim != sel_acct->sim_enum)
        {
            ret = MMI_FALSE;
        }
        else
        {
            if (sel_acct->option & CUI_DTCNT_SELECT_SIM)
            {
                ret = MMI_TRUE;
            }
            else
            {
                switch (sel_acct->sim_selection)
                {
                    case CUI_DTCNT_SELECT_SIM1:
                        if (acct_info->sim_info == SRV_DTCNT_SIM_TYPE_1)
                        {
                            ret = MMI_TRUE;
                        }
                        break;
                    case CUI_DTCNT_SELECT_SIM2:
                        if (acct_info->sim_info == SRV_DTCNT_SIM_TYPE_2)
                        {
                            ret = MMI_TRUE;
                        }
                        break;
                    case CUI_DTCNT_SELECT_SIM3:
                        if (acct_info->sim_info == SRV_DTCNT_SIM_TYPE_3)
                        {
                            ret = MMI_TRUE;
                        }
                        break;
                    case CUI_DTCNT_SELECT_SIM4:
                        if (acct_info->sim_info == SRV_DTCNT_SIM_TYPE_4)
                        {
                            ret = MMI_TRUE;
                        }
                        break;
                    case CUI_DTCNT_SELECT_DUAL_SIM:
                        ret = MMI_TRUE;
                        break;
                    default:
                        ret = MMI_FALSE;
                        break;
                }
            }
        }
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_prepare_list_info
 * DESCRIPTION
 *  To prepare the single or cbm list info for CUI by passing the context index
 * PARAMETERS
 *  cntx_index  [IN]
 *  num        [OUT]
 *  list_info   [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dtcnt_prepare_list_info(cui_dtcnt_select_account_option_struct *sel_acct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 list_num = 0;
    srv_dtcnt_prof_str_info_qry_struct acct_data;
    S32 start = 0;
    U32 i, j;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_comm_disp_name_addr_arr, 0, sizeof(g_comm_disp_name_addr_arr));
    // gprs/csd user defined profile
    // gprs/csd factory config profile
    for (j = 0; j < MMI_DTCNT_LIST_TYPE_TOTAL; j++)
    {
        // When no sim card available
        if (!srv_sim_ctrl_any_sim_is_available())
        {
            break;
        }
        start = list_num;
        /* for GPRS user defined profile */
        for (i = 0; i < MMI_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
        {
            {
                if (cui_dtcnt_is_account_display((mmi_dtcnt_list_type_enum)j, sel_acct, &g_mmi_dtcnt_list_item[i]))
                {
                    sel_acct->list_info[list_num].profile_id = g_mmi_dtcnt_list_item[i].profile_id;

                    //mmi_dtcnt_get_full_account_name(g_mmi_dtcnt_list_item[i].profile_id, (PS8)g_comm_disp_name_addr_arr[list_num].data_account_name, MAX_DATA_ACCOUNT_NAME_LEN + DATA_ACCOUNT_NAME_SUFFIX_LEN + 1, MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
                    acct_data.dest_len = (SRV_DTCNT_PROF_MAX_ACC_NAME_LEN + 1) * ENCODING_LENGTH;
                    acct_data.dest = (CHAR*)g_comm_disp_name_addr_arr[list_num].data_account_name;
                    srv_dtcnt_get_account_name(g_mmi_dtcnt_list_item[i].profile_id,
                                      &acct_data,
                                      SRV_DTCNT_ACCOUNT_PRIMARY);

                    acct_data.dest_len = MAX_DTCNT_LIST_ADDR_LEN * ENCODING_LENGTH;
                    acct_data.dest = (CHAR*)g_comm_disp_name_addr_arr[list_num].data_account_addr;

                    if (j == MMI_DTCNT_LIST_TYPE_GPRS_USER || 
                        j == MMI_DTCNT_LIST_TYPE_GPRS_FACTORY)
                    {
                        sel_acct->list_info[list_num].item_type = CUI_DTCNT_ITEM_GPRS;
                        srv_dtcnt_get_apn(g_mmi_dtcnt_list_item[i].profile_id,
                                      &acct_data,
                                      SRV_DTCNT_ACCOUNT_PRIMARY);
                    }
                    else
                    {
                        sel_acct->list_info[list_num].item_type = CUI_DTCNT_ITEM_CSD;
                        srv_dtcnt_get_csd_number(g_mmi_dtcnt_list_item[i].profile_id,
                                         &acct_data,
                                         SRV_DTCNT_ACCOUNT_PRIMARY);
                    }
                    list_num++;
                }
            }
        }
        cui_dtcnt_arrange_account_list(sel_acct->list_info, 
            g_comm_disp_name_addr_arr,
            start, 
            list_num);
    }
    sel_acct->list_item_number = list_num;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_get_first_entry_highlight_item
 * DESCRIPTION
 *  this function is uesd to get the highlihgt item before first entry screen.
 *  Note: need to be called after get list info.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static U8 cui_dtcnt_get_first_entry_highlight_item(U32 acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_account_info_struct acct_info;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cbm_decode_data_account_id_ext(acct_id, &acct_info);
    for (i = 0; i < g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number; i++)
    {
        if (acct_info.account[0].account_id == g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info[i].profile_id)
        {
            return i;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_select_account
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cui_id     [IN]
 *  app_menu_id  [IN]
 *  bearers  [IN]
 *  app_id    [IN]
 *  account_id  [IN]
 *  option   [IN]
 *  select_type   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dtcnt_select_account(U8 cntx_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_sim_type_enum sim_type = SRV_DTCNT_SIM_TYPE_1;
    mmi_sim_enum sim_enum = MMI_SIM1; // this variable used to prepare data
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cui_dtcnt_sel_index = cntx_index;
    ret = srv_dtcnt_get_sim_preference(&sim_type); // data connection sim
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_DATA_CONNECTION_SIM_GET_SIM_PREFERENCE, sim_type, ret);

    switch (g_cui_dtcnt_sel_acct[cntx_index].type)
    {
        case CUI_DTCNT_SELECT_TYPE_NORMAL:
        {
            // sim list or account list directly
            if ((g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM_ALL) && 
                (mmi_dtcnt_get_available_sim_num() > 1))
            {
                g_cui_dtcnt_sel_acct[cntx_index].sim_list_existed = MMI_TRUE;
                mmi_frm_group_enter((MMI_ID)g_cui_dtcnt_sel_acct[cntx_index].curr_cui_id, MMI_FRM_NODE_NONE_FLAG);
                mmi_frm_scrn_create(
                    g_cui_dtcnt_sel_acct[cntx_index].curr_cui_id,
                    SCR_ID_DTCNT_CUI_SIM_LIST,
                    cui_dtcnt_sim_list_scrn_proc,
                    &g_cui_dtcnt_sel_acct[cntx_index]);
            }
            else
            {
                g_cui_dtcnt_sel_acct[cntx_index].sim_list_existed = MMI_FALSE;
                if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM_ALL)
                {
                    if (mmi_dtcnt_get_available_sim_num() == 1)
                    {
                        sim_enum = mmi_frm_index_to_sim((sim_type - 1));
                    }
                }
                else
                {
                    MMI_ASSERT(g_cui_dtcnt_sel_acct[cntx_index].sim_selection < MMI_SIM_TOTAL);
                    sim_enum = mmi_frm_index_to_sim((U32)g_cui_dtcnt_sel_acct[cntx_index].sim_selection);
                }
                g_cui_dtcnt_sel_acct[cntx_index].sim_enum = sim_enum;
                mmi_frm_group_enter((MMI_ID)g_cui_dtcnt_sel_acct[cntx_index].curr_cui_id, MMI_FRM_NODE_NONE_FLAG);
                mmi_frm_scrn_create(
                    g_cui_dtcnt_sel_acct[cntx_index].curr_cui_id,
                    SCR_ID_DTCNT_CUI_NORMAL_LIST,
                    cui_dtcnt_cbm_normal_list_scrn_proc,
                    &g_cui_dtcnt_sel_acct[cntx_index]);
            }
            break; 

        }
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_get_cntx_index_by_cui_id
 * DESCRIPTION
 *  to get cui display context index by cui ID
 * PARAMETERS
 *  cui_gid
 * RETURNS
 *  S32 index
*****************************************************************************/
S32 cui_dtcnt_get_cntx_index_by_cui_id(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < CUI_DTCNT_MAX_BEARER_LIST_NUM; i++)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_DTCNT_SELECTION_CUI_CONTEXT_INFO, i, g_cui_dtcnt_sel_acct[i].valid, g_cui_dtcnt_sel_acct[i].curr_cui_id);
                        
        if (g_cui_dtcnt_sel_acct[i].valid && g_cui_dtcnt_sel_acct[i].curr_cui_id == cui_id)
        {
            return i;
        }
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_select_run
 * DESCRIPTION
 *  to run data account select group
 * PARAMETERS
 *  cui_gid
 * RETURNS
 *  void
*****************************************************************************/
void cui_dtcnt_select_run(mmi_id cui_gid) /*why no parent gid*/
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    S32 index = -1;
    cui_dtcnt_select_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GRP_ID_INVALID == cui_gid)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_DTCNT_SELECTION_RUN_INFO, cui_gid, index);
        if (!mmi_dtcnt_get_ready_status())
        {
            mmi_popup_display_simple_ext(STR_ID_DTCNT_NOT_READY, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
        }
        return;
    }
    index = cui_dtcnt_get_cntx_index_by_cui_id(cui_gid);
    if (index != -1)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_DTCNT_SELECTION_RUN_INFO, cui_gid, index);
        cui_dtcnt_select_account(index);
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_DTCNT_SELECTION_RUN_ERROR);

        /* send the failed event ID */
        MMI_FRM_INIT_GROUP_EVENT((mmi_group_event_struct*)&evt, CUI_DTCNT_SELECT_EVENT_RESULT_FAILED, cui_gid);
        evt.account_id = MMI_DTCNT_INVALID_ID;
        mmi_frm_group_send_to_parent (cui_gid, (mmi_group_event_struct*)&evt);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_select_run
 * DESCRIPTION
 *  to run data account select group
 * PARAMETERS
 *  cui_gid
 * RETURNS
 *  void
*****************************************************************************/
void cui_dtcnt_select_set_param(mmi_id cui_gid, cui_dtcnt_select_run_struct *p_args)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    S32 index = -1;
    U32 acct_id;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GRP_ID_INVALID == cui_gid)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_DTCNT_SELECTION_INIT_INFO, cui_gid, index);
        return;
    }
    index = cui_dtcnt_get_cntx_index_by_cui_id(cui_gid);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_DTCNT_SELECTION_INIT_INFO, cui_gid, index);
    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_DTCNT_SELECTION_INIT_DETAIL, p_args->bearers, p_args->app_id, p_args->account_id, p_args->option, p_args->sim_selection);

    if (index != -1)
    {
        //g_cui_dtcnt_sel_acct[index].account_id = p_args->account_id;
        for (i = 0; i < MMI_SIM_TOTAL; i++)
        {
            // if support always ask, here need to decode account
            acct_id = cbm_encode_data_account_id(
                            p_args->sim_account_id[i],
                            (cbm_sim_id_enum)i,
                            p_args->app_id,
                            KAL_FALSE);
            srv_dtcnt_get_auto_acc_id(
                acct_id,
                &g_cui_dtcnt_sel_acct[index].sim_account_id[i]);
        }
        g_cui_dtcnt_sel_acct[index].app_menu_id = p_args->AppMenuID;
        g_cui_dtcnt_sel_acct[index].app_icon_id = p_args->icon_id;
        g_cui_dtcnt_sel_acct[index].app_str_id = p_args->str_id;
        g_cui_dtcnt_sel_acct[index].app_id = p_args->app_id;
        g_cui_dtcnt_sel_acct[index].sim_selection = p_args->sim_selection;
        g_cui_dtcnt_sel_acct[index].bearers = p_args->bearers;
        g_cui_dtcnt_sel_acct[index].option = p_args->option;
        g_cui_dtcnt_sel_acct[index].type = p_args->type;
    }
}


/*****************************************************************************
  * FUNCTION
  *  cui_dtcnt_select_group_proc
  * DESCRIPTION
  *  The proc fo the screen group
  * PARAMETERS
  *  cui_gid
  * RETURNS
  *  void
 *****************************************************************************/
static mmi_ret cui_dtcnt_select_group_proc(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}


#define DTCNT_CUI_SIM_HOT_SWAP

/*****************************************************************************
  * FUNCTION
  *  cui_dtcnt_close_all_group
  * DESCRIPTION
  *  close all cui directly, internal use
  * PARAMETERS
  *  sim_selection  [IN]    decide the removed/inserted SIM to refresh or not
  * RETURNS
  *  void
 *****************************************************************************/
void cui_dtcnt_close_all_group(U32 sim_selection)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < CUI_DTCNT_MAX_BEARER_LIST_NUM; i++)
    {
        if (g_cui_dtcnt_sel_acct[i].valid)
        {
            mmi_frm_group_close(g_cui_dtcnt_sel_acct[i].curr_cui_id);            
            memset(&g_cui_dtcnt_sel_acct[i], 0, sizeof(cui_dtcnt_select_account_option_struct));
        }
    }
}
#endif /* __TCPIP__ */ 
