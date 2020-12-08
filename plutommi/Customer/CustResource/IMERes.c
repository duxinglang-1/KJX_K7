/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
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
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   IMEres.c.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements IME Resource for multi-load.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "IMERes.h"
#include "ImeGprot.h"
#include "SettingResDef.h"
#include "gui_virtual_keyboard_language_type.h"
#include "kal_non_specific_general_types.h"
#include "MMIDataType.h"

// __CUSTPACK_MULTIBIN     Terry   BEGIN

#if !defined  __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__
#define __MMI_ALPHABETIC_UPPERCASE_INPUT__
#define __MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__
#endif

#if defined(__MMI_T9__)
#if defined(__MMI_XT9__)

#else
#include "IMEResT9.h"
#endif
#elif defined(__MMI_ZI__)
#include "IMEResZi.h"
#else
const sIMELDBDetails mtk_gIMELDBArray[]={0};
#endif

const sIMEModeDetails mtk_gIMEModeArray[] =
{
#if defined(__MMI_T9_ENGLISH__)||defined(__MMI_ZI_PRC_ENGLISH__)||defined(__MMI_ITAP_ENGLISH__) || defined(__MMI_CSTAR_ENGLISH__)|| defined(__MMI_GB_ENGLISH__)
	/*Smart ABC*/
	#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_ABC,
   IMM_INPUT_TYPE_ENGLISH_SENTENCE_UPPERCASE|IMM_INPUT_TYPE_ENGLISH_SENTENCE | IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_ASCII_CHAR,
    STR_INPUT_METHOD_SMART_U_ABC,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_ABC,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
    "en-US",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_ABC,GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif


/*Smartabc*/
{
    IMM_INPUT_MODE_SMART_LOWERCASE_ABC,
    IMM_INPUT_TYPE_ENGLISH_SENTENCE | IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_ENGLISH_SENTENCE_LOWERCASE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_ASCII_CHAR,
    STR_INPUT_METHOD_SMART_L_ABC,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_ABC,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
    "en-US",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_ABC,GUI_VIRTUAL_KEYBOARD_ENGLISH,IMM_HANDWRITING_TYPE_LOWER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
/*SmartAbc*/
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ABC,
    IMM_INPUT_TYPE_ENGLISH_SENTENCE | IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_ASCII_CHAR,
    STR_INPUT_METHOD_SMART_FIRST_U_ABC,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_ABC,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
    "en-US",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_ABC,GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
#if defined(__MMI_IME_MAGIC_ONE__)
{
    IMM_INPUT_MODE_MAGIC_NUMBER,
    IMM_INPUT_TYPE_NONE,
    STR_INPUT_METHOD_SMART_L_ABC,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_ABC,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"en-US",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif

#endif

/*MultitapABC*/
/*WCSSneedmultitapABC,sowedon'tdisableitinQwertykeypad*/
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC,
    IMM_INPUT_TYPE_ENGLISH_SENTENCE | IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_EMAIL | IMM_INPUT_TYPE_URL | IMM_INPUT_TYPE_ASCII_CHAR,
    STR_INPUT_METHOD_MULTITAP_U_ABC,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_ABC,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"en-US",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC,GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
/*Multitapabc*/
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC,
    IMM_INPUT_TYPE_ENGLISH_SENTENCE | IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC  | IMM_INPUT_TYPE_QUICK_SEARCH | IMM_INPUT_TYPE_EMAIL | IMM_INPUT_TYPE_URL | IMM_INPUT_TYPE_ASCII_CHAR,
    STR_INPUT_METHOD_MULTITAP_L_ABC,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_ABC,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"en-US",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC,GUI_VIRTUAL_KEYBOARD_ENGLISH,IMM_HANDWRITING_TYPE_LOWER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ABC,
    IMM_INPUT_TYPE_ENGLISH_SENTENCE | IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_ASCII_CHAR,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_ABC,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_ABC,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"en-US",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC,GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif


#if defined(__MMI_T9_TR_CHINESE__) ||defined(__MMI_ZI_TR_CHINESE__) ||defined(__MMI_ITAP_TR_CHINESE__) ||defined(__MMI_CSTAR_TR_CHINESE__)||defined(__MMI_GB_TR_CHINESE__)
#if defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__) ||defined(__MMI_ZI_MULTITAP_PHONETIC_INPUT__) ||defined(__MMI_ITAP_MULTITAP_PHONETIC_INPUT__) ||defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__)||defined(__MMI_GB_MULTITAP_PHONETIC_INPUT__)
/*MultitapBopomofo*/
{
    IMM_INPUT_MODE_TR_MULTITAP_BOPOMO,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_BPMF,
    IME_LANG_ATTR_PHONETIC,
    IME_MODE_ATTR_MULTITAP  | IME_MODE_ATTR_EXTSPELL,
    IME_WRITING_LANG_ZHTW,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"zh-TW",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_TRUE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_BOPOMO,IMM_HANDWRITING_TYPE_TRADITIONAL_CHINESE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
/*MultitapBopomofoforquicksearch*/
{
    IMM_INPUT_MODE_QUICK_SEARCH_BOPOMO,
    IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_BPMF,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_MULTITAP  | IME_MODE_ATTR_EXTSPELL,
    IME_WRITING_LANG_ZHTW,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"zh-TW",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_TRUE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_BOPOMO,IMM_HANDWRITING_TYPE_TRADITIONAL_CHINESE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
#if defined(__MMI_T9_STROKE_INPUT__) ||defined(__MMI_ZI_STROKE_INPUT__) ||defined(__MMI_CSTAR_STROKE_INPUT__)||defined(__MMI_GB_STROKE_INPUT__)
/*TraditionalChineseStroke*/
{
    IMM_INPUT_MODE_TR_STROKE,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_TR_STROKE,
    IME_LANG_ATTR_STROKE,
    IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_ZHTW,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"zh-TW",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
#if defined(__MMI_IME_FTE_ENHANCE__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_TR_STROKE,IMM_HANDWRITING_TYPE_TRADITIONAL_CHINESE)
#else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL,IMM_HANDWRITING_TYPE_TRADITIONAL_CHINESE)
#endif
#endif/*__MMI_TOUCH_SCREEN__*/
},
/*TraditionalChineseStroke*/
{
    IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE,
    IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_TR_STROKE,
    IME_LANG_ATTR_STROKE,
    IME_MODE_ATTR_DIRECT,
    IME_WRITING_LANG_ZHTW,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"zh-TW",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
#if defined(__MMI_IME_FTE_ENHANCE__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_TR_STROKE,IMM_HANDWRITING_TYPE_TRADITIONAL_CHINESE)
#else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL,IMM_HANDWRITING_TYPE_TRADITIONAL_CHINESE)
#endif
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
#if(defined(__MMI_T9_SMART_PHONETIC_INPUT__)&&defined(__MMI_T9_AMB_BPMF_INPUT__)) ||defined(__MMI_ZI_SMART_PHONETIC_INPUT__) ||defined(__MMI_ITAP_SMART_PHONETIC_INPUT__)
/*SmartBopomofo*/
{
    IMM_INPUT_MODE_TR_BOPOMO,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_BPMF,
    IME_LANG_ATTR_PHONETIC,
    IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_ZHTW,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"zh-TW",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_TRUE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_BOPOMO,IMM_HANDWRITING_TYPE_TRADITIONAL_CHINESE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
#endif


#if defined(__MMI_ZI_HK_CHINESE__) ||defined(__MMI_T9_HK_CHINESE__)
#if defined(__MMI_ZI_STROKE_INPUT__) ||defined(__MMI_T9_STROKE_INPUT__)
/*CantoneseChineseStroke*/
{
    IMM_INPUT_MODE_HK_STROKE,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_HK_STROKE,
    IME_LANG_ATTR_STROKE,
    IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_ZHHK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"zh-HK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
/*CantoneseChineseStroke*/
{
    IMM_INPUT_MODE_QUICK_SEARCH_HK_STROKE,
    IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_HK_STROKE,
    IME_LANG_ATTR_STROKE,
    IME_MODE_ATTR_DIRECT,
    IME_WRITING_LANG_ZHHK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"zh-HK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_ZI_STROKE_INPUT__)*/
#endif/*defined(__MMI_ZI_HK_CHINESE__)*/


#if defined(__MMI_T9_SM_CHINESE__) ||defined(__MMI_ZI_SM_CHINESE__) ||defined(__MMI_ITAP_SM_CHINESE__) ||defined(__MMI_CSTAR_SM_CHINESE__)||defined(__MMI_GB_SM_CHINESE__)
#if defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__) ||defined(__MMI_ZI_MULTITAP_PHONETIC_INPUT__) ||defined(__MMI_ITAP_MULTITAP_PHONETIC_INPUT__) ||defined(__MMI_GB_MULTITAP_PHONETIC_INPUT__)|| \
((defined(__MMI_TOUCH_SCREEN__) ||defined(__MMI_QWERTY_KEYPAD_SUPPORT__))&&defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__) && !defined(__MMI_CSTAR_PHRASE_INPUT__))
/*MultitapPinyin*/
{
    IMM_INPUT_MODE_SM_MULTITAP_PINYIN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_PINYIN,
    IME_LANG_ATTR_PHONETIC,
    IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_ZHCN,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"zh-CN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_TRUE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_PINYIN,IMM_HANDWRITING_TYPE_SIMPLIFIED_CHINESE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
/*MultitapPinyinforquicksearch*/
{
    IMM_INPUT_MODE_QUICK_SEARCH_PINYIN,
    IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_PINYIN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_ZHCN,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"zh-CN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_TRUE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_PINYIN,IMM_HANDWRITING_TYPE_SIMPLIFIED_CHINESE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_T9_STROKE_INPUT__) ||defined(__MMI_ZI_STROKE_INPUT__) ||defined(__MMI_CSTAR_STROKE_INPUT__)||defined(__MMI_GB_STROKE_INPUT__)
/*SimplifiedChineseStroke*/
{
    IMM_INPUT_MODE_SM_STROKE,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SM_STROKE,
    IME_LANG_ATTR_STROKE,
    IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_ZHCN,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"zh-CN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
#if defined(__MMI_IME_FTE_ENHANCE__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_SM_STROKE,IMM_HANDWRITING_TYPE_SIMPLIFIED_CHINESE)
#else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL,IMM_HANDWRITING_TYPE_SIMPLIFIED_CHINESE)
#endif
#endif/*__MMI_TOUCH_SCREEN__*/
},
{
    IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE,
    IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_SM_STROKE,
    IME_LANG_ATTR_STROKE,
    IME_MODE_ATTR_DIRECT,
    IME_WRITING_LANG_ZHCN,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"zh-CN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
#if defined(__MMI_IME_FTE_ENHANCE__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_SM_STROKE,IMM_HANDWRITING_TYPE_SIMPLIFIED_CHINESE)
#else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL,IMM_HANDWRITING_TYPE_SIMPLIFIED_CHINESE)
#endif
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
#if defined(__MMI_T9_SMART_PHONETIC_INPUT__) ||defined(__MMI_ZI_SMART_PHONETIC_INPUT__) ||defined(__MMI_ITAP_SMART_PHONETIC_INPUT__) ||defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__)||defined(__MMI_GB_SMART_PHONETIC_INPUT__)
/*SmartPinyin*/
{
    IMM_INPUT_MODE_SM_PINYIN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_PINYIN,
    IME_LANG_ATTR_PHONETIC,
    IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_ZHCN,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"zh-CN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_TRUE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_PINYIN,IMM_HANDWRITING_TYPE_SIMPLIFIED_CHINESE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
#endif

#if defined(__MMI_GB_THAI__) || defined(__MMI_ZI_THAI__) ||defined(__MMI_T9_THAI__) ||defined(__MMI_CSTAR_THAI__)
{
    IMM_INPUT_MODE_SMART_THAI,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_THAI,
    IME_LANG_ATTR_ALPHABETIC  | IME_LANG_ATTR_MIXED_LANG_SUPPORT,
    IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_TH,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"th-TH",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_THAI,IMM_HANDWRITING_TYPE_THAI)
#else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_THAI,GUI_VIRTUAL_KEYBOARD_THAI,IMM_HANDWRITING_TYPE_THAI)
#endif
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
#if defined(__MMI_MULTITAP_THAI__)
{
    IMM_INPUT_MODE_MULTITAP_THAI,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_THAI,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_TH,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"th-TH",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_THAI,IMM_HANDWRITING_TYPE_THAI)
#else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_THAI,GUI_VIRTUAL_KEYBOARD_THAI,IMM_HANDWRITING_TYPE_THAI)
#endif
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif

#if defined(__MMI_ZI_HEBREW__) ||defined(__MMI_T9_HEBREW__) ||defined(__MMI_CSTAR_HEBREW__)||defined(__MMI_GB_HEBREW__)
{
    IMM_INPUT_MODE_SMART_HEBREW,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_HEBREW,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_HE,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"he-IL",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_HEBREW,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
#if defined(__MMI_MULTITAP_HEBREW__)
{
    IMM_INPUT_MODE_MULTITAP_HEBREW,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_HEBREW,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_HE,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"he-IL",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_HEBREW,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif

#if defined(__MMI_T9_POLISH__) ||defined(__MMI_ZI_POLISH__) ||defined(__MMI_CSTAR_POLISH__) ||defined(__MMI_GB_POLISH__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_POLISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_POLISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_PL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"pl-PL",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_POLISH,GUI_VIRTUAL_KEYBOARD_POLISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_POLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_POLISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_POLISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_PL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"pl-PL",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_POLISH,GUI_VIRTUAL_KEYBOARD_POLISH,IMM_HANDWRITING_TYPE_LOWER_CASE_POLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_POLISH,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_POLISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_PL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"pl-PL",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_POLISH,GUI_VIRTUAL_KEYBOARD_POLISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_POLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/

#endif

#if defined(__MMI_MULTITAP_POLISH__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
/*MultitapPOLISH*/
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_POLISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_POLISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_PL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"pl-PL",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_POLISH,GUI_VIRTUAL_KEYBOARD_POLISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_POLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
/*Multitappolish*/
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_POLISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_POLISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_PL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"pl-PL",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_POLISH,GUI_VIRTUAL_KEYBOARD_POLISH,IMM_HANDWRITING_TYPE_LOWER_CASE_POLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_POLISH,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_POLISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_PL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"pl-PL",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_POLISH,GUI_VIRTUAL_KEYBOARD_POLISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_POLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/

#endif

#if defined(__MMI_T9_SPANISH__) ||defined(__MMI_ZI_EU_SPANISH__) ||defined(__MMI_CSTAR_SPANISH__) ||defined(__MMI_GB_SPANISH__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_SPANISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_SPANISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
#if defined __MMI_LANG_SA_SPANISH__
    IME_WRITING_LANG_ESSA,
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    "es-SA",
#endif /* defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) */
#else
    IME_WRITING_LANG_ES,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"es-ES",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#endif
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_SPANISH,GUI_VIRTUAL_KEYBOARD_SPANISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_SPANISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_SPANISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_SPANISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
#if defined __MMI_LANG_SA_SPANISH__
    IME_WRITING_LANG_ESSA,
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    "es-SA",
#endif /* defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) */
#else
    IME_WRITING_LANG_ES,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"es-ES",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#endif     
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_SPANISH,GUI_VIRTUAL_KEYBOARD_SPANISH,IMM_HANDWRITING_TYPE_LOWER_CASE_SPANISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SPANISH,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_SPANISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
#if defined __MMI_LANG_SA_SPANISH__
    IME_WRITING_LANG_ESSA,
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    "es-SA",
#endif /* defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) */
#else
    IME_WRITING_LANG_ES,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"es-ES",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#endif       
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_SPANISH,GUI_VIRTUAL_KEYBOARD_SPANISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_SPANISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/

#endif
#if defined(__MMI_ZI_SA_SPANISH__)||defined(__MMI_GB_SA_SPANISH__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_SA_SPANISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_SA_SPANISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_ESSA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"es-SA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_SA_SPANISH,GUI_VIRTUAL_KEYBOARD_SPANISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_SPANISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_SA_SPANISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_SA_SPANISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_ESSA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"es-SA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_SA_SPANISH,GUI_VIRTUAL_KEYBOARD_SPANISH,IMM_HANDWRITING_TYPE_LOWER_CASE_SPANISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SA_SPANISH,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_SA_SPANISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_ESSA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"es-SA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_SA_SPANISH,GUI_VIRTUAL_KEYBOARD_SPANISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_SPANISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif
#if defined(__MMI_MULTITAP_SPANISH__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
/*MultitapSPANISH*/
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SPANISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_SPANISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
#if defined(__MMI_LANG_SA_SPANISH__)
    IME_WRITING_LANG_ESSA,
#else
    IME_WRITING_LANG_ES,
#endif
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
#if defined(__MMI_LANG_SA_SPANISH__)
"es-SA",
#else
"es-ES",
#endif
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_SPANISH,GUI_VIRTUAL_KEYBOARD_SPANISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_SPANISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
/*Multitapspanish*/
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SPANISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_SPANISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
#if defined(__MMI_LANG_SA_SPANISH__)
    IME_WRITING_LANG_ESSA,
#else
    IME_WRITING_LANG_ES,
#endif
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
#if defined(__MMI_LANG_SA_SPANISH__)
"es-SA",
#else
"es-ES",
#endif
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_SPANISH,GUI_VIRTUAL_KEYBOARD_SPANISH,IMM_HANDWRITING_TYPE_LOWER_CASE_SPANISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SPANISH,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_SPANISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
#if defined(__MMI_LANG_SA_SPANISH__)
    IME_WRITING_LANG_ESSA,
#else
    IME_WRITING_LANG_ES,
#endif
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
#if defined(__MMI_LANG_SA_SPANISH__)
"es-SA",
#else
"es-ES",
#endif
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_SPANISH,GUI_VIRTUAL_KEYBOARD_SPANISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_SPANISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/

#endif


#if defined(__MMI_T9_DANISH__) ||defined(__MMI_ZI_DANISH__) ||defined(__MMI_CSTAR_DANISH__) ||defined(__MMI_GB_DANISH__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_DANISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_DANISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_DA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"da-DK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_DANISH,GUI_VIRTUAL_KEYBOARD_DANISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_DANISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_DANISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_DANISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_DA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"da-DK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_DANISH,GUI_VIRTUAL_KEYBOARD_DANISH,IMM_HANDWRITING_TYPE_LOWER_CASE_DANISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_DANISH,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_DANISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_DA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"da-DK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_DANISH,GUI_VIRTUAL_KEYBOARD_DANISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_DANISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_DANISH__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
/*MultitapDANISH*/
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_DANISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_DANISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_DA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"da-DK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_DANISH,GUI_VIRTUAL_KEYBOARD_DANISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_DANISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
/*Multitapdanish*/
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_DANISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_DANISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_DA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"da-DK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_DANISH,GUI_VIRTUAL_KEYBOARD_DANISH,IMM_HANDWRITING_TYPE_LOWER_CASE_DANISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_DANISH,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_DANISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_DA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"da-DK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_DANISH,GUI_VIRTUAL_KEYBOARD_DANISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_DANISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_T9_FRENCH__) ||defined(__MMI_ZI_EU_FRENCH__) ||defined(__MMI_CSTAR_FRENCH__) ||defined(__MMI_GB_FRENCH__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_FRENCH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_FRENCH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
#if defined(__MMI_LANG_CA_FRENCH__)        
    IME_WRITING_LANG_FRCA,
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    "fr-CA",
#endif
#else
    IME_WRITING_LANG_FR,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"fr-FR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#endif
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_FRENCH,GUI_VIRTUAL_KEYBOARD_FRENCH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_FRENCH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_FRENCH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_FRENCH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
#if defined(__MMI_LANG_CA_FRENCH__)        
    IME_WRITING_LANG_FRCA,
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    "fr-CA",
#endif
#else
    IME_WRITING_LANG_FR,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"fr-FR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#endif
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_FRENCH,GUI_VIRTUAL_KEYBOARD_FRENCH,IMM_HANDWRITING_TYPE_LOWER_CASE_FRENCH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_FRENCH,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_FRENCH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
#if defined(__MMI_LANG_CA_FRENCH__)        
    IME_WRITING_LANG_FRCA,
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    "fr-CA",
#endif
#else
    IME_WRITING_LANG_FR,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"fr-FR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#endif
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_FRENCH,GUI_VIRTUAL_KEYBOARD_FRENCH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_FRENCH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_FRENCH__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_FRENCH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_FRENCH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
#if defined(__MMI_LANG_CA_FRENCH__)
    IME_WRITING_LANG_FRCA,
#else
    IME_WRITING_LANG_FR,
#endif
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)

#if defined(__MMI_LANG_CA_FRENCH__)
"fr-CA",
#else
"fr-FR",
#endif
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_FRENCH,GUI_VIRTUAL_KEYBOARD_FRENCH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_FRENCH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_FRENCH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_FRENCH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
#if defined(__MMI_LANG_CA_FRENCH__)
    IME_WRITING_LANG_FRCA,
#else
    IME_WRITING_LANG_FR,
#endif
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
#if defined(__MMI_LANG_CA_FRENCH__)
"fr-CA",
#else
"fr-FR",
#endif
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_FRENCH,GUI_VIRTUAL_KEYBOARD_FRENCH,IMM_HANDWRITING_TYPE_LOWER_CASE_FRENCH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_FRENCH,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_FRENCH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
#if defined(__MMI_LANG_CA_FRENCH__)
    IME_WRITING_LANG_FRCA,
#else
    IME_WRITING_LANG_FR,
#endif
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
#if defined(__MMI_LANG_CA_FRENCH__)
"fr-CA",
#else
"fr-FR",
#endif
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_FRENCH,GUI_VIRTUAL_KEYBOARD_FRENCH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_FRENCH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_T9_AZERBAIJANI__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_AZERBAIJANI,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_AZERBAIJANI,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_AZ,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"az-AZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_AZERBAIJANI,GUI_VIRTUAL_KEYBOARD_AZERBAIJANI_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_AZERBAIJANI,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_AZERBAIJANI,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_AZ,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"az-AZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_AZERBAIJANI,GUI_VIRTUAL_KEYBOARD_AZERBAIJANI,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_AZERBAIJANI,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_AZERBAIJANI,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_AZ,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"az-AZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_AZERBAIJANI,GUI_VIRTUAL_KEYBOARD_AZERBAIJANI_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_AZERBAIJANI__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_AZERBAIJANI,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_AZERBAIJANI,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_AZ,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"az-AZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_AZERBAIJANI,GUI_VIRTUAL_KEYBOARD_AZERBAIJANI_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_AZERBAIJANI,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_AZERBAIJANI,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_AZ,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"az-AZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_AZERBAIJANI,GUI_VIRTUAL_KEYBOARD_AZERBAIJANI,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_AZERBAIJANI,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_AZERBAIJANI,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_AZ,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"az-AZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_AZERBAIJANI,GUI_VIRTUAL_KEYBOARD_AZERBAIJANI_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif


#if defined(__MMI_T9_CATALAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_CATALAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_CATALAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_CA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ca-CA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_CATALAN,GUI_VIRTUAL_KEYBOARD_CATALAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_CATALAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_CATALAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_CATALAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_CA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ca-CA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_CATALAN,GUI_VIRTUAL_KEYBOARD_CATALAN,IMM_HANDWRITING_TYPE_LOWER_CASE_CATALAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_CATALAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_CATALAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_CA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ca-CA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_CATALAN,GUI_VIRTUAL_KEYBOARD_CATALAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_CATALAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_CATALAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_CATALAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_CATALAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_CA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ca-CA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_CATALAN,GUI_VIRTUAL_KEYBOARD_CATALAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_CATALAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_CATALAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_CATALAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_CA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ca-CA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_CATALAN,GUI_VIRTUAL_KEYBOARD_CATALAN,IMM_HANDWRITING_TYPE_LOWER_CASE_CATALAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_CATALAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_CATALAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_CA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ca-CA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_CATALAN,GUI_VIRTUAL_KEYBOARD_CATALAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_CATALAN)
#endif
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif



#if defined(__MMI_T9_KAZAKH__)||defined(__MMI_GB_KAZAKH__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_KAZAKH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_KAZAKH,
    IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_KK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"kk-KK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_KAZAKH,GUI_VIRTUAL_KEYBOARD_KAZAKH_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_KAZAKH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_KAZAKH,
    IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_KK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"kk-KK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_KAZAKH,GUI_VIRTUAL_KEYBOARD_KAZAKH,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_KAZAKH,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_KAZAKH,
    IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_KK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"kk-KK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_KAZAKH,GUI_VIRTUAL_KEYBOARD_KAZAKH_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif


#if defined(__MMI_MULTITAP_KAZAKH__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_KAZAKH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_KAZAKH,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_KK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"kk-KK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_KAZAKH,GUI_VIRTUAL_KEYBOARD_KAZAKH_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_KAZAKH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_KAZAKH,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_KK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"kk-KK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_KAZAKH,GUI_VIRTUAL_KEYBOARD_KAZAKH,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_KAZAKH,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_KAZAKH,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_KK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"kk-KK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_KAZAKH,GUI_VIRTUAL_KEYBOARD_KAZAKH_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif


#if defined(__MMI_T9_HAUSA__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_HAUSA,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_HAUSA,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_HA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ha-HA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_HAUSA,GUI_VIRTUAL_KEYBOARD_HAUSA_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_HAUSA,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_HAUSA,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_HA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ha-HA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_HAUSA,GUI_VIRTUAL_KEYBOARD_HAUSA,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_HAUSA,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_HAUSA,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_HA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ha-HA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_HAUSA,GUI_VIRTUAL_KEYBOARD_HAUSA_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif


#if defined(__MMI_MULTITAP_HAUSA__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_HAUSA,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_HAUSA,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_HA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ha-HA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_HAUSA,GUI_VIRTUAL_KEYBOARD_HAUSA_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_HAUSA,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_HAUSA,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_HA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ha-HA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_HAUSA,GUI_VIRTUAL_KEYBOARD_HAUSA,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_HAUSA,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_HAUSA,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_HA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ha-HA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_HAUSA,GUI_VIRTUAL_KEYBOARD_HAUSA_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_T9_GALICIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_GALICIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_GALICIAN,
    IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_GL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"gl-ES",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_GALICIAN,GUI_VIRTUAL_KEYBOARD_GALICIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_GALICIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_GALICIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_GALICIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_GL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"gl-ES",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_GALICIAN,GUI_VIRTUAL_KEYBOARD_GALICIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_GALICIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_GALICIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_GALICIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_GL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"gl-ES",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_GALICIAN,GUI_VIRTUAL_KEYBOARD_GALICIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_GALICIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif


#if defined(__MMI_MULTITAP_GALICIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_GALICIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_GALICIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_GL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"gl-ES",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_GALICIAN,GUI_VIRTUAL_KEYBOARD_GALICIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_GALICIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_GALICIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_GALICIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_GL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"gl-ES",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_GALICIAN,GUI_VIRTUAL_KEYBOARD_GALICIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_GALICIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_GALICIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_GALICIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_GL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"gl-ES",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_GALICIAN,GUI_VIRTUAL_KEYBOARD_GALICIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_GALICIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_T9_BASQUE__)|| defined(__MMI_GB_BASQUE__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_BASQUE,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_BASQUE,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_EU,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"eu-ES",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_BASQUE,GUI_VIRTUAL_KEYBOARD_BASQUE_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_BASQUE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_BASQUE,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_BASQUE,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_EU,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"eu-ES",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_BASQUE,GUI_VIRTUAL_KEYBOARD_BASQUE,IMM_HANDWRITING_TYPE_LOWER_CASE_BASQUE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_BASQUE,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_BASQUE,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_EU,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"eu-ES",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_BASQUE,GUI_VIRTUAL_KEYBOARD_BASQUE_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_BASQUE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif


#if defined(__MMI_MULTITAP_BASQUE__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_BASQUE,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_BASQUE,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_EU,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"eu-ES",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_BASQUE,GUI_VIRTUAL_KEYBOARD_BASQUE_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_BASQUE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_BASQUE,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_BASQUE,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_EU,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"eu-ES",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_BASQUE,GUI_VIRTUAL_KEYBOARD_BASQUE,IMM_HANDWRITING_TYPE_LOWER_CASE_BASQUE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_BASQUE,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_BASQUE,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_EU,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"eu-ES",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_BASQUE,GUI_VIRTUAL_KEYBOARD_BASQUE_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_BASQUE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_T9_IGBO__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_IGBO,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_IGBO,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_IG,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ig-NG",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_IGBO,GUI_VIRTUAL_KEYBOARD_IGBO_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_IGBO,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_IGBO,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_IG,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ig-NG",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_IGBO,GUI_VIRTUAL_KEYBOARD_IGBO,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_IGBO,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_IGBO,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_IG,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ig-NG",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_IGBO,GUI_VIRTUAL_KEYBOARD_IGBO_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif


#if defined(__MMI_MULTITAP_IGBO__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_IGBO,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_IGBO,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_IG,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ig-NG",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_IGBO,GUI_VIRTUAL_KEYBOARD_IGBO_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_IGBO,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_IGBO,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_IG,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ig-NG",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_IGBO,GUI_VIRTUAL_KEYBOARD_IGBO,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_IGBO,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_IGBO,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_IG,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ig-NG",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_IGBO,GUI_VIRTUAL_KEYBOARD_IGBO_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_T9_FILIPINO__) ||defined(__MMI_GB_FILIPINO__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_FILIPINO,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_FILIPINO,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_FIL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"fil-PH",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_FILIPINO,GUI_VIRTUAL_KEYBOARD_FILIPINO_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_FILIPINO,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_FILIPINO,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_FIL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"fil-PH",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_FILIPINO,GUI_VIRTUAL_KEYBOARD_FILIPINO,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_FILIPINO,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_FILIPINO,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_FIL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"fil-PH",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_FILIPINO,GUI_VIRTUAL_KEYBOARD_FILIPINO_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif


#if defined(__MMI_MULTITAP_FILIPINO__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_FILIPINO,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_FILIPINO,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_FIL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"fil-PH",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_FILIPINO,GUI_VIRTUAL_KEYBOARD_FILIPINO_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_FILIPINO,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_FILIPINO,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_FIL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"fil-PH",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_FILIPINO,GUI_VIRTUAL_KEYBOARD_FILIPINO,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_FILIPINO,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_FILIPINO,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_FIL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"fil-PH",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_FILIPINO,GUI_VIRTUAL_KEYBOARD_FILIPINO_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_T9_IRISH__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_IRISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_IRISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_GA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ga-IE",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_IRISH,GUI_VIRTUAL_KEYBOARD_IRISH_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_IRISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_IRISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_GA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ga-IE",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_IRISH,GUI_VIRTUAL_KEYBOARD_IRISH,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_IRISH,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_IRISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_GA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ga-IE",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_IRISH,GUI_VIRTUAL_KEYBOARD_IRISH_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif


#if defined(__MMI_MULTITAP_IRISH__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_IRISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_IRISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_GA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ga-IE",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_IRISH,GUI_VIRTUAL_KEYBOARD_IRISH_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_IRISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_IRISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_GA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ga-IE",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_IRISH,GUI_VIRTUAL_KEYBOARD_IRISH,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_IRISH,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_IRISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_GA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ga-IE",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_IRISH,GUI_VIRTUAL_KEYBOARD_IRISH_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif



#if defined(__MMI_T9_MACEDONIAN__)|| defined(__MMI_GB_MACEDONIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_MACEDONIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_MACEDONIAN,
    IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_MK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"mk-MK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_MACEDONIAN,GUI_VIRTUAL_KEYBOARD_MACEDONIAN_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_MACEDONIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_MACEDONIAN,
    IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_MK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"mk-MK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_MACEDONIAN,GUI_VIRTUAL_KEYBOARD_MACEDONIAN,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_MACEDONIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_MACEDONIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_MK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"mk-MK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_MACEDONIAN,GUI_VIRTUAL_KEYBOARD_MACEDONIAN_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_MACEDONIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_MACEDONIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_MACEDONIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_MK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"mk-MK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_MACEDONIAN,GUI_VIRTUAL_KEYBOARD_MACEDONIAN_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_MACEDONIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_MACEDONIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_MK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"mk-MK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_MACEDONIAN,GUI_VIRTUAL_KEYBOARD_MACEDONIAN,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_MACEDONIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_MACEDONIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_MK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"mk-MK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_MACEDONIAN,GUI_VIRTUAL_KEYBOARD_MACEDONIAN_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif


#if defined(__MMI_T9_SESOTHO__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_SESOTHO,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_SESOTHO,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_ST,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"st-ST",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_SESOTHO,GUI_VIRTUAL_KEYBOARD_SESOTHO_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_SESOTHO,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_SESOTHO,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_ST,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"st-ST",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_SESOTHO,GUI_VIRTUAL_KEYBOARD_SESOTHO,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SESOTHO,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_SESOTHO,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_ST,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"st-ST",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_SESOTHO,GUI_VIRTUAL_KEYBOARD_SESOTHO_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif


#if defined(__MMI_MULTITAP_SESOTHO__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SESOTHO,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_SESOTHO,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_ST,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"st-ST",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_SESOTHO,GUI_VIRTUAL_KEYBOARD_SESOTHO_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SESOTHO,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_SESOTHO,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_ST,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"st-ST",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_SESOTHO,GUI_VIRTUAL_KEYBOARD_SESOTHO,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SESOTHO,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_SESOTHO,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_ST,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"st-ST",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_SESOTHO,GUI_VIRTUAL_KEYBOARD_SESOTHO_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_T9_TAGALOG__) ||defined(__MMI_ZI_TAGALOG__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_TAGALOG,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_TAGALOG,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_TL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"tl-TL",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_TAGALOG,GUI_VIRTUAL_KEYBOARD_TAGALOG_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_TAGALOG)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_TAGALOG,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_TAGALOG,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_TL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"tl-TL",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_TAGALOG,GUI_VIRTUAL_KEYBOARD_TAGALOG,IMM_HANDWRITING_TYPE_LOWER_CASE_TAGALOG)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_TAGALOG,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_TAGALOG,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_TL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"tl-TL",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_TAGALOG,GUI_VIRTUAL_KEYBOARD_TAGALOG_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_TAGALOG)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_TAGALOG__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_TAGALOG,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_TAGALOG,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_TL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"tl-TL",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_TAGALOG,GUI_VIRTUAL_KEYBOARD_TAGALOG_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_TAGALOG)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_TAGALOG,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_TAGALOG,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_TL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"tl-TL",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_TAGALOG,GUI_VIRTUAL_KEYBOARD_TAGALOG,IMM_HANDWRITING_TYPE_LOWER_CASE_TAGALOG)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_TAGALOG,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_TAGALOG,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_TL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"tl-TL",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_TAGALOG,GUI_VIRTUAL_KEYBOARD_TAGALOG_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_TAGALOG)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_T9_YORUBA__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_YORUBA,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_YORUBA,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_YO,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"yo-YO",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_YORUBA,GUI_VIRTUAL_KEYBOARD_YORUBA_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_YORUBA,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_YORUBA,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_YO,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"yo-YO",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_YORUBA,GUI_VIRTUAL_KEYBOARD_YORUBA,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_YORUBA,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_YORUBA,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_YO,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"yo-YO",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_YORUBA,GUI_VIRTUAL_KEYBOARD_YORUBA_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_YORUBA__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_YORUBA,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_YORUBA,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_YO,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"yo-YO",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_YORUBA,GUI_VIRTUAL_KEYBOARD_YORUBA_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_YORUBA,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_YORUBA,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_YO,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"yo-YO",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_YORUBA,GUI_VIRTUAL_KEYBOARD_YORUBA,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_YORUBA,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_YORUBA,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_YO,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"yo-YO",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_YORUBA,GUI_VIRTUAL_KEYBOARD_YORUBA_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_T9_GERMAN__) ||defined(__MMI_ZI_GERMAN__) ||defined(__MMI_CSTAR_GERMAN__) ||defined(__MMI_GB_GERMAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_GERMAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_GERMAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_DE,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"de-DE",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_GERMAN,GUI_VIRTUAL_KEYBOARD_GERMAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_GERMAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_GERMAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_GERMAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_DE,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"de-DE",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_GERMAN,GUI_VIRTUAL_KEYBOARD_GERMAN,IMM_HANDWRITING_TYPE_LOWER_CASE_GERMAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_GERMAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_GERMAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_DE,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"de-DE",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_GERMAN,GUI_VIRTUAL_KEYBOARD_GERMAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_GERMAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_GERMAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_GERMAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_GERMAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_DE,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"de-DE",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_GERMAN,GUI_VIRTUAL_KEYBOARD_GERMAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_GERMAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_GERMAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_GERMAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_DE,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"de-DE",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_GERMAN,GUI_VIRTUAL_KEYBOARD_GERMAN,IMM_HANDWRITING_TYPE_LOWER_CASE_GERMAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_GERMAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_GERMAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_DE,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"de-DE",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_GERMAN,GUI_VIRTUAL_KEYBOARD_GERMAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_GERMAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_KOREAN__)
{
    IMM_INPUT_MODE_MULTITAP_KOREAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_KOREAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_KR,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ko",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_TOUCH_SCREEN__*/
},

#endif
#if defined(__MMI_T9_ITALIAN__) ||defined(__MMI_ZI_ITALIAN__) ||defined(__MMI_CSTAR_ITALIAN__) ||defined(__MMI_GB_ITALIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_ITALIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_ITALIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_IT,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"it-IT",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_ITALIAN,GUI_VIRTUAL_KEYBOARD_ITALIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ITALIC)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_ITALIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_ITALIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_IT,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"it-IT",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_ITALIAN,GUI_VIRTUAL_KEYBOARD_ITALIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_ITALIC)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ITALIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_ITALIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_IT,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"it-IT",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_ITALIAN,GUI_VIRTUAL_KEYBOARD_ITALIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ITALIC)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_ITALIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ITALIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_ITALIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_IT,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"it-IT",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_ITALIAN,GUI_VIRTUAL_KEYBOARD_ITALIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ITALIC)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ITALIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_ITALIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_IT,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"it-IT",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_ITALIAN,GUI_VIRTUAL_KEYBOARD_ITALIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_ITALIC)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ITALIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_ITALIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_IT,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"it-IT",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_ITALIAN,GUI_VIRTUAL_KEYBOARD_ITALIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ITALIC)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_T9_RUSSIAN__) ||defined(__MMI_ZI_RUSSIAN__) ||defined(__MMI_ZI_RECOMMENDED_SIZE_RUSSIAN__) ||defined(__MMI_CSTAR_RUSSIAN__) ||defined(__MMI_GB_RUSSIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_RUSSIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_RUSSIAN,
    IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_RU,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ru-RU",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_RUSSIAN,GUI_VIRTUAL_KEYBOARD_RUSSIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_RUSSIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_RUSSIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_RUSSIAN,
    IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_RU,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ru-RU",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_RUSSIAN,GUI_VIRTUAL_KEYBOARD_RUSSIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_RUSSIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_RUSSIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_RUSSIAN,
    IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_RU,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ru-RU",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_RUSSIAN,GUI_VIRTUAL_KEYBOARD_RUSSIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_RUSSIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_RUSSIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_RUSSIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_RUSSIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_RU,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ru-RU",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_RUSSIAN,GUI_VIRTUAL_KEYBOARD_RUSSIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_RUSSIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_RUSSIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_RUSSIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_RU,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ru-RU",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_RUSSIAN,GUI_VIRTUAL_KEYBOARD_RUSSIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_RUSSIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_RUSSIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_RUSSIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_RU,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ru-RU",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_RUSSIAN,GUI_VIRTUAL_KEYBOARD_RUSSIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_RUSSIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_ZI_BULGARIAN__) ||defined(__MMI_T9_BULGARIAN__) ||defined(__MMI_CSTAR_BULGARIAN__) ||defined(__MMI_GB_BULGARIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_BULGARIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_BULGARIAN,
    IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_BG,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"bg-BG",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_BULGARIAN,GUI_VIRTUAL_KEYBOARD_BULGARIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_BULGARIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_BULGARIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_BULGARIAN,
    IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_BG,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"bg-BG",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_BULGARIAN,GUI_VIRTUAL_KEYBOARD_BULGARIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_BULGARIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_BULGARIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_BULGARIAN,
    IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_BG,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"bg-BG",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_BULGARIAN,GUI_VIRTUAL_KEYBOARD_BULGARIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_BULGARIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_BULGARIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_BULGARIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_BULGARIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_BG,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"bg-BG",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_BULGARIAN,GUI_VIRTUAL_KEYBOARD_BULGARIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_BULGARIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_BULGARIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_BULGARIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_BG,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"bg-BG",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_BULGARIAN,GUI_VIRTUAL_KEYBOARD_BULGARIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_BULGARIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_BULGARIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_BULGARIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_BG,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"bg-BG",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_BULGARIAN,GUI_VIRTUAL_KEYBOARD_BULGARIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_BULGARIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif


#if defined(__MMI_ZI_UKRAINIAN__) ||defined(__MMI_T9_UKRAINIAN__) ||defined(__MMI_CSTAR_UKRAINIAN__) ||defined(__MMI_GB_UKRAINIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_UKRAINIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_UKRAINIAN,
    IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_UK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"uk-UA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_UKRAINIAN,GUI_VIRTUAL_KEYBOARD_UKRAINIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_UKRANIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_UKRAINIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_UKRAINIAN,
    IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_UK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"uk-UA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_UKRAINIAN,GUI_VIRTUAL_KEYBOARD_UKRAINIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_UKRANIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_UKRAINIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_UKRAINIAN,
    IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_UK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"uk-UA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_UKRAINIAN,GUI_VIRTUAL_KEYBOARD_UKRAINIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_UKRANIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_UKRAINIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_UKRAINIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_UKRAINIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_UK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"uk-UA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_UKRAINIAN,GUI_VIRTUAL_KEYBOARD_UKRAINIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_UKRANIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_UKRAINIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_UKRAINIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_UK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"uk-UA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_UKRAINIAN,GUI_VIRTUAL_KEYBOARD_UKRAINIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_UKRANIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_UKRAINIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_UKRAINIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_UK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"uk-UA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_UKRAINIAN,GUI_VIRTUAL_KEYBOARD_UKRAINIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_UKRANIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_ZI_TURKISH__) ||defined(__MMI_T9_TURKISH__) ||defined(__MMI_CSTAR_TURKISH__) ||defined(__MMI_GB_TURKISH__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_TURKISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_TURKISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_TR,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"tr-TR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_TURKISH,GUI_VIRTUAL_KEYBOARD_TURKISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_TURKEY)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_TURKISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_TURKISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_TR,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"tr-TR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_TURKISH,GUI_VIRTUAL_KEYBOARD_TURKISH,IMM_HANDWRITING_TYPE_LOWER_CASE_TURKEY)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_TURKISH,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_TURKISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_TR,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"tr-TR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_TURKISH,GUI_VIRTUAL_KEYBOARD_TURKISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_TURKEY)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_TURKISH__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_TURKISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_TURKISH,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_TR,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"tr-TR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_TURKISH,GUI_VIRTUAL_KEYBOARD_TURKISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_TURKEY)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_TURKISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_TURKISH,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_TR,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"tr-TR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_TURKISH,GUI_VIRTUAL_KEYBOARD_TURKISH,IMM_HANDWRITING_TYPE_LOWER_CASE_TURKEY)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_TURKISH,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_TURKISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_TR,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"tr-TR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_TURKISH,GUI_VIRTUAL_KEYBOARD_TURKISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_TURKEY)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_ZI_SA_PORTUGUESE__)||defined(__MMI_GB_SA_PORTUGUESE__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_SA_PORTUGUESE,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_SA_PORTUGUESE,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_PTBZ,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"pt-BZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_SA_PORTUGUESE,GUI_VIRTUAL_KEYBOARD_PORTUGUESE_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_PORTUGESE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_SA_PORTUGUESE,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_SA_PORTUGUESE,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_PTBZ,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"pt-BZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_SA_PORTUGUESE,GUI_VIRTUAL_KEYBOARD_PORTUGUESE,IMM_HANDWRITING_TYPE_LOWER_CASE_PORTUGESE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SA_PORTUGUESE,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_SA_PORTUGUESE,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_PTBZ,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"pt-BZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_SA_PORTUGUESE,GUI_VIRTUAL_KEYBOARD_PORTUGUESE_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_PORTUGESE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif
#if defined __MMI_LANG_PORTUGUESE__
#if defined(__MMI_T9_PORTUGUESE__) ||defined(__MMI_ZI_EU_PORTUGUESE__) ||defined(__MMI_CSTAR_PORTUGUESE__) ||defined(__MMI_GB_PORTUGUESE__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_PORTUGUESE,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_PORTUGUESE,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_PT,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"pt-PT",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_PORTUGUESE,GUI_VIRTUAL_KEYBOARD_PORTUGUESE_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_PORTUGESE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_PORTUGUESE,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_PORTUGUESE,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_PT,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"pt-PT",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_PORTUGUESE,GUI_VIRTUAL_KEYBOARD_PORTUGUESE,IMM_HANDWRITING_TYPE_LOWER_CASE_PORTUGESE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_PORTUGUESE,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_PORTUGUESE,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_PT,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"pt-PT",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_PORTUGUESE,GUI_VIRTUAL_KEYBOARD_PORTUGUESE_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_PORTUGESE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_PORTUGUESE__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_PORTUGUESE,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_PORTUGUESE,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_PT,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"pt-PT",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_PORTUGUESE,GUI_VIRTUAL_KEYBOARD_PORTUGUESE_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_PORTUGESE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_PORTUGUESE,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_PORTUGUESE,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_PT,
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
"pt-PT",
#endif /* defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) */
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_PORTUGUESE,GUI_VIRTUAL_KEYBOARD_PORTUGUESE,IMM_HANDWRITING_TYPE_LOWER_CASE_PORTUGESE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_PORTUGUESE,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_PORTUGUESE,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_PT,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"pt-PT",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_PORTUGUESE,GUI_VIRTUAL_KEYBOARD_PORTUGUESE_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_PORTUGESE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif
#endif
#if defined __MMI_LANG_SA_PORTUGUESE__ && !defined __MMI_LANG_PORTUGUESE__
#if defined(__MMI_T9_PORTUGUESE__) ||defined(__MMI_ZI_EU_PORTUGUESE__) ||defined(__MMI_CSTAR_PORTUGUESE__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_PORTUGUESE,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_PORTUGUESE,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_PTBZ,
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    "pt-BZ",
#endif /* defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) */
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_PORTUGUESE,GUI_VIRTUAL_KEYBOARD_PORTUGUESE_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_PORTUGESE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_PORTUGUESE,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_PORTUGUESE,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,

    IME_WRITING_LANG_PTBZ,
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    "pt-BZ",
#endif /* defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) */
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_PORTUGUESE,GUI_VIRTUAL_KEYBOARD_PORTUGUESE,IMM_HANDWRITING_TYPE_LOWER_CASE_PORTUGESE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_PORTUGUESE,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_PORTUGUESE,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_PTBZ,
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    "pt-BZ",
#endif /* defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) */
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_PORTUGUESE,GUI_VIRTUAL_KEYBOARD_PORTUGUESE_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_PORTUGESE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_PORTUGUESE__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_PORTUGUESE,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_PORTUGUESE,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_PTBZ,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"pt-BZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_PORTUGUESE,GUI_VIRTUAL_KEYBOARD_PORTUGUESE_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_PORTUGESE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_PORTUGUESE,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_PORTUGUESE,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_PTBZ,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"pt-BZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_PORTUGUESE,GUI_VIRTUAL_KEYBOARD_PORTUGUESE,IMM_HANDWRITING_TYPE_LOWER_CASE_PORTUGESE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_PORTUGUESE,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_PORTUGUESE,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_PTBZ,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"pt-BZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_PORTUGUESE,GUI_VIRTUAL_KEYBOARD_PORTUGUESE_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_PORTUGESE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif
#endif
#if defined(__MMI_ZI_INDONESIAN__) ||defined(__MMI_T9_INDONESIAN__) ||defined(__MMI_CSTAR_INDONESIAN__) ||defined(__MMI_GB_INDONESIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_INDONESIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_INDONESIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_ID,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"id-ID",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_INDONESIAN,GUI_VIRTUAL_KEYBOARD_INDONESIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_INDONESIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_INDONESIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_INDONESIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_ID,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"id-ID",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_INDONESIAN,GUI_VIRTUAL_KEYBOARD_INDONESIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_INDONESIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_INDONESIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_INDONESIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_ID,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"id-ID",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_INDONESIAN,GUI_VIRTUAL_KEYBOARD_INDONESIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_INDONESIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_INDONESIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_INDONESIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_INDONESIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_ID,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"id-ID",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_INDONESIAN,GUI_VIRTUAL_KEYBOARD_INDONESIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_INDONESIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_INDONESIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_INDONESIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_ID,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"id-ID",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_INDONESIAN,GUI_VIRTUAL_KEYBOARD_INDONESIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_INDONESIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_INDONESIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_INDONESIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_ID,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"id-ID",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_INDONESIAN,GUI_VIRTUAL_KEYBOARD_INDONESIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_INDONESIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif


#if defined(__MMI_T9_CZECH__) ||defined(__MMI_ZI_CZECH__) ||defined(__MMI_CSTAR_CZECH__) ||defined(__MMI_GB_CZECH__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_CZECH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_CZECH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_CS,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"cs-CZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_CZECH,GUI_VIRTUAL_KEYBOARD_CZECH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_CZECH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_CZECH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_CZECH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_CS,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"cs-CZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_CZECH,GUI_VIRTUAL_KEYBOARD_CZECH,IMM_HANDWRITING_TYPE_LOWER_CASE_CZECH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_CZECH,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_CZECH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_CS,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"cs-CZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_CZECH,GUI_VIRTUAL_KEYBOARD_CZECH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_CZECH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_CZECH__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_CZECH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_CZECH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_CS,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"cs-CZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_CZECH,GUI_VIRTUAL_KEYBOARD_CZECH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_CZECH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_CZECH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_CZECH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_CS,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"cs-CZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_CZECH,GUI_VIRTUAL_KEYBOARD_CZECH,IMM_HANDWRITING_TYPE_LOWER_CASE_CZECH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_CZECH,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_CZECH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_CS,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"cs-CZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_CZECH,GUI_VIRTUAL_KEYBOARD_CZECH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_CZECH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_T9_NORWEGIAN__) ||defined(__MMI_ZI_NORWEGIAN__) ||defined(__MMI_CSTAR_NORWEGIAN__) ||defined(__MMI_GB_NORWEGIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_NORWEGIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_NORWEGIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_NO,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"nb-NO",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_NORWEGIAN,GUI_VIRTUAL_KEYBOARD_NORWEGIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_NORWEGIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_NORWEGIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_NORWEGIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_NO,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"nb-NO",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_NORWEGIAN,GUI_VIRTUAL_KEYBOARD_NORWEGIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_NORWEGIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_NORWEGIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_NORWEGIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_NO,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"nb-NO",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_NORWEGIAN,GUI_VIRTUAL_KEYBOARD_NORWEGIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_NORWEGIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_NORWEGIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_NORWEGIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_NORWEGIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_NO,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"nb-NO",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_NORWEGIAN,GUI_VIRTUAL_KEYBOARD_NORWEGIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_NORWEGIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_NORWEGIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_NORWEGIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_NO,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"nb-NO",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_NORWEGIAN,GUI_VIRTUAL_KEYBOARD_NORWEGIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_NORWEGIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_NORWEGIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_NORWEGIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_NO,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"nb-NO",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_NORWEGIAN,GUI_VIRTUAL_KEYBOARD_NORWEGIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_NORWEGIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_ZI_MALAY__) ||defined(__MMI_T9_MALAY__) ||defined(__MMI_CSTAR_MALAY__) ||defined(__MMI_GB_MALAY__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_MALAY,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_MALAY,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_MS,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ms-MY",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_MALAY,GUI_VIRTUAL_KEYBOARD_MALAY_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_MALAY)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_MALAY,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_MALAY,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_MS,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ms-MY",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_MALAY,GUI_VIRTUAL_KEYBOARD_MALAY,IMM_HANDWRITING_TYPE_LOWER_CASE_MALAY)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_MALAY,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_MALAY,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_MS,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ms-MY",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_MALAY,GUI_VIRTUAL_KEYBOARD_MALAY_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_MALAY)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_MALAY__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_MALAY,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_MALAY,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_MS,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ms-MY",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_MALAY,GUI_VIRTUAL_KEYBOARD_MALAY_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_MALAY)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_MALAY,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_MALAY,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_MS,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ms-MY",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_MALAY,GUI_VIRTUAL_KEYBOARD_MALAY,IMM_HANDWRITING_TYPE_LOWER_CASE_MALAY)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_MALAY,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_MALAY,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_MS,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ms-MY",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_MALAY,GUI_VIRTUAL_KEYBOARD_MALAY_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_MALAY)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_ZI_VIETNAMESE__) ||defined(__MMI_T9_VIETNAMESE__) ||defined(__MMI_CSTAR_VIETNAMESE__) ||defined(__MMI_GB_VIETNAMESE__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_VIETNAMESE,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_VIETNAMESE,
    IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_VI,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"vi-VN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_VIETNAMESE,GUI_VIRTUAL_KEYBOARD_VIETNAMESE_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_VIETNAMESE,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_VIETNAMESE,
    IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_VI,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"vi-VN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_VIETNAMESE,GUI_VIRTUAL_KEYBOARD_VIETNAMESE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_VIETNAMESE,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_VIETNAMESE,
    IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_VI,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"vi-VN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_VIETNAMESE,GUI_VIRTUAL_KEYBOARD_VIETNAMESE_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_VIETNAMESE__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_VIETNAMESE,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_VIETNAMESE,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_VI,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"vi-VN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_VIETNAMESE,GUI_VIRTUAL_KEYBOARD_VIETNAMESE_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_VIETNAMESE,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_VIETNAMESE,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_VI,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"vi-VN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_VIETNAMESE,GUI_VIRTUAL_KEYBOARD_VIETNAMESE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_VIETNAMESE,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_VIETNAMESE,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_VI,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"vi-VN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_VIETNAMESE,GUI_VIRTUAL_KEYBOARD_VIETNAMESE_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_T9_FINNISH__) ||defined(__MMI_ZI_FINNISH__) ||defined(__MMI_CSTAR_FINNISH__) ||defined(__MMI_GB_FINNISH__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_FINNISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_FINNISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_FI,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"fi-FI",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_FINNISH,GUI_VIRTUAL_KEYBOARD_FINNISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_FINNISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_FINNISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_FINNISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_FI,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"fi-FI",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_FINNISH,GUI_VIRTUAL_KEYBOARD_FINNISH,IMM_HANDWRITING_TYPE_LOWER_CASE_FINNISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_FINNISH,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_FINNISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_FI,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"fi-FI",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_FINNISH,GUI_VIRTUAL_KEYBOARD_FINNISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_FINNISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_FINNISH__)
/*MultitapFINNISH*/
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_FINNISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_FINNISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_FI,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"fi-FI",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_FINNISH,GUI_VIRTUAL_KEYBOARD_FINNISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_FINNISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
/*Multitapfinnish*/
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_FINNISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_FINNISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_FI,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"fi-FI",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_FINNISH,GUI_VIRTUAL_KEYBOARD_FINNISH,IMM_HANDWRITING_TYPE_LOWER_CASE_FINNISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_FINNISH,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_FINNISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_FI,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"fi-FI",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_FINNISH,GUI_VIRTUAL_KEYBOARD_FINNISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_FINNISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_T9_HUNGARIAN__) ||defined(__MMI_ZI_HUNGARIAN__) ||defined(__MMI_CSTAR_HUNGARIAN__) ||defined(__MMI_GB_HUNGARIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_HUNGARIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_HUNGARIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_HU,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"hu-HU",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_HUNGARIAN,GUI_VIRTUAL_KEYBOARD_HUNGARIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_HUNGARIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_HUNGARIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_HUNGARIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_HU,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"hu-HU",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_HUNGARIAN,GUI_VIRTUAL_KEYBOARD_HUNGARIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_HUNGARIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_HUNGARIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_HUNGARIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_HU,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"hu-HU",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_HUNGARIAN,GUI_VIRTUAL_KEYBOARD_HUNGARIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_HUNGARIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif


#if defined(__MMI_CSTAR_HINGLISH__)||defined(__MMI_GB_HINGLISH__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_HINGLISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_HINGLISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_HABC,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"hg-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_HINGLISH,GUI_VIRTUAL_KEYBOARD_ENGLISH,IMM_HANDWRITING_TYPE_NONE) 
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_HINGLISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_HINGLISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_HABC,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"hg-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_HINGLISH,GUI_VIRTUAL_KEYBOARD_ENGLISH,IMM_HANDWRITING_TYPE_NONE) 
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif

#if defined(__MMI_MULTITAP_HUNGARIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_HUNGARIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_HUNGARIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_HU,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"hu-HU",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_HUNGARIAN,GUI_VIRTUAL_KEYBOARD_HUNGARIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_HUNGARIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_HUNGARIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_HUNGARIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_HU,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"hu-HU",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_HUNGARIAN,GUI_VIRTUAL_KEYBOARD_HUNGARIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_HUNGARIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_HUNGARIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_HUNGARIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_HU,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"hu-HU",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_HUNGARIAN,GUI_VIRTUAL_KEYBOARD_HUNGARIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_HUNGARIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_T9_SLOVAK__) ||defined(__MMI_ZI_SLOVAK__) ||defined(__MMI_CSTAR_SLOVAKIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_SLOVAK,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_SLOVAK,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_SK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sk-SK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_SLOVAK,GUI_VIRTUAL_KEYBOARD_SLOVAK_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_SLOVAKIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_SLOVAK,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_SLOVAK,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_SK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sk-SK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_SLOVAK,GUI_VIRTUAL_KEYBOARD_SLOVAK,IMM_HANDWRITING_TYPE_LOWER_CASE_SLOVAKIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SLOVAK,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_SLOVAK,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_SK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sk-SK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_SLOVAK,GUI_VIRTUAL_KEYBOARD_SLOVAK_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_SLOVAKIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_SLOVAK__)
/*MultitapSLOVAK*/
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SLOVAK,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_SLOVAK,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_SK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sk-SK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_SLOVAK,GUI_VIRTUAL_KEYBOARD_SLOVAK_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_SLOVAKIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
/*Multitapslovak*/
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SLOVAK,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_SLOVAK,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_SK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sk-SK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_SLOVAK,GUI_VIRTUAL_KEYBOARD_SLOVAK,IMM_HANDWRITING_TYPE_LOWER_CASE_SLOVAKIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SLOVAK,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_SLOVAK,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_SK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sk-SK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_SLOVAK,GUI_VIRTUAL_KEYBOARD_SLOVAK_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_SLOVAKIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_ZI_DUTCH__) ||defined(__MMI_T9_DUTCH__) ||defined(__MMI_CSTAR_DUTCH__) ||defined(__MMI_GB_DUTCH__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_DUTCH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_DUTCH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_NL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"nl-NL",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_DUTCH,GUI_VIRTUAL_KEYBOARD_DUTCH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_DUTCH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_DUTCH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_DUTCH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_NL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"nl-NL",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_DUTCH,GUI_VIRTUAL_KEYBOARD_DUTCH,IMM_HANDWRITING_TYPE_LOWER_CASE_DUTCH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_DUTCH,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_DUTCH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_NL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"nl-NL",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_DUTCH,GUI_VIRTUAL_KEYBOARD_DUTCH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_DUTCH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_DUTCH__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_DUTCH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_DUTCH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_NL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"nl-NL",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_DUTCH,GUI_VIRTUAL_KEYBOARD_DUTCH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_DUTCH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_DUTCH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_DUTCH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_NL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"nl-NL",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_DUTCH,GUI_VIRTUAL_KEYBOARD_DUTCH,IMM_HANDWRITING_TYPE_LOWER_CASE_DUTCH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_DUTCH,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_DUTCH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_NL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"nl-NL",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_DUTCH,GUI_VIRTUAL_KEYBOARD_DUTCH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_DUTCH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_T9_SWEDISH__) ||defined(__MMI_ZI_SWEDISH__) ||defined(__MMI_CSTAR_SWEDISH__)||defined(__MMI_GB_SWEDISH__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_SWEDISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_SWEDISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_SV,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sv-SE",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_SWEDISH,GUI_VIRTUAL_KEYBOARD_SWEDISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_SWEDISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_SWEDISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_SWEDISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_SV,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sv-SE",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_SWEDISH,GUI_VIRTUAL_KEYBOARD_SWEDISH,IMM_HANDWRITING_TYPE_LOWER_CASE_SWEDISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SWEDISH,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_SWEDISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_SV,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sv-SE",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_SWEDISH,GUI_VIRTUAL_KEYBOARD_SWEDISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_SWEDISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_SWEDISH__)
/*MultitapSWEDISH*/
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SWEDISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_SWEDISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_SV,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sv-SE",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_SWEDISH,GUI_VIRTUAL_KEYBOARD_SWEDISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_SWEDISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
/*Multitapswedish*/
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SWEDISH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_SWEDISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_SV,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sv-SE",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_SWEDISH,GUI_VIRTUAL_KEYBOARD_SWEDISH,IMM_HANDWRITING_TYPE_LOWER_CASE_SWEDISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SWEDISH,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_SWEDISH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_SV,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sv-SE",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_SWEDISH,GUI_VIRTUAL_KEYBOARD_SWEDISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_SWEDISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_T9_CROATIAN__) ||defined(__MMI_ZI_CROATIAN__) ||defined(__MMI_CSTAR_CROATIAN__) ||defined(__MMI_GB_CROATIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_CROATIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_CROATIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_SH,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"hr-HR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_CROATIAN,GUI_VIRTUAL_KEYBOARD_CROATIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_CROATIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_CROATIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_CROATIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_SH,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"hr-HR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_CROATIAN,GUI_VIRTUAL_KEYBOARD_CROATIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_CROATIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_CROATIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_CROATIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_SH,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"hr-HR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_CROATIAN,GUI_VIRTUAL_KEYBOARD_CROATIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_CROATIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_CROATIAN__)
/*MultitapCROATIAN*/
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_CROATIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_CROATIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_SH,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"hr-HR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_CROATIAN,GUI_VIRTUAL_KEYBOARD_CROATIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_CROATIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
/*Multitapcroatian*/
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_CROATIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_CROATIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_SH,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"hr-HR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_CROATIAN,GUI_VIRTUAL_KEYBOARD_CROATIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_CROATIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_CROATIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_CROATIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_SH,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"hr-HR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_CROATIAN,GUI_VIRTUAL_KEYBOARD_CROATIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_CROATIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_ZI_ROMANIAN__) ||defined(__MMI_T9_ROMANIAN__) ||defined(__MMI_CSTAR_ROMANIAN__) ||defined(__MMI_GB_ROMANIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_ROMANIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_ROMANIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_RO,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ro-RO",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_ROMANIAN,GUI_VIRTUAL_KEYBOARD_ROMANIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ROMANIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_ROMANIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_ROMANIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_RO,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ro-RO",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_ROMANIAN,GUI_VIRTUAL_KEYBOARD_ROMANIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_ROMANIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ROMANIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_ROMANIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_RO,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ro-RO",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_ROMANIAN,GUI_VIRTUAL_KEYBOARD_ROMANIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ROMANIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_ROMANIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ROMANIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_ROMANIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_RO,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ro-RO",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_ROMANIAN,GUI_VIRTUAL_KEYBOARD_ROMANIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ROMANIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ROMANIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_ROMANIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_RO,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ro-RO",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_ROMANIAN,GUI_VIRTUAL_KEYBOARD_ROMANIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_ROMANIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ROMANIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_ROMANIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_RO,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ro-RO",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_ROMANIAN,GUI_VIRTUAL_KEYBOARD_ROMANIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ROMANIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_T9_SLOVENIAN__) ||defined(__MMI_ZI_SLOVENIAN__) ||defined(__MMI_CSTAR_SLOVENIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_SLOVENIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_SLOVENIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_SL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sl-SI",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_SLOVENIAN,GUI_VIRTUAL_KEYBOARD_SLOVENIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_SLOVENIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_SLOVENIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_SLOVENIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_SL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sl-SI",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_SLOVENIAN,GUI_VIRTUAL_KEYBOARD_SLOVENIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_SLOVENIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SLOVENIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_SLOVENIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_SL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sl-SI",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_SLOVENIAN,GUI_VIRTUAL_KEYBOARD_SLOVENIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_SLOVENIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_SLOVENIAN__)
/*MultitapSLOVENIAN*/
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SLOVENIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_SLOVENIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_SL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sl-SI",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_SLOVENIAN,GUI_VIRTUAL_KEYBOARD_SLOVENIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_SLOVENIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
/*MultitapSLOVENIAN*/
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SLOVENIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_SLOVENIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_SL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sl-SI",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_SLOVENIAN,GUI_VIRTUAL_KEYBOARD_SLOVENIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_SLOVENIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SLOVENIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_SLOVENIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_SL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sl-SI",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_SLOVENIAN,GUI_VIRTUAL_KEYBOARD_SLOVENIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_SLOVENIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_T9_GREEK__) ||defined(__MMI_ZI_GREEK__) ||defined(__MMI_CSTAR_GREEK__) ||defined(__MMI_GB_GREEK__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_GREEK,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_GREEK,
    IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_EL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"el-GR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_GREEK,GUI_VIRTUAL_KEYBOARD_GREEK_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_GREEK)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_GREEK,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_GREEK,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_EL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"el-GR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_GREEK,GUI_VIRTUAL_KEYBOARD_GREEK,IMM_HANDWRITING_TYPE_LOWER_CASE_GREEK)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_GREEK,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_GREEK,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_EL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"el-GR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_GREEK,GUI_VIRTUAL_KEYBOARD_GREEK_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_GREEK)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_GREEK__)
/*MultitapGREEK*/
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_GREEK,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_GREEK,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_EL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"el-GR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_GREEK,GUI_VIRTUAL_KEYBOARD_GREEK_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_GREEK)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
/*Multitapgreek*/
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_GREEK,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_GREEK,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_EL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"el-GR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_GREEK,GUI_VIRTUAL_KEYBOARD_GREEK,IMM_HANDWRITING_TYPE_LOWER_CASE_GREEK)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_GREEK,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_GREEK,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_EL,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"el-GR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_GREEK,GUI_VIRTUAL_KEYBOARD_GREEK_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_GREEK)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_ZI_ARABIC__) ||defined(__MMI_T9_ARABIC__) ||defined(__MMI_CSTAR_ARABIC__) ||defined(__MMI_GB_ARABIC__)
{
    IMM_INPUT_MODE_SMART_ARABIC,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_ARABIC,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_AR,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ar-SA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_ARABIC,IMM_HANDWRITING_TYPE_ARABIC)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif

#if defined(__MMI_MULTITAP_ARABIC__)
/*MultitapArabic*/
{
    IMM_INPUT_MODE_MULTITAP_ARABIC,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_ARABIC,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_AR,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ar-SA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_ARABIC,IMM_HANDWRITING_TYPE_ARABIC)
#endif/*__MMI_TOUCH_SCREEN__*/
},

#if!defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
/*Arabicnumeric*/
{
    IMM_INPUT_MODE_ARABIC_NUMERIC,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE  | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_ARABIC_NUMERIC,
    IME_LANG_ATTR_NUMBERIC,
    IME_MODE_ATTR_DIRECT,
    IME_WRITING_LANG_AR,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ar-SA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_ARABIC_NUMERIC,IMM_HANDWRITING_TYPE_ARABIC)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
#endif

#if defined(__MMI_ZI_PERSIAN__) ||defined(__MMI_CSTAR_PERSIAN__) ||defined(__MMI_T9_PERSIAN__) ||defined(__MMI_GB_PERSIAN__)
{
    IMM_INPUT_MODE_SMART_PERSIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_PERSIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_PS,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ps-IR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_FARSI,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif

#if defined(__MMI_MULTITAP_PERSIAN__)
{
    IMM_INPUT_MODE_MULTITAP_PERSIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_PERSIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_PS,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ps-IR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_FARSI,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif

#if defined(__MMI_ZI_URDU__) ||defined(__MMI_T9_URDU__) ||defined(__MMI_GB_URDU__)
{
    IMM_INPUT_MODE_SMART_URDU,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_URDU,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_UR,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ur-PK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_URDU,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif

#if defined(__MMI_MULTITAP_URDU__)
{
    IMM_INPUT_MODE_MULTITAP_URDU,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_URDU,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_UR,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ur-PK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_URDU,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif

#if defined(__MMI_ZI_HINDI__) ||defined(__MMI_T9_HINDI__) ||defined(__MMI_CSTAR_HINDI__) ||defined(__MMI_GB_HINDI__)
{
    IMM_INPUT_MODE_SMART_HINDI,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_HINDI,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_HI,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"hi-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_INDIC_VK_HINDI__)
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_HINDI,IMM_HANDWRITING_TYPE_NONE)
#elif defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_HINDI,GUI_VIRTUAL_KEYBOARD_HINDI,IMM_HANDWRITING_TYPE_NONE)
#else/*__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__*/
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_HINDI,GUI_VIRTUAL_KEYBOARD_HINDI_CONS_MATRAS1,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__*/
#elif defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_INDIC_VK_HINDI__*/
},
#endif/*defined(__MMI_ZI_HINDI__) ||defined(__MMI_T9_HINDI__) ||defined(__MMI_CSTAR_HINDI__)*/

#ifdef __MMI_MULTITAP_HINDI__
{
    IMM_INPUT_MODE_MULTITAP_HINDI,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_HINDI,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_HI,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"hi-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_INDIC_VK_HINDI__)
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_HINDI,IMM_HANDWRITING_TYPE_NONE)
#elif defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_HINDI,GUI_VIRTUAL_KEYBOARD_HINDI,IMM_HANDWRITING_TYPE_NONE)
#else/*__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__*/
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_HINDI,GUI_VIRTUAL_KEYBOARD_HINDI_CONS_MATRAS1,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__*/
#elif defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_INDIC_VK_HINDI__*/
},
#endif/*__MMI_MULTITAP_HINDI__*/

#if defined(__MMI_ZI_TAMIL__) ||defined(__MMI_T9_TAMIL__)||defined(__MMI_GB_TAMIL__)
{
    IMM_INPUT_MODE_SMART_TAMIL,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_TAMIL,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_TA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ta-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_INDIC_VK_TAMIL__)
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
	IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_TAMIL,IMM_HANDWRITING_TYPE_NONE)
#else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_TAMIL,GUI_VIRTUAL_KEYBOARD_TAMIL_CONS_MATRAS1,IMM_HANDWRITING_TYPE_NONE)
#endif
#elif defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_INDIC_VK_TAMIL__*/
},
#endif/*defined(__MMI_ZI_TAMIL__)*/

#if defined(__MMI_MULTITAP_TAMIL__)
{
    IMM_INPUT_MODE_MULTITAP_TAMIL,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_TAMIL,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_TA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ta-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_INDIC_VK_TAMIL__)
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
	IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_TAMIL,IMM_HANDWRITING_TYPE_NONE)
#else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_TAMIL,GUI_VIRTUAL_KEYBOARD_TAMIL_CONS_MATRAS1,IMM_HANDWRITING_TYPE_NONE)
#endif
#elif defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_INDIC_VK_TAMIL__*/
},
#endif/*defined(__MMI_MULTITAP_TAMIL__)*/

#if defined(__MMI_ZI_BENGALI__) ||defined(__MMI_T9_BENGALI__) ||defined(__MMI_CSTAR_BENGALI__) ||defined(__MMI_GB_BENGALI__)
{
    IMM_INPUT_MODE_SMART_BENGALI,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_BENGALI,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_BE,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"be-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_INDIC_VK_BENGALI__)
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_BENGALI,IMM_HANDWRITING_TYPE_NONE)
#elif defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_BENGALI,GUI_VIRTUAL_KEYBOARD_BENGALI,IMM_HANDWRITING_TYPE_NONE)
#else/*__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__*/
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_BENGALI,GUI_VIRTUAL_KEYBOARD_BENGALI_CONS_MATRAS1,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__*/
#elif defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_INDIC_VK_BENGALI__*/
},
#endif/*defined(__MMI_ZI_BENGALI__)*/

#if defined(__MMI_MULTITAP_BENGALI__)
{
    IMM_INPUT_MODE_MULTITAP_BENGALI,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_BENGALI,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_BE,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"be-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_INDIC_VK_BENGALI__)
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_BENGALI,IMM_HANDWRITING_TYPE_NONE)
#elif defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_BENGALI,GUI_VIRTUAL_KEYBOARD_BENGALI,IMM_HANDWRITING_TYPE_NONE)
#else/*__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__*/
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_BENGALI,GUI_VIRTUAL_KEYBOARD_BENGALI_CONS_MATRAS1,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__*/
#elif defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_INDIC_VK_BENGALI__*/
},
#endif/*defined(__MMI_MULTITAP_BENGALI__)*/
#if defined(__MMI_ZI_ASSAMESE_) ||defined(__MMI_T9_ASSAMESE__)
{
    IMM_INPUT_MODE_SMART_ASSAMESE,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_ASSAMESE,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_AS,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"as-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_INDIC_VK_ASSAMESE__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_ASSAMESE_CONS_MATRAS1,IMM_HANDWRITING_TYPE_NONE)
#elif defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_INDIC_VK_ASSAMESE__*/
},
#endif/*defined(__MMI_ZI_ASSAMESE__)*/

#if defined(__MMI_MULTITAP_ASSAMESE__)
{
    IMM_INPUT_MODE_MULTITAP_ASSAMESE,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_ASSAMESE,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_AS,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"as-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_INDIC_VK_ASSAMESE__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_ASSAMESE_CONS_MATRAS1,IMM_HANDWRITING_TYPE_NONE)
#elif defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_INDIC_VK_ASSAMESE__*/
},
#endif/*defined(__MMI_MULTITAP_ASSAMESE__)*/

#if defined(__MMI_ZI_PUNJABI__) ||defined(__MMI_T9_PUNJABI__)||defined(__MMI_GB_PUNJABI__)
{
    IMM_INPUT_MODE_SMART_PUNJABI,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_PUNJABI,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_PA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"pa-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_INDIC_VK_PUNJABI__)
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
	IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_PUNJABI,IMM_HANDWRITING_TYPE_NONE)
#else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_PUNJABI,GUI_VIRTUAL_KEYBOARD_PUNJABI_CONS_MATRAS1,IMM_HANDWRITING_TYPE_NONE)
#endif
#elif defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_INDIC_VK_PUNJABI__*/
},
#endif/*defined(__MMI_ZI_PUNJABI__)*/

