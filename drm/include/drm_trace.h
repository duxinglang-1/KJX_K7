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
 * drm_util.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef DRM_TRACE_H
#define DRM_TRACE_H

#ifdef GEN_FOR_PC
#include "kal_trace.h"
#endif /* GEN_FOR_PC */
#include "kal_trace.h"
#include "stack_config.h"
#define TRACE_GROUP_MUTEX TRACE_GROUP_1
#define TRACE_GROUP_UI TRACE_GROUP_2
#define TRACE_GROUP_MEM TRACE_GROUP_3
#define TRACE_GROUP_HTTP TRACE_GROUP_5
#define TRACE_GROUP_AGENT TRACE_GROUP_6
#define TRACE_GROUP_FILE TRACE_GROUP_7
#define TRACE_GROUP_PDCF TRACE_GROUP_8
#define TRACE_GROUP_GENERAL TRACE_GROUP_9
#define TRACE_GROUP_ERROR TRACE_GROUP_9

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "drm_trace_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP(MOD_DRMT)

TRC_MSG(DRM_MEM_F7D4DBC76E8B4960BD93EE45FC503963,"[DRM] mem_init")
TRC_MSG(DRM_MEM_1101E0162A10E030579EDC200ACF2ABC,"[DRM] mem_reinit")
TRC_MSG(DRM_MEM_DE8595FE31ABFA1653FE554710C80448,"[DRM] mem_total_left_size")
TRC_MSG(DRM_MEM_C11C3F6606DFCB84F7E38CB3F53F2EDD,"[DRM] mem_delete")

TRC_MSG(DRM_ITF_9FF0DD4F811194AD49B061928BE0E764,"DRM_RESULT_INVALID_PARA")
TRC_MSG(DRM_ITF_C53ACC6EEBFD8F74EF7994742BD7F4DE,"DRM_RESULT_SIZE_TOO_BIG")
TRC_MSG(DRM_ITF_11701758220F424D0F4A7A0D6C878692,"DRM_activate_file")
TRC_MSG(DRM_ITF_E7189B32BD094EF8AF6A14A908B8124B,"DRM process file")
TRC_MSG(DRM_ITF_98C6C30956A2AA80A534DAA5F3BE7095,"[DRM] app_process_obj_hdlr")
TRC_MSG(DRM_ITF_F7230E172E65A6BA608EAA6BE334BC12,"[DRM] app_install_obj_hdlr")
TRC_MSG(DRM_ITF_D3609124D70935F282C63B9D34449EC8,"[DRM] ro_expiry_hdlr cb executed")
TRC_MSG(DRM_ITF_8FB627CFA22FB559DFAB176F5D21E1FD,"[DRM] ro_expiry_hdlr")
TRC_MSG(DRM_ITF_B5BAEE0DF7509F4F33FF69BB43157617,"[DRM] app_activate_hdlr")
TRC_MSG(DRM_ITF_9FF0DD4F811194AD49B061928BE0E765,"[DRM] validate_permission_by_cid, result = %d")
TRC_MSG(DRM_ITF_9FF0DD4F811194AD49B061928BE0E766,"[DRM] validate_timed_permission_by_cid, result = %d")
TRC_MSG(DRM_API_INSTALL,                         "DRM_install_object")
TRC_MSG(DRM_API_PARSE_DM,                        "DRM_parse_drm_message")
TRC_MSG(DRM_API_RSP_NO_DISK,                     "FS_DISK_FULL")
TRC_MSG(DRM_API_RSP_NO_RO_SPACE,                 "DRM_RESULT_NO_RIGHTS_SPACE")


TRC_MSG(DRM_0D483A63EA462D5165DB60CEF2935C68,"[DRM] version check fail: fs_errcode = %d")
TRC_MSG(DRM_D9E6C54BFD7BF0C3765D0616565600A4,"[DRM] version check fail: version change")
TRC_MSG(DRM_DC8C1EA787C00E0334AD16D3E6095C5A,"[DRM] version create fail: file status of verno = %d")
TRC_MSG(DRM_CHECK_ENGINE_READY, "[DRM] engine is not ready -- %Mmodule_type")

TRC_MSG(DRM_SDB_FAIL                           ,"[DRM] DB FAIL, f=%d , p=%d, r = %d")
TRC_MSG(DRM_SCAN_FAIL                          ,"[DRM] Scan FAIL, f=%d , p=%d, r = %d")
TRC_MSG(DRM_SCAN_SUCCESS                       ,"[DRM] Scan Finish")
TRC_MSG(DRM_SCAN_START                         ,"[DRM] Scan Start")

TRC_MSG(DRM_PROC_F1271A584DB6AA8B8674A41EA5EC63FF,"[DRM] validate fail by g_drm_is_process_database")
TRC_MSG(DRM_PROC_42E2ADC654B2973692BFFB2C07E71417,"[DRM] handle number %d")

TRC_MSG(DRM_9EBD9C2DFB6FBE9E9D123CBB85204291,"[DRM] stop timer %d")
TRC_MSG(DRM_A6AFDA4FF413E41DEFF856D2B767E3CC,"[DRM] timer expired")
TRC_MSG(DRM_F96AC00ADDFD638732995893F94EFC07,"[DRM] timer is cancelled")

TRC_MSG(DRM_SD_CB_RIGHTS_ARRIVE,           "[SD] Rights Arrive")
TRC_MSG(DRM_SD_CB_TABLE_FULL,           "[SD] Table Full")
TRC_MSG(DRM_SD_CB_CLEAR_ENTRY,           "[SD] Clear serial = %d")
TRC_MSG(DRM_SD_CB_UPDATE,           "[SD] Update serial = %d")
TRC_MSG(DRM_SD_CB_STOP_TIMER,           "[SD] Stop timer, id = %d")
TRC_MSG(DRM_SD_CB_START_TIMER,           "[SD] Start timer, id = %d")
TRC_MSG(DRM_SD_CB_REGISTER_RESULT,           "[SD] Register result = %d")
TRC_MSG(DRM_SD_CB_EXECUTE,           "[SD] Execute callback = %d")
TRC_MSG(DRM_SD_CB_INSERT_TIMER,           "[SD] Insert tiemr id = %d, serial = %d")


