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
 *  Armenian.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Common language module
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
 /*****************************************************************************
 *  Include
 *****************************************************************************/
#include "MMI_include.h"
#include "CommonLang.h"
#include "LangModule.h"

/* RHR */
#include "gui_data_types.h"
#include "MMIDataType.h"
#include "string.h"
#include "LangModuleGProt.h"
#include "kal_general_types.h"
#include "PixcomFontEngine.h"

/***************************************************************************** 
* Define
*****************************************************************************/
typedef struct
{
    UI_character_type input_char[2];
    UI_character_type output_char;
} mmi_lm_latin_ligature_table, *mmi_lm_latin_ligature_table_p;

/****************************************************************************** 
* External Global variables
***************************************************************************** */

/****************************************************************************** 
* External Global Functions
***************************************************************************** */

/****************************************************************************** 
* Global variables
***************************************************************************** */

/***************************************************************************** 
* Local Variables
*****************************************************************************/

#if defined(__MMI_LM_LANG_EUROPEAN_SUPPORT__)
static const mmi_lm_latin_ligature_table mmi_lm_european_symbols[] = 
{
   /****Grave Accent***/
    {{0x0300, 0x61}, 0xE0},
    {{0x0300, 0x65}, 0xE8},
    {{0x0300, 0x69}, 0xEC},
    {{0x0300, 0x6F}, 0xF2},
    {{0x0300, 0x75}, 0xF9},

    {{0x0300, 0x41}, 0xC0},
    {{0x0300, 0x45}, 0xC8},
    {{0x0300, 0x49}, 0xCC},
    {{0x0300, 0x4F}, 0xD2},
    {{0x0300, 0x55}, 0xD9},

   /***Acute Accent***/
    {{0x0301, 0x61}, 0xE1},
    {{0x0301, 0x65}, 0xE9},
    {{0x0301, 0x69}, 0xED},
    {{0x0301, 0x6F}, 0xF3},
    {{0x0301, 0x75}, 0xFA},
    {{0x0301, 0x79}, 0xFD},

    {{0x0301, 0x41}, 0xC1},
    {{0x0301, 0x45}, 0xC9},
    {{0x0301, 0x49}, 0xCD},
    {{0x0301, 0x4F}, 0xD3},
    {{0x0301, 0x55}, 0xDA},
    {{0x0301, 0x59}, 0xDD},
    {{0x0301, 0x4c}, 0x0139}, 
    {{0x0301, 0x6c}, 0x013A}, 
    {{0x0301, 0x52}, 0x0154}, 
    {{0x0301, 0x72}, 0x0155}, 

   /***circumflex accent***/
    {{0x0302, 0x61}, 0xE2},
    {{0x0302, 0x65}, 0xEA},
    {{0x0302, 0x69}, 0xEE},
    {{0x0302, 0x6F}, 0xF4},
    {{0x0302, 0x75}, 0xFB},

    {{0x0302, 0x41}, 0xC2},
    {{0x0302, 0x45}, 0xCA},
    {{0x0302, 0x49}, 0xCE},
    {{0x0302, 0x4F}, 0xD4},
    {{0x0302, 0x55}, 0xDB},

   /***Diaeresis***/
    {{0x0308, 0x61}, 0xE4},
    {{0x0308, 0x65}, 0xEB},
    {{0x0308, 0x69}, 0xEF},
    {{0x0308, 0x6F}, 0xF6},
    {{0x0308, 0x75}, 0xFC},
    {{0x0308, 0x79}, 0xFF},

    {{0x0308, 0x41}, 0xC4},
    {{0x0308, 0x45}, 0xCB},
    {{0x0308, 0x49}, 0xCF},
    {{0x0308, 0x4F}, 0xD6},
    {{0x0308, 0x55}, 0xDC},

   /***Tilde***/
    {{0x0303, 0x61}, 0xE3},
    {{0x0303, 0x6F}, 0xF5},
    {{0x0303, 0x6E}, 0xF1},
    {{0x0303, 0x41}, 0xC3},
    {{0x0303, 0x4F}, 0xD5},
    {{0x0303, 0x4E}, 0xD1},
    
   /***Hacek***/
    {{0x030c, 0x63}, 0x10D},     
    {{0x030c, 0x64}, 0x10F},
    {{0x030c, 0x43}, 0x10C},     
    {{0x030c, 0x44}, 0x10E},
    {{0x030c, 0x45}, 0x11A},     
    {{0x030c, 0x65}, 0x11B},
    {{0x030c, 0x4E}, 0x147},     
    {{0x030c, 0x6E}, 0x148},
    {{0x030c, 0x52}, 0x158},
    {{0x030c, 0x72}, 0x159},     
    {{0x030c, 0x53}, 0x160},
    {{0x030c, 0x73}, 0x161},
    {{0x030c, 0x54}, 0x164},     
    {{0x030c, 0x74}, 0x165},
    {{0x030c, 0x5A}, 0x17D},
    {{0x030c, 0x7A}, 0x17E},
    {{0x030c, 0x6C}, 0x13E},
    {{0x030c, 0x4C}, 0x13D},
    
    /***Cedilla***/
    {{0x0327, 0x53}, 0x15E},
    {{0x0327, 0x73}, 0x15F},
    {{0x0327, 0x43}, 0xC7},
    {{0x0327, 0x63}, 0xE7},
    
    /***Ogonek***/
    {{0x0328, 0x41}, 0x0104},
    {{0x0328, 0x45}, 0x0118},
    {{0x0328, 0x61}, 0x0105},
    {{0x0328, 0x65}, 0x0119}
    

};


