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
 *  LangModule.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  language module
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
#include "Armenian.h"
#include "./../LangModuleInc/Thai.h"
#include "./../LangModuleInc/ThaiGProt.h"
#include "Viet.h"
#include "IndicEngineGprot.h"
#include "ArabicGProt.h"
#include "LangModuleGProt.h"
#include "Indic.h"
#include "CommonLang.h"
#include "ArabicLang.h"
#include "LangModule.h"

/* RHR */
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gui_data_types.h"
#include "kal_public_api.h"
#include "string.h"
    
/***************************************************************************** 
* Define
*****************************************************************************/



#if !defined(__MMI_LANG_THAI__) && !defined(__MMI_LANG_ARMENIAN__) && !defined(__MMI_INDIC_ALG__) && !defined(__MMI_ARSHAPING_ENGINE__) && !defined(__MMI_LANG_VIETNAMESE__) && !defined(__MMI_LM_LANG_EUROPEAN_SUPPORT__)
#define __MMI_LM_BASIC_LANG_ONLY__
#endif

typedef void (*mmi_lm_get_cluster_funcptr) (PU8 start, PU8 end, mmi_lm_cluster_info_p prev2_cluster, mmi_lm_cluster_info_p prev_cluster, mmi_lm_cluster_info_p curr_cluster, MMI_BOOL pos_only);
typedef void (*mmi_lm_show_cluster_funcptr)(mmi_lm_show_cluster_param_p param);
typedef void (*mmi_lm_get_prev_cluster_funcptr)(PU8 start, PU8 end, PU8 cursor, MMI_BOOL pos_only, mmi_lm_cluster_info_p prev_cluster);
typedef void (*mmi_lm_get_next_cluster_funcptr)(PU8 start, PU8 end, PU8 cursor, MMI_BOOL pos_only, mmi_lm_cluster_info_p next_cluster);
typedef S32 (*mmi_lm_cluster_rule_translate)(UI_string_type src, UI_string_type dst, S32 len);

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef struct
{
    mmi_lm_lang_enum lang;
    mmi_lm_get_cluster_funcptr get_cluster;
    mmi_lm_show_cluster_funcptr show_cluster;
    mmi_lm_get_prev_cluster_funcptr get_prev_cluster;
    mmi_lm_get_next_cluster_funcptr get_next_cluster;
    mmi_lm_cluster_rule_translate translate_cluster;
} mmi_lm_lang_item, *mmi_lm_lang_item_p;


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

static const mmi_lm_lang_item g_mmi_lm_lang_info[] =
{
    {MMI_LM_LANG_NONE, NULL, NULL, NULL, NULL, NULL},
#if defined(__MMI_LANG_THAI__)
    {MMI_LM_LANG_THAI, mmi_lm_thai_get_current_cluster, mmi_lm_thai_draw_cluster, mmi_lm_thai_get_prev_cluster, mmi_lm_thai_get_next_cluster, mmi_lm_thai_cluster_translate},
#else
    {MMI_LM_LANG_THAI, NULL, NULL, NULL, NULL, NULL},
#endif
#if defined(__MMI_ARSHAPING_ENGINE__)
    {MMI_LM_LANG_ARABIC, mmi_lm_arabic_get_current_cluster, mmi_lm_arabic_draw_cluster, mmi_lm_arabic_get_prev_cluster, mmi_lm_arabic_get_next_cluster, mmi_lm_arabic_cluster_translate},
#else    
    {MMI_LM_LANG_ARABIC, NULL, NULL, NULL, NULL, NULL},
#endif
#if defined(__MMI_INDIC_ALG__)    
    {MMI_LM_LANG_INDIC, mmi_lm_indic_get_current_cluster, mmi_lm_indic_draw_cluster, mmi_lm_indic_get_prev_cluster, mmi_lm_indic_get_next_cluster, mmi_lm_indic_cluster_translate},
#else
    {MMI_LM_LANG_INDIC, NULL, NULL, NULL, NULL, NULL},
#endif
#if defined(__MMI_LANG_ARMENIAN__)
    {MMI_LM_LANG_ARMENIAN, mmi_lm_armenian_get_current_cluster, mmi_lm_armenian_draw_cluster, mmi_lm_armenian_get_prev_cluster, mmi_lm_armenian_get_next_cluster, mmi_lm_armenian_cluster_translate},
#else
    {MMI_LM_LANG_ARMENIAN, NULL, NULL, NULL, NULL, NULL},
#endif
    {MMI_LM_LANG_OTHERS, mmi_lm_common_get_current_cluster, mmi_lm_common_draw_cluster, mmi_lm_common_get_prev_cluster, mmi_lm_common_get_next_cluster, mmi_lm_common_cluster_translate},
};

