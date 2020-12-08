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
 *   IndicRuleEngine.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   C file for Indic language Engine API's
 *
 * Author:
 *   Pramod (pmt00110)
 *   Pawanjeet (pmt00112)
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
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
#include "MMI_include.h"
#if defined (__MMI_INDIC_ALG__)
#include "imc.h"
#include "IndicRuleEngine.h"

#if defined (__MMI_LANG_THAI__)
#include "ThaiGProt.h"
#endif /* defined (__MMI_LANG_THAI__) */

extern void Get_CharWidth(U32 Ch, S32 *pdWidth);

/* Local Functions */
#if defined (__MMI_LANG_MYANMAR__)
static void ire_adjust_after_language_rules_for_myanmar(U16 *glyphoutput, S32 nentry_buffer);
#endif
#if defined (__MMI_LANG_KHMER__)
static void ire_adjust_after_language_rules_for_khmer_before_rules(U16 *cluster, S32 nentry_buffer);
static void ire_adjust_after_language_rules_for_khmer(U16 *glyphoutput, S32 noutglyph);
#endif
#if defined(__MMI_IRE_SLIM__)
U32 g_is_ra_con = 0;
U32 ire_character_info(U16 character, ire_prev_char_struct *  g_character_information);
#endif

/**************			GLOBAL DEFINITION			*********************/

/*global pointer variable to hold the character info*/
U32 *g_character_status_flag_p  =	0;

/*global structure pointer which points to character info structure */
const ire_character_info_table_struct *g_lang_character_info_p;

indic_rules_ligature_enum indic_rules_current_set_language;
indic_rules_ligature_enum indic_rules_prefered_set_language;

/************        EXTERN DEFINITION       ********************************/
    #if defined (__MMI_MULTITAP_BANGLA_SPEC__)
 extern MMI_BOOL check_ra_hal_bangla_for_imui;
#endif
extern const ire_indic_languages_table_struct indic_lang_char_info_table[];
extern const ire_indic_languages_table_struct indic_lang_ligature_info_table[];
extern const ire_indic_languages_table_struct indic_lang_ligature2_info_table[];

struct ire_g_context_struct g_indic_rule_engine_cntx;
U8 take_prev_char_id = MMI_FALSE ;
U8 is_RA_hal_reordering = MMI_FALSE;

#if defined(__MMI_LANG_KANNADA__)
U8 is_first_entry_kannada_ra_con = MMI_FALSE;
#endif /* defined(__MMI_LANG_KANNADA__) */ 

#if !defined(__MMI_IRE_SLIM__)


/************        API'S DEFINITION       ********************************/


/*****************************************************************************
 * FUNCTION
 *  ire_get_current_cluster
 * DESCRIPTION			
 *  This method will find the current cluster and copy it into the output buffer
 * PARAMETERS
 *  previous_cursor_p       [IN]        Previous cursor pointer to start with
 *  current_cursor_p        [IN]        Current cursor pointer
 *  output_buffer           [IN]        Output buffer
 * RETURNS           
 *  S32  true or false
 *****************************************************************************/
S32 ire_get_current_cluster(PU8 previous_cursor_p, PU8 current_cursor_p, PU16 output_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cluster_len = 0;
    PU8 move_cursor_p = previous_cursor_p;
    U16 n_glyphoutput = 0;
    g_indic_rule_engine_cntx.g_cursor_end_curr_cluster_p = current_cursor_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_CURRENT_CLUSTER);

#ifdef __MMI_BIDI_ALG__
    if (g_indic_rule_engine_cntx.g_ire_arabic_language_character_count)
    {
        if (IRE_INDIC_LANGUAGE_RANGE(IRE_LANG_ID_CONVERT_U8_U16(move_cursor_p)))
        {
            output_buffer[0] = (U16) '?';
            /* terminate the output buffer string with NULL character */
            output_buffer[1] = (U16) NULL;
            g_indic_rule_engine_cntx.g_cursor_end_curr_cluster_p = NULL;
            return TRUE;
        }
    }
#endif /* __MMI_BIDI_ALG__ */ 

    if (IRE_INDIC_LANGUAGE_RANGE(IRE_LANG_ID_CONVERT_PREVIOUS_VAL_U8_U16(current_cursor_p)))
    {
        /* set the start and end pointer */
        ire_init_cluster_start_p(previous_cursor_p);
        ire_init_cluster_end_p(current_cursor_p);
        if ((previous_cursor_p + 2) == current_cursor_p)
        {
            output_buffer[0] = ((*previous_cursor_p) | (*(previous_cursor_p + 1) << 8));
            goto LABEL;

        }
        cluster_len = (current_cursor_p - move_cursor_p) / 2;;
        /* apply language rules on the cluster recently formed */
        if (cluster_len > 1)
        {
            n_glyphoutput = ire_language_rules(
                                output_buffer,
                                (U16*) g_indic_rule_engine_cntx.g_temp_array,
                                g_indic_rule_engine_cntx.g_display_buffer_len);
            /* terminate the output buffer string with NULL character */
            output_buffer[n_glyphoutput] = (U16) NULL;
        }
        else
        {
          LABEL:
            output_buffer[0] = g_indic_rule_engine_cntx.g_temp_array[0];
            output_buffer[1] = (U16) NULL;
        }
    }
    else
    {
        output_buffer[0] = (U16) (IRE_LANG_ID_CONVERT_PREVIOUS_VAL_U8_U16(current_cursor_p));
        /* terminate the output buffer string with NULL character */
        output_buffer[1] = (U16) NULL;
    }
    g_indic_rule_engine_cntx.g_cursor_end_curr_cluster_p = NULL;

    return TRUE;
}

#endif

/*****************************************************************************
 * FUNCTION
 *  ire_get_next_cluster_p
 * DESCRIPTION				
 *  This method will search for the next cluster and returns the pointer 
 *  to the begining of the cluster
 * PARAMETERS
 *  previous_cursor_p       [IN]        Previous cursor pointer to start with
 *  current_cursor_p        [IN]        Current cursor pointer
 * RETURNS                    
 *   PU8   pointer to the begining of next cluster
 *****************************************************************************/
PU8 ire_get_next_cluster_p(PU8 previous_cursor_p, PU8 current_cursor_p)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cluster_len = 0;    /* store the length of the cluster */

    U16 *cluster_buffer = (U16*) g_indic_rule_engine_cntx.g_temp_array;        /* temporary buffer used to find out the cluster length */
    PU8 curr_cursor_p = previous_cursor_p;

    memset(cluster_buffer, '\0', 2 * (G_MAX + 1));

    /* initialize the local buffer */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_NEXT_CLUSTER_P);
	
#ifdef __MMI_BIDI_ALG__
    if (g_indic_rule_engine_cntx.g_ire_arabic_language_character_count)
    {
        if (IRE_INDIC_LANGUAGE_RANGE(IRE_LANG_ID_CONVERT_U8_U16(curr_cursor_p)))
        {
            return (previous_cursor_p + TWO);
        }
    }
#endif /* __MMI_BIDI_ALG__ */ 
    if (previous_cursor_p == current_cursor_p)
    {
        return previous_cursor_p;

    }
    /* Is there any character present or not */
    if (IRE_LANG_ID_CONVERT_U8_U16(previous_cursor_p) == (U16) NULL)
    {
        return previous_cursor_p;
    }
    else if (IRE_INDIC_LANGUAGE_RANGE(IRE_LANG_ID_CONVERT_NEXT_VAL_U8_U16(previous_cursor_p)))
    {
        /* set the start and end pointer */
        ire_init_cluster_start_p(previous_cursor_p);
        ire_init_cluster_end_p(current_cursor_p);
        /* start forming cluster */
        cluster_len = ire_get_cluster(cluster_buffer);
        cluster_buffer[g_indic_rule_engine_cntx.g_display_buffer_len] = 0;
        /* update the cursor pointer by incrementing it with cluster length */
        curr_cursor_p += (cluster_len * 2);
        return curr_cursor_p;
    }
    else
    {
        cluster_buffer[0] = ((*previous_cursor_p) | (*(previous_cursor_p + 1) << 8));
        cluster_buffer[1] = 0;

        return (previous_cursor_p + TWO);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ire_get_prev_cluster_p
 * DESCRIPTION					
 *  This method will search the previous cluster and returns the pointer to 
 *  the begining of cluster
 * PARAMETERS
 *  text_p          [IN]        Pointer to a text to start with
 *  cursor_p        [IN]        Pointer to a current cursor position
 * RETURNS                 
 *  pointer to the begining of previous cluster if exists(?)(?)(?)
 *****************************************************************************/
PU8 ire_get_prev_cluster_p(PU8 text_p, PU8 cursor_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cluster_len = 0;
    U16 cluster_buffer[G_MAX + 1];
    PU8 current_cursor_p = text_p;
    PU8 prev_cursor_p = text_p;
    PU8 cursor_pointer = cursor_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cursor_pointer -= TWO;
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_PREV_CLUSTER_P);
    
#ifdef __MMI_BIDI_ALG__
    if (g_indic_rule_engine_cntx.g_ire_arabic_language_character_count)
    {
        if (IRE_INDIC_LANGUAGE_RANGE(IRE_LANG_ID_CONVERT_U8_U16(cursor_pointer)))
        {
            return (cursor_pointer);
        }
    }
#endif /* __MMI_BIDI_ALG__ */ 

    /* Is previous character belongs to Indic range */
    if (IRE_INDIC_LANGUAGE_RANGE(IRE_LANG_ID_CONVERT_U8_U16(cursor_pointer)))
    {
        /* set the start and end pointer */
        ire_init_cluster_start_p(text_p);
        ire_init_cluster_end_p(cursor_p);

        while (current_cursor_p != cursor_p)
        {
            memset(cluster_buffer, '\0', 2 * (G_MAX + 1));
            /* find the length of cluster */
            cluster_len = ire_get_cluster(cluster_buffer);
            /* store the value of previous pointer */
            prev_cursor_p = current_cursor_p;
            /* update the temporary cursor pointer */
            current_cursor_p += (cluster_len * 2);
            if (cluster_len == 0)
            {
                break;
            }
        }
        return prev_cursor_p;
    }
    else
    {
        return cursor_pointer;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ire_get_next_cluster_p_with_size
 * DESCRIPTION				
 *  This method will search for the next cluster and returns the pointer to 
 *  the begining of the cluster and the size of the current cluster in pixels 
 * PARAMETERS
 *  previous_cursor_p       [IN]        Previous cursor pointer to start with
 *  current_cursor_p        [IN]        Current cursor pointer
 *  cluster_size            [IN]
 *  RETURNS                    pointer to the begining of next cluster
 *****************************************************************************/
PU8 ire_get_next_cluster_p_with_size(PU8 previous_cursor_p, PU8 current_cursor_p, S32 *cluster_size)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32  glyphoutput_len = 0;
    S32  str_width;                                                         /* Width of the string */
    S32  height;                                                            /* Height of the string */
    S32  char_dwidth;                                                       /* Width of the character */
    S32  cluster_len = 0;                                                   /* store the length of the cluster */
    U16  *cluster_buffer = (U16  *) g_indic_rule_engine_cntx.g_temp_array ; /* temporary buffer used to find out the cluster length */
    U16  glyphoutput[G_MAX + 1];
    PU8  curr_char_p;														/* used for storing the current character pointer */
    PU8  curr_cursor_p = previous_cursor_p;
    U16  next_char = 0;														/* used for storing the next character */
    U16  curr_char = 0;														/* used for storing the current character */
    U32  next_char_pos = 0;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_NEXT_CLUSTER_P_WITH_SIZE);
    memset(cluster_buffer, '\0', 2 * (G_MAX + 1));
	
	/*************************************************************************************** 
	 * If the next character after the cluster does not lies in the language range
	 * of the last character in the cluster, then the global parameter will be set
	 * This global parameter will be used by Font Engine to do the width adjustment 
	 * (by adding the offset)when the last character in the cluster is above or below base 
	 * and its width is greater than the last but one character in the cluster. Intially we 
	 * have to reset it
	 **************************************************************************************/
    g_indic_rule_engine_cntx.g_ire_width_adjustment_required = 0;
    
    if (g_indic_rule_engine_cntx.g_ire_arabic_language_character_count)
    {
        if (IRE_INDIC_LANGUAGE_RANGE(IRE_LANG_ID_CONVERT_U8_U16(curr_cursor_p)))
        {
            *cluster_size = gui_get_character_width((U16) '?');
			g_indic_rule_engine_cntx.g_cursor_end_curr_cluster_p = NULL;
			return (previous_cursor_p + TWO);
        }
    }
	cluster_buffer[cluster_len] = 0;
	if(previous_cursor_p == current_cursor_p)
	{
		*cluster_size = 0;
		return previous_cursor_p; 
	}
    /* Is there any character present or not */
	if (IRE_LANG_ID_CONVERT_U8_U16(previous_cursor_p) == (U16) NULL)
    {
		*cluster_size = 0;
		return previous_cursor_p;
    }
    else if (IRE_INDIC_LANGUAGE_RANGE(IRE_LANG_ID_CONVERT_NEXT_VAL_U8_U16(previous_cursor_p)))
    {
        /* set the start and end pointer */
        ire_init_cluster_start_p(previous_cursor_p);
        ire_init_cluster_end_p(current_cursor_p);
		cluster_len = ire_get_cluster(cluster_buffer);
        cluster_buffer[g_indic_rule_engine_cntx.g_display_buffer_len] = 0;
        
        /* curr_char_p will point to the last character in the cluster */
        curr_char_p = curr_cursor_p + ((cluster_len - 1) * 2);
        /* update the cursor pointer by incrementing it with cluster length */
        curr_cursor_p += (cluster_len * 2);
        
        /* The next_char will store the next character after the cluster.
         * and curr_char variable will store the last character in the cluster
         */
        next_char = ((*curr_cursor_p) | (*(curr_cursor_p + 1)<<8));
        curr_char = ((*curr_char_p) | (*(curr_char_p + 1) << 8));

   	    if(cluster_len > 1)
		{
			glyphoutput_len = ire_language_rules(glyphoutput, cluster_buffer, g_indic_rule_engine_cntx.g_display_buffer_len);
            glyphoutput[glyphoutput_len] = (U16)NULL;
		}
		else
		{
			glyphoutput_len = 1;
			glyphoutput[0] = cluster_buffer[0];
			glyphoutput[1] = (U16)NULL;
		}
        
        /*************************************************************************************** 
		 * If the next character after the cluster does not lies in the language range
		 * of the last character in the cluster, then the global parameter will be set
		 * This global parameter will be used by Font Engine to do the width adjustment 
		 * (by adding the offset)when the last character in the cluster is above or below base 
		 * and its width is greater than the last but one character in the cluster 
		 **************************************************************************************/
		
        if (next_char)
        {
            next_char_pos = ire_identify_char_position(next_char);
        }

		if(!(IRE_IS_PREV_CURR_SAME_LANG(curr_char, next_char)))
		{
			g_indic_rule_engine_cntx.g_ire_width_adjustment_required = 1;
		}
        /* If next character has attribute that requires the previous 
         * character's offset consideration, then set the global flag
         * so that the appropriate adjustment can be made in font engine
         */
        else if (next_char_pos == IRE_POST_BASE_POSITION_CONSIDERING_PREV_OFFSET)
        {
            g_indic_rule_engine_cntx.g_ire_width_adjustment_required = 1;
        }

		ire_disable_indic_rules_parsing();
        gui_measure_string(glyphoutput, &str_width, &height);
		ire_enable_indic_rules_parsing();
		
        g_indic_rule_engine_cntx.g_ire_width_adjustment_required = 0;
        *cluster_size = str_width;
		g_indic_rule_engine_cntx.g_cursor_end_curr_cluster_p = NULL;
		return curr_cursor_p;
	}
    else
    {
        cluster_buffer[0] = ((*previous_cursor_p) | (*(previous_cursor_p+1)<<8));
        cluster_buffer[1] =0;
        Get_CharWidth((U32)IRE_LANG_ID_CONVERT_U8_U16(previous_cursor_p), &char_dwidth);
        *cluster_size = char_dwidth;
        return (previous_cursor_p + TWO);
    }
}
#if !defined(__MMI_IRE_SLIM__)


/*****************************************************************************
 * FUNCTION
 *  ire_size_of_current_cluster
 * DESCRIPTION					
 *  This method will return the size of cluster in numbers of pixels
 * PARAMETERS
 *  previous_cursor_p       [IN]        
 *  current_cursor_p        [IN]        
 *  cursor                  [IN]        Pointer
 * RETURNS
 *  S32      size of cluster in number of pixels
 *****************************************************************************/
S32 ire_size_of_current_cluster(PU8 previous_cursor_p, PU8 current_cursor_p, U16 cursor)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cluster_len = 0;
    S32 glyphoutput_len = 0;
    S32 pixel_size = 0;
	S32 width, height;
    U16 *cluster_buffer = (U16*) g_indic_rule_engine_cntx.g_temp_array;
    U16 glyphoutput[G_MAX + 1];
    PU8 move_cursor_p = previous_cursor_p;

    /* initialize the local buffer */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_SIZE_OF_CURRENT_CLUSTER);
    
#ifdef __MMI_BIDI_ALG__
    if (g_indic_rule_engine_cntx.g_ire_arabic_language_character_count)
    {
        if (IRE_INDIC_LANGUAGE_RANGE(IRE_LANG_ID_CONVERT_U8_U16(move_cursor_p)))
        {
            pixel_size = gui_get_character_width((U16) '?');
            g_indic_rule_engine_cntx.g_cursor_end_curr_cluster_p = NULL;
            return pixel_size;
        }
    }
#endif /* __MMI_BIDI_ALG__ */ 

    /* Is cursor pointing to NULL character */
    if (previous_cursor_p == current_cursor_p)
    {
        return 0;
    }
    /* Is this character belongs to Indic language range */
    if (IRE_INDIC_LANGUAGE_RANGE(IRE_LANG_ID_CONVERT_PREVIOUS_VAL_U8_U16(current_cursor_p)))
    {
        /* set the start and end pointer */
        ire_init_cluster_start_p(previous_cursor_p);
        ire_init_cluster_end_p(current_cursor_p);
        if ((previous_cursor_p + 2) == current_cursor_p)
        {
            glyphoutput[0] = ((*previous_cursor_p) | (*(previous_cursor_p + 1) << 8));
            glyphoutput[1] = 0;
            goto LABEL;

        }

        /* start forming cluster */
        /* update the prev cursor pointer by incrementing it with cluster length */
        cluster_len = (current_cursor_p - move_cursor_p) / 2;
        cluster_buffer[g_indic_rule_engine_cntx.g_display_buffer_len] = 0;
        if (cluster_len > 1)
        {
            glyphoutput_len = ire_language_rules(glyphoutput, cluster_buffer, g_indic_rule_engine_cntx.g_display_buffer_len);
                glyphoutput[glyphoutput_len] = (U16)NULL;
        }
        else
        {
            glyphoutput[0] = cluster_buffer[0];
            glyphoutput[1] = (U16)NULL;
        }

        /* find the length in terms of number of pixels */
      LABEL:
        ire_disable_indic_rules_parsing();
		gui_measure_string(glyphoutput, &width, &height);
		ire_enable_indic_rules_parsing();
		pixel_size = width;
    }
    else
    {
        /* find the length in terms of number of pixels */
        pixel_size = gui_get_character_width((U16) IRE_LANG_ID_CONVERT_PREVIOUS_VAL_U8_U16(current_cursor_p));
    }
    g_indic_rule_engine_cntx.g_cursor_end_curr_cluster_p = NULL;
    return pixel_size;
}

#endif
/*****************************************************************************
 * FUNCTION
 *  ire_get_character_lang_id
 * DESCRIPTION			
 *  This method checks the input unicode value and returns the correponding 
 *  language Id
 * PARAMETERS
 *  character       [IN]        Input character (unicode value of a character)
 * RETURNS
 *  U32 Language Id of the input character
 *****************************************************************************/
U32 ire_get_character_lang_id(U16 character)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	#if defined(__MMI_LANG_KHMER__)
	if ((character >= 0x1780 && character <= 0x17FF) || (character >= 0XE701 && character <= 0XE7B8))
	{
		return IRE_LANGUAGE_ID_KHMER;
	}
	#endif /* defined(__MMI_LANG_KHMER__) */
	#if defined(__MMI_LANG_MYANMAR__)
	if ((character >= 0x1000 && character <= 0x109F) || (character >= 0xE800 && character <= 0xE8C2))
	{
		return IRE_LANGUAGE_ID_MYANMAR;
	}
	#endif /* defined(__MMI_LANG_MYANMAR__) */

	#if defined(__MMI_LANG_LAO__)
	if ((character >= 0x0E80 && character <= 0x0EFF))
	{
		return IRE_LANGUAGE_ID_LAO;
	}
	#endif /* defined(__MMI_LANG_LAO__) */ 

    /* proprietery unicode range */
	if (character & 0xF000)
    {
        switch (character & 0xFF00)
        {
        #if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__)
            case 0xE900:
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_CHARACTER_LANG_ID_HINDI_UNICODE_VALUE);
		            return IRE_LANGUAGE_ID_HINDI;
        #endif /* defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) */ 
        #if defined(__MMI_LANG_GUJARATI__)
            case 0xA100:
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_CHARACTER_LANG_ID_GUJARATI_UNICODE_VALUE);
		            return IRE_LANGUAGE_ID_GUJARATI;
        #endif /* defined(__MMI_LANG_GUJARATI__) */ 
        #if defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__)
            case 0xEA00:
		MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_CHARACTER_LANG_ID_BENGALI_UNICODE_VALUE);
				return IRE_LANGUAGE_ID_BENGALI;
            case 0xA400:
				if((character & 0xFFF0)< 0xA450)
	{	            
				if(character !=0xa42F && character !=0xa430 && character !=0xa431)
				{
					MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_CHARACTER_LANG_ID_BENGALI_UNICODE_VALUE);
		            return IRE_LANGUAGE_ID_BENGALI;
				}
				else
				{
					return IRE_LANGUAGE_ID_INVALID;
				}
        }
         else
				{
					return IRE_LANGUAGE_ID_INVALID;
				}
        #endif /* defined(__MMI_LANG_BENGALI__) */ 
        #if defined(__MMI_LANG_PUNJABI__)
            case 0xEB00:
                {
#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
                    if((character & 0xFFF0) >= 0xEBC0)
                    {
                        return IRE_LANGUAGE_ID_INVALID;
                    }
                    else
#endif
                    {
                        MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_CHARACTER_LANG_ID_PUNJABI_UNICODE_VALUE);
		        return IRE_LANGUAGE_ID_PUNJABI;
                    }
                }
        #endif /* defined(__MMI_LANG_PUNJABI__) */ 
        #if defined(__MMI_LANG_KANNADA__)
            case 0xA000:
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_CHARACTER_LANG_ID_KANNADA_UNICODE_VALUE);
		            return IRE_LANGUAGE_ID_KANNADA;
        #endif /* defined(__MMI_LANG_KANNADA__) */ 
        #if defined(__MMI_LANG_MALAYALAM__)
            case 0xA200:
                MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_CHARACTER_LANG_ID_MALAYALAM_UNICODE_VALUE);
                return IRE_LANGUAGE_ID_MALAYALAM;
        #endif /* defined(__MMI_LANG_MALAYALAM__) */ 
        #if defined(__MMI_LANG_SINHALA__)
            case 0xFBC0:
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_CHARACTER_LANG_ID_SINHALA_UNICODE_VALUE);
		            return IRE_LANGUAGE_ID_SINHALA;
        #endif /* defined(__MMI_LANG_SINHALA__) */ 
        #if defined(__MMI_LANG_TELUGU__)
            case 0xEC00:
            case 0xED00:
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_CHARACTER_LANG_ID_TELUGU_UNICODE_VALUE);
		            return IRE_LANGUAGE_ID_TELUGU;
        #endif /* defined(__MMI_LANG_TELUGU__) */ 
        #if defined(__MMI_LANG_ORIYA__)
            case 0xA300:
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_CHARACTER_LANG_ID_ORIYA_UNICODE_VALUE);
		            return IRE_LANGUAGE_ID_ORIYA;
        #endif /* defined(__MMI_LANG_ORIYA__) */ 
        #if defined(__MMI_LANG_TAMIL__)
            case 0xEE00:
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_CHARACTER_LANG_ID_TAMIL_UNICODE_VALUE);
		            return IRE_LANGUAGE_ID_TAMIL;
        #endif /* defined(__MMI_LANG_TAMIL__) */ 
            default:
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_CHARACTER_LANG_ID_INVALID_UNICODE_VALUE);
		            return IRE_LANGUAGE_ID_INVALID;
        }
    }
    else    /* standard unicode range */
    {

        switch (character & 0x0F00)
        {
        #if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__)

            case 0x0900:
        #if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__)
                if (!(character & 0x0080))
                {
                    return IRE_LANGUAGE_ID_HINDI;
                }
        #endif /* defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) */ 
        #if defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__)
                if (character & 0x0080)
                {
                    return IRE_LANGUAGE_ID_BENGALI;
                }
        #endif /* defined(__MMI_LANG_BENGALI__)  || defined(__MMI_LANG_ASSAMESE__) */ 
                return IRE_LANGUAGE_ID_INVALID;
        #endif /* defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__) */ 
        #if defined(__MMI_LANG_PUNJABI__) || defined(__MMI_LANG_GUJARATI__)
            case 0x0A00:
        #if defined(__MMI_LANG_PUNJABI__)
                if (!(character & 0x0080))
                {
                    return IRE_LANGUAGE_ID_PUNJABI;
                }
        #endif /* defined(__MMI_LANG_PUNJABI__) */ 
        #if defined(__MMI_LANG_GUJARATI__)
                if (character & 0x0080)
                {
                    return IRE_LANGUAGE_ID_GUJARATI;
                }
        #endif /* defined(__MMI_LANG_GUJARATI__) */ 
                return IRE_LANGUAGE_ID_INVALID;
        #endif /* defined(__MMI_LANG_PUNJABI__) || defined(__MMI_LANG_GUJARATI__) */ 
        #if defined(__MMI_LANG_ORIYA__) || defined(__MMI_LANG_TAMIL__)
            case 0x0B00:
        #if defined(__MMI_LANG_ORIYA__)
                if (!(character & 0x0080))
                {
                    return IRE_LANGUAGE_ID_ORIYA;
                }
        #endif /* defined(__MMI_LANG_ORIYA__) */ 
        #if defined(__MMI_LANG_TAMIL__)
                if (character & 0x0080)
                {
                    return IRE_LANGUAGE_ID_TAMIL;
                }
        #endif /* defined(__MMI_LANG_TAMIL__) */ 
                return IRE_LANGUAGE_ID_INVALID;
        #endif /* defined(__MMI_LANG_ORIYA__) || defined(__MMI_LANG_TAMIL__) */ 
        #if defined(__MMI_LANG_KANNADA__) || defined(__MMI_LANG_TELUGU__)
            case 0x0C00:
        #if defined(__MMI_LANG_TELUGU__)
                if (!(character & 0x0080))
                {
                    return IRE_LANGUAGE_ID_TELUGU;
                }
        #endif /* defined(__MMI_LANG_TELUGU__) */ 
        #if defined(__MMI_LANG_KANNADA__)
                if (character & 0x0080)
                {
                    return IRE_LANGUAGE_ID_KANNADA;
                }
        #endif /* defined(__MMI_LANG_KANNADA__) */ 
                return IRE_LANGUAGE_ID_INVALID;
        #endif /* defined(__MMI_LANG_KANNADA__) || defined(__MMI_LANG_TELUGU__) */ 
        #if defined(__MMI_LANG_SINHALA__) || defined(__MMI_LANG_MALAYALAM__)
            case 0x0D00:
        #if defined(__MMI_LANG_MALAYALAM__)
                if (!(character & 0x0080))
                {
                    return IRE_LANGUAGE_ID_MALAYALAM;
                }
        #endif /* defined(__MMI_LANG_MALAYALAM__) */ 
        #if defined(__MMI_LANG_SINHALA__)
                if (character & 0x0080)
                {
                    return IRE_LANGUAGE_ID_SINHALA;
                }
        #endif /* defined(__MMI_LANG_SINHALA__) */ 
                return IRE_LANGUAGE_ID_INVALID;
        #endif /* defined(__MMI_LANG_SINHALA__) || defined(__MMI_LANG_MALAYALAM__) */ 
            default:
                return IRE_LANGUAGE_ID_INVALID;
        }
    }
}
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)
S32 ire_check_cluster_for_length(PU8 cluster)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	S32 ret = 0, tempCount = 0;
	U16 curr_char_16 = 0, next_char_16 = 0;
	PU8 curr_cluster = cluster;
	S32 mCharacterStatusFlag = 0, mCharacterStatusFlag_next = 0, langIdIndex= 0;
	 ire_indic_languages_table_struct indic_lang_table_info; 
	S32 curr_char_test = 0, prev_char_test = 0;
	MMI_BOOL initial_state = MMI_TRUE, ire_fill_char = MMI_FALSE, is_reorder = MMI_FALSE;
	  U16 startRange = 0;             /* to store the starting range of language of input character */
    U16 endRange = 0; 
	const ire_character_info_table_struct *char_status_flag_p; 
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	   
	if(*curr_cluster == NULL)
		return 0;

	curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(curr_cluster));
	next_char_16 = (IRE_LANG_ID_CONVERT_U8_U16((curr_cluster)+2));
	ret++;

	if (!IRE_INDIC_LANGUAGE_RANGE(IRE_LANG_ID_CONVERT_U8_U16(curr_cluster)))
	{
		MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_CLUSTER_NON_INDIC_CHARACTER);
		return ret;
	}
	IRE_GET_CHARACTER_LANG_ID_FROM_PREV_CHAR((U16) IRE_LANG_ID_CONVERT_U8_U16(curr_cluster), langIdIndex);
    IRE_SET_PREV_CHAR_LANG_ID(langIdIndex);
    
    IRE_SET_PREV_CHAR_INFO_TABLE_FROM_CHAR_INFO_TABLE(langIdIndex);
    
    startRange = indic_lang_table_info.start_range;
    
    endRange = indic_lang_table_info.end_range;
    char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;
	IRE_IDENTIFY_CHARACTER(next_char_16, char_status_flag_p, startRange, mCharacterStatusFlag_next);
	IRE_IDENTIFY_CHARACTER(curr_char_16, char_status_flag_p, startRange,mCharacterStatusFlag);
	while(curr_char_16)
	{
		if((curr_char_16<startRange) || (curr_char_16>endRange))
		{
			return ret;
		}
		if(!(mCharacterStatusFlag ^ NORMAL_CON)) 
		{
				if(next_char_16 == NULL)
				{
					curr_cluster += 2;
					curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(curr_cluster));
					break;
				}
				else if((!(mCharacterStatusFlag_next ^ HALANT))||(!(mCharacterStatusFlag_next ^ PRE_BASE_DEPVOWEL))||(!(mCharacterStatusFlag_next ^ POST_BASE_DEPVOWEL))||(!(mCharacterStatusFlag_next ^ CENTER_BASE_DEPVOWEL))||(!(mCharacterStatusFlag_next ^ BELOW_BASE_DEPVOWEL))||(!(mCharacterStatusFlag_next ^ ABOVE_BASE_DEPVOWEL)))
				{	
					curr_cluster += 2;
					curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(curr_cluster));
					ret++;		
				}
				else
				{
					ire_fill_char = MMI_TRUE;
					break;
				}
			}
			else if(!(mCharacterStatusFlag ^ RA_CON))	
			{
				if(next_char_16 == NULL)
				{
					curr_cluster += 2;
					curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(curr_cluster));
					is_reorder = MMI_TRUE;
					break;
				}
				else if((!(mCharacterStatusFlag_next ^ HALANT))||(!(mCharacterStatusFlag_next ^ PRE_BASE_DEPVOWEL))||(!(mCharacterStatusFlag_next ^ POST_BASE_DEPVOWEL))||(!(mCharacterStatusFlag_next ^ CENTER_BASE_DEPVOWEL))||(!(mCharacterStatusFlag_next ^ BELOW_BASE_DEPVOWEL))||(!(mCharacterStatusFlag_next ^ ABOVE_BASE_DEPVOWEL)))
				{	
					curr_cluster += 2;
					curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(curr_cluster));
					ret++;		
				}
				else
				{
					ire_fill_char = MMI_TRUE;
					break;
				}
			}
			else if(!(mCharacterStatusFlag ^ INDEPVOWEL))
			{
				if((!(mCharacterStatusFlag_next ^ NORMALSIGN)))
				{
					curr_cluster += 2;
					curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(curr_cluster));;
					ret++;
					break;
				}
				else
				{
					ire_fill_char = MMI_TRUE;
					break;
				}
			}
			else if(!(mCharacterStatusFlag ^ HALANT))
			{
				if(next_char_16 == NULL)
				{
					break;
				}
				else if((!(mCharacterStatusFlag_next ^NORMAL_CON)) ||(!(mCharacterStatusFlag_next ^ RA_CON)))
				{
					curr_cluster += 2;
					curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(curr_cluster));
					ret++;				
				}
				else
				{
					ire_fill_char = MMI_TRUE;
					break;
				}		
			}
			else if(!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL))
			{
				if((!(mCharacterStatusFlag_next ^ NORMALSIGN)))
				{
					curr_cluster += 2;
					curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(curr_cluster));;
					ret++;
					break;
				}
				else
				{
					ire_fill_char = MMI_TRUE;
					break;
				}
			}
			else if(!(mCharacterStatusFlag ^ PRE_BASE_DEPVOWEL)) 
			{
				if((!(mCharacterStatusFlag_next ^ NORMALSIGN)))
				{
					curr_cluster += 2;
					curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(curr_cluster));;
					ret++;
					break;
				}
				else
				{
					ire_fill_char = MMI_TRUE;
					break;
				}
			}
			else if(!(mCharacterStatusFlag ^ CENTER_BASE_DEPVOWEL) || (!(mCharacterStatusFlag ^ BELOW_BASE_DEPVOWEL))||(!(mCharacterStatusFlag ^ ABOVE_BASE_DEPVOWEL))) 
			{
				if((!(mCharacterStatusFlag_next ^ NORMALSIGN)))
				{
					curr_cluster += 2;
					curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(curr_cluster));;
					ret++;
					break;
				}
				else
				{
					ire_fill_char = MMI_TRUE;
					break;
				}
			}
			else if(!(mCharacterStatusFlag ^ NORMALSIGN))
			{
				ire_fill_char = MMI_TRUE;
				break;
			}
			else
			{
			break;
			}
		curr_char_16 = next_char_16;
		next_char_16 = (IRE_LANG_ID_CONVERT_U8_U16((curr_cluster)+2));
		mCharacterStatusFlag = mCharacterStatusFlag_next;
		IRE_IDENTIFY_CHARACTER(next_char_16, char_status_flag_p, startRange, mCharacterStatusFlag_next);
	
		}	
	return ret;	
}
	

