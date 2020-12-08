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
 *  ArabicLang.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Armenian language module
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#if defined(__MMI_ARSHAPING_ENGINE__)
#include "LangModule.h"
#include "ArabicLang.h"
#include "ArabicGProt.h"
#include "ArabicShapingEngine.h"
/***************************************************************************** 
* Define
*****************************************************************************/
#define MMI_LM_ARABIC_CLUSTER_MAX_LEN 6
/***************************************************************************** 
* Typedef 
*****************************************************************************/

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
UI_character_type g_mmi_lm_arabic_text_buff[MMI_LM_ARABIC_CLUSTER_MAX_LEN *3 ];
/***************************************************************************** 
* Local Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_lm_arabic_get_current_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lm_arabic_get_current_cluster(
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
    S32 length = 0;
    S32 input_length = (end - start)/MMI_LM_CHARACTER_SIZE;
    S32 check_len = 0;
    S32 read_len;
    U16 cluster_len;
    S32 i = 0;
    UI_character_type curch;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (prev_cluster->data_len)
    {
        curch = MMI_LM_GET_CHARACTER_FROM_BUFFER(prev_cluster->data_ptr);
        switch (ArabicGetJoinType(MMI_LM_GET_CHARACTER_FROM_BUFFER(start)))
        {
            case ARABIC_NON_JOIN:
            case ARABIC_LEFT_JOIN:
                break;
            default:    
                if (prev_cluster->lang_id == MMI_LM_LANG_ARABIC)
                    curr_cluster->is_connect = MMI_LM_CLUSTER_ATTR_CONNECT;

                if (prev2_cluster->data_len)
                {
                    switch(ArabicGetJoinType(curch))
                    {
                        case ARABIC_NON_JOIN:
                        case ARABIC_LEFT_JOIN:
                            break;
                        default:
                            memcpy(g_mmi_lm_arabic_text_buff, prev2_cluster->data_ptr, prev2_cluster->data_len*MMI_LM_CHARACTER_SIZE);
                            length = prev2_cluster->data_len;                            
                            break;

                    }
                }
                memcpy(g_mmi_lm_arabic_text_buff+length, prev_cluster->data_ptr, prev_cluster->data_len*MMI_LM_CHARACTER_SIZE);
                length += prev_cluster->data_len;        
                break;
        }
        if (!MMI_LM_ARABIC_UCS2_CHAR(curch))
        {
            curr_cluster->is_gap = MMI_LM_CLUSTER_ATTR_GAP;
        }
    }

    check_len = (input_length> MMI_LM_ARABIC_CLUSTER_MAX_LEN? MMI_LM_ARABIC_CLUSTER_MAX_LEN: input_length);

    do
    {
        curch = MMI_LM_GET_CHARACTER_FROM_BUFFER(start+ i*MMI_LM_CHARACTER_SIZE);
        if (MMI_LM_ARABIC_UCS2_CHAR(curch))
        {
            g_mmi_lm_arabic_text_buff[length++] = curch;
        }
        else
        {
            break;
        }
        i ++;
    } while(i < check_len);

    check_len = i;

    g_mmi_lm_arabic_text_buff[length] = 0x0;
    cluster_len = check_len;
    arabic_shape_rules(length, (PU16)g_mmi_lm_arabic_text_buff);
    
    read_len = arabic_ligature_rules(
                        ARABIC_LIGATURE_NONE
                        #if defined(__MMI_LANG_ARABIC__)
                        | ARABIC_LIGATURE_ARABIC
                        #endif
                        #if defined(__MMI_LANG_PERSIAN__)
                        | ARABIC_LIGATURE_PERSIAN
                        #endif
                        #if defined(__MMI_LANG_URDU__)
                        | ARABIC_LIGATURE_URDU
                        #endif
                        , (g_mmi_lm_arabic_text_buff+(length - check_len)), 
                        curr_cluster->display_buffer,
                        &cluster_len, 
                        NULL, 
                        NULL, 
                        MMI_TRUE);
    curr_cluster->data_len = read_len;
    curr_cluster->cluster_len = cluster_len;
    if (!pos_only)
    {
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
 *  mmi_lm_arabic_get_next_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lm_arabic_get_next_cluster(
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
 *  mmi_lm_arabic_cluster_translate
 * DESCRIPTION
 *  Translate string. If in the src, there is a pattern A + B could be changed to another unicode C, then change it to C.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_lm_arabic_cluster_translate(UI_string_type src, UI_string_type dst, S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dst[0] = src[0];
    return 1;

}




/*****************************************************************************
 * FUNCTION
 *  mmi_lm_arabic_get_prev_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lm_arabic_get_prev_cluster(
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
 *  mmi_lm_arabic_draw_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lm_arabic_draw_cluster(mmi_lm_show_cluster_param_p param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_show_one_cluster_param_struct fe_param;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fe_param.string = (PU8)param->cluster->display_buffer;
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



#endif /* defined(__MMI_ARSHAPING_ENGINE__) */