#if defined(__MMI_LANG_TURKISH__)
static const mmi_lm_latin_ligature_table mmi_lm_turkish_symbols[] = 
{
   /****Grave Accent***/
    {{0x0300, 0x61}, 0xE0},
    {{0x0300, 0x65}, 0xE8},
    {{0x0300, 0x69}, 0xEC},
    {{0x0300, 0x131}, 0xEC},
    {{0x0300, 0x6F}, 0xF2},
    {{0x0300, 0x75}, 0xF9},

    {{0x0300, 0x41}, 0xC0},
    {{0x0300, 0x45}, 0xC8},
    {{0x0300, 0x49}, 0xCC},
    {{0x0300, 0x130}, 0xCC},
    {{0x0300, 0x4F}, 0xD2},
    {{0x0300, 0x55}, 0xD9},

   /***Acute Accent***/
    {{0x0301, 0x61}, 0xE1},
    {{0x0301, 0x65}, 0xE9},
    {{0x0301, 0x69}, 0xED},
    {{0x0301, 0x131}, 0xED},
    {{0x0301, 0x6F}, 0xF3},
    {{0x0301, 0x75}, 0xFA},

    {{0x0301, 0x41}, 0xC1},
    {{0x0301, 0x45}, 0xC9},
    {{0x0301, 0x49}, 0xCD},
    {{0x0301, 0x130}, 0xCD},
    {{0x0301, 0x4F}, 0xD3},
    {{0x0301, 0x55}, 0xDA},

   /***circumflex accent***/
    {{0x0302, 0x61}, 0xE2},
    {{0x0302, 0x65}, 0xEA},
    {{0x0302, 0x69}, 0xEE},
    {{0x0302, 0x131}, 0xEE},
    {{0x0302, 0x6F}, 0xF4},
    {{0x0302, 0x75}, 0xFB},

    {{0x0302, 0x41}, 0xC2},
    {{0x0302, 0x45}, 0xCA},
    {{0x0302, 0x49}, 0xCE},
    {{0x0302, 0x130}, 0xCE},
    {{0x0302, 0x4F}, 0xD4},
    {{0x0302, 0x55}, 0xDB},

   /***Diaeresis***/
    {{0x0308, 0x61}, 0xE4},
    {{0x0308, 0x65}, 0xEB},
    {{0x0308, 0x69}, 0xEF},
    {{0x0308, 0x131}, 0xEF},
    {{0x0308, 0x6F}, 0xF6},
    {{0x0308, 0x75}, 0xFC},
    {{0x0308, 0x79}, 0xFF},

    {{0x0308, 0x41}, 0xC4},
    {{0x0308, 0x45}, 0xCB},
    {{0x0308, 0x49}, 0xCF},
    {{0x0308, 0x130}, 0xCF},
    {{0x0308, 0x4F}, 0xD6},
    {{0x0308, 0x55}, 0xDC},

   /***Tilde***/
    {{0x0303, 0x61}, 0xE3},
    {{0x0303, 0x6F}, 0xF5},
    {{0x0303, 0x6E}, 0xF1},

    {{0x0303, 0x41}, 0xC3},
    {{0x0303, 0x4F}, 0xD5},
    {{0x0303, 0x4E}, 0xD1}
};

