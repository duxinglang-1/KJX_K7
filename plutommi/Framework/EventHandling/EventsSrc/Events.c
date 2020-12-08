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
 * Events.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for protocol/keypad/interrupt event handler .
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
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/*****************************************************************************
* Include                                                                     
*****************************************************************************/
#include "mmi_frm_prot.h"
#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif
#include "MMI_features.h"
#include "MMIDataType.h"
#include "mmi_frm_events.h"
#include "GlobalConstants.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"
#include "CustMenuRes.h"
#include "MMI_fw_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_fw_trc.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalResDef.h"
#include "string.h"
#include "stack_msgs.h"
#include "mmi_frm_input.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_history.h"
#include "wgui_draw_manager.h"
#include "mmi_frm_at_util_prot.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_inline_edit.h"
#include "gui_typedef.h"
#include "kal_public_api.h"
#include "Unicodexdcl.h"
#include "Kal_debug.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#define MMI_FRM_MAX_HILITE_HDLR      (5) 

/***************************************************************************** 
* Typedef 
*****************************************************************************/


/*****************************************************************************
* External Global Variables Declaration                                                              
*****************************************************************************/
extern mmi_frm_event_runtime_info_struct g_event_table_runtime_info[];
extern const mmi_frm_event_static_info_struct g_event_table_static_info[];



/*****************************************************************************
* Global Variables                                                              
*****************************************************************************/
U8 hintData[MAX_SUB_MENUS][MAX_SUB_MENU_HINT_SIZE];
U8 subMenuData[MAX_SUB_MENUS][MAX_SUB_MENU_SIZE];
PU8 subMenuDataPtrs[MAX_SUB_MENUS];
PU8 hintDataPtrs[MAX_SUB_MENUS];

/*****************************************************************************
* Local Variables                                                              
*****************************************************************************/
static U16 currParentID;
static U16 currHiliteID;
static mmi_frm_hilite_hdlr_struct mmi_frm_int_hilite_hdlr_table[MMI_FRM_MAX_HILITE_HDLR];
static mmi_frm_hint_hdlr_struct   mmi_frm_int_hint_hdlr_table[MAX_SUB_MENUS];
static U16 mmi_frm_int_hilite_hdlr_count = 0;
static U16 mmi_frm_int_hint_hdlr_count   = 0;
static MMI_BOOL event_initialized = MMI_FALSE;

/*****************************************************************************
* Extern Function Declaration                                                             
*****************************************************************************/
#ifdef __MMI_LCM_PRIMITIVE_FLUSH__    
    extern void mmi_frm_scr_mgm_deinit(void);
#endif /* __MMI_LCM_PRIMITIVE_FLUSH__ */

/*****************************************************************************
 * FUNCTION
 *  InitEvents
 * DESCRIPTION
 *  This function is used for initialize event handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitEvents(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U16 keyCode = 0;
    //U16 keyType = 0;
    U16 count   = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_EVENT_INIT_BEGIN);

    if (event_initialized)
    {
        return;
    }

    event_initialized = MMI_TRUE;
    mmi_frm_set_all_key_hdlr_null();

    currParentID      = 0;

    memset(g_event_table_runtime_info, 0, sizeof(mmi_frm_event_runtime_info_struct)*EVENT_TABLE_END);
    for(count = 0; count < EVENT_TABLE_END; count++)
    {
        memset(g_event_table_static_info[count].table, 0, sizeof(PseventInfo)*g_event_table_static_info[count].num_of_events);
    }

    memset(mmi_frm_int_hilite_hdlr_table, 0, sizeof(mmi_frm_int_hilite_hdlr_table));
    memset(mmi_frm_int_hint_hdlr_table, 0, sizeof(mmi_frm_int_hint_hdlr_table));

    for (count = 0; count < MAX_SUB_MENUS; count++)
    {
        subMenuDataPtrs[count] = subMenuData[count];
    }

    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EQ_SCREEN_SHOT_REQ_IND, (PsIntFuncPtr)mmi_frm_at_snapshot_req, MMI_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EQ_SCRNSIZE_QUERY_REQ_IND, (PsIntFuncPtr)mmi_pen_css_req, MMI_FALSE);
#if defined(__OP11_ATK__) || defined(__AUTO_ATK__)
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EQ_RAM_USAGE_REQ_IND, (PsIntFuncPtr)mmi_frm_at_ram_usage_ind_hdlr, MMI_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EQ_LAUNCH_APP_REQ_IND, (PsIntFuncPtr)mmi_frm_at_lauch_app_ind_hdlr, MMI_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EQ_APP_INFO_OUTPUT_REQ_IND, (PsIntFuncPtr)mmi_frm_at_app_info_output_ind_hdlr, MMI_FALSE);
#endif /* defined(__OP11_ATK__) || defined(__AUTO_ATK__) */
		mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EQ_KEYPAD_DETECT_IND, (PsIntFuncPtr)mmi_frm_key_handle, KAL_FALSE);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_EVENT_INIT_END);
}