/***************************************************************************** 
* Local Function
*****************************************************************************/
static mmi_lm_lang_enum mmi_lm_get_char_lang(UI_character_type c);
static void mmi_lm_get_current_cluster_int(
			PU8 start, 
			PU8 end, 
			mmi_lm_cluster_info_p prev2_cluster, 
			mmi_lm_cluster_info_p prev_cluster, 
			mmi_lm_cluster_info_p curr_cluster,
			MMI_BOOL pos_only);


/*****************************************************************************
 * FUNCTION
 *  mmi_lm_get_char_lang
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
__inline static mmi_lm_lang_enum mmi_lm_get_char_lang(UI_character_type ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_INDIC_ALG__)
    if (IRE_INDIC_CHARACTER_UCS2_RANGE(ch))
    {
        return MMI_LM_LANG_INDIC;
    }
#endif

#if defined(__MMI_LANG_THAI__)
    if (THAI_IS_UCS2_CHARACTER_RANGE(ch))
    {
        return MMI_LM_LANG_THAI;
    }
#endif

#if defined(__MMI_ARSHAPING_ENGINE__)
    if (MMI_LM_ARABIC_UCS2_CHAR(ch))
    {
        return MMI_LM_LANG_ARABIC;
    }    
#endif

#if defined(__MMI_LANG_ARMENIAN__)
    if (IRE_ARMENIAN_UCS2_RANGE(ch))
    {
        return MMI_LM_LANG_ARMENIAN;
    }
#endif

    if (ch == 0x0)
        return MMI_LM_LANG_NONE;

    return MMI_LM_LANG_OTHERS;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_lm_get_current_cluster
 * DESCRIPTION
 *  To get cluster information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lm_get_current_cluster(
			PU8 start, 
			PU8 end, 
			mmi_lm_cluster_info_p prev2_cluster, 
			mmi_lm_cluster_info_p prev_cluster, 
			mmi_lm_cluster_info_p curr_cluster)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_lm_get_current_cluster_int(start, end, prev2_cluster, prev_cluster, curr_cluster, MMI_FALSE);
}




/*****************************************************************************
 * FUNCTION
 *  mmi_lm_get_current_cluster_int
 * DESCRIPTION
 *  To get cluster info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_lm_get_current_cluster_int(
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
    mmi_lm_get_cluster_funcptr get_cluster;
    mmi_lm_lang_enum lang_id;
    UI_character_type curCh = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curCh = (UI_character_type)MMI_LM_GET_CHARACTER_FROM_BUFFER(start);
    lang_id = mmi_lm_get_char_lang(curCh);
    get_cluster = g_mmi_lm_lang_info[lang_id].get_cluster;
    curr_cluster->data_ptr = start;
    curr_cluster->lang_id = lang_id;

    if (lang_id == MMI_LM_LANG_NONE)
    {
        curr_cluster->data_len = curr_cluster->cluster_len = 1;        
        curr_cluster->display_buffer[0] = 0;
        curr_cluster->adv_x = 0;
        curr_cluster->adv_y = 0;
        curr_cluster->w = 0;
        curr_cluster->h = 0;
        curr_cluster->rx = 0;
        curr_cluster->ry = 0;
        curr_cluster->bx = 0;
        curr_cluster->by = 0;
        curr_cluster->is_gap = MMI_LM_CLUSTER_ATTR_GAP;
        curr_cluster->is_connect = MMI_LM_CLUSTER_ATTR_DISCONNECT;
        return;
    }

    ASSERT(get_cluster != NULL);


    /*
     * special process for different behavior between editor and font engine.
     * editor pass unshaping string but font engine passed shaping string into languagemodule.
     * for arabic present form, we would not treat as arabic character becuase we don't want to do shaping twice.
     * but we still have to treat it as arabic cluster.
     */
