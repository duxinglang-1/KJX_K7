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
 *  Gsm7BitNationalLang.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _GSM_7Bit_National_Lang_H
#define _GSM_7Bit_National_Lang_H

#include "MMIDataType.h"
#include "ems.h"

#include "kal_general_types.h"
#include "gui_data_types.h"

typedef enum
{
    EMS_DEFAULT_ONLY = 0,
    EMS_SINGLE_SHIFT_ONLY,
    EMS_LOCK_SHIFT_ONLY,
    EMS_BOTH_TABLE,
    EMS_AUTO_DETECTION
} gui_ems_table_mechanism_enum;

#ifdef __SMS_R8_NATION_LANGUAGE__
typedef struct _GUI_EMS_AUTO_DETECTION
{
    S32 national_char;
    S32 only_in_default;
    S32 only_not_in_locking;
    S32 in_ext_and_national;
} mmi_7bit_auto_detection_struct;
#endif /* __SMS_R8_NATION_LANGUAGE__ */

typedef struct 
{
    S32 ucs2_count;
    S32 gsm_count;
    S32 gsm_ext_count;

#ifdef __SMS_R8_NATION_LANGUAGE__
    mmi_7bit_auto_detection_struct auto_detection;
#endif
} mmi_7bit_counter_struct;

/* please modify this macro to use according table choose mechanism 
 * at the project makefile, add:
 * "SMS_R8_TABLE_MECHANISM = SMS_R8_SINGLE    #SMS_R8_DEFAULT or SMS_R8_LOCKING or SMS_R8_SINGLE or SMS_R8_BOTH or SMS_R8_AUTO"
 * at option.mak, add:
 * "ifdef SMS_R8_TABLE_MECHANISM
       COM_DEFS += __$(strip $(SMS_R8_TABLE_MECHANISM))__
   else
       COM_DEFS += __SMS_R8_DEFAULT__
   endif"
 * change the SMS_R8_TABLE_MECHANISM value to customize the table mechanism.
 */
 
#ifdef __SMS_R8_NATION_LANGUAGE__
    #if defined(__SMS_R8_SINGLE__)
    #define DEFAULT_GSM_NATIONAL_TABLE_MECHANISM    EMS_SINGLE_SHIFT_ONLY
    #elif defined(__SMS_R8_LOCKING__)
    #define DEFAULT_GSM_NATIONAL_TABLE_MECHANISM    EMS_LOCK_SHIFT_ONLY
    #elif defined(__SMS_R8_BOTH__)
    #define DEFAULT_GSM_NATIONAL_TABLE_MECHANISM    EMS_BOTH_TABLE
    #elif defined(__SMS_R8_AUTO__)
    #define DEFAULT_GSM_NATIONAL_TABLE_MECHANISM    EMS_AUTO_DETECTION
    #elif defined(__SMS_R8_DEFAULT__)
    #define DEFAULT_GSM_NATIONAL_TABLE_MECHANISM    EMS_DEFAULT_ONLY
    #else
    #define DEFAULT_GSM_NATIONAL_TABLE_MECHANISM    EMS_SINGLE_SHIFT_ONLY
    #endif
#else /* __SMS_R8_NATION_LANGUAGE__ */
    #define DEFAULT_GSM_NATIONAL_TABLE_MECHANISM    EMS_DEFAULT_ONLY
#endif /* __SMS_R8_NATION_LANGUAGE__ */

/*after makefile is ready, this code should be removed */
#if (!defined(__SMS_R8_SINGLE__) && !defined(__SMS_R8_LOCKING__) && !defined(__SMS_R8_BOTH__) \
     && !defined(__SMS_R8_AUTO__) && !defined(__SMS_R8_DEFAULT__))

    #undef DEFAULT_GSM_NATIONAL_TABLE_MECHANISM

    #if (defined(AMBER38_DEMO_BB) && defined(__FLAVOR_NOT_PRESENT__))
    #define DEFAULT_GSM_NATIONAL_TABLE_MECHANISM    EMS_LOCK_SHIFT_ONLY
    #elif (defined(LIBRA35_DEMO_BB) && defined(__FLAVOR_NOT_PRESENT__))
    #define DEFAULT_GSM_NATIONAL_TABLE_MECHANISM    EMS_AUTO_DETECTION
    #else
    #define DEFAULT_GSM_NATIONAL_TABLE_MECHANISM    EMS_SINGLE_SHIFT_ONLY
    #endif
