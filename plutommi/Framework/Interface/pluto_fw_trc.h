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
 *  pluto_fw_trc.h
 *
 * Project:
 * --------
 *  MAUI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef  PLUTO_FW_TRC_H
#define  PLUTO_FW_TRC_H
#include "kal_trace.h"

#define PLUTO_FW_TRC_EVT          TRACE_GROUP_1
#define PLUTO_FW_TRC_CB           TRACE_GROUP_1
#define PLUTO_FW_TRC_SCREEN       TRACE_GROUP_2
#define PLUTO_FW_TRC_REDRAW       TRACE_GROUP_2
#define PLUTO_FW_TRC_INPUT        TRACE_GROUP_3
#define PLUTO_FW_TRC_KEY          TRACE_GROUP_3
#define PLUTO_FW_TRC_PEN          TRACE_GROUP_3
#define PLUTO_FW_TRC_NMGR         TRACE_GROUP_4
#define PLUTO_FW_TRC_MEM          TRACE_GROUP_5
#define PLUTO_FW_TRC_NVRAM        TRACE_GROUP_6
#define PLUTO_FW_TRC_THEME        TRACE_GROUP_7
#define PLUTO_FW_TRC_QUEUE        TRACE_GROUP_7
 
#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "pluto_fw_trc_gen.h"
#endif /* TST Trace Defintion */
#endif

