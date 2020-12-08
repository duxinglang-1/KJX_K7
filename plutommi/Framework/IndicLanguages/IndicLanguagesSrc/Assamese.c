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
 *   Assamese.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   C file of Assamese font rule 
 *
 * Author:
 *   Sandeep Singh Spall (MTI00136)
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#if defined (__MMI_LANG_ASSAMESE__)

#include "IndicEngineGprot.h"

#ifndef NULL
#define NULL   0
#endif 


#if defined (__MMI_MULTITAP_ASSAMESE__)
const UI_character_type default_assamese_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', ASSAMESE_DEVANAGARI_S_DANDA, ASSAMESE_DEVANAGARI_S_DDANDA, ASSAMESE_D_ZERO, '0', '\0'},  /* key 0 */
    {ASSAMESE_C_KA, ASSAMESE_C_KHA, ASSAMESE_C_GA, ASSAMESE_C_GHA, ASSAMESE_C_NGA, ASSAMESE_D_ONE, '1', '\0'},        /* key 1 */
    {ASSAMESE_C_CA, ASSAMESE_C_CHA, ASSAMESE_C_JA, ASSAMESE_C_JHA, ASSAMESE_C_NYA, ASSAMESE_D_TWO, '2', '\0'},        /* key 2 */
    {ASSAMESE_C_TTA, ASSAMESE_C_TTHA, ASSAMESE_C_DDA, ASSAMESE_C_DDHA, ASSAMESE_C_NNA, ASSAMESE_D_THREE, '3', '\0'},  /* key 3 */
    {ASSAMESE_C_TA, ASSAMESE_C_THA, ASSAMESE_C_DA, ASSAMESE_C_DHA, ASSAMESE_C_NA, ASSAMESE_D_FOUR, '4', '\0'},        /* key 4 */
    {ASSAMESE_C_PA, ASSAMESE_C_PHA, ASSAMESE_C_BA, ASSAMESE_C_BHA, ASSAMESE_C_MA, ASSAMESE_D_FIVE, '5', '\0'},        /* key 5 */
    {ASSAMESE_C_YA, ASSAMESE_C_MRA, ASSAMESE_C_LA, ASSAMESE_C_LRA, ASSAMESE_D_SIX, '6', '\0'},       /* key 6 */
    {ASSAMESE_C_SHA, ASSAMESE_C_SSA, ASSAMESE_C_SA, ASSAMESE_C_HA, ASSAMESE_C_RRA, ASSAMESE_C_RHA, ASSAMESE_C_YYA, ASSAMESE_AD_TA, ASSAMESE_D_SEVEN, '7', '\0'}, /* key 7 */
    {ASSAMESE_IV_A, ASSAMESE_IV_AA, ASSAMESE_IV_I, ASSAMESE_IV_II, ASSAMESE_IV_U, ASSAMESE_IV_UU, ASSAMESE_IV_VR, ASSAMESE_IV_VL, ASSAMESE_IV_E, ASSAMESE_IV_AI, ASSAMESE_IV_O, ASSAMESE_IV_AU, ASSAMESE_D_EIGHT, '8', '\0'},        /* key 8 */
    {ASSAMESE_D_NINE, '9', '\0'},                        /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_assamesematra_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', ASSAMESE_S_HALANT, ASSAMESE_S_CHANDRA_BINDU, ASSAMESE_S_ANUSVARA, ASSAMESE_S_VISARGA, ASSAMESE_S_AVAGRAH, ASSAMESE_DEVANAGARI_S_DANDA, ASSAMESE_DEVANAGARI_S_DDANDA, ASSAMESE_D_ZERO, '0', '\0'},     /* key 0 */
    {ASSAMESE_C_KA, ASSAMESE_C_KHA, ASSAMESE_C_GA, ASSAMESE_C_GHA, ASSAMESE_C_NGA, ASSAMESE_D_ONE, '1', '\0'},        /* key 1 */
    {ASSAMESE_C_CA, ASSAMESE_C_CHA, ASSAMESE_C_JA, ASSAMESE_C_JHA, ASSAMESE_C_NYA, ASSAMESE_D_TWO, '2', '\0'},        /* key 2 */
    {ASSAMESE_C_TTA, ASSAMESE_C_TTHA, ASSAMESE_C_DDA, ASSAMESE_C_DDHA, ASSAMESE_C_NNA, ASSAMESE_D_THREE, '3', '\0'},  /* key 3 */
    {ASSAMESE_C_TA, ASSAMESE_C_THA, ASSAMESE_C_DA, ASSAMESE_C_DHA, ASSAMESE_C_NA, ASSAMESE_D_FOUR, '4', '\0'},        /* key 4 */
    {ASSAMESE_C_PA, ASSAMESE_C_PHA, ASSAMESE_C_BA, ASSAMESE_C_BHA, ASSAMESE_C_MA, ASSAMESE_D_FIVE, '5', '\0'},        /* key 5 */
    {ASSAMESE_C_YA, ASSAMESE_C_MRA, ASSAMESE_C_LA, ASSAMESE_C_LRA, ASSAMESE_D_SIX, '6', '\0'},       /* key 6 */
    {ASSAMESE_C_SHA, ASSAMESE_C_SSA, ASSAMESE_C_SA, ASSAMESE_C_HA, ASSAMESE_C_RRA, ASSAMESE_C_RHA, ASSAMESE_C_YYA, ASSAMESE_AD_TA, ASSAMESE_D_SEVEN, '7', '\0'}, /* key 7 */
    {ASSAMESE_IV_A, ASSAMESE_IV_AA, ASSAMESE_IV_I, ASSAMESE_IV_II, ASSAMESE_IV_U, ASSAMESE_IV_UU, ASSAMESE_IV_VR, ASSAMESE_IV_VL, ASSAMESE_IV_E, ASSAMESE_IV_AI, ASSAMESE_IV_O, ASSAMESE_IV_AU, ASSAMESE_D_EIGHT, '8', '\0'},        /* key 8 */
    {ASSAMESE_DV_AA, ASSAMESE_DV_I, ASSAMESE_DV_II, ASSAMESE_DV_U, ASSAMESE_DV_UU, ASSAMESE_DV_VR, ASSAMESE_DV_E, ASSAMESE_DV_AI, ASSAMESE_DV_O, ASSAMESE_DV_AU, ASSAMESE_D_NINE, '9', '\0'},      /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_assamesematra1_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', ASSAMESE_S_CHANDRA_BINDU, ASSAMESE_S_ANUSVARA, ASSAMESE_S_VISARGA, ASSAMESE_S_AVAGRAH, ASSAMESE_DEVANAGARI_S_DANDA, ASSAMESE_DEVANAGARI_S_DDANDA, ASSAMESE_D_ZERO, '0', '\0'},       /* key 0 */
    {ASSAMESE_C_KA, ASSAMESE_C_KHA, ASSAMESE_C_GA, ASSAMESE_C_GHA, ASSAMESE_C_NGA, ASSAMESE_D_ONE, '1', '\0'},        /* key 1 */
    {ASSAMESE_C_CA, ASSAMESE_C_CHA, ASSAMESE_C_JA, ASSAMESE_C_JHA, ASSAMESE_C_NYA, ASSAMESE_D_TWO, '2', '\0'},        /* key 2 */
    {ASSAMESE_C_TTA, ASSAMESE_C_TTHA, ASSAMESE_C_DDA, ASSAMESE_C_DDHA, ASSAMESE_C_NNA, ASSAMESE_D_THREE, '3', '\0'},  /* key 3 */
    {ASSAMESE_C_TA, ASSAMESE_C_THA, ASSAMESE_C_DA, ASSAMESE_C_DHA, ASSAMESE_C_NA, ASSAMESE_D_FOUR, '4', '\0'},        /* key 4 */
    {ASSAMESE_C_PA, ASSAMESE_C_PHA, ASSAMESE_C_BA, ASSAMESE_C_BHA, ASSAMESE_C_MA, ASSAMESE_D_FIVE, '5', '\0'},        /* key 5 */
    {ASSAMESE_C_YA, ASSAMESE_C_MRA, ASSAMESE_C_LA, ASSAMESE_C_LRA, ASSAMESE_D_SIX, '6', '\0'},       /* key 6 */
    {ASSAMESE_C_SHA, ASSAMESE_C_SSA, ASSAMESE_C_SA, ASSAMESE_C_HA, ASSAMESE_C_RRA, ASSAMESE_C_RHA, ASSAMESE_C_YYA, ASSAMESE_AD_TA, ASSAMESE_D_SEVEN, '7', '\0'}, /* key 7 */
    {ASSAMESE_IV_A, ASSAMESE_IV_AA, ASSAMESE_IV_I, ASSAMESE_IV_II, ASSAMESE_IV_U, ASSAMESE_IV_UU, ASSAMESE_IV_VR, ASSAMESE_IV_VL, ASSAMESE_IV_E, ASSAMESE_IV_AI, ASSAMESE_IV_O, ASSAMESE_IV_AU, ASSAMESE_D_EIGHT, '8', '\0'},        /* key 8 */
    {ASSAMESE_D_NINE, '9', '\0'},    /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
