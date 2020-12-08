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
 *  FrameworkProt_Int.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Framework function declaration
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef FRAMEWORK_PROT_INT_H
#define FRAMEWORK_PROT_INT_H



/***************************************************************************** 
* Define
*****************************************************************************/

/* Queue global MACRO */
#define CIRCQ_NODE_SIZE sizeof(MYQUEUE)
#if defined(__MMI_DUAL_SIM_MASTER__)
	#define CIRCQ_NO_OF_NODES 130
#else
	#define CIRCQ_NO_OF_NODES 65 
#endif

/* history: interanl use macro */
#define MMI_HIST_DISABLE_DESTROY_HANDLER (0)
#define MMI_HIST_ENABLE_DESTROY_HANDLER  (1)

#define MMI_HIST_NODE_WAIT_TO_DESTROY   MMI_HIST_NODE_END
 
/* driver key event which is used for key & touch events */

#define DRV_WM_KEYPRESS                     (kbd_onekey_press)
#define DRV_WM_KEYRELEASE                   (kbd_onekey_release)
#define DRV_WM_KEYLONGPRESS                 (kbd_onekey_longpress)
#define DRV_WM_KEYREPEATED                  (kbd_onekey_repeated)
#define DRV_WM_KEYFULLPRESS                 (kbd_onekey_fullpress)
#define DRV_WM_ENABLE_TWOKEY_DETECTION      (kbd_twokey_detection_enable)
#define DRV_WM_ENABLE_THREEKEY_DETECTION    (kbd_threekey_detection_enable)
#define DRV_WM_DISABLE_MULTIKEY_DETECTION   (kbd_multikey_detection_disable)

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/* MMITask global data */
extern oslMsgqid mmi_ext_qid; 
extern MMI_BOOL g_keypad_flag;
extern drv_get_key_func keypad_ptr;     
extern U8 gInitAllAppFlag;         
extern U8 gInsertSimAppFlag;

/* History global data */
extern pBOOL IsBackHistory;

/* Event handler global data */
extern U16 maxProtocolEvent;
extern U16 usedProtocolEvent;

/* Events global data */
//extern MMI_BOOL g_has_switch_screen;

#ifdef __MMI_DUAL_SIM__
    extern U16 maxSlaveProtocolEvent;
    extern U16 usedSlaveProtocolEvent;
//    extern PseventInfo SlaveProtocolEventHandler[]; /* array size: MAX_SLAVE_PROTOCOL_EVENT */
#endif /* __MMI_DUAL_SIM__ */

/***************************************************************************** 
* Global Function
*****************************************************************************/

/* Timer global function */
extern void EvshedMMITimerHandler(void *dataPtr); 
extern void L4InitTimer(void);

/* history */
extern void mmi_frm_exec_scrn_destroy_hdlr(U16 scrn_id, void *arg_p);
extern S16 mmi_frm_exec_scrn_wait_to_destroy_hdlr(mmi_history_node_status_enum status);

/* sublcd history */
extern void GoBackSubLCDHistoryInt(void);

/* event handler */
extern void mmi_proc_inject_string(void * in);
extern void mmi_frm_reset_interrupt_event_context(void);

/* new key mechanism */

extern void mmi_frm_init_key_event(void);

/* qwerty module function for framework internal use */
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
typedef enum
{
    MMI_FRM_QWERTY_MODE_NONE,
    MMI_FRM_QWERTY_MODE_STANDARD,
    MMI_FRM_QWERTY_MODE_NUMBER
}mmi_frm_qwerty_keypad_mode_enum;

extern void mmi_frm_qwerty_init(void);
extern MMI_BOOL mmi_frm_qwerty_is_special_key(S16 mmi_key_code);
extern void mmi_frm_qwerty_update_key_status_pre_key_event(S16 mmi_key_code, S16 mmi_key_type);
extern void mmi_frm_qwerty_update_key_status_post_key_event(S16 mmi_key_code, S16 mmi_key_type);
extern S16 mmi_frm_qwerty_get_opposite_key_code(S16 mmi_key_code);
extern S16 mmi_frm_qwerty_convert_key_code(S16 mmi_key_code);
extern void mmi_frm_qwerty_get_translated_code_and_special_key_flag(S16 mmi_key_code, U16 *ucs2_value, U32 *special_key_flag);
extern void mmi_frm_qwerty_set_keypad_mode(mmi_frm_qwerty_keypad_mode_enum key_mode);
#endif

#endif /* FRAMEWORK_PROT_INT_H*/ 


