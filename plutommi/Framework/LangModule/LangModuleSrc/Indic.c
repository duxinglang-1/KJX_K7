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
 *  Indic.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Indic language module - to integrate with IRE funcation and langauge module
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMI_features.h"
#ifdef __MMI_INDIC_ALG__

#ifdef __MMI_SCRIPT_EASY__
#include "se_mtk.h"
#endif

/*****************************************************************************
*  Include
*****************************************************************************/
#include "LangModuleGProt.h"
#include "IndicEngineGprot.h"
#include "LangModule.h"
/***************************************************************************** 
* Define
*****************************************************************************/
 
/***************************************************************************** 
* Typedef 
*****************************************************************************/
 
/***************************************************************************** 
* Local Variable
*****************************************************************************/
 
/***************************************************************************** 
* Local Function
*****************************************************************************/
static void mmi_lm_indic_measure_cluster(mmi_lm_cluster_info_p prev_cluster, mmi_lm_cluster_info_p curr_cluster, UI_string_type cluster_buff, S32 buf_len);

/***************************************************************************** 
* Global Variable
*****************************************************************************/
/***************************************************************************** 
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_lm_indic_get_current_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lm_indic_get_current_cluster(
            PU8 start, 
            PU8 end, 
            mmi_lm_cluster_info_p prev2_cluster, 
            mmi_lm_cluster_info_p prev_cluster, 
            mmi_lm_cluster_info_p curr_cluster, 
            MMI_BOOL pos_only)
{
#ifndef __MMI_SCRIPT_EASY__    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type cluster_buffer[G_MAX + 1];
    S32 cluster_len = 0;
    U16  next_char = 0;														/* used for storing the next character */
    U16  curr_char = 0;	
    PU8 curr_char_p = NULL;
    U32  next_char_pos = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    memset(cluster_buffer, '\0', 2 * (G_MAX + 1));
    curr_cluster->lang_id = MMI_LM_LANG_INDIC;
    
    if (ire_is_reset_indic_params())
        ire_reset_indic_params();
    
    /* set the start and end pointer */
    ire_init_cluster_start_p(start);
    ire_init_cluster_end_p(end);
    
    ire_disable_indic_rules_parsing();
    ire_disable_indic_reset_hindi_params();
    
    /* start forming cluster */
    curr_cluster->data_len = ire_get_cluster(cluster_buffer);
    /* check next character */
     curr_char = ((*start) | (*(start + 1)<<8));
     curr_char_p = start + (curr_cluster->data_len * 2);
     next_char = ((*curr_char_p) | (*(curr_char_p + 1) << 8));

    if (next_char)
    {
        next_char_pos = ire_identify_char_position(next_char);
    }

	if(!(IRE_IS_PREV_CURR_SAME_LANG(curr_char, next_char)))
	{
		IRE_WIDTH_ADJUSTMENT_REQUIRED();
	}
    else if (next_char_pos == IRE_POST_BASE_POSITION_CONSIDERING_PREV_OFFSET)
    {
        IRE_WIDTH_ADJUSTMENT_REQUIRED();
    }
    else
    {
        IRE_WIDTH_ADJUSTMENT_NOT_REQUIRED();
    }

    cluster_len = ire_get_display_buffer_len();
    cluster_buffer[cluster_len] = 0;
    curr_cluster->cluster_len = cluster_len;

/*    if (curr_cluster->data_len == 1)
    {
        curr_cluster->display_buffer[0] = cluster_buffer[0];
        curr_cluster->display_buffer[1] = 0;
        curr_cluster->cluster_len = 1;
    }
    else
    {
        curr_cluster->cluster_len = ire_language_rules(curr_cluster->display_buffer, cluster_buffer, MMI_LM_CLUSTER_MAX);
    }
*/
    if (!pos_only)
    {
        mmi_lm_indic_measure_cluster(prev_cluster, curr_cluster, cluster_buffer, cluster_len);
        if ((IRE_IS_PREV_CURR_SAME_LANG(curr_char, next_char)))
        {		    
            curr_cluster->w = curr_cluster->adv_x;
        }              

    }
    ire_enable_indic_rules_parsing();
    ire_enable_indic_reset_indic_params();
