/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
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
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   resource_ime_jtbl.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements indirect IME jumps table for multi-load.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

// __CUSTPACK_MULTIBIN     Terry   BEGIN

#include "IMERes.h"
#include "CustDataRes.h"
#include "CustMenuRes.h"//071706 menu resource
#include "FontRes.h"
#include "kal_release.h"

#if !defined __MMI_XT9__
#if defined(__MMI_T9_V7__) || defined (__MMI_T9_V7_4__)
#if defined(__MMI_T9_TR_CHINESE__) || defined(__MMI_T9_HK_CHINESE__)
extern T9ChineseData const T9FARDATA l0104;
#endif
#if defined(__MMI_T9_SM_CHINESE__)
extern T9ChineseData const T9FARDATA l0204;
#endif
#else
#if defined(__MMI_T9_TR_CHINESE__)
extern T9ChineseData const FARDATA l0104;
#endif
#if defined(__MMI_T9_SM_CHINESE__)
extern T9ChineseData const FARDATA l0204;
#endif
#endif
#endif

extern const U16 mtk_gMaxDeployedLangs;
extern const sLanguageDetails mtk_gLanguageArray[];
extern const font_group_struct g_fontfamily[];

#ifdef __MMI_FONT_COMPRESSION__
extern const mmi_font_compress_info mtk_font_compress_info[];
#endif

#ifdef __MMI_BDF_SW_COMPRESSION__
extern const U8 g_hw_compression_lv1_table[];
extern const U8 g_hw_compression_lv2_table[256][15];
#endif

extern const StringResList	mtk_gStringList[];

extern const sIMEModeDetails mtk_gIMEModeArray[];
extern const sIMEModeDetails mtk_gIMEQSearchModeArray[];
extern const sIMELDBDetails mtk_gIMELDBArray[];
extern const sIMEModuleDetails mtk_gIMEModule;
extern const CUSTOM_MENU_RES_ENTRY mtk_gMenuResEntry;//071706 menu resource
extern const CUSTPACK_FONT_HEADER mtk_font_header[];
extern const S32 mtk_gAv_total_menuitem; //Total number of availble menuitems
extern const U16 mtk_gTrans_string_count; //Total number of available string

void* langpack2ndJumpTbl[] = {
    (void*) mtk_gLanguageArray                //[0]
    , (void*) &mtk_gMaxDeployedLangs          //[1]
    , (void*) mtk_gStringList                 //[2]
    , (void*) mtk_gIMEModeArray               //[3]
    , (void*) mtk_gIMEQSearchModeArray        //[4]
    , (void*) mtk_gIMELDBArray                //[5]
    , (void*) &mtk_gIMEModule                 //[6]

#if ( (defined(__MMI_T9_TR_CHINESE__) || defined(__MMI_T9_HK_CHINESE__))  && !defined (__MMI_XT9__) )
    ,(void*) &l0104                           //[7]
#else
    ,0
#endif
#if defined(__MMI_T9_SM_CHINESE__)  && !defined (__MMI_XT9__)
    , (void*) &l0204                          //[8]
#else
    ,0
#endif
    ,(void*) &mtk_gMenuResEntry               //[9]: menu resource
    ,(void*) mtk_font_header                  //[10]
#ifdef __MMI_FONT_COMPRESSION__
    , (void*) &mtk_font_compress_info         //[11]
#else
    ,0
#endif
    ,(void*) &g_fontfamily                    //[12]
    ,(void*) &mtk_gAv_total_menuitem          //[13]: Total number of availble menuitems
    ,(void*) &mtk_gTrans_string_count         //[14]: Total number of available string
#ifdef __MMI_BDF_SW_COMPRESSION__
    , (void*) g_hw_compression_lv1_table         //[15]
    , (void*) &g_hw_compression_lv2_table[0][0]         //[16]
#else
    ,0
    ,0
#endif

};
// __CUSTPACK_MULTIBIN     Terry   END
