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

/*******************************************************************************
 * Filename:
 * ---------
 *  vmchset.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Char set implement file.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "vmswitch.h"
#ifdef __MRE_LIB_CHSET__
#include "MMI_features.h"
#include "MMIDataType.h"
#include "PixcomFontEngine.h"
#include "string.h"
#include "Conversions.h"
#include "CustDataRes.h"

#include "vmsys.h"
#include "vmchset.h"
#include "vmlog.h"
#include "mmi_trc_int.h"
#include "MMI_mre_trc.h"


extern U16 gMaxDeployedLangs;


/*****************************************************************************
 * FUNCTION
 *  vm_ucs2_to_default
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst         [IN]        
 *  size        [IN]        
 *  src         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_ucs2_to_default(VMSTR dst, VMINT size, VMWSTR src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CHSET_GB2312__
    return vm_ucs2_to_gb2312(dst, size, src);
#else
	return vm_ucs2_to_ascii(dst, size, src);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vm_default_to_ucs2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst         [IN]        
 *  size        [IN]        
 *  src         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_default_to_ucs2(VMWSTR dst, VMINT size, VMSTR src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CHSET_GB2312__
    return vm_gb2312_to_ucs2(dst, size, src);
#else
	return vm_ascii_to_ucs2(dst, size, src);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vm_ucs2_to_gb2312
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst         [IN]        
 *  size        [IN]        
 *  src         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_ucs2_to_gb2312(VMSTR dst, VMINT size, VMWSTR src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT retval = -1;
    VMINT result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (size > CONVERT_CHSET_MAX_LEN || size <= 0)
    {
        retval = -1;
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMCHSET_223 );
    }
    else
    {
        if (src == NULL || dst == NULL)
        {
            retval = -1;
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMCHSET_230 );
        }
        else
        {
#ifdef __MMI_CHSET_GB2312__
			result = mmi_chset_convert(
				MMI_CHSET_UCS2, 
				MMI_CHSET_GB2312, 
				(VMCHAR *)src, 
				(VMCHAR *)dst, 
				size);
#else
			result = mmi_chset_convert(
				MMI_CHSET_UCS2, 
				MMI_CHSET_ASCII, 
				(VMCHAR *)src, 
				(VMCHAR *)dst, 
				size);
#endif
            if (result > 0)
            {
                retval = 0;
            }
            else
            {
                retval = -1;
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMCHSET_256 );
            }
        }
    }
    return retval;

}


/*****************************************************************************
 * FUNCTION
 *  vm_gb2312_to_ucs2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst         [IN]        
 *  size        [IN]        
 *  src         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_gb2312_to_ucs2(VMWSTR dst, VMINT size, VMSTR src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT retval = -1;
    VMINT result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (size > CONVERT_CHSET_MAX_LEN || size <= 0)
    {
        retval = -1;
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMCHSET_291 );
    }
    else
    {
        if (src == NULL || dst == NULL)
        {
            retval = -1;
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMCHSET_298 );
        }
        else
        {
#ifdef __MMI_CHSET_GB2312__
			result = mmi_chset_convert(
				MMI_CHSET_GB2312, 
				MMI_CHSET_UCS2, 				
				(VMCHAR *)src, 
				(VMCHAR *)dst, 
				size);
#else
			result = mmi_chset_convert(
				MMI_CHSET_ASCII, 
				MMI_CHSET_UCS2, 				
				(VMCHAR *)src, 
				(VMCHAR *)dst, 
				size);
#endif
            MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMCHSET_317 , src, result);
            if (result > 0)
            {
                retval = 0;
            }
            else
            {
                retval = -1;
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMCHSET_325 );
            }
        }
    }
    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  vm_ucs2_to_ascii
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst         [IN]        
 *  size        [IN]        
 *  src         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_ucs2_to_ascii(VMSTR dst, VMINT size, VMWSTR src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT retval = -1;
    VMINT result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (size > CONVERT_CHSET_MAX_LEN || size <= 0)
    {
        retval = -1;
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMCHSET_359 );
    }
    else
    {
        if (src == NULL || dst == NULL)
        {
            retval = -1;
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMCHSET_366 );
        }
        else
        {
            result = mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_ASCII, (VMCHAR*) src, (VMCHAR*) dst, size);
            if (result > 0)
            {
                retval = 0;
            }
            else
            {
                retval = -1;
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMCHSET_378 );
            }
        }
    }
    return retval;

}


/*****************************************************************************
 * FUNCTION
 *  vm_ascii_to_ucs2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst         [IN]        
 *  size        [IN]        
 *  src         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_ascii_to_ucs2(VMWSTR dst, VMINT size, VMSTR src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT retval = -1;
    VMINT result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (size > CONVERT_CHSET_MAX_LEN || size <= 0)
    {
        retval = -1;
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMCHSET_413 );
    }
    else
    {
        if (src == NULL || dst == NULL)
        {
            retval = -1;
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMCHSET_420 );
        }
        else
        {
            result = mmi_chset_convert(MMI_CHSET_ASCII, MMI_CHSET_UCS2, (VMCHAR*) src, (VMCHAR*) dst, size);
            MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMCHSET_425 , src, result);
            if (result > 0)
            {
                retval = 0;
            }
            else
            {
                retval = -1;
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMCHSET_433 );
            }
        }
    }
    return retval;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

#define VM_GB_UCS2_STRING_BUFF         (256)    /* the max length of the string is 128 */
VMSTR ucs2_string;
VMSTR ucs2_string_ascii;
VMSTR gb2312_string;


