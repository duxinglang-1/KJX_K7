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

#if defined(__MMI_LANG_ARMENIAN__)
#include "LangModule.h"
#include "Armenian.h"

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

/***************************************************************************** 
* Local Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_lm_armenian_get_current_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lm_armenian_get_current_cluster(
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
    UI_character_type curch, nextch;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        

    /* the rule for armenian is that 1 or 2 character forms one cluster. */
    curch = MMI_LM_GET_CHARACTER_FROM_BUFFER(start);
    start+=2;
    curr_cluster->data_len++;
    curr_cluster->display_buffer[0] = curch;
    
    if (curch == 0x0574 || curch == 0x057e)
    {
        if (start < end)
        {
            nextch = MMI_LM_GET_CHARACTER_FROM_BUFFER(start);
            if (curch == 0x0574)
            {
                if (nextch == 0x0576)
                {
                    curr_cluster->display_buffer[0] = 0xfb13;
                    curr_cluster->data_len++;
                }
                else if (nextch == 0x0565)
                {
                    curr_cluster->display_buffer[0] = 0xfb14;
                    curr_cluster->data_len++;
                }            
                else if (nextch == 0x056B)
                {
                    curr_cluster->display_buffer[0] = 0xfb15;
                    curr_cluster->data_len++;
                }
                else if (nextch == 0x056D)
                {
                    curr_cluster->display_buffer[0] = 0xfb17;
                    curr_cluster->data_len++;
                }
            }
            else if (nextch == 0x0576)
            {
                curr_cluster->display_buffer[0] = 0xfb16;
                curr_cluster->data_len++;
            }
        }
    }

    curr_cluster->cluster_len = 1;
    curr_cluster->display_buffer[1] = 0;
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
 *  mmi_lm_armenian_get_next_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lm_armenian_get_next_cluster(
            PU8 start, 
            PU8 end, 
            PU8 cursor, 
            MMI_BOOL pos_only,
            mmi_lm_cluster_info_p next_cluster)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type curch;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curch = MMI_LM_GET_CHARACTER_FROM_BUFFER(cursor);
    cursor +=2;
    
}


   
/*****************************************************************************
 * FUNCTION
 *  mmi_lm_armenian_cluster_translate
 * DESCRIPTION
 *  Translate string. If in the src, there is a pattern A + B could be changed to another unicode C, then change it to C.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_lm_armenian_cluster_translate(UI_string_type src, UI_string_type dst, S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type curch, nextch;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len > 1)
    {
        curch = src[0];
        if (curch == 0x0574 || curch  == 0x057e)
        {
            nextch = src[1];
            if (curch == 0x0574)
            {
                if (nextch == 0x0576)
                {
                    dst[0] = 0xfb13;
                    return 2;
                }
                else if (nextch == 0x0565)
                {
                    dst[0] = 0xfb14;
                    return 2;
                }            
                else if (nextch == 0x056B)
                {
                    dst[0] = 0xfb15;
                    return 2;
                }
                else if (nextch == 0x056D)
                {
                    dst[0] = 0xfb17;
                    return 2;
                }
            }
            else if (nextch == 0x0576)
            {
                dst[0] = 0xfb16;
                return 2;
            }
            
            dst[0] = curch;
            return 1;
        }

    }
    else
    {
        dst[0] = src[0];
        return 1;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_lm_armenian_get_prev_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lm_armenian_get_prev_cluster(
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
 *  mmi_lm_armenian_draw_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lm_armenian_draw_cluster(mmi_lm_show_cluster_param_p param)
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


#endif /* defined(__MMI_LANG_ARMENIAN__) */