/*****************************************************************************
 * FUNCTION
 *  DeInitFramework_KeyAndEventHandler
 * DESCRIPTION
 *  This function is used for Deinitialize key and event handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeInitFramework_KeyAndEventHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_EVENT_DEINIT_KEY_EVENT_BEGIN);
    mmi_frm_set_all_key_hdlr_null();
#ifdef __MMI_FRM_HISTORY__
    Deinit_active_screen_info();
#endif
    currParentID = 0;

    memset(g_event_table_runtime_info, 0, sizeof(mmi_frm_event_runtime_info_struct)*EVENT_TABLE_END);
    for(count = 0; count < EVENT_TABLE_END; count++)
    {
        memset(g_event_table_static_info[count].table, 0, sizeof(PseventInfo)*g_event_table_static_info[count].num_of_events);
    }

    memset(mmi_frm_int_hilite_hdlr_table, 0, sizeof(mmi_frm_int_hilite_hdlr_table));
    memset(mmi_frm_int_hint_hdlr_table, 0, sizeof(mmi_frm_int_hint_hdlr_table));

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_EVENT_DEINIT_KEY_EVENT_END);
}


/*****************************************************************************
 * FUNCTION
 *  DeInitFramework_History
 * DESCRIPTION
 *  This function is used for Deinitialize History.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeInitFramework_History(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_EVENT_DEINIT_HISTORY_BEGIN);



#ifdef __MMI_FRM_HISTORY__
    DinitHistory();
#endif
    DinitSubLCDHistory();
#ifdef __MMI_LCM_PRIMITIVE_FLUSH__    
    mmi_frm_scr_mgm_deinit();
#endif

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_EVENT_DEINIT_HISTORY_END);
}


/*****************************************************************************
 * FUNCTION
 *  DeInitFramework
 * DESCRIPTION
 *  This function is used for De-initialize history & event handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeInitFramework(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_EVENT_DEINIT_BEGIN);

    DeInitFramework_KeyAndEventHandler();
    DeInitFramework_History();
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_EVENT_DEINIT_END);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_default_proc
 * DESCRIPTION
 *  softkey default proc, it will send event to active screen first, if active screen
 *  do not process this event, we will exec default process
 * PARAMETERS
 *  evt              :[IN]  group event.
 * RETURNS
 *  MMI_RET_OK if success, else MMI_RET_ERR
 *****************************************************************************/
mmi_ret wgui_softkey_default_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* dispatch softkey event to active screen */
    ret = mmi_frm_send_event_to_active_screen(evt);

    /* default process */
    if(ret == MMI_RET_OK)
    {
        switch(evt->evt_id)
        {
            case EVT_ID_WGUI_LSK_CLICK:
            case EVT_ID_WGUI_CSK_CLICK:
                break;

            case EVT_ID_WGUI_RSK_CLICK:
                mmi_frm_scrn_close_active_id();
                break;
		            
            default:
                return MMI_RET_ERR;
        }
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ExecuteCurrHiliteHandler
 * DESCRIPTION
 *  This function finds out the current highlight menu item's handler and 
 *  executes it with clear KEY_RIGHT_ARROW key handler. Sometimes the sub menu
 *  items may be hidden and the sub menu item index will be different. This 
 *  function also handle this case.
 * PARAMETERS
 *  hiliteid        [IN]  ID of the item for which highlight handler needs to 
 *                        be executed.      
 * RETURNS
 *  void
 *****************************************************************************/
void ExecuteCurrHiliteHandler(S32 hiliteid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* To avoid the arrow left key to entry unexpected function, while other APP need they shall register again as BY request. */
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_EVENT_EXECURHILIHTE_HDLR, hiliteid);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    ExecuteCurrHiliteHandler_Ext(hiliteid);

}