#endif

#ifdef __SMS_R8_NATION_LANGUAGE__
extern void mmi_7bit_set_table_mechanism(gui_ems_table_mechanism_enum m);
extern gui_ems_table_mechanism_enum mmi_7bit_get_table_mechanism(void);
extern EMSNationalLanguageType mmi_7bit_get_national_lang(void);
extern void mmi_7bit_get_national_lang_table(EMSNationalLanguage *l);
extern void mmi_7bit_set_national_lang(EMSNationalLanguageType t);
extern void mmi_7bit_set_national_lang_table(EMSNationalLanguage *l);
extern S32 mmi_7bit_check_gsm_by_nl_table(U16 c, EMSNationalLanguageType t);
extern S32 mmi_7bit_check_gsm_ext_character_by_nl_table(U16 c, EMSNationalLanguageType t);
#endif /* __SMS_R8_NATION_LANGUAGE__ */ 

extern S32 mmi_7bit_check_gsm(U16 c);
extern S32 mmi_7bit_check_gsm_ext_character(U16 c);
/* the _default API only use the default table even if the R8 feature is open */
extern S32 mmi_7bit_check_gsm_default(U16 c);
extern S32 mmi_7bit_check_gsm_ext_character_default(U16 c);


extern S32 mmi_7bit_ucs2_to_gsm_char(U16 c);
extern S32 mmi_7bit_ucs2_to_gsm_ext_char(U16 c);
extern S32 mmi_7bit_gsm_to_ucs2_char(U8 c);
extern S32 mmi_7bit_gsm_ext_to_ucs2_char(U8 c);

/* the _default API only use the default table even if the R8 feature is open */
extern S32 mmi_7bit_ucs2_to_gsm_char_default(U16 c);
extern S32 mmi_7bit_ucs2_to_gsm_ext_char_default(U16 c);
extern S32 mmi_7bit_gsm_to_ucs2_char_default(U8 c);
extern S32 mmi_7bit_gsm_ext_to_ucs2_char_default(U8 c);

extern S32 mmi_7bit_gsm_to_ucs2_string(
        U8 *str_in,
        U8 *str_out,
        U32 in_count,
        U32 *out_count,
        U16 not_found_char,
        U16 (*convert_not_found)(U8),
        S32 add_ESC);

extern S32 mmi_7bit_ucs2_to_gsm_string(
        U8 *str_in,
        U8 *str_out,
        U32 in_count,
        U32 *out_count,
        U8 not_found_char,
        U8 (*convert_not_found)(U16),
        S32 added_ESC);

extern S32 mmi_7bit_ucs2_exchange_by_new_table(
        U8 *str_in,
        U8 *str_out,
        U32 in_count,
        U32 *out_count,
        EMSNationalLanguage *old_l,
        EMSNationalLanguage *new_l,
        U16 not_found_char,
        U16 (*convert_not_found)(U16));

#ifdef __SMS_R8_NATION_LANGUAGE__
extern void mmi_7bit_update_character_type(mmi_7bit_auto_detection_struct *auto_detection, UI_character_type c, MMI_BOOL b_add);
extern void mmi_7bit_choose_national_table(mmi_7bit_auto_detection_struct *auto_detection, EMSNationalLanguage *l);
extern MMI_BOOL mmi_7bit_test_gsm_character_in_all_table(UI_character_type c);
#endif

extern void mmi_7bit_counter_init(U8* string);
extern void mmi_7bit_counter_add(U8 *string, U16 c, S32 b_only_restore);
extern void mmi_7bit_counter_delete(U8 *string, U16 c, S32 b_only_restore);
extern mmi_7bit_counter_struct* mmi_7bit_counter_get_info(void);

extern kal_uint16 gui_ems_ucs2_to_nl_callback(EMSNationalLanguage lang, kal_uint8 *src, kal_uint8 *dest, kal_uint16 len, kal_uint8 seg_num);
extern kal_uint16 gui_ems_nl_to_ucs2_callback(EMSNationalLanguage lang, kal_uint8 *src, kal_uint8 *dest, kal_uint16 len, kal_uint8 seg_num);

#endif /* _GSM_7Bit_National_Lang_H */ 


