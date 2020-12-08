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
 * ManageCallMain.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   <file description>.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : Calls_Defs.h

   PURPOSE     : Call application 

   REMARKS     : nil

   AUTHOR      : Vandana Dhawan 

   DATE     : April 25,03

**************************************************************/

#ifndef _PIXTEL_MANAGECALLSMAIN_H
#define _PIXTEL_MANAGECALLSMAIN_H

extern void HighlightManageCalls(void);
extern void EntryCALLSETMain(void);
extern void EntryCALLSETCallTimeReminder(void);
extern void ExitCALLSETCallTimeReminder(void);
extern void EntryCALLSETCtrTime(void);
extern void ExitCALLSETCtrTime(void);

#if (0)
/* under construction !*/
#endif /* (0) */ 
extern void EntryCALLSETCUGMain(void);
extern void InitCallWaiting(void);
extern void InitCallForwarding(void);
extern void InitCallBarring(void);
extern void InitGroupListApp(void);
extern void InitLineSwitch(void);
extern void InitCallerId(void);
extern void HintCALLSETCallerID(U16);
extern void HintCALLSETLineSwitch(U16);
extern void HintCALLSETCallTimeReminder(U16);
extern void HintCALLSETCallTimeDisplay(U16);
extern void HintCALLSETAutoRedial(U16);
#ifdef __MMI_UCM_REJECT_BY_SMS__
extern void mmi_hint_rej_by_sms(U16 index);
#endif /* __MMI_UCM_REJECT_BY_SMS__ */
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
extern void mmi_callset_tap_cb(mmi_tap_type_enum tap_type,S32 index);
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */


#ifdef __MMI_SS_SHOW_CAUSE__
typedef struct
{
    U16 cause_number;
    U8 cause_string[80];
} SSCauseDisplayStruct;
#endif /* __MMI_SS_SHOW_CAUSE__ */ 

/* IP number begin */

#ifdef __IP_NUMBER__
extern void InitIPNumber(void);
extern void HighlightIPNumber(void);
extern void LoadIPNumbers(void);
extern void EntryScrViewIPNumbers(void);
extern void SetCurIPNumberIndex(S32 index);
extern void EntryScrIPNumberOptions(void);
extern void HighlightIPNumActivate(void);
extern void HighlightIPNumEdit(void);
extern void ActivateIPNumber(void);
extern void EntryScrIPNumberEdit(void);
extern void SetIPNumber(void);
extern void GetCurrIPNumber(U8 *num_str);
extern CHAR *GetCurrIPNumberUCS2(void);

#ifdef __MMI_DUAL_SIM_MASTER__
#ifdef __IP_NUMBER__
extern void HighlightCard2IPNumActivate(void);
extern void ActivateCard2IPNumber(void);
extern void GetCurrCard2IPNumber(U8 *num_str);
extern CHAR *GetCurrCard2IPNumberUCS2(void);
#endif /* __IP_NUMBER__ */
#endif/* __MMI_DUAL_SIM_MASTER__*/

#endif /* __IP_NUMBER__ */ 

#ifdef __MMI_CM_BLACK_LIST__

typedef enum
{
    MMI_BLACKLIST_RESULT_OK,
    MMI_BLACKLIST_RESULT_FULL, 
    MMI_BLACKLIST_RESULT_TOO_LONG,
    MMI_BLACKLIST_RESULT_EMPTY,
    MMI_BLACKLIST_RESULT_INVALID_FORMAT,
    MMI_BLACKLIST_RESULT_END_OF_ENUM
} mmi_blacklist_add_result_enum;

extern void InitBlackList(void);
extern void HighlightBlackList(void);
extern void HighlightBlackListMode(void);
#ifdef __MMI_UCM_AUTO_REJECT_NO_CALL_ID__
extern void HighlightBlackListUnknownNumberMode(void);
extern void HintBlackListUnknownNumberMode(U16 index);
extern void EntryScrBlackListUnknownNumberMode(void);
extern void SetBlackListUnknownNumberMode(pBOOL flag);
extern pBOOL GetBlackListUnknownNumberMode(void);
#endif /* __MMI_UCM_AUTO_REJECT_NO_CALL_ID__ */ 
extern void HighlightBlackListNum(void);
extern void HintBlackList(U16 index);
extern void HintBlackListMode(U16 index);
extern void EntryScrBlackList(void);
extern void EntryScrBlackListMode(void);

extern void EntryScrBlackListNum(void);
extern void ExitScrBlackListNum(void);
extern void EntryScrSetBlackListNumConfirm(void);
extern void GoToBlackList(void);
extern void SetBlackListMode(pBOOL flag);
extern pBOOL GetBlackListMode(void);
extern void SetBlackListNum(void);
extern mmi_blacklist_add_result_enum mmi_blacklist_add_number(PU8 number);
extern U16 mmi_blacklist_get_error_string_id_by_cause(mmi_blacklist_add_result_enum cause);
extern void LoadBlackListNum(void);
extern void SetCurrBlackListNumIndex(S32 index);
extern pBOOL IsBlackListNum(PU8 number);
extern pBOOL mmi_blacklist_is_blocked_number(PU8 number);
extern void mmi_blacklist_set_reject_all_mode(pBOOL mode);
extern pBOOL mmi_blacklist_get_reject_all_mode(void);
#endif /* __MMI_CM_BLACK_LIST__ */ 

#ifdef __MMI_CM_WHITE_LIST__
extern void InitWhiteList(void);
extern void HighlightWhiteList(void);
extern void HighlightWhiteListMode(void);
extern void HighlightWhiteListNum(void);
extern void HintWhiteList(U16 index);
extern void HintWhiteListMode(U16 index);
extern void EntryScrWhiteList(void);
extern void EntryScrWhiteListMode(void);
extern void EntryScrWhiteListNum(void);
extern void ExitScrWhiteListNum(void);
extern void mmi_white_list_entry_phone_password(void);
extern void mmi_white_list_soft_key_func(U8 *text, U8 *cursor, S32 length);
extern void mmi_white_list_verify_phone_password_req(void);
extern void mmi_white_list_save_confirm(void);
extern void GoToWhiteList(void);
extern void SetWhiteListMode(pBOOL flag);
extern pBOOL GetWhiteListMode(void);
extern void SetWhiteListNum(void);
extern void LoadWhiteListNum(void);
extern void SetCurrWhiteListNumIndex(S32 index);
extern pBOOL IsWhiteListNum(PU8 number);
extern pBOOL GetWhiteListMode(void);
extern pBOOL IsWhiteListNum(PU8 number);
extern pBOOL mmi_white_list_is_auto_answer_number(PU8 number);
#endif /* __MMI_CM_WHITE_LIST__ */ 

#endif /* _PIXTEL_MANAGECALLSMAIN_H */ 