#endif
#endif /* __MMI_LM_LANG_EUROPEAN_SUPPORT__ */ 



/***************************************************************************** 
* Local Function
*****************************************************************************/
#if defined(__MMI_LM_LANG_EUROPEAN_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_lm_common_latin_ligature_rule
 * DESCRIPTION
 *  Do latin ligature rule by input
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static UI_character_type mmi_lm_common_latin_ligature(mmi_lm_latin_ligature_table_p table, S32 n_entry, UI_character_type curCh, UI_character_type nextCh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    mmi_lm_latin_ligature_table_p d = &table[0];
    UI_character_type input_string[2];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //From Unicode Chart, 0x0300~0x036F is for "Combining Diacritical Marks", so only need to check in this range
    if((nextCh < 0x0300 ) || (nextCh > 0x036F))
        return 0;

    input_string[0] = nextCh;
    input_string[1] = curCh;
    for (i = 0; i < n_entry; i++)
    {

        if (memcmp(d->input_char, input_string, (sizeof(UI_character_type) * 2)) == 0)
        {
            return d->output_char;
        }
        d++;
    }
    return 0;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_lm_common_latin_ligature_rule
 * DESCRIPTION
 *  Do latin ligature rule by input
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static UI_character_type mmi_lm_common_latin_ligature_rule(UI_character_type currCh, U8* buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_LANG_VIETNAMESE__)    
    viet_tone_mark tone_mark = VIET_TONE_NONE;
    viet_vowel_letter viet_vowel = VIET_VOWEL_NONE;
#endif
    UI_character_type nextch = MMI_LM_GET_CHARACTER_FROM_BUFFER(buf_ptr);
    UI_character_type new_char = 0x0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_LANG_VIETNAMESE__)    
    viet_vowel = mmi_viet_vowel_letter(currCh);
    if (VIET_VOWEL_NONE != viet_vowel)
    {
        tone_mark = mmi_viet_tone_mark(nextch);
        if (VIET_TONE_NONE != tone_mark)
        {
            new_char = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
            if (new_char != 0x0)
                return new_char;
        }
    }
#endif

#if defined(__MMI_LANG_TURKISH__)
    new_char = mmi_lm_common_latin_ligature((mmi_lm_latin_ligature_table_p)mmi_lm_turkish_symbols, sizeof(mmi_lm_turkish_symbols)/sizeof(mmi_lm_latin_ligature_table), currCh, nextch);
    if (new_char != 0x0)
        return new_char;
#endif

    new_char = mmi_lm_common_latin_ligature((mmi_lm_latin_ligature_table_p)mmi_lm_european_symbols, sizeof(mmi_lm_european_symbols)/sizeof(mmi_lm_latin_ligature_table), currCh, nextch);
    return new_char;

}

#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_lm_common_get_current_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lm_common_get_current_cluster(
            PU8 start, 
            PU8 end, 
            mmi_lm_cluster_info_p prev2_cluster, 
            mmi_lm_cluster_info_p prev_cluster, 
            mmi_lm_cluster_info_p curr_cluster, 
            MMI_BOOL pos_only)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type curch, prevch;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_cluster->is_gap = MMI_LM_CLUSTER_ATTR_GAP;
    curch = MMI_LM_GET_CHARACTER_FROM_BUFFER(start);
    start += MMI_LM_CHARACTER_SIZE;
    curr_cluster->data_len = 1;
    
