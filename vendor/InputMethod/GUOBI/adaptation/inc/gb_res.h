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
 *    guobiengine.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
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
 **
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "GlobalConstants.h"
#include "ImeGprot.h"
#include "PixtelDataTypes.h"
#include "Fat_fs.h"
#include "DebugInitDef.h"
#include "Imc_symbol.h"
#include "Imc_config.h"
#include "gui_themes.h"





#include "gbapi.h"
#include "gbtype.h"
#include "gbim.h"
#include "gbdef.h"
#include "gb_en.h"
#include "gb_candidate.h"
//#include "guobiengine.h"
#include "Word_engine.h"
#include "wgui_inputs.h"
#include "ImmProt.h"
#include "Multitap_engine.h"

#ifdef __MMI_IME_MEMORY_CARD_SUPPORT__
#include "Ime_lib_config.h"

#ifdef __MMI_IME_SM_CHINESE_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_SM_CHINESE__
#ifdef __MMI_GUOBI_0K__
#include "gb_sc_v5_slim0k.h"
#elif __MMI_GUOBI_5K__
#include "gb_sc_v5_slim5k.h"
#elif __MMI_GUOBI_10K__
#include "gb_sc_v5_slim10k.h"
#else
#include "gb_sc.h"
#endif
#endif
#endif

#ifdef __MMI_IME_HINDI_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_HINDI__
#include "gb_hi.h"
#endif
#endif

#ifdef __MMI_IME_INDONESIAN_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_INDONESIAN__
#include "gb_id.h"
#endif
#endif

#ifdef __MMI_IME_ARABIC_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_ARABIC__
#include "gb_ar.h"
#endif
#endif

#ifdef __MMI_IME_PERSIAN_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_PERSIAN__
#include "gb_fa.h"
#endif
#endif

#ifdef __MMI_IME_FRENCH_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_FRENCH__
#include "gb_fr.h"
#endif
#endif

#ifdef __MMI_IME_VIETNAMESE_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_VIETNAMESE__
#include "gb_vi.h"
#endif
#endif

#ifdef __MMI_IME_TURKISH_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_TURKISH__
#include "gb_tr.h"
#endif
#endif

#ifdef __MMI_IME_RUSSIAN_DATABASE_STORAGE_IN_ROM__
	#ifdef __MMI_GB_RUSSIAN__
#include "gb_ru.h"
#endif
#endif

#ifdef __MMI_IME_SPANISH_DATABASE_STORAGE_IN_ROM__
	#ifdef __MMI_GB_SPANISH__
#include "gb_sp.h"
#endif
#endif

#ifdef __MMI_IME_TR_CHINESE_DATABASE_STORAGE_IN_ROM__
	#ifdef __MMI_GB_TR_CHINESE__
#include "gb_tc.h"
#endif
#endif

#ifdef __MMI_IME_ROMANIAN_DATABASE_STORAGE_IN_ROM__
	#ifdef __MMI_GB_ROMANIAN__
#include "gb_ro.h"
#endif
#endif

#ifdef __MMI_IME_PORTUGUESE_DATABASE_STORAGE_IN_ROM__
	#ifdef __MMI_GB_PORTUGUESE__
#include "gb_pt.h"
#endif
#endif

#ifdef __MMI_IME_DUTCH_DATABASE_STORAGE_IN_ROM__
	#ifdef __MMI_GB_DUTCH__
#include "gb_nl.h"
#endif
#endif

#ifdef __MMI_IME_MALAY_DATABASE_STORAGE_IN_ROM__
	#ifdef __MMI_GB_MALAY__
#include "gb_ms.h"
#endif
#endif

#ifdef __MMI_IME_GREEK_DATABASE_STORAGE_IN_ROM__
	#ifdef __MMI_GB_GREEK__
#include "gb_grc.h"
#endif
#endif

#ifdef __MMI_IME_HUNGARIAN_DATABASE_STORAGE_IN_ROM__
	#ifdef __MMI_GB_HUNGARIAN__
#include "gb_hu.h"
#endif
#endif

#ifdef __MMI_IME_GERMAN_DATABASE_STORAGE_IN_ROM__
	#ifdef __MMI_GB_GERMAN__
#include "gb_de.h"
#endif
#endif

