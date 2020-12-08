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
 *  UseDetailCui.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Use Detail CUI source file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/
#include "MMI_features.h"

#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "CommonScreens.h"
#include "wgui_categories_util.h"
#include "wgui_categories_CM.h"
#include "CommonScreensResDef.h"
#include "AlertScreen.h"

#include "UseDetailCuiGprot.h"
#include "UseDetailCuiProt.h"
#include "Mmi_rp_cui_use_detail_def.h"

#include "UCMGProt.h"
#include "UcmSrvGprot.h"
#include "Conversions.h"    /* only for mmi_chset_ucs2_to_utf8_string */
#include "MenuCuiGprot.h"
#include "PhbCuiGprot.h"
#include "SmsAppGprot.h"
#include "EmailAppGProt.h"
#include "BookmarkCuiGprot.h"
#include "Browser_api.h"
#include "NwUsabSrvGprot.h"
#ifdef MMS_SUPPORT
#include "mms_api.h"
#endif /* MMS_SUPPORT */
#include "NetSetAppGprot.h"
#include "SimCtrlSrvGprot.h"


/****************************************************************************
 * Static Declaration
 ****************************************************************************/
/* Define your local variable here */

/* If modify type sequence, always need to modify here */
static const cui_use_detail_type_cntx_struct mapping_table[] = 
{
    {CUI_USE_DETAIL_MAX_PHONE_NUM_LEN, MENU_ID_USE_DETAIL_PHONENUMBER_OPT, CUI_USE_DETAIL_OPERATE_PHONENUMBER_TOTAL, MMI_TRUE},
    {CUI_USE_DETAIL_MAX_USSD_LEN, MENU_ID_USE_DETAIL_USSD_OPT, CUI_USE_DETAIL_OPERATE_USSD_TOTAL, MMI_TRUE},
    {CUI_USE_DETAIL_MAX_EMAIL_LEN, MENU_ID_USE_DETAIL_EMAIL_OPT, CUI_USE_DETAIL_OPERATE_EMAIL_TOTAL, MMI_FALSE},
    {CUI_USE_DETAIL_MAX_URL_LEN, MENU_ID_USE_DETAIL_URL_OPT, CUI_USE_DETAIL_OPERATE_URL_TOTAL, MMI_FALSE},
};


U16 g_image_list[CUI_USE_DETAIL_OPERATE_NUM] = 
{
    IMG_GLOBAL_CALL_CSK, IMG_GLOBAL_SAVE_CSK, IMG_GLOBAL_SEND_MSG_CSK,
    IMG_GLOBAL_SEND_MSG_CSK, IMG_GLOBAL_SAVE_CSK, IMG_GLOBAL_COMMON_CSK,
    IMG_GLOBAL_WEB_BROWSER_CSK, IMG_GLOBAL_COMMON_CSK
};


static cui_use_detail_confirm_struct g_use_detail_confirm;


/* Declare your local funcion here */
static mmi_ret cui_use_detail_proc(mmi_event_struct *evt);
static void cui_use_detail_handle_general_option(mmi_id owner_gid, cui_use_detail_cntx_struct *use_detail_cntx);
static void cui_use_detail_handle_edit_option(mmi_id owner_gid, U16 *edit_buffer);
static void cui_use_detail_free_cntx(cui_use_detail_cntx_struct *use_detail_cntx);
static void cui_use_detail_close_process(mmi_id group_id, cui_use_detail_result_enum result, cui_use_detail_close_type_enum close_type);
static MMI_BOOL cui_use_detail_check_basic_obj(cui_use_detail_basic_obj_struct *obj_list, U8 obj_count);
static cui_use_detail_cntx_struct *cui_use_detail_create_cntx(cui_use_detail_basic_obj_struct *obj_list, U8 obj_count, void* parent_data);
static void cui_use_detail_set_supported_operate(cui_use_detail_operate_enum *operate);
static U8 cui_use_detail_check_available_operate_num(cui_use_detail_operate_enum operate, cui_use_detail_operate_enum *avail_operate);
static void cui_use_detail_single_obj_process(mmi_id group_id, MMI_BOOL force_single);
static void cui_use_detail_pre_operate_hdlr(mmi_id group_id, MMI_BOOL force_single);
static void cui_use_detail_chose_operate(mmi_id parent_gid, mmi_menu_id root_menu_id);
static void cui_use_detial_operate_hdlr(mmi_id group_id);

#ifdef __MMI_UCM__
static void cui_use_detail_dial_by_call_type(srv_ucm_call_type_enum dial_type, U16 *number);
#endif /* __MMI_UCM__ */
#ifdef __MMI_PHB_OPTIONAL_FIELD__
static void cui_use_detail_save_to_phb(mmi_id parent_gid, cui_use_detail_operate_enum operate, U16 *contxt);
#else /* __MMI_PHB_OPTIONAL_FIELD__ */
static void cui_use_detail_save_number_to_phb(mmi_id parent_gid, U16 *number);
#endif /* __MMI_PHB_OPTIONAL_FIELD__ */
#ifdef __MOD_SMSAL__
static void cui_use_detail_send_sms(U16 *number);
#endif /* __MOD_SMSAL_ */
#ifdef __MMI_MMS__
static void cui_use_detail_send_mms(U16 *number);
#endif /* __MMI_MMS__ */
#ifdef __MMI_EMAIL__
static void cui_use_detail_send_email(U16 *email_addr);
#endif /* __MMI_EMAIL__ */

#ifdef BROWSER_SUPPORT
static void cui_use_detail_go_to_wap(U16 *url_addr);
#ifdef __OP01__
static void cui_use_detail_go_to_wap_by_confirm(mmi_id parent_gid, U16 *url_addr);
static void cui_use_detail_enter_confirm(MMI_ID parent_id, U16 str_id, void *user_tag);
static mmi_ret cui_use_detail_cnf_cb(mmi_event_struct *evt);
#endif /* __OP01__ */
#if defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
static void cui_use_detail_add_to_bookmark(mmi_id parent_gid, U16 *url_addr);
#endif /* __MMI_BRW_BKM_INTERFACE_SUPPORT__ */
#endif /* BROWSER_SUPPORT */

static void cui_use_detail_list_lsk_hdlr(void);
static void cui_use_detail_list_csk_hdlr(void);
static void cui_use_detail_list_rsk_hdlr(void);
static void cui_use_detail_enter_view_list(mmi_id group_id);
static void cui_use_detail_entry_view_list(mmi_scrn_essential_struct* scr_info);
static mmi_ret cui_use_detail_view_list_delete_proc(mmi_event_struct *evt);
static void cui_use_detail_list_hilite_hdlr(S32 item_index);
static void cui_use_detail_set_lsk_csk_info(cui_use_detail_cntx_struct *use_detail_cntx, mmi_id screen_id);
static void cui_use_detail_edit_lsk_hdlr(void);
static void cui_use_detail_edit_csk_hdlr(void);
static void cui_use_detail_edit_rsk_hdlr(void);
static void cui_use_detail_enter_editor(mmi_id group_id);
static void cui_use_detail_entry_editor(mmi_scrn_essential_struct* scr_info);
static void cui_use_detail_set_dialer_keypad(void);
#ifdef  __MMI_TOUCH_SCREEN__
#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
#ifdef __MMI_UCM__
#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
static void cui_use_detail_set_dynamic_sim_kepad_hdlr(void);
static void cui_use_detail_entry_sim_select(void);
#endif /* defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__) */
#if (MMI_MAX_SIM_NUM >= 4)
static void cui_use_detail_dial_sim4(void);
#endif /* (MMI_MAX_SIM_NUM >= 4) */
#if (MMI_MAX_SIM_NUM >= 3)
static void cui_use_detail_dial_sim3(void);
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#if (MMI_MAX_SIM_NUM >= 2)
static void cui_use_detail_dial_sim1(void);
static void cui_use_detail_dial_sim2(void);
#endif /* (MMI_MAX_SIM_NUM >= 2) */
#endif /* __MMI_UCM__ */
#endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */
#endif /* __MMI_TOUCH_SCREEN__ */
#ifdef __MMI_UCM__
static void cui_use_detail_dial(void);
static void cui_use_detail_dial_by_call_type_hdlr(srv_ucm_call_type_enum dial_type);
#endif /* __MMI_UCM__ */
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
static void cui_use_detail_add_sim_name(mmi_id owner_gid);
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
static void cui_use_detail_sim_select_hdlr(mmi_menu_id highlighted_menu_id, mmi_id group_id);
#endif /* defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__) */
static void cui_use_detail_dispaly_error_popup(MMI_STR_ID str_id);


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_create
 * DESCRIPTION
 *  Create an instance of "Use Detail CUI".
 *  In text, may exist some useful contents, EX: phonenumber, USSD, Email, URL.
 *  For each type of the contents, have some common actions.
 *  This CUI can use the contents which the user provided to do the common actions.
 *  EX: use phonenumber to make call, to send SMS etc.
 * PARAMETERS
 *  caller           : [IN]    Parent group ID
 *  obj_list         : [IN]    the detail contents list which the user want to use
 *  obj_count        : [IN]    number of the detail contents in the list
 *  parent_data      : [IN]    Parent data
 * RETURNS
 *  Return new CUI id if create sucessfully; otherwise, GRP_ID_INVALID
 *****************************************************************************/