#endif
#if defined(__MMI_IRE_SLIM__)
 void ire_fill_display_cluster2(PU16 start_cluster, U16 curr_char)
 {
	start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = curr_char;
	g_indic_rule_engine_cntx.g_display_buffer_len++;
 }					
/*****************************************************************************
 * FUNCTION
 *  ire_fill_display_character
 * DESCRIPTION			
 *  This method will identifies the characters which will participate in 
 *  cluster formation 
 * PARAMETERS
 *  cluster     [IN]    Buffer to be filled with characters
 *                      (which will participate in cluster formation)
 * RETURNS
 *  S32 The number of characters which will form cluster
 *****************************************************************************/
void ire_reorder_ra_hal_con_seq(PU16 curr_cluster)
{
	S32 tempCount = 0, i = 0;
	U16 uTempVar = 0;

	for(i = 0; i<2;i++)
	{
		uTempVar = curr_cluster[0];                                        
		for (tempCount = 0; tempCount < g_indic_rule_engine_cntx.g_display_buffer_len - 1; tempCount++)          
		{                                                                   
			curr_cluster[tempCount] = curr_cluster[tempCount + 1];         
		}                                                                   
		curr_cluster[tempCount] = uTempVar;      
	}
}
void ire_reorder_centerbase_dep_vowel(PU16 start_cluster,const ire_glyph_info_table_struct * char_table_p)
{
	S32 size = 0, tempCount = 0;
	U16 uTempVar = 0;
	uTempVar = start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len - 1];
	for (tempCount = g_indic_rule_engine_cntx.g_display_buffer_len - 2; tempCount >= 0; tempCount--)
	{
		start_cluster[tempCount + 1] = start_cluster[tempCount];
	}
	start_cluster[0]		        = char_table_p[size].output_buffer_glyph[0];
	start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len]			= uTempVar;
	start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len + 1]		= char_table_p[size].output_buffer_glyph[1];
}
/*****************************************************************************
 * FUNCTION
 *  ire_character_type
 * DESCRIPTION			
 *  This method will identifies the characters which will participate in 
 *  cluster formation 
 * PARAMETERS
 *  cluster     [IN]    Buffer to be filled with characters
 *                      (which will participate in cluster formation)
 * RETURNS
 *  S32 The number of characters which will form cluster
 *****************************************************************************/
S32 ire_character_type(U16 curr_char_16, ire_prev_char_struct* g_character_information)
{
	S32 mCharStatusFlag = ire_character_info(curr_char_16, g_character_information);

	switch (mCharStatusFlag & MASK_HIGHER_ORDER_BYTES)
    {
            case NORMAL_CON:        /* 0x00000001 */
				return NORMAL_CON;
            case SMALL_CON:         /* 0x00000003 */
				return SMALL_CON;
			case RA_CON:            /* 0x00000002 */
				return RA_CON;
			case KANNADA_RA_CON:    /* 0x00000004 */
				return KANNADA_RA_CON;

			case CHILLU_CHARACTER:  /* 0x00000005 */
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_IDENTIFY_CHARACTER_TYPE_CONSONANT, IRE_CHAR_TYPE_CON);
		            return CHILLU_CHARACTER;

            case INDEPVOWEL:    /* 0x00000040 */
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_IDENTIFY_CHARACTER_TYPE_INDEPVOWEL, IRE_CHAR_TYPE_INDEPVOWEL);
		            return INDEPVOWEL;

            case PRE_BASE_DEPVOWEL:     /* 0x00000008 */
				return PRE_BASE_DEPVOWEL;

			case POST_BASE_DEPVOWEL:    /* 0x00000010 */
				return POST_BASE_DEPVOWEL;

			case CENTER_BASE_DEPVOWEL:  /* 0x00000028 */
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_IDENTIFY_CHARACTER_TYPE_DEPVOWEL, IRE_CHAR_TYPE_DEPVOWEL);
		            return CENTER_BASE_DEPVOWEL;

            case NORMALSIGN:    /* 0x00000100; */
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_IDENTIFY_CHARACTER_TYPE_SIGN, IRE_CHAR_TYPE_SIGN);
                return NORMALSIGN;

			case TAMIL_HALANT_SIGN:
                return TAMIL_HALANT_SIGN;

            case HALANT:    /* 0x00000080 */
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_IDENTIFY_CHARACTER_TYPE_HALANT, IRE_CHAR_TYPE_HALANT);
		            return HALANT;

            case LIGATURE:  /* 0x00000200 */
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_IDENTIFY_CHARACTER_TYPE_LIGATURE, IRE_CHAR_TYPE_LIGATURE);
		            return LIGATURE;

            case DIGITS:    /* 0x00000800 */
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_IDENTIFY_CHARACTER_TYPE_DIGIT, IRE_CHAR_TYPE_DIGIT);
		            return DIGITS;

            default:
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_IDENTIFY_CHARACTER_TYPE_INVALID, IRE_CHAR_TYPE_INVALID);
		            return IRE_CHAR_TYPE_INVALID;
        }

}
/*****************************************************************************
 * FUNCTION
 *  ire_get_cluster
 * DESCRIPTION			
 *  This method will identifies the characters which will participate in 
 *  cluster formation 
 * PARAMETERS
 *  cluster     [IN]    Buffer to be filled with characters
 *                      (which will participate in cluster formation)
 * RETURNS
 *  S32 The number of characters which will form cluster
 *****************************************************************************/
S32 ire_get_cluster(PU16 cluster)
{  
    /*------------------------------------ ----------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U32 langIdIndex = 0, character_position=0;
    S32 ret = 0, tempCount = 0;
    U16 curr_char_16 = 0, prev_char_16 = 0, uTempVar = 0;
    PU16 curr_cluster = cluster;
    ire_prev_char_struct g_character_information;
    S32 mCharacterStatusFlag = 0, mCharacterStatusFlag_prev = 0, nsize = 0;
    #if defined (__MMI_LANG_MYANMAR__) || defined (__MMI_LANG_KHMER__)
    S32 mCharacterStatusInfo = 0, mCharacterStatusInfo_prev = 0;
    MMI_BOOL entry_pre_vowel_after_vowel_flag = MMI_FALSE, vowel_character_after_con_post_vowel_is_allowed = MMI_FALSE;
    #endif
    MMI_BOOL con_pre_vowel = MMI_FALSE, con_post_vowel = MMI_FALSE, con_sign = MMI_FALSE;
    S32 con_matra_position = 0, input_len_after_con_post_vowel = 0;
    PU8 start_char_8 = g_indic_rule_engine_cntx.g_cluster_start_p;  
	MMI_BOOL ire_fill_char = MMI_FALSE, is_cons_tamil_hal = MMI_FALSE, is_tamil_ValidRuleEntryExist = MMI_FALSE, is_first_entry_small_cons = MMI_FALSE, is_first_entry_kannada_ra_con = MMI_FALSE;
    MMI_BOOL is_ra_hal = MMI_FALSE, is_ra_hal_con = MMI_FALSE, is_ra_con = MMI_FALSE, small_con_hal_small_con = MMI_FALSE, small_hal_con_hal_con_hal = MMI_FALSE;
    MMI_BOOL is_kannada_ra_hal = MMI_FALSE, is_kannada_ra_hal_con = MMI_FALSE, is_chillu_character = MMI_FALSE, no_more_chillu_character_con = MMI_FALSE;
    ire_main_glyph_table_struct ind_table;
    const ire_main_glyph_table_struct *main_glyph_table_base_address_p;
	const ire_glyph_info_table_struct *char_table_p = NULL;  
    ire_indic_languages_table_struct indic_lang_table_info;
    g_is_ra_con = 0;
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    is_RA_hal_reordering = MMI_FALSE;
    IRE_RESET_SMALL_CONS_HALANT_FLAG();
    g_indic_rule_engine_cntx.g_display_buffer_len = 0;

    if((*start_char_8 == NULL) && (*(start_char_8 + 1) == NULL))
        return 0;

    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
    ret++;

    if (!IRE_INDIC_LANGUAGE_RANGE(IRE_LANG_ID_CONVERT_U8_U16(start_char_8)))
    {
        MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_CLUSTER_NON_INDIC_CHARACTER);
        ire_fill_display_cluster2(curr_cluster , curr_char_16);
        return ret;
    }
    IRE_GET_CHARACTER_LANG_ID_FROM_PREV_CHAR(curr_char_16, langIdIndex);
    indic_lang_table_info = indic_lang_char_info_table[langIdIndex];
    while(curr_char_16 && !(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX)&& ire_fill_char == MMI_FALSE)
    {
        mCharacterStatusFlag_prev = mCharacterStatusFlag;
        mCharacterStatusFlag = ire_character_type(curr_char_16, &g_character_information);
        #if defined (__MMI_LANG_MYANMAR__) || defined (__MMI_LANG_KHMER__)
        mCharacterStatusInfo_prev = 0;
        mCharacterStatusInfo = ire_character_info(curr_char_16, &g_character_information);
        #endif
        if (!IRE_INDIC_LANGUAGE_RANGE(curr_char_16))
        {
            break;

        }
        if (start_char_8 == g_indic_rule_engine_cntx.g_cluster_end_p)
        {
            cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = NULL;
            g_indic_rule_engine_cntx.g_cluster_start_p += 2*ret;
            return ret;
        }
        if (is_cons_tamil_hal && is_tamil_ValidRuleEntryExist)
        {
            if (!(mCharacterStatusFlag == NORMAL_CON
                || mCharacterStatusFlag == POST_BASE_DEPVOWEL
                || mCharacterStatusFlag == CENTER_BASE_DEPVOWEL
                || mCharacterStatusFlag == PRE_BASE_DEPVOWEL
                || mCharacterStatusFlag == TAMIL_HALANT_SIGN))
            {
                break;
            }
        }
        switch (mCharacterStatusFlag)
        {
        case NORMAL_CON:	
            {
                if(prev_char_16 == NULL)
                {
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                }
				else if((mCharacterStatusFlag_prev == HALANT))
                {	
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    ret++;
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                    if(is_ra_hal == MMI_TRUE)
                    {
                        is_ra_hal_con = MMI_TRUE;
                    }
                }
                else if(mCharacterStatusFlag_prev == TAMIL_HALANT_SIGN)
                {	
					if (is_cons_tamil_hal)
					{
                    main_glyph_table_base_address_p = indic_lang_table_info.indic_main_info_table_p;
                    ind_table = main_glyph_table_base_address_p[cluster[0] - indic_lang_table_info.start_range - 1];
                    char_table_p = ind_table.glyph_info_p;
                    nsize = ind_table.nsize;
                    if (ind_table.max_input_glyph_size > 2)
                    {
                            do
                            {
                                nsize--;
                                /* check the entries inside the rule table */
                                if((char_table_p[nsize].input_buffer_len == 1) || 
                                    ((mmi_ire_reverse_memcmp(char_table_p[nsize].input_buffer_glyph + 1, ((PU16)g_indic_rule_engine_cntx.g_cluster_start_p) + 1, 
                                    (U8)(char_table_p[nsize].input_buffer_len - 1)) == MMI_TRUE) &&
                                    (char_table_p[nsize].input_buffer_len != 1)))
                                    /* The pointers have been incrememnted to point to the second entry because we dont want the 
                                    first entries in the buffer to be compared */ 
                                {
                                    is_tamil_ValidRuleEntryExist = MMI_TRUE;
                                    break;
                                }

                            } while (char_table_p[nsize].input_buffer_len > 2);
                        }
                        if (is_tamil_ValidRuleEntryExist == MMI_FALSE)
                        {
                            ire_fill_char = MMI_TRUE;
                            break;
                        }

                        prev_char_16 = curr_char_16;
                        start_char_8 += 2;
                        curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                        ret++;
                        ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                    }
                    else
                    {
                        ire_fill_char = MMI_TRUE;
                    }
                }
                else if(mCharacterStatusFlag_prev == CHILLU_CHARACTER)
                {
                    if(no_more_chillu_character_con == MMI_TRUE)
                    {
                        ire_fill_char = MMI_TRUE;
                    }
                    else
                    {
                        prev_char_16 = curr_char_16;
                        start_char_8 += 2;
                        curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                        ret++;
                        ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                        is_chillu_character = MMI_TRUE;
                        if(g_indic_rule_engine_cntx.g_display_buffer_len >= 4)
                            no_more_chillu_character_con = MMI_TRUE;
                    }
                }
                else
                {
                    ire_fill_char = MMI_TRUE;
                }
                break;
            }
        case RA_CON:		
            {
                if(prev_char_16 == NULL)
                {
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    is_ra_con = MMI_TRUE;
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                }
                else if(mCharacterStatusFlag_prev == HALANT)
                {
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    ret++;
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                    if(is_ra_hal == MMI_TRUE)
                    {
                        is_ra_hal_con = MMI_TRUE;
                    }
                }
                else
                {
                    ire_fill_char = MMI_TRUE;
                }
                break;
            }
        case SMALL_CON: 	
            {
                if(prev_char_16 == NULL)
                {
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    is_first_entry_small_cons = MMI_TRUE;
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                }
                else if((mCharacterStatusFlag_prev == HALANT))
                {
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                    ret++;
                    if(is_first_entry_small_cons == MMI_TRUE)
                        small_con_hal_small_con = MMI_TRUE;
                    IRE_DOUBLE_SET_SMALL_CONS_HALANT_FLAG();
                    if(small_hal_con_hal_con_hal == MMI_TRUE)
                    {
                        small_hal_con_hal_con_hal = MMI_FALSE;
                    }
                    if(is_kannada_ra_hal == MMI_TRUE)
                    {
                        is_kannada_ra_hal_con = MMI_TRUE; 
                        IRE_DOUBLE_SET_SMALL_CONS_HALANT_FLAG();
                    }
                }
                else
                {
                    ire_fill_char = MMI_TRUE;
                }
                break;
            }
        case KANNADA_RA_CON:
            {
                if(prev_char_16 == NULL)
                {
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    is_first_entry_kannada_ra_con = MMI_TRUE;
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                }
                else if((mCharacterStatusFlag_prev == HALANT))
                {
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                    ret++;
                    if(is_first_entry_kannada_ra_con == MMI_TRUE)
                    {
                        is_first_entry_kannada_ra_con = MMI_FALSE;
                        is_ra_hal = MMI_FALSE;
                        small_con_hal_small_con = MMI_TRUE;
                        IRE_DOUBLE_SET_SMALL_CONS_HALANT_FLAG();
                        break;
                    }
                    small_con_hal_small_con = MMI_TRUE;
                    IRE_DOUBLE_SET_SMALL_CONS_HALANT_FLAG();
                    if(small_hal_con_hal_con_hal == MMI_TRUE)
                        small_hal_con_hal_con_hal = MMI_FALSE;
                }
                else
                {
                    ire_fill_char = MMI_TRUE;
                }
                break;
            }
        case CHILLU_CHARACTER:
            {
                if(no_more_chillu_character_con == MMI_TRUE)
                {
                    ire_fill_char = MMI_TRUE;
                }
                else if(prev_char_16 == NULL)
                {
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                    is_chillu_character = MMI_TRUE;
                }
                else if(mCharacterStatusFlag_prev == NORMAL_CON)
                {
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    ret++;
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                    is_chillu_character = MMI_TRUE;
                    if(g_indic_rule_engine_cntx.g_display_buffer_len >= 4)
                        no_more_chillu_character_con = MMI_TRUE;			
                }
                else
                {
                    ire_fill_char = MMI_TRUE;
                }
                break;
            }
        case INDEPVOWEL:
            {
                if(prev_char_16 == NULL)
                {
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                }
                else
                {
                    ire_fill_char = MMI_TRUE;
                }
                break;
            }
        case HALANT:
            {
                if(prev_char_16 == NULL)
                {
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                    ire_fill_char = MMI_TRUE;
                }
                else if((mCharacterStatusFlag_prev == NORMAL_CON) || (mCharacterStatusFlag_prev ==  CHILLU_CHARACTER))
                {
                    if(is_ra_hal_con == MMI_TRUE)
                    {
                        ire_reorder_ra_hal_con_seq(curr_cluster);
                        is_ra_hal_con = MMI_FALSE;
                        is_ra_con  = MMI_FALSE;
                        is_ra_hal = MMI_FALSE;
                    }
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    ret++;
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);			
                }
                else if((mCharacterStatusFlag_prev == SMALL_CON))
                {
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    ret++;
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                    if(small_con_hal_small_con == MMI_TRUE)
                    {
                        small_hal_con_hal_con_hal = MMI_TRUE;
                        IRE_RESET_SMALL_CONS_HALANT_FLAG();
                        small_con_hal_small_con = MMI_FALSE;
                    }
                    else if(is_kannada_ra_hal_con == MMI_TRUE)
                        is_kannada_ra_hal_con = MMI_FALSE;
                }
                else if((mCharacterStatusFlag_prev == KANNADA_RA_CON))
                {
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    ret++;
                    if(is_first_entry_kannada_ra_con == MMI_TRUE)
                        is_kannada_ra_hal = MMI_TRUE;
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                    if(small_con_hal_small_con == MMI_TRUE)
                    {
                        small_hal_con_hal_con_hal = MMI_TRUE;
                        IRE_RESET_SMALL_CONS_HALANT_FLAG();
                        small_con_hal_small_con = MMI_FALSE;
                    }
                }
                else if(mCharacterStatusFlag_prev == RA_CON)
                {
                    if(is_ra_hal_con == MMI_TRUE)
                    {
                        ire_reorder_ra_hal_con_seq(curr_cluster);
                        is_ra_hal_con = MMI_FALSE;
                        is_ra_con  = MMI_FALSE;
                        is_ra_hal = MMI_FALSE;
                    }
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    ret++;
                    if(is_ra_con == MMI_TRUE)
                        is_ra_hal = MMI_TRUE;
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                }
                else if (con_matra_position && (con_post_vowel || con_sign) && !is_ra_con)
                {
                    if (ret == con_matra_position)
                    {
                        prev_char_16 = curr_char_16;
                        start_char_8 += 2;
                        curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                        ret++;
                        ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                    }
                    else
                    {
                    }
                }
                else
                {
                    ire_fill_char = MMI_TRUE;
                }		
                if ( ret >= G_MAX -2)
                {
                    ire_fill_char = MMI_TRUE;
                }
                break;
            }
        case TAMIL_HALANT_SIGN:
            {
                if(prev_char_16 == NULL)
                {
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                    ire_fill_char = MMI_TRUE;
                }
                    else if (is_tamil_ValidRuleEntryExist)
                    {
                        prev_char_16 = curr_char_16;
                        start_char_8 += 2;
                        curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));;
                        ret++;
                        ire_fill_char = MMI_TRUE;
                        break;
                    }
                else if((mCharacterStatusFlag_prev == NORMAL_CON)  ||(mCharacterStatusFlag_prev == SMALL_CON) ||(mCharacterStatusFlag_prev == KANNADA_RA_CON)|| (mCharacterStatusFlag_prev ==  CHILLU_CHARACTER))
                {
                        if (ret > 1)
                        {
                            ire_fill_char = MMI_TRUE;
                            break;
                        }
                    if(is_ra_hal_con == MMI_TRUE)
                    {
                        ire_reorder_ra_hal_con_seq(curr_cluster);
                        is_ra_hal_con = MMI_FALSE;
                        is_ra_con  = MMI_FALSE;
                        is_ra_hal = MMI_FALSE;
                    }
                        is_cons_tamil_hal = MMI_TRUE;
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    ret++;
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                }
                else
                {
                    ire_fill_char = MMI_TRUE;
                }
                break;
            }
        case POST_BASE_DEPVOWEL:
            {
                if(prev_char_16 == NULL)
                {
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                    ire_fill_char = MMI_TRUE;
                    break;
                }
                if((mCharacterStatusFlag_prev == NORMAL_CON) || (mCharacterStatusFlag_prev == NORMALSIGN)||(mCharacterStatusFlag_prev == RA_CON))
                {
                    if (NORMAL_CON != mCharacterStatusFlag_prev && is_tamil_ValidRuleEntryExist)
                    {
                        ire_fill_char = MMI_TRUE;
                        break;
                    }
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    ret++;
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                    if(is_ra_hal_con == MMI_TRUE)
                    {
                        ire_reorder_ra_hal_con_seq(curr_cluster);
                        is_ra_hal_con = MMI_FALSE;
                        is_ra_con  = MMI_FALSE;
                        is_ra_hal = MMI_FALSE;
                        is_RA_hal_reordering = MMI_TRUE;
                    }
                    con_matra_position = ret;
                    con_post_vowel = MMI_TRUE;
                    break;
                }
                else if((mCharacterStatusFlag_prev == SMALL_CON))
                {
                    if(is_kannada_ra_hal_con == MMI_TRUE)
                    {
                        ire_reorder_ra_hal_con_seq(curr_cluster);
                        is_RA_hal_reordering = MMI_TRUE;
                        is_kannada_ra_hal_con = MMI_FALSE;
                    }
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                    ret++;
                    con_matra_position = ret;
                    con_post_vowel = MMI_TRUE;
                    character_position = ire_identify_char_position(prev_char_16);
                    if((small_con_hal_small_con == MMI_TRUE) && character_position != IRE_BELOW_AND_POST_BASE_POSITION)
                    {
                        for (tempCount = 1; tempCount <= ret - 2; tempCount++)
                        {
                            uTempVar = curr_cluster[ret - tempCount ];
                            curr_cluster[ret - tempCount] = curr_cluster[ret - tempCount - 1];
                            curr_cluster[ret - tempCount - 1 ] = uTempVar;
                        }
                    }

                    break;
                }
                else if((mCharacterStatusFlag_prev == KANNADA_RA_CON))
                {
                    if(is_kannada_ra_hal_con == MMI_TRUE)
                    {
                        ire_reorder_ra_hal_con_seq(curr_cluster);
                        is_RA_hal_reordering = MMI_TRUE;
                        is_kannada_ra_hal_con = MMI_FALSE;
                    }
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                    ret++;
                    IRE_DOUBLE_SET_SMALL_CONS_HALANT_FLAG();		
                    con_matra_position = ret;
                    con_post_vowel = MMI_TRUE;
                    break;
                }
                #if defined (__MMI_LANG_MYANMAR__) || defined (__MMI_LANG_KHMER__)
                else if (con_pre_vowel == MMI_TRUE)
                {
                    if (mCharacterStatusFlag_prev == PRE_BASE_DEPVOWEL || mCharacterStatusFlag_prev == POST_BASE_DEPVOWEL)
                    {
                        prev_char_16 = curr_char_16;
                        start_char_8 += 2;
                        curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                        ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                        ret++;
                        if (ret >= G_MAX -1)
                        {
                            ire_fill_char = MMI_TRUE;
                        }
                    }
                else
                {
                    ire_fill_char = MMI_TRUE;
                    break;
                }
            }
                #endif /*#if defined (__MMI_LANG_MYANMAR__) || defined (__MMI_LANG_KHMER__)*/
                else if (con_post_vowel == MMI_TRUE)
                {
                    if (mCharacterStatusFlag_prev == PRE_BASE_DEPVOWEL || mCharacterStatusFlag_prev == POST_BASE_DEPVOWEL)
                    {
                        prev_char_16 = curr_char_16;
                        start_char_8 += 2;
                        curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                        ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                        ret++;
                        if (mCharacterStatusFlag_prev == PRE_BASE_DEPVOWEL)
                        {
                            input_len_after_con_post_vowel = 2;
                        }
                        else
                        {
                            input_len_after_con_post_vowel = 1;
                        }
                        #if defined (__MMI_LANG_MYANMAR__) || defined (__MMI_LANG_KHMER__)
                        if (ret - con_matra_position == 1 && mCharacterStatusInfo & MASK_CHECK_ENTER_AFTER_VOWEL)
                        {
                            vowel_character_after_con_post_vowel_is_allowed = MMI_TRUE;
                        }
                        if (vowel_character_after_con_post_vowel_is_allowed)
                        {
                            input_len_after_con_post_vowel ++;
                        }
                        #endif /*#if defined (__MMI_LANG_MYANMAR__) || defined (__MMI_LANG_KHMER__)*/
                        if (ret - con_matra_position >= input_len_after_con_post_vowel)
                        {
                            ire_fill_char = MMI_TRUE;
                        }
                    }
                }
                else
				{
					ire_fill_char = MMI_TRUE;
				}
                break;
			}
        case PRE_BASE_DEPVOWEL: 
            {
                if(prev_char_16 == NULL)
                {
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                    ire_fill_char = MMI_TRUE;
                    break;
                }
				if((mCharacterStatusFlag_prev == NORMAL_CON)||(mCharacterStatusFlag_prev == RA_CON) || (mCharacterStatusFlag_prev == NORMALSIGN) || (is_tamil_ValidRuleEntryExist == MMI_TRUE))
                {
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));;
                    ret++;
                    if(is_ra_hal_con == MMI_TRUE)
                    {
                        ire_reorder_ra_hal_con_seq(curr_cluster);
                        is_ra_hal_con = MMI_FALSE;
                        is_ra_con  = MMI_FALSE;
                        is_ra_hal = MMI_FALSE;
                    }
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                    uTempVar = curr_cluster[ret - 1];
                    for (tempCount = ret - 2; tempCount >= 0; tempCount--)
                        curr_cluster[tempCount + 1] = curr_cluster[tempCount];
                    curr_cluster[0] = uTempVar;
                    if (is_tamil_ValidRuleEntryExist)
                    {
                        ire_fill_char = MMI_TRUE;
                        break;
                    }
                    con_matra_position = ret;
					con_pre_vowel = MMI_TRUE;
                    break;
                }
                else if((mCharacterStatusFlag_prev == SMALL_CON))
                {
                    if(is_kannada_ra_hal_con == MMI_TRUE)
                    {
                        ire_reorder_ra_hal_con_seq(curr_cluster);
                        is_kannada_ra_hal_con = MMI_FALSE;
                        is_RA_hal_reordering = MMI_TRUE;
                    }
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                    ret++;
                    uTempVar = curr_cluster[ret - 1];
                    for (tempCount = ret - 2; tempCount >= 0; tempCount--)
                        curr_cluster[tempCount + 1] = curr_cluster[tempCount];
                    curr_cluster[0] = uTempVar;
                    con_matra_position = ret;
                    con_pre_vowel = MMI_TRUE;
                    break;
                }
#if defined (__MMI_LANG_MYANMAR__) || defined (__MMI_LANG_KHMER__)
                else if (con_pre_vowel == MMI_TRUE)
                {
                    if (mCharacterStatusFlag_prev == PRE_BASE_DEPVOWEL)
                    {
                        if (mCharacterStatusInfo & MASK_CHECK_ENTER_AFTER_VOWEL && (MMI_FALSE == entry_pre_vowel_after_vowel_flag || con_post_vowel == MMI_TRUE))
                        {
                            prev_char_16 = curr_char_16;
                            start_char_8 += 2;
                            curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                            ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                            ret++;

                            uTempVar = curr_cluster[ret - 1];
                            for (tempCount = ret - 2; tempCount >= 0; tempCount--)
                                curr_cluster[tempCount + 1] = curr_cluster[tempCount];
                            curr_cluster[0] = uTempVar;

                            entry_pre_vowel_after_vowel_flag = MMI_TRUE;
                        }
                        else
                        {
                            ire_fill_char = MMI_TRUE;
                        }
                    }
                    else
                    {
                        ire_fill_char = MMI_TRUE;
                    }
                }