#if defined(__MMI_MULTITAP_PUNJABI__)
{
    IMM_INPUT_MODE_MULTITAP_PUNJABI,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_PUNJABI,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_PA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"pa-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_INDIC_VK_PUNJABI__)
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
	IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_PUNJABI,IMM_HANDWRITING_TYPE_NONE)
#else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_PUNJABI,GUI_VIRTUAL_KEYBOARD_PUNJABI_CONS_MATRAS1,IMM_HANDWRITING_TYPE_NONE)
#endif
#elif defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_INDIC_VK_PUNJABI__*/
},
#endif/*defined(__MMI_MULTITAP_PUNJABI__)*/

#if defined(__MMI_ZI_TELUGU__) ||defined(__MMI_T9_TELUGU__) ||defined(__MMI_GB_TELUGU__)
{
    IMM_INPUT_MODE_SMART_TELUGU,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_TELUGU,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_TE,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"te-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_INDIC_VK_TELUGU__)
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
	IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_TELUGU,IMM_HANDWRITING_TYPE_NONE)
#else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_TELUGU,GUI_VIRTUAL_KEYBOARD_TELUGU_CONS_MATRAS1,IMM_HANDWRITING_TYPE_NONE)
#endif
#elif defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_INDIC_VK_TELUGU__*/
},
#endif/*defined(__MMI_ZI_TELUGU__)*/