TRC_MSG(RMGR_UTIL_SPACE_CHECK,                      "[RMGR] mmi_rmgr_space_check, size = %d, max = %d")
TRC_MSG(RMGR_UTIL_SPACE_CHECK_CANCEL,               "[RMGR] mmi_rmgr_space_check_cancel")
TRC_MSG(RMGR_UTIL_UNLOCK_SESSION_CALLBACK,          "[RMGR] mmi_rmgr_unlock_session_callback")
TRC_MSG(RMGR_UTIL_UNLOCK_SESSION_RIGHT_DELIVERY_CB, "[RMGR] mmi_rmgr_unlock_session_right_delivery_cb, %d %d")
TRC_MSG(RMGR_UTIL_RESUME_UNLOCKING,                 "[RMGR] mmi_rmgr_resume_unlocking, %d")
TRC_MSG(RMGR_UTIL_UNLOCK_SESSUION_DEL_CB,           "[RMGR] mmi_rmgr_unlock_session_del_cb")
TRC_MSG(RMGR_UTIL_REGISTER_UNLOCK_SESSION,          "[RMGR] mmi_rmgr_register_unlock_session %d %d %d %d %d")
TRC_MSG(RMGR_UTIL_WIPE_UNLOCK_SESSION,              "[RMGR] mmi_rmgr_wipe_unlock_session")
TRC_MSG(RMGR_UTIL_SEND_RIGHTS_REQUEST,              "[RMGR] mmi_rmgr_send_rights_request")
TRC_MSG(RMGR_UTIL_REQUEST_RIGHTS_CONFIRM_DEL_CB,    "[RMGR] mmi_rmgr_request_rights_confirm_del_cb")
TRC_MSG(RMGR_UTIL_REQUEST_RIGHTS_BACK,              "[RMGR] mmi_rmgr_request_rights_back")
TRC_MSG(RMGR_UTIL_EXIT_REQUEST_RUGHTS_CONFIRM,      "[RMGR] mmi_rmgr_exit_request_rights_confirm")
TRC_MSG(RMGR_UTIL_REQUEST_RIGHTS_CONFIRM,           "[RMGR] mmi_rmgr_request_rights_confirm")
TRC_MSG(RMGR_UTIL_CHECK_RIGHTS_INTERNAL,            "[RMGR] mmi_rmgr_check_rights_internal %d %d %d %d")
TRC_MSG(RMGR_UTIL_CHECK_RIGHTS_BY_HANDLE,           "[RMGR] mmi_rmgr_check_rights_by_handle %d %d %d %d")
TRC_MSG(RMGR_UTIL_CHECK_RIGHTS_BY_PATH,             "[RMGR] mmi_rmgr_check_rights_by_path %d %d %d")
TRC_MSG(RMGR_UTIL_CHECK_RIGHTS_FULL_PROCEDURE,      "[RMGR] mmi_rmgr_check_rights_full_procedure %d %d %d %d %d")
TRC_MSG(RMGR_UTIL_CHECK_FORWARD,                    "[RMGR] mmi_rmgr_check_forward")
TRC_MSG(RMGR_UTIL_EXTREND_RIGHTS_INTERNAL,          "[RMGR] mmi_rmgr_extend_rights_internal %d %d")
TRC_MSG(RMGR_UTIL_EXTREND_RIGHTS_BY_PATH,           "[RMGR] mmi_rmgr_extend_rights_by_path %d %d")
TRC_MSG(RMGR_UTIL_EXTREND_RIGHTS_FULL_PROCEDURE,    "[RMGR] mmi_rmgr_extend_rights_full_procedure %d %d")
TRC_MSG(RMGR_UTIL_ACTIVATE_CALLBACK,                "[RMGR] mmi_rmgr_activate_callback result = %d")
TRC_MSG(RMGR_UTIL_SHOW_PROCESS_INFO,                "[RMGR] mmi_rmgr_show_process_info %d %d %d")

