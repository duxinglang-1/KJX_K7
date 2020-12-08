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
 *    ImeQwertyProt.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   header file for framework qwerty module
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MMI_IME_QWERTY_PROT_H__
#define __MMI_IME_QWERTY_PROT_H__

#include "MMI_features.h"
    #include "MMIDataType.h"
    #include "kal_general_types.h"
    #include "gui_data_types.h"
/*****************************************************************************
 * Defines
 *****************************************************************************/

#define MMI_QWERTY_MAKE_TRANSLATED_CODE(func, ch) ((U32)((((U32)(func))<<16) | (((U32)(ch)) & 0xFFFF))) 


/*****************************************************************************
 * Typedef
 *****************************************************************************/

/*****************************************************************************
 * Global Functions
 *****************************************************************************/
extern void mmi_imm_qwerty_init(void);

extern MMI_BOOL mmi_imm_qwerty_is_special_key(S16 mmi_key_code);

extern S16 mmi_imm_qwerty_get_opposite_key_code(S16 mmi_key_code);

extern U32 mmi_imm_qwerty_get_translated_key_code_of_current_lang(S16 mmi_key_code, U32 switch_flags);

extern U32 mmi_imm_qwerty_get_multitap_chars(S16 mmi_key_code, U32 switch_flags, UI_character_type string[], U32 max_size);

extern MMI_BOOL mmi_imm_qwerty_is_valid_special_key_of_current_lang(U32 special_flag);

extern MMI_BOOL mmi_imm_qwerty_is_valid_character_by_mmi_key(S16 mmi_key_code, UI_character_type char_code);
extern U32 mmi_imm_qwerty_get_supported_chars(S16 mmi_key_code, UI_character_type string[], U32 buf_size);

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
extern MMI_BOOL mmi_imm_qwerty_custom_update_special_key_status(S16 key_code,
                                                                S16 key_type,
                                                                U32 *special_key_flag,
                                                                U32 *special_key_lock_flag);
#endif

#endif /* __MMI_IME_QWERTY_PROT_H__ */ 