#if defined(__MMI_MULTITAP_TELUGU__)
{
    IMM_INPUT_MODE_MULTITAP_TELUGU,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_TELUGU,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_TE,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"te-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_INDIC_VK_TELUGU__)
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
	IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_TELUGU,IMM_HANDWRITING_TYPE_NONE)
#else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_TELUGU,GUI_VIRTUAL_KEYBOARD_TELUGU_CONS_MATRAS1,IMM_HANDWRITING_TYPE_NONE)
#endif
#elif defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_INDIC_VK_TELUGU__*/
},
#endif/*defined(__MMI_MULTITAP_TELUGU__)*/

#if defined(__MMI_ZI_MARATHI__) ||defined(__MMI_T9_MARATHI__)||defined(__MMI_GB_MARATHI__)
{
    IMM_INPUT_MODE_SMART_MARATHI,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_MARATHI,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_MR,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"mr-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_INDIC_VK_MARATHI__)
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
	IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_MARATHI,IMM_HANDWRITING_TYPE_NONE)
#else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_MARATHI,GUI_VIRTUAL_KEYBOARD_MARATHI_CONS_MATRAS1,IMM_HANDWRITING_TYPE_NONE)
#endif
#elif defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_INDIC_VK_MARATHI__*/
},
#endif/*defined(__MMI_ZI_MARATHI__)*/