#ifdef __DRM_BSCI__
TRC_MSG(DRM_PROC_2D552BA94E10FF1095B833BE8BE9F878,"[DRM] handle roap pdu = %d")
TRC_MSG(DRM_PROC_69FFC62E04A823236F332A4152DC786D,"[DRM] handle roap trigger = %d")
TRC_MSG(DRM_PROC_006BE2686497EBB1D36013234BF8DF7F,"[DRM] handle protected ro = %d")
TRC_MSG(DRM_PROC_CFEB290175E901962405C945EAD556F8,"[DRM] handle roap pdu %d")
TRC_MSG(DRM_PROC_2577938C8DC4F30FB1642542CD6AD8E6,"[DRM] handle roap trigger %d")
TRC_MSG(DRM_PROC_21AA64FC566C0622A38B281BD4B0D011,"[DRM] handle protected ro %d")
TRC_MSG(DRM_PROC_3CDDF74893FE8928CBD1695B57D204ED,"[DRM] TYPE = DRM_PROCESS_TYPE_ASYNC\n")
TRC_MSG(DRM_PROC_C8AAFD9F27CB9E04E1CA5600CEDD1C26,"[DRM] DRM_RESULT_SIZE_TOO_BIG\n")
TRC_MSG(DRM_PROC_1A670B8E07098069EC81E8EC9F7E426A,"[DRM] Clean up fail, req->index = %d")
TRC_MSG(DRM_PROC_C2D21CE3D1A403014BD098A77630BB67,"[DRM] register fail %d")
TRC_MSG(DRM_PROC_1E108DC21F439768788743DCD9E41301,"[DRM] open file with permission none to %d")
TRC_MSG(DRM_PROC_FECA8D983297C12F35AD6759BBCF7CA8,"[DRM] open file with permission none")
TRC_MSG(DRM_PROC_94D37C626EDE1EBD07C1B922EC475135,"[DRM] open file with permission %d")
TRC_MSG(DRM_PROC_7D47C94CBB9449B602590795DD19F23A,"[DRM] open file: fp = %d, error = %d")
TRC_MSG(DRM_PROC_A9236614A812A11E8B6F8B1778F49C13,"[DRM] open file, too many files")
TRC_MSG(DRM_PROC_5601D5444894B1A059791DA1A115FFC1,"[DRM] close file: fp = %d")
TRC_MSG(DRM_PROC_53888BEB6E3577691605CEE13F48F827,"[DRM] close file: invalid file handle")
TRC_MSG(DRM_PROC_0CED13BC5B4E41A0B8843FEFD4217D0A,"[DRM] read file: fp = %d, size = %d, count = %d")
TRC_MSG(DRM_PROC_AFE6A581EA41CFEF956F81B9BBC68CC3,"[DRM] read file: fp = %d, size = %d, result = %d")
TRC_MSG(DRM_PROC_E08E6CDF705816C9329D1BBAFE1150F1,"[DRM] seek file: fp = %d, offset = %d, ref = %s")
TRC_MSG(DRM_PROC_3EE52FE310E8F2139CD05807F98D6CD2,"[DRM] seek file error: position %d")
TRC_MSG(DRM_PROC_E82A9027D45F014F136BD3F511C317AD,"[DRM] seek file: position %d")
TRC_MSG(DRM_PROC_54370E078EB39B792409D7C1937CA85E,"[DRM] file size: fp = %d = %d, size = %d")
TRC_MSG(DRM_PROC_27FDB38BDD52FC9E186AB389E95A4BC7,"[DRM] file pos: fp = %d = %d, pos = %d")
TRC_MSG(DRM_PROC_34495C3950743E51DD5068E7B3296AE8,"[DRM] Consume Right invalid para")
TRC_MSG(DRM_PROC_F1B7EC5C4BD77464195D56E9555FBB59,"[DRM] Permission not match perm = %d, bPerm = %d")
TRC_MSG(DRM_PROC_28B4BC2786DD5B1AC43F8EDB5FBA4FDB,"[DRM] Consume Right consumer = %d, fp = %d, perm = %d, only time = %d")
TRC_MSG(DRM_PROC_070085A43ABBEB409261C509F2B93A8E,"[DRM] Consume Right no valid consumer")
TRC_MSG(DRM_PROC_7295D728DEFFB0C6A9ADE22A45DAB91C,"[DRM] consume start_timer endtime = %d, accum = %d")
TRC_MSG(DRM_PROC_EEFAB64483F997CC4B15885841726012,"[DRM] consume count used = %d, total = %d, only_time = %d")
TRC_MSG(DRM_PROC_8F0C5DFFA9C73F5FF4CBBA31E5D72EBC,"[DRM] consume count time_count = %d, total = %d, only_time = %d")
TRC_MSG(DRM_PROC_2696B4778FBCDDBD9DFF6A086A8C8DDF,"[DRM] Consume Right Not drm, source = %d,  perm = %d, only_time = %d")
TRC_MSG(DRM_PROC_2B57B9E430EB9601A7772704DFB9B167,"[DRM] consume Right error %d")
TRC_MSG(DRM_PROC_2B57B9E430EB9601A7772704DFB9B166,"[DRM] stop consume, consumer = %d, time_passed = %d")
TRC_MSG(DRM_PROC_0C4F5AF5E0BD87FA2D1E3C344CEB99FD,"[DRM] stop consume count, only_time = %d")
TRC_MSG(DRM_PROC_F707DD1FEADCC76230032CAE9794C202,"[DRM] stop consume time, waiting_clean = %d, is_paused = %d, cb_executed = %d")
TRC_MSG(DRM_PROC_0D4CA3F9EDF90B7288E7132D63ACEFC4,"[DRM] stop consume, invalid id = %d")
TRC_MSG(DRM_PROC_51A09153F42584592CEA9342F28FB2C3,"[DRM] pause_consume, consumer = %d")
TRC_MSG(DRM_PROC_268522A5D590F8D82DAE04973321BA39,"[DRM] resume_consume, consumer = %d ")
TRC_MSG(DRM_PROC_51A09153F42584592CEA9342F28FB2C4,"[DRM] pause_consume, chktime = %d, pass_time = %d")
TRC_MSG(DRM_PROC_268522A5D590F8D82DAE04973321BA40,"[DRM] resume_consume, chktime = %d, pass_time = %d")
TRC_MSG(DRM_PROC_132CC2BAAE8D05B9A454355DF953BB0F,"[DRM] consume clean, consumer = %d")
TRC_MSG(DRM_PROC_B79E602BD77807A86E9E844657E9AE93,"[DRM] consume update, consumer = %d")
TRC_MSG(DRM_PROC_EBB26CC5236B3FDF948895BF612A0EC1,"[DRM] validate pass by count constraint")
TRC_MSG(DRM_PROC_D2A0BE72F5C0386F06D1DEC1C2928E8C,"[DRM] validate fp = %d, perm = %d, time_based = %d = %d")
TRC_MSG(DRM_PROC_90BEE4A6C08B4C63DB7E4AE8B1CD63C9,"[DRM] validate fp = %d, perm = %d, non drm")
TRC_MSG(DRM_PROC_42A60F652C5F452DF123852D505210C9,"DRM_FindFirstN: Invalid Path")
TRC_MSG(DRM_PROC_012B4C3C6EC5A694E63A607EC56A400B,"DRM_FindFirstN: Invalid Find Cntx")
TRC_MSG(DRM_PROC_A9BDC5E86F9E4D3865D2A0811D9B0B17,"DRM_FindFirstN: fp = %d")
TRC_MSG(DRM_PROC_94FFB7C40E8E25289D08B9C7E4FA7551,"DRM_FindFirstN: get db file info fail, error = %d")
TRC_MSG(DRM_PROC_B95511BF381C5550D25D02CAB6F50CBD,"DRM_FindFirstN: numobjects < 2, %d")
TRC_MSG(DRM_PROC_7D00901F72B86AB43F4FA744C8E57C50,"DRM_FindFirstN: expected index out of range: 0 ~ %d, EntryIndex")
TRC_MSG(DRM_PROC_BB95B342417D5CAFEBC7891BDEE694D9,"DRM_FindFirstN: get size fail, error = %d")
TRC_MSG(DRM_PROC_2BF1818BB002D1FE1869DED24BA1FEB2,"DRM_FindFirstN: No seperater")
TRC_MSG(DRM_PROC_E3D009D31A2923C00F3CC9578242C3B9,"DRM_FindFirstN: size too big")
TRC_MSG(DRM_PROC_F4DEB50D9A14303480846E8E706825B5,"DRM_FindNext, handle not match, fp = %d")
TRC_MSG(DRM_PROC_2FA9E9BD188F5BD2F66D2D28549679E8,"DRM_FindNext, index out of range: 0 ~ %d, %d, %d")
TRC_MSG(DRM_PROC_7BCAB82F20565AADF2742C6535DB09F3,"DRM_FindNext, fopen fail, error = %d")
TRC_MSG(DRM_PROC_6A194757136D6B6F21497E985AFCB01A,"DRM_FindNext, get size error, error = %d")
TRC_MSG(DRM_PROC_3D4895AEB133E0D05FFECA0EC9F0E5B5,"DRM_FIND_CLOSE")
TRC_MSG(DRM_PROC_C88D3861E0079F5C396F8648989E66B2,"DRM_FIND_CLOSE invalid memory")
TRC_MSG(DRM_PROC_F1271A584DB6AA8B8674A41EA5EC63FD,"[DRM] bsci_activateContent = %d")
TRC_MSG(DRM_PROC_F1271A584DB6AA8B8674A41EA5EC63FE,"[DRM] new_path_len = 0, careful")