#endif
                else if (con_post_vowel == MMI_TRUE)
                {
                    input_len_after_con_post_vowel = 2;
                    if (mCharacterStatusFlag_prev == PRE_BASE_DEPVOWEL || mCharacterStatusFlag_prev == POST_BASE_DEPVOWEL)
                    {
                        prev_char_16 = curr_char_16;
                        start_char_8 += 2;
                        curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                        ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                        ret++;
                    }   
                    #if defined (__MMI_LANG_MYANMAR__) || defined (__MMI_LANG_KHMER__)
                    if (ret - con_matra_position == 1 && mCharacterStatusInfo & MASK_CHECK_ENTER_AFTER_VOWEL)
                    {
                        vowel_character_after_con_post_vowel_is_allowed = MMI_TRUE;
                    }
                    if (vowel_character_after_con_post_vowel_is_allowed)
                    {
                        input_len_after_con_post_vowel ++;
                    }
                    #endif /*#if defined (__MMI_LANG_MYANMAR__) || defined (__MMI_LANG_KHMER__)*/
                    if (ret - con_matra_position >= input_len_after_con_post_vowel)
                    {
                        ire_fill_char = MMI_TRUE;
                    }

                }
                else
                {
                    ire_fill_char = MMI_TRUE;
                    break;
                }
            }
            break;
        case CENTER_BASE_DEPVOWEL:
            {
                if(prev_char_16 == NULL)
                {
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                    ire_fill_char = MMI_TRUE;
                    break;
                }
                if((mCharacterStatusFlag_prev == NORMAL_CON)||(mCharacterStatusFlag_prev == RA_CON) || (mCharacterStatusFlag_prev == NORMALSIGN))
                {
                    if (NORMAL_CON != mCharacterStatusFlag_prev && is_tamil_ValidRuleEntryExist)
                    {
                        ire_fill_char = MMI_TRUE;
                        break;
                    }
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));;
                    ret++;
                    if(is_ra_hal_con == MMI_TRUE)
                    {
                        ire_reorder_ra_hal_con_seq(curr_cluster);
                        is_ra_hal_con = MMI_FALSE;
                        is_ra_con  = MMI_FALSE;
                        is_ra_hal = MMI_FALSE;
                    }
                    main_glyph_table_base_address_p = indic_lang_table_info.indic_main_info_table_p;
                    ind_table = main_glyph_table_base_address_p[prev_char_16 - indic_lang_table_info.start_range - 1];
                    char_table_p = ind_table.glyph_info_p;
                    ire_reorder_centerbase_dep_vowel(curr_cluster, char_table_p);
                    g_indic_rule_engine_cntx.g_display_buffer_len += 2;					
                    break;
                }
                else if((mCharacterStatusFlag_prev == SMALL_CON))
                {
                    if(is_kannada_ra_hal_con == MMI_TRUE)
                    {
                        ire_reorder_ra_hal_con_seq(curr_cluster);
                        is_kannada_ra_hal_con = MMI_FALSE;
                        is_RA_hal_reordering = MMI_TRUE;
                    }
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    ret++;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    main_glyph_table_base_address_p = indic_lang_table_info.indic_main_info_table_p;
                    ind_table = main_glyph_table_base_address_p[prev_char_16 - indic_lang_table_info.start_range - 1];
                    char_table_p = ind_table.glyph_info_p;
                    ire_reorder_centerbase_dep_vowel(curr_cluster, char_table_p);
                    g_indic_rule_engine_cntx.g_display_buffer_len += 2;
                    break;
                }
                else
                {
                    ire_fill_char = MMI_TRUE;
                    break;
                }
            }
        case BELOW_BASE_DEPVOWEL:
        case ABOVE_BASE_DEPVOWEL:
            {
                if(prev_char_16 == NULL)
                {
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                    ire_fill_char = MMI_TRUE;
                    break;
                }
                if((mCharacterStatusFlag_prev == NORMAL_CON))
                {
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));;
                    ret++;
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                    if(is_ra_hal_con == MMI_TRUE)
                    {
                        ire_reorder_ra_hal_con_seq(curr_cluster);
                        is_ra_hal_con = MMI_FALSE;
                        is_ra_con  = MMI_FALSE;
                        is_ra_hal = MMI_FALSE;
                    }
                    break;
                }
                else if((mCharacterStatusFlag_prev == SMALL_CON))
                {
                    if(is_kannada_ra_hal_con == MMI_TRUE)
                    {
                        ire_reorder_ra_hal_con_seq(curr_cluster);
                        is_kannada_ra_hal_con = MMI_FALSE;
                        is_RA_hal_reordering = MMI_TRUE;
                    }
                    prev_char_16 = curr_char_16;
                    ret++;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                    break;
                }
                else
                {
                    ire_fill_char = MMI_TRUE;
                    break;
                }
            }
        case NORMALSIGN:
            {
                if(prev_char_16 == NULL)
                {
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                    ire_fill_char = MMI_TRUE;
                    break;
                }
                if((mCharacterStatusFlag_prev == NORMAL_CON) ||(mCharacterStatusFlag_prev == RA_CON) ||(mCharacterStatusFlag_prev == KANNADA_RA_CON)|| (mCharacterStatusFlag_prev ==  CHILLU_CHARACTER) || (mCharacterStatusFlag_prev ==  INDEPVOWEL) || (mCharacterStatusFlag_prev == POST_BASE_DEPVOWEL) || (mCharacterStatusFlag_prev == PRE_BASE_DEPVOWEL) || (mCharacterStatusFlag_prev == CENTER_BASE_DEPVOWEL) || (mCharacterStatusFlag_prev == BELOW_BASE_DEPVOWEL) || (mCharacterStatusFlag_prev == ABOVE_BASE_DEPVOWEL))
                {
                    if(is_ra_hal_con == MMI_TRUE)
                    {
                        ire_reorder_ra_hal_con_seq(curr_cluster);
                        is_ra_hal_con = MMI_FALSE;
                        is_ra_con  = MMI_FALSE;
                        is_ra_hal = MMI_FALSE;
                    }
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));;
                    ret++;
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                    con_matra_position = ret;
                    con_sign = MMI_TRUE;
                    if (ret == 2)
                    {
                        is_ra_con  = MMI_FALSE;
                    }
                    if(is_kannada_ra_hal_con == MMI_TRUE)
                    {
                        ire_reorder_ra_hal_con_seq(curr_cluster);
                        is_kannada_ra_hal_con = MMI_FALSE;
                        is_RA_hal_reordering = MMI_TRUE;
                    }
                    break;
                }
                else if((mCharacterStatusFlag_prev == SMALL_CON))
                {
                    if(is_kannada_ra_hal_con == MMI_TRUE)
                    {
                        ire_reorder_ra_hal_con_seq(curr_cluster);
                        is_kannada_ra_hal_con = MMI_FALSE;
                        is_RA_hal_reordering = MMI_TRUE;
                    }
                    prev_char_16 = curr_char_16;
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                    ret++;
                    break;
                }
                #if defined (__MMI_LANG_MYANMAR__)
                else if (mCharacterStatusFlag_prev == NORMALSIGN)
                {
                    if (((mCharacterStatusInfo & MASK_LANG_SPECIFIC) >> 20) == IRE_SUPPORT_SIGN_SIGN_ENTRY)
                    {
                        prev_char_16 = curr_char_16;
                        start_char_8 += 2;
                        curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                        ire_fill_display_cluster2(curr_cluster ,prev_char_16);
                        ret++;
                        ire_fill_char = MMI_TRUE;
                        break;
                    }
                }
                #endif /*#if defined (__MMI_LANG_MYANMAR__)*/
                else
                {
                    ire_fill_char = MMI_TRUE;
                    break;
                }
            }
        default:
            {
                if(curr_char_16 == 0x200D)
                {
                    start_char_8 += 2;
                    curr_char_16 = (IRE_LANG_ID_CONVERT_U8_U16(start_char_8));
                    mCharacterStatusFlag = mCharacterStatusFlag_prev;
                    #if defined (__MMI_LANG_MYANMAR__) || defined (__MMI_LANG_KHMER__)
                    mCharacterStatusInfo = mCharacterStatusInfo_prev;
                    #endif
                    ret++;
                    break;
                }
                else if(prev_char_16 != NULL)
                {
                    ire_fill_char = MMI_TRUE;
                    break;
                }
                ire_fill_display_cluster2(curr_cluster ,curr_char_16);
                ire_fill_char = MMI_TRUE;
                break;
            }			
        }
        IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
            cluster,
            curr_char_16,
            indic_lang_table_info.start_range,
            indic_lang_table_info.end_range,
            ret);
    } 

    if(is_ra_hal_con == MMI_TRUE || is_kannada_ra_hal_con == MMI_TRUE)
    {
        ire_reorder_ra_hal_con_seq(curr_cluster);
        is_ra_hal_con = MMI_FALSE;
        if(is_first_entry_kannada_ra_con == MMI_TRUE)
            is_RA_hal_reordering = MMI_TRUE;
        is_kannada_ra_hal_con = MMI_FALSE;
        is_ra_con  = MMI_FALSE;
        is_ra_hal = MMI_FALSE;
        is_kannada_ra_hal = MMI_FALSE;
    }
    if(small_hal_con_hal_con_hal == TRUE)
    {
        for (tempCount = 1; tempCount <= ret - 2; tempCount++)
        {
            uTempVar = curr_cluster[ret - tempCount ];
            curr_cluster[ret - tempCount] = curr_cluster[ret - tempCount - 1];
            curr_cluster[ret - tempCount - 1 ] = uTempVar;
        }
    }
    curr_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16) NULL;
    g_indic_rule_engine_cntx.g_cluster_start_p += (ret * 2);
    return ret;
}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
U32 ire_character_info(U16 character, ire_prev_char_struct *  g_character_information)
{
	S32 langIdIndex = 0;
	U32 *temp = NULL;
	U32 temp2 = 0;
	IRE_GET_CHARACTER_LANG_ID_FROM_PREV_CHAR(character, langIdIndex);
    IRE_SET_PREV_CHAR_LANG_ID(langIdIndex);
	g_character_information->lang_id_index = langIdIndex;
	
	if (g_character_information->lang_id_index && IRE_INDIC_CHARACTER_UCS2_RANGE(character))
	{
		if (!(character & 0xE000))
    	{
        	/* get Indic language array index   */
        	g_indic_rule_engine_cntx.ire_prev_char_lang_id.ire_prev_char_table_info = indic_lang_char_info_table[langIdIndex];
			g_character_information->ire_prev_char_table_info = indic_lang_char_info_table[langIdIndex];
			(g_character_information->ire_prev_char_table_info).indic_char_info_flag_p += ((character - (g_character_information->ire_prev_char_table_info.start_range)) - 1);
			(g_character_information->ire_prev_char_table_info).indic_main_info_table_p += ((character - (g_character_information->ire_prev_char_table_info.start_range)) - 1);
	
		}
    	else
    	{
        	/* get Indic language ligature array index   */
      	 	g_indic_rule_engine_cntx.ire_prev_char_lang_id.ire_prev_char_table_info = indic_lang_ligature_info_table[langIdIndex];
      	 	g_character_information->ire_prev_char_table_info= indic_lang_ligature_info_table[langIdIndex];
			(g_character_information->ire_prev_char_table_info).indic_char_info_flag_p += ((character - (g_character_information->ire_prev_char_table_info.start_range)) - 1);

		}
		IRE_MODIFY_LIGATURE_RELATED_INFORMATION(
        	character,
        	g_character_information->ire_prev_char_table_info.indic_char_info_flag_p,
        	g_character_information->ire_prev_char_table_info.start_range,
        	g_character_information->ire_prev_char_table_info.end_range,
        	g_character_information->lang_id_index);
		temp = (U32 *) ((g_character_information->ire_prev_char_table_info.indic_char_info_flag_p));
		temp2 = * temp;
		return temp2;
	}
	return 0;
}


U32 ire_character_allignment_info(U32 mcharacter_status_flag)
{
	if (mcharacter_status_flag == 0)
    {
        return 0;
    }
	switch(mcharacter_status_flag & MASK_CHARACTER_ALIGNMENT)
	{
		case RIGHT_ALIGNED_CHARACTER:
			return IRE_RIGHT_ALIGNED_CHARACTER;
	}
	return IRE_NOT_A_LIGATURE;
	
}

/*****************************************************************************
 * FUNCTION
 *  ire_get_text_x
 * DESCRIPTION				
 *  This method will calculate the width, dwidth based upon the type of input 
 *  characters
 * PARAMETERS
 *  ptext_x                 [IN]
 *  current_character       [IN]        
 *  text_y                  [IN]        
 *  d_width                 [IN]        
 *  width                   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ire_get_text_x(S32 *ptext_x, U16 current_character, S32 text_y, U16 d_width, U16 width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 langIdIndex = 0;
    U8 is_Indic = 1;

    const ire_character_info_table_struct *char_status_flag_p = NULL;
	ire_prev_char_struct g_character_information;
	
    U32 mCharStatusFlag = 0;
    #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__))
    U32 mCharStatusFlagPrev = 0;
    U32 character_position=0;
    #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_TEXT_X);

	mCharStatusFlag = ire_character_info(current_character, &g_character_information);
	char_status_flag_p	= (g_character_information.ire_prev_char_table_info).indic_char_info_flag_p;
	langIdIndex = g_character_information.lang_id_index;
	/*	To check for THAI character	*/
    if ( current_character >= 0x0E01 && current_character <= 0x0E7F)
    {
        g_indic_rule_engine_cntx.g_prev_char_text_x = *ptext_x;
        g_indic_rule_engine_cntx.g_prev_char_dwidth = width;
        g_indic_rule_engine_cntx.g_prev_char_width = width;
        #if defined (__MMI_LANG_THAI__)
        if (IsThaiAboveLineChar(current_character))
        {
            g_indic_rule_engine_cntx.g_prev_char_dwidth = 0;
            g_indic_rule_engine_cntx.g_prev_char_width = 0;
        }
        #endif /* defined (__MMI_LANG_THAI__) */
        g_indic_rule_engine_cntx.g_prev_character = current_character;
        return;
    }
	/*	if language is NULL then there is no need for Dwidth	*/
    if (!langIdIndex)
    {
        d_width = width;
        g_indic_rule_engine_cntx.g_prev_char_dwidth = g_indic_rule_engine_cntx.g_prev_char_width;
        is_Indic = 0;
        if (r2lMMIFlag)
        {
            return;
        }
    }
	/*	In case of the First Character in the cluuster then there is no previous character width or dwidth hence no need for calculation*/
    if (!(g_indic_rule_engine_cntx.g_new_line))
    {
        g_indic_rule_engine_cntx.g_new_line = 1;
        if (langIdIndex)
        {
            *ptext_x = *ptext_x - g_indic_rule_engine_cntx.g_indic_padding;
        }
        g_indic_rule_engine_cntx.g_prev_char_text_x = *ptext_x;
        g_indic_rule_engine_cntx.g_prev_char_dwidth = d_width;
        g_indic_rule_engine_cntx.g_prev_char_width = width;
        g_indic_rule_engine_cntx.g_prev_character = current_character;
    #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__))
        g_indic_rule_engine_cntx.sign_cons_or_below_base = 0;
        IRE_SET_RENDERING_CORRECTION(current_character);
    #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__)) */ 
        return;
    }

    /*
     * As char might belong to indic range, but our product doesn't support that language
     * In that case, just fill the char as such, it could be in the form of square box.
     * so this check is required
     */
    #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__)) 
    character_position = ire_identify_char_position(current_character);
    #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__)) */

    if (char_status_flag_p != NULL)
    {
        #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__))
        
        if(langIdIndex == g_indic_rule_engine_cntx.ire_prev_char_lang_id.lang_id_index)
        {
            /* if not ligature range */
            mCharStatusFlagPrev = ire_character_info(g_indic_rule_engine_cntx.g_prev_character, &g_character_information);
            mCharStatusFlagPrev = mCharStatusFlagPrev & MASK_HIGHER_ORDER_BYTES;
        }
        
        if ((!g_indic_rule_engine_cntx.sign_cons_or_below_base) && 
             (character_position == IRE_BELOW_BASE_POSITION) &&
             (mCharStatusFlagPrev != NORMAL_CON))
        {
                if(g_indic_rule_engine_cntx.error_correction_for_rendering)
            {

                U8 correction = g_indic_rule_engine_cntx.error_correction_for_rendering;
                *ptext_x = g_indic_rule_engine_cntx.g_prev_char_text_x + correction;
                g_indic_rule_engine_cntx.g_prev_char_dwidth = correction + d_width;
                g_indic_rule_engine_cntx.g_prev_char_width = correction + width;
            }
            else
            {
                S32 curr_char_align = ire_character_allignment_info(mCharStatusFlag);
				MMI_BOOL need_check_alignment = (g_indic_rule_engine_cntx.g_prev_char_width < width)?MMI_FALSE: MMI_TRUE;
	            
				if (need_check_alignment && 
            		(curr_char_align == IRE_RIGHT_ALIGNED_CHARACTER))
				{
        			*ptext_x = g_indic_rule_engine_cntx.g_prev_char_text_x  + (g_indic_rule_engine_cntx.g_prev_char_width - width);
				}
				else
				{
					*ptext_x = g_indic_rule_engine_cntx.g_prev_char_text_x;
				}
            }
                IRE_RESET_RENDERING_CORRECTION();
            }
        else
    #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */ 
        if ((!((mCharStatusFlag & 0x0000F000) ^ ABOVE_BASE_POSITION) || 
        	 !((mCharStatusFlag & 0x0000F000) ^ BELOW_BASE_POSITION_IGNORE_CORRECTION_ATTRIBUTE))
        #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__))    
                 && (!(character_position==IRE_BELOW_BASE_POSITION))
        #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */
           )
        {
            S32 curr_char_align = ire_character_allignment_info(mCharStatusFlag);
            MMI_BOOL need_check_alignment = (g_indic_rule_engine_cntx.g_prev_char_width < width)?MMI_FALSE: MMI_TRUE;
            
			if (need_check_alignment && 
            	(curr_char_align == IRE_RIGHT_ALIGNED_CHARACTER))
            {
        		*ptext_x = g_indic_rule_engine_cntx.g_prev_char_text_x  + (g_indic_rule_engine_cntx.g_prev_char_width - width);
	        }
			else
			{
				*ptext_x = g_indic_rule_engine_cntx.g_prev_char_text_x;
			}
        }
        else
        {
			{
            if (is_Indic)
            {
                if (!(IRE_INDIC_CHARACTER_UCS2_RANGE(g_indic_rule_engine_cntx.g_prev_character)))
                {
                    g_indic_rule_engine_cntx.g_prev_char_text_x -= g_indic_rule_engine_cntx.g_indic_padding;
                }
            }
            *ptext_x = g_indic_rule_engine_cntx.g_prev_char_dwidth + g_indic_rule_engine_cntx.g_prev_char_text_x;
            g_indic_rule_engine_cntx.g_prev_char_text_x = *ptext_x;
            g_indic_rule_engine_cntx.g_prev_char_dwidth = d_width;
            g_indic_rule_engine_cntx.g_prev_char_width = width;
            #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__))
            IRE_SET_RENDERING_CORRECTION(current_character);
            #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */
			}
        }
    }
    else
    {
        if (is_Indic)
        {
            if (!(IRE_INDIC_CHARACTER_UCS2_RANGE(g_indic_rule_engine_cntx.g_prev_character)))
            {
                g_indic_rule_engine_cntx.g_prev_char_text_x -= g_indic_rule_engine_cntx.g_indic_padding;
            }
        }
        *ptext_x = g_indic_rule_engine_cntx.g_prev_char_dwidth + g_indic_rule_engine_cntx.g_prev_char_text_x;
        g_indic_rule_engine_cntx.g_prev_char_text_x = *ptext_x;
        g_indic_rule_engine_cntx.g_prev_char_dwidth = d_width;
        g_indic_rule_engine_cntx.g_prev_char_width = width;
        #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__))
        IRE_RESET_RENDERING_CORRECTION();
        #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */
    }
    g_indic_rule_engine_cntx.g_prev_character = current_character;
#if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__))
    if( (character_position == IRE_BELOW_BASE_POSITION) || 
    	(!((mCharStatusFlag & 0x0000F000) ^ BELOW_BASE_POSITION_IGNORE_CORRECTION_ATTRIBUTE)) )
    {
        g_indic_rule_engine_cntx.sign_cons_or_below_base = 1;
    }
    else
    {
        g_indic_rule_engine_cntx.sign_cons_or_below_base =0;
    }
#endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */ 
    return;
}



/*****************************************************************************
 * FUNCTION
 *  ire_language_rules
 * DESCRIPTION			
 *  This method will apply grammer rules on the input cluster buffer
 *  and copy the output buffer i.e glyphoutput
 * PARAMETERS
 *  glyphoutput     [IN]        
 *  cluster         [IN]        
 *  nentry          [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/


S32 ire_language_rules(PU16 glyphoutput, PU16 cluster, S32 nentry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 size;
    S32 noutglyph = 0;      /* no. of entries in output cluster to be given to renderer */
    S32 matched = FALSE;
    S32 input = nentry;
    S32 tomatch = nentry;   /* nentries--no. of elements in the cluster */
    S32 is_last_char_halant = MMI_FALSE; /* to check weather the last character in the cluster is halant */
    U32 langIdIndex = 0;    /* to store the value of language Id of input character */
    U32 mCharStatusFlagPrev = 0;
    U32 mCharStatusFlag = 0;
    U32 mCharStatusFlagNext = 0;
    U16 startRange = 0;     /* to store the starting range of language of input character */
    U16 is_input_buffer_cpy = MMI_FALSE;
    S32 temp = 0;
	ire_prev_char_struct g_character_information;
#if defined (__MMI_LANG_TELUGU__)
    U8 check_seq_KA_hal_SSA = MMI_FALSE;
    PU16 pglyphoutput = NULL;
#endif /* defined (__MMI_LANG_TELUGU__) */    
#if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__))
    U8 telugu_kannada_check = 0;
#endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */ 

    const ire_main_glyph_table_struct *main_glyph_table_base_address_p = NULL;
    const ire_character_info_table_struct *char_status_flag_p = NULL;
    const ire_glyph_info_table_struct *char_table_p;    /* pointer to character table containing ligature info   of that character */
    ire_main_glyph_table_struct ind_table;              /* main table containing full character table info */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_LANGUAGE_RULES);
     IRE_GET_CHARACTER_LANG_ID_FROM_PREV_CHAR((*cluster), langIdIndex);
    IRE_SET_PREV_CHAR_LANG_ID(langIdIndex);
    switch(langIdIndex) 
    {
        #if defined (__MMI_LANG_KHMER__)
        case IRE_LANGUAGE_ID_KHMER:
            ire_adjust_after_language_rules_for_khmer_before_rules(cluster, nentry);
            break;
        #endif /* defined (__MMI_LANG_KHMER__) */
        default:
            break;
    }
    if (IRE_INDIC_CHARACTER_UCS2_RANGE(*cluster))
    {
        /*  if number of entries are single  */
        if (nentry == 1)
        {
			glyphoutput[0] = *cluster;
            glyphoutput[1] = (U16) NULL;
            return 1;
        }
        /* more than one entries   */
        while (nentry)
        {
        #if (defined (__MMI_LANG_TELUGU__) || defined(__MMI_LANG_KANNADA__))
            if ( (!telugu_kannada_check) && (IRE_GET_SMALL_CONS_HALANT_FLAG() == 2) )
            {
                telugu_kannada_check = 1;
            #if defined (__MMI_LANG_TELUGU__)
                if( nentry > 2 && cluster[0] == TELUGU_C_KA && cluster[2] == TELUGU_C_SSA)
                {
                 check_seq_KA_hal_SSA = MMI_TRUE;
                 pglyphoutput = glyphoutput;
                }
            #endif /* defined (__MMI_LANG_TELUGU__) */ 
                glyphoutput[0] = *cluster;
                glyphoutput[1] = (U16) NULL;
                glyphoutput++;
                cluster++;
                nentry--;
                noutglyph++;
            }
        #endif /* (defined (__MMI_LANG_TELUGU__) || defined(__MMI_LANG_KANNADA__)) */ 
            if (!(*cluster & 0xE000))
			{
				/* get Indic language array index   */
				mCharStatusFlag = ire_character_type(*cluster,  &g_character_information);
				startRange =  g_character_information.ire_prev_char_table_info.start_range;
				char_status_flag_p = g_character_information.ire_prev_char_table_info.indic_char_info_flag_p;
				main_glyph_table_base_address_p = g_character_information.ire_prev_char_table_info.indic_main_info_table_p;
				temp = 0;
			}
			else
				temp = -1;

            if (main_glyph_table_base_address_p != NULL && temp == 0)
            {
            	ind_table = main_glyph_table_base_address_p[temp];  /* gets the individual charactr's table in main table */
            }
            
            if ((temp < 0) || (ind_table.glyph_info_p == NULL) || main_glyph_table_base_address_p == NULL || temp > 0x200)
            {
                if(IRE_INDIC_CHARACTER_UCS2_RANGE(*cluster))
                {
                    *glyphoutput = *cluster;
                    nentry--;
                    noutglyph++;
                    cluster++;
                    glyphoutput++;
                    if(*cluster == (U16)NULL)
                    {
                        *glyphoutput = (U16)NULL;
                        break;
                    }
                    else
                    {
                        --tomatch;
                        continue;
                    }
                }
                else
                {
                    glyphoutput[nentry - 1] = *cluster;
                    glyphoutput[nentry] = (U16) NULL;
                    return nentry;
                }
            }
            char_table_p = ind_table.glyph_info_p;  /* holds the add. of individual character */
            size = ind_table.nsize;
            matched = FALSE;
            while (size)
            {
                size--;
                if ((tomatch != char_table_p[size].input_buffer_len)
		   #if (defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__))
                    || ((char_table_p[size].rule_language) &&
                        (char_table_p[size].rule_language != indic_rules_current_set_language))
		   #endif /* (defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__)) */
		    )
		   {
           		if (tomatch > char_table_p[size].input_buffer_len)
                {
                	break;
                }
                continue;
           }
				
		else if ((char_table_p[size].input_buffer_len == 1) || ((mmi_ire_reverse_memcmp(char_table_p[size].input_buffer_glyph + 1, cluster + 1, (U8)(char_table_p[size].input_buffer_len - 1)) == MMI_TRUE) && (char_table_p[size].input_buffer_len != 1)))
        {
        	mCharStatusFlag = ire_character_type(*cluster, &g_character_information);	
			switch (mCharStatusFlag)
            {
            case RA_CON:
            case KANNADA_RA_CON:
            {
            	if (noutglyph)
                {
                	mCharStatusFlagPrev = ire_character_type(*(cluster - 1),&g_character_information);
                }
                else
                {
                	mCharStatusFlag = 0;
                }
                mCharStatusFlagNext = ire_character_type(*(cluster + 1), &g_character_information);
                if (( (input >= 3) &&( (!(mCharStatusFlagPrev ^ NORMAL_CON)) || (!(mCharStatusFlagPrev ^ RA_CON)) ||(!(mCharStatusFlagPrev ^ POST_BASE_DEPVOWEL)) ) ) 
                /* FOR HANDLING REORDERING FOR kANNADA RA */
                #if defined(__MMI_LANG_KANNADA__)
                || 
                /* KANNADA_RA_CON + HALANT should be displayed as the output_buffer_glyph
                            * from the character_table, whenever we have some character/ligature in the
                            * glyphoutput buffer prior to this comnbination */
                ((!(mCharStatusFlag ^ KANNADA_RA_CON)) && (is_RA_hal_reordering) && (noutglyph != 0))
                #endif /* defined(__MMI_LANG_KANNADA__) */
                )
                {
                	memcpy(
                    glyphoutput,
                    char_table_p[size].output_buffer_glyph,
                    char_table_p[size].output_buffer_len * 2);
                    glyphoutput[char_table_p[size].output_buffer_len] = (U16) NULL;
                    break;
                }
                            else if (!(mCharStatusFlagNext ^ HALANT))
                            {
                                memcpy(
                                    glyphoutput,
                                    char_table_p[size].input_buffer_glyph,
                                    char_table_p[size].input_buffer_len * 2);
                                glyphoutput[char_table_p[size].input_buffer_len] = (U16) NULL;
								is_input_buffer_cpy = MMI_TRUE;
                                #if defined(__MMI_LANG_KANNADA__)
                                mCharStatusFlag = ire_character_info((*cluster), &g_character_information);
                                mCharStatusFlag = mCharStatusFlag & MASK_HIGHER_ORDER_BYTES;
                                if(!(mCharStatusFlag ^ KANNADA_RA_CON))
                                {
                                    /* if the cluster buffer contains RA + Halant + NULL,
                                     * then instead of displaying the input buffer glyph, 
                                     * display the ligature KANNADA_L_RA_HALANT
                                     */
                                    glyphoutput[0] = KANNADA_L_RA_HALANT;
                                    glyphoutput[1] = (U16)NULL;
                                    
                                    /* The input buffer glyph contains 2 characters and noutglyph will be increased by 2 
                                     * but here we are displaying the ligature which has only 1 character, hence
                                     * glyphoutput and noutglyph are being reduced by 1 
                                     */
                                    glyphoutput -= 1;
                                    noutglyph -= 1;
                                }
                                #endif /* defined(__MMI_LANG_KANNADA__) */
                                break;
                            }
							else
							{
                                memcpy(
                                    glyphoutput,
                                    char_table_p[size].output_buffer_glyph,
                                    char_table_p[size].output_buffer_len * 2);
                                glyphoutput[char_table_p[size].output_buffer_len] = (U16) NULL;
                                break;
							 }
                        }   /* End of case RA statement */
                        default:
                        {
                            /* identifying the last character in the global display buffer */
                            mCharStatusFlag = ire_character_type(*(cluster + tomatch -1),&g_character_information);
				
                            /* checking that whether the HALANT is the last character in the global display buffer */
                            if ((!((mCharStatusFlag) ^ HALANT)) && (*(cluster + tomatch) == (U16) NULL))
                            {
                                if (char_table_p[size].is_con_hal_ligature == 0)
                                {
									if((tomatch <= 2))
                                    {
                                        memcpy(
                                            glyphoutput,
                                            char_table_p[size].input_buffer_glyph,
                                            char_table_p[size].input_buffer_len * 2);
                                        glyphoutput[char_table_p[size].input_buffer_len] = (U16) NULL;
                                        is_input_buffer_cpy = MMI_TRUE;
                                        break;
                                    }
                                    
                                    
	                                
                                    /* if we dont have the combination (RA + Hal) or (Hal + Hal) */
                                    if(!is_RA_hal_reordering) /* if not set global RA_reorder flag */
                                    {            
                                        is_last_char_halant = MMI_TRUE;
                                        break; /* break from default */
                                    }
                                }
                            }
                            memcpy(
                                glyphoutput,
                                char_table_p[size].output_buffer_glyph,
                                char_table_p[size].output_buffer_len * 2);
                            glyphoutput[char_table_p[size].output_buffer_len] = (U16) NULL;
                            break;
                          
                        }   /* End of default statement */
                    }       /* End of switch case   */

                    if(is_last_char_halant)
                    {
                        is_last_char_halant = MMI_FALSE;
                        continue; /* continue with the inner while loop */
                    }
                    nentry -= char_table_p[size].input_buffer_len;
                    cluster += char_table_p[size].input_buffer_len;

                    if (is_input_buffer_cpy)
                    {
                        glyphoutput += char_table_p[size].input_buffer_len;
                        noutglyph += char_table_p[size].input_buffer_len;
                        is_input_buffer_cpy = MMI_FALSE;
                    }
                    else
                    {
                        glyphoutput += char_table_p[size].output_buffer_len;
                        noutglyph += char_table_p[size].output_buffer_len;
                    }
                    matched = TRUE;

                    mCharStatusFlag = ire_character_info((*cluster), &g_character_information);
                                

                #if defined (__MMI_LANG_TAMIL__)
					mCharStatusFlag = ire_character_info((*cluster), &g_character_information);
                    mCharStatusFlag = mCharStatusFlag & MASK_HIGHER_ORDER_BYTES;
                    if ((*(glyphoutput - 1) == TAMIL_L_KSHA) &&
                             (!((mCharStatusFlag) ^ CENTER_BASE_DEPVOWEL)))
                    {
                        /* centre base handling */
                        ind_table = main_glyph_table_base_address_p[((*cluster) - startRange) - 1];     /* gets the individual charactr's table in main table */
                        char_table_p = ind_table.glyph_info_p;  /* holds the add. of individual character */
                        switch (*(glyphoutput - 1))
                        {
                            case TAMIL_L_KSHA:
                            {
                                *(glyphoutput - 1) = char_table_p[0].output_buffer_glyph[0];
                                *(glyphoutput) = TAMIL_L_KSHA;
                                *(glyphoutput + 1) = char_table_p[0].output_buffer_glyph[1];
                                break;
                            }
                            default:
                                break;
                        }
                        *(glyphoutput + 2) = (U16) NULL;
                        nentry -= 1;
                        cluster += 1;
                        noutglyph += 2;
                        matched = TRUE;
                        break;
                    }   /* End of else if statement */
                #endif /* defined (__MMI_LANG_TAMIL__) */ 
                    break;
                }
            }   /*   End of inner while loop */
            if (matched != TRUE && tomatch)
            {
                --tomatch;
            }
            else
            {
                tomatch = nentry;
            }
        }   /* End of outer while loop */
  MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_LANGUAGE_RULES_NOUTGLYPH, noutglyph);
	  #if defined (__MMI_LANG_TELUGU__)
        if (check_seq_KA_hal_SSA)
        {
            U8 index = 0;

            while (pglyphoutput[index] != (U16) NULL)
            {
                if (pglyphoutput[index] == (U16) TELUGU_L_SMALL_SSA)
                {
                    pglyphoutput[index] = (U16) TELUGU_L_KSHA_HALANT;
                    break;
                }
                index++;
            }

        }
    #endif /* defined (__MMI_LANG_TELUGU__) */ 
        
        /* Some times after the language rules have been applied to the API, we need to adjuct/reorder some of the
         * character for this we will call a function corresponding to a specific language to adjust/reorder the 
         * characters, according to the requirement
         */
        switch(langIdIndex) 
        {
            #if defined (__MMI_LANG_MALAYALAM__)
            case IRE_LANGUAGE_ID_MALAYALAM:
                ire_adjust_after_language_rules_for_malayalam(glyphoutput, noutglyph);
                break;
            #endif /* defined (__MMI_LANG_MALAYALAM__) */
            #if defined (__MMI_LANG_KANNADA__)
            case IRE_LANGUAGE_ID_KANNADA:
                ire_adjust_after_language_rules_for_kannada(glyphoutput, noutglyph);
                break;
            #endif /* defined (__MMI_LANG_KANNADA__) */
            #if defined (__MMI_LANG_TELUGU__)
            case IRE_LANGUAGE_ID_TELUGU:
                ire_adjust_after_language_rules_for_telugu(glyphoutput, noutglyph);
                break;
            #endif /* defined (__MMI_LANG_TELUGU__) */
			#if defined (__MMI_LANG_MYANMAR__)
            case IRE_LANGUAGE_ID_MYANMAR:
                ire_adjust_after_language_rules_for_myanmar(glyphoutput, noutglyph);
                break;
            #endif /* defined (__MMI_LANG_KHMER__) */
				#if defined (__MMI_LANG_KHMER__)
            case IRE_LANGUAGE_ID_KHMER:
                ire_adjust_after_language_rules_for_khmer(glyphoutput, noutglyph);
                break;
            #endif /* defined (__MMI_LANG_KHMER__) */
            default:
                break;
        }
            
        return noutglyph;
    }   /* End of if statement */
    else
    {
        glyphoutput[0] = *cluster;
        glyphoutput[1] = (U16) NULL;
        return 1;
    }
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined (__MMI_LANG_TELUGU__)
/* under construction !*/
/* under construction !*/
#endif /* defined (__MMI_LANG_TELUGU__) */    
#if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__))
/* under construction !*/
#endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if defined (__MMI_LANG_KHMER__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* defined (__MMI_LANG_KHMER__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (defined (__MMI_LANG_TELUGU__) || defined(__MMI_LANG_KANNADA__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #if defined (__MMI_LANG_TELUGU__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* defined (__MMI_LANG_TELUGU__) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* (defined (__MMI_LANG_TELUGU__) || defined(__MMI_LANG_KANNADA__)) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		   #if (defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__))
/* under construction !*/
/* under construction !*/
		   #endif /* (defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__)) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                                 #if defined(__MMI_LANG_KANNADA__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                                 #endif /* defined(__MMI_LANG_KANNADA__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
								#if defined(__MMI_MULTITAP_BANGLA_SPEC__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                                #if defined(__MMI_LANG_KANNADA__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                                #endif /* defined(__MMI_LANG_KANNADA__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
										#if defined (__MMI_LANG_KHMER__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
										#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
										#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #if defined (__MMI_LANG_TAMIL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif /* defined (__MMI_LANG_TAMIL__) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	  #if defined (__MMI_LANG_TELUGU__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined (__MMI_LANG_TELUGU__) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #if defined (__MMI_LANG_MALAYALAM__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* defined (__MMI_LANG_MALAYALAM__) */
            #if defined (__MMI_LANG_KANNADA__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* defined (__MMI_LANG_KANNADA__) */
            #if defined (__MMI_LANG_TELUGU__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* defined (__MMI_LANG_TELUGU__) */
			#if defined (__MMI_LANG_MYANMAR__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* defined (__MMI_LANG_KHMER__) */
				#if defined (__MMI_LANG_KHMER__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* defined (__MMI_LANG_KHMER__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#else

/*****************************************************************************
 * FUNCTION
 *  ire_get_cluster
 * DESCRIPTION			
 *  This method will identifies the characters which will participate in 
 *  cluster formation 
 * PARAMETERS
 *  cluster     [IN]    Buffer to be filled with characters
 *                      (which will participate in cluster formation)
 * RETURNS
 *  S32 The number of characters which will form cluster
 *****************************************************************************/
S32 ire_get_cluster(PU16 cluster)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nFill = 0;                  /* no. of elements filled in the cluster */
    S32 j = 0;                      /* loop counter */
    S32 i = 0;                      /* loop counter */
    S32 ch_index = 0;
    S32 size = 0;
    #if defined (__MMI_LANG_TAMIL__)
    S32 nsize = 0;
    #endif /* defined (__MMI_LANG_TAMIL__) */
    U32 langIdIndex = 0;            /* to store the value of language Id of input character */
    U32 mCharacterStatusFlag = 0;
    U32 mCharacterStatusFlagPrev = 0;
    U32 mCharacterStatusFlagNext = 0;
    U16 startRange = 0;             /* to store the starting range of language of input character */
    U16 endRange = 0;               /* to store the end range of language of input character */
    U16 temp = 0;                   /* temporary local variable to hold unicode value during runtime */
    PU16 start_cluster = cluster;   /* pointer to the begining of the buffer */
    U16 curr_char = 0, char_temp = 0;					/* for storing the current character in the logical buffer */
    PU8 start_char = g_indic_rule_engine_cntx.g_cluster_start_p;        /* pointer to the text pointer which is under consideration for cluster formation */
    #if defined (__MMI_LANG_TAMIL__)
    U8 isValidRuleEntryExist = MMI_FALSE;
    #endif /* defined (__MMI_LANG_TAMIL__) */
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)
	U16 start_character_temp = 0;
#endif
    U8 ire_continue_clustering = MMI_FALSE;
    U8 is_first_entry_ra_cons = MMI_FALSE;
    U8 ire_reordering_done = MMI_FALSE;
    U8 ire_is_chillu_character = MMI_FALSE;
    #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__))
    U8 is_first_entry_small_cons = MMI_FALSE;
    U8 temp_small_cons_halant_flag = 0;
    #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */ 
    const ire_glyph_info_table_struct *char_table_p;        /* pointer to character table containing ligature info   of that character */
    const ire_character_info_table_struct *char_status_flag_p;  /* pointer to a character info structure */
    const ire_main_glyph_table_struct *main_glyph_table_base_address_p;
    ire_indic_languages_table_struct indic_lang_table_info; /* store the Indic language table entry,(i.e structure info) */
    ire_main_glyph_table_struct ind_table;                  /* main table containing full character table info */