#ifdef __MMI_MULTITAP_MARATHI__
{
    IMM_INPUT_MODE_MULTITAP_MARATHI,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_MARATHI,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_MR,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"mr-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_INDIC_VK_MARATHI__)
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
	IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_MARATHI,IMM_HANDWRITING_TYPE_NONE)
#else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_MARATHI,GUI_VIRTUAL_KEYBOARD_MARATHI_CONS_MATRAS1,IMM_HANDWRITING_TYPE_NONE)
#endif
#elif defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_INDIC_VK_MARATHI__*/
},
#endif/*__MMI_MULTITAP_MARATHI__*/

#if defined(__MMI_ZI_KANNADA__) ||defined(__MMI_T9_KANNADA__) ||defined(__MMI_CSTAR_KANNADA__)
{
    IMM_INPUT_MODE_SMART_KANNADA,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_KANNADA,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_KN,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"kn-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_INDIC_VK_KANNADA__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_KANNADA_CONS_MATRAS1,IMM_HANDWRITING_TYPE_NONE)
#elif defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_INDIC_VK_KANNADA__*/
},
#endif/*defined(__MMI_ZI_KANNADA__) ||defined(__MMI_T9_KANNADA__) ||defined(__MMI_CSTAR_KANNADA__)*/

#ifdef __MMI_MULTITAP_KANNADA__
{
    IMM_INPUT_MODE_MULTITAP_KANNADA,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_KANNADA,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_KN,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"kn-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_INDIC_VK_KANNADA__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_KANNADA_CONS_MATRAS1,IMM_HANDWRITING_TYPE_NONE)
#elif defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_INDIC_VK_KANNADA__*/
},
#endif/*__MMI_MULTITAP_KANNADA__*/