#if defined(__MMI_LM_LANG_EUROPEAN_SUPPORT__)
    if (start < end)
    {
        UI_character_type new_char = 0x0;
        new_char = mmi_lm_common_latin_ligature_rule(curch, start);
        if (new_char != 0x0000)
        {
            curch = new_char;
            curr_cluster->data_len++;
        }
    }
#endif

    curr_cluster->display_buffer[0] = curch;
    curr_cluster->display_buffer[1] = 0;
    curr_cluster->cluster_len = 1;

    if (!pos_only)
    {
        if (curr_cluster->lang_id == prev_cluster->lang_id)
        {
            if (MMI_LM_TEST_PREV_CONNECT(curch))
            {
                curr_cluster->is_connect = MMI_LM_CLUSTER_ATTR_CONNECT;
            }
            else
            {
                prevch = MMI_LM_GET_CHARACTER_FROM_BUFFER(prev_cluster->data_ptr);
                if (MMI_LM_TEST_BACK_CONNECT(prevch) ||
                    ( MMI_LM_TEST_ALPHABETIC_CHAR(curch) && 
                       (!MMI_LM_TEST_WORD_WRAPPING_BREAK_CHARACTER(prevch) && MMI_LM_TEST_ALPHABETIC_CHAR(prevch))))
                {
                    curr_cluster->is_connect = MMI_LM_CLUSTER_ATTR_CONNECT;
                }
            }  
        }
        mmi_fe_query_single_cluster(prev_cluster, curr_cluster);
        if (prev_cluster->lang_id== MMI_LM_LANG_INDIC && prev_cluster->lang_id != curr_cluster->lang_id)
        {
            curr_cluster->rx = prev_cluster->w - prev_cluster->adv_x;
            if (curr_cluster->rx < 0)
                curr_cluster->rx = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_lm_common_get_next_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lm_common_get_next_cluster(
            PU8 start, 
            PU8 end, 
            PU8 cursor, 
            MMI_BOOL pos_only,
            mmi_lm_cluster_info_p next_cluster)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


    
/*****************************************************************************
 * FUNCTION
 *  mmi_lm_common_cluster_translate
 * DESCRIPTION
 *  Translate string. If in the src, there is a pattern A + B could be changed to another unicode C, then change it to C.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_lm_common_cluster_translate(UI_string_type src, UI_string_type dst, S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type curch = src[0];
    S32 ret = 1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_LM_LANG_EUROPEAN_SUPPORT__)
    if (len > 1)
    {
        UI_character_type new_char = 0x0;
        new_char = mmi_lm_common_latin_ligature_rule(curch, (U8*)(src+1));
        if (new_char != 0x0000)
        {
            curch = new_char;
            ret = 2;
        }
    }
#endif
    dst[0] = curch;
    return ret;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_lm_common_get_prev_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lm_common_get_prev_cluster(
            PU8 start, 
            PU8 end, 
            PU8 cursor, 
            MMI_BOOL pos_only,
            mmi_lm_cluster_info_p prev_cluster)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}

/*****************************************************************************
 * FUNCTION
 *  mmi_lm_common_draw_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lm_common_draw_cluster(mmi_lm_show_cluster_param_p param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    mmi_fe_show_one_cluster_param_struct fe_param;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fe_param.string = (U8*)(&(param->cluster->display_buffer));
    fe_param.len = param->cluster->cluster_len;
    fe_param.baseline = param->baseline;
    fe_param.bordered = param->bordered;
    fe_param.x = param->x;
    fe_param.y = param->y;
    fe_param.langid = param->cluster->lang_id;
    fe_param.subarray_start = 0;
    fe_param.subarray_len = fe_param.len;
    mmi_fe_show_single_cluster(&fe_param);

}



