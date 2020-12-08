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
 *  Viet.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Vietnamese header file
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef LANGMODULE_GPROT_H
#define LANGMODULE_GPROT_H

#include "MMI_features.h"
#include "gui_data_types.h"
#include "MMIDataType.h"
#include "viet.h"
#include "IndicEngineGProt.h"
#include "ArabicGProt.h"
#include "ThaiGProt.h"

/* RHR */
#include "kal_general_types.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#define MMI_LM_CLUSTER_MAX  5

/* cluster relation attribute */
#define MMI_LM_CLUSTER_ATTR_NO_GAP 0
#define MMI_LM_CLUSTER_ATTR_GAP 1
#define MMI_LM_CLUSTER_ATTR_DISCONNECT 0
#define MMI_LM_CLUSTER_ATTR_CONNECT 1

#define MMI_LM_GET_CHARACTER_FROM_BUFFER(buffer) ((buffer)[0]|((buffer)[1]<<8))
#define MMI_LM_GET_PREV_CHARACTER_FROM_BUFFER(buffer, start) ((buffer > start) ? ((*(((buffer)-2)+0))|((*(((buffer)-2)+1))<<8)): 0)
#define MMI_LM_GET_NEXT_CHARACTER_FROM_BUFFER(buffer, end) (((buffer) < (end)) ? ((*(((buffer)+2)+0))|((*(((buffer)+2)+1))<<8)) : 0)

#define MMI_LM_TEST_ALPHABETIC_CHAR(c) (( ((UI_character_type)(c)>=(UI_character_type)0x2E80) && ((UI_character_type)(c)<=(UI_character_type)0x9FAF)  || (c) == 0xFF1A || (c)==0xFE55 || (c)==0xFF1F|| (c) == '(' || (c) == 0xff08)?0:1)
#define MMI_LM_TEST_WORD_WRAPPING_BREAK_CHARACTER(c)  (((c) == 0x20 || (c) == 0x2D) ? 1:0)
#define MMI_LM_TEST_PREV_CONNECT(c) ((c) == ')' || (c) == 0xff09)
#define MMI_LM_TEST_BACK_CONNECT(c)  ((c) == '(' || (c) == 0xff08)

#define MMI_LM_CHARACTER_SIZE 2
/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{
    MMI_LM_LANG_NONE = 0,
    MMI_LM_LANG_THAI,
    MMI_LM_LANG_ARABIC,
    MMI_LM_LANG_INDIC,
    MMI_LM_LANG_ARMENIAN,
    MMI_LM_LANG_OTHERS,
    MMI_LM_LANG_MAX
} mmi_lm_lang_enum;


typedef struct
{
    /* original data & cluster info */
    U8* data_ptr;
    UI_character_type display_buffer[MMI_LM_CLUSTER_MAX];
    
    /* display info */    
    kal_int16 w; 
    kal_int16 h; 
    kal_int8 adv_x; 
    kal_int8 adv_y;
    kal_int8 bx; 
    kal_int8 by; 
    kal_int8 rx;
    kal_int8 ry;
    
    
    /* relation flags */
    U32 is_gap :1;    /* to identify if there is gap between current and previous cluster. */
    U32 is_connect :1; /* to identify if current cluster could be put into next line by refering the previous cluster. */
    U32 data_len:4;         
    U32 cluster_len:4;  
    U32 lang_id:4; /* mmi_lm_lang_enum */

} mmi_lm_cluster_info, *mmi_lm_cluster_info_p;

typedef struct
{
    S32 x;
    S32 y;
    S32 baseline;
    U8 bordered;
    mmi_lm_cluster_info_p cluster;
    mmi_lm_cluster_info_p prev_cluster;
} mmi_lm_show_cluster_param, *mmi_lm_show_cluster_param_p;


/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
#define mmi_lm_cluster_init(x)  memset (x, 0, sizeof (mmi_lm_cluster_info))

extern void mmi_lm_get_current_cluster(
			PU8 start, 
			PU8 end, 
			mmi_lm_cluster_info_p prev2_cluster, 
			mmi_lm_cluster_info_p prev_cluster, 
			mmi_lm_cluster_info_p curr_cluster);
extern void mmi_lm_get_next_cluster(
			PU8 start, 
			PU8 end, 
			PU8 cursor, 
			MMI_BOOL pos_only,
			mmi_lm_cluster_info_p next_cluster);
extern void mmi_lm_get_prev_cluster(
			PU8 start, 
			PU8 end, 
			PU8 cursor, 
			MMI_BOOL pos_only,
			mmi_lm_cluster_info_p prev_cluster);

extern void mmi_lm_draw_cluster(mmi_lm_show_cluster_param_p param);

extern S32 mmi_lm_cluster_translate(UI_string_type src, S32 len);


#endif /* LANGMODULE_GPROT_H */ 




