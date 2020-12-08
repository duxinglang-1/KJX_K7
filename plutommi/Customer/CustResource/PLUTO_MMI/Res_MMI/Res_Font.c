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
 * Res_setting.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
/*****************************************************************************
*  Include
*****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "CustDataProts.h"
#include "GlobalDefs.h"
#include "CustResDef.h"
#include "vector_font_lang_memory_card_config.h"

/*****************************************************************************
*  Define
*****************************************************************************/

extern void SetFontResource(U16 FontID, S8 *filename, U32 userdata, S32 flags, S8 *enum_value, S8 *resfile);

#define ADD_FONT_RESOURCE(FontID, filename, userdata, flags, rom)                   \
    RES_PRINT_INFO("ADD FONT RESOURCE\t(%s [%d])...\n", __FILE__, __LINE__);        \
    if(rom) SetFontResource(FontID, filename, userdata, flags, #FontID, __FILE__);  \
    Sys_font_info_gen(FontID, filename);                                            \
    FontID++;                                                                       \
    RES_PRINT_INFO("\tdone.\n");

#if (defined(__MMI_LANG_ENGLISH__) || defined(__MMI_LANG_SWAHILI__) || defined(__MMI_LANG_ZULU__) || defined(__MMI_LANG_XHOSA__))&& \
     !defined(__MMI_LANG_TURKISH__)&&!defined(__MMI_LANG_VIETNAMESE__)&&!defined(__MMI_LANG_POLISH__)&&!defined(__MMI_LANG_CZECH__)&&!defined(__MMI_LANG_NORWEGIAN__)&& \
     !defined(__MMI_LANG_FINNISH__)&&!defined(__MMI_LANG_HUNGARIAN__)&&!defined(__MMI_LANG_SLOVAK__)&&!defined(__MMI_LANG_DUTCH__)&&!defined(__MMI_LANG_SWEDISH__)&& \
     !defined(__MMI_LANG_CROATIAN__)&&!defined(__MMI_LANG_ROMANIAN__)&&!defined(__MMI_LANG_SLOVENIAN__) && !defined(__MMI_LANG_FRENCH__) && \
     !defined (__MMI_LANG_LITHUANIAN__)&&!defined (__MMI_LANG_LATVIAN__)&&!defined (__MMI_LANG_ESTONIAN__)&&!defined(__MMI_LANG_AFRIKAANS__)&&!defined(__MMI_LANG_AZERBAIJANI__)&& \
     !defined (__MMI_LANG_HAUSA__)&&!defined(__MMI_LANG_ICELANDIC__)&&!defined(__MMI_LANG_SERBIAN__)&& !defined (__MMI_LANG_IGBO__)
#define __MMI_FONT_LATIN_BASIC__

#elif (defined(__MMI_LANG_TURKISH__)|| defined(__MMI_LANG_POLISH__) ||defined(__MMI_LANG_CZECH__)||defined(__MMI_LANG_SWEDISH__)|| \
       defined(__MMI_LANG_CROATIAN__)||defined(__MMI_LANG_SLOVENIAN__)||defined(__MMI_LANG_NORWEGIAN__)||defined(__MMI_LANG_SLOVAK__)|| \
       defined(__MMI_LANG_FINNISH__)||defined(__MMI_LANG_DUTCH__)||defined(__MMI_LANG_HUNGARIAN__) || defined(__MMI_LANG_FRENCH__) || \
       defined (__MMI_LANG_LITHUANIAN__) || defined (__MMI_LANG_LATVIAN__) || defined (__MMI_LANG_ESTONIAN__) || defined(__MMI_LANG_AFRIKAANS__))&& \
       !defined(__MMI_LANG_ROMANIAN__)&&!defined(__MMI_LANG_VIETNAMESE__)&&!defined (__MMI_LANG_HAUSA__)&& !defined (__MMI_LANG_IGBO__)
#define __MMI_FONT_LATIN_EXTEND_A__

#else

#define __MMI_FONT_LATIN_ALL__

#endif

#define SYS_FONT_INFO_FILENAME   "..\\..\\Customer\\CustResource\\Sys_font_info.h"