TRC_MSG(DRM_HTTP_47DF204AB1C7161AD0D7195F1F1421BC,"[DRM] drmt_http_update_result %d")
TRC_MSG(DRM_HTTP_F9BCE59EE962CFD6E2B3D3C8CF37F38F,"[DRM] drmt_http_init_response_buffer")
TRC_MSG(DRM_HTTP_B33BE014D4DD386953F52C4417B591FD,"[DRM] drmt_http_send_auth_res")
TRC_MSG(DRM_HTTP_093AB9DBFD772D0C0B57D5799EE4993E,"[DRM] drmt_http_recv_auth_ind")
TRC_MSG(DRM_HTTP_991D76F05BA11DED2DFFED85DD5B9B83,"[DRM] drmt_http_send_set_channel_req")
TRC_MSG(DRM_HTTP_398028D815C883686BDF5A31D999CF59,"[DRM] drmt_http_recv_set_channel_rsp")
TRC_MSG(DRM_HTTP_5BD927F2AECE14896A7B3AAC41849900,"[DRM] drmt_http_send_unset_channel_req")
TRC_MSG(DRM_HTTP_C3F43EF7955CB0B0B6C6841F658B4BB1,"[DRM] drmt_http_recv_unset_channel_rsp")
TRC_MSG(DRM_HTTP_F656286C82B6AACD9A4F8CD4C01CD2D5,"[DRM] drmt_http_send_http_req")
TRC_MSG(DRM_HTTP_B9B6AA63AEC98753274A2974689F4C87,"[DRM] drmt_http_recv_http_rsp")
TRC_MSG(DRM_HTTP_2B451F88170F7C49D4492815F5EBED68,"[DRM] drmt_http_send_cancel_req")
TRC_MSG(DRM_HTTP_FF33BA6B80C6B95C9E90BE80E1EB5DA2,"[DRM] drmt_http_recv_cancel_rsp")
TRC_MSG(DRM_HTTP_62AB0A6842C64D64337F0D6C2844A8B4,"[DRM] drmt_http_recv_dl_progress_ind")
TRC_MSG(DRM_HTTP_7DCA9DC6EF1471F10F6435AFE15D994C,"[DRM] drmt_http_send_dl_progress_res")
TRC_MSG(DRM_HTTP_847BA39B9FC798C9429637B706DBF3EE,"[DRM] drmt_http_send_clear_req")
TRC_MSG(DRM_HTTP_5E7A9F272888D69854C3AD39F2E2C125,"[DRM] drmt_http_recv_clear_rsp")
TRC_MSG(DRM_HTTP_349010A885BD081ADADDFD2C270D0C6F,"[DRM] drmt_http_send_read_req, seq=%d")
TRC_MSG(DRM_HTTP_5E7A9F272888D69854C3AD39F2E2C126,"[DRM] drmt_http_recv_read_rsp")
TRC_MSG(DRM_HTTP_FA0F234D1E76FFFA072E75452F3079DB,"[DRM] Task is not MOD_DRMT!! set channel")
TRC_MSG(DRM_HTTP_C328442339C8A1BE1554282523E9082E,"[DRM] Task is not MOD_DRMT!! get file")
TRC_MSG(DRM_HTTP_36E586CCB128A20B83AE4A3B924A9401,"[DRM] parse header fail")
TRC_MSG(DRM_HTTP_61FD51B50DE6B2257A6FC0C6226F25C3,"[DRM] OSD_Http_Get_File Invalid parameter")
TRC_MSG(DRM_HTTP_2D8750E26EA605F3EB6B7AB0C502EB1E,"[DRM] OSD_Http_Get_File No connection")
TRC_MSG(DRM_HTTP_A430913F0B62DF6FD39BD89A149A02DB,"[DRM] OSD_Http_Get_File http error = %d")
TRC_MSG(DRM_HTTP_608EF489FA860ECC13FE42D5CF999384,"[DRM] OSD_Http_Get_File user cancel")
TRC_MSG(DRM_HTTP_14D3CFB6D13A93714158992A289246C4,"[DRM] OSD_Http_Get_File no memory")
TRC_MSG(DRM_HTTP_D1D1B57FD700BFEB59038472A38D0918,"[DRM] OSD_Http_Get_File server error=%d")
TRC_MSG(DRM_HTTP_C3061AFF49CC762641C261BA5CF4898D,"[DRM] OSD_Http_Get_File server status=%d")
TRC_MSG(DRM_HTTP_84D26DF64F23340947BA3E1C4131773F,"[DRM] OSD_Http_Get_File progress user cancel")
TRC_MSG(DRM_HTTP_C4FB297F12069BC3E138BA813226A67C,"[DRM] Task is not MOD_DRMT!! post file")
TRC_MSG(DRM_HTTP_B185F9B8E7563AE66DAF794F7E9EB32D,"[DRM] OSD_Http_Post_File invalid parameter")
TRC_MSG(DRM_HTTP_4855AA57D79B8D29FFEDB837639F9FC0,"[DRM] OSD_Http_Post_File no connection")
TRC_MSG(DRM_HTTP_857D1C676B2F2E6B56594790CC4FC65A,"[DRM] OSD_Http_Post_File http error=%d")
TRC_MSG(DRM_HTTP_19C3B294AF58EACD9977BCBCE5634FF9,"[DRM] OSD_Http_Post_File User Cancel")
TRC_MSG(DRM_HTTP_4610AFF15A476D0135F25C60B1DEB1F4,"[DRM] OSD_Http_Post_File No memory")
TRC_MSG(DRM_HTTP_BF31E4F2B98B05F07DCFD7624D438782,"[DRM] OSD_Http_Post_File server error")
TRC_MSG(DRM_HTTP_D384D3ABD27768A9153C27FDD4CFEF30,"[DRM] OSD_Http_Post_File server error status = %d")
TRC_MSG(DRM_HTTP_89AD01DCC51EC65EF47A0C069BABE2CE,"[DRM] OSD_Http_Post_File No error")
TRC_MSG(DRM_HTTP_38EFA074DDD665379D6C0B6E114E9615,"[DRM] Task is not MOD_DRMT!! post buffer")
TRC_MSG(DRM_HTTP_68CBD68EFBDC3F4D44F9298A5AA22DFD,"[DRM] OSD_Http_Post_Buffer invalid parameter")
TRC_MSG(DRM_HTTP_96A3D30310F089C02DFED627BA317B56,"[DRM] OSD_Http_Post_Buffer no connection")
TRC_MSG(DRM_HTTP_84411388BD92A88B8001897355587BEE,"[DRM] OSD_Http_Post_Buffer http error")
TRC_MSG(DRM_HTTP_86BDDF49357975F46BD36679E02D1CA9,"[DRM] OSD_Http_Post_Buffer user cancel")
TRC_MSG(DRM_HTTP_A7921039480D4A9F18C893DC6C842E2F,"[DRM] OSD_Http_Post_Buffer no memory")
TRC_MSG(DRM_HTTP_2F471C4D361CE0C3D41B461336EA11CA,"[DRM] OSD_Http_Post_Buffer server error=%d")
TRC_MSG(DRM_HTTP_AC66F2B9F810F97980BF4F4F9439362C,"[DRM] OSD_Http_Post_Buffer server status=%d")
TRC_MSG(DRM_HTTP_9848AB83FAABF326779AEC1F42227C57,"[DRM] OSD_Http_Post_Buffer no error")