#if defined (__MMI_LANG_MYANMAR__) || defined (__MMI_LANG_KHMER__)
	U32 entry_of_vowel_allowed_flag = 0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_indic_rule_engine_cntx.g_display_buffer_len = 0;
    #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__))
    IRE_RESET_SMALL_CONS_HALANT_FLAG();
    IRE_RESET_SMALL_CONSONANT_FLAG();
    #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */ 

    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_CLUSTER);
    
    is_RA_hal_reordering = MMI_FALSE;
    #if defined(__MMI_LANG_KANNADA__)
    is_first_entry_kannada_ra_con = MMI_FALSE;
    #endif /* defined(__MMI_LANG_KANNADA__) */ 
    /* Is this a valid unicode value */
    if (!IRE_LANG_ID_CONVERT_U8_U16(start_char))
    {
        return 0;
    }
    /* Is this character belongs to Indic language range or not */
    if (!IRE_INDIC_LANGUAGE_RANGE(IRE_LANG_ID_CONVERT_U8_U16(start_char)))
    {
        MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_CLUSTER_NON_INDIC_CHARACTER);
	    IRE_LANG_ID_FILL_CLUSTER();
        start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16) NULL;
        g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
        return nFill;
    }
    /* store the language Id of input character  */
    IRE_GET_CHARACTER_LANG_ID_FROM_PREV_CHAR((U16) IRE_LANG_ID_CONVERT_U8_U16(start_char), langIdIndex);
    IRE_SET_PREV_CHAR_LANG_ID(langIdIndex);
    /* get Indic language array index   */
    IRE_SET_PREV_CHAR_INFO_TABLE_FROM_CHAR_INFO_TABLE(langIdIndex);
    /* store start range of Indic language table */
    startRange = indic_lang_table_info.start_range;
    /* store end range of Indic language ligature   */
    endRange = indic_lang_table_info.end_range;
    /* get the pointer to the begining of the array of structures  */
    char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;

    main_glyph_table_base_address_p = indic_lang_table_info.indic_main_info_table_p;

    /*
     * As char might belong to indic range, but our product doesn't support that language
     * In that case, just fill the char as such, it could be in the form of square box.
     * so this check is required
     */
    if (NULL == char_status_flag_p)
    {
        IRE_LANG_ID_FILL_CLUSTER();
        start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16) NULL;
        g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
        return nFill;
    }
    /* Identify the charcater based on character flag and update the g flag */
    IRE_IDENTIFY_CHARACTER(
        IRE_LANG_ID_CONVERT_U8_U16(start_char),
        char_status_flag_p,
        startRange,
        mCharacterStatusFlag);

    nFill = 0;

    switch (mCharacterStatusFlag)
    {
        /* Consonants */
        case NORMAL_CON:    /* 0x00000001 */
        case RA_CON:        /* 0x00000002 */
        case SMALL_CON:     /* 0x00000003 */
        case KANNADA_RA_CON:/* 0x00000004 */
        {
            MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_CLUSTER_INDIC_CHARACTER_TYPE_CONSONANT);
	        if ((!(mCharacterStatusFlag ^ RA_CON)))
            {
                U16 next_char = IRE_LANG_ID_CONVERT_NEXT_VAL_U8_U16(start_char);
                if ((next_char >= startRange) && (next_char <= endRange))
                {
                    /* Identify the charcater based on character flag and update the g flag */
                    IRE_IDENTIFY_CHARACTER(
                        next_char,
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlagNext);
                    if(mCharacterStatusFlagNext^NORMALSIGN)
                    {
                        is_first_entry_ra_cons = MMI_TRUE;
                    }
                }
            }
            #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__))
            else if ((!(mCharacterStatusFlag ^ SMALL_CON)))
            {
                is_first_entry_small_cons = MMI_TRUE;
				#if !defined (__MMI_LANG_MYANMAR__)
                IRE_SET_SMALL_CONSONANT_FLAG();
#endif
            }
            #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */ 
            #if defined (__MMI_LANG_KANNADA__)
            else if ((!(mCharacterStatusFlag ^ KANNADA_RA_CON)))
            {
                is_first_entry_ra_cons = MMI_TRUE;
                is_first_entry_kannada_ra_con = MMI_TRUE;
                IRE_SET_SMALL_CONSONANT_FLAG();
            }
            #endif /* defined (__MMI_LANG_KANNADA__) */ 
            IRE_LANG_ID_FILL_CLUSTER();
            IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
            MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));

            /* Is the next character belongs to the language of current character   */
            IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                start_cluster,
                IRE_LANG_ID_CONVERT_U8_U16(start_char),
                startRange,
                endRange,
                nFill);
            /* Identify next character and update character flag  */
            IRE_IDENTIFY_CHARACTER(
                IRE_LANG_ID_CONVERT_U8_U16(start_char),
                char_status_flag_p,
                startRange,
                mCharacterStatusFlag);

			#if defined __MMI_MULTITAP_BANGLA_SPEC__
				
				if (!(mCharacterStatusFlag ^ LIGATURE_USED_AS_CONSONANT))
				{

					IRE_LANG_ID_FILL_CLUSTER();
                    IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));
                    /* Is the next character belongs to the language of current character   */
                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                        start_cluster,
                        IRE_LANG_ID_CONVERT_U8_U16(start_char),
                        startRange,
                        endRange,
                        nFill);
                    /* Identify next character and update character flag  */
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);
					if(!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL))  /* Con + Post base Matra */
               		{
                    	IRE_LANG_ID_FILL_CLUSTER();
                    	IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    	MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));
                    	/* Is the next character belongs to the language of current character   */
                    	IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                        	start_cluster,
                        	IRE_LANG_ID_CONVERT_U8_U16(start_char),
                        	startRange,
                        	endRange,
                        	nFill);
                    	/* Identify next character and update character flag  */
                    	IRE_IDENTIFY_CHARACTER(
                        	(IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        	char_status_flag_p,
                        	startRange,
                        	mCharacterStatusFlag);

                    	if (!(mCharacterStatusFlag ^ NORMALSIGN))
                    	{
                        	IRE_LANG_ID_FILL_CLUSTER();
                        	start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16)NULL;	                
							g_indic_rule_engine_cntx.g_cluster_start_p += (2 * nFill);	
							return nFill;		
						}
                	}

				}
						
			#endif

            if (!(mCharacterStatusFlag ^ HALANT))   /* Con + Halant */
            {
                MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_CLUSTER_INDIC_CHARACTER_TYPE_HALANT_SIGN);
		        
		        /*#if defined(__MMI_LANG_KHMER__)*/
		        /* Khmer language specific hack to avoid entry of lots of rules */
		        /*if (start_cluster[0] == KHMER_C_NYO)
		        {
		        		start_cluster[0] = KHMER_LIGRATURE_178;
		        }
		        #endif*/
		        
		        IRE_LANG_ID_FILL_CLUSTER();
                IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                curr_char = ((*start_char) | (*(start_char + 1) << 8));
                /* For Handling Zero Width Joiner */
                if(curr_char == ZWJ)
				{
				    start_char = start_char + 2;
                    nFill++;
                }
                /* For Handling Zero Width Non Joiner */
                if(curr_char == ZWNJ)
                {
                    nFill++;
                    g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                    start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16)NULL;
                    return nFill;
                }
		        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);

CONTINUE_CLUSTERING:
                MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));
                /* Is the next character belongs to the language of current character   */
                IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                    start_cluster,
                    IRE_LANG_ID_CONVERT_U8_U16(start_char),
                    startRange,
                    endRange,
                    nFill);

                /* This statement will be valid only when goto has been used.
                 * Now, if RA + HAl + Con sequence has been reordered, then 
                 * undo the reodreding as the reordering will be happen again
                 * after the following code is executed. Thus to avoid 
                 * reordering happening two times, we undo the reordering done
                 * at the first go
                 */
                if(is_RA_hal_reordering)
                {
                    IRE_UNDO_RA_HAL_REORDERING(g_indic_rule_engine_cntx.g_display_buffer_len - 2, j, temp, i);
                }
                /* Identify next character and update character flag  */
                IRE_IDENTIFY_CHARACTER(
                    (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                    char_status_flag_p,
                    startRange,
                    mCharacterStatusFlag);
                /* Handling of RA + Hal + RA for Kannada language */
                #if (defined (__MMI_LANG_KANNADA__))
                {
                    if( (is_first_entry_kannada_ra_con == MMI_TRUE) && (!(mCharacterStatusFlag ^ KANNADA_RA_CON)) )
                    {
                        is_first_entry_ra_cons = MMI_FALSE;
                        is_first_entry_kannada_ra_con = MMI_FALSE;
                        is_first_entry_small_cons = MMI_TRUE;
                        IRE_SET_SMALL_CONSONANT_FLAG();
                    }
                }
                #endif /* (defined (__MMI_LANG_KANNADA__)) */
                /* loop for Con + hal + Con + hal + con .....sequence */
                while ((mCharacterStatusFlag & ALL_CONSONANT_TYPE))
                {
                    #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__))
                    if (is_first_entry_small_cons == MMI_FALSE)
                    {
                        IRE_LANG_ID_FILL_CLUSTER();
                    }
                    else
                    {
                        temp_small_cons_halant_flag = 1;
                    #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */ 
                        IRE_LANG_ID_FILL_CLUSTER();
                    #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__))
                    }
                    #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */
                    if (start_char == g_indic_rule_engine_cntx.g_cluster_end_p)
                    {
                        break;
                    }
                    /* Is the next character belongs to the language of current character   */
                    if ((!IRE_CHECK_CHARACTER_LANG_RANGE(IRE_LANG_ID_CONVERT_U8_U16(start_char), startRange, endRange)) || 
                        (g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX))
                    {
                        break;
                    }
                    
                    /* Identify next character and update character flag  */
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);

                    /* Identify previous character and update character flag  */
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_PREVIOUS_VAL_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlagPrev);

                    if (!(mCharacterStatusFlag ^ HALANT))
                    {
                        IRE_LANG_ID_FILL_CLUSTER();
                        if (start_char == g_indic_rule_engine_cntx.g_cluster_end_p)
                        {
                            break;
                        }
                        curr_char = ((*start_char) | (*(start_char + 1) << 8));
				        /* For Handling Zero Width Joiner */
                        if(curr_char == ZWJ)
				        {
				            start_char = start_char + 2;
                            nFill++;
                            if (start_char == g_indic_rule_engine_cntx.g_cluster_end_p)
                            {
                                break;
                            }
                        }
                        /* For Handling Zero Width Non Joiner */
                        if(curr_char == ZWNJ)
                        {
                            nFill++;
                            g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                            start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16)NULL;
                            #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__))
                            if (is_first_entry_small_cons == MMI_TRUE)
                            {
                                IRE_REORDER_SMALL_CON_POST_BASE_MATRA(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp, i);
                            }
                            #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */
                            return nFill;
                        }
			            
                        
                        /******************************************************************************************** 
                         * If no. of characters in the cluster buffer exceeds 4 and there is one chillu characters 
                         * amoungst them, then the clustering stop stop there 
                         ********************************************************************************************/
                        if ((!IRE_CHECK_CHARACTER_LANG_RANGE(IRE_LANG_ID_CONVERT_U8_U16(start_char), startRange, endRange)) || 
                            (g_indic_rule_engine_cntx.g_display_buffer_len >= (G_MAX - 2)) ||
                            ((g_indic_rule_engine_cntx.g_display_buffer_len >= 4) && (ire_is_chillu_character)))
                        {
                            break;
                        }
                        /* Identify next character and update character flag  */
                        IRE_IDENTIFY_CHARACTER(
                            (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                            char_status_flag_p,
                            startRange,
                            mCharacterStatusFlag);
                    }
                    /************************************************************************* 
                     * Clustering should continue if the next character is Chillu character 
                     * or the next character is normal consonant and the previous character 
                     * is either Halant or Chillu character
                     *************************************************************************/
                    else if ((!(mCharacterStatusFlag ^ CHILLU_CHARACTER)) ||
                             ( (!(mCharacterStatusFlag ^ NORMAL_CON)) && 
                               ( (!(mCharacterStatusFlagPrev ^ HALANT)) || 
                                 (!(mCharacterStatusFlagPrev ^ CHILLU_CHARACTER)) )))
                    {
                        if(!(mCharacterStatusFlag ^ CHILLU_CHARACTER))
                        {
                            ire_is_chillu_character = MMI_TRUE;
                        }
                        
                        /*********************************************************** 
                         * If no. of characters in the cluster buffer exceeds 4 and 
                         * there is one chillu characters amoungst them, then the 
                         * clustering stop stop there 
                         ***********************************************************/
                        if ((!IRE_CHECK_CHARACTER_LANG_RANGE(IRE_LANG_ID_CONVERT_U8_U16(start_char), startRange, endRange)) || 
                            ((g_indic_rule_engine_cntx.g_display_buffer_len >= 4) && (ire_is_chillu_character)))
                        {
                            break;
                        }

                        continue;
                    }
                    /* If the next character is neither Chillu character nor Halant, then we should
                     * break out of the while loop */  
                    else
                    {
                        break;
                    }
                     #if defined (__MMI_LANG_HINDI__)&& defined(__MMI_VECTOR_FONT_SUPPORT__)
                    
                   IRE_GET_CHARACTER_LANG_ID_FROM_PREV_CHAR((*cluster), langIdIndex);    
                    if(langIdIndex==IRE_LANGUAGE_ID_HINDI)
                    {
                    /* Identify prev. character and update character flag  */
                IRE_IDENTIFY_CHARACTER(
                    (IRE_LANG_ID_CONVERT_PREVIOUS_VAL_U8_U16(start_char)),
                    char_status_flag_p,
                    startRange,
                    mCharacterStatusFlagPrev);

                    if(!(mCharacterStatusFlag ^ RA_CON)&&!(mCharacterStatusFlagPrev^HALANT))
                    {
                         IRE_LANG_ID_FILL_CLUSTER();
                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                               /* Identify next character and update character flag  */
                        IRE_IDENTIFY_CHARACTER(
                            (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                            char_status_flag_p,
                            startRange,
                            mCharacterStatusFlag);
                                   if(!(mCharacterStatusFlag ^ RA_CON))
                                   {
                                   IRE_LANG_ID_FILL_CLUSTER();
                                   IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                                    
                                   }
                                     IRE_IDENTIFY_CHARACTER(
                            (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                            char_status_flag_p,
                            startRange,
                            mCharacterStatusFlag);
                                   if(!(mCharacterStatusFlag ^ HALANT))
                                   {
                                   IRE_LANG_ID_FILL_CLUSTER();
                                   IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                                    
                                   }
                    break;
                    }
                    }
                #endif
                } /* end of while loop for Con + Hal + Con + Hal +.... */
                #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__))
                if (temp_small_cons_halant_flag)
                {
                    if (IRE_IS_CHAR_TYPE_HALANT(cluster[g_indic_rule_engine_cntx.g_display_buffer_len - 1]))
                    {
                        /* reorder put halant after first Cons treat halant as post base matra */
                        IRE_REORDER_SMALL_CON_POST_BASE_MATRA(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp, i);
						#if !defined (__MMI_LANG_MYANMAR__)
                        IRE_SET_SMALL_CONS_HALANT_FLAG();
#endif
                    }
                    else
                    {
                        IRE_DOUBLE_SET_SMALL_CONS_HALANT_FLAG();
                    }
                    IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                }
                if ((is_first_entry_small_cons == MMI_TRUE) && (g_indic_rule_engine_cntx.g_display_buffer_len & 1))
                {
                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                        start_cluster,
                        IRE_LANG_ID_CONVERT_U8_U16(start_char),
                        startRange,
                        endRange,
                        nFill);
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);

                    if (!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL))
                    {
                        U16 character_position = 0;
                        U16 curr_char = 0;
                        
                        curr_char = ((*start_char) | (*(start_char + 1) << 8));
                        IRE_LANG_ID_FILL_CLUSTER();
                        
                        /* If the current character is below and postbase, then do not
                         * do the reordering
                         */
                        character_position = ire_identify_char_position(curr_char);
                        if (character_position != IRE_BELOW_AND_POST_BASE_POSITION)
                        {
                            IRE_REORDER_SMALL_CON_POST_BASE_MATRA(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp, i);
                            #if !defined (__MMI_LANG_MYANMAR__)
                            IRE_SET_SMALL_CONS_HALANT_FLAG();
#endif
                        
                        }
                        else
                        {
                            #if !defined (__MMI_LANG_MYANMAR__)
                            IRE_DOUBLE_SET_SMALL_CONS_HALANT_FLAG();
#endif
                        }
                    }

                    IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));
                    /* Is the next character belongs to the language of current character   */
                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                        start_cluster, 
                        IRE_LANG_ID_CONVERT_U8_U16(start_char), 
                        startRange, 
                        endRange, 
                        nFill);    /* Identify next character and update character flag  */
                    /* Identify next character and update character flag  */
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);

                    if (!(mCharacterStatusFlag ^ NORMALSIGN))
                    {
                        curr_char = ((*start_char) | (*(start_char + 1) << 8));
                        IRE_LANG_ID_FILL_CLUSTER();
                        
                        /* if sequence con + hal + con + ....+ nukta is encountered,
                         * then nukta should be shown below the first consonant
                         */
                        
                        /* if character belong to Kannada language */
                        if((g_indic_rule_engine_cntx.ire_prev_char_lang_id.lang_id_index == IRE_LANGUAGE_ID_KANNADA)/*curr_char == KANNADA_S_NUKTA*/)
                        {
                            IRE_IDENTIFY_CHAR_TYPE_FOR_VALIDITY(curr_char, char_status_flag_p, startRange, mCharacterStatusFlag);
                            /* If sign is of type 3 ie NUKTA sign */
                            if(!(mCharacterStatusFlag ^ CHARACTER_TYPE_3))
                            {
                                IRE_REORDER_SMALL_CON_POST_BASE_MATRA(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp, i);
                            }
                        }
                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                        
                        #if defined(__MMI_LANG_MYANMAR__)
                        {
                        	U32 language_specific_attribute = 0;
                        	
                        	/* Is the next character belongs to the language of current character   */
		                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
		                        start_cluster, 
		                        IRE_LANG_ID_CONVERT_U8_U16(start_char), 
		                        startRange, 
		                        endRange, 
		                        nFill);    /* Identify next character and update character flag  */
		                    /* Identify next character and update character flag  */
		                    IRE_IDENTIFY_CHARACTER(
		                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
		                        char_status_flag_p,
		                        startRange,
		                        mCharacterStatusFlag);
                        	
	                        IRE_LANGUAGE_SPECIFIC_ATTRIBUTE(
								(IRE_LANG_ID_CONVERT_U8_U16(start_char)),
							    char_status_flag_p,
							    startRange,
							    language_specific_attribute);
							    
							if (language_specific_attribute & IRE_SUPPORT_SIGN_SIGN_ENTRY)
							{
								if (!(mCharacterStatusFlag ^ NORMALSIGN))
								{
									IRE_LANG_ID_FILL_CLUSTER();
									IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
								}
							}
							    
						}
						#endif /* defined(__MMI_LANG_MYANMAR__) */
                    }

                }
                else if ((is_first_entry_small_cons == MMI_TRUE) && (g_indic_rule_engine_cntx.g_display_buffer_len % 2))
                {
                    IRE_REORDER_SMALL_CON_POST_BASE_MATRA(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp, i);
                    IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));
                }
                #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */ 
                if (is_first_entry_ra_cons == MMI_TRUE)
                {
                    #if defined (__MMI_LANG_KANNADA__)
                    if(is_first_entry_kannada_ra_con)
                    {
                        if (IRE_IS_CHAR_TYPE_HALANT(cluster[g_indic_rule_engine_cntx.g_display_buffer_len - 1]))
                        {
                            IRE_SET_SMALL_CONS_HALANT_FLAG();
                        }
                        else
                        {
                            IRE_DOUBLE_SET_SMALL_CONS_HALANT_FLAG();
                        }                    
                    }
                    #endif /* defined (__MMI_LANG_KANNADA__) */

                    if (g_indic_rule_engine_cntx.g_display_buffer_len % 2)
                    {
                        /* If it is the end of cluster, then reorder RA + Hal + Con sequence and
                         * end the cluster */
                        if (start_char == g_indic_rule_engine_cntx.g_cluster_end_p)
                        {
                            if(ire_continue_clustering)
                            {
                                IRE_REORDER_RA_HALANT_CONS_HALANT_SEQUENCE(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp, i);
                            }
                            else
                            {
                                IRE_REORDER_RA_HALANT_CONS_SEQUENCE(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp, i);
                            }
                            is_RA_hal_reordering = MMI_TRUE;
                            IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                        }
                        ire_reordering_done = MMI_FALSE;
                        IRE_IDENTIFY_CHARACTER(
                            (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                            char_status_flag_p,
                            startRange,
                            mCharacterStatusFlag);
						                    #if defined __MMI_MULTITAP_BANGLA_SPEC__
				
				if (!(mCharacterStatusFlag ^ LIGATURE_USED_AS_CONSONANT))
				{
					if (is_first_entry_ra_cons == MMI_TRUE)
					{
						IRE_REORDER_RA_HALANT_CONS_SEQUENCE(
                                    g_indic_rule_engine_cntx.g_display_buffer_len,
                                    j,
                                    temp,
                                    i);
						is_RA_hal_reordering = MMI_TRUE;
					}
					IRE_LANG_ID_FILL_CLUSTER();
                    IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));
                    /* Is the next character belongs to the language of current character   */
                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                        start_cluster,
                        IRE_LANG_ID_CONVERT_U8_U16(start_char),
                        startRange,
                        endRange,
                        nFill);
                    /* Identify next character and update character flag  */
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);
					if(!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL))  /* Con + Post base Matra */
               		{
                    	IRE_LANG_ID_FILL_CLUSTER();
                    	IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    	MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));
                    	/* Is the next character belongs to the language of current character   */
                    	IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                        	start_cluster,
                        	IRE_LANG_ID_CONVERT_U8_U16(start_char),
                        	startRange,
                        	endRange,
                        	nFill);
                    	/* Identify next character and update character flag  */
                    	IRE_IDENTIFY_CHARACTER(
                        	(IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        	char_status_flag_p,
                        	startRange,
                        	mCharacterStatusFlag);

                    	if (!(mCharacterStatusFlag ^ NORMALSIGN))
                    	{
                        	IRE_LANG_ID_FILL_CLUSTER();
                        	start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16)NULL;	                
							g_indic_rule_engine_cntx.g_cluster_start_p += (2 * nFill);	
							return nFill;		
						}
						start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16)NULL;	                
						g_indic_rule_engine_cntx.g_cluster_start_p += (2 * nFill);	
						return nFill;	
                	}
					else if (!(mCharacterStatusFlag ^ NORMALSIGN))
                    	{
                        	IRE_LANG_ID_FILL_CLUSTER();
                        	start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16)NULL;	                
							g_indic_rule_engine_cntx.g_cluster_start_p += (2 * nFill);	
							return nFill;	
                	}
					else if (!(mCharacterStatusFlag ^ PRE_BASE_DEPVOWEL))        /* Con + Halant + Ra + Prebase matra */
					{
						IRE_LANG_ID_FILL_CLUSTER();

						IRE_REORDER_PREBASE_MATRA(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp);

						IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
						MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));
						IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                        	start_cluster,
                        	IRE_LANG_ID_CONVERT_U8_U16(start_char),
                        	startRange,
                        	endRange,
                        	nFill);
                    	/* Identify next character and update character flag  */
                    	IRE_IDENTIFY_CHARACTER(
                        	(IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        	char_status_flag_p,
                        	startRange,
                        	mCharacterStatusFlag);

					if (!(mCharacterStatusFlag ^ NORMALSIGN))
                    	{
                        	IRE_LANG_ID_FILL_CLUSTER();
                        	start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16)NULL;	                
							g_indic_rule_engine_cntx.g_cluster_start_p += (2 * nFill);	
							return nFill;	
					}
						start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16)NULL;	                
						g_indic_rule_engine_cntx.g_cluster_start_p += (2 * nFill);	
						return nFill;	
					}
					else
					{
						start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16)NULL;	                
						g_indic_rule_engine_cntx.g_cluster_start_p += (2 * nFill);	
						return nFill;	
					}
				}
						
			#endif
					

                        if (!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL))
                        {
                            #if defined (__MMI_LANG_KANNADA__)
                            if(is_first_entry_kannada_ra_con)
                            {
                                IRE_REORDER_RA_HALANT_CONS_SEQUENCE(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp, i);
                                is_RA_hal_reordering = MMI_TRUE;
                                IRE_LANG_ID_FILL_CLUSTER();
                                IRE_REORDER_SMALL_CON_POST_BASE_MATRA(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp, i);
                                ire_reordering_done = MMI_TRUE;
                                if(IRE_GET_SMALL_CONS_HALANT_FLAG() == 2)
                                {
                                    IRE_SET_SMALL_CONS_HALANT_FLAG();
                                }
                            }
                            else
                            #endif /* defined (__MMI_LANG_KANNADA__) */
                            {
                                IRE_LANG_ID_FILL_CLUSTER();
                            }
                        }
                        else if (!(mCharacterStatusFlag ^ CENTER_BASE_DEPVOWEL))        /* Con + Halant + Ra + halant + Postbase matra/sign */
                        {
                            /* centre base handling */
                            ch_index = ((IRE_LANG_ID_CONVERT_U8_U16(start_char)) - startRange) - 1;     /* find the index of character in main table */
                            ind_table = main_glyph_table_base_address_p[ch_index];      /* gets the individual charactr's table in main table */
                            char_table_p = ind_table.glyph_info_p;      /* holds the add. of individual character */
                            IRE_REORDER_RA_HALANT_CONS_SEQUENCE(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp, i);
                            is_RA_hal_reordering = MMI_TRUE;
                            IRE_REORDER_CENTER_BASE_DEP_VOWEL(start_cluster, g_indic_rule_engine_cntx.g_display_buffer_len, char_table_p, temp, size, j);
                            g_indic_rule_engine_cntx.g_display_buffer_len += 2;
                            IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                            /* Identify next character and update character flag  */

                            IRE_CHECK_NEXT_CHARACTER_LANG_RANGE_VARIANT(
                                start_cluster,
                                IRE_LANG_ID_CONVERT_U8_U16(start_char),
                                startRange,
                                endRange,
                                nFill);
                            IRE_IDENTIFY_CHARACTER(
                                (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                                char_status_flag_p,
                                startRange,
                                mCharacterStatusFlag);
                            if (!(mCharacterStatusFlag ^ NORMALSIGN))
                            {
                                start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = IRE_LANG_ID_CONVERT_U8_U16(start_char);
                                ++nFill;
                                start_char += 2;
                                g_indic_rule_engine_cntx.g_display_buffer_len++;
                                start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16) NULL;
                                g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                                return nFill;
                            }
                            else
                            {
                                start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16) NULL;
                                g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                                return nFill;
                            }
                        }
                        
                        if(!(ire_reordering_done))
                        {
                            IRE_REORDER_RA_HALANT_CONS_SEQUENCE(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp, i);
                            is_RA_hal_reordering = MMI_TRUE;
                        }
                        
                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                        MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));
                        /* Is the next character belongs to the language of current character   */
                        IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                            start_cluster, 
                            IRE_LANG_ID_CONVERT_U8_U16(start_char), 
                            startRange, 
                            endRange, 
                            nFill);        /* Identify next character and update character flag  */
                        /* Identify next character and update character flag  */
                        IRE_IDENTIFY_CHARACTER(
                            (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                            char_status_flag_p,
                            startRange,
                            mCharacterStatusFlag);

                        if (!(mCharacterStatusFlag ^ NORMALSIGN))
                        {
                            curr_char = ((*start_char) | (*(start_char + 1) << 8));
                            IRE_LANG_ID_FILL_CLUSTER();
                            IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                            IRE_IDENTIFY_CHARACTER(
                            (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                            char_status_flag_p,
                            startRange,
                            mCharacterStatusFlag);
                            if (!(mCharacterStatusFlag ^ HALANT))
                            {
                                IRE_LANG_ID_FILL_CLUSTER();
                                IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                                if(g_indic_rule_engine_cntx.g_display_buffer_len < G_MAX - 2)
                                {
                                    ire_continue_clustering = MMI_TRUE;
                                    goto CONTINUE_CLUSTERING;
                                }
                            }
                            
                            /* if sequence con + hal + con + ....+ nukta is encountered,
                             * then nukta should be shown below the first consonant
                             */
                            
                            /* if character belong to Kannada language */
                            if((g_indic_rule_engine_cntx.ire_prev_char_lang_id.lang_id_index == IRE_LANGUAGE_ID_KANNADA)/*curr_char == KANNADA_S_NUKTA*/)
                            {
                                IRE_IDENTIFY_CHAR_TYPE_FOR_VALIDITY(curr_char, char_status_flag_p, startRange, mCharacterStatusFlag);
                                /* If sign is of type 3 ie NUKTA sign */
                                if(!(mCharacterStatusFlag ^ CHARACTER_TYPE_3))
                                {
                                    IRE_REORDER_SMALL_CON_POST_BASE_MATRA(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp, i);
                                }
                            }
                            IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                            #if defined(__MMI_LANG_MYANMAR__)
                            {
	                        	U32 language_specific_attribute = 0;
	                        	
	                        	/* Is the next character belongs to the language of current character   */
			                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
			                        start_cluster, 
			                        IRE_LANG_ID_CONVERT_U8_U16(start_char), 
			                        startRange, 
			                        endRange, 
			                        nFill);    /* Identify next character and update character flag  */
			                    /* Identify next character and update character flag  */
			                    IRE_IDENTIFY_CHARACTER(
			                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
			                        char_status_flag_p,
			                        startRange,
			                        mCharacterStatusFlag);
	                        	
		                        IRE_LANGUAGE_SPECIFIC_ATTRIBUTE(
									(IRE_LANG_ID_CONVERT_U8_U16(start_char)),
								    char_status_flag_p,
								    startRange,
								    language_specific_attribute);
								    
								if (language_specific_attribute & IRE_SUPPORT_SIGN_SIGN_ENTRY)
								{
									if (!(mCharacterStatusFlag ^ NORMALSIGN))
									{
										IRE_LANG_ID_FILL_CLUSTER();
										IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
									}
								}
								    
							}
							#endif /* defined(__MMI_LANG_MYANMAR__) */
                        }
                    }
                    #if defined(__MMI_LANG_KANNADA__)
                    else if(is_first_entry_kannada_ra_con)
                    {
                        IRE_REORDER_RA_HALANT_CONS_SEQUENCE(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp, i);
                        if(g_indic_rule_engine_cntx.g_display_buffer_len > 4)
                        {
                            IRE_REORDER_CONS_HALANT_KANNADA_RA_HALANT_SEQUENCE(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp);
                        }
                        is_RA_hal_reordering = MMI_TRUE;
                    }
                    #endif /* defined(__MMI_LANG_KANNADA__) */ 
                    else
                    {
                        if(ire_continue_clustering)
                        {
                            IRE_REORDER_RA_HALANT_CONS_SEQUENCE(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp, i);
                        }
                        else
                        {
                            IRE_REORDER_RA_HALANT_CONS_HALANT_SEQUENCE(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp, i);
                        }
                        is_RA_hal_reordering = MMI_TRUE;
                    }

                    IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));
                }   /* End of if statement if(is_first_entry_ra_cons == MMI_TRUE) */

                IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                /* Is the next character belongs to the language of current character   */
                IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                    start_cluster,
                    IRE_LANG_ID_CONVERT_U8_U16(start_char),
                    startRange,
                    endRange,
                    nFill);
                /* Identify next character and update character flag  */
                IRE_IDENTIFY_CHARACTER(
                    (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                    char_status_flag_p,
                    startRange,
                    mCharacterStatusFlag);

                /* Identify prev. character and update character flag  */
                IRE_IDENTIFY_CHARACTER(
                    (IRE_LANG_ID_CONVERT_PREVIOUS_VAL_U8_U16(start_char)),
                    char_status_flag_p,
                    startRange,
                    mCharacterStatusFlagPrev);

                /*******************************************************************
                 * The following logic checks has been added to stop the clustering
                 * after halant, when we receive the following combinations 
                 * ....+ Halant + DV +... or ....+ Halant + Sign +...
                 ******************************************************************/
                
                if (!(mCharacterStatusFlagPrev ^ HALANT))
                {
                    start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16) NULL;
                    g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                    return nFill;
                }
				#if defined __MMI_MULTITAP_BANGLA_SPEC__
				
				if (!(mCharacterStatusFlag ^ LIGATURE_USED_AS_CONSONANT))
				{

					IRE_LANG_ID_FILL_CLUSTER();
                    IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));
                    /* Is the next character belongs to the language of current character   */
                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                        start_cluster,
                        IRE_LANG_ID_CONVERT_U8_U16(start_char),
                        startRange,
                        endRange,
                        nFill);
                    /* Identify next character and update character flag  */
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);
					if(!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL))  /* Con + Post base Matra */
               		{
                    	IRE_LANG_ID_FILL_CLUSTER();
                    	IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    	MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));
                    	/* Is the next character belongs to the language of current character   */
                    	IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                        	start_cluster,
                        	IRE_LANG_ID_CONVERT_U8_U16(start_char),
                        	startRange,
                        	endRange,
                        	nFill);
                    	/* Identify next character and update character flag  */
                    	IRE_IDENTIFY_CHARACTER(
                        	(IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        	char_status_flag_p,
                        	startRange,
                        	mCharacterStatusFlag);

                    	if (!(mCharacterStatusFlag ^ NORMALSIGN))
                    	{
                        	IRE_LANG_ID_FILL_CLUSTER();
                        	start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16)NULL;	                
							g_indic_rule_engine_cntx.g_cluster_start_p += (2 * nFill);	
							return nFill;		
						}
                	}

				}
						
			#endif
                if (!(mCharacterStatusFlag ^ PRE_BASE_DEPVOWEL))        /* Con + Halant + Ra + Prebase matra */
                {
                    IRE_LANG_ID_FILL_CLUSTER();

                    IRE_REORDER_PREBASE_MATRA(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp);

                    IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));
                    
                    #if defined (__MMI_LANG_MYANMAR__) || defined (__MMI_LANG_KHMER__)
                    VOWEL_VOWEL_SUPPORT_3:
                    {
	                    U32 entry_of_vowel_allowed_flag = 0;
	                    
	                    /* Is the next character belongs to the language of current character   */
	                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
	                        start_cluster,
	                        IRE_LANG_ID_CONVERT_U8_U16(start_char),
	                        startRange,
	                        endRange,
	                        nFill);
	                    /* Identify next character and update character flag  */
	                    IRE_IDENTIFY_CHARACTER(
	                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
	                        char_status_flag_p,
	                        startRange,
	                        mCharacterStatusFlag);
	                        
	                    IRE_CHECK_VOWEL_ENTRY_ATTRIBUTE(
	                    	(IRE_LANG_ID_CONVERT_U8_U16(start_char)),
	                        char_status_flag_p,
	                        startRange,
	                        entry_of_vowel_allowed_flag);
	                        
	                    if (entry_of_vowel_allowed_flag)
	                    {
		                    if (!(mCharacterStatusFlag ^ PRE_BASE_DEPVOWEL))
		                    {
		                        IRE_LANG_ID_FILL_CLUSTER();
		                        IRE_REORDER_PREBASE_MATRA(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp);
		                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
		                    }
		                    else if (!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL))
		                    {
		                    	IRE_LANG_ID_FILL_CLUSTER();
		                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
		                    }
		                }
	                }
					#endif /* defined (__MMI_LANG_MYANMAR__) */
                    
                    /* Is the next character belongs to the language of current character   */
                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                        start_cluster,
                        IRE_LANG_ID_CONVERT_U8_U16(start_char),
                        startRange,
                        endRange,
                        nFill);
                    /* Identify next character and update character flag  */
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);

                    #if defined (__MMI_LANG_MYANMAR__) || defined (__MMI_LANG_KHMER__)
					IRE_CHECK_VOWEL_ENTRY_ATTRIBUTE(
						(IRE_LANG_ID_CONVERT_U8_U16(start_char)),
						char_status_flag_p,
						startRange,
						entry_of_vowel_allowed_flag);
						
					if (entry_of_vowel_allowed_flag)
					{
					    if (!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL))
					    {
						    if (g_indic_rule_engine_cntx.g_display_buffer_len == (G_MAX- 1) )
                            {
                                start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16) NULL;
                                g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                                return nFill;
                            }
                            goto VOWEL_VOWEL_SUPPORT_3;
					    }
					    }
					    #endif /* defined (__MMI_LANG_MYANMAR__) || defined (__MMI_LANG_KHMER__) */

                    if (!(mCharacterStatusFlag ^ NORMALSIGN))   /* Con + Halant + Ra + halant + Prebase matra + Sign */
                    {
                        IRE_LANG_ID_FILL_CLUSTER();
                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                        #if defined(__MMI_LANG_MYANMAR__)
                        {
                        	U32 language_specific_attribute = 0;
                        	
                        	/* Is the next character belongs to the language of current character   */
		                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
		                        start_cluster, 
		                        IRE_LANG_ID_CONVERT_U8_U16(start_char), 
		                        startRange, 
		                        endRange, 
		                        nFill);    /* Identify next character and update character flag  */
		                    /* Identify next character and update character flag  */
		                    IRE_IDENTIFY_CHARACTER(
		                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
		                        char_status_flag_p,
		                        startRange,
		                        mCharacterStatusFlag);
                        	
	                        IRE_LANGUAGE_SPECIFIC_ATTRIBUTE(
								(IRE_LANG_ID_CONVERT_U8_U16(start_char)),
							    char_status_flag_p,
							    startRange,
							    language_specific_attribute);
							    
							if (language_specific_attribute & IRE_SUPPORT_SIGN_SIGN_ENTRY)
							{
								if (!(mCharacterStatusFlag ^ NORMALSIGN))
								{
									IRE_LANG_ID_FILL_CLUSTER();
									IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
								}
							}
							    
						}
						#endif /* defined(__MMI_LANG_MYANMAR__) */
                    }
                }
                else if ((!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL)) || (!(mCharacterStatusFlag ^ NORMALSIGN)))      /* Con + Halant + Ra +  Postbase matra/sign */
                {
                    IRE_LANG_ID_FILL_CLUSTER();
                    IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));
                    
                    #if defined (__MMI_LANG_MYANMAR__) || defined (__MMI_LANG_KHMER__)
					if (!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL))
					{
	                    U32 entry_of_vowel_allowed_flag = 0;
	                    
	                    /* Is the next character belongs to the language of current character   */
	                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
	                        start_cluster,
	                        IRE_LANG_ID_CONVERT_U8_U16(start_char),
	                        startRange,
	                        endRange,
	                        nFill);
	                    /* Identify next character and update character flag  */
	                    IRE_IDENTIFY_CHARACTER(
	                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
	                        char_status_flag_p,
	                        startRange,
	                        mCharacterStatusFlag);
	                        
	                    IRE_CHECK_VOWEL_ENTRY_ATTRIBUTE(
	                    	(IRE_LANG_ID_CONVERT_U8_U16(start_char)),
	                        char_status_flag_p,
	                        startRange,
	                        entry_of_vowel_allowed_flag);
	                        
	                    if (entry_of_vowel_allowed_flag)
	                    {
		                    if (!(mCharacterStatusFlag ^ PRE_BASE_DEPVOWEL))
		                    {
		                        IRE_LANG_ID_FILL_CLUSTER();
		                        IRE_REORDER_PREBASE_MATRA(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp);
		                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
		                    }
		                    else if (!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL))
		                    {
		                    	IRE_LANG_ID_FILL_CLUSTER();
		                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
		                    }
		                }
	                }
					#endif /* defined (__MMI_LANG_MYANMAR__) */
                    
                    /* Is the next character belongs to the language of current character   */
                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                        start_cluster,
                        IRE_LANG_ID_CONVERT_U8_U16(start_char),
                        startRange,
                        endRange,
                        nFill);
                    /* Identify next character and update character flag  */
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);
                    if (!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL))
                    {
                        IRE_LANG_ID_FILL_CLUSTER();
                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    }
                    else if (!(mCharacterStatusFlag ^ PRE_BASE_DEPVOWEL))
                    {
                        IRE_LANG_ID_FILL_CLUSTER();

                        IRE_REORDER_PREBASE_MATRA(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp);

                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                        
                        #if defined (__MMI_LANG_MYANMAR__) || defined (__MMI_LANG_KHMER__)
	                    /* Is the next character belongs to the language of current character   */
	                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
	                        start_cluster,
	                        IRE_LANG_ID_CONVERT_U8_U16(start_char),
	                        startRange,
	                        endRange,
	                        nFill);
	                    /* Identify next character and update character flag  */
	                    IRE_IDENTIFY_CHARACTER(
	                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
	                        char_status_flag_p,
	                        startRange,
	                        mCharacterStatusFlag);
	
	                    if (!(mCharacterStatusFlag ^ PRE_BASE_DEPVOWEL))
	                    {
	                        IRE_LANG_ID_FILL_CLUSTER();
	                        IRE_REORDER_PREBASE_MATRA(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp);
	                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
	                    }
	                    else if (!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL))
	                    {
	                    	IRE_LANG_ID_FILL_CLUSTER();
	                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
	                    }
						#endif /* defined (__MMI_LANG_MYANMAR__) */
                    }
                    else if (!(mCharacterStatusFlag ^ CENTER_BASE_DEPVOWEL))    /* Con + Halant + Ra + halant + Postbase matra/sign */
                    {
                        /* centre base handling */
                        ch_index = ((IRE_LANG_ID_CONVERT_U8_U16(start_char)) - startRange) - 1; /* find the index of character in main table */
                        ind_table = main_glyph_table_base_address_p[ch_index];  /* gets the individual charactr's table in main table */
                        char_table_p = ind_table.glyph_info_p;  /* holds the add. of individual character */

                        IRE_REORDER_CENTER_BASE_DEP_VOWEL(start_cluster, g_indic_rule_engine_cntx.g_display_buffer_len, char_table_p, temp, size, j);

                        g_indic_rule_engine_cntx.g_display_buffer_len += 2;

                        start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16) NULL;
                        g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                        return nFill;
                    }
                    else if(!(mCharacterStatusFlag ^ HALANT))
                    {
                        IRE_LANG_ID_FILL_CLUSTER();
                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                        if(g_indic_rule_engine_cntx.g_display_buffer_len < G_MAX - 2)
                        {
                            ire_continue_clustering = MMI_TRUE;
                            goto CONTINUE_CLUSTERING;
                        }
                    }
                    /* Identify next character and update character flag  */
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);
                    if (!((mCharacterStatusFlag) ^ NORMALSIGN))
                    {
                        IRE_LANG_ID_FILL_CLUSTER();
                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                        
                        #if defined(__MMI_LANG_MYANMAR__)
                        {
                        	U32 language_specific_attribute = 0;
                        	
                        	/* Is the next character belongs to the language of current character   */
		                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
		                        start_cluster, 
		                        IRE_LANG_ID_CONVERT_U8_U16(start_char), 
		                        startRange, 
		                        endRange, 
		                        nFill);    /* Identify next character and update character flag  */
		                    /* Identify next character and update character flag  */
		                    IRE_IDENTIFY_CHARACTER(
		                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
		                        char_status_flag_p,
		                        startRange,
		                        mCharacterStatusFlag);
                        	
	                        IRE_LANGUAGE_SPECIFIC_ATTRIBUTE(
								(IRE_LANG_ID_CONVERT_U8_U16(start_char)),
							    char_status_flag_p,
							    startRange,
							    language_specific_attribute);
							    
							if (language_specific_attribute & IRE_SUPPORT_SIGN_SIGN_ENTRY)
							{
								if (!(mCharacterStatusFlag ^ NORMALSIGN))
								{
									IRE_LANG_ID_FILL_CLUSTER();
									IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
								}
							}
							    
						}
						#endif /* defined(__MMI_LANG_MYANMAR__) */
                    }
                }
                else if (!(mCharacterStatusFlag ^ CENTER_BASE_DEPVOWEL))        /* Con + Halant + Ra + Centrebase matra/sign */
                {
                    /* centre base handling */
                    ch_index = ((IRE_LANG_ID_CONVERT_U8_U16(start_char)) - startRange) - 1;     /* find the index of character in main table */
                    ind_table = main_glyph_table_base_address_p[ch_index];      /* gets the individual charactr's table in main table */
                    char_table_p = ind_table.glyph_info_p;  /* holds the add. of individual character */

                    IRE_REORDER_CENTER_BASE_DEP_VOWEL(start_cluster, g_indic_rule_engine_cntx.g_display_buffer_len, char_table_p, temp, size, j);
                    g_indic_rule_engine_cntx.g_display_buffer_len += 2;
                    IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    
                    /* Identify next character and update character flag  */
                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE_VARIANT(
                        start_cluster,
                        IRE_LANG_ID_CONVERT_U8_U16(start_char),
                        startRange,
                        endRange,
                        nFill);
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);
                    if (!(mCharacterStatusFlag ^ NORMALSIGN))
                    {
                        start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = IRE_LANG_ID_CONVERT_U8_U16(start_char);
                        ++nFill;
                        start_char += 2;
                        g_indic_rule_engine_cntx.g_display_buffer_len++;
                        start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16) NULL;
                        g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                        return nFill;
                    }
                    else
                    {
                        start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16) NULL;
                        g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                        return nFill;
                    }
                }
            }   /*  End of Halant  */
            #if defined (__MMI_LANG_TAMIL__)
            else if (!(mCharacterStatusFlag ^ TAMIL_HALANT_SIGN))
            {
                MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_CLUSTER_INDIC_CHARACTER_TYPE_TAMIL_HALANT_SIGN);
		            IRE_LANG_ID_FILL_CLUSTER();
                    IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    curr_char = ((*start_char) | (*(start_char + 1) << 8));
                    /* For Handling Zero Width Joiner */
                    if(curr_char == ZWJ)
				    {
                        start_char = start_char + 2;
                        nFill++;
                    }
                    /* For Handling Zero Width Non Joiner */
                    if(curr_char == ZWNJ)
                    {
                        nFill++;
                        g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                        start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16)NULL;
                        return nFill;
                    }
                IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);

                MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));
                /* Is the next character belongs to the language of current character   */
                IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                    start_cluster,
                    IRE_LANG_ID_CONVERT_U8_U16(start_char),
                    startRange,
                    endRange,
                    nFill);
                /* Identify next character and update character flag  */
                IRE_IDENTIFY_CHARACTER(
                    (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                    char_status_flag_p,
                    startRange,
                    mCharacterStatusFlag);

                if (!(mCharacterStatusFlag ^ NORMAL_CON))
                {
                    /* get the char pointer of first entries of cluster buffer */
                    ch_index = ((start_cluster[0]) - startRange) - 1;   /* find the index of character in main table */
                    ind_table = main_glyph_table_base_address_p[ch_index];      /* gets the individual charactr's table in main table */
                    char_table_p = ind_table.glyph_info_p;  /* holds the add. of individual character */
                    nsize = ind_table.nsize;                /* get no. of entries inside array */

                    /* get the max. length of input buffer */
                    if (ind_table.max_input_glyph_size > 2)
                    {
                        IRE_LANG_ID_FILL_CLUSTER();

                        MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));
                        /* Identify next character and update character flag  */
                        IRE_IDENTIFY_CHARACTER(
                            (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                            char_status_flag_p,
                            startRange,
                            mCharacterStatusFlag);

                        if ((!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL)) || (!(mCharacterStatusFlag ^ CENTER_BASE_DEPVOWEL))) /* con + halant + con + Prebase matra */
                        {
                            IRE_LANG_ID_FILL_CLUSTER();

                        }

                        do
                        {
                            nsize--;
                            /* check the entries inside the rule table */
			                if((char_table_p[nsize].input_buffer_len == 1) || 
                               ((mmi_ire_reverse_memcmp(char_table_p[nsize].input_buffer_glyph + 1, cluster + 1, 
                                                        (U8)(char_table_p[nsize].input_buffer_len - 1)) == MMI_TRUE) &&
                                (char_table_p[nsize].input_buffer_len != 1)))
                            /* The pointers have been incrememnted to point to the second entry because we dont want the 
                                first entries in the buffer to be compared */ 
                            {
                                isValidRuleEntryExist = MMI_TRUE;
                                break;
                            }

                        } while (char_table_p[nsize].input_buffer_len > 2);

                        /* if the entry does not exists and total number of entries are three */
                        if ((g_indic_rule_engine_cntx.g_display_buffer_len == 3) && (MMI_FALSE == isValidRuleEntryExist))
                        {
                            start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len - 1] = (U16) NULL;
                            nFill--;
                            start_char -= 2;
                            g_indic_rule_engine_cntx.g_display_buffer_len--;
                            g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                            return nFill;
                        }
                        /* if the entry does not exists and total number of entries are four */
                        else if ((g_indic_rule_engine_cntx.g_display_buffer_len == 4) && (MMI_FALSE == isValidRuleEntryExist))
                        {
                            start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len - 1] = (U16) NULL;
                            start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len - 2] = (U16) NULL;
                            nFill -= 2;
                            start_char -= 4;
                            g_indic_rule_engine_cntx.g_display_buffer_len -= 2;
                            g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                            return nFill;
                        }

                        if (!(mCharacterStatusFlag ^ PRE_BASE_DEPVOWEL))
                        {
                            IRE_LANG_ID_FILL_CLUSTER();
                            IRE_REORDER_PREBASE_MATRA(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp);
                            IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                        }
                        else if (!(mCharacterStatusFlag ^ TAMIL_HALANT_SIGN))
                        {
                            IRE_LANG_ID_FILL_CLUSTER();
                            IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                            curr_char = ((*start_char) | (*(start_char + 1) << 8));
                            /* For Handling Zero Width Joiner */
                            if(curr_char == ZWJ)
				            {
                                start_char = start_char + 2;
                                nFill++;
                            }
                            /* For Handling Zero Width Non Joiner */
                            if(curr_char == ZWNJ)
                            {
                                nFill++;
                                g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                                start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16)NULL;
                                return nFill;
                            }
                            IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                        }
                    }   /* End of if(length of input buffer) */
                }       /* End of if(Normal consonant) */
            }           /* End of tamil halant sign */
            #endif /* defined (__MMI_LANG_TAMIL__) */
            else
            {
                /* Con + Pre base Matra */
                if (!(mCharacterStatusFlag ^ PRE_BASE_DEPVOWEL))
                {
                    char_temp =  ((*start_char) | (*(start_char + 1) << 8));
                    IRE_LANG_ID_FILL_CLUSTER();
                    IRE_REORDER_PREBASE_MATRA(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp);

                    IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));
