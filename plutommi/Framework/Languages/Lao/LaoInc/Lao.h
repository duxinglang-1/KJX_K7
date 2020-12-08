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
 *  Lao.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Lao header file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef LAO_H
#define LAO_H

#include "MMI_features.h"
#include "gui_data_types.h"
#include "MMIDataType.h"


/***************************************************************************** 
* Define
*****************************************************************************/
#define IRE_LAO_LANG_START_RANGE      0x0E80
#define IRE_LAO_LANG_END_RANGE        0x0EFF

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{   
    LAO_C_KO = 0x0E81,
    LAO_C_KHO_SUNG = 0x0E82,
    LAO_C_KHO_TAM = 0x0E84,
    LAO_C_NGO = 0x0E87,
    
    LAO_C_CO = 0x0E88,
    LAO_C_SO_TAM = 0x0E8A,
    LAO_C_NYO = 0x0E8D,
    
    LAO_C_DO = 0x0E94,
    LAO_C_TO = 0x0E95,
    LAO_C_THO_SUNG = 0x0E96,
    LAO_C_THO_TAM = 0x0E97,
    LAO_C_NO = 0x0E99,
    
    LAO_C_BO = 0x0E9A,
    LAO_C_PO = 0x0E9B,
    LAO_C_PHO_SUNG = 0x0E9C,
    LAO_C_FO_TAM = 0x0E9D,
    LAO_C_PHO_TAM = 0x0E9E,
    
    LAO_C_FO_SUNG = 0x0E9F,
    LAO_C_MO = 0x0EA1,
    LAO_C_YO = 0x0EA2,
    LAO_C_LO_LING = 0x0EA3,
    LAO_C_LO_LOOT = 0x0EA5,
    
    LAO_C_WO = 0x0EA7,
    LAO_C_SO_SUNG = 0x0EAA,
    LAO_C_HO_SUNG = 0x0EAB,
    LAO_C_O = 0x0EAD,
    LAO_C_HO_TAM = 0x0EAE,
    
    LAO_S_ELLIPSIS = 0x0EAF,
    
    /* INDEPENDENT VOWLES */
    LAO_IV_A = 0x0EB0,
    LAO_DV_MAIKAN = 0x0EB1,

    LAO_IV_AA = 0x0EB2,
    LAO_IV_AM = 0x0EB3,
    LAO_DV_I = 0x0EB4,
    LAO_DV_II = 0x0EB5,
    LAO_DV_Y = 0x0EB6,
    
    LAO_DV_YY = 0x0EB7,
    LAO_DV_U = 0x0EB8,
    LAO_DV_UU = 0x0EB9,
    LAO_DV_MAI_KON = 0x0EBB,
    
    LAO_S_LO = 0x0EBC,
    LAO_S_NYO = 0x0EBD, 
    
    LAO_IV_E = 0x0EC0, 
    
    LAO_IV_EI = 0x0EC1, 
    LAO_IV_O = 0x0EC2, 
    LAO_IV_AY = 0x0EC3, 
    
    LAO_IV_AI = 0x0EC4,
    
    LAO_M_KOLA = 0x0EC6, 
    
    LAO_TM_MAI_EK = 0x0EC8, 
    LAO_TM_MAI_THO = 0x0EC9, 
    LAO_TM_MAI_TI = 0x0ECA, 
    LAO_TM_MAI_CATAWA = 0x0ECB, 
    
    LAO_S_CANCELLATION_MARK = 0x0ECC, 
    LAO_S_NIGGAHITA = 0x0ECD, 
    
    LAO_D_ZERO = 0x0ED0, /* LAO digital 0 */
    LAO_D_ONE = 0x0ED1, /* LAO digital 1 */
    LAO_D_TWO = 0x0ED2, /* LAO digital 2 */
    LAO_D_THREE = 0x0ED3, /* LAO digital 3 */
    LAO_D_FOUR = 0x0ED4, /* LAO digital 4 */
    LAO_D_FIVE = 0x0ED5, /* LAO digital 5 */
    LAO_D_SIX = 0x0ED6, /* LAO digital 6 */
    LAO_D_SEVEN = 0x0ED7, /* LAO digital 7 */
    LAO_D_EIGHT = 0x0ED8, /* LAO digital 8 */
    LAO_D_NINE = 0x0ED9, /* LAO digital 9 */
    
    LAO_D_HONO = 0x0EDC, /* sign */
    LAO_D_HOMO = 0x0EDD
}Lao_characters_enum;


/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
#if defined(__MMI_MULTITAP_LAO__)
extern const UI_character_type default_lao_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_laomatra_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_laomatra1_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_laomatra2_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_laomatra3_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_laomatra4_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_laomatra5_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_laomatra6_multitap_strings[MAX_MULTITAPS][32];
#endif
/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
#if defined(__MMI_MULTITAP_LAO__)
extern UI_string_type get_lao_multitap_string(S32 index);
#endif

#endif /* LAO_H */ 