TRC_MSG(DRM_1E8FAB649C15C97FE385C4D4809C1A0B,"[DRM] lock: %d %d %d %d %d")
TRC_MSG(DRM_3772C98C55B2263F987C1DE4379FDC73,"[DRM] unlock: %d %d %d %d")
TRC_MSG(DRM_BD019324FD2E6DD67B418496002FBC26,"[DRM] OSD_STime_UpdateSecureTime")
TRC_MSG(DRM_C295FEB824B5D12B1AD92C8C3B5AE1B3,"[DRM] UpdateTime_UTC")
TRC_MSG(DRM_563A16AE0163A6E3E0CB7735CCBC0E6A,"[DRM] EnableTrustedTime")
TRC_MSG(DRM_76154F6A677B1A18CD2E121813A629E7,"[DRM] Need do Time Sync, trusted = %d")

TRC_MSG(DRM_UI_324EE1E4B544F83ECD611E4734A1D96D,"[DRM] UIType = %d")
TRC_MSG(DRM_UI_9C799241E9357A8D5B75A35CEB06F908,"[DRM] User Ret:%d")
TRC_MSG(DRM_UI_5CB9240A57CD8D60476A5B395404C138,"[DRM] User Cancel")
TRC_MSG(DRM_UI_AE02C1B9B939E916993C1A028379053D,"[DRM] OSD_UI_Allow_Register_Agent")
TRC_MSG(DRM_UI_433FD538FB338A2920837B42E0C18271,"[DRM] Task is not MOD_DRMT!!")
TRC_MSG(DRM_UI_27EDCEF388663B44B8B57CBB5F9EC16C,"[DRM] OSD_UI_Allow_Acquire_RO")
TRC_MSG(DRM_UI_4CB2472378581912503B6818DCE4AE35,"[DRM] OSD_UI_Allow_Domain_Join")
TRC_MSG(DRM_UI_1CA79C5696144200FD11AFD58FE174A7,"[DRM] OSD_UI_Allow_Domain_Leave")
TRC_MSG(DRM_UI_BD88657EA67AAEDD97FAC4234F1B9EFB,"[DRM] OSD_UI_Notify_V2_Install")
TRC_MSG(DRM_UI_CC50EC727A55296390D82079A1E9FA10,"[DRM] OSD_UI_Store_Dcf")
TRC_MSG(DRM_UI_10E86F995DC716D8BB83DAE1D0C19837,"[DRM] OSD_UI_Browse_Rights_Issuer")
TRC_MSG(DRM_UI_87DC11DF79DF7F131D253049F29DBC5B,"[DRM] riUrl is null!!")
TRC_MSG(DRM_UI_147518AFD7F58D521C797410F060457A,"[DRM] OSD_UI_Browse_Join_Domain")
TRC_MSG(DRM_UI_4545672B6249BD69C1805ABCAFACAAB8,"[DRM] User ret: %d")
TRC_MSG(DRM_UI_24DC341CD4E0865B1C92090B42C33FCD,"[DRM] OSD_UI_Browse_Register")
TRC_MSG(DRM_UI_0CAD3AA84D71D32A5877E564C134F28A,"[DRM] OSD_UI_Allow_Preview_Download")
TRC_MSG(DRM_UI_26163E29301CB73AEA33DBA908ED50D1,"[DRM] OSD_UI_Allow_Silent_Download")
TRC_MSG(DRM_UI_2425E7B21CE2BFF472EE890E3CB8BE11,"[DRM] OSD_UI_Allow_Time_Sync")
TRC_MSG(DRM_UI_C8EF1722E3B0E8E528EDF6AAF647BD97,"[DRM] OSD_UI_Time_Sync_Status")
TRC_MSG(DRM_UI_C17E41C3635D73563B4CECEBE258219A,"[DRM] OSD_UI_Notify_SD_RO")
TRC_MSG(DRM_UI_63DB84106CAA948B9ABFBDAC1F8F2AA3,"[DRM] HandleROAPStatus code = %d")
TRC_MSG(DRM_UI_133BA84F47C7DEF44ABB1752D567001E,"[DRM] mmi_drm_send_get_auth_cnf")
TRC_MSG(DRM_UI_CE94B029B5756B814B4232BC9719ED38,"[DRM] mmi_drm_recv_get_auth_req")
TRC_MSG(DRM_UI_F1FD1800D19CEBDA0801E88457290DC4,"[DRM] mmi_drm_send_get_user_confirm_cnf")
TRC_MSG(DRM_UI_17D20C96FAF91BFEA39E8F747F887E37,"[DRM] mmi_drm_recv_get_user_confirm_req")
TRC_MSG(DRM_UI_797AEA2EED5663D4006AE425A425A6A6,"[DRM] mmi_drm_send_alert_user_rsp")
TRC_MSG(DRM_UI_D29FECA278D3080AC8A72760BE12C606,"[DRM] mmi_drm_recv_alert_user_ind")
TRC_MSG(DRM_UI_4ACAB9E6A26B1DBC49FD6C60AE7BB217,"[DRM] mmi_drm_send_notify_info_rsp")
TRC_MSG(DRM_UI_142FD2E5271AC508EC9475EC6849825D,"[DRM] mmi_drm_send_open_url_cnf")
TRC_MSG(DRM_UI_22F28A2359C392559C8711B17F956C03,"[DRM] mmi_drm_recv_open_url_req")
TRC_MSG(DRM_UI_5393CDEA59C3901674ED763A3B00D2F6,"[DRM] mmi_drm_clean_screen_ind")
TRC_MSG(DRM_UI_GET_CONFIRM_MESSAGE             ,"[DRM] receive confirm message from mmi %d")

