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
 * UMApperance.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "UMDefs.h"
#include "UMProt.h"
#include "mmi_rp_app_unifiedmessage_def.h"
#include "UCMGProt.h"
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "MMI_features_switch.h"
#include "MMI_features_type.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "gui_typedef.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_list.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_util.h"
#include "wgui_categories_email.h"
#include "mmi_rp_app_sms_def.h"
#include "gui_data_types.h"
#include "gui.h"
#include "wgui_touch_screen.h"
#include "wgui_fixed_menus.h"
#include "wgui_categories_popup.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_include.h"
#include "string.h"
#include "wgui_categories.h"
#include "gui_effect_oem.h"

#ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
MMI_BOOL mmi_um_ui_aprc_thread_enhance_draw(mmi_um_ui_aprc_st_union *aprc_cntx, 
                                 mmi_um_ui_aprc_st_enum aprc_st_type);
MMI_BOOL mmi_um_ui_aprc_thread_enhance_redraw(mmi_um_ui_aprc_st_union *aprc_cntx, 
                                   mmi_um_ui_aprc_st_enum aprc_st_type, 
                                   mmi_um_ui_aprc_redraw_type_enum type);
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
MMI_BOOL mmi_um_ui_aprc_thread_enhance_ms_draw(mmi_um_ui_aprc_st_union *aprc_cntx, 
                                 mmi_um_ui_aprc_st_enum aprc_st_type);