#if defined(__MMI_ARSHAPING_ENGINE__)
    if (IS_ARABIC_CHARACTER(curCh))
        curr_cluster->lang_id = MMI_LM_LANG_ARABIC;
#endif

    if (prev_cluster->lang_id != curr_cluster->lang_id)
    {
        curr_cluster->is_gap = MMI_LM_CLUSTER_ATTR_GAP;
    }

    get_cluster(
        start, 
        end, 
        prev2_cluster, 
        prev_cluster, 
        curr_cluster,
        pos_only);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_lm_get_next_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lm_get_next_cluster(
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
    ASSERT((start <= cursor) && (start <= end) && (cursor <= end));

    if (end == cursor)
    {
        next_cluster->data_ptr = cursor;
    }
    else
    {
#if defined(__MMI_LM_BASIC_LANG_ONLY__)
        {
            mmi_lm_cluster_info prevcluster, prev2cluster;
            mmi_lm_cluster_init(&prevcluster);
            mmi_lm_cluster_init(&prev2cluster);
                        
            mmi_lm_get_current_cluster_int(cursor + 2, end, &prev2cluster, &prevcluster, next_cluster, pos_only);
            //next_cluster->data_ptr = cursor + 2;   
        }
#else
        {
            PU8 temp_cursor;
            mmi_lm_cluster_info cluster, prevcluster, prev2cluster;
            mmi_lm_lang_enum lang_id, prev_lang_id;

            temp_cursor = cursor + 2;
            lang_id = mmi_lm_get_char_lang((UI_character_type)MMI_LM_GET_CHARACTER_FROM_BUFFER(cursor));
            do
            {
                temp_cursor-= 2;
                prev_lang_id = mmi_lm_get_char_lang((UI_character_type)MMI_LM_GET_PREV_CHARACTER_FROM_BUFFER(temp_cursor, start));
            } while (prev_lang_id == lang_id && temp_cursor > start);

            /* get cluster from the new start position */
            mmi_lm_cluster_init(&prevcluster);
            mmi_lm_cluster_init(&cluster);

            do 
            {
                memcpy(&prev2cluster, &prevcluster, sizeof(mmi_lm_cluster_info));
                memcpy(&prevcluster, &cluster, sizeof(mmi_lm_cluster_info));
                mmi_lm_cluster_init(&cluster);
                
                mmi_lm_get_current_cluster_int(temp_cursor, end, &prev2cluster, &prevcluster, &cluster, pos_only);
                temp_cursor += (cluster.data_len*MMI_LM_CHARACTER_SIZE);
            } while ((cluster.data_ptr <= cursor) && (cluster.data_ptr < end));

            if (cluster.data_ptr >= end)
            {
                next_cluster->data_ptr = end;
            }
            else
            {
                memcpy(next_cluster, &cluster, sizeof(mmi_lm_cluster_info));
            }
        }
#endif
    }

    

}