/*****************************************************************************
 * FUNCTION
 *  vm_chset_memory_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vm_chset_memory_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_MOD_VMCHSET, TRC_MRE_VMCHSET_499 );
    ucs2_string = vm_malloc(VM_GB_UCS2_STRING_BUFF);
    if (NULL == ucs2_string)
    {
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMCHSET_503 );
        return;
    }

    ucs2_string_ascii = vm_malloc(VM_GB_UCS2_STRING_BUFF);
    if (NULL == ucs2_string_ascii)
    {
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMCHSET_510 );
        return;
    }

    gb2312_string = vm_malloc(VM_GB_UCS2_STRING_BUFF);
    if (NULL == gb2312_string)
    {
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMCHSET_517 );
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vm_chset_memory_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vm_chset_memory_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_MOD_VMCHSET, TRC_MRE_VMCHSET_542 );
    if (NULL != ucs2_string)
    {
        vm_free(ucs2_string);
        ucs2_string = NULL;
    }

    if (NULL != ucs2_string_ascii)
    {
        vm_free(ucs2_string_ascii);
        ucs2_string_ascii = NULL;
    }

    if (NULL != gb2312_string)
    {
        vm_free(gb2312_string);
        gb2312_string = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vm_ucs2_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMWSTR vm_ucs2_string(VMSTR s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != ucs2_string)
    {
        vm_default_to_ucs2((VMWSTR) ucs2_string, VM_GB_UCS2_STRING_BUFF, s);
    }
    return (VMWSTR) ucs2_string;
}


/*****************************************************************************
 * FUNCTION
 *  vm_ucs2_string_by_ascii
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMWSTR vm_ucs2_string_by_ascii(VMSTR s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != ucs2_string_ascii)
    {
        vm_ascii_to_ucs2((VMWSTR) ucs2_string_ascii, VM_GB_UCS2_STRING_BUFF, s);
    }
    return (VMWSTR) ucs2_string_ascii;
}


/*****************************************************************************
 * FUNCTION
 *  vm_gb2312_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMSTR vm_gb2312_string(VMWSTR s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != gb2312_string)
    {
        vm_ucs2_to_gb2312(gb2312_string, VM_GB_UCS2_STRING_BUFF, s);
    }
    return gb2312_string;
}

const static VMINT mreEncodingType2mtkEncodingType[2][VM_CHSET_TOTAL] = 
{
    {
     VM_CHSET_ASCII,
     VM_CHSET_ARABIC_ISO,
     VM_CHSET_ARABIC_WIN,
     VM_CHSET_PERSIAN_CP1097,
     VM_CHSET_PERSIAN_CP1098,
     VM_CHSET_BALTIC_ISO,
     VM_CHSET_BALTIC_WIN,
     VM_CHSET_CEURO_ISO,
     VM_CHSET_CEURO_WIN,
     VM_CHSET_CYRILLIC_ISO,
     VM_CHSET_CYRILLIC_WIN,
     VM_CHSET_GREEK_ISO,
     VM_CHSET_GREEK_WIN,
     VM_CHSET_HEBREW_ISO,
     VM_CHSET_HEBREW_WIN,
     VM_CHSET_LATIN_ISO,
     VM_CHSET_NORDIC_ISO,
     VM_CHSET_SEURO_ISO,
     VM_CHSET_TURKISH_ISO,
     VM_CHSET_TURKISH_WIN,
     VM_CHSET_WESTERN_ISO,
     VM_CHSET_ARMENIAN_ISO,
     VM_CHSET_WESTERN_WIN,
     VM_CHSET_BIG5,
     VM_CHSET_GB2312,
     VM_CHSET_HKSCS,
     VM_CHSET_SJIS,
     VM_CHSET_GB18030,
     VM_CHSET_UTF7,
     VM_CHSET_EUCKR,
     VM_CHSET_THAI_WIN,
     VM_CHSET_VIETNAMESE_WIN,
     VM_CHSET_KOI8_R,
     VM_CHSET_TIS_620,
     VM_CHSET_UTF16LE,
     VM_CHSET_UTF16BE,
     VM_CHSET_UTF8,
     VM_CHSET_UCS2},
    {
     MMI_CHSET_ASCII,
     MMI_CHSET_ARABIC_ISO,
     MMI_CHSET_ARABIC_WIN,
     MMI_CHSET_PERSIAN_CP1097,
     MMI_CHSET_PERSIAN_CP1098,
     MMI_CHSET_BALTIC_ISO,
     MMI_CHSET_BALTIC_WIN,
     MMI_CHSET_CEURO_ISO,
     MMI_CHSET_CEURO_WIN,
     MMI_CHSET_CYRILLIC_ISO,
     MMI_CHSET_CYRILLIC_WIN,
     MMI_CHSET_GREEK_ISO,
     MMI_CHSET_GREEK_WIN,
     MMI_CHSET_HEBREW_ISO,
     MMI_CHSET_HEBREW_WIN,
     MMI_CHSET_LATIN_ISO,
     MMI_CHSET_NORDIC_ISO,
     MMI_CHSET_SEURO_ISO,
     MMI_CHSET_TURKISH_ISO,
     MMI_CHSET_TURKISH_WIN,
     MMI_CHSET_WESTERN_ISO,
     MMI_CHSET_ARMENIAN_ISO,
     MMI_CHSET_WESTERN_WIN,
     MMI_CHSET_BIG5,
     MMI_CHSET_GB2312,
     MMI_CHSET_HKSCS,
     MMI_CHSET_SJIS,
     MMI_CHSET_GB18030,
     MMI_CHSET_UTF7,
     MMI_CHSET_EUCKR,
     MMI_CHSET_THAI_WIN,
     MMI_CHSET_VIETNAMESE_WIN,
     MMI_CHSET_KOI8_R,
     MMI_CHSET_TIS_620,
     MMI_CHSET_UTF16LE,
     MMI_CHSET_UTF16BE,
     MMI_CHSET_UTF8,
     MMI_CHSET_UCS2}
};


/*****************************************************************************
 * FUNCTION
 *  vm_chset_convert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_type        [IN]        
 *  dest_type       [IN]        
 *  src             [IN]         
 *  dest            [OUT]         
 *  dest_size       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_chset_convert(vm_chset_enum src_type, vm_chset_enum dest_type, VMCHAR *src, VMCHAR *dest, VMINT dest_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G2_CHSET, TRC_MRE_CHSET_CONVERT_S, src_type, dest_type, src, dest, dest_size);
    if (src == NULL || dest == NULL || dest_size <= 0)
    {
        return VM_CHSET_CONVERT_ERR_PARAM;
    }

    if (src_type <= VM_CHSET_BASE || src_type >= VM_CHSET_TOTAL)
    {
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMCHSET_757 );
        return VM_CHSET_CONVERT_SRC_UNSUPPORT_CHSET;
    }

    if (dest_type <= VM_CHSET_BASE || dest_type >= VM_CHSET_TOTAL)
    {
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMCHSET_763 );
        return VM_CHSET_CONVERT_DST_UNSUPPORT_CHSET;
    }

    if (mmi_chset_is_enabled((mmi_chset_enum)mreEncodingType2mtkEncodingType[1][src_type - 1]) == KAL_FALSE)
    {
        vm_log_error(
            "[CHSET MODULE] Src enconding unsupport, MRE encoding val[%d], MTK encoding val[%d].",
            mreEncodingType2mtkEncodingType[0][src_type - 1],
            mreEncodingType2mtkEncodingType[1][src_type - 1]);
        return VM_CHSET_CONVERT_SRC_UNSUPPORT_CHSET;
    }

    if (mmi_chset_is_enabled((mmi_chset_enum)mreEncodingType2mtkEncodingType[1][dest_type - 1]) == KAL_FALSE)
    {
        vm_log_error(
            "[CHSET MODULE] Dest enconding unsupport, MRE encoding val[%d], MTK encoding val[%d].",
            mreEncodingType2mtkEncodingType[0][dest_type - 1],
            mreEncodingType2mtkEncodingType[1][dest_type - 1]);
        return VM_CHSET_CONVERT_DST_UNSUPPORT_CHSET;
    }

    if (mmi_chset_convert(
                    (mmi_chset_enum)mreEncodingType2mtkEncodingType[1][src_type - 1],
                    (mmi_chset_enum)mreEncodingType2mtkEncodingType[1][dest_type - 1],
                    src,
                    dest,
                    dest_size) > 0)
    {
        return VM_CHSET_CONVERT_SUCCESS;
    }

    return VM_CHSET_CONVERT_FATAL_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_language
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
typedef struct
{
    VMCHAR * lang_str;
    vm_language_t lang_int;
}lang_t;

static lang_t g_lang[] = {
    {"zh-CN", GB},
    {"zh-TW", BIG5},
    {"en-US", ENGLISH},
    {"en-EN", ENGLISH},
#if defined(__MMI_LANG_UK_ENGLISH__)
    {"en-UK", UK_ENGLISH},
#endif
#if defined(__MMI_LANG_KOREAN__)
    {"ko", KOREAN},
#endif
#if defined(__MMI_LANG_SPANISH__)
    {"es-ES", SPANISH},
#endif
#if defined(__MMI_LANG_SA_SPANISH__)
    {"es-SA", SA_SPANISH},
#endif
#if defined(__MMI_LANG_FRENCH__)
    {"fr-FR", FRENCH},
#endif
#if defined(__MMI_LANG_CA_FRENCH__)
    {"fr-CA", CA_FRENCH},
#endif
#if defined(__MMI_LANG_DANISH__)
    {"da-DK", DANISH},
#endif
#if defined(__MMI_LANG_POLISH__)
    {"pl-PL", POLISH},
#endif
#if defined(__MMI_LANG_PORTUGUESE__)
    {"pt-PT", PORTUGUESE},
#endif
#if defined(__MMI_LANG_ALBANIAN__)
    {"sq-SQ", ALBANIAN},
#endif
#if defined(__MMI_LANG_SA_PORTUGUESE__)
    {"pt-BZ", SA_PORTUGUESE},
#endif
#if defined(__MMI_LANG_ICELANDIC__)
    {"is-IS", ICELANDIC},
#endif
#if defined(__MMI_LANG_SERBIAN__)
    {"sr-SR", SERBIAN},
#endif
#if defined(__MMI_LANG_AZERBAIJANI__)
    {"az-AZ", AZERBAIJANI},
#endif
#if defined(__MMI_LANG_CATALAN__)
    {"ca-CA", CATALAN},
#endif
#if defined(__MMI_LANG_HAUSA__)
    {"ha-HA", HAUSA},
#endif
#if defined(__MMI_LANG_KAZAKH__)
    {"kk-KK", KAZAKH},
#endif
#if defined(__MMI_LANG_MACEDONIAN__)
    {"mk-MK", MACEDONIAN},
#endif
#if defined(__MMI_LANG_SESOTHO__)
    {"st-ST", SESOTHO},
#endif
#if defined(__MMI_LANG_TAGALOG__)
    {"tl-TL", TAGALOG},
#endif
#if defined(__MMI_LANG_YORUBA__)
    {"yo-YO", YORUBA},
#endif
#if defined(__MMI_LANG_ITALIAN__)
    {"it-IT", ITALIAN},
#endif
#if defined(__MMI_LANG_GERMAN__)
    {"de-DE", GERMAN},
#endif
#if defined(__MMI_LANG_MALAY__)
    {"ms-MY", MALAY},
#endif
#if defined(__MMI_LANG_INDONESIAN__)
    {"id-ID", INDONESIAN},
#endif
#if defined(__MMI_LANG_CZECH__)
    {"cs-CZ", CZECH},
#endif
#if defined(__MMI_LANG_NORWEGIAN__)
    {"nb-NO", NORWEGIAN},
#endif
#if defined(__MMI_LANG_SLOVAK__)
    {"sk-SK", SLOVAK},
#endif
#if defined(__MMI_LANG_DUTCH__)
    {"nl-NL", DUTCH},
#endif
#if defined(__MMI_LANG_FINNISH__)
    {"fi-FI", FINNISH},
#endif
#if defined(__MMI_LANG_HUNGARIAN__)
    {"hu-HU", HUNGARIAN},
#endif
#if defined(__MMI_LANG_VIETNAMESE__)
    {"vi-VN", VIETNAMESE},
#endif
#if defined(__MMI_LANG_TURKISH__)
    {"tr-TR", TURKISH},
#endif
#if defined(__MMI_LANG_RUSSIAN__)
    {"ru-RU", RUSSIAN},
#endif
#if defined(__MMI_LANG_BULGARIAN__)
    {"bg-BG", BULGARIAN},
#endif
#if defined(__MMI_LANG_UKRAINIAN__)
    {"uk-UA", UKRAINIAN},
#endif
#if defined(__MMI_LANG_ARABIC__)
    {"ar-SA", ARABIC},
#endif
#if defined(__MMI_LANG_PERSIAN__)
    {"ps-IR", PERSIAN},
#endif
#if defined(__MMI_LANG_URDU__)
    {"ur-PK", URDU},
#endif
#if defined(__MMI_LANG_HEBREW__)
    {"he-IL", HEBREW},
#endif
#if defined(__MMI_LANG_THAI__)
    {"th-TH", THAI},
#endif
#if defined(__MMI_LANG_GREEK__)
    {"el-GR", GREEK},
#endif
#if defined(__MMI_LANG_SWEDISH__)
    {"sv-SE", SWEDISH},
#endif
#if defined(__MMI_LANG_CROATIAN__)
    {"hr-HR", CROATIAN},
#endif
#if defined(__MMI_LANG_ROMANIAN__)
    {"ro-RO", ROMANIAN},
#endif
#if defined(__MMI_LANG_SLOVENIAN__)
    {"sl-SI", SLOVENIAN},
#endif
#if defined(__MMI_LANG_HINDI__)
    {"hi-IN", HINDI},
#endif
#if defined(__MMI_LANG_MARATHI__)
    {"mr-IN", MARATHI},
#endif
#if defined(__MMI_LANG_TAMIL__)
    {"ta-IN", TAMIL},
#endif
#if defined(__MMI_LANG_GUJARATI__)
    {"gu-IN", GUJARATI},
#endif
#if defined(__MMI_LANG_BENGALI__)
    {"be-IN", BENGALI},
#endif
#if defined(__MMI_LANG_ASSAMESE__)
    {"as-IN", ASSAMESE},
#endif
#if defined(__MMI_LANG_PUNJABI__)
    {"pa-IN", PUNJABI},
#endif
#if defined(__MMI_LANG_TELUGU__)
    {"te-IN", TELUGU},
#endif
#if defined(__MMI_LANG_KANNADA__)
    {"kn-IN", KANNADA},
#endif
#if defined(__MMI_LANG_MALAYALAM__)
    {"ml-IN", MALAYALAM},
#endif
#if defined(__MMI_LANG_ORIYA__)
    {"or-IN", ORIYA},
#endif
#if defined(__MMI_LANG_XHOSA__)
    {"xh-ZA", XHOSA},
#endif
#if defined(__MMI_LANG_SWAHILI__)
    {"sw-TZ", SWAHILI},
#endif
#if defined(__MMI_LANG_AFRIKAANS__)
    {"af-NA", AFRIKAANS},
#endif
#if defined(__MMI_LANG_ZULU__)
    {"zu-SZ", ZULU},
#endif
#if defined(__MMI_LANG_LITHUANIAN__)
    {"lt-LT", LITHUANIAN},
#endif
#if defined(__MMI_LANG_LATVIAN__)
    {"lv-LV", LATVIAN},
#endif
#if defined(__MMI_LANG_ESTONIAN__)
    {"et-EE", ESTONIAN},
#endif
#if defined(__MMI_LANG_ARMENIAN__)
    {"hy-AM", ARMENIAN},
#endif
#if defined(__MMI_LANG_GEORGIAN__)
    {"ka-GE", GEORGIAN},
#endif
#if defined(__MMI_LANG_MOLDOVAN__)
    {"mo-MD", MOLDOVAN},
#endif
#if defined(__MMI_LANG_GALICIAN__)
    {"gl-ES", GALICIAN},
#endif
#if defined(__MMI_LANG_BASQUE__)
    {"eu-ES", BASQUE},
#endif
#if defined(__MMI_LANG_IGBO__)
    {"ig-NG", IGBO},
#endif
#if defined(__MMI_LANG_FILIPINO__)
    {"fil-PH", FILIPINO},
#endif
#if defined(__MMI_LANG_IRISH__)
    {"ga-IE", IRISH},
#endif
    {0, GB}
};



vm_language_t vm_get_language(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUCHAR *countrycode = NULL;
    vm_language_t retval = LANG_UNKOWN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    countrycode = (U8*) Get_Current_Lang_CountryCode();
    if (countrycode != NULL)
    {
        lang_t * lang_p = g_lang;
        VMINT i;
        
        MMI_TRACE(MMI_MRE_TRC_MOD_VMCHSET, TRC_MRE_VMCHSET_823 , countrycode);
        
        for (i = 0; 0 != lang_p[i].lang_str; i++)
        {
            if (0 == strcmp((char*)countrycode, (char*)lang_p[i].lang_str))
            {
                return lang_p[i].lang_int;
            }
        }
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if defined(__MMI_LANG_UK_ENGLISH__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_UK_ENGLISH__) */ 
    #if defined(__MMI_LANG_KOREAN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_KOREAN__) */ 
    #if defined(__MMI_LANG_SPANISH__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_SPANISH__) */ 
    #if defined(__MMI_LANG_SA_SPANISH__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_SA_SPANISH__) */ 
    #if defined(__MMI_LANG_FRENCH__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_FRENCH__) */ 
    #if defined(__MMI_LANG_CA_FRENCH__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_CA_FRENCH__) */ 
    #if defined(__MMI_LANG_DANISH__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_DANISH__) */ 
    #if defined(__MMI_LANG_POLISH__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_POLISH__) */ 
    #if defined(__MMI_LANG_PORTUGUESE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_PORTUGUESE__) */ 
    #if defined(__MMI_LANG_ALBANIAN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_ALBANIAN__) */ 
    #if defined(__MMI_LANG_SA_PORTUGUESE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_SA___) */ 
    #if defined(__MMI_LANG_ICELANDIC__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_ICELANDIC__) */ 
    #if defined(__MMI_LANG_SERBIAN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_SERBIAN__) */ 
    #if defined(__MMI_LANG_AZERBAIJANI__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_AZERBAIJANI__) */ 
    #if defined(__MMI_LANG_CATALAN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_CATALAN__) */ 
    #if defined(__MMI_LANG_HAUSA__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_HAUSA__) */ 