TRC_MSG(DRM_FILE_58B98B6D6BA0B0CE9C71401A3A18BDB2,"OSD_File_Wopen: error=%d")
TRC_MSG(DRM_FILE_4CC8A2698557B49A30DD5B35422FF59F,"OSD_File_Wopen Error: index= %d, old_handle = %d")
TRC_MSG(DRM_FILE_446229A7A1C7CCA3FBD3C64EC875C4A7,"OSD_File_Wopen: handle=%d")
TRC_MSG(DRM_FILE_70A6E922AA99BF7E84FF98FD1B775FB9,"OSD_File_Wopen: append seek result=%d")
TRC_MSG(DRM_FILE_71C0D86F8C4394F54A8EE41C095B368C,"OSD_File_Assign: handle = %d, FS_GetFileInfo fail=%d")
TRC_MSG(DRM_FILE_4D61456C2833757C519AD3923365157D,"OSD_File_Close: handle not exist %d")
TRC_MSG(DRM_FILE_86A1A877ED409FEBDC09990895DF3752,"OSD_File_Close: handle = %d, result=%d")
TRC_MSG(DRM_FILE_9B2CD17514F55D37CD5E9C438CFEBA99,"OSD_File_Read: handle = %d, size=%d, len=%d")
TRC_MSG(DRM_FILE_4818EB856094772543165435C7A589F0,"OSD_File_Read: handle=%d, size=%d, len=%d, error = %d")
TRC_MSG(DRM_FILE_AAE236EA9C122FAFD9DA1AEDBF6D4046,"OSD_File_Read: handle=%d, size=%d, len=%d, FS_PARAM_ERROR")
TRC_MSG(DRM_FILE_60E191189978B1D7A657F5BFEC99AC40,"OSD_File_Write: handle = %d, size=%d, len=%d")
TRC_MSG(DRM_FILE_B7F51347BE1617D3295D1173E84F5398,"OSD_File_Write: error = %d")
TRC_MSG(DRM_FILE_CF46929AD6E21A4E674BB750705C1A4F,"OSD_File_Seek: handle = %d, offset=%d, result=%d")
TRC_MSG(DRM_FILE_3FF8830FAA1E4BF4BA6A49F064FC0BE8,"OSD_File_Tell: handle = %d, position=%d")
TRC_MSG(DRM_FILE_70FCCB2F98B7DF6D413DA199F2BC19BE,"OSD_File_Eof: handle = %d, position=%d, size=%d")
TRC_MSG(DRM_FILE_B57F22A4E9EDF89BAAC620EB93C676B7,"OSD_File_Truncate")
TRC_MSG(DRM_FILE_18635590160793C61AE9BFD28109761D,"OSD_File_GetSize: handle=%d, size=%d")

TRC_MSG(DRM_PROC_GERNERATE_SEED_FAIL            ,"[DRM] Gernerate Seed Fail, result = %d")
TRC_MSG(DRM_PROC_GET_BOUNDARY_FAIL              ,"[DRM] Get boundary fail, result = %d")
TRC_MSG(DRM_PROC_PARSE_DRM_MESSAGE_FAIL         ,"[DRM] Parse drm message fail, result = %d")
TRC_MSG(DRM_PROC_CID_DB_ADD_FAIL                ,"[DRM] Add cid into db fail, result = %d")
TRC_MSG(DRM_PROC_DELETE_RIGHTS_BY_CID_FAIL      ,"[DRM] Delete Right by cid fail, result = %d")
TRC_MSG(DRM_PROC_DELETE_CID_FROM_DB_FAIL        ,"[DRM] Delete cdi from db fail, result = %d")

TRC_MSG(DRM_PROC_CONSTRUCT_PDCF                 ,"[DRM] construct_pdcf, fh = %d")
TRC_MSG(DRM_PROC_INIT_TRACK_BY_KMS              ,"[DRM] init_track_by_kms, trackID = %d, permission = %d")
TRC_MSG(DRM_PROC_PDCF_ERROR                     ,"[DRM] error = %d, kk=%d")
TRC_MSG(DRM_PROC_INIT_TRACK_BY_META             ,"[DRM] init_track_by_meta, trackID = %d, permission = %d")
TRC_MSG(DRM_PROC_DESTRUCT_PDCF                  ,"[DRM] destruct_pdcf, pdcf_handle = %d")
TRC_MSG(DRM_PROC_DECODE_PDCF                    ,"[DRM] decode_trace, track_handle = %d, is_streaming = %d")

#elif defined(__DRM_MTK__)
/* common */
TRC_MSG(DRM_MTK_OPEN_FILE,  "FS_Open = %d")
TRC_MSG(DRM_MTK_OBJ_DM,     "DM Obj")
TRC_MSG(DRM_MTK_OBJ_FL,     "FL Obj")
TRC_MSG(DRM_MTK_OBJ_CD,     "CD Obj")
TRC_MSG(DRM_MTK_OBJ_SD_00,  "SD Obj")
TRC_MSG(DRM_MTK_OBJ_SD_01,  "SD w/o rights")
TRC_MSG(DRM_MTK_OBJ_SD_02,  "SD w/ rights")
TRC_MSG(DRM_MTK_RESULT,     "result = %x")