#ifdef __MMI_IME_CZECH_DATABASE_STORAGE_IN_ROM__
	#ifdef __MMI_GB_CZECH__
#include "gb_cs.h"
#endif
#endif

#ifdef __MMI_IME_BENGALI_DATABASE_STORAGE_IN_ROM__
	#ifdef __MMI_GB_BENGALI__
#include "gb_bn.h"
#endif
#endif

#ifdef __MMI_IME_ITALIAN_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_ITALIAN__
#include "gb_it.h"
#endif
#endif

#ifdef __MMI_IME_SA_PORTUGUESE_DATABASE_STORAGE_IN_ROM__
	#ifdef __MMI_GB_SA_PORTUGUESE__
#include "gb_pt_sa.h"
#endif
#endif

#ifdef __MMI_IME_SA_SPANISH_DATABASE_STORAGE_IN_ROM__
	#ifdef __MMI_GB_SA_SPANISH__
#include "gb_sp_sa.h"
#endif
#endif

#ifdef __MMI_IME_THAI_DATABASE_STORAGE_IN_ROM__
	#ifdef __MMI_GB_THAI__
#include "gb_th.h"
#endif
#endif

#ifdef __MMI_IME_BULGARIAN_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_BULGARIAN__
#include "gb_bg.h"
#endif
#endif

#ifdef __MMI_IME_CROATIAN_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_CROATIAN__
#include "gb_hr.h"
#endif
#endif

#ifdef __MMI_IME_DANISH_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_DANISH__
#include "gb_da.h"
#endif
#endif

#ifdef __MMI_IME_FRENCH_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_POLISH__
#include "gb_pl.h"
#endif
#endif

#ifdef __MMI_IME_URDU_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_URDU__
#include "gb_ur.h"
#endif
#endif

#ifdef __MMI_IME_HEBREW_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_HEBREW__
#include "gb_he.h"
#endif
#endif

#ifdef __MMI_IME_NORWEGIAN_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_NORWEGIAN__
#include "gb_no.h"
#endif
#endif

#ifdef __MMI_IME_ESTONIAN_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_ESTONIAN__
#include "gb_es.h"
#endif
#endif

#ifdef __MMI_IME_FINNISH_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_FINNISH__
#include "gb_fi.h"
#endif
#endif

#ifdef __MMI_IME_FRENCH_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_GUJARATI__
#include "gb_gu.h"
#endif
#endif

#ifdef __MMI_IME_HINGLISH_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_HINGLISH__
#include "gb_hi_e.h"
#endif
#endif

#ifdef __MMI_IME_KAZAKH_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_KAZAKH__
#include "gb_kk_kz.h"
#endif
#endif

#ifdef __MMI_IME_LITHUANIAN_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_LITHUANIAN__
#include "gb_lt.h"
#endif
#endif

#ifdef __MMI_IME_LATVIAN_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_LATVIAN__
#include "gb_lv.h"
#endif
#endif

#ifdef __MMI_IME_FRENCH_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_MALAYALAM__
#include "gb_ml.h"
#endif
#endif

#ifdef __MMI_IME_MARATHI_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_MARATHI__
#include "gb_mr.h"
#endif
#endif

#ifdef __MMI_IME_PUNJABI_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_PUNJABI__
#include "gb_pu.h"
#endif
#endif

#ifdef __MMI_IME_SWEDISH_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_SWEDISH__
#include "gb_sv.h"
#endif
#endif

#ifdef __MMI_IME_TAMIL_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_TAMIL__
#include "gb_ta.h"
#endif
#endif

#ifdef __MMI_IME_TELUGU_DATABASE_STORAGE_IN_ROM__
#ifdef __MMI_GB_TELUGU__
#include "gb_te.h"
#endif
#endif

#else /*__MMI_IME_MEMORY_CARD_SUPPORT__*/

#ifdef __MMI_GB_SM_CHINESE__
#ifdef __MMI_GUOBI_0K__
#include "gb_sc_v5_slim0k.h"
#elif __MMI_GUOBI_5K__
#include "gb_sc_v5_slim5k.h"
#elif __MMI_GUOBI_10K__
#include "gb_sc_v5_slim10k.h"
#else
#include "gb_sc.h"
#endif
#endif