FILE *sys_font_info_file_handle = NULL;

S8* Get_file_name_by_path(const S8 *path)
{
    S8 *p;

    p = strstr(path, ".ttf");
    while(*(--p) != '\\')
        ;
    p++;

    return p;
}

void Sys_Font_Oninit()
{
#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
    sys_font_info_file_handle = fopen(SYS_FONT_INFO_FILENAME, "w");
    if(sys_font_info_file_handle)
    {
        fputs(_T("#ifndef __SYS_FONT_INFO_H__\n#define __SYS_FONT_INFO_H__\n"),sys_font_info_file_handle);
        fputs(_T("\ntypedef struct{\n"),sys_font_info_file_handle);
        fputs(_T("    U8* name;\n"),sys_font_info_file_handle);
        fputs(_T("    U16 res_id;\n"),sys_font_info_file_handle);
        fputs(_T("}mmi_system_font_info_struct;\n"),sys_font_info_file_handle);
        fputs(_T("\nconst mmi_system_font_info_struct system_font[] = {\n"),sys_font_info_file_handle);
    }
#endif
}

void Sys_font_info_gen(U16 FontID, S8 *filename)
{
#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
    S8 *name;

    if(sys_font_info_file_handle)
    {
        if(FontID > IMG_GLOBAL_FONT_MAX)
        {
            name = Get_file_name_by_path(filename);
            fprintf(sys_font_info_file_handle, "    {\"%s\", %d},\n", name, FontID);
        }
        else
        {
            fprintf(sys_font_info_file_handle, "    {NULL, %d},\n", FontID);
        }
    }
#endif
}

void Sys_font_deinit(U16 index)
{
#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
    if(sys_font_info_file_handle)
    {
        fputs(_T("};\n"),sys_font_info_file_handle);
        fprintf(sys_font_info_file_handle, "\n#define POP_FONT_FILES_EXT %d\n", index - (IMG_GLOBAL_FONT_MAX + 1));
        fputs(_T("\n#endif /*__SYS_FONT_INFO_H__*/\n"),sys_font_info_file_handle);
        fclose(sys_font_info_file_handle);
    }
#endif
}