#if defined (__MMI_LANG_TAMIL__) || defined (__MMI_LANG_BENGALI__) 
					if((IRE_LANG_ID_CONVERT_U8_U16(start_char)) == 0x0bbe || (char_temp == 0x09c7 || char_temp == 0x09c8))
					{
						IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
	                        start_cluster,
	                        IRE_LANG_ID_CONVERT_U8_U16(start_char),
	                        startRange,
	                        endRange,
	                        nFill);
	                    /* Identify next character and update character flag  */
	                    IRE_IDENTIFY_CHARACTER(
	                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
	                        char_status_flag_p,
	                        startRange,
	                        mCharacterStatusFlag);
						if (!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL))
						{
							IRE_LANG_ID_FILL_CLUSTER();
					        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
					        MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));
						}
					}	                    
#endif
                    #if defined (__MMI_LANG_MYANMAR__) || defined (__MMI_LANG_KHMER__)
VOWEL_VOWEL_SUPPORT_2:
                    {
	                    U32 entry_of_vowel_allowed_flag = 0;
	                    
	                    /* Is the next character belongs to the language of current character   */
	                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
	                        start_cluster,
	                        IRE_LANG_ID_CONVERT_U8_U16(start_char),
	                        startRange,
	                        endRange,
	                        nFill);
	                    /* Identify next character and update character flag  */
	                    IRE_IDENTIFY_CHARACTER(
	                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
	                        char_status_flag_p,
	                        startRange,
	                        mCharacterStatusFlag);
	                        
	                    IRE_CHECK_VOWEL_ENTRY_ATTRIBUTE(
	                    	(IRE_LANG_ID_CONVERT_U8_U16(start_char)),
	                        char_status_flag_p,
	                        startRange,
	                        entry_of_vowel_allowed_flag);
	                        
	                    if (entry_of_vowel_allowed_flag)
	                    {
		                    if (!(mCharacterStatusFlag ^ PRE_BASE_DEPVOWEL))
		                    {
		                        IRE_LANG_ID_FILL_CLUSTER();
		                        IRE_REORDER_PREBASE_MATRA(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp);
		                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
		                    }
		                    else if (!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL))
		                    {
		                    	IRE_LANG_ID_FILL_CLUSTER();
		                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
		                    }
		                }
	                }
					#endif /* defined (__MMI_LANG_MYANMAR__) */
                    
                    
                    /* Is the next character belongs to the language of current character   */
                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                        start_cluster,
                        IRE_LANG_ID_CONVERT_U8_U16(start_char),
                        startRange,
                        endRange,
                        nFill);
                    /* Identify next character and update character flag  */
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);

					#if defined (__MMI_LANG_MYANMAR__) || defined (__MMI_LANG_KHMER__)
					IRE_CHECK_VOWEL_ENTRY_ATTRIBUTE(
						(IRE_LANG_ID_CONVERT_U8_U16(start_char)),
						char_status_flag_p,
						startRange,
						entry_of_vowel_allowed_flag);
						
					if (entry_of_vowel_allowed_flag)
					{
					if (!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL))
					{
						if (g_indic_rule_engine_cntx.g_display_buffer_len == (G_MAX- 1) )
                        {
                            start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16) NULL;
                            g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                            return nFill;
                        }
                        goto VOWEL_VOWEL_SUPPORT_2;
					}
					}
					#endif /* defined (__MMI_LANG_MYANMAR__) || defined (__MMI_LANG_KHMER__) */

                    if (!(mCharacterStatusFlag ^ NORMALSIGN))
                    {
                        IRE_LANG_ID_FILL_CLUSTER();
                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                        #if defined(__MMI_LANG_MYANMAR__)
                        {
                        	U32 language_specific_attribute = 0;
                        	
                        	/* Is the next character belongs to the language of current character   */
		                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
		                        start_cluster, 
		                        IRE_LANG_ID_CONVERT_U8_U16(start_char), 
		                        startRange, 
		                        endRange, 
		                        nFill);    /* Identify next character and update character flag  */
		                    /* Identify next character and update character flag  */
		                    IRE_IDENTIFY_CHARACTER(
		                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
		                        char_status_flag_p,
		                        startRange,
		                        mCharacterStatusFlag);
                        	
	                        IRE_LANGUAGE_SPECIFIC_ATTRIBUTE(
								(IRE_LANG_ID_CONVERT_U8_U16(start_char)),
							    char_status_flag_p,
							    startRange,
							    language_specific_attribute);
							    
							if (language_specific_attribute & IRE_SUPPORT_SIGN_SIGN_ENTRY)
							{
								if (!(mCharacterStatusFlag ^ NORMALSIGN))
								{
									IRE_LANG_ID_FILL_CLUSTER();
									IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
								}
							}
							    
						}
						#endif /* defined(__MMI_LANG_MYANMAR__) */
                    }
                }
                else if (!(mCharacterStatusFlag ^ CENTER_BASE_DEPVOWEL))        /* Con + Halant + Ra + halant + Postbase matra/sign */
                {
                    /* centre base handling */
                    ch_index = ((IRE_LANG_ID_CONVERT_U8_U16(start_char)) - startRange) - 1;     /* find the index of character in main table */
                    ind_table = main_glyph_table_base_address_p[ch_index];      /* gets the individual charactr's table in main table */
                    char_table_p = ind_table.glyph_info_p;  /* holds the add. of individual character */

                    IRE_REORDER_CENTER_BASE_DEP_VOWEL(start_cluster, g_indic_rule_engine_cntx.g_display_buffer_len, char_table_p, temp, size, j);
                    g_indic_rule_engine_cntx.g_display_buffer_len += 2;
                    IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE_VARIANT(
                        start_cluster,
                        IRE_LANG_ID_CONVERT_U8_U16(start_char),
                        startRange,
                        endRange,
                        nFill);
                    /* Identify next character and update character flag  */
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);
                    if (!(mCharacterStatusFlag ^ NORMALSIGN))
                    {
                        start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = IRE_LANG_ID_CONVERT_U8_U16(start_char);
                        ++nFill;
                        start_char += 2;
                        g_indic_rule_engine_cntx.g_display_buffer_len++;
                        start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16) NULL;
                        g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                        return nFill;
                    }
                    else
                    {
                        start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16) NULL;
                        g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                        return nFill;
                    }
                }
                else if (!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL))  /* Con + Post base Matra */
                {
                    IRE_LANG_ID_FILL_CLUSTER();
                    IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));
                    
                    #if defined (__MMI_LANG_MYANMAR__) || defined (__MMI_LANG_KHMER__)
VOWEL_VOWEL_SUPPORT_1:
                    {
	                    
	                    /* Is the next character belongs to the language of current character   */
	                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
	                        start_cluster,
	                        IRE_LANG_ID_CONVERT_U8_U16(start_char),
	                        startRange,
	                        endRange,
	                        nFill);
	                    /* Identify next character and update character flag  */
	                    IRE_IDENTIFY_CHARACTER(
	                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
	                        char_status_flag_p,
	                        startRange,
	                        mCharacterStatusFlag);
	                        
	                    IRE_CHECK_VOWEL_ENTRY_ATTRIBUTE(
	                    	(IRE_LANG_ID_CONVERT_U8_U16(start_char)),
	                        char_status_flag_p,
	                        startRange,
	                        entry_of_vowel_allowed_flag);
	                        
	                    if (entry_of_vowel_allowed_flag)
	                    {
		                    if (!(mCharacterStatusFlag ^ PRE_BASE_DEPVOWEL))
		                    {
		                        IRE_LANG_ID_FILL_CLUSTER();
		                        IRE_REORDER_PREBASE_MATRA(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp);
		                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
		                    }
		                    else if (!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL))
		                    {
		                    	IRE_LANG_ID_FILL_CLUSTER();
		                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
		                    }
		                }
	                }
					#endif /* defined (__MMI_LANG_MYANMAR__) */
                    
                    /* Is the next character belongs to the language of current character   */
                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                        start_cluster,
                        IRE_LANG_ID_CONVERT_U8_U16(start_char),
                        startRange,
                        endRange,
                        nFill);
                    /* Identify next character and update character flag  */
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);

					#if defined (__MMI_LANG_MYANMAR__) || defined (__MMI_LANG_KHMER__)
					IRE_CHECK_VOWEL_ENTRY_ATTRIBUTE(
						(IRE_LANG_ID_CONVERT_U8_U16(start_char)),
						char_status_flag_p,
						startRange,
						entry_of_vowel_allowed_flag);
						
					if (entry_of_vowel_allowed_flag)
					{
					if (!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL))
					{
						if (g_indic_rule_engine_cntx.g_display_buffer_len == (G_MAX- 1) )
                        {
                            start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16) NULL;
                            g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                            return nFill;
                        }
                        goto VOWEL_VOWEL_SUPPORT_1;
					}
					}
					#endif /* defined (__MMI_LANG_MYANMAR__) || defined (__MMI_LANG_KHMER__) */

                    if (!(mCharacterStatusFlag ^ NORMALSIGN))
                    {
                        IRE_LANG_ID_FILL_CLUSTER();
                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                        #if defined(__MMI_LANG_MYANMAR__)
                        {
                        	U32 language_specific_attribute = 0;
                        	
                        	/* Is the next character belongs to the language of current character   */
		                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
		                        start_cluster, 
		                        IRE_LANG_ID_CONVERT_U8_U16(start_char), 
		                        startRange, 
		                        endRange, 
		                        nFill);    /* Identify next character and update character flag  */
		                    /* Identify next character and update character flag  */
		                    IRE_IDENTIFY_CHARACTER(
		                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
		                        char_status_flag_p,
		                        startRange,
		                        mCharacterStatusFlag);
                        	
	                        IRE_LANGUAGE_SPECIFIC_ATTRIBUTE(
								(IRE_LANG_ID_CONVERT_U8_U16(start_char)),
							    char_status_flag_p,
							    startRange,
							    language_specific_attribute);
							    
							if (language_specific_attribute & IRE_SUPPORT_SIGN_SIGN_ENTRY)
							{
								if (!(mCharacterStatusFlag ^ NORMALSIGN))
								{
									IRE_LANG_ID_FILL_CLUSTER();
									IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
								}
							}
							    
						}
						#endif /* defined(__MMI_LANG_MYANMAR__) */
                    }
                }
                else if (!(mCharacterStatusFlag ^ NORMALSIGN))  /* Con + Sign */
                {
                    IRE_LANG_ID_FILL_CLUSTER();
                    IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));
                    /* Is the next character belongs to the language of current character   */
                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                        start_cluster,
                        IRE_LANG_ID_CONVERT_U8_U16(start_char),
                        startRange,
                        endRange,
                        nFill);
                    /* Identify next character and update character flag  */
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);

                    if (!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL))
                    {
                        IRE_LANG_ID_FILL_CLUSTER();
                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    }
                    else if (!(mCharacterStatusFlag ^ PRE_BASE_DEPVOWEL))
                    {
                        IRE_LANG_ID_FILL_CLUSTER();
                        IRE_REORDER_PREBASE_MATRA(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp);
                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    }
                    else if (!(mCharacterStatusFlag ^ CENTER_BASE_DEPVOWEL))    /* Con + Halant + Ra + halant + Postbase matra/sign */
                    {
                        /* centre base handling */
                        ch_index = ((IRE_LANG_ID_CONVERT_U8_U16(start_char)) - startRange) - 1; /* find the index of character in main table */
                        ind_table = main_glyph_table_base_address_p[ch_index];  /* gets the individual charactr's table in main table */
                        char_table_p = ind_table.glyph_info_p;  /* holds the add. of individual character */

                        IRE_REORDER_CENTER_BASE_DEP_VOWEL(start_cluster, g_indic_rule_engine_cntx.g_display_buffer_len, char_table_p, temp, size, j);
                        g_indic_rule_engine_cntx.g_display_buffer_len += 2;
                        /*start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16) NULL;
                        g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                        return nFill;*/
                    }
                    else if(!(mCharacterStatusFlag ^ HALANT))
                    {
                        IRE_LANG_ID_FILL_CLUSTER();
                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                        if(g_indic_rule_engine_cntx.g_display_buffer_len < G_MAX - 2)
                        {
                            ire_continue_clustering = MMI_TRUE;
                            goto CONTINUE_CLUSTERING;
                        }
                    }
                    /* Is the next character belongs to the language of current character   */
                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                        start_cluster,
                        IRE_LANG_ID_CONVERT_U8_U16(start_char),
                        startRange,
                        endRange,
                        nFill);
                    /* Identify next character and update character flag  */
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);

                    if (!((mCharacterStatusFlag) ^ NORMALSIGN))
                    {
                        IRE_LANG_ID_FILL_CLUSTER();
                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    }
                }
            }   /* End of Con + Pre/Post base Matra */
            start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16) NULL;
            g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
            return nFill;
        }       /* End of case statement Normal Consonant */

        case INDEPVOWEL:    /* Independent Vowel *//* 0x00000040: */
        {
            #if defined(__MMI_MULTITAP_BANGLA_SPEC__)
            start_character_temp = ((start_char)[0]|((start_char)[1]<<8));
#endif
            IRE_LANG_ID_FILL_CLUSTER();
            IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
            MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));
			
            IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                start_cluster,
                IRE_LANG_ID_CONVERT_U8_U16(start_char),
                startRange,
                endRange,
                nFill);
            /* Identify next character and update character flag  */
            IRE_IDENTIFY_CHARACTER(
                (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                char_status_flag_p,
                startRange,
                mCharacterStatusFlag);
           	#if defined __MMI_MULTITAP_BANGLA_SPEC__
			
				if(!(mCharacterStatusFlag ^ HALANT))
            {
                IRE_LANG_ID_FILL_CLUSTER();
                IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
				MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));
                    /* Is the next character belongs to the language of current character   */
                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                        start_cluster,
                        IRE_LANG_ID_CONVERT_U8_U16(start_char),
                        startRange,
                        endRange,
                        nFill);
                    /* Identify next character and update character flag  */
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);
					start_character_temp = ((start_char)[0]|((start_char)[1]<<8));
				if(!(mCharacterStatusFlag ^ NORMAL_CON))
				{
					if(start_character_temp == 0x09af)
					{
				IRE_LANG_ID_FILL_CLUSTER();
                    IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));
                    /* Is the next character belongs to the language of current character   */
                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                        start_cluster,
                        IRE_LANG_ID_CONVERT_U8_U16(start_char),
                        startRange,
                        endRange,
                        nFill);
                    /* Identify next character and update character flag  */
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);
					if(!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL))  /* Con + Post base Matra */
               		{
            IRE_LANG_ID_FILL_CLUSTER();
            IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
            MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));
                    	/* Is the next character belongs to the language of current character   */
            IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                start_cluster,
                IRE_LANG_ID_CONVERT_U8_U16(start_char),
                startRange,
                endRange,
                nFill);
            /* Identify next character and update character flag  */
            IRE_IDENTIFY_CHARACTER(
                (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                char_status_flag_p,
                startRange,
                mCharacterStatusFlag);

                    	if (!(mCharacterStatusFlag ^ NORMALSIGN))
                    	{
                        	IRE_LANG_ID_FILL_CLUSTER();
                        	start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16)NULL;	                
							g_indic_rule_engine_cntx.g_cluster_start_p += (2 * nFill);	
							return nFill;		
						}
					}
					else if(!(mCharacterStatusFlag ^ PRE_BASE_DEPVOWEL))
						{
							 IRE_LANG_ID_FILL_CLUSTER();
                        IRE_REORDER_PREBASE_MATRA(g_indic_rule_engine_cntx.g_display_buffer_len, j, temp);
                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
						MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));
                    	/* Is the next character belongs to the language of current character   */
                    	IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                        	start_cluster,
                        	IRE_LANG_ID_CONVERT_U8_U16(start_char),
                        	startRange,
                        	endRange,
                        	nFill);
                    	/* Identify next character and update character flag  */
                    	IRE_IDENTIFY_CHARACTER(
                        	(IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        	char_status_flag_p,
                        	startRange,
                        	mCharacterStatusFlag);
						
                    	if (!(mCharacterStatusFlag ^ NORMALSIGN))
                    	{
                        	IRE_LANG_ID_FILL_CLUSTER();
                        	start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16)NULL;	                
							g_indic_rule_engine_cntx.g_cluster_start_p += (2 * nFill);	
							return nFill;		
						}
					}

					else if(!(mCharacterStatusFlag ^ CENTER_BASE_DEPVOWEL))
						{
							 ch_index = ((IRE_LANG_ID_CONVERT_U8_U16(start_char)) - startRange) - 1; /* find the index of character in main table */
                        ind_table = main_glyph_table_base_address_p[ch_index];  /* gets the individual charactr's table in main table */
                        char_table_p = ind_table.glyph_info_p;  /* holds the add. of individual character */
							 IRE_REORDER_CENTER_BASE_DEP_VOWEL(start_cluster, g_indic_rule_engine_cntx.g_display_buffer_len, char_table_p, temp, size, j);
                      g_indic_rule_engine_cntx.g_display_buffer_len += 2;
							  IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
						MMI_ASSERT(!(g_indic_rule_engine_cntx.g_display_buffer_len > G_MAX));
                    	/* Is the next character belongs to the language of current character   */
                    	IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                        	start_cluster,
                        	IRE_LANG_ID_CONVERT_U8_U16(start_char),
                        	startRange,
                        	endRange,
                        	nFill);
                    	/* Identify next character and update character flag  */
                    	IRE_IDENTIFY_CHARACTER(
                        	(IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        	char_status_flag_p,
                        	startRange,
                        	mCharacterStatusFlag);
						
                    	if (!(mCharacterStatusFlag ^ NORMALSIGN))
                    	{
                        	IRE_LANG_ID_FILL_CLUSTER();
                        	start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16)NULL;	                
							g_indic_rule_engine_cntx.g_cluster_start_p += (2 * nFill);	
							return nFill;		
						}
					}

				}
			}
			}
			