#ifdef __MMI_GB_HINDI__
#include "gb_hi.h"
#endif

#ifdef __MMI_GB_INDONESIAN__
#include "gb_id.h"
#endif

#ifdef __MMI_GB_ARABIC__
#include "gb_ar.h"
#endif

#ifdef __MMI_GB_PERSIAN__
#include "gb_fa.h"
#endif

#ifdef __MMI_GB_FRENCH__
#include "gb_fr.h"
#endif

#ifdef __MMI_GB_VIETNAMESE__
#include "gb_vi.h"
#endif

#ifdef __MMI_GB_TURKISH__
#include "gb_tr.h"
#endif

#ifdef __MMI_GB_RUSSIAN__
#include "gb_ru.h"
#endif

#ifdef __MMI_GB_SPANISH__
#include "gb_sp.h"
#endif

#ifdef __MMI_GB_TR_CHINESE__
#include "gb_tc.h"
#endif

#ifdef __MMI_GB_ROMANIAN__
#include "gb_ro.h"
#endif

#ifdef __MMI_GB_PORTUGUESE__
#include "gb_pt.h"
#endif

#ifdef __MMI_GB_DUTCH__
#include "gb_nl.h"
#endif

#ifdef __MMI_GB_MALAY__
#include "gb_ms.h"
#endif

#ifdef __MMI_GB_GREEK__
#include "gb_grc.h"
#endif

#ifdef __MMI_GB_HUNGARIAN__
#include "gb_hu.h"
#endif

#ifdef __MMI_GB_GERMAN__
#include "gb_de.h"
#endif

#ifdef __MMI_GB_CZECH__
#include "gb_cs.h"
#endif

#ifdef __MMI_GB_BENGALI__
#include "gb_bn.h"
#endif

#ifdef __MMI_GB_ITALIAN__
#include "gb_it.h"
#endif

#ifdef __MMI_GB_SA_PORTUGUESE__
#include "gb_pt_sa.h"
#endif

#ifdef __MMI_GB_SA_SPANISH__
#include "gb_sp_sa.h"
#endif

#ifdef __MMI_GB_THAI__
#include "gb_th.h"
#endif

#ifdef __MMI_GB_BULGARIAN__
#include "gb_bg.h"
#endif

#ifdef __MMI_GB_CROATIAN__
#include "gb_hr.h"
#endif

#ifdef __MMI_GB_DANISH__
#include "gb_da.h"
#endif

#ifdef __MMI_GB_POLISH__
#include "gb_pl.h"
#endif	

#ifdef __MMI_GB_URDU__
#include "gb_ur.h"
#endif	

#ifdef __MMI_GB_HEBREW__
#include "gb_he.h"
#endif		

#ifdef __MMI_GB_NORWEGIAN__
#include "gb_no.h"
#endif

#ifdef __MMI_GB_ESTONIAN__
#include "gb_es.h"
#endif

#ifdef __MMI_GB_FINNISH__
#include "gb_fi.h"
#endif

#ifdef __MMI_GB_GUJARATI__
#include "gb_gu.h"
#endif

#ifdef __MMI_GB_HINGLISH__
#include "gb_hi_e.h"
#endif

#ifdef __MMI_GB_KAZAKH__
#include "gb_kk_kz.h"
#endif

#ifdef __MMI_GB_LITHUANIAN__
#include "gb_lt.h"
#endif

#ifdef __MMI_GB_LATVIAN__
#include "gb_lv.h"
#endif

#ifdef __MMI_GB_MALAYALAM__
#include "gb_ml.h"
#endif

#ifdef __MMI_GB_MARATHI__
#include "gb_mr.h"
#endif


#ifdef __MMI_GB_PUNJABI__
#include "gb_pu.h"
#endif


#ifdef __MMI_GB_SWEDISH__
#include "gb_sv.h"
#endif

#ifdef __MMI_GB_TAMIL__
#include "gb_ta.h"
#endif

#ifdef __MMI_GB_TELUGU__
#include "gb_te.h"
#endif

#ifdef __MMI_GB_AFRIKAANS__
#include "gb_af.h"
#endif

#ifdef __MMI_GB_ALBANIAN__
#include "gb_sq.h"
#endif