#if defined(__MMI_ZI_MALAYALAM__) ||defined(__MMI_T9_MALAYALAM__) ||defined(__MMI_CSTAR_MALAYALAM__)||defined(__MMI_GB_MALAYALAM__)
{
    IMM_INPUT_MODE_SMART_MALAYALAM,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_MALAYALAM,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_ML,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ml-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_INDIC_VK_MALAYALAM__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_MALAYALAM_CONS_MATRAS1,IMM_HANDWRITING_TYPE_NONE)
#elif defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_INDIC_VK_MALAYALAM__*/
},
#endif/*defined(__MMI_ZI_MALAYALAM__) ||defined(__MMI_T9_MALAYALAM__) ||defined(__MMI_CSTAR_MALAYALAM__)*/

#ifdef __MMI_MULTITAP_MALAYALAM__
{
    IMM_INPUT_MODE_MULTITAP_MALAYALAM,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_MALAYALAM,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_ML,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ml-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_INDIC_VK_MALAYALAM__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_MALAYALAM_CONS_MATRAS1,IMM_HANDWRITING_TYPE_NONE)
#elif defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_INDIC_VK_MALAYALAM__*/
},
#endif/*__MMI_MULTITAP_MALAYALAM__*/

#if defined (__MMI_GB_LAO__)
{
    IMM_INPUT_MODE_SMART_LAO,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC ,
    STR_INPUT_METHOD_SMART_LAO,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_LO,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)