const UI_character_type default_assamesematra2_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', ASSAMESE_S_ANUSVARA, ASSAMESE_S_VISARGA, ASSAMESE_S_AVAGRAH, ASSAMESE_DEVANAGARI_S_DANDA, ASSAMESE_DEVANAGARI_S_DDANDA, ASSAMESE_D_ZERO, '0', '\0'},       /* key 0 */
    {ASSAMESE_C_KA, ASSAMESE_C_KHA, ASSAMESE_C_GA, ASSAMESE_C_GHA, ASSAMESE_C_NGA, ASSAMESE_D_ONE, '1', '\0'},        /* key 1 */
    {ASSAMESE_C_CA, ASSAMESE_C_CHA, ASSAMESE_C_JA, ASSAMESE_C_JHA, ASSAMESE_C_NYA, ASSAMESE_D_TWO, '2', '\0'},        /* key 2 */
    {ASSAMESE_C_TTA, ASSAMESE_C_TTHA, ASSAMESE_C_DDA, ASSAMESE_C_DDHA, ASSAMESE_C_NNA, ASSAMESE_D_THREE, '3', '\0'},  /* key 3 */
    {ASSAMESE_C_TA, ASSAMESE_C_THA, ASSAMESE_C_DA, ASSAMESE_C_DHA, ASSAMESE_C_NA, ASSAMESE_D_FOUR, '4', '\0'},        /* key 4 */
    {ASSAMESE_C_PA, ASSAMESE_C_PHA, ASSAMESE_C_BA, ASSAMESE_C_BHA, ASSAMESE_C_MA, ASSAMESE_D_FIVE, '5', '\0'},        /* key 5 */
    {ASSAMESE_C_YA, ASSAMESE_C_MRA, ASSAMESE_C_LA, ASSAMESE_C_LRA, ASSAMESE_D_SIX, '6', '\0'},       /* key 6 */
    {ASSAMESE_C_SHA, ASSAMESE_C_SSA, ASSAMESE_C_SA, ASSAMESE_C_HA, ASSAMESE_C_RRA, ASSAMESE_C_RHA, ASSAMESE_C_YYA, ASSAMESE_AD_TA, ASSAMESE_D_SEVEN, '7', '\0'}, /* key 7 */
    {ASSAMESE_IV_A, ASSAMESE_IV_AA, ASSAMESE_IV_I, ASSAMESE_IV_II, ASSAMESE_IV_U, ASSAMESE_IV_UU, ASSAMESE_IV_VR, ASSAMESE_IV_VL, ASSAMESE_IV_E, ASSAMESE_IV_AI, ASSAMESE_IV_O, ASSAMESE_IV_AU, ASSAMESE_D_EIGHT, '8', '\0'},        /* key 8 */
    {ASSAMESE_D_NINE, '9', '\0'},    /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined (__MMI_MULTITAP_ASSAMESE__) */ 