/* under construction !*/
    #if defined(__MMI_LANG_KAZAKH__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_KAZAKH__) */ 
    #if defined(__MMI_LANG_MACEDONIAN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_MACEDONIAN__) */ 
    #if defined(__MMI_LANG_SESOTHO__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_SESOTHO__) */ 
/* under construction !*/
    #if defined(__MMI_LANG_TAGALOG__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_TAGALOG__) */ 
    #if defined(__MMI_LANG_YORUBA__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_YORUBA__) */ 
    #if defined(__MMI_LANG_ITALIAN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_ITALIAN__) */ 
    #if defined(__MMI_LANG_GERMAN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_GERMAN__) */ 
    #if defined(__MMI_LANG_MALAY__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_MALAY__) */ 
    #if defined(__MMI_LANG_INDONESIAN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_INDONESIAN__) */ 
    #if defined(__MMI_LANG_CZECH__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_CZECH__) */ 
    #if defined(__MMI_LANG_NORWEGIAN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_NORWEGIAN__) */ 
    #if defined(__MMI_LANG_SLOVAK__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_SLOVAK__) */ 
    #if defined(__MMI_LANG_DUTCH__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_DUTCH__) */ 
    #if defined(__MMI_LANG_FINNISH__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_FINNISH__) */ 
    #if defined(__MMI_LANG_HUNGARIAN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_HUNGARIAN__) */ 
    #if defined(__MMI_LANG_VIETNAMESE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
    #if defined(__MMI_LANG_TURKISH__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_TURKISH__) */ 
    #if defined(__MMI_LANG_RUSSIAN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_RUSSIAN__) */ 
    #if defined(__MMI_LANG_BULGARIAN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_BULGARIAN__) */ 
    #if defined(__MMI_LANG_UKRAINIAN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_UKRAINIAN__) */ 
    #if defined(__MMI_LANG_ARABIC__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_ARABIC__) */ 
    #if defined(__MMI_LANG_PERSIAN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_PERSIAN__) */ 
    #if defined(__MMI_LANG_URDU__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_URDU__) */ 
    #if defined(__MMI_LANG_HEBREW__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_HEBREW__) */ 
    #if defined(__MMI_LANG_THAI__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_THAI__) */ 
    #if defined(__MMI_LANG_GREEK__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_GREEK__) */ 
    #if defined(__MMI_LANG_SWEDISH__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_SWEDISH__) */ 
    #if defined(__MMI_LANG_CROATIAN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_CROATIAN__) */ 
    #if defined(__MMI_LANG_ROMANIAN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_ROMANIAN__) */ 
    #if defined(__MMI_LANG_SLOVENIAN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_SLOVENIAN__) */ 
    #if defined(__MMI_LANG_HINDI__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_HINDI__) */ 
    #if defined(__MMI_LANG_MARATHI__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_MARATHI__) */ 
    #if defined(__MMI_LANG_TAMIL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_TAMIL__) */ 
    #if defined(__MMI_LANG_GUJARATI__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_GUJARATI__) */ 
    #if defined(__MMI_LANG_BENGALI__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_BENGALI__) */ 
    #if defined(__MMI_LANG_ASSAMESE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_ASSAMESE__) */ 
    #if defined(__MMI_LANG_PUNJABI__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_PUNJABI__) */ 
    #if defined(__MMI_LANG_TELUGU__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_TELUGU__) */ 
    #if defined(__MMI_LANG_KANNADA__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_KANNADA__) */ 
    #if defined(__MMI_LANG_MALAYALAM__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_MALAYALAM__) */ 
    #if defined(__MMI_LANG_ORIYA__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_ORIYA__) */ 
    #if defined(__MMI_LANG_XHOSA__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_XHOSA__) */ 
    #if defined(__MMI_LANG_SWAHILI__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_SWAHILI__) */ 
    #if defined(__MMI_LANG_AFRIKAANS__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_AFRIKAANS__) */ 
    #if defined(__MMI_LANG_ZULU__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_ZULU__) */ 
    #if defined(__MMI_LANG_LITHUANIAN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_LITHUANIAN__) */ 
    #if defined(__MMI_LANG_LATVIAN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_LATVIAN__) */ 
    #if defined(__MMI_LANG_ESTONIAN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_ESTONIAN__) */ 
    #if defined(__MMI_LANG_ARMENIAN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_ARMENIAN__) */ 
    #if defined(__MMI_LANG_GEORGIAN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_GEORGIAN__) */ 
    #if defined(__MMI_LANG_MOLDOVAN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_MOLDOVAN__) */ 
    #if defined(__MMI_LANG_GALICIAN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_GALICIAN__) */ 
    #if defined(__MMI_LANG_BASQUE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_BASQUE__) */ 
    #if defined(__MMI_LANG_IGBO__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_IGBO__) */ 
    #if defined(__MMI_LANG_FILIPINO__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_FILIPINO__) */ 
    #if defined(__MMI_LANG_IRISH__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_IRISH__) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
    }
    return retval;
}

VMINT32 vm_get_language_ssc(VMINT8 *ssc)
{
    return mmi_res_get_cur_language((U8 *)ssc);
}

/*****************************************************************************
 * FUNCTION
 *  vm_get_current_lang_country_code
 * DESCRIPTION
 *  To get current language's country code
 *  This is used to get current language's country code
 * PARAMETERS
 *  void
 * RETURNS
 *  country code
 *****************************************************************************/
VMUSTR vm_get_current_lang_country_code(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUCHAR *countrycode = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    countrycode = (U8*) Get_Current_Lang_CountryCode();
    return countrycode;
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_language_num
 * DESCRIPTION
 *  To query support language number.
 * PARAMETERS
 *  void
 * RETURNS
 *  the language number.
 *****************************************************************************/
VMINT32 vm_get_language_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gMaxDeployedLangs;
}


#endif /* __MRE_LIB_CHSET__ */ 