#endif
            if (!(mCharacterStatusFlag ^ NORMALSIGN))
            {
                IRE_LANG_ID_FILL_CLUSTER();
                IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
            }
            start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16) NULL;
            g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
            return nFill;
        }
        
        /* Halant */
        /****************************************************************
         * This piece of code has been added as we allow the combination
         * Halant or Halant + ZWJ or Halant + ZWNJ to be dispayed 
         * independentely in the candidate window
         ****************************************************************/
        case HALANT:
        {
            MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_CLUSTER_INDIC_CHARACTER_TYPE_HALANT_SIGN);
            IRE_LANG_ID_FILL_CLUSTER();
            IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
            curr_char = ((*start_char) | (*(start_char + 1) << 8));
            /* For Handling Zero Width Joiner */
            if(curr_char == ZWJ)
			{
				start_char = start_char + 2;
                nFill++;
            }
            /* For Handling Zero Width Non Joiner */
            if(curr_char == ZWNJ)
            {
                nFill++;
                g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16)NULL;
                return nFill;
            }
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)
if(curr_char == 0x09af || curr_char == 0x09b0 )
IRE_LANG_ID_FILL_CLUSTER();
            IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
#endif
			
			
		    IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
            start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16) NULL;
            g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
            return nFill;
        }
        
        /* Chillu Characters */

        /* *******************************************************************
         * Chilu Characters are present in Malayalam language and they
         * are equivalent to Con + Halant, ie why, the combination
         * Chilu_character + con + .. should form a cluster.
         * In our design we dont allow Chillu Characters +  Chillu Characters
         * to take part in cluster formation
         *********************************************************************/ 
        case CHILLU_CHARACTER :
        {
            ire_is_chillu_character = MMI_TRUE;
            IRE_LANG_ID_FILL_CLUSTER();
            IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
            goto CONTINUE_CLUSTERING;
        }

        /* Dependent Vowel Range */
        /**************************************************************
         * If the Dependent Vowels or Normal signs comes independently,
         * or for any default case, they should be displayed as it is
         **************************************************************/
        case PRE_BASE_DEPVOWEL:     /* 0x00000008 */
        case POST_BASE_DEPVOWEL:    /* 0x00000010 */
        case BELOW_BASE_DEPVOWEL:   /* 0x00000018 */
        case ABOVE_BASE_DEPVOWEL:   /* 0x00000020 */
        case CENTER_BASE_DEPVOWEL:  /* 0x00000028 */
        /* Normal Sign */
        case NORMALSIGN:            /* 0x00000100 */
        /* Default */
        default:
        {
            IRE_LANG_ID_FILL_CLUSTER();
            start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16) NULL;
            g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
            return nFill;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  ire_get_multitap_text_x
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptext_x                 [IN]
 *  current_character       [IN]        
 *  Char_Range              [IN]        
 *  check_char              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ire_get_multitap_text_x(S32 *ptext_x, U16 current_character, S32 Char_Range, S32 check_char)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S32 prev_char_mtext_x = 0;
    static S32 prev_char_mdwidth = 0;
    S32 character_height = 0;
    S32 text_x = 0;
    S32 mtext_gap = 5;
    U32 mCharacterStatusFlag = 0;
    U32 langIdIndex = 0;    /* to store the value of language Id of input character */
    U16 startRange = 0;     /* to store the starting range of language of input character */

    ire_indic_languages_table_struct indic_lang_table_info;
    const ire_character_info_table_struct *char_status_flag_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTI IRE TRACE UPDATION START */
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_MULTITAP_TEXT_X);
    /* MTI IRE TRACE UPDATION END */

    text_x = *ptext_x;
    if (!(check_char))
    {
        switch (Char_Range)
        {
            case 1:
                *ptext_x = 59;
                break;
            case 2:
                *ptext_x = 54;
                break;
            case 3:
                *ptext_x = 49;
                break;
            case 4:
                *ptext_x = 44;
                break;
            case 5:
                *ptext_x = 39;
                break;
            case 6:
                *ptext_x = 35;
                break;
            case 7:
                *ptext_x = 30;
                break;
            case 8:
                *ptext_x = 25;
                break;
            case 9:
                *ptext_x = 20;
                break;
            case 10:
                *ptext_x = 15;
                break;
            case 11:
                *ptext_x = 10;
                break;
            case 12:
            case 13:
            case 14:
                *ptext_x = 7;
                break;
            default:
                *ptext_x = 3;
                break;
        }
        prev_char_mtext_x = *ptext_x;
        Get_CharWidthHeight(current_character, &prev_char_mdwidth, &character_height);
        return;
    }
    /* store the language Id of input character  */
    langIdIndex = ire_get_character_lang_id(current_character);
    /* get Indic language array index   */
    indic_lang_table_info = indic_lang_char_info_table[langIdIndex];
    /* store start range of Indic language table */
    startRange = indic_lang_table_info.start_range;
    /* get the pointer to the begining of the array of structures  */
    char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;

    /*
     * As char might belong to indic range, but our product doesn't support that language
     * In that case, just fill the char as such, it could be in the form of square box.
     * so this check is required
     */
    if (NULL != char_status_flag_p)
    {

        IRE_IDENTIFY_CHARACTER(current_character, char_status_flag_p, startRange, mCharacterStatusFlag);

        if ((!((mCharacterStatusFlag) ^ PRE_BASE_DEPVOWEL)) ||
            (!((mCharacterStatusFlag) ^ CENTER_BASE_DEPVOWEL)) ||
            (!((mCharacterStatusFlag) ^ NORMALSIGN)) || (!((mCharacterStatusFlag) ^ POST_BASE_DEPVOWEL)))
        {
            text_x = prev_char_mdwidth + prev_char_mtext_x + mtext_gap;
        }
        else
        {
            text_x = prev_char_mdwidth + prev_char_mtext_x;
        }
    }
    else
    {
        text_x = prev_char_mdwidth + prev_char_mtext_x;
    }

    Get_CharWidthHeight(current_character, &prev_char_mdwidth, &character_height);
    prev_char_mtext_x = text_x;

    /* TBD under consideration...need to be fixed */
    if (current_character == 0x940) /* DV_II */
    {
        *ptext_x = text_x + mtext_gap;
    }
    else
    {
        *ptext_x = text_x;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ire_get_text_x
 * DESCRIPTION				
 *  This method will calculate the width, dwidth based upon the type of input 
 *  characters
 * PARAMETERS
 *  ptext_x                 [IN]
 *  current_character       [IN]        
 *  text_y                  [IN]        
 *  d_width                 [IN]        
 *  width                   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ire_get_text_x(S32 *ptext_x, U16 current_character, S32 text_y, U16 d_width, U16 width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 langIdIndex = 0;
    U16 startRange = 0, previous_startRange = 0, previous_endRange = 0, endRange = 0;
    U8 is_Indic = 1;

    const ire_character_info_table_struct *char_status_flag_p = NULL, *prev_char_status_flag_p = NULL;
    const ire_character_info_table_struct *pLangFlag;
    ire_indic_languages_table_struct indic_lang_table_info, prev_indic_lang_table_info;

    U32 *mchar_status_flag_p = NULL;
    U32 mCharStatusFlag = 0;
    #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__))
    U32 mCharStatusFlagPrev = 0;
    U32 character_position=0;
    #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_TEXT_X);
	IRE_GET_CHARACTER_LANG_ID_FROM_PREV_CHAR(current_character, langIdIndex);
    IRE_SET_PREV_CHAR_LANG_ID(langIdIndex);
    /* if not ligature range */
    if (!(current_character & 0xE000))
    {
        /* get Indic language array index   */
        IRE_SET_PREV_CHAR_INFO_TABLE_FROM_CHAR_INFO_TABLE(langIdIndex);
    }
    else
    {
        /* get Indic language ligature array index   */
        IRE_SET_PREV_CHAR_INFO_TABLE_FROM_LIGATURE_INFO_TABLE(langIdIndex);
    }
	/* If above API returns NULL, the character is not Indic Range */
    if ( current_character >= 0x0E01 && current_character <= 0x0E7F)
    {
        g_indic_rule_engine_cntx.g_prev_char_text_x = *ptext_x;
        g_indic_rule_engine_cntx.g_prev_char_dwidth = width;
        g_indic_rule_engine_cntx.g_prev_char_width = width;
        #if defined (__MMI_LANG_THAI__)
        if (IsThaiAboveLineChar(current_character))
        {
            g_indic_rule_engine_cntx.g_prev_char_dwidth = 0;
            g_indic_rule_engine_cntx.g_prev_char_width = 0;
        }
        #endif /* defined (__MMI_LANG_THAI__) */
        g_indic_rule_engine_cntx.g_prev_character = current_character;
        return;
    }

    if (!langIdIndex)
    {
        d_width = width;
        g_indic_rule_engine_cntx.g_prev_char_dwidth = g_indic_rule_engine_cntx.g_prev_char_width;
        is_Indic = 0;
        if (r2lMMIFlag)
        {
            return;
        }
    }
    if (!(g_indic_rule_engine_cntx.g_new_line))
    {
        g_indic_rule_engine_cntx.g_new_line = 1;
        if (langIdIndex)
        {
            *ptext_x = *ptext_x - g_indic_rule_engine_cntx.g_indic_padding;
        }
        g_indic_rule_engine_cntx.g_prev_char_text_x = *ptext_x;
        g_indic_rule_engine_cntx.g_prev_char_dwidth = d_width;
        g_indic_rule_engine_cntx.g_prev_char_width = width;
        g_indic_rule_engine_cntx.g_prev_character = current_character;
    #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__))
        g_indic_rule_engine_cntx.sign_cons_or_below_base = 0;
        IRE_SET_RENDERING_CORRECTION(current_character);
    #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__)) */ 
        return;
    }
    if (langIdIndex)
    {
		/* start range of Indic language */
        startRange = indic_lang_table_info.start_range;
        /* end range of Indic language */
        endRange = indic_lang_table_info.end_range;
        /* get the pointer to the begining of the array of structures  */
        char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;
		
		IRE_MODIFY_LIGATURE_RELATED_INFORMATION(
        	current_character,
        	char_status_flag_p,
        	startRange,
        	endRange,
        	langIdIndex);
		
        /* get pointer of the character flag which is nothing but pointer to a structure */
        pLangFlag = (char_status_flag_p + ((current_character - startRange) - 1));
        /* store the charater flag information by ORing and shifting bits */
        mchar_status_flag_p = (U32*) pLangFlag;

        mCharStatusFlag = *mchar_status_flag_p;
    }

    /*
     * As char might belong to indic range, but our product doesn't support that language
     * In that case, just fill the char as such, it could be in the form of square box.
     * so this check is required
     */
    #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__)) 
    character_position = ire_identify_char_position(current_character);
    #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__)) */

    if (char_status_flag_p != NULL)
    {
        #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__))
        
        if(langIdIndex == g_indic_rule_engine_cntx.ire_prev_char_lang_id.lang_id_index)
        {
            /* if not ligature range */
            if (!(g_indic_rule_engine_cntx.g_prev_character & 0xE000))
            {
                prev_indic_lang_table_info = indic_lang_char_info_table[langIdIndex];
            }
            else
            {
                prev_indic_lang_table_info = indic_lang_ligature_info_table[langIdIndex];
            }

	        previous_startRange = prev_indic_lang_table_info.start_range;
            previous_endRange = prev_indic_lang_table_info.end_range;
            prev_char_status_flag_p = prev_indic_lang_table_info.indic_char_info_flag_p;

			IRE_MODIFY_LIGATURE_RELATED_INFORMATION(
				g_indic_rule_engine_cntx.g_prev_character,
				prev_char_status_flag_p,
				previous_startRange,
				previous_endRange,
				langIdIndex);

            IRE_IDENTIFY_CHARACTER(
                g_indic_rule_engine_cntx.g_prev_character, 
                prev_char_status_flag_p, 
                previous_startRange, 
                mCharStatusFlagPrev);
        }
        
        if ((!g_indic_rule_engine_cntx.sign_cons_or_below_base) && 
             (character_position == IRE_BELOW_BASE_POSITION) &&
             (mCharStatusFlagPrev != NORMAL_CON))
        {
                if(g_indic_rule_engine_cntx.error_correction_for_rendering)
            {

                U8 correction = g_indic_rule_engine_cntx.error_correction_for_rendering;
                *ptext_x = g_indic_rule_engine_cntx.g_prev_char_text_x + correction;
                g_indic_rule_engine_cntx.g_prev_char_dwidth = correction + d_width;
                g_indic_rule_engine_cntx.g_prev_char_width = correction + width;
            }
            else
            {
                S32 curr_char_align = ire_identify_char_alignment(current_character);
				MMI_BOOL need_check_alignment = (g_indic_rule_engine_cntx.g_prev_char_width < width)?MMI_FALSE: MMI_TRUE;
	            
				if (need_check_alignment && 
            		(curr_char_align == IRE_RIGHT_ALIGNED_CHARACTER))
				{
        			*ptext_x = g_indic_rule_engine_cntx.g_prev_char_text_x  + (g_indic_rule_engine_cntx.g_prev_char_width - width);
				}
				else
				{
					*ptext_x = g_indic_rule_engine_cntx.g_prev_char_text_x;
				}
            }
                IRE_RESET_RENDERING_CORRECTION();
            }
        else
    #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */ 
        if ((!((mCharStatusFlag & 0x0000F000) ^ ABOVE_BASE_POSITION) || 
        	 !((mCharStatusFlag & 0x0000F000) ^ BELOW_BASE_POSITION_IGNORE_CORRECTION_ATTRIBUTE))
        #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__))    
                 && (!(character_position==IRE_BELOW_BASE_POSITION))
        #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */
           )
        {
            S32 curr_char_align = ire_identify_char_alignment(current_character);
            MMI_BOOL need_check_alignment = (g_indic_rule_engine_cntx.g_prev_char_width < width)?MMI_FALSE: MMI_TRUE;
            
			if (need_check_alignment && 
            	(curr_char_align == IRE_RIGHT_ALIGNED_CHARACTER))
            {
        		*ptext_x = g_indic_rule_engine_cntx.g_prev_char_text_x  + (g_indic_rule_engine_cntx.g_prev_char_width - width);
	        }
			else
			{
				*ptext_x = g_indic_rule_engine_cntx.g_prev_char_text_x;
			}
        }
        else
        {
			{
            if (is_Indic)
            {
                if (!(IRE_INDIC_CHARACTER_UCS2_RANGE(g_indic_rule_engine_cntx.g_prev_character)))
                {
                    g_indic_rule_engine_cntx.g_prev_char_text_x -= g_indic_rule_engine_cntx.g_indic_padding;
                }
            }
            *ptext_x = g_indic_rule_engine_cntx.g_prev_char_dwidth + g_indic_rule_engine_cntx.g_prev_char_text_x;
            g_indic_rule_engine_cntx.g_prev_char_text_x = *ptext_x;
            g_indic_rule_engine_cntx.g_prev_char_dwidth = d_width;
            g_indic_rule_engine_cntx.g_prev_char_width = width;
            #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__))
            IRE_SET_RENDERING_CORRECTION(current_character);
            #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */
			}
        }
    }
    else
    {
        if (is_Indic)
        {
            if (!(IRE_INDIC_CHARACTER_UCS2_RANGE(g_indic_rule_engine_cntx.g_prev_character)))
            {
                g_indic_rule_engine_cntx.g_prev_char_text_x -= g_indic_rule_engine_cntx.g_indic_padding;
            }
        }
        *ptext_x = g_indic_rule_engine_cntx.g_prev_char_dwidth + g_indic_rule_engine_cntx.g_prev_char_text_x;
        g_indic_rule_engine_cntx.g_prev_char_text_x = *ptext_x;
        g_indic_rule_engine_cntx.g_prev_char_dwidth = d_width;
        g_indic_rule_engine_cntx.g_prev_char_width = width;
        #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__))
        IRE_RESET_RENDERING_CORRECTION();
        #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */
    }
    g_indic_rule_engine_cntx.g_prev_character = current_character;
#if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__))
    if( (character_position == IRE_BELOW_BASE_POSITION) || 
    	(!((mCharStatusFlag & 0x0000F000) ^ BELOW_BASE_POSITION_IGNORE_CORRECTION_ATTRIBUTE)) )
    {
        g_indic_rule_engine_cntx.sign_cons_or_below_base = 1;
    }
    else
    {
        g_indic_rule_engine_cntx.sign_cons_or_below_base =0;
    }
#endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */ 
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ire_get_bordered_text_x
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptext_x                 [IN]
 *  current_character       [IN]        
 *  text_y                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ire_get_bordered_text_x(S32 *ptext_x, U16 current_character, S32 text_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 character_height = 0;
    U32 langIdIndex = 0;
    U16 startRange = 0, endRange = 0;

    const ire_character_info_table_struct *char_status_flag_p;
    const ire_character_info_table_struct *pLangFlag;
    ire_indic_languages_table_struct indic_lang_table_info;

    U32 *mchar_status_flag_p = NULL;
    U32 mCharStatusFlag = 0;
    #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__))
    U32 character_position=0;
    #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */
    char_status_flag_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_BORDERED_TEXT_X);

	IRE_GET_CHARACTER_LANG_ID_FROM_PREV_CHAR(current_character, langIdIndex);
    IRE_SET_PREV_CHAR_LANG_ID(langIdIndex);
    /* if not ligature range */
    if (!(current_character & 0xE000))
    {
        /* get Indic language array index   */
        IRE_SET_PREV_CHAR_INFO_TABLE_FROM_CHAR_INFO_TABLE(langIdIndex);
    }
    else
    {
        /* get Indic language ligature array index   */
        IRE_SET_PREV_CHAR_INFO_TABLE_FROM_LIGATURE_INFO_TABLE(langIdIndex);
    }
    if (g_indic_rule_engine_cntx.g_new_bline)
    {
        g_indic_rule_engine_cntx.g_new_bline = 0;
        g_indic_rule_engine_cntx.g_prev_char_btext_x = *ptext_x;
        Get_CharWidthHeight(current_character, &(g_indic_rule_engine_cntx.g_prev_char_bdwidth), &character_height);
        return;
    }
    if (langIdIndex)
    {
        /* start range of Indic language ligature or character */
        startRange = indic_lang_table_info.start_range;
        /* end range of Indic language */
        endRange = indic_lang_table_info.end_range;
        /* get the pointer to the begining of the array of structures  */
        char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;
        
        IRE_MODIFY_LIGATURE_RELATED_INFORMATION(
        	current_character,
        	char_status_flag_p,
        	startRange,
        	endRange,
        	langIdIndex);
        
        /* get pointer of the character flag which is nothing but pointer to a structure */
        pLangFlag = (char_status_flag_p + ((current_character - startRange) - 1));
        /* store the charater flag information by ORing and shifting bits */
        mchar_status_flag_p = (U32*) pLangFlag;

        mCharStatusFlag = *mchar_status_flag_p;
    }
    /*
     * As char might belong to indic range, but our product doesn't support that language
     * In that case, just fill the char as such, it could be in the form of square box.
     * so this check is required
     */
    #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__)) 
    character_position = ire_identify_char_position(current_character);
    #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */
    if (NULL != char_status_flag_p)
    {
    #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__))
        if (IRE_GET_SMALL_CONSONANT_FLAG() && (character_position==IRE_BELOW_BASE_POSITION))
        {
            *ptext_x = g_indic_rule_engine_cntx.g_prev_char_btext_x;
            g_indic_rule_engine_cntx.g_prev_char_bdwidth = g_indic_rule_engine_cntx.g_prev_char_bdwidth;
            #if !defined (__MMI_LANG_MYANMAR__)
            IRE_RESET_SMALL_CONSONANT_FLAG();
#endif
        }
        else
    #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */ 
        if ((!((mCharStatusFlag & 0x0000F000) ^ ABOVE_BASE_POSITION) || 
        	 !((mCharStatusFlag & 0x0000F000) ^ BELOW_BASE_POSITION_IGNORE_CORRECTION_ATTRIBUTE))
            #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) || defined (__MMI_LANG_KHMER__) || defined (__MMI_LANG_MYANMAR__))
             && (!(character_position==IRE_BELOW_BASE_POSITION))
            #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */
           )
        {
            *ptext_x = g_indic_rule_engine_cntx.g_prev_char_btext_x;
            g_indic_rule_engine_cntx.g_prev_char_bdwidth = g_indic_rule_engine_cntx.g_prev_char_bdwidth;
        #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__))
            if ((mCharStatusFlag & 0x0000F000) == BELOW_BASE_POSITION_IGNORE_CORRECTION_ATTRIBUTE)
            {
                IRE_RESET_SMALL_CONSONANT_FLAG();
            }
        #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */ 

        }
        else
        {
            *ptext_x = g_indic_rule_engine_cntx.g_prev_char_bdwidth + g_indic_rule_engine_cntx.g_prev_char_btext_x;
            g_indic_rule_engine_cntx.g_prev_char_btext_x = *ptext_x;
            Get_CharWidthHeight(current_character, &(g_indic_rule_engine_cntx.g_prev_char_bdwidth), &character_height);
        #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__))
            if (IRE_GET_SMALL_CONSONANT_FLAG() && ((mCharStatusFlag & 0x0000000F) == NORMAL_CON))
            {
                IRE_RESET_SMALL_CONSONANT_FLAG();
            }
        #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */ 

        }
    }
    else
    {
        *ptext_x = g_indic_rule_engine_cntx.g_prev_char_bdwidth + g_indic_rule_engine_cntx.g_prev_char_btext_x;
        g_indic_rule_engine_cntx.g_prev_char_btext_x = *ptext_x;
        Get_CharWidthHeight(current_character, &(g_indic_rule_engine_cntx.g_prev_char_bdwidth), &character_height);
    #if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__) )
        if (IRE_GET_SMALL_CONSONANT_FLAG())
        {
            IRE_RESET_SMALL_CONSONANT_FLAG();
        }
    #endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */ 
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ire_language_rules
 * DESCRIPTION			
 *  This method will apply grammer rules on the input cluster buffer
 *  and copy the output buffer i.e glyphoutput
 * PARAMETERS
 *  glyphoutput     [IN]        
 *  cluster         [IN]        
 *  nentry          [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 ire_language_rules(PU16 glyphoutput, PU16 cluster, S32 nentry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 size;
    S32 noutglyph = 0;      /* no. of entries in output cluster to be given to renderer */
    S32 matched = FALSE;
    S32 input = nentry;
    S32 tomatch = nentry;   /* nentries--no. of elements in the cluster */
    S32 is_last_char_halant = MMI_FALSE; /* to check weather the last character in the cluster is halant */
    U32 langIdIndex = 0;    /* to store the value of language Id of input character */
    U32 mCharStatusFlagPrev = 0;
    U32 mCharStatusFlag = 0;
    U32 mCharStatusFlagNext = 0;
    U16 startRange = 0;     /* to store the starting range of language of input character */
    U16 is_input_buffer_cpy = MMI_FALSE;
    S32 temp = 0;

#if defined (__MMI_LANG_TELUGU__)
    U8 check_seq_KA_hal_SSA = MMI_FALSE;
    PU16 pglyphoutput = NULL;
#endif /* defined (__MMI_LANG_TELUGU__) */    
#if (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__))
    U8 telugu_kannada_check = 0;
#endif /* (defined (__MMI_LANG_TELUGU__) || defined (__MMI_LANG_KANNADA__)) */ 

    const ire_main_glyph_table_struct *main_glyph_table_base_address_p;
    const ire_character_info_table_struct *char_status_flag_p = NULL;
    const ire_glyph_info_table_struct *char_table_p;    /* pointer to character table containing ligature info   of that character */
    ire_main_glyph_table_struct ind_table;              /* main table containing full character table info */
    ire_indic_languages_table_struct indic_lang_table_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_LANGUAGE_RULES);
    
    /* get language index   */
    IRE_GET_CHARACTER_LANG_ID_FROM_PREV_CHAR((*cluster), langIdIndex);
    IRE_SET_PREV_CHAR_LANG_ID(langIdIndex);

	/* Some times before the language rules have been applied to the API, we need to adjuct/reorder some of the
     * character for this we will call a function corresponding to a specific language to adjust/reorder the 
     * characters, according to the requirement
     */
    switch(langIdIndex) 
    {
        #if defined (__MMI_LANG_KHMER__)
        case IRE_LANGUAGE_ID_KHMER:
            ire_adjust_after_language_rules_for_khmer_before_rules(cluster, nentry);
            break;
        #endif /* defined (__MMI_LANG_KHMER__) */
        default:
            break;
    }
    /* get Indic language array index   */
    /* if not ligature range */
    if (!((*cluster) & 0xE000))
    {
        /* get Indic language array index   */
        IRE_SET_PREV_CHAR_INFO_TABLE_FROM_CHAR_INFO_TABLE(langIdIndex);
    }
    else
    {
        /* get Indic language ligature array index   */
        IRE_SET_PREV_CHAR_INFO_TABLE_FROM_LIGATURE_INFO_TABLE(langIdIndex);
    }
    /* start range of Indic language */
    startRange = indic_lang_table_info.start_range;
    /* get the pointer to the begining of the array of structures  */
    char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;

    main_glyph_table_base_address_p = indic_lang_table_info.indic_main_info_table_p;

    if (IRE_INDIC_CHARACTER_UCS2_RANGE(*cluster))
    {
        /*  if number of entries are single  */
        if (nentry == 1)
        {
			glyphoutput[0] = *cluster;
            glyphoutput[1] = (U16) NULL;
            return 1;
        }
        /* more than one entries   */
        while (nentry)
        {
        #if (defined (__MMI_LANG_TELUGU__) || defined(__MMI_LANG_KANNADA__))
            if ( (!telugu_kannada_check) && (IRE_GET_SMALL_CONS_HALANT_FLAG() == 2) )
            {
                telugu_kannada_check = 1;
            #if defined (__MMI_LANG_TELUGU__)
                if( nentry > 2 && cluster[0] == TELUGU_C_KA && cluster[2] == TELUGU_C_SSA)
                {
                 check_seq_KA_hal_SSA = MMI_TRUE;
                 pglyphoutput = glyphoutput;
                }
            #endif /* defined (__MMI_LANG_TELUGU__) */ 
                glyphoutput[0] = *cluster;
                glyphoutput[1] = (U16) NULL;
                glyphoutput++;
                cluster++;
                nentry--;
                noutglyph++;
            }
        #endif /* (defined (__MMI_LANG_TELUGU__) || defined(__MMI_LANG_KANNADA__)) */ 
            if (!(*cluster & 0xE000))
			{
				/* get Indic language array index   */
				IRE_SET_PREV_CHAR_INFO_TABLE_FROM_CHAR_INFO_TABLE(langIdIndex);

				/* start range of Indic language */
				startRange = indic_lang_table_info.start_range;

				/* get the pointer to the begining of the array of structures  */
				char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;

				temp = (S32) (*cluster) - startRange - 1;
			}
			/* To handle the case when the second part of 
			 * spliat base matra is in ligature range
			 */
			else
			{
				/**glyphoutput = *cluster;
				nentry--;
                noutglyph++;
                cluster++;
                glyphoutput++;
				if(*cluster == (U16)NULL)
                {
                    *glyphoutput = (U16)NULL;
                    return noutglyph;
                }
                else
                {
                    --tomatch;
                    continue;
                }*/

				/*#if defined(__MMI_LANG_KHMER__)
				if (*cluster != KHMER_LIGRATURE_178)
				#endif  defined(__MMI_LANG_KHMER__) */
				{
					temp = -1;
				}
				/*#if defined(__MMI_LANG_KHMER__)
				else
				{
			    		  get Indic language ligature array index   
                    IRE_SET_PREV_CHAR_INFO_TABLE_FROM_LIGATURE_INFO_TABLE(langIdIndex);

                     start range of Indic language 
                    startRange = indic_lang_table_info.start_range;
                     get the pointer to the begining of the array of structures  
                    char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;

                    temp = (S32) (*cluster) - startRange - 1;
				}
				#endif  defined(__MMI_LANG_KHMER__) */
			}

            if ((main_glyph_table_base_address_p != NULL)&&(temp>=0)) /*[MAUI_03059048]*/
            {
            	ind_table = main_glyph_table_base_address_p[temp];  /* gets the individual charactr's table in main table */
            }
            
            if ((temp < 0) || (ind_table.glyph_info_p == NULL) || main_glyph_table_base_address_p == NULL)
            {
                if(IRE_INDIC_CHARACTER_UCS2_RANGE(*cluster))
                {
                    *glyphoutput = *cluster;
                    nentry--;
                    noutglyph++;
                    cluster++;
                    glyphoutput++;
                    if(*cluster == (U16)NULL)
                    {
                        *glyphoutput = (U16)NULL;
                        break;
                    }
                    else
                    {
                        --tomatch;
                        continue;
                    }
                }
                else
                {
                    glyphoutput[nentry - 1] = *cluster;
                    glyphoutput[nentry] = (U16) NULL;
                    return nentry;
                }
            }
            char_table_p = ind_table.glyph_info_p;  /* holds the add. of individual character */
            size = ind_table.nsize;
            matched = FALSE;
            while (size)
            {
                size--;
                if ((tomatch != char_table_p[size].input_buffer_len)
		   #if (defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__))
                    || ((char_table_p[size].rule_language) &&
                        (char_table_p[size].rule_language != indic_rules_current_set_language))
		   #endif /* (defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__)) */
		    )
                {
                    if (tomatch > char_table_p[size].input_buffer_len)
                    {
                        break;
                    }
                    continue;
                }
		else if ((char_table_p[size].input_buffer_len == 1) || 
                         ((mmi_ire_reverse_memcmp(char_table_p[size].input_buffer_glyph + 1, 
                                                  cluster + 1, 
                                                  (U8)(char_table_p[size].input_buffer_len - 1)) == MMI_TRUE) &&
                         (char_table_p[size].input_buffer_len != 1)))
                {
                    IRE_IDENTIFY_CHARACTER((*cluster), char_status_flag_p, startRange, mCharStatusFlag);

                    switch (mCharStatusFlag)
                    {
                        case RA_CON:
                        case KANNADA_RA_CON:
                        {
                            if (noutglyph)
                            {
                                IRE_IDENTIFY_CHARACTER(*(cluster - 1), char_status_flag_p, startRange, mCharStatusFlagPrev);
                            }
                            else
                            {
                                mCharStatusFlag = 0;
                            }
                            IRE_IDENTIFY_CHARACTER(*(cluster + 1), char_status_flag_p, startRange, mCharStatusFlagNext);

                            if ( 
                                 ( (input >= 3) &&
                                   ( (!(mCharStatusFlagPrev ^ NORMAL_CON)) || 
                                     (!(mCharStatusFlagPrev ^ RA_CON)) ||
                                     (!(mCharStatusFlagPrev ^ POST_BASE_DEPVOWEL)) 
                                   ) 
                                 ) 
                                 /* FOR HANDLING REORDERING FOR kANNADA RA */
                                 #if defined(__MMI_LANG_KANNADA__)
                                 || 
                                 /* KANNADA_RA_CON + HALANT should be displayed as the output_buffer_glyph
                                  * from the character_table, whenever we have some character/ligature in the
                                  * glyphoutput buffer prior to this comnbination */
                                 (
                                     (!(mCharStatusFlag ^ KANNADA_RA_CON)) &&
                                     (is_RA_hal_reordering) &&                                      
                                     (noutglyph != 0)
                                 )
                                 #endif /* defined(__MMI_LANG_KANNADA__) */
                               )
                            {
                                memcpy(
                                    glyphoutput,
                                    char_table_p[size].output_buffer_glyph,
                                    char_table_p[size].output_buffer_len * 2);
                                glyphoutput[char_table_p[size].output_buffer_len] = (U16) NULL;
                                break;
                            }

                            else if (!(mCharStatusFlagNext ^ HALANT))
                            {
								#if defined(__MMI_MULTITAP_BANGLA_SPEC__)
							if(check_ra_hal_bangla_for_imui)
							{
								memcpy(
                                    glyphoutput,
                                    char_table_p[size].output_buffer_glyph,
                                    char_table_p[size].output_buffer_len * 2);
								glyphoutput[char_table_p[size].output_buffer_len] = (U16) NULL;
								check_ra_hal_bangla_for_imui =MMI_FALSE;
                                break;
							}
							else
#endif	
							{
                                memcpy(
                                    glyphoutput,
                                    char_table_p[size].input_buffer_glyph,
                                    char_table_p[size].input_buffer_len * 2);
                                glyphoutput[char_table_p[size].input_buffer_len] = (U16) NULL;
								is_input_buffer_cpy = MMI_TRUE;
                                #if defined(__MMI_LANG_KANNADA__)
                                IRE_IDENTIFY_CHARACTER((*cluster), char_status_flag_p, startRange, mCharStatusFlag);
                                if(!(mCharStatusFlag ^ KANNADA_RA_CON))
                                {
                                    /* if the cluster buffer contains RA + Halant + NULL,
                                     * then instead of displaying the input buffer glyph, 
                                     * display the ligature KANNADA_L_RA_HALANT
                                     */
                                    glyphoutput[0] = KANNADA_L_RA_HALANT;
                                    glyphoutput[1] = (U16)NULL;
                                    
                                    /* The input buffer glyph contains 2 characters and noutglyph will be increased by 2 
                                     * but here we are displaying the ligature which has only 1 character, hence
                                     * glyphoutput and noutglyph are being reduced by 1 
                                     */
                                    glyphoutput -= 1;
                                    noutglyph -= 1;
                                }
                                #endif /* defined(__MMI_LANG_KANNADA__) */
                                break;
                            }
							}
							else
							{
                                memcpy(
                                    glyphoutput,
                                    char_table_p[size].output_buffer_glyph,
                                    char_table_p[size].output_buffer_len * 2);
                                glyphoutput[char_table_p[size].output_buffer_len] = (U16) NULL;
                                break;
							 }
                        }   /* End of case RA statement */
                        default:
                        {
                            /* identifying the last character in the global display buffer */
                            IRE_IDENTIFY_CHARACTER(*(cluster + tomatch - 1), char_status_flag_p, startRange, mCharStatusFlag);

                            /* checking that whether the HALANT is the last character in the global display buffer */
                            if ((!((mCharStatusFlag) ^ HALANT)) && (*(cluster + tomatch) == (U16) NULL))
                            {
                                if (char_table_p[size].is_con_hal_ligature == 0)
                                {
									if((tomatch <= 2))
                                    {
										#if defined (__MMI_LANG_KHMER__)
											if(*cluster == KHMER_C_NYO)
											{
												memcpy(
														glyphoutput,
														char_table_p[size].output_buffer_glyph,
														char_table_p[size].output_buffer_len * 2);
														glyphoutput[char_table_p[size].output_buffer_len] = (U16) NULL;
											}
											else
											{
												memcpy(
														glyphoutput,
														char_table_p[size].input_buffer_glyph,
														char_table_p[size].input_buffer_len * 2);
												glyphoutput[char_table_p[size].input_buffer_len] = (U16) NULL;
												is_input_buffer_cpy = MMI_TRUE;
											}
										#else
                                        memcpy(
                                            glyphoutput,
                                            char_table_p[size].input_buffer_glyph,
                                            char_table_p[size].input_buffer_len * 2);
                                        glyphoutput[char_table_p[size].input_buffer_len] = (U16) NULL;
                                        is_input_buffer_cpy = MMI_TRUE;
										#endif
                                        break;
                                    }
                                    
                                    
	                                
                                    /* if we dont have the combination (RA + Hal) or (Hal + Hal) */
                                    if(!is_RA_hal_reordering) /* if not set global RA_reorder flag */
                                    {            
                                        is_last_char_halant = MMI_TRUE;
                                        break; /* break from default */
                                    }
                                }
                            }
                            memcpy(
                                glyphoutput,
                                char_table_p[size].output_buffer_glyph,
                                char_table_p[size].output_buffer_len * 2);
                            glyphoutput[char_table_p[size].output_buffer_len] = (U16) NULL;
                            break;
                          
                        }   /* End of default statement */
                    }       /* End of switch case   */

                    if(is_last_char_halant)
                    {
                        is_last_char_halant = MMI_FALSE;
                        continue; /* continue with the inner while loop */
                    }
                    nentry -= char_table_p[size].input_buffer_len;
                    cluster += char_table_p[size].input_buffer_len;

                    if (is_input_buffer_cpy)
                    {
                        glyphoutput += char_table_p[size].input_buffer_len;
                        noutglyph += char_table_p[size].input_buffer_len;
                        is_input_buffer_cpy = MMI_FALSE;
                    }
                    else
                    {
                        glyphoutput += char_table_p[size].output_buffer_len;
                        noutglyph += char_table_p[size].output_buffer_len;
                    }
                    matched = TRUE;

                    IRE_IDENTIFY_CHARACTER(*cluster, char_status_flag_p, startRange, mCharStatusFlag);


                #if defined (__MMI_LANG_TAMIL__)
					IRE_IDENTIFY_CHARACTER(*cluster, char_status_flag_p, startRange, mCharStatusFlag);
					if ((*(glyphoutput - 1) == TAMIL_L_KSHA) &&
                             (!((mCharStatusFlag) ^ CENTER_BASE_DEPVOWEL)))
                    {
                        /* centre base handling */
                        ind_table = main_glyph_table_base_address_p[((*cluster) - startRange) - 1];     /* gets the individual charactr's table in main table */
                        char_table_p = ind_table.glyph_info_p;  /* holds the add. of individual character */
                        switch (*(glyphoutput - 1))
                        {
                            case TAMIL_L_KSHA:
                            {
                                *(glyphoutput - 1) = char_table_p[0].output_buffer_glyph[0];
                                *(glyphoutput) = TAMIL_L_KSHA;
                                *(glyphoutput + 1) = char_table_p[0].output_buffer_glyph[1];
                                break;
                            }
                            default:
                                break;
                        }
                        *(glyphoutput + 2) = (U16) NULL;
                        nentry -= 1;
                        cluster += 1;
                        noutglyph += 2;
                        matched = TRUE;
                        break;
                    }   /* End of else if statement */
                #endif /* defined (__MMI_LANG_TAMIL__) */ 
                    break;
                }
            }   /*   End of inner while loop */
            if (matched != TRUE && tomatch)
            {
                --tomatch;
            }
            else
            {
                tomatch = nentry;
            }
        }   /* End of outer while loop */
  MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_LANGUAGE_RULES_NOUTGLYPH, noutglyph);
	  #if defined (__MMI_LANG_TELUGU__)
        if (check_seq_KA_hal_SSA)
        {
            U8 index = 0;

            while (pglyphoutput[index] != (U16) NULL)
            {
                if (pglyphoutput[index] == (U16) TELUGU_L_SMALL_SSA)
                {
                    pglyphoutput[index] = (U16) TELUGU_L_KSHA_HALANT;
                    break;
                }
                index++;
            }

        }
    #endif /* defined (__MMI_LANG_TELUGU__) */ 
        
        /* Some times after the language rules have been applied to the API, we need to adjuct/reorder some of the
         * character for this we will call a function corresponding to a specific language to adjust/reorder the 
         * characters, according to the requirement
         */
        switch(g_indic_rule_engine_cntx.ire_prev_char_lang_id.lang_id_index) 
        {
            #if defined (__MMI_LANG_MALAYALAM__)
            case IRE_LANGUAGE_ID_MALAYALAM:
                ire_adjust_after_language_rules_for_malayalam(glyphoutput, noutglyph);
                break;
            #endif /* defined (__MMI_LANG_MALAYALAM__) */
            #if defined (__MMI_LANG_KANNADA__)
            case IRE_LANGUAGE_ID_KANNADA:
                ire_adjust_after_language_rules_for_kannada(glyphoutput, noutglyph);
                break;
            #endif /* defined (__MMI_LANG_KANNADA__) */
            #if defined (__MMI_LANG_TELUGU__)
            case IRE_LANGUAGE_ID_TELUGU:
                ire_adjust_after_language_rules_for_telugu(glyphoutput, noutglyph);
                break;
            #endif /* defined (__MMI_LANG_TELUGU__) */
			#if defined (__MMI_LANG_MYANMAR__)
            case IRE_LANGUAGE_ID_MYANMAR:
                ire_adjust_after_language_rules_for_myanmar(glyphoutput, noutglyph);
                break;
            #endif /* defined (__MMI_LANG_KHMER__) */
				#if defined (__MMI_LANG_KHMER__)
            case IRE_LANGUAGE_ID_KHMER:
                ire_adjust_after_language_rules_for_khmer(glyphoutput, noutglyph);
                break;
            #endif /* defined (__MMI_LANG_KHMER__) */
            default:
                break;
        }
            
        return noutglyph;
    }   /* End of if statement */
    else
    {
        glyphoutput[0] = *cluster;
        glyphoutput[1] = (U16) NULL;
        return 1;
    }
}


#if defined (__MMI_INDIC_ALG__) && defined (__MMI_BIDI_ALG__)
/*****************************************************************************
 * FUNCTION
 *  ire_get_indic_rules_for_whole_string
 * DESCRIPTION
 *  This function will be called if both R2L and Indic Languages are present
 * PARAMETERS
 *  String      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ire_get_indic_rules_for_whole_string(PU8 String, PU8 temp_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S32 Len;
    S32 cluster_length;
    U16 unicode = 0;
    U16 Fill = 0;
    U16 clFill = 0;
    U16 cluster_fill[G_MAX + 1];
    U16 glyph_output[G_MAX + 1];
    U16 indic_present = 0;
    U8 *temp_string = String;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_GET_INDIC_RULES_FOR_WHOLE_STRING);
    
    /* If the memory is not available for allocation to the pointer,give an assert */
    if (temp_buffer == NULL)
	{
		MMI_ASSERT(0);
	}
	
    while ((temp_string[clFill] != '\0' || temp_string[clFill + 1] != '\0') && !indic_present)
    {
        unicode = temp_string[clFill];
        unicode |= (temp_string[clFill + 1] << 8);
        if (IRE_INDIC_CHARACTER_UCS2_RANGE(unicode))
        {
            indic_present = 1;
        }
        clFill += 2;
    }
    if (indic_present)
    {
        ire_init_cluster_start_p(String);
        ire_init_cluster_end_p(String + (2 * mmi_ucs2strlen((const char*)String)));
        while (temp_string[0] != '\0' || temp_string[1] != '\0')
        {
            clFill = 0;
            unicode = temp_string[0];
            unicode |= (temp_string[1] << 8);
            cluster_length = ire_get_cluster(cluster_fill);
            if (IRE_INDIC_CHARACTER_UCS2_RANGE(unicode))
            {
                if(cluster_length > 1)
                {
                ire_language_rules(glyph_output, cluster_fill, g_indic_rule_engine_cntx.g_display_buffer_len);
                temp_string += cluster_length * 2;
                }
                else
                {
                    temp_buffer[Fill++] = temp_string[0];
                    temp_buffer[Fill++] = temp_string[1];
                    temp_string += 2;
                }
                while (glyph_output[clFill] != '\0')
                {
                    temp_buffer[Fill++] = (U8) (glyph_output[clFill] & 0x00ff);
                    temp_buffer[Fill++] = (U8) (glyph_output[clFill++] >> 8) & 0x00ff;
                }
            }
            else
            {
                temp_buffer[Fill++] = temp_string[0];
                temp_buffer[Fill++] = temp_string[1];
                temp_string += 2;
            }
        }
        temp_buffer[Fill++] = '\0';
        temp_buffer[Fill++] = '\0';
        memcpy(String, temp_buffer, Fill);
    }
}
#endif /* defined (__MMI_INDIC_ALG__) && defined (__MMI_BIDI_ALG__) */



#endif
/*****************************************************************************
 * FUNCTION
 *  ire_identify_character_type
 * DESCRIPTION
 * PARAMETERS
 *  currentCharacter        [IN]        
 * RETURNS
 *  S32   Character type 
 *****************************************************************************/
S32 ire_identify_character_type(U16 currentCharacter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 langIdIndex = 0;
    U16 startRange = 0, endRange = 0;

    ire_indic_languages_table_struct indic_lang_table_info;
    const ire_character_info_table_struct *char_status_flag_p;

    U32 mCharStatusFlag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_IDENTIFY_CHARACTER_TYPE);
    
    if (IRE_INDIC_CHARACTER_UCS2_RANGE(currentCharacter))
    {
        /* get language index   */
        IRE_GET_CHARACTER_LANG_ID_FROM_PREV_CHAR(currentCharacter, langIdIndex);
        IRE_SET_PREV_CHAR_LANG_ID(langIdIndex);
        /* if not ligature range */
        if (!(currentCharacter & 0xE000))
        {
            /* get Indic language array index   */
			IRE_SET_PREV_CHAR_INFO_TABLE_FROM_CHAR_INFO_TABLE(langIdIndex);
        }
        else
        {
            /* get Indic language ligature array index   */
			IRE_SET_PREV_CHAR_INFO_TABLE_FROM_LIGATURE_INFO_TABLE(langIdIndex);
        }
		    /* start range of Indic language ligature or character */
            startRange = indic_lang_table_info.start_range;
            /* end range of Indic language ligature or character */
            endRange = indic_lang_table_info.end_range;
            /* get the pointer to the begining of the array of structures */
            char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;

        /*
         * As char might belong to indic range, but our product doesn't support that language
         * In that case, just fill the char as such, it could be in the form of square box.
         * so this check is required
         */
        if (NULL == char_status_flag_p)
        {
            return 0;
        }
        
        IRE_MODIFY_LIGATURE_RELATED_INFORMATION(
        	currentCharacter,
        	char_status_flag_p,
        	startRange,
        	endRange,
        	langIdIndex);
        	
        /* Identify next character and update character flag  */
        IRE_IDENTIFY_CHARACTER(currentCharacter, char_status_flag_p, startRange, mCharStatusFlag);

        switch (mCharStatusFlag)
        {
            case NORMAL_CON:        /* 0x00000001 */
            case SMALL_CON:         /* 0x00000003 */
            case RA_CON:            /* 0x00000002 */
            case KANNADA_RA_CON:    /* 0x00000004 */
            case CHILLU_CHARACTER:  /* 0x00000005 */
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_IDENTIFY_CHARACTER_TYPE_CONSONANT, IRE_CHAR_TYPE_CON);
		            return IRE_CHAR_TYPE_CON;

            case INDEPVOWEL:    /* 0x00000040 */
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_IDENTIFY_CHARACTER_TYPE_INDEPVOWEL, IRE_CHAR_TYPE_INDEPVOWEL);
		            return IRE_CHAR_TYPE_INDEPVOWEL;

            case PRE_BASE_DEPVOWEL:     /* 0x00000008 */
            case POST_BASE_DEPVOWEL:    /* 0x00000010 */
            case CENTER_BASE_DEPVOWEL:  /* 0x00000028 */
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_IDENTIFY_CHARACTER_TYPE_DEPVOWEL, IRE_CHAR_TYPE_DEPVOWEL);
		            return IRE_CHAR_TYPE_DEPVOWEL;

            case NORMALSIGN:    /* 0x00000100; */
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_IDENTIFY_CHARACTER_TYPE_SIGN, IRE_CHAR_TYPE_SIGN);
                return IRE_CHAR_TYPE_SIGN;
            case TAMIL_HALANT_SIGN:
                return IRE_CHAR_TYPE_HALANT1;

            case HALANT:    /* 0x00000080 */
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_IDENTIFY_CHARACTER_TYPE_HALANT, IRE_CHAR_TYPE_HALANT);
		            return IRE_CHAR_TYPE_HALANT;

            case LIGATURE:  /* 0x00000200 */
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_IDENTIFY_CHARACTER_TYPE_LIGATURE, IRE_CHAR_TYPE_LIGATURE);
		            return IRE_CHAR_TYPE_LIGATURE;

            case DIGITS:    /* 0x00000800 */
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_IDENTIFY_CHARACTER_TYPE_DIGIT, IRE_CHAR_TYPE_DIGIT);
		            return IRE_CHAR_TYPE_DIGIT;

            default:
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_IDENTIFY_CHARACTER_TYPE_INVALID, IRE_CHAR_TYPE_INVALID);
		            return IRE_CHAR_TYPE_INVALID;
        }
    }
    return IRE_CHAR_TYPE_INVALID;
}