#if defined(__MMI_MULTITAP_ASSAMESE__)


/*****************************************************************************
 * FUNCTION
 *  get_assamese_multitap_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  i(?)        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
/* MTI IRE OPTIMIZATION START */
UI_string_type get_assamese_multitap_string(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type previous_char;
    mmi_imc_message_struct imc_msg;
    UI_character_type string_buf[10] = {0}; /* /TODO: define an value for the string length */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/* get previous character but skip highlight and multitap. */
    imc_msg.message_id = MMI_IMC_MESSAGE_GET_STRING_BEFORE_CANDIDATE;
    imc_msg.param_0 = 1;
    imc_msg.param_1 = (U32)string_buf;
	
    mmi_imc_send_message(&imc_msg);
	
    previous_char = string_buf[0];
    if (previous_char)
    {
        if ((previous_char >= ASSAMESE_C_KA && previous_char <= ASSAMESE_C_HA) ||
            (previous_char >= ASSAMESE_C_RRA && previous_char <= ASSAMESE_C_YYA) ||
            (previous_char >= ASSAMESE_C_MRA && previous_char <= ASSAMESE_C_LRA))
        {
            return (UI_character_type*) default_assamesematra_multitap_strings[index];
        }
        else
        {
            switch (previous_char)
            {
                case (ASSAMESE_IV_A):
                case (ASSAMESE_IV_AA):
                case (ASSAMESE_IV_VR):
                case (ASSAMESE_IV_VL):
                case (ASSAMESE_IV_E):
                case (ASSAMESE_IV_O):
                case (ASSAMESE_DV_AA):
                case (ASSAMESE_DV_I):
                case (ASSAMESE_DV_II):
                case (ASSAMESE_DV_U):
                case (ASSAMESE_DV_UU):
                case (ASSAMESE_DV_VR):
                case (ASSAMESE_DV_VRR):
                case (ASSAMESE_DV_E):
                case (ASSAMESE_DV_AI):
                case (ASSAMESE_DV_O):
                case (ASSAMESE_DV_AU):
                {
                    return (UI_character_type*) default_assamesematra1_multitap_strings[index];

                }
                case (ASSAMESE_IV_I):
                case (ASSAMESE_IV_II):
                case (ASSAMESE_IV_U):
                case (ASSAMESE_IV_UU):
                case (ASSAMESE_IV_AI):
                case (ASSAMESE_IV_AU):		
                {
                    return (UI_character_type*) default_assamesematra2_multitap_strings[index];

                }                
                default:
                    return (UI_character_type*) default_assamese_multitap_strings[index];

            }
        }
    }
    else
    {
        return (UI_character_type*) default_assamese_multitap_strings[index];
    }

}