"lo-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_LAO,IMM_HANDWRITING_TYPE_NONE)
#endif/*defined(__MMI_TOUCH_SCREEN__)*/
},
#endif/*__MMI_SMART_LAO__*/

#ifdef __MMI_MULTITAP_LAO__
{
    IMM_INPUT_MODE_MULTITAP_LAO,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_LAO,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_LO,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"lo-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_LAO,IMM_HANDWRITING_TYPE_NONE)
#endif/*defined(__MMI_TOUCH_SCREEN__)*/
},
#endif/*__MMI_MULTITAP_LAO__*/

#if defined(__MMI_T9_KHMER__) ||  defined(__MMI_GB_KHMER__)
{
    IMM_INPUT_MODE_SMART_KHMER,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_KHMER,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_KM,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"km-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_MULTITAP_KHMER__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_KHMER,IMM_HANDWRITING_TYPE_NONE)
#elif defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*__MMI_MULTITAP_KHMER__*/

#ifdef __MMI_MULTITAP_KHMER__
{
    IMM_INPUT_MODE_MULTITAP_KHMER,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_KHMER,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_KM,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"km-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_MULTITAP_KHMER__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_KHMER,IMM_HANDWRITING_TYPE_NONE)
#elif defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*__MMI_MULTITAP_KHMER__*/
#if defined(__MMI_ZI_MYANMAR__) ||defined(__MMI_T9_MYANMAR__) ||defined(__MMI_CSTAR_MYANMAR__) ||defined(__MMI_GB_MYANMAR__)
{
    IMM_INPUT_MODE_SMART_MYANMAR,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_MYANMAR,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_MY,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"my-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_MULTITAP_MYANMAR__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_MYANMAR,IMM_HANDWRITING_TYPE_NONE)
#elif defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_ZI_MYANMAR__) ||defined(__MMI_T9_MYANMAR__) ||defined(__MMI_CSTAR_MYANMAR__)*/

#ifdef __MMI_MULTITAP_MYANMAR__
{
    IMM_INPUT_MODE_MULTITAP_MYANMAR,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_MYANMAR,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_MY,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"my-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_MULTITAP_MYANMAR__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_MYANMAR,IMM_HANDWRITING_TYPE_NONE)
#elif defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*__MMI_MULTITAP_MYANMAR__*/


#if defined(__MMI_ZI_ORIYA__) ||defined(__MMI_T9_ORIYA__) ||defined(__MMI_CSTAR_ORIYA__)
{
    IMM_INPUT_MODE_SMART_ORIYA,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_ORIYA,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_OR,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"or-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_INDIC_VK_ORIYA__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_ORIYA_CONS_MATRAS1,IMM_HANDWRITING_TYPE_NONE)
#elif defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_INDIC_VK_ORIYA__*/

},
#endif/*defined(__MMI_ZI_ORIYA__) ||defined(__MMI_T9_ORIYA__) ||defined(__MMI_CSTAR_ORIYA__)*/
#ifdef __MMI_MULTITAP_ORIYA__
{
    IMM_INPUT_MODE_MULTITAP_ORIYA,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_ORIYA,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_OR,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"or-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_INDIC_VK_ORIYA__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_ORIYA_CONS_MATRAS1,IMM_HANDWRITING_TYPE_NONE)
#elif defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_INDIC_VK_ORIYA__*/
},
#endif/*__MMI_MULTITAP_ORIYA__*/
#if defined(__MMI_ZI_GUJARATI__) ||defined(__MMI_T9_GUJARATI__) ||defined(__MMI_CSTAR_GUJARATI__)||defined(__MMI_GB_GUJARATI__)
{
    IMM_INPUT_MODE_SMART_GUJARATI,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_GUJARATI,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_GU,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"gu-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_INDIC_VK_GUJARATI__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_GUJARATI_CONS_MATRAS1,IMM_HANDWRITING_TYPE_NONE)
#elif defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_INVALID
#endif/*__MMI_INDIC_VK_GUJARATI__*/
},
#endif/*__MMI_MULTITAP_GUJARATI__*/

#ifdef __MMI_MULTITAP_GUJARATI__
{
    IMM_INPUT_MODE_MULTITAP_GUJARATI,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_GUJARATI,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_GU,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"gu-IN",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_GUJARATI_CONS_MATRAS1,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*__MMI_MULTITAP_GUJARATI__*/

#if defined(__MMI_ZI_XHOSA__) ||defined(__MMI_T9_XHOSA__) ||defined(__MMI_CSTAR_XHOSA__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_XHOSA,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_XHOSA,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_XH,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"xh-ZA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_XHOSA,GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_XHOSA,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_XHOSA,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_XH,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"xh-ZA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_XHOSA,GUI_VIRTUAL_KEYBOARD_ENGLISH,IMM_HANDWRITING_TYPE_LOWER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_XHOSA,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_XHOSA,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_XH,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"xh-ZA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_XHOSA,GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_XHOSA__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_XHOSA,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_XHOSA,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_XH,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"xh-ZA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_XHOSA,GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_XHOSA,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_XHOSA,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_XH,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"xh-ZA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_XHOSA,GUI_VIRTUAL_KEYBOARD_ENGLISH,IMM_HANDWRITING_TYPE_LOWER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_XHOSA,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_XHOSA,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_XH,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"xh-ZA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_XHOSA,GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_ZI_SWAHILI__) ||defined(__MMI_T9_SWAHILI__) ||defined(__MMI_CSTAR_SWAHILI__) ||defined(__MMI_GB_SWAHILI__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_SWAHILI,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_SWAHILI,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_SW,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sw-TZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_SWAHILI,GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_SWAHILI,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_SWAHILI,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_SW,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sw-TZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_SWAHILI,GUI_VIRTUAL_KEYBOARD_ENGLISH,IMM_HANDWRITING_TYPE_LOWER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SWAHILI,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_SWAHILI,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_SW,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sw-TZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_SWAHILI,GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_SWAHILI__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SWAHILI,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_SWAHILI,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_SW,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sw-TZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_SWAHILI,GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SWAHILI,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_SWAHILI,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_SW,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sw-TZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_SWAHILI,GUI_VIRTUAL_KEYBOARD_ENGLISH,IMM_HANDWRITING_TYPE_LOWER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SWAHILI,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_SWAHILI,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_SW,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sw-TZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_SWAHILI,GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_ZI_AFRIKAANS__) ||defined(__MMI_T9_AFRIKAANS__) ||defined(__MMI_CSTAR_AFRIKAANS__)||defined(__MMI_GB_AFRIKAANS__) 
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_AFRIKAANS,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_AFRIKAANS,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_AF,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"af-NA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_AFRIKAANS,GUI_VIRTUAL_KEYBOARD_AFRIKAAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH)
#else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_AFRIKAANS,GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH)
#endif
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_AFRIKAANS,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_AFRIKAANS,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_AF,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"af-NA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_AFRIKAANS,GUI_VIRTUAL_KEYBOARD_AFRIKAAN,IMM_HANDWRITING_TYPE_LOWER_CASE_ENGLISH)
#else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_AFRIKAANS,GUI_VIRTUAL_KEYBOARD_ENGLISH,IMM_HANDWRITING_TYPE_LOWER_CASE_ENGLISH)
#endif
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_AFRIKAANS,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_AFRIKAANS,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_AF,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"af-NA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_AFRIKAANS,GUI_VIRTUAL_KEYBOARD_AFRIKAAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH)
#else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_AFRIKAANS,GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH)
#endif
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_AFRIKAANS__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_AFRIKAANS,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_AFRIKAANS,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_AF,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"af-NA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_AFRIKAANS,GUI_VIRTUAL_KEYBOARD_AFRIKAAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH)
#else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_AFRIKAANS,GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH)
#endif
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_AFRIKAANS,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_AFRIKAANS,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_AF,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"af-NA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_AFRIKAANS,GUI_VIRTUAL_KEYBOARD_AFRIKAAN,IMM_HANDWRITING_TYPE_LOWER_CASE_ENGLISH)
#else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_AFRIKAANS,GUI_VIRTUAL_KEYBOARD_ENGLISH,IMM_HANDWRITING_TYPE_LOWER_CASE_ENGLISH)
#endif
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_AFRIKAANS,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_AFRIKAANS,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_AF,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"af-NA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_AFRIKAANS,GUI_VIRTUAL_KEYBOARD_AFRIKAAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH)
#else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_AFRIKAANS,GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif


#if defined(__MMI_ZI_ZULU__) ||defined(__MMI_T9_ZULU__) ||defined(__MMI_CSTAR_ZULU__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_ZULU,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_ZULU,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_ZU,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"zu-SZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_ZULU,GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_ZULU,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_ZULU,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_ZU,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"zu-SZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_ZULU,GUI_VIRTUAL_KEYBOARD_ENGLISH,IMM_HANDWRITING_TYPE_LOWER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ZULU,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_ZULU,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_ZU,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"zu-SZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_ZULU,GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_ZULU__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ZULU,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_ZULU,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_ZU,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"zu-SZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_ZULU,GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ZULU,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_ZULU,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_ZU,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"zu-SZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_ZULU,GUI_VIRTUAL_KEYBOARD_ENGLISH,IMM_HANDWRITING_TYPE_LOWER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ZULU,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_ZULU,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_ZU,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"zu-SZ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_ZULU,GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_ZI_LITHUANIAN__) ||defined(__MMI_T9_LITHUANIAN__) ||defined(__MMI_CSTAR_LITHUANIAN__)||defined(__MMI_GB_LITHUANIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_LITHUANIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_LITHUANIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_LT,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"lt-LT",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_LITHUANIAN,GUI_VIRTUAL_KEYBOARD_LITHUANIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_LITHUANIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_LITHUANIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_LITHUANIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_LT,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"lt-LT",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_LITHUANIAN,GUI_VIRTUAL_KEYBOARD_LITHUANIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_LITHUANIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_LITHUANIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_LITHUANIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_LT,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"lt-LT",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_LITHUANIAN,GUI_VIRTUAL_KEYBOARD_LITHUANIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_LITHUANIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_LITHUANIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_LITHUANIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_LITHUANIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_LT,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"lt-LT",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_LITHUANIAN,GUI_VIRTUAL_KEYBOARD_LITHUANIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_LITHUANIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_LITHUANIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_LITHUANIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_LT,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"lt-LT",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_LITHUANIAN,GUI_VIRTUAL_KEYBOARD_LITHUANIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_LITHUANIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_LITHUANIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_LITHUANIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_LT,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"lt-LT",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_LITHUANIAN,GUI_VIRTUAL_KEYBOARD_LITHUANIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_LITHUANIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_ZI_LATVIAN__) ||defined(__MMI_T9_LATVIAN__) ||defined(__MMI_CSTAR_LATVIAN__) ||defined(__MMI_GB_LATVIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_LATVIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_LATVIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_LV,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"lv-LV",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_LATVIAN,GUI_VIRTUAL_KEYBOARD_LATVIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_LATVIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_LATVIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_LATVIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_LV,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"lv-LV",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_LATVIAN,GUI_VIRTUAL_KEYBOARD_LATVIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_LATVIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_LATVIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_LATVIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_LV,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"lv-LV",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_LATVIAN,GUI_VIRTUAL_KEYBOARD_LATVIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_LATVIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_LATVIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_LATVIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_LATVIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_LV,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"lv-LV",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_LATVIAN,GUI_VIRTUAL_KEYBOARD_LATVIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_LATVIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_LATVIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_LATVIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_LV,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"lv-LV",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_LATVIAN,GUI_VIRTUAL_KEYBOARD_LATVIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_LATVIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_LATVIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_LATVIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_LV,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"lv-LV",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_LATVIAN,GUI_VIRTUAL_KEYBOARD_LATVIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_LATVIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_ZI_ESTONIAN__) ||defined(__MMI_T9_ESTONIAN__) ||defined(__MMI_CSTAR_ESTONIAN__)||defined(__MMI_GB_ESTONIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_ESTONIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_ESTONIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_ET,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"et-EE",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_ESTONIAN,GUI_VIRTUAL_KEYBOARD_ESTONIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ESTONIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_ESTONIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_ESTONIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_ET,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"et-EE",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_ESTONIAN,GUI_VIRTUAL_KEYBOARD_ESTONIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_ESTONIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ESTONIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_ESTONIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_ET,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"et-EE",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_ESTONIAN,GUI_VIRTUAL_KEYBOARD_ESTONIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ESTONIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_ESTONIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ESTONIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_ESTONIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_ET,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"et-EE",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_ESTONIAN,GUI_VIRTUAL_KEYBOARD_ESTONIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ESTONIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ESTONIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_ESTONIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_ET,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"et-EE",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_ESTONIAN,GUI_VIRTUAL_KEYBOARD_ESTONIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_ESTONIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ESTONIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_ESTONIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_ET,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"et-EE",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_ESTONIAN,GUI_VIRTUAL_KEYBOARD_ESTONIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ESTONIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif


#if defined(__MMI_T9_ALBANIAN__) ||defined(__MMI_ZI_ALBANIAN__) ||defined(__MMI_CSTAR_ALBANIAN__) ||defined(__MMI_GB_ALBANIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_ALBANIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_ALBANIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_SQ,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sq-SQ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_ALBANIAN,GUI_VIRTUAL_KEYBOARD_ALBANIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ALBANIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_ALBANIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_ALBANIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_SQ,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sq-SQ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_ALBANIAN,GUI_VIRTUAL_KEYBOARD_ALBANIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_ALBANIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ALBANIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_ALBANIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_SQ,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sq-SQ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_ALBANIAN,GUI_VIRTUAL_KEYBOARD_ALBANIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ALBANIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif


#if defined(__MMI_MULTITAP_ALBANIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ALBANIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_ALBANIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_SQ,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sq-SQ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_ALBANIAN,GUI_VIRTUAL_KEYBOARD_ALBANIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ALBANIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ALBANIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_ALBANIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_SQ,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sq-SQ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_ALBANIAN,GUI_VIRTUAL_KEYBOARD_ALBANIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_ALBANIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ALBANIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_ALBANIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_SQ,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sq-SQ",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_ALBANIAN,GUI_VIRTUAL_KEYBOARD_ALBANIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ALBANIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_ZI_ARMENIAN__) ||defined(__MMI_T9_ARMENIAN__) ||defined(__MMI_CSTAR_ARMENIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_ARMENIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_ARMENIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_HY,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"hy-AM",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_ARMENIAN,GUI_VIRTUAL_KEYBOARD_ARMENIAN_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_ARMENIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_ARMENIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_HY,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"hy-AM",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_ARMENIAN,GUI_VIRTUAL_KEYBOARD_ARMENIAN,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ARMENIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_ARMENIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_HY,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"hy-AM",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_ARMENIAN,GUI_VIRTUAL_KEYBOARD_ARMENIAN,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_ARMENIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ARMENIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_ARMENIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_HY,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"hy-AM",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_ARMENIAN,GUI_VIRTUAL_KEYBOARD_ARMENIAN_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ARMENIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_ARMENIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_HY,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"hy-AM",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_ARMENIAN,GUI_VIRTUAL_KEYBOARD_ARMENIAN,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ARMENIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_ARMENIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_HY,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"hy-AM",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_ARMENIAN,GUI_VIRTUAL_KEYBOARD_ARMENIAN_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_ZI_GEORGIAN__) ||defined(__MMI_T9_GEORGIAN__) ||defined(__MMI_CSTAR_GEORGIAN__) ||defined(__MMI_GB_GEORGIAN__)
{
    IMM_INPUT_MODE_SMART_GEORGIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_GEORGIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_KA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ka-GE",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_GEORGIAN,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif

#if defined(__MMI_MULTITAP_GEORGIAN__)
{
    IMM_INPUT_MODE_MULTITAP_GEORGIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_GEORGIAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_KA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"ka-GE",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_GEORGIAN,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif

#if defined(__MMI_MULTITAP_ICELANDIC__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ICELANDIC,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_ICELANDIC,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_IS,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"is-IS",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_ICELANDIC,GUI_VIRTUAL_KEYBOARD_ICELANDIC_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ICELANDIC,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_ICELANDIC,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_IS,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"is-IS",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_ICELANDIC,GUI_VIRTUAL_KEYBOARD_ICELANDIC,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ICELANDIC,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_ICELANDIC,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_IS,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"is-IS",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_ICELANDIC,GUI_VIRTUAL_KEYBOARD_ICELANDIC_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif
#if defined(__MMI_ZI_ICELANDIC__) ||defined(__MMI_T9_ICELANDIC__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_ICELANDIC,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_ICELANDIC,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_IS,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"is-IS",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_ICELANDIC,GUI_VIRTUAL_KEYBOARD_ICELANDIC_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_ICELANDIC,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_ICELANDIC,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_IS,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"is-IS",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_ICELANDIC,GUI_VIRTUAL_KEYBOARD_ICELANDIC,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ICELANDIC,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_ICELANDIC,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_IS,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"is-IS",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_ICELANDIC,GUI_VIRTUAL_KEYBOARD_ICELANDIC_UPPERCASE,IMM_HANDWRITING_TYPE_NONE)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif


#if defined(__MMI_MULTITAP_SERBIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SERBIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_SERBIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_SR,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sr-SR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_SERBIAN,GUI_VIRTUAL_KEYBOARD_SERBIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_SERBIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)*/
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SERBIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_SERBIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_SR,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sr-SR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_SERBIAN,GUI_VIRTUAL_KEYBOARD_SERBIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_SERBIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SERBIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_SERBIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_SR,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sr-SR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_SERBIAN,GUI_VIRTUAL_KEYBOARD_SERBIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_SERBIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif/*(__MMI_MULTITAP_SERBIAN__)*/

#if defined(__MMI_T9_SERBIAN__) ||defined(__MMI_ZI_SERBIAN__) ||defined(__MMI_GB_SERBIAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_SERBIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_SERBIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_SR,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sr-SR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_SERBIAN,GUI_VIRTUAL_KEYBOARD_SERBIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_SERBIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_SERBIAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_SERBIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_SR,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sr-SR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_SERBIAN,GUI_VIRTUAL_KEYBOARD_SERBIAN,IMM_HANDWRITING_TYPE_LOWER_CASE_SERBIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SERBIAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_SERBIAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_SR,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"sr-SR",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_SERBIAN,GUI_VIRTUAL_KEYBOARD_SERBIAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_SERBIAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif


#if defined(__MMI_ZI_UK_ENGLISH__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_UK_ABC,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_UK_ABC,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_ENUK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"en-UK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_UK_ABC,GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_UK_ABC,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_UK_ABC,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_ENUK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"en-UK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_UK_ABC,GUI_VIRTUAL_KEYBOARD_ENGLISH,IMM_HANDWRITING_TYPE_LOWER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_UK_ABC,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_UK_ABC,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_ENUK,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"en-UK",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_UK_ABC,GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif





#if defined(__MMI_ZI_CA_FRENCH__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_CA_FRENCH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_CA_FRENCH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_FRCA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"fr-CA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_FRENCH,GUI_VIRTUAL_KEYBOARD_FRENCH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_FRENCH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_CA_FRENCH,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_CA_FRENCH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_FRCA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"fr-CA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_FRENCH,GUI_VIRTUAL_KEYBOARD_FRENCH,IMM_HANDWRITING_TYPE_LOWER_CASE_FRENCH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_CA_FRENCH,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_CA_FRENCH,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_MIXED_LANG_SUPPORT  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_FRCA,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"fr-CA",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_FRENCH,GUI_VIRTUAL_KEYBOARD_FRENCH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_FRENCH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif





#if defined(__MMI_ZI_MOLDOVAN__) ||defined(__MMI_T9_MOLDOVAN__) ||defined(__MMI_CSTAR_MOLDOVAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_MOLDOVAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_U_MOLDOVAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_MO,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"mo-MD",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_MOLDOVAN,GUI_VIRTUAL_KEYBOARD_MOLDOVAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_MALDOVAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_SMART_LOWERCASE_MOLDOVAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_L_MOLDOVAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_MO,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"mo-MD",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_UPPERCASE_MOLDOVAN,GUI_VIRTUAL_KEYBOARD_MOLDOVAN,IMM_HANDWRITING_TYPE_LOWER_CASE_MALDOVAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_SMART_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_MOLDOVAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_SMART_FIRST_U_MOLDOVAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_SMART,
    IME_WRITING_LANG_MO,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"mo-MD",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_SMART_LOWERCASE_MOLDOVAN,GUI_VIRTUAL_KEYBOARD_MOLDOVAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_MALDOVAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_SMART_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_MULTITAP_MOLDOVAN__)
#if defined(__MMI_ALPHABETIC_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_MOLDOVAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_U_MOLDOVAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_MO,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"mo-MD",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_MOLDOVAN,GUI_VIRTUAL_KEYBOARD_MOLDOVAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_MALDOVAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_MOLDOVAN,
    IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH,
    STR_INPUT_METHOD_MULTITAP_L_MOLDOVAN,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_MO,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"mo-MD",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_MOLDOVAN,GUI_VIRTUAL_KEYBOARD_MOLDOVAN,IMM_HANDWRITING_TYPE_LOWER_CASE_MALDOVAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_MOLDOVAN,
    IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC,
    STR_INPUT_METHOD_MULTITAP_FIRST_U_MOLDOVAN,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_TITLECASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_MO,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"mo-MD",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_MOLDOVAN,GUI_VIRTUAL_KEYBOARD_MOLDOVAN_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_MALDOVAN)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif/*defined(__MMI_MULTITAP_FIRST_UPPERCASE__)*/
#endif

#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC_NO_NUMERIC,
0,
    STR_INPUT_METHOD_MULTITAP_U_ABC,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_UPPERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_ABC,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC_NO_NUMERIC,GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE,IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC_NO_NUMERIC,
0,
    STR_INPUT_METHOD_MULTITAP_L_ABC,
    IME_LANG_ATTR_ALPHABETIC,
    IME_MODE_ATTR_LOWERCASE  | IME_MODE_ATTR_MULTITAP,
    IME_WRITING_LANG_ABC,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC_NO_NUMERIC,GUI_VIRTUAL_KEYBOARD_ENGLISH,IMM_HANDWRITING_TYPE_LOWER_CASE_ENGLISH)
#endif/*__MMI_TOUCH_SCREEN__*/
},
#endif
/*    IMM_INPUT_MODE_123*/
{
    IMM_INPUT_MODE_123_SYMBOLS,
    IMM_INPUT_TYPE_ENGLISH_SENTENCE | IMM_INPUT_TYPE_SENTENCE |IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_QUICK_SEARCH | IMM_INPUT_TYPE_EMAIL | IMM_INPUT_TYPE_URL | IMM_INPUT_TYPE_NUMERIC_SYMBOL | IMM_INPUT_TYPE_ASCII_CHAR,
    STR_INPUT_METHOD_NUMERIC,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_NUMBERIC,
    IME_MODE_ATTR_DIRECT,
    IME_WRITING_LANG_123,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"123",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_EN_123SYM_1,IMM_HANDWRITING_TYPE_NUMBER)
    #else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_NUMBER,IMM_HANDWRITING_TYPE_NUMBER)
    #endif
#endif/*__MMI_TOUCH_SCREEN__*/
},
/*    IMM_INPUT_MODE_123*/
{
    IMM_INPUT_MODE_123,
    IMM_INPUT_TYPE_NUMERIC,
    STR_INPUT_METHOD_NUMERIC,
    IME_LANG_ATTR_ENGLISH_ONLY  | IME_LANG_ATTR_NUMBERIC,
    IME_MODE_ATTR_DIRECT,
    IME_WRITING_LANG_123,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"123",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
#if defined(__MMI_IME_FTE_ENHANCE__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY,IMM_HANDWRITING_TYPE_NUMBER)
#else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY,IMM_HANDWRITING_TYPE_NUMBER)
#endif
#endif/*__MMI_TOUCH_SCREEN__*/
},

{
    IMM_INPUT_MODE_SIGNED_123,
    IMM_INPUT_TYPE_SIGNED_NUMERIC,
    STR_INPUT_METHOD_NUMERIC,
    IME_LANG_ATTR_NUMBERIC  | IME_LANG_ATTR_SYMBOLIC,
    IME_MODE_ATTR_DIRECT,
    IME_WRITING_LANG_123,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
#if defined(__MMI_IME_FTE_ENHANCE__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY,IMM_HANDWRITING_TYPE_NUMBER)
#else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_NUMBER,IMM_HANDWRITING_TYPE_NUMBER)
#endif
#endif/*__MMI_TOUCH_SCREEN__*/

},
{
    IMM_INPUT_MODE_SIGNED_FLOAT_123,
    IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC,
    STR_INPUT_METHOD_NUMERIC,
    IME_LANG_ATTR_NUMBERIC  | IME_LANG_ATTR_SYMBOLIC,
    IME_MODE_ATTR_DIRECT,
    IME_WRITING_LANG_123,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
#if defined(__MMI_IME_FTE_ENHANCE__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY,IMM_HANDWRITING_TYPE_NUMBER)
#else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_NUMBER,IMM_HANDWRITING_TYPE_NUMBER)
#endif
#endif/*__MMI_TOUCH_SCREEN__*/

},
{
    IMM_INPUT_MODE_FLOAT_123,
    IMM_INPUT_TYPE_DECIMAL_NUMERIC,
    STR_INPUT_METHOD_NUMERIC,
    IME_LANG_ATTR_NUMBERIC  | IME_LANG_ATTR_SYMBOLIC,
    IME_MODE_ATTR_DIRECT,
    IME_WRITING_LANG_123,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
#if defined(__MMI_IME_FTE_ENHANCE__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY,IMM_HANDWRITING_TYPE_NUMBER)
#else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_NUMBER_DOT_TRAY,IMM_HANDWRITING_TYPE_NUMBER)
#endif
#endif/*__MMI_TOUCH_SCREEN__*/

},
{
    IMM_INPUT_MODE_PHONE_NUMBER,
    IMM_INPUT_TYPE_PHONE_NUMBER,
    STR_INPUT_METHOD_NUMERIC,
    IME_LANG_ATTR_NUMBERIC  | IME_LANG_ATTR_SYMBOLIC,
    IME_MODE_ATTR_MULTITAP  | IME_MODE_ATTR_DIRECT,
    IME_WRITING_LANG_123,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_PHONE_NUMBER,IMM_HANDWRITING_TYPE_NUMBER)
#endif/*__MMI_TOUCH_SCREEN__*/

},
{
    IMM_INPUT_MODE_PHONE_NUMBER_WILDCHAR,
    IMM_INPUT_TYPE_PHONE_NUMBER_WILDCHAR,
    STR_INPUT_METHOD_NUMERIC,
    IME_LANG_ATTR_NUMBERIC  | IME_LANG_ATTR_SYMBOLIC,
    IME_MODE_ATTR_MULTITAP  | IME_MODE_ATTR_DIRECT,
    IME_WRITING_LANG_123,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_PHONE_NUMBER_WILDCHAR,IMM_HANDWRITING_TYPE_NUMBER)
#endif/*__MMI_TOUCH_SCREEN__*/

},
{
    IMM_INPUT_MODE_SIM_NUMERIC,
    IMM_INPUT_TYPE_SIM_NUMERIC,
    STR_INPUT_METHOD_NUMERIC,
    IME_LANG_ATTR_NUMBERIC  | IME_LANG_ATTR_SYMBOLIC,
    IME_MODE_ATTR_MULTITAP  | IME_MODE_ATTR_DIRECT,
    IME_WRITING_LANG_123,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
#if defined(__MMI_IME_FTE_ENHANCE__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_SIM_NUMERIC,IMM_HANDWRITING_TYPE_NUMBER)
#else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_PHONE_NUMBER,IMM_HANDWRITING_TYPE_NUMBER)
#endif
#endif/*__MMI_TOUCH_SCREEN__*/

},
{
    IMM_INPUT_MODE_KEYPAD_NUMERIC,
    IMM_INPUT_TYPE_KEYPAD_NUMERIC,
    STR_INPUT_METHOD_NUMERIC,
    IME_LANG_ATTR_NUMBERIC  | IME_LANG_ATTR_SYMBOLIC,
    IME_MODE_ATTR_DIRECT,
    IME_WRITING_LANG_123,
#if defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)|| defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
"",
#endif/*defined(__MMI_PREFER_WRITING_LANG__) ||defined(__MMI_MIXED_LANG_SUPPORT__)*/
#if defined(__MMI_TOUCH_SCREEN__)
#if defined(__MMI_IME_FTE_ENHANCE__)
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_KEYPAD_NUMERIC,IMM_HANDWRITING_TYPE_NUMBER)
#else
    IME_HAND_WRITING_ATTRIB(MMI_FALSE,IME_HAN_WRITING_INVALID_INPUT_MODE,GUI_VIRTUAL_KEYBOARD_PHONE_NUMBER,IMM_HANDWRITING_TYPE_NUMBER)
#endif
#endif/*__MMI_TOUCH_SCREEN__*/

},
/*EndofArray*/
{
(    IMM_INPUT_MODE_MAX_NUM),
(0xff),
(0xff),
(0xff),
(0xff)
},
};

const sIMEModeDetails mtk_gIMEQSearchModeArray[] =
{
/*EndofArray*/
{
( IMM_INPUT_MODE_MAX_NUM ),
(0xff),
(0xff),
(0xff),
(0xff),
},
};

#if defined(__MMI_T9__)

#if defined(__MMI_T9_V7__)
const sIMEModuleDetails mtk_gIMEModule=T9V7;
#elif defined(__MMI_T9_V7_4__)
const sIMEModuleDetails mtk_gIMEModule=T9V7_4;
#elif defined(__MMI_XT9__)
const sIMEModuleDetails mtk_gIMEModule=XT9;
#endif

#elif defined(__MMI_ZI__)
const sIMEModuleDetails mtk_gIMEModule=ZiV6;
#else
const sIMEModuleDetails mtk_gIMEModule = IME_OTHERS;
#endif



//__CUSTPACK_MULTIBINTerryEND