void PopulateFontResource(void)
{
    
    int i = IMG_GLOBAL_FONT_1, j = IMG_GLOBAL_FONT_MAX + 1;

    Sys_Font_Oninit();
    
#if defined(FONT_ENGINE_MONOTYPE_DEMO)
    {   
        ADD_FONT_RESOURCE(
                i,
                CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Monotype_demo\\\\SmartHint\\\\NewSansMT_PRC2312-121416-D.stf", 0, 0, 1);
    }

#endif

#if defined(FONT_ENGINE_FREETYPE)
    {
#if defined(__MMI_LANG_IGBO__)
        ADD_FONT_RESOURCE(
                i,
                CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Monotype\\\\AlbanyWT.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#endif
        ADD_FONT_RESOURCE(
                i,
                CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Android\\\\RobotoRegular.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#if defined(__MMI_LANG_YORUBA__) || defined(__MMI_LANG_AZERBAIJANI__) || defined(__MMI_LANG_HAUSA__)
        ADD_FONT_RESOURCE(
                i,
                CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Dynacom\\\\DFU_HMD.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#endif
      
#if defined(__MMI_LANG_HK_CHINESE__) && !defined(__MMI_LANG_SM_CHINESE__) && !defined(__MMI_LANG_TR_CHINESE__)
        ADD_FONT_RESOURCE(
                i,
                CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Arphic\\\\bhkhei00m.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#elif (defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__)) && !defined(__MMI_LANG_HK_CHINESE__)
        ADD_FONT_RESOURCE(
                i,
                CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Android\\\\DroidSansFallback.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#elif defined(__MMI_LANG_HK_CHINESE__) && (defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__))
        ADD_FONT_RESOURCE(
                i,
                CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Monotype\\\\MHeiMedium18030C.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#endif
    }
#endif

#if !defined(FONT_ENGINE_ETRUMP)
    ADD_FONT_RESOURCE(
        i,
        CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Android\\\\DroidSansMono.ttf", 1, MMI_RES_FLAG_FONT_IS_ENFB, 1);  
#endif

#if defined(FONT_ENGINE_FREETYPE_DEMO)
    {
        #if defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__)
        ADD_FONT_RESOURCE(
                i,
                CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Android\\\\DroidSansFallback.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
        #endif
    }
#endif

#if defined(FONT_ENGINE_ETRUMP)

        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifLatinBasicF.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);

#if defined(__MMI_LANG_AFRIKAANS__)&&!defined(__MMI_LANG_AFRIKAANS_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_INDONESIAN__)&&!defined(__MMI_LANG_INDONESIAN_MEMORY_CARD_SUPPORT__) || \
    defined(__MMI_LANG_PORTUGUESE__)&&!defined(__MMI_LANG_PORTUGUESE_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_BULGARIAN__)&&!defined(__MMI_LANG_BULGARIAN_MEMORY_CARD_SUPPORT__) || \
    defined(__MMI_LANG_CATALAN__)&&!defined(__MMI_LANG_CATALAN_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_CROATIAN__)&&!defined(__MMI_LANG_CROATIAN_MEMORY_CARD_SUPPORT__) ||  \
    defined(__MMI_LANG_CZECH__)&&!defined(__MMI_LANG_CZECH_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_DANISH__)&&!defined(__MMI_LANG_DANISH_MEMORY_CARD_SUPPORT__) || \
    defined(__MMI_LANG_DUTCH__)&&!defined(__MMI_LANG_DUTCH_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_ESTONIAN__)&&!defined(__MMI_LANG_ESTONIAN_MEMORY_CARD_SUPPORT__) || \
    defined(__MMI_LANG_FINNISH__)&&!defined(__MMI_LANG_FINNISH_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_FRENCH__)&&!defined(__MMI_LANG_FRENCH_MEMORY_CARD_SUPPORT__) || \
    defined(__MMI_LANG_GERMAN__)&&!defined(__MMI_LANG_GERMAN_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_GREEK__)&&!defined(__MMI_LANG_GREEK_MEMORY_CARD_SUPPORT__) || \
    defined(__MMI_LANG_HAUSA__)&&!defined(__MMI_LANG_HAUSA_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_HUNGARIAN__)&&!defined(__MMI_LANG_HUNGARIAN_MEMORY_CARD_SUPPORT__) || \
    defined(__MMI_LANG_ZULU__)&&!defined(__MMI_LANG_ZULU_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_ITALIAN__)&&!defined(__MMI_LANG_ITALIAN_MEMORY_CARD_SUPPORT__) || \
    defined(__MMI_LANG_KAZAKH__)&&!defined(__MMI_LANG_KAZAKH_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_SWAHILI__)&&!defined(__MMI_LANG_SWAHILI_MEMORY_CARD_SUPPORT__) || \
    defined(__MMI_LANG_LATVIAN__)&&!defined(__MMI_LANG_LATVIAN_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_LITHUANIAN__)&&!defined(__MMI_LANG_LITHUANIAN_MEMORY_CARD_SUPPORT__) || \
    defined(__MMI_LANG_MALAY__)&&!defined(__MMI_LANG_MALAY_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_SPANISH__)&&!defined(__MMI_LANG_SPANISH_MEMORY_CARD_SUPPORT__) || \
    defined(__MMI_LANG_MOLDOVAN__)&&!defined(__MMI_LANG_MOLDOVAN_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_NORWEGIAN__)&&!defined(__MMI_LANG_NORWEGIAN_MEMORY_CARD_SUPPORT__) || \
    defined(__MMI_LANG_POLISH__)&&!defined(__MMI_LANG_POLISH_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_ROMANIAN__)&&!defined(__MMI_LANG_ROMANIAN_MEMORY_CARD_SUPPORT__) || \
    defined(__MMI_LANG_RUSSIAN__)&&!defined(__MMI_LANG_RUSSIAN_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_SERBIAN__)&&!defined(__MMI_LANG_SERBIAN_MEMORY_CARD_SUPPORT__) || \
    defined(__MMI_LANG_SLOVAK__)&&!defined(__MMI_LANG_SLOVAK_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_SLOVENIAN__)&&!defined(__MMI_LANG_SLOVENIAN_MEMORY_CARD_SUPPORT__) || \
    defined(__MMI_LANG_SWEDISH__)&&!defined(__MMI_LANG_SWEDISH_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_TAGALOG__)&&!defined(__MMI_LANG_TAGALOG_MEMORY_CARD_SUPPORT__) || \
    defined(__MMI_LANG_TURKISH__)&&!defined(__MMI_LANG_TURKISH_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_UKRAINIAN__)&&!defined(__MMI_LANG_UKRAINIAN_MEMORY_CARD_SUPPORT__) || \
    defined(__MMI_LANG_VIETNAMESE__)&&!defined(__MMI_LANG_VIETNAMESE_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_XHOSA__)&&!defined(__MMI_LANG_XHOSA_MEMORY_CARD_SUPPORT__) || \
    defined(__MMI_LANG_SA_PORTUGUESE__)&&!defined(__MMI_LANG_SA_PORTUGUESE_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_SA_SPANISH__)&&!defined(__MMI_LANG_SA_SPANISH_MEMORY_CARD_SUPPORT__) || \
    defined(__MMI_LANG_BASQUE__)&&!defined(__MMI_LANG_BASQUE_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_GEORGIAN__)&&!defined(__MMI_LANG_GEORGIAN_MEMORY_CARD_SUPPORT__) || \
    defined(__MMI_LANG_ICELANDIC__)&&!defined(__MMI_LANG_ICELANDIC_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_IRISH__)&&!defined(__MMI_LANG_IRISH_MEMORY_CARD_SUPPORT__) || \
    defined(__MMI_LANG_MACEDONIAN__)&&!defined(__MMI_LANG_MACEDONIAN_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_YORUBA__)&&!defined(__MMI_LANG_YORUBA_MEMORY_CARD_SUPPORT__)

        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifLatinFullSetF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);

#elif defined(__MMI_LANG_AFRIKAANS_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_INDONESIAN_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_PORTUGUESE_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_BULGARIAN_MEMORY_CARD_SUPPORT__) || \
        defined(__MMI_LANG_CATALAN_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_CROATIAN_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_CZECH_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_DANISH_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_DUTCH_MEMORY_CARD_SUPPORT__) || \
        defined(__MMI_LANG_ESTONIAN_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_FINNISH_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_FRENCH_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_GERMAN_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_GREEK_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_HAUSA_MEMORY_CARD_SUPPORT__) || \
        defined(__MMI_LANG_HUNGARIAN_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_ZULU_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_ITALIAN_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_KAZAKH_MEMORY_CARD_SUPPORT__)|| defined(__MMI_LANG_SWAHILI_MEMORY_CARD_SUPPORT__) || \
        defined(__MMI_LANG_LATVIAN_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_LITHUANIAN_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_MALAY_MEMORY_CARD_SUPPORT__)|| defined(__MMI_LANG_SPANISH_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_MOLDOVAN_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_NORWEGIAN_MEMORY_CARD_SUPPORT__) || \
        defined(__MMI_LANG_POLISH_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_ROMANIAN_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_RUSSIAN_MEMORY_CARD_SUPPORT__)|| defined(__MMI_LANG_SERBIAN_MEMORY_CARD_SUPPORT__) || \
        defined(__MMI_LANG_SLOVAK_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_SLOVENIAN_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_SWEDISH_MEMORY_CARD_SUPPORT__)|| defined(__MMI_LANG_TAGALOG_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_TURKISH_MEMORY_CARD_SUPPORT__) || \
        defined(__MMI_LANG_UKRAINIAN_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_VIETNAMESE_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_XHOSA_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_SA_PORTUGUESE_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_SA_SPANISH_MEMORY_CARD_SUPPORT__) || \
        defined(__MMI_LANG_BASQUE_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_GEORGIAN_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_ICELANDIC_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_IRISH_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_MACEDONIAN_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_YORUBA_MEMORY_CARD_SUPPORT__)

        ADD_FONT_RESOURCE(
            j,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifLatinFullSetF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 0);
#endif

#if defined(__MMI_LANG_SM_CHINESE__)&&!defined(__MMI_LANG_SM_CHINESE_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKYH2312F.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#elif defined(__MMI_LANG_SM_CHINESE_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            j,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKYH2312F.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 0);
#endif
            
#if defined(__MMI_LANG_TR_CHINESE__)&&!defined(__MMI_LANG_TR_CHINESE_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKYHBIG5F.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#elif defined(__MMI_LANG_TR_CHINESE_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            j,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKYHBIG5F.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 0);
#endif

#if defined(__MMI_LANG_ARABIC__)&&!defined(__MMI_LANG_ARABIC_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_PERSIAN__)&&!defined(__MMI_LANG_PERSIAN_MEMORY_CARD_SUPPORT__) || \
    defined(__MMI_LANG_URDU__)&&!defined(__MMI_LANG_URDU_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_HEBREW__)&&!defined(__MMI_LANG_HEBREW_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifArabicF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#elif defined(__MMI_LANG_ARABIC_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_PERSIAN_MEMORY_CARD_SUPPORT__) || \
        defined(__MMI_LANG_URDU_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_HEBREW_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            j,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifArabicF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 0);
#endif

#if defined(__MMI_LANG_BENGALI__)&&!defined(__MMI_LANG_BENGALI_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_ASSAMESE__)&&!defined(__MMI_LANG_ASSAMESE_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifBengalF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\MTK\\\\BTRC_Bengali_proprietary.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#endif
#elif defined(__MMI_LANG_BENGALI_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_ASSAMESE_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            j,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifBengalF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 0);
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\MTK\\\\BTRC_Bengali_proprietary.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#endif
#endif

#if defined(__MMI_LANG_GUJARATI__)&&!defined(__MMI_LANG_GUJARATI_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifGujaratiF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#elif defined(__MMI_LANG_GUJARATI_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            j,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifGujaratiF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 0);

#endif

#if defined(__MMI_LANG_MARATHI__)&&!defined(__MMI_LANG_MARATHI_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_HINDI__)&&!defined(__MMI_LANG_HINDI_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifHindiF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#elif defined(__MMI_LANG_MARATHI_MEMORY_CARD_SUPPORT__) || defined(__MMI_LANG_HINDI_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            j,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifHindiF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 0);
#endif

#if defined(__MMI_LANG_KANNADA__)&&!defined(__MMI_LANG_KANNADA_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifKanadaF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#elif defined(__MMI_LANG_KANNADA_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            j,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifKanadaF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 0);
#endif

#if defined(__MMI_LANG_MALAYALAM__)&&!defined(__MMI_LANG_MALAYALAM_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifMalaylamF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#elif defined(__MMI_LANG_MALAYALAM_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            j,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifMalaylamF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 0);
#endif

/*
#if defined(__MMI_LANG_ORIYA__)
            ADD_FONT_RESOURCE(
                    i,
                    CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifOriyaF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB);
#endif
*/

#if defined(__MMI_LANG_PUNJABI__)&&!defined(__MMI_LANG_PUNJABI_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifGurmukhiF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#elif defined(__MMI_LANG_PUNJABI_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            j,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifGurmukhiF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 0);
#endif
            
#if defined(__MMI_LANG_TAMIL__)&&!defined(__MMI_LANG_TAMIL_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifTamilF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#elif defined(__MMI_LANG_TAMIL_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            j,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifTamilF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 0);
#endif

#if defined(__MMI_LANG_TELUGU__)&&!defined(__MMI_LANG_TELUGU_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifTeluguF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#elif defined(__MMI_LANG_TELUGU_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            j,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifTeluguF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 0);
#endif

#if defined(__MMI_LANG_THAI__)&&!defined(__MMI_LANG_THAI_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifThaiF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#elif defined(__MMI_LANG_THAI_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            j,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifThaiF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 0);
#endif

#if defined(__MMI_LANG_LAO__)&&!defined(__MMI_LANG_LAO_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifLaosF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#elif defined(__MMI_LANG_LAO_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            j,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifLaosF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 0);
#endif

#if defined(__MMI_LANG_MYANMAR__)&&!defined(__MMI_LANG_MYANMAR_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifMyanmarF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#elif defined(__MMI_LANG_MYANMAR_MEMORY_CARD_SUPPORT__)
        ADD_FONT_RESOURCE(
            j,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Etrump\\\\MTKSansSerifMyanmarF_OTTB_SE.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 0);
#endif

#endif // FONT_ENGINE_ETRUMP



    /* MTK internal data */
    ADD_FONT_RESOURCE(
          i,
          CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\MTK\\\\MTK_proprietary.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);

#if defined(FONT_ENGINE_FREETYPE)
#if defined(__MMI_LANG_ARABIC__) || defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__) || defined(__MMI_LANG_RUSSIAN__) ||defined(__MMI_LANG_BULGARIAN__) || defined(__MMI_LANG_UKRAINIAN__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Monotype\\\\UniversOTS.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#endif
#endif

#if defined(FONT_ENGINE_MONOTYPE) || defined(FONT_ENGINE_WTLE)
    {   
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Monotype\\\\UniversOTS.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);

    
    #if defined(__MMI_LANG_SM_CHINESE__) && !defined(__MMI_LANG_TR_CHINESE__) && !defined(__MMI_LANG_HK_CHINESE__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Monotype\\\\NewSansMT_PRC2312-121416.stf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
    #endif
    
    #if defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_HK_CHINESE__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Monotype\\\\NewSansMT_PRC18030-121416.ccc", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
    #endif
    }
#endif

#if defined(FONT_ENGINE_FREETYPE) || defined(FONT_ENGINE_MONOTYPE) || defined(FONT_ENGINE_WTLE)
#if defined(__MMI_LANG_THAI__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Monotype\\\\UniversOTSThai.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#endif
#if defined(__MMI_LANG_ARABIC__) || defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__) || defined(__MMI_LANG_GEORGIAN__) || defined(__MMI_LANG_ARMENIAN__) || defined(__MMI_LANG_HEBREW__) || defined(__MMI_FONT_LATIN_ALL__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Monotype\\\\AlbanyWT.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#endif

#if defined(__MMI_LANG_TAMIL__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Monotype\\\\UniversOTSTamil.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#endif
#if defined(__MMI_LANG_TELUGU__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Monotype\\\\UniversOTSTelugu.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#endif
#if defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Monotype\\\\UniversOTSBengali.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)        
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\MTK\\\\BTRC_Bengali_proprietary.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#endif

#endif
#if defined(__MMI_LANG_GUJARATI__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Monotype\\\\UniversOTSGujarati.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#endif
#if defined(__MMI_LANG_KANNADA__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Monotype\\\\UniversOTSKannada.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#endif
#if defined(__MMI_LANG_MALAYALAM__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Monotype\\\\UniversOTSMalayalam.TTF", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#endif

#if defined(__MMI_LANG_ORIYA__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Monotype\\\\mts_t_v1_Oriya2.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#endif

#if defined(__MMI_LANG_PUNJABI__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Monotype\\\\UniversOTSGurmukhi.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#endif

#if defined(__MMI_INDIC_ALG__)
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\Monotype\\\\UniversOTSDevanagari.ttf", 0, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#endif


#endif


#if !defined(FONT_ENGINE_MONOTYPE_DEMO)

    /* common usage for Zi */
#if defined(__MMI_ZI_STROKE_INPUT__) && (defined(__MMI_ZI_TR_CHINESE__) || defined(__MMI_ZI_SM_CHINESE__) || defined(__MMI_ZI_HK_CHINESE__))
        /* flag 0x01 presnet the font belong to ucs2 private use. */
        ADD_FONT_RESOURCE(
            i,
            CUST_IMG_PATH_ROOT "\\\\..\\\\..\\\\Fonts\\\\MTK\\\\stroke.ttf", 0x01 << 16, MMI_RES_FLAG_FONT_IS_ENFB, 1);
#endif

#endif

    Sys_font_deinit(j);

}

#endif