#else
    #define SE_MTK_CLUSTER_MAX ((1<<4) - 1)
    U32 cluster_len = se_mtk_find_cluster((unsigned short*)start, (end - start) / 2);
    curr_cluster->data_len = cluster_len > SE_MTK_CLUSTER_MAX ? SE_MTK_CLUSTER_MAX :  cluster_len;
    ASSERT(curr_cluster->data_len);
    curr_cluster->cluster_len = curr_cluster->data_len;
    if (!pos_only)
    {
        mmi_lm_indic_measure_cluster(prev_cluster, curr_cluster, (unsigned short*)start, curr_cluster->cluster_len);
        curr_cluster->w = curr_cluster->adv_x;
    }    
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_lm_indic_get_next_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lm_indic_get_next_cluster(
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
    
    next_cluster->data_ptr = ire_get_next_cluster_p(start, cursor);
}


    
/*****************************************************************************
 * FUNCTION
 *  mmi_lm_indic_cluster_translate
 * DESCRIPTION
 *  Translate string. If in the src, there is a pattern A + B could be changed to another unicode C, then change it to C.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_lm_indic_cluster_translate(UI_string_type src, UI_string_type dst, S32 len)
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
 *  mmi_lm_indic_get_prev_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lm_indic_get_prev_cluster(
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
    
    prev_cluster->data_ptr = ire_get_prev_cluster_p(start, end);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_lm_indic_draw_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lm_indic_draw_cluster(mmi_lm_show_cluster_param_p param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    mmi_fe_show_one_cluster_param_struct fe_param;
    mmi_lm_cluster_info_p cluster;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    {
    #ifndef __MMI_SCRIPT_EASY__    
        UI_character_type prev_ch = 0, cur_ch = 0;
        UI_character_type data_buff[G_MAX * 4];
        
        cluster = param->cluster;
        cur_ch = (UI_character_type)MMI_LM_GET_CHARACTER_FROM_BUFFER(cluster->data_ptr);
        if (param->prev_cluster)
        {
            if (param->prev_cluster->data_ptr)
            {
                prev_ch = (UI_character_type)MMI_LM_GET_CHARACTER_FROM_BUFFER(param->prev_cluster->data_ptr);
            }
        }
        if (IRE_INDIC_CHARACTER_UCS2_RANGE(prev_ch) && IRE_GET_CHARACTER_LANG_ID(prev_ch) == IRE_GET_CHARACTER_LANG_ID(cur_ch))
        {
            memcpy(&data_buff, param->prev_cluster->data_ptr, param->prev_cluster->data_len << 1);
            memcpy(&data_buff[param->prev_cluster->data_len], cluster->data_ptr, cluster->data_len << 1);
            fe_param.len = param->prev_cluster->data_len + cluster->data_len;
            fe_param.subarray_start = param->prev_cluster->data_len;
            fe_param.subarray_len = cluster->data_len;
        }
        else
        {
            memcpy(&data_buff, cluster->data_ptr, cluster->data_len << 1);
            fe_param.len = cluster->data_len;
            fe_param.subarray_start = 0;
            fe_param.subarray_len = cluster->data_len;
        }
        fe_param.string = (PU8)&data_buff;
    #else
        cluster = param->cluster;
        fe_param.string = (PU8)cluster->data_ptr;
        fe_param.len = cluster->data_len;
        fe_param.subarray_start = 0;
        fe_param.subarray_len = cluster->data_len;
    #endif /* #ifndef __MMI_SCRIPT_EASY__ */
        fe_param.baseline = param->baseline;
        fe_param.bordered = param->bordered;
        fe_param.x = param->x;
        fe_param.y = param->y;
        fe_param.langid = param->cluster->lang_id;
        mmi_fe_show_single_cluster(&fe_param);
                        
    }
