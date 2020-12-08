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
 *    Imm_qwerty.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Language resource of qwerty keypad support
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "MMI_features.h"
     
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
     
#include "ImeGprot.h"
#include "ImmProt.h"
#include "Imc.h"
#include "ImeQwertyProt.h"
     
#include "Imc.h"

#ifdef __MMI_IME_PLUG_IN__
#include "ImeSDKGprot.h"
#include "ImeSDKProt.h"
#endif

/*****************************************************************************
 * Defines
 *****************************************************************************/

/*****************************************************************************
 * Typedef
 *****************************************************************************/

/*****************************************************************************
 * Global variables
 *****************************************************************************/
extern mmi_imm_qwerty_lang_struct g_qwerty_lang_table[];

extern mmi_imm_qwerty_key_struct g_qwerty_lang_table_common_keys[];

extern const S16 g_qwerty_opposite_key_table[][2];

extern const S16 g_qwerty_special_key[];
extern MMI_BOOL mmi_ime_multitap_vendor_change_mode( const sIMEModeDetails *mode_details_ptr, U32 reserved );
extern U32 mmi_ime_word_engine_qwerty_get_multitap_chars(S16 mmi_key_code, U32 switch_flags, UI_character_type string[], U32 max_size);
/*****************************************************************************
 * Local variables
 *****************************************************************************/

static mmi_imm_qwerty_key_struct_p g_mmi_imm_qwerty_current_lang_table_ptr = NULL;


/*****************************************************************************
 * Local functions
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_imm_qwerty_init
 * DESCRIPTION
 *  Initialize qwerty language module
 * PARAMETERS
 * RETURNS
 *  Opposite mmi key code
 *****************************************************************************/
void mmi_imm_qwerty_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_imm_qwerty_change_lang(IME_WRITING_LANG_ABC);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imm_qwerty_get_opposite_key_code
 * DESCRIPTION
 *  Get opposited mmi key code
 * PARAMETERS
 * RETURNS
 *  Opposite mmi key code
 *****************************************************************************/
S16 mmi_imm_qwerty_get_opposite_key_code(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; g_qwerty_opposite_key_table[i][0] != KEY_INVALID; i++)
    {
        if (g_qwerty_opposite_key_table[i][0] == mmi_key_code)
        {
            return g_qwerty_opposite_key_table[i][1];
        }
        else if (g_qwerty_opposite_key_table[i][1] == mmi_key_code)
        {
            return g_qwerty_opposite_key_table[i][0];
        }
    }

    return mmi_key_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imm_qwerty_get_translated_key_code_of_current_lang
 * DESCRIPTION
 *  Get translated key code of current qwerty language
 * PARAMETERS
 * RETURNS
 *  Translated key code
 *****************************************************************************/
U32 mmi_imm_qwerty_get_translated_key_code_of_current_lang(S16 mmi_key_code, U32 switch_flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; g_mmi_imm_qwerty_current_lang_table_ptr[i].mmi_key_code != KEY_INVALID; i++)
    {
        if (g_mmi_imm_qwerty_current_lang_table_ptr[i].mmi_key_code == mmi_key_code)
        {
            for (j = 0; g_mmi_imm_qwerty_current_lang_table_ptr[i].attributes[j].translated_code != 0; j++)
            {
                if (switch_flags == 0 && g_mmi_imm_qwerty_current_lang_table_ptr[i].attributes[j].switch_flags == 0)
                {
                    return g_mmi_imm_qwerty_current_lang_table_ptr[i].attributes[j].translated_code;
                }
                else if (g_mmi_imm_qwerty_current_lang_table_ptr[i].attributes[j].switch_flags & switch_flags)
                {
                    return g_mmi_imm_qwerty_current_lang_table_ptr[i].attributes[j].translated_code;
                }
            }

            break;
        }
    }

    for (i = 0; g_qwerty_lang_table_common_keys[i].mmi_key_code != KEY_INVALID; i++)
    {
        if (g_qwerty_lang_table_common_keys[i].mmi_key_code == mmi_key_code)
        {
            for (j = 0; g_qwerty_lang_table_common_keys[i].attributes[j].translated_code != 0; j++)
            {
                if (switch_flags == 0 && g_qwerty_lang_table_common_keys[i].attributes[j].switch_flags == 0)
                {
                    return g_qwerty_lang_table_common_keys[i].attributes[j].translated_code;
                }
                else if (g_qwerty_lang_table_common_keys[i].attributes[j].switch_flags & switch_flags)
                {
                    return g_qwerty_lang_table_common_keys[i].attributes[j].translated_code;
                }
            }

            break;
        }
    }

    return MMI_FRM_QWERTY_INVALID_TRANSLATED_CODE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imm_qwerty_get_keymap_by_language
 * DESCRIPTION
 *  To get one language mapping symbols for the specific key 
 * PARAMETERS
 *  search_key_code         :       [in]        the key code to query
 *  search_lang             :       [in]        the language to query
 *  string                  :       [out]       the array to contain the mapping symbols,
 *                                             
 * RETURNS
 *  U32			    :       number of the mapping symbols
 *****************************************************************************/