#ifdef __MMI_GB_FILIPINO__
#include "gb_ph.h"
#endif

#ifdef __MMI_GB_KHMER__
#include "gb_kh.h"
#endif

#ifdef __MMI_GB_SERBIAN__
#include "gb_sr.h"
#endif

#ifdef __MMI_GB_SWAHILI__
#include "gb_sw.h"
#endif

#ifdef __MMI_GB_UKRAINIAN__
#include "gb_uk.h"
#endif

#ifdef __MMI_GB_BASQUE__
#include "gb_eu.h"
#endif
#ifdef __MMI_GB_GEORGIAN__
#include "gb_ka.h"
#endif
#ifdef __MMI_GB_LAO__
#include "gb_lo.h"
#endif
#ifdef __MMI_GB_MACEDONIAN__
#include "gb_mk.h"
#endif

#endif /*__MMI_IME_MEMORY_CARD_SUPPORT__*/

#include "IMERes.h"     /* include cfor sIMEModeDetails */
#include "Imc.h"
typedef struct
{
    mmi_imm_input_mode_enum								input_mode;
    const GBU8 						*key_map_p;
    U32	                          	nLdbNum;
    U32                             required_keys;
    U32                             symbol_keys;
    mmi_ime_get_spellings_funcptr   get_spell_funcptr;
    mmi_ime_get_associates_funcptr  get_assoc_funcptr;
    mmi_ime_get_candidates_funcptr  get_cand_funcptr;
    #if defined(__MMI_IME_USER_DATABASE__)
    GBI32 *  pUDBID; 
#endif
}  mmi_ime_mode_info_struct, * mmi_ime_mode_info_struct_p;


typedef struct
{
	pGBInputStruct						ime_init_mode_p;					
	GBAuxInfo							*aux_p;					
	const mmi_ime_mode_info_struct 		*ime_mode_info_p;
	const GBLDB							*ldbs_num_map_p;	
	GBU16								g_nDataCount;
	const GBU8  						*key_map_p;
	U8										case_type;
	
} GBEngine, *PGBEngine;

