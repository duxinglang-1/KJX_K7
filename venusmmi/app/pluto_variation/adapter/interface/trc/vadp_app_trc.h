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
 *  vfx_trc.h
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 *==============================================================================
 *******************************************************************************/

#ifndef __VADP_APP_TRC_H__
#define __VADP_APP_TRC_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef GEN_FOR_PC
 #include "stack_config.h"
#else
 #include "kal_trace.h"
#endif /* GEN_FOR_PC */

#include "kal_trace.h"

/* For MOD_VFX_APP */
#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "vadp_app_trc_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP(MOD_VAPP)

    /* Comments for following trace log */
    TRC_MSG(VAPP_HS_INIT_MSG, "[HS] Home Screen Init")

    /* 
     * Home screen: 
     */
     
    /* Common: */
    TRC_MSG(VAPP_HS_ON_INIT_MSG,                            "[HS] onInit")
    TRC_MSG(VAPP_HS_ON_DEINIT_MSG,                          "[HS] onDeInit")
    TRC_MSG(VAPP_HS_ON_INIT_VIEW_MSG,                       "[HS] onInitView")
    TRC_MSG(VAPP_HS_ON_DEINIT_VIEW_MSG,                     "[HS] onDeinitView")
    TRC_MSG(VAPP_HS_ON_ENTER_VIEW_MSG,                      "[HS] onEnterView")
    TRC_MSG(VAPP_HS_ON_EXIT_VIEW_MSG,                       "[HS] onExitView")
    TRC_MSG(VAPP_HS_ON_TIMER_ADD_WIDGET_MSG,                "[HS] onTimerAddWidget, trace: %d")
    TRC_MSG(VAPP_HS_ON_TIMER_ADD_SHORTCUT_MSG,              "[HS] onTimerAddShortcut, trace: %d")
    TRC_MSG(VAPP_HS_ON_TIMER_CREATE_WIDGET_MSG,             "[HS] onTimerCreateWidget, trace: %d, idx: %d")
    TRC_MSG(VAPP_HS_ON_WIDGET_BAR_UPDATE_FOLDING_MSG,       "[HS] onWidgetBarUpdateFolding, fold: %d")
    TRC_MSG(VAPP_HS_ON_CLOSE_WIDGET_BAR_MSG,                "[HS] onCloseWidgetBar")
    TRC_MSG(VAPP_HS_FOLD_ALL_MSG,                           "[HS] foldAll, trace: %d")
    TRC_MSG(VAPP_HS_ROTATE_DESKTOP_MSG,                     "[HS] rotateDesktop, trace: %d")
    
    /* Operator name: */
    TRC_MSG(VAPP_HS_ON_NETWORK_NAME_CHANGED_MSG,            "[HS] onNetworkNameChanged")
    TRC_MSG(VAPP_HS_ON_NETWORK_STATUS_CHANGED_MSG,          "[HS] onNetworkStatusChanged")
    TRC_MSG(VAPP_HS_ON_NETWORK_NAME_CHANGED_2_MSG,          "[HS] onNetworkNameChanged_2")
    TRC_MSG(VAPP_HS_ON_NETWORK_STATUS_CHANGED_2_MSG,        "[HS] onNetworkStatusChanged_2")
    TRC_MSG(VAPP_HS_ON_SET_IDLE_MODE_TEXT_MSG,              "[HS] setIdleModeText")
    TRC_MSG(VAPP_HS_ON_SET_IDLE_MODE_ICON_MSG,              "[HS] setIdleModeIcon")

    /* Recent event widget: */
    TRC_MSG(VAPP_HS_RECENT_EVENT_ON_CREATE_VIEW_MSG,        "[HS][RecentEvent] onCreateView")
    TRC_MSG(VAPP_HS_RECENT_EVENT_ON_RELEASE_VIEW_MSG,       "[HS][RecentEvent] onReleaseView")
    TRC_MSG(VAPP_HS_RECENT_EVENT_ON_EVENT_CHANGED_MSG,      "[HS][RecentEvent] onEventChanged")
    TRC_MSG(VAPP_HS_RECENT_EVENT_DUMP_DETAIL_CHANGED_MSG,   "[HS][RecentEvent] changed, idx: %d, type: %d, time: %d, read: %d")
    TRC_MSG(VAPP_HS_RECENT_EVENT_ON_SELECT_EVENT_MSG,       "[HS][RecentEvent] onSelectEvent")
    TRC_MSG(VAPP_HS_RECENT_EVENT_DUMP_DETAIL_SELECTED_MSG,  "[HS][RecentEvent] selected, idx: ")

    /* Event inbox widget: */
    TRC_MSG(VAPP_HS_EVENT_INBOX_EVT_HDLR,                   "[HS][EventInbox] evt_hdlr, evt_id: %d")
    TRC_MSG(VAPP_HS_EVENT_INBOX_CHANGED,                    "[HS][EventInbox] changed, type: %d")
    TRC_MSG(VAPP_HS_EVENT_INBOX_REFRESH,                    "[HS][EventInbox] refresh")
    TRC_MSG(VAPP_HS_EVENT_INBOX_UM_RSP,                     "[HS][EventInbox] UM rsp, type: %d, num: %d")
    TRC_MSG(VAPP_HS_EVENT_INBOX_SET_NUM,                    "[HS][EventInbox] set_num, type: %d, num: %d")
        
    /* Alarm widget: */
    TRC_MSG(VAPP_HS_ALARM_ON_CREATE_VIEW_MSG,               "[HS][Alarm] onCreateView")
    TRC_MSG(VAPP_HS_ALARM_ON_RELEASE_VIEW_MSG,              "[HS][Alarm] onReleaseView")       
    TRC_MSG(VAPP_HS_ALARM_ON_TOGGLE_MSG,                    "[HS][Alarm] onToggleAlarm")
    TRC_MSG(VAPP_HS_ALARM_DUMP_DETAIL_TOGGLE_MSG,           "[HS][Alarm] toggle, idx: %d, val: %d")

    /* Audio widget: */
    TRC_MSG(VAPP_HS_AUDPLY_GET_STATE_MSG,                   "[HS][Audplayer] getState = %d")
    TRC_MSG(VAPP_HS_AUDPLY_GET_DURATION_MSG,                "[HS][Audplayer] getDuration = %d")
    TRC_MSG(VAPP_HS_AUDPLY_GET_CURRTIME_MSG,                "[HS][Audplayer] getCurrTime = %d")

    /* FMR widget: */
    TRC_MSG(VAPP_HS_FMR_GET_STATE_MSG,                      "[HS][FMR] getState = %d")
    TRC_MSG(VAPP_HS_FMR_GET_CHNUM_MSG,                      "[HS][FMR] getChannelNum = %d")
    
    /* Todo Widget */
    TRC_MSG(VAPP_HS_TODO_AVAILABLE,           "[HS][TODO]Available=%d")
    TRC_MSG(VAPP_HS_TODO_SEARCH_TIME,         "[HS][TODO]SearchTime:%d/%d/%d %d:%d:%d")
    TRC_MSG(VAPP_HS_TODO_SEARCH_CALLBACK,     "[HS][TODO][Callback]refTime:%d/%d/%d %d:%d:%d, repeat=%d")
    TRC_MSG(VAPP_HS_TODO_SEARCH_CALLBACK_RET, "[HS][TODO][Callback]ret=%d")
    
    /* Squeeze & Jelly filter effect */ 
    TRC_MSG(VAPP_SQUEEZE_FILTER_ON_PROCESS_CLOCK_BEGIN_MSG,  "Vcp Squeeze Filter On Process Clock Begin: %d\n")
    TRC_MSG(VAPP_SQUEEZE_FILTER_ON_PROCESS_CLOCK_END_MSG,  "Vcp Squeeze Filter On Process Clock End: %d\n")
    TRC_MSG(VAPP_JELLY_FILTER_ON_PROCESS_CLOCK_BEGIN_MSG,  "Vcp Squeeze Filter On Process Clock Begin: %d\n")
    TRC_MSG(VAPP_JELLY_FILTER_ON_PROCESS_CLOCK_END_MSG,  "Vcp Squeeze Filter On Process Clock End: %d\n")

    /* 3D cube */
    /* common */
    TRC_MSG(VAPP_CUBE_ON_INIT_MSG,                      "[3D CUBE] VappCubeScr::onInit")
    TRC_MSG(VAPP_CUBE_ON_DEINIT_MSG,                    "[3D CUBE] VappCubeScr::onDeInit")
    TRC_MSG(VAPP_CUBE_ON_ENTRY_CUBE_APP,                "[3D CUBE] EntryCubeVapp (%d)")
    TRC_MSG(VAPP_CUBE_ON_PREVIEW_PEN_INPUT,             "[3D CUBE] onPreviewPenInput, trace: %d, pos: (%d, %d)") 
    TRC_MSG(VAPP_CUBE_CANNOT_CREATE_FOLDER,             "[3D CUBE] error!! cannot create shell folder")
    TRC_MSG(VAPP_CUBE_CANNOT_GET_SNAPSHOT,              "[3D CUBE] error!! cannot get snapshot")
    TRC_MSG(VAPP_CUBE_FOLD_SHORTCUT_BAR,                "[3D CUBE] fold shortcut bar (%d)")  
    TRC_MSG(VAPP_CUBE_REG_DEF_PAGE_ACT,                 "[3D CUBE] VappCubeScr::regDefaultPageAct: obj=%d")
    TRC_MSG(VAPP_CUBE_DEREG_DEF_PAGE_ACT,               "[3D CUBE] VappCubeScr::deregDefaultPageAct: obj=%d")
    TRC_MSG(VAPP_CUBE_CANCEL_PAGE_ACT,                  "[3D CUBE] VappCubeScr::cancelDefaultPageAct!!")
    TRC_MSG(VAPP_CUBE_ON_EXP_LIST,                      "[3D CUBE] VappCubeScr::noDefaultPageAction: obj=%d")

    /* 3d cube application */
    TRC_MSG(VAPP_CUBE_INIT,                             "[3D CUBE] VappCube::onInit")
    TRC_MSG(VAPP_CUBE_SHOW_SMALL_CUBE,                  "[3D CUBE] display small cube")
    TRC_MSG(VAPP_CUBE_INIT_CUBE_APP,                    "[3D CUBE] VappCube::VappCube: small=%d idx=%d action=%d cube_effect=%d")
    TRC_MSG(VAPP_CUBE_GET_CUBE_HISTORY,                 "[3D CUBE] VappCube::getHistory: small=%d idx=%d")
    TRC_MSG(VAPP_CUBE_GET_CUR_SCR_IDX,                  "[3D CUBE] VappCube::getCurrentScrIndex: cur_idx=%d")
    TRC_MSG(VAPP_CUBE_FINISH,                           "[3D CUBE] VappCube::onCubeFinish: select_idx=%d")
    TRC_MSG(VAPP_CUBE_ENTRY_APP_SCR,                    "[3D CUBE] VappCube::entryAppScreen")

    /* 3d cube adaption layer */
    TRC_MSG(VAPP_CUBE_SAVE_FILE, "[3D CUBE] [%d]. save file into driver(%d), scr=%d, len=%d")
    TRC_MSG(VAPP_CUBE_SAVE_FILE_FAIL, "[3D CUBE] [%d]. fail to save file into driver(%d), scr=%d")
    TRC_MSG(VAPP_CUBE_ENCODE_FILE, "[3D CUBE] [%d]. encode file to: %d, ret=%d")
    TRC_MSG(VAPP_CUBE_IS_FILE_EXISTED, "[3D CUBE] [%d] is screen(%d) existed, ret=%d")
    TRC_MSG(VAPP_CUBE_FREE_RES, "[3D CUBE] free cube resources!!")
    TRC_MSG(VAPP_CUBE_SAVE_LAYER_TO_BUF, "[3D CUBE] [%d]. save current layer to buffer, ret=%d")
    TRC_MSG(VAPP_CBUE_IS_IN_TRANSITION, "[3D CUBE] is cube in transition: %d")
    TRC_MSG(VAPP_CUBE_GET_BUF_FROM_FILE, "[3D CUBE] [%d]. get buffer from file, scr_idx=%d, len=%d")
    TRC_MSG(VAPP_CUBE_IS_SMALL, "[3D CUBE] is small cube: %d")

    /* Cube VipContact */
    TRC_MSG(VAPP_CUBE_VIP_CONTACT_INIT,        "[3D CUBE][VipContact] Init")
    TRC_MSG(VAPP_CUBE_VIP_CONTACT_DEINIT,      "[3D CUBE][VipContact] Deinit")
    TRC_MSG(VAPP_CUBE_VIP_CONTACT_PHB_EVENT,   "[3D CUBE][VipContact] phb evt:id=%d,index=%d")
    TRC_MSG(VAPP_CUBE_VIP_CONTACT_PHB_EVENT_UPDATE,"[3D CUBE][VipContact] updated index=%d")
    TRC_MSG(VAPP_CUBE_VIP_CONTACT_PHB_AVAILABLE, "[3D CUBE][VipContact]phb available=%d")
    TRC_MSG(VAPP_CUBE_VIP_CONTACT_PHB_SELECT,    "[3D CUBE][VipContact]phb select index=%d, store index=%d")
    TRC_MSG(VAPP_CUBE_VIP_CONTACT_NWK_AVAILABLE, "[3D CUBE][VipContact]network available=%d")

    TRC_MSG(VAPP_CUBE_VIP_CONTACT_EDIT_SWAP, "[3D CUBE][VipContact]Edit Swap:currIdx=%d,moveIdx=")
    TRC_MSG(VAPP_CUBE_VIP_CONTACT_NO_SWAP, "[3D CUBE][VipContact]Edit Swap: no swap")
    TRC_MSG(VAPP_CUBE_VIP_CONTACT_SWITCH_NOFITY, "[3D CUBE][VipContact]number list switch back")
    TRC_MSG(VAPP_CUBE_VIP_CONTACT_NUM_SELECT, "[3D CUBE][VipContact]number selected: flag=%d")
    TRC_MSG(VAPP_CUBE_VIP_CONTACT_UPDATE_CONT, "[3D CUBE][VipContact]update contact image: index=%d, ret=%d")
    TRC_MSG(VAPP_CUBE_VIP_CONTACT_ACTION_HANDLER, "[3D CUBE][VipContact]Action handler, button=%d")
    TRC_MSG(VAPP_CUBE_VIP_CONTACT_CALL_MULTI_NUM, "[3D CUBE][VipContact]Action handler, Call, multi,index=%d")
    TRC_MSG(VAPP_CUBE_VIP_CONTACT_CALL_ONE_NUM, "[3D CUBE][VipContact]Action handler, Call, one,index=%d")
    TRC_MSG(VAPP_CUBE_VIP_CONTACT_FIND_SELECT, "[3D CUBE][VipContact]findSelect(),index=%d")
    TRC_MSG(VAPP_CUBE_VIP_CONTACT_SHOW_BTN_HILITE, "[3D CUBE][VipContact]showButtonHilite()")
    TRC_MSG(VAPP_CUBE_VIP_CONTACT_CLOSE_BTN_HILITE, "[3D CUBE][VipContact]closeButtonHilite()")
    TRC_MSG(VAPP_CUBE_VIP_CONTACT_EDIT_DONE, "[3D CUBE][VipContact]onBtnEditDone()")
    TRC_MSG(VAPP_CUBE_VIP_CONTACT_UPDATE_STATE, "[3D CUBE][VipContact]upodateContent(), state=%d")
    TRC_MSG(VAPP_CUBE_VIP_CONTACT_SELECT_CONTACT, "[3D CUBE][VipContact]selectCont(), index=%d")

    /* 3D cube Imgview Application*/
    TRC_MSG(VAPP_CUBE_IMGVIEW_SCR_CREATE_FILE_LIST,                   "[Cube Imgview] [SCR] createFileList : result = %d, cell count = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_SCR_ONINIT,                             "[Cube Imgview] [SCR] OnInit : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_SCR_ONDEINIT,                           "[Cube Imgview] [SCR] OnDeinit : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_SCR_ON_PENINPUT,                        "[Cube Imgview] [SCR] onPenInput : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_SCR_ON_SORTOVER,                        "[Cube Imgview] [SCR] onSortOver : myData = %d, count = %d, sort_state = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_SCR_ON_DECODE_OVER,                     "[Cube Imgview] [SCR] onDecodeOver : index = %d , mode = %d, state = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_SCR_ON_EVENT_TAP_CELL,                  "[Cube Imgview] [SCR] onEventTapCell : index = %d ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_SCR_ON_LOADING_TIMER_ARRIVE,            "[Cube Imgview] [SCR] onLoadingTimerExpir : loading count = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_SCR_ON_BACK_EFFECT_FINISH,              "[Cube Imgview] [SCR] onBackEffectFinished : isComplete = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_SCR_ON_FRONT_EFFECT_FINISH,             "[Cube Imgview] [SCR] onFrontEffectFinished : isComplete = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_SCR_ON_EVENT_BUTTON_UP,                 "[Cube Imgview] [SCR] onEventUpClose : is contain pos = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_SCR_GET_AVAILABLE_RECT,                 "[Cube Imgview] [SCR] getAvailRect : rect = %d, %d, %d, %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_SCR_START_TIMELINE,                     "[Cube Imgview] [SCR] startTimeLine : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_SCR_STOP_TIMELINE,                      "[Cube Imgview] [SCR] stopTimeLine : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_SCR_ON_TIMELINE_STOP,                   "[Cube Imgview] [SCR] onTimeLineStop : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_SCR_SET_ARROW_HIDDEN,                   "[Cube Imgview] [SCR] setArrowHidden : is Hideen = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_SCR_GET_APP_STATE,                      "[Cube Imgview] [SCR] getAppState : state = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_SCR_SET_APP_STATE,                      "[Cube Imgview] [SCR] setAppState : state = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_SCR_VIEW_MODE_TAP_CELL,                 "[Cube Imgview] [SCR] onViewModeEventTapCell : index = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_SCR_GET_TARGET_WIDTH_HEIGHT,            "[Cube Imgview] [SCR] getTargetWidthHeight : index = %d, mode = %d")

    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU1_ONINIT,                           "[Cube Imgview] [MENU1] onInit : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU1_ONDEINIT,                         "[Cube Imgview] [MENU1] onDeinit : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU1_CREATE_LAYOUT,                    "[Cube Imgview] [MENU1] createLayout : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU1_CREATE_CELL,                      "[Cube Imgview] [MENU1] createCell : group = %d, index = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU1_ON_CLOSE_CELL,                    "[Cube Imgview] [MENU1] onCloseCell : group = %d, index = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU1_ON_UPDATE_CELL,                   "[Cube Imgview] [MENU1] onUpdateCell : pos = %d, flag = %d, is skip update = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU1_ON_TAP_CELL,                      "[Cube Imgview] [MENU1] onTapCell : group = %d, index = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU1_ON_KEY_INPUT,                     "[Cube Imgview] [MENU1] onKeyInput : app mode = %d, key = %d , new focus = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU1_ON_FOCUS_INDEX_CHANGE,            "[Cube Imgview] [MENU1] onFocusIndexChange : new = %d, old = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU1_ON_DRAG_START,                    "[Cube Imgview] [MENU1] onDragStart : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU1_ON_DRAG_END,                      "[Cube Imgview] [MENU1] onDragEnd : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU1_ON_VIEW_CHANGE,                   "[Cube Imgview] [MENU1] onViewChanged : new = %d, old = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU1_ON_DRAG,                          "[Cube Imgview] [MENU1] onDrag : offset = %d, cancel free mdoe = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU1_GET_CELL_WIDTH_HEIGHT,            "[Cube Imgview] [MENU1] getCellWidthHeight : width = %d, height = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU1_SET_CELL_WIDTH,                   "[Cube Imgview] [MENU1] setCellWidth : value = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU1_SET_CELL_HEIGHT,                  "[Cube Imgview] [MENU1] setCellHeight : value = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU1_SET_CELL_COUNT,                   "[Cube Imgview] [MENU1] setCellCount : count = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU1_ON_FOCUS_CHANGE,                  "[Cube Imgview] [MENU1] onFocusChange : group = %d, pos = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU1_SET_CACHE_NUMBER,                 "[Cube Imgview] [MENU1] setCacheNumber :")

    TRC_MSG(VAPP_CUBE_IMGVIEW_LAYOUT1_ONINIT,                         "[Cube Imgview] [LAYOUT1] onInit : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_LAYOUT1_ONDEINIT,                       "[Cube Imgview] [LAYOUT1] onDeinit : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_LAYOUT1_GET_CELL_COUNT,                 "[Cube Imgview] [LAYOUT1] getCellCount : count = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_LAYOUT1_GET_CONTENT_LEN,                "[Cube Imgview] [LAYOUT1] getContentLength : length = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_LAYOUT1_QUERY_REGION,                   "[Cube Imgview] [LAYOUT1] queryRegion : region = %d - %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_LAYOUT1_QUERY_CELL_RECT,                "[Cube Imgview] [LAYOUT1] queryCellRect : index = %d, rect = %d, %d, %d, %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_LAYOUT1_QUEYR_CELL_RECT_BY_POS,         "[Cube Imgview] [LAYOUT1] queryCellContentRectByPos : index = %d, rect = %d, %d, %d, %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_LAYOUT1_GET_CONTNET_SIZE,               "[Cube Imgview] [LAYOUT1] getContentSize : size = %d, %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_LAYOUT1_GET_PREFER_MAGIN,               "[Cube Imgview] [LAYOUT1] getPreferFocusMargin : margin = %d, %d, %d, %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_LAYOUT1_SET_FOCUS_ITEM,                 "[Cube Imgview] [LAYOUT1] setFocusItem : index = %d, isVisible = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_LAYOUT1_GET_CELL_POS_BY_PT,             "[Cube Imgview] [LAYOUT1] getCellPosByPt : pt = %d, %d,  pos = %d, %d")

    TRC_MSG(VAPP_CUBE_IMGVIEW_CELL1_ONINIT,                           "[Cube Imgview] [CELL1] onInit : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_CELL1_ONDEINIT,                         "[Cube Imgview] [CELL1] onDeinit : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_CELL1_SET_BG_POS,                       "[Cube Imgview] [CELL1] setBgPos : pos = %d, %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_CELL1_SET_CONTENT_POS,                  "[Cube Imgview] [CELL1] setContentPos : pos = %d, %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_CELL1_SET_BOUNDS,                       "[Cube Imgview] [CELL1] setBgBounds : bounds = %d, %d, %d, %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_CELL1_SET_CONTENT_BOUNDS,               "[Cube Imgview] [CELL1] setContentBounds : bounds = %d, %d, %d, %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_CELL1_UPDATE_CELL,                      "[Cube Imgview] [CELL1] updateCellImgae : group = %d, index = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_CELL1_UPDATE_POS,                       "[Cube Imgview] [CELL1] updatePos : rect = %d, %d, %d, %d, animation = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_CELL1_ENTER,                            "[Cube Imgview] [CELL1] enter : rect = %d, %d, %d, %d, animation = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_CELL1_LEAVE,                            "[Cube Imgview] [CELL1] leave : rect = %d, %d, %d, %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_CELL1_SET_CONTENT_INDEX,                "[Cube Imgview] [CELL1] setContentIndex : index = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_CELL1_ADD_DISPLAY_RIGHTS,               "[Cube Imgview] [CELL1] addDisplayRights : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_CELL1_REDUCE_DISPLAY_RIGHTS,            "[Cube Imgview] [CELL1] reduceDisplayRights : ")
    
    TRC_MSG(VAPP_CUBE_IMGVIEW_BTN2_SET_IMG,                           "[Cube Imgview] [BTN2] setImage : image = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_BTN2_SET_HILIGHT_IMG,                   "[Cube Imgview] [BTN2] setImageHighLight : image = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_BTN2_ONINIT,                            "[Cube Imgview] [BTN2] onInit : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_BTN2_ONDEINIT,                          "[Cube Imgview] [BTN2] onDeinit : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_BTN2_ONPENINPUT,                        "[Cube Imgview] [BTN2] onPenInput : act event = %d")
    
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU2_ONINIT,                           "[Cube Imgview] [MENU2] onInit : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU2_ONDEINIT,                         "[Cube Imgview] [MENU2] onDeinit : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU2_CREATE_LAYOUT,                    "[Cube Imgview] [MENU2] createLayout : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU2_CREATE_CELL,                      "[Cube Imgview] [MENU2] createCell : group = %d, index = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU2_ON_CLOSE_CELL,                    "[Cube Imgview] [MENU2] onCloseCell : group = %d, index = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU2_ON_UPDATE_CELL,                   "[Cube Imgview] [MENU2] onUpdateCell : group = %d, index = %d, flag = %d, is skip = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU2_ON_TAP_CELL,                      "[Cube Imgview] [MENU2] onTapCell : group = %d, index = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU2_ON_KEY_INPUT,                     "[Cube Imgview] [MENU2] onKeyInput : act event is %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU2_ON_FOCUS_INDEX_CHANGE,            "[Cube Imgview] [MENU2] onFocusIndexChange : new = %d, old = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU2_GET_CELL_WIDTH_HEIGHT,            "[Cube Imgview] [MENU2] getCellWidthHeight : width = %d, height = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU2_ON_DRAG_START,                    "[Cube Imgview] [MENU2] onDragStart : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU2_ON_DRAG_END,                      "[Cube Imgview] [MENU2] onDragEnd : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU2_ON_DRAG,                          "[Cube Imgview] [MENU2] onDrag : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU2_SET_FOCUS_ITEM,                   "[Cube Imgview] [MENU2] setFocusItem : focus = %d, is visible = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU2_SET_CELL_COUNT,                   "[Cube Imgview] [MENU2] setCellCount : count = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU2_SET_CELL_WIDTH,                   "[Cube Imgview] [MENU2] setCellWidth = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU2_SET_CELL_HEIGHT,                  "[Cube Imgview] [MENU2] setCellHeight = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU2_QUERY_CELL_RECT,                  "[Cube Imgview] [MENU2] queryCellRect : index = %d, rect = %d, %d, %d, %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU2_SET_CACHE_NUMBER,                 "[Cube Imgview] [MENU2] setCacheNumber : number = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU2_GET_VIEW_RECT,                    "[Cube Imgview] [MENU2] getViewRect : rect = %d, %d, %d, %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_MENU2_GET_FOCUS_INDEX_BY_PT,            "[Cube Imgview] [MENU2] getFocusIndexByRect : rect = %d, %d, %d, %d, index = %d")

    TRC_MSG(VAPP_CUBE_IMGVIEW_LAYOUT2_ONINIT,                         "[Cube Imgview] [LAYOUT2] onInit : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_LAYOUT2_ONDEINIT,                       "[Cube Imgview] [LAYOUT2] onDeinit :")
    TRC_MSG(VAPP_CUBE_IMGVIEW_LAYOUT2_GET_CELL_COUNT,                 "[Cube Imgview] [LAYOUT2] getCellCount : count = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_LAYOUT2_GET_CONTENT_LEN,                "[Cube Imgview] [LAYOUT2] getContentLength : length = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_LAYOUT2_QUERY_REGION,                   "[Cube Imgview] [LAYOUT2] queryRegion : rect = %d, %d, %d, %d, region = %d - %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_LAYOUT2_QUERY_CELL_RECT,                "[Cube Imgview] [LAYOUT2] queryCellRect : index = %d, rect = %d, %d, %d, %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_LAYOUT2_QUERY_CONTENT_RECT_BY_POS,      "[Cube Imgview] [LAYOUT2] queryCellContentRectByPos : group = %d, index = %d, rect = %d, %d, %d, %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_LAYOUT2_GET_CONTENT_SIZE,               "[Cube Imgview] [LAYOUT2] getContentSize : size = %d, %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_LAYOUT2_GET_PREFER_MARGIN,              "[Cube Imgview] [LAYOUT2] getPreferFocusMargin : magin = %d, %d, %d, %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_LAYOUT2_ON_VIEW_CHANGE,                 "[Cube Imgview] [LAYOUT2] onViewChanged : new = %d, old = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_LAYOUT2_GET_CELL_POS_BY_PT,             "[Cube Imgview] [LAYOUT2] getCellPosByPt : pt = %d, %d, pos = %d, %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_LAYOUT2_GET_VIEW_RECT,                  "[Cube Imgview] [LAYOUT2] getViewRect : rect = %d, %d, %d, %d")

    TRC_MSG(VAPP_CUBE_IMGVIEW_CELL2_ONINIT,                           "[Cube Imgview] [CELL2] onInit : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_CELL2_ONDEINIT,                         "[Cube Imgview] [CELL2] onDeinit : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_CELL2_SET_BG_POS,                       "[Cube Imgview] [CELL2] setBgPos : pos = %d, %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_CELL2_SET_CONTENT_POS,                  "[Cube Imgview] [CELL2] setContentPos : pos = %d, %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_CELL2_SET_BG_BOUNDS,                    "[Cube Imgview] [CELL2] setBgBounds : bounds = %d, %d, %d, %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_CELL2_SET_CONTENT_BOUNDS,               "[Cube Imgview] [CELL2] setContentBounds : bounds = %d, %d, %d, %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_CELL2_UPDATE_CELL_IMAGE,                "[Cube Imgview] [CELL2] updateCellImgae : group = %d, pos = %d")
    TRC_MSG(VAPP_CUBE_IMGVIEW_CELL2_ON_DRAW,                          "[Cube Imgview] [CELL2] onDraw : ")
    TRC_MSG(VAPP_CUBE_IMGVIEW_CELL2_SET_CELL_POS,                     "[Cube Imgview] [CELL2] setCellPos : index = %d")

    /* 3d cube media player */
    TRC_MSG(VAPP_CUBE_MEDPLY_SET_STATE,                 "[CUBE MEDPLY] SET state: %d")
    TRC_MSG(VAPP_CUBE_MEDPLY_SET_PLAY_INDEX,            "[CUBE MEDPLY] SET play index: %d")
    TRC_MSG(VAPP_CUBE_MEDPLY_INFO_STATE,                "[CUBE MEDPLY] STATE: %d")
    TRC_MSG(VAPP_CUBE_MEDPLY_INFO_HIGHLIGHT_INDEX,      "[CUBE MEDPLY] m_highlightIndex = %d")
    TRC_MSG(VAPP_CUBE_MEDPLY_INFO_PLAY_INDEX,           "[CUBE MEDPLY] m_curPlayIndex =%d")
    TRC_MSG(VAPP_CUBE_MEDPLY_INFO_TOTAL_TIME,           "[CUBE MEDPLY] song duration = %d")
    TRC_MSG(VAPP_CUBE_MEDPLY_INFO_IS_LIST_END,          "[CUBE MEDPLY] is list end = %d")     

    TRC_MSG(VAPP_CUBE_MEDPLY_FUNC_ON_TAP_FOCUS_CELL,    "[CUBE MEDPLY] onTapCell()")
    TRC_MSG(VAPP_CUBE_MEDPLY_FUNC_EVENT_TAP_CELL,       "[CUBE MEDPLY] onEventTapCell()")
    TRC_MSG(VAPP_CUBE_MEDPLY_FUNC_LOAD_PANEL,           "[CUBE MEDPLY] loadPlayPanel()")
    TRC_MSG(VAPP_CUBE_MEDPLY_FUNC_PREPARE_PANEL,        "[CUBE MEDPLY] preparePlayPanel()")
    TRC_MSG(VAPP_CUBE_MEDPLY_FUNC_ADJUST_ITEM,          "[CUBE MEDPLY] adjustFocusItem()")
    TRC_MSG(VAPP_CUBE_MEDPLY_FUNC_EVENT_MEDIA_CHANGE,   "[CUBE MEDPLY] onEventMediaChange()")
    TRC_MSG(VAPP_CUBE_MEDPLY_FUNC_EVENT_PLAY_END,       "[CUBE MEDPLY] onEventPlayEnd()")
    TRC_MSG(VAPP_CUBE_MEDPLY_FUNC_EVENT_STATE_CHANGE,   "[CUBE MEDPLY] onEventStateChanged()")
    TRC_MSG(VAPP_CUBE_MEDPLY_FUNC_EVENT_UP_CLOSE,       "[CUBE MEDPLY] onEventUpClose()")
    TRC_MSG(VAPP_CUBE_MEDPLY_FUNC_ON_SWITCH_PLAY,       "[CUBE MEDPLY] onSwitchPlay()")  
    
    /* Shell Media Player */
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_CALL_UPDATECELLIMAGE,"[Shell][MP] Calling updateCellImage(), line:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_CREATECELL,"[Shell][MP] createCell(%d), line:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_GETIMAGEBUFFER_OK,"[Shell][MP] onUpdateCell(%d) getImageBuffer, OK line:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_GETIMAGEBUFFER_DECODING,"[Shell][MP] onUpdateCell(%d) getImageBuffer, DECODING line:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_GETIMAGEBUFFER_FAIL,"[Shell][MP] onUpdateCell(%d) getImageBuffer, FAIL line:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_ONUPDATECELL,"[Shell][MP] onUpdateCell(%d), line:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_ONUPDATECELL_IMAGE,"[Shell][MP] onUpdateCell(%d) STATE_IMAGE, line:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_ONUPDATECELL_SETIMAGE,"[Shell][MP] onUpdateCell(%d) setImageVuffer, line:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_ONUPDATECELL_USEDEFAULT,"[Shell][MP] onUpdateCell(%d) useDefaultImage, line:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_EXIT_UDPATECELLIMAGE,"[Shell][MP] return from upateCellImage(), line:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_UDPATECELLIMAGE_LOCKIMAGE,"[Shell][MP] lock image[%d], line:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_UDPATECELLIMAGE_LOCKIMAGE_OK,"[Shell][MP] lock image(%d) OK, line:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_UDPATECELLIMAGE_LOCKIMAGE_FAIL,"[Shell][MP] lock image(%d) fail, line:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_UDPATECELLIMAGE_LOCKIMAGE_WAITING,"[Shell][MP] lock image(%d) waiting, line:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_ONDECODECALLBACK,"[Shell][MP] onDecodeCallback image(%d), line:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_CALL_UPDATEDECODERESULT,"[Shell][MP] updateDecodeResult(%d), line:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_CALL_UPDATEDECODERESULT_FAIL,"[Shell][MP] Cell(%d) not exist, line:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_UPDATEDECODERESULT_CELLEXIST,"[Shell][MP] updateDecodeResult: cell(%d) exist, line:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_UPDATEDECODERESULT_OK,"[Shell][MP] updateDecodeResult: succeed to setImageBuffer(%d), line:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_UPDATEDECODERESULT_FAIL,"[Shell][MP] updateDecodeResult: fail , useDefaultImage(%d), line:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_UPDATEDECODERESULT_WAIT,"[Shell][MP] updateDecodeResult: waiting(%d), line:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_ONCLOSECELL,"[Shell][MP] onCloseCell(%d), line:%d")
    TRC_MSG(VADP_SHELL_MEDIAPLAYER_CANCEL_DECODE_CELL,"[SHELL][MP][ADP] cancel_decode_cell, line:%d")
    TRC_MSG(VADP_SHELL_MEDIAPLAYER_GET_IMAGE_FROM_DB,"[SHELL][MP][ADP] get_image_from_db(%d) result = %d, line:%d")
    TRC_MSG(VADP_SHELL_MEDIAPLAYER_CANCEL_GET_IMAGE,"[SHELL][MP][ADP] cancel_get_image, line:%d")
    TRC_MSG(VADP_SHELL_MEDIAPLAYER_ARTWORK_ASYNC_STOP,"[SHELL][MP][ADP] cancel_async_get_image , line:%d")    
    TRC_MSG(VADP_SHELL_MEDIAPLAYER_GET_ARTWORK_ASYNC,"[SHELL][MP][ADP] get_item_artwork_async[%d] state = %d, result = %d, line:%d")    
    TRC_MSG(VADP_SHELL_MEDIAPLAYER_VADP_SHELL_MEDIAPLAYER_LIST_SRV_CALLBACK,"[SHELL][MP][ADP] list_srv_callback result = %d, cur_index = %d, artwork_index = %d, line:%d")    
    TRC_MSG(VADP_SHELL_MEDIAPLAYER_LIST_SRV_CALLBACK_FAIL_1,"[SHELL][MP][ADP] list_srv_callback : state not loading, line:%d")
    TRC_MSG(VADP_SHELL_MEDIAPLAYER_LIST_SRV_CALLBACK_OK,"[SHELL][MP][ADP] list_srv_callback : try to decode(%d), line:%d")
    TRC_MSG(VADP_SHELL_MEDIAPLAYER_ENGINE_CB_DECODE_FAIL,"[SHELL][MP][ADP] decode fail, line:%d")
    TRC_MSG(VADP_SHELL_MEDIAPLAYER_GDI_DECODE_CB_HANDLE_ERROR,"[SHELL][MP][ADP] handle error, line:%d")
    TRC_MSG(VADP_SHELL_MEDIAPLAYER_GDI_DECODE_CB_OK,"[SHELL][MP][ADP] decode success, line:%d")
    TRC_MSG(VADP_SHELL_MEDIAPLAYER_GDI_DECODE_CB_FAIL,"[SHELL][MP][ADP] decode fail, line:%d ")
    TRC_MSG(VADP_SHELL_MEDIAPLAYER_FAIL_TO_GET_MEDIA_ID, "[SHELL][MP][ADP] fail to get id, line:%d ")
    TRC_MSG(VADP_SHELL_MEDIAPLAYER_FAIL_TO_GET_DETAILS, "[SHELL][MP][ADP] fail to get details, line:%d ")

    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_ONINIT,"[SHELL][MP] onInit()")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_ONDEINIT,"[SHELL][MP] onDeinit()")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_ONINITVIEW,"[SHELL][MP] onInitView()")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_ONDEINITVIEW,"[SHELL][MP] onDeinitView()")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_ONENTERVIEW,"[SHELL][MP] onEnterView, count:%d, countM:%d, hightlight:%d, state:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_ONEXITVIEW,"[SHELL][MP] onExitView()")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_ONSWITCHVIEW,"[SHELL][MP] onSwitchView() from %d to %d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_ONFINISHSWITCHVIEW,"[SHELL][MP] onFinishSwitchView(%d,%d)")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_CELL_ONINIT,"[SHELL][MP] Cell::onInit(%d,%d)")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_CELL_ONDEINIT,"[SHELL][MP] Cell::onDeinit(%d,%d)")    
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_ONBUTTONCLICK,"[SHELL][MP] onButtonClick, id:%d, state:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_ONPLAYERCALLBACK,"[SHELL][MP] onPlayerCallback, type:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_ONSTATUSCHANGED,"[SHELL][MP] onStatusChanged, state:%d , pstate:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_ONMEDIACHANGED,"[SHELL][MP] onMediaChanged, state:%d , hightlight:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_ONPLAYEND,"[SHELL][MP] onPlayEnd: mode:%d")
    TRC_MSG(VAPP_SHELL_MEDIAPLAYER_ONLISTEND,"[SHELL][MP] onListEnd: mode:%d")

    /* Shell base */
    TRC_MSG(VAPP_SHELL_BASE_HIDE_SHORTCUT,              "[SHELL][BASE] %d. hide shortcut=%d")
    TRC_MSG(VAPP_SHELL_BASE_GET_SHORTCUT_SIZE,          "[SHELL][BASE] get shortcut size: width=%d, height=%d")
    TRC_MSG(VAPP_SHELL_BASE_UPDATE_CONTENT,             "[SHELL][BASE] VappShellWheelCell::updateCell")
    TRC_MSG(VAPP_SHELL_BASE_UPDATE_CELL,                "[SHELL][BASE] %d.update cell!!")
    TRC_MSG(VAPP_SHELL_BASE_ON_TAP,                     "[SHELL][BASE] VappShellWheelMenu::onTap=%d")
    TRC_MSG(VAPP_SHELL_BASE_LIFE_CYCLE,                 "[SHELL][BASE] app's life cycle=%d")
    TRC_MSG(VAPP_SHELL_BASE_REG_DEF_PAGE_ACT,           "[SHELL][BASE] VappShellPanel::regDefaultPageAct: obj=%d")
    TRC_MSG(VAPP_SHELL_BASE_DEREG_DEF_PAGE_ACT,         "[SHELL][BASE] VappShellPanel::deregDefaultPageAct: obj=%d")
    TRC_MSG(VAPP_SHELL_BASE_CANCEL_PAGE_ACT,            "[SHELL][BASE] VappShellPanel::cancelDefaultPageAct!!")
    TRC_MSG(VAPP_SHELL_BASE_ON_EXP_LIST,                "[SHELL][BASE] VappShellPanel::noDefaultPageAction: obj=%d")
    TRC_MSG(VAPP_SHELL_BASE_GET_ORDER,                  "[SHELL][BASE] get panel order==> array_idx=%d, panel_id=%d, order=%d, state=%d")
    TRC_MSG(VAPP_SHELL_BASE_DISPLAY_IND,                "[SHELL][BASE] display ind==> ind_idx=%d, ind_pos=%d")
    TRC_MSG(VAPP_SHELL_BASE_CREATE_IND_BAR,             "[SHELL][BASE] create ind bar, num=%d")
    TRC_MSG(VAPP_SHELL_BASE_SCR_KEY_EVENT,              "[SHELL][BASE] shell screen key event==>%d")
    TRC_MSG(VAPP_SHELL_BASE_IS_IN_HISTORY,              "[SHELL][BASE] shell is in history!!")
    TRC_MSG(VAPP_SHELL_BASE_CREATE_SWITCH_MENU,         "[SHELL][BASE] create wheel menu!!")
    TRC_MSG(VAPP_SHELL_BASE_CANCEL_PANEL_SWIPE,         "[SHELL][BASE] cancel panel swipe!!")
    TRC_MSG(VAPP_SHELL_BASE_CHANGE_ORDER,               "[SHELL][BASE] change order==>panel_id=%d, pre_pos=%d, cur_pos=%d")
    TRC_MSG(VAPP_SHELL_BASE_CLOSE_PANEL,                "[SHELL][BASE] close panel==>panel_id=%d, pre_pos=%d, cur_pos=%d")
    TRC_MSG(VAPP_SHELL_BASE_ADD_PANEL,                  "[SHELL][BASE] add panel==>panel_id=%d, state=%d, pos=%d")
    TRC_MSG(VAPP_SHELL_BASE_PANEL_SWIPE_FINISH,         "[SHELL][BASE] VappShellScr::onPageSwitchFinish!!")
    TRC_MSG(VAPP_SHELL_BASE_PANEL_START_SWIPE,          "[SHELL][BASE] shell start to swipe panel!!")
    TRC_MSG(VAPP_SHELL_BASE_PANEL_IS_SELECT,            "[SHELL][BASE] %d. page is selected!!")
    TRC_MSG(VAPP_SHELL_BASE_TRIGGER_SWIPE_PANEL,        "[SHELL][BASE] trigger swipe panel to==>%d")
    TRC_MSG(VAPP_SHELL_BASE_IS_ACTIVE,                  "[SHELL][BASE] is panel active==>%d")
    TRC_MSG(VAPP_SHELL_BASE_CREATE_CELL,                "[SHELL][BASE] create cell==>num=%d, sub_cell=%d")
    TRC_MSG(VAPP_SHELL_BASE_CLOSE_CELL,                 "[SHELL][BASE] close cell==>num=%d, sub_cell=%d")
    TRC_MSG(VAPP_SHELL_BASE_MENU_KEY_EVENT,             "[SHELL][BASE] wheel menu key events===>%d")

    /* Shell Settings start */
    TRC_MSG(VAPP_SHELL_SETTINGS_ONINIT,  "[SHELL][SETTINGS]onInit()")
    TRC_MSG(VAPP_SHELL_SETTINGS_GET_INDEX_BY_MODE, "[SHELL][SETTINGS]getIndexByMode(): mode=%d, index=%d")
    TRC_MSG(VAPP_SHELL_SETTINGS_RADIO_SELECTED, "[SHELL][SETTINGS]MakeCustomData(): id=%d, selected=%d")	
    TRC_MSG(VAPP_SHELL_SETTINGS_SWITCHCALLBACK, "[SHELL][SETTINGS]onSwitchCallback(): id=%d, result=%d, visual=%d")
    TRC_MSG(VAPP_SHELL_SETTINGS_UPDATEMENU_STAGE, "[SHELL][SETTINGS]updateMenuStatus(): state=%d")
    TRC_MSG(VAPP_SHELL_SETTINGS_BTN_CALLBACK, "[SHELL][SETTINGS]cellButtonCallback(): id=%d")
    TRC_MSG(VAPP_SHELL_SETTINGS_OPTION_LIST_CALLBACK, "[SHELL][SETTINGS]cellOptionListCallback():id=%d,index=%d")
    TRC_MSG(VAPP_SHELL_SETTINGS_BTN_SWITCH_CALLBACK, "[SHELL][SETTINGS]cellSwitchButtonCallback():id=%d,status=%d")
    TRC_MSG(VAPP_SHELL_SETTINGS_BTN_SWITCH_BT, "[SHELL][SETTINGS]cellSwitchButtonCallback():BT,status=%d")
    TRC_MSG(VAPP_SHELL_SETTINGS_BTN_SWITCH_WIFI, "[SHELL][SETTINGS]cellSwitchButtonCallback():WiFI,status=%d")
    TRC_MSG(VAPP_SHELL_SETTINGS_BTN_SWITCH_FLIGHTMODE, "[SHELL][SETTINGS]cellSwitchButtonCallback():FlightMode,status=%d")

    TRC_MSG(VAPP_SHELL_SETTINGS_CMD_POPUP_CALLBACK, "[SHELL][SETTINGS]onCommandPopCallback(): id=%d")
    TRC_MSG(VAPP_SHELL_SETTINGS_PROFILE_SEL, "[SHELL][SETTINGS]onProfileSelection(): selIndex=%d")
    TRC_MSG(VAPP_SHELL_SETTINGS_LANG_SEL, "[SHELL][SETTINGS]onLanguageSelection(): selIndex=%d")
    TRC_MSG(VAPP_SHELL_SETTINGS_AUTOLOCK_SEL, "[SHELL][SETTINGS]onAutoLockSelection(): selIndex=%d")

    TRC_MSG(VAPP_SHELL_SETTINGS_SET_LEVEL, "[SHELL][SETTINGS]onLevelClick(): level=%d")
    TRC_MSG(VAPP_SHELL_SETTINGS_GET_BL, "[SHELL][SETTINGS]showBrightnessScr(): level=%d")

	TRC_MSG(VAPP_SHELL_SETTINGS_EVT_HANDLR, "[SHELL][SETTINGS]evtHandler(): evt_id=%d")
	TRC_MSG(VAPP_SHELL_SETTINGS_RET_EVT_HANDLR, "[SHELL][SETTINGS]regEvtHdlr()")
	TRC_MSG(VAPP_SHELL_SETTINGS_UNREG_EVT_HANDLR, "[SHELL][SETTINGS]unregEvtHdlr()")
	
	TRC_MSG(VAPP_SHELL_SETTINGS_SWITCH_WIFI, "[SHELL][SETTINGS]switchWlan(), %d")
	TRC_MSG(VAPP_SHELL_SETTINGS_WIFI_RESULT, "[SHELL][SETTINGS]onSwitchWlanResult(), state=%d, result=%d")
	TRC_MSG(VAPP_SHELL_SETTINGS_WIFI_ON, "[SHELL][SETTINGS]onSwitchWlanResult(), ON result=%d")
	TRC_MSG(VAPP_SHELL_SETTINGS_WIFI_OFF, "[SHELL][SETTINGS]onSwitchWlanResult(), OFF, result=%d")
	TRC_MSG(VAPP_SHELL_SETTINGS_WIFI_MENU, "[SHELL][SETTINGS]onSwitchWlanResult(), MENU, =%d")

	TRC_MSG(VAPP_SHELL_SETTINGS_ERROR, "[SHELL][SETTINGS]showErrorPopup()")
    /* Shell Settings end */

    /* Shell Recent Calls start */
    TRC_MSG(VAPP_SHELL_RC_ONINIT,            "[SHELL RC]onInit: m_currListIdx=%d")
    TRC_MSG(VAPP_SHELL_RC_ONDEINIT,          "[SHELL RC]onDeinit: m_currListIdx=%d")
    TRC_MSG(VAPP_SHELL_RC_ONINITVIEW,        "[SHELL RC]onInitView: m_currListIdx=%d")
    TRC_MSG(VAPP_SHELL_RC_ONDEINITVIEW,      "[SHELL RC]onDeinitView:")
    TRC_MSG(VAPP_SHELL_RC_ONENTERVIEW,       "[SHELL RC]onEnterView: m_currListIdx=%d")
    TRC_MSG(VAPP_SHELL_RC_ONEXITVIEW,        "[SHELL RC]onExitView: m_currListIdx=%d, exist_cause=%d, real_enter=%d")    
    TRC_MSG(VAPP_SHELL_RC_UPDATELIST,        "[SHELL RC]onUpdateList: m_currListIdx=%d, needUpdateList=%d")
    TRC_MSG(VAPP_SHELL_RC_CHANGELIST,        "[SHELL RC]onChangeList: m_currListIdx=%d, switchTabIdx=%d")
    TRC_MSG(VAPP_SHELL_RC_TABRCITEM,         "[SHELL RC]onTabRCItem: m_currListIdx=%d, ItemIdx=%d")
    TRC_MSG(VAPP_SHELL_RC_SHOWCMDPOPUP,      "[SHELL RC]ShowCmdPopup: is_phb=%d, has_name=%d, has_number=%d, is_voip=%d")
    TRC_MSG(VAPP_SHELL_RC_CLICKBTN,          "[SHELL RC]RspClickBtn: is_voip=%d, is_phb=%d, pressBtnId=%d")
    TRC_MSG(VAPP_SHELL_RC_TIMECHANGE,        "[SHELL RC]TimeChange: timeFlag=%d")
    TRC_MSG(VAPP_SHELL_RC_SRVSTATE,          "[SHELL RCDP]SrvState: m_srvState=%d")
    TRC_MSG(VAPP_SHELL_RC_PROCESSEVENT,      "[SHELL RCDP]ProcessSrvEvent: m_currListIdx=%d, log_type=%d, srvState=%d")
    TRC_MSG(VAPP_SHELL_RC_GETTEXT,           "[SHELL RCDP]GetText: itemIndex=%d, field=%d")
    TRC_MSG(VAPP_SHELL_RC_GETIMAGE,          "[SHELL RCDP]GetImage: itemIndex=%d, field=%d, logType=%d")
    TRC_MSG(VAPP_SHELL_RC_GETCOUNT,          "[SHELL RCDP]GetCount: currList=%d, count=%d")
    TRC_MSG(VAPP_SHELL_RC_TEST,              "[SHELL RCTEST]Flag1=%d, Flag2=%d, Flag3=%d, Flag4=%d")
    /* Shell Recent Calls end */
 
   /* Shell PageOrder start */
    TRC_MSG(VAPP_SHELL_ORDER_LOAD, 		      "[SHELL][ORDER]loadOrder(): dirty=%d")
    TRC_MSG(VAPP_SHELL_ORDER_LOAD_DETAIL,     "[SHELL][ORDER]loadOrder(): [%d,%d][%d,%d][%d,%d][%d,%d][%d,%d][%d,%d][%d,%d][%d,%d]")
    TRC_MSG(VAPP_SHELL_ORDER_GET_BY_INDEX,    "[SHELL][ORDER]getOrderById(): result=%d,id=%d, order=%d, state=%d")
    TRC_MSG(VAPP_SHELL_ORDER_GET_STATE, 	  "[SHELL][ORDER]getState(): index=%d, order=%d, state=%d")
    TRC_MSG(VAPP_SHELL_ORDER_SET_STATE, 	  "[SHELL][ORDER]setState(): index=%d, order=%d, state=%d")
    TRC_MSG(VAPP_SHELL_ORDER_SWAP, 			  "[SHELL][ORDER]swapOrder(): index1=%d, index2=%d")
    TRC_MSG(VAPP_SHELL_ORDER_SET_PANEL_STATE, "[SHELL][ORDER]setPanelState(): id=%d, state=%d")
    /* Shell PageOrder end */

    /* Shell shortcuts */
    TRC_MSG(VAPP_SHELL_SHCT_ONINIT,                     "[SHELL][SHCT] onInit()")
    TRC_MSG(VAPP_SHELL_SHCT_ONDEINIT,                   "[SHELL][SHCT] onDeinit()")
    TRC_MSG(VAPP_SHELL_SHCT_ONINITVIEW,                 "[SHELL][SHCT] onInitView()")
    TRC_MSG(VAPP_SHELL_SHCT_ONDEINITVIEW,               "[SHELL][SHCT] onDeinitView()")
    TRC_MSG(VAPP_SHELL_SHCT_ONENTERVIEW,                "[SHELL][SHCT] onEnterView(), m_operationState = %d")
    TRC_MSG(VAPP_SHELL_SHCT_ONEXITVIEW,                 "[SHELL][SHCT] onExitView()")
    TRC_MSG(VAPP_SHELL_SHCT_EMPTY_RECORD,               "[SHELL][SHCT] Init with empty record")
    TRC_MSG(VAPP_SHELL_SHCT_DISPLAY_POPUP_CONFIRM,      "[SHELL][SHCT] displayItemEditCnfScr()")
    TRC_MSG(VAPP_SHELL_SHCT_DISPLAY_CANDIDATE_LIST,     "[SHELL][SHCT] displayCandidateList()")
    TRC_MSG(VAPP_SHELL_SHCT_ENTRY_JAVA_SEL,             "[SHELL][SHCT] mmi_shct_entry_java_sel()")
    TRC_MSG(VAPP_SHELL_SHCT_CANDIDATE_SEL,              "[SHELL][SHCT] Candidate list select, m_operationState = %d")
    TRC_MSG(VAPP_SHELL_SHCT_CLOSE_CANDIDATE_LIST,       "[SHELL][SHCT] Close candidate list")
    TRC_MSG(VAPP_SHELL_SHCT_REMOVE_ITEMS,               "[SHELL][SHCT] VappShellShctScr::removeShctItem(), itemType=%d, itemId=%d")
    TRC_MSG(VAPP_SHELL_SHCT_SCRN_CFG_INFO,              "[SHELL][SHCT] Screen config infomation")
    TRC_MSG(VAPP_SHELL_SHCT_MAX_ITEM_NUM,               "[SHELL][SHCT] maxNumH=%d, maxNumV=%d")
    TRC_MSG(VAPP_SHELL_SHCT_SCRN_INFO,                  "[SHELL][SHCT] origin.x=%d, origin.y=%d, size.width=%d, size.height=%d")
    TRC_MSG(VAPP_SHELL_SHCT_ICON_INFO,                  "[SHELL][SHCT] point.x=%d, point.y=%d, iconSize.width=%d, iconSize.height=%d")
    TRC_MSG(VAPP_SHELL_SHCT_DISTANCE_INFO,              "[SHELL][SHCT] iconDistanceX=%d, iconDistanceY=%d, itemDistanceX=%d, itemDistanceY=%d")
    TRC_MSG(VAPP_SHELL_SHCT_TEXT_FONT_INFO,             "[SHELL][SHCT] fontSize.width=%d, fontSize.height=%d")
    TRC_MSG(VAPP_SHELL_SHCT_TEXT_BG_INFO,               "[SHELL][SHCT] textBgImgPos.x=%d, textBgImgPos.y=%d, textBgImgSize.width=%d, textBgImgSize.height=%d")
    TRC_MSG(VAPP_SHELL_SHCT_TEXT_INFO,                  "[SHELL][SHCT] textPos.x=%d, textPos.y=%d, textSize.width=%d, textSize.height=%d")
    TRC_MSG(VAPP_SHELL_SHCT_CHECK_DUPLACATE_NUM,        "[SHELL][SHCT] checkIsDuplicated(), number=%d")
    TRC_MSG(VAPP_SHELL_SHCT_ADD_SHCT_ITEM,              "[SHELL][SHCT] addShctItem(), orgin_type=%d, new_type=%d, orgin_id=%d, new_id=%d, index=%d")
    TRC_MSG(VAPP_SHELL_SHCT_REPLACE_SHCT_ITEM,          "[SHELL][SHCT] replaceShctItem(), orgin_type=%d, new_type=%d, orgin_id=%d, new_id=%d, index=%d")
    TRC_MSG(VAPP_SHELL_SHCT_REMOVE_SHCT_ITEM,           "[SHELL][SHCT] removeShctItem(), new_type=%d, new_id=%d, index=%d")
    TRC_MSG(VAPP_SHELL_SHCT_ON_TAP,                     "[SHELL][SHCT] onShctItemTap(), m_itemType=%d, m_itemId=%d, m_index=%d")
    TRC_MSG(VAPP_SHELL_SHCT_ON_LONG_PRESS,              "[SHELL][SHCT] onShctItemHold(), m_itemType=%d, m_itemId=%d, m_index=%d")
    TRC_MSG(VAPP_SHELL_SHCT_LAUNCH_APP,                 "[SHELL][SHCT] launchApp(), m_itemType=%d, m_itemId=%d, m_index=%d")
    TRC_MSG(VAPP_SHELL_SHCT_SAVE_NVRAM,                 "[SHELL][SHCT] saveToNvram(), m_itemType=%d, m_itemId=%d, m_index=%d")
    TRC_MSG(VAPP_SHELL_SHCT_PEN_INPUT_DOWN,             "[SHELL][SHCT] onPenInput(), Pen down")
    TRC_MSG(VAPP_SHELL_SHCT_PEN_INPUT_LONG_TAP,         "[SHELL][SHCT] onPenInput(), Pen long tap")
    TRC_MSG(VAPP_SHELL_SHCT_PEN_INPUT_UP,               "[SHELL][SHCT] onPenInput(), Pen up")
    TRC_MSG(VAPP_SHELL_SHCT_PEN_INPUT_ABORT,            "[SHELL][SHCT] onPenInput(), Pen abort")
    TRC_MSG(VAPP_SHELL_SHCT_PEN_INPUT_MOVE,             "[SHELL][SHCT] onPenInput(), Pen move")    
    TRC_MSG(VAPP_SHELL_SHCT_PEN_INPUT_MOVE_OUT,         "[SHELL][SHCT] onPenInput(), Pen move out")
    TRC_MSG(VAPP_SHELL_SHCT_ITEM_TAP_ZOOM_IN,           "[SHELL][SHCT] displayZoomAnimation(), TAP_ZOOM_IN")
    TRC_MSG(VAPP_SHELL_SHCT_ITEM_TAP_ZOOM_OUT,          "[SHELL][SHCT] displayZoomAnimation(), TAP_ZOOM_OUT")
    TRC_MSG(VAPP_SHELL_SHCT_ITEM_LONG_TAP_ZOOM_OUT,     "[SHELL][SHCT] displayZoomAnimation(), LONG_TAP_ZOOM_OUT")

    /* Shell favorite contact */
    TRC_MSG(VAPP_SHELL_FC_LIST_SET_READY,       "[SHELL][FC] fc list set ready = %d")
    TRC_MSG(VAPP_SHELL_FC_LIST_ONINIT,          "[SHELL][FC] fc list onInit")
    TRC_MSG(VAPP_SHELL_FC_LIST_ONDEINIT,        "[SHELL][FC] fc list onDeinit")
    TRC_MSG(VAPP_SHELL_FC_LIST_BUILD,           "[SHELL][FC] fc list build, focus = %d")
    TRC_MSG(VAPP_SHELL_FC_LIST_LISENER,         "[SHELL][FC] fc list lisener, event = %d")
    TRC_MSG(VAPP_SHELL_FC_LIST_SAVE,            "[SHELL][FC] fc list save, focus = %d")
    TRC_MSG(VAPP_SHELL_FC_SET,                  "[SHELL][FC] fc set, storeIndex = %d, id = %d") 
    TRC_MSG(VAPP_SHELL_FC_SET_IMG,              "[SHELL][FC] fc set image, id = %d")
    TRC_MSG(VAPP_SHELL_FC_FRAME_INIT,           "[SHELL][FC] fc frame init")
    TRC_MSG(VAPP_SHELL_FC_FRAME_DEINIT,         "[SHELL][FC] fc frame deinit")
    TRC_MSG(VAPP_SHELL_FC_FRAME_INIT_VIEW,      "[SHELL][FC] fc frame init view, state = %d")
    TRC_MSG(VAPP_SHELL_FC_FRAME_DEINIT_VIEW,    "[SHELL][FC] fc frame deinit view, state = %d")
    TRC_MSG(VAPP_SHELL_FC_FRAME_ENTER_VIEW,     "[SHELL][FC] fc frame enter view, state = %d, ready = %d")
    TRC_MSG(VAPP_SHELL_FC_FRAME_EXIT_VIEW,      "[SHELL][FC] fc frame exit view, state = %d, cause = %d")
    TRC_MSG(VAPP_SHELL_FC_MSG_SHOW_INFO,        "[SHELL][FC] fc msg show info, count = %d")
    TRC_MSG(VAPP_SHELL_FC_MSG_SHOW_WAITING,     "[SHELL][FC] fc msg show waiting icon")
    TRC_MSG(VAPP_SHELL_FC_MSG_REFRSH,           "[SHELL][FC] fc msg refresh, sync = %d")
    TRC_MSG(VAPP_SHELL_FC_MSG_REFRESH_NOTIFY,   "[SHELL][FC] fc msg refresh notify, msg type = %d, msg box = %d")
    TRC_MSG(VAPP_SHELL_FC_MSG_READY_NOTIFY,     "[SHELL][FC] fc msg ready notify, type = %d")
    TRC_MSG(VAPP_SHELL_FC_MSG_RELEASED,         "[SHELL][FC] fc msg list released")
    TRC_MSG(VAPP_SHELL_FC_MSG_UPDATE,           "[SHELL][FC] fc msg list update, size = %d")
    TRC_MSG(VAPP_SHELL_FC_MSG_GET_FINISHED,     "[SHELL][FC] fc msg get msg finished, result = %d")
    TRC_MSG(VAPP_SHELL_FC_CLOG_CHANGE_NOTIFY,   "[SHELL][FC] fc clog change notify, evt = %d")
    TRC_MSG(VAPP_SHELL_FC_CLOG_TAP_ITEM,        "[SHELL][FC] fc clog tap item, index = %d, hdlr = %d, result = %d")
    TRC_MSG(VAPP_SHELL_FC_CLOG_GET_CONTENT,     "[SHELL][FC] fc clog get content, sync = %d")
    TRC_MSG(VAPP_SHELL_FC_CLOG_CREATE_HDLR,     "[SHELL][FC] fc clog create hdlr, hdlr = %d")
    TRC_MSG(VAPP_SHELL_FC_CLOG_GET_DONE,        "[SHELL][FC] fc clog get done, hdlr = %d, count = %d")
    TRC_MSG(VAPP_SHELL_FC_CLOG_ONDEINIT,        "[SHELL][FC] fc clog deinit, hdlr = %d")
    TRC_MSG(VAPP_SHELL_FC_MAKE_CALL_CB,         "[SHELL][FC] fc make call cb")
    TRC_MSG(VAPP_SHELL_FC_MAKE_CALL,            "[SHELL][FC] fc make call, storeIndex = %d, id = %d")
    TRC_MSG(VAPP_SHELL_FC_SEND_MSG,             "[SHELL][FC] fc send msg")
    TRC_MSG(VAPP_SHELL_FC_SEND_EMAIL,           "[SHELL][FC] fc send email")
    TRC_MSG(VAPP_SHELL_FC_VIEW_MSG,             "[SEHLL][FC] fc view msg, id = %d, type = %d")    
    /* Shell favorite contact */

    /* Shell Image Viewer */
    TRC_MSG(VAPP_SHELLIV_CELL_UPDATE_IMAGE,     "[SHELL IV] VappShellIVCell::updateImage ret = %d")
    TRC_MSG(VAPP_SHELLIV_CELL_SET_IMAGEBUFFER,  "[SHELL IV] VappShellIVCell::setImageBuffer %d, m_imageWidth = %d, m_imageHeight = %d")
    TRC_MSG(VAPP_SHELLIV_MENU_CREATE_CELL,      "[SHELL IV] VappShellIVMenu::createCell index = %d")
    TRC_MSG(VAPP_SHELLIV_MENU_CLOSE_CELL,       "[SHELL IV] VappShellIVMenu::onCloseCell index = %d")
    TRC_MSG(VAPP_SHELLIV_MENU_AFTERUPDATE,      "[SHELL IV] VappShellIVMenu::onAfterUpdateCell")
    TRC_MSG(VAPP_SHELLIV_MENU_UPDATECELLIMAGE,  "[SHELL IV] VappShellIVMenu::updateCellImage ret = %d")
    TRC_MSG(VAPP_SHELLIV_MENU_DELETEFOCUS,      "[SHELL IV] VappShellIVMenu::deleteFocusItem, index = %d")
    TRC_MSG(VAPP_SHELLIV_PANEL_ONINIT,          "[SHELL IV] VappShellIVPanel::onInitView")
    TRC_MSG(VAPP_SHELLIV_PANEL_ONDEINIT,        "[SHELL IV] VappShellIVPanel::onDeinitView")
    TRC_MSG(VAPP_SHELLIV_PANEL_ONENTER,         "[SHELL IV] VappShellIVPanel::onEnterView")
    TRC_MSG(VAPP_SHELLIV_PANEL_ONEXIT,          "[SHELL IV] VappShellIVPanel::onExit")
    TRC_MSG(VAPP_SHELLIV_PANEL_LISTREADYCB,     "[SHELL IV] VappShellIVPanel::listReadyCallBack")
    TRC_MSG(VAPP_SHELLIV_PANEL_DELETEDONECB,    "[SHELL IV] VappShellIVPanel::deleteDoneCallBack")
    TRC_MSG(VAPP_SHELLIV_CLOSE_IMG,             "[SHELL IV] VappShellIVMenu::closeCellImage()->cell->setDefaultIcon() index = %d")
    TRC_MSG(VAPP_SHELLIV_FRAMEEFFECT,           "[SHELL IV] VappShellIVMenu::onFrameEffectFinished m_removedFrame = %x")
    TRC_MSG(VAPP_SHELLIV_RELOADLING,            "[SHELL IV] VappShellIVPanel::refreshingListCallBack")
    TRC_MSG(VADP_SHELLIV_DECODEIMG,             "[SHELL IV] decode image index= %d, mapped_index = %d")
    TRC_MSG(VADP_SHELLIV_NBDECODEIMG,           "[SHELL IV] NB decode image index= %d, mapped_index = %d")
    TRC_MSG(VADP_SHELLIV_DECODECB_RET,          "[SHELL IV] Non-Blocking decode cb, ret = %d")
    TRC_MSG(VADP_SHELLIV_DECODECB,              "[SHELL IV] Non-Blocking decode done, index = %d duration = %d")
    TRC_MSG(VADP_SHELLIV_ENTERIMGVIEWER,        "[SHELL IV] enter image viewer done, duration = %d")
    TRC_MSG(VADP_SHELLIV_RELOAD_FILELIST,       "[SHELL IV] reload file list, error_code = %d, file_list = %d")
    TRC_MSG(VADP_SHELLIV_REFRESH_LIST,          "[SHELL IV] refresh list [%d], focus index = %d")
    TRC_MSG(VADP_SHELLIV_RESULT,                "[SHELL IV] result [%d], result = %d")
    TRC_MSG(VADP_SHELLIV_FL_STATE,              "[SHELL IV] filelist state [%d], state = %d")

    /* Shell Message Viewer */
    TRC_MSG(VAPP_SHELL_MV_LISTSCREEN_SETISDISABLED                ,"[SHELL][MV] ListScreen::setIsDisabled, isDisabled = %d")
    TRC_MSG(VAPP_SHELL_MV_LISTSCREEN_ONLISTMENUTAP                ,"[SHELL][MV] ListScreen::onListMenuTap, index = %d")
    TRC_MSG(VAPP_SHELL_MV_LISTSCREEN_ONBACKBUTTONCLICK            ,"[SHELL][MV] ListScreen::onBackButtonClick")
    TRC_MSG(VAPP_SHELL_MV_LISTSCREEN_ONMSGLISTUPDATED             ,"[SHELL][MV] ListScreen::onMsgListUpdated")
    TRC_MSG(VAPP_SHELL_MV_LISTSCREEN_ONMSGLISTRELEASED            ,"[SHELL][MV] ListScreen::onMsgListReleased")
    TRC_MSG(VAPP_SHELL_MV_LISTSCREEN_ONGETMSGINFOFINISHED         ,"[SHELL][MV] ListScreen::onGetMsgInfoFinished")
    TRC_MSG(VAPP_SHELL_MV_NPFRAME_ONINIT                          ,"[SHELL][MV] NPFrame::onInit, this = %x")
    TRC_MSG(VAPP_SHELL_MV_NPFRAME_ONDEINIT                        ,"[SHELL][MV] NPFrame::onDeinit, this = %x")
    TRC_MSG(VAPP_SHELL_MV_NPFRAME_SETPAGEDATA                     ,"[SHELL][MV] NPFrame::setPageData, this = %x, msg_id = %d, pageIndex = %d")
    TRC_MSG(VAPP_SHELL_MV_NPFRAME_SETISREAD                       ,"[SHELL][MV] NPFrame::setIsRead, this = %x, m_loading = %d, isRead = %d, status = %d")
    TRC_MSG(VAPP_SHELL_MV_NPFRAME_UPDATEMSGINFO                   ,"[SHELL][MV] NPFrame::updateMsgInfo, this = %x, result = %d")
    TRC_MSG(VAPP_SHELL_MV_NPFRAME_ONGETMSGINFOFINISHED            ,"[SHELL][MV] NPFrame::onGetMsgInfoFinished, this = %x, error = %d")
    TRC_MSG(VAPP_SHELL_MV_NPFRAME_ONREADSMSDATAFINISHED           ,"[SHELL][MV] NPFrame::onReadSmsDataFinished, isValid = %d, this = %x, result = %d, status = %d")
    TRC_MSG(VAPP_SHELL_MV_MAINSCREEN_ONINIT                       ,"[SHELL][MV] MainScreen::onInit, this = %x")
    TRC_MSG(VAPP_SHELL_MV_MAINSCREEN_ONDEINIT                     ,"[SHELL][MV] MainScreen::onDeinit, this = %x")
    TRC_MSG(VAPP_SHELL_MV_MAINSCREEN_SETMSGINDEX                  ,"[SHELL][MV] MainScreen::setMsgIndex, index = %d")
    TRC_MSG(VAPP_SHELL_MV_MAINSCREEN_SETISFREEZE                  ,"[SHELL][MV] MainScreen::setIsFreeze, isFreeze = %d")
    TRC_MSG(VAPP_SHELL_MV_MAINSCREEN_SETISDISABLED                ,"[SHELL][MV] MainScreen::setIsDisabled, isDisabled = %d")
    TRC_MSG(VAPP_SHELL_MV_MAINSCREEN_SETFOCUSED                   ,"[SHELL][MV] MainScreen::setFocused, value = %d")
    TRC_MSG(VAPP_SHELL_MV_MAINSCREEN_DELETEMSG                    ,"[SHELL][MV] MainScreen::deleteMsg, msg_id = %d")
    TRC_MSG(VAPP_SHELL_MV_MAINSCREEN_UPDATEALL                    ,"[SHELL][MV] MainScreen::updateAll, isUpdating = %d, isOutofDate = %d")
    TRC_MSG(VAPP_SHELL_MV_MAINSCREEN_ONTOOLBARCLICK               ,"[SHELL][MV] MainScreen::onToolbarClick, Id = %d")
    TRC_MSG(VAPP_SHELL_MV_MAINSCREEN_ONCONFIRMPOPUPCLICKED        ,"[SHELL][MV] MainScreen::onConfirmPopupClicked, Id = %d")
    TRC_MSG(VAPP_SHELL_MV_MAINSCREEN_ONCONFIRMPOPUPSTATECHANGED   ,"[SHELL][MV] MainScreen::onConfirmPopupStateChanged, state = %d, m_deleteConfirmed = %d")
    TRC_MSG(VAPP_SHELL_MV_MAINSCREEN_ONMSGLISTUPDATED             ,"[SHELL][MV] MainScreen::onMsgListUpdated, list_size = %d, msg_type = %d")
    TRC_MSG(VAPP_SHELL_MV_MAINSCREEN_ONMSGLISTUPDATED_INFO        ,"[SHELL][MV] MainScreen::onMsgListUpdated, m_cacheMsgIndex = %d")
    TRC_MSG(VAPP_SHELL_MV_MAINSCREEN_ONMSGLISTRELEASED            ,"[SHELL][MV] MainScreen::onMsgListReleased")
    TRC_MSG(VAPP_SHELL_MV_MAINSCREEN_ONPAGEINDEXCHANGED           ,"[SHELL][MV] MainScreen::onPageIndexChanged, pageIndex = %d, cell = %x")
    TRC_MSG(VAPP_SHELL_MV_MAINSCREEN_ONNOTEPAPERTAP               ,"[SHELL][MV] MainScreen::onNotePaperTap, pageIndex = %d, cell = %x")
    TRC_MSG(VAPP_SHELL_MV_MAINSCREEN_ONNOTEPAPERPAGEDELETED       ,"[SHELL][MV] MainScreen::onNotePaperPageDeleted")
    TRC_MSG(VAPP_SHELL_MV_MAINSCREEN_SMSDELETEDCB                 ,"[SHELL][MV] MainScreen::smsDeletedCb, isValid = %d, result = %d")
    TRC_MSG(VAPP_SHELL_MV_MAINSCREEN_SCREENGROUPPROG              ,"[SHELL][MV] MainScreen::screenGroupProg, evt_id = %d")
    TRC_MSG(VAPP_SHELL_MV_MAINSCREEN_CREATENPFRAME                ,"[SHELL][MV] MainScreen::createNPFrame, page = %d, size = %d, isUpdating = %d")
    TRC_MSG(VAPP_SHELL_MV_MAINSCREEN_CLOSENPFRAME                 ,"[SHELL][MV] MainScreen::closeNPFrame, cell = %x")
    TRC_MSG(VAPP_SHELL_MV_MAINSCREEN_UPDATENPFRAME                ,"[SHELL][MV] MainScreen::updateNPFrame, page = %d, size = %d, cell = %x")
    TRC_MSG(VAPP_SHELL_MV_ONINIT                                  ,"[SHELL][MV] BASE::onInit, this = %x")
    TRC_MSG(VAPP_SHELL_MV_ONINITVIEW                              ,"[SHELL][MV] BASE::onInitView, this = %x")
    TRC_MSG(VAPP_SHELL_MV_ONENTERVIEW                             ,"[SHELL][MV] BASE::onEnterView, this = %x, m_viewMode = %d")
    TRC_MSG(VAPP_SHELL_MV_ONEXITVIEW                              ,"[SHELL][MV] BASE::onExitView, this = %x, cause = %d")
    TRC_MSG(VAPP_SHELL_MV_ONDEINITVIEW                            ,"[SHELL][MV] BASE::onDeinitView, this = %x")
    TRC_MSG(VAPP_SHELL_MV_ONDEINIT                                ,"[SHELL][MV] BASE::onDeinit, this = %x")
    TRC_MSG(VAPP_SHELL_MV_ONUPDATEVIEW                            ,"[SHELL][MV] BASE::onUpdateView, this = %x")
    TRC_MSG(VAPP_SHELL_MV_SETFOCUSED                              ,"[SHELL][MV] BASE::setFocused, value = %d")
    TRC_MSG(VAPP_SHELL_MV_ONSWITCHVIEW                            ,"[SHELL][MV] BASE::onSwitchView, m_viewMode = %d")
    TRC_MSG(VAPP_SHELL_MV_ONMSGLISTUPDATING                       ,"[SHELL][MV] BASE::onMsgListUpdating")
    TRC_MSG(VAPP_SHELL_MV_ONMSGLISTUPDATED                        ,"[SHELL][MV] BASE::onMsgListUpdated")
    TRC_MSG(VAPP_SHELL_MV_ONMSGLISTRELEASED                       ,"[SHELL][MV] BASE::onMsgListReleased")
    TRC_MSG(VAPP_SHELL_MV_ONUMSRVREFRESHNOTIFY                    ,"[SHELL][MV] BASE::onUmSrvReadyNotify, msg_type = %d, panelState = %d")

    TRC_MSG(VAPP_MSGDATAPROVIDER_ONINIT          ,"[SHELL][MV] DataProvider::onInit, this = %x")
    TRC_MSG(VAPP_MSGDATAPROVIDER_ONDEINIT        ,"[SHELL][MV] DataProvider::onDeinit, this = %x")
    TRC_MSG(VAPP_MSGDATAPROVIDER_PID             ,"[SHELL][MV] DataProvider::PID, PID = %d")
    TRC_MSG(VAPP_MSGDATAPROVIDER_GETMSGNUM       ,"[SHELL][MV] DataProvider::getMsgNum, this = %x, m_PID = %d, m_isAuto = %d")
    TRC_MSG(VAPP_MSGDATAPROVIDER_GETMSGLIST      ,"[SHELL][MV] DataProvider::getMsgList, this = %x, result = %d")
    TRC_MSG(VAPP_MSGDATAPROVIDER_GETMSGINFO      ,"[SHELL][MV] DataProvider::getMsgInfo, this = %x, result = %d")
    TRC_MSG(VAPP_MSGDATAPROVIDER_GETTHREADLIST   ,"[SHELL][MV] DataProvider::getThreadList, this = %x, result = %d")
    TRC_MSG(VAPP_MSGDATAPROVIDER_GETTHREADINFO   ,"[SHELL][MV] DataProvider::getThreadInfo, this = %x, result = %d")
    TRC_MSG(VAPP_MSGDATAPROVIDER_CANCELPROCESS   ,"[SHELL][MV] DataProvider::cancelProcess, this = %x, m_PID = %d")
    TRC_MSG(VAPP_MSGDATAPROVIDER_GETMSGNUMCB     ,"[SHELL][MV] DataProvider::getMsgNumCb, isValid = %d, user_data = %x, PID = %d")
    TRC_MSG(VAPP_MSGDATAPROVIDER_GETMSGLISTCB    ,"[SHELL][MV] DataProvider::getMsgListCb, isValid = %d, user_data = %x, PID = %d")
    TRC_MSG(VAPP_MSGDATAPROVIDER_GETMSGINFOCB    ,"[SHELL][MV] DataProvider::getMsgInfoCb, isValid = %d, user_data = %x, PID = %d")
    TRC_MSG(VAPP_MSGDATAPROVIDER_GETTHREADLISTCB ,"[SHELL][MV] DataProvider::getThreadListCb, isValid = %d, user_data = %x, PID = %d")
    TRC_MSG(VAPP_MSGDATAPROVIDER_GETTHREADINFOCB ,"[SHELL][MV] DataProvider::getThreadInfoCb, isValid = %d, user_data = %x, PID = %d")
    TRC_MSG(VAPP_BASELIST_ONINIT                 ,"[SHELL][MV] MsgList::onInit, this = %x")
    TRC_MSG(VAPP_BASELIST_ONDEINIT               ,"[SHELL][MV] MsgList::onDeinit, this = %x")
    TRC_MSG(VAPP_BASELIST_RELEASE                ,"[SHELL][MV] MsgList::release, this = %x, m_listCntxID = %d, fullRelease = %d")
    TRC_MSG(VAPP_BASELIST_LISTMGRNOTIFYCB        ,"[SHELL][MV] MsgList::listMgrNotifyCB, isValid = %d, event = %d, list_cid = %d, user_data = %x")
    TRC_MSG(VAPP_BASELIST_ONLISTMGRNOTIFY        ,"[SHELL][MV] MsgList::onListMgrNotify, this = %x, event = %d, list_cid = %d")
    TRC_MSG(VAPP_MSGLIST_FORCEUPDATE             ,"[SHELL][MV] MsgList::forceUpdate, this = %x, isUpdating = %d, isModified = %d")
    TRC_MSG(VAPP_MSGLIST_UPDATE                  ,"[SHELL][MV] MsgList::update, this = %x")
    TRC_MSG(VAPP_MSGLIST_ONGETMSGLISTFINISHED    ,"[SHELL][MV] MsgList::onGetMsgListFinished, this = %x, m_isModified = %d, error = %d")

    TRC_MSG(VAPP_NOTEPAPER_SHOWNEXTPAGE  ,"[SHELL][MV] NotePaper::showNextPage, m_flipForward = %d, m_flipFrameCount = %d")
    TRC_MSG(VAPP_NOTEPAPER_SHOWPREVPAGE  ,"[SHELL][MV] NotePaper::showPrevPage, m_flipForward = %d, m_flipFrameCount = %d")
    TRC_MSG(VAPP_NOTEPAPER_LOADALLFRAME  ,"[SHELL][MV] NotePaper::loadFrame, isLoadAllFrame = %d")
    TRC_MSG(VAPP_NOTEPAPER_UPDATETOPAGE  ,"[SHELL][MV] NotePaper::updateToPage, pageIndex = %d")
    TRC_MSG(VAPP_NOTEPAPER_DELETEPAGE    ,"[SHELL][MV] NotePaper::deletePage")
    TRC_MSG(VAPP_NOTEPAPER_ONDRAGEND     ,"[SHELL][MV] NotePaper::onDragEnd, xspeed = %d, yspeed = %d")
    TRC_MSG(VAPP_NOTEPAPER_ONTAP         ,"[SHELL][MV] NotePaper::onTap, isFlipping = %d, m_canTapInFlipping = %d")
    TRC_MSG(VAPP_NOTEPAPER_PENDOWN       ,"[SHELL][MV] NotePaper::onPenInput (Down)")
    TRC_MSG(VAPP_NOTEPAPER_PENUP         ,"[SHELL][MV] NotePaper::onPenInput (Up), m_maxMoveOffset = %d")
    TRC_MSG(VAPP_NOTEPAPER_ONPAGEDELETED ,"[SHELL][MV] NotePaper::onPageDeleted, isCompleted = %d")

    /* MEDIAWALL */
    TRC_MSG(VAPP_MEDIAWALL_RESTTIMER_TIMELINE_STOP,     "[MEDIAWALL] onResetTimerTick : m_rotateTimeline->stop()")
    TRC_MSG(VAPP_MEDIAWALL_RESTTIMER_TIMELINE_START,    "[MEDIAWALL] onResetTimerTick : m_rotateTimeline->start()")
    TRC_MSG(VAPP_MEDIAWALL_DECREASEIMTER_TICK,          "[MEDIAWALL] onDecreaseTimerTick m_rotateAngle = %d, m_cameraDistance = %d")
    TRC_MSG(VAPP_MEDIAWALL_ONDRAG,                      "[MEDIAWALL] onDrag xoffset = %d, m_lastXOffset = %d, m_rotateAngle = %d")
    TRC_MSG(VAPP_MEDIAWALL_ONDRAG_TIMELINE_START,       "[MEDIAWALL] onDrag : m_rotateTimeline->start() line[%d]")
    TRC_MSG(VAPP_MEDIAWALL_ONDRAGEND,                   "[MEDIAWALL] VappMediaWallMenu::onDragEnd, m_lastXOffset = %d")
    TRC_MSG(VAPP_MEDIAWALL_ONDRAGINFO_0,                "[MEDIAWALL] VappMediaWallMenu::onDrag speed = %d m_rotateAngle = %d")
    TRC_MSG(VAPP_MEDIAWALL_ONDRAGINFO_1,                "[MEDIAWALL] VappMediaWallMenu::onDrag[1] reverse m_rotateAngle = %d, m_cameraDistance = %d")
    TRC_MSG(VAPP_MEDIAWALL_ONDRAGINFO_2,                "[MEDIAWALL] VappMediaWallMenu::onDrag[2] positve m_rotateAngle = %d, m_cameraDistance = %d")
    TRC_MSG(VAPP_MEDIAWALL_ONDRAGINFO_3,                "[MEDIAWALL] VappMediaWallMenu::onDrag[3] negative m_rotateAngle = %d, m_cameraDistance = %d")
    TRC_MSG(VAPP_MEDIAWALL_ONVEIWSCROLLEND_1,           "[MEDIAWALL] onViewScrollEnd[%d] m_cameraDistance = %d, m_rotateAngle = %d, m_isScrolling = %d")
    TRC_MSG(VAPP_MEDIAWALL_ONVEIWSCROLLEND_2,           "[MEDIAWALL] onViewScrollEnd[%d] m_rotateTimeline->getIsEnabled() = %d")
    TRC_MSG(VAPP_MEDIAWALL_ROTATETIMELINESTOP,          "[MEDIAWALL] onRotateTimeLineStop[%d] isCompleted = %d, m_rotateAngle = %d, m_isScrolling = %d")
    TRC_MSG(VAPP_MEDIAWALL_SETROTATE,                   "[MEDIAWALL] setRotate")
    TRC_MSG(VAPP_MEDIAWALL_ROTATE_TIMER,                "[MEDIAWALL] Rotate onTimerTick state = %d")
    TRC_MSG(VADP_MEDIAWALL_MOTION_TILT,                 "[MEDIAWALL] vadp_mediawall_motion_tilt_hdlr direction = %d")

    /* World Clock*/
    TRC_MSG(VAPP_WORLDCLOCK_ON_INIT_SELECT_CITY,    "[WORLDCLOCK] VappSelectCityPage::oninit")
    TRC_MSG(VAPP_WORLDCLOCK_ON_INIT_TZ_POPUP,       "[WORLDCLOCK] VappWorldClockBubble::oninit")
    TRC_MSG(VAPP_WORLDCLOCK_ON_INIT_TZ_PANEL,       "[WORLDCLOCK] VappWorldClockTZPanel::oninit")
    TRC_MSG(VAPP_WORLDCLOCK_ON_INIT_FOREIGN_CITY,   "[WORLDCLOCK] VappWCFrnCityPanel::oninit")
    TRC_MSG(VAPP_WORLDCLOCK_ON_INIT_HOME_CITY,      "[WORLDCLOCK] VappWCHomeCityPanel::oninit")    
    TRC_MSG(VAPP_WORLDCLOCK_ON_INIT_MAPPAGE,        "[WORLDCLOCK] VappWCMapPage::oninit")
    TRC_MSG(VAPP_WORLDCLOCK_ON_INIT_FLOAT_CITY,     "[WORLDCLOCK] VappWCFloatCity::oninit")
    TRC_MSG(VAPP_WORLDCLOCK_SHOW_FLOATCITY,         "[WORLDCLOCK] VappWCMapPage::showFloatCity")
    TRC_MSG(VAPP_WORLDCLOCK_FANCY_MAP,              "[WORLDCLOCK] VappWCMapPage::fancyMapView")
    TRC_MSG(VAPP_WORLDCLOCK_MAPPAGE_SHOW_SELECTPAGE,"[WORLDCLOCK] VappWCMapPage::showSelectCityPage")
    
    /* CBS */
    TRC_MSG(TRC_VAPP_CBS_SIM_STATUS,                        "[CBS] VappCbsSettingFrom::fillSimTable() : Sim%d status = %d")
    TRC_MSG(TRC_VAPP_CBS_SUBSCRIBE_STATUS,                  "[CBS] VappCbsSettingForm::showForm() : Sim%d status = %d")
    TRC_MSG(TRC_VAPP_CBS_SUBSCRIBE_SUBMIT,                  "[CBS] VappCbsSettingPage::activationSwitched() : item_ptr = %d, item_id = %d, new_status = %d")
    TRC_MSG(TRC_VAPP_CBS_SUBSCRIBE_CALLBACK,                "[CBS] VappCbsSettingFrom::switchActivationCallback() : action_page = %d , result_status = %d")

    TRC_MSG(TRC_VAPP_CBS_CHANNEL_ENTRY_NORMAL,              "[CBS] VappCbsChannelListPage::showPage() : sim_id = %d, channel_amount = %d, is_reentry = %d")
    TRC_MSG(TRC_VAPP_CBS_CHANNEL_ENTRY_OPT,                 "[CBS] VappCbsChannelListPage::switchToOptPage() : sim_id = %d, channel_amount = %d, selection_amount = %d, is_reentry = %d")
    TRC_MSG(TRC_VAPP_CBS_CHANNEL_ENTRY_LIST,                 "[CBS] VappCbsChannelListPage::switchToListPage() : sim_id = %d, channel_amount = %d, selection_amount = %d, is_reentry = %d")
    TRC_MSG(TRC_VAPP_CBS_CHANNEL_ENTRY_PRE_DELETE,          "[CBS] VappCbsChannelListPage::deleteChannels() : channel_amount = %d, selection_amount = %d")
    TRC_MSG(TRC_VAPP_CBS_CHANNEL_IS_SELECT,                 "[CBS] VappCbsChannelListPage::deleteChannels() : channel_id = %d, selection_status = %d")
    TRC_MSG(TRC_VAPP_CBS_CHANNEL_DELETEING,                 "[CBS] VappCbsChannelListPage::channelDeleteCallback() : channel_id = %d, delete_result = %d")
    TRC_MSG(TRC_VAPP_CBS_CHANNEL_DELETE_RESULT,             "[CBS] VappCbsChannelListPage::channelDeleteCallback() : deleteing_number = %d, delete_result = %d")
    TRC_MSG(TRC_VAPP_CBS_CHANNEL_CHANGE_PROC,               "[CBS] VappCbsChannelListPage::channelChangeProc() : evt_id = %d, new_channel_amount = %d ")
    TRC_MSG(TRC_VAPP_CBS_CHANNEL_CHANGE_PROC_AFTER,               "[CBS] VappCbsChannelListPage::channelChangeProc() : evt_id = %d, new_channel_amount = %d ")


    TRC_MSG(TRC_VAPP_CBS_CHANNEL_EDITOR_ENTRY,              "[CBS] VappCbsChannelEditorPage::updateForm() : channel id = %d, is_new = %d")
    TRC_MSG(TRC_VAPP_CBS_CHANNEL_EDITOR_SUBMIT,             "[CBS] VappCbsChannelEditorPage::save(): channel id = %d, is_new = %d")
    TRC_MSG(TRC_VAPP_CBS_CHANNEL_EDITOR_CALLBACK,           "[CBS] VappCbsChannelEditorPage::channelActionCallback(): channel id = %d, is_new = %d, error cause = %d")
    TRC_MSG(TRC_VAPP_CBS_CHANNEL_EDITOR_CHANGE_PROC,        "[CBS] VappCbsChannelEditorPage::channelChangeProc() evt_id = %d, channel_id = %d ")


    TRC_MSG(TRC_VAPP_CBS_MSG_ENTRY,                         "[CBS]VappCbsMsgListPage::showList() : sim_id = %d, channel_id = %d, is_reentry = %d")
    TRC_MSG(TRC_VAPP_CBS_MSG_ENTRY_OPT_LIST,                "[CBS] VappCbsMsgListPage::switchToOptPage() : sim_id = %d, channel_id = %d, selection_amount = %d, is_reentry = %d")
    TRC_MSG(TRC_VAPP_CBS_MSG_ENTRY_VIEW_LIST,               "[CBS] VappCbsMsgListPage::switchToViewPage() : sim_id = %d, channel_id = %d, selection_amount = %d, is_reentry = %d")
    TRC_MSG(TRC_VAPP_CBS_MSG_PRE_DELETE,                    "[CBS] VappCbsMsgListPage::deleteSelected(): sim_id = %d,, msg_amount = %d, selection_amount = %d")
    TRC_MSG(TRC_VAPP_CBS_MSG_IS_SELECT,                     "[CBS] VappCbsMsgListPage::deleteSelected(): channel_id = %d, selection_status = %d")
    TRC_MSG(TRC_VAPP_CBS_MSG_DELETEING,                     "[CBS] VappCbsMsgListPage::deleteSelected(): channel_id = %d, delete_result = %d")
    TRC_MSG(TRC_VAPP_CBS_MSG_DELETE_RESULT,                 "[CBS] VappCbsMsgListPage::deleteSelected(): deleteing_number = %d, delete_result = %d")
    TRC_MSG(TRC_VAPP_CBS_MSG_MSG_CHANGE_PROC,               "[CBS] VappCbsMsgListPage::msgChangeProc() : evt_id = %d, msg_id = %d, sim_id = %d ")
    TRC_MSG(TRC_VAPP_CBS_MSG_CHANNEL_CHANGE_PROC,           "[CBS] VappCbsChannelListPage::channelChangeProc() evt_id = %d, channel_id = %d, sim_id = %d")

    TRC_MSG(TRC_VAPP_CBS_VIEWER_ENTRY,                      "[CBS]VappCbsViewerPage::updateContent() : sim_id = %d, msg_id = %d, content = %d")
    TRC_MSG(TRC_VAPP_CBS_VIEWER_PRE_DELETE,                 "[CBS] VappCbsViewerPage::deleteCurrMsg(): sim_id = %d, channel_id = %d, msg_id = %d")
    TRC_MSG(TRC_VAPP_CBS_VIEWER_DELETE_RESULT,              "[CBS] VappCbsViewerPage::deleteCurrMsg(): sim_id = %d, channel_id = %d, msg_id = %d, delete result = %d")
    TRC_MSG(TRC_VAPP_CBS_VIEWER_MSG_CHANGE_PROC,            "[CBS] VappCbsMsgListPage::msgChangeProc() : evt_id = %d, msg_id = %d , sim_id = %d")
    TRC_MSG(TRC_VAPP_CBS_VIEWER_CHANNEL_CHANGE_PROC,        "[CBS] VappCbsChannelListPage::channelChangeProc() evt_id = %d, channel_id = %d ")


    TRC_MSG(TRC_VAPP_CBS_NEW_MSG_VIEWER_ENTRY,              "[CBS]VappCbsNewMsgPopupViewer::setContent() : sim_id = %d, msg_id = %d, content_ptr = %d")
    TRC_MSG(TRC_VAPP_CBS_NEW_MSG_VIEWER_EXIT,               "[CBS] VappCbsNewMsgPopupViewer::onDeinit(): sim_id = %d, msg_id = %d, content_ptr = %d")
    TRC_MSG(TRC_VAPP_CBS_NEW_MSG_VIEWER_GET_SIM,            "[CBS] VappCbsNewMsgPopupViewer::getSim(): sim_id = %d")
    TRC_MSG(TRC_VAPP_CBS_NEW_MSG_VIEWER_GET_MSG,            "[CBS] VappCbsNewMsgPopupViewer::getMsg(): msg_id = %d")

    TRC_MSG(TRC_VAPP_CBS_NEW_MSG_MANAGER_INIT,              "[CBS] VappCbsNewMsgManager::onInit()")
    TRC_MSG(TRC_VAPP_CBS_NEW_MSG_MANAGER_ADD_UNIT,          "[CBS] VappCbsNewMsgManager::addOneUnit() : sim_id = %d, msg_id = %d ")
    TRC_MSG(TRC_VAPP_CBS_NEW_MSG_MANAGER_REMOVE_UNIT,       "[CBS] VappCbsNewMsgManager::removeOneUnit() : sim_id = %d, msg_id = %d ")
    TRC_MSG(TRC_VAPP_CBS_NEW_MSG_MANAGER_IS_MSG_BEING_VIEWED, "[CBS]VappCbsViewerPage::isMsgBeingViewed() : sim_id = %d, msg_id = %d")
    TRC_MSG(TRC_VAPP_CBS_NEW_MSG_MANAGER_GET_VIEWER_PTR,    "[CBS] VappCbsNewMsgManager::getViewer() : viwer_ptr = %d")
    TRC_MSG(TRC_VAPP_CBS_NEW_MSG_MANAGER_CLOSE_VIEWER,      "[CBS] VappCbsNewMsgManager::closeViewer() : is_viewer_present = %d")
    TRC_MSG(TRC_VAPP_CBS_NEW_MSG_MANAGER_NEW_MSG_PROC,      "[CBS] VappCbsNewMsgManager::cbsNewMsgProc() : msg = %d, sim_id = %d ")
    TRC_MSG(TRC_VAPP_CBS_NEW_MSG_MANAGER_MSG_DELETE_PROC,   "[CBS] VappCbsNewMsgManager::cbsMsgDeleteProc() : evt_id = %d, msg_id = %d, sim_id = %d")
    TRC_MSG(TRC_VAPP_CBS_NEW_MSG_MANAGER_CHANNEL_CHANGE_PROC, "[CBS] VappCbsNewMsgManager::channelChangeProc() evt_id = %d, channel_id = %d ")
    TRC_MSG(TRC_VAPP_CBS_NEW_MSG_MANAGER_MSG_VIEWED_PROC,   "[CBS] VappCbsNewMsgManager::msgViewedProc() : evt_id = %d, msg_id = %d, sim_id = %d ")
    TRC_MSG(TRC_VAPP_CBS_NEW_MSG_MANAGER_GS_CHANGE_PROC,    "[CBS] VappCbsNewMsgManager::msgChangeProc() : evt_id = %d, gs = %d ")
    TRC_MSG(TRC_VAPP_CBS_NEW_MSG_MANAGER_NOTIFY,            "[CBS] VappCbsNewMsgManager::cbsNmgrNotifyByApp() : msg_amount = %d, is_deferred = %d")
    TRC_MSG(TRC_VAPP_CBS_NEW_MSG_MANAGER_SHOW_FIRST_MSG,    "[CBS] VappCbsNewMsgManager::updateMsgBeingViewed() : msg_id = %d, sim_id = %d ")
    TRC_MSG(TRC_VAPP_CBS_NEW_MSG_MANAGER_MSG_FAILED,        "[CBS] VappCbsNewMsgManager::updateMsgBeingViewed() : msg_id = %d, sim_id = %d ")
    TRC_MSG(TRC_VAPP_CBS_NEW_MSG_MANAGER_START_PORC,        "[CBS] VappCbsNewMsgManager::startOneProc()")
    TRC_MSG(TRC_VAPP_CBS_NEW_MSG_MANAGER_END_PORC,          "[CBS] VappCbsNewMsgManager::endOneProc()")
    
    /* SAT */
    TRC_MSG(TRC_VAPP_SAT_INDICATION,                "[SAT] MMI_SAT_RECV_IND event id: %d")
    TRC_MSG(TRC_VAPP_SAT_USER_LAUNCH,               "[SAT] VAPP_SAT_USER_LAUNCH")
    TRC_MSG(TRC_VAPP_SAT_SIM_LAUNCH,                "[SAT] VAPP_SAT_SIM_LAUNCH")

    TRC_MSG(TRC_VAPP_SAT_APP_ONINIT,                "[SAT] VappSatApp::onInit")
    TRC_MSG(TRC_VAPP_SAT_APP_ONDEINIT,              "[SAT] VappSatApp::onDeinit")
    TRC_MSG(TRC_VAPP_SAT_APP_ONRUN,                 "[SAT] VappSatApp::onRun")
    TRC_MSG(TRC_VAPP_SAT_APP_SHOWSCREEN,            "[SAT] VappSatApp::showScreen, param act: %d, simId: %d, cmdType: %d")
    TRC_MSG(TRC_VAPP_SAT_APP_SHOWSCREEN_NEW,        "[SAT] VappSatApp::showScreen, create new screen")
    TRC_MSG(TRC_VAPP_SAT_APP_ONPROC,                "[SAT] VappSatApp::onProc event id: %d")
    TRC_MSG(TRC_VAPP_SAT_APP_ONRECVIND,             "[SAT] VappSatApp::onRecvInd event id: %d")
    TRC_MSG(TRC_VAPP_SAT_APP_ONRECVUCMIND,          "[SAT] VappSatApp::onRecvUcmInd SAT Call release indication")

    TRC_MSG(TRC_VAPP_SAT_MAIN_SCRN_ONINIT,          "[SAT] VappSatMainScrn::onInit")
    TRC_MSG(TRC_VAPP_SAT_MAIN_SCRN_ONDEINIT,        "[SAT] VappSatMainScrn::onDeinit")
    TRC_MSG(TRC_VAPP_SAT_MAIN_SCRN_ONRECVIND,       "[SAT] VappSatMainScrn::onRecvInd, event id: %d")
    TRC_MSG(TRC_VAPP_SAT_MAIN_SCRN_ONPROC,          "[SAT] VappSatMainScrn::onProc, event id: %d")
    TRC_MSG(TRC_VAPP_SAT_MAIN_SCRN_ON1STREADY,      "[SAT] VappSatMainScrn::on1stReady")
    TRC_MSG(TRC_VAPP_SAT_MAIN_SCRN_SHOWPAGE,        "[SAT] VappSatMainScrn::showPage, simId: %d, cmdType: %d")
    TRC_MSG(TRC_VAPP_SAT_MAIN_SCRN_POPUP,           "[SAT] VappSatMainScrn will popup...")

	TRC_MSG(TRC_VAPP_SAT_POPUP_SCRN_POPUP,			"[SAT] VappSatPopupScrn::showPopup")
	TRC_MSG(TRC_VAPP_SAT_POPUP_SCRN_ONRESETPHONE,	"[SAT] VappSatPopupScrn::onResetPhone")

    TRC_MSG(TRC_VAPP_SAT_BASE_PAGE_ONINIT,          "[SAT] VappSatBasePage::onInit, simId: %d, cmdType: %d")
    TRC_MSG(TRC_VAPP_SAT_BASE_PAGE_ONDEINIT,        "[SAT] VappSatBasePage::onDeinit, simId: %d, cmdType: %d")
    TRC_MSG(TRC_VAPP_SAT_BASE_PAGE_ONUPDATE,        "[SAT] VappSatBasePage::onUpdate")
    TRC_MSG(TRC_VAPP_SAT_BASE_PAGE_ONPROC,          "[SAT] VappSatBasePage::onProc, event id: %d")
    TRC_MSG(TRC_VAPP_SAT_BASE_PAGE_ONMERESPONSE,    "[SAT] VappSatBasePage::onMeResponse, type: %d")
    TRC_MSG(TRC_VAPP_SAT_BASE_PAGE_ONRESPONSE,      "[SAT] VappSatBasePage::onResponse")
    TRC_MSG(TRC_VAPP_SAT_BASE_PAGE_SHOWPLEASEWAIT,  "[SAT] VappSatBasePage::showPleaseWait")
    TRC_MSG(TRC_VAPP_SAT_BASE_PAGE_HIDEPLEASEWAIT,  "[SAT] VappSatBasePage::hidePleaseWait")
    TRC_MSG(TRC_VAPP_SAT_BASE_PAGE_SHOWPOPUP,       "[SAT] VappSatBasePage::showPopup")
    TRC_MSG(TRC_VAPP_SAT_BASE_PAGE_HIDEPOPUP,       "[SAT] VappSatBasePage::hidePopup")
    TRC_MSG(TRC_VAPP_SAT_BASE_PAGE_SETTITLEBAR,     "[SAT] VappSatBasePage::setTitleBar")
    TRC_MSG(TRC_VAPP_SAT_BASE_PAGE_TIMER_EXPIRY,    "[SAT] VappSatBasePage::onTimerExpiry")
    TRC_MSG(TRC_VAPP_SAT_BASE_PAGE_EXIT,            "[SAT] VappSatBasePage will exit...")
    TRC_MSG(TRC_VAPP_SAT_BASE_PAGE_ONRESETPHONE,    "[SAT] VappSatBasePage::onResetPhone")

    TRC_MSG(TRC_VAPP_SAT_VIEW_PAGE_ONINIT,          "[SAT] VappSatViewPage::onInit")
    TRC_MSG(TRC_VAPP_SAT_VIEW_PAGE_ONDEINIT,        "[SAT] VappSatViewPage::onDeinit")
    TRC_MSG(TRC_VAPP_SAT_VIEW_PAGE_ONPROC,          "[SAT] VappSatViewPage::onProc, event id: %d")
    TRC_MSG(TRC_VAPP_SAT_VIEW_PAGE_ONPROC_RET,      "[SAT] VappSatViewPage::onProc, ret: %d")
    TRC_MSG(TRC_VAPP_SAT_VIEW_PAGE_ONRESPONSE,      "[SAT] VappSatViewPage::onResponse, simId: %d, cmdType: %d, btnType: %d")
    TRC_MSG(TRC_VAPP_SAT_VIEW_PAGE_CMDPARSER,       "[SAT] VappSatViewPage::cmdParser, cmdType: %d")
    TRC_MSG(TRC_VAPP_SAT_VIEW_PAGE_EXIT,            "[SAT] VappSatViewPage will exit...")

    TRC_MSG(TRC_VAPP_SAT_EDITOR_PAGE_ONINIT,        "[SAT] VappSatEditorPage::onInit")
    TRC_MSG(TRC_VAPP_SAT_EDITOR_PAGE_ONDEINIT,      "[SAT] VappSatEditorPage::onDeinit")
    TRC_MSG(TRC_VAPP_SAT_EDITOR_PAGE_ONPROC,        "[SAT] VappSatEditorPage::onProc, event id: %d")
    TRC_MSG(TRC_VAPP_SAT_EDITOR_PAGE_ONPROC_RET,    "[SAT] VappSatEditorPage::onProc, ret: %d")
    TRC_MSG(TRC_VAPP_SAT_EDITOR_PAGE_ONRESPONS,     "[SAT] VappSatEditorPage::onResponse, simId: %d, cmdType: %d, btnType: %d")
    TRC_MSG(TRC_VAPP_SAT_EDITOR_PAGE_CMDPARSER,     "[SAT] VappSatEditorPage::cmdParser, cmdType: %d")
    TRC_MSG(TRC_VAPP_SAT_EDITOR_PAGE_EXIT,          "[SAT] VappSatEditorPage will exit...")

    TRC_MSG(TRC_VAPP_SAT_MENU_PAGE_CONSTRUCT,       "[SAT] VappSatMenuPage::VappSatMenuPage, main menu")
    TRC_MSG(TRC_VAPP_SAT_MENU_PAGE_ONINIT,          "[SAT] VappSatMenuPage::onInit")
    TRC_MSG(TRC_VAPP_SAT_MENU_PAGE_ONDEINIT,        "[SAT] VappSatMenuPage::onDeinit")
    TRC_MSG(TRC_VAPP_SAT_MENU_PAGE_SETIME,          "[SAT] VappSatMenuPage::setInputMethod, input type: %d")
    TRC_MSG(TRC_VAPP_SAT_MENU_PAGE_ONPROC,          "[SAT] VappSatMenuPage::onProc, event id: %d")
    TRC_MSG(TRC_VAPP_SAT_MENU_PAGE_ONPROC_RET,      "[SAT] VappSatMenuPage::onProc, ret: %d")
    TRC_MSG(TRC_VAPP_SAT_MENU_PAGE_ONRESPONS,       "[SAT] VappSatMenuPage::onResponse, simId: %d, cmdType: %d, btnType: %d, menu id: %d")
    TRC_MSG(TRC_VAPP_SAT_MENU_PAGE_CMDPARSER,       "[SAT] VappSatMenuPage::cmdParser, cmdType: %d")
    TRC_MSG(TRC_VAPP_SAT_MENU_PAGE_EXIT,            "[SAT] VappSatMenuPage will exit...")

END_TRACE_MAP(MOD_VAPP)

#ifdef __cplusplus
}
#endif

#endif /* __VADP_APP_TRC_H__ */