U32 mmi_imm_qwerty_get_keymap_by_language(S16 search_key_code, mmi_imm_support_writing_lang_enum search_lang, UI_character_type string[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j, k,index;
    U32 count = 0;
    U32 mapping_number = 0 ;
    S16 key_code = search_key_code;
    UI_character_type char_code;
    MMI_BOOL add_flag = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(NULL != string );
    memset(string, 0, sizeof(UI_character_type));
    if (search_key_code >= KEY_0 && search_key_code <= KEY_9)
    {
        key_code = mmi_imm_qwerty_get_opposite_key_code(search_key_code);
    }
    
    for (i = 0; g_qwerty_lang_table[i].lang != IME_WRITING_LANG_NONE; i++)
    {
        if (g_qwerty_lang_table[i].lang == search_lang)
        {
                for (j = 0; g_qwerty_lang_table[i].qwerty_table[j].mmi_key_code != KEY_INVALID; j++)
                {
                    if (g_qwerty_lang_table[i].qwerty_table[j].mmi_key_code == key_code)  
                    {
                        for (k = 0; g_qwerty_lang_table[i].qwerty_table[j].attributes[k].translated_code != 0; k++)
                        {
                            if (!(g_qwerty_lang_table[i].qwerty_table[j].attributes[k].switch_flags & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_CAPSLOCK))
                            {
                                    char_code = MMI_QWERTY_GET_UCS2_CODE(g_qwerty_lang_table[i].qwerty_table[j].attributes[k].translated_code);

                                    for(index = 0; string[index] != 0; index++)
                                    {
                                        if (string[index] == char_code)
                                        {
                                            add_flag = MMI_FALSE;
                                        }
                                    }        
                                    if (add_flag)
                                    {
                                        string[count++] = char_code;
                                        string[count] = 0;
                                        mapping_number++;
                                    }
                            }
                    
                        }
						break;
                    }
                }
				break;
        }
   
    }

    return mapping_number;


}

#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) &&defined(__MMI_IME_V3__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imm_qwerty_change_group_letters_format
 * DESCRIPTION
 *  change the group letter format to the vendor requries
 * PARAMETERS
 *   void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imm_qwerty_change_group_letters_format(void)
{
    U16 i,j=0,k;
    UI_character_type *index;
    for(i = 0; i < MMI_IMM_QWERTY_MAX_LETTER_GROUPS; i++)
    {
        index = g_mmi_imm_cur_lang_group_letter_table[i];
        k = 0;
        while(index[k] != 0)
        {
            g_mmi_imm_group_letter_set[j++] = index[k++];
        }
		if(k != 0)  //only insert one zero bettwen two group
		{
			g_mmi_imm_group_letter_set[j++] = 0;
		}
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imm_qwerty_get_group_letters_for_cur_lang
 * DESCRIPTION
 *  Get group letters for current language
 * PARAMETERS
    search_lang             :       [in]        the language to query
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_imm_qwerty_get_group_letters_for_cur_lang(mmi_imm_support_writing_lang_enum search_lang)
{

    U16 index, i, count = 0;
    UI_character_type *group_letter_ptr = NULL;
    for(index = KEY_A; index <= KEY_Z; index++)
    {
        group_letter_ptr = g_mmi_imm_cur_lang_group_letter_table[index-KEY_A];
        count = mmi_imm_qwerty_get_keymap_by_language(index, search_lang, group_letter_ptr);
    }

    for(i = 0; i < 2; i++)  /*for KEY_PERIOD and key_0*/
    {
        group_letter_ptr = g_mmi_imm_cur_lang_group_letter_table[++index];
        count += mmi_imm_qwerty_get_keymap_by_language(++index, search_lang, group_letter_ptr);
    }
 
mmi_imm_qwerty_change_group_letters_format();

}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_imm_qwerty_get_multitap_chars
 * DESCRIPTION
 *  Get multitap characters of a qwerty key
 * PARAMETERS
 * RETURNS
 *  Number of multitap characters
 *****************************************************************************/
U32 mmi_imm_qwerty_get_multitap_chars(S16 mmi_key_code, U32 switch_flags, UI_character_type string[], U32 max_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    U32 count = 0;
    UI_character_type char_code;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; g_mmi_imm_qwerty_current_lang_table_ptr[i].mmi_key_code != KEY_INVALID && count < max_size; i++)
    {
        if (g_mmi_imm_qwerty_current_lang_table_ptr[i].mmi_key_code == mmi_key_code)
        {
            for (j = 0; g_mmi_imm_qwerty_current_lang_table_ptr[i].attributes[j].translated_code != 0 && count < max_size; j++)
            {
                if (switch_flags == 0 && g_mmi_imm_qwerty_current_lang_table_ptr[i].attributes[j].switch_flags == 0)
                {
                    char_code = MMI_QWERTY_GET_UCS2_CODE(g_mmi_imm_qwerty_current_lang_table_ptr[i].attributes[j].translated_code);

                    if (mmi_imm_test_input(&char_code, 1))
                    {
                        string[count++] = char_code;
                        string[count++] = 0;
                    }
                }
                else if (g_mmi_imm_qwerty_current_lang_table_ptr[i].attributes[j].switch_flags & switch_flags)
                {
                    char_code = MMI_QWERTY_GET_UCS2_CODE(g_mmi_imm_qwerty_current_lang_table_ptr[i].attributes[j].translated_code);
                    
                    if (mmi_imm_test_input(&char_code, 1))
                    {
                        string[count++] = char_code;
                        string[count++] = 0;
                    }
                }
            }

            break;
        }
    }

    
    for (i = 0; g_qwerty_lang_table_common_keys[i].mmi_key_code != KEY_INVALID && count < max_size; i++)
    {
        if (g_qwerty_lang_table_common_keys[i].mmi_key_code == mmi_key_code)
        {
            for (j = 0; g_qwerty_lang_table_common_keys[i].attributes[j].translated_code != 0 && count < max_size; j++)
            {
                if (switch_flags == 0 && g_qwerty_lang_table_common_keys[i].attributes[j].switch_flags == 0)
                {
                    char_code = MMI_QWERTY_GET_UCS2_CODE(g_qwerty_lang_table_common_keys[i].attributes[j].translated_code);

                    if (mmi_imm_test_input(&char_code, 1))
                    {
                        string[count++] = char_code;
                        string[count++] = 0;
                    }
                }
                else if (g_qwerty_lang_table_common_keys[i].attributes[j].switch_flags & switch_flags)
                {
                    char_code = MMI_QWERTY_GET_UCS2_CODE(g_qwerty_lang_table_common_keys[i].attributes[j].translated_code);

                    if (mmi_imm_test_input(&char_code, 1))
                    {
                        string[count++] = char_code;
                        string[count++] = 0;
                    }
                }
            }
    
            break;
        }
    }
        
    return (count / 2);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imm_qwerty_change_lang
 * DESCRIPTION
 *  Change qwerty language
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imm_qwerty_change_lang(mmi_imm_support_writing_lang_enum lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

#if defined __MMI_XT9__  /* for xt9 we need to initialize multitap */
    const sIMEModeDetails *mode_details_ptr = NULL;
    if(!mmi_imm_is_smart_input_method(mmi_imm_get_curr_input_mode()))
    {
        mode_details_ptr = mmi_imm_get_input_mode_array_item(mmi_imm_get_curr_input_mode());
        mmi_ime_multitap_vendor_change_mode( mode_details_ptr, 0 );
    }
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; g_qwerty_lang_table[i].lang != IME_WRITING_LANG_NONE; i++)
    {
        if (g_qwerty_lang_table[i].lang == lang)
        {
            g_mmi_imm_qwerty_current_lang_table_ptr = g_qwerty_lang_table[i].qwerty_table;
            
            mmi_imm_change_dead_character_lang_table(lang);
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imm_qwerty_is_special_key
 * DESCRIPTION
 *  If it is special key which should support multi-key
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imm_qwerty_is_special_key(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; g_qwerty_special_key[i] != KEY_INVALID; i++)
    {
        if (g_qwerty_special_key[i] == mmi_key_code)
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imm_qwerty_is_valid_special_key_of_current_lang
 * DESCRIPTION
 *  If it is valid special key current qwerty language
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imm_qwerty_is_valid_special_key_of_current_lang(U32 special_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    UI_character_type char_code;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (special_flag == 0)
    {
        return MMI_TRUE;
    }
    
    for (i = 0; g_mmi_imm_qwerty_current_lang_table_ptr[i].mmi_key_code != KEY_INVALID; i++)
    {
        for (j = 0; g_mmi_imm_qwerty_current_lang_table_ptr[i].attributes[j].translated_code != 0; j++)
        {
            if (g_mmi_imm_qwerty_current_lang_table_ptr[i].attributes[j].switch_flags & special_flag)
            {
                char_code = MMI_QWERTY_GET_UCS2_CODE(g_mmi_imm_qwerty_current_lang_table_ptr[i].attributes[j].translated_code);
                
                if (mmi_imm_test_input(&char_code, 1))
                {
                    return MMI_TRUE;
                }
            }
        }
    }

    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imm_qwerty_is_valid_character_by_mmi_key
 * DESCRIPTION
 *  Is the valid character of spcific mmi key
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imm_qwerty_is_valid_character_by_mmi_key(S16 mmi_key_code, UI_character_type char_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; g_mmi_imm_qwerty_current_lang_table_ptr[i].mmi_key_code != KEY_INVALID; i++)
    {
        if (g_mmi_imm_qwerty_current_lang_table_ptr[i].mmi_key_code == mmi_key_code)
        {
            for (j = 0; g_mmi_imm_qwerty_current_lang_table_ptr[i].attributes[j].translated_code != 0; j++)
            {
                if (char_code == MMI_QWERTY_GET_UCS2_CODE(g_mmi_imm_qwerty_current_lang_table_ptr[i].attributes[j].translated_code))
                {
                    return MMI_TRUE;
                }
            }

            break;
        }
    }

    for (i = 0; g_qwerty_lang_table_common_keys[i].mmi_key_code != KEY_INVALID; i++)
    {
        if (g_qwerty_lang_table_common_keys[i].mmi_key_code == mmi_key_code)
        {
            for (j = 0; g_qwerty_lang_table_common_keys[i].attributes[j].translated_code != 0; j++)
            {
                if (char_code == MMI_QWERTY_GET_UCS2_CODE(g_qwerty_lang_table_common_keys[i].attributes[j].translated_code))
                {
                    return MMI_TRUE;
                }
            }

            break;
        }
    }
    
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imm_qwerty_get_supported_chars
 * DESCRIPTION
 *  Get all supported characters of a qwerty key
 * PARAMETERS
 * RETURNS
 *  Number of characters
 *****************************************************************************/
U32 mmi_imm_qwerty_get_supported_chars(S16 mmi_key_code, UI_character_type string[], U32 buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    U32 count = 0;
    UI_character_type char_code;
    S16 opp_key_code;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; g_mmi_imm_qwerty_current_lang_table_ptr[i].mmi_key_code != KEY_INVALID && count < buf_size; i++)
    {
        if (g_mmi_imm_qwerty_current_lang_table_ptr[i].mmi_key_code == mmi_key_code)
        {
            for (j = 0; g_mmi_imm_qwerty_current_lang_table_ptr[i].attributes[j].translated_code != 0 && count < buf_size; j++)
            {
                char_code = MMI_QWERTY_GET_UCS2_CODE(g_mmi_imm_qwerty_current_lang_table_ptr[i].attributes[j].translated_code);

                if (char_code > 0)
                {
                    string[count++] = char_code;
                    string[count++] = 0;
                }
            }

            break;
        }
    }

    
    for (i = 0; g_qwerty_lang_table_common_keys[i].mmi_key_code != KEY_INVALID && count < buf_size; i++)
    {
        if (g_qwerty_lang_table_common_keys[i].mmi_key_code == mmi_key_code)
        {
            for (j = 0; g_qwerty_lang_table_common_keys[i].attributes[j].translated_code != 0 && count < buf_size; j++)
            {
                char_code = MMI_QWERTY_GET_UCS2_CODE(g_qwerty_lang_table_common_keys[i].attributes[j].translated_code);
                
                if (char_code > 0)
                {
                    string[count++] = char_code;
                    string[count++] = 0;
                }
            }
    
            break;
        }
    }
    opp_key_code=mmi_imm_qwerty_get_opposite_key_code(mmi_key_code); /*Added for dialer key handling*/
    if(opp_key_code==KEY_W||opp_key_code==KEY_P)
    {
     for (i = 0; g_mmi_imm_qwerty_current_lang_table_ptr[i].mmi_key_code != KEY_INVALID && count < buf_size; i++)
    {
        if (g_mmi_imm_qwerty_current_lang_table_ptr[i].mmi_key_code == opp_key_code)
        {
            for (j = 0; g_mmi_imm_qwerty_current_lang_table_ptr[i].attributes[j].translated_code != 0 && count < buf_size; j++)
            {
                char_code = MMI_QWERTY_GET_UCS2_CODE(g_mmi_imm_qwerty_current_lang_table_ptr[i].attributes[j].translated_code);

                if (char_code > 0)
                {
                    string[count++] = char_code;
                    string[count++] = 0;
                }
            }
        
            break;
        }
    }
    }
    return (count / 2);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imm_qwerty_custom_update_special_key_status
 * DESCRIPTION
 *  It ask the vendor to process the special key status
 * PARAMETERS
 *  key_code                :   [IN] the key code to process
 *  key_type                :   [IN] the key type to process
 *  special_key_flag        :   [OUT] the place to record the result of special key flag
 *  special_key_lock_flag   :   [OUT] the place to record the result of special key lock flag
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE                :   vendor process the special key successfully
 *  MMI_FALSE               :   vendor process the special key unsuccessfully
 *****************************************************************************/
MMI_BOOL mmi_imm_qwerty_custom_update_special_key_status(S16 key_code,
                                                         S16 key_type,
                                                         U32 *special_key_flag,
                                                         U32 *special_key_lock_flag)
{
#ifdef __MMI_IME_PLUG_IN__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ime_sdk_key_event_data_struct key_event_data;
    mmi_ime_sdk_special_key_status_struct special_key_status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    key_event_data.mmi_key_code = key_code;
    key_event_data.mmi_key_type = key_type;
    
    if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_UPDATE_SPECIAL_KEY_STATUS, (U32)&key_event_data, (U32)&special_key_status) == 1)
    {
        *special_key_flag = special_key_status.special_key_flag;
        *special_key_lock_flag = special_key_status.special_key_lock_flags;
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
#else
    return MMI_FALSE;
#endif
}

#endif /* #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__) */