#if defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
const GBLDB g_ldbs_map[] = {


					#ifdef __MMI_GB_ARABIC__
					{
						GBL_Arabic,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_ARABIC_DATABASE_STORAGE_IN_ROM__
						prv_arDataArray
					#else
					    NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_BENGALI__
					{
						GBL_Bengali,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_BENGALI_DATABASE_STORAGE_IN_ROM__
						prv_bnDataArray	
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_BULGARIAN__
					{
						GBL_Bulgarian,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_BULGARIAN_DATABASE_STORAGE_IN_ROM__
						prv_bgDataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_CROATIAN__
					{
						GBL_Croatian,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_CROATIAN_DATABASE_STORAGE_IN_ROM__
						prv_hrDataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_CZECH__
					{
						GBL_Czech,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_CZECH_DATABASE_STORAGE_IN_ROM__
						prv_czDataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_DANISH__
					{
						GBL_Danish,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_DANISH_DATABASE_STORAGE_IN_ROM__
						prv_daDataArray
					#else
						NULL
					#endif
				  },
					#endif
					#ifdef __MMI_GB_DUTCH__
					{
						GBL_Dutch,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_DUTCH_DATABASE_STORAGE_IN_ROM__
						prv_nlDataArray
					#else
						NULL
					#endif
				  },
					#endif
					#ifdef __MMI_GB_ENGLISH__
					{
						GBL_English,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_ENGLISH_DATABASE_STORAGE_IN_ROM__
						prv_enDataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_ESTONIAN__
					{
						GBL_Estonian,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_ESTONIAN_DATABASE_STORAGE_IN_ROM__
						prv_etDataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_FINNISH__
					{
						GBL_Finnish,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_FINNISH_DATABASE_STORAGE_IN_ROM__
						prv_fiDataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_FRENCH__
					{
						GBL_French,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_FRENCH_DATABASE_STORAGE_IN_ROM__
						prv_frDataArray
					#else
						NULL
					#endif	
					},
					#endif
					#ifdef __MMI_GB_GERMAN__
					{
						GBL_German,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_GERMAN_DATABASE_STORAGE_IN_ROM__
						prv_deDataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_GREEK__
					{
						GBL_Greek,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_GREEK_DATABASE_STORAGE_IN_ROM__
						prv_elDataArray
					#else
						NULL
					#endif	
					},
					#endif
					#ifdef __MMI_GB_GUJARATI__
					{
						GBL_Gujarati,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_GUJARATI_DATABASE_STORAGE_IN_ROM__
						prv_guDataArray
					#else
						NULL
					#endif
					},
					#endif
					
					#ifdef __MMI_GB_HINDI__
					{
						GBL_Hindi,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_HINDI_DATABASE_STORAGE_IN_ROM__
						prv_hiDataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_HINGLISH__
					{
						GBL_Hinglish,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_HINGLISH_DATABASE_STORAGE_IN_ROM__
						prv_hinDataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_HUNGARIAN__
					{
						GBL_Hungarian,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_HUNGARIAN_DATABASE_STORAGE_IN_ROM__
						prv_huDataArray
					#else
						NULL
					#endif	
					},
					#endif
					#ifdef __MMI_GB_INDONESIAN__
					{
						GBL_Indonesian,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_INDONESIAN_DATABASE_STORAGE_IN_ROM__
						prv_idDataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_KAZAKH__
					{
						GBL_Kazakh,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_KAZAKH_DATABASE_STORAGE_IN_ROM__
						prv_kk_KZDataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_LATVIAN__
					{
						GBL_Latvian,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_LATVIAN_DATABASE_STORAGE_IN_ROM__
						prv_lvDataArray
					#else
						NULL
					#endif	
					},
					#endif
					#ifdef __MMI_GB_LITHUANIAN__
					{
						GBL_Lithuanian,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_LITHUANIAN_DATABASE_STORAGE_IN_ROM__
						prv_ltDataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_MALAY__
					{
						GBL_Malaysian,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_MALAY_DATABASE_STORAGE_IN_ROM__
						prv_msDataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_MALAYALAM__
					{
						GBL_Malayalam,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_MALAYALAM_DATABASE_STORAGE_IN_ROM__
						prv_mlDataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_MARATHI__
					{
						GBL_Marathi,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_MARATHI_DATABASE_STORAGE_IN_ROM__
						prv_mrDataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef  __MMI_GB_PORTUGUESE__
					{
						GBL_Portuguese,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_PORTUGUESE_DATABASE_STORAGE_IN_ROM__
						prv_ptDataArray
					#else
						NULL
					#endif	
					},
					#endif
					#ifdef __MMI_GB_PERSIAN__
					{
						GBL_Farsi,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_PERSIAN_DATABASE_STORAGE_IN_ROM__
						prv_faDataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_PUNJABI__
					{
						GBL_Punjabi,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_PUNJABI_DATABASE_STORAGE_IN_ROM__
						prv_paDataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_ROMANIAN__
					{
						GBL_Romanian,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_ROMANIAN_DATABASE_STORAGE_IN_ROM__
						prv_roDataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_RUSSIAN__
					{
						GBL_Russian,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_RUSSIAN_DATABASE_STORAGE_IN_ROM__
						prv_ruDataArray
					#else
						NULL
					#endif	
					},
					#endif										
					#ifdef __MMI_GB_SA_SPANISH__
					{
						GBL_Spanish_SA,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_SA_SPANISH_DATABASE_STORAGE_IN_ROM__
						prv_essDataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_SA_PORTUGUESE__
					{
						GBL_Portuguese_SA,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_SA_PORTUGUESE_DATABASE_STORAGE_IN_ROM__
						prv_ptsDataArray
					#else
						NULL
					#endif
					},		
					#endif								
					#ifdef __MMI_GB_SM_CHINESE__
					{
						GBL_Chinese,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_SM_CHINESE_DATABASE_STORAGE_IN_ROM__
						prv_scdataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_SPANISH__
					{
						GBL_Spanish,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_SPANISH_DATABASE_STORAGE_IN_ROM__
						prv_esDataArray
					#else
						NULL
					#endif
					},
					#endif	
					#ifdef __MMI_GB_SWEDISH__
					{
						GBL_Swedish,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_SWEDISH_DATABASE_STORAGE_IN_ROM__
						prv_svDataArray
					#else
						NULL
					#endif	
					},
					#endif
					#ifdef __MMI_GB_TAMIL__
					{
						GBL_Tamil,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_TAMIL_DATABASE_STORAGE_IN_ROM__
						prv_taDataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_TELUGU__
					{
						GBL_Telugu,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_TELUGU_DATABASE_STORAGE_IN_ROM__
						prv_teDataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_THAI__
					{
						GBL_Thai,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_THAI_DATABASE_STORAGE_IN_ROM__
						prv_thDataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_TR_CHINESE__
					{
						GBL_Traditional_Chinese,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_TR_CHINESE_DATABASE_STORAGE_IN_ROM__
						prv_tcdataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_TURKISH__
					{
						GBL_Turkish,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_TURKISH_DATABASE_STORAGE_IN_ROM__
						prv_trDataArray
					#else
						NULL
					#endif	
					},
					#endif
					#ifdef __MMI_GB_VIETNAMESE__
					{
						GBL_Vietnamese,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_VIETNAMESE_DATABASE_STORAGE_IN_ROM__
						prv_viDataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_POLISH__
					{
						GBL_Polish,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_POLISH_DATABASE_STORAGE_IN_ROM__
						prv_plDataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_NORWEGIAN__
					{
						GBL_Norwegian,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_NORWEGIAN_DATABASE_STORAGE_IN_ROM__
						prv_noDataArray
					#else
						NULL
					#endif	
					},
					#endif
					#ifdef __MMI_GB_ITALIAN__
					{
						GBL_Italian,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_ITALIAN_DATABASE_STORAGE_IN_ROM__
						prv_itDataArray
					#else
						NULL
					#endif
					},
					#endif
					#ifdef __MMI_GB_URDU__
					{
						GBL_Urdu,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_URDU_DATABASE_STORAGE_IN_ROM__
						prv_urDataArray
					#else
						NULL
					#endif	
					},
					#endif
					#ifdef __MMI_GB_HEBREW__
					{
						GBL_Hebrew,
						GBL_Sub_Not_Spec,
					#ifdef __MMI_IME_HEBREW_DATABASE_STORAGE_IN_ROM__
						prv_heDataArray
					#else
						NULL
					#endif	
					},
					#endif
					
					
					{
						GBL_NULL,
						GBL_Sub_Not_Spec,
						NULL
					}
				};
#else
const GBLDB g_ldbs_map[] = {
                #ifdef __MMI_GB_AFRIKAANS__
					{
						GBL_Afrikaans,
						GBL_Sub_Not_Spec,
						prv_afDataArray
					},
					#endif
                    #ifdef __MMI_GB_ALBANIAN__
					{
						GBL_Albanian,
						GBL_Sub_Not_Spec,
						prv_sqDataArray
					},
					#endif
					#ifdef __MMI_GB_ARABIC__
					{
						GBL_Arabic,
						GBL_Sub_Not_Spec,
						prv_arDataArray
					},
					#endif
					#ifdef __MMI_GB_BASQUE__
					{
						GBL_Basque,
						GBL_Sub_Not_Spec,
						prv_euDataArray
					},
					#endif
					#ifdef __MMI_GB_BENGALI__
					{
					GBL_Bengali,
					GBL_Sub_Not_Spec,
					prv_bnDataArray	
					},
					#endif
					#ifdef __MMI_GB_BULGARIAN__
					{
					GBL_Bulgarian,
					GBL_Sub_Not_Spec,
					prv_bgDataArray	
					},
					#endif
					#ifdef __MMI_GB_CROATIAN__
					{
					GBL_Croatian,
					GBL_Sub_Not_Spec,
					prv_hrDataArray	
					},
					#endif
					#ifdef __MMI_GB_CZECH__
					{
					GBL_Czech,
					GBL_Sub_Not_Spec,
					prv_czDataArray	
					},
					#endif
					#ifdef __MMI_GB_DANISH__
					{
					GBL_Danish,
					GBL_Sub_Not_Spec,
					prv_daDataArray	
				  },
					#endif
					#ifdef __MMI_GB_DUTCH__
					{
					GBL_Dutch,
					GBL_Sub_Not_Spec,
					prv_nlDataArray	
				  },
					#endif
					#ifdef __MMI_GB_ENGLISH__
					{
						GBL_English,
						GBL_Sub_Not_Spec,
						prv_enDataArray
					},
					#endif
					#ifdef __MMI_GB_ESTONIAN__
					{
						GBL_Estonian,
						GBL_Sub_Not_Spec,
						prv_etDataArray
					},
					#endif
                #ifdef __MMI_GB_FILIPINO__
					{
						GBL_Tagalog,
						GBL_Sub_Not_Spec,
						prv_tlDataArray
					},
					#endif
					#ifdef __MMI_GB_FINNISH__
					{
						GBL_Finnish,
						GBL_Sub_Not_Spec,
						prv_fiDataArray
					},
					#endif
					#ifdef __MMI_GB_FRENCH__
					{
						GBL_French,
						GBL_Sub_Not_Spec,
						prv_frDataArray
					},
					#endif
					#ifdef __MMI_GB_GEORGIAN__
					{
						GBL_Georgian,
						GBL_Sub_Not_Spec,
						prv_geDataArray
					},
					#endif
					#ifdef __MMI_GB_GERMAN__
					{
						GBL_German,
						GBL_Sub_Not_Spec,
						prv_deDataArray
					},
					#endif
					#ifdef __MMI_GB_GREEK__
					{
						GBL_Greek,
						GBL_Sub_Not_Spec,
						prv_elDataArray
					},
					#endif
					#ifdef __MMI_GB_GUJARATI__
					{
						GBL_Gujarati,
						GBL_Sub_Not_Spec,
						prv_guDataArray
					},
					#endif
					
					#ifdef __MMI_GB_HINDI__
					{
						GBL_Hindi,
						GBL_Sub_Not_Spec,
						prv_hiDataArray
					},
					#endif
					#ifdef __MMI_GB_HINGLISH__
					{
						GBL_Hinglish,
						GBL_Sub_Not_Spec,
						prv_hinDataArray
					},
					#endif
					#ifdef __MMI_GB_HUNGARIAN__
					{
						GBL_Hungarian,
						GBL_Sub_Not_Spec,
						prv_huDataArray
					},
					#endif
					#ifdef __MMI_GB_INDONESIAN__
					{
						GBL_Indonesian,
						GBL_Sub_Not_Spec,
						prv_idDataArray
					},
					#endif
					#ifdef __MMI_GB_KAZAKH__
					{
						GBL_Kazakh,
						GBL_Sub_Not_Spec,
						prv_kk_KZDataArray
					},
					#endif
               #ifdef __MMI_GB_KHMER__
					{
						GBL_Khmer,
						GBL_Sub_Not_Spec,
						prv_khDataArray
					},
					#endif
					#ifdef __MMI_GB_LAO__
					{
						GBL_Lao,
						GBL_Sub_Not_Spec,
						prv_loDataArray
					},
					#endif
					#ifdef __MMI_GB_LATVIAN__
					{
						GBL_Latvian,
						GBL_Sub_Not_Spec,
						prv_lvDataArray
					},
					#endif
					#ifdef __MMI_GB_LITHUANIAN__
					{
						GBL_Lithuanian,
						GBL_Sub_Not_Spec,
						prv_ltDataArray
					},
					#endif
					#ifdef __MMI_GB_MACEDONIAN__
					{
						GBL_Macedonian,
						GBL_Sub_Not_Spec,
						prv_mkDataArray
					},
					#endif
					#ifdef __MMI_GB_MALAY__
					{
						GBL_Malaysian,
						GBL_Sub_Not_Spec,
						prv_msDataArray
					},
					#endif
					#ifdef __MMI_GB_MALAYALAM__
					{
						GBL_Malayalam,
						GBL_Sub_Not_Spec,
						prv_mlDataArray
					},
					#endif
					#ifdef __MMI_GB_MARATHI__
					{
						GBL_Marathi,
						GBL_Sub_Not_Spec,
						prv_mrDataArray
					},
					#endif
					#ifdef  __MMI_GB_PORTUGUESE__
					{
						GBL_Portuguese,
						GBL_Sub_Not_Spec,
						prv_ptDataArray
					},
					#endif
					#ifdef __MMI_GB_PERSIAN__
					{
						GBL_Farsi,
						GBL_Sub_Not_Spec,
						prv_faDataArray
					},
					#endif
					#ifdef __MMI_GB_PUNJABI__
					{
						GBL_Punjabi,
						GBL_Sub_Not_Spec,
						prv_paDataArray
					},
					#endif
					#ifdef __MMI_GB_ROMANIAN__
					{
						GBL_Romanian,
						GBL_Sub_Not_Spec,
						prv_roDataArray
					},
					#endif
					#ifdef __MMI_GB_RUSSIAN__
					{
						GBL_Russian,
						GBL_Sub_Not_Spec,
						prv_ruDataArray
					},
					#endif										
                #ifdef __MMI_GB_SERBIAN__
					{
						GBL_Serbian,
						GBL_Sub_Not_Spec,
						prv_srDataArray
					},
					#endif
					#ifdef __MMI_GB_SA_SPANISH__
					{
						GBL_Spanish_SA,
						GBL_Sub_Not_Spec,
						prv_essDataArray
					},
					#endif
					#ifdef __MMI_GB_SA_PORTUGUESE__
					{
						GBL_Portuguese_SA,
						GBL_Sub_Not_Spec,
						prv_ptsDataArray
					},		
					#endif								
					#ifdef __MMI_GB_SM_CHINESE__
					{
						GBL_Chinese,
						GBL_Sub_Not_Spec,
						prv_scdataArray
					},
					#endif
					#ifdef __MMI_GB_SPANISH__
					{
						GBL_Spanish,
						GBL_Sub_Not_Spec,
						prv_esDataArray
					},
					#endif	
               #ifdef __MMI_GB_SWAHILI__
					{
						GBL_Swahili,
						GBL_Sub_Not_Spec,
						prv_swDataArray
					},
					#endif	
					#ifdef __MMI_GB_SWEDISH__
					{
						GBL_Swedish,
						GBL_Sub_Not_Spec,
						prv_svDataArray
					},
					#endif
					#ifdef __MMI_GB_TAMIL__
					{
						GBL_Tamil,
						GBL_Sub_Not_Spec,
						prv_taDataArray
					},
					#endif
					#ifdef __MMI_GB_TELUGU__
					{
						GBL_Telugu,
						GBL_Sub_Not_Spec,
						prv_teDataArray
					},
					#endif
					#ifdef __MMI_GB_THAI__
					{
						GBL_Thai,
						GBL_Sub_Not_Spec,
						prv_thDataArray
					},
					#endif
					#ifdef __MMI_GB_TR_CHINESE__
					{
						GBL_Traditional_Chinese,
						GBL_Sub_Not_Spec,
						prv_tcdataArray
					},
					#endif
					#ifdef __MMI_GB_TURKISH__
					{
						GBL_Turkish,
						GBL_Sub_Not_Spec,
						prv_trDataArray
					},
					#endif
               #ifdef __MMI_GB_UKRAINIAN__
					{
						GBL_Ukrainian,
						GBL_Sub_Not_Spec,
						prv_ukDataArray
					},
					#endif
					#ifdef __MMI_GB_VIETNAMESE__
					{
						GBL_Vietnamese,
						GBL_Sub_Not_Spec,
						prv_viDataArray
					},
					#endif
					#ifdef __MMI_GB_POLISH__
					{
						GBL_Polish,
						GBL_Sub_Not_Spec,
						prv_plDataArray
					},
					#endif
					#ifdef __MMI_GB_NORWEGIAN__
					{
						GBL_Norwegian,
						GBL_Sub_Not_Spec,
						prv_noDataArray
					},
					#endif
					#ifdef __MMI_GB_ITALIAN__
					{
						GBL_Italian,
						GBL_Sub_Not_Spec,
						prv_itDataArray
					},
					#endif
					#ifdef __MMI_GB_URDU__
					{
						GBL_Urdu,
						GBL_Sub_Not_Spec,
						prv_urDataArray
					},
					#endif
					#ifdef __MMI_GB_HEBREW__
					{
						GBL_Hebrew,
						GBL_Sub_Not_Spec,
						prv_heDataArray
					},
					#endif
					
					
					{
						GBL_NULL,
						GBL_Sub_Not_Spec,
						NULL
					}
				};
#endif