/*****************************************************************************
 * FUNCTION
 *  ire_identify_sign_range
 * DESCRIPTION
 * PARAMETERS
 *  currentCharacter        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 ire_identify_sign_range(U16 currentCharacter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 langIdIndex = 0;
    U16 startRange = 0, endRange = 0;

    ire_indic_languages_table_struct indic_lang_table_info;
    const ire_character_info_table_struct *char_status_flag_p;

    const ire_character_info_table_struct *pLangFlag;

    U32 *mchar_status_flag_p = NULL;
    U32 mCharStatusFlag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_IDENTIFY_SIGN_RANGE);
    
    if (IRE_INDIC_CHARACTER_UCS2_RANGE(currentCharacter))
    {
        /* get language index   */
        IRE_GET_CHARACTER_LANG_ID_FROM_PREV_CHAR(currentCharacter, langIdIndex);
        IRE_SET_PREV_CHAR_LANG_ID(langIdIndex);

        /* if not ligature range */
        if (!(currentCharacter & 0xE000))
        {
            /* get Indic language array index   */
            IRE_SET_PREV_CHAR_INFO_TABLE_FROM_CHAR_INFO_TABLE(langIdIndex);
        }
        else
        {
            /* get Indic language ligature array index   */
            IRE_SET_PREV_CHAR_INFO_TABLE_FROM_LIGATURE_INFO_TABLE(langIdIndex);
        }
			/* start range of Indic language ligature or character */
            startRange = indic_lang_table_info.start_range;
            /* end range of Indic language */
        	endRange = indic_lang_table_info.end_range;
            /* get the pointer to the begining of the array of structures */
            char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;

        /*
         * As char might belong to indic range, but our product doesn't support that language
         * In that case, just fill the char as such, it could be in the form of square box.
         * so this check is required
         */
        if (NULL == char_status_flag_p)
        {
            return 0;
        }
        
        IRE_MODIFY_LIGATURE_RELATED_INFORMATION(
        	currentCharacter,
        	char_status_flag_p,
        	startRange,
        	endRange,
        	langIdIndex);
        
        /* get pointer of the character flag which is nothing but pointer to a structure */
        pLangFlag = (char_status_flag_p + ((currentCharacter - startRange) - 1));
        /* store the charater flag information by ORing and shifting bits */
        mchar_status_flag_p = (U32*) pLangFlag;

        mCharStatusFlag = *mchar_status_flag_p;
        if (!((mCharStatusFlag & 0x0000F000) ^ ABOVE_BASE_POSITION) || !((mCharStatusFlag & 0x0000F000) ^ BELOW_BASE_POSITION))
        {
            return 1;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  ire_identify_char_position
 * DESCRIPTION
 *  This API is used to return the family to which the character belongs
 * PARAMETERS
 *  currentCharacter        [IN]    The current character    
 * RETURNS
 *  S32                     [OUT]   The family to which the character belongs
 *****************************************************************************/
S32 ire_identify_char_position(U16 currentCharacter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 langIdIndex = 0;
    U16 startRange = 0, endRange = 0;

    ire_indic_languages_table_struct indic_lang_table_info;
    const ire_character_info_table_struct *char_status_flag_p;

    const ire_character_info_table_struct *pLangFlag;

    U32 *mchar_status_flag_p = NULL;
    U32 mCharStatusFlag = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_IDENTIFY_CHAR_POSITION);
    
    if (IRE_INDIC_CHARACTER_UCS2_RANGE(currentCharacter))
    {
        /* get language index   */
        IRE_GET_CHARACTER_LANG_ID_FROM_PREV_CHAR(currentCharacter, langIdIndex);
        IRE_SET_PREV_CHAR_LANG_ID(langIdIndex);

        /* if not ligature range */
        if (!(currentCharacter & 0xE000))
        {
            /* get Indic language array index   */
            IRE_SET_PREV_CHAR_INFO_TABLE_FROM_CHAR_INFO_TABLE(langIdIndex);
        }
        else
        {
            /* get Indic language ligature array index   */
            IRE_SET_PREV_CHAR_INFO_TABLE_FROM_LIGATURE_INFO_TABLE(langIdIndex);
        }
		    /* start range of Indic language ligature or character */
            startRange = indic_lang_table_info.start_range;
            /* end range of Indic language */
        	endRange = indic_lang_table_info.end_range;
            /* get the pointer to the begining of the array of structures */
            char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;

        /*
         * As char might belong to indic range, but our product doesn't support that language
         * In that case, just fill the char as such, it could be in the form of square box.
         * so this check is required
         */
        if (NULL == char_status_flag_p)
        {
            return 0;
        }
        
        IRE_MODIFY_LIGATURE_RELATED_INFORMATION(
        	currentCharacter,
        	char_status_flag_p,
        	startRange,
        	endRange,
        	langIdIndex);
        
        /* get pointer of the character flag which is nothing but pointer to a structure */
        pLangFlag = (char_status_flag_p + ((currentCharacter - startRange) - 1));
        /* store the charater flag information by ORing and shifting bits */
        mchar_status_flag_p = (U32*) pLangFlag;

        mCharStatusFlag = *mchar_status_flag_p;

        switch (mCharStatusFlag & 0x0000F000)
        {
            case ABOVE_BASE_POSITION:
                return IRE_ABOVE_BASE_POSITION;                             /* IRE_CHAR_TYPE_SIGN */

            case BELOW_BASE_POSITION_IGNORE_CORRECTION_ATTRIBUTE:
                return IRE_BELOW_BASE_POSITION_IGNORE_CORRECTION_ATTRIBUTE; /* dependent vowel or sign with below base position */
                /* IRE_CHAR_TYPE_SPECIAL_SIGN */

            case BELOW_BASE_POSITION:                                       
                return IRE_BELOW_BASE_POSITION;                             /* IRE_CHAR_TYPE_SIGN_CONSONANT ie small consonants with below base position */

            /* CONSONANT FOR WHICH RENDERING CORRECTION FLAG IS SET AS 1, 
             * This consonants will display the small consonants from 
             * half of the width of previous  base consonant
             */
            case POST_BASE_POSITION_REQ_CORRECTION:  
                return IRE_POST_BASE_POSITION_REQ_CORRECTION;               

            /* CONSONANT FOR WHICH RENDERING CORRECTION FLAG IS SET AS 1, 
             * This consonants will display the small consonants from 
             * one less than the width of previous  base consonant
             */
            case POST_BASE_POSITION_REQ_CORRECTION2:  
                return IRE_POST_BASE_POSITION_REQ_CORRECTION2;              

            case BELOW_AND_POST_BASE_POSITION:
                return IRE_BELOW_AND_POST_BASE_POSITION;                    /* IRE_CHAR_TYPE_SIGN_CONSONANT ie small consonants with post base position */

			/* Consider the offset of previous character in
			 * calculating the width if the next character
			 * has the following attribute
			 */
			case POST_BASE_POSITION_CONSIDERING_PREV_OFFSET:
                return IRE_POST_BASE_POSITION_CONSIDERING_PREV_OFFSET;

            default :
                return IRE_POSTBASE_POSITION;
        }

    }
    return IRE_POSTBASE_POSITION;
}
#if !defined(__MMI_IRE_SLIM__)


/*****************************************************************************
 * FUNCTION
 *  ire_identify_char_position
 * DESCRIPTION
 *  This API is used to return the alignment of character
 * PARAMETERS
 *  currentCharacter        [IN]    The current character    
 * RETURNS
 *  S32                     [OUT]   The family to which the character belongs
 *****************************************************************************/
S32 ire_identify_char_alignment(U16 currentCharacter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 langIdIndex = 0;
    U16 startRange = 0, endRange = 0;

    ire_indic_languages_table_struct indic_lang_table_info;
    const ire_character_info_table_struct *char_status_flag_p;

    const ire_character_info_table_struct *pLangFlag;

    U32 *mchar_status_flag_p = NULL;
    U32 mCharStatusFlag = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IRE_INDIC_CHARACTER_UCS2_RANGE(currentCharacter))
    {
        /* get language index   */
        IRE_GET_CHARACTER_LANG_ID_FROM_PREV_CHAR(currentCharacter, langIdIndex);
        IRE_SET_PREV_CHAR_LANG_ID(langIdIndex);

        /* if not ligature range */
        if (!(currentCharacter & 0xE000))
        {
            /* get Indic language array index   */
            IRE_SET_PREV_CHAR_INFO_TABLE_FROM_CHAR_INFO_TABLE(langIdIndex);
        }
        else
        {
            /* get Indic language ligature array index   */
            IRE_SET_PREV_CHAR_INFO_TABLE_FROM_LIGATURE_INFO_TABLE(langIdIndex);
        }
		    /* start range of Indic language ligature or character */
            startRange = indic_lang_table_info.start_range;
            /* end range of Indic language */
        	endRange = indic_lang_table_info.end_range;
            /* get the pointer to the begining of the array of structures */
            char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;

        /*
         * As char might belong to indic range, but our product doesn't support that language
         * In that case, just fill the char as such, it could be in the form of square box.
         * so this check is required
         */
        if (NULL == char_status_flag_p)
        {
            return 0;
        }
        
        IRE_MODIFY_LIGATURE_RELATED_INFORMATION(
        	currentCharacter,
        	char_status_flag_p,
        	startRange,
        	endRange,
        	langIdIndex);
        
        /* get pointer of the character flag which is nothing but pointer to a structure */
        pLangFlag = (char_status_flag_p + ((currentCharacter - startRange) - 1));
        /* store the charater flag information by ORing and shifting bits */
        mchar_status_flag_p = (U32*) pLangFlag;

        mCharStatusFlag = *mchar_status_flag_p;

        switch (mCharStatusFlag & MASK_CHARACTER_ALIGNMENT)
        {
            case RIGHT_ALIGNED_CHARACTER:
                return IRE_RIGHT_ALIGNED_CHARACTER; 

            default :
            	/* To-Do: Remove Ligature type from IRE Flags and use this flag exclusively for alignment*/
                return IRE_NOT_A_LIGATURE;
        }

    }
    return IRE_NOT_A_LIGATURE;
}
#endif
#if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__)


/*****************************************************************************
 * FUNCTION
 *  set_current_language_for_hindi_rules
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_current_language_for_hindi_rules(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;
    U8 temp_str1[30];
    U8 temp_str2[30];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8*) temp_str1, (S8*) gLanguageArray[gCurrLangIndex].aLangSSC);
    for (index = 0; index < (sizeof(HRLangSSC) / sizeof(HRLangSSC[0])); index++)
    {
        mmi_asc_to_ucs2((S8*) temp_str2, (S8*) HRLangSSC[index].ssc_string);
        if (mmi_ucs2cmp((const S8*)temp_str1, (const S8*)temp_str2) == 0)
        {
            indic_rules_current_set_language = HRLangSSC[index].language_enum;
            indic_rules_prefered_set_language = indic_rules_current_set_language;
            return;
        }
    }
    indic_rules_current_set_language = HRLangSSC[0].language_enum;
    indic_rules_prefered_set_language = indic_rules_current_set_language;

}


/*****************************************************************************
 * FUNCTION
 *  overwrite_current_language_for_hindi_rules_based_on_input_method
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL overwrite_current_language_for_hindi_rules_based_on_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    indic_rules_ligature_enum previous_set_language = indic_rules_current_set_language;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_imm_get_curr_input_mode())    
    {
        #if defined (__MMI_MULTITAP_HINDI__)
        case IMM_INPUT_MODE_MULTITAP_HINDI:
        case IMM_INPUT_MODE_SMART_HINDI:
            indic_rules_current_set_language = MMI_HINDI_LANG;
            break;
        #endif /* defined (__MMI_MULTITAP_HINDI__) */ 

        #if defined (__MMI_MULTITAP_MARATHI__)
        case IMM_INPUT_MODE_MULTITAP_MARATHI:
        case IMM_INPUT_MODE_SMART_MARATHI:
            indic_rules_current_set_language = MMI_MARATHI_LANG;
            break;
        #endif /* defined (__MMI_MULTITAP_MARATHI__) */ 
        
        #if defined (__MMI_MULTITAP_BENGALI__)
        case IMM_INPUT_MODE_MULTITAP_BENGALI:
        case IMM_INPUT_MODE_SMART_BENGALI:
            indic_rules_current_set_language = MMI_BENGALI_LANG;
            break;
        #endif /* defined (__MMI_MULTITAP_BENGALI__) */ 

        #if defined (__MMI_MULTITAP_ASSAMESE__)
        case IMM_INPUT_MODE_MULTITAP_ASSAMESE:
            indic_rules_current_set_language = MMI_ASSAMESE_LANG;
            break;
        #endif /* defined (__MMI_MULTITAP_ASSAMESE__) */

        default:
            indic_rules_current_set_language = MMI_ALL_LANG;
    }
    /* 
     * Giving an indication to the users that the current_set_language has
     * changed, if this API returns MMI_TRUE
     *--------------------------------------------------------------------
     * The pluto editor will use this information to reload its cache 
     *--------------------------------------------------------------------
     */
    if (previous_set_language == indic_rules_current_set_language)
    {
        /* If the previous set language has not changed, then return FALSE */
        return MMI_FALSE;
    }
    else
    {
        /* If the previous set language has changed, then return TRUE */
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  restore_current_language_for_hindi_rules
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void restore_current_language_for_hindi_rules(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    indic_rules_current_set_language = indic_rules_prefered_set_language;
}
#endif /* defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__) */ 


/*****************************************************************************
 * FUNCTION
 *  ire_small_con_rendering_correction
 * DESCRIPTION
 *  
 * PARAMETERS
 *  previous_unicode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 ire_small_con_rendering_correction(U16 currentCharacter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 langIdIndex = 0;
    U16 startRange = 0, endRange = 0;
    S32 StrWidth =0;

    ire_indic_languages_table_struct indic_lang_table_info;
    const ire_character_info_table_struct *char_status_flag_p;

    const ire_character_info_table_struct *pLangFlag;

    U32 *mchar_status_flag_p = NULL;
    U32 mCharStatusFlag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G7_IRE, TRC_IRE_SMALL_CON_RENDERING_CORRECTION);

    if (IRE_INDIC_CHARACTER_UCS2_RANGE(currentCharacter))
    {
        /* get language index   */
        IRE_GET_CHARACTER_LANG_ID_FROM_PREV_CHAR(currentCharacter, langIdIndex);
        IRE_SET_PREV_CHAR_LANG_ID(langIdIndex);

        /* if not ligature range */
        if (!(currentCharacter & 0xE000))
        {
            /* get Indic language array index   */
            IRE_SET_PREV_CHAR_INFO_TABLE_FROM_CHAR_INFO_TABLE(langIdIndex);
		}
        else
        {
         	/* get Indic language ligature array index   */
            IRE_SET_PREV_CHAR_INFO_TABLE_FROM_LIGATURE_INFO_TABLE(langIdIndex);
		}
		/* start range of Indic language ligature or character */
        startRange = indic_lang_table_info.start_range;
        /* end range of Indic language */
        endRange = indic_lang_table_info.end_range;
        /* get the pointer to the begining of the array of structures  */
        char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;
		
        /*
         * As char might belong to indic range, but our product doesn't support that language
         * In that case, just fill the char as such, it could be in the form of square box.
         * so this check is required
         */
        if (NULL == char_status_flag_p)
        {
            g_indic_rule_engine_cntx.error_correction_for_rendering = 0;
            return 0;
        }
        
        IRE_MODIFY_LIGATURE_RELATED_INFORMATION(
        	currentCharacter,
        	char_status_flag_p,
        	startRange,
        	endRange,
        	langIdIndex);
        
        /* get pointer of the character flag which is nothing but pointer to a structure */
        pLangFlag = (char_status_flag_p + ((currentCharacter - startRange) - 1));
        /* store the charater flag information by ORing and shifting bits */
        mchar_status_flag_p = (U32*) pLangFlag;

        mCharStatusFlag = *mchar_status_flag_p;
        
        if ((mCharStatusFlag & 0x0000F000) == POST_BASE_POSITION_REQ_CORRECTION)
        {
            Get_CharWidth(currentCharacter, &StrWidth);
            g_indic_rule_engine_cntx.error_correction_for_rendering = (StrWidth>>1) +1 ;
            return 0;
        }
        else if ((mCharStatusFlag & 0x0000F000) == POST_BASE_POSITION_REQ_CORRECTION2)
        {
            Get_CharWidth(currentCharacter, &StrWidth);
            g_indic_rule_engine_cntx.error_correction_for_rendering = StrWidth - 2 ;
            return 0;
        }
    }
    g_indic_rule_engine_cntx.error_correction_for_rendering =0;
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  ire_IsValidInput
 * DESCRIPTION
 *  This API check for the validation of input 
 *  entered by user(for VK),
 *  given by smart methods (like ZI or T9)
 * PARAMETERS
 *  Unicode             [IN]        
 *  strlen              [IN]        
 * RETURNS
 *  MMI_FALSE           [OUT]   if input is not valid
 *  MMI_TRUE            [OUT]   if input is valid
 *****************************************************************************/
U8 ire_IsValidInput(U16 *Unicode, U8 strlen)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 previous_str[3] = {0};
    mmi_imc_message_struct imc_msg;
    UI_character_type string_buf[10] = {0}; ///TODO: define an value for the string length
    UI_buffer_type start_p = NULL, end_p = NULL;
	S32 str_len = 0;
	U8 i=0;
	mmi_imc_state_enum curr_state = mmi_imc_get_state() ; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    imc_msg.message_id = MMI_IMC_MESSAGE_IS_AUTO_CLEAR_HIGHLIGHT_WORD_MODE; 
    
    if (mmi_imc_send_message(&imc_msg))
    {
        if(curr_state==MMI_IMC_STATE_SMART_CANDIDATE) 
	  {
	   imc_msg.message_id = MMI_IMC_MESSAGE_GET_HIGHLIGHT_WORD;
	   imc_msg.param_0=(U32)&start_p;
	   imc_msg.param_1 = (U32)&end_p;
	   str_len = mmi_imc_send_message(&imc_msg);
	   for (i = 0; i < str_len-1; i++)
	   {
	   start_p += 2;
	   }
	   previous_str[0]= (UI_character_type)((*((start_p)+0))|((*((start_p)+1))<<8));
	  }
	  else if(curr_state== MMI_IMC_STATE_MULTITAP)
	  {
	  imc_msg.message_id = MMI_IMC_MESSAGE_GET_STRING_BEFORE_CANDIDATE; 
	  imc_msg.param_0 = 3;
        imc_msg.param_1 = (U32)&string_buf[0];
        
        mmi_imc_send_message(&imc_msg);
		previous_str[0] = string_buf[0];
	previous_str[1] = string_buf[1];
	previous_str[2] = string_buf[2];
	  }
	    
    }   
    else
    {
		 if(curr_state==MMI_IMC_STATE_SMART_CANDIDATE) 
	  {
	   imc_msg.message_id = MMI_IMC_MESSAGE_GET_HIGHLIGHT_WORD;
	   imc_msg.param_0=(U32)&start_p;
	   imc_msg.param_1 = (U32)&end_p;
	   str_len = mmi_imc_send_message(&imc_msg);
	   for (i = 0; i < str_len-1; i++)
	   {
			start_p += 2;
	   }
	   previous_str[0]= (UI_character_type)((*((start_p)+0))|((*((start_p)+1))<<8));
	  }
		 else
		 {
        imc_msg.message_id = MMI_IMC_MESSAGE_GET_STRING_BEFORE_CANDIDATE; 
		imc_msg.param_0 = 3;
        imc_msg.param_1 = (U32)&string_buf[0];
        
        mmi_imc_send_message(&imc_msg);

    previous_str[0] = string_buf[0];
	previous_str[1] = string_buf[1];
	previous_str[2] = string_buf[2];
		 }
	}
    return ire_IsValidInput_int(Unicode, strlen, previous_str);
}