/* MTI IRE OPTIMIZATION END */
/*****************************************************************************
 * FUNCTION
 *  get_assamese_single_line_multitap_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  i       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
UI_character_type *get_assamese_single_line_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type previous_char;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    previous_char = gui_single_line_current_character(&MMI_singleline_inputbox);
    if (previous_char)
    {
        if ((previous_char >= ASSAMESE_C_KA && previous_char <= ASSAMESE_C_HA) ||
            (previous_char >= ASSAMESE_C_RRA && previous_char <= ASSAMESE_C_YYA) ||
            (previous_char >= ASSAMESE_C_MRA && previous_char <= ASSAMESE_C_LRA))
        {
            return ((UI_character_type*) default_assamesematra_multitap_strings[i]);
        }
        else
        {
            switch (previous_char)
            {
                case (ASSAMESE_IV_A):
                case (ASSAMESE_IV_AA):
                case (ASSAMESE_IV_VR):
                case (ASSAMESE_IV_VL):
                case (ASSAMESE_IV_E):
                case (ASSAMESE_IV_O):
                case (ASSAMESE_DV_AA):
                case (ASSAMESE_DV_I):
                case (ASSAMESE_DV_II):
                case (ASSAMESE_DV_U):
                case (ASSAMESE_DV_UU):
                case (ASSAMESE_DV_VR):
                case (ASSAMESE_DV_VRR):
                case (ASSAMESE_DV_E):
                case (ASSAMESE_DV_AI):
                case (ASSAMESE_DV_O):
                case (ASSAMESE_DV_AU):
                {
                    return ((UI_character_type*) default_assamesematra1_multitap_strings[i]);

                }
                case (ASSAMESE_IV_I):
                case (ASSAMESE_IV_II):
                case (ASSAMESE_IV_U):
                case (ASSAMESE_IV_UU):
                case (ASSAMESE_IV_AI):
                case (ASSAMESE_IV_AU):
                {
                    return ((UI_character_type*) default_assamesematra2_multitap_strings[i]);

                }                
                default:
                {
                    return ((UI_character_type*) default_assamese_multitap_strings[i]);
                }

            }
        }
    }
    else
    {
        return ((UI_character_type*) default_assamese_multitap_strings[i]);
    }

}
UI_character_type *get_assamese_multitap_string_for_vk(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    	
	return ((UI_character_type*) default_assamesematra_multitap_strings[i]);
}

#endif /* defined(__MMI_MULTITAP_ASSAMESE__) */ 

#else /* defined (__MMI_LANG_ASSAMESE__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_assamese_warning_remove
 * DESCRIPTION
 *  for removing warnings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_assamese_warning_remove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* dummy function */
}
#endif /* defined (__MMI_LANG_ASSAMESE__) */ 