mmi_id cui_use_detail_create(mmi_id caller, cui_use_detail_basic_obj_struct *obj_list, U8 obj_count, void* parent_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_use_detail_cntx_struct *use_detail_cntx;
    mmi_id use_detail_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_USE_DETAIL, TRC_CUI_USE_DETAIL_CREATE, caller, obj_list, obj_count, parent_data);

    if (!mmi_frm_group_is_present(caller) ||
        !cui_use_detail_check_basic_obj(obj_list, obj_count))
    {
        return GRP_ID_INVALID;
    }

    use_detail_cntx = cui_use_detail_create_cntx(obj_list, obj_count, parent_data);
    use_detail_gid = mmi_frm_group_create(caller, GRP_ID_AUTO_GEN, cui_use_detail_proc, use_detail_cntx);
    MMI_ASSERT(use_detail_gid != GRP_ID_INVALID);
    return use_detail_gid;
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_set_mode
 * DESCRIPTION
 *  Set mode for every use detial type. If not invoke this API, every type have default mode.
 *  Default mode: edit_flag for USSD is MMI_TRUE, others is MMI_FALSE;
 *                CUI_USE_DETAIL_OPERATE_XXX_TOTAL is XXX_OPERATE's default operate
 *                Not support edit function for email and URL, so if user set MMI_TRUE, the value
 *                will be modified to MMI_FALSE.
 * PARAMETERS
 *  cui_id             : [IN]    ID of CUI
 *  mode_list          : [IN]    mode for use detail type
 *  list_count         : [IN]    number of mode list
 * RETURNS
 *  Return MMI_TRUE if set mode sucessfully; otherwise, return MMI_FALSE
 *****************************************************************************/