/*****************************************************************************
 * FUNCTION
 *  ire_IsValidInput_int
 * DESCRIPTION
 *  This is an internal API that checks for the validation of input 
 *  entered by user(for VK),
 *  given by smart methods (like ZI or T9)
 * PARAMETERS
 *  candidate           [IN]        
 *  strlen              [IN]        
 *  previous_string     [IN]        
 * RETURNS
 *  MMI_FALSE           [OUT]   if input is not valid
 *  MMI_TRUE            [OUT]   if input is valid
 *****************************************************************************/
U8 ire_IsValidInput_int(UI_string_type candidate, U8 strlen, UI_string_type previous_string)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U32 mCharStatusFlag     = 0;
    U32 mCharStatusFlagPrev = 0;
    U16 previous_char       = previous_string[0];
    U16 previous_char2       = previous_string[1];
    U16 startRange          = 0;
    U8  current_char_type   = 0;
    U8  previous_char_type  = 0;
    U8  previous_char2_type  = 0;
    
    const ire_character_info_table_struct *char_status_flag_p = NULL;   /* pointer to a character info structure */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!(IRE_IS_PREV_CURR_SAME_LANG(previous_char, previous_char2)))
    {
        previous_char2 = 0;
    }
    current_char_type = ire_identify_character_type(candidate[0]);

    if ((!previous_char) || (strlen == 1))
    {
        switch (current_char_type)
        {
            case IRE_CHAR_TYPE_HALANT:
            case IRE_CHAR_TYPE_HALANT1: 
            case IRE_CHAR_TYPE_DEPVOWEL:
            case IRE_CHAR_TYPE_SIGN:
                return MMI_FALSE;

            default:
                break;
        }
    }
    else
    {
        U32 prev_language_specific_attribute = 0;
            
        previous_char_type = ire_identify_character_type(previous_char);
        previous_char2_type = ire_identify_character_type(previous_char2);
        
        switch (current_char_type)
        {
            case IRE_CHAR_TYPE_HALANT:
            case IRE_CHAR_TYPE_HALANT1: /* character type for Tamil Halant */
            case IRE_CHAR_TYPE_DEPVOWEL:
                
                /* if previous and current character does not belong to same language
                 * then it is not a valid input
                 */
                if(!(IRE_IS_PREV_CURR_SAME_LANG(previous_char, candidate[0])))
                {
                    return MMI_FALSE;
                }
                
                switch (previous_char_type)
                {
                	case IRE_CHAR_TYPE_SIGN:
                		
		                /* Since the current and previous characters belongs to the same language, hence,
		                 * using startRange and char_status_flag_p of previous character that is stored 
		                 * in global structure used for maintaining the information about previous character
		                 */
		                startRange = g_indic_rule_engine_cntx.ire_prev_char_lang_id.ire_prev_char_table_info.start_range;
		                char_status_flag_p = g_indic_rule_engine_cntx.ire_prev_char_lang_id.ire_prev_char_table_info.indic_char_info_flag_p;
		                
		                /* identify sign type */
		                IRE_IDENTIFY_CHAR_TYPE_FOR_VALIDITY(previous_char, char_status_flag_p, startRange, mCharStatusFlag);
                		
                        IRE_LANGUAGE_SPECIFIC_ATTRIBUTE(
			                    previous_char,
		                        char_status_flag_p,
		                        startRange,
		                        prev_language_specific_attribute);

		                if (prev_language_specific_attribute & IRE_CONSONANT_SHIFTER)
                        {
                            return MMI_TRUE;
                        }

						/* if the previous char is nukta (CHARACTER_TYPE_3) or a 
						 * sign after which dep. vowel (CHARACTER_TYPE_4) can be written, 
						 * then it is a valid candidate 
						 */

                        if(mCharStatusFlag == CHARACTER_TYPE_3 || 
							(mCharStatusFlag == CHARACTER_TYPE_4 && current_char_type == IRE_CHAR_TYPE_DEPVOWEL))
                        {
							#if defined(__MMI_LANG_MYANMAR__) || defined(__MMI_LANG_LAO__)
                        	return MMI_FALSE;
#else
                        	return MMI_TRUE;
#endif
                        }
                        else
                        {
                        	return MMI_FALSE;
                        }
                        
                    case IRE_CHAR_TYPE_CON:
                    	return MMI_TRUE;

					case IRE_CHAR_TYPE_DEPVOWEL:
						{
							U32 entry_of_vowel_allowed_flag = 0;

							/* Since the current and previous characters belongs to the same language, hence,
							 * using startRange and char_status_flag_p of previous character that is stored 
							 * in global structure used for maintaining the information about previous character
							 */
							startRange = g_indic_rule_engine_cntx.ire_prev_char_lang_id.ire_prev_char_table_info.start_range;
							char_status_flag_p = g_indic_rule_engine_cntx.ire_prev_char_lang_id.ire_prev_char_table_info.indic_char_info_flag_p;
			                
							IRE_CHECK_VOWEL_ENTRY_ATTRIBUTE(
                    			candidate[0],
								char_status_flag_p,
								startRange,
								entry_of_vowel_allowed_flag);

							if (entry_of_vowel_allowed_flag)
							{
#if defined(__MMI_LANG_MYANMAR__) ||defined(__MMI_LANG_LAO__)
								//if(previous_char2_type == IRE_CHAR_TYPE_DEPVOWEL ||previous_char2_type == IRE_CHAR_TYPE_SIGN )
									return MMI_FALSE;
								//else
#else
								return MMI_TRUE;
#endif
							}
							return MMI_FALSE;
						}
                    	
                    default:
                    	return MMI_FALSE;	     
                }
                //break;
            case IRE_CHAR_TYPE_SIGN:
                /* --------------------------------------------LOGIC USED------------------------------------------------- 
                 * If sign is of type 0, then it can come after vowels of any type (0, 1 or 2)
                 * If sign is not of type 0, then it can come after vowel of same type
                 * If sign is nukta, then previous character should also be a consonant of same type for candidate to be valid
                 * The character type for nukta is CHARACTER_TYPE_3
                 * -------------------------------------------------------------------------------------------------------
                 */ 
                /* if previous and current character does not belong to same language
                 * then it is not a valid input
                 */
                if(!(IRE_IS_PREV_CURR_SAME_LANG(previous_char, candidate[0])))
                {
                    return MMI_FALSE;
                }
                /* Since the current and previous characters belongs to the same language, hence,
                 * using startRange and char_status_flag_p of previous character that is stored 
                 * in global structure used for maintaining the information about previous character
                 */
                startRange = g_indic_rule_engine_cntx.ire_prev_char_lang_id.ire_prev_char_table_info.start_range;
                char_status_flag_p = g_indic_rule_engine_cntx.ire_prev_char_lang_id.ire_prev_char_table_info.indic_char_info_flag_p;
                
                /* identify sign type */
                IRE_IDENTIFY_CHAR_TYPE_FOR_VALIDITY(candidate[0], char_status_flag_p, startRange, mCharStatusFlag);
                /* identify prev character type */
                IRE_IDENTIFY_CHAR_TYPE_FOR_VALIDITY(previous_char, char_status_flag_p, startRange, mCharStatusFlagPrev);
            
                
                switch (previous_char_type)
                {
                    case IRE_CHAR_TYPE_CON:
                        /* if the current char is nukta, then it is a valid candidate 
                         * if its previous character is consonant of type 3 
                         */
                        if(mCharStatusFlag == CHARACTER_TYPE_3)
                        {
                            /* if consonant type and sign type is same,then it is a valid candidate. 
                             * For nukta sign, type is IRE_CHAR_TYPE_THREE 
                             */
                            if(mCharStatusFlag == mCharStatusFlagPrev)
                            {
                                return MMI_TRUE;
                            }
                            else
                            {
                                return MMI_FALSE;
                            }
                        }
                        /* if current character is a sign but not a nukta sign */
                        else
                        {
                             return MMI_TRUE;
                        }
                        //break;
                    case IRE_CHAR_TYPE_INDEPVOWEL:
                    case IRE_CHAR_TYPE_DEPVOWEL:
                        /* if sign is of type 0 then it can come after dep vowel or indep vowel of any type(0,1 or 2) */
                        if(mCharStatusFlag == CHARACTER_TYPE_0 || (mCharStatusFlag == CHARACTER_TYPE_4 && current_char_type == IRE_CHAR_TYPE_SIGN))
                        {
                            return MMI_TRUE;
                        }
                        /* if sign type(0,1 or 2) does not matches vowel type(0,1 or 2), then the candidate is not valid */
                        else if (mCharStatusFlag != mCharStatusFlagPrev)
                        {
                            return MMI_FALSE;
                        }
                        break;
                    case IRE_CHAR_TYPE_SIGN:
                        {
                            U32 language_specific_attribute = 0;
                            /*Since you have to check for charcters which forms ligatures with consonant having Nukta  with additional consonant containing Nukta*/
                               #if defined (__MMI_LANG_HINDI__)
                                U32 langIdIndex = 0;    /* to store the value of language Id of input character */
                                  /* get language index   */
                            
                            U32 character_position = ire_identify_char_position(candidate[0]);
                             IRE_GET_CHARACTER_LANG_ID_FROM_PREV_CHAR(previous_char, langIdIndex);
                               IRE_SET_PREV_CHAR_LANG_ID(langIdIndex);
                       if((langIdIndex==IRE_LANGUAGE_ID_HINDI)&&(mCharStatusFlagPrev== CHARACTER_TYPE_3 && character_position !=IRE_BELOW_BASE_POSITION_IGNORE_CORRECTION_ATTRIBUTE))
                        {
                           return MMI_TRUE;
                        }
                               #endif
                            IRE_LANGUAGE_SPECIFIC_ATTRIBUTE(
			                    previous_char,
		                        char_status_flag_p,
		                        startRange,
		                        prev_language_specific_attribute);

                            IRE_LANGUAGE_SPECIFIC_ATTRIBUTE(
								candidate[0],
							    char_status_flag_p,
							    startRange,
							    language_specific_attribute);

		                    if (prev_language_specific_attribute & IRE_CONSONANT_SHIFTER)
                            {
                                if (language_specific_attribute & IRE_CONSONANT_SHIFTER)
                                {
                                    return MMI_FALSE;
                                }
                                else
                                {
                                    return MMI_TRUE;
                                }
                            }

                            if (language_specific_attribute & IRE_SUPPORT_SIGN_SIGN_ENTRY)
                            {
                                #if defined(__MMI_LANG_MYANMAR__) || defined(__MMI_LANG_LAO__)
								return MMI_FALSE;
#else
                                return MMI_TRUE;
#endif
                            }
                            else
                            {
                                return MMI_FALSE;
                            }
                        }
                    default:
                        return MMI_FALSE;
                }/* end of inner switch */
                break;
        }/* end of outer switch */
    }/* end of else */
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  ire_IsvalidInput_from_adaption
 * DESCRIPTION
 *  
 * PARAMETERS
 *  Unicode     [IN]        
 *  strlen      [IN]        
 * RETURNS
 *  U8              [OUT]
 *****************************************************************************/
U8 ire_IsvalidInput_from_adaption(U16 *Unicode, U16 strlen)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 current_char_type = 0;
    U8 previous_char_type = 0;
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(strlen)
    {
        current_char_type = ire_identify_character_type(Unicode[index]);
        switch (current_char_type)
        {
            case IRE_CHAR_TYPE_HALANT:
            case IRE_CHAR_TYPE_HALANT1:
            case IRE_CHAR_TYPE_DEPVOWEL:
            if ((previous_char_type != IRE_CHAR_TYPE_CON))
            {
                return MMI_FALSE;
            }
            break;
            case IRE_CHAR_TYPE_SIGN:
            switch (previous_char_type)
            {
                case IRE_CHAR_TYPE_CON:
                case IRE_CHAR_TYPE_INDEPVOWEL:
                case IRE_CHAR_TYPE_DEPVOWEL:
                break;
                default:
                return MMI_FALSE;
            }
            break;
        }
        previous_char_type = current_char_type;
        index ++;
        strlen --;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ire_reverse_memcmp
 * DESCRIPTION
 *  for comparing the memory for a fixed chuck of memory from two locations 
 *  starting from end to second element ie memory comparison from n th to 2nd
 *  element
 * PARAMETERS
 *  PU16	src_p		[IN]
 *  PU16	des_p		[IN]
 *  U8		count       [IN] 
 * RETURNS
 *  U8		[OUT]
 *			MMI_TRUE			when memory blocks match
 *			MMI_FALSE			otherwise
 *****************************************************************************/
U8 mmi_ire_reverse_memcmp(const U16 *src_p, const U16 *des_p, U8 count)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const U16 *source_p = src_p;
	const U16 *dest_p = des_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	if((source_p == NULL) ||(dest_p == NULL))
	{
		return MMI_FALSE;
	}
    /*if(count == 0)
	{
		return MMI_TRUE;
	}*/

	count--;
	source_p += count;
	dest_p += count;
    while(*source_p == *dest_p)
	{
		if(count == 0)
		{
			return MMI_TRUE;
		}
		source_p--;
		dest_p--;
		count--;
		
	}
	return MMI_FALSE;
}
	#if defined(__MMI_MULTITAP_BANGLA_SPEC__)
void ire_shuffling_editor_buffer_for_bengali_spec(U8* b_text, S32 str_len)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	UI_buffer_type temp_texp_p;
	S32 ijk = 0, ij, ijk_prev = 0;
	U8 uTempVar1, uTempVar2 = 0, uTempVar3 , uTempVar4;
	 /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while(ijk < (str_len - 4))
	{
		ijk_prev =ijk;
		ijk += 2*(ire_check_cluster_for_length(b_text + ijk_prev));
		if(ijk == ijk_prev)
			break;
	}
	uTempVar1 = b_text[str_len - 2];
	uTempVar2 = b_text[str_len - 1];
	uTempVar3 = b_text[str_len - 4];
	uTempVar4 = b_text[str_len - 3];
	ij = str_len;
	while(ijk_prev < ij)
	{
		b_text[ij - 1] = b_text[ij - 5];
		ij--;
	}
	b_text[ijk_prev] = uTempVar3;
	b_text[ijk_prev+1] = uTempVar4;
	b_text[ijk_prev+2] = uTempVar1;
	b_text[ijk_prev+3] = uTempVar2;
}
void ire_reshuffling_editor_buffer_for_bengali_spec(U8* b_text, S32 str_len)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ijk = 0, ij, ijk_prev = 0;
	U8 uTempVar1, uTempVar2 = 0, uTempVar3 , uTempVar4;
	 /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while(ijk < (str_len - 4))
	{
		ijk_prev =ijk;
		ijk += 2*(ire_check_cluster_for_length(b_text + ijk_prev));
		if(ijk == ijk_prev)
			break;
	}
	uTempVar1 = b_text[ijk_prev];
	uTempVar2 = b_text[ijk_prev +1];
	uTempVar3 = b_text[ijk_prev +2];
	uTempVar4 = b_text[ijk_prev +3];
	ij = ijk_prev;
	while(ij < str_len)
	{
		b_text[ij] = b_text[ij+ 4];
		ij++;
	}
	b_text[str_len -2] = uTempVar3;
	b_text[str_len -1] = uTempVar4;
	b_text[str_len -3] = uTempVar1;
	b_text[str_len-4] = uTempVar2;
}
#endif
#if defined(__MMI_LANG_KANNADA__)
/*****************************************************************************
 * FUNCTION
 *  ire_adjust_after_language_rules_for_kannada
 * DESCRIPTION
 *  Some times after the language rules have been applied , 
 *	we need to adjuct/reorder some of the	character. For this we will call a 
 *	function corresponding to a specific language to adjust/reorder the 
 *	characters, according to the requirement. For kannada language this API is 
 *  used for handling the display for special(two part) post base matras
 * PARAMETERS
 *	U16*            [IN/OUT]
 *  S32             [IN]        
 * RETURNS
 * 	void 
 *****************************************************************************/
void ire_adjust_after_language_rules_for_kannada(U16 *glyphoutput, S32 nentry_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 mCharStatusFlag = 0;
    U32 mCharStatusFlagNext = 0;
    U32 langIdIndex = IRE_LANGUAGE_ID_KANNADA;            									/* to store the value of language Id of input character */
    S32 i =0;
    S32 j =0;
    U16 startRange = 0;     											
    PU16 glyphoutput_buffer_p = NULL;
    const ire_character_info_table_struct *char_status_flag_p = NULL;
    ire_indic_languages_table_struct indic_lang_table_info; 			/* store the Indic language table entry,(i.e structure info) */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* If we enter a special postbase matra, then the reordering of
     * the display buffer is handeled in the following code
     */
    if(nentry_buffer > 2)
    {
        glyphoutput_buffer_p = glyphoutput;
        glyphoutput = glyphoutput - nentry_buffer;

        IRE_IDENTIFY_LANGUAGE_START_RANGE(*(glyphoutput + 1));
        IRE_IDENTIFY_CHARACTER_POSITION(*(glyphoutput + 1), char_status_flag_p, startRange, mCharStatusFlag);

        IRE_IDENTIFY_LANGUAGE_START_RANGE(*(glyphoutput + 2));
        IRE_IDENTIFY_CHARACTER_POSITION(*(glyphoutput + 2), char_status_flag_p, startRange, mCharStatusFlagNext);

        /* if the character at glyphoutput[1] is a special postbas matra */
        if(!(mCharStatusFlag ^ SPECIAL_POST_BASE_POSITION))
        {
            IRE_IDENTIFY_LANGUAGE_START_RANGE(*(glyphoutput + 2));
            IRE_IDENTIFY_CHARACTER(*(glyphoutput + 2 ), char_status_flag_p, startRange, mCharStatusFlagNext);

            /* if the character at glyphoutput[2] is NOT a normal sign */
            if(mCharStatusFlagNext ^ NORMALSIGN) 
            {
                IRE_IDENTIFY_LANGUAGE_START_RANGE(*(glyphoutput + nentry_buffer - 1));
                IRE_IDENTIFY_CHARACTER(*(glyphoutput + nentry_buffer - 1 ), char_status_flag_p, startRange, mCharStatusFlag);

                /* if last element in the glyphoutput buffer is KANNADA_L_RA_HALANT_CON */
                if( *(glyphoutput + nentry_buffer - 1) == KANNADA_L_RA_HALANT_CON )
                {
                    /* reorder till last but one */
                    IRE_REORDER_KANNADA_POST_BASE_MATRA_AFTER_RULES(1, nentry_buffer - 1, i, j);
                }
                /* if last element in the glyphoutput buffer is normal sign */
                else if(!(mCharStatusFlag ^ NORMALSIGN))
                {
                    /* if second last element in the glyphoutput buffer is normal sign */
                    if( *(glyphoutput + nentry_buffer - 2) == KANNADA_L_RA_HALANT_CON )
                    {
                        /* reorder till last but two */
                        IRE_REORDER_KANNADA_POST_BASE_MATRA_AFTER_RULES(1, nentry_buffer - 2, i, j);
                    }
                    else
                    {
                        /* reorder till last but one */
                        IRE_REORDER_KANNADA_POST_BASE_MATRA_AFTER_RULES(1, nentry_buffer - 1, i, j);
                    }
                }
                else
                {
                    /* reorder till last */
                    IRE_REORDER_KANNADA_POST_BASE_MATRA_AFTER_RULES(1, nentry_buffer, i, j);
                }
            }
        }
        else if( (!(mCharStatusFlagNext ^ SPECIAL_POST_BASE_POSITION)) && 
                 (nentry_buffer > 3) )
        {
            IRE_IDENTIFY_LANGUAGE_START_RANGE(*(glyphoutput + 1));
            IRE_IDENTIFY_CHARACTER(*(glyphoutput + 1 ), char_status_flag_p, startRange, mCharStatusFlag);

            if(!(mCharStatusFlag ^ POST_BASE_DEPVOWEL))
            {
                IRE_IDENTIFY_LANGUAGE_START_RANGE(*(glyphoutput + 3));
                IRE_IDENTIFY_CHARACTER(*(glyphoutput + 3 ), char_status_flag_p, startRange, mCharStatusFlagNext);

                /* if the character at glyphoutput[2] is NOT a normal sign */
                if(mCharStatusFlagNext ^ NORMALSIGN) 
                {
                    IRE_IDENTIFY_LANGUAGE_START_RANGE(*(glyphoutput + nentry_buffer - 1));
                    IRE_IDENTIFY_CHARACTER(*(glyphoutput + nentry_buffer - 1 ), char_status_flag_p, startRange, mCharStatusFlag);

                    /* if last element in the glyphoutput buffer is KANNADA_L_RA_HALANT_CON */
                    if( *(glyphoutput + nentry_buffer - 1) == KANNADA_L_RA_HALANT_CON )
                    {
                        /* reorder till last but one */
                        IRE_REORDER_KANNADA_POST_BASE_MATRA_AFTER_RULES(2, nentry_buffer - 1, i, j);
                    }
                    /* if last element in the glyphoutput buffer is normal sign */
                    else if(!(mCharStatusFlag ^ NORMALSIGN))
                    {
                        /* if second last element in the glyphoutput buffer is normal sign */
                        if( *(glyphoutput + nentry_buffer - 2) == KANNADA_L_RA_HALANT_CON )
                        {
                            /* reorder till last but two */
                            IRE_REORDER_KANNADA_POST_BASE_MATRA_AFTER_RULES(2, nentry_buffer - 2, i, j);
                        }
                        else
                        {
                            /* reorder till last but one */
                            IRE_REORDER_KANNADA_POST_BASE_MATRA_AFTER_RULES(2, nentry_buffer - 1, i, j);
                        }
                    }
                    else
                    {
                        /* reorder till last */
                        IRE_REORDER_KANNADA_POST_BASE_MATRA_AFTER_RULES(2, nentry_buffer, i, j);
                    }   
                }
            }
        }
        glyphoutput = glyphoutput_buffer_p;
    }
}
#endif /* defined(__MMI_LANG_KANNADA__) */


#if defined(__MMI_LANG_MALAYALAM__)
/*****************************************************************************
 * FUNCTION
 *  ire_adjust_after_language_rules_for_malayalam
 * DESCRIPTION
 *  Some times after the language rules have been applied , 
 *	we need to adjuct/reorder some of the	character. For this we will call a 
 *	function corresponding to a specific language to adjust/reorder the 
 *	characters, according to the requirement. For malayalam language this API is used
 * PARAMETERS
 *	U16*            [IN/OUT]
 *  S32             [IN]        
 * RETURNS
 * 	void 
 *****************************************************************************/
void ire_adjust_after_language_rules_for_malayalam(U16 *glyphoutput_buffer, S32 nentry_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count  = 0;
    S32 nentry = nentry_buffer;
    U16 temp_var;
    U16 *temp_glyphoutput_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_glyphoutput_buffer = glyphoutput_buffer;
    /* pointer pointing to the secong element in the glyphoutput buffer 
     * as the first element can never be MALAYALAM_L_RAKAR */
    glyphoutput_buffer = glyphoutput_buffer - (nentry - 1); 
    
    while(count < (nentry - 1))
    {
        if(*glyphoutput_buffer == MALAYALAM_L_RAKAR)
        {
            temp_var                   = *glyphoutput_buffer;
            *glyphoutput_buffer        = *(glyphoutput_buffer - 1);
            *(glyphoutput_buffer - 1)  = temp_var;
        }
        glyphoutput_buffer++;
        count++;
    }
    glyphoutput_buffer = temp_glyphoutput_buffer;
}
#endif /* defined(__MMI_LANG_MALAYALAM__) */


#if defined(__MMI_LANG_MYANMAR__)
/*****************************************************************************
 * FUNCTION
 *  ire_adjust_after_language_rules_for_khmer
 * DESCRIPTION
 *  If the combination consonant shifter + Vowel is encountered, then they 
 * 	should be interchanged
 * PARAMETERS
 *	U16*            [IN/OUT]
 *  S32             [IN]        
 * RETURNS
 * 	void 
 *****************************************************************************/
static void ire_adjust_after_language_rules_for_myanmar(U16 *glyphoutput, S32 nentry_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 mCharStatusFlag = 0;
    U32 mCharStatusFlagNext = 0;
    U32 langIdIndex = IRE_LANGUAGE_ID_MYANMAR;            				/* to store the value of language Id of input character */
    S32 count  = 0;
    S32 nentry = nentry_buffer;
    U16 temp_var;
    U16 *temp_glyphoutput_buffer;
    U16 startRange = 0;     											
    const ire_character_info_table_struct *char_status_flag_p = NULL;
    ire_indic_languages_table_struct indic_lang_table_info; 			/* store the Indic language table entry,(i.e structure info) */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if(nentry >= 2)
    {
        temp_glyphoutput_buffer = glyphoutput;
        
		/* pointer pointing to the first element in the glyphoutput buffer  */
        glyphoutput = glyphoutput - nentry; 
        
        while(count < nentry - 1)
        {
            IRE_IDENTIFY_LANGUAGE_START_RANGE(*(glyphoutput + 1));
            IRE_IDENTIFY_CHARACTER(*(glyphoutput + 1 ), char_status_flag_p, startRange, mCharStatusFlagNext);
			
			if (*glyphoutput == MYNAMMAR_LIG_186)
            {
				if  ((!(mCharStatusFlagNext ^ NORMAL_CON))    ||
					 (!(mCharStatusFlagNext ^ SMALL_CON)) )
                {
					temp_var            = *glyphoutput;
                    *glyphoutput        = *(glyphoutput + 1);
                    *(glyphoutput + 1)  = temp_var;
				}
			}
			glyphoutput++;
            count++;	
        }

        glyphoutput = temp_glyphoutput_buffer;
    }
}
#endif /* defined(__MMI_LANG_MYANMAR__) */


#if defined (__MMI_LANG_KHMER__)

/*****************************************************************************
 * FUNCTION
 *  ire_adjust_after_language_rules_for_khmer
 * DESCRIPTION
 *  If the combination consonant shifter + Vowel is encountered, then they 
 * 	should be interchanged
 * PARAMETERS
 *	U16*            [IN/OUT]
 *  S32             [IN]        
 * RETURNS
 * 	void 
 *****************************************************************************/
static void ire_adjust_after_language_rules_for_khmer_before_rules(U16 *cluster, S32 nentry_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 mCharStatusFlagNext = 0;
    U32 langIdIndex = IRE_LANGUAGE_ID_KHMER;            				/* to store the value of language Id of input character */
    S32 count  = 1;
    S32 nentry = nentry_buffer;
    U16 temp_var;
    U16 *temp_cluster_buffer;
    U16 startRange = 0;     											
    const ire_character_info_table_struct *char_status_flag_p = NULL;
    ire_indic_languages_table_struct indic_lang_table_info; 			/* store the Indic language table entry,(i.e structure info) */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if(nentry > 2)
    {
        temp_cluster_buffer = cluster;
        
		while(count < nentry)
        {
        	U32 language_specific_attribute = 0;
            
            IRE_IDENTIFY_LANGUAGE_START_RANGE(*(cluster));           	
        	IRE_LANGUAGE_SPECIFIC_ATTRIBUTE(
				*cluster,
			    char_status_flag_p,
			    startRange,
			    language_specific_attribute);
			    
			if (language_specific_attribute & IRE_CONSONANT_SHIFTER)
			{
				IRE_IDENTIFY_LANGUAGE_START_RANGE(*(cluster + 1));
				IRE_IDENTIFY_CHARACTER(*(cluster + 1 ), char_status_flag_p, startRange, mCharStatusFlagNext);
				
				/* Interchanging the consonant shifter and
				 * vowel
				 */
				if (!(mCharStatusFlagNext ^ POST_BASE_DEPVOWEL))
				{
					temp_var            = *cluster;
                    *cluster        = *(cluster + 1);
                    *(cluster + 1)  = temp_var;
				}
			}
			cluster++;
            count++;	
        }
        cluster = temp_cluster_buffer;
	}
}

/*****************************************************************************
 * FUNCTION
 *  ire_adjust_after_language_rules_for_khmer
 * DESCRIPTION
 *  
 * PARAMETERS
 *	U16*            [IN/OUT]
 *  S32             [IN]        
 * RETURNS
 * 	void 
 *****************************************************************************/
static void ire_adjust_after_language_rules_for_khmer(U16 *glyphoutput, S32 nentry_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 mCharStatusFlag = 0;
    U32 langIdIndex = IRE_LANGUAGE_ID_KHMER;            				/* to store the value of language Id of input character */
    S32 count  = 1;
    S32 nentry = nentry_buffer;
    U16 temp_var;
    U16 *temp_glyphoutput_buffer, *start_glyphoutput;
    U16 startRange = 0;     											
    const ire_character_info_table_struct *char_status_flag_p = NULL;
    ire_indic_languages_table_struct indic_lang_table_info; 			/* store the Indic language table entry,(i.e structure info) */
	int index = 0;
	MMI_BOOL found = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if(nentry > 1)
    {
        temp_glyphoutput_buffer = glyphoutput;
        
		/* pointer pointing to the first element in the glyphoutput buffer  */
        start_glyphoutput = glyphoutput - nentry;
		glyphoutput = glyphoutput - nentry;
        
        while(count <= nentry)
        {
        	IRE_IDENTIFY_LANGUAGE_START_RANGE(*(glyphoutput));
            IRE_IDENTIFY_CHARACTER(*(glyphoutput), char_status_flag_p, startRange, mCharStatusFlag);

		    /* If it is not a dep vowel */
            if ((mCharStatusFlag != POST_BASE_DEPVOWEL) &&
				(mCharStatusFlag != PRE_BASE_DEPVOWEL) && 
				(!found))
			{
				index = nentry_buffer - (temp_glyphoutput_buffer - glyphoutput);
				found = MMI_TRUE;
			}

			if ((*glyphoutput == KHMER_LIGRATURE_98) && found)
			{
				U16 temp_char = *glyphoutput;
				U16 number = temp_glyphoutput_buffer - glyphoutput;
				U16 i = 0;

				
				for (i = count - 1; i > index; i--)
				{
					start_glyphoutput[i] = start_glyphoutput[i-1];
				}
				start_glyphoutput[index] = temp_char;
				break;

			}

			glyphoutput++;
            count++;	
        }
       glyphoutput = temp_glyphoutput_buffer;
	}
}

#endif /* defined(__MMI_LANG_KHMER__) */


#if defined(__MMI_LANG_TELUGU__)
/*****************************************************************************
 * FUNCTION
 *  ire_adjust_after_language_rules_for_telugu
 * DESCRIPTION
 *  Some times after the language rules have been applied , 
 *	we need to adjuct/reorder some of the	character. For this we will call a 
 *	function corresponding to a specific language to adjust/reorder the 
 *	characters, according to the requirement. For telugu language this API is 
 *  used for handling the display in the situation in which glyphoutput contains
 *  SMALL_CON + DV + NORMAL_CON + ......
 *  This API will reorder and show the combination as 
 *  SMALL_CON + NORMAL_CON + DV + ......
 * PARAMETERS
 *	U16*            [IN/OUT]
 *  S32             [IN]        
 * RETURNS
 * 	void 
 *****************************************************************************/
void ire_adjust_after_language_rules_for_telugu(U16 *glyphoutput, S32 nentry_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 mCharStatusFlag = 0;
    U32 mCharStatusFlagNext = 0;
    U32 langIdIndex = IRE_LANGUAGE_ID_TELUGU;            				/* to store the value of language Id of input character */
    S32 count  = 0;
    S32 nentry = nentry_buffer;
    U16 temp_var;
    U16 *temp_glyphoutput_buffer;
    U16 startRange = 0;     											
    const ire_character_info_table_struct *char_status_flag_p = NULL;
    ire_indic_languages_table_struct indic_lang_table_info; 			/* store the Indic language table entry,(i.e structure info) */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if(nentry > 2)
    {
        temp_glyphoutput_buffer = glyphoutput;
        /* pointer pointing to the secong element in the glyphoutput buffer 
         * as the first element can never be PostBaseDependent vowel  */
        glyphoutput = glyphoutput - (nentry - 1); 
        
        while(count < (nentry - 2))
        {
            IRE_IDENTIFY_LANGUAGE_START_RANGE(*(glyphoutput));
            IRE_IDENTIFY_CHARACTER(*(glyphoutput), char_status_flag_p, startRange, mCharStatusFlag);

            IRE_IDENTIFY_LANGUAGE_START_RANGE(*(glyphoutput + 1));
            IRE_IDENTIFY_CHARACTER(*(glyphoutput + 1 ), char_status_flag_p, startRange, mCharStatusFlagNext);

            if((!(mCharStatusFlag ^ POST_BASE_DEPVOWEL)) &&
               (!(mCharStatusFlagNext ^ NORMAL_CON)) )
            {
                IRE_IDENTIFY_CHARACTER_POSITION(*(glyphoutput), char_status_flag_p, startRange, mCharStatusFlag);
                if (!(mCharStatusFlag ^ IRE_POSTBASE_POSITION))
                {
                    temp_var            = *glyphoutput;
                    *glyphoutput        = *(glyphoutput + 1);
                    *(glyphoutput + 1)  = temp_var;
                }
            }
            glyphoutput++;
            count++;
        }

        glyphoutput = temp_glyphoutput_buffer;
    }
}
#endif /* defined(__MMI_LANG_TELUGU__) */


#else /* defined(__MMI_INDIC_ALG__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_ire_warning_remove
 * DESCRIPTION
 *  for removing warnings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ire_warning_remove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* dummy function */
}

#endif /* defined (__MMI_INDIC_ALG__) */ 