/* drm_core_cmd.c */
TRC_MSG(DRM_MTK_ADD_OBJ_RO,        "drm_core_add_object")
TRC_MSG(DRM_MTK_API_INSTALL,       "drm_core_install_object")
TRC_MSG(DRM_MTK_API_PARSE_DB,      "drm_core_parse_drm_message")
TRC_MSG(DRM_MTK_API_ENCODE_DM,     "drm_core_encode_drm_message")
    
TRC_MSG(DRM_MTK_RO_VALIDATE,           "drm_core_check_rights = %d")
TRC_MSG(DRM_MTK_RO_FUTURE,             "drm_core_rights_in_future: %d")
TRC_MSG(DRM_MTK_RO_LOAD_MULTI,         "Rights: load multi rights")


TRC_MSG(DRM_MTK_CHECK_RO,                   "drm_core_check_rights_aux: ltime = %d")
TRC_MSG(DRM_MTK_CHECK_RO_STATUS,            "Right status = %d")

TRC_MSG(DRM_MTK_MULTIRO_00,         "Update DT cons: [CUR] = %x ~ %x")
TRC_MSG(DRM_MTK_MULTIRO_01,         "Update DT cons: [POS] = %x ~ %x")
TRC_MSG(DRM_MTK_MULTIRO_02,         "Update DT cons: num = %d")
TRC_MSG(DRM_MTK_MULTIRO_03,         "Update DT cons: Unlimited")

TRC_MSG(DRM_MTK_CONS_VALIDATE_TYPE,           "check constraint, type = %d")
TRC_MSG(DRM_MTK_CONS_COUNT_VALIDATE,           "constraint used_count = %d")
TRC_MSG(DRM_MTK_CONS_DATETIME_VALIDATE,           "constraint constraint current time = %d, start_time = %d, end_time = %d")
TRC_MSG(DRM_MTK_CONS_INTERVAL_VALIDATE,           "constraint current time = %d, interval = %d, start_intv = %d, end_intv = %d")
TRC_MSG(DRM_MTK_CONS_DATETIME_IN_FUTURE,           "constraint datetime in future")
TRC_MSG(DRM_MTK_CONS_GET_CONSTRAINT,           "get constraint: best_index = %d, is_download = %d")
TRC_MSG(DRM_MTK_CONS_GET_IN_FUTURE_CONS,           "get in future constraint, next is %d")
TRC_MSG(DRM_MTK_LOAD_RO_BEST,           "RO best[0] = %d, best[1] = %d, best[2] = %d, best[3] = %d")
TRC_MSG(DRM_MTK_LOAD_RO_NUM,           "RO num[0] = %d, num[1] = %d, num[2] = %d, num[3] = %d")

TRC_MSG(DRM_MTK_MULTIRO_PERMISSION,           "Multi RO permission = %d")
TRC_MSG(DRM_MTK_MULTIRO_CONS,           "Multi RO constraint index = %d, type = %d")
TRC_MSG(DRM_MTK_MULTIRO_NEW_CONS_POS,           "Multi RO new constraint pos = %d")
TRC_MSG(DRM_MTK_MULTIRO_NEW_CONS_TYPE,           "Multi RO new constraint type = %d")
TRC_MSG(DRM_MTK_MULTIRO_INSERT_RESULT,           "Multi RO insert prev_cons = %d, next_cons = %d")
TRC_MSG(DRM_MTK_MULTIRO_INSERT_NEW,           "Multi RO insert into empty list, best = %d, number = %d")

TRC_MSG(DRM_MTK_MULTIRO_MERGE_COUNT,           "Multi RO merge count, used_count = %d, total_count = %d")
TRC_MSG(DRM_MTK_MULTIRO_DT_CONS_RANGE,           "Multi RO DT start = %d, end = %d")
TRC_MSG(DRM_MTK_MULTIRO_DT_CONS_DT,           "Multi RO merge DT compare start = %d, end = %d")
TRC_MSG(DRM_MTK_MULTIRO_MERGE_DT_FIRST,           "Multi RO first DT constraint")
TRC_MSG(DRM_MTK_MULTIRO_MERGE_DT_LAST,           "Multi RO last DT constraint")
TRC_MSG(DRM_MTK_MULTIRO_MERGE_DT_COMPARE_INDEX,           "Multi RO merge DT compare = %d, next = %d")
TRC_MSG(DRM_MTK_MULTIRO_MERGE_DT_COMPARE_DT,           "Multi RO merge DT compare dt, start = %d, end = %d")
TRC_MSG(DRM_MTK_MULTIRO_MERGE_DT_NEXT_DT,           "Multi RO merge DT next dt, start = %d, end = %d")
TRC_MSG(DRM_MTK_MULTIRO_MERGE_DT_S1,           "Multi RO merge DT S1")
TRC_MSG(DRM_MTK_MULTIRO_MERGE_DT_S2,           "Multi RO merge DT S2")
TRC_MSG(DRM_MTK_MULTIRO_MERGE_DT_S3,           "Multi RO merge DT S3")
TRC_MSG(DRM_MTK_MULTIRO_MERGE_DT_S4,           "Multi RO merge DT S4")
TRC_MSG(DRM_MTK_MULTIRO_MERGE_DT_S5,           "Multi RO merge DT S5")
TRC_MSG(DRM_MTK_MULTIRO_MERGE_DT_S6,           "Multi RO merge DT S6")
TRC_MSG(DRM_MTK_MULTIRO_MERGE_DT_S7,           "Multi RO merge DT S7")

TRC_MSG(DRM_MTK_MULTIRO_ORDER,           "Update multi RO order")

TRC_MSG(DRM_MTK_RO_CONSUME,            "drm_core_consume_rights_aux, rights= %d, timed? %d")
TRC_MSG(DRM_MTK_RO_CONSUME_FAIL,       "w/o valid rights")
TRC_MSG(DRM_MTK_RO_CONSUME_COUNT,      "count: %d -> %d")
TRC_MSG(DRM_MTK_RO_CONSUME_INTERVAL,   "interval: %d -> %d")