#else
    {
        /*----------------------------------------------------------------*/
        /* Local Variables                                                */
        /*----------------------------------------------------------------*/
        
        U16 disp_cluster[G_MAX + 1], cluster_buffer[G_MAX + 1];
        S32 act_len = 0, data_len = 0;
        U8* disp_ptr = NULL;
        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/

        cluster = param->cluster;
        if (ire_is_reset_indic_params())
            ire_reset_indic_params();

        /* set the start and end pointer */
        ire_init_cluster_start_p(cluster->data_ptr);
        ire_init_cluster_end_p(cluster->data_ptr + cluster->data_len*2);

        ire_disable_indic_rules_parsing();
        ire_disable_indic_reset_hindi_params();

        /* we already copy the disp cluster into cluster_buffer. */
        if (cluster->cluster_len < MMI_LM_CLUSTER_MAX)
        {
            disp_ptr = (U8*)&cluster->display_buffer;
        }
        else
        {
            memcpy(cluster_buffer, cluster->data_ptr, cluster->data_len * MMI_LM_CHARACTER_SIZE);        
            data_len = ire_get_cluster(cluster_buffer);
            MMI_ASSERT(data_len == cluster->data_len);        
            act_len = ire_get_display_buffer_len();
            cluster->cluster_len = ire_language_rules(disp_cluster, cluster_buffer, act_len);
            disp_ptr = (U8*)&disp_cluster;
        }
        fe_param.string = disp_ptr;
        fe_param.len = cluster->cluster_len;
        fe_param.baseline = param->baseline;
        fe_param.bordered = param->bordered;
        fe_param.x = param->x;
        fe_param.y = param->y;
        fe_param.langid = cluster->lang_id;
        fe_param.subarray_start = 0;
        fe_param.subarray_len = fe_param.len;
        mmi_fe_show_single_cluster(&fe_param);

        ire_enable_indic_rules_parsing();
        ire_enable_indic_reset_indic_params();
    }
#endif        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_lm_indic_measure_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_lm_indic_measure_cluster(
                mmi_lm_cluster_info_p prev_cluster, 
                mmi_lm_cluster_info_p curr_cluster, 
                UI_string_type cluster_buff, 
                S32 buf_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VECTOR_FONT_SUPPORT__)    
    {       
        mmi_fe_query_single_cluster(prev_cluster, curr_cluster);
    }
#else
    {
        /*----------------------------------------------------------------*/
        /* Local Variables                                                */
        /*----------------------------------------------------------------*/
        mmi_fe_get_string_info_param_struct param = {0};
        U16 disp_cluster[G_MAX + 1];
        mmi_lm_cluster_info temp_cluster;
        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        mmi_lm_cluster_init(&temp_cluster);
        temp_cluster.data_ptr = (U8*)cluster_buff;
        temp_cluster.data_len = buf_len;
        temp_cluster.lang_id = MMI_LM_LANG_INDIC;

        mmi_fe_query_single_cluster(prev_cluster, &temp_cluster);
        if (temp_cluster.cluster_len < MMI_LM_CLUSTER_MAX)
            memcpy(&curr_cluster->display_buffer, &temp_cluster.display_buffer, (temp_cluster.cluster_len+1)<<1);
        curr_cluster->adv_x = temp_cluster.adv_x;
        curr_cluster->adv_y = temp_cluster.adv_y;
        curr_cluster->w = temp_cluster.w;
        curr_cluster->h = temp_cluster.h;
        curr_cluster->bx = temp_cluster.bx;    
        curr_cluster->by = temp_cluster.by; 
        curr_cluster->cluster_len = temp_cluster.cluster_len;
    }
#endif
    if (prev_cluster->lang_id != MMI_LM_LANG_INDIC || prev_cluster->lang_id == MMI_LM_LANG_NONE)
    {
        curr_cluster->is_gap = MMI_LM_CLUSTER_ATTR_GAP;
		if(!((prev_cluster->display_buffer[prev_cluster->data_len - 1] == ' ') || (prev_cluster->display_buffer[prev_cluster->data_len - 1] == '-')))
			curr_cluster->is_connect = MMI_LM_CLUSTER_ATTR_CONNECT;
    }
    else
    {
        if ((IRE_GET_CHARACTER_LANG_ID(MMI_LM_GET_CHARACTER_FROM_BUFFER(curr_cluster->data_ptr))) != (IRE_GET_CHARACTER_LANG_ID(MMI_LM_GET_CHARACTER_FROM_BUFFER(prev_cluster->data_ptr))))
        {
            curr_cluster->is_gap = MMI_LM_CLUSTER_ATTR_GAP;
            if (prev_cluster->w > prev_cluster->adv_x)
                curr_cluster->rx = prev_cluster->w - prev_cluster->adv_x;
        }
        else
        {
            curr_cluster->is_connect = MMI_LM_CLUSTER_ATTR_CONNECT;
            if (prev_cluster->lang_id != curr_cluster->lang_id && prev_cluster->w > prev_cluster->adv_x)
                curr_cluster->rx = prev_cluster->w - prev_cluster->adv_x;
        }
    }


}

 
#endif /* __MMI_INDIC_ALG__ */ 
    