MMI_BOOL mmi_um_ui_aprc_thread_enhance_ms_redraw(mmi_um_ui_aprc_st_union *aprc_cntx, 
                                   mmi_um_ui_aprc_st_enum aprc_st_type, 
                                   mmi_um_ui_aprc_redraw_type_enum type);
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
#endif /* __MMI_UM_CONVERSATION_BOX_ENHANCE__ */
MMI_BOOL mmi_um_ui_aprc_general_fw_function(mmi_um_ui_aprc_general_cntx_struct *general_cntx)
{
    if (MMI_FALSE == mmi_frm_scrn_enter(         
                                general_cntx->grp_id, 
                                general_cntx->scrn_id, 
                                (FuncPtr) general_cntx->exit_func, 
                                (FuncPtr) general_cntx->entry_func, 
                                MMI_FRM_SCRN_GROUP))
    {
        /* Could not display, insert to history */
        mmi_um_ui_aprc_reg_leave_proc(general_cntx);
        return MMI_FALSE;
    }

    mmi_um_ui_aprc_reg_leave_proc(general_cntx);

    RegisterHighlightHandler(general_cntx->hilite_hdlr);
    mmi_um_ui_aprc_enable_softkey(general_cntx);
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_set_cntx
 * DESCRIPTION
 *  It is used to set the appearnce context from the input.
 *  Because the screen handler does not know the drawing function of each 
 *  appearance, this function just sets the draw and re-draw in the aprc_cntx.
 *  Hence, screen handler does not need to know the detail of appearance. It
 *  just calls the draw/redraw function to display/update the screen.
 *
 * PARAMETERS
 *  aprc_node           [OUT]: the appearance context
 *  aprc_type           [IN]: the appearance type
 *
 * RETURNS
 *  MMI_TRUE: create successfully
 *  MMI_FALSE: create fail
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_set_cntx(mmi_um_ui_aprc_node_struct    *aprc_node, 
                                 mmi_um_ui_aprc_st_enum         aprc_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aprc_node->st_type = aprc_type;
    switch (aprc_type)
    {
        case MMI_UM_UI_SCRN_TYPE_MAIN_MENU:
        {
            aprc_node->type = MMI_UM_UI_APRC_53;
            aprc_node->draw_func = mmi_um_ui_aprc_53_draw;
            aprc_node->redraw_func = mmi_um_ui_aprc_53_redraw;
            break;
        }
        case MMI_UM_UI_SCRN_TYPE_FOLDER:
        {
            SET_GENERAL_FOLDER_APRC_TYPE(aprc_node->type);
        #if __MMI_UNIFIED_MESSAGE_FOLDER_LIST_STYLE__ == __UM_LIST_INLINE__
            aprc_node->draw_func = mmi_um_ui_aprc_268_draw;
            aprc_node->redraw_func = mmi_um_ui_aprc_268_redraw;
        #elif __MMI_UNIFIED_MESSAGE_FOLDER_LIST_STYLE__ == __UM_LIST_NORMAL__
            aprc_node->draw_func = mmi_um_ui_aprc_263_draw;
            aprc_node->redraw_func = mmi_um_ui_aprc_263_redraw;
        #endif /* __MMI_UNIFIED_MESSAGE_FOLDER_LIST_STYLE__ */
            break;
        }
    #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
        case MMI_UM_UI_SCRN_TYPE_MS:
        {
            SET_MS_APRC_TYPE(aprc_node->type);
        #if __MMI_UNIFIED_MESSAGE_FOLDER_LIST_STYLE__ == __UM_LIST_INLINE__
            aprc_node->draw_func = mmi_um_ui_aprc_1002_draw;
            aprc_node->redraw_func = mmi_um_ui_aprc_1002_redraw;
        #elif __MMI_UNIFIED_MESSAGE_FOLDER_LIST_STYLE__ == __UM_LIST_NORMAL__
            aprc_node->draw_func = mmi_um_ui_aprc_267_draw;
            aprc_node->redraw_func = mmi_um_ui_aprc_267_redraw;
        #endif /* __MMI_UNIFIED_MESSAGE_FOLDER_LIST_STYLE__ */
            break;
        }
    #endif /* __UNIFIED_MESSAGE_MARK_SEVERAL__ */
        case MMI_UM_UI_SCRN_TYPE_LIST:
        {
            aprc_node->type = MMI_UM_UI_APRC_53;
            aprc_node->draw_func = mmi_um_ui_aprc_53_draw;
            aprc_node->redraw_func = mmi_um_ui_aprc_53_redraw;
            break;
        }
        case MMI_UM_UI_SCRN_TYPE_LOADING:
        {
            aprc_node->st_type = aprc_type;
            aprc_node->type = MMI_UM_UI_APRC_165;
            aprc_node->draw_func = mmi_um_ui_aprc_165_draw;
            aprc_node->redraw_func = mmi_um_ui_aprc_165_redraw;
            break;
        }
    #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
        case MMI_UM_UI_SCRN_TYPE_LOADING_PGRS:
        {
            aprc_node->type = MMI_UM_UI_APRC_6003;
            aprc_node->draw_func = mmi_um_ui_aprc_6003_draw;
            aprc_node->redraw_func = mmi_um_ui_aprc_6003_redraw;
            break;
        }
    #endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
    #ifdef __MMI_UM_CONVERSATION_BOX__
    case MMI_UM_UI_SCRN_TYPE_THRD_MSG:
    #ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
        {
            aprc_node->type = MMI_UM_UI_APRC_THREAD_ENHANCE;
            aprc_node->draw_func = mmi_um_ui_aprc_thread_enhance_draw;
            aprc_node->redraw_func = mmi_um_ui_aprc_thread_enhance_redraw;
            break;
        }
    #endif
        case MMI_UM_UI_SCRN_TYPE_CONVERSATION_BOX:
        {
            aprc_node->type = MMI_UM_UI_APRC_263;
            aprc_node->draw_func = mmi_um_ui_aprc_263_draw;
            aprc_node->redraw_func = mmi_um_ui_aprc_263_redraw;
            break;
        }
    #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    
    case MMI_UM_UI_SCRN_TYPE_MS_THRD_MSG:
#ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
        {
            aprc_node->type = MMI_UM_UI_APRC_THREAD_ENHANCE_MS;
            aprc_node->draw_func = mmi_um_ui_aprc_thread_enhance_ms_draw;
            aprc_node->redraw_func = mmi_um_ui_aprc_thread_enhance_ms_redraw;
            break;
        }
#endif
        case MMI_UM_UI_SCRN_TYPE_MS_CONVERSATION_BOX:
        {
            aprc_node->type = MMI_UM_UI_APRC_267;
            aprc_node->draw_func = mmi_um_ui_aprc_267_draw;
            aprc_node->redraw_func = mmi_um_ui_aprc_267_redraw;
            break;
        }
    #endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
        case MMI_UM_UI_SCRN_TYPE_CONVERSATION_SETTING:
        {
            aprc_node->type = MMI_UM_UI_APRC_36;
            aprc_node->draw_func = mmi_um_ui_aprc_36_draw;
            aprc_node->redraw_func = mmi_um_ui_aprc_36_redraw;
            break;
        }
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
#if (defined(__OP01__) && (MMI_MAX_SIM_NUM >= 2))
        case MMI_UM_UI_SCRN_TYPE_PREFER_SIM_SETTING:
        {
            aprc_node->type = MMI_UM_UI_APRC_36;
            aprc_node->draw_func = mmi_um_ui_aprc_36_draw;
            aprc_node->redraw_func = mmi_um_ui_aprc_36_redraw;
            break;
        }
#endif
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_263_draw
 * DESCRIPTION
 *  It is used to draw the category 263 screen. It needs to call several
 *  framework APIs to accomplish displaying a screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *  aprc_st_type        [IN]: The screen type of this appearance
 *
 * RETURNS
 *  MMI_TRUE: the screen is displayed
 *  MMI_FALSE: the screen is not displayed
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_263_draw(mmi_um_ui_aprc_st_union *aprc_cntx, 
                                 mmi_um_ui_aprc_st_enum aprc_st_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *title_str;
    U8 *gui_buffer;
    S32 list_not_ready;
    list_menu_category_history *list_gui_buffer;
    mmi_um_ui_aprc_struct_union *aprc_int_cntx;
    mmi_um_ui_aprc_263_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aprc_int_cntx= OslMalloc(sizeof(mmi_um_ui_aprc_struct_union));
    aprc = &(aprc_int_cntx->aprc_263);
    mmi_um_ui_aprc_set_int_cntx(aprc_int_cntx, MMI_UM_UI_APRC_263, aprc_cntx, aprc_st_type);

    if (MMI_FALSE == mmi_um_ui_aprc_general_fw_function(&(aprc->general_aprc_cntx)))
    {
        OslMfree(aprc_int_cntx);
        return MMI_TRUE;
    }

    if (aprc->general_aprc_cntx.gui_buffer == NULL)
    {
        /* use the history gui buffer */
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
        /* arrange the highlight */
        if (gui_buffer != NULL)
        {
            list_gui_buffer = (list_menu_category_history *)gui_buffer;
            list_gui_buffer->highlighted_item = aprc->general_aprc_cntx.hilite_idx;
        }
    }
    else
    {
        gui_buffer = aprc->general_aprc_cntx.gui_buffer;
    }
    wgui_cat_set_list_menu_empty_lable(get_string(STR_UM_EMPTY_MSG_ID));
#ifdef __MMI_ICON_BAR_SUPPORT__
    mmi_um_ui_aprc_reg_toolbar_cb_hdlr(&(aprc->general_aprc_cntx.tb_hdlr));
    /* If num_of_item == 0, the toolbar should be dimmed */
    if (0 < aprc->general_aprc_cntx.tb_hdlr.num_of_toolbar &&
        0 == aprc->general_aprc_cntx.num_of_item)
    {
        U16 i;

        for (i = 0 ; i < aprc->general_aprc_cntx.tb_hdlr.num_of_toolbar ; i++)
        {
            wgui_icon_bar_set_item_enable_state(
                            i, 
                            MMI_FALSE);
        }
    }
#endif /* __MMI_ICON_BAR_SUPPORT__ */

    /* If it has the special title, it needs to display a specified string in title */
    if (NULL == aprc->special_title)
    {
        title_str = (U8 *) get_string(aprc->general_aprc_cntx.title_str_id);
    }
    else
    {
        title_str = aprc->special_title;
    }

#ifdef __MMI_UM_CONVERSATION_BOX__
    /* Set the style of the box */
    wgui_cat263_set_display_style(aprc->folder_style);
#endif /* __MMI_UM_CONVERSATION_BOX__ */
#if (MMI_MAX_SIM_NUM >= 2)
#ifdef __MMI_UM_CONVERSATION_BOX__
    if (aprc_st_type != MMI_UM_UI_SCRN_TYPE_CONVERSATION_BOX)
#endif /* __MMI_UM_CONVERSATION_BOX__ */
    {
        wgui_cat_list_set_display_more_icon(MMI_TRUE);
    }
#endif
#ifndef __MMI_MAINLCD_96X64__ 
    ShowCategory263Screen(
        title_str,
        aprc->general_aprc_cntx.title_icon_id,
        aprc->general_aprc_cntx.lsk_str_id,
        aprc->general_aprc_cntx.lsk_icon_id,
        aprc->general_aprc_cntx.rsk_str_id,
        aprc->general_aprc_cntx.rsk_icon_id,
        aprc->general_aprc_cntx.num_of_item,
        aprc->get_item_cb,
        aprc->get_item_hint_cb,
        aprc->general_aprc_cntx.hilite_idx,
        IMG_MESSAGE_READ,   
        gui_buffer,
        &list_not_ready);
#else
	wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON);
	wgui_cat1032_show(
        (WCHAR*)title_str,
        (PU8)GetImage(aprc->general_aprc_cntx.title_icon_id),
        (WCHAR*)GetString(aprc->general_aprc_cntx.lsk_str_id),
        (PU8)aprc->general_aprc_cntx.lsk_icon_id,
        (WCHAR*)GetString(aprc->general_aprc_cntx.rsk_str_id),
        (PU8)aprc->general_aprc_cntx.rsk_icon_id,
        aprc->general_aprc_cntx.num_of_item,
        aprc->get_item_cb,
        aprc->get_item_hint_cb,
        aprc->general_aprc_cntx.hilite_idx,
		0,
        IMG_MESSAGE_READ,   /* for icon position used */
		0,
        gui_buffer,
        &list_not_ready);
#endif
    if (aprc->hilite_notify_cb != NULL)
    {
        wgui_async_list_register_update_callback(aprc->hilite_notify_cb);
    }

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    mmi_um_ui_aprc_reg_intuitive_cmd_cb_hdlr(aprc->general_aprc_cntx.intuitive_cmd_cb_func);
#endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */

    /* the screen does not display */
    if (list_not_ready)
    {
        OslMfree(aprc_int_cntx);
        return MMI_FALSE;
    }

    mmi_um_ui_aprc_set_key_hdlr(&(aprc->general_aprc_cntx.key_hdlr));

    OslMfree(aprc_int_cntx);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_263_redraw
 * DESCRIPTION
 *  It is used to redraw the category 263 screen. It needs to call several
 *  framework APIs to accomplish displaying a screen. Sometiems it needs to
 *  update the screen. Screen handler should call this API to update the
 *  current screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *  aprc_st_type        [IN]: The screen type of this appearance
 *  type                [IN]: Redrawing region
 *
 * RETURNS
 *  MMI_TRUE: the screen updates finished
 *  MMI_FALSE: the screen updates fail
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_263_redraw(mmi_um_ui_aprc_st_union *aprc_cntx, 
                                   mmi_um_ui_aprc_st_enum aprc_st_type, 
                                   mmi_um_ui_aprc_redraw_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_UM_ULTRA_SLIM__
    MMI_BOOL result;
    mmi_um_ui_aprc_struct_union *aprc_int_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aprc_int_cntx= OslMalloc(sizeof(mmi_um_ui_aprc_struct_union));
    mmi_um_ui_aprc_set_int_cntx(aprc_int_cntx, MMI_UM_UI_APRC_263, aprc_cntx, aprc_st_type);
    result = MMI_TRUE;

#ifdef __MMI_ICON_BAR_SUPPORT__
    if ((type & MMI_UM_UI_APRC_REDRAW_TB_STATUS) == MMI_UM_UI_APRC_REDRAW_TB_STATUS)
    {
        result = mmi_um_ui_aprc_263_redraw_tb_status(aprc_int_cntx);
    }
#endif /* __MMI_ICON_BAR_SUPPORT__ */

    OslMfree(aprc_int_cntx);
    return result;
#else
    return MMI_TRUE;
#endif
}

#ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_263_draw
 * DESCRIPTION
 *  It is used to draw the category 263 screen. It needs to call several
 *  framework APIs to accomplish displaying a screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *  aprc_st_type        [IN]: The screen type of this appearance
 *
 * RETURNS
 *  MMI_TRUE: the screen is displayed
 *  MMI_FALSE: the screen is not displayed
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_thread_enhance_draw(mmi_um_ui_aprc_st_union *aprc_cntx, 
                                 mmi_um_ui_aprc_st_enum aprc_st_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *title_str;
    U8 *gui_buffer;
    S32 list_not_ready;
    list_menu_category_history *list_gui_buffer;
    mmi_um_ui_aprc_struct_union *aprc_int_cntx;
    mmi_um_ui_aprc_263_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aprc_int_cntx= OslMalloc(sizeof(mmi_um_ui_aprc_struct_union));
    aprc = &(aprc_int_cntx->aprc_263);
    mmi_um_ui_aprc_set_int_cntx(aprc_int_cntx, MMI_UM_UI_APRC_THREAD_ENHANCE, aprc_cntx, aprc_st_type);

    if (MMI_FALSE == mmi_um_ui_aprc_general_fw_function(&(aprc->general_aprc_cntx)))
    {
        OslMfree(aprc_int_cntx);
        return MMI_TRUE;
    }

    if (aprc->general_aprc_cntx.gui_buffer == NULL)
    {
        /* use the history gui buffer */
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
        /* arrange the highlight */
        if (gui_buffer != NULL)
        {
            list_gui_buffer = (list_menu_category_history *)gui_buffer;
            list_gui_buffer->highlighted_item = aprc->general_aprc_cntx.hilite_idx;
        }
    }
    else
    {
        gui_buffer = aprc->general_aprc_cntx.gui_buffer;
    }
    wgui_cat_set_list_menu_empty_lable(get_string(STR_UM_EMPTY_MSG_ID));
#ifdef __MMI_ICON_BAR_SUPPORT__
    mmi_um_ui_aprc_reg_toolbar_cb_hdlr(&(aprc->general_aprc_cntx.tb_hdlr));
    /* If num_of_item == 0, the toolbar should be dimmed */
    if (0 < aprc->general_aprc_cntx.tb_hdlr.num_of_toolbar &&
        0 == aprc->general_aprc_cntx.num_of_item)
    {
        U16 i;

        for (i = 0 ; i < aprc->general_aprc_cntx.tb_hdlr.num_of_toolbar ; i++)
        {
            wgui_icon_bar_set_item_enable_state(
                            i, 
                            MMI_FALSE);
        }
    }
#endif /* __MMI_ICON_BAR_SUPPORT__ */

    /* If it has the special title, it needs to display a specified string in title */
    if (NULL == aprc->special_title)
    {
        title_str = (U8 *) get_string(aprc->general_aprc_cntx.title_str_id);
    }
    else
    {
        title_str = aprc->special_title;
    }

    if (aprc->general_aprc_cntx.num_of_item == 0)
    {
        aprc->general_aprc_cntx.lsk_str_id = 0;
        aprc->general_aprc_cntx.lsk_icon_id = 0;
    }
    if (NULL != gui_buffer)
    {
        change_list_menu_category_history(
            (U8*)gui_buffer, 
            aprc->general_aprc_cntx.hilite_idx, 
            aprc->general_aprc_cntx.num_of_item, 
            0);
    }
    wgui_cat_conversation_show(
        title_str,
        GetImage(aprc->general_aprc_cntx.title_icon_id),
        aprc->general_aprc_cntx.lsk_str_id,
        aprc->general_aprc_cntx.rsk_str_id,
        aprc->general_aprc_cntx.num_of_item,
        mmi_um_ui_sh_thread_enhance_get_async_item,           //get item info for image and string.
        NULL,
        NULL,
        aprc->general_aprc_cntx.hilite_idx,
        IMG_MESSAGE_READ,                                  //default icon for calc width and height
        gui_buffer,
        &list_not_ready);

    if (aprc->hilite_notify_cb != NULL)
    {
        wgui_async_list_register_update_callback(aprc->hilite_notify_cb);
    }

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    mmi_um_ui_aprc_reg_intuitive_cmd_cb_hdlr(aprc->general_aprc_cntx.intuitive_cmd_cb_func);
#endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */

    mmi_um_ui_aprc_set_key_hdlr(&(aprc->general_aprc_cntx.key_hdlr));

    OslMfree(aprc_int_cntx);
	
    /* the screen does not display */
    if (list_not_ready)
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_263_redraw
 * DESCRIPTION
 *  It is used to redraw the category 263 screen. It needs to call several
 *  framework APIs to accomplish displaying a screen. Sometiems it needs to
 *  update the screen. Screen handler should call this API to update the
 *  current screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *  aprc_st_type        [IN]: The screen type of this appearance
 *  type                [IN]: Redrawing region
 *
 * RETURNS
 *  MMI_TRUE: the screen updates finished
 *  MMI_FALSE: the screen updates fail
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_thread_enhance_redraw(mmi_um_ui_aprc_st_union *aprc_cntx, 
                                   mmi_um_ui_aprc_st_enum aprc_st_type, 
                                   mmi_um_ui_aprc_redraw_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    mmi_um_ui_aprc_struct_union *aprc_int_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aprc_int_cntx= OslMalloc(sizeof(mmi_um_ui_aprc_struct_union));
    mmi_um_ui_aprc_set_int_cntx(aprc_int_cntx, MMI_UM_UI_APRC_THREAD_ENHANCE, aprc_cntx, aprc_st_type);
    result = MMI_TRUE;

#ifdef __MMI_ICON_BAR_SUPPORT__
    if ((type & MMI_UM_UI_APRC_REDRAW_TB_STATUS) == MMI_UM_UI_APRC_REDRAW_TB_STATUS)
    {
        result = mmi_um_ui_aprc_263_redraw_tb_status(aprc_int_cntx);
    }
#endif /* __MMI_ICON_BAR_SUPPORT__ */

    OslMfree(aprc_int_cntx);
    return result;
}

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_thread_enhance_ms_draw
 * DESCRIPTION
 *  It is used to draw the category 267 screen. It needs to call several
 *  framework APIs to accomplish displaying a screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *  aprc_st_type        [IN]: The screen type of this appearance
 *
 * RETURNS
 *  MMI_TRUE: the screen is displayed
 *  MMI_FALSE: the screen is not displayed
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_thread_enhance_ms_draw(mmi_um_ui_aprc_st_union *aprc_cntx, 
                                 mmi_um_ui_aprc_st_enum aprc_st_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *title_str;
    U8 *gui_buffer;
    S32 list_not_ready;
    list_menu_category_history *list_gui_buffer;
    mmi_um_ui_aprc_struct_union *aprc_int_cntx;
    mmi_um_ui_aprc_267_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aprc_int_cntx= OslMalloc(sizeof(mmi_um_ui_aprc_struct_union));
    aprc = &(aprc_int_cntx->aprc_267);
    mmi_um_ui_aprc_set_int_cntx(aprc_int_cntx, MMI_UM_UI_APRC_267, aprc_cntx, aprc_st_type);

    if (MMI_FALSE == mmi_um_ui_aprc_general_fw_function(&(aprc->general_aprc_cntx)))
    {
        OslMfree(aprc_int_cntx);
        return MMI_TRUE;
    }
    
    if (aprc->general_aprc_cntx.gui_buffer == NULL)
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
        /* arrange the highlight */
        if (gui_buffer != NULL)
        {
            list_gui_buffer = (list_menu_category_history *)gui_buffer;
            list_gui_buffer->highlighted_item = aprc->general_aprc_cntx.hilite_idx;
        }
    }
    else
    {
        gui_buffer = aprc->general_aprc_cntx.gui_buffer;
    }

#ifdef __MMI_ICON_BAR_SUPPORT__
    mmi_um_ui_aprc_reg_toolbar_cb_hdlr(&(aprc->general_aprc_cntx.tb_hdlr));
#endif /* __MMI_ICON_BAR_SUPPORT__ */

    /* If it has the special title, it needs to display a specified string in title */
    if (NULL == aprc->special_title)
    {
        title_str = (U8 *) get_string(aprc->general_aprc_cntx.title_str_id);
    }
    else
    {
        title_str = aprc->special_title;
    }

    wgui_cat_conversation_show(
        title_str,
        GetImage(aprc->general_aprc_cntx.title_icon_id),
        aprc->general_aprc_cntx.lsk_str_id,
        aprc->general_aprc_cntx.rsk_str_id,
        aprc->general_aprc_cntx.num_of_item,
        mmi_um_ui_sh_thread_enhance_get_async_item,           //get item info for image and string.
        aprc->get_mark_cb,
        aprc->set_mark_cb,
        aprc->general_aprc_cntx.hilite_idx,
        IMG_MESSAGE_READ,                                  //default icon for calc width and height
        gui_buffer,
        &list_not_ready);

    if (aprc->hilite_notify_cb != NULL)
    {
        wgui_async_list_register_update_callback(aprc->hilite_notify_cb);
    }
    
#ifdef __MMI_ICON_BAR_SUPPORT__
    mmi_um_ui_aprc_reg_intuitive_cmd_cb_hdlr(aprc->general_aprc_cntx.intuitive_cmd_cb_func);
#endif /* __MMI_ICON_BAR_SUPPORT__ */

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback_all(UI_dummy_function);
#endif /* __MMI_TOUCH_SCREEN__ */

    /* the screen does not display */
    if (list_not_ready)
    {
        OslMfree(aprc_int_cntx);
        return MMI_FALSE;
    }

    mmi_um_ui_aprc_set_key_hdlr(&(aprc->general_aprc_cntx.key_hdlr));

    OslMfree(aprc_int_cntx);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_267_redraw
 * DESCRIPTION
 *  It is used to redraw the category 267 screen. It needs to call several
 *  framework APIs to accomplish displaying a screen. Sometiems it needs to
 *  update the screen. Screen handler should call this API to update the
 *  current screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *  aprc_st_type        [IN]: The screen type of this appearance
 *  type                [IN]: Redrawing region
 *
 * RETURNS
 *  MMI_TRUE: the screen updates finished
 *  MMI_FALSE: the screen updates fail
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_thread_enhance_ms_redraw(mmi_um_ui_aprc_st_union *aprc_cntx, 
                                   mmi_um_ui_aprc_st_enum aprc_st_type, 
                                   mmi_um_ui_aprc_redraw_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}


#endif

#endif /* __MMI_UM_CONVERSATION_BOX_ENHANCE__ */

#ifdef __MMI_ICON_BAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_263_redraw_tb_status
 * DESCRIPTION
 *  It is used to redraw the toolbar status of category 263 screen. It needs 
 *  to call several framework APIs to accomplish displaying a screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *
 * RETURNS
 *  MMI_TRUE: the screen updates finished
 *  MMI_FALSE: the screen updates fail
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_263_redraw_tb_status(mmi_um_ui_aprc_struct_union *aprc_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    mmi_um_ui_aprc_263_struct *aprc = &(aprc_cntx->aprc_263);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 < aprc->general_aprc_cntx.tb_hdlr.num_of_toolbar)
    {
        for (i = 0 ; i < aprc->general_aprc_cntx.tb_hdlr.num_of_toolbar ; i++)
        {
            wgui_icon_bar_set_item_enable_state(
                            i, 
                            aprc->general_aprc_cntx.tb_hdlr.status[i]);
        }
        wgui_icon_bar_update();
    }

    return MMI_TRUE;
}
#endif /* __MMI_ICON_BAR_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_268_draw
 * DESCRIPTION
 *  It is used to draw the category 268 screen. It needs to call several
 *  framework APIs to accomplish displaying a screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *  aprc_st_type        [IN]: The screen type of this appearance
 *
 * RETURNS
 *  MMI_TRUE: the screen is displayed
 *  MMI_FALSE: the screen is not displayed
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_268_draw(mmi_um_ui_aprc_st_union *aprc_cntx, 
                                 mmi_um_ui_aprc_st_enum aprc_st_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    S32 list_not_ready;
    list_menu_category_history *list_gui_buffer;
    mmi_um_ui_aprc_struct_union *aprc_int_cntx;
    mmi_um_ui_aprc_268_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aprc_int_cntx= OslMalloc(sizeof(mmi_um_ui_aprc_struct_union));
    aprc = &(aprc_int_cntx->aprc_268);
    mmi_um_ui_aprc_set_int_cntx(aprc_int_cntx, MMI_UM_UI_APRC_268, aprc_cntx, aprc_st_type);

    if (MMI_FALSE == mmi_um_ui_aprc_general_fw_function(&(aprc->general_aprc_cntx)))
    {
        OslMfree(aprc_int_cntx);
        return MMI_TRUE;
    }
    
    if (aprc->general_aprc_cntx.gui_buffer == NULL)
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
        /* arrange the highlight */
        if (gui_buffer != NULL)
        {
            list_gui_buffer = (list_menu_category_history *)gui_buffer;
            list_gui_buffer->highlighted_item = aprc->general_aprc_cntx.hilite_idx;
        }
    }
    else
    {
        gui_buffer = aprc->general_aprc_cntx.gui_buffer;
    }
    wgui_cat_set_list_menu_empty_lable(get_string(STR_UM_EMPTY_MSG_ID));

#ifdef __MMI_ICON_BAR_SUPPORT__
    mmi_um_ui_aprc_reg_toolbar_cb_hdlr(&(aprc->general_aprc_cntx.tb_hdlr));
    /* If num_of_item == 0, the toolbar should be dimmed */
    if (0 < aprc->general_aprc_cntx.tb_hdlr.num_of_toolbar &&
        0 == aprc->general_aprc_cntx.num_of_item)
    {
        U16 i;

        for (i = 0 ; i < aprc->general_aprc_cntx.tb_hdlr.num_of_toolbar ; i++)
        {
            wgui_icon_bar_set_item_enable_state(
                            i, 
                            MMI_FALSE);
        }
    }
#endif /* __MMI_ICON_BAR_SUPPORT__ */
#if (MMI_MAX_SIM_NUM >= 2)
    wgui_cat_list_set_display_more_icon(MMI_TRUE);
#endif

    ShowCategory268Screen(
        (U8*) get_string(aprc->general_aprc_cntx.title_str_id),
        aprc->general_aprc_cntx.title_icon_id,
        aprc->general_aprc_cntx.lsk_str_id,
        aprc->general_aprc_cntx.lsk_icon_id,
        aprc->general_aprc_cntx.rsk_str_id,
        aprc->general_aprc_cntx.rsk_icon_id,
        aprc->general_aprc_cntx.num_of_item,
        aprc->get_item_cb,
        aprc->get_item_hint_cb,
        aprc->general_aprc_cntx.hilite_idx,
        IMG_MESSAGE_READ,       /* for icon position used */
        gui_buffer,
        &list_not_ready);

    if (aprc->hilite_notify_cb != NULL)
    {
        wgui_async_list_register_update_callback(aprc->hilite_notify_cb);
    }
    
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    mmi_um_ui_aprc_reg_intuitive_cmd_cb_hdlr(aprc->general_aprc_cntx.intuitive_cmd_cb_func);
#endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */

    /* the screen does not display */
    if (list_not_ready)
    {
        OslMfree(aprc_int_cntx);
        return MMI_FALSE;
    }

    mmi_um_ui_aprc_set_key_hdlr(&(aprc->general_aprc_cntx.key_hdlr));

    OslMfree(aprc_int_cntx);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_268_redraw
 * DESCRIPTION
 *  It is used to redraw the category 268 screen. It needs to call several
 *  framework APIs to accomplish displaying a screen. Sometiems it needs to
 *  update the screen. Screen handler should call this API to update the
 *  current screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *  aprc_st_type        [IN]: The screen type of this appearance
 *  type                [IN]: Redrawing region
 *
 * RETURNS
 *  MMI_TRUE: the screen updates finished
 *  MMI_FALSE: the screen updates fail
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_268_redraw(mmi_um_ui_aprc_st_union *aprc_cntx, 
                                   mmi_um_ui_aprc_st_enum aprc_st_type, 
                                   mmi_um_ui_aprc_redraw_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    mmi_um_ui_aprc_struct_union *aprc_int_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aprc_int_cntx= OslMalloc(sizeof(mmi_um_ui_aprc_struct_union));
    mmi_um_ui_aprc_set_int_cntx(aprc_int_cntx, MMI_UM_UI_APRC_268, aprc_cntx, aprc_st_type);
    result = MMI_TRUE;

#ifdef __MMI_ICON_BAR_SUPPORT__
    if ((type & MMI_UM_UI_APRC_REDRAW_TB_STATUS) == MMI_UM_UI_APRC_REDRAW_TB_STATUS)
    {
        result = mmi_um_ui_aprc_268_redraw_tb_status(aprc_int_cntx);
    }
#endif /* __MMI_ICON_BAR_SUPPORT__ */

    OslMfree(aprc_int_cntx);
    return result;
}


#ifdef __MMI_ICON_BAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_268_redraw_tb_status
 * DESCRIPTION
 *  It is used to redraw the toolbar status of category 268 screen. It needs 
 *  to call several framework APIs to accomplish displaying a screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *
 * RETURNS
 *  MMI_TRUE: the screen updates finished
 *  MMI_FALSE: the screen updates fail
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_268_redraw_tb_status(mmi_um_ui_aprc_struct_union * aprc_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    mmi_um_ui_aprc_268_struct *aprc = &(aprc_cntx->aprc_268);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 < aprc->general_aprc_cntx.tb_hdlr.num_of_toolbar)
    {
        for (i = 0 ; i < aprc->general_aprc_cntx.tb_hdlr.num_of_toolbar ; i++)
        {
            wgui_icon_bar_set_item_enable_state(
                            i, 
                            aprc->general_aprc_cntx.tb_hdlr.status[i]);
        }
        wgui_icon_bar_update();
    }

    return MMI_TRUE;
}
#endif /* __MMI_ICON_BAR_SUPPORT__ */

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_267_draw
 * DESCRIPTION
 *  It is used to draw the category 267 screen. It needs to call several
 *  framework APIs to accomplish displaying a screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *  aprc_st_type        [IN]: The screen type of this appearance
 *
 * RETURNS
 *  MMI_TRUE: the screen is displayed
 *  MMI_FALSE: the screen is not displayed
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_267_draw(mmi_um_ui_aprc_st_union *aprc_cntx, 
                                 mmi_um_ui_aprc_st_enum aprc_st_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *title_str;
    U8 *gui_buffer;
    S32 list_not_ready;
    list_menu_category_history *list_gui_buffer;
    mmi_um_ui_aprc_struct_union *aprc_int_cntx;
    mmi_um_ui_aprc_267_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aprc_int_cntx= OslMalloc(sizeof(mmi_um_ui_aprc_struct_union));
    aprc = &(aprc_int_cntx->aprc_267);
    mmi_um_ui_aprc_set_int_cntx(aprc_int_cntx, MMI_UM_UI_APRC_267, aprc_cntx, aprc_st_type);

    if (MMI_FALSE == mmi_um_ui_aprc_general_fw_function(&(aprc->general_aprc_cntx)))
    {
        OslMfree(aprc_int_cntx);
        return MMI_TRUE;
    }
    
#if 0
/* under construction !*/
#endif
    if (aprc->general_aprc_cntx.gui_buffer == NULL)
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
        /* arrange the highlight */
        if (gui_buffer != NULL)
        {
            list_gui_buffer = (list_menu_category_history *)gui_buffer;
            list_gui_buffer->highlighted_item = aprc->general_aprc_cntx.hilite_idx;
        }
    }
    else
    {
        gui_buffer = aprc->general_aprc_cntx.gui_buffer;
    }

#ifdef __MMI_ICON_BAR_SUPPORT__
    mmi_um_ui_aprc_reg_toolbar_cb_hdlr(&(aprc->general_aprc_cntx.tb_hdlr));
#endif /* __MMI_ICON_BAR_SUPPORT__ */

    /* If it has the special title, it needs to display a specified string in title */
    if (NULL == aprc->special_title)
    {
        title_str = (U8 *) get_string(aprc->general_aprc_cntx.title_str_id);
    }
    else
    {
        title_str = aprc->special_title;
    }
#ifdef __MMI_UM_CONVERSATION_BOX__
    /* Set the style of the box */
    wgui_cat263_set_display_style(aprc->folder_style);
#endif /* __MMI_UM_CONVERSATION_BOX__ */
#if (MMI_MAX_SIM_NUM >= 2)
#ifdef __MMI_UM_CONVERSATION_BOX__
    if (aprc_st_type != MMI_UM_UI_SCRN_TYPE_MS_CONVERSATION_BOX)
#endif /* __MMI_UM_CONVERSATION_BOX__ */
    {
        wgui_cat_list_set_display_more_icon(MMI_TRUE);
    }
#endif

    ShowCategory267Screen(
        (UI_string_type) title_str,
        get_image(aprc->general_aprc_cntx.title_icon_id),
        get_string(aprc->general_aprc_cntx.lsk_str_id),
        get_image(aprc->general_aprc_cntx.lsk_icon_id),
        get_string(aprc->general_aprc_cntx.rsk_str_id),
        get_image(aprc->general_aprc_cntx.rsk_icon_id),
        aprc->general_aprc_cntx.num_of_item,
        aprc->get_item_cb,
        aprc->get_item_hint_cb,
        aprc->get_mark_cb,
        aprc->set_mark_cb,
        get_string(aprc->hint_info_msg),
        aprc->general_aprc_cntx.hilite_idx,
        IMG_MESSAGE_READ,       /* for icon position used */
        gui_buffer,
        &list_not_ready);

    if (aprc->hilite_notify_cb != NULL)
    {
        wgui_async_list_register_update_callback(aprc->hilite_notify_cb);
    }
    
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    mmi_um_ui_aprc_reg_intuitive_cmd_cb_hdlr(aprc->general_aprc_cntx.intuitive_cmd_cb_func);
#endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback_all(UI_dummy_function);
#endif /* __MMI_TOUCH_SCREEN__ */

    /* the screen does not display */
    if (list_not_ready)
    {
        OslMfree(aprc_int_cntx);
        return MMI_FALSE;
    }

    mmi_um_ui_aprc_set_key_hdlr(&(aprc->general_aprc_cntx.key_hdlr));

    OslMfree(aprc_int_cntx);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_267_redraw
 * DESCRIPTION
 *  It is used to redraw the category 267 screen. It needs to call several
 *  framework APIs to accomplish displaying a screen. Sometiems it needs to
 *  update the screen. Screen handler should call this API to update the
 *  current screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *  aprc_st_type        [IN]: The screen type of this appearance
 *  type                [IN]: Redrawing region
 *
 * RETURNS
 *  MMI_TRUE: the screen updates finished
 *  MMI_FALSE: the screen updates fail
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_267_redraw(mmi_um_ui_aprc_st_union *aprc_cntx, 
                                   mmi_um_ui_aprc_st_enum aprc_st_type, 
                                   mmi_um_ui_aprc_redraw_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}


#endif

#if 1
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_53_draw
 * DESCRIPTION
 *  It is used to draw the category 53 screen. It needs to call several
 *  framework APIs to accomplish displaying a screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *  aprc_st_type        [IN]: The screen type of this appearance
 *
 * RETURNS
 *  MMI_TRUE: the screen is displayed
 *  MMI_FALSE: the screen is not displayed
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_53_draw(mmi_um_ui_aprc_st_union *aprc_cntx, 
                                mmi_um_ui_aprc_st_enum aprc_st_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    mmi_um_ui_aprc_struct_union *aprc_int_cntx;
    mmi_um_ui_aprc_53_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aprc_int_cntx= OslMalloc(sizeof(mmi_um_ui_aprc_struct_union));
    aprc = &(aprc_int_cntx->aprc_53);
    mmi_um_ui_aprc_set_int_cntx(aprc_int_cntx, MMI_UM_UI_APRC_53, aprc_cntx, aprc_st_type);

    if (MMI_FALSE == mmi_um_ui_aprc_general_fw_function(&(aprc->general_aprc_cntx)))
    {
        OslMfree(aprc_int_cntx);
        return MMI_TRUE;
    }
    
    if (aprc->general_aprc_cntx.gui_buffer == NULL)
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    }
    else
    {
        gui_buffer = aprc->general_aprc_cntx.gui_buffer;
    }

    SetParentHandler(aprc->general_aprc_cntx.menu_item_id);

#ifdef __MMI_WGUI_MINI_TAB_BAR__
    wgui_enable_mini_tab_bar(aprc->general_aprc_cntx.menu_item_id);
#endif /* __MMI_WGUI_MINI_TAB_BAR__ */

#ifdef __MMI_ICON_BAR_SUPPORT__
    mmi_um_ui_aprc_reg_toolbar_cb_hdlr(&(aprc->general_aprc_cntx.tb_hdlr));
#endif /* __MMI_ICON_BAR_SUPPORT__ */

    wgui_list_menu_enable_access_by_shortcut();
    ShowCategory53Screen(
        aprc->general_aprc_cntx.title_str_id,
        aprc->general_aprc_cntx.title_icon_id,
        aprc->general_aprc_cntx.lsk_str_id,
        aprc->general_aprc_cntx.lsk_icon_id,
        aprc->general_aprc_cntx.rsk_str_id,
        aprc->general_aprc_cntx.rsk_icon_id,
        aprc->general_aprc_cntx.num_of_item,
        aprc->list_of_items,
        aprc->list_of_item_icons,
        aprc->list_of_item_hints,
        0,
        aprc->general_aprc_cntx.hilite_idx,
        gui_buffer);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    mmi_um_ui_aprc_reg_intuitive_cmd_cb_hdlr(aprc->general_aprc_cntx.intuitive_cmd_cb_func);
#endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */

    mmi_um_ui_aprc_set_key_hdlr(&(aprc->general_aprc_cntx.key_hdlr));

    OslMfree(aprc_int_cntx);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_53_redraw
 * DESCRIPTION
 *  It is used to redraw the category 53 screen. It needs to call several
 *  framework APIs to accomplish displaying a screen. Sometiems it needs to
 *  update the screen. Screen handler should call this API to update the
 *  current screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *  aprc_st_type        [IN]: The screen type of this appearance
 *  type                [IN]: Redrawing region
 *
 * RETURNS
 *  MMI_TRUE: the screen updates finished
 *  MMI_FALSE: the screen updates fail
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_53_redraw(mmi_um_ui_aprc_st_union *aprc_cntx, 
                                  mmi_um_ui_aprc_st_enum aprc_st_type, 
                                  mmi_um_ui_aprc_redraw_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    mmi_um_ui_aprc_struct_union *aprc_int_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aprc_int_cntx= OslMalloc(sizeof(mmi_um_ui_aprc_struct_union));
    mmi_um_ui_aprc_set_int_cntx(aprc_int_cntx, MMI_UM_UI_APRC_53, aprc_cntx, aprc_st_type);
    result = MMI_TRUE;

    if ((type & MMI_UM_UI_APRC_REDRAW_BODY) == MMI_UM_UI_APRC_REDRAW_BODY)
    {
        result = mmi_um_ui_aprc_53_redraw_body(aprc_int_cntx);
    }

    RedrawCategoryFunction();

    OslMfree(aprc_int_cntx);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_53_redraw_body
 * DESCRIPTION
 *  It is used to redraw the body of category 53 screen. It needs to call 
 *  several framework APIs to accomplish displaying a screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *
 * RETURNS
 *  MMI_TRUE: the screen updates finished
 *  MMI_FALSE: the screen updates fail
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_53_redraw_body(mmi_um_ui_aprc_struct_union *aprc_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_aprc_53_struct *aprc = &(aprc_cntx->aprc_53);
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Update each body */
    for (i = 0; i < aprc->general_aprc_cntx.num_of_item; i++)
    {
        /* Update menu item string */
        if (aprc->list_of_items[i] != NULL)
        {
            Category53ChangeItemText(i, aprc->list_of_items[i]);
        }

        /* Update menu item hint string */
        if (aprc->list_of_item_hints != NULL)
        {
            Category53ChangeItemDescription(i, aprc->list_of_item_hints[i]);
        }
        else
        {
            Category53ChangeItemDescription(i, NULL);
        }
    }

    return MMI_TRUE;
}

#endif
    
#if 1
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_52_draw
 * DESCRIPTION
 *  It is used to draw the category 52 screen. It needs to call several
 *  framework APIs to accomplish displaying a screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *  aprc_st_type        [IN]: The screen type of this appearance
 *
 * RETURNS
 *  MMI_TRUE: the screen is displayed
 *  MMI_FALSE: the screen is not displayed
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_52_draw(mmi_um_ui_aprc_st_union *aprc_cntx, 
                                mmi_um_ui_aprc_st_enum aprc_st_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    mmi_um_ui_aprc_struct_union *aprc_int_cntx;
    mmi_um_ui_aprc_52_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aprc_int_cntx= OslMalloc(sizeof(mmi_um_ui_aprc_struct_union));
    aprc = &(aprc_int_cntx->aprc_52);
    mmi_um_ui_aprc_set_int_cntx(aprc_int_cntx, MMI_UM_UI_APRC_52, aprc_cntx, aprc_st_type);

    if (MMI_FALSE == mmi_um_ui_aprc_general_fw_function(&(aprc->general_aprc_cntx)))
    {
        OslMfree(aprc_int_cntx);
        return MMI_TRUE;
    }
    
    if (aprc->general_aprc_cntx.gui_buffer == NULL)
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    }
    else
    {
        gui_buffer = aprc->general_aprc_cntx.gui_buffer;
    }

    SetParentHandler(aprc->general_aprc_cntx.menu_item_id);

#ifdef __MMI_ICON_BAR_SUPPORT__
    mmi_um_ui_aprc_reg_toolbar_cb_hdlr(&(aprc->general_aprc_cntx.tb_hdlr));
#endif /* __MMI_ICON_BAR_SUPPORT__ */

    wgui_list_menu_enable_access_by_shortcut();
    ShowCategory52Screen(
        aprc->general_aprc_cntx.title_str_id,
        aprc->general_aprc_cntx.title_icon_id,
        aprc->general_aprc_cntx.lsk_str_id,
        aprc->general_aprc_cntx.lsk_icon_id,
        aprc->general_aprc_cntx.rsk_str_id,
        aprc->general_aprc_cntx.rsk_icon_id,
        aprc->general_aprc_cntx.num_of_item,
        aprc->list_of_items,
        aprc->list_of_item_icons,
        aprc->list_of_item_hints,
        0,
        aprc->general_aprc_cntx.hilite_idx,
        gui_buffer);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    mmi_um_ui_aprc_reg_intuitive_cmd_cb_hdlr(aprc->general_aprc_cntx.intuitive_cmd_cb_func);
#endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */

    mmi_um_ui_aprc_set_key_hdlr(&(aprc->general_aprc_cntx.key_hdlr));

    OslMfree(aprc_int_cntx);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_52_redraw
 * DESCRIPTION
 *  It is used to redraw the category 52 screen. It needs to call several
 *  framework APIs to accomplish displaying a screen. Sometiems it needs to
 *  update the screen. Screen handler should call this API to update the
 *  current screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *  aprc_st_type        [IN]: The screen type of this appearance
 *  type                [IN]: Redrawing region
 *
 * RETURNS
 *  MMI_TRUE: the screen updates finished
 *  MMI_FALSE: the screen updates fail
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_52_redraw(mmi_um_ui_aprc_st_union *aprc_cntx, 
                                  mmi_um_ui_aprc_st_enum aprc_st_type, 
                                  mmi_um_ui_aprc_redraw_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_165_draw
 * DESCRIPTION
 *  It is used to draw the category 165 screen. It needs to call several
 *  framework APIs to accomplish displaying a screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *  aprc_st_type        [IN]: The screen type of this appearance
 *
 * RETURNS
 *  MMI_TRUE: the screen is displayed
 *  MMI_FALSE: the screen is not displayed
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_165_draw(mmi_um_ui_aprc_st_union *aprc_cntx, 
                                 mmi_um_ui_aprc_st_enum aprc_st_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    mmi_um_ui_aprc_struct_union *aprc_int_cntx;
    mmi_um_ui_aprc_165_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aprc_int_cntx= OslMalloc(sizeof(mmi_um_ui_aprc_struct_union));
    aprc = &(aprc_int_cntx->aprc_165);
    mmi_um_ui_aprc_set_int_cntx(aprc_int_cntx, MMI_UM_UI_APRC_165, aprc_cntx, aprc_st_type);


    if (MMI_FALSE == mmi_um_ui_aprc_general_fw_function(&(aprc->general_aprc_cntx)))
    {
        OslMfree(aprc_int_cntx);
        return MMI_TRUE;
    }
    
    if (aprc->general_aprc_cntx.gui_buffer == NULL)
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    }
    else
    {
        gui_buffer = aprc->general_aprc_cntx.gui_buffer;
    }

    /* It should block sliding show */
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
    if (aprc->scrn_effect == MMI_UM_UI_BLOCK_SLIDE_SHOW)
    {
        gui_screen_switch_effect_block(MMI_TRUE);
    }
#endif /* __MMI_SCREEN_SWITCH_EFFECT__ */

    ShowCategory165Screen(
        aprc->general_aprc_cntx.lsk_str_id,
        aprc->general_aprc_cntx.lsk_icon_id,
        aprc->general_aprc_cntx.rsk_str_id,
        aprc->general_aprc_cntx.rsk_icon_id,
        get_string(aprc->msg_str_id),
        aprc->msg_icon_id,
        gui_buffer);

    mmi_um_ui_aprc_set_key_hdlr(&(aprc->general_aprc_cntx.key_hdlr));

    OslMfree(aprc_int_cntx);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_165_redraw
 * DESCRIPTION
 *  It is used to redraw the category 165 screen. It needs to call several
 *  framework APIs to accomplish displaying a screen. Sometiems it needs to
 *  update the screen. Screen handler should call this API to update the
 *  current screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *  aprc_st_type        [IN]: The screen type of this appearance
 *  type                [IN]: Redrawing region
 *
 * RETURNS
 *  MMI_TRUE: the screen updates finished
 *  MMI_FALSE: the screen updates fail
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_165_redraw(mmi_um_ui_aprc_st_union *aprc_cntx, 
                                   mmi_um_ui_aprc_st_enum aprc_st_type, 
                                   mmi_um_ui_aprc_redraw_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_UM_ULTRA_SLIM__
    mmi_um_ui_aprc_struct_union *aprc_int_cntx;
    mmi_um_ui_aprc_165_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aprc_int_cntx= OslMalloc(sizeof(mmi_um_ui_aprc_struct_union));
    aprc = &(aprc_int_cntx->aprc_165);
    mmi_um_ui_aprc_set_int_cntx(aprc_int_cntx, MMI_UM_UI_APRC_165, aprc_cntx, aprc_st_type);

    /* redraw key handler */
    if ((type & MMI_UM_UI_APRC_REDRAW_KEY) == MMI_UM_UI_APRC_REDRAW_KEY)
    {
        mmi_um_ui_aprc_change_key_hdlr(&(aprc->general_aprc_cntx));
    }

    /* redraw body */
    if ((type & MMI_UM_UI_APRC_REDRAW_BODY) == MMI_UM_UI_APRC_REDRAW_BODY)
    {
        wgui_cat_popup_update_string(get_string(aprc->msg_str_id));
    }

    OslMfree(aprc_int_cntx);
#endif
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_1002_draw
 * DESCRIPTION
 *  It is used to draw the category 1002 screen. It needs to call several
 *  framework APIs to accomplish displaying a screen. This is the inline mark
 *  several screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *  aprc_st_type        [IN]: The screen type of this appearance
 *
 * RETURNS
 *  MMI_TRUE: the screen is displayed
 *  MMI_FALSE: the screen is not displayed
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_1002_draw(mmi_um_ui_aprc_st_union *aprc_cntx, 
                                  mmi_um_ui_aprc_st_enum aprc_st_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    S32 list_not_ready;
    list_menu_category_history *list_gui_buffer;
    mmi_um_ui_aprc_struct_union *aprc_int_cntx;
    mmi_um_ui_aprc_1002_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aprc_int_cntx= OslMalloc(sizeof(mmi_um_ui_aprc_struct_union));
    aprc = &(aprc_int_cntx->aprc_1002);
    mmi_um_ui_aprc_set_int_cntx(aprc_int_cntx, MMI_UM_UI_APRC_1002, aprc_cntx, aprc_st_type);

    if (MMI_FALSE == mmi_um_ui_aprc_general_fw_function(&(aprc->general_aprc_cntx)))
    {
        OslMfree(aprc_int_cntx);
        return MMI_TRUE;
    }

    if (aprc->general_aprc_cntx.gui_buffer == NULL)
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
        /* arrange the highlight */
        if (gui_buffer != NULL)
        {
            list_gui_buffer = (list_menu_category_history *)gui_buffer;
            list_gui_buffer->highlighted_item = aprc->general_aprc_cntx.hilite_idx;
        }
    }
    else
    {
        gui_buffer = aprc->general_aprc_cntx.gui_buffer;
    }

#if (MMI_MAX_SIM_NUM >= 2)
    wgui_cat_list_set_display_more_icon(MMI_TRUE);
#endif

    wgui_cat1002_show(
        get_string(aprc->general_aprc_cntx.title_str_id),
        get_image(aprc->general_aprc_cntx.title_icon_id),
        get_string(aprc->general_aprc_cntx.lsk_str_id),
        get_image(aprc->general_aprc_cntx.lsk_icon_id),
        get_string(aprc->general_aprc_cntx.rsk_str_id),
        get_image(aprc->general_aprc_cntx.rsk_icon_id),
        aprc->general_aprc_cntx.num_of_item,
        aprc->get_item_cb,
        aprc->get_item_hint_cb,
        aprc->get_mark_cb,
        aprc->set_mark_cb,
        get_string(aprc->hint_info_msg),
        aprc->general_aprc_cntx.hilite_idx,
        IMG_MESSAGE_READ,       /* for icon position used */
        gui_buffer,
        &list_not_ready);

    if (aprc->hilite_notify_cb != NULL)
    {
        wgui_async_list_register_update_callback(aprc->hilite_notify_cb);
    }

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback_all(UI_dummy_function);
#endif /* __MMI_TOUCH_SCREEN__ */

    /* the screen does not display */
    if (list_not_ready)
    {
        OslMfree(aprc_int_cntx);
        return MMI_FALSE;
    }

    mmi_um_ui_aprc_set_key_hdlr(&(aprc->general_aprc_cntx.key_hdlr));

    OslMfree(aprc_int_cntx);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_1002_redraw
 * DESCRIPTION
 *  It is used to redraw the category 1002 screen. It needs to call several
 *  framework APIs to accomplish displaying a screen. Sometiems it needs to
 *  update the screen. Screen handler should call this API to update the
 *  current screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *  aprc_st_type        [IN]: The screen type of this appearance
 *  type                [IN]: Redrawing region
 *
 * RETURNS
 *  MMI_TRUE: the screen updates finished
 *  MMI_FALSE: the screen updates fail
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_1002_redraw(mmi_um_ui_aprc_st_union *aprc_cntx, 
                                    mmi_um_ui_aprc_st_enum aprc_st_type, 
                                    mmi_um_ui_aprc_redraw_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_36_draw
 * DESCRIPTION
 *  It is used to draw the category 36 screen. It needs to call several
 *  framework APIs to accomplish displaying a screen. This is the inline mark
 *  several screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *  aprc_st_type        [IN]: The screen type of this appearance
 *
 * RETURNS
 *  MMI_TRUE: the screen is displayed
 *  MMI_FALSE: the screen is not displayed
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_36_draw(mmi_um_ui_aprc_st_union *aprc_cntx, 
                                mmi_um_ui_aprc_st_enum aprc_st_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    mmi_um_ui_aprc_struct_union *aprc_int_cntx;
    mmi_um_ui_aprc_36_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aprc_int_cntx= OslMalloc(sizeof(mmi_um_ui_aprc_struct_union));
    aprc = &(aprc_int_cntx->aprc_36);
    mmi_um_ui_aprc_set_int_cntx(aprc_int_cntx, MMI_UM_UI_APRC_36, aprc_cntx, aprc_st_type);

    if (MMI_FALSE == mmi_um_ui_aprc_general_fw_function(&(aprc->general_aprc_cntx)))
    {
        OslMfree(aprc_int_cntx);
        return MMI_TRUE;
    }

    if (aprc->general_aprc_cntx.gui_buffer == NULL)
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    }
    else
    {
        gui_buffer = aprc->general_aprc_cntx.gui_buffer;
    }

    SetParentHandler(aprc->general_aprc_cntx.menu_item_id);

#ifdef __MMI_ICON_BAR_SUPPORT__
    mmi_um_ui_aprc_reg_toolbar_cb_hdlr(&(aprc->general_aprc_cntx.tb_hdlr));
#endif /* __MMI_ICON_BAR_SUPPORT__ */

    ShowCategory36Screen(
        aprc->general_aprc_cntx.title_str_id,
        aprc->general_aprc_cntx.title_icon_id,
        aprc->general_aprc_cntx.lsk_str_id,
        aprc->general_aprc_cntx.lsk_icon_id,
        aprc->general_aprc_cntx.rsk_str_id,
        aprc->general_aprc_cntx.rsk_icon_id,
        aprc->general_aprc_cntx.num_of_item,
        aprc->list_of_items,
        (U16) aprc->general_aprc_cntx.hilite_idx,
        gui_buffer);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    mmi_um_ui_aprc_reg_intuitive_cmd_cb_hdlr(aprc->general_aprc_cntx.intuitive_cmd_cb_func);
#endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */

    mmi_um_ui_aprc_set_key_hdlr(&(aprc->general_aprc_cntx.key_hdlr));

    OslMfree(aprc_int_cntx);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_36_redraw
 * DESCRIPTION
 *  It is used to redraw the category 36 screen. It needs to call several
 *  framework APIs to accomplish displaying a screen. Sometiems it needs to
 *  update the screen. Screen handler should call this API to update the
 *  current screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *  aprc_st_type        [IN]: The screen type of this appearance
 *  type                [IN]: Redrawing region
 *
 * RETURNS
 *  MMI_TRUE: the screen updates finished
 *  MMI_FALSE: the screen updates fail
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_36_redraw(mmi_um_ui_aprc_st_union *aprc_cntx, 
                                  mmi_um_ui_aprc_st_enum aprc_st_type, 
                                  mmi_um_ui_aprc_redraw_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_6003_draw
 * DESCRIPTION
 *  It is used to draw the category 6003 screen. It needs to call several
 *  framework APIs to accomplish displaying a screen. This is the inline mark
 *  several screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *  aprc_st_type        [IN]: The screen type of this appearance
 *
 * RETURNS
 *  MMI_TRUE: the screen is displayed
 *  MMI_FALSE: the screen is not displayed
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_6003_draw(mmi_um_ui_aprc_st_union *aprc_cntx, 
                                  mmi_um_ui_aprc_st_enum aprc_st_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_aprc_struct_union *aprc_int_cntx;
    mmi_um_ui_aprc_6003_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aprc_int_cntx= OslMalloc(sizeof(mmi_um_ui_aprc_struct_union));
    aprc = &(aprc_int_cntx->aprc_6003);
    mmi_um_ui_aprc_set_int_cntx(aprc_int_cntx, MMI_UM_UI_APRC_6003, aprc_cntx, aprc_st_type);

    if (MMI_FALSE == mmi_um_ui_aprc_general_fw_function(&(aprc->general_aprc_cntx)))
    {
        OslMfree(aprc_int_cntx);
        return MMI_TRUE;
    }
    
    SetParentHandler(aprc->general_aprc_cntx.menu_item_id);

#ifdef __MMI_ICON_BAR_SUPPORT__
    mmi_um_ui_aprc_reg_toolbar_cb_hdlr(&(aprc->general_aprc_cntx.tb_hdlr));
#endif /* __MMI_ICON_BAR_SUPPORT__ */

    wgui_cat6003_show(
        aprc->general_aprc_cntx.lsk_str_id, 
        aprc->general_aprc_cntx.rsk_str_id, 
        aprc->message, 
        aprc->sub_message, 
        aprc->percentage);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    mmi_um_ui_aprc_reg_intuitive_cmd_cb_hdlr(aprc->general_aprc_cntx.intuitive_cmd_cb_func);
#endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */

    mmi_um_ui_aprc_set_key_hdlr(&(aprc->general_aprc_cntx.key_hdlr));

    OslMfree(aprc_int_cntx);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_6003_redraw
 * DESCRIPTION
 *  It is used to redraw the category 6003 screen. It needs to call several
 *  framework APIs to accomplish displaying a screen. Sometiems it needs to
 *  update the screen. Screen handler should call this API to update the
 *  current screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *  aprc_st_type        [IN]: The screen type of this appearance
 *  type                [IN]: Redrawing region
 *
 * RETURNS
 *  MMI_TRUE: the screen updates finished
 *  MMI_FALSE: the screen updates fail
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_6003_redraw(mmi_um_ui_aprc_st_union *aprc_cntx, 
                                    mmi_um_ui_aprc_st_enum aprc_st_type, 
                                    mmi_um_ui_aprc_redraw_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    mmi_um_ui_aprc_struct_union *aprc_int_cntx;
    mmi_um_ui_aprc_6003_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aprc_int_cntx= OslMalloc(sizeof(mmi_um_ui_aprc_struct_union));
    aprc = &(aprc_int_cntx->aprc_6003);
    mmi_um_ui_aprc_set_int_cntx(aprc_int_cntx, MMI_UM_UI_APRC_6003, aprc_cntx, aprc_st_type);
    result = MMI_TRUE;

    /* redraw key handler */
    if ((type & MMI_UM_UI_APRC_REDRAW_KEY) == MMI_UM_UI_APRC_REDRAW_KEY)
    {
        mmi_um_ui_aprc_change_key_hdlr(&(aprc->general_aprc_cntx));
    }

    if ((type & MMI_UM_UI_APRC_REDRAW_BODY) == MMI_UM_UI_APRC_REDRAW_BODY)
    {
        result = mmi_um_ui_aprc_6003_redraw_body(aprc_int_cntx);
    }

    OslMfree(aprc_int_cntx);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_6003_redraw_body
 * DESCRIPTION
 *  It is used to redraw the body of category 6003 screen. It needs to call 
 *  several framework APIs to accomplish displaying a screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *
 * RETURNS
 *  MMI_TRUE: the screen updates finished
 *  MMI_FALSE: the screen updates fail
 *****************************************************************************/
MMI_BOOL mmi_um_ui_aprc_6003_redraw_body(mmi_um_ui_aprc_struct_union *aprc_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_aprc_6003_struct *aprc = &(aprc_cntx->aprc_6003);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat6003_update_all(
        aprc->message, 
        aprc->sub_message, 
        aprc->percentage);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_set_key_hdlr
 * DESCRIPTION
 *  It is used to set key handler. After drawing, it should call this function
 *  to set key handler.
 *
 * PARAMETERS
 *  key_hdlr:           [IN]    Key handler
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_aprc_set_key_hdlr(mmi_um_ui_key_handler_struct *key_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (key_hdlr->lsk_hdlr != NULL)
    {
        SetLeftSoftkeyFunction(key_hdlr->lsk_hdlr, KEY_EVENT_UP);
    }
    if (key_hdlr->rsk_hdlr != NULL)
    {
        SetRightSoftkeyFunction(key_hdlr->rsk_hdlr, KEY_EVENT_UP);
    }
    if (key_hdlr->csk_hdlr != NULL)
    {
        SetCenterSoftkeyFunction(key_hdlr->csk_hdlr, KEY_EVENT_UP);
    }

    /* Send key handler by UCM */
    if (KEY_SEND == key_hdlr->special_key_code)
    {
        mmi_ucm_handle_sendkeys_for_call(key_hdlr->key_hdlr, KEY_EVENT_UP);
    }
    /* Special key for different purpose */
    else if (key_hdlr->special_key_code != 0)
    {
        SetKeyHandler(key_hdlr->key_hdlr, 
                      key_hdlr->special_key_code, 
                      KEY_EVENT_UP);
    }

    /* Clear end key */
    if (key_hdlr->clear_end_key)
    {
        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_enable_softkey
 * DESCRIPTION
 *  It is used to enable softkey. Before drawing, it should call this function
 *  to enable softkey.
 *
 * PARAMETERS
 *  general_cntx:       [IN]    General appearance context
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_aprc_enable_softkey(mmi_um_ui_aprc_general_cntx_struct *general_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* if csk icon/string is not equal to empty, it should enable csk handler */
    if (0 != general_cntx->csk_str_id ||
        0 != general_cntx->csk_icon_id)
    {
        EnableCenterSoftkey(general_cntx->csk_str_id, general_cntx->csk_icon_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_change_key_hdlr
 * DESCRIPTION
 *  It is used to change key handler. After redrawing, it should call this 
 *  function to set key handler.
 *
 * PARAMETERS
 *  general_cntx:           [IN]    General context
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_aprc_change_key_hdlr(mmi_um_ui_aprc_general_cntx_struct *general_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ChangeLeftSoftkey(general_cntx->lsk_str_id, general_cntx->lsk_icon_id);
    ChangeRightSoftkey(general_cntx->rsk_str_id, general_cntx->rsk_icon_id);
    ChangeCenterSoftkey(general_cntx->csk_str_id, general_cntx->csk_icon_id);
    /* If NULL, clear it. Else set as callback function */
    if (general_cntx->key_hdlr.lsk_hdlr != NULL)
    {
        SetLeftSoftkeyFunction(general_cntx->key_hdlr.lsk_hdlr, KEY_EVENT_UP);
    }
    else
    {
        clear_softkey_handler(MMI_LEFT_SOFTKEY);
    }
    if (general_cntx->key_hdlr.rsk_hdlr != NULL)
    {
        SetRightSoftkeyFunction(general_cntx->key_hdlr.rsk_hdlr, KEY_EVENT_UP);
    }
    else
    {
        clear_softkey_handler(MMI_RIGHT_SOFTKEY);
    }
    if (general_cntx->key_hdlr.csk_hdlr != NULL)
    {
        SetCenterSoftkeyFunction(general_cntx->key_hdlr.csk_hdlr, KEY_EVENT_UP);
    }
    else
    {
        clear_softkey_handler(MMI_CENTER_SOFTKEY);
    }

    if (general_cntx->key_hdlr.clear_end_key)
    {
        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_reg_leave_proc
 * DESCRIPTION
 *  It is used to register leave proc handler by calling FW API
 *
 * PARAMETERS
 *  general_cntx        [IN]:    General context
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_aprc_reg_leave_proc(mmi_um_ui_aprc_general_cntx_struct *general_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != general_cntx->leave_proc)
    {
        mmi_frm_scrn_set_leave_proc(general_cntx->grp_id, general_cntx->scrn_id, general_cntx->leave_proc);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_set_int_cntx
 * DESCRIPTION
 *  It is used to set the internal appearance context.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: Internal appearance struct union
 *  aprc_type           [IN]: Internal appearance type
 *  aprc_st_cntx        [IN]: External appearance struct union
 *  aprc_st_type        [IN]: External appearance type
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_aprc_set_int_cntx(mmi_um_ui_aprc_struct_union *aprc_cntx, 
                                 mmi_um_ui_aprc_type_enum aprc_type, 
                                 mmi_um_ui_aprc_st_union *aprc_st_cntx, 
                                 mmi_um_ui_aprc_st_enum aprc_st_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (aprc_st_type)
    {
        case MMI_UM_UI_SCRN_TYPE_MAIN_MENU:
        case MMI_UM_UI_SCRN_TYPE_LIST:
        {
            mmi_um_ui_aprc_st_main_menu_struct *aprc_ext = &(aprc_st_cntx->main_menu);
            mmi_um_ui_aprc_53_struct *aprc_int  = &(aprc_cntx->aprc_53);
            memset(aprc_cntx, 0, sizeof(mmi_um_ui_aprc_struct_union));

            memcpy(&(aprc_int->general_aprc_cntx), 
                   &(aprc_ext->general_aprc_cntx), 
                   sizeof(mmi_um_ui_aprc_general_cntx_struct));
            aprc_int->list_of_items = aprc_ext->list_of_items;
            aprc_int->list_of_item_hints = aprc_ext->list_of_item_hints;
            aprc_int->list_of_item_icons = aprc_ext->list_of_item_icons;
            break;
        }
         
        case MMI_UM_UI_SCRN_TYPE_FOLDER:
        {
            mmi_um_ui_aprc_st_folder_struct *aprc_ext = &(aprc_st_cntx->folder);
        #if __MMI_UNIFIED_MESSAGE_FOLDER_LIST_STYLE__ == __UM_LIST_INLINE__
            mmi_um_ui_aprc_268_struct *aprc_int = &(aprc_cntx->aprc_268);
        #elif __MMI_UNIFIED_MESSAGE_FOLDER_LIST_STYLE__ == __UM_LIST_NORMAL__
            mmi_um_ui_aprc_263_struct *aprc_int = &(aprc_cntx->aprc_263);
        #endif /* __MMI_UNIFIED_MESSAGE_FOLDER_LIST_STYLE__ */
            memset(aprc_cntx, 0, sizeof(mmi_um_ui_aprc_struct_union));

            memcpy(&(aprc_int->general_aprc_cntx), 
                   &(aprc_ext->general_aprc_cntx), 
                   sizeof(mmi_um_ui_aprc_general_cntx_struct));
            aprc_int->get_item_cb = aprc_ext->get_item_cb;
            aprc_int->get_item_hint_cb = aprc_ext->get_item_hint_cb;
            aprc_int->hilite_notify_cb = aprc_ext->hilite_notify_cb;
            break;
        }
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
        case MMI_UM_UI_SCRN_TYPE_MS:
        {
            mmi_um_ui_aprc_st_ms_struct *aprc_ext = &(aprc_st_cntx->ms_folder);
        #if __MMI_UNIFIED_MESSAGE_FOLDER_LIST_STYLE__ == __UM_LIST_INLINE__
            mmi_um_ui_aprc_1002_struct *aprc_int = &(aprc_cntx->aprc_1002);
        #elif __MMI_UNIFIED_MESSAGE_FOLDER_LIST_STYLE__ == __UM_LIST_NORMAL__
            mmi_um_ui_aprc_267_struct *aprc_int = &(aprc_cntx->aprc_267);
        #endif /* __MMI_UNIFIED_MESSAGE_FOLDER_LIST_STYLE__ */
            memset(aprc_cntx, 0, sizeof(mmi_um_ui_aprc_struct_union));

            memcpy(&(aprc_int->general_aprc_cntx), 
                   &(aprc_ext->general_aprc_cntx), 
                   sizeof(mmi_um_ui_aprc_general_cntx_struct));
            aprc_int->get_item_cb = aprc_ext->get_item_cb;
            aprc_int->get_item_hint_cb = aprc_ext->get_item_hint_cb;
            aprc_int->hilite_notify_cb = aprc_ext->hilite_notify_cb;
            aprc_int->get_mark_cb = aprc_ext->get_mark_cb;
            aprc_int->set_mark_cb = aprc_ext->set_mark_cb;
            aprc_int->hint_info_msg = aprc_ext->hint_info_msg;
            break;
        }
#endif

        case MMI_UM_UI_SCRN_TYPE_LOADING:
        {
            mmi_um_ui_aprc_st_loading_struct *aprc_ext = &(aprc_st_cntx->loading);
            mmi_um_ui_aprc_165_struct *aprc_int  = &(aprc_cntx->aprc_165);
            memset(aprc_cntx, 0, sizeof(mmi_um_ui_aprc_struct_union));

            memcpy(&(aprc_int->general_aprc_cntx), 
                   &(aprc_ext->general_aprc_cntx), 
                   sizeof(mmi_um_ui_aprc_general_cntx_struct));
            aprc_int->msg_str_id = aprc_ext->msg_str_id;
            aprc_int->msg_icon_id = aprc_ext->msg_icon_id;
            aprc_int->scrn_effect = aprc_ext->scrn_effect;
            break;
        }
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
        case MMI_UM_UI_SCRN_TYPE_LOADING_PGRS:
        {
            mmi_um_ui_aprc_st_loading_pgrs_struct *aprc_ext = &(aprc_st_cntx->loading_pgrs);
            mmi_um_ui_aprc_6003_struct *aprc_int = &(aprc_cntx->aprc_6003);

            memcpy(&(aprc_int->general_aprc_cntx), 
                   &(aprc_ext->general_aprc_cntx), 
                   sizeof(mmi_um_ui_aprc_general_cntx_struct));
            aprc_int->message = aprc_ext->message;
            aprc_int->sub_message = aprc_ext->sub_message;
            aprc_int->progress_info_left = aprc_ext->progress_info_left;
            aprc_int->progress_info_right = aprc_ext->progress_info_right;
            aprc_int->current_item = aprc_ext->current_item;
            aprc_int->percentage = aprc_ext->percentage;
            break;
        }
#endif
    #ifdef __MMI_UM_CONVERSATION_BOX__
        case MMI_UM_UI_SCRN_TYPE_CONVERSATION_BOX:
        {
            mmi_um_ui_aprc_st_cs_folder_struct *aprc_ext = &(aprc_st_cntx->cs_folder);
            mmi_um_ui_aprc_263_struct *aprc_int = &(aprc_cntx->aprc_263);
            memset(aprc_cntx, 0, sizeof(mmi_um_ui_aprc_struct_union));

            memcpy(&(aprc_int->general_aprc_cntx), 
                   &(aprc_ext->general_aprc_cntx), 
                   sizeof(mmi_um_ui_aprc_general_cntx_struct));
            aprc_int->folder_style = aprc_ext->folder_style;
            aprc_int->get_item_cb = aprc_ext->get_item_cb;
            aprc_int->get_item_hint_cb = aprc_ext->get_item_hint_cb;
            aprc_int->hilite_notify_cb = aprc_ext->hilite_notify_cb;
            break;
        }
        case MMI_UM_UI_SCRN_TYPE_THRD_MSG:
        {
            mmi_um_ui_aprc_st_folder_struct *aprc_ext = &(aprc_st_cntx->folder);
            mmi_um_ui_aprc_263_struct *aprc_int = &(aprc_cntx->aprc_263);
            memset(aprc_cntx, 0, sizeof(mmi_um_ui_aprc_struct_union));

            memcpy(&(aprc_int->general_aprc_cntx), 
                   &(aprc_ext->general_aprc_cntx), 
                   sizeof(mmi_um_ui_aprc_general_cntx_struct));
            aprc_int->folder_style = aprc_ext->folder_style;
            aprc_int->special_title = aprc_ext->special_title;
            aprc_int->get_item_cb = aprc_ext->get_item_cb;
            aprc_int->get_item_hint_cb = aprc_ext->get_item_hint_cb;
            aprc_int->hilite_notify_cb = aprc_ext->hilite_notify_cb;
            break;
        }
    #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
        case MMI_UM_UI_SCRN_TYPE_MS_CONVERSATION_BOX:
        {
            mmi_um_ui_aprc_st_ms_cs_folder_struct *aprc_ext = &(aprc_st_cntx->ms_cs_folder);
            mmi_um_ui_aprc_267_struct *aprc_int = &(aprc_cntx->aprc_267);
            memset(aprc_cntx, 0, sizeof(mmi_um_ui_aprc_struct_union));

            memcpy(&(aprc_int->general_aprc_cntx), 
                   &(aprc_ext->general_aprc_cntx), 
                   sizeof(mmi_um_ui_aprc_general_cntx_struct));
            aprc_int->folder_style = aprc_ext->folder_style;
            aprc_int->get_item_cb = aprc_ext->get_item_cb;
            aprc_int->get_item_hint_cb = aprc_ext->get_item_hint_cb;
            aprc_int->hilite_notify_cb = aprc_ext->hilite_notify_cb;
            aprc_int->get_mark_cb = aprc_ext->get_mark_cb;
            aprc_int->set_mark_cb = aprc_ext->set_mark_cb;
            aprc_int->hint_info_msg = aprc_ext->hint_info_msg;
            break;
        }
        case MMI_UM_UI_SCRN_TYPE_MS_THRD_MSG:
        {
            mmi_um_ui_aprc_st_ms_struct *aprc_ext = &(aprc_st_cntx->ms_folder);
            mmi_um_ui_aprc_267_struct *aprc_int = &(aprc_cntx->aprc_267);
            memset(aprc_cntx, 0, sizeof(mmi_um_ui_aprc_struct_union));

            memcpy(&(aprc_int->general_aprc_cntx), 
                   &(aprc_ext->general_aprc_cntx), 
                   sizeof(mmi_um_ui_aprc_general_cntx_struct));
            aprc_int->folder_style = aprc_ext->folder_style;
            aprc_int->special_title = aprc_ext->special_title;
            aprc_int->get_item_cb = aprc_ext->get_item_cb;
            aprc_int->get_item_hint_cb = aprc_ext->get_item_hint_cb;
            aprc_int->hilite_notify_cb = aprc_ext->hilite_notify_cb;
            aprc_int->get_mark_cb = aprc_ext->get_mark_cb;
            aprc_int->set_mark_cb = aprc_ext->set_mark_cb;
            aprc_int->hint_info_msg = aprc_ext->hint_info_msg;
            break;
        }
    #endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
        case MMI_UM_UI_SCRN_TYPE_CONVERSATION_SETTING:
        {
            mmi_um_ui_aprc_st_cs_setting_struct *aprc_ext = &(aprc_st_cntx->cs_setting);
            mmi_um_ui_aprc_36_struct *aprc_int = &(aprc_cntx->aprc_36);

            memcpy(&(aprc_int->general_aprc_cntx), 
                   &(aprc_ext->general_aprc_cntx), 
                   sizeof(mmi_um_ui_aprc_general_cntx_struct));
            aprc_int->list_of_items = aprc_ext->list_of_items;
            break;
        }
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        

#if (defined(__OP01__) && (MMI_MAX_SIM_NUM >= 2))
        case MMI_UM_UI_SCRN_TYPE_PREFER_SIM_SETTING:
        {
            mmi_um_ui_aprc_st_cs_setting_struct *aprc_ext = &(aprc_st_cntx->cs_setting);
            mmi_um_ui_aprc_36_struct *aprc_int = &(aprc_cntx->aprc_36);

            memcpy(&(aprc_int->general_aprc_cntx), 
                   &(aprc_ext->general_aprc_cntx), 
                   sizeof(mmi_um_ui_aprc_general_cntx_struct));
            aprc_int->list_of_items = aprc_ext->list_of_items;
            break;
        }
#endif
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }
}


#ifdef __MMI_ICON_BAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_reg_toolbar_cb_hdlr
 * DESCRIPTION
 *  It is used to register toolbar callback handler by calling FW 
 *  API
 *
 * PARAMETERS
 *  tb_cntx             [IN]:   callback handler
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_aprc_reg_toolbar_cb_hdlr(mmi_um_ui_tb_handler_struct *tb_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check the maximum number of icons */
    MMI_ASSERT(tb_cntx->num_of_toolbar <= MMI_UM_UI_MAX_TB_ICON);
    if (0 < tb_cntx->num_of_toolbar)
    {
        wgui_icon_bar_setup(
                    tb_cntx->num_of_toolbar,
                    tb_cntx->body,
                    tb_cntx->body_disable,
                    tb_cntx->hint,
                    tb_cntx->callback);
    }
}
#endif /* __MMI_ICON_BAR_SUPPORT__ */

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_aprc_reg_intuitive_cmd_cb_hdlr
 * DESCRIPTION
 *  It is used to register intuitive command callback handler by calling FW 
 *  API
 *
 * PARAMETERS
 *  intuitive_cb_hdlr       [IN]:   callback handler
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_aprc_reg_intuitive_cmd_cb_hdlr(void(* intuitive_cb_hdlr)(mmi_tap_type_enum tap_type, S32 index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register intuitive command callback handler. It is the FTE features for tap selection */
    if (NULL != intuitive_cb_hdlr)
    {
        wgui_register_tap_callback(intuitive_cb_hdlr);
    }
}
#endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