MMI_BOOL cui_use_detail_set_mode(mmi_id cui_id, cui_use_detail_mode_struct *mode_list, U8 list_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_use_detail_cntx_struct *use_detail_cntx;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    use_detail_cntx = (cui_use_detail_cntx_struct*)mmi_frm_group_get_user_data(cui_id);

    MMI_TRACE(MMI_COMMON_TRC_G6_USE_DETAIL, TRC_CUI_USE_DETAIL_SET_MODE, cui_id, use_detail_cntx, mode_list, list_count);

    if (!use_detail_cntx || mode_list == NULL || list_count <= 0)
    {
        return MMI_FALSE;
    }

    for (i = 0; i < list_count; i++)
    {
        U8 type = mode_list[i].type;
        use_detail_cntx->mode_list[type].operate = (cui_use_detail_operate_enum)(mode_list[i].operate & mapping_table[type].total_operate);
        use_detail_cntx->mode_list[type].edit_flag = (MMI_BOOL)(mode_list[i].edit_flag & mapping_table[type].filter_edit_flag);
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_set_view_flag
 * DESCRIPTION
 *  Set view flag for use detail cui. If not invoke this API, view flag have default value.
 *  Default value: If obj_count > 1, view_flag is MMI_TRUE, obj_count == 1, view_falg is MMI_FALSE.
 * PARAMETERS
 *  cui_id             : [IN]    ID of CUI
 *  view_flag          : [IN]    support diaplay all contents in a list or not
 * RETURNS
 *  void
 *****************************************************************************/
void cui_use_detail_set_view_flag(mmi_id cui_id, MMI_BOOL view_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_use_detail_cntx_struct *use_detail_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    use_detail_cntx = (cui_use_detail_cntx_struct*)mmi_frm_group_get_user_data(cui_id);

    MMI_TRACE(MMI_COMMON_TRC_G6_USE_DETAIL, TRC_CUI_USE_DETAIL_SET_VIEW_FLAG, cui_id, use_detail_cntx, view_flag);

    if (use_detail_cntx)
    {
        use_detail_cntx->view_flag = view_flag;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_run
 * DESCRIPTION
 *  Run "Use Detail CUI"
 * PARAMETERS
 *  cui_id             : [IN]    ID of CUI
 * RETURNS
 *  void
 *****************************************************************************/
void cui_use_detail_run(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_use_detail_cntx_struct *use_detail_cntx;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cui_id != GRP_ID_INVALID);
    mmi_frm_group_enter(cui_id, MMI_FRM_NODE_NONE_FLAG);
    use_detail_cntx = (cui_use_detail_cntx_struct*)mmi_frm_group_get_user_data(cui_id);

    for (i = 0; i < CUI_USE_DETAIL_TYPE_END_OF_ENUM; i++)
    {
        cui_use_detail_set_supported_operate(&(use_detail_cntx->mode_list[i].operate));
    }

    if (use_detail_cntx->view_flag)
    {
        cui_use_detail_enter_view_list(cui_id);
    }
    else
    {
        cui_use_detail_single_obj_process(cui_id, MMI_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_close
 * DESCRIPTION
 *  Close "Use Detail CUI"
 * PARAMETERS
 *  cui_id             : [IN]    ID of CUI
 * RETURNS
 *  void
 *****************************************************************************/
void cui_use_detail_close(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(cui_id);
}


/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_proc
 * DESCRIPTION
 *  Proc of use detail cui
 * PARAMETERS
 *  evt         : [IN]    event
 * RETURNS
 * Return MMI_RET_OK if handle this event successfully; otherwise, return other fail info
 *****************************************************************************/
static mmi_ret cui_use_detail_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_event_struct *group_evt = (mmi_group_event_struct*)evt;
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    cui_use_detail_cntx_struct *use_detail_cntx;
    mmi_group_node_struct node_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_frm_group_get_info(group_evt->sender_id, &node_info);
    use_detail_cntx = (cui_use_detail_cntx_struct *)mmi_frm_group_get_user_data(node_info.parent);

    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            {
                mmi_scenario_evt_struct *scenario_evt = (mmi_scenario_evt_struct*)evt;
                use_detail_cntx = (cui_use_detail_cntx_struct *)mmi_frm_group_get_user_data(scenario_evt->targ_group);
                cui_use_detail_free_cntx(use_detail_cntx);
            }
            break;

        case EVT_ID_CUI_MENU_LIST_ENTRY:
            {
                use_detail_cntx->close_flag = MMI_FALSE;
                cui_use_detail_handle_general_option(menu_evt->sender_id, use_detail_cntx);

                if (MENU_ID_USE_DETAIL_USSD_OPT == menu_evt->parent_menu_id)
                {
                    cui_use_detail_handle_edit_option(menu_evt->sender_id, use_detail_cntx->edit_buffer);
                }

            #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                if (MENU_ID_USE_DETAIL_SIM_SELECT == menu_evt->parent_menu_id)
                {
                    cui_use_detail_add_sim_name(menu_evt->sender_id);
                }
            #endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            use_detail_cntx->close_flag = MMI_TRUE;
        #if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
            if (MENU_ID_USE_DETAIL_SIM_SELECT  ==  menu_evt->parent_menu_id)
            {
                cui_use_detail_sim_select_hdlr(menu_evt->highlighted_menu_id, node_info.parent);
            }
            else
        #endif /* defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__) */
            {
                /* Must confirm the order of MENU_ID_USE_DETAIL_OPT_XXX is same as cui_use_detail_operate_enum */
                use_detail_cntx->exe_operate = (cui_use_detail_operate_enum)(1 << (menu_evt->highlighted_menu_id - MENU_ID_USE_DETAIL_OPT_CALL));
                cui_use_detial_operate_hdlr(node_info.parent);
                cui_menu_close(menu_evt->sender_id);
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            if (!use_detail_cntx->close_flag)
            {
                cui_use_detail_close_process(node_info.parent, CUI_USE_DETAIL_RESULT_OK, CUI_USE_DETAIL_CLOSE_TYPE_BACK);
            }
            break;

        case EVT_ID_PHB_SAVE_CONTACT:
        case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
            cui_phb_save_contact_close(group_evt->sender_id);
            cui_use_detail_close_process(node_info.parent, CUI_USE_DETAIL_RESULT_OK, CUI_USE_DETAIL_CLOSE_TYPE_DONE);
            break;

    #ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
        case EVT_ID_CUI_BKM_ADD_BKM_CLOSE:
            cui_bkm_add_bkm_close(group_evt->sender_id);
            cui_use_detail_close_process(node_info.parent, CUI_USE_DETAIL_RESULT_OK, CUI_USE_DETAIL_CLOSE_TYPE_DONE);
            break;
    #endif /* __MMI_BRW_BKM_INTERFACE_SUPPORT__ */

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_handle_general_option
 * DESCRIPTION
 *  common option set function
 * PARAMETERS
 *  owner_gid               : [IN]    event
 *  use_detail_cntx         : [IN]    use detail cntx
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_handle_general_option(mmi_id owner_gid, cui_use_detail_cntx_struct *use_detail_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    cui_use_detail_type_enum type;
    cui_use_detail_operate_enum total_operate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    type = use_detail_cntx->obj_list[use_detail_cntx->obj_index].type;
    cui_use_detail_check_available_operate_num(use_detail_cntx->mode_list[type].operate, &total_operate);

    for (i = 0; i < CUI_USE_DETAIL_OPERATE_NUM; i++)
    {
        if (total_operate & (CUI_USE_DETAIL_OPERATE_CALL << i))
        {
            cui_menu_set_item_hidden(owner_gid, MENU_ID_USE_DETAIL_OPT_CALL + i, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(owner_gid, MENU_ID_USE_DETAIL_OPT_CALL + i, MMI_TRUE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_handle_edit_option
 * DESCRIPTION
 *  edit option set function
 * PARAMETERS
 *  owner_gid           : [IN]    event
 *  edit_buffer         : [IN]    edit buffer pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_handle_edit_option(mmi_id owner_gid, U16 *edit_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((CHAR *)edit_buffer))
    {
        cui_menu_set_item_disabled(owner_gid, MENU_ID_USE_DETAIL_OPT_CALL, MMI_FALSE);
        cui_menu_set_item_disabled(owner_gid, MENU_ID_USE_DETAIL_OPT_SAVE_NUM_TO_PHB, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_disabled(owner_gid, MENU_ID_USE_DETAIL_OPT_CALL, MMI_TRUE);
        cui_menu_set_item_disabled(owner_gid, MENU_ID_USE_DETAIL_OPT_SAVE_NUM_TO_PHB, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_free_cntx
 * DESCRIPTION
 *  Free all buffers when group is closed
 * PARAMETERS
 *  use_detail_cntx         : [IN]    use detial context
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_free_cntx(cui_use_detail_cntx_struct *use_detail_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (use_detail_cntx)
    {
        if (use_detail_cntx->edit_buffer)
        {
            OslMfree(use_detail_cntx->edit_buffer);
            use_detail_cntx->edit_buffer = NULL;
        }

        if (use_detail_cntx->obj_list)
        {
            OslMfree(use_detail_cntx->obj_list);
            use_detail_cntx->obj_list = NULL;
        }

        if (use_detail_cntx->mode_list)
        {
            OslMfree(use_detail_cntx->mode_list);
            use_detail_cntx->mode_list = NULL;
        }

        OslMfree(use_detail_cntx);
        use_detail_cntx = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_close_process
 * DESCRIPTION
 *  Close related screen according to close type.
 *  The scrren close sequence: Back to edit scrren -> Back to list scrren -> Close CUI
 *  CUI_USE_DETAIL_CLOSE_TYPE_BACK:
 *    If have edit scrren, back to edit scrren, else if have list screen, 
 *    back to list scrren, else send close event;
 *  CUI_USE_DETAIL_CLOSE_TYPE_DONE && CUI_USE_DETAIL_CLOSE_TYPE_EDIT_ABORT: 
 *    If have list screen, back to list scrren, else send close event;
 *  CUI_USE_DETAIL_CLOSE_TYPE_VIEW_ABORT && CUI_USE_DETAIL_CLOSE_TYPE_NO_OPERATE:
 *    Send close event
 * PARAMETERS
 *  group_id         : [IN]    Cui group id
 *  result           : [IN]    Result be sent to parents
 *  close_type       : [IN]    Close type be used to decide close which screen
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_close_process(mmi_id group_id, cui_use_detail_result_enum result, cui_use_detail_close_type_enum close_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_use_detail_result_event_struct result_evt;
    cui_use_detail_cntx_struct *use_detail_cntx;
    cui_use_detail_type_enum type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(group_id))
    {
        use_detail_cntx = (cui_use_detail_cntx_struct*)mmi_frm_group_get_user_data(group_id);
        MMI_TRACE(MMI_COMMON_TRC_G6_USE_DETAIL, TRC_CUI_USE_DETAIL_CLOSE, group_id, result, close_type, use_detail_cntx);

        switch (close_type)
        {
            case CUI_USE_DETAIL_CLOSE_TYPE_BACK:
                type = use_detail_cntx->obj_list[use_detail_cntx->obj_index].type;
                if (use_detail_cntx->mode_list[type].edit_flag)
                {
                    break;
                }

            case CUI_USE_DETAIL_CLOSE_TYPE_DONE:
            case CUI_USE_DETAIL_CLOSE_TYPE_EDIT_ABORT:
                if (use_detail_cntx->view_flag)
                {
                    if (mmi_frm_scrn_is_present(group_id, SCR_ID_CUI_USE_DETAIL_EDIT, MMI_FRM_NODE_ALL_FLAG))
                    {
                        mmi_frm_scrn_close(group_id, SCR_ID_CUI_USE_DETAIL_EDIT);
                    }
                    break;
                }

            case CUI_USE_DETAIL_CLOSE_TYPE_VIEW_ABORT:
            case CUI_USE_DETAIL_CLOSE_TYPE_NO_OPERATE:
                /* Send result event to caller */
                MMI_FRM_INIT_GROUP_EVENT(&result_evt, EVT_ID_CUI_USE_DETAIL_RESULT, group_id);
                result_evt.result = result;
                result_evt.operate = use_detail_cntx->exe_operate;
                result_evt.parent_data = use_detail_cntx->parent_data;
                mmi_frm_group_post_to_caller(group_id, (mmi_group_event_struct*)&result_evt);
                break;

            default:
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_check_basic_obj
 * DESCRIPTION
 *  Check the input date about the contents list is valid or not
 * PARAMETERS
 *  obj_list         : [IN]    the detail contents list which the user want to use
 *  obj_count        : [IN]    number of the detail contents in the list
 * RETURNS
 *  Return MMI_TRUE if the input contents is vaild; otherwise, MMI_FALSE
 *****************************************************************************/
static MMI_BOOL cui_use_detail_check_basic_obj(cui_use_detail_basic_obj_struct *obj_list, U8 obj_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == obj_list || obj_count <= 0)
    {
        return MMI_FALSE;
    }

    obj_count = (obj_count > CUI_USE_DETAIL_MAX_OBJ_NUM) ? (CUI_USE_DETAIL_MAX_OBJ_NUM) : (obj_count);

    for (i = 0; i < obj_count; i++)
    {
        if (obj_list[i].type >= CUI_USE_DETAIL_TYPE_END_OF_ENUM ||
            obj_list[i].detail_txt == NULL ||
            obj_list[i].txtlen == 0)
        {
            return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_create_cntx
 * DESCRIPTION
 *  Create Use detail cntx struct, set input value and default value for every member
 * PARAMETERS
 *  obj_list         : [IN]    the detail contents list which the user want to use
 *  obj_count        : [IN]    number of the detail contents in the list
 *  parent_data      : [IN]    Parent data
 * RETURNS
 *  Return cntx struct pointer
 *****************************************************************************/
static cui_use_detail_cntx_struct *cui_use_detail_create_cntx(cui_use_detail_basic_obj_struct *obj_list, U8 obj_count, void* parent_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_use_detail_cntx_struct *use_detail_cntx;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    use_detail_cntx = OslMalloc(sizeof(cui_use_detail_cntx_struct));
    /* Cannot be removed, some parameters need to be initialized to 0 */
    memset(use_detail_cntx, 0, sizeof(cui_use_detail_cntx_struct));

    MMI_TRACE(MMI_COMMON_TRC_G6_USE_DETAIL, TRC_CUI_USE_DETAIL_CREATE_CNTX, use_detail_cntx);

    /* Set basic info */
    obj_count = (obj_count > CUI_USE_DETAIL_MAX_OBJ_NUM) ? (CUI_USE_DETAIL_MAX_OBJ_NUM) : (obj_count);
    use_detail_cntx->obj_list = OslMalloc(sizeof(cui_use_detail_basic_obj_struct) * obj_count);
    memcpy(use_detail_cntx->obj_list, obj_list, sizeof(cui_use_detail_basic_obj_struct) * obj_count);
	use_detail_cntx->obj_count = obj_count;

    /* Set mode*/
    use_detail_cntx->mode_list = OslMalloc(sizeof(cui_use_detail_mode_struct) * CUI_USE_DETAIL_TYPE_END_OF_ENUM);
    for (i = 0; i < CUI_USE_DETAIL_TYPE_END_OF_ENUM; i++)
    {
        use_detail_cntx->mode_list[i].type = (cui_use_detail_type_enum)i;
        use_detail_cntx->mode_list[i].operate = mapping_table[i].total_operate;
        /* Default edit flag for USSD is MMI_TRUE; others are MMI_FALSE */
        use_detail_cntx->mode_list[i].edit_flag = MMI_FALSE;
        if (CUI_USE_DETAIL_TYPE_USSD == (cui_use_detail_type_enum)i)
        {
            use_detail_cntx->mode_list[i].edit_flag = MMI_TRUE;
        }
    }

    use_detail_cntx->parent_data = parent_data;

    if (obj_count != 1)
    {
        use_detail_cntx->view_flag = MMI_TRUE;
    }
    return use_detail_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_set_supported_operate
 * DESCRIPTION
 *  Remove the action not supported in handset
 * PARAMETERS
 *  operate         : [OUT]    Total operate can be done for one object
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_set_supported_operate(cui_use_detail_operate_enum *operate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_UCM__
    *operate  &= (~CUI_USE_DETAIL_OPERATE_CALL);
#endif /* __MMI_UCM__ */

#ifndef __MOD_SMSAL__
    *operate  &= (~CUI_USE_DETAIL_OPERATE_SEND_SMS);
#endif /* __MOD_SMSAL__ */

#ifndef __MMI_MMS__
    *operate  &= (~CUI_USE_DETAIL_OPERATE_SEND_MMS);
#endif /* __MMI_MMS__ */

#ifndef __MMI_EMAIL__
    *operate  &= (~CUI_USE_DETAIL_OPERATE_SEND_EMAIL);
#endif /* __MMI_EMAIL__ */

#ifndef __MMI_PHB_OPTIONAL_FIELD__
    *operate  &= (~CUI_USE_DETAIL_OPERATE_SAVE_EMAIL_TO_PHB);
#endif /* __MMI_PHB_OPTIONAL_FIELD__ */

#ifndef BROWSER_SUPPORT
    *operate  &= (~CUI_USE_DETAIL_OPERATE_TO_WAP);
#endif /* BROWSER_SUPPORT */

#if !defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__) || !defined(BROWSER_SUPPORT)
    *operate  &= (~CUI_USE_DETAIL_OPERATE_ADD_TO_BOOKMARK);
#endif /* __MMI_BRW_BKM_INTERFACE_SUPPORT__ */

}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_check_available_operate_num
 * DESCRIPTION
 *  Check the available operate number, and give the available operate info
 * PARAMETERS
 *  operate            : [IN]    Total operate can be done for one object
 *  avail_operate      : [OUT]   If the available operate number is 0, output the first
 *                               operate the user want to do; if the available operate
 *                               number >= 1, output the available operate.
 *                               Can set NULL means no need to get the operate.
 * RETURNS
 *  Return the available operate number
 *****************************************************************************/
static U8 cui_use_detail_check_available_operate_num(cui_use_detail_operate_enum operate, cui_use_detail_operate_enum *avail_operate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get the first check operate */
    for (i = 0; i < CUI_USE_DETAIL_OPERATE_NUM; i++)
    {
        if (operate & (CUI_USE_DETAIL_OPERATE_CALL << i))
        {
            count++;
            if (avail_operate != NULL && 1 == count)
            {
                *avail_operate = CUI_USE_DETAIL_OPERATE_CALL << i;
            }
        }
    }

    /* Remove the not available operate */
#ifdef __MMI_EMAIL__
    if (!mmi_email_is_email_can_forward())
    {
        if (operate & CUI_USE_DETAIL_OPERATE_SEND_EMAIL)
        {
            operate  &= (~CUI_USE_DETAIL_OPERATE_SEND_EMAIL);
            count--;
        }
    }
#endif /* __MMI_EMAIL__ */

    /* Get the available operate */
    if (count != 0)
    {
        *avail_operate = operate;
    }

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_single_obj_process
 * DESCRIPTION
 *  Process one content(object), can edit before operate or exe operate
 * PARAMETERS
 *  group_id         : [IN]    Parent group ID
 *  force_single     : [IN]    Force to execute one operate directly
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_single_obj_process(mmi_id group_id, MMI_BOOL force_single)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_use_detail_cntx_struct *use_detail_cntx;
    cui_use_detail_basic_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    use_detail_cntx = (cui_use_detail_cntx_struct*)mmi_frm_group_get_user_data(group_id);
    obj = &use_detail_cntx->obj_list[use_detail_cntx->obj_index];

    /* Prepare edit data */
    if (use_detail_cntx->edit_buffer)
    {
        OslMfree(use_detail_cntx->edit_buffer);
    }
    use_detail_cntx->edit_buffer = OslMalloc((mapping_table[obj->type].max_len + 1) * ENCODING_LENGTH);
    obj->txtlen = (obj->txtlen > mapping_table[obj->type].max_len) ? (mapping_table[obj->type].max_len) : (obj->txtlen);
    mmi_ucs2ncpy((CHAR*)use_detail_cntx->edit_buffer, (CHAR*)obj->detail_txt, obj->txtlen);

    /* Check if no action can be done -> check if need to eidt -> Process operate */
    if (CUI_USE_DETIAL_OPERATE_NO_OPERATE == use_detail_cntx->mode_list[obj->type].operate)
    {
        cui_use_detail_dispaly_error_popup(STR_GLOBAL_ERROR);
        cui_use_detail_close_process(group_id, CUI_USE_DETAIL_RESULT_ERROR, CUI_USE_DETAIL_CLOSE_TYPE_NO_OPERATE);
    }
    else if (use_detail_cntx->mode_list[obj->type].edit_flag)
    {
        cui_use_detail_enter_editor(group_id);
    }
    else
    {
        cui_use_detail_pre_operate_hdlr(group_id, force_single);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_pre_operate_hdlr
 * DESCRIPTION
 *  Process one content(object), exe one action directly or chose one action
 * PARAMETERS
 *  group_id         : [IN]    Parent group ID
 *  force_single     : [IN]    Force to execute one operate directly
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_pre_operate_hdlr(mmi_id group_id, MMI_BOOL force_single)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 type, count;
    cui_use_detail_cntx_struct *use_detail_cntx;
    cui_use_detail_operate_enum total_operate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    use_detail_cntx = (cui_use_detail_cntx_struct*)mmi_frm_group_get_user_data(group_id);
    type = use_detail_cntx->obj_list[use_detail_cntx->obj_index].type;
    count = cui_use_detail_check_available_operate_num(use_detail_cntx->mode_list[type].operate, &total_operate);

    if (count <= 1 && (MMI_FALSE == use_detail_cntx->view_flag) && (MMI_FALSE == use_detail_cntx->mode_list[type].edit_flag))
    {
        use_detail_cntx->exe_operate = total_operate;
        cui_use_detial_operate_hdlr(group_id);
    }
    else if (MMI_TRUE == force_single)
    {
        cui_use_detial_operate_hdlr(group_id);
    }
    else
    {
        cui_use_detail_chose_operate(group_id, mapping_table[type].root_menu_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_chose_operate
 * DESCRIPTION
 *  Create menu cui to chose operate
 * PARAMETERS
 *  group_id            : [IN]    Parent group ID
 *  root_menu_id        : [IN]    root menu id
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_chose_operate(mmi_id parent_gid, mmi_menu_id root_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_create_and_run(
                parent_gid,
                CUI_MENU_SRC_TYPE_RESOURCE,
                CUI_MENU_TYPE_FROM_RESOURCE,
                root_menu_id,
                MMI_FALSE,
                NULL);
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detial_operate_hdlr
 * DESCRIPTION
 *  Execuse the operate
 * PARAMETERS
 *  group_id            : [IN]    Parent group ID
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detial_operate_hdlr(mmi_id group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    cui_use_detail_cntx_struct *use_detail_cntx = (cui_use_detail_cntx_struct *)mmi_frm_group_get_user_data(group_id);
    MMI_BOOL execuse_flag = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_USE_DETAIL, TRC_CUI_USE_DETAIL_OPERATE_HDLR, use_detail_cntx->exe_operate);

    if (CUI_USE_DETAIL_TYPE_PHONENUMBER == use_detail_cntx->obj_list[use_detail_cntx->obj_index].type)
    {
        WCHAR valid_ucs2_addr[CUI_USE_DETAIL_MAX_PHONE_NUM_LEN + 1];
        mmi_ucs2cpy((CHAR*)valid_ucs2_addr, (CHAR*)use_detail_cntx->edit_buffer);
        mmi_sms_validate_number((CHAR*)valid_ucs2_addr,
                                (CHAR*)use_detail_cntx->edit_buffer,
                                mmi_ucs2strlen((const CHAR*)valid_ucs2_addr));
    }

    switch (use_detail_cntx->exe_operate)
    {
    #ifdef __MMI_UCM__
        case CUI_USE_DETAIL_OPERATE_CALL:
            cui_use_detail_dial_by_call_type(SRV_UCM_CALL_TYPE_NO_DATA_CSD, use_detail_cntx->edit_buffer);
            break;
    #endif /* __MMI_UCM__ */

        case CUI_USE_DETAIL_OPERATE_SAVE_NUM_TO_PHB:
        #ifdef __MMI_PHB_OPTIONAL_FIELD__
            cui_use_detail_save_to_phb(group_id, CUI_USE_DETAIL_OPERATE_SAVE_NUM_TO_PHB, use_detail_cntx->edit_buffer);
        #else /* __MMI_PHB_OPTIONAL_FIELD__ */        
            cui_use_detail_save_number_to_phb(group_id, use_detail_cntx->edit_buffer);
        #endif /* __MMI_PHB_OPTIONAL_FIELD__ */
            execuse_flag = MMI_FALSE;
            break;

    #ifdef __MOD_SMSAL__
        case CUI_USE_DETAIL_OPERATE_SEND_SMS:
            cui_use_detail_send_sms(use_detail_cntx->edit_buffer);
            break;
    #endif /* __MOD_SMSAL__ */

    #ifdef __MMI_MMS__
        case CUI_USE_DETAIL_OPERATE_SEND_MMS:
            cui_use_detail_send_mms(use_detail_cntx->edit_buffer);
            break;
    #endif /* __MMI_MMS__ */

    #ifdef __MMI_EMAIL__
        case CUI_USE_DETAIL_OPERATE_SEND_EMAIL:
            cui_use_detail_send_email(use_detail_cntx->edit_buffer);
            break;
    #endif /* __MMI_EMAIL__ */

    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case CUI_USE_DETAIL_OPERATE_SAVE_EMAIL_TO_PHB:
            cui_use_detail_save_to_phb(group_id, CUI_USE_DETAIL_OPERATE_SAVE_EMAIL_TO_PHB, use_detail_cntx->edit_buffer);
            execuse_flag = MMI_FALSE;
            break;
    #endif /* __MMI_PHB_OPTIONAL_FIELD__ */

    #ifdef BROWSER_SUPPORT
        case CUI_USE_DETAIL_OPERATE_TO_WAP:
        #ifdef __OP01__
            cui_use_detail_go_to_wap_by_confirm(group_id, use_detail_cntx->edit_buffer);
            execuse_flag = MMI_FALSE;
        #else /* __OP01__ */
            cui_use_detail_go_to_wap(use_detail_cntx->edit_buffer);
        #endif /* __OP01__*/
            break;

    #if defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
        case CUI_USE_DETAIL_OPERATE_ADD_TO_BOOKMARK:
            cui_use_detail_add_to_bookmark(group_id, use_detail_cntx->edit_buffer);
            execuse_flag = MMI_FALSE;
            break;
    #endif /* __MMI_BRW_BKM_INTERFACE_SUPPORT__ */
    #endif /* BROWSER_SUPPORT */

        default:
            break;
    }

    if (MMI_TRUE == execuse_flag)
    {
        cui_use_detail_close_process(group_id, CUI_USE_DETAIL_RESULT_OK, CUI_USE_DETAIL_CLOSE_TYPE_DONE);
    }
}


#ifdef __MMI_UCM__
/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_dial_by_call_type
 * DESCRIPTION
 *  Save number to phb
 * PARAMETERS
 *  dial_type         : [IN]    dial type
 *  number            : [IN]    Phonenubmer
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_dial_by_call_type(srv_ucm_call_type_enum dial_type, U16 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_init_call_para(&param);
    param.dial_type = dial_type;
    param.ucs2_num_uri = number;
    mmi_ucm_call_launch(0, &param);
}
#endif /* __MMI_UCM__ */


#ifdef __MMI_PHB_OPTIONAL_FIELD__
/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_save_to_phb
 * DESCRIPTION
 *  Save number or email to phb
 * PARAMETERS
 *  parent_gid        : [IN]    Parent group ID
 *  operate           : [IN]    Operate want to excuse
 *  contxt            : [IN]    Save contxt
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_save_to_phb(mmi_id parent_gid, cui_use_detail_operate_enum operate, U16 *contxt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID save_to_phb_cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    save_to_phb_cui_id = cui_phb_save_contact_create(parent_gid);

    if (save_to_phb_cui_id != GRP_ID_INVALID)
    {
        if (CUI_USE_DETAIL_OPERATE_SAVE_NUM_TO_PHB == operate)
        {
            cui_phb_save_contact_set_number(save_to_phb_cui_id, contxt);
        }
        else if (CUI_USE_DETAIL_OPERATE_SAVE_EMAIL_TO_PHB == operate)
        {
            cui_phb_save_contact_set_email(save_to_phb_cui_id, contxt);
        }
        cui_phb_save_contact_run(save_to_phb_cui_id);
    }
}


#else /* __MMI_PHB_OPTIONAL_FIELD__ */
/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_save_number_to_phb
 * DESCRIPTION
 *  Save number to phb
 * PARAMETERS
 *  parent_gid        : [IN]    Parent group ID
 *  number            : [IN]    Phonenubmer
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_save_number_to_phb(mmi_id parent_gid, U16 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID save_to_phb_cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    save_to_phb_cui_id = cui_phb_save_contact_create(parent_gid);

    if (save_to_phb_cui_id != GRP_ID_INVALID)
    {
        cui_phb_save_contact_set_number(save_to_phb_cui_id, number);
        cui_phb_save_contact_run(save_to_phb_cui_id);
    }

    
}
#endif /* __MMI_PHB_OPTIONAL_FIELD__ */


#ifdef __MOD_SMSAL__
/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_send_sms
 * DESCRIPTION
 *  Send sms
 * PARAMETERS
 *  number            : [IN]    Phonenumber
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_send_sms(U16 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_sms_write_msg_para_struct sendData;
    U8* ascii_number;
    U8 number_len = mmi_ucs2strlen((CHAR*)number);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (number_len == 0)
    {
        cui_use_detail_dispaly_error_popup(STR_GLOBAL_NO_NUMBER);
        return;
    }

    memset((CHAR*)&sendData, 0, sizeof(mmi_sms_write_msg_para_struct));
    ascii_number = OslMalloc(number_len + 1);
    memset(ascii_number, 0, number_len + 1);
    mmi_ucs2_n_to_asc((CHAR*)ascii_number, (CHAR*)number, (number_len) * ENCODING_LENGTH);
    sendData.ascii_addr = ascii_number;
    sendData.flag = MMI_SMS_ENTRY_WRITE_REPLY;
    mmi_sms_write_msg_lanch(0, &sendData);
    OslMfree(ascii_number);
}
#endif /* __MOD_SMSAL__ */


#ifdef __MMI_MMS__
/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_send_mms
 * DESCRIPTION
 *  Send mms
 * PARAMETERS
 *  number            : [IN]    Phonenumber
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_send_mms(U16 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((CHAR*)number) == 0)
    {    
        cui_use_detail_dispaly_error_popup(STR_GLOBAL_NO_NUMBER);
        return;
    }

    mms_address_insert_hdlr((CHAR*)number);
}
#endif /* __MMI_MMS__ */


#ifdef __MMI_EMAIL__
/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_send_email
 * DESCRIPTION
 *  Send emial
 * PARAMETERS
 *  email_addr           : [IN]    Email address
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_send_email(U16 *email_addr)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_app_send_to((CHAR*)email_addr);
}
#endif /* __MMI_EMAIL__ */


#ifdef BROWSER_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_go_to_wap
 * DESCRIPTION
 *  Go to wap
 * PARAMETERS
 *  url_addr           : [IN]    URL address
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_go_to_wap(U16 *url_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wap_start_browser(WAP_BROWSER_GOTO_URL, (U8*)url_addr);
}


#ifdef __OP01__
/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_go_to_wap_by_confirm
 * DESCRIPTION
 *  Go to wap
 * PARAMETERS
 *  parent_gid         : [IN]    Parent group ID
 *  url_addr           : [IN]    URL address
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_go_to_wap_by_confirm(mmi_id parent_gid, U16 *url_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_use_detail_confirm.confirm_type = CUI_USE_DETAIL_CONFIRM_TYPE_GO_TO_WAP;
    g_use_detail_confirm.parent_gid = parent_gid;
    g_use_detail_confirm.url_addr = url_addr;
    cui_use_detail_enter_confirm(parent_gid, STR_ID_USE_DETAIL_GO_TO_WAP_CONFIRM, &g_use_detail_confirm);
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_enter_confirm
 * DESCRIPTION
 *  Go to wap
 * PARAMETERS 
 *  parent_gid         : [IN]    Parent group ID
 *  str_id             : [IN]    Confirm body string 
 *  user_tag           : [IN]    Confirm user data
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_enter_confirm(MMI_ID parent_id, U16 str_id, void *user_tag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = parent_id;
    arg.user_tag = (void *)user_tag;
    arg.f_enter_history = MMI_FALSE;
    arg.callback = (mmi_proc_func)cui_use_detail_cnf_cb;
    mmi_confirm_display((WCHAR *)(GetString(str_id)), MMI_EVENT_QUERY, &arg);
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_cnf_cb
 * DESCRIPTION
 *  confirm callback
 * PARAMETERS
 *  evt     [IN] Event structure passed by callback manager
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret cui_use_detail_cnf_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert_result = (mmi_alert_result_evt_struct*)evt;
    cui_use_detail_confirm_struct *confirm_data = (cui_use_detail_confirm_struct *)alert_result->user_tag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (confirm_data->confirm_type)
        {
            case CUI_USE_DETAIL_CONFIRM_TYPE_GO_TO_WAP:
                if (MMI_ALERT_CNFM_YES == alert_result->result)
                {
                    cui_use_detail_go_to_wap(confirm_data->url_addr);
                    mmi_alert_dismiss(alert_result->alert_id);
                    cui_use_detail_close_process(confirm_data->parent_gid, CUI_USE_DETAIL_RESULT_OK, CUI_USE_DETAIL_CLOSE_TYPE_DONE);
                }
                else if (MMI_ALERT_CNFM_NO == alert_result->result || MMI_ALERT_CNFM_CANCEL == alert_result->result || MMI_POPUP_INTERRUPT_EXIT == alert_result->result)
                {
                    mmi_alert_dismiss(alert_result->alert_id);
                    cui_use_detail_close_process(confirm_data->parent_gid, CUI_USE_DETAIL_RESULT_ABORT, CUI_USE_DETAIL_CLOSE_TYPE_DONE);
                }
                else
                {
                    /* do nothing */
                }
                break;

            default:
                break;
        }
    }
    return MMI_RET_OK;
}
#endif /* __OP01__ */


#if defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_add_to_bookmark
 * DESCRIPTION
 *  Add a URL to bookmark
 * PARAMETERS
 *  parent_gid        : [IN]    Parent group ID
 *  url_addr          : [IN]    URL address
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_add_to_bookmark(mmi_id parent_gid, U16 *url_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID bkm_cui_id;
    bkm_cui_id = cui_bkm_add_bkm_create(parent_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bkm_cui_id != GRP_ID_INVALID)
    {
        U8 *utf8_url = OslMalloc(CUI_USE_DETAIL_MAX_URL_LEN + 1);
        mmi_chset_ucs2_to_utf8_string(utf8_url, CUI_USE_DETAIL_MAX_URL_LEN + 1, (U8*)url_addr);
        cui_bkm_add_bkm_run(bkm_cui_id, (const U8*)utf8_url);
        OslMfree(utf8_url);
    }
}
#endif /* __MMI_BRW_BKM_INTERFACE_SUPPORT__ */
#endif /* BROWSER_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_list_lsk_hdlr
 * DESCRIPTION
 *  Set view list lsk key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_list_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_use_detail_single_obj_process(mmi_frm_group_get_active_id(), MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_list_csk_hdlr
 * DESCRIPTION
 *  Set view list csk key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_list_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_use_detail_single_obj_process(mmi_frm_group_get_active_id(), MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_list_rsk_hdlr
 * DESCRIPTION
 *  Set view list rsk key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_list_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_use_detail_close_process(mmi_frm_group_get_active_id(), CUI_USE_DETAIL_RESULT_ABORT, CUI_USE_DETAIL_CLOSE_TYPE_VIEW_ABORT);
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_enter_view_list
 * DESCRIPTION
 *  Enter view list screen
 * PARAMETERS
 *  group_id             : [IN]    Parent group id
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_enter_view_list(mmi_id group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_is_present(group_id, SCR_ID_CUI_USE_DETAIL_VIEW_LIST, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(group_id, SCR_ID_CUI_USE_DETAIL_VIEW_LIST);
    }

    mmi_frm_scrn_first_enter(
            group_id,
            SCR_ID_CUI_USE_DETAIL_VIEW_LIST,
            (FuncPtr)cui_use_detail_entry_view_list,
            NULL);
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_entry_view_list
 * DESCRIPTION
 *  View list screen entry function
 * PARAMETERS
 *  scr_info             : [IN]    screen info
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_entry_view_list(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    cui_use_detail_cntx_struct *use_detail_cntx;
    U8 number_of_items;
    U16 **list_of_items;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    scr_info->scrn_id,
                    NULL,
                    (FuncPtr)cui_use_detail_entry_view_list,
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }

    mmi_frm_scrn_set_leave_proc(scr_info->group_id, scr_info->scrn_id, (mmi_proc_func)cui_use_detail_view_list_delete_proc);
    guiBuffer = mmi_frm_scrn_get_gui_buf(scr_info->group_id, scr_info->scrn_id);
    RegisterHighlightHandler(cui_use_detail_list_hilite_hdlr);

    use_detail_cntx = (cui_use_detail_cntx_struct*)mmi_frm_group_get_user_data(scr_info->group_id);
    number_of_items = use_detail_cntx->obj_count;
    if (NULL == guiBuffer)
    {
        list_of_items = OslMalloc(sizeof(PU16) * number_of_items);
        for (i = 0; i < number_of_items; i++)
        {
            list_of_items[i] = use_detail_cntx->obj_list[i].detail_txt;
        }
        mmi_frm_scrn_set_user_data(scr_info->group_id, scr_info->scrn_id, (void*)list_of_items);
    }
    else
    {
        list_of_items = (U16 **)mmi_frm_scrn_get_user_data(scr_info->group_id, scr_info->scrn_id);
    }

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory53Screen(
        STR_GLOBAL_LIST,
        IMG_NONE,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (S32)number_of_items,
        (U8 **)list_of_items,
        (U16*)gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(cui_use_detail_list_rsk_hdlr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_view_list_delete_proc
 * DESCRIPTION
 *  View list screen proc function
 * PARAMETERS
 *  evt             : [IN]    screen ievent
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret cui_use_detail_view_list_delete_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_evt_struct *scenario_evt = (mmi_scenario_evt_struct*)evt;
    U16 **list_of_items = (U16 **)mmi_frm_scrn_get_user_data(scenario_evt->targ_group, scenario_evt->targ_scrn);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
            if (list_of_items != NULL)
            {
                OslMfree(list_of_items);
            }
        break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_get_hilite_index
 * DESCRIPTION
 *  Get the hilite index of view list
 * PARAMETERS
 *  item_index            : [IN]    hilight item
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_list_hilite_hdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id group_id;
    cui_use_detail_cntx_struct *use_detail_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_id = mmi_frm_group_get_active_id();
    use_detail_cntx = (cui_use_detail_cntx_struct*)mmi_frm_group_get_user_data(group_id);
    use_detail_cntx->obj_index = item_index;
    cui_use_detail_set_lsk_csk_info(use_detail_cntx, SCR_ID_CUI_USE_DETAIL_VIEW_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_set_lsk_csk_info
 * DESCRIPTION
 *  Get the hilite index of view list
 * PARAMETERS
 *  use_detail_cntx       : [IN]    cntx pointer
 *  screen_id             : [IN]    screen id
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_set_lsk_csk_info(cui_use_detail_cntx_struct *use_detail_cntx, mmi_id screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_use_detail_type_enum type;
    cui_use_detail_operate_enum operate;
    U16 lsk_id = STR_GLOBAL_OPTIONS;
    U16 img_id = IMG_GLOBAL_COMMON_CSK;
    U32 i;
    HandlePtr lsk_hdlr = 0;
    HandlePtr csk_hdlr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    type = use_detail_cntx->obj_list[use_detail_cntx->obj_index].type;
    operate = use_detail_cntx->mode_list[type].operate;

    cui_use_detail_check_available_operate_num(operate, &(use_detail_cntx->exe_operate));

    for (i = 0; i < CUI_USE_DETAIL_OPERATE_NUM; i++)
    {
        if ((CUI_USE_DETAIL_OPERATE_CALL << i) & use_detail_cntx->exe_operate)
        {
            img_id = g_image_list[i];
            use_detail_cntx->exe_operate = CUI_USE_DETAIL_OPERATE_CALL << i;
            break;
        }
    }

    if (CUI_USE_DETIAL_OPERATE_NO_OPERATE == use_detail_cntx->mode_list[type].operate)
    {
        lsk_id = 0;
        img_id = 0;
    }
    else
    {
        if (use_detail_cntx->mode_list[type].edit_flag && screen_id != SCR_ID_CUI_USE_DETAIL_EDIT)
        {
            lsk_id = STR_GLOBAL_EDIT;
            img_id = IMG_GLOBAL_COMMON_CSK;
        }
        else if (CUI_USE_DETAIL_TYPE_URL != type)
        {
            img_id = IMG_GLOBAL_COMMON_CSK;
        }

        if (SCR_ID_CUI_USE_DETAIL_EDIT == screen_id)
        {
            lsk_hdlr = cui_use_detail_edit_lsk_hdlr;
            csk_hdlr = cui_use_detail_edit_csk_hdlr;
        }
        else if (SCR_ID_CUI_USE_DETAIL_VIEW_LIST == screen_id)
        {
            lsk_hdlr = cui_use_detail_list_lsk_hdlr;
            if (CUI_USE_DETAIL_TYPE_URL != type)
            {
                csk_hdlr = cui_use_detail_list_lsk_hdlr;
            }
            else
            {
                csk_hdlr = cui_use_detail_list_csk_hdlr;
            }
        }
    }

    ChangeLeftSoftkey(lsk_id, 0);
    ChangeCenterSoftkey(0, img_id);
    SetLeftSoftkeyFunction(lsk_hdlr, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(csk_hdlr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_edit_lsk_hdlr
 * DESCRIPTION
 *  Set edit screen lsk key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_edit_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_use_detail_pre_operate_hdlr(mmi_frm_group_get_active_id(), MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_edit_csk_hdlr
 * DESCRIPTION
 *  Set edit screen csk key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_edit_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_use_detail_pre_operate_hdlr(mmi_frm_group_get_active_id(), MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_edit_rsk_hdlr
 * DESCRIPTION
 *  Set edit screen rsk key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_edit_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_use_detail_close_process(mmi_frm_group_get_active_id(), CUI_USE_DETAIL_RESULT_ABORT, CUI_USE_DETAIL_CLOSE_TYPE_EDIT_ABORT);
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_enter_editor
 * DESCRIPTION
 *  Enter edit screen
 * PARAMETERS
 *  group_id         : [IN]    Parent group ID
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_enter_editor(mmi_id group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_first_enter(
            group_id,
            SCR_ID_CUI_USE_DETAIL_EDIT,
            (FuncPtr)cui_use_detail_entry_editor,
            NULL);
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_entry_editor
 * DESCRIPTION
 *  Edit screen entry function
 * PARAMETERS
 *  scr_info         : [IN]    Screen info passed by FW
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_entry_editor(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    cui_use_detail_type_enum type;
    cui_use_detail_cntx_struct *use_detail_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    scr_info->scrn_id,
                    NULL,
                    (FuncPtr)cui_use_detail_entry_editor,
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_gui_buf(scr_info->group_id, scr_info->scrn_id);
    use_detail_cntx = (cui_use_detail_cntx_struct*)mmi_frm_group_get_user_data(scr_info->group_id);
    type = use_detail_cntx->obj_list[use_detail_cntx->obj_index].type;

    cui_use_detail_set_dialer_keypad();

    ShowCategory16Screen(
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*)use_detail_cntx->edit_buffer,
        mapping_table[type].max_len,
        guiBuffer);

    cui_use_detail_set_lsk_csk_info(use_detail_cntx, scr_info->scrn_id);
    SetCategory16RightSoftkeyFunction(cui_use_detail_edit_rsk_hdlr, KEY_EVENT_UP);
#ifdef __MMI_UCM__
    SetKeyHandler(cui_use_detail_dial, KEY_SEND, KEY_EVENT_UP);
#endif /* __MMI_UCM__ */
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_set_dialer_keypad
 * DESCRIPTION
 *  Set dialer keypad
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_set_dialer_keypad(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef  __MMI_TOUCH_SCREEN__
#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
#ifdef __MMI_UCM__
#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
    cui_use_detail_set_dynamic_sim_kepad_hdlr();
#else /* defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__) */
#if (MMI_MAX_SIM_NUM == 2)
    if (srv_nw_usab_is_usable(MMI_SIM1))
    {
        SetDialingKeypadCallHandler(cui_use_detail_dial_sim1);
    }

    if (srv_nw_usab_is_usable(MMI_SIM2))
    {
        SetDialingKeypadCall2Handler(cui_use_detail_dial_sim2);
    }
#else /* (MMI_MAX_SIM_NUM == 2) */
    SetDialingKeypadCallHandler(cui_use_detail_dial);
#endif /* (MMI_MAX_SIM_NUM == 2) */
#endif /* defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__) */
#endif /* __MMI_UCM__ */
#endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */
#endif /* __MMI_TOUCH_SCREEN__ */
}


#ifdef  __MMI_TOUCH_SCREEN__
#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
#ifdef __MMI_UCM__
#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_set_dynamic_sim_kepad_hdlr
 * DESCRIPTION
 *  Set Dialer keypad handler for dynamic sim
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_set_dynamic_sim_kepad_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U8 count = 0;
    mmi_sim_enum sim_id;
    MMI_BOOL ecc_call = MMI_FALSE;
    U8 index = 0;
    void (*handler[])(void) = {
    #if (MMI_MAX_SIM_NUM >= 2)
        cui_use_detail_dial_sim1,
        cui_use_detail_dial_sim2,
    #if (MMI_MAX_SIM_NUM >= 3)
        cui_use_detail_dial_sim3,
    #if (MMI_MAX_SIM_NUM >= 4)
        cui_use_detail_dial_sim4,
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    if (0 == srv_sim_ctrl_get_num_of_inserted())
    {
        ecc_call = MMI_TRUE;
        SetDialingKeypadEmergencyFunckey(MMI_TRUE);
    }
    else
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
    {
        for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
        {
            if (srv_nw_usab_is_usable(sim_id))
            {
                count++;
                index = i;
            }
        }
    }

    if (MMI_TRUE == ecc_call || 0 == count)
    {
        SetDialingKeypadCallHandler(cui_use_detail_dial);
    }
    else if (1 == count)
    {
        SetDialingKeypadCallHandler(handler[index]);
    }
    else
    {
        SetDialingKeypadCallHandler(cui_use_detail_entry_sim_select);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_entry_sim_select
 * DESCRIPTION
 *  Shows the sim selection screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_entry_sim_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_id menu_id;
    mmi_sim_enum sim_id;
    mmi_id group_id = mmi_frm_group_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_id = cui_menu_create(
                    group_id,
                    CUI_MENU_SRC_TYPE_RESOURCE,
                    CUI_MENU_TYPE_OPTION,
                    MENU_ID_USE_DETAIL_SIM_SELECT,
                    MMI_FALSE,
                    NULL);

    cui_menu_set_default_title_string_by_id(menu_id, STR_ID_USE_DETAIL_SIM_SELECT);

    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {
        if (srv_nw_usab_is_usable(sim_id))
        {
            cui_menu_set_item_hidden(menu_id, MENU_ID_USE_DETAIL_FROM_SIM1 + i, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_id, MENU_ID_USE_DETAIL_FROM_SIM1 + i, MMI_TRUE);
        }
    }

    cui_menu_run(menu_id);
}
#endif /* defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__) */


#if (MMI_MAX_SIM_NUM >= 4)
/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_dial_sim4
 * DESCRIPTION
 *  Dail from SIM4
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_dial_sim4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_use_detail_dial_by_call_type_hdlr(SRV_UCM_VOICE_CALL_TYPE_SIM4);
}
#endif /* (MMI_MAX_SIM_NUM >= 4) */


#if (MMI_MAX_SIM_NUM >= 3)
/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_dial_sim3
 * DESCRIPTION
 *  Dail from SIM3
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_dial_sim3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_use_detail_dial_by_call_type_hdlr(SRV_UCM_VOICE_CALL_TYPE_SIM3);
}
#endif /* (MMI_MAX_SIM_NUM >= 3) */


#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_dial_sim1
 * DESCRIPTION
 *  Dail from SIM1
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_dial_sim1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_use_detail_dial_by_call_type_hdlr(SRV_UCM_VOICE_CALL_TYPE);
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_dial_sim2
 * DESCRIPTION
 *  Dail from SIM2
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_dial_sim2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_use_detail_dial_by_call_type_hdlr(SRV_UCM_VOICE_CALL_TYPE_SIM2);
}
#endif /* (MMI_MAX_SIM_NUM >= 2) */
#endif /* __MMI_UCM__ */
#endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */
#endif /* __MMI_TOUCH_SCREEN__ */


#ifdef __MMI_UCM__
/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_dial
 * DESCRIPTION
 *  Dail from all SIM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_use_detail_dial_by_call_type_hdlr(SRV_UCM_CALL_TYPE_NO_DATA_CSD);
}


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_dial_by_call_type_hdlr
 * DESCRIPTION
 *  Dial by call type hdlr
 * PARAMETERS
 *  dial_type         : [IN]    dial type
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_dial_by_call_type_hdlr(srv_ucm_call_type_enum dial_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id group_id = mmi_frm_group_get_active_id();
    cui_use_detail_cntx_struct* use_detail_cntx = (cui_use_detail_cntx_struct*)mmi_frm_group_get_user_data(group_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_use_detail_dial_by_call_type(dial_type, use_detail_cntx->edit_buffer);
    cui_use_detail_close_process(group_id, CUI_USE_DETAIL_RESULT_OK, CUI_USE_DETAIL_CLOSE_TYPE_DONE);

}
#endif /* __MMI_UCM__ */


#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_add_sim_name
 * DESCRIPTION
 *  Set menu item string with SIM name
 * PARAMETERS
 *  owner_gid       [IN]    Menu GID from cui_menu_create
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_add_sim_name(mmi_id owner_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_sim_enum sim_id;
    WCHAR *sim_name;
	WCHAR menu_str[MAX_SUBMENU_CHARACTERS];
    U16 string_table[] = {
    #if (MMI_MAX_SIM_NUM >= 2)
        STR_ID_USE_DETAIL_FROM_SIM1,
        STR_ID_USE_DETAIL_FROM_SIM2,
    #if (MMI_MAX_SIM_NUM >= 3)
        STR_ID_USE_DETAIL_FROM_SIM3,
    #if (MMI_MAX_SIM_NUM >= 4)
        STR_ID_USE_DETAIL_FROM_SIM4,
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {
        sim_name = mmi_netset_get_sim_name(sim_id);
        if (sim_name)
        {
            kal_wsprintf(menu_str, "%w(%w)", GetString(string_table[i]), mmi_netset_get_sim_name(sim_id));
            cui_menu_set_item_string(owner_gid, MENU_ID_USE_DETAIL_FROM_SIM1 + i, menu_str);
        }
    }
}
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */


#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_sim_select_hdlr
 * DESCRIPTION
 *  Dial call when select one sim
 * PARAMETERS
 *  highlighted_menu_id       [IN]    highlighted menu item
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_sim_select_hdlr(mmi_menu_id highlighted_menu_id, mmi_id group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_call_type_enum voice_type[] = {
        SRV_UCM_VOICE_CALL_TYPE,
        SRV_UCM_VOICE_CALL_TYPE_SIM2,
        SRV_UCM_VOICE_CALL_TYPE_SIM3,
        SRV_UCM_VOICE_CALL_TYPE_SIM4,
        };

    cui_use_detail_cntx_struct* use_detail_cntx = (cui_use_detail_cntx_struct*)mmi_frm_group_get_user_data(group_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UCM__
    cui_use_detail_dial_by_call_type(voice_type[highlighted_menu_id - MENU_ID_USE_DETAIL_FROM_SIM1], use_detail_cntx->edit_buffer);
#endif /* __MMI_UCM__ */
    cui_use_detail_close_process(group_id, CUI_USE_DETAIL_RESULT_OK, CUI_USE_DETAIL_CLOSE_TYPE_DONE);
}
#endif /* defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__) */


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_dispaly_error_popup
 * DESCRIPTION
 *  Send mms
 * PARAMETERS
 *  str_id            : [IN]    the string of error reason
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_use_detail_dispaly_error_popup(MMI_STR_ID str_id)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_ext(str_id, MMI_EVENT_FAILURE, NULL);
}