/* drm_core_proc.c */
TRC_MSG(DRM_MTK_FILE_UPDATE_00, "handle = %d: @start/position/end = %d/%d/%d -%d")
TRC_MSG(DRM_MTK_FILE_UPDATE_01, "handle = %d: start/@position/end = %d/%d/%d -%d")
TRC_MSG(DRM_MTK_FILE_FS_POS,    "current pos = %d - %d")
TRC_MSG(DRM_MTK_FILE_ASSERT,    "ASSERT - %d")

TRC_MSG(DRM_MTK_FILE_OPEN_00,   "drm_open_file: Empty path")
TRC_MSG(DRM_MTK_FILE_OPEN_01,   "drm_open_file: w/ rigths, length = %d")
TRC_MSG(DRM_MTK_FILE_OPEN_02,   "drm_open_file: w/o rights")
TRC_MSG(DRM_MTK_FILE_CLOSE,     "drm_close_file: handle = %d -%d")
TRC_MSG(DRM_MTK_FILE_READ_00,   "drm_read_file: Rights pending")
TRC_MSG(DRM_MTK_FILE_READ_01,   "drm_read_file: handle = %d, size = %d, offset = %d")
TRC_MSG(DRM_MTK_FILE_READ_02,   "drm_read_file: @Cache Total Missed! -%d")
TRC_MSG(DRM_MTK_FILE_READ_03,   "drm_read_file: @EOF! -%d")
TRC_MSG(DRM_MTK_FILE_READ_04,   "drm_read_file: @Cache Partial Missed! -%d")
TRC_MSG(DRM_MTK_FILE_READ_05,   "drm_read_file: fail = %d")

TRC_MSG(DRM_MTK_FILE_SEEK_00,       "drm_seek_file: handle = %d, offset = %d, ref = %d")
TRC_MSG(DRM_MTK_FILE_SEEK_01,       "drm_seek_file: backward %d %d")
TRC_MSG(DRM_MTK_FILE_SEEK_02,       "drm_seek_file: @Cache Missed! -%d")
TRC_MSG(DRM_MTK_FILE_SEEK_03,       "drm_seek_file: FS_Seek %d %d")
TRC_MSG(DRM_MTK_FILE_SEEK_04,       "drm_seek_file: fail = %d, offset = %d, ref = %d")
TRC_MSG(DRM_MTK_FILE_SIZE_00,       "drm_file_size: ret = %d, size = %d, updated = NO")
TRC_MSG(DRM_MTK_FILE_SIZE_01,       "drm_file_size: ret = %d, size = %d, updated = YES")
TRC_MSG(DRM_MTK_FILE_POS,           "drm_file_pos: handle = %d, position = %d")

TRC_MSG(DRM_MTK_DEC,           "previous_blk = %d, curr_blk = %d")
TRC_MSG(DRM_MTK_DEC_OFFSET,    "handle = %d, offset = %d")
TRC_MSG(DRM_MTK_DEC_LEN,       "handle = %d, len = %d")
TRC_MSG(DRM_MTK_DEC_IN,        "handle = %d, in = %x%x")
TRC_MSG(DRM_MTK_DEC_OUT,       "handle = %d, out = %x%x")


 
/* drm_core_parse.c */
TRC_MSG(DRM_MTK_PARSER_TYPE,    "Mime type = %s")
TRC_MSG(DRM_MTK_PARSER_ENC,     "encrypt size = %d")
TRC_MSG(DRM_MTK_PARSER_CID,     "Empty CID")
#else /* __DRM_WS__ */
TRC_MSG(DRM_WS_PTR_UPDATE_START, "index = %d: @start/position/end = %d/%d/%d -%d")
TRC_MSG(DRM_WS_PTR_UPDATE_POS, "index = %d: start/@position/end = %d/%d/%d -%d")
TRC_MSG(DRM_WS_PTR_UPDATE_END, "index = %d: start/position/@end = %d/%d/%d -%d")

TRC_MSG(DRM_WS_OPEN_TYPE,    "        - DRM")
TRC_MSG(DRM_WS_OPEN_INFO,    "        - nEncMethod = %d, uEncCntSize = %d, uOrgCntSize = %d")
TRC_MSG(DRM_WS_OPEN_IDEX,    "        - index = %d")

TRC_MSG(DRM_WS_CLOSE,   "drm_close_file: index = %d")

TRC_MSG(DRM_WS_READ_PARA,      "drm_read_file: index = %d, size = %d")
TRC_MSG(DRM_WS_READ_CACHE_PTR, "        - Cache Reload = %d, pointer = %d")
TRC_MSG(DRM_WS_READ_MISS,      "        - @Cache Total Missed!")
TRC_MSG(DRM_WS_READ_EOF,       "        - @EOF! len_to_copy = %d")
TRC_MSG(DRM_WS_READ_PARTIAL,   "        - @Cache Partial Missed! len_to_copy = %d")
TRC_MSG(DRM_WS_READ_FAIL,      "        - fail = %d - %d")

TRC_MSG(DRM_WS_SEEK,    "drm_core_seek_file: index = %d, offset = %d, ref = %d")

TRC_MSG(DRM_WS_POS,     "drm_core_file_pos: index = %d, position = %d")

TRC_MSG(DRM_WS_SIZE,     "drm_core_file_size: index = %d, size = %d")
TRC_MSG(DRM_WS_CONTENT_TYPE_FAIL,    "drm_core_get_content_type: can't find")

TRC_MSG(DRM_WS_DEC,        "        - previous_blk = %d, curr_blk = %d")
TRC_MSG(DRM_WS_DEC_OFFSET, "        - offset = %d")
TRC_MSG(DRM_WS_DEC_IV_LEN,    "        - IV len = %d")
TRC_MSG(DRM_WS_DEC_DATA_LEN,    "        - data len = %d")
TRC_MSG(DRM_WS_DEC_IV,     "        - IV = %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x")
TRC_MSG(DRM_WS_DEC_IN,     "        - ciphertext = %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x")
TRC_MSG(DRM_WS_DEC_EXTERN, "        - DRMAgent_DecryptData(%d)=%d")
TRC_MSG(DRM_WS_DEC_OUT,    "        - plain-text  = %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x")
TRC_MSG(DRM_WS_DEC_PAD,    "        - padding = %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x")

#endif
END_TRACE_MAP(MOD_DRMT)

#endif /* DRM_TRACE_H */