//RHR Add 
#include "stack_config.h"
BEGIN_TRACE_MAP(MOD_PLUTO_FW)
    /*****************************************************************************************************************
     * NMGR trace
     *****************************************************************************************************************/
    TRC_MSG(TRC_MMI_FRM_NMGR_CONFIRM_POPUP, "[MMI_FRM][NMGR] nmgr_confirm_popup <defer = %d>")
    TRC_MSG(TRC_MMI_FRM_NMGR_DO_CONFIRM_NOTIFY, "[MMI_FRM][NMGR] do_confirm_popup_notify <scenario_id = %Mmmi_scenario_id, type = %Mmmi_event_notify_enum>")
    TRC_MSG(TRC_MMI_FRM_NMGR_MESSAGE_CNT, "[MMI_FRM][NMGR] get_unread_message_count <sms = %d, mms = %d, wappush = %d, provision = %d>")

    /*****************************************************************************************************************
     * MMI Framework theme trace
     *****************************************************************************************************************/
    //ThemeManager.c 
    TRC_MSG(MMI_TM_TRC_ADD_IMG_ID_TO_CACHE_HDLR, "[MMI_FRM][THEME] mmi_tm_add_img_id_to_cache: img_list_index =%d, image_offset = %d type = %d")
    TRC_MSG(MMI_TM_TRC_CREATE_NON_IMAGEID_IMAGE_HDLR, "[MMI_FRM][THEME] mmi_tm_create_non_imageid_image: image_offset =%d, type = %d")
    TRC_MSG(MMI_TM_TRC_SET_IMAGEID_HDLR, "[MMI_FRM][THEME] mmi_tm_set_imageid: image_id =%d has type = %d")


    /*****************************************************************************************************************
     * MMI Framework NVRAM trace
     *****************************************************************************************************************/
    TRC_MSG(TRC_MMI_FRM_NVRAM_READ_RECORD_BEGIN, "[MMI_FRM][NVRAM] ReadRecord <Begin> <lid = %d, record id = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_READ_MULTI_RECORD_BEGIN, "[MMI_FRM][NVRAM] ReadMultiRecord <Begin> <lid = %d, record id = %d, rec_amount = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_WRITE_RECORD_BEGIN, "[MMI_FRM][NVRAM] WriteRecord <Begin> <lid = %d, record_id = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_ASYNC_WRITE_RECORD_BEGIN, "[MMI_FRM][NVRAM] write async record <Begin> <lid = %d, record_id = %d>")

    
    TRC_MSG(TRC_MMI_FRM_NVRAM_READ_CORE_RECORD_BEGIN, "[MMI_FRM][NVRAM] ReadRecord <Begin> <lid = %Mnvram_lid_core_enum, record id = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_READ_COMAPP_RECORD_BEGIN, "[MMI_FRM][NVRAM] ReadRecord <Begin> <lid = %Mnvram_lid_commapp_enum, record id = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_READ_CUST_RECORD_BEGIN, "[MMI_FRM][NVRAM] ReadRecord <Begin> <lid = %Mnvram_lid_cust_enum, record id = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_READ_RECORD_END, "[MMI_FRM][NVRAM] ReadRecord <End> <result = %MMMINVRAMERRORSENUM>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_READ_MULTI_CORE_RECORD_BEGIN, "[MMI_FRM][NVRAM] ReadMultiRecord <Begin> <lid = %Mnvram_lid_core_enum, record id = %d, rec_amount = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_READ_MULTI_COMAPP_RECORD_BEGIN, "[MMI_FRM][NVRAM] ReadMultiRecord <Begin> <lid = %Mnvram_lid_commapp_enum, record id = %d, rec_amount = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_READ_MULTI_CUST_RECORD_BEGIN, "[MMI_FRM][NVRAM] ReadMultiRecord <Begin> <lid = %Mnvram_lid_cust_enum, record id = %d, rec_amount = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_READ_MULTI_RECORD_END, "[MMI_FRM][NVRAM] ReadMultiRecord <End> <result = %MMMINVRAMERRORSENUM>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_WRITE_CORE_RECORD_BEGIN, "[MMI_FRM][NVRAM] WriteRecord <Begin> <lid = %Mnvram_lid_core_enum, record_id = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_WRITE_COMAPP_RECORD_BEGIN, "[MMI_FRM][NVRAM] WriteRecord <Begin> <lid = %Mnvram_lid_commapp_enum, record_id = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_WRITE_CUST_RECORD_BEGIN, "[MMI_FRM][NVRAM] WriteRecord <Begin> <lid = %Mnvram_lid_cust_enum, record_id = %d>") 
    TRC_MSG(TRC_MMI_FRM_NVRAM_WRITE_RECORD_END, "[MMI_FRM][NVRAM] WriteRecord <End> <result = %MMMINVRAMERRORSENUM>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_READ_VALUE, "[MMI_FRM][NVRAM CACHE] ReadValue <type = %MDATASIZE, value id = %Mmmi_rp_fw_nvram_mgr_mmi_cache_enum, result = %MMMINVRAMERRORSENUM>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_WRITE_VALUE, "[MMI_FRM][NVRAM CACHE] WriteValue <type = %MDATASIZE, value id = %Mmmi_rp_fw_nvram_mgr_mmi_cache_enum, result = %MMMINVRAMERRORSENUM>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_FLUSH_CACHE_DATA, "[MMI_FRM][NVRAM CACHE] <Flush cache data> <type = %MDATASIZE, flag = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_SET_FLUSH_CACHE_FLAG, "[MMI_FRM][NVRAM CACHE] <set flush cache flag> <type = %MDATASIZE, value = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_ASYNC_WRITE_CORE_RECORD_BEGIN, "[MMI_FRM][NVRAM] write async record <Begin> <lid = %Mnvram_lid_core_enum, record_id = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_ASYNC_WRITE_COMAPP_RECORD_BEGIN, "[MMI_FRM][NVRAM] write async record <Begin> <lid = %Mnvram_lid_commapp_enum, record_id = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_ASYNC_WRITE_CUST_RECORD_BEGIN, "[MMI_FRM][NVRAM] write async record <Begin> <lid = %Mnvram_lid_cust_enum, record_id = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_JUDGE_IS_PROCEDURE, "[MMI_FRM][NVRAM] IsInNVRAMProcedure <recursive_num = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_SEND_WRITE_REQ, "[MMI_FRM][NVRAM] SendNVRAMWriteReq")
    TRC_MSG(TRC_MMI_FRM_NVRAM_SEND_READ_REQ, "[MMI_FRM][NVRAM] SendNVRAMReadReq")
    TRC_MSG(TRC_MMI_FRM_NVRAM_FS_SANITY_CHECK_PROCESSING, "[MMI_FRM][NVRAM] <FS sanity check processing>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_WRITE_CACHE_BY_LID, "[MMI_FRM][NVRAM CACHE] <direct write cache by lid><lid = %Mnvram_lid_cust_enum>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_CHECK_CQ, "[MMI_FRM][NVRAM] <check circular q> <result = %McircularQ_check_enum>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_REARRANGE_CACHE_BUFFER, "[MMI_FRM][NVRAM CACHE]Re-arrange Cache buffer, type =%d,  move_num = %d")
    TRC_MSG(TRC_MMI_FRM_NVRAM_CACHE_DEL, "[MMI_FRM][NVRAM CACHE]Different with previous version, type = %d, delete index = %d")
    TRC_MSG(TRC_MMI_FRM_NVRAM_CACHE_ADD,"[MMI_FRM][NVRAM CACHE]Different with previous version, type = %d, add index = %d")
    /*****************************************************************************************************************
     * MMI Framework key trace
     *****************************************************************************************************************/
    TRC_MSG(TRC_MMI_FRM_KEY_MMI_KEY_CODE_SUPPORTED, "[MMI_FRM][Key] mmi_frm_kbd_is_key_supported <keycode = %Mmmi_keypads_enum, is_support = %d>")
    TRC_MSG(TRC_MMI_FRM_KEY_SET_KEY_HDLR, "[MMI_FRM][Key] <set key hdlr> <%Mmmi_keypads_enum, %Mmmi_key_types_enum, ptr = 0x%x>")
    TRC_MSG(TRC_MMI_FRM_KEY_CLRALLKEY_HDLR, "[MMI_FRM][Key] ClearAllKeyHandler")
    TRC_MSG(TRC_MMI_FRM_KEY_REVERSE_CODE, "[MMI_FRM][Key] mmi_kbd_reverse_code: <mmi_key_code = %Mmmi_keypads_enum, device_key_code = %d>")
    TRC_MSG(TRC_MMI_FRM_KEY_KEYPAD_MODE, "[MMI_FRM][Key] mmi_frm_set_keypad_mode <%Mmmi_frm_keypad_mode_enum>")
    TRC_MSG(TRC_MMI_FRM_KEY_PTR_CHANGE_SUCCESS, "[MMI_FRM][Key] <keypad ptr changed successfully> <l4_mode = %ML4_keypad_mode_enum>")
    TRC_MSG(TRC_MMI_FRM_KEY_DEVICE_KEY_INFO, "[MMI_FRM][Key] device_key_code = %d, device_key_type = %Mkbd_event")
    TRC_MSG(TRC_MMI_FRM_KEY_GET_ANY_KEY_HDLR, "[MMI_FRM][Key] <get any key handler> <key code = %Mmmi_keypads_enum, key type = %Mmmi_key_types_enum, func_ptr = %x>")
    TRC_MSG(TRC_MMI_FRM_KEY_CLARE_APP_INVOKE_SPACE_PROC, "[MMI_FRM][Key]clear invoke space application proc")

    TRC_MSG(TRC_MMI_FRM_KEY_TONE_STOP, "[MMI_FRM][Key tone] <stop> <code = %Mmmi_keypads_enum, id = %d, dura = %Maudio_play_style_enum>")
    TRC_MSG(TRC_MMI_FRM_KEY_TONE_PLAY, "[MMI_FRM][Key tone] <play> <code = %Mmmi_keypads_enum, id = %d, dura = %Maudio_play_style_enum>")
    TRC_MSG(TRC_MMI_FRM_KEY_TONE_INFO, "[MMI_FRM][Key tone] <Info> <type = %d, state = %Mmmi_frm_kbd_tone_state_enum>")

    /*****************************************************************************************************************
     * MMI Framework screen/history
     *****************************************************************************************************************/
    TRC_MSG(TRC_MMI_FRM_HIST_CREATE_ACTIVE_SCRN, "[MMI_FRM][Scenario][History] mmi_frm_create_active_scrn <scrn_id = %Mmmi_screen_id_cgen_enum, topHistoryIndex = %d, currHistoryIndex = %d, activeScrnIndex = %d, newScrnIndexadd = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_UPDATE_ACTIVE_SCRN_FROM_NEW_SCRN, "[MMI_FRM][Scenario][History] mmi_frm_update_active_scrn_from_new_scrn <topHistoryIndex = %d, currHistoryIndex = %d, activeScrnIndex = %d, newScrnIndexadd = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_UPDATE_ACTIVE_SCRN, "[MMI_FRM][Scenario][History] mmi_frm_update_active_scrn <scrn_id = %Mmmi_screen_id_cgen_enum, topHistoryIndex = %d, currHistoryIndex = %d, activeScrnIndex = %d, newScrnIndexadd = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_REMOVE_HIST_NODE, "[MMI_FRM][Scenario][History] Remove history node <status=%M, remove_index=%d>")
    TRC_MSG(MMI_FRM_INFO_SET_SCREEN_ID_CB_HDLR, "[MMI_FRM][Scenario][History] SetDelScrnIDCallbackHandler: <ScrnID=%Mmmi_screen_id_cgen_enum, funcPtr=%x>")
    TRC_MSG(MMI_FRM_INFO_CLR_SCREEN_ID_CB_HDLR, "[MMI_FRM][Scenario][History] ClearDelScrnIDCallbackHandler: <ScrnID=%Mmmi_screen_id_cgen_enum, funcPtr=%x>")
    TRC_MSG(MMI_FRM_INFO_SRCH_DEL_SCRN_CB_HDLR, "[MMI_FRM][Scenario][History] SearchDelScrnIDCallbackHandler: <ScrnID=%Mmmi_screen_id_cgen_enum is found in history_idx=%d>")
    TRC_MSG(TRC_MMI_FRM_SRCH_DEL_SCRN_CB_HDLR, "[MMI_FRM][Scenario][History] mmi_frm_search_destroy_scrn_callback <scrn_id = %Mmmi_screen_id_cgen_enum, scrn_idx = %d>")
    TRC_MSG(MMI_FRM_INFO_GET_PREVIOUS_SCR_IDOF_HDLR, "[MMI_FRM][Scenario][History] GetPreviousScrnIdOf <scrnid = %Mmmi_screen_id_cgen_enum, previousScrnId = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_GET_PREVIOUS_SCR_IDOF_2_HDLR, "[MMI_FRM][Scenario][History] GetPreviousScrnIdOf <NO previousScrnId> <scrnid = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_IS_SCR_PRESENT_HDLR, "[MMI_FRM][Scenario][History] IsScreenPresent <scrnid = %Mmmi_screen_id_cgen_enum, present = %Mkal_bool>")
    TRC_MSG(TRC_MMI_FRM_HIST_DEL_HISTORY_HDLR, "[MMI_FRM][Scenario][History] DeleteHistoryInt <start_scrn_id=%Mmmi_screen_id_cgen_enum, if include start_scrn_id=%d, expected delete count=%d, end_scrn_id=%Mmmi_screen_id_cgen_enum, if include end_scrn_id=%d>")
    TRC_MSG(TRC_MMI_FRM_HIST_DEL_HISTORY_INDEX_HDLR, "[MMI_FRM][Scenario][History] DeleteHistory <currHistoryIndex=%d, start_hist_idx=%d, end_hist_idx=%d>")
    TRC_MSG(TRC_MMI_FRM_HIST_INSERT_HIST_BY_IDX, "[MMI_FRM][Scenario][History] insert_history_by_idx <insert_idx = %d, scrn_id = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_INIT_HIST_BEGIN, "[MMI_FRM][Scenario][History] InitHistory <Begin>")
    TRC_MSG(TRC_MMI_FRM_HIST_INIT_HIST_END, "[MMI_FRM][Scenario][History] InitHistory <End>")
    TRC_MSG(TRC_MMI_FRM_HIST_DINIT_HIST_BEGIN, "[MMI_FRM][Scenario][History] DinitHistory <Begin>")
    TRC_MSG(TRC_MMI_FRM_HIST_DINIT_HIST_END, "[MMI_FRM][Scenario][History] DinitHistory <End>")
    TRC_MSG(MMI_FRM_INFO_EXEC_HIST_SCRN_CB_STRAT, "[MMI_FRM][Scenario][History] ExecHistoryScrnCallBackHandle Start <ScrnID=%Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_EXEC_HIST_SCRN_CB_END, "[MMI_FRM][Scenario][History] ExecHistoryScrnCallBackHandle End <ScrnID=%Mmmi_screen_id_cgen_enum><is_stop_allow=%d>")
    TRC_MSG(MMI_FRM_INFO_HIST_GET_HIST_HDLR, "[MMI_FRM][Scenario][History] GetHistory <screen ID =%Mmmi_screen_id_cgen_enum, history index=%d>")
    TRC_MSG(MMI_FRM_INFO_HIST_GET_NHIST_HDLR, "[MMI_FRM][Scenario][History] GetNHistory <screen ID = %Mmmi_screen_id_cgen_enum, history index = %d>")
    TRC_MSG(MMI_FRM_INFO_HIST_GET_HIST_SCRID_HDLR, "[MMI_FRM][Scenario][History] GetHistoryScrID <screen ID =%Mmmi_screen_id_cgen_enum, history index=%d>")
    TRC_MSG(TRC_MMI_FRM_HIST_INC_HIST, "[MMI_FRM][Scenario][History] increment <curr_hist_idx = %d, top_hist_idx = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_DECREMENT_CURRHIST_IDX, "[MMI_FRM][Scenario][History] decrement_current_history_index <curr_hist_idx = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_SET_HISTO_STATUS, "[MMI_FRM][Scenario][History] mmi_frm_set_history_node_status <set non-gobacking status> <idx = %d, status: %Mmmi_history_node_status_enum => %Mmmi_history_node_status_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_SET_HISTO_STATUS_GB, "[MMI_FRM][Scenario][History] mmi_frm_set_history_node_status <set gobacking status> <idx = %d, status: %Mmmi_history_node_status_enum => %Mmmi_history_node_status_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_SET_HISTO_STATUS_GB_RET, "[MMI_FRM][Scenario][History] mmi_frm_set_history_node_status <return gobacking status> <idx = %d, status: %Mmmi_history_node_status_enum => %Mmmi_history_node_status_enum, reentry = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_SET_HISTO_STATUS_RET, "[MMI_FRM][Scenario][History] mmi_frm_set_history_node_status <return non-gobacking status> <status = %Mmmi_history_node_status_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_EXE_WAIT_TO_DESTROY_HDLR, "[MMI_FRM][Scenario][History] mmi_frm_exec_scrn_wait_to_destroy_hdlr <status = %Mmmi_history_node_status_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_NEXT_SCR_ID, "[MMI_FRM][Scenario][History] GetNextScrnIdOf <scrn_id = %Mmmi_screen_id_cgen_enum, next_scrn_id = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_SCR_IDX, "[MMI_FRM][Scenario][History] mmi_frm_get_screen_index <scrn_id = %Mmmi_screen_id_cgen_enum, idx = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_RANGE_IDX_ERR1, "[MMI_FRM][Scenario][History] get_range_index <Error: startScrId == 0 && endScrId == 0>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_RANGE_IDX_ERR2, "[MMI_FRM][Scenario][History] get_range_index <Error: scr not present in history>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_RANGE_IDX_ERR3, "[MMI_FRM][Scenario][History] get_range_index <Error: endIdxTmp is invalid>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_RANGE_IDX_ERR4, "[MMI_FRM][Scenario][History] get_range_index <Error: count exists, no startIdx/endIdx>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_RANGE_IDX_ERR5, "[MMI_FRM][Scenario][History] get_range_index <Error: startIdx < 0 || endIdx < 0>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_RANGE_IDX_SUCCESS, "[MMI_FRM][Scenario][History] get_range_index <Success> <startIdx = %d, endIdx = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_SET_SMALL_SCRN, "[MMI_FRM][Scenario][History] set_small_screen <Success>")
    TRC_MSG(TRC_MMI_FRM_HIST_SET_SMALL_SCRN_ERR, "[MMI_FRM][Scenario][History] set_small_screen <Fail since no small scrn>")
    TRC_MSG(TRC_MMI_FRM_HIST_IS_REDRAW_BK, "[MMI_FRM][Scenario][History] mmi_is_redrawing_bk_screens <sm_scrn_state = %Mmmi_hist_smallscreen_state_enum>")
//    TRC_MSG(TRC_MMI_FRM_HIST_RESET_TAB, "[MMI_FRM][Scenario][History] mmi_frm_reset_tab <tab_info_p = 0x%x>")
//    TRC_MSG(TRC_MMI_FRM_HIST_GEN_TAB_FIRST_ENTRY, "[MMI_FRM][Scenario][History] mmi_frm_general_tab_entry_int <First entry time> <func = 0x%x, tab_page_cnt = %d, sel_idx = %d>")
//    TRC_MSG(TRC_MMI_FRM_HIST_GEN_TAB_OTHER_ENTRY, "[MMI_FRM][Scenario][History] mmi_frm_general_tab_entry_int <Other entry time> <scrn_id = %Mmmi_screen_id_cgen_enum, func = 0x%x, tab_page_cnt = %d, sel_idx = %d>")
//    TRC_MSG(TRC_MMI_FRM_HIST_GEN_TAB_EXIT_HDLR, "[MMI_FRM][Scenario][History] mmi_frm_general_tab_exit")
//    TRC_MSG(TRC_MMI_FRM_HIST_GEN_TAB_DELETE_HDLR, "[MMI_FRM][Scenario][History] mmi_frm_general_tab_delete_hdlr <arg_p = 0x%x>")
//    TRC_MSG(TRC_MMI_FRM_HIST_RELEASE_TAB_GROUP, "[MMI_FRM][Scenario][History] mmi_frm_release_tab_group <tab_page_count = %d, tab_history_p = 0x%x>")
//    TRC_MSG(TRC_MMI_FRM_HIST_FIND_TAB_HIST, "[MMI_FRM][Scenario][History] mmi_frm_find_tab_history <scrn_id = %Mmmi_screen_id_cgen_enum, tab_idx = %d>")
//    TRC_MSG(TRC_MMI_FRM_HIST_ADD_TAB_HIST_ERR1, "[MMI_FRM][Scenario][History] mmi_frm_add_tab_history <Fail - gobacking>")
//    TRC_MSG(TRC_MMI_FRM_HIST_ADD_TAB_HIST_ERR2, "[MMI_FRM][Scenario][History] mmi_frm_add_tab_history <Fail - can't find tab history>")
//    TRC_MSG(TRC_MMI_FRM_HIST_ADD_TAB_N_HIST_ERR1, "[MMI_FRM][Scenario][History] mmi_frm_add_tab_n_history <Fail - gobacking>")
//    TRC_MSG(TRC_MMI_FRM_HIST_ADD_TAB_N_HIST_ERR2, "[MMI_FRM][Scenario][History] mmi_frm_add_tab_n_history <Fail - can't find tab history>")
//    TRC_MSG(TRC_MMI_FRM_HIST_GET_CUR_TAB_GUIBUF, "[MMI_FRM][Scenario][History] mmi_frm_get_cur_tab_gui_buffer <Success>")
//    TRC_MSG(TRC_MMI_FRM_HIST_GET_CUR_TAB_GUIBUF_ERR, "[MMI_FRM][Scenario][History] mmi_frm_get_cur_tab_gui_buffer <NULL pointer>")
//    TRC_MSG(TRC_MMI_FRM_HIST_GET_CUR_TAB_INPUTBUF, "[MMI_FRM][Scenario][History] mmi_frm_get_cur_tab_input_buffer <Success>")
//    TRC_MSG(TRC_MMI_FRM_HIST_GET_CUR_TAB_INPUTBUF_ERR, "[MMI_FRM][Scenario][History] mmi_frm_get_cur_tab_input_buffer <NULL pointer>")
//    TRC_MSG(TRC_MMI_FRM_HIST_GET_CUR_TAB_N_INPUTBUF, "[MMI_FRM][Scenario][History] mmi_frm_get_cur_tab_n_input_buffer <Success>")
//    TRC_MSG(TRC_MMI_FRM_HIST_GET_CUR_TAB_N_INPUTBUF_ERR1, "[MMI_FRM][Scenario][History] mmi_frm_get_cur_tab_n_input_buffer <Fail - can't find tab history>")
//    TRC_MSG(TRC_MMI_FRM_HIST_GET_CUR_TAB_N_INPUTBUF_ERR2, "[MMI_FRM][Scenario][History] mmi_frm_get_cur_tab_n_input_buffer <Fail - NULL input buffer pointer>")
    TRC_MSG(TRC_MMI_FRM_HIST_TAB_L_ARROW_KEY_HDLR, "[MMI_FRM][Scenario][History] mmi_frm_general_tab_l_arrow_key_hdlr")
    TRC_MSG(TRC_MMI_FRM_HIST_TAB_R_ARROW_KEY_HDLR, "[MMI_FRM][Scenario][History] mmi_frm_general_tab_r_arrow_key_hdlr")
//    TRC_MSG(TRC_MMI_FRM_HIST_FREE_TAB_BAR_ITEMS, "[MMI_FRM][Scenario][History] mmi_frm_free_tab_bar_items")
//    TRC_MSG(TRC_MMI_FRM_HIST_GET_TAB_BAR_ITEMS, "[MMI_FRM][Scenario][History] mmi_frm_get_tab_bar_items")
//    TRC_MSG(TRC_MMI_FRM_HIST_GET_TAB_BAR_ITEMS_ERR, "[MMI_FRM][Scenario][History] mmi_frm_get_tab_bar_items <Fail - tab_bar_num = 0>")
//    TRC_MSG(TRC_MMI_FRM_HIST_GEN_TAB_ENTRY_CHANGE_PAGE_IDX, "[MMI_FRM][Scenario][History] mmi_frm_general_tab_entry_change_page_index")
//    TRC_MSG(TRC_MMI_FRM_HIST_GEN_TAB_ENTRY_CHANGE_PAGE_IDX_ERR, "[MMI_FRM][Scenario][History] mmi_frm_general_tab_entry_change_page_index <Fail>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_ARG_WITH_SCRN_EXIT, "[MMI_FRM][Scenario][History] mmi_frm_get_argument_with_screen <Exit screen's arg> <scrn_id = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_ARG_WITH_SCRN_HIST, "[MMI_FRM][Scenario][History] mmi_frm_get_argument_with_screen <scrn_id = %Mmmi_screen_id_cgen_enum, hist_idx = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_ARG_WITH_SCRN_NULL, "[MMI_FRM][Scenario][History] mmi_frm_get_argument_with_screen <NULL arg> <scrn_id = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_SCRN_INFO, "[MMI_FRM][Scenario][History] mmi_frm_get_screen_info <scrn_id = %Mmmi_screen_id_cgen_enum, state = %Mmmi_frm_screen_state_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_SCRN_INFO_ERR, "[MMI_FRM][Scenario][History] mmi_frm_get_screen_info <Fail> <scrn_id = %Mmmi_screen_id_cgen_enum>")
//    TRC_MSG(TRC_MMI_FRM_HIST_HOLD_HIST_BUFF, "[MMI_FRM][Scenario][History] mmi_frm_hold_history_buffer <scrn_id = %Mmmi_screen_id_cgen_enum>")
//    TRC_MSG(TRC_MMI_FRM_HIST_HOLD_HIST_BUFF_ERR, "[MMI_FRM][Scenario][History] mmi_frm_hold_history_buffer <Fail> <scrn_id = %Mmmi_screen_id_cgen_enum>")
//    TRC_MSG(TRC_MMI_FRM_HIST_FREE_HIST_BUFF, "[MMI_FRM][Scenario][History] mmi_frm_free_history_buffer <scrn_id = %Mmmi_screen_id_cgen_enum>")
//    TRC_MSG(TRC_MMI_FRM_HIST_FREE_HIST_BUFF_ERR, "[MMI_FRM][Scenario][History] mmi_frm_free_history_buffer <Fail> <scrn_id = %Mmmi_screen_id_cgen_enum>")

    TRC_MSG(MMI_FRM_SCENARIO_POST_EVT_INTERNAL, "[MMI_FRM][Scenario] post_scenario_evt <act = %Mpost_scenario_act_enum, gid = %Mmmi_screen_id_cgen_enum, sid = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_SCENARIO_PROCESS_POST_EVT, "[MMI_FRM][Scenario] scenario_process_post_evt_ex <Begin> <type = %d>")
    TRC_MSG(MMI_FRM_SCENARIO_PROCESS_POST_EVT_HANDLING, "[MMI_FRM][Scenario] scenario_process_post_evt_ex <act = %Mpost_scenario_act_enum, gid = %Mmmi_screen_id_cgen_enum, sid = %Mmmi_screen_id_cgen_enum, node = 0x%x>")
    TRC_MSG(MMI_FRM_SCENARIO_PROCESS_POST_EVT_END, "[MMI_FRM][Scenario] scenario_process_post_evt_ex <End> <type = %d>")

    TRC_MSG(MMI_FRM_SCENARIO_SCRN_INACTIVE, "[MMI_FRM][Scenario] scrn_inactive <node = 0x%x, state = 0x%x, attrib = 0x%x, scrn_type = %Mmmi_node_type_enum, shell.state = 0x%x>")
    TRC_MSG(MMI_FRM_SCENARIO_SCRN_ACTIVE, "[MMI_FRM][Scenario] scrn_inactive <node = 0x%x, state = 0x%x, attrib = 0x%x, scrn_type = %Mmmi_node_type_enum, shell.state = 0x%x>")



    TRC_MSG(TRC_MMI_FRM_MEM_APP_ASM_ALLOC_INT, "[ASM][applib] <alloc> <app_id = %Mapplib_mem_ap_id_enum, size = %d, line = %d, ptr = 0x%x, alloc_count = %d>")
    TRC_MSG(TRC_MMI_FRM_MEM_APP_ASM_FREE_INT, "[ASM][applib] <free> <app_id = %Mapplib_mem_ap_id_enum, size = %d, line = %d, ptr = 0x%x, alloc_count = %d>")


END_TRACE_MAP(MOD_PLUTO_FW)
#endif /* PLUTO_FW_TRC_H*/