/*****************************************************************************
 * FUNCTION
 *  ExecuteCurrHiliteHandler_Ext
 * DESCRIPTION
 *  This function finds out the current highlight menu item's handler and 
 *  executes it without clear KEY_RIGHT_ARROW key handler. Sometimes the sub 
 *  menu items may be hidden and the sub menu item index will be different.
 *  This function also handle this case.
 * PARAMETERS
 *  hiliteid        [IN]  ID of the item for which highlight handler needs to 
 *                        be executed.      
 * RETURNS
 *  void
 *****************************************************************************/
void ExecuteCurrHiliteHandler_Ext(S32 hiliteid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr currFuncPtr = NULL;
    S32 hiliteItemID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHiliteID = (U16) hiliteid;
    if (currParentID == 0)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_EVENT_EXECURHILIHTE_HDLR_ERROR);
        return;
    }

    /* check if menuitem is hidden */
    hiliteItemID = GetSeqItemId_Ext((U16) currParentID, (S16) hiliteid);    
    currFuncPtr = mmi_frm_get_hilite_hdlr((U16)hiliteItemID);
    
    if (currFuncPtr)
    {
        (*currFuncPtr) ();
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetCurrHiliteID
 * DESCRIPTION
 *  This function is used for query the current highlighted menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  Returns the index of the currently highlighted menu item
 *****************************************************************************/
U16 GetCurrHiliteID(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return currHiliteID;
}


/*****************************************************************************
 * FUNCTION
 *  SetHiliteHandler
 * DESCRIPTION
 *  This function is used for dynamcally register the handler for the menu item. If the 
 *  menu items are pre-definable, the applications use this function to dynamcally set 
 *  the highlight handlers. 
 *
 *  Note: (1) Please distinguish the function from RegisterHighlightHandler() 
 *        which is provided by UI layer. SetHiliteHandler() is for single 
 *        menu item; RegisterHighlightHandler() is global for all menu items.
 *        (2) When the screen switchs, the registred handler will invalid.
 * PARAMETERS
 *  itemid              [IN]  ID of the item for which highlight handler needs 
 *                            to be set.      
 *  hiliteFuncPtr       [IN]  Function to be executed whenever item with above
 *                            ID is highlighted.      
 * RETURNS
 *  void
 *****************************************************************************/
void SetHiliteHandler(U16 itemid, FuncPtr hiliteFuncPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_EVENT_SETCURHILIHTE_HDLR, itemid, hiliteFuncPtr);

    MMI_ASSERT(mmi_frm_int_hilite_hdlr_count < MMI_FRM_MAX_HILITE_HDLR);
        
    result = mmi_frm_binary_search((U32)itemid, (mmi_frm_pair_data_struct*)mmi_frm_int_hilite_hdlr_table, 
                                   (U32)mmi_frm_int_hilite_hdlr_count, &index);
            
    if (result == MMI_FALSE)
    {
        if (mmi_frm_int_hilite_hdlr_count != 0)
        {
            memmove(&mmi_frm_int_hilite_hdlr_table[index+1], &mmi_frm_int_hilite_hdlr_table[index], 
                     (mmi_frm_int_hilite_hdlr_count - index)*sizeof(mmi_frm_hilite_hdlr_struct));
        }
        mmi_frm_int_hilite_hdlr_count++;        
    }      

    mmi_frm_int_hilite_hdlr_table[index].menu_id     = itemid;
    mmi_frm_int_hilite_hdlr_table[index].hilite_hdlr = hiliteFuncPtr;  
 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_hilite_hdlr
 * DESCRIPTION
 *  This function is used for get the highlight handler for the menu item.
 * PARAMETERS
 *  menu_id          [IN]   ID of the menu item for which highlight handler needs 
 *                          to be get.
 * RETURNS
 *  The highlight handler.  
 *****************************************************************************/
FuncPtr mmi_frm_get_hilite_hdlr(U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index; 
    FuncPtr hilight_func;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
            
    /* Firstly search the dynamic table */
    if (mmi_frm_binary_search((U32)menu_id, (mmi_frm_pair_data_struct*)mmi_frm_int_hilite_hdlr_table, 
                                   (U32)mmi_frm_int_hilite_hdlr_count, &index))
    {
        return mmi_frm_int_hilite_hdlr_table[index].hilite_hdlr;
    }
    /* And then search the constant table. The constant table is generanted by resgen. */
    else if ((hilight_func = mmi_res_menu_get_hilite_hdlr(menu_id)) != NULL)
    {
        return hilight_func;
    }
    else
    {
        return NULL;
    }       

}


/*****************************************************************************
 * FUNCTION
 *  ClearHiliteHandler
 * DESCRIPTION
 *  This function is used for clear hilite func handlers for a particular menu item
 * PARAMETERS
 *  itemid      [IN] Item ID to for which one want to disable highlight handler.       
 * RETURNS
 *  void
 *****************************************************************************/
void ClearHiliteHandler(U16 itemid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_EVENT_CLRCURHILIHTE_HDLR, itemid);

    SetHiliteHandler(itemid, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  ConstructHintsList
 * DESCRIPTION
 *  Constructs Hint List for a static menu screen
 * PARAMETERS
 *  parentID        [IN]   The parent screen ID to construct enough hint list 
 *                         string array.     
 *  hintArray       [OUT]  The application fill the hint string into the output
 *                         array.     
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL mmi_frm_test_menu_item_hide(U16 menu_item_id);
void ConstructHintsList(U16 parentID, U8 **hintArray)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, noOfChild;
    U16 hiliteItemID[MAX_SUB_MENUS];
    U8 idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    noOfChild = (U8) GetNumOfChild(parentID);
    for (i = 0; i < noOfChild; i++)
    {
        hiliteItemID[i] = GetSeqItemId((U16) parentID, (S16) i);
        /* check if menuitem is hidden */
        if (!mmi_frm_test_menu_item_hide(hiliteItemID[i]))  /* the menuitem is not hidden */
        {
            if (mmi_frm_get_hint_hdlr(hiliteItemID[i]))
            {
                (*mmi_frm_get_hint_hdlr(hiliteItemID[i])) (idx);
                hintArray[idx] = hintData[idx];
                idx++;
            }
            else
            {
                hintArray[idx++] = NULL;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetHintHandler
 * DESCRIPTION
 *  This function is used for dynamcally register the handler for the menu item. The 
 *  registered should be responsible for providing hint content of one menu 
 *  item.
 *  Note:    When the screen switchs, the registred handler will invalid.
 * PARAMETERS
 *  itemid          [IN]   ID of the item for which hint handler needs to be set.
 *  hintFuncPtr     [IN]   Function to be executed whenever item with above ID 
 *                         is highlighted.     
 * RETURNS
 *  void
 *****************************************************************************/
void SetHintHandler(U16 itemid, FuncPtrShort hintFuncPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_EVENT_SETHINT_HDLR, itemid, hintFuncPtr);

    MMI_ASSERT(mmi_frm_int_hint_hdlr_count < MAX_SUB_MENUS);

    result = mmi_frm_binary_search((U32)itemid, (mmi_frm_pair_data_struct*)mmi_frm_int_hint_hdlr_table, 
                                   (U32)mmi_frm_int_hint_hdlr_count, &index);
            
    if (result == MMI_FALSE)
    {
        if (mmi_frm_int_hint_hdlr_count != 0)
        {
            memmove(&mmi_frm_int_hint_hdlr_table[index+1], &mmi_frm_int_hint_hdlr_table[index], 
                     (mmi_frm_int_hint_hdlr_count - index)*sizeof(mmi_frm_hint_hdlr_struct));
        }
        mmi_frm_int_hint_hdlr_count++;        
    }
    
    mmi_frm_int_hint_hdlr_table[index].menu_id     = itemid;
    mmi_frm_int_hint_hdlr_table[index].hint_hdlr   = hintFuncPtr;  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_hint_hdlr
 * DESCRIPTION
 *  This function is used for get the hint handler for the menu item.
 * PARAMETERS
 *  menu_id          [IN]   ID of the menu item for which hint handler needs 
 *                          to be get.
 * RETURNS
 *  The hint handler.  
 *****************************************************************************/
FuncPtrShort mmi_frm_get_hint_hdlr(U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    FuncPtrShort hint_func;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Firstly search the dynamic table */
    if (mmi_frm_binary_search((U32)menu_id, (mmi_frm_pair_data_struct*)mmi_frm_int_hint_hdlr_table, 
                              (U32)mmi_frm_int_hint_hdlr_count, &index))
    {
        return mmi_frm_int_hint_hdlr_table[index].hint_hdlr;
    }
    /* And then search the constant table. The constant table is generanted by resgen. */
    else if ((hint_func = mmi_res_menu_get_hint_hdlr(menu_id)) != NULL)
    {
        return hint_func;
    }
    else
    {
        return NULL;
    }       
}


/*****************************************************************************
 * FUNCTION
 *  ClearHintHandler
 * DESCRIPTION
 *  This is used to clear hint function handler associated with ItemID.
 * PARAMETERS
 *  itemid      [IN]  Item ID to for which one want to disable hint handler      
 * RETURNS
 *  void
 *****************************************************************************/
void ClearHintHandler(U16 itemid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_EVENT_CLRHINT_HDLR, itemid);

    SetHintHandler(itemid, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  SetParentHandler
 * DESCRIPTION
 *  This is used to set current parent menu item ID. After the application 
 *  set the parent menu item ID, the framework understand which menu is the 
 *  application in and handle the highlight and hint handler.
 * PARAMETERS
 *  parentID        [IN]  The parent menu item ID.      
 * RETURNS
 *  void
 *****************************************************************************/
void SetParentHandler(U16 parentID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currParentID = parentID;
}


/*****************************************************************************
 * FUNCTION
 *  GetParentHandler
 * DESCRIPTION
 *  This is used to get current parent menu item ID.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return the parent item ID.
 *****************************************************************************/
U16 GetParentHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return currParentID;
}


/*****************************************************************************
 * FUNCTION
 *  ClearInputEventHandler
 * DESCRIPTION
 *  This function is used for clear all input device handlers associated 
 *  with current screen.
 *  The input value should be one of following devices:
 *    MMI_DEVICE_KEY   Key events
 *    MMI_DEVICE_PEN   Pen events
 *    MMI_DEVICE_ALL   All of above device events.
 *
 * PARAMETERS
 *  device      [IN]        Which device handlers would be  cleared
 * RETURNS
 *  void
 *****************************************************************************/
void ClearInputEventHandler(U16 device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (device & MMI_DEVICE_KEY)
    {
        ClearAllKeyHandler();
    }

#ifdef  __MMI_TOUCH_SCREEN__
    if ( device & MMI_DEVICE_PEN )
    {
        wgui_clear_pen_handlers();
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  GetInputEventInfo
 * DESCRIPTION
 *  This function is used for get the information of the current input event
 *
 * PARAMETERS
 *  device      [IN]        Which device handlers would be  cleared
 * RETURNS
 *  void
 *****************************************************************************/
void GetInputEventInfo(U16 *device, U16 *keyCode, U16 *keyType, mmi_pen_event_type_enum *pen_type, mmi_pen_stroke_type_enum *stroke_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *device = MMI_DEVICE_NONE;

    GetkeyInfo(keyCode, keyType);
    if ((*keyCode) == KEY_INVALID)
    {
        *device = MMI_DEVICE_KEY;
    }

#ifdef  __MMI_TOUCH_SCREEN__
    mmi_pen_get_info(pen_type, stroke_type);
    if ((*pen_type) != MMI_PEN_EVENT_NONE || (*stroke_type) != MMI_PEN_STROKE_NONE)
    {
        *device = MMI_DEVICE_PEN;
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  MaskItems
 * DESCRIPTION
 *  This function is used for gets the items from the item array using the 
 *  given mask.  The data type of item should U16. 
 * PARAMETERS
 *  maskList        [IN/OUT]  The array of items.      
 *  noOfItems       [IN]      The number of the list.     
 *  maskingWord     [IN]      the mask word.   
 * RETURNS
 *  The number of item be marked.
 *****************************************************************************/
U8 MaskItems(U16 *maskList, U8 noOfItems, U32 maskingWord)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 0, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < noOfItems; i++)
        if (IsBitSet(maskingWord, i))
        {
            maskList[count++] = maskList[i];
        }
    return (U8) count;
}


/*****************************************************************************
 * FUNCTION
 *  MaskItemsU8
 * DESCRIPTION
 *  This function is used for gets the items from the item array using the 
 *  given mask.  The data type of item should U8. 
 * PARAMETERS
 *  maskList        [IN/OUT]  The array of items.      
 *  noOfItems       [IN]      The number of the list.  
 *  maskingWord     [IN]      the mask word.   
 * RETURNS
 *  The number of item be marked.
 *****************************************************************************/
U8 MaskItemsU8(U8 *maskList, U8 noOfItems, U32 maskingWord)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 0, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < noOfItems; i++)
        if (IsBitSet(maskingWord, i))
        {
            maskList[count++] = maskList[i];
        }
    return (U8) count;
}


/*****************************************************************************
 * FUNCTION
 *  MaskStringItems
 * DESCRIPTION
 *  This function is used for gets the strings from the string array 
 *  using the given mask.  The data type of item should the pointer to U8. 
 * PARAMETERS
 *  maskList        [IN/OUT]  The array of items.      
 *  noOfItems       [IN]      The number of the list.  
 *  maskingWord     [IN]      the mask word.      
 * RETURNS
 *  U8
 *****************************************************************************/
U8 MaskStringItems(U8 **maskList, U8 noOfItems, U32 maskingWord)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 0, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < noOfItems; i++)
        if (IsBitSet(maskingWord, i))
        {
            maskList[count++] = maskList[i];
        }
    return (U8) count;
}


/*****************************************************************************
 * FUNCTION
 *  ExecuteItemHiliteHandler
 * DESCRIPTION
 *  Execute the hilite handler of specified menu item
 * PARAMETERS
 *  hiliteItemID        [IN]  ID of the item for which highlight handler needs 
 *                            to be executed.       
 * RETURNS
 *  void
 *****************************************************************************/
void ExecuteItemHiliteHandler(U16 hiliteItemID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_get_hilite_hdlr(hiliteItemID))
    {
        (mmi_frm_get_hilite_hdlr(hiliteItemID))();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_binary_search
 * DESCRIPTION
 *  Performs a binary search of a sorted array.
 * PARAMETERS
 *  key             [IN]    Object to search for. 
 *  search_table    [IN]    Pointer to base of search data.
 *  num             [IN]    Number of elements. 
 *  index           [OUT]   index to an occurrence of key in the search_table
 *                          array. 
 * RETURNS
 *  If key is found, the function returns MMI_TRUE, else returns MMI_FALSE.
 *****************************************************************************/
MMI_BOOL mmi_frm_binary_search(U32 key, mmi_frm_pair_data_struct* search_table, U32 num, U32* index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 m =0, low = 0, high = num -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    while(low <= high)
    {
        m = (low + high)/2;

        if (key == search_table[m].key)
        {
            *index = m;
            return MMI_TRUE;
        }            
        else if (key > search_table[m].key)
        {
            low = m + 1;
        }
        else
        {
            high = m - 1;
        }
    }

    *index = low;
    return MMI_FALSE;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_binary_search_ex
 * DESCRIPTION
 *  Performs a binary search of a sorted array.
 *  find Max {search_table[index] <= key}
 * PARAMETERS
 *  key             [IN]    Object to search for. 
 *  search_table    [IN]    Pointer to base of search data.
 *  num             [IN]    Number of elements. 
 *  index           [OUT]   index to an occurrence of key in the search_table
 *                          array. 
 * RETURNS
 *  If key is found, the function returns MMI_TRUE, else returns MMI_FALSE.
 *****************************************************************************/
MMI_BOOL mmi_frm_binary_search_ex(U32 key, mmi_frm_pair_data_struct* search_table, U32 num, U32* index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 m =0, low = 0, high = num -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    while(low <= high)
    {
        m = (low + high)/2;

        if (key >= search_table[m].key && (m == num - 1 || key < search_table[m + 1].key))
        {
            *index = m;
            return MMI_TRUE;
        }            
        else if (key < search_table[m].key)
        {
            high = m - 1;            
        }
        else
        {
            low = m + 1;
        }
    }

    *index = low;
    return MMI_FALSE;    
}