/*****************************************************************************
 * FUNCTION
 *  mmi_lm_get_prev_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lm_get_prev_cluster(
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
    ASSERT((start <= cursor) && (start <= end) && (cursor <= end));

    if (cursor == start)
    {
        prev_cluster->data_ptr = cursor;
    }
    else
    {
#if defined(__MMI_LM_BASIC_LANG_ONLY__)
        {
            mmi_lm_cluster_info prevcluster, prev2cluster;
            mmi_lm_cluster_init(&prevcluster);
            mmi_lm_cluster_init(&prev2cluster);
            mmi_lm_get_current_cluster_int(cursor - 2, end, &prev2cluster, &prevcluster, prev_cluster, pos_only);
                
//            prev_cluster->data_ptr = cursor - 2;
        }
#else
        {
            //mmi_lm_get_next_cluster_funcptr get_prev_cluster;
            //mmi_lm_lang_enum lang_id;
            PU8 temp_cursor;
            mmi_lm_cluster_info cluster, prevcluster, prev2cluster;

            mmi_lm_get_char_lang((UI_character_type)MMI_LM_GET_CHARACTER_FROM_BUFFER(cursor));
            //get_prev_cluster = g_mmi_lm_lang_info[lang_id].get_prev_cluster;

            if (start == cursor)
            {
                prev_cluster->data_ptr = cursor;
            }
            else
            {

                temp_cursor = start;
                /* get cluster from the new start position */
                mmi_lm_cluster_init(&prevcluster);
                mmi_lm_cluster_init(&cluster);

                do 
                {
                    memcpy(&prev2cluster, &prevcluster, sizeof(mmi_lm_cluster_info));
                    memcpy(&prevcluster, &cluster, sizeof(mmi_lm_cluster_info));
                    mmi_lm_cluster_init(&cluster);
                    
                    mmi_lm_get_current_cluster_int(temp_cursor, end, &prev2cluster, &prevcluster, &cluster, pos_only);
                    temp_cursor+= (cluster.data_len*MMI_LM_CHARACTER_SIZE);
                } while ((cluster.data_ptr + cluster.data_len* MMI_LM_CHARACTER_SIZE) < cursor);


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
                {
                    memcpy(prev_cluster, &cluster, sizeof(mmi_lm_cluster_info));
                }

                if (!prev_cluster->data_ptr)
                {
                    prev_cluster->data_ptr = start;
                }
            }
        }
#endif
    }

    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_lm_draw_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lm_draw_cluster(mmi_lm_show_cluster_param_p param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_lm_show_cluster_funcptr show_cluster;
    mmi_lm_cluster_info_p cluster;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cluster = param->cluster;
    if (cluster->cluster_len == 0 || cluster->lang_id == MMI_LM_LANG_NONE)
        return;
    if (cluster->display_buffer[0] == 0x0
        && cluster->lang_id != MMI_LM_LANG_INDIC)
        return;
    
    show_cluster = g_mmi_lm_lang_info[cluster->lang_id].show_cluster;

    ASSERT(show_cluster!= NULL);

    show_cluster(param);
}
    
/*****************************************************************************
 * FUNCTION
 *  mmi_lm_cluster_translate
 * DESCRIPTION
 *  Translate string. If in the src, there is a pattern A + B could be changed to another unicode C, then change it to C.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_lm_cluster_translate(UI_string_type src, S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_lm_cluster_rule_translate cluster_translate;
    mmi_lm_lang_enum lang_id;
    UI_character_type curCh = 0;
    UI_string_type dst = src;
    S32 move_len = 0, ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len <= 0)
        return 0;

    do
    {
        curCh = (UI_character_type)src[0];
        lang_id = mmi_lm_get_char_lang(curCh);
		if (lang_id != NULL)
		{
        cluster_translate = g_mmi_lm_lang_info[lang_id].translate_cluster;
		}
		else
		{
			cluster_translate = g_mmi_lm_lang_info[MMI_LM_LANG_OTHERS].translate_cluster;
		}
        move_len = cluster_translate(src, dst, len);
        len -= move_len;
        src += move_len;
        dst++;
        ret ++;
    } while (len);
    return ret;    
}



